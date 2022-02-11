int F_1 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_3 , int V_4 ,
const T_3 * V_5 )
{
if ( V_4 & V_6 )
{
T_1 * V_7 , * V_8 ;
V_7 = F_2 ( V_1 , V_2 , V_5 ) ;
if ( ! V_7 )
{
F_3 ( V_9 , V_10 ) ;
return 0 ;
}
F_4 ( V_3 , V_7 , V_4 ) ;
( void ) F_5 ( V_7 ) ;
do
{
V_8 = F_6 ( V_7 ) ;
F_7 ( V_7 ) ;
V_7 = V_8 ;
} while ( V_7 != V_1 );
}
else
F_8 ( V_5 , V_1 , V_2 ) ;
return 1 ;
}
static int F_9 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_3 , int V_4 ,
const T_3 * V_5 )
{
T_1 * V_11 ;
int V_12 ;
V_11 = F_10 ( F_11 () ) ;
if( ! V_11 )
{
F_3 ( V_13 , V_10 ) ;
return 0 ;
}
V_1 = F_12 ( V_11 , V_1 ) ;
V_12 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
( void ) F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
F_7 ( V_11 ) ;
return V_12 ;
}
int F_13 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_3 , int V_4 ,
const char * V_14 ,
const T_3 * V_5 )
{
int V_12 ;
F_14 ( V_1 , L_1 , V_14 ) ;
V_12 = F_9 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_14 ( V_1 , L_2 , V_14 ) ;
return V_12 ;
}
static T_2 * F_15 ( T_1 * V_7 , const T_3 * V_5 )
{
T_1 * V_11 ;
T_2 * V_2 ;
if( ! ( V_11 = F_10 ( F_11 () ) ) ) {
F_3 ( V_15 , V_10 ) ;
return 0 ;
}
V_7 = F_12 ( V_11 , V_7 ) ;
V_2 = F_16 ( V_5 , V_7 , NULL ) ;
if( ! V_2 )
F_3 ( V_15 , V_16 ) ;
( void ) F_5 ( V_7 ) ;
V_7 = F_6 ( V_7 ) ;
F_7 ( V_11 ) ;
return V_2 ;
}
static int F_17 ( T_1 * V_1 , T_1 * V_17 , T_2 * V_2 , int V_4 ,
const T_3 * V_5 )
{
T_1 * V_18 ;
const T_4 * V_19 = V_5 -> V_20 ;
T_5 V_21 ;
if ( ! ( V_4 & V_22 ) )
{
F_4 ( V_17 , V_1 , V_4 ) ;
return 1 ;
}
if ( ! V_19 || ! V_19 -> V_23 )
{
F_3 ( V_24 ,
V_25 ) ;
return 0 ;
}
V_21 . V_1 = V_1 ;
V_21 . V_26 = NULL ;
V_21 . V_27 = NULL ;
if ( V_19 -> V_23 ( V_28 , & V_2 , V_5 , & V_21 ) <= 0 )
return 0 ;
F_4 ( V_17 , V_21 . V_26 , V_4 ) ;
if ( V_19 -> V_23 ( V_29 , & V_2 , V_5 , & V_21 ) <= 0 )
return 0 ;
while ( V_21 . V_26 != V_1 )
{
V_18 = F_6 ( V_21 . V_26 ) ;
F_7 ( V_21 . V_26 ) ;
V_21 . V_26 = V_18 ;
}
return 1 ;
}
T_2 * F_18 ( T_1 * V_7 , T_1 * * V_30 , const T_3 * V_5 )
{
T_1 * V_31 ;
F_19 ( V_32 ) * V_33 = NULL ;
F_19 ( T_1 ) * V_34 = NULL ;
V_32 * V_14 ;
T_6 * V_35 ;
T_2 * V_2 ;
int V_36 ;
if( V_30 ) * V_30 = NULL ;
if ( ! ( V_33 = F_20 ( V_7 ) ) ) {
F_3 ( V_37 , V_38 ) ;
return NULL ;
}
if( ! ( V_14 = F_21 ( V_33 , L_3 ) ) || ! V_14 -> V_39 ) {
F_22 ( V_33 , V_40 ) ;
F_3 ( V_37 , V_41 ) ;
return NULL ;
}
if( ! strcmp ( V_14 -> V_39 , L_4 ) ) {
V_35 = F_23 ( V_14 , L_5 ) ;
if( ! V_35 || ! V_35 -> V_42 ) {
F_22 ( V_33 , V_40 ) ;
F_3 ( V_37 , V_43 ) ;
return NULL ;
}
V_36 = F_24 ( V_7 , V_35 -> V_42 , & V_34 ) ;
F_22 ( V_33 , V_40 ) ;
if( ! V_36 || ( F_25 ( V_34 ) != 2 ) ) {
F_3 ( V_37 , V_44 ) ;
F_26 ( V_34 , V_45 ) ;
return NULL ;
}
V_31 = F_27 ( V_34 , 1 ) ;
if ( ! ( V_33 = F_20 ( V_31 ) ) ) {
F_3 ( V_37 , V_46 ) ;
F_26 ( V_34 , V_45 ) ;
return NULL ;
}
if( ! ( V_14 = F_21 ( V_33 , L_3 ) ) ||
! V_14 -> V_39 ) {
F_22 ( V_33 , V_40 ) ;
F_3 ( V_37 , V_47 ) ;
return NULL ;
}
if( strcmp ( V_14 -> V_39 , L_6 ) &&
strcmp ( V_14 -> V_39 , L_7 ) ) {
F_22 ( V_33 , V_40 ) ;
F_3 ( V_37 , V_48 ) ;
F_28 ( 2 , L_8 , V_14 -> V_39 ) ;
F_26 ( V_34 , V_45 ) ;
return NULL ;
}
F_22 ( V_33 , V_40 ) ;
if( ! ( V_2 = F_15 ( V_31 , V_5 ) ) ) {
F_3 ( V_37 , V_49 ) ;
F_26 ( V_34 , V_45 ) ;
return NULL ;
}
if( V_30 ) {
* V_30 = F_27 ( V_34 , 0 ) ;
F_7 ( V_31 ) ;
F_29 ( V_34 ) ;
} else F_26 ( V_34 , V_45 ) ;
return V_2 ;
}
if ( strcmp ( V_14 -> V_39 , L_9 ) &&
strcmp ( V_14 -> V_39 , L_10 ) ) {
F_3 ( V_37 , V_50 ) ;
F_28 ( 2 , L_8 , V_14 -> V_39 ) ;
F_22 ( V_33 , V_40 ) ;
return NULL ;
}
F_22 ( V_33 , V_40 ) ;
if( ! ( V_2 = F_15 ( V_7 , V_5 ) ) ) {
F_3 ( V_37 , V_51 ) ;
return NULL ;
}
return V_2 ;
}
int F_4 ( T_1 * V_3 , T_1 * V_1 , int V_4 )
{
T_1 * V_52 ;
char V_53 ;
int V_54 ;
char V_55 [ V_56 ] ;
V_52 = F_10 ( F_30 () ) ;
if ( ! V_52 )
return 0 ;
V_1 = F_12 ( V_52 , V_1 ) ;
if( V_4 & V_57 )
{
while( ( V_54 = F_31 ( V_3 , V_55 , V_56 ) ) > 0 )
F_32 ( V_1 , V_55 , V_54 ) ;
}
else
{
if( V_4 & V_58 )
F_14 ( V_1 , L_11 ) ;
while ( ( V_54 = F_33 ( V_3 , V_55 , V_56 ) ) > 0 )
{
V_53 = F_34 ( V_55 , & V_54 ) ;
if ( V_54 )
F_32 ( V_1 , V_55 , V_54 ) ;
if( V_53 ) F_32 ( V_1 , L_12 , 2 ) ;
}
}
( void ) F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
F_7 ( V_52 ) ;
return 1 ;
}
int F_35 ( T_1 * V_3 , T_1 * V_1 )
{
char V_59 [ 4096 ] ;
int V_54 ;
F_19 ( V_32 ) * V_33 ;
V_32 * V_14 ;
if ( ! ( V_33 = F_20 ( V_3 ) ) ) {
F_3 ( V_60 , V_38 ) ;
return 0 ;
}
if( ! ( V_14 = F_21 ( V_33 , L_3 ) ) || ! V_14 -> V_39 ) {
F_3 ( V_60 , V_61 ) ;
F_22 ( V_33 , V_40 ) ;
return 0 ;
}
if ( strcmp ( V_14 -> V_39 , L_13 ) ) {
F_3 ( V_60 , V_50 ) ;
F_28 ( 2 , L_8 , V_14 -> V_39 ) ;
F_22 ( V_33 , V_40 ) ;
return 0 ;
}
F_22 ( V_33 , V_40 ) ;
while ( ( V_54 = F_31 ( V_3 , V_59 , sizeof( V_59 ) ) ) > 0 )
F_32 ( V_1 , V_59 , V_54 ) ;
if ( V_54 < 0 )
return 0 ;
return 1 ;
}
char * F_36 ( char * V_62 )
{
return F_37 ( F_38 ( V_62 ) ) ;
}
static char * F_38 ( char * V_62 )
{
char * V_63 , V_64 ;
for( V_63 = V_62 ; ( V_64 = * V_63 ) ; V_63 ++ ) {
if( V_64 == '"' ) {
if( V_63 [ 1 ] ) return V_63 + 1 ;
return NULL ;
}
if( ! isspace ( ( unsigned char ) V_64 ) ) return V_63 ;
}
return NULL ;
}
static char * F_37 ( char * V_62 )
{
char * V_63 , V_64 ;
if( ! V_62 ) return NULL ;
for( V_63 = V_62 + strlen ( V_62 ) - 1 ; V_63 >= V_62 ; V_63 -- ) {
V_64 = * V_63 ;
if( V_64 == '"' ) {
if( V_63 - 1 == V_62 ) return NULL ;
* V_63 = 0 ;
return V_62 ;
}
if( isspace ( ( unsigned char ) V_64 ) ) * V_63 = 0 ;
else return V_62 ;
}
return NULL ;
}
static V_32 * F_39 ( char * V_62 , char * V_39 )
{
V_32 * V_65 ;
char * V_66 , * V_67 , * V_63 ;
int V_64 ;
if( V_62 ) {
if( ! ( V_66 = F_40 ( V_62 ) ) ) return NULL ;
for( V_63 = V_66 ; * V_63 ; V_63 ++ ) {
V_64 = * V_63 ;
if( isupper ( V_64 ) ) {
V_64 = tolower ( V_64 ) ;
* V_63 = V_64 ;
}
}
} else V_66 = NULL ;
if( V_39 ) {
if( ! ( V_67 = F_40 ( V_39 ) ) ) return NULL ;
for( V_63 = V_67 ; * V_63 ; V_63 ++ ) {
V_64 = * V_63 ;
if( isupper ( V_64 ) ) {
V_64 = tolower ( V_64 ) ;
* V_63 = V_64 ;
}
}
} else V_67 = NULL ;
V_65 = ( V_32 * ) F_41 ( sizeof( V_32 ) ) ;
if( ! V_65 ) return NULL ;
V_65 -> V_62 = V_66 ;
V_65 -> V_39 = V_67 ;
if( ! ( V_65 -> V_68 = F_42 ( V_69 ) ) ) return NULL ;
return V_65 ;
}
static int F_43 ( V_32 * V_65 , char * V_62 , char * V_39 )
{
char * V_66 , * V_67 , * V_63 ;
int V_64 ;
T_6 * V_70 ;
if( V_62 ) {
V_66 = F_40 ( V_62 ) ;
if( ! V_66 ) return 0 ;
for( V_63 = V_66 ; * V_63 ; V_63 ++ ) {
V_64 = * V_63 ;
if( isupper ( V_64 ) ) {
V_64 = tolower ( V_64 ) ;
* V_63 = V_64 ;
}
}
} else V_66 = NULL ;
if( V_39 ) {
V_67 = F_40 ( V_39 ) ;
if( ! V_67 ) return 0 ;
} else V_67 = NULL ;
V_70 = ( T_6 * ) F_41 ( sizeof( T_6 ) ) ;
if( ! V_70 ) return 0 ;
V_70 -> V_71 = V_66 ;
V_70 -> V_42 = V_67 ;
F_44 ( V_65 -> V_68 , V_70 ) ;
return 1 ;
}
static int F_45 ( const V_32 * const * V_72 ,
const V_32 * const * V_73 )
{
return ( strcmp ( ( * V_72 ) -> V_62 , ( * V_73 ) -> V_62 ) ) ;
}
static int V_69 ( const T_6 * const * V_72 ,
const T_6 * const * V_73 )
{
return ( strcmp ( ( * V_72 ) -> V_71 , ( * V_73 ) -> V_71 ) ) ;
}
static T_6 * F_23 ( V_32 * V_14 , char * V_62 )
{
T_6 V_74 ;
int V_75 ;
V_74 . V_71 = V_62 ;
V_75 = F_46 ( V_14 -> V_68 , & V_74 ) ;
if( V_75 < 0 ) return NULL ;
return F_47 ( V_14 -> V_68 , V_75 ) ;
}
static void V_40 ( V_32 * V_14 )
{
if( V_14 -> V_62 ) F_48 ( V_14 -> V_62 ) ;
if( V_14 -> V_39 ) F_48 ( V_14 -> V_39 ) ;
if( V_14 -> V_68 ) F_49 ( V_14 -> V_68 , V_76 ) ;
F_48 ( V_14 ) ;
}
static void V_76 ( T_6 * V_74 )
{
if( V_74 -> V_71 ) F_48 ( V_74 -> V_71 ) ;
if( V_74 -> V_42 ) F_48 ( V_74 -> V_42 ) ;
F_48 ( V_74 ) ;
}
static int F_50 ( char * line , int V_77 , char * V_78 , int V_79 )
{
if( V_77 == - 1 ) V_77 = strlen ( line ) ;
if( V_79 == - 1 ) V_79 = strlen ( V_78 ) ;
if( V_79 + 2 > V_77 ) return 0 ;
if( ! strncmp ( line , L_14 , 2 ) && ! strncmp ( line + 2 , V_78 , V_79 ) ) {
if( ! strncmp ( line + V_79 + 2 , L_14 , 2 ) ) return 2 ;
else return 1 ;
}
return 0 ;
}
static int F_34 ( char * V_55 , int * V_80 )
{
int V_54 = * V_80 ;
char * V_63 , V_64 ;
int V_81 = 0 ;
V_63 = V_55 + V_54 - 1 ;
for ( V_63 = V_55 + V_54 - 1 ; V_54 > 0 ; V_54 -- , V_63 -- )
{
V_64 = * V_63 ;
if ( V_64 == '\n' )
V_81 = 1 ;
else if ( V_64 != '\r' )
break;
}
* V_80 = V_54 ;
return V_81 ;
}
