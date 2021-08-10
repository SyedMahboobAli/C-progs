def convertCase(string):
    new=''
    for a in string:
        if a=='A'or a=='E' or a=='I' or a=='O' or a=='U':
            new+=a.lower()
        
        elif a!='a'and a!='e' and a!='i' and a!='o' and a!='u':
            new+=a.upper()
        else:
            new+=a
    return new

        



