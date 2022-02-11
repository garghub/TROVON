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
T_6 F_7 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
if ( ! F_5 ( V_1 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_18 )
return V_19 ;
return V_20 ;
}
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = 0 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
return V_32 ;
}
static T_4 V_27 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_33 )
{
T_1 V_34 ;
V_34 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_34 < 1 )
return FALSE ;
* V_33 = V_34 ;
return F_8 ( & V_1 -> V_35 , V_1 -> V_7 ,
V_1 -> V_36 , V_2 , V_3 ) ;
}
static T_4
V_29 ( T_2 * V_1 , T_1 V_37 ,
struct V_38 * V_35 , T_7 * V_11 , int * V_2 , T_3 * * V_3 )
{
if ( F_9 ( V_1 -> V_39 , V_37 - 1 , V_40 , V_2 ) == - 1 )
return FALSE ;
return F_8 ( V_35 , V_1 -> V_39 , V_11 , V_2 ,
V_3 ) ;
}
static T_4
F_8 ( struct V_38 * V_35 , T_8 V_7 , T_7 * V_11 ,
int * V_2 , T_3 * * V_3 )
{
T_9 * V_41 ;
char line [ V_12 ] ;
int V_42 ;
int V_43 , V_44 , V_45 ;
int V_46 , V_47 , V_48 ;
struct V_49 V_49 ;
char V_50 [ 4 ] = L_1 ;
T_3 * V_51 ;
static const T_3 V_52 [] = L_2 ;
int V_53 , V_54 ;
F_10 ( V_11 , V_55 ) ;
V_41 = F_11 ( V_11 ) ;
V_43 = 0 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
V_51 = strstr ( line , V_56 ) ;
if( ! V_51 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_3 ) ;
return FALSE ;
}
V_51 += strlen ( V_56 ) ;
if( F_13 ( V_51 , & V_41 [ V_43 ] , V_58 , V_59 )
!= V_60 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_4 ) ;
return FALSE ;
}
V_43 += V_60 ;
V_51 = line ;
while( ! F_14 ( * V_51 ) ) {
V_51 ++ ;
}
if( F_13 ( V_51 , & V_41 [ V_43 ] , V_58 ,
V_59 ) != V_60 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_5 ) ;
return FALSE ;
}
V_43 += V_60 ;
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
if( strlen ( line ) < V_61 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_6 ) ;
return FALSE ;
}
V_42 = sscanf ( line + V_61 ,
L_7 ,
& V_44 ,
& V_49 . V_62 , V_50 ,
& V_49 . V_63 , & V_49 . V_64 , & V_49 . V_65 ,
& V_49 . V_66 , & V_45 ) ;
if ( V_42 != 8 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_8 ) ;
return FALSE ;
}
if ( V_44 < 0 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_9 ) ;
return FALSE ;
}
if( strncmp ( & line [ V_67 ] , V_68 ,
strlen ( V_68 ) ) == 0 ) {
if( F_13 ( & line [ V_69 ] , & V_41 [ V_43 ] , V_58 ,
V_59 ) != V_70 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_10 ) ;
return FALSE ;
}
V_43 += V_70 ;
} else {
V_46 = V_43 ;
V_43 += V_71 ;
V_47 = V_43 ;
if( F_13 ( & line [ V_72 ] , & V_41 [ V_43 ] , V_58 ,
V_59 ) != V_73 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_11 ) ;
return FALSE ;
}
V_43 += V_73 ;
if( F_13 ( & line [ V_74 ] , & V_41 [ V_43 ] , V_58 ,
V_59 ) != V_75 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_12 ) ;
return FALSE ;
}
if( ( V_41 [ V_43 ] & V_76 ) != V_77 ) {
if( F_13 ( & line [ V_78 ] ,
& V_41 [ V_43 + V_75 ] , V_59 ,
V_58 ) != V_79 - V_75 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_13 ) ;
return FALSE ;
}
V_43 += V_79 ;
} else {
V_43 += V_75 ;
}
if( strncmp ( & line [ V_80 ] , V_81 ,
strlen ( V_81 ) ) == 0 ) {
if( F_13 ( & line [ V_78 ] , & V_41 [ V_43 ] , V_58 ,
V_82 ) != V_83 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_14 ) ;
return FALSE ;
}
V_43 += V_83 ;
}
V_48 = V_43 - V_47 + V_44 ;
V_41 [ V_46 ] = ( V_48 ) >> 8 ;
V_41 [ V_46 + 1 ] = ( V_48 ) & 0xFF ;
}
V_35 -> V_84 = V_85 ;
V_35 -> V_86 = V_87 | V_88 ;
V_51 = strstr ( V_52 , V_50 ) ;
if ( V_51 )
V_49 . V_89 = ( int ) ( V_51 - V_52 ) / 3 ;
V_49 . V_63 -= 1900 ;
V_49 . V_90 = - 1 ;
V_35 -> V_91 . V_92 = mktime ( & V_49 ) ;
V_35 -> V_91 . V_93 = V_45 * 10000000 ;
V_35 -> V_94 = V_43 + V_44 ;
V_35 -> V_95 = V_43 + V_44 ;
if ( V_35 -> V_94 > V_96 ) {
* V_2 = V_57 ;
* V_3 = F_15 ( L_15 ,
V_35 -> V_94 , V_96 ) ;
return FALSE ;
}
F_10 ( V_11 , V_35 -> V_94 ) ;
V_41 = F_11 ( V_11 ) ;
V_35 -> V_97 . V_98 . V_99 = 0 ;
V_53 = 0 ;
while ( V_53 < V_44 ) {
if ( F_6 ( line , V_12 , V_7 ) == NULL ) {
* V_2 = F_4 ( V_7 , V_3 ) ;
if ( * V_2 == 0 ) {
* V_2 = V_18 ;
}
return FALSE ;
}
if ( ! ( V_54 = F_16 ( line ,
& V_41 [ V_43 + V_53 ] , V_53 ) ) ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_16 ) ;
return FALSE ;
}
V_53 += V_54 ;
if ( V_53 > V_44 ) {
* V_2 = V_57 ;
* V_3 = F_12 ( L_17 ) ;
return FALSE ;
}
}
return TRUE ;
}
static T_10
F_16 ( char * V_100 , T_9 * V_11 , int V_101 ) {
int V_102 , V_14 ;
int V_103 ;
for( V_14 = 0 ; V_14 < V_104 ; V_14 ++ )
{
if( V_100 [ V_14 ] == '\0' ) {
return 0 ;
}
}
if( V_100 [ V_104 ] == V_105 )
{
V_102 = V_106 ;
}
else
{
V_102 = V_107 ;
}
while( V_14 < V_102 )
{
if( V_100 [ V_14 ] == '\0' ) {
return 0 ;
}
V_14 ++ ;
}
V_103 = 0 ;
for( V_14 = 0 ; V_14 < V_108 ; V_14 ++ ) {
if( ! F_17 ( V_100 [ V_102 ] ) ) {
if( F_18 ( V_100 [ V_102 ] ) ) {
V_103 *= 10 ;
V_103 += V_100 [ V_102 ] - '0' ;
} else {
return 0 ;
}
}
V_102 ++ ;
}
if ( V_103 != V_101 ) {
return 0 ;
}
while( V_100 [ V_102 ] != V_109 ) {
if( V_100 [ V_102 ] == '\0' ) {
return 0 ;
}
V_102 ++ ;
}
V_102 ++ ;
return F_13 ( & V_100 [ V_102 ] , V_11 , V_110 , V_111 ) ;
}
static T_10
F_13 ( char * V_112 , T_9 * V_11 , char V_113 , char V_114 ) {
int V_102 , V_53 ;
V_102 = 0 ;
V_53 = 0 ;
while( V_112 [ V_102 ] != V_114 ) {
if( ! ( F_14 ( V_112 [ V_102 ] ) &&
F_14 ( V_112 [ V_102 + 1 ] ) ) ) {
return 0 ;
}
if( F_18 ( V_112 [ V_102 ] ) ) {
V_11 [ V_53 ] = ( V_112 [ V_102 ] - '0' ) << 4 ;
} else {
V_11 [ V_53 ] = ( F_19 ( V_112 [ V_102 ] ) - 'A' + 10 ) << 4 ;
}
V_102 ++ ;
if( F_18 ( V_112 [ V_102 ] ) ) {
V_11 [ V_53 ] += V_112 [ V_102 ] - '0' ;
} else {
V_11 [ V_53 ] += F_19 ( V_112 [ V_102 ] ) - 'A' + 10 ;
}
V_102 ++ ;
V_53 ++ ;
while( V_112 [ V_102 ] == V_113 ) {
V_102 ++ ;
}
}
return V_53 ;
}
