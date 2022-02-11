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
F_6 ( V_10 , F_7 ( 0 ) ) ;
if ( F_8 () != 0 ) {
V_5 = - V_12 ;
goto V_13;
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
V_13:
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
static int F_15 ( int V_29 , int V_34 )
{
struct V_3 V_4 = { . V_6 = V_35 , } ;
V_34 = ( V_34 < 0 ) ? 0 : ( ( V_34 > V_36 ) ? V_36 : V_34 ) ;
V_4 . V_31 = ( V_29 & 0xff ) | ( V_34 << 8 ) ;
return F_3 ( & V_4 ) ? : F_13 ( V_29 ) ;
}
static int F_16 ( int V_37 )
{
struct V_3 V_4 = { . V_6 = V_38 , } ;
int V_5 ;
int V_39 ;
#ifdef F_17
static int V_40 [ 4 ] ;
#endif
V_4 . V_31 = V_37 & 0xff ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_39 = V_4 . V_6 & 0xff ;
#ifdef F_17
if ( V_39 > V_41 ) {
V_39 = V_40 [ V_37 ] ;
V_40 [ V_37 ] = V_41 ;
} else {
V_40 [ V_37 ] = V_39 ;
}
#endif
return V_39 ;
}
static int F_18 ( int V_42 )
{
struct V_3 V_4 = { . V_6 = V_42 , } ;
int V_5 ;
V_5 = F_3 ( & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_4 . V_6 == 1145651527 && V_4 . V_43 == 1145392204 ? 0 : - 1 ;
}
static int
F_19 ( struct V_44 * V_45 , unsigned int V_46 , unsigned long V_47 )
{
int V_48 = 0 ;
int V_34 ;
unsigned char V_49 [ 16 ] ;
int T_2 * V_50 = ( int T_2 * ) V_47 ;
if ( ! V_50 )
return - V_15 ;
switch ( V_46 ) {
case V_51 :
V_48 = ( V_52 [ 0 ] << 16 ) |
( V_52 [ 1 ] << 8 ) | V_52 [ 2 ] ;
break;
case V_53 :
memset ( V_49 , 0 , 16 ) ;
F_20 ( V_49 , F_1 ( V_54 ) ,
sizeof( V_49 ) ) ;
break;
case V_55 :
V_48 = F_11 () ;
break;
case V_56 :
V_48 = F_12 () ;
break;
case V_57 :
V_48 = F_16 ( 0 ) ;
break;
case V_58 :
if ( F_21 ( & V_48 , V_50 , sizeof( int ) ) )
return - V_59 ;
V_48 = F_14 ( V_48 ) ;
break;
case V_60 :
if ( F_21 ( & V_48 , V_50 , sizeof( int ) ) )
return - V_59 ;
V_48 = F_13 ( V_48 ) ;
break;
case V_61 :
if ( V_62 && ! F_22 ( V_63 ) )
return - V_64 ;
if ( F_21 ( & V_48 , V_50 , sizeof( int ) ) )
return - V_59 ;
if ( F_21 ( & V_34 , V_50 + 1 , sizeof( int ) ) )
return - V_59 ;
V_48 = F_15 ( V_48 , V_34 ) ;
break;
default:
return - V_15 ;
}
if ( V_48 < 0 )
return V_48 ;
switch ( V_46 ) {
case V_51 :
if ( F_23 ( V_50 , & V_48 , 4 ) )
return - V_59 ;
break;
case V_53 :
if ( F_23 ( V_50 , V_49 , 16 ) )
return - V_59 ;
break;
default:
if ( F_23 ( V_50 , & V_48 , sizeof( int ) ) )
return - V_59 ;
break;
}
return 0 ;
}
static long F_24 ( struct V_44 * V_45 , unsigned int V_46 , unsigned long V_47 )
{
long V_65 ;
F_25 ( & V_66 ) ;
V_65 = F_19 ( V_45 , V_46 , V_47 ) ;
F_26 ( & V_66 ) ;
return V_65 ;
}
static int F_27 ( struct V_67 * V_68 , void * V_69 )
{
int V_70 , V_71 , V_72 ;
int V_73 , V_74 , V_75 , V_76 ;
V_71 = F_16 ( 0 ) ;
V_73 = F_13 ( V_77 ) ;
V_74 = F_13 ( V_78 ) ;
V_75 = F_14 ( V_77 ) ;
V_76 = F_14 ( V_78 ) ;
V_70 = F_11 () ;
if ( V_79 )
V_72 = F_12 () ;
else
V_72 = - 1 ;
return F_28 ( V_68 , L_2 ,
V_80 ,
V_52 ,
F_1 ( V_54 ) ,
V_71 ,
V_73 , V_74 , V_75 , V_76 ,
V_72 , V_70 ) ;
}
static int F_29 ( struct V_81 * V_81 , struct V_44 * V_44 )
{
return F_30 ( V_44 , F_27 , NULL ) ;
}
static T_3 F_31 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
char * V_86 )
{
int V_87 = F_32 ( V_85 ) -> V_87 ;
int V_39 ;
V_39 = F_16 ( V_87 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_86 , L_3 , V_39 * 1000 ) ;
}
static T_3 F_33 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
char * V_86 )
{
int V_87 = F_32 ( V_85 ) -> V_87 ;
int V_88 ;
V_88 = F_14 ( V_87 ) ;
if ( V_88 < 0 )
return V_88 ;
return sprintf ( V_86 , L_3 , V_88 ) ;
}
static T_3 F_34 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
char * V_86 )
{
int V_87 = F_32 ( V_85 ) -> V_87 ;
int V_89 ;
V_89 = F_13 ( V_87 ) ;
if ( V_89 < 0 )
return - V_90 ;
return sprintf ( V_86 , L_3 , F_35 ( V_89 * 128 , 0 , 255 ) ) ;
}
static T_3 F_36 ( struct V_82 * V_83 ,
struct V_84 * V_91 ,
const char * V_86 , T_4 V_92 )
{
int V_87 = F_32 ( V_91 ) -> V_87 ;
unsigned long V_48 ;
int V_93 ;
V_93 = F_37 ( V_86 , 10 , & V_48 ) ;
if ( V_93 )
return V_93 ;
V_48 = F_35 ( F_38 ( V_48 , 128 ) , 0 , 2 ) ;
F_25 ( & V_66 ) ;
V_93 = F_15 ( V_87 , V_48 ) ;
F_26 ( & V_66 ) ;
return V_93 < 0 ? - V_90 : V_92 ;
}
static T_3 F_39 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
char * V_86 )
{
static const char * V_94 [ 3 ] = {
L_4 ,
L_5 ,
L_6 ,
} ;
int V_87 = F_32 ( V_85 ) -> V_87 ;
return sprintf ( V_86 , L_7 , V_94 [ V_87 ] ) ;
}
static T_5 F_40 ( struct V_95 * V_96 , struct V_97 * V_91 ,
int V_87 )
{
if ( ( V_87 == 0 || V_87 == 1 ) &&
! ( V_98 & V_99 ) )
return 0 ;
if ( V_87 == 2 && ! ( V_98 & V_100 ) )
return 0 ;
if ( V_87 == 3 && ! ( V_98 & V_101 ) )
return 0 ;
if ( V_87 == 4 && ! ( V_98 & V_102 ) )
return 0 ;
if ( V_87 >= 5 && V_87 <= 7 &&
! ( V_98 & V_103 ) )
return 0 ;
if ( V_87 >= 8 && V_87 <= 10 &&
! ( V_98 & V_104 ) )
return 0 ;
return V_91 -> V_105 ;
}
static int T_6 F_41 ( void )
{
int V_93 ;
V_98 = 0 ;
V_93 = F_16 ( 0 ) ;
if ( V_93 >= 0 )
V_98 |= V_99 ;
V_93 = F_16 ( 1 ) ;
if ( V_93 >= 0 )
V_98 |= V_100 ;
V_93 = F_16 ( 2 ) ;
if ( V_93 >= 0 )
V_98 |= V_101 ;
V_93 = F_16 ( 3 ) ;
if ( V_93 >= 0 )
V_98 |= V_102 ;
V_93 = F_13 ( V_77 ) ;
if ( V_93 >= 0 )
V_98 |= V_103 ;
V_93 = F_13 ( V_78 ) ;
if ( V_93 >= 0 )
V_98 |= V_104 ;
V_106 = F_42 ( NULL , L_8 , NULL ,
V_107 ) ;
if ( F_43 ( V_106 ) ) {
V_93 = F_44 ( V_106 ) ;
V_106 = NULL ;
F_45 ( L_9 , V_93 ) ;
return V_93 ;
}
return 0 ;
}
static int T_6 F_46 ( void )
{
const struct V_108 * V_109 ;
if ( ! F_47 ( V_110 ) ) {
if ( ! V_111 && ! V_112 )
return - V_113 ;
F_48 ( L_10 ) ;
F_48 ( L_11 ,
F_1 ( V_114 ) ,
F_1 ( V_115 ) ,
F_1 ( V_116 ) ) ;
}
F_20 ( V_52 , F_1 ( V_116 ) ,
sizeof( V_52 ) ) ;
if ( F_18 ( V_117 ) &&
F_18 ( V_118 ) ) {
F_45 ( L_12 ) ;
if ( ! V_112 )
return - V_113 ;
}
V_33 = V_119 ;
V_109 = F_49 ( V_110 ) ;
if ( V_109 && V_119 == V_120 && V_109 -> V_121 )
V_33 = ( unsigned long ) V_109 -> V_121 ;
return 0 ;
}
static int T_6 F_50 ( void )
{
struct V_122 * V_123 ;
int V_93 ;
if ( F_46 () )
return - V_113 ;
V_123 = F_51 ( L_8 , 0 , NULL , & V_124 ) ;
if ( ! V_123 )
return - V_125 ;
V_93 = F_41 () ;
if ( V_93 )
goto V_126;
return 0 ;
V_126:
F_52 ( L_8 , NULL ) ;
return V_93 ;
}
static void T_7 F_53 ( void )
{
F_54 ( V_106 ) ;
F_52 ( L_8 , NULL ) ;
}
