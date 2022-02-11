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
static int F_12 ( int V_1 , T_3 * V_34 , int V_35 )
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
static int F_13 ( int V_1 , T_3 * V_34 , int V_35 , T_3 * V_38 ,
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
static int F_14 ( int V_1 , T_3 * V_34 , int V_35 , T_3 * V_38 ,
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
static int F_15 ( int V_1 , int V_42 , T_3 * V_34 , int V_35 ,
T_3 * V_38 , int V_39 )
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
V_49 = V_46 . V_50 ;
V_51 = V_46 . V_52 ;
V_44 = strchr ( V_47 , '-' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_43 = fopen ( L_13 , L_7 ) ;
if ( V_43 != NULL ) {
while ( fgets ( V_45 , sizeof( V_45 ) , V_43 ) ) {
char * V_38 , * V_53 ;
if ( V_45 [ 0 ] == '#' )
continue;
V_44 = strchr ( V_45 , '=' ) ;
if ( ! V_44 )
continue;
* V_44 ++ = 0 ;
V_38 = V_44 ;
V_53 = V_44 ;
while ( * V_44 ) {
if ( * V_44 == '\\' ) {
++ V_44 ;
if ( ! * V_44 )
break;
* V_53 ++ = * V_44 ++ ;
} else if ( * V_44 == '\'' || * V_44 == '"' ||
* V_44 == '\n' ) {
++ V_44 ;
} else {
* V_53 ++ = * V_44 ++ ;
}
}
* V_53 = 0 ;
if ( ! strcmp ( V_45 , L_14 ) ) {
V_44 = F_18 ( V_38 ) ;
if ( ! V_44 )
break;
V_49 = V_44 ;
} else if ( ! strcmp ( V_45 , L_15 ) ) {
V_44 = F_18 ( V_38 ) ;
if ( ! V_44 )
break;
V_54 = V_44 ;
}
}
fclose ( V_43 ) ;
return;
}
V_43 = fopen ( L_16 , L_7 ) ;
if ( V_43 != NULL )
goto V_55;
V_43 = fopen ( L_17 , L_7 ) ;
if ( V_43 != NULL )
goto V_55;
return;
V_55:
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_18 ( V_45 ) ;
if ( ! V_44 )
goto V_56;
V_49 = V_44 ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_18 ( V_45 ) ;
if ( ! V_44 )
goto V_56;
V_54 = V_44 ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_44 = strchr ( V_45 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_44 = F_18 ( V_45 ) ;
if ( V_44 )
V_57 = V_44 ;
}
}
}
V_56:
fclose ( V_43 ) ;
return;
}
static char * F_19 ( char * V_58 )
{
T_4 * V_59 ;
struct V_60 * V_61 ;
T_1 * V_43 ;
char * V_44 , * V_53 , * V_62 ;
char * V_63 = NULL ;
char V_45 [ 256 ] ;
char * V_64 = L_18 ;
char V_65 [ 256 ] ;
V_59 = F_20 ( V_64 ) ;
if ( V_59 == NULL )
return NULL ;
snprintf ( V_65 , sizeof( V_65 ) , L_19 , V_64 ) ;
V_53 = V_65 + strlen ( V_64 ) ;
while ( ( V_61 = F_21 ( V_59 ) ) != NULL ) {
* V_53 = '\0' ;
strcat ( V_65 , V_61 -> V_66 ) ;
strcat ( V_65 , L_20 ) ;
V_43 = fopen ( V_65 , L_7 ) ;
if ( V_43 == NULL )
continue;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_62 = strchr ( V_44 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
if ( ! strcmp ( V_44 , V_58 ) ) {
V_63 = F_18 ( V_61 -> V_66 ) ;
fclose ( V_43 ) ;
break;
}
}
fclose ( V_43 ) ;
}
F_22 ( V_59 ) ;
return V_63 ;
}
static char * F_23 ( char * V_63 )
{
T_1 * V_43 ;
char * V_44 , * V_62 ;
char V_45 [ 256 ] ;
char V_67 [ 256 ] ;
int V_26 ;
char * V_68 = NULL ;
snprintf ( V_67 , sizeof( V_67 ) , L_21 , L_18 ,
V_63 , L_22 ) ;
V_43 = fopen ( V_67 , L_7 ) ;
if ( V_43 == NULL )
return NULL ;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_62 = strchr ( V_44 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
for ( V_26 = 0 ; V_26 < strlen ( V_44 ) ; V_26 ++ )
V_44 [ V_26 ] = toupper ( V_44 [ V_26 ] ) ;
V_68 = F_18 ( V_44 ) ;
}
fclose ( V_43 ) ;
return V_68 ;
}
static char * F_24 ( char * V_69 )
{
T_4 * V_59 ;
struct V_60 * V_61 ;
T_1 * V_43 ;
char * V_44 , * V_53 , * V_62 ;
char * V_63 = NULL ;
char V_45 [ 256 ] ;
char * V_64 = L_18 ;
char V_65 [ 256 ] ;
int V_26 ;
V_59 = F_20 ( V_64 ) ;
if ( V_59 == NULL )
return NULL ;
snprintf ( V_65 , sizeof( V_65 ) , V_64 ) ;
V_53 = V_65 + strlen ( V_64 ) ;
while ( ( V_61 = F_21 ( V_59 ) ) != NULL ) {
* V_53 = '\0' ;
strcat ( V_65 , V_61 -> V_66 ) ;
strcat ( V_65 , L_22 ) ;
V_43 = fopen ( V_65 , L_7 ) ;
if ( V_43 == NULL )
continue;
V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ;
if ( V_44 ) {
V_62 = strchr ( V_44 , '\n' ) ;
if ( V_62 )
* V_62 = '\0' ;
for ( V_26 = 0 ; V_26 < strlen ( V_44 ) ; V_26 ++ )
V_44 [ V_26 ] = toupper ( V_44 [ V_26 ] ) ;
if ( ! strcmp ( V_44 , V_69 ) ) {
V_63 = F_18 ( V_61 -> V_66 ) ;
fclose ( V_43 ) ;
break;
}
}
fclose ( V_43 ) ;
}
F_22 ( V_59 ) ;
return V_63 ;
}
static void F_25 ( char * V_70 ,
char * V_71 , int V_72 ,
int V_73 , int V_74 )
{
char V_45 [ 256 ] ;
char * V_44 ;
char * V_62 ;
T_1 * V_43 ;
V_43 = F_26 ( V_70 , L_7 ) ;
if ( V_43 == NULL )
return;
if ( V_74 == 0 )
memset ( V_71 , 0 , V_72 ) ;
while ( ( V_44 = fgets ( V_45 , sizeof( V_45 ) , V_43 ) ) != NULL ) {
if ( ( V_72 - strlen ( V_71 ) ) < ( V_73 + 1 ) )
break;
V_62 = strchr ( V_44 , '\n' ) ;
* V_62 = '\0' ;
strcat ( V_71 , V_44 ) ;
strcat ( V_71 , L_23 ) ;
}
F_27 ( V_43 ) ;
}
static void F_28 ( char * V_63 ,
struct V_75 * V_76 )
{
char V_70 [ 512 ] ;
char V_77 [ 128 ] ;
char * V_44 ;
T_1 * V_43 ;
sprintf ( V_70 , L_24 , L_25 , V_63 ) ;
strcat ( V_70 , L_26 ) ;
F_25 ( V_70 , ( char * ) V_76 -> V_78 ,
( V_79 * 2 ) , V_80 , 0 ) ;
sprintf ( V_70 , L_24 , L_27 , V_63 ) ;
strcat ( V_70 , L_26 ) ;
F_25 ( V_70 , ( char * ) V_76 -> V_78 ,
( V_79 * 2 ) , V_81 , 1 ) ;
sprintf ( V_70 , L_19 , L_28 ) ;
F_25 ( V_70 , ( char * ) V_76 -> V_82 ,
( V_83 * 2 ) , V_80 , 0 ) ;
sprintf ( V_70 , L_24 , L_29 , V_63 ) ;
V_43 = F_26 ( V_70 , L_7 ) ;
if ( V_43 == NULL )
return;
V_44 = fgets ( V_77 , sizeof( V_77 ) , V_43 ) ;
if ( V_44 == NULL ) {
F_27 ( V_43 ) ;
return;
}
if ( ! strncmp ( V_44 , L_30 , 7 ) )
V_76 -> V_84 = 1 ;
else
V_76 -> V_84 = 0 ;
F_27 ( V_43 ) ;
}
static unsigned int F_29 ( unsigned int * V_85 )
{
unsigned int V_86 = * V_85 - ( ( * V_85 >> 1 ) & 0x55555555 ) ;
V_86 = ( V_86 & 0x33333333 ) + ( ( V_86 >> 2 ) & 0x33333333 ) ;
V_86 = ( V_86 + ( V_86 >> 4 ) ) & 0x0F0F0F0F ;
V_86 = V_86 + ( V_86 >> 8 ) ;
return ( V_86 + ( V_86 >> 16 ) ) & 0x000000FF ;
}
static int F_30 ( void * V_87 ,
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
V_96 = F_31 ( V_88 , & V_91 -> V_98 , V_95 , 50 ) ;
V_94 = V_80 ;
} else {
V_93 = (struct V_92 * ) V_87 ;
V_96 = F_31 ( V_88 , & V_93 -> V_99 . V_100 , V_95 , 50 ) ;
V_94 = V_81 ;
}
if ( ( V_89 - * V_74 ) < V_94 + 1 )
return V_101 ;
if ( V_96 == NULL ) {
strcpy ( V_76 , L_31 ) ;
return V_101 ;
}
if ( * V_74 == 0 )
strcpy ( V_76 , V_95 ) ;
else
strcat ( V_76 , V_95 ) ;
strcat ( V_76 , L_23 ) ;
* V_74 += strlen ( V_96 ) + 1 ;
return 0 ;
}
static int
F_32 ( int V_88 , char * V_63 , int V_102 ,
void * V_103 , int V_89 )
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
if ( F_33 ( & V_105 ) ) {
strcpy ( V_76 , L_32 ) ;
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
if ( ( V_88 != 0 ) && ( V_106 -> V_115 -> V_118 != V_88 ) ) {
V_106 = V_106 -> V_116 ;
continue;
}
if ( ( V_106 -> V_115 -> V_118 != V_97 ) &&
( V_106 -> V_115 -> V_118 != V_119 ) ) {
V_106 = V_106 -> V_116 ;
continue;
}
if ( V_102 == V_120 ) {
if ( V_106 -> V_115 -> V_118 == V_97 ) {
V_108 -> V_114 |= V_121 ;
error = F_30 (
V_106 -> V_122 ,
V_97 ,
( char * )
V_108 -> V_123 ,
V_89 ,
& V_107 ) ;
if ( error )
goto V_124;
} else {
V_108 -> V_114 |= V_125 ;
V_110 = 0 ;
V_111 = ( char * ) V_108 -> V_123 ;
V_93 = (struct V_92 * )
V_106 -> V_122 ;
V_85 = V_93 -> V_99 . V_126 ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
V_110 += F_29 ( & V_85 [ V_26 ] ) ;
sprintf ( V_109 , L_33 , V_110 ) ;
if ( ( V_89 - V_107 ) <
( strlen ( V_109 ) + 1 ) )
goto V_124;
if ( V_107 == 0 )
strcpy ( V_111 , V_109 ) ;
else
strcat ( V_111 , V_109 ) ;
strcat ( ( char * ) V_108 -> V_123 , L_23 ) ;
V_107 += strlen ( V_111 ) + 1 ;
}
F_28 ( V_63 , V_108 ) ;
}
V_124:
error = F_30 ( V_106 -> V_115 ,
V_106 -> V_115 -> V_118 ,
V_76 ,
V_89 , & V_74 ) ;
if ( error )
goto V_127;
V_106 = V_106 -> V_116 ;
}
V_127:
F_34 ( V_105 ) ;
return error ;
}
static int F_35 ( char * V_91 , int type )
{
int V_128 ;
struct V_129 V_130 ;
V_128 = F_36 ( V_119 , V_91 , & V_130 ) ;
if ( V_128 != 1 ) {
if ( type == V_131 )
return 1 ;
return 0 ;
}
sprintf ( V_91 , L_34
L_35 ,
( int ) V_130 . V_100 [ 0 ] , ( int ) V_130 . V_100 [ 1 ] ,
( int ) V_130 . V_100 [ 2 ] , ( int ) V_130 . V_100 [ 3 ] ,
( int ) V_130 . V_100 [ 4 ] , ( int ) V_130 . V_100 [ 5 ] ,
( int ) V_130 . V_100 [ 6 ] , ( int ) V_130 . V_100 [ 7 ] ,
( int ) V_130 . V_100 [ 8 ] , ( int ) V_130 . V_100 [ 9 ] ,
( int ) V_130 . V_100 [ 10 ] , ( int ) V_130 . V_100 [ 11 ] ,
( int ) V_130 . V_100 [ 12 ] , ( int ) V_130 . V_100 [ 13 ] ,
( int ) V_130 . V_100 [ 14 ] , ( int ) V_130 . V_100 [ 15 ] ) ;
return 1 ;
}
static int F_37 ( char * V_91 )
{
int V_128 ;
struct V_132 V_133 ;
V_128 = F_36 ( V_97 , V_91 , & V_133 ) ;
if ( V_128 == 1 )
return 1 ;
return 0 ;
}
static int F_38 ( char * V_134 , int * V_74 ,
char * V_135 , int V_136 )
{
char * V_62 ;
char * V_137 ;
V_137 = V_134 + * V_74 ;
V_62 = strchr ( V_137 , ';' ) ;
if ( V_62 )
* V_62 = 0 ;
else
V_62 = V_137 + strlen ( V_137 ) ;
if ( strlen ( V_137 ) != 0 ) {
int V_26 = 0 ;
while ( V_137 [ V_26 ] == ' ' )
V_26 ++ ;
if ( ( V_62 - V_137 ) <= V_136 ) {
strcpy ( V_135 , ( V_137 + V_26 ) ) ;
* V_74 += ( V_62 - V_137 ) + 1 ;
return 1 ;
}
}
return 0 ;
}
static int F_39 ( T_1 * V_138 , char * V_139 , char * V_140 , char * V_141 )
{
int V_128 ;
V_128 = fprintf ( V_138 , L_36 , V_139 , V_140 , L_37 , V_141 ) ;
if ( V_128 < 0 )
return V_101 ;
return 0 ;
}
static int F_40 ( T_1 * V_138 , char * V_142 , int type )
{
int error = 0 ;
char V_91 [ V_81 ] ;
int V_26 = 0 ;
int V_36 = 0 ;
char V_96 [ 256 ] ;
char V_143 [ 10 ] ;
int V_74 = 0 ;
memset ( V_91 , 0 , sizeof( V_91 ) ) ;
while ( F_38 ( V_142 , & V_74 , V_91 ,
( V_83 * 2 ) ) ) {
V_143 [ 0 ] = 0 ;
if ( F_37 ( V_91 ) ) {
switch ( type ) {
case V_144 :
snprintf ( V_96 , sizeof( V_96 ) , L_19 , L_38 ) ;
break;
case V_131 :
snprintf ( V_96 , sizeof( V_96 ) , L_19 , L_39 ) ;
break;
case V_145 :
snprintf ( V_96 , sizeof( V_96 ) , L_19 , L_40 ) ;
break;
case V_146 :
snprintf ( V_96 , sizeof( V_96 ) , L_19 , L_41 ) ;
break;
}
if ( V_26 != 0 ) {
if ( type != V_146 ) {
snprintf ( V_143 , sizeof( V_143 ) ,
L_42 , V_26 ++ ) ;
} else {
snprintf ( V_143 , sizeof( V_143 ) ,
L_43 , ++ V_26 ) ;
}
} else if ( type == V_146 ) {
snprintf ( V_143 , sizeof( V_143 ) , L_43 , ++ V_26 ) ;
}
} else if ( F_35 ( V_91 , type ) ) {
switch ( type ) {
case V_144 :
snprintf ( V_96 , sizeof( V_96 ) , L_19 , L_44 ) ;
break;
case V_131 :
snprintf ( V_96 , sizeof( V_96 ) , L_19 , L_45 ) ;
break;
case V_145 :
snprintf ( V_96 , sizeof( V_96 ) , L_19 ,
L_46 ) ;
break;
case V_146 :
snprintf ( V_96 , sizeof( V_96 ) , L_19 , L_41 ) ;
break;
}
if ( ( V_36 != 0 ) || ( type == V_146 ) ) {
if ( type != V_146 ) {
snprintf ( V_143 , sizeof( V_143 ) ,
L_42 , V_36 ++ ) ;
} else {
snprintf ( V_143 , sizeof( V_143 ) ,
L_43 , ++ V_26 ) ;
}
} else if ( type == V_146 ) {
snprintf ( V_143 , sizeof( V_143 ) ,
L_43 , ++ V_26 ) ;
}
} else {
return V_147 ;
}
error = F_39 ( V_138 , V_96 , V_143 , V_91 ) ;
if ( error )
return error ;
memset ( V_91 , 0 , sizeof( V_91 ) ) ;
}
return 0 ;
}
static int F_41 ( char * V_63 , struct V_75 * V_148 )
{
int error = 0 ;
char V_149 [ 128 ] ;
T_1 * V_43 ;
char V_70 [ 512 ] ;
char * V_68 ;
snprintf ( V_149 , sizeof( V_149 ) , L_21 , V_150 ,
L_47 , V_63 ) ;
V_43 = fopen ( V_149 , L_4 ) ;
if ( V_43 == NULL ) {
F_4 ( V_10 , L_48 ) ;
return V_101 ;
}
V_68 = F_23 ( V_63 ) ;
if ( V_68 == NULL ) {
error = V_101 ;
goto V_151;
}
error = F_39 ( V_43 , L_49 , L_50 , V_68 ) ;
if ( error )
goto V_151;
error = F_39 ( V_43 , L_51 , L_50 , V_63 ) ;
if ( error )
goto V_151;
if ( V_148 -> V_84 ) {
error = F_39 ( V_43 , L_52 , L_50 , L_53 ) ;
if ( error )
goto V_151;
goto V_152;
}
error = F_40 ( V_43 , ( char * ) V_148 -> V_113 , V_144 ) ;
if ( error )
goto V_151;
error = F_40 ( V_43 , ( char * ) V_148 -> V_123 , V_131 ) ;
if ( error )
goto V_151;
error = F_40 ( V_43 , ( char * ) V_148 -> V_78 , V_145 ) ;
if ( error )
goto V_151;
error = F_40 ( V_43 , ( char * ) V_148 -> V_82 , V_146 ) ;
if ( error )
goto V_151;
V_152:
free ( V_68 ) ;
fclose ( V_43 ) ;
snprintf ( V_70 , sizeof( V_70 ) , L_24 , L_54 , V_149 ) ;
system ( V_70 ) ;
return 0 ;
V_151:
F_4 ( V_10 , L_55 ) ;
free ( V_68 ) ;
fclose ( V_43 ) ;
return error ;
}
static int
F_42 ( char * V_76 , int V_89 )
{
struct V_153 V_154 , * V_155 ;
int error = 0 ;
F_43 ( V_76 , V_89 ) ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_156 = V_97 ;
V_154 . V_157 = V_158 ;
V_154 . V_159 = V_160 ;
error = F_44 ( V_76 , NULL , & V_154 , & V_155 ) ;
if ( error != 0 ) {
strcpy ( V_76 , L_56 ) ;
return error ;
}
strcpy ( V_76 , V_155 -> V_161 ) ;
F_45 ( V_155 ) ;
return error ;
}
static int
F_46 ( int V_8 , struct V_162 * V_163 )
{
struct V_164 * V_165 ;
unsigned int V_166 ;
struct V_167 V_168 ;
char V_76 [ 64 ] ;
struct V_169 V_170 [ 2 ] ;
V_166 = F_47 ( sizeof( struct V_162 ) + V_163 -> V_72 ) ;
V_165 = (struct V_164 * ) V_76 ;
V_165 -> V_171 = 0 ;
V_165 -> V_172 = F_2 () ;
V_165 -> V_173 = V_174 ;
V_165 -> V_175 = F_48 ( V_166 - sizeof( * V_165 ) ) ;
V_165 -> V_176 = 0 ;
V_170 [ 0 ] . V_177 = V_165 ;
V_170 [ 0 ] . V_178 = sizeof( * V_165 ) ;
V_170 [ 1 ] . V_177 = V_163 ;
V_170 [ 1 ] . V_178 = V_166 ;
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
V_168 . V_179 = & V_91 ;
V_168 . V_180 = sizeof( V_91 ) ;
V_168 . V_181 = V_170 ;
V_168 . V_182 = 2 ;
return F_49 ( V_8 , & V_168 , 0 ) ;
}
int main ( void )
{
int V_8 , V_72 , V_183 ;
int error ;
struct V_162 * V_168 ;
struct V_184 V_185 ;
struct V_164 * V_186 ;
struct V_162 * V_187 ;
struct V_188 * V_189 ;
char * V_44 ;
char * V_190 ;
char * V_191 ;
int V_102 ;
int V_1 ;
char * V_63 ;
struct V_75 * V_192 ;
F_50 ( 1 , 0 ) ;
F_51 ( L_57 , 0 , V_193 ) ;
F_4 ( V_194 , L_58 , F_2 () ) ;
F_16 () ;
if ( F_8 () ) {
F_4 ( V_10 , L_59 ) ;
exit ( V_11 ) ;
}
V_8 = F_52 ( V_195 , V_196 , V_197 ) ;
if ( V_8 < 0 ) {
F_4 ( V_10 , L_60 , V_8 ) ;
exit ( V_11 ) ;
}
V_91 . V_198 = V_195 ;
V_91 . V_199 = 0 ;
V_91 . V_200 = 0 ;
V_91 . V_201 = V_202 ;
error = F_53 ( V_8 , (struct V_203 * ) & V_91 , sizeof( V_91 ) ) ;
if ( error < 0 ) {
F_4 ( V_10 , L_61 , error ) ;
F_54 ( V_8 ) ;
exit ( V_11 ) ;
}
V_183 = V_91 . V_201 ;
F_55 ( V_8 , 270 , 1 , & V_183 , sizeof( V_183 ) ) ;
V_168 = (struct V_162 * ) V_204 ;
V_168 -> V_205 . V_206 = V_202 ;
V_168 -> V_205 . V_207 = V_208 ;
V_189 = (struct V_188 * ) V_168 -> V_209 ;
V_189 -> V_210 . V_211 = V_212 ;
V_168 -> V_213 = 0 ;
V_168 -> V_72 = sizeof( struct V_188 ) ;
V_72 = F_46 ( V_8 , V_168 ) ;
if ( V_72 < 0 ) {
F_4 ( V_10 , L_62 , V_72 ) ;
F_54 ( V_8 ) ;
exit ( V_11 ) ;
}
V_185 . V_8 = V_8 ;
while ( 1 ) {
struct V_203 * V_214 = (struct V_203 * ) & V_91 ;
T_5 V_215 = sizeof( V_91 ) ;
V_185 . V_216 = V_217 ;
V_185 . V_218 = 0 ;
F_56 ( & V_185 , 1 , - 1 ) ;
V_72 = F_57 ( V_8 , V_219 , sizeof( V_219 ) , 0 ,
V_214 , & V_215 ) ;
if ( V_72 < 0 || V_91 . V_200 ) {
F_4 ( V_10 , L_63 ,
V_91 . V_200 , V_220 , strerror ( V_220 ) ) ;
F_54 ( V_8 ) ;
return - 1 ;
}
V_186 = (struct V_164 * ) V_219 ;
V_187 = (struct V_162 * ) F_58 ( V_186 ) ;
V_189 = (struct V_188 * ) V_187 -> V_209 ;
V_102 = V_189 -> V_210 . V_211 ;
V_1 = V_189 -> V_210 . V_1 ;
V_189 -> error = V_221 ;
if ( ( V_222 ) && ( V_102 == V_212 ) ) {
V_222 = 0 ;
V_44 = ( char * ) V_189 -> V_223 . V_224 . V_225 ;
V_226 = malloc ( strlen ( V_44 ) + 1 ) ;
if ( V_226 ) {
strcpy ( V_226 , V_44 ) ;
F_4 ( V_194 , L_64 ,
V_226 ) ;
} else {
F_4 ( V_10 , L_9 ) ;
}
continue;
}
switch ( V_102 ) {
case V_120 :
V_192 = & V_189 -> V_223 . V_192 ;
V_63 =
F_24 ( ( char * ) V_192 -> V_227 ) ;
if ( V_63 == NULL ) {
V_189 -> error = V_101 ;
break;
}
error = F_32 (
0 , V_63 , V_120 ,
V_192 ,
( V_83 * 2 ) ) ;
if ( error )
V_189 -> error = error ;
free ( V_63 ) ;
break;
case V_228 :
V_192 = & V_189 -> V_223 . V_192 ;
V_63 = F_19 (
( char * ) V_192 -> V_227 ) ;
if ( V_63 == NULL ) {
V_189 -> error = V_229 ;
break;
}
error = F_41 ( V_63 , V_192 ) ;
if ( error )
V_189 -> error = error ;
free ( V_63 ) ;
break;
case V_230 :
if ( F_13 ( V_1 ,
V_189 -> V_223 . V_231 . V_209 . V_34 ,
V_189 -> V_223 . V_231 . V_209 . V_35 ,
V_189 -> V_223 . V_231 . V_209 . V_38 ,
V_189 -> V_223 . V_231 . V_209 . V_39 ) )
V_189 -> error = V_232 ;
break;
case V_233 :
if ( F_14 ( V_1 ,
V_189 -> V_223 . V_231 . V_209 . V_34 ,
V_189 -> V_223 . V_231 . V_209 . V_35 ,
V_189 -> V_223 . V_231 . V_209 . V_38 ,
V_189 -> V_223 . V_231 . V_209 . V_39 ) )
V_189 -> error = V_232 ;
break;
case V_234 :
if ( F_12 ( V_1 ,
V_189 -> V_223 . V_235 . V_34 ,
V_189 -> V_223 . V_235 . V_35 ) )
V_189 -> error = V_232 ;
break;
default:
break;
}
if ( V_102 != V_112 )
goto V_236;
if ( V_1 != V_237 ) {
if ( F_15 ( V_1 ,
V_189 -> V_223 . V_238 . V_42 ,
V_189 -> V_223 . V_238 . V_209 . V_34 ,
V_40 ,
V_189 -> V_223 . V_238 . V_209 . V_38 ,
V_41 ) )
V_189 -> error = V_232 ;
goto V_236;
}
V_189 = (struct V_188 * ) V_187 -> V_209 ;
V_191 = ( char * ) V_189 -> V_223 . V_238 . V_209 . V_34 ;
V_190 = ( char * ) V_189 -> V_223 . V_238 . V_209 . V_38 ;
switch ( V_189 -> V_223 . V_238 . V_42 ) {
case V_239 :
F_42 ( V_190 ,
V_41 ) ;
strcpy ( V_191 , L_65 ) ;
break;
case V_240 :
strcpy ( V_191 , L_66 ) ;
strcpy ( V_190 , V_226 ) ;
break;
case V_241 :
F_32 ( V_97 , NULL , V_112 ,
V_190 , V_41 ) ;
strcpy ( V_191 , L_67 ) ;
break;
case V_242 :
F_32 ( V_119 , NULL , V_112 ,
V_190 , V_41 ) ;
strcpy ( V_191 , L_68 ) ;
break;
case V_243 :
strcpy ( V_190 , V_47 ) ;
strcpy ( V_191 , L_69 ) ;
break;
case V_244 :
strcpy ( V_190 , V_49 ) ;
strcpy ( V_191 , L_70 ) ;
break;
case V_245 :
strcpy ( V_190 , V_54 ) ;
strcpy ( V_191 , L_71 ) ;
break;
case V_246 :
strcpy ( V_190 , V_57 ) ;
strcpy ( V_191 , L_72 ) ;
break;
case V_247 :
strcpy ( V_190 , V_47 ) ;
strcpy ( V_191 , L_73 ) ;
break;
case V_248 :
strcpy ( V_190 , V_51 ) ;
strcpy ( V_191 , L_74 ) ;
break;
default:
V_189 -> error = V_232 ;
break;
}
V_236:
V_187 -> V_205 . V_206 = V_202 ;
V_187 -> V_205 . V_207 = V_208 ;
V_187 -> V_213 = 0 ;
V_187 -> V_72 = sizeof( struct V_188 ) ;
V_72 = F_46 ( V_8 , V_187 ) ;
if ( V_72 < 0 ) {
F_4 ( V_10 , L_75 , V_72 ) ;
exit ( V_11 ) ;
}
}
}
