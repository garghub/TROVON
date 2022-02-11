static void F_1 ( int V_1 )
{
struct V_2 V_3 = { V_4 , V_5 , 0 , 0 , 0 } ;
V_3 . V_6 = F_2 () ;
if ( F_3 ( V_7 [ V_1 ] . V_8 , V_9 , & V_3 ) == - 1 ) {
F_4 ( V_10 , L_1 , V_1 ,
V_11 , strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
}
static void F_5 ( int V_1 )
{
struct V_2 V_3 = { V_13 , V_5 , 0 , 0 , 0 } ;
V_3 . V_6 = F_2 () ;
if ( F_3 ( V_7 [ V_1 ] . V_8 , V_14 , & V_3 ) == - 1 ) {
F_4 ( V_10 , L_2 , V_1 ,
V_11 , strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
}
static void F_6 ( int V_1 )
{
T_1 * V_15 ;
T_2 V_16 ;
F_1 ( V_1 ) ;
V_15 = fopen ( V_7 [ V_1 ] . V_17 , L_3 ) ;
if ( ! V_15 ) {
F_4 ( V_10 , L_4 , V_1 ,
V_11 , strerror ( V_11 ) ) ;
F_5 ( V_1 ) ;
exit ( V_12 ) ;
}
V_16 = fwrite ( V_7 [ V_1 ] . V_18 ,
sizeof( struct V_19 ) ,
V_7 [ V_1 ] . V_20 , V_15 ) ;
if ( ferror ( V_15 ) || fclose ( V_15 ) ) {
F_5 ( V_1 ) ;
F_4 ( V_10 , L_5 , V_1 ) ;
exit ( V_12 ) ;
}
F_5 ( V_1 ) ;
}
static void F_7 ( int V_1 )
{
T_1 * V_15 ;
T_2 V_21 = 0 ;
struct V_19 * V_22 = V_7 [ V_1 ] . V_18 ;
struct V_19 * V_23 ;
int V_24 = V_7 [ V_1 ] . V_24 ;
int V_25 = sizeof( struct V_19 ) * V_26 ;
F_1 ( V_1 ) ;
V_15 = fopen ( V_7 [ V_1 ] . V_17 , L_6 ) ;
if ( ! V_15 ) {
F_4 ( V_10 , L_4 , V_1 ,
V_11 , strerror ( V_11 ) ) ;
F_5 ( V_1 ) ;
exit ( V_12 ) ;
}
for (; ; ) {
V_23 = & V_22 [ V_21 ] ;
V_21 += fread ( V_23 , sizeof( struct V_19 ) ,
V_26 * V_24 ,
V_15 ) ;
if ( ferror ( V_15 ) ) {
F_4 ( V_10 , L_7 , V_1 ) ;
exit ( V_12 ) ;
}
if ( ! feof ( V_15 ) ) {
V_24 ++ ;
V_22 = realloc ( V_22 , V_25 * V_24 ) ;
if ( V_22 == NULL ) {
F_4 ( V_10 , L_8 ) ;
exit ( V_12 ) ;
}
continue;
}
break;
}
V_7 [ V_1 ] . V_24 = V_24 ;
V_7 [ V_1 ] . V_18 = V_22 ;
V_7 [ V_1 ] . V_20 = V_21 ;
fclose ( V_15 ) ;
F_5 ( V_1 ) ;
}
static int F_8 ( void )
{
int V_8 ;
T_1 * V_15 ;
T_2 V_21 ;
char * V_17 ;
struct V_19 * V_22 ;
struct V_19 * V_23 ;
int V_24 ;
int V_27 ;
int V_25 = sizeof( struct V_19 ) * V_26 ;
if ( F_9 ( V_28 , V_29 ) ) {
if ( F_10 ( V_28 , 0755 ) ) {
F_4 ( V_10 , L_9 , V_28 ,
V_11 , strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
}
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
V_17 = V_7 [ V_27 ] . V_17 ;
V_21 = 0 ;
V_24 = 1 ;
sprintf ( V_17 , L_10 , V_28 , V_27 ) ;
V_8 = F_11 ( V_17 , V_31 | V_32 | V_33 , 0644 ) ;
if ( V_8 == - 1 )
return 1 ;
V_15 = fopen ( V_17 , L_6 ) ;
if ( ! V_15 ) {
F_12 ( V_8 ) ;
return 1 ;
}
V_22 = malloc ( V_25 * V_24 ) ;
if ( V_22 == NULL ) {
fclose ( V_15 ) ;
F_12 ( V_8 ) ;
return 1 ;
}
for (; ; ) {
V_23 = & V_22 [ V_21 ] ;
V_21 += fread ( V_23 , sizeof( struct V_19 ) ,
V_26 ,
V_15 ) ;
if ( ferror ( V_15 ) ) {
F_4 ( V_10 , L_7 ,
V_27 ) ;
exit ( V_12 ) ;
}
if ( ! feof ( V_15 ) ) {
V_24 ++ ;
V_22 = realloc ( V_22 , V_25 *
V_24 ) ;
if ( V_22 == NULL ) {
fclose ( V_15 ) ;
F_12 ( V_8 ) ;
return 1 ;
}
continue;
}
break;
}
V_7 [ V_27 ] . V_8 = V_8 ;
V_7 [ V_27 ] . V_24 = V_24 ;
V_7 [ V_27 ] . V_18 = V_22 ;
V_7 [ V_27 ] . V_20 = V_21 ;
fclose ( V_15 ) ;
}
return 0 ;
}
static int F_13 ( int V_1 , const char * V_34 , int V_35 )
{
int V_27 ;
int V_36 , V_37 ;
int V_20 ;
struct V_19 * V_22 ;
F_7 ( V_1 ) ;
V_20 = V_7 [ V_1 ] . V_20 ;
V_22 = V_7 [ V_1 ] . V_18 ;
for ( V_27 = 0 ; V_27 < V_20 ; V_27 ++ ) {
if ( memcmp ( V_34 , V_22 [ V_27 ] . V_34 , V_35 ) )
continue;
if ( V_27 == V_20 ) {
V_7 [ V_1 ] . V_20 -- ;
F_6 ( V_1 ) ;
return 0 ;
}
V_36 = V_27 ;
V_37 = V_36 + 1 ;
for (; V_37 < V_20 ; V_37 ++ ) {
strcpy ( V_22 [ V_36 ] . V_34 , V_22 [ V_37 ] . V_34 ) ;
strcpy ( V_22 [ V_36 ] . V_38 , V_22 [ V_37 ] . V_38 ) ;
V_36 ++ ;
}
V_7 [ V_1 ] . V_20 -- ;
F_6 ( V_1 ) ;
return 0 ;
}
return 1 ;
}
static int F_14 ( int V_1 , const char * V_34 , int V_35 , const char * V_38 ,
int V_39 )
{
int V_27 ;
int V_20 ;
struct V_19 * V_22 ;
int V_24 ;
if ( ( V_35 > V_40 ) ||
( V_39 > V_41 ) )
return 1 ;
F_7 ( V_1 ) ;
V_20 = V_7 [ V_1 ] . V_20 ;
V_22 = V_7 [ V_1 ] . V_18 ;
V_24 = V_7 [ V_1 ] . V_24 ;
for ( V_27 = 0 ; V_27 < V_20 ; V_27 ++ ) {
if ( memcmp ( V_34 , V_22 [ V_27 ] . V_34 , V_35 ) )
continue;
memcpy ( V_22 [ V_27 ] . V_38 , V_38 , V_39 ) ;
F_6 ( V_1 ) ;
return 0 ;
}
if ( V_20 == ( V_26 * V_24 ) ) {
V_22 = realloc ( V_22 , sizeof( struct V_19 ) *
V_26 * ( V_24 + 1 ) ) ;
if ( V_22 == NULL )
return 1 ;
V_7 [ V_1 ] . V_24 ++ ;
}
memcpy ( V_22 [ V_27 ] . V_38 , V_38 , V_39 ) ;
memcpy ( V_22 [ V_27 ] . V_34 , V_34 , V_35 ) ;
V_7 [ V_1 ] . V_18 = V_22 ;
V_7 [ V_1 ] . V_20 ++ ;
F_6 ( V_1 ) ;
return 0 ;
}
static int F_15 ( int V_1 , const char * V_34 , int V_35 , char * V_38 ,
int V_39 )
{
int V_27 ;
int V_20 ;
struct V_19 * V_22 ;
if ( ( V_35 > V_40 ) ||
( V_39 > V_41 ) )
return 1 ;
F_7 ( V_1 ) ;
V_20 = V_7 [ V_1 ] . V_20 ;
V_22 = V_7 [ V_1 ] . V_18 ;
for ( V_27 = 0 ; V_27 < V_20 ; V_27 ++ ) {
if ( memcmp ( V_34 , V_22 [ V_27 ] . V_34 , V_35 ) )
continue;
memcpy ( V_38 , V_22 [ V_27 ] . V_38 , V_39 ) ;
return 0 ;
}
return 1 ;
}
static int F_16 ( int V_1 , int V_42 , char * V_34 , int V_35 ,
char * V_38 , int V_39 )
{
struct V_19 * V_22 ;
F_7 ( V_1 ) ;
V_22 = V_7 [ V_1 ] . V_18 ;
if ( V_42 >= V_7 [ V_1 ] . V_20 ) {
return 1 ;
}
memcpy ( V_34 , V_22 [ V_42 ] . V_34 , V_35 ) ;
memcpy ( V_38 , V_22 [ V_42 ] . V_38 , V_39 ) ;
return 0 ;
}
void F_17 ( void )
{
T_1 * V_43 ;
char * V_44 , V_45 [ 512 ] ;
F_18 ( & V_46 ) ;
V_47 = V_46 . V_48 ;
V_49 = F_19 ( V_46 . V_48 ) ;
V_50 = V_46 . V_51 ;
V_52 = V_46 . V_53 ;
V_44 = strchr ( V_47 , '-' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_43 = fopen ( L_11 , L_12 ) ;
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
if ( ! strcmp ( V_45 , L_13 ) ) {
V_44 = F_19 ( V_38 ) ;
if ( ! V_44 )
break;
V_50 = V_44 ;
} else if ( ! strcmp ( V_45 , L_14 ) ) {
V_44 = F_19 ( V_38 ) ;
if ( ! V_44 )
break;
V_55 = V_44 ;
}
}
fclose ( V_43 ) ;
return;
}
V_43 = fopen ( L_15 , L_12 ) ;
if ( V_43 != NULL )
goto V_56;
V_43 = fopen ( L_16 , L_12 ) ;
if ( V_43 != NULL )
goto V_56;
return;
V_56:
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_19 ( V_45 ) ;
if ( ! V_44 )
goto V_57;
V_50 = V_44 ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_19 ( V_45 ) ;
if ( ! V_44 )
goto V_57;
V_55 = V_44 ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_19 ( V_45 ) ;
if ( V_44 )
V_58 = V_44 ;
}
}
}
V_57:
fclose ( V_43 ) ;
return;
}
static char * F_20 ( char * V_59 )
{
T_3 * V_60 ;
struct V_61 * V_62 ;
T_1 * V_43 ;
char * V_44 , * V_54 , * V_63 ;
char * V_64 = NULL ;
char V_45 [ 256 ] ;
char * V_65 = L_17 ;
char V_66 [ 256 ] ;
V_60 = F_21 ( V_65 ) ;
if ( V_60 == NULL )
return NULL ;
snprintf ( V_66 , sizeof( V_66 ) , L_18 , V_65 ) ;
V_54 = V_66 + strlen ( V_65 ) ;
while ( ( V_62 = F_22 ( V_60 ) ) != NULL ) {
* V_54 = '\0' ;
strcat ( V_66 , V_62 -> V_67 ) ;
strcat ( V_66 , L_19 ) ;
V_43 = fopen ( V_66 , L_12 ) ;
if ( V_43 == NULL )
continue;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_63 = strchr ( V_44 , '\n' ) ;
if ( V_63 )
* V_63 = '\0' ;
if ( ! strcmp ( V_44 , V_59 ) ) {
V_64 = F_19 ( V_62 -> V_67 ) ;
fclose ( V_43 ) ;
break;
}
}
fclose ( V_43 ) ;
}
F_23 ( V_60 ) ;
return V_64 ;
}
static char * F_24 ( char * V_64 )
{
T_1 * V_43 ;
char * V_44 , * V_63 ;
char V_45 [ 256 ] ;
char V_68 [ 256 ] ;
int V_27 ;
char * V_69 = NULL ;
snprintf ( V_68 , sizeof( V_68 ) , L_20 , L_17 ,
V_64 , L_21 ) ;
V_43 = fopen ( V_68 , L_12 ) ;
if ( V_43 == NULL )
return NULL ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_63 = strchr ( V_44 , '\n' ) ;
if ( V_63 )
* V_63 = '\0' ;
for ( V_27 = 0 ; V_27 < strlen ( V_44 ) ; V_27 ++ )
V_44 [ V_27 ] = toupper ( V_44 [ V_27 ] ) ;
V_69 = F_19 ( V_44 ) ;
}
fclose ( V_43 ) ;
return V_69 ;
}
static char * F_25 ( char * V_70 )
{
T_3 * V_60 ;
struct V_61 * V_62 ;
T_1 * V_43 ;
char * V_44 , * V_54 , * V_63 ;
char * V_64 = NULL ;
char V_45 [ 256 ] ;
char * V_65 = L_17 ;
char V_66 [ 256 ] ;
int V_27 ;
V_60 = F_21 ( V_65 ) ;
if ( V_60 == NULL )
return NULL ;
snprintf ( V_66 , sizeof( V_66 ) , V_65 ) ;
V_54 = V_66 + strlen ( V_65 ) ;
while ( ( V_62 = F_22 ( V_60 ) ) != NULL ) {
* V_54 = '\0' ;
strcat ( V_66 , V_62 -> V_67 ) ;
strcat ( V_66 , L_21 ) ;
V_43 = fopen ( V_66 , L_12 ) ;
if ( V_43 == NULL )
continue;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_63 = strchr ( V_44 , '\n' ) ;
if ( V_63 )
* V_63 = '\0' ;
for ( V_27 = 0 ; V_27 < strlen ( V_44 ) ; V_27 ++ )
V_44 [ V_27 ] = toupper ( V_44 [ V_27 ] ) ;
if ( ! strcmp ( V_44 , V_70 ) ) {
V_64 = F_19 ( V_62 -> V_67 ) ;
fclose ( V_43 ) ;
break;
}
}
fclose ( V_43 ) ;
}
F_23 ( V_60 ) ;
return V_64 ;
}
static void F_26 ( char * V_71 ,
char * V_72 , int V_73 ,
int V_74 , int V_75 )
{
char V_45 [ 256 ] ;
char * V_44 ;
char * V_63 ;
T_1 * V_43 ;
V_43 = F_27 ( V_71 , L_12 ) ;
if ( V_43 == NULL )
return;
if ( V_75 == 0 )
memset ( V_72 , 0 , V_73 ) ;
while ( ( V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ) != NULL ) {
if ( ( V_73 - strlen ( V_72 ) ) < ( V_74 + 1 ) )
break;
V_63 = strchr ( V_44 , '\n' ) ;
if ( V_63 )
* V_63 = '\0' ;
strcat ( V_72 , V_44 ) ;
strcat ( V_72 , L_22 ) ;
}
F_28 ( V_43 ) ;
}
static void F_29 ( char * V_64 ,
struct V_76 * V_77 )
{
char V_71 [ 512 ] ;
char V_78 [ 128 ] ;
char * V_44 ;
T_1 * V_43 ;
sprintf ( V_71 , L_23 , L_24 , V_64 ) ;
strcat ( V_71 , L_25 ) ;
F_26 ( V_71 , ( char * ) V_77 -> V_79 ,
( V_80 * 2 ) , V_81 , 0 ) ;
sprintf ( V_71 , L_23 , L_26 , V_64 ) ;
strcat ( V_71 , L_25 ) ;
F_26 ( V_71 , ( char * ) V_77 -> V_79 ,
( V_80 * 2 ) , V_82 , 1 ) ;
sprintf ( V_71 , L_18 , L_27 ) ;
F_26 ( V_71 , ( char * ) V_77 -> V_83 ,
( V_84 * 2 ) , V_81 , 0 ) ;
sprintf ( V_71 , L_23 , L_28 , V_64 ) ;
V_43 = F_27 ( V_71 , L_12 ) ;
if ( V_43 == NULL )
return;
V_44 = fgets ( V_78 , sizeof( V_78 ) , V_43 ) ;
if ( V_44 == NULL ) {
F_28 ( V_43 ) ;
return;
}
if ( ! strncmp ( V_44 , L_29 , 7 ) )
V_77 -> V_85 = 1 ;
else
V_77 -> V_85 = 0 ;
F_28 ( V_43 ) ;
}
static unsigned int F_30 ( unsigned int * V_86 )
{
unsigned int V_87 = * V_86 - ( ( * V_86 >> 1 ) & 0x55555555 ) ;
V_87 = ( V_87 & 0x33333333 ) + ( ( V_87 >> 2 ) & 0x33333333 ) ;
V_87 = ( V_87 + ( V_87 >> 4 ) ) & 0x0F0F0F0F ;
V_87 = V_87 + ( V_87 >> 8 ) ;
return ( V_87 + ( V_87 >> 16 ) ) & 0x000000FF ;
}
static int F_31 ( void * V_88 ,
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
V_97 = F_32 ( V_89 , & V_92 -> V_99 , V_96 , 50 ) ;
V_95 = V_81 ;
} else {
V_94 = (struct V_93 * ) V_88 ;
V_97 = F_32 ( V_89 , & V_94 -> V_100 . V_101 , V_96 , 50 ) ;
V_95 = V_82 ;
}
if ( ( V_90 - * V_75 ) < V_95 + 2 )
return V_102 ;
if ( V_97 == NULL ) {
strcpy ( V_77 , L_30 ) ;
return V_102 ;
}
if ( * V_75 == 0 )
strcpy ( V_77 , V_96 ) ;
else {
strcat ( V_77 , L_22 ) ;
strcat ( V_77 , V_96 ) ;
}
* V_75 += strlen ( V_97 ) + 1 ;
return 0 ;
}
static int
F_33 ( int V_89 , char * V_64 , int V_103 ,
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
int V_27 ;
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
if ( F_34 ( & V_106 ) ) {
strcpy ( V_77 , L_31 ) ;
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
error = F_31 (
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
for ( V_27 = 0 ; V_27 < 4 ; V_27 ++ )
V_111 += F_30 ( & V_86 [ V_27 ] ) ;
sprintf ( V_110 , L_32 , V_111 ) ;
if ( ( V_90 - V_108 ) <
( strlen ( V_110 ) + 1 ) )
goto V_127;
if ( V_108 == 0 )
strcpy ( V_112 , V_110 ) ;
else {
strcat ( ( char * ) V_109 -> V_126 , L_22 ) ;
strcat ( V_112 , V_110 ) ;
}
V_108 += strlen ( V_112 ) + 1 ;
}
F_29 ( V_64 , V_109 ) ;
}
V_127:
error = F_31 ( V_107 -> V_116 ,
V_107 -> V_116 -> V_119 ,
V_77 ,
V_90 , & V_75 ) ;
if ( error )
goto V_130;
V_107 = V_107 -> V_117 ;
}
V_130:
F_35 ( V_106 ) ;
return error ;
}
static int F_36 ( char * V_92 , int type )
{
int V_131 ;
struct V_132 V_133 ;
V_131 = F_37 ( V_122 , V_92 , & V_133 ) ;
if ( V_131 != 1 ) {
if ( type == V_134 )
return 1 ;
return 0 ;
}
sprintf ( V_92 , L_33
L_34 ,
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
static int F_38 ( char * V_92 )
{
int V_131 ;
struct V_135 V_136 ;
V_131 = F_37 ( V_98 , V_92 , & V_136 ) ;
if ( V_131 == 1 )
return 1 ;
return 0 ;
}
static int F_39 ( char * V_137 , int * V_75 ,
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
int V_27 = 0 ;
while ( V_140 [ V_27 ] == ' ' )
V_27 ++ ;
if ( ( V_63 - V_140 ) <= V_139 ) {
strcpy ( V_138 , ( V_140 + V_27 ) ) ;
* V_75 += ( V_63 - V_140 ) + 1 ;
return 1 ;
}
}
return 0 ;
}
static int F_40 ( T_1 * V_141 , char * V_142 , char * V_143 , char * V_144 )
{
int V_131 ;
V_131 = fprintf ( V_141 , L_35 , V_142 , V_143 , L_36 , V_144 ) ;
if ( V_131 < 0 )
return V_102 ;
return 0 ;
}
static int F_41 ( T_1 * V_141 , char * V_145 , int type )
{
int error = 0 ;
char V_92 [ V_82 ] ;
int V_27 = 0 ;
int V_36 = 0 ;
char V_97 [ 256 ] ;
char V_146 [ 10 ] ;
int V_75 = 0 ;
memset ( V_92 , 0 , sizeof( V_92 ) ) ;
while ( F_39 ( V_145 , & V_75 , V_92 ,
( V_84 * 2 ) ) ) {
V_146 [ 0 ] = 0 ;
if ( F_38 ( V_92 ) ) {
switch ( type ) {
case V_147 :
snprintf ( V_97 , sizeof( V_97 ) , L_18 , L_37 ) ;
break;
case V_134 :
snprintf ( V_97 , sizeof( V_97 ) , L_18 , L_38 ) ;
break;
case V_148 :
snprintf ( V_97 , sizeof( V_97 ) , L_18 , L_39 ) ;
break;
case V_149 :
snprintf ( V_97 , sizeof( V_97 ) , L_18 , L_40 ) ;
break;
}
if ( type == V_149 ) {
snprintf ( V_146 , sizeof( V_146 ) , L_41 , ++ V_27 ) ;
} else if ( type == V_148 && V_27 == 0 ) {
++ V_27 ;
} else {
snprintf ( V_146 , sizeof( V_146 ) , L_41 , V_27 ++ ) ;
}
} else if ( F_36 ( V_92 , type ) ) {
switch ( type ) {
case V_147 :
snprintf ( V_97 , sizeof( V_97 ) , L_18 , L_42 ) ;
break;
case V_134 :
snprintf ( V_97 , sizeof( V_97 ) , L_18 , L_43 ) ;
break;
case V_148 :
snprintf ( V_97 , sizeof( V_97 ) , L_18 ,
L_44 ) ;
break;
case V_149 :
snprintf ( V_97 , sizeof( V_97 ) , L_18 , L_40 ) ;
break;
}
if ( type == V_149 ) {
snprintf ( V_146 , sizeof( V_146 ) , L_41 , ++ V_27 ) ;
} else if ( V_36 == 0 ) {
++ V_36 ;
} else {
snprintf ( V_146 , sizeof( V_146 ) , L_45 , V_36 ++ ) ;
}
} else {
return V_150 ;
}
error = F_40 ( V_141 , V_97 , V_146 , V_92 ) ;
if ( error )
return error ;
memset ( V_92 , 0 , sizeof( V_92 ) ) ;
}
return 0 ;
}
static int F_42 ( char * V_64 , struct V_76 * V_151 )
{
int error = 0 ;
char V_152 [ 128 ] ;
T_1 * V_43 ;
char V_71 [ 512 ] ;
char * V_69 ;
snprintf ( V_152 , sizeof( V_152 ) , L_20 , V_28 ,
L_46 , V_64 ) ;
V_43 = fopen ( V_152 , L_47 ) ;
if ( V_43 == NULL ) {
F_4 ( V_10 , L_48 ,
V_11 , strerror ( V_11 ) ) ;
return V_102 ;
}
V_69 = F_24 ( V_64 ) ;
if ( V_69 == NULL ) {
error = V_102 ;
goto V_153;
}
error = F_40 ( V_43 , L_49 , L_50 , V_69 ) ;
if ( error )
goto V_153;
error = F_40 ( V_43 , L_51 , L_50 , V_64 ) ;
if ( error )
goto V_153;
if ( V_151 -> V_85 ) {
error = F_40 ( V_43 , L_52 , L_50 , L_53 ) ;
if ( error )
goto V_153;
goto V_154;
} else {
error = F_40 ( V_43 , L_52 , L_50 , L_54 ) ;
if ( error )
goto V_153;
}
error = F_41 ( V_43 , ( char * ) V_151 -> V_114 , V_147 ) ;
if ( error )
goto V_153;
error = F_41 ( V_43 , ( char * ) V_151 -> V_126 , V_134 ) ;
if ( error )
goto V_153;
error = F_41 ( V_43 , ( char * ) V_151 -> V_79 , V_148 ) ;
if ( error )
goto V_153;
error = F_41 ( V_43 , ( char * ) V_151 -> V_83 , V_149 ) ;
if ( error )
goto V_153;
V_154:
free ( V_69 ) ;
fclose ( V_43 ) ;
snprintf ( V_71 , sizeof( V_71 ) , L_23 , L_55 , V_152 ) ;
system ( V_71 ) ;
return 0 ;
V_153:
F_4 ( V_10 , L_56 ) ;
free ( V_69 ) ;
fclose ( V_43 ) ;
return error ;
}
static int
F_43 ( char * V_77 , int V_90 )
{
struct V_155 V_156 , * V_157 ;
int error = 0 ;
F_44 ( V_77 , V_90 ) ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_158 = V_98 ;
V_156 . V_159 = V_160 ;
V_156 . V_161 = V_162 ;
error = F_45 ( V_77 , NULL , & V_156 , & V_157 ) ;
if ( error != 0 ) {
strcpy ( V_77 , L_57 ) ;
return error ;
}
strcpy ( V_77 , V_157 -> V_163 ) ;
F_46 ( V_157 ) ;
return error ;
}
static int
F_47 ( int V_8 , struct V_164 * V_165 )
{
struct V_166 * V_167 ;
unsigned int V_168 ;
struct V_169 V_170 ;
char V_77 [ 64 ] ;
struct V_171 V_172 [ 2 ] ;
V_168 = F_48 ( sizeof( struct V_164 ) + V_165 -> V_73 ) ;
V_167 = (struct V_166 * ) V_77 ;
V_167 -> V_173 = 0 ;
V_167 -> V_174 = F_2 () ;
V_167 -> V_175 = V_176 ;
V_167 -> V_177 = F_49 ( V_168 - sizeof( * V_167 ) ) ;
V_167 -> V_178 = 0 ;
V_172 [ 0 ] . V_179 = V_167 ;
V_172 [ 0 ] . V_180 = sizeof( * V_167 ) ;
V_172 [ 1 ] . V_179 = V_165 ;
V_172 [ 1 ] . V_180 = V_168 ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_181 = & V_92 ;
V_170 . V_182 = sizeof( V_92 ) ;
V_170 . V_183 = V_172 ;
V_170 . V_184 = 2 ;
return F_50 ( V_8 , & V_170 , 0 ) ;
}
int main ( void )
{
int V_8 , V_73 , V_185 ;
int error ;
struct V_164 * V_170 ;
struct V_186 V_187 ;
struct V_166 * V_188 ;
struct V_164 * V_189 ;
struct V_190 * V_191 ;
char * V_44 ;
char * V_192 ;
char * V_193 ;
int V_103 ;
int V_1 ;
char * V_64 ;
struct V_76 * V_194 ;
F_51 ( 1 , 0 ) ;
F_52 ( L_58 , 0 , V_195 ) ;
F_4 ( V_196 , L_59 , F_2 () ) ;
F_17 () ;
if ( F_8 () ) {
F_4 ( V_10 , L_60 ) ;
exit ( V_12 ) ;
}
V_8 = F_53 ( V_197 , V_198 , V_199 ) ;
if ( V_8 < 0 ) {
F_4 ( V_10 , L_61 , V_11 ,
strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
V_92 . V_200 = V_197 ;
V_92 . V_201 = 0 ;
V_92 . V_202 = 0 ;
V_92 . V_203 = 0 ;
error = F_54 ( V_8 , (struct V_204 * ) & V_92 , sizeof( V_92 ) ) ;
if ( error < 0 ) {
F_4 ( V_10 , L_62 , V_11 , strerror ( V_11 ) ) ;
F_12 ( V_8 ) ;
exit ( V_12 ) ;
}
V_185 = V_205 ;
if ( F_55 ( V_8 , V_206 , V_207 , & V_185 , sizeof( V_185 ) ) < 0 ) {
F_4 ( V_10 , L_63 , V_11 , strerror ( V_11 ) ) ;
F_12 ( V_8 ) ;
exit ( V_12 ) ;
}
V_170 = (struct V_164 * ) V_208 ;
V_170 -> V_209 . V_210 = V_205 ;
V_170 -> V_209 . V_211 = V_212 ;
V_191 = (struct V_190 * ) V_170 -> V_213 ;
V_191 -> V_214 . V_215 = V_216 ;
V_170 -> V_217 = 0 ;
V_170 -> V_73 = sizeof( struct V_190 ) ;
V_73 = F_47 ( V_8 , V_170 ) ;
if ( V_73 < 0 ) {
F_4 ( V_10 , L_64 , V_11 , strerror ( V_11 ) ) ;
F_12 ( V_8 ) ;
exit ( V_12 ) ;
}
V_187 . V_8 = V_8 ;
while ( 1 ) {
struct V_204 * V_218 = (struct V_204 * ) & V_92 ;
T_4 V_219 = sizeof( V_92 ) ;
V_187 . V_220 = V_221 ;
V_187 . V_222 = 0 ;
if ( F_56 ( & V_187 , 1 , - 1 ) < 0 ) {
F_4 ( V_10 , L_65 , V_11 , strerror ( V_11 ) ) ;
if ( V_11 == V_223 ) {
F_12 ( V_8 ) ;
exit ( V_12 ) ;
}
else
continue;
}
V_73 = F_57 ( V_8 , V_224 , sizeof( V_224 ) , 0 ,
V_218 , & V_219 ) ;
if ( V_73 < 0 ) {
F_4 ( V_10 , L_66 ,
V_92 . V_202 , V_11 , strerror ( V_11 ) ) ;
F_12 ( V_8 ) ;
return - 1 ;
}
if ( V_92 . V_202 ) {
F_4 ( V_225 , L_67 ,
V_92 . V_202 ) ;
continue;
}
V_188 = (struct V_166 * ) V_224 ;
if ( V_188 -> V_175 != V_176 )
continue;
V_189 = (struct V_164 * ) F_58 ( V_188 ) ;
V_191 = (struct V_190 * ) V_189 -> V_213 ;
V_103 = V_191 -> V_214 . V_215 ;
V_1 = V_191 -> V_214 . V_1 ;
V_191 -> error = V_226 ;
if ( ( V_227 ) && ( V_103 == V_216 ) ) {
V_227 = 0 ;
V_44 = ( char * ) V_191 -> V_228 . V_229 . V_230 ;
V_231 = malloc ( strlen ( V_44 ) + 1 ) ;
if ( V_231 ) {
strcpy ( V_231 , V_44 ) ;
F_4 ( V_196 , L_68 ,
V_231 ) ;
} else {
F_4 ( V_10 , L_8 ) ;
}
continue;
}
switch ( V_103 ) {
case V_123 :
V_194 = & V_191 -> V_228 . V_194 ;
V_64 =
F_25 ( ( char * ) V_194 -> V_232 ) ;
if ( V_64 == NULL ) {
V_191 -> error = V_102 ;
break;
}
error = F_33 (
0 , V_64 , V_123 ,
V_194 ,
( V_84 * 2 ) ) ;
if ( error )
V_191 -> error = error ;
free ( V_64 ) ;
break;
case V_233 :
V_194 = & V_191 -> V_228 . V_194 ;
V_64 = F_20 (
( char * ) V_194 -> V_232 ) ;
if ( V_64 == NULL ) {
V_191 -> error = V_234 ;
break;
}
error = F_42 ( V_64 , V_194 ) ;
if ( error )
V_191 -> error = error ;
free ( V_64 ) ;
break;
case V_235 :
if ( F_14 ( V_1 ,
V_191 -> V_228 . V_236 . V_213 . V_34 ,
V_191 -> V_228 . V_236 . V_213 . V_35 ,
V_191 -> V_228 . V_236 . V_213 . V_38 ,
V_191 -> V_228 . V_236 . V_213 . V_39 ) )
V_191 -> error = V_237 ;
break;
case V_238 :
if ( F_15 ( V_1 ,
V_191 -> V_228 . V_236 . V_213 . V_34 ,
V_191 -> V_228 . V_236 . V_213 . V_35 ,
V_191 -> V_228 . V_236 . V_213 . V_38 ,
V_191 -> V_228 . V_236 . V_213 . V_39 ) )
V_191 -> error = V_237 ;
break;
case V_239 :
if ( F_13 ( V_1 ,
V_191 -> V_228 . V_240 . V_34 ,
V_191 -> V_228 . V_240 . V_35 ) )
V_191 -> error = V_237 ;
break;
default:
break;
}
if ( V_103 != V_113 )
goto V_241;
if ( V_1 != V_242 ) {
if ( F_16 ( V_1 ,
V_191 -> V_228 . V_243 . V_42 ,
V_191 -> V_228 . V_243 . V_213 . V_34 ,
V_40 ,
V_191 -> V_228 . V_243 . V_213 . V_38 ,
V_41 ) )
V_191 -> error = V_237 ;
goto V_241;
}
V_191 = (struct V_190 * ) V_189 -> V_213 ;
V_193 = ( char * ) V_191 -> V_228 . V_243 . V_213 . V_34 ;
V_192 = ( char * ) V_191 -> V_228 . V_243 . V_213 . V_38 ;
switch ( V_191 -> V_228 . V_243 . V_42 ) {
case V_244 :
F_43 ( V_192 ,
V_41 ) ;
strcpy ( V_193 , L_69 ) ;
break;
case V_245 :
strcpy ( V_193 , L_70 ) ;
strcpy ( V_192 , V_231 ) ;
break;
case V_246 :
F_33 ( V_98 , NULL , V_113 ,
V_192 , V_41 ) ;
strcpy ( V_193 , L_71 ) ;
break;
case V_247 :
F_33 ( V_122 , NULL , V_113 ,
V_192 , V_41 ) ;
strcpy ( V_193 , L_72 ) ;
break;
case V_248 :
strcpy ( V_192 , V_49 ) ;
strcpy ( V_193 , L_73 ) ;
break;
case V_249 :
strcpy ( V_192 , V_50 ) ;
strcpy ( V_193 , L_74 ) ;
break;
case V_250 :
strcpy ( V_192 , V_55 ) ;
strcpy ( V_193 , L_75 ) ;
break;
case V_251 :
strcpy ( V_192 , V_58 ) ;
strcpy ( V_193 , L_76 ) ;
break;
case V_252 :
strcpy ( V_192 , V_47 ) ;
strcpy ( V_193 , L_77 ) ;
break;
case V_253 :
strcpy ( V_192 , V_52 ) ;
strcpy ( V_193 , L_78 ) ;
break;
default:
V_191 -> error = V_237 ;
break;
}
V_241:
V_189 -> V_209 . V_210 = V_205 ;
V_189 -> V_209 . V_211 = V_212 ;
V_189 -> V_217 = 0 ;
V_189 -> V_73 = sizeof( struct V_190 ) ;
V_73 = F_47 ( V_8 , V_189 ) ;
if ( V_73 < 0 ) {
F_4 ( V_10 , L_79 , V_11 ,
strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
}
}
