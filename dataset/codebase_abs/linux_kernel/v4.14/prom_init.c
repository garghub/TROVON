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
static void T_1 F_29 ( T_5 V_16 ,
struct V_61 * V_62 )
{
switch ( V_16 ) {
case F_28 ( V_69 ) :
F_25 ( L_38 ) ;
V_62 -> V_70 = true ;
break;
case F_28 ( V_71 ) :
F_25 ( L_39 ) ;
V_62 -> V_70 = true ;
break;
case F_28 ( V_72 ) :
F_25 ( L_40 ) ;
break;
default:
F_25 ( L_41 , V_16 ) ;
break;
}
}
static void T_1 F_30 ( T_5 V_73 , T_5 V_16 ,
struct V_61 * V_62 )
{
switch ( V_73 ) {
case F_31 ( V_74 ) :
F_27 ( V_16 & F_28 ( V_74 ) , V_62 ) ;
break;
case F_31 ( V_75 ) :
if ( V_16 & F_28 ( V_75 ) ) {
F_25 ( L_42 ) ;
V_62 -> V_76 = true ;
}
break;
case F_31 ( V_77 ) :
F_29 ( V_16 & F_28 ( V_77 ) ,
V_62 ) ;
break;
}
}
static void T_1 F_32 ( void )
{
struct V_61 V_78 = {
. V_66 = false ,
. V_65 = false ,
. V_76 = false ,
. V_70 = false
} ;
int V_79 = F_14 ( V_15 . V_54 ,
L_43 ) ;
if ( V_79 > 1 ) {
int V_6 ;
T_5 V_80 [ V_79 ] ;
F_25 ( L_44 ,
V_79 ) ;
F_13 ( V_15 . V_54 , L_43 ,
& V_80 , sizeof( V_80 ) ) ;
for ( V_6 = 0 ; V_6 < V_79 ; V_6 += 2 ) {
F_25 ( L_45 , V_6 / 2
, V_80 [ V_6 ]
, V_80 [ V_6 + 1 ] ) ;
F_30 ( V_80 [ V_6 ] , V_80 [ V_6 + 1 ] ,
& V_78 ) ;
}
}
if ( V_78 . V_65 && V_78 . V_76 ) {
F_25 ( L_46 ) ;
V_81 . V_82 . V_83 = F_28 ( V_67 ) ;
V_81 . V_82 . V_84 = F_28 ( V_75 ) ;
} else if ( V_78 . V_66 ) {
F_25 ( L_47 ) ;
V_81 . V_82 . V_83 = F_28 ( V_68 ) ;
} else {
F_25 ( L_48 ) ;
}
if ( V_78 . V_70 ) {
F_25 ( L_49 ) ;
V_81 . V_82 . V_85 = F_28 ( V_71 ) ;
}
}
static void T_1 F_33 ( void )
{
T_6 V_86 ;
V_8 V_29 ;
V_38 V_87 ;
F_32 () ;
V_86 = F_2 ( L_50 , 1 , 1 , F_4 ( L_51 ) ) ;
if ( V_86 != 0 ) {
V_87 = F_34 ( V_88 , F_26 () ) ;
F_10 ( L_52 ,
V_87 , V_88 ) ;
V_81 . V_82 . V_89 = F_3 ( V_87 ) ;
F_10 ( L_53 ) ;
if ( F_6 ( L_4 , 3 , 2 , & V_29 ,
F_4 ( L_54 ) ,
V_86 ,
F_4 ( & V_81 ) ) == 0 ) {
if ( V_29 )
F_10 ( L_55
L_56 ) ;
F_2 ( L_57 , 1 , 0 , V_86 ) ;
F_10 ( L_58 ) ;
return;
}
F_2 ( L_57 , 1 , 0 , V_86 ) ;
F_10 ( L_59 ) ;
}
#ifdef F_35
{
T_6 V_90 ;
V_90 = F_2 ( L_50 , 1 , 1 ,
F_4 ( L_60 ) ) ;
if ( V_90 == 0 ) {
F_10 ( L_61 ) ;
return;
}
F_2 ( L_4 , 3 , 1 , F_4 ( L_62 ) ,
V_90 , F_4 ( & V_91 ) ) ;
F_2 ( L_57 , 1 , 0 , V_90 ) ;
}
#endif
}
static unsigned long T_1 F_36 ( unsigned long V_19 , unsigned long V_26 )
{
unsigned long V_47 = V_92 ;
unsigned long V_93 = 0 ;
if ( V_26 )
V_47 = F_37 ( V_47 , V_26 ) ;
F_25 ( L_63 , V_19 , V_26 ) ;
if ( V_94 == 0 )
F_38 ( L_64 ) ;
if ( V_26 )
V_47 = F_37 ( V_92 , V_26 ) ;
else
V_47 = V_92 ;
for(; ( V_47 + V_19 ) <= V_95 ;
V_47 = F_37 ( V_47 + 0x100000 , V_26 ) ) {
F_25 ( L_65 , V_47 ) ;
V_93 = ( unsigned long ) F_11 ( V_47 , V_19 , 0 ) ;
if ( V_93 != V_10 && V_93 != 0 )
break;
V_93 = 0 ;
if ( V_26 == 0 )
break;
}
if ( V_93 == 0 )
return 0 ;
V_92 = V_93 + V_19 ;
F_25 ( L_66 , V_93 ) ;
F_25 ( L_67 , V_92 ) ;
F_25 ( L_68 , V_95 ) ;
F_25 ( L_69 , V_96 ) ;
F_25 ( L_70 , V_97 ) ;
F_25 ( L_71 , V_94 ) ;
return V_93 ;
}
static unsigned long T_1 F_39 ( unsigned long V_19 , unsigned long V_26 ,
int V_98 )
{
unsigned long V_47 , V_93 = 0 ;
F_25 ( L_72 , V_19 , V_26 ,
V_98 ? L_73 : L_74 ) ;
if ( V_94 == 0 )
F_38 ( L_75 ) ;
if ( V_98 ) {
V_93 = F_40 ( V_96 - V_19 , V_26 ) ;
if ( V_93 <= V_92 )
return 0 ;
if ( V_93 < V_97 ) {
if ( V_95 == V_97 )
V_95 = V_97 = V_93 ;
else
return 0 ;
}
V_96 = V_93 ;
goto V_99;
}
V_47 = F_40 ( V_95 - V_19 , V_26 ) ;
for (; V_47 > V_92 ;
V_47 = F_40 ( V_47 - 0x100000 , V_26 ) ) {
F_25 ( L_65 , V_47 ) ;
V_93 = ( unsigned long ) F_11 ( V_47 , V_19 , 0 ) ;
if ( V_93 != V_10 && V_93 != 0 )
break;
V_93 = 0 ;
}
if ( V_93 == 0 )
return 0 ;
V_95 = V_93 ;
V_99:
F_25 ( L_66 , V_93 ) ;
F_25 ( L_67 , V_92 ) ;
F_25 ( L_68 , V_95 ) ;
F_25 ( L_69 , V_96 ) ;
F_25 ( L_70 , V_97 ) ;
F_25 ( L_71 , V_94 ) ;
return V_93 ;
}
static unsigned long T_1 F_41 ( int V_22 , T_7 * * V_100 )
{
T_7 * V_13 = * V_100 ;
unsigned long V_101 = 0 ;
while ( V_22 > sizeof( unsigned long ) / 4 ) {
V_13 ++ ;
V_22 -- ;
}
V_101 = F_5 ( * V_13 ++ ) ;
#ifdef F_23
if ( V_22 > 1 ) {
V_101 <<= 32 ;
V_101 |= F_5 ( * ( V_13 ++ ) ) ;
}
#endif
* V_100 = V_13 ;
return V_101 ;
}
static void T_1 F_42 ( T_8 V_47 , T_8 V_19 )
{
T_8 V_102 = V_47 + V_19 ;
unsigned long V_103 = V_104 ;
if ( V_19 == 0 )
return;
V_47 = F_40 ( V_47 , V_105 ) ;
V_102 = F_37 ( V_102 , V_105 ) ;
V_19 = V_102 - V_47 ;
if ( V_103 >= ( V_106 - 1 ) )
F_38 ( L_76 ) ;
V_107 [ V_103 ] . V_47 = F_43 ( V_47 ) ;
V_107 [ V_103 ] . V_19 = F_43 ( V_19 ) ;
V_104 = V_103 + 1 ;
}
static void T_1 F_44 ( void )
{
T_3 V_34 ;
char * V_108 , type [ 64 ] ;
unsigned int V_60 ;
T_7 * V_13 , * V_46 ;
T_9 V_16 ;
V_38 V_109 , V_110 ;
V_16 = F_3 ( 2 ) ;
F_13 ( V_15 . V_86 , L_77 , & V_16 , sizeof( V_16 ) ) ;
V_109 = F_5 ( V_16 ) ;
V_16 = F_3 ( 1 ) ;
F_13 ( V_15 . V_86 , L_78 , & V_16 , sizeof( V_110 ) ) ;
V_110 = F_5 ( V_16 ) ;
F_25 ( L_79 , V_109 ) ;
F_25 ( L_80 , V_110 ) ;
F_25 ( L_81 ) ;
V_108 = V_111 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
type [ 0 ] = 0 ;
F_13 ( V_34 , L_27 , type , sizeof( type ) ) ;
if ( type [ 0 ] == 0 ) {
F_13 ( V_34 , L_82 , type , sizeof( type ) ) ;
}
if ( strcmp ( type , L_83 ) )
continue;
V_60 = F_13 ( V_34 , L_84 , V_112 , sizeof( V_112 ) ) ;
if ( V_60 > sizeof( V_112 ) ) {
F_10 ( L_85 ) ;
V_60 = sizeof( V_112 ) ;
}
V_13 = V_112 ;
V_46 = V_13 + ( V_60 / sizeof( T_7 ) ) ;
#ifdef F_45
memset ( V_108 , 0 , V_113 ) ;
F_2 ( L_86 , 3 , 1 , V_34 , V_108 , V_113 - 1 ) ;
F_25 ( L_87 , V_108 ) ;
#endif
while ( ( V_46 - V_13 ) >= ( V_109 + V_110 ) ) {
unsigned long V_47 , V_19 ;
V_47 = F_41 ( V_109 , & V_13 ) ;
V_19 = F_41 ( V_110 , & V_13 ) ;
if ( V_19 == 0 )
continue;
F_25 ( L_88 , V_47 , V_19 ) ;
if ( V_47 == 0 && ( V_114 & V_115 ) )
V_97 = V_19 ;
if ( ( V_47 + V_19 ) > V_94 )
V_94 = V_47 + V_19 ;
}
}
V_92 = F_46 ( ( unsigned long ) & V_116 + 0x4000 ) ;
V_96 = V_94 ;
if ( V_58 ) {
if ( V_58 <= V_92 ) {
F_10 ( L_89 ,
V_58 ) ;
V_58 = 0 ;
} else if ( V_58 >= V_94 ) {
F_10 ( L_90 ,
V_58 ) ;
V_58 = 0 ;
} else {
V_94 = V_58 ;
V_97 = F_47 ( V_97 , V_58 ) ;
}
}
if ( ! V_97 )
V_97 = V_94 ;
V_97 = F_47 ( 0x30000000ul , V_97 ) ;
V_95 = V_97 ;
V_96 = V_94 ;
if ( V_117 &&
V_117 < V_97 &&
V_118 > V_92 )
V_92 = F_46 ( V_118 ) ;
F_10 ( L_91 ) ;
F_10 ( L_92 , V_58 ) ;
F_10 ( L_67 , V_92 ) ;
F_10 ( L_68 , V_95 ) ;
F_10 ( L_69 , V_96 ) ;
F_10 ( L_70 , V_97 ) ;
F_10 ( L_71 , V_94 ) ;
}
static void T_1 F_48 ( void )
{
T_9 V_16 ;
T_6 V_119 ;
if ( F_13 ( V_15 . V_54 , L_93 , & V_16 , sizeof( V_16 ) ) > 0 ) {
V_119 = F_5 ( V_16 ) ;
F_2 ( L_57 , 1 , 0 , V_119 ) ;
}
}
static void T_1 F_49 ( void )
{
T_3 V_120 ;
T_6 V_121 ;
T_8 V_47 , V_2 ;
T_8 V_19 = 0 , V_26 = 0x10000 ;
T_10 V_122 ;
V_38 V_11 [ 2 ] ;
F_25 ( L_94 ) ;
V_120 = F_2 ( L_95 , 1 , 1 , F_4 ( L_96 ) ) ;
F_25 ( L_97 , V_120 ) ;
if ( ! F_50 ( V_120 ) )
return;
V_122 = 0 ;
F_13 ( V_120 , L_98 , & V_122 , sizeof( V_122 ) ) ;
V_19 = F_51 ( V_122 ) ;
if ( V_19 == 0 )
return;
V_122 = 0 ;
F_13 ( V_120 , L_99 , & V_122 , sizeof( V_122 ) ) ;
V_26 = F_51 ( V_122 ) ;
V_47 = F_39 ( V_19 , V_26 , 0 ) ;
if ( V_47 == 0 ) {
F_10 ( L_100 ) ;
return;
}
V_121 = F_2 ( L_50 , 1 , 1 , F_4 ( L_96 ) ) ;
if ( ! F_52 ( V_121 ) ) {
F_10 ( L_101 , V_121 ) ;
return;
}
F_10 ( L_102 , V_47 ) ;
if ( F_6 ( L_4 , 4 , 3 , V_11 ,
F_4 ( L_103 ) ,
V_121 ,
V_47 >> 32 , V_47 & 0xffffffff ) != 0
|| ( V_11 [ 0 ] == 0 && V_11 [ 1 ] == 0 ) ) {
F_10 ( L_104 ) ;
return;
}
V_2 = ( ( ( T_8 ) V_11 [ 0 ] ) << 32 ) | V_11 [ 1 ] ;
F_10 ( L_58 ) ;
F_42 ( V_47 , V_19 ) ;
F_25 ( L_105 , V_47 ) ;
F_25 ( L_106 , V_26 ) ;
F_25 ( L_107 , V_2 ) ;
F_25 ( L_108 , ( long ) V_19 ) ;
F_17 ( V_120 , L_96 , L_109 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_120 , L_96 , L_110 ,
& V_2 , sizeof( V_2 ) ) ;
#ifdef F_53
V_123 = V_47 ;
V_124 = V_2 ;
#endif
F_25 ( L_111 ) ;
}
static void T_1 F_54 ( void )
{
T_3 V_125 ;
T_6 V_126 ;
V_38 V_47 , V_2 = 0 ;
T_9 V_16 ;
V_38 V_19 = 0 ;
F_25 ( L_112 ) ;
V_125 = F_2 ( L_95 , 1 , 1 , F_4 ( L_113 ) ) ;
F_25 ( L_114 , V_125 ) ;
if ( ! F_50 ( V_125 ) )
return;
V_16 = 0 ;
F_13 ( V_125 , L_115 , & V_16 , sizeof( V_19 ) ) ;
V_19 = F_5 ( V_16 ) ;
if ( V_19 == 0 )
return;
V_47 = F_39 ( V_19 , V_105 , 0 ) ;
if ( V_47 == 0 )
F_38 ( L_116 ) ;
V_126 = F_2 ( L_50 , 1 , 1 , F_4 ( L_113 ) ) ;
if ( ! F_52 ( V_126 ) ) {
F_10 ( L_117 , V_126 ) ;
return;
}
F_10 ( L_118 , V_47 ) ;
if ( F_6 ( L_4 , 3 , 2 , & V_2 ,
F_4 ( L_119 ) ,
V_126 , V_47 ) != 0
|| V_2 == 0 ) {
F_10 ( L_104 ) ;
return;
}
F_10 ( L_58 ) ;
F_42 ( V_47 , V_19 ) ;
V_16 = F_3 ( V_47 ) ;
F_17 ( V_125 , L_113 , L_120 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_3 ( V_2 ) ;
F_17 ( V_125 , L_113 , L_121 ,
& V_16 , sizeof( V_16 ) ) ;
if ( F_13 ( V_125 , L_122 ,
& V_16 , sizeof( V_16 ) ) != V_10 )
V_127 = true ;
F_25 ( L_123 , V_47 ) ;
F_25 ( L_124 , V_2 ) ;
F_25 ( L_125 , ( long ) V_19 ) ;
F_25 ( L_126 ) ;
}
static void T_1 F_55 ( void )
{
T_3 V_128 ;
T_6 V_129 ;
V_38 V_2 = 0 , V_19 = 0 , V_130 = 0 ;
T_8 V_47 ;
T_9 V_16 ;
F_25 ( L_127 ) ;
V_128 = F_2 ( L_95 , 1 , 1 , F_4 ( L_128 ) ) ;
F_25 ( L_129 , V_128 ) ;
if ( ! F_50 ( V_128 ) )
return;
V_129 = F_2 ( L_50 , 1 , 1 , F_4 ( L_128 ) ) ;
if ( ! F_52 ( V_129 ) ) {
F_10 ( L_130 , V_129 ) ;
return;
}
if ( F_13 ( V_128 , L_131 ,
& V_16 , sizeof( V_16 ) ) != V_10 ) {
if ( F_6 ( L_4 , 2 , 2 , & V_130 ,
F_4 ( L_132 ) ,
V_129 ) != 0 || V_130 == 0 ) {
F_10 ( L_133 ) ;
return;
}
if ( F_6 ( L_4 , 2 , 2 , & V_19 ,
F_4 ( L_134 ) ,
V_129 ) != 0 || V_19 == 0 ) {
F_10 ( L_135 ) ;
return;
}
} else {
if ( F_6 ( L_4 , 2 , 2 , & V_19 ,
F_4 ( L_136 ) ,
V_129 ) != 0 || V_19 == 0 ) {
F_10 ( L_137 ) ;
return;
}
}
V_47 = F_39 ( V_19 , V_105 , 0 ) ;
if ( V_47 == 0 )
F_38 ( L_138 ) ;
F_10 ( L_139 , V_47 ) ;
memset ( ( void * ) V_47 , 0 , V_19 ) ;
if ( F_6 ( L_4 , 4 , 2 , & V_2 ,
F_4 ( L_140 ) ,
V_129 , V_19 , V_47 ) != 0 || V_2 == 0 ) {
F_10 ( L_141 ) ;
return;
}
F_10 ( L_58 ) ;
F_42 ( V_47 , V_19 ) ;
F_17 ( V_128 , L_128 , L_142 ,
& V_47 , sizeof( V_47 ) ) ;
F_17 ( V_128 , L_128 , L_143 ,
& V_19 , sizeof( V_19 ) ) ;
F_25 ( L_144 , V_47 ) ;
F_25 ( L_145 , ( long ) V_19 ) ;
F_25 ( L_146 ) ;
}
static void T_1 F_56 ( void )
{
T_3 V_34 ;
T_6 V_131 ;
char V_132 [ 64 ] , type [ 64 ] , V_133 [ 64 ] ;
char * V_108 = V_111 ;
T_8 V_47 , V_26 ;
V_38 V_134 , V_135 ;
T_8 V_136 , * V_137 ;
T_8 V_138 , V_139 ;
T_8 V_6 ;
if ( V_56 )
return;
F_25 ( L_147 ) ;
V_138 = V_96 ;
V_139 = V_138 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
V_132 [ 0 ] = 0 ;
type [ 0 ] = 0 ;
V_133 [ 0 ] = 0 ;
F_13 ( V_34 , L_148 ,
V_132 , sizeof( V_132 ) ) ;
F_13 ( V_34 , L_27 , type , sizeof( type ) ) ;
F_13 ( V_34 , L_149 , V_133 , sizeof( V_133 ) ) ;
if ( ( type [ 0 ] == 0 ) || ( strstr ( type , L_150 ) == NULL ) )
continue;
if ( V_132 [ 0 ] != 0 ) {
if ( ( strstr ( V_132 , L_151 ) == NULL ) &&
( strstr ( V_132 , L_152 ) == NULL ) &&
( strstr ( V_132 , L_153 ) == NULL ) )
continue;
} else if ( V_133 [ 0 ] != 0 ) {
if ( ( strstr ( V_133 , L_154 ) == NULL ) &&
( strstr ( V_133 , L_155 ) == NULL ) &&
( strstr ( V_133 , L_156 ) == NULL ) )
continue;
}
if ( F_13 ( V_34 , L_157 , & V_134 ,
sizeof( V_134 ) ) == V_10 )
V_134 = 0 ;
if ( F_13 ( V_34 , L_158 , & V_135 ,
sizeof( V_135 ) ) == V_10 )
V_135 = 4UL << 20 ;
if ( F_57 ( V_140 ) || F_57 ( V_141 ) )
V_135 = 8UL << 20 ;
else
V_135 = 4UL << 20 ;
V_26 = F_58 ( V_134 , V_135 ) ;
V_47 = F_39 ( V_135 , V_26 , 1 ) ;
if ( V_47 == 0 )
F_38 ( L_159 ) ;
if ( V_47 < V_139 )
V_139 = V_47 ;
memset ( V_108 , 0 , V_113 ) ;
if ( F_2 ( L_86 , 3 , 1 , V_34 ,
V_108 , V_113 - 1 ) == V_10 ) {
F_10 ( L_160 ) ;
}
F_17 ( V_34 , V_108 , L_161 , & V_47 , sizeof( V_47 ) ) ;
F_17 ( V_34 , V_108 , L_162 , & V_135 , sizeof( V_135 ) ) ;
F_25 ( L_163 , V_108 ) ;
F_25 ( L_164 , V_34 ) ;
F_25 ( L_165 , V_47 ) ;
F_25 ( L_166 , V_135 ) ;
V_137 = ( T_8 * ) V_47 ;
for ( V_6 = 0 ; V_6 < ( V_135 >> 3 ) ; V_137 ++ , V_6 ++ ) {
V_136 = ( V_6 << V_142 ) ;
V_136 |= 0x3 ;
* V_137 = V_136 ;
}
F_10 ( L_167 , V_108 ) ;
V_131 = F_2 ( L_50 , 1 , 1 , V_108 ) ;
if ( V_131 == 0 )
F_10 ( L_168 ) ;
else
F_10 ( L_169 ) ;
F_2 ( L_4 , 6 , 0 , F_4 ( L_170 ) ,
V_131 , - 1 , V_135 ,
( V_38 ) V_47 , ( V_38 ) ( V_47 >> 32 ) ) ;
F_2 ( L_57 , 1 , 0 , V_131 ) ;
}
F_42 ( V_139 , V_138 - V_139 ) ;
V_143 = V_139 ;
V_144 = V_138 ;
F_25 ( L_171 ) ;
}
static void T_1 F_59 ( void )
{
unsigned long V_6 ;
T_3 V_34 ;
char type [ 64 ] ;
unsigned long * V_145
= ( void * ) F_60 ( V_146 ) ;
unsigned long * V_147
= ( void * ) F_60 ( V_148 ) ;
unsigned long V_149 = F_60 ( V_150 ) ;
if ( ( V_114 == V_151 ||
V_114 == V_152 ) &&
V_127 ) {
F_10 ( L_172 ) ;
return;
}
F_25 ( L_173 ) ;
F_25 ( L_174 , ( unsigned long ) V_145 ) ;
F_25 ( L_175 , * V_145 ) ;
F_25 ( L_176 ,
( unsigned long ) V_147 ) ;
F_25 ( L_177 , * V_147 ) ;
F_25 ( L_178 , V_149 ) ;
* V_145 = 0 ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
unsigned int V_153 ;
T_9 V_154 ;
type [ 0 ] = 0 ;
F_13 ( V_34 , L_27 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_28 ) != 0 )
continue;
if ( F_13 ( V_34 , L_179 , type , sizeof( type ) ) > 0 )
if ( strcmp ( type , L_180 ) != 0 )
continue;
V_154 = F_3 ( - 1 ) ;
F_13 ( V_34 , L_84 , & V_154 , sizeof( V_154 ) ) ;
V_153 = F_5 ( V_154 ) ;
F_25 ( L_181 , V_153 ) ;
* V_147 = ( unsigned long ) - 1 ;
if ( V_153 != V_15 . V_155 ) {
F_10 ( L_182 , V_153 ) ;
F_2 ( L_183 , 3 , 0 , V_34 ,
V_149 , V_153 ) ;
for ( V_6 = 0 ; ( V_6 < 100000000 ) &&
( * V_147 == ( ( unsigned long ) - 1 ) ) ; V_6 ++ )
F_61 () ;
if ( * V_147 == V_153 )
F_10 ( L_184 ) ;
else
F_10 ( L_185 , * V_147 ) ;
}
#ifdef F_62
else
F_10 ( L_186 , V_153 ) ;
#endif
}
F_25 ( L_187 ) ;
}
static void T_1 F_63 ( unsigned long V_156 )
{
V_9 = V_156 ;
V_15 . V_54 = F_2 ( L_95 , 1 , 1 , F_4 ( L_188 ) ) ;
if ( ! F_50 ( V_15 . V_54 ) )
F_38 ( L_189 ) ;
V_15 . V_86 = F_2 ( L_95 , 1 , 1 , F_4 ( L_51 ) ) ;
if ( ! F_50 ( V_15 . V_86 ) )
F_38 ( L_190 ) ;
V_15 . V_32 = 0 ;
}
static void T_1 F_64 ( void )
{
T_3 V_157 ;
char V_158 [ 64 ] ;
V_157 = F_2 ( L_95 , 1 , 1 , F_4 ( L_191 ) ) ;
if ( ! F_50 ( V_157 ) )
return;
if ( F_13 ( V_157 , L_149 , V_158 , sizeof( V_158 ) ) <= 0 )
return;
V_158 [ sizeof( V_158 ) - 1 ] = 0 ;
if ( strcmp ( V_158 , L_192 ) == 0 )
V_159 = V_28 ;
else if ( strncmp ( V_158 , L_193 , 12 ) == 0 ) {
V_159 = V_28 | V_44 ;
F_2 ( L_17 , 1 , 1 , L_194 ) ;
} else
return;
V_15 . V_31 = F_2 ( L_50 , 1 , 1 , F_4 ( L_195 ) ) ;
F_13 ( V_15 . V_54 , L_196 , & V_15 . V_32 ,
sizeof( V_15 . V_32 ) ) ;
V_15 . V_32 = F_5 ( V_15 . V_32 ) ;
if ( ! F_52 ( V_15 . V_31 ) || ! F_52 ( V_15 . V_32 ) )
V_159 &= ~ V_28 ;
}
static void T_1 F_65 ( void )
{
char * V_108 = V_160 ;
char type [ 16 ] ;
T_3 V_161 ;
T_9 V_16 ;
if ( F_13 ( V_15 . V_54 , L_197 , & V_16 , sizeof( V_16 ) ) <= 0 )
F_38 ( L_198 ) ;
V_15 . stdout = F_5 ( V_16 ) ;
memset ( V_108 , 0 , 256 ) ;
F_2 ( L_199 , 3 , 1 , V_15 . stdout , V_108 , 255 ) ;
F_10 ( L_200 , V_160 ) ;
F_17 ( V_15 . V_54 , L_188 , L_201 ,
V_108 , strlen ( V_108 ) + 1 ) ;
V_161 = F_2 ( L_202 , 1 , 1 , V_15 . stdout ) ;
if ( V_161 != V_10 ) {
V_16 = F_3 ( V_161 ) ;
F_17 ( V_15 . V_54 , L_188 , L_203 ,
& V_16 , sizeof( V_16 ) ) ;
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_161 , L_27 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_204 ) == 0 )
F_17 ( V_161 , V_108 , L_205 , NULL , 0 ) ;
}
}
static int T_1 F_66 ( void )
{
char V_162 [ 256 ] ;
int V_163 , V_6 = 0 ;
#ifdef F_23
T_3 V_164 ;
int V_40 ;
#endif
V_163 = F_13 ( V_15 . V_86 , L_148 ,
V_162 , sizeof( V_162 ) - 1 ) ;
if ( V_163 > 0 ) {
V_162 [ V_163 ] = 0 ;
while ( V_6 < V_163 ) {
char * V_13 = & V_162 [ V_6 ] ;
int V_165 = strlen ( V_13 ) ;
if ( V_165 == 0 )
break;
if ( strstr ( V_13 , L_206 ) ||
strstr ( V_13 , L_207 ) )
return V_166 ;
#ifdef F_23
if ( strstr ( V_13 , L_208 ) ||
strstr ( V_13 , L_209 ) )
return V_167 ;
#endif
V_6 += V_165 + 1 ;
}
}
#ifdef F_23
if ( F_50 ( F_2 ( L_95 , 1 , 1 , F_4 ( L_96 ) ) ) )
return V_168 ;
V_163 = F_13 ( V_15 . V_86 , L_27 ,
V_162 , sizeof( V_162 ) - 1 ) ;
if ( V_163 <= 0 )
return V_167 ;
if ( strcmp ( V_162 , L_210 ) )
return V_167 ;
V_164 = F_2 ( L_95 , 1 , 1 , F_4 ( L_113 ) ) ;
if ( ! F_50 ( V_164 ) )
return V_167 ;
V_40 = F_14 ( V_164 , L_211 ) ;
if ( V_40 != V_10 ) {
F_25 ( L_212 ) ;
return V_152 ;
}
return V_151 ;
#else
return V_167 ;
#endif
}
static int T_1 F_67 ( T_6 V_169 , int V_6 , int V_101 , int V_170 , int V_171 )
{
return F_2 ( L_4 , 6 , 1 , F_4 ( L_213 ) , V_169 , V_6 , V_171 , V_170 , V_101 ) ;
}
static void T_1 F_68 ( void )
{
char type [ 16 ] , * V_108 ;
T_3 V_34 ;
T_6 V_169 ;
int V_6 ;
static unsigned char V_172 [] = {
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
const unsigned char * V_173 ;
F_25 ( L_214 ) ;
for ( V_34 = 0 ; F_12 ( & V_34 ) ; ) {
memset ( type , 0 , sizeof( type ) ) ;
F_13 ( V_34 , L_27 , type , sizeof( type ) ) ;
if ( strcmp ( type , L_204 ) != 0 )
continue;
V_108 = V_111 ;
memset ( V_108 , 0 , V_113 ) ;
if ( F_2 ( L_86 , 3 , 1 , V_34 , V_108 ,
V_113 - 10 ) == V_10 )
continue;
F_10 ( L_215 , V_108 ) ;
V_169 = F_2 ( L_50 , 1 , 1 , V_108 ) ;
if ( V_169 == 0 ) {
F_10 ( L_216 ) ;
continue;
}
F_10 ( L_184 ) ;
F_17 ( V_34 , V_108 , L_217 , NULL , 0 ) ;
V_173 = V_172 ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ , V_173 += 3 )
if ( F_67 ( V_169 , V_6 , V_173 [ 0 ] , V_173 [ 1 ] ,
V_173 [ 2 ] ) != 0 )
break;
#ifdef F_69
V_173 = F_70 ( V_174 . V_173 ) ;
for ( V_6 = 0 ; V_6 < V_174 . V_175 ; V_6 ++ , V_173 += 3 )
if ( F_67 ( V_169 , V_6 + 32 , V_173 [ 0 ] , V_173 [ 1 ] ,
V_173 [ 2 ] ) != 0 )
break;
#endif
#ifdef F_71
if ( F_13 ( V_34 , L_205 , NULL , 0 ) !=
V_10 ) {
V_38 V_176 , V_177 , V_178 , V_93 ;
F_10 ( L_218 ) ;
F_13 ( V_34 , L_219 , & V_176 , 4 ) ;
F_13 ( V_34 , L_220 , & V_177 , 4 ) ;
F_13 ( V_34 , L_221 , & V_178 , 4 ) ;
F_13 ( V_34 , L_222 , & V_93 , 4 ) ;
F_10 ( L_223 ,
V_176 , V_177 , V_178 , V_93 ) ;
F_72 ( V_176 , V_177 , 8 , V_178 , V_93 ) ;
}
#endif
}
}
static void T_1 * F_73 ( unsigned long * V_179 , unsigned long * V_180 ,
unsigned long V_181 , unsigned long V_26 )
{
void * V_29 ;
* V_179 = F_74 ( * V_179 , V_26 ) ;
while ( ( * V_179 + V_181 ) > * V_180 ) {
unsigned long V_182 , V_183 ;
F_25 ( L_224 ,
V_92 ) ;
V_182 = V_95 - V_92 ;
if ( V_182 > V_184 )
V_182 = V_184 ;
if ( V_182 < V_105 )
F_38 ( L_225
L_226 ) ;
V_183 = F_36 ( V_182 , 0 ) ;
if ( V_183 == 0 )
F_38 ( L_225
L_227 ) ;
* V_180 = V_183 + V_182 ;
}
V_29 = ( void * ) * V_179 ;
* V_179 += V_181 ;
return V_29 ;
}
static unsigned long T_1 F_75 ( char * V_39 )
{
char * V_22 , * V_185 ;
V_22 = V_185 = ( char * ) V_186 ;
V_22 += 4 ;
while ( V_22 < ( char * ) V_187 ) {
if ( strcmp ( V_22 , V_39 ) == 0 )
return V_22 - V_185 ;
V_22 += strlen ( V_22 ) + 1 ;
}
return 0 ;
}
static void T_1 F_76 ( T_3 V_34 ,
unsigned long * V_179 ,
unsigned long * V_180 )
{
char * V_188 , * V_189 , * V_190 ;
unsigned long V_191 ;
T_3 V_192 ;
V_190 = ( char * ) V_186 ;
V_188 = L_228 ;
for (; ; ) {
V_189 = F_73 ( V_179 , V_180 , V_193 , 1 ) ;
if ( F_2 ( L_229 , 3 , 1 , V_34 , V_188 , V_189 ) != 1 ) {
* V_179 = ( unsigned long ) V_189 ;
break;
}
if ( strcmp ( V_189 , L_82 ) == 0 ) {
* V_179 = ( unsigned long ) V_189 ;
V_188 = L_82 ;
continue;
}
V_191 = F_75 ( V_189 ) ;
if ( V_191 != 0 ) {
* V_179 = ( unsigned long ) V_189 ;
V_189 = V_190 + V_191 ;
} else {
* V_179 = ( unsigned long ) V_189 + strlen ( V_189 ) + 1 ;
V_187 = * V_179 ;
}
V_188 = V_189 ;
}
V_192 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_192 != 0 ) {
F_76 ( V_192 , V_179 , V_180 ) ;
V_192 = F_2 ( L_9 , 1 , 1 , V_192 ) ;
}
}
static void T_1 F_77 ( T_3 V_34 , unsigned long * V_179 ,
unsigned long * V_180 )
{
T_3 V_192 ;
char * V_189 , * V_188 , * V_190 , * V_13 , * V_194 , * V_195 , * V_108 ;
unsigned long V_191 ;
unsigned char * V_196 ;
static char V_35 [ V_193 ] ;
int V_52 , V_182 , V_197 = 0 ;
F_78 ( V_198 , V_179 , V_180 ) ;
V_189 = ( char * ) * V_179 ;
V_182 = * V_180 - * V_179 ;
if ( V_182 > 255 )
V_182 = 255 ;
V_52 = F_2 ( L_86 , 3 , 1 , V_34 , V_189 , V_182 ) ;
if ( V_52 >= 0 ) {
if ( V_52 >= V_182 ) {
if ( V_52 >= * V_180 - * V_179 )
V_189 = F_73 ( V_179 , V_180 , V_52 + 1 , 1 ) ;
F_2 ( L_86 , 3 , 1 , V_34 , V_189 , V_52 ) ;
}
V_189 [ V_52 ] = '\0' ;
for ( V_195 = V_13 = V_189 , V_194 = V_189 + V_52 ; V_13 < V_194 ; V_13 ++ ) {
if ( * V_13 == '/' )
V_195 = V_189 ;
else if ( * V_13 != 0 )
* V_195 ++ = * V_13 ;
}
* V_195 = 0 ;
* V_179 = F_74 ( ( unsigned long ) V_195 + 1 , 4 ) ;
}
V_108 = V_111 ;
memset ( V_108 , 0 , V_113 ) ;
F_2 ( L_86 , 3 , 1 , V_34 , V_108 , V_113 - 1 ) ;
V_188 = L_228 ;
V_190 = ( char * ) V_186 ;
for (; ; ) {
if ( F_2 ( L_229 , 3 , 1 , V_34 , V_188 ,
V_35 ) != 1 )
break;
if ( strcmp ( V_35 , L_82 ) == 0 ) {
V_188 = L_82 ;
continue;
}
V_191 = F_75 ( V_35 ) ;
if ( V_191 == 0 ) {
F_10 ( L_230
L_231 , V_35 , V_108 ) ;
break;
}
V_188 = V_190 + V_191 ;
V_52 = F_2 ( L_12 , 2 , 1 , V_34 , V_35 ) ;
if ( V_52 == V_10 )
continue;
F_78 ( V_199 , V_179 , V_180 ) ;
F_78 ( V_52 , V_179 , V_180 ) ;
F_78 ( V_191 , V_179 , V_180 ) ;
V_196 = F_73 ( V_179 , V_180 , V_52 , 4 ) ;
F_2 ( L_11 , 4 , 1 , V_34 , V_35 , V_196 , V_52 ) ;
* V_179 = F_74 ( * V_179 , 4 ) ;
if ( ! strcmp ( V_35 , L_232 ) )
V_197 = 1 ;
}
if ( ! V_197 ) {
V_191 = F_75 ( L_233 ) ;
if ( V_191 == 0 )
F_10 ( L_230
L_234 , V_108 ) ;
else {
F_78 ( V_199 , V_179 , V_180 ) ;
F_78 ( 4 , V_179 , V_180 ) ;
F_78 ( V_191 , V_179 , V_180 ) ;
V_196 = F_73 ( V_179 , V_180 , 4 , 4 ) ;
* ( T_9 * ) V_196 = F_3 ( V_34 ) ;
}
}
V_192 = F_2 ( L_8 , 1 , 1 , V_34 ) ;
while ( V_192 != 0 ) {
F_77 ( V_192 , V_179 , V_180 ) ;
V_192 = F_2 ( L_9 , 1 , 1 , V_192 ) ;
}
F_78 ( V_200 , V_179 , V_180 ) ;
}
static void T_1 F_79 ( void )
{
T_3 V_86 ;
unsigned long V_179 , V_180 , V_182 ;
struct V_201 * V_202 ;
char * V_189 ;
T_8 * V_203 ;
V_182 = V_95 - V_92 - 0x4000 ;
if ( V_182 > V_184 )
V_182 = V_184 ;
F_25 ( L_235 , V_92 ) ;
V_179 = ( unsigned long ) F_36 ( V_182 , V_105 ) ;
if ( V_179 == 0 )
F_38 ( L_236 ) ;
V_180 = V_179 + V_182 ;
V_86 = F_2 ( L_9 , 1 , 1 , ( T_3 ) 0 ) ;
if ( V_86 == ( T_3 ) 0 )
F_38 ( L_237 ) ;
V_179 = F_74 ( V_179 , 4 ) ;
V_202 = F_73 ( & V_179 , & V_180 ,
sizeof( struct V_201 ) , 4 ) ;
V_204 = ( unsigned long ) V_202 ;
V_203 = F_73 ( & V_179 , & V_180 , sizeof( V_107 ) , 8 ) ;
V_179 = F_46 ( V_179 ) ;
V_186 = V_179 ;
V_179 += 4 ;
V_189 = F_73 ( & V_179 , & V_180 , 16 , 1 ) ;
strcpy ( V_189 , L_233 ) ;
V_179 = ( unsigned long ) V_189 + strlen ( V_189 ) + 1 ;
F_10 ( L_238 ) ;
F_76 ( V_86 , & V_179 , & V_180 ) ;
V_187 = V_179 ;
V_179 = F_46 ( V_179 ) ;
V_205 = V_179 ;
F_10 ( L_239 ) ;
F_77 ( V_86 , & V_179 , & V_180 ) ;
F_78 ( V_206 , & V_179 , & V_180 ) ;
V_207 = F_46 ( V_179 ) ;
V_202 -> V_208 = F_3 ( V_15 . V_155 ) ;
V_202 -> V_209 = F_3 ( V_210 ) ;
V_202 -> V_211 = F_3 ( V_207 - V_204 ) ;
V_202 -> V_212 = F_3 ( V_205 - V_204 ) ;
V_202 -> V_213 = F_3 ( V_186 - V_204 ) ;
V_202 -> V_214 = F_3 ( V_187 - V_186 ) ;
V_202 -> V_215 = F_3 ( ( ( unsigned long ) V_203 ) - V_204 ) ;
V_202 -> V_158 = F_3 ( V_216 ) ;
V_202 -> V_217 = F_3 ( 0x10 ) ;
memcpy ( V_203 , V_107 , sizeof( V_107 ) ) ;
#ifdef F_45
{
int V_6 ;
F_10 ( L_240 ) ;
for ( V_6 = 0 ; V_6 < V_104 ; V_6 ++ )
F_10 ( L_241 ,
F_51 ( V_107 [ V_6 ] . V_47 ) ,
F_51 ( V_107 [ V_6 ] . V_19 ) ) ;
}
#endif
V_104 = V_106 ;
F_10 ( L_242 ,
V_186 , V_187 ) ;
F_10 ( L_243 ,
V_205 , V_207 ) ;
}
static void T_1 F_80 ( void )
{
T_3 V_218 ;
V_38 V_219 = 0x01002000 ;
V_38 V_220 [ 6 ] ;
char * V_221 ;
V_221 = L_244 ;
V_218 = F_2 ( L_95 , 1 , 1 , F_4 ( V_221 ) ) ;
if ( ! F_50 ( V_218 ) ) {
V_221 = L_245 ;
V_218 = F_2 ( L_95 , 1 , 1 , F_4 ( V_221 ) ) ;
V_219 = 0x01003000 ;
}
if ( ! F_50 ( V_218 ) )
return;
if ( F_14 ( V_218 , L_246 ) != 12 )
return;
if ( F_13 ( V_218 , L_246 , V_220 , sizeof( V_220 ) )
== V_10 )
return;
if ( V_220 [ 0 ] != 0x1 ||
V_220 [ 1 ] != 0xf4000000 ||
V_220 [ 2 ] != 0x00010000 )
return;
F_10 ( L_247 ) ;
V_220 [ 0 ] = 0x1 ;
V_220 [ 1 ] = 0x0 ;
V_220 [ 2 ] = V_219 ;
V_220 [ 3 ] = 0x0 ;
V_220 [ 4 ] = 0x0 ;
V_220 [ 5 ] = 0x00010000 ;
F_17 ( V_218 , V_221 , L_246 ,
V_220 , sizeof( V_220 ) ) ;
}
static void T_1 F_81 ( void )
{
T_3 V_222 ;
V_38 V_223 [ 4 ] ;
char * V_221 = L_248 ;
V_38 V_224 , V_225 ;
V_222 = F_2 ( L_95 , 1 , 1 , F_4 ( V_221 ) ) ;
if ( ! F_50 ( V_222 ) )
return;
if ( F_14 ( V_222 , L_84 ) != 8 )
return;
F_13 ( V_15 . V_86 , L_77 , & V_224 , sizeof( V_224 ) ) ;
F_13 ( V_15 . V_86 , L_78 , & V_225 , sizeof( V_225 ) ) ;
if ( ( V_224 != 2 ) || ( V_225 != 2 ) )
return;
if ( F_13 ( V_222 , L_84 , V_223 , sizeof( V_223 ) ) == V_10 )
return;
if ( V_223 [ 0 ] != V_226 || V_223 [ 1 ] != V_227 )
return;
F_10 ( L_249 ) ;
V_223 [ 0 ] = 0x0 ;
V_223 [ 1 ] = V_226 ;
V_223 [ 2 ] = 0x0 ;
V_223 [ 3 ] = V_227 ;
F_17 ( V_222 , V_221 , L_84 , V_223 , sizeof( V_223 ) ) ;
}
static void T_1 F_82 ( void )
{
T_3 V_228 ;
V_38 V_229 [ 6 ] ;
V_38 V_219 = 0x01006000 ;
char * V_221 ;
int V_230 ;
V_221 = L_250 ;
V_228 = F_2 ( L_95 , 1 , 1 , F_4 ( V_221 ) ) ;
if ( ! F_50 ( V_228 ) ) {
V_221 = L_251 ;
V_228 = F_2 ( L_95 , 1 , 1 , F_4 ( V_221 ) ) ;
V_219 = 0x01003000 ;
}
if ( F_50 ( V_228 ) ) {
V_230 = F_14 ( V_228 , L_246 ) ;
if ( V_230 == 0 || V_230 == V_10 ) {
F_10 ( L_252 ) ;
V_229 [ 0 ] = 0x1 ;
V_229 [ 1 ] = 0x0 ;
V_229 [ 2 ] = V_219 ;
V_229 [ 3 ] = 0x0 ;
V_229 [ 4 ] = 0x0 ;
V_229 [ 5 ] = 0x00010000 ;
F_17 ( V_228 , V_221 , L_246 , V_229 , sizeof( V_229 ) ) ;
}
}
V_221 = L_253 ;
V_228 = F_2 ( L_95 , 1 , 1 , F_4 ( V_221 ) ) ;
if ( F_50 ( V_228 ) ) {
F_10 ( L_254 ) ;
V_229 [ 0 ] = 14 ;
V_229 [ 1 ] = 0x0 ;
F_17 ( V_228 , V_221 , L_255 , V_229 , 2 * sizeof( V_38 ) ) ;
F_10 ( L_256 ) ;
V_230 = F_13 ( V_228 , L_257 , V_229 , sizeof( V_38 ) ) ;
if ( V_230 == sizeof( V_38 ) ) {
V_229 [ 0 ] &= ~ 0x5 ;
F_17 ( V_228 , V_221 , L_257 , V_229 , sizeof( V_38 ) ) ;
}
}
}
static void T_1 F_83 ( void )
{
T_3 V_231 , V_232 , V_233 ;
V_38 V_234 ;
V_38 V_235 [ 2 ] ;
V_38 V_236 ;
V_231 = F_2 ( L_95 , 1 , 1 , F_4 ( L_258 ) ) ;
if ( ! F_50 ( V_231 ) )
return;
V_232 = F_2 ( L_95 , 1 , 1 , F_4 ( L_259 ) ) ;
if ( ! F_50 ( V_232 ) )
return;
V_233 = F_2 ( L_95 , 1 , 1 , F_4 ( L_260 ) ) ;
if ( ! F_50 ( V_233 ) )
return;
if ( F_13 ( V_231 , L_261 , & V_234 , sizeof( V_234 ) )
== V_10 )
return;
if ( V_234 < 0x35 || V_234 > 0x39 )
return;
if ( F_14 ( V_232 , L_255 ) > 0 )
return;
F_10 ( L_262 ) ;
V_235 [ 0 ] = 0 ;
V_235 [ 1 ] = 1 ;
F_17 ( V_232 , L_259 , L_255 ,
& V_235 , sizeof( V_235 ) ) ;
V_236 = ( V_38 ) V_233 ;
F_17 ( V_232 , L_259 , L_263 ,
& V_236 , sizeof( V_236 ) ) ;
}
static void T_1 F_84 ( void )
{
V_38 V_34 ;
char V_229 [ 64 ] ;
int V_237 ;
V_34 = F_2 ( L_95 , 1 , 1 , F_4 ( L_264 ) ) ;
if ( ! F_50 ( V_34 ) )
return;
V_237 = F_13 ( V_34 , L_265 , V_229 , sizeof( V_229 ) ) ;
if ( ! V_237 )
return;
V_34 = F_2 ( L_95 , 1 , 1 , F_4 ( L_266 ) ) ;
if ( ! F_50 ( V_34 ) ) {
F_10 ( L_267 ) ;
F_2 ( L_17 , 1 , 1 ,
L_268
L_269
L_270
L_271
L_272
L_273
L_274
L_275
L_276
L_277
L_278
L_279
L_280 ) ;
} ;
V_34 = F_2 ( L_95 , 1 , 1 ,
F_4 ( L_281 ) ) ;
if ( ! F_50 ( V_34 ) ) {
F_10 ( L_282 ) ;
F_2 ( L_17 , 1 , 1 ,
L_283
L_269
L_284
L_285
L_286
L_287
L_280
L_288
L_289
L_290
L_291 ) ;
}
}
static void T_1 F_85 ( void )
{
int V_238 [ 3 ] = { 2 , 2 , 0 } ;
int V_239 [ 3 * 16 ] = { 3 , 0 , 0 , 3 , 1 , 0 , 3 , 2 , 0 , 3 , 3 , 0 ,
3 , 4 , 0 , 3 , 5 , 0 , 3 , 6 , 0 , 3 , 7 , 0 ,
3 , 8 , 0 , 3 , 9 , 0 , 3 , 10 , 0 , 3 , 11 , 0 ,
3 , 12 , 0 , 3 , 13 , 0 , 3 , 14 , 0 , 3 , 15 , 0 } ;
V_38 V_34 ;
char V_229 [ 64 ] ;
int V_237 , V_163 ;
V_34 = F_2 ( L_95 , 1 , 1 , F_4 ( L_51 ) ) ;
if ( ! F_50 ( V_34 ) )
return;
V_237 = F_13 ( V_34 , L_149 , V_229 , sizeof( V_229 ) ) ;
if ( V_237 == V_10 )
return;
if ( strcmp ( V_229 , L_292 ) )
return;
F_10 ( L_293 ) ;
V_34 = F_2 ( L_95 , 1 , 1 , F_4 ( L_51 ) ) ;
V_237 = F_13 ( V_34 , L_27 , V_229 , sizeof( V_229 ) ) ;
if ( V_237 != V_10 && ( strcmp ( V_229 , L_210 ) == 0 ) )
F_17 ( V_34 , L_51 , L_27 , L_294 , sizeof( L_294 ) ) ;
V_237 = F_13 ( V_34 , L_295 , V_229 , sizeof( V_229 ) ) ;
if ( V_237 != V_10 && ( strstr ( V_229 , L_296 ) ) )
F_17 ( V_34 , L_51 , L_295 ,
L_297 ,
sizeof( L_297 ) ) ;
V_34 = F_2 ( L_95 , 1 , 1 , F_4 ( L_298 ) ) ;
if ( F_50 ( V_34 ) ) {
V_163 = F_14 ( V_34 , L_255 ) ;
if ( V_163 == 12 ) {
F_10 ( L_299 ) ;
F_17 ( V_34 , L_300 , L_255 ,
V_239 , sizeof( V_239 ) ) ;
}
}
V_34 = F_2 ( L_95 , 1 , 1 , F_4 ( L_301 ) ) ;
if ( F_50 ( V_34 ) ) {
V_237 = F_13 ( V_34 , L_255 , V_229 , sizeof( V_229 ) ) ;
if ( V_237 == V_10 ) {
F_10 ( L_302 ) ;
F_17 ( V_34 , L_301 , L_255 ,
V_238 , sizeof( V_238 ) ) ;
}
}
F_84 () ;
}
static void T_1 F_86 ( void )
{
V_38 V_235 [ 2 ] , V_236 , V_240 , V_16 = 0 ;
char * V_221 , * V_241 ;
T_3 V_242 , V_34 ;
V_221 = L_303 ;
V_242 = F_2 ( L_95 , 1 , 1 , F_4 ( V_221 ) ) ;
if ( ! F_50 ( V_242 ) )
return;
if ( F_14 ( V_242 , L_304 ) != V_10 )
return;
F_10 ( L_305 ) ;
F_17 ( V_242 , V_221 , L_304 , & V_16 , 0 ) ;
V_241 = L_306 ;
V_34 = F_2 ( L_95 , 1 , 1 , F_4 ( V_241 ) ) ;
V_236 = F_4 ( V_242 ) ;
for( ; F_12 ( & V_34 ) ; ) {
if ( ! F_50 ( V_34 ) )
continue;
V_240 = F_14 ( V_34 , L_255 ) ;
if ( V_240 == 0 || V_240 == V_10 )
continue;
F_13 ( V_34 , L_255 , & V_235 , sizeof( V_235 ) ) ;
if ( ( V_235 [ 0 ] < 212 ) || ( V_235 [ 0 ] > 222 ) )
continue;
if ( ( V_235 [ 0 ] >= 212 ) && ( V_235 [ 0 ] <= 215 ) )
V_235 [ 0 ] -= 203 ;
if ( ( V_235 [ 0 ] >= 216 ) && ( V_235 [ 0 ] <= 220 ) )
V_235 [ 0 ] -= 213 ;
if ( V_235 [ 0 ] == 221 )
V_235 [ 0 ] = 14 ;
if ( V_235 [ 0 ] == 222 )
V_235 [ 0 ] = 8 ;
F_17 ( V_34 , V_241 , L_255 , V_235 ,
sizeof( V_235 ) ) ;
F_17 ( V_34 , V_241 , L_263 , & V_236 ,
sizeof( V_236 ) ) ;
}
V_221 = L_307 ;
V_242 = F_2 ( L_95 , 1 , 1 , F_4 ( V_221 ) ) ;
if ( ! F_50 ( V_242 ) )
return;
F_10 ( L_308 ) ;
F_17 ( V_242 , V_221 , L_27 , L_309 , sizeof( L_309 ) ) ;
}
static inline void F_86 ( void ) { }
static void T_1 F_87 ( void )
{
F_80 () ;
F_81 () ;
F_82 () ;
F_83 () ;
F_85 () ;
F_86 () ;
}
static void T_1 F_88 ( void )
{
T_9 V_240 ;
T_6 V_243 ;
T_3 V_244 ;
V_240 = 0 ;
if ( F_13 ( V_15 . V_54 , L_28 , & V_240 , sizeof( V_240 ) ) <= 0 )
return;
V_243 = F_5 ( V_240 ) ;
V_244 = F_2 ( L_202 , 1 , 1 , V_243 ) ;
if ( ! F_50 ( V_244 ) )
return;
F_13 ( V_244 , L_84 , & V_240 , sizeof( V_240 ) ) ;
V_15 . V_155 = F_5 ( V_240 ) ;
F_25 ( L_310 , V_15 . V_155 ) ;
}
static void T_1 F_89 ( unsigned long V_245 , unsigned long V_246 )
{
#ifdef F_90
if ( V_245 && V_246 && V_246 != 0xdeadbeef ) {
T_10 V_16 ;
V_117 = F_91 ( V_245 ) ? F_92 ( V_245 ) : V_245 ;
V_118 = V_117 + V_246 ;
V_16 = F_43 ( V_117 ) ;
F_17 ( V_15 . V_54 , L_188 , L_311 ,
& V_16 , sizeof( V_16 ) ) ;
V_16 = F_43 ( V_118 ) ;
F_17 ( V_15 . V_54 , L_188 , L_312 ,
& V_16 , sizeof( V_16 ) ) ;
F_42 ( V_117 ,
V_118 - V_117 ) ;
F_25 ( L_313 , V_117 ) ;
F_25 ( L_314 , V_118 ) ;
}
#endif
}
static void F_93 ( void )
{
}
static void F_94 ( void )
{
}
static void F_95 ( unsigned long V_247 , unsigned long V_248 )
{
unsigned long V_6 ;
unsigned long * V_249 ;
asm volatile("addi %0,2,-0x8000" : "=b" (toc_entry));
for ( V_6 = 0 ; V_6 < V_248 ; V_6 ++ ) {
* V_249 = * V_249 + V_247 ;
V_249 ++ ;
}
}
static void F_93 ( void )
{
unsigned long V_247 = F_96 () ;
unsigned long V_248 =
( V_250 - V_251 ) / sizeof( long ) ;
F_95 ( V_247 , V_248 ) ;
F_61 () ;
}
static void F_94 ( void )
{
unsigned long V_247 = F_96 () ;
unsigned long V_248 =
( V_250 - V_251 ) / sizeof( long ) ;
F_61 () ;
F_95 ( - V_247 , V_248 ) ;
}
unsigned long T_1 F_97 ( unsigned long V_245 , unsigned long V_246 ,
unsigned long V_156 ,
unsigned long V_252 , unsigned long V_253 ,
unsigned long V_254 )
{
unsigned long V_202 ;
#ifdef F_98
unsigned long V_247 = F_96 () ;
F_99 ( V_247 ) ;
#else
F_93 () ;
#endif
memset ( & V_255 , 0 , V_256 - V_255 ) ;
F_63 ( V_156 ) ;
F_64 () ;
F_65 () ;
F_10 ( L_315 , V_257 ) ;
V_114 = F_66 () ;
F_10 ( L_316 , V_114 ) ;
#ifndef F_100
if ( V_258 > 0 )
F_38 ( L_317 ) ;
#endif
F_89 ( V_245 , V_246 ) ;
F_20 () ;
#if F_101 ( V_259 ) || F_101 ( V_260 )
if ( V_114 == V_151 ||
V_114 == V_152 )
F_33 () ;
#endif
if ( V_114 != V_166 )
F_102 ( 0 , V_254 , 0x100 , 0 ) ;
F_44 () ;
F_88 () ;
F_68 () ;
#if F_101 ( F_23 ) && F_101 ( F_35 )
if ( V_114 == V_151 )
F_56 () ;
#endif
if ( V_114 != V_166 &&
V_114 != V_168 )
F_54 () ;
#ifdef V_260
if ( V_114 == V_168 )
F_49 () ;
#endif
#ifdef F_23
F_55 () ;
#endif
if ( V_114 != V_166 &&
V_114 != V_168 )
F_59 () ;
if ( V_58 ) {
T_10 V_16 = F_43 ( V_58 ) ;
F_17 ( V_15 . V_54 , L_188 , L_318 ,
& V_16 , sizeof( V_16 ) ) ;
}
#ifdef F_23
if ( V_56 )
F_17 ( V_15 . V_54 , L_188 , L_319 ,
NULL , 0 ) ;
if ( V_57 )
F_17 ( V_15 . V_54 , L_188 , L_320 ,
NULL , 0 ) ;
if ( V_143 ) {
F_17 ( V_15 . V_54 , L_188 , L_321 ,
& V_143 ,
sizeof( V_143 ) ) ;
F_17 ( V_15 . V_54 , L_188 , L_322 ,
& V_144 ,
sizeof( V_144 ) ) ;
}
#endif
F_87 () ;
F_10 ( L_323 ) ;
F_79 () ;
if ( V_114 != V_166 &&
V_114 != V_168 )
F_48 () ;
F_10 ( L_324 ) ;
F_2 ( L_325 , 0 , 0 ) ;
V_202 = V_204 ;
if ( V_114 != V_168 ) {
F_10 ( L_326 , V_254 ) ;
F_25 ( L_327 , V_202 ) ;
}
#ifdef F_98
F_99 ( - V_247 ) ;
#else
F_94 () ;
#endif
#ifdef F_53
F_103 ( V_202 , V_254 , 0 , 0 , 0 ,
V_123 , V_124 ) ;
#else
F_103 ( V_202 , V_254 , 0 , 0 , 0 , 0 , 0 ) ;
#endif
return 0 ;
}
