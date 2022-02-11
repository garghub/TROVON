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
if ( F_16 ( * V_18 ) || F_17 ( F_18 ( * V_18 ) ) )
goto V_25;
V_19 = F_19 ( V_18 , V_15 ) ;
if ( F_20 ( * V_19 ) || F_17 ( F_21 ( * V_19 ) ) )
goto V_25;
F_22 () ;
V_20 = F_23 ( V_19 , V_15 ) ;
if ( F_24 ( * V_20 ) || F_17 ( F_25 ( * V_20 ) ) )
goto V_26;
#ifdef F_26
if ( F_27 ( * V_20 ) ) {
if ( F_28 ( * V_20 ) )
goto V_26;
V_23 = F_29 ( * V_20 ) << V_27 ;
V_23 += V_15 & ~ V_28 ;
__asm__ __volatile__("lduwa [%1] %2, %0"
: "=r" (insn)
: "r" (pa), "i" (ASI_PHYS_USE_EC));
} else
#endif
{
V_21 = F_30 ( V_20 , V_15 ) ;
V_22 = * V_21 ;
if ( F_31 ( V_22 ) ) {
V_23 = ( F_32 ( V_22 ) << V_27 ) ;
V_23 += ( V_15 & ~ V_29 ) ;
__asm__ __volatile__("lduwa [%1] %2, %0"
: "=r" (insn)
: "r" (pa), "i" (ASI_PHYS_USE_EC));
}
F_33 ( V_21 ) ;
}
V_26:
F_34 () ;
V_25:
return V_24 ;
}
static inline void
F_35 ( struct V_1 * V_2 , int V_30 , int V_31 ,
unsigned long V_4 , struct V_5 * V_6 )
{
if ( ! F_36 ( V_6 , V_30 ) )
return;
if ( ! F_37 () )
return;
F_9 ( L_12 ,
F_38 ( V_6 ) > 1 ? V_32 : V_33 ,
V_6 -> V_34 , F_38 ( V_6 ) , V_4 ,
( void * ) V_2 -> V_15 , ( void * ) V_2 -> V_16 [ V_35 ] ,
( void * ) V_2 -> V_16 [ V_36 ] , V_31 ) ;
F_39 ( V_37 L_13 , V_2 -> V_15 ) ;
F_9 ( V_37 L_14 ) ;
}
static void F_40 ( int V_31 , int V_30 , struct V_1 * V_2 ,
unsigned long V_38 , unsigned int V_24 ,
int V_39 )
{
unsigned long V_40 ;
T_7 V_41 ;
V_41 . V_42 = V_31 ;
V_41 . V_43 = V_30 ;
V_41 . V_44 = 0 ;
if ( V_39 & V_45 ) {
V_40 = V_2 -> V_15 ;
} else {
if ( V_24 )
V_40 = F_41 ( V_2 , V_24 , 0 ) ;
else
V_40 = V_38 ;
}
V_41 . V_46 = ( void V_47 * ) V_40 ;
V_41 . V_48 = 0 ;
if ( F_17 ( V_49 ) )
F_35 ( V_2 , V_30 , V_31 , V_40 , V_17 ) ;
F_42 ( V_30 , & V_41 , V_17 ) ;
}
static unsigned int F_43 ( struct V_1 * V_2 , unsigned int V_24 )
{
if ( ! V_24 ) {
if ( ! V_2 -> V_15 || ( V_2 -> V_15 & 0x3 ) )
return 0 ;
if ( V_2 -> V_50 & V_51 ) {
V_24 = * ( unsigned int * ) V_2 -> V_15 ;
} else {
V_24 = F_14 ( V_2 -> V_15 ) ;
}
}
return V_24 ;
}
static void T_1 F_44 ( struct V_1 * V_2 , int V_42 ,
int V_39 , unsigned int V_24 ,
unsigned long V_4 )
{
unsigned char V_52 = V_53 ;
if ( ( ! V_24 ) && ( V_2 -> V_50 & V_51 ) )
goto V_54;
if ( ! ( V_39 & ( V_55 | V_45 ) ) &&
( V_24 & 0xc0800000 ) == 0xc0800000 ) {
if ( V_24 & 0x2000 )
V_52 = ( V_2 -> V_50 >> 24 ) ;
else
V_52 = ( V_24 >> 5 ) ;
if ( ( V_52 & 0xf2 ) == 0x82 ) {
if ( V_24 & 0x1000000 ) {
F_45 ( V_24 , V_2 ) ;
} else {
F_46 ( V_24 , V_2 ) ;
}
return;
}
}
if ( V_2 -> V_50 & V_51 ) {
const struct V_56 * V_57 ;
V_57 = F_47 ( V_2 -> V_15 ) ;
if ( V_57 ) {
V_2 -> V_15 = V_57 -> V_58 ;
V_2 -> V_59 = V_2 -> V_15 + 4 ;
return;
}
} else {
F_40 ( V_42 , V_60 , V_2 , V_4 , V_24 , V_39 ) ;
return;
}
V_54:
F_8 ( V_4 , V_17 , V_2 ) ;
}
static void T_8 T_1 F_48 ( struct V_1 * V_2 )
{
static int V_61 ;
if ( V_61 ++ < 10 )
F_9 ( V_62 L_15
L_16 ,
V_17 -> V_34 , V_17 -> V_63 ,
V_2 -> V_15 ) ;
F_49 ( V_2 ) ;
}
T_9 void T_1 F_50 ( struct V_1 * V_2 )
{
enum V_64 V_65 = F_51 () ;
struct V_66 * V_9 = V_17 -> V_9 ;
struct V_67 * V_68 ;
unsigned int V_24 = 0 ;
int V_42 , V_39 , V_69 ;
unsigned long V_4 , V_70 ;
unsigned int V_71 = V_72 | V_73 ;
V_39 = F_52 () ;
if ( F_1 ( V_2 ) )
goto V_74;
V_42 = V_75 ;
V_4 = F_53 () -> V_76 ;
if ( ( V_39 & V_45 ) &&
( V_39 & V_77 ) )
F_54 () ;
if ( F_55 ( V_78 ) ) {
if ( ! ( V_2 -> V_50 & V_51 ) ) {
if ( F_17 ( ( V_2 -> V_15 >> 32 ) != 0 ) ) {
F_48 ( V_2 ) ;
goto V_79;
}
}
if ( F_17 ( ( V_4 >> 32 ) != 0 ) )
goto V_79;
}
if ( V_2 -> V_50 & V_51 ) {
unsigned long V_15 = V_2 -> V_15 ;
if ( ( V_15 >= V_80 && V_15 < ( unsigned long ) V_81 ) ||
( V_15 >= V_82 && V_15 < V_83 ) ) {
} else {
F_12 ( V_2 , V_4 ) ;
goto V_74;
}
} else
V_71 |= V_84 ;
if ( F_56 () || ! V_9 )
goto V_79;
F_57 ( V_85 , 1 , V_2 , V_4 ) ;
if ( ! F_58 ( & V_9 -> V_86 ) ) {
if ( ( V_2 -> V_50 & V_51 ) &&
! F_47 ( V_2 -> V_15 ) ) {
V_24 = F_43 ( V_2 , V_24 ) ;
goto V_87;
}
V_88:
F_59 ( & V_9 -> V_86 ) ;
}
if ( V_39 & V_89 )
goto V_90;
V_68 = F_60 ( V_9 , V_4 ) ;
if ( ! V_68 )
goto V_91;
if ( ( ( V_39 &
( V_77 | V_55 | V_92 ) ) == V_77 ) &&
( V_68 -> V_93 & V_94 ) != 0 ) {
V_24 = F_43 ( V_2 , 0 ) ;
if ( ! V_24 )
goto V_95;
if ( ( V_24 & 0xc0200000 ) == 0xc0200000 &&
( V_24 & 0x01780000 ) != 0x01680000 ) {
V_39 |= V_55 ;
}
}
V_95:
if ( V_68 -> V_96 <= V_4 )
goto V_97;
if ( ! ( V_68 -> V_93 & V_98 ) )
goto V_91;
if ( ! ( V_39 & V_55 ) ) {
V_24 = F_43 ( V_2 , V_24 ) ;
if ( ( V_24 & 0xc0800000 ) == 0xc0800000 ) {
unsigned char V_52 ;
if ( V_24 & 0x2000 )
V_52 = ( V_2 -> V_50 >> 24 ) ;
else
V_52 = ( V_24 >> 5 ) ;
if ( ( V_52 & 0xf2 ) == 0x82 )
goto V_91;
}
}
if ( F_61 ( V_68 , V_4 ) )
goto V_91;
V_97:
V_42 = V_99 ;
if ( ( V_39 & V_45 ) && ! ( V_68 -> V_93 & V_100 ) ) {
F_62 ( V_4 != V_2 -> V_15 ) ;
F_62 ( V_2 -> V_50 & V_51 ) ;
goto V_91;
}
if ( V_39 & V_55 ) {
if ( ! ( V_68 -> V_93 & V_94 ) )
goto V_91;
if ( V_101 == V_102 &&
( V_68 -> V_93 & V_100 ) != 0 &&
V_68 -> V_103 != NULL )
F_63 ( V_39 |
V_104 ) ;
V_71 |= V_105 ;
} else {
if ( ! ( V_68 -> V_93 & ( V_106 | V_100 ) ) )
goto V_91;
}
V_69 = F_64 ( V_9 , V_68 , V_4 , V_71 ) ;
if ( ( V_69 & V_107 ) && F_65 ( V_17 ) )
goto V_74;
if ( F_17 ( V_69 & V_108 ) ) {
if ( V_69 & V_109 )
goto V_110;
else if ( V_69 & V_111 )
goto V_90;
F_54 () ;
}
if ( V_71 & V_72 ) {
if ( V_69 & V_112 ) {
V_17 -> V_113 ++ ;
F_57 ( V_114 ,
1 , V_2 , V_4 ) ;
} else {
V_17 -> V_115 ++ ;
F_57 ( V_116 ,
1 , V_2 , V_4 ) ;
}
if ( V_69 & V_107 ) {
V_71 &= ~ V_72 ;
V_71 |= V_117 ;
goto V_88;
}
}
F_66 ( & V_9 -> V_86 ) ;
V_70 = F_67 ( V_9 ) ;
#if F_68 ( V_118 ) || F_68 ( F_26 )
V_70 -= ( V_9 -> V_10 . V_119 * ( V_120 / V_7 ) ) ;
#endif
if ( F_17 ( V_70 >
V_9 -> V_10 . V_121 [ V_122 ] . V_123 ) )
F_69 ( V_9 , V_122 , V_70 ) ;
#if F_68 ( V_118 ) || F_68 ( F_26 )
V_70 = V_9 -> V_10 . V_119 ;
if ( F_17 ( V_70 >
V_9 -> V_10 . V_121 [ V_124 ] . V_123 ) ) {
if ( V_9 -> V_10 . V_121 [ V_124 ] . V_125 )
F_69 ( V_9 , V_124 , V_70 ) ;
else
F_70 ( V_2 ) ;
}
#endif
V_74:
F_71 ( V_65 ) ;
return;
V_91:
V_24 = F_43 ( V_2 , V_24 ) ;
F_66 ( & V_9 -> V_86 ) ;
V_87:
F_44 ( V_2 , V_42 , V_39 , V_24 , V_4 ) ;
goto V_74;
V_110:
V_24 = F_43 ( V_2 , V_24 ) ;
F_66 ( & V_9 -> V_86 ) ;
if ( ! ( V_2 -> V_50 & V_51 ) ) {
F_72 () ;
goto V_74;
}
goto V_87;
V_79:
V_24 = F_43 ( V_2 , 0 ) ;
goto V_87;
V_90:
V_24 = F_43 ( V_2 , V_24 ) ;
F_66 ( & V_9 -> V_86 ) ;
F_40 ( V_126 , V_127 , V_2 , V_4 , V_24 , V_39 ) ;
if ( V_2 -> V_50 & V_51 )
goto V_87;
}
