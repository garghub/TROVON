static int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_4 = V_1 | V_3 | V_5 ;
V_6 -> V_4 = F_2 ( V_4 ) ;
return 0 ;
}
static T_1 void * F_3 ( unsigned long V_7 )
{
void * V_8 ;
V_8 = F_4 ( F_5 ( V_7 , V_7 , V_9 ) ) ;
memset ( V_8 , 0 , V_7 ) ;
return V_8 ;
}
int F_6 ( unsigned long V_10 , unsigned long V_11 ,
T_2 V_12 ,
unsigned int V_13 )
{
T_3 * V_14 ;
T_4 * V_15 ;
T_5 * V_16 ;
T_6 * V_17 ;
F_7 ( V_18 > V_19 ) ;
if ( F_8 () ) {
V_14 = F_9 ( V_10 ) ;
V_15 = F_10 ( & V_20 , V_14 , V_10 ) ;
if ( ! V_15 )
return - V_21 ;
if ( V_13 == V_22 ) {
V_17 = ( T_6 * ) V_15 ;
goto V_23;
}
V_16 = F_11 ( & V_20 , V_15 , V_10 ) ;
if ( ! V_16 )
return - V_21 ;
if ( V_13 == V_24 ) {
V_17 = F_12 ( V_16 ) ;
goto V_23;
}
V_17 = F_13 ( V_16 , V_10 ) ;
if ( ! V_17 )
return - V_21 ;
} else {
V_14 = F_9 ( V_10 ) ;
if ( F_14 ( * V_14 ) ) {
V_15 = F_3 ( V_25 ) ;
F_15 ( V_15 == NULL ) ;
F_16 ( & V_20 , V_14 , V_15 ) ;
}
V_15 = F_17 ( V_14 , V_10 ) ;
if ( V_13 == V_22 ) {
V_17 = ( T_6 * ) V_15 ;
goto V_23;
}
if ( F_18 ( * V_15 ) ) {
V_16 = F_3 ( V_26 ) ;
F_15 ( V_16 == NULL ) ;
F_19 ( & V_20 , V_15 , V_16 ) ;
}
V_16 = F_20 ( V_15 , V_10 ) ;
if ( V_13 == V_24 ) {
V_17 = F_12 ( V_16 ) ;
goto V_23;
}
if ( ! F_21 ( * V_16 ) ) {
V_17 = F_3 ( V_27 ) ;
F_15 ( V_17 == NULL ) ;
F_22 ( & V_20 , V_16 , V_17 ) ;
}
V_17 = F_23 ( V_16 , V_10 ) ;
}
V_23:
F_24 ( & V_20 , V_10 , V_17 , F_25 ( V_11 >> V_28 , V_12 ) ) ;
F_26 () ;
return 0 ;
}
static void T_7 F_27 ( void )
{
int V_29 ;
T_8 V_1 , V_30 , V_31 ;
unsigned long V_32 ;
struct V_33 * V_34 ;
unsigned long V_35 ;
V_36 = 0 ;
V_29 = 0 ;
F_28 (memory, reg) {
V_31 = V_34 -> V_1 ;
V_37:
if ( V_29 < 1 && V_38 [ V_39 ] . V_40 )
V_35 = V_22 ;
else if ( V_29 < 2 && V_38 [ V_41 ] . V_40 )
V_35 = V_24 ;
else
V_35 = V_27 ;
V_1 = F_29 ( V_31 , V_35 ) ;
V_30 = F_30 ( V_34 -> V_1 + V_34 -> V_7 , V_35 ) ;
F_31 ( L_1 ,
( unsigned long ) V_1 , ( unsigned long ) V_30 ,
V_35 ) ;
while ( V_1 < V_30 ) {
F_6 ( ( unsigned long ) F_4 ( V_1 ) ,
V_1 , V_42 ,
V_35 ) ;
V_1 += V_35 ;
}
if ( V_30 < V_34 -> V_1 + V_34 -> V_7 ) {
V_31 = V_30 ;
V_29 ++ ;
goto V_37;
}
}
F_32 ( ( V_43 > 36 ) , L_2 ) ;
V_44 = F_3 ( 1UL << V_43 ) ;
V_32 = F_33 () ;
V_44 -> V_45 = F_2 ( V_32 | F_34 ( V_20 . V_46 ) | V_47 ) ;
F_35 ( F_34 ( V_44 ) , 0 , V_43 - 12 ) ;
F_31 ( L_3 , V_44 , V_20 . V_46 ) ;
}
static void T_7 F_36 ( void )
{
unsigned long V_32 , V_48 ;
F_37 () ;
V_32 = F_33 () ;
V_48 = V_32 | F_34 ( V_20 . V_46 ) | V_47 | V_49 ;
F_38 ( 0 , V_48 , 0 ) ;
F_31 ( L_4 ) ;
F_31 ( L_5 , V_6 ) ;
}
void T_7 F_39 ( void )
{
F_35 = F_1 ;
}
static int T_7 F_40 ( unsigned int V_40 )
{
int V_50 = - 1 ;
switch ( V_40 ) {
case 0xc :
V_50 = V_51 ;
break;
case 0x10 :
V_50 = V_52 ;
break;
case 0x15 :
V_50 = V_41 ;
break;
case 0x1e :
V_50 = V_39 ;
break;
}
return V_50 ;
}
static int T_7 F_41 ( unsigned long V_53 ,
const char * V_54 , int V_55 ,
void * V_56 )
{
int V_7 = 0 ;
int V_40 , V_50 ;
unsigned int V_57 ;
const T_9 * V_58 ;
const char * type = F_42 ( V_53 , L_6 , NULL ) ;
if ( type == NULL || strcmp ( type , L_7 ) != 0 )
return 0 ;
V_58 = F_42 ( V_53 , L_8 , & V_7 ) ;
if ( ! V_58 )
return 0 ;
F_31 ( L_9 ) ;
for (; V_7 >= 4 ; V_7 -= 4 , ++ V_58 ) {
struct V_59 * V_60 ;
V_40 = F_43 ( V_58 [ 0 ] ) & ~ ( 0xe << 28 ) ;
V_57 = F_43 ( V_58 [ 0 ] ) >> 29 ;
F_31 ( L_10 , V_40 , V_57 ) ;
V_50 = F_40 ( V_40 ) ;
if ( V_50 < 0 )
continue;
V_60 = & V_38 [ V_50 ] ;
V_60 -> V_40 = V_40 ;
V_60 -> V_57 = V_57 ;
}
V_61 -> V_62 &= ~ V_63 ;
return 1 ;
}
void T_7 F_44 ( void )
{
int V_64 ;
V_64 = F_45 ( F_41 , NULL ) ;
if ( V_64 != 0 )
goto V_65;
V_38 [ V_51 ] . V_40 = 12 ;
V_38 [ V_51 ] . V_57 = 0x0 ;
V_38 [ V_52 ] . V_40 = 16 ;
V_38 [ V_52 ] . V_57 = 0x5 ;
V_65:
#ifdef F_46
if ( V_38 [ V_41 ] . V_40 ) {
V_66 = V_41 ;
}
#endif
return;
}
static void F_47 ( void )
{
unsigned long V_67 ;
unsigned long V_68 = 3UL << F_48 ( 53 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(0), "i"(2), "r"(0) : "memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(1), "i"(2), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync; isync; slbia": : :"memory");
V_67 = F_49 ( V_69 ) ;
V_67 |= V_70 ;
F_50 ( V_69 , V_67 ) ;
asm volatile("isync": : :"memory");
while ( ! ( F_49 ( V_69 ) & V_70 ) )
F_51 () ;
}
static void F_52 ( void )
{
F_50 ( V_71 , ( 3ul << 62 ) ) ;
}
static void F_53 ( void )
{
unsigned long V_72 ;
if ( F_54 ( V_73 ) )
V_72 = 0 ;
else
V_72 = ( 1ul << 62 ) ;
F_50 ( V_74 , V_72 ) ;
}
void T_7 F_55 ( void )
{
unsigned long V_75 ;
#ifdef F_56
V_76 = V_52 ;
#else
V_76 = V_51 ;
#endif
#ifdef F_46
V_66 = V_76 ;
#endif
V_77 = V_78 ;
V_79 = V_80 ;
V_81 = V_82 ;
V_83 = V_47 ;
V_84 = V_80 ;
V_85 = V_86 ;
V_87 = V_88 ;
V_89 = V_90 ;
V_91 = V_92 ;
V_93 = V_94 ;
V_95 = V_96 ;
V_97 = V_98 ;
V_99 = V_100 ;
V_101 = V_102 ;
V_103 = V_104 ;
V_105 = V_106 ;
V_107 = (struct V_108 * ) V_109 ;
V_110 = V_111 ;
#ifdef F_57
V_112 = V_113 ;
#endif
V_114 = V_115 ;
V_116 = V_117 ;
if ( ! F_58 ( V_118 ) ) {
F_39 () ;
if ( F_54 ( V_73 ) )
F_47 () ;
V_75 = F_49 ( V_119 ) ;
F_50 ( V_119 , V_75 | V_120 | V_121 ) ;
F_36 () ;
F_52 () ;
}
F_59 ( V_9 ) ;
F_53 () ;
F_27 () ;
}
void F_60 ( void )
{
unsigned long V_75 ;
if ( ! F_58 ( V_118 ) ) {
if ( F_54 ( V_73 ) )
F_47 () ;
V_75 = F_49 ( V_119 ) ;
F_50 ( V_119 , V_75 | V_120 | V_121 ) ;
F_50 ( V_122 ,
F_34 ( V_6 ) | ( V_123 - 12 ) ) ;
F_52 () ;
}
F_53 () ;
}
void F_61 ( void )
{
unsigned long V_75 ;
if ( ! F_58 ( V_118 ) ) {
V_75 = F_49 ( V_119 ) ;
F_50 ( V_119 , V_75 & ~ V_120 ) ;
F_50 ( V_122 , 0 ) ;
F_62 () ;
}
}
void F_63 ( T_10 V_124 ,
T_10 V_125 )
{
F_15 ( V_124 != 0 ) ;
V_126 = F_64 ( T_8 , V_125 , 0x40000000 ) ;
F_59 ( V_124 + V_125 ) ;
}
int T_11 F_65 ( unsigned long V_127 ,
unsigned long V_128 ,
unsigned long V_129 )
{
unsigned long V_12 = V_130 | V_131 | V_132 ;
F_15 ( F_6 ( V_127 , V_129 , F_66 ( V_12 ) , V_128 ) ) ;
return 0 ;
}
void F_67 ( unsigned long V_127 , unsigned long V_128 )
{
}
unsigned long F_68 ( struct V_133 * V_134 , unsigned long V_135 ,
T_5 * V_16 , unsigned long V_136 ,
unsigned long V_137 )
{
unsigned long V_138 ;
#ifdef F_69
F_70 ( ! F_71 ( * V_16 ) ) ;
F_72 ( & V_134 -> V_139 ) ;
#endif
V_138 = F_73 ( V_134 , V_135 , ( T_6 * ) V_16 , V_136 , V_137 , 1 ) ;
F_74 ( V_135 , V_138 , V_136 , V_137 ) ;
return V_138 ;
}
T_5 F_75 ( struct V_140 * V_141 , unsigned long V_142 ,
T_5 * V_16 )
{
T_5 V_143 ;
F_76 ( V_142 & ~ V_144 ) ;
F_76 ( F_71 ( * V_16 ) ) ;
V_143 = * V_16 ;
F_77 ( V_16 ) ;
F_78 () ;
F_79 ( V_141 , V_142 , V_142 + V_145 ) ;
return V_143 ;
}
void F_80 ( struct V_133 * V_134 , T_5 * V_16 ,
T_12 V_146 )
{
struct V_147 * V_148 = (struct V_147 * ) V_146 ;
F_72 ( F_81 ( V_134 , V_16 ) ) ;
if ( ! F_82 ( V_134 , V_16 ) )
F_83 ( V_148 ) ;
else
F_84 ( V_148 , (struct V_147 * ) F_82 ( V_134 , V_16 ) ) ;
F_82 ( V_134 , V_16 ) = V_146 ;
}
T_12 F_85 ( struct V_133 * V_134 , T_5 * V_16 )
{
T_6 * V_17 ;
T_12 V_146 ;
struct V_147 * V_148 ;
F_72 ( F_81 ( V_134 , V_16 ) ) ;
V_146 = F_82 ( V_134 , V_16 ) ;
V_148 = (struct V_147 * ) V_146 ;
if ( F_86 ( V_148 ) )
F_82 ( V_134 , V_16 ) = NULL ;
else {
F_82 ( V_134 , V_16 ) = ( T_12 ) V_148 -> V_149 ;
F_87 ( V_148 ) ;
}
V_17 = ( T_6 * ) V_146 ;
* V_17 = F_88 ( 0 ) ;
V_17 ++ ;
* V_17 = F_88 ( 0 ) ;
return V_146 ;
}
T_5 F_89 ( struct V_133 * V_134 ,
unsigned long V_135 , T_5 * V_16 )
{
T_5 V_150 ;
unsigned long V_138 ;
V_138 = F_68 ( V_134 , V_135 , V_16 , ~ 0UL , 0 ) ;
V_150 = F_90 ( V_138 ) ;
F_78 () ;
return V_150 ;
}
int F_91 ( void )
{
if ( V_38 [ V_41 ] . V_40 == V_151 )
return 1 ;
return 0 ;
}
