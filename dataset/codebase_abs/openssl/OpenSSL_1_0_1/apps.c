int F_1 ( char * V_1 , int * V_2 , char * * V_3 [] )
{
T_1 * V_4 ;
int V_5 , V_6 ;
unsigned int V_7 ;
static char * V_8 = NULL ;
static char * * V_9 = NULL ;
char * V_10 ;
V_4 = fopen ( V_1 , L_1 ) ;
if ( V_4 == NULL )
return ( 0 ) ;
if ( fseek ( V_4 , 0 , V_11 ) == 0 )
V_7 = ftell ( V_4 ) , rewind ( V_4 ) ;
else V_7 = - 1 ;
if ( V_7 <= 0 )
{
fclose ( V_4 ) ;
return ( 0 ) ;
}
* V_2 = 0 ;
* V_3 = NULL ;
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
int F_4 ( char * V_12 )
{
if ( V_12 == NULL )
return V_13 ;
if ( ( * V_12 == 'D' ) || ( * V_12 == 'd' ) )
return ( V_14 ) ;
else if ( ( * V_12 == 'T' ) || ( * V_12 == 't' ) )
return ( V_15 ) ;
else if ( ( * V_12 == 'N' ) || ( * V_12 == 'n' ) )
return ( V_16 ) ;
else if ( ( * V_12 == 'S' ) || ( * V_12 == 's' ) )
return ( V_17 ) ;
else if ( ( * V_12 == 'M' ) || ( * V_12 == 'm' ) )
return ( V_18 ) ;
else if ( ( * V_12 == '1' )
|| ( strcmp ( V_12 , L_2 ) == 0 ) || ( strcmp ( V_12 , L_3 ) == 0 )
|| ( strcmp ( V_12 , L_4 ) == 0 ) || ( strcmp ( V_12 , L_5 ) == 0 ) )
return ( V_19 ) ;
else if ( ( * V_12 == 'E' ) || ( * V_12 == 'e' ) )
return ( V_20 ) ;
else if ( ( * V_12 == 'P' ) || ( * V_12 == 'p' ) )
{
if ( V_12 [ 1 ] == 'V' || V_12 [ 1 ] == 'v' )
return V_21 ;
else
return ( V_22 ) ;
}
else
return ( V_13 ) ;
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
int V_5 , V_6 ;
char * V_10 ;
* V_2 = 0 ;
* V_3 = NULL ;
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
#if ! F_6 ( V_70 )
} else if( ! strncmp ( V_9 , L_19 , 3 ) ) {
T_2 * V_71 ;
V_6 = atoi ( V_9 + 3 ) ;
if( V_6 >= 0 ) V_69 = F_52 ( V_6 , V_72 ) ;
if( ( V_6 < 0 ) || ! V_69 ) {
F_45 ( V_59 , L_20 , V_9 + 3 ) ;
return NULL ;
}
V_71 = F_53 ( F_54 () ) ;
V_69 = F_55 ( V_71 , V_69 ) ;
#endif
} else if( ! strcmp ( V_9 , L_21 ) ) {
V_69 = F_56 ( V_73 , V_72 ) ;
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
int F_59 ( T_2 * V_59 , T_6 * V_74 )
{
char * V_10 ;
F_60 ( V_75 ) * V_76 ;
V_75 * V_77 ;
int V_6 ;
if( ! ( V_10 = F_61 ( V_74 , NULL , L_25 ) ) )
{
F_62 () ;
return 1 ;
}
if( ! ( V_76 = F_63 ( V_74 , V_10 ) ) ) {
F_45 ( V_59 , L_26 , V_10 ) ;
return 0 ;
}
for( V_6 = 0 ; V_6 < F_64 ( V_76 ) ; V_6 ++ ) {
V_77 = F_65 ( V_76 , V_6 ) ;
if( F_66 ( V_77 -> V_78 , V_77 -> V_79 , V_77 -> V_79 ) == V_80 ) {
F_45 ( V_59 , L_27 ,
V_77 -> V_79 , V_77 -> V_78 ) ;
return 0 ;
}
}
return 1 ;
}
T_3 * F_67 ( T_2 * V_59 , const char * V_1 , int V_81 ,
const char * V_82 , T_7 * V_83 , const char * V_84 )
{
T_3 * V_35 = NULL ;
T_2 * V_85 ;
if ( ( V_85 = F_53 ( F_68 () ) ) == NULL )
{
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_1 == NULL )
{
#ifdef F_69
# ifndef F_70
setvbuf ( V_73 , NULL , F_69 , 0 ) ;
# endif
#endif
F_71 ( V_85 , V_73 , V_72 ) ;
}
else
{
if ( F_72 ( V_85 , V_1 ) <= 0 )
{
F_45 ( V_59 , L_28 ,
V_84 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_86;
}
}
if ( V_81 == V_14 )
V_35 = F_73 ( V_85 , NULL ) ;
else if ( V_81 == V_16 )
{
T_8 * V_87 ;
V_87 = F_74 ( F_75 ( T_8 ) , V_85 , NULL ) ;
if ( V_87 == NULL )
goto V_86;
if ( ( strncmp ( V_88 , ( char * ) V_87 -> V_89 -> V_31 ,
V_87 -> V_89 -> V_90 ) != 0 ) )
{
F_76 ( V_87 ) ;
F_45 ( V_59 , L_29 ) ;
goto V_86;
}
V_35 = V_87 -> V_85 ;
V_87 -> V_85 = NULL ;
F_76 ( V_87 ) ;
}
else if ( V_81 == V_22 )
V_35 = F_77 ( V_85 , NULL ,
( V_91 * ) F_37 , NULL ) ;
else if ( V_81 == V_19 )
{
if ( ! F_78 ( V_59 , V_85 , V_84 , NULL , NULL ,
NULL , & V_35 , NULL ) )
goto V_86;
}
else {
F_45 ( V_59 , L_30 ,
V_84 ) ;
goto V_86;
}
V_86:
if ( V_35 == NULL )
{
F_45 ( V_59 , L_31 ) ;
F_46 ( V_59 ) ;
}
if ( V_85 != NULL ) F_79 ( V_85 ) ;
return ( V_35 ) ;
}
T_9 * F_80 ( T_2 * V_59 , const char * V_1 , int V_81 , int V_92 ,
const char * V_82 , T_7 * V_83 , const char * V_93 )
{
T_2 * V_94 = NULL ;
T_9 * V_95 = NULL ;
V_42 V_49 ;
V_49 . V_41 = V_82 ;
V_49 . V_48 = V_1 ;
if ( V_1 == NULL && ( ! V_92 || V_81 == V_20 ) )
{
F_45 ( V_59 , L_32 ) ;
goto V_86;
}
#ifndef F_81
if ( V_81 == V_20 )
{
if ( ! V_83 )
F_45 ( V_59 , L_33 ) ;
else
{
V_95 = F_82 ( V_83 , V_1 ,
V_43 , & V_49 ) ;
if ( ! V_95 )
{
F_45 ( V_59 , L_34 , V_93 ) ;
F_46 ( V_59 ) ;
}
}
goto V_86;
}
#endif
V_94 = F_53 ( F_68 () ) ;
if ( V_94 == NULL )
{
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_1 == NULL && V_92 )
{
#ifdef F_69
# ifndef F_70
setvbuf ( V_73 , NULL , F_69 , 0 ) ;
# endif
#endif
F_71 ( V_94 , V_73 , V_72 ) ;
}
else
if ( F_72 ( V_94 , V_1 ) <= 0 )
{
F_45 ( V_59 , L_28 ,
V_93 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_81 == V_14 )
{
V_95 = F_83 ( V_94 , NULL ) ;
}
else if ( V_81 == V_22 )
{
V_95 = F_84 ( V_94 , NULL ,
( V_91 * ) F_37 , & V_49 ) ;
}
#if ! F_6 ( V_96 ) && ! F_6 ( V_97 )
else if ( V_81 == V_16 || V_81 == V_98 )
V_95 = F_85 ( V_59 , V_94 , V_1 , V_93 , V_81 ) ;
#endif
else if ( V_81 == V_19 )
{
if ( ! F_78 ( V_59 , V_94 , V_93 ,
( V_91 * ) F_37 , & V_49 ,
& V_95 , NULL , NULL ) )
goto V_86;
}
#if ! F_6 ( V_97 ) && ! F_6 ( V_99 ) && ! F_6 ( V_96 )
else if ( V_81 == V_18 )
V_95 = F_86 ( V_94 ) ;
else if ( V_81 == V_21 )
V_95 = F_87 ( V_94 , ( V_91 * ) F_37 ,
& V_49 ) ;
#endif
else
{
F_45 ( V_59 , L_35 ) ;
goto V_86;
}
V_86:
if ( V_94 != NULL ) F_79 ( V_94 ) ;
if ( V_95 == NULL )
{
F_45 ( V_59 , L_36 , V_93 ) ;
F_46 ( V_59 ) ;
}
return ( V_95 ) ;
}
T_9 * F_88 ( T_2 * V_59 , const char * V_1 , int V_81 , int V_92 ,
const char * V_82 , T_7 * V_83 , const char * V_93 )
{
T_2 * V_94 = NULL ;
T_9 * V_95 = NULL ;
V_42 V_49 ;
V_49 . V_41 = V_82 ;
V_49 . V_48 = V_1 ;
if ( V_1 == NULL && ( ! V_92 || V_81 == V_20 ) )
{
F_45 ( V_59 , L_32 ) ;
goto V_86;
}
#ifndef F_81
if ( V_81 == V_20 )
{
if ( ! V_83 )
F_45 ( V_58 , L_33 ) ;
else
V_95 = F_89 ( V_83 , V_1 ,
V_43 , & V_49 ) ;
goto V_86;
}
#endif
V_94 = F_53 ( F_68 () ) ;
if ( V_94 == NULL )
{
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_1 == NULL && V_92 )
{
#ifdef F_69
# ifndef F_70
setvbuf ( V_73 , NULL , F_69 , 0 ) ;
# endif
#endif
F_71 ( V_94 , V_73 , V_72 ) ;
}
else
if ( F_72 ( V_94 , V_1 ) <= 0 )
{
F_45 ( V_59 , L_28 ,
V_93 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_81 == V_14 )
{
V_95 = F_90 ( V_94 , NULL ) ;
}
#ifndef V_97
else if ( V_81 == V_100 )
{
T_10 * V_101 ;
V_101 = F_91 ( V_94 , NULL ) ;
if ( V_101 )
{
V_95 = F_92 () ;
if ( V_95 )
F_93 ( V_95 , V_101 ) ;
F_94 ( V_101 ) ;
}
else
V_95 = NULL ;
}
else if ( V_81 == V_102 )
{
T_10 * V_101 ;
V_101 = F_95 ( V_94 , NULL ,
( V_91 * ) F_37 , & V_49 ) ;
if ( V_101 )
{
V_95 = F_92 () ;
if ( V_95 )
F_93 ( V_95 , V_101 ) ;
F_94 ( V_101 ) ;
}
else
V_95 = NULL ;
}
#endif
else if ( V_81 == V_22 )
{
V_95 = F_96 ( V_94 , NULL ,
( V_91 * ) F_37 , & V_49 ) ;
}
#if ! F_6 ( V_96 ) && ! F_6 ( V_97 )
else if ( V_81 == V_16 || V_81 == V_98 )
V_95 = F_85 ( V_59 , V_94 , V_1 , V_93 , V_81 ) ;
#endif
#if ! F_6 ( V_97 ) && ! F_6 ( V_99 )
else if ( V_81 == V_18 )
V_95 = F_97 ( V_94 ) ;
#endif
else
{
F_45 ( V_59 , L_35 ) ;
goto V_86;
}
V_86:
if ( V_94 != NULL ) F_79 ( V_94 ) ;
if ( V_95 == NULL )
F_45 ( V_59 , L_36 , V_93 ) ;
return ( V_95 ) ;
}
static T_9 *
F_85 ( T_2 * V_59 , T_2 * V_94 , const char * V_1 ,
const char * V_93 , int V_81 )
{
T_9 * V_95 ;
T_11 * V_8 ;
T_10 * V_101 ;
const unsigned char * V_10 ;
int V_25 , V_6 ;
V_8 = F_98 () ;
V_95 = F_92 () ;
V_25 = 0 ;
if ( V_8 == NULL || V_95 == NULL )
goto error;
for (; ; )
{
if ( ! F_99 ( V_8 , V_25 + 1024 * 10 ) )
goto error;
V_6 = F_100 ( V_94 , & ( V_8 -> V_31 [ V_25 ] ) , 1024 * 10 ) ;
V_25 += V_6 ;
if ( V_6 == 0 )
break;
if ( V_6 < 0 )
{
F_45 ( V_59 , L_37 ,
V_93 , V_1 ) ;
goto error;
}
}
V_10 = ( unsigned char * ) V_8 -> V_31 ;
V_101 = F_101 ( NULL , & V_10 , ( long ) V_25 , NULL ,
( V_81 == V_98 ? 1 : 0 ) ) ;
if ( V_101 == NULL )
goto error;
F_102 ( V_8 ) ;
F_93 ( V_95 , V_101 ) ;
return V_95 ;
error:
F_102 ( V_8 ) ;
F_103 ( V_95 ) ;
return NULL ;
}
int F_104 ( unsigned long * V_103 , const char * V_9 )
{
static const T_12 V_104 [] = {
{ L_38 , V_105 , 0 } ,
{ L_39 , V_106 , 0 } ,
{ L_40 , V_107 , 0 } ,
{ L_41 , V_108 , 0 } ,
{ L_42 , V_109 , 0 } ,
{ L_43 , V_110 , 0 } ,
{ L_44 , V_111 , 0 } ,
{ L_45 , V_112 , 0 } ,
{ L_46 , V_113 , 0 } ,
{ L_47 , V_114 , 0 } ,
{ L_48 , V_115 , 0xffffffffL } ,
{ L_49 , V_116 , V_117 } ,
{ L_50 , V_118 , V_117 } ,
{ L_51 , V_119 , V_117 } ,
{ L_52 , V_120 , V_117 } ,
{ L_53 , V_121 , 0 } ,
{ L_54 , V_122 , V_123 } ,
{ L_55 , V_124 , V_123 } ,
{ L_56 , V_125 , V_123 } ,
{ L_57 , V_126 , 0 } ,
{ L_58 , V_127 , V_123 } ,
{ L_59 , V_128 , 0 } ,
{ L_60 , V_129 , 0 } ,
{ L_61 , V_130 , 0xffffffffL } ,
{ L_62 , V_131 , 0xffffffffL } ,
{ L_63 , V_132 , 0xffffffffL } ,
{ L_64 , V_132 , 0xffffffffL } ,
{ NULL , 0 , 0 }
} ;
return F_105 ( V_103 , V_9 , V_104 ) ;
}
int F_106 ( int * V_133 , const char * V_9 )
{
if ( ! strcasecmp ( V_9 , L_65 ) )
* V_133 = V_134 ;
else if ( ! strcasecmp ( V_9 , L_66 ) )
* V_133 = V_135 ;
else if ( ! strcasecmp ( V_9 , L_67 ) )
* V_133 = V_136 ;
else
return 0 ;
return 1 ;
}
int F_107 ( T_3 * V_35 , T_13 * V_137 , int V_133 )
{
F_60 ( V_138 ) * V_139 = NULL ;
V_138 * V_140 , * V_141 ;
T_14 * V_142 ;
int V_6 , V_143 , V_144 = 0 ;
if ( ! V_35 || ! V_137 || ( V_133 == V_134 ) )
return 1 ;
V_139 = F_108 ( V_137 ) ;
for( V_6 = 0 ; V_6 < F_109 ( V_139 ) ; V_6 ++ ) {
V_140 = F_110 ( V_139 , V_6 ) ;
V_142 = F_111 ( V_140 ) ;
V_143 = F_112 ( V_35 , V_142 , - 1 ) ;
if ( V_143 != - 1 ) {
if ( V_133 == V_135 )
continue;
do {
V_141 = F_113 ( V_35 , V_143 ) ;
F_114 ( V_35 , V_143 ) ;
F_115 ( V_141 ) ;
V_143 = F_112 ( V_35 , V_142 , - 1 ) ;
} while ( V_143 != - 1 );
}
if ( ! F_116 ( V_35 , V_140 , - 1 ) )
goto V_86;
}
V_144 = 1 ;
V_86:
F_117 ( V_139 , F_115 ) ;
return V_144 ;
}
static int F_105 ( unsigned long * V_103 , const char * V_9 , const T_12 * V_145 )
{
F_60 ( V_75 ) * V_146 ;
V_75 * V_147 ;
int V_6 , V_144 = 1 ;
if( ! V_9 ) return 0 ;
V_146 = F_118 ( V_9 ) ;
for ( V_6 = 0 ; V_6 < F_64 ( V_146 ) ; V_6 ++ ) {
V_147 = F_65 ( V_146 , V_6 ) ;
if ( ! F_119 ( V_103 , V_147 -> V_79 , V_145 ) )
V_144 = 0 ;
}
F_120 ( V_146 , V_148 ) ;
return V_144 ;
}
static int F_119 ( unsigned long * V_103 , const char * V_9 , const T_12 * V_145 )
{
char V_149 ;
const T_12 * V_150 ;
V_149 = V_9 [ 0 ] ;
if( V_149 == '-' ) {
V_149 = 0 ;
V_9 ++ ;
} else if ( V_149 == '+' ) {
V_149 = 1 ;
V_9 ++ ;
} else V_149 = 1 ;
for( V_150 = V_145 ; V_150 -> V_79 ; V_150 ++ ) {
if( ! strcasecmp ( V_9 , V_150 -> V_79 ) ) {
* V_103 &= ~ V_150 -> V_151 ;
if( V_149 ) * V_103 |= V_150 -> V_152 ;
else * V_103 &= ~ V_150 -> V_152 ;
return 1 ;
}
}
return 0 ;
}
void F_121 ( T_2 * V_24 , const char * V_153 , T_15 * V_154 , unsigned long V_155 )
{
char * V_8 ;
char V_156 = 0 ;
int V_157 = 0 ;
if( V_153 ) F_14 ( V_24 , V_153 ) ;
if( ( V_155 & V_117 ) == V_120 ) {
V_156 = 1 ;
V_157 = 4 ;
}
if( V_155 == V_115 ) {
V_8 = F_12 ( V_154 , 0 , 0 ) ;
F_14 ( V_24 , V_8 ) ;
F_14 ( V_24 , L_9 ) ;
F_2 ( V_8 ) ;
} else {
if( V_156 ) F_14 ( V_24 , L_9 ) ;
F_122 ( V_24 , V_154 , V_157 , V_155 ) ;
F_14 ( V_24 , L_9 ) ;
}
}
T_16 * F_123 ( T_2 * V_158 , char * V_159 , char * V_160 )
{
T_16 * V_161 ;
T_17 * V_162 ;
if( ! ( V_161 = F_124 () ) ) goto V_86;
V_162 = F_125 ( V_161 , F_126 () ) ;
if ( V_162 == NULL ) goto V_86;
if ( V_159 ) {
if( ! F_127 ( V_162 , V_159 , V_163 ) ) {
F_45 ( V_158 , L_68 , V_159 ) ;
goto V_86;
}
} else F_127 ( V_162 , NULL , V_164 ) ;
V_162 = F_125 ( V_161 , F_128 () ) ;
if ( V_162 == NULL ) goto V_86;
if ( V_160 ) {
if( ! F_129 ( V_162 , V_160 , V_163 ) ) {
F_45 ( V_158 , L_69 , V_160 ) ;
goto V_86;
}
} else F_129 ( V_162 , NULL , V_164 ) ;
F_62 () ;
return V_161 ;
V_86:
F_130 ( V_161 ) ;
return NULL ;
}
static T_7 * F_131 ( T_2 * V_59 , const char * V_165 , int V_166 )
{
T_7 * V_83 = F_132 ( L_70 ) ;
if ( V_83 )
{
if ( ! F_133 ( V_83 , L_71 , V_165 , 0 )
|| ! F_133 ( V_83 , L_72 , NULL , 0 ) )
{
F_134 ( V_83 ) ;
V_83 = NULL ;
}
}
return V_83 ;
}
T_7 * F_135 ( T_2 * V_59 , const char * V_165 , int V_166 )
{
T_7 * V_83 = NULL ;
if ( V_165 )
{
if( strcmp ( V_165 , L_73 ) == 0 )
{
F_45 ( V_59 , L_74 ) ;
F_136 () ;
return NULL ;
}
if( ( V_83 = F_132 ( V_165 ) ) == NULL
&& ( V_83 = F_131 ( V_59 , V_165 , V_166 ) ) == NULL )
{
F_45 ( V_59 , L_75 , V_165 ) ;
F_46 ( V_59 ) ;
return NULL ;
}
if ( V_166 )
{
F_137 ( V_83 , V_167 ,
0 , V_59 , 0 ) ;
}
F_138 ( V_83 , L_76 , 0 , V_43 , 0 , 1 ) ;
if( ! F_139 ( V_83 , V_168 ) )
{
F_45 ( V_59 , L_77 ) ;
F_46 ( V_59 ) ;
F_134 ( V_83 ) ;
return NULL ;
}
F_45 ( V_59 , L_78 , F_140 ( V_83 ) ) ;
F_134 ( V_83 ) ;
}
return V_83 ;
}
int F_141 ( T_2 * V_59 , T_6 * V_77 )
{
static int V_169 = 0 ;
if ( V_169 )
return 1 ;
V_169 = 1 ;
if ( ! V_77 )
V_77 = V_170 ;
if ( ! V_77 )
return 1 ;
F_142 () ;
if ( F_143 ( V_77 , NULL , 0 ) <= 0 )
{
F_45 ( V_59 , L_79 ) ;
F_46 ( V_59 ) ;
return 0 ;
}
return 1 ;
}
char * F_144 ()
{
const char * V_171 = F_145 () ;
T_18 V_7 ;
char * V_10 ;
V_7 = strlen ( V_171 ) + strlen ( V_172 ) + 2 ;
V_10 = F_3 ( V_7 ) ;
F_7 ( V_10 , V_171 , V_7 ) ;
#ifndef F_146
F_147 ( V_10 , L_80 , V_7 ) ;
#endif
F_147 ( V_10 , V_172 , V_7 ) ;
return V_10 ;
}
static unsigned long F_148 ( const T_19 * V_173 )
{
const char * V_26 ;
V_26 = V_173 [ V_174 ] ;
while ( * V_26 == '0' ) V_26 ++ ;
return ( F_149 ( V_26 ) ) ;
}
static int F_150 ( const T_19 * V_173 , const T_19 * V_175 )
{
const char * V_176 , * V_177 ;
for ( V_176 = V_173 [ V_174 ] ; * V_176 == '0' ; V_176 ++ ) ;
for ( V_177 = V_175 [ V_174 ] ; * V_177 == '0' ; V_177 ++ ) ;
return ( strcmp ( V_176 , V_177 ) ) ;
}
static int F_151 ( char * * V_173 )
{ return ( V_173 [ 0 ] [ 0 ] == 'V' ) ; }
static unsigned long F_152 ( const T_19 * V_173 )
{ return ( F_149 ( V_173 [ V_178 ] ) ) ; }
int F_153 ( const T_19 * V_173 , const T_19 * V_175 )
{ return ( strcmp ( V_173 [ V_178 ] , V_175 [ V_178 ] ) ) ; }
int F_154 ( char * V_179 , char * V_180 , char * V_181 )
{
char V_8 [ 5 ] [ V_182 ] ;
int V_6 , V_183 ;
V_6 = strlen ( V_179 ) + strlen ( V_181 ) ;
V_183 = strlen ( V_179 ) + strlen ( V_180 ) ;
if ( V_6 > V_183 ) V_183 = V_6 ;
if ( V_183 + 1 >= V_182 )
{
F_45 ( V_58 , L_81 ) ;
goto V_59;
}
#ifndef F_146
V_183 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_82 ,
V_179 , V_180 ) ;
#else
V_183 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_83 ,
V_179 , V_180 ) ;
#endif
#ifndef F_146
V_183 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_82 ,
V_179 , V_181 ) ;
#else
V_183 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_83 ,
V_179 , V_181 ) ;
#endif
#ifdef F_156
F_45 ( V_58 , L_84 ,
V_179 , V_8 [ 1 ] ) ;
#endif
if ( rename ( V_179 , V_8 [ 1 ] ) < 0 && V_184 != V_185
#ifdef F_157
&& V_184 != F_157
#endif
) {
F_45 ( V_58 ,
L_85 ,
V_179 , V_8 [ 1 ] ) ;
perror ( L_86 ) ;
goto V_59;
}
#ifdef F_156
F_45 ( V_58 , L_84 ,
V_8 [ 0 ] , V_179 ) ;
#endif
if ( rename ( V_8 [ 0 ] , V_179 ) < 0 )
{
F_45 ( V_58 ,
L_85 ,
V_8 [ 0 ] , V_179 ) ;
perror ( L_86 ) ;
rename ( V_8 [ 1 ] , V_179 ) ;
goto V_59;
}
return 1 ;
V_59:
return 0 ;
}
int F_158 ( T_20 * V_175 , T_21 * V_186 )
{
T_20 * V_71 ;
int V_144 = 0 ;
if ( V_175 )
V_71 = V_175 ;
else
V_71 = F_159 () ;
if ( ! V_71 )
return 0 ;
if ( ! F_160 ( V_71 , V_187 , 0 , 0 ) )
goto error;
if ( V_186 && ! F_161 ( V_71 , V_186 ) )
goto error;
V_144 = 1 ;
error:
if ( ! V_175 )
F_162 ( V_71 ) ;
return V_144 ;
}
T_22 * F_163 ( char * V_188 , T_23 * V_189 )
{
T_22 * V_190 = NULL ;
T_24 * V_191 = NULL ;
T_2 * V_23 = F_53 ( F_68 () ) ;
T_6 * V_192 = NULL ;
char V_8 [ 1 ] [ V_182 ] ;
long V_193 = - 1 ;
if ( V_23 == NULL )
{
F_46 ( V_58 ) ;
goto V_59;
}
if ( F_72 ( V_23 , V_188 ) <= 0 )
{
perror ( V_188 ) ;
F_45 ( V_58 , L_87 , V_188 ) ;
goto V_59;
}
if ( ( V_191 = F_164 ( V_23 , V_194 ) ) == NULL )
goto V_59;
#ifndef F_146
F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_88 , V_188 ) ;
#else
F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_89 , V_188 ) ;
#endif
V_192 = F_165 ( NULL ) ;
if ( F_166 ( V_192 , V_8 [ 0 ] , & V_193 ) <= 0 )
{
if ( V_193 > 0 )
{
F_45 ( V_58 ,
L_90
, V_193 , V_8 [ 0 ] ) ;
goto V_59;
}
else
{
F_167 ( V_192 ) ;
V_192 = NULL ;
}
}
if ( ( V_190 = F_3 ( sizeof( T_22 ) ) ) == NULL )
{
fprintf ( V_195 , L_91 ) ;
goto V_59;
}
V_190 -> V_196 = V_191 ;
V_191 = NULL ;
if ( V_189 )
V_190 -> V_197 = * V_189 ;
else
{
V_190 -> V_197 . V_198 = 1 ;
}
if ( V_192 )
{
char * V_10 = F_61 ( V_192 , NULL , L_92 ) ;
if ( V_10 )
{
#ifdef F_156
F_45 ( V_58 , L_93 , V_10 ) ;
#endif
V_190 -> V_197 . V_198 = F_168 ( V_10 , 1 ) ;
}
}
V_59:
if ( V_192 ) F_167 ( V_192 ) ;
if ( V_191 ) F_169 ( V_191 ) ;
if ( V_23 ) F_58 ( V_23 ) ;
return V_190 ;
}
int F_170 ( T_22 * V_196 )
{
if ( ! F_171 ( V_196 -> V_196 , V_174 , NULL ,
F_172 ( V_199 ) ,
F_173 ( V_199 ) ) )
{
F_45 ( V_58 ,
L_94 ,
V_196 -> V_196 -> error , V_196 -> V_196 -> V_60 , V_196 -> V_196 -> V_61 ) ;
return 0 ;
}
if ( V_196 -> V_197 . V_198
&& ! F_171 ( V_196 -> V_196 , V_178 , F_151 ,
F_172 ( V_200 ) ,
F_173 ( V_200 ) ) )
{
F_45 ( V_58 , L_95 ,
V_196 -> V_196 -> error , V_196 -> V_196 -> V_60 , V_196 -> V_196 -> V_61 ) ;
return 0 ;
}
return 1 ;
}
int F_174 ( const char * V_188 , const char * V_201 , T_22 * V_196 )
{
char V_8 [ 3 ] [ V_182 ] ;
T_2 * V_24 = F_53 ( F_68 () ) ;
int V_183 ;
if ( V_24 == NULL )
{
F_46 ( V_58 ) ;
goto V_59;
}
V_183 = strlen ( V_188 ) + strlen ( V_201 ) ;
if ( V_183 + 6 >= V_182 )
{
F_45 ( V_58 , L_81 ) ;
goto V_59;
}
#ifndef F_146
V_183 = F_155 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_88 , V_188 ) ;
#else
V_183 = F_155 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_89 , V_188 ) ;
#endif
#ifndef F_146
V_183 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_96 , V_188 , V_201 ) ;
#else
V_183 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_97 , V_188 , V_201 ) ;
#endif
#ifndef F_146
V_183 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_82 , V_188 , V_201 ) ;
#else
V_183 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_83 , V_188 , V_201 ) ;
#endif
#ifdef F_156
F_45 ( V_58 , L_98 , V_8 [ 0 ] ) ;
#endif
if ( F_175 ( V_24 , V_8 [ 0 ] ) <= 0 )
{
perror ( V_188 ) ;
F_45 ( V_58 , L_87 , V_188 ) ;
goto V_59;
}
V_183 = F_176 ( V_24 , V_196 -> V_196 ) ;
if ( V_183 <= 0 ) goto V_59;
F_79 ( V_24 ) ;
V_24 = F_53 ( F_68 () ) ;
#ifdef F_156
F_45 ( V_58 , L_98 , V_8 [ 1 ] ) ;
#endif
if ( F_175 ( V_24 , V_8 [ 1 ] ) <= 0 )
{
perror ( V_8 [ 2 ] ) ;
F_45 ( V_58 , L_87 , V_8 [ 2 ] ) ;
goto V_59;
}
F_45 ( V_24 , L_99 ,
V_196 -> V_197 . V_198 ? L_100 : L_101 ) ;
F_79 ( V_24 ) ;
return 1 ;
V_59:
return 0 ;
}
int F_177 ( const char * V_188 , const char * V_180 , const char * V_181 )
{
char V_8 [ 5 ] [ V_182 ] ;
int V_6 , V_183 ;
V_6 = strlen ( V_188 ) + strlen ( V_181 ) ;
V_183 = strlen ( V_188 ) + strlen ( V_180 ) ;
if ( V_6 > V_183 ) V_183 = V_6 ;
if ( V_183 + 6 >= V_182 )
{
F_45 ( V_58 , L_81 ) ;
goto V_59;
}
#ifndef F_146
V_183 = F_155 ( V_8 [ 4 ] , sizeof V_8 [ 4 ] , L_88 , V_188 ) ;
#else
V_183 = F_155 ( V_8 [ 4 ] , sizeof V_8 [ 4 ] , L_89 , V_188 ) ;
#endif
#ifndef F_146
V_183 = F_155 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_96 ,
V_188 , V_180 ) ;
#else
V_183 = F_155 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_97 ,
V_188 , V_180 ) ;
#endif
#ifndef F_146
V_183 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_82 ,
V_188 , V_180 ) ;
#else
V_183 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_83 ,
V_188 , V_180 ) ;
#endif
#ifndef F_146
V_183 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_82 ,
V_188 , V_181 ) ;
#else
V_183 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_83 ,
V_188 , V_181 ) ;
#endif
#ifndef F_146
V_183 = F_155 ( V_8 [ 3 ] , sizeof V_8 [ 3 ] , L_96 ,
V_188 , V_181 ) ;
#else
V_183 = F_155 ( V_8 [ 3 ] , sizeof V_8 [ 3 ] , L_97 ,
V_188 , V_181 ) ;
#endif
#ifdef F_156
F_45 ( V_58 , L_84 ,
V_188 , V_8 [ 1 ] ) ;
#endif
if ( rename ( V_188 , V_8 [ 1 ] ) < 0 && V_184 != V_185
#ifdef F_157
&& V_184 != F_157
#endif
) {
F_45 ( V_58 ,
L_85 ,
V_188 , V_8 [ 1 ] ) ;
perror ( L_86 ) ;
goto V_59;
}
#ifdef F_156
F_45 ( V_58 , L_84 ,
V_8 [ 0 ] , V_188 ) ;
#endif
if ( rename ( V_8 [ 0 ] , V_188 ) < 0 )
{
F_45 ( V_58 ,
L_85 ,
V_8 [ 0 ] , V_188 ) ;
perror ( L_86 ) ;
rename ( V_8 [ 1 ] , V_188 ) ;
goto V_59;
}
#ifdef F_156
F_45 ( V_58 , L_84 ,
V_8 [ 4 ] , V_8 [ 3 ] ) ;
#endif
if ( rename ( V_8 [ 4 ] , V_8 [ 3 ] ) < 0 && V_184 != V_185
#ifdef F_157
&& V_184 != F_157
#endif
) {
F_45 ( V_58 ,
L_85 ,
V_8 [ 4 ] , V_8 [ 3 ] ) ;
perror ( L_86 ) ;
rename ( V_188 , V_8 [ 0 ] ) ;
rename ( V_8 [ 1 ] , V_188 ) ;
goto V_59;
}
#ifdef F_156
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
rename ( V_188 , V_8 [ 0 ] ) ;
rename ( V_8 [ 1 ] , V_188 ) ;
goto V_59;
}
return 1 ;
V_59:
return 0 ;
}
void F_178 ( T_22 * V_196 )
{
if ( V_196 )
{
if ( V_196 -> V_196 ) F_169 ( V_196 -> V_196 ) ;
F_2 ( V_196 ) ;
}
}
int F_168 ( const char * V_202 , int V_203 )
{
int V_144 = V_203 ;
if ( V_202 )
{
switch ( * V_202 )
{
case 'f' :
case 'F' :
case 'n' :
case 'N' :
case '0' :
V_144 = 0 ;
break;
case 't' :
case 'T' :
case 'y' :
case 'Y' :
case '1' :
V_144 = 1 ;
break;
default:
V_144 = V_203 ;
break;
}
}
return V_144 ;
}
T_15 * F_179 ( char * V_204 , long V_205 , int V_206 )
{
T_18 V_207 = strlen ( V_204 ) + 1 ;
char * V_8 = F_3 ( V_207 ) ;
T_18 V_208 = V_207 / 2 + 1 ;
char * * V_209 = F_3 ( V_208 * sizeof ( char * ) ) ;
char * * V_210 = F_3 ( V_208 * sizeof ( char * ) ) ;
int * V_211 = F_3 ( V_208 * sizeof ( int ) ) ;
char * V_212 = V_204 , * V_158 = V_8 ;
int V_6 , V_213 = 0 ;
T_15 * V_26 = NULL ;
int V_214 ;
if ( ! V_8 || ! V_209 || ! V_210 )
{
F_45 ( V_58 , L_102 ) ;
goto error;
}
if ( * V_204 != '/' )
{
F_45 ( V_58 , L_103 ) ;
goto error;
}
V_212 ++ ;
V_211 [ V_213 ] = 0 ;
while ( * V_212 )
{
V_209 [ V_213 ] = V_158 ;
while ( * V_212 )
{
if ( * V_212 == '\\' )
{
if ( * ++ V_212 )
* V_158 ++ = * V_212 ++ ;
else
{
F_45 ( V_58 , L_104 ) ;
goto error;
}
}
else if ( * V_212 == '=' )
{
V_212 ++ ;
* V_158 ++ = '\0' ;
break;
}
else
* V_158 ++ = * V_212 ++ ;
}
if ( ! * V_212 )
{
F_45 ( V_58 , L_105 , V_213 ) ;
goto error;
}
V_210 [ V_213 ] = V_158 ;
while ( * V_212 )
{
if ( * V_212 == '\\' )
{
if ( * ++ V_212 )
* V_158 ++ = * V_212 ++ ;
else
{
F_45 ( V_58 , L_104 ) ;
goto error;
}
}
else if ( * V_212 == '/' )
{
V_212 ++ ;
V_211 [ V_213 + 1 ] = 0 ;
break;
}
else if ( * V_212 == '+' && V_206 )
{
V_212 ++ ;
V_211 [ V_213 + 1 ] = - 1 ;
break;
}
else
* V_158 ++ = * V_212 ++ ;
}
* V_158 ++ = '\0' ;
V_213 ++ ;
}
if ( ! ( V_26 = F_180 () ) )
goto error;
for ( V_6 = 0 ; V_6 < V_213 ; V_6 ++ )
{
if ( ( V_214 = F_181 ( V_209 [ V_6 ] ) ) == V_80 )
{
F_45 ( V_58 , L_106 , V_209 [ V_6 ] ) ;
continue;
}
if ( ! * V_210 [ V_6 ] )
{
F_45 ( V_58 , L_107 , V_209 [ V_6 ] ) ;
continue;
}
if ( ! F_182 ( V_26 , V_214 , V_205 , ( unsigned char * ) V_210 [ V_6 ] , - 1 , - 1 , V_211 [ V_6 ] ) )
goto error;
}
F_2 ( V_210 ) ;
F_2 ( V_209 ) ;
F_2 ( V_8 ) ;
return V_26 ;
error:
F_183 ( V_26 ) ;
if ( V_210 )
F_2 ( V_210 ) ;
if ( V_209 )
F_2 ( V_209 ) ;
if ( V_8 )
F_2 ( V_8 ) ;
return NULL ;
}
int F_184 ( char * * * V_215 , int * V_216 ,
int * V_217 , T_2 * V_59 , T_25 * * V_218 )
{
T_14 * V_219 = NULL ;
unsigned long V_103 = 0 ;
int V_6 ;
int V_220 = 0 , V_221 = - 1 ;
char * * V_222 = * V_215 ;
char * V_9 = * * V_215 , * V_223 = ( * V_215 ) [ 1 ] ;
T_26 V_224 = 0 ;
if ( ! strcmp ( V_9 , L_108 ) )
{
if ( ! V_223 )
* V_217 = 1 ;
else
{
V_219 = F_185 ( V_223 , 0 ) ;
if ( ! V_219 )
{
F_45 ( V_59 , L_109 ,
V_223 ) ;
* V_217 = 1 ;
}
}
( * V_215 ) ++ ;
}
else if ( strcmp ( V_9 , L_110 ) == 0 )
{
T_27 * V_225 ;
if ( ! V_223 )
* V_217 = 1 ;
else
{
V_6 = F_186 ( V_223 ) ;
if( V_6 < 0 )
{
F_45 ( V_59 , L_111 ) ;
* V_217 = 1 ;
}
else
{
V_225 = F_187 ( V_6 ) ;
V_220 = F_188 ( V_225 ) ;
}
}
( * V_215 ) ++ ;
}
else if ( strcmp ( V_9 , L_112 ) == 0 )
{
if ( ! V_223 )
* V_217 = 1 ;
else
{
V_221 = atoi ( V_223 ) ;
if( V_221 < 0 )
{
F_45 ( V_59 , L_113 ) ;
* V_217 = 1 ;
}
}
( * V_215 ) ++ ;
}
else if ( strcmp ( V_9 , L_114 ) == 0 )
{
if ( ! V_223 )
* V_217 = 1 ;
else
{
long V_226 ;
if ( sscanf ( V_223 , L_115 , & V_226 ) != 1 )
{
F_45 ( V_58 ,
L_116 ,
V_223 ) ;
* V_217 = 1 ;
}
V_224 = ( T_26 ) V_226 ;
}
( * V_215 ) ++ ;
}
else if ( ! strcmp ( V_9 , L_117 ) )
V_103 |= V_227 ;
else if ( ! strcmp ( V_9 , L_118 ) )
V_103 |= V_228 ;
else if ( ! strcmp ( V_9 , L_119 ) )
V_103 |= V_229 ;
else if ( ! strcmp ( V_9 , L_120 ) )
V_103 |= V_229 | V_230 ;
else if ( ! strcmp ( V_9 , L_121 ) )
V_103 |= V_231 ;
else if ( ! strcmp ( V_9 , L_122 ) )
V_103 |= V_232 ;
else if ( ! strcmp ( V_9 , L_123 ) )
V_103 |= V_233 ;
else if ( ! strcmp ( V_9 , L_124 ) )
V_103 |= V_234 ;
else if ( ! strcmp ( V_9 , L_125 ) )
V_103 |= V_235 ;
else if ( ! strcmp ( V_9 , L_126 ) )
V_103 |= V_236 ;
else if ( ! strcmp ( V_9 , L_127 ) )
V_103 |= V_237 ;
else if ( ! strcmp ( V_9 , L_128 ) )
V_103 |= V_238 ;
else if ( ! strcmp ( V_9 , L_129 ) )
V_103 |= V_239 ;
else
return 0 ;
if ( * V_217 )
{
if ( * V_218 )
F_189 ( * V_218 ) ;
* V_218 = NULL ;
goto V_86;
}
if ( ! * V_218 && ! ( * V_218 = F_190 () ) )
{
* V_217 = 1 ;
goto V_86;
}
if ( V_219 )
F_191 ( * V_218 , V_219 ) ;
if ( V_103 )
F_192 ( * V_218 , V_103 ) ;
if ( V_220 )
F_193 ( * V_218 , V_220 ) ;
if ( V_221 >= 0 )
F_194 ( * V_218 , V_221 ) ;
if ( V_224 )
F_195 ( * V_218 , V_224 ) ;
V_86:
( * V_215 ) ++ ;
if ( V_216 )
* V_216 -= * V_215 - V_222 ;
return 1 ;
}
int F_196 ( unsigned char * * V_24 , int V_240 , T_2 * V_23 )
{
T_2 * V_241 ;
int V_7 , V_144 ;
unsigned char V_242 [ 1024 ] ;
V_241 = F_53 ( F_197 () ) ;
if ( ! V_241 )
return - 1 ;
for(; ; )
{
if ( ( V_240 != - 1 ) && V_240 < 1024 )
V_7 = V_240 ;
else
V_7 = 1024 ;
V_7 = F_100 ( V_23 , V_242 , V_7 ) ;
if ( V_7 <= 0 )
break;
if ( F_198 ( V_241 , V_242 , V_7 ) != V_7 )
{
F_79 ( V_241 ) ;
return - 1 ;
}
V_240 -= V_7 ;
if ( V_240 == 0 )
break;
}
V_144 = F_199 ( V_241 , ( char * * ) V_24 ) ;
F_200 ( V_241 , V_243 ) ;
F_79 ( V_241 ) ;
return V_144 ;
}
int F_201 ( T_28 * V_244 , char * V_78 )
{
int V_245 ;
char * V_246 , * V_247 = NULL ;
V_246 = F_50 ( V_78 ) ;
if ( ! V_246 )
return - 1 ;
V_247 = strchr ( V_246 , ':' ) ;
if ( V_247 )
{
* V_247 = 0 ;
V_247 ++ ;
}
V_245 = F_202 ( V_244 , V_246 , V_247 ) ;
F_2 ( V_246 ) ;
return V_245 ;
}
void F_203 ( T_2 * V_24 , T_29 * V_244 )
{
T_30 * V_248 ;
int V_249 ;
int V_250 = 0 ;
if ( V_24 == NULL )
{
V_24 = F_56 ( V_195 , V_72 ) ;
V_250 = 1 ;
}
V_248 = F_204 ( V_244 ) ;
V_249 = F_205 ( V_244 ) ;
F_45 ( V_24 , L_130 ,
V_249 ? L_131 : L_132 ) ;
F_206 ( V_24 , L_133 , F_207 ( V_248 ) ) ;
F_206 ( V_24 , L_134 , F_208 ( V_248 ) ) ;
if ( V_250 )
F_79 ( V_24 ) ;
}
static T_31 * F_209 ( const char * V_251 , const char * V_252 ,
const char * V_253 )
{
T_20 * V_10 = NULL ;
T_20 * V_254 = NULL ;
T_20 * V_28 = NULL ;
T_20 * V_255 = F_159 () ;
T_31 * V_244 ;
F_210 ( & V_10 , L_135 ) ;
V_254 = F_159 () ;
F_211 ( V_254 , 2 ) ;
V_28 = F_159 () ;
F_212 ( V_28 , V_10 ) ;
F_213 ( ( const unsigned char * ) V_253 , strlen ( V_253 ) , V_255 ) ;
V_244 = F_214 ( V_251 , V_252 , V_10 , V_254 , V_28 , V_255 ) ;
F_162 ( V_255 ) ;
F_162 ( V_28 ) ;
F_162 ( V_254 ) ;
F_162 ( V_10 ) ;
return V_244 ;
}
static void F_215 ( T_2 * V_256 , const T_32 * V_10 )
{
F_216 ( V_256 , V_10 -> V_257 ) ;
F_14 ( V_256 , L_9 ) ;
F_216 ( V_256 , V_10 -> V_258 . V_259 ) ;
F_14 ( V_256 , L_9 ) ;
F_216 ( V_256 , V_10 -> V_258 . V_175 ) ;
F_14 ( V_256 , L_9 ) ;
}
static void F_217 ( T_2 * V_260 , T_31 * V_244 )
{
T_33 V_261 ;
F_218 ( & V_261 ) ;
F_219 ( & V_261 , V_244 ) ;
F_215 ( V_260 , & V_261 . V_262 ) ;
F_215 ( V_260 , & V_261 . V_263 ) ;
( void ) F_220 ( V_260 ) ;
F_221 ( & V_261 ) ;
}
static void F_222 ( T_2 * V_260 , T_31 * V_244 )
{
T_34 V_264 ;
F_223 ( & V_264 ) ;
F_224 ( & V_264 , V_244 ) ;
F_215 ( V_260 , & V_264 ) ;
( void ) F_220 ( V_260 ) ;
F_225 ( & V_264 ) ;
}
static void F_226 ( T_2 * V_260 , T_31 * V_244 )
{
T_35 V_265 ;
F_227 ( & V_265 ) ;
F_228 ( & V_265 , V_244 ) ;
F_198 ( V_260 , V_265 . V_266 , sizeof V_265 . V_266 ) ;
( void ) F_220 ( V_260 ) ;
F_229 ( & V_265 ) ;
}
static void F_230 ( T_2 * V_260 , T_31 * V_244 )
{
T_36 V_267 ;
F_231 ( & V_267 ) ;
F_232 ( & V_267 , V_244 ) ;
F_198 ( V_260 , V_267 . V_268 , sizeof V_267 . V_268 ) ;
( void ) F_220 ( V_260 ) ;
F_233 ( & V_267 ) ;
}
static void F_234 ( T_20 * * V_269 , T_2 * V_260 )
{
char V_8 [ 10240 ] ;
int V_270 ;
V_270 = F_57 ( V_260 , V_8 , sizeof V_8 ) ;
assert ( V_270 > 0 ) ;
assert ( V_8 [ V_270 - 1 ] == '\n' ) ;
V_8 [ V_270 - 1 ] = '\0' ;
F_210 ( V_269 , V_8 ) ;
}
static void F_235 ( T_32 * V_10 , T_2 * V_260 )
{
F_234 ( & V_10 -> V_257 , V_260 ) ;
F_234 ( & V_10 -> V_258 . V_259 , V_260 ) ;
F_234 ( & V_10 -> V_258 . V_175 , V_260 ) ;
}
static void F_236 ( T_31 * V_244 , T_2 * V_260 )
{
T_33 V_261 ;
F_218 ( & V_261 ) ;
F_235 ( & V_261 . V_262 , V_260 ) ;
F_235 ( & V_261 . V_263 , V_260 ) ;
if( ! F_237 ( V_244 , & V_261 ) )
{
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_221 ( & V_261 ) ;
}
static void F_238 ( T_31 * V_244 , T_2 * V_260 )
{
T_34 V_264 ;
F_223 ( & V_264 ) ;
F_235 ( & V_264 , V_260 ) ;
if( ! F_239 ( V_244 , & V_264 ) )
{
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_225 ( & V_264 ) ;
}
static void F_240 ( T_31 * V_244 , T_2 * V_260 )
{
T_35 V_265 ;
int V_270 ;
F_227 ( & V_265 ) ;
V_270 = F_100 ( V_260 , V_265 . V_266 , sizeof V_265 . V_266 ) ;
assert ( V_270 == sizeof V_265 . V_266 ) ;
if( ! F_241 ( V_244 , & V_265 ) )
{
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_229 ( & V_265 ) ;
}
static void F_242 ( T_31 * V_244 , T_2 * V_260 )
{
T_36 V_267 ;
int V_270 ;
F_231 ( & V_267 ) ;
V_270 = F_100 ( V_260 , V_267 . V_268 , sizeof V_267 . V_268 ) ;
assert ( V_270 == sizeof V_267 . V_268 ) ;
if( ! F_243 ( V_244 , & V_267 ) )
{
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_233 ( & V_267 ) ;
}
void F_244 ( T_2 * V_24 , T_2 * V_256 , const char * V_253 )
{
T_31 * V_244 ;
T_2 * V_260 ;
F_14 ( V_24 , L_136 ) ;
V_244 = F_209 ( L_137 , L_138 , V_253 ) ;
V_260 = F_53 ( F_54 () ) ;
F_55 ( V_260 , V_256 ) ;
F_217 ( V_260 , V_244 ) ;
F_236 ( V_244 , V_260 ) ;
F_222 ( V_260 , V_244 ) ;
F_238 ( V_244 , V_260 ) ;
F_226 ( V_260 , V_244 ) ;
F_242 ( V_244 , V_260 ) ;
F_14 ( V_24 , L_139 ) ;
V_271 = F_245 ( F_246 ( V_244 ) ) ;
F_247 ( V_260 ) ;
F_79 ( V_260 ) ;
F_248 ( V_244 ) ;
}
void F_249 ( T_2 * V_24 , T_2 * V_256 , const char * V_253 )
{
T_31 * V_244 ;
T_2 * V_260 ;
F_14 ( V_24 , L_136 ) ;
V_244 = F_209 ( L_138 , L_137 , V_253 ) ;
V_260 = F_53 ( F_54 () ) ;
F_55 ( V_260 , V_256 ) ;
F_236 ( V_244 , V_260 ) ;
F_217 ( V_260 , V_244 ) ;
F_238 ( V_244 , V_260 ) ;
F_222 ( V_260 , V_244 ) ;
F_240 ( V_244 , V_260 ) ;
F_230 ( V_260 , V_244 ) ;
F_14 ( V_24 , L_139 ) ;
V_271 = F_245 ( F_246 ( V_244 ) ) ;
F_247 ( V_260 ) ;
F_79 ( V_260 ) ;
F_248 ( V_244 ) ;
}
unsigned char * F_250 ( unsigned short * V_272 , const char * V_23 )
{
T_18 V_7 ;
unsigned char * V_24 ;
T_18 V_6 , V_273 = 0 ;
V_7 = strlen ( V_23 ) ;
if ( V_7 >= 65535 )
return NULL ;
V_24 = F_3 ( strlen ( V_23 ) + 1 ) ;
if ( ! V_24 )
return NULL ;
for ( V_6 = 0 ; V_6 <= V_7 ; ++ V_6 )
{
if ( V_6 == V_7 || V_23 [ V_6 ] == ',' )
{
if ( V_6 - V_273 > 255 )
{
F_2 ( V_24 ) ;
return NULL ;
}
V_24 [ V_273 ] = V_6 - V_273 ;
V_273 = V_6 + 1 ;
}
else
V_24 [ V_6 + 1 ] = V_23 [ V_6 ] ;
}
* V_272 = V_7 + 1 ;
return V_24 ;
}
static int F_251 ( const char * V_274 , const char * V_275 )
{
T_37 * V_276 = NULL , * V_277 ;
T_38 V_59 ;
int V_144 = 0 ;
if ( sizeof( T_37 ) == 1 )
{
V_276 = ( T_37 * ) V_274 ;
V_277 = ( T_37 * ) V_275 ;
}
else
{
T_18 V_6 , V_278 = strlen ( V_274 ) + 1 , V_33 = strlen ( V_275 ) + 1 ;
V_276 = ( T_37 * ) malloc ( sizeof( T_37 ) * ( V_278 + V_33 ) ) ;
if ( V_276 == NULL ) goto V_59;
V_277 = V_276 + V_278 ;
#if ! F_6 ( V_279 ) || V_279 >= 101
if ( ! F_252 ( V_280 , 0 , V_274 , V_278 , ( V_281 * ) V_276 , V_278 ) )
#endif
for ( V_6 = 0 ; V_6 < V_278 ; V_6 ++ ) V_276 [ V_6 ] = ( T_37 ) V_274 [ V_6 ] ;
#if ! F_6 ( V_279 ) || V_279 >= 101
if ( ! F_252 ( V_280 , 0 , V_275 , V_33 , ( V_281 * ) V_277 , V_33 ) )
#endif
for ( V_6 = 0 ; V_6 < V_33 ; V_6 ++ ) V_277 [ V_6 ] = ( T_37 ) V_275 [ V_6 ] ;
}
if ( F_253 ( V_276 , V_277 ) ) goto V_50;
V_59 = F_254 () ;
if ( V_59 == V_282 || V_59 == V_283 )
{
if ( F_255 ( V_277 ) && F_253 ( V_276 , V_277 ) )
goto V_50;
V_59 = F_254 () ;
}
if ( V_59 == V_284 || V_59 == V_285 )
V_184 = V_185 ;
else if ( V_59 == V_286 )
V_184 = V_287 ;
else
V_184 = V_288 ;
V_59:
V_144 = - 1 ;
V_50:
if ( V_276 != NULL && V_276 != ( T_37 * ) V_274 ) free ( V_276 ) ;
return V_144 ;
}
double F_256 ( int V_289 , int V_290 )
{
T_39 V_291 ;
double V_144 = 0 ;
static T_40 V_292 ;
static int V_293 = 1 ;
#ifdef F_257
static T_41 V_294 = NULL ;
if ( V_294 == NULL )
{
if ( F_258 () < 0x80000000 )
V_294 = F_259 ( V_295 , FALSE ,
F_260 () ) ;
if ( V_294 == NULL ) V_294 = ( T_41 ) - 1 ;
}
if ( V_290 && V_294 != ( T_41 ) - 1 )
{
T_39 V_296 ;
F_261 ( V_294 , & V_296 , & V_296 , & V_296 , & V_291 ) ;
}
else
#endif
{
T_42 V_297 ;
if ( V_290 && V_293 )
{
F_45 ( V_58 , L_140
L_141 ) ;
V_293 = 0 ;
}
F_262 ( & V_297 ) ;
F_263 ( & V_297 , & V_291 ) ;
}
if ( V_289 == V_298 )
{
V_292 . V_299 . V_300 = V_291 . V_301 ;
V_292 . V_299 . V_302 = V_291 . V_303 ;
}
else {
T_40 V_304 ;
V_304 . V_299 . V_300 = V_291 . V_301 ;
V_304 . V_299 . V_302 = V_291 . V_303 ;
V_144 = ( V_305 ) ( V_304 . V_306 - V_292 . V_306 ) * 1e-7 ;
}
return ( V_144 ) ;
}
double F_256 ( int V_289 , int V_290 )
{
double V_144 = 0 ;
static T_43 V_292 ;
static int V_293 = 1 ;
if ( V_290 && V_293 )
{
F_45 ( V_58 , L_140
L_141 ) ;
V_293 = 0 ;
}
if ( V_289 == V_298 ) V_292 = clock () ;
else V_144 = ( clock () - V_292 ) / ( double ) V_307 ;
return ( V_144 ) ;
}
double F_256 ( int V_289 , int V_290 )
{
double V_144 = 0 ;
#ifdef F_264
static struct V_308 V_292 ;
struct V_308 V_291 ;
#else
static unsigned long V_292 ;
unsigned long V_291 ;
#endif
static int V_293 = 1 ;
if ( V_290 && V_293 )
{
F_45 ( V_58 , L_140
L_141 ) ;
V_293 = 0 ;
}
#ifdef F_264
F_265 ( F_264 , & V_291 ) ;
if ( V_289 == V_298 ) V_292 = V_291 ;
else V_144 = ( ( V_291 . V_309 + V_291 . V_310 * 1e-9 )
- ( V_292 . V_309 + V_292 . V_310 * 1e-9 ) ) ;
#else
V_291 = F_266 () ;
if ( V_289 == V_298 ) V_292 = V_291 ;
else V_144 = ( V_291 - V_292 ) / ( double ) F_267 () ;
#endif
return ( V_144 ) ;
}
double F_256 ( int V_289 , int V_290 )
{
static T_43 V_292 ;
double V_144 = 0 ;
T_43 V_291 ;
#ifdef F_268
struct V_311 V_312 ;
V_291 = F_269 ( & V_312 ) ;
if ( V_290 ) V_291 = V_312 . V_313 ;
#else
if ( V_290 )
V_291 = clock () ;
else {
struct V_314 V_315 ;
F_270 ( & V_315 , NULL ) ;
V_291 = ( T_43 ) (
( unsigned long long ) V_315 . V_309 * V_316 +
( unsigned long long ) V_315 . V_317 * ( 1000000 / V_316 )
) ;
}
#endif
if ( V_289 == V_298 ) V_292 = V_291 ;
else V_144 = ( V_291 - V_292 ) / ( double ) ( V_316 ) ;
return ( V_144 ) ;
}
double F_256 ( int V_289 , int V_290 )
{
double V_144 = 0 ;
struct V_311 V_312 ;
T_43 V_291 = F_269 ( & V_312 ) ;
static T_43 V_292 ;
if ( V_290 ) V_291 = V_312 . V_313 ;
if ( V_289 == V_298 ) V_292 = V_291 ;
else
{
long int V_318 = F_271 ( V_319 ) ;
V_144 = ( V_291 - V_292 ) / ( double ) V_318 ;
}
return ( V_144 ) ;
}
double F_256 ( int V_289 , int V_290 )
{
double V_144 = 0 ;
struct V_320 V_312 ;
struct V_314 V_291 ;
static struct V_314 V_292 ;
if ( V_290 ) F_272 ( V_321 , & V_312 ) , V_291 = V_312 . V_322 ;
else F_270 ( & V_291 , NULL ) ;
if ( V_289 == V_298 ) V_292 = V_291 ;
else V_144 = ( ( V_291 . V_309 + V_291 . V_317 * 1e-6 )
- ( V_292 . V_309 + V_292 . V_317 * 1e-6 ) ) ;
return V_144 ;
}
int F_273 ( const char * V_79 )
{
T_41 V_323 ;
T_44 V_324 ;
#if F_6 ( V_325 ) || F_6 ( V_326 )
T_18 V_6 , V_327 = strlen ( V_79 ) + 1 ;
if ( V_327 > sizeof( V_324 . V_328 ) / sizeof( V_324 . V_328 [ 0 ] ) )
return - 1 ;
#if ! F_6 ( V_279 ) || V_279 >= 101
if ( ! F_252 ( V_280 , 0 , V_79 , V_327 , V_324 . V_328 , V_327 ) )
#endif
for ( V_6 = 0 ; V_6 < V_327 ; V_6 ++ )
V_324 . V_328 [ V_6 ] = ( V_281 ) V_79 [ V_6 ] ;
V_323 = F_274 ( V_324 . V_328 , & V_324 ) ;
#else
V_323 = F_274 ( V_79 , & V_324 ) ;
#endif
if ( V_323 == V_329 ) return - 1 ;
F_275 ( V_323 ) ;
return ( ( V_324 . V_330 & V_331 ) != 0 ) ;
}
int F_273 ( const char * V_79 )
{
#if F_6 ( V_332 )
struct V_333 V_334 ;
if ( V_333 ( V_79 , & V_334 ) == 0 ) return V_332 ( V_334 . V_335 ) ;
else return - 1 ;
#else
return - 1 ;
#endif
}
int F_276 ( void * V_8 , int V_336 )
{
T_38 V_26 ;
if ( F_277 ( F_278 ( V_337 ) , V_8 , V_336 , & V_26 , NULL ) )
return ( V_26 ) ;
else return ( - 1 ) ;
}
int F_276 ( void * V_8 , int V_336 )
{ return F_279 ( fileno ( V_73 ) , V_8 , V_336 ) ; }
int F_280 ( const void * V_8 , int V_336 )
{
T_38 V_26 ;
if ( F_281 ( F_278 ( V_338 ) , V_8 , V_336 , & V_26 , NULL ) )
return ( V_26 ) ;
else return ( - 1 ) ;
}
int F_280 ( const void * V_8 , int V_336 )
{ return F_282 ( fileno ( stdout ) , V_8 , V_336 ) ; }
