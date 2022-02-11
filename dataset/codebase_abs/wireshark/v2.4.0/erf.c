static T_1 F_1 ( T_2 V_1 ) {
const struct V_2 * V_3 = ( const struct V_2 * ) V_1 ;
return ( ( V_4 ) V_3 -> V_5 ^ ( V_4 ) V_3 -> V_6 ) ;
}
static T_3 F_2 ( T_2 V_7 , T_2 V_8 ) {
const struct V_2 * V_9 = ( const struct V_2 * ) V_7 ;
const struct V_2 * V_10 = ( const struct V_2 * ) V_8 ;
return ( V_9 -> V_5 ) == ( V_10 -> V_5 ) &&
( V_9 -> V_6 & V_11 ) == ( V_10 -> V_6 & V_11 ) ;
}
static void F_3 ( T_4 V_1 ) {
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if( V_3 -> V_12 != NULL ) {
F_4 ( V_3 -> V_12 ) ;
V_3 -> V_12 = NULL ;
}
F_4 ( V_3 ) ;
V_3 = NULL ;
}
static T_3 F_5 ( T_2 V_7 , T_2 V_8 )
{
const struct V_13 * V_14 = ( const struct V_13 * ) V_7 ;
const struct V_13 * V_15 = ( const struct V_13 * ) V_8 ;
return V_14 -> V_16 == V_15 -> V_16 && V_14 -> V_5 == V_15 -> V_5 ;
}
static T_1 F_6 ( T_2 V_1 )
{
const struct V_13 * V_17 = ( const struct V_13 * ) V_1 ;
return ( ( ( T_1 ) V_17 -> V_5 ) << 16 ) | V_17 -> V_16 ;
}
static void F_7 ( T_4 V_1 )
{
int V_18 = 0 ;
struct V_13 * V_17 = (struct V_13 * ) V_1 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
F_4 ( V_17 -> V_19 [ V_18 ] . V_20 ) ;
F_4 ( V_17 -> V_19 [ V_18 ] . V_21 ) ;
}
F_4 ( V_17 -> V_22 ) ;
F_4 ( V_17 ) ;
}
static struct V_13 * F_8 ( T_5 V_5 , T_6 V_16 )
{
int V_18 = 0 ;
struct V_13 * V_17 = NULL ;
V_17 = (struct V_13 * ) F_9 ( sizeof( struct V_13 ) ) ;
V_17 -> V_5 = V_5 ;
V_17 -> V_16 = V_16 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_17 -> V_19 [ V_18 ] . V_23 = - 1 ;
V_17 -> V_19 [ V_18 ] . V_24 = - 1 ;
}
V_17 -> V_25 = - 1 ;
V_17 -> V_26 = ( V_4 ) - 1 ;
return V_17 ;
}
T_7 * F_10 ( void )
{
T_7 * V_27 ;
V_27 = ( T_7 * ) F_11 ( sizeof( T_7 ) ) ;
V_27 -> V_3 = F_12 ( F_1 , F_2 , F_3 , NULL ) ;
V_27 -> V_17 = F_12 ( F_6 , F_5 , F_7 , NULL ) ;
V_27 -> V_28 = V_29 ;
V_27 -> V_30 = 0 ;
V_27 -> V_31 = 0 ;
return V_27 ;
}
T_7 * F_13 ( T_7 * V_27 )
{
if ( V_27 )
{
F_14 ( V_27 -> V_3 ) ;
F_14 ( V_27 -> V_17 ) ;
F_4 ( V_27 ) ;
}
return NULL ;
}
static void F_15 ( T_8 * V_32 ) {
if( V_32 ) {
if( V_32 -> V_33 ) {
F_16 ( V_32 -> V_33 , TRUE ) ;
}
if( V_32 -> V_34 ) {
F_17 ( V_32 -> V_34 , TRUE ) ;
}
if( V_32 -> V_35 ) {
F_4 ( V_32 -> V_35 ) ;
}
F_4 ( V_32 -> rand ) ;
F_4 ( V_32 ) ;
}
}
static void F_18 ( T_4 V_36 ) {
struct V_37 * V_38 = (struct V_37 * ) V_36 ;
if ( V_38 ) {
F_16 ( V_38 -> V_39 , TRUE ) ;
V_38 -> V_39 = NULL ;
}
F_4 ( V_38 ) ;
}
static void F_19 ( T_4 V_36 ) {
struct V_40 * V_41 = (struct V_40 * ) V_36 ;
if ( V_41 ) {
F_4 ( V_41 -> V_42 ) ;
V_41 -> V_42 = NULL ;
}
F_4 ( V_41 ) ;
}
static T_3 F_20 ( struct V_43 * V_44 , int * V_45 ) {
T_8 * V_32 = ( T_8 * ) V_44 -> V_46 ;
T_3 V_47 = TRUE ;
if( V_32 -> V_48 ) {
if ( ! V_32 -> V_33 ) {
V_32 -> V_33 = F_21 ( F_18 ) ;
if ( V_32 -> V_49 == V_50 && V_32 -> V_51 ) {
F_22 ( V_44 , V_52 , 0 , V_32 -> V_35 , V_32 -> V_33 ) ;
} else {
F_23 ( V_44 , V_32 -> V_33 ) ;
}
}
if ( ! F_24 ( V_44 , V_32 , V_32 -> V_53 , V_32 -> V_33 , V_32 -> V_34 , V_45 ) ) V_47 = FALSE ;
}
F_15 ( V_32 ) ;
V_44 -> V_46 = NULL ;
return V_47 ;
}
static void
F_25 ( T_4 V_36 , T_4 T_9 V_54 )
{
F_4 ( V_36 ) ;
}
extern T_10 F_26 ( T_11 * V_55 , int * V_45 , T_12 * * V_56 )
{
int V_18 , V_57 , V_58 = V_59 ;
int V_60 = 0 ;
char * V_61 ;
T_13 V_62 , V_63 ;
T_14 V_64 ;
V_4 V_65 ;
struct V_66 V_67 ;
V_4 V_68 ;
T_15 V_69 ;
T_5 V_70 ;
T_6 type ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
if ( ( V_61 = getenv ( L_1 ) ) != NULL ) {
if ( F_27 ( V_61 , NULL , & V_57 ) && V_57 >= 0 && V_57 < 101 ) {
V_58 = V_57 ;
}
}
for ( V_18 = 0 ; V_18 < V_58 ; V_18 ++ ) {
if ( ! F_28 ( V_55 -> V_71 , & V_64 , sizeof( V_64 ) , V_45 , V_56 ) ) {
if ( * V_45 == 0 ) {
break;
}
if ( * V_45 == V_72 ) {
if ( V_18 < V_73 ) {
return V_74 ;
} else {
break;
}
} else {
return V_75 ;
}
}
V_69 = F_29 ( V_64 . V_69 ) ;
if ( V_69 < 16 ) {
return V_74 ;
}
V_68 = V_69 - ( V_4 ) sizeof( V_64 ) ;
if ( V_68 > V_76 ) {
return V_74 ;
}
if ( ( V_64 . type & 0x7F ) == V_77 ) {
if ( ! F_30 ( V_55 -> V_71 , NULL , V_68 , V_45 , V_56 ) ) {
if ( * V_45 != V_72 ) {
return V_75 ;
}
if ( V_18 < V_73 ) {
return V_74 ;
}
}
continue;
}
if ( ( V_64 . type & 0x7F ) == 0 ) {
return V_74 ;
}
if ( ( V_63 = F_31 ( & V_64 . V_63 ) ) < V_62 ) {
if ( ( ( V_62 - V_63 ) >> 32 ) > 1 ) {
return V_74 ;
}
}
if ( ( V_60 ) && ( V_63 > V_62 ) && ( ( ( V_63 - V_62 ) >> 32 ) > 3600 * 24 * 7 ) ) {
return V_74 ;
}
memcpy ( & V_62 , & V_63 , sizeof( V_62 ) ) ;
type = V_64 . type ;
while ( type & 0x80 ) {
if ( ! F_30 ( V_55 -> V_71 , & V_70 , sizeof( V_70 ) , V_45 , V_56 ) ) {
if ( * V_45 == V_72 ) {
return V_74 ;
}
return V_75 ;
}
V_68 -= ( V_4 ) sizeof( V_70 ) ;
memcpy ( & type , & V_70 , sizeof( type ) ) ;
}
switch( V_64 . type & 0x7F ) {
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
if ( ! F_30 ( V_55 -> V_71 , & V_65 , sizeof( V_65 ) , V_45 , V_56 ) ) {
if ( * V_45 == V_72 ) {
return V_74 ;
}
return V_75 ;
}
V_68 -= ( V_4 ) sizeof( V_65 ) ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
if ( ! F_30 ( V_55 -> V_71 , & V_67 , sizeof( V_67 ) , V_45 , V_56 ) ) {
if ( * V_45 == V_72 ) {
return V_74 ;
}
return V_75 ;
}
V_68 -= ( V_4 ) sizeof( V_67 ) ;
break;
default:
break;
}
if ( V_68 > V_76 ) {
return V_74 ;
}
if ( ! F_30 ( V_55 -> V_71 , NULL , V_68 , V_45 , V_56 ) ) {
if ( * V_45 != V_72 ) {
return V_75 ;
}
if ( V_18 < V_73 ) {
return V_74 ;
}
}
V_60 = 1 ;
}
if ( F_32 ( V_55 -> V_71 , 0L , V_90 , V_45 ) == - 1 ) {
return V_75 ;
}
V_55 -> V_91 = V_92 ;
V_55 -> V_93 = 0 ;
V_55 -> V_94 = V_95 ;
V_55 -> V_96 = V_97 ;
V_55 -> V_98 = V_99 ;
V_55 -> V_100 = V_101 ;
V_55 -> V_102 = V_103 ;
V_55 -> V_46 = F_10 () ;
return V_104 ;
}
static T_3 V_97 ( T_11 * V_55 , int * V_45 , T_12 * * V_56 ,
T_16 * V_105 )
{
T_14 V_106 ;
V_4 V_68 , V_107 ;
T_17 * V_108 ;
* V_105 = F_33 ( V_55 -> V_71 ) ;
V_108 = F_21 ( F_3 ) ;
do {
if ( ! F_34 ( V_55 , V_55 -> V_71 ,
& V_55 -> V_109 , & V_106 ,
V_45 , V_56 , & V_107 , & V_68 ,
V_108 ) ) {
F_16 ( V_108 , TRUE ) ;
return FALSE ;
}
if ( ! F_35 ( V_55 -> V_71 , V_55 -> V_110 , V_68 ,
V_45 , V_56 ) ) {
F_16 ( V_108 , TRUE ) ;
return FALSE ;
}
if ( ( V_106 . type & 0x7F ) == V_50 && V_68 > 0 )
{
F_36 ( ( T_7 * ) V_55 -> V_46 , V_55 , & V_55 -> V_109 . V_111 , V_68 , V_108 ) ;
}
} while ( V_106 . type == V_77 );
F_16 ( V_108 , TRUE ) ;
return TRUE ;
}
static T_3 V_99 ( T_11 * V_55 , T_16 V_112 ,
struct V_113 * V_109 , T_18 * V_114 ,
int * V_45 , T_12 * * V_56 )
{
T_14 V_106 ;
V_4 V_68 ;
T_17 * V_108 ;
if ( F_32 ( V_55 -> V_115 , V_112 , V_90 , V_45 ) == - 1 )
return FALSE ;
V_108 = F_21 ( F_3 ) ;
do {
if ( ! F_34 ( V_55 , V_55 -> V_115 , V_109 , & V_106 ,
V_45 , V_56 , NULL , & V_68 , V_108 ) ) {
F_16 ( V_108 , TRUE ) ;
return FALSE ;
}
} while ( V_106 . type == V_77 );
F_16 ( V_108 , TRUE ) ;
return F_35 ( V_55 -> V_115 , V_114 , V_68 ,
V_45 , V_56 ) ;
}
static struct V_2 * F_37 ( T_7 * V_46 ,
T_5 V_5 ,
T_5 V_6 )
{
struct V_2 V_116 = {
V_5 ,
V_6 ,
0 ,
NULL
} ;
if ( ! V_46 ) {
return NULL ;
}
return (struct V_2 * ) F_38 ( V_46 -> V_3 , & V_116 ) ;
}
static T_3 F_34 ( T_11 * V_55 , T_19 V_71 ,
struct V_113 * V_109 ,
T_14 * V_106 ,
int * V_45 ,
T_12 * * V_56 ,
V_4 * V_107 ,
V_4 * V_68 ,
T_17 * V_108 )
{
union V_117 * V_111 = & V_109 -> V_111 ;
T_6 V_118 [ 8 ] ;
T_5 V_119 ;
T_6 type = 0 ;
V_4 V_65 ;
V_4 V_120 ;
struct V_121 V_67 ;
V_4 V_122 = 0 ;
int V_18 = 0 ;
int V_123 = sizeof( V_111 -> erf . V_124 ) / sizeof( struct V_125 ) ;
T_7 * V_46 = ( T_7 * ) V_55 -> V_46 ;
T_5 V_5 = V_29 ;
T_6 V_16 = 0 ;
T_6 V_126 = 0 ;
T_3 V_127 = FALSE ;
if ( ! F_28 ( V_71 , V_106 , sizeof( * V_106 ) , V_45 , V_56 ) ) {
return FALSE ;
}
if ( V_107 != NULL ) {
* V_107 = sizeof( * V_106 ) ;
}
* V_68 = F_29 ( V_106 -> V_69 ) - ( V_4 ) sizeof( * V_106 ) ;
if ( * V_68 > V_76 ) {
* V_45 = V_128 ;
* V_56 = F_39 ( L_2 ,
* V_68 , V_76 ) ;
return FALSE ;
}
if ( * V_68 == 0 ) {
if ( ( V_106 -> type & 0x7F ) != V_77 ) {
* V_45 = V_128 ;
* V_56 = F_40 ( L_3 ) ;
return FALSE ;
}
}
{
T_5 V_63 = F_31 ( & V_106 -> V_63 ) ;
V_109 -> V_129 = V_130 ;
#if 0
} else {
phdr->rec_type = REC_TYPE_FT_SPECIFIC_REPORT;
}
#endif
V_109 -> V_131 = V_132 | V_133 | V_134 ;
V_109 -> V_63 . V_135 = ( long ) ( V_63 >> 32 ) ;
V_63 = ( ( V_63 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_63 += ( V_63 & 0x80000000 ) << 1 ;
V_109 -> V_63 . V_136 = ( ( int ) ( V_63 >> 32 ) ) ;
if ( V_109 -> V_63 . V_136 >= 1000000000 ) {
V_109 -> V_63 . V_136 -= 1000000000 ;
V_109 -> V_63 . V_135 += 1 ;
}
V_126 = V_106 -> V_137 & 0x03 ;
}
memset ( & V_111 -> erf , 0 , sizeof( V_111 -> erf ) ) ;
V_111 -> erf . V_109 . V_63 = F_31 ( & V_106 -> V_63 ) ;
V_111 -> erf . V_109 . type = V_106 -> type ;
V_111 -> erf . V_109 . V_137 = V_106 -> V_137 ;
V_111 -> erf . V_109 . V_69 = F_29 ( V_106 -> V_69 ) ;
V_111 -> erf . V_109 . V_138 = F_29 ( V_106 -> V_138 ) ;
V_111 -> erf . V_109 . V_139 = F_29 ( V_106 -> V_139 ) ;
type = V_106 -> type ;
while ( type & 0x80 ) {
if ( ! F_30 ( V_71 , & V_118 , sizeof( V_118 ) ,
V_45 , V_56 ) )
return FALSE ;
if ( V_107 != NULL )
* V_107 += ( V_4 ) sizeof( V_118 ) ;
* V_68 -= ( V_4 ) sizeof( V_118 ) ;
V_122 += ( V_4 ) sizeof( V_118 ) ;
V_119 = F_41 ( V_118 ) ;
if ( V_18 < V_123 )
memcpy ( & V_111 -> erf . V_124 [ V_18 ] . V_140 , & V_119 , sizeof( V_119 ) ) ;
type = V_118 [ 0 ] ;
switch ( type & 0x7FU ) {
case V_141 :
if ( ! V_127 )
V_5 = V_119 & V_142 ;
V_127 = TRUE ;
case V_143 :
if ( ! V_16 )
V_16 = ( V_119 >> 48 ) & 0xff ;
break;
case V_11 :
break;
}
V_18 ++ ;
}
V_109 -> V_144 = ( T_1 ) F_42 ( ( T_7 * ) V_55 -> V_46 , V_55 , V_111 , V_5 , V_16 , V_126 ) ;
F_43 ( V_46 , V_109 , V_111 , V_5 , V_108 ) ;
switch ( V_106 -> type & 0x7F ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_50 :
case V_150 :
case V_151 :
#if 0
{
phdr->len = g_htons(erf_header->wlen);
phdr->caplen = g_htons(erf_header->wlen);
}
return TRUE;
#endif
break;
case V_77 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
if ( ! F_30 ( V_71 , & V_67 , sizeof( V_67 ) , V_45 , V_56 ) )
return FALSE ;
if ( V_107 != NULL )
* V_107 += ( V_4 ) sizeof( V_67 ) ;
* V_68 -= ( V_4 ) sizeof( V_67 ) ;
V_122 += ( V_4 ) sizeof( V_67 ) ;
V_111 -> erf . V_158 . V_67 = V_67 ;
break;
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
if ( ! F_30 ( V_71 , & V_65 , sizeof( V_65 ) , V_45 , V_56 ) )
return FALSE ;
if ( V_107 != NULL )
* V_107 += ( V_4 ) sizeof( V_65 ) ;
* V_68 -= ( V_4 ) sizeof( V_65 ) ;
V_122 += ( V_4 ) sizeof( V_65 ) ;
V_111 -> erf . V_158 . V_65 = F_44 ( V_65 ) ;
break;
case V_85 :
if ( ! F_30 ( V_71 , & V_120 , sizeof( V_120 ) , V_45 , V_56 ) )
return FALSE ;
if ( V_107 != NULL )
* V_107 += ( V_4 ) sizeof( V_120 ) ;
* V_68 -= ( V_4 ) sizeof( V_120 ) ;
V_122 += ( V_4 ) sizeof( V_120 ) ;
V_111 -> erf . V_158 . V_120 = F_44 ( V_120 ) ;
break;
case V_159 :
case V_160 :
default:
break;
}
{
V_109 -> V_161 = F_29 ( V_106 -> V_139 ) ;
V_109 -> V_162 = F_45 ( F_29 ( V_106 -> V_139 ) ,
F_29 ( V_106 -> V_69 ) - ( V_4 ) sizeof( * V_106 ) - V_122 ) ;
}
if ( * V_68 > V_76 ) {
* V_45 = V_128 ;
* V_56 = F_39 ( L_2 ,
* V_68 , V_76 ) ;
return FALSE ;
}
return TRUE ;
}
static int F_46 ( int V_163 )
{
unsigned int V_18 ;
for( V_18 = 0 ; V_18 < V_164 ; V_18 ++ ) {
if( V_165 [ V_18 ] . V_166 == V_163 )
return V_165 [ V_18 ] . V_167 ;
}
return - 1 ;
}
static T_3 F_47 ( V_43 * V_44 , int V_163 , const union V_117 * V_111 , int * V_45 )
{
T_6 V_168 [ sizeof( struct V_169 ) ] ;
T_6 V_170 [ sizeof( union V_170 ) ] ;
T_6 V_140 [ 8 * V_171 ] ;
T_20 V_172 = 0 ;
T_20 V_173 = 0 ;
int V_18 = 0 ;
T_6 V_174 = 0 ;
switch( V_163 ) {
case V_95 :
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
F_48 ( & V_168 [ 0 ] , V_111 -> erf . V_109 . V_63 ) ;
V_168 [ 8 ] = V_111 -> erf . V_109 . type ;
V_168 [ 9 ] = V_111 -> erf . V_109 . V_137 ;
F_49 ( & V_168 [ 10 ] , V_111 -> erf . V_109 . V_69 ) ;
F_49 ( & V_168 [ 12 ] , V_111 -> erf . V_109 . V_138 ) ;
F_49 ( & V_168 [ 14 ] , V_111 -> erf . V_109 . V_139 ) ;
V_172 = sizeof( struct V_175 ) ;
switch( V_111 -> erf . V_109 . type & 0x7F ) {
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
F_50 ( & V_170 [ 0 ] , V_111 -> erf . V_158 . V_65 ) ;
V_173 += ( int ) sizeof( struct V_176 ) ;
break;
case V_85 :
F_50 ( & V_170 [ 0 ] , V_111 -> erf . V_158 . V_120 ) ;
V_173 += ( int ) sizeof( struct V_177 ) ;
break;
case V_86 :
case V_87 :
case V_88 :
case V_89 :
memcpy ( & V_170 [ 0 ] , & V_111 -> erf . V_158 . V_67 , sizeof V_111 -> erf . V_158 . V_67 ) ;
V_173 += ( int ) sizeof( struct V_66 ) ;
break;
default:
break;
}
break;
default:
return FALSE ;
}
if ( ! F_51 ( V_44 , V_168 , V_172 , V_45 ) )
return FALSE ;
V_44 -> V_178 += V_172 ;
V_174 = V_111 -> erf . V_109 . type & 0x80 ;
if( V_174 ) {
do{
F_52 ( V_140 + ( V_18 * 8 ) , V_111 -> erf . V_124 [ V_18 ] . V_140 ) ;
if( V_18 == V_171 - 1 ) V_140 [ V_18 * 8 ] = V_140 [ V_18 * 8 ] & 0x7F ;
V_174 = V_140 [ V_18 * 8 ] & 0x80 ;
V_18 ++ ;
}while( V_174 && V_18 < V_171 );
if ( ! F_51 ( V_44 , V_140 , 8 * V_18 , V_45 ) )
return FALSE ;
V_44 -> V_178 += 8 * V_18 ;
}
if( ! F_51 ( V_44 , V_170 , V_173 , V_45 ) )
return FALSE ;
V_44 -> V_178 += V_173 ;
return TRUE ;
}
static void F_53 ( T_8 * V_32 ) {
T_21 V_179 ;
F_54 ( & V_179 ) ;
V_32 -> V_180 = ( ( T_5 ) V_179 . V_181 << 32 ) + ( ( T_5 ) V_179 . V_182 << 32 ) / 1000 / 1000 ;
}
static void F_55 ( T_22 T_23 V_54 ,
T_1 V_183 ,
T_24 T_25 V_54 ,
T_26 * V_184 ,
void * T_9 ) {
struct V_37 * V_38 = (struct V_37 * ) T_9 ;
struct V_40 * V_41 = NULL ;
V_41 = (struct V_40 * ) F_9 ( sizeof( struct V_40 ) ) ;
switch( V_183 ) {
case V_185 :
V_41 -> type = V_186 ;
V_41 -> V_42 = ( T_6 * ) F_40 ( V_184 -> V_187 ) ;
V_41 -> V_188 = ( T_15 ) strlen ( ( char * ) V_41 -> V_42 ) ;
break;
case V_189 :
V_41 -> type = V_190 ;
V_41 -> V_42 = ( T_6 * ) F_40 ( V_184 -> V_187 ) ;
V_41 -> V_188 = ( T_15 ) strlen ( ( char * ) V_41 -> V_42 ) ;
break;
default:
F_19 ( V_41 ) ;
V_41 = NULL ;
break;
}
if ( V_41 )
F_56 ( V_38 -> V_39 , V_41 ) ;
}
static void F_57 ( T_22 T_23 V_54 ,
T_1 V_183 ,
T_24 T_25 V_54 ,
T_26 * V_184 ,
void * T_9 ) {
struct V_37 * V_38 = (struct V_37 * ) T_9 ;
struct V_40 * V_41 = NULL ;
V_41 = (struct V_40 * ) F_9 ( sizeof( struct V_40 ) ) ;
switch( V_183 ) {
case V_191 :
V_41 -> type = V_192 ;
V_41 -> V_42 = ( T_6 * ) F_40 ( V_184 -> V_187 ) ;
V_41 -> V_188 = ( T_15 ) strlen ( ( char * ) V_41 -> V_42 ) ;
break;
case V_193 :
V_41 -> type = V_194 ;
V_41 -> V_42 = ( T_6 * ) F_40 ( V_184 -> V_187 ) ;
V_41 -> V_188 = ( T_15 ) strlen ( ( char * ) V_41 -> V_42 ) ;
break;
default:
F_19 ( V_41 ) ;
V_41 = NULL ;
break;
}
if ( V_41 )
F_56 ( V_38 -> V_39 , V_41 ) ;
}
static void F_58 ( T_22 T_23 V_54 ,
T_1 V_183 ,
T_24 T_25 V_54 ,
T_26 * V_184 ,
void * T_9 ) {
struct V_37 * V_38 = (struct V_37 * ) T_9 ;
struct V_40 * V_41 = NULL ;
V_41 = (struct V_40 * ) F_9 ( sizeof( struct V_40 ) ) ;
switch( V_183 ) {
case V_189 :
V_41 -> type = V_190 ;
V_41 -> V_42 = ( T_6 * ) F_40 ( V_184 -> V_187 ) ;
V_41 -> V_188 = ( T_15 ) strlen ( ( char * ) V_41 -> V_42 ) ;
break;
case V_195 :
V_41 -> type = V_196 ;
V_41 -> V_42 = ( T_6 * ) F_40 ( V_184 -> V_187 ) ;
V_41 -> V_188 = ( T_15 ) strlen ( ( char * ) V_41 -> V_42 ) ;
break;
case V_197 :
V_41 -> type = V_198 ;
V_41 -> V_42 = ( T_6 * ) F_40 ( V_184 -> V_187 ) ;
V_41 -> V_188 = ( T_15 ) strlen ( ( char * ) V_41 -> V_42 ) ;
break;
case V_199 :
V_41 -> type = V_194 ;
V_41 -> V_42 = ( T_6 * ) F_40 ( V_184 -> V_187 ) ;
V_41 -> V_188 = ( T_15 ) strlen ( ( char * ) V_41 -> V_42 ) ;
break;
case V_200 :
V_41 -> type = V_201 ;
V_41 -> V_188 = 8 ;
V_41 -> V_42 = ( T_6 * ) F_11 ( sizeof( V_184 -> V_202 ) ) ;
F_48 ( V_41 -> V_42 , V_184 -> V_202 << 32 ) ;
break;
case V_203 :
V_41 -> type = V_204 ;
V_41 -> V_188 = 8 ;
V_41 -> V_42 = ( T_6 * ) F_11 ( sizeof( V_184 -> V_202 ) ) ;
F_52 ( V_41 -> V_42 , V_184 -> V_202 ) ;
break;
case V_205 :
V_41 -> type = V_206 ;
V_41 -> V_188 = 4 ;
V_41 -> V_42 = ( T_6 * ) F_11 ( sizeof( V_184 -> V_207 ) ) ;
memcpy ( V_41 -> V_42 , & V_184 -> V_207 , sizeof( V_184 -> V_207 ) ) ;
break;
case V_208 :
V_41 -> type = V_209 ;
V_41 -> V_188 = 16 ;
V_41 -> V_42 = ( T_6 * ) F_11 ( sizeof( V_184 -> V_210 ) ) ;
memcpy ( V_41 -> V_42 , & V_184 -> V_210 , sizeof( V_184 -> V_210 ) ) ;
break;
case V_211 :
{
T_27 * V_212 ;
V_41 -> type = 0xF800 ;
V_212 = ( T_27 * ) & V_184 -> V_213 ;
if( V_212 -> V_214 ) {
V_41 -> type = V_215 ;
V_41 -> V_42 = ( T_6 * ) F_40 ( V_212 -> V_214 ) ;
V_41 -> V_188 = ( T_15 ) strlen ( ( char * ) V_41 -> V_42 ) ;
}
}
break;
case V_216 :
V_41 -> type = V_217 ;
V_41 -> V_188 = 4 ;
V_41 -> V_42 = ( T_6 * ) F_11 ( V_41 -> V_188 ) ;
F_50 ( V_41 -> V_42 , ( V_4 ) V_184 -> V_218 ) ;
break;
case V_219 :
#if 0
tag_ptr->type = ERF_META_TAG_if_eui;
tag_ptr->length = 8;
tag_ptr->value = (guint8*)g_malloc(sizeof(optval->eui64val));
memcpy(tag_ptr->value, &optval->euival, sizeof(optval->eui64val));
break;
#endif
case V_220 :
#if 0
tag_ptr->type = ERF_META_TAG_if_mac;
tag_ptr->length = 6;
tag_ptr->value = (guint8*)g_malloc(sizeof(optval->macval));
memcpy(tag_ptr->value, &optval->macval, sizeof(optval->macval));
break;
#endif
case V_221 :
case V_222 :
default:
F_19 ( V_41 ) ;
V_41 = NULL ;
break;
}
if ( V_41 )
F_56 ( V_38 -> V_39 , V_41 ) ;
}
static void F_59 ( struct V_37 * V_38 ) {
T_1 V_18 = 0 ;
struct V_40 * V_41 ;
V_38 -> V_223 = 8 ;
for(; V_18 < V_38 -> V_39 -> V_161 ; V_18 ++ ) {
V_41 = (struct V_40 * ) F_60 ( V_38 -> V_39 , V_18 ) ;
V_38 -> V_223 += F_61 ( V_41 -> V_188 ) ;
}
}
static T_3 F_62 ( T_22 T_23 , T_17 * V_224 , T_15 V_225 , T_15 V_226 , T_28 V_227 ) {
if( ! T_23 || ! V_224 || ! V_227 ) {
return FALSE ;
}
struct V_37 * V_38 ;
V_38 = (struct V_37 * ) F_11 ( sizeof( struct V_37 ) ) ;
V_38 -> V_39 = F_21 ( F_19 ) ;
V_38 -> type = V_225 ;
V_38 -> V_226 = V_226 ;
F_63 ( T_23 , V_227 , ( void * ) V_38 ) ;
F_59 ( V_38 ) ;
F_56 ( V_224 , V_38 ) ;
return TRUE ;
}
static T_3 F_64 ( V_43 * V_44 , struct V_40 * V_41 , int * V_45 ) {
T_15 V_36 [ 2 ] ;
T_1 V_228 = 0 ;
V_4 V_229 = 0 ;
V_228 = F_65 ( V_41 -> V_188 ) - V_41 -> V_188 ;
V_36 [ 0 ] = F_66 ( V_41 -> type ) ;
V_36 [ 1 ] = F_66 ( V_41 -> V_188 ) ;
if( ! F_51 ( V_44 , V_36 , sizeof( V_36 ) , V_45 ) ) return FALSE ;
V_44 -> V_178 += sizeof( V_36 ) ;
if( ! F_51 ( V_44 , V_41 -> V_42 , V_41 -> V_188 , V_45 ) ) return FALSE ;
V_44 -> V_178 += V_41 -> V_188 ;
if( V_228 ) {
if( ! F_51 ( V_44 , & V_229 , V_228 , V_45 ) ) return FALSE ;
V_44 -> V_178 += V_228 ;
}
return TRUE ;
}
static T_3 F_67 ( V_43 * V_44 , struct V_37 * V_38 , int * V_45 ) {
struct V_40 * V_41 ;
T_1 V_18 ;
T_15 V_36 [ 4 ] ;
V_36 [ 0 ] = F_66 ( V_38 -> type ) ;
V_36 [ 1 ] = F_66 ( 4 ) ;
V_36 [ 2 ] = F_66 ( V_38 -> V_226 ) ;
V_36 [ 3 ] = F_66 ( V_38 -> V_223 ) ;
if( ! F_51 ( V_44 , V_36 , sizeof( V_36 ) , V_45 ) ) return FALSE ;
V_44 -> V_178 += sizeof( V_36 ) ;
for( V_18 = 0 ; V_18 < V_38 -> V_39 -> V_161 ; V_18 ++ ) {
V_41 = (struct V_40 * ) F_60 ( V_38 -> V_39 , V_18 ) ;
if( ! F_64 ( V_44 , V_41 , V_45 ) ) return FALSE ;
}
return TRUE ;
}
static T_3 F_23 ( V_43 * V_44 , T_17 * V_224 ) {
T_22 T_23 ;
T_1 V_18 = 0 ;
T_23 = F_68 ( V_44 -> V_230 , T_22 , 0 ) ;
F_62 ( T_23 , V_224 , V_52 , 0 , F_55 ) ;
T_23 = F_68 ( V_44 -> V_230 , T_22 , 0 ) ;
F_62 ( T_23 , V_224 , V_231 , 0 , F_57 ) ;
for( V_18 = 0 ; V_18 < V_44 -> V_232 -> V_161 ; V_18 ++ ) {
T_23 = F_68 ( V_44 -> V_232 , T_22 , V_18 ) ;
F_62 ( T_23 , V_224 , V_233 , ( V_234 ) V_18 + 1 , F_58 ) ;
}
return TRUE ;
}
static T_3 F_22 ( V_43 * V_44 V_54 , T_15 V_225 , T_15 V_226 , T_12 * V_12 , T_17 * V_224 ) {
struct V_37 * V_38 ;
struct V_40 * V_235 = NULL ;
struct V_40 * V_236 = NULL ;
const T_12 * V_237 = NULL ;
V_38 = (struct V_37 * ) F_11 ( sizeof( struct V_37 ) ) ;
V_38 -> type = V_225 ;
V_38 -> V_226 = V_226 ;
V_38 -> V_39 = F_21 ( F_19 ) ;
V_235 = (struct V_40 * ) F_11 ( sizeof( struct V_40 ) ) ;
V_235 -> type = V_190 ;
V_235 -> V_42 = ( T_6 * ) F_40 ( V_12 ? V_12 : L_4 ) ;
V_235 -> V_188 = ( T_15 ) strlen ( ( char * ) V_235 -> V_42 ) ;
F_56 ( V_38 -> V_39 , V_235 ) ;
V_237 = F_69 () ;
if ( V_237 ) {
V_236 = (struct V_40 * ) F_11 ( sizeof( struct V_40 ) ) ;
V_236 -> type = V_238 ;
V_236 -> V_42 = ( T_6 * ) F_40 ( V_237 ) ;
V_236 -> V_188 = ( T_15 ) strlen ( ( char * ) V_236 -> V_42 ) ;
F_56 ( V_38 -> V_39 , V_236 ) ;
}
F_59 ( V_38 ) ;
F_56 ( V_224 , V_38 ) ;
return TRUE ;
}
static T_5 F_70 ( T_8 * V_32 ) {
return ( ( ( T_5 ) F_71 ( V_32 -> rand ) << 32 ) | ( T_5 ) F_71 ( V_32 -> rand ) ) >> 16 ;
}
static T_5 F_72 ( T_6 V_239 , T_5 V_240 , T_6 V_241 ) {
T_5 V_242 ;
V_242 = V_240 & V_142 ;
V_242 |= ( ( T_5 ) V_241 ) << 48 ;
V_242 |= ( ( T_5 ) V_239 ) << 56 ;
return V_242 ;
}
static inline T_3 F_73 ( T_5 V_242 , T_5 V_243 , T_29 * V_244 ) {
T_1 V_18 = 0 ;
struct V_125 V_245 ;
struct V_125 * V_246 = NULL ;
if ( ! V_244 )
return FALSE ;
V_242 = V_242 & ~ V_247 ;
if ( V_243 == 0 )
V_243 = V_248 ;
V_243 &= ~ V_247 ;
for ( V_18 = 0 ; V_18 < V_244 -> V_161 ; V_18 ++ ) {
V_246 = & F_68 ( V_244 , struct V_125 , V_18 ) ;
if ( V_242 == ( V_246 -> V_140 & V_243 ) ) {
return TRUE ;
}
}
if ( V_246 ) {
V_246 -> V_140 |= V_247 ;
}
V_245 . V_140 = V_242 ;
F_74 ( V_244 , V_245 ) ;
return TRUE ;
}
static inline T_3 F_75 ( T_5 V_242 , T_29 * V_244 ) {
struct V_125 V_245 ;
if ( ! V_244 )
return FALSE ;
V_245 . V_140 = V_242 & ~ V_247 ;
if ( V_244 -> V_161 ) {
F_68 ( V_244 , struct V_125 , V_244 -> V_161 - 1 ) . V_140 |= V_247 ;
}
F_74 ( V_244 , V_245 ) ;
return TRUE ;
}
static T_3 F_76 ( T_8 * V_32 , const union V_117 * V_111 , T_29 * V_244 ) {
T_6 type ;
T_6 V_249 ;
int V_174 ;
T_5 V_250 ;
int V_18 = 0 ;
T_6 V_16 = 0 ;
T_5 V_5 = 0 ;
T_3 V_127 = FALSE ;
if ( ! V_244 )
return FALSE ;
V_249 = V_111 -> erf . V_109 . type & 0x7f ;
V_174 = V_111 -> erf . V_109 . type & 0x80 ;
while ( V_174 && V_18 < V_171 ) {
V_250 = V_111 -> erf . V_124 [ V_18 ] . V_140 ;
type = ( T_6 ) ( V_250 >> 56 ) ;
switch ( type & 0x7f ) {
case V_141 :
V_5 = V_250 & V_142 ;
V_16 = ( V_250 >> 48 ) & 0xff ;
if ( V_5 != V_32 -> V_5 || V_16 != 0 )
if ( ! F_73 ( V_250 , 0 , V_244 ) ) return FALSE ;
if ( ! V_127 ) {
if ( V_249 == V_50 && ( ( V_250 >> 48 ) & 0xff ) > 0 ) {
if ( V_32 -> V_28 == V_29 ) {
V_32 -> V_28 = V_5 ;
}
}
}
V_127 = TRUE ;
break;
case V_143 :
if ( V_16 == 0 )
V_16 = ( V_250 >> 48 ) & 0xff ;
break;
}
V_174 = type & 0x80 ;
V_18 ++ ;
}
if ( ! V_127 ) {
T_5 V_28 = V_32 -> V_28 == V_29 ? 0 : V_32 -> V_28 ;
if ( V_28 != V_32 -> V_5 || V_16 != 0 )
if ( ! F_73 ( F_77 ( V_28 , V_16 ) , 0 , V_244 ) ) return FALSE ;
}
return TRUE ;
}
static T_3 F_78 ( V_43 * V_44 , T_8 * V_32 , const struct V_113 * V_109 , union V_117 * V_251 , int * V_45 ) {
T_29 * V_252 ;
T_17 * V_224 = NULL ;
T_6 V_174 ;
T_6 V_18 = 0 ;
T_6 V_253 = 0 ;
T_6 V_254 = 0 ;
T_5 V_255 = V_29 ;
T_5 V_256 = F_77 ( V_32 -> V_5 , 0 ) ;
T_5 V_257 = 0 ;
T_5 V_258 = 0 ;
T_3 V_259 = FALSE ;
T_3 V_260 = FALSE ;
T_3 V_261 = FALSE ;
T_30 V_262 = 0 ;
T_6 V_263 = 0 ;
T_6 V_16 = 0 ;
T_3 V_47 = FALSE ;
T_5 V_28 = V_32 -> V_28 == V_29 ? 0 : V_32 -> V_28 ;
V_174 = V_251 -> erf . V_109 . type & 0x80 ;
while ( V_174 && ( V_18 < V_171 ) ) {
T_5 V_250 = V_251 -> erf . V_124 [ V_18 ] . V_140 ;
T_6 type = ( T_6 ) ( V_250 >> 56 ) ;
switch ( type & 0x7f ) {
case V_141 :
if ( V_260 && ! V_263 )
V_263 = V_18 ;
if ( ( V_250 & V_142 ) == V_32 -> V_5 ) {
V_260 = TRUE ;
}
if ( ! V_259 )
V_255 = V_250 ;
V_259 = TRUE ;
break;
case V_143 :
if ( V_16 == 0 )
V_16 = ( T_6 ) ( V_250 >> 48 ) ;
if ( ! V_261 )
V_257 = V_250 ;
V_261 = TRUE ;
break;
}
V_174 = type & 0x80 ;
V_18 += 1 ;
}
V_253 = V_18 ;
if ( ! V_263 )
V_263 = V_18 ;
if ( ! V_259 && V_28 == V_32 -> V_5 ) {
V_260 = TRUE ;
}
V_262 = 1 + ( V_260 ? 0 : 1 ) + ( V_259 ? 0 : 1 ) ;
if( V_253 + V_262 > V_171
|| V_251 -> erf . V_109 . V_69 + V_262 * 8 > 65535 ) {
* V_45 = V_264 ;
return FALSE ;
}
V_251 -> erf . V_109 . V_69 += V_262 * 8 ;
V_251 -> erf . V_109 . type |= 0x80 ;
if ( V_263 > 0 ) {
V_251 -> erf . V_124 [ V_263 - 1 ] . V_140 |= V_247 ;
}
V_258 = F_79 ( F_70 ( V_32 ) , 0 ) ;
if ( V_263 < V_253 ) {
for ( V_254 = V_253 ; V_254 > V_263 ; V_254 -- ) {
V_251 -> erf . V_124 [ V_254 ] . V_140 = V_251 -> erf . V_124 [ V_254 - 1 ] . V_140 ;
}
V_258 |= V_247 ;
}
if( ! V_259 ) {
V_255 = F_77 ( V_28 , V_16 ) ;
V_251 -> erf . V_124 [ V_263 ++ ] . V_140 = F_80 ( V_255 ) ;
}
if( ! V_260 ) {
V_251 -> erf . V_124 [ V_263 ++ ] . V_140 = F_80 ( V_256 ) ;
}
V_251 -> erf . V_124 [ V_263 ] . V_140 = V_258 ;
V_252 = F_81 ( FALSE , FALSE , sizeof( struct V_125 ) ) ;
F_75 ( V_258 | V_265 , V_252 ) ;
F_75 ( V_255 , V_252 ) ;
if ( V_261 ) {
F_75 ( V_257 & ~ ( V_266 | V_267 ) , V_252 ) ;
}
V_224 = F_21 ( F_18 ) ;
F_22 ( V_44 , V_268 , 0x8000 , V_109 -> V_269 , V_224 ) ;
V_47 = F_24 ( V_44 , V_32 , V_251 -> erf . V_109 . V_63 , V_224 , V_252 , V_45 ) ;
F_16 ( V_224 , TRUE ) ;
F_17 ( V_252 , TRUE ) ;
return V_47 ;
}
static T_3 F_24 ( V_43 * V_44 , T_8 * V_32 , T_5 V_270 , T_17 * V_224 , T_29 * V_244 , int * V_45 ) {
union V_117 V_271 ;
struct V_40 V_272 ;
struct V_37 * V_38 ;
T_1 V_273 = 0 ;
T_1 V_274 = 0 ;
T_16 V_275 = 0 ;
T_1 V_18 ;
T_1 V_276 = 0 ;
if( ! V_224 || V_224 -> V_161 <= 0 )
return FALSE ;
for( V_18 = 0 ; V_18 < V_224 -> V_161 ; V_18 ++ ) {
V_38 = (struct V_37 * ) F_60 ( V_224 , V_18 ) ;
V_273 += V_38 -> V_223 ;
}
V_272 . type = V_277 ;
V_272 . V_188 = 8U ;
V_272 . V_42 = ( T_6 * ) & V_32 -> V_180 ;
V_273 += V_272 . V_188 + 4 ;
V_274 = V_273 + 24 ;
if ( V_244 ) {
V_276 = F_45 ( V_244 -> V_161 , V_171 - 1 ) ;
V_274 += V_276 * 8 ;
}
V_274 += F_82 ( V_274 ) ;
if( V_274 > 65535 ) {
* V_45 = V_264 ;
return FALSE ;
}
V_271 . erf . V_109 . V_63 = V_270 ;
V_271 . erf . V_109 . type = V_50 | 0x80 ;
V_271 . erf . V_109 . V_137 = 0x04 ;
V_271 . erf . V_109 . V_138 = 0 ;
V_271 . erf . V_109 . V_139 = ( T_15 ) V_273 ;
V_271 . erf . V_109 . V_69 = ( T_15 ) V_274 ;
V_271 . erf . V_124 [ 0 ] . V_140 = F_77 ( V_32 -> V_5 , 0 ) ;
if ( V_276 > 0 ) {
V_271 . erf . V_124 [ 0 ] . V_140 |= V_247 ;
memcpy ( & V_271 . erf . V_124 [ 1 ] , V_244 -> V_36 , sizeof( struct V_125 ) * V_276 ) ;
}
V_275 = V_44 -> V_178 + V_271 . erf . V_109 . V_69 ;
if( ! F_47 ( V_44 , V_95 , & V_271 , V_45 ) ) return FALSE ;
F_64 ( V_44 , & V_272 , V_45 ) ;
for( V_18 = 0 ; V_18 < V_224 -> V_161 ; V_18 ++ ) {
V_38 = (struct V_37 * ) F_60 ( V_224 , V_18 ) ;
F_67 ( V_44 , V_38 , V_45 ) ;
}
while( V_44 -> V_178 < V_275 ) {
if( ! F_51 ( V_44 , L_4 , 1 , V_45 ) ) return FALSE ;
V_44 -> V_178 ++ ;
}
V_44 -> V_278 = TRUE ;
return TRUE ;
}
T_8 * F_83 ( void ) {
T_8 * V_32 ;
V_32 = ( T_8 * ) F_11 ( sizeof( T_8 ) ) ;
V_32 -> V_48 = FALSE ;
V_32 -> V_51 = FALSE ;
V_32 -> V_180 = 0 ;
V_32 -> V_5 = V_279 ;
V_32 -> V_28 = V_29 ;
V_32 -> V_280 = 0 ;
V_32 -> V_281 = 0 ;
V_32 -> V_53 = 0 ;
V_32 -> V_49 = 0 ;
V_32 -> V_35 = NULL ;
V_32 -> V_33 = NULL ;
V_32 -> V_34 = F_81 ( FALSE , FALSE , sizeof( struct V_125 ) ) ;
V_32 -> rand = F_84 () ;
return V_32 ;
}
static T_3 F_85 (
V_43 * V_44 ,
const struct V_113 * V_109 ,
const T_6 * V_282 ,
int * V_45 ,
T_12 * * V_56 V_54 )
{
const union V_117 * V_111 = & V_109 -> V_111 ;
union V_117 V_283 ;
int V_163 ;
int V_249 ;
T_16 V_275 = 0 ;
T_1 V_284 = 0 ;
int V_285 = 0 ;
T_3 V_286 = FALSE ;
V_4 V_287 = 0x00000000 ;
T_8 * V_32 = ( T_8 * ) V_44 -> V_46 ;
T_5 V_288 = F_77 ( 0 , 1 ) ;
if( V_109 -> V_162 > V_76 ) {
* V_45 = V_264 ;
return FALSE ;
}
if( V_44 -> V_163 == V_289 ) {
V_163 = V_109 -> V_290 ;
} else{
V_163 = V_44 -> V_163 ;
}
if( ! V_32 -> V_180 ) {
F_53 ( V_32 ) ;
V_32 -> V_280 = V_109 -> V_63 . V_135 ;
}
if ( V_163 != V_95 ) {
unsigned int V_274 ; ;
unsigned int V_273 ;
V_274 = V_109 -> V_162 + 16 ;
V_273 = V_109 -> V_161 ;
if ( V_109 -> V_129 != V_130 ) {
* V_45 = V_291 ;
return FALSE ;
}
if ( ( V_249 = F_46 ( V_163 ) ) == - 1 ) {
* V_45 = V_292 ;
return FALSE ;
}
memset ( & V_283 , 0 , sizeof( union V_117 ) ) ;
V_283 . erf . V_109 . V_63 = ( ( T_5 ) V_109 -> V_63 . V_135 << 32 ) + ( ( ( T_5 ) V_109 -> V_63 . V_136 << 32 ) / 1000 / 1000 / 1000 ) ;
V_283 . erf . V_109 . type = ( T_6 ) V_249 ;
V_283 . erf . V_109 . V_137 = V_109 -> V_144 % V_293 ;
V_283 . erf . V_109 . V_137 |= 0x4 ;
V_283 . erf . V_109 . V_138 = 0 ;
switch( V_283 . erf . V_109 . type & 0x7F ) {
case V_86 :
V_274 += 2 ;
if ( V_111 -> V_294 . V_295 != 4 ) {
if( ! ( V_109 -> V_162 < V_109 -> V_161 ) ) {
V_287 = F_86 ( V_282 , V_109 -> V_162 , 0xFFFFFFFF ) ;
V_274 += 4 ;
V_273 += 4 ;
V_286 = TRUE ;
}
}
break;
case V_152 :
if( ! ( V_109 -> V_162 < V_109 -> V_161 ) ) {
V_287 = F_86 ( V_282 , V_109 -> V_162 , 0xFFFFFFFF ) ;
V_274 += 4 ;
V_273 += 4 ;
V_286 = TRUE ;
}
break;
default:
break;
}
V_283 . erf . V_109 . type |= 0x80 ;
V_283 . erf . V_124 [ 0 ] . V_140 = V_288 ;
V_274 += 8 ;
V_284 = F_82 ( V_274 ) ;
if( V_109 -> V_162 < V_109 -> V_161 ) {
V_285 = ( 8 - V_284 ) % 8 ;
V_274 -= V_285 ;
} else{
V_274 += V_284 ;
}
if ( V_274 > V_296 || V_273 > V_296 ) {
* V_45 = V_264 ;
return FALSE ;
}
V_283 . erf . V_109 . V_69 = ( T_15 ) V_274 ;
V_283 . erf . V_109 . V_139 = ( T_15 ) V_273 ;
V_111 = & V_283 ;
}
V_249 = V_111 -> erf . V_109 . type & 0x7FU ;
F_76 ( V_32 , V_111 , V_32 -> V_34 ) ;
if ( V_249 == V_50 ) {
V_32 -> V_51 = F_87 ( V_44 , V_32 , V_111 , V_282 ) ;
} else {
if ( V_32 -> V_49 == V_50 && V_32 -> V_51 ) {
if( V_32 -> V_48 ) {
if ( ! V_32 -> V_33 ) {
V_32 -> V_33 = F_21 ( F_18 ) ;
F_22 ( V_44 , V_52 , 0 , V_32 -> V_35 , V_32 -> V_33 ) ;
}
if ( ! F_24 ( V_44 , V_32 , V_32 -> V_53 , V_32 -> V_33 , V_32 -> V_34 , V_45 ) ) return FALSE ;
V_32 -> V_281 = V_109 -> V_63 . V_135 ;
}
V_32 -> V_48 = FALSE ;
} else if ( V_109 -> V_63 . V_135 > V_32 -> V_280 + 1
&& V_32 -> V_281 != V_109 -> V_63 . V_135 ) {
if ( V_32 -> V_48 ) {
if ( ! V_32 -> V_33 ) {
V_32 -> V_33 = F_21 ( F_18 ) ;
F_23 ( V_44 , V_32 -> V_33 ) ;
}
}
if ( V_32 -> V_33 ) {
if ( ! F_24 ( V_44 , V_32 , ( T_5 ) ( V_109 -> V_63 . V_135 ) << 32 , V_32 -> V_33 , V_32 -> V_34 , V_45 ) ) return FALSE ;
V_32 -> V_281 = V_109 -> V_63 . V_135 ;
}
}
}
if( V_109 -> V_269 || V_109 -> V_297 ) {
if ( V_163 == V_95 ) {
if( V_109 -> V_297 ) {
memcpy ( & V_283 , V_111 , sizeof( union V_117 ) ) ;
if( ! F_78 ( V_44 , V_32 , V_109 , & V_283 , V_45 ) ) return FALSE ;
V_111 = & V_283 ;
}
} else {
if( ! F_78 ( V_44 , V_32 , V_109 , & V_283 , V_45 ) ) return FALSE ;
}
}
V_275 = V_44 -> V_178 + V_111 -> erf . V_109 . V_69 ;
if( ! F_47 ( V_44 , V_95 , V_111 , V_45 ) ) return FALSE ;
if( ! F_51 ( V_44 , V_282 , V_109 -> V_162 - V_285 , V_45 ) ) return FALSE ;
V_44 -> V_178 += V_109 -> V_162 - V_285 ;
if( V_286 ) {
if( ! F_51 ( V_44 , & V_287 , 4 , V_45 ) ) return FALSE ;
V_44 -> V_178 += 4 ;
}
while( V_44 -> V_178 < V_275 ) {
if( ! F_51 ( V_44 , L_4 , 1 , V_45 ) ) return FALSE ;
V_44 -> V_178 ++ ;
}
V_32 -> V_49 = V_111 -> erf . V_109 . type & 0x7FU ;
V_32 -> V_53 = V_111 -> erf . V_109 . V_63 ;
return TRUE ;
}
int F_88 ( int V_163 )
{
if( V_163 == V_289 )
return 0 ;
if ( F_46 ( V_163 ) == - 1 )
return V_292 ;
return 0 ;
}
int F_89 ( V_43 * V_44 , int * V_45 V_54 )
{
T_8 * V_32 ;
T_12 * V_61 ;
T_5 V_5 ;
V_32 = F_83 () ;
V_44 -> V_298 = F_85 ;
V_44 -> V_46 = V_32 ;
V_44 -> V_299 = F_20 ;
F_90 ( V_44 , & V_32 -> V_35 ) ;
if ( V_32 -> V_35 || V_44 -> V_163 != V_95 )
V_32 -> V_48 = TRUE ;
if ( ( V_61 = getenv ( L_5 ) ) != NULL ) {
if ( F_91 ( V_61 , NULL , & V_5 ) ) {
V_32 -> V_5 = V_5 & V_142 ;
}
}
return TRUE ;
}
int F_92 ( T_11 * V_55 )
{
T_22 V_300 ;
T_31 * V_301 ;
int V_18 ;
if ( ! V_55 )
return - 1 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_300 = F_93 ( V_302 ) ;
V_301 = ( T_31 * ) F_94 ( V_300 ) ;
V_301 -> V_303 = V_95 ;
V_301 -> V_304 = 1000000000 ;
V_301 -> V_305 = 65535 ;
F_95 ( V_300 , V_221 , 0x09 ) ;
V_301 -> V_306 = 0 ;
V_301 -> V_307 = NULL ;
F_96 ( V_300 , V_195 , L_6 , 'A' + V_18 ) ;
F_96 ( V_300 , V_197 , L_7 , V_18 , 'A' + V_18 ) ;
F_74 ( V_55 -> V_232 , V_300 ) ;
}
return 0 ;
}
int F_97 ( union V_117 * V_111 , T_5 * V_5 , T_6 * V_16 )
{
T_6 type ;
T_6 V_174 ;
T_5 V_250 ;
int V_18 = 0 ;
T_3 V_127 = FALSE ;
if ( ! V_111 || ! V_5 || ! V_16 )
return - 1 ;
* V_5 = V_29 ;
* V_16 = 0 ;
V_174 = V_111 -> erf . V_109 . type & 0x80 ;
while ( V_174 && ( V_18 < V_171 ) ) {
V_250 = V_111 -> erf . V_124 [ V_18 ] . V_140 ;
type = ( T_6 ) ( V_250 >> 56 ) ;
switch ( type & 0x7f ) {
case V_141 :
if ( ! V_127 )
* V_5 = V_250 & V_142 ;
V_127 = TRUE ;
case V_143 :
if ( * V_16 == 0 )
* V_16 = ( V_250 >> 48 ) & 0xff ;
break;
}
if ( V_127 )
break;
V_174 = type & 0x80 ;
V_18 += 1 ;
}
return 0 ;
}
int F_98 ( T_7 * V_27 , T_11 * V_55 , union V_117 * V_111 )
{
T_5 V_5 ;
T_6 V_16 ;
T_6 V_126 ;
if ( ! V_111 )
return - 1 ;
V_126 = V_111 -> erf . V_109 . V_137 & 0x03 ;
F_97 ( V_111 , & V_5 , & V_16 ) ;
return F_42 ( V_27 , V_55 , V_111 , V_5 , V_16 , V_126 ) ;
}
static struct V_13 * F_99 ( T_7 * V_27 , T_5 V_5 , T_6 V_16 )
{
struct V_13 V_308 ;
if ( ! V_27 )
return NULL ;
V_308 . V_5 = V_5 ;
V_308 . V_16 = V_16 ;
return (struct V_13 * ) F_38 ( V_27 -> V_17 , & V_308 ) ;
}
static void F_100 ( T_22 T_23 , T_1 V_183 , T_5 V_5 , T_6 V_16 , T_6 V_126 , const T_12 * V_21 )
{
char V_309 [ 16 ] ;
char V_310 [ 24 ] ;
V_309 [ 0 ] = '\0' ;
V_310 [ 0 ] = '\0' ;
if ( V_5 == V_29 ) {
V_5 = 0 ;
}
if ( V_5 > 0 ) {
F_101 ( V_310 , sizeof( V_310 ) , L_8 V_311 L_9 , V_5 ) ;
}
if ( V_16 > 0 ) {
F_101 ( V_309 , sizeof( V_309 ) , L_10 , V_16 ) ;
}
if ( V_21 ) {
F_102 ( T_23 , V_183 , L_11 , V_21 , V_310 , V_309 , V_126 ) ;
} else {
F_102 ( T_23 , V_183 , L_12 , 'A' + V_126 , V_310 , V_309 , V_126 ) ;
}
}
static int F_43 ( T_7 * V_27 , struct V_113 * V_109 , union V_117 * V_111 , T_5 V_5 , T_17 * V_108 )
{
T_6 type ;
T_6 V_174 ;
T_5 V_250 ;
T_5 V_312 = 0 ;
T_5 V_313 ;
T_5 V_314 = 0 ;
int V_18 = 0 ;
T_12 * V_12 = NULL ;
if ( ! V_109 || ! V_111 )
return - 1 ;
V_313 = V_5 == V_29 ? V_27 -> V_28 : V_5 ;
V_174 = V_111 -> erf . V_109 . type & 0x80 ;
while ( V_174 && ( V_18 < V_171 ) ) {
V_250 = V_111 -> erf . V_124 [ V_18 ] . V_140 ;
type = ( T_6 ) ( V_250 >> 56 ) ;
switch ( type & 0x7f ) {
case V_141 :
V_313 = V_250 & V_142 ;
break;
case V_11 :
{
V_314 = V_250 & V_315 ;
if ( ! ( F_103 ( V_250 ) ) ) {
struct V_2 * V_316 ;
V_316 = F_37 ( V_27 , V_313 , V_314 ) ;
if ( V_316 ) {
if ( V_316 -> V_180 > V_312 ) {
if ( V_316 -> V_12 && V_316 -> V_12 [ 0 ] != '\0' ) {
V_12 = V_316 -> V_12 ;
}
V_312 = V_316 -> V_180 ;
}
}
}
else {
if ( V_108 && ( V_111 -> erf . V_109 . type & 0x7f ) == V_50 ) {
struct V_2 * V_317 =
(struct V_2 * ) F_9 ( sizeof( struct V_2 ) ) ;
V_317 -> V_5 = V_313 ;
V_317 -> V_6 = V_314 ;
F_56 ( V_108 , V_317 ) ;
}
}
break;
}
}
V_174 = type & 0x80 ;
V_18 += 1 ;
}
if ( V_12 ) {
V_109 -> V_269 = F_40 ( V_12 ) ;
V_109 -> V_131 |= V_318 ;
} else {
V_109 -> V_269 = NULL ;
}
return 0 ;
}
static int F_104 ( T_7 * V_27 , T_11 * V_55 , T_5 V_28 )
{
T_32 V_319 ;
T_4 V_320 ;
T_33 * V_321 = NULL ;
T_33 * V_322 = NULL ;
T_22 V_300 ;
struct V_13 * V_17 = NULL ;
struct V_13 * V_323 = NULL ;
struct V_324 * V_325 = NULL ;
struct V_2 * V_326 = NULL ;
struct V_2 * V_327 = NULL ;
T_12 * V_328 = NULL ;
char V_329 [ 16 ] ;
int V_18 ;
if ( ! V_27 )
return - 1 ;
V_27 -> V_28 = V_28 ;
F_105 ( & V_319 , V_27 -> V_17 ) ;
while ( F_106 ( & V_319 , & V_320 , NULL ) ) {
V_17 = (struct V_13 * ) V_320 ;
if ( V_17 -> V_5 == V_29 ) {
V_323 = F_99 ( V_27 , V_28 , V_17 -> V_16 ) ;
if ( ! V_323 ) {
F_107 ( & V_319 ) ;
V_321 = F_108 ( V_321 , V_17 ) ;
} else {
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_325 = & V_17 -> V_19 [ V_18 ] ;
if ( V_325 -> V_23 >= 0 ) {
V_300 = F_68 ( V_55 -> V_232 , T_22 , V_325 -> V_23 ) ;
F_101 ( V_329 , sizeof( V_329 ) , L_6 , 'A' + V_18 ) ;
V_328 = V_325 -> V_20 ;
V_325 -> V_20 = F_109 ( V_328 ? V_328 : V_329 , L_13 , NULL ) ;
F_4 ( V_328 ) ;
V_328 = V_325 -> V_21 ;
V_325 -> V_21 = F_109 ( V_328 ? V_328 : V_329 , L_13 , NULL ) ;
F_4 ( V_328 ) ;
F_100 ( V_300 , V_195 , V_28 , V_17 -> V_16 , ( T_6 ) V_18 , V_325 -> V_20 ) ;
F_100 ( V_300 , V_197 , V_28 , V_17 -> V_16 , ( T_6 ) V_18 , V_325 -> V_21 ) ;
}
}
}
}
}
if ( V_321 ) {
V_322 = V_321 ;
do {
V_17 = (struct V_13 * ) V_322 -> V_36 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_325 = & V_17 -> V_19 [ V_18 ] ;
if ( V_325 -> V_23 >= 0 ) {
V_300 = F_68 ( V_55 -> V_232 , T_22 , V_325 -> V_23 ) ;
F_100 ( V_300 , V_195 , V_28 , V_17 -> V_16 , ( T_6 ) V_18 , V_325 -> V_20 ) ;
F_100 ( V_300 , V_197 , V_28 , V_17 -> V_16 , ( T_6 ) V_18 , V_325 -> V_21 ) ;
}
}
V_17 -> V_5 = V_28 ;
F_110 ( V_27 -> V_17 , V_17 , V_17 ) ;
} while ( ( V_322 = F_111 ( V_322 ) ) );
F_112 ( V_321 ) ;
V_321 = NULL ;
}
F_105 ( & V_319 , V_27 -> V_3 ) ;
while ( F_106 ( & V_319 , & V_320 , NULL ) ) {
V_326 = (struct V_2 * ) V_320 ;
if ( V_326 -> V_5 == V_29 ) {
V_327 = F_37 ( V_27 , V_28 ,
V_326 -> V_6 ) ;
if ( V_327 && V_327 -> V_180 >= V_326 -> V_180 ) {
F_113 ( & V_319 ) ;
} else {
F_107 ( & V_319 ) ;
V_321 = F_108 ( V_321 , V_326 ) ;
}
}
}
if ( V_321 ) {
V_322 = V_321 ;
do {
V_326 = (struct V_2 * ) V_322 -> V_36 ;
V_326 -> V_5 = V_28 ;
F_110 ( V_27 -> V_3 , V_326 , V_326 ) ;
} while ( ( V_322 = F_111 ( V_322 ) ) );
F_112 ( V_321 ) ;
V_321 = NULL ;
}
return 0 ;
}
int F_42 ( T_7 * V_27 , T_11 * V_55 , union V_117 * V_111 , T_5 V_5 , T_6 V_16 , T_6 V_126 )
{
T_22 V_300 ;
T_31 * V_301 ;
struct V_13 * V_17 = NULL ;
if ( ! V_55 || ! V_111 || ! V_27 || V_126 > 3 )
return - 1 ;
if ( V_5 == V_29 ) {
V_5 = V_27 -> V_28 ;
} else if ( ( V_111 -> erf . V_109 . type & 0x7f ) == V_50 ) {
if ( V_27 -> V_28 == V_29 && V_16 > 0 ) {
F_104 ( V_27 , V_55 , V_5 ) ;
}
}
V_17 = F_99 ( V_27 , V_5 , V_16 ) ;
if ( ! V_17 ) {
V_17 = F_8 ( V_5 , V_16 ) ;
F_110 ( V_27 -> V_17 , V_17 , V_17 ) ;
}
if ( V_17 -> V_19 [ V_126 ] . V_23 >= 0 ) {
return V_17 -> V_19 [ V_126 ] . V_23 ;
}
V_300 = F_93 ( V_302 ) ;
V_301 = ( T_31 * ) F_94 ( V_300 ) ;
V_301 -> V_303 = V_95 ;
V_301 -> V_304 = 1000000000 ;
V_301 -> V_305 = 65535 ;
F_95 ( V_300 , V_221 , 0x09 ) ;
V_301 -> V_306 = 0 ;
V_301 -> V_307 = NULL ;
F_100 ( V_300 , V_195 , V_5 , V_16 , V_126 , NULL ) ;
F_100 ( V_300 , V_197 , V_5 , V_16 , V_126 , NULL ) ;
V_17 -> V_19 [ V_126 ] . V_23 = ( int ) V_55 -> V_232 -> V_161 ;
F_74 ( V_55 -> V_232 , V_300 ) ;
return V_17 -> V_19 [ V_126 ] . V_23 ;
}
static V_4 F_114 ( struct V_40 * V_330 , T_6 * V_41 , V_4 V_331 )
{
T_15 V_332 ;
T_15 V_333 ;
V_4 V_334 ;
if ( ! V_41 || ! V_330 || V_331 < V_335 )
return 0 ;
V_332 = F_115 ( & V_41 [ 0 ] ) ;
V_333 = F_115 ( & V_41 [ 2 ] ) ;
V_334 = F_61 ( V_333 ) ;
if ( V_331 < V_334 ) {
return 0 ;
}
V_330 -> type = V_332 ;
V_330 -> V_188 = V_333 ;
V_330 -> V_42 = & V_41 [ 4 ] ;
return V_334 ;
}
static int F_116 ( T_7 * V_27 , T_11 * V_55 , union V_117 * V_111 V_54 , struct V_336 * V_337 )
{
struct V_40 V_330 = { 0 , 0 , NULL } ;
T_22 V_338 ;
char * V_339 ;
T_12 * V_340 = NULL ;
T_12 * V_341 = NULL ;
T_12 * V_342 = NULL ;
T_12 * V_21 = NULL ;
T_12 * V_343 = NULL ;
T_12 * V_344 = NULL ;
V_4 V_334 ;
if ( ! V_55 || ! V_337 || ! V_55 -> V_230 || ( V_55 -> V_230 -> V_161 == 0 ) )
return - 1 ;
V_338 = F_68 ( V_55 -> V_230 , T_22 , 0 ) ;
while ( ( V_334 = F_114 ( & V_330 , V_337 -> V_41 , V_337 -> V_331 ) ) && ! F_117 ( V_330 . type ) ) {
switch ( V_337 -> V_345 ) {
case V_52 :
{
if ( V_27 -> V_30 > V_337 -> V_180 ) {
return 0 ;
}
switch ( V_330 . type ) {
case V_190 :
{
T_12 * V_346 = NULL ;
if ( F_118 ( V_338 , V_189 , 0 , & V_346 ) == V_347 ) {
F_119 ( V_338 , V_189 , 0 , V_330 . V_42 , V_330 . V_188 ) ;
} else {
F_120 ( V_338 , V_189 , V_330 . V_42 , V_330 . V_188 ) ;
}
break;
}
}
}
case V_231 :
{
if ( V_27 -> V_31 > V_337 -> V_180 ) {
return 0 ;
}
switch ( V_330 . type ) {
case V_348 :
F_4 ( V_342 ) ;
V_342 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
break;
case V_192 :
F_4 ( V_343 ) ;
V_343 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
break;
case V_198 :
F_4 ( V_21 ) ;
V_21 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
break;
case V_194 :
F_122 ( V_338 , V_193 , V_330 . V_42 , V_330 . V_188 ) ;
break;
case V_186 :
F_4 ( V_340 ) ;
V_340 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
break;
case V_349 :
F_4 ( V_341 ) ;
V_341 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
break;
case V_215 :
F_4 ( V_337 -> V_17 -> V_350 ) ;
V_337 -> V_17 -> V_350 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
break;
default:
break;
}
}
break;
}
V_337 -> V_41 += V_334 ;
V_337 -> V_331 -= V_334 ;
}
if ( V_340 ) {
V_339 = F_123 ( L_14 , V_340 , V_341 , NULL ) ;
F_122 ( V_338 , V_185 , V_339 , strlen ( V_339 ) ) ;
F_4 ( V_339 ) ;
F_4 ( V_340 ) ;
F_4 ( V_341 ) ;
V_340 = NULL ;
V_341 = NULL ;
}
if ( V_342 || V_343 ) {
if ( V_342 && V_343 ) {
V_344 = F_109 ( V_342 , L_15 , V_343 , NULL ) ;
} else if ( V_343 ) {
V_344 = V_343 ;
V_343 = NULL ;
} else {
V_344 = V_342 ;
V_342 = NULL ;
}
}
if ( V_337 -> V_345 == V_231 && V_21 ) {
if ( V_344 ) {
F_102 ( V_338 , V_191 , L_16 , V_21 , V_344 ) ;
} else {
F_122 ( V_338 , V_191 , V_21 , strlen ( V_21 ) ) ;
}
} else if ( V_344 ) {
F_122 ( V_338 , V_191 , V_344 , strlen ( V_344 ) ) ;
}
F_4 ( V_344 ) ;
F_4 ( V_342 ) ;
F_4 ( V_21 ) ;
F_4 ( V_343 ) ;
if ( V_337 -> V_345 == V_52 ) {
V_27 -> V_30 = V_337 -> V_180 ;
} else {
V_27 -> V_31 = V_337 -> V_180 ;
}
return 1 ;
}
static int F_124 ( T_7 * V_27 V_54 , T_11 * V_55 , union V_117 * V_111 V_54 , struct V_336 * V_337 )
{
struct V_40 V_330 = { 0 , 0 , NULL } ;
V_4 V_334 ;
if ( ! V_55 || ! V_337 )
return - 1 ;
if ( V_337 -> V_17 -> V_351 > V_337 -> V_180 ) {
return 0 ;
}
while ( ( V_334 = F_114 ( & V_330 , V_337 -> V_41 , V_337 -> V_331 ) ) && ! F_117 ( V_330 . type ) ) {
switch ( V_330 . type ) {
case V_217 :
if ( V_330 . V_188 >= 4 ) {
V_337 -> V_17 -> V_25 = ( V_352 ) F_125 ( V_330 . V_42 ) ;
}
break;
case V_353 :
if ( V_330 . V_188 >= 4 ) {
V_337 -> V_17 -> V_26 = F_125 ( V_330 . V_42 ) ;
}
break;
case V_215 :
F_4 ( V_337 -> V_17 -> V_22 ) ;
V_337 -> V_17 -> V_22 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
break;
}
V_337 -> V_41 += V_334 ;
V_337 -> V_331 -= V_334 ;
}
V_337 -> V_17 -> V_351 = V_337 -> V_180 ;
return 1 ;
}
static int F_126 ( T_7 * V_27 , T_11 * V_55 , union V_117 * V_111 , struct V_336 * V_337 )
{
struct V_40 V_330 = { 0 , 0 , NULL } ;
V_4 V_334 ;
int V_354 = - 1 ;
T_22 V_300 = NULL ;
T_31 * V_301 = NULL ;
T_27 V_355 ;
V_4 V_126 = 0 ;
struct V_324 * V_325 = NULL ;
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
if ( ! V_55 || ! V_337 || ! V_111 || ! V_337 -> V_17 )
return - 1 ;
V_126 = V_337 -> V_356 - 1 ;
if ( V_126 < 4 ) {
V_325 = & V_337 -> V_17 -> V_19 [ V_126 ] ;
V_354 = V_325 -> V_23 ;
if ( V_354 == - 1 ) {
T_6 * V_357 = V_337 -> V_41 ;
V_4 V_358 = V_337 -> V_331 ;
while ( ( V_334 = F_114 ( & V_330 , V_357 , V_358 ) ) && ! F_117 ( V_330 . type ) ) {
if ( V_330 . type == V_359 ) {
if ( V_330 . V_188 >= 4 && F_125 ( V_330 . V_42 ) == 2 ) {
V_325 -> V_23 = - 2 ;
V_354 = - 2 ;
}
} else if ( V_330 . type == V_360 ) {
if ( V_330 . V_188 >= 4 ) {
V_325 -> V_24 = ( V_361 ) F_125 ( V_330 . V_42 ) ;
}
}
V_357 += V_334 ;
V_358 -= V_334 ;
}
if ( V_354 == - 1 ) {
V_354 = F_42 ( V_27 , V_55 , V_111 , V_337 -> V_17 -> V_5 , V_337 -> V_17 -> V_16 , ( T_6 ) V_126 ) ;
}
}
if ( V_354 >= 0 ) {
V_300 = F_68 ( V_55 -> V_232 , T_22 , V_354 ) ;
V_301 = ( T_31 * ) F_94 ( V_300 ) ;
} else if ( V_354 == - 2 ) {
return 0 ;
} else {
return - 1 ;
}
}
if ( ! V_300 )
return 0 ;
if ( V_337 -> V_17 -> V_362 > V_337 -> V_180 && V_337 -> V_17 -> V_363 & ( 1 << V_126 ) )
return 0 ;
while ( ( V_334 = F_114 ( & V_330 , V_337 -> V_41 , V_337 -> V_331 ) ) && ! F_117 ( V_330 . type ) ) {
switch ( V_330 . type ) {
case V_196 :
if ( ! V_325 -> V_20 ) {
V_325 -> V_20 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
F_100 ( V_300 , V_195 , V_337 -> V_17 -> V_5 , V_337 -> V_17 -> V_16 , ( T_6 ) V_126 , V_325 -> V_20 ) ;
if ( ! V_325 -> V_21 ) {
F_100 ( V_300 , V_197 , V_337 -> V_17 -> V_5 , V_337 -> V_17 -> V_16 , ( T_6 ) V_126 , V_325 -> V_20 ) ;
}
}
break;
case V_198 :
if ( ! V_325 -> V_21 ) {
V_325 -> V_21 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
F_100 ( V_300 , V_197 , V_337 -> V_17 -> V_5 , V_337 -> V_17 -> V_16 , ( T_6 ) V_126 , V_325 -> V_21 ) ;
if ( ! V_325 -> V_20 ) {
F_100 ( V_300 , V_195 , V_337 -> V_17 -> V_5 , V_337 -> V_17 -> V_16 , ( T_6 ) V_126 , V_325 -> V_21 ) ;
}
}
break;
case V_204 :
if ( V_330 . V_188 >= 8 )
F_127 ( V_300 , V_203 , F_41 ( V_330 . V_42 ) ) ;
break;
case V_364 :
break;
case V_217 :
if ( V_330 . V_188 >= 4 ) {
F_95 ( V_300 , V_216 , ( T_6 ) F_125 ( V_330 . V_42 ) ) ;
V_325 -> V_365 . V_295 = 1 ;
}
break;
case V_353 :
if ( V_330 . V_188 >= 4 ) {
V_301 -> V_305 = F_125 ( V_330 . V_42 ) ;
V_325 -> V_365 . V_366 = 1 ;
}
break;
case V_190 :
F_120 ( V_300 , V_189 , V_330 . V_42 , V_330 . V_188 ) ;
break;
case V_215 :
V_355 . V_214 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
F_128 ( V_300 , V_211 , & V_355 , sizeof V_355 ) ;
F_4 ( V_355 . V_214 ) ;
V_325 -> V_365 . V_212 = 1 ;
break;
default:
break;
}
V_337 -> V_41 += V_334 ;
V_337 -> V_331 -= V_334 ;
}
if ( ! V_325 -> V_365 . V_212 ) {
if ( V_337 -> V_17 -> V_22 ) {
V_355 . V_214 = V_337 -> V_17 -> V_22 ;
F_128 ( V_300 , V_211 , & V_355 , sizeof V_355 ) ;
} else if ( V_337 -> V_17 -> V_350 ) {
V_355 . V_214 = V_337 -> V_17 -> V_350 ;
F_128 ( V_300 , V_211 , & V_355 , sizeof V_355 ) ;
}
}
if ( V_337 -> V_17 -> V_25 != - 1 && ! V_325 -> V_365 . V_295 ) {
F_95 ( V_300 , V_216 , ( T_6 ) V_337 -> V_17 -> V_25 ) ;
V_325 -> V_365 . V_295 = 1 ;
}
if ( V_337 -> V_17 -> V_26 != ( V_4 ) - 1 && ! V_325 -> V_365 . V_366 ) {
V_301 -> V_305 = F_125 ( V_330 . V_42 ) ;
V_325 -> V_365 . V_366 = 1 ;
}
V_337 -> V_363 |= 1 << V_126 ;
return 1 ;
}
static int F_129 ( T_7 * V_27 V_54 , T_11 * V_55 , union V_117 * V_111 , struct V_336 * V_337 )
{
struct V_40 V_330 = { 0 , 0 , NULL } ;
V_4 V_334 ;
int V_354 = - 1 ;
T_22 V_300 = NULL ;
T_31 * V_301 = NULL ;
T_27 V_355 ;
V_4 V_126 = 0 ;
V_361 V_24 = - 1 ;
T_6 * V_357 ;
V_4 V_358 ;
struct V_324 * V_325 = NULL ;
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
if ( ! V_55 || ! V_111 || ! V_337 || ! V_337 -> V_17 )
return - 1 ;
V_357 = V_337 -> V_41 ;
V_358 = V_337 -> V_331 ;
if ( V_337 -> V_356 > 0 && V_337 -> V_356 != 0x7fff ) {
V_24 = V_337 -> V_356 - 1 ;
} else {
while ( ( V_334 = F_114 ( & V_330 , V_357 , V_358 ) ) && ! F_117 ( V_330 . type ) ) {
if ( V_330 . type == V_360 ) {
if ( V_330 . V_188 >= 4 ) {
V_24 = ( V_361 ) F_125 ( V_330 . V_42 ) ;
}
}
V_357 += V_334 ;
V_358 -= V_334 ;
}
}
for ( V_126 = 0 ; V_126 < 4 ; V_126 ++ ) {
V_357 = V_337 -> V_41 ;
V_358 = V_337 -> V_331 ;
V_325 = & V_337 -> V_17 -> V_19 [ V_126 ] ;
if ( V_337 -> V_17 -> V_363 & ( 1 << V_126 )
|| ! ( V_337 -> V_363 & ( 1 << V_126 ) ) ) {
continue;
}
if ( V_325 -> V_24 != - 1
&& V_325 -> V_24 != V_24 ) {
continue;
}
V_354 = V_325 -> V_23 ;
if ( V_354 >= 0 ) {
V_300 = F_68 ( V_55 -> V_232 , T_22 , V_354 ) ;
V_301 = ( T_31 * ) F_94 ( V_300 ) ;
}
if ( ! V_300 ) {
continue;
}
while ( ( V_334 = F_114 ( & V_330 , V_357 , V_358 ) ) && ! F_117 ( V_330 . type ) ) {
switch ( V_330 . type ) {
case V_217 :
if ( V_330 . V_188 >= 4 ) {
V_352 V_295 = ( V_352 ) F_125 ( V_330 . V_42 ) ;
T_6 V_367 = 0 ;
switch ( F_130 ( V_300 , V_216 , & V_367 ) ) {
case V_347 :
if ( V_295 > V_367 || ! V_325 -> V_365 . V_295 ) {
F_131 ( V_300 , V_216 , ( T_6 ) F_125 ( V_330 . V_42 ) ) ;
V_325 -> V_365 . V_295 = 1 ;
}
break;
case V_368 :
F_95 ( V_300 , V_216 , ( T_6 ) F_125 ( V_330 . V_42 ) ) ;
V_325 -> V_365 . V_295 = 1 ;
break;
default:
break;
}
}
break;
case V_353 :
if ( V_330 . V_188 >= 4 ) {
V_4 V_366 = F_125 ( V_330 . V_42 ) ;
if ( V_366 > V_301 -> V_305 || ! V_325 -> V_365 . V_366 ) {
V_301 -> V_305 = F_125 ( V_330 . V_42 ) ;
V_325 -> V_365 . V_366 = 1 ;
}
}
break;
case V_215 :
if ( ! V_325 -> V_365 . V_212 ) {
V_355 . V_214 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
F_128 ( V_300 , V_211 , & V_355 , sizeof V_355 ) ;
F_4 ( V_355 . V_214 ) ;
V_325 -> V_365 . V_212 = 1 ;
}
break;
default:
break;
}
V_357 += V_334 ;
V_358 -= V_334 ;
}
}
V_337 -> V_41 = V_357 ;
V_337 -> V_331 = V_358 ;
return 1 ;
}
static int F_132 ( T_7 * V_27 , T_11 * V_55 , union V_117 * V_111 , struct V_336 * V_337 , T_17 * V_108 ) {
struct V_40 V_330 = { 0 , 0 , NULL } ;
V_4 V_334 ;
T_12 * V_369 = NULL ;
T_1 V_18 = 0 ;
if ( ! V_55 || ! V_337 || ! V_111 )
return - 1 ;
if ( ! V_108 || V_108 -> V_161 == 0 )
return 0 ;
while ( ( V_334 = F_114 ( & V_330 , V_337 -> V_41 , V_337 -> V_331 ) ) && ! F_117 ( V_330 . type ) ) {
switch( V_330 . type ) {
case V_190 :
if( ! V_369 ) {
V_369 = F_121 ( ( T_12 * ) V_330 . V_42 , V_330 . V_188 ) ;
}
break;
default:
break;
}
V_337 -> V_41 += V_334 ;
V_337 -> V_331 -= V_334 ;
}
if( V_369 ) {
for( V_18 = 0 ; V_18 < V_108 -> V_161 ; V_18 ++ ) {
struct V_2 * V_116 ;
struct V_2 * V_316 ;
V_116 = (struct V_2 * ) F_60 ( V_108 , V_18 ) ;
V_316 = (struct V_2 * ) F_38 ( V_27 -> V_3 , V_116 ) ;
if( V_316 ) {
if( V_316 -> V_180 < V_337 -> V_180 ) {
V_316 -> V_180 = V_337 -> V_180 ;
F_4 ( V_316 -> V_12 ) ;
V_316 -> V_12 = F_40 ( V_369 ) ;
}
}
else {
struct V_2 * V_370 ;
V_370 = (struct V_2 * ) F_9 ( sizeof( struct V_2 ) ) ;
V_370 -> V_6 = V_116 -> V_6 ;
V_370 -> V_5 = V_116 -> V_5 ;
V_370 -> V_180 = V_337 -> V_180 ;
V_370 -> V_12 = F_40 ( V_369 ) ;
F_110 ( V_27 -> V_3 , V_370 , V_370 ) ;
}
}
}
F_4 ( V_369 ) ;
return 1 ;
}
static int F_36 ( T_7 * V_27 , T_11 * V_55 , union V_117 * V_111 , V_4 V_68 , T_17 * V_108 )
{
struct V_336 V_337 ;
struct V_336 * V_371 = NULL ;
T_5 V_5 ;
T_6 V_16 ;
T_33 * V_372 = NULL ;
T_33 * V_322 = NULL ;
struct V_40 V_330 = { 0 , 0 , NULL } ;
V_4 V_334 ;
if ( ! V_27 || ! V_55 || ! V_111 )
return - 1 ;
memset ( & V_337 , 0 , sizeof( struct V_336 ) ) ;
F_97 ( V_111 , & V_5 , & V_16 ) ;
if ( V_5 == 0 ) {
V_5 = V_27 -> V_28 ;
}
V_337 . V_17 = F_99 ( V_27 , V_5 , V_16 ) ;
if ( ! V_337 . V_17 ) {
V_337 . V_17 = F_8 ( V_5 , V_16 ) ;
F_110 ( V_27 -> V_17 , V_337 . V_17 , V_337 . V_17 ) ;
}
V_337 . V_41 = V_55 -> V_110 -> V_36 ;
V_337 . V_331 = V_68 ;
while ( ( V_334 = F_114 ( & V_330 , V_337 . V_41 , V_337 . V_331 ) ) ) {
if ( ! F_117 ( V_330 . type ) ) {
if( V_337 . V_180 == 0U
&& V_330 . type == V_277
) {
memcpy ( & V_337 . V_180 , V_330 . V_42 , sizeof( V_337 . V_180 ) ) ;
if ( ( V_337 . V_17 -> V_363 & 0x03 )
&& V_337 . V_180 < V_27 -> V_31 && V_337 . V_180 < V_27 -> V_30
&& ( ! V_108 || ! V_108 -> V_161 ) ) {
return 0 ;
}
}
V_337 . V_41 += V_334 ;
V_337 . V_331 -= V_334 ;
continue;
}
if ( V_330 . type != V_337 . V_345 ) {
if ( ( V_330 . type == V_373 && V_337 . V_345 == V_233 ) ||
( V_330 . type == V_233 && V_337 . V_345 == V_373 ) ) {
} else {
V_337 . V_374 = V_337 . V_345 ;
V_337 . V_375 = V_337 . V_356 ;
}
}
V_337 . V_345 = V_330 . type ;
if ( V_330 . V_188 >= 4 ) {
V_337 . V_356 = F_115 ( V_330 . V_42 ) ;
} else {
V_337 . V_356 = 0 ;
}
V_337 . V_41 += V_334 ;
V_337 . V_331 -= V_334 ;
if ( ( V_334 = F_114 ( & V_330 , V_337 . V_41 , V_337 . V_331 ) ) ) {
if ( V_330 . type == V_376 && V_330 . V_188 >= 4 ) {
V_337 . V_374 = F_115 ( V_330 . V_42 ) ;
V_337 . V_375 = F_115 ( & V_330 . V_42 [ 2 ] ) ;
}
}
if ( F_117 ( V_330 . type ) ) {
continue;
}
if ( V_337 . V_356 & 0x8000 ) {
if( V_337 . V_345 & ( V_268 ) ) {
F_132 ( V_27 , V_55 , V_111 , & V_337 , V_108 ) ;
}
continue;
}
switch ( V_337 . V_345 ) {
case V_52 :
case V_231 :
F_116 ( V_27 , V_55 , V_111 , & V_337 ) ;
break;
case V_377 :
F_124 ( V_27 , V_55 , V_111 , & V_337 ) ;
break;
case V_233 :
F_126 ( V_27 , V_55 , V_111 , & V_337 ) ;
break;
case V_373 :
V_372 = F_133 ( V_372 , F_134 ( & V_337 , sizeof( struct V_336 ) ) ) ;
break;
case V_378 :
case V_379 :
default:
break;
}
}
if ( V_372 ) {
V_322 = V_372 ;
do {
V_371 = (struct V_336 * ) V_322 -> V_36 ;
switch ( V_371 -> V_345 ) {
case V_373 :
F_129 ( V_27 , V_55 , V_111 , V_371 ) ;
break;
}
} while ( ( V_322 = F_111 ( V_322 ) ) );
F_135 ( V_372 , F_25 , NULL ) ;
F_112 ( V_372 ) ;
}
if ( V_337 . V_363 ) {
V_337 . V_17 -> V_363 |= V_337 . V_363 ;
V_337 . V_17 -> V_362 = V_337 . V_180 ;
}
return 0 ;
}
static T_3 F_90 ( V_43 * V_44 , T_12 * * V_35 ) {
T_22 V_380 ;
T_3 V_47 ;
V_380 = NULL ;
if( V_44 -> V_230 && ( V_44 -> V_230 -> V_161 > 0 ) ) {
V_380 = F_68 ( V_44 -> V_230 , T_22 , 0 ) ;
}
if( V_380 != NULL ) {
V_47 = F_118 ( V_380 , V_189 , 0 , V_35 ) ;
if( V_47 ) {
return FALSE ;
}
}
return TRUE ;
}
static T_3 F_87 ( V_43 * V_44 V_54 , T_8 * V_32 , const union V_117 * V_111 , const T_6 * V_282 ) {
struct V_336 V_337 ;
struct V_40 V_330 = { 0 , 0 , NULL } ;
V_4 V_334 ;
T_3 V_381 = FALSE ;
T_3 V_382 = FALSE ;
T_12 * V_369 = NULL ;
memset ( & V_337 , 0 , sizeof( struct V_336 ) ) ;
V_337 . V_331 = V_111 -> erf . V_109 . V_139 ;
memcpy ( & ( V_337 . V_41 ) , & V_282 , sizeof( V_282 ) ) ;
while( ( V_334 = F_114 ( & V_330 , V_337 . V_41 , V_337 . V_331 ) ) ) {
if ( F_117 ( V_330 . type ) ) {
V_337 . V_345 = V_330 . type ;
if ( V_330 . V_188 >= 4 ) {
V_337 . V_356 = F_115 ( V_330 . V_42 ) ;
} else {
V_337 . V_356 = 0 ;
}
if ( ! ( V_337 . V_356 & 0x8000 ) ) {
V_382 = TRUE ;
if( V_330 . type == V_52 ) {
V_381 = TRUE ;
}
}
} else {
if ( V_337 . V_345 == V_52 && ! ( V_337 . V_356 & 0x8000 ) ) {
if ( V_330 . type == V_190 ) {
if( ! V_369 ) {
V_369 = F_121 ( ( char * ) V_330 . V_42 , V_330 . V_188 ) ;
}
break;
}
}
}
V_337 . V_41 += V_334 ;
V_337 . V_331 -= V_334 ;
}
if( V_381 && ( V_369 || V_32 -> V_35 ) ) {
if( F_136 ( V_369 , V_32 -> V_35 )
&& ! ( V_32 -> V_35 == NULL && V_369 && V_369 [ 0 ] == '\0' ) ) {
V_32 -> V_48 = TRUE ;
F_4 ( V_369 ) ;
return TRUE ;
} else {
V_32 -> V_48 = FALSE ;
}
}
F_4 ( V_369 ) ;
return V_382 ;
}
static void V_101 ( T_11 * V_55 )
{
T_7 * V_27 = ( T_7 * ) V_55 -> V_46 ;
F_13 ( V_27 ) ;
V_55 -> V_46 = NULL ;
}
