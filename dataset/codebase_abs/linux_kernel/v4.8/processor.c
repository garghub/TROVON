static void
F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
V_3 = & F_2 ( V_4 , V_1 ) ;
V_3 -> V_5 = 1 ;
V_3 -> V_6 = 1 ;
}
static int F_3 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
unsigned long V_10 ;
struct V_2 * V_3 ;
#ifdef F_4
if ( F_5 () >= V_11 ) {
F_6 ( V_12 L_1 ) ;
return 1 ;
}
#else
if ( V_13 . V_14 > 0 ) {
F_6 ( V_12 L_2 ) ;
return 1 ;
}
#endif
V_10 = V_13 . V_14 ;
V_9 = V_8 -> V_15 . V_16 ;
#ifdef F_7
if ( F_8 () ) {
T_1 V_17 ;
unsigned long V_18 ;
T_2 * V_19 ;
#undef V_20
#ifdef V_20
struct V_21 V_22 ;
#endif
V_19 = F_9 ( sizeof ( * V_19 ) , V_23 ) ;
if ( ! V_19 )
F_10 ( L_3 ) ;
V_17 = F_11 ( & V_18 , V_8 -> V_24 ,
V_8 -> V_25 , V_26 , V_19 ) ;
F_12 ( V_27 != V_17 ) ;
F_12 ( V_8 -> V_28 != V_19 -> V_28 ) ;
F_12 ( V_8 -> V_29 != V_19 -> V_30 ) ;
V_9 = V_19 -> V_31 [ 0 ] ;
F_13 ( V_19 ) ;
#ifdef V_20
V_17 = F_14 ( & V_22 , V_8 -> V_15 . V_16 ) ;
F_12 ( V_27 != V_17 ) ;
if ( V_22 . V_32 >= V_33 ) {
F_6 ( V_34 L_4
L_5
L_6 ,
V_8 -> V_15 . V_16 , V_22 . V_32 , V_33 ) ;
V_13 . V_14 -- ;
return 1 ;
} else {
V_10 = V_22 . V_32 ;
}
#endif
}
#endif
V_3 = & F_2 ( V_4 , V_10 ) ;
V_13 . V_14 ++ ;
if ( V_10 )
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
V_3 -> V_35 = V_35 ;
V_3 -> V_8 = V_8 ;
V_3 -> V_15 = V_8 -> V_15 . V_16 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_9 = V_9 ;
#ifdef F_4
F_1 ( V_10 ) ;
#endif
#if 0
if (cpuid) {
struct irqaction actions[];
actions = kmalloc(sizeof(struct irqaction)*MAX_CPU_IRQ, GFP_ATOMIC);
if (!actions) {
actions = cpu_irq_actions[0];
}
cpu_irq_actions[cpuid] = actions;
}
#endif
#ifdef F_4
if ( V_10 ) {
F_15 ( V_10 , true ) ;
F_16 ( V_10 ) ;
}
#endif
return 0 ;
}
void T_3 F_17 ( void )
{
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_36 = 100 * V_37 -> V_38 ;
#define V_3 ((unsigned long *)&boot_cpu_data.pdc.model)
if ( F_18 ( & V_13 . V_39 . V_40 ) == V_27 )
F_6 ( V_12
L_7 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] , V_3 [ 4 ] , V_3 [ 5 ] , V_3 [ 6 ] , V_3 [ 7 ] , V_3 [ 8 ] ) ;
#undef V_3
if ( F_19 ( & V_13 . V_39 . V_41 , 0 ) == V_27 )
F_6 ( V_12 L_8 ,
V_13 . V_39 . V_41 ) ;
if ( F_20 ( & V_13 . V_39 . V_10 ) == V_27 )
F_6 ( V_12 L_9 ,
( V_13 . V_39 . V_10 >> 5 ) & 127 ,
V_13 . V_39 . V_10 & 31 ,
V_13 . V_39 . V_10 ) ;
if ( F_21 ( & V_13 . V_39 . V_42 ) == V_27 )
F_6 ( V_12 L_10 ,
V_13 . V_39 . V_42 ) ;
if ( F_22 ( V_13 . V_39 . V_43 ) == V_27 )
F_6 ( V_12 L_11 ,
V_13 . V_39 . V_43 ) ;
V_13 . V_44 = V_13 . V_39 . V_40 . V_44 ;
V_13 . V_45 = V_13 . V_39 . V_40 . V_45 ;
V_13 . V_46 = F_23 ( V_13 . V_44 ) ;
V_13 . V_47 = V_48 [ V_13 . V_46 ] [ 0 ] ;
V_13 . V_49 = V_48 [ V_13 . V_46 ] [ 1 ] ;
#ifdef F_24
V_50 = ( V_13 . V_46 == V_51 ) ||
( V_13 . V_46 == V_52 ) ;
#endif
}
int F_25 ( int V_1 )
{
int V_53 ;
struct V_54 V_55 ;
F_26 () ;
V_53 = V_54 ( & V_55 ) ;
if( V_53 >= 0 && V_55 . V_56 ) {
F_27 ( V_55 . V_56 , 10 ) ;
F_2 ( V_4 , V_1 ) . V_57 = V_55 . V_58 ;
F_2 ( V_4 , V_1 ) . V_59 = V_55 . V_40 ;
if ( V_1 == 0 )
F_6 ( V_12 L_12 ,
V_1 , V_55 . V_58 , V_55 . V_40 ) ;
asm volatile ("fstd %fr0,8(%sp)");
} else {
F_6 ( V_34 L_13
L_14
#ifdef F_7
L_15
#endif
, V_55 . V_56 ) ;
#ifdef F_7
F_28 ( 100 ) ;
F_10 ( L_16 ) ;
#endif
}
F_1 ( V_1 ) ;
return V_53 ;
}
int
F_29 ( struct V_60 * V_61 , void * V_62 )
{
unsigned long V_63 ;
F_30 (cpu) {
const struct V_2 * V_64 = & F_2 ( V_4 , V_63 ) ;
#ifdef F_4
if ( 0 == V_64 -> V_15 )
continue;
#endif
F_31 ( V_61 , L_17
L_18 ,
V_63 , V_13 . V_49 ) ;
F_31 ( V_61 , L_19 , V_13 . V_47 ) ;
F_31 ( V_61 , L_20 ,
V_13 . V_36 / 1000000 ,
V_13 . V_36 % 1000000 ) ;
F_31 ( V_61 , L_21 ) ;
if ( V_13 . V_39 . V_42 & V_65 )
F_32 ( V_61 , L_22 ) ;
if ( V_13 . V_39 . V_42 & V_66 )
F_32 ( V_61 , L_23 ) ;
if ( V_13 . V_39 . V_42 & V_67 )
F_32 ( V_61 , L_24 ) ;
switch ( V_13 . V_39 . V_42 & V_68 ) {
case V_69 :
F_32 ( V_61 , L_25 ) ;
break;
case V_70 :
F_32 ( V_61 , L_26 ) ;
break;
case V_71 :
F_32 ( V_61 , L_27 ) ;
break;
}
F_31 ( V_61 , L_28 , V_13 . V_39 . V_42 ) ;
F_31 ( V_61 , L_29
L_30 ,
V_13 . V_39 . V_43 ,
V_64 -> V_8 ?
V_64 -> V_8 -> V_72 : L_31 ) ;
F_31 ( V_61 , L_32
L_33 ,
V_13 . V_44 ,
V_13 . V_45 ) ;
F_33 ( V_61 ) ;
F_31 ( V_61 , L_34 ,
V_64 -> V_35 / ( 500000 / V_73 ) ,
( V_64 -> V_35 / ( 5000 / V_73 ) ) % 100 ) ;
F_31 ( V_61 , L_35 ,
V_13 . V_39 . V_40 . V_74 ) ;
}
return 0 ;
}
void T_3 F_34 ( void )
{
F_35 ( & V_75 ) ;
}
