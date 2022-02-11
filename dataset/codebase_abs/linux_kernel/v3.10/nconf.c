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
struct V_57 V_58 ;
char * V_59 ;
int V_60 ;
V_58 = F_43 () ;
F_44 ( & V_58 , _ ( L_17
L_18 ) , V_61 , V_61 ) ;
V_62:
V_60 = F_45 ( V_5 ,
_ ( L_19 ) ,
F_46 ( & V_58 ) ,
L_20 , & V_63 , & V_64 ) ;
switch ( V_60 ) {
case 0 :
break;
case 1 :
F_5 ( V_5 ,
_ ( L_21 ) , V_65 ) ;
goto V_62;
default:
F_47 ( & V_58 ) ;
return;
}
V_59 = V_63 ;
if ( strncasecmp ( V_63 , V_61 , strlen ( V_61 ) ) == 0 )
V_59 += strlen ( V_61 ) ;
V_56 = F_48 ( V_59 ) ;
V_19 = F_49 ( V_56 , NULL ) ;
free ( V_56 ) ;
F_5 ( V_5 ,
_ ( L_22 ) , F_46 ( & V_19 ) ) ;
F_47 ( & V_19 ) ;
F_47 ( & V_58 ) ;
}
static void F_50 ( struct V_15 * V_15 )
{
struct V_55 * V_66 ;
struct V_67 * V_68 ;
struct V_15 * V_69 ;
int type , V_70 , V_71 = 2 ;
T_4 V_72 ;
char V_73 ;
if ( ! V_15 || ( ! V_20 && ! F_31 ( V_15 ) ) )
return;
V_66 = V_15 -> V_66 ;
V_68 = V_15 -> V_50 ;
if ( ! V_66 ) {
if ( V_68 && V_15 != V_74 ) {
const char * V_50 = F_51 ( V_15 ) ;
enum V_75 V_76 ;
V_76 = V_15 -> V_50 ? V_15 -> V_50 -> type : V_77 ;
switch ( V_76 ) {
case V_78 :
V_79 ++ ;
V_50 = _ ( V_50 ) ;
if ( V_80 ) {
F_30 ( V_15 , 'm' ,
L_23 ,
V_15 -> V_81 ? L_24 : L_25 ,
V_82 + 1 , ' ' , V_50 ) ;
} else
F_30 ( V_15 , 'm' ,
L_26 ,
V_82 + 1 ,
' ' , V_50 ) ;
if ( V_80 && V_15 -> V_81 )
goto V_83;
return;
case V_84 :
if ( V_50 ) {
V_79 ++ ;
F_30 ( V_15 , ':' ,
L_27 ,
V_82 + 1 , ' ' ,
_ ( V_50 ) ) ;
}
break;
default:
if ( V_50 ) {
V_79 ++ ;
F_30 ( V_15 , ':' , L_28 ,
V_82 + 1 , ' ' ,
_ ( V_50 ) ) ;
}
}
} else
V_71 = 0 ;
goto V_83;
}
type = F_52 ( V_66 ) ;
if ( F_53 ( V_66 ) ) {
struct V_55 * V_85 = F_54 ( V_66 ) ;
struct V_15 * V_86 = NULL ;
V_79 ++ ;
for ( V_69 = V_15 -> V_87 ; V_69 ; V_69 = V_69 -> V_88 ) {
if ( F_31 ( V_69 ) && V_69 -> V_66 == V_85 )
V_86 = V_69 ;
}
V_72 = F_55 ( V_66 ) ;
if ( F_56 ( V_66 ) ) {
switch ( type ) {
case V_89 :
F_30 ( V_15 , 't' , L_29 ,
V_72 == V_90 ? ' ' : '*' ) ;
break;
case V_91 :
switch ( V_72 ) {
case V_92 :
V_73 = '*' ;
break;
case V_93 :
V_73 = 'M' ;
break;
default:
V_73 = ' ' ;
break;
}
F_30 ( V_15 , 't' , L_30 , V_73 ) ;
break;
}
} else {
F_30 ( V_15 , V_86 ? 't' : ':' , L_31 ) ;
}
F_34 ( L_32 , V_82 + 1 ,
' ' , _ ( F_51 ( V_15 ) ) ) ;
if ( V_72 == V_92 ) {
if ( V_86 ) {
F_34 ( L_33 ,
_ ( F_51 ( V_86 ) ) ) ;
F_34 ( L_34 ) ;
if ( V_86 -> V_87 ) {
V_82 += 2 ;
F_50 ( V_86 ) ;
V_82 -= 2 ;
}
}
return;
}
} else {
if ( V_15 == V_74 ) {
F_30 ( V_15 , ':' ,
L_28 , V_82 + 1 ,
' ' , _ ( F_51 ( V_15 ) ) ) ;
goto V_83;
}
V_79 ++ ;
V_72 = F_55 ( V_66 ) ;
if ( F_57 ( V_66 ) && V_72 == V_92 ) {
F_30 ( V_15 , ':' , L_31 ) ;
} else {
switch ( type ) {
case V_89 :
if ( F_56 ( V_66 ) )
F_30 ( V_15 , 't' , L_29 ,
V_72 == V_90 ? ' ' : '*' ) ;
else
F_30 ( V_15 , 't' , L_35 ,
V_72 == V_90 ? ' ' : '*' ) ;
break;
case V_91 :
switch ( V_72 ) {
case V_92 :
V_73 = '*' ;
break;
case V_93 :
V_73 = 'M' ;
break;
default:
V_73 = ' ' ;
break;
}
if ( F_56 ( V_66 ) ) {
if ( V_66 -> V_94 . V_95 == V_93 )
F_30 ( V_15 ,
't' , L_36 , V_73 ) ;
else
F_30 ( V_15 ,
't' , L_30 , V_73 ) ;
} else
F_30 ( V_15 , 't' , L_35 , V_73 ) ;
break;
default:
V_70 = 2 + strlen ( F_58 ( V_66 ) ) ;
F_30 ( V_15 , 's' , L_37 ,
F_58 ( V_66 ) ) ;
V_70 = V_82 - V_70 + 4 ;
if ( V_70 < 0 )
V_70 = 0 ;
F_34 ( L_38 , V_70 , ' ' ,
_ ( F_51 ( V_15 ) ) ,
( F_59 ( V_66 ) ||
! F_56 ( V_66 ) ) ? L_20 :
_ ( L_39 ) ) ;
goto V_83;
}
}
F_34 ( L_38 , V_82 + 1 , ' ' ,
_ ( F_51 ( V_15 ) ) ,
( F_59 ( V_66 ) || ! F_56 ( V_66 ) ) ?
L_20 : _ ( L_39 ) ) ;
if ( V_15 -> V_50 && V_15 -> V_50 -> type == V_78 ) {
F_34 ( L_34 ) ;
return;
}
}
V_83:
V_82 += V_71 ;
for ( V_69 = V_15 -> V_87 ; V_69 ; V_69 = V_69 -> V_88 )
F_50 ( V_69 ) ;
V_82 -= V_71 ;
}
static void F_60 ( void )
{
F_61 ( V_29 ) ;
F_24 () ;
}
static void F_62 ( int V_96 , int * V_97 )
{
int V_98 ;
F_63 ( V_29 , * V_97 ) ;
V_98 = F_64 ( V_29 ) ;
if ( V_96 < V_98 ||
V_96 >= V_98 + V_99 ) {
V_98 = F_65 ( V_96 - V_99 / 2 , 0 ) ;
if ( V_98 >= F_66 ( V_29 ) - V_99 )
V_98 = F_66 ( V_29 ) - V_99 ;
F_63 ( V_29 , V_98 ) ;
}
F_67 ( V_29 ,
V_23 [ V_96 ] ) ;
* V_97 = V_98 ;
F_68 ( V_29 ) ;
F_69 ( V_5 ) ;
}
static void F_70 ( const char * V_50 , const char * V_100 ,
int V_96 , int * V_97 )
{
int V_101 , V_102 ;
T_5 * V_103 ;
V_18 = V_100 ;
F_71 () ;
( void ) F_2 ( V_5 , V_6 [ V_13 ] ) ;
F_72 ( V_104 , 1 , 0 , V_105 ,
V_48 ,
V_6 [ V_106 ] ) ;
( void ) F_2 ( V_5 , V_6 [ V_107 ] ) ;
F_73 ( V_5 , 0 , 0 ) ;
( void ) F_2 ( V_5 , V_6 [ V_108 ] ) ;
F_3 ( V_5 , 0 , 3 , L_40 , V_50 ) ;
( void ) F_2 ( V_5 , V_6 [ V_13 ] ) ;
F_74 ( V_29 , V_23 ) ;
F_75 ( V_29 , & V_102 , & V_101 ) ;
V_101 = F_76 ( V_101 , V_109 - 2 ) ;
V_102 = V_99 ;
V_103 = F_77 ( V_5 ,
V_102 ,
V_101 ,
2 ,
( V_109 - V_101 ) / 2 ) ;
F_78 ( V_103 , TRUE ) ;
F_79 ( V_29 , V_103 ) ;
F_80 ( V_29 , V_103 ) ;
F_81 ( V_29 , V_102 , 1 ) ;
F_62 ( V_96 , V_97 ) ;
F_81 ( V_29 , V_102 , 1 ) ;
F_1 () ;
F_68 ( V_29 ) ;
F_69 ( V_5 ) ;
}
static void F_82 ( T_1 * V_110 )
{
if ( * V_110 == V_31 )
* V_110 =
V_111 ;
else if ( * V_110 == V_32 )
* V_110 =
V_34 ;
}
static int F_83 ( int V_14 , struct V_112 * V_113 , int * V_114 )
{
char V_115 = ( char ) V_14 ;
int V_116 = 0 ;
* V_114 = - 1 ;
if ( V_14 == '/' || ( V_113 -> V_117 && V_14 == 27 ) ) {
F_84 ( 0 , 0 ) ;
F_85 () ;
F_86 () ;
V_113 -> V_117 = 1 - V_113 -> V_117 ;
F_26 ( V_113 -> V_118 , sizeof( V_113 -> V_118 ) ) ;
V_113 -> V_110 = V_111 ;
return 0 ;
} else if ( ! V_113 -> V_117 )
return 1 ;
if ( isalnum ( V_115 ) || isgraph ( V_115 ) || V_115 == ' ' ) {
V_113 -> V_118 [ strlen ( V_113 -> V_118 ) ] = V_115 ;
V_113 -> V_118 [ strlen ( V_113 -> V_118 ) ] = '\0' ;
F_82 ( & V_113 -> V_110 ) ;
* V_114 = F_27 ( V_113 -> V_118 ,
V_113 -> V_110 ) ;
} else if ( V_14 == V_119 ) {
V_113 -> V_110 = V_31 ;
* V_114 = F_27 ( V_113 -> V_118 ,
V_113 -> V_110 ) ;
} else if ( V_14 == V_120 ) {
V_113 -> V_110 = V_32 ;
* V_114 = F_27 ( V_113 -> V_118 ,
V_113 -> V_110 ) ;
} else if ( V_14 == V_121 || V_14 == 127 ) {
V_113 -> V_118 [ strlen ( V_113 -> V_118 ) - 1 ] = '\0' ;
F_82 ( & V_113 -> V_110 ) ;
} else
V_116 = 1 ;
if ( V_116 ) {
V_113 -> V_117 = 0 ;
F_26 ( V_113 -> V_118 , sizeof( V_113 -> V_118 ) ) ;
F_84 ( 0 , 0 ) ;
F_85 () ;
F_86 () ;
return - 1 ;
}
return 0 ;
}
static void F_87 ( struct V_15 * V_15 )
{
struct V_15 * V_122 = 0 ;
const char * V_50 = F_51 ( V_15 ) ;
struct V_55 * V_66 ;
int V_19 ;
int V_123 = 0 ;
int V_97 = 0 ;
struct V_112 V_112 = {
. V_117 = 0 ,
. V_110 = V_111 ,
. V_118 = L_20 ,
} ;
while ( ! V_53 ) {
F_60 () ;
V_74 = V_15 ;
F_50 ( V_15 ) ;
if ( ! V_79 )
break;
F_70 ( V_50 ? _ ( V_50 ) : _ ( L_41 ) ,
_ ( V_124 ) ,
V_123 , & V_97 ) ;
F_78 ( ( F_88 ( V_29 ) ) , TRUE ) ;
while ( ! V_53 ) {
if ( V_112 . V_117 ) {
F_89 ( 0 , 0 ,
L_42 , V_112 . V_118 ) ;
F_86 () ;
}
F_69 ( V_5 ) ;
V_19 = F_90 ( F_88 ( V_29 ) ) ;
if ( ! V_19 )
break;
if ( F_83 ( V_19 , & V_112 , & V_123 ) == 0 ) {
if ( V_123 != - 1 )
F_62 ( V_123 ,
& V_97 ) ;
continue;
}
if ( F_20 ( & V_19 ,
(struct V_15 * ) F_38 () ) )
break;
switch ( V_19 ) {
case V_119 :
F_91 ( V_29 , V_125 ) ;
break;
case V_120 :
F_91 ( V_29 , V_126 ) ;
break;
case V_127 :
F_91 ( V_29 , V_128 ) ;
break;
case V_129 :
F_91 ( V_29 , V_130 ) ;
break;
case V_131 :
F_91 ( V_29 , V_132 ) ;
break;
case V_133 :
F_91 ( V_29 , V_134 ) ;
break;
case 'h' :
case '?' :
F_7 ( (struct V_15 * ) F_38 () ) ;
break;
}
if ( V_19 == 10 || V_19 == 27 ||
V_19 == 32 || V_19 == 'n' || V_19 == 'y' ||
V_19 == V_21 || V_19 == V_135 ||
V_19 == 'm' )
break;
F_69 ( V_5 ) ;
}
F_69 ( V_5 ) ;
if ( V_19 == 27 || ( V_15 != & V_49 && V_19 == V_21 ) )
break;
V_97 = F_64 ( V_29 ) ;
V_123 = F_37 () ;
if ( ! F_35 () )
continue;
V_122 = (struct V_15 * ) F_38 () ;
if ( ! V_122 || ! F_31 ( V_122 ) )
continue;
V_66 = V_122 -> V_66 ;
switch ( V_19 ) {
case ' ' :
if ( F_39 ( 't' ) )
F_92 ( V_66 ) ;
else if ( F_39 ( 'm' ) )
F_87 ( V_122 ) ;
break;
case V_135 :
case 10 :
switch ( F_35 () ) {
case 'm' :
if ( V_80 )
V_122 -> V_81 =
( void * ) ( long ) ! V_122 -> V_81 ;
else
F_87 ( V_122 ) ;
break;
case 't' :
if ( F_53 ( V_66 ) &&
F_55 ( V_66 ) == V_92 )
F_93 ( V_122 ) ;
else if ( V_122 -> V_50 &&
V_122 -> V_50 -> type == V_78 )
F_87 ( V_122 ) ;
else if ( V_19 == 10 )
F_92 ( V_66 ) ;
break;
case 's' :
F_94 ( V_122 ) ;
break;
}
break;
case 'y' :
if ( F_39 ( 't' ) ) {
if ( F_95 ( V_66 , V_92 ) )
break;
if ( F_95 ( V_66 , V_93 ) )
F_10 ( V_5 , V_136 , 0 ) ;
}
break;
case 'n' :
if ( F_39 ( 't' ) )
F_95 ( V_66 , V_90 ) ;
break;
case 'm' :
if ( F_39 ( 't' ) )
F_95 ( V_66 , V_93 ) ;
break;
}
}
}
static void F_96 ( const char * V_36 , T_2 V_37 )
{
char V_137 [ 1024 ] ;
vsnprintf ( V_137 , sizeof( V_137 ) , V_36 , V_37 ) ;
F_10 ( V_5 , V_137 , 1 , L_16 ) ;
}
static void F_7 ( struct V_15 * V_15 )
{
struct V_57 V_138 ;
if ( ! V_15 )
return;
V_138 = F_43 () ;
F_97 ( V_15 , & V_138 ) ;
F_5 ( V_5 , _ ( F_51 ( V_15 ) ) , F_46 ( & V_138 ) ) ;
F_47 ( & V_138 ) ;
}
static void F_93 ( struct V_15 * V_15 )
{
const char * V_50 = _ ( F_51 ( V_15 ) ) ;
struct V_15 * V_69 = 0 ;
struct V_55 * V_139 ;
int V_96 = 0 ;
int V_97 = 0 ;
int V_19 , V_1 = 0 ;
struct V_112 V_112 = {
. V_117 = 0 ,
. V_110 = V_111 ,
. V_118 = L_20 ,
} ;
V_139 = F_54 ( V_15 -> V_66 ) ;
while ( ! V_53 ) {
F_60 () ;
for ( V_1 = 0 , V_69 = V_15 -> V_87 ; V_69 ; V_69 = V_69 -> V_88 ) {
if ( ! V_20 && ! F_31 ( V_69 ) )
continue;
if ( V_69 -> V_66 == F_54 ( V_15 -> V_66 ) )
F_30 ( V_69 , ':' , L_43 ,
_ ( F_51 ( V_69 ) ) ) ;
else if ( V_69 -> V_66 )
F_30 ( V_69 , ':' , L_44 ,
_ ( F_51 ( V_69 ) ) ) ;
else
F_30 ( V_69 , ':' , L_45 ,
_ ( F_51 ( V_69 ) ) ) ;
if ( V_69 -> V_66 == V_139 ) {
V_97 = F_64 ( V_29 ) ;
V_96 = V_1 ;
}
V_1 ++ ;
}
F_70 ( V_50 ? _ ( V_50 ) : _ ( L_46 ) ,
_ ( V_140 ) ,
V_96 ,
& V_97 ) ;
while ( ! V_53 ) {
if ( V_112 . V_117 ) {
F_89 ( 0 , 0 , L_42 ,
V_112 . V_118 ) ;
F_86 () ;
}
F_69 ( V_5 ) ;
V_19 = F_90 ( F_88 ( V_29 ) ) ;
if ( ! V_19 )
break;
if ( F_83 ( V_19 , & V_112 , & V_96 ) == 0 ) {
if ( V_96 != - 1 )
F_62 ( V_96 ,
& V_97 ) ;
continue;
}
if ( F_20 (
& V_19 ,
(struct V_15 * ) F_38 () ) )
break;
switch ( V_19 ) {
case V_119 :
F_91 ( V_29 , V_125 ) ;
break;
case V_120 :
F_91 ( V_29 , V_126 ) ;
break;
case V_127 :
F_91 ( V_29 , V_128 ) ;
break;
case V_129 :
F_91 ( V_29 , V_130 ) ;
break;
case V_131 :
F_91 ( V_29 , V_132 ) ;
break;
case V_133 :
F_91 ( V_29 , V_134 ) ;
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
F_69 ( V_5 ) ;
}
if ( V_19 == 27 || V_19 == V_21 )
break;
V_69 = F_38 () ;
if ( ! V_69 || ! F_31 ( V_69 ) || ! V_69 -> V_66 )
continue;
switch ( V_19 ) {
case ' ' :
case 10 :
case V_135 :
F_95 ( V_69 -> V_66 , V_92 ) ;
return;
case 'h' :
case '?' :
F_7 ( V_69 ) ;
V_139 = V_69 -> V_66 ;
break;
case V_54 :
return;
}
}
}
static void F_94 ( struct V_15 * V_15 )
{
const char * V_50 = F_51 ( V_15 ) ;
while ( 1 ) {
int V_19 ;
const char * V_141 ;
switch ( F_52 ( V_15 -> V_66 ) ) {
case V_142 :
V_141 = _ ( V_143 ) ;
break;
case V_144 :
V_141 = _ ( V_145 ) ;
break;
case V_146 :
V_141 = _ ( V_147 ) ;
break;
default:
V_141 = _ ( L_47 ) ;
}
V_19 = F_45 ( V_5 ,
V_50 ? _ ( V_50 ) : _ ( L_41 ) ,
V_141 ,
F_58 ( V_15 -> V_66 ) ,
& V_63 ,
& V_64 ) ;
switch ( V_19 ) {
case 0 :
if ( F_98 ( V_15 -> V_66 ,
V_63 ) )
return;
F_10 ( V_5 ,
_ ( L_48 ) , 0 ) ;
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
V_19 = F_45 ( V_5 ,
NULL , V_148 ,
V_52 ,
& V_63 ,
& V_64 ) ;
switch ( V_19 ) {
case 0 :
if ( ! V_63 [ 0 ] )
return;
if ( ! F_99 ( V_63 ) ) {
F_40 ( V_63 ) ;
F_100 ( 1 ) ;
return;
}
F_10 ( V_5 , _ ( L_49 ) , 0 ) ;
break;
case 1 :
F_5 ( V_5 ,
_ ( L_50 ) ,
V_149 ) ;
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
V_19 = F_45 ( V_5 ,
NULL , V_150 ,
V_52 ,
& V_63 ,
& V_64 ) ;
switch ( V_19 ) {
case 0 :
if ( ! V_63 [ 0 ] )
return;
V_19 = F_42 ( V_63 ) ;
if ( ! V_19 ) {
F_40 ( V_63 ) ;
return;
}
F_10 ( V_5 , _ ( L_51
L_52 ) ,
1 , L_16 ) ;
break;
case 1 :
F_5 ( V_5 ,
_ ( L_53 ) ,
V_151 ) ;
break;
case V_54 :
return;
}
}
}
void F_21 ( void )
{
if ( V_5 != NULL )
F_101 ( V_5 ) ;
V_5 = F_102 ( V_8 - 2 , V_105 - 2 , 2 , 1 ) ;
F_78 ( V_5 , TRUE ) ;
V_99 = V_8 - 7 ;
V_109 = V_105 - 6 ;
F_103 ( V_5 ) ;
}
int main ( int V_152 , char * * V_153 )
{
char * V_154 ;
setlocale ( V_155 , L_20 ) ;
F_104 ( V_156 , V_157 ) ;
F_105 ( V_156 ) ;
F_106 ( V_153 [ 1 ] ) ;
F_99 ( NULL ) ;
V_154 = getenv ( L_54 ) ;
if ( V_154 ) {
if ( ! strcasecmp ( V_154 , L_55 ) )
V_80 = 1 ;
}
F_107 () ;
F_108 () ;
F_109 () ;
F_110 () ;
F_78 ( V_104 , TRUE ) ;
F_111 ( 0 ) ;
if ( V_105 < 75 || V_8 < 20 ) {
F_112 () ;
printf ( L_56
L_57 ) ;
return 1 ;
}
F_113 ( V_104 , FALSE ) ;
#if V_158
F_114 ( 1 ) ;
#else
V_159 = 1 ;
#endif
V_29 = F_115 ( V_23 ) ;
F_116 ( V_29 , V_160 ) ;
F_117 ( V_29 , V_161 ) ;
F_117 ( V_29 , V_162 ) ;
F_117 ( V_29 , V_163 ) ;
F_117 ( V_29 , V_164 ) ;
F_118 ( V_29 , L_58 ) ;
F_119 ( V_29 , V_6 [ V_165 ] ) ;
F_120 ( V_29 , V_6 [ V_166 ] ) ;
F_121 ( V_29 , V_6 [ V_167 ] ) ;
F_40 ( F_122 () ) ;
F_21 () ;
if ( F_123 ( F_22 ( 1 ) ) == FALSE ) {
F_5 ( V_5 ,
_ ( L_59 ) ,
_ ( V_168 ) ) ;
}
F_124 ( F_96 ) ;
while ( ! V_53 ) {
F_87 ( & V_49 ) ;
if ( ! V_53 && F_19 () == 0 )
break;
}
F_61 ( V_29 ) ;
F_125 ( V_29 ) ;
F_101 ( V_5 ) ;
F_71 () ;
F_85 () ;
F_112 () ;
return 0 ;
}
