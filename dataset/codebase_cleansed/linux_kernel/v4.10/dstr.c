static int dstr_read_regr( PIA *pi, int cont, int regr )
{ int a, b, r;
r = regr + cont_map[cont];
w0(0x81); P1;
if (pi->mode) { w0(0x11); } else { w0(1); }
P2; w0(r); P1;
switch (pi->mode) {
case 0: w2(6); a = r1(); w2(4); w2(6); b = r1(); w2(4);
return j44(a,b);
case 1: w0(0); w2(0x26); a = r0(); w2(4);
return a;
case 2:
case 3:
case 4: w2(0x24); a = r4(); w2(4);
return a;
}
return -1;
}
static void dstr_write_regr( PIA *pi, int cont, int regr, int val )
{ int r;
r = regr + cont_map[cont];
w0(0x81); P1;
if (pi->mode >= 2) { w0(0x11); } else { w0(1); }
P2; w0(r); P1;
switch (pi->mode) {
case 0:
case 1: w0(val); w2(5); w2(7); w2(5); w2(4);
break;
case 2:
case 3:
case 4: w4(val);
break;
}
}
static void dstr_connect ( PIA *pi )
{ pi->saved_r0 = r0();
pi->saved_r2 = r2();
w2(4); CCP(0xe0); w0(0xff);
}
static void dstr_disconnect ( PIA *pi )
{ CCP(0x30);
w0(pi->saved_r0);
w2(pi->saved_r2);
}
static void dstr_read_block( PIA *pi, char * buf, int count )
{ int k, a, b;
w0(0x81); P1;
if (pi->mode) { w0(0x19); } else { w0(9); }
P2; w0(0x82); P1; P3; w0(0x20); P1;
switch (pi->mode) {
case 0: for (k=0;k<count;k++) {
w2(6); a = r1(); w2(4);
w2(6); b = r1(); w2(4);
buf[k] = j44(a,b);
}
break;
case 1: w0(0);
for (k=0;k<count;k++) {
w2(0x26); buf[k] = r0(); w2(0x24);
}
w2(4);
break;
case 2: w2(0x24);
for (k=0;k<count;k++) buf[k] = r4();
w2(4);
break;
case 3: w2(0x24);
for (k=0;k<count/2;k++) ((u16 *)buf)[k] = r4w();
w2(4);
break;
case 4: w2(0x24);
for (k=0;k<count/4;k++) ((u32 *)buf)[k] = r4l();
w2(4);
break;
}
}
static void dstr_write_block( PIA *pi, char * buf, int count )
{ int k;
w0(0x81); P1;
if (pi->mode) { w0(0x19); } else { w0(9); }
P2; w0(0x82); P1; P3; w0(0x20); P1;
switch (pi->mode) {
case 0:
case 1: for (k=0;k<count;k++) {
w2(5); w0(buf[k]); w2(7);
}
w2(5); w2(4);
break;
case 2: w2(0xc5);
for (k=0;k<count;k++) w4(buf[k]);
w2(0xc4);
break;
case 3: w2(0xc5);
for (k=0;k<count/2;k++) w4w(((u16 *)buf)[k]);
w2(0xc4);
break;
case 4: w2(0xc5);
for (k=0;k<count/4;k++) w4l(((u32 *)buf)[k]);
w2(0xc4);
break;
}
}
static void dstr_log_adapter( PIA *pi, char * scratch, int verbose )
{ char *mode_string[5] = {"4-bit","8-bit","EPP-8",
"EPP-16","EPP-32"};
printk("%s: dstr %s, DataStor EP2000 at 0x%x, ",
pi->device,DSTR_VERSION,pi->port);
printk("mode %d (%s), delay %d\n",pi->mode,
mode_string[pi->mode],pi->delay);
}
static int __init dstr_init(void)
{
return paride_register(&dstr);
}
static void __exit dstr_exit(void)
{
paride_unregister(&dstr);
}
