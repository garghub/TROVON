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
unsigned int type ,
bool V_122 )
{
if ( ! V_105 ) {
if ( type == V_91 ||
( type & V_91 && V_26 - V_24 >= V_123 ) ) {
V_18 () ;
} else {
V_5 ;
if ( V_122 )
F_75 ( V_24 , V_26 ) ;
else
F_76 ( V_24 , V_26 ) ;
}
}
if ( type == V_91 ||
( type & V_91 && V_26 - V_24 > V_124 ) )
V_59 () ;
else {
switch ( F_77 () ) {
case V_44 :
F_78 ( V_24 , V_26 ) ;
break;
default:
if ( V_122 )
F_79 ( V_24 , V_26 ) ;
else
F_80 ( V_24 , V_26 ) ;
break;
}
}
}
static inline void F_81 ( unsigned long V_24 ,
unsigned long V_26 )
{
F_74 ( V_24 , V_26 , V_1 | V_91 , false ) ;
}
static inline void F_82 ( unsigned long V_24 ,
unsigned long V_26 )
{
F_74 ( V_24 , V_26 , V_1 | V_91 , true ) ;
}
static inline void F_83 ( void * args )
{
struct V_125 * V_126 = args ;
unsigned long V_24 = V_126 -> V_24 ;
unsigned long V_26 = V_126 -> V_26 ;
unsigned int type = V_126 -> type ;
bool V_122 = V_126 -> V_122 ;
F_74 ( V_24 , V_26 , type , V_122 ) ;
}
static void F_84 ( unsigned long V_24 , unsigned long V_26 ,
bool V_122 )
{
struct V_125 args ;
unsigned long V_127 , V_128 ;
args . V_24 = V_24 ;
args . V_26 = V_26 ;
args . type = V_1 | V_91 ;
args . V_122 = V_122 ;
F_7 () ;
if ( F_1 ( V_91 ) && ! F_1 ( V_1 ) ) {
V_127 = V_26 - V_24 ;
V_128 = V_124 ;
if ( ! V_105 ) {
V_127 *= 2 ;
V_128 += V_123 ;
}
if ( V_127 <= V_128 )
args . type &= ~ V_91 ;
}
F_5 ( args . type , F_83 , & args ) ;
F_10 () ;
F_85 () ;
}
static void F_86 ( unsigned long V_24 , unsigned long V_26 )
{
return F_84 ( V_24 , V_26 , false ) ;
}
static void F_87 ( unsigned long V_24 , unsigned long V_26 )
{
return F_84 ( V_24 , V_26 , true ) ;
}
static void F_88 ( unsigned long V_4 , unsigned long V_127 )
{
F_89 ( V_127 == 0 ) ;
F_7 () ;
if ( V_129 ) {
if ( V_127 >= V_65 )
V_76 () ;
else
F_90 ( V_4 , V_4 + V_127 ) ;
F_10 () ;
F_44 () ;
return;
}
if ( V_127 >= V_123 ) {
V_18 () ;
} else {
V_5 ;
F_76 ( V_4 , V_4 + V_127 ) ;
}
F_10 () ;
F_91 ( V_4 , V_127 ) ;
F_44 () ;
}
static void F_92 ( unsigned long V_4 , unsigned long V_127 )
{
F_89 ( V_127 == 0 ) ;
F_7 () ;
if ( V_129 ) {
if ( V_127 >= V_65 )
V_76 () ;
else {
F_93 ( V_4 , V_4 + V_127 ) ;
}
F_10 () ;
F_44 () ;
return;
}
if ( V_127 >= V_123 ) {
V_18 () ;
} else {
V_5 ;
F_94 ( V_4 , V_4 + V_127 ) ;
}
F_10 () ;
F_95 ( V_4 , V_127 ) ;
F_44 () ;
}
static void F_96 ( void * args )
{
struct V_130 * V_131 = args ;
unsigned long V_4 = V_131 -> V_4 ;
struct V_38 * V_38 = V_131 -> V_38 ;
struct V_92 * V_93 = V_131 -> V_93 ;
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
V_114 ? F_97 ( V_4 & ~ ( V_6 - 1 ) )
: F_98 (
V_4 & ~ ( V_6 - 1 ) ) ;
if ( ! V_119 && V_65 )
V_114 ? F_99 ( V_4 & ~ ( V_64 - 1 ) )
: F_100 (
V_4 & ~ ( V_64 - 1 ) ) ;
}
if ( V_41 )
V_114 ? F_101 ( V_4 & ~ ( V_41 - 1 ) )
: F_102 ( V_4 & ~ ( V_41 - 1 ) ) ;
if ( V_114 ) {
if ( V_109 )
F_68 () ;
else
F_69 ( V_114 ) ;
}
if ( V_132 ) {
__asm__ __volatile__ (
".set push\n\t"
".set noat\n\t"
".set "MIPS_ISA_LEVEL"\n\t"
#ifdef F_103
"la $at,1f\n\t"
#endif
#ifdef F_104
"dla $at,1f\n\t"
#endif
"cache %0,($at)\n\t"
"nop; nop; nop\n"
"1:\n\t"
".set pop"
:
: "i" (Hit_Invalidate_I));
}
if ( V_133 )
__asm__ __volatile__ ("sync");
}
static void F_105 ( unsigned long V_4 )
{
struct V_130 args ;
int V_134 ;
F_106 ( & V_116 -> V_93 -> V_135 ) ;
V_134 = F_107 ( V_4 , 1 , 0 , & args . V_38 ) ;
if ( V_134 < 1 )
goto V_136;
args . V_93 = V_116 -> V_93 ;
args . V_4 = V_4 ;
F_5 ( V_1 , F_96 , & args ) ;
F_108 ( args . V_38 ) ;
V_136:
F_109 ( & V_116 -> V_93 -> V_135 ) ;
}
static void F_110 ( void )
{
if ( V_120 )
V_59 () ;
}
static inline void F_111 ( void * args )
{
V_18 () ;
}
static inline void F_112 ( void * args )
{
struct V_137 * V_138 = args ;
unsigned long V_114 = V_138 -> V_114 ;
int V_127 = V_138 -> V_127 ;
V_5 ;
F_76 ( V_114 , V_114 + V_127 ) ;
}
static void F_113 ( unsigned long V_114 , int V_127 )
{
struct V_137 args ;
args . V_114 = ( unsigned long ) V_114 ;
args . V_127 = V_127 ;
if ( V_127 >= V_123 )
F_5 ( V_91 ,
F_111 , NULL ) ;
else
F_5 ( V_1 , F_112 ,
& args ) ;
}
static inline void F_114 ( void )
{
const unsigned long V_41 = 32 ;
unsigned long V_4 ;
F_115 ( 0 ) ;
F_116 ( 0 ) ;
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
static inline int F_117 ( struct V_139 * V_140 )
{
unsigned int V_141 = V_140 -> V_142 & V_143 ;
unsigned int V_144 = V_140 -> V_142 & V_145 ;
int V_146 = 0 ;
switch ( V_141 ) {
case V_147 :
if ( V_144 <= F_118 ( 2 , 4 , 0 ) )
V_146 = 1 ;
if ( V_144 == F_118 ( 2 , 4 , 0 ) )
F_119 ( F_120 () | V_148 ) ;
break;
case V_149 :
if ( V_144 <= F_118 ( 1 , 1 , 0 ) ) {
V_146 = 1 ;
F_119 ( F_120 () | V_148 ) ;
}
break;
default:
F_121 () ;
}
return V_146 ;
}
static void F_122 ( void )
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
static void F_123 ( void )
{
struct V_139 * V_140 = & V_27 ;
unsigned int V_150 = F_124 () ;
unsigned int V_151 = F_125 () ;
int V_152 = 0 ;
unsigned long V_153 ;
unsigned int V_154 ;
switch ( F_34 () ) {
case V_155 :
case V_156 :
case V_157 :
case V_158 :
V_124 = 1 << ( 12 + ( ( V_150 & V_159 ) >> 9 ) ) ;
V_140 -> V_28 . V_160 = 16 << ( ( V_150 & V_161 ) >> 5 ) ;
V_140 -> V_28 . V_33 = 2 ;
V_140 -> V_28 . V_31 = F_126 ( V_124 / 2 ) ;
V_123 = 1 << ( 12 + ( ( V_150 & V_162 ) >> 6 ) ) ;
V_140 -> V_163 . V_160 = 16 << ( ( V_150 & V_164 ) >> 4 ) ;
V_140 -> V_163 . V_33 = 2 ;
V_140 -> V_163 . V_31 = F_126 ( V_123 / 2 ) ;
V_140 -> V_165 |= V_166 ;
break;
case V_167 :
case V_168 :
V_124 = 1 << ( 12 + ( ( V_150 & V_159 ) >> 9 ) ) ;
V_140 -> V_28 . V_160 = 16 << ( ( V_150 & V_161 ) >> 5 ) ;
V_140 -> V_28 . V_33 = 2 ;
V_140 -> V_28 . V_31 = 0 ;
V_123 = 1 << ( 12 + ( ( V_150 & V_162 ) >> 6 ) ) ;
V_140 -> V_163 . V_160 = 16 << ( ( V_150 & V_164 ) >> 4 ) ;
V_140 -> V_163 . V_33 = 2 ;
V_140 -> V_163 . V_31 = 0 ;
V_140 -> V_165 |= V_166 | V_169 ;
break;
case V_170 :
V_124 = 1 << ( 12 + ( ( V_150 & V_159 ) >> 9 ) ) ;
V_140 -> V_28 . V_160 = 16 << ( ( V_150 & V_161 ) >> 5 ) ;
V_140 -> V_28 . V_33 = 4 ;
V_140 -> V_28 . V_31 = 0 ;
V_123 = 1 << ( 12 + ( ( V_150 & V_162 ) >> 6 ) ) ;
V_140 -> V_163 . V_160 = 16 << ( ( V_150 & V_164 ) >> 4 ) ;
V_140 -> V_163 . V_33 = 4 ;
V_140 -> V_163 . V_31 = 0 ;
V_140 -> V_165 |= V_166 ;
V_140 -> V_165 |= V_169 ;
break;
case V_171 :
case V_82 :
case V_83 :
case V_172 :
case V_84 :
case V_85 :
case V_173 :
V_124 = 1 << ( 12 + ( ( V_150 & V_159 ) >> 9 ) ) ;
V_140 -> V_28 . V_160 = 16 << ( ( V_150 & V_161 ) >> 5 ) ;
V_140 -> V_28 . V_33 = 1 ;
V_140 -> V_28 . V_31 = 0 ;
V_123 = 1 << ( 12 + ( ( V_150 & V_162 ) >> 6 ) ) ;
V_140 -> V_163 . V_160 = 16 << ( ( V_150 & V_164 ) >> 4 ) ;
V_140 -> V_163 . V_33 = 1 ;
V_140 -> V_163 . V_31 = 0 ;
V_140 -> V_165 |= V_166 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_124 = 1 << ( 12 + ( ( V_150 & V_174 ) >> 29 ) ) ;
V_140 -> V_28 . V_160 = 64 ;
V_140 -> V_28 . V_33 = 2 ;
V_140 -> V_28 . V_31 = 0 ;
V_123 = 1 << ( 12 + ( ( V_150 & V_175 ) >> 26 ) ) ;
V_140 -> V_163 . V_160 = 32 ;
V_140 -> V_163 . V_33 = 2 ;
V_140 -> V_163 . V_31 = 0 ;
V_140 -> V_165 |= V_169 ;
break;
case V_176 :
F_127 ( V_150 & ~ V_177 ) ;
case V_178 :
if ( V_140 -> V_142 == 0x0c80U || V_140 -> V_142 == 0x0c81U ||
V_140 -> V_142 == 0x0c82U ) {
V_150 |= 0x00400000U ;
if ( V_140 -> V_142 == 0x0c80U )
V_150 |= V_179 ;
F_127 ( V_150 ) ;
} else
V_140 -> V_165 |= V_166 ;
V_124 = 1 << ( 10 + ( ( V_150 & V_159 ) >> 9 ) ) ;
V_140 -> V_28 . V_160 = 16 << ( ( V_150 & V_161 ) >> 5 ) ;
V_140 -> V_28 . V_33 = 2 ;
V_140 -> V_28 . V_31 = F_126 ( V_124 / 2 ) ;
V_123 = 1 << ( 10 + ( ( V_150 & V_162 ) >> 6 ) ) ;
V_140 -> V_163 . V_160 = 16 << ( ( V_150 & V_164 ) >> 4 ) ;
V_140 -> V_163 . V_33 = 2 ;
V_140 -> V_163 . V_31 = F_126 ( V_123 / 2 ) ;
break;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
V_124 = 1 << ( 10 + ( ( V_150 & V_159 ) >> 9 ) ) ;
V_140 -> V_28 . V_160 = 16 << ( ( V_150 & V_161 ) >> 5 ) ;
V_140 -> V_28 . V_33 = 1 ;
V_140 -> V_28 . V_31 = 0 ;
V_123 = 1 << ( 10 + ( ( V_150 & V_162 ) >> 6 ) ) ;
V_140 -> V_163 . V_160 = 16 << ( ( V_150 & V_164 ) >> 4 ) ;
V_140 -> V_163 . V_33 = 1 ;
V_140 -> V_163 . V_31 = 0 ;
V_140 -> V_165 |= V_166 ;
break;
case V_186 :
F_114 () ;
V_124 = 1 << ( 12 + ( ( V_150 & V_159 ) >> 9 ) ) ;
V_140 -> V_28 . V_160 = 16 << ( ( V_150 & V_161 ) >> 5 ) ;
V_140 -> V_28 . V_33 = 4 ;
V_140 -> V_28 . V_31 = F_126 ( V_124 / V_140 -> V_28 . V_33 ) ;
V_123 = 1 << ( 12 + ( ( V_150 & V_162 ) >> 6 ) ) ;
V_140 -> V_163 . V_160 = 16 << ( ( V_150 & V_164 ) >> 4 ) ;
V_140 -> V_163 . V_33 = 4 ;
V_140 -> V_163 . V_31 = F_126 ( V_123 / V_140 -> V_163 . V_33 ) ;
V_140 -> V_165 |= V_166 ;
V_140 -> V_165 |= V_169 ;
break;
case V_44 :
V_124 = 1 << ( 12 + ( ( V_150 & V_159 ) >> 9 ) ) ;
V_140 -> V_28 . V_160 = 16 << ( ( V_150 & V_161 ) >> 5 ) ;
if ( V_151 & 0x3 )
V_140 -> V_28 . V_33 = 4 ;
else
V_140 -> V_28 . V_33 = 2 ;
V_140 -> V_28 . V_31 = 0 ;
V_123 = 1 << ( 12 + ( ( V_150 & V_162 ) >> 6 ) ) ;
V_140 -> V_163 . V_160 = 16 << ( ( V_150 & V_164 ) >> 4 ) ;
if ( V_151 & 0x3 )
V_140 -> V_163 . V_33 = 4 ;
else
V_140 -> V_163 . V_33 = 2 ;
V_140 -> V_163 . V_31 = 0 ;
break;
case V_81 :
V_153 = F_128 () ;
V_154 = ( V_153 >> 19 ) & 7 ;
if ( V_154 )
V_140 -> V_28 . V_160 = 2 << V_154 ;
else
V_140 -> V_28 . V_160 = 0 ;
V_140 -> V_28 . V_187 = 64 << ( ( V_153 >> 22 ) & 7 ) ;
V_140 -> V_28 . V_33 = 1 + ( ( V_153 >> 16 ) & 7 ) ;
V_124 = V_140 -> V_28 . V_187 *
V_140 -> V_28 . V_33 *
V_140 -> V_28 . V_160 ;
V_140 -> V_28 . V_31 = 0 ;
V_154 = ( V_153 >> 10 ) & 7 ;
if ( V_154 )
V_140 -> V_163 . V_160 = 2 << V_154 ;
else
V_140 -> V_163 . V_160 = 0 ;
V_140 -> V_163 . V_187 = 64 << ( ( V_153 >> 13 ) & 7 ) ;
V_140 -> V_163 . V_33 = 1 + ( ( V_153 >> 7 ) & 7 ) ;
V_123 = V_140 -> V_163 . V_187 *
V_140 -> V_163 . V_33 *
V_140 -> V_163 . V_160 ;
V_140 -> V_163 . V_31 = 0 ;
if ( ( V_151 & V_145 ) >= V_188 )
V_140 -> V_165 |= V_169 ;
break;
case V_189 :
V_140 -> V_28 . V_160 = 128 ;
V_140 -> V_28 . V_187 = 16 ;
V_140 -> V_28 . V_33 = 8 ;
V_140 -> V_28 . V_23 |= V_190 ;
V_124 = V_140 -> V_28 . V_187 * V_140 -> V_28 . V_33 * V_140 -> V_28 . V_160 ;
V_140 -> V_163 . V_160 = 128 ;
V_140 -> V_163 . V_33 = 8 ;
V_140 -> V_163 . V_187 = 8 ;
V_123 = V_140 -> V_163 . V_187 * V_140 -> V_163 . V_33 * V_140 -> V_163 . V_160 ;
V_140 -> V_165 |= V_169 ;
break;
default:
if ( ! ( V_150 & V_191 ) )
F_129 ( L_1 ) ;
V_153 = F_128 () ;
V_154 = ( V_153 >> 19 ) & 7 ;
if ( V_154 == 7 )
F_129 ( L_2 ) ;
V_140 -> V_28 . V_160 = V_154 ? 2 << V_154 : 0 ;
V_140 -> V_28 . V_187 = 32 << ( ( ( V_153 >> 22 ) + 1 ) & 7 ) ;
V_140 -> V_28 . V_33 = 1 + ( ( V_153 >> 16 ) & 7 ) ;
V_124 = V_140 -> V_28 . V_187 *
V_140 -> V_28 . V_33 *
V_140 -> V_28 . V_160 ;
V_140 -> V_28 . V_31 = F_126 ( V_124 / V_140 -> V_28 . V_33 ) ;
if ( V_150 & V_192 )
V_140 -> V_28 . V_23 |= V_190 ;
V_140 -> V_163 . V_23 = 0 ;
V_154 = ( V_153 >> 10 ) & 7 ;
if ( V_154 == 7 )
F_129 ( L_3 ) ;
V_140 -> V_163 . V_160 = V_154 ? 2 << V_154 : 0 ;
V_140 -> V_163 . V_187 = 32 << ( ( ( V_153 >> 13 ) + 1 ) & 7 ) ;
V_140 -> V_163 . V_33 = 1 + ( ( V_153 >> 7 ) & 7 ) ;
V_123 = V_140 -> V_163 . V_187 *
V_140 -> V_163 . V_33 *
V_140 -> V_163 . V_160 ;
V_140 -> V_163 . V_31 = F_126 ( V_123 / V_140 -> V_163 . V_33 ) ;
V_140 -> V_165 |= V_169 ;
break;
}
if ( ( V_151 & V_143 ) == V_193 &&
( V_151 & V_145 ) < V_194 &&
! ( V_150 & V_195 ) && V_140 -> V_28 . V_160 != 16 &&
V_40 <= 0x8000 )
F_129 ( L_4 ) ;
V_140 -> V_28 . V_29 = V_124 / V_140 -> V_28 . V_33 ;
V_140 -> V_163 . V_29 = V_123 / V_140 -> V_163 . V_33 ;
V_140 -> V_28 . V_187 = V_140 -> V_28 . V_160 ?
V_124 / ( V_140 -> V_28 . V_160 * V_140 -> V_28 . V_33 ) : 0 ;
V_140 -> V_163 . V_187 = V_140 -> V_163 . V_160 ?
V_123 / ( V_140 -> V_163 . V_160 * V_140 -> V_163 . V_33 ) : 0 ;
switch ( F_34 () ) {
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
V_140 -> V_163 . V_23 |= V_203 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
break;
case V_204 :
case V_205 :
V_152 = F_117 ( V_140 ) ;
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
case V_216 :
case V_217 :
if ( ! ( F_130 () & V_218 ) &&
( V_140 -> V_28 . V_29 > V_40 ) )
V_140 -> V_28 . V_23 |= V_219 ;
if ( ! V_152 && ( F_130 () & V_220 ) ) {
V_140 -> V_163 . V_23 |= V_203 ;
break;
}
default:
if ( V_152 || V_140 -> V_163 . V_29 > V_40 )
V_140 -> V_163 . V_23 |= V_219 ;
}
if ( V_140 -> V_163 . V_23 & V_203 )
V_140 -> V_163 . V_23 &= ~ V_219 ;
switch ( F_34 () ) {
case V_196 :
V_140 -> V_28 . V_23 |= V_190 ;
break;
case V_221 :
case V_198 :
case V_199 :
V_140 -> V_28 . V_23 |= V_222 ;
break;
case V_90 :
V_140 -> V_28 . V_23 |= V_222 ;
V_140 -> V_163 . V_23 &= ~ V_219 ;
break;
case V_44 :
V_140 -> V_28 . V_33 = 1 ;
}
F_131 ( L_5 ,
V_124 >> 10 ,
V_140 -> V_28 . V_23 & V_190 ? L_6 : L_7 ,
V_223 [ V_140 -> V_28 . V_33 ] , V_140 -> V_28 . V_160 ) ;
F_131 ( L_8 ,
V_123 >> 10 , V_223 [ V_140 -> V_163 . V_33 ] ,
( V_140 -> V_163 . V_23 & V_203 ) ? L_9 : L_7 ,
( V_140 -> V_163 . V_23 & V_219 ) ?
L_10 : L_11 ,
V_140 -> V_163 . V_160 ) ;
}
static void F_132 ( void )
{
struct V_139 * V_140 = & V_27 ;
unsigned int V_224 , V_154 ;
if ( F_34 () != V_81 )
return;
V_224 = F_133 () ;
if ( ( V_154 = ( ( V_224 >> 20 ) & 15 ) ) )
V_140 -> V_225 . V_160 = 2 << V_154 ;
else
V_140 -> V_225 . V_160 = V_154 ;
V_140 -> V_225 . V_187 = 64 << ( ( V_224 >> 24 ) & 15 ) ;
V_140 -> V_225 . V_33 = 1 + ( ( V_224 >> 16 ) & 15 ) ;
V_226 = V_140 -> V_225 . V_187 * V_140 -> V_225 . V_33 * V_140 -> V_225 . V_160 ;
V_140 -> V_225 . V_31 = 0 ;
V_140 -> V_225 . V_29 = V_226 / V_140 -> V_225 . V_33 ;
F_134 ( L_12 ,
V_226 >> 10 , V_223 [ V_140 -> V_225 . V_33 ] , V_140 -> V_225 . V_160 ) ;
}
static int F_135 ( void )
{
unsigned long V_23 , V_4 , V_227 , V_26 , V_228 ;
unsigned int V_150 = F_124 () ;
struct V_139 * V_140 = & V_27 ;
if ( V_150 & V_195 )
return 0 ;
V_227 = ( unsigned long ) & V_229 ;
V_227 &= ~ ( ( 4 * 1024 * 1024 ) - 1 ) ;
V_26 = V_227 + ( 4 * 1024 * 1024 ) ;
F_24 ( V_23 ) ;
V_228 = ( 64 * 1024 ) ;
for ( V_4 = V_227 ; V_4 < V_26 ; V_4 = ( V_227 + V_228 ) ) {
unsigned long * V_230 = ( unsigned long * ) V_4 ;
__asm__ __volatile__("nop" : : "r" (*p));
V_228 <<= 1 ;
}
F_115 ( 0 ) ;
F_116 ( 0 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
F_136 ( V_231 , V_227 ) ;
F_136 ( V_232 , V_227 ) ;
F_136 ( V_233 , V_227 ) ;
V_228 = ( 128 * 1024 ) ;
for ( V_4 = V_227 + ( 128 * 1024 ) ; V_4 < V_26 ; V_4 = V_227 + V_228 ) {
F_136 ( V_234 , V_4 ) ;
__asm__ __volatile__("nop; nop; nop; nop;");
if ( ! F_137 () )
break;
V_228 <<= 1 ;
}
F_26 ( V_23 ) ;
V_4 -= V_227 ;
V_65 = V_4 ;
V_140 -> V_235 . V_160 = 16 << ( ( V_150 & V_236 ) >> 22 ) ;
V_140 -> V_235 . V_33 = 1 ;
V_140 -> V_235 . V_31 = 0 ;
return 1 ;
}
static void T_6 F_138 ( void )
{
struct V_139 * V_140 = & V_27 ;
V_65 = 512 * 1024 ;
V_140 -> V_235 . V_160 = 32 ;
V_140 -> V_235 . V_33 = 4 ;
V_140 -> V_235 . V_31 = 0 ;
V_140 -> V_235 . V_29 = V_65 / ( V_140 -> V_235 . V_33 ) ;
V_140 -> V_235 . V_187 = V_65 / ( V_140 -> V_235 . V_160 * V_140 -> V_235 . V_33 ) ;
F_134 ( L_13 ,
V_65 >> 10 , V_223 [ V_140 -> V_235 . V_33 ] , V_140 -> V_235 . V_160 ) ;
V_140 -> V_165 |= V_237 ;
}
static void T_6 F_139 ( void )
{
struct V_139 * V_140 = & V_27 ;
unsigned int V_224 , V_154 ;
V_224 = F_133 () ;
V_154 = ( V_224 >> 4 ) & 15 ;
if ( V_154 )
V_140 -> V_235 . V_160 = 2 << V_154 ;
else
V_140 -> V_235 . V_160 = 0 ;
V_140 -> V_235 . V_187 = 64 << ( ( V_224 >> 8 ) & 15 ) ;
V_140 -> V_235 . V_33 = 1 + ( V_224 & 15 ) ;
V_65 = V_140 -> V_235 . V_187 *
V_140 -> V_235 . V_33 *
V_140 -> V_235 . V_160 ;
V_65 *= 4 ;
V_140 -> V_235 . V_31 = 0 ;
V_140 -> V_235 . V_29 = V_65 / V_140 -> V_235 . V_33 ;
F_134 ( L_13 ,
V_65 >> 10 , V_223 [ V_140 -> V_235 . V_33 ] , V_140 -> V_235 . V_160 ) ;
if ( V_65 )
V_140 -> V_165 |= V_237 ;
return;
}
static void F_140 ( void )
{
struct V_139 * V_140 = & V_27 ;
unsigned int V_150 = F_124 () ;
int V_238 = 0 ;
switch ( F_34 () ) {
case V_82 :
case V_83 :
case V_84 :
case V_85 :
V_238 = F_141 ( F_135 ) ;
if ( V_238 )
V_140 -> V_165 |= V_239 ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
V_65 = 0x80000 << ( ( V_150 & V_240 ) >> 16 ) ;
V_140 -> V_235 . V_160 = 64 << ( ( V_150 >> 13 ) & 1 ) ;
V_140 -> V_235 . V_33 = 2 ;
V_140 -> V_235 . V_31 = 0 ;
V_238 = 1 ;
break;
case V_157 :
case V_158 :
#ifdef F_142
F_143 () ;
#endif
return;
case V_186 :
#ifdef F_144
F_145 () ;
#endif
return;
case V_44 :
F_138 () ;
return;
case V_81 :
F_139 () ;
return;
case V_189 :
case V_241 :
return;
default:
if ( V_140 -> V_242 & ( V_243 | V_244 |
V_245 | V_246 |
V_247 | V_248 ) ) {
#ifdef F_146
if ( F_147 () ) {
V_65 = V_140 -> V_235 . V_33 * V_140 -> V_235 . V_187 * V_140 -> V_235 . V_160 ;
F_131 ( L_14 ,
V_65 >> 10 ,
V_223 [ V_140 -> V_235 . V_33 ] , V_140 -> V_235 . V_160 ) ;
}
#else
if ( ! ( V_140 -> V_235 . V_23 & V_249 ) )
F_129 ( L_15 ) ;
#endif
return;
}
V_238 = 0 ;
}
if ( ! V_238 )
return;
V_140 -> V_235 . V_29 = V_65 / V_140 -> V_235 . V_33 ;
V_140 -> V_235 . V_187 = V_65 / ( V_140 -> V_235 . V_160 * V_140 -> V_235 . V_33 ) ;
F_131 ( L_13 ,
V_65 >> 10 , V_223 [ V_140 -> V_235 . V_33 ] , V_140 -> V_235 . V_160 ) ;
V_140 -> V_165 |= V_237 ;
}
void F_148 ( void )
{
switch ( F_125 () ) {
case 0x00030100 :
case 0x00030201 :
case 0x00030202 :
case 0x01030200 :
case 0x02030200 :
case 0x02030201 :
case 0x02030202 :
F_149 ( 1 << 19 ) ;
break;
}
}
static void F_150 ( void )
{
unsigned long V_250 ;
V_250 = F_124 () ;
V_250 &= ~ ( 0x7 | ( 7 << 25 ) | ( 7 << 28 ) ) ;
V_250 |= ( ( ( V_251 >> V_252 ) << 0 ) |
( ( V_251 >> V_252 ) << 25 ) |
( ( V_251 >> V_252 ) << 28 ) ) ;
F_127 ( V_250 ) ;
F_151 () ;
}
static int T_6 F_152 ( char * V_253 )
{
F_153 ( & V_253 , & V_254 ) ;
return 0 ;
}
static void F_154 ( void )
{
if ( V_254 < 0 || V_254 > 7 )
V_254 = F_124 () & V_255 ;
V_251 = V_254 << V_252 ;
F_155 ( L_16 , V_254 ) ;
F_156 ( V_255 , V_254 ) ;
switch ( F_34 () ) {
case V_171 :
case V_82 :
case V_83 :
case V_172 :
case V_84 :
case V_85 :
F_157 ( V_256 ) ;
break;
case V_221 :
F_148 () ;
break;
case V_257 :
F_150 () ;
break;
}
}
static void F_158 ( void )
{
extern char __weak V_258 ;
extern char __weak V_259 ;
switch ( F_34 () ) {
case V_200 :
case V_201 :
F_159 ( 0x100 , & V_259 , 0x80 ) ;
break;
default:
F_159 ( 0x100 , & V_258 , 0x80 ) ;
break;
}
}
static int F_160 ( struct V_260 * V_261 , unsigned long V_262 ,
void * V_263 )
{
switch ( V_262 ) {
case V_264 :
case V_265 :
F_154 () ;
break;
}
return V_266 ;
}
int T_6 F_161 ( void )
{
return F_162 ( & V_267 ) ;
}
