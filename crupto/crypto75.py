from pwn import *

flag = ''

r = remote('challenge.hackfest.tn', 3001)
print r.recvline().strip()
print r.recvline().strip()

while len(flag) < 34:
    l = len(flag)
    print l, flag
    base = 'A' * (39 - l) + flag
    r.sendline(base.encode('base64'))
    hashed = r.recv().replace('\n','').decode('base64')
    for c in range(256):
        payload = base + chr(c)
        r.sendline(payload.encode('base64'))
        hashed2 = r.recv().replace('\n','').decode('base64')
        if hashed[:48] == hashed2[:48]:
            print hashed.encode('hex')
            print hashed2.encode('hex')
            flag += chr(c)
            break
    if len(flag) == l:
        print 'not found'
        break
print flag
