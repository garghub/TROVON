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
unsigned long V_8 , V_37 ;
V_8 = F_9 ( F_8 ( & V_27 ) ) ;
for ( V_37 = 0 ; V_37 < V_8 ; V_37 ++ )
F_19 ( V_37 << V_38 ,
V_39 , 0 ) ;
}
static T_3 T_1 void F_20 ( void )
{
if ( ( F_21 ( NULL , 0 , 0 , 0 ) >> 28 ) <= 2 ) {
V_3 . V_40 |= V_41 ;
return;
}
if ( F_21 ( & V_42 , 3 , 2 , 2 ) == - V_43 || ! V_42 . V_44 )
return;
if ( ! memcmp ( V_42 . V_45 [ 0 ] . V_46 , L_8 , 3 ) )
V_3 . V_40 |= V_47 ;
else
V_3 . V_40 |= V_48 ;
}
static void F_22 ( void )
{
unsigned long V_49 ;
const struct V_50 * V_51 ;
V_49 = V_3 . V_52 . V_49 ;
V_51 = F_23 ( V_49 & V_53 ) ;
if ( ! V_51 )
F_4 ( 0 ) ;
V_3 . V_52 . V_49 = V_51 -> V_51 | V_54 ;
}
static T_3 T_1 void F_24 ( void )
{
T_5 V_55 ;
V_55 . V_56 = V_57 | V_58 | V_59 | V_60 ;
V_55 . V_49 = V_54 | ( unsigned long ) V_61 ;
V_3 . V_62 = V_55 ;
V_55 . V_49 = V_54 | ( unsigned long ) V_63 ;
V_3 . V_64 = V_55 ;
V_65 = F_22 ;
}
static T_3 T_1 void F_25 ( void )
{
F_26 ( V_3 . V_66 ,
F_27 ( V_3 . V_66 ) ) ;
}
static T_3 T_1 void F_28 ( void )
{
#ifndef F_29
if ( ! F_30 ( 2 ) || ! F_30 ( 8 ) )
return;
V_3 . V_40 |= V_67 ;
F_31 ( 0 , 23 ) ;
#endif
}
static T_1 void F_32 ( void )
{
#ifndef F_33
int V_68 ;
asm volatile(
" la 0,0\n"
" mvpg %2,%2\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "a" (0) : "memory", "cc", "0");
if ( ! V_68 )
V_3 . V_40 |= V_69 ;
#endif
}
static T_1 void F_34 ( void )
{
#ifndef F_33
int V_68 , V_70 ;
asm volatile(
" efpc %1,0\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc), "=d" (tmp): "0" (-EOPNOTSUPP) : "cc");
if ( ! V_68 )
V_3 . V_40 |= V_71 ;
#endif
}
static T_1 void F_35 ( void )
{
#ifndef F_33
int V_68 ;
asm volatile(
" la 0,0\n"
" la 1,0\n"
" la 2,4\n"
" csp 0,2\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc", "0", "1", "2");
if ( ! V_68 )
V_3 . V_40 |= V_72 ;
#endif
}
static T_1 void F_36 ( void )
{
unsigned int V_73 ;
int V_68 ;
V_73 = F_37 () ;
asm volatile(
" diag %2,0,0x9c\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "d" (cpu_address) : "cc");
if ( ! V_68 )
V_3 . V_40 |= V_74 ;
}
static T_1 void F_38 ( void )
{
#ifdef F_33
int V_68 ;
asm volatile(
" diag 0,0,0x44\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc");
if ( ! V_68 )
V_3 . V_40 |= V_75 ;
#endif
}
static T_1 void F_39 ( void )
{
#ifdef F_33
if ( F_30 ( 3 ) )
V_3 . V_40 |= V_76 ;
if ( F_30 ( 8 ) )
V_3 . V_40 |= V_77 ;
if ( F_30 ( 11 ) )
V_3 . V_40 |= V_78 ;
if ( F_30 ( 27 ) )
V_3 . V_40 |= V_79 ;
if ( F_30 ( 40 ) )
V_3 . V_40 |= V_80 ;
#endif
}
static T_1 void F_40 ( void )
{
#ifdef F_6
unsigned long V_81 = ( unsigned long ) V_27 + ( 4UL << 20 ) ;
if ( ! V_28 || ! V_29 )
return;
if ( V_28 >= V_81 )
return;
memmove ( ( void * ) V_81 , ( void * ) V_28 , V_29 ) ;
V_28 = V_81 ;
#endif
}
static void T_1 F_41 ( T_4 (* F_42)( char * , T_4 ) )
{
char * V_82 , * V_83 ;
T_4 V_68 , V_14 ;
V_14 = strlen ( V_21 ) ;
V_83 = V_21 + V_14 ;
V_82 = V_21 + V_14 + 1 ;
V_68 = F_42 ( V_82 , V_84 - V_14 - 1 ) ;
if ( V_68 ) {
if ( * V_82 == '=' )
memmove ( V_21 , V_82 + 1 , V_68 ) ;
else
* V_83 = ' ' ;
}
}
static inline int F_43 ( const char * V_85 )
{
int V_5 ;
for ( V_5 = 0 ; V_85 [ V_5 ] ; V_5 ++ )
if ( V_85 [ V_5 ] & 0x80 )
return 1 ;
return 0 ;
}
static void T_1 F_16 ( void )
{
V_86 [ V_87 - 1 ] = 0 ;
if ( F_43 ( V_86 ) )
F_44 ( V_86 , V_87 ) ;
F_45 ( V_21 , F_46 ( V_86 ) ,
V_87 ) ;
if ( V_20 )
F_41 ( V_88 ) ;
F_41 ( V_89 ) ;
}
void T_1 F_47 ( void )
{
F_1 () ;
F_48 () ;
F_40 () ;
F_17 () ;
F_18 () ;
F_49 () ;
F_50 () ;
F_24 () ;
F_25 () ;
F_20 () ;
F_15 () ;
F_16 () ;
F_5 () ;
F_32 () ;
F_34 () ;
F_35 () ;
F_36 () ;
F_38 () ;
F_39 () ;
F_28 () ;
F_51 () ;
F_52 ( V_90 ) ;
#ifdef F_53
V_3 . V_91 = ( unsigned long ) V_92 ;
#endif
F_54 () ;
}
