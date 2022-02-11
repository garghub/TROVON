static inline int F_1 ( struct V_1 * args , unsigned long V_2 )
{
return ( ( int ( * ) ( struct V_1 * ) ) V_2 ) ( args ) ;
}
static int T_1 F_2 ( const char * V_3 , int V_4 , int V_5 , ... )
{
int V_6 ;
struct V_1 args ;
T_2 V_7 ;
args . V_3 = F_3 ( F_4 ( V_3 ) ) ;
args . V_4 = F_3 ( V_4 ) ;
args . V_5 = F_3 ( V_5 ) ;
va_start ( V_7 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ )
args . args [ V_6 ] = F_3 ( va_arg ( V_7 , V_8 ) ) ;
va_end ( V_7 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
args . args [ V_4 + V_6 ] = 0 ;
if ( F_1 ( & args , V_9 ) < 0 )
return V_10 ;
return ( V_5 > 0 ) ? F_5 ( args . args [ V_4 ] ) : 0 ;
}
static int T_1 F_6 ( const char * V_3 , int V_4 , int V_5 ,
V_8 * V_11 , ... )
{
int V_6 ;
struct V_1 args ;
T_2 V_7 ;
args . V_3 = F_3 ( F_4 ( V_3 ) ) ;
args . V_4 = F_3 ( V_4 ) ;
args . V_5 = F_3 ( V_5 ) ;
va_start ( V_7 , V_11 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ )
args . args [ V_6 ] = F_3 ( va_arg ( V_7 , V_8 ) ) ;
va_end ( V_7 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
args . args [ V_4 + V_6 ] = 0 ;
if ( F_1 ( & args , V_9 ) < 0 )
return V_10 ;
if ( V_11 != NULL )
for ( V_6 = 1 ; V_6 < V_5 ; ++ V_6 )
V_11 [ V_6 - 1 ] = F_5 ( args . args [ V_4 + V_6 ] ) ;
return ( V_5 > 0 ) ? F_5 ( args . args [ V_4 ] ) : 0 ;
}
static void T_1 F_7 ( const char * V_12 )
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
F_2 ( L_1 , 3 , 1 , V_15 . stdout , F_4 ( L_2 ) , 2 ) ;
}
}
static void T_1 F_8 ( unsigned long V_16 )
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
static void T_1 F_9 ( unsigned long V_16 )
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
static void T_1 F_10 ( const char * V_21 , ... )
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
F_4 ( L_2 ) , 2 ) ;
continue;
}
++ V_14 ;
if ( * V_14 == 0 )
break;
switch ( * V_14 ) {
case 's' :
++ V_14 ;
V_22 = va_arg ( args , const char * ) ;
F_7 ( V_22 ) ;
break;
case 'x' :
++ V_14 ;
V_23 = va_arg (args, unsigned long) ;
F_8 ( V_23 ) ;
break;
case 'd' :
++ V_14 ;
V_24 = va_arg ( args , int ) ;
if ( V_24 < 0 ) {
F_7 ( L_3 ) ;
V_24 = - V_24 ;
}
F_9 ( V_24 ) ;
break;
case 'l' :
++ V_14 ;
if ( * V_14 == 0 )
break;
else if ( * V_14 == 'x' ) {
++ V_14 ;
V_23 = va_arg (args, unsigned long) ;
F_8 ( V_23 ) ;
} else if ( * V_14 == 'u' ) {
++ V_14 ;
V_23 = va_arg (args, unsigned long) ;
F_9 ( V_23 ) ;
} else if ( * V_14 == 'd' ) {
++ V_14 ;
V_24 = va_arg ( args , long ) ;
if ( V_24 < 0 ) {
F_7 ( L_3 ) ;
V_24 = - V_24 ;
}
F_9 ( V_24 ) ;
}
break;
}
}
}
static unsigned int T_1 F_11 ( unsigned long V_25 , unsigned long V_19 ,
unsigned long V_26 )
{
if ( V_26 == 0 && ( V_27 & V_28 ) ) {
int V_29 ;
V_8 V_30 ;
V_29 = F_6 ( L_4 , 5 , 2 , & V_30 ,
F_4 ( L_5 ) , V_15 . V_31 ,
V_26 , V_19 , V_25 ) ;
if ( V_29 != 0 || V_30 == - 1 )
return - 1 ;
V_29 = F_6 ( L_4 , 5 , 2 , & V_30 ,
F_4 ( L_5 ) , V_15 . V_32 ,
V_26 , V_19 , V_25 ) ;
if ( V_29 != 0 ) {
F_2 ( L_4 , 4 , 1 , F_4 ( L_6 ) ,
V_15 . V_31 , V_19 , V_25 ) ;
return - 1 ;
}
F_2 ( L_4 , 6 , 1 ,
F_4 ( L_7 ) , V_15 . V_32 , 0x12 , V_19 , V_25 , V_25 ) ;
return V_25 ;
}
return F_2 ( L_5 , 3 , 1 , ( V_8 ) V_25 , ( V_8 ) V_19 ,
( V_8 ) V_26 ) ;
}
static int T_1 F_12 ( T_3 * V_33 )
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
static int inline F_13 ( T_3 V_34 , const char * V_35 ,
void * V_36 , T_4 V_37 )
{
return F_2 ( L_11 , 4 , 1 , V_34 , F_4 ( V_35 ) ,
( V_38 ) ( unsigned long ) V_36 , ( V_38 ) V_37 ) ;
}
static int inline F_14 ( T_3 V_34 , const char * V_35 )
{
return F_2 ( L_12 , 2 , 1 , V_34 , F_4 ( V_35 ) ) ;
}
static void F_15 ( char * * V_39 , const char * V_14 )
{
char * V_13 = * V_39 ;
while ( * V_14 )
* V_13 ++ = * V_14 ++ ;
* V_13 ++ = ' ' ;
* V_39 = V_13 ;
}
static char * F_16 ( unsigned int V_40 )
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
static int T_1 F_17 ( T_3 V_34 , const char * V_42 ,
const char * V_35 , void * V_36 , T_4 V_37 )
{
char V_43 [ 256 ] , * V_13 ;
if ( ! ( V_27 & V_44 ) )
return F_2 ( L_14 , 4 , 1 , V_34 , F_4 ( V_35 ) ,
( V_38 ) ( unsigned long ) V_36 , ( V_38 ) V_37 ) ;
V_13 = V_43 ;
F_15 ( & V_13 , L_15 ) ;
F_15 ( & V_13 , V_42 ) ;
F_15 ( & V_13 , F_16 ( ( V_38 ) ( unsigned long ) V_36 ) ) ;
F_15 ( & V_13 , F_16 ( V_37 ) ) ;
F_15 ( & V_13 , F_16 ( F_4 ( V_35 ) ) ) ;
F_15 ( & V_13 , F_16 ( strlen ( V_35 ) ) ) ;
F_15 ( & V_13 , L_16 ) ;
* V_13 = 0 ;
return F_2 ( L_17 , 1 , 1 , ( V_38 ) ( unsigned long ) V_43 ) ;
}
static unsigned long F_18 ( const char * V_45 , const char * * V_46 )
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
static unsigned long F_19 ( const char * V_48 , const char * * V_49 )
{
unsigned long V_29 = F_18 ( V_48 , V_49 ) ;
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
static void T_1 F_20 ( void )
{
const char * V_51 ;
char * V_13 ;
int V_52 = 0 ;
V_53 [ 0 ] = 0 ;
V_13 = V_53 ;
if ( ( long ) V_15 . V_54 > 0 )
V_52 = F_13 ( V_15 . V_54 , L_18 , V_13 , V_55 - 1 ) ;
#ifdef F_21
if ( V_52 <= 0 || V_13 [ 0 ] == '\0' )
F_22 ( V_53 ,
F_21 , sizeof( V_53 ) ) ;
#endif
F_10 ( L_19 , V_53 ) ;
#ifdef F_23
V_51 = strstr ( V_53 , L_20 ) ;
if ( V_51 ) {
F_10 ( L_21 , V_51 ) ;
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
V_58 = F_19 ( V_51 , ( const char * * ) & V_51 ) ;
#ifdef F_23
V_58 = F_24 ( V_58 , 0x1000000 ) ;
#endif
}
}
static int T_1 F_25 ( void )
{
T_3 V_34 ;
char type [ 64 ] ;
unsigned int V_59 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_26 ) )
continue;
V_59 = F_14 ( V_34 , L_27 ) ;
if ( V_59 == V_10 )
break;
V_59 >>= 2 ;
F_26 ( L_28 , ( unsigned long ) V_59 ) ;
if ( V_59 < 1 || V_59 > 64 ) {
F_10 ( L_29 ,
( unsigned long ) V_59 ) ;
return 1 ;
}
return V_59 ;
}
F_26 ( L_30 ) ;
return 1 ;
}
static void T_1 F_27 ( void )
{
T_5 V_60 ;
V_8 V_29 ;
V_38 V_61 ;
unsigned char * V_62 ;
V_60 = F_2 ( L_31 , 1 , 1 , F_4 ( L_32 ) ) ;
if ( V_60 != 0 ) {
V_62 = & V_63 [ V_64 ] ;
V_61 = 0 ;
V_61 |= V_62 [ 0 ] << 24 ;
V_61 |= V_62 [ 1 ] << 16 ;
V_61 |= V_62 [ 2 ] << 8 ;
V_61 |= V_62 [ 3 ] ;
if ( V_61 != V_65 ) {
F_10 ( L_33
L_34 ,
V_61 ) ;
} else {
V_61 = F_28 ( V_65 , F_25 () ) ;
F_10 ( L_35 ,
V_61 , V_65 ) ;
V_62 [ 0 ] = ( V_61 >> 24 ) & 0xff ;
V_62 [ 1 ] = ( V_61 >> 16 ) & 0xff ;
V_62 [ 2 ] = ( V_61 >> 8 ) & 0xff ;
V_62 [ 3 ] = V_61 & 0xff ;
}
F_10 ( L_36 ) ;
if ( F_6 ( L_4 , 3 , 2 , & V_29 ,
F_4 ( L_37 ) ,
V_60 ,
F_4 ( V_63 ) ) == 0 ) {
if ( V_29 )
F_10 ( L_38
L_39 ) ;
F_2 ( L_40 , 1 , 0 , V_60 ) ;
F_10 ( L_41 ) ;
return;
}
F_2 ( L_40 , 1 , 0 , V_60 ) ;
F_10 ( L_42 ) ;
}
#ifdef F_29
{
T_5 V_66 ;
V_66 = F_2 ( L_31 , 1 , 1 ,
F_4 ( L_43 ) ) ;
if ( V_66 == 0 ) {
F_10 ( L_44 ) ;
return;
}
F_2 ( L_4 , 3 , 1 , F_4 ( L_45 ) ,
V_66 , F_4 ( & V_67 ) ) ;
F_2 ( L_40 , 1 , 0 , V_66 ) ;
}
#endif
}
static unsigned long T_1 F_30 ( unsigned long V_19 , unsigned long V_26 )
{
unsigned long V_47 = V_68 ;
unsigned long V_69 = 0 ;
if ( V_26 )
V_47 = F_31 ( V_47 , V_26 ) ;
F_26 ( L_46 , V_19 , V_26 ) ;
if ( V_70 == 0 )
F_32 ( L_47 ) ;
if ( V_26 )
V_47 = F_31 ( V_68 , V_26 ) ;
else
V_47 = V_68 ;
for(; ( V_47 + V_19 ) <= V_71 ;
V_47 = F_31 ( V_47 + 0x100000 , V_26 ) ) {
F_26 ( L_48 , V_47 ) ;
V_69 = ( unsigned long ) F_11 ( V_47 , V_19 , 0 ) ;
if ( V_69 != V_10 && V_69 != 0 )
break;
V_69 = 0 ;
if ( V_26 == 0 )
break;
}
if ( V_69 == 0 )
return 0 ;
V_68 = V_69 + V_19 ;
F_26 ( L_49 , V_69 ) ;
F_26 ( L_50 , V_68 ) ;
F_26 ( L_51 , V_71 ) ;
F_26 ( L_52 , V_72 ) ;
F_26 ( L_53 , V_73 ) ;
F_26 ( L_54 , V_70 ) ;
return V_69 ;
}
static unsigned long T_1 F_33 ( unsigned long V_19 , unsigned long V_26 ,
int V_74 )
{
unsigned long V_47 , V_69 = 0 ;
F_26 ( L_55 , V_19 , V_26 ,
V_74 ? L_56 : L_57 ) ;
if ( V_70 == 0 )
F_32 ( L_58 ) ;
if ( V_74 ) {
V_69 = F_34 ( V_72 - V_19 , V_26 ) ;
if ( V_69 <= V_68 )
return 0 ;
if ( V_69 < V_73 ) {
if ( V_71 == V_73 )
V_71 = V_73 = V_69 ;
else
return 0 ;
}
V_72 = V_69 ;
goto V_75;
}
V_47 = F_34 ( V_71 - V_19 , V_26 ) ;
for (; V_47 > V_68 ;
V_47 = F_34 ( V_47 - 0x100000 , V_26 ) ) {
F_26 ( L_48 , V_47 ) ;
V_69 = ( unsigned long ) F_11 ( V_47 , V_19 , 0 ) ;
if ( V_69 != V_10 && V_69 != 0 )
break;
V_69 = 0 ;
}
if ( V_69 == 0 )
return 0 ;
V_71 = V_69 ;
V_75:
F_26 ( L_49 , V_69 ) ;
F_26 ( L_50 , V_68 ) ;
F_26 ( L_51 , V_71 ) ;
F_26 ( L_52 , V_72 ) ;
F_26 ( L_53 , V_73 ) ;
F_26 ( L_54 , V_70 ) ;
return V_69 ;
}
static unsigned long T_1 F_35 ( int V_22 , T_6 * * V_76 )
{
T_6 * V_13 = * V_76 ;
unsigned long V_77 = 0 ;
while ( V_22 > sizeof( unsigned long ) / 4 ) {
V_13 ++ ;
V_22 -- ;
}
V_77 = F_5 ( * V_13 ++ ) ;
#ifdef F_23
if ( V_22 > 1 ) {
V_77 <<= 32 ;
V_77 |= F_5 ( * ( V_13 ++ ) ) ;
}
#endif
* V_76 = V_13 ;
return V_77 ;
}
static void T_1 F_36 ( T_7 V_47 , T_7 V_19 )
{
T_7 V_78 = V_47 + V_19 ;
unsigned long V_79 = V_80 ;
if ( V_19 == 0 )
return;
V_47 = F_34 ( V_47 , V_81 ) ;
V_78 = F_31 ( V_78 , V_81 ) ;
V_19 = V_78 - V_47 ;
if ( V_79 >= ( V_82 - 1 ) )
F_32 ( L_59 ) ;
V_83 [ V_79 ] . V_47 = F_37 ( V_47 ) ;
V_83 [ V_79 ] . V_19 = F_37 ( V_19 ) ;
V_80 = V_79 + 1 ;
}
static void T_1 F_38 ( void )
{
T_3 V_34 ;
char * V_84 , type [ 64 ] ;
unsigned int V_59 ;
T_6 * V_13 , * V_46 ;
T_8 V_16 ;
V_38 V_85 , V_86 ;
V_16 = F_3 ( 2 ) ;
F_13 ( V_15 . V_60 , L_60 , & V_16 , sizeof( V_16 ) ) ;
V_85 = F_5 ( V_16 ) ;
V_16 = F_3 ( 1 ) ;
F_13 ( V_15 . V_60 , L_61 , & V_16 , sizeof( V_86 ) ) ;
V_86 = F_5 ( V_16 ) ;
F_26 ( L_62 , V_85 ) ;
F_26 ( L_63 , V_86 ) ;
F_26 ( L_64 ) ;
V_84 = V_87 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( type [ 0 ] == 0 ) {
F_13 ( V_34 , L_65 , type , sizeof( type ) ) ;
}
if ( strcmp ( type , L_66 ) )
continue;
V_59 = F_13 ( V_34 , L_67 , V_88 , sizeof( V_88 ) ) ;
if ( V_59 > sizeof( V_88 ) ) {
F_10 ( L_68 ) ;
V_59 = sizeof( V_88 ) ;
}
V_13 = V_88 ;
V_46 = V_13 + ( V_59 / sizeof( T_6 ) ) ;
#ifdef F_39
memset ( V_84 , 0 , V_89 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_84 , V_89 - 1 ) ;
F_26 ( L_70 , V_84 ) ;
#endif
while ( ( V_46 - V_13 ) >= ( V_85 + V_86 ) ) {
unsigned long V_47 , V_19 ;
V_47 = F_35 ( V_85 , & V_13 ) ;
V_19 = F_35 ( V_86 , & V_13 ) ;
if ( V_19 == 0 )
continue;
F_26 ( L_71 , V_47 , V_19 ) ;
if ( V_47 == 0 && ( V_90 & V_91 ) )
V_73 = V_19 ;
if ( ( V_47 + V_19 ) > V_70 )
V_70 = V_47 + V_19 ;
}
}
V_68 = F_40 ( ( unsigned long ) & V_92 + 0x4000 ) ;
V_72 = V_70 ;
if ( V_58 ) {
if ( V_58 <= V_68 ) {
F_10 ( L_72 ,
V_58 ) ;
V_58 = 0 ;
} else if ( V_58 >= V_70 ) {
F_10 ( L_73 ,
V_58 ) ;
V_58 = 0 ;
} else {
V_70 = V_58 ;
V_73 = F_41 ( V_73 , V_58 ) ;
}
}
if ( ! V_73 )
V_73 = V_70 ;
V_73 = F_41 ( 0x30000000ul , V_73 ) ;
V_71 = V_73 ;
V_72 = V_70 ;
if ( V_93 &&
V_93 < V_73 &&
V_94 > V_68 )
V_68 = F_40 ( V_94 ) ;
F_10 ( L_74 ) ;
F_10 ( L_75 , V_58 ) ;
F_10 ( L_50 , V_68 ) ;
F_10 ( L_51 , V_71 ) ;
F_10 ( L_52 , V_72 ) ;
F_10 ( L_53 , V_73 ) ;
F_10 ( L_54 , V_70 ) ;
}
static void T_1 F_42 ( void )
{
T_8 V_16 ;
T_5 V_95 ;
if ( F_13 ( V_15 . V_54 , L_76 , & V_16 , sizeof( V_16 ) ) > 0 ) {
V_95 = F_5 ( V_16 ) ;
F_2 ( L_40 , 1 , 0 , V_95 ) ;
}
}
static void T_1 F_43 ( void )
{
long V_96 ;
if ( F_44 ( F_2 ( L_77 , 1 , 1 ,
F_4 ( L_78 ) ) ) ) {
F_10 ( L_79 ) ;
return;
}
F_10 ( L_80 ) ;
V_96 = F_45 ( & V_97 ,
& V_98 ) ;
F_26 ( L_81 , V_96 ) ;
if ( V_96 != 0 ) {
F_10 ( L_82 ) ;
return;
}
V_90 = V_99 ;
F_10 ( L_83 ) ;
F_26 ( L_84 , V_97 ) ;
F_26 ( L_85 , V_98 ) ;
if ( V_98 < 0x10000 )
V_98 = 0x10000 ;
}
static int T_1 F_46 ( int V_100 , int V_4 , int V_5 ,
int * V_101 , ... )
{
struct V_102 V_102 ;
T_2 V_7 ;
int V_6 ;
V_102 . V_100 = V_100 ;
V_102 . V_4 = V_4 ;
V_102 . V_5 = V_5 ;
V_102 . V_11 = ( V_103 * ) & ( V_102 . args [ V_4 ] ) ;
va_start ( V_7 , V_101 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; ++ V_6 )
V_102 . args [ V_6 ] = va_arg ( V_7 , V_103 ) ;
va_end ( V_7 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; ++ V_6 )
V_102 . V_11 [ V_6 ] = 0 ;
F_47 ( & V_102 , V_104 ,
V_105 ) ;
if ( V_5 > 1 && V_101 != NULL )
for ( V_6 = 0 ; V_6 < V_5 - 1 ; ++ V_6 )
V_101 [ V_6 ] = V_102 . V_11 [ V_6 + 1 ] ;
return ( V_5 > 0 ) ? V_102 . V_11 [ 0 ] : 0 ;
}
static void T_1 F_48 ( void )
{
int V_6 , V_79 , V_106 , V_96 ;
long V_107 ;
T_3 V_34 ;
char type [ 64 ] ;
V_38 V_108 [ 8 ] ;
void * V_2 = ( unsigned long * ) & V_109 ;
struct V_110 * V_111 = & V_110 ;
F_26 ( L_86 ) ;
F_26 ( L_87 , V_2 ) ;
F_26 ( L_88 , V_111 ) ;
V_111 -> V_112 = - 1 ;
V_111 -> V_113 = 0 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_26 ) != 0 )
continue;
if ( F_13 ( V_34 , L_89 , type , sizeof( type ) ) > 0 )
if ( strcmp ( type , L_90 ) != 0 )
continue;
V_79 = F_13 ( V_34 , L_27 , V_108 ,
sizeof( V_108 ) ) ;
if ( V_79 == V_10 )
break;
V_79 >>= 2 ;
for ( V_6 = 0 ; V_6 < V_79 ; V_6 ++ ) {
V_106 = V_108 [ V_6 ] ;
F_26 ( L_91 , V_106 ) ;
if ( V_106 == V_15 . V_106 ) {
F_26 ( L_92 ) ;
continue;
}
F_26 ( L_93 ) ;
V_111 -> V_112 = - 1 ;
V_96 = F_46 ( V_114 , 3 , 1 ,
NULL , V_106 , V_2 , V_111 ) ;
F_26 ( L_94 , V_96 ) ;
for ( V_107 = 0 ; V_107 < 100000000 && V_111 -> V_112 == - 1 ; V_107 ++ ) {
F_49 () ;
F_50 () ;
}
F_51 () ;
if ( V_111 -> V_112 != - 1 )
F_26 ( L_95 , V_111 -> V_112 ) ;
else
F_26 ( L_96 ) ;
}
}
F_26 ( L_97 ) ;
}
static void T_1 F_52 ( void )
{
struct V_110 * V_111 = & V_110 ;
struct V_115 * args = & V_111 -> args ;
T_7 V_26 = V_98 ;
T_7 V_116 , V_117 ;
args -> V_118 = ( T_7 ) V_119 ;
args -> V_120 = V_92 - V_119 ;
args -> V_121 = 0 ;
args -> V_122 = 0x60 ;
V_116 = F_31 ( args -> V_120 , V_26 ) ;
if ( V_93 != 0 ) {
args -> V_123 = V_93 ;
args -> V_124 = V_94 - args -> V_123 ;
args -> V_125 = V_116 ;
V_116 = F_31 ( args -> V_125 + args -> V_124 , V_26 ) ;
}
V_117 = F_34 ( 0x40000000 - V_97 , V_26 ) ;
if ( V_117 < V_116 )
V_117 = V_116 ;
args -> V_126 = V_117 ;
F_22 ( V_127 , V_53 ,
V_55 ) ;
F_26 ( L_98 , args -> V_118 ) ;
F_26 ( L_99 , args -> V_120 ) ;
F_26 ( L_100 , args -> V_121 ) ;
F_26 ( L_101 , args -> V_122 ) ;
F_26 ( L_102 , args -> V_126 ) ;
F_26 ( L_103 , args -> V_123 ) ;
F_26 ( L_104 , args -> V_124 ) ;
F_26 ( L_105 , args -> V_125 ) ;
F_10 ( L_106 ) ;
F_42 () ;
F_50 () ;
V_111 -> V_113 = 1 ;
for (; ; )
F_53 ( args ) ;
}
static void T_1 F_54 ( void )
{
T_3 V_128 ;
T_5 V_129 ;
T_7 V_47 , V_2 ;
T_7 V_19 = 0 , V_26 = 0x10000 ;
T_9 V_130 ;
V_38 V_11 [ 2 ] ;
F_26 ( L_107 ) ;
V_128 = F_2 ( L_77 , 1 , 1 , F_4 ( L_108 ) ) ;
F_26 ( L_109 , V_128 ) ;
if ( ! F_44 ( V_128 ) )
return;
V_130 = 0 ;
F_13 ( V_128 , L_110 , & V_130 , sizeof( V_130 ) ) ;
V_19 = F_55 ( V_130 ) ;
if ( V_19 == 0 )
return;
V_130 = 0 ;
F_13 ( V_128 , L_111 , & V_130 , sizeof( V_130 ) ) ;
V_26 = F_55 ( V_130 ) ;
V_47 = F_33 ( V_19 , V_26 , 0 ) ;
if ( V_47 == 0 ) {
F_10 ( L_112 ) ;
return;
}
V_129 = F_2 ( L_31 , 1 , 1 , F_4 ( L_108 ) ) ;
if ( ! F_56 ( V_129 ) ) {
F_10 ( L_113 , V_129 ) ;
return;
}
F_10 ( L_114 , V_47 ) ;
if ( F_6 ( L_4 , 4 , 3 , V_11 ,
F_4 ( L_115 ) ,
V_129 ,
V_47 >> 32 , V_47 & 0xffffffff ) != 0
|| ( V_11 [ 0 ] == 0 && V_11 [ 1 ] == 0 ) ) {
F_10 ( L_116 ) ;
return;
}
V_2 = ( ( ( T_7 ) V_11 [ 0 ] ) << 32 ) | V_11 [ 1 ] ;
F_10 ( L_41 ) ;
F_36 ( V_47 , V_19 ) ;
F_26 ( L_117 , V_47 ) ;
F_26 ( L_118 , V_26 ) ;
F_26 ( L_119 , V_2 ) ;
F_26 ( L_120 , ( long ) V_19 ) ;
F_17 ( V_128 , L_108 , L_121 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_128 , L_108 , L_122 ,
& V_2 , sizeof( V_2 ) ) ;
#ifdef F_57
V_131 = V_47 ;
V_132 = V_2 ;
#endif
F_26 ( L_123 ) ;
}
static void T_1 F_58 ( void )
{
T_3 V_133 ;
T_5 V_134 ;
V_38 V_47 , V_2 = 0 ;
T_8 V_16 ;
V_38 V_19 = 0 ;
F_26 ( L_124 ) ;
V_133 = F_2 ( L_77 , 1 , 1 , F_4 ( L_125 ) ) ;
F_26 ( L_126 , V_133 ) ;
if ( ! F_44 ( V_133 ) )
return;
V_16 = 0 ;
F_13 ( V_133 , L_127 , & V_16 , sizeof( V_19 ) ) ;
V_19 = F_5 ( V_16 ) ;
if ( V_19 == 0 )
return;
V_47 = F_33 ( V_19 , V_81 , 0 ) ;
if ( V_47 == 0 )
F_32 ( L_128 ) ;
V_134 = F_2 ( L_31 , 1 , 1 , F_4 ( L_125 ) ) ;
if ( ! F_56 ( V_134 ) ) {
F_10 ( L_129 , V_134 ) ;
return;
}
F_10 ( L_130 , V_47 ) ;
if ( F_6 ( L_4 , 3 , 2 , & V_2 ,
F_4 ( L_131 ) ,
V_134 , V_47 ) != 0
|| V_2 == 0 ) {
F_10 ( L_116 ) ;
return;
}
F_10 ( L_41 ) ;
F_36 ( V_47 , V_19 ) ;
V_16 = F_3 ( V_47 ) ;
F_17 ( V_133 , L_125 , L_132 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_3 ( V_2 ) ;
F_17 ( V_133 , L_125 , L_133 ,
& V_16 , sizeof( V_16 ) ) ;
if ( F_13 ( V_133 , L_134 ,
& V_16 , sizeof( V_16 ) ) != V_10 )
V_135 = true ;
#if F_59 ( V_136 ) && F_59 ( F_29 )
V_104 = V_47 ;
V_105 = V_2 ;
F_13 ( V_133 , L_135 , & V_114 , 4 ) ;
#endif
F_26 ( L_136 , V_47 ) ;
F_26 ( L_137 , V_2 ) ;
F_26 ( L_138 , ( long ) V_19 ) ;
F_26 ( L_139 ) ;
}
static void T_1 F_60 ( void )
{
T_3 V_137 ;
T_5 V_138 ;
V_38 V_2 = 0 , V_19 = 0 ;
T_7 V_47 ;
F_26 ( L_140 ) ;
V_137 = F_2 ( L_77 , 1 , 1 , F_4 ( L_141 ) ) ;
F_26 ( L_142 , V_137 ) ;
if ( ! F_44 ( V_137 ) )
return;
V_138 = F_2 ( L_31 , 1 , 1 , F_4 ( L_141 ) ) ;
if ( ! F_56 ( V_138 ) ) {
F_10 ( L_143 , V_138 ) ;
return;
}
if ( F_6 ( L_4 , 2 , 2 , & V_19 ,
F_4 ( L_144 ) ,
V_138 ) != 0 || V_19 == 0 ) {
F_10 ( L_145 ) ;
return;
}
V_47 = F_33 ( V_19 , V_81 , 0 ) ;
if ( V_47 == 0 )
F_32 ( L_146 ) ;
F_10 ( L_147 , V_47 ) ;
if ( F_6 ( L_4 , 4 , 2 , & V_2 ,
F_4 ( L_148 ) ,
V_138 , V_19 , V_47 ) != 0 || V_2 == 0 ) {
F_10 ( L_149 ) ;
return;
}
F_10 ( L_41 ) ;
F_36 ( V_47 , V_19 ) ;
F_17 ( V_137 , L_141 , L_150 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_137 , L_141 , L_151 ,
& V_19 , sizeof( V_19 ) ) ;
F_26 ( L_152 , V_47 ) ;
F_26 ( L_153 , ( long ) V_19 ) ;
F_26 ( L_154 ) ;
}
static void T_1 F_61 ( void )
{
T_3 V_34 ;
T_5 V_139 ;
char V_140 [ 64 ] , type [ 64 ] , V_141 [ 64 ] ;
char * V_84 = V_87 ;
T_7 V_47 , V_26 ;
V_38 V_142 , V_143 ;
T_7 V_144 , * V_145 ;
T_7 V_146 , V_147 ;
T_7 V_6 ;
if ( V_56 )
return;
F_26 ( L_155 ) ;
V_146 = V_72 ;
V_147 = V_146 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
V_140 [ 0 ] = 0 ;
type [ 0 ] = 0 ;
V_141 [ 0 ] = 0 ;
F_13 ( V_34 , L_156 ,
V_140 , sizeof( V_140 ) ) ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
F_13 ( V_34 , L_157 , V_141 , sizeof( V_141 ) ) ;
if ( ( type [ 0 ] == 0 ) || ( strstr ( type , L_158 ) == NULL ) )
continue;
if ( V_140 [ 0 ] != 0 ) {
if ( ( strstr ( V_140 , L_159 ) == NULL ) &&
( strstr ( V_140 , L_160 ) == NULL ) &&
( strstr ( V_140 , L_161 ) == NULL ) )
continue;
} else if ( V_141 [ 0 ] != 0 ) {
if ( ( strstr ( V_141 , L_162 ) == NULL ) &&
( strstr ( V_141 , L_163 ) == NULL ) &&
( strstr ( V_141 , L_164 ) == NULL ) )
continue;
}
if ( F_13 ( V_34 , L_165 , & V_142 ,
sizeof( V_142 ) ) == V_10 )
V_142 = 0 ;
if ( F_13 ( V_34 , L_166 , & V_143 ,
sizeof( V_143 ) ) == V_10 )
V_143 = 4UL << 20 ;
if ( F_62 ( V_148 ) || F_62 ( V_149 ) )
V_143 = 8UL << 20 ;
else
V_143 = 4UL << 20 ;
V_26 = F_63 ( V_142 , V_143 ) ;
V_47 = F_33 ( V_143 , V_26 , 1 ) ;
if ( V_47 == 0 )
F_32 ( L_167 ) ;
if ( V_47 < V_147 )
V_147 = V_47 ;
memset ( V_84 , 0 , V_89 ) ;
if ( F_2 ( L_69 , 3 , 1 , V_34 ,
V_84 , V_89 - 1 ) == V_10 ) {
F_10 ( L_168 ) ;
}
F_17 ( V_34 , V_84 , L_169 , & V_47 , sizeof( V_47 ) ) ;
F_17 ( V_34 , V_84 , L_170 , & V_143 , sizeof( V_143 ) ) ;
F_26 ( L_171 , V_84 ) ;
F_26 ( L_172 , V_34 ) ;
F_26 ( L_173 , V_47 ) ;
F_26 ( L_174 , V_143 ) ;
V_145 = ( T_7 * ) V_47 ;
for ( V_6 = 0 ; V_6 < ( V_143 >> 3 ) ; V_145 ++ , V_6 ++ ) {
V_144 = ( V_6 << V_150 ) ;
V_144 |= 0x3 ;
* V_145 = V_144 ;
}
F_10 ( L_175 , V_84 ) ;
V_139 = F_2 ( L_31 , 1 , 1 , V_84 ) ;
if ( V_139 == 0 )
F_10 ( L_176 ) ;
else
F_10 ( L_177 ) ;
F_2 ( L_4 , 6 , 0 , F_4 ( L_178 ) ,
V_139 , - 1 , V_143 ,
( V_38 ) V_47 , ( V_38 ) ( V_47 >> 32 ) ) ;
F_2 ( L_40 , 1 , 0 , V_139 ) ;
}
F_36 ( V_147 , V_146 - V_147 ) ;
V_151 = V_147 ;
V_152 = V_146 ;
F_26 ( L_179 ) ;
}
static void T_1 F_64 ( void )
{
unsigned long V_6 ;
T_3 V_34 ;
char type [ 64 ] ;
unsigned long * V_153
= ( void * ) F_65 ( V_154 ) ;
unsigned long * V_155
= ( void * ) F_65 ( V_156 ) ;
unsigned long V_157 = F_65 ( V_158 ) ;
if ( ( V_90 == V_159 ||
V_90 == V_160 ) &&
V_135 ) {
F_10 ( L_180 ) ;
return;
}
F_26 ( L_181 ) ;
F_26 ( L_182 , ( unsigned long ) V_153 ) ;
F_26 ( L_183 , * V_153 ) ;
F_26 ( L_184 ,
( unsigned long ) V_155 ) ;
F_26 ( L_185 , * V_155 ) ;
F_26 ( L_186 , V_157 ) ;
* V_153 = 0 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
unsigned int V_161 ;
T_8 V_162 ;
type [ 0 ] = 0 ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_26 ) != 0 )
continue;
if ( F_13 ( V_34 , L_89 , type , sizeof( type ) ) > 0 )
if ( strcmp ( type , L_90 ) != 0 )
continue;
V_162 = F_3 ( - 1 ) ;
F_13 ( V_34 , L_67 , & V_162 , sizeof( V_162 ) ) ;
V_161 = F_5 ( V_162 ) ;
F_26 ( L_187 , V_161 ) ;
* V_155 = ( unsigned long ) - 1 ;
if ( V_161 != V_15 . V_106 ) {
F_10 ( L_188 , V_161 ) ;
F_2 ( L_135 , 3 , 0 , V_34 ,
V_157 , V_161 ) ;
for ( V_6 = 0 ; ( V_6 < 100000000 ) &&
( * V_155 == ( ( unsigned long ) - 1 ) ) ; V_6 ++ )
F_50 () ;
if ( * V_155 == V_161 )
F_10 ( L_189 ) ;
else
F_10 ( L_190 , * V_155 ) ;
}
#ifdef F_66
else
F_10 ( L_191 , V_161 ) ;
#endif
}
F_26 ( L_192 ) ;
}
static void T_1 F_67 ( unsigned long V_163 )
{
V_9 = V_163 ;
V_15 . V_54 = F_2 ( L_77 , 1 , 1 , F_4 ( L_193 ) ) ;
if ( ! F_44 ( V_15 . V_54 ) )
F_32 ( L_194 ) ;
V_15 . V_60 = F_2 ( L_77 , 1 , 1 , F_4 ( L_32 ) ) ;
if ( ! F_44 ( V_15 . V_60 ) )
F_32 ( L_195 ) ;
V_15 . V_32 = 0 ;
}
static void T_1 F_68 ( void )
{
T_3 V_164 ;
char V_165 [ 64 ] ;
V_164 = F_2 ( L_77 , 1 , 1 , F_4 ( L_196 ) ) ;
if ( ! F_44 ( V_164 ) )
return;
if ( F_13 ( V_164 , L_157 , V_165 , sizeof( V_165 ) ) <= 0 )
return;
V_165 [ sizeof( V_165 ) - 1 ] = 0 ;
if ( strcmp ( V_165 , L_197 ) == 0 )
V_166 = V_28 ;
else if ( strncmp ( V_165 , L_198 , 12 ) == 0 ) {
V_166 = V_28 | V_44 ;
F_2 ( L_17 , 1 , 1 , L_199 ) ;
} else
return;
V_15 . V_31 = F_2 ( L_31 , 1 , 1 , F_4 ( L_200 ) ) ;
F_13 ( V_15 . V_54 , L_201 , & V_15 . V_32 ,
sizeof( V_15 . V_32 ) ) ;
V_15 . V_32 = F_5 ( V_15 . V_32 ) ;
if ( ! F_56 ( V_15 . V_31 ) || ! F_56 ( V_15 . V_32 ) )
V_166 &= ~ V_28 ;
}
static void T_1 F_69 ( void )
{
char * V_84 = V_167 ;
char type [ 16 ] ;
T_3 V_168 ;
T_8 V_16 ;
if ( F_13 ( V_15 . V_54 , L_202 , & V_16 , sizeof( V_16 ) ) <= 0 )
F_32 ( L_203 ) ;
V_15 . stdout = F_5 ( V_16 ) ;
memset ( V_84 , 0 , 256 ) ;
F_2 ( L_204 , 3 , 1 , V_15 . stdout , V_84 , 255 ) ;
F_10 ( L_205 , V_167 ) ;
F_17 ( V_15 . V_54 , L_193 , L_206 ,
V_84 , strlen ( V_84 ) + 1 ) ;
V_168 = F_2 ( L_207 , 1 , 1 , V_15 . stdout ) ;
if ( V_168 != V_10 ) {
V_16 = F_3 ( V_168 ) ;
F_17 ( V_15 . V_54 , L_193 , L_208 ,
& V_16 , sizeof( V_16 ) ) ;
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_168 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_209 ) == 0 )
F_17 ( V_168 , V_84 , L_210 , NULL , 0 ) ;
}
}
static int T_1 F_70 ( void )
{
char V_169 [ 256 ] ;
int V_170 , V_6 = 0 ;
#ifdef F_23
T_3 V_171 ;
int V_40 ;
#endif
V_170 = F_13 ( V_15 . V_60 , L_156 ,
V_169 , sizeof( V_169 ) - 1 ) ;
if ( V_170 > 0 ) {
V_169 [ V_170 ] = 0 ;
while ( V_6 < V_170 ) {
char * V_13 = & V_169 [ V_6 ] ;
int V_172 = strlen ( V_13 ) ;
if ( V_172 == 0 )
break;
if ( strstr ( V_13 , L_211 ) ||
strstr ( V_13 , L_212 ) )
return V_173 ;
#ifdef F_23
if ( strstr ( V_13 , L_213 ) ||
strstr ( V_13 , L_214 ) )
return V_174 ;
#endif
V_6 += V_172 + 1 ;
}
}
#ifdef F_23
if ( F_44 ( F_2 ( L_77 , 1 , 1 , F_4 ( L_108 ) ) ) )
return V_99 ;
V_170 = F_13 ( V_15 . V_60 , L_25 ,
V_169 , sizeof( V_169 ) - 1 ) ;
if ( V_170 <= 0 )
return V_174 ;
if ( strcmp ( V_169 , L_215 ) )
return V_174 ;
V_171 = F_2 ( L_77 , 1 , 1 , F_4 ( L_125 ) ) ;
if ( ! F_44 ( V_171 ) )
return V_174 ;
V_40 = F_14 ( V_171 , L_216 ) ;
if ( V_40 != V_10 ) {
F_26 ( L_217 ) ;
return V_160 ;
}
return V_159 ;
#else
return V_174 ;
#endif
}
static int T_1 F_71 ( T_5 V_175 , int V_6 , int V_77 , int V_176 , int V_177 )
{
return F_2 ( L_4 , 6 , 1 , F_4 ( L_218 ) , V_175 , V_6 , V_177 , V_176 , V_77 ) ;
}
static void T_1 F_72 ( void )
{
char type [ 16 ] , * V_84 ;
T_3 V_34 ;
T_5 V_175 ;
int V_6 ;
static unsigned char V_178 [] = {
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
const unsigned char * V_179 ;
F_26 ( L_219 ) ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_209 ) != 0 )
continue;
V_84 = V_87 ;
memset ( V_84 , 0 , V_89 ) ;
if ( F_2 ( L_69 , 3 , 1 , V_34 , V_84 ,
V_89 - 10 ) == V_10 )
continue;
F_10 ( L_220 , V_84 ) ;
V_175 = F_2 ( L_31 , 1 , 1 , V_84 ) ;
if ( V_175 == 0 ) {
F_10 ( L_221 ) ;
continue;
}
F_10 ( L_189 ) ;
F_17 ( V_34 , V_84 , L_222 , NULL , 0 ) ;
V_179 = V_178 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ , V_179 += 3 )
if ( F_71 ( V_175 , V_6 , V_179 [ 0 ] , V_179 [ 1 ] ,
V_179 [ 2 ] ) != 0 )
break;
#ifdef F_73
V_179 = F_74 ( V_180 . V_179 ) ;
for ( V_6 = 0 ; V_6 < V_180 . V_181 ; V_6 ++ , V_179 += 3 )
if ( F_71 ( V_175 , V_6 + 32 , V_179 [ 0 ] , V_179 [ 1 ] ,
V_179 [ 2 ] ) != 0 )
break;
#endif
#ifdef F_75
if ( F_13 ( V_34 , L_210 , NULL , 0 ) !=
V_10 ) {
V_38 V_182 , V_183 , V_184 , V_69 ;
F_10 ( L_223 ) ;
F_13 ( V_34 , L_224 , & V_182 , 4 ) ;
F_13 ( V_34 , L_225 , & V_183 , 4 ) ;
F_13 ( V_34 , L_226 , & V_184 , 4 ) ;
F_13 ( V_34 , L_227 , & V_69 , 4 ) ;
F_10 ( L_228 ,
V_182 , V_183 , V_184 , V_69 ) ;
F_76 ( V_182 , V_183 , 8 , V_184 , V_69 ) ;
}
#endif
}
}
static void T_1 * F_77 ( unsigned long * V_185 , unsigned long * V_186 ,
unsigned long V_187 , unsigned long V_26 )
{
void * V_29 ;
* V_185 = F_78 ( * V_185 , V_26 ) ;
while ( ( * V_185 + V_187 ) > * V_186 ) {
unsigned long V_188 , V_189 ;
F_26 ( L_229 ,
V_68 ) ;
V_188 = V_71 - V_68 ;
if ( V_188 > V_190 )
V_188 = V_190 ;
if ( V_188 < V_81 )
F_32 ( L_230
L_231 ) ;
V_189 = F_30 ( V_188 , 0 ) ;
if ( V_189 == 0 )
F_32 ( L_230
L_232 ) ;
* V_186 = V_189 + V_188 ;
}
V_29 = ( void * ) * V_185 ;
* V_185 += V_187 ;
return V_29 ;
}
static unsigned long T_1 F_79 ( char * V_39 )
{
char * V_22 , * V_191 ;
V_22 = V_191 = ( char * ) V_192 ;
V_22 += 4 ;
while ( V_22 < ( char * ) V_193 ) {
if ( strcmp ( V_22 , V_39 ) == 0 )
return V_22 - V_191 ;
V_22 += strlen ( V_22 ) + 1 ;
}
return 0 ;
}
static void T_1 F_80 ( T_3 V_34 ,
unsigned long * V_185 ,
unsigned long * V_186 )
{
char * V_194 , * V_195 , * V_196 ;
unsigned long V_197 ;
T_3 V_198 ;
V_196 = ( char * ) V_192 ;
V_194 = L_233 ;
for (; ; ) {
V_195 = F_77 ( V_185 , V_186 , V_199 , 1 ) ;
if ( F_2 ( L_234 , 3 , 1 , V_34 , V_194 , V_195 ) != 1 ) {
* V_185 = ( unsigned long ) V_195 ;
break;
}
if ( strcmp ( V_195 , L_65 ) == 0 ) {
* V_185 = ( unsigned long ) V_195 ;
V_194 = L_65 ;
continue;
}
V_197 = F_79 ( V_195 ) ;
if ( V_197 != 0 ) {
* V_185 = ( unsigned long ) V_195 ;
V_195 = V_196 + V_197 ;
} else {
* V_185 = ( unsigned long ) V_195 + strlen ( V_195 ) + 1 ;
V_193 = * V_185 ;
}
V_194 = V_195 ;
}
V_198 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_198 != 0 ) {
F_80 ( V_198 , V_185 , V_186 ) ;
V_198 = F_2 ( L_9 , 1 , 1 , V_198 ) ;
}
}
static void T_1 F_81 ( T_3 V_34 , unsigned long * V_185 ,
unsigned long * V_186 )
{
T_3 V_198 ;
char * V_195 , * V_194 , * V_196 , * V_13 , * V_200 , * V_201 , * V_84 ;
unsigned long V_197 ;
unsigned char * V_202 ;
static char V_35 [ V_199 ] ;
int V_52 , V_188 , V_203 = 0 ;
F_82 ( V_204 , V_185 , V_186 ) ;
V_195 = ( char * ) * V_185 ;
V_188 = * V_186 - * V_185 ;
if ( V_188 > 255 )
V_188 = 255 ;
V_52 = F_2 ( L_69 , 3 , 1 , V_34 , V_195 , V_188 ) ;
if ( V_52 >= 0 ) {
if ( V_52 >= V_188 ) {
if ( V_52 >= * V_186 - * V_185 )
V_195 = F_77 ( V_185 , V_186 , V_52 + 1 , 1 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_195 , V_52 ) ;
}
V_195 [ V_52 ] = '\0' ;
for ( V_201 = V_13 = V_195 , V_200 = V_195 + V_52 ; V_13 < V_200 ; V_13 ++ ) {
if ( * V_13 == '/' )
V_201 = V_195 ;
else if ( * V_13 != 0 )
* V_201 ++ = * V_13 ;
}
* V_201 = 0 ;
* V_185 = F_78 ( ( unsigned long ) V_201 + 1 , 4 ) ;
}
V_84 = V_87 ;
memset ( V_84 , 0 , V_89 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_84 , V_89 - 1 ) ;
V_194 = L_233 ;
V_196 = ( char * ) V_192 ;
for (; ; ) {
if ( F_2 ( L_234 , 3 , 1 , V_34 , V_194 ,
V_35 ) != 1 )
break;
if ( strcmp ( V_35 , L_65 ) == 0 ) {
V_194 = L_65 ;
continue;
}
V_197 = F_79 ( V_35 ) ;
if ( V_197 == 0 ) {
F_10 ( L_235
L_236 , V_35 , V_84 ) ;
break;
}
V_194 = V_196 + V_197 ;
V_52 = F_2 ( L_12 , 2 , 1 , V_34 , V_35 ) ;
if ( V_52 == V_10 )
continue;
F_82 ( V_205 , V_185 , V_186 ) ;
F_82 ( V_52 , V_185 , V_186 ) ;
F_82 ( V_197 , V_185 , V_186 ) ;
V_202 = F_77 ( V_185 , V_186 , V_52 , 4 ) ;
F_2 ( L_11 , 4 , 1 , V_34 , V_35 , V_202 , V_52 ) ;
* V_185 = F_78 ( * V_185 , 4 ) ;
if ( ! strcmp ( V_35 , L_237 ) )
V_203 = 1 ;
}
if ( ! V_203 ) {
V_197 = F_79 ( L_238 ) ;
if ( V_197 == 0 )
F_10 ( L_235
L_239 , V_84 ) ;
else {
F_82 ( V_205 , V_185 , V_186 ) ;
F_82 ( 4 , V_185 , V_186 ) ;
F_82 ( V_197 , V_185 , V_186 ) ;
V_202 = F_77 ( V_185 , V_186 , 4 , 4 ) ;
* ( T_8 * ) V_202 = F_3 ( V_34 ) ;
}
}
V_198 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_198 != 0 ) {
F_81 ( V_198 , V_185 , V_186 ) ;
V_198 = F_2 ( L_9 , 1 , 1 , V_198 ) ;
}
F_82 ( V_206 , V_185 , V_186 ) ;
}
static void T_1 F_83 ( void )
{
T_3 V_60 ;
unsigned long V_185 , V_186 , V_188 ;
struct V_207 * V_208 ;
char * V_195 ;
T_7 * V_209 ;
V_188 = V_71 - V_68 - 0x4000 ;
if ( V_188 > V_190 )
V_188 = V_190 ;
F_26 ( L_240 , V_68 ) ;
V_185 = ( unsigned long ) F_30 ( V_188 , V_81 ) ;
if ( V_185 == 0 )
F_32 ( L_241 ) ;
V_186 = V_185 + V_188 ;
V_60 = F_2 ( L_9 , 1 , 1 , ( T_3 ) 0 ) ;
if ( V_60 == ( T_3 ) 0 )
F_32 ( L_242 ) ;
V_185 = F_78 ( V_185 , 4 ) ;
V_208 = F_77 ( & V_185 , & V_186 ,
sizeof( struct V_207 ) , 4 ) ;
V_210 = ( unsigned long ) V_208 ;
V_209 = F_77 ( & V_185 , & V_186 , sizeof( V_83 ) , 8 ) ;
V_185 = F_40 ( V_185 ) ;
V_192 = V_185 ;
V_185 += 4 ;
V_195 = F_77 ( & V_185 , & V_186 , 16 , 1 ) ;
strcpy ( V_195 , L_238 ) ;
V_185 = ( unsigned long ) V_195 + strlen ( V_195 ) + 1 ;
F_10 ( L_243 ) ;
F_80 ( V_60 , & V_185 , & V_186 ) ;
V_193 = V_185 ;
V_185 = F_40 ( V_185 ) ;
V_211 = V_185 ;
F_10 ( L_244 ) ;
F_81 ( V_60 , & V_185 , & V_186 ) ;
F_82 ( V_212 , & V_185 , & V_186 ) ;
V_213 = F_40 ( V_185 ) ;
V_208 -> V_214 = F_3 ( V_15 . V_106 ) ;
V_208 -> V_215 = F_3 ( V_216 ) ;
V_208 -> V_217 = F_3 ( V_213 - V_210 ) ;
V_208 -> V_218 = F_3 ( V_211 - V_210 ) ;
V_208 -> V_219 = F_3 ( V_192 - V_210 ) ;
V_208 -> V_220 = F_3 ( V_193 - V_192 ) ;
V_208 -> V_221 = F_3 ( ( ( unsigned long ) V_209 ) - V_210 ) ;
V_208 -> V_165 = F_3 ( V_222 ) ;
V_208 -> V_223 = F_3 ( 0x10 ) ;
memcpy ( V_209 , V_83 , sizeof( V_83 ) ) ;
#ifdef F_39
{
int V_6 ;
F_10 ( L_245 ) ;
for ( V_6 = 0 ; V_6 < V_80 ; V_6 ++ )
F_10 ( L_246 ,
F_55 ( V_83 [ V_6 ] . V_47 ) ,
F_55 ( V_83 [ V_6 ] . V_19 ) ) ;
}
#endif
V_80 = V_82 ;
F_10 ( L_247 ,
V_192 , V_193 ) ;
F_10 ( L_248 ,
V_211 , V_213 ) ;
}
static void T_1 F_84 ( void )
{
T_3 V_224 ;
V_38 V_225 = 0x01002000 ;
V_38 V_226 [ 6 ] ;
char * V_227 ;
V_227 = L_249 ;
V_224 = F_2 ( L_77 , 1 , 1 , F_4 ( V_227 ) ) ;
if ( ! F_44 ( V_224 ) ) {
V_227 = L_250 ;
V_224 = F_2 ( L_77 , 1 , 1 , F_4 ( V_227 ) ) ;
V_225 = 0x01003000 ;
}
if ( ! F_44 ( V_224 ) )
return;
if ( F_14 ( V_224 , L_251 ) != 12 )
return;
if ( F_13 ( V_224 , L_251 , V_226 , sizeof( V_226 ) )
== V_10 )
return;
if ( V_226 [ 0 ] != 0x1 ||
V_226 [ 1 ] != 0xf4000000 ||
V_226 [ 2 ] != 0x00010000 )
return;
F_10 ( L_252 ) ;
V_226 [ 0 ] = 0x1 ;
V_226 [ 1 ] = 0x0 ;
V_226 [ 2 ] = V_225 ;
V_226 [ 3 ] = 0x0 ;
V_226 [ 4 ] = 0x0 ;
V_226 [ 5 ] = 0x00010000 ;
F_17 ( V_224 , V_227 , L_251 ,
V_226 , sizeof( V_226 ) ) ;
}
static void T_1 F_85 ( void )
{
T_3 V_228 ;
V_38 V_229 [ 4 ] ;
char * V_227 = L_253 ;
V_38 V_230 , V_231 ;
V_228 = F_2 ( L_77 , 1 , 1 , F_4 ( V_227 ) ) ;
if ( ! F_44 ( V_228 ) )
return;
if ( F_14 ( V_228 , L_67 ) != 8 )
return;
F_13 ( V_15 . V_60 , L_60 , & V_230 , sizeof( V_230 ) ) ;
F_13 ( V_15 . V_60 , L_61 , & V_231 , sizeof( V_231 ) ) ;
if ( ( V_230 != 2 ) || ( V_231 != 2 ) )
return;
if ( F_13 ( V_228 , L_67 , V_229 , sizeof( V_229 ) ) == V_10 )
return;
if ( V_229 [ 0 ] != V_232 || V_229 [ 1 ] != V_233 )
return;
F_10 ( L_254 ) ;
V_229 [ 0 ] = 0x0 ;
V_229 [ 1 ] = V_232 ;
V_229 [ 2 ] = 0x0 ;
V_229 [ 3 ] = V_233 ;
F_17 ( V_228 , V_227 , L_67 , V_229 , sizeof( V_229 ) ) ;
}
static void T_1 F_86 ( void )
{
T_3 V_234 ;
V_38 V_235 [ 6 ] ;
V_38 V_225 = 0x01006000 ;
char * V_227 ;
int V_96 ;
V_227 = L_255 ;
V_234 = F_2 ( L_77 , 1 , 1 , F_4 ( V_227 ) ) ;
if ( ! F_44 ( V_234 ) ) {
V_227 = L_256 ;
V_234 = F_2 ( L_77 , 1 , 1 , F_4 ( V_227 ) ) ;
V_225 = 0x01003000 ;
}
if ( F_44 ( V_234 ) ) {
V_96 = F_14 ( V_234 , L_251 ) ;
if ( V_96 == 0 || V_96 == V_10 ) {
F_10 ( L_257 ) ;
V_235 [ 0 ] = 0x1 ;
V_235 [ 1 ] = 0x0 ;
V_235 [ 2 ] = V_225 ;
V_235 [ 3 ] = 0x0 ;
V_235 [ 4 ] = 0x0 ;
V_235 [ 5 ] = 0x00010000 ;
F_17 ( V_234 , V_227 , L_251 , V_235 , sizeof( V_235 ) ) ;
}
}
V_227 = L_258 ;
V_234 = F_2 ( L_77 , 1 , 1 , F_4 ( V_227 ) ) ;
if ( F_44 ( V_234 ) ) {
F_10 ( L_259 ) ;
V_235 [ 0 ] = 14 ;
V_235 [ 1 ] = 0x0 ;
F_17 ( V_234 , V_227 , L_260 , V_235 , 2 * sizeof( V_38 ) ) ;
F_10 ( L_261 ) ;
V_96 = F_13 ( V_234 , L_262 , V_235 , sizeof( V_38 ) ) ;
if ( V_96 == sizeof( V_38 ) ) {
V_235 [ 0 ] &= ~ 0x5 ;
F_17 ( V_234 , V_227 , L_262 , V_235 , sizeof( V_38 ) ) ;
}
}
}
static void T_1 F_87 ( void )
{
T_3 V_236 , V_237 , V_238 ;
V_38 V_239 ;
V_38 V_240 [ 2 ] ;
V_38 V_241 ;
V_236 = F_2 ( L_77 , 1 , 1 , F_4 ( L_263 ) ) ;
if ( ! F_44 ( V_236 ) )
return;
V_237 = F_2 ( L_77 , 1 , 1 , F_4 ( L_264 ) ) ;
if ( ! F_44 ( V_237 ) )
return;
V_238 = F_2 ( L_77 , 1 , 1 , F_4 ( L_265 ) ) ;
if ( ! F_44 ( V_238 ) )
return;
if ( F_13 ( V_236 , L_266 , & V_239 , sizeof( V_239 ) )
== V_10 )
return;
if ( V_239 < 0x35 || V_239 > 0x39 )
return;
if ( F_14 ( V_237 , L_260 ) > 0 )
return;
F_10 ( L_267 ) ;
V_240 [ 0 ] = 0 ;
V_240 [ 1 ] = 1 ;
F_17 ( V_237 , L_264 , L_260 ,
& V_240 , sizeof( V_240 ) ) ;
V_241 = ( V_38 ) V_238 ;
F_17 ( V_237 , L_264 , L_268 ,
& V_241 , sizeof( V_241 ) ) ;
}
static void T_1 F_88 ( void )
{
V_38 V_34 ;
char V_235 [ 64 ] ;
int V_242 ;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_269 ) ) ;
if ( ! F_44 ( V_34 ) )
return;
V_242 = F_13 ( V_34 , L_270 , V_235 , sizeof( V_235 ) ) ;
if ( ! V_242 )
return;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_271 ) ) ;
if ( ! F_44 ( V_34 ) ) {
F_10 ( L_272 ) ;
F_2 ( L_17 , 1 , 1 ,
L_273
L_274
L_275
L_276
L_277
L_278
L_279
L_280
L_281
L_282
L_283
L_284
L_285 ) ;
} ;
V_34 = F_2 ( L_77 , 1 , 1 ,
F_4 ( L_286 ) ) ;
if ( ! F_44 ( V_34 ) ) {
F_10 ( L_287 ) ;
F_2 ( L_17 , 1 , 1 ,
L_288
L_274
L_289
L_290
L_291
L_292
L_285
L_293
L_294
L_295
L_296 ) ;
}
}
static void T_1 F_89 ( void )
{
int V_243 [ 3 ] = { 2 , 2 , 0 } ;
int V_244 [ 3 * 16 ] = { 3 , 0 , 0 , 3 , 1 , 0 , 3 , 2 , 0 , 3 , 3 , 0 ,
3 , 4 , 0 , 3 , 5 , 0 , 3 , 6 , 0 , 3 , 7 , 0 ,
3 , 8 , 0 , 3 , 9 , 0 , 3 , 10 , 0 , 3 , 11 , 0 ,
3 , 12 , 0 , 3 , 13 , 0 , 3 , 14 , 0 , 3 , 15 , 0 } ;
V_38 V_34 ;
char V_235 [ 64 ] ;
int V_242 , V_170 ;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_32 ) ) ;
if ( ! F_44 ( V_34 ) )
return;
V_242 = F_13 ( V_34 , L_157 , V_235 , sizeof( V_235 ) ) ;
if ( V_242 == V_10 )
return;
if ( strcmp ( V_235 , L_297 ) )
return;
F_10 ( L_298 ) ;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_32 ) ) ;
V_242 = F_13 ( V_34 , L_25 , V_235 , sizeof( V_235 ) ) ;
if ( V_242 != V_10 && ( strcmp ( V_235 , L_215 ) == 0 ) )
F_17 ( V_34 , L_32 , L_25 , L_299 , sizeof( L_299 ) ) ;
V_242 = F_13 ( V_34 , L_300 , V_235 , sizeof( V_235 ) ) ;
if ( V_242 != V_10 && ( strstr ( V_235 , L_301 ) ) )
F_17 ( V_34 , L_32 , L_300 ,
L_302 ,
sizeof( L_302 ) ) ;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_303 ) ) ;
if ( F_44 ( V_34 ) ) {
V_170 = F_14 ( V_34 , L_260 ) ;
if ( V_170 == 12 ) {
F_10 ( L_304 ) ;
F_17 ( V_34 , L_305 , L_260 ,
V_244 , sizeof( V_244 ) ) ;
}
}
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_306 ) ) ;
if ( F_44 ( V_34 ) ) {
V_242 = F_13 ( V_34 , L_260 , V_235 , sizeof( V_235 ) ) ;
if ( V_242 == V_10 ) {
F_10 ( L_307 ) ;
F_17 ( V_34 , L_306 , L_260 ,
V_243 , sizeof( V_243 ) ) ;
}
}
F_88 () ;
}
static void T_1 F_90 ( void )
{
F_84 () ;
F_85 () ;
F_86 () ;
F_87 () ;
F_89 () ;
}
static void T_1 F_91 ( void )
{
T_8 V_245 ;
T_5 V_246 ;
T_3 V_247 ;
V_245 = 0 ;
if ( F_13 ( V_15 . V_54 , L_26 , & V_245 , sizeof( V_245 ) ) <= 0 )
return;
V_246 = F_5 ( V_245 ) ;
V_247 = F_2 ( L_207 , 1 , 1 , V_246 ) ;
F_13 ( V_247 , L_67 , & V_245 , sizeof( V_245 ) ) ;
V_15 . V_106 = F_5 ( V_245 ) ;
F_26 ( L_308 , V_15 . V_106 ) ;
}
static void T_1 F_92 ( unsigned long V_248 , unsigned long V_249 )
{
#ifdef F_93
if ( V_248 && V_249 && V_249 != 0xdeadbeef ) {
T_9 V_16 ;
V_93 = F_94 ( V_248 ) ? F_95 ( V_248 ) : V_248 ;
V_94 = V_93 + V_249 ;
V_16 = F_37 ( V_93 ) ;
F_17 ( V_15 . V_54 , L_193 , L_309 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_37 ( V_94 ) ;
F_17 ( V_15 . V_54 , L_193 , L_310 ,
& V_16 , sizeof( V_16 ) ) ;
F_36 ( V_93 ,
V_94 - V_93 ) ;
F_26 ( L_311 , V_93 ) ;
F_26 ( L_312 , V_94 ) ;
}
#endif
}
static void F_96 ( void )
{
}
static void F_97 ( void )
{
}
static void F_98 ( unsigned long V_250 , unsigned long V_251 )
{
unsigned long V_6 ;
unsigned long * V_252 ;
asm volatile("addi %0,2,-0x8000" : "=b" (toc_entry));
for ( V_6 = 0 ; V_6 < V_251 ; V_6 ++ ) {
* V_252 = * V_252 + V_250 ;
V_252 ++ ;
}
}
static void F_96 ( void )
{
unsigned long V_250 = F_99 () ;
unsigned long V_251 =
( V_253 - V_254 ) / sizeof( long ) ;
F_98 ( V_250 , V_251 ) ;
F_50 () ;
}
static void F_97 ( void )
{
unsigned long V_250 = F_99 () ;
unsigned long V_251 =
( V_253 - V_254 ) / sizeof( long ) ;
F_50 () ;
F_98 ( - V_250 , V_251 ) ;
}
unsigned long T_1 F_100 ( unsigned long V_248 , unsigned long V_249 ,
unsigned long V_163 ,
unsigned long V_255 , unsigned long V_256 ,
unsigned long V_257 )
{
unsigned long V_208 ;
#ifdef F_101
unsigned long V_250 = F_99 () ;
F_102 ( V_250 ) ;
#else
F_96 () ;
#endif
memset ( & V_258 , 0 , V_259 - V_258 ) ;
F_67 ( V_163 ) ;
F_68 () ;
F_69 () ;
F_10 ( L_313 , V_260 ) ;
V_90 = F_70 () ;
F_10 ( L_314 , V_90 ) ;
#ifndef F_103
if ( V_261 > 0 )
F_32 ( L_315 ) ;
#endif
F_92 ( V_248 , V_249 ) ;
#if F_59 ( V_262 ) || F_59 ( V_136 )
if ( V_90 == V_159 ||
V_90 == V_160 )
F_27 () ;
#endif
if ( V_90 != V_173 )
F_104 ( 0 , V_257 , 0x100 , 0 ) ;
F_20 () ;
F_38 () ;
F_91 () ;
F_72 () ;
#if F_59 ( F_23 ) && F_59 ( F_29 )
if ( V_90 == V_159 )
F_61 () ;
#endif
if ( V_90 != V_173 &&
V_90 != V_99 )
F_58 () ;
#ifdef V_136
#ifdef F_29
if ( V_90 == V_160 ) {
F_43 () ;
if ( V_90 == V_99 ) {
F_48 () ;
F_52 () ;
}
} else
#endif
if ( V_90 == V_99 )
F_54 () ;
#endif
#ifdef F_23
F_60 () ;
#endif
if ( V_90 != V_173 &&
V_90 != V_99 )
F_64 () ;
if ( V_58 ) {
T_9 V_16 = F_37 ( V_58 ) ;
F_17 ( V_15 . V_54 , L_193 , L_316 ,
& V_16 , sizeof( V_16 ) ) ;
}
#ifdef F_23
if ( V_56 )
F_17 ( V_15 . V_54 , L_193 , L_317 ,
NULL , 0 ) ;
if ( V_57 )
F_17 ( V_15 . V_54 , L_193 , L_318 ,
NULL , 0 ) ;
if ( V_151 ) {
F_17 ( V_15 . V_54 , L_193 , L_319 ,
& V_151 ,
sizeof( V_151 ) ) ;
F_17 ( V_15 . V_54 , L_193 , L_320 ,
& V_152 ,
sizeof( V_152 ) ) ;
}
#endif
F_90 () ;
F_10 ( L_321 ) ;
F_83 () ;
if ( V_90 != V_173 &&
V_90 != V_99 )
F_42 () ;
F_10 ( L_322 ) ;
F_2 ( L_323 , 0 , 0 ) ;
V_208 = V_210 ;
if ( V_90 != V_99 ) {
F_10 ( L_324 ) ;
F_26 ( L_325 , V_208 ) ;
}
#ifdef F_101
F_102 ( - V_250 ) ;
#else
F_97 () ;
#endif
#ifdef F_57
F_105 ( V_208 , V_257 , 0 , 0 , 0 ,
V_131 , V_132 ) ;
#else
F_105 ( V_208 , V_257 , 0 , 0 , 0 , 0 , 0 ) ;
#endif
return 0 ;
}
