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
V_4 . V_18 = V_16 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_14 ( int V_16 , int V_22 )
{
struct V_3 V_4 = { . V_6 = V_23 , } ;
V_4 . V_18 = ( V_16 & 0xff ) | ( V_22 << 8 ) ;
return F_3 ( & V_4 ) ? : ( V_4 . V_6 & 0xffff ) * V_20 ;
}
static int F_15 ( int V_16 , int V_22 )
{
struct V_3 V_4 = { . V_6 = V_24 , } ;
V_22 = ( V_22 < 0 ) ? 0 : ( ( V_22 > V_25 ) ? V_25 : V_22 ) ;
V_4 . V_18 = ( V_16 & 0xff ) | ( V_22 << 8 ) ;
return F_3 ( & V_4 ) ? : F_11 ( V_16 ) ;
}
static int F_16 ( int V_26 )
{
struct V_3 V_4 = { . V_6 = V_27 , } ;
V_4 . V_18 = V_26 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_17 ( int V_26 )
{
struct V_3 V_4 = {
. V_6 = V_28 ,
. V_18 = V_26 & 0xff ,
} ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_18 ( int V_26 )
{
int V_29 = F_17 ( V_26 ) ;
if ( V_29 == 0x99 ) {
F_19 ( 100 ) ;
V_29 = F_17 ( V_26 ) ;
}
if ( V_29 > V_30 )
return - V_31 ;
return V_29 ;
}
static int F_20 ( int V_32 )
{
struct V_3 V_4 = { . V_6 = V_32 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_4 . V_6 == 1145651527 && V_4 . V_33 == 1145392204 ? 0 : - 1 ;
}
static int F_21 ( void )
{
struct V_3 V_4 = { . V_6 = V_34 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( ( V_4 . V_6 >> V_35 ) & V_36 ) {
case V_37 :
return V_38 ;
case V_39 :
return V_40 ;
case V_41 :
return V_42 ;
default:
return 0 ;
}
}
static int F_22 ( void )
{
struct V_3 V_4 = { . V_6 = V_43 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_4 . V_6 & 0xff ) == V_44 ? V_45 : V_46 ;
}
static int
F_23 ( struct V_47 * V_48 , unsigned int V_49 , unsigned long V_50 )
{
int V_51 = 0 ;
int V_22 ;
unsigned char V_52 [ 16 ] ;
int T_2 * V_53 = ( int T_2 * ) V_50 ;
if ( ! V_53 )
return - V_15 ;
switch ( V_49 ) {
case V_54 :
V_51 = ( V_55 [ 0 ] << 16 ) |
( V_55 [ 1 ] << 8 ) | V_55 [ 2 ] ;
break;
case V_56 :
memset ( V_52 , 0 , 16 ) ;
F_24 ( V_52 , F_1 ( V_57 ) ,
sizeof( V_52 ) ) ;
break;
case V_58 :
V_51 = F_21 () ;
break;
case V_59 :
V_51 = F_22 () ;
break;
case V_60 :
V_51 = F_18 ( 0 ) ;
break;
case V_61 :
if ( F_25 ( & V_51 , V_53 , sizeof( int ) ) )
return - V_62 ;
V_51 = F_12 ( V_51 ) ;
break;
case V_63 :
if ( F_25 ( & V_51 , V_53 , sizeof( int ) ) )
return - V_62 ;
V_51 = F_11 ( V_51 ) ;
break;
case V_64 :
if ( V_65 && ! F_26 ( V_66 ) )
return - V_67 ;
if ( F_25 ( & V_51 , V_53 , sizeof( int ) ) )
return - V_62 ;
if ( F_25 ( & V_22 , V_53 + 1 , sizeof( int ) ) )
return - V_62 ;
V_51 = F_15 ( V_51 , V_22 ) ;
break;
default:
return - V_15 ;
}
if ( V_51 < 0 )
return V_51 ;
switch ( V_49 ) {
case V_54 :
if ( F_27 ( V_53 , & V_51 , 4 ) )
return - V_62 ;
break;
case V_56 :
if ( F_27 ( V_53 , V_52 , 16 ) )
return - V_62 ;
break;
default:
if ( F_27 ( V_53 , & V_51 , sizeof( int ) ) )
return - V_62 ;
break;
}
return 0 ;
}
static long F_28 ( struct V_47 * V_48 , unsigned int V_49 , unsigned long V_50 )
{
long V_68 ;
F_29 ( & V_69 ) ;
V_68 = F_23 ( V_48 , V_49 , V_50 ) ;
F_30 ( & V_69 ) ;
return V_68 ;
}
static int F_31 ( struct V_70 * V_71 , void * V_72 )
{
int V_73 , V_74 , V_75 ;
int V_76 , V_77 , V_78 , V_79 ;
V_74 = F_18 ( 0 ) ;
V_76 = F_11 ( V_80 ) ;
V_77 = F_11 ( V_81 ) ;
V_78 = F_12 ( V_80 ) ;
V_79 = F_12 ( V_81 ) ;
V_73 = F_21 () ;
if ( V_82 )
V_75 = F_22 () ;
else
V_75 = - 1 ;
F_32 ( V_71 , L_2 ,
V_83 ,
V_55 ,
F_1 ( V_57 ) ,
V_74 ,
V_76 , V_77 , V_78 , V_79 ,
V_75 , V_73 ) ;
return 0 ;
}
static int F_33 ( struct V_84 * V_84 , struct V_47 * V_47 )
{
return F_34 ( V_47 , F_31 , NULL ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( L_3 , 0 , NULL , & V_85 ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( L_3 , NULL ) ;
}
static inline void T_3 F_35 ( void )
{
}
static inline void T_4 F_37 ( void )
{
}
static T_5 F_39 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
static const char * const V_91 [] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_7 ,
} ;
int V_92 = F_40 ( V_89 ) -> V_92 ;
int type ;
type = F_16 ( V_92 ) ;
if ( type < 0 )
return type ;
if ( type >= F_41 ( V_91 ) )
type = F_41 ( V_91 ) - 1 ;
return sprintf ( V_90 , L_9 , V_91 [ type ] ) ;
}
static T_5 F_42 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
int V_92 = F_40 ( V_89 ) -> V_92 ;
int V_29 ;
V_29 = F_18 ( V_92 ) ;
if ( V_29 < 0 )
return V_29 ;
return sprintf ( V_90 , L_10 , V_29 * 1000 ) ;
}
static T_5 F_43 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
static const char * const V_91 [] = {
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
} ;
int V_92 = F_40 ( V_89 ) -> V_92 ;
bool V_93 = false ;
int type ;
type = F_13 ( V_92 ) ;
if ( type < 0 )
return type ;
if ( type & 0x10 ) {
V_93 = true ;
type &= 0x0F ;
}
if ( type >= F_41 ( V_91 ) )
type = ( F_41 ( V_91 ) - 1 ) ;
return sprintf ( V_90 , L_17 , ( V_93 ? L_18 : L_19 ) , V_91 [ type ] ) ;
}
static T_5 F_44 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
int V_92 = F_40 ( V_89 ) -> V_92 ;
int V_94 ;
V_94 = F_12 ( V_92 ) ;
if ( V_94 < 0 )
return V_94 ;
return sprintf ( V_90 , L_10 , V_94 ) ;
}
static T_5 F_45 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
char * V_90 )
{
int V_92 = F_40 ( V_89 ) -> V_92 ;
int V_95 ;
V_95 = F_11 ( V_92 ) ;
if ( V_95 < 0 )
return - V_96 ;
return sprintf ( V_90 , L_10 , F_46 ( V_95 * V_97 , 0 , 255 ) ) ;
}
static T_5 F_47 ( struct V_86 * V_87 ,
struct V_88 * V_98 ,
const char * V_90 , T_6 V_99 )
{
int V_92 = F_40 ( V_98 ) -> V_92 ;
unsigned long V_51 ;
int V_100 ;
V_100 = F_48 ( V_90 , 10 , & V_51 ) ;
if ( V_100 )
return V_100 ;
V_51 = F_46 ( F_49 ( V_51 , V_97 ) , 0 , V_25 ) ;
F_29 ( & V_69 ) ;
V_100 = F_15 ( V_92 , V_51 ) ;
F_30 ( & V_69 ) ;
return V_100 < 0 ? - V_96 : V_99 ;
}
static T_7 F_50 ( struct V_101 * V_102 , struct V_103 * V_98 ,
int V_92 )
{
if ( V_92 >= 0 && V_92 <= 1 &&
! ( V_104 & V_105 ) )
return 0 ;
if ( V_92 >= 2 && V_92 <= 3 &&
! ( V_104 & V_106 ) )
return 0 ;
if ( V_92 >= 4 && V_92 <= 5 &&
! ( V_104 & V_107 ) )
return 0 ;
if ( V_92 >= 6 && V_92 <= 7 &&
! ( V_104 & V_108 ) )
return 0 ;
if ( V_92 >= 8 && V_92 <= 10 &&
! ( V_104 & V_109 ) )
return 0 ;
if ( V_92 >= 11 && V_92 <= 13 &&
! ( V_104 & V_110 ) )
return 0 ;
return V_98 -> V_111 ;
}
static int T_3 F_51 ( void )
{
int V_100 ;
V_104 = 0 ;
V_100 = F_16 ( 0 ) ;
if ( V_100 >= 0 )
V_104 |= V_105 ;
V_100 = F_16 ( 1 ) ;
if ( V_100 >= 0 )
V_104 |= V_106 ;
V_100 = F_16 ( 2 ) ;
if ( V_100 >= 0 )
V_104 |= V_107 ;
V_100 = F_16 ( 3 ) ;
if ( V_100 >= 0 )
V_104 |= V_108 ;
V_100 = F_13 ( 0 ) ;
if ( V_100 >= 0 )
V_104 |= V_109 ;
V_100 = F_13 ( 1 ) ;
if ( V_100 >= 0 )
V_104 |= V_110 ;
V_112 = F_52 ( NULL , L_20 ,
NULL , V_113 ) ;
if ( F_53 ( V_112 ) ) {
V_100 = F_54 ( V_112 ) ;
V_112 = NULL ;
F_55 ( L_21 , V_100 ) ;
return V_100 ;
}
return 0 ;
}
static int T_3 F_56 ( void )
{
const struct V_114 * V_115 ;
int V_16 , V_68 ;
if ( ! F_57 ( V_116 ) ||
F_57 ( V_117 ) ) {
if ( ! V_118 && ! V_119 )
return - V_120 ;
F_58 ( L_22 ) ;
F_58 ( L_23 ,
F_1 ( V_121 ) ,
F_1 ( V_122 ) ,
F_1 ( V_123 ) ) ;
}
F_24 ( V_55 , F_1 ( V_123 ) ,
sizeof( V_55 ) ) ;
if ( F_20 ( V_124 ) &&
F_20 ( V_125 ) ) {
F_55 ( L_24 ) ;
if ( ! V_119 )
return - V_120 ;
}
V_115 = F_59 ( V_116 ) ;
if ( V_115 && V_115 -> V_126 ) {
const struct V_127 * V_128 = V_115 -> V_126 ;
if ( ! V_129 && V_128 -> V_129 )
V_129 = V_128 -> V_129 ;
if ( ! V_130 && V_128 -> V_130 )
V_130 = V_128 -> V_130 ;
}
V_25 = V_130 ? : V_131 ;
V_97 = F_60 ( 255 , V_25 ) ;
if ( ! V_129 ) {
for ( V_16 = 0 ; V_16 < 2 ; ++ V_16 ) {
V_68 = F_14 ( V_16 , V_25 ) ;
if ( V_68 < 0 )
continue;
if ( V_68 > V_132 )
V_20 = 1 ;
break;
}
} else {
V_20 = V_129 ;
}
return 0 ;
}
static int T_3 F_61 ( void )
{
int V_100 ;
if ( F_56 () )
return - V_120 ;
V_100 = F_51 () ;
if ( V_100 )
return V_100 ;
F_35 () ;
return 0 ;
}
static void T_4 F_62 ( void )
{
F_63 ( V_112 ) ;
F_37 () ;
}
