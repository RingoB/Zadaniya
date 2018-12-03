str='abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ'
ind=[1,0]
word=input('word: ')
key=int(input('key: '))
if(key<0): ind=[-1,1]
for i in range(len(word)): print(str[str.find(word[i])+ind[0]*((key*ind[0])%26)+26*ind[1]], end = "")
