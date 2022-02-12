static void ktti_write_regr( PIA *pi, int cont, int regr, int val)
{ int r;
r = regr + cont_map[cont];
w0(r); w2(0xb); w2(0xa); w2(3); w2(6);
w0(val); w2(3); w0(0); w2(6); w2(0xb);
}
static int ktti_read_regr( PIA *pi, int cont, int regr )
{ int a, b, r;
r = regr + cont_map[cont];
w0(r); w2(0xb); w2(0xa); w2(9); w2(0xc); w2(9);
a = r1(); w2(0xc); b = r1(); w2(9); w2(0xc); w2(9);
return j44(a,b);
}
static void ktti_read_block( PIA *pi, char * buf, int count )
{ int k, a, b;
for (k=0;k<count/2;k++) {
w0(0x10); w2(0xb); w2(0xa); w2(9); w2(0xc); w2(9);
a = r1(); w2(0xc); b = r1(); w2(9);
buf[2*k] = j44(a,b);
a = r1(); w2(0xc); b = r1(); w2(9);
buf[2*k+1] = j44(a,b);
}
}
static void ktti_write_block( PIA *pi, char * buf, int count )
{ int k;
for (k=0;k<count/2;k++) {
w0(0x10); w2(0xb); w2(0xa); w2(3); w2(6);
w0(buf[2*k]); w2(3);
w0(buf[2*k+1]); w2(6);
w2(0xb);
}
}
static void ktti_connect ( PIA *pi )
{ pi->saved_r0 = r0();
pi->saved_r2 = r2();
w2(0xb); w2(0xa); w0(0); w2(3); w2(6);
}
static void ktti_disconnect ( PIA *pi )
{ w2(0xb); w2(0xa); w0(0xa0); w2(3); w2(4);
w0(pi->saved_r0);
w2(pi->saved_r2);
}
static void ktti_log_adapter( PIA *pi, char * scratch, int verbose )
{ printk("%s: ktti %s, KT adapter at 0x%x, delay %d\n",
pi->device,KTTI_VERSION,pi->port,pi->delay);
}
static int __init ktti_init(void)
{
return paride_register(&ktti);
}
static void __exit ktti_exit(void)
{
paride_unregister(&ktti);
}
