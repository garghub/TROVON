static inline int F_1 ( struct V_1 * args , unsigned long V_2 )
{
return ( ( int ( * ) ( struct V_1 * ) ) V_2 ) ( args ) ;
}
static int T_1 F_2 ( const char * V_3 , int V_4 , int V_5 , ... )
{
int V_6 ;
struct V_1 args ;
T_2 V_7 ;
args . V_3 = F_3 ( V_3 ) ;
args . V_4 = V_4 ;
args . V_5 = V_5 ;
va_start ( V_7 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ )
args . args [ V_6 ] = va_arg ( V_7 , V_8 ) ;
va_end ( V_7 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
args . args [ V_4 + V_6 ] = 0 ;
if ( F_1 ( & args , V_9 ) < 0 )
return V_10 ;
return ( V_5 > 0 ) ? args . args [ V_4 ] : 0 ;
}
static int T_1 F_4 ( const char * V_3 , int V_4 , int V_5 ,
V_8 * V_11 , ... )
{
int V_6 ;
struct V_1 args ;
T_2 V_7 ;
args . V_3 = F_3 ( V_3 ) ;
args . V_4 = V_4 ;
args . V_5 = V_5 ;
va_start ( V_7 , V_11 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ )
args . args [ V_6 ] = va_arg ( V_7 , V_8 ) ;
va_end ( V_7 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
args . args [ V_4 + V_6 ] = 0 ;
if ( F_1 ( & args , V_9 ) < 0 )
return V_10 ;
if ( V_11 != NULL )
for ( V_6 = 1 ; V_6 < V_5 ; ++ V_6 )
V_11 [ V_6 - 1 ] = args . args [ V_4 + V_6 ] ;
return ( V_5 > 0 ) ? args . args [ V_4 ] : 0 ;
}
static void T_1 F_5 ( const char * V_12 )
{
const char * V_13 , * V_14 ;
if ( V_15 . stdout == 0 )
return;
for ( V_13 = V_12 ; * V_13 != 0 ; V_13 = V_14 ) {
for ( V_14 = V_13 ; * V_14 != 0 && * V_14 != '\n' ; ++ V_14 )
;
if ( V_14 > V_13 )
F_2 ( L_1 , 3 , 1 , V_15 . stdout , V_13 , V_14 - V_13 ) ;
if ( * V_14 == 0 )
break;
++ V_14 ;
F_2 ( L_1 , 3 , 1 , V_15 . stdout , F_3 ( L_2 ) , 2 ) ;
}
}
static void T_1 F_6 ( unsigned long V_16 )
{
int V_6 , V_17 = sizeof( V_16 ) * 2 ;
char V_18 [ sizeof( V_16 ) * 2 + 1 ] ;
for ( V_6 = V_17 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_18 [ V_6 ] = ( V_16 & 0xf ) + '0' ;
if ( V_18 [ V_6 ] > '9' )
V_18 [ V_6 ] += ( 'a' - '0' - 10 ) ;
V_16 >>= 4 ;
}
V_18 [ V_17 ] = '\0' ;
F_2 ( L_1 , 3 , 1 , V_15 . stdout , V_18 , V_17 ) ;
}
static void T_1 F_7 ( unsigned long V_16 )
{
int V_6 , V_19 ;
char V_18 [ V_20 + 1 ] ;
for ( V_6 = V_20 - 1 ; V_6 >= 0 ; V_6 -- ) {
V_18 [ V_6 ] = ( V_16 % 10 ) + '0' ;
V_16 = V_16 / 10 ;
if ( V_16 == 0 )
break;
}
V_19 = V_20 - V_6 ;
F_2 ( L_1 , 3 , 1 , V_15 . stdout , V_18 + V_6 , V_19 ) ;
}
static void T_1 F_8 ( const char * V_21 , ... )
{
const char * V_13 , * V_14 , * V_22 ;
T_2 args ;
unsigned long V_23 ;
long V_24 ;
va_start ( args , V_21 ) ;
for ( V_13 = V_21 ; * V_13 != 0 ; V_13 = V_14 ) {
for ( V_14 = V_13 ; * V_14 != 0 && * V_14 != '\n' && * V_14 != '%' ; ++ V_14 )
;
if ( V_14 > V_13 )
F_2 ( L_1 , 3 , 1 , V_15 . stdout , V_13 , V_14 - V_13 ) ;
if ( * V_14 == 0 )
break;
if ( * V_14 == '\n' ) {
++ V_14 ;
F_2 ( L_1 , 3 , 1 , V_15 . stdout ,
F_3 ( L_2 ) , 2 ) ;
continue;
}
++ V_14 ;
if ( * V_14 == 0 )
break;
switch ( * V_14 ) {
case 's' :
++ V_14 ;
V_22 = va_arg ( args , const char * ) ;
F_5 ( V_22 ) ;
break;
case 'x' :
++ V_14 ;
V_23 = va_arg (args, unsigned long) ;
F_6 ( V_23 ) ;
break;
case 'd' :
++ V_14 ;
V_24 = va_arg ( args , int ) ;
if ( V_24 < 0 ) {
F_5 ( L_3 ) ;
V_24 = - V_24 ;
}
F_7 ( V_24 ) ;
break;
case 'l' :
++ V_14 ;
if ( * V_14 == 0 )
break;
else if ( * V_14 == 'x' ) {
++ V_14 ;
V_23 = va_arg (args, unsigned long) ;
F_6 ( V_23 ) ;
} else if ( * V_14 == 'u' ) {
++ V_14 ;
V_23 = va_arg (args, unsigned long) ;
F_7 ( V_23 ) ;
} else if ( * V_14 == 'd' ) {
++ V_14 ;
V_24 = va_arg ( args , long ) ;
if ( V_24 < 0 ) {
F_5 ( L_3 ) ;
V_24 = - V_24 ;
}
F_7 ( V_24 ) ;
}
break;
}
}
}
static unsigned int T_1 F_9 ( unsigned long V_25 , unsigned long V_19 ,
unsigned long V_26 )
{
if ( V_26 == 0 && ( V_27 & V_28 ) ) {
int V_29 ;
V_8 V_30 ;
V_29 = F_4 ( L_4 , 5 , 2 , & V_30 ,
F_3 ( L_5 ) , V_15 . V_31 ,
V_26 , V_19 , V_25 ) ;
if ( V_29 != 0 || V_30 == - 1 )
return - 1 ;
V_29 = F_4 ( L_4 , 5 , 2 , & V_30 ,
F_3 ( L_5 ) , V_15 . V_32 ,
V_26 , V_19 , V_25 ) ;
if ( V_29 != 0 ) {
F_2 ( L_4 , 4 , 1 , F_3 ( L_6 ) ,
V_15 . V_31 , V_19 , V_25 ) ;
return - 1 ;
}
F_2 ( L_4 , 6 , 1 ,
F_3 ( L_7 ) , V_15 . V_32 , 0x12 , V_19 , V_25 , V_25 ) ;
return V_25 ;
}
return F_2 ( L_5 , 3 , 1 , ( V_8 ) V_25 , ( V_8 ) V_19 ,
( V_8 ) V_26 ) ;
}
static int T_1 F_10 ( T_3 * V_33 )
{
T_3 V_34 ;
if ( ( V_34 = * V_33 ) != 0
&& ( * V_33 = F_2 ( L_8 , 1 , 1 , V_34 ) ) != 0 )
return 1 ;
if ( ( * V_33 = F_2 ( L_9 , 1 , 1 , V_34 ) ) != 0 )
return 1 ;
for (; ; ) {
if ( ( V_34 = F_2 ( L_10 , 1 , 1 , V_34 ) ) == 0 )
return 0 ;
if ( ( * V_33 = F_2 ( L_9 , 1 , 1 , V_34 ) ) != 0 )
return 1 ;
}
}
static int inline F_11 ( T_3 V_34 , const char * V_35 ,
void * V_36 , T_4 V_37 )
{
return F_2 ( L_11 , 4 , 1 , V_34 , F_3 ( V_35 ) ,
( V_38 ) ( unsigned long ) V_36 , ( V_38 ) V_37 ) ;
}
static int inline F_12 ( T_3 V_34 , const char * V_35 )
{
return F_2 ( L_12 , 2 , 1 , V_34 , F_3 ( V_35 ) ) ;
}
static void F_13 ( char * * V_39 , const char * V_14 )
{
char * V_13 = * V_39 ;
while ( * V_14 )
* V_13 ++ = * V_14 ++ ;
* V_13 ++ = ' ' ;
* V_39 = V_13 ;
}
static char * F_14 ( unsigned int V_40 )
{
static char V_41 [] = L_13 ;
static char V_30 [ 9 ] ;
int V_6 ;
V_30 [ 8 ] = 0 ;
V_6 = 8 ;
do {
-- V_6 ;
V_30 [ V_6 ] = V_41 [ V_40 & 0xf ] ;
V_40 >>= 4 ;
} while ( V_40 != 0 && V_6 > 0 );
return & V_30 [ V_6 ] ;
}
static int T_1 F_15 ( T_3 V_34 , const char * V_42 ,
const char * V_35 , void * V_36 , T_4 V_37 )
{
char V_43 [ 256 ] , * V_13 ;
if ( ! ( V_27 & V_44 ) )
return F_2 ( L_14 , 4 , 1 , V_34 , F_3 ( V_35 ) ,
( V_38 ) ( unsigned long ) V_36 , ( V_38 ) V_37 ) ;
V_13 = V_43 ;
F_13 ( & V_13 , L_15 ) ;
F_13 ( & V_13 , V_42 ) ;
F_13 ( & V_13 , F_14 ( ( V_38 ) ( unsigned long ) V_36 ) ) ;
F_13 ( & V_13 , F_14 ( V_37 ) ) ;
F_13 ( & V_13 , F_14 ( F_3 ( V_35 ) ) ) ;
F_13 ( & V_13 , F_14 ( strlen ( V_35 ) ) ) ;
F_13 ( & V_13 , L_16 ) ;
* V_13 = 0 ;
return F_2 ( L_17 , 1 , 1 , ( V_38 ) ( unsigned long ) V_43 ) ;
}
unsigned long F_16 ( const char * V_45 , const char * * V_46 )
{
unsigned long V_30 = 0 , V_47 = 10 , V_36 ;
if ( * V_45 == '0' ) {
V_47 = 8 ;
V_45 ++ ;
if ( toupper ( * V_45 ) == 'X' ) {
V_45 ++ ;
V_47 = 16 ;
}
}
while ( isxdigit ( * V_45 ) &&
( V_36 = isdigit ( * V_45 ) ? * V_45 - '0' : toupper ( * V_45 ) - 'A' + 10 ) < V_47 ) {
V_30 = V_30 * V_47 + V_36 ;
V_45 ++ ;
}
if ( V_46 )
* V_46 = V_45 ;
return V_30 ;
}
unsigned long F_17 ( const char * V_48 , const char * * V_49 )
{
unsigned long V_29 = F_16 ( V_48 , V_49 ) ;
int V_50 = 0 ;
if ( 'G' == * * V_49 || 'g' == * * V_49 )
V_50 = 30 ;
if ( 'M' == * * V_49 || 'm' == * * V_49 )
V_50 = 20 ;
if ( 'K' == * * V_49 || 'k' == * * V_49 )
V_50 = 10 ;
if ( V_50 ) {
V_29 <<= V_50 ;
( * V_49 ) ++ ;
}
return V_29 ;
}
static void T_1 F_18 ( void )
{
const char * V_51 ;
char * V_13 ;
int V_52 = 0 ;
V_53 [ 0 ] = 0 ;
V_13 = V_53 ;
if ( ( long ) V_15 . V_54 > 0 )
V_52 = F_11 ( V_15 . V_54 , L_18 , V_13 , V_55 - 1 ) ;
#ifdef F_19
if ( V_52 <= 0 || V_13 [ 0 ] == '\0' )
F_20 ( V_53 ,
F_19 , sizeof( V_53 ) ) ;
#endif
F_8 ( L_19 , V_53 ) ;
#ifdef F_21
V_51 = strstr ( V_53 , L_20 ) ;
if ( V_51 ) {
F_8 ( L_21 , V_51 ) ;
V_51 += 6 ;
while ( * V_51 && * V_51 == ' ' )
V_51 ++ ;
if ( ! strncmp ( V_51 , L_22 , 3 ) )
V_56 = 1 ;
else if ( ! strncmp ( V_51 , L_23 , 5 ) )
V_57 = 1 ;
}
#endif
V_51 = strstr ( V_53 , L_24 ) ;
if ( V_51 ) {
V_51 += 4 ;
V_58 = F_17 ( V_51 , ( const char * * ) & V_51 ) ;
#ifdef F_21
V_58 = F_22 ( V_58 , 0x1000000 ) ;
#endif
}
}
static int T_1 F_23 ( void )
{
T_3 V_34 ;
char type [ 64 ] ;
unsigned int V_59 ;
for ( V_34 = 0 ; F_10 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_11 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_26 ) )
continue;
V_59 = F_12 ( V_34 , L_27 ) ;
if ( V_59 == V_10 )
break;
V_59 >>= 2 ;
F_24 ( L_28 , ( unsigned long ) V_59 ) ;
if ( V_59 < 1 || V_59 > 64 ) {
F_8 ( L_29 ,
( unsigned long ) V_59 ) ;
return 1 ;
}
return V_59 ;
}
F_24 ( L_30 ) ;
return 1 ;
}
static void T_1 F_25 ( void )
{
T_5 V_60 , V_61 ;
V_8 V_29 ;
V_38 * V_62 ;
V_61 = F_2 ( L_31 , 1 , 1 , F_3 ( L_32 ) ) ;
if ( V_61 != 0 ) {
V_62 = ( V_38 * ) & V_63 [ V_64 ] ;
if ( * V_62 != V_65 ) {
F_8 ( L_33
L_34 ,
* V_62 ) ;
} else {
* V_62 = F_26 ( V_65 , F_23 () ) ;
F_8 ( L_35 ,
* V_62 , V_65 ) ;
}
F_8 ( L_36 ) ;
if ( F_4 ( L_4 , 3 , 2 , & V_29 ,
F_3 ( L_37 ) ,
V_61 ,
F_3 ( V_63 ) ) == 0 ) {
if ( V_29 )
F_8 ( L_38
L_39 ) ;
F_2 ( L_40 , 1 , 0 , V_61 ) ;
F_8 ( L_41 ) ;
return;
}
F_2 ( L_40 , 1 , 0 , V_61 ) ;
F_8 ( L_42 ) ;
}
V_60 = F_2 ( L_31 , 1 , 1 , F_3 ( L_43 ) ) ;
if ( V_60 == 0 ) {
F_8 ( L_44 ) ;
return;
}
F_2 ( L_4 , 3 , 1 , F_3 ( L_45 ) ,
V_60 , F_3 ( & V_66 ) ) ;
F_2 ( L_40 , 1 , 0 , V_60 ) ;
}
static unsigned long T_1 F_27 ( unsigned long V_19 , unsigned long V_26 )
{
unsigned long V_47 = V_67 ;
unsigned long V_68 = 0 ;
if ( V_26 )
V_47 = F_28 ( V_47 , V_26 ) ;
F_24 ( L_46 , V_19 , V_26 ) ;
if ( V_69 == 0 )
F_29 ( L_47 ) ;
if ( V_26 )
V_47 = F_28 ( V_67 , V_26 ) ;
else
V_47 = V_67 ;
for(; ( V_47 + V_19 ) <= V_70 ;
V_47 = F_28 ( V_47 + 0x100000 , V_26 ) ) {
F_24 ( L_48 , V_47 ) ;
V_68 = ( unsigned long ) F_9 ( V_47 , V_19 , 0 ) ;
if ( V_68 != V_10 && V_68 != 0 )
break;
V_68 = 0 ;
if ( V_26 == 0 )
break;
}
if ( V_68 == 0 )
return 0 ;
V_67 = V_68 + V_19 ;
F_24 ( L_49 , V_68 ) ;
F_24 ( L_50 , V_67 ) ;
F_24 ( L_51 , V_70 ) ;
F_24 ( L_52 , V_71 ) ;
F_24 ( L_53 , V_72 ) ;
F_24 ( L_54 , V_69 ) ;
return V_68 ;
}
static unsigned long T_1 F_30 ( unsigned long V_19 , unsigned long V_26 ,
int V_73 )
{
unsigned long V_47 , V_68 = 0 ;
F_24 ( L_55 , V_19 , V_26 ,
V_73 ? L_56 : L_57 ) ;
if ( V_69 == 0 )
F_29 ( L_58 ) ;
if ( V_73 ) {
V_68 = F_31 ( V_71 - V_19 , V_26 ) ;
if ( V_68 <= V_67 )
return 0 ;
if ( V_68 < V_72 ) {
if ( V_70 == V_72 )
V_70 = V_72 = V_68 ;
else
return 0 ;
}
V_71 = V_68 ;
goto V_74;
}
V_47 = F_31 ( V_70 - V_19 , V_26 ) ;
for (; V_47 > V_67 ;
V_47 = F_31 ( V_47 - 0x100000 , V_26 ) ) {
F_24 ( L_48 , V_47 ) ;
V_68 = ( unsigned long ) F_9 ( V_47 , V_19 , 0 ) ;
if ( V_68 != V_10 && V_68 != 0 )
break;
V_68 = 0 ;
}
if ( V_68 == 0 )
return 0 ;
V_70 = V_68 ;
V_74:
F_24 ( L_49 , V_68 ) ;
F_24 ( L_50 , V_67 ) ;
F_24 ( L_51 , V_70 ) ;
F_24 ( L_52 , V_71 ) ;
F_24 ( L_53 , V_72 ) ;
F_24 ( L_54 , V_69 ) ;
return V_68 ;
}
static unsigned long T_1 F_32 ( int V_22 , T_6 * * V_75 )
{
T_6 * V_13 = * V_75 ;
unsigned long V_76 = 0 ;
while ( V_22 > sizeof( unsigned long ) / 4 ) {
V_13 ++ ;
V_22 -- ;
}
V_76 = * V_13 ++ ;
#ifdef F_21
if ( V_22 > 1 ) {
V_76 <<= 32 ;
V_76 |= * ( V_13 ++ ) ;
}
#endif
* V_75 = V_13 ;
return V_76 ;
}
static void T_1 F_33 ( T_7 V_47 , T_7 V_19 )
{
T_7 V_77 = V_47 + V_19 ;
unsigned long V_78 = V_79 ;
if ( V_19 == 0 )
return;
V_47 = F_31 ( V_47 , V_80 ) ;
V_77 = F_28 ( V_77 , V_80 ) ;
V_19 = V_77 - V_47 ;
if ( V_78 >= ( V_81 - 1 ) )
F_29 ( L_59 ) ;
V_82 [ V_78 ] . V_47 = V_47 ;
V_82 [ V_78 ] . V_19 = V_19 ;
V_79 = V_78 + 1 ;
}
static void T_1 F_34 ( void )
{
T_3 V_34 ;
char * V_83 , type [ 64 ] ;
unsigned int V_59 ;
T_6 * V_13 , * V_46 ;
V_38 V_84 , V_85 ;
V_84 = 2 ;
F_11 ( V_15 . V_61 , L_60 , & V_84 , sizeof( V_84 ) ) ;
V_85 = 1 ;
F_11 ( V_15 . V_61 , L_61 , & V_85 , sizeof( V_85 ) ) ;
F_24 ( L_62 , ( unsigned long ) V_84 ) ;
F_24 ( L_63 , ( unsigned long ) V_85 ) ;
F_24 ( L_64 ) ;
V_83 = V_86 ;
for ( V_34 = 0 ; F_10 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_11 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( type [ 0 ] == 0 ) {
F_11 ( V_34 , L_65 , type , sizeof( type ) ) ;
}
if ( strcmp ( type , L_66 ) )
continue;
V_59 = F_11 ( V_34 , L_67 , V_87 , sizeof( V_87 ) ) ;
if ( V_59 > sizeof( V_87 ) ) {
F_8 ( L_68 ) ;
V_59 = sizeof( V_87 ) ;
}
V_13 = V_87 ;
V_46 = V_13 + ( V_59 / sizeof( T_6 ) ) ;
#ifdef F_35
memset ( V_83 , 0 , V_88 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_83 , V_88 - 1 ) ;
F_24 ( L_70 , V_83 ) ;
#endif
while ( ( V_46 - V_13 ) >= ( V_84 + V_85 ) ) {
unsigned long V_47 , V_19 ;
V_47 = F_32 ( V_84 , & V_13 ) ;
V_19 = F_32 ( V_85 , & V_13 ) ;
if ( V_19 == 0 )
continue;
F_24 ( L_71 , V_47 , V_19 ) ;
if ( V_47 == 0 && ( V_89 & V_90 ) )
V_72 = V_19 ;
if ( ( V_47 + V_19 ) > V_69 )
V_69 = V_47 + V_19 ;
}
}
V_67 = F_36 ( ( unsigned long ) & V_91 + 0x4000 ) ;
V_71 = V_69 ;
if ( V_58 ) {
if ( V_58 <= V_67 ) {
F_8 ( L_72 ,
V_58 ) ;
V_58 = 0 ;
} else if ( V_58 >= V_69 ) {
F_8 ( L_73 ,
V_58 ) ;
V_58 = 0 ;
} else {
V_69 = V_58 ;
V_72 = F_37 ( V_72 , V_58 ) ;
}
}
if ( ! V_72 )
V_72 = V_69 ;
V_72 = F_37 ( 0x30000000ul , V_72 ) ;
V_70 = V_72 ;
V_71 = V_69 ;
if ( V_92 &&
V_92 < V_72 &&
V_93 > V_67 )
V_67 = F_36 ( V_93 ) ;
F_8 ( L_74 ) ;
F_8 ( L_75 , V_58 ) ;
F_8 ( L_50 , V_67 ) ;
F_8 ( L_51 , V_70 ) ;
F_8 ( L_52 , V_71 ) ;
F_8 ( L_53 , V_72 ) ;
F_8 ( L_54 , V_69 ) ;
}
static void T_1 F_38 ( void )
{
T_5 V_16 ;
if ( F_11 ( V_15 . V_54 , L_76 , & V_16 , sizeof( V_16 ) ) > 0 )
F_2 ( L_40 , 1 , 0 , V_16 ) ;
}
static void T_1 F_39 ( void )
{
long V_94 ;
if ( F_40 ( F_2 ( L_77 , 1 , 1 ,
F_3 ( L_78 ) ) ) ) {
F_8 ( L_79 ) ;
return;
}
F_8 ( L_80 ) ;
V_94 = F_41 ( & V_95 ,
& V_96 ) ;
F_24 ( L_81 , V_94 ) ;
if ( V_94 != 0 ) {
F_8 ( L_82 ) ;
return;
}
V_89 = V_97 ;
F_8 ( L_83 ) ;
F_24 ( L_84 , V_95 ) ;
F_24 ( L_85 , V_96 ) ;
if ( V_96 < 0x10000 )
V_96 = 0x10000 ;
}
static int F_42 ( int V_98 , int V_4 , int V_5 , int * V_99 , ... )
{
struct V_100 V_100 ;
T_2 V_7 ;
int V_6 ;
V_100 . V_98 = V_98 ;
V_100 . V_4 = V_4 ;
V_100 . V_5 = V_5 ;
V_100 . V_11 = ( V_101 * ) & ( V_100 . args [ V_4 ] ) ;
va_start ( V_7 , V_99 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; ++ V_6 )
V_100 . args [ V_6 ] = va_arg ( V_7 , V_101 ) ;
va_end ( V_7 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; ++ V_6 )
V_100 . V_11 [ V_6 ] = 0 ;
F_43 ( & V_100 , V_102 ,
V_103 ) ;
if ( V_5 > 1 && V_99 != NULL )
for ( V_6 = 0 ; V_6 < V_5 - 1 ; ++ V_6 )
V_99 [ V_6 ] = V_100 . V_11 [ V_6 + 1 ] ;
return ( V_5 > 0 ) ? V_100 . V_11 [ 0 ] : 0 ;
}
static void T_1 F_44 ( void )
{
int V_6 , V_78 , V_104 , V_94 ;
long V_105 ;
T_3 V_34 ;
char type [ 64 ] ;
V_38 V_106 [ 8 ] ;
void * V_2 = ( unsigned long * ) & V_107 ;
struct V_108 * V_109 = & V_108 ;
F_24 ( L_86 ) ;
F_24 ( L_87 , V_2 ) ;
F_24 ( L_88 , V_109 ) ;
V_109 -> V_110 = - 1 ;
V_109 -> V_111 = 0 ;
for ( V_34 = 0 ; F_10 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_11 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_26 ) != 0 )
continue;
if ( F_11 ( V_34 , L_89 , type , sizeof( type ) ) > 0 )
if ( strcmp ( type , L_90 ) != 0 )
continue;
V_78 = F_11 ( V_34 , L_27 , V_106 ,
sizeof( V_106 ) ) ;
if ( V_78 == V_10 )
break;
V_78 >>= 2 ;
for ( V_6 = 0 ; V_6 < V_78 ; V_6 ++ ) {
V_104 = V_106 [ V_6 ] ;
F_24 ( L_91 , V_104 ) ;
if ( V_104 == V_15 . V_104 ) {
F_24 ( L_92 ) ;
continue;
}
F_24 ( L_93 ) ;
V_109 -> V_110 = - 1 ;
V_94 = F_42 ( V_112 , 3 , 1 ,
NULL , V_104 , V_2 , V_109 ) ;
F_24 ( L_94 , V_94 ) ;
for ( V_105 = 0 ; V_105 < 100000000 && V_109 -> V_110 == - 1 ; V_105 ++ ) {
F_45 () ;
F_46 () ;
}
F_47 () ;
if ( V_109 -> V_110 != - 1 )
F_24 ( L_95 , V_109 -> V_110 ) ;
else
F_24 ( L_96 ) ;
}
}
F_24 ( L_97 ) ;
}
static void T_1 F_48 ( void )
{
struct V_108 * V_109 = & V_108 ;
struct V_113 * args = & V_109 -> args ;
T_7 V_26 = V_96 ;
T_7 V_114 , V_115 ;
args -> V_116 = ( T_7 ) V_117 ;
args -> V_118 = V_91 - V_117 ;
args -> V_119 = 0 ;
args -> V_120 = 0x60 ;
V_114 = F_28 ( args -> V_118 , V_26 ) ;
if ( V_92 != 0 ) {
args -> V_121 = V_92 ;
args -> V_122 = V_93 - args -> V_121 ;
args -> V_123 = V_114 ;
V_114 = F_28 ( args -> V_123 + args -> V_122 , V_26 ) ;
}
V_115 = F_31 ( 0x40000000 - V_95 , V_26 ) ;
if ( V_115 < V_114 )
V_115 = V_114 ;
args -> V_124 = V_115 ;
F_20 ( V_125 , V_53 ,
V_55 ) ;
F_24 ( L_98 , args -> V_116 ) ;
F_24 ( L_99 , args -> V_118 ) ;
F_24 ( L_100 , args -> V_119 ) ;
F_24 ( L_101 , args -> V_120 ) ;
F_24 ( L_102 , args -> V_124 ) ;
F_24 ( L_103 , args -> V_121 ) ;
F_24 ( L_104 , args -> V_122 ) ;
F_24 ( L_105 , args -> V_123 ) ;
F_8 ( L_106 ) ;
F_38 () ;
F_46 () ;
V_109 -> V_111 = 1 ;
for (; ; )
F_49 ( args ) ;
}
static void T_1 F_50 ( void )
{
T_3 V_126 ;
T_5 V_127 ;
T_7 V_47 , V_2 ;
T_7 V_19 = 0 , V_26 = 0x10000 ;
V_38 V_11 [ 2 ] ;
F_24 ( L_107 ) ;
V_126 = F_2 ( L_77 , 1 , 1 , F_3 ( L_108 ) ) ;
F_24 ( L_109 , V_126 ) ;
if ( ! F_40 ( V_126 ) )
return;
F_11 ( V_126 , L_110 , & V_19 , sizeof( V_19 ) ) ;
if ( V_19 == 0 )
return;
F_11 ( V_126 , L_111 , & V_26 ,
sizeof( V_26 ) ) ;
V_47 = F_30 ( V_19 , V_26 , 0 ) ;
if ( V_47 == 0 ) {
F_8 ( L_112 ) ;
return;
}
V_127 = F_2 ( L_31 , 1 , 1 , F_3 ( L_108 ) ) ;
if ( ! F_51 ( V_127 ) ) {
F_8 ( L_113 , V_127 ) ;
return;
}
F_8 ( L_114 , V_47 ) ;
if ( F_4 ( L_4 , 4 , 3 , V_11 ,
F_3 ( L_115 ) ,
V_127 ,
V_47 >> 32 , V_47 & 0xffffffff ) != 0
|| ( V_11 [ 0 ] == 0 && V_11 [ 1 ] == 0 ) ) {
F_8 ( L_116 ) ;
return;
}
V_2 = ( ( ( T_7 ) V_11 [ 0 ] ) << 32 ) | V_11 [ 1 ] ;
F_8 ( L_41 ) ;
F_33 ( V_47 , V_19 ) ;
F_24 ( L_117 , V_47 ) ;
F_24 ( L_118 , V_26 ) ;
F_24 ( L_119 , V_2 ) ;
F_24 ( L_120 , ( long ) V_19 ) ;
F_15 ( V_126 , L_108 , L_121 ,
& V_47 , sizeof( V_47 ) ) ;
F_15 ( V_126 , L_108 , L_122 ,
& V_2 , sizeof( V_2 ) ) ;
#ifdef F_52
V_128 = V_47 ;
V_129 = V_2 ;
#endif
F_24 ( L_123 ) ;
}
static void T_1 F_53 ( void )
{
T_3 V_130 ;
T_5 V_131 ;
V_38 V_47 , V_2 = 0 ;
V_38 V_19 = 0 ;
F_24 ( L_124 ) ;
V_130 = F_2 ( L_77 , 1 , 1 , F_3 ( L_125 ) ) ;
F_24 ( L_126 , V_130 ) ;
if ( ! F_40 ( V_130 ) )
return;
F_11 ( V_130 , L_127 , & V_19 , sizeof( V_19 ) ) ;
if ( V_19 == 0 )
return;
V_47 = F_30 ( V_19 , V_80 , 0 ) ;
if ( V_47 == 0 )
F_29 ( L_128 ) ;
V_131 = F_2 ( L_31 , 1 , 1 , F_3 ( L_125 ) ) ;
if ( ! F_51 ( V_131 ) ) {
F_8 ( L_129 , V_131 ) ;
return;
}
F_8 ( L_130 , V_47 ) ;
if ( F_4 ( L_4 , 3 , 2 , & V_2 ,
F_3 ( L_131 ) ,
V_131 , V_47 ) != 0
|| V_2 == 0 ) {
F_8 ( L_116 ) ;
return;
}
F_8 ( L_41 ) ;
F_33 ( V_47 , V_19 ) ;
F_15 ( V_130 , L_125 , L_132 ,
& V_47 , sizeof( V_47 ) ) ;
F_15 ( V_130 , L_125 , L_133 ,
& V_2 , sizeof( V_2 ) ) ;
#ifdef F_54
V_102 = V_47 ;
V_103 = V_2 ;
F_11 ( V_130 , L_134 , & V_112 , 4 ) ;
#endif
F_24 ( L_135 , V_47 ) ;
F_24 ( L_136 , V_2 ) ;
F_24 ( L_137 , ( long ) V_19 ) ;
F_24 ( L_138 ) ;
}
static void T_1 F_55 ( void )
{
T_3 V_132 ;
T_5 V_133 ;
V_38 V_2 = 0 , V_19 = 0 ;
T_7 V_47 ;
F_24 ( L_139 ) ;
V_132 = F_2 ( L_77 , 1 , 1 , F_3 ( L_140 ) ) ;
F_24 ( L_141 , V_132 ) ;
if ( ! F_40 ( V_132 ) )
return;
V_133 = F_2 ( L_31 , 1 , 1 , F_3 ( L_140 ) ) ;
if ( ! F_51 ( V_133 ) ) {
F_8 ( L_142 , V_133 ) ;
return;
}
if ( F_4 ( L_4 , 2 , 2 , & V_19 ,
F_3 ( L_143 ) ,
V_133 ) != 0 || V_19 == 0 ) {
F_8 ( L_144 ) ;
return;
}
V_47 = F_30 ( V_19 , V_80 , 0 ) ;
if ( V_47 == 0 )
F_29 ( L_145 ) ;
F_8 ( L_146 , V_47 ) ;
if ( F_4 ( L_4 , 4 , 2 , & V_2 ,
F_3 ( L_147 ) ,
V_133 , V_19 , V_47 ) != 0 || V_2 == 0 ) {
F_8 ( L_148 ) ;
return;
}
F_8 ( L_41 ) ;
F_33 ( V_47 , V_19 ) ;
F_15 ( V_132 , L_140 , L_149 ,
& V_47 , sizeof( V_47 ) ) ;
F_15 ( V_132 , L_140 , L_150 ,
& V_19 , sizeof( V_19 ) ) ;
F_24 ( L_151 , V_47 ) ;
F_24 ( L_152 , ( long ) V_19 ) ;
F_24 ( L_153 ) ;
}
static void T_1 F_56 ( void )
{
T_3 V_34 ;
T_5 V_134 ;
char V_135 [ 64 ] , type [ 64 ] , V_136 [ 64 ] ;
char * V_83 = V_86 ;
T_7 V_47 , V_26 ;
V_38 V_137 , V_138 ;
T_7 V_139 , * V_140 ;
T_7 V_141 , V_142 ;
T_7 V_6 ;
if ( V_56 )
return;
F_24 ( L_154 ) ;
V_141 = V_71 ;
V_142 = V_141 ;
for ( V_34 = 0 ; F_10 ( & V_34 ) ; ) {
V_135 [ 0 ] = 0 ;
type [ 0 ] = 0 ;
V_136 [ 0 ] = 0 ;
F_11 ( V_34 , L_155 ,
V_135 , sizeof( V_135 ) ) ;
F_11 ( V_34 , L_25 , type , sizeof( type ) ) ;
F_11 ( V_34 , L_156 , V_136 , sizeof( V_136 ) ) ;
if ( ( type [ 0 ] == 0 ) || ( strstr ( type , L_157 ) == NULL ) )
continue;
if ( V_135 [ 0 ] != 0 ) {
if ( ( strstr ( V_135 , L_158 ) == NULL ) &&
( strstr ( V_135 , L_159 ) == NULL ) &&
( strstr ( V_135 , L_160 ) == NULL ) )
continue;
} else if ( V_136 [ 0 ] != 0 ) {
if ( ( strstr ( V_136 , L_161 ) == NULL ) &&
( strstr ( V_136 , L_162 ) == NULL ) &&
( strstr ( V_136 , L_163 ) == NULL ) )
continue;
}
if ( F_11 ( V_34 , L_164 , & V_137 ,
sizeof( V_137 ) ) == V_10 )
V_137 = 0 ;
if ( F_11 ( V_34 , L_165 , & V_138 ,
sizeof( V_138 ) ) == V_10 )
V_138 = 4UL << 20 ;
if ( F_57 ( V_143 ) || F_57 ( V_144 ) )
V_138 = 8UL << 20 ;
else
V_138 = 4UL << 20 ;
V_26 = F_58 ( V_137 , V_138 ) ;
V_47 = F_30 ( V_138 , V_26 , 1 ) ;
if ( V_47 == 0 )
F_29 ( L_166 ) ;
if ( V_47 < V_142 )
V_142 = V_47 ;
memset ( V_83 , 0 , V_88 ) ;
if ( F_2 ( L_69 , 3 , 1 , V_34 ,
V_83 , V_88 - 1 ) == V_10 ) {
F_8 ( L_167 ) ;
}
F_15 ( V_34 , V_83 , L_168 , & V_47 , sizeof( V_47 ) ) ;
F_15 ( V_34 , V_83 , L_169 , & V_138 , sizeof( V_138 ) ) ;
F_24 ( L_170 , V_83 ) ;
F_24 ( L_171 , V_34 ) ;
F_24 ( L_172 , V_47 ) ;
F_24 ( L_173 , V_138 ) ;
V_140 = ( T_7 * ) V_47 ;
for ( V_6 = 0 ; V_6 < ( V_138 >> 3 ) ; V_140 ++ , V_6 ++ ) {
V_139 = ( V_6 << V_145 ) ;
V_139 |= 0x3 ;
* V_140 = V_139 ;
}
F_8 ( L_174 , V_83 ) ;
V_134 = F_2 ( L_31 , 1 , 1 , V_83 ) ;
if ( V_134 == 0 )
F_8 ( L_175 ) ;
else
F_8 ( L_176 ) ;
F_2 ( L_4 , 6 , 0 , F_3 ( L_177 ) ,
V_134 , - 1 , V_138 ,
( V_38 ) V_47 , ( V_38 ) ( V_47 >> 32 ) ) ;
F_2 ( L_40 , 1 , 0 , V_134 ) ;
}
F_33 ( V_142 , V_141 - V_142 ) ;
V_146 = V_142 ;
V_147 = V_141 ;
F_24 ( L_178 ) ;
}
static void T_1 F_59 ( void )
{
unsigned long V_6 ;
unsigned int V_148 ;
T_3 V_34 ;
char type [ 64 ] ;
unsigned long * V_149
= ( void * ) F_60 ( V_150 ) ;
unsigned long * V_151
= ( void * ) F_60 ( V_152 ) ;
unsigned long V_153 = F_60 ( V_154 ) ;
F_24 ( L_179 ) ;
F_24 ( L_180 , ( unsigned long ) V_149 ) ;
F_24 ( L_181 , * V_149 ) ;
F_24 ( L_182 ,
( unsigned long ) V_151 ) ;
F_24 ( L_183 , * V_151 ) ;
F_24 ( L_184 , V_153 ) ;
* V_149 = 0 ;
for ( V_34 = 0 ; F_10 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_11 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_26 ) != 0 )
continue;
if ( F_11 ( V_34 , L_89 , type , sizeof( type ) ) > 0 )
if ( strcmp ( type , L_90 ) != 0 )
continue;
V_148 = - 1 ;
F_11 ( V_34 , L_67 , & V_148 , sizeof( V_148 ) ) ;
F_24 ( L_185 , V_148 ) ;
* V_151 = ( unsigned long ) - 1 ;
if ( V_148 != V_15 . V_104 ) {
F_8 ( L_186 , V_148 ) ;
F_2 ( L_134 , 3 , 0 , V_34 ,
V_153 , V_148 ) ;
for ( V_6 = 0 ; ( V_6 < 100000000 ) &&
( * V_151 == ( ( unsigned long ) - 1 ) ) ; V_6 ++ )
F_46 () ;
if ( * V_151 == V_148 )
F_8 ( L_187 ) ;
else
F_8 ( L_188 , * V_151 ) ;
}
#ifdef F_61
else
F_8 ( L_189 , V_148 ) ;
#endif
}
F_24 ( L_190 ) ;
}
static void T_1 F_62 ( unsigned long V_155 )
{
V_9 = V_155 ;
V_15 . V_54 = F_2 ( L_77 , 1 , 1 , F_3 ( L_191 ) ) ;
if ( ! F_40 ( V_15 . V_54 ) )
F_29 ( L_192 ) ;
V_15 . V_61 = F_2 ( L_77 , 1 , 1 , F_3 ( L_32 ) ) ;
if ( ! F_40 ( V_15 . V_61 ) )
F_29 ( L_193 ) ;
V_15 . V_32 = 0 ;
}
static void T_1 F_63 ( void )
{
T_3 V_156 ;
char V_157 [ 64 ] ;
V_156 = F_2 ( L_77 , 1 , 1 , F_3 ( L_194 ) ) ;
if ( ! F_40 ( V_156 ) )
return;
if ( F_11 ( V_156 , L_156 , V_157 , sizeof( V_157 ) ) <= 0 )
return;
V_157 [ sizeof( V_157 ) - 1 ] = 0 ;
if ( strcmp ( V_157 , L_195 ) == 0 )
V_158 = V_28 ;
else if ( strncmp ( V_157 , L_196 , 12 ) == 0 ) {
V_158 = V_28 | V_44 ;
F_2 ( L_17 , 1 , 1 , L_197 ) ;
} else
return;
V_15 . V_31 = F_2 ( L_31 , 1 , 1 , F_3 ( L_198 ) ) ;
F_11 ( V_15 . V_54 , L_199 , & V_15 . V_32 ,
sizeof( V_15 . V_32 ) ) ;
if ( ! F_51 ( V_15 . V_31 ) || ! F_51 ( V_15 . V_32 ) )
V_158 &= ~ V_28 ;
}
static void T_1 F_64 ( void )
{
char * V_83 = V_159 ;
char type [ 16 ] ;
V_38 V_16 ;
if ( F_11 ( V_15 . V_54 , L_200 , & V_16 , sizeof( V_16 ) ) <= 0 )
F_29 ( L_201 ) ;
V_15 . stdout = V_16 ;
memset ( V_83 , 0 , 256 ) ;
F_2 ( L_202 , 3 , 1 , V_15 . stdout , V_83 , 255 ) ;
V_16 = F_2 ( L_203 , 1 , 1 , V_15 . stdout ) ;
F_15 ( V_15 . V_54 , L_191 , L_204 ,
& V_16 , sizeof( V_16 ) ) ;
F_8 ( L_205 , V_159 ) ;
F_15 ( V_15 . V_54 , L_191 , L_206 ,
V_83 , strlen ( V_83 ) + 1 ) ;
memset ( type , 0 , sizeof( type ) ) ;
F_11 ( V_16 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_207 ) == 0 )
F_15 ( V_16 , V_83 , L_208 , NULL , 0 ) ;
}
static int T_1 F_65 ( void )
{
char V_160 [ 256 ] ;
int V_161 , V_6 = 0 ;
#ifdef F_21
T_3 V_162 ;
int V_40 ;
#endif
V_161 = F_11 ( V_15 . V_61 , L_155 ,
V_160 , sizeof( V_160 ) - 1 ) ;
if ( V_161 > 0 ) {
V_160 [ V_161 ] = 0 ;
while ( V_6 < V_161 ) {
char * V_13 = & V_160 [ V_6 ] ;
int V_163 = strlen ( V_13 ) ;
if ( V_163 == 0 )
break;
if ( strstr ( V_13 , L_209 ) ||
strstr ( V_13 , L_210 ) )
return V_164 ;
#ifdef F_21
if ( strstr ( V_13 , L_211 ) ||
strstr ( V_13 , L_212 ) )
return V_165 ;
#endif
V_6 += V_163 + 1 ;
}
}
#ifdef F_21
if ( F_40 ( F_2 ( L_77 , 1 , 1 , F_3 ( L_108 ) ) ) )
return V_97 ;
V_161 = F_11 ( V_15 . V_61 , L_25 ,
V_160 , sizeof( V_160 ) - 1 ) ;
if ( V_161 <= 0 )
return V_165 ;
if ( strcmp ( V_160 , L_213 ) )
return V_165 ;
V_162 = F_2 ( L_77 , 1 , 1 , F_3 ( L_125 ) ) ;
if ( ! F_40 ( V_162 ) )
return V_165 ;
V_40 = F_12 ( V_162 , L_214 ) ;
if ( V_40 != V_10 ) {
F_24 ( L_215 ) ;
return V_166 ;
}
return V_167 ;
#else
return V_165 ;
#endif
}
static int T_1 F_66 ( T_5 V_168 , int V_6 , int V_76 , int V_169 , int V_170 )
{
return F_2 ( L_4 , 6 , 1 , F_3 ( L_216 ) , V_168 , V_6 , V_170 , V_169 , V_76 ) ;
}
static void T_1 F_67 ( void )
{
char type [ 16 ] , * V_83 ;
T_3 V_34 ;
T_5 V_168 ;
int V_6 ;
static unsigned char V_171 [] = {
0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0xaa ,
0x00 , 0xaa , 0x00 ,
0x00 , 0xaa , 0xaa ,
0xaa , 0x00 , 0x00 ,
0xaa , 0x00 , 0xaa ,
0xaa , 0xaa , 0x00 ,
0xaa , 0xaa , 0xaa ,
0x55 , 0x55 , 0x55 ,
0x55 , 0x55 , 0xff ,
0x55 , 0xff , 0x55 ,
0x55 , 0xff , 0xff ,
0xff , 0x55 , 0x55 ,
0xff , 0x55 , 0xff ,
0xff , 0xff , 0x55 ,
0xff , 0xff , 0xff
} ;
const unsigned char * V_172 ;
F_24 ( L_217 ) ;
for ( V_34 = 0 ; F_10 ( & V_34 ) ; ) {
memset ( type , 0 , sizeof( type ) ) ;
F_11 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_207 ) != 0 )
continue;
V_83 = V_86 ;
memset ( V_83 , 0 , V_88 ) ;
if ( F_2 ( L_69 , 3 , 1 , V_34 , V_83 ,
V_88 - 10 ) == V_10 )
continue;
F_8 ( L_218 , V_83 ) ;
V_168 = F_2 ( L_31 , 1 , 1 , V_83 ) ;
if ( V_168 == 0 ) {
F_8 ( L_219 ) ;
continue;
}
F_8 ( L_187 ) ;
F_15 ( V_34 , V_83 , L_220 , NULL , 0 ) ;
V_172 = V_171 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ , V_172 += 3 )
if ( F_66 ( V_168 , V_6 , V_172 [ 0 ] , V_172 [ 1 ] ,
V_172 [ 2 ] ) != 0 )
break;
#ifdef F_68
V_172 = F_69 ( V_173 . V_172 ) ;
for ( V_6 = 0 ; V_6 < V_173 . V_174 ; V_6 ++ , V_172 += 3 )
if ( F_66 ( V_168 , V_6 + 32 , V_172 [ 0 ] , V_172 [ 1 ] ,
V_172 [ 2 ] ) != 0 )
break;
#endif
}
}
static void T_1 * F_70 ( unsigned long * V_175 , unsigned long * V_176 ,
unsigned long V_177 , unsigned long V_26 )
{
void * V_29 ;
* V_175 = F_71 ( * V_175 , V_26 ) ;
while ( ( * V_175 + V_177 ) > * V_176 ) {
unsigned long V_178 , V_179 ;
F_24 ( L_221 ,
V_67 ) ;
V_178 = V_70 - V_67 ;
if ( V_178 > V_180 )
V_178 = V_180 ;
if ( V_178 < V_80 )
F_29 ( L_222
L_223 ) ;
V_179 = F_27 ( V_178 , 0 ) ;
if ( V_179 == 0 )
F_29 ( L_222
L_224 ) ;
* V_176 = V_179 + V_178 ;
}
V_29 = ( void * ) * V_175 ;
* V_175 += V_177 ;
return V_29 ;
}
static unsigned long T_1 F_72 ( char * V_39 )
{
char * V_22 , * V_181 ;
V_22 = V_181 = ( char * ) V_182 ;
V_22 += 4 ;
while ( V_22 < ( char * ) V_183 ) {
if ( strcmp ( V_22 , V_39 ) == 0 )
return V_22 - V_181 ;
V_22 += strlen ( V_22 ) + 1 ;
}
return 0 ;
}
static void T_1 F_73 ( T_3 V_34 ,
unsigned long * V_175 ,
unsigned long * V_176 )
{
char * V_184 , * V_185 , * V_186 ;
unsigned long V_187 ;
T_3 V_188 ;
V_186 = ( char * ) V_182 ;
V_184 = L_225 ;
for (; ; ) {
V_185 = F_70 ( V_175 , V_176 , V_189 , 1 ) ;
if ( F_2 ( L_226 , 3 , 1 , V_34 , V_184 , V_185 ) != 1 ) {
* V_175 = ( unsigned long ) V_185 ;
break;
}
if ( strcmp ( V_185 , L_65 ) == 0 ) {
* V_175 = ( unsigned long ) V_185 ;
V_184 = L_65 ;
continue;
}
V_187 = F_72 ( V_185 ) ;
if ( V_187 != 0 ) {
* V_175 = ( unsigned long ) V_185 ;
V_185 = V_186 + V_187 ;
} else {
* V_175 = ( unsigned long ) V_185 + strlen ( V_185 ) + 1 ;
V_183 = * V_175 ;
}
V_184 = V_185 ;
}
V_188 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_188 != 0 ) {
F_73 ( V_188 , V_175 , V_176 ) ;
V_188 = F_2 ( L_9 , 1 , 1 , V_188 ) ;
}
}
static void T_1 F_74 ( T_3 V_34 , unsigned long * V_175 ,
unsigned long * V_176 )
{
T_3 V_188 ;
char * V_185 , * V_184 , * V_186 , * V_13 , * V_190 , * V_191 , * V_83 ;
unsigned long V_187 ;
unsigned char * V_192 ;
static char V_35 [ V_189 ] ;
int V_52 , V_178 , V_193 = 0 ;
F_75 ( V_194 , V_175 , V_176 ) ;
V_185 = ( char * ) * V_175 ;
V_178 = * V_176 - * V_175 ;
if ( V_178 > 255 )
V_178 = 255 ;
V_52 = F_2 ( L_69 , 3 , 1 , V_34 , V_185 , V_178 ) ;
if ( V_52 >= 0 ) {
if ( V_52 >= V_178 ) {
if ( V_52 >= * V_176 - * V_175 )
V_185 = F_70 ( V_175 , V_176 , V_52 + 1 , 1 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_185 , V_52 ) ;
}
V_185 [ V_52 ] = '\0' ;
for ( V_191 = V_13 = V_185 , V_190 = V_185 + V_52 ; V_13 < V_190 ; V_13 ++ ) {
if ( * V_13 == '/' )
V_191 = V_185 ;
else if ( * V_13 != 0 )
* V_191 ++ = * V_13 ;
}
* V_191 = 0 ;
* V_175 = F_71 ( ( unsigned long ) V_191 + 1 , 4 ) ;
}
V_83 = V_86 ;
memset ( V_83 , 0 , V_88 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_83 , V_88 - 1 ) ;
V_184 = L_225 ;
V_186 = ( char * ) V_182 ;
for (; ; ) {
if ( F_2 ( L_226 , 3 , 1 , V_34 , V_184 ,
V_35 ) != 1 )
break;
if ( strcmp ( V_35 , L_65 ) == 0 ) {
V_184 = L_65 ;
continue;
}
V_187 = F_72 ( V_35 ) ;
if ( V_187 == 0 ) {
F_8 ( L_227
L_228 , V_35 , V_83 ) ;
break;
}
V_184 = V_186 + V_187 ;
V_52 = F_2 ( L_12 , 2 , 1 , V_34 , V_35 ) ;
if ( V_52 == V_10 )
continue;
F_75 ( V_195 , V_175 , V_176 ) ;
F_75 ( V_52 , V_175 , V_176 ) ;
F_75 ( V_187 , V_175 , V_176 ) ;
V_192 = F_70 ( V_175 , V_176 , V_52 , 4 ) ;
F_2 ( L_11 , 4 , 1 , V_34 , V_35 , V_192 , V_52 ) ;
* V_175 = F_71 ( * V_175 , 4 ) ;
if ( ! strcmp ( V_35 , L_229 ) )
V_193 = 1 ;
}
if ( ! V_193 ) {
V_187 = F_72 ( L_230 ) ;
if ( V_187 == 0 )
F_8 ( L_227
L_231 , V_83 ) ;
else {
F_75 ( V_195 , V_175 , V_176 ) ;
F_75 ( 4 , V_175 , V_176 ) ;
F_75 ( V_187 , V_175 , V_176 ) ;
V_192 = F_70 ( V_175 , V_176 , 4 , 4 ) ;
* ( V_38 * ) V_192 = V_34 ;
}
}
V_188 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_188 != 0 ) {
F_74 ( V_188 , V_175 , V_176 ) ;
V_188 = F_2 ( L_9 , 1 , 1 , V_188 ) ;
}
F_75 ( V_196 , V_175 , V_176 ) ;
}
static void T_1 F_76 ( void )
{
T_3 V_61 ;
unsigned long V_175 , V_176 , V_178 ;
struct V_197 * V_198 ;
char * V_185 ;
T_7 * V_199 ;
V_178 = V_70 - V_67 - 0x4000 ;
if ( V_178 > V_180 )
V_178 = V_180 ;
F_24 ( L_232 , V_67 ) ;
V_175 = ( unsigned long ) F_27 ( V_178 , V_80 ) ;
if ( V_175 == 0 )
F_29 ( L_233 ) ;
V_176 = V_175 + V_178 ;
V_61 = F_2 ( L_9 , 1 , 1 , ( T_3 ) 0 ) ;
if ( V_61 == ( T_3 ) 0 )
F_29 ( L_234 ) ;
V_175 = F_71 ( V_175 , 4 ) ;
V_198 = F_70 ( & V_175 , & V_176 ,
sizeof( struct V_197 ) , 4 ) ;
V_200 = ( unsigned long ) V_198 ;
V_199 = F_70 ( & V_175 , & V_176 , sizeof( V_82 ) , 8 ) ;
V_175 = F_36 ( V_175 ) ;
V_182 = V_175 ;
V_175 += 4 ;
V_185 = F_70 ( & V_175 , & V_176 , 16 , 1 ) ;
strcpy ( V_185 , L_230 ) ;
V_175 = ( unsigned long ) V_185 + strlen ( V_185 ) + 1 ;
F_8 ( L_235 ) ;
F_73 ( V_61 , & V_175 , & V_176 ) ;
V_183 = V_175 ;
V_175 = F_36 ( V_175 ) ;
V_201 = V_175 ;
F_8 ( L_236 ) ;
F_74 ( V_61 , & V_175 , & V_176 ) ;
F_75 ( V_202 , & V_175 , & V_176 ) ;
V_203 = F_36 ( V_175 ) ;
V_198 -> V_204 = V_15 . V_104 ;
V_198 -> V_205 = V_206 ;
V_198 -> V_207 = V_203 - V_200 ;
V_198 -> V_208 = V_201 - V_200 ;
V_198 -> V_209 = V_182 - V_200 ;
V_198 -> V_210 = V_183 - V_182 ;
V_198 -> V_211 = ( ( unsigned long ) V_199 ) - V_200 ;
V_198 -> V_157 = V_212 ;
V_198 -> V_213 = 0x10 ;
memcpy ( V_199 , V_82 , sizeof( V_82 ) ) ;
#ifdef F_35
{
int V_6 ;
F_8 ( L_237 ) ;
for ( V_6 = 0 ; V_6 < V_79 ; V_6 ++ )
F_8 ( L_238 ,
V_82 [ V_6 ] . V_47 ,
V_82 [ V_6 ] . V_19 ) ;
}
#endif
V_79 = V_81 ;
F_8 ( L_239 ,
V_182 , V_183 ) ;
F_8 ( L_240 ,
V_201 , V_203 ) ;
}
static void T_1 F_77 ( void )
{
T_3 V_214 ;
V_38 V_215 = 0x01002000 ;
V_38 V_216 [ 6 ] ;
char * V_217 ;
V_217 = L_241 ;
V_214 = F_2 ( L_77 , 1 , 1 , F_3 ( V_217 ) ) ;
if ( ! F_40 ( V_214 ) ) {
V_217 = L_242 ;
V_214 = F_2 ( L_77 , 1 , 1 , F_3 ( V_217 ) ) ;
V_215 = 0x01003000 ;
}
if ( ! F_40 ( V_214 ) )
return;
if ( F_12 ( V_214 , L_243 ) != 12 )
return;
if ( F_11 ( V_214 , L_243 , V_216 , sizeof( V_216 ) )
== V_10 )
return;
if ( V_216 [ 0 ] != 0x1 ||
V_216 [ 1 ] != 0xf4000000 ||
V_216 [ 2 ] != 0x00010000 )
return;
F_8 ( L_244 ) ;
V_216 [ 0 ] = 0x1 ;
V_216 [ 1 ] = 0x0 ;
V_216 [ 2 ] = V_215 ;
V_216 [ 3 ] = 0x0 ;
V_216 [ 4 ] = 0x0 ;
V_216 [ 5 ] = 0x00010000 ;
F_15 ( V_214 , V_217 , L_243 ,
V_216 , sizeof( V_216 ) ) ;
}
static void T_1 F_78 ( void )
{
T_3 V_218 ;
V_38 V_219 [ 4 ] ;
char * V_217 = L_245 ;
V_38 V_220 , V_221 ;
V_218 = F_2 ( L_77 , 1 , 1 , F_3 ( V_217 ) ) ;
if ( ! F_40 ( V_218 ) )
return;
if ( F_12 ( V_218 , L_67 ) != 8 )
return;
F_11 ( V_15 . V_61 , L_60 , & V_220 , sizeof( V_220 ) ) ;
F_11 ( V_15 . V_61 , L_61 , & V_221 , sizeof( V_221 ) ) ;
if ( ( V_220 != 2 ) || ( V_221 != 2 ) )
return;
if ( F_11 ( V_218 , L_67 , V_219 , sizeof( V_219 ) ) == V_10 )
return;
if ( V_219 [ 0 ] != V_222 || V_219 [ 1 ] != V_223 )
return;
F_8 ( L_246 ) ;
V_219 [ 0 ] = 0x0 ;
V_219 [ 1 ] = V_222 ;
V_219 [ 2 ] = 0x0 ;
V_219 [ 3 ] = V_223 ;
F_15 ( V_218 , V_217 , L_67 , V_219 , sizeof( V_219 ) ) ;
}
static void T_1 F_79 ( void )
{
T_3 V_224 ;
V_38 V_225 [ 6 ] ;
V_38 V_215 = 0x01006000 ;
char * V_217 ;
int V_94 ;
V_217 = L_247 ;
V_224 = F_2 ( L_77 , 1 , 1 , F_3 ( V_217 ) ) ;
if ( ! F_40 ( V_224 ) ) {
V_217 = L_248 ;
V_224 = F_2 ( L_77 , 1 , 1 , F_3 ( V_217 ) ) ;
V_215 = 0x01003000 ;
}
if ( F_40 ( V_224 ) ) {
V_94 = F_12 ( V_224 , L_243 ) ;
if ( V_94 == 0 || V_94 == V_10 ) {
F_8 ( L_249 ) ;
V_225 [ 0 ] = 0x1 ;
V_225 [ 1 ] = 0x0 ;
V_225 [ 2 ] = V_215 ;
V_225 [ 3 ] = 0x0 ;
V_225 [ 4 ] = 0x0 ;
V_225 [ 5 ] = 0x00010000 ;
F_15 ( V_224 , V_217 , L_243 , V_225 , sizeof( V_225 ) ) ;
}
}
V_217 = L_250 ;
V_224 = F_2 ( L_77 , 1 , 1 , F_3 ( V_217 ) ) ;
if ( F_40 ( V_224 ) ) {
F_8 ( L_251 ) ;
V_225 [ 0 ] = 14 ;
V_225 [ 1 ] = 0x0 ;
F_15 ( V_224 , V_217 , L_252 , V_225 , 2 * sizeof( V_38 ) ) ;
F_8 ( L_253 ) ;
V_94 = F_11 ( V_224 , L_254 , V_225 , sizeof( V_38 ) ) ;
if ( V_94 == sizeof( V_38 ) ) {
V_225 [ 0 ] &= ~ 0x5 ;
F_15 ( V_224 , V_217 , L_254 , V_225 , sizeof( V_38 ) ) ;
}
}
}
static void T_1 F_80 ( void )
{
T_3 V_226 , V_227 , V_228 ;
V_38 V_229 ;
V_38 V_230 [ 2 ] ;
V_38 V_231 ;
V_226 = F_2 ( L_77 , 1 , 1 , F_3 ( L_255 ) ) ;
if ( ! F_40 ( V_226 ) )
return;
V_227 = F_2 ( L_77 , 1 , 1 , F_3 ( L_256 ) ) ;
if ( ! F_40 ( V_227 ) )
return;
V_228 = F_2 ( L_77 , 1 , 1 , F_3 ( L_257 ) ) ;
if ( ! F_40 ( V_228 ) )
return;
if ( F_11 ( V_226 , L_258 , & V_229 , sizeof( V_229 ) )
== V_10 )
return;
if ( V_229 < 0x35 || V_229 > 0x39 )
return;
if ( F_12 ( V_227 , L_252 ) > 0 )
return;
F_8 ( L_259 ) ;
V_230 [ 0 ] = 0 ;
V_230 [ 1 ] = 1 ;
F_15 ( V_227 , L_256 , L_252 ,
& V_230 , sizeof( V_230 ) ) ;
V_231 = ( V_38 ) V_228 ;
F_15 ( V_227 , L_256 , L_260 ,
& V_231 , sizeof( V_231 ) ) ;
}
static void T_1 F_81 ( void )
{
V_38 V_34 ;
char V_225 [ 64 ] ;
int V_232 ;
V_34 = F_2 ( L_77 , 1 , 1 , F_3 ( L_261 ) ) ;
if ( ! F_40 ( V_34 ) )
return;
V_232 = F_11 ( V_34 , L_262 , V_225 , sizeof( V_225 ) ) ;
if ( ! V_232 )
return;
V_34 = F_2 ( L_77 , 1 , 1 , F_3 ( L_263 ) ) ;
if ( ! F_40 ( V_34 ) ) {
F_8 ( L_264 ) ;
F_2 ( L_17 , 1 , 1 ,
L_265
L_266
L_267
L_268
L_269
L_270
L_271
L_272
L_273
L_274
L_275
L_276
L_277 ) ;
} ;
V_34 = F_2 ( L_77 , 1 , 1 ,
F_3 ( L_278 ) ) ;
if ( ! F_40 ( V_34 ) ) {
F_8 ( L_279 ) ;
F_2 ( L_17 , 1 , 1 ,
L_280
L_266
L_281
L_282
L_283
L_284
L_277
L_285
L_286
L_287
L_288 ) ;
}
}
static void T_1 F_82 ( void )
{
int V_233 [ 3 ] = { 2 , 2 , 0 } ;
int V_234 [ 3 * 16 ] = { 3 , 0 , 0 , 3 , 1 , 0 , 3 , 2 , 0 , 3 , 3 , 0 ,
3 , 4 , 0 , 3 , 5 , 0 , 3 , 6 , 0 , 3 , 7 , 0 ,
3 , 8 , 0 , 3 , 9 , 0 , 3 , 10 , 0 , 3 , 11 , 0 ,
3 , 12 , 0 , 3 , 13 , 0 , 3 , 14 , 0 , 3 , 15 , 0 } ;
V_38 V_34 ;
char V_225 [ 64 ] ;
int V_232 , V_161 ;
V_34 = F_2 ( L_77 , 1 , 1 , F_3 ( L_32 ) ) ;
if ( ! F_40 ( V_34 ) )
return;
V_232 = F_11 ( V_34 , L_156 , V_225 , sizeof( V_225 ) ) ;
if ( V_232 == V_10 )
return;
if ( strcmp ( V_225 , L_289 ) )
return;
F_8 ( L_290 ) ;
V_34 = F_2 ( L_77 , 1 , 1 , F_3 ( L_32 ) ) ;
V_232 = F_11 ( V_34 , L_25 , V_225 , sizeof( V_225 ) ) ;
if ( V_232 != V_10 && ( strcmp ( V_225 , L_213 ) == 0 ) )
F_15 ( V_34 , L_32 , L_25 , L_291 , sizeof( L_291 ) ) ;
V_232 = F_11 ( V_34 , L_292 , V_225 , sizeof( V_225 ) ) ;
if ( V_232 != V_10 && ( strstr ( V_225 , L_293 ) ) )
F_15 ( V_34 , L_32 , L_292 ,
L_294 ,
sizeof( L_294 ) ) ;
V_34 = F_2 ( L_77 , 1 , 1 , F_3 ( L_295 ) ) ;
if ( F_40 ( V_34 ) ) {
V_161 = F_12 ( V_34 , L_252 ) ;
if ( V_161 == 12 ) {
F_8 ( L_296 ) ;
F_15 ( V_34 , L_297 , L_252 ,
V_234 , sizeof( V_234 ) ) ;
}
}
V_34 = F_2 ( L_77 , 1 , 1 , F_3 ( L_298 ) ) ;
if ( F_40 ( V_34 ) ) {
V_232 = F_11 ( V_34 , L_252 , V_225 , sizeof( V_225 ) ) ;
if ( V_232 == V_10 ) {
F_8 ( L_299 ) ;
F_15 ( V_34 , L_298 , L_252 ,
V_233 , sizeof( V_233 ) ) ;
}
}
F_81 () ;
}
static void T_1 F_83 ( void )
{
F_77 () ;
F_78 () ;
F_79 () ;
F_80 () ;
F_82 () ;
}
static void T_1 F_84 ( void )
{
V_38 V_235 ;
T_5 V_236 ;
T_3 V_237 ;
V_15 . V_104 = 0 ;
if ( F_11 ( V_15 . V_54 , L_26 , & V_236 , sizeof( V_236 ) ) <= 0 )
return;
V_237 = F_2 ( L_203 , 1 , 1 , V_236 ) ;
F_11 ( V_237 , L_67 , & V_235 , sizeof( V_235 ) ) ;
V_15 . V_104 = V_235 ;
F_24 ( L_300 , V_15 . V_104 ) ;
}
static void T_1 F_85 ( unsigned long V_238 , unsigned long V_239 )
{
#ifdef F_86
if ( V_238 && V_239 && V_239 != 0xdeadbeef ) {
unsigned long V_16 ;
V_92 = F_87 ( V_238 ) ? F_88 ( V_238 ) : V_238 ;
V_93 = V_92 + V_239 ;
V_16 = V_92 ;
F_15 ( V_15 . V_54 , L_191 , L_301 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = V_93 ;
F_15 ( V_15 . V_54 , L_191 , L_302 ,
& V_16 , sizeof( V_16 ) ) ;
F_33 ( V_92 ,
V_93 - V_92 ) ;
F_24 ( L_303 , V_92 ) ;
F_24 ( L_304 , V_93 ) ;
}
#endif
}
static void F_89 ( void )
{
}
static void F_90 ( void )
{
}
static void F_91 ( unsigned long V_240 , unsigned long V_241 )
{
unsigned long V_6 ;
unsigned long * V_242 ;
asm volatile("addi %0,2,-0x8000" : "=b" (toc_entry));
for ( V_6 = 0 ; V_6 < V_241 ; V_6 ++ ) {
* V_242 = * V_242 + V_240 ;
V_242 ++ ;
}
}
static void F_89 ( void )
{
unsigned long V_240 = F_92 () ;
unsigned long V_241 =
( V_243 - V_244 ) / sizeof( long ) ;
F_91 ( V_240 , V_241 ) ;
F_46 () ;
}
static void F_90 ( void )
{
unsigned long V_240 = F_92 () ;
unsigned long V_241 =
( V_243 - V_244 ) / sizeof( long ) ;
F_46 () ;
F_91 ( - V_240 , V_241 ) ;
}
unsigned long T_1 F_93 ( unsigned long V_238 , unsigned long V_239 ,
unsigned long V_155 ,
unsigned long V_245 , unsigned long V_246 ,
unsigned long V_247 )
{
unsigned long V_198 ;
#ifdef F_94
unsigned long V_240 = F_92 () ;
F_95 ( V_240 ) ;
#else
F_89 () ;
#endif
memset ( & V_248 , 0 , V_249 - V_248 ) ;
F_62 ( V_155 ) ;
F_63 () ;
F_64 () ;
F_8 ( L_305 , V_250 ) ;
V_89 = F_65 () ;
F_8 ( L_306 , V_89 ) ;
#ifndef F_96
if ( V_251 > 0 )
F_29 ( L_307 ) ;
#endif
F_85 ( V_238 , V_239 ) ;
#if F_97 ( V_252 ) || F_97 ( F_54 )
if ( V_89 == V_167 ||
V_89 == V_166 )
F_25 () ;
#endif
if ( V_89 != V_164 )
F_98 ( 0 , V_247 , 0x100 , 0 ) ;
F_18 () ;
F_34 () ;
F_84 () ;
F_67 () ;
#ifdef F_21
if ( V_89 == V_167 )
F_56 () ;
#endif
if ( V_89 != V_164 &&
V_89 != V_97 )
F_53 () ;
#ifdef F_54
if ( V_89 == V_166 ) {
F_39 () ;
if ( V_89 == V_97 ) {
F_44 () ;
F_48 () ;
}
} else if ( V_89 == V_97 )
F_50 () ;
#endif
#ifdef F_21
F_55 () ;
#endif
if ( V_89 != V_164 &&
V_89 != V_97 )
F_59 () ;
if ( V_58 )
F_15 ( V_15 . V_54 , L_191 , L_308 ,
& V_58 ,
sizeof( V_58 ) ) ;
#ifdef F_21
if ( V_56 )
F_15 ( V_15 . V_54 , L_191 , L_309 ,
NULL , 0 ) ;
if ( V_57 )
F_15 ( V_15 . V_54 , L_191 , L_310 ,
NULL , 0 ) ;
if ( V_146 ) {
F_15 ( V_15 . V_54 , L_191 , L_311 ,
& V_146 ,
sizeof( V_146 ) ) ;
F_15 ( V_15 . V_54 , L_191 , L_312 ,
& V_147 ,
sizeof( V_147 ) ) ;
}
#endif
F_83 () ;
F_8 ( L_313 ) ;
F_76 () ;
if ( V_89 != V_164 &&
V_89 != V_97 )
F_38 () ;
F_8 ( L_314 ) ;
F_2 ( L_315 , 0 , 0 ) ;
V_198 = V_200 ;
if ( V_89 != V_97 ) {
F_8 ( L_316 ) ;
F_24 ( L_317 , V_198 ) ;
}
#ifdef F_94
F_95 ( - V_240 ) ;
#else
F_90 () ;
#endif
#ifdef F_52
F_99 ( V_198 , V_247 , 0 , 0 , 0 ,
V_128 , V_129 ) ;
#else
F_99 ( V_198 , V_247 , 0 , 0 , 0 , 0 , 0 ) ;
#endif
return 0 ;
}
