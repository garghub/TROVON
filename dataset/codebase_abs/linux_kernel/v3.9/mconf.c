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
struct V_28 V_30 ;
char * V_31 ;
int V_32 , V_33 = 0 , V_34 = 0 ;
bool V_35 ;
V_30 = F_6 () ;
F_7 ( & V_30 , _ ( L_5
L_6 ) , V_36 , V_36 ) ;
V_35:
F_8 () ;
V_32 = F_9 ( _ ( L_7 ) ,
F_10 ( & V_30 ) ,
10 , 75 , L_8 ) ;
switch ( V_32 ) {
case 0 :
break;
case 1 :
F_11 ( _ ( L_9 ) , V_37 ) ;
goto V_35;
default:
F_12 ( & V_30 ) ;
return;
}
V_31 = V_38 ;
if ( strncasecmp ( V_38 , V_36 , strlen ( V_36 ) ) == 0 )
V_31 += strlen ( V_36 ) ;
V_27 = F_13 ( V_31 ) ;
do {
F_14 ( V_39 ) ;
struct V_40 * V_24 [ V_20 ] ;
int V_23 [ V_20 + 1 ] , V_41 ;
struct V_13 V_14 = {
. V_39 = & V_39 ,
. V_24 = V_24 ,
. V_23 = V_23 ,
} ;
V_29 = F_15 ( V_27 , & V_39 ) ;
V_32 = F_16 ( _ ( L_10 ) , ( char * )
F_10 ( & V_29 ) , 0 , 0 , V_23 , & V_33 ,
& V_34 , & F_3 , ( void * )
& V_14 ) ;
V_35 = false ;
for ( V_41 = 0 ; V_41 < V_20 && V_23 [ V_41 ] ; V_41 ++ )
if ( V_32 == V_23 [ V_41 ] ) {
F_17 ( V_24 [ V_41 ] -> V_42 , V_24 [ V_41 ] ) ;
V_35 = true ;
}
F_12 ( & V_29 ) ;
} while ( V_35 );
free ( V_27 ) ;
F_12 ( & V_30 ) ;
}
static void F_18 ( struct V_40 * V_40 )
{
struct V_26 * V_43 ;
struct V_44 * V_45 ;
struct V_40 * V_46 ;
int type , V_47 , V_48 = 2 ;
T_2 V_49 ;
char V_50 ;
bool V_51 ;
V_51 = F_19 ( V_40 ) ;
if ( V_52 && ! F_20 ( V_40 ) )
return;
else if ( ! V_52 && ! V_51 )
return;
V_43 = V_40 -> V_43 ;
V_45 = V_40 -> V_6 ;
if ( ! V_43 ) {
if ( V_45 && V_40 != V_53 ) {
const char * V_6 = F_21 ( V_40 ) ;
switch ( V_45 -> type ) {
case V_54 :
V_55 ++ ;
V_6 = _ ( V_6 ) ;
if ( V_56 ) {
F_22 ( L_11 ,
V_40 -> V_14 ? L_12 : L_13 ,
V_57 + 1 , ' ' , V_6 ) ;
} else
F_22 ( L_14 , V_57 + 1 , ' ' , V_6 ) ;
F_23 ( 'm' ) ;
F_24 ( V_40 ) ;
if ( V_56 && V_40 -> V_14 )
goto V_58;
return;
case V_59 :
if ( V_6 ) {
V_55 ++ ;
F_22 ( L_15 , V_57 + 1 , ' ' , _ ( V_6 ) ) ;
F_23 ( ':' ) ;
F_24 ( V_40 ) ;
}
break;
default:
if ( V_6 ) {
V_55 ++ ;
F_22 ( L_16 , V_57 + 1 , ' ' , _ ( V_6 ) ) ;
F_23 ( ':' ) ;
F_24 ( V_40 ) ;
}
}
} else
V_48 = 0 ;
goto V_58;
}
type = F_25 ( V_43 ) ;
if ( F_26 ( V_43 ) ) {
struct V_26 * V_60 = F_27 ( V_43 ) ;
struct V_40 * V_61 = NULL ;
V_55 ++ ;
for ( V_46 = V_40 -> V_62 ; V_46 ; V_46 = V_46 -> V_63 ) {
if ( F_19 ( V_46 ) && V_46 -> V_43 == V_60 )
V_61 = V_46 ;
}
V_49 = F_28 ( V_43 ) ;
if ( F_29 ( V_43 ) ) {
switch ( type ) {
case V_64 :
F_22 ( L_17 , V_49 == V_65 ? ' ' : '*' ) ;
break;
case V_66 :
switch ( V_49 ) {
case V_67 : V_50 = '*' ; break;
case V_68 : V_50 = 'M' ; break;
default: V_50 = ' ' ; break;
}
F_22 ( L_18 , V_50 ) ;
break;
}
F_23 ( 't' ) ;
F_24 ( V_40 ) ;
} else {
F_22 ( L_4 ) ;
F_23 ( V_61 ? 't' : ':' ) ;
F_24 ( V_40 ) ;
}
F_30 ( L_19 , V_57 + 1 , ' ' , _ ( F_21 ( V_40 ) ) ) ;
if ( V_49 == V_67 ) {
if ( V_61 ) {
F_30 ( L_20 , _ ( F_21 ( V_61 ) ) ) ;
F_30 ( L_21 ) ;
if ( V_61 -> V_62 ) {
V_57 += 2 ;
F_18 ( V_61 ) ;
V_57 -= 2 ;
}
}
return;
}
} else {
if ( V_40 == V_53 ) {
F_22 ( L_16 , V_57 + 1 , ' ' , _ ( F_21 ( V_40 ) ) ) ;
F_23 ( ':' ) ;
F_24 ( V_40 ) ;
goto V_58;
}
V_55 ++ ;
V_49 = F_28 ( V_43 ) ;
if ( F_31 ( V_43 ) && V_49 == V_67 ) {
F_22 ( L_4 ) ;
F_23 ( ':' ) ;
F_24 ( V_40 ) ;
} else {
switch ( type ) {
case V_64 :
if ( F_29 ( V_43 ) )
F_22 ( L_17 , V_49 == V_65 ? ' ' : '*' ) ;
else
F_22 ( L_22 , V_49 == V_65 ? ' ' : '*' ) ;
F_23 ( 't' ) ;
F_24 ( V_40 ) ;
break;
case V_66 :
switch ( V_49 ) {
case V_67 : V_50 = '*' ; break;
case V_68 : V_50 = 'M' ; break;
default: V_50 = ' ' ; break;
}
if ( F_29 ( V_43 ) ) {
if ( V_43 -> V_69 . V_70 == V_68 )
F_22 ( L_23 , V_50 ) ;
else
F_22 ( L_18 , V_50 ) ;
} else
F_22 ( L_22 , V_50 ) ;
F_23 ( 't' ) ;
F_24 ( V_40 ) ;
break;
default:
V_47 = 2 + strlen ( F_32 ( V_43 ) ) ;
F_22 ( L_24 , F_32 ( V_43 ) ) ;
V_47 = V_57 - V_47 + 4 ;
if ( V_47 < 0 )
V_47 = 0 ;
F_30 ( L_25 , V_47 , ' ' , _ ( F_21 ( V_40 ) ) ,
( F_33 ( V_43 ) || ! F_29 ( V_43 ) ) ?
L_8 : _ ( L_26 ) ) ;
F_23 ( 's' ) ;
F_24 ( V_40 ) ;
goto V_58;
}
}
F_30 ( L_25 , V_57 + 1 , ' ' , _ ( F_21 ( V_40 ) ) ,
( F_33 ( V_43 ) || ! F_29 ( V_43 ) ) ?
L_8 : _ ( L_26 ) ) ;
if ( V_40 -> V_6 -> type == V_54 ) {
F_30 ( L_21 ) ;
return;
}
}
V_58:
V_57 += V_48 ;
for ( V_46 = V_40 -> V_62 ; V_46 ; V_46 = V_46 -> V_63 )
F_18 ( V_46 ) ;
V_57 -= V_48 ;
}
static void F_17 ( struct V_40 * V_40 , struct V_40 * V_71 )
{
struct V_40 * V_72 ;
const char * V_6 = F_21 ( V_40 ) ;
struct V_26 * V_43 ;
int V_29 ;
int V_73 = 0 ;
while ( 1 ) {
F_34 () ;
V_53 = V_40 ;
F_18 ( V_40 ) ;
if ( ! V_55 )
break;
F_8 () ;
V_29 = F_35 ( V_6 ? _ ( V_6 ) : _ ( L_27 ) ,
_ ( V_74 ) ,
V_71 , & V_73 ) ;
if ( V_29 == 1 || V_29 == V_75 || V_29 == - V_76 )
break;
if ( ! F_36 () )
continue;
if ( ! F_37 () )
continue;
V_72 = F_38 () ;
V_71 = F_38 () ;
if ( V_72 )
V_43 = V_72 -> V_43 ;
else
V_43 = NULL ;
switch ( V_29 ) {
case 0 :
switch ( F_37 () ) {
case 'm' :
if ( V_56 )
V_72 -> V_14 = ( void * ) ( long ) ! V_72 -> V_14 ;
else
F_17 ( V_72 , NULL ) ;
break;
case 't' :
if ( F_26 ( V_43 ) && F_28 ( V_43 ) == V_67 )
F_39 ( V_72 ) ;
else if ( V_72 -> V_6 -> type == V_54 )
F_17 ( V_72 , NULL ) ;
break;
case 's' :
F_40 ( V_72 ) ;
break;
}
break;
case 2 :
if ( V_43 )
F_41 ( V_72 ) ;
else
F_11 ( _ ( L_28 ) , _ ( V_77 ) ) ;
break;
case 3 :
F_42 () ;
break;
case 4 :
F_43 () ;
break;
case 5 :
if ( F_44 ( 't' ) ) {
if ( F_45 ( V_43 , V_67 ) )
break;
if ( F_45 ( V_43 , V_68 ) )
F_46 ( NULL , V_78 , 6 , 74 ) ;
}
break;
case 6 :
if ( F_44 ( 't' ) )
F_45 ( V_43 , V_65 ) ;
break;
case 7 :
if ( F_44 ( 't' ) )
F_45 ( V_43 , V_68 ) ;
break;
case 8 :
if ( F_44 ( 't' ) )
F_47 ( V_43 ) ;
else if ( F_44 ( 'm' ) )
F_17 ( V_72 , NULL ) ;
break;
case 9 :
F_5 () ;
break;
case 10 :
V_52 = ! V_52 ;
break;
}
}
}
static int F_16 ( const char * V_30 , char * V_7 , int V_79 , int V_80 , int
* V_23 , int * V_33 , int * V_34 , T_3
F_3 , void * V_14 )
{
F_8 () ;
return F_48 ( V_30 , V_7 , V_79 , V_80 , V_23 , V_33 , V_34 ,
F_3 , V_14 ) ;
}
static void F_46 ( const char * V_30 , const char * V_7 , int V_79 , int V_80 )
{
F_16 (title, (char *) text, r, c, (int []) {0}, NULL, NULL,
NULL, NULL) ;
}
static void F_11 ( const char * V_30 , const char * V_7 )
{
F_46 ( V_30 , V_7 , 0 , 0 ) ;
}
static void F_49 ( const char * V_81 , T_4 V_82 )
{
char V_9 [ V_3 + 1 ] ;
vsnprintf ( V_9 , sizeof( V_9 ) , V_81 , V_82 ) ;
if ( V_83 )
printf ( L_2 , V_9 ) ;
else
F_46 ( NULL , V_9 , 6 , 60 ) ;
}
static void F_41 ( struct V_40 * V_40 )
{
struct V_28 V_84 = F_6 () ;
V_84 . V_85 = F_50 ( V_86 ) - 10 ;
F_51 ( V_40 , & V_84 ) ;
F_11 ( _ ( F_21 ( V_40 ) ) , F_10 ( & V_84 ) ) ;
F_12 ( & V_84 ) ;
}
static void F_39 ( struct V_40 * V_40 )
{
const char * V_6 = _ ( F_21 ( V_40 ) ) ;
struct V_40 * V_46 ;
struct V_26 * V_87 ;
V_87 = F_27 ( V_40 -> V_43 ) ;
while ( 1 ) {
int V_29 ;
int V_88 ;
F_34 () ;
V_53 = V_40 ;
for ( V_46 = V_40 -> V_62 ; V_46 ; V_46 = V_46 -> V_63 ) {
if ( ! F_19 ( V_46 ) )
continue;
if ( V_46 -> V_43 )
F_22 ( L_2 , _ ( F_21 ( V_46 ) ) ) ;
else {
F_22 ( L_29 , _ ( F_21 ( V_46 ) ) ) ;
F_23 ( ':' ) ;
}
F_24 ( V_46 ) ;
if ( V_46 -> V_43 == V_87 )
F_52 ( 1 ) ;
if ( V_46 -> V_43 == F_27 ( V_40 -> V_43 ) )
F_23 ( 'X' ) ;
}
F_8 () ;
V_29 = F_53 ( V_6 ? _ ( V_6 ) : _ ( L_27 ) ,
_ ( V_89 ) ,
15 , 70 , 6 ) ;
V_88 = F_36 () ;
switch ( V_29 ) {
case 0 :
if ( V_88 ) {
V_46 = F_38 () ;
if ( ! V_46 -> V_43 )
break;
F_45 ( V_46 -> V_43 , V_67 ) ;
}
return;
case 1 :
if ( V_88 ) {
V_46 = F_38 () ;
F_41 ( V_46 ) ;
V_87 = V_46 -> V_43 ;
} else
F_41 ( V_40 ) ;
break;
case V_75 :
return;
case - V_76 :
return;
}
}
}
static void F_40 ( struct V_40 * V_40 )
{
const char * V_6 = F_21 ( V_40 ) ;
while ( 1 ) {
int V_29 ;
const char * V_90 ;
switch ( F_25 ( V_40 -> V_43 ) ) {
case V_91 :
V_90 = _ ( V_92 ) ;
break;
case V_93 :
V_90 = _ ( V_94 ) ;
break;
case V_95 :
V_90 = _ ( V_96 ) ;
break;
default:
V_90 = _ ( L_30 ) ;
}
F_8 () ;
V_29 = F_9 ( V_6 ? _ ( V_6 ) : _ ( L_27 ) ,
V_90 , 10 , 75 ,
F_32 ( V_40 -> V_43 ) ) ;
switch ( V_29 ) {
case 0 :
if ( F_54 ( V_40 -> V_43 , V_38 ) )
return;
F_46 ( NULL , _ ( L_31 ) , 5 , 43 ) ;
break;
case 1 :
F_41 ( V_40 ) ;
break;
case V_75 :
return;
}
}
}
static void F_43 ( void )
{
while ( 1 ) {
int V_29 ;
F_8 () ;
V_29 = F_9 ( NULL , V_97 ,
11 , 55 , V_8 ) ;
switch( V_29 ) {
case 0 :
if ( ! V_38 [ 0 ] )
return;
if ( ! F_55 ( V_38 ) ) {
F_1 ( V_38 ) ;
F_56 ( 1 ) ;
return;
}
F_46 ( NULL , _ ( L_32 ) , 5 , 38 ) ;
break;
case 1 :
F_11 ( _ ( L_33 ) , V_98 ) ;
break;
case V_75 :
return;
}
}
}
static void F_42 ( void )
{
while ( 1 ) {
int V_29 ;
F_8 () ;
V_29 = F_9 ( NULL , V_99 ,
11 , 55 , V_8 ) ;
switch( V_29 ) {
case 0 :
if ( ! V_38 [ 0 ] )
return;
if ( ! F_57 ( V_38 ) ) {
F_1 ( V_38 ) ;
return;
}
F_46 ( NULL , _ ( L_34 ) , 5 , 60 ) ;
break;
case 1 :
F_11 ( _ ( L_35 ) , V_100 ) ;
break;
case V_75 :
return;
}
}
}
static int F_58 ( void )
{
int V_29 ;
V_83 = 1 ;
F_8 () ;
if ( F_59 () )
V_29 = F_60 ( NULL ,
_ ( L_36
L_37 ) ,
6 , 60 ) ;
else
V_29 = - 1 ;
F_61 ( V_101 , V_102 ) ;
switch ( V_29 ) {
case 0 :
if ( F_57 ( V_8 ) ) {
fprintf ( V_103 , _ ( L_38
L_39
L_40
L_38 ) ) ;
return 1 ;
}
case - 1 :
printf ( _ ( L_38
L_41
L_42
L_38 ) ) ;
V_29 = 0 ;
break;
default:
fprintf ( V_103 , _ ( L_38
L_40
L_38 ) ) ;
if ( V_29 != V_75 )
V_29 = 0 ;
}
return V_29 ;
}
static void F_62 ( int V_104 )
{
exit ( F_58 () ) ;
}
int main ( int V_105 , char * * V_106 )
{
char * V_107 ;
int V_29 ;
setlocale ( V_108 , L_8 ) ;
F_63 ( V_109 , V_110 ) ;
F_64 ( V_109 ) ;
signal ( V_111 , F_62 ) ;
F_65 ( V_106 [ 1 ] ) ;
F_55 ( NULL ) ;
V_107 = getenv ( L_43 ) ;
if ( V_107 ) {
if ( ! strcasecmp ( V_107 , L_44 ) )
V_56 = 1 ;
}
if ( F_66 ( NULL ) ) {
fprintf ( V_103 , F_67 ( L_45 ) ) ;
fprintf ( V_103 , F_67 ( L_46 ) ) ;
return 1 ;
}
F_1 ( F_68 () ) ;
F_69 ( F_49 ) ;
do {
F_17 ( & V_5 , NULL ) ;
V_29 = F_58 () ;
} while ( V_29 == V_75 );
return V_29 ;
}
