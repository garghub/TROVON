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
T_3 V_96 ;
T_5 V_97 ;
T_7 V_47 , V_2 ;
T_7 V_19 = 0 , V_26 = 0x10000 ;
T_9 V_98 ;
V_38 V_11 [ 2 ] ;
F_26 ( L_77 ) ;
V_96 = F_2 ( L_78 , 1 , 1 , F_4 ( L_79 ) ) ;
F_26 ( L_80 , V_96 ) ;
if ( ! F_44 ( V_96 ) )
return;
V_98 = 0 ;
F_13 ( V_96 , L_81 , & V_98 , sizeof( V_98 ) ) ;
V_19 = F_45 ( V_98 ) ;
if ( V_19 == 0 )
return;
V_98 = 0 ;
F_13 ( V_96 , L_82 , & V_98 , sizeof( V_98 ) ) ;
V_26 = F_45 ( V_98 ) ;
V_47 = F_33 ( V_19 , V_26 , 0 ) ;
if ( V_47 == 0 ) {
F_10 ( L_83 ) ;
return;
}
V_97 = F_2 ( L_31 , 1 , 1 , F_4 ( L_79 ) ) ;
if ( ! F_46 ( V_97 ) ) {
F_10 ( L_84 , V_97 ) ;
return;
}
F_10 ( L_85 , V_47 ) ;
if ( F_6 ( L_4 , 4 , 3 , V_11 ,
F_4 ( L_86 ) ,
V_97 ,
V_47 >> 32 , V_47 & 0xffffffff ) != 0
|| ( V_11 [ 0 ] == 0 && V_11 [ 1 ] == 0 ) ) {
F_10 ( L_87 ) ;
return;
}
V_2 = ( ( ( T_7 ) V_11 [ 0 ] ) << 32 ) | V_11 [ 1 ] ;
F_10 ( L_41 ) ;
F_36 ( V_47 , V_19 ) ;
F_26 ( L_88 , V_47 ) ;
F_26 ( L_89 , V_26 ) ;
F_26 ( L_90 , V_2 ) ;
F_26 ( L_91 , ( long ) V_19 ) ;
F_17 ( V_96 , L_79 , L_92 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_96 , L_79 , L_93 ,
& V_2 , sizeof( V_2 ) ) ;
#ifdef F_47
V_99 = V_47 ;
V_100 = V_2 ;
#endif
F_26 ( L_94 ) ;
}
static void T_1 F_48 ( void )
{
T_3 V_101 ;
T_5 V_102 ;
V_38 V_47 , V_2 = 0 ;
T_8 V_16 ;
V_38 V_19 = 0 ;
F_26 ( L_95 ) ;
V_101 = F_2 ( L_78 , 1 , 1 , F_4 ( L_96 ) ) ;
F_26 ( L_97 , V_101 ) ;
if ( ! F_44 ( V_101 ) )
return;
V_16 = 0 ;
F_13 ( V_101 , L_98 , & V_16 , sizeof( V_19 ) ) ;
V_19 = F_5 ( V_16 ) ;
if ( V_19 == 0 )
return;
V_47 = F_33 ( V_19 , V_81 , 0 ) ;
if ( V_47 == 0 )
F_32 ( L_99 ) ;
V_102 = F_2 ( L_31 , 1 , 1 , F_4 ( L_96 ) ) ;
if ( ! F_46 ( V_102 ) ) {
F_10 ( L_100 , V_102 ) ;
return;
}
F_10 ( L_101 , V_47 ) ;
if ( F_6 ( L_4 , 3 , 2 , & V_2 ,
F_4 ( L_102 ) ,
V_102 , V_47 ) != 0
|| V_2 == 0 ) {
F_10 ( L_87 ) ;
return;
}
F_10 ( L_41 ) ;
F_36 ( V_47 , V_19 ) ;
V_16 = F_3 ( V_47 ) ;
F_17 ( V_101 , L_96 , L_103 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_3 ( V_2 ) ;
F_17 ( V_101 , L_96 , L_104 ,
& V_16 , sizeof( V_16 ) ) ;
if ( F_13 ( V_101 , L_105 ,
& V_16 , sizeof( V_16 ) ) != V_10 )
V_103 = true ;
F_26 ( L_106 , V_47 ) ;
F_26 ( L_107 , V_2 ) ;
F_26 ( L_108 , ( long ) V_19 ) ;
F_26 ( L_109 ) ;
}
static void T_1 F_49 ( void )
{
T_3 V_104 ;
T_5 V_105 ;
V_38 V_2 = 0 , V_19 = 0 , V_106 = 0 ;
T_7 V_47 ;
T_8 V_16 ;
F_26 ( L_110 ) ;
V_104 = F_2 ( L_78 , 1 , 1 , F_4 ( L_111 ) ) ;
F_26 ( L_112 , V_104 ) ;
if ( ! F_44 ( V_104 ) )
return;
V_105 = F_2 ( L_31 , 1 , 1 , F_4 ( L_111 ) ) ;
if ( ! F_46 ( V_105 ) ) {
F_10 ( L_113 , V_105 ) ;
return;
}
if ( F_13 ( V_104 , L_114 ,
& V_16 , sizeof( V_16 ) ) != V_10 ) {
if ( F_6 ( L_4 , 2 , 2 , & V_106 ,
F_4 ( L_115 ) ,
V_105 ) != 0 || V_106 == 0 ) {
F_10 ( L_116 ) ;
return;
}
if ( F_6 ( L_4 , 2 , 2 , & V_19 ,
F_4 ( L_117 ) ,
V_105 ) != 0 || V_19 == 0 ) {
F_10 ( L_118 ) ;
return;
}
} else {
if ( F_6 ( L_4 , 2 , 2 , & V_19 ,
F_4 ( L_119 ) ,
V_105 ) != 0 || V_19 == 0 ) {
F_10 ( L_120 ) ;
return;
}
}
V_47 = F_33 ( V_19 , V_81 , 0 ) ;
if ( V_47 == 0 )
F_32 ( L_121 ) ;
F_10 ( L_122 , V_47 ) ;
memset ( ( void * ) V_47 , 0 , V_19 ) ;
if ( F_6 ( L_4 , 4 , 2 , & V_2 ,
F_4 ( L_123 ) ,
V_105 , V_19 , V_47 ) != 0 || V_2 == 0 ) {
F_10 ( L_124 ) ;
return;
}
F_10 ( L_41 ) ;
F_36 ( V_47 , V_19 ) ;
F_17 ( V_104 , L_111 , L_125 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_104 , L_111 , L_126 ,
& V_19 , sizeof( V_19 ) ) ;
F_26 ( L_127 , V_47 ) ;
F_26 ( L_128 , ( long ) V_19 ) ;
F_26 ( L_129 ) ;
}
static void T_1 F_50 ( void )
{
T_3 V_34 ;
T_5 V_107 ;
char V_108 [ 64 ] , type [ 64 ] , V_109 [ 64 ] ;
char * V_84 = V_87 ;
T_7 V_47 , V_26 ;
V_38 V_110 , V_111 ;
T_7 V_112 , * V_113 ;
T_7 V_114 , V_115 ;
T_7 V_6 ;
if ( V_56 )
return;
F_26 ( L_130 ) ;
V_114 = V_72 ;
V_115 = V_114 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
V_108 [ 0 ] = 0 ;
type [ 0 ] = 0 ;
V_109 [ 0 ] = 0 ;
F_13 ( V_34 , L_131 ,
V_108 , sizeof( V_108 ) ) ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
F_13 ( V_34 , L_132 , V_109 , sizeof( V_109 ) ) ;
if ( ( type [ 0 ] == 0 ) || ( strstr ( type , L_133 ) == NULL ) )
continue;
if ( V_108 [ 0 ] != 0 ) {
if ( ( strstr ( V_108 , L_134 ) == NULL ) &&
( strstr ( V_108 , L_135 ) == NULL ) &&
( strstr ( V_108 , L_136 ) == NULL ) )
continue;
} else if ( V_109 [ 0 ] != 0 ) {
if ( ( strstr ( V_109 , L_137 ) == NULL ) &&
( strstr ( V_109 , L_138 ) == NULL ) &&
( strstr ( V_109 , L_139 ) == NULL ) )
continue;
}
if ( F_13 ( V_34 , L_140 , & V_110 ,
sizeof( V_110 ) ) == V_10 )
V_110 = 0 ;
if ( F_13 ( V_34 , L_141 , & V_111 ,
sizeof( V_111 ) ) == V_10 )
V_111 = 4UL << 20 ;
if ( F_51 ( V_116 ) || F_51 ( V_117 ) )
V_111 = 8UL << 20 ;
else
V_111 = 4UL << 20 ;
V_26 = F_52 ( V_110 , V_111 ) ;
V_47 = F_33 ( V_111 , V_26 , 1 ) ;
if ( V_47 == 0 )
F_32 ( L_142 ) ;
if ( V_47 < V_115 )
V_115 = V_47 ;
memset ( V_84 , 0 , V_89 ) ;
if ( F_2 ( L_69 , 3 , 1 , V_34 ,
V_84 , V_89 - 1 ) == V_10 ) {
F_10 ( L_143 ) ;
}
F_17 ( V_34 , V_84 , L_144 , & V_47 , sizeof( V_47 ) ) ;
F_17 ( V_34 , V_84 , L_145 , & V_111 , sizeof( V_111 ) ) ;
F_26 ( L_146 , V_84 ) ;
F_26 ( L_147 , V_34 ) ;
F_26 ( L_148 , V_47 ) ;
F_26 ( L_149 , V_111 ) ;
V_113 = ( T_7 * ) V_47 ;
for ( V_6 = 0 ; V_6 < ( V_111 >> 3 ) ; V_113 ++ , V_6 ++ ) {
V_112 = ( V_6 << V_118 ) ;
V_112 |= 0x3 ;
* V_113 = V_112 ;
}
F_10 ( L_150 , V_84 ) ;
V_107 = F_2 ( L_31 , 1 , 1 , V_84 ) ;
if ( V_107 == 0 )
F_10 ( L_151 ) ;
else
F_10 ( L_152 ) ;
F_2 ( L_4 , 6 , 0 , F_4 ( L_153 ) ,
V_107 , - 1 , V_111 ,
( V_38 ) V_47 , ( V_38 ) ( V_47 >> 32 ) ) ;
F_2 ( L_40 , 1 , 0 , V_107 ) ;
}
F_36 ( V_115 , V_114 - V_115 ) ;
V_119 = V_115 ;
V_120 = V_114 ;
F_26 ( L_154 ) ;
}
static void T_1 F_53 ( void )
{
unsigned long V_6 ;
T_3 V_34 ;
char type [ 64 ] ;
unsigned long * V_121
= ( void * ) F_54 ( V_122 ) ;
unsigned long * V_123
= ( void * ) F_54 ( V_124 ) ;
unsigned long V_125 = F_54 ( V_126 ) ;
if ( ( V_90 == V_127 ||
V_90 == V_128 ) &&
V_103 ) {
F_10 ( L_155 ) ;
return;
}
F_26 ( L_156 ) ;
F_26 ( L_157 , ( unsigned long ) V_121 ) ;
F_26 ( L_158 , * V_121 ) ;
F_26 ( L_159 ,
( unsigned long ) V_123 ) ;
F_26 ( L_160 , * V_123 ) ;
F_26 ( L_161 , V_125 ) ;
* V_121 = 0 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
unsigned int V_129 ;
T_8 V_130 ;
type [ 0 ] = 0 ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_26 ) != 0 )
continue;
if ( F_13 ( V_34 , L_162 , type , sizeof( type ) ) > 0 )
if ( strcmp ( type , L_163 ) != 0 )
continue;
V_130 = F_3 ( - 1 ) ;
F_13 ( V_34 , L_67 , & V_130 , sizeof( V_130 ) ) ;
V_129 = F_5 ( V_130 ) ;
F_26 ( L_164 , V_129 ) ;
* V_123 = ( unsigned long ) - 1 ;
if ( V_129 != V_15 . V_131 ) {
F_10 ( L_165 , V_129 ) ;
F_2 ( L_166 , 3 , 0 , V_34 ,
V_125 , V_129 ) ;
for ( V_6 = 0 ; ( V_6 < 100000000 ) &&
( * V_123 == ( ( unsigned long ) - 1 ) ) ; V_6 ++ )
F_55 () ;
if ( * V_123 == V_129 )
F_10 ( L_167 ) ;
else
F_10 ( L_168 , * V_123 ) ;
}
#ifdef F_56
else
F_10 ( L_169 , V_129 ) ;
#endif
}
F_26 ( L_170 ) ;
}
static void T_1 F_57 ( unsigned long V_132 )
{
V_9 = V_132 ;
V_15 . V_54 = F_2 ( L_78 , 1 , 1 , F_4 ( L_171 ) ) ;
if ( ! F_44 ( V_15 . V_54 ) )
F_32 ( L_172 ) ;
V_15 . V_60 = F_2 ( L_78 , 1 , 1 , F_4 ( L_32 ) ) ;
if ( ! F_44 ( V_15 . V_60 ) )
F_32 ( L_173 ) ;
V_15 . V_32 = 0 ;
}
static void T_1 F_58 ( void )
{
T_3 V_133 ;
char V_134 [ 64 ] ;
V_133 = F_2 ( L_78 , 1 , 1 , F_4 ( L_174 ) ) ;
if ( ! F_44 ( V_133 ) )
return;
if ( F_13 ( V_133 , L_132 , V_134 , sizeof( V_134 ) ) <= 0 )
return;
V_134 [ sizeof( V_134 ) - 1 ] = 0 ;
if ( strcmp ( V_134 , L_175 ) == 0 )
V_135 = V_28 ;
else if ( strncmp ( V_134 , L_176 , 12 ) == 0 ) {
V_135 = V_28 | V_44 ;
F_2 ( L_17 , 1 , 1 , L_177 ) ;
} else
return;
V_15 . V_31 = F_2 ( L_31 , 1 , 1 , F_4 ( L_178 ) ) ;
F_13 ( V_15 . V_54 , L_179 , & V_15 . V_32 ,
sizeof( V_15 . V_32 ) ) ;
V_15 . V_32 = F_5 ( V_15 . V_32 ) ;
if ( ! F_46 ( V_15 . V_31 ) || ! F_46 ( V_15 . V_32 ) )
V_135 &= ~ V_28 ;
}
static void T_1 F_59 ( void )
{
char * V_84 = V_136 ;
char type [ 16 ] ;
T_3 V_137 ;
T_8 V_16 ;
if ( F_13 ( V_15 . V_54 , L_180 , & V_16 , sizeof( V_16 ) ) <= 0 )
F_32 ( L_181 ) ;
V_15 . stdout = F_5 ( V_16 ) ;
memset ( V_84 , 0 , 256 ) ;
F_2 ( L_182 , 3 , 1 , V_15 . stdout , V_84 , 255 ) ;
F_10 ( L_183 , V_136 ) ;
F_17 ( V_15 . V_54 , L_171 , L_184 ,
V_84 , strlen ( V_84 ) + 1 ) ;
V_137 = F_2 ( L_185 , 1 , 1 , V_15 . stdout ) ;
if ( V_137 != V_10 ) {
V_16 = F_3 ( V_137 ) ;
F_17 ( V_15 . V_54 , L_171 , L_186 ,
& V_16 , sizeof( V_16 ) ) ;
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_137 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_187 ) == 0 )
F_17 ( V_137 , V_84 , L_188 , NULL , 0 ) ;
}
}
static int T_1 F_60 ( void )
{
char V_138 [ 256 ] ;
int V_139 , V_6 = 0 ;
#ifdef F_23
T_3 V_140 ;
int V_40 ;
#endif
V_139 = F_13 ( V_15 . V_60 , L_131 ,
V_138 , sizeof( V_138 ) - 1 ) ;
if ( V_139 > 0 ) {
V_138 [ V_139 ] = 0 ;
while ( V_6 < V_139 ) {
char * V_13 = & V_138 [ V_6 ] ;
int V_141 = strlen ( V_13 ) ;
if ( V_141 == 0 )
break;
if ( strstr ( V_13 , L_189 ) ||
strstr ( V_13 , L_190 ) )
return V_142 ;
#ifdef F_23
if ( strstr ( V_13 , L_191 ) ||
strstr ( V_13 , L_192 ) )
return V_143 ;
#endif
V_6 += V_141 + 1 ;
}
}
#ifdef F_23
if ( F_44 ( F_2 ( L_78 , 1 , 1 , F_4 ( L_79 ) ) ) )
return V_144 ;
V_139 = F_13 ( V_15 . V_60 , L_25 ,
V_138 , sizeof( V_138 ) - 1 ) ;
if ( V_139 <= 0 )
return V_143 ;
if ( strcmp ( V_138 , L_193 ) )
return V_143 ;
V_140 = F_2 ( L_78 , 1 , 1 , F_4 ( L_96 ) ) ;
if ( ! F_44 ( V_140 ) )
return V_143 ;
V_40 = F_14 ( V_140 , L_194 ) ;
if ( V_40 != V_10 ) {
F_26 ( L_195 ) ;
return V_128 ;
}
return V_127 ;
#else
return V_143 ;
#endif
}
static int T_1 F_61 ( T_5 V_145 , int V_6 , int V_77 , int V_146 , int V_147 )
{
return F_2 ( L_4 , 6 , 1 , F_4 ( L_196 ) , V_145 , V_6 , V_147 , V_146 , V_77 ) ;
}
static void T_1 F_62 ( void )
{
char type [ 16 ] , * V_84 ;
T_3 V_34 ;
T_5 V_145 ;
int V_6 ;
static unsigned char V_148 [] = {
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
const unsigned char * V_149 ;
F_26 ( L_197 ) ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_187 ) != 0 )
continue;
V_84 = V_87 ;
memset ( V_84 , 0 , V_89 ) ;
if ( F_2 ( L_69 , 3 , 1 , V_34 , V_84 ,
V_89 - 10 ) == V_10 )
continue;
F_10 ( L_198 , V_84 ) ;
V_145 = F_2 ( L_31 , 1 , 1 , V_84 ) ;
if ( V_145 == 0 ) {
F_10 ( L_199 ) ;
continue;
}
F_10 ( L_167 ) ;
F_17 ( V_34 , V_84 , L_200 , NULL , 0 ) ;
V_149 = V_148 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ , V_149 += 3 )
if ( F_61 ( V_145 , V_6 , V_149 [ 0 ] , V_149 [ 1 ] ,
V_149 [ 2 ] ) != 0 )
break;
#ifdef F_63
V_149 = F_64 ( V_150 . V_149 ) ;
for ( V_6 = 0 ; V_6 < V_150 . V_151 ; V_6 ++ , V_149 += 3 )
if ( F_61 ( V_145 , V_6 + 32 , V_149 [ 0 ] , V_149 [ 1 ] ,
V_149 [ 2 ] ) != 0 )
break;
#endif
#ifdef F_65
if ( F_13 ( V_34 , L_188 , NULL , 0 ) !=
V_10 ) {
V_38 V_152 , V_153 , V_154 , V_69 ;
F_10 ( L_201 ) ;
F_13 ( V_34 , L_202 , & V_152 , 4 ) ;
F_13 ( V_34 , L_203 , & V_153 , 4 ) ;
F_13 ( V_34 , L_204 , & V_154 , 4 ) ;
F_13 ( V_34 , L_205 , & V_69 , 4 ) ;
F_10 ( L_206 ,
V_152 , V_153 , V_154 , V_69 ) ;
F_66 ( V_152 , V_153 , 8 , V_154 , V_69 ) ;
}
#endif
}
}
static void T_1 * F_67 ( unsigned long * V_155 , unsigned long * V_156 ,
unsigned long V_157 , unsigned long V_26 )
{
void * V_29 ;
* V_155 = F_68 ( * V_155 , V_26 ) ;
while ( ( * V_155 + V_157 ) > * V_156 ) {
unsigned long V_158 , V_159 ;
F_26 ( L_207 ,
V_68 ) ;
V_158 = V_71 - V_68 ;
if ( V_158 > V_160 )
V_158 = V_160 ;
if ( V_158 < V_81 )
F_32 ( L_208
L_209 ) ;
V_159 = F_30 ( V_158 , 0 ) ;
if ( V_159 == 0 )
F_32 ( L_208
L_210 ) ;
* V_156 = V_159 + V_158 ;
}
V_29 = ( void * ) * V_155 ;
* V_155 += V_157 ;
return V_29 ;
}
static unsigned long T_1 F_69 ( char * V_39 )
{
char * V_22 , * V_161 ;
V_22 = V_161 = ( char * ) V_162 ;
V_22 += 4 ;
while ( V_22 < ( char * ) V_163 ) {
if ( strcmp ( V_22 , V_39 ) == 0 )
return V_22 - V_161 ;
V_22 += strlen ( V_22 ) + 1 ;
}
return 0 ;
}
static void T_1 F_70 ( T_3 V_34 ,
unsigned long * V_155 ,
unsigned long * V_156 )
{
char * V_164 , * V_165 , * V_166 ;
unsigned long V_167 ;
T_3 V_168 ;
V_166 = ( char * ) V_162 ;
V_164 = L_211 ;
for (; ; ) {
V_165 = F_67 ( V_155 , V_156 , V_169 , 1 ) ;
if ( F_2 ( L_212 , 3 , 1 , V_34 , V_164 , V_165 ) != 1 ) {
* V_155 = ( unsigned long ) V_165 ;
break;
}
if ( strcmp ( V_165 , L_65 ) == 0 ) {
* V_155 = ( unsigned long ) V_165 ;
V_164 = L_65 ;
continue;
}
V_167 = F_69 ( V_165 ) ;
if ( V_167 != 0 ) {
* V_155 = ( unsigned long ) V_165 ;
V_165 = V_166 + V_167 ;
} else {
* V_155 = ( unsigned long ) V_165 + strlen ( V_165 ) + 1 ;
V_163 = * V_155 ;
}
V_164 = V_165 ;
}
V_168 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_168 != 0 ) {
F_70 ( V_168 , V_155 , V_156 ) ;
V_168 = F_2 ( L_9 , 1 , 1 , V_168 ) ;
}
}
static void T_1 F_71 ( T_3 V_34 , unsigned long * V_155 ,
unsigned long * V_156 )
{
T_3 V_168 ;
char * V_165 , * V_164 , * V_166 , * V_13 , * V_170 , * V_171 , * V_84 ;
unsigned long V_167 ;
unsigned char * V_172 ;
static char V_35 [ V_169 ] ;
int V_52 , V_158 , V_173 = 0 ;
F_72 ( V_174 , V_155 , V_156 ) ;
V_165 = ( char * ) * V_155 ;
V_158 = * V_156 - * V_155 ;
if ( V_158 > 255 )
V_158 = 255 ;
V_52 = F_2 ( L_69 , 3 , 1 , V_34 , V_165 , V_158 ) ;
if ( V_52 >= 0 ) {
if ( V_52 >= V_158 ) {
if ( V_52 >= * V_156 - * V_155 )
V_165 = F_67 ( V_155 , V_156 , V_52 + 1 , 1 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_165 , V_52 ) ;
}
V_165 [ V_52 ] = '\0' ;
for ( V_171 = V_13 = V_165 , V_170 = V_165 + V_52 ; V_13 < V_170 ; V_13 ++ ) {
if ( * V_13 == '/' )
V_171 = V_165 ;
else if ( * V_13 != 0 )
* V_171 ++ = * V_13 ;
}
* V_171 = 0 ;
* V_155 = F_68 ( ( unsigned long ) V_171 + 1 , 4 ) ;
}
V_84 = V_87 ;
memset ( V_84 , 0 , V_89 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_84 , V_89 - 1 ) ;
V_164 = L_211 ;
V_166 = ( char * ) V_162 ;
for (; ; ) {
if ( F_2 ( L_212 , 3 , 1 , V_34 , V_164 ,
V_35 ) != 1 )
break;
if ( strcmp ( V_35 , L_65 ) == 0 ) {
V_164 = L_65 ;
continue;
}
V_167 = F_69 ( V_35 ) ;
if ( V_167 == 0 ) {
F_10 ( L_213
L_214 , V_35 , V_84 ) ;
break;
}
V_164 = V_166 + V_167 ;
V_52 = F_2 ( L_12 , 2 , 1 , V_34 , V_35 ) ;
if ( V_52 == V_10 )
continue;
F_72 ( V_175 , V_155 , V_156 ) ;
F_72 ( V_52 , V_155 , V_156 ) ;
F_72 ( V_167 , V_155 , V_156 ) ;
V_172 = F_67 ( V_155 , V_156 , V_52 , 4 ) ;
F_2 ( L_11 , 4 , 1 , V_34 , V_35 , V_172 , V_52 ) ;
* V_155 = F_68 ( * V_155 , 4 ) ;
if ( ! strcmp ( V_35 , L_215 ) )
V_173 = 1 ;
}
if ( ! V_173 ) {
V_167 = F_69 ( L_216 ) ;
if ( V_167 == 0 )
F_10 ( L_213
L_217 , V_84 ) ;
else {
F_72 ( V_175 , V_155 , V_156 ) ;
F_72 ( 4 , V_155 , V_156 ) ;
F_72 ( V_167 , V_155 , V_156 ) ;
V_172 = F_67 ( V_155 , V_156 , 4 , 4 ) ;
* ( T_8 * ) V_172 = F_3 ( V_34 ) ;
}
}
V_168 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_168 != 0 ) {
F_71 ( V_168 , V_155 , V_156 ) ;
V_168 = F_2 ( L_9 , 1 , 1 , V_168 ) ;
}
F_72 ( V_176 , V_155 , V_156 ) ;
}
static void T_1 F_73 ( void )
{
T_3 V_60 ;
unsigned long V_155 , V_156 , V_158 ;
struct V_177 * V_178 ;
char * V_165 ;
T_7 * V_179 ;
V_158 = V_71 - V_68 - 0x4000 ;
if ( V_158 > V_160 )
V_158 = V_160 ;
F_26 ( L_218 , V_68 ) ;
V_155 = ( unsigned long ) F_30 ( V_158 , V_81 ) ;
if ( V_155 == 0 )
F_32 ( L_219 ) ;
V_156 = V_155 + V_158 ;
V_60 = F_2 ( L_9 , 1 , 1 , ( T_3 ) 0 ) ;
if ( V_60 == ( T_3 ) 0 )
F_32 ( L_220 ) ;
V_155 = F_68 ( V_155 , 4 ) ;
V_178 = F_67 ( & V_155 , & V_156 ,
sizeof( struct V_177 ) , 4 ) ;
V_180 = ( unsigned long ) V_178 ;
V_179 = F_67 ( & V_155 , & V_156 , sizeof( V_83 ) , 8 ) ;
V_155 = F_40 ( V_155 ) ;
V_162 = V_155 ;
V_155 += 4 ;
V_165 = F_67 ( & V_155 , & V_156 , 16 , 1 ) ;
strcpy ( V_165 , L_216 ) ;
V_155 = ( unsigned long ) V_165 + strlen ( V_165 ) + 1 ;
F_10 ( L_221 ) ;
F_70 ( V_60 , & V_155 , & V_156 ) ;
V_163 = V_155 ;
V_155 = F_40 ( V_155 ) ;
V_181 = V_155 ;
F_10 ( L_222 ) ;
F_71 ( V_60 , & V_155 , & V_156 ) ;
F_72 ( V_182 , & V_155 , & V_156 ) ;
V_183 = F_40 ( V_155 ) ;
V_178 -> V_184 = F_3 ( V_15 . V_131 ) ;
V_178 -> V_185 = F_3 ( V_186 ) ;
V_178 -> V_187 = F_3 ( V_183 - V_180 ) ;
V_178 -> V_188 = F_3 ( V_181 - V_180 ) ;
V_178 -> V_189 = F_3 ( V_162 - V_180 ) ;
V_178 -> V_190 = F_3 ( V_163 - V_162 ) ;
V_178 -> V_191 = F_3 ( ( ( unsigned long ) V_179 ) - V_180 ) ;
V_178 -> V_134 = F_3 ( V_192 ) ;
V_178 -> V_193 = F_3 ( 0x10 ) ;
memcpy ( V_179 , V_83 , sizeof( V_83 ) ) ;
#ifdef F_39
{
int V_6 ;
F_10 ( L_223 ) ;
for ( V_6 = 0 ; V_6 < V_80 ; V_6 ++ )
F_10 ( L_224 ,
F_45 ( V_83 [ V_6 ] . V_47 ) ,
F_45 ( V_83 [ V_6 ] . V_19 ) ) ;
}
#endif
V_80 = V_82 ;
F_10 ( L_225 ,
V_162 , V_163 ) ;
F_10 ( L_226 ,
V_181 , V_183 ) ;
}
static void T_1 F_74 ( void )
{
T_3 V_194 ;
V_38 V_195 = 0x01002000 ;
V_38 V_196 [ 6 ] ;
char * V_197 ;
V_197 = L_227 ;
V_194 = F_2 ( L_78 , 1 , 1 , F_4 ( V_197 ) ) ;
if ( ! F_44 ( V_194 ) ) {
V_197 = L_228 ;
V_194 = F_2 ( L_78 , 1 , 1 , F_4 ( V_197 ) ) ;
V_195 = 0x01003000 ;
}
if ( ! F_44 ( V_194 ) )
return;
if ( F_14 ( V_194 , L_229 ) != 12 )
return;
if ( F_13 ( V_194 , L_229 , V_196 , sizeof( V_196 ) )
== V_10 )
return;
if ( V_196 [ 0 ] != 0x1 ||
V_196 [ 1 ] != 0xf4000000 ||
V_196 [ 2 ] != 0x00010000 )
return;
F_10 ( L_230 ) ;
V_196 [ 0 ] = 0x1 ;
V_196 [ 1 ] = 0x0 ;
V_196 [ 2 ] = V_195 ;
V_196 [ 3 ] = 0x0 ;
V_196 [ 4 ] = 0x0 ;
V_196 [ 5 ] = 0x00010000 ;
F_17 ( V_194 , V_197 , L_229 ,
V_196 , sizeof( V_196 ) ) ;
}
static void T_1 F_75 ( void )
{
T_3 V_198 ;
V_38 V_199 [ 4 ] ;
char * V_197 = L_231 ;
V_38 V_200 , V_201 ;
V_198 = F_2 ( L_78 , 1 , 1 , F_4 ( V_197 ) ) ;
if ( ! F_44 ( V_198 ) )
return;
if ( F_14 ( V_198 , L_67 ) != 8 )
return;
F_13 ( V_15 . V_60 , L_60 , & V_200 , sizeof( V_200 ) ) ;
F_13 ( V_15 . V_60 , L_61 , & V_201 , sizeof( V_201 ) ) ;
if ( ( V_200 != 2 ) || ( V_201 != 2 ) )
return;
if ( F_13 ( V_198 , L_67 , V_199 , sizeof( V_199 ) ) == V_10 )
return;
if ( V_199 [ 0 ] != V_202 || V_199 [ 1 ] != V_203 )
return;
F_10 ( L_232 ) ;
V_199 [ 0 ] = 0x0 ;
V_199 [ 1 ] = V_202 ;
V_199 [ 2 ] = 0x0 ;
V_199 [ 3 ] = V_203 ;
F_17 ( V_198 , V_197 , L_67 , V_199 , sizeof( V_199 ) ) ;
}
static void T_1 F_76 ( void )
{
T_3 V_204 ;
V_38 V_205 [ 6 ] ;
V_38 V_195 = 0x01006000 ;
char * V_197 ;
int V_206 ;
V_197 = L_233 ;
V_204 = F_2 ( L_78 , 1 , 1 , F_4 ( V_197 ) ) ;
if ( ! F_44 ( V_204 ) ) {
V_197 = L_234 ;
V_204 = F_2 ( L_78 , 1 , 1 , F_4 ( V_197 ) ) ;
V_195 = 0x01003000 ;
}
if ( F_44 ( V_204 ) ) {
V_206 = F_14 ( V_204 , L_229 ) ;
if ( V_206 == 0 || V_206 == V_10 ) {
F_10 ( L_235 ) ;
V_205 [ 0 ] = 0x1 ;
V_205 [ 1 ] = 0x0 ;
V_205 [ 2 ] = V_195 ;
V_205 [ 3 ] = 0x0 ;
V_205 [ 4 ] = 0x0 ;
V_205 [ 5 ] = 0x00010000 ;
F_17 ( V_204 , V_197 , L_229 , V_205 , sizeof( V_205 ) ) ;
}
}
V_197 = L_236 ;
V_204 = F_2 ( L_78 , 1 , 1 , F_4 ( V_197 ) ) ;
if ( F_44 ( V_204 ) ) {
F_10 ( L_237 ) ;
V_205 [ 0 ] = 14 ;
V_205 [ 1 ] = 0x0 ;
F_17 ( V_204 , V_197 , L_238 , V_205 , 2 * sizeof( V_38 ) ) ;
F_10 ( L_239 ) ;
V_206 = F_13 ( V_204 , L_240 , V_205 , sizeof( V_38 ) ) ;
if ( V_206 == sizeof( V_38 ) ) {
V_205 [ 0 ] &= ~ 0x5 ;
F_17 ( V_204 , V_197 , L_240 , V_205 , sizeof( V_38 ) ) ;
}
}
}
static void T_1 F_77 ( void )
{
T_3 V_207 , V_208 , V_209 ;
V_38 V_210 ;
V_38 V_211 [ 2 ] ;
V_38 V_212 ;
V_207 = F_2 ( L_78 , 1 , 1 , F_4 ( L_241 ) ) ;
if ( ! F_44 ( V_207 ) )
return;
V_208 = F_2 ( L_78 , 1 , 1 , F_4 ( L_242 ) ) ;
if ( ! F_44 ( V_208 ) )
return;
V_209 = F_2 ( L_78 , 1 , 1 , F_4 ( L_243 ) ) ;
if ( ! F_44 ( V_209 ) )
return;
if ( F_13 ( V_207 , L_244 , & V_210 , sizeof( V_210 ) )
== V_10 )
return;
if ( V_210 < 0x35 || V_210 > 0x39 )
return;
if ( F_14 ( V_208 , L_238 ) > 0 )
return;
F_10 ( L_245 ) ;
V_211 [ 0 ] = 0 ;
V_211 [ 1 ] = 1 ;
F_17 ( V_208 , L_242 , L_238 ,
& V_211 , sizeof( V_211 ) ) ;
V_212 = ( V_38 ) V_209 ;
F_17 ( V_208 , L_242 , L_246 ,
& V_212 , sizeof( V_212 ) ) ;
}
static void T_1 F_78 ( void )
{
V_38 V_34 ;
char V_205 [ 64 ] ;
int V_213 ;
V_34 = F_2 ( L_78 , 1 , 1 , F_4 ( L_247 ) ) ;
if ( ! F_44 ( V_34 ) )
return;
V_213 = F_13 ( V_34 , L_248 , V_205 , sizeof( V_205 ) ) ;
if ( ! V_213 )
return;
V_34 = F_2 ( L_78 , 1 , 1 , F_4 ( L_249 ) ) ;
if ( ! F_44 ( V_34 ) ) {
F_10 ( L_250 ) ;
F_2 ( L_17 , 1 , 1 ,
L_251
L_252
L_253
L_254
L_255
L_256
L_257
L_258
L_259
L_260
L_261
L_262
L_263 ) ;
} ;
V_34 = F_2 ( L_78 , 1 , 1 ,
F_4 ( L_264 ) ) ;
if ( ! F_44 ( V_34 ) ) {
F_10 ( L_265 ) ;
F_2 ( L_17 , 1 , 1 ,
L_266
L_252
L_267
L_268
L_269
L_270
L_263
L_271
L_272
L_273
L_274 ) ;
}
}
static void T_1 F_79 ( void )
{
int V_214 [ 3 ] = { 2 , 2 , 0 } ;
int V_215 [ 3 * 16 ] = { 3 , 0 , 0 , 3 , 1 , 0 , 3 , 2 , 0 , 3 , 3 , 0 ,
3 , 4 , 0 , 3 , 5 , 0 , 3 , 6 , 0 , 3 , 7 , 0 ,
3 , 8 , 0 , 3 , 9 , 0 , 3 , 10 , 0 , 3 , 11 , 0 ,
3 , 12 , 0 , 3 , 13 , 0 , 3 , 14 , 0 , 3 , 15 , 0 } ;
V_38 V_34 ;
char V_205 [ 64 ] ;
int V_213 , V_139 ;
V_34 = F_2 ( L_78 , 1 , 1 , F_4 ( L_32 ) ) ;
if ( ! F_44 ( V_34 ) )
return;
V_213 = F_13 ( V_34 , L_132 , V_205 , sizeof( V_205 ) ) ;
if ( V_213 == V_10 )
return;
if ( strcmp ( V_205 , L_275 ) )
return;
F_10 ( L_276 ) ;
V_34 = F_2 ( L_78 , 1 , 1 , F_4 ( L_32 ) ) ;
V_213 = F_13 ( V_34 , L_25 , V_205 , sizeof( V_205 ) ) ;
if ( V_213 != V_10 && ( strcmp ( V_205 , L_193 ) == 0 ) )
F_17 ( V_34 , L_32 , L_25 , L_277 , sizeof( L_277 ) ) ;
V_213 = F_13 ( V_34 , L_278 , V_205 , sizeof( V_205 ) ) ;
if ( V_213 != V_10 && ( strstr ( V_205 , L_279 ) ) )
F_17 ( V_34 , L_32 , L_278 ,
L_280 ,
sizeof( L_280 ) ) ;
V_34 = F_2 ( L_78 , 1 , 1 , F_4 ( L_281 ) ) ;
if ( F_44 ( V_34 ) ) {
V_139 = F_14 ( V_34 , L_238 ) ;
if ( V_139 == 12 ) {
F_10 ( L_282 ) ;
F_17 ( V_34 , L_283 , L_238 ,
V_215 , sizeof( V_215 ) ) ;
}
}
V_34 = F_2 ( L_78 , 1 , 1 , F_4 ( L_284 ) ) ;
if ( F_44 ( V_34 ) ) {
V_213 = F_13 ( V_34 , L_238 , V_205 , sizeof( V_205 ) ) ;
if ( V_213 == V_10 ) {
F_10 ( L_285 ) ;
F_17 ( V_34 , L_284 , L_238 ,
V_214 , sizeof( V_214 ) ) ;
}
}
F_78 () ;
}
static void T_1 F_80 ( void )
{
F_74 () ;
F_75 () ;
F_76 () ;
F_77 () ;
F_79 () ;
}
static void T_1 F_81 ( void )
{
T_8 V_216 ;
T_5 V_217 ;
T_3 V_218 ;
V_216 = 0 ;
if ( F_13 ( V_15 . V_54 , L_26 , & V_216 , sizeof( V_216 ) ) <= 0 )
return;
V_217 = F_5 ( V_216 ) ;
V_218 = F_2 ( L_185 , 1 , 1 , V_217 ) ;
F_13 ( V_218 , L_67 , & V_216 , sizeof( V_216 ) ) ;
V_15 . V_131 = F_5 ( V_216 ) ;
F_26 ( L_286 , V_15 . V_131 ) ;
}
static void T_1 F_82 ( unsigned long V_219 , unsigned long V_220 )
{
#ifdef F_83
if ( V_219 && V_220 && V_220 != 0xdeadbeef ) {
T_9 V_16 ;
V_93 = F_84 ( V_219 ) ? F_85 ( V_219 ) : V_219 ;
V_94 = V_93 + V_220 ;
V_16 = F_37 ( V_93 ) ;
F_17 ( V_15 . V_54 , L_171 , L_287 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_37 ( V_94 ) ;
F_17 ( V_15 . V_54 , L_171 , L_288 ,
& V_16 , sizeof( V_16 ) ) ;
F_36 ( V_93 ,
V_94 - V_93 ) ;
F_26 ( L_289 , V_93 ) ;
F_26 ( L_290 , V_94 ) ;
}
#endif
}
static void F_86 ( void )
{
}
static void F_87 ( void )
{
}
static void F_88 ( unsigned long V_221 , unsigned long V_222 )
{
unsigned long V_6 ;
unsigned long * V_223 ;
asm volatile("addi %0,2,-0x8000" : "=b" (toc_entry));
for ( V_6 = 0 ; V_6 < V_222 ; V_6 ++ ) {
* V_223 = * V_223 + V_221 ;
V_223 ++ ;
}
}
static void F_86 ( void )
{
unsigned long V_221 = F_89 () ;
unsigned long V_222 =
( V_224 - V_225 ) / sizeof( long ) ;
F_88 ( V_221 , V_222 ) ;
F_55 () ;
}
static void F_87 ( void )
{
unsigned long V_221 = F_89 () ;
unsigned long V_222 =
( V_224 - V_225 ) / sizeof( long ) ;
F_55 () ;
F_88 ( - V_221 , V_222 ) ;
}
unsigned long T_1 F_90 ( unsigned long V_219 , unsigned long V_220 ,
unsigned long V_132 ,
unsigned long V_226 , unsigned long V_227 ,
unsigned long V_228 )
{
unsigned long V_178 ;
#ifdef F_91
unsigned long V_221 = F_89 () ;
F_92 ( V_221 ) ;
#else
F_86 () ;
#endif
memset ( & V_229 , 0 , V_230 - V_229 ) ;
F_57 ( V_132 ) ;
F_58 () ;
F_59 () ;
F_10 ( L_291 , V_231 ) ;
V_90 = F_60 () ;
F_10 ( L_292 , V_90 ) ;
#ifndef F_93
if ( V_232 > 0 )
F_32 ( L_293 ) ;
#endif
F_82 ( V_219 , V_220 ) ;
#if F_94 ( V_233 ) || F_94 ( V_234 )
if ( V_90 == V_127 ||
V_90 == V_128 )
F_27 () ;
#endif
if ( V_90 != V_142 )
F_95 ( 0 , V_228 , 0x100 , 0 ) ;
F_20 () ;
F_38 () ;
F_81 () ;
F_62 () ;
#if F_94 ( F_23 ) && F_94 ( F_29 )
if ( V_90 == V_127 )
F_50 () ;
#endif
if ( V_90 != V_142 &&
V_90 != V_144 )
F_48 () ;
#ifdef V_234
if ( V_90 == V_144 )
F_43 () ;
#endif
#ifdef F_23
F_49 () ;
#endif
if ( V_90 != V_142 &&
V_90 != V_144 )
F_53 () ;
if ( V_58 ) {
T_9 V_16 = F_37 ( V_58 ) ;
F_17 ( V_15 . V_54 , L_171 , L_294 ,
& V_16 , sizeof( V_16 ) ) ;
}
#ifdef F_23
if ( V_56 )
F_17 ( V_15 . V_54 , L_171 , L_295 ,
NULL , 0 ) ;
if ( V_57 )
F_17 ( V_15 . V_54 , L_171 , L_296 ,
NULL , 0 ) ;
if ( V_119 ) {
F_17 ( V_15 . V_54 , L_171 , L_297 ,
& V_119 ,
sizeof( V_119 ) ) ;
F_17 ( V_15 . V_54 , L_171 , L_298 ,
& V_120 ,
sizeof( V_120 ) ) ;
}
#endif
F_80 () ;
F_10 ( L_299 ) ;
F_73 () ;
if ( V_90 != V_142 &&
V_90 != V_144 )
F_42 () ;
F_10 ( L_300 ) ;
F_2 ( L_301 , 0 , 0 ) ;
V_178 = V_180 ;
if ( V_90 != V_144 ) {
F_10 ( L_302 ) ;
F_26 ( L_303 , V_178 ) ;
}
#ifdef F_91
F_92 ( - V_221 ) ;
#else
F_87 () ;
#endif
#ifdef F_47
F_96 ( V_178 , V_228 , 0 , 0 , 0 ,
V_99 , V_100 ) ;
#else
F_96 ( V_178 , V_228 , 0 , 0 , 0 , 0 , 0 ) ;
#endif
return 0 ;
}
