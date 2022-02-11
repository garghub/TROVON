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
snprintf ( V_65 , sizeof( V_65 ) , V_64 ) ;
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
sprintf ( V_70 , L_18 , L_27 ) ;
F_26 ( V_70 , ( char * ) V_76 -> V_82 ,
( V_83 * 2 ) , V_80 , 0 ) ;
sprintf ( V_70 , L_23 , L_28 , V_63 ) ;
V_42 = F_27 ( V_70 , L_12 ) ;
if ( V_42 == NULL )
return;
V_43 = fgets ( V_77 , sizeof( V_77 ) , V_42 ) ;
if ( V_43 == NULL ) {
F_28 ( V_42 ) ;
return;
}
if ( ! strncmp ( V_43 , L_29 , 7 ) )
V_76 -> V_84 = 1 ;
else
V_76 -> V_84 = 0 ;
F_28 ( V_42 ) ;
}
static unsigned int F_30 ( unsigned int * V_85 )
{
unsigned int V_86 = * V_85 - ( ( * V_85 >> 1 ) & 0x55555555 ) ;
V_86 = ( V_86 & 0x33333333 ) + ( ( V_86 >> 2 ) & 0x33333333 ) ;
V_86 = ( V_86 + ( V_86 >> 4 ) ) & 0x0F0F0F0F ;
V_86 = V_86 + ( V_86 >> 8 ) ;
return ( V_86 + ( V_86 >> 16 ) ) & 0x000000FF ;
}
static int F_31 ( void * V_87 ,
int V_88 , char * V_76 ,
int V_89 , int * V_74 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
int V_94 ;
char V_95 [ 50 ] ;
const char * V_96 ;
if ( V_88 == V_97 ) {
V_91 = (struct V_90 * ) V_87 ;
V_96 = F_32 ( V_88 , & V_91 -> V_98 , V_95 , 50 ) ;
V_94 = V_80 ;
} else {
V_93 = (struct V_92 * ) V_87 ;
V_96 = F_32 ( V_88 , & V_93 -> V_99 . V_100 , V_95 , 50 ) ;
V_94 = V_81 ;
}
if ( ( V_89 - * V_74 ) < V_94 + 2 )
return V_101 ;
if ( V_96 == NULL ) {
strcpy ( V_76 , L_30 ) ;
return V_101 ;
}
if ( * V_74 == 0 )
strcpy ( V_76 , V_95 ) ;
else {
strcat ( V_76 , L_22 ) ;
strcat ( V_76 , V_95 ) ;
}
* V_74 += strlen ( V_96 ) + 1 ;
return 0 ;
}
static int
F_33 ( int V_88 , char * V_63 , int V_102 ,
void * V_103 , unsigned int V_89 )
{
struct V_104 * V_105 ;
struct V_104 * V_106 ;
int V_74 = 0 ;
int V_107 = 0 ;
int error = 0 ;
char * V_76 ;
struct V_75 * V_108 ;
char V_109 [ 5 ] ;
int V_110 ;
int V_26 ;
unsigned int * V_85 ;
char * V_111 ;
struct V_92 * V_93 ;
if ( V_102 == V_112 ) {
V_76 = V_103 ;
} else {
V_108 = V_103 ;
V_76 = ( char * ) V_108 -> V_113 ;
V_108 -> V_114 = 0 ;
}
if ( F_34 ( & V_105 ) ) {
strcpy ( V_76 , L_31 ) ;
return V_101 ;
}
V_106 = V_105 ;
while ( V_106 != NULL ) {
if ( V_106 -> V_115 == NULL ) {
V_106 = V_106 -> V_116 ;
continue;
}
if ( ( V_63 != NULL ) &&
( strncmp ( V_106 -> V_117 , V_63 , strlen ( V_63 ) ) ) ) {
V_106 = V_106 -> V_116 ;
continue;
}
if ( ( ( ( V_88 != 0 ) &&
( V_106 -> V_115 -> V_118 != V_88 ) ) ) ||
( V_106 -> V_119 & V_120 ) ) {
V_106 = V_106 -> V_116 ;
continue;
}
if ( ( V_106 -> V_115 -> V_118 != V_97 ) &&
( V_106 -> V_115 -> V_118 != V_121 ) ) {
V_106 = V_106 -> V_116 ;
continue;
}
if ( V_102 == V_122 ) {
if ( V_106 -> V_115 -> V_118 == V_97 ) {
V_108 -> V_114 |= V_123 ;
error = F_31 (
V_106 -> V_124 ,
V_97 ,
( char * )
V_108 -> V_125 ,
V_89 ,
& V_107 ) ;
if ( error )
goto V_126;
} else {
V_108 -> V_114 |= V_127 ;
V_110 = 0 ;
V_111 = ( char * ) V_108 -> V_125 ;
V_93 = (struct V_92 * )
V_106 -> V_124 ;
V_85 = V_93 -> V_99 . V_128 ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
V_110 += F_30 ( & V_85 [ V_26 ] ) ;
sprintf ( V_109 , L_32 , V_110 ) ;
if ( V_89 < V_107 + strlen ( V_109 ) + 1 )
goto V_126;
if ( V_107 == 0 )
strcpy ( V_111 , V_109 ) ;
else {
strcat ( ( char * ) V_108 -> V_125 , L_22 ) ;
strcat ( V_111 , V_109 ) ;
}
V_107 += strlen ( V_111 ) + 1 ;
}
F_29 ( V_63 , V_108 ) ;
}
V_126:
error = F_31 ( V_106 -> V_115 ,
V_106 -> V_115 -> V_118 ,
V_76 ,
V_89 , & V_74 ) ;
if ( error )
goto V_129;
V_106 = V_106 -> V_116 ;
}
V_129:
F_35 ( V_105 ) ;
return error ;
}
static int F_36 ( char * V_91 , int type )
{
int V_130 ;
struct V_131 V_132 ;
V_130 = F_37 ( V_121 , V_91 , & V_132 ) ;
if ( V_130 != 1 ) {
if ( type == V_133 )
return 1 ;
return 0 ;
}
sprintf ( V_91 , L_33
L_34 ,
( int ) V_132 . V_100 [ 0 ] , ( int ) V_132 . V_100 [ 1 ] ,
( int ) V_132 . V_100 [ 2 ] , ( int ) V_132 . V_100 [ 3 ] ,
( int ) V_132 . V_100 [ 4 ] , ( int ) V_132 . V_100 [ 5 ] ,
( int ) V_132 . V_100 [ 6 ] , ( int ) V_132 . V_100 [ 7 ] ,
( int ) V_132 . V_100 [ 8 ] , ( int ) V_132 . V_100 [ 9 ] ,
( int ) V_132 . V_100 [ 10 ] , ( int ) V_132 . V_100 [ 11 ] ,
( int ) V_132 . V_100 [ 12 ] , ( int ) V_132 . V_100 [ 13 ] ,
( int ) V_132 . V_100 [ 14 ] , ( int ) V_132 . V_100 [ 15 ] ) ;
return 1 ;
}
static int F_38 ( char * V_91 )
{
int V_130 ;
struct V_134 V_135 ;
V_130 = F_37 ( V_97 , V_91 , & V_135 ) ;
if ( V_130 == 1 )
return 1 ;
return 0 ;
}
static int F_39 ( char * V_136 , int * V_74 ,
char * V_137 , int V_138 )
{
char * V_62 ;
char * V_139 ;
V_139 = V_136 + * V_74 ;
V_62 = strchr ( V_139 , ';' ) ;
if ( V_62 )
* V_62 = 0 ;
else
V_62 = V_139 + strlen ( V_139 ) ;
if ( strlen ( V_139 ) != 0 ) {
int V_26 = 0 ;
while ( V_139 [ V_26 ] == ' ' )
V_26 ++ ;
if ( ( V_62 - V_139 ) <= V_138 ) {
strcpy ( V_137 , ( V_139 + V_26 ) ) ;
* V_74 += ( V_62 - V_139 ) + 1 ;
return 1 ;
}
}
return 0 ;
}
static int F_40 ( T_1 * V_140 , char * V_141 , char * V_142 , char * V_143 )
{
int V_130 ;
V_130 = fprintf ( V_140 , L_35 , V_141 , V_142 , L_36 , V_143 ) ;
if ( V_130 < 0 )
return V_101 ;
return 0 ;
}
static int F_41 ( T_1 * V_140 , char * V_144 , int type )
{
int error = 0 ;
char V_91 [ V_81 ] ;
int V_26 = 0 ;
int V_35 = 0 ;
char V_96 [ 256 ] ;
char V_145 [ 10 ] ;
int V_74 = 0 ;
memset ( V_91 , 0 , sizeof( V_91 ) ) ;
while ( F_39 ( V_144 , & V_74 , V_91 ,
( V_83 * 2 ) ) ) {
V_145 [ 0 ] = 0 ;
if ( F_38 ( V_91 ) ) {
switch ( type ) {
case V_146 :
snprintf ( V_96 , sizeof( V_96 ) , L_18 , L_37 ) ;
break;
case V_133 :
snprintf ( V_96 , sizeof( V_96 ) , L_18 , L_38 ) ;
break;
case V_147 :
snprintf ( V_96 , sizeof( V_96 ) , L_18 , L_39 ) ;
break;
case V_148 :
snprintf ( V_96 , sizeof( V_96 ) , L_18 , L_40 ) ;
break;
}
if ( type == V_148 ) {
snprintf ( V_145 , sizeof( V_145 ) , L_41 , ++ V_26 ) ;
} else if ( type == V_147 && V_26 == 0 ) {
++ V_26 ;
} else {
snprintf ( V_145 , sizeof( V_145 ) , L_41 , V_26 ++ ) ;
}
} else if ( F_36 ( V_91 , type ) ) {
switch ( type ) {
case V_146 :
snprintf ( V_96 , sizeof( V_96 ) , L_18 , L_42 ) ;
break;
case V_133 :
snprintf ( V_96 , sizeof( V_96 ) , L_18 , L_43 ) ;
break;
case V_147 :
snprintf ( V_96 , sizeof( V_96 ) , L_18 ,
L_44 ) ;
break;
case V_148 :
snprintf ( V_96 , sizeof( V_96 ) , L_18 , L_40 ) ;
break;
}
if ( type == V_148 ) {
snprintf ( V_145 , sizeof( V_145 ) , L_41 , ++ V_26 ) ;
} else if ( V_35 == 0 ) {
++ V_35 ;
} else {
snprintf ( V_145 , sizeof( V_145 ) , L_45 , V_35 ++ ) ;
}
} else {
return V_149 ;
}
error = F_40 ( V_140 , V_96 , V_145 , V_91 ) ;
if ( error )
return error ;
memset ( V_91 , 0 , sizeof( V_91 ) ) ;
}
return 0 ;
}
static int F_42 ( char * V_63 , struct V_75 * V_150 )
{
int error = 0 ;
char V_151 [ 128 ] ;
T_1 * V_42 ;
char V_70 [ 512 ] ;
char * V_68 ;
snprintf ( V_151 , sizeof( V_151 ) , L_20 , V_27 ,
L_46 , V_63 ) ;
V_42 = fopen ( V_151 , L_47 ) ;
if ( V_42 == NULL ) {
F_4 ( V_10 , L_48 ,
V_11 , strerror ( V_11 ) ) ;
return V_101 ;
}
V_68 = F_24 ( V_63 ) ;
if ( V_68 == NULL ) {
error = V_101 ;
goto V_152;
}
error = F_40 ( V_42 , L_49 , L_50 , V_68 ) ;
free ( V_68 ) ;
if ( error )
goto V_152;
error = F_40 ( V_42 , L_51 , L_50 , V_63 ) ;
if ( error )
goto V_152;
if ( V_150 -> V_84 ) {
error = F_40 ( V_42 , L_52 , L_50 , L_53 ) ;
if ( error )
goto V_152;
} else {
error = F_40 ( V_42 , L_52 , L_50 , L_54 ) ;
if ( error )
goto V_152;
}
error = F_41 ( V_42 , ( char * ) V_150 -> V_113 , V_146 ) ;
if ( error )
goto V_152;
error = F_41 ( V_42 , ( char * ) V_150 -> V_125 , V_133 ) ;
if ( error )
goto V_152;
error = F_41 ( V_42 , ( char * ) V_150 -> V_78 , V_147 ) ;
if ( error )
goto V_152;
error = F_41 ( V_42 , ( char * ) V_150 -> V_82 , V_148 ) ;
if ( error )
goto V_152;
fclose ( V_42 ) ;
snprintf ( V_70 , sizeof( V_70 ) , L_23 , L_55 , V_151 ) ;
if ( system ( V_70 ) ) {
F_4 ( V_10 , L_56 ,
V_70 , V_11 , strerror ( V_11 ) ) ;
return V_101 ;
}
return 0 ;
V_152:
F_4 ( V_10 , L_57 ) ;
fclose ( V_42 ) ;
return error ;
}
static void
F_43 ( char * V_76 , int V_89 )
{
struct V_153 V_154 , * V_155 ;
int error = 0 ;
F_44 ( V_76 , V_89 ) ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_156 = V_97 ;
V_154 . V_157 = V_158 ;
V_154 . V_159 = V_160 ;
error = F_45 ( V_76 , NULL , & V_154 , & V_155 ) ;
if ( error != 0 ) {
snprintf ( V_76 , V_89 , L_58 ,
error , F_46 ( error ) ) ;
return;
}
snprintf ( V_76 , V_89 , L_18 , V_155 -> V_161 ) ;
F_47 ( V_155 ) ;
}
static int
F_48 ( int V_8 , struct V_162 * V_163 )
{
struct V_164 V_165 = { . V_166 = V_167 } ;
unsigned int V_168 ;
struct V_169 V_170 ;
struct V_171 V_172 [ 2 ] ;
V_168 = sizeof( struct V_162 ) + V_163 -> V_72 ;
V_165 . V_173 = F_2 () ;
V_165 . V_174 = F_49 ( V_168 ) ;
V_172 [ 0 ] . V_175 = & V_165 ;
V_172 [ 0 ] . V_176 = sizeof( V_165 ) ;
V_172 [ 1 ] . V_175 = V_163 ;
V_172 [ 1 ] . V_176 = V_168 ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_177 = & V_91 ;
V_170 . V_178 = sizeof( V_91 ) ;
V_170 . V_179 = V_172 ;
V_170 . V_180 = 2 ;
return F_50 ( V_8 , & V_170 , 0 ) ;
}
void F_51 ( char * V_181 [] )
{
fprintf ( V_182 , L_59
L_60
L_61
L_62 , V_181 [ 0 ] ) ;
}
int main ( int V_183 , char * V_181 [] )
{
int V_8 , V_72 , V_184 ;
int error ;
struct V_162 * V_170 ;
struct V_185 V_186 ;
struct V_164 * V_187 ;
struct V_162 * V_188 ;
struct V_189 * V_190 ;
char * V_43 ;
char * V_191 ;
char * V_192 ;
int V_102 ;
int V_1 ;
char * V_63 ;
struct V_75 * V_193 ;
char * V_194 ;
T_2 V_195 ;
int V_196 = 1 , V_197 = 0 , V_198 ;
static struct V_199 V_200 [] = {
{ L_63 , V_201 , 0 , 'h' } ,
{ L_64 , V_201 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_198 = F_52 ( V_183 , V_181 , L_65 , V_200 ,
& V_197 ) ) != - 1 ) {
switch ( V_198 ) {
case 'n' :
V_196 = 0 ;
break;
case 'h' :
default:
F_51 ( V_181 ) ;
exit ( V_12 ) ;
}
}
if ( V_196 && F_53 ( 1 , 0 ) )
return 1 ;
F_54 ( L_66 , 0 , V_202 ) ;
F_4 ( V_203 , L_67 , F_2 () ) ;
V_195 = F_49 ( 0 ) + sizeof( struct V_162 ) + sizeof( struct V_189 ) ;
V_194 = calloc ( 1 , V_195 ) ;
if ( ! V_194 ) {
F_4 ( V_10 , L_68 ) ;
exit ( V_12 ) ;
}
F_17 () ;
F_43 ( V_204 , sizeof( V_204 ) ) ;
if ( F_8 () ) {
F_4 ( V_10 , L_69 ) ;
exit ( V_12 ) ;
}
V_8 = F_55 ( V_205 , V_206 , V_207 ) ;
if ( V_8 < 0 ) {
F_4 ( V_10 , L_70 , V_11 ,
strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
V_91 . V_208 = V_205 ;
V_91 . V_209 = 0 ;
V_91 . V_210 = 0 ;
V_91 . V_211 = 0 ;
error = F_56 ( V_8 , (struct V_212 * ) & V_91 , sizeof( V_91 ) ) ;
if ( error < 0 ) {
F_4 ( V_10 , L_71 , V_11 , strerror ( V_11 ) ) ;
F_12 ( V_8 ) ;
exit ( V_12 ) ;
}
V_184 = V_213 ;
if ( F_57 ( V_8 , V_214 , V_215 , & V_184 , sizeof( V_184 ) ) < 0 ) {
F_4 ( V_10 , L_72 , V_11 , strerror ( V_11 ) ) ;
F_12 ( V_8 ) ;
exit ( V_12 ) ;
}
V_170 = (struct V_162 * ) V_194 ;
V_170 -> V_216 . V_217 = V_213 ;
V_170 -> V_216 . V_218 = V_219 ;
V_190 = (struct V_189 * ) V_170 -> V_220 ;
V_190 -> V_221 . V_222 = V_223 ;
V_170 -> V_224 = 0 ;
V_170 -> V_72 = sizeof( struct V_189 ) ;
V_72 = F_48 ( V_8 , V_170 ) ;
if ( V_72 < 0 ) {
F_4 ( V_10 , L_73 , V_11 , strerror ( V_11 ) ) ;
F_12 ( V_8 ) ;
exit ( V_12 ) ;
}
V_186 . V_8 = V_8 ;
while ( 1 ) {
struct V_212 * V_225 = (struct V_212 * ) & V_91 ;
T_5 V_226 = sizeof( V_91 ) ;
V_186 . V_227 = V_228 ;
V_186 . V_229 = 0 ;
if ( F_58 ( & V_186 , 1 , - 1 ) < 0 ) {
F_4 ( V_10 , L_74 , V_11 , strerror ( V_11 ) ) ;
if ( V_11 == V_230 ) {
F_12 ( V_8 ) ;
exit ( V_12 ) ;
}
else
continue;
}
V_72 = F_59 ( V_8 , V_194 , V_195 , 0 ,
V_225 , & V_226 ) ;
if ( V_72 < 0 ) {
int V_231 = V_11 ;
F_4 ( V_10 , L_75 ,
V_91 . V_210 , V_11 , strerror ( V_11 ) ) ;
if ( V_231 == V_232 ) {
F_4 ( V_10 , L_76 ) ;
continue;
}
F_12 ( V_8 ) ;
return - 1 ;
}
if ( V_91 . V_210 ) {
F_4 ( V_233 , L_77 ,
V_91 . V_210 ) ;
continue;
}
V_187 = (struct V_164 * ) V_194 ;
if ( V_187 -> V_166 != V_167 )
continue;
V_188 = (struct V_162 * ) F_60 ( V_187 ) ;
V_190 = (struct V_189 * ) V_188 -> V_220 ;
V_102 = V_190 -> V_221 . V_222 ;
V_1 = V_190 -> V_221 . V_1 ;
V_190 -> error = V_234 ;
if ( ( V_235 ) && ( V_102 == V_223 ) ) {
V_235 = 0 ;
V_43 = ( char * ) V_190 -> V_236 . V_237 . V_238 ;
V_239 = malloc ( strlen ( V_43 ) + 1 ) ;
if ( V_239 ) {
strcpy ( V_239 , V_43 ) ;
F_4 ( V_203 , L_78 ,
V_239 ) ;
} else {
F_4 ( V_10 , L_8 ) ;
}
continue;
}
switch ( V_102 ) {
case V_122 :
V_193 = & V_190 -> V_236 . V_193 ;
V_63 =
F_25 ( ( char * ) V_193 -> V_240 ) ;
if ( V_63 == NULL ) {
V_190 -> error = V_101 ;
break;
}
error = F_33 (
0 , V_63 , V_122 ,
V_193 ,
( V_83 * 2 ) ) ;
if ( error )
V_190 -> error = error ;
free ( V_63 ) ;
break;
case V_241 :
V_193 = & V_190 -> V_236 . V_193 ;
V_63 = F_20 (
( char * ) V_193 -> V_240 ) ;
if ( V_63 == NULL ) {
V_190 -> error = V_242 ;
break;
}
error = F_42 ( V_63 , V_193 ) ;
if ( error )
V_190 -> error = error ;
free ( V_63 ) ;
break;
case V_243 :
if ( F_14 ( V_1 ,
V_190 -> V_236 . V_244 . V_220 . V_33 ,
V_190 -> V_236 . V_244 . V_220 . V_34 ,
V_190 -> V_236 . V_244 . V_220 . V_37 ,
V_190 -> V_236 . V_244 . V_220 . V_38 ) )
V_190 -> error = V_245 ;
break;
case V_246 :
if ( F_15 ( V_1 ,
V_190 -> V_236 . V_244 . V_220 . V_33 ,
V_190 -> V_236 . V_244 . V_220 . V_34 ,
V_190 -> V_236 . V_244 . V_220 . V_37 ,
V_190 -> V_236 . V_244 . V_220 . V_38 ) )
V_190 -> error = V_245 ;
break;
case V_247 :
if ( F_13 ( V_1 ,
V_190 -> V_236 . V_248 . V_33 ,
V_190 -> V_236 . V_248 . V_34 ) )
V_190 -> error = V_245 ;
break;
default:
break;
}
if ( V_102 != V_112 )
goto V_249;
if ( V_1 != V_250 ) {
if ( F_16 ( V_1 ,
V_190 -> V_236 . V_251 . V_41 ,
V_190 -> V_236 . V_251 . V_220 . V_33 ,
V_39 ,
V_190 -> V_236 . V_251 . V_220 . V_37 ,
V_40 ) )
V_190 -> error = V_245 ;
goto V_249;
}
V_190 = (struct V_189 * ) V_188 -> V_220 ;
V_192 = ( char * ) V_190 -> V_236 . V_251 . V_220 . V_33 ;
V_191 = ( char * ) V_190 -> V_236 . V_251 . V_220 . V_37 ;
switch ( V_190 -> V_236 . V_251 . V_41 ) {
case V_252 :
strcpy ( V_191 , V_204 ) ;
strcpy ( V_192 , L_79 ) ;
break;
case V_253 :
strcpy ( V_192 , L_80 ) ;
strcpy ( V_191 , V_239 ) ;
break;
case V_254 :
F_33 ( V_97 , NULL , V_112 ,
V_191 , V_40 ) ;
strcpy ( V_192 , L_81 ) ;
break;
case V_255 :
F_33 ( V_121 , NULL , V_112 ,
V_191 , V_40 ) ;
strcpy ( V_192 , L_82 ) ;
break;
case V_256 :
strcpy ( V_191 , V_48 ) ;
strcpy ( V_192 , L_83 ) ;
break;
case V_257 :
strcpy ( V_191 , V_49 ) ;
strcpy ( V_192 , L_84 ) ;
break;
case V_258 :
strcpy ( V_191 , V_54 ) ;
strcpy ( V_192 , L_85 ) ;
break;
case V_259 :
strcpy ( V_191 , V_57 ) ;
strcpy ( V_192 , L_86 ) ;
break;
case V_260 :
strcpy ( V_191 , V_46 ) ;
strcpy ( V_192 , L_87 ) ;
break;
case V_261 :
strcpy ( V_191 , V_51 ) ;
strcpy ( V_192 , L_88 ) ;
break;
default:
V_190 -> error = V_245 ;
break;
}
V_249:
V_188 -> V_216 . V_217 = V_213 ;
V_188 -> V_216 . V_218 = V_219 ;
V_188 -> V_224 = 0 ;
V_188 -> V_72 = sizeof( struct V_189 ) ;
V_72 = F_48 ( V_8 , V_188 ) ;
if ( V_72 < 0 ) {
int V_231 = V_11 ;
F_4 ( V_10 , L_89 , V_11 ,
strerror ( V_11 ) ) ;
if ( V_231 == V_262 || V_231 == V_232 ) {
F_4 ( V_10 , L_90 ) ;
continue;
}
exit ( V_12 ) ;
}
}
}
