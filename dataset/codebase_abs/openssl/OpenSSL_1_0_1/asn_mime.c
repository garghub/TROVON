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
int V_22 = 1 ;
if ( ! ( V_4 & V_23 ) || ( V_4 & V_24 ) )
{
F_4 ( V_17 , V_1 , V_4 ) ;
return 1 ;
}
if ( ! V_19 || ! V_19 -> V_25 )
{
F_3 ( V_26 ,
V_27 ) ;
return 0 ;
}
V_21 . V_1 = V_1 ;
V_21 . V_28 = NULL ;
V_21 . V_29 = NULL ;
if ( V_19 -> V_25 ( V_30 , & V_2 , V_5 , & V_21 ) <= 0 )
return 0 ;
F_4 ( V_17 , V_21 . V_28 , V_4 ) ;
if ( V_19 -> V_25 ( V_31 , & V_2 , V_5 , & V_21 ) <= 0 )
V_22 = 0 ;
while ( V_21 . V_28 != V_1 )
{
V_18 = F_6 ( V_21 . V_28 ) ;
F_7 ( V_21 . V_28 ) ;
V_21 . V_28 = V_18 ;
}
return V_22 ;
}
T_2 * F_18 ( T_1 * V_7 , T_1 * * V_32 , const T_3 * V_5 )
{
T_1 * V_33 ;
F_19 ( V_34 ) * V_35 = NULL ;
F_19 ( T_1 ) * V_36 = NULL ;
V_34 * V_14 ;
T_6 * V_37 ;
T_2 * V_2 ;
int V_38 ;
if( V_32 ) * V_32 = NULL ;
if ( ! ( V_35 = F_20 ( V_7 ) ) ) {
F_3 ( V_39 , V_40 ) ;
return NULL ;
}
if( ! ( V_14 = F_21 ( V_35 , L_3 ) ) || ! V_14 -> V_41 ) {
F_22 ( V_35 , V_42 ) ;
F_3 ( V_39 , V_43 ) ;
return NULL ;
}
if( ! strcmp ( V_14 -> V_41 , L_4 ) ) {
V_37 = F_23 ( V_14 , L_5 ) ;
if( ! V_37 || ! V_37 -> V_44 ) {
F_22 ( V_35 , V_42 ) ;
F_3 ( V_39 , V_45 ) ;
return NULL ;
}
V_38 = F_24 ( V_7 , V_37 -> V_44 , & V_36 ) ;
F_22 ( V_35 , V_42 ) ;
if( ! V_38 || ( F_25 ( V_36 ) != 2 ) ) {
F_3 ( V_39 , V_46 ) ;
F_26 ( V_36 , V_47 ) ;
return NULL ;
}
V_33 = F_27 ( V_36 , 1 ) ;
if ( ! ( V_35 = F_20 ( V_33 ) ) ) {
F_3 ( V_39 , V_48 ) ;
F_26 ( V_36 , V_47 ) ;
return NULL ;
}
if( ! ( V_14 = F_21 ( V_35 , L_3 ) ) ||
! V_14 -> V_41 ) {
F_22 ( V_35 , V_42 ) ;
F_3 ( V_39 , V_49 ) ;
return NULL ;
}
if( strcmp ( V_14 -> V_41 , L_6 ) &&
strcmp ( V_14 -> V_41 , L_7 ) ) {
F_3 ( V_39 , V_50 ) ;
F_28 ( 2 , L_8 , V_14 -> V_41 ) ;
F_22 ( V_35 , V_42 ) ;
F_26 ( V_36 , V_47 ) ;
return NULL ;
}
F_22 ( V_35 , V_42 ) ;
if( ! ( V_2 = F_15 ( V_33 , V_5 ) ) ) {
F_3 ( V_39 , V_51 ) ;
F_26 ( V_36 , V_47 ) ;
return NULL ;
}
if( V_32 ) {
* V_32 = F_27 ( V_36 , 0 ) ;
F_7 ( V_33 ) ;
F_29 ( V_36 ) ;
} else F_26 ( V_36 , V_47 ) ;
return V_2 ;
}
if ( strcmp ( V_14 -> V_41 , L_9 ) &&
strcmp ( V_14 -> V_41 , L_10 ) ) {
F_3 ( V_39 , V_52 ) ;
F_28 ( 2 , L_8 , V_14 -> V_41 ) ;
F_22 ( V_35 , V_42 ) ;
return NULL ;
}
F_22 ( V_35 , V_42 ) ;
if( ! ( V_2 = F_15 ( V_7 , V_5 ) ) ) {
F_3 ( V_39 , V_53 ) ;
return NULL ;
}
return V_2 ;
}
int F_4 ( T_1 * V_3 , T_1 * V_1 , int V_4 )
{
T_1 * V_54 ;
char V_55 ;
int V_56 ;
char V_57 [ V_58 ] ;
V_54 = F_10 ( F_30 () ) ;
if ( ! V_54 )
return 0 ;
V_1 = F_12 ( V_54 , V_1 ) ;
if( V_4 & V_59 )
{
while( ( V_56 = F_31 ( V_3 , V_57 , V_58 ) ) > 0 )
F_32 ( V_1 , V_57 , V_56 ) ;
}
else
{
if( V_4 & V_60 )
F_14 ( V_1 , L_11 ) ;
while ( ( V_56 = F_33 ( V_3 , V_57 , V_58 ) ) > 0 )
{
V_55 = F_34 ( V_57 , & V_56 ) ;
if ( V_56 )
F_32 ( V_1 , V_57 , V_56 ) ;
if( V_55 ) F_32 ( V_1 , L_12 , 2 ) ;
}
}
( void ) F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
F_7 ( V_54 ) ;
return 1 ;
}
int F_35 ( T_1 * V_3 , T_1 * V_1 )
{
char V_61 [ 4096 ] ;
int V_56 ;
F_19 ( V_34 ) * V_35 ;
V_34 * V_14 ;
if ( ! ( V_35 = F_20 ( V_3 ) ) ) {
F_3 ( V_62 , V_40 ) ;
return 0 ;
}
if( ! ( V_14 = F_21 ( V_35 , L_3 ) ) || ! V_14 -> V_41 ) {
F_3 ( V_62 , V_63 ) ;
F_22 ( V_35 , V_42 ) ;
return 0 ;
}
if ( strcmp ( V_14 -> V_41 , L_13 ) ) {
F_3 ( V_62 , V_52 ) ;
F_28 ( 2 , L_8 , V_14 -> V_41 ) ;
F_22 ( V_35 , V_42 ) ;
return 0 ;
}
F_22 ( V_35 , V_42 ) ;
while ( ( V_56 = F_31 ( V_3 , V_61 , sizeof( V_61 ) ) ) > 0 )
F_32 ( V_1 , V_61 , V_56 ) ;
if ( V_56 < 0 )
return 0 ;
return 1 ;
}
char * F_36 ( char * V_64 )
{
return F_37 ( F_38 ( V_64 ) ) ;
}
static char * F_38 ( char * V_64 )
{
char * V_65 , V_66 ;
for( V_65 = V_64 ; ( V_66 = * V_65 ) ; V_65 ++ ) {
if( V_66 == '"' ) {
if( V_65 [ 1 ] ) return V_65 + 1 ;
return NULL ;
}
if( ! isspace ( ( unsigned char ) V_66 ) ) return V_65 ;
}
return NULL ;
}
static char * F_37 ( char * V_64 )
{
char * V_65 , V_66 ;
if( ! V_64 ) return NULL ;
for( V_65 = V_64 + strlen ( V_64 ) - 1 ; V_65 >= V_64 ; V_65 -- ) {
V_66 = * V_65 ;
if( V_66 == '"' ) {
if( V_65 - 1 == V_64 ) return NULL ;
* V_65 = 0 ;
return V_64 ;
}
if( isspace ( ( unsigned char ) V_66 ) ) * V_65 = 0 ;
else return V_64 ;
}
return NULL ;
}
static V_34 * F_39 ( char * V_64 , char * V_41 )
{
V_34 * V_67 ;
char * V_68 , * V_69 , * V_65 ;
int V_66 ;
if( V_64 ) {
if( ! ( V_68 = F_40 ( V_64 ) ) ) return NULL ;
for( V_65 = V_68 ; * V_65 ; V_65 ++ ) {
V_66 = ( unsigned char ) * V_65 ;
if( isupper ( V_66 ) ) {
V_66 = tolower ( V_66 ) ;
* V_65 = V_66 ;
}
}
} else V_68 = NULL ;
if( V_41 ) {
if( ! ( V_69 = F_40 ( V_41 ) ) ) return NULL ;
for( V_65 = V_69 ; * V_65 ; V_65 ++ ) {
V_66 = ( unsigned char ) * V_65 ;
if( isupper ( V_66 ) ) {
V_66 = tolower ( V_66 ) ;
* V_65 = V_66 ;
}
}
} else V_69 = NULL ;
V_67 = ( V_34 * ) F_41 ( sizeof( V_34 ) ) ;
if( ! V_67 ) return NULL ;
V_67 -> V_64 = V_68 ;
V_67 -> V_41 = V_69 ;
if( ! ( V_67 -> V_70 = F_42 ( V_71 ) ) ) return NULL ;
return V_67 ;
}
static int F_43 ( V_34 * V_67 , char * V_64 , char * V_41 )
{
char * V_68 , * V_69 , * V_65 ;
int V_66 ;
T_6 * V_72 ;
if( V_64 ) {
V_68 = F_40 ( V_64 ) ;
if( ! V_68 ) return 0 ;
for( V_65 = V_68 ; * V_65 ; V_65 ++ ) {
V_66 = ( unsigned char ) * V_65 ;
if( isupper ( V_66 ) ) {
V_66 = tolower ( V_66 ) ;
* V_65 = V_66 ;
}
}
} else V_68 = NULL ;
if( V_41 ) {
V_69 = F_40 ( V_41 ) ;
if( ! V_69 ) return 0 ;
} else V_69 = NULL ;
V_72 = ( T_6 * ) F_41 ( sizeof( T_6 ) ) ;
if( ! V_72 ) return 0 ;
V_72 -> V_73 = V_68 ;
V_72 -> V_44 = V_69 ;
F_44 ( V_67 -> V_70 , V_72 ) ;
return 1 ;
}
static int F_45 ( const V_34 * const * V_74 ,
const V_34 * const * V_75 )
{
if ( ! ( * V_74 ) -> V_64 || ! ( * V_75 ) -> V_64 )
return ! ! ( * V_74 ) -> V_64 - ! ! ( * V_75 ) -> V_64 ;
return ( strcmp ( ( * V_74 ) -> V_64 , ( * V_75 ) -> V_64 ) ) ;
}
static int V_71 ( const T_6 * const * V_74 ,
const T_6 * const * V_75 )
{
if ( ! ( * V_74 ) -> V_73 || ! ( * V_75 ) -> V_73 )
return ! ! ( * V_74 ) -> V_73 - ! ! ( * V_75 ) -> V_73 ;
return ( strcmp ( ( * V_74 ) -> V_73 , ( * V_75 ) -> V_73 ) ) ;
}
static T_6 * F_23 ( V_34 * V_14 , char * V_64 )
{
T_6 V_76 ;
int V_77 ;
V_76 . V_73 = V_64 ;
V_77 = F_46 ( V_14 -> V_70 , & V_76 ) ;
if( V_77 < 0 ) return NULL ;
return F_47 ( V_14 -> V_70 , V_77 ) ;
}
static void V_42 ( V_34 * V_14 )
{
if( V_14 -> V_64 ) F_48 ( V_14 -> V_64 ) ;
if( V_14 -> V_41 ) F_48 ( V_14 -> V_41 ) ;
if( V_14 -> V_70 ) F_49 ( V_14 -> V_70 , V_78 ) ;
F_48 ( V_14 ) ;
}
static void V_78 ( T_6 * V_76 )
{
if( V_76 -> V_73 ) F_48 ( V_76 -> V_73 ) ;
if( V_76 -> V_44 ) F_48 ( V_76 -> V_44 ) ;
F_48 ( V_76 ) ;
}
static int F_50 ( char * line , int V_79 , char * V_80 , int V_81 )
{
if( V_79 == - 1 ) V_79 = strlen ( line ) ;
if( V_81 == - 1 ) V_81 = strlen ( V_80 ) ;
if( V_81 + 2 > V_79 ) return 0 ;
if( ! strncmp ( line , L_14 , 2 ) && ! strncmp ( line + 2 , V_80 , V_81 ) ) {
if( ! strncmp ( line + V_81 + 2 , L_14 , 2 ) ) return 2 ;
else return 1 ;
}
return 0 ;
}
static int F_34 ( char * V_57 , int * V_82 )
{
int V_56 = * V_82 ;
char * V_65 , V_66 ;
int V_83 = 0 ;
V_65 = V_57 + V_56 - 1 ;
for ( V_65 = V_57 + V_56 - 1 ; V_56 > 0 ; V_56 -- , V_65 -- )
{
V_66 = * V_65 ;
if ( V_66 == '\n' )
V_83 = 1 ;
else if ( V_66 != '\r' )
break;
}
* V_82 = V_56 ;
return V_83 ;
}
