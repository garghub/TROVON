int
F_1 ( T_1 * V_1 , int * V_2 , T_2 * * T_3 V_3 )
{
T_4 V_4 = 0 ;
T_5 V_5 ;
T_6 V_6 ;
T_7 V_7 = 0 ;
T_8 * V_8 ;
static T_2 V_9 [ V_10 ] ;
static T_9 V_11 = FALSE ;
V_12 = 0 ;
F_2 ( V_1 -> V_13 , & V_4 , & V_7 , V_9 ,
sizeof V_9 ) ;
if ( ( ( V_14 ) V_7 < strlen ( V_15 ) ) ||
V_7 >= V_16 ) {
return 0 ;
}
if ( memcmp ( V_15 , V_9 , strlen ( V_15 ) ) != 0 ) {
return 0 ;
}
if ( ! V_11 ) {
F_3 () ;
V_11 = TRUE ;
}
V_8 = F_4 ( T_8 , 1 ) ;
memset ( ( void * ) V_8 , '\0' , sizeof( T_8 ) ) ;
F_5 ( V_8 -> V_17 , V_9 , V_7 + 1 ) ;
V_8 -> V_7 = V_7 ;
F_2 ( V_1 -> V_13 , & V_4 , & ( V_8 -> V_18 ) ,
V_9 , sizeof V_9 ) ;
if ( ( V_8 -> V_18 >= V_19 ) ||
( ! F_6 ( V_9 , & V_5 , & V_6 ) ) ) {
F_7 ( V_8 ) ;
return 0 ;
}
V_8 -> V_20 = V_5 ;
V_8 -> V_21 = V_6 ;
F_5 ( V_8 -> V_22 , V_9 , V_8 -> V_18 + 1 ) ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
V_1 -> V_29 = V_30 ;
V_1 -> V_31 = V_32 ;
V_1 -> V_33 = V_34 ;
V_8 -> V_35 =
F_8 ( V_36 , V_37 ) ;
V_1 -> V_38 = ( void * ) V_8 ;
* V_2 = V_12 ;
return 1 ;
}
static T_9
V_28 ( T_1 * V_1 , int * V_2 , T_2 * * T_3 V_3 ,
T_4 * V_39 )
{
T_4 V_4 = F_9 ( V_1 -> V_13 ) ;
long V_40 , V_41 , V_42 ;
T_10 V_43 ;
int V_44 ;
T_8 * V_8 =
( T_8 * ) V_1 -> V_38 ;
if ( ! V_8 ) {
return FALSE ;
}
while ( 1 ) {
int V_45 , V_46 , V_47 , V_48 ;
int V_49 = FALSE ;
T_4 V_50 = V_4 ;
static T_2 V_9 [ V_10 + 1 ] ;
T_2 V_51 [ V_52 ] ;
T_2 V_53 [ V_54 ] ;
T_11 V_55 ;
T_2 V_56 [ V_57 + 1 ] ;
T_2 V_58 [ V_59 + 1 ] ;
T_2 V_60 [ V_61 + 1 ] ;
if ( F_9 ( V_1 -> V_13 ) == 0 ) {
V_50 += ( V_8 -> V_7 + 1 +
V_8 -> V_18 + 1 ) ;
}
V_12 = 0 ;
if ( F_2 ( V_1 -> V_13 , & V_4 , & V_45 , V_9 ,
sizeof V_9 ) == FALSE ) {
break;
}
if ( F_10 ( V_9 , V_45 , & V_46 , & V_47 ,
& V_41 , & V_42 ,
& V_40 ,
& V_48 , & V_43 , & V_44 , & V_49 ,
V_51 ,
V_53 , & V_55 ,
V_56 , V_58 , V_60 ) ) {
T_11 * V_62 ;
int V_63 ;
int V_64 = 0 ;
T_12 * V_65 ;
char V_66 [ V_67 + 1 ] ;
T_4 * V_68 = NULL ;
F_11 ( V_66 , V_67 , L_1 , V_46 , V_47 / 100 ) ;
V_1 -> V_69 . V_70 = V_71 ;
V_1 -> V_69 . V_72 = V_26 ;
* V_39 = V_50 ;
V_1 -> V_69 . V_73 . V_74 = V_8 -> V_20 + V_46 ;
if ( ( V_8 -> V_21 + V_47 ) >= 1000000 ) {
V_1 -> V_69 . V_73 . V_74 ++ ;
}
V_1 -> V_69 . V_73 . V_75 =
( ( V_8 -> V_21 + V_47 ) % 1000000 ) * 1000 ;
F_12 ( V_1 -> V_62 ,
strlen ( V_53 ) + 1 +
1 +
strlen ( V_66 ) + 1 +
strlen ( V_58 ) + 1 +
strlen ( V_60 ) + 1 +
strlen ( V_56 ) + 1 +
1 +
1 +
( V_49 ? V_48 : ( V_48 / 2 ) ) ) ;
V_62 = F_13 ( V_1 -> V_62 ) ;
V_64 = F_14 ( V_62 , V_66 ,
V_43 , V_44 , V_53 ,
V_55 ,
V_56 , V_58 ,
V_60 ) ;
V_1 -> V_69 . V_76 = V_64 + ( V_49 ? V_48 : ( V_48 / 2 ) ) ;
V_1 -> V_69 . V_77 = V_64 + ( V_49 ? V_48 : ( V_48 / 2 ) ) ;
if ( ! V_49 ) {
for ( V_63 = 0 ; V_63 <= V_48 ; V_63 += 2 ) {
V_62 [ V_64 + V_63 / 2 ] =
F_15 ( V_9 + V_40 + V_63 ) ;
}
}
else {
for ( V_63 = 0 ; V_63 <= V_48 ; V_63 ++ ) {
V_62 [ V_64 + V_63 ] = V_9 [ V_40 + V_63 ] ;
}
}
V_65 = F_4 ( T_12 , 1 ) ;
V_65 -> V_78 = F_16 ( V_41 + 2 ) ;
F_5 ( V_65 -> V_78 , V_9 , V_41 + 1 ) ;
V_65 -> V_78 [ V_41 + 1 ] = '\0' ;
if ( ( ( V_14 ) ( V_40 - V_42 - 1 ) == strlen ( L_2 ) ) &&
( strncmp ( V_9 + V_42 , L_2 , strlen ( L_2 ) ) == 0 ) ) {
V_65 -> V_79 = NULL ;
}
else {
V_65 -> V_79 = F_16 ( V_40 - V_42 ) ;
F_5 ( V_65 -> V_79 , V_9 + V_42 ,
V_40 - V_42 ) ;
V_65 -> V_79 [ V_40 - V_42 - 1 ] = '\0' ;
}
V_68 = F_16 ( sizeof( * V_68 ) ) ;
* V_68 = V_50 ;
F_17 ( V_8 -> V_35 , V_68 , V_65 ) ;
F_18 ( V_1 , V_44 , V_50 , & V_1 -> V_80 ,
V_43 , V_51 ) ;
* V_2 = V_12 ;
return TRUE ;
}
}
* V_2 = V_12 ;
return FALSE ;
}
static T_9
V_30 ( T_1 * V_1 , T_4 V_81 ,
union V_82 * V_80 , T_11 * V_83 ,
int V_84 , int * V_2 , T_2 * * T_3 )
{
T_4 V_4 = 0 ;
long V_40 , V_41 , V_42 ;
static T_2 V_9 [ V_10 + 1 ] ;
T_2 V_51 [ V_52 ] ;
T_2 V_53 [ V_54 ] ;
T_11 V_55 ;
T_2 V_56 [ V_57 + 1 ] ;
T_2 V_58 [ V_59 + 1 ] ;
T_2 V_60 [ V_61 + 1 ] ;
int V_49 = FALSE ;
T_10 V_43 ;
int V_44 ;
int V_46 , V_47 , V_48 ;
* V_2 = V_12 = 0 ;
if ( F_19 ( V_1 -> V_85 , V_81 , V_86 , V_2 ) == - 1 ) {
return FALSE ;
}
if ( F_2 ( V_1 -> V_85 , & V_4 , & V_84 , V_9 ,
sizeof V_9 ) == FALSE ) {
return FALSE ;
}
if ( F_10 ( V_9 , V_84 , & V_46 , & V_47 ,
& V_41 , & V_42 ,
& V_40 ,
& V_48 , & V_43 , & V_44 , & V_49 ,
V_51 ,
V_53 , & V_55 ,
V_56 , V_58 , V_60 ) ) {
int V_63 ;
int V_64 = 0 ;
char V_66 [ V_67 + 1 ] ;
F_11 ( V_66 , V_67 , L_1 , V_46 , V_47 / 100 ) ;
V_1 -> V_69 . V_72 = V_26 ;
V_64 = F_14 ( V_83 , V_66 ,
V_43 , V_44 , V_53 ,
V_55 ,
V_56 , V_58 ,
V_60 ) ;
if ( ! V_49 ) {
for ( V_63 = 0 ; V_63 <= V_48 ; V_63 += 2 ) {
V_83 [ V_64 + V_63 / 2 ] = F_15 ( V_9 + V_40 + V_63 ) ;
}
}
else {
for ( V_63 = 0 ; V_63 <= V_48 ; V_63 ++ ) {
V_83 [ V_64 + V_63 ] = V_9 [ V_40 + V_63 ] ;
}
}
F_18 ( V_1 , V_44 , V_81 , V_80 , V_43 ,
V_51 ) ;
* V_2 = V_12 = 0 ;
return TRUE ;
}
* V_2 = V_12 ;
* T_3 = F_20 ( L_3
L_4 V_87 L_5 ,
V_81 ) ;
return FALSE ;
}
static void
V_32 ( T_1 * V_1 )
{
T_8 * V_8 =
( T_8 * ) V_1 -> V_38 ;
if ( ! V_8 ) {
return;
}
F_21 ( V_8 -> V_35 ,
V_88 , NULL ) ;
F_22 ( V_8 -> V_35 ) ;
}
T_9
F_23 ( T_13 * V_89 , int * V_2 V_3 )
{
V_89 -> V_90 = V_91 ;
return TRUE ;
}
int
F_24 ( int V_44 )
{
switch ( V_44 ) {
case V_26 :
return 0 ;
default:
return V_92 ;
}
}
static T_9
V_91 ( T_13 * V_89 , const struct V_93 * V_69 ,
const union V_82 * V_80 ,
const T_11 * V_83 , int * V_2 )
{
T_6 V_63 ;
T_12 * V_94 = NULL ;
T_2 V_95 [ 16 ] ;
T_9 V_49 ;
T_14 * V_96 ;
T_8 * V_8 =
( T_8 * ) V_80 -> V_96 . V_1 -> V_38 ;
V_96 = ( T_14 * ) V_89 -> V_38 ;
if ( V_96 == NULL ) {
if ( ! F_25 ( V_89 , V_8 -> V_17 ,
V_8 -> V_7 , V_2 ) ) {
return FALSE ;
}
if ( ! F_25 ( V_89 , L_6 , 1 , V_2 ) ) {
return FALSE ;
}
if ( ! F_25 ( V_89 , V_8 -> V_22 ,
V_8 -> V_18 , V_2 ) ) {
return FALSE ;
}
if ( ! F_25 ( V_89 , L_6 , 1 , V_2 ) ) {
return FALSE ;
}
V_96 = ( T_14 * ) F_16 ( sizeof( T_14 ) ) ;
V_89 -> V_38 = ( void * ) V_96 ;
V_96 -> V_97 . V_74 = V_8 -> V_20 ;
V_96 -> V_97 . V_75 =
( V_8 -> V_21 * 1000 ) ;
V_96 -> V_98 = TRUE ;
}
V_94 = ( T_12 * ) F_26 ( V_8 -> V_35 ,
( const void * ) & ( V_80 -> V_96 . V_81 ) ) ;
if ( ! F_25 ( V_89 , V_94 -> V_78 ,
strlen ( V_94 -> V_78 ) , V_2 ) ) {
return FALSE ;
}
V_49 = ( strstr ( V_94 -> V_78 , L_7 ) != NULL ) ;
if ( V_69 -> V_73 . V_75 >= V_96 -> V_97 . V_75 ) {
F_11 ( V_95 , 16 , L_8 ,
( long ) ( V_69 -> V_73 . V_74 - V_96 -> V_97 . V_74 ) ,
( V_69 -> V_73 . V_75 - V_96 -> V_97 . V_75 ) / 100000 ) ;
}
else {
F_11 ( V_95 , 16 , L_9 ,
( long ) ( V_69 -> V_73 . V_74 - V_96 -> V_97 . V_74 - 1 ) ,
( ( 1000000000 + ( V_69 -> V_73 . V_75 / 100000 ) ) - ( V_96 -> V_97 . V_75 / 100000 ) ) % 10000 ) ;
}
if ( ! F_25 ( V_89 , V_95 , strlen ( V_95 ) , V_2 ) ) {
return FALSE ;
}
if ( V_94 -> V_79 == NULL ) {
if ( ! F_25 ( V_89 , L_2 , strlen ( L_2 ) , V_2 ) ) {
return FALSE ;
}
}
else {
if ( ! F_25 ( V_89 , V_94 -> V_79 ,
strlen ( V_94 -> V_79 ) , V_2 ) ) {
return FALSE ;
}
}
for ( V_63 = 0 ; V_83 [ V_63 ] != '\0' ; V_63 ++ ) ;
V_63 ++ ;
V_63 ++ ;
for (; V_83 [ V_63 ] != '\0' ; V_63 ++ ) ;
V_63 ++ ;
for (; V_83 [ V_63 ] != '\0' ; V_63 ++ ) ;
V_63 ++ ;
for (; V_83 [ V_63 ] != '\0' ; V_63 ++ ) ;
V_63 ++ ;
for (; V_83 [ V_63 ] != '\0' ; V_63 ++ ) ;
V_63 ++ ;
V_63 += 2 ;
if ( ! F_25 ( V_89 , L_10 , 1 , V_2 ) ) {
return FALSE ;
}
if ( ! V_49 ) {
for (; V_63 < V_69 -> V_76 ; V_63 ++ ) {
T_2 V_99 [ 2 ] ;
V_99 [ 0 ] = F_27 ( ( T_11 ) ( V_83 [ V_63 ] >> 4 ) ) ;
V_99 [ 1 ] = F_27 ( ( T_11 ) ( V_83 [ V_63 ] & 0x0f ) ) ;
if ( ! F_25 ( V_89 , V_99 , 2 , V_2 ) ) {
return FALSE ;
}
}
}
else {
for (; V_63 < V_69 -> V_76 ; V_63 ++ ) {
char V_99 [ 1 ] ;
V_99 [ 0 ] = V_83 [ V_63 ] ;
if ( ! F_25 ( V_89 , V_99 , 1 , V_2 ) ) {
return FALSE ;
}
}
}
if ( ! F_25 ( V_89 , L_6 , 1 , V_2 ) ) {
return FALSE ;
}
return TRUE ;
}
static T_9
F_2 ( T_15 V_13 , T_4 * V_4 , T_7 * V_84 ,
T_2 * V_9 , V_14 V_100 )
{
T_4 V_101 = F_9 ( V_13 ) ;
char * V_102 = F_28 ( V_9 , ( int ) V_100 - 1 , V_13 ) ;
if ( V_102 == NULL ) {
return FALSE ;
}
* V_84 = ( T_7 ) ( F_9 ( V_13 ) - V_101 ) ;
* V_4 = * V_4 + * V_84 ;
if ( V_9 [ * V_84 - 1 ] == '\n' ) {
V_9 [ * V_84 - 1 ] = '\0' ;
* V_84 = * V_84 - 1 ;
}
return TRUE ;
}
static T_9
F_10 ( T_2 * V_9 , T_7 V_45 ,
T_7 * V_46 , T_7 * V_47 ,
long * V_41 , long * V_42 ,
long * V_39 , T_7 * V_48 ,
T_10 * V_43 ,
int * V_44 , int * V_49 ,
T_2 * V_51 ,
T_2 * V_53 , T_11 * V_103 ,
T_2 * V_56 , T_2 * V_58 ,
T_2 * V_60 )
{
int V_63 = 0 ;
int V_104 ;
char V_105 [ V_106 + 1 ] ;
int V_107 = 0 ;
int V_108 = 1 ;
int V_109 = 0 ;
int V_110 = 0 ;
char V_111 [ V_112 + 1 ] ;
int V_113 ;
char V_114 [ V_115 + 1 ] ;
int V_116 ;
int V_117 = FALSE ;
T_9 V_118 = FALSE ;
* V_49 = FALSE ;
for ( V_63 = 0 ; ( V_9 [ V_63 ] != '.' ) && ( V_63 < V_54 ) && ( V_63 + 1 < V_45 ) ; V_63 ++ ) {
if ( V_9 [ V_63 ] == '/' ) {
V_53 [ V_63 ] = '\0' ;
if ( strncmp ( V_9 + V_63 , L_7 , 5 ) != 0 ) {
return FALSE ;
}
F_11 ( V_56 , V_57 , L_11 ) ;
* V_49 = TRUE ;
break;
}
if ( ! isalnum ( ( V_119 ) V_9 [ V_63 ] ) && ( V_9 [ V_63 ] != '_' ) && ( V_9 [ V_63 ] != '-' ) ) {
return FALSE ;
}
V_53 [ V_63 ] = V_9 [ V_63 ] ;
}
if ( V_63 == V_54 || ( V_63 + 1 >= V_45 ) ) {
return FALSE ;
}
V_58 [ 0 ] = '\0' ;
V_60 [ 0 ] = '\0' ;
V_105 [ 0 ] = '\0' ;
if ( ! ( * V_49 ) ) {
if ( V_9 [ V_63 ] != '.' ) {
return FALSE ;
}
V_53 [ V_63 ] = '\0' ;
V_63 ++ ;
for ( V_104 = 0 ;
( V_9 [ V_63 ] != '/' ) && ( V_104 <= V_106 ) && ( V_63 + 1 < V_45 ) ;
V_63 ++ , V_104 ++ ) {
if ( ! isdigit ( ( V_119 ) V_9 [ V_63 ] ) ) {
return FALSE ;
}
V_105 [ V_104 ] = V_9 [ V_63 ] ;
}
if ( V_104 > V_106 || ( V_63 + 1 >= V_45 ) ) {
return FALSE ;
}
if ( V_9 [ V_63 ] != '/' )
{
return FALSE ;
}
V_105 [ V_104 ] = '\0' ;
* V_103 = atoi ( V_105 ) ;
V_63 ++ ;
for ( V_109 = 0 ;
( V_9 [ V_63 ] != '/' ) && ( V_109 < V_57 ) && ( V_63 < V_45 ) ;
V_63 ++ , V_109 ++ ) {
if ( ! isalnum ( ( V_119 ) V_9 [ V_63 ] ) && V_9 [ V_63 ] != '_' ) {
return FALSE ;
}
V_56 [ V_109 ] = V_9 [ V_63 ] ;
}
if ( V_109 == V_57 || V_63 >= V_45 ) {
return FALSE ;
}
V_56 [ V_109 ] = '\0' ;
if ( V_9 [ V_63 ] != '/' ) {
return FALSE ;
}
V_63 ++ ;
for ( V_107 = 0 ;
( isdigit ( ( V_119 ) V_9 [ V_63 ] ) ) && ( V_107 <= V_59 ) && ( V_63 + 1 < V_45 ) ;
V_63 ++ , V_107 ++ ) {
if ( ! isdigit ( ( V_119 ) V_9 [ V_63 ] ) ) {
return FALSE ;
}
V_58 [ V_107 ] = V_9 [ V_63 ] ;
}
if ( V_107 > V_59 || ( V_63 + 1 >= V_45 ) ) {
return FALSE ;
}
if ( V_107 > 0 ) {
V_58 [ V_107 ] = '\0' ;
V_108 = atoi ( V_58 ) ;
}
else {
F_5 ( V_58 , L_12 , V_59 + 1 ) ;
}
V_60 [ 0 ] = '\0' ;
if ( V_9 [ V_63 ] == ',' ) {
V_63 ++ ;
for ( V_110 = 0 ;
( isdigit ( ( V_119 ) V_9 [ V_63 ] ) || V_9 [ V_63 ] == ',' ) &&
( V_110 <= V_61 ) && ( V_63 + 1 < V_45 ) ;
V_63 ++ , V_110 ++ ) {
if ( ! isdigit ( ( V_119 ) V_9 [ V_63 ] ) && ( V_9 [ V_63 ] != ',' ) ) {
return FALSE ;
}
V_60 [ V_110 ] = V_9 [ V_63 ] ;
}
if ( V_110 > V_61 || ( V_63 + 1 >= V_45 ) ) {
return FALSE ;
}
V_60 [ V_110 ] = '\0' ;
}
}
if ( ( strcmp ( V_56 , L_13 ) == 0 ) ||
( strcmp ( V_56 , L_14 ) == 0 ) ||
( strcmp ( V_56 , L_15 ) == 0 ) ||
( strcmp ( V_56 , L_16 ) == 0 ) ||
( strcmp ( V_56 , L_17 ) == 0 ) ) {
* V_44 = V_120 ;
}
else
if ( ( strcmp ( V_56 , L_18 ) == 0 ) ||
( strcmp ( V_56 , L_19 ) == 0 ) ||
( strcmp ( V_56 , L_20 ) == 0 ) ||
( strcmp ( V_56 , L_21 ) == 0 ) ||
( strcmp ( V_56 , L_22 ) == 0 ) ||
( strcmp ( V_56 , L_23 ) == 0 ) ) {
if ( ( V_108 > 256 ) && ( V_108 % 256 == 3 ) ) {
* V_44 = 0 ;
}
else {
* V_44 = V_121 ;
V_118 = TRUE ;
}
}
else if ( strcmp ( V_56 , L_24 ) == 0 ) {
* V_44 = V_121 ;
V_118 = TRUE ;
}
else
if ( strcmp ( V_56 , L_25 ) == 0 ) {
* V_44 = V_122 ;
}
else
if ( strcmp ( V_56 , L_26 ) == 0 ) {
V_117 = TRUE ;
* V_44 = V_123 ;
}
else
if ( strcmp ( V_56 , L_27 ) == 0 ) {
* V_44 = V_123 ;
}
else
if ( strcmp ( V_56 , L_28 ) == 0 ) {
* V_44 = V_124 ;
}
else
if ( ( strcmp ( V_56 , L_29 ) == 0 ) ||
( strcmp ( V_56 , L_30 ) == 0 ) ) {
* V_44 = V_125 ;
}
else
if ( strcmp ( V_56 , L_31 ) == 0 ) {
* V_44 = V_126 ;
}
else
if ( strcmp ( V_56 , L_32 ) == 0 ) {
* V_44 = V_127 ;
}
else
if ( ( strcmp ( V_56 , L_33 ) == 0 ) ||
( strcmp ( V_56 , L_34 ) == 0 ) ||
( strncmp ( V_56 , L_35 , strlen ( L_35 ) ) == 0 ) ) {
* V_44 = V_128 ;
}
else {
* V_44 = V_129 ;
}
if ( V_118 ) {
int V_130 = 0 ;
for (; ( V_9 [ V_63 ] != '$' ) && ( V_63 + 1 < V_45 ) ; V_63 ++ ) ;
V_63 ++ ;
if ( V_63 + 1 >= V_45 ) {
return FALSE ;
}
for (;
( ( V_9 [ V_63 ] >= '0' ) && ( V_9 [ V_63 ] <= '?' ) &&
( V_63 < V_45 ) &&
( V_130 < V_52 ) ) ;
V_63 ++ , V_130 ++ ) {
V_51 [ V_130 ] = V_9 [ V_63 ] ;
if ( ! isdigit ( ( V_119 ) V_9 [ V_63 ] ) ) {
V_51 [ V_130 ] = 'a' + ( V_9 [ V_63 ] - '9' ) - 1 ;
}
}
if ( V_130 != V_52 || V_63 >= V_45 ) {
return FALSE ;
}
}
V_63 ++ ;
if ( isdigit ( V_9 [ V_63 ] ) ) {
while ( ( V_63 + 1 < V_45 ) && V_9 [ V_63 ] != '/' ) {
V_63 ++ ;
}
}
while ( ( V_63 + 1 < V_45 ) && V_9 [ V_63 ] == '/' ) {
V_63 ++ ;
}
if ( ( V_63 + 1 < V_45 ) && V_9 [ V_63 ] == ' ' ) {
V_63 ++ ;
}
if ( ! ( * V_49 ) ) {
if ( V_9 [ V_63 ] == 's' ) {
* V_43 = V_131 ;
}
else
if ( V_9 [ V_63 ] == 'r' ) {
* V_43 = V_132 ;
}
else {
return FALSE ;
}
V_63 ++ ;
}
else {
* V_43 = V_131 ;
}
for (; ( ( V_9 [ V_63 ] != 't' ) || ( V_9 [ V_63 + 1 ] != 'm' ) ) && ( V_63 + 1 < V_45 ) ; V_63 ++ ) ;
if ( V_63 >= V_45 ) {
return FALSE ;
}
for (; ! isdigit ( ( V_119 ) V_9 [ V_63 ] ) && ( V_63 < V_45 ) ; V_63 ++ ) ;
if ( V_63 >= V_45 ) {
return FALSE ;
}
* V_41 = V_63 ;
for ( V_113 = 0 ;
( V_9 [ V_63 ] != '.' ) &&
( V_113 <= V_112 ) &&
( V_63 < V_45 ) ;
V_63 ++ , V_113 ++ ) {
if ( ! isdigit ( ( V_119 ) V_9 [ V_63 ] ) ) {
return FALSE ;
}
V_111 [ V_113 ] = V_9 [ V_63 ] ;
}
if ( V_113 > V_112 || V_63 >= V_45 ) {
return FALSE ;
}
V_111 [ V_113 ] = '\0' ;
* V_46 = atoi ( V_111 ) ;
if ( V_9 [ V_63 ] != '.' ) {
return FALSE ;
}
V_63 ++ ;
for ( V_116 = 0 ;
( V_9 [ V_63 ] != ' ' ) &&
( V_116 <= V_115 ) &&
( V_63 < V_45 ) ;
V_63 ++ , V_116 ++ ) {
if ( ! isdigit ( ( V_119 ) V_9 [ V_63 ] ) ) {
return FALSE ;
}
V_114 [ V_116 ] = V_9 [ V_63 ] ;
}
if ( V_116 > V_115 || V_63 >= V_45 ) {
return FALSE ;
}
V_114 [ V_116 ] = '\0' ;
* V_47 = atoi ( V_114 ) * 100 ;
if ( V_9 [ V_63 ] != ' ' ) {
return FALSE ;
}
* V_42 = V_63 ;
for (; ( V_9 [ V_63 ] != '$' ) && ( V_9 [ V_63 ] != '\'' ) && ( V_63 + 1 < V_45 ) ; V_63 ++ ) ;
if ( ( V_9 [ V_63 ] == '\'' ) || ( V_63 + 1 >= V_45 ) ) {
return FALSE ;
}
V_63 ++ ;
* V_39 = V_63 ;
* V_48 = V_45 - V_63 ;
if ( V_117 ) {
* V_39 += 2 ;
* V_48 -= 2 ;
}
return TRUE ;
}
static int
F_14 ( T_11 * V_62 , char * V_66 ,
T_10 V_43 , int V_44 ,
T_2 * V_53 , T_11 V_55 ,
T_2 * V_56 , T_2 * V_58 ,
T_2 * V_60 )
{
int V_64 = 0 ;
F_5 ( ( char * ) V_62 , V_53 , V_54 + 1 ) ;
V_64 += ( int ) ( strlen ( V_53 ) + 1 ) ;
V_62 [ V_64 ] = V_55 ;
V_64 ++ ;
F_5 ( ( char * ) & V_62 [ V_64 ] , V_66 , V_67 + 1 ) ;
V_64 += ( int ) ( strlen ( V_66 ) + 1 ) ;
F_5 ( ( char * ) & V_62 [ V_64 ] , V_56 , V_57 + 1 ) ;
V_64 += ( int ) ( strlen ( V_56 ) + 1 ) ;
F_5 ( ( void * ) & V_62 [ V_64 ] , V_58 , V_59 + 1 ) ;
V_64 += ( int ) ( strlen ( V_58 ) + 1 ) ;
F_5 ( ( char * ) & V_62 [ V_64 ] , V_60 , V_61 + 1 ) ;
V_64 += ( int ) ( strlen ( V_60 ) + 1 ) ;
V_62 [ V_64 ] = V_43 ;
V_64 ++ ;
V_62 [ V_64 ] = ( T_11 ) V_44 ;
V_64 ++ ;
return V_64 ;
}
static void
F_18 ( T_1 * V_1 ,
int V_72 ,
T_4 V_133 ,
union V_82 * V_80 ,
T_10 V_43 ,
T_2 * V_51 )
{
V_80 -> V_96 . V_81 = V_133 ;
V_80 -> V_96 . V_1 = V_1 ;
switch ( V_72 ) {
case V_121 :
F_29 ( V_80 , V_43 , V_51 ) ;
break;
case V_123 :
F_30 ( V_80 , V_43 ) ;
break;
case V_122 :
F_31 ( V_80 , V_43 ) ;
break;
default:
break;
}
}
static void
F_29 ( union V_82 * V_80 ,
T_10 V_43 ,
T_2 * V_51 )
{
V_80 -> V_96 . V_134 . V_135 . V_136 = 0x00 ;
V_80 -> V_96 . V_134 . V_135 . V_137 = ( V_43 == V_132 ) ;
V_80 -> V_96 . V_134 . V_135 . V_138 = V_139 ;
V_80 -> V_96 . V_134 . V_135 . type = V_140 ;
V_80 -> V_96 . V_134 . V_135 . V_141 = V_142 ;
V_80 -> V_96 . V_134 . V_135 . V_143 =
F_15 ( V_51 + 1 ) ;
V_80 -> V_96 . V_134 . V_135 . V_144 =
( ( F_32 ( V_51 [ 3 ] ) << 12 ) |
( F_32 ( V_51 [ 4 ] ) << 8 ) |
( F_32 ( V_51 [ 5 ] ) << 4 ) |
F_32 ( V_51 [ 6 ] ) ) ;
V_80 -> V_96 . V_134 . V_135 . V_145 = 0 ;
if ( isalnum ( ( V_119 ) V_51 [ 11 ] ) ) {
V_80 -> V_96 . V_134 . V_135 . V_146 =
F_15 ( V_51 + 10 ) ;
}
else {
V_80 -> V_96 . V_134 . V_135 . V_146 =
( int ) V_51 [ 11 ] - '0' ;
}
}
static void
F_30 ( union V_82 * V_80 ,
T_10 V_43 )
{
V_80 -> V_96 . V_134 . V_147 . V_148 = ( V_43 == V_132 ) ;
V_80 -> V_96 . V_134 . V_147 . V_137 = 0 ;
}
static void
F_31 ( union V_82 * V_80 ,
T_10 V_43 )
{
V_80 -> V_96 . V_134 . V_149 . V_131 = ( V_43 == V_131 ) ;
}
static T_11
F_32 ( T_2 V_99 )
{
if ( ( V_99 >= '0' ) && ( V_99 <= '9' ) ) {
return V_99 - '0' ;
}
if ( ( V_99 >= 'a' ) && ( V_99 <= 'f' ) ) {
return 0x0a + ( V_99 - 'a' ) ;
}
return 0xff ;
}
static void F_3 ( void )
{
V_119 V_150 [ 16 ] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' ,
'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
T_7 V_151 , V_152 ;
for ( V_151 = 0 ; V_151 < 16 ; V_151 ++ ) {
for ( V_152 = 0 ; V_152 < 16 ; V_152 ++ ) {
V_153 [ V_150 [ V_151 ] ] [ V_150 [ V_152 ] ] = V_151 * 16 + V_152 ;
}
}
}
static T_11 F_15 ( T_2 * V_99 )
{
return V_153 [ ( unsigned char ) V_99 [ 0 ] ] [ ( unsigned char ) V_99 [ 1 ] ] ;
}
static T_2
F_27 ( T_11 V_154 )
{
static char V_155 [ 16 ] =
{ '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( V_154 > 15 ) {
return '?' ;
}
return V_155 [ V_154 ] ;
}
static T_7
V_37 ( T_16 V_156 , T_16 V_157 )
{
return ( * ( const T_4 * ) V_156 == * ( const T_4 * ) V_157 ) ;
}
static T_17
V_36 ( T_16 V_156 )
{
return ( T_17 ) ( * ( const T_4 * ) V_156 ) ;
}
static T_9
F_6 ( T_2 * V_9 , T_5 * V_74 , T_6 * V_6 )
{
int V_63 ;
struct V_158 V_158 ;
#define F_33 9
char V_159 [ F_33 + 1 ] ;
int V_160 , V_161 , V_162 , V_163 , V_164 ;
int V_165 ;
if ( strlen ( V_9 ) > V_19 ) {
return FALSE ;
}
for ( V_63 = 0 ; ( V_9 [ V_63 ] != ' ' ) && ( V_63 < F_33 ) ; V_63 ++ ) {
V_159 [ V_63 ] = V_9 [ V_63 ] ;
}
V_159 [ V_63 ] = '\0' ;
if ( strcmp ( V_159 , L_36 ) == 0 ) V_158 . V_166 = 0 ;
else if ( strcmp ( V_159 , L_37 ) == 0 ) V_158 . V_166 = 1 ;
else if ( strcmp ( V_159 , L_38 ) == 0 ) V_158 . V_166 = 2 ;
else if ( strcmp ( V_159 , L_39 ) == 0 ) V_158 . V_166 = 3 ;
else if ( strcmp ( V_159 , L_40 ) == 0 ) V_158 . V_166 = 4 ;
else if ( strcmp ( V_159 , L_41 ) == 0 ) V_158 . V_166 = 5 ;
else if ( strcmp ( V_159 , L_42 ) == 0 ) V_158 . V_166 = 6 ;
else if ( strcmp ( V_159 , L_43 ) == 0 ) V_158 . V_166 = 7 ;
else if ( strcmp ( V_159 , L_44 ) == 0 ) V_158 . V_166 = 8 ;
else if ( strcmp ( V_159 , L_45 ) == 0 ) V_158 . V_166 = 9 ;
else if ( strcmp ( V_159 , L_46 ) == 0 ) V_158 . V_166 = 10 ;
else if ( strcmp ( V_159 , L_47 ) == 0 ) V_158 . V_166 = 11 ;
else {
return FALSE ;
}
V_63 ++ ;
V_165 = sscanf ( V_9 + V_63 , L_48 ,
& V_160 , & V_161 , & V_162 , & V_163 , & V_164 , V_6 ) ;
if ( V_165 != 6 ) {
return FALSE ;
}
V_158 . V_167 = V_161 - 1900 ;
V_158 . V_168 = V_160 ;
V_158 . V_169 = V_162 ;
V_158 . V_170 = V_163 ;
V_158 . V_171 = V_164 ;
V_158 . V_172 = - 1 ;
* V_74 = mktime ( & V_158 ) ;
* V_6 = * V_6 * 100 ;
return TRUE ;
}
static T_9
V_88 ( T_18 V_173 , T_18 V_174 ,
T_18 T_19 V_3 )
{
T_12 * V_175 = ( T_12 * ) V_174 ;
F_7 ( V_173 ) ;
F_7 ( V_175 -> V_78 ) ;
if ( V_175 -> V_79 ) {
F_7 ( V_175 -> V_79 ) ;
}
F_7 ( V_175 ) ;
return TRUE ;
}
