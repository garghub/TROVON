extern T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
int V_4 , V_5 , V_6 = V_7 ;
int V_8 = 0 ;
char * V_9 ;
T_4 V_10 , V_11 ;
T_5 V_12 ;
T_6 V_13 ;
T_7 V_14 ;
T_6 V_15 ;
T_7 V_16 ;
T_8 V_17 ;
T_9 type ;
T_10 V_18 ;
T_3 * V_19 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
if ( ( V_9 = getenv ( L_1 ) ) != NULL ) {
if ( ( V_5 = atoi ( V_9 ) ) > 0 && V_5 < 101 ) {
V_6 = V_5 ;
}
}
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( ! F_2 ( V_1 -> V_20 , & V_12 , sizeof( V_12 ) , V_2 , V_3 ) ) {
if ( * V_2 == 0 ) {
break;
}
if ( * V_2 == V_21 ) {
if ( V_4 < V_22 ) {
return V_23 ;
} else {
break;
}
} else {
return V_24 ;
}
}
V_16 = F_3 ( V_12 . V_16 ) ;
if ( V_16 < 16 ) {
return V_23 ;
}
V_15 = V_16 - ( T_6 ) sizeof( V_12 ) ;
if ( V_15 > V_25 ) {
return V_23 ;
}
if ( ( V_12 . type & 0x7F ) == V_26 ) {
if ( F_4 ( V_1 -> V_20 , V_15 , V_27 , V_2 ) == - 1 ) {
return V_24 ;
}
continue;
}
if ( ( V_12 . type & 0x7F ) == 0 || ( V_12 . type & 0x7F ) > V_28 ) {
return V_23 ;
}
if ( ( V_12 . type & 0x7F ) > V_29 ) {
return V_23 ;
}
if ( ( V_11 = F_5 ( & V_12 . V_11 ) ) < V_10 ) {
if ( ( ( V_10 - V_11 ) >> 32 ) > 1 ) {
return V_23 ;
}
}
if ( ( V_8 ) && ( V_11 > V_10 ) && ( ( ( V_11 - V_10 ) >> 32 ) > 3600 * 24 * 7 ) ) {
return V_23 ;
}
memcpy ( & V_10 , & V_11 , sizeof( V_10 ) ) ;
type = V_12 . type ;
while ( type & 0x80 ) {
if ( ! F_6 ( V_1 -> V_20 , & V_17 , sizeof( V_17 ) , V_2 , V_3 ) ) {
if ( * V_2 == V_21 ) {
return V_23 ;
}
return V_24 ;
}
V_15 -= ( T_6 ) sizeof( V_17 ) ;
memcpy ( & type , & V_17 , sizeof( type ) ) ;
}
switch( V_12 . type & 0x7F ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
if ( ! F_6 ( V_1 -> V_20 , & V_13 , sizeof( V_13 ) , V_2 , V_3 ) ) {
if ( * V_2 == V_21 ) {
return V_23 ;
}
return V_24 ;
}
V_15 -= ( T_6 ) sizeof( V_13 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
if ( ! F_6 ( V_1 -> V_20 , & V_14 , sizeof( V_14 ) , V_2 , V_3 ) ) {
if ( * V_2 == V_21 ) {
return V_23 ;
}
return V_24 ;
}
V_15 -= ( T_6 ) sizeof( V_14 ) ;
break;
default:
break;
}
if ( V_15 > V_25 ) {
return V_23 ;
}
V_19 = ( T_3 * ) F_7 ( V_15 ) ;
V_18 = F_6 ( V_1 -> V_20 , V_19 , V_15 , V_2 , V_3 ) ;
F_8 ( V_19 ) ;
if ( ! V_18 ) {
if ( * V_2 != V_21 ) {
return V_24 ;
}
if ( V_4 < V_22 ) {
return V_23 ;
}
}
V_8 = 1 ;
}
if ( F_4 ( V_1 -> V_20 , 0L , V_41 , V_2 ) == - 1 ) {
return V_24 ;
}
V_1 -> V_42 = V_43 ;
V_1 -> V_44 = 0 ;
V_1 -> V_45 = V_46 ;
V_1 -> V_47 = V_48 ;
V_1 -> V_49 = V_50 ;
V_1 -> V_51 = V_52 ;
F_9 ( V_1 ) ;
return V_53 ;
}
static T_10 V_48 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_11 * V_54 )
{
T_5 V_55 ;
T_6 V_15 , V_56 ;
* V_54 = F_10 ( V_1 -> V_20 ) ;
do {
if ( ! F_11 ( V_1 -> V_20 ,
& V_1 -> V_57 , & V_55 ,
V_2 , V_3 , & V_56 , & V_15 ) ) {
return FALSE ;
}
if ( ! F_12 ( V_1 -> V_20 , V_1 -> V_58 , V_15 ,
V_2 , V_3 ) )
return FALSE ;
} while ( V_55 . type == V_26 );
return TRUE ;
}
static T_10 V_50 ( T_2 * V_1 , T_11 V_59 ,
struct V_60 * V_57 , T_12 * V_61 ,
int * V_2 , T_3 * * V_3 )
{
T_5 V_55 ;
T_6 V_15 ;
if ( F_4 ( V_1 -> V_62 , V_59 , V_41 , V_2 ) == - 1 )
return FALSE ;
do {
if ( ! F_11 ( V_1 -> V_62 , V_57 , & V_55 ,
V_2 , V_3 , NULL , & V_15 ) )
return FALSE ;
} while ( V_55 . type == V_26 );
return F_12 ( V_1 -> V_62 , V_61 , V_15 ,
V_2 , V_3 ) ;
}
static T_10 F_11 ( T_13 V_20 ,
struct V_60 * V_57 ,
T_5 * V_55 ,
int * V_2 ,
T_3 * * V_3 ,
T_6 * V_56 ,
T_6 * V_15 )
{
union V_63 * V_64 = & V_57 -> V_64 ;
T_6 V_13 ;
T_9 V_65 [ 8 ] ;
T_8 V_66 ;
T_9 type = 0 ;
T_7 V_14 ;
T_6 V_67 = 0 ;
int V_4 = 0 ;
int V_68 = sizeof( V_64 -> erf . V_69 ) / sizeof( struct V_70 ) ;
if ( ! F_2 ( V_20 , V_55 , sizeof( * V_55 ) , V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_56 != NULL ) {
* V_56 = sizeof( * V_55 ) ;
}
* V_15 = F_3 ( V_55 -> V_16 ) - ( T_6 ) sizeof( * V_55 ) ;
if ( * V_15 > V_25 ) {
* V_2 = V_71 ;
* V_3 = F_13 ( L_2 ,
* V_15 , V_25 ) ;
return FALSE ;
}
if ( * V_15 == 0 ) {
if ( ( V_55 -> type & 0x7F ) != V_26 ) {
* V_2 = V_71 ;
* V_3 = F_13 ( L_3 ) ;
return FALSE ;
}
}
{
T_8 V_11 = F_5 ( & V_55 -> V_11 ) ;
V_57 -> V_72 = V_73 ;
V_57 -> V_74 = V_75 | V_76 | V_77 ;
V_57 -> V_11 . V_78 = ( long ) ( V_11 >> 32 ) ;
V_11 = ( ( V_11 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_11 += ( V_11 & 0x80000000 ) << 1 ;
V_57 -> V_11 . V_79 = ( ( int ) ( V_11 >> 32 ) ) ;
if ( V_57 -> V_11 . V_79 >= 1000000000 ) {
V_57 -> V_11 . V_79 -= 1000000000 ;
V_57 -> V_11 . V_78 += 1 ;
}
V_57 -> V_80 = ( V_55 -> V_81 & 0x03 ) ;
}
memset ( & V_64 -> erf , 0 , sizeof( V_64 -> erf ) ) ;
V_64 -> erf . V_57 . V_11 = F_5 ( & V_55 -> V_11 ) ;
V_64 -> erf . V_57 . type = V_55 -> type ;
V_64 -> erf . V_57 . V_81 = V_55 -> V_81 ;
V_64 -> erf . V_57 . V_16 = F_3 ( V_55 -> V_16 ) ;
V_64 -> erf . V_57 . V_82 = F_3 ( V_55 -> V_82 ) ;
V_64 -> erf . V_57 . V_83 = F_3 ( V_55 -> V_83 ) ;
type = V_55 -> type ;
while ( type & 0x80 ) {
if ( ! F_6 ( V_20 , & V_65 , sizeof( V_65 ) ,
V_2 , V_3 ) )
return FALSE ;
if ( V_56 != NULL )
* V_56 += ( T_6 ) sizeof( V_65 ) ;
* V_15 -= ( T_6 ) sizeof( V_65 ) ;
V_67 += ( T_6 ) sizeof( V_65 ) ;
V_66 = F_14 ( V_65 ) ;
if ( V_4 < V_68 )
memcpy ( & V_64 -> erf . V_69 [ V_4 ] . V_84 , & V_66 , sizeof( V_66 ) ) ;
type = V_65 [ 0 ] ;
V_4 ++ ;
}
switch ( V_55 -> type & 0x7F ) {
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_29 :
#if 0
{
phdr->len = g_htons(erf_header->wlen);
phdr->caplen = g_htons(erf_header->wlen);
}
return TRUE;
#endif
break;
case V_26 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
break;
case V_38 :
case V_39 :
case V_40 :
if ( ! F_6 ( V_20 , & V_14 , sizeof( V_14 ) , V_2 , V_3 ) )
return FALSE ;
if ( V_56 != NULL )
* V_56 += ( T_6 ) sizeof( V_14 ) ;
* V_15 -= ( T_6 ) sizeof( V_14 ) ;
V_67 += ( T_6 ) sizeof( V_14 ) ;
V_64 -> erf . V_94 . V_14 = F_15 ( V_14 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
if ( ! F_6 ( V_20 , & V_13 , sizeof( V_13 ) , V_2 , V_3 ) )
return FALSE ;
if ( V_56 != NULL )
* V_56 += ( T_6 ) sizeof( V_13 ) ;
* V_15 -= ( T_6 ) sizeof( V_13 ) ;
V_67 += ( T_6 ) sizeof( V_13 ) ;
V_64 -> erf . V_94 . V_13 = F_16 ( V_13 ) ;
break;
case V_95 :
case V_96 :
default:
* V_2 = V_97 ;
* V_3 = F_13 ( L_4 ,
V_55 -> type ) ;
return FALSE ;
}
{
V_57 -> V_98 = F_15 ( V_55 -> V_83 ) ;
V_57 -> V_99 = F_17 ( F_15 ( V_55 -> V_83 ) ,
F_15 ( V_55 -> V_16 ) - ( T_6 ) sizeof( * V_55 ) - V_67 ) ;
}
if ( * V_15 > V_25 ) {
* V_2 = V_71 ;
* V_3 = F_13 ( L_2 ,
* V_15 , V_25 ) ;
return FALSE ;
}
return TRUE ;
}
static int F_18 ( int V_100 )
{
unsigned int V_4 ;
for( V_4 = 0 ; V_4 < V_101 ; V_4 ++ ) {
if( V_102 [ V_4 ] . V_103 == V_100 )
return V_102 [ V_4 ] . V_104 ;
}
return - 1 ;
}
static T_10 F_19 ( T_14 * V_105 , int V_100 , const union V_63 * V_64 , int * V_2 )
{
T_9 V_106 [ sizeof( struct V_107 ) ] ;
T_9 V_108 [ ( ( sizeof( struct V_109 ) > sizeof( struct V_110 ) ) ?
sizeof( struct V_109 ) : sizeof( struct V_110 ) ) ] ;
T_9 V_84 [ 8 * V_111 ] ;
T_15 V_112 = 0 ;
T_15 V_113 = 0 ;
int V_4 = 0 ;
T_9 V_114 = 0 ;
switch( V_100 ) {
case V_46 :
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
F_20 ( & V_106 [ 0 ] , V_64 -> erf . V_57 . V_11 ) ;
V_106 [ 8 ] = V_64 -> erf . V_57 . type ;
V_106 [ 9 ] = V_64 -> erf . V_57 . V_81 ;
F_21 ( & V_106 [ 10 ] , V_64 -> erf . V_57 . V_16 ) ;
F_21 ( & V_106 [ 12 ] , V_64 -> erf . V_57 . V_82 ) ;
F_21 ( & V_106 [ 14 ] , V_64 -> erf . V_57 . V_83 ) ;
V_112 = sizeof( struct V_115 ) ;
switch( V_64 -> erf . V_57 . type & 0x7F ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
F_22 ( & V_108 [ 0 ] , V_64 -> erf . V_94 . V_13 ) ;
V_113 += ( int ) sizeof( struct V_109 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
F_21 ( & V_108 [ 0 ] , V_64 -> erf . V_94 . V_14 ) ;
V_113 += ( int ) sizeof( struct V_110 ) ;
break;
default:
break;
}
break;
default:
return FALSE ;
}
if ( ! F_23 ( V_105 , V_106 , V_112 , V_2 ) )
return FALSE ;
V_105 -> V_116 += V_112 ;
V_114 = V_64 -> erf . V_57 . type & 0x80 ;
if( V_114 ) {
do{
F_24 ( V_84 + ( V_4 * 8 ) , V_64 -> erf . V_69 [ V_4 ] . V_84 ) ;
if( V_4 == V_111 - 1 ) V_84 [ V_4 * 8 ] = V_84 [ V_4 * 8 ] & 0x7F ;
V_114 = V_84 [ V_4 * 8 ] & 0x80 ;
V_4 ++ ;
}while( V_114 && V_4 < V_111 );
if ( ! F_23 ( V_105 , V_84 , 8 * V_4 , V_2 ) )
return FALSE ;
V_105 -> V_116 += 8 * V_4 ;
}
if( ! F_23 ( V_105 , V_108 , V_113 , V_2 ) )
return FALSE ;
V_105 -> V_116 += V_113 ;
return TRUE ;
}
static T_10 F_25 (
T_14 * V_105 ,
const struct V_60 * V_57 ,
const T_9 * V_117 ,
int * V_2 ,
T_3 * * V_3 V_118 )
{
const union V_63 * V_64 = & V_57 -> V_64 ;
union V_63 V_119 ;
int V_100 ;
T_11 V_120 = 0 ;
int V_4 ;
int V_121 = 0 ;
T_10 V_122 = FALSE ;
T_6 V_123 = 0x00000000 ;
if ( V_57 -> V_72 != V_73 ) {
* V_2 = V_124 ;
return FALSE ;
}
if( V_57 -> V_99 > V_25 ) {
* V_2 = V_125 ;
return FALSE ;
}
if( V_105 -> V_100 == V_126 ) {
V_100 = V_57 -> V_127 ;
} else{
V_100 = V_105 -> V_100 ;
}
if( V_100 == V_46 ) {
V_120 = V_105 -> V_116 + V_64 -> erf . V_57 . V_16 ;
if( ! F_19 ( V_105 , V_100 , V_64 , V_2 ) ) return FALSE ;
if( ! F_23 ( V_105 , V_117 , V_57 -> V_99 , V_2 ) ) return FALSE ;
V_105 -> V_116 += V_57 -> V_99 ;
while( V_105 -> V_116 < V_120 ) {
if( ! F_23 ( V_105 , L_5 , 1 , V_2 ) ) return FALSE ;
V_105 -> V_116 ++ ;
}
return TRUE ;
}
V_119 . erf . V_57 . V_11 = ( ( T_8 ) V_57 -> V_11 . V_78 << 32 ) + ( ( ( T_8 ) V_57 -> V_11 . V_79 << 32 ) / 1000 / 1000 / 1000 ) ;
V_119 . erf . V_57 . type = F_18 ( V_100 ) ;
V_119 . erf . V_57 . V_81 = 0x4 ;
V_119 . erf . V_57 . V_82 = 0 ;
V_119 . erf . V_57 . V_16 = V_57 -> V_99 + 16 ;
V_119 . erf . V_57 . V_83 = V_57 -> V_98 ;
switch( V_119 . erf . V_57 . type ) {
case V_38 :
V_119 . erf . V_57 . V_16 += 2 ;
if ( V_64 -> V_128 . V_129 != 4 ) {
if( ! ( V_57 -> V_99 < V_57 -> V_98 ) ) {
V_123 = F_26 ( V_117 , V_57 -> V_99 , 0xFFFFFFFF ) ;
V_119 . erf . V_57 . V_16 += 4 ;
V_119 . erf . V_57 . V_83 += 4 ;
V_122 = TRUE ;
}
}
break;
case V_89 :
if( ! ( V_57 -> V_99 < V_57 -> V_98 ) ) {
V_123 = F_26 ( V_117 , V_57 -> V_99 , 0xFFFFFFFF ) ;
V_119 . erf . V_57 . V_16 += 4 ;
V_119 . erf . V_57 . V_83 += 4 ;
V_122 = TRUE ;
}
break;
default:
break;
}
V_120 = ( 8 - ( V_119 . erf . V_57 . V_16 % 8 ) ) % 8 ;
if( V_57 -> V_99 < V_57 -> V_98 ) {
V_121 = ( 8 - ( V_130 ) V_120 ) % 8 ;
V_119 . erf . V_57 . V_16 -= V_121 ;
} else{
V_119 . erf . V_57 . V_16 += ( V_131 ) V_120 ;
}
if( ! F_19 ( V_105 , V_46 , & V_119 , V_2 ) ) return FALSE ;
if( ! F_23 ( V_105 , V_117 , V_57 -> V_99 - V_121 , V_2 ) ) return FALSE ;
V_105 -> V_116 += V_57 -> V_99 - V_121 ;
if( V_122 ) {
if( ! F_23 ( V_105 , & V_123 , 4 , V_2 ) ) return FALSE ;
V_105 -> V_116 += 4 ;
}
if( V_121 == 0 ) {
for( V_4 = ( V_131 ) V_120 ; V_4 > 0 ; V_4 -- ) {
if( ! F_23 ( V_105 , L_5 , 1 , V_2 ) ) return FALSE ;
V_105 -> V_116 ++ ;
}
}
return TRUE ;
}
int F_27 ( int V_100 )
{
if( V_100 == V_126 )
return 0 ;
if ( F_18 ( V_100 ) == - 1 )
return V_132 ;
return 0 ;
}
int F_28 ( T_14 * V_105 , int * V_2 )
{
V_105 -> V_133 = F_25 ;
switch( V_105 -> V_42 ) {
case V_43 :
V_105 -> V_134 = V_52 ;
break;
default:
* V_2 = V_135 ;
return FALSE ;
break;
}
return TRUE ;
}
int F_9 ( T_2 * V_1 )
{
T_16 V_136 ;
int V_4 ;
if ( ! V_1 )
return - 1 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_137 = V_46 ;
V_136 . V_138 = 1000000000 ;
V_136 . V_139 = F_29 ( V_46 ) ;
V_136 . V_140 = 65535 ;
V_136 . V_141 = NULL ;
V_136 . V_142 = 0 ;
V_136 . V_143 = 0x09 ;
V_136 . V_144 = NULL ;
V_136 . V_145 = 0 ;
V_136 . V_146 = NULL ;
V_136 . V_147 = NULL ;
V_136 . V_148 = 0 ;
V_136 . V_149 = 0 ;
V_136 . V_150 = NULL ;
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ ) {
V_136 . V_151 = F_13 ( L_6 , 'A' + V_4 ) ;
V_136 . V_152 = F_13 ( L_7 , V_4 , 'A' + V_4 ) ;
F_30 ( V_1 -> V_153 , V_136 ) ;
}
return 0 ;
}
