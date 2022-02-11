static char * F_1 ( char * V_1 , int * V_2 )
{
int V_3 = 0 ;
while ( V_1 [ V_3 ] != '\0' && V_1 [ V_3 ] == ' ' ) {
V_3 ++ ;
}
* V_2 += V_3 ;
return V_1 + V_3 ;
}
static char * F_2 ( char * V_1 , char V_4 , int * V_5 , int * V_6 , T_1 V_7 )
{
static char V_8 [ 1024 ] ;
int V_3 = 0 ;
char * V_9 = F_1 ( V_1 , V_6 ) ;
while ( V_9 [ V_3 ] != '\0' && V_9 [ V_3 ] != V_4 ) {
V_3 ++ ;
}
* V_5 = V_3 ;
* V_6 += V_3 ;
if ( V_7 ) {
char * V_10 = F_3 ( V_9 , V_3 + 1 ) ;
V_10 [ V_3 ] = '\0' ;
return V_10 ;
}
else {
memcpy ( & V_8 , V_9 , V_3 ) ;
V_8 [ V_3 ] = '\0' ;
return V_8 ;
}
}
static T_1 F_4 ( T_2 * V_11 , const char * V_12 , T_1 V_13 )
{
if ( V_11 -> V_14 < V_15 ) {
T_3 * V_16 = & ( V_11 -> V_17 [ V_11 -> V_14 ++ ] ) ;
V_16 -> V_18 = F_5 ( V_12 ) ;
V_16 -> V_19 = V_13 ;
V_11 -> V_20 = V_16 ;
return TRUE ;
}
return FALSE ;
}
static void F_6 ( T_2 * V_11 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_21 = TRUE ;
}
}
static void F_7 ( T_2 * V_11 , T_4 V_22 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_3 = V_22 ;
V_11 -> V_20 -> V_23 = TRUE ;
}
}
static void F_8 ( T_2 * V_11 , T_5 V_22 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_24 = V_22 ;
}
}
static void F_9 ( T_2 * V_11 , T_4 V_22 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_25 = V_22 ;
V_11 -> V_20 -> V_26 = TRUE ;
}
}
static void F_10 ( T_2 * V_11 , T_5 V_22 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_27 = V_22 ;
}
}
static void F_11 ( T_2 * V_11 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_28 = TRUE ;
}
}
static void F_12 ( T_2 * V_11 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_29 = TRUE ;
}
}
static void F_13 ( T_2 * V_11 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_30 = TRUE ;
}
}
static void F_14 ( T_2 * V_11 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_31 = TRUE ;
}
}
static void F_15 ( T_2 * V_11 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_32 = TRUE ;
}
}
static void F_16 ( T_2 * V_11 )
{
if ( V_11 -> V_20 ) {
V_11 -> V_20 -> V_33 = TRUE ;
}
}
static T_1 F_17 ( T_2 * V_11 , const char * V_34 , T_1 V_13 )
{
if ( F_4 ( V_11 , V_34 , V_13 ) ) {
V_11 -> V_20 -> V_35 = V_36 ;
return TRUE ;
}
return FALSE ;
}
static void F_18 ( T_2 * V_11 )
{
if ( V_11 -> V_20 != NULL ) {
V_11 -> V_20 -> V_35 = V_36 ;
}
}
static T_1 F_19 ( T_2 * V_11 , const char * V_37 )
{
if ( F_4 ( V_11 , V_37 , FALSE ) ) {
V_11 -> V_20 -> V_35 = V_38 ;
return TRUE ;
}
return FALSE ;
}
static T_1 F_20 ( T_2 * V_11 , const char * V_39 )
{
V_11 -> V_39 = F_5 ( V_39 ) ;
return TRUE ;
}
static void F_21 ( T_2 * V_11 , const char * V_40 )
{
if ( V_11 -> V_41 < V_42 ) {
V_11 -> V_43 [ V_11 -> V_41 ++ ] = F_5 ( V_40 ) ;
}
}
static void F_22 ( T_6 * V_44 , T_2 * V_11 , char * V_45 )
{
T_7 V_46 = NULL ;
T_7 V_22 = NULL ;
if ( strlen ( V_45 ) < 2 ) {
return;
}
if ( V_11 -> V_47 . V_48 >= V_49 ) {
return;
}
if ( F_23 ( V_44 -> V_50 , V_45 + 1 , & V_46 , & V_22 ) ) {
V_11 -> V_47 . V_51 [ V_11 -> V_47 . V_48 ] . V_52 = ( char * ) V_46 ;
V_11 -> V_47 . V_51 [ V_11 -> V_47 . V_48 ] . V_22 = ( char * ) V_22 ;
V_11 -> V_47 . V_48 ++ ;
}
}
static void F_24 ( T_6 * V_44 , T_2 * V_11 , char * V_45 )
{
T_7 V_46 = NULL ;
T_7 V_22 = NULL ;
if ( strlen ( V_45 ) < 2 ) {
return;
}
if ( V_11 -> V_47 . V_53 >= V_54 ) {
return;
}
if ( F_23 ( V_44 -> V_55 , V_45 + 1 , & V_46 , & V_22 ) ) {
V_11 -> V_47 . V_56 [ V_11 -> V_47 . V_53 ] . V_52 = ( char * ) V_46 ;
V_11 -> V_47 . V_56 [ V_11 -> V_47 . V_53 ] . V_22 = ( char * ) V_22 ;
V_11 -> V_47 . V_53 ++ ;
}
}
void F_25 ( T_6 * V_44 , T_2 * V_11 )
{
int V_5 ;
int V_6 = 0 ;
char * V_45 ;
if ( V_11 -> V_47 . V_57 ) {
return;
}
F_2 ( V_11 -> V_58 + V_6 , ' ' , & V_5 , & V_6 , FALSE ) ;
F_2 ( V_11 -> V_58 + V_6 , ' ' , & V_5 , & V_6 , FALSE ) ;
V_45 = F_2 ( V_11 -> V_58 + V_6 , ' ' , & V_5 , & V_6 , FALSE ) ;
F_26 ( L_1 , V_45 ) ;
F_22 ( V_44 , V_11 , V_45 ) ;
V_45 = F_2 ( V_11 -> V_58 + V_6 , ' ' , & V_5 , & V_6 , FALSE ) ;
F_26 ( L_2 , V_45 ) ;
F_24 ( V_44 , V_11 , V_45 ) ;
F_2 ( V_11 -> V_58 + V_6 , ' ' , & V_5 , & V_6 , FALSE ) ;
V_45 = F_2 ( V_11 -> V_58 + V_6 , ' ' , & V_5 , & V_6 , FALSE ) ;
F_26 ( L_3 , V_45 ) ;
F_22 ( V_44 , V_11 , V_45 ) ;
V_45 = F_2 ( V_11 -> V_58 + V_6 , ' ' , & V_5 , & V_6 , FALSE ) ;
F_26 ( L_4 , V_45 ) ;
F_24 ( V_44 , V_11 , V_45 ) ;
V_11 -> V_47 . V_57 = TRUE ;
}
static T_1 F_27 ( T_6 * V_44 , char * line )
{
T_8 V_59 = V_60 ;
char * V_61 ;
char * V_62 ;
char * V_22 ;
int V_5 ;
int V_6 = 0 ;
V_61 = F_2 ( line , ' ' , & V_5 , & V_6 , FALSE ) ;
if ( V_61 == NULL ) {
return FALSE ;
}
if ( strncmp ( V_61 , L_5 , 3 ) == 0 ) {
V_59 = V_63 ;
}
else if ( strncmp ( V_61 , L_6 , 5 ) == 0 ) {
V_59 = V_64 ;
}
else if ( strncmp ( V_61 , L_7 , 7 ) == 0 ) {
V_59 = V_65 ;
}
else {
return FALSE ;
}
V_62 = F_2 ( line + V_6 , ' ' , & V_5 , & V_6 , TRUE ) ;
if ( V_62 == NULL ) {
return FALSE ;
}
V_22 = F_2 ( line + V_6 , ' ' , & V_5 , & V_6 , TRUE ) ;
if ( V_22 == NULL ) {
return FALSE ;
}
switch ( V_59 ) {
case V_63 :
if ( strcmp ( V_62 , L_8 ) == 0 ) {
V_44 -> V_66 = V_22 ;
V_44 -> V_67 = F_28 ( V_22 ) ;
F_26 ( L_9 ,
V_44 -> V_66 , V_44 -> V_67 ) ;
}
F_29 ( V_44 -> V_68 , V_62 , V_22 ) ;
break;
case V_64 :
F_29 ( V_44 -> V_50 , V_62 , V_22 ) ;
break;
case V_65 :
F_29 ( V_44 -> V_55 , V_62 , V_22 ) ;
break;
default:
return FALSE ;
}
return FALSE ;
}
static T_5 F_30 ( T_9 V_69 )
{
T_5 V_70 = 0 , V_71 = 0 ;
const char * V_72 = ( const char * ) V_69 ;
char V_73 = V_72 [ V_71 ] ;
while ( V_73 != '\0' ) {
V_70 += ( int ) V_73 ;
V_73 = V_72 [ ++ V_71 ] ;
}
return V_70 ;
}
static T_1 F_31 ( T_9 V_74 , T_9 V_75 )
{
const char * V_76 = ( const char * ) V_74 ;
const char * V_77 = ( const char * ) V_75 ;
return ( strcmp ( V_76 , V_77 ) == 0 ) ;
}
static T_1 F_32 ( T_6 * V_44 , char * line )
{
char * V_1 ;
char * V_78 , * V_79 ;
int V_5 = 0 , V_6 = 0 ;
int V_71 ;
if ( strncmp ( line , L_10 , 18 ) != 0 ) {
return FALSE ;
}
V_1 = line + 18 ;
V_78 = F_2 ( V_1 , ' ' , & V_5 , & V_6 , TRUE ) ;
for ( V_71 = 0 ; V_78 [ V_71 ] != '\0' ; V_71 ++ ) {
V_78 [ V_71 ] = F_33 ( V_78 [ V_71 ] ) ;
}
V_79 = F_2 ( V_1 + V_6 , ' ' , & V_5 , & V_6 , TRUE ) ;
F_29 ( V_44 -> V_80 , V_78 , V_79 ) ;
return FALSE ;
}
char * F_34 ( T_6 * V_44 , char * V_81 )
{
static char V_82 [ 512 ] ;
int V_5 = ( int ) strlen ( V_81 ) ;
int V_6 = 0 ;
F_26 ( L_11 , V_81 ) ;
char * V_83 = F_2 ( V_81 , ',' , & V_5 , & V_6 , FALSE ) ;
if ( * V_83 != '\0' ) {
T_5 V_71 ;
for ( V_71 = 0 ; V_83 [ V_71 ] != '\0' ; V_71 ++ ) {
V_83 [ V_71 ] = F_33 ( V_83 [ V_71 ] ) ;
}
char * V_84 ;
V_84 = ( char * ) F_35 ( V_44 -> V_80 , V_83 ) ;
F_36 ( V_82 , 512 , L_12 , V_84 , V_81 + V_5 + 1 ) ;
return V_82 ;
}
return L_13 ;
}
void F_37 ( T_6 * V_44 , T_2 * V_11 ,
T_5 * V_85 ,
T_5 * V_86 )
{
V_44 -> V_87 ++ ;
* V_85 = V_44 -> V_87 ;
if ( V_11 != NULL ) {
* V_86 = ++ V_11 -> V_88 ;
}
}
static T_1 F_38 ( T_7 V_69 ,
T_7 V_22 ,
T_7 T_10 V_89 )
{
char * V_72 = ( char * ) V_69 ;
char * V_90 = ( char * ) V_22 ;
F_39 ( V_72 ) ;
F_39 ( V_90 ) ;
return TRUE ;
}
static T_1 F_40 ( T_6 * V_44 , char * line , const char * V_91 , int V_92 )
{
int V_5 ;
int V_6 = 0 ;
char * V_93 ;
char * V_94 = F_2 ( line , ' ' , & V_5 , & V_6 , FALSE ) ;
if ( strlen ( V_94 ) == 0 ) {
return FALSE ;
}
if ( strncmp ( V_94 , L_14 , 7 ) != 0 ) {
return FALSE ;
}
V_93 = F_2 ( line + V_6 , ' ' , & V_5 , & V_6 , FALSE ) ;
if ( * V_93 != '\0' ) {
T_11 * V_95 ;
char V_96 [ 512 ] ;
T_1 V_97 = FALSE ;
if ( strncmp ( V_93 , L_15 , 10 ) == 0 ) {
if ( V_44 -> V_67 ) {
F_36 ( V_96 , 512 , L_16 ,
V_44 -> V_66 ,
V_98 ,
V_93 + 10 ) ;
}
else {
F_36 ( V_96 , 512 , L_17 ,
V_91 ,
V_98 ,
V_44 -> V_66 ,
V_98 ,
V_93 + 10 ) ;
}
V_97 = TRUE ;
}
else {
if ( ! F_28 ( V_93 ) ) {
F_36 ( V_96 , 512 , L_18 , V_91 , V_93 ) ;
}
else {
F_41 ( V_96 , V_93 , 512 ) ;
}
}
F_26 ( L_19 , V_96 ) ;
V_95 = F_42 ( V_96 , L_20 ) ;
if ( V_95 == NULL ) {
F_26 ( L_21 , V_96 ) ;
return FALSE ;
}
if ( V_97 ) {
V_44 -> V_99 ++ ;
}
F_43 ( V_44 , V_95 , V_96 , V_91 , V_92 + 1 ) ;
fclose ( V_95 ) ;
return TRUE ;
}
return FALSE ;
}
static void F_44 ( T_2 * V_11 , char * V_100 , int V_101 , int V_102 , int V_103 )
{
static char V_52 [ 1024 ] , V_22 [ 1024 ] ;
V_52 [ 0 ] = '\0' ;
V_22 [ 0 ] = '\0' ;
T_4 V_104 = 0 ;
T_12 V_105 = 0 ;
T_4 V_106 = 0 ;
if ( V_103 != 0 ) {
F_36 ( V_52 , V_103 - V_101 , L_22 , V_100 + V_101 ) ;
if ( V_100 [ V_103 ] == ' ' ) {
V_106 = 1 ;
}
F_36 ( V_22 , V_102 - V_106 - V_103 , L_22 ,
V_100 + V_103 + V_106 ) ;
V_104 = ( T_4 ) strlen ( V_22 ) ;
}
else {
F_36 ( V_52 , V_102 - V_101 , L_22 , V_100 + V_101 ) ;
}
F_45 ( V_22 , ( const V_107 * * ) & V_22 [ V_104 ] , & V_105 ) ;
if ( V_52 [ 0 ] == '\0' ) {
return;
}
if ( strcmp ( V_52 , L_23 ) == 0 ) {
V_11 -> V_108 = F_5 ( V_22 ) ;
}
else if ( strcmp ( V_52 , L_24 ) == 0 ) {
V_11 -> V_109 = V_105 ;
}
else if ( strcmp ( V_52 , L_25 ) == 0 ) {
V_105 = V_11 -> V_110 ;
}
else if ( strcmp ( V_52 , L_26 ) == 0 ) {
int V_111 = 0 ;
if ( V_104 < 3 ) {
return;
}
if ( V_22 [ 0 ] == '!' ) {
V_111 = 1 ;
if ( V_104 < 4 ) {
return;
}
}
V_22 [ V_102 - V_103 - V_106 - 2 ] = '\0' ;
F_4 ( V_11 , V_22 + V_111 + 1 , V_111 == 1 ) ;
}
else if ( strcmp ( V_52 , L_27 ) == 0 ) {
int V_111 = 0 ;
if ( V_104 < 3 ) {
return;
}
if ( V_22 [ 0 ] == '!' ) {
V_111 = 1 ;
if ( V_104 < 4 ) {
return;
}
}
V_22 [ V_102 - V_103 - V_106 - 2 ] = '\0' ;
F_17 ( V_11 , V_22 + V_111 + 1 , V_111 == 1 ) ;
}
else if ( strcmp ( V_52 , L_28 ) == 0 ) {
F_18 ( V_11 ) ;
}
else if ( strcmp ( V_52 , L_29 ) == 0 ) {
int V_111 = 0 ;
if ( V_104 < 3 ) {
return;
}
V_22 [ V_102 - V_103 - V_106 - 2 ] = '\0' ;
F_19 ( V_11 , V_22 + V_111 + 1 ) ;
}
else if ( strcmp ( V_52 , L_30 ) == 0 ) {
F_6 ( V_11 ) ;
}
else if ( strcmp ( V_52 , L_31 ) == 0 ) {
F_7 ( V_11 , V_105 ) ;
}
else if ( strcmp ( V_52 , L_32 ) == 0 ) {
F_8 ( V_11 , V_105 ) ;
}
else if ( strcmp ( V_52 , L_33 ) == 0 ) {
F_10 ( V_11 , V_105 ) ;
}
else if ( strcmp ( V_52 , L_34 ) == 0 ) {
F_9 ( V_11 , V_105 ) ;
}
else if ( strcmp ( V_52 , L_35 ) == 0 ) {
F_11 ( V_11 ) ;
}
else if ( strcmp ( V_52 , L_36 ) == 0 ) {
F_13 ( V_11 ) ;
}
else if ( strcmp ( V_52 , L_37 ) == 0 ) {
F_14 ( V_11 ) ;
}
else if ( strcmp ( V_52 , L_38 ) == 0 ) {
F_15 ( V_11 ) ;
}
else if ( strcmp ( V_52 , L_39 ) == 0 ) {
F_16 ( V_11 ) ;
}
else if ( strcmp ( V_52 , L_40 ) == 0 ) {
F_12 ( V_11 ) ;
}
else if ( strcmp ( V_52 , L_41 ) == 0 ) {
F_20 ( V_11 , V_22 ) ;
}
else if ( strcmp ( V_52 , L_42 ) == 0 ) {
F_21 ( V_11 , V_22 ) ;
}
else {
}
}
static T_1 F_46 ( T_6 * V_44 , char * line , const char * V_112 , int V_113 , int V_114 )
{
char * V_115 ;
char * V_100 ;
T_1 V_116 = FALSE ;
int V_117 = 0 , V_118 = 0 , V_103 = 0 ;
char V_73 ;
int V_5 = 0 ;
T_2 * V_11 = NULL ;
if ( strncmp ( line , L_43 , 6 ) != 0 ) {
return FALSE ;
}
V_11 = ( T_2 * ) F_47 ( sizeof( T_2 ) ) ;
F_26 ( L_44 , line ) ;
memset ( V_11 , 0 , sizeof( T_2 ) ) ;
V_11 -> V_58 = F_5 ( line ) ;
V_11 -> V_119 = F_5 ( V_112 ) ;
V_11 -> V_113 = V_113 ;
V_11 -> V_120 = F_2 ( line + 6 , ' ' , & V_5 , & V_5 , TRUE ) ;
V_115 = strstr ( line , L_45 ) ;
if ( V_115 == NULL ) {
F_26 ( L_46 ) ;
return FALSE ;
}
V_118 = ( int ) ( V_115 - line ) + 1 ;
if ( line [ V_114 - 1 ] != ')' ) {
F_39 ( V_11 ) ;
return FALSE ;
}
else {
line [ V_114 - 1 ] = ';' ;
}
while ( line [ V_118 ] == ' ' ) V_118 ++ ;
V_100 = & line [ V_118 ] ;
V_118 = 0 ;
while ( ( V_73 = V_100 [ V_118 ++ ] ) ) {
if ( V_73 == '"' ) {
V_116 = ! V_116 ;
}
if ( ! V_116 ) {
if ( V_73 == ':' ) {
V_103 = V_118 ;
}
if ( V_73 == ';' ) {
F_44 ( V_11 , V_100 , V_117 , V_118 , V_103 ) ;
while ( V_100 [ V_118 ] == ' ' ) V_118 ++ ;
V_117 = V_118 ;
V_103 = 0 ;
V_116 = FALSE ;
}
}
}
F_29 ( V_44 -> V_121 , F_48 ( ( T_5 ) V_11 -> V_109 ) , V_11 ) ;
return TRUE ;
}
static T_1 F_49 ( T_7 V_69 V_89 ,
T_7 V_22 ,
T_7 T_10 V_89 )
{
T_2 * V_11 = ( T_2 * ) V_22 ;
unsigned int V_71 ;
F_26 ( L_47 , V_22 ) ;
F_39 ( V_11 -> V_58 ) ;
F_39 ( V_11 -> V_119 ) ;
F_39 ( V_11 -> V_108 ) ;
F_39 ( V_11 -> V_39 ) ;
F_39 ( V_11 -> V_120 ) ;
for ( V_71 = 0 ; V_71 < V_11 -> V_14 ; V_71 ++ ) {
F_39 ( V_11 -> V_17 [ V_71 ] . V_18 ) ;
F_39 ( V_11 -> V_17 [ V_71 ] . V_122 ) ;
}
for ( V_71 = 0 ; V_71 < V_11 -> V_41 ; V_71 ++ ) {
F_39 ( V_11 -> V_43 [ V_71 ] ) ;
}
F_26 ( L_48 , V_11 ) ;
F_39 ( V_11 ) ;
return TRUE ;
}
static void F_43 ( T_6 * V_44 , T_11 * V_123 ,
const char * V_112 , const char * V_124 , int V_92 )
{
#define F_50 4096
char line [ F_50 ] ;
int V_113 = 0 ;
F_26 ( L_49 , V_112 , V_92 ) ;
if ( V_92 > V_125 ) {
return;
}
while ( fgets ( line , F_50 , V_123 ) ) {
int V_114 ;
++ V_113 ;
if ( ( line [ 0 ] == '\0' ) || ( line [ 0 ] == '#' ) ) {
continue;
}
V_114 = ( int ) strlen ( line ) ;
while ( V_114 && ( ( line [ V_114 - 1 ] == '\n' ) || ( line [ V_114 - 1 ] == '\r' ) ) ) {
-- V_114 ;
}
line [ V_114 ] = '\0' ;
if ( V_114 == 0 ) {
continue;
}
if ( F_27 ( V_44 , line ) ) {
continue;
}
if ( F_32 ( V_44 , line ) ) {
continue;
}
if ( F_40 ( V_44 , line , V_124 , V_92 ) ) {
continue;
}
if ( F_46 ( V_44 , line , V_112 , V_113 , V_114 ) ) {
V_44 -> V_126 ++ ;
continue;
}
}
}
void F_51 ( T_6 * * V_44 , const char * V_127 )
{
V_107 * V_124 ;
V_107 * V_128 ;
T_11 * V_123 ;
F_26 ( L_50 , V_127 ) ;
* V_44 = ( T_6 * ) F_47 ( sizeof( T_6 ) ) ;
memset ( * V_44 , 0 , sizeof( T_6 ) ) ;
( * V_44 ) -> V_121 = F_52 ( V_129 , V_130 ) ;
( * V_44 ) -> V_80 = F_52 ( F_30 , F_31 ) ;
( * V_44 ) -> V_68 = F_52 ( F_30 , F_31 ) ;
( * V_44 ) -> V_50 = F_52 ( F_30 , F_31 ) ;
( * V_44 ) -> V_55 = F_52 ( F_30 , F_31 ) ;
V_124 = F_53 ( V_127 ) ;
V_128 = F_54 ( V_127 ) ;
V_123 = F_42 ( V_127 , L_20 ) ;
if ( V_123 == NULL ) {
F_26 ( L_21 , V_127 ) ;
return;
}
F_43 ( * V_44 , V_123 , V_127 , V_124 , 1 ) ;
F_39 ( V_124 ) ;
F_39 ( V_128 ) ;
fclose ( V_123 ) ;
}
void F_55 ( T_6 * * V_44 )
{
F_26 ( L_51 ) ;
F_56 ( ( * V_44 ) -> V_121 , F_49 , NULL ) ;
F_57 ( ( * V_44 ) -> V_121 ) ;
F_56 ( ( * V_44 ) -> V_80 , F_38 , NULL ) ;
F_57 ( ( * V_44 ) -> V_80 ) ;
F_56 ( ( * V_44 ) -> V_68 , F_38 , NULL ) ;
F_57 ( ( * V_44 ) -> V_68 ) ;
F_56 ( ( * V_44 ) -> V_50 , F_38 , NULL ) ;
F_57 ( ( * V_44 ) -> V_50 ) ;
F_56 ( ( * V_44 ) -> V_55 , F_38 , NULL ) ;
F_57 ( ( * V_44 ) -> V_55 ) ;
F_39 ( * V_44 ) ;
* V_44 = NULL ;
}
T_2 * F_58 ( T_6 * V_44 , T_12 V_109 )
{
if ( ( V_44 == NULL ) || ( V_44 -> V_121 == NULL ) ) {
return NULL ;
}
else {
return ( T_2 * ) F_35 ( V_44 -> V_121 , F_48 ( V_109 ) ) ;
}
}
void F_59 ( T_6 * V_44 , unsigned int V_109 ,
unsigned int * V_131 , unsigned int * V_132 ,
unsigned int * V_133 , unsigned int * V_134 )
{
* V_131 = V_44 -> V_99 ;
* V_132 = V_44 -> V_126 ;
* V_133 = V_44 -> V_87 ;
T_2 * V_11 ;
V_11 = F_58 ( V_44 , V_109 ) ;
if ( V_11 ) {
* V_134 = V_11 -> V_88 ;
}
else {
* V_134 = 0 ;
}
}
static void F_60 ( T_7 V_69 V_89 ,
T_7 V_22 ,
T_7 T_10 V_89 )
{
T_2 * V_11 = ( T_2 * ) V_22 ;
V_11 -> V_88 = 0 ;
}
void F_61 ( T_6 * V_44 )
{
if ( V_44 == NULL ) {
return;
}
V_44 -> V_87 = 0 ;
F_62 ( V_44 -> V_121 , F_60 , NULL ) ;
}
static unsigned char F_63 ( char V_73 )
{
static unsigned char V_135 [ 256 ] ;
static T_1 V_136 = FALSE ;
if ( ! V_136 ) {
unsigned char V_137 ;
for ( V_137 = 'a' ; V_137 <= 'f' ; V_137 ++ ) {
V_135 [ V_137 ] = 0xa + ( V_137 - 'a' ) ;
}
for ( V_137 = 'A' ; V_137 <= 'F' ; V_137 ++ ) {
V_135 [ V_137 ] = 0xa + ( V_137 - 'A' ) ;
}
for ( V_137 = '0' ; V_137 <= '9' ; V_137 ++ ) {
V_135 [ V_137 ] = ( V_137 - '0' ) ;
}
V_136 = TRUE ;
}
return V_135 [ ( unsigned char ) V_73 ] ;
}
T_5 F_64 ( T_3 * V_138 )
{
int V_139 = 0 ;
T_1 V_140 = FALSE ;
T_1 V_141 = FALSE ;
unsigned char V_142 = 0 ;
char V_73 ;
int V_71 ;
T_1 V_143 = FALSE ;
static V_107 V_144 [ 1024 ] ;
if ( V_138 -> V_145 ) {
return V_138 -> V_146 ;
}
for ( V_71 = 0 ; V_138 -> V_18 [ V_71 ] != '\0' ; V_71 ++ ) {
V_73 = V_138 -> V_18 [ V_71 ] ;
if ( V_73 == '|' ) {
V_140 = ! V_140 ;
continue;
}
if ( ! V_140 ) {
if ( ! V_143 ) {
if ( V_73 == '\\' ) {
V_143 = TRUE ;
continue;
}
else {
V_144 [ V_139 ++ ] = ( unsigned char ) V_73 ;
}
}
else {
V_143 = 0 ;
V_144 [ V_139 ++ ] = ( unsigned char ) V_73 ;
}
}
else {
if ( V_73 == ' ' ) {
continue;
}
else {
unsigned char V_147 = F_63 ( V_73 ) ;
if ( ! V_141 ) {
V_142 = V_147 ;
V_141 = TRUE ;
}
else {
V_144 [ V_139 ++ ] = ( V_142 << 4 ) + V_147 ;
V_141 = FALSE ;
}
}
}
}
V_138 -> V_122 = ( V_148 * ) F_47 ( V_139 + 1 ) ;
memcpy ( V_138 -> V_122 , V_144 , V_139 + 1 ) ;
V_138 -> V_145 = TRUE ;
V_138 -> V_146 = V_139 ;
return V_139 ;
}
T_1 F_65 ( T_3 * V_138 )
{
T_5 V_149 , V_150 , V_151 = 0 ;
if ( V_138 -> V_122 ) {
return TRUE ;
}
V_149 = ( T_5 ) strlen ( V_138 -> V_18 ) ;
if ( V_149 < 3 ) {
return FALSE ;
}
if ( V_149 >= 512 ) {
return FALSE ;
}
if ( V_138 -> V_18 [ 0 ] != '/' ) {
return FALSE ;
}
for ( V_150 = V_149 - 1 ; V_150 > 2 ; V_150 -- ) {
if ( V_138 -> V_18 [ V_150 ] == '/' ) {
V_151 = V_150 ;
break;
}
else {
switch ( V_138 -> V_18 [ V_150 ] ) {
case 'i' :
V_138 -> V_152 = TRUE ;
break;
case 's' :
V_138 -> V_153 = TRUE ;
break;
case 'B' :
V_138 -> V_154 = TRUE ;
break;
case 'm' :
V_138 -> V_155 = TRUE ;
break;
default:
F_26 ( L_52 , V_138 -> V_18 [ V_150 ] ) ;
break;
}
}
}
if ( V_151 == 0 ) {
return FALSE ;
}
V_138 -> V_122 = ( V_148 * ) F_47 ( V_151 ) ;
memcpy ( V_138 -> V_122 , V_138 -> V_18 + 1 , V_151 - 1 ) ;
V_138 -> V_122 [ V_151 - 1 ] = '\0' ;
V_138 -> V_145 = TRUE ;
V_138 -> V_146 = V_151 - 1 ;
return TRUE ;
}
