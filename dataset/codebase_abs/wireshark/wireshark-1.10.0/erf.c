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
F_12 ( V_1 -> V_55 , V_15 ) ;
F_13 ( F_14 ( V_1 -> V_55 ) ,
( V_56 ) ( V_15 ) , V_1 -> V_20 , V_2 , V_3 ) ;
} while ( V_52 . type == V_24 );
return TRUE ;
}
static T_10 V_48 ( T_1 * V_1 , T_11 V_57 ,
struct V_58 * V_54 , T_8 * V_59 ,
int T_12 V_60 , int * V_2 , T_2 * * V_3 )
{
T_4 V_52 ;
T_5 V_15 ;
if ( F_5 ( V_1 -> V_61 , V_57 , V_39 , V_2 ) == - 1 )
return FALSE ;
do {
if ( ! F_11 ( V_1 -> V_61 , V_54 , & V_52 ,
V_2 , V_3 , NULL , & V_15 ) )
return FALSE ;
} while ( V_52 . type == V_24 );
F_13 ( V_59 , ( int ) V_15 , V_1 -> V_61 , V_2 ,
V_3 ) ;
return TRUE ;
}
static int F_11 ( T_13 V_20 ,
struct V_58 * V_54 ,
T_4 * V_52 ,
int * V_2 ,
T_2 * * V_3 ,
T_5 * V_53 ,
T_5 * V_15 )
{
union V_62 * V_63 = & V_54 -> V_63 ;
T_5 V_13 ;
T_8 V_64 [ 8 ] ;
T_7 V_65 ;
T_8 type = 0 ;
T_6 V_14 ;
T_5 V_66 = 0 ;
int V_4 = 0 ;
int V_67 = sizeof( V_63 -> erf . V_68 ) / sizeof( struct V_69 ) ;
F_13 ( V_52 , sizeof( * V_52 ) , V_20 , V_2 ,
V_3 ) ;
if ( V_53 != NULL ) {
* V_53 = sizeof( * V_52 ) ;
}
* V_15 = F_4 ( V_52 -> V_16 ) - ( T_5 ) sizeof( * V_52 ) ;
if ( * V_15 > V_23 ) {
* V_2 = V_70 ;
* V_3 = F_15 ( L_2 ,
* V_15 , V_23 ) ;
return FALSE ;
}
if ( * V_15 == 0 ) {
if ( ( V_52 -> type & 0x7F ) != V_24 ) {
* V_2 = V_70 ;
* V_3 = F_15 ( L_3 ) ;
return FALSE ;
}
}
{
T_7 V_11 = F_6 ( & V_52 -> V_11 ) ;
V_54 -> V_71 = V_72 | V_73 | V_74 ;
V_54 -> V_11 . V_75 = ( long ) ( V_11 >> 32 ) ;
V_11 = ( ( V_11 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_11 += ( V_11 & 0x80000000 ) << 1 ;
V_54 -> V_11 . V_76 = ( ( int ) ( V_11 >> 32 ) ) ;
if ( V_54 -> V_11 . V_76 >= 1000000000 ) {
V_54 -> V_11 . V_76 -= 1000000000 ;
V_54 -> V_11 . V_75 += 1 ;
}
V_54 -> V_77 = ( V_52 -> V_78 & 0x03 ) ;
}
memset ( & V_63 -> erf , 0 , sizeof( V_63 -> erf ) ) ;
V_63 -> erf . V_54 . V_11 = F_6 ( & V_52 -> V_11 ) ;
V_63 -> erf . V_54 . type = V_52 -> type ;
V_63 -> erf . V_54 . V_78 = V_52 -> V_78 ;
V_63 -> erf . V_54 . V_16 = F_4 ( V_52 -> V_16 ) ;
V_63 -> erf . V_54 . V_79 = F_4 ( V_52 -> V_79 ) ;
V_63 -> erf . V_54 . V_80 = F_4 ( V_52 -> V_80 ) ;
type = V_52 -> type ;
while ( type & 0x80 ) {
F_13 ( & V_64 , sizeof( V_64 ) , V_20 , V_2 ,
V_3 ) ;
if ( V_53 != NULL )
* V_53 += ( T_5 ) sizeof( V_64 ) ;
* V_15 -= ( T_5 ) sizeof( V_64 ) ;
V_66 += ( T_5 ) sizeof( V_64 ) ;
V_65 = F_16 ( V_64 ) ;
if ( V_4 < V_67 )
memcpy ( & V_63 -> erf . V_68 [ V_4 ] . V_81 , & V_65 , sizeof( V_65 ) ) ;
type = V_64 [ 0 ] ;
V_4 ++ ;
}
switch ( V_52 -> type & 0x7F ) {
case V_82 :
case V_83 :
case V_84 :
case V_85 :
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
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
break;
case V_36 :
case V_37 :
case V_38 :
F_13 ( & V_14 , sizeof( V_14 ) , V_20 , V_2 ,
V_3 ) ;
if ( V_53 != NULL )
* V_53 += ( T_5 ) sizeof( V_14 ) ;
* V_15 -= ( T_5 ) sizeof( V_14 ) ;
V_66 += ( T_5 ) sizeof( V_14 ) ;
V_63 -> erf . V_91 . V_14 = F_17 ( V_14 ) ;
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
V_66 += ( T_5 ) sizeof( V_13 ) ;
V_63 -> erf . V_91 . V_13 = F_18 ( V_13 ) ;
break;
case V_92 :
case V_93 :
default:
* V_2 = V_94 ;
* V_3 = F_15 ( L_4 ,
V_52 -> type ) ;
return FALSE ;
}
{
V_54 -> V_95 = F_17 ( V_52 -> V_80 ) ;
V_54 -> V_96 = F_19 ( F_17 ( V_52 -> V_80 ) ,
F_17 ( V_52 -> V_16 ) - ( T_5 ) sizeof( * V_52 ) - V_66 ) ;
}
if ( * V_15 > V_23 ) {
* V_2 = V_70 ;
* V_3 = F_15 ( L_2 ,
* V_15 , V_23 ) ;
return FALSE ;
}
return TRUE ;
}
static int F_20 ( int V_97 )
{
unsigned int V_4 ;
for( V_4 = 0 ; V_4 < V_98 ; V_4 ++ ) {
if( V_99 [ V_4 ] . V_100 == V_97 )
return V_99 [ V_4 ] . V_101 ;
}
return - 1 ;
}
static T_10 F_21 ( T_14 * V_102 , int V_97 , const union V_62 * V_63 , int * V_2 )
{
T_8 V_103 [ sizeof( struct V_104 ) ] ;
T_8 V_105 [ ( ( sizeof( struct V_106 ) > sizeof( struct V_107 ) ) ?
sizeof( struct V_106 ) : sizeof( struct V_107 ) ) ] ;
T_8 V_81 [ 8 * V_108 ] ;
T_9 V_109 = 0 ;
T_9 V_110 = 0 ;
int V_4 = 0 ;
switch( V_97 ) {
case V_44 :
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
F_22 ( & V_103 [ 0 ] , V_63 -> erf . V_54 . V_11 ) ;
V_103 [ 8 ] = V_63 -> erf . V_54 . type ;
V_103 [ 9 ] = V_63 -> erf . V_54 . V_78 ;
F_23 ( & V_103 [ 10 ] , V_63 -> erf . V_54 . V_16 ) ;
F_23 ( & V_103 [ 12 ] , V_63 -> erf . V_54 . V_79 ) ;
F_23 ( & V_103 [ 14 ] , V_63 -> erf . V_54 . V_80 ) ;
V_109 = sizeof( struct V_111 ) ;
switch( V_63 -> erf . V_54 . type & 0x7F ) {
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
F_24 ( & V_105 [ 0 ] , V_63 -> erf . V_91 . V_13 ) ;
V_110 += ( int ) sizeof( struct V_106 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
F_23 ( & V_105 [ 0 ] , V_63 -> erf . V_91 . V_14 ) ;
V_110 += ( int ) sizeof( struct V_107 ) ;
break;
default:
break;
}
break;
default:
return FALSE ;
}
if ( ! F_25 ( V_102 , V_103 , V_109 , V_2 ) )
return FALSE ;
V_102 -> V_112 += V_109 ;
if( ( V_63 -> erf . V_54 . type & 0x80 ) != 0 ) {
do{
F_26 ( V_81 + ( V_4 * 8 ) , V_63 -> erf . V_68 [ V_4 ] . V_81 ) ;
if( V_4 == V_108 - 1 ) V_81 [ V_4 * 8 ] = V_81 [ V_4 * 8 ] & 0x7F ;
V_4 ++ ;
}while( ( V_81 [ 0 ] & 0x80 ) != 0 && V_4 < V_108 );
if ( ! F_25 ( V_102 , V_81 , V_108 * V_4 , V_2 ) )
return FALSE ;
V_102 -> V_112 += V_108 * V_4 ;
}
if( ! F_25 ( V_102 , V_105 , V_110 , V_2 ) )
return FALSE ;
V_102 -> V_112 += V_110 ;
return TRUE ;
}
static T_10 F_27 (
T_14 * V_102 ,
const struct V_58 * V_54 ,
const T_8 * V_59 ,
int * V_2 )
{
const union V_62 * V_63 = & V_54 -> V_63 ;
union V_62 V_113 ;
int V_97 ;
T_11 V_114 = 0 ;
int V_4 ;
int V_115 = 0 ;
T_10 V_116 = FALSE ;
T_5 V_117 = 0x00000000 ;
if( V_102 -> V_97 == V_118 ) {
V_97 = V_54 -> V_119 ;
} else{
V_97 = V_102 -> V_97 ;
}
if( V_97 == V_44 ) {
V_114 = V_102 -> V_112 + V_63 -> erf . V_54 . V_16 ;
if( ! F_21 ( V_102 , V_97 , V_63 , V_2 ) ) return FALSE ;
if( ! F_25 ( V_102 , V_59 , V_54 -> V_96 , V_2 ) ) return FALSE ;
V_102 -> V_112 += V_54 -> V_96 ;
while( V_102 -> V_112 < V_114 ) {
if( ! F_25 ( V_102 , L_5 , 1 , V_2 ) ) return FALSE ;
V_102 -> V_112 ++ ;
}
return TRUE ;
}
V_113 . erf . V_54 . V_11 = ( ( T_7 ) V_54 -> V_11 . V_75 << 32 ) + ( ( ( T_7 ) V_54 -> V_11 . V_76 << 32 ) / 1000 / 1000 / 1000 ) ;
V_113 . erf . V_54 . type = F_20 ( V_97 ) ;
V_113 . erf . V_54 . V_78 = 0x4 ;
V_113 . erf . V_54 . V_79 = 0 ;
V_113 . erf . V_54 . V_16 = V_54 -> V_96 + 16 ;
V_113 . erf . V_54 . V_80 = V_54 -> V_95 ;
switch( V_113 . erf . V_54 . type ) {
case V_36 :
V_113 . erf . V_54 . V_16 += 2 ;
if ( V_63 -> V_120 . V_121 != 4 ) {
if( ! ( V_54 -> V_96 < V_54 -> V_95 ) ) {
V_117 = F_28 ( V_59 , V_54 -> V_96 , 0xFFFFFFFF ) ;
V_113 . erf . V_54 . V_16 += 4 ;
V_113 . erf . V_54 . V_80 += 4 ;
V_116 = TRUE ;
}
}
break;
case V_86 :
if( ! ( V_54 -> V_96 < V_54 -> V_95 ) ) {
V_117 = F_28 ( V_59 , V_54 -> V_96 , 0xFFFFFFFF ) ;
V_113 . erf . V_54 . V_16 += 4 ;
V_113 . erf . V_54 . V_80 += 4 ;
V_116 = TRUE ;
}
break;
default:
break;
}
V_114 = ( 8 - ( V_113 . erf . V_54 . V_16 % 8 ) ) % 8 ;
if( V_54 -> V_96 < V_54 -> V_95 ) {
V_115 = ( 8 - ( V_122 ) V_114 ) % 8 ;
V_113 . erf . V_54 . V_16 -= V_115 ;
} else{
V_113 . erf . V_54 . V_16 += ( V_123 ) V_114 ;
}
if( ! F_21 ( V_102 , V_44 , & V_113 , V_2 ) ) return FALSE ;
if( ! F_25 ( V_102 , V_59 , V_54 -> V_96 - V_115 , V_2 ) ) return FALSE ;
V_102 -> V_112 += V_54 -> V_96 - V_115 ;
if( V_116 ) {
if( ! F_25 ( V_102 , & V_117 , 4 , V_2 ) ) return FALSE ;
V_102 -> V_112 += 4 ;
}
if( V_115 == 0 ) {
for( V_4 = ( V_123 ) V_114 ; V_4 > 0 ; V_4 -- ) {
if( ! F_25 ( V_102 , L_5 , 1 , V_2 ) ) return FALSE ;
V_102 -> V_112 ++ ;
}
}
return TRUE ;
}
int F_29 ( int V_97 )
{
if( V_97 == V_118 )
return 0 ;
if ( F_20 ( V_97 ) == - 1 )
return V_94 ;
return 0 ;
}
int F_30 ( T_14 * V_102 , int * V_2 )
{
V_102 -> V_124 = F_27 ;
V_102 -> V_125 = NULL ;
switch( V_102 -> V_40 ) {
case V_41 :
V_102 -> V_49 = V_50 ;
break;
default:
* V_2 = V_126 ;
return FALSE ;
break;
}
return TRUE ;
}
int F_9 ( T_1 * V_1 )
{
T_15 V_127 ;
int V_4 ;
if ( ! V_1 )
return - 1 ;
if ( ! V_1 -> V_128 ) {
V_1 -> V_128 = F_31 ( FALSE , FALSE , sizeof( T_15 ) ) ;
}
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_129 = V_44 ;
V_127 . V_130 = 1000000000 ;
V_127 . V_131 = F_32 ( V_44 ) ;
V_127 . V_132 = 65535 ;
V_127 . V_133 = NULL ;
V_127 . V_134 = 0 ;
V_127 . V_135 = 0x09 ;
V_127 . V_136 = NULL ;
V_127 . V_137 = 0 ;
V_127 . V_138 = NULL ;
V_127 . V_139 = NULL ;
V_127 . V_140 = 0 ;
V_127 . V_141 = 0 ;
V_127 . V_142 = NULL ;
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ ) {
V_127 . V_143 = F_15 ( L_6 , 'A' + V_4 ) ;
V_127 . V_144 = F_15 ( L_7 , V_4 , 'A' + V_4 ) ;
F_33 ( V_1 -> V_128 , V_127 ) ;
V_1 -> V_145 ++ ;
}
return 0 ;
}
