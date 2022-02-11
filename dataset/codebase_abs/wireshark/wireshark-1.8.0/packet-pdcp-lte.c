static T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
const T_3 * V_3 = ( const T_3 * ) V_1 ;
const T_3 * V_4 = ( const T_3 * ) V_2 ;
return ( memcmp ( V_3 , V_4 , sizeof( T_3 ) ) == 0 ) ;
}
static T_4 F_2 ( T_2 V_1 )
{
const T_3 * V_3 = ( const T_3 * ) V_1 ;
return V_3 -> V_5 + V_3 -> V_6 + V_3 -> V_7 + V_3 -> V_8 ;
}
static T_1 F_3 ( T_2 V_1 , T_2 V_2 )
{
const T_5 * V_3 = ( const T_5 * ) V_1 ;
const T_5 * V_4 = ( const T_5 * ) V_2 ;
return ( memcmp ( V_3 , V_4 , sizeof( T_5 ) ) == 0 ) ;
}
static T_4 F_4 ( T_2 V_1 )
{
const T_5 * V_3 = ( const T_5 * ) V_1 ;
return V_3 -> V_9 + ( V_3 -> V_7 << 13 ) +
( V_3 -> V_6 << 5 ) +
( V_3 -> V_10 << 18 ) +
( V_3 -> V_8 << 9 ) ;
}
static T_6 F_5 ( T_7 V_10 , T_8 V_9 ,
T_9 * V_11 ,
T_10 V_12 )
{
static T_5 V_13 ;
T_5 * V_14 ;
if ( V_12 ) {
V_14 = F_6 ( T_5 ) ;
}
else {
memset ( & V_13 , 0 , sizeof( T_5 ) ) ;
V_14 = & V_13 ;
}
V_14 -> V_9 = V_9 ;
V_14 -> V_10 = V_10 ;
V_14 -> V_6 = ( V_15 ) V_11 -> V_6 ;
V_14 -> V_7 = V_11 -> V_7 ;
V_14 -> V_8 = V_11 -> V_8 ;
return V_14 ;
}
static void F_7 ( T_11 * V_16 ,
T_9 * V_11 ,
T_7 V_17 ,
T_12 * V_18 , T_13 * V_19 , T_14 * V_20 )
{
T_13 * V_21 ;
T_15 * V_22 ;
T_15 * V_23 ;
T_15 * V_24 ;
V_22 = F_8 ( V_19 ,
V_25 ,
V_20 , 0 , 0 ,
L_1 , L_2 ) ;
V_21 = F_9 ( V_22 ,
V_26 ) ;
F_10 ( V_22 ) ;
if ( V_16 -> V_27 != 0 ) {
F_11 ( V_21 , V_28 ,
V_20 , 0 , 0 , V_16 -> V_27 ) ;
}
V_23 = F_11 ( V_21 , V_29 ,
V_20 , 0 , 0 , V_16 -> V_30 ) ;
F_10 ( V_23 ) ;
switch ( V_11 -> V_31 ) {
case V_32 :
case V_33 :
case V_34 :
break;
default:
F_12 () ;
break;
}
switch ( V_16 -> V_35 ) {
case V_36 :
F_13 ( V_23 ) ;
V_24 = F_14 ( V_21 , V_37 ,
V_20 , 0 , 0 , TRUE ) ;
F_10 ( V_24 ) ;
F_15 ( V_22 , L_3 ) ;
if ( V_16 -> V_38 != 0 ) {
F_11 ( V_21 , V_39 ,
V_20 , 0 , 0 , V_16 -> V_38 ) ;
}
break;
case V_40 :
V_24 = F_14 ( V_21 , V_37 ,
V_20 , 0 , 0 , FALSE ) ;
F_10 ( V_24 ) ;
V_24 = F_14 ( V_21 , V_41 ,
V_20 , 0 , 0 , TRUE ) ;
F_10 ( V_24 ) ;
if ( V_16 -> V_42 != V_16 -> V_43 ) {
F_16 ( V_18 , V_24 , V_44 , V_45 ,
L_4 ,
V_16 -> V_43 , V_16 -> V_42 ,
F_17 ( V_11 -> V_8 , V_46 , L_5 ) ,
V_11 -> V_47 ) ;
F_15 ( V_22 , L_6 ,
V_16 -> V_43 , V_16 -> V_42 ) ;
}
else {
F_16 ( V_18 , V_24 , V_44 , V_45 ,
L_7 ,
V_16 -> V_43 ,
F_17 ( V_11 -> V_8 , V_46 , L_5 ) ,
V_11 -> V_47 ) ;
F_15 ( V_22 , L_8 ,
V_16 -> V_43 ) ;
}
break;
case V_48 :
V_24 = F_14 ( V_21 , V_37 ,
V_20 , 0 , 0 , FALSE ) ;
F_10 ( V_24 ) ;
V_24 = F_14 ( V_21 , V_49 ,
V_20 , 0 , 0 , TRUE ) ;
F_10 ( V_24 ) ;
F_16 ( V_18 , V_24 , V_44 , V_45 ,
L_9 ,
V_16 -> V_43 ,
F_17 ( V_11 -> V_8 , V_46 , L_5 ) ,
V_11 -> V_47 ) ;
F_15 ( V_22 , L_10 ,
V_16 -> V_43 ) ;
break;
default:
F_16 ( V_18 , V_23 , V_44 , V_45 ,
L_11 ,
F_17 ( V_11 -> V_8 , V_46 , L_5 ) ,
V_11 -> V_47 , V_17 , V_16 -> V_30 ) ;
break;
}
}
static void F_18 ( T_12 * V_18 , T_14 * V_20 ,
T_9 * V_11 ,
T_7 V_17 ,
T_13 * V_19 )
{
T_3 V_50 ;
T_3 * V_51 ;
T_16 * V_52 ;
T_11 * V_53 = NULL ;
T_10 V_54 = FALSE ;
T_7 V_55 = 0 ;
T_7 V_56 = 0 ;
if ( V_18 -> V_57 -> V_58 . V_59 ) {
V_53 =
( T_11 * ) F_19 ( V_60 ,
F_5 ( V_17 ,
V_18 -> V_57 -> V_61 ,
V_11 , FALSE ) ) ;
if ( V_53 != NULL ) {
F_7 ( V_53 , V_11 ,
V_17 ,
V_18 , V_19 , V_20 ) ;
return;
}
else {
return;
}
}
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_5 = V_11 -> V_47 ;
V_50 . V_6 = V_11 -> V_6 ;
V_50 . V_7 = V_11 -> V_7 ;
V_50 . V_8 = V_11 -> V_8 ;
V_52 = ( T_16 * ) F_19 ( V_62 , & V_50 ) ;
if ( V_52 == NULL ) {
V_54 = TRUE ;
V_52 = F_6 ( T_16 ) ;
V_51 = F_20 ( & V_50 , sizeof( T_3 ) ) ;
F_21 ( V_62 , V_51 , V_52 ) ;
}
V_53 = F_22 ( T_11 ) ;
V_53 -> V_38 = 0 ;
switch ( V_11 -> V_31 ) {
case V_32 :
V_56 = 32 ;
break;
case V_33 :
V_56 = 128 ;
break;
case V_34 :
V_56 = 4096 ;
break;
default:
F_12 () ;
break;
}
if ( ! V_54 ) {
V_55 = ( V_52 -> V_63 + 1 ) % V_56 ;
}
else {
V_55 = V_17 ;
}
V_53 -> V_64 = ( V_17 == V_55 ) ;
if ( ! V_53 -> V_64 ) {
if ( ( ( V_56 + V_55 - V_17 ) % V_56 ) > 15 ) {
V_53 -> V_35 = V_40 ;
V_53 -> V_43 = V_55 ;
V_53 -> V_42 = ( V_56 + V_17 - 1 ) % V_56 ;
V_53 -> V_30 = V_55 ;
V_53 -> V_27 = V_52 -> V_27 ;
V_52 -> V_27 = V_18 -> V_57 -> V_61 ;
V_52 -> V_63 = V_17 ;
}
else {
V_53 -> V_35 = V_48 ;
V_53 -> V_43 = V_17 ;
V_53 -> V_30 = V_55 ;
V_53 -> V_27 = V_52 -> V_27 ;
}
}
else {
V_53 -> V_35 = V_36 ;
V_53 -> V_30 = V_55 ;
V_53 -> V_27 = V_52 -> V_27 ;
V_52 -> V_27 = V_18 -> V_57 -> V_61 ;
V_52 -> V_63 = V_17 ;
if ( V_53 -> V_27 != 0 ) {
T_11 * V_65 ;
V_65 = ( T_11 * ) F_19 ( V_60 ,
F_5 ( ( V_17 + 4095 ) % 4096 ,
V_53 -> V_27 ,
V_11 ,
FALSE ) ) ;
if ( V_65 != NULL ) {
V_65 -> V_38 = V_18 -> V_57 -> V_61 ;
}
}
}
F_21 ( V_60 ,
F_5 ( V_17 , V_18 -> V_57 -> V_61 ,
V_11 , TRUE ) ,
V_53 ) ;
F_7 ( V_53 , V_11 , V_17 ,
V_18 , V_19 , V_20 ) ;
}
static void F_23 ( T_15 * V_66 ,
T_12 * V_18 , const char * V_67 , ... )
{
#define F_24 256
static char V_68 [ F_24 ] ;
T_17 V_69 ;
va_start ( V_69 , V_67 ) ;
F_25 ( V_68 , F_24 , V_67 , V_69 ) ;
va_end ( V_69 ) ;
F_26 ( V_18 -> V_70 , V_71 , V_68 ) ;
F_15 ( V_66 , L_12 , V_68 ) ;
}
static void F_27 ( T_12 * V_18 , T_14 * V_20 , T_13 * V_19 ,
T_9 * V_72 )
{
T_15 * V_24 ;
T_13 * V_73 ;
T_15 * V_74 = F_28 ( V_19 ,
V_75 ,
V_20 , 0 , 0 , V_76 | V_77 ) ;
V_73 = F_9 ( V_74 , V_78 ) ;
V_24 = F_11 ( V_73 , V_79 , V_20 , 0 , 0 ,
V_72 -> V_8 ) ;
F_10 ( V_24 ) ;
V_24 = F_11 ( V_73 , V_80 , V_20 , 0 , 0 ,
V_72 -> V_6 ) ;
F_10 ( V_24 ) ;
if ( V_72 -> V_47 != 0 ) {
V_24 = F_11 ( V_73 , V_81 , V_20 , 0 , 0 ,
V_72 -> V_47 ) ;
F_10 ( V_24 ) ;
}
V_24 = F_11 ( V_73 , V_82 , V_20 , 0 , 0 ,
V_72 -> V_83 ) ;
F_10 ( V_24 ) ;
if ( V_72 -> V_7 != 0 ) {
V_24 = F_11 ( V_73 , V_84 , V_20 , 0 , 0 ,
V_72 -> V_7 ) ;
F_10 ( V_24 ) ;
}
if ( V_72 -> V_6 == V_85 ) {
V_24 = F_11 ( V_73 , V_86 , V_20 , 0 , 0 ,
V_72 -> V_87 ) ;
F_10 ( V_24 ) ;
if ( ! V_72 -> V_87 ) {
V_24 = F_11 ( V_73 , V_88 , V_20 , 0 , 0 ,
V_72 -> V_31 ) ;
F_10 ( V_24 ) ;
}
}
V_24 = F_14 ( V_73 , V_89 , V_20 , 0 , 0 ,
V_72 -> V_90 ) ;
F_10 ( V_24 ) ;
if ( V_72 -> V_90 ) {
V_24 = F_11 ( V_73 , V_91 , V_20 , 0 , 0 ,
V_72 -> V_92 ) ;
F_10 ( V_24 ) ;
V_24 = F_11 ( V_73 , V_93 , V_20 , 0 , 0 ,
V_72 -> V_94 ) ;
F_10 ( V_24 ) ;
V_24 = F_11 ( V_73 , V_95 , V_20 , 0 , 0 ,
V_72 -> V_96 ) ;
F_10 ( V_24 ) ;
V_24 = F_11 ( V_73 , V_97 , V_20 , 0 , 0 ,
V_72 -> V_98 ) ;
F_10 ( V_24 ) ;
V_24 = F_11 ( V_73 , V_99 , V_20 , 0 , 0 ,
V_72 -> V_100 ) ;
F_10 ( V_24 ) ;
V_24 = F_11 ( V_73 , V_101 , V_20 , 0 , 0 ,
V_72 -> V_102 ) ;
F_10 ( V_24 ) ;
}
F_15 ( V_74 , L_13 ,
F_17 ( V_72 -> V_8 , V_46 , L_5 ) ,
F_17 ( V_72 -> V_6 , V_103 , L_5 ) ) ;
if ( V_72 -> V_90 ) {
const char * V_92 = F_17 ( V_72 -> V_92 , V_104 , L_14 ) ;
F_15 ( V_74 , L_15 ,
V_92 [ 0 ] ,
F_17 ( V_72 -> V_98 , V_105 , L_5 ) ) ;
}
F_15 ( V_74 , L_16 ) ;
F_10 ( V_74 ) ;
F_29 ( V_18 -> V_70 , V_71 , L_17 ,
F_17 ( V_72 -> V_6 , V_103 , L_5 ) ) ;
}
static T_18 F_30 ( struct T_9 * V_72 )
{
T_18 V_106 = 0 ;
switch ( V_72 -> V_83 )
{
case V_107 :
if ( V_72 -> V_8 == V_108 ) {
V_106 = F_31 ( L_18 ) ;
}
else {
V_106 = F_31 ( L_19 ) ;
}
break;
case V_109 :
V_106 = F_31 ( L_20 ) ;
break;
case V_110 :
switch ( V_72 -> V_111 ) {
case V_112 :
V_106 = F_31 ( L_21 ) ;
break;
case V_113 :
V_106 = F_31 ( L_22 ) ;
break;
}
break;
case V_114 :
if ( V_72 -> V_8 == V_108 ) {
V_106 = F_31 ( L_23 ) ;
}
else {
V_106 = F_31 ( L_24 ) ;
}
break;
default:
break;
}
return V_106 ;
}
static T_10 F_32 ( T_14 * V_20 , T_12 * V_18 ,
T_13 * V_19 )
{
T_1 V_115 = 0 ;
struct T_9 * V_11 ;
T_14 * V_116 ;
V_15 V_117 = 0 ;
T_10 V_118 = FALSE ;
T_10 V_119 = FALSE ;
if ( ! V_120 ) {
return FALSE ;
}
if ( ( V_121 ) F_33 ( V_20 , V_115 ) < ( strlen ( V_122 ) + 3 + 2 ) ) {
return FALSE ;
}
if ( F_34 ( V_20 , V_115 , V_122 , strlen ( V_122 ) ) != 0 ) {
return FALSE ;
}
V_115 += ( T_1 ) strlen ( V_122 ) ;
V_11 = ( T_9 * ) F_35 ( V_18 -> V_57 , V_123 ) ;
if ( V_11 == NULL ) {
V_11 = F_6 ( T_9 ) ;
V_118 = FALSE ;
}
else {
V_118 = TRUE ;
}
V_11 -> V_87 = F_36 ( V_20 , V_115 ++ ) ;
V_11 -> V_6 = F_36 ( V_20 , V_115 ++ ) ;
V_11 -> V_90 = F_36 ( V_20 , V_115 ++ ) ;
while ( V_117 != V_124 ) {
V_117 = F_36 ( V_20 , V_115 ++ ) ;
switch ( V_117 ) {
case V_125 :
V_11 -> V_31 = F_36 ( V_20 , V_115 ) ;
V_115 ++ ;
V_119 = TRUE ;
break;
case V_126 :
V_11 -> V_8 = F_36 ( V_20 , V_115 ) ;
V_115 ++ ;
break;
case V_127 :
V_11 -> V_83 = F_36 ( V_20 , V_115 ) ;
V_115 ++ ;
break;
case V_128 :
V_11 -> V_111 = F_36 ( V_20 , V_115 ) ;
V_115 ++ ;
break;
case V_129 :
V_11 -> V_130 = F_37 ( V_20 , V_115 ) ;
V_115 += 2 ;
break;
case V_131 :
V_11 -> V_100 = F_36 ( V_20 , V_115 ) ;
V_115 ++ ;
break;
case V_132 :
V_11 -> V_102 = F_36 ( V_20 , V_115 ) ;
V_115 ++ ;
break;
case V_133 :
V_11 -> V_92 = F_36 ( V_20 , V_115 ) ;
V_115 ++ ;
break;
case V_134 :
V_11 -> V_94 = F_36 ( V_20 , V_115 ) ;
V_115 ++ ;
break;
case V_135 :
V_11 -> V_96 = F_36 ( V_20 , V_115 ) ;
V_115 ++ ;
break;
case V_136 :
V_11 -> V_98 = F_37 ( V_20 , V_115 ) ;
V_115 += 2 ;
break;
case V_124 :
continue;
default:
return FALSE ;
}
}
if ( ( V_11 -> V_6 == V_85 ) && ( V_119 == FALSE ) ) {
return FALSE ;
}
if ( ! V_118 ) {
F_38 ( V_18 -> V_57 , V_123 , V_11 ) ;
}
V_116 = F_39 ( V_20 , V_115 , - 1 , F_40 ( V_20 ) - V_115 ) ;
F_41 ( V_116 , V_18 , V_19 ) ;
return TRUE ;
}
static void F_41 ( T_14 * V_20 , T_12 * V_18 , T_13 * V_19 )
{
const char * V_92 ;
T_13 * V_137 = NULL ;
T_15 * V_138 = NULL ;
T_1 V_115 = 0 ;
T_1 V_139 ;
struct T_9 * V_72 ;
T_19 * V_140 = NULL ;
T_14 * V_141 = NULL ;
#if 0
proto_tree *rohc_tree = NULL;
proto_item *rohc_ti = NULL;
guint8 base_header_byte;
gboolean udp_checksum_needed = TRUE;
gboolean ip_id_needed = TRUE;
#endif
F_42 ( V_18 -> V_70 , V_142 , L_25 ) ;
if ( ( V_143 == V_144 ) &&
( F_35 ( V_18 -> V_57 , V_145 ) != NULL ) ) {
F_43 ( V_18 -> V_70 , FALSE ) ;
}
else {
F_44 ( V_18 -> V_70 , V_71 ) ;
F_43 ( V_18 -> V_70 , TRUE ) ;
}
if ( V_19 ) {
V_138 = F_28 ( V_19 , V_123 , V_20 , V_115 , - 1 , V_77 ) ;
V_137 = F_9 ( V_138 , V_146 ) ;
}
V_72 = F_35 ( V_18 -> V_57 , V_123 ) ;
if ( V_72 == NULL ) {
return;
}
V_92 = F_17 ( V_72 -> V_92 , V_104 , L_14 ) ;
if ( V_137 ) {
F_27 ( V_18 , V_20 , V_137 , V_72 ) ;
}
if ( V_72 -> V_90 ) {
F_29 ( V_18 -> V_70 , V_71 , L_26 , V_92 [ 0 ] ) ;
}
if ( ! V_72 -> V_87 ) {
T_7 V_147 = 0 ;
T_10 V_148 = FALSE ;
if ( V_72 -> V_6 == V_149 ) {
T_8 V_150 ;
T_8 V_151 ;
V_15 V_152 = ( F_36 ( V_20 , V_115 ) & 0xe0 ) >> 5 ;
T_15 * V_24 = F_28 ( V_137 , V_153 ,
V_20 , V_115 , 1 , V_154 ) ;
if ( V_152 != 0 ) {
F_16 ( V_18 , V_24 , V_155 , V_156 ,
L_27 ) ;
}
V_147 = F_36 ( V_20 , V_115 ) & 0x1f ;
V_148 = TRUE ;
F_28 ( V_137 , V_157 , V_20 , V_115 , 1 , V_154 ) ;
F_23 ( V_138 , V_18 , L_28 , V_147 ) ;
V_115 ++ ;
if ( V_158 ) {
T_18 V_106 = F_30 ( V_72 ) ;
if ( V_106 != 0 ) {
T_14 * V_159 = F_39 ( V_20 , V_115 ,
F_33 ( V_20 , V_115 ) - 4 ,
F_33 ( V_20 , V_115 ) - 4 ) ;
T_10 V_160 = F_45 ( V_18 -> V_70 ) ;
F_43 ( V_18 -> V_70 , TRUE ) ;
F_46 ( V_106 , V_159 , V_18 , V_137 ) ;
F_43 ( V_18 -> V_70 , V_160 ) ;
}
else {
F_28 ( V_137 , V_161 , V_20 , V_115 ,
F_33 ( V_20 , V_115 ) - 4 , V_77 ) ;
}
}
else {
F_28 ( V_137 , V_161 , V_20 , V_115 ,
F_33 ( V_20 , V_115 ) - 4 , V_77 ) ;
}
V_151 = F_33 ( V_20 , V_115 ) - 4 ;
V_115 += V_151 ;
V_150 = F_47 ( V_20 , V_115 ) ;
F_28 ( V_137 , V_162 , V_20 , V_115 , 4 , V_154 ) ;
V_115 += 4 ;
F_29 ( V_18 -> V_70 , V_71 , L_29 ,
V_150 , V_151 ) ;
}
else if ( V_72 -> V_6 == V_85 ) {
T_10 V_163 = ( F_36 ( V_20 , V_115 ) & 0x80 ) >> 7 ;
F_28 ( V_137 , V_164 , V_20 , V_115 , 1 , V_154 ) ;
if ( V_163 == 1 ) {
if ( V_72 -> V_31 == V_33 ) {
V_147 = F_36 ( V_20 , V_115 ) & 0x7f ;
V_148 = TRUE ;
F_28 ( V_137 , V_165 , V_20 , V_115 , 1 , V_154 ) ;
V_115 ++ ;
}
else if ( V_72 -> V_31 == V_34 ) {
T_15 * V_24 ;
V_15 V_166 ;
V_24 = F_28 ( V_137 , V_167 , V_20 , V_115 , 1 , V_154 ) ;
V_166 = ( F_36 ( V_20 , V_115 ) & 0x70 ) >> 4 ;
if ( V_166 != 0 ) {
F_16 ( V_18 , V_24 , V_155 , V_156 ,
L_30 ,
V_166 ) ;
}
V_147 = F_37 ( V_20 , V_115 ) & 0x0fff ;
V_148 = TRUE ;
F_28 ( V_137 , V_168 , V_20 , V_115 , 2 , V_154 ) ;
V_115 += 2 ;
}
else {
return;
}
F_23 ( V_138 , V_18 , L_31 , V_147 ) ;
}
else {
V_15 V_169 = ( F_36 ( V_20 , V_115 ) & 0x70 ) >> 4 ;
F_28 ( V_137 , V_170 , V_20 , V_115 , 1 , V_154 ) ;
switch ( V_169 ) {
case 0 :
{
T_7 V_171 ;
T_4 V_172 = 0 ;
T_4 V_173 ;
T_13 * V_174 ;
T_15 * V_175 = NULL ;
V_171 = F_37 ( V_20 , V_115 ) & 0x0fff ;
V_173 = ( V_171 + 1 ) % 4096 ;
F_28 ( V_137 , V_176 , V_20 ,
V_115 , 2 , V_154 ) ;
V_115 += 2 ;
if ( F_33 ( V_20 , V_115 ) > 0 ) {
V_175 = F_28 ( V_137 , V_177 , V_20 ,
V_115 , - 1 , V_77 ) ;
V_174 = F_9 ( V_175 , V_178 ) ;
for ( ; F_33 ( V_20 , V_115 ) ; V_115 ++ ) {
T_4 V_179 = 0 ;
for ( ; V_179 < 8 ; V_179 ++ ) {
if ( ( F_36 ( V_20 , V_115 ) >> ( 7 - V_179 ) & 0x1 ) == 0 ) {
F_48 ( V_174 , V_180 , V_20 , V_115 * 8 + V_179 ,
1 , 0 , L_31 , V_173 ) ;
V_172 ++ ;
}
V_173 = ( V_173 + 1 ) % 4096 ;
}
}
}
if ( V_175 != NULL ) {
F_15 ( V_175 , L_32 , V_172 ) ;
}
F_23 ( V_138 , V_18 , L_33 ,
V_171 , V_172 ) ;
}
return;
case 1 :
V_115 ++ ;
break;
default:
return;
}
}
}
else {
F_23 ( V_138 , V_18 , L_34 ,
V_72 -> V_6 ) ;
return;
}
if ( V_148 ) {
T_10 V_181 = FALSE ;
switch ( V_182 ) {
case FALSE :
break;
case V_183 :
if ( ( F_35 ( V_18 -> V_57 , V_145 ) != NULL ) &&
! V_72 -> V_184 ) {
V_181 = TRUE ;
}
break;
case V_185 :
if ( F_35 ( V_18 -> V_57 , V_145 ) == NULL ) {
V_181 = TRUE ;
}
break;
}
if ( V_181 ) {
F_18 ( V_18 , V_20 , V_72 ,
( T_7 ) V_147 , V_137 ) ;
}
}
}
else {
F_23 ( V_138 , V_18 , L_35 ) ;
}
if ( ! V_72 -> V_90 ) {
if ( F_33 ( V_20 , V_115 ) > 0 ) {
if ( V_72 -> V_6 == V_85 ) {
if ( V_186 ) {
T_14 * V_159 = F_49 ( V_20 , V_115 ) ;
if ( V_143 != V_187 ) {
F_43 ( V_18 -> V_70 , FALSE ) ;
}
switch ( F_36 ( V_20 , V_115 ) & 0xf0 ) {
case 0x40 :
F_46 ( V_188 , V_159 , V_18 , V_137 ) ;
break;
case 0x60 :
F_46 ( V_189 , V_159 , V_18 , V_137 ) ;
break;
default:
F_46 ( V_190 , V_159 , V_18 , V_137 ) ;
break;
}
if ( V_143 == V_187 ) {
F_43 ( V_18 -> V_70 , FALSE ) ;
}
}
else {
F_28 ( V_137 , V_191 , V_20 , V_115 , - 1 , V_77 ) ;
}
}
else {
if ( V_158 ) {
T_18 V_106 = F_30 ( V_72 ) ;
if ( V_106 != 0 ) {
T_14 * V_159 = F_39 ( V_20 , V_115 ,
F_33 ( V_20 , V_115 ) ,
F_33 ( V_20 , V_115 ) ) ;
F_46 ( V_106 , V_159 , V_18 , V_137 ) ;
}
else {
F_28 ( V_137 , V_161 , V_20 , V_115 ,
F_33 ( V_20 , V_115 ) , V_77 ) ;
}
}
else {
F_28 ( V_137 , V_161 , V_20 , V_115 , - 1 , V_77 ) ;
}
}
F_23 ( V_138 , V_18 , L_36 ,
F_33 ( V_20 , V_115 ) ) ;
}
F_43 ( V_18 -> V_70 , V_143 == V_144 ) ;
return;
}
if ( ! V_192 ) {
F_29 ( V_18 -> V_70 , V_142 , L_37 ,
F_17 ( V_72 -> V_98 , V_105 , L_5 ) ) ;
return;
}
#if 0
if (pdcp_tree) {
rohc_ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_rohc, tvb, offset, -1, ENC_NA);
rohc_tree = proto_item_add_subtree(rohc_ti, ett_pdcp_rohc);
}
#endif
V_139 = V_115 ;
V_141 = F_49 ( V_20 , V_139 ) ;
V_140 = F_50 ( T_19 ) ;
V_140 -> V_90 = V_72 -> V_90 ;
V_140 -> V_130 = V_72 -> V_130 ;
V_140 -> V_100 = V_72 -> V_100 ;
V_140 -> V_102 = V_72 -> V_102 ;
V_140 -> V_92 = V_72 -> V_92 ;
V_140 -> V_94 = V_72 -> V_94 ;
V_140 -> V_96 = V_72 -> V_96 ;
V_140 -> V_98 = V_72 -> V_98 ;
V_140 -> V_193 = NULL ;
V_18 -> V_194 = V_140 ;
if ( V_143 != V_187 ) {
F_43 ( V_18 -> V_70 , FALSE ) ;
}
else {
F_44 ( V_18 -> V_70 , V_71 ) ;
}
F_51 ( V_195 , V_141 , V_18 , V_19 ) ;
F_43 ( V_18 -> V_70 , V_143 == V_144 ) ;
return;
#if 0
while (tvb_get_guint8(tvb, offset) == 0xe0) {
offset++;
}
if (offset > rohc_offset) {
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_padding, tvb, rohc_offset,
offset-rohc_offset, ENC_NA);
}
cid = 0;
if ((p_pdcp_info->cid_inclusion_info == CID_IN_ROHC_PACKET) &&
!p_pdcp_info->large_cid_present)
{
if (((tvb_get_guint8(tvb, offset) >> 4) & 0x0f) == 0x0e) {
cid = tvb_get_guint8(tvb, offset) & 0x0f;
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_add_cid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
else {
proto_item *ti = proto_tree_add_uint(rohc_tree, hf_pdcp_lte_rohc_add_cid, tvb, offset, 0, 0);
PROTO_ITEM_SET_GENERATED(ti);
}
}
base_header_byte = tvb_get_guint8(tvb, offset);
if ((base_header_byte & 0xfe) == 0xfc) {
p_rohc_info = ep_new(rohc_info);
p_rohc_info->rohc_compression = p_pdcp_info->rohc_compression;
p_rohc_info->rohc_ip_version = p_pdcp_info->rohc_ip_version;
p_rohc_info->cid_inclusion_info = p_pdcp_info->cid_inclusion_info;
p_rohc_info->large_cid_present = p_pdcp_info->large_cid_present;
p_rohc_info->mode = p_pdcp_info->mode;
p_rohc_info->rnd = p_pdcp_info->rnd;
p_rohc_info->udp_checkum_present = p_pdcp_info->udp_checkum_present;
p_rohc_info->profile = p_pdcp_info->profile;
p_rohc_info->last_created_item = NULL;
offset = dissect_rohc_ir_packet(tvb, rohc_tree, pinfo, offset, cid, TRUE, p_rohc_info);
udp_checksum_needed = FALSE;
ip_id_needed = FALSE;
}
else if (base_header_byte == 0xf8) {
p_rohc_info = ep_new(rohc_info);
p_rohc_info->rohc_compression = p_pdcp_info->rohc_compression;
p_rohc_info->rohc_ip_version = p_pdcp_info->rohc_ip_version;
p_rohc_info->cid_inclusion_info = p_pdcp_info->cid_inclusion_info;
p_rohc_info->large_cid_present = p_pdcp_info->large_cid_present;
p_rohc_info->mode = p_pdcp_info->mode;
p_rohc_info->rnd = p_pdcp_info->rnd;
p_rohc_info->udp_checkum_present = p_pdcp_info->udp_checkum_present;
p_rohc_info->profile = p_pdcp_info->profile;
p_rohc_info->last_created_item = NULL;
offset = dissect_rohc_ir_dyn_packet(tvb, rohc_tree, pinfo, offset, cid, TRUE, p_rohc_info);
udp_checksum_needed = FALSE;
ip_id_needed = FALSE;
}
else if (((base_header_byte & 0xf8) >> 3) == 0x1e) {
offset = dissect_pdcp_feedback_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
return;
}
else if ((base_header_byte & 0x80) == 0) {
if (((base_header_byte & 0xc0) == 0) &&
(p_pdcp_info->mode == RELIABLE_BIDIRECTIONAL)) {
offset = dissect_pdcp_r_0_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
else if ((((base_header_byte & 0x40) >> 6) == 1) &&
(p_pdcp_info->mode == RELIABLE_BIDIRECTIONAL)) {
offset = dissect_pdcp_r_0_crc_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
else {
offset = dissect_pdcp_uo_0_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
}
else if (((base_header_byte & 0xc0) >> 6) == 2) {
switch (p_pdcp_info->mode) {
case RELIABLE_BIDIRECTIONAL:
if (!((p_pdcp_info->rohc_ip_version == 4) &&
(!p_pdcp_info->rnd))) {
offset = dissect_pdcp_r_1_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
return;
}
else {
dissect_pdcp_r_1_ts_or_id_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
return;
}
break;
case UNIDIRECTIONAL:
case OPTIMISTIC_BIDIRECTIONAL:
if (!((p_pdcp_info->rohc_ip_version == 4) &&
(!p_pdcp_info->rnd))) {
dissect_pdcp_uo_1_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
} else {
dissect_pdcp_uo_1_ts_or_id_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
return;
}
}
else if (((base_header_byte & 0xe0) >> 5) == 6) {
if (!((p_pdcp_info->rohc_ip_version == 4) &&
(!p_pdcp_info->rnd))) {
dissect_pdcp_uor_2_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
else {
dissect_pdcp_uor_2_ts_or_id_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
return;
}
}
else if ((base_header_byte & 0xfe) == 0xfe) {
return;
}
if (p_pdcp_info->rnd && ip_id_needed) {
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_ip_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (p_pdcp_info->udp_checkum_present && udp_checksum_needed) {
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_udp_checksum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_payload, tvb, offset, -1, ENC_NA);
}
#endif
}
static void F_52 ( void )
{
if ( V_62 ) {
F_53 ( V_62 ) ;
}
if ( V_60 ) {
F_53 ( V_60 ) ;
}
V_62 = F_54 ( F_2 , F_1 ) ;
V_60 = F_54 ( F_4 , F_3 ) ;
}
void F_55 ( void )
{
static T_20 V_196 [] =
{
{ & V_75 ,
{ L_38 ,
L_39 , V_197 , V_198 , NULL , 0x0 ,
L_40 , V_199
}
} ,
{ & V_89 ,
{ L_41 ,
L_42 , V_200 , V_198 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_91 ,
{ L_43 ,
L_44 , V_201 , V_202 , F_56 ( V_104 ) , 0x0 ,
NULL , V_199
}
} ,
{ & V_93 ,
{ L_45 ,
L_46 , V_201 , V_202 , NULL , 0x0 ,
L_47 , V_199
}
} ,
{ & V_95 ,
{ L_48 ,
L_49 , V_201 , V_202 , NULL , 0x0 ,
L_50 , V_199
}
} ,
{ & V_79 ,
{ L_51 ,
L_52 , V_201 , V_202 , F_56 ( V_46 ) , 0x0 ,
L_53 , V_199
}
} ,
{ & V_81 ,
{ L_54 ,
L_55 , V_203 , V_202 , 0 , 0x0 ,
L_56 , V_199
}
} ,
{ & V_82 ,
{ L_57 ,
L_58 , V_201 , V_202 , F_56 ( V_204 ) , 0x0 ,
NULL , V_199
}
} ,
{ & V_84 ,
{ L_59 ,
L_60 , V_201 , V_202 , 0 , 0x0 ,
NULL , V_199
}
} ,
{ & V_97 ,
{ L_61 ,
L_62 , V_201 , V_202 , F_56 ( V_105 ) , 0x0 ,
L_43 , V_199
}
} ,
{ & V_86 ,
{ L_63 ,
L_64 , V_201 , V_202 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_80 ,
{ L_65 ,
L_66 , V_201 , V_202 , F_56 ( V_103 ) , 0x0 ,
NULL , V_199
}
} ,
{ & V_88 ,
{ L_67 ,
L_68 , V_201 , V_202 , NULL , 0x0 ,
L_69 , V_199
}
} ,
{ & V_99 ,
{ L_70 ,
L_71 , V_201 , V_202 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_101 ,
{ L_72 ,
L_73 , V_201 , V_202 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_153 ,
{ L_74 ,
L_75 , V_201 , V_202 , NULL , 0xe0 ,
NULL , V_199
}
} ,
{ & V_157 ,
{ L_76 ,
L_77 , V_201 , V_202 , NULL , 0x1f ,
L_78 , V_199
}
} ,
{ & V_165 ,
{ L_76 ,
L_77 , V_201 , V_202 , NULL , 0x7f ,
L_78 , V_199
}
} ,
{ & V_167 ,
{ L_74 ,
L_79 , V_201 , V_205 , NULL , 0x70 ,
L_80 , V_199
}
} ,
{ & V_168 ,
{ L_76 ,
L_77 , V_203 , V_202 , NULL , 0x0fff ,
L_78 , V_199
}
} ,
{ & V_161 ,
{ L_81 ,
L_82 , V_206 , V_198 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_162 ,
{ L_83 ,
L_84 , V_207 , V_208 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_164 ,
{ L_85 ,
L_86 , V_201 , V_205 , F_56 ( V_209 ) , 0x80 ,
NULL , V_199
}
} ,
{ & V_191 ,
{ L_87 ,
L_88 , V_206 , V_198 , NULL , 0x0 ,
NULL , V_199
}
} ,
{ & V_170 ,
{ L_89 ,
L_90 , V_201 , V_205 , F_56 ( V_210 ) , 0x70 ,
NULL , V_199
}
} ,
{ & V_176 ,
{ L_91 ,
L_92 , V_203 , V_202 , NULL , 0x0fff ,
L_93 , V_199
}
} ,
{ & V_177 ,
{ L_94 ,
L_95 , V_211 , V_198 , NULL , 0x0 ,
L_96 , V_199
}
} ,
{ & V_180 ,
{ L_97 ,
L_98 , V_200 , V_198 , NULL , 0x0 ,
L_99 , V_199
}
} ,
{ & V_25 ,
{ L_2 ,
L_100 , V_197 , V_198 , 0 , 0x0 ,
NULL , V_199
}
} ,
{ & V_37 ,
{ L_101 ,
L_102 , V_200 , V_198 , 0 , 0x0 ,
NULL , V_199
}
} ,
{ & V_28 ,
{ L_103 ,
L_104 , V_212 , V_198 , 0 , 0x0 ,
NULL , V_199
}
} ,
{ & V_39 ,
{ L_105 ,
L_106 , V_212 , V_198 , 0 , 0x0 ,
NULL , V_199
}
} ,
{ & V_29 ,
{ L_107 ,
L_108 , V_203 , V_202 , 0 , 0x0 ,
NULL , V_199
}
} ,
{ & V_41 ,
{ L_109 ,
L_110 , V_200 , V_198 , 0 , 0x0 ,
NULL , V_199
}
} ,
{ & V_49 ,
{ L_111 ,
L_112 , V_200 , V_198 , 0 , 0x0 ,
NULL , V_199
}
} ,
#if 0
{ &hf_pdcp_lte_rohc,
{ "ROHC Message",
"pdcp-lte.rohc", FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_padding,
{ "Padding",
"pdcp-lte.rohc.padding", FT_NONE, BASE_NONE, NULL, 0,
"ROHC Padding", HFILL
}
},
{ &hf_pdcp_lte_rohc_r_0_crc,
{ "R-0-CRC Packet",
"pdcp-lte.r-0-crc", FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback,
{ "Feedback",
"pdcp-lte.rohc.feedback", FT_NONE, BASE_NONE, NULL, 0,
"Feedback Packet", HFILL
}
},
{ &hf_pdcp_lte_rohc_type0_t,
{ "T",
"pdcp-lte.rohc.t0.t", FT_UINT8, BASE_HEX, VALS(t_vals), 0x20,
"Indicates whether frame type is TS (1) or ID (0)", HFILL
}
},
{ &hf_pdcp_lte_rohc_type1_t,
{ "T",
"pdcp-lte.rohc.t1.t", FT_UINT8, BASE_HEX, VALS(t_vals), 0x80,
"Indicates whether frame type is TS (1) or ID (0)", HFILL
}
},
{ &hf_pdcp_lte_rohc_type2_t,
{ "T",
"pdcp-lte.rohc.t2.t", FT_UINT8, BASE_HEX, VALS(t_vals), 0x80,
"Indicates whether frame type is TS (1) or ID (0)", HFILL
}
},
{ &hf_pdcp_lte_rohc_d,
{ "D",
"pdcp-lte.rohc.d", FT_UINT8, BASE_HEX, NULL, 0x01,
"Indicates whether Dynamic chain is present", HFILL
}
},
{ &hf_pdcp_lte_rohc_ir_crc,
{ "CRC",
"pdcp-lte.rohc.ir.crc", FT_UINT8, BASE_HEX, NULL, 0x0,
"8-bit CRC", HFILL
}
},
{ &hf_pdcp_lte_rohc_static_ipv4,
{ "Static IPv4 chain",
"pdcp-lte.rohc.static.ipv4", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_version,
{ "IP Version",
"pdcp-lte.rohc.ip-version", FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_protocol,
{ "IP Protocol",
"pdcp-lte.rohc.ip-protocol", FT_UINT8, BASE_DEC, VALS(ip_protocol_vals), 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_src,
{ "IP Source address",
"pdcp-lte.rohc.ip-src", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_dst,
{ "IP Destination address",
"pdcp-lte.rohc.ip-dst", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_udp,
{ "Static UDP chain",
"pdcp-lte.rohc.static.udp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_udp_src_port,
{ "Static UDP source port",
"pdcp-lte.rohc.static.udp.src-port", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_udp_dst_port,
{ "Static UDP destination port",
"pdcp-lte.rohc.static.udp.dst-port", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_rtp,
{ "Static RTP chain",
"pdcp-lte.rohc.static.rtp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_rtp_ssrc,
{ "SSRC",
"pdcp-lte.rohc.static.rtp.ssrc", FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
"Static RTP chain SSRC", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4,
{ "Dynamic IPv4 chain",
"pdcp-lte.rohc.dynamic.ipv4", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_tos,
{ "ToS",
"pdcp-lte.rohc.ip.tos", FT_UINT8, BASE_HEX, NULL, 0x0,
"IP Type of Service", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_ttl,
{ "TTL",
"pdcp-lte.rohc.ip.ttl", FT_UINT8, BASE_HEX, NULL, 0x0,
"IP Time To Live", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_id,
{ "IP-ID",
"pdcp-lte.rohc.ip.id", FT_UINT16, BASE_HEX, NULL, 0x0,
"IP ID", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_df,
{ "Don't Fragment",
"pdcp-lte.rohc.ip.df", FT_UINT8, BASE_HEX, NULL, 0x80,
"IP Don't Fragment flag", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_rnd,
{ "Random IP-ID field",
"pdcp-lte.rohc.ip.rnd", FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_nbo,
{ "Network Byte Order IP-ID field",
"pdcp-lte.rohc.ip.nbo", FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_udp,
{ "Dynamic UDP chain",
"pdcp-lte.rohc.dynamic.udp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_udp_checksum,
{ "UDP Checksum",
"pdcp-lte.rohc.dynamic.udp.checksum", FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_udp_seqnum,
{ "UDP Sequence Number",
"pdcp-lte.rohc.dynamic.udp.seqnum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp,
{ "Dynamic RTP chain",
"pdcp-lte.rohc.dynamic.rtp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_rx,
{ "RX",
"pdcp-lte.rohc.dynamic.rtp.rx", FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_cc,
{ "Contributing CSRCs",
"pdcp-lte.rohc.dynamic.rtp.cc", FT_UINT8, BASE_DEC, NULL, 0x0f,
"Dynamic RTP chain CCs", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_seqnum,
{ "RTP Sequence Number",
"pdcp-lte.rohc.dynamic.rtp.seqnum", FT_UINT16, BASE_DEC, NULL, 0x0,
"Dynamic RTP chain Sequence Number", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_timestamp,
{ "RTP Timestamp",
"pdcp-lte.rohc.dynamic.rtp.timestamp", FT_UINT32, BASE_DEC, NULL, 0x0,
"Dynamic RTP chain Timestamp", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_reserved3,
{ "Reserved",
"pdcp-lte.rohc.dynamic.rtp.reserved3", FT_UINT8, BASE_HEX, NULL, 0xc0,
"Reserved bits", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_x,
{ "X",
"pdcp-lte.rohc.dynamic.rtp.x", FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_mode,
{ "Mode",
"pdcp-lte.rohc.dynamic.rtp.mode", FT_UINT8, BASE_HEX, VALS(rohc_mode_vals), 0x0c,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_tis,
{ "TIS",
"pdcp-lte.rohc.dynamic.rtp.tis", FT_UINT8, BASE_HEX, NULL, 0x02,
"Dynamic RTP chain TIS (indicates time_stride present)", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_tss,
{ "TSS",
"pdcp-lte.rohc.dynamic.rtp.tss", FT_UINT8, BASE_HEX, NULL, 0x01,
"Dynamic RTP chain TSS (indicates TS_stride present)", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_ts_stride,
{ "TS Stride",
"pdcp-lte.rohc.dynamic.rtp.ts-stride", FT_UINT32, BASE_DEC, NULL, 0x0,
"Dynamic RTP chain TS Stride", HFILL
}
},
{ &hf_pdcp_lte_rohc_ts,
{ "TS",
"pdcp-lte.rohc.ts", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_m,
{ "M",
"pdcp-lte.rohc.m", FT_UINT8, BASE_DEC, NULL, 0x40,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_uor2_sn,
{ "SN",
"pdcp-lte.rohc.uor2.sn", FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_uor2_x,
{ "X",
"pdcp-lte.rohc.uor2.x", FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_add_cid,
{ "Add-CID",
"pdcp-lte.rohc.add-cid", FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_large_cid,
{ "Large-CID",
"pdcp-lte.rohc.large-cid", FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_uo0_sn,
{ "SN",
"pdcp-lte.rohc.uo0.sn", FT_UINT8, BASE_DEC, NULL, 0x78,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_uo0_crc,
{ "CRC",
"pdcp-lte.rohc.uo0.crc", FT_UINT8, BASE_DEC, NULL, 0x07,
"3-bit CRC", HFILL
}
},
{ &hf_pdcp_lte_rohc_r0_sn,
{ "SN",
"pdcp-lte.rohc.r0.sn", FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_r0_crc_sn,
{ "SN",
"pdcp-lte.rohc.r0-crc.sn", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_r0_crc_crc,
{ "CRC7",
"pdcp-lte.rohc.r0-crc.crc", FT_UINT8, BASE_DEC, NULL, 0x7f,
"CRC 7", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_code,
{ "Code",
"pdcp-lte.rohc.feedback-code", FT_UINT8, BASE_DEC, NULL, 0x07,
"Feedback options length (if > 0)", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_size,
{ "Size",
"pdcp-lte.rohc.feedback-size", FT_UINT8, BASE_DEC, NULL, 0x0,
"Feedback options length", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_feedback1,
{ "FEEDBACK-1 (SN)",
"pdcp-lte.rohc.feedback.feedback1", FT_UINT8, BASE_DEC, NULL, 0x0,
"Feedback-1", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_feedback2,
{ "FEEDBACK-2",
"pdcp-lte.rohc.feedback.feedback2", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_ack_type,
{ "Acktype",
"pdcp-lte.rohc.feedback-acktype", FT_UINT8, BASE_DEC, VALS(feedback_ack_vals), 0xc0,
"Feedback-2 ack type", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_mode,
{ "mode",
"pdcp-lte.rohc.feedback-mode", FT_UINT8, BASE_DEC, VALS(rohc_mode_vals), 0x30,
"Feedback mode", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_sn,
{ "SN",
"pdcp-lte.rohc.feedback-sn", FT_UINT16, BASE_DEC, NULL, 0x0fff,
"Feedback sequence number", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_option,
{ "Option",
"pdcp-lte.rohc.feedback-option", FT_UINT8, BASE_DEC, VALS(feedback_option_vals), 0xf0,
"Feedback option", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_length,
{ "Length",
"pdcp-lte.rohc.feedback-length", FT_UINT8, BASE_DEC, NULL, 0x0f,
"Feedback length", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_crc,
{ "CRC",
"pdcp-lte.rohc.feedback-crc", FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
"Feedback CRC", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_option_sn,
{ "SN",
"pdcp-lte.rohc.feedback-option-sn", FT_UINT8, BASE_DEC, NULL, 0x0,
"Feedback Option SN", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_option_clock,
{ "Clock",
"pdcp-lte.rohc.feedback-option-clock", FT_UINT8, BASE_DEC, NULL, 0x0,
"Feedback Option Clock", HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_id,
{ "IP-ID",
"pdcp-lte.rohc.ip-id", FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_udp_checksum,
{ "UDP Checksum",
"pdcp-lte.rohc.udp-checksum", FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_payload,
{ "Payload",
"pdcp-lte.rohc.payload", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
#endif
} ;
static T_1 * V_213 [] =
{
& V_146 ,
& V_78 ,
& V_214 ,
& V_26 ,
& V_215 ,
& V_216 ,
& V_217 ,
& V_218 ,
& V_219 ,
& V_220 ,
& V_221 ,
& V_178
} ;
static T_21 V_222 [] = {
{ L_113 , L_114 , FALSE } ,
{ L_115 , L_116 , V_183 } ,
{ L_117 , L_118 , V_185 } ,
{ NULL , NULL , - 1 }
} ;
static T_21 V_223 [] = {
{ L_119 , L_120 , V_144 } ,
{ L_121 , L_122 , V_224 } ,
{ L_123 , L_124 , V_187 } ,
{ NULL , NULL , - 1 }
} ;
T_22 * V_225 ;
V_123 = F_57 ( L_25 , L_25 , L_125 ) ;
F_58 ( V_123 , V_196 , F_59 ( V_196 ) ) ;
F_60 ( V_213 , F_59 ( V_213 ) ) ;
F_61 ( L_125 , F_41 , V_123 ) ;
V_225 = F_62 ( V_123 , NULL ) ;
F_63 ( V_225 , L_126 ) ;
F_64 ( V_225 , L_127 ,
L_128 ,
L_128 ,
& V_186 ) ;
F_64 ( V_225 , L_129 ,
L_130 ,
L_130 ,
& V_158 ) ;
F_65 ( V_225 , L_131 ,
L_132 ,
L_132 ,
& V_182 , V_222 , FALSE ) ;
F_64 ( V_225 , L_133 ,
L_134 ,
L_134 ,
& V_192 ) ;
F_64 ( V_225 , L_135 ,
L_136 ,
L_137
L_138 ,
& V_120 ) ;
F_65 ( V_225 , L_139 ,
L_140 ,
L_141 ,
& V_143 , V_223 , FALSE ) ;
F_66 ( & F_52 ) ;
}
void F_67 ( void )
{
F_68 ( L_142 , F_32 , V_123 ) ;
V_188 = F_31 ( L_143 ) ;
V_189 = F_31 ( L_144 ) ;
V_195 = F_31 ( L_145 ) ;
V_190 = F_31 ( L_146 ) ;
}
