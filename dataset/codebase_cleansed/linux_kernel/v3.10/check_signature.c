int check_signature(const volatile void __iomem *io_addr,
const unsigned char *signature, int length)
{
while (length--) {
if (readb(io_addr) != *signature)
return 0;
io_addr++;
signature++;
}
return 1;
}
