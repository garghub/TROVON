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
static void F_12 ( void )
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
static void F_14 ( void )
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
static void F_15 ( void )
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
static void F_25 ( void )
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
static void F_27 ( void )
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
static void F_29 ( void )
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
static void F_30 ( void )
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
static void F_32 ( void )
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
static void F_33 ( void )
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
T_1 * V_88 ;
T_2 * V_89 ;
T_3 * V_90 ;
T_4 * V_91 ;
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
F_3 () ;
if ( V_105 ) {
if ( V_104 >= V_49 )
V_60 () ;
else
F_74 ( V_4 , V_4 + V_104 ) ;
F_6 () ;
F_75 () ;
return;
}
if ( V_106 && V_104 >= V_100 ) {
V_13 () ;
} else {
V_5 ;
F_76 ( V_4 , V_4 + V_104 ) ;
}
F_6 () ;
F_77 ( V_4 , V_104 ) ;
F_75 () ;
}
static void F_78 ( unsigned long V_4 , unsigned long V_104 )
{
F_73 ( V_104 == 0 ) ;
F_3 () ;
if ( V_105 ) {
if ( V_104 >= V_49 )
V_60 () ;
else {
F_79 ( V_4 , V_4 + V_104 ) ;
}
F_6 () ;
F_75 () ;
return;
}
if ( V_106 && V_104 >= V_100 ) {
V_13 () ;
} else {
V_5 ;
F_80 ( V_4 , V_4 + V_104 ) ;
}
F_6 () ;
F_81 ( V_4 , V_104 ) ;
F_75 () ;
}
static void F_82 ( void * V_107 )
{
unsigned long V_35 = F_26 () ;
unsigned long V_6 = F_13 () ;
unsigned long V_48 = F_31 () ;
unsigned long V_4 = ( unsigned long ) V_107 ;
V_5 ;
if ( V_6 )
F_83 ( V_4 & ~ ( V_6 - 1 ) ) ;
if ( ! V_97 && V_49 )
F_84 ( V_4 & ~ ( V_48 - 1 ) ) ;
if ( V_35 )
F_85 ( V_4 & ~ ( V_35 - 1 ) ) ;
if ( V_108 ) {
__asm__ __volatile__ (
".set push\n\t"
".set noat\n\t"
".set mips3\n\t"
#ifdef F_86
"la $at,1f\n\t"
#endif
#ifdef F_87
"dla $at,1f\n\t"
#endif
"cache %0,($at)\n\t"
"nop; nop; nop\n"
"1:\n\t"
".set pop"
:
: "i" (Hit_Invalidate_I));
}
if ( V_109 )
__asm__ __volatile__ ("sync");
}
static void F_88 ( unsigned long V_4 )
{
F_1 ( F_82 , ( void * ) V_4 ) ;
}
static void F_89 ( void )
{
if ( V_98 )
V_45 () ;
}
static inline void F_90 ( void * args )
{
struct V_110 * V_111 = args ;
unsigned long V_92 = V_111 -> V_92 ;
int V_104 = V_111 -> V_104 ;
if ( V_106 && V_104 >= V_100 )
V_13 () ;
else {
V_5 ;
F_76 ( V_92 , V_92 + V_104 ) ;
}
}
static void F_91 ( unsigned long V_92 , int V_104 )
{
struct V_110 args ;
args . V_92 = ( unsigned long ) V_92 ;
args . V_104 = V_104 ;
F_1 ( F_90 , & args ) ;
}
static inline void F_92 ( void )
{
const unsigned long V_35 = 32 ;
unsigned long V_4 ;
F_93 ( 0 ) ;
F_94 ( 0 ) ;
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
static inline void F_95 ( struct V_112 * V_113 )
{
unsigned int V_114 = V_113 -> V_115 & V_116 ;
unsigned int V_117 = V_113 -> V_115 & V_118 ;
switch ( V_114 ) {
case V_119 :
if ( V_117 <= F_96 ( 2 , 4 , 0 ) )
V_113 -> V_120 . V_17 |= V_121 ;
if ( V_117 == F_96 ( 2 , 4 , 0 ) )
F_97 ( F_98 () | V_122 ) ;
break;
case V_123 :
if ( V_117 <= F_96 ( 1 , 1 , 0 ) ) {
V_113 -> V_120 . V_17 |= V_121 ;
F_97 ( F_98 () | V_122 ) ;
}
break;
default:
F_99 () ;
}
}
static void F_100 ( void )
{
struct V_112 * V_113 = & V_21 ;
unsigned int V_124 = F_101 () ;
unsigned int V_125 = F_102 () ;
unsigned long V_126 ;
unsigned int V_127 ;
switch ( F_35 () ) {
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_101 = 1 << ( 12 + ( ( V_124 & V_132 ) >> 9 ) ) ;
V_113 -> V_22 . V_133 = 16 << ( ( V_124 & V_134 ) >> 5 ) ;
V_113 -> V_22 . V_27 = 2 ;
V_113 -> V_22 . V_25 = F_103 ( V_101 / 2 ) ;
V_100 = 1 << ( 12 + ( ( V_124 & V_135 ) >> 6 ) ) ;
V_113 -> V_120 . V_133 = 16 << ( ( V_124 & V_136 ) >> 4 ) ;
V_113 -> V_120 . V_27 = 2 ;
V_113 -> V_120 . V_25 = F_103 ( V_100 / 2 ) ;
V_113 -> V_137 |= V_138 ;
break;
case V_139 :
case V_140 :
V_101 = 1 << ( 12 + ( ( V_124 & V_132 ) >> 9 ) ) ;
V_113 -> V_22 . V_133 = 16 << ( ( V_124 & V_134 ) >> 5 ) ;
V_113 -> V_22 . V_27 = 2 ;
V_113 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_124 & V_135 ) >> 6 ) ) ;
V_113 -> V_120 . V_133 = 16 << ( ( V_124 & V_136 ) >> 4 ) ;
V_113 -> V_120 . V_27 = 2 ;
V_113 -> V_120 . V_25 = 0 ;
V_113 -> V_137 |= V_138 | V_141 ;
break;
case V_142 :
V_101 = 1 << ( 12 + ( ( V_124 & V_132 ) >> 9 ) ) ;
V_113 -> V_22 . V_133 = 16 << ( ( V_124 & V_134 ) >> 5 ) ;
V_113 -> V_22 . V_27 = 4 ;
V_113 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_124 & V_135 ) >> 6 ) ) ;
V_113 -> V_120 . V_133 = 16 << ( ( V_124 & V_136 ) >> 4 ) ;
V_113 -> V_120 . V_27 = 4 ;
V_113 -> V_120 . V_25 = 0 ;
V_113 -> V_137 |= V_138 ;
V_113 -> V_137 |= V_141 ;
break;
case V_143 :
case V_66 :
case V_67 :
case V_144 :
case V_68 :
case V_69 :
case V_145 :
V_101 = 1 << ( 12 + ( ( V_124 & V_132 ) >> 9 ) ) ;
V_113 -> V_22 . V_133 = 16 << ( ( V_124 & V_134 ) >> 5 ) ;
V_113 -> V_22 . V_27 = 1 ;
V_113 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_124 & V_135 ) >> 6 ) ) ;
V_113 -> V_120 . V_133 = 16 << ( ( V_124 & V_136 ) >> 4 ) ;
V_113 -> V_120 . V_27 = 1 ;
V_113 -> V_120 . V_25 = 0 ;
V_113 -> V_137 |= V_138 ;
break;
case V_70 :
case V_71 :
case V_72 :
V_101 = 1 << ( 12 + ( ( V_124 & V_146 ) >> 29 ) ) ;
V_113 -> V_22 . V_133 = 64 ;
V_113 -> V_22 . V_27 = 2 ;
V_113 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_124 & V_147 ) >> 26 ) ) ;
V_113 -> V_120 . V_133 = 32 ;
V_113 -> V_120 . V_27 = 2 ;
V_113 -> V_120 . V_25 = 0 ;
V_113 -> V_137 |= V_141 ;
break;
case V_148 :
F_104 ( V_124 & ~ V_149 ) ;
case V_150 :
if ( V_113 -> V_115 == 0x0c80U || V_113 -> V_115 == 0x0c81U ||
V_113 -> V_115 == 0x0c82U ) {
V_124 |= 0x00400000U ;
if ( V_113 -> V_115 == 0x0c80U )
V_124 |= V_151 ;
F_104 ( V_124 ) ;
} else
V_113 -> V_137 |= V_138 ;
V_101 = 1 << ( 10 + ( ( V_124 & V_132 ) >> 9 ) ) ;
V_113 -> V_22 . V_133 = 16 << ( ( V_124 & V_134 ) >> 5 ) ;
V_113 -> V_22 . V_27 = 2 ;
V_113 -> V_22 . V_25 = F_103 ( V_101 / 2 ) ;
V_100 = 1 << ( 10 + ( ( V_124 & V_135 ) >> 6 ) ) ;
V_113 -> V_120 . V_133 = 16 << ( ( V_124 & V_136 ) >> 4 ) ;
V_113 -> V_120 . V_27 = 2 ;
V_113 -> V_120 . V_25 = F_103 ( V_100 / 2 ) ;
break;
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
V_101 = 1 << ( 10 + ( ( V_124 & V_132 ) >> 9 ) ) ;
V_113 -> V_22 . V_133 = 16 << ( ( V_124 & V_134 ) >> 5 ) ;
V_113 -> V_22 . V_27 = 1 ;
V_113 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 10 + ( ( V_124 & V_135 ) >> 6 ) ) ;
V_113 -> V_120 . V_133 = 16 << ( ( V_124 & V_136 ) >> 4 ) ;
V_113 -> V_120 . V_27 = 1 ;
V_113 -> V_120 . V_25 = 0 ;
V_113 -> V_137 |= V_138 ;
break;
case V_158 :
F_92 () ;
V_101 = 1 << ( 12 + ( ( V_124 & V_132 ) >> 9 ) ) ;
V_113 -> V_22 . V_133 = 16 << ( ( V_124 & V_134 ) >> 5 ) ;
V_113 -> V_22 . V_27 = 4 ;
V_113 -> V_22 . V_25 = F_103 ( V_101 / V_113 -> V_22 . V_27 ) ;
V_100 = 1 << ( 12 + ( ( V_124 & V_135 ) >> 6 ) ) ;
V_113 -> V_120 . V_133 = 16 << ( ( V_124 & V_136 ) >> 4 ) ;
V_113 -> V_120 . V_27 = 4 ;
V_113 -> V_120 . V_25 = F_103 ( V_100 / V_113 -> V_120 . V_27 ) ;
V_113 -> V_137 |= V_138 ;
V_113 -> V_137 |= V_141 ;
break;
case V_159 :
V_101 = 1 << ( 12 + ( ( V_124 & V_132 ) >> 9 ) ) ;
V_113 -> V_22 . V_133 = 16 << ( ( V_124 & V_134 ) >> 5 ) ;
if ( V_125 & 0x3 )
V_113 -> V_22 . V_27 = 4 ;
else
V_113 -> V_22 . V_27 = 2 ;
V_113 -> V_22 . V_25 = 0 ;
V_100 = 1 << ( 12 + ( ( V_124 & V_135 ) >> 6 ) ) ;
V_113 -> V_120 . V_133 = 16 << ( ( V_124 & V_136 ) >> 4 ) ;
if ( V_125 & 0x3 )
V_113 -> V_120 . V_27 = 4 ;
else
V_113 -> V_120 . V_27 = 2 ;
V_113 -> V_120 . V_25 = 0 ;
break;
default:
if ( ! ( V_124 & V_160 ) )
F_105 ( L_1 ) ;
V_126 = F_106 () ;
if ( ( V_127 = ( ( V_126 >> 19 ) & 7 ) ) )
V_113 -> V_22 . V_133 = 2 << V_127 ;
else
V_113 -> V_22 . V_133 = V_127 ;
V_113 -> V_22 . V_161 = 32 << ( ( ( V_126 >> 22 ) + 1 ) & 7 ) ;
V_113 -> V_22 . V_27 = 1 + ( ( V_126 >> 16 ) & 7 ) ;
V_101 = V_113 -> V_22 . V_161 *
V_113 -> V_22 . V_27 *
V_113 -> V_22 . V_133 ;
V_113 -> V_22 . V_25 = F_103 ( V_101 / V_113 -> V_22 . V_27 ) ;
if ( V_124 & 0x8 )
V_113 -> V_22 . V_17 |= V_121 ;
V_113 -> V_120 . V_17 = 0 ;
if ( ( V_127 = ( ( V_126 >> 10 ) & 7 ) ) )
V_113 -> V_120 . V_133 = 2 << V_127 ;
else
V_113 -> V_120 . V_133 = V_127 ;
V_113 -> V_120 . V_161 = 32 << ( ( ( V_126 >> 13 ) + 1 ) & 7 ) ;
V_113 -> V_120 . V_27 = 1 + ( ( V_126 >> 7 ) & 7 ) ;
V_100 = V_113 -> V_120 . V_161 *
V_113 -> V_120 . V_27 *
V_113 -> V_120 . V_133 ;
V_113 -> V_120 . V_25 = F_103 ( V_100 / V_113 -> V_120 . V_27 ) ;
V_113 -> V_137 |= V_141 ;
break;
}
if ( ( V_125 & V_116 ) == V_162 &&
( V_125 & V_118 ) < V_163 &&
! ( V_124 & V_164 ) && V_113 -> V_22 . V_133 != 16 &&
V_34 <= 0x8000 )
F_105 ( L_2 ) ;
V_113 -> V_22 . V_23 = V_101 / V_113 -> V_22 . V_27 ;
V_113 -> V_120 . V_23 = V_100 / V_113 -> V_120 . V_27 ;
V_113 -> V_22 . V_161 = V_113 -> V_22 . V_133 ?
V_101 / ( V_113 -> V_22 . V_133 * V_113 -> V_22 . V_27 ) : 0 ;
V_113 -> V_120 . V_161 = V_113 -> V_120 . V_133 ?
V_100 / ( V_113 -> V_120 . V_133 * V_113 -> V_120 . V_27 ) : 0 ;
switch ( F_35 () ) {
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
V_113 -> V_120 . V_17 |= V_170 ;
break;
case V_70 :
case V_71 :
case V_72 :
break;
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
if ( F_35 () == V_175 )
F_95 ( V_113 ) ;
if ( ( F_107 () & ( 1 << 16 ) ) ) {
V_113 -> V_120 . V_17 |= V_170 ;
break;
}
default:
if ( V_113 -> V_120 . V_23 > V_34 )
V_113 -> V_120 . V_17 |= V_177 ;
}
switch ( F_35 () ) {
case V_165 :
V_113 -> V_22 . V_17 |= V_121 ;
break;
case V_178 :
V_113 -> V_22 . V_17 |= V_179 ;
break;
}
#ifdef V_65
V_113 -> V_22 . V_27 = 1 ;
#endif
F_108 ( L_3 ,
V_101 >> 10 ,
V_113 -> V_22 . V_17 & V_121 ? L_4 : L_5 ,
V_180 [ V_113 -> V_22 . V_27 ] , V_113 -> V_22 . V_133 ) ;
F_108 ( L_6 ,
V_100 >> 10 , V_180 [ V_113 -> V_120 . V_27 ] ,
( V_113 -> V_120 . V_17 & V_170 ) ? L_7 : L_5 ,
( V_113 -> V_120 . V_17 & V_177 ) ?
L_8 : L_9 ,
V_113 -> V_120 . V_133 ) ;
}
static int F_109 ( void )
{
unsigned long V_17 , V_4 , V_181 , V_20 , V_182 ;
unsigned int V_124 = F_101 () ;
struct V_112 * V_113 = & V_21 ;
if ( V_124 & V_164 )
return 0 ;
V_181 = ( unsigned long ) & V_183 ;
V_181 &= ~ ( ( 4 * 1024 * 1024 ) - 1 ) ;
V_20 = V_181 + ( 4 * 1024 * 1024 ) ;
F_17 ( V_17 ) ;
V_182 = ( 64 * 1024 ) ;
for ( V_4 = V_181 ; V_4 < V_20 ; V_4 = ( V_181 + V_182 ) ) {
unsigned long * V_184 = ( unsigned long * ) V_4 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_182 <<= 1 ;
}
F_93 ( 0 ) ;
F_94 ( 0 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
F_110 ( V_185 , V_181 ) ;
F_110 ( V_186 , V_181 ) ;
F_110 ( V_187 , V_181 ) ;
V_182 = ( 128 * 1024 ) ;
for ( V_4 = V_181 + ( 128 * 1024 ) ; V_4 < V_20 ; V_4 = V_181 + V_182 ) {
F_110 ( V_188 , V_4 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
if ( ! F_111 () )
break;
V_182 <<= 1 ;
}
F_19 ( V_17 ) ;
V_4 -= V_181 ;
V_49 = V_4 ;
V_113 -> V_189 . V_133 = 16 << ( ( V_124 & V_190 ) >> 22 ) ;
V_113 -> V_189 . V_27 = 1 ;
V_113 -> V_120 . V_25 = 0 ;
return 1 ;
}
static void T_5 F_112 ( void )
{
struct V_112 * V_113 = & V_21 ;
V_49 = 512 * 1024 ;
V_113 -> V_189 . V_133 = 32 ;
V_113 -> V_189 . V_27 = 4 ;
V_113 -> V_189 . V_25 = 0 ;
V_113 -> V_189 . V_23 = V_49 / ( V_113 -> V_189 . V_27 ) ;
V_113 -> V_189 . V_161 = V_49 / ( V_113 -> V_189 . V_133 * V_113 -> V_189 . V_27 ) ;
F_113 ( L_10 ,
V_49 >> 10 , V_180 [ V_113 -> V_189 . V_27 ] , V_113 -> V_189 . V_133 ) ;
V_113 -> V_137 |= V_191 ;
}
static void F_114 ( void )
{
struct V_112 * V_113 = & V_21 ;
unsigned int V_124 = F_101 () ;
int V_192 = 0 ;
switch ( F_35 () ) {
case V_66 :
case V_67 :
case V_68 :
case V_69 :
V_192 = F_115 ( F_109 ) ;
if ( V_192 )
V_113 -> V_137 |= V_193 ;
break;
case V_70 :
case V_71 :
case V_72 :
V_49 = 0x80000 << ( ( V_124 & V_194 ) >> 16 ) ;
V_113 -> V_189 . V_133 = 64 << ( ( V_124 >> 13 ) & 1 ) ;
V_113 -> V_189 . V_27 = 2 ;
V_113 -> V_189 . V_25 = 0 ;
V_192 = 1 ;
break;
case V_130 :
case V_131 :
#ifdef F_116
F_117 () ;
#endif
return;
case V_158 :
#ifdef F_118
F_119 () ;
#endif
return;
#if F_4 ( V_65 )
case V_159 :
F_112 () ;
return;
#endif
case V_195 :
return;
default:
if ( V_113 -> V_196 & ( V_197 | V_198 |
V_199 | V_200 ) ) {
#ifdef F_120
if ( F_121 () ) {
V_49 = V_113 -> V_189 . V_27 * V_113 -> V_189 . V_161 * V_113 -> V_189 . V_133 ;
F_108 ( L_11 ,
V_49 >> 10 ,
V_180 [ V_113 -> V_189 . V_27 ] , V_113 -> V_189 . V_133 ) ;
}
#else
if ( ! ( V_113 -> V_189 . V_17 & V_201 ) )
F_105 ( L_12 ) ;
#endif
return;
}
V_192 = 0 ;
}
if ( ! V_192 )
return;
V_113 -> V_189 . V_23 = V_49 / V_113 -> V_189 . V_27 ;
V_113 -> V_189 . V_161 = V_49 / ( V_113 -> V_189 . V_133 * V_113 -> V_189 . V_27 ) ;
F_108 ( L_10 ,
V_49 >> 10 , V_180 [ V_113 -> V_189 . V_27 ] , V_113 -> V_189 . V_133 ) ;
V_113 -> V_137 |= V_191 ;
}
void F_122 ( void )
{
switch ( F_102 () ) {
case 0x00030100 :
case 0x00030201 :
case 0x00030202 :
case 0x01030200 :
case 0x02030200 :
case 0x02030201 :
case 0x02030202 :
F_123 ( 1 << 19 ) ;
break;
}
}
static void F_124 ( void )
{
unsigned long V_202 ;
V_202 = F_101 () ;
V_202 &= ~ ( 0x7 | ( 7 << 25 ) | ( 7 << 28 ) ) ;
V_202 |= ( ( ( V_203 >> V_204 ) << 0 ) |
( ( V_203 >> V_204 ) << 25 ) |
( ( V_203 >> V_204 ) << 28 ) ) ;
F_104 ( V_202 ) ;
F_125 () ;
}
static int T_5 F_126 ( char * V_205 )
{
F_127 ( & V_205 , & V_206 ) ;
return 0 ;
}
static void F_128 ( void )
{
if ( V_206 < 0 || V_206 > 7 )
V_206 = F_101 () & V_207 ;
V_203 = V_206 << V_204 ;
F_129 ( L_13 , V_206 ) ;
F_130 ( V_207 , V_206 ) ;
switch ( F_35 () ) {
case V_143 :
case V_66 :
case V_67 :
case V_144 :
case V_68 :
case V_69 :
F_131 ( V_208 ) ;
break;
case V_178 :
F_122 () ;
break;
case V_209 :
F_124 () ;
break;
}
}
static void F_132 ( void )
{
extern char __weak V_210 ;
extern char __weak V_211 ;
switch ( F_35 () ) {
case V_167 :
case V_168 :
F_133 ( 0x100 , & V_211 , 0x80 ) ;
break;
default:
F_133 ( 0x100 , & V_210 , 0x80 ) ;
break;
}
}
void F_134 ( void )
{
extern void V_212 ( void ) ;
extern void V_213 ( void ) ;
struct V_112 * V_113 = & V_21 ;
F_100 () ;
F_114 () ;
F_12 () ;
F_14 () ;
F_15 () ;
F_25 () ;
F_27 () ;
F_29 () ;
F_30 () ;
F_32 () ;
F_33 () ;
if ( V_113 -> V_120 . V_133 )
V_214 = F_135 ( unsigned long,
c->dcache.sets * c->dcache.linesz - 1 ,
PAGE_SIZE - 1 ) ;
else
V_214 = V_34 - 1 ;
V_215 = F_41 ;
V_216 = F_42 ;
V_217 = F_7 ;
V_218 = F_36 ;
V_219 = F_46 ;
V_220 = F_62 ;
V_221 = F_44 ;
V_222 = F_91 ;
V_223 = F_88 ;
V_224 = F_89 ;
V_225 = F_63 ;
V_226 = F_64 ;
V_227 = F_70 ;
V_228 = F_66 ;
#if F_4 ( V_229 )
if ( V_230 ) {
V_231 = ( void * ) F_7 ;
V_232 = ( void * ) F_7 ;
V_233 = ( void * ) F_7 ;
} else {
V_231 = F_72 ;
V_232 = F_72 ;
V_233 = F_78 ;
}
#endif
V_212 () ;
V_213 () ;
F_34 ( NULL ) ;
F_128 () ;
V_234 = F_132 ;
}
