static inline const char * F_1 ( int V_1 )
{
const char * V_2 = F_2 ( V_1 ) ;
return V_2 && * V_2 ? V_2 : L_1 ;
}
static int F_3 ( struct V_3 * V_4 )
{
int V_5 ;
int V_6 = V_4 -> V_6 ;
T_1 V_7 ;
#ifdef F_4
int V_8 = V_4 -> V_8 ;
unsigned long V_9 ;
T_2 V_10 , V_11 , V_12 ;
V_10 = F_5 () ;
#endif
if ( ! F_6 ( & V_7 , V_13 ) )
return - V_14 ;
F_7 ( V_7 , & V_15 -> V_16 ) ;
V_5 = F_8 ( V_15 , F_9 ( 0 ) ) ;
if ( V_5 )
goto V_17;
if ( F_10 () != 0 ) {
V_5 = - V_18 ;
goto V_17;
}
#if F_11 ( V_19 )
asm volatile("pushq %%rax\n\t"
"movl 0(%%rax),%%edx\n\t"
"pushq %%rdx\n\t"
"movl 4(%%rax),%%ebx\n\t"
"movl 8(%%rax),%%ecx\n\t"
"movl 12(%%rax),%%edx\n\t"
"movl 16(%%rax),%%esi\n\t"
"movl 20(%%rax),%%edi\n\t"
"popq %%rax\n\t"
"out %%al,$0xb2\n\t"
"out %%al,$0x84\n\t"
"xchgq %%rax,(%%rsp)\n\t"
"movl %%ebx,4(%%rax)\n\t"
"movl %%ecx,8(%%rax)\n\t"
"movl %%edx,12(%%rax)\n\t"
"movl %%esi,16(%%rax)\n\t"
"movl %%edi,20(%%rax)\n\t"
"popq %%rdx\n\t"
"movl %%edx,0(%%rax)\n\t"
"pushfq\n\t"
"popq %%rax\n\t"
"andl $1,%%eax\n"
: "=a"(rc)
: "a"(regs)
: "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory");
#else
asm volatile("pushl %%eax\n\t"
"movl 0(%%eax),%%edx\n\t"
"push %%edx\n\t"
"movl 4(%%eax),%%ebx\n\t"
"movl 8(%%eax),%%ecx\n\t"
"movl 12(%%eax),%%edx\n\t"
"movl 16(%%eax),%%esi\n\t"
"movl 20(%%eax),%%edi\n\t"
"popl %%eax\n\t"
"out %%al,$0xb2\n\t"
"out %%al,$0x84\n\t"
"xchgl %%eax,(%%esp)\n\t"
"movl %%ebx,4(%%eax)\n\t"
"movl %%ecx,8(%%eax)\n\t"
"movl %%edx,12(%%eax)\n\t"
"movl %%esi,16(%%eax)\n\t"
"movl %%edi,20(%%eax)\n\t"
"popl %%edx\n\t"
"movl %%edx,0(%%eax)\n\t"
"lahf\n\t"
"shrl $8,%%eax\n\t"
"andl $1,%%eax\n"
: "=a"(rc)
: "a"(regs)
: "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory");
#endif
if ( V_5 != 0 || ( V_4 -> V_6 & 0xffff ) == 0xffff || V_4 -> V_6 == V_6 )
V_5 = - V_20 ;
V_17:
F_8 ( V_15 , V_7 ) ;
F_12 ( V_7 ) ;
#ifdef F_4
V_12 = F_5 () ;
V_11 = F_13 ( V_12 , V_10 ) ;
V_9 = F_14 ( V_11 ) >> 10 ;
F_15 ( L_2 , V_6 , V_8 ,
( V_5 ? 0xffff : V_4 -> V_6 & 0xffff ) , V_9 ) ;
#endif
return V_5 ;
}
static int F_16 ( int V_21 )
{
struct V_3 V_4 = { . V_6 = V_22 , } ;
V_4 . V_8 = V_21 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_17 ( int V_21 )
{
struct V_3 V_4 = { . V_6 = V_23 , } ;
V_4 . V_8 = V_21 & 0xff ;
return F_3 ( & V_4 ) ? : ( V_4 . V_6 & 0xffff ) * V_24 ;
}
static int F_18 ( int V_21 )
{
struct V_3 V_4 = { . V_6 = V_25 , } ;
if ( V_26 )
return - V_20 ;
V_4 . V_8 = V_21 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_19 ( int V_21 )
{
static int V_27 [ 3 ] = { V_28 , V_28 , V_28 } ;
if ( V_27 [ V_21 ] == V_28 )
V_27 [ V_21 ] = F_18 ( V_21 ) ;
return V_27 [ V_21 ] ;
}
static int F_20 ( int V_21 , int V_29 )
{
struct V_3 V_4 = { . V_6 = V_30 , } ;
V_4 . V_8 = ( V_21 & 0xff ) | ( V_29 << 8 ) ;
return F_3 ( & V_4 ) ? : ( V_4 . V_6 & 0xffff ) * V_24 ;
}
static int F_21 ( int V_21 , int V_29 )
{
struct V_3 V_4 = { . V_6 = V_31 , } ;
V_29 = ( V_29 < 0 ) ? 0 : ( ( V_29 > V_32 ) ? V_32 : V_29 ) ;
V_4 . V_8 = ( V_21 & 0xff ) | ( V_29 << 8 ) ;
return F_3 ( & V_4 ) ? : F_16 ( V_21 ) ;
}
static int F_22 ( int V_33 )
{
struct V_3 V_4 = { . V_6 = V_34 , } ;
V_4 . V_8 = V_33 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_23 ( int V_33 )
{
struct V_3 V_4 = {
. V_6 = V_35 ,
. V_8 = V_33 & 0xff ,
} ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_24 ( int V_33 )
{
int V_36 = F_23 ( V_33 ) ;
if ( V_36 == 0x99 ) {
F_25 ( 100 ) ;
V_36 = F_23 ( V_33 ) ;
}
if ( V_36 > V_37 )
return - V_38 ;
return V_36 ;
}
static int F_26 ( int V_39 )
{
struct V_3 V_4 = { . V_6 = V_39 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_4 . V_6 == 1145651527 && V_4 . V_40 == 1145392204 ? 0 : - 1 ;
}
static int F_27 ( void )
{
struct V_3 V_4 = { . V_6 = V_41 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( ( V_4 . V_6 >> V_42 ) & V_43 ) {
case V_44 :
return V_45 ;
case V_46 :
return V_47 ;
case V_48 :
return V_49 ;
default:
return 0 ;
}
}
static int F_28 ( void )
{
struct V_3 V_4 = { . V_6 = V_50 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_4 . V_6 & 0xff ) == V_51 ? V_52 : V_53 ;
}
static int
F_29 ( struct V_54 * V_55 , unsigned int V_56 , unsigned long V_57 )
{
int V_58 = 0 ;
int V_29 ;
unsigned char V_59 [ 16 ] ;
int T_3 * V_60 = ( int T_3 * ) V_57 ;
if ( ! V_60 )
return - V_20 ;
switch ( V_56 ) {
case V_61 :
if ( ! isdigit ( V_62 [ 0 ] ) || ! isdigit ( V_62 [ 1 ] ) ||
! isdigit ( V_62 [ 2 ] ) )
return - V_20 ;
V_58 = ( V_62 [ 0 ] << 16 ) |
( V_62 [ 1 ] << 8 ) | V_62 [ 2 ] ;
break;
case V_63 :
if ( V_64 && ! F_30 ( V_65 ) )
return - V_66 ;
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
F_31 ( V_59 , V_67 , sizeof( V_59 ) ) ;
break;
case V_68 :
V_58 = F_27 () ;
break;
case V_69 :
V_58 = F_28 () ;
break;
case V_70 :
V_58 = F_24 ( 0 ) ;
break;
case V_71 :
if ( F_32 ( & V_58 , V_60 , sizeof( int ) ) )
return - V_72 ;
V_58 = F_17 ( V_58 ) ;
break;
case V_73 :
if ( F_32 ( & V_58 , V_60 , sizeof( int ) ) )
return - V_72 ;
V_58 = F_16 ( V_58 ) ;
break;
case V_74 :
if ( V_64 && ! F_30 ( V_65 ) )
return - V_66 ;
if ( F_32 ( & V_58 , V_60 , sizeof( int ) ) )
return - V_72 ;
if ( F_32 ( & V_29 , V_60 + 1 , sizeof( int ) ) )
return - V_72 ;
V_58 = F_21 ( V_58 , V_29 ) ;
break;
default:
return - V_20 ;
}
if ( V_58 < 0 )
return V_58 ;
switch ( V_56 ) {
case V_61 :
if ( F_33 ( V_60 , & V_58 , 4 ) )
return - V_72 ;
break;
case V_63 :
if ( F_33 ( V_60 , V_59 , 16 ) )
return - V_72 ;
break;
default:
if ( F_33 ( V_60 , & V_58 , sizeof( int ) ) )
return - V_72 ;
break;
}
return 0 ;
}
static long F_34 ( struct V_54 * V_55 , unsigned int V_56 , unsigned long V_57 )
{
long V_75 ;
F_35 ( & V_76 ) ;
V_75 = F_29 ( V_55 , V_56 , V_57 ) ;
F_36 ( & V_76 ) ;
return V_75 ;
}
static int F_37 ( struct V_77 * V_78 , void * V_79 )
{
int V_80 , V_81 , V_82 ;
int V_83 , V_84 , V_85 , V_86 ;
V_81 = F_24 ( 0 ) ;
V_83 = F_16 ( V_87 ) ;
V_84 = F_16 ( V_88 ) ;
V_85 = F_17 ( V_87 ) ;
V_86 = F_17 ( V_88 ) ;
V_80 = F_27 () ;
if ( V_89 )
V_82 = F_28 () ;
else
V_82 = - 1 ;
F_38 ( V_78 , L_3 ,
V_90 ,
V_62 ,
( V_64 && ! F_30 ( V_65 ) ) ? L_4 : V_67 ,
V_81 ,
V_83 , V_84 , V_85 , V_86 ,
V_82 , V_80 ) ;
return 0 ;
}
static int F_39 ( struct V_91 * V_91 , struct V_54 * V_54 )
{
return F_40 ( V_54 , F_37 , NULL ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( L_5 , 0 , NULL , & V_92 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( L_5 , NULL ) ;
}
static inline void T_4 F_41 ( void )
{
}
static inline void T_5 F_43 ( void )
{
}
static T_6 F_45 ( struct V_93 * V_94 ,
struct V_95 * V_96 ,
char * V_97 )
{
static const char * const V_98 [] = {
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_9 ,
} ;
int V_99 = F_46 ( V_96 ) -> V_99 ;
int type ;
type = F_22 ( V_99 ) ;
if ( type < 0 )
return type ;
if ( type >= F_47 ( V_98 ) )
type = F_47 ( V_98 ) - 1 ;
return sprintf ( V_97 , L_11 , V_98 [ type ] ) ;
}
static T_6 F_48 ( struct V_93 * V_94 ,
struct V_95 * V_96 ,
char * V_97 )
{
int V_99 = F_46 ( V_96 ) -> V_99 ;
int V_36 ;
V_36 = F_24 ( V_99 ) ;
if ( V_36 < 0 )
return V_36 ;
return sprintf ( V_97 , L_12 , V_36 * 1000 ) ;
}
static T_6 F_49 ( struct V_93 * V_94 ,
struct V_95 * V_96 ,
char * V_97 )
{
static const char * const V_98 [] = {
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
} ;
int V_99 = F_46 ( V_96 ) -> V_99 ;
bool V_100 = false ;
int type ;
type = F_19 ( V_99 ) ;
if ( type < 0 )
return type ;
if ( type & 0x10 ) {
V_100 = true ;
type &= 0x0F ;
}
if ( type >= F_47 ( V_98 ) )
type = ( F_47 ( V_98 ) - 1 ) ;
return sprintf ( V_97 , L_19 , ( V_100 ? L_20 : L_21 ) , V_98 [ type ] ) ;
}
static T_6 F_50 ( struct V_93 * V_94 ,
struct V_95 * V_96 ,
char * V_97 )
{
int V_99 = F_46 ( V_96 ) -> V_99 ;
int V_101 ;
V_101 = F_17 ( V_99 ) ;
if ( V_101 < 0 )
return V_101 ;
return sprintf ( V_97 , L_12 , V_101 ) ;
}
static T_6 F_51 ( struct V_93 * V_94 ,
struct V_95 * V_96 ,
char * V_97 )
{
int V_99 = F_46 ( V_96 ) -> V_99 ;
int V_102 ;
V_102 = F_16 ( V_99 ) ;
if ( V_102 < 0 )
return - V_103 ;
return sprintf ( V_97 , L_12 , F_52 ( V_102 * V_104 , 0 , 255 ) ) ;
}
static T_6 F_53 ( struct V_93 * V_94 ,
struct V_95 * V_105 ,
const char * V_97 , T_7 V_106 )
{
int V_99 = F_46 ( V_105 ) -> V_99 ;
unsigned long V_58 ;
int V_107 ;
V_107 = F_54 ( V_97 , 10 , & V_58 ) ;
if ( V_107 )
return V_107 ;
V_58 = F_52 ( F_55 ( V_58 , V_104 ) , 0 , V_32 ) ;
F_35 ( & V_76 ) ;
V_107 = F_21 ( V_99 , V_58 ) ;
F_36 ( & V_76 ) ;
return V_107 < 0 ? - V_103 : V_106 ;
}
static T_8 F_56 ( struct V_108 * V_109 , struct V_110 * V_105 ,
int V_99 )
{
if ( V_26 &&
( V_99 == 9 || V_99 == 12 || V_99 == 15 ) )
return 0 ;
if ( V_99 >= 0 && V_99 <= 1 &&
! ( V_111 & V_112 ) )
return 0 ;
if ( V_99 >= 2 && V_99 <= 3 &&
! ( V_111 & V_113 ) )
return 0 ;
if ( V_99 >= 4 && V_99 <= 5 &&
! ( V_111 & V_114 ) )
return 0 ;
if ( V_99 >= 6 && V_99 <= 7 &&
! ( V_111 & V_115 ) )
return 0 ;
if ( V_99 >= 8 && V_99 <= 10 &&
! ( V_111 & V_116 ) )
return 0 ;
if ( V_99 >= 11 && V_99 <= 13 &&
! ( V_111 & V_117 ) )
return 0 ;
if ( V_99 >= 14 && V_99 <= 16 &&
! ( V_111 & V_118 ) )
return 0 ;
return V_105 -> V_119 ;
}
static int T_4 F_57 ( void )
{
int V_107 ;
V_111 = 0 ;
V_107 = F_22 ( 0 ) ;
if ( V_107 >= 0 )
V_111 |= V_112 ;
V_107 = F_22 ( 1 ) ;
if ( V_107 >= 0 )
V_111 |= V_113 ;
V_107 = F_22 ( 2 ) ;
if ( V_107 >= 0 )
V_111 |= V_114 ;
V_107 = F_22 ( 3 ) ;
if ( V_107 >= 0 )
V_111 |= V_115 ;
V_107 = F_16 ( 0 ) ;
if ( V_107 < 0 )
V_107 = F_19 ( 0 ) ;
if ( V_107 >= 0 )
V_111 |= V_116 ;
V_107 = F_16 ( 1 ) ;
if ( V_107 < 0 )
V_107 = F_19 ( 1 ) ;
if ( V_107 >= 0 )
V_111 |= V_117 ;
V_107 = F_16 ( 2 ) ;
if ( V_107 < 0 )
V_107 = F_19 ( 2 ) ;
if ( V_107 >= 0 )
V_111 |= V_118 ;
V_120 = F_58 ( NULL , L_22 ,
NULL , V_121 ) ;
if ( F_59 ( V_120 ) ) {
V_107 = F_60 ( V_120 ) ;
V_120 = NULL ;
F_61 ( L_23 , V_107 ) ;
return V_107 ;
}
return 0 ;
}
static int T_4 F_62 ( void )
{
const struct V_122 * V_123 ;
int V_21 , V_75 ;
if ( ! F_63 ( V_124 ) ) {
if ( ! V_125 && ! V_126 )
return - V_127 ;
F_64 ( L_24 ) ;
F_64 ( L_25 ,
F_1 ( V_128 ) ,
F_1 ( V_129 ) ,
F_1 ( V_130 ) ) ;
}
if ( F_63 ( V_131 ) )
V_26 = true ;
F_31 ( V_62 , F_1 ( V_130 ) ,
sizeof( V_62 ) ) ;
F_31 ( V_67 , F_1 ( V_132 ) ,
sizeof( V_67 ) ) ;
if ( F_26 ( V_133 ) &&
F_26 ( V_134 ) ) {
F_61 ( L_26 ) ;
if ( ! V_126 )
return - V_127 ;
}
V_123 = F_65 ( V_124 ) ;
if ( V_123 && V_123 -> V_135 ) {
const struct V_136 * V_137 = V_123 -> V_135 ;
if ( ! V_138 && V_137 -> V_138 )
V_138 = V_137 -> V_138 ;
if ( ! V_139 && V_137 -> V_139 )
V_139 = V_137 -> V_139 ;
}
V_32 = V_139 ? : V_140 ;
V_104 = F_66 ( 255 , V_32 ) ;
if ( ! V_138 ) {
for ( V_21 = 0 ; V_21 < 2 ; ++ V_21 ) {
V_75 = F_20 ( V_21 , V_32 ) ;
if ( V_75 < 0 )
continue;
if ( V_75 > V_141 )
V_24 = 1 ;
break;
}
} else {
V_24 = V_138 ;
}
return 0 ;
}
static int T_4 F_67 ( void )
{
int V_107 ;
if ( F_62 () )
return - V_127 ;
V_107 = F_57 () ;
if ( V_107 )
return V_107 ;
F_41 () ;
return 0 ;
}
static void T_5 F_68 ( void )
{
F_69 ( V_120 ) ;
F_43 () ;
}
