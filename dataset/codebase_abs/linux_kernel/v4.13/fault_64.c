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
#if F_26 ( V_27 ) || F_26 ( V_28 )
if ( F_27 ( * V_20 ) ) {
V_23 = F_28 ( * V_20 ) << V_29 ;
V_23 += V_15 & ~ V_30 ;
__asm__ __volatile__("lduwa [%1] %2, %0"
: "=r" (insn)
: "r" (pa), "i" (ASI_PHYS_USE_EC));
} else
#endif
{
V_21 = F_29 ( V_20 , V_15 ) ;
V_22 = * V_21 ;
if ( F_30 ( V_22 ) ) {
V_23 = ( F_31 ( V_22 ) << V_29 ) ;
V_23 += ( V_15 & ~ V_31 ) ;
__asm__ __volatile__("lduwa [%1] %2, %0"
: "=r" (insn)
: "r" (pa), "i" (ASI_PHYS_USE_EC));
}
F_32 ( V_21 ) ;
}
V_26:
F_33 () ;
V_25:
return V_24 ;
}
static inline void
F_34 ( struct V_1 * V_2 , int V_32 , int V_33 ,
unsigned long V_4 , struct V_5 * V_6 )
{
if ( ! F_35 ( V_6 , V_32 ) )
return;
if ( ! F_36 () )
return;
F_9 ( L_12 ,
F_37 ( V_6 ) > 1 ? V_34 : V_35 ,
V_6 -> V_36 , F_37 ( V_6 ) , V_4 ,
( void * ) V_2 -> V_15 , ( void * ) V_2 -> V_16 [ V_37 ] ,
( void * ) V_2 -> V_16 [ V_38 ] , V_33 ) ;
F_38 ( V_39 L_13 , V_2 -> V_15 ) ;
F_9 ( V_39 L_14 ) ;
}
static void F_39 ( int V_33 , int V_32 , struct V_1 * V_2 ,
unsigned long V_40 , unsigned int V_24 ,
int V_41 )
{
unsigned long V_42 ;
T_7 V_43 ;
V_43 . V_44 = V_33 ;
V_43 . V_45 = V_32 ;
V_43 . V_46 = 0 ;
if ( V_41 & V_47 ) {
V_42 = V_2 -> V_15 ;
} else {
if ( V_24 )
V_42 = F_40 ( V_2 , V_24 , 0 ) ;
else
V_42 = V_40 ;
}
V_43 . V_48 = ( void V_49 * ) V_42 ;
V_43 . V_50 = 0 ;
if ( F_17 ( V_51 ) )
F_34 ( V_2 , V_32 , V_33 , V_42 , V_17 ) ;
F_41 ( V_32 , & V_43 , V_17 ) ;
}
static unsigned int F_42 ( struct V_1 * V_2 , unsigned int V_24 )
{
if ( ! V_24 ) {
if ( ! V_2 -> V_15 || ( V_2 -> V_15 & 0x3 ) )
return 0 ;
if ( V_2 -> V_52 & V_53 ) {
V_24 = * ( unsigned int * ) V_2 -> V_15 ;
} else {
V_24 = F_14 ( V_2 -> V_15 ) ;
}
}
return V_24 ;
}
static void T_1 F_43 ( struct V_1 * V_2 , int V_44 ,
int V_41 , unsigned int V_24 ,
unsigned long V_4 )
{
unsigned char V_54 = V_55 ;
if ( ( ! V_24 ) && ( V_2 -> V_52 & V_53 ) )
goto V_56;
if ( ! ( V_41 & ( V_57 | V_47 ) ) &&
( V_24 & 0xc0800000 ) == 0xc0800000 ) {
if ( V_24 & 0x2000 )
V_54 = ( V_2 -> V_52 >> 24 ) ;
else
V_54 = ( V_24 >> 5 ) ;
if ( ( V_54 & 0xf2 ) == 0x82 ) {
if ( V_24 & 0x1000000 ) {
F_44 ( V_24 , V_2 ) ;
} else {
F_45 ( V_24 , V_2 ) ;
}
return;
}
}
if ( V_2 -> V_52 & V_53 ) {
const struct V_58 * V_59 ;
V_59 = F_46 ( V_2 -> V_15 ) ;
if ( V_59 ) {
V_2 -> V_15 = V_59 -> V_60 ;
V_2 -> V_61 = V_2 -> V_15 + 4 ;
return;
}
} else {
F_39 ( V_44 , V_62 , V_2 , V_4 , V_24 , V_41 ) ;
return;
}
V_56:
F_8 ( V_4 , V_17 , V_2 ) ;
}
static void T_8 T_1 F_47 ( struct V_1 * V_2 )
{
static int V_63 ;
if ( V_63 ++ < 10 )
F_9 ( V_64 L_15
L_16 ,
V_17 -> V_36 , V_17 -> V_65 ,
V_2 -> V_15 ) ;
F_48 ( V_2 ) ;
}
T_9 void T_1 F_49 ( struct V_1 * V_2 )
{
enum V_66 V_67 = F_50 () ;
struct V_68 * V_9 = V_17 -> V_9 ;
struct V_69 * V_70 ;
unsigned int V_24 = 0 ;
int V_44 , V_41 , V_71 ;
unsigned long V_4 , V_72 ;
unsigned int V_73 = V_74 | V_75 ;
V_41 = F_51 () ;
if ( F_1 ( V_2 ) )
goto V_76;
V_44 = V_77 ;
V_4 = F_52 () -> V_78 ;
if ( ( V_41 & V_47 ) &&
( V_41 & V_79 ) )
F_53 () ;
if ( F_54 ( V_80 ) ) {
if ( ! ( V_2 -> V_52 & V_53 ) ) {
if ( F_17 ( ( V_2 -> V_15 >> 32 ) != 0 ) ) {
F_47 ( V_2 ) ;
goto V_81;
}
}
if ( F_17 ( ( V_4 >> 32 ) != 0 ) )
goto V_81;
}
if ( V_2 -> V_52 & V_53 ) {
unsigned long V_15 = V_2 -> V_15 ;
if ( ( V_15 >= V_82 && V_15 < ( unsigned long ) V_83 ) ||
( V_15 >= V_84 && V_15 < V_85 ) ) {
} else {
F_12 ( V_2 , V_4 ) ;
goto V_76;
}
} else
V_73 |= V_86 ;
if ( F_55 () || ! V_9 )
goto V_81;
F_56 ( V_87 , 1 , V_2 , V_4 ) ;
if ( ! F_57 ( & V_9 -> V_88 ) ) {
if ( ( V_2 -> V_52 & V_53 ) &&
! F_46 ( V_2 -> V_15 ) ) {
V_24 = F_42 ( V_2 , V_24 ) ;
goto V_89;
}
V_90:
F_58 ( & V_9 -> V_88 ) ;
}
if ( V_41 & V_91 )
goto V_92;
V_70 = F_59 ( V_9 , V_4 ) ;
if ( ! V_70 )
goto V_93;
if ( ( ( V_41 &
( V_79 | V_57 | V_94 ) ) == V_79 ) &&
( V_70 -> V_95 & V_96 ) != 0 ) {
V_24 = F_42 ( V_2 , 0 ) ;
if ( ! V_24 )
goto V_97;
if ( ( V_24 & 0xc0200000 ) == 0xc0200000 &&
( V_24 & 0x01780000 ) != 0x01680000 ) {
V_41 |= V_57 ;
}
}
V_97:
if ( V_70 -> V_98 <= V_4 )
goto V_99;
if ( ! ( V_70 -> V_95 & V_100 ) )
goto V_93;
if ( ! ( V_41 & V_57 ) ) {
V_24 = F_42 ( V_2 , V_24 ) ;
if ( ( V_24 & 0xc0800000 ) == 0xc0800000 ) {
unsigned char V_54 ;
if ( V_24 & 0x2000 )
V_54 = ( V_2 -> V_52 >> 24 ) ;
else
V_54 = ( V_24 >> 5 ) ;
if ( ( V_54 & 0xf2 ) == 0x82 )
goto V_93;
}
}
if ( F_60 ( V_70 , V_4 ) )
goto V_93;
V_99:
V_44 = V_101 ;
if ( ( V_41 & V_47 ) && ! ( V_70 -> V_95 & V_102 ) ) {
F_61 ( V_4 != V_2 -> V_15 ,
L_17 , V_4 , V_2 -> V_15 ) ;
F_62 ( V_2 -> V_52 & V_53 ) ;
goto V_93;
}
if ( V_41 & V_57 ) {
if ( ! ( V_70 -> V_95 & V_96 ) )
goto V_93;
if ( V_103 == V_104 &&
( V_70 -> V_95 & V_102 ) != 0 &&
V_70 -> V_105 != NULL )
F_63 ( V_41 |
V_106 ) ;
V_73 |= V_107 ;
} else {
if ( ! ( V_70 -> V_95 & ( V_108 | V_102 ) ) )
goto V_93;
}
V_71 = F_64 ( V_70 , V_4 , V_73 ) ;
if ( ( V_71 & V_109 ) && F_65 ( V_17 ) )
goto V_76;
if ( F_17 ( V_71 & V_110 ) ) {
if ( V_71 & V_111 )
goto V_112;
else if ( V_71 & V_113 )
goto V_93;
else if ( V_71 & V_114 )
goto V_92;
F_53 () ;
}
if ( V_73 & V_74 ) {
if ( V_71 & V_115 ) {
V_17 -> V_116 ++ ;
F_56 ( V_117 ,
1 , V_2 , V_4 ) ;
} else {
V_17 -> V_118 ++ ;
F_56 ( V_119 ,
1 , V_2 , V_4 ) ;
}
if ( V_71 & V_109 ) {
V_73 &= ~ V_74 ;
V_73 |= V_120 ;
goto V_90;
}
}
F_66 ( & V_9 -> V_88 ) ;
V_72 = F_67 ( V_9 ) ;
#if F_26 ( V_28 )
V_72 -= ( V_9 -> V_10 . V_121 * ( V_122 / V_7 ) ) ;
#endif
if ( F_17 ( V_72 >
V_9 -> V_10 . V_123 [ V_124 ] . V_125 ) )
F_68 ( V_9 , V_124 , V_72 ) ;
#if F_26 ( V_27 ) || F_26 ( V_28 )
V_72 = V_9 -> V_10 . V_126 + V_9 -> V_10 . V_121 ;
V_72 *= V_127 ;
if ( F_17 ( V_72 >
V_9 -> V_10 . V_123 [ V_128 ] . V_125 ) ) {
if ( V_9 -> V_10 . V_123 [ V_128 ] . V_129 )
F_68 ( V_9 , V_128 , V_72 ) ;
else
F_69 ( V_2 ) ;
}
#endif
V_76:
F_70 ( V_67 ) ;
return;
V_93:
V_24 = F_42 ( V_2 , V_24 ) ;
F_66 ( & V_9 -> V_88 ) ;
V_89:
F_43 ( V_2 , V_44 , V_41 , V_24 , V_4 ) ;
goto V_76;
V_112:
V_24 = F_42 ( V_2 , V_24 ) ;
F_66 ( & V_9 -> V_88 ) ;
if ( ! ( V_2 -> V_52 & V_53 ) ) {
F_71 () ;
goto V_76;
}
goto V_89;
V_81:
V_24 = F_42 ( V_2 , 0 ) ;
goto V_89;
V_92:
V_24 = F_42 ( V_2 , V_24 ) ;
F_66 ( & V_9 -> V_88 ) ;
F_39 ( V_130 , V_131 , V_2 , V_4 , V_24 , V_41 ) ;
if ( V_2 -> V_52 & V_53 )
goto V_89;
}
