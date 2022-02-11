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
struct V_35 * V_32 , T_6 * V_11 , int * V_2 , T_3 * * V_3 )
{
if ( F_9 ( V_1 -> V_36 , V_34 - 1 , V_37 , V_2 ) == - 1 )
return FALSE ;
return F_8 ( V_32 , V_1 -> V_36 , V_11 , V_2 ,
V_3 ) ;
}
static T_4
F_8 ( struct V_35 * V_32 , T_7 V_7 , T_6 * V_11 ,
int * V_2 , T_3 * * V_3 )
{
T_8 * V_38 ;
char line [ V_12 ] ;
int V_39 ;
int V_40 , V_41 , V_42 ;
int V_43 , V_44 , V_45 ;
struct V_46 V_46 ;
char V_47 [ 4 ] = L_1 ;
T_3 * V_48 ;
static const T_3 V_49 [] = L_2 ;
int V_50 , V_51 ;
F_10 ( V_11 , V_52 ) ;
V_38 = F_11 ( V_11 ) ;
V_40 = 0 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
V_48 = strstr ( line , V_53 ) ;
if( ! V_48 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_3 ) ;
return FALSE ;
}
V_48 += strlen ( V_53 ) ;
if( F_13 ( V_48 , & V_38 [ V_40 ] , V_55 , V_56 )
!= V_57 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_4 ) ;
return FALSE ;
}
V_40 += V_57 ;
V_48 = line ;
while( ! isxdigit ( ( V_58 ) * V_48 ) ) {
V_48 ++ ;
}
if( F_13 ( V_48 , & V_38 [ V_40 ] , V_55 ,
V_56 ) != V_57 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_5 ) ;
return FALSE ;
}
V_40 += V_57 ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
if( strlen ( line ) < V_59 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_6 ) ;
return FALSE ;
}
V_39 = sscanf ( line + V_59 ,
L_7 ,
& V_41 ,
& V_46 . V_60 , V_47 ,
& V_46 . V_61 , & V_46 . V_62 , & V_46 . V_63 ,
& V_46 . V_64 , & V_42 ) ;
if ( V_39 != 8 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_8 ) ;
return FALSE ;
}
if( strncmp ( & line [ V_65 ] , V_66 ,
strlen ( V_66 ) ) == 0 ) {
if( F_13 ( & line [ V_67 ] , & V_38 [ V_40 ] , V_55 ,
V_56 ) != V_68 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_9 ) ;
return FALSE ;
}
V_40 += V_68 ;
} else {
V_43 = V_40 ;
V_40 += V_69 ;
V_44 = V_40 ;
if( F_13 ( & line [ V_70 ] , & V_38 [ V_40 ] , V_55 ,
V_56 ) != V_71 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_10 ) ;
return FALSE ;
}
V_40 += V_71 ;
if( F_13 ( & line [ V_72 ] , & V_38 [ V_40 ] , V_55 ,
V_56 ) != V_73 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_11 ) ;
return FALSE ;
}
if( ( V_38 [ V_40 ] & V_74 ) != V_75 ) {
if( F_13 ( & line [ V_76 ] ,
& V_38 [ V_40 + V_73 ] , V_56 ,
V_55 ) != V_77 - V_73 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_12 ) ;
return FALSE ;
}
V_40 += V_77 ;
} else {
V_40 += V_73 ;
}
if( strncmp ( & line [ V_78 ] , V_79 ,
strlen ( V_79 ) ) == 0 ) {
if( F_13 ( & line [ V_76 ] , & V_38 [ V_40 ] , V_55 ,
V_80 ) != V_81 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_13 ) ;
return FALSE ;
}
V_40 += V_81 ;
}
V_45 = V_40 - V_44 + V_41 ;
V_38 [ V_43 ] = ( V_45 ) >> 8 ;
V_38 [ V_43 + 1 ] = ( V_45 ) & 0xFF ;
}
V_32 -> V_82 = V_83 ;
V_32 -> V_84 = V_85 | V_86 ;
V_48 = strstr ( V_49 , V_47 ) ;
if ( V_48 )
V_46 . V_87 = ( int ) ( V_48 - V_49 ) / 3 ;
V_46 . V_61 -= 1900 ;
V_46 . V_88 = - 1 ;
V_32 -> V_89 . V_90 = mktime ( & V_46 ) ;
V_32 -> V_89 . V_91 = V_42 * 10000000 ;
V_32 -> V_92 = V_40 + V_41 ;
V_32 -> V_93 = V_40 + V_41 ;
V_32 -> V_94 . V_95 . V_96 = 0 ;
V_50 = 0 ;
while ( V_50 < V_41 ) {
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
if ( ! ( V_51 = F_14 ( line ,
& V_38 [ V_40 + V_50 ] , V_50 ) ) ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_14 ) ;
return FALSE ;
}
V_50 += V_51 ;
if ( V_50 > V_41 ) {
* V_2 = V_54 ;
* V_3 = F_12 ( L_15 ) ;
return FALSE ;
}
}
return TRUE ;
}
static T_9
F_14 ( char * V_97 , T_8 * V_11 , int V_98 ) {
int V_99 , V_14 ;
int V_100 ;
for( V_14 = 0 ; V_14 < V_101 ; V_14 ++ )
{
if( V_97 [ V_14 ] == '\0' ) {
return 0 ;
}
}
if( V_97 [ V_101 ] == V_102 )
{
V_99 = V_103 ;
}
else
{
V_99 = V_104 ;
}
while( V_14 < V_99 )
{
if( V_97 [ V_14 ] == '\0' ) {
return 0 ;
}
V_14 ++ ;
}
V_100 = 0 ;
for( V_14 = 0 ; V_14 < V_105 ; V_14 ++ ) {
if( ! isspace ( ( V_58 ) V_97 [ V_99 ] ) ) {
if( isdigit ( ( V_58 ) V_97 [ V_99 ] ) ) {
V_100 *= 10 ;
V_100 += V_97 [ V_99 ] - '0' ;
} else {
return 0 ;
}
}
V_99 ++ ;
}
if ( V_100 != V_98 ) {
return 0 ;
}
while( V_97 [ V_99 ] != V_106 ) {
if( V_97 [ V_99 ] == '\0' ) {
return 0 ;
}
V_99 ++ ;
}
V_99 ++ ;
return F_13 ( & V_97 [ V_99 ] , V_11 , V_107 , V_108 ) ;
}
static T_9
F_13 ( char * V_109 , T_8 * V_11 , char V_110 , char V_111 ) {
int V_99 , V_50 ;
V_99 = 0 ;
V_50 = 0 ;
while( V_109 [ V_99 ] != V_111 ) {
if( ! ( isxdigit ( ( V_58 ) V_109 [ V_99 ] ) &&
isxdigit ( ( V_58 ) V_109 [ V_99 + 1 ] ) ) ) {
return 0 ;
}
if( isdigit ( ( V_58 ) V_109 [ V_99 ] ) ) {
V_11 [ V_50 ] = ( V_109 [ V_99 ] - '0' ) << 4 ;
} else {
V_11 [ V_50 ] = ( toupper ( V_109 [ V_99 ] ) - 'A' + 10 ) << 4 ;
}
V_99 ++ ;
if( isdigit ( ( V_58 ) V_109 [ V_99 ] ) ) {
V_11 [ V_50 ] += V_109 [ V_99 ] - '0' ;
} else {
V_11 [ V_50 ] += toupper ( V_109 [ V_99 ] ) - 'A' + 10 ;
}
V_99 ++ ;
V_50 ++ ;
while( V_109 [ V_99 ] == V_110 ) {
V_99 ++ ;
}
}
return V_50 ;
}
