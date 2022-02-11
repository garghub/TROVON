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
int V_50 ;
if ( ! F_23 ( 11 ) )
return;
V_3 . V_43 |= V_51 ;
for ( V_50 = 6 ; V_50 > 1 ; V_50 -- ) {
if ( F_21 ( & V_42 , 15 , 1 , V_50 ) == 0 )
break;
}
V_52 = V_50 ;
}
static void F_24 ( void )
{
const struct V_53 * V_54 ;
unsigned long V_55 , V_56 ;
unsigned long V_57 ;
V_57 = V_3 . V_58 . V_57 ;
V_54 = F_25 ( V_57 ) ;
if ( ! V_54 )
F_4 ( 0 ) ;
F_26 ( V_55 , 0 , 0 ) ;
V_56 = V_55 & ~ ( 1UL << 28 ) ;
F_27 ( V_56 , 0 , 0 ) ;
V_3 . V_58 . V_57 = F_28 ( V_54 ) ;
F_27 ( V_55 , 0 , 0 ) ;
}
static T_3 T_1 void F_29 ( void )
{
T_5 V_59 ;
V_59 . V_60 = V_61 | V_62 | V_63 | V_64 ;
V_59 . V_57 = ( unsigned long ) V_65 ;
V_3 . V_66 = V_59 ;
V_59 . V_57 = ( unsigned long ) V_67 ;
V_3 . V_68 = V_59 ;
V_69 = F_24 ;
}
static T_3 T_1 void F_30 ( void )
{
F_31 ( V_3 . V_70 ,
F_32 ( V_3 . V_70 ) ) ;
}
static T_1 void F_33 ( void )
{
unsigned int V_71 ;
int V_72 ;
V_71 = F_34 () ;
F_35 ( V_73 ) ;
asm volatile(
" diag %2,0,0x9c\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "d" (cpu_address) : "cc");
if ( ! V_72 )
V_3 . V_43 |= V_74 ;
}
static T_1 void F_36 ( void )
{
int V_72 ;
F_35 ( V_75 ) ;
asm volatile(
" diag 0,0,0x44\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc");
if ( ! V_72 )
V_3 . V_43 |= V_76 ;
}
static T_1 void F_37 ( void )
{
if ( F_23 ( 8 ) ) {
V_3 . V_43 |= V_77 ;
F_38 ( 0 , 23 ) ;
}
if ( F_23 ( 78 ) )
V_3 . V_43 |= V_78 ;
if ( F_23 ( 3 ) )
V_3 . V_43 |= V_79 ;
if ( F_23 ( 40 ) )
V_3 . V_43 |= V_80 ;
if ( F_23 ( 50 ) && F_23 ( 73 ) )
V_3 . V_43 |= V_81 ;
if ( F_23 ( 51 ) )
V_3 . V_43 |= V_82 ;
if ( F_23 ( 129 ) ) {
V_3 . V_43 |= V_83 ;
F_38 ( 0 , 17 ) ;
}
}
static inline void F_39 ( void )
{
#ifdef F_40
if ( F_23 ( 129 ) )
F_41 ( V_84 ) ;
#endif
}
static int T_1 F_42 ( char * V_85 )
{
V_3 . V_43 &= ~ V_83 ;
F_43 ( 0 , 17 ) ;
return 1 ;
}
static int T_1 F_44 ( char * V_85 )
{
int V_86 ;
F_45 ( & V_85 , & V_86 ) ;
if ( V_86 && F_23 ( 128 ) )
V_3 . V_43 |= V_87 ;
return 0 ;
}
static int T_1 F_46 ( void )
{
if ( V_88 )
F_38 ( 2 , 3 ) ;
return 0 ;
}
static T_1 void F_47 ( void )
{
#ifdef F_6
unsigned long V_89 = ( unsigned long ) V_27 + ( 4UL << 20 ) ;
if ( ! V_28 || ! V_29 )
return;
if ( V_28 >= V_89 )
return;
memmove ( ( void * ) V_89 , ( void * ) V_28 , V_29 ) ;
V_28 = V_89 ;
#endif
}
static void T_1 F_48 ( T_4 (* F_49)( char * , T_4 ) )
{
char * V_90 , * V_91 ;
T_4 V_72 , V_14 ;
V_14 = strlen ( V_21 ) ;
V_91 = V_21 + V_14 ;
V_90 = V_21 + V_14 + 1 ;
V_72 = F_49 ( V_90 , V_92 - V_14 - 1 ) ;
if ( V_72 ) {
if ( * V_90 == '=' )
memmove ( V_21 , V_90 + 1 , V_72 ) ;
else
* V_91 = ' ' ;
}
}
static inline int F_50 ( const char * V_85 )
{
int V_5 ;
for ( V_5 = 0 ; V_85 [ V_5 ] ; V_5 ++ )
if ( V_85 [ V_5 ] & 0x80 )
return 1 ;
return 0 ;
}
static void T_1 F_16 ( void )
{
V_93 [ V_94 - 1 ] = 0 ;
if ( F_50 ( V_93 ) )
F_51 ( V_93 , V_94 ) ;
F_52 ( V_21 , F_53 ( V_93 ) ,
V_94 ) ;
if ( V_20 )
F_48 ( V_95 ) ;
F_48 ( V_96 ) ;
}
void T_1 F_54 ( void )
{
F_1 () ;
F_55 () ;
F_47 () ;
F_17 () ;
F_18 () ;
F_56 () ;
F_29 () ;
F_30 () ;
F_20 () ;
F_15 () ;
F_16 () ;
F_5 () ;
F_33 () ;
F_36 () ;
F_37 () ;
F_39 () ;
F_22 () ;
F_57 () ;
F_58 () ;
}
