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
else
return ( V_21 ) ;
}
void F_5 ( char * V_22 , char * V_23 , int V_24 )
{
int V_6 , V_25 ;
char * V_10 = NULL ;
V_25 = strlen ( V_22 ) ;
for ( V_6 = V_25 - 1 ; V_6 > 0 ; V_6 -- )
{
if ( ( V_22 [ V_6 ] == '/' ) || ( V_22 [ V_6 ] == '\\' ) || ( V_22 [ V_6 ] == ':' ) )
{
V_10 = & ( V_22 [ V_6 + 1 ] ) ;
break;
}
}
if ( V_10 == NULL )
V_10 = V_22 ;
V_25 = strlen ( V_10 ) ;
if ( ( V_25 > 4 ) && ( V_10 [ V_25 - 4 ] == '.' ) &&
( ( V_10 [ V_25 - 3 ] == 'e' ) || ( V_10 [ V_25 - 3 ] == 'E' ) ) &&
( ( V_10 [ V_25 - 2 ] == 'x' ) || ( V_10 [ V_25 - 2 ] == 'X' ) ) &&
( ( V_10 [ V_25 - 1 ] == 'e' ) || ( V_10 [ V_25 - 1 ] == 'E' ) ) )
V_25 -= 4 ;
if ( V_25 > V_24 - 1 )
V_25 = V_24 - 1 ;
for ( V_6 = 0 ; V_6 < V_25 ; V_6 ++ )
{
if ( ( V_10 [ V_6 ] >= 'A' ) && ( V_10 [ V_6 ] <= 'Z' ) )
V_23 [ V_6 ] = V_10 [ V_6 ] - 'A' + 'a' ;
else
V_23 [ V_6 ] = V_10 [ V_6 ] ;
}
V_23 [ V_25 ] = '\0' ;
}
void F_5 ( char * V_22 , char * V_23 , int V_24 )
{
char * V_10 = V_22 , * V_26 ;
char * V_27 = L_6 ;
while( * V_27 != '\0' )
{
V_26 = strrchr ( V_10 , * V_27 ) ;
if ( V_26 > V_10 )
V_10 = V_26 + 1 ;
V_27 ++ ;
}
V_26 = strrchr ( V_10 , '.' ) ;
if ( V_26 == NULL )
V_26 = V_22 + V_24 ;
strncpy ( V_23 , V_10 , V_26 - V_10 ) ;
V_23 [ V_26 - V_10 ] = '\0' ;
}
void F_5 ( char * V_22 , char * V_23 , int V_24 )
{
char * V_10 ;
V_10 = strrchr ( V_22 , '/' ) ;
if ( V_10 != NULL )
V_10 ++ ;
else
V_10 = V_22 ;
strncpy ( V_23 , V_10 , V_24 - 1 ) ;
V_23 [ V_24 - 1 ] = '\0' ;
}
int F_6 ( char * V_28 , char * V_29 )
{
#ifdef F_7
int V_30 ;
V_30 = F_8 ( V_28 , V_29 , V_31 | V_32 ) ;
return ( V_30 ? 0 : - 1 ) ;
#else
F_9 ( V_29 ) ;
return F_10 ( V_28 , V_29 ) ;
#endif
}
int F_11 ( ARGS * V_9 , char * V_8 , int * V_2 , char * * V_3 [] )
{
int V_5 , V_7 , V_6 ;
char * V_10 ;
* V_2 = 0 ;
* V_3 = NULL ;
V_7 = strlen ( V_8 ) ;
V_6 = 0 ;
if ( V_9 -> V_33 == 0 )
{
V_9 -> V_33 = 20 ;
V_9 -> V_34 = ( char * * ) F_3 ( sizeof( char * ) * V_9 -> V_33 ) ;
}
for ( V_6 = 0 ; V_6 < V_9 -> V_33 ; V_6 ++ )
V_9 -> V_34 [ V_6 ] = NULL ;
V_5 = 0 ;
V_10 = V_8 ;
for (; ; )
{
if ( ! * V_10 ) break;
while ( * V_10 && ( ( * V_10 == ' ' ) || ( * V_10 == '\t' ) || ( * V_10 == '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 ) break;
if ( V_5 >= V_9 -> V_33 )
{
V_9 -> V_33 += 20 ;
V_9 -> V_34 = ( char * * ) F_12 ( V_9 -> V_34 ,
sizeof( char * ) * V_9 -> V_33 ) ;
if ( V_2 == 0 ) return ( 0 ) ;
}
V_9 -> V_34 [ V_5 ++ ] = V_10 ;
if ( ( * V_10 == '\'' ) || ( * V_10 == '\"' ) )
{
V_6 = * ( V_10 ++ ) ;
V_9 -> V_34 [ V_5 - 1 ] ++ ;
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
* V_3 = V_9 -> V_34 ;
return ( 1 ) ;
}
int F_13 ( long V_35 )
{
return ( 1 ) ;
}
int F_14 ( T_2 * V_23 , T_3 * V_36 )
{
char V_8 [ 256 ] ;
F_15 ( F_16 ( V_36 ) , V_8 , 256 ) ;
F_17 ( V_23 , L_7 ) ;
F_17 ( V_23 , V_8 ) ;
F_15 ( F_18 ( V_36 ) , V_8 , 256 ) ;
F_17 ( V_23 , L_8 ) ;
F_17 ( V_23 , V_8 ) ;
F_17 ( V_23 , L_9 ) ;
return 0 ;
}
int F_19 ( T_2 * V_37 , char * V_38 , char * V_39 , char * * V_40 , char * * V_41 )
{
int V_42 ;
if( ! V_39 || ! V_38 || strcmp ( V_38 , V_39 ) ) V_42 = 0 ;
else V_42 = 1 ;
if( V_38 ) {
* V_40 = F_20 ( V_37 , V_38 , V_42 ) ;
if( ! * V_40 ) return 0 ;
} else if( V_40 ) * V_40 = NULL ;
if( V_39 ) {
* V_41 = F_20 ( V_37 , V_39 , V_42 ? 2 : 0 ) ;
if( ! * V_41 ) return 0 ;
} else if( V_41 ) * V_41 = NULL ;
return 1 ;
}
static char * F_20 ( T_2 * V_37 , char * V_9 , int V_43 )
{
char * V_44 , V_45 [ V_46 ] ;
static T_2 * V_47 = NULL ;
int V_6 ;
if( ! strncmp ( V_9 , L_10 , 5 ) ) return F_21 ( V_9 + 5 ) ;
if( ! strncmp ( V_9 , L_11 , 4 ) ) {
V_44 = getenv ( V_9 + 4 ) ;
if( ! V_44 ) {
F_22 ( V_37 , L_12 , V_9 + 4 ) ;
return NULL ;
}
return F_21 ( V_44 ) ;
}
if( ! V_43 || ! V_47 ) {
if( ! strncmp ( V_9 , L_13 , 5 ) ) {
V_47 = F_23 ( V_9 + 5 , L_1 ) ;
if( ! V_47 ) {
F_22 ( V_37 , L_14 , V_9 + 5 ) ;
return NULL ;
}
} else if( ! strncmp ( V_9 , L_15 , 3 ) ) {
T_2 * V_48 ;
V_6 = atoi ( V_9 + 3 ) ;
if( V_6 >= 0 ) V_47 = F_24 ( V_6 , V_49 ) ;
if( ( V_6 < 0 ) || ! V_47 ) {
F_22 ( V_37 , L_16 , V_9 + 3 ) ;
return NULL ;
}
V_48 = F_25 ( F_26 () ) ;
V_47 = F_27 ( V_48 , V_47 ) ;
} else if( ! strcmp ( V_9 , L_17 ) ) {
V_47 = F_28 ( V_50 , V_49 ) ;
if( ! V_47 ) {
F_22 ( V_37 , L_18 ) ;
return NULL ;
}
} else {
F_22 ( V_37 , L_19 , V_9 ) ;
return NULL ;
}
}
V_6 = F_29 ( V_47 , V_45 , V_46 ) ;
if( V_43 != 1 ) {
F_30 ( V_47 ) ;
V_47 = NULL ;
}
if( V_6 <= 0 ) {
F_22 ( V_37 , L_20 ) ;
return NULL ;
}
V_44 = strchr ( V_45 , '\n' ) ;
if( V_44 ) * V_44 = 0 ;
return F_21 ( V_45 ) ;
}
int F_31 ( T_2 * V_37 , T_4 * V_51 )
{
char * V_10 ;
F_32 ( V_52 ) * V_53 ;
V_52 * V_54 ;
int V_6 ;
if( ! ( V_10 = F_33 ( V_51 , NULL , L_21 ) ) ) return 1 ;
if( ! ( V_53 = F_34 ( V_51 , V_10 ) ) ) {
F_22 ( V_37 , L_22 , V_10 ) ;
return 0 ;
}
for( V_6 = 0 ; V_6 < F_35 ( V_53 ) ; V_6 ++ ) {
V_54 = F_36 ( V_53 , V_6 ) ;
if( F_37 ( V_54 -> V_55 , V_54 -> V_56 , V_54 -> V_56 ) == V_57 ) {
F_22 ( V_37 , L_23 ,
V_54 -> V_56 , V_54 -> V_55 ) ;
return 0 ;
}
}
return 1 ;
}
T_3 * F_38 ( T_2 * V_37 , char * V_1 , int V_58 )
{
T_5 * V_59 = NULL ;
T_6 * V_8 = NULL ;
T_3 * V_36 = NULL ;
T_2 * V_60 ;
if ( ( V_60 = F_25 ( F_39 () ) ) == NULL )
{
F_40 ( V_37 ) ;
goto V_61;
}
if ( V_1 == NULL )
F_41 ( V_60 , V_50 , V_49 ) ;
else
{
if ( F_42 ( V_60 , V_1 ) <= 0 )
{
perror ( V_1 ) ;
goto V_61;
}
}
if ( V_58 == V_15 )
V_36 = F_43 ( V_60 , NULL ) ;
else if ( V_58 == V_18 )
{
unsigned char * V_10 , * V_62 ;
int V_24 = 0 , V_6 ;
V_8 = F_44 () ;
for (; ; )
{
if ( ( V_8 == NULL ) || ( ! F_45 ( V_8 , V_24 + 1024 * 10 ) ) )
goto V_61;
V_6 = F_46 ( V_60 , & ( V_8 -> V_34 [ V_24 ] ) , 1024 * 10 ) ;
V_24 += V_6 ;
if ( V_6 == 0 ) break;
if ( V_6 < 0 )
{
perror ( L_24 ) ;
goto V_61;
}
}
V_10 = ( unsigned char * ) V_8 -> V_34 ;
V_62 = V_10 ;
if ( ( V_59 = F_47 ( NULL , & V_10 , ( long ) V_24 ) ) == NULL )
goto V_61;
if ( ( V_59 -> V_63 == NULL ) || ( V_59 -> V_63 -> V_34 == NULL ) ||
( strncmp ( V_64 , ( char * ) V_59 -> V_63 -> V_34 ,
V_59 -> V_63 -> V_65 ) != 0 ) )
{
F_22 ( V_37 , L_25 ) ;
goto V_61;
}
V_10 = V_62 ;
V_59 -> V_66 = F_48 () ;
if ( ( V_59 = F_47 ( & V_59 , & V_10 , ( long ) V_24 ) ) == NULL )
goto V_61;
V_36 = ( T_3 * ) V_59 -> V_34 ;
V_59 -> V_34 = NULL ;
}
else if ( V_58 == V_17 )
V_36 = F_49 ( V_60 , NULL , NULL , NULL ) ;
else if ( V_58 == V_20 )
{
T_7 * V_67 = F_50 ( V_60 , NULL ) ;
F_51 ( V_67 , NULL , NULL , & V_36 , NULL ) ;
F_52 ( V_67 ) ;
V_67 = NULL ;
}
else {
F_22 ( V_37 , L_26 ) ;
goto V_61;
}
V_61:
if ( V_36 == NULL )
{
F_22 ( V_37 , L_27 ) ;
F_40 ( V_37 ) ;
}
if ( V_59 != NULL ) F_53 ( V_59 ) ;
if ( V_60 != NULL ) F_54 ( V_60 ) ;
if ( V_8 != NULL ) F_55 ( V_8 ) ;
return ( V_36 ) ;
}
T_8 * F_56 ( T_2 * V_37 , char * V_1 , int V_58 , char * V_68 )
{
T_2 * V_69 = NULL ;
T_8 * V_70 = NULL ;
if ( V_1 == NULL )
{
F_22 ( V_37 , L_28 ) ;
goto V_61;
}
V_69 = F_25 ( F_39 () ) ;
if ( V_69 == NULL )
{
F_40 ( V_37 ) ;
goto V_61;
}
if ( F_42 ( V_69 , V_1 ) <= 0 )
{
perror ( V_1 ) ;
goto V_61;
}
if ( V_58 == V_15 )
{
V_70 = F_57 ( V_69 , NULL ) ;
}
else if ( V_58 == V_17 )
{
V_70 = F_58 ( V_69 , NULL , NULL , V_68 ) ;
}
else if ( V_58 == V_20 )
{
T_7 * V_67 = F_50 ( V_69 , NULL ) ;
F_51 ( V_67 , V_68 , & V_70 , NULL , NULL ) ;
F_52 ( V_67 ) ;
V_67 = NULL ;
}
else
{
F_22 ( V_37 , L_29 ) ;
goto V_61;
}
V_61:
if ( V_69 != NULL ) F_54 ( V_69 ) ;
if ( V_70 == NULL )
F_22 ( V_37 , L_30 ) ;
return ( V_70 ) ;
}
T_8 * F_59 ( T_2 * V_37 , char * V_1 , int V_58 )
{
T_2 * V_69 = NULL ;
T_8 * V_70 = NULL ;
if ( V_1 == NULL )
{
F_22 ( V_37 , L_28 ) ;
goto V_61;
}
V_69 = F_25 ( F_39 () ) ;
if ( V_69 == NULL )
{
F_40 ( V_37 ) ;
goto V_61;
}
if ( F_42 ( V_69 , V_1 ) <= 0 )
{
perror ( V_1 ) ;
goto V_61;
}
if ( V_58 == V_15 )
{
V_70 = F_60 ( V_69 , NULL ) ;
}
else if ( V_58 == V_17 )
{
V_70 = F_61 ( V_69 , NULL , NULL , NULL ) ;
}
else
{
F_22 ( V_37 , L_29 ) ;
goto V_61;
}
V_61:
if ( V_69 != NULL ) F_54 ( V_69 ) ;
if ( V_70 == NULL )
F_22 ( V_37 , L_31 ) ;
return ( V_70 ) ;
}
int F_62 ( unsigned long * V_71 , const char * V_9 )
{
char V_72 ;
const T_9 * V_73 , V_74 [] = {
{ L_32 , V_75 , 0 } ,
{ L_33 , V_76 , 0 } ,
{ L_34 , V_77 , 0 } ,
{ L_35 , V_78 , 0 } ,
{ L_36 , V_79 , 0 } ,
{ L_37 , V_80 , 0 } ,
{ L_38 , V_81 , 0 } ,
{ L_39 , V_82 , 0 } ,
{ L_40 , V_83 , 0 } ,
{ L_41 , V_84 , 0 } ,
{ L_42 , V_85 , 0xffffffffL } ,
{ L_43 , V_86 , V_87 } ,
{ L_44 , V_88 , V_87 } ,
{ L_45 , V_89 , V_87 } ,
{ L_46 , V_90 , V_87 } ,
{ L_47 , V_91 , 0 } ,
{ L_48 , V_92 , V_93 } ,
{ L_49 , V_94 , V_93 } ,
{ L_50 , V_95 , V_93 } ,
{ L_51 , V_96 , V_93 } ,
{ L_52 , V_97 , 0 } ,
{ L_53 , V_98 , 0 } ,
{ L_54 , V_99 , 0xffffffffL } ,
{ L_55 , V_100 , 0xffffffffL } ,
{ L_56 , V_101 , 0xffffffffL } ,
{ NULL , 0 , 0 }
} ;
V_72 = V_9 [ 0 ] ;
if( V_72 == '-' ) {
V_72 = 0 ;
V_9 ++ ;
} else if ( V_72 == '+' ) {
V_72 = 1 ;
V_9 ++ ;
} else V_72 = 1 ;
for( V_73 = V_74 ; V_73 -> V_56 ; V_73 ++ ) {
if( ! strcmp ( V_9 , V_73 -> V_56 ) ) {
* V_71 &= ~ V_73 -> V_102 ;
if( V_72 ) * V_71 |= V_73 -> V_103 ;
else * V_71 &= ~ V_73 -> V_103 ;
return 1 ;
}
}
return 0 ;
}
void F_63 ( T_2 * V_23 , char * V_104 , T_10 * V_105 , unsigned long V_106 )
{
char V_8 [ 256 ] ;
char V_107 = 0 ;
int V_108 = 0 ;
if( V_104 ) F_17 ( V_23 , V_104 ) ;
if( ( V_106 & V_87 ) == V_90 ) {
V_107 = 1 ;
V_108 = 4 ;
}
if( V_106 == V_85 ) {
F_15 ( V_105 , V_8 , 256 ) ;
F_17 ( V_23 , V_8 ) ;
F_17 ( V_23 , L_9 ) ;
} else {
if( V_107 ) F_17 ( V_23 , L_9 ) ;
F_64 ( V_23 , V_105 , V_108 , V_106 ) ;
F_17 ( V_23 , L_9 ) ;
}
}
