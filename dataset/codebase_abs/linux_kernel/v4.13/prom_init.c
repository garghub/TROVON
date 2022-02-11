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
va_end ( args ) ;
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
static inline int F_13 ( T_3 V_34 , const char * V_35 ,
void * V_36 , T_4 V_37 )
{
return F_2 ( L_11 , 4 , 1 , V_34 , F_4 ( V_35 ) ,
( V_38 ) ( unsigned long ) V_36 , ( V_38 ) V_37 ) ;
}
static inline int F_14 ( T_3 V_34 , const char * V_35 )
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
V_51 = strstr ( V_53 , L_25 ) ;
if ( V_51 ) {
F_25 ( L_26 ) ;
V_59 = true ;
}
}
static int T_1 F_26 ( void )
{
T_3 V_34 ;
char type [ 64 ] ;
unsigned int V_60 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_13 ( V_34 , L_27 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_28 ) )
continue;
V_60 = F_14 ( V_34 , L_29 ) ;
if ( V_60 == V_10 )
break;
V_60 >>= 2 ;
F_25 ( L_30 , ( unsigned long ) V_60 ) ;
if ( V_60 < 1 || V_60 > 64 ) {
F_10 ( L_31 ,
( unsigned long ) V_60 ) ;
return 1 ;
}
return V_60 ;
}
F_25 ( L_32 ) ;
return 1 ;
}
static void T_1 F_27 ( T_5 V_16 ,
struct V_61 * V_62 )
{
switch ( V_16 ) {
case F_28 ( V_63 ) :
case F_28 ( V_64 ) :
F_25 ( L_33 ) ;
V_62 -> V_65 = ! V_59 ;
V_62 -> V_66 = true ;
break;
case F_28 ( V_67 ) :
F_25 ( L_34 ) ;
if ( V_59 ) {
F_10 ( L_35 ) ;
}
V_62 -> V_65 = true ;
break;
case F_28 ( V_68 ) :
F_25 ( L_36 ) ;
V_62 -> V_66 = true ;
break;
default:
F_25 ( L_37 , V_16 ) ;
break;
}
}
static void T_1 F_29 ( T_5 V_69 , T_5 V_16 ,
struct V_61 * V_62 )
{
switch ( V_69 ) {
case F_30 ( V_70 ) :
F_27 ( V_16 & F_28 ( V_70 ) , V_62 ) ;
break;
case F_30 ( V_71 ) :
if ( V_16 & F_28 ( V_71 ) ) {
F_25 ( L_38 ) ;
V_62 -> V_72 = true ;
}
break;
}
}
static void T_1 F_31 ( void )
{
struct V_61 V_73 = {
. V_66 = false ,
. V_65 = false ,
. V_72 = false
} ;
int V_74 = F_14 ( V_15 . V_54 ,
L_39 ) ;
if ( V_74 > 1 ) {
int V_6 ;
T_5 V_75 [ V_74 ] ;
F_25 ( L_40 ,
V_74 ) ;
F_13 ( V_15 . V_54 , L_39 ,
& V_75 , sizeof( V_75 ) ) ;
for ( V_6 = 0 ; V_6 < V_74 ; V_6 += 2 ) {
F_25 ( L_41 , V_6 / 2
, V_75 [ V_6 ]
, V_75 [ V_6 + 1 ] ) ;
F_29 ( V_75 [ V_6 ] , V_75 [ V_6 + 1 ] ,
& V_73 ) ;
}
}
if ( V_73 . V_65 && V_73 . V_72 ) {
F_25 ( L_42 ) ;
V_76 . V_77 . V_78 = F_28 ( V_67 ) ;
V_76 . V_77 . V_79 = F_28 ( V_71 ) ;
} else if ( V_73 . V_66 ) {
F_25 ( L_43 ) ;
V_76 . V_77 . V_78 = F_28 ( V_68 ) ;
} else {
F_25 ( L_44 ) ;
}
}
static void T_1 F_32 ( void )
{
T_6 V_80 ;
V_8 V_29 ;
V_38 V_81 ;
F_31 () ;
V_80 = F_2 ( L_45 , 1 , 1 , F_4 ( L_46 ) ) ;
if ( V_80 != 0 ) {
V_81 = F_33 ( V_82 , F_26 () ) ;
F_10 ( L_47 ,
V_81 , V_82 ) ;
V_76 . V_77 . V_83 = F_3 ( V_81 ) ;
F_10 ( L_48 ) ;
if ( F_6 ( L_4 , 3 , 2 , & V_29 ,
F_4 ( L_49 ) ,
V_80 ,
F_4 ( & V_76 ) ) == 0 ) {
if ( V_29 )
F_10 ( L_50
L_51 ) ;
F_2 ( L_52 , 1 , 0 , V_80 ) ;
F_10 ( L_53 ) ;
return;
}
F_2 ( L_52 , 1 , 0 , V_80 ) ;
F_10 ( L_54 ) ;
}
#ifdef F_34
{
T_6 V_84 ;
V_84 = F_2 ( L_45 , 1 , 1 ,
F_4 ( L_55 ) ) ;
if ( V_84 == 0 ) {
F_10 ( L_56 ) ;
return;
}
F_2 ( L_4 , 3 , 1 , F_4 ( L_57 ) ,
V_84 , F_4 ( & V_85 ) ) ;
F_2 ( L_52 , 1 , 0 , V_84 ) ;
}
#endif
}
static unsigned long T_1 F_35 ( unsigned long V_19 , unsigned long V_26 )
{
unsigned long V_47 = V_86 ;
unsigned long V_87 = 0 ;
if ( V_26 )
V_47 = F_36 ( V_47 , V_26 ) ;
F_25 ( L_58 , V_19 , V_26 ) ;
if ( V_88 == 0 )
F_37 ( L_59 ) ;
if ( V_26 )
V_47 = F_36 ( V_86 , V_26 ) ;
else
V_47 = V_86 ;
for(; ( V_47 + V_19 ) <= V_89 ;
V_47 = F_36 ( V_47 + 0x100000 , V_26 ) ) {
F_25 ( L_60 , V_47 ) ;
V_87 = ( unsigned long ) F_11 ( V_47 , V_19 , 0 ) ;
if ( V_87 != V_10 && V_87 != 0 )
break;
V_87 = 0 ;
if ( V_26 == 0 )
break;
}
if ( V_87 == 0 )
return 0 ;
V_86 = V_87 + V_19 ;
F_25 ( L_61 , V_87 ) ;
F_25 ( L_62 , V_86 ) ;
F_25 ( L_63 , V_89 ) ;
F_25 ( L_64 , V_90 ) ;
F_25 ( L_65 , V_91 ) ;
F_25 ( L_66 , V_88 ) ;
return V_87 ;
}
static unsigned long T_1 F_38 ( unsigned long V_19 , unsigned long V_26 ,
int V_92 )
{
unsigned long V_47 , V_87 = 0 ;
F_25 ( L_67 , V_19 , V_26 ,
V_92 ? L_68 : L_69 ) ;
if ( V_88 == 0 )
F_37 ( L_70 ) ;
if ( V_92 ) {
V_87 = F_39 ( V_90 - V_19 , V_26 ) ;
if ( V_87 <= V_86 )
return 0 ;
if ( V_87 < V_91 ) {
if ( V_89 == V_91 )
V_89 = V_91 = V_87 ;
else
return 0 ;
}
V_90 = V_87 ;
goto V_93;
}
V_47 = F_39 ( V_89 - V_19 , V_26 ) ;
for (; V_47 > V_86 ;
V_47 = F_39 ( V_47 - 0x100000 , V_26 ) ) {
F_25 ( L_60 , V_47 ) ;
V_87 = ( unsigned long ) F_11 ( V_47 , V_19 , 0 ) ;
if ( V_87 != V_10 && V_87 != 0 )
break;
V_87 = 0 ;
}
if ( V_87 == 0 )
return 0 ;
V_89 = V_87 ;
V_93:
F_25 ( L_61 , V_87 ) ;
F_25 ( L_62 , V_86 ) ;
F_25 ( L_63 , V_89 ) ;
F_25 ( L_64 , V_90 ) ;
F_25 ( L_65 , V_91 ) ;
F_25 ( L_66 , V_88 ) ;
return V_87 ;
}
static unsigned long T_1 F_40 ( int V_22 , T_7 * * V_94 )
{
T_7 * V_13 = * V_94 ;
unsigned long V_95 = 0 ;
while ( V_22 > sizeof( unsigned long ) / 4 ) {
V_13 ++ ;
V_22 -- ;
}
V_95 = F_5 ( * V_13 ++ ) ;
#ifdef F_23
if ( V_22 > 1 ) {
V_95 <<= 32 ;
V_95 |= F_5 ( * ( V_13 ++ ) ) ;
}
#endif
* V_94 = V_13 ;
return V_95 ;
}
static void T_1 F_41 ( T_8 V_47 , T_8 V_19 )
{
T_8 V_96 = V_47 + V_19 ;
unsigned long V_97 = V_98 ;
if ( V_19 == 0 )
return;
V_47 = F_39 ( V_47 , V_99 ) ;
V_96 = F_36 ( V_96 , V_99 ) ;
V_19 = V_96 - V_47 ;
if ( V_97 >= ( V_100 - 1 ) )
F_37 ( L_71 ) ;
V_101 [ V_97 ] . V_47 = F_42 ( V_47 ) ;
V_101 [ V_97 ] . V_19 = F_42 ( V_19 ) ;
V_98 = V_97 + 1 ;
}
static void T_1 F_43 ( void )
{
T_3 V_34 ;
char * V_102 , type [ 64 ] ;
unsigned int V_60 ;
T_7 * V_13 , * V_46 ;
T_9 V_16 ;
V_38 V_103 , V_104 ;
V_16 = F_3 ( 2 ) ;
F_13 ( V_15 . V_80 , L_72 , & V_16 , sizeof( V_16 ) ) ;
V_103 = F_5 ( V_16 ) ;
V_16 = F_3 ( 1 ) ;
F_13 ( V_15 . V_80 , L_73 , & V_16 , sizeof( V_104 ) ) ;
V_104 = F_5 ( V_16 ) ;
F_25 ( L_74 , V_103 ) ;
F_25 ( L_75 , V_104 ) ;
F_25 ( L_76 ) ;
V_102 = V_105 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_13 ( V_34 , L_27 , type , sizeof( type ) ) ;
if ( type [ 0 ] == 0 ) {
F_13 ( V_34 , L_77 , type , sizeof( type ) ) ;
}
if ( strcmp ( type , L_78 ) )
continue;
V_60 = F_13 ( V_34 , L_79 , V_106 , sizeof( V_106 ) ) ;
if ( V_60 > sizeof( V_106 ) ) {
F_10 ( L_80 ) ;
V_60 = sizeof( V_106 ) ;
}
V_13 = V_106 ;
V_46 = V_13 + ( V_60 / sizeof( T_7 ) ) ;
#ifdef F_44
memset ( V_102 , 0 , V_107 ) ;
F_2 ( L_81 , 3 , 1 , V_34 , V_102 , V_107 - 1 ) ;
F_25 ( L_82 , V_102 ) ;
#endif
while ( ( V_46 - V_13 ) >= ( V_103 + V_104 ) ) {
unsigned long V_47 , V_19 ;
V_47 = F_40 ( V_103 , & V_13 ) ;
V_19 = F_40 ( V_104 , & V_13 ) ;
if ( V_19 == 0 )
continue;
F_25 ( L_83 , V_47 , V_19 ) ;
if ( V_47 == 0 && ( V_108 & V_109 ) )
V_91 = V_19 ;
if ( ( V_47 + V_19 ) > V_88 )
V_88 = V_47 + V_19 ;
}
}
V_86 = F_45 ( ( unsigned long ) & V_110 + 0x4000 ) ;
V_90 = V_88 ;
if ( V_58 ) {
if ( V_58 <= V_86 ) {
F_10 ( L_84 ,
V_58 ) ;
V_58 = 0 ;
} else if ( V_58 >= V_88 ) {
F_10 ( L_85 ,
V_58 ) ;
V_58 = 0 ;
} else {
V_88 = V_58 ;
V_91 = F_46 ( V_91 , V_58 ) ;
}
}
if ( ! V_91 )
V_91 = V_88 ;
V_91 = F_46 ( 0x30000000ul , V_91 ) ;
V_89 = V_91 ;
V_90 = V_88 ;
if ( V_111 &&
V_111 < V_91 &&
V_112 > V_86 )
V_86 = F_45 ( V_112 ) ;
F_10 ( L_86 ) ;
F_10 ( L_87 , V_58 ) ;
F_10 ( L_62 , V_86 ) ;
F_10 ( L_63 , V_89 ) ;
F_10 ( L_64 , V_90 ) ;
F_10 ( L_65 , V_91 ) ;
F_10 ( L_66 , V_88 ) ;
}
static void T_1 F_47 ( void )
{
T_9 V_16 ;
T_6 V_113 ;
if ( F_13 ( V_15 . V_54 , L_88 , & V_16 , sizeof( V_16 ) ) > 0 ) {
V_113 = F_5 ( V_16 ) ;
F_2 ( L_52 , 1 , 0 , V_113 ) ;
}
}
static void T_1 F_48 ( void )
{
T_3 V_114 ;
T_6 V_115 ;
T_8 V_47 , V_2 ;
T_8 V_19 = 0 , V_26 = 0x10000 ;
T_10 V_116 ;
V_38 V_11 [ 2 ] ;
F_25 ( L_89 ) ;
V_114 = F_2 ( L_90 , 1 , 1 , F_4 ( L_91 ) ) ;
F_25 ( L_92 , V_114 ) ;
if ( ! F_49 ( V_114 ) )
return;
V_116 = 0 ;
F_13 ( V_114 , L_93 , & V_116 , sizeof( V_116 ) ) ;
V_19 = F_50 ( V_116 ) ;
if ( V_19 == 0 )
return;
V_116 = 0 ;
F_13 ( V_114 , L_94 , & V_116 , sizeof( V_116 ) ) ;
V_26 = F_50 ( V_116 ) ;
V_47 = F_38 ( V_19 , V_26 , 0 ) ;
if ( V_47 == 0 ) {
F_10 ( L_95 ) ;
return;
}
V_115 = F_2 ( L_45 , 1 , 1 , F_4 ( L_91 ) ) ;
if ( ! F_51 ( V_115 ) ) {
F_10 ( L_96 , V_115 ) ;
return;
}
F_10 ( L_97 , V_47 ) ;
if ( F_6 ( L_4 , 4 , 3 , V_11 ,
F_4 ( L_98 ) ,
V_115 ,
V_47 >> 32 , V_47 & 0xffffffff ) != 0
|| ( V_11 [ 0 ] == 0 && V_11 [ 1 ] == 0 ) ) {
F_10 ( L_99 ) ;
return;
}
V_2 = ( ( ( T_8 ) V_11 [ 0 ] ) << 32 ) | V_11 [ 1 ] ;
F_10 ( L_53 ) ;
F_41 ( V_47 , V_19 ) ;
F_25 ( L_100 , V_47 ) ;
F_25 ( L_101 , V_26 ) ;
F_25 ( L_102 , V_2 ) ;
F_25 ( L_103 , ( long ) V_19 ) ;
F_17 ( V_114 , L_91 , L_104 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_114 , L_91 , L_105 ,
& V_2 , sizeof( V_2 ) ) ;
#ifdef F_52
V_117 = V_47 ;
V_118 = V_2 ;
#endif
F_25 ( L_106 ) ;
}
static void T_1 F_53 ( void )
{
T_3 V_119 ;
T_6 V_120 ;
V_38 V_47 , V_2 = 0 ;
T_9 V_16 ;
V_38 V_19 = 0 ;
F_25 ( L_107 ) ;
V_119 = F_2 ( L_90 , 1 , 1 , F_4 ( L_108 ) ) ;
F_25 ( L_109 , V_119 ) ;
if ( ! F_49 ( V_119 ) )
return;
V_16 = 0 ;
F_13 ( V_119 , L_110 , & V_16 , sizeof( V_19 ) ) ;
V_19 = F_5 ( V_16 ) ;
if ( V_19 == 0 )
return;
V_47 = F_38 ( V_19 , V_99 , 0 ) ;
if ( V_47 == 0 )
F_37 ( L_111 ) ;
V_120 = F_2 ( L_45 , 1 , 1 , F_4 ( L_108 ) ) ;
if ( ! F_51 ( V_120 ) ) {
F_10 ( L_112 , V_120 ) ;
return;
}
F_10 ( L_113 , V_47 ) ;
if ( F_6 ( L_4 , 3 , 2 , & V_2 ,
F_4 ( L_114 ) ,
V_120 , V_47 ) != 0
|| V_2 == 0 ) {
F_10 ( L_99 ) ;
return;
}
F_10 ( L_53 ) ;
F_41 ( V_47 , V_19 ) ;
V_16 = F_3 ( V_47 ) ;
F_17 ( V_119 , L_108 , L_115 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_3 ( V_2 ) ;
F_17 ( V_119 , L_108 , L_116 ,
& V_16 , sizeof( V_16 ) ) ;
if ( F_13 ( V_119 , L_117 ,
& V_16 , sizeof( V_16 ) ) != V_10 )
V_121 = true ;
F_25 ( L_118 , V_47 ) ;
F_25 ( L_119 , V_2 ) ;
F_25 ( L_120 , ( long ) V_19 ) ;
F_25 ( L_121 ) ;
}
static void T_1 F_54 ( void )
{
T_3 V_122 ;
T_6 V_123 ;
V_38 V_2 = 0 , V_19 = 0 , V_124 = 0 ;
T_8 V_47 ;
T_9 V_16 ;
F_25 ( L_122 ) ;
V_122 = F_2 ( L_90 , 1 , 1 , F_4 ( L_123 ) ) ;
F_25 ( L_124 , V_122 ) ;
if ( ! F_49 ( V_122 ) )
return;
V_123 = F_2 ( L_45 , 1 , 1 , F_4 ( L_123 ) ) ;
if ( ! F_51 ( V_123 ) ) {
F_10 ( L_125 , V_123 ) ;
return;
}
if ( F_13 ( V_122 , L_126 ,
& V_16 , sizeof( V_16 ) ) != V_10 ) {
if ( F_6 ( L_4 , 2 , 2 , & V_124 ,
F_4 ( L_127 ) ,
V_123 ) != 0 || V_124 == 0 ) {
F_10 ( L_128 ) ;
return;
}
if ( F_6 ( L_4 , 2 , 2 , & V_19 ,
F_4 ( L_129 ) ,
V_123 ) != 0 || V_19 == 0 ) {
F_10 ( L_130 ) ;
return;
}
} else {
if ( F_6 ( L_4 , 2 , 2 , & V_19 ,
F_4 ( L_131 ) ,
V_123 ) != 0 || V_19 == 0 ) {
F_10 ( L_132 ) ;
return;
}
}
V_47 = F_38 ( V_19 , V_99 , 0 ) ;
if ( V_47 == 0 )
F_37 ( L_133 ) ;
F_10 ( L_134 , V_47 ) ;
memset ( ( void * ) V_47 , 0 , V_19 ) ;
if ( F_6 ( L_4 , 4 , 2 , & V_2 ,
F_4 ( L_135 ) ,
V_123 , V_19 , V_47 ) != 0 || V_2 == 0 ) {
F_10 ( L_136 ) ;
return;
}
F_10 ( L_53 ) ;
F_41 ( V_47 , V_19 ) ;
F_17 ( V_122 , L_123 , L_137 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_122 , L_123 , L_138 ,
& V_19 , sizeof( V_19 ) ) ;
F_25 ( L_139 , V_47 ) ;
F_25 ( L_140 , ( long ) V_19 ) ;
F_25 ( L_141 ) ;
}
static void T_1 F_55 ( void )
{
T_3 V_34 ;
T_6 V_125 ;
char V_126 [ 64 ] , type [ 64 ] , V_127 [ 64 ] ;
char * V_102 = V_105 ;
T_8 V_47 , V_26 ;
V_38 V_128 , V_129 ;
T_8 V_130 , * V_131 ;
T_8 V_132 , V_133 ;
T_8 V_6 ;
if ( V_56 )
return;
F_25 ( L_142 ) ;
V_132 = V_90 ;
V_133 = V_132 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
V_126 [ 0 ] = 0 ;
type [ 0 ] = 0 ;
V_127 [ 0 ] = 0 ;
F_13 ( V_34 , L_143 ,
V_126 , sizeof( V_126 ) ) ;
F_13 ( V_34 , L_27 , type , sizeof( type ) ) ;
F_13 ( V_34 , L_144 , V_127 , sizeof( V_127 ) ) ;
if ( ( type [ 0 ] == 0 ) || ( strstr ( type , L_145 ) == NULL ) )
continue;
if ( V_126 [ 0 ] != 0 ) {
if ( ( strstr ( V_126 , L_146 ) == NULL ) &&
( strstr ( V_126 , L_147 ) == NULL ) &&
( strstr ( V_126 , L_148 ) == NULL ) )
continue;
} else if ( V_127 [ 0 ] != 0 ) {
if ( ( strstr ( V_127 , L_149 ) == NULL ) &&
( strstr ( V_127 , L_150 ) == NULL ) &&
( strstr ( V_127 , L_151 ) == NULL ) )
continue;
}
if ( F_13 ( V_34 , L_152 , & V_128 ,
sizeof( V_128 ) ) == V_10 )
V_128 = 0 ;
if ( F_13 ( V_34 , L_153 , & V_129 ,
sizeof( V_129 ) ) == V_10 )
V_129 = 4UL << 20 ;
if ( F_56 ( V_134 ) || F_56 ( V_135 ) )
V_129 = 8UL << 20 ;
else
V_129 = 4UL << 20 ;
V_26 = F_57 ( V_128 , V_129 ) ;
V_47 = F_38 ( V_129 , V_26 , 1 ) ;
if ( V_47 == 0 )
F_37 ( L_154 ) ;
if ( V_47 < V_133 )
V_133 = V_47 ;
memset ( V_102 , 0 , V_107 ) ;
if ( F_2 ( L_81 , 3 , 1 , V_34 ,
V_102 , V_107 - 1 ) == V_10 ) {
F_10 ( L_155 ) ;
}
F_17 ( V_34 , V_102 , L_156 , & V_47 , sizeof( V_47 ) ) ;
F_17 ( V_34 , V_102 , L_157 , & V_129 , sizeof( V_129 ) ) ;
F_25 ( L_158 , V_102 ) ;
F_25 ( L_159 , V_34 ) ;
F_25 ( L_160 , V_47 ) ;
F_25 ( L_161 , V_129 ) ;
V_131 = ( T_8 * ) V_47 ;
for ( V_6 = 0 ; V_6 < ( V_129 >> 3 ) ; V_131 ++ , V_6 ++ ) {
V_130 = ( V_6 << V_136 ) ;
V_130 |= 0x3 ;
* V_131 = V_130 ;
}
F_10 ( L_162 , V_102 ) ;
V_125 = F_2 ( L_45 , 1 , 1 , V_102 ) ;
if ( V_125 == 0 )
F_10 ( L_163 ) ;
else
F_10 ( L_164 ) ;
F_2 ( L_4 , 6 , 0 , F_4 ( L_165 ) ,
V_125 , - 1 , V_129 ,
( V_38 ) V_47 , ( V_38 ) ( V_47 >> 32 ) ) ;
F_2 ( L_52 , 1 , 0 , V_125 ) ;
}
F_41 ( V_133 , V_132 - V_133 ) ;
V_137 = V_133 ;
V_138 = V_132 ;
F_25 ( L_166 ) ;
}
static void T_1 F_58 ( void )
{
unsigned long V_6 ;
T_3 V_34 ;
char type [ 64 ] ;
unsigned long * V_139
= ( void * ) F_59 ( V_140 ) ;
unsigned long * V_141
= ( void * ) F_59 ( V_142 ) ;
unsigned long V_143 = F_59 ( V_144 ) ;
if ( ( V_108 == V_145 ||
V_108 == V_146 ) &&
V_121 ) {
F_10 ( L_167 ) ;
return;
}
F_25 ( L_168 ) ;
F_25 ( L_169 , ( unsigned long ) V_139 ) ;
F_25 ( L_170 , * V_139 ) ;
F_25 ( L_171 ,
( unsigned long ) V_141 ) ;
F_25 ( L_172 , * V_141 ) ;
F_25 ( L_173 , V_143 ) ;
* V_139 = 0 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
unsigned int V_147 ;
T_9 V_148 ;
type [ 0 ] = 0 ;
F_13 ( V_34 , L_27 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_28 ) != 0 )
continue;
if ( F_13 ( V_34 , L_174 , type , sizeof( type ) ) > 0 )
if ( strcmp ( type , L_175 ) != 0 )
continue;
V_148 = F_3 ( - 1 ) ;
F_13 ( V_34 , L_79 , & V_148 , sizeof( V_148 ) ) ;
V_147 = F_5 ( V_148 ) ;
F_25 ( L_176 , V_147 ) ;
* V_141 = ( unsigned long ) - 1 ;
if ( V_147 != V_15 . V_149 ) {
F_10 ( L_177 , V_147 ) ;
F_2 ( L_178 , 3 , 0 , V_34 ,
V_143 , V_147 ) ;
for ( V_6 = 0 ; ( V_6 < 100000000 ) &&
( * V_141 == ( ( unsigned long ) - 1 ) ) ; V_6 ++ )
F_60 () ;
if ( * V_141 == V_147 )
F_10 ( L_179 ) ;
else
F_10 ( L_180 , * V_141 ) ;
}
#ifdef F_61
else
F_10 ( L_181 , V_147 ) ;
#endif
}
F_25 ( L_182 ) ;
}
static void T_1 F_62 ( unsigned long V_150 )
{
V_9 = V_150 ;
V_15 . V_54 = F_2 ( L_90 , 1 , 1 , F_4 ( L_183 ) ) ;
if ( ! F_49 ( V_15 . V_54 ) )
F_37 ( L_184 ) ;
V_15 . V_80 = F_2 ( L_90 , 1 , 1 , F_4 ( L_46 ) ) ;
if ( ! F_49 ( V_15 . V_80 ) )
F_37 ( L_185 ) ;
V_15 . V_32 = 0 ;
}
static void T_1 F_63 ( void )
{
T_3 V_151 ;
char V_152 [ 64 ] ;
V_151 = F_2 ( L_90 , 1 , 1 , F_4 ( L_186 ) ) ;
if ( ! F_49 ( V_151 ) )
return;
if ( F_13 ( V_151 , L_144 , V_152 , sizeof( V_152 ) ) <= 0 )
return;
V_152 [ sizeof( V_152 ) - 1 ] = 0 ;
if ( strcmp ( V_152 , L_187 ) == 0 )
V_153 = V_28 ;
else if ( strncmp ( V_152 , L_188 , 12 ) == 0 ) {
V_153 = V_28 | V_44 ;
F_2 ( L_17 , 1 , 1 , L_189 ) ;
} else
return;
V_15 . V_31 = F_2 ( L_45 , 1 , 1 , F_4 ( L_190 ) ) ;
F_13 ( V_15 . V_54 , L_191 , & V_15 . V_32 ,
sizeof( V_15 . V_32 ) ) ;
V_15 . V_32 = F_5 ( V_15 . V_32 ) ;
if ( ! F_51 ( V_15 . V_31 ) || ! F_51 ( V_15 . V_32 ) )
V_153 &= ~ V_28 ;
}
static void T_1 F_64 ( void )
{
char * V_102 = V_154 ;
char type [ 16 ] ;
T_3 V_155 ;
T_9 V_16 ;
if ( F_13 ( V_15 . V_54 , L_192 , & V_16 , sizeof( V_16 ) ) <= 0 )
F_37 ( L_193 ) ;
V_15 . stdout = F_5 ( V_16 ) ;
memset ( V_102 , 0 , 256 ) ;
F_2 ( L_194 , 3 , 1 , V_15 . stdout , V_102 , 255 ) ;
F_10 ( L_195 , V_154 ) ;
F_17 ( V_15 . V_54 , L_183 , L_196 ,
V_102 , strlen ( V_102 ) + 1 ) ;
V_155 = F_2 ( L_197 , 1 , 1 , V_15 . stdout ) ;
if ( V_155 != V_10 ) {
V_16 = F_3 ( V_155 ) ;
F_17 ( V_15 . V_54 , L_183 , L_198 ,
& V_16 , sizeof( V_16 ) ) ;
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_155 , L_27 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_199 ) == 0 )
F_17 ( V_155 , V_102 , L_200 , NULL , 0 ) ;
}
}
static int T_1 F_65 ( void )
{
char V_156 [ 256 ] ;
int V_157 , V_6 = 0 ;
#ifdef F_23
T_3 V_158 ;
int V_40 ;
#endif
V_157 = F_13 ( V_15 . V_80 , L_143 ,
V_156 , sizeof( V_156 ) - 1 ) ;
if ( V_157 > 0 ) {
V_156 [ V_157 ] = 0 ;
while ( V_6 < V_157 ) {
char * V_13 = & V_156 [ V_6 ] ;
int V_159 = strlen ( V_13 ) ;
if ( V_159 == 0 )
break;
if ( strstr ( V_13 , L_201 ) ||
strstr ( V_13 , L_202 ) )
return V_160 ;
#ifdef F_23
if ( strstr ( V_13 , L_203 ) ||
strstr ( V_13 , L_204 ) )
return V_161 ;
#endif
V_6 += V_159 + 1 ;
}
}
#ifdef F_23
if ( F_49 ( F_2 ( L_90 , 1 , 1 , F_4 ( L_91 ) ) ) )
return V_162 ;
V_157 = F_13 ( V_15 . V_80 , L_27 ,
V_156 , sizeof( V_156 ) - 1 ) ;
if ( V_157 <= 0 )
return V_161 ;
if ( strcmp ( V_156 , L_205 ) )
return V_161 ;
V_158 = F_2 ( L_90 , 1 , 1 , F_4 ( L_108 ) ) ;
if ( ! F_49 ( V_158 ) )
return V_161 ;
V_40 = F_14 ( V_158 , L_206 ) ;
if ( V_40 != V_10 ) {
F_25 ( L_207 ) ;
return V_146 ;
}
return V_145 ;
#else
return V_161 ;
#endif
}
static int T_1 F_66 ( T_6 V_163 , int V_6 , int V_95 , int V_164 , int V_165 )
{
return F_2 ( L_4 , 6 , 1 , F_4 ( L_208 ) , V_163 , V_6 , V_165 , V_164 , V_95 ) ;
}
static void T_1 F_67 ( void )
{
char type [ 16 ] , * V_102 ;
T_3 V_34 ;
T_6 V_163 ;
int V_6 ;
static unsigned char V_166 [] = {
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
const unsigned char * V_167 ;
F_25 ( L_209 ) ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_34 , L_27 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_199 ) != 0 )
continue;
V_102 = V_105 ;
memset ( V_102 , 0 , V_107 ) ;
if ( F_2 ( L_81 , 3 , 1 , V_34 , V_102 ,
V_107 - 10 ) == V_10 )
continue;
F_10 ( L_210 , V_102 ) ;
V_163 = F_2 ( L_45 , 1 , 1 , V_102 ) ;
if ( V_163 == 0 ) {
F_10 ( L_211 ) ;
continue;
}
F_10 ( L_179 ) ;
F_17 ( V_34 , V_102 , L_212 , NULL , 0 ) ;
V_167 = V_166 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ , V_167 += 3 )
if ( F_66 ( V_163 , V_6 , V_167 [ 0 ] , V_167 [ 1 ] ,
V_167 [ 2 ] ) != 0 )
break;
#ifdef F_68
V_167 = F_69 ( V_168 . V_167 ) ;
for ( V_6 = 0 ; V_6 < V_168 . V_169 ; V_6 ++ , V_167 += 3 )
if ( F_66 ( V_163 , V_6 + 32 , V_167 [ 0 ] , V_167 [ 1 ] ,
V_167 [ 2 ] ) != 0 )
break;
#endif
#ifdef F_70
if ( F_13 ( V_34 , L_200 , NULL , 0 ) !=
V_10 ) {
V_38 V_170 , V_171 , V_172 , V_87 ;
F_10 ( L_213 ) ;
F_13 ( V_34 , L_214 , & V_170 , 4 ) ;
F_13 ( V_34 , L_215 , & V_171 , 4 ) ;
F_13 ( V_34 , L_216 , & V_172 , 4 ) ;
F_13 ( V_34 , L_217 , & V_87 , 4 ) ;
F_10 ( L_218 ,
V_170 , V_171 , V_172 , V_87 ) ;
F_71 ( V_170 , V_171 , 8 , V_172 , V_87 ) ;
}
#endif
}
}
static void T_1 * F_72 ( unsigned long * V_173 , unsigned long * V_174 ,
unsigned long V_175 , unsigned long V_26 )
{
void * V_29 ;
* V_173 = F_73 ( * V_173 , V_26 ) ;
while ( ( * V_173 + V_175 ) > * V_174 ) {
unsigned long V_176 , V_177 ;
F_25 ( L_219 ,
V_86 ) ;
V_176 = V_89 - V_86 ;
if ( V_176 > V_178 )
V_176 = V_178 ;
if ( V_176 < V_99 )
F_37 ( L_220
L_221 ) ;
V_177 = F_35 ( V_176 , 0 ) ;
if ( V_177 == 0 )
F_37 ( L_220
L_222 ) ;
* V_174 = V_177 + V_176 ;
}
V_29 = ( void * ) * V_173 ;
* V_173 += V_175 ;
return V_29 ;
}
static unsigned long T_1 F_74 ( char * V_39 )
{
char * V_22 , * V_179 ;
V_22 = V_179 = ( char * ) V_180 ;
V_22 += 4 ;
while ( V_22 < ( char * ) V_181 ) {
if ( strcmp ( V_22 , V_39 ) == 0 )
return V_22 - V_179 ;
V_22 += strlen ( V_22 ) + 1 ;
}
return 0 ;
}
static void T_1 F_75 ( T_3 V_34 ,
unsigned long * V_173 ,
unsigned long * V_174 )
{
char * V_182 , * V_183 , * V_184 ;
unsigned long V_185 ;
T_3 V_186 ;
V_184 = ( char * ) V_180 ;
V_182 = L_223 ;
for (; ; ) {
V_183 = F_72 ( V_173 , V_174 , V_187 , 1 ) ;
if ( F_2 ( L_224 , 3 , 1 , V_34 , V_182 , V_183 ) != 1 ) {
* V_173 = ( unsigned long ) V_183 ;
break;
}
if ( strcmp ( V_183 , L_77 ) == 0 ) {
* V_173 = ( unsigned long ) V_183 ;
V_182 = L_77 ;
continue;
}
V_185 = F_74 ( V_183 ) ;
if ( V_185 != 0 ) {
* V_173 = ( unsigned long ) V_183 ;
V_183 = V_184 + V_185 ;
} else {
* V_173 = ( unsigned long ) V_183 + strlen ( V_183 ) + 1 ;
V_181 = * V_173 ;
}
V_182 = V_183 ;
}
V_186 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_186 != 0 ) {
F_75 ( V_186 , V_173 , V_174 ) ;
V_186 = F_2 ( L_9 , 1 , 1 , V_186 ) ;
}
}
static void T_1 F_76 ( T_3 V_34 , unsigned long * V_173 ,
unsigned long * V_174 )
{
T_3 V_186 ;
char * V_183 , * V_182 , * V_184 , * V_13 , * V_188 , * V_189 , * V_102 ;
unsigned long V_185 ;
unsigned char * V_190 ;
static char V_35 [ V_187 ] ;
int V_52 , V_176 , V_191 = 0 ;
F_77 ( V_192 , V_173 , V_174 ) ;
V_183 = ( char * ) * V_173 ;
V_176 = * V_174 - * V_173 ;
if ( V_176 > 255 )
V_176 = 255 ;
V_52 = F_2 ( L_81 , 3 , 1 , V_34 , V_183 , V_176 ) ;
if ( V_52 >= 0 ) {
if ( V_52 >= V_176 ) {
if ( V_52 >= * V_174 - * V_173 )
V_183 = F_72 ( V_173 , V_174 , V_52 + 1 , 1 ) ;
F_2 ( L_81 , 3 , 1 , V_34 , V_183 , V_52 ) ;
}
V_183 [ V_52 ] = '\0' ;
for ( V_189 = V_13 = V_183 , V_188 = V_183 + V_52 ; V_13 < V_188 ; V_13 ++ ) {
if ( * V_13 == '/' )
V_189 = V_183 ;
else if ( * V_13 != 0 )
* V_189 ++ = * V_13 ;
}
* V_189 = 0 ;
* V_173 = F_73 ( ( unsigned long ) V_189 + 1 , 4 ) ;
}
V_102 = V_105 ;
memset ( V_102 , 0 , V_107 ) ;
F_2 ( L_81 , 3 , 1 , V_34 , V_102 , V_107 - 1 ) ;
V_182 = L_223 ;
V_184 = ( char * ) V_180 ;
for (; ; ) {
if ( F_2 ( L_224 , 3 , 1 , V_34 , V_182 ,
V_35 ) != 1 )
break;
if ( strcmp ( V_35 , L_77 ) == 0 ) {
V_182 = L_77 ;
continue;
}
V_185 = F_74 ( V_35 ) ;
if ( V_185 == 0 ) {
F_10 ( L_225
L_226 , V_35 , V_102 ) ;
break;
}
V_182 = V_184 + V_185 ;
V_52 = F_2 ( L_12 , 2 , 1 , V_34 , V_35 ) ;
if ( V_52 == V_10 )
continue;
F_77 ( V_193 , V_173 , V_174 ) ;
F_77 ( V_52 , V_173 , V_174 ) ;
F_77 ( V_185 , V_173 , V_174 ) ;
V_190 = F_72 ( V_173 , V_174 , V_52 , 4 ) ;
F_2 ( L_11 , 4 , 1 , V_34 , V_35 , V_190 , V_52 ) ;
* V_173 = F_73 ( * V_173 , 4 ) ;
if ( ! strcmp ( V_35 , L_227 ) )
V_191 = 1 ;
}
if ( ! V_191 ) {
V_185 = F_74 ( L_228 ) ;
if ( V_185 == 0 )
F_10 ( L_225
L_229 , V_102 ) ;
else {
F_77 ( V_193 , V_173 , V_174 ) ;
F_77 ( 4 , V_173 , V_174 ) ;
F_77 ( V_185 , V_173 , V_174 ) ;
V_190 = F_72 ( V_173 , V_174 , 4 , 4 ) ;
* ( T_9 * ) V_190 = F_3 ( V_34 ) ;
}
}
V_186 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_186 != 0 ) {
F_76 ( V_186 , V_173 , V_174 ) ;
V_186 = F_2 ( L_9 , 1 , 1 , V_186 ) ;
}
F_77 ( V_194 , V_173 , V_174 ) ;
}
static void T_1 F_78 ( void )
{
T_3 V_80 ;
unsigned long V_173 , V_174 , V_176 ;
struct V_195 * V_196 ;
char * V_183 ;
T_8 * V_197 ;
V_176 = V_89 - V_86 - 0x4000 ;
if ( V_176 > V_178 )
V_176 = V_178 ;
F_25 ( L_230 , V_86 ) ;
V_173 = ( unsigned long ) F_35 ( V_176 , V_99 ) ;
if ( V_173 == 0 )
F_37 ( L_231 ) ;
V_174 = V_173 + V_176 ;
V_80 = F_2 ( L_9 , 1 , 1 , ( T_3 ) 0 ) ;
if ( V_80 == ( T_3 ) 0 )
F_37 ( L_232 ) ;
V_173 = F_73 ( V_173 , 4 ) ;
V_196 = F_72 ( & V_173 , & V_174 ,
sizeof( struct V_195 ) , 4 ) ;
V_198 = ( unsigned long ) V_196 ;
V_197 = F_72 ( & V_173 , & V_174 , sizeof( V_101 ) , 8 ) ;
V_173 = F_45 ( V_173 ) ;
V_180 = V_173 ;
V_173 += 4 ;
V_183 = F_72 ( & V_173 , & V_174 , 16 , 1 ) ;
strcpy ( V_183 , L_228 ) ;
V_173 = ( unsigned long ) V_183 + strlen ( V_183 ) + 1 ;
F_10 ( L_233 ) ;
F_75 ( V_80 , & V_173 , & V_174 ) ;
V_181 = V_173 ;
V_173 = F_45 ( V_173 ) ;
V_199 = V_173 ;
F_10 ( L_234 ) ;
F_76 ( V_80 , & V_173 , & V_174 ) ;
F_77 ( V_200 , & V_173 , & V_174 ) ;
V_201 = F_45 ( V_173 ) ;
V_196 -> V_202 = F_3 ( V_15 . V_149 ) ;
V_196 -> V_203 = F_3 ( V_204 ) ;
V_196 -> V_205 = F_3 ( V_201 - V_198 ) ;
V_196 -> V_206 = F_3 ( V_199 - V_198 ) ;
V_196 -> V_207 = F_3 ( V_180 - V_198 ) ;
V_196 -> V_208 = F_3 ( V_181 - V_180 ) ;
V_196 -> V_209 = F_3 ( ( ( unsigned long ) V_197 ) - V_198 ) ;
V_196 -> V_152 = F_3 ( V_210 ) ;
V_196 -> V_211 = F_3 ( 0x10 ) ;
memcpy ( V_197 , V_101 , sizeof( V_101 ) ) ;
#ifdef F_44
{
int V_6 ;
F_10 ( L_235 ) ;
for ( V_6 = 0 ; V_6 < V_98 ; V_6 ++ )
F_10 ( L_236 ,
F_50 ( V_101 [ V_6 ] . V_47 ) ,
F_50 ( V_101 [ V_6 ] . V_19 ) ) ;
}
#endif
V_98 = V_100 ;
F_10 ( L_237 ,
V_180 , V_181 ) ;
F_10 ( L_238 ,
V_199 , V_201 ) ;
}
static void T_1 F_79 ( void )
{
T_3 V_212 ;
V_38 V_213 = 0x01002000 ;
V_38 V_214 [ 6 ] ;
char * V_215 ;
V_215 = L_239 ;
V_212 = F_2 ( L_90 , 1 , 1 , F_4 ( V_215 ) ) ;
if ( ! F_49 ( V_212 ) ) {
V_215 = L_240 ;
V_212 = F_2 ( L_90 , 1 , 1 , F_4 ( V_215 ) ) ;
V_213 = 0x01003000 ;
}
if ( ! F_49 ( V_212 ) )
return;
if ( F_14 ( V_212 , L_241 ) != 12 )
return;
if ( F_13 ( V_212 , L_241 , V_214 , sizeof( V_214 ) )
== V_10 )
return;
if ( V_214 [ 0 ] != 0x1 ||
V_214 [ 1 ] != 0xf4000000 ||
V_214 [ 2 ] != 0x00010000 )
return;
F_10 ( L_242 ) ;
V_214 [ 0 ] = 0x1 ;
V_214 [ 1 ] = 0x0 ;
V_214 [ 2 ] = V_213 ;
V_214 [ 3 ] = 0x0 ;
V_214 [ 4 ] = 0x0 ;
V_214 [ 5 ] = 0x00010000 ;
F_17 ( V_212 , V_215 , L_241 ,
V_214 , sizeof( V_214 ) ) ;
}
static void T_1 F_80 ( void )
{
T_3 V_216 ;
V_38 V_217 [ 4 ] ;
char * V_215 = L_243 ;
V_38 V_218 , V_219 ;
V_216 = F_2 ( L_90 , 1 , 1 , F_4 ( V_215 ) ) ;
if ( ! F_49 ( V_216 ) )
return;
if ( F_14 ( V_216 , L_79 ) != 8 )
return;
F_13 ( V_15 . V_80 , L_72 , & V_218 , sizeof( V_218 ) ) ;
F_13 ( V_15 . V_80 , L_73 , & V_219 , sizeof( V_219 ) ) ;
if ( ( V_218 != 2 ) || ( V_219 != 2 ) )
return;
if ( F_13 ( V_216 , L_79 , V_217 , sizeof( V_217 ) ) == V_10 )
return;
if ( V_217 [ 0 ] != V_220 || V_217 [ 1 ] != V_221 )
return;
F_10 ( L_244 ) ;
V_217 [ 0 ] = 0x0 ;
V_217 [ 1 ] = V_220 ;
V_217 [ 2 ] = 0x0 ;
V_217 [ 3 ] = V_221 ;
F_17 ( V_216 , V_215 , L_79 , V_217 , sizeof( V_217 ) ) ;
}
static void T_1 F_81 ( void )
{
T_3 V_222 ;
V_38 V_223 [ 6 ] ;
V_38 V_213 = 0x01006000 ;
char * V_215 ;
int V_224 ;
V_215 = L_245 ;
V_222 = F_2 ( L_90 , 1 , 1 , F_4 ( V_215 ) ) ;
if ( ! F_49 ( V_222 ) ) {
V_215 = L_246 ;
V_222 = F_2 ( L_90 , 1 , 1 , F_4 ( V_215 ) ) ;
V_213 = 0x01003000 ;
}
if ( F_49 ( V_222 ) ) {
V_224 = F_14 ( V_222 , L_241 ) ;
if ( V_224 == 0 || V_224 == V_10 ) {
F_10 ( L_247 ) ;
V_223 [ 0 ] = 0x1 ;
V_223 [ 1 ] = 0x0 ;
V_223 [ 2 ] = V_213 ;
V_223 [ 3 ] = 0x0 ;
V_223 [ 4 ] = 0x0 ;
V_223 [ 5 ] = 0x00010000 ;
F_17 ( V_222 , V_215 , L_241 , V_223 , sizeof( V_223 ) ) ;
}
}
V_215 = L_248 ;
V_222 = F_2 ( L_90 , 1 , 1 , F_4 ( V_215 ) ) ;
if ( F_49 ( V_222 ) ) {
F_10 ( L_249 ) ;
V_223 [ 0 ] = 14 ;
V_223 [ 1 ] = 0x0 ;
F_17 ( V_222 , V_215 , L_250 , V_223 , 2 * sizeof( V_38 ) ) ;
F_10 ( L_251 ) ;
V_224 = F_13 ( V_222 , L_252 , V_223 , sizeof( V_38 ) ) ;
if ( V_224 == sizeof( V_38 ) ) {
V_223 [ 0 ] &= ~ 0x5 ;
F_17 ( V_222 , V_215 , L_252 , V_223 , sizeof( V_38 ) ) ;
}
}
}
static void T_1 F_82 ( void )
{
T_3 V_225 , V_226 , V_227 ;
V_38 V_228 ;
V_38 V_229 [ 2 ] ;
V_38 V_230 ;
V_225 = F_2 ( L_90 , 1 , 1 , F_4 ( L_253 ) ) ;
if ( ! F_49 ( V_225 ) )
return;
V_226 = F_2 ( L_90 , 1 , 1 , F_4 ( L_254 ) ) ;
if ( ! F_49 ( V_226 ) )
return;
V_227 = F_2 ( L_90 , 1 , 1 , F_4 ( L_255 ) ) ;
if ( ! F_49 ( V_227 ) )
return;
if ( F_13 ( V_225 , L_256 , & V_228 , sizeof( V_228 ) )
== V_10 )
return;
if ( V_228 < 0x35 || V_228 > 0x39 )
return;
if ( F_14 ( V_226 , L_250 ) > 0 )
return;
F_10 ( L_257 ) ;
V_229 [ 0 ] = 0 ;
V_229 [ 1 ] = 1 ;
F_17 ( V_226 , L_254 , L_250 ,
& V_229 , sizeof( V_229 ) ) ;
V_230 = ( V_38 ) V_227 ;
F_17 ( V_226 , L_254 , L_258 ,
& V_230 , sizeof( V_230 ) ) ;
}
static void T_1 F_83 ( void )
{
V_38 V_34 ;
char V_223 [ 64 ] ;
int V_231 ;
V_34 = F_2 ( L_90 , 1 , 1 , F_4 ( L_259 ) ) ;
if ( ! F_49 ( V_34 ) )
return;
V_231 = F_13 ( V_34 , L_260 , V_223 , sizeof( V_223 ) ) ;
if ( ! V_231 )
return;
V_34 = F_2 ( L_90 , 1 , 1 , F_4 ( L_261 ) ) ;
if ( ! F_49 ( V_34 ) ) {
F_10 ( L_262 ) ;
F_2 ( L_17 , 1 , 1 ,
L_263
L_264
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
L_275 ) ;
} ;
V_34 = F_2 ( L_90 , 1 , 1 ,
F_4 ( L_276 ) ) ;
if ( ! F_49 ( V_34 ) ) {
F_10 ( L_277 ) ;
F_2 ( L_17 , 1 , 1 ,
L_278
L_264
L_279
L_280
L_281
L_282
L_275
L_283
L_284
L_285
L_286 ) ;
}
}
static void T_1 F_84 ( void )
{
int V_232 [ 3 ] = { 2 , 2 , 0 } ;
int V_233 [ 3 * 16 ] = { 3 , 0 , 0 , 3 , 1 , 0 , 3 , 2 , 0 , 3 , 3 , 0 ,
3 , 4 , 0 , 3 , 5 , 0 , 3 , 6 , 0 , 3 , 7 , 0 ,
3 , 8 , 0 , 3 , 9 , 0 , 3 , 10 , 0 , 3 , 11 , 0 ,
3 , 12 , 0 , 3 , 13 , 0 , 3 , 14 , 0 , 3 , 15 , 0 } ;
V_38 V_34 ;
char V_223 [ 64 ] ;
int V_231 , V_157 ;
V_34 = F_2 ( L_90 , 1 , 1 , F_4 ( L_46 ) ) ;
if ( ! F_49 ( V_34 ) )
return;
V_231 = F_13 ( V_34 , L_144 , V_223 , sizeof( V_223 ) ) ;
if ( V_231 == V_10 )
return;
if ( strcmp ( V_223 , L_287 ) )
return;
F_10 ( L_288 ) ;
V_34 = F_2 ( L_90 , 1 , 1 , F_4 ( L_46 ) ) ;
V_231 = F_13 ( V_34 , L_27 , V_223 , sizeof( V_223 ) ) ;
if ( V_231 != V_10 && ( strcmp ( V_223 , L_205 ) == 0 ) )
F_17 ( V_34 , L_46 , L_27 , L_289 , sizeof( L_289 ) ) ;
V_231 = F_13 ( V_34 , L_290 , V_223 , sizeof( V_223 ) ) ;
if ( V_231 != V_10 && ( strstr ( V_223 , L_291 ) ) )
F_17 ( V_34 , L_46 , L_290 ,
L_292 ,
sizeof( L_292 ) ) ;
V_34 = F_2 ( L_90 , 1 , 1 , F_4 ( L_293 ) ) ;
if ( F_49 ( V_34 ) ) {
V_157 = F_14 ( V_34 , L_250 ) ;
if ( V_157 == 12 ) {
F_10 ( L_294 ) ;
F_17 ( V_34 , L_295 , L_250 ,
V_233 , sizeof( V_233 ) ) ;
}
}
V_34 = F_2 ( L_90 , 1 , 1 , F_4 ( L_296 ) ) ;
if ( F_49 ( V_34 ) ) {
V_231 = F_13 ( V_34 , L_250 , V_223 , sizeof( V_223 ) ) ;
if ( V_231 == V_10 ) {
F_10 ( L_297 ) ;
F_17 ( V_34 , L_296 , L_250 ,
V_232 , sizeof( V_232 ) ) ;
}
}
F_83 () ;
}
static void T_1 F_85 ( void )
{
V_38 V_229 [ 2 ] , V_230 , V_234 , V_16 = 0 ;
char * V_215 , * V_235 ;
T_3 V_236 , V_34 ;
V_215 = L_298 ;
V_236 = F_2 ( L_90 , 1 , 1 , F_4 ( V_215 ) ) ;
if ( ! F_49 ( V_236 ) )
return;
if ( F_14 ( V_236 , L_299 ) != V_10 )
return;
F_10 ( L_300 ) ;
F_17 ( V_236 , V_215 , L_299 , & V_16 , 0 ) ;
V_235 = L_301 ;
V_34 = F_2 ( L_90 , 1 , 1 , F_4 ( V_235 ) ) ;
V_230 = F_4 ( V_236 ) ;
for( ; F_12 ( & V_34 ) ; ) {
if ( ! F_49 ( V_34 ) )
continue;
V_234 = F_14 ( V_34 , L_250 ) ;
if ( V_234 == 0 || V_234 == V_10 )
continue;
F_13 ( V_34 , L_250 , & V_229 , sizeof( V_229 ) ) ;
if ( ( V_229 [ 0 ] < 212 ) || ( V_229 [ 0 ] > 222 ) )
continue;
if ( ( V_229 [ 0 ] >= 212 ) && ( V_229 [ 0 ] <= 215 ) )
V_229 [ 0 ] -= 203 ;
if ( ( V_229 [ 0 ] >= 216 ) && ( V_229 [ 0 ] <= 220 ) )
V_229 [ 0 ] -= 213 ;
if ( V_229 [ 0 ] == 221 )
V_229 [ 0 ] = 14 ;
if ( V_229 [ 0 ] == 222 )
V_229 [ 0 ] = 8 ;
F_17 ( V_34 , V_235 , L_250 , V_229 ,
sizeof( V_229 ) ) ;
F_17 ( V_34 , V_235 , L_258 , & V_230 ,
sizeof( V_230 ) ) ;
}
V_215 = L_302 ;
V_236 = F_2 ( L_90 , 1 , 1 , F_4 ( V_215 ) ) ;
if ( ! F_49 ( V_236 ) )
return;
F_10 ( L_303 ) ;
F_17 ( V_236 , V_215 , L_27 , L_304 , sizeof( L_304 ) ) ;
}
static inline void F_85 ( void ) { }
static void T_1 F_86 ( void )
{
F_79 () ;
F_80 () ;
F_81 () ;
F_82 () ;
F_84 () ;
F_85 () ;
}
static void T_1 F_87 ( void )
{
T_9 V_234 ;
T_6 V_237 ;
T_3 V_238 ;
V_234 = 0 ;
if ( F_13 ( V_15 . V_54 , L_28 , & V_234 , sizeof( V_234 ) ) <= 0 )
return;
V_237 = F_5 ( V_234 ) ;
V_238 = F_2 ( L_197 , 1 , 1 , V_237 ) ;
if ( ! F_49 ( V_238 ) )
return;
F_13 ( V_238 , L_79 , & V_234 , sizeof( V_234 ) ) ;
V_15 . V_149 = F_5 ( V_234 ) ;
F_25 ( L_305 , V_15 . V_149 ) ;
}
static void T_1 F_88 ( unsigned long V_239 , unsigned long V_240 )
{
#ifdef F_89
if ( V_239 && V_240 && V_240 != 0xdeadbeef ) {
T_10 V_16 ;
V_111 = F_90 ( V_239 ) ? F_91 ( V_239 ) : V_239 ;
V_112 = V_111 + V_240 ;
V_16 = F_42 ( V_111 ) ;
F_17 ( V_15 . V_54 , L_183 , L_306 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_42 ( V_112 ) ;
F_17 ( V_15 . V_54 , L_183 , L_307 ,
& V_16 , sizeof( V_16 ) ) ;
F_41 ( V_111 ,
V_112 - V_111 ) ;
F_25 ( L_308 , V_111 ) ;
F_25 ( L_309 , V_112 ) ;
}
#endif
}
static void F_92 ( void )
{
}
static void F_93 ( void )
{
}
static void F_94 ( unsigned long V_241 , unsigned long V_242 )
{
unsigned long V_6 ;
unsigned long * V_243 ;
asm volatile("addi %0,2,-0x8000" : "=b" (toc_entry));
for ( V_6 = 0 ; V_6 < V_242 ; V_6 ++ ) {
* V_243 = * V_243 + V_241 ;
V_243 ++ ;
}
}
static void F_92 ( void )
{
unsigned long V_241 = F_95 () ;
unsigned long V_242 =
( V_244 - V_245 ) / sizeof( long ) ;
F_94 ( V_241 , V_242 ) ;
F_60 () ;
}
static void F_93 ( void )
{
unsigned long V_241 = F_95 () ;
unsigned long V_242 =
( V_244 - V_245 ) / sizeof( long ) ;
F_60 () ;
F_94 ( - V_241 , V_242 ) ;
}
unsigned long T_1 F_96 ( unsigned long V_239 , unsigned long V_240 ,
unsigned long V_150 ,
unsigned long V_246 , unsigned long V_247 ,
unsigned long V_248 )
{
unsigned long V_196 ;
#ifdef F_97
unsigned long V_241 = F_95 () ;
F_98 ( V_241 ) ;
#else
F_92 () ;
#endif
memset ( & V_249 , 0 , V_250 - V_249 ) ;
F_62 ( V_150 ) ;
F_63 () ;
F_64 () ;
F_10 ( L_310 , V_251 ) ;
V_108 = F_65 () ;
F_10 ( L_311 , V_108 ) ;
#ifndef F_99
if ( V_252 > 0 )
F_37 ( L_312 ) ;
#endif
F_88 ( V_239 , V_240 ) ;
F_20 () ;
#if F_100 ( V_253 ) || F_100 ( V_254 )
if ( V_108 == V_145 ||
V_108 == V_146 )
F_32 () ;
#endif
if ( V_108 != V_160 )
F_101 ( 0 , V_248 , 0x100 , 0 ) ;
F_43 () ;
F_87 () ;
F_67 () ;
#if F_100 ( F_23 ) && F_100 ( F_34 )
if ( V_108 == V_145 )
F_55 () ;
#endif
if ( V_108 != V_160 &&
V_108 != V_162 )
F_53 () ;
#ifdef V_254
if ( V_108 == V_162 )
F_48 () ;
#endif
#ifdef F_23
F_54 () ;
#endif
if ( V_108 != V_160 &&
V_108 != V_162 )
F_58 () ;
if ( V_58 ) {
T_10 V_16 = F_42 ( V_58 ) ;
F_17 ( V_15 . V_54 , L_183 , L_313 ,
& V_16 , sizeof( V_16 ) ) ;
}
#ifdef F_23
if ( V_56 )
F_17 ( V_15 . V_54 , L_183 , L_314 ,
NULL , 0 ) ;
if ( V_57 )
F_17 ( V_15 . V_54 , L_183 , L_315 ,
NULL , 0 ) ;
if ( V_137 ) {
F_17 ( V_15 . V_54 , L_183 , L_316 ,
& V_137 ,
sizeof( V_137 ) ) ;
F_17 ( V_15 . V_54 , L_183 , L_317 ,
& V_138 ,
sizeof( V_138 ) ) ;
}
#endif
F_86 () ;
F_10 ( L_318 ) ;
F_78 () ;
if ( V_108 != V_160 &&
V_108 != V_162 )
F_47 () ;
F_10 ( L_319 ) ;
F_2 ( L_320 , 0 , 0 ) ;
V_196 = V_198 ;
if ( V_108 != V_162 ) {
F_10 ( L_321 , V_248 ) ;
F_25 ( L_322 , V_196 ) ;
}
#ifdef F_97
F_98 ( - V_241 ) ;
#else
F_93 () ;
#endif
#ifdef F_52
F_102 ( V_196 , V_248 , 0 , 0 , 0 ,
V_117 , V_118 ) ;
#else
F_102 ( V_196 , V_248 , 0 , 0 , 0 , 0 , 0 ) ;
#endif
return 0 ;
}
