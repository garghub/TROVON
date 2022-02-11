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
if ( ! F_4 ( & V_7 , V_8 ) )
return - V_9 ;
F_5 ( V_7 , & V_10 -> V_11 ) ;
V_5 = F_6 ( V_10 , F_7 ( 0 ) ) ;
if ( V_5 )
goto V_12;
if ( F_8 () != 0 ) {
V_5 = - V_13 ;
goto V_12;
}
#if F_9 ( V_14 )
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
V_5 = - V_15 ;
V_12:
F_6 ( V_10 , V_7 ) ;
F_10 ( V_7 ) ;
return V_5 ;
}
static int F_11 ( int V_16 )
{
struct V_3 V_4 = { . V_6 = V_17 , } ;
V_4 . V_18 = V_16 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_12 ( int V_16 )
{
struct V_3 V_4 = { . V_6 = V_19 , } ;
V_4 . V_18 = V_16 & 0xff ;
return F_3 ( & V_4 ) ? : ( V_4 . V_6 & 0xffff ) * V_20 ;
}
static int F_13 ( int V_16 )
{
struct V_3 V_4 = { . V_6 = V_21 , } ;
if ( V_22 )
return - V_15 ;
V_4 . V_18 = V_16 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_14 ( int V_16 )
{
static int V_23 [ 2 ] = { V_24 , V_24 } ;
if ( V_23 [ V_16 ] == V_24 )
V_23 [ V_16 ] = F_13 ( V_16 ) ;
return V_23 [ V_16 ] ;
}
static int F_15 ( int V_16 , int V_25 )
{
struct V_3 V_4 = { . V_6 = V_26 , } ;
V_4 . V_18 = ( V_16 & 0xff ) | ( V_25 << 8 ) ;
return F_3 ( & V_4 ) ? : ( V_4 . V_6 & 0xffff ) * V_20 ;
}
static int F_16 ( int V_16 , int V_25 )
{
struct V_3 V_4 = { . V_6 = V_27 , } ;
V_25 = ( V_25 < 0 ) ? 0 : ( ( V_25 > V_28 ) ? V_28 : V_25 ) ;
V_4 . V_18 = ( V_16 & 0xff ) | ( V_25 << 8 ) ;
return F_3 ( & V_4 ) ? : F_11 ( V_16 ) ;
}
static int F_17 ( int V_29 )
{
struct V_3 V_4 = { . V_6 = V_30 , } ;
V_4 . V_18 = V_29 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_18 ( int V_29 )
{
struct V_3 V_4 = {
. V_6 = V_31 ,
. V_18 = V_29 & 0xff ,
} ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_19 ( int V_29 )
{
int V_32 = F_18 ( V_29 ) ;
if ( V_32 == 0x99 ) {
F_20 ( 100 ) ;
V_32 = F_18 ( V_29 ) ;
}
if ( V_32 > V_33 )
return - V_34 ;
return V_32 ;
}
static int F_21 ( int V_35 )
{
struct V_3 V_4 = { . V_6 = V_35 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_4 . V_6 == 1145651527 && V_4 . V_36 == 1145392204 ? 0 : - 1 ;
}
static int F_22 ( void )
{
struct V_3 V_4 = { . V_6 = V_37 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( ( V_4 . V_6 >> V_38 ) & V_39 ) {
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
static int F_23 ( void )
{
struct V_3 V_4 = { . V_6 = V_46 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_4 . V_6 & 0xff ) == V_47 ? V_48 : V_49 ;
}
static int
F_24 ( struct V_50 * V_51 , unsigned int V_52 , unsigned long V_53 )
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
if ( V_60 && ! F_25 ( V_61 ) )
return - V_62 ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
F_26 ( V_55 , V_63 , sizeof( V_55 ) ) ;
break;
case V_64 :
V_54 = F_22 () ;
break;
case V_65 :
V_54 = F_23 () ;
break;
case V_66 :
V_54 = F_19 ( 0 ) ;
break;
case V_67 :
if ( F_27 ( & V_54 , V_56 , sizeof( int ) ) )
return - V_68 ;
V_54 = F_12 ( V_54 ) ;
break;
case V_69 :
if ( F_27 ( & V_54 , V_56 , sizeof( int ) ) )
return - V_68 ;
V_54 = F_11 ( V_54 ) ;
break;
case V_70 :
if ( V_60 && ! F_25 ( V_61 ) )
return - V_62 ;
if ( F_27 ( & V_54 , V_56 , sizeof( int ) ) )
return - V_68 ;
if ( F_27 ( & V_25 , V_56 + 1 , sizeof( int ) ) )
return - V_68 ;
V_54 = F_16 ( V_54 , V_25 ) ;
break;
default:
return - V_15 ;
}
if ( V_54 < 0 )
return V_54 ;
switch ( V_52 ) {
case V_57 :
if ( F_28 ( V_56 , & V_54 , 4 ) )
return - V_68 ;
break;
case V_59 :
if ( F_28 ( V_56 , V_55 , 16 ) )
return - V_68 ;
break;
default:
if ( F_28 ( V_56 , & V_54 , sizeof( int ) ) )
return - V_68 ;
break;
}
return 0 ;
}
static long F_29 ( struct V_50 * V_51 , unsigned int V_52 , unsigned long V_53 )
{
long V_71 ;
F_30 ( & V_72 ) ;
V_71 = F_24 ( V_51 , V_52 , V_53 ) ;
F_31 ( & V_72 ) ;
return V_71 ;
}
static int F_32 ( struct V_73 * V_74 , void * V_75 )
{
int V_76 , V_77 , V_78 ;
int V_79 , V_80 , V_81 , V_82 ;
V_77 = F_19 ( 0 ) ;
V_79 = F_11 ( V_83 ) ;
V_80 = F_11 ( V_84 ) ;
V_81 = F_12 ( V_83 ) ;
V_82 = F_12 ( V_84 ) ;
V_76 = F_22 () ;
if ( V_85 )
V_78 = F_23 () ;
else
V_78 = - 1 ;
F_33 ( V_74 , L_2 ,
V_86 ,
V_58 ,
( V_60 && ! F_25 ( V_61 ) ) ? L_3 : V_63 ,
V_77 ,
V_79 , V_80 , V_81 , V_82 ,
V_78 , V_76 ) ;
return 0 ;
}
static int F_34 ( struct V_87 * V_87 , struct V_50 * V_50 )
{
return F_35 ( V_50 , F_32 , NULL ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( L_4 , 0 , NULL , & V_88 ) ;
}
static void T_4 F_38 ( void )
{
F_39 ( L_4 , NULL ) ;
}
static inline void T_3 F_36 ( void )
{
}
static inline void T_4 F_38 ( void )
{
}
static T_5 F_40 ( struct V_89 * V_90 ,
struct V_91 * V_92 ,
char * V_93 )
{
static const char * const V_94 [] = {
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_8 ,
} ;
int V_95 = F_41 ( V_92 ) -> V_95 ;
int type ;
type = F_17 ( V_95 ) ;
if ( type < 0 )
return type ;
if ( type >= F_42 ( V_94 ) )
type = F_42 ( V_94 ) - 1 ;
return sprintf ( V_93 , L_10 , V_94 [ type ] ) ;
}
static T_5 F_43 ( struct V_89 * V_90 ,
struct V_91 * V_92 ,
char * V_93 )
{
int V_95 = F_41 ( V_92 ) -> V_95 ;
int V_32 ;
V_32 = F_19 ( V_95 ) ;
if ( V_32 < 0 )
return V_32 ;
return sprintf ( V_93 , L_11 , V_32 * 1000 ) ;
}
static T_5 F_44 ( struct V_89 * V_90 ,
struct V_91 * V_92 ,
char * V_93 )
{
static const char * const V_94 [] = {
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
} ;
int V_95 = F_41 ( V_92 ) -> V_95 ;
bool V_96 = false ;
int type ;
type = F_14 ( V_95 ) ;
if ( type < 0 )
return type ;
if ( type & 0x10 ) {
V_96 = true ;
type &= 0x0F ;
}
if ( type >= F_42 ( V_94 ) )
type = ( F_42 ( V_94 ) - 1 ) ;
return sprintf ( V_93 , L_18 , ( V_96 ? L_19 : L_20 ) , V_94 [ type ] ) ;
}
static T_5 F_45 ( struct V_89 * V_90 ,
struct V_91 * V_92 ,
char * V_93 )
{
int V_95 = F_41 ( V_92 ) -> V_95 ;
int V_97 ;
V_97 = F_12 ( V_95 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_93 , L_11 , V_97 ) ;
}
static T_5 F_46 ( struct V_89 * V_90 ,
struct V_91 * V_92 ,
char * V_93 )
{
int V_95 = F_41 ( V_92 ) -> V_95 ;
int V_98 ;
V_98 = F_11 ( V_95 ) ;
if ( V_98 < 0 )
return - V_99 ;
return sprintf ( V_93 , L_11 , F_47 ( V_98 * V_100 , 0 , 255 ) ) ;
}
static T_5 F_48 ( struct V_89 * V_90 ,
struct V_91 * V_101 ,
const char * V_93 , T_6 V_102 )
{
int V_95 = F_41 ( V_101 ) -> V_95 ;
unsigned long V_54 ;
int V_103 ;
V_103 = F_49 ( V_93 , 10 , & V_54 ) ;
if ( V_103 )
return V_103 ;
V_54 = F_47 ( F_50 ( V_54 , V_100 ) , 0 , V_28 ) ;
F_30 ( & V_72 ) ;
V_103 = F_16 ( V_95 , V_54 ) ;
F_31 ( & V_72 ) ;
return V_103 < 0 ? - V_99 : V_102 ;
}
static T_7 F_51 ( struct V_104 * V_105 , struct V_106 * V_101 ,
int V_95 )
{
if ( V_22 &&
( V_95 == 9 || V_95 == 12 ) )
return 0 ;
if ( V_95 >= 0 && V_95 <= 1 &&
! ( V_107 & V_108 ) )
return 0 ;
if ( V_95 >= 2 && V_95 <= 3 &&
! ( V_107 & V_109 ) )
return 0 ;
if ( V_95 >= 4 && V_95 <= 5 &&
! ( V_107 & V_110 ) )
return 0 ;
if ( V_95 >= 6 && V_95 <= 7 &&
! ( V_107 & V_111 ) )
return 0 ;
if ( V_95 >= 8 && V_95 <= 10 &&
! ( V_107 & V_112 ) )
return 0 ;
if ( V_95 >= 11 && V_95 <= 13 &&
! ( V_107 & V_113 ) )
return 0 ;
return V_101 -> V_114 ;
}
static int T_3 F_52 ( void )
{
int V_103 ;
V_107 = 0 ;
V_103 = F_17 ( 0 ) ;
if ( V_103 >= 0 )
V_107 |= V_108 ;
V_103 = F_17 ( 1 ) ;
if ( V_103 >= 0 )
V_107 |= V_109 ;
V_103 = F_17 ( 2 ) ;
if ( V_103 >= 0 )
V_107 |= V_110 ;
V_103 = F_17 ( 3 ) ;
if ( V_103 >= 0 )
V_107 |= V_111 ;
V_103 = F_11 ( 0 ) ;
if ( V_103 < 0 )
V_103 = F_14 ( 0 ) ;
if ( V_103 >= 0 )
V_107 |= V_112 ;
V_103 = F_11 ( 1 ) ;
if ( V_103 < 0 )
V_103 = F_14 ( 1 ) ;
if ( V_103 >= 0 )
V_107 |= V_113 ;
V_115 = F_53 ( NULL , L_21 ,
NULL , V_116 ) ;
if ( F_54 ( V_115 ) ) {
V_103 = F_55 ( V_115 ) ;
V_115 = NULL ;
F_56 ( L_22 , V_103 ) ;
return V_103 ;
}
return 0 ;
}
static int T_3 F_57 ( void )
{
const struct V_117 * V_118 ;
int V_16 , V_71 ;
if ( ! F_58 ( V_119 ) ) {
if ( ! V_120 && ! V_121 )
return - V_122 ;
F_59 ( L_23 ) ;
F_59 ( L_24 ,
F_1 ( V_123 ) ,
F_1 ( V_124 ) ,
F_1 ( V_125 ) ) ;
}
if ( F_58 ( V_126 ) )
V_22 = true ;
F_26 ( V_58 , F_1 ( V_125 ) ,
sizeof( V_58 ) ) ;
F_26 ( V_63 , F_1 ( V_127 ) ,
sizeof( V_63 ) ) ;
if ( F_21 ( V_128 ) &&
F_21 ( V_129 ) ) {
F_56 ( L_25 ) ;
if ( ! V_121 )
return - V_122 ;
}
V_118 = F_60 ( V_119 ) ;
if ( V_118 && V_118 -> V_130 ) {
const struct V_131 * V_132 = V_118 -> V_130 ;
if ( ! V_133 && V_132 -> V_133 )
V_133 = V_132 -> V_133 ;
if ( ! V_134 && V_132 -> V_134 )
V_134 = V_132 -> V_134 ;
}
V_28 = V_134 ? : V_135 ;
V_100 = F_61 ( 255 , V_28 ) ;
if ( ! V_133 ) {
for ( V_16 = 0 ; V_16 < 2 ; ++ V_16 ) {
V_71 = F_15 ( V_16 , V_28 ) ;
if ( V_71 < 0 )
continue;
if ( V_71 > V_136 )
V_20 = 1 ;
break;
}
} else {
V_20 = V_133 ;
}
return 0 ;
}
static int T_3 F_62 ( void )
{
int V_103 ;
if ( F_57 () )
return - V_122 ;
V_103 = F_52 () ;
if ( V_103 )
return V_103 ;
F_36 () ;
return 0 ;
}
static void T_4 F_63 ( void )
{
F_64 ( V_115 ) ;
F_38 () ;
}
