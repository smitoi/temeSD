#fmi-no-stress
#let's get covrigi

input = open('covrigi.in')
linie = [int(x) for x in input.readline().split(' ')]
nr_concurenti = linie[0]
nr_camere = linie[1]
pret_rsp = linie[2]
nr_rsp = 0
castiguri = [int(x) for x in input.readline().split(' ')]
nr_conc_camere = sorted([int(x) for x in input.readline().split(' ')], reverse = True)
loc_orig = sum(nr_conc_camere)
loc_actual = loc_orig

for index in range(len(nr_conc_camere) - 1, -1, -1):
    if castiguri[loc_orig - sum(nr_conc_camere[0 : index + 1])] - pret_rsp * (index + 1) > castiguri[loc_actual] - pret_rsp * nr_rsp:
        loc_actual = loc_orig - sum(nr_conc_camere[0 : index + 1])
        nr_rsp = index + 1

out = open('covrigi.out', 'w')	
out.write(str(castiguri[loc_actual] - nr_rsp * pret_rsp))
