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
if ( F_5 ( V_1 -> V_7 ) ) {
* V_2 = 0 ;
} else {
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
}
return - 1 ;
}
static T_4 F_6 ( T_2 * V_1 , int * V_2 ,
T_3 * * V_3 )
{
char V_11 [ V_12 ] ;
int line , V_4 ;
T_5 V_13 ;
unsigned int V_14 , V_5 ;
V_11 [ V_12 - 1 ] = 0 ;
for ( line = 0 ; line < V_15 ; line ++ ) {
if ( F_7 ( V_11 , V_12 , V_1 -> V_7 ) != NULL ) {
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
else {
if ( F_5 ( V_1 -> V_7 ) )
* V_2 = 0 ;
else
* V_2 = F_4 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
}
* V_2 = 0 ;
return FALSE ;
}
int F_8 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
if ( ! F_6 ( V_1 , V_2 , V_3 ) ) {
if ( * V_2 == 0 )
return 0 ;
else
return - 1 ;
}
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = 0 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
return 1 ;
}
static T_4 V_24 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_29 )
{
T_1 V_30 ;
T_6 * V_11 ;
int V_31 ;
V_30 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_30 < 1 )
return FALSE ;
F_9 ( V_1 -> V_32 , V_33 ) ;
V_11 = F_10 ( V_1 -> V_32 ) ;
V_31 = F_11 ( V_1 , V_1 -> V_7 , V_11 , V_2 , V_3 ) ;
if ( V_31 == - 1 )
return FALSE ;
V_1 -> V_34 . V_35 . V_36 = 0 ;
* V_29 = V_30 ;
return TRUE ;
}
static T_4
V_26 ( T_2 * V_1 , T_1 V_37 ,
union V_38 * V_34 V_39 ,
T_6 * V_40 , int V_41 , int * V_2 , T_3 * * V_3 )
{
int V_31 ;
if ( F_12 ( V_1 -> V_42 , V_37 - 1 , V_43 , V_2 ) == - 1 )
return FALSE ;
V_31 = F_11 ( NULL , V_1 -> V_42 , V_40 , V_2 ,
V_3 ) ;
if ( V_31 != V_41 ) {
if ( V_31 != - 1 ) {
* V_2 = V_44 ;
* V_3 = F_13 ( L_1 ,
V_31 , V_41 ) ;
}
return FALSE ;
}
V_34 -> V_35 . V_36 = 0 ;
return TRUE ;
}
static int
F_11 ( T_2 * V_1 , T_7 V_7 , T_6 * V_11 , int * V_2 ,
T_3 * * V_3 )
{
char line [ V_12 ] ;
int V_45 ;
int V_46 , V_31 , V_47 ;
int V_48 , V_49 , V_50 ;
struct V_51 V_51 ;
char V_52 [ 4 ] = L_2 ;
T_3 * V_53 ;
static const T_3 V_54 [] = L_3 ;
int V_55 , V_56 ;
V_46 = 0 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
if ( F_7 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_57 ;
}
return - 1 ;
}
V_53 = strstr ( line , V_58 ) ;
if( ! V_53 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_4 ) ;
return - 1 ;
}
V_53 += strlen ( V_58 ) ;
if( F_15 ( V_53 , & V_11 [ V_46 ] , V_59 , V_60 )
!= V_61 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_5 ) ;
return - 1 ;
}
V_46 += V_61 ;
V_53 = line ;
while( ! isxdigit ( ( V_62 ) * V_53 ) ) {
V_53 ++ ;
}
if( F_15 ( V_53 , & V_11 [ V_46 ] , V_59 ,
V_60 ) != V_61 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_6 ) ;
return - 1 ;
}
V_46 += V_61 ;
if ( F_7 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_57 ;
}
return - 1 ;
}
if( strlen ( line ) < V_63 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_7 ) ;
return - 1 ;
}
V_45 = sscanf ( line + V_63 ,
L_8 ,
& V_31 ,
& V_51 . V_64 , V_52 ,
& V_51 . V_65 , & V_51 . V_66 , & V_51 . V_67 ,
& V_51 . V_68 , & V_47 ) ;
if ( V_45 != 8 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_9 ) ;
return - 1 ;
}
if( strncmp ( & line [ V_69 ] , V_70 ,
strlen ( V_70 ) ) == 0 ) {
if( F_15 ( & line [ V_71 ] , & V_11 [ V_46 ] , V_59 ,
V_60 ) != V_72 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_10 ) ;
return - 1 ;
}
V_46 += V_72 ;
} else {
V_48 = V_46 ;
V_46 += V_73 ;
V_49 = V_46 ;
if( F_15 ( & line [ V_74 ] , & V_11 [ V_46 ] , V_59 ,
V_60 ) != V_75 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_11 ) ;
return - 1 ;
}
V_46 += V_75 ;
if( F_15 ( & line [ V_76 ] , & V_11 [ V_46 ] , V_59 ,
V_60 ) != V_77 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_12 ) ;
return - 1 ;
}
if( ( V_11 [ V_46 ] & V_78 ) != V_79 ) {
if( F_15 ( & line [ V_80 ] ,
& V_11 [ V_46 + V_77 ] , V_60 ,
V_59 ) != V_81 - V_77 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_13 ) ;
return - 1 ;
}
V_46 += V_81 ;
} else {
V_46 += V_77 ;
}
if( strncmp ( & line [ V_82 ] , V_83 ,
strlen ( V_83 ) ) == 0 ) {
if( F_15 ( & line [ V_80 ] , & V_11 [ V_46 ] , V_59 ,
V_84 ) != V_85 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_14 ) ;
return - 1 ;
}
V_46 += V_85 ;
}
V_50 = V_46 - V_49 + V_31 ;
V_11 [ V_48 ] = ( V_50 ) >> 8 ;
V_11 [ V_48 + 1 ] = ( V_50 ) & 0xFF ;
}
if ( V_1 ) {
V_1 -> V_86 . V_87 = V_88 | V_89 ;
V_53 = strstr ( V_54 , V_52 ) ;
if ( V_53 )
V_51 . V_90 = ( int ) ( V_53 - V_54 ) / 3 ;
V_51 . V_65 -= 1900 ;
V_51 . V_91 = - 1 ;
V_1 -> V_86 . V_92 . V_93 = mktime ( & V_51 ) ;
V_1 -> V_86 . V_92 . V_94 = V_47 * 10000000 ;
V_1 -> V_86 . V_95 = V_46 + V_31 ;
V_1 -> V_86 . V_41 = V_46 + V_31 ;
}
V_55 = 0 ;
while ( V_55 < V_31 ) {
if ( F_7 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_57 ;
}
return - 1 ;
}
if ( ! ( V_56 = F_16 ( line ,
& V_11 [ V_46 + V_55 ] , V_55 ) ) ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_15 ) ;
return - 1 ;
}
V_55 += V_56 ;
if ( V_55 > V_31 ) {
* V_2 = V_44 ;
* V_3 = F_14 ( L_16 ) ;
return - 1 ;
}
}
return V_46 + V_31 ;
}
static T_8
F_16 ( char * V_96 , T_6 * V_11 , int V_97 ) {
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
if( ! isspace ( ( V_62 ) V_96 [ V_98 ] ) ) {
if( isdigit ( ( V_62 ) V_96 [ V_98 ] ) ) {
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
return F_15 ( & V_96 [ V_98 ] , V_11 , V_106 , V_107 ) ;
}
static T_8
F_15 ( char * V_108 , T_6 * V_11 , char V_109 , char V_110 ) {
int V_98 , V_55 ;
V_98 = 0 ;
V_55 = 0 ;
while( V_108 [ V_98 ] != V_110 ) {
if( ! ( isxdigit ( ( V_62 ) V_108 [ V_98 ] ) &&
isxdigit ( ( V_62 ) V_108 [ V_98 + 1 ] ) ) ) {
return 0 ;
}
if( isdigit ( ( V_62 ) V_108 [ V_98 ] ) ) {
V_11 [ V_55 ] = ( V_108 [ V_98 ] - '0' ) << 4 ;
} else {
V_11 [ V_55 ] = ( toupper ( V_108 [ V_98 ] ) - 'A' + 10 ) << 4 ;
}
V_98 ++ ;
if( isdigit ( ( V_62 ) V_108 [ V_98 ] ) ) {
V_11 [ V_55 ] += V_108 [ V_98 ] - '0' ;
} else {
V_11 [ V_55 ] += toupper ( V_108 [ V_98 ] ) - 'A' + 10 ;
}
V_98 ++ ;
V_55 ++ ;
while( V_108 [ V_98 ] == V_109 ) {
V_98 ++ ;
}
}
return V_55 ;
}
