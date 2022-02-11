static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
F_2 ( & V_6 -> V_9 , V_8 ) ;
if ( V_4 < 8 ) {
F_3 ( V_3 , V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_10 ) ;
F_3 ( V_3 , V_11 ) ;
}
F_4 ( & V_6 -> V_9 , V_8 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
T_1 V_12 ;
F_2 ( & V_6 -> V_9 , V_8 ) ;
if ( V_4 < 8 ) {
V_12 = F_6 ( V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_10 ) ;
V_12 = F_6 ( V_11 ) ;
}
F_4 ( & V_6 -> V_9 , V_8 ) ;
return V_12 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_13 )
F_9 ( V_2 -> V_13 , V_2 ) ;
}
static int F_10 ( struct V_14 * V_15 )
{
V_16 = V_15 ;
F_11 ( V_15 ) ;
return 0 ;
}
static void F_12 ( struct V_14 * V_15 )
{
F_13 ( V_15 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
F_12 ( V_15 ) ;
}
static int F_15 ( struct V_14 * V_15 )
{
F_16 ( L_1 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 )
{
F_16 ( L_2 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_17 , void * V_18 )
{
int V_19 , V_12 ;
V_17 -> V_20 [ 0 ] -> V_8 &= ~ V_21 ;
V_17 -> V_20 [ 0 ] -> V_8 |= V_22 ;
for ( V_19 = 0x000 ; V_19 < 0x400 ; V_19 += 0x20 ) {
V_17 -> V_20 [ 0 ] -> V_23 = V_19 ;
V_12 = F_19 ( V_17 ) ;
if ( ! V_12 )
return 0 ;
}
return - V_24 ;
}
static void F_11 ( struct V_14 * V_15 )
{
int V_12 ;
F_16 ( L_3 , V_15 ) ;
V_15 -> V_25 |= V_26 | V_27 ;
V_12 = F_20 ( V_15 , F_18 , NULL ) ;
if ( V_12 ) {
F_21 ( & V_15 -> V_2 , L_4 ) ;
return;
}
if ( ! V_15 -> V_13 )
F_22 ( & V_15 -> V_2 , L_5 ) ;
V_12 = F_23 ( V_15 ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_5 * V_6 ;
struct V_14 * V_15 ;
unsigned int V_13 ;
int V_12 ;
F_16 ( L_6 , V_2 , V_29 ) ;
V_15 = V_16 ;
if ( ! V_15 )
return - V_30 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 = V_15 -> V_20 [ 0 ] -> V_23 ;
V_13 = V_15 -> V_13 ;
V_2 -> V_34 = V_35 + F_25 ( V_2 , V_15 ) ;
#if 0
{
int i;
printk("comedi%d: %s: DAQCard: io 0x%04lx, irq %u, ",
dev->minor, dev->driver->driver_name, dev->iobase, irq);
printk(" board fingerprint:");
for (i = 0; i < 32; i += 2) {
printk(" %04x %02x", inw(dev->iobase + i),
inb(dev->iobase + i + 1));
}
printk("\n");
printk(" board fingerprint (windowed):");
for (i = 0; i < 10; i++)
printk(" 0x%04x", win_in(i));
printk("\n");
printk("boardtype.name: %s\n", boardtype.name);
}
#endif
V_2 -> V_36 = V_37 . V_38 ;
V_12 = F_26 ( V_13 , V_39 , V_40 ,
L_7 , V_2 ) ;
if ( V_12 < 0 ) {
F_27 ( V_2 -> V_41 , L_8 ) ;
return - V_42 ;
}
V_2 -> V_13 = V_13 ;
V_12 = F_28 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_6 = V_2 -> V_7 ;
V_6 -> V_43 = & F_1 ;
V_6 -> V_44 = & F_5 ;
V_6 -> V_45 = & V_46 ;
V_6 -> V_47 = & V_48 ;
V_12 = F_29 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( V_35 [ V_49 ] . V_51 == V_15 -> V_52 )
return V_49 ;
}
F_27 ( V_2 -> V_41 ,
L_9 , V_15 -> V_52 ) ;
return 0 ;
}
int F_30 ( void )
{
F_31 ( & V_53 ) ;
F_32 ( & V_32 ) ;
return 0 ;
}
void F_33 ( void )
{
F_34 ( & V_53 ) ;
#if 0
while (cur_dev != NULL)
cs_detach(cur_dev->handle);
#endif
F_35 ( & V_32 ) ;
}
