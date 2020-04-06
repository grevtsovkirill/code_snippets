import os
import glob

do_campaign=True
samples = ['413008_ttw','410155_ttw','410472_ttbar','410156_ttZnunu','410157_ttZqq','410218_ttee','410219_ttmumu','410220_tttautau',
           '410658_topt','410659_atopt','410644_tops','410645_atops',           
           '304014_threeTop','410080_fourTop','410081_ttww','410408_WtZ']
samples = ['410155_ttw'] 
for itt in samples:
    dsid_cut = itt.find("_")
    dsid = itt[:dsid_cut]
    if do_campaign:
        r_tag = 'r9364'
        fname = dsid
    else: 
        r_tag = ''
        fname = itt
    fold_name0 = 'user.kgrevtso.'+dsid+'.*'+r_tag+'*'
    fold_name = glob.glob(fold_name0)
    command = 'hadd '+fname+'.root user.kgrevtso.'+dsid+'.*'+r_tag+'*/user.*.root'
    print(dsid_cut,fold_name)
    if fold_name:
        if os.path.exists(fold_name[0]) and not os.path.exists(itt+'.root'):
            print(command)
            #os.system(command)
            print(" ========================== ")
        else:
            print('File '+itt+'.root exists')
            print(" ------------------------- ")
    else:
        print('File '+itt+' - not yet exists')

