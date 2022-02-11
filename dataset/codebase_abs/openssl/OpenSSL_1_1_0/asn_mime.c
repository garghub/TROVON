int F_1 ( T_1 * V_1 , T_2 * V_2 , T_1 * V_3 , int V_4 ,
const T_3 * V_5 )
{
if ( V_4 & V_6 ) {
T_1 * V_7 , * V_8 ;
V_7 = F_2 ( V_1 , V_2 , V_5 ) ;
if ( ! V_7 ) {
F_3 ( V_9 , V_10 ) ;
return 0 ;
}
F_4 ( V_3 , V_7 , V_4 ) ;
( void ) F_5 ( V_7 ) ;
do {
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
if ( V_11 == NULL ) {
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
const char * V_14 , const T_3 * V_5 )
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
if ( ( V_11 = F_10 ( F_11 () ) ) == NULL ) {
F_3 ( V_15 , V_10 ) ;
return 0 ;
}
V_7 = F_12 ( V_11 , V_7 ) ;
V_2 = F_16 ( V_5 , V_7 , NULL ) ;
if ( ! V_2 )
F_3 ( V_15 , V_16 ) ;
( void ) F_5 ( V_7 ) ;
F_6 ( V_7 ) ;
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
if ( ! ( V_4 & V_23 ) || ( V_4 & V_24 ) ) {
F_4 ( V_17 , V_1 , V_4 ) ;
return 1 ;
}
if ( ! V_19 || ! V_19 -> V_25 ) {
F_3 ( V_26 , V_27 ) ;
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
while ( V_21 . V_28 != V_1 ) {
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
if ( V_32 )
* V_32 = NULL ;
if ( ( V_35 = F_20 ( V_7 ) ) == NULL ) {
F_3 ( V_39 , V_40 ) ;
return NULL ;
}
if ( ( V_14 = F_21 ( V_35 , L_3 ) ) == NULL
|| V_14 -> V_41 == NULL ) {
F_22 ( V_35 , V_42 ) ;
F_3 ( V_39 , V_43 ) ;
return NULL ;
}
if ( strcmp ( V_14 -> V_41 , L_4 ) == 0 ) {
V_37 = F_23 ( V_14 , L_5 ) ;
if ( ! V_37 || ! V_37 -> V_44 ) {
F_22 ( V_35 , V_42 ) ;
F_3 ( V_39 , V_45 ) ;
return NULL ;
}
V_38 = F_24 ( V_7 , V_37 -> V_44 , & V_36 ) ;
F_22 ( V_35 , V_42 ) ;
if ( ! V_38 || ( F_25 ( V_36 ) != 2 ) ) {
F_3 ( V_39 , V_46 ) ;
F_26 ( V_36 , V_47 ) ;
return NULL ;
}
V_33 = F_27 ( V_36 , 1 ) ;
if ( ( V_35 = F_20 ( V_33 ) ) == NULL ) {
F_3 ( V_39 , V_48 ) ;
F_26 ( V_36 , V_47 ) ;
return NULL ;
}
if ( ( V_14 = F_21 ( V_35 , L_3 ) ) == NULL
|| V_14 -> V_41 == NULL ) {
F_22 ( V_35 , V_42 ) ;
F_3 ( V_39 , V_49 ) ;
return NULL ;
}
if ( strcmp ( V_14 -> V_41 , L_6 ) &&
strcmp ( V_14 -> V_41 , L_7 ) ) {
F_3 ( V_39 , V_50 ) ;
F_28 ( 2 , L_8 , V_14 -> V_41 ) ;
F_22 ( V_35 , V_42 ) ;
F_26 ( V_36 , V_47 ) ;
return NULL ;
}
F_22 ( V_35 , V_42 ) ;
if ( ( V_2 = F_15 ( V_33 , V_5 ) ) == NULL ) {
F_3 ( V_39 , V_51 ) ;
F_26 ( V_36 , V_47 ) ;
return NULL ;
}
if ( V_32 ) {
* V_32 = F_27 ( V_36 , 0 ) ;
F_7 ( V_33 ) ;
F_29 ( V_36 ) ;
} else
F_26 ( V_36 , V_47 ) ;
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
if ( ( V_2 = F_15 ( V_7 , V_5 ) ) == NULL ) {
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
if ( V_54 == NULL )
return 0 ;
V_1 = F_12 ( V_54 , V_1 ) ;
if ( V_4 & V_59 ) {
while ( ( V_56 = F_31 ( V_3 , V_57 , V_58 ) ) > 0 )
F_32 ( V_1 , V_57 , V_56 ) ;
} else {
int V_60 = 0 ;
if ( V_4 & V_61 )
F_14 ( V_1 , L_11 ) ;
while ( ( V_56 = F_33 ( V_3 , V_57 , V_58 ) ) > 0 ) {
V_55 = F_34 ( V_57 , & V_56 , V_4 ) ;
if ( V_56 ) {
if ( V_4 & V_62 ) {
int V_63 ;
for ( V_63 = 0 ; V_63 < V_60 ; V_63 ++ )
F_32 ( V_1 , L_12 , 2 ) ;
V_60 = 0 ;
}
F_32 ( V_1 , V_57 , V_56 ) ;
if ( V_55 )
F_32 ( V_1 , L_12 , 2 ) ;
} else if ( V_4 & V_62 )
V_60 ++ ;
else if ( V_55 )
F_32 ( V_1 , L_12 , 2 ) ;
}
}
( void ) F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
F_7 ( V_54 ) ;
return 1 ;
}
int F_35 ( T_1 * V_3 , T_1 * V_1 )
{
char V_64 [ 4096 ] ;
int V_56 ;
F_19 ( V_34 ) * V_35 ;
V_34 * V_14 ;
if ( ( V_35 = F_20 ( V_3 ) ) == NULL ) {
F_3 ( V_65 , V_40 ) ;
return 0 ;
}
if ( ( V_14 = F_21 ( V_35 , L_3 ) ) == NULL
|| V_14 -> V_41 == NULL ) {
F_3 ( V_65 , V_66 ) ;
F_22 ( V_35 , V_42 ) ;
return 0 ;
}
if ( strcmp ( V_14 -> V_41 , L_13 ) ) {
F_3 ( V_65 , V_52 ) ;
F_28 ( 2 , L_8 , V_14 -> V_41 ) ;
F_22 ( V_35 , V_42 ) ;
return 0 ;
}
F_22 ( V_35 , V_42 ) ;
while ( ( V_56 = F_31 ( V_3 , V_64 , sizeof( V_64 ) ) ) > 0 )
F_32 ( V_1 , V_64 , V_56 ) ;
if ( V_56 < 0 )
return 0 ;
return 1 ;
}
char * F_36 ( char * V_67 )
{
return F_37 ( F_38 ( V_67 ) ) ;
}
static char * F_38 ( char * V_67 )
{
char * V_68 , V_69 ;
for ( V_68 = V_67 ; ( V_69 = * V_68 ) ; V_68 ++ ) {
if ( V_69 == '"' ) {
if ( V_68 [ 1 ] )
return V_68 + 1 ;
return NULL ;
}
if ( ! isspace ( ( unsigned char ) V_69 ) )
return V_68 ;
}
return NULL ;
}
static char * F_37 ( char * V_67 )
{
char * V_68 , V_69 ;
if ( ! V_67 )
return NULL ;
for ( V_68 = V_67 + strlen ( V_67 ) - 1 ; V_68 >= V_67 ; V_68 -- ) {
V_69 = * V_68 ;
if ( V_69 == '"' ) {
if ( V_68 - 1 == V_67 )
return NULL ;
* V_68 = 0 ;
return V_67 ;
}
if ( isspace ( ( unsigned char ) V_69 ) )
* V_68 = 0 ;
else
return V_67 ;
}
return NULL ;
}
static V_34 * F_39 ( const char * V_67 , const char * V_41 )
{
V_34 * V_70 = NULL ;
char * V_71 = NULL , * V_72 = NULL , * V_68 ;
int V_69 ;
if ( V_67 ) {
if ( ( V_71 = F_40 ( V_67 ) ) == NULL )
return NULL ;
for ( V_68 = V_71 ; * V_68 ; V_68 ++ ) {
V_69 = ( unsigned char ) * V_68 ;
if ( isupper ( V_69 ) ) {
V_69 = tolower ( V_69 ) ;
* V_68 = V_69 ;
}
}
}
if ( V_41 ) {
if ( ( V_72 = F_40 ( V_41 ) ) == NULL )
goto V_73;
for ( V_68 = V_72 ; * V_68 ; V_68 ++ ) {
V_69 = ( unsigned char ) * V_68 ;
if ( isupper ( V_69 ) ) {
V_69 = tolower ( V_69 ) ;
* V_68 = V_69 ;
}
}
}
V_70 = F_41 ( sizeof( * V_70 ) ) ;
if ( V_70 == NULL )
goto V_73;
V_70 -> V_67 = V_71 ;
V_70 -> V_41 = V_72 ;
if ( ( V_70 -> V_74 = F_42 ( V_75 ) ) == NULL )
goto V_73;
return V_70 ;
V_73:
F_43 ( V_71 ) ;
F_43 ( V_72 ) ;
F_43 ( V_70 ) ;
return NULL ;
}
static int F_44 ( V_34 * V_70 , const char * V_67 , const char * V_41 )
{
char * V_71 = NULL , * V_72 = NULL , * V_68 ;
int V_69 ;
T_6 * V_76 = NULL ;
if ( V_67 ) {
V_71 = F_40 ( V_67 ) ;
if ( ! V_71 )
goto V_73;
for ( V_68 = V_71 ; * V_68 ; V_68 ++ ) {
V_69 = ( unsigned char ) * V_68 ;
if ( isupper ( V_69 ) ) {
V_69 = tolower ( V_69 ) ;
* V_68 = V_69 ;
}
}
}
if ( V_41 ) {
V_72 = F_40 ( V_41 ) ;
if ( ! V_72 )
goto V_73;
}
V_76 = F_41 ( sizeof( * V_76 ) ) ;
if ( V_76 == NULL )
goto V_73;
V_76 -> V_77 = V_71 ;
V_76 -> V_44 = V_72 ;
if ( ! F_45 ( V_70 -> V_74 , V_76 ) )
goto V_73;
return 1 ;
V_73:
F_43 ( V_71 ) ;
F_43 ( V_72 ) ;
F_43 ( V_76 ) ;
return 0 ;
}
static int F_46 ( const V_34 * const * V_78 ,
const V_34 * const * V_79 )
{
if ( ! ( * V_78 ) -> V_67 || ! ( * V_79 ) -> V_67 )
return ! ! ( * V_78 ) -> V_67 - ! ! ( * V_79 ) -> V_67 ;
return ( strcmp ( ( * V_78 ) -> V_67 , ( * V_79 ) -> V_67 ) ) ;
}
static int V_75 ( const T_6 * const * V_78 ,
const T_6 * const * V_79 )
{
if ( ! ( * V_78 ) -> V_77 || ! ( * V_79 ) -> V_77 )
return ! ! ( * V_78 ) -> V_77 - ! ! ( * V_79 ) -> V_77 ;
return ( strcmp ( ( * V_78 ) -> V_77 , ( * V_79 ) -> V_77 ) ) ;
}
static T_6 * F_23 ( V_34 * V_14 , const char * V_67 )
{
T_6 V_80 ;
int V_81 ;
V_80 . V_77 = ( char * ) V_67 ;
V_80 . V_44 = NULL ;
V_81 = F_47 ( V_14 -> V_74 , & V_80 ) ;
if ( V_81 < 0 )
return NULL ;
return F_48 ( V_14 -> V_74 , V_81 ) ;
}
static void V_42 ( V_34 * V_14 )
{
if ( V_14 == NULL )
return;
F_43 ( V_14 -> V_67 ) ;
F_43 ( V_14 -> V_41 ) ;
if ( V_14 -> V_74 )
F_49 ( V_14 -> V_74 , V_82 ) ;
F_43 ( V_14 ) ;
}
static void V_82 ( T_6 * V_80 )
{
F_43 ( V_80 -> V_77 ) ;
F_43 ( V_80 -> V_44 ) ;
F_43 ( V_80 ) ;
}
static int F_50 ( char * line , int V_83 , const char * V_84 , int V_85 )
{
if ( V_83 == - 1 )
V_83 = strlen ( line ) ;
if ( V_85 == - 1 )
V_85 = strlen ( V_84 ) ;
if ( V_85 + 2 > V_83 )
return 0 ;
if ( ( strncmp ( line , L_14 , 2 ) == 0 )
&& strncmp ( line + 2 , V_84 , V_85 ) == 0 ) {
if ( strncmp ( line + V_85 + 2 , L_14 , 2 ) == 0 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_34 ( char * V_57 , int * V_86 , int V_4 )
{
int V_56 = * V_86 ;
char * V_68 , V_69 ;
int V_87 = 0 ;
V_68 = V_57 + V_56 - 1 ;
for ( V_68 = V_57 + V_56 - 1 ; V_56 > 0 ; V_56 -- , V_68 -- ) {
V_69 = * V_68 ;
if ( V_69 == '\n' )
V_87 = 1 ;
else if ( V_87 && V_4 & V_62 && V_69 < 33 )
continue;
else if ( V_69 != '\r' )
break;
}
* V_86 = V_56 ;
return V_87 ;
}
