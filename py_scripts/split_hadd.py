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
onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
n_div=len(onlyfiles)/n_split+1
print(n_div)

lll = [onlyfiles[i:i + n_div] for i in range(0, len(onlyfiles),n_div )]

#print(lll[0])
#l_val = 0
for l_val in range(n_split): 
    
    command = 'hadd 410470_'+str(l_val)+'.root '
    for it in lll[l_val]:
        command+=mypath+'/'+it+' '

    print(command)
    print(" ========================== ")
    #system(command)
    print(" ------------------------- ")
