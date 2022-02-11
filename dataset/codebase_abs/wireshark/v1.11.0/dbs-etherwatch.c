static T_1 F_1 ( T_2 * V_1 , int * V_2 ,
T_3 * * V_3 )
{
int V_4 ;
unsigned int V_5 = 0 ;
T_1 V_6 ;
while ( ( V_4 = F_2 ( V_1 -> V_7 ) ) != V_8 ) {
if ( V_4 == V_9 [ V_5 ] ) {
V_5 ++ ;
if ( V_5 >= V_10 ) {
V_6 = F_3 ( V_1 -> V_7 ) ;
if ( V_6 == - 1 ) {
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
return - 1 ;
}
return V_6 + 1 ;
}
} else {
V_5 = 0 ;
}
}
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
return - 1 ;
}
static T_4 F_5 ( T_2 * V_1 , int * V_2 ,
T_3 * * V_3 )
{
char V_11 [ V_12 ] ;
int line , V_4 ;
T_5 V_13 ;
unsigned int V_14 , V_5 ;
V_11 [ V_12 - 1 ] = 0 ;
for ( line = 0 ; line < V_15 ; line ++ ) {
if ( F_6 ( V_11 , V_12 , V_1 -> V_7 ) == NULL ) {
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
V_13 = strlen ( V_11 ) ;
if ( V_13 < V_16 )
continue;
V_5 = 0 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
V_4 = V_11 [ V_14 ] ;
if ( V_4 == V_17 [ V_5 ] ) {
V_5 ++ ;
if ( V_5 >=
V_16 ) {
return TRUE ;
}
}
else
V_5 = 0 ;
}
}
* V_2 = 0 ;
return FALSE ;
}
int F_7 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
if ( ! F_5 ( V_1 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_18 )
return - 1 ;
return 0 ;
}
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
return 1 ;
}
static T_4 V_25 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_30 )
{
T_1 V_31 ;
V_31 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_31 < 1 )
return FALSE ;
* V_30 = V_31 ;
return F_8 ( & V_1 -> V_32 , V_1 -> V_7 ,
V_1 -> V_33 , V_2 , V_3 ) ;
}
static T_4
V_27 ( T_2 * V_1 , T_1 V_34 ,
struct V_35 * V_32 , T_6 * V_11 , int T_7 V_36 ,
int * V_2 , T_3 * * V_3 )
{
if ( F_9 ( V_1 -> V_37 , V_34 - 1 , V_38 , V_2 ) == - 1 )
return FALSE ;
return F_8 ( V_32 , V_1 -> V_37 , V_11 , V_2 ,
V_3 ) ;
}
static T_4
F_8 ( struct V_35 * V_32 , T_8 V_7 , T_6 * V_11 ,
int * V_2 , T_3 * * V_3 )
{
T_9 * V_39 ;
char line [ V_12 ] ;
int V_40 ;
int V_41 , V_42 , V_43 ;
int V_44 , V_45 , V_46 ;
struct V_47 V_47 ;
char V_48 [ 4 ] = L_1 ;
T_3 * V_49 ;
static const T_3 V_50 [] = L_2 ;
int V_51 , V_52 ;
F_10 ( V_11 , V_53 ) ;
V_39 = F_11 ( V_11 ) ;
V_41 = 0 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
V_49 = strstr ( line , V_54 ) ;
if( ! V_49 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_3 ) ;
return FALSE ;
}
V_49 += strlen ( V_54 ) ;
if( F_13 ( V_49 , & V_39 [ V_41 ] , V_56 , V_57 )
!= V_58 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_4 ) ;
return FALSE ;
}
V_41 += V_58 ;
V_49 = line ;
while( ! isxdigit ( ( V_59 ) * V_49 ) ) {
V_49 ++ ;
}
if( F_13 ( V_49 , & V_39 [ V_41 ] , V_56 ,
V_57 ) != V_58 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_5 ) ;
return FALSE ;
}
V_41 += V_58 ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
if( strlen ( line ) < V_60 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_6 ) ;
return FALSE ;
}
V_40 = sscanf ( line + V_60 ,
L_7 ,
& V_42 ,
& V_47 . V_61 , V_48 ,
& V_47 . V_62 , & V_47 . V_63 , & V_47 . V_64 ,
& V_47 . V_65 , & V_43 ) ;
if ( V_40 != 8 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_8 ) ;
return FALSE ;
}
if( strncmp ( & line [ V_66 ] , V_67 ,
strlen ( V_67 ) ) == 0 ) {
if( F_13 ( & line [ V_68 ] , & V_39 [ V_41 ] , V_56 ,
V_57 ) != V_69 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_9 ) ;
return FALSE ;
}
V_41 += V_69 ;
} else {
V_44 = V_41 ;
V_41 += V_70 ;
V_45 = V_41 ;
if( F_13 ( & line [ V_71 ] , & V_39 [ V_41 ] , V_56 ,
V_57 ) != V_72 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_10 ) ;
return FALSE ;
}
V_41 += V_72 ;
if( F_13 ( & line [ V_73 ] , & V_39 [ V_41 ] , V_56 ,
V_57 ) != V_74 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_11 ) ;
return FALSE ;
}
if( ( V_39 [ V_41 ] & V_75 ) != V_76 ) {
if( F_13 ( & line [ V_77 ] ,
& V_39 [ V_41 + V_74 ] , V_57 ,
V_56 ) != V_78 - V_74 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_12 ) ;
return FALSE ;
}
V_41 += V_78 ;
} else {
V_41 += V_74 ;
}
if( strncmp ( & line [ V_79 ] , V_80 ,
strlen ( V_80 ) ) == 0 ) {
if( F_13 ( & line [ V_77 ] , & V_39 [ V_41 ] , V_56 ,
V_81 ) != V_82 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_13 ) ;
return FALSE ;
}
V_41 += V_82 ;
}
V_46 = V_41 - V_45 + V_42 ;
V_39 [ V_44 ] = ( V_46 ) >> 8 ;
V_39 [ V_44 + 1 ] = ( V_46 ) & 0xFF ;
}
V_32 -> V_83 = V_84 | V_85 ;
V_49 = strstr ( V_50 , V_48 ) ;
if ( V_49 )
V_47 . V_86 = ( int ) ( V_49 - V_50 ) / 3 ;
V_47 . V_62 -= 1900 ;
V_47 . V_87 = - 1 ;
V_32 -> V_88 . V_89 = mktime ( & V_47 ) ;
V_32 -> V_88 . V_90 = V_43 * 10000000 ;
V_32 -> V_91 = V_41 + V_42 ;
V_32 -> T_7 = V_41 + V_42 ;
V_32 -> V_92 . V_93 . V_94 = 0 ;
V_51 = 0 ;
while ( V_51 < V_42 ) {
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
if ( ! ( V_52 = F_14 ( line ,
& V_39 [ V_41 + V_51 ] , V_51 ) ) ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_14 ) ;
return FALSE ;
}
V_51 += V_52 ;
if ( V_51 > V_42 ) {
* V_2 = V_55 ;
* V_3 = F_12 ( L_15 ) ;
return FALSE ;
}
}
return TRUE ;
}
static T_10
F_14 ( char * V_95 , T_9 * V_11 , int V_96 ) {
int V_97 , V_14 ;
int V_98 ;
for( V_14 = 0 ; V_14 < V_99 ; V_14 ++ )
{
if( V_95 [ V_14 ] == '\0' ) {
return 0 ;
}
}
if( V_95 [ V_99 ] == V_100 )
{
V_97 = V_101 ;
}
else
{
V_97 = V_102 ;
}
while( V_14 < V_97 )
{
if( V_95 [ V_14 ] == '\0' ) {
return 0 ;
}
V_14 ++ ;
}
V_98 = 0 ;
for( V_14 = 0 ; V_14 < V_103 ; V_14 ++ ) {
if( ! isspace ( ( V_59 ) V_95 [ V_97 ] ) ) {
if( isdigit ( ( V_59 ) V_95 [ V_97 ] ) ) {
V_98 *= 10 ;
V_98 += V_95 [ V_97 ] - '0' ;
} else {
return 0 ;
}
}
V_97 ++ ;
}
if ( V_98 != V_96 ) {
return 0 ;
}
while( V_95 [ V_97 ] != V_104 ) {
if( V_95 [ V_97 ] == '\0' ) {
return 0 ;
}
V_97 ++ ;
}
V_97 ++ ;
return F_13 ( & V_95 [ V_97 ] , V_11 , V_105 , V_106 ) ;
}
static T_10
F_13 ( char * V_107 , T_9 * V_11 , char V_108 , char V_109 ) {
int V_97 , V_51 ;
V_97 = 0 ;
V_51 = 0 ;
while( V_107 [ V_97 ] != V_109 ) {
if( ! ( isxdigit ( ( V_59 ) V_107 [ V_97 ] ) &&
isxdigit ( ( V_59 ) V_107 [ V_97 + 1 ] ) ) ) {
return 0 ;
}
if( isdigit ( ( V_59 ) V_107 [ V_97 ] ) ) {
V_11 [ V_51 ] = ( V_107 [ V_97 ] - '0' ) << 4 ;
} else {
V_11 [ V_51 ] = ( toupper ( V_107 [ V_97 ] ) - 'A' + 10 ) << 4 ;
}
V_97 ++ ;
if( isdigit ( ( V_59 ) V_107 [ V_97 ] ) ) {
V_11 [ V_51 ] += V_107 [ V_97 ] - '0' ;
} else {
V_11 [ V_51 ] += toupper ( V_107 [ V_97 ] ) - 'A' + 10 ;
}
V_97 ++ ;
V_51 ++ ;
while( V_107 [ V_97 ] == V_108 ) {
V_97 ++ ;
}
}
return V_51 ;
}
