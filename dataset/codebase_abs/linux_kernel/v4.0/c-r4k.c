static inline void F_1 ( void (* F_2) ( void * V_1 ) , void * V_1 )
{
F_3 () ;
#ifndef F_4
F_5 ( F_2 , V_1 , 1 ) ;
#endif
F_2 ( V_1 ) ;
F_6 () ;
}
static void F_7 ( void ) {}
static inline void F_8 ( unsigned long V_2 )
{
V_3 ;
F_9 ( V_2 ) ;
}
static inline void F_10 ( unsigned long V_2 )
{
F_11 ( V_2 ) ;
}
static inline void F_12 ( unsigned long V_2 )
{
F_13 ( V_2 ) ;
}
static void F_14 ( void )
{
unsigned long V_4 = F_15 () ;
switch ( V_4 ) {
case 0 :
V_5 = ( void * ) F_7 ;
break;
case 16 :
V_5 = V_6 ;
break;
case 32 :
V_5 = F_8 ;
break;
case 64 :
V_5 = F_10 ;
break;
case 128 :
V_5 = F_12 ;
break;
default:
break;
}
}
static void F_16 ( void )
{
unsigned long V_4 = F_15 () ;
if ( V_4 == 0 )
V_7 = ( void * ) F_7 ;
else if ( V_4 == 16 )
V_7 = V_8 ;
else if ( V_4 == 32 )
V_7 = V_9 ;
else if ( V_4 == 64 )
V_7 = V_10 ;
}
static void F_17 ( void )
{
unsigned long V_4 = F_15 () ;
if ( V_4 == 0 )
V_11 = ( void * ) F_7 ;
else if ( V_4 == 16 )
V_11 = V_12 ;
else if ( V_4 == 32 )
V_11 = V_13 ;
else if ( V_4 == 64 )
V_11 = V_14 ;
else if ( V_4 == 128 )
V_11 = V_15 ;
}
static void F_18 ( void )
{
unsigned long V_4 = F_15 () ;
if ( V_4 == 0 )
V_16 = ( void * ) F_7 ;
else if ( V_4 == 16 )
V_16 = V_17 ;
else if ( V_4 == 32 )
V_16 = V_18 ;
else if ( V_4 == 64 )
V_16 = V_19 ;
else if ( V_4 == 128 )
V_16 = V_20 ;
}
static inline void F_19 ( void )
{
unsigned long V_21 ;
F_20 ( V_21 ) ;
F_21 () ;
F_22 ( V_21 ) ;
}
static inline void F_23 ( void )
{
unsigned long V_22 = V_23 ;
unsigned long V_24 = V_22 + V_25 . V_26 . V_27 ;
unsigned long V_28 = 1UL << V_25 . V_26 . V_29 ;
unsigned long V_30 = V_25 . V_26 . V_31 <<
V_25 . V_26 . V_29 ;
unsigned long V_32 , V_2 ;
V_33 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 += V_28 )
for ( V_2 = V_22 + 0x400 ; V_2 < V_24 ; V_2 += 0x400 * 2 )
F_24 ( V_2 | V_32 , V_34 ) ;
V_35 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 += V_28 )
for ( V_2 = V_22 ; V_2 < V_24 ; V_2 += 0x400 * 2 )
F_24 ( V_2 | V_32 , V_34 ) ;
}
static inline void F_25 ( unsigned long V_36 )
{
unsigned long V_21 ;
F_20 ( V_21 ) ;
F_26 ( V_36 ) ;
F_22 ( V_21 ) ;
}
static inline void F_27 ( unsigned long V_36 )
{
unsigned long V_37 = V_25 . V_26 . V_27 - 1 ;
unsigned long V_22 = V_23 + ( V_36 & V_37 ) ;
unsigned long V_24 = V_22 + V_38 ;
unsigned long V_28 = 1UL << V_25 . V_26 . V_29 ;
unsigned long V_30 = V_25 . V_26 . V_31 <<
V_25 . V_26 . V_29 ;
unsigned long V_32 , V_2 ;
V_33 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 += V_28 )
for ( V_2 = V_22 + 0x400 ; V_2 < V_24 ; V_2 += 0x400 * 2 )
F_24 ( V_2 | V_32 , V_34 ) ;
V_35 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 += V_28 )
for ( V_2 = V_22 ; V_2 < V_24 ; V_2 += 0x400 * 2 )
F_24 ( V_2 | V_32 , V_34 ) ;
}
static void F_28 ( void )
{
unsigned long V_39 = F_29 () ;
if ( V_39 == 0 )
V_40 = ( void * ) F_7 ;
else if ( V_39 == 16 )
V_40 = V_41 ;
else if ( V_39 == 32 && F_30 () == V_42 )
V_40 = V_43 ;
else if ( V_39 == 32 )
V_40 = V_44 ;
else if ( V_39 == 64 )
V_40 = V_45 ;
else if ( V_39 == 128 )
V_40 = V_46 ;
}
static void T_1 F_31 ( void )
{
unsigned long V_39 = F_29 () ;
if ( V_39 == 0 )
V_47 = ( void * ) F_7 ;
else if ( V_39 == 16 )
V_47 = V_48 ;
else if ( V_39 == 32 )
V_47 = V_49 ;
else if ( V_39 == 64 )
V_47 = V_50 ;
}
static void F_32 ( void )
{
unsigned long V_39 = F_29 () ;
if ( V_39 == 0 )
V_51 = ( void * ) F_7 ;
else if ( V_39 == 16 )
V_51 = V_52 ;
else if ( V_39 == 32 ) {
if ( V_53 && F_33 () )
V_51 =
F_25 ;
else if ( V_54 )
V_51 =
F_27 ;
else if ( F_30 () == V_42 )
V_51 =
V_55 ;
else
V_51 =
F_26 ;
} else if ( V_39 == 64 )
V_51 = V_56 ;
}
static void F_34 ( void )
{
unsigned long V_39 = F_29 () ;
if ( V_39 == 0 )
V_57 = ( void * ) F_7 ;
else if ( V_39 == 16 )
V_57 = V_58 ;
else if ( V_39 == 32 ) {
if ( V_53 && F_33 () )
V_57 = F_19 ;
else if ( V_54 )
V_57 = F_23 ;
else if ( F_30 () == V_42 )
V_57 = V_59 ;
else
V_57 = F_21 ;
} else if ( V_39 == 64 )
V_57 = V_60 ;
else if ( V_39 == 128 )
V_57 = V_61 ;
}
static void F_35 ( void )
{
unsigned long V_62 = F_36 () ;
if ( V_63 == 0 )
V_64 = ( void * ) F_7 ;
else if ( V_62 == 16 )
V_64 = V_65 ;
else if ( V_62 == 32 )
V_64 = V_66 ;
else if ( V_62 == 64 )
V_64 = V_67 ;
else if ( V_62 == 128 )
V_64 = V_68 ;
}
static void F_37 ( void )
{
unsigned long V_62 = F_36 () ;
if ( V_63 == 0 )
V_69 = ( void * ) F_7 ;
else if ( V_62 == 16 )
V_69 = V_70 ;
else if ( V_62 == 32 )
V_69 = V_71 ;
else if ( V_62 == 64 )
V_69 = V_72 ;
else if ( V_62 == 128 )
V_69 = V_73 ;
}
static void F_38 ( void )
{
unsigned long V_62 = F_36 () ;
if ( V_63 == 0 )
V_74 = ( void * ) F_7 ;
else if ( V_62 == 16 )
V_74 = V_75 ;
else if ( V_62 == 32 )
V_74 = V_76 ;
else if ( V_62 == 64 )
V_74 = V_77 ;
else if ( V_62 == 128 )
V_74 = V_78 ;
}
static inline void F_39 ( void * args )
{
switch ( F_30 () ) {
case V_42 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_74 () ;
break;
default:
V_16 () ;
V_57 () ;
break;
}
}
static void F_40 ( void )
{
F_1 ( F_39 , NULL ) ;
}
static inline int F_41 ( const struct V_87 * V_88 )
{
#ifdef F_4
int V_89 ;
F_42 (i)
if ( F_43 ( V_89 , V_88 ) )
return 1 ;
return 0 ;
#else
return F_43 ( F_44 () , V_88 ) ;
#endif
}
static void F_45 ( void )
{
V_16 () ;
}
static void F_46 ( void )
{
V_16 () ;
}
static inline void F_47 ( void * args )
{
struct V_90 * V_91 = args ;
int V_92 = V_91 -> V_93 & V_94 ;
if ( ! ( F_41 ( V_91 -> V_95 ) ) )
return;
V_16 () ;
if ( V_92 )
V_57 () ;
}
static void F_48 ( struct V_90 * V_91 ,
unsigned long V_22 , unsigned long V_24 )
{
int V_92 = V_91 -> V_93 & V_94 ;
if ( V_96 || ( V_92 && ! V_97 ) )
F_1 ( F_47 , V_91 ) ;
}
static inline void F_49 ( void * args )
{
struct V_87 * V_88 = args ;
if ( ! F_41 ( V_88 ) )
return;
if ( F_30 () == V_80 ||
F_30 () == V_81 ||
F_30 () == V_82 ||
F_30 () == V_83 ) {
V_74 () ;
return;
}
V_16 () ;
}
static void F_50 ( struct V_87 * V_88 )
{
if ( ! V_96 )
return;
F_1 ( F_49 , V_88 ) ;
}
static inline void F_51 ( void * args )
{
struct V_98 * V_99 = args ;
struct V_90 * V_91 = V_99 -> V_91 ;
unsigned long V_2 = V_99 -> V_2 ;
struct V_36 * V_36 = F_52 ( V_99 -> V_100 ) ;
int V_92 = V_91 -> V_93 & V_94 ;
struct V_87 * V_88 = V_91 -> V_95 ;
int V_101 = 0 ;
T_2 * V_102 ;
T_3 * V_103 ;
T_4 * V_104 ;
T_5 * V_105 ;
void * V_106 ;
if ( ! F_41 ( V_88 ) )
return;
V_2 &= V_107 ;
V_102 = F_53 ( V_88 , V_2 ) ;
V_103 = F_54 ( V_102 , V_2 ) ;
V_104 = F_55 ( V_103 , V_2 ) ;
V_105 = F_56 ( V_104 , V_2 ) ;
if ( ! ( F_57 ( * V_105 ) ) )
return;
if ( ( V_88 == V_108 -> V_109 ) && ( F_58 ( * V_105 ) & V_110 ) )
V_106 = NULL ;
else {
V_101 = ( V_96 &&
F_59 ( V_36 ) && ! F_60 ( V_36 ) ) ;
if ( V_101 )
V_106 = F_61 ( V_36 , V_2 ) ;
else
V_106 = F_62 ( V_36 ) ;
V_2 = ( unsigned long ) V_106 ;
}
if ( V_96 || ( V_92 && ! V_97 ) ) {
V_106 ? V_5 ( V_2 ) :
V_7 ( V_2 ) ;
if ( V_92 && ! V_111 )
V_64 ( V_2 ) ;
}
if ( V_92 ) {
if ( V_106 && V_112 && V_88 == V_108 -> V_109 ) {
int V_113 = F_44 () ;
if ( F_43 ( V_113 , V_88 ) != 0 )
F_63 ( V_88 , V_113 ) ;
} else
V_106 ? V_40 ( V_2 ) :
V_47 ( V_2 ) ;
}
if ( V_106 ) {
if ( V_101 )
F_64 () ;
else
F_65 ( V_106 ) ;
}
}
static void F_66 ( struct V_90 * V_91 ,
unsigned long V_2 , unsigned long V_100 )
{
struct V_98 args ;
args . V_91 = V_91 ;
args . V_2 = V_2 ;
args . V_100 = V_100 ;
F_1 ( F_51 , & args ) ;
}
static inline void F_67 ( void * V_2 )
{
V_5 ( ( unsigned long ) V_2 ) ;
}
static void F_68 ( unsigned long V_2 )
{
if ( F_69 () )
F_67 ( ( void * ) V_2 ) ;
else
F_1 ( F_67 , ( void * ) V_2 ) ;
}
static inline void F_70 ( unsigned long V_22 , unsigned long V_24 )
{
if ( ! V_97 ) {
if ( V_24 - V_22 >= V_114 ) {
V_16 () ;
} else {
V_3 ;
F_71 ( V_22 , V_24 ) ;
}
}
if ( V_24 - V_22 > V_115 )
V_57 () ;
else {
switch ( F_72 () ) {
case V_42 :
F_73 ( V_22 , V_24 ) ;
break;
default:
F_74 ( V_22 , V_24 ) ;
break;
}
}
#ifdef F_75
F_76 ( V_22 , ( V_24 - V_22 ) ) ;
F_77 () ;
#endif
}
static inline void F_78 ( void * args )
{
struct V_116 * V_117 = args ;
unsigned long V_22 = V_117 -> V_22 ;
unsigned long V_24 = V_117 -> V_24 ;
F_70 ( V_22 , V_24 ) ;
}
static void F_79 ( unsigned long V_22 , unsigned long V_24 )
{
struct V_116 args ;
args . V_22 = V_22 ;
args . V_24 = V_24 ;
F_1 ( F_78 , & args ) ;
F_80 () ;
}
static void F_81 ( unsigned long V_2 , unsigned long V_118 )
{
F_82 ( V_118 == 0 ) ;
F_3 () ;
if ( V_119 ) {
if ( V_118 >= V_63 )
V_74 () ;
else
F_83 ( V_2 , V_2 + V_118 ) ;
F_6 () ;
F_77 () ;
return;
}
if ( V_120 && V_118 >= V_114 ) {
V_16 () ;
} else {
V_3 ;
F_84 ( V_2 , V_2 + V_118 ) ;
}
F_6 () ;
F_76 ( V_2 , V_118 ) ;
F_77 () ;
}
static void F_85 ( unsigned long V_2 , unsigned long V_118 )
{
F_82 ( V_118 == 0 ) ;
F_3 () ;
if ( V_119 ) {
if ( V_118 >= V_63 )
V_74 () ;
else {
F_86 ( V_2 , V_2 + V_118 ) ;
}
F_6 () ;
F_77 () ;
return;
}
if ( V_120 && V_118 >= V_114 ) {
V_16 () ;
} else {
V_3 ;
F_87 ( V_2 , V_2 + V_118 ) ;
}
F_6 () ;
F_88 ( V_2 , V_118 ) ;
F_77 () ;
}
static void F_89 ( void * V_121 )
{
unsigned long V_39 = F_29 () ;
unsigned long V_4 = F_15 () ;
unsigned long V_62 = F_36 () ;
unsigned long V_2 = ( unsigned long ) V_121 ;
V_3 ;
if ( V_4 )
F_90 ( V_2 & ~ ( V_4 - 1 ) ) ;
if ( ! V_111 && V_63 )
F_91 ( V_2 & ~ ( V_62 - 1 ) ) ;
if ( V_39 )
F_92 ( V_2 & ~ ( V_39 - 1 ) ) ;
if ( V_122 ) {
__asm__ __volatile__ (
".set push\n\t"
".set noat\n\t"
".set "MIPS_ISA_LEVEL"\n\t"
#ifdef F_93
"la $at,1f\n\t"
#endif
#ifdef F_94
"dla $at,1f\n\t"
#endif
"cache %0,($at)\n\t"
"nop; nop; nop\n"
"1:\n\t"
".set pop"
:
: "i" (Hit_Invalidate_I));
}
if ( V_123 )
__asm__ __volatile__ ("sync");
}
static void F_95 ( unsigned long V_2 )
{
F_1 ( F_89 , ( void * ) V_2 ) ;
}
static void F_96 ( void )
{
if ( V_112 )
V_57 () ;
}
static inline void F_97 ( void * args )
{
struct V_124 * V_125 = args ;
unsigned long V_106 = V_125 -> V_106 ;
int V_118 = V_125 -> V_118 ;
if ( V_120 && V_118 >= V_114 )
V_16 () ;
else {
V_3 ;
F_84 ( V_106 , V_106 + V_118 ) ;
}
}
static void F_98 ( unsigned long V_106 , int V_118 )
{
struct V_124 args ;
args . V_106 = ( unsigned long ) V_106 ;
args . V_118 = V_118 ;
F_1 ( F_97 , & args ) ;
}
static inline void F_99 ( void )
{
const unsigned long V_39 = 32 ;
unsigned long V_2 ;
F_100 ( 0 ) ;
F_101 ( 0 ) ;
for ( V_2 = V_23 ; V_2 <= V_23 + 4096 ; V_2 += V_39 ) {
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
static inline void F_102 ( struct V_126 * V_127 )
{
unsigned int V_128 = V_127 -> V_129 & V_130 ;
unsigned int V_131 = V_127 -> V_129 & V_132 ;
switch ( V_128 ) {
case V_133 :
if ( V_131 <= F_103 ( 2 , 4 , 0 ) )
V_127 -> V_134 . V_21 |= V_135 ;
if ( V_131 == F_103 ( 2 , 4 , 0 ) )
F_104 ( F_105 () | V_136 ) ;
break;
case V_137 :
if ( V_131 <= F_103 ( 1 , 1 , 0 ) ) {
V_127 -> V_134 . V_21 |= V_135 ;
F_104 ( F_105 () | V_136 ) ;
}
break;
default:
F_106 () ;
}
}
static void F_107 ( void )
{
F_77 () ;
F_77 () ;
__asm__ __volatile__(
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
: : : "memory");
}
static void F_108 ( void )
{
struct V_126 * V_127 = & V_25 ;
unsigned int V_138 = F_109 () ;
unsigned int V_139 = F_110 () ;
unsigned long V_140 ;
unsigned int V_141 ;
switch ( F_30 () ) {
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_115 = 1 << ( 12 + ( ( V_138 & V_146 ) >> 9 ) ) ;
V_127 -> V_26 . V_147 = 16 << ( ( V_138 & V_148 ) >> 5 ) ;
V_127 -> V_26 . V_31 = 2 ;
V_127 -> V_26 . V_29 = F_111 ( V_115 / 2 ) ;
V_114 = 1 << ( 12 + ( ( V_138 & V_149 ) >> 6 ) ) ;
V_127 -> V_134 . V_147 = 16 << ( ( V_138 & V_150 ) >> 4 ) ;
V_127 -> V_134 . V_31 = 2 ;
V_127 -> V_134 . V_29 = F_111 ( V_114 / 2 ) ;
V_127 -> V_151 |= V_152 ;
break;
case V_153 :
case V_154 :
V_115 = 1 << ( 12 + ( ( V_138 & V_146 ) >> 9 ) ) ;
V_127 -> V_26 . V_147 = 16 << ( ( V_138 & V_148 ) >> 5 ) ;
V_127 -> V_26 . V_31 = 2 ;
V_127 -> V_26 . V_29 = 0 ;
V_114 = 1 << ( 12 + ( ( V_138 & V_149 ) >> 6 ) ) ;
V_127 -> V_134 . V_147 = 16 << ( ( V_138 & V_150 ) >> 4 ) ;
V_127 -> V_134 . V_31 = 2 ;
V_127 -> V_134 . V_29 = 0 ;
V_127 -> V_151 |= V_152 | V_155 ;
break;
case V_156 :
V_115 = 1 << ( 12 + ( ( V_138 & V_146 ) >> 9 ) ) ;
V_127 -> V_26 . V_147 = 16 << ( ( V_138 & V_148 ) >> 5 ) ;
V_127 -> V_26 . V_31 = 4 ;
V_127 -> V_26 . V_29 = 0 ;
V_114 = 1 << ( 12 + ( ( V_138 & V_149 ) >> 6 ) ) ;
V_127 -> V_134 . V_147 = 16 << ( ( V_138 & V_150 ) >> 4 ) ;
V_127 -> V_134 . V_31 = 4 ;
V_127 -> V_134 . V_29 = 0 ;
V_127 -> V_151 |= V_152 ;
V_127 -> V_151 |= V_155 ;
break;
case V_157 :
case V_80 :
case V_81 :
case V_158 :
case V_82 :
case V_83 :
case V_159 :
V_115 = 1 << ( 12 + ( ( V_138 & V_146 ) >> 9 ) ) ;
V_127 -> V_26 . V_147 = 16 << ( ( V_138 & V_148 ) >> 5 ) ;
V_127 -> V_26 . V_31 = 1 ;
V_127 -> V_26 . V_29 = 0 ;
V_114 = 1 << ( 12 + ( ( V_138 & V_149 ) >> 6 ) ) ;
V_127 -> V_134 . V_147 = 16 << ( ( V_138 & V_150 ) >> 4 ) ;
V_127 -> V_134 . V_31 = 1 ;
V_127 -> V_134 . V_29 = 0 ;
V_127 -> V_151 |= V_152 ;
break;
case V_84 :
case V_85 :
case V_86 :
V_115 = 1 << ( 12 + ( ( V_138 & V_160 ) >> 29 ) ) ;
V_127 -> V_26 . V_147 = 64 ;
V_127 -> V_26 . V_31 = 2 ;
V_127 -> V_26 . V_29 = 0 ;
V_114 = 1 << ( 12 + ( ( V_138 & V_161 ) >> 26 ) ) ;
V_127 -> V_134 . V_147 = 32 ;
V_127 -> V_134 . V_31 = 2 ;
V_127 -> V_134 . V_29 = 0 ;
V_127 -> V_151 |= V_155 ;
break;
case V_162 :
F_112 ( V_138 & ~ V_163 ) ;
case V_164 :
if ( V_127 -> V_129 == 0x0c80U || V_127 -> V_129 == 0x0c81U ||
V_127 -> V_129 == 0x0c82U ) {
V_138 |= 0x00400000U ;
if ( V_127 -> V_129 == 0x0c80U )
V_138 |= V_165 ;
F_112 ( V_138 ) ;
} else
V_127 -> V_151 |= V_152 ;
V_115 = 1 << ( 10 + ( ( V_138 & V_146 ) >> 9 ) ) ;
V_127 -> V_26 . V_147 = 16 << ( ( V_138 & V_148 ) >> 5 ) ;
V_127 -> V_26 . V_31 = 2 ;
V_127 -> V_26 . V_29 = F_111 ( V_115 / 2 ) ;
V_114 = 1 << ( 10 + ( ( V_138 & V_149 ) >> 6 ) ) ;
V_127 -> V_134 . V_147 = 16 << ( ( V_138 & V_150 ) >> 4 ) ;
V_127 -> V_134 . V_31 = 2 ;
V_127 -> V_134 . V_29 = F_111 ( V_114 / 2 ) ;
break;
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
V_115 = 1 << ( 10 + ( ( V_138 & V_146 ) >> 9 ) ) ;
V_127 -> V_26 . V_147 = 16 << ( ( V_138 & V_148 ) >> 5 ) ;
V_127 -> V_26 . V_31 = 1 ;
V_127 -> V_26 . V_29 = 0 ;
V_114 = 1 << ( 10 + ( ( V_138 & V_149 ) >> 6 ) ) ;
V_127 -> V_134 . V_147 = 16 << ( ( V_138 & V_150 ) >> 4 ) ;
V_127 -> V_134 . V_31 = 1 ;
V_127 -> V_134 . V_29 = 0 ;
V_127 -> V_151 |= V_152 ;
break;
case V_172 :
F_99 () ;
V_115 = 1 << ( 12 + ( ( V_138 & V_146 ) >> 9 ) ) ;
V_127 -> V_26 . V_147 = 16 << ( ( V_138 & V_148 ) >> 5 ) ;
V_127 -> V_26 . V_31 = 4 ;
V_127 -> V_26 . V_29 = F_111 ( V_115 / V_127 -> V_26 . V_31 ) ;
V_114 = 1 << ( 12 + ( ( V_138 & V_149 ) >> 6 ) ) ;
V_127 -> V_134 . V_147 = 16 << ( ( V_138 & V_150 ) >> 4 ) ;
V_127 -> V_134 . V_31 = 4 ;
V_127 -> V_134 . V_29 = F_111 ( V_114 / V_127 -> V_134 . V_31 ) ;
V_127 -> V_151 |= V_152 ;
V_127 -> V_151 |= V_155 ;
break;
case V_42 :
V_115 = 1 << ( 12 + ( ( V_138 & V_146 ) >> 9 ) ) ;
V_127 -> V_26 . V_147 = 16 << ( ( V_138 & V_148 ) >> 5 ) ;
if ( V_139 & 0x3 )
V_127 -> V_26 . V_31 = 4 ;
else
V_127 -> V_26 . V_31 = 2 ;
V_127 -> V_26 . V_29 = 0 ;
V_114 = 1 << ( 12 + ( ( V_138 & V_149 ) >> 6 ) ) ;
V_127 -> V_134 . V_147 = 16 << ( ( V_138 & V_150 ) >> 4 ) ;
if ( V_139 & 0x3 )
V_127 -> V_134 . V_31 = 4 ;
else
V_127 -> V_134 . V_31 = 2 ;
V_127 -> V_134 . V_29 = 0 ;
break;
case V_79 :
V_140 = F_113 () ;
V_141 = ( V_140 >> 19 ) & 7 ;
if ( V_141 )
V_127 -> V_26 . V_147 = 2 << V_141 ;
else
V_127 -> V_26 . V_147 = 0 ;
V_127 -> V_26 . V_173 = 64 << ( ( V_140 >> 22 ) & 7 ) ;
V_127 -> V_26 . V_31 = 1 + ( ( V_140 >> 16 ) & 7 ) ;
V_115 = V_127 -> V_26 . V_173 *
V_127 -> V_26 . V_31 *
V_127 -> V_26 . V_147 ;
V_127 -> V_26 . V_29 = 0 ;
V_141 = ( V_140 >> 10 ) & 7 ;
if ( V_141 )
V_127 -> V_134 . V_147 = 2 << V_141 ;
else
V_127 -> V_134 . V_147 = 0 ;
V_127 -> V_134 . V_173 = 64 << ( ( V_140 >> 13 ) & 7 ) ;
V_127 -> V_134 . V_31 = 1 + ( ( V_140 >> 7 ) & 7 ) ;
V_114 = V_127 -> V_134 . V_173 *
V_127 -> V_134 . V_31 *
V_127 -> V_134 . V_147 ;
V_127 -> V_134 . V_29 = 0 ;
break;
case V_174 :
V_127 -> V_26 . V_147 = 128 ;
V_127 -> V_26 . V_173 = 16 ;
V_127 -> V_26 . V_31 = 8 ;
V_127 -> V_26 . V_21 |= V_135 ;
V_115 = V_127 -> V_26 . V_173 * V_127 -> V_26 . V_31 * V_127 -> V_26 . V_147 ;
V_127 -> V_134 . V_147 = 128 ;
V_127 -> V_134 . V_31 = 8 ;
V_127 -> V_134 . V_173 = 8 ;
V_114 = V_127 -> V_134 . V_173 * V_127 -> V_134 . V_31 * V_127 -> V_134 . V_147 ;
V_127 -> V_151 |= V_155 ;
break;
default:
if ( ! ( V_138 & V_175 ) )
F_114 ( L_1 ) ;
V_140 = F_113 () ;
V_141 = ( V_140 >> 19 ) & 7 ;
if ( V_141 == 7 )
F_114 ( L_2 ) ;
V_127 -> V_26 . V_147 = V_141 ? 2 << V_141 : 0 ;
V_127 -> V_26 . V_173 = 32 << ( ( ( V_140 >> 22 ) + 1 ) & 7 ) ;
V_127 -> V_26 . V_31 = 1 + ( ( V_140 >> 16 ) & 7 ) ;
V_115 = V_127 -> V_26 . V_173 *
V_127 -> V_26 . V_31 *
V_127 -> V_26 . V_147 ;
V_127 -> V_26 . V_29 = F_111 ( V_115 / V_127 -> V_26 . V_31 ) ;
if ( V_138 & 0x8 )
V_127 -> V_26 . V_21 |= V_135 ;
V_127 -> V_134 . V_21 = 0 ;
V_141 = ( V_140 >> 10 ) & 7 ;
if ( V_141 == 7 )
F_114 ( L_3 ) ;
V_127 -> V_134 . V_147 = V_141 ? 2 << V_141 : 0 ;
V_127 -> V_134 . V_173 = 32 << ( ( ( V_140 >> 13 ) + 1 ) & 7 ) ;
V_127 -> V_134 . V_31 = 1 + ( ( V_140 >> 7 ) & 7 ) ;
V_114 = V_127 -> V_134 . V_173 *
V_127 -> V_134 . V_31 *
V_127 -> V_134 . V_147 ;
V_127 -> V_134 . V_29 = F_111 ( V_114 / V_127 -> V_134 . V_31 ) ;
V_127 -> V_151 |= V_155 ;
break;
}
if ( ( V_139 & V_130 ) == V_176 &&
( V_139 & V_132 ) < V_177 &&
! ( V_138 & V_178 ) && V_127 -> V_26 . V_147 != 16 &&
V_38 <= 0x8000 )
F_114 ( L_4 ) ;
V_127 -> V_26 . V_27 = V_115 / V_127 -> V_26 . V_31 ;
V_127 -> V_134 . V_27 = V_114 / V_127 -> V_134 . V_31 ;
V_127 -> V_26 . V_173 = V_127 -> V_26 . V_147 ?
V_115 / ( V_127 -> V_26 . V_147 * V_127 -> V_26 . V_31 ) : 0 ;
V_127 -> V_134 . V_173 = V_127 -> V_134 . V_147 ?
V_114 / ( V_127 -> V_134 . V_147 * V_127 -> V_134 . V_31 ) : 0 ;
switch ( F_30 () ) {
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
V_127 -> V_134 . V_21 |= V_184 ;
break;
case V_84 :
case V_85 :
case V_86 :
break;
case V_185 :
case V_186 :
F_102 ( V_127 ) ;
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
if ( ! ( F_115 () & V_197 ) &&
( V_127 -> V_26 . V_27 > V_38 ) )
V_127 -> V_26 . V_21 |= V_198 ;
if ( F_115 () & V_199 ) {
V_127 -> V_134 . V_21 |= V_184 ;
break;
}
default:
if ( V_127 -> V_134 . V_27 > V_38 )
V_127 -> V_134 . V_21 |= V_198 ;
}
switch ( F_30 () ) {
case V_179 :
V_127 -> V_26 . V_21 |= V_135 ;
break;
case V_200 :
V_127 -> V_26 . V_21 |= V_201 ;
break;
case V_42 :
V_127 -> V_26 . V_31 = 1 ;
}
F_116 ( L_5 ,
V_115 >> 10 ,
V_127 -> V_26 . V_21 & V_135 ? L_6 : L_7 ,
V_202 [ V_127 -> V_26 . V_31 ] , V_127 -> V_26 . V_147 ) ;
F_116 ( L_8 ,
V_114 >> 10 , V_202 [ V_127 -> V_134 . V_31 ] ,
( V_127 -> V_134 . V_21 & V_184 ) ? L_9 : L_7 ,
( V_127 -> V_134 . V_21 & V_198 ) ?
L_10 : L_11 ,
V_127 -> V_134 . V_147 ) ;
}
static int F_117 ( void )
{
unsigned long V_21 , V_2 , V_203 , V_24 , V_204 ;
unsigned int V_138 = F_109 () ;
struct V_126 * V_127 = & V_25 ;
if ( V_138 & V_178 )
return 0 ;
V_203 = ( unsigned long ) & V_205 ;
V_203 &= ~ ( ( 4 * 1024 * 1024 ) - 1 ) ;
V_24 = V_203 + ( 4 * 1024 * 1024 ) ;
F_20 ( V_21 ) ;
V_204 = ( 64 * 1024 ) ;
for ( V_2 = V_203 ; V_2 < V_24 ; V_2 = ( V_203 + V_204 ) ) {
unsigned long * V_206 = ( unsigned long * ) V_2 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_204 <<= 1 ;
}
F_100 ( 0 ) ;
F_101 ( 0 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
F_118 ( V_207 , V_203 ) ;
F_118 ( V_208 , V_203 ) ;
F_118 ( V_209 , V_203 ) ;
V_204 = ( 128 * 1024 ) ;
for ( V_2 = V_203 + ( 128 * 1024 ) ; V_2 < V_24 ; V_2 = V_203 + V_204 ) {
F_118 ( V_210 , V_2 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
if ( ! F_119 () )
break;
V_204 <<= 1 ;
}
F_22 ( V_21 ) ;
V_2 -= V_203 ;
V_63 = V_2 ;
V_127 -> V_211 . V_147 = 16 << ( ( V_138 & V_212 ) >> 22 ) ;
V_127 -> V_211 . V_31 = 1 ;
V_127 -> V_134 . V_29 = 0 ;
return 1 ;
}
static void T_6 F_120 ( void )
{
struct V_126 * V_127 = & V_25 ;
V_63 = 512 * 1024 ;
V_127 -> V_211 . V_147 = 32 ;
V_127 -> V_211 . V_31 = 4 ;
V_127 -> V_211 . V_29 = 0 ;
V_127 -> V_211 . V_27 = V_63 / ( V_127 -> V_211 . V_31 ) ;
V_127 -> V_211 . V_173 = V_63 / ( V_127 -> V_211 . V_147 * V_127 -> V_211 . V_31 ) ;
F_121 ( L_12 ,
V_63 >> 10 , V_202 [ V_127 -> V_211 . V_31 ] , V_127 -> V_211 . V_147 ) ;
V_127 -> V_151 |= V_213 ;
}
static void T_6 F_122 ( void )
{
struct V_126 * V_127 = & V_25 ;
unsigned int V_214 , V_141 ;
V_214 = F_123 () ;
V_141 = ( V_214 >> 4 ) & 15 ;
if ( V_141 )
V_127 -> V_211 . V_147 = 2 << V_141 ;
else
V_127 -> V_211 . V_147 = 0 ;
V_127 -> V_211 . V_173 = 64 << ( ( V_214 >> 8 ) & 15 ) ;
V_127 -> V_211 . V_31 = 1 + ( V_214 & 15 ) ;
V_63 = V_127 -> V_211 . V_173 *
V_127 -> V_211 . V_31 *
V_127 -> V_211 . V_147 ;
V_63 *= 4 ;
V_127 -> V_211 . V_29 = 0 ;
F_121 ( L_12 ,
V_63 >> 10 , V_202 [ V_127 -> V_211 . V_31 ] , V_127 -> V_211 . V_147 ) ;
if ( V_63 )
V_127 -> V_151 |= V_213 ;
return;
}
static void F_124 ( void )
{
struct V_126 * V_127 = & V_25 ;
unsigned int V_138 = F_109 () ;
int V_215 = 0 ;
switch ( F_30 () ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_215 = F_125 ( F_117 ) ;
if ( V_215 )
V_127 -> V_151 |= V_216 ;
break;
case V_84 :
case V_85 :
case V_86 :
V_63 = 0x80000 << ( ( V_138 & V_217 ) >> 16 ) ;
V_127 -> V_211 . V_147 = 64 << ( ( V_138 >> 13 ) & 1 ) ;
V_127 -> V_211 . V_31 = 2 ;
V_127 -> V_211 . V_29 = 0 ;
V_215 = 1 ;
break;
case V_144 :
case V_145 :
#ifdef F_126
F_127 () ;
#endif
return;
case V_172 :
#ifdef F_128
F_129 () ;
#endif
return;
case V_42 :
F_120 () ;
return;
case V_79 :
F_122 () ;
return;
case V_174 :
case V_218 :
return;
default:
if ( V_127 -> V_219 & ( V_220 | V_221 |
V_222 | V_223 |
V_224 | V_225 ) ) {
#ifdef F_130
if ( F_131 () ) {
V_63 = V_127 -> V_211 . V_31 * V_127 -> V_211 . V_173 * V_127 -> V_211 . V_147 ;
F_116 ( L_13 ,
V_63 >> 10 ,
V_202 [ V_127 -> V_211 . V_31 ] , V_127 -> V_211 . V_147 ) ;
}
#else
if ( ! ( V_127 -> V_211 . V_21 & V_226 ) )
F_114 ( L_14 ) ;
#endif
return;
}
V_215 = 0 ;
}
if ( ! V_215 )
return;
V_127 -> V_211 . V_27 = V_63 / V_127 -> V_211 . V_31 ;
V_127 -> V_211 . V_173 = V_63 / ( V_127 -> V_211 . V_147 * V_127 -> V_211 . V_31 ) ;
F_116 ( L_12 ,
V_63 >> 10 , V_202 [ V_127 -> V_211 . V_31 ] , V_127 -> V_211 . V_147 ) ;
V_127 -> V_151 |= V_213 ;
}
void F_132 ( void )
{
switch ( F_110 () ) {
case 0x00030100 :
case 0x00030201 :
case 0x00030202 :
case 0x01030200 :
case 0x02030200 :
case 0x02030201 :
case 0x02030202 :
F_133 ( 1 << 19 ) ;
break;
}
}
static void F_134 ( void )
{
unsigned long V_227 ;
V_227 = F_109 () ;
V_227 &= ~ ( 0x7 | ( 7 << 25 ) | ( 7 << 28 ) ) ;
V_227 |= ( ( ( V_228 >> V_229 ) << 0 ) |
( ( V_228 >> V_229 ) << 25 ) |
( ( V_228 >> V_229 ) << 28 ) ) ;
F_112 ( V_227 ) ;
F_135 () ;
}
static int T_6 F_136 ( char * V_230 )
{
F_137 ( & V_230 , & V_231 ) ;
return 0 ;
}
static void F_138 ( void )
{
if ( V_231 < 0 || V_231 > 7 )
V_231 = F_109 () & V_232 ;
V_228 = V_231 << V_229 ;
F_139 ( L_15 , V_231 ) ;
F_140 ( V_232 , V_231 ) ;
switch ( F_30 () ) {
case V_157 :
case V_80 :
case V_81 :
case V_158 :
case V_82 :
case V_83 :
F_141 ( V_233 ) ;
break;
case V_200 :
F_132 () ;
break;
case V_234 :
F_134 () ;
break;
}
}
static void F_142 ( void )
{
extern char __weak V_235 ;
extern char __weak V_236 ;
switch ( F_30 () ) {
case V_181 :
case V_182 :
F_143 ( 0x100 , & V_236 , 0x80 ) ;
break;
default:
F_143 ( 0x100 , & V_235 , 0x80 ) ;
break;
}
}
void F_144 ( void )
{
extern void V_237 ( void ) ;
extern void V_238 ( void ) ;
struct V_126 * V_127 = & V_25 ;
F_108 () ;
F_124 () ;
F_14 () ;
F_17 () ;
F_18 () ;
F_28 () ;
F_32 () ;
F_34 () ;
F_35 () ;
F_37 () ;
F_38 () ;
#ifdef F_75
F_16 () ;
F_31 () ;
#endif
if ( V_127 -> V_134 . V_147 )
V_239 = F_145 ( unsigned long,
c->dcache.sets * c->dcache.linesz - 1 ,
PAGE_SIZE - 1 ) ;
else
V_239 = V_38 - 1 ;
V_240 = F_45 ;
V_241 = F_46 ;
V_242 = F_7 ;
V_243 = F_40 ;
V_244 = F_50 ;
V_245 = F_66 ;
V_246 = F_48 ;
V_247 = F_98 ;
V_248 = F_95 ;
V_249 = F_96 ;
V_250 = F_67 ;
V_251 = F_68 ;
V_252 = F_79 ;
V_253 = F_70 ;
#if F_146 ( V_254 ) || F_146 ( V_255 )
if ( V_256 ) {
V_257 = ( void * ) F_7 ;
V_258 = ( void * ) F_7 ;
V_259 = ( void * ) F_7 ;
} else {
V_257 = F_81 ;
V_258 = F_81 ;
V_259 = F_85 ;
}
#endif
V_237 () ;
V_238 () ;
F_39 ( NULL ) ;
F_138 () ;
V_260 = F_142 ;
switch ( F_30 () ) {
case V_261 :
case V_262 :
V_251 = V_5 ;
break;
case V_263 :
if ( V_127 -> V_211 . V_21 & V_226 )
break;
V_245 = ( void * ) F_107 ;
V_246 = ( void * ) F_107 ;
V_248 = ( void * ) F_107 ;
V_250 = ( void * ) F_107 ;
V_251 = ( void * ) F_107 ;
V_252 = ( void * ) F_107 ;
V_253 = ( void * ) F_107 ;
V_25 . V_134 . V_21 &= ~ V_198 ;
V_25 . V_151 |= V_213 ;
break;
}
}
static int F_147 ( struct V_264 * V_265 , unsigned long V_266 ,
void * V_267 )
{
switch ( V_266 ) {
case V_268 :
case V_269 :
F_138 () ;
break;
}
return V_270 ;
}
int T_6 F_148 ( void )
{
return F_149 ( & V_271 ) ;
}
