static inline T_1 int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( F_2 () && ! F_3 ( V_2 ) ) {
F_4 () ;
if ( F_5 () && F_6 ( V_2 , 0 ) )
V_3 = 1 ;
F_7 () ;
}
return V_3 ;
}
static void T_1 F_8 ( unsigned long V_4 ,
struct V_5 * V_6 ,
struct V_1 * V_2 )
{
if ( ( unsigned long ) V_4 < V_7 ) {
F_9 ( V_8 L_1
L_2 ) ;
} else {
F_9 ( V_8 L_3
L_4 , ( unsigned long ) V_4 ) ;
}
F_9 ( V_8 L_5 ,
( V_6 -> V_9 ?
F_10 ( V_6 -> V_9 -> V_10 ) :
F_10 ( V_6 -> V_11 -> V_10 ) ) ) ;
F_9 ( V_8 L_6 ,
( V_6 -> V_9 ? ( unsigned long ) V_6 -> V_9 -> V_12 :
( unsigned long ) V_6 -> V_11 -> V_12 ) ) ;
F_11 ( L_7 , V_2 ) ;
}
static void T_1 F_12 ( struct V_1 * V_2 , unsigned long V_13 )
{
F_9 ( V_14 L_8 ,
V_2 -> V_15 ) ;
F_9 ( V_14 L_9 , V_2 -> V_16 [ 15 ] ) ;
F_9 ( L_10 , ( void * ) V_2 -> V_16 [ 15 ] ) ;
F_9 ( V_14 L_11 , V_13 ) ;
F_13 () ;
F_8 ( V_2 -> V_15 , V_17 , V_2 ) ;
}
static unsigned int F_14 ( unsigned long V_15 )
{
T_2 * V_18 = F_15 ( V_17 -> V_9 , V_15 ) ;
T_3 * V_19 ;
T_4 * V_20 ;
T_5 * V_21 , V_22 ;
unsigned long V_23 ;
T_6 V_24 = 0 ;
unsigned long V_25 ;
if ( F_16 ( * V_18 ) )
goto V_26;
V_19 = F_17 ( V_18 , V_15 ) ;
if ( F_18 ( * V_19 ) )
goto V_26;
V_20 = F_19 ( V_19 , V_15 ) ;
if ( F_20 ( * V_20 ) )
goto V_26;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
__asm__ __volatile__("wrpr %0, %1, %%pstate"
: : "r" (pstate), "i" (PSTATE_IE));
V_21 = F_21 ( V_20 , V_15 ) ;
V_22 = * V_21 ;
if ( ! F_22 ( V_22 ) )
goto V_27;
V_23 = ( F_23 ( V_22 ) << V_28 ) ;
V_23 += ( V_15 & ~ V_29 ) ;
__asm__ __volatile__("lduwa [%1] %2, %0"
: "=r" (insn)
: "r" (pa), "i" (ASI_PHYS_USE_EC));
V_27:
F_24 ( V_21 ) ;
__asm__ __volatile__("wrpr %0, 0x0, %%pstate" : : "r" (pstate));
V_26:
return V_24 ;
}
static inline void
F_25 ( struct V_1 * V_2 , int V_30 , int V_31 ,
unsigned long V_4 , struct V_5 * V_6 )
{
if ( ! F_26 ( V_6 , V_30 ) )
return;
if ( ! F_27 () )
return;
F_9 ( L_12 ,
F_28 ( V_6 ) > 1 ? V_32 : V_33 ,
V_6 -> V_34 , F_28 ( V_6 ) , V_4 ,
( void * ) V_2 -> V_15 , ( void * ) V_2 -> V_16 [ V_35 ] ,
( void * ) V_2 -> V_16 [ V_36 ] , V_31 ) ;
F_29 ( V_37 L_13 , V_2 -> V_15 ) ;
F_9 ( V_37 L_14 ) ;
}
static void F_30 ( int V_31 , int V_30 , struct V_1 * V_2 ,
unsigned int V_24 , int V_38 )
{
unsigned long V_39 ;
T_7 V_40 ;
V_40 . V_41 = V_31 ;
V_40 . V_42 = V_30 ;
V_40 . V_43 = 0 ;
if ( V_38 & V_44 )
V_39 = V_2 -> V_15 ;
else
V_39 = F_31 ( V_2 , V_24 , 0 ) ;
V_40 . V_45 = ( void V_46 * ) V_39 ;
V_40 . V_47 = 0 ;
if ( F_32 ( V_48 ) )
F_25 ( V_2 , V_30 , V_31 , V_39 , V_17 ) ;
F_33 ( V_30 , & V_40 , V_17 ) ;
}
static unsigned int F_34 ( struct V_1 * V_2 , unsigned int V_24 )
{
if ( ! V_24 ) {
if ( ! V_2 -> V_15 || ( V_2 -> V_15 & 0x3 ) )
return 0 ;
if ( V_2 -> V_49 & V_50 ) {
V_24 = * ( unsigned int * ) V_2 -> V_15 ;
} else {
V_24 = F_14 ( V_2 -> V_15 ) ;
}
}
return V_24 ;
}
static void T_1 F_35 ( struct V_1 * V_2 , int V_41 ,
int V_38 , unsigned int V_24 ,
unsigned long V_4 )
{
unsigned char V_51 = V_52 ;
if ( ( ! V_24 ) && ( V_2 -> V_49 & V_50 ) )
goto V_53;
if ( ! ( V_38 & ( V_54 | V_44 ) ) &&
( V_24 & 0xc0800000 ) == 0xc0800000 ) {
if ( V_24 & 0x2000 )
V_51 = ( V_2 -> V_49 >> 24 ) ;
else
V_51 = ( V_24 >> 5 ) ;
if ( ( V_51 & 0xf2 ) == 0x82 ) {
if ( V_24 & 0x1000000 ) {
F_36 ( V_24 , V_2 ) ;
} else {
F_37 ( V_24 , V_2 ) ;
}
return;
}
}
if ( V_2 -> V_49 & V_50 ) {
const struct V_55 * V_56 ;
V_56 = F_38 ( V_2 -> V_15 ) ;
if ( V_56 ) {
V_2 -> V_15 = V_56 -> V_57 ;
V_2 -> V_58 = V_2 -> V_15 + 4 ;
return;
}
} else {
F_30 ( V_41 , V_59 , V_2 , V_24 , V_38 ) ;
return;
}
V_53:
F_8 ( V_4 , V_17 , V_2 ) ;
}
static void T_8 T_1 F_39 ( struct V_1 * V_2 )
{
static int V_60 ;
if ( V_60 ++ < 10 )
F_9 ( V_61 L_15
L_16 ,
V_17 -> V_34 , V_17 -> V_62 ,
V_2 -> V_15 ) ;
F_40 ( V_2 ) ;
}
static void T_8 T_1 F_41 ( struct V_1 * V_2 ,
unsigned long V_39 )
{
static int V_60 ;
if ( V_60 ++ < 10 )
F_9 ( V_61 L_17
L_18 ,
V_17 -> V_34 , V_17 -> V_62 , V_39 ) ;
F_40 ( V_2 ) ;
}
T_9 void T_1 F_42 ( struct V_1 * V_2 )
{
struct V_63 * V_9 = V_17 -> V_9 ;
struct V_64 * V_65 ;
unsigned int V_24 = 0 ;
int V_41 , V_38 , V_66 ;
unsigned long V_4 , V_67 ;
unsigned int V_68 = V_69 | V_70 ;
V_38 = F_43 () ;
if ( F_1 ( V_2 ) )
return;
V_41 = V_71 ;
V_4 = F_44 () -> V_72 ;
if ( ( V_38 & V_44 ) &&
( V_38 & V_73 ) )
F_45 () ;
if ( F_46 ( V_74 ) ) {
if ( ! ( V_2 -> V_49 & V_50 ) ) {
if ( F_32 ( ( V_2 -> V_15 >> 32 ) != 0 ) ) {
F_39 ( V_2 ) ;
goto V_75;
}
}
if ( F_32 ( ( V_4 >> 32 ) != 0 ) ) {
F_41 ( V_2 , V_4 ) ;
goto V_75;
}
}
if ( V_2 -> V_49 & V_50 ) {
unsigned long V_15 = V_2 -> V_15 ;
if ( ( V_15 >= V_76 && V_15 < ( unsigned long ) V_77 ) ||
( V_15 >= V_78 && V_15 < V_79 ) ) {
} else {
F_12 ( V_2 , V_4 ) ;
return;
}
}
if ( F_47 () || ! V_9 )
goto V_75;
F_48 ( V_80 , 1 , V_2 , V_4 ) ;
if ( ! F_49 ( & V_9 -> V_81 ) ) {
if ( ( V_2 -> V_49 & V_50 ) &&
! F_38 ( V_2 -> V_15 ) ) {
V_24 = F_34 ( V_2 , V_24 ) ;
goto V_82;
}
V_83:
F_50 ( & V_9 -> V_81 ) ;
}
V_65 = F_51 ( V_9 , V_4 ) ;
if ( ! V_65 )
goto V_84;
if ( ( ( V_38 &
( V_73 | V_54 | V_85 ) ) == V_73 ) &&
( V_65 -> V_86 & V_87 ) != 0 ) {
V_24 = F_34 ( V_2 , 0 ) ;
if ( ! V_24 )
goto V_88;
if ( ( V_24 & 0xc0200000 ) == 0xc0200000 &&
( V_24 & 0x01780000 ) != 0x01680000 ) {
V_38 |= V_54 ;
}
}
V_88:
if ( V_65 -> V_89 <= V_4 )
goto V_90;
if ( ! ( V_65 -> V_86 & V_91 ) )
goto V_84;
if ( ! ( V_38 & V_54 ) ) {
V_24 = F_34 ( V_2 , V_24 ) ;
if ( ( V_24 & 0xc0800000 ) == 0xc0800000 ) {
unsigned char V_51 ;
if ( V_24 & 0x2000 )
V_51 = ( V_2 -> V_49 >> 24 ) ;
else
V_51 = ( V_24 >> 5 ) ;
if ( ( V_51 & 0xf2 ) == 0x82 )
goto V_84;
}
}
if ( F_52 ( V_65 , V_4 ) )
goto V_84;
V_90:
V_41 = V_92 ;
if ( ( V_38 & V_44 ) && ! ( V_65 -> V_86 & V_93 ) ) {
F_53 ( V_4 != V_2 -> V_15 ) ;
F_53 ( V_2 -> V_49 & V_50 ) ;
goto V_84;
}
if ( V_38 & V_54 ) {
if ( ! ( V_65 -> V_86 & V_87 ) )
goto V_84;
if ( V_94 == V_95 &&
( V_65 -> V_86 & V_93 ) != 0 &&
V_65 -> V_96 != NULL )
F_54 ( V_38 |
V_97 ) ;
} else {
if ( ! ( V_65 -> V_86 & ( V_98 | V_93 ) ) )
goto V_84;
}
V_68 |= ( ( V_38 & V_54 ) ? V_99 : 0 ) ;
V_66 = F_55 ( V_9 , V_65 , V_4 , V_68 ) ;
if ( ( V_66 & V_100 ) && F_56 ( V_17 ) )
return;
if ( F_32 ( V_66 & V_101 ) ) {
if ( V_66 & V_102 )
goto V_103;
else if ( V_66 & V_104 )
goto V_105;
F_45 () ;
}
if ( V_68 & V_69 ) {
if ( V_66 & V_106 ) {
V_17 -> V_107 ++ ;
F_48 ( V_108 ,
1 , V_2 , V_4 ) ;
} else {
V_17 -> V_109 ++ ;
F_48 ( V_110 ,
1 , V_2 , V_4 ) ;
}
if ( V_66 & V_100 ) {
V_68 &= ~ V_69 ;
goto V_83;
}
}
F_57 ( & V_9 -> V_81 ) ;
V_67 = F_58 ( V_9 ) ;
#ifdef F_59
V_67 -= ( V_9 -> V_10 . V_111 * ( V_112 / V_7 ) ) ;
#endif
if ( F_32 ( V_67 >
V_9 -> V_10 . V_113 [ V_114 ] . V_115 ) )
F_60 ( V_9 , V_114 , V_67 ) ;
#ifdef F_59
V_67 = V_9 -> V_10 . V_111 ;
if ( F_32 ( V_67 >
V_9 -> V_10 . V_113 [ V_116 ] . V_115 ) )
F_60 ( V_9 , V_116 , V_67 ) ;
#endif
return;
V_84:
V_24 = F_34 ( V_2 , V_24 ) ;
F_57 ( & V_9 -> V_81 ) ;
V_82:
F_35 ( V_2 , V_41 , V_38 , V_24 , V_4 ) ;
return;
V_103:
V_24 = F_34 ( V_2 , V_24 ) ;
F_57 ( & V_9 -> V_81 ) ;
if ( ! ( V_2 -> V_49 & V_50 ) ) {
F_61 () ;
return;
}
goto V_82;
V_75:
V_24 = F_34 ( V_2 , 0 ) ;
goto V_82;
V_105:
V_24 = F_34 ( V_2 , V_24 ) ;
F_57 ( & V_9 -> V_81 ) ;
F_30 ( V_117 , V_118 , V_2 , V_24 , V_38 ) ;
if ( V_2 -> V_49 & V_50 )
goto V_82;
}
