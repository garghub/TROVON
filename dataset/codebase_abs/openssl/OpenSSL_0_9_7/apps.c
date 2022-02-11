int F_1 ( char * V_1 , int * V_2 , char * * V_3 [] )
{
T_1 * V_4 ;
int V_5 , V_6 ;
unsigned int V_7 ;
static char * V_8 = NULL ;
static char * * V_9 = NULL ;
char * V_10 ;
struct V_11 V_12 ;
if ( V_11 ( V_1 , & V_12 ) < 0 ) return ( 0 ) ;
V_4 = fopen ( V_1 , L_1 ) ;
if ( V_4 == NULL )
return ( 0 ) ;
* V_2 = 0 ;
* V_3 = NULL ;
V_7 = ( unsigned int ) V_12 . V_13 ;
if ( V_8 != NULL ) F_2 ( V_8 ) ;
V_8 = ( char * ) F_3 ( V_7 + 1 ) ;
if ( V_8 == NULL ) return ( 0 ) ;
V_7 = fread ( V_8 , 1 , V_7 , V_4 ) ;
if ( V_7 <= 1 ) return ( 0 ) ;
V_8 [ V_7 ] = '\0' ;
V_6 = 0 ;
for ( V_10 = V_8 ; * V_10 ; V_10 ++ )
if ( * V_10 == '\n' ) V_6 ++ ;
if ( V_9 != NULL ) F_2 ( V_9 ) ;
V_9 = ( char * * ) F_3 ( sizeof( char * ) * ( V_6 * 2 ) ) ;
* V_3 = V_9 ;
V_5 = 0 ;
V_10 = V_8 ;
for (; ; )
{
if ( ! * V_10 ) break;
if ( * V_10 == '#' )
{
while ( * V_10 && ( * V_10 != '\n' ) ) V_10 ++ ;
continue;
}
* ( V_9 ++ ) = V_10 ;
V_5 ++ ;
while ( * V_10 && ( ( * V_10 != ' ' ) && ( * V_10 != '\t' ) && ( * V_10 != '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 ) break;
if ( * V_10 == '\n' )
{
* ( V_10 ++ ) = '\0' ;
continue;
}
V_10 ++ ;
while ( * V_10 && ( ( * V_10 == ' ' ) || ( * V_10 == '\t' ) || ( * V_10 == '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 ) break;
if ( * V_10 == '\n' )
{
V_10 ++ ;
continue;
}
* ( V_9 ++ ) = V_10 ++ ;
V_5 ++ ;
while ( * V_10 && ( * V_10 != '\n' ) ) V_10 ++ ;
if ( ! * V_10 ) break;
* ( V_10 ++ ) = '\0' ;
}
* V_2 = V_5 ;
return ( 1 ) ;
}
int F_4 ( char * V_14 )
{
if ( ( * V_14 == 'D' ) || ( * V_14 == 'd' ) )
return ( V_15 ) ;
else if ( ( * V_14 == 'T' ) || ( * V_14 == 't' ) )
return ( V_16 ) ;
else if ( ( * V_14 == 'P' ) || ( * V_14 == 'p' ) )
return ( V_17 ) ;
else if ( ( * V_14 == 'N' ) || ( * V_14 == 'n' ) )
return ( V_18 ) ;
else if ( ( * V_14 == 'S' ) || ( * V_14 == 's' ) )
return ( V_19 ) ;
else if ( ( * V_14 == '1' )
|| ( strcmp ( V_14 , L_2 ) == 0 ) || ( strcmp ( V_14 , L_3 ) == 0 )
|| ( strcmp ( V_14 , L_4 ) == 0 ) || ( strcmp ( V_14 , L_5 ) == 0 ) )
return ( V_20 ) ;
else if ( ( * V_14 == 'E' ) || ( * V_14 == 'e' ) )
return ( V_21 ) ;
else
return ( V_22 ) ;
}
void F_5 ( char * V_23 , char * V_24 , int V_25 )
{
int V_6 , V_26 ;
char * V_10 = NULL ;
V_26 = strlen ( V_23 ) ;
for ( V_6 = V_26 - 1 ; V_6 > 0 ; V_6 -- )
{
if ( ( V_23 [ V_6 ] == '/' ) || ( V_23 [ V_6 ] == '\\' ) || ( V_23 [ V_6 ] == ':' ) )
{
V_10 = & ( V_23 [ V_6 + 1 ] ) ;
break;
}
}
if ( V_10 == NULL )
V_10 = V_23 ;
V_26 = strlen ( V_10 ) ;
if ( ( V_26 > 4 ) && ( V_10 [ V_26 - 4 ] == '.' ) &&
( ( V_10 [ V_26 - 3 ] == 'e' ) || ( V_10 [ V_26 - 3 ] == 'E' ) ) &&
( ( V_10 [ V_26 - 2 ] == 'x' ) || ( V_10 [ V_26 - 2 ] == 'X' ) ) &&
( ( V_10 [ V_26 - 1 ] == 'e' ) || ( V_10 [ V_26 - 1 ] == 'E' ) ) )
V_26 -= 4 ;
if ( V_26 > V_25 - 1 )
V_26 = V_25 - 1 ;
for ( V_6 = 0 ; V_6 < V_26 ; V_6 ++ )
{
if ( ( V_10 [ V_6 ] >= 'A' ) && ( V_10 [ V_6 ] <= 'Z' ) )
V_24 [ V_6 ] = V_10 [ V_6 ] - 'A' + 'a' ;
else
V_24 [ V_6 ] = V_10 [ V_6 ] ;
}
V_24 [ V_26 ] = '\0' ;
}
void F_5 ( char * V_23 , char * V_24 , int V_25 )
{
char * V_10 = V_23 , * V_27 ;
char * V_28 = L_6 ;
while( * V_28 != '\0' )
{
V_27 = strrchr ( V_10 , * V_28 ) ;
if ( V_27 > V_10 )
V_10 = V_27 + 1 ;
V_28 ++ ;
}
V_27 = strrchr ( V_10 , '.' ) ;
if ( V_27 == NULL )
V_27 = V_10 + strlen ( V_10 ) ;
strncpy ( V_24 , V_10 , V_25 - 1 ) ;
if ( V_27 - V_10 >= V_25 )
{
V_24 [ V_25 - 1 ] = '\0' ;
}
else
{
V_24 [ V_27 - V_10 ] = '\0' ;
}
}
void F_5 ( char * V_23 , char * V_24 , int V_25 )
{
char * V_10 ;
V_10 = strrchr ( V_23 , '/' ) ;
if ( V_10 != NULL )
V_10 ++ ;
else
V_10 = V_23 ;
F_6 ( V_24 , V_10 , V_25 ) ;
}
int F_7 ( char * V_29 , char * V_30 )
{
#ifndef F_8
if( ( remove ( V_30 ) != 0 ) && ( V_31 != V_32 ) )
return - 1 ;
#undef rename
return rename ( V_29 , V_30 ) ;
#else
{
BOOL V_33 = FALSE ;
T_2 * V_34 ;
T_2 * V_35 ;
int V_6 ;
V_34 = malloc ( ( strlen ( V_29 ) + 1 ) * 2 ) ;
V_35 = malloc ( ( strlen ( V_30 ) + 1 ) * 2 ) ;
if ( V_34 != NULL && V_35 != NULL )
{
for ( V_6 = 0 ; V_6 < ( int ) strlen ( V_29 ) + 1 ; V_6 ++ )
V_34 [ V_6 ] = ( short ) V_29 [ V_6 ] ;
for ( V_6 = 0 ; V_6 < ( int ) strlen ( V_30 ) + 1 ; V_6 ++ )
V_35 [ V_6 ] = ( short ) V_30 [ V_6 ] ;
V_33 = F_9 ( V_34 , V_35 ) ;
}
if ( V_34 != NULL )
free ( V_34 ) ;
if ( V_35 != NULL )
free ( V_35 ) ;
return V_33 ;
}
#endif
}
int F_10 ( const char * V_36 , const char * V_37 )
{
while ( * V_36 && * V_37 )
{
int V_38 = toupper ( * V_36 ) - toupper ( * V_37 ) ;
if ( V_38 ) return V_38 < 0 ? - 1 : 1 ;
}
if ( * V_36 )
return 1 ;
if ( * V_37 )
return - 1 ;
return 0 ;
}
int F_11 ( ARGS * V_9 , char * V_8 , int * V_2 , char * * V_3 [] )
{
int V_5 , V_7 , V_6 ;
char * V_10 ;
* V_2 = 0 ;
* V_3 = NULL ;
V_7 = strlen ( V_8 ) ;
V_6 = 0 ;
if ( V_9 -> V_39 == 0 )
{
V_9 -> V_39 = 20 ;
V_9 -> V_40 = ( char * * ) F_3 ( sizeof( char * ) * V_9 -> V_39 ) ;
}
for ( V_6 = 0 ; V_6 < V_9 -> V_39 ; V_6 ++ )
V_9 -> V_40 [ V_6 ] = NULL ;
V_5 = 0 ;
V_10 = V_8 ;
for (; ; )
{
if ( ! * V_10 ) break;
while ( * V_10 && ( ( * V_10 == ' ' ) || ( * V_10 == '\t' ) || ( * V_10 == '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 ) break;
if ( V_5 >= V_9 -> V_39 )
{
V_9 -> V_39 += 20 ;
V_9 -> V_40 = ( char * * ) F_12 ( V_9 -> V_40 ,
sizeof( char * ) * V_9 -> V_39 ) ;
if ( V_2 == 0 ) return ( 0 ) ;
}
V_9 -> V_40 [ V_5 ++ ] = V_10 ;
if ( ( * V_10 == '\'' ) || ( * V_10 == '\"' ) )
{
V_6 = * ( V_10 ++ ) ;
V_9 -> V_40 [ V_5 - 1 ] ++ ;
while ( * V_10 && ( * V_10 != V_6 ) )
V_10 ++ ;
* V_10 = '\0' ;
}
else
{
while ( * V_10 && ( ( * V_10 != ' ' ) &&
( * V_10 != '\t' ) && ( * V_10 != '\n' ) ) )
V_10 ++ ;
if ( * V_10 == '\0' )
V_10 -- ;
else
* V_10 = '\0' ;
}
V_10 ++ ;
}
* V_2 = V_5 ;
* V_3 = V_9 -> V_40 ;
return ( 1 ) ;
}
int F_13 ( long V_41 )
{
return ( 1 ) ;
}
int F_14 ( T_3 * V_24 , T_4 * V_42 )
{
char * V_10 ;
V_10 = F_15 ( F_16 ( V_42 ) , NULL , 0 ) ;
F_17 ( V_24 , L_7 ) ;
F_17 ( V_24 , V_10 ) ;
F_2 ( V_10 ) ;
V_10 = F_15 ( F_18 ( V_42 ) , NULL , 0 ) ;
F_17 ( V_24 , L_8 ) ;
F_17 ( V_24 , V_10 ) ;
F_17 ( V_24 , L_9 ) ;
F_2 ( V_10 ) ;
return 0 ;
}
static int F_19 ( T_5 * V_43 )
{
return F_20 ( F_21 () ) ( V_43 ) ;
}
static int F_22 ( T_5 * V_43 , T_6 * V_44 )
{
if ( F_23 ( V_44 ) & V_45
&& F_24 ( V_43 ) )
{
switch( F_25 ( V_44 ) )
{
case V_46 :
case V_47 :
{
const char * V_48 =
( ( V_49 * ) F_24 ( V_43 ) ) -> V_48 ;
if ( V_48 [ 0 ] != '\0' )
{
F_26 ( V_43 , V_44 , V_48 ) ;
return 1 ;
}
}
default:
break;
}
}
return F_27 ( F_21 () ) ( V_43 , V_44 ) ;
}
static int F_28 ( T_5 * V_43 , T_6 * V_44 )
{
if ( F_23 ( V_44 ) & V_45
&& F_24 ( V_43 ) )
{
switch( F_25 ( V_44 ) )
{
case V_46 :
case V_47 :
{
const char * V_48 =
( ( V_49 * ) F_24 ( V_43 ) ) -> V_48 ;
if ( V_48 [ 0 ] != '\0' )
return 1 ;
}
default:
break;
}
}
return F_29 ( F_21 () ) ( V_43 , V_44 ) ;
}
static int F_30 ( T_5 * V_43 )
{
return F_31 ( F_21 () ) ( V_43 ) ;
}
int F_32 ( void )
{
V_50 = F_33 ( L_10 ) ;
F_34 ( V_50 , F_19 ) ;
F_35 ( V_50 , F_22 ) ;
F_36 ( V_50 , F_28 ) ;
F_37 ( V_50 , F_30 ) ;
return 0 ;
}
void F_38 ( void )
{
if( V_50 )
{
F_39 ( V_50 ) ;
V_50 = NULL ;
}
}
int F_40 ( char * V_8 , int V_51 , int V_52 ,
V_49 * V_53 )
{
T_5 * V_43 = NULL ;
int V_38 = 0 ;
const char * V_54 = NULL ;
const char * V_48 = NULL ;
V_49 * V_55 = ( V_49 * ) V_53 ;
if ( V_55 )
{
if ( V_55 -> V_48 )
V_48 = V_55 -> V_48 ;
if ( V_55 -> V_54 )
V_54 = V_55 -> V_54 ;
}
if ( V_48 )
{
V_38 = strlen ( V_48 ) ;
if ( V_38 > V_51 )
V_38 = V_51 ;
memcpy ( V_8 , V_48 , V_38 ) ;
return V_38 ;
}
V_43 = F_41 ( V_50 ) ;
if ( V_43 )
{
int V_56 = 0 ;
char * V_57 = NULL ;
int V_58 = 0 ;
char * V_59 = NULL ;
V_59 = F_42 ( V_43 , L_11 ,
V_55 -> V_54 ) ;
V_58 |= V_45 ;
F_43 ( V_43 , V_60 , 1 , 0 , 0 ) ;
if ( V_56 >= 0 )
V_56 = F_44 ( V_43 , V_59 , V_58 , V_8 ,
V_61 , V_62 - 1 ) ;
if ( V_56 >= 0 && V_52 )
{
V_57 = ( char * ) F_3 ( V_51 ) ;
V_56 = F_45 ( V_43 , V_59 , V_58 , V_57 ,
V_61 , V_62 - 1 , V_8 ) ;
}
if ( V_56 >= 0 )
do
{
V_56 = F_46 ( V_43 ) ;
}
while ( V_56 < 0 && F_43 ( V_43 , V_63 , 0 , 0 , 0 ) );
if ( V_57 )
{
F_47 ( V_57 , ( unsigned int ) V_51 ) ;
F_2 ( V_57 ) ;
}
if ( V_56 >= 0 )
V_38 = strlen ( V_8 ) ;
if ( V_56 == - 1 )
{
F_48 ( V_64 , L_12 ) ;
F_49 ( V_64 ) ;
F_47 ( V_8 , ( unsigned int ) V_51 ) ;
V_38 = 0 ;
}
if ( V_56 == - 2 )
{
F_48 ( V_64 , L_13 ) ;
F_47 ( V_8 , ( unsigned int ) V_51 ) ;
V_38 = 0 ;
}
F_50 ( V_43 ) ;
F_2 ( V_59 ) ;
}
return V_38 ;
}
int F_51 ( T_3 * V_65 , char * V_66 , char * V_67 , char * * V_68 , char * * V_69 )
{
int V_70 ;
if( ! V_67 || ! V_66 || strcmp ( V_66 , V_67 ) ) V_70 = 0 ;
else V_70 = 1 ;
if( V_66 ) {
* V_68 = F_52 ( V_65 , V_66 , V_70 ) ;
if( ! * V_68 ) return 0 ;
} else if( V_68 ) * V_68 = NULL ;
if( V_67 ) {
* V_69 = F_52 ( V_65 , V_67 , V_70 ? 2 : 0 ) ;
if( ! * V_69 ) return 0 ;
} else if( V_69 ) * V_69 = NULL ;
return 1 ;
}
static char * F_52 ( T_3 * V_65 , char * V_9 , int V_71 )
{
char * V_72 , V_73 [ V_74 ] ;
static T_3 * V_75 = NULL ;
int V_6 ;
if( ! strncmp ( V_9 , L_14 , 5 ) ) return F_53 ( V_9 + 5 ) ;
if( ! strncmp ( V_9 , L_15 , 4 ) ) {
V_72 = getenv ( V_9 + 4 ) ;
if( ! V_72 ) {
F_48 ( V_65 , L_16 , V_9 + 4 ) ;
return NULL ;
}
return F_53 ( V_72 ) ;
}
if( ! V_71 || ! V_75 ) {
if( ! strncmp ( V_9 , L_17 , 5 ) ) {
V_75 = F_54 ( V_9 + 5 , L_1 ) ;
if( ! V_75 ) {
F_48 ( V_65 , L_18 , V_9 + 5 ) ;
return NULL ;
}
} else if( ! strncmp ( V_9 , L_19 , 3 ) ) {
T_3 * V_76 ;
V_6 = atoi ( V_9 + 3 ) ;
if( V_6 >= 0 ) V_75 = F_55 ( V_6 , V_77 ) ;
if( ( V_6 < 0 ) || ! V_75 ) {
F_48 ( V_65 , L_20 , V_9 + 3 ) ;
return NULL ;
}
V_76 = F_56 ( F_57 () ) ;
V_75 = F_58 ( V_76 , V_75 ) ;
} else if( ! strcmp ( V_9 , L_21 ) ) {
V_75 = F_59 ( V_78 , V_77 ) ;
if( ! V_75 ) {
F_48 ( V_65 , L_22 ) ;
return NULL ;
}
} else {
F_48 ( V_65 , L_23 , V_9 ) ;
return NULL ;
}
}
V_6 = F_60 ( V_75 , V_73 , V_74 ) ;
if( V_71 != 1 ) {
F_61 ( V_75 ) ;
V_75 = NULL ;
}
if( V_6 <= 0 ) {
F_48 ( V_65 , L_24 ) ;
return NULL ;
}
V_72 = strchr ( V_73 , '\n' ) ;
if( V_72 ) * V_72 = 0 ;
return F_53 ( V_73 ) ;
}
int F_62 ( T_3 * V_65 , T_7 * V_79 )
{
char * V_10 ;
F_63 ( V_80 ) * V_81 ;
V_80 * V_82 ;
int V_6 ;
if( ! ( V_10 = F_64 ( V_79 , NULL , L_25 ) ) )
{
F_65 () ;
return 1 ;
}
if( ! ( V_81 = F_66 ( V_79 , V_10 ) ) ) {
F_48 ( V_65 , L_26 , V_10 ) ;
return 0 ;
}
for( V_6 = 0 ; V_6 < F_67 ( V_81 ) ; V_6 ++ ) {
V_82 = F_68 ( V_81 , V_6 ) ;
if( F_69 ( V_82 -> V_83 , V_82 -> V_84 , V_82 -> V_84 ) == V_85 ) {
F_48 ( V_65 , L_27 ,
V_82 -> V_84 , V_82 -> V_83 ) ;
return 0 ;
}
}
return 1 ;
}
T_4 * F_70 ( T_3 * V_65 , const char * V_1 , int V_86 ,
const char * V_87 , T_8 * V_88 , const char * V_89 )
{
T_9 * V_90 = NULL ;
T_10 * V_8 = NULL ;
T_4 * V_42 = NULL ;
T_3 * V_91 ;
if ( ( V_91 = F_56 ( F_71 () ) ) == NULL )
{
F_49 ( V_65 ) ;
goto V_92;
}
if ( V_1 == NULL )
{
setvbuf ( V_78 , NULL , V_93 , 0 ) ;
F_72 ( V_91 , V_78 , V_77 ) ;
}
else
{
if ( F_73 ( V_91 , V_1 ) <= 0 )
{
F_48 ( V_65 , L_28 ,
V_89 , V_1 ) ;
F_49 ( V_65 ) ;
goto V_92;
}
}
if ( V_86 == V_15 )
V_42 = F_74 ( V_91 , NULL ) ;
else if ( V_86 == V_18 )
{
unsigned char * V_10 , * V_94 ;
int V_25 = 0 , V_6 ;
V_8 = F_75 () ;
for (; ; )
{
if ( ( V_8 == NULL ) || ( ! F_76 ( V_8 , V_25 + 1024 * 10 ) ) )
goto V_92;
V_6 = F_77 ( V_91 , & ( V_8 -> V_40 [ V_25 ] ) , 1024 * 10 ) ;
V_25 += V_6 ;
if ( V_6 == 0 ) break;
if ( V_6 < 0 )
{
perror ( L_29 ) ;
goto V_92;
}
}
V_10 = ( unsigned char * ) V_8 -> V_40 ;
V_94 = V_10 ;
if ( ( V_90 = F_78 ( NULL , & V_10 , ( long ) V_25 ) ) == NULL )
goto V_92;
if ( ( V_90 -> V_95 == NULL ) || ( V_90 -> V_95 -> V_40 == NULL ) ||
( strncmp ( V_96 , ( char * ) V_90 -> V_95 -> V_40 ,
V_90 -> V_95 -> V_97 ) != 0 ) )
{
F_48 ( V_65 , L_30 ) ;
goto V_92;
}
V_10 = V_94 ;
V_90 -> V_98 = F_79 () ;
if ( ( V_90 = F_78 ( & V_90 , & V_10 , ( long ) V_25 ) ) == NULL )
goto V_92;
V_42 = ( T_4 * ) V_90 -> V_40 ;
V_90 -> V_40 = NULL ;
}
else if ( V_86 == V_17 )
V_42 = F_80 ( V_91 , NULL ,
( V_99 * ) F_40 , NULL ) ;
else if ( V_86 == V_20 )
{
T_11 * V_100 = F_81 ( V_91 , NULL ) ;
F_82 ( V_100 , NULL , NULL , & V_42 , NULL ) ;
F_83 ( V_100 ) ;
V_100 = NULL ;
}
else {
F_48 ( V_65 , L_31 ,
V_89 ) ;
goto V_92;
}
V_92:
if ( V_42 == NULL )
{
F_48 ( V_65 , L_32 ) ;
F_49 ( V_65 ) ;
}
if ( V_90 != NULL ) F_84 ( V_90 ) ;
if ( V_91 != NULL ) F_85 ( V_91 ) ;
if ( V_8 != NULL ) F_86 ( V_8 ) ;
return ( V_42 ) ;
}
T_12 * F_87 ( T_3 * V_65 , const char * V_1 , int V_86 , int V_101 ,
const char * V_87 , T_8 * V_88 , const char * V_102 )
{
T_3 * V_103 = NULL ;
T_12 * V_104 = NULL ;
V_49 V_55 ;
V_55 . V_48 = V_87 ;
V_55 . V_54 = V_1 ;
if ( V_1 == NULL && ( ! V_101 || V_86 == V_21 ) )
{
F_48 ( V_65 , L_33 ) ;
goto V_92;
}
if ( V_86 == V_21 )
{
if ( ! V_88 )
F_48 ( V_64 , L_34 ) ;
else
V_104 = F_88 ( V_88 , V_1 ,
V_50 , & V_55 ) ;
goto V_92;
}
V_103 = F_56 ( F_71 () ) ;
if ( V_103 == NULL )
{
F_49 ( V_65 ) ;
goto V_92;
}
if ( V_1 == NULL && V_101 )
{
setvbuf ( V_78 , NULL , V_93 , 0 ) ;
F_72 ( V_103 , V_78 , V_77 ) ;
}
else
if ( F_73 ( V_103 , V_1 ) <= 0 )
{
F_48 ( V_65 , L_28 ,
V_102 , V_1 ) ;
F_49 ( V_65 ) ;
goto V_92;
}
if ( V_86 == V_15 )
{
V_104 = F_89 ( V_103 , NULL ) ;
}
else if ( V_86 == V_17 )
{
V_104 = F_90 ( V_103 , NULL ,
( V_99 * ) F_40 , & V_55 ) ;
}
#if ! F_91 ( V_105 ) && ! F_91 ( V_106 )
else if ( V_86 == V_18 || V_86 == V_107 )
V_104 = F_92 ( V_65 , V_103 , V_1 , V_102 , V_86 ) ;
#endif
else if ( V_86 == V_20 )
{
T_11 * V_100 = F_81 ( V_103 , NULL ) ;
F_82 ( V_100 , V_87 , & V_104 , NULL , NULL ) ;
F_83 ( V_100 ) ;
V_100 = NULL ;
}
else
{
F_48 ( V_65 , L_35 ) ;
goto V_92;
}
V_92:
if ( V_103 != NULL ) F_85 ( V_103 ) ;
if ( V_104 == NULL )
F_48 ( V_65 , L_36 , V_102 ) ;
return ( V_104 ) ;
}
T_12 * F_93 ( T_3 * V_65 , const char * V_1 , int V_86 , int V_101 ,
const char * V_87 , T_8 * V_88 , const char * V_102 )
{
T_3 * V_103 = NULL ;
T_12 * V_104 = NULL ;
V_49 V_55 ;
V_55 . V_48 = V_87 ;
V_55 . V_54 = V_1 ;
if ( V_1 == NULL && ( ! V_101 || V_86 == V_21 ) )
{
F_48 ( V_65 , L_33 ) ;
goto V_92;
}
if ( V_86 == V_21 )
{
if ( ! V_88 )
F_48 ( V_64 , L_34 ) ;
else
V_104 = F_94 ( V_88 , V_1 ,
V_50 , & V_55 ) ;
goto V_92;
}
V_103 = F_56 ( F_71 () ) ;
if ( V_103 == NULL )
{
F_49 ( V_65 ) ;
goto V_92;
}
if ( V_1 == NULL && V_101 )
{
setvbuf ( V_78 , NULL , V_93 , 0 ) ;
F_72 ( V_103 , V_78 , V_77 ) ;
}
else
if ( F_73 ( V_103 , V_1 ) <= 0 )
{
F_48 ( V_65 , L_28 ,
V_102 , V_1 ) ;
F_49 ( V_65 ) ;
goto V_92;
}
if ( V_86 == V_15 )
{
V_104 = F_95 ( V_103 , NULL ) ;
}
else if ( V_86 == V_17 )
{
V_104 = F_96 ( V_103 , NULL ,
( V_99 * ) F_40 , & V_55 ) ;
}
#if ! F_91 ( V_105 ) && ! F_91 ( V_106 )
else if ( V_86 == V_18 || V_86 == V_107 )
V_104 = F_92 ( V_65 , V_103 , V_1 , V_102 , V_86 ) ;
#endif
else
{
F_48 ( V_65 , L_35 ) ;
goto V_92;
}
V_92:
if ( V_103 != NULL ) F_85 ( V_103 ) ;
if ( V_104 == NULL )
F_48 ( V_65 , L_36 , V_102 ) ;
return ( V_104 ) ;
}
static T_12 *
F_92 ( T_3 * V_65 , T_3 * V_103 , const char * V_1 ,
const char * V_102 , int V_86 )
{
T_12 * V_104 ;
T_10 * V_8 ;
T_13 * V_108 ;
const unsigned char * V_10 ;
int V_25 , V_6 ;
V_8 = F_75 () ;
V_104 = F_97 () ;
V_25 = 0 ;
if ( V_8 == NULL || V_104 == NULL )
goto error;
for (; ; )
{
if ( ! F_98 ( V_8 , V_25 + 1024 * 10 ) )
goto error;
V_6 = F_77 ( V_103 , & ( V_8 -> V_40 [ V_25 ] ) , 1024 * 10 ) ;
V_25 += V_6 ;
if ( V_6 == 0 )
break;
if ( V_6 < 0 )
{
F_48 ( V_65 , L_37 ,
V_102 , V_1 ) ;
goto error;
}
}
V_10 = ( unsigned char * ) V_8 -> V_40 ;
V_108 = F_99 ( NULL , & V_10 , ( long ) V_25 , NULL ,
( V_86 == V_107 ? 1 : 0 ) ) ;
if ( V_108 == NULL )
goto error;
F_86 ( V_8 ) ;
F_100 ( V_104 , V_108 ) ;
return V_104 ;
error:
F_86 ( V_8 ) ;
F_101 ( V_104 ) ;
return NULL ;
}
int F_102 ( unsigned long * V_109 , const char * V_9 )
{
static const T_14 V_110 [] = {
{ L_38 , V_111 , 0 } ,
{ L_39 , V_112 , 0 } ,
{ L_40 , V_113 , 0 } ,
{ L_41 , V_114 , 0 } ,
{ L_42 , V_115 , 0 } ,
{ L_43 , V_116 , 0 } ,
{ L_44 , V_117 , 0 } ,
{ L_45 , V_118 , 0 } ,
{ L_46 , V_119 , 0 } ,
{ L_47 , V_120 , 0 } ,
{ L_48 , V_121 , 0xffffffffL } ,
{ L_49 , V_122 , V_123 } ,
{ L_50 , V_124 , V_123 } ,
{ L_51 , V_125 , V_123 } ,
{ L_52 , V_126 , V_123 } ,
{ L_53 , V_127 , 0 } ,
{ L_54 , V_128 , V_129 } ,
{ L_55 , V_130 , V_129 } ,
{ L_56 , V_131 , V_129 } ,
{ L_57 , V_132 , 0 } ,
{ L_58 , V_133 , V_129 } ,
{ L_59 , V_134 , 0 } ,
{ L_60 , V_135 , 0 } ,
{ L_61 , V_136 , 0xffffffffL } ,
{ L_62 , V_137 , 0xffffffffL } ,
{ L_63 , V_138 , 0xffffffffL } ,
{ L_64 , V_138 , 0xffffffffL } ,
{ NULL , 0 , 0 }
} ;
return F_103 ( V_109 , V_9 , V_110 ) ;
}
int F_104 ( int * V_139 , const char * V_9 )
{
if ( ! strcasecmp ( V_9 , L_65 ) )
* V_139 = V_140 ;
else if ( ! strcasecmp ( V_9 , L_66 ) )
* V_139 = V_141 ;
else if ( ! strcasecmp ( V_9 , L_67 ) )
* V_139 = V_142 ;
else
return 0 ;
return 1 ;
}
int F_105 ( T_4 * V_42 , T_15 * V_143 , int V_139 )
{
F_63 ( V_144 ) * V_145 = NULL ;
V_144 * V_146 , * V_147 ;
T_16 * V_148 ;
int V_6 , V_149 , V_150 = 0 ;
if ( ! V_42 || ! V_143 || ( V_139 == V_140 ) )
return 1 ;
V_145 = F_106 ( V_143 ) ;
for( V_6 = 0 ; V_6 < F_107 ( V_145 ) ; V_6 ++ ) {
V_146 = F_108 ( V_145 , V_6 ) ;
V_148 = F_109 ( V_146 ) ;
V_149 = F_110 ( V_42 , V_148 , - 1 ) ;
if ( V_149 != - 1 ) {
if ( V_139 == V_141 )
continue;
do {
V_147 = F_111 ( V_42 , V_149 ) ;
F_112 ( V_42 , V_149 ) ;
F_113 ( V_147 ) ;
V_149 = F_110 ( V_42 , V_148 , - 1 ) ;
} while ( V_149 != - 1 );
}
if ( ! F_114 ( V_42 , V_146 , - 1 ) )
goto V_92;
}
V_150 = 1 ;
V_92:
F_115 ( V_145 , F_113 ) ;
return V_150 ;
}
static int F_103 ( unsigned long * V_109 , const char * V_9 , const T_14 * V_151 )
{
F_63 ( V_80 ) * V_152 ;
V_80 * V_153 ;
int V_6 , V_150 = 1 ;
if( ! V_9 ) return 0 ;
V_152 = F_116 ( V_9 ) ;
for ( V_6 = 0 ; V_6 < F_67 ( V_152 ) ; V_6 ++ ) {
V_153 = F_68 ( V_152 , V_6 ) ;
if ( ! F_117 ( V_109 , V_153 -> V_84 , V_151 ) )
V_150 = 0 ;
}
F_118 ( V_152 , V_154 ) ;
return V_150 ;
}
static int F_117 ( unsigned long * V_109 , const char * V_9 , const T_14 * V_151 )
{
char V_155 ;
const T_14 * V_156 ;
V_155 = V_9 [ 0 ] ;
if( V_155 == '-' ) {
V_155 = 0 ;
V_9 ++ ;
} else if ( V_155 == '+' ) {
V_155 = 1 ;
V_9 ++ ;
} else V_155 = 1 ;
for( V_156 = V_151 ; V_156 -> V_84 ; V_156 ++ ) {
if( ! strcasecmp ( V_9 , V_156 -> V_84 ) ) {
* V_109 &= ~ V_156 -> V_157 ;
if( V_155 ) * V_109 |= V_156 -> V_158 ;
else * V_109 &= ~ V_156 -> V_158 ;
return 1 ;
}
}
return 0 ;
}
void F_119 ( T_3 * V_24 , char * V_159 , T_17 * V_160 , unsigned long V_161 )
{
char * V_8 ;
char V_162 = 0 ;
int V_163 = 0 ;
if( V_159 ) F_17 ( V_24 , V_159 ) ;
if( ( V_161 & V_123 ) == V_126 ) {
V_162 = 1 ;
V_163 = 4 ;
}
if( V_161 == V_121 ) {
V_8 = F_15 ( V_160 , 0 , 0 ) ;
F_17 ( V_24 , V_8 ) ;
F_17 ( V_24 , L_9 ) ;
F_2 ( V_8 ) ;
} else {
if( V_162 ) F_17 ( V_24 , L_9 ) ;
F_120 ( V_24 , V_160 , V_163 , V_161 ) ;
F_17 ( V_24 , L_9 ) ;
}
}
T_18 * F_121 ( T_3 * V_164 , char * V_165 , char * V_166 )
{
T_18 * V_167 ;
T_19 * V_168 ;
if( ! ( V_167 = F_122 () ) ) goto V_92;
V_168 = F_123 ( V_167 , F_124 () ) ;
if ( V_168 == NULL ) goto V_92;
if ( V_165 ) {
if( ! F_125 ( V_168 , V_165 , V_169 ) ) {
F_48 ( V_164 , L_68 , V_165 ) ;
goto V_92;
}
} else F_125 ( V_168 , NULL , V_170 ) ;
V_168 = F_123 ( V_167 , F_126 () ) ;
if ( V_168 == NULL ) goto V_92;
if ( V_166 ) {
if( ! F_127 ( V_168 , V_166 , V_169 ) ) {
F_48 ( V_164 , L_69 , V_166 ) ;
goto V_92;
}
} else F_127 ( V_168 , NULL , V_170 ) ;
F_65 () ;
return V_167 ;
V_92:
F_128 ( V_167 ) ;
return NULL ;
}
static T_8 * F_129 ( T_3 * V_65 , const char * V_171 , int V_172 )
{
T_8 * V_88 = F_130 ( L_70 ) ;
if ( V_88 )
{
if ( ! F_131 ( V_88 , L_71 , V_171 , 0 )
|| ! F_131 ( V_88 , L_72 , NULL , 0 ) )
{
F_132 ( V_88 ) ;
V_88 = NULL ;
}
}
return V_88 ;
}
T_8 * F_133 ( T_3 * V_65 , const char * V_171 , int V_172 )
{
T_8 * V_88 = NULL ;
if ( V_171 )
{
if( strcmp ( V_171 , L_73 ) == 0 )
{
F_48 ( V_65 , L_74 ) ;
F_134 () ;
return NULL ;
}
if( ( V_88 = F_130 ( V_171 ) ) == NULL
&& ( V_88 = F_129 ( V_65 , V_171 , V_172 ) ) == NULL )
{
F_48 ( V_65 , L_75 , V_171 ) ;
F_49 ( V_65 ) ;
return NULL ;
}
if ( V_172 )
{
F_135 ( V_88 , V_173 ,
0 , V_65 , 0 ) ;
}
F_136 ( V_88 , L_76 , 0 , V_50 , 0 , 1 ) ;
if( ! F_137 ( V_88 , V_174 ) )
{
F_48 ( V_65 , L_77 ) ;
F_49 ( V_65 ) ;
F_132 ( V_88 ) ;
return NULL ;
}
F_48 ( V_65 , L_78 , F_138 ( V_88 ) ) ;
F_132 ( V_88 ) ;
}
return V_88 ;
}
int F_139 ( T_3 * V_65 , T_7 * V_82 )
{
if ( ! V_82 )
V_82 = V_175 ;
if ( ! V_82 )
return 1 ;
F_140 () ;
if ( F_141 ( V_82 , NULL , 0 ) <= 0 )
{
F_48 ( V_65 , L_79 ) ;
F_49 ( V_65 ) ;
return 0 ;
}
return 1 ;
}
char * F_142 ()
{
const char * V_176 = F_143 () ;
char * V_10 ;
V_10 = F_3 ( strlen ( V_176 ) + strlen ( V_177 ) + 2 ) ;
strcpy ( V_10 , V_176 ) ;
#ifndef F_144
strcat ( V_10 , L_80 ) ;
#endif
strcat ( V_10 , V_177 ) ;
return V_10 ;
}
