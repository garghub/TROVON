static void
F_1 ( unsigned long V_1 )
{
}
static int T_1 F_2 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
unsigned long V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 = { } ;
#ifdef F_3
if ( F_4 () >= V_10 ) {
F_5 ( V_11 L_1 ) ;
return 1 ;
}
#else
if ( V_12 . V_13 > 0 ) {
F_5 ( V_11 L_2 ) ;
return 1 ;
}
#endif
V_5 = V_12 . V_13 ;
V_4 = V_3 -> V_14 . V_15 ;
V_9 . V_16 = V_9 . V_17 = V_5 ;
#ifdef F_6
if ( F_7 () ) {
T_2 V_18 ;
unsigned long V_19 ;
T_3 * V_20 ;
V_20 = F_8 ( sizeof ( * V_20 ) , V_21 ) ;
if ( ! V_20 )
F_9 ( L_3 ) ;
V_18 = F_10 ( & V_19 , V_3 -> V_22 ,
V_3 -> V_23 , V_24 , V_20 ) ;
F_11 ( V_25 != V_18 ) ;
F_11 ( V_3 -> V_26 != V_20 -> V_26 ) ;
F_11 ( V_3 -> V_27 != V_20 -> V_28 ) ;
V_4 = V_20 -> V_29 [ 0 ] ;
F_12 ( V_20 ) ;
V_18 = F_13 ( & V_9 , V_3 -> V_14 . V_15 ) ;
F_11 ( V_25 != V_18 ) ;
F_14 ( L_4
L_5 ,
V_5 , V_9 . V_16 , V_9 . V_17 ,
& V_3 -> V_14 . V_15 ) ;
#undef V_30
#ifdef V_30
if ( V_9 . V_16 >= V_31 ) {
F_5 ( V_32 L_6
L_7
L_8 ,
& V_3 -> V_14 . V_15 , V_9 . V_16 , V_31 ) ;
V_12 . V_13 -- ;
return 1 ;
} else {
V_5 = V_9 . V_16 ;
}
#endif
}
#endif
V_7 = & F_15 ( V_33 , V_5 ) ;
V_12 . V_13 ++ ;
if ( V_5 )
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_34 = V_34 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_14 = V_3 -> V_14 . V_15 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_16 = V_9 . V_16 ;
V_7 -> V_17 = V_9 . V_17 ;
#ifdef F_3
F_1 ( V_5 ) ;
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
#ifdef F_3
if ( V_5 ) {
F_16 ( V_5 , true ) ;
F_17 ( V_5 ) ;
}
#endif
return 0 ;
}
void T_1 F_18 ( void )
{
unsigned long V_35 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_35 = F_19 () ;
F_20 ( & V_35 , sizeof( V_35 ) ) ;
V_12 . V_36 = 100 * V_37 -> V_38 ;
#define V_7 ((unsigned long *)&boot_cpu_data.pdc.model)
if ( F_21 ( & V_12 . V_39 . V_40 ) == V_25 ) {
F_5 ( V_11
L_9 ,
V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] , V_7 [ 4 ] , V_7 [ 5 ] , V_7 [ 6 ] , V_7 [ 7 ] , V_7 [ 8 ] ) ;
F_20 ( & V_12 . V_39 . V_40 ,
sizeof( V_12 . V_39 . V_40 ) ) ;
}
#undef V_7
if ( F_22 ( & V_12 . V_39 . V_41 , 0 ) == V_25 ) {
F_5 ( V_11 L_10 ,
V_12 . V_39 . V_41 ) ;
F_20 ( & V_12 . V_39 . V_41 ,
sizeof( V_12 . V_39 . V_41 ) ) ;
}
if ( F_23 ( & V_12 . V_39 . V_5 ) == V_25 ) {
F_5 ( V_11 L_11 ,
( V_12 . V_39 . V_5 >> 5 ) & 127 ,
V_12 . V_39 . V_5 & 31 ,
V_12 . V_39 . V_5 ) ;
F_20 ( & V_12 . V_39 . V_5 ,
sizeof( V_12 . V_39 . V_5 ) ) ;
}
if ( F_24 ( & V_12 . V_39 . V_42 ) == V_25 )
F_5 ( V_11 L_12 ,
V_12 . V_39 . V_42 ) ;
if ( F_25 ( V_12 . V_39 . V_43 ) == V_25 )
F_5 ( V_11 L_13 ,
V_12 . V_39 . V_43 ) ;
V_12 . V_44 = V_12 . V_39 . V_40 . V_44 ;
V_12 . V_45 = V_12 . V_39 . V_40 . V_45 ;
V_12 . V_46 = F_26 ( V_12 . V_44 ) ;
V_12 . V_47 = V_48 [ V_12 . V_46 ] [ 0 ] ;
V_12 . V_49 = V_48 [ V_12 . V_46 ] [ 1 ] ;
#ifdef F_27
V_50 = ( V_12 . V_46 == V_51 ) ||
( V_12 . V_46 == V_52 ) ;
#endif
}
int T_1 F_28 ( int V_1 )
{
int V_53 ;
struct V_54 V_55 ;
F_29 () ;
V_53 = V_54 ( & V_55 ) ;
if( V_53 >= 0 && V_55 . V_56 ) {
F_30 ( V_55 . V_56 , 10 ) ;
F_15 ( V_33 , V_1 ) . V_57 = V_55 . V_58 ;
F_15 ( V_33 , V_1 ) . V_59 = V_55 . V_40 ;
if ( V_1 == 0 )
F_5 ( V_11 L_14 ,
V_1 , V_55 . V_58 , V_55 . V_40 ) ;
asm volatile ("fstd %fr0,8(%sp)");
} else {
F_5 ( V_32 L_15
L_16
#ifdef F_6
L_17
#endif
, V_55 . V_56 ) ;
#ifdef F_6
F_31 ( 100 ) ;
F_9 ( L_18 ) ;
#endif
}
F_1 ( V_1 ) ;
return V_53 ;
}
int
F_32 ( struct V_60 * V_61 , void * V_62 )
{
unsigned long V_63 ;
F_33 (cpu) {
const struct V_6 * V_64 = & F_15 ( V_33 , V_63 ) ;
#ifdef F_3
if ( 0 == V_64 -> V_14 )
continue;
#endif
F_34 ( V_61 , L_19
L_20 ,
V_63 , V_12 . V_49 ) ;
F_34 ( V_61 , L_21 , V_12 . V_47 ) ;
F_34 ( V_61 , L_22 ,
V_12 . V_36 / 1000000 ,
V_12 . V_36 % 1000000 ) ;
F_34 ( V_61 , L_23 ) ;
if ( V_12 . V_39 . V_42 & V_65 )
F_35 ( V_61 , L_24 ) ;
if ( V_12 . V_39 . V_42 & V_66 )
F_35 ( V_61 , L_25 ) ;
if ( V_12 . V_39 . V_42 & V_67 )
F_35 ( V_61 , L_26 ) ;
switch ( V_12 . V_39 . V_42 & V_68 ) {
case V_69 :
F_35 ( V_61 , L_27 ) ;
break;
case V_70 :
F_35 ( V_61 , L_28 ) ;
break;
case V_71 :
F_35 ( V_61 , L_29 ) ;
break;
}
F_34 ( V_61 , L_30 , V_12 . V_39 . V_42 ) ;
F_34 ( V_61 , L_31
L_32 ,
V_12 . V_39 . V_43 ,
V_64 -> V_3 ?
V_64 -> V_3 -> V_72 : L_33 ) ;
F_34 ( V_61 , L_34
L_35 ,
V_12 . V_44 ,
V_12 . V_45 ) ;
F_36 ( V_61 ) ;
F_34 ( V_61 , L_36 ,
V_64 -> V_34 / ( 500000 / V_73 ) ,
( V_64 -> V_34 / ( 5000 / V_73 ) ) % 100 ) ;
F_34 ( V_61 , L_37 ,
V_12 . V_39 . V_40 . V_74 ) ;
}
return 0 ;
}
void T_1 F_37 ( void )
{
F_38 ( & V_75 ) ;
}
