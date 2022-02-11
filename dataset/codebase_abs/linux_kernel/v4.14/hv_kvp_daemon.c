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
char * V_43 , * V_62 ;
char * V_63 = NULL ;
char V_44 [ 256 ] ;
char V_64 [ V_65 ] ;
V_59 = F_21 ( V_66 ) ;
if ( V_59 == NULL )
return NULL ;
while ( ( V_61 = F_22 ( V_59 ) ) != NULL ) {
snprintf ( V_64 , sizeof( V_64 ) , L_17 ,
V_66 , V_61 -> V_67 ) ;
V_42 = fopen ( V_64 , L_12 ) ;
if ( V_42 == NULL )
continue;
V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ;
if ( V_43 ) {
V_62 = strchr ( V_43 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
if ( ! strcmp ( V_43 , V_58 ) ) {
V_63 = F_19 ( V_61 -> V_67 ) ;
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
char V_68 [ V_65 ] ;
unsigned int V_26 ;
char * V_69 = NULL ;
snprintf ( V_68 , sizeof( V_68 ) , L_18 , V_66 ,
V_63 , L_19 ) ;
V_42 = fopen ( V_68 , L_12 ) ;
if ( V_42 == NULL )
return NULL ;
V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ;
if ( V_43 ) {
V_62 = strchr ( V_43 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
for ( V_26 = 0 ; V_26 < strlen ( V_43 ) ; V_26 ++ )
V_43 [ V_26 ] = toupper ( V_43 [ V_26 ] ) ;
V_69 = F_19 ( V_43 ) ;
}
fclose ( V_42 ) ;
return V_69 ;
}
static char * F_25 ( char * V_70 )
{
T_4 * V_59 ;
struct V_60 * V_61 ;
T_1 * V_42 ;
char * V_43 , * V_62 ;
char * V_63 = NULL ;
char V_44 [ 256 ] ;
char V_64 [ V_65 ] ;
unsigned int V_26 ;
V_59 = F_21 ( V_66 ) ;
if ( V_59 == NULL )
return NULL ;
while ( ( V_61 = F_22 ( V_59 ) ) != NULL ) {
snprintf ( V_64 , sizeof( V_64 ) , L_20 , V_66 ,
V_61 -> V_67 ) ;
V_42 = fopen ( V_64 , L_12 ) ;
if ( V_42 == NULL )
continue;
V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ;
if ( V_43 ) {
V_62 = strchr ( V_43 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
for ( V_26 = 0 ; V_26 < strlen ( V_43 ) ; V_26 ++ )
V_43 [ V_26 ] = toupper ( V_43 [ V_26 ] ) ;
if ( ! strcmp ( V_43 , V_70 ) ) {
V_63 = F_19 ( V_61 -> V_67 ) ;
fclose ( V_42 ) ;
break;
}
}
fclose ( V_42 ) ;
}
F_23 ( V_59 ) ;
return V_63 ;
}
static void F_26 ( char * V_71 ,
char * V_72 , unsigned int V_73 ,
int V_74 , int V_75 )
{
char V_44 [ 256 ] ;
char * V_43 ;
char * V_62 ;
T_1 * V_42 ;
V_42 = F_27 ( V_71 , L_12 ) ;
if ( V_42 == NULL )
return;
if ( V_75 == 0 )
memset ( V_72 , 0 , V_73 ) ;
while ( ( V_43 = fgets ( V_44 , sizeof( V_44 ) , V_42 ) ) != NULL ) {
if ( V_73 < strlen ( V_72 ) + V_74 + 1 )
break;
V_62 = strchr ( V_43 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
strcat ( V_72 , V_43 ) ;
strcat ( V_72 , L_21 ) ;
}
F_28 ( V_42 ) ;
}
static void F_29 ( char * V_63 ,
struct V_76 * V_77 )
{
char V_71 [ 512 ] ;
char V_78 [ 128 ] ;
char * V_43 ;
T_1 * V_42 ;
sprintf ( V_71 , L_22 , L_23 , V_63 ) ;
strcat ( V_71 , L_24 ) ;
F_26 ( V_71 , ( char * ) V_77 -> V_79 ,
( V_80 * 2 ) , V_81 , 0 ) ;
sprintf ( V_71 , L_22 , L_25 , V_63 ) ;
strcat ( V_71 , L_24 ) ;
F_26 ( V_71 , ( char * ) V_77 -> V_79 ,
( V_80 * 2 ) , V_82 , 1 ) ;
sprintf ( V_71 , V_83 L_26 , L_27 ) ;
F_26 ( V_71 , ( char * ) V_77 -> V_84 ,
( V_85 * 2 ) , V_81 , 0 ) ;
sprintf ( V_71 , V_83 L_22 , L_28 , V_63 ) ;
V_42 = F_27 ( V_71 , L_12 ) ;
if ( V_42 == NULL )
return;
V_43 = fgets ( V_78 , sizeof( V_78 ) , V_42 ) ;
if ( V_43 == NULL ) {
F_28 ( V_42 ) ;
return;
}
if ( ! strncmp ( V_43 , L_29 , 7 ) )
V_77 -> V_86 = 1 ;
else
V_77 -> V_86 = 0 ;
F_28 ( V_42 ) ;
}
static unsigned int F_30 ( unsigned int * V_87 )
{
unsigned int V_88 = * V_87 - ( ( * V_87 >> 1 ) & 0x55555555 ) ;
V_88 = ( V_88 & 0x33333333 ) + ( ( V_88 >> 2 ) & 0x33333333 ) ;
V_88 = ( V_88 + ( V_88 >> 4 ) ) & 0x0F0F0F0F ;
V_88 = V_88 + ( V_88 >> 8 ) ;
return ( V_88 + ( V_88 >> 16 ) ) & 0x000000FF ;
}
static int F_31 ( void * V_89 ,
int V_90 , char * V_77 ,
int V_91 , int * V_75 )
{
struct V_92 * V_93 ;
struct V_94 * V_95 ;
int V_96 ;
char V_97 [ 50 ] ;
const char * V_98 ;
if ( V_90 == V_99 ) {
V_93 = (struct V_92 * ) V_89 ;
V_98 = F_32 ( V_90 , & V_93 -> V_100 , V_97 , 50 ) ;
V_96 = V_81 ;
} else {
V_95 = (struct V_94 * ) V_89 ;
V_98 = F_32 ( V_90 , & V_95 -> V_101 . V_102 , V_97 , 50 ) ;
V_96 = V_82 ;
}
if ( ( V_91 - * V_75 ) < V_96 + 2 )
return V_103 ;
if ( V_98 == NULL ) {
strcpy ( V_77 , L_30 ) ;
return V_103 ;
}
if ( * V_75 == 0 )
strcpy ( V_77 , V_97 ) ;
else {
strcat ( V_77 , L_21 ) ;
strcat ( V_77 , V_97 ) ;
}
* V_75 += strlen ( V_98 ) + 1 ;
return 0 ;
}
static int
F_33 ( int V_90 , char * V_63 , int V_104 ,
void * V_105 , unsigned int V_91 )
{
struct V_106 * V_107 ;
struct V_106 * V_108 ;
int V_75 = 0 ;
int V_109 = 0 ;
int error = 0 ;
char * V_77 ;
struct V_76 * V_110 ;
char V_111 [ 5 ] ;
int V_112 ;
int V_26 ;
unsigned int * V_87 ;
char * V_113 ;
struct V_94 * V_95 ;
if ( V_104 == V_114 ) {
V_77 = V_105 ;
} else {
V_110 = V_105 ;
V_77 = ( char * ) V_110 -> V_115 ;
V_110 -> V_116 = 0 ;
}
if ( F_34 ( & V_107 ) ) {
strcpy ( V_77 , L_31 ) ;
return V_103 ;
}
V_108 = V_107 ;
while ( V_108 != NULL ) {
if ( V_108 -> V_117 == NULL ) {
V_108 = V_108 -> V_118 ;
continue;
}
if ( ( V_63 != NULL ) &&
( strncmp ( V_108 -> V_119 , V_63 , strlen ( V_63 ) ) ) ) {
V_108 = V_108 -> V_118 ;
continue;
}
if ( ( ( ( V_90 != 0 ) &&
( V_108 -> V_117 -> V_120 != V_90 ) ) ) ||
( V_108 -> V_121 & V_122 ) ) {
V_108 = V_108 -> V_118 ;
continue;
}
if ( ( V_108 -> V_117 -> V_120 != V_99 ) &&
( V_108 -> V_117 -> V_120 != V_123 ) ) {
V_108 = V_108 -> V_118 ;
continue;
}
if ( V_104 == V_124 ) {
if ( V_108 -> V_117 -> V_120 == V_99 ) {
V_110 -> V_116 |= V_125 ;
error = F_31 (
V_108 -> V_126 ,
V_99 ,
( char * )
V_110 -> V_127 ,
V_91 ,
& V_109 ) ;
if ( error )
goto V_128;
} else {
V_110 -> V_116 |= V_129 ;
V_112 = 0 ;
V_113 = ( char * ) V_110 -> V_127 ;
V_95 = (struct V_94 * )
V_108 -> V_126 ;
V_87 = V_95 -> V_101 . V_130 ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
V_112 += F_30 ( & V_87 [ V_26 ] ) ;
sprintf ( V_111 , L_32 , V_112 ) ;
if ( V_91 < V_109 + strlen ( V_111 ) + 1 )
goto V_128;
if ( V_109 == 0 )
strcpy ( V_113 , V_111 ) ;
else {
strcat ( ( char * ) V_110 -> V_127 , L_21 ) ;
strcat ( V_113 , V_111 ) ;
}
V_109 += strlen ( V_113 ) + 1 ;
}
F_29 ( V_63 , V_110 ) ;
}
V_128:
error = F_31 ( V_108 -> V_117 ,
V_108 -> V_117 -> V_120 ,
V_77 ,
V_91 , & V_75 ) ;
if ( error )
goto V_131;
V_108 = V_108 -> V_118 ;
}
V_131:
F_35 ( V_107 ) ;
return error ;
}
static int F_36 ( char * V_93 , int type )
{
int V_132 ;
struct V_133 V_134 ;
V_132 = F_37 ( V_123 , V_93 , & V_134 ) ;
if ( V_132 != 1 ) {
if ( type == V_135 )
return 1 ;
return 0 ;
}
sprintf ( V_93 , L_33
L_34 ,
( int ) V_134 . V_102 [ 0 ] , ( int ) V_134 . V_102 [ 1 ] ,
( int ) V_134 . V_102 [ 2 ] , ( int ) V_134 . V_102 [ 3 ] ,
( int ) V_134 . V_102 [ 4 ] , ( int ) V_134 . V_102 [ 5 ] ,
( int ) V_134 . V_102 [ 6 ] , ( int ) V_134 . V_102 [ 7 ] ,
( int ) V_134 . V_102 [ 8 ] , ( int ) V_134 . V_102 [ 9 ] ,
( int ) V_134 . V_102 [ 10 ] , ( int ) V_134 . V_102 [ 11 ] ,
( int ) V_134 . V_102 [ 12 ] , ( int ) V_134 . V_102 [ 13 ] ,
( int ) V_134 . V_102 [ 14 ] , ( int ) V_134 . V_102 [ 15 ] ) ;
return 1 ;
}
static int F_38 ( char * V_93 )
{
int V_132 ;
struct V_136 V_137 ;
V_132 = F_37 ( V_99 , V_93 , & V_137 ) ;
if ( V_132 == 1 )
return 1 ;
return 0 ;
}
static int F_39 ( char * V_138 , int * V_75 ,
char * V_139 , int V_140 )
{
char * V_62 ;
char * V_141 ;
V_141 = V_138 + * V_75 ;
V_62 = strchr ( V_141 , ';' ) ;
if ( V_62 )
* V_62 = 0 ;
else
V_62 = V_141 + strlen ( V_141 ) ;
if ( strlen ( V_141 ) != 0 ) {
int V_26 = 0 ;
while ( V_141 [ V_26 ] == ' ' )
V_26 ++ ;
if ( ( V_62 - V_141 ) <= V_140 ) {
strcpy ( V_139 , ( V_141 + V_26 ) ) ;
* V_75 += ( V_62 - V_141 ) + 1 ;
return 1 ;
}
}
return 0 ;
}
static int F_40 ( T_1 * V_142 , char * V_143 , char * V_144 , char * V_145 )
{
int V_132 ;
V_132 = fprintf ( V_142 , L_35 , V_143 , V_144 , L_36 , V_145 ) ;
if ( V_132 < 0 )
return V_103 ;
return 0 ;
}
static int F_41 ( T_1 * V_142 , char * V_146 , int type )
{
int error = 0 ;
char V_93 [ V_82 ] ;
int V_26 = 0 ;
int V_35 = 0 ;
char V_98 [ 256 ] ;
char V_147 [ 13 ] ;
int V_75 = 0 ;
memset ( V_93 , 0 , sizeof( V_93 ) ) ;
while ( F_39 ( V_146 , & V_75 , V_93 ,
( V_85 * 2 ) ) ) {
V_147 [ 0 ] = 0 ;
if ( F_38 ( V_93 ) ) {
switch ( type ) {
case V_148 :
snprintf ( V_98 , sizeof( V_98 ) , L_26 , L_37 ) ;
break;
case V_135 :
snprintf ( V_98 , sizeof( V_98 ) , L_26 , L_38 ) ;
break;
case V_149 :
snprintf ( V_98 , sizeof( V_98 ) , L_26 , L_39 ) ;
break;
case V_150 :
snprintf ( V_98 , sizeof( V_98 ) , L_26 , L_40 ) ;
break;
}
if ( type == V_150 ) {
snprintf ( V_147 , sizeof( V_147 ) , L_41 , ++ V_26 ) ;
} else if ( type == V_149 && V_26 == 0 ) {
++ V_26 ;
} else {
snprintf ( V_147 , sizeof( V_147 ) , L_41 , V_26 ++ ) ;
}
} else if ( F_36 ( V_93 , type ) ) {
switch ( type ) {
case V_148 :
snprintf ( V_98 , sizeof( V_98 ) , L_26 , L_42 ) ;
break;
case V_135 :
snprintf ( V_98 , sizeof( V_98 ) , L_26 , L_43 ) ;
break;
case V_149 :
snprintf ( V_98 , sizeof( V_98 ) , L_26 ,
L_44 ) ;
break;
case V_150 :
snprintf ( V_98 , sizeof( V_98 ) , L_26 , L_40 ) ;
break;
}
if ( type == V_150 ) {
snprintf ( V_147 , sizeof( V_147 ) , L_41 , ++ V_26 ) ;
} else if ( V_35 == 0 ) {
++ V_35 ;
} else {
snprintf ( V_147 , sizeof( V_147 ) , L_45 , V_35 ++ ) ;
}
} else {
return V_151 ;
}
error = F_40 ( V_142 , V_98 , V_147 , V_93 ) ;
if ( error )
return error ;
memset ( V_93 , 0 , sizeof( V_93 ) ) ;
}
return 0 ;
}
static int F_42 ( char * V_63 , struct V_76 * V_152 )
{
int error = 0 ;
char V_153 [ V_65 ] ;
T_1 * V_42 ;
char V_71 [ V_65 ] ;
char * V_69 ;
snprintf ( V_153 , sizeof( V_153 ) , L_18 , V_27 ,
L_46 , V_63 ) ;
V_42 = fopen ( V_153 , L_47 ) ;
if ( V_42 == NULL ) {
F_4 ( V_10 , L_48 ,
V_11 , strerror ( V_11 ) ) ;
return V_103 ;
}
V_69 = F_24 ( V_63 ) ;
if ( V_69 == NULL ) {
error = V_103 ;
goto V_154;
}
error = F_40 ( V_42 , L_49 , L_50 , V_69 ) ;
free ( V_69 ) ;
if ( error )
goto V_154;
error = F_40 ( V_42 , L_51 , L_50 , V_63 ) ;
if ( error )
goto V_154;
if ( V_152 -> V_86 ) {
error = F_40 ( V_42 , L_52 , L_50 , L_53 ) ;
if ( error )
goto V_154;
} else {
error = F_40 ( V_42 , L_52 , L_50 , L_54 ) ;
if ( error )
goto V_154;
}
error = F_41 ( V_42 , ( char * ) V_152 -> V_115 , V_148 ) ;
if ( error )
goto V_154;
error = F_41 ( V_42 , ( char * ) V_152 -> V_127 , V_135 ) ;
if ( error )
goto V_154;
error = F_41 ( V_42 , ( char * ) V_152 -> V_79 , V_149 ) ;
if ( error )
goto V_154;
error = F_41 ( V_42 , ( char * ) V_152 -> V_84 , V_150 ) ;
if ( error )
goto V_154;
fclose ( V_42 ) ;
snprintf ( V_71 , sizeof( V_71 ) , V_83 L_22 ,
L_55 , V_153 ) ;
if ( system ( V_71 ) ) {
F_4 ( V_10 , L_56 ,
V_71 , V_11 , strerror ( V_11 ) ) ;
return V_103 ;
}
return 0 ;
V_154:
F_4 ( V_10 , L_57 ) ;
fclose ( V_42 ) ;
return error ;
}
static void
F_43 ( char * V_77 , int V_91 )
{
struct V_155 V_156 , * V_157 ;
int error = 0 ;
F_44 ( V_77 , V_91 ) ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_158 = V_99 ;
V_156 . V_159 = V_160 ;
V_156 . V_161 = V_162 ;
error = F_45 ( V_77 , NULL , & V_156 , & V_157 ) ;
if ( error != 0 ) {
snprintf ( V_77 , V_91 , L_58 ,
error , F_46 ( error ) ) ;
return;
}
snprintf ( V_77 , V_91 , L_26 , V_157 -> V_163 ) ;
F_47 ( V_157 ) ;
}
void F_48 ( char * V_164 [] )
{
fprintf ( V_165 , L_59
L_60
L_61
L_62 , V_164 [ 0 ] ) ;
}
int main ( int V_166 , char * V_164 [] )
{
int V_167 , V_73 ;
int error ;
struct V_168 V_169 ;
char * V_43 ;
struct V_170 V_171 [ 1 ] ;
char * V_172 ;
char * V_173 ;
int V_104 ;
int V_1 ;
char * V_63 ;
struct V_76 * V_174 ;
int V_175 = 1 , V_176 = 0 , V_177 ;
static struct V_178 V_179 [] = {
{ L_63 , V_180 , 0 , 'h' } ,
{ L_64 , V_180 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_177 = F_49 ( V_166 , V_164 , L_65 , V_179 ,
& V_176 ) ) != - 1 ) {
switch ( V_177 ) {
case 'n' :
V_175 = 0 ;
break;
case 'h' :
default:
F_48 ( V_164 ) ;
exit ( V_12 ) ;
}
}
if ( V_175 && F_50 ( 1 , 0 ) )
return 1 ;
F_51 ( L_66 , 0 , V_181 ) ;
F_4 ( V_182 , L_67 , F_2 () ) ;
V_167 = F_11 ( L_68 , V_30 | V_32 ) ;
if ( V_167 < 0 ) {
F_4 ( V_10 , L_69 ,
V_11 , strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
F_17 () ;
F_43 ( V_183 , sizeof( V_183 ) ) ;
if ( F_8 () ) {
F_4 ( V_10 , L_70 ) ;
exit ( V_12 ) ;
}
V_171 -> V_184 . V_185 = V_186 ;
V_73 = F_52 ( V_167 , V_171 , sizeof( struct V_170 ) ) ;
if ( V_73 != sizeof( struct V_170 ) ) {
F_4 ( V_10 , L_71 ,
V_11 , strerror ( V_11 ) ) ;
F_12 ( V_167 ) ;
exit ( V_12 ) ;
}
V_169 . V_8 = V_167 ;
while ( 1 ) {
V_169 . V_187 = V_188 ;
V_169 . V_189 = 0 ;
if ( F_53 ( & V_169 , 1 , - 1 ) < 0 ) {
F_4 ( V_10 , L_72 , V_11 , strerror ( V_11 ) ) ;
if ( V_11 == V_190 ) {
F_12 ( V_167 ) ;
exit ( V_12 ) ;
}
else
continue;
}
V_73 = F_54 ( V_167 , V_171 , sizeof( struct V_170 ) ) ;
if ( V_73 != sizeof( struct V_170 ) ) {
F_4 ( V_10 , L_73 ,
V_11 , strerror ( V_11 ) ) ;
F_12 ( V_167 ) ;
return V_12 ;
}
V_104 = V_171 -> V_184 . V_185 ;
V_1 = V_171 -> V_184 . V_1 ;
V_171 -> error = V_191 ;
if ( ( V_192 ) && ( V_104 == V_186 ) ) {
V_192 = 0 ;
V_43 = ( char * ) V_171 -> V_193 . V_194 . V_195 ;
V_196 = malloc ( strlen ( V_43 ) + 1 ) ;
if ( V_196 ) {
strcpy ( V_196 , V_43 ) ;
F_4 ( V_182 , L_74 ,
V_196 ) ;
} else {
F_4 ( V_10 , L_8 ) ;
}
continue;
}
switch ( V_104 ) {
case V_124 :
V_174 = & V_171 -> V_193 . V_174 ;
V_63 =
F_25 ( ( char * ) V_174 -> V_197 ) ;
if ( V_63 == NULL ) {
V_171 -> error = V_103 ;
break;
}
error = F_33 (
0 , V_63 , V_124 ,
V_174 ,
( V_85 * 2 ) ) ;
if ( error )
V_171 -> error = error ;
free ( V_63 ) ;
break;
case V_198 :
V_174 = & V_171 -> V_193 . V_174 ;
V_63 = F_20 (
( char * ) V_174 -> V_197 ) ;
if ( V_63 == NULL ) {
V_171 -> error = V_199 ;
break;
}
error = F_42 ( V_63 , V_174 ) ;
if ( error )
V_171 -> error = error ;
free ( V_63 ) ;
break;
case V_200 :
if ( F_14 ( V_1 ,
V_171 -> V_193 . V_201 . V_202 . V_33 ,
V_171 -> V_193 . V_201 . V_202 . V_34 ,
V_171 -> V_193 . V_201 . V_202 . V_37 ,
V_171 -> V_193 . V_201 . V_202 . V_38 ) )
V_171 -> error = V_203 ;
break;
case V_204 :
if ( F_15 ( V_1 ,
V_171 -> V_193 . V_201 . V_202 . V_33 ,
V_171 -> V_193 . V_201 . V_202 . V_34 ,
V_171 -> V_193 . V_201 . V_202 . V_37 ,
V_171 -> V_193 . V_201 . V_202 . V_38 ) )
V_171 -> error = V_203 ;
break;
case V_205 :
if ( F_13 ( V_1 ,
V_171 -> V_193 . V_206 . V_33 ,
V_171 -> V_193 . V_206 . V_34 ) )
V_171 -> error = V_203 ;
break;
default:
break;
}
if ( V_104 != V_114 )
goto V_207;
if ( V_1 != V_208 ) {
if ( F_16 ( V_1 ,
V_171 -> V_193 . V_209 . V_41 ,
V_171 -> V_193 . V_209 . V_202 . V_33 ,
V_39 ,
V_171 -> V_193 . V_209 . V_202 . V_37 ,
V_40 ) )
V_171 -> error = V_203 ;
goto V_207;
}
V_173 = ( char * ) V_171 -> V_193 . V_209 . V_202 . V_33 ;
V_172 = ( char * ) V_171 -> V_193 . V_209 . V_202 . V_37 ;
switch ( V_171 -> V_193 . V_209 . V_41 ) {
case V_210 :
strcpy ( V_172 , V_183 ) ;
strcpy ( V_173 , L_75 ) ;
break;
case V_211 :
strcpy ( V_173 , L_76 ) ;
strcpy ( V_172 , V_196 ) ;
break;
case V_212 :
F_33 ( V_99 , NULL , V_114 ,
V_172 , V_40 ) ;
strcpy ( V_173 , L_77 ) ;
break;
case V_213 :
F_33 ( V_123 , NULL , V_114 ,
V_172 , V_40 ) ;
strcpy ( V_173 , L_78 ) ;
break;
case V_214 :
strcpy ( V_172 , V_48 ) ;
strcpy ( V_173 , L_79 ) ;
break;
case V_215 :
strcpy ( V_172 , V_49 ) ;
strcpy ( V_173 , L_80 ) ;
break;
case V_216 :
strcpy ( V_172 , V_54 ) ;
strcpy ( V_173 , L_81 ) ;
break;
case V_217 :
strcpy ( V_172 , V_57 ) ;
strcpy ( V_173 , L_82 ) ;
break;
case V_218 :
strcpy ( V_172 , V_46 ) ;
strcpy ( V_173 , L_83 ) ;
break;
case V_219 :
strcpy ( V_172 , V_51 ) ;
strcpy ( V_173 , L_84 ) ;
break;
default:
V_171 -> error = V_203 ;
break;
}
V_207:
V_73 = F_52 ( V_167 , V_171 , sizeof( struct V_170 ) ) ;
if ( V_73 != sizeof( struct V_170 ) ) {
F_4 ( V_10 , L_85 , V_11 ,
strerror ( V_11 ) ) ;
exit ( V_12 ) ;
}
}
F_12 ( V_167 ) ;
exit ( 0 ) ;
}
