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
static int F_11 ( void )
{
struct V_3 V_4 = { . V_6 = V_16 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
switch ( ( V_4 . V_6 >> V_17 ) & V_18 ) {
case V_19 :
return V_20 ;
case V_21 :
return V_22 ;
case V_23 :
return V_24 ;
default:
return 0 ;
}
}
static int F_12 ( void )
{
struct V_3 V_4 = { . V_6 = V_25 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_4 . V_6 & 0xff ) == V_26 ? V_27 : V_28 ;
}
static int F_13 ( int V_29 )
{
struct V_3 V_4 = { . V_6 = V_30 , } ;
V_4 . V_31 = V_29 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_14 ( int V_29 )
{
struct V_3 V_4 = { . V_6 = V_32 , } ;
V_4 . V_31 = V_29 & 0xff ;
return F_3 ( & V_4 ) ? : ( V_4 . V_6 & 0xffff ) * V_33 ;
}
static int F_15 ( int V_29 )
{
struct V_3 V_4 = { . V_6 = V_34 , } ;
V_4 . V_31 = V_29 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_16 ( int V_29 , int V_35 )
{
struct V_3 V_4 = { . V_6 = V_36 , } ;
V_4 . V_31 = ( V_29 & 0xff ) | ( V_35 << 8 ) ;
return F_3 ( & V_4 ) ? : ( V_4 . V_6 & 0xffff ) * V_33 ;
}
static int F_17 ( int V_29 , int V_35 )
{
struct V_3 V_4 = { . V_6 = V_37 , } ;
V_35 = ( V_35 < 0 ) ? 0 : ( ( V_35 > V_38 ) ? V_38 : V_35 ) ;
V_4 . V_31 = ( V_29 & 0xff ) | ( V_35 << 8 ) ;
return F_3 ( & V_4 ) ? : F_13 ( V_29 ) ;
}
static int F_18 ( int V_39 )
{
struct V_3 V_4 = { . V_6 = V_40 , } ;
V_4 . V_31 = V_39 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_19 ( int V_39 )
{
struct V_3 V_4 = {
. V_6 = V_41 ,
. V_31 = V_39 & 0xff ,
} ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_20 ( int V_39 )
{
int V_42 = F_19 ( V_39 ) ;
if ( V_42 == 0x99 ) {
F_21 ( 100 ) ;
V_42 = F_19 ( V_39 ) ;
}
if ( V_42 > V_43 )
return - V_44 ;
return V_42 ;
}
static int F_22 ( int V_45 )
{
struct V_3 V_4 = { . V_6 = V_45 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_4 . V_6 == 1145651527 && V_4 . V_46 == 1145392204 ? 0 : - 1 ;
}
static int
F_23 ( struct V_47 * V_48 , unsigned int V_49 , unsigned long V_50 )
{
int V_51 = 0 ;
int V_35 ;
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
V_51 = F_11 () ;
break;
case V_59 :
V_51 = F_12 () ;
break;
case V_60 :
V_51 = F_20 ( 0 ) ;
break;
case V_61 :
if ( F_25 ( & V_51 , V_53 , sizeof( int ) ) )
return - V_62 ;
V_51 = F_14 ( V_51 ) ;
break;
case V_63 :
if ( F_25 ( & V_51 , V_53 , sizeof( int ) ) )
return - V_62 ;
V_51 = F_13 ( V_51 ) ;
break;
case V_64 :
if ( V_65 && ! F_26 ( V_66 ) )
return - V_67 ;
if ( F_25 ( & V_51 , V_53 , sizeof( int ) ) )
return - V_62 ;
if ( F_25 ( & V_35 , V_53 + 1 , sizeof( int ) ) )
return - V_62 ;
V_51 = F_17 ( V_51 , V_35 ) ;
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
V_74 = F_20 ( 0 ) ;
V_76 = F_13 ( V_80 ) ;
V_77 = F_13 ( V_81 ) ;
V_78 = F_14 ( V_80 ) ;
V_79 = F_14 ( V_81 ) ;
V_73 = F_11 () ;
if ( V_82 )
V_75 = F_12 () ;
else
V_75 = - 1 ;
return F_32 ( V_71 , L_2 ,
V_83 ,
V_55 ,
F_1 ( V_57 ) ,
V_74 ,
V_76 , V_77 , V_78 , V_79 ,
V_75 , V_73 ) ;
}
static int F_33 ( struct V_84 * V_84 , struct V_47 * V_47 )
{
return F_34 ( V_47 , F_31 , NULL ) ;
}
static T_3 F_35 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_89 )
{
static const char * const V_90 [] = {
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_6 ,
} ;
int V_91 = F_36 ( V_88 ) -> V_91 ;
int type ;
type = F_18 ( V_91 ) ;
if ( type < 0 )
return type ;
if ( type >= F_37 ( V_90 ) )
type = F_37 ( V_90 ) - 1 ;
return sprintf ( V_89 , L_8 , V_90 [ type ] ) ;
}
static T_3 F_38 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_89 )
{
int V_91 = F_36 ( V_88 ) -> V_91 ;
int V_42 ;
V_42 = F_20 ( V_91 ) ;
if ( V_42 < 0 )
return V_42 ;
return sprintf ( V_89 , L_9 , V_42 * 1000 ) ;
}
static T_3 F_39 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_89 )
{
static const char * const V_90 [] = {
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
} ;
int V_91 = F_36 ( V_88 ) -> V_91 ;
bool V_92 = false ;
int type ;
type = F_15 ( V_91 ) ;
if ( type < 0 )
return type ;
if ( type & 0x10 ) {
V_92 = true ;
type &= 0x0F ;
}
if ( type >= F_37 ( V_90 ) )
type = ( F_37 ( V_90 ) - 1 ) ;
return sprintf ( V_89 , L_16 , ( V_92 ? L_17 : L_18 ) , V_90 [ type ] ) ;
}
static T_3 F_40 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_89 )
{
int V_91 = F_36 ( V_88 ) -> V_91 ;
int V_93 ;
V_93 = F_14 ( V_91 ) ;
if ( V_93 < 0 )
return V_93 ;
return sprintf ( V_89 , L_9 , V_93 ) ;
}
static T_3 F_41 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
char * V_89 )
{
int V_91 = F_36 ( V_88 ) -> V_91 ;
int V_94 ;
V_94 = F_13 ( V_91 ) ;
if ( V_94 < 0 )
return - V_95 ;
return sprintf ( V_89 , L_9 , F_42 ( V_94 * V_96 , 0 , 255 ) ) ;
}
static T_3 F_43 ( struct V_85 * V_86 ,
struct V_87 * V_97 ,
const char * V_89 , T_4 V_98 )
{
int V_91 = F_36 ( V_97 ) -> V_91 ;
unsigned long V_51 ;
int V_99 ;
V_99 = F_44 ( V_89 , 10 , & V_51 ) ;
if ( V_99 )
return V_99 ;
V_51 = F_42 ( F_45 ( V_51 , V_96 ) , 0 , V_38 ) ;
F_29 ( & V_69 ) ;
V_99 = F_17 ( V_91 , V_51 ) ;
F_30 ( & V_69 ) ;
return V_99 < 0 ? - V_95 : V_98 ;
}
static T_5 F_46 ( struct V_100 * V_101 , struct V_102 * V_97 ,
int V_91 )
{
if ( V_91 >= 0 && V_91 <= 1 &&
! ( V_103 & V_104 ) )
return 0 ;
if ( V_91 >= 2 && V_91 <= 3 &&
! ( V_103 & V_105 ) )
return 0 ;
if ( V_91 >= 4 && V_91 <= 5 &&
! ( V_103 & V_106 ) )
return 0 ;
if ( V_91 >= 6 && V_91 <= 7 &&
! ( V_103 & V_107 ) )
return 0 ;
if ( V_91 >= 8 && V_91 <= 10 &&
! ( V_103 & V_108 ) )
return 0 ;
if ( V_91 >= 11 && V_91 <= 13 &&
! ( V_103 & V_109 ) )
return 0 ;
return V_97 -> V_110 ;
}
static int T_6 F_47 ( void )
{
int V_99 ;
V_103 = 0 ;
V_99 = F_18 ( 0 ) ;
if ( V_99 >= 0 )
V_103 |= V_104 ;
V_99 = F_18 ( 1 ) ;
if ( V_99 >= 0 )
V_103 |= V_105 ;
V_99 = F_18 ( 2 ) ;
if ( V_99 >= 0 )
V_103 |= V_106 ;
V_99 = F_18 ( 3 ) ;
if ( V_99 >= 0 )
V_103 |= V_107 ;
V_99 = F_15 ( 0 ) ;
if ( V_99 >= 0 )
V_103 |= V_108 ;
V_99 = F_15 ( 1 ) ;
if ( V_99 >= 0 )
V_103 |= V_109 ;
V_111 = F_48 ( NULL , L_19 , NULL ,
V_112 ) ;
if ( F_49 ( V_111 ) ) {
V_99 = F_50 ( V_111 ) ;
V_111 = NULL ;
F_51 ( L_20 , V_99 ) ;
return V_99 ;
}
return 0 ;
}
static int T_6 F_52 ( void )
{
const struct V_113 * V_114 ;
int V_29 , V_68 ;
if ( ! F_53 ( V_115 ) ) {
if ( ! V_116 && ! V_117 )
return - V_118 ;
F_54 ( L_21 ) ;
F_54 ( L_22 ,
F_1 ( V_119 ) ,
F_1 ( V_120 ) ,
F_1 ( V_121 ) ) ;
}
F_24 ( V_55 , F_1 ( V_121 ) ,
sizeof( V_55 ) ) ;
if ( F_22 ( V_122 ) &&
F_22 ( V_123 ) ) {
F_51 ( L_23 ) ;
if ( ! V_117 )
return - V_118 ;
}
V_114 = F_55 ( V_115 ) ;
if ( V_114 && V_114 -> V_124 ) {
const struct V_125 * V_126 = V_114 -> V_124 ;
if ( ! V_127 && V_126 -> V_127 )
V_127 = V_126 -> V_127 ;
if ( ! V_128 && V_126 -> V_128 )
V_128 = V_126 -> V_128 ;
}
V_38 = V_128 ? : V_129 ;
V_96 = F_56 ( 255 , V_38 ) ;
if ( ! V_127 ) {
for ( V_29 = 0 ; V_29 < 2 ; ++ V_29 ) {
V_68 = F_16 ( V_29 , V_38 ) ;
if ( V_68 < 0 )
continue;
if ( V_68 > V_130 )
V_33 = 1 ;
break;
}
} else {
V_33 = V_127 ;
}
return 0 ;
}
static int T_6 F_57 ( void )
{
struct V_131 * V_132 ;
int V_99 ;
if ( F_52 () )
return - V_118 ;
V_132 = F_58 ( L_19 , 0 , NULL , & V_133 ) ;
if ( ! V_132 )
return - V_134 ;
V_99 = F_47 () ;
if ( V_99 )
goto V_135;
return 0 ;
V_135:
F_59 ( L_19 , NULL ) ;
return V_99 ;
}
static void T_7 F_60 ( void )
{
F_61 ( V_111 ) ;
F_59 ( L_19 , NULL ) ;
}
