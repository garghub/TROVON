static void _sclp_wait_int(void)
{
unsigned long cr0, cr0_new, psw_mask, addr;
psw_t psw_ext_save, psw_wait;
__ctl_store(cr0, 0, 0);
cr0_new = cr0 | 0x200;
__ctl_load(cr0_new, 0, 0);
psw_ext_save = S390_lowcore.external_new_psw;
psw_mask = __extract_psw() & (PSW_MASK_EA | PSW_MASK_BA);
S390_lowcore.external_new_psw.mask = psw_mask;
psw_wait.mask = psw_mask | PSW_MASK_EXT | PSW_MASK_WAIT;
S390_lowcore.ext_int_code = 0;
do {
asm volatile(
" larl %[addr],0f\n"
" stg %[addr],%[psw_wait_addr]\n"
" stg %[addr],%[psw_ext_addr]\n"
" lpswe %[psw_wait]\n"
"0:\n"
: [addr] "=&d" (addr),
[psw_wait_addr] "=Q" (psw_wait.addr),
[psw_ext_addr] "=Q" (S390_lowcore.external_new_psw.addr)
: [psw_wait] "Q" (psw_wait)
: "cc", "memory");
} while (S390_lowcore.ext_int_code != EXT_IRQ_SERVICE_SIG);
__ctl_load(cr0, 0, 0);
S390_lowcore.external_new_psw = psw_ext_save;
}
static int _sclp_servc(unsigned int cmd, char *sccb)
{
unsigned int cc;
do {
asm volatile(
" .insn rre,0xb2200000,%1,%2\n"
" ipm %0\n"
: "=d" (cc) : "d" (cmd), "a" (sccb)
: "cc", "memory");
cc >>= 28;
if (cc == 3)
return -EINVAL;
_sclp_wait_int();
} while (cc != 0);
return (*(unsigned short *)(sccb + 6) == 0x20) ? 0 : -EIO;
}
static int _sclp_setup(int disable)
{
static unsigned char init_sccb[] = {
0x00, 0x1c,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x04,
0x80, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
unsigned int *masks;
int rc;
memcpy(_sclp_work_area, init_sccb, 28);
masks = (unsigned int *)(_sclp_work_area + 12);
if (disable)
memset(masks, 0, 16);
rc = _sclp_servc(0x00780005, _sclp_work_area);
if (rc)
return rc;
if ((masks[0] & masks[3]) != masks[0] ||
(masks[1] & masks[2]) != masks[1])
return -EIO;
return 0;
}
static int _sclp_print(const char *str)
{
static unsigned char write_head[] = {
0x00, 0x52,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x4a,
0x02, 0x00, 0x00, 0x00,
0x00, 0x44,
0x00, 0x01,
0xd4, 0xc4, 0xc2, 0x40,
0x00, 0x00, 0x00, 0x01,
0x00, 0x38,
0x00, 0x01,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00,
};
static unsigned char write_mto[] = {
0x00, 0x0a,
0x00, 0x04,
0x10, 0x00,
0x00, 0x00, 0x00, 0x00
};
unsigned char *ptr, ch;
unsigned int count;
memcpy(_sclp_work_area, write_head, sizeof(write_head));
ptr = _sclp_work_area + sizeof(write_head);
do {
memcpy(ptr, write_mto, sizeof(write_mto));
for (count = sizeof(write_mto); (ch = *str++) != 0; count++) {
if (ch == 0x0a)
break;
ptr[count] = _ascebc[ch];
}
*(unsigned short *) ptr = count;
*(unsigned short *)(_sclp_work_area + 14) += count;
*(unsigned short *)(_sclp_work_area + 8) += count;
*(unsigned short *)(_sclp_work_area + 0) += count;
ptr += count;
} while (ch != 0);
return _sclp_servc(0x00760005, _sclp_work_area);
}
int _sclp_print_early(const char *str)
{
int rc;
rc = _sclp_setup(0);
if (rc)
return rc;
rc = _sclp_print(str);
if (rc)
return rc;
return _sclp_setup(1);
}
