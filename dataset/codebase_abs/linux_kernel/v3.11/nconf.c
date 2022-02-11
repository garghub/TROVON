static void F_1 ( void )
{
int V_1 ;
int V_2 = 1 ;
const int V_3 = 1 ;
int V_4 = F_2 ( V_5 ) ;
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ ) {
( void ) F_3 ( V_7 , V_8 [ V_9 ] ) ;
F_4 ( V_7 , V_4 - 3 , V_2 ,
L_1 ,
V_10 [ V_1 ] . V_11 ) ;
( void ) F_3 ( V_7 , V_8 [ V_12 ] ) ;
V_2 += strlen ( V_10 [ V_1 ] . V_11 ) ;
F_4 ( V_7 , V_4 - 3 ,
V_2 , L_1 ,
V_10 [ V_1 ] . V_13 ) ;
V_2 += strlen ( V_10 [ V_1 ] . V_13 ) + V_3 ;
}
( void ) F_3 ( V_7 , V_8 [ V_14 ] ) ;
}
static void F_5 ( int * V_15 , struct V_16 * V_17 )
{
F_6 ( V_7 ,
_ ( L_2 ) , _ ( V_18 ) ) ;
return;
}
static void F_7 ( int * V_15 , struct V_16 * V_17 )
{
F_8 ( V_17 ) ;
return;
}
static void F_9 ( int * V_15 , struct V_16 * V_17 )
{
F_6 ( V_7 ,
_ ( L_3 ) ,
_ ( V_19 ) ) ;
return;
}
static void F_10 ( int * V_15 , struct V_16 * V_17 )
{
int V_20 = F_11 ( V_7 ,
_ ( L_4 ) ,
2 ,
L_5 ,
L_6 ) ;
if ( V_20 == 0 )
V_21 = 1 ;
else if ( V_20 == 1 )
V_21 = 0 ;
return;
}
static void F_12 ( int * V_15 , struct V_16 * V_17 )
{
* V_15 = V_22 ;
return;
}
static void F_13 ( int * V_15 , struct V_16 * V_17 )
{
F_14 () ;
return;
}
static void F_15 ( int * V_15 , struct V_16 * V_17 )
{
F_16 () ;
return;
}
static void F_17 ( int * V_15 , struct V_16 * V_17 )
{
F_18 () ;
return;
}
static void F_19 ( int * V_15 , struct V_16 * V_17 )
{
F_20 () ;
return;
}
static int F_21 ( int * V_15 , struct V_16 * V_16 )
{
int V_1 ;
if ( * V_15 == V_23 ) {
F_22 () ;
return 1 ;
}
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ ) {
if ( * V_15 == F_23 ( V_10 [ V_1 ] . V_15 ) ||
* V_15 == '0' + V_10 [ V_1 ] . V_15 ) {
V_10 [ V_1 ] . F_24 ( V_15 , V_16 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_25 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_24 [ V_1 ] ; V_1 ++ )
F_26 ( V_24 [ V_1 ] ) ;
F_27 ( V_24 , sizeof( V_24 ) ) ;
F_27 ( V_25 , sizeof( V_25 ) ) ;
V_26 = 0 ;
}
static int F_28 ( const char * V_27 , T_1 V_28 )
{
int V_29 = F_29 ( V_17 ( V_30 ) ) ;
int V_31 ;
if ( V_28 == V_32 )
++ V_29 ;
else if ( V_28 == V_33 )
-- V_29 ;
V_31 = V_29 ;
V_31 = ( V_31 + V_26 ) % V_26 ;
while ( true ) {
char * V_34 = V_25 [ V_31 ] . V_34 ;
if ( F_30 ( V_34 , V_27 ) != 0 )
return V_31 ;
if ( V_28 == V_33 ||
V_28 == V_35 )
-- V_31 ;
else
++ V_31 ;
V_31 = ( V_31 + V_26 ) % V_26 ;
if ( V_31 == V_29 )
return - 1 ;
}
}
static void F_31 ( struct V_16 * V_16 , char V_36 , const char * V_37 , ... )
{
T_2 V_38 ;
if ( V_26 > V_39 - 1 )
return;
F_27 ( & V_25 [ V_26 ] , sizeof( V_25 [ 0 ] ) ) ;
V_25 [ V_26 ] . V_36 = V_36 ;
V_25 [ V_26 ] . V_40 = V_16 ;
if ( V_16 != NULL )
V_25 [ V_26 ] . V_41 =
F_32 ( V_16 ) ;
else
V_25 [ V_26 ] . V_41 = 1 ;
va_start ( V_38 , V_37 ) ;
vsnprintf ( V_25 [ V_26 ] . V_34 ,
sizeof( V_25 [ V_26 ] . V_34 ) ,
V_37 , V_38 ) ;
va_end ( V_38 ) ;
if ( ! V_25 [ V_26 ] . V_41 )
memcpy ( V_25 [ V_26 ] . V_34 , L_7 , 3 ) ;
V_24 [ V_26 ] = F_33 (
V_25 [ V_26 ] . V_34 ,
V_25 [ V_26 ] . V_34 ) ;
F_34 ( V_24 [ V_26 ] ,
& V_25 [ V_26 ] ) ;
V_26 ++ ;
V_24 [ V_26 ] = NULL ;
}
static void F_35 ( const char * V_37 , ... )
{
T_2 V_38 ;
int V_31 = V_26 - 1 ;
char V_42 [ 256 ] ;
char V_43 [ 256 ] ;
if ( V_31 < 0 )
return;
va_start ( V_38 , V_37 ) ;
vsnprintf ( V_42 , sizeof( V_42 ) , V_37 , V_38 ) ;
va_end ( V_38 ) ;
snprintf ( V_43 , sizeof( V_43 ) , L_8 ,
V_25 [ V_31 ] . V_34 , V_42 ) ;
strncpy ( V_25 [ V_31 ] . V_34 ,
V_43 ,
sizeof( V_25 [ V_31 ] . V_34 ) ) ;
F_26 ( V_24 [ V_31 ] ) ;
V_24 [ V_31 ] = F_33 (
V_25 [ V_31 ] . V_34 ,
V_25 [ V_31 ] . V_34 ) ;
F_34 ( V_24 [ V_31 ] ,
& V_25 [ V_31 ] ) ;
}
static char F_36 ( void )
{
T_3 * V_44 ;
struct V_45 * V_46 ;
V_44 = V_17 ( V_30 ) ;
if ( V_44 == NULL )
return 0 ;
V_46 = (struct V_45 * ) F_37 ( V_44 ) ;
return V_46 -> V_36 ;
}
static int F_38 ( void )
{
return F_29 ( V_17 ( V_30 ) ) ;
}
static void * F_39 ( void )
{
T_3 * V_44 ;
struct V_45 * V_46 ;
V_44 = V_17 ( V_30 ) ;
if ( ! V_44 )
return NULL ;
V_46 = (struct V_45 * ) F_37 ( V_44 ) ;
return V_46 -> V_40 ;
}
static int F_40 ( char V_36 )
{
return F_36 () == V_36 ;
}
static const char * F_41 ( const char * V_47 )
{
int V_48 ;
V_48 = snprintf ( V_49 , sizeof( V_49 ) ,
L_9 , V_47 , V_50 . V_51 -> V_52 ) ;
if ( V_48 >= sizeof( V_49 ) )
V_49 [ sizeof( V_49 ) - 1 ] = '\0' ;
V_48 = snprintf ( V_53 , sizeof( V_53 ) , L_1 , V_47 ) ;
if ( V_48 >= sizeof( V_53 ) )
V_53 [ sizeof( V_53 ) - 1 ] = '\0' ;
return V_49 ;
}
static int F_20 ( void )
{
int V_20 ;
if ( ! F_42 () ) {
V_54 = 1 ;
return 0 ;
}
V_20 = F_11 ( V_7 ,
_ ( L_10
L_11 ) ,
2 ,
L_12 ,
L_13 ) ;
if ( V_20 == V_55 ) {
V_54 = 0 ;
return - 1 ;
}
switch ( V_20 ) {
case 0 :
V_20 = F_43 ( V_53 ) ;
if ( V_20 )
F_11 (
V_7 ,
_ ( L_14
L_15 ) ,
1 ,
L_16 ) ;
break;
default:
F_11 (
V_7 ,
_ ( L_15 ) ,
1 ,
L_16 ) ;
break;
}
V_54 = 1 ;
return 0 ;
}
static void F_18 ( void )
{
struct V_56 * * V_57 ;
struct V_58 V_20 ;
struct V_58 V_59 ;
char * V_60 ;
int V_61 ;
V_59 = F_44 () ;
F_45 ( & V_59 , _ ( L_17
L_18 ) , V_62 , V_62 ) ;
V_63:
V_61 = F_46 ( V_7 ,
_ ( L_19 ) ,
F_47 ( & V_59 ) ,
L_20 , & V_64 , & V_65 ) ;
switch ( V_61 ) {
case 0 :
break;
case 1 :
F_6 ( V_7 ,
_ ( L_21 ) , V_66 ) ;
goto V_63;
default:
F_48 ( & V_59 ) ;
return;
}
V_60 = V_64 ;
if ( strncasecmp ( V_64 , V_62 , strlen ( V_62 ) ) == 0 )
V_60 += strlen ( V_62 ) ;
V_57 = F_49 ( V_60 ) ;
V_20 = F_50 ( V_57 , NULL ) ;
free ( V_57 ) ;
F_6 ( V_7 ,
_ ( L_22 ) , F_47 ( & V_20 ) ) ;
F_48 ( & V_20 ) ;
F_48 ( & V_59 ) ;
}
static void F_51 ( struct V_16 * V_16 )
{
struct V_56 * V_67 ;
struct V_68 * V_69 ;
struct V_16 * V_70 ;
int type , V_71 , V_72 = 2 ;
T_4 V_73 ;
char V_74 ;
if ( ! V_16 || ( ! V_21 && ! F_32 ( V_16 ) ) )
return;
V_67 = V_16 -> V_67 ;
V_69 = V_16 -> V_51 ;
if ( ! V_67 ) {
if ( V_69 && V_16 != V_75 ) {
const char * V_51 = F_52 ( V_16 ) ;
enum V_76 V_77 ;
V_77 = V_16 -> V_51 ? V_16 -> V_51 -> type : V_78 ;
switch ( V_77 ) {
case V_79 :
V_80 ++ ;
V_51 = _ ( V_51 ) ;
if ( V_81 ) {
F_31 ( V_16 , 'm' ,
L_23 ,
V_16 -> V_82 ? L_24 : L_25 ,
V_83 + 1 , ' ' , V_51 ) ;
} else
F_31 ( V_16 , 'm' ,
L_26 ,
V_83 + 1 , ' ' , V_51 ,
F_53 ( V_16 ) ? L_27 : L_28 ) ;
if ( V_81 && V_16 -> V_82 )
goto V_84;
return;
case V_85 :
if ( V_51 ) {
V_80 ++ ;
F_31 ( V_16 , ':' ,
L_29 ,
V_83 + 1 , ' ' ,
_ ( V_51 ) ) ;
}
break;
default:
if ( V_51 ) {
V_80 ++ ;
F_31 ( V_16 , ':' , L_30 ,
V_83 + 1 , ' ' ,
_ ( V_51 ) ) ;
}
}
} else
V_72 = 0 ;
goto V_84;
}
type = F_54 ( V_67 ) ;
if ( F_55 ( V_67 ) ) {
struct V_56 * V_86 = F_56 ( V_67 ) ;
struct V_16 * V_87 = NULL ;
V_80 ++ ;
for ( V_70 = V_16 -> V_88 ; V_70 ; V_70 = V_70 -> V_89 ) {
if ( F_32 ( V_70 ) && V_70 -> V_67 == V_86 )
V_87 = V_70 ;
}
V_73 = F_57 ( V_67 ) ;
if ( F_58 ( V_67 ) ) {
switch ( type ) {
case V_90 :
F_31 ( V_16 , 't' , L_31 ,
V_73 == V_91 ? ' ' : '*' ) ;
break;
case V_92 :
switch ( V_73 ) {
case V_93 :
V_74 = '*' ;
break;
case V_94 :
V_74 = 'M' ;
break;
default:
V_74 = ' ' ;
break;
}
F_31 ( V_16 , 't' , L_32 , V_74 ) ;
break;
}
} else {
F_31 ( V_16 , V_87 ? 't' : ':' , L_33 ) ;
}
F_35 ( L_34 , V_83 + 1 ,
' ' , _ ( F_52 ( V_16 ) ) ) ;
if ( V_73 == V_93 ) {
if ( V_87 ) {
F_35 ( L_35 ,
_ ( F_52 ( V_87 ) ) ) ;
F_35 ( L_36 ) ;
if ( V_87 -> V_88 ) {
V_83 += 2 ;
F_51 ( V_87 ) ;
V_83 -= 2 ;
}
}
return;
}
} else {
if ( V_16 == V_75 ) {
F_31 ( V_16 , ':' ,
L_30 , V_83 + 1 ,
' ' , _ ( F_52 ( V_16 ) ) ) ;
goto V_84;
}
V_80 ++ ;
V_73 = F_57 ( V_67 ) ;
if ( F_59 ( V_67 ) && V_73 == V_93 ) {
F_31 ( V_16 , ':' , L_33 ) ;
} else {
switch ( type ) {
case V_90 :
if ( F_58 ( V_67 ) )
F_31 ( V_16 , 't' , L_31 ,
V_73 == V_91 ? ' ' : '*' ) ;
else
F_31 ( V_16 , 't' , L_37 ,
V_73 == V_91 ? ' ' : '*' ) ;
break;
case V_92 :
switch ( V_73 ) {
case V_93 :
V_74 = '*' ;
break;
case V_94 :
V_74 = 'M' ;
break;
default:
V_74 = ' ' ;
break;
}
if ( F_58 ( V_67 ) ) {
if ( V_67 -> V_95 . V_96 == V_94 )
F_31 ( V_16 ,
't' , L_38 , V_74 ) ;
else
F_31 ( V_16 ,
't' , L_32 , V_74 ) ;
} else
F_31 ( V_16 , 't' , L_37 , V_74 ) ;
break;
default:
V_71 = 2 + strlen ( F_60 ( V_67 ) ) ;
F_31 ( V_16 , 's' , L_39 ,
F_60 ( V_67 ) ) ;
V_71 = V_83 - V_71 + 4 ;
if ( V_71 < 0 )
V_71 = 0 ;
F_35 ( L_40 , V_71 , ' ' ,
_ ( F_52 ( V_16 ) ) ,
( F_61 ( V_67 ) ||
! F_58 ( V_67 ) ) ? L_20 :
_ ( L_41 ) ) ;
goto V_84;
}
}
F_35 ( L_40 , V_83 + 1 , ' ' ,
_ ( F_52 ( V_16 ) ) ,
( F_61 ( V_67 ) || ! F_58 ( V_67 ) ) ?
L_20 : _ ( L_41 ) ) ;
if ( V_16 -> V_51 && V_16 -> V_51 -> type == V_79 ) {
F_35 ( L_42 , F_53 ( V_16 ) ? L_27 : L_28 ) ;
return;
}
}
V_84:
V_83 += V_72 ;
for ( V_70 = V_16 -> V_88 ; V_70 ; V_70 = V_70 -> V_89 )
F_51 ( V_70 ) ;
V_83 -= V_72 ;
}
static void F_62 ( void )
{
F_63 ( V_30 ) ;
F_25 () ;
}
static void F_64 ( int V_97 , int * V_98 )
{
int V_99 ;
F_65 ( V_30 , * V_98 ) ;
V_99 = F_66 ( V_30 ) ;
if ( V_97 < V_99 ||
V_97 >= V_99 + V_100 ) {
V_99 = F_67 ( V_97 - V_100 / 2 , 0 ) ;
if ( V_99 >= F_68 ( V_30 ) - V_100 )
V_99 = F_68 ( V_30 ) - V_100 ;
F_65 ( V_30 , V_99 ) ;
}
F_69 ( V_30 ,
V_24 [ V_97 ] ) ;
* V_98 = V_99 ;
F_70 ( V_30 ) ;
F_71 ( V_7 ) ;
}
static void F_72 ( const char * V_51 , const char * V_101 ,
int V_97 , int * V_98 )
{
int V_102 , V_103 ;
T_5 * V_104 ;
V_19 = V_101 ;
F_73 () ;
( void ) F_3 ( V_7 , V_8 [ V_14 ] ) ;
F_74 ( V_5 , 1 , 0 , F_75 ( V_5 ) ,
V_49 ,
V_8 [ V_105 ] ) ;
( void ) F_3 ( V_7 , V_8 [ V_106 ] ) ;
F_76 ( V_7 , 0 , 0 ) ;
( void ) F_3 ( V_7 , V_8 [ V_107 ] ) ;
F_4 ( V_7 , 0 , 3 , L_43 , V_51 ) ;
( void ) F_3 ( V_7 , V_8 [ V_14 ] ) ;
F_77 ( V_30 , V_24 ) ;
F_78 ( V_30 , & V_103 , & V_102 ) ;
V_102 = F_79 ( V_102 , V_108 - 2 ) ;
V_103 = V_100 ;
V_104 = F_80 ( V_7 ,
V_103 ,
V_102 ,
2 ,
( V_108 - V_102 ) / 2 ) ;
F_81 ( V_104 , TRUE ) ;
F_82 ( V_30 , V_104 ) ;
F_83 ( V_30 , V_104 ) ;
F_84 ( V_30 , V_103 , 1 ) ;
F_64 ( V_97 , V_98 ) ;
F_84 ( V_30 , V_103 , 1 ) ;
F_1 () ;
F_70 ( V_30 ) ;
F_71 ( V_7 ) ;
}
static void F_85 ( T_1 * V_109 )
{
if ( * V_109 == V_32 )
* V_109 =
V_110 ;
else if ( * V_109 == V_33 )
* V_109 =
V_35 ;
}
static int F_86 ( int V_15 , struct V_111 * V_112 , int * V_113 )
{
char V_114 = ( char ) V_15 ;
int V_115 = 0 ;
* V_113 = - 1 ;
if ( V_15 == '/' || ( V_112 -> V_116 && V_15 == 27 ) ) {
F_87 ( 0 , 0 ) ;
F_88 () ;
F_89 () ;
V_112 -> V_116 = 1 - V_112 -> V_116 ;
F_27 ( V_112 -> V_117 , sizeof( V_112 -> V_117 ) ) ;
V_112 -> V_109 = V_110 ;
return 0 ;
} else if ( ! V_112 -> V_116 )
return 1 ;
if ( isalnum ( V_114 ) || isgraph ( V_114 ) || V_114 == ' ' ) {
V_112 -> V_117 [ strlen ( V_112 -> V_117 ) ] = V_114 ;
V_112 -> V_117 [ strlen ( V_112 -> V_117 ) ] = '\0' ;
F_85 ( & V_112 -> V_109 ) ;
* V_113 = F_28 ( V_112 -> V_117 ,
V_112 -> V_109 ) ;
} else if ( V_15 == V_118 ) {
V_112 -> V_109 = V_32 ;
* V_113 = F_28 ( V_112 -> V_117 ,
V_112 -> V_109 ) ;
} else if ( V_15 == V_119 ) {
V_112 -> V_109 = V_33 ;
* V_113 = F_28 ( V_112 -> V_117 ,
V_112 -> V_109 ) ;
} else if ( V_15 == V_120 || V_15 == 127 ) {
V_112 -> V_117 [ strlen ( V_112 -> V_117 ) - 1 ] = '\0' ;
F_85 ( & V_112 -> V_109 ) ;
} else
V_115 = 1 ;
if ( V_115 ) {
V_112 -> V_116 = 0 ;
F_27 ( V_112 -> V_117 , sizeof( V_112 -> V_117 ) ) ;
F_87 ( 0 , 0 ) ;
F_88 () ;
F_89 () ;
return - 1 ;
}
return 0 ;
}
static void F_90 ( struct V_16 * V_16 )
{
struct V_16 * V_121 = 0 ;
const char * V_51 = F_52 ( V_16 ) ;
struct V_56 * V_67 ;
int V_20 ;
int V_122 = 0 ;
int V_98 = 0 ;
struct V_111 V_111 = {
. V_116 = 0 ,
. V_109 = V_110 ,
. V_117 = L_20 ,
} ;
while ( ! V_54 ) {
F_62 () ;
V_75 = V_16 ;
F_51 ( V_16 ) ;
if ( ! V_80 )
break;
F_72 ( V_51 ? _ ( V_51 ) : _ ( L_44 ) ,
_ ( V_123 ) ,
V_122 , & V_98 ) ;
F_81 ( ( F_91 ( V_30 ) ) , TRUE ) ;
while ( ! V_54 ) {
if ( V_111 . V_116 ) {
F_92 ( 0 , 0 ,
L_45 , V_111 . V_117 ) ;
F_89 () ;
}
F_71 ( V_7 ) ;
V_20 = F_93 ( F_91 ( V_30 ) ) ;
if ( ! V_20 )
break;
if ( F_86 ( V_20 , & V_111 , & V_122 ) == 0 ) {
if ( V_122 != - 1 )
F_64 ( V_122 ,
& V_98 ) ;
continue;
}
if ( F_21 ( & V_20 ,
(struct V_16 * ) F_39 () ) )
break;
switch ( V_20 ) {
case V_118 :
F_94 ( V_30 , V_124 ) ;
break;
case V_119 :
F_94 ( V_30 , V_125 ) ;
break;
case V_126 :
F_94 ( V_30 , V_127 ) ;
break;
case V_128 :
F_94 ( V_30 , V_129 ) ;
break;
case V_130 :
F_94 ( V_30 , V_131 ) ;
break;
case V_132 :
F_94 ( V_30 , V_133 ) ;
break;
case 'h' :
case '?' :
F_8 ( (struct V_16 * ) F_39 () ) ;
break;
}
if ( V_20 == 10 || V_20 == 27 ||
V_20 == 32 || V_20 == 'n' || V_20 == 'y' ||
V_20 == V_22 || V_20 == V_134 ||
V_20 == 'm' )
break;
F_71 ( V_7 ) ;
}
F_71 ( V_7 ) ;
if ( V_20 == 27 || ( V_16 != & V_50 && V_20 == V_22 ) )
break;
V_98 = F_66 ( V_30 ) ;
V_122 = F_38 () ;
if ( ! F_36 () )
continue;
V_121 = (struct V_16 * ) F_39 () ;
if ( ! V_121 || ! F_32 ( V_121 ) )
continue;
V_67 = V_121 -> V_67 ;
switch ( V_20 ) {
case ' ' :
if ( F_40 ( 't' ) )
F_95 ( V_67 ) ;
else if ( F_40 ( 'm' ) )
F_90 ( V_121 ) ;
break;
case V_134 :
case 10 :
switch ( F_36 () ) {
case 'm' :
if ( V_81 )
V_121 -> V_82 =
( void * ) ( long ) ! V_121 -> V_82 ;
else
F_90 ( V_121 ) ;
break;
case 't' :
if ( F_55 ( V_67 ) &&
F_57 ( V_67 ) == V_93 )
F_96 ( V_121 ) ;
else if ( V_121 -> V_51 &&
V_121 -> V_51 -> type == V_79 )
F_90 ( V_121 ) ;
else if ( V_20 == 10 )
F_95 ( V_67 ) ;
break;
case 's' :
F_97 ( V_121 ) ;
break;
}
break;
case 'y' :
if ( F_40 ( 't' ) ) {
if ( F_98 ( V_67 , V_93 ) )
break;
if ( F_98 ( V_67 , V_94 ) )
F_11 ( V_7 , V_135 , 0 ) ;
}
break;
case 'n' :
if ( F_40 ( 't' ) )
F_98 ( V_67 , V_91 ) ;
break;
case 'm' :
if ( F_40 ( 't' ) )
F_98 ( V_67 , V_94 ) ;
break;
}
}
}
static void F_99 ( const char * V_37 , T_2 V_38 )
{
char V_136 [ 1024 ] ;
vsnprintf ( V_136 , sizeof( V_136 ) , V_37 , V_38 ) ;
F_11 ( V_7 , V_136 , 1 , L_16 ) ;
}
static void F_8 ( struct V_16 * V_16 )
{
struct V_58 V_137 ;
if ( ! V_16 )
return;
V_137 = F_44 () ;
F_100 ( V_16 , & V_137 ) ;
F_6 ( V_7 , _ ( F_52 ( V_16 ) ) , F_47 ( & V_137 ) ) ;
F_48 ( & V_137 ) ;
}
static void F_96 ( struct V_16 * V_16 )
{
const char * V_51 = _ ( F_52 ( V_16 ) ) ;
struct V_16 * V_70 = 0 ;
struct V_56 * V_138 ;
int V_97 = 0 ;
int V_98 = 0 ;
int V_20 , V_1 = 0 ;
struct V_111 V_111 = {
. V_116 = 0 ,
. V_109 = V_110 ,
. V_117 = L_20 ,
} ;
V_138 = F_56 ( V_16 -> V_67 ) ;
while ( ! V_54 ) {
F_62 () ;
for ( V_1 = 0 , V_70 = V_16 -> V_88 ; V_70 ; V_70 = V_70 -> V_89 ) {
if ( ! V_21 && ! F_32 ( V_70 ) )
continue;
if ( V_70 -> V_67 == F_56 ( V_16 -> V_67 ) )
F_31 ( V_70 , ':' , L_46 ,
_ ( F_52 ( V_70 ) ) ) ;
else if ( V_70 -> V_67 )
F_31 ( V_70 , ':' , L_47 ,
_ ( F_52 ( V_70 ) ) ) ;
else
F_31 ( V_70 , ':' , L_48 ,
_ ( F_52 ( V_70 ) ) ) ;
if ( V_70 -> V_67 == V_138 ) {
V_98 = F_66 ( V_30 ) ;
V_97 = V_1 ;
}
V_1 ++ ;
}
F_72 ( V_51 ? _ ( V_51 ) : _ ( L_49 ) ,
_ ( V_139 ) ,
V_97 ,
& V_98 ) ;
while ( ! V_54 ) {
if ( V_111 . V_116 ) {
F_92 ( 0 , 0 , L_45 ,
V_111 . V_117 ) ;
F_89 () ;
}
F_71 ( V_7 ) ;
V_20 = F_93 ( F_91 ( V_30 ) ) ;
if ( ! V_20 )
break;
if ( F_86 ( V_20 , & V_111 , & V_97 ) == 0 ) {
if ( V_97 != - 1 )
F_64 ( V_97 ,
& V_98 ) ;
continue;
}
if ( F_21 (
& V_20 ,
(struct V_16 * ) F_39 () ) )
break;
switch ( V_20 ) {
case V_118 :
F_94 ( V_30 , V_124 ) ;
break;
case V_119 :
F_94 ( V_30 , V_125 ) ;
break;
case V_126 :
F_94 ( V_30 , V_127 ) ;
break;
case V_128 :
F_94 ( V_30 , V_129 ) ;
break;
case V_130 :
F_94 ( V_30 , V_131 ) ;
break;
case V_132 :
F_94 ( V_30 , V_133 ) ;
break;
case 'h' :
case '?' :
F_8 ( (struct V_16 * ) F_39 () ) ;
break;
}
if ( V_20 == 10 || V_20 == 27 || V_20 == ' ' ||
V_20 == V_22 ) {
break;
}
F_71 ( V_7 ) ;
}
if ( V_20 == 27 || V_20 == V_22 )
break;
V_70 = F_39 () ;
if ( ! V_70 || ! F_32 ( V_70 ) || ! V_70 -> V_67 )
continue;
switch ( V_20 ) {
case ' ' :
case 10 :
case V_134 :
F_98 ( V_70 -> V_67 , V_93 ) ;
return;
case 'h' :
case '?' :
F_8 ( V_70 ) ;
V_138 = V_70 -> V_67 ;
break;
case V_55 :
return;
}
}
}
static void F_97 ( struct V_16 * V_16 )
{
const char * V_51 = F_52 ( V_16 ) ;
while ( 1 ) {
int V_20 ;
const char * V_140 ;
switch ( F_54 ( V_16 -> V_67 ) ) {
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
V_140 = _ ( L_50 ) ;
}
V_20 = F_46 ( V_7 ,
V_51 ? _ ( V_51 ) : _ ( L_44 ) ,
V_140 ,
F_60 ( V_16 -> V_67 ) ,
& V_64 ,
& V_65 ) ;
switch ( V_20 ) {
case 0 :
if ( F_101 ( V_16 -> V_67 ,
V_64 ) )
return;
F_11 ( V_7 ,
_ ( L_51 ) , 0 ) ;
break;
case 1 :
F_8 ( V_16 ) ;
break;
case V_55 :
return;
}
}
}
static void F_16 ( void )
{
while ( 1 ) {
int V_20 ;
V_20 = F_46 ( V_7 ,
NULL , V_147 ,
V_53 ,
& V_64 ,
& V_65 ) ;
switch ( V_20 ) {
case 0 :
if ( ! V_64 [ 0 ] )
return;
if ( ! F_102 ( V_64 ) ) {
F_41 ( V_64 ) ;
F_103 ( 1 ) ;
return;
}
F_11 ( V_7 , _ ( L_52 ) , 0 ) ;
break;
case 1 :
F_6 ( V_7 ,
_ ( L_53 ) ,
V_148 ) ;
break;
case V_55 :
return;
}
}
}
static void F_14 ( void )
{
while ( 1 ) {
int V_20 ;
V_20 = F_46 ( V_7 ,
NULL , V_149 ,
V_53 ,
& V_64 ,
& V_65 ) ;
switch ( V_20 ) {
case 0 :
if ( ! V_64 [ 0 ] )
return;
V_20 = F_43 ( V_64 ) ;
if ( ! V_20 ) {
F_41 ( V_64 ) ;
return;
}
F_11 ( V_7 , _ ( L_54
L_55 ) ,
1 , L_16 ) ;
break;
case 1 :
F_6 ( V_7 ,
_ ( L_56 ) ,
V_150 ) ;
break;
case V_55 :
return;
}
}
}
void F_22 ( void )
{
int V_4 , V_151 ;
F_104 ( V_5 , V_4 , V_151 ) ;
if ( V_7 != NULL )
F_105 ( V_7 ) ;
V_7 = F_106 ( V_4 - 2 , V_151 - 2 , 2 , 1 ) ;
F_81 ( V_7 , TRUE ) ;
V_100 = V_4 - 7 ;
V_108 = V_151 - 6 ;
F_107 ( V_7 ) ;
}
int main ( int V_152 , char * * V_153 )
{
int V_4 , V_151 ;
char * V_154 ;
setlocale ( V_155 , L_20 ) ;
F_108 ( V_156 , V_157 ) ;
F_109 ( V_156 ) ;
F_110 ( V_153 [ 1 ] ) ;
F_102 ( NULL ) ;
V_154 = getenv ( L_57 ) ;
if ( V_154 ) {
if ( ! strcasecmp ( V_154 , L_58 ) )
V_81 = 1 ;
}
F_111 () ;
F_112 () ;
F_113 () ;
F_114 () ;
F_81 ( V_5 , TRUE ) ;
F_115 ( 0 ) ;
F_104 ( V_5 , V_4 , V_151 ) ;
if ( V_151 < 75 || V_4 < 20 ) {
F_116 () ;
printf ( L_59
L_60 ) ;
return 1 ;
}
F_117 ( V_5 , FALSE ) ;
#if V_158
F_118 ( 1 ) ;
#else
V_159 = 1 ;
#endif
V_30 = F_119 ( V_24 ) ;
F_120 ( V_30 , V_160 ) ;
F_121 ( V_30 , V_161 ) ;
F_121 ( V_30 , V_162 ) ;
F_121 ( V_30 , V_163 ) ;
F_121 ( V_30 , V_164 ) ;
F_122 ( V_30 , L_61 ) ;
F_123 ( V_30 , V_8 [ V_165 ] ) ;
F_124 ( V_30 , V_8 [ V_166 ] ) ;
F_125 ( V_30 , V_8 [ V_167 ] ) ;
F_41 ( F_126 () ) ;
F_22 () ;
if ( F_127 ( F_23 ( 1 ) ) == FALSE ) {
F_6 ( V_7 ,
_ ( L_62 ) ,
_ ( V_168 ) ) ;
}
F_128 ( F_99 ) ;
while ( ! V_54 ) {
F_90 ( & V_50 ) ;
if ( ! V_54 && F_20 () == 0 )
break;
}
F_63 ( V_30 ) ;
F_129 ( V_30 ) ;
F_105 ( V_7 ) ;
F_73 () ;
F_88 () ;
F_116 () ;
return 0 ;
}
