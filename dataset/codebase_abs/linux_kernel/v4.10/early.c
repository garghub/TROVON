static void T_1 F_1 ( void )
{
T_2 time ;
if ( F_2 ( & time ) == 0 )
return;
if ( F_3 ( V_1 ) != 0 || F_2 ( & time ) != 0 )
F_4 ( 0 ) ;
V_2 = V_1 ;
V_3 . V_4 = V_2 ;
}
static T_3 T_1 void F_5 ( void )
{
unsigned int V_5 , V_6 , V_7 , V_8 , V_9 ;
#ifdef F_6
unsigned int V_10 , V_11 ;
#endif
int V_12 ;
int V_13 ;
T_4 V_14 ;
char * V_15 ;
char V_16 [ V_17 ] ;
char V_18 [ V_19 ] ;
if ( ! V_20 )
return;
for ( V_5 = 0 ; V_5 < strlen ( V_21 ) ; V_5 ++ )
V_22 [ V_5 ] = toupper ( V_21 [ V_5 ] ) ;
V_15 = strstr ( V_22 , L_1 ) ;
if ( ! V_15 )
return;
V_15 += 8 ;
for ( V_5 = 0 ; V_5 < V_23 ; V_5 ++ ) {
if ( V_15 [ V_5 ] == ' ' || V_15 [ V_5 ] == '\0' )
break;
V_24 [ V_5 ] = V_15 [ V_5 ] ;
}
V_6 = F_7 ( F_8 ( & V_25 ) ) ;
V_7 = F_7 ( F_8 ( & V_26 ) ) ;
V_8 = F_9 ( F_8 ( & V_27 ) ) ;
V_9 = V_8 << 2 ;
V_13 = snprintf ( V_16 , V_17 ,
L_2 ,
V_24 , V_6 - 1 , V_6 ,
V_7 - 1 , V_7 , V_8 ) ;
#ifdef F_6
if ( V_28 && V_29 ) {
V_10 = F_7 ( F_8 ( V_28 ) ) ;
V_11 = F_9 ( F_8 ( V_28 + V_29 ) ) ;
V_9 = V_11 << 2 ;
V_13 += snprintf ( V_16 + V_13 , V_17 - V_13 ,
L_3 , V_10 , V_11 ) ;
}
#endif
snprintf ( V_16 + V_13 , V_17 - V_13 ,
L_4 , V_9 ) ;
V_16 [ V_17 - 1 ] = '\0' ;
snprintf ( V_18 , V_19 , L_5 ,
V_24 , V_24 ) ;
V_18 [ V_19 - 1 ] = '\0' ;
F_10 ( V_16 , NULL , 0 , & V_12 ) ;
if ( V_12 != 0 ) {
F_11 ( L_6 ,
V_12 ) ;
V_24 [ 0 ] = '\0' ;
return;
}
V_14 = strlen ( V_18 ) ;
F_12 ( V_18 , V_14 ) ;
V_12 = F_13 ( V_18 , V_14 ) ;
if ( V_12 > V_19 || V_12 == 1 ) {
F_11 ( L_7 ,
V_12 ) ;
V_24 [ 0 ] = '\0' ;
return;
}
V_2 = F_14 () ;
V_3 . V_4 = V_2 ;
V_3 . V_30 = 0x7fffffffffffffffULL ;
V_3 . V_31 = 0 ;
V_3 . V_32 = 0 ;
asm volatile("SPT 0(%0)" : : "a" (&S390_lowcore.last_update_timer));
F_15 () ;
F_16 () ;
V_33 = V_34 ;
}
static inline void F_5 ( void ) { }
static T_3 T_1 void F_17 ( void )
{
memset ( V_35 , 0 , V_36 - V_35 ) ;
}
static T_3 T_1 void F_18 ( void )
{
#if V_37
unsigned long V_8 , V_38 ;
V_8 = F_9 ( F_8 ( & V_27 ) ) ;
for ( V_38 = 0 ; V_38 < V_8 ; V_38 ++ )
F_19 ( V_38 << V_39 ,
V_37 , 0 ) ;
#endif
}
static T_3 T_1 void F_20 ( void )
{
struct V_40 * V_41 = (struct V_40 * ) & V_42 ;
if ( F_21 ( NULL , 0 , 0 , 0 ) <= 2 ) {
V_3 . V_43 |= V_44 ;
return;
}
if ( F_21 ( V_41 , 3 , 2 , 2 ) || ! V_41 -> V_45 )
return;
if ( ! memcmp ( V_41 -> V_46 [ 0 ] . V_47 , L_8 , 3 ) )
V_3 . V_43 |= V_48 ;
else
V_3 . V_43 |= V_49 ;
}
static T_3 T_1 void F_22 ( void )
{
struct V_50 * V_51 = (struct V_50 * ) & V_42 ;
if ( F_21 ( V_51 , 1 , 1 , 1 ) )
return;
F_23 ( V_51 -> V_52 , sizeof( V_51 -> V_52 ) ) ;
F_23 ( V_51 -> type , sizeof( V_51 -> type ) ) ;
F_23 ( V_51 -> V_53 , sizeof( V_51 -> V_53 ) ) ;
F_23 ( V_51 -> V_54 , sizeof( V_51 -> V_54 ) ) ;
F_24 ( L_9 ,
V_51 -> V_52 ,
V_51 -> type ,
V_51 -> V_53 ,
V_51 -> V_54 ,
V_55 ? L_10 :
V_20 ? L_11 :
V_56 ? L_12 : L_13 ) ;
}
static T_1 void F_25 ( void )
{
int V_57 ;
if ( ! F_26 ( 11 ) )
return;
V_3 . V_43 |= V_58 ;
for ( V_57 = 6 ; V_57 > 1 ; V_57 -- ) {
if ( F_21 ( & V_42 , 15 , 1 , V_57 ) == 0 )
break;
}
V_59 = V_57 ;
}
static void F_27 ( void )
{
const struct V_60 * V_61 ;
unsigned long V_62 , V_63 ;
unsigned long V_64 ;
V_64 = V_3 . V_65 . V_64 ;
V_61 = F_28 ( V_64 ) ;
if ( ! V_61 )
F_4 ( 0 ) ;
F_29 ( V_62 , 0 , 0 ) ;
V_63 = V_62 & ~ ( 1UL << 28 ) ;
F_30 ( V_63 , 0 , 0 ) ;
V_3 . V_65 . V_64 = F_31 ( V_61 ) ;
F_30 ( V_62 , 0 , 0 ) ;
}
static T_3 T_1 void F_32 ( void )
{
T_5 V_66 ;
V_66 . V_67 = V_68 | V_69 | V_70 | V_71 ;
V_66 . V_64 = ( unsigned long ) V_72 ;
V_3 . V_73 = V_66 ;
V_66 . V_64 = ( unsigned long ) V_74 ;
V_3 . V_75 = V_66 ;
V_76 = F_27 ;
V_3 . V_77 = V_78 ;
}
static T_3 T_1 void F_33 ( void )
{
F_34 ( V_3 . V_79 ,
F_35 ( V_3 . V_79 ) ) ;
}
static T_1 void F_36 ( void )
{
unsigned int V_80 ;
int V_81 ;
V_80 = F_37 () ;
F_38 ( V_82 ) ;
asm volatile(
" diag %2,0,0x9c\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "d" (cpu_address) : "cc");
if ( ! V_81 )
V_3 . V_43 |= V_83 ;
}
static T_1 void F_39 ( void )
{
int V_81 ;
F_38 ( V_84 ) ;
asm volatile(
" diag 0,0,0x44\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc");
if ( ! V_81 )
V_3 . V_43 |= V_85 ;
}
static T_1 void F_40 ( void )
{
if ( F_26 ( 8 ) ) {
V_3 . V_43 |= V_86 ;
F_41 ( 0 , 23 ) ;
}
if ( F_26 ( 78 ) )
V_3 . V_43 |= V_87 ;
if ( F_26 ( 3 ) )
V_3 . V_43 |= V_88 ;
if ( F_26 ( 40 ) )
V_3 . V_43 |= V_89 ;
if ( F_26 ( 50 ) && F_26 ( 73 ) )
V_3 . V_43 |= V_90 ;
if ( F_26 ( 51 ) )
V_3 . V_43 |= V_91 ;
if ( F_26 ( 129 ) ) {
V_3 . V_43 |= V_92 ;
F_41 ( 0 , 17 ) ;
}
}
static inline void F_42 ( void )
{
#ifdef F_43
if ( F_26 ( 129 ) )
F_44 ( V_93 ) ;
#endif
}
static int T_1 F_45 ( char * V_94 )
{
V_3 . V_43 &= ~ V_92 ;
F_46 ( 0 , 17 ) ;
return 1 ;
}
static int T_1 F_47 ( char * V_94 )
{
int V_95 ;
F_48 ( & V_94 , & V_95 ) ;
if ( V_95 && F_26 ( 128 ) )
V_3 . V_43 |= V_96 ;
return 0 ;
}
static int T_1 F_49 ( void )
{
if ( V_97 )
F_41 ( 2 , 3 ) ;
return 0 ;
}
static T_1 void F_50 ( void * V_98 , const void * V_99 , T_4 V_100 )
{
unsigned long V_64 ;
long V_101 ;
T_5 V_102 ;
if ( ! V_100 )
return;
V_101 = 1 ;
if ( V_98 > V_99 ) {
V_101 = - V_101 ;
V_98 += V_100 - 1 ;
V_99 += V_100 - 1 ;
}
V_102 = V_3 . V_75 ;
V_3 . V_75 . V_67 = F_51 () ;
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
V_3 . V_75 = V_102 ;
}
static T_1 T_3 void F_52 ( void )
{
void * V_99 , * V_98 ;
V_99 = ( void * ) ( unsigned long ) V_3 . V_103 ;
V_98 = ( void * ) V_104 ;
F_50 ( V_98 , V_99 , V_105 ) ;
V_3 . V_103 = V_104 ;
}
static T_1 T_3 void F_53 ( void )
{
#ifdef F_6
unsigned long V_106 = ( unsigned long ) V_27 + ( 4UL << 20 ) ;
if ( ! V_28 || ! V_29 )
return;
if ( V_28 >= V_106 )
return;
F_50 ( ( void * ) V_106 , ( void * ) V_28 , V_29 ) ;
V_28 = V_106 ;
#endif
}
static void T_1 F_54 ( T_4 (* F_55)( char * , T_4 ) )
{
char * V_107 , * V_108 ;
T_4 V_81 , V_14 ;
V_14 = strlen ( V_21 ) ;
V_108 = V_21 + V_14 ;
V_107 = V_21 + V_14 + 1 ;
V_81 = F_55 ( V_107 , V_109 - V_14 - 1 ) ;
if ( V_81 ) {
if ( * V_107 == '=' )
memmove ( V_21 , V_107 + 1 , V_81 ) ;
else
* V_108 = ' ' ;
}
}
static inline int F_56 ( const char * V_94 )
{
int V_5 ;
for ( V_5 = 0 ; V_94 [ V_5 ] ; V_5 ++ )
if ( V_94 [ V_5 ] & 0x80 )
return 1 ;
return 0 ;
}
static void T_1 F_16 ( void )
{
V_110 [ V_111 - 1 ] = 0 ;
if ( F_56 ( V_110 ) )
F_23 ( V_110 , V_111 ) ;
F_57 ( V_21 , F_58 ( V_110 ) ,
V_111 ) ;
if ( V_20 )
F_54 ( V_112 ) ;
F_54 ( V_113 ) ;
}
void T_1 F_59 ( void )
{
F_1 () ;
F_52 () ;
F_53 () ;
F_17 () ;
F_60 () ;
F_61 () ;
F_18 () ;
F_62 () ;
F_32 () ;
F_33 () ;
F_20 () ;
F_22 () ;
F_15 () ;
F_16 () ;
F_5 () ;
F_36 () ;
F_39 () ;
F_40 () ;
F_42 () ;
F_25 () ;
F_63 () ;
F_64 () ;
}
