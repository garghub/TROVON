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
case V_89 :
V_75 () ;
F_40 () ;
break;
default:
V_17 () ;
V_58 () ;
break;
}
}
static void F_41 ( void )
{
F_1 ( F_39 , NULL ) ;
}
static inline int F_42 ( const struct V_90 * V_91 )
{
#ifdef F_43
int V_92 ;
F_44 (i)
if ( F_45 ( V_92 , V_91 ) )
return 1 ;
return 0 ;
#else
return F_45 ( F_46 () , V_91 ) ;
#endif
}
static void F_47 ( void )
{
V_17 () ;
}
static void F_48 ( void )
{
V_17 () ;
}
static inline void F_49 ( void * args )
{
struct V_93 * V_94 = args ;
int V_95 = V_94 -> V_96 & V_97 ;
if ( ! ( F_42 ( V_94 -> V_98 ) ) )
return;
if ( V_99 || ( V_95 && ! V_100 ) )
V_17 () ;
if ( V_95 )
V_58 () ;
}
static void F_50 ( struct V_93 * V_94 ,
unsigned long V_23 , unsigned long V_25 )
{
int V_95 = V_94 -> V_96 & V_97 ;
if ( V_99 || V_95 )
F_1 ( F_49 , V_94 ) ;
}
static inline void F_51 ( void * args )
{
struct V_90 * V_91 = args ;
if ( ! F_42 ( V_91 ) )
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
static void F_52 ( struct V_90 * V_91 )
{
if ( ! V_99 )
return;
F_1 ( F_51 , V_91 ) ;
}
static inline void F_53 ( void * args )
{
struct V_101 * V_102 = args ;
struct V_93 * V_94 = V_102 -> V_94 ;
unsigned long V_3 = V_102 -> V_3 ;
struct V_37 * V_37 = F_54 ( V_102 -> V_103 ) ;
int V_95 = V_94 -> V_96 & V_97 ;
struct V_90 * V_91 = V_94 -> V_98 ;
int V_104 = 0 ;
T_1 * V_105 ;
T_2 * V_106 ;
T_3 * V_107 ;
T_4 * V_108 ;
void * V_109 ;
if ( ! F_42 ( V_91 ) )
return;
V_3 &= V_110 ;
V_105 = F_55 ( V_91 , V_3 ) ;
V_106 = F_56 ( V_105 , V_3 ) ;
V_107 = F_57 ( V_106 , V_3 ) ;
V_108 = F_58 ( V_107 , V_3 ) ;
if ( ! ( F_59 ( * V_108 ) ) )
return;
if ( ( V_91 == V_111 -> V_112 ) && ( F_60 ( * V_108 ) & V_113 ) )
V_109 = NULL ;
else {
V_104 = ( V_99 &&
F_61 ( V_37 ) &&
! F_62 ( V_37 ) ) ;
if ( V_104 )
V_109 = F_63 ( V_37 , V_3 ) ;
else
V_109 = F_64 ( V_37 ) ;
V_3 = ( unsigned long ) V_109 ;
}
if ( V_99 || ( V_95 && ! V_100 ) ) {
V_109 ? V_6 ( V_3 ) :
V_8 ( V_3 ) ;
if ( V_95 && ! V_114 )
V_65 ( V_3 ) ;
}
if ( V_95 ) {
if ( V_109 && V_115 && V_91 == V_111 -> V_112 ) {
int V_116 = F_46 () ;
if ( F_45 ( V_116 , V_91 ) != 0 )
F_65 ( V_91 , V_116 ) ;
} else
V_109 ? V_41 ( V_3 ) :
V_48 ( V_3 ) ;
}
if ( V_109 ) {
if ( V_104 )
F_66 () ;
else
F_67 ( V_109 ) ;
}
}
static void F_68 ( struct V_93 * V_94 ,
unsigned long V_3 , unsigned long V_103 )
{
struct V_101 args ;
args . V_94 = V_94 ;
args . V_3 = V_3 ;
args . V_103 = V_103 ;
F_1 ( F_53 , & args ) ;
}
static inline void F_69 ( void * V_3 )
{
V_6 ( ( unsigned long ) V_3 ) ;
}
static void F_70 ( unsigned long V_3 )
{
if ( F_71 () )
F_69 ( ( void * ) V_3 ) ;
else
F_1 ( F_69 , ( void * ) V_3 ) ;
}
static inline void F_72 ( unsigned long V_23 , unsigned long V_25 )
{
if ( ! V_100 ) {
if ( V_25 - V_23 >= V_117 ) {
V_17 () ;
} else {
V_4 ;
F_73 ( V_23 , V_25 ) ;
}
}
if ( V_25 - V_23 > V_118 )
V_58 () ;
else {
switch ( F_74 () ) {
case V_43 :
F_75 ( V_23 , V_25 ) ;
break;
default:
F_76 ( V_23 , V_25 ) ;
break;
}
}
#ifdef F_77
F_78 ( V_23 , ( V_25 - V_23 ) ) ;
F_40 () ;
#endif
}
static inline void F_79 ( void * args )
{
struct V_119 * V_120 = args ;
unsigned long V_23 = V_120 -> V_23 ;
unsigned long V_25 = V_120 -> V_25 ;
F_72 ( V_23 , V_25 ) ;
}
static void F_80 ( unsigned long V_23 , unsigned long V_25 )
{
struct V_119 args ;
args . V_23 = V_23 ;
args . V_25 = V_25 ;
F_1 ( F_79 , & args ) ;
F_81 () ;
}
static void F_82 ( unsigned long V_3 , unsigned long V_121 )
{
F_83 ( V_121 == 0 ) ;
F_3 () ;
if ( V_122 ) {
if ( V_121 >= V_64 )
V_75 () ;
else
F_84 ( V_3 , V_3 + V_121 ) ;
F_6 () ;
F_40 () ;
return;
}
if ( V_123 && V_121 >= V_117 ) {
V_17 () ;
} else {
V_4 ;
F_85 ( V_3 , V_3 + V_121 ) ;
}
F_6 () ;
F_78 ( V_3 , V_121 ) ;
F_40 () ;
}
static void F_86 ( unsigned long V_3 , unsigned long V_121 )
{
F_83 ( V_121 == 0 ) ;
F_3 () ;
if ( V_122 ) {
if ( V_121 >= V_64 )
V_75 () ;
else {
F_87 ( V_3 , V_3 + V_121 ) ;
}
F_6 () ;
F_40 () ;
return;
}
if ( V_123 && V_121 >= V_117 ) {
V_17 () ;
} else {
V_4 ;
F_88 ( V_3 , V_3 + V_121 ) ;
}
F_6 () ;
F_89 ( V_3 , V_121 ) ;
F_40 () ;
}
static void F_90 ( void * V_124 )
{
unsigned long V_40 = F_29 () ;
unsigned long V_5 = F_15 () ;
unsigned long V_63 = F_36 () ;
unsigned long V_3 = ( unsigned long ) V_124 ;
V_4 ;
if ( V_5 )
F_91 ( V_3 & ~ ( V_5 - 1 ) ) ;
if ( ! V_114 && V_64 )
F_92 ( V_3 & ~ ( V_63 - 1 ) ) ;
if ( V_40 )
F_93 ( V_3 & ~ ( V_40 - 1 ) ) ;
if ( V_125 ) {
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
if ( V_126 )
__asm__ __volatile__ ("sync");
}
static void F_96 ( unsigned long V_3 )
{
F_1 ( F_90 , ( void * ) V_3 ) ;
}
static void F_97 ( void )
{
if ( V_115 )
V_58 () ;
}
static inline void F_98 ( void * args )
{
struct V_127 * V_128 = args ;
unsigned long V_109 = V_128 -> V_109 ;
int V_121 = V_128 -> V_121 ;
if ( V_123 && V_121 >= V_117 )
V_17 () ;
else {
V_4 ;
F_85 ( V_109 , V_109 + V_121 ) ;
}
}
static void F_99 ( unsigned long V_109 , int V_121 )
{
struct V_127 args ;
args . V_109 = ( unsigned long ) V_109 ;
args . V_121 = V_121 ;
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
static inline int F_103 ( struct V_129 * V_130 )
{
unsigned int V_131 = V_130 -> V_132 & V_133 ;
unsigned int V_134 = V_130 -> V_132 & V_135 ;
int V_136 = 0 ;
switch ( V_131 ) {
case V_137 :
if ( V_134 <= F_104 ( 2 , 4 , 0 ) )
V_136 = 1 ;
if ( V_134 == F_104 ( 2 , 4 , 0 ) )
F_105 ( F_106 () | V_138 ) ;
break;
case V_139 :
if ( V_134 <= F_104 ( 1 , 1 , 0 ) ) {
V_136 = 1 ;
F_105 ( F_106 () | V_138 ) ;
}
break;
default:
F_107 () ;
}
return V_136 ;
}
static void F_108 ( void )
{
F_40 () ;
F_40 () ;
__asm__ __volatile__(
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
: : : "memory");
}
static void F_109 ( void )
{
struct V_129 * V_130 = & V_26 ;
unsigned int V_140 = F_110 () ;
unsigned int V_141 = F_111 () ;
int V_142 = 0 ;
unsigned long V_143 ;
unsigned int V_144 ;
switch ( F_30 () ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_118 = 1 << ( 12 + ( ( V_140 & V_149 ) >> 9 ) ) ;
V_130 -> V_27 . V_150 = 16 << ( ( V_140 & V_151 ) >> 5 ) ;
V_130 -> V_27 . V_32 = 2 ;
V_130 -> V_27 . V_30 = F_112 ( V_118 / 2 ) ;
V_117 = 1 << ( 12 + ( ( V_140 & V_152 ) >> 6 ) ) ;
V_130 -> V_153 . V_150 = 16 << ( ( V_140 & V_154 ) >> 4 ) ;
V_130 -> V_153 . V_32 = 2 ;
V_130 -> V_153 . V_30 = F_112 ( V_117 / 2 ) ;
V_130 -> V_155 |= V_156 ;
break;
case V_157 :
case V_158 :
V_118 = 1 << ( 12 + ( ( V_140 & V_149 ) >> 9 ) ) ;
V_130 -> V_27 . V_150 = 16 << ( ( V_140 & V_151 ) >> 5 ) ;
V_130 -> V_27 . V_32 = 2 ;
V_130 -> V_27 . V_30 = 0 ;
V_117 = 1 << ( 12 + ( ( V_140 & V_152 ) >> 6 ) ) ;
V_130 -> V_153 . V_150 = 16 << ( ( V_140 & V_154 ) >> 4 ) ;
V_130 -> V_153 . V_32 = 2 ;
V_130 -> V_153 . V_30 = 0 ;
V_130 -> V_155 |= V_156 | V_159 ;
break;
case V_160 :
V_118 = 1 << ( 12 + ( ( V_140 & V_149 ) >> 9 ) ) ;
V_130 -> V_27 . V_150 = 16 << ( ( V_140 & V_151 ) >> 5 ) ;
V_130 -> V_27 . V_32 = 4 ;
V_130 -> V_27 . V_30 = 0 ;
V_117 = 1 << ( 12 + ( ( V_140 & V_152 ) >> 6 ) ) ;
V_130 -> V_153 . V_150 = 16 << ( ( V_140 & V_154 ) >> 4 ) ;
V_130 -> V_153 . V_32 = 4 ;
V_130 -> V_153 . V_30 = 0 ;
V_130 -> V_155 |= V_156 ;
V_130 -> V_155 |= V_159 ;
break;
case V_161 :
case V_81 :
case V_82 :
case V_162 :
case V_83 :
case V_84 :
case V_163 :
V_118 = 1 << ( 12 + ( ( V_140 & V_149 ) >> 9 ) ) ;
V_130 -> V_27 . V_150 = 16 << ( ( V_140 & V_151 ) >> 5 ) ;
V_130 -> V_27 . V_32 = 1 ;
V_130 -> V_27 . V_30 = 0 ;
V_117 = 1 << ( 12 + ( ( V_140 & V_152 ) >> 6 ) ) ;
V_130 -> V_153 . V_150 = 16 << ( ( V_140 & V_154 ) >> 4 ) ;
V_130 -> V_153 . V_32 = 1 ;
V_130 -> V_153 . V_30 = 0 ;
V_130 -> V_155 |= V_156 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_118 = 1 << ( 12 + ( ( V_140 & V_164 ) >> 29 ) ) ;
V_130 -> V_27 . V_150 = 64 ;
V_130 -> V_27 . V_32 = 2 ;
V_130 -> V_27 . V_30 = 0 ;
V_117 = 1 << ( 12 + ( ( V_140 & V_165 ) >> 26 ) ) ;
V_130 -> V_153 . V_150 = 32 ;
V_130 -> V_153 . V_32 = 2 ;
V_130 -> V_153 . V_30 = 0 ;
V_130 -> V_155 |= V_159 ;
break;
case V_166 :
F_113 ( V_140 & ~ V_167 ) ;
case V_168 :
if ( V_130 -> V_132 == 0x0c80U || V_130 -> V_132 == 0x0c81U ||
V_130 -> V_132 == 0x0c82U ) {
V_140 |= 0x00400000U ;
if ( V_130 -> V_132 == 0x0c80U )
V_140 |= V_169 ;
F_113 ( V_140 ) ;
} else
V_130 -> V_155 |= V_156 ;
V_118 = 1 << ( 10 + ( ( V_140 & V_149 ) >> 9 ) ) ;
V_130 -> V_27 . V_150 = 16 << ( ( V_140 & V_151 ) >> 5 ) ;
V_130 -> V_27 . V_32 = 2 ;
V_130 -> V_27 . V_30 = F_112 ( V_118 / 2 ) ;
V_117 = 1 << ( 10 + ( ( V_140 & V_152 ) >> 6 ) ) ;
V_130 -> V_153 . V_150 = 16 << ( ( V_140 & V_154 ) >> 4 ) ;
V_130 -> V_153 . V_32 = 2 ;
V_130 -> V_153 . V_30 = F_112 ( V_117 / 2 ) ;
break;
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
V_118 = 1 << ( 10 + ( ( V_140 & V_149 ) >> 9 ) ) ;
V_130 -> V_27 . V_150 = 16 << ( ( V_140 & V_151 ) >> 5 ) ;
V_130 -> V_27 . V_32 = 1 ;
V_130 -> V_27 . V_30 = 0 ;
V_117 = 1 << ( 10 + ( ( V_140 & V_152 ) >> 6 ) ) ;
V_130 -> V_153 . V_150 = 16 << ( ( V_140 & V_154 ) >> 4 ) ;
V_130 -> V_153 . V_32 = 1 ;
V_130 -> V_153 . V_30 = 0 ;
V_130 -> V_155 |= V_156 ;
break;
case V_176 :
F_100 () ;
V_118 = 1 << ( 12 + ( ( V_140 & V_149 ) >> 9 ) ) ;
V_130 -> V_27 . V_150 = 16 << ( ( V_140 & V_151 ) >> 5 ) ;
V_130 -> V_27 . V_32 = 4 ;
V_130 -> V_27 . V_30 = F_112 ( V_118 / V_130 -> V_27 . V_32 ) ;
V_117 = 1 << ( 12 + ( ( V_140 & V_152 ) >> 6 ) ) ;
V_130 -> V_153 . V_150 = 16 << ( ( V_140 & V_154 ) >> 4 ) ;
V_130 -> V_153 . V_32 = 4 ;
V_130 -> V_153 . V_30 = F_112 ( V_117 / V_130 -> V_153 . V_32 ) ;
V_130 -> V_155 |= V_156 ;
V_130 -> V_155 |= V_159 ;
break;
case V_43 :
V_118 = 1 << ( 12 + ( ( V_140 & V_149 ) >> 9 ) ) ;
V_130 -> V_27 . V_150 = 16 << ( ( V_140 & V_151 ) >> 5 ) ;
if ( V_141 & 0x3 )
V_130 -> V_27 . V_32 = 4 ;
else
V_130 -> V_27 . V_32 = 2 ;
V_130 -> V_27 . V_30 = 0 ;
V_117 = 1 << ( 12 + ( ( V_140 & V_152 ) >> 6 ) ) ;
V_130 -> V_153 . V_150 = 16 << ( ( V_140 & V_154 ) >> 4 ) ;
if ( V_141 & 0x3 )
V_130 -> V_153 . V_32 = 4 ;
else
V_130 -> V_153 . V_32 = 2 ;
V_130 -> V_153 . V_30 = 0 ;
break;
case V_80 :
V_143 = F_114 () ;
V_144 = ( V_143 >> 19 ) & 7 ;
if ( V_144 )
V_130 -> V_27 . V_150 = 2 << V_144 ;
else
V_130 -> V_27 . V_150 = 0 ;
V_130 -> V_27 . V_177 = 64 << ( ( V_143 >> 22 ) & 7 ) ;
V_130 -> V_27 . V_32 = 1 + ( ( V_143 >> 16 ) & 7 ) ;
V_118 = V_130 -> V_27 . V_177 *
V_130 -> V_27 . V_32 *
V_130 -> V_27 . V_150 ;
V_130 -> V_27 . V_30 = 0 ;
V_144 = ( V_143 >> 10 ) & 7 ;
if ( V_144 )
V_130 -> V_153 . V_150 = 2 << V_144 ;
else
V_130 -> V_153 . V_150 = 0 ;
V_130 -> V_153 . V_177 = 64 << ( ( V_143 >> 13 ) & 7 ) ;
V_130 -> V_153 . V_32 = 1 + ( ( V_143 >> 7 ) & 7 ) ;
V_117 = V_130 -> V_153 . V_177 *
V_130 -> V_153 . V_32 *
V_130 -> V_153 . V_150 ;
V_130 -> V_153 . V_30 = 0 ;
if ( ( V_141 & V_135 ) >= V_178 )
V_130 -> V_155 |= V_159 ;
break;
case V_179 :
V_130 -> V_27 . V_150 = 128 ;
V_130 -> V_27 . V_177 = 16 ;
V_130 -> V_27 . V_32 = 8 ;
V_130 -> V_27 . V_22 |= V_180 ;
V_118 = V_130 -> V_27 . V_177 * V_130 -> V_27 . V_32 * V_130 -> V_27 . V_150 ;
V_130 -> V_153 . V_150 = 128 ;
V_130 -> V_153 . V_32 = 8 ;
V_130 -> V_153 . V_177 = 8 ;
V_117 = V_130 -> V_153 . V_177 * V_130 -> V_153 . V_32 * V_130 -> V_153 . V_150 ;
V_130 -> V_155 |= V_159 ;
break;
default:
if ( ! ( V_140 & V_181 ) )
F_115 ( L_1 ) ;
V_143 = F_114 () ;
V_144 = ( V_143 >> 19 ) & 7 ;
if ( V_144 == 7 )
F_115 ( L_2 ) ;
V_130 -> V_27 . V_150 = V_144 ? 2 << V_144 : 0 ;
V_130 -> V_27 . V_177 = 32 << ( ( ( V_143 >> 22 ) + 1 ) & 7 ) ;
V_130 -> V_27 . V_32 = 1 + ( ( V_143 >> 16 ) & 7 ) ;
V_118 = V_130 -> V_27 . V_177 *
V_130 -> V_27 . V_32 *
V_130 -> V_27 . V_150 ;
V_130 -> V_27 . V_30 = F_112 ( V_118 / V_130 -> V_27 . V_32 ) ;
if ( V_140 & 0x8 )
V_130 -> V_27 . V_22 |= V_180 ;
V_130 -> V_153 . V_22 = 0 ;
V_144 = ( V_143 >> 10 ) & 7 ;
if ( V_144 == 7 )
F_115 ( L_3 ) ;
V_130 -> V_153 . V_150 = V_144 ? 2 << V_144 : 0 ;
V_130 -> V_153 . V_177 = 32 << ( ( ( V_143 >> 13 ) + 1 ) & 7 ) ;
V_130 -> V_153 . V_32 = 1 + ( ( V_143 >> 7 ) & 7 ) ;
V_117 = V_130 -> V_153 . V_177 *
V_130 -> V_153 . V_32 *
V_130 -> V_153 . V_150 ;
V_130 -> V_153 . V_30 = F_112 ( V_117 / V_130 -> V_153 . V_32 ) ;
V_130 -> V_155 |= V_159 ;
break;
}
if ( ( V_141 & V_133 ) == V_182 &&
( V_141 & V_135 ) < V_183 &&
! ( V_140 & V_184 ) && V_130 -> V_27 . V_150 != 16 &&
V_39 <= 0x8000 )
F_115 ( L_4 ) ;
V_130 -> V_27 . V_28 = V_118 / V_130 -> V_27 . V_32 ;
V_130 -> V_153 . V_28 = V_117 / V_130 -> V_153 . V_32 ;
V_130 -> V_27 . V_177 = V_130 -> V_27 . V_150 ?
V_118 / ( V_130 -> V_27 . V_150 * V_130 -> V_27 . V_32 ) : 0 ;
V_130 -> V_153 . V_177 = V_130 -> V_153 . V_150 ?
V_117 / ( V_130 -> V_153 . V_150 * V_130 -> V_153 . V_32 ) : 0 ;
switch ( F_30 () ) {
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
V_130 -> V_153 . V_22 |= V_190 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
break;
case V_191 :
case V_192 :
V_142 = F_103 ( V_130 ) ;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
if ( ! ( F_116 () & V_206 ) &&
( V_130 -> V_27 . V_28 > V_39 ) )
V_130 -> V_27 . V_22 |= V_207 ;
if ( ! V_142 && ( F_116 () & V_208 ) ) {
V_130 -> V_153 . V_22 |= V_190 ;
break;
}
default:
if ( V_142 || V_130 -> V_153 . V_28 > V_39 )
V_130 -> V_153 . V_22 |= V_207 ;
}
switch ( F_30 () ) {
case V_185 :
V_130 -> V_27 . V_22 |= V_180 ;
break;
case V_209 :
case V_203 :
V_130 -> V_27 . V_22 |= V_210 ;
break;
case V_89 :
V_130 -> V_27 . V_22 |= V_210 ;
V_130 -> V_153 . V_22 &= ~ V_207 ;
break;
case V_43 :
V_130 -> V_27 . V_32 = 1 ;
}
F_117 ( L_5 ,
V_118 >> 10 ,
V_130 -> V_27 . V_22 & V_180 ? L_6 : L_7 ,
V_211 [ V_130 -> V_27 . V_32 ] , V_130 -> V_27 . V_150 ) ;
F_117 ( L_8 ,
V_117 >> 10 , V_211 [ V_130 -> V_153 . V_32 ] ,
( V_130 -> V_153 . V_22 & V_190 ) ? L_9 : L_7 ,
( V_130 -> V_153 . V_22 & V_207 ) ?
L_10 : L_11 ,
V_130 -> V_153 . V_150 ) ;
}
static void F_118 ( void )
{
struct V_129 * V_130 = & V_26 ;
unsigned int V_212 , V_144 ;
if ( F_30 () != V_80 )
return;
V_212 = F_119 () ;
if ( ( V_144 = ( ( V_212 >> 20 ) & 15 ) ) )
V_130 -> V_213 . V_150 = 2 << V_144 ;
else
V_130 -> V_213 . V_150 = V_144 ;
V_130 -> V_213 . V_177 = 64 << ( ( V_212 >> 24 ) & 15 ) ;
V_130 -> V_213 . V_32 = 1 + ( ( V_212 >> 16 ) & 15 ) ;
V_214 = V_130 -> V_213 . V_177 * V_130 -> V_213 . V_32 * V_130 -> V_213 . V_150 ;
V_130 -> V_213 . V_30 = 0 ;
F_120 ( L_12 ,
V_214 >> 10 , V_211 [ V_130 -> V_213 . V_32 ] , V_130 -> V_213 . V_150 ) ;
}
static int F_121 ( void )
{
unsigned long V_22 , V_3 , V_215 , V_25 , V_216 ;
unsigned int V_140 = F_110 () ;
struct V_129 * V_130 = & V_26 ;
if ( V_140 & V_184 )
return 0 ;
V_215 = ( unsigned long ) & V_217 ;
V_215 &= ~ ( ( 4 * 1024 * 1024 ) - 1 ) ;
V_25 = V_215 + ( 4 * 1024 * 1024 ) ;
F_20 ( V_22 ) ;
V_216 = ( 64 * 1024 ) ;
for ( V_3 = V_215 ; V_3 < V_25 ; V_3 = ( V_215 + V_216 ) ) {
unsigned long * V_218 = ( unsigned long * ) V_3 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_216 <<= 1 ;
}
F_101 ( 0 ) ;
F_102 ( 0 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
F_122 ( V_219 , V_215 ) ;
F_122 ( V_220 , V_215 ) ;
F_122 ( V_221 , V_215 ) ;
V_216 = ( 128 * 1024 ) ;
for ( V_3 = V_215 + ( 128 * 1024 ) ; V_3 < V_25 ; V_3 = V_215 + V_216 ) {
F_122 ( V_222 , V_3 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
if ( ! F_123 () )
break;
V_216 <<= 1 ;
}
F_22 ( V_22 ) ;
V_3 -= V_215 ;
V_64 = V_3 ;
V_130 -> V_223 . V_150 = 16 << ( ( V_140 & V_224 ) >> 22 ) ;
V_130 -> V_223 . V_32 = 1 ;
V_130 -> V_223 . V_30 = 0 ;
return 1 ;
}
static void T_5 F_124 ( void )
{
struct V_129 * V_130 = & V_26 ;
V_64 = 512 * 1024 ;
V_130 -> V_223 . V_150 = 32 ;
V_130 -> V_223 . V_32 = 4 ;
V_130 -> V_223 . V_30 = 0 ;
V_130 -> V_223 . V_28 = V_64 / ( V_130 -> V_223 . V_32 ) ;
V_130 -> V_223 . V_177 = V_64 / ( V_130 -> V_223 . V_150 * V_130 -> V_223 . V_32 ) ;
F_120 ( L_13 ,
V_64 >> 10 , V_211 [ V_130 -> V_223 . V_32 ] , V_130 -> V_223 . V_150 ) ;
V_130 -> V_155 |= V_225 ;
}
static void T_5 F_125 ( void )
{
struct V_129 * V_130 = & V_26 ;
unsigned int V_212 , V_144 ;
V_212 = F_119 () ;
V_144 = ( V_212 >> 4 ) & 15 ;
if ( V_144 )
V_130 -> V_223 . V_150 = 2 << V_144 ;
else
V_130 -> V_223 . V_150 = 0 ;
V_130 -> V_223 . V_177 = 64 << ( ( V_212 >> 8 ) & 15 ) ;
V_130 -> V_223 . V_32 = 1 + ( V_212 & 15 ) ;
V_64 = V_130 -> V_223 . V_177 *
V_130 -> V_223 . V_32 *
V_130 -> V_223 . V_150 ;
V_64 *= 4 ;
V_130 -> V_223 . V_30 = 0 ;
F_120 ( L_13 ,
V_64 >> 10 , V_211 [ V_130 -> V_223 . V_32 ] , V_130 -> V_223 . V_150 ) ;
if ( V_64 )
V_130 -> V_155 |= V_225 ;
return;
}
static void F_126 ( void )
{
struct V_129 * V_130 = & V_26 ;
unsigned int V_140 = F_110 () ;
int V_226 = 0 ;
switch ( F_30 () ) {
case V_81 :
case V_82 :
case V_83 :
case V_84 :
V_226 = F_127 ( F_121 ) ;
if ( V_226 )
V_130 -> V_155 |= V_227 ;
break;
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_64 = 0x80000 << ( ( V_140 & V_228 ) >> 16 ) ;
V_130 -> V_223 . V_150 = 64 << ( ( V_140 >> 13 ) & 1 ) ;
V_130 -> V_223 . V_32 = 2 ;
V_130 -> V_223 . V_30 = 0 ;
V_226 = 1 ;
break;
case V_147 :
case V_148 :
#ifdef F_128
F_129 () ;
#endif
return;
case V_176 :
#ifdef F_130
F_131 () ;
#endif
return;
case V_43 :
F_124 () ;
return;
case V_80 :
F_125 () ;
return;
case V_179 :
case V_229 :
return;
default:
if ( V_130 -> V_230 & ( V_231 | V_232 |
V_233 | V_234 |
V_235 | V_236 ) ) {
#ifdef F_132
if ( F_133 () ) {
V_64 = V_130 -> V_223 . V_32 * V_130 -> V_223 . V_177 * V_130 -> V_223 . V_150 ;
F_117 ( L_14 ,
V_64 >> 10 ,
V_211 [ V_130 -> V_223 . V_32 ] , V_130 -> V_223 . V_150 ) ;
}
#else
if ( ! ( V_130 -> V_223 . V_22 & V_237 ) )
F_115 ( L_15 ) ;
#endif
return;
}
V_226 = 0 ;
}
if ( ! V_226 )
return;
V_130 -> V_223 . V_28 = V_64 / V_130 -> V_223 . V_32 ;
V_130 -> V_223 . V_177 = V_64 / ( V_130 -> V_223 . V_150 * V_130 -> V_223 . V_32 ) ;
F_117 ( L_13 ,
V_64 >> 10 , V_211 [ V_130 -> V_223 . V_32 ] , V_130 -> V_223 . V_150 ) ;
V_130 -> V_155 |= V_225 ;
}
void F_134 ( void )
{
switch ( F_111 () ) {
case 0x00030100 :
case 0x00030201 :
case 0x00030202 :
case 0x01030200 :
case 0x02030200 :
case 0x02030201 :
case 0x02030202 :
F_135 ( 1 << 19 ) ;
break;
}
}
static void F_136 ( void )
{
unsigned long V_238 ;
V_238 = F_110 () ;
V_238 &= ~ ( 0x7 | ( 7 << 25 ) | ( 7 << 28 ) ) ;
V_238 |= ( ( ( V_239 >> V_240 ) << 0 ) |
( ( V_239 >> V_240 ) << 25 ) |
( ( V_239 >> V_240 ) << 28 ) ) ;
F_113 ( V_238 ) ;
F_137 () ;
}
static int T_5 F_138 ( char * V_241 )
{
F_139 ( & V_241 , & V_242 ) ;
return 0 ;
}
static void F_140 ( void )
{
if ( V_242 < 0 || V_242 > 7 )
V_242 = F_110 () & V_243 ;
V_239 = V_242 << V_240 ;
F_141 ( L_16 , V_242 ) ;
F_142 ( V_243 , V_242 ) ;
switch ( F_30 () ) {
case V_161 :
case V_81 :
case V_82 :
case V_162 :
case V_83 :
case V_84 :
F_143 ( V_244 ) ;
break;
case V_209 :
F_134 () ;
break;
case V_245 :
F_136 () ;
break;
}
}
static void F_144 ( void )
{
extern char __weak V_246 ;
extern char __weak V_247 ;
switch ( F_30 () ) {
case V_187 :
case V_188 :
F_145 ( 0x100 , & V_247 , 0x80 ) ;
break;
default:
F_145 ( 0x100 , & V_246 , 0x80 ) ;
break;
}
}
void F_146 ( void )
{
extern void V_248 ( void ) ;
extern void V_249 ( void ) ;
struct V_129 * V_130 = & V_26 ;
F_109 () ;
F_118 () ;
F_126 () ;
F_14 () ;
F_17 () ;
F_18 () ;
F_28 () ;
F_32 () ;
F_34 () ;
F_35 () ;
F_37 () ;
F_38 () ;
#ifdef F_77
F_16 () ;
F_31 () ;
#endif
if ( V_130 -> V_153 . V_150 && V_99 )
V_250 = F_147 ( unsigned long,
c->dcache.sets * c->dcache.linesz - 1 ,
PAGE_SIZE - 1 ) ;
else
V_250 = V_39 - 1 ;
V_251 = F_47 ;
V_252 = F_48 ;
V_253 = F_7 ;
V_254 = F_41 ;
V_255 = F_52 ;
V_256 = F_68 ;
V_257 = F_50 ;
V_258 = F_99 ;
V_259 = F_96 ;
V_260 = F_97 ;
V_261 = F_69 ;
V_262 = F_70 ;
V_263 = F_80 ;
V_264 = F_72 ;
#if F_148 ( V_265 ) || F_148 ( V_266 )
if ( V_267 ) {
V_268 = ( void * ) F_7 ;
V_269 = ( void * ) F_7 ;
V_270 = ( void * ) F_7 ;
} else {
V_268 = F_82 ;
V_269 = F_82 ;
V_270 = F_86 ;
}
#endif
V_248 () ;
V_249 () ;
F_39 ( NULL ) ;
F_140 () ;
V_271 = F_144 ;
switch ( F_30 () ) {
case V_272 :
case V_273 :
V_262 = V_6 ;
break;
case V_89 :
if ( V_130 -> V_223 . V_22 & V_237 )
break;
V_256 = ( void * ) F_108 ;
V_257 = ( void * ) F_108 ;
V_259 = ( void * ) F_108 ;
V_261 = ( void * ) F_108 ;
V_262 = ( void * ) F_108 ;
V_263 = ( void * ) F_108 ;
V_264 = ( void * ) F_108 ;
V_26 . V_155 |= V_225 ;
break;
case V_80 :
V_254 = F_7 ;
V_251 = F_7 ;
V_252 = F_7 ;
V_258 = ( void * ) F_7 ;
V_255 = ( void * ) F_7 ;
V_256 = ( void * ) F_7 ;
V_257 = ( void * ) F_7 ;
V_259 = ( void * ) F_7 ;
V_260 = ( void * ) F_7 ;
V_262 = ( void * ) F_7 ;
V_261 = ( void * ) F_7 ;
break;
}
}
static int F_149 ( struct V_274 * V_275 , unsigned long V_276 ,
void * V_277 )
{
switch ( V_276 ) {
case V_278 :
case V_279 :
F_140 () ;
break;
}
return V_280 ;
}
int T_5 F_150 ( void )
{
return F_151 ( & V_281 ) ;
}
