import random
i=0
stringlist=["ekfrasi"]
count=1
while i<=len(stringlist) :
	if stringlist[i]=="ekfrasi":
		print("Step",count,":"," ".join(stringlist))
		x=random.randint(0,1)
		if x==0:
			stringlist.remove("ekfrasi")
			stringlist.insert(i,"oros")
		else :
			stringlist.insert(i+1,"+")
			stringlist.insert(i+2,"oros")
	elif stringlist[i]=="oros":
		print("Step",count,":"," ".join(stringlist))
		x=random.randint(0,1)
		if x==0 :
			stringlist.remove("oros")
			stringlist.insert(i,"paragontas")
		else :
			stringlist.insert(i+1, "*")
			stringlist.insert(i+2, "paragontas")
	elif stringlist[i]=="paragontas":
		print("Step",count,":"," ".join(stringlist))
		x=random.randint(0,2)
		if x==0:
			stringlist.remove("paragontas")
			stringlist.insert(i,"a")
		elif x==1:
			stringlist.remove("paragontas")
			stringlist.insert(i,"b")
		else:
			stringlist.remove("paragontas")
			stringlist.insert(i,"c")
	else:
		i+=2
	count+=1
print("Generated String:"," ".join(stringlist))

	