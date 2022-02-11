static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 , V_10 , V_11 , V_12 ;
int V_13 ;
int V_14 = 0 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_9 ; V_9 ++ ) {
V_13 = F_6 ( V_7 -> V_15 ) ;
F_7 ( V_13 , V_3 -> V_16 + V_17 ) ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
V_14 = F_8 ( V_3 -> V_16 + V_17 ) ;
F_9 ( V_19 L_1 , V_14 ) ;
F_10 ( 10 ) ;
if ( V_14 & V_20 )
break;
}
if ( V_10 >= V_18 ) {
F_9 ( V_19 L_1 , V_14 ) ;
return - V_21 ;
}
V_11 = F_8 ( V_3 -> V_16 + V_22 ) ;
V_12 = F_8 ( V_3 -> V_16 + V_22 ) ;
V_8 [ V_9 ] = ( V_11 << 4 ) | ( V_12 >> 4 ) ;
}
return V_9 ;
}
static int F_11 ( unsigned int * V_23 , unsigned int V_24 )
{
int V_10 ;
unsigned int V_25 ;
V_25 = 10000 ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
if ( ( 2 * ( * V_23 ) ) < ( V_25 * 11 ) )
break;
V_25 *= 10 ;
}
* V_23 = V_25 ;
return V_10 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_26 * V_27 )
{
int V_28 = 0 ;
int V_29 ;
V_29 = V_27 -> V_30 ;
V_27 -> V_30 &= V_31 ;
if ( ! V_27 -> V_30 || V_29 != V_27 -> V_30 )
V_28 ++ ;
V_29 = V_27 -> V_32 ;
V_27 -> V_32 &= V_33 ;
if ( ! V_27 -> V_32 || V_29 != V_27 -> V_32 )
V_28 ++ ;
V_29 = V_27 -> V_34 ;
V_27 -> V_34 &= V_31 ;
if ( ! V_27 -> V_34 || V_29 != V_27 -> V_34 )
V_28 ++ ;
V_29 = V_27 -> V_35 ;
V_27 -> V_35 &= V_36 ;
if ( ! V_27 -> V_35 || V_29 != V_27 -> V_35 )
V_28 ++ ;
V_29 = V_27 -> V_37 ;
V_27 -> V_37 &= V_36 | V_38 ;
if ( ! V_27 -> V_37 || V_29 != V_27 -> V_37 )
V_28 ++ ;
if ( V_28 )
return 1 ;
if ( V_27 -> V_37 != V_33 && V_27 -> V_37 != V_39 )
V_28 ++ ;
if ( V_28 )
return 2 ;
if ( V_27 -> V_40 != 0 ) {
V_27 -> V_40 = 0 ;
V_28 ++ ;
}
if ( V_27 -> V_41 > 1000000000 ) {
V_27 -> V_41 = 1000000000 ;
V_28 ++ ;
}
if ( V_27 -> V_41 < V_42 ) {
V_27 -> V_41 = V_42 ;
V_28 ++ ;
}
if ( V_27 -> V_43 != V_27 -> V_44 ) {
V_27 -> V_43 = V_27 -> V_44 ;
V_28 ++ ;
}
if ( V_27 -> V_37 == V_36 ) {
if ( V_27 -> V_45 < 2 ) {
V_27 -> V_45 = 2 ;
V_28 ++ ;
}
} else {
if ( V_27 -> V_45 != 0 ) {
V_27 -> V_45 = 0 ;
V_28 ++ ;
}
}
if ( V_28 )
return 3 ;
V_29 = V_27 -> V_41 ;
F_11 ( & V_27 -> V_41 , V_27 -> V_24 & V_46 ) ;
if ( V_29 != V_27 -> V_41 )
V_28 ++ ;
if ( V_28 )
return 4 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_26 * V_27 = & V_5 -> V_47 -> V_27 ;
int V_13 ;
int V_48 ;
V_48 =
F_11 ( & V_27 -> V_41 ,
V_27 -> V_24 & V_46 ) ;
V_13 = F_6 ( V_27 -> V_49 [ 0 ] ) ;
V_50 -> V_51 = V_27 -> V_45 ;
F_7 ( V_13 | V_52 | ( V_48 << 5 ) , V_3 -> V_16 + V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_53 * V_54 )
{
int V_10 , V_55 ;
int V_56 ;
struct V_4 * V_5 ;
unsigned long V_16 ;
V_16 = V_54 -> V_57 [ 0 ] ;
F_9 ( V_19 L_2 , V_3 -> V_58 , V_16 ) ;
if ( ! F_15 ( V_16 , V_59 , L_3 ) ) {
F_9 ( V_60 L_4 ) ;
return - V_61 ;
}
V_3 -> V_16 = V_16 ;
V_3 -> V_62 = L_3 ;
F_7 ( 0 , V_3 -> V_16 + V_17 ) ;
F_10 ( 100 ) ;
if ( F_8 ( V_3 -> V_16 + V_17 ) & V_63 ) {
F_9 ( V_60 L_5 ) ;
return - V_61 ;
}
V_10 = F_8 ( V_3 -> V_16 + V_22 ) ;
V_10 = F_8 ( V_3 -> V_16 + V_22 ) ;
V_55 = V_54 -> V_57 [ 1 ] ;
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
V_3 -> V_55 = 0 ;
if ( V_55 > 0 ) {
if ( F_16 ( V_55 , V_64 , 0 , L_3 , V_3 ) ) {
F_9 ( V_65 L_6 , V_55 ) ;
} else {
F_9 ( V_19 L_7 , V_55 ) ;
V_3 -> V_55 = V_55 ;
}
} else if ( V_55 == 0 ) {
F_9 ( V_65 L_8 ) ;
} else {
#if 0
printk(KERN_DEBUG "(probe returned multiple irqs--bad)\n");
#else
F_9 ( V_65 L_9 ) ;
#endif
}
V_56 = F_17 ( V_3 , 1 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_18 ( V_3 , sizeof( struct V_66 ) ) ;
if ( V_56 < 0 )
return V_56 ;
V_5 = V_3 -> V_67 + 0 ;
V_3 -> V_68 = V_5 ;
V_5 -> type = V_69 ;
V_5 -> V_70 = V_71 | V_72 | V_73 ;
V_5 -> V_74 = 16 ;
V_5 -> V_75 = 1 ;
V_5 -> V_76 = F_5 ;
V_5 -> V_77 = F_13 ;
V_5 -> V_78 = F_12 ;
V_5 -> V_79 = 0xfff ;
V_5 -> V_80 = & V_81 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
F_9 ( V_19 L_10 , V_3 -> V_58 ) ;
if ( V_3 -> V_55 )
F_20 ( V_3 -> V_55 , V_3 ) ;
if ( V_3 -> V_16 )
F_21 ( V_3 -> V_16 , V_59 ) ;
return 0 ;
}
static T_3 V_64 ( int V_55 , void * V_82 )
{
int V_12 , V_11 ;
struct V_2 * V_3 = V_82 ;
struct V_4 * V_5 ;
int V_8 ;
if ( ! V_3 -> V_83 ) {
F_22 ( V_3 , L_11 ) ;
return V_84 ;
}
V_5 = V_3 -> V_67 + 0 ;
V_11 = F_8 ( V_3 -> V_16 + V_22 ) ;
V_12 = F_8 ( V_3 -> V_16 + V_22 ) ;
V_8 = ( V_11 << 4 ) | ( V_12 >> 4 ) ;
if ( ! ( -- V_50 -> V_51 ) ) {
int V_10 ;
F_7 ( 0 , V_3 -> V_16 + V_17 ) ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
if ( F_8 ( V_3 -> V_16 + V_17 ) & V_20 )
break;
}
F_8 ( V_3 -> V_16 + V_22 ) ;
F_8 ( V_3 -> V_16 + V_22 ) ;
V_5 -> V_47 -> V_85 |= V_86 ;
}
F_23 ( V_3 , V_5 ) ;
return V_84 ;
}
