from os import listdir
from os import system
from os.path import isfile, join
import argparse

parser = argparse.ArgumentParser(description='Inputs')
parser.add_argument('-p','--path', required=True, type=str, help='Folder to look over ')
parser.add_argument('--nsplit', required=False, default=4, type=int, help='number of output files. def=4, increase if input is too large')
args = parser.parse_args()

mypath = vars(args)["path"]
n_split = vars(args)["nsplit"]
#mypath = 'user.kgrevtso.410470.PhPy8EG.DAOD_TOPQ1.e6337_s3126_r10201_p3832.1103_MCTrC_v0_output_root'
getdsid = mypath[5:]
dsid_cut = getdsid.find(".")
dsid = getdsid[dsid_cut+1:dsid_cut+7]

onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
n_div=len(onlyfiles)/n_split+1
print(onlyfiles)

print("Nfiles=",len(onlyfiles),"; nsplit=",n_split,"; n_div=",n_div)

if (n_div)<n_split:
     parser.error("Too fine granularity (not enough files to make proper split) - try to reduce n_split option with flag --nsplit or merge to one file")


lll = [onlyfiles[i:i + n_div] for i in range(0, len(onlyfiles),n_div )]

for l_val in range(n_split): 
    
    command = 'hadd '+dsid+'_'+str(l_val)+'.root '
    for it in lll[l_val]:
        command+=mypath+'/'+it+' '

    #print(command)
    print(" ========================== ")
    system(command)
    print(" ------------------------- ")
