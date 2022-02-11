static int F_1 ( unsigned char * V_1 , const char * V_2 )
{
char * V_3 ;
int V_4 , V_5 ;
int V_6 ;
while ( * V_2 && ( * V_2 == ' ' || * V_2 == '\t' || * V_2 == '\n' ) )
++ V_2 ;
V_6 = strlen ( V_2 ) ;
V_4 = 0 ;
while ( V_4 < V_6 ) {
V_3 = strchr ( V_7 , V_2 [ V_4 ] ) ;
if ( V_3 == ( char * ) 0 )
break;
else
V_1 [ V_4 ] = V_3 - V_7 ;
++ V_4 ;
}
if ( V_4 == 0 )
return 0 ;
V_6 = V_4 ;
V_4 = V_6 - 1 ;
V_5 = V_6 ;
while ( 1 ) {
V_1 [ V_5 ] = V_1 [ V_4 ] ;
if ( -- V_4 < 0 )
break;
V_1 [ V_5 ] |= ( V_1 [ V_4 ] & 3 ) << 6 ;
-- V_5 ;
V_1 [ V_5 ] = ( unsigned char ) ( ( V_1 [ V_4 ] & 0x3c ) >> 2 ) ;
if ( -- V_4 < 0 )
break;
V_1 [ V_5 ] |= ( V_1 [ V_4 ] & 0xf ) << 4 ;
-- V_5 ;
V_1 [ V_5 ] = ( unsigned char ) ( ( V_1 [ V_4 ] & 0x30 ) >> 4 ) ;
if ( -- V_4 < 0 )
break;
V_1 [ V_5 ] |= ( V_1 [ V_4 ] << 2 ) ;
V_1 [ -- V_5 ] = 0 ;
if ( -- V_4 < 0 )
break;
}
while ( V_1 [ V_5 ] == 0 && V_5 <= V_6 )
++ V_5 ;
V_4 = 0 ;
while ( V_5 <= V_6 )
V_1 [ V_4 ++ ] = V_1 [ V_5 ++ ] ;
return V_4 ;
}
static char * F_2 ( char * V_8 , const unsigned char * V_2 , int V_6 )
{
int V_9 , V_10 = V_6 % 3 ;
unsigned char V_11 = 0 , V_12 = 0 , V_13 = 0 , V_14 = 0 ;
char * V_15 = V_8 ;
switch ( V_10 ) {
case 1 :
V_13 = V_2 [ 0 ] ;
break;
case 2 :
V_12 = V_2 [ 0 ] ;
V_13 = V_2 [ 1 ] ;
break;
}
while ( 1 ) {
V_9 = ( V_11 & 0xfc ) >> 2 ;
if ( V_14 || V_9 != 0 ) {
* V_8 ++ = V_7 [ V_9 ] ;
V_14 = 1 ;
}
V_9 = ( ( V_11 & 3 ) << 4 ) | ( ( V_12 & 0xf0 ) >> 4 ) ;
if ( V_14 || V_9 != 0 ) {
* V_8 ++ = V_7 [ V_9 ] ;
V_14 = 1 ;
}
V_9 = ( ( V_12 & 0xf ) << 2 ) | ( ( V_13 & 0xc0 ) >> 6 ) ;
if ( V_14 || V_9 != 0 ) {
* V_8 ++ = V_7 [ V_9 ] ;
V_14 = 1 ;
}
V_9 = V_13 & 0x3f ;
if ( V_14 || V_9 != 0 ) {
* V_8 ++ = V_7 [ V_9 ] ;
V_14 = 1 ;
}
if ( V_10 >= V_6 )
break;
else {
V_11 = V_2 [ V_10 ++ ] ;
V_12 = V_2 [ V_10 ++ ] ;
V_13 = V_2 [ V_10 ++ ] ;
}
}
* V_8 ++ = '\0' ;
return V_15 ;
}
void F_3 ( T_1 * V_16 )
{
if ( V_16 == NULL )
return;
F_4 ( V_16 -> V_17 ) ;
F_5 ( V_16 -> V_18 ) ;
F_6 ( V_16 -> V_19 ) ;
F_6 ( V_16 -> V_20 ) ;
F_6 ( V_16 ) ;
}
static T_1 * F_7 ( void )
{
T_1 * V_21 = F_8 ( sizeof( * V_21 ) ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_22 = NULL ;
V_21 -> V_23 = NULL ;
V_21 -> V_17 = NULL ;
V_21 -> V_18 = NULL ;
V_21 -> V_19 = NULL ;
V_21 -> V_20 = NULL ;
return V_21 ;
}
static void F_9 ( T_1 * V_24 , const T_2 * V_23 ,
const T_2 * V_22 )
{
V_24 -> V_22 = V_22 ;
V_24 -> V_23 = V_23 ;
}
static int F_10 ( T_1 * V_24 , const char * V_19 ,
const char * V_20 )
{
if ( V_19 != NULL && NULL == ( V_24 -> V_19 = F_11 ( V_19 ) ) )
return 0 ;
return ( V_20 == NULL || NULL != ( V_24 -> V_20 = F_11 ( V_20 ) ) ) ;
}
static int F_12 ( T_1 * V_24 , const char * V_17 ,
const char * V_18 )
{
unsigned char V_25 [ V_26 ] ;
int V_27 ;
if ( strlen ( V_17 ) > V_26 || strlen ( V_18 ) > V_26 )
return 0 ;
V_27 = F_1 ( V_25 , V_18 ) ;
if ( NULL == ( V_24 -> V_18 = F_13 ( V_25 , V_27 , NULL ) ) )
return 0 ;
V_27 = F_1 ( V_25 , V_17 ) ;
return ( ( V_24 -> V_17 = F_13 ( V_25 , V_27 , NULL ) ) != NULL ) ;
}
static int F_14 ( T_1 * V_24 , T_2 * V_17 , T_2 * V_18 )
{
V_24 -> V_18 = V_18 ;
V_24 -> V_17 = V_17 ;
return ( V_24 -> V_17 != NULL && V_24 -> V_18 != NULL ) ;
}
static T_1 * F_15 ( T_1 * V_2 )
{
T_1 * V_21 ;
if ( V_2 == NULL )
return NULL ;
if ( ( V_21 = F_7 () ) == NULL )
return NULL ;
F_9 ( V_21 , V_2 -> V_23 , V_2 -> V_22 ) ;
if ( ! F_10 ( V_21 , V_2 -> V_19 , V_2 -> V_20 )
|| ! F_14 ( V_21 , F_16 ( V_2 -> V_17 ) , F_16 ( V_2 -> V_18 ) ) ) {
F_3 ( V_21 ) ;
return NULL ;
}
return V_21 ;
}
T_3 * F_17 ( char * V_28 )
{
T_3 * V_29 = F_8 ( sizeof( * V_29 ) ) ;
if ( V_29 == NULL )
return NULL ;
if ( ( V_29 -> V_30 = F_18 () ) == NULL
|| ( V_29 -> V_31 = F_19 () ) == NULL ) {
F_6 ( V_29 ) ;
return NULL ;
}
V_29 -> V_32 = NULL ;
V_29 -> V_33 = NULL ;
V_29 -> V_28 = NULL ;
if ( ( V_28 != NULL ) && ( V_29 -> V_28 = F_11 ( V_28 ) ) == NULL ) {
F_20 ( V_29 -> V_30 ) ;
F_21 ( V_29 -> V_31 ) ;
F_6 ( V_29 ) ;
return NULL ;
}
return V_29 ;
}
void F_22 ( T_3 * V_29 )
{
if ( ! V_29 )
return;
F_23 ( V_29 -> V_30 , F_3 ) ;
F_21 ( V_29 -> V_31 ) ;
F_6 ( V_29 -> V_28 ) ;
F_6 ( V_29 ) ;
}
static T_4 * F_24 ( const char * V_34 )
{
unsigned char V_25 [ V_26 ] ;
int V_27 ;
T_4 * V_35 = F_8 ( sizeof( * V_35 ) ) ;
if ( V_35 == NULL )
return NULL ;
if ( ( V_35 -> V_36 = F_11 ( V_34 ) ) == NULL )
goto V_37;
V_27 = F_1 ( V_25 , V_34 ) ;
if ( ( V_35 -> V_38 = F_13 ( V_25 , V_27 , NULL ) ) )
return V_35 ;
F_6 ( V_35 -> V_36 ) ;
V_37:
F_6 ( V_35 ) ;
return NULL ;
}
static void F_25 ( T_4 * V_31 )
{
if ( V_31 == NULL )
return;
F_6 ( V_31 -> V_36 ) ;
F_4 ( V_31 -> V_38 ) ;
F_6 ( V_31 ) ;
}
int F_26 ( T_3 * V_29 , char * V_39 )
{
int V_40 ;
F_27 ( V_41 ) * V_42 = F_28 () ;
char * V_43 = NULL ;
int V_4 ;
char * * V_44 ;
V_41 * V_45 = NULL ;
T_1 * V_16 = NULL ;
T_5 * V_46 = NULL ;
T_6 * V_47 = F_29 ( F_30 () ) ;
V_40 = V_48 ;
if ( V_47 == NULL || F_31 ( V_47 , V_39 ) <= 0 )
goto V_37;
V_40 = V_49 ;
if ( ( V_46 = F_32 ( V_47 , V_50 ) ) == NULL )
goto V_37;
V_40 = V_51 ;
if ( V_29 -> V_28 ) {
V_43 = F_33 ( NULL ) -> V_19 ;
}
for ( V_4 = 0 ; V_4 < F_34 ( V_46 -> V_52 ) ; V_4 ++ ) {
V_44 = F_35 ( V_46 -> V_52 , V_4 ) ;
if ( V_44 [ V_53 ] [ 0 ] == V_54 ) {
if ( ( V_45 = F_8 ( sizeof( * V_45 ) ) ) == NULL )
goto V_37;
if ( ( V_45 -> V_19 = F_11 ( V_44 [ V_55 ] ) ) == NULL
|| ( V_45 -> V_22 = F_36 ( V_29 -> V_31 , V_44 [ V_56 ] ) )
== NULL
|| ( V_45 -> V_23 = F_36 ( V_29 -> V_31 , V_44 [ V_57 ] ) )
== NULL
|| F_37 ( V_42 , V_45 , 0 ) == 0 )
goto V_37;
V_45 = NULL ;
if ( V_29 -> V_28 != NULL ) {
V_43 = V_44 [ V_55 ] ;
}
} else if ( V_44 [ V_53 ] [ 0 ] == V_58 ) {
const V_41 * V_59 ;
if ( ( V_59 = F_38 ( V_44 [ V_60 ] , V_42 ) ) != NULL ) {
V_40 = V_51 ;
if ( ( V_16 = F_7 () ) == NULL )
goto V_37;
F_9 ( V_16 , V_59 -> V_23 , V_59 -> V_22 ) ;
if ( ! F_10
( V_16 , V_44 [ V_55 ] , V_44 [ V_61 ] ) )
goto V_37;
V_40 = V_62 ;
if ( ! F_12
( V_16 , V_44 [ V_57 ] , V_44 [ V_56 ] ) )
goto V_37;
if ( F_39 ( V_29 -> V_30 , V_16 , 0 ) == 0 )
goto V_37;
V_16 = NULL ;
}
}
}
if ( V_43 != NULL ) {
if ( ( ( V_45 = F_38 ( V_43 , V_42 ) ) == NULL ) ) {
V_40 = V_62 ;
goto V_37;
}
V_29 -> V_32 = V_45 -> V_23 ;
V_29 -> V_33 = V_45 -> V_22 ;
V_45 = NULL ;
}
V_40 = V_63 ;
V_37:
if ( V_45 != NULL ) {
F_6 ( V_45 -> V_19 ) ;
F_6 ( V_45 ) ;
}
F_3 ( V_16 ) ;
F_40 ( V_46 ) ;
F_41 ( V_47 ) ;
F_42 ( V_42 ) ;
return V_40 ;
}
static T_1 * F_43 ( T_3 * V_29 , char * V_64 )
{
int V_4 ;
T_1 * V_65 ;
if ( V_29 == NULL )
return NULL ;
for ( V_4 = 0 ; V_4 < F_44 ( V_29 -> V_30 ) ; V_4 ++ ) {
V_65 = F_45 ( V_29 -> V_30 , V_4 ) ;
if ( strcmp ( V_65 -> V_19 , V_64 ) == 0 )
return V_65 ;
}
return NULL ;
}
T_1 * F_46 ( T_3 * V_29 , char * V_64 )
{
return F_43 ( V_29 , V_64 ) ;
}
T_1 * F_47 ( T_3 * V_29 , char * V_64 )
{
T_1 * V_65 ;
unsigned char V_66 [ V_67 ] ;
unsigned char V_68 [ V_67 ] ;
T_7 * V_69 = NULL ;
if ( V_29 == NULL )
return NULL ;
if ( ( V_65 = F_43 ( V_29 , V_64 ) ) != NULL )
return F_15 ( V_65 ) ;
if ( ( V_29 -> V_28 == NULL ) ||
( V_29 -> V_32 == NULL ) || ( V_29 -> V_33 == NULL ) )
return NULL ;
if ( ( V_65 = F_7 () ) == NULL )
return NULL ;
F_9 ( V_65 , V_29 -> V_32 , V_29 -> V_33 ) ;
if ( ! F_10 ( V_65 , V_64 , NULL ) )
goto V_37;
if ( F_48 ( V_66 , V_67 ) <= 0 )
goto V_37;
V_69 = F_49 () ;
if ( V_69 == NULL
|| ! F_50 ( V_69 , F_51 () , NULL )
|| ! F_52 ( V_69 , V_29 -> V_28 , strlen ( V_29 -> V_28 ) )
|| ! F_52 ( V_69 , V_64 , strlen ( V_64 ) )
|| ! F_53 ( V_69 , V_68 , NULL ) )
goto V_37;
F_54 ( V_69 ) ;
V_69 = NULL ;
if ( F_14 ( V_65 ,
F_13 ( V_68 , V_67 , NULL ) ,
F_13 ( V_66 , V_67 , NULL ) ) )
return V_65 ;
V_37:
F_54 ( V_69 ) ;
F_3 ( V_65 ) ;
return NULL ;
}
char * F_55 ( const char * V_65 , const char * V_70 , char * * V_71 ,
char * * V_72 , const char * V_22 , const char * V_23 )
{
int V_27 ;
char * V_73 = NULL , * V_74 = NULL ;
const T_2 * V_75 = NULL , * V_76 = NULL ;
T_2 * V_77 = NULL , * V_78 = NULL , * V_17 = NULL , * V_18 = NULL ;
unsigned char V_25 [ V_26 ] ;
unsigned char V_79 [ V_26 ] ;
char * V_80 = NULL ;
int V_81 = 0 ;
if ( ( V_65 == NULL ) ||
( V_70 == NULL ) || ( V_71 == NULL ) || ( V_72 == NULL ) )
goto V_37;
if ( V_22 ) {
if ( ( V_27 = F_1 ( V_25 , V_22 ) ) == 0 )
goto V_37;
V_77 = F_13 ( V_25 , V_27 , NULL ) ;
V_75 = V_77 ;
if ( ( V_27 = F_1 ( V_25 , V_23 ) ) == 0 )
goto V_37;
V_78 = F_13 ( V_25 , V_27 , NULL ) ;
V_76 = V_78 ;
V_80 = L_1 ;
} else {
V_41 * V_45 = F_38 ( V_23 , NULL ) ;
if ( V_45 == NULL )
goto V_37;
V_75 = V_45 -> V_22 ;
V_76 = V_45 -> V_23 ;
V_80 = V_45 -> V_19 ;
}
if ( * V_71 == NULL ) {
if ( F_48 ( V_79 , V_82 ) <= 0 )
goto V_37;
V_17 = F_13 ( V_79 , V_82 , NULL ) ;
} else {
if ( ( V_27 = F_1 ( V_79 , * V_71 ) ) == 0 )
goto V_37;
V_17 = F_13 ( V_79 , V_27 , NULL ) ;
}
if ( ! F_56 ( V_65 , V_70 , & V_17 , & V_18 , V_75 , V_76 ) )
goto V_37;
F_57 ( V_18 , V_25 ) ;
V_81 = F_58 ( V_18 ) * 2 ;
if ( ( ( V_74 = F_8 ( V_81 ) ) == NULL ) )
goto V_37;
F_2 ( V_74 , V_25 , F_58 ( V_18 ) ) ;
if ( * V_71 == NULL ) {
char * V_83 ;
if ( ( V_83 = F_8 ( V_82 * 2 ) ) == NULL ) {
goto V_37;
}
F_2 ( V_83 , V_79 , V_82 ) ;
* V_71 = V_83 ;
}
* V_72 = V_74 ;
V_74 = NULL ;
V_73 = V_80 ;
V_37:
F_4 ( V_77 ) ;
F_4 ( V_78 ) ;
F_59 ( V_74 , V_81 ) ;
F_5 ( V_17 ) ;
F_5 ( V_18 ) ;
return V_73 ;
}
int F_56 ( const char * V_65 , const char * V_70 , T_2 * * V_71 ,
T_2 * * V_72 , const T_2 * V_22 ,
const T_2 * V_23 )
{
int V_73 = 0 ;
T_2 * V_84 = NULL ;
T_8 * V_85 = F_60 () ;
unsigned char V_79 [ V_26 ] ;
T_2 * V_86 = NULL ;
if ( ( V_65 == NULL ) ||
( V_70 == NULL ) ||
( V_71 == NULL ) ||
( V_72 == NULL ) || ( V_22 == NULL ) || ( V_23 == NULL ) || ( V_85 == NULL ) )
goto V_37;
if ( * V_71 == NULL ) {
if ( F_48 ( V_79 , V_82 ) <= 0 )
goto V_37;
V_86 = F_13 ( V_79 , V_82 , NULL ) ;
} else {
V_86 = * V_71 ;
}
V_84 = F_61 ( V_86 , V_65 , V_70 ) ;
* V_72 = F_62 () ;
if ( * V_72 == NULL )
goto V_37;
if ( ! F_63 ( * V_72 , V_23 , V_84 , V_22 , V_85 ) ) {
F_5 ( * V_72 ) ;
goto V_37;
}
V_73 = 1 ;
* V_71 = V_86 ;
V_37:
if ( V_71 != NULL && * V_71 != V_86 )
F_5 ( V_86 ) ;
F_5 ( V_84 ) ;
F_64 ( V_85 ) ;
return V_73 ;
}
