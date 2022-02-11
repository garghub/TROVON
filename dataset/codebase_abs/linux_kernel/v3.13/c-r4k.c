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
else if ( V_35 == 32 && F_27 () == V_38 )
V_36 = V_39 ;
else if ( V_35 == 32 )
V_36 = V_40 ;
else if ( V_35 == 64 )
V_36 = V_41 ;
}
static void F_28 ( void )
{
unsigned long V_35 = F_26 () ;
if ( V_35 == 0 )
V_42 = ( void * ) F_7 ;
else if ( V_35 == 16 )
V_42 = V_43 ;
else if ( V_35 == 32 ) {
if ( V_44 && F_29 () )
V_42 =
F_22 ;
else if ( V_45 )
V_42 =
F_24 ;
else if ( F_27 () == V_38 )
V_42 =
V_46 ;
else
V_42 =
F_23 ;
} else if ( V_35 == 64 )
V_42 = V_47 ;
}
static void F_30 ( void )
{
unsigned long V_35 = F_26 () ;
if ( V_35 == 0 )
V_48 = ( void * ) F_7 ;
else if ( V_35 == 16 )
V_48 = V_49 ;
else if ( V_35 == 32 ) {
if ( V_44 && F_29 () )
V_48 = F_16 ;
else if ( V_45 )
V_48 = F_20 ;
else if ( F_27 () == V_38 )
V_48 = V_50 ;
else
V_48 = F_18 ;
} else if ( V_35 == 64 )
V_48 = V_51 ;
}
static void F_31 ( void )
{
unsigned long V_52 = F_32 () ;
if ( V_53 == 0 )
V_54 = ( void * ) F_7 ;
else if ( V_52 == 16 )
V_54 = V_55 ;
else if ( V_52 == 32 )
V_54 = V_56 ;
else if ( V_52 == 64 )
V_54 = V_57 ;
else if ( V_52 == 128 )
V_54 = V_58 ;
}
static void F_33 ( void )
{
unsigned long V_52 = F_32 () ;
if ( V_53 == 0 )
V_59 = ( void * ) F_7 ;
else if ( V_52 == 16 )
V_59 = V_60 ;
else if ( V_52 == 32 )
V_59 = V_61 ;
else if ( V_52 == 64 )
V_59 = V_62 ;
else if ( V_52 == 128 )
V_59 = V_63 ;
}
static void F_34 ( void )
{
unsigned long V_52 = F_32 () ;
if ( V_53 == 0 )
V_64 = ( void * ) F_7 ;
else if ( V_52 == 16 )
V_64 = V_65 ;
else if ( V_52 == 32 )
V_64 = V_66 ;
else if ( V_52 == 64 )
V_64 = V_67 ;
else if ( V_52 == 128 )
V_64 = V_68 ;
}
static inline void F_35 ( void * args )
{
switch ( F_27 () ) {
case V_38 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_64 () ;
break;
default:
V_13 () ;
V_48 () ;
break;
}
}
static void F_36 ( void )
{
F_1 ( F_35 , NULL ) ;
}
static inline int F_37 ( const struct V_76 * V_77 )
{
#if F_4 ( V_2 ) || F_4 ( V_3 )
int V_78 ;
F_38 (i)
if ( F_39 ( V_78 , V_77 ) )
return 1 ;
return 0 ;
#else
return F_39 ( F_40 () , V_77 ) ;
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
struct V_79 * V_80 = args ;
int V_81 = V_80 -> V_82 & V_83 ;
if ( ! ( F_37 ( V_80 -> V_84 ) ) )
return;
V_13 () ;
if ( V_81 )
V_48 () ;
}
static void F_44 ( struct V_79 * V_80 ,
unsigned long V_18 , unsigned long V_20 )
{
int V_81 = V_80 -> V_82 & V_83 ;
if ( V_85 || ( V_81 && ! V_86 ) )
F_1 ( F_43 , V_80 ) ;
}
static inline void F_45 ( void * args )
{
struct V_76 * V_77 = args ;
if ( ! F_37 ( V_77 ) )
return;
if ( F_27 () == V_69 ||
F_27 () == V_70 ||
F_27 () == V_71 ||
F_27 () == V_72 ) {
V_64 () ;
return;
}
V_13 () ;
}
static void F_46 ( struct V_76 * V_77 )
{
if ( ! V_85 )
return;
F_1 ( F_45 , V_77 ) ;
}
static inline void F_47 ( void * args )
{
struct V_87 * V_88 = args ;
struct V_79 * V_80 = V_88 -> V_80 ;
unsigned long V_4 = V_88 -> V_4 ;
struct V_32 * V_32 = F_48 ( V_88 -> V_89 ) ;
int V_81 = V_80 -> V_82 & V_83 ;
struct V_76 * V_77 = V_80 -> V_84 ;
int V_90 = 0 ;
T_1 * V_91 ;
T_2 * V_92 ;
T_3 * V_93 ;
T_4 * V_94 ;
void * V_95 ;
if ( ! F_37 ( V_77 ) )
return;
V_4 &= V_96 ;
V_91 = F_49 ( V_77 , V_4 ) ;
V_92 = F_50 ( V_91 , V_4 ) ;
V_93 = F_51 ( V_92 , V_4 ) ;
V_94 = F_52 ( V_93 , V_4 ) ;
if ( ! ( F_53 ( * V_94 ) ) )
return;
if ( ( V_77 == V_97 -> V_98 ) && ( F_54 ( * V_94 ) & V_99 ) )
V_95 = NULL ;
else {
V_90 = ( V_85 &&
F_55 ( V_32 ) && ! F_56 ( V_32 ) ) ;
if ( V_90 )
V_95 = F_57 ( V_32 , V_4 ) ;
else
V_95 = F_58 ( V_32 ) ;
V_4 = ( unsigned long ) V_95 ;
}
if ( V_85 || ( V_81 && ! V_86 ) ) {
V_7 ( V_4 ) ;
if ( V_81 && ! V_100 )
V_54 ( V_4 ) ;
}
if ( V_81 ) {
if ( V_95 && V_101 && V_77 == V_97 -> V_98 ) {
int V_102 = F_40 () ;
if ( F_39 ( V_102 , V_77 ) != 0 )
F_59 ( V_77 , V_102 ) ;
} else
V_36 ( V_4 ) ;
}
if ( V_95 ) {
if ( V_90 )
F_60 () ;
else
F_61 ( V_95 ) ;
}
}
static void F_62 ( struct V_79 * V_80 ,
unsigned long V_4 , unsigned long V_89 )
{
struct V_87 args ;
args . V_80 = V_80 ;
args . V_4 = V_4 ;
args . V_89 = V_89 ;
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
if ( ! V_86 ) {
if ( V_20 - V_18 >= V_103 ) {
V_13 () ;
} else {
V_5 ;
F_67 ( V_18 , V_20 ) ;
}
}
if ( V_20 - V_18 > V_104 )
V_48 () ;
else {
switch ( F_68 () ) {
case V_38 :
F_69 ( V_18 , V_20 ) ;
break;
default:
F_70 ( V_18 , V_20 ) ;
break;
}
}
}
static inline void F_71 ( void * args )
{
struct V_105 * V_106 = args ;
unsigned long V_18 = V_106 -> V_18 ;
unsigned long V_20 = V_106 -> V_20 ;
F_66 ( V_18 , V_20 ) ;
}
static void F_72 ( unsigned long V_18 , unsigned long V_20 )
{
struct V_105 args ;
args . V_18 = V_18 ;
args . V_20 = V_20 ;
F_1 ( F_71 , & args ) ;
F_73 () ;
}
static void F_74 ( unsigned long V_4 , unsigned long V_107 )
{
F_75 ( V_107 == 0 ) ;
F_3 () ;
if ( V_108 ) {
if ( V_107 >= V_53 )
V_64 () ;
else
F_76 ( V_4 , V_4 + V_107 ) ;
F_6 () ;
F_77 () ;
return;
}
if ( V_109 && V_107 >= V_103 ) {
V_13 () ;
} else {
V_5 ;
F_78 ( V_4 , V_4 + V_107 ) ;
}
F_6 () ;
F_79 ( V_4 , V_107 ) ;
F_77 () ;
}
static void F_80 ( unsigned long V_4 , unsigned long V_107 )
{
F_75 ( V_107 == 0 ) ;
F_3 () ;
if ( V_108 ) {
if ( V_107 >= V_53 )
V_64 () ;
else {
F_81 ( V_4 , V_4 + V_107 ) ;
}
F_6 () ;
F_77 () ;
return;
}
if ( V_109 && V_107 >= V_103 ) {
V_13 () ;
} else {
V_5 ;
F_82 ( V_4 , V_4 + V_107 ) ;
}
F_6 () ;
F_83 ( V_4 , V_107 ) ;
F_77 () ;
}
static void F_84 ( void * V_110 )
{
unsigned long V_35 = F_26 () ;
unsigned long V_6 = F_13 () ;
unsigned long V_52 = F_32 () ;
unsigned long V_4 = ( unsigned long ) V_110 ;
V_5 ;
if ( V_6 )
F_85 ( V_4 & ~ ( V_6 - 1 ) ) ;
if ( ! V_100 && V_53 )
F_86 ( V_4 & ~ ( V_52 - 1 ) ) ;
if ( V_35 )
F_87 ( V_4 & ~ ( V_35 - 1 ) ) ;
if ( V_111 ) {
__asm__ __volatile__ (
".set push\n\t"
".set noat\n\t"
".set mips3\n\t"
#ifdef F_88
"la $at,1f\n\t"
#endif
#ifdef F_89
"dla $at,1f\n\t"
#endif
"cache %0,($at)\n\t"
"nop; nop; nop\n"
"1:\n\t"
".set pop"
:
: "i" (Hit_Invalidate_I));
}
if ( V_112 )
__asm__ __volatile__ ("sync");
}
static void F_90 ( unsigned long V_4 )
{
F_1 ( F_84 , ( void * ) V_4 ) ;
}
static void F_91 ( void )
{
if ( V_101 )
V_48 () ;
}
static inline void F_92 ( void * args )
{
struct V_113 * V_114 = args ;
unsigned long V_95 = V_114 -> V_95 ;
int V_107 = V_114 -> V_107 ;
if ( V_109 && V_107 >= V_103 )
V_13 () ;
else {
V_5 ;
F_78 ( V_95 , V_95 + V_107 ) ;
}
}
static void F_93 ( unsigned long V_95 , int V_107 )
{
struct V_113 args ;
args . V_95 = ( unsigned long ) V_95 ;
args . V_107 = V_107 ;
F_1 ( F_92 , & args ) ;
}
static inline void F_94 ( void )
{
const unsigned long V_35 = 32 ;
unsigned long V_4 ;
F_95 ( 0 ) ;
F_96 ( 0 ) ;
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
static inline void F_97 ( struct V_115 * V_116 )
{
unsigned int V_117 = V_116 -> V_118 & V_119 ;
unsigned int V_120 = V_116 -> V_118 & V_121 ;
switch ( V_117 ) {
case V_122 :
if ( V_120 <= F_98 ( 2 , 4 , 0 ) )
V_116 -> V_123 . V_17 |= V_124 ;
if ( V_120 == F_98 ( 2 , 4 , 0 ) )
F_99 ( F_100 () | V_125 ) ;
break;
case V_126 :
if ( V_120 <= F_98 ( 1 , 1 , 0 ) ) {
V_116 -> V_123 . V_17 |= V_124 ;
F_99 ( F_100 () | V_125 ) ;
}
break;
default:
F_101 () ;
}
}
static void F_102 ( void )
{
struct V_115 * V_116 = & V_21 ;
unsigned int V_127 = F_103 () ;
unsigned int V_128 = F_104 () ;
unsigned long V_129 ;
unsigned int V_130 ;
switch ( F_27 () ) {
case V_131 :
case V_132 :
case V_133 :
case V_134 :
V_104 = 1 << ( 12 + ( ( V_127 & V_135 ) >> 9 ) ) ;
V_116 -> V_22 . V_136 = 16 << ( ( V_127 & V_137 ) >> 5 ) ;
V_116 -> V_22 . V_27 = 2 ;
V_116 -> V_22 . V_25 = F_105 ( V_104 / 2 ) ;
V_103 = 1 << ( 12 + ( ( V_127 & V_138 ) >> 6 ) ) ;
V_116 -> V_123 . V_136 = 16 << ( ( V_127 & V_139 ) >> 4 ) ;
V_116 -> V_123 . V_27 = 2 ;
V_116 -> V_123 . V_25 = F_105 ( V_103 / 2 ) ;
V_116 -> V_140 |= V_141 ;
break;
case V_142 :
case V_143 :
V_104 = 1 << ( 12 + ( ( V_127 & V_135 ) >> 9 ) ) ;
V_116 -> V_22 . V_136 = 16 << ( ( V_127 & V_137 ) >> 5 ) ;
V_116 -> V_22 . V_27 = 2 ;
V_116 -> V_22 . V_25 = 0 ;
V_103 = 1 << ( 12 + ( ( V_127 & V_138 ) >> 6 ) ) ;
V_116 -> V_123 . V_136 = 16 << ( ( V_127 & V_139 ) >> 4 ) ;
V_116 -> V_123 . V_27 = 2 ;
V_116 -> V_123 . V_25 = 0 ;
V_116 -> V_140 |= V_141 | V_144 ;
break;
case V_145 :
V_104 = 1 << ( 12 + ( ( V_127 & V_135 ) >> 9 ) ) ;
V_116 -> V_22 . V_136 = 16 << ( ( V_127 & V_137 ) >> 5 ) ;
V_116 -> V_22 . V_27 = 4 ;
V_116 -> V_22 . V_25 = 0 ;
V_103 = 1 << ( 12 + ( ( V_127 & V_138 ) >> 6 ) ) ;
V_116 -> V_123 . V_136 = 16 << ( ( V_127 & V_139 ) >> 4 ) ;
V_116 -> V_123 . V_27 = 4 ;
V_116 -> V_123 . V_25 = 0 ;
V_116 -> V_140 |= V_141 ;
V_116 -> V_140 |= V_144 ;
break;
case V_146 :
case V_69 :
case V_70 :
case V_147 :
case V_71 :
case V_72 :
case V_148 :
V_104 = 1 << ( 12 + ( ( V_127 & V_135 ) >> 9 ) ) ;
V_116 -> V_22 . V_136 = 16 << ( ( V_127 & V_137 ) >> 5 ) ;
V_116 -> V_22 . V_27 = 1 ;
V_116 -> V_22 . V_25 = 0 ;
V_103 = 1 << ( 12 + ( ( V_127 & V_138 ) >> 6 ) ) ;
V_116 -> V_123 . V_136 = 16 << ( ( V_127 & V_139 ) >> 4 ) ;
V_116 -> V_123 . V_27 = 1 ;
V_116 -> V_123 . V_25 = 0 ;
V_116 -> V_140 |= V_141 ;
break;
case V_73 :
case V_74 :
case V_75 :
V_104 = 1 << ( 12 + ( ( V_127 & V_149 ) >> 29 ) ) ;
V_116 -> V_22 . V_136 = 64 ;
V_116 -> V_22 . V_27 = 2 ;
V_116 -> V_22 . V_25 = 0 ;
V_103 = 1 << ( 12 + ( ( V_127 & V_150 ) >> 26 ) ) ;
V_116 -> V_123 . V_136 = 32 ;
V_116 -> V_123 . V_27 = 2 ;
V_116 -> V_123 . V_25 = 0 ;
V_116 -> V_140 |= V_144 ;
break;
case V_151 :
F_106 ( V_127 & ~ V_152 ) ;
case V_153 :
if ( V_116 -> V_118 == 0x0c80U || V_116 -> V_118 == 0x0c81U ||
V_116 -> V_118 == 0x0c82U ) {
V_127 |= 0x00400000U ;
if ( V_116 -> V_118 == 0x0c80U )
V_127 |= V_154 ;
F_106 ( V_127 ) ;
} else
V_116 -> V_140 |= V_141 ;
V_104 = 1 << ( 10 + ( ( V_127 & V_135 ) >> 9 ) ) ;
V_116 -> V_22 . V_136 = 16 << ( ( V_127 & V_137 ) >> 5 ) ;
V_116 -> V_22 . V_27 = 2 ;
V_116 -> V_22 . V_25 = F_105 ( V_104 / 2 ) ;
V_103 = 1 << ( 10 + ( ( V_127 & V_138 ) >> 6 ) ) ;
V_116 -> V_123 . V_136 = 16 << ( ( V_127 & V_139 ) >> 4 ) ;
V_116 -> V_123 . V_27 = 2 ;
V_116 -> V_123 . V_25 = F_105 ( V_103 / 2 ) ;
break;
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
V_104 = 1 << ( 10 + ( ( V_127 & V_135 ) >> 9 ) ) ;
V_116 -> V_22 . V_136 = 16 << ( ( V_127 & V_137 ) >> 5 ) ;
V_116 -> V_22 . V_27 = 1 ;
V_116 -> V_22 . V_25 = 0 ;
V_103 = 1 << ( 10 + ( ( V_127 & V_138 ) >> 6 ) ) ;
V_116 -> V_123 . V_136 = 16 << ( ( V_127 & V_139 ) >> 4 ) ;
V_116 -> V_123 . V_27 = 1 ;
V_116 -> V_123 . V_25 = 0 ;
V_116 -> V_140 |= V_141 ;
break;
case V_161 :
F_94 () ;
V_104 = 1 << ( 12 + ( ( V_127 & V_135 ) >> 9 ) ) ;
V_116 -> V_22 . V_136 = 16 << ( ( V_127 & V_137 ) >> 5 ) ;
V_116 -> V_22 . V_27 = 4 ;
V_116 -> V_22 . V_25 = F_105 ( V_104 / V_116 -> V_22 . V_27 ) ;
V_103 = 1 << ( 12 + ( ( V_127 & V_138 ) >> 6 ) ) ;
V_116 -> V_123 . V_136 = 16 << ( ( V_127 & V_139 ) >> 4 ) ;
V_116 -> V_123 . V_27 = 4 ;
V_116 -> V_123 . V_25 = F_105 ( V_103 / V_116 -> V_123 . V_27 ) ;
V_116 -> V_140 |= V_141 ;
V_116 -> V_140 |= V_144 ;
break;
case V_38 :
V_104 = 1 << ( 12 + ( ( V_127 & V_135 ) >> 9 ) ) ;
V_116 -> V_22 . V_136 = 16 << ( ( V_127 & V_137 ) >> 5 ) ;
if ( V_128 & 0x3 )
V_116 -> V_22 . V_27 = 4 ;
else
V_116 -> V_22 . V_27 = 2 ;
V_116 -> V_22 . V_25 = 0 ;
V_103 = 1 << ( 12 + ( ( V_127 & V_138 ) >> 6 ) ) ;
V_116 -> V_123 . V_136 = 16 << ( ( V_127 & V_139 ) >> 4 ) ;
if ( V_128 & 0x3 )
V_116 -> V_123 . V_27 = 4 ;
else
V_116 -> V_123 . V_27 = 2 ;
V_116 -> V_123 . V_25 = 0 ;
break;
default:
if ( ! ( V_127 & V_162 ) )
F_107 ( L_1 ) ;
V_129 = F_108 () ;
if ( ( V_130 = ( ( V_129 >> 19 ) & 7 ) ) )
V_116 -> V_22 . V_136 = 2 << V_130 ;
else
V_116 -> V_22 . V_136 = V_130 ;
V_116 -> V_22 . V_163 = 32 << ( ( ( V_129 >> 22 ) + 1 ) & 7 ) ;
V_116 -> V_22 . V_27 = 1 + ( ( V_129 >> 16 ) & 7 ) ;
V_104 = V_116 -> V_22 . V_163 *
V_116 -> V_22 . V_27 *
V_116 -> V_22 . V_136 ;
V_116 -> V_22 . V_25 = F_105 ( V_104 / V_116 -> V_22 . V_27 ) ;
if ( V_127 & 0x8 )
V_116 -> V_22 . V_17 |= V_124 ;
V_116 -> V_123 . V_17 = 0 ;
if ( ( V_130 = ( ( V_129 >> 10 ) & 7 ) ) )
V_116 -> V_123 . V_136 = 2 << V_130 ;
else
V_116 -> V_123 . V_136 = V_130 ;
V_116 -> V_123 . V_163 = 32 << ( ( ( V_129 >> 13 ) + 1 ) & 7 ) ;
V_116 -> V_123 . V_27 = 1 + ( ( V_129 >> 7 ) & 7 ) ;
V_103 = V_116 -> V_123 . V_163 *
V_116 -> V_123 . V_27 *
V_116 -> V_123 . V_136 ;
V_116 -> V_123 . V_25 = F_105 ( V_103 / V_116 -> V_123 . V_27 ) ;
V_116 -> V_140 |= V_144 ;
break;
}
if ( ( V_128 & V_119 ) == V_164 &&
( V_128 & V_121 ) < V_165 &&
! ( V_127 & V_166 ) && V_116 -> V_22 . V_136 != 16 &&
V_34 <= 0x8000 )
F_107 ( L_2 ) ;
V_116 -> V_22 . V_23 = V_104 / V_116 -> V_22 . V_27 ;
V_116 -> V_123 . V_23 = V_103 / V_116 -> V_123 . V_27 ;
V_116 -> V_22 . V_163 = V_116 -> V_22 . V_136 ?
V_104 / ( V_116 -> V_22 . V_136 * V_116 -> V_22 . V_27 ) : 0 ;
V_116 -> V_123 . V_163 = V_116 -> V_123 . V_136 ?
V_103 / ( V_116 -> V_123 . V_136 * V_116 -> V_123 . V_27 ) : 0 ;
switch ( F_27 () ) {
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
V_116 -> V_123 . V_17 |= V_172 ;
break;
case V_73 :
case V_74 :
case V_75 :
break;
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
if ( F_27 () == V_177 )
F_97 ( V_116 ) ;
if ( ( F_109 () & ( 1 << 16 ) ) ) {
V_116 -> V_123 . V_17 |= V_172 ;
break;
}
default:
if ( V_116 -> V_123 . V_23 > V_34 )
V_116 -> V_123 . V_17 |= V_179 ;
}
switch ( F_27 () ) {
case V_167 :
V_116 -> V_22 . V_17 |= V_124 ;
break;
case V_180 :
V_116 -> V_22 . V_17 |= V_181 ;
break;
case V_38 :
V_116 -> V_22 . V_27 = 1 ;
}
F_110 ( L_3 ,
V_104 >> 10 ,
V_116 -> V_22 . V_17 & V_124 ? L_4 : L_5 ,
V_182 [ V_116 -> V_22 . V_27 ] , V_116 -> V_22 . V_136 ) ;
F_110 ( L_6 ,
V_103 >> 10 , V_182 [ V_116 -> V_123 . V_27 ] ,
( V_116 -> V_123 . V_17 & V_172 ) ? L_7 : L_5 ,
( V_116 -> V_123 . V_17 & V_179 ) ?
L_8 : L_9 ,
V_116 -> V_123 . V_136 ) ;
}
static int F_111 ( void )
{
unsigned long V_17 , V_4 , V_183 , V_20 , V_184 ;
unsigned int V_127 = F_103 () ;
struct V_115 * V_116 = & V_21 ;
if ( V_127 & V_166 )
return 0 ;
V_183 = ( unsigned long ) & V_185 ;
V_183 &= ~ ( ( 4 * 1024 * 1024 ) - 1 ) ;
V_20 = V_183 + ( 4 * 1024 * 1024 ) ;
F_17 ( V_17 ) ;
V_184 = ( 64 * 1024 ) ;
for ( V_4 = V_183 ; V_4 < V_20 ; V_4 = ( V_183 + V_184 ) ) {
unsigned long * V_186 = ( unsigned long * ) V_4 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_184 <<= 1 ;
}
F_95 ( 0 ) ;
F_96 ( 0 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
F_112 ( V_187 , V_183 ) ;
F_112 ( V_188 , V_183 ) ;
F_112 ( V_189 , V_183 ) ;
V_184 = ( 128 * 1024 ) ;
for ( V_4 = V_183 + ( 128 * 1024 ) ; V_4 < V_20 ; V_4 = V_183 + V_184 ) {
F_112 ( V_190 , V_4 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
if ( ! F_113 () )
break;
V_184 <<= 1 ;
}
F_19 ( V_17 ) ;
V_4 -= V_183 ;
V_53 = V_4 ;
V_116 -> V_191 . V_136 = 16 << ( ( V_127 & V_192 ) >> 22 ) ;
V_116 -> V_191 . V_27 = 1 ;
V_116 -> V_123 . V_25 = 0 ;
return 1 ;
}
static void T_5 F_114 ( void )
{
struct V_115 * V_116 = & V_21 ;
V_53 = 512 * 1024 ;
V_116 -> V_191 . V_136 = 32 ;
V_116 -> V_191 . V_27 = 4 ;
V_116 -> V_191 . V_25 = 0 ;
V_116 -> V_191 . V_23 = V_53 / ( V_116 -> V_191 . V_27 ) ;
V_116 -> V_191 . V_163 = V_53 / ( V_116 -> V_191 . V_136 * V_116 -> V_191 . V_27 ) ;
F_115 ( L_10 ,
V_53 >> 10 , V_182 [ V_116 -> V_191 . V_27 ] , V_116 -> V_191 . V_136 ) ;
V_116 -> V_140 |= V_193 ;
}
static void F_116 ( void )
{
struct V_115 * V_116 = & V_21 ;
unsigned int V_127 = F_103 () ;
int V_194 = 0 ;
switch ( F_27 () ) {
case V_69 :
case V_70 :
case V_71 :
case V_72 :
V_194 = F_117 ( F_111 ) ;
if ( V_194 )
V_116 -> V_140 |= V_195 ;
break;
case V_73 :
case V_74 :
case V_75 :
V_53 = 0x80000 << ( ( V_127 & V_196 ) >> 16 ) ;
V_116 -> V_191 . V_136 = 64 << ( ( V_127 >> 13 ) & 1 ) ;
V_116 -> V_191 . V_27 = 2 ;
V_116 -> V_191 . V_25 = 0 ;
V_194 = 1 ;
break;
case V_133 :
case V_134 :
#ifdef F_118
F_119 () ;
#endif
return;
case V_161 :
#ifdef F_120
F_121 () ;
#endif
return;
case V_38 :
F_114 () ;
return;
case V_197 :
return;
default:
if ( V_116 -> V_198 & ( V_199 | V_200 |
V_201 | V_202 ) ) {
#ifdef F_122
if ( F_123 () ) {
V_53 = V_116 -> V_191 . V_27 * V_116 -> V_191 . V_163 * V_116 -> V_191 . V_136 ;
F_110 ( L_11 ,
V_53 >> 10 ,
V_182 [ V_116 -> V_191 . V_27 ] , V_116 -> V_191 . V_136 ) ;
}
#else
if ( ! ( V_116 -> V_191 . V_17 & V_203 ) )
F_107 ( L_12 ) ;
#endif
return;
}
V_194 = 0 ;
}
if ( ! V_194 )
return;
V_116 -> V_191 . V_23 = V_53 / V_116 -> V_191 . V_27 ;
V_116 -> V_191 . V_163 = V_53 / ( V_116 -> V_191 . V_136 * V_116 -> V_191 . V_27 ) ;
F_110 ( L_10 ,
V_53 >> 10 , V_182 [ V_116 -> V_191 . V_27 ] , V_116 -> V_191 . V_136 ) ;
V_116 -> V_140 |= V_193 ;
}
void F_124 ( void )
{
switch ( F_104 () ) {
case 0x00030100 :
case 0x00030201 :
case 0x00030202 :
case 0x01030200 :
case 0x02030200 :
case 0x02030201 :
case 0x02030202 :
F_125 ( 1 << 19 ) ;
break;
}
}
static void F_126 ( void )
{
unsigned long V_204 ;
V_204 = F_103 () ;
V_204 &= ~ ( 0x7 | ( 7 << 25 ) | ( 7 << 28 ) ) ;
V_204 |= ( ( ( V_205 >> V_206 ) << 0 ) |
( ( V_205 >> V_206 ) << 25 ) |
( ( V_205 >> V_206 ) << 28 ) ) ;
F_106 ( V_204 ) ;
F_127 () ;
}
static int T_5 F_128 ( char * V_207 )
{
F_129 ( & V_207 , & V_208 ) ;
return 0 ;
}
static void F_130 ( void )
{
if ( V_208 < 0 || V_208 > 7 )
V_208 = F_103 () & V_209 ;
V_205 = V_208 << V_206 ;
F_131 ( L_13 , V_208 ) ;
F_132 ( V_209 , V_208 ) ;
switch ( F_27 () ) {
case V_146 :
case V_69 :
case V_70 :
case V_147 :
case V_71 :
case V_72 :
F_133 ( V_210 ) ;
break;
case V_180 :
F_124 () ;
break;
case V_211 :
F_126 () ;
break;
}
}
static void F_134 ( void )
{
extern char __weak V_212 ;
extern char __weak V_213 ;
switch ( F_27 () ) {
case V_169 :
case V_170 :
F_135 ( 0x100 , & V_213 , 0x80 ) ;
break;
default:
F_135 ( 0x100 , & V_212 , 0x80 ) ;
break;
}
}
void F_136 ( void )
{
extern void V_214 ( void ) ;
extern void V_215 ( void ) ;
struct V_115 * V_116 = & V_21 ;
F_102 () ;
F_116 () ;
F_12 () ;
F_14 () ;
F_15 () ;
F_25 () ;
F_28 () ;
F_30 () ;
F_31 () ;
F_33 () ;
F_34 () ;
if ( V_116 -> V_123 . V_136 )
V_216 = F_137 ( unsigned long,
c->dcache.sets * c->dcache.linesz - 1 ,
PAGE_SIZE - 1 ) ;
else
V_216 = V_34 - 1 ;
V_217 = F_41 ;
V_218 = F_42 ;
V_219 = F_7 ;
V_220 = F_36 ;
V_221 = F_46 ;
V_222 = F_62 ;
V_223 = F_44 ;
V_224 = F_93 ;
V_225 = F_90 ;
V_226 = F_91 ;
V_227 = F_63 ;
V_228 = F_64 ;
V_229 = F_72 ;
V_230 = F_66 ;
#if F_4 ( V_231 )
if ( V_232 ) {
V_233 = ( void * ) F_7 ;
V_234 = ( void * ) F_7 ;
V_235 = ( void * ) F_7 ;
} else {
V_233 = F_74 ;
V_234 = F_74 ;
V_235 = F_80 ;
}
#endif
V_214 () ;
V_215 () ;
F_35 ( NULL ) ;
F_130 () ;
V_236 = F_134 ;
}
