from os import listdir
from os import system
from os.path import isfile, join

mypath = 'user.kgrevtso.410470.PhPy8EG.DAOD_TOPQ1.e6337_s3126_r10201_p3832.1103_MCTrC_v0_output_root'
onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
n_div=len(onlyfiles)/4+1
print(n_div)

lll = [onlyfiles[i:i + n_div] for i in range(0, len(onlyfiles),n_div )]

#print(lll[0])
#l_val = 0
for l_val in range(4): 
    
    command = 'hadd 410470_'+str(l_val)+'.root '
    for it in lll[l_val]:
        command+=mypath+'/'+it+' '

    #print(command)
    print(" ========================== ")
    system(command)
    print(" ------------------------- ")
