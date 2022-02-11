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
struct V_9 * * V_10 ;
struct V_11 V_12 ;
char * V_13 ;
int V_14 ;
V_15:
F_4 () ;
V_14 = F_5 ( _ ( L_3 ) ,
_ ( L_4 V_16 L_5
L_6 V_16 L_7 ) ,
10 , 75 , L_8 ) ;
switch ( V_14 ) {
case 0 :
break;
case 1 :
F_6 ( _ ( L_9 ) , V_17 ) ;
goto V_15;
default:
return;
}
V_13 = V_18 ;
if ( strncasecmp ( V_18 , V_16 , strlen ( V_16 ) ) == 0 )
V_13 += strlen ( V_16 ) ;
V_10 = F_7 ( V_13 ) ;
V_12 = F_8 ( V_10 ) ;
free ( V_10 ) ;
F_9 ( _ ( L_10 ) , F_10 ( & V_12 ) , 0 , 0 ) ;
F_11 ( & V_12 ) ;
}
static void F_12 ( struct V_19 * V_19 )
{
struct V_9 * V_20 ;
struct V_21 * V_22 ;
struct V_19 * V_23 ;
int type , V_24 , V_25 = 2 ;
T_1 V_26 ;
char V_27 ;
bool V_28 ;
V_28 = F_13 ( V_19 ) ;
if ( V_29 && ! F_14 ( V_19 ) )
return;
else if ( ! V_29 && ! V_28 )
return;
V_20 = V_19 -> V_20 ;
V_22 = V_19 -> V_6 ;
if ( ! V_20 ) {
if ( V_22 && V_19 != V_30 ) {
const char * V_6 = F_15 ( V_19 ) ;
switch ( V_22 -> type ) {
case V_31 :
V_32 ++ ;
V_6 = _ ( V_6 ) ;
if ( V_33 ) {
F_16 ( L_11 ,
V_19 -> V_34 ? L_12 : L_13 ,
V_35 + 1 , ' ' , V_6 ) ;
} else
F_16 ( L_14 , V_35 + 1 , ' ' , V_6 ) ;
F_17 ( 'm' ) ;
F_18 ( V_19 ) ;
if ( V_33 && V_19 -> V_34 )
goto V_36;
return;
case V_37 :
if ( V_6 ) {
V_32 ++ ;
F_16 ( L_15 , V_35 + 1 , ' ' , _ ( V_6 ) ) ;
F_17 ( ':' ) ;
F_18 ( V_19 ) ;
}
break;
default:
if ( V_6 ) {
V_32 ++ ;
F_16 ( L_16 , V_35 + 1 , ' ' , _ ( V_6 ) ) ;
F_17 ( ':' ) ;
F_18 ( V_19 ) ;
}
}
} else
V_25 = 0 ;
goto V_36;
}
type = F_19 ( V_20 ) ;
if ( F_20 ( V_20 ) ) {
struct V_9 * V_38 = F_21 ( V_20 ) ;
struct V_19 * V_39 = NULL ;
V_32 ++ ;
for ( V_23 = V_19 -> V_40 ; V_23 ; V_23 = V_23 -> V_41 ) {
if ( F_13 ( V_23 ) && V_23 -> V_20 == V_38 )
V_39 = V_23 ;
}
V_26 = F_22 ( V_20 ) ;
if ( F_23 ( V_20 ) ) {
switch ( type ) {
case V_42 :
F_16 ( L_17 , V_26 == V_43 ? ' ' : '*' ) ;
break;
case V_44 :
switch ( V_26 ) {
case V_45 : V_27 = '*' ; break;
case V_46 : V_27 = 'M' ; break;
default: V_27 = ' ' ; break;
}
F_16 ( L_18 , V_27 ) ;
break;
}
F_17 ( 't' ) ;
F_18 ( V_19 ) ;
} else {
F_16 ( L_19 ) ;
F_17 ( V_39 ? 't' : ':' ) ;
F_18 ( V_19 ) ;
}
F_24 ( L_20 , V_35 + 1 , ' ' , _ ( F_15 ( V_19 ) ) ) ;
if ( V_26 == V_45 ) {
if ( V_39 ) {
F_24 ( L_21 , _ ( F_15 ( V_39 ) ) ) ;
F_24 ( L_22 ) ;
if ( V_39 -> V_40 ) {
V_35 += 2 ;
F_12 ( V_39 ) ;
V_35 -= 2 ;
}
}
return;
}
} else {
if ( V_19 == V_30 ) {
F_16 ( L_16 , V_35 + 1 , ' ' , _ ( F_15 ( V_19 ) ) ) ;
F_17 ( ':' ) ;
F_18 ( V_19 ) ;
goto V_36;
}
V_32 ++ ;
V_26 = F_22 ( V_20 ) ;
if ( F_25 ( V_20 ) && V_26 == V_45 ) {
F_16 ( L_19 ) ;
F_17 ( ':' ) ;
F_18 ( V_19 ) ;
} else {
switch ( type ) {
case V_42 :
if ( F_23 ( V_20 ) )
F_16 ( L_17 , V_26 == V_43 ? ' ' : '*' ) ;
else
F_16 ( L_23 , V_26 == V_43 ? ' ' : '*' ) ;
F_17 ( 't' ) ;
F_18 ( V_19 ) ;
break;
case V_44 :
switch ( V_26 ) {
case V_45 : V_27 = '*' ; break;
case V_46 : V_27 = 'M' ; break;
default: V_27 = ' ' ; break;
}
if ( F_23 ( V_20 ) ) {
if ( V_20 -> V_47 . V_48 == V_46 )
F_16 ( L_24 , V_27 ) ;
else
F_16 ( L_18 , V_27 ) ;
} else
F_16 ( L_23 , V_27 ) ;
F_17 ( 't' ) ;
F_18 ( V_19 ) ;
break;
default:
V_24 = 2 + strlen ( F_26 ( V_20 ) ) ;
F_16 ( L_25 , F_26 ( V_20 ) ) ;
V_24 = V_35 - V_24 + 4 ;
if ( V_24 < 0 )
V_24 = 0 ;
F_24 ( L_26 , V_24 , ' ' , _ ( F_15 ( V_19 ) ) ,
( F_27 ( V_20 ) || ! F_23 ( V_20 ) ) ?
L_8 : _ ( L_27 ) ) ;
F_17 ( 's' ) ;
F_18 ( V_19 ) ;
goto V_36;
}
}
F_24 ( L_26 , V_35 + 1 , ' ' , _ ( F_15 ( V_19 ) ) ,
( F_27 ( V_20 ) || ! F_23 ( V_20 ) ) ?
L_8 : _ ( L_27 ) ) ;
if ( V_19 -> V_6 -> type == V_31 ) {
F_24 ( L_22 ) ;
return;
}
}
V_36:
V_35 += V_25 ;
for ( V_23 = V_19 -> V_40 ; V_23 ; V_23 = V_23 -> V_41 )
F_12 ( V_23 ) ;
V_35 -= V_25 ;
}
static void F_28 ( struct V_19 * V_19 )
{
struct V_19 * V_49 ;
const char * V_6 = F_15 ( V_19 ) ;
struct V_9 * V_20 ;
struct V_19 * V_50 = NULL ;
int V_12 ;
int V_51 = 0 ;
while ( 1 ) {
F_29 () ;
V_30 = V_19 ;
F_12 ( V_19 ) ;
if ( ! V_32 )
break;
if ( V_19 == & V_5 ) {
F_16 ( L_28 ) ;
F_17 ( ':' ) ;
F_16 ( _ ( L_29 ) ) ;
F_17 ( 'L' ) ;
F_16 ( _ ( L_30 ) ) ;
F_17 ( 'S' ) ;
}
F_4 () ;
V_12 = F_30 ( V_6 ? _ ( V_6 ) : _ ( L_31 ) ,
_ ( V_52 ) ,
V_50 , & V_51 ) ;
if ( V_12 == 1 || V_12 == V_53 || V_12 == - V_54 )
break;
if ( ! F_31 () )
continue;
if ( ! F_32 () )
continue;
V_49 = F_33 () ;
V_50 = F_33 () ;
if ( V_49 )
V_20 = V_49 -> V_20 ;
else
V_20 = NULL ;
switch ( V_12 ) {
case 0 :
switch ( F_32 () ) {
case 'm' :
if ( V_33 )
V_49 -> V_34 = ( void * ) ( long ) ! V_49 -> V_34 ;
else
F_28 ( V_49 ) ;
break;
case 't' :
if ( F_20 ( V_20 ) && F_22 ( V_20 ) == V_45 )
F_34 ( V_49 ) ;
else if ( V_49 -> V_6 -> type == V_31 )
F_28 ( V_49 ) ;
break;
case 's' :
F_35 ( V_49 ) ;
break;
case 'L' :
F_36 () ;
break;
case 'S' :
F_37 () ;
break;
}
break;
case 2 :
if ( V_20 )
F_38 ( V_49 ) ;
else
F_6 ( _ ( L_32 ) , _ ( V_55 ) ) ;
break;
case 3 :
if ( F_39 ( 't' ) ) {
if ( F_40 ( V_20 , V_45 ) )
break;
if ( F_40 ( V_20 , V_46 ) )
F_9 ( NULL , V_56 , 6 , 74 ) ;
}
break;
case 4 :
if ( F_39 ( 't' ) )
F_40 ( V_20 , V_43 ) ;
break;
case 5 :
if ( F_39 ( 't' ) )
F_40 ( V_20 , V_46 ) ;
break;
case 6 :
if ( F_39 ( 't' ) )
F_41 ( V_20 ) ;
else if ( F_39 ( 'm' ) )
F_28 ( V_49 ) ;
break;
case 7 :
F_3 () ;
break;
case 8 :
V_29 = ! V_29 ;
break;
}
}
}
static void F_9 ( const char * V_57 , const char * V_7 , int V_58 , int V_59 )
{
F_4 () ;
F_42 ( V_57 , V_7 , V_58 , V_59 ) ;
}
static void F_6 ( const char * V_57 , const char * V_7 )
{
F_9 ( V_57 , V_7 , 0 , 0 ) ;
}
static void F_38 ( struct V_19 * V_19 )
{
struct V_11 V_60 = F_43 () ;
V_60 . V_61 = F_44 ( V_62 ) - 10 ;
F_45 ( V_19 , & V_60 ) ;
F_6 ( _ ( F_15 ( V_19 ) ) , F_10 ( & V_60 ) ) ;
F_11 ( & V_60 ) ;
}
static void F_34 ( struct V_19 * V_19 )
{
const char * V_6 = _ ( F_15 ( V_19 ) ) ;
struct V_19 * V_23 ;
struct V_9 * V_63 ;
V_63 = F_21 ( V_19 -> V_20 ) ;
while ( 1 ) {
int V_12 ;
int V_64 ;
F_29 () ;
V_30 = V_19 ;
for ( V_23 = V_19 -> V_40 ; V_23 ; V_23 = V_23 -> V_41 ) {
if ( ! F_13 ( V_23 ) )
continue;
if ( V_23 -> V_20 )
F_16 ( L_2 , _ ( F_15 ( V_23 ) ) ) ;
else {
F_16 ( L_33 , _ ( F_15 ( V_23 ) ) ) ;
F_17 ( ':' ) ;
}
F_18 ( V_23 ) ;
if ( V_23 -> V_20 == V_63 )
F_46 ( 1 ) ;
if ( V_23 -> V_20 == F_21 ( V_19 -> V_20 ) )
F_17 ( 'X' ) ;
}
F_4 () ;
V_12 = F_47 ( V_6 ? _ ( V_6 ) : _ ( L_31 ) ,
_ ( V_65 ) ,
15 , 70 , 6 ) ;
V_64 = F_31 () ;
switch ( V_12 ) {
case 0 :
if ( V_64 ) {
V_23 = F_33 () ;
if ( ! V_23 -> V_20 )
break;
F_40 ( V_23 -> V_20 , V_45 ) ;
}
return;
case 1 :
if ( V_64 ) {
V_23 = F_33 () ;
F_38 ( V_23 ) ;
V_63 = V_23 -> V_20 ;
} else
F_38 ( V_19 ) ;
break;
case V_53 :
return;
case - V_54 :
return;
}
}
}
static void F_35 ( struct V_19 * V_19 )
{
const char * V_6 = F_15 ( V_19 ) ;
while ( 1 ) {
int V_12 ;
const char * V_66 ;
switch ( F_19 ( V_19 -> V_20 ) ) {
case V_67 :
V_66 = _ ( V_68 ) ;
break;
case V_69 :
V_66 = _ ( V_70 ) ;
break;
case V_71 :
V_66 = _ ( V_72 ) ;
break;
default:
V_66 = _ ( L_34 ) ;
}
F_4 () ;
V_12 = F_5 ( V_6 ? _ ( V_6 ) : _ ( L_31 ) ,
V_66 , 10 , 75 ,
F_26 ( V_19 -> V_20 ) ) ;
switch ( V_12 ) {
case 0 :
if ( F_48 ( V_19 -> V_20 , V_18 ) )
return;
F_9 ( NULL , _ ( L_35 ) , 5 , 43 ) ;
break;
case 1 :
F_38 ( V_19 ) ;
break;
case V_53 :
return;
}
}
}
static void F_36 ( void )
{
while ( 1 ) {
int V_12 ;
F_4 () ;
V_12 = F_5 ( NULL , V_73 ,
11 , 55 , V_8 ) ;
switch( V_12 ) {
case 0 :
if ( ! V_18 [ 0 ] )
return;
if ( ! F_49 ( V_18 ) ) {
F_1 ( V_18 ) ;
F_50 ( 1 ) ;
return;
}
F_9 ( NULL , _ ( L_36 ) , 5 , 38 ) ;
break;
case 1 :
F_6 ( _ ( L_37 ) , V_74 ) ;
break;
case V_53 :
return;
}
}
}
static void F_37 ( void )
{
while ( 1 ) {
int V_12 ;
F_4 () ;
V_12 = F_5 ( NULL , V_75 ,
11 , 55 , V_8 ) ;
switch( V_12 ) {
case 0 :
if ( ! V_18 [ 0 ] )
return;
if ( ! F_51 ( V_18 ) ) {
F_1 ( V_18 ) ;
return;
}
F_9 ( NULL , _ ( L_38 ) , 5 , 60 ) ;
break;
case 1 :
F_6 ( _ ( L_39 ) , V_76 ) ;
break;
case V_53 :
return;
}
}
}
static int F_52 ( void )
{
int V_12 ;
F_4 () ;
if ( F_53 () )
V_12 = F_54 ( NULL ,
_ ( L_40
L_41 ) ,
6 , 60 ) ;
else
V_12 = - 1 ;
F_55 ( V_77 , V_78 ) ;
switch ( V_12 ) {
case 0 :
if ( F_51 ( V_8 ) ) {
fprintf ( V_79 , _ ( L_42
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
V_12 = 0 ;
break;
default:
fprintf ( V_79 , _ ( L_42
L_44
L_42 ) ) ;
if ( V_12 != V_53 )
V_12 = 0 ;
}
return V_12 ;
}
static void F_56 ( int V_80 )
{
exit ( F_52 () ) ;
}
int main ( int V_81 , char * * V_82 )
{
char * V_83 ;
int V_12 ;
setlocale ( V_84 , L_8 ) ;
F_57 ( V_85 , V_86 ) ;
F_58 ( V_85 ) ;
signal ( V_87 , F_56 ) ;
F_59 ( V_82 [ 1 ] ) ;
F_49 ( NULL ) ;
V_83 = getenv ( L_47 ) ;
if ( V_83 ) {
if ( ! strcasecmp ( V_83 , L_48 ) )
V_33 = 1 ;
}
F_60 () ;
F_61 ( V_62 , V_78 , V_77 ) ;
if ( F_62 ( NULL ) ) {
fprintf ( V_79 , F_63 ( L_49 ) ) ;
fprintf ( V_79 , F_63 ( L_50 ) ) ;
return 1 ;
}
F_1 ( F_64 () ) ;
do {
F_28 ( & V_5 ) ;
V_12 = F_52 () ;
} while ( V_12 == V_53 );
return V_12 ;
}
