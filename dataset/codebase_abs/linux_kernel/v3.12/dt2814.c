static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 , V_9 , V_10 , V_11 ;
int V_12 ;
int V_13 = 0 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
V_12 = F_2 ( V_6 -> V_14 ) ;
F_3 ( V_12 , V_2 -> V_15 + V_16 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
V_13 = F_4 ( V_2 -> V_15 + V_16 ) ;
F_5 ( V_18 L_1 , V_13 ) ;
F_6 ( 10 ) ;
if ( V_13 & V_19 )
break;
}
if ( V_9 >= V_17 ) {
F_5 ( V_18 L_1 , V_13 ) ;
return - V_20 ;
}
V_10 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_11 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_7 [ V_8 ] = ( V_10 << 4 ) | ( V_11 >> 4 ) ;
}
return V_8 ;
}
static int F_7 ( unsigned int * V_22 , unsigned int V_23 )
{
int V_9 ;
unsigned int V_24 ;
V_24 = 10000 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
if ( ( 2 * ( * V_22 ) ) < ( V_24 * 11 ) )
break;
V_24 *= 10 ;
}
* V_22 = V_24 ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_25 * V_26 )
{
int V_27 = 0 ;
int V_28 ;
V_27 |= F_9 ( & V_26 -> V_29 , V_30 ) ;
V_27 |= F_9 ( & V_26 -> V_31 , V_32 ) ;
V_27 |= F_9 ( & V_26 -> V_33 , V_30 ) ;
V_27 |= F_9 ( & V_26 -> V_34 , V_35 ) ;
V_27 |= F_9 ( & V_26 -> V_36 , V_35 | V_37 ) ;
if ( V_27 )
return 1 ;
V_27 |= F_10 ( V_26 -> V_36 ) ;
if ( V_27 )
return 2 ;
V_27 |= F_11 ( & V_26 -> V_38 , 0 ) ;
V_27 |= F_12 ( & V_26 -> V_39 , 1000000000 ) ;
V_27 |= F_13 ( & V_26 -> V_39 ,
V_40 ) ;
V_27 |= F_11 ( & V_26 -> V_41 , V_26 -> V_42 ) ;
if ( V_26 -> V_36 == V_35 )
V_27 |= F_13 ( & V_26 -> V_43 , 2 ) ;
else
V_27 |= F_11 ( & V_26 -> V_43 , 0 ) ;
if ( V_27 )
return 3 ;
V_28 = V_26 -> V_39 ;
F_7 ( & V_26 -> V_39 , V_26 -> V_23 & V_44 ) ;
if ( V_28 != V_26 -> V_39 )
V_27 ++ ;
if ( V_27 )
return 4 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_45 * V_46 = V_2 -> V_47 ;
struct V_25 * V_26 = & V_4 -> V_48 -> V_26 ;
int V_12 ;
int V_49 ;
V_49 =
F_7 ( & V_26 -> V_39 ,
V_26 -> V_23 & V_44 ) ;
V_12 = F_2 ( V_26 -> V_50 [ 0 ] ) ;
V_46 -> V_51 = V_26 -> V_43 ;
F_3 ( V_12 | V_52 | ( V_49 << 5 ) , V_2 -> V_15 + V_16 ) ;
return 0 ;
}
static T_1 F_15 ( int V_53 , void * V_54 )
{
int V_11 , V_10 ;
struct V_1 * V_2 = V_54 ;
struct V_45 * V_46 = V_2 -> V_47 ;
struct V_3 * V_4 ;
int V_7 ;
if ( ! V_2 -> V_55 ) {
F_16 ( V_2 , L_2 ) ;
return V_56 ;
}
V_4 = & V_2 -> V_57 [ 0 ] ;
V_10 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_11 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_7 = ( V_10 << 4 ) | ( V_11 >> 4 ) ;
if ( ! ( -- V_46 -> V_51 ) ) {
int V_9 ;
F_3 ( 0 , V_2 -> V_15 + V_16 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
if ( F_4 ( V_2 -> V_15 + V_16 ) & V_19 )
break;
}
F_4 ( V_2 -> V_15 + V_21 ) ;
F_4 ( V_2 -> V_15 + V_21 ) ;
V_4 -> V_48 -> V_58 |= V_59 ;
}
F_17 ( V_2 , V_4 ) ;
return V_56 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_45 * V_46 ;
int V_9 , V_53 ;
int V_62 ;
struct V_3 * V_4 ;
V_62 = F_19 ( V_2 , V_61 -> V_63 [ 0 ] , V_64 ) ;
if ( V_62 )
return V_62 ;
F_3 ( 0 , V_2 -> V_15 + V_16 ) ;
F_6 ( 100 ) ;
if ( F_4 ( V_2 -> V_15 + V_16 ) & V_65 ) {
F_5 ( V_66 L_3 ) ;
return - V_67 ;
}
V_9 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_9 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_53 = V_61 -> V_63 [ 1 ] ;
#if 0
if (irq < 0) {
save_flags(flags);
sti();
irqs = probe_irq_on();
outb(0, dev->iobase + DT2814_CSR);
udelay(100);
irq = probe_irq_off(irqs);
restore_flags(flags);
if (inb(dev->iobase + DT2814_CSR) & DT2814_ERR)
printk(KERN_DEBUG "error probing irq (bad)\n");
i = inb(dev->iobase + DT2814_DATA);
i = inb(dev->iobase + DT2814_DATA);
}
#endif
V_2 -> V_53 = 0 ;
if ( V_53 > 0 ) {
if ( F_20 ( V_53 , F_15 , 0 , L_4 , V_2 ) ) {
F_5 ( V_68 L_5 , V_53 ) ;
} else {
F_5 ( V_18 L_6 , V_53 ) ;
V_2 -> V_53 = V_53 ;
}
} else if ( V_53 == 0 ) {
F_5 ( V_68 L_7 ) ;
} else {
#if 0
printk(KERN_DEBUG "(probe returned multiple irqs--bad)\n");
#else
F_5 ( V_68 L_8 ) ;
#endif
}
V_62 = F_21 ( V_2 , 1 ) ;
if ( V_62 )
return V_62 ;
V_46 = F_22 ( V_2 , sizeof( * V_46 ) ) ;
if ( ! V_46 )
return - V_69 ;
V_4 = & V_2 -> V_57 [ 0 ] ;
V_2 -> V_70 = V_4 ;
V_4 -> type = V_71 ;
V_4 -> V_72 = V_73 | V_74 | V_75 ;
V_4 -> V_76 = 16 ;
V_4 -> V_77 = 1 ;
V_4 -> V_78 = F_1 ;
V_4 -> V_79 = F_14 ;
V_4 -> V_80 = F_8 ;
V_4 -> V_81 = 0xfff ;
V_4 -> V_82 = & V_83 ;
return 0 ;
}
