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
if ( ( * V_12 == 'D' ) || ( * V_12 == 'd' ) )
return ( V_13 ) ;
else if ( ( * V_12 == 'T' ) || ( * V_12 == 't' ) )
return ( V_14 ) ;
else if ( ( * V_12 == 'N' ) || ( * V_12 == 'n' ) )
return ( V_15 ) ;
else if ( ( * V_12 == 'S' ) || ( * V_12 == 's' ) )
return ( V_16 ) ;
else if ( ( * V_12 == 'M' ) || ( * V_12 == 'm' ) )
return ( V_17 ) ;
else if ( ( * V_12 == '1' )
|| ( strcmp ( V_12 , L_2 ) == 0 ) || ( strcmp ( V_12 , L_3 ) == 0 )
|| ( strcmp ( V_12 , L_4 ) == 0 ) || ( strcmp ( V_12 , L_5 ) == 0 ) )
return ( V_18 ) ;
else if ( ( * V_12 == 'E' ) || ( * V_12 == 'e' ) )
return ( V_19 ) ;
else if ( ( * V_12 == 'P' ) || ( * V_12 == 'p' ) )
{
if ( V_12 [ 1 ] == 'V' || V_12 [ 1 ] == 'v' )
return V_20 ;
else
return ( V_21 ) ;
}
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
setvbuf ( V_73 , NULL , F_69 , 0 ) ;
#endif
F_70 ( V_85 , V_73 , V_72 ) ;
}
else
{
if ( F_71 ( V_85 , V_1 ) <= 0 )
{
F_45 ( V_59 , L_28 ,
V_84 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_86;
}
}
if ( V_81 == V_13 )
V_35 = F_72 ( V_85 , NULL ) ;
else if ( V_81 == V_15 )
{
T_8 * V_87 ;
V_87 = F_73 ( F_74 ( T_8 ) , V_85 , NULL ) ;
if ( V_87 == NULL )
goto V_86;
if ( ( strncmp ( V_88 , ( char * ) V_87 -> V_89 -> V_31 ,
V_87 -> V_89 -> V_90 ) != 0 ) )
{
F_75 ( V_87 ) ;
F_45 ( V_59 , L_29 ) ;
goto V_86;
}
V_35 = V_87 -> V_85 ;
V_87 -> V_85 = NULL ;
F_75 ( V_87 ) ;
}
else if ( V_81 == V_21 )
V_35 = F_76 ( V_85 , NULL ,
( V_91 * ) F_37 , NULL ) ;
else if ( V_81 == V_18 )
{
if ( ! F_77 ( V_59 , V_85 , V_84 , NULL , NULL ,
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
if ( V_85 != NULL ) F_78 ( V_85 ) ;
return ( V_35 ) ;
}
T_9 * F_79 ( T_2 * V_59 , const char * V_1 , int V_81 , int V_92 ,
const char * V_82 , T_7 * V_83 , const char * V_93 )
{
T_2 * V_94 = NULL ;
T_9 * V_95 = NULL ;
V_42 V_49 ;
V_49 . V_41 = V_82 ;
V_49 . V_48 = V_1 ;
if ( V_1 == NULL && ( ! V_92 || V_81 == V_19 ) )
{
F_45 ( V_59 , L_32 ) ;
goto V_86;
}
#ifndef F_80
if ( V_81 == V_19 )
{
if ( ! V_83 )
F_45 ( V_58 , L_33 ) ;
else
V_95 = F_81 ( V_83 , V_1 ,
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
setvbuf ( V_73 , NULL , F_69 , 0 ) ;
#endif
F_70 ( V_94 , V_73 , V_72 ) ;
}
else
if ( F_71 ( V_94 , V_1 ) <= 0 )
{
F_45 ( V_59 , L_28 ,
V_93 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_81 == V_13 )
{
V_95 = F_82 ( V_94 , NULL ) ;
}
else if ( V_81 == V_21 )
{
V_95 = F_83 ( V_94 , NULL ,
( V_91 * ) F_37 , & V_49 ) ;
}
#if ! F_6 ( V_96 ) && ! F_6 ( V_97 )
else if ( V_81 == V_15 || V_81 == V_98 )
V_95 = F_84 ( V_59 , V_94 , V_1 , V_93 , V_81 ) ;
#endif
else if ( V_81 == V_18 )
{
if ( ! F_77 ( V_59 , V_94 , V_93 ,
( V_91 * ) F_37 , & V_49 ,
& V_95 , NULL , NULL ) )
goto V_86;
}
#if ! F_6 ( V_97 ) && ! F_6 ( V_99 )
else if ( V_81 == V_17 )
V_95 = F_85 ( V_94 ) ;
else if ( V_81 == V_20 )
V_95 = F_86 ( V_94 , ( V_91 * ) F_37 ,
& V_49 ) ;
#endif
else
{
F_45 ( V_59 , L_34 ) ;
goto V_86;
}
V_86:
if ( V_94 != NULL ) F_78 ( V_94 ) ;
if ( V_95 == NULL )
F_45 ( V_59 , L_35 , V_93 ) ;
return ( V_95 ) ;
}
T_9 * F_87 ( T_2 * V_59 , const char * V_1 , int V_81 , int V_92 ,
const char * V_82 , T_7 * V_83 , const char * V_93 )
{
T_2 * V_94 = NULL ;
T_9 * V_95 = NULL ;
V_42 V_49 ;
V_49 . V_41 = V_82 ;
V_49 . V_48 = V_1 ;
if ( V_1 == NULL && ( ! V_92 || V_81 == V_19 ) )
{
F_45 ( V_59 , L_32 ) ;
goto V_86;
}
#ifndef F_80
if ( V_81 == V_19 )
{
if ( ! V_83 )
F_45 ( V_58 , L_33 ) ;
else
V_95 = F_88 ( V_83 , V_1 ,
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
setvbuf ( V_73 , NULL , F_69 , 0 ) ;
#endif
F_70 ( V_94 , V_73 , V_72 ) ;
}
else
if ( F_71 ( V_94 , V_1 ) <= 0 )
{
F_45 ( V_59 , L_28 ,
V_93 , V_1 ) ;
F_46 ( V_59 ) ;
goto V_86;
}
if ( V_81 == V_13 )
{
V_95 = F_89 ( V_94 , NULL ) ;
}
#ifndef V_97
else if ( V_81 == V_100 )
{
T_10 * V_101 ;
V_101 = F_90 ( V_94 , NULL ) ;
if ( V_101 )
{
V_95 = F_91 () ;
if ( V_95 )
F_92 ( V_95 , V_101 ) ;
F_93 ( V_101 ) ;
}
else
V_95 = NULL ;
}
else if ( V_81 == V_102 )
{
T_10 * V_101 ;
V_101 = F_94 ( V_94 , NULL ,
( V_91 * ) F_37 , & V_49 ) ;
if ( V_101 )
{
V_95 = F_91 () ;
if ( V_95 )
F_92 ( V_95 , V_101 ) ;
F_93 ( V_101 ) ;
}
else
V_95 = NULL ;
}
#endif
else if ( V_81 == V_21 )
{
V_95 = F_95 ( V_94 , NULL ,
( V_91 * ) F_37 , & V_49 ) ;
}
#if ! F_6 ( V_96 ) && ! F_6 ( V_97 )
else if ( V_81 == V_15 || V_81 == V_98 )
V_95 = F_84 ( V_59 , V_94 , V_1 , V_93 , V_81 ) ;
#endif
#if ! F_6 ( V_97 ) && ! F_6 ( V_99 )
else if ( V_81 == V_17 )
V_95 = F_96 ( V_94 ) ;
#endif
else
{
F_45 ( V_59 , L_34 ) ;
goto V_86;
}
V_86:
if ( V_94 != NULL ) F_78 ( V_94 ) ;
if ( V_95 == NULL )
F_45 ( V_59 , L_35 , V_93 ) ;
return ( V_95 ) ;
}
static T_9 *
F_84 ( T_2 * V_59 , T_2 * V_94 , const char * V_1 ,
const char * V_93 , int V_81 )
{
T_9 * V_95 ;
T_11 * V_8 ;
T_10 * V_101 ;
const unsigned char * V_10 ;
int V_25 , V_6 ;
V_8 = F_97 () ;
V_95 = F_91 () ;
V_25 = 0 ;
if ( V_8 == NULL || V_95 == NULL )
goto error;
for (; ; )
{
if ( ! F_98 ( V_8 , V_25 + 1024 * 10 ) )
goto error;
V_6 = F_99 ( V_94 , & ( V_8 -> V_31 [ V_25 ] ) , 1024 * 10 ) ;
V_25 += V_6 ;
if ( V_6 == 0 )
break;
if ( V_6 < 0 )
{
F_45 ( V_59 , L_36 ,
V_93 , V_1 ) ;
goto error;
}
}
V_10 = ( unsigned char * ) V_8 -> V_31 ;
V_101 = F_100 ( NULL , & V_10 , ( long ) V_25 , NULL ,
( V_81 == V_98 ? 1 : 0 ) ) ;
if ( V_101 == NULL )
goto error;
F_101 ( V_8 ) ;
F_92 ( V_95 , V_101 ) ;
return V_95 ;
error:
F_101 ( V_8 ) ;
F_102 ( V_95 ) ;
return NULL ;
}
int F_103 ( unsigned long * V_103 , const char * V_9 )
{
static const T_12 V_104 [] = {
{ L_37 , V_105 , 0xffffffffl } ,
{ L_38 , V_106 , 0xffffffffl } ,
{ L_39 , V_107 , 0 } ,
{ L_40 , V_108 , 0 } ,
{ L_41 , V_109 , 0 } ,
{ L_42 , V_110 , 0 } ,
{ L_43 , V_111 , 0 } ,
{ L_44 , V_112 , 0 } ,
{ L_45 , V_113 , 0 } ,
{ L_46 , V_114 , 0 } ,
{ L_47 , V_115 , 0 } ,
{ L_48 , V_116 , 0 } ,
{ L_49 , V_117 , 0 } ,
{ L_50 , V_118 , 0 } ,
{ L_51 , V_119 , V_120 } ,
{ L_52 , V_121 , V_120 } ,
{ L_53 , V_122 , V_120 } ,
{ L_54 , V_123 , V_120 } ,
{ NULL , 0 , 0 }
} ;
return F_104 ( V_103 , V_9 , V_104 ) ;
}
int F_105 ( unsigned long * V_103 , const char * V_9 )
{
static const T_12 V_124 [] = {
{ L_55 , V_125 , 0 } ,
{ L_56 , V_126 , 0 } ,
{ L_57 , V_127 , 0 } ,
{ L_58 , V_128 , 0 } ,
{ L_59 , V_129 , 0 } ,
{ L_60 , V_130 , 0 } ,
{ L_61 , V_131 , 0 } ,
{ L_62 , V_132 , 0 } ,
{ L_63 , V_133 , 0 } ,
{ L_64 , V_134 , 0 } ,
{ L_65 , V_135 , 0xffffffffL } ,
{ L_66 , V_136 , V_137 } ,
{ L_67 , V_138 , V_137 } ,
{ L_68 , V_139 , V_137 } ,
{ L_69 , V_140 , V_137 } ,
{ L_70 , V_141 , 0 } ,
{ L_71 , V_142 , V_143 } ,
{ L_72 , V_144 , V_143 } ,
{ L_73 , V_145 , V_143 } ,
{ L_74 , V_146 , 0 } ,
{ L_75 , V_147 , V_143 } ,
{ L_76 , V_148 , 0 } ,
{ L_77 , V_149 , 0 } ,
{ L_78 , V_150 , 0xffffffffL } ,
{ L_79 , V_151 , 0xffffffffL } ,
{ L_80 , V_152 , 0xffffffffL } ,
{ L_38 , V_152 , 0xffffffffL } ,
{ NULL , 0 , 0 }
} ;
return F_104 ( V_103 , V_9 , V_124 ) ;
}
int F_106 ( int * V_153 , const char * V_9 )
{
if ( ! strcasecmp ( V_9 , L_81 ) )
* V_153 = V_154 ;
else if ( ! strcasecmp ( V_9 , L_82 ) )
* V_153 = V_155 ;
else if ( ! strcasecmp ( V_9 , L_83 ) )
* V_153 = V_156 ;
else
return 0 ;
return 1 ;
}
int F_107 ( T_3 * V_35 , T_13 * V_157 , int V_153 )
{
F_60 ( V_158 ) * V_159 = NULL ;
V_158 * V_160 , * V_161 ;
T_14 * V_162 ;
int V_6 , V_163 , V_164 = 0 ;
if ( ! V_35 || ! V_157 || ( V_153 == V_154 ) )
return 1 ;
V_159 = F_108 ( V_157 ) ;
for( V_6 = 0 ; V_6 < F_109 ( V_159 ) ; V_6 ++ ) {
V_160 = F_110 ( V_159 , V_6 ) ;
V_162 = F_111 ( V_160 ) ;
V_163 = F_112 ( V_35 , V_162 , - 1 ) ;
if ( V_163 != - 1 ) {
if ( V_153 == V_155 )
continue;
do {
V_161 = F_113 ( V_35 , V_163 ) ;
F_114 ( V_35 , V_163 ) ;
F_115 ( V_161 ) ;
V_163 = F_112 ( V_35 , V_162 , - 1 ) ;
} while ( V_163 != - 1 );
}
if ( ! F_116 ( V_35 , V_160 , - 1 ) )
goto V_86;
}
V_164 = 1 ;
V_86:
F_117 ( V_159 , F_115 ) ;
return V_164 ;
}
static int F_104 ( unsigned long * V_103 , const char * V_9 , const T_12 * V_165 )
{
F_60 ( V_75 ) * V_166 ;
V_75 * V_167 ;
int V_6 , V_164 = 1 ;
if( ! V_9 ) return 0 ;
V_166 = F_118 ( V_9 ) ;
for ( V_6 = 0 ; V_6 < F_64 ( V_166 ) ; V_6 ++ ) {
V_167 = F_65 ( V_166 , V_6 ) ;
if ( ! F_119 ( V_103 , V_167 -> V_79 , V_165 ) )
V_164 = 0 ;
}
F_120 ( V_166 , V_168 ) ;
return V_164 ;
}
static int F_119 ( unsigned long * V_103 , const char * V_9 , const T_12 * V_165 )
{
char V_169 ;
const T_12 * V_170 ;
V_169 = V_9 [ 0 ] ;
if( V_169 == '-' ) {
V_169 = 0 ;
V_9 ++ ;
} else if ( V_169 == '+' ) {
V_169 = 1 ;
V_9 ++ ;
} else V_169 = 1 ;
for( V_170 = V_165 ; V_170 -> V_79 ; V_170 ++ ) {
if( ! strcasecmp ( V_9 , V_170 -> V_79 ) ) {
* V_103 &= ~ V_170 -> V_171 ;
if( V_169 ) * V_103 |= V_170 -> V_172 ;
else * V_103 &= ~ V_170 -> V_172 ;
return 1 ;
}
}
return 0 ;
}
void F_121 ( T_2 * V_24 , const char * V_173 , T_15 * V_174 , unsigned long V_175 )
{
char * V_8 ;
char V_176 = 0 ;
int V_177 = 0 ;
if( V_173 ) F_14 ( V_24 , V_173 ) ;
if( ( V_175 & V_137 ) == V_140 ) {
V_176 = 1 ;
V_177 = 4 ;
}
if( V_175 == V_135 ) {
V_8 = F_12 ( V_174 , 0 , 0 ) ;
F_14 ( V_24 , V_8 ) ;
F_14 ( V_24 , L_9 ) ;
F_2 ( V_8 ) ;
} else {
if( V_176 ) F_14 ( V_24 , L_9 ) ;
F_122 ( V_24 , V_174 , V_177 , V_175 ) ;
F_14 ( V_24 , L_9 ) ;
}
}
T_16 * F_123 ( T_2 * V_178 , char * V_179 , char * V_180 )
{
T_16 * V_181 ;
T_17 * V_182 ;
if( ! ( V_181 = F_124 () ) ) goto V_86;
V_182 = F_125 ( V_181 , F_126 () ) ;
if ( V_182 == NULL ) goto V_86;
if ( V_179 ) {
if( ! F_127 ( V_182 , V_179 , V_183 ) ) {
F_45 ( V_178 , L_84 , V_179 ) ;
goto V_86;
}
} else F_127 ( V_182 , NULL , V_184 ) ;
V_182 = F_125 ( V_181 , F_128 () ) ;
if ( V_182 == NULL ) goto V_86;
if ( V_180 ) {
if( ! F_129 ( V_182 , V_180 , V_183 ) ) {
F_45 ( V_178 , L_85 , V_180 ) ;
goto V_86;
}
} else F_129 ( V_182 , NULL , V_184 ) ;
F_62 () ;
return V_181 ;
V_86:
F_130 ( V_181 ) ;
return NULL ;
}
static T_7 * F_131 ( T_2 * V_59 , const char * V_185 , int V_186 )
{
T_7 * V_83 = F_132 ( L_86 ) ;
if ( V_83 )
{
if ( ! F_133 ( V_83 , L_87 , V_185 , 0 )
|| ! F_133 ( V_83 , L_88 , NULL , 0 ) )
{
F_134 ( V_83 ) ;
V_83 = NULL ;
}
}
return V_83 ;
}
T_7 * F_135 ( T_2 * V_59 , const char * V_185 , int V_186 )
{
T_7 * V_83 = NULL ;
if ( V_185 )
{
if( strcmp ( V_185 , L_89 ) == 0 )
{
F_45 ( V_59 , L_90 ) ;
F_136 () ;
return NULL ;
}
if( ( V_83 = F_132 ( V_185 ) ) == NULL
&& ( V_83 = F_131 ( V_59 , V_185 , V_186 ) ) == NULL )
{
F_45 ( V_59 , L_91 , V_185 ) ;
F_46 ( V_59 ) ;
return NULL ;
}
if ( V_186 )
{
F_137 ( V_83 , V_187 ,
0 , V_59 , 0 ) ;
}
F_138 ( V_83 , L_92 , 0 , V_43 , 0 , 1 ) ;
if( ! F_139 ( V_83 , V_188 ) )
{
F_45 ( V_59 , L_93 ) ;
F_46 ( V_59 ) ;
F_134 ( V_83 ) ;
return NULL ;
}
F_45 ( V_59 , L_94 , F_140 ( V_83 ) ) ;
F_134 ( V_83 ) ;
}
return V_83 ;
}
int F_141 ( T_2 * V_59 , T_6 * V_77 )
{
static int V_189 = 0 ;
if ( V_189 )
return 1 ;
V_189 = 1 ;
if ( ! V_77 )
V_77 = V_190 ;
if ( ! V_77 )
return 1 ;
F_142 () ;
if ( F_143 ( V_77 , NULL , 0 ) <= 0 )
{
F_45 ( V_59 , L_95 ) ;
F_46 ( V_59 ) ;
return 0 ;
}
return 1 ;
}
char * F_144 ()
{
const char * V_191 = F_145 () ;
T_18 V_7 ;
char * V_10 ;
V_7 = strlen ( V_191 ) + strlen ( V_192 ) + 2 ;
V_10 = F_3 ( V_7 ) ;
F_7 ( V_10 , V_191 , V_7 ) ;
#ifndef F_146
F_147 ( V_10 , L_96 , V_7 ) ;
#endif
F_147 ( V_10 , V_192 , V_7 ) ;
return V_10 ;
}
static unsigned long F_148 ( const T_19 * V_193 )
{
const char * V_26 ;
V_26 = V_193 [ V_194 ] ;
while ( * V_26 == '0' ) V_26 ++ ;
return ( F_149 ( V_26 ) ) ;
}
static int F_150 ( const T_19 * V_193 , const T_19 * V_195 )
{
const char * V_196 , * V_197 ;
for ( V_196 = V_193 [ V_194 ] ; * V_196 == '0' ; V_196 ++ ) ;
for ( V_197 = V_195 [ V_194 ] ; * V_197 == '0' ; V_197 ++ ) ;
return ( strcmp ( V_196 , V_197 ) ) ;
}
static int F_151 ( char * * V_193 )
{ return ( V_193 [ 0 ] [ 0 ] == 'V' ) ; }
static unsigned long F_152 ( const T_19 * V_193 )
{ return ( F_149 ( V_193 [ V_198 ] ) ) ; }
int F_153 ( const T_19 * V_193 , const T_19 * V_195 )
{ return ( strcmp ( V_193 [ V_198 ] , V_195 [ V_198 ] ) ) ; }
int F_154 ( char * V_199 , char * V_200 , char * V_201 )
{
char V_8 [ 5 ] [ V_202 ] ;
int V_6 , V_203 ;
V_6 = strlen ( V_199 ) + strlen ( V_201 ) ;
V_203 = strlen ( V_199 ) + strlen ( V_200 ) ;
if ( V_6 > V_203 ) V_203 = V_6 ;
if ( V_203 + 1 >= V_202 )
{
F_45 ( V_58 , L_97 ) ;
goto V_59;
}
#ifndef F_146
V_203 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_98 ,
V_199 , V_200 ) ;
#else
V_203 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_99 ,
V_199 , V_200 ) ;
#endif
#ifndef F_146
V_203 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_98 ,
V_199 , V_201 ) ;
#else
V_203 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_99 ,
V_199 , V_201 ) ;
#endif
#ifdef F_156
F_45 ( V_58 , L_100 ,
V_199 , V_8 [ 1 ] ) ;
#endif
if ( rename ( V_199 , V_8 [ 1 ] ) < 0 && V_204 != V_205
#ifdef F_157
&& V_204 != F_157
#endif
) {
F_45 ( V_58 ,
L_101 ,
V_199 , V_8 [ 1 ] ) ;
perror ( L_102 ) ;
goto V_59;
}
#ifdef F_156
F_45 ( V_58 , L_100 ,
V_8 [ 0 ] , V_199 ) ;
#endif
if ( rename ( V_8 [ 0 ] , V_199 ) < 0 )
{
F_45 ( V_58 ,
L_101 ,
V_8 [ 0 ] , V_199 ) ;
perror ( L_102 ) ;
rename ( V_8 [ 1 ] , V_199 ) ;
goto V_59;
}
return 1 ;
V_59:
return 0 ;
}
int F_158 ( T_20 * V_195 , T_21 * V_206 )
{
T_20 * V_71 ;
int V_164 = 0 ;
if ( V_195 )
V_71 = V_195 ;
else
V_71 = F_159 () ;
if ( ! V_71 )
return 0 ;
if ( ! F_160 ( V_71 , V_207 , 0 , 0 ) )
goto error;
if ( V_206 && ! F_161 ( V_71 , V_206 ) )
goto error;
V_164 = 1 ;
error:
if ( ! V_195 )
F_162 ( V_71 ) ;
return V_164 ;
}
T_22 * F_163 ( char * V_208 , T_23 * V_209 )
{
T_22 * V_210 = NULL ;
T_24 * V_211 = NULL ;
T_2 * V_23 = F_53 ( F_68 () ) ;
T_6 * V_212 = NULL ;
char V_8 [ 1 ] [ V_202 ] ;
long V_213 = - 1 ;
if ( V_23 == NULL )
{
F_46 ( V_58 ) ;
goto V_59;
}
if ( F_71 ( V_23 , V_208 ) <= 0 )
{
perror ( V_208 ) ;
F_45 ( V_58 , L_103 , V_208 ) ;
goto V_59;
}
if ( ( V_211 = F_164 ( V_23 , V_214 ) ) == NULL )
goto V_59;
#ifndef F_146
F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_104 , V_208 ) ;
#else
F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_105 , V_208 ) ;
#endif
V_212 = F_165 ( NULL ) ;
if ( F_166 ( V_212 , V_8 [ 0 ] , & V_213 ) <= 0 )
{
if ( V_213 > 0 )
{
F_45 ( V_58 ,
L_106
, V_213 , V_8 [ 0 ] ) ;
goto V_59;
}
else
{
F_167 ( V_212 ) ;
V_212 = NULL ;
}
}
if ( ( V_210 = F_3 ( sizeof( T_22 ) ) ) == NULL )
{
fprintf ( V_215 , L_107 ) ;
goto V_59;
}
V_210 -> V_216 = V_211 ;
V_211 = NULL ;
if ( V_209 )
V_210 -> V_217 = * V_209 ;
else
{
V_210 -> V_217 . V_218 = 1 ;
}
if ( V_212 )
{
char * V_10 = F_61 ( V_212 , NULL , L_108 ) ;
if ( V_10 )
{
#ifdef F_156
F_45 ( V_58 , L_109 , V_10 ) ;
#endif
V_210 -> V_217 . V_218 = F_168 ( V_10 , 1 ) ;
}
}
V_59:
if ( V_212 ) F_167 ( V_212 ) ;
if ( V_211 ) F_169 ( V_211 ) ;
if ( V_23 ) F_58 ( V_23 ) ;
return V_210 ;
}
int F_170 ( T_22 * V_216 )
{
if ( ! F_171 ( V_216 -> V_216 , V_194 , NULL ,
F_172 ( V_219 ) ,
F_173 ( V_219 ) ) )
{
F_45 ( V_58 ,
L_110 ,
V_216 -> V_216 -> error , V_216 -> V_216 -> V_60 , V_216 -> V_216 -> V_61 ) ;
return 0 ;
}
if ( V_216 -> V_217 . V_218
&& ! F_171 ( V_216 -> V_216 , V_198 , F_151 ,
F_172 ( V_220 ) ,
F_173 ( V_220 ) ) )
{
F_45 ( V_58 , L_111 ,
V_216 -> V_216 -> error , V_216 -> V_216 -> V_60 , V_216 -> V_216 -> V_61 ) ;
return 0 ;
}
return 1 ;
}
int F_174 ( const char * V_208 , const char * V_221 , T_22 * V_216 )
{
char V_8 [ 3 ] [ V_202 ] ;
T_2 * V_24 = F_53 ( F_68 () ) ;
int V_203 ;
if ( V_24 == NULL )
{
F_46 ( V_58 ) ;
goto V_59;
}
V_203 = strlen ( V_208 ) + strlen ( V_221 ) ;
if ( V_203 + 6 >= V_202 )
{
F_45 ( V_58 , L_97 ) ;
goto V_59;
}
#ifndef F_146
V_203 = F_155 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_104 , V_208 ) ;
#else
V_203 = F_155 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_105 , V_208 ) ;
#endif
#ifndef F_146
V_203 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_112 , V_208 , V_221 ) ;
#else
V_203 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_113 , V_208 , V_221 ) ;
#endif
#ifndef F_146
V_203 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_98 , V_208 , V_221 ) ;
#else
V_203 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_99 , V_208 , V_221 ) ;
#endif
#ifdef F_156
F_45 ( V_58 , L_114 , V_8 [ 0 ] ) ;
#endif
if ( F_175 ( V_24 , V_8 [ 0 ] ) <= 0 )
{
perror ( V_208 ) ;
F_45 ( V_58 , L_103 , V_208 ) ;
goto V_59;
}
V_203 = F_176 ( V_24 , V_216 -> V_216 ) ;
if ( V_203 <= 0 ) goto V_59;
F_78 ( V_24 ) ;
V_24 = F_53 ( F_68 () ) ;
#ifdef F_156
F_45 ( V_58 , L_114 , V_8 [ 1 ] ) ;
#endif
if ( F_175 ( V_24 , V_8 [ 1 ] ) <= 0 )
{
perror ( V_8 [ 2 ] ) ;
F_45 ( V_58 , L_103 , V_8 [ 2 ] ) ;
goto V_59;
}
F_45 ( V_24 , L_115 ,
V_216 -> V_217 . V_218 ? L_116 : L_117 ) ;
F_78 ( V_24 ) ;
return 1 ;
V_59:
return 0 ;
}
int F_177 ( const char * V_208 , const char * V_200 , const char * V_201 )
{
char V_8 [ 5 ] [ V_202 ] ;
int V_6 , V_203 ;
V_6 = strlen ( V_208 ) + strlen ( V_201 ) ;
V_203 = strlen ( V_208 ) + strlen ( V_200 ) ;
if ( V_6 > V_203 ) V_203 = V_6 ;
if ( V_203 + 6 >= V_202 )
{
F_45 ( V_58 , L_97 ) ;
goto V_59;
}
#ifndef F_146
V_203 = F_155 ( V_8 [ 4 ] , sizeof V_8 [ 4 ] , L_104 , V_208 ) ;
#else
V_203 = F_155 ( V_8 [ 4 ] , sizeof V_8 [ 4 ] , L_105 , V_208 ) ;
#endif
#ifndef F_146
V_203 = F_155 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_112 ,
V_208 , V_200 ) ;
#else
V_203 = F_155 ( V_8 [ 2 ] , sizeof V_8 [ 2 ] , L_113 ,
V_208 , V_200 ) ;
#endif
#ifndef F_146
V_203 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_98 ,
V_208 , V_200 ) ;
#else
V_203 = F_155 ( V_8 [ 0 ] , sizeof V_8 [ 0 ] , L_99 ,
V_208 , V_200 ) ;
#endif
#ifndef F_146
V_203 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_98 ,
V_208 , V_201 ) ;
#else
V_203 = F_155 ( V_8 [ 1 ] , sizeof V_8 [ 1 ] , L_99 ,
V_208 , V_201 ) ;
#endif
#ifndef F_146
V_203 = F_155 ( V_8 [ 3 ] , sizeof V_8 [ 3 ] , L_112 ,
V_208 , V_201 ) ;
#else
V_203 = F_155 ( V_8 [ 3 ] , sizeof V_8 [ 3 ] , L_113 ,
V_208 , V_201 ) ;
#endif
#ifdef F_156
F_45 ( V_58 , L_100 ,
V_208 , V_8 [ 1 ] ) ;
#endif
if ( rename ( V_208 , V_8 [ 1 ] ) < 0 && V_204 != V_205
#ifdef F_157
&& V_204 != F_157
#endif
) {
F_45 ( V_58 ,
L_101 ,
V_208 , V_8 [ 1 ] ) ;
perror ( L_102 ) ;
goto V_59;
}
#ifdef F_156
F_45 ( V_58 , L_100 ,
V_8 [ 0 ] , V_208 ) ;
#endif
if ( rename ( V_8 [ 0 ] , V_208 ) < 0 )
{
F_45 ( V_58 ,
L_101 ,
V_8 [ 0 ] , V_208 ) ;
perror ( L_102 ) ;
rename ( V_8 [ 1 ] , V_208 ) ;
goto V_59;
}
#ifdef F_156
F_45 ( V_58 , L_100 ,
V_8 [ 4 ] , V_8 [ 3 ] ) ;
#endif
if ( rename ( V_8 [ 4 ] , V_8 [ 3 ] ) < 0 && V_204 != V_205
#ifdef F_157
&& V_204 != F_157
#endif
) {
F_45 ( V_58 ,
L_101 ,
V_8 [ 4 ] , V_8 [ 3 ] ) ;
perror ( L_102 ) ;
rename ( V_208 , V_8 [ 0 ] ) ;
rename ( V_8 [ 1 ] , V_208 ) ;
goto V_59;
}
#ifdef F_156
F_45 ( V_58 , L_100 ,
V_8 [ 2 ] , V_8 [ 4 ] ) ;
#endif
if ( rename ( V_8 [ 2 ] , V_8 [ 4 ] ) < 0 )
{
F_45 ( V_58 ,
L_101 ,
V_8 [ 2 ] , V_8 [ 4 ] ) ;
perror ( L_102 ) ;
rename ( V_8 [ 3 ] , V_8 [ 4 ] ) ;
rename ( V_208 , V_8 [ 0 ] ) ;
rename ( V_8 [ 1 ] , V_208 ) ;
goto V_59;
}
return 1 ;
V_59:
return 0 ;
}
void F_178 ( T_22 * V_216 )
{
if ( V_216 )
{
if ( V_216 -> V_216 ) F_169 ( V_216 -> V_216 ) ;
F_2 ( V_216 ) ;
}
}
int F_168 ( const char * V_222 , int V_223 )
{
int V_164 = V_223 ;
if ( V_222 )
{
switch ( * V_222 )
{
case 'f' :
case 'F' :
case 'n' :
case 'N' :
case '0' :
V_164 = 0 ;
break;
case 't' :
case 'T' :
case 'y' :
case 'Y' :
case '1' :
V_164 = 1 ;
break;
default:
V_164 = V_223 ;
break;
}
}
return V_164 ;
}
T_15 * F_179 ( char * V_224 , long V_225 , int V_226 )
{
T_18 V_227 = strlen ( V_224 ) + 1 ;
char * V_8 = F_3 ( V_227 ) ;
T_18 V_228 = V_227 / 2 + 1 ;
char * * V_229 = F_3 ( V_228 * sizeof ( char * ) ) ;
char * * V_230 = F_3 ( V_228 * sizeof ( char * ) ) ;
int * V_231 = F_3 ( V_228 * sizeof ( int ) ) ;
char * V_232 = V_224 , * V_178 = V_8 ;
int V_6 , V_233 = 0 ;
T_15 * V_26 = NULL ;
int V_234 ;
if ( ! V_8 || ! V_229 || ! V_230 )
{
F_45 ( V_58 , L_118 ) ;
goto error;
}
if ( * V_224 != '/' )
{
F_45 ( V_58 , L_119 ) ;
goto error;
}
V_232 ++ ;
V_231 [ V_233 ] = 0 ;
while ( * V_232 )
{
V_229 [ V_233 ] = V_178 ;
while ( * V_232 )
{
if ( * V_232 == '\\' )
{
if ( * ++ V_232 )
* V_178 ++ = * V_232 ++ ;
else
{
F_45 ( V_58 , L_120 ) ;
goto error;
}
}
else if ( * V_232 == '=' )
{
V_232 ++ ;
* V_178 ++ = '\0' ;
break;
}
else
* V_178 ++ = * V_232 ++ ;
}
if ( ! * V_232 )
{
F_45 ( V_58 , L_121 , V_233 ) ;
goto error;
}
V_230 [ V_233 ] = V_178 ;
while ( * V_232 )
{
if ( * V_232 == '\\' )
{
if ( * ++ V_232 )
* V_178 ++ = * V_232 ++ ;
else
{
F_45 ( V_58 , L_120 ) ;
goto error;
}
}
else if ( * V_232 == '/' )
{
V_232 ++ ;
V_231 [ V_233 + 1 ] = 0 ;
break;
}
else if ( * V_232 == '+' && V_226 )
{
V_232 ++ ;
V_231 [ V_233 + 1 ] = - 1 ;
break;
}
else
* V_178 ++ = * V_232 ++ ;
}
* V_178 ++ = '\0' ;
V_233 ++ ;
}
if ( ! ( V_26 = F_180 () ) )
goto error;
for ( V_6 = 0 ; V_6 < V_233 ; V_6 ++ )
{
if ( ( V_234 = F_181 ( V_229 [ V_6 ] ) ) == V_80 )
{
F_45 ( V_58 , L_122 , V_229 [ V_6 ] ) ;
continue;
}
if ( ! * V_230 [ V_6 ] )
{
F_45 ( V_58 , L_123 , V_229 [ V_6 ] ) ;
continue;
}
if ( ! F_182 ( V_26 , V_234 , V_225 , ( unsigned char * ) V_230 [ V_6 ] , - 1 , - 1 , V_231 [ V_6 ] ) )
goto error;
}
F_2 ( V_230 ) ;
F_2 ( V_229 ) ;
F_2 ( V_8 ) ;
return V_26 ;
error:
F_183 ( V_26 ) ;
if ( V_230 )
F_2 ( V_230 ) ;
if ( V_229 )
F_2 ( V_229 ) ;
if ( V_8 )
F_2 ( V_8 ) ;
return NULL ;
}
int F_184 ( char * * * V_235 , int * V_236 ,
int * V_237 , T_2 * V_59 , T_25 * * V_238 )
{
T_14 * V_239 = NULL ;
unsigned long V_103 = 0 ;
int V_6 ;
int V_240 = 0 , V_241 = - 1 ;
char * * V_242 = * V_235 ;
char * V_9 = * * V_235 , * V_243 = ( * V_235 ) [ 1 ] ;
if ( ! strcmp ( V_9 , L_124 ) )
{
if ( ! V_243 )
* V_237 = 1 ;
else
{
V_239 = F_185 ( V_243 , 0 ) ;
if ( ! V_239 )
{
F_45 ( V_59 , L_125 ,
V_243 ) ;
* V_237 = 1 ;
}
}
( * V_235 ) ++ ;
}
else if ( strcmp ( V_9 , L_126 ) == 0 )
{
T_26 * V_244 ;
if ( ! V_243 )
* V_237 = 1 ;
else
{
V_6 = F_186 ( V_243 ) ;
if( V_6 < 0 )
{
F_45 ( V_59 , L_127 ) ;
* V_237 = 1 ;
}
else
{
V_244 = F_187 ( V_6 ) ;
V_240 = F_188 ( V_244 ) ;
}
}
( * V_235 ) ++ ;
}
else if ( strcmp ( V_9 , L_128 ) == 0 )
{
if ( ! V_243 )
* V_237 = 1 ;
else
{
V_241 = atoi ( V_243 ) ;
if( V_241 < 0 )
{
F_45 ( V_59 , L_129 ) ;
* V_237 = 1 ;
}
}
( * V_235 ) ++ ;
}
else if ( ! strcmp ( V_9 , L_130 ) )
V_103 |= V_245 ;
else if ( ! strcmp ( V_9 , L_131 ) )
V_103 |= V_246 ;
else if ( ! strcmp ( V_9 , L_132 ) )
V_103 |= V_247 ;
else if ( ! strcmp ( V_9 , L_133 ) )
V_103 |= V_247 | V_248 ;
else if ( ! strcmp ( V_9 , L_134 ) )
V_103 |= V_249 ;
else if ( ! strcmp ( V_9 , L_135 ) )
V_103 |= V_250 ;
else if ( ! strcmp ( V_9 , L_136 ) )
V_103 |= V_251 ;
else if ( ! strcmp ( V_9 , L_137 ) )
V_103 |= V_252 ;
else if ( ! strcmp ( V_9 , L_138 ) )
V_103 |= V_253 ;
else if ( ! strcmp ( V_9 , L_139 ) )
V_103 |= V_254 ;
else if ( ! strcmp ( V_9 , L_140 ) )
V_103 |= V_255 ;
else if ( ! strcmp ( V_9 , L_141 ) )
V_103 |= V_256 ;
else if ( ! strcmp ( V_9 , L_142 ) )
V_103 |= V_257 ;
else
return 0 ;
if ( * V_237 )
{
if ( * V_238 )
F_189 ( * V_238 ) ;
* V_238 = NULL ;
goto V_86;
}
if ( ! * V_238 && ! ( * V_238 = F_190 () ) )
{
* V_237 = 1 ;
goto V_86;
}
if ( V_239 )
F_191 ( * V_238 , V_239 ) ;
if ( V_103 )
F_192 ( * V_238 , V_103 ) ;
if ( V_240 )
F_193 ( * V_238 , V_240 ) ;
if ( V_241 >= 0 )
F_194 ( * V_238 , V_241 ) ;
V_86:
( * V_235 ) ++ ;
if ( V_236 )
* V_236 -= * V_235 - V_242 ;
return 1 ;
}
int F_195 ( unsigned char * * V_24 , int V_258 , T_2 * V_23 )
{
T_2 * V_259 ;
int V_7 , V_164 ;
unsigned char V_260 [ 1024 ] ;
V_259 = F_53 ( F_196 () ) ;
if ( ! V_259 )
return - 1 ;
for(; ; )
{
if ( ( V_258 != - 1 ) && V_258 < 1024 )
V_7 = V_258 ;
else
V_7 = 1024 ;
V_7 = F_99 ( V_23 , V_260 , V_7 ) ;
if ( V_7 <= 0 )
break;
if ( F_197 ( V_259 , V_260 , V_7 ) != V_7 )
{
F_78 ( V_259 ) ;
return - 1 ;
}
V_258 -= V_7 ;
if ( V_258 == 0 )
break;
}
V_164 = F_198 ( V_259 , ( char * * ) V_24 ) ;
F_199 ( V_259 , V_261 ) ;
F_78 ( V_259 ) ;
return V_164 ;
}
int F_200 ( T_27 * V_262 , char * V_78 )
{
int V_263 ;
char * V_264 , * V_265 = NULL ;
V_264 = F_50 ( V_78 ) ;
if ( ! V_264 )
return - 1 ;
V_265 = strchr ( V_264 , ':' ) ;
if ( V_265 )
{
* V_265 = 0 ;
V_265 ++ ;
}
V_263 = F_201 ( V_262 , V_264 , V_265 ) ;
F_2 ( V_264 ) ;
return V_263 ;
}
void F_202 ( T_2 * V_24 , T_28 * V_262 )
{
T_29 * V_266 ;
int V_267 ;
int V_268 = 0 ;
if ( V_24 == NULL )
{
V_24 = F_56 ( V_215 , V_72 ) ;
V_268 = 1 ;
}
V_266 = F_203 ( V_262 ) ;
V_267 = F_204 ( V_262 ) ;
F_45 ( V_24 , L_143 ,
V_267 ? L_144 : L_145 ) ;
F_205 ( V_24 , L_146 , F_206 ( V_266 ) ) ;
F_205 ( V_24 , L_147 , F_207 ( V_266 ) ) ;
if ( V_268 )
F_78 ( V_24 ) ;
}
static T_30 * F_208 ( const char * V_269 , const char * V_270 ,
const char * V_271 )
{
T_20 * V_10 = NULL ;
T_20 * V_272 = NULL ;
T_20 * V_28 = NULL ;
T_20 * V_273 = F_159 () ;
T_30 * V_262 ;
F_209 ( & V_10 , L_148 ) ;
V_272 = F_159 () ;
F_210 ( V_272 , 2 ) ;
V_28 = F_159 () ;
F_211 ( V_28 , V_10 ) ;
F_212 ( ( const unsigned char * ) V_271 , strlen ( V_271 ) , V_273 ) ;
V_262 = F_213 ( V_269 , V_270 , V_10 , V_272 , V_28 , V_273 ) ;
F_162 ( V_273 ) ;
F_162 ( V_28 ) ;
F_162 ( V_272 ) ;
F_162 ( V_10 ) ;
return V_262 ;
}
static void F_214 ( T_2 * V_274 , const T_31 * V_10 )
{
F_215 ( V_274 , V_10 -> V_275 ) ;
F_14 ( V_274 , L_9 ) ;
F_215 ( V_274 , V_10 -> V_276 . V_277 ) ;
F_14 ( V_274 , L_9 ) ;
F_215 ( V_274 , V_10 -> V_276 . V_195 ) ;
F_14 ( V_274 , L_9 ) ;
}
static void F_216 ( T_2 * V_278 , T_30 * V_262 )
{
T_32 V_279 ;
F_217 ( & V_279 ) ;
F_218 ( & V_279 , V_262 ) ;
F_214 ( V_278 , & V_279 . V_280 ) ;
F_214 ( V_278 , & V_279 . V_281 ) ;
( void ) F_219 ( V_278 ) ;
F_220 ( & V_279 ) ;
}
static void F_221 ( T_2 * V_278 , T_30 * V_262 )
{
T_33 V_282 ;
F_222 ( & V_282 ) ;
F_223 ( & V_282 , V_262 ) ;
F_214 ( V_278 , & V_282 ) ;
( void ) F_219 ( V_278 ) ;
F_224 ( & V_282 ) ;
}
static void F_225 ( T_2 * V_278 , T_30 * V_262 )
{
T_34 V_283 ;
F_226 ( & V_283 ) ;
F_227 ( & V_283 , V_262 ) ;
F_197 ( V_278 , V_283 . V_284 , sizeof V_283 . V_284 ) ;
( void ) F_219 ( V_278 ) ;
F_228 ( & V_283 ) ;
}
static void F_229 ( T_2 * V_278 , T_30 * V_262 )
{
T_35 V_285 ;
F_230 ( & V_285 ) ;
F_231 ( & V_285 , V_262 ) ;
F_197 ( V_278 , V_285 . V_286 , sizeof V_285 . V_286 ) ;
( void ) F_219 ( V_278 ) ;
F_232 ( & V_285 ) ;
}
static void F_233 ( T_20 * * V_287 , T_2 * V_278 )
{
char V_8 [ 10240 ] ;
int V_288 ;
V_288 = F_57 ( V_278 , V_8 , sizeof V_8 ) ;
assert ( V_288 > 0 ) ;
assert ( V_8 [ V_288 - 1 ] == '\n' ) ;
V_8 [ V_288 - 1 ] = '\0' ;
F_209 ( V_287 , V_8 ) ;
}
static void F_234 ( T_31 * V_10 , T_2 * V_278 )
{
F_233 ( & V_10 -> V_275 , V_278 ) ;
F_233 ( & V_10 -> V_276 . V_277 , V_278 ) ;
F_233 ( & V_10 -> V_276 . V_195 , V_278 ) ;
}
static void F_235 ( T_30 * V_262 , T_2 * V_278 )
{
T_32 V_279 ;
F_217 ( & V_279 ) ;
F_234 ( & V_279 . V_280 , V_278 ) ;
F_234 ( & V_279 . V_281 , V_278 ) ;
if( ! F_236 ( V_262 , & V_279 ) )
{
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_220 ( & V_279 ) ;
}
static void F_237 ( T_30 * V_262 , T_2 * V_278 )
{
T_33 V_282 ;
F_222 ( & V_282 ) ;
F_234 ( & V_282 , V_278 ) ;
if( ! F_238 ( V_262 , & V_282 ) )
{
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_224 ( & V_282 ) ;
}
static void F_239 ( T_30 * V_262 , T_2 * V_278 )
{
T_34 V_283 ;
int V_288 ;
F_226 ( & V_283 ) ;
V_288 = F_99 ( V_278 , V_283 . V_284 , sizeof V_283 . V_284 ) ;
assert ( V_288 == sizeof V_283 . V_284 ) ;
if( ! F_240 ( V_262 , & V_283 ) )
{
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_228 ( & V_283 ) ;
}
static void F_241 ( T_30 * V_262 , T_2 * V_278 )
{
T_35 V_285 ;
int V_288 ;
F_230 ( & V_285 ) ;
V_288 = F_99 ( V_278 , V_285 . V_286 , sizeof V_285 . V_286 ) ;
assert ( V_288 == sizeof V_285 . V_286 ) ;
if( ! F_242 ( V_262 , & V_285 ) )
{
F_46 ( V_58 ) ;
exit ( 1 ) ;
}
F_232 ( & V_285 ) ;
}
void F_243 ( T_2 * V_24 , T_2 * V_274 , const char * V_271 )
{
T_30 * V_262 ;
T_2 * V_278 ;
F_14 ( V_24 , L_149 ) ;
V_262 = F_208 ( L_150 , L_151 , V_271 ) ;
V_278 = F_53 ( F_54 () ) ;
F_55 ( V_278 , V_274 ) ;
F_216 ( V_278 , V_262 ) ;
F_235 ( V_262 , V_278 ) ;
F_221 ( V_278 , V_262 ) ;
F_237 ( V_262 , V_278 ) ;
F_225 ( V_278 , V_262 ) ;
F_241 ( V_262 , V_278 ) ;
F_14 ( V_24 , L_152 ) ;
V_289 = F_244 ( F_245 ( V_262 ) ) ;
F_246 ( V_278 ) ;
F_78 ( V_278 ) ;
F_247 ( V_262 ) ;
}
void F_248 ( T_2 * V_24 , T_2 * V_274 , const char * V_271 )
{
T_30 * V_262 ;
T_2 * V_278 ;
F_14 ( V_24 , L_149 ) ;
V_262 = F_208 ( L_151 , L_150 , V_271 ) ;
V_278 = F_53 ( F_54 () ) ;
F_55 ( V_278 , V_274 ) ;
F_235 ( V_262 , V_278 ) ;
F_216 ( V_278 , V_262 ) ;
F_237 ( V_262 , V_278 ) ;
F_221 ( V_278 , V_262 ) ;
F_239 ( V_262 , V_278 ) ;
F_229 ( V_278 , V_262 ) ;
F_14 ( V_24 , L_152 ) ;
V_289 = F_244 ( F_245 ( V_262 ) ) ;
F_246 ( V_278 ) ;
F_78 ( V_278 ) ;
F_247 ( V_262 ) ;
}
static int F_249 ( const char * V_290 , const char * V_291 )
{
T_36 * V_292 = NULL , * V_293 ;
T_37 V_59 ;
int V_164 = 0 ;
if ( sizeof( T_36 ) == 1 )
{
V_292 = ( T_36 * ) V_290 ;
V_293 = ( T_36 * ) V_291 ;
}
else
{
T_18 V_6 , V_294 = strlen ( V_290 ) + 1 , V_33 = strlen ( V_291 ) + 1 ;
V_292 = ( T_36 * ) malloc ( sizeof( T_36 ) * ( V_294 + V_33 ) ) ;
if ( V_292 == NULL ) goto V_59;
V_293 = V_292 + V_294 ;
#if ! F_6 ( V_295 ) || V_295 >= 101
if ( ! F_250 ( V_296 , 0 , V_290 , V_294 , ( V_297 * ) V_292 , V_294 ) )
#endif
for ( V_6 = 0 ; V_6 < V_294 ; V_6 ++ ) V_292 [ V_6 ] = ( T_36 ) V_290 [ V_6 ] ;
#if ! F_6 ( V_295 ) || V_295 >= 101
if ( ! F_250 ( V_296 , 0 , V_291 , V_33 , ( V_297 * ) V_293 , V_33 ) )
#endif
for ( V_6 = 0 ; V_6 < V_33 ; V_6 ++ ) V_293 [ V_6 ] = ( T_36 ) V_291 [ V_6 ] ;
}
if ( F_251 ( V_292 , V_293 ) ) goto V_50;
V_59 = F_252 () ;
if ( V_59 == V_298 || V_59 == V_299 )
{
if ( F_253 ( V_293 ) && F_251 ( V_292 , V_293 ) )
goto V_50;
V_59 = F_252 () ;
}
if ( V_59 == V_300 || V_59 == V_301 )
V_204 = V_205 ;
else if ( V_59 == V_302 )
V_204 = V_303 ;
else
V_204 = V_304 ;
V_59:
V_164 = - 1 ;
V_50:
if ( V_292 != NULL && V_292 != ( T_36 * ) V_290 ) free ( V_292 ) ;
return V_164 ;
}
double F_254 ( int V_305 , int V_306 )
{
T_38 V_307 ;
double V_164 = 0 ;
static T_39 V_308 ;
static int V_309 = 1 ;
#ifdef F_255
static T_40 V_310 = NULL ;
if ( V_310 == NULL )
{
if ( F_256 () < 0x80000000 )
V_310 = F_257 ( V_311 , FALSE ,
F_258 () ) ;
if ( V_310 == NULL ) V_310 = ( T_40 ) - 1 ;
}
if ( V_306 && V_310 != ( T_40 ) - 1 )
{
T_38 V_312 ;
F_259 ( V_310 , & V_312 , & V_312 , & V_312 , & V_307 ) ;
}
else
#endif
{
T_41 V_313 ;
if ( V_306 && V_309 )
{
F_45 ( V_58 , L_153
L_154 ) ;
V_309 = 0 ;
}
F_260 ( & V_313 ) ;
F_261 ( & V_313 , & V_307 ) ;
}
if ( V_305 == V_314 )
{
V_308 . V_315 . V_316 = V_307 . V_317 ;
V_308 . V_315 . V_318 = V_307 . V_319 ;
}
else {
T_39 V_320 ;
V_320 . V_315 . V_316 = V_307 . V_317 ;
V_320 . V_315 . V_318 = V_307 . V_319 ;
V_164 = ( V_321 ) ( V_320 . V_322 - V_308 . V_322 ) * 1e-7 ;
}
return ( V_164 ) ;
}
double F_254 ( int V_305 , int V_306 )
{
double V_164 = 0 ;
static T_42 V_308 ;
static int V_309 = 1 ;
if ( V_306 && V_309 )
{
F_45 ( V_58 , L_153
L_154 ) ;
V_309 = 0 ;
}
if ( V_305 == V_314 ) V_308 = clock () ;
else V_164 = ( clock () - V_308 ) / ( double ) V_323 ;
return ( V_164 ) ;
}
double F_254 ( int V_305 , int V_306 )
{
double V_164 = 0 ;
#ifdef F_262
static struct V_324 V_308 ;
struct V_324 V_307 ;
#else
static unsigned long V_308 ;
unsigned long V_307 ;
#endif
static int V_309 = 1 ;
if ( V_306 && V_309 )
{
F_45 ( V_58 , L_153
L_154 ) ;
V_309 = 0 ;
}
#ifdef F_262
F_263 ( F_262 , & V_307 ) ;
if ( V_305 == V_314 ) V_308 = V_307 ;
else V_164 = ( ( V_307 . V_325 + V_307 . V_326 * 1e-9 )
- ( V_308 . V_325 + V_308 . V_326 * 1e-9 ) ) ;
#else
V_307 = F_264 () ;
if ( V_305 == V_314 ) V_308 = V_307 ;
else V_164 = ( V_307 - V_308 ) / ( double ) F_265 () ;
#endif
return ( V_164 ) ;
}
double F_254 ( int V_305 , int V_306 )
{
static T_42 V_308 ;
double V_164 = 0 ;
T_42 V_307 ;
#ifdef F_266
struct V_327 V_328 ;
V_307 = F_267 ( & V_328 ) ;
if ( V_306 ) V_307 = V_328 . V_329 ;
#else
if ( V_306 )
V_307 = clock () ;
else {
struct V_330 V_331 ;
F_268 ( & V_331 , NULL ) ;
V_307 = ( T_42 ) (
( unsigned long long ) V_331 . V_325 * V_332 +
( unsigned long long ) V_331 . V_333 * ( 1000000 / V_332 )
) ;
}
#endif
if ( V_305 == V_314 ) V_308 = V_307 ;
else V_164 = ( V_307 - V_308 ) / ( double ) ( V_332 ) ;
return ( V_164 ) ;
}
double F_254 ( int V_305 , int V_306 )
{
double V_164 = 0 ;
struct V_327 V_328 ;
T_42 V_307 = F_267 ( & V_328 ) ;
static T_42 V_308 ;
if ( V_306 ) V_307 = V_328 . V_329 ;
if ( V_305 == V_314 ) V_308 = V_307 ;
else
{
long int V_334 = F_269 ( V_335 ) ;
V_164 = ( V_307 - V_308 ) / ( double ) V_334 ;
}
return ( V_164 ) ;
}
double F_254 ( int V_305 , int V_306 )
{
double V_164 = 0 ;
struct V_336 V_328 ;
struct V_330 V_307 ;
static struct V_330 V_308 ;
if ( V_306 ) F_270 ( V_337 , & V_328 ) , V_307 = V_328 . V_338 ;
else F_268 ( & V_307 , NULL ) ;
if ( V_305 == V_314 ) V_308 = V_307 ;
else V_164 = ( ( V_307 . V_325 + V_307 . V_333 * 1e-6 )
- ( V_308 . V_325 + V_308 . V_333 * 1e-6 ) ) ;
return V_164 ;
}
int F_271 ( const char * V_79 )
{
T_40 V_339 ;
T_43 V_340 ;
#if F_6 ( V_341 ) || F_6 ( V_342 )
T_18 V_6 , V_343 = strlen ( V_79 ) + 1 ;
if ( V_343 > sizeof( V_340 . V_344 ) / sizeof( V_340 . V_344 [ 0 ] ) )
return - 1 ;
#if ! F_6 ( V_295 ) || V_295 >= 101
if ( ! F_250 ( V_296 , 0 , V_79 , V_343 , V_340 . V_344 , V_343 ) )
#endif
for ( V_6 = 0 ; V_6 < V_343 ; V_6 ++ )
V_340 . V_344 [ V_6 ] = ( V_297 ) V_79 [ V_6 ] ;
V_339 = F_272 ( V_340 . V_344 , & V_340 ) ;
#else
V_339 = F_272 ( V_79 , & V_340 ) ;
#endif
if ( V_339 == V_345 ) return - 1 ;
F_273 ( V_339 ) ;
return ( ( V_340 . V_346 & V_347 ) != 0 ) ;
}
int F_271 ( const char * V_79 )
{
#if F_6 ( V_348 )
struct V_349 V_350 ;
if ( V_349 ( V_79 , & V_350 ) == 0 ) return V_348 ( V_350 . V_351 ) ;
else return - 1 ;
#else
return - 1 ;
#endif
}
int F_274 ( void * V_8 , int V_352 )
{
T_37 V_26 ;
if ( F_275 ( F_276 ( V_353 ) , V_8 , V_352 , & V_26 , NULL ) )
return ( V_26 ) ;
else return ( - 1 ) ;
}
int F_274 ( void * V_8 , int V_352 )
{ return F_277 ( fileno ( V_73 ) , V_8 , V_352 ) ; }
int F_278 ( const void * V_8 , int V_352 )
{
T_37 V_26 ;
if ( F_279 ( F_276 ( V_354 ) , V_8 , V_352 , & V_26 , NULL ) )
return ( V_26 ) ;
else return ( - 1 ) ;
}
int F_278 ( const void * V_8 , int V_352 )
{ return F_280 ( fileno ( stdout ) , V_8 , V_352 ) ; }
