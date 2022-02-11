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
static T_1 void F_22 ( void )
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
V_55 . V_56 = V_57 | V_58 ;
V_55 . V_49 = V_54 | ( unsigned long ) V_59 ;
V_3 . V_60 = V_55 ;
V_55 . V_49 = V_54 | ( unsigned long ) V_61 ;
V_3 . V_62 = V_55 ;
V_63 = F_22 ;
}
static T_3 T_1 void F_25 ( void )
{
unsigned long V_64 ;
V_3 . V_65 = 0 ;
asm volatile(
" .insn s,0xb2b10000,0(0)\n"
"0:\n"
EX_TABLE(0b,0b) : "=m" (S390_lowcore.stfl_fac_list));
memcpy ( & V_3 . V_66 , & V_3 . V_65 , 4 ) ;
V_64 = 4 ;
if ( F_26 ( 7 ) ) {
register unsigned long T_6 V_67 ( L_9 ) = V_68 / 64 - 1 ;
asm volatile(".insn s,0xb2b00000,%0"
: "=m" (S390_lowcore.stfle_fac_list), "+d" (reg0)
: : "cc");
V_64 = ( T_6 + 1 ) * 8 ;
}
memset ( ( char * ) V_3 . V_66 + V_64 , 0 ,
V_68 / 8 - V_64 ) ;
}
static T_3 T_1 void F_27 ( void )
{
#ifndef F_28
if ( ! F_26 ( 2 ) || ! F_26 ( 8 ) )
return;
V_3 . V_40 |= V_69 ;
F_29 ( 0 , 23 ) ;
#endif
}
static T_1 void F_30 ( void )
{
#ifndef F_31
int V_70 ;
asm volatile(
" la 0,0\n"
" mvpg %2,%2\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "a" (0) : "memory", "cc", "0");
if ( ! V_70 )
V_3 . V_40 |= V_71 ;
#endif
}
static T_1 void F_32 ( void )
{
#ifndef F_31
int V_70 , V_72 ;
asm volatile(
" efpc %1,0\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc), "=d" (tmp): "0" (-EOPNOTSUPP) : "cc");
if ( ! V_70 )
V_3 . V_40 |= V_73 ;
#endif
}
static T_1 void F_33 ( void )
{
#ifndef F_31
int V_70 ;
asm volatile(
" la 0,0\n"
" la 1,0\n"
" la 2,4\n"
" csp 0,2\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc", "0", "1", "2");
if ( ! V_70 )
V_3 . V_40 |= V_74 ;
#endif
}
static T_1 void F_34 ( void )
{
unsigned int V_75 ;
int V_70 ;
V_75 = F_35 () ;
asm volatile(
" diag %2,0,0x9c\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP), "d" (cpu_address) : "cc");
if ( ! V_70 )
V_3 . V_40 |= V_76 ;
}
static T_1 void F_36 ( void )
{
#ifdef F_31
int V_70 ;
asm volatile(
" diag 0,0,0x44\n"
"0: la %0,0\n"
"1:\n"
EX_TABLE(0b,1b)
: "=d" (rc) : "0" (-EOPNOTSUPP) : "cc");
if ( ! V_70 )
V_3 . V_40 |= V_77 ;
#endif
}
static T_1 void F_37 ( void )
{
#ifdef F_31
if ( F_26 ( 3 ) )
V_3 . V_40 |= V_78 ;
if ( F_26 ( 8 ) )
V_3 . V_40 |= V_79 ;
if ( F_26 ( 11 ) )
V_3 . V_40 |= V_80 ;
if ( F_26 ( 27 ) )
V_3 . V_40 |= V_81 ;
if ( F_26 ( 40 ) )
V_3 . V_40 |= V_82 ;
#endif
}
static T_1 void F_38 ( void )
{
#ifdef F_6
if ( ! V_28 || ! V_29 )
return;
if ( V_28 >= ( unsigned long ) V_36 )
return;
memmove ( V_36 , ( void * ) V_28 , V_29 ) ;
V_28 = ( unsigned long ) V_36 ;
#endif
}
static void T_1 F_39 ( T_4 (* F_40)( char * , T_4 ) )
{
char * V_83 , * V_84 ;
T_4 V_70 , V_14 ;
V_14 = strlen ( V_21 ) ;
V_84 = V_21 + V_14 ;
V_83 = V_21 + V_14 + 1 ;
V_70 = F_40 ( V_83 , V_85 - V_14 - 1 ) ;
if ( V_70 ) {
if ( * V_83 == '=' )
memmove ( V_21 , V_83 + 1 , V_70 ) ;
else
* V_84 = ' ' ;
}
}
static void T_1 F_16 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_86 ; V_5 ++ )
if ( V_87 [ V_5 ] & 0x80 )
break;
if ( V_5 < V_86 )
F_41 ( V_87 , V_86 ) ;
V_87 [ V_86 - 1 ] = 0 ;
F_42 ( V_21 , F_43 ( V_87 ) ,
V_86 ) ;
if ( V_20 )
F_39 ( V_88 ) ;
F_39 ( V_89 ) ;
}
void T_1 F_44 ( void )
{
F_1 () ;
F_45 () ;
F_38 () ;
F_17 () ;
F_18 () ;
F_46 () ;
F_47 () ;
F_48 () ;
F_24 () ;
F_25 () ;
F_20 () ;
F_15 () ;
F_16 () ;
F_5 () ;
F_30 () ;
F_32 () ;
F_33 () ;
F_34 () ;
F_36 () ;
F_37 () ;
F_27 () ;
F_49 () ;
F_50 ( V_90 ) ;
#ifdef F_51
V_3 . V_91 = ( unsigned long ) V_92 ;
#endif
F_52 () ;
}
