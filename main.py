import FieldFileSetup as ffp

a=ffp.FieldFileSetup()


#a.dump()

a.loadFile("data.dat")

a.setNumOfElement(2,2,2)

print a.get3DVectorValue(a.data1,1,1,1)
