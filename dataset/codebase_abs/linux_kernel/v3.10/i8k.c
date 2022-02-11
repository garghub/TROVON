static inline const char * F_1 ( int V_1 )
{
const char * V_2 = F_2 ( V_1 ) ;
return V_2 && * V_2 ? V_2 : L_1 ;
}
static int F_3 ( struct V_3 * V_4 )
{
int V_5 ;
int V_6 = V_4 -> V_6 ;
#if F_4 ( V_7 )
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
:"=a"(rc)
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
:"=a"(rc)
: "a"(regs)
: "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory");
#endif
if ( V_5 != 0 || ( V_4 -> V_6 & 0xffff ) == 0xffff || V_4 -> V_6 == V_6 )
return - V_8 ;
return 0 ;
}
static int F_5 ( void )
{
struct V_3 V_4 = { . V_6 = V_9 , } ;
return F_3 ( & V_4 ) ? : V_4 . V_6 ;
}
static int F_6 ( void )
{
struct V_3 V_4 = { . V_6 = V_10 , } ;
int V_5 ;
if ( ( V_5 = F_3 ( & V_4 ) ) < 0 )
return V_5 ;
switch ( ( V_4 . V_6 >> V_11 ) & V_12 ) {
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
case V_17 :
return V_18 ;
default:
return 0 ;
}
}
static int F_7 ( void )
{
struct V_3 V_4 = { . V_6 = V_19 , } ;
int V_5 ;
if ( ( V_5 = F_3 ( & V_4 ) ) < 0 )
return V_5 ;
return ( V_4 . V_6 & 0xff ) == V_20 ? V_21 : V_22 ;
}
static int F_8 ( int V_23 )
{
struct V_3 V_4 = { . V_6 = V_24 , } ;
V_4 . V_25 = V_23 & 0xff ;
return F_3 ( & V_4 ) ? : V_4 . V_6 & 0xff ;
}
static int F_9 ( int V_23 )
{
struct V_3 V_4 = { . V_6 = V_26 , } ;
V_4 . V_25 = V_23 & 0xff ;
return F_3 ( & V_4 ) ? : ( V_4 . V_6 & 0xffff ) * V_27 ;
}
static int F_10 ( int V_23 , int V_28 )
{
struct V_3 V_4 = { . V_6 = V_29 , } ;
V_28 = ( V_28 < 0 ) ? 0 : ( ( V_28 > V_30 ) ? V_30 : V_28 ) ;
V_4 . V_25 = ( V_23 & 0xff ) | ( V_28 << 8 ) ;
return F_3 ( & V_4 ) ? : F_8 ( V_23 ) ;
}
static int F_11 ( int V_31 )
{
struct V_3 V_4 = { . V_6 = V_32 , } ;
int V_5 ;
int V_33 ;
#ifdef F_12
static int V_34 ;
#endif
V_4 . V_25 = V_31 & 0xff ;
if ( ( V_5 = F_3 ( & V_4 ) ) < 0 )
return V_5 ;
V_33 = V_4 . V_6 & 0xff ;
#ifdef F_12
if ( V_33 > V_35 ) {
V_33 = V_34 ;
V_34 = V_35 ;
} else {
V_34 = V_33 ;
}
#endif
return V_33 ;
}
static int F_13 ( int V_36 )
{
struct V_3 V_4 = { . V_6 = V_36 , } ;
int V_5 ;
if ( ( V_5 = F_3 ( & V_4 ) ) < 0 )
return V_5 ;
return V_4 . V_6 == 1145651527 && V_4 . V_37 == 1145392204 ? 0 : - 1 ;
}
static int
F_14 ( struct V_38 * V_39 , unsigned int V_40 , unsigned long V_41 )
{
int V_42 = 0 ;
int V_28 ;
unsigned char V_43 [ 16 ] ;
int T_1 * V_44 = ( int T_1 * ) V_41 ;
if ( ! V_44 )
return - V_8 ;
switch ( V_40 ) {
case V_45 :
V_42 = F_5 () ;
break;
case V_46 :
memset ( V_43 , 0 , 16 ) ;
F_15 ( V_43 , F_1 ( V_47 ) , sizeof( V_43 ) ) ;
break;
case V_48 :
V_42 = F_6 () ;
break;
case V_49 :
V_42 = F_7 () ;
break;
case V_50 :
V_42 = F_11 ( 0 ) ;
break;
case V_51 :
if ( F_16 ( & V_42 , V_44 , sizeof( int ) ) )
return - V_52 ;
V_42 = F_9 ( V_42 ) ;
break;
case V_53 :
if ( F_16 ( & V_42 , V_44 , sizeof( int ) ) )
return - V_52 ;
V_42 = F_8 ( V_42 ) ;
break;
case V_54 :
if ( V_55 && ! F_17 ( V_56 ) )
return - V_57 ;
if ( F_16 ( & V_42 , V_44 , sizeof( int ) ) )
return - V_52 ;
if ( F_16 ( & V_28 , V_44 + 1 , sizeof( int ) ) )
return - V_52 ;
V_42 = F_10 ( V_42 , V_28 ) ;
break;
default:
return - V_8 ;
}
if ( V_42 < 0 )
return V_42 ;
switch ( V_40 ) {
case V_45 :
if ( F_18 ( V_44 , & V_42 , 4 ) )
return - V_52 ;
break;
case V_46 :
if ( F_18 ( V_44 , V_43 , 16 ) )
return - V_52 ;
break;
default:
if ( F_18 ( V_44 , & V_42 , sizeof( int ) ) )
return - V_52 ;
break;
}
return 0 ;
}
static long F_19 ( struct V_38 * V_39 , unsigned int V_40 , unsigned long V_41 )
{
long V_58 ;
F_20 ( & V_59 ) ;
V_58 = F_14 ( V_39 , V_40 , V_41 ) ;
F_21 ( & V_59 ) ;
return V_58 ;
}
static int F_22 ( struct V_60 * V_61 , void * V_62 )
{
int V_63 , V_64 , V_65 ;
int V_66 , V_67 , V_68 , V_69 ;
V_64 = F_11 ( 0 ) ;
V_66 = F_8 ( V_70 ) ;
V_67 = F_8 ( V_71 ) ;
V_68 = F_9 ( V_70 ) ;
V_69 = F_9 ( V_71 ) ;
V_63 = F_6 () ;
if ( V_72 )
V_65 = F_7 () ;
else
V_65 = - 1 ;
return F_23 ( V_61 , L_2 ,
V_73 ,
V_74 ,
F_1 ( V_47 ) ,
V_64 ,
V_66 , V_67 , V_68 , V_69 ,
V_65 , V_63 ) ;
}
static int F_24 ( struct V_75 * V_75 , struct V_38 * V_38 )
{
return F_25 ( V_38 , F_22 , NULL ) ;
}
static T_2 F_26 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
char * V_80 )
{
int V_64 ;
V_64 = F_11 ( 0 ) ;
if ( V_64 < 0 )
return V_64 ;
return sprintf ( V_80 , L_3 , V_64 * 1000 ) ;
}
static T_2 F_27 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
char * V_80 )
{
int V_81 = F_28 ( V_79 ) -> V_81 ;
int V_82 ;
V_82 = F_9 ( V_81 ) ;
if ( V_82 < 0 )
return V_82 ;
return sprintf ( V_80 , L_3 , V_82 ) ;
}
static T_2 F_29 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
char * V_80 )
{
static const char * V_83 [ 4 ] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
} ;
int V_81 = F_28 ( V_79 ) -> V_81 ;
return sprintf ( V_80 , L_8 , V_83 [ V_81 ] ) ;
}
static void F_30 ( struct V_76 * V_77 )
{
F_31 ( V_77 , & V_84 ) ;
F_31 ( V_77 , & V_85 . V_86 ) ;
F_31 ( V_77 , & V_87 . V_86 ) ;
F_31 ( V_77 , & V_88 . V_86 ) ;
F_31 ( V_77 , & V_89 . V_86 ) ;
F_31 ( V_77 , & V_90 . V_86 ) ;
F_31 ( V_77 , & V_91 . V_86 ) ;
}
static int T_3 F_32 ( void )
{
int V_92 ;
V_93 = F_33 ( NULL ) ;
if ( F_34 ( V_93 ) ) {
V_92 = F_35 ( V_93 ) ;
V_93 = NULL ;
F_36 ( V_94 L_9 , V_92 ) ;
return V_92 ;
}
V_92 = F_37 ( V_93 ,
& V_91 . V_86 ) ;
if ( V_92 )
goto V_95;
V_92 = F_11 ( 0 ) ;
if ( V_92 < 0 ) {
F_38 ( V_93 ,
L_10 , V_92 ) ;
} else {
V_92 = F_37 ( V_93 , & V_84 ) ;
if ( V_92 )
goto V_96;
V_92 = F_37 ( V_93 ,
& V_88 . V_86 ) ;
if ( V_92 )
goto V_96;
}
V_92 = F_8 ( V_70 ) ;
if ( V_92 < 0 ) {
F_38 ( V_93 ,
L_11 , L_12 , V_92 ) ;
} else {
V_92 = F_37 ( V_93 ,
& V_85 . V_86 ) ;
if ( V_92 )
goto V_96;
V_92 = F_37 ( V_93 ,
& V_89 . V_86 ) ;
if ( V_92 )
goto V_96;
}
V_92 = F_8 ( V_71 ) ;
if ( V_92 < 0 ) {
F_38 ( V_93 ,
L_11 , L_13 , V_92 ) ;
} else {
V_92 = F_37 ( V_93 ,
& V_87 . V_86 ) ;
if ( V_92 )
goto V_96;
V_92 = F_37 ( V_93 ,
& V_90 . V_86 ) ;
if ( V_92 )
goto V_96;
}
return 0 ;
V_96:
F_30 ( V_93 ) ;
V_95:
F_39 ( V_93 ) ;
return V_92 ;
}
static void T_4 F_40 ( void )
{
F_30 ( V_93 ) ;
F_39 ( V_93 ) ;
}
static int T_3 F_41 ( void )
{
char V_43 [ 4 ] ;
int V_97 ;
if ( ! F_42 ( V_98 ) ) {
if ( ! V_99 && ! V_100 )
return - V_101 ;
F_36 ( V_102 L_14 ) ;
F_36 ( V_102 L_15 ,
F_1 ( V_103 ) ,
F_1 ( V_104 ) ,
F_1 ( V_105 ) ) ;
}
F_15 ( V_74 , F_1 ( V_105 ) , sizeof( V_74 ) ) ;
if ( F_13 ( V_106 ) &&
F_13 ( V_107 ) ) {
F_36 ( V_94 L_16 ) ;
if ( ! V_100 )
return - V_101 ;
}
V_97 = F_5 () ;
if ( V_97 <= 0 ) {
F_36 ( V_108 L_17 ) ;
} else {
V_43 [ 0 ] = ( V_97 >> 16 ) & 0xff ;
V_43 [ 1 ] = ( V_97 >> 8 ) & 0xff ;
V_43 [ 2 ] = ( V_97 ) & 0xff ;
V_43 [ 3 ] = '\0' ;
if ( ! F_2 ( V_105 ) )
F_15 ( V_74 , V_43 , sizeof( V_74 ) ) ;
if ( strncmp ( V_43 , V_74 , sizeof( V_74 ) ) != 0 )
F_36 ( V_108 L_18 ,
V_43 , V_74 ) ;
}
return 0 ;
}
static int T_3 F_43 ( void )
{
struct V_109 * V_110 ;
int V_92 ;
if ( F_41 () )
return - V_101 ;
V_110 = F_44 ( L_4 , 0 , NULL , & V_111 ) ;
if ( ! V_110 )
return - V_112 ;
V_92 = F_32 () ;
if ( V_92 )
goto V_113;
F_36 ( V_102
L_19 ,
V_114 ) ;
return 0 ;
V_113:
F_45 ( L_4 , NULL ) ;
return V_92 ;
}
static void T_4 F_46 ( void )
{
F_40 () ;
F_45 ( L_4 , NULL ) ;
}
