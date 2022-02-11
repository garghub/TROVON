T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
T_2 V_3 ;
T_1 V_4 ;
V_3 = F_2 ( V_5 | V_6 , FALSE , V_1 ) ;
if( V_3 == NULL ) {
return V_7 ;
}
if( V_2 ) {
F_3 ( ( V_8 ) V_9 , ( V_10 ) V_1 ) ;
if( F_4 ( V_3 , V_2 ) != V_11 )
V_4 = ( F_5 ( V_3 , 0 ) ? V_12 : V_7 ) ;
else
V_4 = V_13 ;
} else {
V_4 = ( F_5 ( V_3 , 0 ) ? V_12 : V_7 ) ;
}
F_6 ( V_3 ) ;
return V_4 ;
}
T_1 F_7 ( T_1 V_1 , T_1 V_14 , T_3 V_15 , T_1 V_2 )
{
T_4 V_16 ;
T_5 V_17 ;
BOOL (F_8 * F_9)( T_1 V_18 , T_3 V_19 ) ;
V_16 = F_10 ( L_1 ) ;
if( V_16 == NULL )
return V_7 ;
F_9 = ( BOOL ( F_8 * ) ( T_1 , T_3 ) )
F_11 ( V_16 , L_2 ) ;
if( F_9 == NULL )
{
F_12 ( V_16 ) ;
return V_7 ;
}
V_17 . V_20 = V_1 ;
V_17 . V_14 = V_14 ;
F_3 ( ( V_8 ) V_21 , ( V_10 ) & V_17 ) ;
F_13 ( V_2 ) ;
F_9 ( V_1 , V_15 ) ;
F_12 ( V_16 ) ;
return V_22 ;
}
BOOL T_6 V_9 ( T_7 V_23 , V_10 V_24 )
{
T_1 V_20 ;
F_14 ( V_23 , & V_20 ) ;
if( V_20 == ( T_1 ) V_24 )
{
F_15 ( V_23 , V_25 , 0 , 0 ) ;
}
return TRUE ;
}
BOOL T_6 V_21 ( T_7 V_23 , V_10 V_24 )
{
T_1 V_20 ;
T_1 V_14 ;
T_5 * V_26 ;
V_26 = ( T_5 * ) V_24 ;
V_14 = F_14 ( V_23 , & V_20 ) ;
if( V_20 == V_26 -> V_20 && V_26 -> V_14 == V_14 )
{
F_15 ( V_23 , V_25 , 0 , 0 ) ;
}
return TRUE ;
}
void F_16 ( char * V_27 )
{
T_8 V_28 ;
T_9 V_29 ;
F_17 ( & V_28 , sizeof( V_28 ) ) ;
V_28 . V_30 = sizeof( V_28 ) ;
F_17 ( & V_29 , sizeof( V_29 ) ) ;
if( F_18 ( NULL , V_27 , NULL , NULL , FALSE , 0 , NULL , NULL , & V_28 , & V_29 ) ) {
( void ) F_4 ( V_29 . V_31 , V_32 ) ;
( void ) F_6 ( V_29 . V_31 ) ;
( void ) F_6 ( V_29 . V_33 ) ;
}
}
void F_19 ( char * V_34 , char * V_35 , char * F_19 )
{
char V_27 [ V_36 ] ;
int V_37 = V_36 ;
char * V_38 ;
char V_39 [ V_36 ] ;
T_10 V_40 ;
V_27 [ 0 ] = '\0' ;
if( F_20 ( V_41 , V_34 , 0 , ( V_42 | V_43 ) , & V_40 ) == V_44 ) {
V_37 = V_36 ;
if( F_21 ( V_40 , V_35 , NULL , NULL , V_27 , & V_37 ) == V_44 ) {
V_38 = getenv ( L_3 ) ;
if( ! strncmp ( V_27 , V_38 , strlen ( V_38 ) + 1 ) ) {
V_27 [ 0 ] = '"' ;
V_37 = V_36 - 1 ;
( void ) F_21 ( V_40 , F_19 , NULL , NULL , & V_27 [ 1 ] , & V_37 ) ;
if( ! strncmp ( V_27 , L_4 , 12 ) ) {
strncat ( V_27 , L_5 , 5 ) ;
}
strncat ( V_27 , L_6 , 2 ) ;
F_22 ( V_40 , V_35 ) ;
} else {
V_27 [ 0 ] = '\0' ;
}
}
F_23 ( V_40 ) ;
}
if( * V_27 ) {
#if 0
MessageBox(NULL,
buffer,
"Uninstall",
MB_YESNO|MB_TOPMOST|MB_ICONQUESTION);
#endif
F_16 ( V_27 ) ;
}
}
void F_24 ()
{
T_10 V_40 ;
T_10 V_45 ;
char V_27 [ V_36 + 1 ] ;
int V_37 = 0 ;
T_1 V_46 = V_47 ;
if( F_20 ( V_41 , V_48 , 0 , ( V_42 ) , & V_40 ) == V_44 ) {
if( F_21 ( V_40 , V_49 , NULL , NULL , V_27 , & V_37 ) == V_44 ) {
if( ! strcmp ( V_27 , V_50 ) ) {
if( F_20 ( V_41 , V_51 , 0 , ( V_42 | V_43 ) , & V_45 ) == V_44 ) {
( void ) F_25 ( V_45 , V_52 , 0 , V_53 , ( V_54 * ) & V_46 , sizeof( T_1 ) ) ;
F_23 ( V_45 ) ;
}
}
}
F_23 ( V_40 ) ;
}
}
void F_26 ( int V_55 , char * V_56 [] )
{
char * V_57 ;
char * V_58 ;
char * V_59 ;
char V_27 [ V_36 + 1 ] ;
char V_60 [ V_61 + 1 ] ;
T_2 * V_62 ;
T_1 V_63 = 0 ;
int V_64 ;
V_27 [ 0 ] = '\0' ;
strncat ( V_27 , V_56 [ 0 ] , strlen ( V_56 [ 0 ] ) + 1 ) ;
if( V_59 = strrchr ( V_27 , '\\' ) )
* V_59 = '\0' ;
strncat ( V_27 , V_65 , strlen ( V_65 ) + 1 ) ;
if( ( V_62 = F_27 ( V_27 , V_66 , 0 , NULL , V_67 , V_68 , NULL ) ) != V_69 ) {
if( F_28 ( V_62 , & V_60 , V_61 , & V_63 , NULL ) != 0 ) {
V_60 [ V_63 ] = '\0' ;
V_58 = V_60 ;
while( V_59 = strchr ( V_58 , '\n' ) ) {
* V_59 ++ = '\0' ;
F_29 ( V_58 ) ;
V_58 = V_59 ;
}
}
F_6 ( V_62 ) ;
}
if( ( V_57 = getenv ( L_7 ) ) != NULL ) {
V_27 [ 0 ] = '\0' ;
strncat ( V_27 , V_57 , strlen ( V_57 ) + 1 ) ;
strncat ( V_27 , V_70 , strlen ( V_70 ) + 1 ) ;
for( V_64 = 2 ; V_64 < V_55 ; V_64 ++ ) {
strncat ( V_27 , L_8 , 2 ) ;
strncat ( V_27 , V_56 [ V_64 ] , strlen ( V_56 [ V_64 ] ) + 1 ) ;
}
F_16 ( V_27 ) ;
}
}
void F_30 ( T_1 V_71 )
{
T_1 V_72 = 0 ;
T_2 V_73 = V_69 ;
T_11 V_74 ;
T_1 V_75 ;
char * V_76 ;
char V_77 [ V_78 + 1 ] ;
char V_79 [ V_78 + 1 ] ;
V_76 = getenv ( L_7 ) ;
strncpy ( V_77 , V_76 , strlen ( V_76 ) + 1 ) ;
strncat ( V_77 , L_9 , 7 ) ;
V_73 = F_31 ( V_77 , & V_74 ) ;
if( V_73 != V_69 ) {
do {
V_72 = ( T_1 ) atoi ( V_74 . V_80 ) ;
if( V_72 )
F_1 ( V_72 , V_71 ) ;
strncpy ( V_79 , V_76 , strlen ( V_76 ) + 1 ) ;
strncat ( V_79 , L_10 , 2 ) ;
strncat ( V_79 , V_74 . V_80 , strlen ( V_74 . V_80 ) + 1 ) ;
F_32 ( F_33 ( V_79 ) ) ;
} while( F_34 ( V_73 , & V_74 ) != 0 );
F_35 ( V_73 ) ;
}
}
void F_36 ( char * V_81 )
{
T_10 V_40 ;
T_1 V_82 ;
char V_27 [ V_36 ] ;
int V_37 = V_36 ;
V_27 [ 0 ] = '\0' ;
if( F_37 ( V_83 , V_81 , 0 , NULL , 0 , ( V_42 | V_43 ) , NULL , & V_40 , & V_82 ) == V_44 ) {
if( ( F_21 ( V_40 , L_11 , NULL , NULL , V_27 , & V_37 ) != V_44 ) || ( V_27 [ 0 ] == '\0' ) ) {
( void ) F_25 ( V_40 , L_11 , 0 , V_84 , V_85 , strlen ( V_85 ) + 1 ) ;
}
F_23 ( V_40 ) ;
}
}
BOOL F_38 ()
{
char * * V_86 ;
char * V_87 ;
T_2 * V_62 ;
char V_27 [ V_36 + 1 ] ;
T_1 V_37 ;
T_1 V_88 ;
BOOL V_89 = FALSE ;
V_87 = getenv ( L_7 ) ;
V_27 [ 0 ] = '\0' ;
strncat ( V_27 , V_87 , strlen ( V_87 ) + 1 ) ;
strncat ( V_27 , V_65 , strlen ( V_65 ) + 1 ) ;
if( ( V_62 = F_27 ( V_27 , V_90 , 0 , NULL , V_91 , V_68 , NULL ) ) != V_69 ) {
for( V_86 = V_92 ; * V_86 ; V_86 ++ ) {
if( V_87 = getenv ( * V_86 ) ) {
V_27 [ 0 ] = '\0' ;
strncat ( V_27 , * V_86 , strlen ( * V_86 ) + 1 ) ;
strncat ( V_27 , L_12 , 2 ) ;
strncat ( V_27 , V_87 , strlen ( V_87 ) + 1 ) ;
strncat ( V_27 , L_13 , 2 ) ;
V_37 = strlen ( V_27 ) ;
F_39 ( V_62 , V_27 , V_37 , & V_88 , NULL ) ;
}
}
F_6 ( V_62 ) ;
V_89 = TRUE ;
}
return V_89 ;
}
void F_40 ( char * V_81 )
{
T_10 V_40 ;
T_1 V_82 ;
char V_27 [ V_36 ] ;
int V_37 = V_36 ;
boolean V_93 = FALSE ;
V_27 [ 0 ] = '\0' ;
if( F_20 ( V_83 , V_81 , 0 , ( V_42 | V_43 ) , & V_40 ) == V_44 ) {
if( F_21 ( V_40 , L_11 , NULL , NULL , V_27 , & V_37 ) == V_44 ) {
if( ! strncmp ( V_27 , V_85 , strlen ( V_85 ) + 1 ) )
V_93 = TRUE ;
}
F_23 ( V_40 ) ;
}
if( V_93 )
F_41 ( V_83 , V_81 ) ;
}
void F_42 ( void )
{
char * * V_94 ;
T_10 V_40 ;
T_1 V_82 ;
char * V_76 ;
char * V_95 ;
char * V_38 ;
char * V_96 ;
char V_97 [ V_78 + 1 ] ;
char V_98 [ V_78 + 1 ] ;
char V_99 [ V_78 + 1 ] ;
char V_100 [ V_78 + 1 ] ;
char V_39 [ V_36 ] ;
char V_27 [ V_36 ] ;
int V_37 = V_36 ;
boolean V_101 = FALSE ;
boolean V_102 = FALSE ;
if( F_37 ( V_83 , V_85 , 0 , NULL , 0 ,
( V_42 | V_43 ) , NULL , & V_40 , & V_82 ) == V_44 ) {
( void ) F_25 ( V_40 , L_11 , 0 , V_84 , V_103 , strlen ( V_103 ) + 1 ) ;
F_23 ( V_40 ) ;
}
V_76 = getenv ( L_7 ) ;
strncpy ( V_97 , V_76 , strlen ( V_76 ) + 1 ) ;
strncat ( V_97 , V_104 , strlen ( V_104 ) + 1 ) ;
strncpy ( V_39 , V_85 , strlen ( V_85 ) + 1 ) ;
strncat ( V_39 , V_105 , strlen ( V_105 ) + 1 ) ;
if( F_37 ( V_83 , V_39 , 0 , NULL , 0 ,
( V_42 | V_43 ) , NULL , & V_40 , & V_82 ) == V_44 ) {
( void ) F_25 ( V_40 , L_11 , 0 , V_84 , V_97 , strlen ( V_97 ) + 1 ) ;
F_23 ( V_40 ) ;
}
strncpy ( V_39 , V_85 , strlen ( V_85 ) + 1 ) ;
strncat ( V_39 , V_106 , strlen ( V_106 ) + 1 ) ;
strncpy ( V_97 , V_76 , strlen ( V_76 ) + 1 ) ;
strncat ( V_97 , V_70 , strlen ( V_70 ) + 1 ) ;
strncat ( V_97 , L_14 , 3 ) ;
if( F_37 ( V_83 , V_39 , 0 , NULL , 0 ,
( V_42 | V_43 ) , NULL , & V_40 , & V_82 ) == V_44 ) {
( void ) F_25 ( V_40 , L_11 , 0 , V_84 , V_97 , strlen ( V_97 ) + 1 ) ;
F_23 ( V_40 ) ;
}
for( V_94 = V_107 ; * V_94 ; V_94 ++ )
F_36 ( * V_94 ) ;
F_43 ( V_108 , V_109 , 0 , 0 ) ;
if( F_20 ( V_41 , V_110 , 0 , ( V_42 ) , & V_40 ) == V_44 ) {
if( F_21 ( V_40 , V_111 , NULL , NULL , V_27 , & V_37 ) == V_44 ) {
if( V_27 [ 0 ] != '\0' )
V_101 = TRUE ;
}
F_23 ( V_40 ) ;
}
if( ! V_101 &&
( F_44 ( NULL ,
F_33 ( L_15 ) ,
F_33 ( L_16 ) ,
V_112 | V_113 | V_114 ) == V_115 ) ) {
V_95 = getenv ( L_17 ) ;
strncpy ( V_98 , L_6 , 2 ) ;
strncat ( V_98 , V_95 , strlen ( V_95 ) + 1 ) ;
strncat ( V_98 , V_116 , strlen ( V_116 ) + 1 ) ;
strncat ( V_98 , L_6 , 2 ) ;
F_16 ( V_98 ) ;
if( F_20 ( V_41 , V_110 , 0 , ( V_42 | V_43 ) , & V_40 ) == V_44 ) {
V_38 = getenv ( L_3 ) ;
( void ) F_25 ( V_40 , V_117 , 0 , V_84 , V_38 , strlen ( V_38 ) + 1 ) ;
F_24 () ;
}
}
if( F_20 ( V_41 , V_118 , 0 , ( V_42 ) , & V_40 ) == V_44 ) {
V_37 = V_36 ;
if( F_21 ( V_40 , V_119 , NULL , NULL , V_27 , & V_37 ) == V_44 ) {
if( V_27 [ 0 ] != '\0' )
V_102 = TRUE ;
}
F_23 ( V_40 ) ;
}
if( ! V_102 ) {
V_95 = getenv ( L_17 ) ;
strncpy ( V_99 , L_6 , 2 ) ;
strncat ( V_99 , V_95 , strlen ( V_95 ) + 1 ) ;
strncat ( V_99 , V_120 , strlen ( V_120 ) + 1 ) ;
strncat ( V_99 , L_18 , 5 ) ;
F_16 ( V_99 ) ;
if( F_20 ( V_41 , V_118 , 0 , ( V_42 | V_43 ) , & V_40 ) == V_44 ) {
V_38 = getenv ( L_3 ) ;
( void ) F_25 ( V_40 , V_121 , 0 , V_84 , V_38 , strlen ( V_38 ) + 1 ) ;
}
}
V_96 = getenv ( L_19 ) ;
strncpy ( V_100 , V_96 , strlen ( V_96 ) + 1 ) ;
strncat ( V_100 , V_122 , strlen ( V_122 ) + 1 ) ;
( void ) F_45 ( V_100 , NULL ) ;
F_38 () ;
}
void F_46 ( void )
{
T_1 V_82 ;
char * * V_94 ;
char * V_38 ;
char V_39 [ V_36 ] ;
F_30 ( 0 ) ;
for( V_94 = V_107 ; * V_94 ; V_94 ++ )
F_40 ( * V_94 ) ;
F_43 ( V_108 , V_109 , 0 , 0 ) ;
strncpy ( V_39 , V_85 , strlen ( V_85 ) + 1 ) ;
strncat ( V_39 , V_105 , strlen ( V_105 ) + 1 ) ;
F_41 ( V_83 , V_39 ) ;
strncpy ( V_39 , V_85 , strlen ( V_85 ) + 1 ) ;
strncat ( V_39 , V_123 , strlen ( V_123 ) + 1 ) ;
F_41 ( V_83 , V_39 ) ;
strncpy ( V_39 , V_85 , strlen ( V_85 ) + 1 ) ;
strncat ( V_39 , V_124 , strlen ( V_124 ) + 1 ) ;
F_41 ( V_83 , V_39 ) ;
strncpy ( V_39 , V_85 , strlen ( V_85 ) + 1 ) ;
strncat ( V_39 , V_106 , strlen ( V_106 ) + 1 ) ;
F_41 ( V_83 , V_39 ) ;
F_41 ( V_83 , V_85 ) ;
F_19 ( V_110 , V_117 , V_111 ) ;
F_19 ( V_118 , V_121 , V_119 ) ;
}
main ( int V_55 , char * V_56 [] )
{
T_1 V_125 = 0 ;
char * V_126 ;
#if 0
char **envptr;
char *envval;
# endif
V_126 = getenv ( L_20 ) ;
if( V_126 && ! strncmp ( V_126 , L_21 , 4 ) )
V_125 = V_32 ;
#if 0
for(envptr = environmentvars; *envptr; envptr++) {
envval = getenv(*envptr);
MessageBox(NULL,
envval ? envval : "NULL",
*envptr,
MB_YESNO|MB_TOPMOST|MB_ICONQUESTION);
}
#endif
if( V_55 > 1 ) {
if( ! strncmp ( V_56 [ 1 ] , L_22 , 13 ) )
F_42 () ;
else if( ! strncmp ( V_56 [ 1 ] , L_23 , 9 ) )
F_26 ( V_55 , V_56 ) ;
else if( ! strncmp ( V_56 [ 1 ] , L_24 , 8 ) )
F_30 ( V_125 ) ;
else if( ! strncmp ( V_56 [ 1 ] , L_25 , 11 ) )
F_46 () ;
}
exit ( 0 ) ;
}
