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
char * V_58 ;
int V_59 ;
V_60:
V_59 = F_43 ( V_5 ,
_ ( L_17 ) ,
_ ( L_18 V_61 L_19
L_20 V_61 L_21 ) ,
L_22 , & V_62 , & V_63 ) ;
switch ( V_59 ) {
case 0 :
break;
case 1 :
F_5 ( V_5 ,
_ ( L_23 ) , V_64 ) ;
goto V_60;
default:
return;
}
V_58 = V_62 ;
if ( strncasecmp ( V_62 , V_61 , strlen ( V_61 ) ) == 0 )
V_58 += strlen ( V_61 ) ;
V_56 = F_44 ( V_58 ) ;
V_19 = F_45 ( V_56 ) ;
free ( V_56 ) ;
F_5 ( V_5 ,
_ ( L_24 ) , F_46 ( & V_19 ) ) ;
F_47 ( & V_19 ) ;
}
static void F_48 ( struct V_15 * V_15 )
{
struct V_55 * V_65 ;
struct V_66 * V_67 ;
struct V_15 * V_68 ;
int type , V_69 , V_70 = 2 ;
T_4 V_71 ;
char V_72 ;
if ( ! V_15 || ( ! V_20 && ! F_31 ( V_15 ) ) )
return;
V_65 = V_15 -> V_65 ;
V_67 = V_15 -> V_50 ;
if ( ! V_65 ) {
if ( V_67 && V_15 != V_73 ) {
const char * V_50 = F_49 ( V_15 ) ;
enum V_74 V_75 ;
V_75 = V_15 -> V_50 ? V_15 -> V_50 -> type : V_76 ;
switch ( V_75 ) {
case V_77 :
V_78 ++ ;
V_50 = _ ( V_50 ) ;
if ( V_79 ) {
F_30 ( V_15 , 'm' ,
L_25 ,
V_15 -> V_80 ? L_26 : L_27 ,
V_81 + 1 , ' ' , V_50 ) ;
} else
F_30 ( V_15 , 'm' ,
L_28 ,
V_81 + 1 ,
' ' , V_50 ) ;
if ( V_79 && V_15 -> V_80 )
goto V_82;
return;
case V_83 :
if ( V_50 ) {
V_78 ++ ;
F_30 ( V_15 , ':' ,
L_29 ,
V_81 + 1 , ' ' ,
_ ( V_50 ) ) ;
}
break;
default:
if ( V_50 ) {
V_78 ++ ;
F_30 ( V_15 , ':' , L_30 ,
V_81 + 1 , ' ' ,
_ ( V_50 ) ) ;
}
}
} else
V_70 = 0 ;
goto V_82;
}
type = F_50 ( V_65 ) ;
if ( F_51 ( V_65 ) ) {
struct V_55 * V_84 = F_52 ( V_65 ) ;
struct V_15 * V_85 = NULL ;
V_78 ++ ;
for ( V_68 = V_15 -> V_86 ; V_68 ; V_68 = V_68 -> V_87 ) {
if ( F_31 ( V_68 ) && V_68 -> V_65 == V_84 )
V_85 = V_68 ;
}
V_71 = F_53 ( V_65 ) ;
if ( F_54 ( V_65 ) ) {
switch ( type ) {
case V_88 :
F_30 ( V_15 , 't' , L_31 ,
V_71 == V_89 ? ' ' : '*' ) ;
break;
case V_90 :
switch ( V_71 ) {
case V_91 :
V_72 = '*' ;
break;
case V_92 :
V_72 = 'M' ;
break;
default:
V_72 = ' ' ;
break;
}
F_30 ( V_15 , 't' , L_32 , V_72 ) ;
break;
}
} else {
F_30 ( V_15 , V_85 ? 't' : ':' , L_33 ) ;
}
F_34 ( L_34 , V_81 + 1 ,
' ' , _ ( F_49 ( V_15 ) ) ) ;
if ( V_71 == V_91 ) {
if ( V_85 ) {
F_34 ( L_35 ,
_ ( F_49 ( V_85 ) ) ) ;
F_34 ( L_36 ) ;
if ( V_85 -> V_86 ) {
V_81 += 2 ;
F_48 ( V_85 ) ;
V_81 -= 2 ;
}
}
return;
}
} else {
if ( V_15 == V_73 ) {
F_30 ( V_15 , ':' ,
L_30 , V_81 + 1 ,
' ' , _ ( F_49 ( V_15 ) ) ) ;
goto V_82;
}
V_78 ++ ;
V_71 = F_53 ( V_65 ) ;
if ( F_55 ( V_65 ) && V_71 == V_91 ) {
F_30 ( V_15 , ':' , L_33 ) ;
} else {
switch ( type ) {
case V_88 :
if ( F_54 ( V_65 ) )
F_30 ( V_15 , 't' , L_31 ,
V_71 == V_89 ? ' ' : '*' ) ;
else
F_30 ( V_15 , 't' , L_37 ,
V_71 == V_89 ? ' ' : '*' ) ;
break;
case V_90 :
switch ( V_71 ) {
case V_91 :
V_72 = '*' ;
break;
case V_92 :
V_72 = 'M' ;
break;
default:
V_72 = ' ' ;
break;
}
if ( F_54 ( V_65 ) ) {
if ( V_65 -> V_93 . V_94 == V_92 )
F_30 ( V_15 ,
't' , L_38 , V_72 ) ;
else
F_30 ( V_15 ,
't' , L_32 , V_72 ) ;
} else
F_30 ( V_15 , 't' , L_37 , V_72 ) ;
break;
default:
V_69 = 2 + strlen ( F_56 ( V_65 ) ) ;
F_30 ( V_15 , 's' , L_39 ,
F_56 ( V_65 ) ) ;
V_69 = V_81 - V_69 + 4 ;
if ( V_69 < 0 )
V_69 = 0 ;
F_34 ( L_40 , V_69 , ' ' ,
_ ( F_49 ( V_15 ) ) ,
( F_57 ( V_65 ) ||
! F_54 ( V_65 ) ) ? L_22 :
_ ( L_41 ) ) ;
goto V_82;
}
}
F_34 ( L_40 , V_81 + 1 , ' ' ,
_ ( F_49 ( V_15 ) ) ,
( F_57 ( V_65 ) || ! F_54 ( V_65 ) ) ?
L_22 : _ ( L_41 ) ) ;
if ( V_15 -> V_50 && V_15 -> V_50 -> type == V_77 ) {
F_34 ( L_36 ) ;
return;
}
}
V_82:
V_81 += V_70 ;
for ( V_68 = V_15 -> V_86 ; V_68 ; V_68 = V_68 -> V_87 )
F_48 ( V_68 ) ;
V_81 -= V_70 ;
}
static void F_58 ( void )
{
F_59 ( V_29 ) ;
F_24 () ;
}
static void F_60 ( int V_95 , int * V_96 )
{
int V_97 ;
F_61 ( V_29 , * V_96 ) ;
V_97 = F_62 ( V_29 ) ;
if ( V_95 < V_97 ||
V_95 >= V_97 + V_98 ) {
V_97 = F_63 ( V_95 - V_98 / 2 , 0 ) ;
if ( V_97 >= F_64 ( V_29 ) - V_98 )
V_97 = F_64 ( V_29 ) - V_98 ;
F_61 ( V_29 , V_97 ) ;
}
F_65 ( V_29 ,
V_23 [ V_95 ] ) ;
* V_96 = V_97 ;
F_66 ( V_29 ) ;
F_67 ( V_5 ) ;
}
static void F_68 ( const char * V_50 , const char * V_99 ,
int V_95 , int * V_96 )
{
int V_100 , V_101 ;
T_5 * V_102 ;
V_18 = V_99 ;
F_69 () ;
( void ) F_2 ( V_5 , V_6 [ V_13 ] ) ;
F_70 ( V_103 , 1 , 0 , V_104 ,
V_48 ,
V_6 [ V_105 ] ) ;
( void ) F_2 ( V_5 , V_6 [ V_106 ] ) ;
F_71 ( V_5 , 0 , 0 ) ;
( void ) F_2 ( V_5 , V_6 [ V_107 ] ) ;
F_3 ( V_5 , 0 , 3 , L_42 , V_50 ) ;
( void ) F_2 ( V_5 , V_6 [ V_13 ] ) ;
F_72 ( V_29 , V_23 ) ;
F_73 ( V_29 , & V_101 , & V_100 ) ;
V_100 = F_74 ( V_100 , V_108 - 2 ) ;
V_101 = V_98 ;
V_102 = F_75 ( V_5 ,
V_101 ,
V_100 ,
2 ,
( V_108 - V_100 ) / 2 ) ;
F_76 ( V_102 , TRUE ) ;
F_77 ( V_29 , V_102 ) ;
F_78 ( V_29 , V_102 ) ;
F_79 ( V_29 , V_101 , 1 ) ;
F_60 ( V_95 , V_96 ) ;
F_79 ( V_29 , V_101 , 1 ) ;
F_1 () ;
F_66 ( V_29 ) ;
F_67 ( V_5 ) ;
}
static void F_80 ( T_1 * V_109 )
{
if ( * V_109 == V_31 )
* V_109 =
V_110 ;
else if ( * V_109 == V_32 )
* V_109 =
V_34 ;
}
static int F_81 ( int V_14 , struct V_111 * V_112 , int * V_113 )
{
char V_114 = ( char ) V_14 ;
int V_115 = 0 ;
* V_113 = - 1 ;
if ( V_14 == '/' || ( V_112 -> V_116 && V_14 == 27 ) ) {
F_82 ( 0 , 0 ) ;
F_83 () ;
F_84 () ;
V_112 -> V_116 = 1 - V_112 -> V_116 ;
F_26 ( V_112 -> V_117 , sizeof( V_112 -> V_117 ) ) ;
V_112 -> V_109 = V_110 ;
return 0 ;
} else if ( ! V_112 -> V_116 )
return 1 ;
if ( isalnum ( V_114 ) || isgraph ( V_114 ) || V_114 == ' ' ) {
V_112 -> V_117 [ strlen ( V_112 -> V_117 ) ] = V_114 ;
V_112 -> V_117 [ strlen ( V_112 -> V_117 ) ] = '\0' ;
F_80 ( & V_112 -> V_109 ) ;
* V_113 = F_27 ( V_112 -> V_117 ,
V_112 -> V_109 ) ;
} else if ( V_14 == V_118 ) {
V_112 -> V_109 = V_31 ;
* V_113 = F_27 ( V_112 -> V_117 ,
V_112 -> V_109 ) ;
} else if ( V_14 == V_119 ) {
V_112 -> V_109 = V_32 ;
* V_113 = F_27 ( V_112 -> V_117 ,
V_112 -> V_109 ) ;
} else if ( V_14 == V_120 || V_14 == 127 ) {
V_112 -> V_117 [ strlen ( V_112 -> V_117 ) - 1 ] = '\0' ;
F_80 ( & V_112 -> V_109 ) ;
} else
V_115 = 1 ;
if ( V_115 ) {
V_112 -> V_116 = 0 ;
F_26 ( V_112 -> V_117 , sizeof( V_112 -> V_117 ) ) ;
F_82 ( 0 , 0 ) ;
F_83 () ;
F_84 () ;
return - 1 ;
}
return 0 ;
}
static void F_85 ( struct V_15 * V_15 )
{
struct V_15 * V_121 = 0 ;
const char * V_50 = F_49 ( V_15 ) ;
struct V_55 * V_65 ;
int V_19 ;
int V_122 = 0 ;
int V_96 = 0 ;
struct V_111 V_111 = {
. V_116 = 0 ,
. V_109 = V_110 ,
. V_117 = L_22 ,
} ;
while ( ! V_53 ) {
F_58 () ;
V_73 = V_15 ;
F_48 ( V_15 ) ;
if ( ! V_78 )
break;
F_68 ( V_50 ? _ ( V_50 ) : _ ( L_43 ) ,
_ ( V_123 ) ,
V_122 , & V_96 ) ;
F_76 ( ( F_86 ( V_29 ) ) , TRUE ) ;
while ( ! V_53 ) {
if ( V_111 . V_116 ) {
F_87 ( 0 , 0 ,
L_44 , V_111 . V_117 ) ;
F_84 () ;
}
F_67 ( V_5 ) ;
V_19 = F_88 ( F_86 ( V_29 ) ) ;
if ( ! V_19 )
break;
if ( F_81 ( V_19 , & V_111 , & V_122 ) == 0 ) {
if ( V_122 != - 1 )
F_60 ( V_122 ,
& V_96 ) ;
continue;
}
if ( F_20 ( & V_19 ,
(struct V_15 * ) F_38 () ) )
break;
switch ( V_19 ) {
case V_118 :
F_89 ( V_29 , V_124 ) ;
break;
case V_119 :
F_89 ( V_29 , V_125 ) ;
break;
case V_126 :
F_89 ( V_29 , V_127 ) ;
break;
case V_128 :
F_89 ( V_29 , V_129 ) ;
break;
case V_130 :
F_89 ( V_29 , V_131 ) ;
break;
case V_132 :
F_89 ( V_29 , V_133 ) ;
break;
case 'h' :
case '?' :
F_7 ( (struct V_15 * ) F_38 () ) ;
break;
}
if ( V_19 == 10 || V_19 == 27 ||
V_19 == 32 || V_19 == 'n' || V_19 == 'y' ||
V_19 == V_21 || V_19 == V_134 ||
V_19 == 'm' )
break;
F_67 ( V_5 ) ;
}
F_67 ( V_5 ) ;
if ( V_19 == 27 || ( V_15 != & V_49 && V_19 == V_21 ) )
break;
V_96 = F_62 ( V_29 ) ;
V_122 = F_37 () ;
if ( ! F_35 () )
continue;
V_121 = (struct V_15 * ) F_38 () ;
if ( ! V_121 || ! F_31 ( V_121 ) )
continue;
V_65 = V_121 -> V_65 ;
switch ( V_19 ) {
case ' ' :
if ( F_39 ( 't' ) )
F_90 ( V_65 ) ;
else if ( F_39 ( 'm' ) )
F_85 ( V_121 ) ;
break;
case V_134 :
case 10 :
switch ( F_35 () ) {
case 'm' :
if ( V_79 )
V_121 -> V_80 =
( void * ) ( long ) ! V_121 -> V_80 ;
else
F_85 ( V_121 ) ;
break;
case 't' :
if ( F_51 ( V_65 ) &&
F_53 ( V_65 ) == V_91 )
F_91 ( V_121 ) ;
else if ( V_121 -> V_50 &&
V_121 -> V_50 -> type == V_77 )
F_85 ( V_121 ) ;
else if ( V_19 == 10 )
F_90 ( V_65 ) ;
break;
case 's' :
F_92 ( V_121 ) ;
break;
}
break;
case 'y' :
if ( F_39 ( 't' ) ) {
if ( F_93 ( V_65 , V_91 ) )
break;
if ( F_93 ( V_65 , V_92 ) )
F_10 ( V_5 , V_135 , 0 ) ;
}
break;
case 'n' :
if ( F_39 ( 't' ) )
F_93 ( V_65 , V_89 ) ;
break;
case 'm' :
if ( F_39 ( 't' ) )
F_93 ( V_65 , V_92 ) ;
break;
}
}
}
static void F_94 ( const char * V_36 , T_2 V_37 )
{
char V_136 [ 1024 ] ;
vsnprintf ( V_136 , sizeof( V_136 ) , V_36 , V_37 ) ;
F_10 ( V_5 , V_136 , 1 , L_16 ) ;
}
static void F_7 ( struct V_15 * V_15 )
{
struct V_57 V_137 ;
if ( ! V_15 )
return;
V_137 = F_95 () ;
F_96 ( V_15 , & V_137 ) ;
F_5 ( V_5 , _ ( F_49 ( V_15 ) ) , F_46 ( & V_137 ) ) ;
F_47 ( & V_137 ) ;
}
static void F_91 ( struct V_15 * V_15 )
{
const char * V_50 = _ ( F_49 ( V_15 ) ) ;
struct V_15 * V_68 = 0 ;
struct V_55 * V_138 ;
int V_95 = 0 ;
int V_96 = 0 ;
int V_19 , V_1 = 0 ;
struct V_111 V_111 = {
. V_116 = 0 ,
. V_109 = V_110 ,
. V_117 = L_22 ,
} ;
V_138 = F_52 ( V_15 -> V_65 ) ;
while ( ! V_53 ) {
F_58 () ;
for ( V_1 = 0 , V_68 = V_15 -> V_86 ; V_68 ; V_68 = V_68 -> V_87 ) {
if ( ! V_20 && ! F_31 ( V_68 ) )
continue;
if ( V_68 -> V_65 == F_52 ( V_15 -> V_65 ) )
F_30 ( V_68 , ':' , L_45 ,
_ ( F_49 ( V_68 ) ) ) ;
else if ( V_68 -> V_65 )
F_30 ( V_68 , ':' , L_46 ,
_ ( F_49 ( V_68 ) ) ) ;
else
F_30 ( V_68 , ':' , L_47 ,
_ ( F_49 ( V_68 ) ) ) ;
if ( V_68 -> V_65 == V_138 ) {
V_96 = F_62 ( V_29 ) ;
V_95 = V_1 ;
}
V_1 ++ ;
}
F_68 ( V_50 ? _ ( V_50 ) : _ ( L_48 ) ,
_ ( V_139 ) ,
V_95 ,
& V_96 ) ;
while ( ! V_53 ) {
if ( V_111 . V_116 ) {
F_87 ( 0 , 0 , L_44 ,
V_111 . V_117 ) ;
F_84 () ;
}
F_67 ( V_5 ) ;
V_19 = F_88 ( F_86 ( V_29 ) ) ;
if ( ! V_19 )
break;
if ( F_81 ( V_19 , & V_111 , & V_95 ) == 0 ) {
if ( V_95 != - 1 )
F_60 ( V_95 ,
& V_96 ) ;
continue;
}
if ( F_20 (
& V_19 ,
(struct V_15 * ) F_38 () ) )
break;
switch ( V_19 ) {
case V_118 :
F_89 ( V_29 , V_124 ) ;
break;
case V_119 :
F_89 ( V_29 , V_125 ) ;
break;
case V_126 :
F_89 ( V_29 , V_127 ) ;
break;
case V_128 :
F_89 ( V_29 , V_129 ) ;
break;
case V_130 :
F_89 ( V_29 , V_131 ) ;
break;
case V_132 :
F_89 ( V_29 , V_133 ) ;
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
V_68 = F_38 () ;
if ( ! V_68 || ! F_31 ( V_68 ) || ! V_68 -> V_65 )
continue;
switch ( V_19 ) {
case ' ' :
case 10 :
case V_134 :
F_93 ( V_68 -> V_65 , V_91 ) ;
return;
case 'h' :
case '?' :
F_7 ( V_68 ) ;
V_138 = V_68 -> V_65 ;
break;
case V_54 :
return;
}
}
}
static void F_92 ( struct V_15 * V_15 )
{
const char * V_50 = F_49 ( V_15 ) ;
while ( 1 ) {
int V_19 ;
const char * V_140 ;
switch ( F_50 ( V_15 -> V_65 ) ) {
case V_141 :
V_140 = _ ( V_142 ) ;
break;
case V_143 :
V_140 = _ ( V_144 ) ;
break;
case V_145 :
V_140 = _ ( V_146 ) ;
break;
default:
V_140 = _ ( L_49 ) ;
}
V_19 = F_43 ( V_5 ,
V_50 ? _ ( V_50 ) : _ ( L_43 ) ,
V_140 ,
F_56 ( V_15 -> V_65 ) ,
& V_62 ,
& V_63 ) ;
switch ( V_19 ) {
case 0 :
if ( F_97 ( V_15 -> V_65 ,
V_62 ) )
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
while ( 1 ) {
int V_19 ;
V_19 = F_43 ( V_5 ,
NULL , V_147 ,
V_52 ,
& V_62 ,
& V_63 ) ;
switch ( V_19 ) {
case 0 :
if ( ! V_62 [ 0 ] )
return;
if ( ! F_98 ( V_62 ) ) {
F_40 ( V_62 ) ;
F_99 ( 1 ) ;
return;
}
F_10 ( V_5 , _ ( L_51 ) , 0 ) ;
break;
case 1 :
F_5 ( V_5 ,
_ ( L_52 ) ,
V_148 ) ;
break;
case V_54 :
return;
}
}
}
static void F_13 ( void )
{
while ( 1 ) {
int V_19 ;
V_19 = F_43 ( V_5 ,
NULL , V_149 ,
V_52 ,
& V_62 ,
& V_63 ) ;
switch ( V_19 ) {
case 0 :
if ( ! V_62 [ 0 ] )
return;
V_19 = F_42 ( V_62 ) ;
if ( ! V_19 ) {
F_40 ( V_62 ) ;
return;
}
F_10 ( V_5 , _ ( L_53
L_54 ) ,
1 , L_16 ) ;
break;
case 1 :
F_5 ( V_5 ,
_ ( L_55 ) ,
V_150 ) ;
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
V_5 = F_101 ( V_8 - 2 , V_104 - 2 , 2 , 1 ) ;
F_76 ( V_5 , TRUE ) ;
V_98 = V_8 - 7 ;
V_108 = V_104 - 6 ;
F_102 ( V_5 ) ;
}
int main ( int V_151 , char * * V_152 )
{
char * V_153 ;
setlocale ( V_154 , L_22 ) ;
F_103 ( V_155 , V_156 ) ;
F_104 ( V_155 ) ;
F_105 ( V_152 [ 1 ] ) ;
F_98 ( NULL ) ;
V_153 = getenv ( L_56 ) ;
if ( V_153 ) {
if ( ! strcasecmp ( V_153 , L_57 ) )
V_79 = 1 ;
}
F_106 () ;
F_107 () ;
F_108 () ;
F_109 () ;
F_76 ( V_103 , TRUE ) ;
F_110 ( 0 ) ;
if ( V_104 < 75 || V_8 < 20 ) {
F_111 () ;
printf ( L_58
L_59 ) ;
return 1 ;
}
F_112 ( V_103 , FALSE ) ;
V_157 = 1 ;
V_29 = F_113 ( V_23 ) ;
F_114 ( V_29 , V_158 ) ;
F_115 ( V_29 , V_159 ) ;
F_115 ( V_29 , V_160 ) ;
F_115 ( V_29 , V_161 ) ;
F_115 ( V_29 , V_162 ) ;
F_116 ( V_29 , L_60 ) ;
F_117 ( V_29 , V_6 [ V_163 ] ) ;
F_118 ( V_29 , V_6 [ V_164 ] ) ;
F_119 ( V_29 , V_6 [ V_165 ] ) ;
F_40 ( F_120 () ) ;
F_21 () ;
if ( F_121 ( F_22 ( 1 ) ) == FALSE ) {
F_5 ( V_5 ,
_ ( L_3 ) ,
_ ( V_166 ) ) ;
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
