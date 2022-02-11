static void F_1 ( const char * V_1 )
{
static char V_2 [ V_3 + 128 ] ;
int V_4 ;
V_4 = snprintf ( V_2 , sizeof( V_2 ) ,
L_1 , V_1 , V_5 . V_6 -> V_7 ) ;
if ( V_4 >= sizeof( V_2 ) )
V_2 [ sizeof( V_2 ) - 1 ] = '\0' ;
F_2 ( V_2 ) ;
V_4 = snprintf ( V_8 , sizeof( V_8 ) , L_2 , V_1 ) ;
if ( V_4 >= sizeof( V_8 ) )
V_8 [ sizeof( V_8 ) - 1 ] = '\0' ;
}
static void F_3 ( void )
{
struct V_9 * V_10 ;
struct V_11 * V_12 , * V_13 ;
for ( V_12 = V_14 ; V_12 != NULL ; V_12 = V_13 ) {
V_13 = V_12 -> V_15 ;
free ( V_12 ) ;
}
V_14 = NULL ;
F_4 (sp, &trail, entries) {
if ( V_10 -> V_7 ) {
if ( V_12 ) {
V_12 -> V_15 = F_5 ( 1 , sizeof( * V_12 ) ) ;
V_12 = V_12 -> V_15 ;
} else {
V_14 = V_12 = F_5 ( 1 , sizeof( * V_12 ) ) ;
}
V_12 -> V_7 = V_10 -> V_7 ;
}
}
F_6 ( V_14 ) ;
}
static void F_7 ( void )
{
struct V_11 * V_12 , * V_13 ;
for ( V_12 = V_14 ; V_12 != NULL ; V_12 = V_13 ) {
V_13 = V_12 -> V_15 ;
free ( V_12 ) ;
}
V_14 = NULL ;
F_6 ( V_14 ) ;
}
static void F_8 ( char * V_16 , T_1 V_17 , T_1 V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_22 * V_12 ;
int V_23 = 0 ;
F_4 (pos, data->head, entries) {
if ( V_12 -> V_24 >= V_17 && V_12 -> V_24 < V_18 ) {
char V_25 [ 4 ] ;
if ( V_23 < V_26 ) {
int V_27 = '0' + ( V_12 -> V_28 % V_26 ) + 1 ;
sprintf ( V_25 , L_3 , V_27 ) ;
V_21 -> V_29 [ V_23 ] = V_27 ;
V_21 -> V_30 [ V_23 ] = V_12 -> V_31 ;
V_23 ++ ;
} else {
sprintf ( V_25 , L_4 ) ;
}
memcpy ( V_16 + V_12 -> V_24 , V_25 , sizeof( V_25 ) - 1 ) ;
}
}
V_21 -> V_29 [ V_23 ] = 0 ;
}
static void F_9 ( void )
{
struct V_32 * * V_33 ;
struct V_34 V_35 ;
struct V_34 V_36 ;
char * V_37 ;
int V_38 , V_39 = 0 , V_40 = 0 ;
bool V_41 ;
struct V_34 V_42 ;
struct V_9 V_43 ;
V_36 = F_10 () ;
F_11 ( & V_36 , _ ( L_5
L_6 ) , V_44 ) ;
V_41:
F_12 () ;
V_38 = F_13 ( _ ( L_7 ) ,
F_14 ( & V_36 ) ,
10 , 75 , L_8 ) ;
switch ( V_38 ) {
case 0 :
break;
case 1 :
F_15 ( _ ( L_9 ) , V_45 ) ;
goto V_41;
default:
F_16 ( & V_36 ) ;
return;
}
V_37 = V_46 ;
if ( strncasecmp ( V_46 , V_44 , strlen ( V_44 ) ) == 0 )
V_37 += strlen ( V_44 ) ;
V_42 = F_10 () ;
F_11 ( & V_42 , L_10 , V_46 ) ;
V_43 . V_7 = F_14 ( & V_42 ) ;
F_17 ( & V_43 . V_47 , & V_48 ) ;
V_33 = F_18 ( V_37 ) ;
do {
F_19 ( V_49 ) ;
struct V_50 * V_30 [ V_26 ] ;
int V_29 [ V_26 + 1 ] , V_51 ;
struct V_20 V_21 = {
. V_49 = & V_49 ,
. V_30 = V_30 ,
. V_29 = V_29 ,
} ;
struct V_22 * V_12 , * V_13 ;
V_35 = F_20 ( V_33 , & V_49 ) ;
F_3 () ;
V_38 = F_21 ( _ ( L_11 ) , ( char * )
F_14 ( & V_35 ) , 0 , 0 , V_29 , & V_39 ,
& V_40 , & F_8 , ( void * )
& V_21 ) ;
V_41 = false ;
for ( V_51 = 0 ; V_51 < V_26 && V_29 [ V_51 ] ; V_51 ++ )
if ( V_38 == V_29 [ V_51 ] ) {
F_22 ( V_30 [ V_51 ] -> V_52 , V_30 [ V_51 ] ) ;
V_41 = true ;
}
F_16 ( & V_35 ) ;
F_23 (pos, tmp, &head, entries)
free ( V_12 ) ;
} while ( V_41 );
free ( V_33 ) ;
F_16 ( & V_36 ) ;
F_24 ( V_48 . V_53 ) ;
F_16 ( & V_42 ) ;
}
static void F_25 ( struct V_50 * V_50 )
{
struct V_32 * V_54 ;
struct V_55 * V_56 ;
struct V_50 * V_57 ;
int type , V_13 , V_58 = 2 ;
T_2 V_59 ;
char V_60 ;
bool V_61 ;
V_61 = F_26 ( V_50 ) ;
if ( V_62 && ! F_27 ( V_50 ) )
return;
else if ( ! V_62 && ! V_61 )
return;
V_54 = V_50 -> V_54 ;
V_56 = V_50 -> V_6 ;
if ( ! V_54 ) {
if ( V_56 && V_50 != V_63 ) {
const char * V_6 = F_28 ( V_50 ) ;
switch ( V_56 -> type ) {
case V_64 :
V_65 ++ ;
V_6 = _ ( V_6 ) ;
if ( V_66 ) {
F_29 ( L_12 ,
V_50 -> V_21 ? L_13 : L_14 ,
V_67 + 1 , ' ' , V_6 ) ;
} else
F_29 ( L_15 ,
V_67 + 1 , ' ' , V_6 ,
F_30 ( V_50 ) ? L_16 : L_17 ) ;
F_31 ( 'm' ) ;
F_32 ( V_50 ) ;
if ( V_66 && V_50 -> V_21 )
goto V_68;
return;
case V_69 :
if ( V_6 ) {
V_65 ++ ;
F_29 ( L_18 , V_67 + 1 , ' ' , _ ( V_6 ) ) ;
F_31 ( ':' ) ;
F_32 ( V_50 ) ;
}
break;
default:
if ( V_6 ) {
V_65 ++ ;
F_29 ( L_19 , V_67 + 1 , ' ' , _ ( V_6 ) ) ;
F_31 ( ':' ) ;
F_32 ( V_50 ) ;
}
}
} else
V_58 = 0 ;
goto V_68;
}
type = F_33 ( V_54 ) ;
if ( F_34 ( V_54 ) ) {
struct V_32 * V_70 = F_35 ( V_54 ) ;
struct V_50 * V_71 = NULL ;
V_65 ++ ;
for ( V_57 = V_50 -> V_72 ; V_57 ; V_57 = V_57 -> V_15 ) {
if ( F_26 ( V_57 ) && V_57 -> V_54 == V_70 )
V_71 = V_57 ;
}
V_59 = F_36 ( V_54 ) ;
if ( F_37 ( V_54 ) ) {
switch ( type ) {
case V_73 :
F_29 ( L_20 , V_59 == V_74 ? ' ' : '*' ) ;
break;
case V_75 :
switch ( V_59 ) {
case V_76 : V_60 = '*' ; break;
case V_77 : V_60 = 'M' ; break;
default: V_60 = ' ' ; break;
}
F_29 ( L_21 , V_60 ) ;
break;
}
F_31 ( 't' ) ;
F_32 ( V_50 ) ;
} else {
F_29 ( L_4 ) ;
F_31 ( V_71 ? 't' : ':' ) ;
F_32 ( V_50 ) ;
}
F_38 ( L_22 , V_67 + 1 , ' ' , _ ( F_28 ( V_50 ) ) ) ;
if ( V_59 == V_76 ) {
if ( V_71 ) {
F_38 ( L_23 , _ ( F_28 ( V_71 ) ) ) ;
F_38 ( L_24 ) ;
if ( V_71 -> V_72 ) {
V_67 += 2 ;
F_25 ( V_71 ) ;
V_67 -= 2 ;
}
}
return;
}
} else {
if ( V_50 == V_63 ) {
F_29 ( L_19 , V_67 + 1 , ' ' , _ ( F_28 ( V_50 ) ) ) ;
F_31 ( ':' ) ;
F_32 ( V_50 ) ;
goto V_68;
}
V_65 ++ ;
V_59 = F_36 ( V_54 ) ;
if ( F_39 ( V_54 ) && V_59 == V_76 ) {
F_29 ( L_4 ) ;
F_31 ( ':' ) ;
F_32 ( V_50 ) ;
} else {
switch ( type ) {
case V_73 :
if ( F_37 ( V_54 ) )
F_29 ( L_20 , V_59 == V_74 ? ' ' : '*' ) ;
else
F_29 ( L_25 , V_59 == V_74 ? ' ' : '*' ) ;
F_31 ( 't' ) ;
F_32 ( V_50 ) ;
break;
case V_75 :
switch ( V_59 ) {
case V_76 : V_60 = '*' ; break;
case V_77 : V_60 = 'M' ; break;
default: V_60 = ' ' ; break;
}
if ( F_37 ( V_54 ) ) {
if ( V_54 -> V_78 . V_79 == V_77 )
F_29 ( L_26 , V_60 ) ;
else
F_29 ( L_21 , V_60 ) ;
} else
F_29 ( L_25 , V_60 ) ;
F_31 ( 't' ) ;
F_32 ( V_50 ) ;
break;
default:
V_13 = 2 + strlen ( F_40 ( V_54 ) ) ;
F_29 ( L_27 , F_40 ( V_54 ) ) ;
V_13 = V_67 - V_13 + 4 ;
if ( V_13 < 0 )
V_13 = 0 ;
F_38 ( L_28 , V_13 , ' ' , _ ( F_28 ( V_50 ) ) ,
( F_41 ( V_54 ) || ! F_37 ( V_54 ) ) ?
L_8 : _ ( L_29 ) ) ;
F_31 ( 's' ) ;
F_32 ( V_50 ) ;
goto V_68;
}
}
F_38 ( L_28 , V_67 + 1 , ' ' , _ ( F_28 ( V_50 ) ) ,
( F_41 ( V_54 ) || ! F_37 ( V_54 ) ) ?
L_8 : _ ( L_29 ) ) ;
if ( V_50 -> V_6 -> type == V_64 ) {
F_38 ( L_30 , F_30 ( V_50 ) ? L_16 : L_17 ) ;
return;
}
}
V_68:
V_67 += V_58 ;
for ( V_57 = V_50 -> V_72 ; V_57 ; V_57 = V_57 -> V_15 )
F_25 ( V_57 ) ;
V_67 -= V_58 ;
}
static void F_22 ( struct V_50 * V_50 , struct V_50 * V_80 )
{
struct V_50 * V_81 ;
const char * V_6 = F_28 ( V_50 ) ;
struct V_9 V_43 ;
struct V_32 * V_54 ;
int V_35 ;
int V_82 = 0 ;
if ( V_50 != & V_5 )
V_43 . V_7 = F_28 ( V_50 ) ;
else
V_43 . V_7 = NULL ;
F_17 ( & V_43 . V_47 , & V_48 ) ;
while ( 1 ) {
F_42 () ;
V_63 = V_50 ;
F_25 ( V_50 ) ;
if ( ! V_65 )
break;
F_3 () ;
F_12 () ;
V_35 = F_43 ( V_6 ? _ ( V_6 ) : _ ( L_31 ) ,
_ ( V_83 ) ,
V_80 , & V_82 ) ;
if ( V_35 == 1 || V_35 == V_84 || V_35 == - V_85 )
break;
if ( F_44 () != 0 ) {
if ( ! F_45 () )
continue;
if ( ! F_46 () )
continue;
}
V_81 = F_47 () ;
V_80 = F_47 () ;
if ( V_81 )
V_54 = V_81 -> V_54 ;
else
V_54 = NULL ;
switch ( V_35 ) {
case 0 :
switch ( F_46 () ) {
case 'm' :
if ( V_66 )
V_81 -> V_21 = ( void * ) ( long ) ! V_81 -> V_21 ;
else
F_22 ( V_81 , NULL ) ;
break;
case 't' :
if ( F_34 ( V_54 ) && F_36 ( V_54 ) == V_76 )
F_48 ( V_81 ) ;
else if ( V_81 -> V_6 -> type == V_64 )
F_22 ( V_81 , NULL ) ;
break;
case 's' :
F_49 ( V_81 ) ;
break;
}
break;
case 2 :
if ( V_54 )
F_50 ( V_81 ) ;
else {
F_7 () ;
F_15 ( _ ( L_32 ) , _ ( V_86 ) ) ;
}
break;
case 3 :
F_7 () ;
F_51 () ;
break;
case 4 :
F_7 () ;
F_52 () ;
break;
case 5 :
if ( F_53 ( 't' ) ) {
if ( F_54 ( V_54 , V_76 ) )
break;
if ( F_54 ( V_54 , V_77 ) )
F_55 ( NULL , V_87 , 6 , 74 ) ;
}
break;
case 6 :
if ( F_53 ( 't' ) )
F_54 ( V_54 , V_74 ) ;
break;
case 7 :
if ( F_53 ( 't' ) )
F_54 ( V_54 , V_77 ) ;
break;
case 8 :
if ( F_53 ( 't' ) )
F_56 ( V_54 ) ;
else if ( F_53 ( 'm' ) )
F_22 ( V_81 , NULL ) ;
break;
case 9 :
F_9 () ;
break;
case 10 :
V_62 = ! V_62 ;
break;
}
}
F_24 ( V_48 . V_53 ) ;
}
static int F_21 ( const char * V_36 , char * V_7 , int V_88 , int V_89 , int
* V_29 , int * V_39 , int * V_40 , T_3
F_8 , void * V_21 )
{
F_12 () ;
return F_57 ( V_36 , V_7 , V_88 , V_89 , V_29 , V_39 , V_40 ,
F_8 , V_21 ) ;
}
static void F_55 ( const char * V_36 , const char * V_7 , int V_88 , int V_89 )
{
F_21 (title, (char *) text, r, c, (int []) {0}, NULL, NULL,
NULL, NULL) ;
}
static void F_15 ( const char * V_36 , const char * V_7 )
{
F_55 ( V_36 , V_7 , 0 , 0 ) ;
}
static void F_58 ( const char * V_90 , T_4 V_91 )
{
char V_16 [ V_3 + 1 ] ;
vsnprintf ( V_16 , sizeof( V_16 ) , V_90 , V_91 ) ;
if ( V_92 )
printf ( L_2 , V_16 ) ;
else
F_55 ( NULL , V_16 , 6 , 60 ) ;
}
static void F_50 ( struct V_50 * V_50 )
{
struct V_34 V_93 = F_10 () ;
V_93 . V_94 = F_59 ( V_95 ) - 10 ;
F_60 ( V_50 , & V_93 ) ;
F_15 ( _ ( F_28 ( V_50 ) ) , F_14 ( & V_93 ) ) ;
F_16 ( & V_93 ) ;
}
static void F_48 ( struct V_50 * V_50 )
{
const char * V_6 = _ ( F_28 ( V_50 ) ) ;
struct V_50 * V_57 ;
struct V_32 * V_96 ;
V_96 = F_35 ( V_50 -> V_54 ) ;
while ( 1 ) {
int V_35 ;
int V_97 ;
F_42 () ;
V_63 = V_50 ;
for ( V_57 = V_50 -> V_72 ; V_57 ; V_57 = V_57 -> V_15 ) {
if ( ! F_26 ( V_57 ) )
continue;
if ( V_57 -> V_54 )
F_29 ( L_2 , _ ( F_28 ( V_57 ) ) ) ;
else {
F_29 ( L_33 , _ ( F_28 ( V_57 ) ) ) ;
F_31 ( ':' ) ;
}
F_32 ( V_57 ) ;
if ( V_57 -> V_54 == V_96 )
F_61 ( 1 ) ;
if ( V_57 -> V_54 == F_35 ( V_50 -> V_54 ) )
F_31 ( 'X' ) ;
}
F_12 () ;
V_35 = F_62 ( V_6 ? _ ( V_6 ) : _ ( L_31 ) ,
_ ( V_98 ) ,
V_99 ,
V_100 ,
V_101 ) ;
V_97 = F_45 () ;
switch ( V_35 ) {
case 0 :
if ( V_97 ) {
V_57 = F_47 () ;
if ( ! V_57 -> V_54 )
break;
F_54 ( V_57 -> V_54 , V_76 ) ;
}
return;
case 1 :
if ( V_97 ) {
V_57 = F_47 () ;
F_50 ( V_57 ) ;
V_96 = V_57 -> V_54 ;
} else
F_50 ( V_50 ) ;
break;
case V_84 :
return;
case - V_85 :
return;
}
}
}
static void F_49 ( struct V_50 * V_50 )
{
const char * V_6 = F_28 ( V_50 ) ;
while ( 1 ) {
int V_35 ;
const char * V_102 ;
switch ( F_33 ( V_50 -> V_54 ) ) {
case V_103 :
V_102 = _ ( V_104 ) ;
break;
case V_105 :
V_102 = _ ( V_106 ) ;
break;
case V_107 :
V_102 = _ ( V_108 ) ;
break;
default:
V_102 = _ ( L_34 ) ;
}
F_12 () ;
V_35 = F_13 ( V_6 ? _ ( V_6 ) : _ ( L_31 ) ,
V_102 , 10 , 75 ,
F_40 ( V_50 -> V_54 ) ) ;
switch ( V_35 ) {
case 0 :
if ( F_63 ( V_50 -> V_54 , V_46 ) )
return;
F_55 ( NULL , _ ( L_35 ) , 5 , 43 ) ;
break;
case 1 :
F_50 ( V_50 ) ;
break;
case V_84 :
return;
}
}
}
static void F_52 ( void )
{
while ( 1 ) {
int V_35 ;
F_12 () ;
V_35 = F_13 ( NULL , V_109 ,
11 , 55 , V_8 ) ;
switch( V_35 ) {
case 0 :
if ( ! V_46 [ 0 ] )
return;
if ( ! F_64 ( V_46 ) ) {
F_1 ( V_46 ) ;
F_65 ( 1 ) ;
return;
}
F_55 ( NULL , _ ( L_36 ) , 5 , 38 ) ;
break;
case 1 :
F_15 ( _ ( L_37 ) , V_110 ) ;
break;
case V_84 :
return;
}
}
}
static void F_51 ( void )
{
while ( 1 ) {
int V_35 ;
F_12 () ;
V_35 = F_13 ( NULL , V_111 ,
11 , 55 , V_8 ) ;
switch( V_35 ) {
case 0 :
if ( ! V_46 [ 0 ] )
return;
if ( ! F_66 ( V_46 ) ) {
F_1 ( V_46 ) ;
return;
}
F_55 ( NULL , _ ( L_38 ) , 5 , 60 ) ;
break;
case 1 :
F_15 ( _ ( L_39 ) , V_112 ) ;
break;
case V_84 :
return;
}
}
}
static int F_67 ( void )
{
int V_35 ;
V_92 = 1 ;
F_7 () ;
F_12 () ;
if ( F_68 () )
V_35 = F_69 ( NULL ,
_ ( L_40
L_41 ) ,
6 , 60 ) ;
else
V_35 = - 1 ;
F_70 ( V_113 , V_114 ) ;
switch ( V_35 ) {
case 0 :
if ( F_66 ( V_8 ) ) {
fprintf ( V_115 , _ ( L_42
L_43
L_44
L_42 ) ) ;
return 1 ;
}
case - 1 :
printf ( _ ( L_42
L_45
L_46
L_42 ) ) ;
V_35 = 0 ;
break;
default:
fprintf ( V_115 , _ ( L_42
L_44
L_42 ) ) ;
if ( V_35 != V_84 )
V_35 = 0 ;
}
return V_35 ;
}
static void F_71 ( int V_116 )
{
exit ( F_67 () ) ;
}
int main ( int V_117 , char * * V_118 )
{
char * V_119 ;
int V_35 ;
setlocale ( V_120 , L_8 ) ;
F_72 ( V_121 , V_122 ) ;
F_73 ( V_121 ) ;
signal ( V_123 , F_71 ) ;
F_74 ( V_118 [ 1 ] ) ;
F_64 ( NULL ) ;
V_119 = getenv ( L_47 ) ;
if ( V_119 ) {
if ( ! strcasecmp ( V_119 , L_48 ) )
V_66 = 1 ;
}
if ( F_75 ( NULL ) ) {
fprintf ( V_115 , F_76 ( L_49 ) ) ;
fprintf ( V_115 , F_76 ( L_50 ) ) ;
return 1 ;
}
F_1 ( F_77 () ) ;
F_78 ( F_58 ) ;
do {
F_22 ( & V_5 , NULL ) ;
V_35 = F_67 () ;
} while ( V_35 == V_84 );
return V_35 ;
}
