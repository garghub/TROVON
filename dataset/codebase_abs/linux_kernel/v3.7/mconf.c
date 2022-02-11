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
static void F_3 ( char * V_9 , T_1 V_10 , T_1 V_11 , void * V_12 )
{
struct V_13 * V_14 = V_12 ;
struct V_15 * V_16 ;
int V_17 = 0 ;
F_4 (pos, data->head, entries) {
if ( V_16 -> V_18 >= V_10 && V_16 -> V_18 < V_11 ) {
char V_19 [ 4 ] ;
if ( V_17 < V_20 ) {
int V_21 = '0' + ( V_16 -> V_22 % V_20 ) + 1 ;
sprintf ( V_19 , L_3 , V_21 ) ;
V_14 -> V_23 [ V_17 ] = V_21 ;
V_14 -> V_24 [ V_17 ] = V_16 -> V_25 ;
V_17 ++ ;
} else {
sprintf ( V_19 , L_4 ) ;
}
memcpy ( V_9 + V_16 -> V_18 , V_19 , sizeof( V_19 ) - 1 ) ;
}
}
V_14 -> V_23 [ V_17 ] = 0 ;
}
static void F_5 ( void )
{
struct V_26 * * V_27 ;
struct V_28 V_29 ;
char * V_30 ;
int V_31 , V_32 = 0 , V_33 = 0 ;
bool V_34 ;
V_34:
F_6 () ;
V_31 = F_7 ( _ ( L_5 ) ,
_ ( L_6 V_35 L_7
L_8 V_35 L_9 ) ,
10 , 75 , L_10 ) ;
switch ( V_31 ) {
case 0 :
break;
case 1 :
F_8 ( _ ( L_11 ) , V_36 ) ;
goto V_34;
default:
return;
}
V_30 = V_37 ;
if ( strncasecmp ( V_37 , V_35 , strlen ( V_35 ) ) == 0 )
V_30 += strlen ( V_35 ) ;
V_27 = F_9 ( V_30 ) ;
do {
F_10 ( V_38 ) ;
struct V_39 * V_24 [ V_20 ] ;
int V_23 [ V_20 + 1 ] , V_40 ;
struct V_13 V_14 = {
. V_38 = & V_38 ,
. V_24 = V_24 ,
. V_23 = V_23 ,
} ;
V_29 = F_11 ( V_27 , & V_38 ) ;
V_31 = F_12 ( _ ( L_12 ) , ( char * )
F_13 ( & V_29 ) , 0 , 0 , V_23 , & V_32 ,
& V_33 , & F_3 , ( void * )
& V_14 ) ;
V_34 = false ;
for ( V_40 = 0 ; V_40 < V_20 && V_23 [ V_40 ] ; V_40 ++ )
if ( V_31 == V_23 [ V_40 ] ) {
F_14 ( V_24 [ V_40 ] -> V_41 , V_24 [ V_40 ] ) ;
V_34 = true ;
}
F_15 ( & V_29 ) ;
} while ( V_34 );
free ( V_27 ) ;
}
static void F_16 ( struct V_39 * V_39 )
{
struct V_26 * V_42 ;
struct V_43 * V_44 ;
struct V_39 * V_45 ;
int type , V_46 , V_47 = 2 ;
T_2 V_48 ;
char V_49 ;
bool V_50 ;
V_50 = F_17 ( V_39 ) ;
if ( V_51 && ! F_18 ( V_39 ) )
return;
else if ( ! V_51 && ! V_50 )
return;
V_42 = V_39 -> V_42 ;
V_44 = V_39 -> V_6 ;
if ( ! V_42 ) {
if ( V_44 && V_39 != V_52 ) {
const char * V_6 = F_19 ( V_39 ) ;
switch ( V_44 -> type ) {
case V_53 :
V_54 ++ ;
V_6 = _ ( V_6 ) ;
if ( V_55 ) {
F_20 ( L_13 ,
V_39 -> V_14 ? L_14 : L_15 ,
V_56 + 1 , ' ' , V_6 ) ;
} else
F_20 ( L_16 , V_56 + 1 , ' ' , V_6 ) ;
F_21 ( 'm' ) ;
F_22 ( V_39 ) ;
if ( V_55 && V_39 -> V_14 )
goto V_57;
return;
case V_58 :
if ( V_6 ) {
V_54 ++ ;
F_20 ( L_17 , V_56 + 1 , ' ' , _ ( V_6 ) ) ;
F_21 ( ':' ) ;
F_22 ( V_39 ) ;
}
break;
default:
if ( V_6 ) {
V_54 ++ ;
F_20 ( L_18 , V_56 + 1 , ' ' , _ ( V_6 ) ) ;
F_21 ( ':' ) ;
F_22 ( V_39 ) ;
}
}
} else
V_47 = 0 ;
goto V_57;
}
type = F_23 ( V_42 ) ;
if ( F_24 ( V_42 ) ) {
struct V_26 * V_59 = F_25 ( V_42 ) ;
struct V_39 * V_60 = NULL ;
V_54 ++ ;
for ( V_45 = V_39 -> V_61 ; V_45 ; V_45 = V_45 -> V_62 ) {
if ( F_17 ( V_45 ) && V_45 -> V_42 == V_59 )
V_60 = V_45 ;
}
V_48 = F_26 ( V_42 ) ;
if ( F_27 ( V_42 ) ) {
switch ( type ) {
case V_63 :
F_20 ( L_19 , V_48 == V_64 ? ' ' : '*' ) ;
break;
case V_65 :
switch ( V_48 ) {
case V_66 : V_49 = '*' ; break;
case V_67 : V_49 = 'M' ; break;
default: V_49 = ' ' ; break;
}
F_20 ( L_20 , V_49 ) ;
break;
}
F_21 ( 't' ) ;
F_22 ( V_39 ) ;
} else {
F_20 ( L_4 ) ;
F_21 ( V_60 ? 't' : ':' ) ;
F_22 ( V_39 ) ;
}
F_28 ( L_21 , V_56 + 1 , ' ' , _ ( F_19 ( V_39 ) ) ) ;
if ( V_48 == V_66 ) {
if ( V_60 ) {
F_28 ( L_22 , _ ( F_19 ( V_60 ) ) ) ;
F_28 ( L_23 ) ;
if ( V_60 -> V_61 ) {
V_56 += 2 ;
F_16 ( V_60 ) ;
V_56 -= 2 ;
}
}
return;
}
} else {
if ( V_39 == V_52 ) {
F_20 ( L_18 , V_56 + 1 , ' ' , _ ( F_19 ( V_39 ) ) ) ;
F_21 ( ':' ) ;
F_22 ( V_39 ) ;
goto V_57;
}
V_54 ++ ;
V_48 = F_26 ( V_42 ) ;
if ( F_29 ( V_42 ) && V_48 == V_66 ) {
F_20 ( L_4 ) ;
F_21 ( ':' ) ;
F_22 ( V_39 ) ;
} else {
switch ( type ) {
case V_63 :
if ( F_27 ( V_42 ) )
F_20 ( L_19 , V_48 == V_64 ? ' ' : '*' ) ;
else
F_20 ( L_24 , V_48 == V_64 ? ' ' : '*' ) ;
F_21 ( 't' ) ;
F_22 ( V_39 ) ;
break;
case V_65 :
switch ( V_48 ) {
case V_66 : V_49 = '*' ; break;
case V_67 : V_49 = 'M' ; break;
default: V_49 = ' ' ; break;
}
if ( F_27 ( V_42 ) ) {
if ( V_42 -> V_68 . V_69 == V_67 )
F_20 ( L_25 , V_49 ) ;
else
F_20 ( L_20 , V_49 ) ;
} else
F_20 ( L_24 , V_49 ) ;
F_21 ( 't' ) ;
F_22 ( V_39 ) ;
break;
default:
V_46 = 2 + strlen ( F_30 ( V_42 ) ) ;
F_20 ( L_26 , F_30 ( V_42 ) ) ;
V_46 = V_56 - V_46 + 4 ;
if ( V_46 < 0 )
V_46 = 0 ;
F_28 ( L_27 , V_46 , ' ' , _ ( F_19 ( V_39 ) ) ,
( F_31 ( V_42 ) || ! F_27 ( V_42 ) ) ?
L_10 : _ ( L_28 ) ) ;
F_21 ( 's' ) ;
F_22 ( V_39 ) ;
goto V_57;
}
}
F_28 ( L_27 , V_56 + 1 , ' ' , _ ( F_19 ( V_39 ) ) ,
( F_31 ( V_42 ) || ! F_27 ( V_42 ) ) ?
L_10 : _ ( L_28 ) ) ;
if ( V_39 -> V_6 -> type == V_53 ) {
F_28 ( L_23 ) ;
return;
}
}
V_57:
V_56 += V_47 ;
for ( V_45 = V_39 -> V_61 ; V_45 ; V_45 = V_45 -> V_62 )
F_16 ( V_45 ) ;
V_56 -= V_47 ;
}
static void F_14 ( struct V_39 * V_39 , struct V_39 * V_70 )
{
struct V_39 * V_71 ;
const char * V_6 = F_19 ( V_39 ) ;
struct V_26 * V_42 ;
int V_29 ;
int V_72 = 0 ;
while ( 1 ) {
F_32 () ;
V_52 = V_39 ;
F_16 ( V_39 ) ;
if ( ! V_54 )
break;
if ( V_39 == & V_5 ) {
F_20 ( L_29 ) ;
F_21 ( ':' ) ;
F_20 ( _ ( L_30 ) ) ;
F_21 ( 'L' ) ;
F_20 ( _ ( L_31 ) ) ;
F_21 ( 'S' ) ;
}
F_6 () ;
V_29 = F_33 ( V_6 ? _ ( V_6 ) : _ ( L_32 ) ,
_ ( V_73 ) ,
V_70 , & V_72 ) ;
if ( V_29 == 1 || V_29 == V_74 || V_29 == - V_75 )
break;
if ( ! F_34 () )
continue;
if ( ! F_35 () )
continue;
V_71 = F_36 () ;
V_70 = F_36 () ;
if ( V_71 )
V_42 = V_71 -> V_42 ;
else
V_42 = NULL ;
switch ( V_29 ) {
case 0 :
switch ( F_35 () ) {
case 'm' :
if ( V_55 )
V_71 -> V_14 = ( void * ) ( long ) ! V_71 -> V_14 ;
else
F_14 ( V_71 , NULL ) ;
break;
case 't' :
if ( F_24 ( V_42 ) && F_26 ( V_42 ) == V_66 )
F_37 ( V_71 ) ;
else if ( V_71 -> V_6 -> type == V_53 )
F_14 ( V_71 , NULL ) ;
break;
case 's' :
F_38 ( V_71 ) ;
break;
case 'L' :
F_39 () ;
break;
case 'S' :
F_40 () ;
break;
}
break;
case 2 :
if ( V_42 )
F_41 ( V_71 ) ;
else
F_8 ( _ ( L_33 ) , _ ( V_76 ) ) ;
break;
case 3 :
if ( F_42 ( 't' ) ) {
if ( F_43 ( V_42 , V_66 ) )
break;
if ( F_43 ( V_42 , V_67 ) )
F_44 ( NULL , V_77 , 6 , 74 ) ;
}
break;
case 4 :
if ( F_42 ( 't' ) )
F_43 ( V_42 , V_64 ) ;
break;
case 5 :
if ( F_42 ( 't' ) )
F_43 ( V_42 , V_67 ) ;
break;
case 6 :
if ( F_42 ( 't' ) )
F_45 ( V_42 ) ;
else if ( F_42 ( 'm' ) )
F_14 ( V_71 , NULL ) ;
break;
case 7 :
F_5 () ;
break;
case 8 :
V_51 = ! V_51 ;
break;
}
}
}
static int F_12 ( const char * V_78 , char * V_7 , int V_79 , int V_80 , int
* V_23 , int * V_32 , int * V_33 , T_3
F_3 , void * V_14 )
{
F_6 () ;
return F_46 ( V_78 , V_7 , V_79 , V_80 , V_23 , V_32 , V_33 ,
F_3 , V_14 ) ;
}
static void F_44 ( const char * V_78 , const char * V_7 , int V_79 , int V_80 )
{
F_12 (title, (char *) text, r, c, (int []) {0}, NULL, NULL,
NULL, NULL) ;
}
static void F_8 ( const char * V_78 , const char * V_7 )
{
F_44 ( V_78 , V_7 , 0 , 0 ) ;
}
static void F_41 ( struct V_39 * V_39 )
{
struct V_28 V_81 = F_47 () ;
V_81 . V_82 = F_48 ( V_83 ) - 10 ;
F_49 ( V_39 , & V_81 ) ;
F_8 ( _ ( F_19 ( V_39 ) ) , F_13 ( & V_81 ) ) ;
F_15 ( & V_81 ) ;
}
static void F_37 ( struct V_39 * V_39 )
{
const char * V_6 = _ ( F_19 ( V_39 ) ) ;
struct V_39 * V_45 ;
struct V_26 * V_84 ;
V_84 = F_25 ( V_39 -> V_42 ) ;
while ( 1 ) {
int V_29 ;
int V_85 ;
F_32 () ;
V_52 = V_39 ;
for ( V_45 = V_39 -> V_61 ; V_45 ; V_45 = V_45 -> V_62 ) {
if ( ! F_17 ( V_45 ) )
continue;
if ( V_45 -> V_42 )
F_20 ( L_2 , _ ( F_19 ( V_45 ) ) ) ;
else {
F_20 ( L_34 , _ ( F_19 ( V_45 ) ) ) ;
F_21 ( ':' ) ;
}
F_22 ( V_45 ) ;
if ( V_45 -> V_42 == V_84 )
F_50 ( 1 ) ;
if ( V_45 -> V_42 == F_25 ( V_39 -> V_42 ) )
F_21 ( 'X' ) ;
}
F_6 () ;
V_29 = F_51 ( V_6 ? _ ( V_6 ) : _ ( L_32 ) ,
_ ( V_86 ) ,
15 , 70 , 6 ) ;
V_85 = F_34 () ;
switch ( V_29 ) {
case 0 :
if ( V_85 ) {
V_45 = F_36 () ;
if ( ! V_45 -> V_42 )
break;
F_43 ( V_45 -> V_42 , V_66 ) ;
}
return;
case 1 :
if ( V_85 ) {
V_45 = F_36 () ;
F_41 ( V_45 ) ;
V_84 = V_45 -> V_42 ;
} else
F_41 ( V_39 ) ;
break;
case V_74 :
return;
case - V_75 :
return;
}
}
}
static void F_38 ( struct V_39 * V_39 )
{
const char * V_6 = F_19 ( V_39 ) ;
while ( 1 ) {
int V_29 ;
const char * V_87 ;
switch ( F_23 ( V_39 -> V_42 ) ) {
case V_88 :
V_87 = _ ( V_89 ) ;
break;
case V_90 :
V_87 = _ ( V_91 ) ;
break;
case V_92 :
V_87 = _ ( V_93 ) ;
break;
default:
V_87 = _ ( L_35 ) ;
}
F_6 () ;
V_29 = F_7 ( V_6 ? _ ( V_6 ) : _ ( L_32 ) ,
V_87 , 10 , 75 ,
F_30 ( V_39 -> V_42 ) ) ;
switch ( V_29 ) {
case 0 :
if ( F_52 ( V_39 -> V_42 , V_37 ) )
return;
F_44 ( NULL , _ ( L_36 ) , 5 , 43 ) ;
break;
case 1 :
F_41 ( V_39 ) ;
break;
case V_74 :
return;
}
}
}
static void F_39 ( void )
{
while ( 1 ) {
int V_29 ;
F_6 () ;
V_29 = F_7 ( NULL , V_94 ,
11 , 55 , V_8 ) ;
switch( V_29 ) {
case 0 :
if ( ! V_37 [ 0 ] )
return;
if ( ! F_53 ( V_37 ) ) {
F_1 ( V_37 ) ;
F_54 ( 1 ) ;
return;
}
F_44 ( NULL , _ ( L_37 ) , 5 , 38 ) ;
break;
case 1 :
F_8 ( _ ( L_38 ) , V_95 ) ;
break;
case V_74 :
return;
}
}
}
static void F_40 ( void )
{
while ( 1 ) {
int V_29 ;
F_6 () ;
V_29 = F_7 ( NULL , V_96 ,
11 , 55 , V_8 ) ;
switch( V_29 ) {
case 0 :
if ( ! V_37 [ 0 ] )
return;
if ( ! F_55 ( V_37 ) ) {
F_1 ( V_37 ) ;
return;
}
F_44 ( NULL , _ ( L_39 ) , 5 , 60 ) ;
break;
case 1 :
F_8 ( _ ( L_40 ) , V_97 ) ;
break;
case V_74 :
return;
}
}
}
static int F_56 ( void )
{
int V_29 ;
F_6 () ;
if ( F_57 () )
V_29 = F_58 ( NULL ,
_ ( L_41
L_42 ) ,
6 , 60 ) ;
else
V_29 = - 1 ;
F_59 ( V_98 , V_99 ) ;
switch ( V_29 ) {
case 0 :
if ( F_55 ( V_8 ) ) {
fprintf ( V_100 , _ ( L_43
L_44
L_45
L_43 ) ) ;
return 1 ;
}
case - 1 :
printf ( _ ( L_43
L_46
L_47
L_43 ) ) ;
V_29 = 0 ;
break;
default:
fprintf ( V_100 , _ ( L_43
L_45
L_43 ) ) ;
if ( V_29 != V_74 )
V_29 = 0 ;
}
return V_29 ;
}
static void F_60 ( int V_101 )
{
exit ( F_56 () ) ;
}
int main ( int V_102 , char * * V_103 )
{
char * V_104 ;
int V_29 ;
setlocale ( V_105 , L_10 ) ;
F_61 ( V_106 , V_107 ) ;
F_62 ( V_106 ) ;
signal ( V_108 , F_60 ) ;
F_63 ( V_103 [ 1 ] ) ;
F_53 ( NULL ) ;
V_104 = getenv ( L_48 ) ;
if ( V_104 ) {
if ( ! strcasecmp ( V_104 , L_49 ) )
V_55 = 1 ;
}
if ( F_64 ( NULL ) ) {
fprintf ( V_100 , F_65 ( L_50 ) ) ;
fprintf ( V_100 , F_65 ( L_51 ) ) ;
return 1 ;
}
F_1 ( F_66 () ) ;
do {
F_14 ( & V_5 , NULL ) ;
V_29 = F_56 () ;
} while ( V_29 == V_74 );
return V_29 ;
}
