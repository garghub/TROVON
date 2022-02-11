static T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
const struct V_3 * V_4 = ( const struct V_3 * ) V_1 ;
const struct V_3 * V_5 = ( const struct V_3 * ) V_2 ;
return V_4 -> V_6 == V_5 -> V_6 && V_4 -> V_7 == V_5 -> V_7 ;
}
static T_3 F_2 ( T_2 V_8 )
{
const struct V_3 * V_9 = ( const struct V_3 * ) V_8 ;
return ( ( ( T_3 ) V_9 -> V_7 ) << 16 ) | V_9 -> V_6 ;
}
static void F_3 ( T_4 V_8 )
{
int V_10 = 0 ;
struct V_3 * V_9 = (struct V_3 * ) V_8 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
F_4 ( V_9 -> V_11 [ V_10 ] . V_12 ) ;
F_4 ( V_9 -> V_11 [ V_10 ] . V_13 ) ;
}
F_4 ( V_9 -> V_14 ) ;
F_4 ( V_9 ) ;
}
static struct V_3 * F_5 ( T_5 V_7 , T_6 V_6 )
{
int V_10 = 0 ;
struct V_3 * V_9 = NULL ;
V_9 = (struct V_3 * ) F_6 ( sizeof( struct V_3 ) ) ;
memset ( V_9 , 0 , sizeof( struct V_3 ) ) ;
V_9 -> V_7 = V_7 ;
V_9 -> V_6 = V_6 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
V_9 -> V_11 [ V_10 ] . V_15 = - 1 ;
V_9 -> V_11 [ V_10 ] . V_16 = - 1 ;
}
V_9 -> V_17 = - 1 ;
V_9 -> V_18 = ( V_19 ) - 1 ;
return V_9 ;
}
T_7 * F_7 ( void )
{
T_7 * V_20 ;
V_20 = ( T_7 * ) F_6 ( sizeof( T_7 ) ) ;
V_20 -> V_9 = F_8 ( F_2 , F_1 , F_3 , NULL ) ;
V_20 -> V_21 = 0 ;
V_20 -> V_22 = FALSE ;
V_20 -> V_23 = FALSE ;
return V_20 ;
}
T_7 * F_9 ( T_7 * V_20 )
{
if ( V_20 )
{
F_10 ( V_20 -> V_9 ) ;
F_4 ( V_20 ) ;
}
return NULL ;
}
static void
F_11 ( T_4 V_24 , T_4 T_8 V_25 )
{
F_4 ( V_24 ) ;
}
extern T_9 F_12 ( T_10 * V_26 , int * V_27 , T_11 * * V_28 )
{
int V_10 , V_29 , V_30 = V_31 ;
int V_32 = 0 ;
char * V_33 ;
T_12 V_34 , V_35 ;
T_13 V_36 ;
V_19 V_37 ;
struct V_38 V_39 ;
V_19 V_40 ;
T_14 V_41 ;
T_5 V_42 ;
T_6 type ;
T_1 V_43 ;
T_11 * V_44 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
if ( ( V_33 = getenv ( L_1 ) ) != NULL ) {
if ( ( V_29 = atoi ( V_33 ) ) >= 0 && V_29 < 101 ) {
V_30 = V_29 ;
}
}
for ( V_10 = 0 ; V_10 < V_30 ; V_10 ++ ) {
if ( ! F_13 ( V_26 -> V_45 , & V_36 , sizeof( V_36 ) , V_27 , V_28 ) ) {
if ( * V_27 == 0 ) {
break;
}
if ( * V_27 == V_46 ) {
if ( V_10 < V_47 ) {
return V_48 ;
} else {
break;
}
} else {
return V_49 ;
}
}
V_41 = F_14 ( V_36 . V_41 ) ;
if ( V_41 < 16 ) {
return V_48 ;
}
V_40 = V_41 - ( V_19 ) sizeof( V_36 ) ;
if ( V_40 > V_50 ) {
return V_48 ;
}
if ( ( V_36 . type & 0x7F ) == V_51 ) {
if ( F_15 ( V_26 -> V_45 , V_40 , V_52 , V_27 ) == - 1 ) {
return V_49 ;
}
continue;
}
if ( ( V_36 . type & 0x7F ) == 0 ) {
return V_48 ;
}
if ( ( V_35 = F_16 ( & V_36 . V_35 ) ) < V_34 ) {
if ( ( ( V_34 - V_35 ) >> 32 ) > 1 ) {
return V_48 ;
}
}
if ( ( V_32 ) && ( V_35 > V_34 ) && ( ( ( V_35 - V_34 ) >> 32 ) > 3600 * 24 * 7 ) ) {
return V_48 ;
}
memcpy ( & V_34 , & V_35 , sizeof( V_34 ) ) ;
type = V_36 . type ;
while ( type & 0x80 ) {
if ( ! F_17 ( V_26 -> V_45 , & V_42 , sizeof( V_42 ) , V_27 , V_28 ) ) {
if ( * V_27 == V_46 ) {
return V_48 ;
}
return V_49 ;
}
V_40 -= ( V_19 ) sizeof( V_42 ) ;
memcpy ( & type , & V_42 , sizeof( type ) ) ;
}
switch( V_36 . type & 0x7F ) {
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
if ( ! F_17 ( V_26 -> V_45 , & V_37 , sizeof( V_37 ) , V_27 , V_28 ) ) {
if ( * V_27 == V_46 ) {
return V_48 ;
}
return V_49 ;
}
V_40 -= ( V_19 ) sizeof( V_37 ) ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
if ( ! F_17 ( V_26 -> V_45 , & V_39 , sizeof( V_39 ) , V_27 , V_28 ) ) {
if ( * V_27 == V_46 ) {
return V_48 ;
}
return V_49 ;
}
V_40 -= ( V_19 ) sizeof( V_39 ) ;
break;
default:
break;
}
if ( V_40 > V_50 ) {
return V_48 ;
}
V_44 = ( T_11 * ) F_6 ( V_40 ) ;
V_43 = F_17 ( V_26 -> V_45 , V_44 , V_40 , V_27 , V_28 ) ;
F_4 ( V_44 ) ;
if ( ! V_43 ) {
if ( * V_27 != V_46 ) {
return V_49 ;
}
if ( V_10 < V_47 ) {
return V_48 ;
}
}
V_32 = 1 ;
}
if ( F_15 ( V_26 -> V_45 , 0L , V_65 , V_27 ) == - 1 ) {
return V_49 ;
}
V_26 -> V_66 = V_67 ;
V_26 -> V_68 = 0 ;
V_26 -> V_69 = V_70 ;
V_26 -> V_71 = V_72 ;
V_26 -> V_73 = V_74 ;
V_26 -> V_75 = V_76 ;
V_26 -> V_77 = V_78 ;
V_26 -> V_79 = F_7 () ;
return V_80 ;
}
static T_1 V_72 ( T_10 * V_26 , int * V_27 , T_11 * * V_28 ,
T_15 * V_81 )
{
T_13 V_82 ;
V_19 V_40 , V_83 ;
* V_81 = F_18 ( V_26 -> V_45 ) ;
do {
if ( ! F_19 ( V_26 , V_26 -> V_45 ,
& V_26 -> V_84 , & V_82 ,
V_27 , V_28 , & V_83 , & V_40 ) ) {
return FALSE ;
}
if ( ! F_20 ( V_26 -> V_45 , V_26 -> V_85 , V_40 ,
V_27 , V_28 ) )
return FALSE ;
if ( ( V_82 . type & 0x7F ) == V_86 && V_40 > 0 )
{
F_21 ( ( T_7 * ) V_26 -> V_79 , V_26 , & V_26 -> V_84 . V_87 , V_40 ) ;
}
} while ( V_82 . type == V_51 );
return TRUE ;
}
static T_1 V_74 ( T_10 * V_26 , T_15 V_88 ,
struct V_89 * V_84 , T_16 * V_90 ,
int * V_27 , T_11 * * V_28 )
{
T_13 V_82 ;
V_19 V_40 ;
if ( F_15 ( V_26 -> V_91 , V_88 , V_65 , V_27 ) == - 1 )
return FALSE ;
do {
if ( ! F_19 ( V_26 , V_26 -> V_91 , V_84 , & V_82 ,
V_27 , V_28 , NULL , & V_40 ) )
return FALSE ;
} while ( V_82 . type == V_51 );
return F_20 ( V_26 -> V_91 , V_90 , V_40 ,
V_27 , V_28 ) ;
}
static T_1 F_19 ( T_10 * V_26 , T_17 V_45 ,
struct V_89 * V_84 ,
T_13 * V_82 ,
int * V_27 ,
T_11 * * V_28 ,
V_19 * V_83 ,
V_19 * V_40 )
{
union V_92 * V_87 = & V_84 -> V_87 ;
T_6 V_93 [ 8 ] ;
T_5 V_94 ;
T_6 type = 0 ;
V_19 V_37 ;
V_19 V_95 ;
struct V_96 V_39 ;
V_19 V_97 = 0 ;
int V_10 = 0 ;
int V_98 = sizeof( V_87 -> erf . V_99 ) / sizeof( struct V_100 ) ;
T_5 V_7 = 0 ;
T_6 V_6 = 0 ;
T_6 V_101 = 0 ;
T_1 V_102 = FALSE ;
if ( ! F_13 ( V_45 , V_82 , sizeof( * V_82 ) , V_27 , V_28 ) ) {
return FALSE ;
}
if ( V_83 != NULL ) {
* V_83 = sizeof( * V_82 ) ;
}
* V_40 = F_14 ( V_82 -> V_41 ) - ( V_19 ) sizeof( * V_82 ) ;
if ( * V_40 > V_50 ) {
* V_27 = V_103 ;
* V_28 = F_22 ( L_2 ,
* V_40 , V_50 ) ;
return FALSE ;
}
if ( * V_40 == 0 ) {
if ( ( V_82 -> type & 0x7F ) != V_51 ) {
* V_27 = V_103 ;
* V_28 = F_23 ( L_3 ) ;
return FALSE ;
}
}
{
T_5 V_35 = F_16 ( & V_82 -> V_35 ) ;
V_84 -> V_104 = V_105 ;
#if 0
} else {
phdr->rec_type = REC_TYPE_FT_SPECIFIC_REPORT;
}
#endif
V_84 -> V_106 = V_107 | V_108 | V_109 ;
V_84 -> V_35 . V_110 = ( long ) ( V_35 >> 32 ) ;
V_35 = ( ( V_35 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_35 += ( V_35 & 0x80000000 ) << 1 ;
V_84 -> V_35 . V_111 = ( ( int ) ( V_35 >> 32 ) ) ;
if ( V_84 -> V_35 . V_111 >= 1000000000 ) {
V_84 -> V_35 . V_111 -= 1000000000 ;
V_84 -> V_35 . V_110 += 1 ;
}
V_101 = V_82 -> V_112 & 0x03 ;
}
memset ( & V_87 -> erf , 0 , sizeof( V_87 -> erf ) ) ;
V_87 -> erf . V_84 . V_35 = F_16 ( & V_82 -> V_35 ) ;
V_87 -> erf . V_84 . type = V_82 -> type ;
V_87 -> erf . V_84 . V_112 = V_82 -> V_112 ;
V_87 -> erf . V_84 . V_41 = F_14 ( V_82 -> V_41 ) ;
V_87 -> erf . V_84 . V_113 = F_14 ( V_82 -> V_113 ) ;
V_87 -> erf . V_84 . V_114 = F_14 ( V_82 -> V_114 ) ;
type = V_82 -> type ;
while ( type & 0x80 ) {
if ( ! F_17 ( V_45 , & V_93 , sizeof( V_93 ) ,
V_27 , V_28 ) )
return FALSE ;
if ( V_83 != NULL )
* V_83 += ( V_19 ) sizeof( V_93 ) ;
* V_40 -= ( V_19 ) sizeof( V_93 ) ;
V_97 += ( V_19 ) sizeof( V_93 ) ;
V_94 = F_24 ( V_93 ) ;
if ( V_10 < V_98 )
memcpy ( & V_87 -> erf . V_99 [ V_10 ] . V_115 , & V_94 , sizeof( V_94 ) ) ;
type = V_93 [ 0 ] ;
switch ( type & 0x7f ) {
case V_116 :
if ( ! V_102 )
V_7 = V_94 & V_117 ;
V_102 = TRUE ;
case V_118 :
if ( ! V_6 )
V_6 = ( V_94 >> 48 ) & 0xff ;
break;
}
V_10 ++ ;
}
V_84 -> V_119 = ( T_3 ) F_25 ( ( T_7 * ) V_26 -> V_79 , V_26 , V_87 , V_7 , V_6 , V_101 ) ;
switch ( V_82 -> type & 0x7F ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_86 :
case V_125 :
case V_126 :
#if 0
{
phdr->len = g_htons(erf_header->wlen);
phdr->caplen = g_htons(erf_header->wlen);
}
return TRUE;
#endif
break;
case V_51 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
if ( ! F_17 ( V_45 , & V_39 , sizeof( V_39 ) , V_27 , V_28 ) )
return FALSE ;
if ( V_83 != NULL )
* V_83 += ( V_19 ) sizeof( V_39 ) ;
* V_40 -= ( V_19 ) sizeof( V_39 ) ;
V_97 += ( V_19 ) sizeof( V_39 ) ;
V_87 -> erf . V_133 . V_39 = V_39 ;
break;
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
if ( ! F_17 ( V_45 , & V_37 , sizeof( V_37 ) , V_27 , V_28 ) )
return FALSE ;
if ( V_83 != NULL )
* V_83 += ( V_19 ) sizeof( V_37 ) ;
* V_40 -= ( V_19 ) sizeof( V_37 ) ;
V_97 += ( V_19 ) sizeof( V_37 ) ;
V_87 -> erf . V_133 . V_37 = F_26 ( V_37 ) ;
break;
case V_60 :
if ( ! F_17 ( V_45 , & V_95 , sizeof( V_95 ) , V_27 , V_28 ) )
return FALSE ;
if ( V_83 != NULL )
* V_83 += ( V_19 ) sizeof( V_95 ) ;
* V_40 -= ( V_19 ) sizeof( V_95 ) ;
V_97 += ( V_19 ) sizeof( V_95 ) ;
V_87 -> erf . V_133 . V_95 = F_26 ( V_95 ) ;
break;
case V_134 :
case V_135 :
default:
break;
}
{
V_84 -> V_136 = F_14 ( V_82 -> V_114 ) ;
V_84 -> V_137 = F_27 ( F_14 ( V_82 -> V_114 ) ,
F_14 ( V_82 -> V_41 ) - ( V_19 ) sizeof( * V_82 ) - V_97 ) ;
}
if ( * V_40 > V_50 ) {
* V_27 = V_103 ;
* V_28 = F_22 ( L_2 ,
* V_40 , V_50 ) ;
return FALSE ;
}
return TRUE ;
}
static int F_28 ( int V_138 )
{
unsigned int V_10 ;
for( V_10 = 0 ; V_10 < V_139 ; V_10 ++ ) {
if( V_140 [ V_10 ] . V_141 == V_138 )
return V_140 [ V_10 ] . V_142 ;
}
return - 1 ;
}
static T_1 F_29 ( T_18 * V_143 , int V_138 , const union V_92 * V_87 , int * V_27 )
{
T_6 V_144 [ sizeof( struct V_145 ) ] ;
T_6 V_146 [ sizeof( union V_146 ) ] ;
T_6 V_115 [ 8 * V_147 ] ;
T_19 V_148 = 0 ;
T_19 V_149 = 0 ;
int V_10 = 0 ;
T_6 V_150 = 0 ;
switch( V_138 ) {
case V_70 :
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
F_30 ( & V_144 [ 0 ] , V_87 -> erf . V_84 . V_35 ) ;
V_144 [ 8 ] = V_87 -> erf . V_84 . type ;
V_144 [ 9 ] = V_87 -> erf . V_84 . V_112 ;
F_31 ( & V_144 [ 10 ] , V_87 -> erf . V_84 . V_41 ) ;
F_31 ( & V_144 [ 12 ] , V_87 -> erf . V_84 . V_113 ) ;
F_31 ( & V_144 [ 14 ] , V_87 -> erf . V_84 . V_114 ) ;
V_148 = sizeof( struct V_151 ) ;
switch( V_87 -> erf . V_84 . type & 0x7F ) {
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
F_32 ( & V_146 [ 0 ] , V_87 -> erf . V_133 . V_37 ) ;
V_149 += ( int ) sizeof( struct V_152 ) ;
break;
case V_60 :
F_32 ( & V_146 [ 0 ] , V_87 -> erf . V_133 . V_95 ) ;
V_149 += ( int ) sizeof( struct V_153 ) ;
break;
case V_61 :
case V_62 :
case V_63 :
case V_64 :
memcpy ( & V_146 [ 0 ] , & V_87 -> erf . V_133 . V_39 , sizeof V_87 -> erf . V_133 . V_39 ) ;
V_149 += ( int ) sizeof( struct V_38 ) ;
break;
default:
break;
}
break;
default:
return FALSE ;
}
if ( ! F_33 ( V_143 , V_144 , V_148 , V_27 ) )
return FALSE ;
V_143 -> V_154 += V_148 ;
V_150 = V_87 -> erf . V_84 . type & 0x80 ;
if( V_150 ) {
do{
F_34 ( V_115 + ( V_10 * 8 ) , V_87 -> erf . V_99 [ V_10 ] . V_115 ) ;
if( V_10 == V_147 - 1 ) V_115 [ V_10 * 8 ] = V_115 [ V_10 * 8 ] & 0x7F ;
V_150 = V_115 [ V_10 * 8 ] & 0x80 ;
V_10 ++ ;
}while( V_150 && V_10 < V_147 );
if ( ! F_33 ( V_143 , V_115 , 8 * V_10 , V_27 ) )
return FALSE ;
V_143 -> V_154 += 8 * V_10 ;
}
if( ! F_33 ( V_143 , V_146 , V_149 , V_27 ) )
return FALSE ;
V_143 -> V_154 += V_149 ;
return TRUE ;
}
static T_1 F_35 (
T_18 * V_143 ,
const struct V_89 * V_84 ,
const T_6 * V_155 ,
int * V_27 ,
T_11 * * V_28 V_25 )
{
const union V_92 * V_87 = & V_84 -> V_87 ;
union V_92 V_156 ;
int V_138 ;
T_15 V_157 = 0 ;
int V_10 ;
int V_158 = 0 ;
T_1 V_159 = FALSE ;
V_19 V_160 = 0x00000000 ;
if( V_84 -> V_137 > V_50 ) {
* V_27 = V_161 ;
return FALSE ;
}
if( V_143 -> V_138 == V_162 ) {
V_138 = V_84 -> V_163 ;
} else{
V_138 = V_143 -> V_138 ;
}
if( V_138 == V_70 ) {
V_157 = V_143 -> V_154 + V_87 -> erf . V_84 . V_41 ;
if( ! F_29 ( V_143 , V_138 , V_87 , V_27 ) ) return FALSE ;
if( ! F_33 ( V_143 , V_155 , V_84 -> V_137 , V_27 ) ) return FALSE ;
V_143 -> V_154 += V_84 -> V_137 ;
while( V_143 -> V_154 < V_157 ) {
if( ! F_33 ( V_143 , L_4 , 1 , V_27 ) ) return FALSE ;
V_143 -> V_154 ++ ;
}
return TRUE ;
}
if ( V_84 -> V_104 != V_105 ) {
* V_27 = V_164 ;
return FALSE ;
}
V_156 . erf . V_84 . V_35 = ( ( T_5 ) V_84 -> V_35 . V_110 << 32 ) + ( ( ( T_5 ) V_84 -> V_35 . V_111 << 32 ) / 1000 / 1000 / 1000 ) ;
V_156 . erf . V_84 . type = F_28 ( V_138 ) ;
V_156 . erf . V_84 . V_112 = 0x4 ;
V_156 . erf . V_84 . V_113 = 0 ;
V_156 . erf . V_84 . V_41 = V_84 -> V_137 + 16 ;
V_156 . erf . V_84 . V_114 = V_84 -> V_136 ;
switch( V_156 . erf . V_84 . type ) {
case V_61 :
V_156 . erf . V_84 . V_41 += 2 ;
if ( V_87 -> V_165 . V_166 != 4 ) {
if( ! ( V_84 -> V_137 < V_84 -> V_136 ) ) {
V_160 = F_36 ( V_155 , V_84 -> V_137 , 0xFFFFFFFF ) ;
V_156 . erf . V_84 . V_41 += 4 ;
V_156 . erf . V_84 . V_114 += 4 ;
V_159 = TRUE ;
}
}
break;
case V_127 :
if( ! ( V_84 -> V_137 < V_84 -> V_136 ) ) {
V_160 = F_36 ( V_155 , V_84 -> V_137 , 0xFFFFFFFF ) ;
V_156 . erf . V_84 . V_41 += 4 ;
V_156 . erf . V_84 . V_114 += 4 ;
V_159 = TRUE ;
}
break;
default:
break;
}
V_157 = ( 8 - ( V_156 . erf . V_84 . V_41 % 8 ) ) % 8 ;
if( V_84 -> V_137 < V_84 -> V_136 ) {
V_158 = ( 8 - ( T_3 ) V_157 ) % 8 ;
V_156 . erf . V_84 . V_41 -= V_158 ;
} else{
V_156 . erf . V_84 . V_41 += ( V_167 ) V_157 ;
}
if( ! F_29 ( V_143 , V_70 , & V_156 , V_27 ) ) return FALSE ;
if( ! F_33 ( V_143 , V_155 , V_84 -> V_137 - V_158 , V_27 ) ) return FALSE ;
V_143 -> V_154 += V_84 -> V_137 - V_158 ;
if( V_159 ) {
if( ! F_33 ( V_143 , & V_160 , 4 , V_27 ) ) return FALSE ;
V_143 -> V_154 += 4 ;
}
if( V_158 == 0 ) {
for( V_10 = ( V_167 ) V_157 ; V_10 > 0 ; V_10 -- ) {
if( ! F_33 ( V_143 , L_4 , 1 , V_27 ) ) return FALSE ;
V_143 -> V_154 ++ ;
}
}
return TRUE ;
}
int F_37 ( int V_138 )
{
if( V_138 == V_162 )
return 0 ;
if ( F_28 ( V_138 ) == - 1 )
return V_168 ;
return 0 ;
}
int F_38 ( T_18 * V_143 , int * V_27 )
{
V_143 -> V_169 = F_35 ;
switch( V_143 -> V_66 ) {
case V_67 :
V_143 -> V_170 = V_78 ;
break;
default:
* V_27 = V_171 ;
return FALSE ;
break;
}
return TRUE ;
}
int F_39 ( T_10 * V_26 )
{
T_20 V_172 ;
T_21 * V_173 ;
int V_10 ;
if ( ! V_26 )
return - 1 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
V_172 = F_40 ( V_174 ) ;
V_173 = ( T_21 * ) F_41 ( V_172 ) ;
V_173 -> V_175 = V_70 ;
V_173 -> V_176 = 1000000000 ;
V_173 -> V_177 = F_42 ( V_70 ) ;
V_173 -> V_178 = 65535 ;
F_43 ( V_172 , V_179 , 0x09 ) ;
V_173 -> V_180 = 0 ;
V_173 -> V_181 = NULL ;
F_44 ( V_172 , V_182 , L_5 , 'A' + V_10 ) ;
F_44 ( V_172 , V_183 , L_6 , V_10 , 'A' + V_10 ) ;
F_45 ( V_26 -> V_184 , V_172 ) ;
}
return 0 ;
}
int F_46 ( union V_92 * V_87 , T_5 * V_7 , T_6 * V_6 )
{
T_6 type ;
T_6 V_150 ;
T_5 V_185 ;
int V_10 = 0 ;
T_1 V_102 = FALSE ;
if ( ! V_87 || ! V_7 || ! V_6 )
return - 1 ;
* V_7 = 0 ;
* V_6 = 0 ;
V_150 = V_87 -> erf . V_84 . type & 0x80 ;
while ( V_150 && ( V_10 < V_147 ) ) {
V_185 = V_87 -> erf . V_99 [ V_10 ] . V_115 ;
type = ( T_6 ) ( V_185 >> 56 ) ;
switch ( type & 0x7f ) {
case V_116 :
if ( ! V_102 )
* V_7 = V_185 & V_117 ;
V_102 = TRUE ;
case V_118 :
if ( * V_6 == 0 )
* V_6 = ( V_185 >> 48 ) & 0xff ;
break;
}
if ( V_102 )
break;
V_150 = type & 0x80 ;
V_10 += 1 ;
}
return 0 ;
}
int F_47 ( T_7 * V_20 , T_10 * V_26 , union V_92 * V_87 )
{
T_5 V_7 ;
T_6 V_6 ;
T_6 V_101 ;
if ( ! V_87 )
return - 1 ;
V_101 = V_87 -> erf . V_84 . V_112 & 0x03 ;
F_46 ( V_87 , & V_7 , & V_6 ) ;
return F_25 ( V_20 , V_26 , V_87 , V_7 , V_6 , V_101 ) ;
}
static struct V_3 * F_48 ( T_7 * V_20 , T_5 V_7 , T_6 V_6 )
{
struct V_3 V_186 ;
if ( ! V_20 )
return NULL ;
V_186 . V_7 = V_7 ;
V_186 . V_6 = V_6 ;
return (struct V_3 * ) F_49 ( V_20 -> V_9 , & V_186 ) ;
}
static void F_50 ( T_20 V_187 , T_3 V_188 , T_5 V_7 , T_6 V_6 , T_6 V_101 , const T_11 * V_13 )
{
char V_189 [ 16 ] ;
char V_190 [ 24 ] ;
V_189 [ 0 ] = '\0' ;
V_190 [ 0 ] = '\0' ;
if ( V_7 > 0 ) {
F_51 ( V_190 , sizeof( V_190 ) , L_7 V_191 L_8 , V_7 ) ;
}
if ( V_6 > 0 ) {
F_51 ( V_189 , sizeof( V_189 ) , L_9 , V_6 ) ;
}
if ( V_13 ) {
F_52 ( V_187 , V_188 , L_10 , V_13 , V_190 , V_189 , V_101 ) ;
} else {
F_52 ( V_187 , V_188 , L_11 , 'A' + V_101 , V_190 , V_189 , V_101 ) ;
}
}
static int F_53 ( T_7 * V_20 , T_10 * V_26 , T_5 V_21 )
{
T_22 V_192 ;
T_4 V_193 ;
T_23 * V_194 = NULL ;
T_23 * V_195 = NULL ;
T_20 V_172 ;
struct V_3 * V_9 = NULL ;
int V_10 ;
if ( ! V_20 )
return - 1 ;
V_20 -> V_21 = V_21 ;
F_54 ( & V_192 , V_20 -> V_9 ) ;
while ( F_55 ( & V_192 , & V_193 , NULL ) ) {
V_9 = (struct V_3 * ) V_193 ;
if ( V_9 -> V_7 == 0 ) {
F_56 ( & V_192 ) ;
V_194 = F_57 ( V_194 , V_9 ) ;
}
}
if ( V_194 ) {
V_195 = V_194 ;
do {
V_9 = (struct V_3 * ) V_195 -> V_24 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
if ( V_9 -> V_11 [ V_10 ] . V_15 >= 0 ) {
V_172 = F_58 ( V_26 -> V_184 , T_20 , V_9 -> V_11 [ V_10 ] . V_15 ) ;
F_50 ( V_172 , V_182 , V_21 , V_9 -> V_6 , ( T_6 ) V_10 , V_9 -> V_11 [ V_10 ] . V_12 ) ;
F_50 ( V_172 , V_183 , V_21 , V_9 -> V_6 , ( T_6 ) V_10 , V_9 -> V_11 [ V_10 ] . V_13 ) ;
}
}
V_9 -> V_7 = V_21 ;
F_59 ( V_20 -> V_9 , V_9 , V_9 ) ;
} while ( ( V_195 = F_60 ( V_195 ) ) );
F_61 ( V_194 ) ;
}
return 0 ;
}
int F_25 ( T_7 * V_20 , T_10 * V_26 , union V_92 * V_87 , T_5 V_7 , T_6 V_6 , T_6 V_101 )
{
T_20 V_172 ;
T_21 * V_173 ;
struct V_3 * V_9 = NULL ;
if ( ! V_26 || ! V_87 || ! V_20 || V_101 > 3 )
return - 1 ;
if ( ( V_87 -> erf . V_84 . type & 0x7f ) == V_86 ) {
if ( V_20 -> V_21 == 0 && V_6 > 0 && V_7 != 0 ) {
F_53 ( V_20 , V_26 , V_7 ) ;
}
}
if ( V_7 == 0 ) {
V_7 = V_20 -> V_21 ;
}
V_9 = F_48 ( V_20 , V_7 , V_6 ) ;
if ( ! V_9 ) {
V_9 = F_5 ( V_7 , V_6 ) ;
F_59 ( V_20 -> V_9 , V_9 , V_9 ) ;
}
if ( V_9 -> V_11 [ V_101 ] . V_15 >= 0 ) {
return V_9 -> V_11 [ V_101 ] . V_15 ;
}
V_172 = F_40 ( V_174 ) ;
V_173 = ( T_21 * ) F_41 ( V_172 ) ;
V_173 -> V_175 = V_70 ;
V_173 -> V_176 = 1000000000 ;
V_173 -> V_177 = F_42 ( V_70 ) ;
V_173 -> V_178 = 65535 ;
F_43 ( V_172 , V_179 , 0x09 ) ;
V_173 -> V_180 = 0 ;
V_173 -> V_181 = NULL ;
F_50 ( V_172 , V_182 , V_7 , V_6 , V_101 , NULL ) ;
F_50 ( V_172 , V_183 , V_7 , V_6 , V_101 , NULL ) ;
V_9 -> V_11 [ V_101 ] . V_15 = ( int ) V_26 -> V_184 -> V_136 ;
F_45 ( V_26 -> V_184 , V_172 ) ;
return V_9 -> V_11 [ V_101 ] . V_15 ;
}
static V_19 F_62 ( struct V_196 * V_197 , T_6 * V_198 , V_19 V_199 )
{
T_14 V_200 ;
T_14 V_201 ;
V_19 V_202 ;
if ( ! V_198 || ! V_197 || V_199 < V_203 )
return 0 ;
V_200 = F_63 ( & V_198 [ 0 ] ) ;
V_201 = F_63 ( & V_198 [ 2 ] ) ;
V_202 = F_64 ( V_201 ) ;
if ( V_199 < V_202 ) {
return 0 ;
}
V_197 -> type = V_200 ;
V_197 -> V_204 = V_201 ;
V_197 -> V_205 = & V_198 [ 4 ] ;
return V_202 ;
}
static int F_65 ( T_7 * V_20 , T_10 * V_26 , union V_92 * V_87 V_25 , struct V_206 * V_207 )
{
struct V_196 V_197 = { 0 , 0 , NULL } ;
T_20 V_208 ;
char * V_209 ;
T_11 * V_210 = NULL ;
T_11 * V_211 = NULL ;
T_11 * V_212 = NULL ;
T_11 * V_13 = NULL ;
T_11 * V_213 = NULL ;
T_11 * V_214 = NULL ;
V_19 V_202 ;
if ( ! V_26 || ! V_207 || ! V_26 -> V_215 || ( V_26 -> V_215 -> V_136 == 0 ) )
return - 1 ;
V_208 = F_58 ( V_26 -> V_215 , T_20 , 0 ) ;
while ( ( V_202 = F_62 ( & V_197 , V_207 -> V_198 , V_207 -> V_199 ) ) && ! F_66 ( V_197 . type ) ) {
switch ( V_207 -> V_216 ) {
case V_217 :
{
if ( V_20 -> V_22 == TRUE ) {
return 0 ;
}
switch ( V_197 . type ) {
case V_218 :
F_67 ( V_208 , V_219 , V_197 . V_205 , V_197 . V_204 ) ;
break;
}
}
case V_220 :
{
if ( V_20 -> V_23 == TRUE ) {
return 0 ;
}
switch ( V_197 . type ) {
case V_221 :
F_4 ( V_212 ) ;
V_212 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
break;
case V_222 :
F_4 ( V_213 ) ;
V_213 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
break;
case V_223 :
F_4 ( V_13 ) ;
V_13 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
break;
case V_224 :
F_69 ( V_208 , V_225 , V_197 . V_205 , V_197 . V_204 ) ;
break;
case V_226 :
F_4 ( V_210 ) ;
V_210 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
break;
case V_227 :
F_4 ( V_211 ) ;
V_211 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
break;
default:
break;
}
}
break;
}
V_207 -> V_198 += V_202 ;
V_207 -> V_199 -= V_202 ;
}
if ( V_210 ) {
V_209 = F_70 ( L_12 , V_210 , V_211 , NULL ) ;
F_69 ( V_208 , V_228 , V_209 , strlen ( V_209 ) ) ;
F_4 ( V_209 ) ;
F_4 ( V_210 ) ;
F_4 ( V_211 ) ;
V_210 = NULL ;
V_211 = NULL ;
}
if ( V_212 || V_213 ) {
if ( V_212 && V_213 ) {
V_214 = F_71 ( V_212 , L_13 , V_213 , NULL ) ;
} else if ( V_213 ) {
V_214 = V_213 ;
V_213 = NULL ;
} else {
V_214 = V_212 ;
V_212 = NULL ;
}
}
if ( V_207 -> V_216 == V_220 && V_13 ) {
if ( V_214 ) {
F_52 ( V_208 , V_229 , L_14 , V_13 , V_214 ) ;
} else {
F_69 ( V_208 , V_229 , V_13 , strlen ( V_13 ) ) ;
}
} else if ( V_214 ) {
F_69 ( V_208 , V_229 , V_214 , strlen ( V_214 ) ) ;
}
F_4 ( V_214 ) ;
F_4 ( V_212 ) ;
F_4 ( V_13 ) ;
F_4 ( V_213 ) ;
if ( V_207 -> V_216 == V_217 ) {
V_20 -> V_22 = TRUE ;
} else {
V_20 -> V_23 = TRUE ;
}
return 1 ;
}
static int F_72 ( T_7 * V_20 V_25 , T_10 * V_26 , union V_92 * V_87 V_25 , struct V_206 * V_207 )
{
struct V_196 V_197 = { 0 , 0 , NULL } ;
V_19 V_202 ;
if ( ! V_26 || ! V_207 )
return - 1 ;
if ( V_207 -> V_9 -> V_230 == TRUE ) {
return 0 ;
}
while ( ( V_202 = F_62 ( & V_197 , V_207 -> V_198 , V_207 -> V_199 ) ) && ! F_66 ( V_197 . type ) ) {
switch ( V_197 . type ) {
case V_231 :
if ( V_197 . V_204 >= 4 ) {
V_207 -> V_9 -> V_17 = ( V_232 ) F_73 ( V_197 . V_205 ) ;
}
break;
case V_233 :
if ( V_197 . V_204 >= 4 ) {
V_207 -> V_9 -> V_18 = F_73 ( V_197 . V_205 ) ;
}
break;
case V_234 :
F_4 ( V_207 -> V_9 -> V_14 ) ;
V_207 -> V_9 -> V_14 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
break;
}
V_207 -> V_198 += V_202 ;
V_207 -> V_199 -= V_202 ;
}
V_207 -> V_9 -> V_230 = TRUE ;
return 1 ;
}
static int F_74 ( T_7 * V_20 , T_10 * V_26 , union V_92 * V_87 , struct V_206 * V_207 )
{
struct V_196 V_197 = { 0 , 0 , NULL } ;
V_19 V_202 ;
int V_235 = - 1 ;
T_20 V_172 = NULL ;
T_21 * V_173 = NULL ;
T_24 V_236 ;
V_19 V_101 = 0 ;
struct V_237 * V_238 = NULL ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
if ( ! V_26 || ! V_207 || ! V_87 || ! V_207 -> V_9 )
return - 1 ;
V_101 = V_207 -> V_239 - 1 ;
if ( V_101 < 4 ) {
V_238 = & V_207 -> V_9 -> V_11 [ V_101 ] ;
V_235 = V_238 -> V_15 ;
if ( V_235 == - 1 ) {
T_6 * V_240 = V_207 -> V_198 ;
V_19 V_241 = V_207 -> V_199 ;
while ( ( V_202 = F_62 ( & V_197 , V_240 , V_241 ) ) && ! F_66 ( V_197 . type ) ) {
if ( V_197 . type == V_242 ) {
if ( V_197 . V_204 >= 4 && F_73 ( V_197 . V_205 ) == 2 ) {
V_238 -> V_15 = - 2 ;
V_235 = - 2 ;
}
} else if ( V_197 . type == V_243 ) {
if ( V_197 . V_204 >= 4 ) {
V_238 -> V_16 = ( V_244 ) F_73 ( V_197 . V_205 ) ;
}
}
V_240 += V_202 ;
V_241 -= V_202 ;
}
if ( V_235 == - 1 ) {
V_235 = F_25 ( V_20 , V_26 , V_87 , V_207 -> V_9 -> V_7 , V_207 -> V_9 -> V_6 , ( T_6 ) V_101 ) ;
}
}
if ( V_235 >= 0 ) {
V_172 = F_58 ( V_26 -> V_184 , T_20 , V_235 ) ;
V_173 = ( T_21 * ) F_41 ( V_172 ) ;
} else if ( V_235 == - 2 ) {
return 0 ;
} else {
return - 1 ;
}
}
if ( ! V_172 || V_207 -> V_9 -> V_245 & ( 1 << V_101 ) )
return 0 ;
while ( ( V_202 = F_62 ( & V_197 , V_207 -> V_198 , V_207 -> V_199 ) ) && ! F_66 ( V_197 . type ) ) {
switch ( V_197 . type ) {
case V_246 :
if ( ! V_238 -> V_12 ) {
V_238 -> V_12 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
F_50 ( V_172 , V_182 , V_207 -> V_9 -> V_7 , V_207 -> V_9 -> V_6 , ( T_6 ) V_101 , V_238 -> V_12 ) ;
if ( ! V_238 -> V_13 ) {
F_50 ( V_172 , V_183 , V_207 -> V_9 -> V_7 , V_207 -> V_9 -> V_6 , ( T_6 ) V_101 , V_238 -> V_12 ) ;
}
}
break;
case V_223 :
if ( ! V_238 -> V_13 ) {
V_238 -> V_13 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
F_50 ( V_172 , V_183 , V_207 -> V_9 -> V_7 , V_207 -> V_9 -> V_6 , ( T_6 ) V_101 , V_238 -> V_13 ) ;
if ( ! V_238 -> V_12 ) {
F_50 ( V_172 , V_182 , V_207 -> V_9 -> V_7 , V_207 -> V_9 -> V_6 , ( T_6 ) V_101 , V_238 -> V_13 ) ;
}
}
break;
case V_247 :
if ( V_197 . V_204 >= 8 )
F_75 ( V_172 , V_248 , F_24 ( V_197 . V_205 ) ) ;
break;
case V_249 :
break;
case V_231 :
if ( V_197 . V_204 >= 4 ) {
F_43 ( V_172 , V_250 , ( T_6 ) F_73 ( V_197 . V_205 ) ) ;
V_238 -> V_251 . V_166 = 1 ;
}
break;
case V_233 :
if ( V_197 . V_204 >= 4 ) {
V_173 -> V_178 = F_73 ( V_197 . V_205 ) ;
V_238 -> V_251 . V_252 = 1 ;
}
break;
case V_218 :
F_67 ( V_172 , V_219 , V_197 . V_205 , V_197 . V_204 ) ;
break;
case V_234 :
V_236 . V_253 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
F_76 ( V_172 , V_254 , & V_236 , sizeof V_236 ) ;
F_4 ( V_236 . V_253 ) ;
V_238 -> V_251 . V_255 = 1 ;
break;
default:
break;
}
V_207 -> V_198 += V_202 ;
V_207 -> V_199 -= V_202 ;
}
if ( V_207 -> V_9 -> V_14 && ! V_238 -> V_251 . V_255 ) {
V_236 . V_253 = V_207 -> V_9 -> V_14 ;
F_76 ( V_172 , V_254 , & V_236 , sizeof V_236 ) ;
}
if ( V_207 -> V_9 -> V_17 != - 1 && ! V_238 -> V_251 . V_166 ) {
F_43 ( V_172 , V_250 , ( T_6 ) V_207 -> V_9 -> V_17 ) ;
V_238 -> V_251 . V_166 = 1 ;
}
if ( V_207 -> V_9 -> V_18 != ( V_19 ) - 1 && ! V_238 -> V_251 . V_252 ) {
V_173 -> V_178 = F_73 ( V_197 . V_205 ) ;
V_238 -> V_251 . V_252 = 1 ;
}
V_207 -> V_245 |= 1 << V_101 ;
return 1 ;
}
static int F_77 ( T_7 * V_20 V_25 , T_10 * V_26 , union V_92 * V_87 , struct V_206 * V_207 )
{
struct V_196 V_197 = { 0 , 0 , NULL } ;
V_19 V_202 ;
int V_235 = - 1 ;
T_20 V_172 = NULL ;
T_21 * V_173 = NULL ;
T_24 V_236 ;
V_19 V_101 = 0 ;
V_244 V_16 = - 1 ;
T_6 * V_240 ;
V_19 V_241 ;
struct V_237 * V_238 = NULL ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
if ( ! V_26 || ! V_87 || ! V_207 || ! V_207 -> V_9 )
return - 1 ;
V_240 = V_207 -> V_198 ;
V_241 = V_207 -> V_199 ;
if ( V_207 -> V_239 > 0 && V_207 -> V_239 != 0x7fff ) {
V_16 = V_207 -> V_239 - 1 ;
} else {
while ( ( V_202 = F_62 ( & V_197 , V_240 , V_241 ) ) && ! F_66 ( V_197 . type ) ) {
if ( V_197 . type == V_243 ) {
if ( V_197 . V_204 >= 4 ) {
V_16 = ( V_244 ) F_73 ( V_197 . V_205 ) ;
}
}
V_240 += V_202 ;
V_241 -= V_202 ;
}
}
for ( V_101 = 0 ; V_101 < 4 ; V_101 ++ ) {
V_240 = V_207 -> V_198 ;
V_241 = V_207 -> V_199 ;
V_238 = & V_207 -> V_9 -> V_11 [ V_101 ] ;
if ( V_207 -> V_9 -> V_245 & ( 1 << V_101 )
|| ! ( V_207 -> V_245 & ( 1 << V_101 ) ) ) {
continue;
}
if ( V_238 -> V_16 != - 1
&& V_238 -> V_16 != V_16 ) {
continue;
}
V_235 = V_238 -> V_15 ;
if ( V_235 >= 0 ) {
V_172 = F_58 ( V_26 -> V_184 , T_20 , V_235 ) ;
V_173 = ( T_21 * ) F_41 ( V_172 ) ;
}
if ( ! V_172 ) {
continue;
}
while ( ( V_202 = F_62 ( & V_197 , V_240 , V_241 ) ) && ! F_66 ( V_197 . type ) ) {
switch ( V_197 . type ) {
case V_231 :
if ( V_197 . V_204 >= 4 ) {
V_232 V_166 = ( V_232 ) F_73 ( V_197 . V_205 ) ;
T_6 V_256 = 0 ;
switch ( F_78 ( V_172 , V_250 , & V_256 ) ) {
case V_257 :
if ( V_166 > V_256 || ! V_238 -> V_251 . V_166 ) {
F_79 ( V_172 , V_250 , ( T_6 ) F_73 ( V_197 . V_205 ) ) ;
V_238 -> V_251 . V_166 = 1 ;
}
break;
case V_258 :
F_43 ( V_172 , V_250 , ( T_6 ) F_73 ( V_197 . V_205 ) ) ;
V_238 -> V_251 . V_166 = 1 ;
break;
default:
break;
}
}
break;
case V_233 :
if ( V_197 . V_204 >= 4 ) {
V_19 V_252 = F_73 ( V_197 . V_205 ) ;
if ( V_252 > V_173 -> V_178 || ! V_238 -> V_251 . V_252 ) {
V_173 -> V_178 = F_73 ( V_197 . V_205 ) ;
V_238 -> V_251 . V_252 = 1 ;
}
}
break;
case V_234 :
if ( ! V_238 -> V_251 . V_255 ) {
V_236 . V_253 = F_68 ( ( T_11 * ) V_197 . V_205 , V_197 . V_204 ) ;
F_76 ( V_172 , V_254 , & V_236 , sizeof V_236 ) ;
F_4 ( V_236 . V_253 ) ;
V_238 -> V_251 . V_255 = 1 ;
}
break;
default:
break;
}
V_240 += V_202 ;
V_241 -= V_202 ;
}
}
V_207 -> V_198 = V_240 ;
V_207 -> V_199 = V_241 ;
return 1 ;
}
static int F_21 ( T_7 * V_20 , T_10 * V_26 , union V_92 * V_87 , V_19 V_40 )
{
struct V_206 V_207 ;
struct V_206 * V_259 = NULL ;
T_5 V_7 ;
T_6 V_6 ;
T_23 * V_260 = NULL ;
T_23 * V_195 = NULL ;
struct V_196 V_197 = { 0 , 0 , NULL } ;
V_19 V_202 ;
if ( ! V_20 || ! V_26 || ! V_87 )
return - 1 ;
memset ( & V_207 , 0 , sizeof( struct V_206 ) ) ;
F_46 ( V_87 , & V_7 , & V_6 ) ;
if ( V_7 == 0 ) {
V_7 = V_20 -> V_21 ;
}
V_207 . V_9 = F_48 ( V_20 , V_7 , V_6 ) ;
if ( ! V_207 . V_9 ) {
V_207 . V_9 = F_5 ( V_7 , V_6 ) ;
F_59 ( V_20 -> V_9 , V_207 . V_9 , V_207 . V_9 ) ;
}
if ( ( V_207 . V_9 -> V_245 & 0x03 )
&& V_20 -> V_23 && V_20 -> V_22 ) {
return 0 ;
}
V_207 . V_198 = V_26 -> V_85 -> V_24 ;
V_207 . V_199 = V_40 ;
while ( ( V_202 = F_62 ( & V_197 , V_207 . V_198 , V_207 . V_199 ) ) ) {
if ( ! F_66 ( V_197 . type ) ) {
V_207 . V_198 += V_202 ;
V_207 . V_199 -= V_202 ;
continue;
}
if ( V_197 . type != V_207 . V_216 ) {
if ( ( V_197 . type == V_261 && V_207 . V_216 == V_262 ) ||
( V_197 . type == V_262 && V_207 . V_216 == V_261 ) ) {
} else {
V_207 . V_263 = V_207 . V_216 ;
V_207 . V_264 = V_207 . V_239 ;
}
}
V_207 . V_216 = V_197 . type ;
if ( V_197 . V_204 >= 4 ) {
V_207 . V_239 = F_63 ( V_197 . V_205 ) ;
} else {
V_207 . V_239 = 0 ;
}
V_207 . V_198 += V_202 ;
V_207 . V_199 -= V_202 ;
if ( ( V_202 = F_62 ( & V_197 , V_207 . V_198 , V_207 . V_199 ) ) ) {
if ( V_197 . type == V_265 && V_197 . V_204 >= 4 ) {
V_207 . V_263 = F_63 ( V_197 . V_205 ) ;
V_207 . V_264 = F_63 ( & V_197 . V_205 [ 2 ] ) ;
}
}
if ( F_66 ( V_197 . type ) ) {
continue;
}
if ( V_207 . V_239 & 0x8000 ) {
continue;
}
switch ( V_207 . V_216 ) {
case V_217 :
case V_220 :
F_65 ( V_20 , V_26 , V_87 , & V_207 ) ;
break;
case V_266 :
F_72 ( V_20 , V_26 , V_87 , & V_207 ) ;
break;
case V_262 :
F_74 ( V_20 , V_26 , V_87 , & V_207 ) ;
break;
case V_261 :
V_260 = F_57 ( V_260 , F_80 ( & V_207 , sizeof( struct V_206 ) ) ) ;
break;
case V_267 :
case V_268 :
default:
break;
}
}
if ( V_260 ) {
V_195 = V_260 ;
do {
V_259 = (struct V_206 * ) V_195 -> V_24 ;
switch ( V_259 -> V_216 ) {
case V_261 :
F_77 ( V_20 , V_26 , V_87 , V_259 ) ;
break;
}
} while ( ( V_195 = F_60 ( V_195 ) ) );
F_81 ( V_260 , F_11 , NULL ) ;
F_61 ( V_260 ) ;
}
V_207 . V_9 -> V_245 |= V_207 . V_245 ;
return 0 ;
}
static void V_76 ( T_10 * V_26 )
{
T_7 * V_20 = ( T_7 * ) V_26 -> V_79 ;
F_9 ( V_20 ) ;
V_26 -> V_79 = NULL ;
}
