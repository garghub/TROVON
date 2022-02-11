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
T_6 * V_61 ;
V_60 = F_2 ( L_31 , 1 , 1 , F_4 ( L_32 ) ) ;
if ( V_60 != 0 ) {
V_61 = ( T_6 * ) & V_62 [ V_63 ] ;
if ( F_28 ( V_61 ) != V_64 ) {
F_10 ( L_33
L_34 ,
F_28 ( V_61 ) ) ;
} else {
* V_61 = F_3 ( F_29 ( V_64 , F_25 () ) ) ;
F_10 ( L_35 ,
F_28 ( V_61 ) , V_64 ) ;
}
F_10 ( L_36 ) ;
if ( F_6 ( L_4 , 3 , 2 , & V_29 ,
F_4 ( L_37 ) ,
V_60 ,
F_4 ( V_62 ) ) == 0 ) {
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
#ifdef F_30
{
T_5 V_65 ;
V_65 = F_2 ( L_31 , 1 , 1 ,
F_4 ( L_43 ) ) ;
if ( V_65 == 0 ) {
F_10 ( L_44 ) ;
return;
}
F_2 ( L_4 , 3 , 1 , F_4 ( L_45 ) ,
V_65 , F_4 ( & V_66 ) ) ;
F_2 ( L_40 , 1 , 0 , V_65 ) ;
}
#endif
}
static unsigned long T_1 F_31 ( unsigned long V_19 , unsigned long V_26 )
{
unsigned long V_47 = V_67 ;
unsigned long V_68 = 0 ;
if ( V_26 )
V_47 = F_32 ( V_47 , V_26 ) ;
F_26 ( L_46 , V_19 , V_26 ) ;
if ( V_69 == 0 )
F_33 ( L_47 ) ;
if ( V_26 )
V_47 = F_32 ( V_67 , V_26 ) ;
else
V_47 = V_67 ;
for(; ( V_47 + V_19 ) <= V_70 ;
V_47 = F_32 ( V_47 + 0x100000 , V_26 ) ) {
F_26 ( L_48 , V_47 ) ;
V_68 = ( unsigned long ) F_11 ( V_47 , V_19 , 0 ) ;
if ( V_68 != V_10 && V_68 != 0 )
break;
V_68 = 0 ;
if ( V_26 == 0 )
break;
}
if ( V_68 == 0 )
return 0 ;
V_67 = V_68 + V_19 ;
F_26 ( L_49 , V_68 ) ;
F_26 ( L_50 , V_67 ) ;
F_26 ( L_51 , V_70 ) ;
F_26 ( L_52 , V_71 ) ;
F_26 ( L_53 , V_72 ) ;
F_26 ( L_54 , V_69 ) ;
return V_68 ;
}
static unsigned long T_1 F_34 ( unsigned long V_19 , unsigned long V_26 ,
int V_73 )
{
unsigned long V_47 , V_68 = 0 ;
F_26 ( L_55 , V_19 , V_26 ,
V_73 ? L_56 : L_57 ) ;
if ( V_69 == 0 )
F_33 ( L_58 ) ;
if ( V_73 ) {
V_68 = F_35 ( V_71 - V_19 , V_26 ) ;
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
V_47 = F_35 ( V_70 - V_19 , V_26 ) ;
for (; V_47 > V_67 ;
V_47 = F_35 ( V_47 - 0x100000 , V_26 ) ) {
F_26 ( L_48 , V_47 ) ;
V_68 = ( unsigned long ) F_11 ( V_47 , V_19 , 0 ) ;
if ( V_68 != V_10 && V_68 != 0 )
break;
V_68 = 0 ;
}
if ( V_68 == 0 )
return 0 ;
V_70 = V_68 ;
V_74:
F_26 ( L_49 , V_68 ) ;
F_26 ( L_50 , V_67 ) ;
F_26 ( L_51 , V_70 ) ;
F_26 ( L_52 , V_71 ) ;
F_26 ( L_53 , V_72 ) ;
F_26 ( L_54 , V_69 ) ;
return V_68 ;
}
static unsigned long T_1 F_36 ( int V_22 , T_7 * * V_75 )
{
T_7 * V_13 = * V_75 ;
unsigned long V_76 = 0 ;
while ( V_22 > sizeof( unsigned long ) / 4 ) {
V_13 ++ ;
V_22 -- ;
}
V_76 = F_5 ( * V_13 ++ ) ;
#ifdef F_23
if ( V_22 > 1 ) {
V_76 <<= 32 ;
V_76 |= F_5 ( * ( V_13 ++ ) ) ;
}
#endif
* V_75 = V_13 ;
return V_76 ;
}
static void T_1 F_37 ( T_8 V_47 , T_8 V_19 )
{
T_8 V_77 = V_47 + V_19 ;
unsigned long V_78 = V_79 ;
if ( V_19 == 0 )
return;
V_47 = F_35 ( V_47 , V_80 ) ;
V_77 = F_32 ( V_77 , V_80 ) ;
V_19 = V_77 - V_47 ;
if ( V_78 >= ( V_81 - 1 ) )
F_33 ( L_59 ) ;
V_82 [ V_78 ] . V_47 = F_38 ( V_47 ) ;
V_82 [ V_78 ] . V_19 = F_38 ( V_19 ) ;
V_79 = V_78 + 1 ;
}
static void T_1 F_39 ( void )
{
T_3 V_34 ;
char * V_83 , type [ 64 ] ;
unsigned int V_59 ;
T_7 * V_13 , * V_46 ;
T_6 V_16 ;
V_38 V_84 , V_85 ;
V_16 = F_3 ( 2 ) ;
F_13 ( V_15 . V_60 , L_60 , & V_16 , sizeof( V_16 ) ) ;
V_84 = F_5 ( V_16 ) ;
V_16 = F_3 ( 1 ) ;
F_13 ( V_15 . V_60 , L_61 , & V_16 , sizeof( V_85 ) ) ;
V_85 = F_5 ( V_16 ) ;
F_26 ( L_62 , V_84 ) ;
F_26 ( L_63 , V_85 ) ;
F_26 ( L_64 ) ;
V_83 = V_86 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( type [ 0 ] == 0 ) {
F_13 ( V_34 , L_65 , type , sizeof( type ) ) ;
}
if ( strcmp ( type , L_66 ) )
continue;
V_59 = F_13 ( V_34 , L_67 , V_87 , sizeof( V_87 ) ) ;
if ( V_59 > sizeof( V_87 ) ) {
F_10 ( L_68 ) ;
V_59 = sizeof( V_87 ) ;
}
V_13 = V_87 ;
V_46 = V_13 + ( V_59 / sizeof( T_7 ) ) ;
#ifdef F_40
memset ( V_83 , 0 , V_88 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_83 , V_88 - 1 ) ;
F_26 ( L_70 , V_83 ) ;
#endif
while ( ( V_46 - V_13 ) >= ( V_84 + V_85 ) ) {
unsigned long V_47 , V_19 ;
V_47 = F_36 ( V_84 , & V_13 ) ;
V_19 = F_36 ( V_85 , & V_13 ) ;
if ( V_19 == 0 )
continue;
F_26 ( L_71 , V_47 , V_19 ) ;
if ( V_47 == 0 && ( V_89 & V_90 ) )
V_72 = V_19 ;
if ( ( V_47 + V_19 ) > V_69 )
V_69 = V_47 + V_19 ;
}
}
V_67 = F_41 ( ( unsigned long ) & V_91 + 0x4000 ) ;
V_71 = V_69 ;
if ( V_58 ) {
if ( V_58 <= V_67 ) {
F_10 ( L_72 ,
V_58 ) ;
V_58 = 0 ;
} else if ( V_58 >= V_69 ) {
F_10 ( L_73 ,
V_58 ) ;
V_58 = 0 ;
} else {
V_69 = V_58 ;
V_72 = F_42 ( V_72 , V_58 ) ;
}
}
if ( ! V_72 )
V_72 = V_69 ;
V_72 = F_42 ( 0x30000000ul , V_72 ) ;
V_70 = V_72 ;
V_71 = V_69 ;
if ( V_92 &&
V_92 < V_72 &&
V_93 > V_67 )
V_67 = F_41 ( V_93 ) ;
F_10 ( L_74 ) ;
F_10 ( L_75 , V_58 ) ;
F_10 ( L_50 , V_67 ) ;
F_10 ( L_51 , V_70 ) ;
F_10 ( L_52 , V_71 ) ;
F_10 ( L_53 , V_72 ) ;
F_10 ( L_54 , V_69 ) ;
}
static void T_1 F_43 ( void )
{
T_6 V_16 ;
T_5 V_94 ;
if ( F_13 ( V_15 . V_54 , L_76 , & V_16 , sizeof( V_16 ) ) > 0 ) {
V_94 = F_5 ( V_16 ) ;
F_2 ( L_40 , 1 , 0 , V_94 ) ;
}
}
static void T_1 F_44 ( void )
{
long V_95 ;
if ( F_45 ( F_2 ( L_77 , 1 , 1 ,
F_4 ( L_78 ) ) ) ) {
F_10 ( L_79 ) ;
return;
}
F_10 ( L_80 ) ;
V_95 = F_46 ( & V_96 ,
& V_97 ) ;
F_26 ( L_81 , V_95 ) ;
if ( V_95 != 0 ) {
F_10 ( L_82 ) ;
return;
}
V_89 = V_98 ;
F_10 ( L_83 ) ;
F_26 ( L_84 , V_96 ) ;
F_26 ( L_85 , V_97 ) ;
if ( V_97 < 0x10000 )
V_97 = 0x10000 ;
}
static int T_1 F_47 ( int V_99 , int V_4 , int V_5 ,
int * V_100 , ... )
{
struct V_101 V_101 ;
T_2 V_7 ;
int V_6 ;
V_101 . V_99 = V_99 ;
V_101 . V_4 = V_4 ;
V_101 . V_5 = V_5 ;
V_101 . V_11 = ( V_102 * ) & ( V_101 . args [ V_4 ] ) ;
va_start ( V_7 , V_100 ) ;
for ( V_6 = 0 ; V_6 < V_4 ; ++ V_6 )
V_101 . args [ V_6 ] = va_arg ( V_7 , V_102 ) ;
va_end ( V_7 ) ;
for ( V_6 = 0 ; V_6 < V_5 ; ++ V_6 )
V_101 . V_11 [ V_6 ] = 0 ;
F_48 ( & V_101 , V_103 ,
V_104 ) ;
if ( V_5 > 1 && V_100 != NULL )
for ( V_6 = 0 ; V_6 < V_5 - 1 ; ++ V_6 )
V_100 [ V_6 ] = V_101 . V_11 [ V_6 + 1 ] ;
return ( V_5 > 0 ) ? V_101 . V_11 [ 0 ] : 0 ;
}
static void T_1 F_49 ( void )
{
int V_6 , V_78 , V_105 , V_95 ;
long V_106 ;
T_3 V_34 ;
char type [ 64 ] ;
V_38 V_107 [ 8 ] ;
void * V_2 = ( unsigned long * ) & V_108 ;
struct V_109 * V_110 = & V_109 ;
F_26 ( L_86 ) ;
F_26 ( L_87 , V_2 ) ;
F_26 ( L_88 , V_110 ) ;
V_110 -> V_111 = - 1 ;
V_110 -> V_112 = 0 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_26 ) != 0 )
continue;
if ( F_13 ( V_34 , L_89 , type , sizeof( type ) ) > 0 )
if ( strcmp ( type , L_90 ) != 0 )
continue;
V_78 = F_13 ( V_34 , L_27 , V_107 ,
sizeof( V_107 ) ) ;
if ( V_78 == V_10 )
break;
V_78 >>= 2 ;
for ( V_6 = 0 ; V_6 < V_78 ; V_6 ++ ) {
V_105 = V_107 [ V_6 ] ;
F_26 ( L_91 , V_105 ) ;
if ( V_105 == V_15 . V_105 ) {
F_26 ( L_92 ) ;
continue;
}
F_26 ( L_93 ) ;
V_110 -> V_111 = - 1 ;
V_95 = F_47 ( V_113 , 3 , 1 ,
NULL , V_105 , V_2 , V_110 ) ;
F_26 ( L_94 , V_95 ) ;
for ( V_106 = 0 ; V_106 < 100000000 && V_110 -> V_111 == - 1 ; V_106 ++ ) {
F_50 () ;
F_51 () ;
}
F_52 () ;
if ( V_110 -> V_111 != - 1 )
F_26 ( L_95 , V_110 -> V_111 ) ;
else
F_26 ( L_96 ) ;
}
}
F_26 ( L_97 ) ;
}
static void T_1 F_53 ( void )
{
struct V_109 * V_110 = & V_109 ;
struct V_114 * args = & V_110 -> args ;
T_8 V_26 = V_97 ;
T_8 V_115 , V_116 ;
args -> V_117 = ( T_8 ) V_118 ;
args -> V_119 = V_91 - V_118 ;
args -> V_120 = 0 ;
args -> V_121 = 0x60 ;
V_115 = F_32 ( args -> V_119 , V_26 ) ;
if ( V_92 != 0 ) {
args -> V_122 = V_92 ;
args -> V_123 = V_93 - args -> V_122 ;
args -> V_124 = V_115 ;
V_115 = F_32 ( args -> V_124 + args -> V_123 , V_26 ) ;
}
V_116 = F_35 ( 0x40000000 - V_96 , V_26 ) ;
if ( V_116 < V_115 )
V_116 = V_115 ;
args -> V_125 = V_116 ;
F_22 ( V_126 , V_53 ,
V_55 ) ;
F_26 ( L_98 , args -> V_117 ) ;
F_26 ( L_99 , args -> V_119 ) ;
F_26 ( L_100 , args -> V_120 ) ;
F_26 ( L_101 , args -> V_121 ) ;
F_26 ( L_102 , args -> V_125 ) ;
F_26 ( L_103 , args -> V_122 ) ;
F_26 ( L_104 , args -> V_123 ) ;
F_26 ( L_105 , args -> V_124 ) ;
F_10 ( L_106 ) ;
F_43 () ;
F_51 () ;
V_110 -> V_112 = 1 ;
for (; ; )
F_54 ( args ) ;
}
static void T_1 F_55 ( void )
{
T_3 V_127 ;
T_5 V_128 ;
T_8 V_47 , V_2 ;
T_8 V_19 = 0 , V_26 = 0x10000 ;
T_9 V_129 ;
V_38 V_11 [ 2 ] ;
F_26 ( L_107 ) ;
V_127 = F_2 ( L_77 , 1 , 1 , F_4 ( L_108 ) ) ;
F_26 ( L_109 , V_127 ) ;
if ( ! F_45 ( V_127 ) )
return;
V_129 = 0 ;
F_13 ( V_127 , L_110 , & V_129 , sizeof( V_129 ) ) ;
V_19 = F_56 ( V_129 ) ;
if ( V_19 == 0 )
return;
V_129 = 0 ;
F_13 ( V_127 , L_111 , & V_129 , sizeof( V_129 ) ) ;
V_26 = F_56 ( V_129 ) ;
V_47 = F_34 ( V_19 , V_26 , 0 ) ;
if ( V_47 == 0 ) {
F_10 ( L_112 ) ;
return;
}
V_128 = F_2 ( L_31 , 1 , 1 , F_4 ( L_108 ) ) ;
if ( ! F_57 ( V_128 ) ) {
F_10 ( L_113 , V_128 ) ;
return;
}
F_10 ( L_114 , V_47 ) ;
if ( F_6 ( L_4 , 4 , 3 , V_11 ,
F_4 ( L_115 ) ,
V_128 ,
V_47 >> 32 , V_47 & 0xffffffff ) != 0
|| ( V_11 [ 0 ] == 0 && V_11 [ 1 ] == 0 ) ) {
F_10 ( L_116 ) ;
return;
}
V_2 = ( ( ( T_8 ) V_11 [ 0 ] ) << 32 ) | V_11 [ 1 ] ;
F_10 ( L_41 ) ;
F_37 ( V_47 , V_19 ) ;
F_26 ( L_117 , V_47 ) ;
F_26 ( L_118 , V_26 ) ;
F_26 ( L_119 , V_2 ) ;
F_26 ( L_120 , ( long ) V_19 ) ;
F_17 ( V_127 , L_108 , L_121 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_127 , L_108 , L_122 ,
& V_2 , sizeof( V_2 ) ) ;
#ifdef F_58
V_130 = V_47 ;
V_131 = V_2 ;
#endif
F_26 ( L_123 ) ;
}
static void T_1 F_59 ( void )
{
T_3 V_132 ;
T_5 V_133 ;
V_38 V_47 , V_2 = 0 ;
T_6 V_16 ;
V_38 V_19 = 0 ;
F_26 ( L_124 ) ;
V_132 = F_2 ( L_77 , 1 , 1 , F_4 ( L_125 ) ) ;
F_26 ( L_126 , V_132 ) ;
if ( ! F_45 ( V_132 ) )
return;
V_16 = 0 ;
F_13 ( V_132 , L_127 , & V_16 , sizeof( V_19 ) ) ;
V_19 = F_5 ( V_16 ) ;
if ( V_19 == 0 )
return;
V_47 = F_34 ( V_19 , V_80 , 0 ) ;
if ( V_47 == 0 )
F_33 ( L_128 ) ;
V_133 = F_2 ( L_31 , 1 , 1 , F_4 ( L_125 ) ) ;
if ( ! F_57 ( V_133 ) ) {
F_10 ( L_129 , V_133 ) ;
return;
}
F_10 ( L_130 , V_47 ) ;
if ( F_6 ( L_4 , 3 , 2 , & V_2 ,
F_4 ( L_131 ) ,
V_133 , V_47 ) != 0
|| V_2 == 0 ) {
F_10 ( L_116 ) ;
return;
}
F_10 ( L_41 ) ;
F_37 ( V_47 , V_19 ) ;
V_16 = F_3 ( V_47 ) ;
F_17 ( V_132 , L_125 , L_132 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_3 ( V_2 ) ;
F_17 ( V_132 , L_125 , L_133 ,
& V_16 , sizeof( V_16 ) ) ;
if ( F_13 ( V_132 , L_134 ,
& V_16 , sizeof( V_16 ) ) != V_10 )
V_134 = true ;
#if F_60 ( V_135 ) && F_60 ( F_30 )
V_103 = V_47 ;
V_104 = V_2 ;
F_13 ( V_132 , L_135 , & V_113 , 4 ) ;
#endif
F_26 ( L_136 , V_47 ) ;
F_26 ( L_137 , V_2 ) ;
F_26 ( L_138 , ( long ) V_19 ) ;
F_26 ( L_139 ) ;
}
static void T_1 F_61 ( void )
{
T_3 V_136 ;
T_5 V_137 ;
V_38 V_2 = 0 , V_19 = 0 ;
T_8 V_47 ;
F_26 ( L_140 ) ;
V_136 = F_2 ( L_77 , 1 , 1 , F_4 ( L_141 ) ) ;
F_26 ( L_142 , V_136 ) ;
if ( ! F_45 ( V_136 ) )
return;
V_137 = F_2 ( L_31 , 1 , 1 , F_4 ( L_141 ) ) ;
if ( ! F_57 ( V_137 ) ) {
F_10 ( L_143 , V_137 ) ;
return;
}
if ( F_6 ( L_4 , 2 , 2 , & V_19 ,
F_4 ( L_144 ) ,
V_137 ) != 0 || V_19 == 0 ) {
F_10 ( L_145 ) ;
return;
}
V_47 = F_34 ( V_19 , V_80 , 0 ) ;
if ( V_47 == 0 )
F_33 ( L_146 ) ;
F_10 ( L_147 , V_47 ) ;
if ( F_6 ( L_4 , 4 , 2 , & V_2 ,
F_4 ( L_148 ) ,
V_137 , V_19 , V_47 ) != 0 || V_2 == 0 ) {
F_10 ( L_149 ) ;
return;
}
F_10 ( L_41 ) ;
F_37 ( V_47 , V_19 ) ;
F_17 ( V_136 , L_141 , L_150 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_136 , L_141 , L_151 ,
& V_19 , sizeof( V_19 ) ) ;
F_26 ( L_152 , V_47 ) ;
F_26 ( L_153 , ( long ) V_19 ) ;
F_26 ( L_154 ) ;
}
static void T_1 F_62 ( void )
{
T_3 V_34 ;
T_5 V_138 ;
char V_139 [ 64 ] , type [ 64 ] , V_140 [ 64 ] ;
char * V_83 = V_86 ;
T_8 V_47 , V_26 ;
V_38 V_141 , V_142 ;
T_8 V_143 , * V_144 ;
T_8 V_145 , V_146 ;
T_8 V_6 ;
if ( V_56 )
return;
F_26 ( L_155 ) ;
V_145 = V_71 ;
V_146 = V_145 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
V_139 [ 0 ] = 0 ;
type [ 0 ] = 0 ;
V_140 [ 0 ] = 0 ;
F_13 ( V_34 , L_156 ,
V_139 , sizeof( V_139 ) ) ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
F_13 ( V_34 , L_157 , V_140 , sizeof( V_140 ) ) ;
if ( ( type [ 0 ] == 0 ) || ( strstr ( type , L_158 ) == NULL ) )
continue;
if ( V_139 [ 0 ] != 0 ) {
if ( ( strstr ( V_139 , L_159 ) == NULL ) &&
( strstr ( V_139 , L_160 ) == NULL ) &&
( strstr ( V_139 , L_161 ) == NULL ) )
continue;
} else if ( V_140 [ 0 ] != 0 ) {
if ( ( strstr ( V_140 , L_162 ) == NULL ) &&
( strstr ( V_140 , L_163 ) == NULL ) &&
( strstr ( V_140 , L_164 ) == NULL ) )
continue;
}
if ( F_13 ( V_34 , L_165 , & V_141 ,
sizeof( V_141 ) ) == V_10 )
V_141 = 0 ;
if ( F_13 ( V_34 , L_166 , & V_142 ,
sizeof( V_142 ) ) == V_10 )
V_142 = 4UL << 20 ;
if ( F_63 ( V_147 ) || F_63 ( V_148 ) )
V_142 = 8UL << 20 ;
else
V_142 = 4UL << 20 ;
V_26 = F_64 ( V_141 , V_142 ) ;
V_47 = F_34 ( V_142 , V_26 , 1 ) ;
if ( V_47 == 0 )
F_33 ( L_167 ) ;
if ( V_47 < V_146 )
V_146 = V_47 ;
memset ( V_83 , 0 , V_88 ) ;
if ( F_2 ( L_69 , 3 , 1 , V_34 ,
V_83 , V_88 - 1 ) == V_10 ) {
F_10 ( L_168 ) ;
}
F_17 ( V_34 , V_83 , L_169 , & V_47 , sizeof( V_47 ) ) ;
F_17 ( V_34 , V_83 , L_170 , & V_142 , sizeof( V_142 ) ) ;
F_26 ( L_171 , V_83 ) ;
F_26 ( L_172 , V_34 ) ;
F_26 ( L_173 , V_47 ) ;
F_26 ( L_174 , V_142 ) ;
V_144 = ( T_8 * ) V_47 ;
for ( V_6 = 0 ; V_6 < ( V_142 >> 3 ) ; V_144 ++ , V_6 ++ ) {
V_143 = ( V_6 << V_149 ) ;
V_143 |= 0x3 ;
* V_144 = V_143 ;
}
F_10 ( L_175 , V_83 ) ;
V_138 = F_2 ( L_31 , 1 , 1 , V_83 ) ;
if ( V_138 == 0 )
F_10 ( L_176 ) ;
else
F_10 ( L_177 ) ;
F_2 ( L_4 , 6 , 0 , F_4 ( L_178 ) ,
V_138 , - 1 , V_142 ,
( V_38 ) V_47 , ( V_38 ) ( V_47 >> 32 ) ) ;
F_2 ( L_40 , 1 , 0 , V_138 ) ;
}
F_37 ( V_146 , V_145 - V_146 ) ;
V_150 = V_146 ;
V_151 = V_145 ;
F_26 ( L_179 ) ;
}
static void T_1 F_65 ( void )
{
unsigned long V_6 ;
T_3 V_34 ;
char type [ 64 ] ;
unsigned long * V_152
= ( void * ) F_66 ( V_153 ) ;
unsigned long * V_154
= ( void * ) F_66 ( V_155 ) ;
unsigned long V_156 = F_66 ( V_157 ) ;
if ( ( V_89 == V_158 ||
V_89 == V_159 ) &&
V_134 ) {
F_10 ( L_180 ) ;
return;
}
F_26 ( L_181 ) ;
F_26 ( L_182 , ( unsigned long ) V_152 ) ;
F_26 ( L_183 , * V_152 ) ;
F_26 ( L_184 ,
( unsigned long ) V_154 ) ;
F_26 ( L_185 , * V_154 ) ;
F_26 ( L_186 , V_156 ) ;
* V_152 = 0 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
unsigned int V_160 ;
T_6 V_161 ;
type [ 0 ] = 0 ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_26 ) != 0 )
continue;
if ( F_13 ( V_34 , L_89 , type , sizeof( type ) ) > 0 )
if ( strcmp ( type , L_90 ) != 0 )
continue;
V_161 = F_3 ( - 1 ) ;
F_13 ( V_34 , L_67 , & V_161 , sizeof( V_161 ) ) ;
V_160 = F_5 ( V_161 ) ;
F_26 ( L_187 , V_160 ) ;
* V_154 = ( unsigned long ) - 1 ;
if ( V_160 != V_15 . V_105 ) {
F_10 ( L_188 , V_160 ) ;
F_2 ( L_135 , 3 , 0 , V_34 ,
V_156 , V_160 ) ;
for ( V_6 = 0 ; ( V_6 < 100000000 ) &&
( * V_154 == ( ( unsigned long ) - 1 ) ) ; V_6 ++ )
F_51 () ;
if ( * V_154 == V_160 )
F_10 ( L_189 ) ;
else
F_10 ( L_190 , * V_154 ) ;
}
#ifdef F_67
else
F_10 ( L_191 , V_160 ) ;
#endif
}
F_26 ( L_192 ) ;
}
static void T_1 F_68 ( unsigned long V_162 )
{
V_9 = V_162 ;
V_15 . V_54 = F_2 ( L_77 , 1 , 1 , F_4 ( L_193 ) ) ;
if ( ! F_45 ( V_15 . V_54 ) )
F_33 ( L_194 ) ;
V_15 . V_60 = F_2 ( L_77 , 1 , 1 , F_4 ( L_32 ) ) ;
if ( ! F_45 ( V_15 . V_60 ) )
F_33 ( L_195 ) ;
V_15 . V_32 = 0 ;
}
static void T_1 F_69 ( void )
{
T_3 V_163 ;
char V_164 [ 64 ] ;
V_163 = F_2 ( L_77 , 1 , 1 , F_4 ( L_196 ) ) ;
if ( ! F_45 ( V_163 ) )
return;
if ( F_13 ( V_163 , L_157 , V_164 , sizeof( V_164 ) ) <= 0 )
return;
V_164 [ sizeof( V_164 ) - 1 ] = 0 ;
if ( strcmp ( V_164 , L_197 ) == 0 )
V_165 = V_28 ;
else if ( strncmp ( V_164 , L_198 , 12 ) == 0 ) {
V_165 = V_28 | V_44 ;
F_2 ( L_17 , 1 , 1 , L_199 ) ;
} else
return;
V_15 . V_31 = F_2 ( L_31 , 1 , 1 , F_4 ( L_200 ) ) ;
F_13 ( V_15 . V_54 , L_201 , & V_15 . V_32 ,
sizeof( V_15 . V_32 ) ) ;
V_15 . V_32 = F_5 ( V_15 . V_32 ) ;
if ( ! F_57 ( V_15 . V_31 ) || ! F_57 ( V_15 . V_32 ) )
V_165 &= ~ V_28 ;
}
static void T_1 F_70 ( void )
{
char * V_83 = V_166 ;
char type [ 16 ] ;
T_3 V_167 ;
T_6 V_16 ;
if ( F_13 ( V_15 . V_54 , L_202 , & V_16 , sizeof( V_16 ) ) <= 0 )
F_33 ( L_203 ) ;
V_15 . stdout = F_5 ( V_16 ) ;
memset ( V_83 , 0 , 256 ) ;
F_2 ( L_204 , 3 , 1 , V_15 . stdout , V_83 , 255 ) ;
V_167 = F_2 ( L_205 , 1 , 1 , V_15 . stdout ) ;
V_16 = F_3 ( V_167 ) ;
F_17 ( V_15 . V_54 , L_193 , L_206 ,
& V_16 , sizeof( V_16 ) ) ;
F_10 ( L_207 , V_166 ) ;
F_17 ( V_15 . V_54 , L_193 , L_208 ,
V_83 , strlen ( V_83 ) + 1 ) ;
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_167 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_209 ) == 0 )
F_17 ( V_167 , V_83 , L_210 , NULL , 0 ) ;
}
static int T_1 F_71 ( void )
{
char V_168 [ 256 ] ;
int V_169 , V_6 = 0 ;
#ifdef F_23
T_3 V_170 ;
int V_40 ;
#endif
V_169 = F_13 ( V_15 . V_60 , L_156 ,
V_168 , sizeof( V_168 ) - 1 ) ;
if ( V_169 > 0 ) {
V_168 [ V_169 ] = 0 ;
while ( V_6 < V_169 ) {
char * V_13 = & V_168 [ V_6 ] ;
int V_171 = strlen ( V_13 ) ;
if ( V_171 == 0 )
break;
if ( strstr ( V_13 , L_211 ) ||
strstr ( V_13 , L_212 ) )
return V_172 ;
#ifdef F_23
if ( strstr ( V_13 , L_213 ) ||
strstr ( V_13 , L_214 ) )
return V_173 ;
#endif
V_6 += V_171 + 1 ;
}
}
#ifdef F_23
if ( F_45 ( F_2 ( L_77 , 1 , 1 , F_4 ( L_108 ) ) ) )
return V_98 ;
V_169 = F_13 ( V_15 . V_60 , L_25 ,
V_168 , sizeof( V_168 ) - 1 ) ;
if ( V_169 <= 0 )
return V_173 ;
if ( strcmp ( V_168 , L_215 ) )
return V_173 ;
V_170 = F_2 ( L_77 , 1 , 1 , F_4 ( L_125 ) ) ;
if ( ! F_45 ( V_170 ) )
return V_173 ;
V_40 = F_14 ( V_170 , L_216 ) ;
if ( V_40 != V_10 ) {
F_26 ( L_217 ) ;
return V_159 ;
}
return V_158 ;
#else
return V_173 ;
#endif
}
static int T_1 F_72 ( T_5 V_174 , int V_6 , int V_76 , int V_175 , int V_176 )
{
return F_2 ( L_4 , 6 , 1 , F_4 ( L_218 ) , V_174 , V_6 , V_176 , V_175 , V_76 ) ;
}
static void T_1 F_73 ( void )
{
char type [ 16 ] , * V_83 ;
T_3 V_34 ;
T_5 V_174 ;
int V_6 ;
static unsigned char V_177 [] = {
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
const unsigned char * V_178 ;
F_26 ( L_219 ) ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_34 , L_25 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_209 ) != 0 )
continue;
V_83 = V_86 ;
memset ( V_83 , 0 , V_88 ) ;
if ( F_2 ( L_69 , 3 , 1 , V_34 , V_83 ,
V_88 - 10 ) == V_10 )
continue;
F_10 ( L_220 , V_83 ) ;
V_174 = F_2 ( L_31 , 1 , 1 , V_83 ) ;
if ( V_174 == 0 ) {
F_10 ( L_221 ) ;
continue;
}
F_10 ( L_189 ) ;
F_17 ( V_34 , V_83 , L_222 , NULL , 0 ) ;
V_178 = V_177 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ , V_178 += 3 )
if ( F_72 ( V_174 , V_6 , V_178 [ 0 ] , V_178 [ 1 ] ,
V_178 [ 2 ] ) != 0 )
break;
#ifdef F_74
V_178 = F_75 ( V_179 . V_178 ) ;
for ( V_6 = 0 ; V_6 < V_179 . V_180 ; V_6 ++ , V_178 += 3 )
if ( F_72 ( V_174 , V_6 + 32 , V_178 [ 0 ] , V_178 [ 1 ] ,
V_178 [ 2 ] ) != 0 )
break;
#endif
#ifdef F_76
if ( F_13 ( V_34 , L_210 , NULL , 0 ) !=
V_10 ) {
V_38 V_181 , V_182 , V_183 , V_68 ;
F_10 ( L_223 ) ;
F_13 ( V_34 , L_224 , & V_181 , 4 ) ;
F_13 ( V_34 , L_225 , & V_182 , 4 ) ;
F_13 ( V_34 , L_226 , & V_183 , 4 ) ;
F_13 ( V_34 , L_227 , & V_68 , 4 ) ;
F_10 ( L_228 ,
V_181 , V_182 , V_183 , V_68 ) ;
F_77 ( V_181 , V_182 , 8 , V_183 , V_68 ) ;
}
#endif
}
}
static void T_1 * F_78 ( unsigned long * V_184 , unsigned long * V_185 ,
unsigned long V_186 , unsigned long V_26 )
{
void * V_29 ;
* V_184 = F_79 ( * V_184 , V_26 ) ;
while ( ( * V_184 + V_186 ) > * V_185 ) {
unsigned long V_187 , V_188 ;
F_26 ( L_229 ,
V_67 ) ;
V_187 = V_70 - V_67 ;
if ( V_187 > V_189 )
V_187 = V_189 ;
if ( V_187 < V_80 )
F_33 ( L_230
L_231 ) ;
V_188 = F_31 ( V_187 , 0 ) ;
if ( V_188 == 0 )
F_33 ( L_230
L_232 ) ;
* V_185 = V_188 + V_187 ;
}
V_29 = ( void * ) * V_184 ;
* V_184 += V_186 ;
return V_29 ;
}
static unsigned long T_1 F_80 ( char * V_39 )
{
char * V_22 , * V_190 ;
V_22 = V_190 = ( char * ) V_191 ;
V_22 += 4 ;
while ( V_22 < ( char * ) V_192 ) {
if ( strcmp ( V_22 , V_39 ) == 0 )
return V_22 - V_190 ;
V_22 += strlen ( V_22 ) + 1 ;
}
return 0 ;
}
static void T_1 F_81 ( T_3 V_34 ,
unsigned long * V_184 ,
unsigned long * V_185 )
{
char * V_193 , * V_194 , * V_195 ;
unsigned long V_196 ;
T_3 V_197 ;
V_195 = ( char * ) V_191 ;
V_193 = L_233 ;
for (; ; ) {
V_194 = F_78 ( V_184 , V_185 , V_198 , 1 ) ;
if ( F_2 ( L_234 , 3 , 1 , V_34 , V_193 , V_194 ) != 1 ) {
* V_184 = ( unsigned long ) V_194 ;
break;
}
if ( strcmp ( V_194 , L_65 ) == 0 ) {
* V_184 = ( unsigned long ) V_194 ;
V_193 = L_65 ;
continue;
}
V_196 = F_80 ( V_194 ) ;
if ( V_196 != 0 ) {
* V_184 = ( unsigned long ) V_194 ;
V_194 = V_195 + V_196 ;
} else {
* V_184 = ( unsigned long ) V_194 + strlen ( V_194 ) + 1 ;
V_192 = * V_184 ;
}
V_193 = V_194 ;
}
V_197 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_197 != 0 ) {
F_81 ( V_197 , V_184 , V_185 ) ;
V_197 = F_2 ( L_9 , 1 , 1 , V_197 ) ;
}
}
static void T_1 F_82 ( T_3 V_34 , unsigned long * V_184 ,
unsigned long * V_185 )
{
T_3 V_197 ;
char * V_194 , * V_193 , * V_195 , * V_13 , * V_199 , * V_200 , * V_83 ;
unsigned long V_196 ;
unsigned char * V_201 ;
static char V_35 [ V_198 ] ;
int V_52 , V_187 , V_202 = 0 ;
F_83 ( V_203 , V_184 , V_185 ) ;
V_194 = ( char * ) * V_184 ;
V_187 = * V_185 - * V_184 ;
if ( V_187 > 255 )
V_187 = 255 ;
V_52 = F_2 ( L_69 , 3 , 1 , V_34 , V_194 , V_187 ) ;
if ( V_52 >= 0 ) {
if ( V_52 >= V_187 ) {
if ( V_52 >= * V_185 - * V_184 )
V_194 = F_78 ( V_184 , V_185 , V_52 + 1 , 1 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_194 , V_52 ) ;
}
V_194 [ V_52 ] = '\0' ;
for ( V_200 = V_13 = V_194 , V_199 = V_194 + V_52 ; V_13 < V_199 ; V_13 ++ ) {
if ( * V_13 == '/' )
V_200 = V_194 ;
else if ( * V_13 != 0 )
* V_200 ++ = * V_13 ;
}
* V_200 = 0 ;
* V_184 = F_79 ( ( unsigned long ) V_200 + 1 , 4 ) ;
}
V_83 = V_86 ;
memset ( V_83 , 0 , V_88 ) ;
F_2 ( L_69 , 3 , 1 , V_34 , V_83 , V_88 - 1 ) ;
V_193 = L_233 ;
V_195 = ( char * ) V_191 ;
for (; ; ) {
if ( F_2 ( L_234 , 3 , 1 , V_34 , V_193 ,
V_35 ) != 1 )
break;
if ( strcmp ( V_35 , L_65 ) == 0 ) {
V_193 = L_65 ;
continue;
}
V_196 = F_80 ( V_35 ) ;
if ( V_196 == 0 ) {
F_10 ( L_235
L_236 , V_35 , V_83 ) ;
break;
}
V_193 = V_195 + V_196 ;
V_52 = F_2 ( L_12 , 2 , 1 , V_34 , V_35 ) ;
if ( V_52 == V_10 )
continue;
F_83 ( V_204 , V_184 , V_185 ) ;
F_83 ( V_52 , V_184 , V_185 ) ;
F_83 ( V_196 , V_184 , V_185 ) ;
V_201 = F_78 ( V_184 , V_185 , V_52 , 4 ) ;
F_2 ( L_11 , 4 , 1 , V_34 , V_35 , V_201 , V_52 ) ;
* V_184 = F_79 ( * V_184 , 4 ) ;
if ( ! strcmp ( V_35 , L_237 ) )
V_202 = 1 ;
}
if ( ! V_202 ) {
V_196 = F_80 ( L_238 ) ;
if ( V_196 == 0 )
F_10 ( L_235
L_239 , V_83 ) ;
else {
F_83 ( V_204 , V_184 , V_185 ) ;
F_83 ( 4 , V_184 , V_185 ) ;
F_83 ( V_196 , V_184 , V_185 ) ;
V_201 = F_78 ( V_184 , V_185 , 4 , 4 ) ;
* ( T_6 * ) V_201 = F_3 ( V_34 ) ;
}
}
V_197 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_197 != 0 ) {
F_82 ( V_197 , V_184 , V_185 ) ;
V_197 = F_2 ( L_9 , 1 , 1 , V_197 ) ;
}
F_83 ( V_205 , V_184 , V_185 ) ;
}
static void T_1 F_84 ( void )
{
T_3 V_60 ;
unsigned long V_184 , V_185 , V_187 ;
struct V_206 * V_207 ;
char * V_194 ;
T_8 * V_208 ;
V_187 = V_70 - V_67 - 0x4000 ;
if ( V_187 > V_189 )
V_187 = V_189 ;
F_26 ( L_240 , V_67 ) ;
V_184 = ( unsigned long ) F_31 ( V_187 , V_80 ) ;
if ( V_184 == 0 )
F_33 ( L_241 ) ;
V_185 = V_184 + V_187 ;
V_60 = F_2 ( L_9 , 1 , 1 , ( T_3 ) 0 ) ;
if ( V_60 == ( T_3 ) 0 )
F_33 ( L_242 ) ;
V_184 = F_79 ( V_184 , 4 ) ;
V_207 = F_78 ( & V_184 , & V_185 ,
sizeof( struct V_206 ) , 4 ) ;
V_209 = ( unsigned long ) V_207 ;
V_208 = F_78 ( & V_184 , & V_185 , sizeof( V_82 ) , 8 ) ;
V_184 = F_41 ( V_184 ) ;
V_191 = V_184 ;
V_184 += 4 ;
V_194 = F_78 ( & V_184 , & V_185 , 16 , 1 ) ;
strcpy ( V_194 , L_238 ) ;
V_184 = ( unsigned long ) V_194 + strlen ( V_194 ) + 1 ;
F_10 ( L_243 ) ;
F_81 ( V_60 , & V_184 , & V_185 ) ;
V_192 = V_184 ;
V_184 = F_41 ( V_184 ) ;
V_210 = V_184 ;
F_10 ( L_244 ) ;
F_82 ( V_60 , & V_184 , & V_185 ) ;
F_83 ( V_211 , & V_184 , & V_185 ) ;
V_212 = F_41 ( V_184 ) ;
V_207 -> V_213 = F_3 ( V_15 . V_105 ) ;
V_207 -> V_214 = F_3 ( V_215 ) ;
V_207 -> V_216 = F_3 ( V_212 - V_209 ) ;
V_207 -> V_217 = F_3 ( V_210 - V_209 ) ;
V_207 -> V_218 = F_3 ( V_191 - V_209 ) ;
V_207 -> V_219 = F_3 ( V_192 - V_191 ) ;
V_207 -> V_220 = F_3 ( ( ( unsigned long ) V_208 ) - V_209 ) ;
V_207 -> V_164 = F_3 ( V_221 ) ;
V_207 -> V_222 = F_3 ( 0x10 ) ;
memcpy ( V_208 , V_82 , sizeof( V_82 ) ) ;
#ifdef F_40
{
int V_6 ;
F_10 ( L_245 ) ;
for ( V_6 = 0 ; V_6 < V_79 ; V_6 ++ )
F_10 ( L_246 ,
F_56 ( V_82 [ V_6 ] . V_47 ) ,
F_56 ( V_82 [ V_6 ] . V_19 ) ) ;
}
#endif
V_79 = V_81 ;
F_10 ( L_247 ,
V_191 , V_192 ) ;
F_10 ( L_248 ,
V_210 , V_212 ) ;
}
static void T_1 F_85 ( void )
{
T_3 V_223 ;
V_38 V_224 = 0x01002000 ;
V_38 V_225 [ 6 ] ;
char * V_226 ;
V_226 = L_249 ;
V_223 = F_2 ( L_77 , 1 , 1 , F_4 ( V_226 ) ) ;
if ( ! F_45 ( V_223 ) ) {
V_226 = L_250 ;
V_223 = F_2 ( L_77 , 1 , 1 , F_4 ( V_226 ) ) ;
V_224 = 0x01003000 ;
}
if ( ! F_45 ( V_223 ) )
return;
if ( F_14 ( V_223 , L_251 ) != 12 )
return;
if ( F_13 ( V_223 , L_251 , V_225 , sizeof( V_225 ) )
== V_10 )
return;
if ( V_225 [ 0 ] != 0x1 ||
V_225 [ 1 ] != 0xf4000000 ||
V_225 [ 2 ] != 0x00010000 )
return;
F_10 ( L_252 ) ;
V_225 [ 0 ] = 0x1 ;
V_225 [ 1 ] = 0x0 ;
V_225 [ 2 ] = V_224 ;
V_225 [ 3 ] = 0x0 ;
V_225 [ 4 ] = 0x0 ;
V_225 [ 5 ] = 0x00010000 ;
F_17 ( V_223 , V_226 , L_251 ,
V_225 , sizeof( V_225 ) ) ;
}
static void T_1 F_86 ( void )
{
T_3 V_227 ;
V_38 V_228 [ 4 ] ;
char * V_226 = L_253 ;
V_38 V_229 , V_230 ;
V_227 = F_2 ( L_77 , 1 , 1 , F_4 ( V_226 ) ) ;
if ( ! F_45 ( V_227 ) )
return;
if ( F_14 ( V_227 , L_67 ) != 8 )
return;
F_13 ( V_15 . V_60 , L_60 , & V_229 , sizeof( V_229 ) ) ;
F_13 ( V_15 . V_60 , L_61 , & V_230 , sizeof( V_230 ) ) ;
if ( ( V_229 != 2 ) || ( V_230 != 2 ) )
return;
if ( F_13 ( V_227 , L_67 , V_228 , sizeof( V_228 ) ) == V_10 )
return;
if ( V_228 [ 0 ] != V_231 || V_228 [ 1 ] != V_232 )
return;
F_10 ( L_254 ) ;
V_228 [ 0 ] = 0x0 ;
V_228 [ 1 ] = V_231 ;
V_228 [ 2 ] = 0x0 ;
V_228 [ 3 ] = V_232 ;
F_17 ( V_227 , V_226 , L_67 , V_228 , sizeof( V_228 ) ) ;
}
static void T_1 F_87 ( void )
{
T_3 V_233 ;
V_38 V_234 [ 6 ] ;
V_38 V_224 = 0x01006000 ;
char * V_226 ;
int V_95 ;
V_226 = L_255 ;
V_233 = F_2 ( L_77 , 1 , 1 , F_4 ( V_226 ) ) ;
if ( ! F_45 ( V_233 ) ) {
V_226 = L_256 ;
V_233 = F_2 ( L_77 , 1 , 1 , F_4 ( V_226 ) ) ;
V_224 = 0x01003000 ;
}
if ( F_45 ( V_233 ) ) {
V_95 = F_14 ( V_233 , L_251 ) ;
if ( V_95 == 0 || V_95 == V_10 ) {
F_10 ( L_257 ) ;
V_234 [ 0 ] = 0x1 ;
V_234 [ 1 ] = 0x0 ;
V_234 [ 2 ] = V_224 ;
V_234 [ 3 ] = 0x0 ;
V_234 [ 4 ] = 0x0 ;
V_234 [ 5 ] = 0x00010000 ;
F_17 ( V_233 , V_226 , L_251 , V_234 , sizeof( V_234 ) ) ;
}
}
V_226 = L_258 ;
V_233 = F_2 ( L_77 , 1 , 1 , F_4 ( V_226 ) ) ;
if ( F_45 ( V_233 ) ) {
F_10 ( L_259 ) ;
V_234 [ 0 ] = 14 ;
V_234 [ 1 ] = 0x0 ;
F_17 ( V_233 , V_226 , L_260 , V_234 , 2 * sizeof( V_38 ) ) ;
F_10 ( L_261 ) ;
V_95 = F_13 ( V_233 , L_262 , V_234 , sizeof( V_38 ) ) ;
if ( V_95 == sizeof( V_38 ) ) {
V_234 [ 0 ] &= ~ 0x5 ;
F_17 ( V_233 , V_226 , L_262 , V_234 , sizeof( V_38 ) ) ;
}
}
}
static void T_1 F_88 ( void )
{
T_3 V_235 , V_236 , V_237 ;
V_38 V_238 ;
V_38 V_239 [ 2 ] ;
V_38 V_240 ;
V_235 = F_2 ( L_77 , 1 , 1 , F_4 ( L_263 ) ) ;
if ( ! F_45 ( V_235 ) )
return;
V_236 = F_2 ( L_77 , 1 , 1 , F_4 ( L_264 ) ) ;
if ( ! F_45 ( V_236 ) )
return;
V_237 = F_2 ( L_77 , 1 , 1 , F_4 ( L_265 ) ) ;
if ( ! F_45 ( V_237 ) )
return;
if ( F_13 ( V_235 , L_266 , & V_238 , sizeof( V_238 ) )
== V_10 )
return;
if ( V_238 < 0x35 || V_238 > 0x39 )
return;
if ( F_14 ( V_236 , L_260 ) > 0 )
return;
F_10 ( L_267 ) ;
V_239 [ 0 ] = 0 ;
V_239 [ 1 ] = 1 ;
F_17 ( V_236 , L_264 , L_260 ,
& V_239 , sizeof( V_239 ) ) ;
V_240 = ( V_38 ) V_237 ;
F_17 ( V_236 , L_264 , L_268 ,
& V_240 , sizeof( V_240 ) ) ;
}
static void T_1 F_89 ( void )
{
V_38 V_34 ;
char V_234 [ 64 ] ;
int V_241 ;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_269 ) ) ;
if ( ! F_45 ( V_34 ) )
return;
V_241 = F_13 ( V_34 , L_270 , V_234 , sizeof( V_234 ) ) ;
if ( ! V_241 )
return;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_271 ) ) ;
if ( ! F_45 ( V_34 ) ) {
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
if ( ! F_45 ( V_34 ) ) {
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
static void T_1 F_90 ( void )
{
int V_242 [ 3 ] = { 2 , 2 , 0 } ;
int V_243 [ 3 * 16 ] = { 3 , 0 , 0 , 3 , 1 , 0 , 3 , 2 , 0 , 3 , 3 , 0 ,
3 , 4 , 0 , 3 , 5 , 0 , 3 , 6 , 0 , 3 , 7 , 0 ,
3 , 8 , 0 , 3 , 9 , 0 , 3 , 10 , 0 , 3 , 11 , 0 ,
3 , 12 , 0 , 3 , 13 , 0 , 3 , 14 , 0 , 3 , 15 , 0 } ;
V_38 V_34 ;
char V_234 [ 64 ] ;
int V_241 , V_169 ;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_32 ) ) ;
if ( ! F_45 ( V_34 ) )
return;
V_241 = F_13 ( V_34 , L_157 , V_234 , sizeof( V_234 ) ) ;
if ( V_241 == V_10 )
return;
if ( strcmp ( V_234 , L_297 ) )
return;
F_10 ( L_298 ) ;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_32 ) ) ;
V_241 = F_13 ( V_34 , L_25 , V_234 , sizeof( V_234 ) ) ;
if ( V_241 != V_10 && ( strcmp ( V_234 , L_215 ) == 0 ) )
F_17 ( V_34 , L_32 , L_25 , L_299 , sizeof( L_299 ) ) ;
V_241 = F_13 ( V_34 , L_300 , V_234 , sizeof( V_234 ) ) ;
if ( V_241 != V_10 && ( strstr ( V_234 , L_301 ) ) )
F_17 ( V_34 , L_32 , L_300 ,
L_302 ,
sizeof( L_302 ) ) ;
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_303 ) ) ;
if ( F_45 ( V_34 ) ) {
V_169 = F_14 ( V_34 , L_260 ) ;
if ( V_169 == 12 ) {
F_10 ( L_304 ) ;
F_17 ( V_34 , L_305 , L_260 ,
V_243 , sizeof( V_243 ) ) ;
}
}
V_34 = F_2 ( L_77 , 1 , 1 , F_4 ( L_306 ) ) ;
if ( F_45 ( V_34 ) ) {
V_241 = F_13 ( V_34 , L_260 , V_234 , sizeof( V_234 ) ) ;
if ( V_241 == V_10 ) {
F_10 ( L_307 ) ;
F_17 ( V_34 , L_306 , L_260 ,
V_242 , sizeof( V_242 ) ) ;
}
}
F_89 () ;
}
static void T_1 F_91 ( void )
{
F_85 () ;
F_86 () ;
F_87 () ;
F_88 () ;
F_90 () ;
}
static void T_1 F_92 ( void )
{
T_6 V_244 ;
T_5 V_245 ;
T_3 V_246 ;
V_244 = 0 ;
if ( F_13 ( V_15 . V_54 , L_26 , & V_244 , sizeof( V_244 ) ) <= 0 )
return;
V_245 = F_5 ( V_244 ) ;
V_246 = F_2 ( L_205 , 1 , 1 , V_245 ) ;
F_13 ( V_246 , L_67 , & V_244 , sizeof( V_244 ) ) ;
V_15 . V_105 = F_5 ( V_244 ) ;
F_26 ( L_308 , V_15 . V_105 ) ;
}
static void T_1 F_93 ( unsigned long V_247 , unsigned long V_248 )
{
#ifdef F_94
if ( V_247 && V_248 && V_248 != 0xdeadbeef ) {
T_9 V_16 ;
V_92 = F_95 ( V_247 ) ? F_96 ( V_247 ) : V_247 ;
V_93 = V_92 + V_248 ;
V_16 = F_38 ( V_92 ) ;
F_17 ( V_15 . V_54 , L_193 , L_309 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_38 ( V_93 ) ;
F_17 ( V_15 . V_54 , L_193 , L_310 ,
& V_16 , sizeof( V_16 ) ) ;
F_37 ( V_92 ,
V_93 - V_92 ) ;
F_26 ( L_311 , V_92 ) ;
F_26 ( L_312 , V_93 ) ;
}
#endif
}
static void F_97 ( void )
{
}
static void F_98 ( void )
{
}
static void F_99 ( unsigned long V_249 , unsigned long V_250 )
{
unsigned long V_6 ;
unsigned long * V_251 ;
asm volatile("addi %0,2,-0x8000" : "=b" (toc_entry));
for ( V_6 = 0 ; V_6 < V_250 ; V_6 ++ ) {
* V_251 = * V_251 + V_249 ;
V_251 ++ ;
}
}
static void F_97 ( void )
{
unsigned long V_249 = F_100 () ;
unsigned long V_250 =
( V_252 - V_253 ) / sizeof( long ) ;
F_99 ( V_249 , V_250 ) ;
F_51 () ;
}
static void F_98 ( void )
{
unsigned long V_249 = F_100 () ;
unsigned long V_250 =
( V_252 - V_253 ) / sizeof( long ) ;
F_51 () ;
F_99 ( - V_249 , V_250 ) ;
}
unsigned long T_1 F_101 ( unsigned long V_247 , unsigned long V_248 ,
unsigned long V_162 ,
unsigned long V_254 , unsigned long V_255 ,
unsigned long V_256 )
{
unsigned long V_207 ;
#ifdef F_102
unsigned long V_249 = F_100 () ;
F_103 ( V_249 ) ;
#else
F_97 () ;
#endif
memset ( & V_257 , 0 , V_258 - V_257 ) ;
F_68 ( V_162 ) ;
F_69 () ;
F_70 () ;
F_10 ( L_313 , V_259 ) ;
V_89 = F_71 () ;
F_10 ( L_314 , V_89 ) ;
#ifndef F_104
if ( V_260 > 0 )
F_33 ( L_315 ) ;
#endif
F_93 ( V_247 , V_248 ) ;
#if F_60 ( V_261 ) || F_60 ( V_135 )
if ( V_89 == V_158 ||
V_89 == V_159 )
F_27 () ;
#endif
if ( V_89 != V_172 )
F_105 ( 0 , V_256 , 0x100 , 0 ) ;
F_20 () ;
F_39 () ;
F_92 () ;
F_73 () ;
#if F_60 ( F_23 ) && F_60 ( F_30 )
if ( V_89 == V_158 )
F_62 () ;
#endif
if ( V_89 != V_172 &&
V_89 != V_98 )
F_59 () ;
#ifdef V_135
#ifdef F_30
if ( V_89 == V_159 ) {
F_44 () ;
if ( V_89 == V_98 ) {
F_49 () ;
F_53 () ;
}
} else
#endif
if ( V_89 == V_98 )
F_55 () ;
#endif
#ifdef F_23
F_61 () ;
#endif
if ( V_89 != V_172 &&
V_89 != V_98 )
F_65 () ;
if ( V_58 ) {
T_9 V_16 = F_38 ( V_58 ) ;
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
if ( V_150 ) {
F_17 ( V_15 . V_54 , L_193 , L_319 ,
& V_150 ,
sizeof( V_150 ) ) ;
F_17 ( V_15 . V_54 , L_193 , L_320 ,
& V_151 ,
sizeof( V_151 ) ) ;
}
#endif
F_91 () ;
F_10 ( L_321 ) ;
F_84 () ;
if ( V_89 != V_172 &&
V_89 != V_98 )
F_43 () ;
F_10 ( L_322 ) ;
F_2 ( L_323 , 0 , 0 ) ;
V_207 = V_209 ;
if ( V_89 != V_98 ) {
F_10 ( L_324 ) ;
F_26 ( L_325 , V_207 ) ;
}
#ifdef F_102
F_103 ( - V_249 ) ;
#else
F_98 () ;
#endif
#ifdef F_58
F_106 ( V_207 , V_256 , 0 , 0 , 0 ,
V_130 , V_131 ) ;
#else
F_106 ( V_207 , V_256 , 0 , 0 , 0 , 0 , 0 ) ;
#endif
return 0 ;
}
