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
V_28 = V_26 -> V_29 ;
V_26 -> V_29 &= V_30 ;
if ( ! V_26 -> V_29 || V_28 != V_26 -> V_29 )
V_27 ++ ;
V_28 = V_26 -> V_31 ;
V_26 -> V_31 &= V_32 ;
if ( ! V_26 -> V_31 || V_28 != V_26 -> V_31 )
V_27 ++ ;
V_28 = V_26 -> V_33 ;
V_26 -> V_33 &= V_30 ;
if ( ! V_26 -> V_33 || V_28 != V_26 -> V_33 )
V_27 ++ ;
V_28 = V_26 -> V_34 ;
V_26 -> V_34 &= V_35 ;
if ( ! V_26 -> V_34 || V_28 != V_26 -> V_34 )
V_27 ++ ;
V_28 = V_26 -> V_36 ;
V_26 -> V_36 &= V_35 | V_37 ;
if ( ! V_26 -> V_36 || V_28 != V_26 -> V_36 )
V_27 ++ ;
if ( V_27 )
return 1 ;
if ( V_26 -> V_36 != V_32 && V_26 -> V_36 != V_38 )
V_27 ++ ;
if ( V_27 )
return 2 ;
if ( V_26 -> V_39 != 0 ) {
V_26 -> V_39 = 0 ;
V_27 ++ ;
}
if ( V_26 -> V_40 > 1000000000 ) {
V_26 -> V_40 = 1000000000 ;
V_27 ++ ;
}
if ( V_26 -> V_40 < V_41 ) {
V_26 -> V_40 = V_41 ;
V_27 ++ ;
}
if ( V_26 -> V_42 != V_26 -> V_43 ) {
V_26 -> V_42 = V_26 -> V_43 ;
V_27 ++ ;
}
if ( V_26 -> V_36 == V_35 ) {
if ( V_26 -> V_44 < 2 ) {
V_26 -> V_44 = 2 ;
V_27 ++ ;
}
} else {
if ( V_26 -> V_44 != 0 ) {
V_26 -> V_44 = 0 ;
V_27 ++ ;
}
}
if ( V_27 )
return 3 ;
V_28 = V_26 -> V_40 ;
F_7 ( & V_26 -> V_40 , V_26 -> V_23 & V_45 ) ;
if ( V_28 != V_26 -> V_40 )
V_27 ++ ;
if ( V_27 )
return 4 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_25 * V_26 = & V_4 -> V_46 -> V_26 ;
int V_12 ;
int V_47 ;
V_47 =
F_7 ( & V_26 -> V_40 ,
V_26 -> V_23 & V_45 ) ;
V_12 = F_2 ( V_26 -> V_48 [ 0 ] ) ;
V_49 -> V_50 = V_26 -> V_44 ;
F_3 ( V_12 | V_51 | ( V_47 << 5 ) , V_2 -> V_15 + V_16 ) ;
return 0 ;
}
static T_1 F_10 ( int V_52 , void * V_53 )
{
int V_11 , V_10 ;
struct V_1 * V_2 = V_53 ;
struct V_3 * V_4 ;
int V_7 ;
if ( ! V_2 -> V_54 ) {
F_11 ( V_2 , L_2 ) ;
return V_55 ;
}
V_4 = V_2 -> V_56 + 0 ;
V_10 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_11 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_7 = ( V_10 << 4 ) | ( V_11 >> 4 ) ;
if ( ! ( -- V_49 -> V_50 ) ) {
int V_9 ;
F_3 ( 0 , V_2 -> V_15 + V_16 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
if ( F_4 ( V_2 -> V_15 + V_16 ) & V_19 )
break;
}
F_4 ( V_2 -> V_15 + V_21 ) ;
F_4 ( V_2 -> V_15 + V_21 ) ;
V_4 -> V_46 -> V_57 |= V_58 ;
}
F_12 ( V_2 , V_4 ) ;
return V_55 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
int V_9 , V_52 ;
int V_61 ;
struct V_3 * V_4 ;
unsigned long V_15 ;
V_15 = V_60 -> V_62 [ 0 ] ;
F_5 ( V_18 L_3 , V_2 -> V_63 , V_15 ) ;
if ( ! F_14 ( V_15 , V_64 , L_4 ) ) {
F_5 ( V_65 L_5 ) ;
return - V_66 ;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_67 = L_4 ;
F_3 ( 0 , V_2 -> V_15 + V_16 ) ;
F_6 ( 100 ) ;
if ( F_4 ( V_2 -> V_15 + V_16 ) & V_68 ) {
F_5 ( V_65 L_6 ) ;
return - V_66 ;
}
V_9 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_9 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_52 = V_60 -> V_62 [ 1 ] ;
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
V_2 -> V_52 = 0 ;
if ( V_52 > 0 ) {
if ( F_15 ( V_52 , F_10 , 0 , L_4 , V_2 ) ) {
F_5 ( V_69 L_7 , V_52 ) ;
} else {
F_5 ( V_18 L_8 , V_52 ) ;
V_2 -> V_52 = V_52 ;
}
} else if ( V_52 == 0 ) {
F_5 ( V_69 L_9 ) ;
} else {
#if 0
printk(KERN_DEBUG "(probe returned multiple irqs--bad)\n");
#else
F_5 ( V_69 L_10 ) ;
#endif
}
V_61 = F_16 ( V_2 , 1 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_17 ( V_2 , sizeof( struct V_70 ) ) ;
if ( V_61 < 0 )
return V_61 ;
V_4 = V_2 -> V_56 + 0 ;
V_2 -> V_71 = V_4 ;
V_4 -> type = V_72 ;
V_4 -> V_73 = V_74 | V_75 | V_76 ;
V_4 -> V_77 = 16 ;
V_4 -> V_78 = 1 ;
V_4 -> V_79 = F_1 ;
V_4 -> V_80 = F_9 ;
V_4 -> V_81 = F_8 ;
V_4 -> V_82 = 0xfff ;
V_4 -> V_83 = & V_84 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 )
F_19 ( V_2 -> V_52 , V_2 ) ;
if ( V_2 -> V_15 )
F_20 ( V_2 -> V_15 , V_64 ) ;
}
