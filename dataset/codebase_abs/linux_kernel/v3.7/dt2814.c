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
if ( V_26 -> V_38 != 0 ) {
V_26 -> V_38 = 0 ;
V_27 ++ ;
}
if ( V_26 -> V_39 > 1000000000 ) {
V_26 -> V_39 = 1000000000 ;
V_27 ++ ;
}
if ( V_26 -> V_39 < V_40 ) {
V_26 -> V_39 = V_40 ;
V_27 ++ ;
}
if ( V_26 -> V_41 != V_26 -> V_42 ) {
V_26 -> V_41 = V_26 -> V_42 ;
V_27 ++ ;
}
if ( V_26 -> V_36 == V_35 ) {
if ( V_26 -> V_43 < 2 ) {
V_26 -> V_43 = 2 ;
V_27 ++ ;
}
} else {
if ( V_26 -> V_43 != 0 ) {
V_26 -> V_43 = 0 ;
V_27 ++ ;
}
}
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
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_25 * V_26 = & V_4 -> V_45 -> V_26 ;
int V_12 ;
int V_46 ;
V_46 =
F_7 ( & V_26 -> V_39 ,
V_26 -> V_23 & V_44 ) ;
V_12 = F_2 ( V_26 -> V_47 [ 0 ] ) ;
V_48 -> V_49 = V_26 -> V_43 ;
F_3 ( V_12 | V_50 | ( V_46 << 5 ) , V_2 -> V_15 + V_16 ) ;
return 0 ;
}
static T_1 F_12 ( int V_51 , void * V_52 )
{
int V_11 , V_10 ;
struct V_1 * V_2 = V_52 ;
struct V_3 * V_4 ;
int V_7 ;
if ( ! V_2 -> V_53 ) {
F_13 ( V_2 , L_2 ) ;
return V_54 ;
}
V_4 = & V_2 -> V_55 [ 0 ] ;
V_10 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_11 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_7 = ( V_10 << 4 ) | ( V_11 >> 4 ) ;
if ( ! ( -- V_48 -> V_49 ) ) {
int V_9 ;
F_3 ( 0 , V_2 -> V_15 + V_16 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
if ( F_4 ( V_2 -> V_15 + V_16 ) & V_19 )
break;
}
F_4 ( V_2 -> V_15 + V_21 ) ;
F_4 ( V_2 -> V_15 + V_21 ) ;
V_4 -> V_45 -> V_56 |= V_57 ;
}
F_14 ( V_2 , V_4 ) ;
return V_54 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
int V_9 , V_51 ;
int V_60 ;
struct V_3 * V_4 ;
unsigned long V_15 ;
V_15 = V_59 -> V_61 [ 0 ] ;
F_5 ( V_18 L_3 , V_2 -> V_62 , V_15 ) ;
if ( ! F_16 ( V_15 , V_63 , L_4 ) ) {
F_5 ( V_64 L_5 ) ;
return - V_65 ;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_66 = L_4 ;
F_3 ( 0 , V_2 -> V_15 + V_16 ) ;
F_6 ( 100 ) ;
if ( F_4 ( V_2 -> V_15 + V_16 ) & V_67 ) {
F_5 ( V_64 L_6 ) ;
return - V_65 ;
}
V_9 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_9 = F_4 ( V_2 -> V_15 + V_21 ) ;
V_51 = V_59 -> V_61 [ 1 ] ;
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
V_2 -> V_51 = 0 ;
if ( V_51 > 0 ) {
if ( F_17 ( V_51 , F_12 , 0 , L_4 , V_2 ) ) {
F_5 ( V_68 L_7 , V_51 ) ;
} else {
F_5 ( V_18 L_8 , V_51 ) ;
V_2 -> V_51 = V_51 ;
}
} else if ( V_51 == 0 ) {
F_5 ( V_68 L_9 ) ;
} else {
#if 0
printk(KERN_DEBUG "(probe returned multiple irqs--bad)\n");
#else
F_5 ( V_68 L_10 ) ;
#endif
}
V_60 = F_18 ( V_2 , 1 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_19 ( V_2 , sizeof( struct V_69 ) ) ;
if ( V_60 < 0 )
return V_60 ;
V_4 = & V_2 -> V_55 [ 0 ] ;
V_2 -> V_70 = V_4 ;
V_4 -> type = V_71 ;
V_4 -> V_72 = V_73 | V_74 | V_75 ;
V_4 -> V_76 = 16 ;
V_4 -> V_77 = 1 ;
V_4 -> V_78 = F_1 ;
V_4 -> V_79 = F_11 ;
V_4 -> V_80 = F_8 ;
V_4 -> V_81 = 0xfff ;
V_4 -> V_82 = & V_83 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 )
F_21 ( V_2 -> V_51 , V_2 ) ;
if ( V_2 -> V_15 )
F_22 ( V_2 -> V_15 , V_63 ) ;
}
