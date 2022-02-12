static void aten_write_regr( PIA *pi, int cont, int regr, int val)
{ int r;
r = regr + cont_map[cont] + 0x80;
w0(r); w2(0xe); w2(6); w0(val); w2(7); w2(6); w2(0xc);
}
static int aten_read_regr( PIA *pi, int cont, int regr )
{ int a, b, r;
r = regr + cont_map[cont] + 0x40;
switch (pi->mode) {
case 0: w0(r); w2(0xe); w2(6);
w2(7); w2(6); w2(0);
a = r1(); w0(0x10); b = r1(); w2(0xc);
return j44(a,b);
case 1: r |= 0x10;
w0(r); w2(0xe); w2(6); w0(0xff);
w2(0x27); w2(0x26); w2(0x20);
a = r0();
w2(0x26); w2(0xc);
return a;
}
return -1;
}
static void aten_read_block( PIA *pi, char * buf, int count )
{ int k, a, b, c, d;
switch (pi->mode) {
case 0: w0(0x48); w2(0xe); w2(6);
for (k=0;k<count/2;k++) {
w2(7); w2(6); w2(2);
a = r1(); w0(0x58); b = r1();
w2(0); d = r1(); w0(0x48); c = r1();
buf[2*k] = j44(c,d);
buf[2*k+1] = j44(a,b);
}
w2(0xc);
break;
case 1: w0(0x58); w2(0xe); w2(6);
for (k=0;k<count/2;k++) {
w2(0x27); w2(0x26); w2(0x22);
a = r0(); w2(0x20); b = r0();
buf[2*k] = b; buf[2*k+1] = a;
}
w2(0x26); w2(0xc);
break;
}
}
static void aten_write_block( PIA *pi, char * buf, int count )
{ int k;
w0(0x88); w2(0xe); w2(6);
for (k=0;k<count/2;k++) {
w0(buf[2*k+1]); w2(0xe); w2(6);
w0(buf[2*k]); w2(7); w2(6);
}
w2(0xc);
}
static void aten_connect ( PIA *pi )
{ pi->saved_r0 = r0();
pi->saved_r2 = r2();
w2(0xc);
}
static void aten_disconnect ( PIA *pi )
{ w0(pi->saved_r0);
w2(pi->saved_r2);
}
static void aten_log_adapter( PIA *pi, char * scratch, int verbose )
{ char *mode_string[2] = {"4-bit","8-bit"};
printk("%s: aten %s, ATEN EH-100 at 0x%x, ",
pi->device,ATEN_VERSION,pi->port);
printk("mode %d (%s), delay %d\n",pi->mode,
mode_string[pi->mode],pi->delay);
}
static int __init aten_init(void)
{
return paride_register(&aten);
}
static void __exit aten_exit(void)
{
paride_unregister( &aten );
}
