static inline const char * F_1 ( int V_1 )
{
const char * V_2 = F_2 ( V_1 ) ;
return V_2 && * V_2 ? V_2 : L_1 ;
}
static int F_3 ( void * V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_3 ;
int V_7 = V_6 -> V_7 ;
#ifdef F_4
int V_8 = V_6 -> V_8 ;
unsigned long V_9 ;
T_1 V_10 , V_11 , V_12 ;
V_10 = F_5 () ;
#endif
if ( F_6 () != 0 )
return - V_13 ;
#if F_7 ( V_14 )
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
if ( V_4 != 0 || ( V_6 -> V_7 & 0xffff ) == 0xffff || V_6 -> V_7 == V_7 )
V_4 = - V_15 ;
#ifdef F_4
V_12 = F_5 () ;
V_11 = F_8 ( V_12 , V_10 ) ;
V_9 = F_9 ( V_11 ) >> 10 ;
F_10 ( L_2 , V_7 , V_8 ,
( V_4 ? 0xffff : V_6 -> V_7 & 0xffff ) , V_9 ) ;
#endif
return V_4 ;
}
static int F_11 ( struct V_5 * V_6 )
{
int V_16 ;
F_12 () ;
V_16 = F_13 ( 0 , F_3 , V_6 , true ) ;
F_14 () ;
return V_16 ;
}
static int F_15 ( int V_17 )
{
struct V_5 V_6 = { . V_7 = V_18 , } ;
V_6 . V_8 = V_17 & 0xff ;
return F_11 ( & V_6 ) ? : V_6 . V_7 & 0xff ;
}
static int F_16 ( int V_17 )
{
struct V_5 V_6 = { . V_7 = V_19 , } ;
V_6 . V_8 = V_17 & 0xff ;
return F_11 ( & V_6 ) ? : ( V_6 . V_7 & 0xffff ) * V_20 ;
}
static int F_17 ( int V_17 )
{
struct V_5 V_6 = { . V_7 = V_21 , } ;
if ( V_22 )
return - V_15 ;
V_6 . V_8 = V_17 & 0xff ;
return F_11 ( & V_6 ) ? : V_6 . V_7 & 0xff ;
}
static int F_18 ( int V_17 )
{
static int V_23 [ 3 ] = { V_24 , V_24 , V_24 } ;
if ( V_23 [ V_17 ] == V_24 )
V_23 [ V_17 ] = F_17 ( V_17 ) ;
return V_23 [ V_17 ] ;
}
static int F_19 ( int V_17 , int V_25 )
{
struct V_5 V_6 = { . V_7 = V_26 , } ;
V_6 . V_8 = ( V_17 & 0xff ) | ( V_25 << 8 ) ;
return F_11 ( & V_6 ) ? : ( V_6 . V_7 & 0xffff ) * V_20 ;
}
static int F_20 ( int V_17 , int V_25 )
{
struct V_5 V_6 = { . V_7 = V_27 , } ;
V_25 = ( V_25 < 0 ) ? 0 : ( ( V_25 > V_28 ) ? V_28 : V_25 ) ;
V_6 . V_8 = ( V_17 & 0xff ) | ( V_25 << 8 ) ;
return F_11 ( & V_6 ) ? : F_15 ( V_17 ) ;
}
static int F_21 ( int V_29 )
{
struct V_5 V_6 = { . V_7 = V_30 , } ;
V_6 . V_8 = V_29 & 0xff ;
return F_11 ( & V_6 ) ? : V_6 . V_7 & 0xff ;
}
static int F_22 ( int V_29 )
{
struct V_5 V_6 = {
. V_7 = V_31 ,
. V_8 = V_29 & 0xff ,
} ;
return F_11 ( & V_6 ) ? : V_6 . V_7 & 0xff ;
}
static int F_23 ( int V_29 )
{
int V_32 = F_22 ( V_29 ) ;
if ( V_32 == 0x99 ) {
F_24 ( 100 ) ;
V_32 = F_22 ( V_29 ) ;
}
if ( V_32 > V_33 )
return - V_34 ;
return V_32 ;
}
static int F_25 ( int V_35 )
{
struct V_5 V_6 = { . V_7 = V_35 , } ;
int V_4 ;
V_4 = F_11 ( & V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_6 . V_7 == 1145651527 && V_6 . V_36 == 1145392204 ? 0 : - 1 ;
}
static int F_26 ( void )
{
struct V_5 V_6 = { . V_7 = V_37 , } ;
int V_4 ;
V_4 = F_11 ( & V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( ( V_6 . V_7 >> V_38 ) & V_39 ) {
case V_40 :
return V_41 ;
case V_42 :
return V_43 ;
case V_44 :
return V_45 ;
default:
return 0 ;
}
}
static int F_27 ( void )
{
struct V_5 V_6 = { . V_7 = V_46 , } ;
int V_4 ;
V_4 = F_11 ( & V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
return ( V_6 . V_7 & 0xff ) == V_47 ? V_48 : V_49 ;
}
static int
F_28 ( struct V_50 * V_51 , unsigned int V_52 , unsigned long V_53 )
{
int V_54 = 0 ;
int V_25 ;
unsigned char V_55 [ 16 ] ;
int T_2 * V_56 = ( int T_2 * ) V_53 ;
if ( ! V_56 )
return - V_15 ;
switch ( V_52 ) {
case V_57 :
if ( ! isdigit ( V_58 [ 0 ] ) || ! isdigit ( V_58 [ 1 ] ) ||
! isdigit ( V_58 [ 2 ] ) )
return - V_15 ;
V_54 = ( V_58 [ 0 ] << 16 ) |
( V_58 [ 1 ] << 8 ) | V_58 [ 2 ] ;
break;
case V_59 :
if ( V_60 && ! F_29 ( V_61 ) )
return - V_62 ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
F_30 ( V_55 , V_63 , sizeof( V_55 ) ) ;
break;
case V_64 :
V_54 = F_26 () ;
break;
case V_65 :
V_54 = F_27 () ;
break;
case V_66 :
V_54 = F_23 ( 0 ) ;
break;
case V_67 :
if ( F_31 ( & V_54 , V_56 , sizeof( int ) ) )
return - V_68 ;
V_54 = F_16 ( V_54 ) ;
break;
case V_69 :
if ( F_31 ( & V_54 , V_56 , sizeof( int ) ) )
return - V_68 ;
V_54 = F_15 ( V_54 ) ;
break;
case V_70 :
if ( V_60 && ! F_29 ( V_61 ) )
return - V_62 ;
if ( F_31 ( & V_54 , V_56 , sizeof( int ) ) )
return - V_68 ;
if ( F_31 ( & V_25 , V_56 + 1 , sizeof( int ) ) )
return - V_68 ;
V_54 = F_20 ( V_54 , V_25 ) ;
break;
default:
return - V_15 ;
}
if ( V_54 < 0 )
return V_54 ;
switch ( V_52 ) {
case V_57 :
if ( F_32 ( V_56 , & V_54 , 4 ) )
return - V_68 ;
break;
case V_59 :
if ( F_32 ( V_56 , V_55 , 16 ) )
return - V_68 ;
break;
default:
if ( F_32 ( V_56 , & V_54 , sizeof( int ) ) )
return - V_68 ;
break;
}
return 0 ;
}
static long F_33 ( struct V_50 * V_51 , unsigned int V_52 , unsigned long V_53 )
{
long V_16 ;
F_34 ( & V_71 ) ;
V_16 = F_28 ( V_51 , V_52 , V_53 ) ;
F_35 ( & V_71 ) ;
return V_16 ;
}
static int F_36 ( struct V_72 * V_73 , void * V_74 )
{
int V_75 , V_76 , V_77 ;
int V_78 , V_79 , V_80 , V_81 ;
V_76 = F_23 ( 0 ) ;
V_78 = F_15 ( V_82 ) ;
V_79 = F_15 ( V_83 ) ;
V_80 = F_16 ( V_82 ) ;
V_81 = F_16 ( V_83 ) ;
V_75 = F_26 () ;
if ( V_84 )
V_77 = F_27 () ;
else
V_77 = - 1 ;
F_37 ( V_73 , L_3 ,
V_85 ,
V_58 ,
( V_60 && ! F_29 ( V_61 ) ) ? L_4 : V_63 ,
V_76 ,
V_78 , V_79 , V_80 , V_81 ,
V_77 , V_75 ) ;
return 0 ;
}
static int F_38 ( struct V_86 * V_86 , struct V_50 * V_50 )
{
return F_39 ( V_50 , F_36 , NULL ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( L_5 , 0 , NULL , & V_87 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( L_5 , NULL ) ;
}
static inline void T_3 F_40 ( void )
{
}
static inline void T_4 F_42 ( void )
{
}
static T_5 F_44 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
char * V_92 )
{
static const char * const V_93 [] = {
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_9 ,
} ;
int V_94 = F_45 ( V_91 ) -> V_94 ;
int type ;
type = F_21 ( V_94 ) ;
if ( type < 0 )
return type ;
if ( type >= F_46 ( V_93 ) )
type = F_46 ( V_93 ) - 1 ;
return sprintf ( V_92 , L_11 , V_93 [ type ] ) ;
}
static T_5 F_47 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
char * V_92 )
{
int V_94 = F_45 ( V_91 ) -> V_94 ;
int V_32 ;
V_32 = F_23 ( V_94 ) ;
if ( V_32 < 0 )
return V_32 ;
return sprintf ( V_92 , L_12 , V_32 * 1000 ) ;
}
static T_5 F_48 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
char * V_92 )
{
static const char * const V_93 [] = {
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
} ;
int V_94 = F_45 ( V_91 ) -> V_94 ;
bool V_95 = false ;
int type ;
type = F_18 ( V_94 ) ;
if ( type < 0 )
return type ;
if ( type & 0x10 ) {
V_95 = true ;
type &= 0x0F ;
}
if ( type >= F_46 ( V_93 ) )
type = ( F_46 ( V_93 ) - 1 ) ;
return sprintf ( V_92 , L_19 , ( V_95 ? L_20 : L_21 ) , V_93 [ type ] ) ;
}
static T_5 F_49 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
char * V_92 )
{
int V_94 = F_45 ( V_91 ) -> V_94 ;
int V_96 ;
V_96 = F_16 ( V_94 ) ;
if ( V_96 < 0 )
return V_96 ;
return sprintf ( V_92 , L_12 , V_96 ) ;
}
static T_5 F_50 ( struct V_88 * V_89 ,
struct V_90 * V_91 ,
char * V_92 )
{
int V_94 = F_45 ( V_91 ) -> V_94 ;
int V_97 ;
V_97 = F_15 ( V_94 ) ;
if ( V_97 < 0 )
return - V_98 ;
return sprintf ( V_92 , L_12 , F_51 ( V_97 * V_99 , 0 , 255 ) ) ;
}
static T_5 F_52 ( struct V_88 * V_89 ,
struct V_90 * V_100 ,
const char * V_92 , T_6 V_101 )
{
int V_94 = F_45 ( V_100 ) -> V_94 ;
unsigned long V_54 ;
int V_102 ;
V_102 = F_53 ( V_92 , 10 , & V_54 ) ;
if ( V_102 )
return V_102 ;
V_54 = F_51 ( F_54 ( V_54 , V_99 ) , 0 , V_28 ) ;
F_34 ( & V_71 ) ;
V_102 = F_20 ( V_94 , V_54 ) ;
F_35 ( & V_71 ) ;
return V_102 < 0 ? - V_98 : V_101 ;
}
static T_7 F_55 ( struct V_103 * V_104 , struct V_105 * V_100 ,
int V_94 )
{
if ( V_22 &&
( V_94 == 9 || V_94 == 12 || V_94 == 15 ) )
return 0 ;
if ( V_94 >= 0 && V_94 <= 1 &&
! ( V_106 & V_107 ) )
return 0 ;
if ( V_94 >= 2 && V_94 <= 3 &&
! ( V_106 & V_108 ) )
return 0 ;
if ( V_94 >= 4 && V_94 <= 5 &&
! ( V_106 & V_109 ) )
return 0 ;
if ( V_94 >= 6 && V_94 <= 7 &&
! ( V_106 & V_110 ) )
return 0 ;
if ( V_94 >= 8 && V_94 <= 10 &&
! ( V_106 & V_111 ) )
return 0 ;
if ( V_94 >= 11 && V_94 <= 13 &&
! ( V_106 & V_112 ) )
return 0 ;
if ( V_94 >= 14 && V_94 <= 16 &&
! ( V_106 & V_113 ) )
return 0 ;
return V_100 -> V_114 ;
}
static int T_3 F_56 ( void )
{
int V_102 ;
V_106 = 0 ;
V_102 = F_21 ( 0 ) ;
if ( V_102 >= 0 )
V_106 |= V_107 ;
V_102 = F_21 ( 1 ) ;
if ( V_102 >= 0 )
V_106 |= V_108 ;
V_102 = F_21 ( 2 ) ;
if ( V_102 >= 0 )
V_106 |= V_109 ;
V_102 = F_21 ( 3 ) ;
if ( V_102 >= 0 )
V_106 |= V_110 ;
V_102 = F_15 ( 0 ) ;
if ( V_102 < 0 )
V_102 = F_18 ( 0 ) ;
if ( V_102 >= 0 )
V_106 |= V_111 ;
V_102 = F_15 ( 1 ) ;
if ( V_102 < 0 )
V_102 = F_18 ( 1 ) ;
if ( V_102 >= 0 )
V_106 |= V_112 ;
V_102 = F_15 ( 2 ) ;
if ( V_102 < 0 )
V_102 = F_18 ( 2 ) ;
if ( V_102 >= 0 )
V_106 |= V_113 ;
V_115 = F_57 ( NULL , L_22 ,
NULL , V_116 ) ;
if ( F_58 ( V_115 ) ) {
V_102 = F_59 ( V_115 ) ;
V_115 = NULL ;
F_60 ( L_23 , V_102 ) ;
return V_102 ;
}
return 0 ;
}
static int T_3 F_61 ( void )
{
const struct V_117 * V_118 ;
int V_17 , V_16 ;
if ( ! F_62 ( V_119 ) ) {
if ( ! V_120 && ! V_121 )
return - V_122 ;
F_63 ( L_24 ) ;
F_63 ( L_25 ,
F_1 ( V_123 ) ,
F_1 ( V_124 ) ,
F_1 ( V_125 ) ) ;
}
if ( F_62 ( V_126 ) )
V_22 = true ;
F_30 ( V_58 , F_1 ( V_125 ) ,
sizeof( V_58 ) ) ;
F_30 ( V_63 , F_1 ( V_127 ) ,
sizeof( V_63 ) ) ;
if ( F_25 ( V_128 ) &&
F_25 ( V_129 ) ) {
F_60 ( L_26 ) ;
if ( ! V_121 )
return - V_122 ;
}
V_118 = F_64 ( V_119 ) ;
if ( V_118 && V_118 -> V_130 ) {
const struct V_131 * V_132 = V_118 -> V_130 ;
if ( ! V_133 && V_132 -> V_133 )
V_133 = V_132 -> V_133 ;
if ( ! V_134 && V_132 -> V_134 )
V_134 = V_132 -> V_134 ;
}
V_28 = V_134 ? : V_135 ;
V_99 = F_65 ( 255 , V_28 ) ;
if ( ! V_133 ) {
for ( V_17 = 0 ; V_17 < 2 ; ++ V_17 ) {
V_16 = F_19 ( V_17 , V_28 ) ;
if ( V_16 < 0 )
continue;
if ( V_16 > V_136 )
V_20 = 1 ;
break;
}
} else {
V_20 = V_133 ;
}
return 0 ;
}
static int T_3 F_66 ( void )
{
int V_102 ;
if ( F_61 () )
return - V_122 ;
V_102 = F_56 () ;
if ( V_102 )
return V_102 ;
F_40 () ;
return 0 ;
}
static void T_4 F_67 ( void )
{
F_68 ( V_115 ) ;
F_42 () ;
}
