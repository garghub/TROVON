static inline bool F_1 ( unsigned int type )
{
if ( type == V_1 && F_2 () )
return false ;
#ifdef F_3
return ! F_4 ( & V_2 [ 0 ] ) ;
#else
return false ;
#endif
}
static inline void F_5 ( unsigned int type ,
void (* F_6)( void * V_3 ) , void * V_3 )
{
F_7 () ;
if ( F_1 ( type ) )
F_8 ( & V_2 [ F_9 () ] ,
F_6 , V_3 , 1 ) ;
F_6 ( V_3 ) ;
F_10 () ;
}
static void F_11 ( void ) {}
static inline void F_12 ( unsigned long V_4 )
{
V_5 ;
F_13 ( V_4 ) ;
}
static inline void F_14 ( unsigned long V_4 )
{
F_15 ( V_4 ) ;
}
static inline void F_16 ( unsigned long V_4 )
{
F_17 ( V_4 ) ;
}
static void F_18 ( void )
{
unsigned long V_6 = F_19 () ;
switch ( V_6 ) {
case 0 :
V_7 = ( void * ) F_11 ;
break;
case 16 :
V_7 = V_8 ;
break;
case 32 :
V_7 = F_12 ;
break;
case 64 :
V_7 = F_14 ;
break;
case 128 :
V_7 = F_16 ;
break;
default:
break;
}
}
static void F_20 ( void )
{
unsigned long V_6 = F_19 () ;
if ( V_6 == 0 )
V_9 = ( void * ) F_11 ;
else if ( V_6 == 16 )
V_9 = V_10 ;
else if ( V_6 == 32 )
V_9 = V_11 ;
else if ( V_6 == 64 )
V_9 = V_12 ;
}
static void F_21 ( void )
{
unsigned long V_6 = F_19 () ;
if ( V_6 == 0 )
V_13 = ( void * ) F_11 ;
else if ( V_6 == 16 )
V_13 = V_14 ;
else if ( V_6 == 32 )
V_13 = V_15 ;
else if ( V_6 == 64 )
V_13 = V_16 ;
else if ( V_6 == 128 )
V_13 = V_17 ;
}
static void F_22 ( void )
{
unsigned long V_6 = F_19 () ;
if ( V_6 == 0 )
V_18 = ( void * ) F_11 ;
else if ( V_6 == 16 )
V_18 = V_19 ;
else if ( V_6 == 32 )
V_18 = V_20 ;
else if ( V_6 == 64 )
V_18 = V_21 ;
else if ( V_6 == 128 )
V_18 = V_22 ;
}
static inline void F_23 ( void )
{
unsigned long V_23 ;
F_24 ( V_23 ) ;
F_25 () ;
F_26 ( V_23 ) ;
}
static inline void F_27 ( void )
{
unsigned long V_24 = V_25 ;
unsigned long V_26 = V_24 + V_27 . V_28 . V_29 ;
unsigned long V_30 = 1UL << V_27 . V_28 . V_31 ;
unsigned long V_32 = V_27 . V_28 . V_33 <<
V_27 . V_28 . V_31 ;
unsigned long V_34 , V_4 ;
V_35 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 += V_30 )
for ( V_4 = V_24 + 0x400 ; V_4 < V_26 ; V_4 += 0x400 * 2 )
F_28 ( V_4 | V_34 , V_36 ) ;
V_37 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 += V_30 )
for ( V_4 = V_24 ; V_4 < V_26 ; V_4 += 0x400 * 2 )
F_28 ( V_4 | V_34 , V_36 ) ;
}
static inline void F_29 ( unsigned long V_38 )
{
unsigned long V_23 ;
F_24 ( V_23 ) ;
F_30 ( V_38 ) ;
F_26 ( V_23 ) ;
}
static inline void F_31 ( unsigned long V_38 )
{
unsigned long V_39 = V_27 . V_28 . V_29 - 1 ;
unsigned long V_24 = V_25 + ( V_38 & V_39 ) ;
unsigned long V_26 = V_24 + V_40 ;
unsigned long V_30 = 1UL << V_27 . V_28 . V_31 ;
unsigned long V_32 = V_27 . V_28 . V_33 <<
V_27 . V_28 . V_31 ;
unsigned long V_34 , V_4 ;
V_35 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 += V_30 )
for ( V_4 = V_24 + 0x400 ; V_4 < V_26 ; V_4 += 0x400 * 2 )
F_28 ( V_4 | V_34 , V_36 ) ;
V_37 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 += V_30 )
for ( V_4 = V_24 ; V_4 < V_26 ; V_4 += 0x400 * 2 )
F_28 ( V_4 | V_34 , V_36 ) ;
}
static void F_32 ( void )
{
unsigned long V_41 = F_33 () ;
if ( V_41 == 0 )
V_42 = ( void * ) F_11 ;
else if ( V_41 == 16 )
V_42 = V_43 ;
else if ( V_41 == 32 && F_34 () == V_44 )
V_42 = V_45 ;
else if ( V_41 == 32 )
V_42 = V_46 ;
else if ( V_41 == 64 )
V_42 = V_47 ;
else if ( V_41 == 128 )
V_42 = V_48 ;
}
static void F_35 ( void )
{
unsigned long V_41 = F_33 () ;
if ( V_41 == 0 )
V_49 = ( void * ) F_11 ;
else if ( V_41 == 16 )
V_49 = V_50 ;
else if ( V_41 == 32 )
V_49 = V_51 ;
else if ( V_41 == 64 )
V_49 = V_52 ;
}
static void F_36 ( void )
{
unsigned long V_41 = F_33 () ;
if ( V_41 == 0 )
V_53 = ( void * ) F_11 ;
else if ( V_41 == 16 )
V_53 = V_54 ;
else if ( V_41 == 32 ) {
if ( V_55 && F_37 () )
V_53 =
F_29 ;
else if ( V_56 )
V_53 =
F_31 ;
else if ( F_34 () == V_44 )
V_53 =
V_57 ;
else
V_53 =
F_30 ;
} else if ( V_41 == 64 )
V_53 = V_58 ;
}
static void F_38 ( void )
{
unsigned long V_41 = F_33 () ;
if ( V_41 == 0 )
V_59 = ( void * ) F_11 ;
else if ( V_41 == 16 )
V_59 = V_60 ;
else if ( V_41 == 32 ) {
if ( V_55 && F_37 () )
V_59 = F_23 ;
else if ( V_56 )
V_59 = F_27 ;
else if ( F_34 () == V_44 )
V_59 = V_61 ;
else
V_59 = F_25 ;
} else if ( V_41 == 64 )
V_59 = V_62 ;
else if ( V_41 == 128 )
V_59 = V_63 ;
}
static void F_39 ( void )
{
unsigned long V_64 = F_40 () ;
if ( V_65 == 0 )
V_66 = ( void * ) F_11 ;
else if ( V_64 == 16 )
V_66 = V_67 ;
else if ( V_64 == 32 )
V_66 = V_68 ;
else if ( V_64 == 64 )
V_66 = V_69 ;
else if ( V_64 == 128 )
V_66 = V_70 ;
}
static void F_41 ( void )
{
unsigned long V_64 = F_40 () ;
if ( V_65 == 0 )
V_71 = ( void * ) F_11 ;
else if ( V_64 == 16 )
V_71 = V_72 ;
else if ( V_64 == 32 )
V_71 = V_73 ;
else if ( V_64 == 64 )
V_71 = V_74 ;
else if ( V_64 == 128 )
V_71 = V_75 ;
}
static void F_42 ( void )
{
unsigned long V_64 = F_40 () ;
if ( V_65 == 0 )
V_76 = ( void * ) F_11 ;
else if ( V_64 == 16 )
V_76 = V_77 ;
else if ( V_64 == 32 )
V_76 = V_78 ;
else if ( V_64 == 64 )
V_76 = V_79 ;
else if ( V_64 == 128 )
V_76 = V_80 ;
}
static inline void F_43 ( void * args )
{
switch ( F_34 () ) {
case V_44 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_76 () ;
break;
case V_90 :
V_76 () ;
F_44 () ;
break;
default:
V_18 () ;
V_59 () ;
break;
}
}
static void F_45 ( void )
{
F_5 ( V_91 , F_43 , NULL ) ;
}
static inline int F_46 ( const struct V_92 * V_93 , unsigned int type )
{
unsigned int V_94 ;
const T_1 * V_95 = V_96 ;
#ifdef F_3
if ( F_1 ( type ) )
V_95 = & V_97 [ F_9 () ] ;
#endif
F_47 (i, mask)
if ( F_48 ( V_94 , V_93 ) )
return 1 ;
return 0 ;
}
static void F_49 ( void )
{
V_18 () ;
}
static void F_50 ( void )
{
V_18 () ;
}
static inline void F_51 ( void * args )
{
struct V_98 * V_99 = args ;
int V_100 = V_99 -> V_101 & V_102 ;
if ( ! F_46 ( V_99 -> V_103 , V_91 ) )
return;
if ( V_104 || ( V_100 && ! V_105 ) )
V_18 () ;
if ( V_100 )
V_59 () ;
}
static void F_52 ( struct V_98 * V_99 ,
unsigned long V_24 , unsigned long V_26 )
{
int V_100 = V_99 -> V_101 & V_102 ;
if ( V_104 || V_100 )
F_5 ( V_91 , F_51 , V_99 ) ;
}
static inline void F_53 ( void * args )
{
struct V_92 * V_93 = args ;
if ( ! F_46 ( V_93 , V_91 ) )
return;
if ( F_34 () == V_82 ||
F_34 () == V_83 ||
F_34 () == V_84 ||
F_34 () == V_85 ) {
V_76 () ;
return;
}
V_18 () ;
}
static void F_54 ( struct V_92 * V_93 )
{
if ( ! V_104 )
return;
F_5 ( V_91 , F_53 , V_93 ) ;
}
static inline void F_55 ( void * args )
{
struct V_106 * V_107 = args ;
struct V_98 * V_99 = V_107 -> V_99 ;
unsigned long V_4 = V_107 -> V_4 ;
struct V_38 * V_38 = F_56 ( V_107 -> V_108 ) ;
int V_100 = V_99 -> V_101 & V_102 ;
struct V_92 * V_93 = V_99 -> V_103 ;
int V_109 = 0 ;
T_2 * V_110 ;
T_3 * V_111 ;
T_4 * V_112 ;
T_5 * V_113 ;
void * V_114 ;
if ( ! F_46 ( V_93 , V_1 ) )
return;
V_4 &= V_115 ;
V_110 = F_57 ( V_93 , V_4 ) ;
V_111 = F_58 ( V_110 , V_4 ) ;
V_112 = F_59 ( V_111 , V_4 ) ;
V_113 = F_60 ( V_112 , V_4 ) ;
if ( ! ( F_61 ( * V_113 ) ) )
return;
if ( ( V_93 == V_116 -> V_117 ) && ( F_62 ( * V_113 ) & V_118 ) )
V_114 = NULL ;
else {
V_109 = ( V_104 &&
F_63 ( V_38 ) &&
! F_64 ( V_38 ) ) ;
if ( V_109 )
V_114 = F_65 ( V_38 , V_4 ) ;
else
V_114 = F_66 ( V_38 ) ;
V_4 = ( unsigned long ) V_114 ;
}
if ( V_104 || ( V_100 && ! V_105 ) ) {
V_114 ? V_7 ( V_4 ) :
V_9 ( V_4 ) ;
if ( V_100 && ! V_119 )
V_66 ( V_4 ) ;
}
if ( V_100 ) {
if ( V_114 && V_120 && V_93 == V_116 -> V_117 ) {
int V_121 = F_9 () ;
if ( F_48 ( V_121 , V_93 ) != 0 )
F_67 ( V_93 , V_121 ) ;
} else
V_114 ? V_42 ( V_4 ) :
V_49 ( V_4 ) ;
}
if ( V_114 ) {
if ( V_109 )
F_68 () ;
else
F_69 ( V_114 ) ;
}
}
static void F_70 ( struct V_98 * V_99 ,
unsigned long V_4 , unsigned long V_108 )
{
struct V_106 args ;
args . V_99 = V_99 ;
args . V_4 = V_4 ;
args . V_108 = V_108 ;
F_5 ( V_1 , F_55 , & args ) ;
}
static inline void F_71 ( void * V_4 )
{
V_7 ( ( unsigned long ) V_4 ) ;
}
static void F_72 ( unsigned long V_4 )
{
if ( F_73 () )
F_71 ( ( void * ) V_4 ) ;
else
F_5 ( V_1 , F_71 ,
( void * ) V_4 ) ;
}
static inline void F_74 ( unsigned long V_24 ,
unsigned long V_26 ,
unsigned int type )
{
if ( ! V_105 ) {
if ( type == V_91 ||
( type & V_91 && V_26 - V_24 >= V_122 ) ) {
V_18 () ;
} else {
V_5 ;
F_75 ( V_24 , V_26 ) ;
}
}
if ( type == V_91 ||
( type & V_91 && V_26 - V_24 > V_123 ) )
V_59 () ;
else {
switch ( F_76 () ) {
case V_44 :
F_77 ( V_24 , V_26 ) ;
break;
default:
F_78 ( V_24 , V_26 ) ;
break;
}
}
#ifdef F_79
F_80 ( V_24 , ( V_26 - V_24 ) ) ;
F_44 () ;
#endif
}
static inline void F_81 ( unsigned long V_24 ,
unsigned long V_26 )
{
F_74 ( V_24 , V_26 , V_1 | V_91 ) ;
}
static inline void F_82 ( void * args )
{
struct V_124 * V_125 = args ;
unsigned long V_24 = V_125 -> V_24 ;
unsigned long V_26 = V_125 -> V_26 ;
unsigned int type = V_125 -> type ;
F_74 ( V_24 , V_26 , type ) ;
}
static void F_83 ( unsigned long V_24 , unsigned long V_26 )
{
struct V_124 args ;
unsigned long V_126 , V_127 ;
args . V_24 = V_24 ;
args . V_26 = V_26 ;
args . type = V_1 | V_91 ;
F_7 () ;
if ( F_1 ( V_91 ) && ! F_1 ( V_1 ) ) {
V_126 = V_26 - V_24 ;
V_127 = V_123 ;
if ( ! V_105 ) {
V_126 *= 2 ;
V_127 += V_122 ;
}
if ( V_126 <= V_127 )
args . type &= ~ V_91 ;
}
F_5 ( args . type , F_82 , & args ) ;
F_10 () ;
F_84 () ;
}
static void F_85 ( unsigned long V_4 , unsigned long V_126 )
{
F_86 ( V_126 == 0 ) ;
F_7 () ;
if ( V_128 ) {
if ( V_126 >= V_65 )
V_76 () ;
else
F_87 ( V_4 , V_4 + V_126 ) ;
F_10 () ;
F_44 () ;
return;
}
if ( V_126 >= V_122 ) {
V_18 () ;
} else {
V_5 ;
F_88 ( V_4 , V_4 + V_126 ) ;
}
F_10 () ;
F_80 ( V_4 , V_126 ) ;
F_44 () ;
}
static void F_89 ( unsigned long V_4 , unsigned long V_126 )
{
F_86 ( V_126 == 0 ) ;
F_7 () ;
if ( V_128 ) {
if ( V_126 >= V_65 )
V_76 () ;
else {
F_90 ( V_4 , V_4 + V_126 ) ;
}
F_10 () ;
F_44 () ;
return;
}
if ( V_126 >= V_122 ) {
V_18 () ;
} else {
V_5 ;
F_91 ( V_4 , V_4 + V_126 ) ;
}
F_10 () ;
F_92 ( V_4 , V_126 ) ;
F_44 () ;
}
static void F_93 ( void * args )
{
struct V_129 * V_130 = args ;
unsigned long V_4 = V_130 -> V_4 ;
struct V_38 * V_38 = V_130 -> V_38 ;
struct V_92 * V_93 = V_130 -> V_93 ;
int V_109 = 0 ;
void * V_114 ;
unsigned long V_41 = F_33 () ;
unsigned long V_6 = F_19 () ;
unsigned long V_64 = F_40 () ;
if ( ! F_46 ( V_93 , V_1 ) )
return;
if ( V_93 == V_116 -> V_117 ) {
V_114 = NULL ;
} else {
V_109 = ( V_104 &&
F_63 ( V_38 ) &&
! F_64 ( V_38 ) ) ;
if ( V_109 )
V_114 = F_65 ( V_38 , V_4 ) ;
else
V_114 = F_66 ( V_38 ) ;
V_4 = ( unsigned long ) V_114 + ( V_4 & ~ V_115 ) ;
}
V_5 ;
if ( ! V_105 ) {
if ( V_6 )
V_114 ? F_94 ( V_4 & ~ ( V_6 - 1 ) )
: F_95 (
V_4 & ~ ( V_6 - 1 ) ) ;
if ( ! V_119 && V_65 )
V_114 ? F_96 ( V_4 & ~ ( V_64 - 1 ) )
: F_97 (
V_4 & ~ ( V_64 - 1 ) ) ;
}
if ( V_41 )
V_114 ? F_98 ( V_4 & ~ ( V_41 - 1 ) )
: F_99 ( V_4 & ~ ( V_41 - 1 ) ) ;
if ( V_114 ) {
if ( V_109 )
F_68 () ;
else
F_69 ( V_114 ) ;
}
if ( V_131 ) {
__asm__ __volatile__ (
".set push\n\t"
".set noat\n\t"
".set "MIPS_ISA_LEVEL"\n\t"
#ifdef F_100
"la $at,1f\n\t"
#endif
#ifdef F_101
"dla $at,1f\n\t"
#endif
"cache %0,($at)\n\t"
"nop; nop; nop\n"
"1:\n\t"
".set pop"
:
: "i" (Hit_Invalidate_I));
}
if ( V_132 )
__asm__ __volatile__ ("sync");
}
static void F_102 ( unsigned long V_4 )
{
struct V_129 args ;
int V_133 ;
F_103 ( & V_116 -> V_93 -> V_134 ) ;
V_133 = F_104 ( V_4 , 1 , 0 , & args . V_38 ) ;
if ( V_133 < 1 )
goto V_135;
args . V_93 = V_116 -> V_93 ;
args . V_4 = V_4 ;
F_5 ( V_1 , F_93 , & args ) ;
F_105 ( args . V_38 ) ;
V_135:
F_106 ( & V_116 -> V_93 -> V_134 ) ;
}
static void F_107 ( void )
{
if ( V_120 )
V_59 () ;
}
static inline void F_108 ( void * args )
{
V_18 () ;
}
static inline void F_109 ( void * args )
{
struct V_136 * V_137 = args ;
unsigned long V_114 = V_137 -> V_114 ;
int V_126 = V_137 -> V_126 ;
V_5 ;
F_88 ( V_114 , V_114 + V_126 ) ;
}
static void F_110 ( unsigned long V_114 , int V_126 )
{
struct V_136 args ;
args . V_114 = ( unsigned long ) V_114 ;
args . V_126 = V_126 ;
if ( V_126 >= V_122 )
F_5 ( V_91 ,
F_108 , NULL ) ;
else
F_5 ( V_1 , F_109 ,
& args ) ;
}
static inline void F_111 ( void )
{
const unsigned long V_41 = 32 ;
unsigned long V_4 ;
F_112 ( 0 ) ;
F_113 ( 0 ) ;
for ( V_4 = V_25 ; V_4 <= V_25 + 4096 ; V_4 += V_41 ) {
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
static inline int F_114 ( struct V_138 * V_139 )
{
unsigned int V_140 = V_139 -> V_141 & V_142 ;
unsigned int V_143 = V_139 -> V_141 & V_144 ;
int V_145 = 0 ;
switch ( V_140 ) {
case V_146 :
if ( V_143 <= F_115 ( 2 , 4 , 0 ) )
V_145 = 1 ;
if ( V_143 == F_115 ( 2 , 4 , 0 ) )
F_116 ( F_117 () | V_147 ) ;
break;
case V_148 :
if ( V_143 <= F_115 ( 1 , 1 , 0 ) ) {
V_145 = 1 ;
F_116 ( F_117 () | V_147 ) ;
}
break;
default:
F_118 () ;
}
return V_145 ;
}
static void F_119 ( void )
{
F_44 () ;
F_44 () ;
__asm__ __volatile__(
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
" nop; nop; nop; nop; nop; nop; nop; nop\n"
: : : "memory");
}
static void F_120 ( void )
{
struct V_138 * V_139 = & V_27 ;
unsigned int V_149 = F_121 () ;
unsigned int V_150 = F_122 () ;
int V_151 = 0 ;
unsigned long V_152 ;
unsigned int V_153 ;
switch ( F_34 () ) {
case V_154 :
case V_155 :
case V_156 :
case V_157 :
V_123 = 1 << ( 12 + ( ( V_149 & V_158 ) >> 9 ) ) ;
V_139 -> V_28 . V_159 = 16 << ( ( V_149 & V_160 ) >> 5 ) ;
V_139 -> V_28 . V_33 = 2 ;
V_139 -> V_28 . V_31 = F_123 ( V_123 / 2 ) ;
V_122 = 1 << ( 12 + ( ( V_149 & V_161 ) >> 6 ) ) ;
V_139 -> V_162 . V_159 = 16 << ( ( V_149 & V_163 ) >> 4 ) ;
V_139 -> V_162 . V_33 = 2 ;
V_139 -> V_162 . V_31 = F_123 ( V_122 / 2 ) ;
V_139 -> V_164 |= V_165 ;
break;
case V_166 :
case V_167 :
V_123 = 1 << ( 12 + ( ( V_149 & V_158 ) >> 9 ) ) ;
V_139 -> V_28 . V_159 = 16 << ( ( V_149 & V_160 ) >> 5 ) ;
V_139 -> V_28 . V_33 = 2 ;
V_139 -> V_28 . V_31 = 0 ;
V_122 = 1 << ( 12 + ( ( V_149 & V_161 ) >> 6 ) ) ;
V_139 -> V_162 . V_159 = 16 << ( ( V_149 & V_163 ) >> 4 ) ;
V_139 -> V_162 . V_33 = 2 ;
V_139 -> V_162 . V_31 = 0 ;
V_139 -> V_164 |= V_165 | V_168 ;
break;
case V_169 :
V_123 = 1 << ( 12 + ( ( V_149 & V_158 ) >> 9 ) ) ;
V_139 -> V_28 . V_159 = 16 << ( ( V_149 & V_160 ) >> 5 ) ;
V_139 -> V_28 . V_33 = 4 ;
V_139 -> V_28 . V_31 = 0 ;
V_122 = 1 << ( 12 + ( ( V_149 & V_161 ) >> 6 ) ) ;
V_139 -> V_162 . V_159 = 16 << ( ( V_149 & V_163 ) >> 4 ) ;
V_139 -> V_162 . V_33 = 4 ;
V_139 -> V_162 . V_31 = 0 ;
V_139 -> V_164 |= V_165 ;
V_139 -> V_164 |= V_168 ;
break;
case V_170 :
case V_82 :
case V_83 :
case V_171 :
case V_84 :
case V_85 :
case V_172 :
V_123 = 1 << ( 12 + ( ( V_149 & V_158 ) >> 9 ) ) ;
V_139 -> V_28 . V_159 = 16 << ( ( V_149 & V_160 ) >> 5 ) ;
V_139 -> V_28 . V_33 = 1 ;
V_139 -> V_28 . V_31 = 0 ;
V_122 = 1 << ( 12 + ( ( V_149 & V_161 ) >> 6 ) ) ;
V_139 -> V_162 . V_159 = 16 << ( ( V_149 & V_163 ) >> 4 ) ;
V_139 -> V_162 . V_33 = 1 ;
V_139 -> V_162 . V_31 = 0 ;
V_139 -> V_164 |= V_165 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_123 = 1 << ( 12 + ( ( V_149 & V_173 ) >> 29 ) ) ;
V_139 -> V_28 . V_159 = 64 ;
V_139 -> V_28 . V_33 = 2 ;
V_139 -> V_28 . V_31 = 0 ;
V_122 = 1 << ( 12 + ( ( V_149 & V_174 ) >> 26 ) ) ;
V_139 -> V_162 . V_159 = 32 ;
V_139 -> V_162 . V_33 = 2 ;
V_139 -> V_162 . V_31 = 0 ;
V_139 -> V_164 |= V_168 ;
break;
case V_175 :
F_124 ( V_149 & ~ V_176 ) ;
case V_177 :
if ( V_139 -> V_141 == 0x0c80U || V_139 -> V_141 == 0x0c81U ||
V_139 -> V_141 == 0x0c82U ) {
V_149 |= 0x00400000U ;
if ( V_139 -> V_141 == 0x0c80U )
V_149 |= V_178 ;
F_124 ( V_149 ) ;
} else
V_139 -> V_164 |= V_165 ;
V_123 = 1 << ( 10 + ( ( V_149 & V_158 ) >> 9 ) ) ;
V_139 -> V_28 . V_159 = 16 << ( ( V_149 & V_160 ) >> 5 ) ;
V_139 -> V_28 . V_33 = 2 ;
V_139 -> V_28 . V_31 = F_123 ( V_123 / 2 ) ;
V_122 = 1 << ( 10 + ( ( V_149 & V_161 ) >> 6 ) ) ;
V_139 -> V_162 . V_159 = 16 << ( ( V_149 & V_163 ) >> 4 ) ;
V_139 -> V_162 . V_33 = 2 ;
V_139 -> V_162 . V_31 = F_123 ( V_122 / 2 ) ;
break;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
V_123 = 1 << ( 10 + ( ( V_149 & V_158 ) >> 9 ) ) ;
V_139 -> V_28 . V_159 = 16 << ( ( V_149 & V_160 ) >> 5 ) ;
V_139 -> V_28 . V_33 = 1 ;
V_139 -> V_28 . V_31 = 0 ;
V_122 = 1 << ( 10 + ( ( V_149 & V_161 ) >> 6 ) ) ;
V_139 -> V_162 . V_159 = 16 << ( ( V_149 & V_163 ) >> 4 ) ;
V_139 -> V_162 . V_33 = 1 ;
V_139 -> V_162 . V_31 = 0 ;
V_139 -> V_164 |= V_165 ;
break;
case V_185 :
F_111 () ;
V_123 = 1 << ( 12 + ( ( V_149 & V_158 ) >> 9 ) ) ;
V_139 -> V_28 . V_159 = 16 << ( ( V_149 & V_160 ) >> 5 ) ;
V_139 -> V_28 . V_33 = 4 ;
V_139 -> V_28 . V_31 = F_123 ( V_123 / V_139 -> V_28 . V_33 ) ;
V_122 = 1 << ( 12 + ( ( V_149 & V_161 ) >> 6 ) ) ;
V_139 -> V_162 . V_159 = 16 << ( ( V_149 & V_163 ) >> 4 ) ;
V_139 -> V_162 . V_33 = 4 ;
V_139 -> V_162 . V_31 = F_123 ( V_122 / V_139 -> V_162 . V_33 ) ;
V_139 -> V_164 |= V_165 ;
V_139 -> V_164 |= V_168 ;
break;
case V_44 :
V_123 = 1 << ( 12 + ( ( V_149 & V_158 ) >> 9 ) ) ;
V_139 -> V_28 . V_159 = 16 << ( ( V_149 & V_160 ) >> 5 ) ;
if ( V_150 & 0x3 )
V_139 -> V_28 . V_33 = 4 ;
else
V_139 -> V_28 . V_33 = 2 ;
V_139 -> V_28 . V_31 = 0 ;
V_122 = 1 << ( 12 + ( ( V_149 & V_161 ) >> 6 ) ) ;
V_139 -> V_162 . V_159 = 16 << ( ( V_149 & V_163 ) >> 4 ) ;
if ( V_150 & 0x3 )
V_139 -> V_162 . V_33 = 4 ;
else
V_139 -> V_162 . V_33 = 2 ;
V_139 -> V_162 . V_31 = 0 ;
break;
case V_81 :
V_152 = F_125 () ;
V_153 = ( V_152 >> 19 ) & 7 ;
if ( V_153 )
V_139 -> V_28 . V_159 = 2 << V_153 ;
else
V_139 -> V_28 . V_159 = 0 ;
V_139 -> V_28 . V_186 = 64 << ( ( V_152 >> 22 ) & 7 ) ;
V_139 -> V_28 . V_33 = 1 + ( ( V_152 >> 16 ) & 7 ) ;
V_123 = V_139 -> V_28 . V_186 *
V_139 -> V_28 . V_33 *
V_139 -> V_28 . V_159 ;
V_139 -> V_28 . V_31 = 0 ;
V_153 = ( V_152 >> 10 ) & 7 ;
if ( V_153 )
V_139 -> V_162 . V_159 = 2 << V_153 ;
else
V_139 -> V_162 . V_159 = 0 ;
V_139 -> V_162 . V_186 = 64 << ( ( V_152 >> 13 ) & 7 ) ;
V_139 -> V_162 . V_33 = 1 + ( ( V_152 >> 7 ) & 7 ) ;
V_122 = V_139 -> V_162 . V_186 *
V_139 -> V_162 . V_33 *
V_139 -> V_162 . V_159 ;
V_139 -> V_162 . V_31 = 0 ;
if ( ( V_150 & V_144 ) >= V_187 )
V_139 -> V_164 |= V_168 ;
break;
case V_188 :
V_139 -> V_28 . V_159 = 128 ;
V_139 -> V_28 . V_186 = 16 ;
V_139 -> V_28 . V_33 = 8 ;
V_139 -> V_28 . V_23 |= V_189 ;
V_123 = V_139 -> V_28 . V_186 * V_139 -> V_28 . V_33 * V_139 -> V_28 . V_159 ;
V_139 -> V_162 . V_159 = 128 ;
V_139 -> V_162 . V_33 = 8 ;
V_139 -> V_162 . V_186 = 8 ;
V_122 = V_139 -> V_162 . V_186 * V_139 -> V_162 . V_33 * V_139 -> V_162 . V_159 ;
V_139 -> V_164 |= V_168 ;
break;
default:
if ( ! ( V_149 & V_190 ) )
F_126 ( L_1 ) ;
V_152 = F_125 () ;
V_153 = ( V_152 >> 19 ) & 7 ;
if ( V_153 == 7 )
F_126 ( L_2 ) ;
V_139 -> V_28 . V_159 = V_153 ? 2 << V_153 : 0 ;
V_139 -> V_28 . V_186 = 32 << ( ( ( V_152 >> 22 ) + 1 ) & 7 ) ;
V_139 -> V_28 . V_33 = 1 + ( ( V_152 >> 16 ) & 7 ) ;
V_123 = V_139 -> V_28 . V_186 *
V_139 -> V_28 . V_33 *
V_139 -> V_28 . V_159 ;
V_139 -> V_28 . V_31 = F_123 ( V_123 / V_139 -> V_28 . V_33 ) ;
if ( V_149 & V_191 )
V_139 -> V_28 . V_23 |= V_189 ;
V_139 -> V_162 . V_23 = 0 ;
V_153 = ( V_152 >> 10 ) & 7 ;
if ( V_153 == 7 )
F_126 ( L_3 ) ;
V_139 -> V_162 . V_159 = V_153 ? 2 << V_153 : 0 ;
V_139 -> V_162 . V_186 = 32 << ( ( ( V_152 >> 13 ) + 1 ) & 7 ) ;
V_139 -> V_162 . V_33 = 1 + ( ( V_152 >> 7 ) & 7 ) ;
V_122 = V_139 -> V_162 . V_186 *
V_139 -> V_162 . V_33 *
V_139 -> V_162 . V_159 ;
V_139 -> V_162 . V_31 = F_123 ( V_122 / V_139 -> V_162 . V_33 ) ;
V_139 -> V_164 |= V_168 ;
break;
}
if ( ( V_150 & V_142 ) == V_192 &&
( V_150 & V_144 ) < V_193 &&
! ( V_149 & V_194 ) && V_139 -> V_28 . V_159 != 16 &&
V_40 <= 0x8000 )
F_126 ( L_4 ) ;
V_139 -> V_28 . V_29 = V_123 / V_139 -> V_28 . V_33 ;
V_139 -> V_162 . V_29 = V_122 / V_139 -> V_162 . V_33 ;
V_139 -> V_28 . V_186 = V_139 -> V_28 . V_159 ?
V_123 / ( V_139 -> V_28 . V_159 * V_139 -> V_28 . V_33 ) : 0 ;
V_139 -> V_162 . V_186 = V_139 -> V_162 . V_159 ?
V_122 / ( V_139 -> V_162 . V_159 * V_139 -> V_162 . V_33 ) : 0 ;
switch ( F_34 () ) {
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
V_139 -> V_162 . V_23 |= V_200 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
break;
case V_201 :
case V_202 :
V_151 = F_114 ( V_139 ) ;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
if ( ! ( F_127 () & V_216 ) &&
( V_139 -> V_28 . V_29 > V_40 ) )
V_139 -> V_28 . V_23 |= V_217 ;
if ( ! V_151 && ( F_127 () & V_218 ) ) {
V_139 -> V_162 . V_23 |= V_200 ;
break;
}
default:
if ( V_151 || V_139 -> V_162 . V_29 > V_40 )
V_139 -> V_162 . V_23 |= V_217 ;
}
switch ( F_34 () ) {
case V_195 :
V_139 -> V_28 . V_23 |= V_189 ;
break;
case V_219 :
case V_213 :
V_139 -> V_28 . V_23 |= V_220 ;
break;
case V_90 :
V_139 -> V_28 . V_23 |= V_220 ;
V_139 -> V_162 . V_23 &= ~ V_217 ;
break;
case V_44 :
V_139 -> V_28 . V_33 = 1 ;
}
F_128 ( L_5 ,
V_123 >> 10 ,
V_139 -> V_28 . V_23 & V_189 ? L_6 : L_7 ,
V_221 [ V_139 -> V_28 . V_33 ] , V_139 -> V_28 . V_159 ) ;
F_128 ( L_8 ,
V_122 >> 10 , V_221 [ V_139 -> V_162 . V_33 ] ,
( V_139 -> V_162 . V_23 & V_200 ) ? L_9 : L_7 ,
( V_139 -> V_162 . V_23 & V_217 ) ?
L_10 : L_11 ,
V_139 -> V_162 . V_159 ) ;
}
static void F_129 ( void )
{
struct V_138 * V_139 = & V_27 ;
unsigned int V_222 , V_153 ;
if ( F_34 () != V_81 )
return;
V_222 = F_130 () ;
if ( ( V_153 = ( ( V_222 >> 20 ) & 15 ) ) )
V_139 -> V_223 . V_159 = 2 << V_153 ;
else
V_139 -> V_223 . V_159 = V_153 ;
V_139 -> V_223 . V_186 = 64 << ( ( V_222 >> 24 ) & 15 ) ;
V_139 -> V_223 . V_33 = 1 + ( ( V_222 >> 16 ) & 15 ) ;
V_224 = V_139 -> V_223 . V_186 * V_139 -> V_223 . V_33 * V_139 -> V_223 . V_159 ;
V_139 -> V_223 . V_31 = 0 ;
F_131 ( L_12 ,
V_224 >> 10 , V_221 [ V_139 -> V_223 . V_33 ] , V_139 -> V_223 . V_159 ) ;
}
static int F_132 ( void )
{
unsigned long V_23 , V_4 , V_225 , V_26 , V_226 ;
unsigned int V_149 = F_121 () ;
struct V_138 * V_139 = & V_27 ;
if ( V_149 & V_194 )
return 0 ;
V_225 = ( unsigned long ) & V_227 ;
V_225 &= ~ ( ( 4 * 1024 * 1024 ) - 1 ) ;
V_26 = V_225 + ( 4 * 1024 * 1024 ) ;
F_24 ( V_23 ) ;
V_226 = ( 64 * 1024 ) ;
for ( V_4 = V_225 ; V_4 < V_26 ; V_4 = ( V_225 + V_226 ) ) {
unsigned long * V_228 = ( unsigned long * ) V_4 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_226 <<= 1 ;
}
F_112 ( 0 ) ;
F_113 ( 0 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
F_133 ( V_229 , V_225 ) ;
F_133 ( V_230 , V_225 ) ;
F_133 ( V_231 , V_225 ) ;
V_226 = ( 128 * 1024 ) ;
for ( V_4 = V_225 + ( 128 * 1024 ) ; V_4 < V_26 ; V_4 = V_225 + V_226 ) {
F_133 ( V_232 , V_4 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
if ( ! F_134 () )
break;
V_226 <<= 1 ;
}
F_26 ( V_23 ) ;
V_4 -= V_225 ;
V_65 = V_4 ;
V_139 -> V_233 . V_159 = 16 << ( ( V_149 & V_234 ) >> 22 ) ;
V_139 -> V_233 . V_33 = 1 ;
V_139 -> V_233 . V_31 = 0 ;
return 1 ;
}
static void T_6 F_135 ( void )
{
struct V_138 * V_139 = & V_27 ;
V_65 = 512 * 1024 ;
V_139 -> V_233 . V_159 = 32 ;
V_139 -> V_233 . V_33 = 4 ;
V_139 -> V_233 . V_31 = 0 ;
V_139 -> V_233 . V_29 = V_65 / ( V_139 -> V_233 . V_33 ) ;
V_139 -> V_233 . V_186 = V_65 / ( V_139 -> V_233 . V_159 * V_139 -> V_233 . V_33 ) ;
F_131 ( L_13 ,
V_65 >> 10 , V_221 [ V_139 -> V_233 . V_33 ] , V_139 -> V_233 . V_159 ) ;
V_139 -> V_164 |= V_235 ;
}
static void T_6 F_136 ( void )
{
struct V_138 * V_139 = & V_27 ;
unsigned int V_222 , V_153 ;
V_222 = F_130 () ;
V_153 = ( V_222 >> 4 ) & 15 ;
if ( V_153 )
V_139 -> V_233 . V_159 = 2 << V_153 ;
else
V_139 -> V_233 . V_159 = 0 ;
V_139 -> V_233 . V_186 = 64 << ( ( V_222 >> 8 ) & 15 ) ;
V_139 -> V_233 . V_33 = 1 + ( V_222 & 15 ) ;
V_65 = V_139 -> V_233 . V_186 *
V_139 -> V_233 . V_33 *
V_139 -> V_233 . V_159 ;
V_65 *= 4 ;
V_139 -> V_233 . V_31 = 0 ;
F_131 ( L_13 ,
V_65 >> 10 , V_221 [ V_139 -> V_233 . V_33 ] , V_139 -> V_233 . V_159 ) ;
if ( V_65 )
V_139 -> V_164 |= V_235 ;
return;
}
static void F_137 ( void )
{
struct V_138 * V_139 = & V_27 ;
unsigned int V_149 = F_121 () ;
int V_236 = 0 ;
switch ( F_34 () ) {
case V_82 :
case V_83 :
case V_84 :
case V_85 :
V_236 = F_138 ( F_132 ) ;
if ( V_236 )
V_139 -> V_164 |= V_237 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_65 = 0x80000 << ( ( V_149 & V_238 ) >> 16 ) ;
V_139 -> V_233 . V_159 = 64 << ( ( V_149 >> 13 ) & 1 ) ;
V_139 -> V_233 . V_33 = 2 ;
V_139 -> V_233 . V_31 = 0 ;
V_236 = 1 ;
break;
case V_156 :
case V_157 :
#ifdef F_139
F_140 () ;
#endif
return;
case V_185 :
#ifdef F_141
F_142 () ;
#endif
return;
case V_44 :
F_135 () ;
return;
case V_81 :
F_136 () ;
return;
case V_188 :
case V_239 :
return;
default:
if ( V_139 -> V_240 & ( V_241 | V_242 |
V_243 | V_244 |
V_245 | V_246 ) ) {
#ifdef F_143
if ( F_144 () ) {
V_65 = V_139 -> V_233 . V_33 * V_139 -> V_233 . V_186 * V_139 -> V_233 . V_159 ;
F_128 ( L_14 ,
V_65 >> 10 ,
V_221 [ V_139 -> V_233 . V_33 ] , V_139 -> V_233 . V_159 ) ;
}
#else
if ( ! ( V_139 -> V_233 . V_23 & V_247 ) )
F_126 ( L_15 ) ;
#endif
return;
}
V_236 = 0 ;
}
if ( ! V_236 )
return;
V_139 -> V_233 . V_29 = V_65 / V_139 -> V_233 . V_33 ;
V_139 -> V_233 . V_186 = V_65 / ( V_139 -> V_233 . V_159 * V_139 -> V_233 . V_33 ) ;
F_128 ( L_13 ,
V_65 >> 10 , V_221 [ V_139 -> V_233 . V_33 ] , V_139 -> V_233 . V_159 ) ;
V_139 -> V_164 |= V_235 ;
}
void F_145 ( void )
{
switch ( F_122 () ) {
case 0x00030100 :
case 0x00030201 :
case 0x00030202 :
case 0x01030200 :
case 0x02030200 :
case 0x02030201 :
case 0x02030202 :
F_146 ( 1 << 19 ) ;
break;
}
}
static void F_147 ( void )
{
unsigned long V_248 ;
V_248 = F_121 () ;
V_248 &= ~ ( 0x7 | ( 7 << 25 ) | ( 7 << 28 ) ) ;
V_248 |= ( ( ( V_249 >> V_250 ) << 0 ) |
( ( V_249 >> V_250 ) << 25 ) |
( ( V_249 >> V_250 ) << 28 ) ) ;
F_124 ( V_248 ) ;
F_148 () ;
}
static int T_6 F_149 ( char * V_251 )
{
F_150 ( & V_251 , & V_252 ) ;
return 0 ;
}
static void F_151 ( void )
{
if ( V_252 < 0 || V_252 > 7 )
V_252 = F_121 () & V_253 ;
V_249 = V_252 << V_250 ;
F_152 ( L_16 , V_252 ) ;
F_153 ( V_253 , V_252 ) ;
switch ( F_34 () ) {
case V_170 :
case V_82 :
case V_83 :
case V_171 :
case V_84 :
case V_85 :
F_154 ( V_254 ) ;
break;
case V_219 :
F_145 () ;
break;
case V_255 :
F_147 () ;
break;
}
}
static void F_155 ( void )
{
extern char __weak V_256 ;
extern char __weak V_257 ;
switch ( F_34 () ) {
case V_197 :
case V_198 :
F_156 ( 0x100 , & V_257 , 0x80 ) ;
break;
default:
F_156 ( 0x100 , & V_256 , 0x80 ) ;
break;
}
}
void F_157 ( void )
{
extern void V_258 ( void ) ;
extern void V_259 ( void ) ;
struct V_138 * V_139 = & V_27 ;
F_120 () ;
F_129 () ;
F_137 () ;
F_18 () ;
F_21 () ;
F_22 () ;
F_32 () ;
F_36 () ;
F_38 () ;
F_39 () ;
F_41 () ;
F_42 () ;
#ifdef F_79
F_20 () ;
F_35 () ;
#endif
if ( V_139 -> V_162 . V_159 && V_104 )
V_260 = F_158 ( unsigned long,
c->dcache.sets * c->dcache.linesz - 1 ,
PAGE_SIZE - 1 ) ;
else
V_260 = V_40 - 1 ;
V_261 = F_49 ;
V_262 = F_50 ;
V_263 = F_11 ;
V_264 = F_45 ;
V_265 = F_54 ;
V_266 = F_70 ;
V_267 = F_52 ;
V_268 = F_110 ;
V_269 = F_102 ;
V_270 = F_107 ;
V_271 = F_71 ;
V_272 = F_72 ;
V_273 = F_83 ;
V_274 = F_81 ;
#if F_159 ( V_275 ) || F_159 ( V_276 )
if ( V_277 ) {
V_278 = ( void * ) F_11 ;
V_279 = ( void * ) F_11 ;
V_280 = ( void * ) F_11 ;
} else {
V_278 = F_85 ;
V_279 = F_85 ;
V_280 = F_89 ;
}
#endif
V_258 () ;
V_259 () ;
F_43 ( NULL ) ;
F_151 () ;
V_281 = F_155 ;
switch ( F_34 () ) {
case V_282 :
case V_283 :
V_272 = V_7 ;
break;
case V_90 :
if ( V_139 -> V_233 . V_23 & V_247 )
break;
V_266 = ( void * ) F_119 ;
V_267 = ( void * ) F_119 ;
V_269 = ( void * ) F_119 ;
V_271 = ( void * ) F_119 ;
V_272 = ( void * ) F_119 ;
V_273 = ( void * ) F_119 ;
V_274 = ( void * ) F_119 ;
V_27 . V_164 |= V_235 ;
break;
case V_81 :
V_264 = F_11 ;
V_261 = F_11 ;
V_262 = F_11 ;
V_268 = ( void * ) F_11 ;
V_265 = ( void * ) F_11 ;
V_266 = ( void * ) F_11 ;
V_267 = ( void * ) F_11 ;
V_269 = ( void * ) F_11 ;
V_270 = ( void * ) F_11 ;
V_272 = ( void * ) F_11 ;
V_271 = ( void * ) F_11 ;
break;
}
}
static int F_160 ( struct V_284 * V_285 , unsigned long V_286 ,
void * V_287 )
{
switch ( V_286 ) {
case V_288 :
case V_289 :
F_151 () ;
break;
}
return V_290 ;
}
int T_6 F_161 ( void )
{
return F_162 ( & V_291 ) ;
}
