static void F_1 ( int V_1 )
{
struct V_2 V_3 = { V_4 , V_5 , 0 , 0 , 0 } ;
V_3 . V_6 = F_2 () ;
if ( F_3 ( V_7 [ V_1 ] . V_8 , V_9 , & V_3 ) == - 1 ) {
F_4 ( V_10 , L_1 , V_1 ) ;
exit ( V_11 ) ;
}
}
static void F_5 ( int V_1 )
{
struct V_2 V_3 = { V_12 , V_5 , 0 , 0 , 0 } ;
V_3 . V_6 = F_2 () ;
if ( F_3 ( V_7 [ V_1 ] . V_8 , V_13 , & V_3 ) == - 1 ) {
perror ( L_2 ) ;
F_4 ( V_10 , L_3 , V_1 ) ;
exit ( V_11 ) ;
}
}
static void F_6 ( int V_1 )
{
T_1 * V_14 ;
T_2 V_15 ;
F_1 ( V_1 ) ;
V_14 = fopen ( V_7 [ V_1 ] . V_16 , L_4 ) ;
if ( ! V_14 ) {
F_5 ( V_1 ) ;
F_4 ( V_10 , L_5 , V_1 ) ;
exit ( V_11 ) ;
}
V_15 = fwrite ( V_7 [ V_1 ] . V_17 ,
sizeof( struct V_18 ) ,
V_7 [ V_1 ] . V_19 , V_14 ) ;
if ( ferror ( V_14 ) || fclose ( V_14 ) ) {
F_5 ( V_1 ) ;
F_4 ( V_10 , L_6 , V_1 ) ;
exit ( V_11 ) ;
}
F_5 ( V_1 ) ;
}
static void F_7 ( int V_1 )
{
T_1 * V_14 ;
T_2 V_20 = 0 ;
struct V_18 * V_21 = V_7 [ V_1 ] . V_17 ;
struct V_18 * V_22 ;
int V_23 = V_7 [ V_1 ] . V_23 ;
int V_24 = sizeof( struct V_18 ) * V_25 ;
F_1 ( V_1 ) ;
V_14 = fopen ( V_7 [ V_1 ] . V_16 , L_7 ) ;
if ( ! V_14 ) {
F_5 ( V_1 ) ;
F_4 ( V_10 , L_5 , V_1 ) ;
exit ( V_11 ) ;
}
for (; ; ) {
V_22 = & V_21 [ V_20 ] ;
V_20 += fread ( V_22 , sizeof( struct V_18 ) ,
V_25 * V_23 ,
V_14 ) ;
if ( ferror ( V_14 ) ) {
F_4 ( V_10 , L_8 , V_1 ) ;
exit ( V_11 ) ;
}
if ( ! feof ( V_14 ) ) {
V_23 ++ ;
V_21 = realloc ( V_21 , V_24 * V_23 ) ;
if ( V_21 == NULL ) {
F_4 ( V_10 , L_9 ) ;
exit ( V_11 ) ;
}
continue;
}
break;
}
V_7 [ V_1 ] . V_23 = V_23 ;
V_7 [ V_1 ] . V_17 = V_21 ;
V_7 [ V_1 ] . V_19 = V_20 ;
fclose ( V_14 ) ;
F_5 ( V_1 ) ;
}
static int F_8 ( void )
{
int V_8 ;
T_1 * V_14 ;
T_2 V_20 ;
char * V_16 ;
struct V_18 * V_21 ;
struct V_18 * V_22 ;
int V_23 ;
int V_26 ;
int V_24 = sizeof( struct V_18 ) * V_25 ;
if ( F_9 ( L_10 , V_27 ) ) {
if ( F_10 ( L_10 , V_28 | V_29 | V_30 ) ) {
F_4 ( V_10 , L_11 ) ;
exit ( V_11 ) ;
}
}
for ( V_26 = 0 ; V_26 < V_31 ; V_26 ++ ) {
V_16 = V_7 [ V_26 ] . V_16 ;
V_20 = 0 ;
V_23 = 1 ;
sprintf ( V_16 , L_12 , V_26 ) ;
V_8 = F_11 ( V_16 , V_32 | V_33 , V_28 | V_29 | V_30 ) ;
if ( V_8 == - 1 )
return 1 ;
V_14 = fopen ( V_16 , L_7 ) ;
if ( ! V_14 )
return 1 ;
V_21 = malloc ( V_24 * V_23 ) ;
if ( V_21 == NULL ) {
fclose ( V_14 ) ;
return 1 ;
}
for (; ; ) {
V_22 = & V_21 [ V_20 ] ;
V_20 += fread ( V_22 , sizeof( struct V_18 ) ,
V_25 ,
V_14 ) ;
if ( ferror ( V_14 ) ) {
F_4 ( V_10 , L_8 ,
V_26 ) ;
exit ( V_11 ) ;
}
if ( ! feof ( V_14 ) ) {
V_23 ++ ;
V_21 = realloc ( V_21 , V_24 *
V_23 ) ;
if ( V_21 == NULL ) {
fclose ( V_14 ) ;
return 1 ;
}
continue;
}
break;
}
V_7 [ V_26 ] . V_8 = V_8 ;
V_7 [ V_26 ] . V_23 = V_23 ;
V_7 [ V_26 ] . V_17 = V_21 ;
V_7 [ V_26 ] . V_19 = V_20 ;
fclose ( V_14 ) ;
}
return 0 ;
}
static int F_12 ( int V_1 , const char * V_34 , int V_35 )
{
int V_26 ;
int V_36 , V_37 ;
int V_19 ;
struct V_18 * V_21 ;
F_7 ( V_1 ) ;
V_19 = V_7 [ V_1 ] . V_19 ;
V_21 = V_7 [ V_1 ] . V_17 ;
for ( V_26 = 0 ; V_26 < V_19 ; V_26 ++ ) {
if ( memcmp ( V_34 , V_21 [ V_26 ] . V_34 , V_35 ) )
continue;
if ( V_26 == V_19 ) {
V_7 [ V_1 ] . V_19 -- ;
F_6 ( V_1 ) ;
return 0 ;
}
V_36 = V_26 ;
V_37 = V_36 + 1 ;
for (; V_37 < V_19 ; V_37 ++ ) {
strcpy ( V_21 [ V_36 ] . V_34 , V_21 [ V_37 ] . V_34 ) ;
strcpy ( V_21 [ V_36 ] . V_38 , V_21 [ V_37 ] . V_38 ) ;
V_36 ++ ;
}
V_7 [ V_1 ] . V_19 -- ;
F_6 ( V_1 ) ;
return 0 ;
}
return 1 ;
}
static int F_13 ( int V_1 , const char * V_34 , int V_35 , const char * V_38 ,
int V_39 )
{
int V_26 ;
int V_19 ;
struct V_18 * V_21 ;
int V_23 ;
if ( ( V_35 > V_40 ) ||
( V_39 > V_41 ) )
return 1 ;
F_7 ( V_1 ) ;
V_19 = V_7 [ V_1 ] . V_19 ;
V_21 = V_7 [ V_1 ] . V_17 ;
V_23 = V_7 [ V_1 ] . V_23 ;
for ( V_26 = 0 ; V_26 < V_19 ; V_26 ++ ) {
if ( memcmp ( V_34 , V_21 [ V_26 ] . V_34 , V_35 ) )
continue;
memcpy ( V_21 [ V_26 ] . V_38 , V_38 , V_39 ) ;
F_6 ( V_1 ) ;
return 0 ;
}
if ( V_19 == ( V_25 * V_23 ) ) {
V_21 = realloc ( V_21 , sizeof( struct V_18 ) *
V_25 * ( V_23 + 1 ) ) ;
if ( V_21 == NULL )
return 1 ;
V_7 [ V_1 ] . V_23 ++ ;
}
memcpy ( V_21 [ V_26 ] . V_38 , V_38 , V_39 ) ;
memcpy ( V_21 [ V_26 ] . V_34 , V_34 , V_35 ) ;
V_7 [ V_1 ] . V_17 = V_21 ;
V_7 [ V_1 ] . V_19 ++ ;
F_6 ( V_1 ) ;
return 0 ;
}
static int F_14 ( int V_1 , const char * V_34 , int V_35 , char * V_38 ,
int V_39 )
{
int V_26 ;
int V_19 ;
struct V_18 * V_21 ;
if ( ( V_35 > V_40 ) ||
( V_39 > V_41 ) )
return 1 ;
F_7 ( V_1 ) ;
V_19 = V_7 [ V_1 ] . V_19 ;
V_21 = V_7 [ V_1 ] . V_17 ;
for ( V_26 = 0 ; V_26 < V_19 ; V_26 ++ ) {
if ( memcmp ( V_34 , V_21 [ V_26 ] . V_34 , V_35 ) )
continue;
memcpy ( V_38 , V_21 [ V_26 ] . V_38 , V_39 ) ;
return 0 ;
}
return 1 ;
}
static int F_15 ( int V_1 , int V_42 , char * V_34 , int V_35 ,
char * V_38 , int V_39 )
{
struct V_18 * V_21 ;
F_7 ( V_1 ) ;
V_21 = V_7 [ V_1 ] . V_17 ;
if ( V_42 >= V_7 [ V_1 ] . V_19 ) {
return 1 ;
}
memcpy ( V_34 , V_21 [ V_42 ] . V_34 , V_35 ) ;
memcpy ( V_38 , V_21 [ V_42 ] . V_38 , V_39 ) ;
return 0 ;
}
void F_16 ( void )
{
T_1 * V_43 ;
char * V_44 , V_45 [ 512 ] ;
F_17 ( & V_46 ) ;
V_47 = V_46 . V_48 ;
V_49 = F_18 ( V_46 . V_48 ) ;
V_50 = V_46 . V_51 ;
V_52 = V_46 . V_53 ;
V_44 = strchr ( V_47 , '-' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_43 = fopen ( L_13 , L_7 ) ;
if ( V_43 != NULL ) {
while ( fgets ( V_45 , sizeof( V_45 ) , V_43 ) ) {
char * V_38 , * V_54 ;
if ( V_45 [ 0 ] == '#' )
continue;
V_44 = strchr ( V_45 , '=' ) ;
if ( ! V_44 )
continue;
* V_44 ++ = 0 ;
V_38 = V_44 ;
V_54 = V_44 ;
while ( * V_44 ) {
if ( * V_44 == '\\' ) {
++ V_44 ;
if ( ! * V_44 )
break;
* V_54 ++ = * V_44 ++ ;
} else if ( * V_44 == '\'' || * V_44 == '"' ||
* V_44 == '\n' ) {
++ V_44 ;
} else {
* V_54 ++ = * V_44 ++ ;
}
}
* V_54 = 0 ;
if ( ! strcmp ( V_45 , L_14 ) ) {
V_44 = F_18 ( V_38 ) ;
if ( ! V_44 )
break;
V_50 = V_44 ;
} else if ( ! strcmp ( V_45 , L_15 ) ) {
V_44 = F_18 ( V_38 ) ;
if ( ! V_44 )
break;
V_55 = V_44 ;
}
}
fclose ( V_43 ) ;
return;
}
V_43 = fopen ( L_16 , L_7 ) ;
if ( V_43 != NULL )
goto V_56;
V_43 = fopen ( L_17 , L_7 ) ;
if ( V_43 != NULL )
goto V_56;
return;
V_56:
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_18 ( V_45 ) ;
if ( ! V_44 )
goto V_57;
V_50 = V_44 ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_18 ( V_45 ) ;
if ( ! V_44 )
goto V_57;
V_55 = V_44 ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_18 ( V_45 ) ;
if ( V_44 )
V_58 = V_44 ;
}
}
}
V_57:
fclose ( V_43 ) ;
return;
}
static char * F_19 ( char * V_59 )
{
T_3 * V_60 ;
struct V_61 * V_62 ;
T_1 * V_43 ;
char * V_44 , * V_54 , * V_63 ;
char * V_64 = NULL ;
char V_45 [ 256 ] ;
char * V_65 = L_18 ;
char V_66 [ 256 ] ;
V_60 = F_20 ( V_65 ) ;
if ( V_60 == NULL )
return NULL ;
snprintf ( V_66 , sizeof( V_66 ) , L_19 , V_65 ) ;
V_54 = V_66 + strlen ( V_65 ) ;
while ( ( V_62 = F_21 ( V_60 ) ) != NULL ) {
* V_54 = '\0' ;
strcat ( V_66 , V_62 -> V_67 ) ;
strcat ( V_66 , L_20 ) ;
V_43 = fopen ( V_66 , L_7 ) ;
if ( V_43 == NULL )
continue;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_63 = strchr ( V_44 , '\n' ) ;
if ( V_63 )
* V_63 = '\0' ;
if ( ! strcmp ( V_44 , V_59 ) ) {
V_64 = F_18 ( V_62 -> V_67 ) ;
fclose ( V_43 ) ;
break;
}
}
fclose ( V_43 ) ;
}
F_22 ( V_60 ) ;
return V_64 ;
}
static char * F_23 ( char * V_64 )
{
T_1 * V_43 ;
char * V_44 , * V_63 ;
char V_45 [ 256 ] ;
char V_68 [ 256 ] ;
int V_26 ;
char * V_69 = NULL ;
snprintf ( V_68 , sizeof( V_68 ) , L_21 , L_18 ,
V_64 , L_22 ) ;
V_43 = fopen ( V_68 , L_7 ) ;
if ( V_43 == NULL )
return NULL ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_63 = strchr ( V_44 , '\n' ) ;
if ( V_63 )
* V_63 = '\0' ;
for ( V_26 = 0 ; V_26 < strlen ( V_44 ) ; V_26 ++ )
V_44 [ V_26 ] = toupper ( V_44 [ V_26 ] ) ;
V_69 = F_18 ( V_44 ) ;
}
fclose ( V_43 ) ;
return V_69 ;
}
static char * F_24 ( char * V_70 )
{
T_3 * V_60 ;
struct V_61 * V_62 ;
T_1 * V_43 ;
char * V_44 , * V_54 , * V_63 ;
char * V_64 = NULL ;
char V_45 [ 256 ] ;
char * V_65 = L_18 ;
char V_66 [ 256 ] ;
int V_26 ;
V_60 = F_20 ( V_65 ) ;
if ( V_60 == NULL )
return NULL ;
snprintf ( V_66 , sizeof( V_66 ) , V_65 ) ;
V_54 = V_66 + strlen ( V_65 ) ;
while ( ( V_62 = F_21 ( V_60 ) ) != NULL ) {
* V_54 = '\0' ;
strcat ( V_66 , V_62 -> V_67 ) ;
strcat ( V_66 , L_22 ) ;
V_43 = fopen ( V_66 , L_7 ) ;
if ( V_43 == NULL )
continue;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_63 = strchr ( V_44 , '\n' ) ;
if ( V_63 )
* V_63 = '\0' ;
for ( V_26 = 0 ; V_26 < strlen ( V_44 ) ; V_26 ++ )
V_44 [ V_26 ] = toupper ( V_44 [ V_26 ] ) ;
if ( ! strcmp ( V_44 , V_70 ) ) {
V_64 = F_18 ( V_62 -> V_67 ) ;
fclose ( V_43 ) ;
break;
}
}
fclose ( V_43 ) ;
}
F_22 ( V_60 ) ;
return V_64 ;
}
static void F_25 ( char * V_71 ,
char * V_72 , int V_73 ,
int V_74 , int V_75 )
{
char V_45 [ 256 ] ;
char * V_44 ;
char * V_63 ;
T_1 * V_43 ;
V_43 = F_26 ( V_71 , L_7 ) ;
if ( V_43 == NULL )
return;
if ( V_75 == 0 )
memset ( V_72 , 0 , V_73 ) ;
while ( ( V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ) != NULL ) {
if ( ( V_73 - strlen ( V_72 ) ) < ( V_74 + 1 ) )
break;
V_63 = strchr ( V_44 , '\n' ) ;
* V_63 = '\0' ;
strcat ( V_72 , V_44 ) ;
strcat ( V_72 , L_23 ) ;
}
F_27 ( V_43 ) ;
}
static void F_28 ( char * V_64 ,
struct V_76 * V_77 )
{
char V_71 [ 512 ] ;
char V_78 [ 128 ] ;
char * V_44 ;
T_1 * V_43 ;
sprintf ( V_71 , L_24 , L_25 , V_64 ) ;
strcat ( V_71 , L_26 ) ;
F_25 ( V_71 , ( char * ) V_77 -> V_79 ,
( V_80 * 2 ) , V_81 , 0 ) ;
sprintf ( V_71 , L_24 , L_27 , V_64 ) ;
strcat ( V_71 , L_26 ) ;
F_25 ( V_71 , ( char * ) V_77 -> V_79 ,
( V_80 * 2 ) , V_82 , 1 ) ;
sprintf ( V_71 , L_19 , L_28 ) ;
F_25 ( V_71 , ( char * ) V_77 -> V_83 ,
( V_84 * 2 ) , V_81 , 0 ) ;
sprintf ( V_71 , L_24 , L_29 , V_64 ) ;
V_43 = F_26 ( V_71 , L_7 ) ;
if ( V_43 == NULL )
return;
V_44 = fgets ( V_78 , sizeof( V_78 ) , V_43 ) ;
if ( V_44 == NULL ) {
F_27 ( V_43 ) ;
return;
}
if ( ! strncmp ( V_44 , L_30 , 7 ) )
V_77 -> V_85 = 1 ;
else
V_77 -> V_85 = 0 ;
F_27 ( V_43 ) ;
}
static unsigned int F_29 ( unsigned int * V_86 )
{
unsigned int V_87 = * V_86 - ( ( * V_86 >> 1 ) & 0x55555555 ) ;
V_87 = ( V_87 & 0x33333333 ) + ( ( V_87 >> 2 ) & 0x33333333 ) ;
V_87 = ( V_87 + ( V_87 >> 4 ) ) & 0x0F0F0F0F ;
V_87 = V_87 + ( V_87 >> 8 ) ;
return ( V_87 + ( V_87 >> 16 ) ) & 0x000000FF ;
}
static int F_30 ( void * V_88 ,
int V_89 , char * V_77 ,
int V_90 , int * V_75 )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
int V_95 ;
char V_96 [ 50 ] ;
const char * V_97 ;
if ( V_89 == V_98 ) {
V_92 = (struct V_91 * ) V_88 ;
V_97 = F_31 ( V_89 , & V_92 -> V_99 , V_96 , 50 ) ;
V_95 = V_81 ;
} else {
V_94 = (struct V_93 * ) V_88 ;
V_97 = F_31 ( V_89 , & V_94 -> V_100 . V_101 , V_96 , 50 ) ;
V_95 = V_82 ;
}
if ( ( V_90 - * V_75 ) < V_95 + 2 )
return V_102 ;
if ( V_97 == NULL ) {
strcpy ( V_77 , L_31 ) ;
return V_102 ;
}
if ( * V_75 == 0 )
strcpy ( V_77 , V_96 ) ;
else {
strcat ( V_77 , L_23 ) ;
strcat ( V_77 , V_96 ) ;
}
* V_75 += strlen ( V_97 ) + 1 ;
return 0 ;
}
static int
F_32 ( int V_89 , char * V_64 , int V_103 ,
void * V_104 , int V_90 )
{
struct V_105 * V_106 ;
struct V_105 * V_107 ;
int V_75 = 0 ;
int V_108 = 0 ;
int error = 0 ;
char * V_77 ;
struct V_76 * V_109 ;
char V_110 [ 5 ] ;
int V_111 ;
int V_26 ;
unsigned int * V_86 ;
char * V_112 ;
struct V_93 * V_94 ;
if ( V_103 == V_113 ) {
V_77 = V_104 ;
} else {
V_109 = V_104 ;
V_77 = ( char * ) V_109 -> V_114 ;
V_109 -> V_115 = 0 ;
}
if ( F_33 ( & V_106 ) ) {
strcpy ( V_77 , L_32 ) ;
return V_102 ;
}
V_107 = V_106 ;
while ( V_107 != NULL ) {
if ( V_107 -> V_116 == NULL ) {
V_107 = V_107 -> V_117 ;
continue;
}
if ( ( V_64 != NULL ) &&
( strncmp ( V_107 -> V_118 , V_64 , strlen ( V_64 ) ) ) ) {
V_107 = V_107 -> V_117 ;
continue;
}
if ( ( ( ( V_89 != 0 ) &&
( V_107 -> V_116 -> V_119 != V_89 ) ) ) ||
( V_107 -> V_120 & V_121 ) ) {
V_107 = V_107 -> V_117 ;
continue;
}
if ( ( V_107 -> V_116 -> V_119 != V_98 ) &&
( V_107 -> V_116 -> V_119 != V_122 ) ) {
V_107 = V_107 -> V_117 ;
continue;
}
if ( V_103 == V_123 ) {
if ( V_107 -> V_116 -> V_119 == V_98 ) {
V_109 -> V_115 |= V_124 ;
error = F_30 (
V_107 -> V_125 ,
V_98 ,
( char * )
V_109 -> V_126 ,
V_90 ,
& V_108 ) ;
if ( error )
goto V_127;
} else {
V_109 -> V_115 |= V_128 ;
V_111 = 0 ;
V_112 = ( char * ) V_109 -> V_126 ;
V_94 = (struct V_93 * )
V_107 -> V_125 ;
V_86 = V_94 -> V_100 . V_129 ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
V_111 += F_29 ( & V_86 [ V_26 ] ) ;
sprintf ( V_110 , L_33 , V_111 ) ;
if ( ( V_90 - V_108 ) <
( strlen ( V_110 ) + 1 ) )
goto V_127;
if ( V_108 == 0 )
strcpy ( V_112 , V_110 ) ;
else
strcat ( V_112 , V_110 ) ;
strcat ( ( char * ) V_109 -> V_126 , L_23 ) ;
V_108 += strlen ( V_112 ) + 1 ;
}
F_28 ( V_64 , V_109 ) ;
}
V_127:
error = F_30 ( V_107 -> V_116 ,
V_107 -> V_116 -> V_119 ,
V_77 ,
V_90 , & V_75 ) ;
if ( error )
goto V_130;
V_107 = V_107 -> V_117 ;
}
V_130:
F_34 ( V_106 ) ;
return error ;
}
static int F_35 ( char * V_92 , int type )
{
int V_131 ;
struct V_132 V_133 ;
V_131 = F_36 ( V_122 , V_92 , & V_133 ) ;
if ( V_131 != 1 ) {
if ( type == V_134 )
return 1 ;
return 0 ;
}
sprintf ( V_92 , L_34
L_35 ,
( int ) V_133 . V_101 [ 0 ] , ( int ) V_133 . V_101 [ 1 ] ,
( int ) V_133 . V_101 [ 2 ] , ( int ) V_133 . V_101 [ 3 ] ,
( int ) V_133 . V_101 [ 4 ] , ( int ) V_133 . V_101 [ 5 ] ,
( int ) V_133 . V_101 [ 6 ] , ( int ) V_133 . V_101 [ 7 ] ,
( int ) V_133 . V_101 [ 8 ] , ( int ) V_133 . V_101 [ 9 ] ,
( int ) V_133 . V_101 [ 10 ] , ( int ) V_133 . V_101 [ 11 ] ,
( int ) V_133 . V_101 [ 12 ] , ( int ) V_133 . V_101 [ 13 ] ,
( int ) V_133 . V_101 [ 14 ] , ( int ) V_133 . V_101 [ 15 ] ) ;
return 1 ;
}
static int F_37 ( char * V_92 )
{
int V_131 ;
struct V_135 V_136 ;
V_131 = F_36 ( V_98 , V_92 , & V_136 ) ;
if ( V_131 == 1 )
return 1 ;
return 0 ;
}
static int F_38 ( char * V_137 , int * V_75 ,
char * V_138 , int V_139 )
{
char * V_63 ;
char * V_140 ;
V_140 = V_137 + * V_75 ;
V_63 = strchr ( V_140 , ';' ) ;
if ( V_63 )
* V_63 = 0 ;
else
V_63 = V_140 + strlen ( V_140 ) ;
if ( strlen ( V_140 ) != 0 ) {
int V_26 = 0 ;
while ( V_140 [ V_26 ] == ' ' )
V_26 ++ ;
if ( ( V_63 - V_140 ) <= V_139 ) {
strcpy ( V_138 , ( V_140 + V_26 ) ) ;
* V_75 += ( V_63 - V_140 ) + 1 ;
return 1 ;
}
}
return 0 ;
}
static int F_39 ( T_1 * V_141 , char * V_142 , char * V_143 , char * V_144 )
{
int V_131 ;
V_131 = fprintf ( V_141 , L_36 , V_142 , V_143 , L_37 , V_144 ) ;
if ( V_131 < 0 )
return V_102 ;
return 0 ;
}
static int F_40 ( T_1 * V_141 , char * V_145 , int type )
{
int error = 0 ;
char V_92 [ V_82 ] ;
int V_26 = 0 ;
int V_36 = 0 ;
char V_97 [ 256 ] ;
char V_146 [ 10 ] ;
int V_75 = 0 ;
memset ( V_92 , 0 , sizeof( V_92 ) ) ;
while ( F_38 ( V_145 , & V_75 , V_92 ,
( V_84 * 2 ) ) ) {
V_146 [ 0 ] = 0 ;
if ( F_37 ( V_92 ) ) {
switch ( type ) {
case V_147 :
snprintf ( V_97 , sizeof( V_97 ) , L_19 , L_38 ) ;
break;
case V_134 :
snprintf ( V_97 , sizeof( V_97 ) , L_19 , L_39 ) ;
break;
case V_148 :
snprintf ( V_97 , sizeof( V_97 ) , L_19 , L_40 ) ;
break;
case V_149 :
snprintf ( V_97 , sizeof( V_97 ) , L_19 , L_41 ) ;
break;
}
if ( V_26 != 0 ) {
if ( type != V_149 ) {
snprintf ( V_146 , sizeof( V_146 ) ,
L_42 , V_26 ++ ) ;
} else {
snprintf ( V_146 , sizeof( V_146 ) ,
L_43 , ++ V_26 ) ;
}
} else if ( type == V_149 ) {
snprintf ( V_146 , sizeof( V_146 ) , L_43 , ++ V_26 ) ;
}
} else if ( F_35 ( V_92 , type ) ) {
switch ( type ) {
case V_147 :
snprintf ( V_97 , sizeof( V_97 ) , L_19 , L_44 ) ;
break;
case V_134 :
snprintf ( V_97 , sizeof( V_97 ) , L_19 , L_45 ) ;
break;
case V_148 :
snprintf ( V_97 , sizeof( V_97 ) , L_19 ,
L_46 ) ;
break;
case V_149 :
snprintf ( V_97 , sizeof( V_97 ) , L_19 , L_41 ) ;
break;
}
if ( ( V_36 != 0 ) || ( type == V_149 ) ) {
if ( type != V_149 ) {
snprintf ( V_146 , sizeof( V_146 ) ,
L_42 , V_36 ++ ) ;
} else {
snprintf ( V_146 , sizeof( V_146 ) ,
L_43 , ++ V_26 ) ;
}
} else if ( type == V_149 ) {
snprintf ( V_146 , sizeof( V_146 ) ,
L_43 , ++ V_26 ) ;
}
} else {
return V_150 ;
}
error = F_39 ( V_141 , V_97 , V_146 , V_92 ) ;
if ( error )
return error ;
memset ( V_92 , 0 , sizeof( V_92 ) ) ;
}
return 0 ;
}
static int F_41 ( char * V_64 , struct V_76 * V_151 )
{
int error = 0 ;
char V_152 [ 128 ] ;
T_1 * V_43 ;
char V_71 [ 512 ] ;
char * V_69 ;
snprintf ( V_152 , sizeof( V_152 ) , L_21 , V_153 ,
L_47 , V_64 ) ;
V_43 = fopen ( V_152 , L_4 ) ;
if ( V_43 == NULL ) {
F_4 ( V_10 , L_48 ) ;
return V_102 ;
}
V_69 = F_23 ( V_64 ) ;
if ( V_69 == NULL ) {
error = V_102 ;
goto V_154;
}
error = F_39 ( V_43 , L_49 , L_50 , V_69 ) ;
if ( error )
goto V_154;
error = F_39 ( V_43 , L_51 , L_50 , V_64 ) ;
if ( error )
goto V_154;
if ( V_151 -> V_85 ) {
error = F_39 ( V_43 , L_52 , L_50 , L_53 ) ;
if ( error )
goto V_154;
goto V_155;
}
error = F_40 ( V_43 , ( char * ) V_151 -> V_114 , V_147 ) ;
if ( error )
goto V_154;
error = F_40 ( V_43 , ( char * ) V_151 -> V_126 , V_134 ) ;
if ( error )
goto V_154;
error = F_40 ( V_43 , ( char * ) V_151 -> V_79 , V_148 ) ;
if ( error )
goto V_154;
error = F_40 ( V_43 , ( char * ) V_151 -> V_83 , V_149 ) ;
if ( error )
goto V_154;
V_155:
free ( V_69 ) ;
fclose ( V_43 ) ;
snprintf ( V_71 , sizeof( V_71 ) , L_24 , L_54 , V_152 ) ;
system ( V_71 ) ;
return 0 ;
V_154:
F_4 ( V_10 , L_55 ) ;
free ( V_69 ) ;
fclose ( V_43 ) ;
return error ;
}
static int
F_42 ( char * V_77 , int V_90 )
{
struct V_156 V_157 , * V_158 ;
int error = 0 ;
F_43 ( V_77 , V_90 ) ;
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
V_157 . V_159 = V_98 ;
V_157 . V_160 = V_161 ;
V_157 . V_162 = V_163 ;
error = F_44 ( V_77 , NULL , & V_157 , & V_158 ) ;
if ( error != 0 ) {
strcpy ( V_77 , L_56 ) ;
return error ;
}
strcpy ( V_77 , V_158 -> V_164 ) ;
F_45 ( V_158 ) ;
return error ;
}
static int
F_46 ( int V_8 , struct V_165 * V_166 )
{
struct V_167 * V_168 ;
unsigned int V_169 ;
struct V_170 V_171 ;
char V_77 [ 64 ] ;
struct V_172 V_173 [ 2 ] ;
V_169 = F_47 ( sizeof( struct V_165 ) + V_166 -> V_73 ) ;
V_168 = (struct V_167 * ) V_77 ;
V_168 -> V_174 = 0 ;
V_168 -> V_175 = F_2 () ;
V_168 -> V_176 = V_177 ;
V_168 -> V_178 = F_48 ( V_169 - sizeof( * V_168 ) ) ;
V_168 -> V_179 = 0 ;
V_173 [ 0 ] . V_180 = V_168 ;
V_173 [ 0 ] . V_181 = sizeof( * V_168 ) ;
V_173 [ 1 ] . V_180 = V_166 ;
V_173 [ 1 ] . V_181 = V_169 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_182 = & V_92 ;
V_171 . V_183 = sizeof( V_92 ) ;
V_171 . V_184 = V_173 ;
V_171 . V_185 = 2 ;
return F_49 ( V_8 , & V_171 , 0 ) ;
}
int main ( void )
{
int V_8 , V_73 , V_186 ;
int error ;
struct V_165 * V_171 ;
struct V_187 V_188 ;
struct V_167 * V_189 ;
struct V_165 * V_190 ;
struct V_191 * V_192 ;
char * V_44 ;
char * V_193 ;
char * V_194 ;
int V_103 ;
int V_1 ;
char * V_64 ;
struct V_76 * V_195 ;
F_50 ( 1 , 0 ) ;
F_51 ( L_57 , 0 , V_196 ) ;
F_4 ( V_197 , L_58 , F_2 () ) ;
F_16 () ;
if ( F_8 () ) {
F_4 ( V_10 , L_59 ) ;
exit ( V_11 ) ;
}
V_8 = F_52 ( V_198 , V_199 , V_200 ) ;
if ( V_8 < 0 ) {
F_4 ( V_10 , L_60 , V_8 ) ;
exit ( V_11 ) ;
}
V_92 . V_201 = V_198 ;
V_92 . V_202 = 0 ;
V_92 . V_203 = 0 ;
V_92 . V_204 = V_205 ;
error = F_53 ( V_8 , (struct V_206 * ) & V_92 , sizeof( V_92 ) ) ;
if ( error < 0 ) {
F_4 ( V_10 , L_61 , error ) ;
F_54 ( V_8 ) ;
exit ( V_11 ) ;
}
V_186 = V_92 . V_204 ;
F_55 ( V_8 , 270 , 1 , & V_186 , sizeof( V_186 ) ) ;
V_171 = (struct V_165 * ) V_207 ;
V_171 -> V_208 . V_209 = V_205 ;
V_171 -> V_208 . V_210 = V_211 ;
V_192 = (struct V_191 * ) V_171 -> V_212 ;
V_192 -> V_213 . V_214 = V_215 ;
V_171 -> V_216 = 0 ;
V_171 -> V_73 = sizeof( struct V_191 ) ;
V_73 = F_46 ( V_8 , V_171 ) ;
if ( V_73 < 0 ) {
F_4 ( V_10 , L_62 , V_73 ) ;
F_54 ( V_8 ) ;
exit ( V_11 ) ;
}
V_188 . V_8 = V_8 ;
while ( 1 ) {
struct V_206 * V_217 = (struct V_206 * ) & V_92 ;
T_4 V_218 = sizeof( V_92 ) ;
V_188 . V_219 = V_220 ;
V_188 . V_221 = 0 ;
F_56 ( & V_188 , 1 , - 1 ) ;
V_73 = F_57 ( V_8 , V_222 , sizeof( V_222 ) , 0 ,
V_217 , & V_218 ) ;
if ( V_73 < 0 ) {
F_4 ( V_10 , L_63 ,
V_92 . V_203 , V_223 , strerror ( V_223 ) ) ;
F_54 ( V_8 ) ;
return - 1 ;
}
if ( V_92 . V_203 ) {
F_4 ( V_224 , L_64 ,
V_92 . V_203 ) ;
continue;
}
V_189 = (struct V_167 * ) V_222 ;
V_190 = (struct V_165 * ) F_58 ( V_189 ) ;
V_192 = (struct V_191 * ) V_190 -> V_212 ;
V_103 = V_192 -> V_213 . V_214 ;
V_1 = V_192 -> V_213 . V_1 ;
V_192 -> error = V_225 ;
if ( ( V_226 ) && ( V_103 == V_215 ) ) {
V_226 = 0 ;
V_44 = ( char * ) V_192 -> V_227 . V_228 . V_229 ;
V_230 = malloc ( strlen ( V_44 ) + 1 ) ;
if ( V_230 ) {
strcpy ( V_230 , V_44 ) ;
F_4 ( V_197 , L_65 ,
V_230 ) ;
} else {
F_4 ( V_10 , L_9 ) ;
}
continue;
}
switch ( V_103 ) {
case V_123 :
V_195 = & V_192 -> V_227 . V_195 ;
V_64 =
F_24 ( ( char * ) V_195 -> V_231 ) ;
if ( V_64 == NULL ) {
V_192 -> error = V_102 ;
break;
}
error = F_32 (
0 , V_64 , V_123 ,
V_195 ,
( V_84 * 2 ) ) ;
if ( error )
V_192 -> error = error ;
free ( V_64 ) ;
break;
case V_232 :
V_195 = & V_192 -> V_227 . V_195 ;
V_64 = F_19 (
( char * ) V_195 -> V_231 ) ;
if ( V_64 == NULL ) {
V_192 -> error = V_233 ;
break;
}
error = F_41 ( V_64 , V_195 ) ;
if ( error )
V_192 -> error = error ;
free ( V_64 ) ;
break;
case V_234 :
if ( F_13 ( V_1 ,
V_192 -> V_227 . V_235 . V_212 . V_34 ,
V_192 -> V_227 . V_235 . V_212 . V_35 ,
V_192 -> V_227 . V_235 . V_212 . V_38 ,
V_192 -> V_227 . V_235 . V_212 . V_39 ) )
V_192 -> error = V_236 ;
break;
case V_237 :
if ( F_14 ( V_1 ,
V_192 -> V_227 . V_235 . V_212 . V_34 ,
V_192 -> V_227 . V_235 . V_212 . V_35 ,
V_192 -> V_227 . V_235 . V_212 . V_38 ,
V_192 -> V_227 . V_235 . V_212 . V_39 ) )
V_192 -> error = V_236 ;
break;
case V_238 :
if ( F_12 ( V_1 ,
V_192 -> V_227 . V_239 . V_34 ,
V_192 -> V_227 . V_239 . V_35 ) )
V_192 -> error = V_236 ;
break;
default:
break;
}
if ( V_103 != V_113 )
goto V_240;
if ( V_1 != V_241 ) {
if ( F_15 ( V_1 ,
V_192 -> V_227 . V_242 . V_42 ,
V_192 -> V_227 . V_242 . V_212 . V_34 ,
V_40 ,
V_192 -> V_227 . V_242 . V_212 . V_38 ,
V_41 ) )
V_192 -> error = V_236 ;
goto V_240;
}
V_192 = (struct V_191 * ) V_190 -> V_212 ;
V_194 = ( char * ) V_192 -> V_227 . V_242 . V_212 . V_34 ;
V_193 = ( char * ) V_192 -> V_227 . V_242 . V_212 . V_38 ;
switch ( V_192 -> V_227 . V_242 . V_42 ) {
case V_243 :
F_42 ( V_193 ,
V_41 ) ;
strcpy ( V_194 , L_66 ) ;
break;
case V_244 :
strcpy ( V_194 , L_67 ) ;
strcpy ( V_193 , V_230 ) ;
break;
case V_245 :
F_32 ( V_98 , NULL , V_113 ,
V_193 , V_41 ) ;
strcpy ( V_194 , L_68 ) ;
break;
case V_246 :
F_32 ( V_122 , NULL , V_113 ,
V_193 , V_41 ) ;
strcpy ( V_194 , L_69 ) ;
break;
case V_247 :
strcpy ( V_193 , V_49 ) ;
strcpy ( V_194 , L_70 ) ;
break;
case V_248 :
strcpy ( V_193 , V_50 ) ;
strcpy ( V_194 , L_71 ) ;
break;
case V_249 :
strcpy ( V_193 , V_55 ) ;
strcpy ( V_194 , L_72 ) ;
break;
case V_250 :
strcpy ( V_193 , V_58 ) ;
strcpy ( V_194 , L_73 ) ;
break;
case V_251 :
strcpy ( V_193 , V_47 ) ;
strcpy ( V_194 , L_74 ) ;
break;
case V_252 :
strcpy ( V_193 , V_52 ) ;
strcpy ( V_194 , L_75 ) ;
break;
default:
V_192 -> error = V_236 ;
break;
}
V_240:
V_190 -> V_208 . V_209 = V_205 ;
V_190 -> V_208 . V_210 = V_211 ;
V_190 -> V_216 = 0 ;
V_190 -> V_73 = sizeof( struct V_191 ) ;
V_73 = F_46 ( V_8 , V_190 ) ;
if ( V_73 < 0 ) {
F_4 ( V_10 , L_76 , V_73 ) ;
exit ( V_11 ) ;
}
}
}
