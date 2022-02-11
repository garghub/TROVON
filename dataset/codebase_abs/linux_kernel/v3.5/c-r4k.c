static inline void F_1 ( void (* F_2) ( void * V_1 ) , void * V_1 )
{
F_3 () ;
#if ! F_4 ( V_2 ) && ! F_4 ( V_3 )
F_5 ( F_2 , V_1 , 1 ) ;
#endif
F_2 ( V_1 ) ;
F_6 () ;
}
static void F_7 ( void ) {}
static inline void F_8 ( unsigned long V_4 )
{
V_5 ;
F_9 ( V_4 ) ;
}
static inline void F_10 ( unsigned long V_4 )
{
V_5 ;
F_11 ( V_4 ) ;
}
static void T_1 F_12 ( void )
{
unsigned long V_6 = F_13 () ;
if ( V_6 == 0 )
V_7 = ( void * ) F_7 ;
else if ( V_6 == 16 )
V_7 = V_8 ;
else if ( V_6 == 32 )
V_7 = F_8 ;
else if ( V_6 == 64 )
V_7 = F_10 ;
}
static void T_1 F_14 ( void )
{
unsigned long V_6 = F_13 () ;
if ( V_6 == 0 )
V_9 = ( void * ) F_7 ;
else if ( V_6 == 16 )
V_9 = V_10 ;
else if ( V_6 == 32 )
V_9 = V_11 ;
else if ( V_6 == 64 )
V_9 = V_12 ;
}
static void T_1 F_15 ( void )
{
unsigned long V_6 = F_13 () ;
if ( V_6 == 0 )
V_13 = ( void * ) F_7 ;
else if ( V_6 == 16 )
V_13 = V_14 ;
else if ( V_6 == 32 )
V_13 = V_15 ;
else if ( V_6 == 64 )
V_13 = V_16 ;
}
static inline void F_16 ( void )
{
unsigned long V_17 ;
F_17 ( V_17 ) ;
F_18 () ;
F_19 ( V_17 ) ;
}
static inline void F_20 ( void )
{
unsigned long V_18 = V_19 ;
unsigned long V_20 = V_18 + V_21 . V_22 . V_23 ;
unsigned long V_24 = 1UL << V_21 . V_22 . V_25 ;
unsigned long V_26 = V_21 . V_22 . V_27 <<
V_21 . V_22 . V_25 ;
unsigned long V_28 , V_4 ;
V_29 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 += V_24 )
for ( V_4 = V_18 + 0x400 ; V_4 < V_20 ; V_4 += 0x400 * 2 )
F_21 ( V_4 | V_28 , V_30 ) ;
V_31 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 += V_24 )
for ( V_4 = V_18 ; V_4 < V_20 ; V_4 += 0x400 * 2 )
F_21 ( V_4 | V_28 , V_30 ) ;
}
static inline void F_22 ( unsigned long V_32 )
{
unsigned long V_17 ;
F_17 ( V_17 ) ;
F_23 ( V_32 ) ;
F_19 ( V_17 ) ;
}
static inline void F_24 ( unsigned long V_32 )
{
unsigned long V_33 = V_21 . V_22 . V_23 - 1 ;
unsigned long V_18 = V_19 + ( V_32 & V_33 ) ;
unsigned long V_20 = V_18 + V_34 ;
unsigned long V_24 = 1UL << V_21 . V_22 . V_25 ;
unsigned long V_26 = V_21 . V_22 . V_27 <<
V_21 . V_22 . V_25 ;
unsigned long V_28 , V_4 ;
V_29 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 += V_24 )
for ( V_4 = V_18 + 0x400 ; V_4 < V_20 ; V_4 += 0x400 * 2 )
F_21 ( V_4 | V_28 , V_30 ) ;
V_31 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 += V_24 )
for ( V_4 = V_18 ; V_4 < V_20 ; V_4 += 0x400 * 2 )
F_21 ( V_4 | V_28 , V_30 ) ;
}
static void T_1 F_25 ( void )
{
unsigned long V_35 = F_26 () ;
if ( V_35 == 0 )
V_36 = ( void * ) F_7 ;
else if ( V_35 == 16 )
V_36 = V_37 ;
else if ( V_35 == 32 )
V_36 = V_38 ;
else if ( V_35 == 64 )
V_36 = V_39 ;
}
static void T_1 F_27 ( void )
{
unsigned long V_35 = F_26 () ;
if ( V_35 == 0 )
V_40 = ( void * ) F_7 ;
else if ( V_35 == 16 )
V_40 = V_41 ;
else if ( V_35 == 32 ) {
if ( V_42 && F_28 () )
V_40 =
F_22 ;
else if ( V_43 )
V_40 =
F_24 ;
else
V_40 =
F_23 ;
} else if ( V_35 == 64 )
V_40 = V_44 ;
}
static void T_1 F_29 ( void )
{
unsigned long V_35 = F_26 () ;
if ( V_35 == 0 )
V_45 = ( void * ) F_7 ;
else if ( V_35 == 16 )
V_45 = V_46 ;
else if ( V_35 == 32 ) {
if ( V_42 && F_28 () )
V_45 = F_16 ;
else if ( V_43 )
V_45 = F_20 ;
else
V_45 = F_18 ;
} else if ( V_35 == 64 )
V_45 = V_47 ;
}
static void T_1 F_30 ( void )
{
unsigned long V_48 = F_31 () ;
if ( V_49 == 0 )
V_50 = ( void * ) F_7 ;
else if ( V_48 == 16 )
V_50 = V_51 ;
else if ( V_48 == 32 )
V_50 = V_52 ;
else if ( V_48 == 64 )
V_50 = V_53 ;
else if ( V_48 == 128 )
V_50 = V_54 ;
}
static void T_1 F_32 ( void )
{
unsigned long V_48 = F_31 () ;
if ( V_49 == 0 )
V_55 = ( void * ) F_7 ;
else if ( V_48 == 16 )
V_55 = V_56 ;
else if ( V_48 == 32 )
V_55 = V_57 ;
else if ( V_48 == 64 )
V_55 = V_58 ;
else if ( V_48 == 128 )
V_55 = V_59 ;
}
static void T_1 F_33 ( void )
{
unsigned long V_48 = F_31 () ;
if ( V_49 == 0 )
V_60 = ( void * ) F_7 ;
else if ( V_48 == 16 )
V_60 = V_61 ;
else if ( V_48 == 32 )
V_60 = V_62 ;
else if ( V_48 == 64 )
V_60 = V_63 ;
else if ( V_48 == 128 )
V_60 = V_64 ;
}
static inline void F_34 ( void * args )
{
#if F_4 ( V_65 )
V_60 () ;
return;
#endif
V_13 () ;
V_45 () ;
switch ( F_35 () ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
V_60 () ;
}
}
static void F_36 ( void )
{
F_1 ( F_34 , NULL ) ;
}
static inline int F_37 ( const struct V_73 * V_74 )
{
#if F_4 ( V_2 ) || F_4 ( V_3 )
int V_75 ;
F_38 (i)
if ( F_39 ( V_75 , V_74 ) )
return 1 ;
return 0 ;
#else
return F_39 ( F_40 () , V_74 ) ;
#endif
}
static void F_41 ( void )
{
V_13 () ;
}
static void F_42 ( void )
{
V_13 () ;
}
static inline void F_43 ( void * args )
{
struct V_76 * V_77 = args ;
int V_78 = V_77 -> V_79 & V_80 ;
if ( ! ( F_37 ( V_77 -> V_81 ) ) )
return;
V_13 () ;
if ( V_78 )
V_45 () ;
}
static void F_44 ( struct V_76 * V_77 ,
unsigned long V_18 , unsigned long V_20 )
{
int V_78 = V_77 -> V_79 & V_80 ;
if ( V_82 || ( V_78 && ! V_83 ) )
F_1 ( F_43 , V_77 ) ;
}
static inline void F_45 ( void * args )
{
struct V_73 * V_74 = args ;
if ( ! F_37 ( V_74 ) )
return;
if ( F_35 () == V_66 ||
F_35 () == V_67 ||
F_35 () == V_68 ||
F_35 () == V_69 ) {
V_60 () ;
return;
}
V_13 () ;
}
static void F_46 ( struct V_73 * V_74 )
{
if ( ! V_82 )
return;
F_1 ( F_45 , V_74 ) ;
}
static inline void F_47 ( void * args )
{
struct V_84 * V_85 = args ;
struct V_76 * V_77 = V_85 -> V_77 ;
unsigned long V_4 = V_85 -> V_4 ;
struct V_32 * V_32 = F_48 ( V_85 -> V_86 ) ;
int V_78 = V_77 -> V_79 & V_80 ;
struct V_73 * V_74 = V_77 -> V_81 ;
int V_87 = 0 ;
T_2 * V_88 ;
T_3 * V_89 ;
T_4 * V_90 ;
T_5 * V_91 ;
void * V_92 ;
if ( ! F_37 ( V_74 ) )
return;
V_4 &= V_93 ;
V_88 = F_49 ( V_74 , V_4 ) ;
V_89 = F_50 ( V_88 , V_4 ) ;
V_90 = F_51 ( V_89 , V_4 ) ;
V_91 = F_52 ( V_90 , V_4 ) ;
if ( ! ( F_53 ( * V_91 ) ) )
return;
if ( ( V_74 == V_94 -> V_95 ) && ( F_54 ( * V_91 ) & V_96 ) )
V_92 = NULL ;
else {
V_87 = ( V_82 &&
F_55 ( V_32 ) && ! F_56 ( V_32 ) ) ;
if ( V_87 )
V_92 = F_57 ( V_32 , V_4 ) ;
else
V_92 = F_58 ( V_32 ) ;
V_4 = ( unsigned long ) V_92 ;
}
if ( V_82 || ( V_78 && ! V_83 ) ) {
V_7 ( V_4 ) ;
if ( V_78 && ! V_97 )
V_50 ( V_4 ) ;
}
if ( V_78 ) {
if ( V_92 && V_98 && V_74 == V_94 -> V_95 ) {
int V_99 = F_40 () ;
if ( F_39 ( V_99 , V_74 ) != 0 )
F_59 ( V_74 , V_99 ) ;
} else
V_36 ( V_4 ) ;
}
if ( V_92 ) {
if ( V_87 )
F_60 () ;
else
F_61 ( V_92 ) ;
}
}
static void F_62 ( struct V_76 * V_77 ,
unsigned long V_4 , unsigned long V_86 )
{
struct V_84 args ;
args . V_77 = V_77 ;
args . V_4 = V_4 ;
args . V_86 = V_86 ;
F_1 ( F_47 , & args ) ;
}
static inline void F_63 ( void * V_4 )
{
V_7 ( ( unsigned long ) V_4 ) ;
}
static void F_64 ( unsigned long V_4 )
{
if ( F_65 () )
F_63 ( ( void * ) V_4 ) ;
else
F_1 ( F_63 , ( void * ) V_4 ) ;
}
static inline void F_66 ( unsigned long V_18 , unsigned long V_20 )
{
if ( ! V_83 ) {
if ( V_20 - V_18 >= V_100 ) {
V_13 () ;
} else {
V_5 ;
F_67 ( V_18 , V_20 ) ;
}
}
if ( V_20 - V_18 > V_101 )
V_45 () ;
else
F_68 ( V_18 , V_20 ) ;
}
static inline void F_69 ( void * args )
{
struct V_102 * V_103 = args ;
unsigned long V_18 = V_103 -> V_18 ;
unsigned long V_20 = V_103 -> V_20 ;
F_66 ( V_18 , V_20 ) ;
}
static void F_70 ( unsigned long V_18 , unsigned long V_20 )
{
struct V_102 args ;
args . V_18 = V_18 ;
args . V_20 = V_20 ;
F_1 ( F_69 , & args ) ;
F_71 () ;
}
static void F_72 ( unsigned long V_4 , unsigned long V_104 )
{
F_73 ( V_104 == 0 ) ;
if ( V_105 ) {
if ( V_104 >= V_49 )
V_60 () ;
else
F_74 ( V_4 , V_4 + V_104 ) ;
F_75 () ;
return;
}
if ( V_106 && V_104 >= V_100 ) {
V_13 () ;
} else {
V_5 ;
F_76 ( V_4 , V_4 + V_104 ) ;
}
F_77 ( V_4 , V_104 ) ;
F_75 () ;
}
static void F_78 ( unsigned long V_4 , unsigned long V_104 )
{
F_73 ( V_104 == 0 ) ;
if ( V_105 ) {
if ( V_104 >= V_49 )
V_60 () ;
else {
unsigned long V_107 = F_31 () ;
unsigned long V_108 = ~ ( V_107 - 1 ) ;
F_79 ( V_109 , V_4 & V_108 ) ;
F_79 ( V_109 ,
( V_4 + V_104 - 1 ) & V_108 ) ;
F_80 ( V_4 , V_4 + V_104 ) ;
}
F_75 () ;
return;
}
if ( V_106 && V_104 >= V_100 ) {
V_13 () ;
} else {
unsigned long V_107 = F_13 () ;
unsigned long V_108 = ~ ( V_107 - 1 ) ;
V_5 ;
F_79 ( V_110 , V_4 & V_108 ) ;
F_79 ( V_110 , ( V_4 + V_104 - 1 ) & V_108 ) ;
F_81 ( V_4 , V_4 + V_104 ) ;
}
F_82 ( V_4 , V_104 ) ;
F_75 () ;
}
static void F_83 ( void * V_111 )
{
unsigned long V_35 = F_26 () ;
unsigned long V_6 = F_13 () ;
unsigned long V_48 = F_31 () ;
unsigned long V_4 = ( unsigned long ) V_111 ;
V_5 ;
if ( V_6 )
F_84 ( V_4 & ~ ( V_6 - 1 ) ) ;
if ( ! V_97 && V_49 )
F_85 ( V_4 & ~ ( V_48 - 1 ) ) ;
if ( V_35 )
F_86 ( V_4 & ~ ( V_35 - 1 ) ) ;
if ( V_112 ) {
__asm__ __volatile__ (
".set push\n\t"
".set noat\n\t"
".set mips3\n\t"
#ifdef F_87
"la $at,1f\n\t"
#endif
#ifdef F_88
"dla $at,1f\n\t"
#endif
"cache %0,($at)\n\t"
"nop; nop; nop\n"
"1:\n\t"
".set pop"
:
: "i" (Hit_Invalidate_I));
}
if ( V_113 )
__asm__ __volatile__ ("sync");
}
static void F_89 ( unsigned long V_4 )
{
F_1 ( F_83 , ( void * ) V_4 ) ;
}
static void F_90 ( void )
{
if ( V_98 )
V_45 () ;
}
static inline void F_91 ( void * args )
{
struct V_114 * V_115 = args ;
unsigned long V_92 = V_115 -> V_92 ;
int V_104 = V_115 -> V_104 ;
if ( V_106 && V_104 >= V_100 )
V_13 () ;
else {
V_5 ;
F_76 ( V_92 , V_92 + V_104 ) ;
}
}
static void F_92 ( unsigned long V_92 , int V_104 )
{
struct V_114 args ;
args . V_92 = ( unsigned long ) V_92 ;
args . V_104 = V_104 ;
F_1 ( F_91 , & args ) ;
}
static inline void F_93 ( void )
{
const unsigned long V_35 = 32 ;
unsigned long V_4 ;
F_94 ( 0 ) ;
F_95 ( 0 ) ;
for ( V_4 = V_19 ; V_4 <= V_19 + 4096 ; V_4 += V_35 ) {
__asm__ __volatile__ (
".set push\n\t"
".set noreorder\n\t"
".set mips3\n\t"
"cache\t%1, 0(%0)\n\t"
"cache\t%1, 0x1000(%0)\n\t"
"cache\t%1, 0x2000(%0)\n\t"
"cache\t%1, 0x3000(%0)\n\t"
"cache\t%2, 0(%0)\n\t"
"cache\t%2, 0x1000(%0)\n\t"
"cache\t%2, 0x2000(%0)\n\t"
"cache\t%2, 0x3000(%0)\n\t"
"cache\t%1, 0(%0)\n\t"
"cache\t%1, 0x1000(%0)\n\t"
"cache\t%1, 0x2000(%0)\n\t"
"cache\t%1, 0x3000(%0)\n\t"
".set pop\n"
:
: "r" (addr), "i" (Index_Store_Tag_I), "i" (Fill));
}
}
static void T_1 F_96 ( void )
{
struct V_116 * V_117 = & V_21 ;
unsigned int V_118 = F_97 () ;
unsigned int V_119 = F_98 () ;
unsigned long V_120 ;
unsigned int V_107 ;
switch ( V_117 -> V_121 ) {
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_101 = 1 << ( 12 + ( ( V_118 & V_126 ) >> 9 ) ) ;
V_117 -> V_22 . V_127 = 16 << ( ( V_118 & V_128 ) >> 5 ) ;
V_117 -> V_22 . V_27 = 2 ;
V_117 -> V_22 . V_25 = F_99 ( V_101 / 2 ) ;
V_100 = 1 << ( 12 + ( ( V_118 & V_129 ) >> 6 ) ) ;
V_117 -> V_130 . V_127 = 16 << ( ( V_118 & V_131 ) >> 4 ) ;
V_117 -> V_130 . V_27 = 2 ;
V_117 -> V_130 . V_25 = F_99 ( V_100 / 2 ) ;
V_117 -> V_132 |= V_133 ;
break;
case V_134 :
case V_135 :
V_101 = 1 << ( 12 + ( ( V_118 & V_126 ) >> 9 ) ) ;
V_117 -> V_22 . V_127 = 16 << ( ( V_118 & V_128 ) >> 5 ) ;
V_117 -> V_22 . V_27 = 2 ;
V_117 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_118 & V_129 ) >> 6 ) ) ;
V_117 -> V_130 . V_127 = 16 << ( ( V_118 & V_131 ) >> 4 ) ;
V_117 -> V_130 . V_27 = 2 ;
V_117 -> V_130 . V_25 = 0 ;
V_117 -> V_132 |= V_133 | V_136 ;
break;
case V_137 :
V_101 = 1 << ( 12 + ( ( V_118 & V_126 ) >> 9 ) ) ;
V_117 -> V_22 . V_127 = 16 << ( ( V_118 & V_128 ) >> 5 ) ;
V_117 -> V_22 . V_27 = 4 ;
V_117 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_118 & V_129 ) >> 6 ) ) ;
V_117 -> V_130 . V_127 = 16 << ( ( V_118 & V_131 ) >> 4 ) ;
V_117 -> V_130 . V_27 = 4 ;
V_117 -> V_130 . V_25 = 0 ;
V_117 -> V_132 |= V_133 ;
V_117 -> V_132 |= V_136 ;
break;
case V_138 :
case V_66 :
case V_67 :
case V_139 :
case V_68 :
case V_69 :
case V_140 :
V_101 = 1 << ( 12 + ( ( V_118 & V_126 ) >> 9 ) ) ;
V_117 -> V_22 . V_127 = 16 << ( ( V_118 & V_128 ) >> 5 ) ;
V_117 -> V_22 . V_27 = 1 ;
V_117 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_118 & V_129 ) >> 6 ) ) ;
V_117 -> V_130 . V_127 = 16 << ( ( V_118 & V_131 ) >> 4 ) ;
V_117 -> V_130 . V_27 = 1 ;
V_117 -> V_130 . V_25 = 0 ;
V_117 -> V_132 |= V_133 ;
break;
case V_70 :
case V_71 :
case V_72 :
V_101 = 1 << ( 12 + ( ( V_118 & V_141 ) >> 29 ) ) ;
V_117 -> V_22 . V_127 = 64 ;
V_117 -> V_22 . V_27 = 2 ;
V_117 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_118 & V_142 ) >> 26 ) ) ;
V_117 -> V_130 . V_127 = 32 ;
V_117 -> V_130 . V_27 = 2 ;
V_117 -> V_130 . V_25 = 0 ;
V_117 -> V_132 |= V_136 ;
break;
case V_143 :
F_100 ( V_118 & ~ V_144 ) ;
case V_145 :
if ( V_117 -> V_146 == 0x0c80U || V_117 -> V_146 == 0x0c81U ||
V_117 -> V_146 == 0x0c82U ) {
V_118 |= 0x00400000U ;
if ( V_117 -> V_146 == 0x0c80U )
V_118 |= V_147 ;
F_100 ( V_118 ) ;
} else
V_117 -> V_132 |= V_133 ;
V_101 = 1 << ( 10 + ( ( V_118 & V_126 ) >> 9 ) ) ;
V_117 -> V_22 . V_127 = 16 << ( ( V_118 & V_128 ) >> 5 ) ;
V_117 -> V_22 . V_27 = 2 ;
V_117 -> V_22 . V_25 = F_99 ( V_101 / 2 ) ;
V_100 = 1 << ( 10 + ( ( V_118 & V_129 ) >> 6 ) ) ;
V_117 -> V_130 . V_127 = 16 << ( ( V_118 & V_131 ) >> 4 ) ;
V_117 -> V_130 . V_27 = 2 ;
V_117 -> V_130 . V_25 = F_99 ( V_100 / 2 ) ;
break;
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
V_101 = 1 << ( 10 + ( ( V_118 & V_126 ) >> 9 ) ) ;
V_117 -> V_22 . V_127 = 16 << ( ( V_118 & V_128 ) >> 5 ) ;
V_117 -> V_22 . V_27 = 1 ;
V_117 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 10 + ( ( V_118 & V_129 ) >> 6 ) ) ;
V_117 -> V_130 . V_127 = 16 << ( ( V_118 & V_131 ) >> 4 ) ;
V_117 -> V_130 . V_27 = 1 ;
V_117 -> V_130 . V_25 = 0 ;
V_117 -> V_132 |= V_133 ;
break;
case V_154 :
F_93 () ;
case V_155 :
V_101 = 1 << ( 12 + ( ( V_118 & V_126 ) >> 9 ) ) ;
V_117 -> V_22 . V_127 = 16 << ( ( V_118 & V_128 ) >> 5 ) ;
V_117 -> V_22 . V_27 = 4 ;
V_117 -> V_22 . V_25 = F_99 ( V_101 / V_117 -> V_22 . V_27 ) ;
V_100 = 1 << ( 12 + ( ( V_118 & V_129 ) >> 6 ) ) ;
V_117 -> V_130 . V_127 = 16 << ( ( V_118 & V_131 ) >> 4 ) ;
V_117 -> V_130 . V_27 = 4 ;
V_117 -> V_130 . V_25 = F_99 ( V_100 / V_117 -> V_130 . V_27 ) ;
#if ! F_4 ( V_156 ) || ! F_4 ( V_157 )
V_117 -> V_132 |= V_133 ;
#endif
V_117 -> V_132 |= V_136 ;
break;
case V_158 :
V_101 = 1 << ( 12 + ( ( V_118 & V_126 ) >> 9 ) ) ;
V_117 -> V_22 . V_127 = 16 << ( ( V_118 & V_128 ) >> 5 ) ;
if ( V_119 & 0x3 )
V_117 -> V_22 . V_27 = 4 ;
else
V_117 -> V_22 . V_27 = 2 ;
V_117 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_118 & V_129 ) >> 6 ) ) ;
V_117 -> V_130 . V_127 = 16 << ( ( V_118 & V_131 ) >> 4 ) ;
if ( V_119 & 0x3 )
V_117 -> V_130 . V_27 = 4 ;
else
V_117 -> V_130 . V_27 = 2 ;
V_117 -> V_130 . V_25 = 0 ;
break;
default:
if ( ! ( V_118 & V_159 ) )
F_101 ( L_1 ) ;
V_120 = F_102 () ;
if ( ( V_107 = ( ( V_120 >> 19 ) & 7 ) ) )
V_117 -> V_22 . V_127 = 2 << V_107 ;
else
V_117 -> V_22 . V_127 = V_107 ;
V_117 -> V_22 . V_160 = 32 << ( ( ( V_120 >> 22 ) + 1 ) & 7 ) ;
V_117 -> V_22 . V_27 = 1 + ( ( V_120 >> 16 ) & 7 ) ;
V_101 = V_117 -> V_22 . V_160 *
V_117 -> V_22 . V_27 *
V_117 -> V_22 . V_127 ;
V_117 -> V_22 . V_25 = F_99 ( V_101 / V_117 -> V_22 . V_27 ) ;
if ( V_118 & 0x8 )
V_117 -> V_22 . V_17 |= V_161 ;
V_117 -> V_130 . V_17 = 0 ;
if ( ( V_107 = ( ( V_120 >> 10 ) & 7 ) ) )
V_117 -> V_130 . V_127 = 2 << V_107 ;
else
V_117 -> V_130 . V_127 = V_107 ;
V_117 -> V_130 . V_160 = 32 << ( ( ( V_120 >> 13 ) + 1 ) & 7 ) ;
V_117 -> V_130 . V_27 = 1 + ( ( V_120 >> 7 ) & 7 ) ;
V_100 = V_117 -> V_130 . V_160 *
V_117 -> V_130 . V_27 *
V_117 -> V_130 . V_127 ;
V_117 -> V_130 . V_25 = F_99 ( V_100 / V_117 -> V_130 . V_27 ) ;
V_117 -> V_132 |= V_136 ;
break;
}
if ( ( V_119 & 0xff00 ) == V_162 && ( V_119 & 0xff ) < 0x40 &&
! ( V_118 & V_163 ) && V_117 -> V_22 . V_127 != 16 &&
V_34 <= 0x8000 )
F_101 ( L_2 ) ;
V_117 -> V_22 . V_23 = V_101 / V_117 -> V_22 . V_27 ;
V_117 -> V_130 . V_23 = V_100 / V_117 -> V_130 . V_27 ;
V_117 -> V_22 . V_160 = V_117 -> V_22 . V_127 ?
V_101 / ( V_117 -> V_22 . V_127 * V_117 -> V_22 . V_27 ) : 0 ;
V_117 -> V_130 . V_160 = V_117 -> V_130 . V_127 ?
V_100 / ( V_117 -> V_130 . V_127 * V_117 -> V_130 . V_27 ) : 0 ;
switch ( V_117 -> V_121 ) {
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
V_117 -> V_130 . V_17 |= V_169 ;
break;
case V_70 :
case V_71 :
case V_72 :
break;
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
if ( ( F_103 () & ( 1 << 16 ) ) ) {
V_117 -> V_130 . V_17 |= V_169 ;
break;
}
default:
if ( V_117 -> V_130 . V_23 > V_34 )
V_117 -> V_130 . V_17 |= V_175 ;
}
switch ( V_117 -> V_121 ) {
case V_164 :
V_117 -> V_22 . V_17 |= V_161 ;
break;
case V_176 :
V_117 -> V_22 . V_17 |= V_177 ;
break;
}
#ifdef V_65
V_117 -> V_22 . V_27 = 1 ;
#endif
F_104 ( L_3 ,
V_101 >> 10 ,
V_117 -> V_22 . V_17 & V_161 ? L_4 : L_5 ,
V_178 [ V_117 -> V_22 . V_27 ] , V_117 -> V_22 . V_127 ) ;
F_104 ( L_6 ,
V_100 >> 10 , V_178 [ V_117 -> V_130 . V_27 ] ,
( V_117 -> V_130 . V_17 & V_169 ) ? L_7 : L_5 ,
( V_117 -> V_130 . V_17 & V_175 ) ?
L_8 : L_9 ,
V_117 -> V_130 . V_127 ) ;
}
static int T_1 F_105 ( void )
{
unsigned long V_17 , V_4 , V_179 , V_20 , V_180 ;
unsigned int V_118 = F_97 () ;
struct V_116 * V_117 = & V_21 ;
if ( V_118 & V_163 )
return 0 ;
V_179 = ( unsigned long ) & V_181 ;
V_179 &= ~ ( ( 4 * 1024 * 1024 ) - 1 ) ;
V_20 = V_179 + ( 4 * 1024 * 1024 ) ;
F_17 ( V_17 ) ;
V_180 = ( 64 * 1024 ) ;
for ( V_4 = V_179 ; V_4 < V_20 ; V_4 = ( V_179 + V_180 ) ) {
unsigned long * V_182 = ( unsigned long * ) V_4 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_180 <<= 1 ;
}
F_94 ( 0 ) ;
F_95 ( 0 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
F_79 ( V_183 , V_179 ) ;
F_79 ( V_184 , V_179 ) ;
F_79 ( V_185 , V_179 ) ;
V_180 = ( 128 * 1024 ) ;
for ( V_4 = V_179 + ( 128 * 1024 ) ; V_4 < V_20 ; V_4 = V_179 + V_180 ) {
F_79 ( V_186 , V_4 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
if ( ! F_106 () )
break;
V_180 <<= 1 ;
}
F_19 ( V_17 ) ;
V_4 -= V_179 ;
V_49 = V_4 ;
V_117 -> V_187 . V_127 = 16 << ( ( V_118 & V_188 ) >> 22 ) ;
V_117 -> V_187 . V_27 = 1 ;
V_117 -> V_130 . V_25 = 0 ;
return 1 ;
}
static void T_6 F_107 ( void )
{
struct V_116 * V_117 = & V_21 ;
V_49 = 512 * 1024 ;
V_117 -> V_187 . V_127 = 32 ;
V_117 -> V_187 . V_27 = 4 ;
V_117 -> V_187 . V_25 = 0 ;
V_117 -> V_187 . V_23 = V_49 / ( V_117 -> V_187 . V_27 ) ;
V_117 -> V_187 . V_160 = V_49 / ( V_117 -> V_187 . V_127 * V_117 -> V_187 . V_27 ) ;
F_108 ( L_10 ,
V_49 >> 10 , V_178 [ V_117 -> V_187 . V_27 ] , V_117 -> V_187 . V_127 ) ;
V_117 -> V_132 |= V_189 ;
}
static void T_1 F_109 ( void )
{
struct V_116 * V_117 = & V_21 ;
unsigned int V_118 = F_97 () ;
int V_190 = 0 ;
switch ( V_117 -> V_121 ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_190 = F_110 ( F_105 ) ;
if ( V_190 )
V_117 -> V_132 |= V_191 ;
break;
case V_70 :
case V_71 :
case V_72 :
V_49 = 0x80000 << ( ( V_118 & V_192 ) >> 16 ) ;
V_117 -> V_187 . V_127 = 64 << ( ( V_118 >> 13 ) & 1 ) ;
V_117 -> V_187 . V_27 = 2 ;
V_117 -> V_187 . V_25 = 0 ;
V_190 = 1 ;
break;
case V_124 :
case V_125 :
#ifdef F_111
F_112 () ;
#endif
return;
case V_154 :
case V_155 :
#ifdef F_113
F_114 () ;
#endif
return;
#if F_4 ( V_65 )
case V_158 :
F_107 () ;
return;
#endif
case V_193 :
return;
default:
if ( V_117 -> V_194 == V_195 ||
V_117 -> V_194 == V_196 ||
V_117 -> V_194 == V_197 ||
V_117 -> V_194 == V_198 ) {
#ifdef F_115
if ( F_116 () ) {
V_49 = V_117 -> V_187 . V_27 * V_117 -> V_187 . V_160 * V_117 -> V_187 . V_127 ;
F_104 ( L_11 ,
V_49 >> 10 ,
V_178 [ V_117 -> V_187 . V_27 ] , V_117 -> V_187 . V_127 ) ;
}
#else
if ( ! ( V_117 -> V_187 . V_17 & V_199 ) )
F_101 ( L_12 ) ;
#endif
return;
}
V_190 = 0 ;
}
if ( ! V_190 )
return;
V_117 -> V_187 . V_23 = V_49 / V_117 -> V_187 . V_27 ;
V_117 -> V_187 . V_160 = V_49 / ( V_117 -> V_187 . V_127 * V_117 -> V_187 . V_27 ) ;
F_104 ( L_10 ,
V_49 >> 10 , V_178 [ V_117 -> V_187 . V_27 ] , V_117 -> V_187 . V_127 ) ;
V_117 -> V_132 |= V_189 ;
}
void F_117 ( void )
{
switch ( F_98 () ) {
case 0x00030100 :
case 0x00030201 :
case 0x00030202 :
case 0x01030200 :
case 0x02030200 :
case 0x02030201 :
case 0x02030202 :
F_118 ( 1 << 19 ) ;
break;
}
}
static void F_119 ( void )
{
unsigned long V_200 ;
V_200 = F_97 () ;
V_200 &= ~ ( 0x7 | ( 7 << 25 ) | ( 7 << 28 ) ) ;
V_200 |= ( ( ( V_201 >> V_202 ) << 0 ) |
( ( V_201 >> V_202 ) << 25 ) |
( ( V_201 >> V_202 ) << 28 ) ) ;
F_100 ( V_200 ) ;
F_120 () ;
}
static int T_6 F_121 ( char * V_203 )
{
F_122 ( & V_203 , & V_204 ) ;
return 1 ;
}
static void T_1 F_123 ( void )
{
if ( V_204 < 0 || V_204 > 7 )
V_204 = F_97 () & V_205 ;
V_201 = V_204 << V_202 ;
F_124 ( L_13 , V_204 ) ;
F_125 ( V_205 , V_204 ) ;
switch ( F_35 () ) {
case V_138 :
case V_66 :
case V_67 :
case V_139 :
case V_68 :
case V_69 :
F_126 ( V_206 ) ;
break;
case V_176 :
F_117 () ;
break;
case V_207 :
F_119 () ;
break;
}
}
static int T_6 F_127 ( char * V_203 )
{
V_208 = 1 ;
return 1 ;
}
static void T_1 F_128 ( void )
{
extern char __weak V_209 ;
extern char __weak V_210 ;
struct V_116 * V_117 = & V_21 ;
switch ( V_117 -> V_121 ) {
case V_166 :
case V_167 :
F_129 ( 0x100 , & V_210 , 0x80 ) ;
break;
default:
F_129 ( 0x100 , & V_209 , 0x80 ) ;
break;
}
}
void T_1 F_130 ( void )
{
extern void V_211 ( void ) ;
extern void V_212 ( void ) ;
struct V_116 * V_117 = & V_21 ;
F_96 () ;
F_109 () ;
F_12 () ;
F_14 () ;
F_15 () ;
F_25 () ;
F_27 () ;
F_29 () ;
F_30 () ;
F_32 () ;
F_33 () ;
if ( V_117 -> V_130 . V_127 )
V_213 = F_131 ( unsigned long,
c->dcache.sets * c->dcache.linesz - 1 ,
PAGE_SIZE - 1 ) ;
else
V_213 = V_34 - 1 ;
V_214 = F_41 ;
V_215 = F_42 ;
V_216 = F_7 ;
V_217 = F_36 ;
V_218 = F_46 ;
V_219 = F_62 ;
V_220 = F_44 ;
V_221 = F_92 ;
V_222 = F_89 ;
V_223 = F_90 ;
V_224 = F_63 ;
V_225 = F_64 ;
V_226 = F_70 ;
V_227 = F_66 ;
#if F_4 ( V_228 )
if ( V_208 ) {
V_229 = ( void * ) F_7 ;
V_230 = ( void * ) F_7 ;
V_231 = ( void * ) F_7 ;
} else {
V_229 = F_72 ;
V_230 = F_72 ;
V_231 = F_78 ;
}
#endif
V_211 () ;
V_212 () ;
#if ! F_4 ( V_232 )
F_34 ( NULL ) ;
#endif
F_123 () ;
V_233 = F_128 ;
}
