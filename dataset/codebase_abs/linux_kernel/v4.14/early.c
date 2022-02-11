static void T_1 F_1 ( void )
{
T_2 time ;
if ( F_2 ( & time ) == 0 )
return;
if ( F_3 ( V_1 ) != 0 || F_2 ( & time ) != 0 )
F_4 ( 0 ) ;
memset ( V_2 , 0 , 16 ) ;
* ( V_3 * ) & V_2 [ 1 ] = V_1 ;
V_4 . V_5 = V_1 ;
}
static T_3 T_1 void F_5 ( void )
{
unsigned int V_6 , V_7 , V_8 , V_9 , V_10 ;
#ifdef F_6
unsigned int V_11 , V_12 ;
#endif
int V_13 ;
int V_14 ;
T_4 V_15 ;
char * V_16 ;
char V_17 [ V_18 ] ;
char V_19 [ V_20 ] ;
if ( ! V_21 )
return;
for ( V_6 = 0 ; V_6 < strlen ( V_22 ) ; V_6 ++ )
V_23 [ V_6 ] = toupper ( V_22 [ V_6 ] ) ;
V_16 = strstr ( V_23 , L_1 ) ;
if ( ! V_16 )
return;
V_16 += 8 ;
for ( V_6 = 0 ; V_6 < V_24 ; V_6 ++ ) {
if ( V_16 [ V_6 ] == ' ' || V_16 [ V_6 ] == '\0' )
break;
V_25 [ V_6 ] = V_16 [ V_6 ] ;
}
V_7 = F_7 ( F_8 ( & V_26 ) ) ;
V_8 = F_7 ( F_8 ( & V_27 ) ) ;
V_9 = F_9 ( F_8 ( & V_28 ) ) ;
V_10 = V_9 << 2 ;
V_14 = snprintf ( V_17 , V_18 ,
L_2 ,
V_25 , V_7 - 1 , V_7 ,
V_8 - 1 , V_8 , V_9 ) ;
#ifdef F_6
if ( V_29 && V_30 ) {
V_11 = F_7 ( F_8 ( V_29 ) ) ;
V_12 = F_9 ( F_8 ( V_29 + V_30 ) ) ;
V_10 = V_12 << 2 ;
V_14 += snprintf ( V_17 + V_14 , V_18 - V_14 ,
L_3 , V_11 , V_12 ) ;
}
#endif
snprintf ( V_17 + V_14 , V_18 - V_14 ,
L_4 , V_10 ) ;
V_17 [ V_18 - 1 ] = '\0' ;
snprintf ( V_19 , V_20 , L_5 ,
V_25 , V_25 ) ;
V_19 [ V_20 - 1 ] = '\0' ;
F_10 ( V_17 , NULL , 0 , & V_13 ) ;
if ( V_13 != 0 ) {
F_11 ( L_6 ,
V_13 ) ;
V_25 [ 0 ] = '\0' ;
return;
}
V_15 = strlen ( V_19 ) ;
F_12 ( V_19 , V_15 ) ;
V_13 = F_13 ( V_19 , V_15 ) ;
if ( V_13 > V_20 || V_13 == 1 ) {
F_11 ( L_7 ,
V_13 ) ;
V_25 [ 0 ] = '\0' ;
return;
}
F_14 ( V_2 ) ;
V_4 . V_5 = * ( V_3 * ) & V_2 [ 1 ] ;
V_4 . V_31 = 0x7fffffffffffffffULL ;
V_4 . V_32 = 0 ;
V_4 . V_33 = 0 ;
asm volatile("SPT 0(%0)" : : "a" (&S390_lowcore.last_update_timer));
F_15 () ;
F_16 () ;
V_34 = V_35 ;
}
static inline void F_5 ( void ) { }
static T_3 T_1 void F_17 ( void )
{
memset ( V_36 , 0 , V_37 - V_36 ) ;
}
static T_3 T_1 void F_18 ( void )
{
#if V_38
unsigned long V_9 , V_39 ;
V_9 = F_9 ( F_8 ( & V_28 ) ) ;
for ( V_39 = 0 ; V_39 < V_9 ; V_39 ++ )
F_19 ( V_39 << V_40 ,
V_38 , 0 ) ;
#endif
}
static T_3 T_1 void F_20 ( void )
{
struct V_41 * V_42 = (struct V_41 * ) & V_43 ;
if ( F_21 ( NULL , 0 , 0 , 0 ) <= 2 ) {
V_4 . V_44 |= V_45 ;
return;
}
if ( F_21 ( V_42 , 3 , 2 , 2 ) || ! V_42 -> V_46 )
return;
if ( ! memcmp ( V_42 -> V_47 [ 0 ] . V_48 , L_8 , 3 ) )
V_4 . V_44 |= V_49 ;
else
V_4 . V_44 |= V_50 ;
}
static inline void F_22 ( char * V_51 )
{
char * V_52 ;
V_52 = F_23 ( V_51 ) ;
if ( V_52 != V_51 )
memmove ( V_51 , V_52 , strlen ( V_52 ) ) ;
while ( * V_51 ) {
if ( ! isspace ( * V_51 ++ ) )
continue;
if ( isspace ( * V_51 ) ) {
V_52 = F_24 ( V_51 ) ;
memmove ( V_51 , V_52 , strlen ( V_52 ) + 1 ) ;
}
}
}
static T_3 T_1 void F_25 ( void )
{
struct V_53 * V_54 = (struct V_53 * ) & V_43 ;
struct V_41 * V_47 = (struct V_41 * ) & V_43 ;
char V_55 [ 80 ] , V_56 [ 17 ] ;
if ( F_21 ( V_54 , 1 , 1 , 1 ) )
return;
F_26 ( V_54 -> V_57 , sizeof( V_54 -> V_57 ) ) ;
F_26 ( V_54 -> type , sizeof( V_54 -> type ) ) ;
F_26 ( V_54 -> V_58 , sizeof( V_54 -> V_58 ) ) ;
F_26 ( V_54 -> V_59 , sizeof( V_54 -> V_59 ) ) ;
sprintf ( V_55 , L_9 ,
V_54 -> V_57 , V_54 -> type ,
V_54 -> V_58 , V_54 -> V_59 ) ;
F_22 ( V_55 ) ;
if ( F_21 ( V_47 , 3 , 2 , 2 ) == 0 && V_47 -> V_46 ) {
F_26 ( V_47 -> V_47 [ 0 ] . V_48 , sizeof( V_47 -> V_47 [ 0 ] . V_48 ) ) ;
sprintf ( V_56 , L_10 , V_47 -> V_47 [ 0 ] . V_48 ) ;
F_22 ( V_56 ) ;
} else {
sprintf ( V_56 , L_11 ,
V_60 ? L_12 :
V_21 ? L_13 :
V_61 ? L_14 : L_15 ) ;
}
F_27 ( L_16 , V_55 , V_56 ) ;
}
static T_1 void F_28 ( void )
{
int V_62 ;
if ( ! F_29 ( 11 ) )
return;
V_4 . V_44 |= V_63 ;
for ( V_62 = 6 ; V_62 > 1 ; V_62 -- ) {
if ( F_21 ( & V_43 , 15 , 1 , V_62 ) == 0 )
break;
}
V_64 = V_62 ;
}
static void F_30 ( void )
{
const struct V_65 * V_66 ;
unsigned long V_67 , V_68 ;
unsigned long V_69 ;
V_69 = V_4 . V_70 . V_69 ;
V_66 = F_31 ( V_69 ) ;
if ( ! V_66 )
F_4 ( 0 ) ;
F_32 ( V_67 , 0 , 0 ) ;
V_68 = V_67 & ~ ( 1UL << 28 ) ;
F_33 ( V_68 , 0 , 0 ) ;
V_4 . V_70 . V_69 = F_34 ( V_66 ) ;
F_33 ( V_67 , 0 , 0 ) ;
}
static T_3 T_1 void F_35 ( void )
{
T_5 V_71 ;
V_71 . V_72 = V_73 | V_74 | V_75 | V_76 ;
V_71 . V_69 = ( unsigned long ) V_77 ;
V_4 . V_78 = V_71 ;
V_71 . V_69 = ( unsigned long ) V_79 ;
V_4 . V_80 = V_71 ;
V_81 = F_30 ;
V_4 . V_82 = V_83 ;
}
static T_3 T_1 void F_36 ( void )
{
F_37 ( V_4 . V_84 ,
F_38 ( V_4 . V_84 ) ) ;
}
static T_1 void F_39 ( void )
{
unsigned int V_85 ;
int V_86 ;
V_85 = F_40 () ;
F_41 ( V_87 ) ;
asm volatile(
" diag %2,0,0x9c\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "d" (cpu_address) : "cc");
if ( ! V_86 )
V_4 . V_44 |= V_88 ;
}
static T_1 void F_42 ( void )
{
int V_86 ;
F_41 ( V_89 ) ;
asm volatile(
" diag 0,0,0x44\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc");
if ( ! V_86 )
V_4 . V_44 |= V_90 ;
}
static T_1 void F_43 ( void )
{
if ( F_29 ( 8 ) ) {
V_4 . V_44 |= V_91 ;
F_44 ( 0 , 23 ) ;
}
if ( F_29 ( 78 ) )
V_4 . V_44 |= V_92 ;
if ( F_29 ( 3 ) )
V_4 . V_44 |= V_93 ;
if ( F_29 ( 40 ) )
V_4 . V_44 |= V_94 ;
if ( F_29 ( 50 ) && F_29 ( 73 ) )
V_4 . V_44 |= V_95 ;
if ( F_29 ( 51 ) )
V_4 . V_44 |= V_96 ;
if ( F_29 ( 129 ) ) {
V_4 . V_44 |= V_97 ;
F_44 ( 0 , 17 ) ;
}
if ( F_29 ( 130 ) ) {
V_4 . V_44 |= V_98 ;
F_44 ( 0 , 20 ) ;
}
if ( F_29 ( 133 ) )
V_4 . V_44 |= V_99 ;
if ( F_29 ( 139 ) && ( V_2 [ 1 ] & 0x80 ) ) {
V_4 . V_44 |= V_100 ;
V_101 = - 1ULL >> 1 ;
F_44 ( 0 , 53 ) ;
}
}
static inline void F_45 ( void )
{
#ifdef F_46
if ( F_29 ( 129 ) )
F_47 ( V_102 ) ;
#endif
}
static int T_1 F_48 ( char * V_51 )
{
V_4 . V_44 &= ~ V_97 ;
F_49 ( 0 , 17 ) ;
return 0 ;
}
static int T_1 F_50 ( char * V_51 )
{
bool V_103 ;
int V_86 ;
V_86 = F_51 ( V_51 , & V_103 ) ;
if ( ! V_86 && ! V_103 ) {
V_4 . V_44 &= ~ V_98 ;
F_49 ( 0 , 20 ) ;
}
return V_86 ;
}
static int T_1 F_52 ( char * V_51 )
{
bool V_103 ;
int V_86 ;
V_86 = F_51 ( V_51 , & V_103 ) ;
if ( ! V_86 && V_103 && F_29 ( 128 ) )
F_44 ( 2 , 3 ) ;
return V_86 ;
}
static T_1 void F_53 ( void * V_104 , const void * V_105 , T_4 V_106 )
{
unsigned long V_69 ;
long V_107 ;
T_5 V_108 ;
if ( ! V_106 )
return;
V_107 = 1 ;
if ( V_104 > V_105 ) {
V_107 = - V_107 ;
V_104 += V_106 - 1 ;
V_105 += V_106 - 1 ;
}
V_108 = V_4 . V_80 ;
V_4 . V_80 . V_72 = F_54 () ;
asm volatile(
" larl %[addr],1f\n"
" stg %[addr],%[psw_pgm_addr]\n"
"0: mvc 0(1,%[dst]),0(%[src])\n"
" agr %[dst],%[incr]\n"
" agr %[src],%[incr]\n"
" brctg %[n],0b\n"
"1:\n"
: [addr] "=&d" (addr),
[psw_pgm_addr] "=Q" (S390_lowcore.program_new_psw.addr),
[dst] "+&a" (dst), [src] "+&a" (src), [n] "+d" (n)
: [incr] "d" (incr)
: "cc", "memory");
V_4 . V_80 = V_108 ;
}
static T_1 T_3 void F_55 ( void )
{
void * V_105 , * V_104 ;
V_105 = ( void * ) ( unsigned long ) V_4 . V_109 ;
V_104 = ( void * ) V_110 ;
F_53 ( V_104 , V_105 , V_111 ) ;
V_4 . V_109 = V_110 ;
}
static T_1 T_3 void F_56 ( void )
{
#ifdef F_6
unsigned long V_112 = ( unsigned long ) V_28 + ( 4UL << 20 ) ;
if ( ! V_29 || ! V_30 )
return;
if ( V_29 >= V_112 )
return;
F_53 ( ( void * ) V_112 , ( void * ) V_29 , V_30 ) ;
V_29 = V_112 ;
#endif
}
static void T_1 F_57 ( T_4 (* F_58)( char * , T_4 ) )
{
char * V_113 , * V_114 ;
T_4 V_86 , V_15 ;
V_15 = strlen ( V_22 ) ;
V_114 = V_22 + V_15 ;
V_113 = V_22 + V_15 + 1 ;
V_86 = F_58 ( V_113 , V_115 - V_15 - 1 ) ;
if ( V_86 ) {
if ( * V_113 == '=' )
memmove ( V_22 , V_113 + 1 , V_86 ) ;
else
* V_114 = ' ' ;
}
}
static inline int F_59 ( const char * V_51 )
{
int V_6 ;
for ( V_6 = 0 ; V_51 [ V_6 ] ; V_6 ++ )
if ( V_51 [ V_6 ] & 0x80 )
return 1 ;
return 0 ;
}
static void T_1 F_16 ( void )
{
V_116 [ V_117 - 1 ] = 0 ;
if ( F_59 ( V_116 ) )
F_26 ( V_116 , V_117 ) ;
F_60 ( V_22 , F_61 ( V_116 ) ,
V_117 ) ;
if ( V_21 )
F_57 ( V_118 ) ;
F_57 ( V_119 ) ;
}
void T_1 F_62 ( void )
{
F_1 () ;
F_55 () ;
F_56 () ;
F_17 () ;
F_63 () ;
F_64 () ;
F_18 () ;
F_65 () ;
F_35 () ;
F_36 () ;
F_20 () ;
F_25 () ;
F_15 () ;
F_16 () ;
F_5 () ;
F_39 () ;
F_42 () ;
F_43 () ;
F_45 () ;
F_28 () ;
F_66 () ;
F_67 () ;
}
