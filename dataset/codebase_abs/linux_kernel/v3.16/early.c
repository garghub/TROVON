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
static T_1 void F_22 ( void )
{
#ifdef F_23
int V_50 ;
if ( ! F_24 ( 11 ) )
return;
V_3 . V_43 |= V_51 ;
for ( V_50 = 6 ; V_50 > 1 ; V_50 -- ) {
if ( F_21 ( & V_42 , 15 , 1 , V_50 ) == 0 )
break;
}
V_52 = V_50 ;
#endif
}
static void F_25 ( void )
{
const struct V_53 * V_54 ;
unsigned long V_55 , V_56 ;
unsigned long V_57 ;
V_57 = V_3 . V_58 . V_57 ;
V_54 = F_26 ( V_57 & V_59 ) ;
if ( ! V_54 )
F_4 ( 0 ) ;
F_27 ( V_55 , 0 , 0 ) ;
V_56 = V_55 & ~ ( 1UL << 28 ) ;
F_28 ( V_56 , 0 , 0 ) ;
V_3 . V_58 . V_57 = F_29 ( V_54 ) | V_60 ;
F_28 ( V_55 , 0 , 0 ) ;
}
static T_3 T_1 void F_30 ( void )
{
T_5 V_61 ;
V_61 . V_62 = V_63 | V_64 | V_65 | V_66 ;
V_61 . V_57 = V_60 | ( unsigned long ) V_67 ;
V_3 . V_68 = V_61 ;
V_61 . V_57 = V_60 | ( unsigned long ) V_69 ;
V_3 . V_70 = V_61 ;
V_71 = F_25 ;
}
static T_3 T_1 void F_31 ( void )
{
F_32 ( V_3 . V_72 ,
F_33 ( V_3 . V_72 ) ) ;
}
static T_1 void F_34 ( void )
{
#ifndef F_23
int V_73 ;
asm volatile(
" la 0,0\n"
" mvpg %2,%2\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "a" (0) : "memory", "cc", "0");
if ( ! V_73 )
V_3 . V_43 |= V_74 ;
#endif
}
static T_1 void F_35 ( void )
{
#ifndef F_23
int V_73 , V_75 ;
asm volatile(
" efpc %1,0\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc), "=d" (tmp): "0" (-EOPNOTSUPP) : "cc");
if ( ! V_73 )
V_3 . V_43 |= V_76 ;
#endif
}
static T_1 void F_36 ( void )
{
#ifndef F_23
int V_73 ;
asm volatile(
" la 0,0\n"
" la 1,0\n"
" la 2,4\n"
" csp 0,2\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc", "0", "1", "2");
if ( ! V_73 )
V_3 . V_43 |= V_77 ;
#endif
}
static T_1 void F_37 ( void )
{
unsigned int V_78 ;
int V_73 ;
V_78 = F_38 () ;
asm volatile(
" diag %2,0,0x9c\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "d" (cpu_address) : "cc");
if ( ! V_73 )
V_3 . V_43 |= V_79 ;
}
static T_1 void F_39 ( void )
{
#ifdef F_23
int V_73 ;
asm volatile(
" diag 0,0,0x44\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc");
if ( ! V_73 )
V_3 . V_43 |= V_80 ;
#endif
}
static T_1 void F_40 ( void )
{
#ifdef F_23
if ( F_24 ( 8 ) ) {
V_3 . V_43 |= V_81 ;
F_41 ( 0 , 23 ) ;
}
if ( F_24 ( 78 ) )
V_3 . V_43 |= V_82 ;
if ( F_24 ( 3 ) )
V_3 . V_43 |= V_83 ;
if ( F_24 ( 40 ) )
V_3 . V_43 |= V_84 ;
if ( F_24 ( 50 ) && F_24 ( 73 ) )
V_3 . V_43 |= V_85 ;
if ( F_24 ( 66 ) )
V_3 . V_43 |= V_86 ;
if ( F_24 ( 51 ) )
V_3 . V_43 |= V_87 ;
#endif
}
static T_1 void F_42 ( void )
{
#ifdef F_6
unsigned long V_88 = ( unsigned long ) V_27 + ( 4UL << 20 ) ;
if ( ! V_28 || ! V_29 )
return;
if ( V_28 >= V_88 )
return;
memmove ( ( void * ) V_88 , ( void * ) V_28 , V_29 ) ;
V_28 = V_88 ;
#endif
}
static void T_1 F_43 ( T_4 (* F_44)( char * , T_4 ) )
{
char * V_89 , * V_90 ;
T_4 V_73 , V_14 ;
V_14 = strlen ( V_21 ) ;
V_90 = V_21 + V_14 ;
V_89 = V_21 + V_14 + 1 ;
V_73 = F_44 ( V_89 , V_91 - V_14 - 1 ) ;
if ( V_73 ) {
if ( * V_89 == '=' )
memmove ( V_21 , V_89 + 1 , V_73 ) ;
else
* V_90 = ' ' ;
}
}
static inline int F_45 ( const char * V_92 )
{
int V_5 ;
for ( V_5 = 0 ; V_92 [ V_5 ] ; V_5 ++ )
if ( V_92 [ V_5 ] & 0x80 )
return 1 ;
return 0 ;
}
static void T_1 F_16 ( void )
{
V_93 [ V_94 - 1 ] = 0 ;
if ( F_45 ( V_93 ) )
F_46 ( V_93 , V_94 ) ;
F_47 ( V_21 , F_48 ( V_93 ) ,
V_94 ) ;
if ( V_20 )
F_43 ( V_95 ) ;
F_43 ( V_96 ) ;
}
void T_1 F_49 ( void )
{
F_1 () ;
F_50 () ;
F_42 () ;
F_17 () ;
F_18 () ;
F_51 () ;
F_52 () ;
F_30 () ;
F_31 () ;
F_20 () ;
F_15 () ;
F_16 () ;
F_5 () ;
F_34 () ;
F_35 () ;
F_36 () ;
F_37 () ;
F_39 () ;
F_40 () ;
F_22 () ;
F_53 () ;
#ifdef F_54
V_3 . V_97 = ( unsigned long ) V_98 ;
#endif
F_55 () ;
}
