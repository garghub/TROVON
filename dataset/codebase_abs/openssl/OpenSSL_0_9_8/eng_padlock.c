void F_1 ( void )
{
#ifdef F_2
T_1 * V_1 = F_3 () ;
if ( ! V_1 ) return;
F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
F_6 () ;
#endif
}
static int
F_7 ( T_1 * V_2 )
{
F_8 () ;
#if 1
V_3 = 0 ;
#endif
F_9 ( V_4 , sizeof( V_4 ) ,
L_1 ,
V_3 ? L_2 : L_3 ,
V_5 ? L_4 : L_5 ) ;
if ( ! F_10 ( V_2 , V_6 ) ||
! F_11 ( V_2 , V_4 ) ||
! F_12 ( V_2 , V_7 ) ||
#ifndef F_13
( V_5 && ! F_14 ( V_2 , V_8 ) ) ||
#endif
( V_3 && ! F_15 ( V_2 , & V_9 ) ) ) {
return 0 ;
}
return 1 ;
}
static T_1 *
F_3 ( void )
{
T_1 * V_10 = F_16 () ;
if ( ! V_10 ) {
return NULL ;
}
if ( ! F_7 ( V_10 ) ) {
F_5 ( V_10 ) ;
return NULL ;
}
return V_10 ;
}
static int
V_7 ( T_1 * V_2 )
{
return ( V_3 || V_5 ) ;
}
static int
F_17 ( T_1 * V_2 , const char * V_11 )
{
if ( V_11 && ( strcmp ( V_11 , V_6 ) != 0 ) ) {
return 0 ;
}
if ( ! F_7 ( V_2 ) ) {
return 0 ;
}
return 1 ;
}
static int
F_18 ( void )
{
int V_12 = - 1 ;
asm volatile (
"pushf\n"
"popl %%eax\n"
"xorl $0x200000, %%eax\n"
"movl %%eax, %%ecx\n"
"andl $0x200000, %%ecx\n"
"pushl %%eax\n"
"popf\n"
"pushf\n"
"popl %%eax\n"
"andl $0x200000, %%eax\n"
"xorl %%eax, %%ecx\n"
"movl %%ecx, %0\n"
: "=r" (result) : : "eax", "ecx");
return ( V_12 == 0 ) ;
}
static int
F_8 ( void )
{
char V_13 [ 16 ] ;
unsigned int V_14 , V_15 ;
if ( ! F_18 () )
return 0 ;
V_14 = 0x00000000 ;
V_13 [ 12 ] = 0 ;
asm volatile (
"pushl %%ebx\n"
"cpuid\n"
"movl %%ebx,(%%edi)\n"
"movl %%edx,4(%%edi)\n"
"movl %%ecx,8(%%edi)\n"
"popl %%ebx"
: "+a"(eax) : "D"(vendor_string) : "ecx", "edx");
if ( strcmp ( V_13 , L_6 ) != 0 )
return 0 ;
V_14 = 0xC0000000 ;
asm volatile ("pushl %%ebx; cpuid; popl %%ebx"
: "+a"(eax) : : "ecx", "edx");
if ( V_14 < 0xC0000001 )
return 0 ;
V_14 = 0xC0000001 ;
asm volatile ("pushl %%ebx; cpuid; popl %%ebx"
: "+a"(eax), "=d"(edx) : : "ecx");
V_5 = ( ( V_15 & ( 0x3 << 6 ) ) == ( 0x3 << 6 ) ) ;
V_3 = ( ( V_15 & ( 0x3 << 2 ) ) == ( 0x3 << 2 ) ) ;
return V_5 + V_3 ;
}
static inline void
F_19 ( T_2 * V_16 )
{
T_3 V_17 = sizeof( V_16 -> V_18 ) / sizeof( V_16 -> V_18 [ 0 ] ) ;
unsigned int * V_19 = V_16 -> V_18 ;
while ( V_17 -- ) {
asm volatile ("bswapl %0" : "+r"(*key));
V_19 ++ ;
}
}
static inline void
F_20 ( void )
{
asm volatile ("pushfl; popfl");
}
static inline void
F_21 ( struct V_20 * V_21 )
{
asm volatile (
"pushfl\n"
" btl $30,(%%esp)\n"
" jnc 1f\n"
" cmpl %2,%1\n"
" je 1f\n"
" popfl\n"
" subl $4,%%esp\n"
"1: addl $4,%%esp\n"
" movl %2,%0"
:"+m"(padlock_saved_context)
: "r"(padlock_saved_context), "r"(cdata) : "cc");
}
static inline unsigned int
F_22 ( void * V_22 , unsigned int V_23 )
{
unsigned int V_24 ;
asm volatile (".byte 0x0f,0xa7,0xc0"
: "=a"(eax_out),"=m"(*(unsigned *)addr)
: "D"(addr), "d" (edx_in)
);
return V_24 ;
}
static inline unsigned char *
F_23 ( void * V_25 , const void * V_26 , T_3 V_27 )
{
long * V_28 = V_25 ;
const long * V_29 = V_26 ;
V_27 /= sizeof( * V_28 ) ;
do { * V_28 ++ = * V_29 ++ ; } while ( -- V_27 );
return V_25 ;
}
static int T_4
F_22 ( void * V_30 , unsigned int V_31 )
{ T_5 T_6 V_32 , V_33
T_5 V_34 0x0f T_5 V_34 0xa7 T_5 V_34 0xc0
}
static void T_4
F_20 ( void )
{ T_5 V_35 T_5 V_36 }
static void T_4
F_21 ( void * V_21 )
{ T_5 {
V_35
T_7 T_8 V_37 [ V_38 ] ,30
V_39 V_40
V_41 V_33 , V_42
V_43 V_40
V_36
V_44 V_38 ,4
V_40 : V_45 V_38 ,4
T_6 V_42 , V_33
}
}
static int
F_8 ( void )
{ T_5 {
V_35
T_9 V_14
T_6 V_33 , V_14
V_46 V_14 ,1<<21
V_47 V_14
V_36
V_35
T_9 V_14
V_46 V_14 , V_33
T_7 V_14 ,21
V_39 V_48
T_6 V_14 ,0
V_49
V_46 V_14 , V_14
V_41 V_50 ,'tneC'
V_51 V_48
V_41 V_15 ,'Hrua'
V_51 V_48
V_41 V_33 ,'slua'
V_51 V_48
T_6 V_14 ,0xC0000000
V_49
T_6 V_15 , V_14
V_46 V_14 , V_14
V_41 V_15 ,0xC0000001
V_52 V_48
T_6 V_14 ,0xC0000001
V_49
V_46 V_14 , V_14
T_7 V_15 ,6
V_39 V_53
T_7 V_15 ,7
V_39 V_53
T_6 V_5 ,1
V_54 V_14
V_53 : T_7 V_15 ,2
V_39 V_55
T_7 V_15 ,3
V_39 V_55
T_6 V_3 ,1
V_54 V_14
V_55 :
V_48 :
}
}
static void T_4
F_19 ( void * V_19 )
{ T_5 {
V_35
T_10
T_6 V_56 , V_33
T_6 V_32 , V_33
T_6 V_33 ,60
V_57 : V_58
V_59 V_14
V_60
V_61 V_57
V_36
}
}
static int
V_8 ( T_1 * V_2 , const T_11 * * V_62 , const int * * V_63 , int V_64 )
{
if ( ! V_62 ) {
* V_63 = V_65 ;
return V_66 ;
}
switch ( V_64 ) {
case V_67 :
* V_62 = & V_68 ;
break;
case V_69 :
* V_62 = & V_70 ;
break;
case V_71 :
* V_62 = & V_72 ;
break;
case V_73 :
* V_62 = & V_74 ;
break;
case V_75 :
* V_62 = & V_76 ;
break;
case V_77 :
* V_62 = & V_78 ;
break;
case V_79 :
* V_62 = & V_80 ;
break;
case V_81 :
* V_62 = & V_82 ;
break;
case V_83 :
* V_62 = & V_84 ;
break;
case V_85 :
* V_62 = & V_86 ;
break;
case V_87 :
* V_62 = & V_88 ;
break;
case V_89 :
* V_62 = & V_90 ;
break;
default:
* V_62 = NULL ;
return 0 ;
}
return 1 ;
}
static int
F_24 ( T_12 * V_91 , const unsigned char * V_19 ,
const unsigned char * V_92 , int V_93 )
{
struct V_20 * V_21 ;
int V_94 = F_25 ( V_91 ) * 8 ;
if ( V_19 == NULL ) return 0 ;
V_21 = F_26 ( V_91 ) ;
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
V_21 -> V_95 . V_96 . V_97 = ( V_91 -> V_98 == 0 ) ;
V_21 -> V_95 . V_96 . V_99 = 10 + ( V_94 - 128 ) / 32 ;
V_21 -> V_95 . V_96 . V_100 = ( V_94 - 128 ) / 64 ;
switch( V_94 ) {
case 128 :
memcpy ( V_21 -> V_16 . V_18 , V_19 , V_101 ) ;
V_21 -> V_95 . V_96 . V_102 = 0 ;
break;
case 192 :
case 256 :
if ( V_93 )
F_27 ( V_19 , V_94 , & V_21 -> V_16 ) ;
else
F_28 ( V_19 , V_94 , & V_21 -> V_16 ) ;
#ifndef F_29
F_19 ( & V_21 -> V_16 ) ;
#endif
V_21 -> V_95 . V_96 . V_102 = 1 ;
break;
default:
return 0 ;
}
F_20 () ;
return 1 ;
}
static int
F_30 ( T_12 * V_91 , unsigned char * V_103 ,
const unsigned char * V_104 , T_3 V_105 )
{
struct V_20 * V_21 ;
void * V_92 ;
V_21 = F_26 ( V_91 ) ;
F_21 ( V_21 ) ;
switch ( F_31 ( V_91 ) ) {
case V_106 :
F_32 ( V_105 / V_107 , V_21 , V_103 , V_104 ) ;
break;
case V_108 :
memcpy ( V_21 -> V_92 , V_91 -> V_92 , V_107 ) ;
V_92 = F_33 ( V_105 / V_107 , V_21 , V_103 , V_104 ) ;
memcpy ( V_91 -> V_92 , V_92 , V_107 ) ;
break;
case V_109 :
memcpy ( V_21 -> V_92 , V_91 -> V_92 , V_107 ) ;
V_92 = F_34 ( V_105 / V_107 , V_21 , V_103 , V_104 ) ;
memcpy ( V_91 -> V_92 , V_92 , V_107 ) ;
break;
case V_110 :
memcpy ( V_21 -> V_92 , V_91 -> V_92 , V_107 ) ;
F_35 ( V_105 / V_107 , V_21 , V_103 , V_104 ) ;
memcpy ( V_91 -> V_92 , V_21 -> V_92 , V_107 ) ;
break;
default:
return 0 ;
}
memset ( V_21 -> V_92 , 0 , V_107 ) ;
return 1 ;
}
static int
F_36 ( T_12 * V_91 , unsigned char * V_103 ,
const unsigned char * V_104 , T_3 V_105 )
{
struct V_20 * V_21 ;
const void * V_111 ;
unsigned char * V_112 ;
void * V_92 ;
int V_113 , V_114 , V_115 ;
T_3 V_116 , V_117 = 0 ;
if ( V_105 == 0 )
return 1 ;
if ( V_105 % V_107 )
return 0 ;
if ( ! V_118 )
return F_30 ( V_91 , V_103 , V_104 , V_105 ) ;
V_113 = ( ( ( T_3 ) V_104 ) & 0x0F ) ;
V_114 = ( ( ( T_3 ) V_103 ) & 0x0F ) ;
V_115 = V_114 | V_113 ;
if ( ! V_115 )
return F_30 ( V_91 , V_103 , V_104 , V_105 ) ;
V_116 = V_105 ;
V_116 %= V_119 ;
if ( V_116 == 0 ) V_116 = V_119 ;
if ( V_114 ) {
V_117 = ( V_116 < V_105 ? V_119 : V_105 ) ;
V_112 = F_37 ( 0x10 + V_117 ) ;
V_112 = F_38 ( V_112 ) ;
}
else
V_112 = V_103 ;
V_21 = F_26 ( V_91 ) ;
F_21 ( V_21 ) ;
switch ( F_31 ( V_91 ) ) {
case V_106 :
do {
if ( V_113 )
V_111 = F_23 ( V_112 , V_104 , V_116 ) ;
else
V_111 = V_104 ;
V_104 += V_116 ;
F_32 ( V_116 / V_107 , V_21 , V_112 , V_111 ) ;
if ( V_114 )
V_103 = F_23 ( V_103 , V_112 , V_116 ) + V_116 ;
else
V_112 = V_103 += V_116 ;
V_105 -= V_116 ;
V_116 = V_119 ;
} while ( V_105 );
break;
case V_108 :
memcpy ( V_21 -> V_92 , V_91 -> V_92 , V_107 ) ;
goto V_120;
do {
if ( V_92 != V_21 -> V_92 )
memcpy ( V_21 -> V_92 , V_92 , V_107 ) ;
V_116 = V_119 ;
V_120:
if ( V_113 )
V_111 = F_23 ( V_112 , V_104 , V_116 ) ;
else
V_111 = V_104 ;
V_104 += V_116 ;
V_92 = F_33 ( V_116 / V_107 , V_21 , V_112 , V_111 ) ;
if ( V_114 )
V_103 = F_23 ( V_103 , V_112 , V_116 ) + V_116 ;
else
V_112 = V_103 += V_116 ;
} while ( V_105 -= V_116 );
memcpy ( V_91 -> V_92 , V_92 , V_107 ) ;
break;
case V_109 :
memcpy ( V_21 -> V_92 , V_91 -> V_92 , V_107 ) ;
goto V_121;
do {
if ( V_92 != V_21 -> V_92 )
memcpy ( V_21 -> V_92 , V_92 , V_107 ) ;
V_116 = V_119 ;
V_121:
if ( V_113 )
V_111 = F_23 ( V_112 , V_104 , V_116 ) ;
else
V_111 = V_104 ;
V_104 += V_116 ;
V_92 = F_34 ( V_116 / V_107 , V_21 , V_112 , V_111 ) ;
if ( V_114 )
V_103 = F_23 ( V_103 , V_112 , V_116 ) + V_116 ;
else
V_112 = V_103 += V_116 ;
} while ( V_105 -= V_116 );
memcpy ( V_91 -> V_92 , V_92 , V_107 ) ;
break;
case V_110 :
memcpy ( V_21 -> V_92 , V_91 -> V_92 , V_107 ) ;
do {
if ( V_113 )
V_111 = F_23 ( V_112 , V_104 , V_116 ) ;
else
V_111 = V_104 ;
V_104 += V_116 ;
F_35 ( V_116 / V_107 , V_21 , V_112 , V_111 ) ;
if ( V_114 )
V_103 = F_23 ( V_103 , V_112 , V_116 ) + V_116 ;
else
V_112 = V_103 += V_116 ;
V_105 -= V_116 ;
V_116 = V_119 ;
} while ( V_105 );
memcpy ( V_91 -> V_92 , V_21 -> V_92 , V_107 ) ;
break;
default:
return 0 ;
}
if ( V_114 ) {
volatile unsigned long * V_122 = ( void * ) V_112 ;
T_3 V_27 = V_117 / sizeof( * V_122 ) ;
while ( V_27 -- ) * V_122 ++ = 0 ;
}
memset ( V_21 -> V_92 , 0 , V_107 ) ;
return 1 ;
}
static int
F_39 ( unsigned char * V_123 , int V_124 )
{
unsigned int V_14 , V_125 ;
while ( V_124 >= 8 ) {
V_14 = F_22 ( V_123 , 0 ) ;
if ( ! ( V_14 & ( 1 << 6 ) ) ) return 0 ;
if ( V_14 & ( 0x1F << 10 ) ) return 0 ;
if ( ( V_14 & 0x1F ) == 0 ) continue;
if ( ( V_14 & 0x1F ) != 8 ) return 0 ;
V_123 += 8 ;
V_124 -= 8 ;
}
while ( V_124 > 0 ) {
V_14 = F_22 ( & V_125 , 3 ) ;
if ( ! ( V_14 & ( 1 << 6 ) ) ) return 0 ;
if ( V_14 & ( 0x1F << 10 ) ) return 0 ;
if ( ( V_14 & 0x1F ) == 0 ) continue;
if ( ( V_14 & 0x1F ) != 1 ) return 0 ;
* V_123 ++ = ( unsigned char ) V_125 ;
V_124 -- ;
}
* ( volatile unsigned int * ) & V_125 = 0 ;
return 1 ;
}
static int
F_40 ( void )
{
return 1 ;
}
