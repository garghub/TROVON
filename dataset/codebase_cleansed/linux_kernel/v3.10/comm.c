static int comm_read_regr( PIA *pi, int cont, int regr )
{ int l, h, r;
r = regr + cont_map[cont];
switch (pi->mode) {
case 0: w0(r); P1; w0(0);
w2(6); l = r1(); w0(0x80); h = r1(); w2(4);
return j44(l,h);
case 1: w0(r+0x20); P1;
w0(0); w2(0x26); h = r0(); w2(4);
return h;
case 2:
case 3:
case 4: w3(r+0x20); (void)r1();
w2(0x24); h = r4(); w2(4);
return h;
}
return -1;
}
static void comm_write_regr( PIA *pi, int cont, int regr, int val )
{ int r;
r = regr + cont_map[cont];
switch (pi->mode) {
case 0:
case 1: w0(r); P1; w0(val); P2;
break;
case 2:
case 3:
case 4: w3(r); (void)r1(); w4(val);
break;
}
}
static void comm_connect ( PIA *pi )
{ pi->saved_r0 = r0();
pi->saved_r2 = r2();
w2(4); w0(0xff); w2(6);
w2(4); w0(0xaa); w2(6);
w2(4); w0(0x00); w2(6);
w2(4); w0(0x87); w2(6);
w2(4); w0(0xe0); w2(0xc); w2(0xc); w2(4);
}
static void comm_disconnect ( PIA *pi )
{ w2(0); w2(0); w2(0); w2(4);
w0(pi->saved_r0);
w2(pi->saved_r2);
}
static void comm_read_block( PIA *pi, char * buf, int count )
{ int i, l, h;
switch (pi->mode) {
case 0: w0(0x48); P1;
for(i=0;i<count;i++) {
w0(0); w2(6); l = r1();
w0(0x80); h = r1(); w2(4);
buf[i] = j44(l,h);
}
break;
case 1: w0(0x68); P1; w0(0);
for(i=0;i<count;i++) {
w2(0x26); buf[i] = r0(); w2(0x24);
}
w2(4);
break;
case 2: w3(0x68); (void)r1(); w2(0x24);
for (i=0;i<count;i++) buf[i] = r4();
w2(4);
break;
case 3: w3(0x68); (void)r1(); w2(0x24);
for (i=0;i<count/2;i++) ((u16 *)buf)[i] = r4w();
w2(4);
break;
case 4: w3(0x68); (void)r1(); w2(0x24);
for (i=0;i<count/4;i++) ((u32 *)buf)[i] = r4l();
w2(4);
break;
}
}
static void comm_write_block( PIA *pi, char * buf, int count )
{ int k;
switch (pi->mode) {
case 0:
case 1: w0(0x68); P1;
for (k=0;k<count;k++) {
w2(5); w0(buf[k^1]); w2(7);
}
w2(5); w2(4);
break;
case 2: w3(0x48); (void)r1();
for (k=0;k<count;k++) w4(buf[k^1]);
break;
case 3: w3(0x48); (void)r1();
for (k=0;k<count/2;k++) w4w(pi_swab16(buf,k));
break;
case 4: w3(0x48); (void)r1();
for (k=0;k<count/4;k++) w4l(pi_swab32(buf,k));
break;
}
}
static void comm_log_adapter( PIA *pi, char * scratch, int verbose )
{ char *mode_string[5] = {"4-bit","8-bit","EPP-8","EPP-16","EPP-32"};
printk("%s: comm %s, DataStor Commuter at 0x%x, ",
pi->device,COMM_VERSION,pi->port);
printk("mode %d (%s), delay %d\n",pi->mode,
mode_string[pi->mode],pi->delay);
}
static int __init comm_init(void)
{
return paride_register(&comm);
}
static void __exit comm_exit(void)
{
paride_unregister(&comm);
}
