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
struct V_21 * V_22 = V_2 -> V_23 ;
int V_12 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_13 ; V_12 ++ ) {
F_3 ( V_7 [ V_12 ] & 0xff , V_2 -> V_14 + V_24 + 2 * V_8 ) ;
F_3 ( ( V_7 [ V_12 ] >> 8 ) & 0xff ,
V_2 -> V_14 + V_25 + 2 * V_8 ) ;
V_22 -> V_26 [ V_8 ] = V_7 [ V_12 ] ;
}
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_21 * V_22 = V_2 -> V_23 ;
int V_12 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_9 ) ;
for ( V_12 = 0 ; V_12 < V_6 -> V_13 ; V_12 ++ )
V_7 [ V_12 ] = V_22 -> V_26 [ V_8 ] ;
return V_12 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_14 + V_27 ) ;
return V_6 -> V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_4 -> V_28 &= ~ V_7 [ 0 ] ;
V_4 -> V_28 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_3 ( V_4 -> V_28 , V_2 -> V_14 + V_27 ) ;
V_7 [ 1 ] = V_4 -> V_28 ;
return V_6 -> V_13 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
const struct V_31 * V_32 = F_10 ( V_2 ) ;
struct V_21 * V_22 ;
int V_33 ;
struct V_3 * V_4 ;
V_33 = F_11 ( V_2 , V_30 -> V_34 [ 0 ] , V_35 ) ;
if ( V_33 )
return V_33 ;
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
dev->board_name, dev);
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
V_33 = F_12 ( V_2 , 4 ) ;
if ( V_33 )
return V_33 ;
V_22 = F_13 ( V_2 , sizeof( * V_22 ) ) ;
if ( ! V_22 )
return - V_36 ;
switch ( V_30 -> V_34 [ 2 ] ) {
case 0 :
V_22 -> V_37 = V_38 ;
break;
case 1 :
V_22 -> V_37 = V_39 ;
break;
case 2 :
V_22 -> V_37 = V_40 ;
break;
default:
V_22 -> V_37 = V_38 ;
break;
}
switch ( V_30 -> V_34 [ 4 ] ) {
case 0 :
V_22 -> V_41 [ 0 ] = V_42 ;
break;
case 1 :
V_22 -> V_41 [ 0 ] = V_43 ;
break;
case 2 :
V_22 -> V_41 [ 0 ] = V_44 ;
break;
default:
V_22 -> V_41 [ 0 ] = V_42 ;
break;
}
switch ( V_30 -> V_34 [ 5 ] ) {
case 0 :
V_22 -> V_41 [ 1 ] = V_42 ;
break;
case 1 :
V_22 -> V_41 [ 1 ] = V_43 ;
break;
case 2 :
V_22 -> V_41 [ 1 ] = V_44 ;
break;
default:
V_22 -> V_41 [ 1 ] = V_42 ;
break;
}
V_4 = & V_2 -> V_45 [ 0 ] ;
V_4 -> type = V_46 ;
V_4 -> V_47 = V_48 | V_49 ;
V_4 -> V_50 = V_22 -> V_37 == V_39 ? 8 : 16 ;
V_4 -> V_51 = F_1 ;
V_4 -> V_52 = 0xfff ;
switch ( V_30 -> V_34 [ 3 ] ) {
case 0 :
default:
V_4 -> V_53 = V_32 -> V_54 ;
break;
case 1 :
V_4 -> V_53 = V_32 -> V_55 ;
break;
case 2 :
V_4 -> V_53 = V_32 -> V_56 ;
break;
}
V_4 = & V_2 -> V_45 [ 1 ] ;
V_4 -> type = V_57 ;
V_4 -> V_47 = V_58 ;
V_4 -> V_50 = 2 ;
V_4 -> V_59 = F_5 ;
V_4 -> V_51 = F_6 ;
V_4 -> V_52 = 0xfff ;
V_4 -> V_60 = V_22 -> V_61 ;
V_22 -> V_61 [ 0 ] = V_62 [ V_22 -> V_41 [ 0 ] ] ;
V_22 -> V_61 [ 1 ] = V_62 [ V_22 -> V_41 [ 1 ] ] ;
V_4 = & V_2 -> V_45 [ 2 ] ;
V_4 -> type = V_63 ;
V_4 -> V_47 = V_48 ;
V_4 -> V_50 = 8 ;
V_4 -> V_64 = F_7 ;
V_4 -> V_52 = 1 ;
V_4 -> V_53 = & V_65 ;
V_4 = & V_2 -> V_45 [ 3 ] ;
V_4 -> type = V_66 ;
V_4 -> V_47 = V_58 ;
V_4 -> V_50 = 8 ;
V_4 -> V_64 = F_8 ;
V_4 -> V_52 = 1 ;
V_4 -> V_28 = 0 ;
V_4 -> V_53 = & V_65 ;
return 0 ;
}
