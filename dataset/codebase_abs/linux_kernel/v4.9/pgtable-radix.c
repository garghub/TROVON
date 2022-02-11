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
V_17 = ( T_6 * ) V_15 ;
goto V_23;
}
V_17 = F_12 ( V_16 , V_10 ) ;
if ( ! V_17 )
return - V_21 ;
} else {
V_14 = F_9 ( V_10 ) ;
if ( F_13 ( * V_14 ) ) {
V_15 = F_3 ( V_25 ) ;
F_14 ( V_15 == NULL ) ;
F_15 ( & V_20 , V_14 , V_15 ) ;
}
V_15 = F_16 ( V_14 , V_10 ) ;
if ( V_13 == V_22 ) {
V_17 = ( T_6 * ) V_15 ;
goto V_23;
}
if ( F_17 ( * V_15 ) ) {
V_16 = F_3 ( V_26 ) ;
F_14 ( V_16 == NULL ) ;
F_18 ( & V_20 , V_15 , V_16 ) ;
}
V_16 = F_19 ( V_15 , V_10 ) ;
if ( V_13 == V_24 ) {
V_17 = ( T_6 * ) V_15 ;
goto V_23;
}
if ( ! F_20 ( * V_16 ) ) {
V_17 = F_3 ( V_27 ) ;
F_14 ( V_17 == NULL ) ;
F_21 ( & V_20 , V_16 , V_17 ) ;
}
V_17 = F_22 ( V_16 , V_10 ) ;
}
V_23:
F_23 ( & V_20 , V_10 , V_17 , F_24 ( V_11 >> V_28 , V_12 ) ) ;
F_25 () ;
return 0 ;
}
static void T_7 F_26 ( void )
{
int V_29 ;
T_8 V_1 , V_30 , V_31 ;
unsigned long V_32 ;
struct V_33 * V_34 ;
unsigned long V_35 ;
V_36 = 0 ;
V_29 = 0 ;
F_27 (memory, reg) {
V_31 = V_34 -> V_1 ;
V_37:
if ( V_29 < 1 && V_38 [ V_39 ] . V_40 )
V_35 = V_22 ;
else if ( V_29 < 2 && V_38 [ V_41 ] . V_40 )
V_35 = V_24 ;
else
V_35 = V_27 ;
V_1 = F_28 ( V_31 , V_35 ) ;
V_30 = F_29 ( V_34 -> V_1 + V_34 -> V_7 , V_35 ) ;
F_30 ( L_1 ,
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
F_31 ( ( V_43 > 23 ) , L_2 ) ;
V_44 = F_3 ( 1UL << V_43 ) ;
V_32 = F_32 () ;
V_44 -> V_45 = F_2 ( V_32 | F_33 ( V_20 . V_46 ) | V_47 ) ;
F_34 ( F_33 ( V_44 ) , 0 , V_43 - 12 ) ;
F_30 ( L_3 , V_44 , V_20 . V_46 ) ;
}
static void T_7 F_35 ( void )
{
unsigned long V_32 ;
V_32 = F_32 () ;
F_31 ( ( V_48 > 24 ) , L_4 ) ;
V_6 = F_3 ( 1UL << V_48 ) ;
V_6 -> V_49 = F_2 ( V_32 | F_33 ( V_20 . V_46 ) |
V_47 | V_50 ) ;
F_30 ( L_5 ) ;
F_30 ( L_6 , V_6 ) ;
F_36 ( V_9 ) ;
F_37 ( V_51 , F_33 ( V_6 ) | ( V_48 - 12 ) ) ;
}
void T_7 F_38 ( void )
{
F_34 = F_1 ;
}
static int T_7 F_39 ( unsigned int V_40 )
{
int V_52 = - 1 ;
switch ( V_40 ) {
case 0xc :
V_52 = V_53 ;
break;
case 0x10 :
V_52 = V_54 ;
break;
case 0x15 :
V_52 = V_41 ;
break;
case 0x1e :
V_52 = V_39 ;
break;
}
return V_52 ;
}
static int T_7 F_40 ( unsigned long V_55 ,
const char * V_56 , int V_57 ,
void * V_58 )
{
int V_7 = 0 ;
int V_40 , V_52 ;
unsigned int V_59 ;
const T_9 * V_60 ;
const char * type = F_41 ( V_55 , L_7 , NULL ) ;
if ( type == NULL || strcmp ( type , L_8 ) != 0 )
return 0 ;
V_60 = F_41 ( V_55 , L_9 , & V_7 ) ;
if ( ! V_60 )
return 0 ;
F_30 ( L_10 ) ;
for (; V_7 >= 4 ; V_7 -= 4 , ++ V_60 ) {
struct V_61 * V_62 ;
V_40 = F_42 ( V_60 [ 0 ] ) & ~ ( 0xe << 28 ) ;
V_59 = F_42 ( V_60 [ 0 ] ) >> 29 ;
F_30 ( L_11 , V_40 , V_59 ) ;
V_52 = F_39 ( V_40 ) ;
if ( V_52 < 0 )
continue;
V_62 = & V_38 [ V_52 ] ;
V_62 -> V_40 = V_40 ;
V_62 -> V_59 = V_59 ;
}
V_63 -> V_64 &= ~ V_65 ;
return 1 ;
}
void T_7 F_43 ( void )
{
int V_66 ;
V_66 = F_44 ( F_40 , NULL ) ;
if ( V_66 != 0 )
goto V_67;
V_38 [ V_53 ] . V_40 = 12 ;
V_38 [ V_53 ] . V_59 = 0x0 ;
V_38 [ V_54 ] . V_40 = 16 ;
V_38 [ V_54 ] . V_59 = 0x5 ;
V_67:
#ifdef F_45
if ( V_38 [ V_41 ] . V_40 ) {
V_68 = V_41 ;
}
#endif
return;
}
static void F_46 ( void )
{
unsigned long V_69 ;
unsigned long V_70 = 3UL << F_47 ( 53 ) ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(0), "i"(2), "r"(0) : "memory");
asm volatile(PPC_TLBIE_5(%0, %4, %3, %2, %1)
: : "r"(rb), "i"(1), "i"(1), "i"(2), "r"(0) : "memory");
asm volatile("eieio; tlbsync; ptesync; isync; slbia": : :"memory");
V_69 = F_48 ( V_71 ) ;
V_69 |= V_72 ;
F_37 ( V_71 , V_69 ) ;
asm volatile("isync": : :"memory");
while ( ! ( F_48 ( V_71 ) & V_72 ) )
F_49 () ;
}
void T_7 F_50 ( void )
{
unsigned long V_73 ;
#ifdef F_51
V_74 = V_54 ;
#else
V_74 = V_53 ;
#endif
#ifdef F_45
V_68 = V_74 ;
#endif
V_75 = V_76 ;
V_77 = V_78 ;
V_79 = V_80 ;
V_81 = V_47 ;
V_82 = V_78 ;
V_83 = V_84 ;
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
V_105 = (struct V_106 * ) V_107 ;
V_108 = V_109 ;
#ifdef F_52
V_110 = V_111 ;
#endif
V_112 = V_113 ;
V_114 = V_115 ;
if ( ! F_53 ( V_116 ) ) {
F_38 () ;
if ( F_54 ( V_117 ) )
F_46 () ;
V_73 = F_48 ( V_118 ) ;
F_37 ( V_118 , V_73 | V_119 | V_120 ) ;
F_35 () ;
}
F_26 () ;
}
void F_55 ( void )
{
unsigned long V_73 ;
if ( ! F_53 ( V_116 ) ) {
if ( F_54 ( V_117 ) )
F_46 () ;
V_73 = F_48 ( V_118 ) ;
F_37 ( V_118 , V_73 | V_119 | V_120 ) ;
F_37 ( V_51 ,
F_33 ( V_6 ) | ( V_48 - 12 ) ) ;
}
}
void F_56 ( void )
{
unsigned long V_73 ;
if ( ! F_53 ( V_116 ) ) {
V_73 = F_48 ( V_118 ) ;
F_37 ( V_118 , V_73 & ~ V_119 ) ;
F_37 ( V_51 , 0 ) ;
F_57 () ;
}
}
void F_58 ( T_10 V_121 ,
T_10 V_122 )
{
F_14 ( V_121 != 0 ) ;
V_123 = F_59 ( T_8 , V_122 , 0x40000000 ) ;
F_36 ( V_121 + V_122 ) ;
}
int T_11 F_60 ( unsigned long V_124 ,
unsigned long V_125 ,
unsigned long V_126 )
{
unsigned long V_12 = V_127 | V_128 | V_129 ;
F_14 ( F_6 ( V_124 , V_126 , F_61 ( V_12 ) , V_125 ) ) ;
return 0 ;
}
void F_62 ( unsigned long V_124 , unsigned long V_125 )
{
}
unsigned long F_63 ( struct V_130 * V_131 , unsigned long V_132 ,
T_5 * V_16 , unsigned long V_133 ,
unsigned long V_134 )
{
unsigned long V_135 ;
#ifdef F_64
F_65 ( ! F_66 ( * V_16 ) ) ;
F_67 ( & V_131 -> V_136 ) ;
#endif
V_135 = F_68 ( V_131 , V_132 , ( T_6 * ) V_16 , V_133 , V_134 , 1 ) ;
F_69 ( V_132 , V_135 , V_133 , V_134 ) ;
return V_135 ;
}
T_5 F_70 ( struct V_137 * V_138 , unsigned long V_139 ,
T_5 * V_16 )
{
T_5 V_140 ;
F_71 ( V_139 & ~ V_141 ) ;
F_71 ( F_66 ( * V_16 ) ) ;
V_140 = * V_16 ;
F_72 ( V_16 ) ;
F_73 () ;
F_74 ( V_138 , V_139 , V_139 + V_142 ) ;
return V_140 ;
}
void F_75 ( struct V_130 * V_131 , T_5 * V_16 ,
T_12 V_143 )
{
struct V_144 * V_145 = (struct V_144 * ) V_143 ;
F_67 ( F_76 ( V_131 , V_16 ) ) ;
if ( ! F_77 ( V_131 , V_16 ) )
F_78 ( V_145 ) ;
else
F_79 ( V_145 , (struct V_144 * ) F_77 ( V_131 , V_16 ) ) ;
F_77 ( V_131 , V_16 ) = V_143 ;
}
T_12 F_80 ( struct V_130 * V_131 , T_5 * V_16 )
{
T_6 * V_17 ;
T_12 V_143 ;
struct V_144 * V_145 ;
F_67 ( F_76 ( V_131 , V_16 ) ) ;
V_143 = F_77 ( V_131 , V_16 ) ;
V_145 = (struct V_144 * ) V_143 ;
if ( F_81 ( V_145 ) )
F_77 ( V_131 , V_16 ) = NULL ;
else {
F_77 ( V_131 , V_16 ) = ( T_12 ) V_145 -> V_146 ;
F_82 ( V_145 ) ;
}
V_17 = ( T_6 * ) V_143 ;
* V_17 = F_83 ( 0 ) ;
V_17 ++ ;
* V_17 = F_83 ( 0 ) ;
return V_143 ;
}
T_5 F_84 ( struct V_130 * V_131 ,
unsigned long V_132 , T_5 * V_16 )
{
T_5 V_147 ;
unsigned long V_135 ;
V_135 = F_63 ( V_131 , V_132 , V_16 , ~ 0UL , 0 ) ;
V_147 = F_85 ( V_135 ) ;
F_73 () ;
return V_147 ;
}
int F_86 ( void )
{
if ( V_38 [ V_41 ] . V_40 == V_148 )
return 1 ;
return 0 ;
}
