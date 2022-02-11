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
F_1 ( V_1 ) ;
V_15 = fopen ( V_7 [ V_1 ] . V_16 , L_3 ) ;
if ( ! V_15 ) {
F_4 ( V_10 , L_4 , V_1 ,
V_11 , strerror ( V_11 ) ) ;
F_5 ( V_1 ) ;
exit ( V_12 ) ;
}
fwrite ( V_7 [ V_1 ] . V_17 , sizeof( struct V_18 ) ,
V_7 [ V_1 ] . V_19 , V_15 ) ;
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
T_2 V_20 = 0 ;
struct V_18 * V_21 = V_7 [ V_1 ] . V_17 ;
struct V_18 * V_22 ;
int V_23 = V_7 [ V_1 ] . V_23 ;
int V_24 = sizeof( struct V_18 ) * V_25 ;
F_1 ( V_1 ) ;
V_15 = fopen ( V_7 [ V_1 ] . V_16 , L_6 ) ;
if ( ! V_15 ) {
F_4 ( V_10 , L_4 , V_1 ,
V_11 , strerror ( V_11 ) ) ;
F_5 ( V_1 ) ;
exit ( V_12 ) ;
}
for (; ; ) {
V_22 = & V_21 [ V_20 ] ;
V_20 += fread ( V_22 , sizeof( struct V_18 ) ,
V_25 * V_23 ,
V_15 ) ;
if ( ferror ( V_15 ) ) {
F_4 ( V_10 , L_7 , V_1 ) ;
exit ( V_12 ) ;
}
if ( ! feof ( V_15 ) ) {
V_23 ++ ;
V_21 = realloc ( V_21 , V_24 * V_23 ) ;
if ( V_21 == NULL ) {
F_4 ( V_10 , L_8 ) ;
exit ( V_12 ) ;
}
continue;
}
break;
}
V_7 [ V_1 ] . V_23 = V_23 ;
V_7 [ V_1 ] . V_17 = V_21 ;
V_7 [ V_1 ] . V_19 = V_20 ;
fclose ( V_15 ) ;
F_5 ( V_1 ) ;
}
static int F_8 ( void )
{
int V_8 ;
T_1 * V_15 ;
T_2 V_20 ;
char * V_16 ;
struct V_18 * V_21 ;
struct V_18 * V_22 ;
int V_23 ;
int V_26 ;
int V_24 = sizeof( struct V_18 ) * V_25 ;
if ( F_9 ( V_27 , V_28 ) ) {
if ( F_10 ( V_27 , 0755 ) ) {
F_4 ( V_10 , L_9 , V_27 ,
V_11 , strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
}
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ ) {
V_16 = V_7 [ V_26 ] . V_16 ;
V_20 = 0 ;
V_23 = 1 ;
sprintf ( V_16 , L_10 , V_27 , V_26 ) ;
V_8 = F_11 ( V_16 , V_30 | V_31 | V_32 , 0644 ) ;
if ( V_8 == - 1 )
return 1 ;
V_15 = fopen ( V_16 , L_6 ) ;
if ( ! V_15 ) {
F_12 ( V_8 ) ;
return 1 ;
}
V_21 = malloc ( V_24 * V_23 ) ;
if ( V_21 == NULL ) {
fclose ( V_15 ) ;
F_12 ( V_8 ) ;
return 1 ;
}
for (; ; ) {
V_22 = & V_21 [ V_20 ] ;
V_20 += fread ( V_22 , sizeof( struct V_18 ) ,
V_25 ,
V_15 ) ;
if ( ferror ( V_15 ) ) {
F_4 ( V_10 , L_7 ,
V_26 ) ;
exit ( V_12 ) ;
}
if ( ! feof ( V_15 ) ) {
V_23 ++ ;
V_21 = realloc ( V_21 , V_24 *
V_23 ) ;
if ( V_21 == NULL ) {
fclose ( V_15 ) ;
F_12 ( V_8 ) ;
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
fclose ( V_15 ) ;
}
return 0 ;
}
static int F_13 ( int V_1 , const T_3 * V_33 , int V_34 )
{
int V_26 ;
int V_35 , V_36 ;
int V_19 ;
struct V_18 * V_21 ;
F_7 ( V_1 ) ;
V_19 = V_7 [ V_1 ] . V_19 ;
V_21 = V_7 [ V_1 ] . V_17 ;
for ( V_26 = 0 ; V_26 < V_19 ; V_26 ++ ) {
if ( memcmp ( V_33 , V_21 [ V_26 ] . V_33 , V_34 ) )
continue;
if ( V_26 == V_19 ) {
V_7 [ V_1 ] . V_19 -- ;
F_6 ( V_1 ) ;
return 0 ;
}
V_35 = V_26 ;
V_36 = V_35 + 1 ;
for (; V_36 < V_19 ; V_36 ++ ) {
strcpy ( V_21 [ V_35 ] . V_33 , V_21 [ V_36 ] . V_33 ) ;
strcpy ( V_21 [ V_35 ] . V_37 , V_21 [ V_36 ] . V_37 ) ;
V_35 ++ ;
}
V_7 [ V_1 ] . V_19 -- ;
F_6 ( V_1 ) ;
return 0 ;
}
return 1 ;
}
static int F_14 ( int V_1 , const T_3 * V_33 , int V_34 ,
const T_3 * V_37 , int V_38 )
{
int V_26 ;
int V_19 ;
struct V_18 * V_21 ;
int V_23 ;
if ( ( V_34 > V_39 ) ||
( V_38 > V_40 ) )
return 1 ;
F_7 ( V_1 ) ;
V_19 = V_7 [ V_1 ] . V_19 ;
V_21 = V_7 [ V_1 ] . V_17 ;
V_23 = V_7 [ V_1 ] . V_23 ;
for ( V_26 = 0 ; V_26 < V_19 ; V_26 ++ ) {
if ( memcmp ( V_33 , V_21 [ V_26 ] . V_33 , V_34 ) )
continue;
memcpy ( V_21 [ V_26 ] . V_37 , V_37 , V_38 ) ;
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
memcpy ( V_21 [ V_26 ] . V_37 , V_37 , V_38 ) ;
memcpy ( V_21 [ V_26 ] . V_33 , V_33 , V_34 ) ;
V_7 [ V_1 ] . V_17 = V_21 ;
V_7 [ V_1 ] . V_19 ++ ;
F_6 ( V_1 ) ;
return 0 ;
}
static int F_15 ( int V_1 , const T_3 * V_33 , int V_34 , T_3 * V_37 ,
int V_38 )
{
int V_26 ;
int V_19 ;
struct V_18 * V_21 ;
if ( ( V_34 > V_39 ) ||
( V_38 > V_40 ) )
return 1 ;
F_7 ( V_1 ) ;
V_19 = V_7 [ V_1 ] . V_19 ;
V_21 = V_7 [ V_1 ] . V_17 ;
for ( V_26 = 0 ; V_26 < V_19 ; V_26 ++ ) {
if ( memcmp ( V_33 , V_21 [ V_26 ] . V_33 , V_34 ) )
continue;
memcpy ( V_37 , V_21 [ V_26 ] . V_37 , V_38 ) ;
return 0 ;
}
return 1 ;
}
static int F_16 ( int V_1 , int V_41 , T_3 * V_33 , int V_34 ,
T_3 * V_37 , int V_38 )
{
struct V_18 * V_21 ;
F_7 ( V_1 ) ;
V_21 = V_7 [ V_1 ] . V_17 ;
if ( V_41 >= V_7 [ V_1 ] . V_19 ) {
return 1 ;
}
memcpy ( V_33 , V_21 [ V_41 ] . V_33 , V_34 ) ;
memcpy ( V_37 , V_21 [ V_41 ] . V_37 , V_38 ) ;
return 0 ;
}
void F_17 ( void )
{
T_1 * V_42 ;
char * V_43 , V_44 [ 512 ] ;
F_18 ( & V_45 ) ;
V_46 = V_45 . V_47 ;
V_48 = F_19 ( V_45 . V_47 ) ;
V_49 = V_45 . V_50 ;
V_51 = V_45 . V_52 ;
V_43 = strchr ( V_46 , '-' ) ;
if ( V_43 )
* V_43 = '\0' ;
V_42 = fopen ( L_11 , L_12 ) ;
if ( V_42 != NULL ) {
while ( fgets ( V_44 , sizeof( V_44 ) , V_42 ) ) {
char * V_37 , * V_53 ;
if ( V_44 [ 0 ] == '#' )
continue;
V_43 = strchr ( V_44 , '=' ) ;
if ( ! V_43 )
continue;
* V_43 ++ = 0 ;
V_37 = V_43 ;
V_53 = V_43 ;
while ( * V_43 ) {
if ( * V_43 == '\\' ) {
++ V_43 ;
if ( ! * V_43 )
break;
* V_53 ++ = * V_43 ++ ;
} else if ( * V_43 == '\'' || * V_43 == '"' ||
* V_43 == '\n' ) {
++ V_43 ;
} else {
* V_53 ++ = * V_43 ++ ;
}
}
* V_53 = 0 ;
if ( ! strcmp ( V_44 , L_13 ) ) {
V_43 = F_19 ( V_37 ) ;
if ( ! V_43 )
break;
V_49 = V_43 ;
} else if ( ! strcmp ( V_44 , L_14 ) ) {
V_43 = F_19 ( V_37 ) ;
if ( ! V_43 )
break;
V_54 = V_43 ;
}
}
fclose ( V_42 ) ;
return;
}
V_42 = fopen ( L_15 , L_12 ) ;
if ( V_42 != NULL )
goto V_55;
V_42 = fopen ( L_16 , L_12 ) ;
if ( V_42 != NULL )
goto V_55;
return;
V_55:
V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ;
if ( V_43 ) {
V_43 = strchr ( V_44 , '\n' ) ;
if ( V_43 )
* V_43 = '\0' ;
V_43 = F_19 ( V_44 ) ;
if ( ! V_43 )
goto V_56;
V_49 = V_43 ;
V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ;
if ( V_43 ) {
V_43 = strchr ( V_44 , '\n' ) ;
if ( V_43 )
* V_43 = '\0' ;
V_43 = F_19 ( V_44 ) ;
if ( ! V_43 )
goto V_56;
V_54 = V_43 ;
V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ;
if ( V_43 ) {
V_43 = strchr ( V_44 , '\n' ) ;
if ( V_43 )
* V_43 = '\0' ;
V_43 = F_19 ( V_44 ) ;
if ( V_43 )
V_57 = V_43 ;
}
}
}
V_56:
fclose ( V_42 ) ;
return;
}
static char * F_20 ( char * V_58 )
{
T_4 * V_59 ;
struct V_60 * V_61 ;
T_1 * V_42 ;
char * V_43 , * V_53 , * V_62 ;
char * V_63 = NULL ;
char V_44 [ 256 ] ;
char * V_64 = L_17 ;
char V_65 [ 256 ] ;
V_59 = F_21 ( V_64 ) ;
if ( V_59 == NULL )
return NULL ;
snprintf ( V_65 , sizeof( V_65 ) , L_18 , V_64 ) ;
V_53 = V_65 + strlen ( V_64 ) ;
while ( ( V_61 = F_22 ( V_59 ) ) != NULL ) {
* V_53 = '\0' ;
strcat ( V_65 , V_61 -> V_66 ) ;
strcat ( V_65 , L_19 ) ;
V_42 = fopen ( V_65 , L_12 ) ;
if ( V_42 == NULL )
continue;
V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ;
if ( V_43 ) {
V_62 = strchr ( V_43 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
if ( ! strcmp ( V_43 , V_58 ) ) {
V_63 = F_19 ( V_61 -> V_66 ) ;
fclose ( V_42 ) ;
break;
}
}
fclose ( V_42 ) ;
}
F_23 ( V_59 ) ;
return V_63 ;
}
static char * F_24 ( char * V_63 )
{
T_1 * V_42 ;
char * V_43 , * V_62 ;
char V_44 [ 256 ] ;
char V_67 [ 256 ] ;
unsigned int V_26 ;
char * V_68 = NULL ;
snprintf ( V_67 , sizeof( V_67 ) , L_20 , L_17 ,
V_63 , L_21 ) ;
V_42 = fopen ( V_67 , L_12 ) ;
if ( V_42 == NULL )
return NULL ;
V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ;
if ( V_43 ) {
V_62 = strchr ( V_43 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
for ( V_26 = 0 ; V_26 < strlen ( V_43 ) ; V_26 ++ )
V_43 [ V_26 ] = toupper ( V_43 [ V_26 ] ) ;
V_68 = F_19 ( V_43 ) ;
}
fclose ( V_42 ) ;
return V_68 ;
}
static char * F_25 ( char * V_69 )
{
T_4 * V_59 ;
struct V_60 * V_61 ;
T_1 * V_42 ;
char * V_43 , * V_53 , * V_62 ;
char * V_63 = NULL ;
char V_44 [ 256 ] ;
char * V_64 = L_17 ;
char V_65 [ 256 ] ;
unsigned int V_26 ;
V_59 = F_21 ( V_64 ) ;
if ( V_59 == NULL )
return NULL ;
snprintf ( V_65 , sizeof( V_65 ) , L_18 , V_64 ) ;
V_53 = V_65 + strlen ( V_64 ) ;
while ( ( V_61 = F_22 ( V_59 ) ) != NULL ) {
* V_53 = '\0' ;
strcat ( V_65 , V_61 -> V_66 ) ;
strcat ( V_65 , L_21 ) ;
V_42 = fopen ( V_65 , L_12 ) ;
if ( V_42 == NULL )
continue;
V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ;
if ( V_43 ) {
V_62 = strchr ( V_43 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
for ( V_26 = 0 ; V_26 < strlen ( V_43 ) ; V_26 ++ )
V_43 [ V_26 ] = toupper ( V_43 [ V_26 ] ) ;
if ( ! strcmp ( V_43 , V_69 ) ) {
V_63 = F_19 ( V_61 -> V_66 ) ;
fclose ( V_42 ) ;
break;
}
}
fclose ( V_42 ) ;
}
F_23 ( V_59 ) ;
return V_63 ;
}
static void F_26 ( char * V_70 ,
char * V_71 , unsigned int V_72 ,
int V_73 , int V_74 )
{
char V_44 [ 256 ] ;
char * V_43 ;
char * V_62 ;
T_1 * V_42 ;
V_42 = F_27 ( V_70 , L_12 ) ;
if ( V_42 == NULL )
return;
if ( V_74 == 0 )
memset ( V_71 , 0 , V_72 ) ;
while ( ( V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ) != NULL ) {
if ( V_72 < strlen ( V_71 ) + V_73 + 1 )
break;
V_62 = strchr ( V_43 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
strcat ( V_71 , V_43 ) ;
strcat ( V_71 , L_22 ) ;
}
F_28 ( V_42 ) ;
}
static void F_29 ( char * V_63 ,
struct V_75 * V_76 )
{
char V_70 [ 512 ] ;
char V_77 [ 128 ] ;
char * V_43 ;
T_1 * V_42 ;
sprintf ( V_70 , L_23 , L_24 , V_63 ) ;
strcat ( V_70 , L_25 ) ;
F_26 ( V_70 , ( char * ) V_76 -> V_78 ,
( V_79 * 2 ) , V_80 , 0 ) ;
sprintf ( V_70 , L_23 , L_26 , V_63 ) ;
strcat ( V_70 , L_25 ) ;
F_26 ( V_70 , ( char * ) V_76 -> V_78 ,
( V_79 * 2 ) , V_81 , 1 ) ;
sprintf ( V_70 , V_82 L_18 , L_27 ) ;
F_26 ( V_70 , ( char * ) V_76 -> V_83 ,
( V_84 * 2 ) , V_80 , 0 ) ;
sprintf ( V_70 , V_82 L_23 , L_28 , V_63 ) ;
V_42 = F_27 ( V_70 , L_12 ) ;
if ( V_42 == NULL )
return;
V_43 = fgets ( V_77 , sizeof( V_77 ) , V_42 ) ;
if ( V_43 == NULL ) {
F_28 ( V_42 ) ;
return;
}
if ( ! strncmp ( V_43 , L_29 , 7 ) )
V_76 -> V_85 = 1 ;
else
V_76 -> V_85 = 0 ;
F_28 ( V_42 ) ;
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
int V_89 , char * V_76 ,
int V_90 , int * V_74 )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
int V_95 ;
char V_96 [ 50 ] ;
const char * V_97 ;
if ( V_89 == V_98 ) {
V_92 = (struct V_91 * ) V_88 ;
V_97 = F_32 ( V_89 , & V_92 -> V_99 , V_96 , 50 ) ;
V_95 = V_80 ;
} else {
V_94 = (struct V_93 * ) V_88 ;
V_97 = F_32 ( V_89 , & V_94 -> V_100 . V_101 , V_96 , 50 ) ;
V_95 = V_81 ;
}
if ( ( V_90 - * V_74 ) < V_95 + 2 )
return V_102 ;
if ( V_97 == NULL ) {
strcpy ( V_76 , L_30 ) ;
return V_102 ;
}
if ( * V_74 == 0 )
strcpy ( V_76 , V_96 ) ;
else {
strcat ( V_76 , L_22 ) ;
strcat ( V_76 , V_96 ) ;
}
* V_74 += strlen ( V_97 ) + 1 ;
return 0 ;
}
static int
F_33 ( int V_89 , char * V_63 , int V_103 ,
void * V_104 , unsigned int V_90 )
{
struct V_105 * V_106 ;
struct V_105 * V_107 ;
int V_74 = 0 ;
int V_108 = 0 ;
int error = 0 ;
char * V_76 ;
struct V_75 * V_109 ;
char V_110 [ 5 ] ;
int V_111 ;
int V_26 ;
unsigned int * V_86 ;
char * V_112 ;
struct V_93 * V_94 ;
if ( V_103 == V_113 ) {
V_76 = V_104 ;
} else {
V_109 = V_104 ;
V_76 = ( char * ) V_109 -> V_114 ;
V_109 -> V_115 = 0 ;
}
if ( F_34 ( & V_106 ) ) {
strcpy ( V_76 , L_31 ) ;
return V_102 ;
}
V_107 = V_106 ;
while ( V_107 != NULL ) {
if ( V_107 -> V_116 == NULL ) {
V_107 = V_107 -> V_117 ;
continue;
}
if ( ( V_63 != NULL ) &&
( strncmp ( V_107 -> V_118 , V_63 , strlen ( V_63 ) ) ) ) {
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
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
V_111 += F_30 ( & V_86 [ V_26 ] ) ;
sprintf ( V_110 , L_32 , V_111 ) ;
if ( V_90 < V_108 + strlen ( V_110 ) + 1 )
goto V_127;
if ( V_108 == 0 )
strcpy ( V_112 , V_110 ) ;
else {
strcat ( ( char * ) V_109 -> V_126 , L_22 ) ;
strcat ( V_112 , V_110 ) ;
}
V_108 += strlen ( V_112 ) + 1 ;
}
F_29 ( V_63 , V_109 ) ;
}
V_127:
error = F_31 ( V_107 -> V_116 ,
V_107 -> V_116 -> V_119 ,
V_76 ,
V_90 , & V_74 ) ;
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
static int F_39 ( char * V_137 , int * V_74 ,
char * V_138 , int V_139 )
{
char * V_62 ;
char * V_140 ;
V_140 = V_137 + * V_74 ;
V_62 = strchr ( V_140 , ';' ) ;
if ( V_62 )
* V_62 = 0 ;
else
V_62 = V_140 + strlen ( V_140 ) ;
if ( strlen ( V_140 ) != 0 ) {
int V_26 = 0 ;
while ( V_140 [ V_26 ] == ' ' )
V_26 ++ ;
if ( ( V_62 - V_140 ) <= V_139 ) {
strcpy ( V_138 , ( V_140 + V_26 ) ) ;
* V_74 += ( V_62 - V_140 ) + 1 ;
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
char V_92 [ V_81 ] ;
int V_26 = 0 ;
int V_35 = 0 ;
char V_97 [ 256 ] ;
char V_146 [ 10 ] ;
int V_74 = 0 ;
memset ( V_92 , 0 , sizeof( V_92 ) ) ;
while ( F_39 ( V_145 , & V_74 , V_92 ,
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
snprintf ( V_146 , sizeof( V_146 ) , L_41 , ++ V_26 ) ;
} else if ( type == V_148 && V_26 == 0 ) {
++ V_26 ;
} else {
snprintf ( V_146 , sizeof( V_146 ) , L_41 , V_26 ++ ) ;
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
snprintf ( V_146 , sizeof( V_146 ) , L_41 , ++ V_26 ) ;
} else if ( V_35 == 0 ) {
++ V_35 ;
} else {
snprintf ( V_146 , sizeof( V_146 ) , L_45 , V_35 ++ ) ;
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
static int F_42 ( char * V_63 , struct V_75 * V_151 )
{
int error = 0 ;
char V_152 [ 128 ] ;
T_1 * V_42 ;
char V_70 [ 512 ] ;
char * V_68 ;
snprintf ( V_152 , sizeof( V_152 ) , L_20 , V_27 ,
L_46 , V_63 ) ;
V_42 = fopen ( V_152 , L_47 ) ;
if ( V_42 == NULL ) {
F_4 ( V_10 , L_48 ,
V_11 , strerror ( V_11 ) ) ;
return V_102 ;
}
V_68 = F_24 ( V_63 ) ;
if ( V_68 == NULL ) {
error = V_102 ;
goto V_153;
}
error = F_40 ( V_42 , L_49 , L_50 , V_68 ) ;
free ( V_68 ) ;
if ( error )
goto V_153;
error = F_40 ( V_42 , L_51 , L_50 , V_63 ) ;
if ( error )
goto V_153;
if ( V_151 -> V_85 ) {
error = F_40 ( V_42 , L_52 , L_50 , L_53 ) ;
if ( error )
goto V_153;
} else {
error = F_40 ( V_42 , L_52 , L_50 , L_54 ) ;
if ( error )
goto V_153;
}
error = F_41 ( V_42 , ( char * ) V_151 -> V_114 , V_147 ) ;
if ( error )
goto V_153;
error = F_41 ( V_42 , ( char * ) V_151 -> V_126 , V_134 ) ;
if ( error )
goto V_153;
error = F_41 ( V_42 , ( char * ) V_151 -> V_78 , V_148 ) ;
if ( error )
goto V_153;
error = F_41 ( V_42 , ( char * ) V_151 -> V_83 , V_149 ) ;
if ( error )
goto V_153;
fclose ( V_42 ) ;
snprintf ( V_70 , sizeof( V_70 ) , V_82 L_23 ,
L_55 , V_152 ) ;
if ( system ( V_70 ) ) {
F_4 ( V_10 , L_56 ,
V_70 , V_11 , strerror ( V_11 ) ) ;
return V_102 ;
}
return 0 ;
V_153:
F_4 ( V_10 , L_57 ) ;
fclose ( V_42 ) ;
return error ;
}
static void
F_43 ( char * V_76 , int V_90 )
{
struct V_154 V_155 , * V_156 ;
int error = 0 ;
F_44 ( V_76 , V_90 ) ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_157 = V_98 ;
V_155 . V_158 = V_159 ;
V_155 . V_160 = V_161 ;
error = F_45 ( V_76 , NULL , & V_155 , & V_156 ) ;
if ( error != 0 ) {
snprintf ( V_76 , V_90 , L_58 ,
error , F_46 ( error ) ) ;
return;
}
snprintf ( V_76 , V_90 , L_18 , V_156 -> V_162 ) ;
F_47 ( V_156 ) ;
}
void F_48 ( char * V_163 [] )
{
fprintf ( V_164 , L_59
L_60
L_61
L_62 , V_163 [ 0 ] ) ;
}
int main ( int V_165 , char * V_163 [] )
{
int V_166 , V_72 ;
int error ;
struct V_167 V_168 ;
char * V_43 ;
struct V_169 V_170 [ 1 ] ;
char * V_171 ;
char * V_172 ;
int V_103 ;
int V_1 ;
char * V_63 ;
struct V_75 * V_173 ;
int V_174 = 1 , V_175 = 0 , V_176 ;
static struct V_177 V_178 [] = {
{ L_63 , V_179 , 0 , 'h' } ,
{ L_64 , V_179 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_176 = F_49 ( V_165 , V_163 , L_65 , V_178 ,
& V_175 ) ) != - 1 ) {
switch ( V_176 ) {
case 'n' :
V_174 = 0 ;
break;
case 'h' :
default:
F_48 ( V_163 ) ;
exit ( V_12 ) ;
}
}
if ( V_174 && F_50 ( 1 , 0 ) )
return 1 ;
F_51 ( L_66 , 0 , V_180 ) ;
F_4 ( V_181 , L_67 , F_2 () ) ;
V_166 = F_11 ( L_68 , V_30 | V_32 ) ;
if ( V_166 < 0 ) {
F_4 ( V_10 , L_69 ,
V_11 , strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
F_17 () ;
F_43 ( V_182 , sizeof( V_182 ) ) ;
if ( F_8 () ) {
F_4 ( V_10 , L_70 ) ;
exit ( V_12 ) ;
}
V_170 -> V_183 . V_184 = V_185 ;
V_72 = F_52 ( V_166 , V_170 , sizeof( struct V_169 ) ) ;
if ( V_72 != sizeof( struct V_169 ) ) {
F_4 ( V_10 , L_71 ,
V_11 , strerror ( V_11 ) ) ;
F_12 ( V_166 ) ;
exit ( V_12 ) ;
}
V_168 . V_8 = V_166 ;
while ( 1 ) {
V_168 . V_186 = V_187 ;
V_168 . V_188 = 0 ;
if ( F_53 ( & V_168 , 1 , - 1 ) < 0 ) {
F_4 ( V_10 , L_72 , V_11 , strerror ( V_11 ) ) ;
if ( V_11 == V_189 ) {
F_12 ( V_166 ) ;
exit ( V_12 ) ;
}
else
continue;
}
V_72 = F_54 ( V_166 , V_170 , sizeof( struct V_169 ) ) ;
if ( V_72 != sizeof( struct V_169 ) ) {
F_4 ( V_10 , L_73 ,
V_11 , strerror ( V_11 ) ) ;
F_12 ( V_166 ) ;
return V_12 ;
}
V_103 = V_170 -> V_183 . V_184 ;
V_1 = V_170 -> V_183 . V_1 ;
V_170 -> error = V_190 ;
if ( ( V_191 ) && ( V_103 == V_185 ) ) {
V_191 = 0 ;
V_43 = ( char * ) V_170 -> V_192 . V_193 . V_194 ;
V_195 = malloc ( strlen ( V_43 ) + 1 ) ;
if ( V_195 ) {
strcpy ( V_195 , V_43 ) ;
F_4 ( V_181 , L_74 ,
V_195 ) ;
} else {
F_4 ( V_10 , L_8 ) ;
}
continue;
}
switch ( V_103 ) {
case V_123 :
V_173 = & V_170 -> V_192 . V_173 ;
V_63 =
F_25 ( ( char * ) V_173 -> V_196 ) ;
if ( V_63 == NULL ) {
V_170 -> error = V_102 ;
break;
}
error = F_33 (
0 , V_63 , V_123 ,
V_173 ,
( V_84 * 2 ) ) ;
if ( error )
V_170 -> error = error ;
free ( V_63 ) ;
break;
case V_197 :
V_173 = & V_170 -> V_192 . V_173 ;
V_63 = F_20 (
( char * ) V_173 -> V_196 ) ;
if ( V_63 == NULL ) {
V_170 -> error = V_198 ;
break;
}
error = F_42 ( V_63 , V_173 ) ;
if ( error )
V_170 -> error = error ;
free ( V_63 ) ;
break;
case V_199 :
if ( F_14 ( V_1 ,
V_170 -> V_192 . V_200 . V_201 . V_33 ,
V_170 -> V_192 . V_200 . V_201 . V_34 ,
V_170 -> V_192 . V_200 . V_201 . V_37 ,
V_170 -> V_192 . V_200 . V_201 . V_38 ) )
V_170 -> error = V_202 ;
break;
case V_203 :
if ( F_15 ( V_1 ,
V_170 -> V_192 . V_200 . V_201 . V_33 ,
V_170 -> V_192 . V_200 . V_201 . V_34 ,
V_170 -> V_192 . V_200 . V_201 . V_37 ,
V_170 -> V_192 . V_200 . V_201 . V_38 ) )
V_170 -> error = V_202 ;
break;
case V_204 :
if ( F_13 ( V_1 ,
V_170 -> V_192 . V_205 . V_33 ,
V_170 -> V_192 . V_205 . V_34 ) )
V_170 -> error = V_202 ;
break;
default:
break;
}
if ( V_103 != V_113 )
goto V_206;
if ( V_1 != V_207 ) {
if ( F_16 ( V_1 ,
V_170 -> V_192 . V_208 . V_41 ,
V_170 -> V_192 . V_208 . V_201 . V_33 ,
V_39 ,
V_170 -> V_192 . V_208 . V_201 . V_37 ,
V_40 ) )
V_170 -> error = V_202 ;
goto V_206;
}
V_172 = ( char * ) V_170 -> V_192 . V_208 . V_201 . V_33 ;
V_171 = ( char * ) V_170 -> V_192 . V_208 . V_201 . V_37 ;
switch ( V_170 -> V_192 . V_208 . V_41 ) {
case V_209 :
strcpy ( V_171 , V_182 ) ;
strcpy ( V_172 , L_75 ) ;
break;
case V_210 :
strcpy ( V_172 , L_76 ) ;
strcpy ( V_171 , V_195 ) ;
break;
case V_211 :
F_33 ( V_98 , NULL , V_113 ,
V_171 , V_40 ) ;
strcpy ( V_172 , L_77 ) ;
break;
case V_212 :
F_33 ( V_122 , NULL , V_113 ,
V_171 , V_40 ) ;
strcpy ( V_172 , L_78 ) ;
break;
case V_213 :
strcpy ( V_171 , V_48 ) ;
strcpy ( V_172 , L_79 ) ;
break;
case V_214 :
strcpy ( V_171 , V_49 ) ;
strcpy ( V_172 , L_80 ) ;
break;
case V_215 :
strcpy ( V_171 , V_54 ) ;
strcpy ( V_172 , L_81 ) ;
break;
case V_216 :
strcpy ( V_171 , V_57 ) ;
strcpy ( V_172 , L_82 ) ;
break;
case V_217 :
strcpy ( V_171 , V_46 ) ;
strcpy ( V_172 , L_83 ) ;
break;
case V_218 :
strcpy ( V_171 , V_51 ) ;
strcpy ( V_172 , L_84 ) ;
break;
default:
V_170 -> error = V_202 ;
break;
}
V_206:
V_72 = F_52 ( V_166 , V_170 , sizeof( struct V_169 ) ) ;
if ( V_72 != sizeof( struct V_169 ) ) {
F_4 ( V_10 , L_85 , V_11 ,
strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
}
F_12 ( V_166 ) ;
exit ( 0 ) ;
}
