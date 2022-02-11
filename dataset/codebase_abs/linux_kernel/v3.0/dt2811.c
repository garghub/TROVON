static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
V_9 = V_5 -> V_10 [ 0 ] ;
F_6 ( V_11 L_1 , V_3 -> V_12 , V_9 ) ;
if ( ! F_7 ( V_9 , V_13 , V_14 ) ) {
F_6 ( V_15 L_2 ) ;
return - V_16 ;
}
V_3 -> V_9 = V_9 ;
V_3 -> V_17 = V_18 -> V_19 ;
#if 0
outb(0, dev->iobase + DT2811_ADCSR);
udelay(100);
i = inb(dev->iobase + DT2811_ADDATLO);
i = inb(dev->iobase + DT2811_ADDATHI);
#endif
#if 0
irq = it->options[1];
if (irq < 0) {
save_flags(flags);
sti();
irqs = probe_irq_on();
outb(DT2811_CLRERROR | DT2811_INTENB,
dev->iobase + DT2811_ADCSR);
outb(0, dev->iobase + DT2811_ADGCR);
udelay(100);
irq = probe_irq_off(irqs);
restore_flags(flags);
if (inb(dev->iobase + DT2811_ADCSR) & DT2811_ADERROR)
printk(KERN_ERR "error probing irq (bad)\n");
dev->irq = 0;
if (irq > 0) {
i = inb(dev->iobase + DT2811_ADDATLO);
i = inb(dev->iobase + DT2811_ADDATHI);
printk(KERN_INFO "(irq = %d)\n", irq);
ret = request_irq(irq, dt2811_interrupt, 0,
driver_name, dev);
if (ret < 0)
return -EIO;
dev->irq = irq;
} else if (irq == 0) {
printk(KERN_INFO "(no irq)\n");
} else {
printk(KERN_ERR "( multiple irq's -- this is bad! )\n");
}
}
#endif
V_6 = F_8 ( V_3 , 4 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_9 ( V_3 , sizeof( struct V_20 ) ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_5 -> V_10 [ 2 ] ) {
case 0 :
V_21 -> V_22 = V_23 ;
break;
case 1 :
V_21 -> V_22 = V_24 ;
break;
case 2 :
V_21 -> V_22 = V_25 ;
break;
default:
V_21 -> V_22 = V_23 ;
break;
}
switch ( V_5 -> V_10 [ 4 ] ) {
case 0 :
V_21 -> V_26 [ 0 ] = V_27 ;
break;
case 1 :
V_21 -> V_26 [ 0 ] = V_28 ;
break;
case 2 :
V_21 -> V_26 [ 0 ] = V_29 ;
break;
default:
V_21 -> V_26 [ 0 ] = V_27 ;
break;
}
switch ( V_5 -> V_10 [ 5 ] ) {
case 0 :
V_21 -> V_26 [ 1 ] = V_27 ;
break;
case 1 :
V_21 -> V_26 [ 1 ] = V_28 ;
break;
case 2 :
V_21 -> V_26 [ 1 ] = V_29 ;
break;
default:
V_21 -> V_26 [ 1 ] = V_27 ;
break;
}
V_8 = V_3 -> V_30 + 0 ;
V_8 -> type = V_31 ;
V_8 -> V_32 = V_33 | V_34 ;
V_8 -> V_35 = V_21 -> V_22 == V_24 ? 8 : 16 ;
V_8 -> V_36 = V_37 ;
V_8 -> V_38 = 0xfff ;
switch ( V_5 -> V_10 [ 3 ] ) {
case 0 :
default:
V_8 -> V_39 = V_18 -> V_40 ;
break;
case 1 :
V_8 -> V_39 = V_18 -> V_41 ;
break;
case 2 :
V_8 -> V_39 = V_18 -> V_42 ;
break;
}
V_8 = V_3 -> V_30 + 1 ;
V_8 -> type = V_43 ;
V_8 -> V_32 = V_44 ;
V_8 -> V_35 = 2 ;
V_8 -> V_45 = V_46 ;
V_8 -> V_36 = V_47 ;
V_8 -> V_38 = 0xfff ;
V_8 -> V_48 = V_21 -> V_49 ;
V_21 -> V_49 [ 0 ] = V_50 [ V_21 -> V_26 [ 0 ] ] ;
V_21 -> V_49 [ 1 ] = V_50 [ V_21 -> V_26 [ 1 ] ] ;
V_8 = V_3 -> V_30 + 2 ;
V_8 -> type = V_51 ;
V_8 -> V_32 = V_33 ;
V_8 -> V_35 = 8 ;
V_8 -> V_52 = V_53 ;
V_8 -> V_38 = 1 ;
V_8 -> V_39 = & V_54 ;
V_8 = V_3 -> V_30 + 3 ;
V_8 -> type = V_55 ;
V_8 -> V_32 = V_44 ;
V_8 -> V_35 = 8 ;
V_8 -> V_52 = V_56 ;
V_8 -> V_38 = 1 ;
V_8 -> V_57 = 0 ;
V_8 -> V_39 = & V_54 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
F_6 ( V_11 L_3 , V_3 -> V_12 ) ;
if ( V_3 -> V_58 )
F_11 ( V_3 -> V_58 , V_3 ) ;
if ( V_3 -> V_9 )
F_12 ( V_3 -> V_9 , V_13 ) ;
return 0 ;
}
static int V_37 ( struct V_2 * V_3 , struct V_7 * V_8 ,
struct V_59 * V_60 , unsigned int * V_61 )
{
int V_62 = F_13 ( V_60 -> V_63 ) ;
int V_64 = V_65 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_60 -> V_67 ; V_66 ++ ) {
F_14 ( V_62 , V_3 -> V_9 + V_68 ) ;
while ( V_64
&& F_15 ( V_3 -> V_9 + V_69 ) & V_70 )
V_64 -- ;
if ( ! V_64 )
return - V_71 ;
V_61 [ V_66 ] = F_15 ( V_3 -> V_9 + V_72 ) ;
V_61 [ V_66 ] |= F_15 ( V_3 -> V_9 + V_73 ) << 8 ;
V_61 [ V_66 ] &= 0xfff ;
}
return V_66 ;
}
static int V_46 ( struct V_2 * V_3 , struct V_7 * V_8 ,
struct V_59 * V_60 , unsigned int * V_61 )
{
int V_66 ;
int V_62 ;
V_62 = F_13 ( V_60 -> V_63 ) ;
for ( V_66 = 0 ; V_66 < V_60 -> V_67 ; V_66 ++ ) {
F_14 ( V_61 [ V_66 ] & 0xff , V_3 -> V_9 + V_74 + 2 * V_62 ) ;
F_14 ( ( V_61 [ V_66 ] >> 8 ) & 0xff ,
V_3 -> V_9 + V_75 + 2 * V_62 ) ;
V_21 -> V_76 [ V_62 ] = V_61 [ V_66 ] ;
}
return V_66 ;
}
static int V_47 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
struct V_59 * V_60 , unsigned int * V_61 )
{
int V_66 ;
int V_62 ;
V_62 = F_13 ( V_60 -> V_63 ) ;
for ( V_66 = 0 ; V_66 < V_60 -> V_67 ; V_66 ++ )
V_61 [ V_66 ] = V_21 -> V_76 [ V_62 ] ;
return V_66 ;
}
static int V_53 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
struct V_59 * V_60 , unsigned int * V_61 )
{
if ( V_60 -> V_67 != 2 )
return - V_77 ;
V_61 [ 1 ] = F_15 ( V_3 -> V_9 + V_78 ) ;
return 2 ;
}
static int V_56 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
struct V_59 * V_60 , unsigned int * V_61 )
{
if ( V_60 -> V_67 != 2 )
return - V_77 ;
V_8 -> V_57 &= ~ V_61 [ 0 ] ;
V_8 -> V_57 |= V_61 [ 0 ] & V_61 [ 1 ] ;
F_14 ( V_8 -> V_57 , V_3 -> V_9 + V_78 ) ;
V_61 [ 1 ] = V_8 -> V_57 ;
return 2 ;
}
