extern int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 , V_5 , V_6 = V_7 ;
int V_8 = 0 ;
char * V_9 ;
T_3 V_10 , V_11 ;
T_4 V_12 ;
T_5 V_13 ;
T_6 V_14 ;
T_5 V_15 ;
T_6 V_16 ;
T_7 V_17 ;
T_8 type ;
T_9 V_18 ;
T_2 * V_19 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
if ( ( V_9 = getenv ( L_1 ) ) != NULL ) {
if ( ( V_5 = atoi ( V_9 ) ) > 0 && V_5 < 101 ) {
V_6 = V_5 ;
}
}
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
V_18 = F_2 ( & V_12 , sizeof( V_12 ) , V_1 -> V_20 ) ;
if ( V_18 == 0 ) break;
if ( V_18 != sizeof( V_12 ) ) {
* V_2 = F_3 ( V_1 -> V_20 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_21 ) {
return - 1 ;
} else {
if ( V_4 < V_22 ) {
return 0 ;
} else {
break;
}
}
}
V_16 = F_4 ( V_12 . V_16 ) ;
if ( V_16 < 16 ) {
return 0 ;
}
V_15 = V_16 - ( T_5 ) sizeof( V_12 ) ;
if ( V_15 > V_23 ) {
return 0 ;
}
if ( ( V_12 . type & 0x7F ) == V_24 ) {
if ( F_5 ( V_1 -> V_20 , V_15 , V_25 , V_2 ) == - 1 ) {
return - 1 ;
}
continue;
}
if ( ( V_12 . type & 0x7F ) == 0 || ( V_12 . type & 0x7F ) > V_26 ) {
return 0 ;
}
if ( ( V_12 . type & 0x7F ) > V_27 ) {
return 0 ;
}
if ( ( V_11 = F_6 ( & V_12 . V_11 ) ) < V_10 ) {
if ( ( ( V_10 - V_11 ) >> 32 ) > 1 ) {
return 0 ;
}
}
if ( ( V_8 ) && ( V_11 > V_10 ) && ( ( ( V_11 - V_10 ) >> 32 ) > 3600 * 24 * 7 ) ) {
return 0 ;
}
memcpy ( & V_10 , & V_11 , sizeof( V_10 ) ) ;
type = V_12 . type ;
while ( type & 0x80 ) {
if ( F_2 ( & V_17 , sizeof( V_17 ) , V_1 -> V_20 ) != sizeof( V_17 ) ) {
* V_2 = F_3 ( V_1 -> V_20 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_21 ;
return - 1 ;
}
V_15 -= ( T_5 ) sizeof( V_17 ) ;
memcpy ( & type , & V_17 , sizeof( type ) ) ;
}
switch( V_12 . type & 0x7F ) {
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
if ( F_2 ( & V_13 , sizeof( V_13 ) , V_1 -> V_20 ) != sizeof( V_13 ) ) {
* V_2 = F_3 ( V_1 -> V_20 , V_3 ) ;
return - 1 ;
}
V_15 -= ( T_5 ) sizeof( V_13 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
if ( F_2 ( & V_14 , sizeof( V_14 ) , V_1 -> V_20 ) != sizeof( V_14 ) ) {
* V_2 = F_3 ( V_1 -> V_20 , V_3 ) ;
return - 1 ;
}
V_15 -= ( T_5 ) sizeof( V_14 ) ;
break;
default:
break;
}
if ( V_15 > V_23 ) {
return 0 ;
}
V_19 = ( T_2 * ) F_7 ( V_15 ) ;
V_18 = F_2 ( V_19 , V_15 , V_1 -> V_20 ) ;
F_8 ( V_19 ) ;
if ( V_18 != V_15 ) {
if ( V_4 < V_22 ) {
return 0 ;
}
}
V_8 = 1 ;
}
if ( F_5 ( V_1 -> V_20 , 0L , V_39 , V_2 ) == - 1 ) {
return - 1 ;
}
V_1 -> V_40 = V_41 ;
V_1 -> V_42 = 0 ;
V_1 -> V_43 = V_44 ;
V_1 -> V_45 = V_46 ;
V_1 -> V_47 = V_48 ;
V_1 -> V_49 = V_50 ;
F_9 ( V_1 ) ;
return 1 ;
}
static T_10 V_46 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_11 * V_51 )
{
T_4 V_52 ;
T_5 V_15 , V_53 ;
* V_51 = F_10 ( V_1 -> V_20 ) ;
do {
if ( ! F_11 ( V_1 -> V_20 ,
& V_1 -> V_54 , & V_52 ,
V_2 , V_3 , & V_53 , & V_15 ) ) {
return FALSE ;
}
if ( ! F_12 ( V_1 -> V_20 , V_1 -> V_55 , V_15 ,
V_2 , V_3 ) )
return FALSE ;
} while ( V_52 . type == V_24 );
return TRUE ;
}
static T_10 V_48 ( T_1 * V_1 , T_11 V_56 ,
struct V_57 * V_54 , T_12 * V_58 ,
int T_13 V_59 , int * V_2 , T_2 * * V_3 )
{
T_4 V_52 ;
T_5 V_15 ;
if ( F_5 ( V_1 -> V_60 , V_56 , V_39 , V_2 ) == - 1 )
return FALSE ;
do {
if ( ! F_11 ( V_1 -> V_60 , V_54 , & V_52 ,
V_2 , V_3 , NULL , & V_15 ) )
return FALSE ;
} while ( V_52 . type == V_24 );
return F_12 ( V_1 -> V_60 , V_58 , V_15 ,
V_2 , V_3 ) ;
}
static int F_11 ( T_14 V_20 ,
struct V_57 * V_54 ,
T_4 * V_52 ,
int * V_2 ,
T_2 * * V_3 ,
T_5 * V_53 ,
T_5 * V_15 )
{
union V_61 * V_62 = & V_54 -> V_62 ;
T_5 V_13 ;
T_8 V_63 [ 8 ] ;
T_7 V_64 ;
T_8 type = 0 ;
T_6 V_14 ;
T_5 V_65 = 0 ;
int V_4 = 0 ;
int V_66 = sizeof( V_62 -> erf . V_67 ) / sizeof( struct V_68 ) ;
F_13 ( V_52 , sizeof( * V_52 ) , V_20 , V_2 ,
V_3 ) ;
if ( V_53 != NULL ) {
* V_53 = sizeof( * V_52 ) ;
}
* V_15 = F_4 ( V_52 -> V_16 ) - ( T_5 ) sizeof( * V_52 ) ;
if ( * V_15 > V_23 ) {
* V_2 = V_69 ;
* V_3 = F_14 ( L_2 ,
* V_15 , V_23 ) ;
return FALSE ;
}
if ( * V_15 == 0 ) {
if ( ( V_52 -> type & 0x7F ) != V_24 ) {
* V_2 = V_69 ;
* V_3 = F_14 ( L_3 ) ;
return FALSE ;
}
}
{
T_7 V_11 = F_6 ( & V_52 -> V_11 ) ;
V_54 -> V_70 = V_71 | V_72 | V_73 ;
V_54 -> V_11 . V_74 = ( long ) ( V_11 >> 32 ) ;
V_11 = ( ( V_11 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_11 += ( V_11 & 0x80000000 ) << 1 ;
V_54 -> V_11 . V_75 = ( ( int ) ( V_11 >> 32 ) ) ;
if ( V_54 -> V_11 . V_75 >= 1000000000 ) {
V_54 -> V_11 . V_75 -= 1000000000 ;
V_54 -> V_11 . V_74 += 1 ;
}
V_54 -> V_76 = ( V_52 -> V_77 & 0x03 ) ;
}
memset ( & V_62 -> erf , 0 , sizeof( V_62 -> erf ) ) ;
V_62 -> erf . V_54 . V_11 = F_6 ( & V_52 -> V_11 ) ;
V_62 -> erf . V_54 . type = V_52 -> type ;
V_62 -> erf . V_54 . V_77 = V_52 -> V_77 ;
V_62 -> erf . V_54 . V_16 = F_4 ( V_52 -> V_16 ) ;
V_62 -> erf . V_54 . V_78 = F_4 ( V_52 -> V_78 ) ;
V_62 -> erf . V_54 . V_79 = F_4 ( V_52 -> V_79 ) ;
type = V_52 -> type ;
while ( type & 0x80 ) {
F_13 ( & V_63 , sizeof( V_63 ) , V_20 , V_2 ,
V_3 ) ;
if ( V_53 != NULL )
* V_53 += ( T_5 ) sizeof( V_63 ) ;
* V_15 -= ( T_5 ) sizeof( V_63 ) ;
V_65 += ( T_5 ) sizeof( V_63 ) ;
V_64 = F_15 ( V_63 ) ;
if ( V_4 < V_66 )
memcpy ( & V_62 -> erf . V_67 [ V_4 ] . V_80 , & V_64 , sizeof( V_64 ) ) ;
type = V_63 [ 0 ] ;
V_4 ++ ;
}
switch ( V_52 -> type & 0x7F ) {
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_27 :
#if 0
{
phdr->len = g_htons(erf_header->wlen);
phdr->caplen = g_htons(erf_header->wlen);
}
return TRUE;
#endif
break;
case V_24 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
break;
case V_36 :
case V_37 :
case V_38 :
F_13 ( & V_14 , sizeof( V_14 ) , V_20 , V_2 ,
V_3 ) ;
if ( V_53 != NULL )
* V_53 += ( T_5 ) sizeof( V_14 ) ;
* V_15 -= ( T_5 ) sizeof( V_14 ) ;
V_65 += ( T_5 ) sizeof( V_14 ) ;
V_62 -> erf . V_90 . V_14 = F_16 ( V_14 ) ;
break;
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
F_13 ( & V_13 , sizeof( V_13 ) , V_20 , V_2 ,
V_3 ) ;
if ( V_53 != NULL )
* V_53 += ( T_5 ) sizeof( V_13 ) ;
* V_15 -= ( T_5 ) sizeof( V_13 ) ;
V_65 += ( T_5 ) sizeof( V_13 ) ;
V_62 -> erf . V_90 . V_13 = F_17 ( V_13 ) ;
break;
case V_91 :
case V_92 :
default:
* V_2 = V_93 ;
* V_3 = F_14 ( L_4 ,
V_52 -> type ) ;
return FALSE ;
}
{
V_54 -> V_94 = F_16 ( V_52 -> V_79 ) ;
V_54 -> V_95 = F_18 ( F_16 ( V_52 -> V_79 ) ,
F_16 ( V_52 -> V_16 ) - ( T_5 ) sizeof( * V_52 ) - V_65 ) ;
}
if ( * V_15 > V_23 ) {
* V_2 = V_69 ;
* V_3 = F_14 ( L_2 ,
* V_15 , V_23 ) ;
return FALSE ;
}
return TRUE ;
}
static int F_19 ( int V_96 )
{
unsigned int V_4 ;
for( V_4 = 0 ; V_4 < V_97 ; V_4 ++ ) {
if( V_98 [ V_4 ] . V_99 == V_96 )
return V_98 [ V_4 ] . V_100 ;
}
return - 1 ;
}
static T_10 F_20 ( T_15 * V_101 , int V_96 , const union V_61 * V_62 , int * V_2 )
{
T_8 V_102 [ sizeof( struct V_103 ) ] ;
T_8 V_104 [ ( ( sizeof( struct V_105 ) > sizeof( struct V_106 ) ) ?
sizeof( struct V_105 ) : sizeof( struct V_106 ) ) ] ;
T_8 V_80 [ 8 * V_107 ] ;
T_9 V_108 = 0 ;
T_9 V_109 = 0 ;
int V_4 = 0 ;
T_8 V_110 = 0 ;
switch( V_96 ) {
case V_44 :
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
F_21 ( & V_102 [ 0 ] , V_62 -> erf . V_54 . V_11 ) ;
V_102 [ 8 ] = V_62 -> erf . V_54 . type ;
V_102 [ 9 ] = V_62 -> erf . V_54 . V_77 ;
F_22 ( & V_102 [ 10 ] , V_62 -> erf . V_54 . V_16 ) ;
F_22 ( & V_102 [ 12 ] , V_62 -> erf . V_54 . V_78 ) ;
F_22 ( & V_102 [ 14 ] , V_62 -> erf . V_54 . V_79 ) ;
V_108 = sizeof( struct V_111 ) ;
switch( V_62 -> erf . V_54 . type & 0x7F ) {
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
F_23 ( & V_104 [ 0 ] , V_62 -> erf . V_90 . V_13 ) ;
V_109 += ( int ) sizeof( struct V_105 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
F_22 ( & V_104 [ 0 ] , V_62 -> erf . V_90 . V_14 ) ;
V_109 += ( int ) sizeof( struct V_106 ) ;
break;
default:
break;
}
break;
default:
return FALSE ;
}
if ( ! F_24 ( V_101 , V_102 , V_108 , V_2 ) )
return FALSE ;
V_101 -> V_112 += V_108 ;
V_110 = V_62 -> erf . V_54 . type & 0x80 ;
if( V_110 ) {
do{
F_25 ( V_80 + ( V_4 * 8 ) , V_62 -> erf . V_67 [ V_4 ] . V_80 ) ;
if( V_4 == V_107 - 1 ) V_80 [ V_4 * 8 ] = V_80 [ V_4 * 8 ] & 0x7F ;
V_110 = V_80 [ V_4 * 8 ] & 0x80 ;
V_4 ++ ;
}while( V_110 && V_4 < V_107 );
if ( ! F_24 ( V_101 , V_80 , 8 * V_4 , V_2 ) )
return FALSE ;
V_101 -> V_112 += 8 * V_4 ;
}
if( ! F_24 ( V_101 , V_104 , V_109 , V_2 ) )
return FALSE ;
V_101 -> V_112 += V_109 ;
return TRUE ;
}
static T_10 F_26 (
T_15 * V_101 ,
const struct V_57 * V_54 ,
const T_8 * V_113 ,
int * V_2 )
{
const union V_61 * V_62 = & V_54 -> V_62 ;
union V_61 V_114 ;
int V_96 ;
T_11 V_115 = 0 ;
int V_4 ;
int V_116 = 0 ;
T_10 V_117 = FALSE ;
T_5 V_118 = 0x00000000 ;
if( V_101 -> V_96 == V_119 ) {
V_96 = V_54 -> V_120 ;
} else{
V_96 = V_101 -> V_96 ;
}
if( V_96 == V_44 ) {
V_115 = V_101 -> V_112 + V_62 -> erf . V_54 . V_16 ;
if( ! F_20 ( V_101 , V_96 , V_62 , V_2 ) ) return FALSE ;
if( ! F_24 ( V_101 , V_113 , V_54 -> V_95 , V_2 ) ) return FALSE ;
V_101 -> V_112 += V_54 -> V_95 ;
while( V_101 -> V_112 < V_115 ) {
if( ! F_24 ( V_101 , L_5 , 1 , V_2 ) ) return FALSE ;
V_101 -> V_112 ++ ;
}
return TRUE ;
}
V_114 . erf . V_54 . V_11 = ( ( T_7 ) V_54 -> V_11 . V_74 << 32 ) + ( ( ( T_7 ) V_54 -> V_11 . V_75 << 32 ) / 1000 / 1000 / 1000 ) ;
V_114 . erf . V_54 . type = F_19 ( V_96 ) ;
V_114 . erf . V_54 . V_77 = 0x4 ;
V_114 . erf . V_54 . V_78 = 0 ;
V_114 . erf . V_54 . V_16 = V_54 -> V_95 + 16 ;
V_114 . erf . V_54 . V_79 = V_54 -> V_94 ;
switch( V_114 . erf . V_54 . type ) {
case V_36 :
V_114 . erf . V_54 . V_16 += 2 ;
if ( V_62 -> V_121 . V_122 != 4 ) {
if( ! ( V_54 -> V_95 < V_54 -> V_94 ) ) {
V_118 = F_27 ( V_113 , V_54 -> V_95 , 0xFFFFFFFF ) ;
V_114 . erf . V_54 . V_16 += 4 ;
V_114 . erf . V_54 . V_79 += 4 ;
V_117 = TRUE ;
}
}
break;
case V_85 :
if( ! ( V_54 -> V_95 < V_54 -> V_94 ) ) {
V_118 = F_27 ( V_113 , V_54 -> V_95 , 0xFFFFFFFF ) ;
V_114 . erf . V_54 . V_16 += 4 ;
V_114 . erf . V_54 . V_79 += 4 ;
V_117 = TRUE ;
}
break;
default:
break;
}
V_115 = ( 8 - ( V_114 . erf . V_54 . V_16 % 8 ) ) % 8 ;
if( V_54 -> V_95 < V_54 -> V_94 ) {
V_116 = ( 8 - ( V_123 ) V_115 ) % 8 ;
V_114 . erf . V_54 . V_16 -= V_116 ;
} else{
V_114 . erf . V_54 . V_16 += ( V_124 ) V_115 ;
}
if( ! F_20 ( V_101 , V_44 , & V_114 , V_2 ) ) return FALSE ;
if( ! F_24 ( V_101 , V_113 , V_54 -> V_95 - V_116 , V_2 ) ) return FALSE ;
V_101 -> V_112 += V_54 -> V_95 - V_116 ;
if( V_117 ) {
if( ! F_24 ( V_101 , & V_118 , 4 , V_2 ) ) return FALSE ;
V_101 -> V_112 += 4 ;
}
if( V_116 == 0 ) {
for( V_4 = ( V_124 ) V_115 ; V_4 > 0 ; V_4 -- ) {
if( ! F_24 ( V_101 , L_5 , 1 , V_2 ) ) return FALSE ;
V_101 -> V_112 ++ ;
}
}
return TRUE ;
}
int F_28 ( int V_96 )
{
if( V_96 == V_119 )
return 0 ;
if ( F_19 ( V_96 ) == - 1 )
return V_93 ;
return 0 ;
}
int F_29 ( T_15 * V_101 , int * V_2 )
{
V_101 -> V_125 = F_26 ;
V_101 -> V_126 = NULL ;
switch( V_101 -> V_40 ) {
case V_41 :
V_101 -> V_49 = V_50 ;
break;
default:
* V_2 = V_127 ;
return FALSE ;
break;
}
return TRUE ;
}
int F_9 ( T_1 * V_1 )
{
T_16 V_128 ;
int V_4 ;
if ( ! V_1 )
return - 1 ;
if ( ! V_1 -> V_129 ) {
V_1 -> V_129 = F_30 ( FALSE , FALSE , sizeof( T_16 ) ) ;
}
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_130 = V_44 ;
V_128 . V_131 = 1000000000 ;
V_128 . V_132 = F_31 ( V_44 ) ;
V_128 . V_133 = 65535 ;
V_128 . V_134 = NULL ;
V_128 . V_135 = 0 ;
V_128 . V_136 = 0x09 ;
V_128 . V_137 = NULL ;
V_128 . V_138 = 0 ;
V_128 . V_139 = NULL ;
V_128 . V_140 = NULL ;
V_128 . V_141 = 0 ;
V_128 . V_142 = 0 ;
V_128 . V_143 = NULL ;
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ ) {
V_128 . V_144 = F_14 ( L_6 , 'A' + V_4 ) ;
V_128 . V_145 = F_14 ( L_7 , V_4 , 'A' + V_4 ) ;
F_32 ( V_1 -> V_129 , V_128 ) ;
V_1 -> V_146 ++ ;
}
return 0 ;
}
