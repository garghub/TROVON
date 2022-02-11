static inline void F_1 ( void (* F_2) ( void * V_1 ) , void * V_1 )
{
F_3 () ;
if ( ! F_4 () )
F_5 ( & V_2 , F_2 , V_1 , 1 ) ;
F_2 ( V_1 ) ;
F_6 () ;
}
static void F_7 ( void ) {}
static inline void F_8 ( unsigned long V_3 )
{
V_4 ;
F_9 ( V_3 ) ;
}
static inline void F_10 ( unsigned long V_3 )
{
F_11 ( V_3 ) ;
}
static inline void F_12 ( unsigned long V_3 )
{
F_13 ( V_3 ) ;
}
static void F_14 ( void )
{
unsigned long V_5 = F_15 () ;
switch ( V_5 ) {
case 0 :
V_6 = ( void * ) F_7 ;
break;
case 16 :
V_6 = V_7 ;
break;
case 32 :
V_6 = F_8 ;
break;
case 64 :
V_6 = F_10 ;
break;
case 128 :
V_6 = F_12 ;
break;
default:
break;
}
}
static void F_16 ( void )
{
unsigned long V_5 = F_15 () ;
if ( V_5 == 0 )
V_8 = ( void * ) F_7 ;
else if ( V_5 == 16 )
V_8 = V_9 ;
else if ( V_5 == 32 )
V_8 = V_10 ;
else if ( V_5 == 64 )
V_8 = V_11 ;
}
static void F_17 ( void )
{
unsigned long V_5 = F_15 () ;
if ( V_5 == 0 )
V_12 = ( void * ) F_7 ;
else if ( V_5 == 16 )
V_12 = V_13 ;
else if ( V_5 == 32 )
V_12 = V_14 ;
else if ( V_5 == 64 )
V_12 = V_15 ;
else if ( V_5 == 128 )
V_12 = V_16 ;
}
static void F_18 ( void )
{
unsigned long V_5 = F_15 () ;
if ( V_5 == 0 )
V_17 = ( void * ) F_7 ;
else if ( V_5 == 16 )
V_17 = V_18 ;
else if ( V_5 == 32 )
V_17 = V_19 ;
else if ( V_5 == 64 )
V_17 = V_20 ;
else if ( V_5 == 128 )
V_17 = V_21 ;
}
static inline void F_19 ( void )
{
unsigned long V_22 ;
F_20 ( V_22 ) ;
F_21 () ;
F_22 ( V_22 ) ;
}
static inline void F_23 ( void )
{
unsigned long V_23 = V_24 ;
unsigned long V_25 = V_23 + V_26 . V_27 . V_28 ;
unsigned long V_29 = 1UL << V_26 . V_27 . V_30 ;
unsigned long V_31 = V_26 . V_27 . V_32 <<
V_26 . V_27 . V_30 ;
unsigned long V_33 , V_3 ;
V_34 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 += V_29 )
for ( V_3 = V_23 + 0x400 ; V_3 < V_25 ; V_3 += 0x400 * 2 )
F_24 ( V_3 | V_33 , V_35 ) ;
V_36 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 += V_29 )
for ( V_3 = V_23 ; V_3 < V_25 ; V_3 += 0x400 * 2 )
F_24 ( V_3 | V_33 , V_35 ) ;
}
static inline void F_25 ( unsigned long V_37 )
{
unsigned long V_22 ;
F_20 ( V_22 ) ;
F_26 ( V_37 ) ;
F_22 ( V_22 ) ;
}
static inline void F_27 ( unsigned long V_37 )
{
unsigned long V_38 = V_26 . V_27 . V_28 - 1 ;
unsigned long V_23 = V_24 + ( V_37 & V_38 ) ;
unsigned long V_25 = V_23 + V_39 ;
unsigned long V_29 = 1UL << V_26 . V_27 . V_30 ;
unsigned long V_31 = V_26 . V_27 . V_32 <<
V_26 . V_27 . V_30 ;
unsigned long V_33 , V_3 ;
V_34 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 += V_29 )
for ( V_3 = V_23 + 0x400 ; V_3 < V_25 ; V_3 += 0x400 * 2 )
F_24 ( V_3 | V_33 , V_35 ) ;
V_36 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 += V_29 )
for ( V_3 = V_23 ; V_3 < V_25 ; V_3 += 0x400 * 2 )
F_24 ( V_3 | V_33 , V_35 ) ;
}
static void F_28 ( void )
{
unsigned long V_40 = F_29 () ;
if ( V_40 == 0 )
V_41 = ( void * ) F_7 ;
else if ( V_40 == 16 )
V_41 = V_42 ;
else if ( V_40 == 32 && F_30 () == V_43 )
V_41 = V_44 ;
else if ( V_40 == 32 )
V_41 = V_45 ;
else if ( V_40 == 64 )
V_41 = V_46 ;
else if ( V_40 == 128 )
V_41 = V_47 ;
}
static void F_31 ( void )
{
unsigned long V_40 = F_29 () ;
if ( V_40 == 0 )
V_48 = ( void * ) F_7 ;
else if ( V_40 == 16 )
V_48 = V_49 ;
else if ( V_40 == 32 )
V_48 = V_50 ;
else if ( V_40 == 64 )
V_48 = V_51 ;
}
static void F_32 ( void )
{
unsigned long V_40 = F_29 () ;
if ( V_40 == 0 )
V_52 = ( void * ) F_7 ;
else if ( V_40 == 16 )
V_52 = V_53 ;
else if ( V_40 == 32 ) {
if ( V_54 && F_33 () )
V_52 =
F_25 ;
else if ( V_55 )
V_52 =
F_27 ;
else if ( F_30 () == V_43 )
V_52 =
V_56 ;
else
V_52 =
F_26 ;
} else if ( V_40 == 64 )
V_52 = V_57 ;
}
static void F_34 ( void )
{
unsigned long V_40 = F_29 () ;
if ( V_40 == 0 )
V_58 = ( void * ) F_7 ;
else if ( V_40 == 16 )
V_58 = V_59 ;
else if ( V_40 == 32 ) {
if ( V_54 && F_33 () )
V_58 = F_19 ;
else if ( V_55 )
V_58 = F_23 ;
else if ( F_30 () == V_43 )
V_58 = V_60 ;
else
V_58 = F_21 ;
} else if ( V_40 == 64 )
V_58 = V_61 ;
else if ( V_40 == 128 )
V_58 = V_62 ;
}
static void F_35 ( void )
{
unsigned long V_63 = F_36 () ;
if ( V_64 == 0 )
V_65 = ( void * ) F_7 ;
else if ( V_63 == 16 )
V_65 = V_66 ;
else if ( V_63 == 32 )
V_65 = V_67 ;
else if ( V_63 == 64 )
V_65 = V_68 ;
else if ( V_63 == 128 )
V_65 = V_69 ;
}
static void F_37 ( void )
{
unsigned long V_63 = F_36 () ;
if ( V_64 == 0 )
V_70 = ( void * ) F_7 ;
else if ( V_63 == 16 )
V_70 = V_71 ;
else if ( V_63 == 32 )
V_70 = V_72 ;
else if ( V_63 == 64 )
V_70 = V_73 ;
else if ( V_63 == 128 )
V_70 = V_74 ;
}
static void F_38 ( void )
{
unsigned long V_63 = F_36 () ;
if ( V_64 == 0 )
V_75 = ( void * ) F_7 ;
else if ( V_63 == 16 )
V_75 = V_76 ;
else if ( V_63 == 32 )
V_75 = V_77 ;
else if ( V_63 == 64 )
V_75 = V_78 ;
else if ( V_63 == 128 )
V_75 = V_79 ;
}
static inline void F_39 ( void * args )
{
switch ( F_30 () ) {
case V_43 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_75 () ;
break;
default:
V_17 () ;
V_58 () ;
break;
}
}
static void F_40 ( void )
{
F_1 ( F_39 , NULL ) ;
}
static inline int F_41 ( const struct V_89 * V_90 )
{
#ifdef F_42
int V_91 ;
F_43 (i)
if ( F_44 ( V_91 , V_90 ) )
return 1 ;
return 0 ;
#else
return F_44 ( F_45 () , V_90 ) ;
#endif
}
static void F_46 ( void )
{
V_17 () ;
}
static void F_47 ( void )
{
V_17 () ;
}
static inline void F_48 ( void * args )
{
struct V_92 * V_93 = args ;
int V_94 = V_93 -> V_95 & V_96 ;
if ( ! ( F_41 ( V_93 -> V_97 ) ) )
return;
V_17 () ;
if ( V_94 )
V_58 () ;
}
static void F_49 ( struct V_92 * V_93 ,
unsigned long V_23 , unsigned long V_25 )
{
int V_94 = V_93 -> V_95 & V_96 ;
if ( V_98 || ( V_94 && ! V_99 ) )
F_1 ( F_48 , V_93 ) ;
}
static inline void F_50 ( void * args )
{
struct V_89 * V_90 = args ;
if ( ! F_41 ( V_90 ) )
return;
if ( F_30 () == V_81 ||
F_30 () == V_82 ||
F_30 () == V_83 ||
F_30 () == V_84 ) {
V_75 () ;
return;
}
V_17 () ;
}
static void F_51 ( struct V_89 * V_90 )
{
if ( ! V_98 )
return;
F_1 ( F_50 , V_90 ) ;
}
static inline void F_52 ( void * args )
{
struct V_100 * V_101 = args ;
struct V_92 * V_93 = V_101 -> V_93 ;
unsigned long V_3 = V_101 -> V_3 ;
struct V_37 * V_37 = F_53 ( V_101 -> V_102 ) ;
int V_94 = V_93 -> V_95 & V_96 ;
struct V_89 * V_90 = V_93 -> V_97 ;
int V_103 = 0 ;
T_1 * V_104 ;
T_2 * V_105 ;
T_3 * V_106 ;
T_4 * V_107 ;
void * V_108 ;
if ( ! F_41 ( V_90 ) )
return;
V_3 &= V_109 ;
V_104 = F_54 ( V_90 , V_3 ) ;
V_105 = F_55 ( V_104 , V_3 ) ;
V_106 = F_56 ( V_105 , V_3 ) ;
V_107 = F_57 ( V_106 , V_3 ) ;
if ( ! ( F_58 ( * V_107 ) ) )
return;
if ( ( V_90 == V_110 -> V_111 ) && ( F_59 ( * V_107 ) & V_112 ) )
V_108 = NULL ;
else {
V_103 = ( V_98 &&
F_60 ( V_37 ) && ! F_61 ( V_37 ) ) ;
if ( V_103 )
V_108 = F_62 ( V_37 , V_3 ) ;
else
V_108 = F_63 ( V_37 ) ;
V_3 = ( unsigned long ) V_108 ;
}
if ( V_98 || ( V_94 && ! V_99 ) ) {
V_108 ? V_6 ( V_3 ) :
V_8 ( V_3 ) ;
if ( V_94 && ! V_113 )
V_65 ( V_3 ) ;
}
if ( V_94 ) {
if ( V_108 && V_114 && V_90 == V_110 -> V_111 ) {
int V_115 = F_45 () ;
if ( F_44 ( V_115 , V_90 ) != 0 )
F_64 ( V_90 , V_115 ) ;
} else
V_108 ? V_41 ( V_3 ) :
V_48 ( V_3 ) ;
}
if ( V_108 ) {
if ( V_103 )
F_65 () ;
else
F_66 ( V_108 ) ;
}
}
static void F_67 ( struct V_92 * V_93 ,
unsigned long V_3 , unsigned long V_102 )
{
struct V_100 args ;
args . V_93 = V_93 ;
args . V_3 = V_3 ;
args . V_102 = V_102 ;
F_1 ( F_52 , & args ) ;
}
static inline void F_68 ( void * V_3 )
{
V_6 ( ( unsigned long ) V_3 ) ;
}
static void F_69 ( unsigned long V_3 )
{
if ( F_70 () )
F_68 ( ( void * ) V_3 ) ;
else
F_1 ( F_68 , ( void * ) V_3 ) ;
}
static inline void F_71 ( unsigned long V_23 , unsigned long V_25 )
{
if ( ! V_99 ) {
if ( V_25 - V_23 >= V_116 ) {
V_17 () ;
} else {
V_4 ;
F_72 ( V_23 , V_25 ) ;
}
}
if ( V_25 - V_23 > V_117 )
V_58 () ;
else {
switch ( F_73 () ) {
case V_43 :
F_74 ( V_23 , V_25 ) ;
break;
default:
F_75 ( V_23 , V_25 ) ;
break;
}
}
#ifdef F_76
F_77 ( V_23 , ( V_25 - V_23 ) ) ;
F_78 () ;
#endif
}
static inline void F_79 ( void * args )
{
struct V_118 * V_119 = args ;
unsigned long V_23 = V_119 -> V_23 ;
unsigned long V_25 = V_119 -> V_25 ;
F_71 ( V_23 , V_25 ) ;
}
static void F_80 ( unsigned long V_23 , unsigned long V_25 )
{
struct V_118 args ;
args . V_23 = V_23 ;
args . V_25 = V_25 ;
F_1 ( F_79 , & args ) ;
F_81 () ;
}
static void F_82 ( unsigned long V_3 , unsigned long V_120 )
{
F_83 ( V_120 == 0 ) ;
F_3 () ;
if ( V_121 ) {
if ( V_120 >= V_64 )
V_75 () ;
else
F_84 ( V_3 , V_3 + V_120 ) ;
F_6 () ;
F_78 () ;
return;
}
if ( V_122 && V_120 >= V_116 ) {
V_17 () ;
} else {
V_4 ;
F_85 ( V_3 , V_3 + V_120 ) ;
}
F_6 () ;
F_77 ( V_3 , V_120 ) ;
F_78 () ;
}
static void F_86 ( unsigned long V_3 , unsigned long V_120 )
{
F_83 ( V_120 == 0 ) ;
F_3 () ;
if ( V_121 ) {
if ( V_120 >= V_64 )
V_75 () ;
else {
F_87 ( V_3 , V_3 + V_120 ) ;
}
F_6 () ;
F_78 () ;
return;
}
if ( V_122 && V_120 >= V_116 ) {
V_17 () ;
} else {
V_4 ;
F_88 ( V_3 , V_3 + V_120 ) ;
}
F_6 () ;
F_89 ( V_3 , V_120 ) ;
F_78 () ;
}
static void F_90 ( void * V_123 )
{
unsigned long V_40 = F_29 () ;
unsigned long V_5 = F_15 () ;
unsigned long V_63 = F_36 () ;
unsigned long V_3 = ( unsigned long ) V_123 ;
V_4 ;
if ( V_5 )
F_91 ( V_3 & ~ ( V_5 - 1 ) ) ;
if ( ! V_113 && V_64 )
F_92 ( V_3 & ~ ( V_63 - 1 ) ) ;
if ( V_40 )
F_93 ( V_3 & ~ ( V_40 - 1 ) ) ;
if ( V_124 ) {
__asm__ __volatile__ (
".set push\n\t"
".set noat\n\t"
".set "MIPS_ISA_LEVEL"\n\t"
#ifdef F_94
"la $at,1f\n\t"
#endif
#ifdef F_95
"dla $at,1f\n\t"
#endif
"cache %0,($at)\n\t"
"nop; nop; nop\n"
"1:\n\t"
".set pop"
:
: "i" (Hit_Invalidate_I));
}
if ( V_125 )
__asm__ __volatile__ ("sync");
}
static void F_96 ( unsigned long V_3 )
{
F_1 ( F_90 , ( void * ) V_3 ) ;
}
static void F_97 ( void )
{
if ( V_114 )
V_58 () ;
}
static inline void F_98 ( void * args )
{
struct V_126 * V_127 = args ;
unsigned long V_108 = V_127 -> V_108 ;
int V_120 = V_127 -> V_120 ;
if ( V_122 && V_120 >= V_116 )
V_17 () ;
else {
V_4 ;
F_85 ( V_108 , V_108 + V_120 ) ;
}
}
static void F_99 ( unsigned long V_108 , int V_120 )
{
struct V_126 args ;
args . V_108 = ( unsigned long ) V_108 ;
args . V_120 = V_120 ;
F_1 ( F_98 , & args ) ;
}
static inline void F_100 ( void )
{
const unsigned long V_40 = 32 ;
unsigned long V_3 ;
F_101 ( 0 ) ;
F_102 ( 0 ) ;
for ( V_3 = V_24 ; V_3 <= V_24 + 4096 ; V_3 += V_40 ) {
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
static inline int F_103 ( struct V_128 * V_129 )
{
unsigned int V_130 = V_129 -> V_131 & V_132 ;
unsigned int V_133 = V_129 -> V_131 & V_134 ;
int V_135 = 0 ;
switch ( V_130 ) {
case V_136 :
if ( V_133 <= F_104 ( 2 , 4 , 0 ) )
V_135 = 1 ;
if ( V_133 == F_104 ( 2 , 4 , 0 ) )
F_105 ( F_106 () | V_137 ) ;
break;
case V_138 :
if ( V_133 <= F_104 ( 1 , 1 , 0 ) ) {
V_135 = 1 ;
F_105 ( F_106 () | V_137 ) ;
}
break;
default:
F_107 () ;
}
return V_135 ;
}
static void F_108 ( void )
{
F_78 () ;
F_78 () ;
__asm__ __volatile__(
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
: : : "memory");
}
static void F_109 ( void )
{
struct V_128 * V_129 = & V_26 ;
unsigned int V_139 = F_110 () ;
unsigned int V_140 = F_111 () ;
int V_141 = 0 ;
unsigned long V_142 ;
unsigned int V_143 ;
switch ( F_30 () ) {
case V_144 :
case V_145 :
case V_146 :
case V_147 :
V_117 = 1 << ( 12 + ( ( V_139 & V_148 ) >> 9 ) ) ;
V_129 -> V_27 . V_149 = 16 << ( ( V_139 & V_150 ) >> 5 ) ;
V_129 -> V_27 . V_32 = 2 ;
V_129 -> V_27 . V_30 = F_112 ( V_117 / 2 ) ;
V_116 = 1 << ( 12 + ( ( V_139 & V_151 ) >> 6 ) ) ;
V_129 -> V_152 . V_149 = 16 << ( ( V_139 & V_153 ) >> 4 ) ;
V_129 -> V_152 . V_32 = 2 ;
V_129 -> V_152 . V_30 = F_112 ( V_116 / 2 ) ;
V_129 -> V_154 |= V_155 ;
break;
case V_156 :
case V_157 :
V_117 = 1 << ( 12 + ( ( V_139 & V_148 ) >> 9 ) ) ;
V_129 -> V_27 . V_149 = 16 << ( ( V_139 & V_150 ) >> 5 ) ;
V_129 -> V_27 . V_32 = 2 ;
V_129 -> V_27 . V_30 = 0 ;
V_116 = 1 << ( 12 + ( ( V_139 & V_151 ) >> 6 ) ) ;
V_129 -> V_152 . V_149 = 16 << ( ( V_139 & V_153 ) >> 4 ) ;
V_129 -> V_152 . V_32 = 2 ;
V_129 -> V_152 . V_30 = 0 ;
V_129 -> V_154 |= V_155 | V_158 ;
break;
case V_159 :
V_117 = 1 << ( 12 + ( ( V_139 & V_148 ) >> 9 ) ) ;
V_129 -> V_27 . V_149 = 16 << ( ( V_139 & V_150 ) >> 5 ) ;
V_129 -> V_27 . V_32 = 4 ;
V_129 -> V_27 . V_30 = 0 ;
V_116 = 1 << ( 12 + ( ( V_139 & V_151 ) >> 6 ) ) ;
V_129 -> V_152 . V_149 = 16 << ( ( V_139 & V_153 ) >> 4 ) ;
V_129 -> V_152 . V_32 = 4 ;
V_129 -> V_152 . V_30 = 0 ;
V_129 -> V_154 |= V_155 ;
V_129 -> V_154 |= V_158 ;
break;
case V_160 :
case V_81 :
case V_82 :
case V_161 :
case V_83 :
case V_84 :
case V_162 :
V_117 = 1 << ( 12 + ( ( V_139 & V_148 ) >> 9 ) ) ;
V_129 -> V_27 . V_149 = 16 << ( ( V_139 & V_150 ) >> 5 ) ;
V_129 -> V_27 . V_32 = 1 ;
V_129 -> V_27 . V_30 = 0 ;
V_116 = 1 << ( 12 + ( ( V_139 & V_151 ) >> 6 ) ) ;
V_129 -> V_152 . V_149 = 16 << ( ( V_139 & V_153 ) >> 4 ) ;
V_129 -> V_152 . V_32 = 1 ;
V_129 -> V_152 . V_30 = 0 ;
V_129 -> V_154 |= V_155 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_117 = 1 << ( 12 + ( ( V_139 & V_163 ) >> 29 ) ) ;
V_129 -> V_27 . V_149 = 64 ;
V_129 -> V_27 . V_32 = 2 ;
V_129 -> V_27 . V_30 = 0 ;
V_116 = 1 << ( 12 + ( ( V_139 & V_164 ) >> 26 ) ) ;
V_129 -> V_152 . V_149 = 32 ;
V_129 -> V_152 . V_32 = 2 ;
V_129 -> V_152 . V_30 = 0 ;
V_129 -> V_154 |= V_158 ;
break;
case V_165 :
F_113 ( V_139 & ~ V_166 ) ;
case V_167 :
if ( V_129 -> V_131 == 0x0c80U || V_129 -> V_131 == 0x0c81U ||
V_129 -> V_131 == 0x0c82U ) {
V_139 |= 0x00400000U ;
if ( V_129 -> V_131 == 0x0c80U )
V_139 |= V_168 ;
F_113 ( V_139 ) ;
} else
V_129 -> V_154 |= V_155 ;
V_117 = 1 << ( 10 + ( ( V_139 & V_148 ) >> 9 ) ) ;
V_129 -> V_27 . V_149 = 16 << ( ( V_139 & V_150 ) >> 5 ) ;
V_129 -> V_27 . V_32 = 2 ;
V_129 -> V_27 . V_30 = F_112 ( V_117 / 2 ) ;
V_116 = 1 << ( 10 + ( ( V_139 & V_151 ) >> 6 ) ) ;
V_129 -> V_152 . V_149 = 16 << ( ( V_139 & V_153 ) >> 4 ) ;
V_129 -> V_152 . V_32 = 2 ;
V_129 -> V_152 . V_30 = F_112 ( V_116 / 2 ) ;
break;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
V_117 = 1 << ( 10 + ( ( V_139 & V_148 ) >> 9 ) ) ;
V_129 -> V_27 . V_149 = 16 << ( ( V_139 & V_150 ) >> 5 ) ;
V_129 -> V_27 . V_32 = 1 ;
V_129 -> V_27 . V_30 = 0 ;
V_116 = 1 << ( 10 + ( ( V_139 & V_151 ) >> 6 ) ) ;
V_129 -> V_152 . V_149 = 16 << ( ( V_139 & V_153 ) >> 4 ) ;
V_129 -> V_152 . V_32 = 1 ;
V_129 -> V_152 . V_30 = 0 ;
V_129 -> V_154 |= V_155 ;
break;
case V_175 :
F_100 () ;
V_117 = 1 << ( 12 + ( ( V_139 & V_148 ) >> 9 ) ) ;
V_129 -> V_27 . V_149 = 16 << ( ( V_139 & V_150 ) >> 5 ) ;
V_129 -> V_27 . V_32 = 4 ;
V_129 -> V_27 . V_30 = F_112 ( V_117 / V_129 -> V_27 . V_32 ) ;
V_116 = 1 << ( 12 + ( ( V_139 & V_151 ) >> 6 ) ) ;
V_129 -> V_152 . V_149 = 16 << ( ( V_139 & V_153 ) >> 4 ) ;
V_129 -> V_152 . V_32 = 4 ;
V_129 -> V_152 . V_30 = F_112 ( V_116 / V_129 -> V_152 . V_32 ) ;
V_129 -> V_154 |= V_155 ;
V_129 -> V_154 |= V_158 ;
break;
case V_43 :
V_117 = 1 << ( 12 + ( ( V_139 & V_148 ) >> 9 ) ) ;
V_129 -> V_27 . V_149 = 16 << ( ( V_139 & V_150 ) >> 5 ) ;
if ( V_140 & 0x3 )
V_129 -> V_27 . V_32 = 4 ;
else
V_129 -> V_27 . V_32 = 2 ;
V_129 -> V_27 . V_30 = 0 ;
V_116 = 1 << ( 12 + ( ( V_139 & V_151 ) >> 6 ) ) ;
V_129 -> V_152 . V_149 = 16 << ( ( V_139 & V_153 ) >> 4 ) ;
if ( V_140 & 0x3 )
V_129 -> V_152 . V_32 = 4 ;
else
V_129 -> V_152 . V_32 = 2 ;
V_129 -> V_152 . V_30 = 0 ;
break;
case V_80 :
V_142 = F_114 () ;
V_143 = ( V_142 >> 19 ) & 7 ;
if ( V_143 )
V_129 -> V_27 . V_149 = 2 << V_143 ;
else
V_129 -> V_27 . V_149 = 0 ;
V_129 -> V_27 . V_176 = 64 << ( ( V_142 >> 22 ) & 7 ) ;
V_129 -> V_27 . V_32 = 1 + ( ( V_142 >> 16 ) & 7 ) ;
V_117 = V_129 -> V_27 . V_176 *
V_129 -> V_27 . V_32 *
V_129 -> V_27 . V_149 ;
V_129 -> V_27 . V_30 = 0 ;
V_143 = ( V_142 >> 10 ) & 7 ;
if ( V_143 )
V_129 -> V_152 . V_149 = 2 << V_143 ;
else
V_129 -> V_152 . V_149 = 0 ;
V_129 -> V_152 . V_176 = 64 << ( ( V_142 >> 13 ) & 7 ) ;
V_129 -> V_152 . V_32 = 1 + ( ( V_142 >> 7 ) & 7 ) ;
V_116 = V_129 -> V_152 . V_176 *
V_129 -> V_152 . V_32 *
V_129 -> V_152 . V_149 ;
V_129 -> V_152 . V_30 = 0 ;
break;
case V_177 :
V_129 -> V_27 . V_149 = 128 ;
V_129 -> V_27 . V_176 = 16 ;
V_129 -> V_27 . V_32 = 8 ;
V_129 -> V_27 . V_22 |= V_178 ;
V_117 = V_129 -> V_27 . V_176 * V_129 -> V_27 . V_32 * V_129 -> V_27 . V_149 ;
V_129 -> V_152 . V_149 = 128 ;
V_129 -> V_152 . V_32 = 8 ;
V_129 -> V_152 . V_176 = 8 ;
V_116 = V_129 -> V_152 . V_176 * V_129 -> V_152 . V_32 * V_129 -> V_152 . V_149 ;
V_129 -> V_154 |= V_158 ;
break;
default:
if ( ! ( V_139 & V_179 ) )
F_115 ( L_1 ) ;
V_142 = F_114 () ;
V_143 = ( V_142 >> 19 ) & 7 ;
if ( V_143 == 7 )
F_115 ( L_2 ) ;
V_129 -> V_27 . V_149 = V_143 ? 2 << V_143 : 0 ;
V_129 -> V_27 . V_176 = 32 << ( ( ( V_142 >> 22 ) + 1 ) & 7 ) ;
V_129 -> V_27 . V_32 = 1 + ( ( V_142 >> 16 ) & 7 ) ;
V_117 = V_129 -> V_27 . V_176 *
V_129 -> V_27 . V_32 *
V_129 -> V_27 . V_149 ;
V_129 -> V_27 . V_30 = F_112 ( V_117 / V_129 -> V_27 . V_32 ) ;
if ( V_139 & 0x8 )
V_129 -> V_27 . V_22 |= V_178 ;
V_129 -> V_152 . V_22 = 0 ;
V_143 = ( V_142 >> 10 ) & 7 ;
if ( V_143 == 7 )
F_115 ( L_3 ) ;
V_129 -> V_152 . V_149 = V_143 ? 2 << V_143 : 0 ;
V_129 -> V_152 . V_176 = 32 << ( ( ( V_142 >> 13 ) + 1 ) & 7 ) ;
V_129 -> V_152 . V_32 = 1 + ( ( V_142 >> 7 ) & 7 ) ;
V_116 = V_129 -> V_152 . V_176 *
V_129 -> V_152 . V_32 *
V_129 -> V_152 . V_149 ;
V_129 -> V_152 . V_30 = F_112 ( V_116 / V_129 -> V_152 . V_32 ) ;
V_129 -> V_154 |= V_158 ;
break;
}
if ( ( V_140 & V_132 ) == V_180 &&
( V_140 & V_134 ) < V_181 &&
! ( V_139 & V_182 ) && V_129 -> V_27 . V_149 != 16 &&
V_39 <= 0x8000 )
F_115 ( L_4 ) ;
V_129 -> V_27 . V_28 = V_117 / V_129 -> V_27 . V_32 ;
V_129 -> V_152 . V_28 = V_116 / V_129 -> V_152 . V_32 ;
V_129 -> V_27 . V_176 = V_129 -> V_27 . V_149 ?
V_117 / ( V_129 -> V_27 . V_149 * V_129 -> V_27 . V_32 ) : 0 ;
V_129 -> V_152 . V_176 = V_129 -> V_152 . V_149 ?
V_116 / ( V_129 -> V_152 . V_149 * V_129 -> V_152 . V_32 ) : 0 ;
switch ( F_30 () ) {
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
V_129 -> V_152 . V_22 |= V_188 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
break;
case V_189 :
case V_190 :
V_141 = F_103 ( V_129 ) ;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
if ( ! ( F_116 () & V_201 ) &&
( V_129 -> V_27 . V_28 > V_39 ) )
V_129 -> V_27 . V_22 |= V_202 ;
if ( ! V_141 && ( F_116 () & V_203 ) ) {
V_129 -> V_152 . V_22 |= V_188 ;
break;
}
default:
if ( V_141 || V_129 -> V_152 . V_28 > V_39 )
V_129 -> V_152 . V_22 |= V_202 ;
}
switch ( F_30 () ) {
case V_183 :
V_129 -> V_27 . V_22 |= V_178 ;
break;
case V_204 :
V_129 -> V_27 . V_22 |= V_205 ;
break;
case V_43 :
V_129 -> V_27 . V_32 = 1 ;
}
F_117 ( L_5 ,
V_117 >> 10 ,
V_129 -> V_27 . V_22 & V_178 ? L_6 : L_7 ,
V_206 [ V_129 -> V_27 . V_32 ] , V_129 -> V_27 . V_149 ) ;
F_117 ( L_8 ,
V_116 >> 10 , V_206 [ V_129 -> V_152 . V_32 ] ,
( V_129 -> V_152 . V_22 & V_188 ) ? L_9 : L_7 ,
( V_129 -> V_152 . V_22 & V_202 ) ?
L_10 : L_11 ,
V_129 -> V_152 . V_149 ) ;
}
static int F_118 ( void )
{
unsigned long V_22 , V_3 , V_207 , V_25 , V_208 ;
unsigned int V_139 = F_110 () ;
struct V_128 * V_129 = & V_26 ;
if ( V_139 & V_182 )
return 0 ;
V_207 = ( unsigned long ) & V_209 ;
V_207 &= ~ ( ( 4 * 1024 * 1024 ) - 1 ) ;
V_25 = V_207 + ( 4 * 1024 * 1024 ) ;
F_20 ( V_22 ) ;
V_208 = ( 64 * 1024 ) ;
for ( V_3 = V_207 ; V_3 < V_25 ; V_3 = ( V_207 + V_208 ) ) {
unsigned long * V_210 = ( unsigned long * ) V_3 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_208 <<= 1 ;
}
F_101 ( 0 ) ;
F_102 ( 0 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
F_119 ( V_211 , V_207 ) ;
F_119 ( V_212 , V_207 ) ;
F_119 ( V_213 , V_207 ) ;
V_208 = ( 128 * 1024 ) ;
for ( V_3 = V_207 + ( 128 * 1024 ) ; V_3 < V_25 ; V_3 = V_207 + V_208 ) {
F_119 ( V_214 , V_3 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
if ( ! F_120 () )
break;
V_208 <<= 1 ;
}
F_22 ( V_22 ) ;
V_3 -= V_207 ;
V_64 = V_3 ;
V_129 -> V_215 . V_149 = 16 << ( ( V_139 & V_216 ) >> 22 ) ;
V_129 -> V_215 . V_32 = 1 ;
V_129 -> V_215 . V_30 = 0 ;
return 1 ;
}
static void T_5 F_121 ( void )
{
struct V_128 * V_129 = & V_26 ;
V_64 = 512 * 1024 ;
V_129 -> V_215 . V_149 = 32 ;
V_129 -> V_215 . V_32 = 4 ;
V_129 -> V_215 . V_30 = 0 ;
V_129 -> V_215 . V_28 = V_64 / ( V_129 -> V_215 . V_32 ) ;
V_129 -> V_215 . V_176 = V_64 / ( V_129 -> V_215 . V_149 * V_129 -> V_215 . V_32 ) ;
F_122 ( L_12 ,
V_64 >> 10 , V_206 [ V_129 -> V_215 . V_32 ] , V_129 -> V_215 . V_149 ) ;
V_129 -> V_154 |= V_217 ;
}
static void T_5 F_123 ( void )
{
struct V_128 * V_129 = & V_26 ;
unsigned int V_218 , V_143 ;
V_218 = F_124 () ;
V_143 = ( V_218 >> 4 ) & 15 ;
if ( V_143 )
V_129 -> V_215 . V_149 = 2 << V_143 ;
else
V_129 -> V_215 . V_149 = 0 ;
V_129 -> V_215 . V_176 = 64 << ( ( V_218 >> 8 ) & 15 ) ;
V_129 -> V_215 . V_32 = 1 + ( V_218 & 15 ) ;
V_64 = V_129 -> V_215 . V_176 *
V_129 -> V_215 . V_32 *
V_129 -> V_215 . V_149 ;
V_64 *= 4 ;
V_129 -> V_215 . V_30 = 0 ;
F_122 ( L_12 ,
V_64 >> 10 , V_206 [ V_129 -> V_215 . V_32 ] , V_129 -> V_215 . V_149 ) ;
if ( V_64 )
V_129 -> V_154 |= V_217 ;
return;
}
static void F_125 ( void )
{
struct V_128 * V_129 = & V_26 ;
unsigned int V_139 = F_110 () ;
int V_219 = 0 ;
switch ( F_30 () ) {
case V_81 :
case V_82 :
case V_83 :
case V_84 :
V_219 = F_126 ( F_118 ) ;
if ( V_219 )
V_129 -> V_154 |= V_220 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_64 = 0x80000 << ( ( V_139 & V_221 ) >> 16 ) ;
V_129 -> V_215 . V_149 = 64 << ( ( V_139 >> 13 ) & 1 ) ;
V_129 -> V_215 . V_32 = 2 ;
V_129 -> V_215 . V_30 = 0 ;
V_219 = 1 ;
break;
case V_146 :
case V_147 :
#ifdef F_127
F_128 () ;
#endif
return;
case V_175 :
#ifdef F_129
F_130 () ;
#endif
return;
case V_43 :
F_121 () ;
return;
case V_80 :
F_123 () ;
return;
case V_177 :
case V_222 :
return;
default:
if ( V_129 -> V_223 & ( V_224 | V_225 |
V_226 | V_227 |
V_228 | V_229 ) ) {
#ifdef F_131
if ( F_132 () ) {
V_64 = V_129 -> V_215 . V_32 * V_129 -> V_215 . V_176 * V_129 -> V_215 . V_149 ;
F_117 ( L_13 ,
V_64 >> 10 ,
V_206 [ V_129 -> V_215 . V_32 ] , V_129 -> V_215 . V_149 ) ;
}
#else
if ( ! ( V_129 -> V_215 . V_22 & V_230 ) )
F_115 ( L_14 ) ;
#endif
return;
}
V_219 = 0 ;
}
if ( ! V_219 )
return;
V_129 -> V_215 . V_28 = V_64 / V_129 -> V_215 . V_32 ;
V_129 -> V_215 . V_176 = V_64 / ( V_129 -> V_215 . V_149 * V_129 -> V_215 . V_32 ) ;
F_117 ( L_12 ,
V_64 >> 10 , V_206 [ V_129 -> V_215 . V_32 ] , V_129 -> V_215 . V_149 ) ;
V_129 -> V_154 |= V_217 ;
}
void F_133 ( void )
{
switch ( F_111 () ) {
case 0x00030100 :
case 0x00030201 :
case 0x00030202 :
case 0x01030200 :
case 0x02030200 :
case 0x02030201 :
case 0x02030202 :
F_134 ( 1 << 19 ) ;
break;
}
}
static void F_135 ( void )
{
unsigned long V_231 ;
V_231 = F_110 () ;
V_231 &= ~ ( 0x7 | ( 7 << 25 ) | ( 7 << 28 ) ) ;
V_231 |= ( ( ( V_232 >> V_233 ) << 0 ) |
( ( V_232 >> V_233 ) << 25 ) |
( ( V_232 >> V_233 ) << 28 ) ) ;
F_113 ( V_231 ) ;
F_136 () ;
}
static int T_5 F_137 ( char * V_234 )
{
F_138 ( & V_234 , & V_235 ) ;
return 0 ;
}
static void F_139 ( void )
{
if ( V_235 < 0 || V_235 > 7 )
V_235 = F_110 () & V_236 ;
V_232 = V_235 << V_233 ;
F_140 ( L_15 , V_235 ) ;
F_141 ( V_236 , V_235 ) ;
switch ( F_30 () ) {
case V_160 :
case V_81 :
case V_82 :
case V_161 :
case V_83 :
case V_84 :
F_142 ( V_237 ) ;
break;
case V_204 :
F_133 () ;
break;
case V_238 :
F_135 () ;
break;
}
}
static void F_143 ( void )
{
extern char __weak V_239 ;
extern char __weak V_240 ;
switch ( F_30 () ) {
case V_185 :
case V_186 :
F_144 ( 0x100 , & V_240 , 0x80 ) ;
break;
default:
F_144 ( 0x100 , & V_239 , 0x80 ) ;
break;
}
}
void F_145 ( void )
{
extern void V_241 ( void ) ;
extern void V_242 ( void ) ;
struct V_128 * V_129 = & V_26 ;
F_109 () ;
F_125 () ;
F_14 () ;
F_17 () ;
F_18 () ;
F_28 () ;
F_32 () ;
F_34 () ;
F_35 () ;
F_37 () ;
F_38 () ;
#ifdef F_76
F_16 () ;
F_31 () ;
#endif
if ( V_129 -> V_152 . V_149 )
V_243 = F_146 ( unsigned long,
c->dcache.sets * c->dcache.linesz - 1 ,
PAGE_SIZE - 1 ) ;
else
V_243 = V_39 - 1 ;
V_244 = F_46 ;
V_245 = F_47 ;
V_246 = F_7 ;
V_247 = F_40 ;
V_248 = F_51 ;
V_249 = F_67 ;
V_250 = F_49 ;
V_251 = F_99 ;
V_252 = F_96 ;
V_253 = F_97 ;
V_254 = F_68 ;
V_255 = F_69 ;
V_256 = F_80 ;
V_257 = F_71 ;
#if F_147 ( V_258 ) || F_147 ( V_259 )
if ( V_260 ) {
V_261 = ( void * ) F_7 ;
V_262 = ( void * ) F_7 ;
V_263 = ( void * ) F_7 ;
} else {
V_261 = F_82 ;
V_262 = F_82 ;
V_263 = F_86 ;
}
#endif
V_241 () ;
V_242 () ;
F_39 ( NULL ) ;
F_139 () ;
V_264 = F_143 ;
switch ( F_30 () ) {
case V_265 :
case V_266 :
V_255 = V_6 ;
break;
case V_267 :
if ( V_129 -> V_215 . V_22 & V_230 )
break;
V_249 = ( void * ) F_108 ;
V_250 = ( void * ) F_108 ;
V_252 = ( void * ) F_108 ;
V_254 = ( void * ) F_108 ;
V_255 = ( void * ) F_108 ;
V_256 = ( void * ) F_108 ;
V_257 = ( void * ) F_108 ;
V_26 . V_152 . V_22 &= ~ V_202 ;
V_26 . V_154 |= V_217 ;
break;
}
}
static int F_148 ( struct V_268 * V_269 , unsigned long V_270 ,
void * V_271 )
{
switch ( V_270 ) {
case V_272 :
case V_273 :
F_139 () ;
break;
}
return V_274 ;
}
int T_5 F_149 ( void )
{
return F_150 ( & V_275 ) ;
}
