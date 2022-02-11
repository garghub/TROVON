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
static inline void F_22 ( char * V_50 )
{
char * V_51 ;
V_51 = F_23 ( V_50 ) ;
if ( V_51 != V_50 )
memmove ( V_50 , V_51 , strlen ( V_51 ) ) ;
while ( * V_50 ) {
if ( ! isspace ( * V_50 ++ ) )
continue;
if ( isspace ( * V_50 ) ) {
V_51 = F_24 ( V_50 ) ;
memmove ( V_50 , V_51 , strlen ( V_51 ) + 1 ) ;
}
}
}
static T_3 T_1 void F_25 ( void )
{
struct V_52 * V_53 = (struct V_52 * ) & V_42 ;
struct V_40 * V_46 = (struct V_40 * ) & V_42 ;
char V_54 [ 80 ] , V_55 [ 17 ] ;
if ( F_21 ( V_53 , 1 , 1 , 1 ) )
return;
F_26 ( V_53 -> V_56 , sizeof( V_53 -> V_56 ) ) ;
F_26 ( V_53 -> type , sizeof( V_53 -> type ) ) ;
F_26 ( V_53 -> V_57 , sizeof( V_53 -> V_57 ) ) ;
F_26 ( V_53 -> V_58 , sizeof( V_53 -> V_58 ) ) ;
sprintf ( V_54 , L_9 ,
V_53 -> V_56 , V_53 -> type ,
V_53 -> V_57 , V_53 -> V_58 ) ;
F_22 ( V_54 ) ;
if ( F_21 ( V_46 , 3 , 2 , 2 ) == 0 && V_46 -> V_45 ) {
F_26 ( V_46 -> V_46 [ 0 ] . V_47 , sizeof( V_46 -> V_46 [ 0 ] . V_47 ) ) ;
sprintf ( V_55 , L_10 , V_46 -> V_46 [ 0 ] . V_47 ) ;
F_22 ( V_55 ) ;
} else {
sprintf ( V_55 , L_11 ,
V_59 ? L_12 :
V_20 ? L_13 :
V_60 ? L_14 : L_15 ) ;
}
F_27 ( L_16 , V_54 , V_55 ) ;
}
static T_1 void F_28 ( void )
{
int V_61 ;
if ( ! F_29 ( 11 ) )
return;
V_3 . V_43 |= V_62 ;
for ( V_61 = 6 ; V_61 > 1 ; V_61 -- ) {
if ( F_21 ( & V_42 , 15 , 1 , V_61 ) == 0 )
break;
}
V_63 = V_61 ;
}
static void F_30 ( void )
{
const struct V_64 * V_65 ;
unsigned long V_66 , V_67 ;
unsigned long V_68 ;
V_68 = V_3 . V_69 . V_68 ;
V_65 = F_31 ( V_68 ) ;
if ( ! V_65 )
F_4 ( 0 ) ;
F_32 ( V_66 , 0 , 0 ) ;
V_67 = V_66 & ~ ( 1UL << 28 ) ;
F_33 ( V_67 , 0 , 0 ) ;
V_3 . V_69 . V_68 = F_34 ( V_65 ) ;
F_33 ( V_66 , 0 , 0 ) ;
}
static T_3 T_1 void F_35 ( void )
{
T_5 V_70 ;
V_70 . V_71 = V_72 | V_73 | V_74 | V_75 ;
V_70 . V_68 = ( unsigned long ) V_76 ;
V_3 . V_77 = V_70 ;
V_70 . V_68 = ( unsigned long ) V_78 ;
V_3 . V_79 = V_70 ;
V_80 = F_30 ;
V_3 . V_81 = V_82 ;
}
static T_3 T_1 void F_36 ( void )
{
F_37 ( V_3 . V_83 ,
F_38 ( V_3 . V_83 ) ) ;
}
static T_1 void F_39 ( void )
{
unsigned int V_84 ;
int V_85 ;
V_84 = F_40 () ;
F_41 ( V_86 ) ;
asm volatile(
" diag %2,0,0x9c\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "d" (cpu_address) : "cc");
if ( ! V_85 )
V_3 . V_43 |= V_87 ;
}
static T_1 void F_42 ( void )
{
int V_85 ;
F_41 ( V_88 ) ;
asm volatile(
" diag 0,0,0x44\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc");
if ( ! V_85 )
V_3 . V_43 |= V_89 ;
}
static T_1 void F_43 ( void )
{
if ( F_29 ( 8 ) ) {
V_3 . V_43 |= V_90 ;
F_44 ( 0 , 23 ) ;
}
if ( F_29 ( 78 ) )
V_3 . V_43 |= V_91 ;
if ( F_29 ( 3 ) )
V_3 . V_43 |= V_92 ;
if ( F_29 ( 40 ) )
V_3 . V_43 |= V_93 ;
if ( F_29 ( 50 ) && F_29 ( 73 ) )
V_3 . V_43 |= V_94 ;
if ( F_29 ( 51 ) )
V_3 . V_43 |= V_95 ;
if ( F_29 ( 129 ) ) {
V_3 . V_43 |= V_96 ;
F_44 ( 0 , 17 ) ;
}
if ( F_29 ( 130 ) ) {
V_3 . V_43 |= V_97 ;
F_44 ( 0 , 20 ) ;
}
if ( F_29 ( 133 ) )
V_3 . V_43 |= V_98 ;
}
static inline void F_45 ( void )
{
#ifdef F_46
if ( F_29 ( 129 ) )
F_47 ( V_99 ) ;
#endif
}
static int T_1 F_48 ( char * V_50 )
{
bool V_100 ;
int V_85 ;
V_85 = F_49 ( V_50 , & V_100 ) ;
if ( ! V_85 && ! V_100 )
V_3 . V_43 &= ~ V_62 ;
return V_85 ;
}
static int T_1 F_50 ( char * V_50 )
{
V_3 . V_43 &= ~ V_96 ;
F_51 ( 0 , 17 ) ;
return 1 ;
}
static int T_1 F_52 ( char * V_50 )
{
bool V_100 ;
int V_85 ;
V_85 = F_49 ( V_50 , & V_100 ) ;
if ( ! V_85 && ! V_100 ) {
V_3 . V_43 &= ~ V_97 ;
F_51 ( 0 , 20 ) ;
}
return V_85 ;
}
static int T_1 F_53 ( char * V_50 )
{
bool V_100 ;
int V_85 ;
V_85 = F_49 ( V_50 , & V_100 ) ;
if ( ! V_85 && V_100 && F_29 ( 128 ) )
F_44 ( 2 , 3 ) ;
return V_85 ;
}
static T_1 void F_54 ( void * V_101 , const void * V_102 , T_4 V_103 )
{
unsigned long V_68 ;
long V_104 ;
T_5 V_105 ;
if ( ! V_103 )
return;
V_104 = 1 ;
if ( V_101 > V_102 ) {
V_104 = - V_104 ;
V_101 += V_103 - 1 ;
V_102 += V_103 - 1 ;
}
V_105 = V_3 . V_79 ;
V_3 . V_79 . V_71 = F_55 () ;
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
V_3 . V_79 = V_105 ;
}
static T_1 T_3 void F_56 ( void )
{
void * V_102 , * V_101 ;
V_102 = ( void * ) ( unsigned long ) V_3 . V_106 ;
V_101 = ( void * ) V_107 ;
F_54 ( V_101 , V_102 , V_108 ) ;
V_3 . V_106 = V_107 ;
}
static T_1 T_3 void F_57 ( void )
{
#ifdef F_6
unsigned long V_109 = ( unsigned long ) V_27 + ( 4UL << 20 ) ;
if ( ! V_28 || ! V_29 )
return;
if ( V_28 >= V_109 )
return;
F_54 ( ( void * ) V_109 , ( void * ) V_28 , V_29 ) ;
V_28 = V_109 ;
#endif
}
static void T_1 F_58 ( T_4 (* F_59)( char * , T_4 ) )
{
char * V_110 , * V_111 ;
T_4 V_85 , V_14 ;
V_14 = strlen ( V_21 ) ;
V_111 = V_21 + V_14 ;
V_110 = V_21 + V_14 + 1 ;
V_85 = F_59 ( V_110 , V_112 - V_14 - 1 ) ;
if ( V_85 ) {
if ( * V_110 == '=' )
memmove ( V_21 , V_110 + 1 , V_85 ) ;
else
* V_111 = ' ' ;
}
}
static inline int F_60 ( const char * V_50 )
{
int V_5 ;
for ( V_5 = 0 ; V_50 [ V_5 ] ; V_5 ++ )
if ( V_50 [ V_5 ] & 0x80 )
return 1 ;
return 0 ;
}
static void T_1 F_16 ( void )
{
V_113 [ V_114 - 1 ] = 0 ;
if ( F_60 ( V_113 ) )
F_26 ( V_113 , V_114 ) ;
F_61 ( V_21 , F_62 ( V_113 ) ,
V_114 ) ;
if ( V_20 )
F_58 ( V_115 ) ;
F_58 ( V_116 ) ;
}
void T_1 F_63 ( void )
{
F_1 () ;
F_56 () ;
F_57 () ;
F_17 () ;
F_64 () ;
F_65 () ;
F_18 () ;
F_66 () ;
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
F_67 () ;
F_68 () ;
}
