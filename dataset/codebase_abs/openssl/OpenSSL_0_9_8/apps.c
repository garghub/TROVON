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
#if F_6 ( V_27 )
if ( ( V_26 > 4 ) && ( V_10 [ V_26 - 4 ] == '.' ) &&
( ( V_10 [ V_26 - 3 ] == 'n' ) || ( V_10 [ V_26 - 3 ] == 'N' ) ) &&
( ( V_10 [ V_26 - 2 ] == 'l' ) || ( V_10 [ V_26 - 2 ] == 'L' ) ) &&
( ( V_10 [ V_26 - 1 ] == 'm' ) || ( V_10 [ V_26 - 1 ] == 'M' ) ) )
V_26 -= 4 ;
#else
if ( ( V_26 > 4 ) && ( V_10 [ V_26 - 4 ] == '.' ) &&
( ( V_10 [ V_26 - 3 ] == 'e' ) || ( V_10 [ V_26 - 3 ] == 'E' ) ) &&
( ( V_10 [ V_26 - 2 ] == 'x' ) || ( V_10 [ V_26 - 2 ] == 'X' ) ) &&
( ( V_10 [ V_26 - 1 ] == 'e' ) || ( V_10 [ V_26 - 1 ] == 'E' ) ) )
V_26 -= 4 ;
#endif
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
char * V_10 = V_23 , * V_28 ;
char * V_29 = L_6 ;
while( * V_29 != '\0' )
{
V_28 = strrchr ( V_10 , * V_29 ) ;
if ( V_28 > V_10 )
V_10 = V_28 + 1 ;
V_29 ++ ;
}
V_28 = strrchr ( V_10 , '.' ) ;
if ( V_28 == NULL )
V_28 = V_10 + strlen ( V_10 ) ;
strncpy ( V_24 , V_10 , V_25 - 1 ) ;
if ( V_28 - V_10 >= V_25 )
{
V_24 [ V_25 - 1 ] = '\0' ;
}
else
{
V_24 [ V_28 - V_10 ] = '\0' ;
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
F_7 ( V_24 , V_10 , V_25 ) ;
}
int F_8 ( ARGS * V_9 , char * V_8 , int * V_2 , char * * V_3 [] )
{
int V_5 , V_7 , V_6 ;
char * V_10 ;
* V_2 = 0 ;
* V_3 = NULL ;
V_7 = strlen ( V_8 ) ;
V_6 = 0 ;
if ( V_9 -> V_30 == 0 )
{
V_9 -> V_30 = 20 ;
V_9 -> V_31 = ( char * * ) F_3 ( sizeof( char * ) * V_9 -> V_30 ) ;
}
for ( V_6 = 0 ; V_6 < V_9 -> V_30 ; V_6 ++ )
V_9 -> V_31 [ V_6 ] = NULL ;
V_5 = 0 ;
V_10 = V_8 ;
for (; ; )
{
if ( ! * V_10 ) break;
while ( * V_10 && ( ( * V_10 == ' ' ) || ( * V_10 == '\t' ) || ( * V_10 == '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 ) break;
if ( V_5 >= V_9 -> V_30 )
{
char * * V_32 ;
int V_33 = V_9 -> V_30 + 20 ;
V_32 = ( char * * ) F_9 ( V_9 -> V_31 ,
sizeof( char * ) * V_33 ) ;
if ( V_32 == NULL )
return 0 ;
V_9 -> V_31 = V_32 ;
V_9 -> V_30 = V_33 ;
for ( V_6 = V_5 ; V_6 < V_9 -> V_30 ; V_6 ++ )
V_9 -> V_31 [ V_6 ] = NULL ;
}
V_9 -> V_31 [ V_5 ++ ] = V_10 ;
if ( ( * V_10 == '\'' ) || ( * V_10 == '\"' ) )
{
V_6 = * ( V_10 ++ ) ;
V_9 -> V_31 [ V_5 - 1 ] ++ ;
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
* V_3 = V_9 -> V_31 ;
return ( 1 ) ;
}
int F_10 ( long V_34 )
{
return ( 1 ) ;
}
int F_11 ( T_2 * V_24 , T_3 * V_35 )
{
char * V_10 ;
V_10 = F_12 ( F_13 ( V_35 ) , NULL , 0 ) ;
F_14 ( V_24 , L_7 ) ;
F_14 ( V_24 , V_10 ) ;
F_2 ( V_10 ) ;
V_10 = F_12 ( F_15 ( V_35 ) , NULL , 0 ) ;
F_14 ( V_24 , L_8 ) ;
F_14 ( V_24 , V_10 ) ;
F_14 ( V_24 , L_9 ) ;
F_2 ( V_10 ) ;
return 0 ;
}
static int F_16 ( T_4 * V_36 )
{
return F_17 ( F_18 () ) ( V_36 ) ;
}
static int F_19 ( T_4 * V_36 , T_5 * V_37 )
{
if ( F_20 ( V_37 ) & V_38
&& F_21 ( V_36 ) )
{
switch( F_22 ( V_37 ) )
{
case V_39 :
case V_40 :
{
const char * V_41 =
( ( V_42 * ) F_21 ( V_36 ) ) -> V_41 ;
if ( V_41 && V_41 [ 0 ] != '\0' )
{
F_23 ( V_36 , V_37 , V_41 ) ;
return 1 ;
}
}
default:
break;
}
}
return F_24 ( F_18 () ) ( V_36 , V_37 ) ;
}
static int F_25 ( T_4 * V_36 , T_5 * V_37 )
{
if ( F_20 ( V_37 ) & V_38
&& F_21 ( V_36 ) )
{
switch( F_22 ( V_37 ) )
{
case V_39 :
case V_40 :
{
const char * V_41 =
( ( V_42 * ) F_21 ( V_36 ) ) -> V_41 ;
if ( V_41 && V_41 [ 0 ] != '\0' )
return 1 ;
}
default:
break;
}
}
return F_26 ( F_18 () ) ( V_36 , V_37 ) ;
}
static int F_27 ( T_4 * V_36 )
{
return F_28 ( F_18 () ) ( V_36 ) ;
}
int F_29 ( void )
{
V_43 = F_30 ( L_10 ) ;
F_31 ( V_43 , F_16 ) ;
F_32 ( V_43 , F_19 ) ;
F_33 ( V_43 , F_25 ) ;
F_34 ( V_43 , F_27 ) ;
return 0 ;
}
void F_35 ( void )
{
if( V_43 )
{
F_36 ( V_43 ) ;
V_43 = NULL ;
}
}
int F_37 ( char * V_8 , int V_44 , int V_45 ,
V_42 * V_46 )
{
T_4 * V_36 = NULL ;
int V_47 = 0 ;
const char * V_48 = NULL ;
const char * V_41 = NULL ;
V_42 * V_49 = ( V_42 * ) V_46 ;
if ( V_49 )
{
if ( V_49 -> V_41 )
V_41 = V_49 -> V_41 ;
if ( V_49 -> V_48 )
V_48 = V_49 -> V_48 ;
}
if ( V_41 )
{
V_47 = strlen ( V_41 ) ;
if ( V_47 > V_44 )
V_47 = V_44 ;
memcpy ( V_8 , V_41 , V_47 ) ;
return V_47 ;
}
V_36 = F_38 ( V_43 ) ;
if ( V_36 )
{
int V_50 = 0 ;
char * V_51 = NULL ;
int V_52 = 0 ;
char * V_53 = NULL ;
V_53 = F_39 ( V_36 , L_11 ,
V_48 ) ;
V_52 |= V_38 ;
F_40 ( V_36 , V_54 , 1 , 0 , 0 ) ;
if ( V_50 >= 0 )
V_50 = F_41 ( V_36 , V_53 , V_52 , V_8 ,
V_55 , V_56 - 1 ) ;
if ( V_50 >= 0 && V_45 )
{
V_51 = ( char * ) F_3 ( V_44 ) ;
V_50 = F_42 ( V_36 , V_53 , V_52 , V_51 ,
V_55 , V_56 - 1 , V_8 ) ;
}
if ( V_50 >= 0 )
do
{
V_50 = F_43 ( V_36 ) ;
}
while ( V_50 < 0 && F_40 ( V_36 , V_57 , 0 , 0 , 0 ) );
if ( V_51 )
{
F_44 ( V_51 , ( unsigned int ) V_44 ) ;
F_2 ( V_51 ) ;
}
if ( V_50 >= 0 )
V_47 = strlen ( V_8 ) ;
if ( V_50 == - 1 )
{
F_45 ( V_58 , L_12 ) ;
F_46 ( V_58 ) ;
F_44 ( V_8 , ( unsigned int ) V_44 ) ;
V_47 = 0 ;
}
if ( V_50 == - 2 )
{
F_45 ( V_58 , L_13 ) ;
F_44 ( V_8 , ( unsigned int ) V_44 ) ;
V_47 = 0 ;
}
F_47 ( V_36 ) ;
F_2 ( V_53 ) ;
}
return V_47 ;
}
int F_48 ( T_2 * V_59 , char * V_60 , char * V_61 , char * * V_62 , char * * V_63 )
{
int V_64 ;
if( ! V_61 || ! V_60 || strcmp ( V_60 , V_61 ) ) V_64 = 0 ;
else V_64 = 1 ;
if( V_60 ) {
* V_62 = F_49 ( V_59 , V_60 , V_64 ) ;
if( ! * V_62 ) return 0 ;
} else if( V_62 ) * V_62 = NULL ;
if( V_61 ) {
* V_63 = F_49 ( V_59 , V_61 , V_64 ? 2 : 0 ) ;
if( ! * V_63 ) return 0 ;
} else if( V_63 ) * V_63 = NULL ;
return 1 ;
}
static char * F_49 ( T_2 * V_59 , char * V_9 , int V_65 )
{
char * V_66 , V_67 [ V_68 ] ;
static T_2 * V_69 = NULL ;
int V_6 ;
if( ! strncmp ( V_9 , L_14 , 5 ) ) return F_50 ( V_9 + 5 ) ;
if( ! strncmp ( V_9 , L_15 , 4 ) ) {
V_66 = getenv ( V_9 + 4 ) ;
if( ! V_66 ) {
F_45 ( V_59 , L_16 , V_9 + 4 ) ;
return NULL ;
}
return F_50 ( V_66 ) ;
}
if( ! V_65 || ! V_69 ) {
if( ! strncmp ( V_9 , L_17 , 5 ) ) {
V_69 = F_51 ( V_9 + 5 , L_1 ) ;
if( ! V_69 ) {
F_45 ( V_59 , L_18 , V_9 + 5 ) ;
return NULL ;
}
} else if( ! strncmp ( V_9 , L_19 , 3 ) ) {
T_2 * V_70 ;
V_6 = atoi ( V_9 + 3 ) ;
if( V_6 >= 0 ) V_69 = F_52 ( V_6 , V_71 ) ;
if( ( V_6 < 0 ) || ! V_69 ) {
F_45 ( V_59 , L_20 , V_9 + 3 ) ;
return NULL ;
}
V_70 = F_53 ( F_54 () ) ;
V_69 = F_55 ( V_70 , V_69 ) ;
} else if( ! strcmp ( V_9 , L_21 ) ) {
V_69 = F_56 ( V_72 , V_71 ) ;
if( ! V_69 ) {
F_45 ( V_59 , L_22 ) ;
return NULL ;
}
} else {
F_45 ( V_59 , L_23 , V_9 ) ;
return NULL ;
}
}
V_6 = F_57 ( V_69 , V_67 , V_68 ) ;
if( V_65 != 1 ) {
F_58 ( V_69 ) ;
V_69 = NULL ;
}
if( V_6 <= 0 ) {
F_45 ( V_59 , L_24 ) ;
return NULL ;
}
V_66 = strchr ( V_67 , '\n' ) ;
if( V_66 ) * V_66 = 0 ;
return F_50 ( V_67 ) ;
}
int F_59 ( T_2 * V_59 , T_6 * V_73 )
{
char * V_10 ;
F_60 ( V_74 ) * V_75 ;
V_74 * V_76 ;
int V_6 ;
if( ! ( V_10 = F_61 ( V_73 , NULL , L_25 ) ) )
{
F_62 () ;
return 1 ;
}
if( ! ( V_75 = F_63 ( V_73 , V_10 ) ) ) {
F_45 ( V_59 , L_26 , V_10 ) ;
return 0 ;
}
for( V_6 = 0 ; V_6 < F_64 ( V_75 ) ; V_6 ++ ) {
V_76 = F_65 ( V_75 , V_6 ) ;
if( F_66 ( V_76 -> V_77 , V_76 -> V_78 , V_76 -> V_78 ) == V_79 ) {
F_45 ( V_59 , L_27 ,
V_76 -> V_78 , V_76 -> V_77 ) ;
return 0 ;
}
}
return 1 ;
}
T_3 * F_67 ( T_2 * V_59 , const char * V_1 , int V_80 ,
const char * V_81 , T_7 * V_82 , const char * V_83 )
{
T_8 * V_84 = NULL ;
T_9 * V_8 = NULL ;
T_3 * V_35 = NULL ;
T_2 * V_85 ;
if ( ( V_85 = F_53 ( F_68 () ) ) == NULL )
{
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_1 == NULL )
{
setvbuf ( V_72 , NULL , V_87 , 0 ) ;
F_69 ( V_85 , V_72 , V_71 ) ;
}
else
{
if ( F_70 ( V_85 , V_1 ) <= 0 )
{
F_45 ( V_59 , L_28 ,
V_83 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_86;
}
}
if ( V_80 == V_15 )
V_35 = F_71 ( V_85 , NULL ) ;
else if ( V_80 == V_18 )
{
const unsigned char * V_10 , * V_88 ;
int V_25 = 0 , V_6 ;
V_8 = F_72 () ;
for (; ; )
{
if ( ( V_8 == NULL ) || ( ! F_73 ( V_8 , V_25 + 1024 * 10 ) ) )
goto V_86;
V_6 = F_74 ( V_85 , & ( V_8 -> V_31 [ V_25 ] ) , 1024 * 10 ) ;
V_25 += V_6 ;
if ( V_6 == 0 ) break;
if ( V_6 < 0 )
{
perror ( L_29 ) ;
goto V_86;
}
}
V_10 = ( unsigned char * ) V_8 -> V_31 ;
V_88 = V_10 ;
if ( ( V_84 = F_75 ( NULL , & V_10 , ( long ) V_25 ) ) == NULL )
goto V_86;
if ( ( V_84 -> V_89 == NULL ) || ( V_84 -> V_89 -> V_31 == NULL ) ||
( strncmp ( V_90 , ( char * ) V_84 -> V_89 -> V_31 ,
V_84 -> V_89 -> V_91 ) != 0 ) )
{
F_45 ( V_59 , L_30 ) ;
goto V_86;
}
V_10 = V_88 ;
V_84 -> V_92 = F_76 () ;
if ( ( V_84 = F_75 ( & V_84 , & V_10 , ( long ) V_25 ) ) == NULL )
goto V_86;
V_35 = ( T_3 * ) V_84 -> V_31 ;
V_84 -> V_31 = NULL ;
}
else if ( V_80 == V_17 )
V_35 = F_77 ( V_85 , NULL ,
( V_93 * ) F_37 , NULL ) ;
else if ( V_80 == V_20 )
{
if ( ! F_78 ( V_59 , V_85 , V_83 , NULL , NULL ,
NULL , & V_35 , NULL ) )
goto V_86;
}
else {
F_45 ( V_59 , L_31 ,
V_83 ) ;
goto V_86;
}
V_86:
if ( V_35 == NULL )
{
F_45 ( V_59 , L_32 ) ;
F_46 ( V_59 ) ;
}
if ( V_84 != NULL ) F_79 ( V_84 ) ;
if ( V_85 != NULL ) F_80 ( V_85 ) ;
if ( V_8 != NULL ) F_81 ( V_8 ) ;
return ( V_35 ) ;
}
T_10 * F_82 ( T_2 * V_59 , const char * V_1 , int V_80 , int V_94 ,
const char * V_81 , T_7 * V_82 , const char * V_95 )
{
T_2 * V_96 = NULL ;
T_10 * V_97 = NULL ;
V_42 V_49 ;
V_49 . V_41 = V_81 ;
V_49 . V_48 = V_1 ;
if ( V_1 == NULL && ( ! V_94 || V_80 == V_21 ) )
{
F_45 ( V_59 , L_33 ) ;
goto V_86;
}
#ifndef F_83
if ( V_80 == V_21 )
{
if ( ! V_82 )
F_45 ( V_58 , L_34 ) ;
else
V_97 = F_84 ( V_82 , V_1 ,
V_43 , & V_49 ) ;
goto V_86;
}
#endif
V_96 = F_53 ( F_68 () ) ;
if ( V_96 == NULL )
{
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_1 == NULL && V_94 )
{
setvbuf ( V_72 , NULL , V_87 , 0 ) ;
F_69 ( V_96 , V_72 , V_71 ) ;
}
else
if ( F_70 ( V_96 , V_1 ) <= 0 )
{
F_45 ( V_59 , L_28 ,
V_95 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_80 == V_15 )
{
V_97 = F_85 ( V_96 , NULL ) ;
}
else if ( V_80 == V_17 )
{
V_97 = F_86 ( V_96 , NULL ,
( V_93 * ) F_37 , & V_49 ) ;
}
#if ! F_6 ( V_98 ) && ! F_6 ( V_99 )
else if ( V_80 == V_18 || V_80 == V_100 )
V_97 = F_87 ( V_59 , V_96 , V_1 , V_95 , V_80 ) ;
#endif
else if ( V_80 == V_20 )
{
if ( ! F_78 ( V_59 , V_96 , V_95 ,
( V_93 * ) F_37 , & V_49 ,
& V_97 , NULL , NULL ) )
goto V_86;
}
else
{
F_45 ( V_59 , L_35 ) ;
goto V_86;
}
V_86:
if ( V_96 != NULL ) F_80 ( V_96 ) ;
if ( V_97 == NULL )
F_45 ( V_59 , L_36 , V_95 ) ;
return ( V_97 ) ;
}
T_10 * F_88 ( T_2 * V_59 , const char * V_1 , int V_80 , int V_94 ,
const char * V_81 , T_7 * V_82 , const char * V_95 )
{
T_2 * V_96 = NULL ;
T_10 * V_97 = NULL ;
V_42 V_49 ;
V_49 . V_41 = V_81 ;
V_49 . V_48 = V_1 ;
if ( V_1 == NULL && ( ! V_94 || V_80 == V_21 ) )
{
F_45 ( V_59 , L_33 ) ;
goto V_86;
}
#ifndef F_83
if ( V_80 == V_21 )
{
if ( ! V_82 )
F_45 ( V_58 , L_34 ) ;
else
V_97 = F_89 ( V_82 , V_1 ,
V_43 , & V_49 ) ;
goto V_86;
}
#endif
V_96 = F_53 ( F_68 () ) ;
if ( V_96 == NULL )
{
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_1 == NULL && V_94 )
{
setvbuf ( V_72 , NULL , V_87 , 0 ) ;
F_69 ( V_96 , V_72 , V_71 ) ;
}
else
if ( F_70 ( V_96 , V_1 ) <= 0 )
{
F_45 ( V_59 , L_28 ,
V_95 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_80 == V_15 )
{
V_97 = F_90 ( V_96 , NULL ) ;
}
else if ( V_80 == V_17 )
{
V_97 = F_91 ( V_96 , NULL ,
( V_93 * ) F_37 , & V_49 ) ;
}
#if ! F_6 ( V_98 ) && ! F_6 ( V_99 )
else if ( V_80 == V_18 || V_80 == V_100 )
V_97 = F_87 ( V_59 , V_96 , V_1 , V_95 , V_80 ) ;
#endif
else
{
F_45 ( V_59 , L_35 ) ;
goto V_86;
}
V_86:
if ( V_96 != NULL ) F_80 ( V_96 ) ;
if ( V_97 == NULL )
F_45 ( V_59 , L_36 , V_95 ) ;
return ( V_97 ) ;
}
static T_10 *
F_87 ( T_2 * V_59 , T_2 * V_96 , const char * V_1 ,
const char * V_95 , int V_80 )
{
T_10 * V_97 ;
T_9 * V_8 ;
T_11 * V_101 ;
const unsigned char * V_10 ;
int V_25 , V_6 ;
V_8 = F_72 () ;
V_97 = F_92 () ;
V_25 = 0 ;
if ( V_8 == NULL || V_97 == NULL )
goto error;
for (; ; )
{
if ( ! F_93 ( V_8 , V_25 + 1024 * 10 ) )
goto error;
V_6 = F_74 ( V_96 , & ( V_8 -> V_31 [ V_25 ] ) , 1024 * 10 ) ;
V_25 += V_6 ;
if ( V_6 == 0 )
break;
if ( V_6 < 0 )
{
F_45 ( V_59 , L_37 ,
V_95 , V_1 ) ;
goto error;
}
}
V_10 = ( unsigned char * ) V_8 -> V_31 ;
V_101 = F_94 ( NULL , & V_10 , ( long ) V_25 , NULL ,
( V_80 == V_100 ? 1 : 0 ) ) ;
if ( V_101 == NULL )
goto error;
F_81 ( V_8 ) ;
F_95 ( V_97 , V_101 ) ;
return V_97 ;
error:
F_81 ( V_8 ) ;
F_96 ( V_97 ) ;
return NULL ;
}
int F_97 ( unsigned long * V_102 , const char * V_9 )
{
static const T_12 V_103 [] = {
{ L_38 , V_104 , 0 } ,
{ L_39 , V_105 , 0 } ,
{ L_40 , V_106 , 0 } ,
{ L_41 , V_107 , 0 } ,
{ L_42 , V_108 , 0 } ,
{ L_43 , V_109 , 0 } ,
{ L_44 , V_110 , 0 } ,
{ L_45 , V_111 , 0 } ,
{ L_46 , V_112 , 0 } ,
{ L_47 , V_113 , 0 } ,
{ L_48 , V_114 , 0xffffffffL } ,
{ L_49 , V_115 , V_116 } ,
{ L_50 , V_117 , V_116 } ,
{ L_51 , V_118 , V_116 } ,
{ L_52 , V_119 , V_116 } ,
{ L_53 , V_120 , 0 } ,
{ L_54 , V_121 , V_122 } ,
{ L_55 , V_123 , V_122 } ,
{ L_56 , V_124 , V_122 } ,
{ L_57 , V_125 , 0 } ,
{ L_58 , V_126 , V_122 } ,
{ L_59 , V_127 , 0 } ,
{ L_60 , V_128 , 0 } ,
{ L_61 , V_129 , 0xffffffffL } ,
{ L_62 , V_130 , 0xffffffffL } ,
{ L_63 , V_131 , 0xffffffffL } ,
{ L_64 , V_131 , 0xffffffffL } ,
{ NULL , 0 , 0 }
} ;
return F_98 ( V_102 , V_9 , V_103 ) ;
}
int F_99 ( int * V_132 , const char * V_9 )
{
if ( ! strcasecmp ( V_9 , L_65 ) )
* V_132 = V_133 ;
else if ( ! strcasecmp ( V_9 , L_66 ) )
* V_132 = V_134 ;
else if ( ! strcasecmp ( V_9 , L_67 ) )
* V_132 = V_135 ;
else
return 0 ;
return 1 ;
}
int F_100 ( T_3 * V_35 , T_13 * V_136 , int V_132 )
{
F_60 ( V_137 ) * V_138 = NULL ;
V_137 * V_139 , * V_140 ;
T_14 * V_141 ;
int V_6 , V_142 , V_143 = 0 ;
if ( ! V_35 || ! V_136 || ( V_132 == V_133 ) )
return 1 ;
V_138 = F_101 ( V_136 ) ;
for( V_6 = 0 ; V_6 < F_102 ( V_138 ) ; V_6 ++ ) {
V_139 = F_103 ( V_138 , V_6 ) ;
V_141 = F_104 ( V_139 ) ;
V_142 = F_105 ( V_35 , V_141 , - 1 ) ;
if ( V_142 != - 1 ) {
if ( V_132 == V_134 )
continue;
do {
V_140 = F_106 ( V_35 , V_142 ) ;
F_107 ( V_35 , V_142 ) ;
F_108 ( V_140 ) ;
V_142 = F_105 ( V_35 , V_141 , - 1 ) ;
} while ( V_142 != - 1 );
}
if ( ! F_109 ( V_35 , V_139 , - 1 ) )
goto V_86;
}
V_143 = 1 ;
V_86:
F_110 ( V_138 , F_108 ) ;
return V_143 ;
}
static int F_98 ( unsigned long * V_102 , const char * V_9 , const T_12 * V_144 )
{
F_60 ( V_74 ) * V_145 ;
V_74 * V_146 ;
int V_6 , V_143 = 1 ;
if( ! V_9 ) return 0 ;
V_145 = F_111 ( V_9 ) ;
for ( V_6 = 0 ; V_6 < F_64 ( V_145 ) ; V_6 ++ ) {
V_146 = F_65 ( V_145 , V_6 ) ;
if ( ! F_112 ( V_102 , V_146 -> V_78 , V_144 ) )
V_143 = 0 ;
}
F_113 ( V_145 , V_147 ) ;
return V_143 ;
}
static int F_112 ( unsigned long * V_102 , const char * V_9 , const T_12 * V_144 )
{
char V_148 ;
const T_12 * V_149 ;
V_148 = V_9 [ 0 ] ;
if( V_148 == '-' ) {
V_148 = 0 ;
V_9 ++ ;
} else if ( V_148 == '+' ) {
V_148 = 1 ;
V_9 ++ ;
} else V_148 = 1 ;
for( V_149 = V_144 ; V_149 -> V_78 ; V_149 ++ ) {
if( ! strcasecmp ( V_9 , V_149 -> V_78 ) ) {
* V_102 &= ~ V_149 -> V_150 ;
if( V_148 ) * V_102 |= V_149 -> V_151 ;
else * V_102 &= ~ V_149 -> V_151 ;
return 1 ;
}
}
return 0 ;
}
void F_114 ( T_2 * V_24 , const char * V_152 , T_15 * V_153 , unsigned long V_154 )
{
char * V_8 ;
char V_155 = 0 ;
int V_156 = 0 ;
if( V_152 ) F_14 ( V_24 , V_152 ) ;
if( ( V_154 & V_116 ) == V_119 ) {
V_155 = 1 ;
V_156 = 4 ;
}
if( V_154 == V_114 ) {
V_8 = F_12 ( V_153 , 0 , 0 ) ;
F_14 ( V_24 , V_8 ) ;
F_14 ( V_24 , L_9 ) ;
F_2 ( V_8 ) ;
} else {
if( V_155 ) F_14 ( V_24 , L_9 ) ;
F_115 ( V_24 , V_153 , V_156 , V_154 ) ;
F_14 ( V_24 , L_9 ) ;
}
}
T_16 * F_116 ( T_2 * V_157 , char * V_158 , char * V_159 )
{
T_16 * V_160 ;
T_17 * V_161 ;
if( ! ( V_160 = F_117 () ) ) goto V_86;
V_161 = F_118 ( V_160 , F_119 () ) ;
if ( V_161 == NULL ) goto V_86;
if ( V_158 ) {
if( ! F_120 ( V_161 , V_158 , V_162 ) ) {
F_45 ( V_157 , L_68 , V_158 ) ;
goto V_86;
}
} else F_120 ( V_161 , NULL , V_163 ) ;
V_161 = F_118 ( V_160 , F_121 () ) ;
if ( V_161 == NULL ) goto V_86;
if ( V_159 ) {
if( ! F_122 ( V_161 , V_159 , V_162 ) ) {
F_45 ( V_157 , L_69 , V_159 ) ;
goto V_86;
}
} else F_122 ( V_161 , NULL , V_163 ) ;
F_62 () ;
return V_160 ;
V_86:
F_123 ( V_160 ) ;
return NULL ;
}
static T_7 * F_124 ( T_2 * V_59 , const char * V_164 , int V_165 )
{
T_7 * V_82 = F_125 ( L_70 ) ;
if ( V_82 )
{
if ( ! F_126 ( V_82 , L_71 , V_164 , 0 )
|| ! F_126 ( V_82 , L_72 , NULL , 0 ) )
{
F_127 ( V_82 ) ;
V_82 = NULL ;
}
}
return V_82 ;
}
T_7 * F_128 ( T_2 * V_59 , const char * V_164 , int V_165 )
{
T_7 * V_82 = NULL ;
if ( V_164 )
{
if( strcmp ( V_164 , L_73 ) == 0 )
{
F_45 ( V_59 , L_74 ) ;
F_129 () ;
return NULL ;
}
if( ( V_82 = F_125 ( V_164 ) ) == NULL
&& ( V_82 = F_124 ( V_59 , V_164 , V_165 ) ) == NULL )
{
F_45 ( V_59 , L_75 , V_164 ) ;
F_46 ( V_59 ) ;
return NULL ;
}
if ( V_165 )
{
F_130 ( V_82 , V_166 ,
0 , V_59 , 0 ) ;
}
F_131 ( V_82 , L_76 , 0 , V_43 , 0 , 1 ) ;
if( ! F_132 ( V_82 , V_167 ) )
{
F_45 ( V_59 , L_77 ) ;
F_46 ( V_59 ) ;
F_127 ( V_82 ) ;
return NULL ;
}
F_45 ( V_59 , L_78 , F_133 ( V_82 ) ) ;
F_127 ( V_82 ) ;
}
return V_82 ;
}
int F_134 ( T_2 * V_59 , T_6 * V_76 )
{
if ( ! V_76 )
V_76 = V_168 ;
if ( ! V_76 )
return 1 ;
F_135 () ;
if ( F_136 ( V_76 , NULL , 0 ) <= 0 )
{
F_45 ( V_59 , L_79 ) ;
F_46 ( V_59 ) ;
return 0 ;
}
return 1 ;
}
char * F_137 ()
{
const char * V_169 = F_138 () ;
T_18 V_7 ;
char * V_10 ;
V_7 = strlen ( V_169 ) + strlen ( V_170 ) + 2 ;
V_10 = F_3 ( V_7 ) ;
F_7 ( V_10 , V_169 , V_7 ) ;
#ifndef F_139
F_140 ( V_10 , L_80 , V_7 ) ;
#endif
F_140 ( V_10 , V_170 , V_7 ) ;
return V_10 ;
}
static unsigned long F_141 ( const char * * V_171 )
{
const char * V_26 ;
V_26 = V_171 [ V_172 ] ;
while ( * V_26 == '0' ) V_26 ++ ;
return ( F_142 ( V_26 ) ) ;
}
static int F_143 ( const char * * V_171 , const char * * V_173 )
{
const char * V_174 , * V_175 ;
for ( V_174 = V_171 [ V_172 ] ; * V_174 == '0' ; V_174 ++ ) ;
for ( V_175 = V_173 [ V_172 ] ; * V_175 == '0' ; V_175 ++ ) ;
return ( strcmp ( V_174 , V_175 ) ) ;
}
static int F_144 ( char * * V_171 )
{ return ( V_171 [ 0 ] [ 0 ] == 'V' ) ; }
static unsigned long F_145 ( const char * * V_171 )
{ return ( F_142 ( V_171 [ V_176 ] ) ) ; }
int F_146 ( const char * * V_171 , const char * * V_173 )
{ return ( strcmp ( V_171 [ V_176 ] ,
V_173 [ V_176 ] ) ) ; }
int F_147 ( char * V_177 , char * V_178 , char * V_179 )
{
char V_8 [ 5 ] [ V_180 ] ;
int V_6 , V_181 ;
struct V_11 V_182 ;
V_6 = strlen ( V_177 ) + strlen ( V_179 ) ;
V_181 = strlen ( V_177 ) + strlen ( V_178 ) ;
if ( V_6 > V_181 ) V_181 = V_6 ;
if ( V_181 + 1 >= V_180 )
{
F_45 ( V_58 , L_81 ) ;
goto V_59;
}
#ifndef F_139
V_181 = F_148 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_82 ,
V_177 , V_178 ) ;
#else
V_181 = F_148 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_83 ,
V_177 , V_178 ) ;
#endif
#ifndef F_139
V_181 = F_148 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_82 ,
V_177 , V_179 ) ;
#else
V_181 = F_148 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_83 ,
V_177 , V_179 ) ;
#endif
if ( V_11 ( V_177 , & V_182 ) < 0 )
{
if ( V_183 != V_184
#ifdef F_149
&& V_183 != F_149
#endif
)
goto V_59;
}
else
{
#ifdef F_150
F_45 ( V_58 , L_84 ,
V_177 , V_8 [ 1 ] ) ;
#endif
if ( rename ( V_177 , V_8 [ 1 ] ) < 0 )
{
F_45 ( V_58 ,
L_85 ,
V_177 , V_8 [ 1 ] ) ;
perror ( L_86 ) ;
goto V_59;
}
}
#ifdef F_150
F_45 ( V_58 , L_84 ,
V_8 [ 0 ] , V_177 ) ;
#endif
if ( rename ( V_8 [ 0 ] , V_177 ) < 0 )
{
F_45 ( V_58 ,
L_85 ,
V_8 [ 0 ] , V_177 ) ;
perror ( L_86 ) ;
rename ( V_8 [ 1 ] , V_177 ) ;
goto V_59;
}
return 1 ;
V_59:
return 0 ;
}
int F_151 ( T_19 * V_173 , T_20 * V_185 )
{
T_19 * V_70 ;
int V_143 = 0 ;
if ( V_173 )
V_70 = V_173 ;
else
V_70 = F_152 () ;
if ( ! V_70 )
return 0 ;
if ( ! F_153 ( V_70 , V_186 , 0 , 0 ) )
goto error;
if ( V_185 && ! F_154 ( V_70 , V_185 ) )
goto error;
V_143 = 1 ;
error:
if ( ! V_173 )
F_155 ( V_70 ) ;
return V_143 ;
}
T_21 * F_156 ( char * V_187 , T_22 * V_188 )
{
T_21 * V_189 = NULL ;
T_23 * V_190 = NULL ;
T_2 * V_23 = F_53 ( F_68 () ) ;
T_6 * V_191 = NULL ;
char V_8 [ 1 ] [ V_180 ] ;
long V_192 = - 1 ;
if ( V_23 == NULL )
{
F_46 ( V_58 ) ;
goto V_59;
}
if ( F_70 ( V_23 , V_187 ) <= 0 )
{
perror ( V_187 ) ;
F_45 ( V_58 , L_87 , V_187 ) ;
goto V_59;
}
if ( ( V_190 = F_157 ( V_23 , V_193 ) ) == NULL )
{
if ( V_190 != NULL ) F_158 ( V_190 ) ;
goto V_59;
}
#ifndef F_139
F_148 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_88 , V_187 ) ;
#else
F_148 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_89 , V_187 ) ;
#endif
V_191 = F_159 ( NULL ) ;
if ( F_160 ( V_191 , V_8 [ 0 ] , & V_192 ) <= 0 )
{
if ( V_192 > 0 )
{
F_45 ( V_58 ,
L_90
, V_192 , V_8 [ 0 ] ) ;
goto V_59;
}
else
{
F_161 ( V_191 ) ;
V_191 = NULL ;
}
}
if ( ( V_189 = F_3 ( sizeof( T_21 ) ) ) == NULL )
{
fprintf ( V_194 , L_91 ) ;
goto V_59;
}
V_189 -> V_195 = V_190 ;
V_190 = NULL ;
if ( V_188 )
V_189 -> V_196 = * V_188 ;
else
{
V_189 -> V_196 . V_197 = 1 ;
}
if ( V_191 )
{
char * V_10 = F_61 ( V_191 , NULL , L_92 ) ;
if ( V_10 )
{
#ifdef F_150
F_45 ( V_58 , L_93 , V_10 ) ;
#endif
V_189 -> V_196 . V_197 = F_162 ( V_10 , 1 ) ;
}
}
V_59:
if ( V_191 ) F_161 ( V_191 ) ;
if ( V_190 ) F_158 ( V_190 ) ;
if ( V_23 ) F_58 ( V_23 ) ;
return V_189 ;
}
int F_163 ( T_21 * V_195 )
{
if ( ! F_164 ( V_195 -> V_195 , V_172 , NULL ,
F_165 ( F_141 ) ,
F_166 ( F_143 ) ) )
{
F_45 ( V_58 ,
L_94 ,
V_195 -> V_195 -> error , V_195 -> V_195 -> V_60 , V_195 -> V_195 -> V_61 ) ;
return 0 ;
}
if ( V_195 -> V_196 . V_197
&& ! F_164 ( V_195 -> V_195 , V_176 , F_144 ,
F_165 ( F_145 ) ,
F_166 ( F_146 ) ) )
{
F_45 ( V_58 , L_95 ,
V_195 -> V_195 -> error , V_195 -> V_195 -> V_60 , V_195 -> V_195 -> V_61 ) ;
return 0 ;
}
return 1 ;
}
int F_167 ( const char * V_187 , const char * V_198 , T_21 * V_195 )
{
char V_8 [ 3 ] [ V_180 ] ;
T_2 * V_24 = F_53 ( F_68 () ) ;
int V_181 ;
if ( V_24 == NULL )
{
F_46 ( V_58 ) ;
goto V_59;
}
V_181 = strlen ( V_187 ) + strlen ( V_198 ) ;
if ( V_181 + 6 >= V_180 )
{
F_45 ( V_58 , L_81 ) ;
goto V_59;
}
#ifndef F_139
V_181 = F_148 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_88 , V_187 ) ;
#else
V_181 = F_148 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_89 , V_187 ) ;
#endif
#ifndef F_139
V_181 = F_148 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_96 , V_187 , V_198 ) ;
#else
V_181 = F_148 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_97 , V_187 , V_198 ) ;
#endif
#ifndef F_139
V_181 = F_148 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_82 , V_187 , V_198 ) ;
#else
V_181 = F_148 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_83 , V_187 , V_198 ) ;
#endif
#ifdef F_150
F_45 ( V_58 , L_98 , V_8 [ 0 ] ) ;
#endif
if ( F_168 ( V_24 , V_8 [ 0 ] ) <= 0 )
{
perror ( V_187 ) ;
F_45 ( V_58 , L_87 , V_187 ) ;
goto V_59;
}
V_181 = F_169 ( V_24 , V_195 -> V_195 ) ;
if ( V_181 <= 0 ) goto V_59;
F_80 ( V_24 ) ;
V_24 = F_53 ( F_68 () ) ;
#ifdef F_150
F_45 ( V_58 , L_98 , V_8 [ 1 ] ) ;
#endif
if ( F_168 ( V_24 , V_8 [ 1 ] ) <= 0 )
{
perror ( V_8 [ 2 ] ) ;
F_45 ( V_58 , L_87 , V_8 [ 2 ] ) ;
goto V_59;
}
F_45 ( V_24 , L_99 ,
V_195 -> V_196 . V_197 ? L_100 : L_101 ) ;
F_80 ( V_24 ) ;
return 1 ;
V_59:
return 0 ;
}
int F_170 ( const char * V_187 , const char * V_178 , const char * V_179 )
{
char V_8 [ 5 ] [ V_180 ] ;
int V_6 , V_181 ;
struct V_11 V_182 ;
V_6 = strlen ( V_187 ) + strlen ( V_179 ) ;
V_181 = strlen ( V_187 ) + strlen ( V_178 ) ;
if ( V_6 > V_181 ) V_181 = V_6 ;
if ( V_181 + 6 >= V_180 )
{
F_45 ( V_58 , L_81 ) ;
goto V_59;
}
#ifndef F_139
V_181 = F_148 ( V_8 [ 4 ] , sizeof V_8 [ 4 ] , L_88 , V_187 ) ;
#else
V_181 = F_148 ( V_8 [ 4 ] , sizeof V_8 [ 4 ] , L_89 , V_187 ) ;
#endif
#ifndef F_139
V_181 = F_148 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_96 ,
V_187 , V_178 ) ;
#else
V_181 = F_148 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_97 ,
V_187 , V_178 ) ;
#endif
#ifndef F_139
V_181 = F_148 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_82 ,
V_187 , V_178 ) ;
#else
V_181 = F_148 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_83 ,
V_187 , V_178 ) ;
#endif
#ifndef F_139
V_181 = F_148 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_82 ,
V_187 , V_179 ) ;
#else
V_181 = F_148 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_83 ,
V_187 , V_179 ) ;
#endif
#ifndef F_139
V_181 = F_148 ( V_8 [ 3 ] , sizeof V_8 [ 3 ] , L_96 ,
V_187 , V_179 ) ;
#else
V_181 = F_148 ( V_8 [ 3 ] , sizeof V_8 [ 3 ] , L_97 ,
V_187 , V_179 ) ;
#endif
if ( V_11 ( V_187 , & V_182 ) < 0 )
{
if ( V_183 != V_184
#ifdef F_149
&& V_183 != F_149
#endif
)
goto V_59;
}
else
{
#ifdef F_150
F_45 ( V_58 , L_84 ,
V_187 , V_8 [ 1 ] ) ;
#endif
if ( rename ( V_187 , V_8 [ 1 ] ) < 0 )
{
F_45 ( V_58 ,
L_85 ,
V_187 , V_8 [ 1 ] ) ;
perror ( L_86 ) ;
goto V_59;
}
}
#ifdef F_150
F_45 ( V_58 , L_84 ,
V_8 [ 0 ] , V_187 ) ;
#endif
if ( rename ( V_8 [ 0 ] , V_187 ) < 0 )
{
F_45 ( V_58 ,
L_85 ,
V_8 [ 0 ] , V_187 ) ;
perror ( L_86 ) ;
rename ( V_8 [ 1 ] , V_187 ) ;
goto V_59;
}
if ( V_11 ( V_8 [ 4 ] , & V_182 ) < 0 )
{
if ( V_183 != V_184
#ifdef F_149
&& V_183 != F_149
#endif
)
goto V_59;
}
else
{
#ifdef F_150
F_45 ( V_58 , L_84 ,
V_8 [ 4 ] , V_8 [ 3 ] ) ;
#endif
if ( rename ( V_8 [ 4 ] , V_8 [ 3 ] ) < 0 )
{
F_45 ( V_58 ,
L_85 ,
V_8 [ 4 ] , V_8 [ 3 ] ) ;
perror ( L_86 ) ;
rename ( V_187 , V_8 [ 0 ] ) ;
rename ( V_8 [ 1 ] , V_187 ) ;
goto V_59;
}
}
#ifdef F_150
F_45 ( V_58 , L_84 ,
V_8 [ 2 ] , V_8 [ 4 ] ) ;
#endif
if ( rename ( V_8 [ 2 ] , V_8 [ 4 ] ) < 0 )
{
F_45 ( V_58 ,
L_85 ,
V_8 [ 2 ] , V_8 [ 4 ] ) ;
perror ( L_86 ) ;
rename ( V_8 [ 3 ] , V_8 [ 4 ] ) ;
rename ( V_187 , V_8 [ 0 ] ) ;
rename ( V_8 [ 1 ] , V_187 ) ;
goto V_59;
}
return 1 ;
V_59:
return 0 ;
}
void F_171 ( T_21 * V_195 )
{
if ( V_195 )
{
if ( V_195 -> V_195 ) F_158 ( V_195 -> V_195 ) ;
F_2 ( V_195 ) ;
}
}
int F_162 ( const char * V_199 , int V_200 )
{
int V_143 = V_200 ;
if ( V_199 )
{
switch ( * V_199 )
{
case 'f' :
case 'F' :
case 'n' :
case 'N' :
case '0' :
V_143 = 0 ;
break;
case 't' :
case 'T' :
case 'y' :
case 'Y' :
case '1' :
V_143 = 0 ;
break;
default:
V_143 = V_200 ;
break;
}
}
return V_143 ;
}
T_15 * F_172 ( char * V_201 , long V_202 , int V_203 )
{
T_18 V_204 = strlen ( V_201 ) + 1 ;
char * V_8 = F_3 ( V_204 ) ;
T_18 V_205 = V_204 / 2 + 1 ;
char * * V_206 = F_3 ( V_205 * sizeof ( char * ) ) ;
char * * V_207 = F_3 ( V_205 * sizeof ( char * ) ) ;
int * V_208 = F_3 ( V_205 * sizeof ( int ) ) ;
char * V_209 = V_201 , * V_157 = V_8 ;
int V_6 , V_210 = 0 ;
T_15 * V_26 = NULL ;
int V_211 ;
if ( ! V_8 || ! V_206 || ! V_207 )
{
F_45 ( V_58 , L_102 ) ;
goto error;
}
if ( * V_201 != '/' )
{
F_45 ( V_58 , L_103 ) ;
goto error;
}
V_209 ++ ;
V_208 [ V_210 ] = 0 ;
while ( * V_209 )
{
V_206 [ V_210 ] = V_157 ;
while ( * V_209 )
{
if ( * V_209 == '\\' )
{
if ( * ++ V_209 )
* V_157 ++ = * V_209 ++ ;
else
{
F_45 ( V_58 , L_104 ) ;
goto error;
}
}
else if ( * V_209 == '=' )
{
V_209 ++ ;
* V_157 ++ = '\0' ;
break;
}
else
* V_157 ++ = * V_209 ++ ;
}
if ( ! * V_209 )
{
F_45 ( V_58 , L_105 , V_210 ) ;
goto error;
}
V_207 [ V_210 ] = V_157 ;
while ( * V_209 )
{
if ( * V_209 == '\\' )
{
if ( * ++ V_209 )
* V_157 ++ = * V_209 ++ ;
else
{
F_45 ( V_58 , L_104 ) ;
goto error;
}
}
else if ( * V_209 == '/' )
{
V_209 ++ ;
V_208 [ V_210 + 1 ] = 0 ;
break;
}
else if ( * V_209 == '+' && V_203 )
{
V_209 ++ ;
V_208 [ V_210 + 1 ] = - 1 ;
break;
}
else
* V_157 ++ = * V_209 ++ ;
}
* V_157 ++ = '\0' ;
V_210 ++ ;
}
if ( ! ( V_26 = F_173 () ) )
goto error;
for ( V_6 = 0 ; V_6 < V_210 ; V_6 ++ )
{
if ( ( V_211 = F_174 ( V_206 [ V_6 ] ) ) == V_79 )
{
F_45 ( V_58 , L_106 , V_206 [ V_6 ] ) ;
continue;
}
if ( ! * V_207 [ V_6 ] )
{
F_45 ( V_58 , L_107 , V_206 [ V_6 ] ) ;
continue;
}
if ( ! F_175 ( V_26 , V_211 , V_202 , ( unsigned char * ) V_207 [ V_6 ] , - 1 , - 1 , V_208 [ V_6 ] ) )
goto error;
}
F_2 ( V_207 ) ;
F_2 ( V_206 ) ;
F_2 ( V_8 ) ;
return V_26 ;
error:
F_176 ( V_26 ) ;
if ( V_207 )
F_2 ( V_207 ) ;
if ( V_206 )
F_2 ( V_206 ) ;
if ( V_8 )
F_2 ( V_8 ) ;
return NULL ;
}
int F_177 ( const char * V_212 , const char * V_213 )
{
#ifndef F_178
if( ( remove ( V_213 ) != 0 ) && ( V_183 != V_184 ) )
return - 1 ;
#undef rename
return rename ( V_212 , V_213 ) ;
#else
{
BOOL V_214 = FALSE ;
T_24 * V_215 ;
T_24 * V_216 ;
int V_6 ;
V_215 = malloc ( ( strlen ( V_212 ) + 1 ) * 2 ) ;
V_216 = malloc ( ( strlen ( V_213 ) + 1 ) * 2 ) ;
if ( V_215 != NULL && V_216 != NULL )
{
for ( V_6 = 0 ; V_6 < ( int ) strlen ( V_212 ) + 1 ; V_6 ++ )
V_215 [ V_6 ] = ( short ) V_212 [ V_6 ] ;
for ( V_6 = 0 ; V_6 < ( int ) strlen ( V_213 ) + 1 ; V_6 ++ )
V_216 [ V_6 ] = ( short ) V_213 [ V_6 ] ;
V_214 = F_179 ( V_215 , V_216 ) ;
}
if ( V_215 != NULL )
free ( V_215 ) ;
if ( V_216 != NULL )
free ( V_216 ) ;
return V_214 ;
}
#endif
}
int F_180 ( char * * * V_217 , int * V_218 ,
int * V_219 , T_2 * V_59 , T_25 * * V_220 )
{
T_14 * V_221 = NULL ;
unsigned long V_102 = 0 ;
int V_6 ;
int V_222 = 0 ;
char * * V_223 = * V_217 ;
char * V_9 = * * V_217 , * V_224 = ( * V_217 ) [ 1 ] ;
if ( ! strcmp ( V_9 , L_108 ) )
{
if ( ! V_224 )
* V_219 = 1 ;
else
{
V_221 = F_181 ( V_224 , 0 ) ;
if ( ! V_221 )
{
F_45 ( V_59 , L_109 ,
V_224 ) ;
* V_219 = 1 ;
}
}
( * V_217 ) ++ ;
}
else if ( strcmp ( V_9 , L_110 ) == 0 )
{
T_26 * V_225 ;
if ( ! V_224 )
* V_219 = 1 ;
else
{
V_6 = F_182 ( V_224 ) ;
if( V_6 < 0 )
{
F_45 ( V_59 , L_111 ) ;
* V_219 = 1 ;
}
else
{
V_225 = F_183 ( V_6 ) ;
V_222 = F_184 ( V_225 ) ;
}
}
( * V_217 ) ++ ;
}
else if ( ! strcmp ( V_9 , L_112 ) )
V_102 |= V_226 ;
else if ( ! strcmp ( V_9 , L_113 ) )
V_102 |= V_227 ;
else if ( ! strcmp ( V_9 , L_114 ) )
V_102 |= V_228 ;
else if ( ! strcmp ( V_9 , L_115 ) )
V_102 |= V_228 | V_229 ;
else if ( ! strcmp ( V_9 , L_116 ) )
V_102 |= V_230 ;
else if ( ! strcmp ( V_9 , L_117 ) )
V_102 |= V_231 ;
else if ( ! strcmp ( V_9 , L_118 ) )
V_102 |= V_232 ;
else if ( ! strcmp ( V_9 , L_119 ) )
V_102 |= V_233 ;
else
return 0 ;
if ( * V_219 )
{
if ( * V_220 )
F_185 ( * V_220 ) ;
* V_220 = NULL ;
goto V_86;
}
if ( ! * V_220 && ! ( * V_220 = F_186 () ) )
{
* V_219 = 1 ;
goto V_86;
}
if ( V_221 )
F_187 ( * V_220 , V_221 ) ;
if ( V_102 )
F_188 ( * V_220 , V_102 ) ;
if ( V_222 )
F_189 ( * V_220 , V_222 ) ;
V_86:
( * V_217 ) ++ ;
if ( V_218 )
* V_218 -= * V_217 - V_223 ;
return 1 ;
}
void F_190 ( T_2 * V_24 , T_27 * V_234 )
{
T_28 * V_235 ;
int V_236 ;
int V_237 = 0 ;
if ( V_24 == NULL )
{
V_24 = F_56 ( V_194 , V_71 ) ;
V_237 = 1 ;
}
V_235 = F_191 ( V_234 ) ;
V_236 = F_192 ( V_234 ) ;
F_45 ( V_24 , L_120 ,
V_236 ? L_121 : L_122 ) ;
F_193 ( V_24 , L_123 , F_194 ( V_235 ) ) ;
F_193 ( V_24 , L_124 , F_195 ( V_235 ) ) ;
if ( V_237 )
F_80 ( V_24 ) ;
}
