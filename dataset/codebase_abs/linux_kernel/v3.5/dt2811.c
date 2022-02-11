static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = F_2 ( V_6 -> V_9 ) ;
int V_10 = V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_13 ; V_12 ++ ) {
F_3 ( V_8 , V_2 -> V_14 + V_15 ) ;
while ( V_10
&& F_4 ( V_2 -> V_14 + V_16 ) & V_17 )
V_10 -- ;
if ( ! V_10 )
return - V_18 ;
V_7 [ V_12 ] = F_4 ( V_2 -> V_14 + V_19 ) ;
V_7 [ V_12 ] |= F_4 ( V_2 -> V_14 + V_20 ) << 8 ;
V_7 [ V_12 ] &= 0xfff ;
}
return V_12 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_12 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_13 ; V_12 ++ ) {
F_3 ( V_7 [ V_12 ] & 0xff , V_2 -> V_14 + V_21 + 2 * V_8 ) ;
F_3 ( ( V_7 [ V_12 ] >> 8 ) & 0xff ,
V_2 -> V_14 + V_22 + 2 * V_8 ) ;
V_23 -> V_24 [ V_8 ] = V_7 [ V_12 ] ;
}
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_12 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_13 ; V_12 ++ )
V_7 [ V_12 ] = V_23 -> V_24 [ V_8 ] ;
return V_12 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_13 != 2 )
return - V_25 ;
V_7 [ 1 ] = F_4 ( V_2 -> V_14 + V_26 ) ;
return 2 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_13 != 2 )
return - V_25 ;
V_4 -> V_27 &= ~ V_7 [ 0 ] ;
V_4 -> V_27 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_3 ( V_4 -> V_27 , V_2 -> V_14 + V_26 ) ;
V_7 [ 1 ] = V_4 -> V_27 ;
return 2 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_30 ;
struct V_3 * V_4 ;
unsigned long V_14 ;
V_14 = V_29 -> V_31 [ 0 ] ;
F_10 ( V_32 L_1 , V_2 -> V_33 , V_14 ) ;
if ( ! F_11 ( V_14 , V_34 , V_35 ) ) {
F_10 ( V_36 L_2 ) ;
return - V_37 ;
}
V_2 -> V_14 = V_14 ;
V_2 -> V_38 = V_39 -> V_40 ;
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
V_30 = F_12 ( V_2 , 4 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_13 ( V_2 , sizeof( struct V_41 ) ) ;
if ( V_30 < 0 )
return V_30 ;
switch ( V_29 -> V_31 [ 2 ] ) {
case 0 :
V_23 -> V_42 = V_43 ;
break;
case 1 :
V_23 -> V_42 = V_44 ;
break;
case 2 :
V_23 -> V_42 = V_45 ;
break;
default:
V_23 -> V_42 = V_43 ;
break;
}
switch ( V_29 -> V_31 [ 4 ] ) {
case 0 :
V_23 -> V_46 [ 0 ] = V_47 ;
break;
case 1 :
V_23 -> V_46 [ 0 ] = V_48 ;
break;
case 2 :
V_23 -> V_46 [ 0 ] = V_49 ;
break;
default:
V_23 -> V_46 [ 0 ] = V_47 ;
break;
}
switch ( V_29 -> V_31 [ 5 ] ) {
case 0 :
V_23 -> V_46 [ 1 ] = V_47 ;
break;
case 1 :
V_23 -> V_46 [ 1 ] = V_48 ;
break;
case 2 :
V_23 -> V_46 [ 1 ] = V_49 ;
break;
default:
V_23 -> V_46 [ 1 ] = V_47 ;
break;
}
V_4 = V_2 -> V_50 + 0 ;
V_4 -> type = V_51 ;
V_4 -> V_52 = V_53 | V_54 ;
V_4 -> V_55 = V_23 -> V_42 == V_44 ? 8 : 16 ;
V_4 -> V_56 = F_1 ;
V_4 -> V_57 = 0xfff ;
switch ( V_29 -> V_31 [ 3 ] ) {
case 0 :
default:
V_4 -> V_58 = V_39 -> V_59 ;
break;
case 1 :
V_4 -> V_58 = V_39 -> V_60 ;
break;
case 2 :
V_4 -> V_58 = V_39 -> V_61 ;
break;
}
V_4 = V_2 -> V_50 + 1 ;
V_4 -> type = V_62 ;
V_4 -> V_52 = V_63 ;
V_4 -> V_55 = 2 ;
V_4 -> V_64 = F_5 ;
V_4 -> V_56 = F_6 ;
V_4 -> V_57 = 0xfff ;
V_4 -> V_65 = V_23 -> V_66 ;
V_23 -> V_66 [ 0 ] = V_67 [ V_23 -> V_46 [ 0 ] ] ;
V_23 -> V_66 [ 1 ] = V_67 [ V_23 -> V_46 [ 1 ] ] ;
V_4 = V_2 -> V_50 + 2 ;
V_4 -> type = V_68 ;
V_4 -> V_52 = V_53 ;
V_4 -> V_55 = 8 ;
V_4 -> V_69 = F_7 ;
V_4 -> V_57 = 1 ;
V_4 -> V_58 = & V_70 ;
V_4 = V_2 -> V_50 + 3 ;
V_4 -> type = V_71 ;
V_4 -> V_52 = V_63 ;
V_4 -> V_55 = 8 ;
V_4 -> V_69 = F_8 ;
V_4 -> V_57 = 1 ;
V_4 -> V_27 = 0 ;
V_4 -> V_58 = & V_70 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_72 )
F_15 ( V_2 -> V_72 , V_2 ) ;
if ( V_2 -> V_14 )
F_16 ( V_2 -> V_14 , V_34 ) ;
}
