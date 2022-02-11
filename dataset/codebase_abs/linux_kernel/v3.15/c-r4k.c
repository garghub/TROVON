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
static void F_16 ( void )
{
unsigned long V_6 = F_13 () ;
if ( V_6 == 0 )
V_17 = ( void * ) F_7 ;
else if ( V_6 == 16 )
V_17 = V_18 ;
else if ( V_6 == 32 )
V_17 = V_19 ;
else if ( V_6 == 64 )
V_17 = V_20 ;
}
static inline void F_17 ( void )
{
unsigned long V_21 ;
F_18 ( V_21 ) ;
F_19 () ;
F_20 ( V_21 ) ;
}
static inline void F_21 ( void )
{
unsigned long V_22 = V_23 ;
unsigned long V_24 = V_22 + V_25 . V_26 . V_27 ;
unsigned long V_28 = 1UL << V_25 . V_26 . V_29 ;
unsigned long V_30 = V_25 . V_26 . V_31 <<
V_25 . V_26 . V_29 ;
unsigned long V_32 , V_4 ;
V_33 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 += V_28 )
for ( V_4 = V_22 + 0x400 ; V_4 < V_24 ; V_4 += 0x400 * 2 )
F_22 ( V_4 | V_32 , V_34 ) ;
V_35 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 += V_28 )
for ( V_4 = V_22 ; V_4 < V_24 ; V_4 += 0x400 * 2 )
F_22 ( V_4 | V_32 , V_34 ) ;
}
static inline void F_23 ( unsigned long V_36 )
{
unsigned long V_21 ;
F_18 ( V_21 ) ;
F_24 ( V_36 ) ;
F_20 ( V_21 ) ;
}
static inline void F_25 ( unsigned long V_36 )
{
unsigned long V_37 = V_25 . V_26 . V_27 - 1 ;
unsigned long V_22 = V_23 + ( V_36 & V_37 ) ;
unsigned long V_24 = V_22 + V_38 ;
unsigned long V_28 = 1UL << V_25 . V_26 . V_29 ;
unsigned long V_30 = V_25 . V_26 . V_31 <<
V_25 . V_26 . V_29 ;
unsigned long V_32 , V_4 ;
V_33 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 += V_28 )
for ( V_4 = V_22 + 0x400 ; V_4 < V_24 ; V_4 += 0x400 * 2 )
F_22 ( V_4 | V_32 , V_34 ) ;
V_35 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 += V_28 )
for ( V_4 = V_22 ; V_4 < V_24 ; V_4 += 0x400 * 2 )
F_22 ( V_4 | V_32 , V_34 ) ;
}
static void F_26 ( void )
{
unsigned long V_39 = F_27 () ;
if ( V_39 == 0 )
V_40 = ( void * ) F_7 ;
else if ( V_39 == 16 )
V_40 = V_41 ;
else if ( V_39 == 32 && F_28 () == V_42 )
V_40 = V_43 ;
else if ( V_39 == 32 )
V_40 = V_44 ;
else if ( V_39 == 64 )
V_40 = V_45 ;
}
static void T_1 F_29 ( void )
{
unsigned long V_39 = F_27 () ;
if ( V_39 == 0 )
V_46 = ( void * ) F_7 ;
else if ( V_39 == 16 )
V_46 = V_47 ;
else if ( V_39 == 32 )
V_46 = V_48 ;
else if ( V_39 == 64 )
V_46 = V_49 ;
}
static void F_30 ( void )
{
unsigned long V_39 = F_27 () ;
if ( V_39 == 0 )
V_50 = ( void * ) F_7 ;
else if ( V_39 == 16 )
V_50 = V_51 ;
else if ( V_39 == 32 ) {
if ( V_52 && F_31 () )
V_50 =
F_23 ;
else if ( V_53 )
V_50 =
F_25 ;
else if ( F_28 () == V_42 )
V_50 =
V_54 ;
else
V_50 =
F_24 ;
} else if ( V_39 == 64 )
V_50 = V_55 ;
}
static void F_32 ( void )
{
unsigned long V_39 = F_27 () ;
if ( V_39 == 0 )
V_56 = ( void * ) F_7 ;
else if ( V_39 == 16 )
V_56 = V_57 ;
else if ( V_39 == 32 ) {
if ( V_52 && F_31 () )
V_56 = F_17 ;
else if ( V_53 )
V_56 = F_21 ;
else if ( F_28 () == V_42 )
V_56 = V_58 ;
else
V_56 = F_19 ;
} else if ( V_39 == 64 )
V_56 = V_59 ;
}
static void F_33 ( void )
{
unsigned long V_60 = F_34 () ;
if ( V_61 == 0 )
V_62 = ( void * ) F_7 ;
else if ( V_60 == 16 )
V_62 = V_63 ;
else if ( V_60 == 32 )
V_62 = V_64 ;
else if ( V_60 == 64 )
V_62 = V_65 ;
else if ( V_60 == 128 )
V_62 = V_66 ;
}
static void F_35 ( void )
{
unsigned long V_60 = F_34 () ;
if ( V_61 == 0 )
V_67 = ( void * ) F_7 ;
else if ( V_60 == 16 )
V_67 = V_68 ;
else if ( V_60 == 32 )
V_67 = V_69 ;
else if ( V_60 == 64 )
V_67 = V_70 ;
else if ( V_60 == 128 )
V_67 = V_71 ;
}
static void F_36 ( void )
{
unsigned long V_60 = F_34 () ;
if ( V_61 == 0 )
V_72 = ( void * ) F_7 ;
else if ( V_60 == 16 )
V_72 = V_73 ;
else if ( V_60 == 32 )
V_72 = V_74 ;
else if ( V_60 == 64 )
V_72 = V_75 ;
else if ( V_60 == 128 )
V_72 = V_76 ;
}
static inline void F_37 ( void * args )
{
switch ( F_28 () ) {
case V_42 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
V_72 () ;
break;
default:
V_17 () ;
V_56 () ;
break;
}
}
static void F_38 ( void )
{
F_1 ( F_37 , NULL ) ;
}
static inline int F_39 ( const struct V_85 * V_86 )
{
#if F_4 ( V_2 ) || F_4 ( V_3 )
int V_87 ;
F_40 (i)
if ( F_41 ( V_87 , V_86 ) )
return 1 ;
return 0 ;
#else
return F_41 ( F_42 () , V_86 ) ;
#endif
}
static void F_43 ( void )
{
V_17 () ;
}
static void F_44 ( void )
{
V_17 () ;
}
static inline void F_45 ( void * args )
{
struct V_88 * V_89 = args ;
int V_90 = V_89 -> V_91 & V_92 ;
if ( ! ( F_39 ( V_89 -> V_93 ) ) )
return;
V_17 () ;
if ( V_90 )
V_56 () ;
}
static void F_46 ( struct V_88 * V_89 ,
unsigned long V_22 , unsigned long V_24 )
{
int V_90 = V_89 -> V_91 & V_92 ;
if ( V_94 || ( V_90 && ! V_95 ) )
F_1 ( F_45 , V_89 ) ;
}
static inline void F_47 ( void * args )
{
struct V_85 * V_86 = args ;
if ( ! F_39 ( V_86 ) )
return;
if ( F_28 () == V_78 ||
F_28 () == V_79 ||
F_28 () == V_80 ||
F_28 () == V_81 ) {
V_72 () ;
return;
}
V_17 () ;
}
static void F_48 ( struct V_85 * V_86 )
{
if ( ! V_94 )
return;
F_1 ( F_47 , V_86 ) ;
}
static inline void F_49 ( void * args )
{
struct V_96 * V_97 = args ;
struct V_88 * V_89 = V_97 -> V_89 ;
unsigned long V_4 = V_97 -> V_4 ;
struct V_36 * V_36 = F_50 ( V_97 -> V_98 ) ;
int V_90 = V_89 -> V_91 & V_92 ;
struct V_85 * V_86 = V_89 -> V_93 ;
int V_99 = 0 ;
T_2 * V_100 ;
T_3 * V_101 ;
T_4 * V_102 ;
T_5 * V_103 ;
void * V_104 ;
if ( ! F_39 ( V_86 ) )
return;
V_4 &= V_105 ;
V_100 = F_51 ( V_86 , V_4 ) ;
V_101 = F_52 ( V_100 , V_4 ) ;
V_102 = F_53 ( V_101 , V_4 ) ;
V_103 = F_54 ( V_102 , V_4 ) ;
if ( ! ( F_55 ( * V_103 ) ) )
return;
if ( ( V_86 == V_106 -> V_107 ) && ( F_56 ( * V_103 ) & V_108 ) )
V_104 = NULL ;
else {
V_99 = ( V_94 &&
F_57 ( V_36 ) && ! F_58 ( V_36 ) ) ;
if ( V_99 )
V_104 = F_59 ( V_36 , V_4 ) ;
else
V_104 = F_60 ( V_36 ) ;
V_4 = ( unsigned long ) V_104 ;
}
if ( V_94 || ( V_90 && ! V_95 ) ) {
V_104 ? V_7 ( V_4 ) :
V_9 ( V_4 ) ;
if ( V_90 && ! V_109 )
V_62 ( V_4 ) ;
}
if ( V_90 ) {
if ( V_104 && V_110 && V_86 == V_106 -> V_107 ) {
int V_111 = F_42 () ;
if ( F_41 ( V_111 , V_86 ) != 0 )
F_61 ( V_86 , V_111 ) ;
} else
V_104 ? V_40 ( V_4 ) :
V_46 ( V_4 ) ;
}
if ( V_104 ) {
if ( V_99 )
F_62 () ;
else
F_63 ( V_104 ) ;
}
}
static void F_64 ( struct V_88 * V_89 ,
unsigned long V_4 , unsigned long V_98 )
{
struct V_96 args ;
args . V_89 = V_89 ;
args . V_4 = V_4 ;
args . V_98 = V_98 ;
F_1 ( F_49 , & args ) ;
}
static inline void F_65 ( void * V_4 )
{
V_7 ( ( unsigned long ) V_4 ) ;
}
static void F_66 ( unsigned long V_4 )
{
if ( F_67 () )
F_65 ( ( void * ) V_4 ) ;
else
F_1 ( F_65 , ( void * ) V_4 ) ;
}
static inline void F_68 ( unsigned long V_22 , unsigned long V_24 )
{
if ( ! V_95 ) {
if ( V_24 - V_22 >= V_112 ) {
V_17 () ;
} else {
V_5 ;
F_69 ( V_22 , V_24 ) ;
}
}
if ( V_24 - V_22 > V_113 )
V_56 () ;
else {
switch ( F_70 () ) {
case V_42 :
F_71 ( V_22 , V_24 ) ;
break;
default:
F_72 ( V_22 , V_24 ) ;
break;
}
}
#ifdef F_73
F_74 ( V_22 , ( V_24 - V_22 ) ) ;
F_75 () ;
#endif
}
static inline void F_76 ( void * args )
{
struct V_114 * V_115 = args ;
unsigned long V_22 = V_115 -> V_22 ;
unsigned long V_24 = V_115 -> V_24 ;
F_68 ( V_22 , V_24 ) ;
}
static void F_77 ( unsigned long V_22 , unsigned long V_24 )
{
struct V_114 args ;
args . V_22 = V_22 ;
args . V_24 = V_24 ;
F_1 ( F_76 , & args ) ;
F_78 () ;
}
static void F_79 ( unsigned long V_4 , unsigned long V_116 )
{
F_80 ( V_116 == 0 ) ;
F_3 () ;
if ( V_117 ) {
if ( V_116 >= V_61 )
V_72 () ;
else
F_81 ( V_4 , V_4 + V_116 ) ;
F_6 () ;
F_75 () ;
return;
}
if ( V_118 && V_116 >= V_112 ) {
V_17 () ;
} else {
V_5 ;
F_82 ( V_4 , V_4 + V_116 ) ;
}
F_6 () ;
F_74 ( V_4 , V_116 ) ;
F_75 () ;
}
static void F_83 ( unsigned long V_4 , unsigned long V_116 )
{
F_80 ( V_116 == 0 ) ;
F_3 () ;
if ( V_117 ) {
if ( V_116 >= V_61 )
V_72 () ;
else {
F_84 ( V_4 , V_4 + V_116 ) ;
}
F_6 () ;
F_75 () ;
return;
}
if ( V_118 && V_116 >= V_112 ) {
V_17 () ;
} else {
V_5 ;
F_85 ( V_4 , V_4 + V_116 ) ;
}
F_6 () ;
F_86 ( V_4 , V_116 ) ;
F_75 () ;
}
static void F_87 ( void * V_119 )
{
unsigned long V_39 = F_27 () ;
unsigned long V_6 = F_13 () ;
unsigned long V_60 = F_34 () ;
unsigned long V_4 = ( unsigned long ) V_119 ;
V_5 ;
if ( V_6 )
F_88 ( V_4 & ~ ( V_6 - 1 ) ) ;
if ( ! V_109 && V_61 )
F_89 ( V_4 & ~ ( V_60 - 1 ) ) ;
if ( V_39 )
F_90 ( V_4 & ~ ( V_39 - 1 ) ) ;
if ( V_120 ) {
__asm__ __volatile__ (
".set push\n\t"
".set noat\n\t"
".set mips3\n\t"
#ifdef F_91
"la $at,1f\n\t"
#endif
#ifdef F_92
"dla $at,1f\n\t"
#endif
"cache %0,($at)\n\t"
"nop; nop; nop\n"
"1:\n\t"
".set pop"
:
: "i" (Hit_Invalidate_I));
}
if ( V_121 )
__asm__ __volatile__ ("sync");
}
static void F_93 ( unsigned long V_4 )
{
F_1 ( F_87 , ( void * ) V_4 ) ;
}
static void F_94 ( void )
{
if ( V_110 )
V_56 () ;
}
static inline void F_95 ( void * args )
{
struct V_122 * V_123 = args ;
unsigned long V_104 = V_123 -> V_104 ;
int V_116 = V_123 -> V_116 ;
if ( V_118 && V_116 >= V_112 )
V_17 () ;
else {
V_5 ;
F_82 ( V_104 , V_104 + V_116 ) ;
}
}
static void F_96 ( unsigned long V_104 , int V_116 )
{
struct V_122 args ;
args . V_104 = ( unsigned long ) V_104 ;
args . V_116 = V_116 ;
F_1 ( F_95 , & args ) ;
}
static inline void F_97 ( void )
{
const unsigned long V_39 = 32 ;
unsigned long V_4 ;
F_98 ( 0 ) ;
F_99 ( 0 ) ;
for ( V_4 = V_23 ; V_4 <= V_23 + 4096 ; V_4 += V_39 ) {
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
static inline void F_100 ( struct V_124 * V_125 )
{
unsigned int V_126 = V_125 -> V_127 & V_128 ;
unsigned int V_129 = V_125 -> V_127 & V_130 ;
switch ( V_126 ) {
case V_131 :
if ( V_129 <= F_101 ( 2 , 4 , 0 ) )
V_125 -> V_132 . V_21 |= V_133 ;
if ( V_129 == F_101 ( 2 , 4 , 0 ) )
F_102 ( F_103 () | V_134 ) ;
break;
case V_135 :
if ( V_129 <= F_101 ( 1 , 1 , 0 ) ) {
V_125 -> V_132 . V_21 |= V_133 ;
F_102 ( F_103 () | V_134 ) ;
}
break;
default:
F_104 () ;
}
}
static void F_105 ( void )
{
struct V_124 * V_125 = & V_25 ;
unsigned int V_136 = F_106 () ;
unsigned int V_137 = F_107 () ;
unsigned long V_138 ;
unsigned int V_139 ;
switch ( F_28 () ) {
case V_140 :
case V_141 :
case V_142 :
case V_143 :
V_113 = 1 << ( 12 + ( ( V_136 & V_144 ) >> 9 ) ) ;
V_125 -> V_26 . V_145 = 16 << ( ( V_136 & V_146 ) >> 5 ) ;
V_125 -> V_26 . V_31 = 2 ;
V_125 -> V_26 . V_29 = F_108 ( V_113 / 2 ) ;
V_112 = 1 << ( 12 + ( ( V_136 & V_147 ) >> 6 ) ) ;
V_125 -> V_132 . V_145 = 16 << ( ( V_136 & V_148 ) >> 4 ) ;
V_125 -> V_132 . V_31 = 2 ;
V_125 -> V_132 . V_29 = F_108 ( V_112 / 2 ) ;
V_125 -> V_149 |= V_150 ;
break;
case V_151 :
case V_152 :
V_113 = 1 << ( 12 + ( ( V_136 & V_144 ) >> 9 ) ) ;
V_125 -> V_26 . V_145 = 16 << ( ( V_136 & V_146 ) >> 5 ) ;
V_125 -> V_26 . V_31 = 2 ;
V_125 -> V_26 . V_29 = 0 ;
V_112 = 1 << ( 12 + ( ( V_136 & V_147 ) >> 6 ) ) ;
V_125 -> V_132 . V_145 = 16 << ( ( V_136 & V_148 ) >> 4 ) ;
V_125 -> V_132 . V_31 = 2 ;
V_125 -> V_132 . V_29 = 0 ;
V_125 -> V_149 |= V_150 | V_153 ;
break;
case V_154 :
V_113 = 1 << ( 12 + ( ( V_136 & V_144 ) >> 9 ) ) ;
V_125 -> V_26 . V_145 = 16 << ( ( V_136 & V_146 ) >> 5 ) ;
V_125 -> V_26 . V_31 = 4 ;
V_125 -> V_26 . V_29 = 0 ;
V_112 = 1 << ( 12 + ( ( V_136 & V_147 ) >> 6 ) ) ;
V_125 -> V_132 . V_145 = 16 << ( ( V_136 & V_148 ) >> 4 ) ;
V_125 -> V_132 . V_31 = 4 ;
V_125 -> V_132 . V_29 = 0 ;
V_125 -> V_149 |= V_150 ;
V_125 -> V_149 |= V_153 ;
break;
case V_155 :
case V_78 :
case V_79 :
case V_156 :
case V_80 :
case V_81 :
case V_157 :
V_113 = 1 << ( 12 + ( ( V_136 & V_144 ) >> 9 ) ) ;
V_125 -> V_26 . V_145 = 16 << ( ( V_136 & V_146 ) >> 5 ) ;
V_125 -> V_26 . V_31 = 1 ;
V_125 -> V_26 . V_29 = 0 ;
V_112 = 1 << ( 12 + ( ( V_136 & V_147 ) >> 6 ) ) ;
V_125 -> V_132 . V_145 = 16 << ( ( V_136 & V_148 ) >> 4 ) ;
V_125 -> V_132 . V_31 = 1 ;
V_125 -> V_132 . V_29 = 0 ;
V_125 -> V_149 |= V_150 ;
break;
case V_82 :
case V_83 :
case V_84 :
V_113 = 1 << ( 12 + ( ( V_136 & V_158 ) >> 29 ) ) ;
V_125 -> V_26 . V_145 = 64 ;
V_125 -> V_26 . V_31 = 2 ;
V_125 -> V_26 . V_29 = 0 ;
V_112 = 1 << ( 12 + ( ( V_136 & V_159 ) >> 26 ) ) ;
V_125 -> V_132 . V_145 = 32 ;
V_125 -> V_132 . V_31 = 2 ;
V_125 -> V_132 . V_29 = 0 ;
V_125 -> V_149 |= V_153 ;
break;
case V_160 :
F_109 ( V_136 & ~ V_161 ) ;
case V_162 :
if ( V_125 -> V_127 == 0x0c80U || V_125 -> V_127 == 0x0c81U ||
V_125 -> V_127 == 0x0c82U ) {
V_136 |= 0x00400000U ;
if ( V_125 -> V_127 == 0x0c80U )
V_136 |= V_163 ;
F_109 ( V_136 ) ;
} else
V_125 -> V_149 |= V_150 ;
V_113 = 1 << ( 10 + ( ( V_136 & V_144 ) >> 9 ) ) ;
V_125 -> V_26 . V_145 = 16 << ( ( V_136 & V_146 ) >> 5 ) ;
V_125 -> V_26 . V_31 = 2 ;
V_125 -> V_26 . V_29 = F_108 ( V_113 / 2 ) ;
V_112 = 1 << ( 10 + ( ( V_136 & V_147 ) >> 6 ) ) ;
V_125 -> V_132 . V_145 = 16 << ( ( V_136 & V_148 ) >> 4 ) ;
V_125 -> V_132 . V_31 = 2 ;
V_125 -> V_132 . V_29 = F_108 ( V_112 / 2 ) ;
break;
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
V_113 = 1 << ( 10 + ( ( V_136 & V_144 ) >> 9 ) ) ;
V_125 -> V_26 . V_145 = 16 << ( ( V_136 & V_146 ) >> 5 ) ;
V_125 -> V_26 . V_31 = 1 ;
V_125 -> V_26 . V_29 = 0 ;
V_112 = 1 << ( 10 + ( ( V_136 & V_147 ) >> 6 ) ) ;
V_125 -> V_132 . V_145 = 16 << ( ( V_136 & V_148 ) >> 4 ) ;
V_125 -> V_132 . V_31 = 1 ;
V_125 -> V_132 . V_29 = 0 ;
V_125 -> V_149 |= V_150 ;
break;
case V_170 :
F_97 () ;
V_113 = 1 << ( 12 + ( ( V_136 & V_144 ) >> 9 ) ) ;
V_125 -> V_26 . V_145 = 16 << ( ( V_136 & V_146 ) >> 5 ) ;
V_125 -> V_26 . V_31 = 4 ;
V_125 -> V_26 . V_29 = F_108 ( V_113 / V_125 -> V_26 . V_31 ) ;
V_112 = 1 << ( 12 + ( ( V_136 & V_147 ) >> 6 ) ) ;
V_125 -> V_132 . V_145 = 16 << ( ( V_136 & V_148 ) >> 4 ) ;
V_125 -> V_132 . V_31 = 4 ;
V_125 -> V_132 . V_29 = F_108 ( V_112 / V_125 -> V_132 . V_31 ) ;
V_125 -> V_149 |= V_150 ;
V_125 -> V_149 |= V_153 ;
break;
case V_42 :
V_113 = 1 << ( 12 + ( ( V_136 & V_144 ) >> 9 ) ) ;
V_125 -> V_26 . V_145 = 16 << ( ( V_136 & V_146 ) >> 5 ) ;
if ( V_137 & 0x3 )
V_125 -> V_26 . V_31 = 4 ;
else
V_125 -> V_26 . V_31 = 2 ;
V_125 -> V_26 . V_29 = 0 ;
V_112 = 1 << ( 12 + ( ( V_136 & V_147 ) >> 6 ) ) ;
V_125 -> V_132 . V_145 = 16 << ( ( V_136 & V_148 ) >> 4 ) ;
if ( V_137 & 0x3 )
V_125 -> V_132 . V_31 = 4 ;
else
V_125 -> V_132 . V_31 = 2 ;
V_125 -> V_132 . V_29 = 0 ;
break;
case V_77 :
V_138 = F_110 () ;
V_139 = ( V_138 >> 19 ) & 7 ;
if ( V_139 )
V_125 -> V_26 . V_145 = 2 << V_139 ;
else
V_125 -> V_26 . V_145 = 0 ;
V_125 -> V_26 . V_171 = 64 << ( ( V_138 >> 22 ) & 7 ) ;
V_125 -> V_26 . V_31 = 1 + ( ( V_138 >> 16 ) & 7 ) ;
V_113 = V_125 -> V_26 . V_171 *
V_125 -> V_26 . V_31 *
V_125 -> V_26 . V_145 ;
V_125 -> V_26 . V_29 = 0 ;
V_139 = ( V_138 >> 10 ) & 7 ;
if ( V_139 )
V_125 -> V_132 . V_145 = 2 << V_139 ;
else
V_125 -> V_132 . V_145 = 0 ;
V_125 -> V_132 . V_171 = 64 << ( ( V_138 >> 13 ) & 7 ) ;
V_125 -> V_132 . V_31 = 1 + ( ( V_138 >> 7 ) & 7 ) ;
V_112 = V_125 -> V_132 . V_171 *
V_125 -> V_132 . V_31 *
V_125 -> V_132 . V_145 ;
V_125 -> V_132 . V_29 = 0 ;
break;
default:
if ( ! ( V_136 & V_172 ) )
F_111 ( L_1 ) ;
V_138 = F_110 () ;
V_139 = ( V_138 >> 19 ) & 7 ;
if ( V_139 == 7 )
F_111 ( L_2 ) ;
V_125 -> V_26 . V_145 = V_139 ? 2 << V_139 : 0 ;
V_125 -> V_26 . V_171 = 32 << ( ( ( V_138 >> 22 ) + 1 ) & 7 ) ;
V_125 -> V_26 . V_31 = 1 + ( ( V_138 >> 16 ) & 7 ) ;
V_113 = V_125 -> V_26 . V_171 *
V_125 -> V_26 . V_31 *
V_125 -> V_26 . V_145 ;
V_125 -> V_26 . V_29 = F_108 ( V_113 / V_125 -> V_26 . V_31 ) ;
if ( V_136 & 0x8 )
V_125 -> V_26 . V_21 |= V_133 ;
V_125 -> V_132 . V_21 = 0 ;
V_139 = ( V_138 >> 10 ) & 7 ;
if ( V_139 == 7 )
F_111 ( L_3 ) ;
V_125 -> V_132 . V_145 = V_139 ? 2 << V_139 : 0 ;
V_125 -> V_132 . V_171 = 32 << ( ( ( V_138 >> 13 ) + 1 ) & 7 ) ;
V_125 -> V_132 . V_31 = 1 + ( ( V_138 >> 7 ) & 7 ) ;
V_112 = V_125 -> V_132 . V_171 *
V_125 -> V_132 . V_31 *
V_125 -> V_132 . V_145 ;
V_125 -> V_132 . V_29 = F_108 ( V_112 / V_125 -> V_132 . V_31 ) ;
V_125 -> V_149 |= V_153 ;
break;
}
if ( ( V_137 & V_128 ) == V_173 &&
( V_137 & V_130 ) < V_174 &&
! ( V_136 & V_175 ) && V_125 -> V_26 . V_145 != 16 &&
V_38 <= 0x8000 )
F_111 ( L_4 ) ;
V_125 -> V_26 . V_27 = V_113 / V_125 -> V_26 . V_31 ;
V_125 -> V_132 . V_27 = V_112 / V_125 -> V_132 . V_31 ;
V_125 -> V_26 . V_171 = V_125 -> V_26 . V_145 ?
V_113 / ( V_125 -> V_26 . V_145 * V_125 -> V_26 . V_31 ) : 0 ;
V_125 -> V_132 . V_171 = V_125 -> V_132 . V_145 ?
V_112 / ( V_125 -> V_132 . V_145 * V_125 -> V_132 . V_31 ) : 0 ;
switch ( F_28 () ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
V_125 -> V_132 . V_21 |= V_181 ;
break;
case V_82 :
case V_83 :
case V_84 :
break;
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
if ( ( V_125 -> V_193 == V_186 ) || ( V_125 -> V_193 == V_188 ) )
F_100 ( V_125 ) ;
if ( ! ( F_112 () & V_194 ) &&
( V_125 -> V_26 . V_27 > V_38 ) )
V_125 -> V_26 . V_21 |= V_195 ;
if ( F_112 () & V_196 ) {
V_125 -> V_132 . V_21 |= V_181 ;
break;
}
default:
if ( V_125 -> V_132 . V_27 > V_38 )
V_125 -> V_132 . V_21 |= V_195 ;
}
switch ( F_28 () ) {
case V_176 :
V_125 -> V_26 . V_21 |= V_133 ;
break;
case V_197 :
V_125 -> V_26 . V_21 |= V_198 ;
break;
case V_42 :
V_125 -> V_26 . V_31 = 1 ;
}
F_113 ( L_5 ,
V_113 >> 10 ,
V_125 -> V_26 . V_21 & V_133 ? L_6 : L_7 ,
V_199 [ V_125 -> V_26 . V_31 ] , V_125 -> V_26 . V_145 ) ;
F_113 ( L_8 ,
V_112 >> 10 , V_199 [ V_125 -> V_132 . V_31 ] ,
( V_125 -> V_132 . V_21 & V_181 ) ? L_9 : L_7 ,
( V_125 -> V_132 . V_21 & V_195 ) ?
L_10 : L_11 ,
V_125 -> V_132 . V_145 ) ;
}
static int F_114 ( void )
{
unsigned long V_21 , V_4 , V_200 , V_24 , V_201 ;
unsigned int V_136 = F_106 () ;
struct V_124 * V_125 = & V_25 ;
if ( V_136 & V_175 )
return 0 ;
V_200 = ( unsigned long ) & V_202 ;
V_200 &= ~ ( ( 4 * 1024 * 1024 ) - 1 ) ;
V_24 = V_200 + ( 4 * 1024 * 1024 ) ;
F_18 ( V_21 ) ;
V_201 = ( 64 * 1024 ) ;
for ( V_4 = V_200 ; V_4 < V_24 ; V_4 = ( V_200 + V_201 ) ) {
unsigned long * V_203 = ( unsigned long * ) V_4 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_201 <<= 1 ;
}
F_98 ( 0 ) ;
F_99 ( 0 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
F_115 ( V_204 , V_200 ) ;
F_115 ( V_205 , V_200 ) ;
F_115 ( V_206 , V_200 ) ;
V_201 = ( 128 * 1024 ) ;
for ( V_4 = V_200 + ( 128 * 1024 ) ; V_4 < V_24 ; V_4 = V_200 + V_201 ) {
F_115 ( V_207 , V_4 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
if ( ! F_116 () )
break;
V_201 <<= 1 ;
}
F_20 ( V_21 ) ;
V_4 -= V_200 ;
V_61 = V_4 ;
V_125 -> V_208 . V_145 = 16 << ( ( V_136 & V_209 ) >> 22 ) ;
V_125 -> V_208 . V_31 = 1 ;
V_125 -> V_132 . V_29 = 0 ;
return 1 ;
}
static void T_6 F_117 ( void )
{
struct V_124 * V_125 = & V_25 ;
V_61 = 512 * 1024 ;
V_125 -> V_208 . V_145 = 32 ;
V_125 -> V_208 . V_31 = 4 ;
V_125 -> V_208 . V_29 = 0 ;
V_125 -> V_208 . V_27 = V_61 / ( V_125 -> V_208 . V_31 ) ;
V_125 -> V_208 . V_171 = V_61 / ( V_125 -> V_208 . V_145 * V_125 -> V_208 . V_31 ) ;
F_118 ( L_12 ,
V_61 >> 10 , V_199 [ V_125 -> V_208 . V_31 ] , V_125 -> V_208 . V_145 ) ;
V_125 -> V_149 |= V_210 ;
}
static void T_6 F_119 ( void )
{
struct V_124 * V_125 = & V_25 ;
unsigned int V_211 , V_139 ;
V_211 = F_120 () ;
V_139 = ( V_211 >> 4 ) & 15 ;
if ( V_139 )
V_125 -> V_208 . V_145 = 2 << V_139 ;
else
V_125 -> V_208 . V_145 = 0 ;
V_125 -> V_208 . V_171 = 64 << ( ( V_211 >> 8 ) & 15 ) ;
V_125 -> V_208 . V_31 = 1 + ( V_211 & 15 ) ;
V_61 = V_125 -> V_208 . V_171 *
V_125 -> V_208 . V_31 *
V_125 -> V_208 . V_145 ;
V_61 *= 4 ;
V_125 -> V_208 . V_29 = 0 ;
F_118 ( L_12 ,
V_61 >> 10 , V_199 [ V_125 -> V_208 . V_31 ] , V_125 -> V_208 . V_145 ) ;
if ( V_61 )
V_125 -> V_149 |= V_210 ;
return;
}
static void F_121 ( void )
{
struct V_124 * V_125 = & V_25 ;
unsigned int V_136 = F_106 () ;
int V_212 = 0 ;
switch ( F_28 () ) {
case V_78 :
case V_79 :
case V_80 :
case V_81 :
V_212 = F_122 ( F_114 ) ;
if ( V_212 )
V_125 -> V_149 |= V_213 ;
break;
case V_82 :
case V_83 :
case V_84 :
V_61 = 0x80000 << ( ( V_136 & V_214 ) >> 16 ) ;
V_125 -> V_208 . V_145 = 64 << ( ( V_136 >> 13 ) & 1 ) ;
V_125 -> V_208 . V_31 = 2 ;
V_125 -> V_208 . V_29 = 0 ;
V_212 = 1 ;
break;
case V_142 :
case V_143 :
#ifdef F_123
F_124 () ;
#endif
return;
case V_170 :
#ifdef F_125
F_126 () ;
#endif
return;
case V_42 :
F_117 () ;
return;
case V_77 :
F_119 () ;
return;
case V_215 :
return;
default:
if ( V_125 -> V_216 & ( V_217 | V_218 |
V_219 | V_220 ) ) {
#ifdef F_127
if ( F_128 () ) {
V_61 = V_125 -> V_208 . V_31 * V_125 -> V_208 . V_171 * V_125 -> V_208 . V_145 ;
F_113 ( L_13 ,
V_61 >> 10 ,
V_199 [ V_125 -> V_208 . V_31 ] , V_125 -> V_208 . V_145 ) ;
}
#else
if ( ! ( V_125 -> V_208 . V_21 & V_221 ) )
F_111 ( L_14 ) ;
#endif
return;
}
V_212 = 0 ;
}
if ( ! V_212 )
return;
V_125 -> V_208 . V_27 = V_61 / V_125 -> V_208 . V_31 ;
V_125 -> V_208 . V_171 = V_61 / ( V_125 -> V_208 . V_145 * V_125 -> V_208 . V_31 ) ;
F_113 ( L_12 ,
V_61 >> 10 , V_199 [ V_125 -> V_208 . V_31 ] , V_125 -> V_208 . V_145 ) ;
V_125 -> V_149 |= V_210 ;
}
void F_129 ( void )
{
switch ( F_107 () ) {
case 0x00030100 :
case 0x00030201 :
case 0x00030202 :
case 0x01030200 :
case 0x02030200 :
case 0x02030201 :
case 0x02030202 :
F_130 ( 1 << 19 ) ;
break;
}
}
static void F_131 ( void )
{
unsigned long V_222 ;
V_222 = F_106 () ;
V_222 &= ~ ( 0x7 | ( 7 << 25 ) | ( 7 << 28 ) ) ;
V_222 |= ( ( ( V_223 >> V_224 ) << 0 ) |
( ( V_223 >> V_224 ) << 25 ) |
( ( V_223 >> V_224 ) << 28 ) ) ;
F_109 ( V_222 ) ;
F_132 () ;
}
static int T_6 F_133 ( char * V_225 )
{
F_134 ( & V_225 , & V_226 ) ;
return 0 ;
}
static void F_135 ( void )
{
if ( V_226 < 0 || V_226 > 7 )
V_226 = F_106 () & V_227 ;
V_223 = V_226 << V_224 ;
F_136 ( L_15 , V_226 ) ;
F_137 ( V_227 , V_226 ) ;
switch ( F_28 () ) {
case V_155 :
case V_78 :
case V_79 :
case V_156 :
case V_80 :
case V_81 :
F_138 ( V_228 ) ;
break;
case V_197 :
F_129 () ;
break;
case V_229 :
F_131 () ;
break;
}
}
static void F_139 ( void )
{
extern char __weak V_230 ;
extern char __weak V_231 ;
switch ( F_28 () ) {
case V_178 :
case V_179 :
F_140 ( 0x100 , & V_231 , 0x80 ) ;
break;
default:
F_140 ( 0x100 , & V_230 , 0x80 ) ;
break;
}
}
void F_141 ( void )
{
extern void V_232 ( void ) ;
extern void V_233 ( void ) ;
struct V_124 * V_125 = & V_25 ;
F_105 () ;
F_121 () ;
F_12 () ;
F_15 () ;
F_16 () ;
F_26 () ;
F_30 () ;
F_32 () ;
F_33 () ;
F_35 () ;
F_36 () ;
#ifdef F_73
F_14 () ;
F_29 () ;
#endif
if ( V_125 -> V_132 . V_145 )
V_234 = F_142 ( unsigned long,
c->dcache.sets * c->dcache.linesz - 1 ,
PAGE_SIZE - 1 ) ;
else
V_234 = V_38 - 1 ;
V_235 = F_43 ;
V_236 = F_44 ;
V_237 = F_7 ;
V_238 = F_38 ;
V_239 = F_48 ;
V_240 = F_64 ;
V_241 = F_46 ;
V_242 = F_96 ;
V_243 = F_93 ;
V_244 = F_94 ;
V_245 = F_65 ;
V_246 = F_66 ;
V_247 = F_77 ;
V_248 = F_68 ;
#if F_4 ( V_249 ) || F_4 ( V_250 )
if ( V_251 ) {
V_252 = ( void * ) F_7 ;
V_253 = ( void * ) F_7 ;
V_254 = ( void * ) F_7 ;
} else {
V_252 = F_79 ;
V_253 = F_79 ;
V_254 = F_83 ;
}
#endif
V_232 () ;
V_233 () ;
F_37 ( NULL ) ;
F_135 () ;
V_255 = F_139 ;
}
