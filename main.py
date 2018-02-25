import FieldFileSetup as ffp

a=ffp.FieldFileSetup()


#a.dump()

a.loadFile("data.dat")

a.setNumOfElement(2,5,2)

#print a.get3DVectorValue(a.data1,1,1,1)

print "#g:",a.getValue(a.data1, 0.1 ,0.1, 0.1)

a.dump()
