static void F_1 ( void )
{
int V_1 ;
int V_2 = 1 ;
const int V_3 = 1 ;
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
( void ) F_2 ( V_5 , V_6 [ V_7 ] ) ;
F_3 ( V_5 , V_8 - 3 , V_2 ,
L_1 ,
V_9 [ V_1 ] . V_10 ) ;
( void ) F_2 ( V_5 , V_6 [ V_11 ] ) ;
V_2 += strlen ( V_9 [ V_1 ] . V_10 ) ;
F_3 ( V_5 , V_8 - 3 ,
V_2 , L_1 ,
V_9 [ V_1 ] . V_12 ) ;
V_2 += strlen ( V_9 [ V_1 ] . V_12 ) + V_3 ;
}
( void ) F_2 ( V_5 , V_6 [ V_13 ] ) ;
}
static void F_4 ( int * V_14 , struct V_15 * V_16 )
{
F_5 ( V_5 ,
_ ( L_2 ) , _ ( V_17 ) ) ;
return;
}
static void F_6 ( int * V_14 , struct V_15 * V_16 )
{
F_7 ( V_16 ) ;
return;
}
static void F_8 ( int * V_14 , struct V_15 * V_16 )
{
F_5 ( V_5 ,
_ ( L_3 ) ,
_ ( V_18 ) ) ;
return;
}
static void F_9 ( int * V_14 , struct V_15 * V_16 )
{
int V_19 = F_10 ( V_5 ,
_ ( L_4 ) ,
2 ,
L_5 ,
L_6 ) ;
if ( V_19 == 0 )
V_20 = 1 ;
else if ( V_19 == 1 )
V_20 = 0 ;
return;
}
static void F_11 ( int * V_14 , struct V_15 * V_16 )
{
* V_14 = V_21 ;
return;
}
static void F_12 ( int * V_14 , struct V_15 * V_16 )
{
F_13 () ;
return;
}
static void F_14 ( int * V_14 , struct V_15 * V_16 )
{
F_15 () ;
return;
}
static void F_16 ( int * V_14 , struct V_15 * V_16 )
{
F_17 () ;
return;
}
static void F_18 ( int * V_14 , struct V_15 * V_16 )
{
F_19 () ;
return;
}
static int F_20 ( int * V_14 , struct V_15 * V_15 )
{
int V_1 ;
if ( * V_14 == V_22 ) {
F_21 () ;
return 1 ;
}
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
if ( * V_14 == F_22 ( V_9 [ V_1 ] . V_14 ) ||
* V_14 == '0' + V_9 [ V_1 ] . V_14 ) {
V_9 [ V_1 ] . F_23 ( V_14 , V_15 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_24 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_23 [ V_1 ] ; V_1 ++ )
F_25 ( V_23 [ V_1 ] ) ;
F_26 ( V_23 , sizeof( V_23 ) ) ;
F_26 ( V_24 , sizeof( V_24 ) ) ;
V_25 = 0 ;
}
static int F_27 ( const char * V_26 , T_1 V_27 )
{
int V_28 = F_28 ( V_16 ( V_29 ) ) ;
int V_30 ;
if ( V_27 == V_31 )
++ V_28 ;
else if ( V_27 == V_32 )
-- V_28 ;
V_30 = V_28 ;
V_30 = ( V_30 + V_25 ) % V_25 ;
while ( true ) {
char * V_33 = V_24 [ V_30 ] . V_33 ;
if ( F_29 ( V_33 , V_26 ) != 0 )
return V_30 ;
if ( V_27 == V_32 ||
V_27 == V_34 )
-- V_30 ;
else
++ V_30 ;
V_30 = ( V_30 + V_25 ) % V_25 ;
if ( V_30 == V_28 )
return - 1 ;
}
}
static void F_30 ( struct V_15 * V_15 , char V_35 , const char * V_36 , ... )
{
T_2 V_37 ;
if ( V_25 > V_38 - 1 )
return;
F_26 ( & V_24 [ V_25 ] , sizeof( V_24 [ 0 ] ) ) ;
V_24 [ V_25 ] . V_35 = V_35 ;
V_24 [ V_25 ] . V_39 = V_15 ;
if ( V_15 != NULL )
V_24 [ V_25 ] . V_40 =
F_31 ( V_15 ) ;
else
V_24 [ V_25 ] . V_40 = 1 ;
va_start ( V_37 , V_36 ) ;
vsnprintf ( V_24 [ V_25 ] . V_33 ,
sizeof( V_24 [ V_25 ] . V_33 ) ,
V_36 , V_37 ) ;
va_end ( V_37 ) ;
if ( ! V_24 [ V_25 ] . V_40 )
memcpy ( V_24 [ V_25 ] . V_33 , L_7 , 3 ) ;
V_23 [ V_25 ] = F_32 (
V_24 [ V_25 ] . V_33 ,
V_24 [ V_25 ] . V_33 ) ;
F_33 ( V_23 [ V_25 ] ,
& V_24 [ V_25 ] ) ;
V_25 ++ ;
V_23 [ V_25 ] = NULL ;
}
static void F_34 ( const char * V_36 , ... )
{
T_2 V_37 ;
int V_30 = V_25 - 1 ;
char V_41 [ 256 ] ;
char V_42 [ 256 ] ;
if ( V_30 < 0 )
return;
va_start ( V_37 , V_36 ) ;
vsnprintf ( V_41 , sizeof( V_41 ) , V_36 , V_37 ) ;
va_end ( V_37 ) ;
snprintf ( V_42 , sizeof( V_42 ) , L_8 ,
V_24 [ V_30 ] . V_33 , V_41 ) ;
strncpy ( V_24 [ V_30 ] . V_33 ,
V_42 ,
sizeof( V_24 [ V_30 ] . V_33 ) ) ;
F_25 ( V_23 [ V_30 ] ) ;
V_23 [ V_30 ] = F_32 (
V_24 [ V_30 ] . V_33 ,
V_24 [ V_30 ] . V_33 ) ;
F_33 ( V_23 [ V_30 ] ,
& V_24 [ V_30 ] ) ;
}
static char F_35 ( void )
{
T_3 * V_43 ;
struct V_44 * V_45 ;
V_43 = V_16 ( V_29 ) ;
if ( V_43 == NULL )
return 0 ;
V_45 = (struct V_44 * ) F_36 ( V_43 ) ;
return V_45 -> V_35 ;
}
static int F_37 ( void )
{
return F_28 ( V_16 ( V_29 ) ) ;
}
static void * F_38 ( void )
{
T_3 * V_43 ;
struct V_44 * V_45 ;
V_43 = V_16 ( V_29 ) ;
if ( ! V_43 )
return NULL ;
V_45 = (struct V_44 * ) F_36 ( V_43 ) ;
return V_45 -> V_39 ;
}
static int F_39 ( char V_35 )
{
return F_35 () == V_35 ;
}
static const char * F_40 ( const char * V_46 )
{
int V_47 ;
V_47 = snprintf ( V_48 , sizeof( V_48 ) ,
L_9 , V_46 , V_49 . V_50 -> V_51 ) ;
if ( V_47 >= sizeof( V_48 ) )
V_48 [ sizeof( V_48 ) - 1 ] = '\0' ;
V_47 = snprintf ( V_52 , sizeof( V_52 ) , L_1 , V_46 ) ;
if ( V_47 >= sizeof( V_52 ) )
V_52 [ sizeof( V_52 ) - 1 ] = '\0' ;
return V_48 ;
}
static int F_19 ( void )
{
int V_19 ;
if ( ! F_41 () ) {
V_53 = 1 ;
return 0 ;
}
V_19 = F_10 ( V_5 ,
_ ( L_10
L_11 ) ,
2 ,
L_12 ,
L_13 ) ;
if ( V_19 == V_54 ) {
V_53 = 0 ;
return - 1 ;
}
switch ( V_19 ) {
case 0 :
V_19 = F_42 ( V_52 ) ;
if ( V_19 )
F_10 (
V_5 ,
_ ( L_14
L_15 ) ,
1 ,
L_16 ) ;
break;
default:
F_10 (
V_5 ,
_ ( L_15 ) ,
1 ,
L_16 ) ;
break;
}
V_53 = 1 ;
return 0 ;
}
static void F_17 ( void )
{
struct V_55 * * V_56 ;
struct V_57 V_19 ;
char V_58 [ 100 ] ;
char * V_59 ;
int V_60 ;
V_61:
V_60 = F_43 ( V_5 ,
_ ( L_17 ) ,
_ ( L_18 V_62 L_19
L_20 V_62 L_21 ) ,
L_22 , V_58 , 99 ) ;
switch ( V_60 ) {
case 0 :
break;
case 1 :
F_5 ( V_5 ,
_ ( L_23 ) , V_63 ) ;
goto V_61;
default:
return;
}
V_59 = V_58 ;
if ( strncasecmp ( V_58 , V_62 , strlen ( V_62 ) ) == 0 )
V_59 += strlen ( V_62 ) ;
V_56 = F_44 ( V_59 ) ;
V_19 = F_45 ( V_56 ) ;
free ( V_56 ) ;
F_5 ( V_5 ,
_ ( L_24 ) , F_46 ( & V_19 ) ) ;
F_47 ( & V_19 ) ;
}
static void F_48 ( struct V_15 * V_15 )
{
struct V_55 * V_64 ;
struct V_65 * V_66 ;
struct V_15 * V_67 ;
int type , V_68 , V_69 = 2 ;
T_4 V_70 ;
char V_71 ;
if ( ! V_15 || ( ! V_20 && ! F_31 ( V_15 ) ) )
return;
V_64 = V_15 -> V_64 ;
V_66 = V_15 -> V_50 ;
if ( ! V_64 ) {
if ( V_66 && V_15 != V_72 ) {
const char * V_50 = F_49 ( V_15 ) ;
enum V_73 V_74 ;
V_74 = V_15 -> V_50 ? V_15 -> V_50 -> type : V_75 ;
switch ( V_74 ) {
case V_76 :
V_77 ++ ;
V_50 = _ ( V_50 ) ;
if ( V_78 ) {
F_30 ( V_15 , 'm' ,
L_25 ,
V_15 -> V_79 ? L_26 : L_27 ,
V_80 + 1 , ' ' , V_50 ) ;
} else
F_30 ( V_15 , 'm' ,
L_28 ,
V_80 + 1 ,
' ' , V_50 ) ;
if ( V_78 && V_15 -> V_79 )
goto V_81;
return;
case V_82 :
if ( V_50 ) {
V_77 ++ ;
F_30 ( V_15 , ':' ,
L_29 ,
V_80 + 1 , ' ' ,
_ ( V_50 ) ) ;
}
break;
default:
if ( V_50 ) {
V_77 ++ ;
F_30 ( V_15 , ':' , L_30 ,
V_80 + 1 , ' ' ,
_ ( V_50 ) ) ;
}
}
} else
V_69 = 0 ;
goto V_81;
}
type = F_50 ( V_64 ) ;
if ( F_51 ( V_64 ) ) {
struct V_55 * V_83 = F_52 ( V_64 ) ;
struct V_15 * V_84 = NULL ;
V_77 ++ ;
for ( V_67 = V_15 -> V_85 ; V_67 ; V_67 = V_67 -> V_86 ) {
if ( F_31 ( V_67 ) && V_67 -> V_64 == V_83 )
V_84 = V_67 ;
}
V_70 = F_53 ( V_64 ) ;
if ( F_54 ( V_64 ) ) {
switch ( type ) {
case V_87 :
F_30 ( V_15 , 't' , L_31 ,
V_70 == V_88 ? ' ' : '*' ) ;
break;
case V_89 :
switch ( V_70 ) {
case V_90 :
V_71 = '*' ;
break;
case V_91 :
V_71 = 'M' ;
break;
default:
V_71 = ' ' ;
break;
}
F_30 ( V_15 , 't' , L_32 , V_71 ) ;
break;
}
} else {
F_30 ( V_15 , V_84 ? 't' : ':' , L_33 ) ;
}
F_34 ( L_34 , V_80 + 1 ,
' ' , _ ( F_49 ( V_15 ) ) ) ;
if ( V_70 == V_90 ) {
if ( V_84 ) {
F_34 ( L_35 ,
_ ( F_49 ( V_84 ) ) ) ;
F_34 ( L_36 ) ;
if ( V_84 -> V_85 ) {
V_80 += 2 ;
F_48 ( V_84 ) ;
V_80 -= 2 ;
}
}
return;
}
} else {
if ( V_15 == V_72 ) {
F_30 ( V_15 , ':' ,
L_30 , V_80 + 1 ,
' ' , _ ( F_49 ( V_15 ) ) ) ;
goto V_81;
}
V_77 ++ ;
V_70 = F_53 ( V_64 ) ;
if ( F_55 ( V_64 ) && V_70 == V_90 ) {
F_30 ( V_15 , ':' , L_33 ) ;
} else {
switch ( type ) {
case V_87 :
if ( F_54 ( V_64 ) )
F_30 ( V_15 , 't' , L_31 ,
V_70 == V_88 ? ' ' : '*' ) ;
else
F_30 ( V_15 , 't' , L_37 ,
V_70 == V_88 ? ' ' : '*' ) ;
break;
case V_89 :
switch ( V_70 ) {
case V_90 :
V_71 = '*' ;
break;
case V_91 :
V_71 = 'M' ;
break;
default:
V_71 = ' ' ;
break;
}
if ( F_54 ( V_64 ) ) {
if ( V_64 -> V_92 . V_93 == V_91 )
F_30 ( V_15 ,
't' , L_38 , V_71 ) ;
else
F_30 ( V_15 ,
't' , L_32 , V_71 ) ;
} else
F_30 ( V_15 , 't' , L_37 , V_71 ) ;
break;
default:
V_68 = 2 + strlen ( F_56 ( V_64 ) ) ;
F_30 ( V_15 , 's' , L_39 ,
F_56 ( V_64 ) ) ;
V_68 = V_80 - V_68 + 4 ;
if ( V_68 < 0 )
V_68 = 0 ;
F_34 ( L_40 , V_68 , ' ' ,
_ ( F_49 ( V_15 ) ) ,
( F_57 ( V_64 ) ||
! F_54 ( V_64 ) ) ? L_22 :
_ ( L_41 ) ) ;
goto V_81;
}
}
F_34 ( L_40 , V_80 + 1 , ' ' ,
_ ( F_49 ( V_15 ) ) ,
( F_57 ( V_64 ) || ! F_54 ( V_64 ) ) ?
L_22 : _ ( L_41 ) ) ;
if ( V_15 -> V_50 && V_15 -> V_50 -> type == V_76 ) {
F_34 ( L_36 ) ;
return;
}
}
V_81:
V_80 += V_69 ;
for ( V_67 = V_15 -> V_85 ; V_67 ; V_67 = V_67 -> V_86 )
F_48 ( V_67 ) ;
V_80 -= V_69 ;
}
static void F_58 ( void )
{
F_59 ( V_29 ) ;
F_24 () ;
}
static void F_60 ( int V_94 , int * V_95 )
{
int V_96 ;
F_61 ( V_29 , * V_95 ) ;
V_96 = F_62 ( V_29 ) ;
if ( V_94 < V_96 ||
V_94 >= V_96 + V_97 ) {
V_96 = F_63 ( V_94 - V_97 / 2 , 0 ) ;
if ( V_96 >= F_64 ( V_29 ) - V_97 )
V_96 = F_64 ( V_29 ) - V_97 ;
F_61 ( V_29 , V_96 ) ;
}
F_65 ( V_29 ,
V_23 [ V_94 ] ) ;
* V_95 = V_96 ;
F_66 ( V_29 ) ;
F_67 ( V_5 ) ;
}
static void F_68 ( const char * V_50 , const char * V_98 ,
int V_94 , int * V_95 )
{
int V_99 , V_100 ;
T_5 * V_101 ;
V_18 = V_98 ;
F_69 () ;
( void ) F_2 ( V_5 , V_6 [ V_13 ] ) ;
F_70 ( V_102 , 1 , 0 , V_103 ,
V_48 ,
V_6 [ V_104 ] ) ;
( void ) F_2 ( V_5 , V_6 [ V_105 ] ) ;
F_71 ( V_5 , 0 , 0 ) ;
( void ) F_2 ( V_5 , V_6 [ V_106 ] ) ;
F_3 ( V_5 , 0 , 3 , L_42 , V_50 ) ;
( void ) F_2 ( V_5 , V_6 [ V_13 ] ) ;
F_72 ( V_29 , V_23 ) ;
F_73 ( V_29 , & V_100 , & V_99 ) ;
V_99 = F_74 ( V_99 , V_107 - 2 ) ;
V_100 = V_97 ;
V_101 = F_75 ( V_5 ,
V_100 ,
V_99 ,
2 ,
( V_107 - V_99 ) / 2 ) ;
F_76 ( V_101 , TRUE ) ;
F_77 ( V_29 , V_101 ) ;
F_78 ( V_29 , V_101 ) ;
F_79 ( V_29 , V_100 , 1 ) ;
F_60 ( V_94 , V_95 ) ;
F_79 ( V_29 , V_100 , 1 ) ;
F_1 () ;
F_66 ( V_29 ) ;
F_67 ( V_5 ) ;
}
static void F_80 ( T_1 * V_108 )
{
if ( * V_108 == V_31 )
* V_108 =
V_109 ;
else if ( * V_108 == V_32 )
* V_108 =
V_34 ;
}
static int F_81 ( int V_14 , struct V_110 * V_111 , int * V_112 )
{
char V_113 = ( char ) V_14 ;
int V_114 = 0 ;
* V_112 = - 1 ;
if ( V_14 == '/' || ( V_111 -> V_115 && V_14 == 27 ) ) {
F_82 ( 0 , 0 ) ;
F_83 () ;
F_84 () ;
V_111 -> V_115 = 1 - V_111 -> V_115 ;
F_26 ( V_111 -> V_116 , sizeof( V_111 -> V_116 ) ) ;
V_111 -> V_108 = V_109 ;
return 0 ;
} else if ( ! V_111 -> V_115 )
return 1 ;
if ( isalnum ( V_113 ) || isgraph ( V_113 ) || V_113 == ' ' ) {
V_111 -> V_116 [ strlen ( V_111 -> V_116 ) ] = V_113 ;
V_111 -> V_116 [ strlen ( V_111 -> V_116 ) ] = '\0' ;
F_80 ( & V_111 -> V_108 ) ;
* V_112 = F_27 ( V_111 -> V_116 ,
V_111 -> V_108 ) ;
} else if ( V_14 == V_117 ) {
V_111 -> V_108 = V_31 ;
* V_112 = F_27 ( V_111 -> V_116 ,
V_111 -> V_108 ) ;
} else if ( V_14 == V_118 ) {
V_111 -> V_108 = V_32 ;
* V_112 = F_27 ( V_111 -> V_116 ,
V_111 -> V_108 ) ;
} else if ( V_14 == V_119 || V_14 == 127 ) {
V_111 -> V_116 [ strlen ( V_111 -> V_116 ) - 1 ] = '\0' ;
F_80 ( & V_111 -> V_108 ) ;
} else
V_114 = 1 ;
if ( V_114 ) {
V_111 -> V_115 = 0 ;
F_26 ( V_111 -> V_116 , sizeof( V_111 -> V_116 ) ) ;
F_82 ( 0 , 0 ) ;
F_83 () ;
F_84 () ;
return - 1 ;
}
return 0 ;
}
static void F_85 ( struct V_15 * V_15 )
{
struct V_15 * V_120 = 0 ;
const char * V_50 = F_49 ( V_15 ) ;
struct V_55 * V_64 ;
int V_19 ;
int V_121 = 0 ;
int V_95 = 0 ;
struct V_110 V_110 = {
. V_115 = 0 ,
. V_108 = V_109 ,
. V_116 = L_22 ,
} ;
while ( ! V_53 ) {
F_58 () ;
V_72 = V_15 ;
F_48 ( V_15 ) ;
if ( ! V_77 )
break;
F_68 ( V_50 ? _ ( V_50 ) : _ ( L_43 ) ,
_ ( V_122 ) ,
V_121 , & V_95 ) ;
F_76 ( ( F_86 ( V_29 ) ) , TRUE ) ;
while ( ! V_53 ) {
if ( V_110 . V_115 ) {
F_87 ( 0 , 0 ,
L_44 , V_110 . V_116 ) ;
F_84 () ;
}
F_67 ( V_5 ) ;
V_19 = F_88 ( F_86 ( V_29 ) ) ;
if ( ! V_19 )
break;
if ( F_81 ( V_19 , & V_110 , & V_121 ) == 0 ) {
if ( V_121 != - 1 )
F_60 ( V_121 ,
& V_95 ) ;
continue;
}
if ( F_20 ( & V_19 ,
(struct V_15 * ) F_38 () ) )
break;
switch ( V_19 ) {
case V_117 :
F_89 ( V_29 , V_123 ) ;
break;
case V_118 :
F_89 ( V_29 , V_124 ) ;
break;
case V_125 :
F_89 ( V_29 , V_126 ) ;
break;
case V_127 :
F_89 ( V_29 , V_128 ) ;
break;
case V_129 :
F_89 ( V_29 , V_130 ) ;
break;
case V_131 :
F_89 ( V_29 , V_132 ) ;
break;
case 'h' :
case '?' :
F_7 ( (struct V_15 * ) F_38 () ) ;
break;
}
if ( V_19 == 10 || V_19 == 27 ||
V_19 == 32 || V_19 == 'n' || V_19 == 'y' ||
V_19 == V_21 || V_19 == V_133 ||
V_19 == 'm' )
break;
F_67 ( V_5 ) ;
}
F_67 ( V_5 ) ;
if ( V_19 == 27 || ( V_15 != & V_49 && V_19 == V_21 ) )
break;
V_95 = F_62 ( V_29 ) ;
V_121 = F_37 () ;
if ( ! F_35 () )
continue;
V_120 = (struct V_15 * ) F_38 () ;
if ( ! V_120 || ! F_31 ( V_120 ) )
continue;
V_64 = V_120 -> V_64 ;
switch ( V_19 ) {
case ' ' :
if ( F_39 ( 't' ) )
F_90 ( V_64 ) ;
else if ( F_39 ( 'm' ) )
F_85 ( V_120 ) ;
break;
case V_133 :
case 10 :
switch ( F_35 () ) {
case 'm' :
if ( V_78 )
V_120 -> V_79 =
( void * ) ( long ) ! V_120 -> V_79 ;
else
F_85 ( V_120 ) ;
break;
case 't' :
if ( F_51 ( V_64 ) &&
F_53 ( V_64 ) == V_90 )
F_91 ( V_120 ) ;
else if ( V_120 -> V_50 &&
V_120 -> V_50 -> type == V_76 )
F_85 ( V_120 ) ;
else if ( V_19 == 10 )
F_90 ( V_64 ) ;
break;
case 's' :
F_92 ( V_120 ) ;
break;
}
break;
case 'y' :
if ( F_39 ( 't' ) ) {
if ( F_93 ( V_64 , V_90 ) )
break;
if ( F_93 ( V_64 , V_91 ) )
F_10 ( V_5 , V_134 , 0 ) ;
}
break;
case 'n' :
if ( F_39 ( 't' ) )
F_93 ( V_64 , V_88 ) ;
break;
case 'm' :
if ( F_39 ( 't' ) )
F_93 ( V_64 , V_91 ) ;
break;
}
}
}
static void F_94 ( const char * V_36 , T_2 V_37 )
{
char V_135 [ 1024 ] ;
vsnprintf ( V_135 , sizeof( V_135 ) , V_36 , V_37 ) ;
F_10 ( V_5 , V_135 , 1 , L_16 ) ;
}
static void F_7 ( struct V_15 * V_15 )
{
struct V_57 V_136 ;
if ( ! V_15 )
return;
V_136 = F_95 () ;
F_96 ( V_15 , & V_136 ) ;
F_5 ( V_5 , _ ( F_49 ( V_15 ) ) , F_46 ( & V_136 ) ) ;
F_47 ( & V_136 ) ;
}
static void F_91 ( struct V_15 * V_15 )
{
const char * V_50 = _ ( F_49 ( V_15 ) ) ;
struct V_15 * V_67 = 0 ;
struct V_55 * V_137 ;
int V_94 = 0 ;
int V_95 = 0 ;
int V_19 , V_1 = 0 ;
struct V_110 V_110 = {
. V_115 = 0 ,
. V_108 = V_109 ,
. V_116 = L_22 ,
} ;
V_137 = F_52 ( V_15 -> V_64 ) ;
while ( ! V_53 ) {
F_58 () ;
for ( V_1 = 0 , V_67 = V_15 -> V_85 ; V_67 ; V_67 = V_67 -> V_86 ) {
if ( ! V_20 && ! F_31 ( V_67 ) )
continue;
if ( V_67 -> V_64 == F_52 ( V_15 -> V_64 ) )
F_30 ( V_67 , ':' , L_45 ,
_ ( F_49 ( V_67 ) ) ) ;
else if ( V_67 -> V_64 )
F_30 ( V_67 , ':' , L_46 ,
_ ( F_49 ( V_67 ) ) ) ;
else
F_30 ( V_67 , ':' , L_47 ,
_ ( F_49 ( V_67 ) ) ) ;
if ( V_67 -> V_64 == V_137 ) {
V_95 = F_62 ( V_29 ) ;
V_94 = V_1 ;
}
V_1 ++ ;
}
F_68 ( V_50 ? _ ( V_50 ) : _ ( L_48 ) ,
_ ( V_138 ) ,
V_94 ,
& V_95 ) ;
while ( ! V_53 ) {
if ( V_110 . V_115 ) {
F_87 ( 0 , 0 , L_44 ,
V_110 . V_116 ) ;
F_84 () ;
}
F_67 ( V_5 ) ;
V_19 = F_88 ( F_86 ( V_29 ) ) ;
if ( ! V_19 )
break;
if ( F_81 ( V_19 , & V_110 , & V_94 ) == 0 ) {
if ( V_94 != - 1 )
F_60 ( V_94 ,
& V_95 ) ;
continue;
}
if ( F_20 (
& V_19 ,
(struct V_15 * ) F_38 () ) )
break;
switch ( V_19 ) {
case V_117 :
F_89 ( V_29 , V_123 ) ;
break;
case V_118 :
F_89 ( V_29 , V_124 ) ;
break;
case V_125 :
F_89 ( V_29 , V_126 ) ;
break;
case V_127 :
F_89 ( V_29 , V_128 ) ;
break;
case V_129 :
F_89 ( V_29 , V_130 ) ;
break;
case V_131 :
F_89 ( V_29 , V_132 ) ;
break;
case 'h' :
case '?' :
F_7 ( (struct V_15 * ) F_38 () ) ;
break;
}
if ( V_19 == 10 || V_19 == 27 || V_19 == ' ' ||
V_19 == V_21 ) {
break;
}
F_67 ( V_5 ) ;
}
if ( V_19 == 27 || V_19 == V_21 )
break;
V_67 = F_38 () ;
if ( ! V_67 || ! F_31 ( V_67 ) || ! V_67 -> V_64 )
continue;
switch ( V_19 ) {
case ' ' :
case 10 :
case V_133 :
F_93 ( V_67 -> V_64 , V_90 ) ;
return;
case 'h' :
case '?' :
F_7 ( V_67 ) ;
V_137 = V_67 -> V_64 ;
break;
case V_54 :
return;
}
}
}
static void F_92 ( struct V_15 * V_15 )
{
const char * V_50 = F_49 ( V_15 ) ;
char V_58 [ 256 ] ;
while ( 1 ) {
int V_19 ;
const char * V_139 ;
switch ( F_50 ( V_15 -> V_64 ) ) {
case V_140 :
V_139 = _ ( V_141 ) ;
break;
case V_142 :
V_139 = _ ( V_143 ) ;
break;
case V_144 :
V_139 = _ ( V_145 ) ;
break;
default:
V_139 = _ ( L_49 ) ;
}
V_19 = F_43 ( V_5 ,
V_50 ? _ ( V_50 ) : _ ( L_43 ) ,
V_139 ,
F_56 ( V_15 -> V_64 ) ,
V_58 ,
sizeof( V_58 ) ) ;
switch ( V_19 ) {
case 0 :
if ( F_97 ( V_15 -> V_64 ,
V_58 ) )
return;
F_10 ( V_5 ,
_ ( L_50 ) , 0 ) ;
break;
case 1 :
F_7 ( V_15 ) ;
break;
case V_54 :
return;
}
}
}
static void F_15 ( void )
{
char V_58 [ 256 ] ;
while ( 1 ) {
int V_19 ;
V_19 = F_43 ( V_5 ,
NULL , V_146 ,
V_52 ,
V_58 ,
sizeof( V_58 ) ) ;
switch ( V_19 ) {
case 0 :
if ( ! V_58 [ 0 ] )
return;
if ( ! F_98 ( V_58 ) ) {
F_40 ( V_58 ) ;
F_99 ( 1 ) ;
return;
}
F_10 ( V_5 , _ ( L_51 ) , 0 ) ;
break;
case 1 :
F_5 ( V_5 ,
_ ( L_52 ) ,
V_147 ) ;
break;
case V_54 :
return;
}
}
}
static void F_13 ( void )
{
char V_58 [ 256 ] ;
while ( 1 ) {
int V_19 ;
V_19 = F_43 ( V_5 ,
NULL , V_148 ,
V_52 ,
V_58 ,
sizeof( V_58 ) ) ;
switch ( V_19 ) {
case 0 :
if ( ! V_58 [ 0 ] )
return;
V_19 = F_42 ( V_58 ) ;
if ( ! V_19 ) {
F_40 ( V_58 ) ;
return;
}
F_10 ( V_5 , _ ( L_53
L_54 ) ,
1 , L_16 ) ;
break;
case 1 :
F_5 ( V_5 ,
_ ( L_55 ) ,
V_149 ) ;
break;
case V_54 :
return;
}
}
}
void F_21 ( void )
{
if ( V_5 != NULL )
F_100 ( V_5 ) ;
V_5 = F_101 ( V_8 - 2 , V_103 - 2 , 2 , 1 ) ;
F_76 ( V_5 , TRUE ) ;
V_97 = V_8 - 7 ;
V_107 = V_103 - 6 ;
F_102 ( V_5 ) ;
}
int main ( int V_150 , char * * V_151 )
{
char * V_152 ;
setlocale ( V_153 , L_22 ) ;
F_103 ( V_154 , V_155 ) ;
F_104 ( V_154 ) ;
F_105 ( V_151 [ 1 ] ) ;
F_98 ( NULL ) ;
V_152 = getenv ( L_56 ) ;
if ( V_152 ) {
if ( ! strcasecmp ( V_152 , L_57 ) )
V_78 = 1 ;
}
F_106 () ;
F_107 () ;
F_108 () ;
F_109 () ;
F_76 ( V_102 , TRUE ) ;
F_110 ( 0 ) ;
if ( V_103 < 75 || V_8 < 20 ) {
F_111 () ;
printf ( L_58
L_59 ) ;
return 1 ;
}
F_112 ( V_102 , FALSE ) ;
V_156 = 1 ;
V_29 = F_113 ( V_23 ) ;
F_114 ( V_29 , V_157 ) ;
F_115 ( V_29 , V_158 ) ;
F_115 ( V_29 , V_159 ) ;
F_115 ( V_29 , V_160 ) ;
F_115 ( V_29 , V_161 ) ;
F_116 ( V_29 , L_60 ) ;
F_117 ( V_29 , V_6 [ V_162 ] ) ;
F_118 ( V_29 , V_6 [ V_163 ] ) ;
F_119 ( V_29 , V_6 [ V_164 ] ) ;
F_40 ( F_120 () ) ;
F_21 () ;
if ( F_121 ( F_22 ( 1 ) ) == FALSE ) {
F_5 ( V_5 ,
_ ( L_3 ) ,
_ ( V_165 ) ) ;
}
F_122 ( F_94 ) ;
while ( ! V_53 ) {
F_85 ( & V_49 ) ;
if ( ! V_53 && F_19 () == 0 )
break;
}
F_59 ( V_29 ) ;
F_123 ( V_29 ) ;
F_100 ( V_5 ) ;
F_69 () ;
F_83 () ;
F_111 () ;
return 0 ;
}
