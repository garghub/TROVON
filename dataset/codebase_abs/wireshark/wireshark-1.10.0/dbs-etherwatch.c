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
T_6 * V_11 ;
int V_32 ;
V_31 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_31 < 1 )
return FALSE ;
F_8 ( V_1 -> V_33 , V_34 ) ;
V_11 = F_9 ( V_1 -> V_33 ) ;
V_32 = F_10 ( V_1 , V_1 -> V_7 , V_11 , V_2 , V_3 ) ;
if ( V_32 == - 1 )
return FALSE ;
V_1 -> V_35 . V_36 . V_37 . V_38 = 0 ;
* V_30 = V_31 ;
return TRUE ;
}
static T_4
V_27 ( T_2 * V_1 , T_1 V_39 ,
struct V_40 * V_35 ,
T_6 * V_41 , int V_42 , int * V_2 , T_3 * * V_3 )
{
union V_43 * V_36 = & V_35 -> V_36 ;
int V_32 ;
if ( F_11 ( V_1 -> V_44 , V_39 - 1 , V_45 , V_2 ) == - 1 )
return FALSE ;
V_32 = F_10 ( NULL , V_1 -> V_44 , V_41 , V_2 ,
V_3 ) ;
if ( V_32 != V_42 ) {
if ( V_32 != - 1 ) {
* V_2 = V_46 ;
* V_3 = F_12 ( L_1 ,
V_32 , V_42 ) ;
}
return FALSE ;
}
V_36 -> V_37 . V_38 = 0 ;
return TRUE ;
}
static int
F_10 ( T_2 * V_1 , T_7 V_7 , T_6 * V_11 , int * V_2 ,
T_3 * * V_3 )
{
char line [ V_12 ] ;
int V_47 ;
int V_48 , V_32 , V_49 ;
int V_50 , V_51 , V_52 ;
struct V_53 V_53 ;
char V_54 [ 4 ] = L_2 ;
T_3 * V_55 ;
static const T_3 V_56 [] = L_3 ;
int V_57 , V_58 ;
V_48 = 0 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return - 1 ;
}
V_55 = strstr ( line , V_59 ) ;
if( ! V_55 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_4 ) ;
return - 1 ;
}
V_55 += strlen ( V_59 ) ;
if( F_14 ( V_55 , & V_11 [ V_48 ] , V_60 , V_61 )
!= V_62 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_5 ) ;
return - 1 ;
}
V_48 += V_62 ;
V_55 = line ;
while( ! isxdigit ( ( V_63 ) * V_55 ) ) {
V_55 ++ ;
}
if( F_14 ( V_55 , & V_11 [ V_48 ] , V_60 ,
V_61 ) != V_62 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_6 ) ;
return - 1 ;
}
V_48 += V_62 ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return - 1 ;
}
if( strlen ( line ) < V_64 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_7 ) ;
return - 1 ;
}
V_47 = sscanf ( line + V_64 ,
L_8 ,
& V_32 ,
& V_53 . V_65 , V_54 ,
& V_53 . V_66 , & V_53 . V_67 , & V_53 . V_68 ,
& V_53 . V_69 , & V_49 ) ;
if ( V_47 != 8 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_9 ) ;
return - 1 ;
}
if( strncmp ( & line [ V_70 ] , V_71 ,
strlen ( V_71 ) ) == 0 ) {
if( F_14 ( & line [ V_72 ] , & V_11 [ V_48 ] , V_60 ,
V_61 ) != V_73 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_10 ) ;
return - 1 ;
}
V_48 += V_73 ;
} else {
V_50 = V_48 ;
V_48 += V_74 ;
V_51 = V_48 ;
if( F_14 ( & line [ V_75 ] , & V_11 [ V_48 ] , V_60 ,
V_61 ) != V_76 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_11 ) ;
return - 1 ;
}
V_48 += V_76 ;
if( F_14 ( & line [ V_77 ] , & V_11 [ V_48 ] , V_60 ,
V_61 ) != V_78 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_12 ) ;
return - 1 ;
}
if( ( V_11 [ V_48 ] & V_79 ) != V_80 ) {
if( F_14 ( & line [ V_81 ] ,
& V_11 [ V_48 + V_78 ] , V_61 ,
V_60 ) != V_82 - V_78 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_13 ) ;
return - 1 ;
}
V_48 += V_82 ;
} else {
V_48 += V_78 ;
}
if( strncmp ( & line [ V_83 ] , V_84 ,
strlen ( V_84 ) ) == 0 ) {
if( F_14 ( & line [ V_81 ] , & V_11 [ V_48 ] , V_60 ,
V_85 ) != V_86 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_14 ) ;
return - 1 ;
}
V_48 += V_86 ;
}
V_52 = V_48 - V_51 + V_32 ;
V_11 [ V_50 ] = ( V_52 ) >> 8 ;
V_11 [ V_50 + 1 ] = ( V_52 ) & 0xFF ;
}
if ( V_1 ) {
V_1 -> V_35 . V_87 = V_88 | V_89 ;
V_55 = strstr ( V_56 , V_54 ) ;
if ( V_55 )
V_53 . V_90 = ( int ) ( V_55 - V_56 ) / 3 ;
V_53 . V_66 -= 1900 ;
V_53 . V_91 = - 1 ;
V_1 -> V_35 . V_92 . V_93 = mktime ( & V_53 ) ;
V_1 -> V_35 . V_92 . V_94 = V_49 * 10000000 ;
V_1 -> V_35 . V_95 = V_48 + V_32 ;
V_1 -> V_35 . V_42 = V_48 + V_32 ;
}
V_57 = 0 ;
while ( V_57 < V_32 ) {
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return - 1 ;
}
if ( ! ( V_58 = F_15 ( line ,
& V_11 [ V_48 + V_57 ] , V_57 ) ) ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_15 ) ;
return - 1 ;
}
V_57 += V_58 ;
if ( V_57 > V_32 ) {
* V_2 = V_46 ;
* V_3 = F_13 ( L_16 ) ;
return - 1 ;
}
}
return V_48 + V_32 ;
}
static T_8
F_15 ( char * V_96 , T_6 * V_11 , int V_97 ) {
int V_98 , V_14 ;
int V_99 ;
for( V_14 = 0 ; V_14 < V_100 ; V_14 ++ )
{
if( V_96 [ V_14 ] == '\0' ) {
return 0 ;
}
}
if( V_96 [ V_100 ] == V_101 )
{
V_98 = V_102 ;
}
else
{
V_98 = V_103 ;
}
while( V_14 < V_98 )
{
if( V_96 [ V_14 ] == '\0' ) {
return 0 ;
}
V_14 ++ ;
}
V_99 = 0 ;
for( V_14 = 0 ; V_14 < V_104 ; V_14 ++ ) {
if( ! isspace ( ( V_63 ) V_96 [ V_98 ] ) ) {
if( isdigit ( ( V_63 ) V_96 [ V_98 ] ) ) {
V_99 *= 10 ;
V_99 += V_96 [ V_98 ] - '0' ;
} else {
return 0 ;
}
}
V_98 ++ ;
}
if ( V_99 != V_97 ) {
return 0 ;
}
while( V_96 [ V_98 ] != V_105 ) {
if( V_96 [ V_98 ] == '\0' ) {
return 0 ;
}
V_98 ++ ;
}
V_98 ++ ;
return F_14 ( & V_96 [ V_98 ] , V_11 , V_106 , V_107 ) ;
}
static T_8
F_14 ( char * V_108 , T_6 * V_11 , char V_109 , char V_110 ) {
int V_98 , V_57 ;
V_98 = 0 ;
V_57 = 0 ;
while( V_108 [ V_98 ] != V_110 ) {
if( ! ( isxdigit ( ( V_63 ) V_108 [ V_98 ] ) &&
isxdigit ( ( V_63 ) V_108 [ V_98 + 1 ] ) ) ) {
return 0 ;
}
if( isdigit ( ( V_63 ) V_108 [ V_98 ] ) ) {
V_11 [ V_57 ] = ( V_108 [ V_98 ] - '0' ) << 4 ;
} else {
V_11 [ V_57 ] = ( toupper ( V_108 [ V_98 ] ) - 'A' + 10 ) << 4 ;
}
V_98 ++ ;
if( isdigit ( ( V_63 ) V_108 [ V_98 ] ) ) {
V_11 [ V_57 ] += V_108 [ V_98 ] - '0' ;
} else {
V_11 [ V_57 ] += toupper ( V_108 [ V_98 ] ) - 'A' + 10 ;
}
V_98 ++ ;
V_57 ++ ;
while( V_108 [ V_98 ] == V_109 ) {
V_98 ++ ;
}
}
return V_57 ;
}
