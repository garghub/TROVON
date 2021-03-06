static int bpck6_read_regr(PIA *pi, int cont, int reg)
{
unsigned int out;
if (reg<0 || reg>7 || cont<0 || cont>2)
{
return(-1);
}
out=ppc6_rd_port(PPCSTRUCT(pi),cont?reg|8:reg);
return(out);
}
static void bpck6_write_regr(PIA *pi, int cont, int reg, int val)
{
if (reg>=0 && reg<=7 && cont>=0 && cont<=1)
{
ppc6_wr_port(PPCSTRUCT(pi),cont?reg|8:reg,(u8)val);
}
}
static void bpck6_write_block( PIA *pi, char * buf, int len )
{
ppc6_wr_port16_blk(PPCSTRUCT(pi),ATAPI_DATA,buf,(u32)len>>1);
}
static void bpck6_read_block( PIA *pi, char * buf, int len )
{
ppc6_rd_port16_blk(PPCSTRUCT(pi),ATAPI_DATA,buf,(u32)len>>1);
}
static void bpck6_connect ( PIA *pi )
{
if(verbose)
{
printk(KERN_DEBUG "connect\n");
}
if(pi->mode >=2)
{
PPCSTRUCT(pi)->mode=4+pi->mode-2;
}
else if(pi->mode==1)
{
PPCSTRUCT(pi)->mode=3;
}
else
{
PPCSTRUCT(pi)->mode=1;
}
ppc6_open(PPCSTRUCT(pi));
ppc6_wr_extout(PPCSTRUCT(pi),0x3);
}
static void bpck6_disconnect ( PIA *pi )
{
if(verbose)
{
printk("disconnect\n");
}
ppc6_wr_extout(PPCSTRUCT(pi),0x0);
ppc6_close(PPCSTRUCT(pi));
}
static int bpck6_test_port ( PIA *pi )
{
if(verbose)
{
printk(KERN_DEBUG "PARPORT indicates modes=%x for lp=0x%lx\n",
((struct pardevice*)(pi->pardev))->port->modes,
((struct pardevice *)(pi->pardev))->port->base);
}
PPCSTRUCT(pi)->ppc_id=pi->unit;
PPCSTRUCT(pi)->lpt_addr=pi->port;
if(((struct pardevice *)(pi->pardev))->port->modes &
(PARPORT_MODE_EPP)
)
{
return 5;
}
else if(((struct pardevice *)(pi->pardev))->port->modes &
(PARPORT_MODE_TRISTATE)
)
{
return 2;
}
else
{
return 1;
}
}
static int bpck6_probe_unit ( PIA *pi )
{
int out;
if(verbose)
{
printk(KERN_DEBUG "PROBE UNIT %x on port:%x\n",pi->unit,pi->port);
}
PPCSTRUCT(pi)->ppc_id=pi->unit;
PPCSTRUCT(pi)->mode=1;
out=ppc6_open(PPCSTRUCT(pi));
if(verbose)
{
printk(KERN_DEBUG "ppc_open returned %2x\n",out);
}
if(out)
{
ppc6_close(PPCSTRUCT(pi));
if(verbose)
{
printk(KERN_DEBUG "leaving probe\n");
}
return(1);
}
else
{
if(verbose)
{
printk(KERN_DEBUG "Failed open\n");
}
return(0);
}
}
static void bpck6_log_adapter( PIA *pi, char * scratch, int verbose )
{
char *mode_string[5]=
{"4-bit","8-bit","EPP-8","EPP-16","EPP-32"};
printk("%s: BACKPACK Protocol Driver V"BACKPACK_VERSION"\n",pi->device);
printk("%s: Copyright 2001 by Micro Solutions, Inc., DeKalb IL.\n",pi->device);
printk("%s: BACKPACK %s, Micro Solutions BACKPACK Drive at 0x%x\n",
pi->device,BACKPACK_VERSION,pi->port);
printk("%s: Unit: %d Mode:%d (%s) Delay %d\n",pi->device,
pi->unit,pi->mode,mode_string[pi->mode],pi->delay);
}
static int bpck6_init_proto(PIA *pi)
{
Interface *p = kzalloc(sizeof(Interface), GFP_KERNEL);
if (p) {
pi->private = (unsigned long)p;
return 0;
}
printk(KERN_ERR "%s: ERROR COULDN'T ALLOCATE MEMORY\n", pi->device);
return -1;
}
static void bpck6_release_proto(PIA *pi)
{
kfree((void *)(pi->private));
}
static int __init bpck6_init(void)
{
printk(KERN_INFO "bpck6: BACKPACK Protocol Driver V"BACKPACK_VERSION"\n");
printk(KERN_INFO "bpck6: Copyright 2001 by Micro Solutions, Inc., DeKalb IL. USA\n");
if(verbose)
printk(KERN_DEBUG "bpck6: verbose debug enabled.\n");
return paride_register(&bpck6);
}
static void __exit bpck6_exit(void)
{
paride_unregister(&bpck6);
}
