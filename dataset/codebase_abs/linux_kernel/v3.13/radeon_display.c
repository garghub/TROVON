static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
F_3 ( L_1 , V_3 -> V_10 ) ;
F_4 ( V_11 + V_3 -> V_12 , 0 ) ;
F_4 ( V_13 + V_3 -> V_12 , 0 ) ;
F_4 ( V_14 + V_3 -> V_12 , 0 ) ;
F_4 ( V_15 + V_3 -> V_12 , 0 ) ;
F_4 ( V_16 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_17 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_18 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_19 , V_3 -> V_10 ) ;
F_4 ( V_20 , 0 ) ;
F_4 ( V_21 , 0x0000003f ) ;
F_5 ( V_22 , 0 ) ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
F_4 ( V_23 ,
( V_3 -> V_24 [ V_9 ] << 20 ) |
( V_3 -> V_25 [ V_9 ] << 10 ) |
( V_3 -> V_26 [ V_9 ] << 0 ) ) ;
}
F_4 ( V_27 + V_3 -> V_12 , V_3 -> V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
F_3 ( L_1 , V_3 -> V_10 ) ;
F_4 ( V_28 + V_3 -> V_12 , 0 ) ;
F_4 ( V_29 + V_3 -> V_12 , 0 ) ;
F_4 ( V_30 + V_3 -> V_12 , 0 ) ;
F_4 ( V_31 + V_3 -> V_12 , 0 ) ;
F_4 ( V_32 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_33 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_34 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_35 + V_3 -> V_12 , 0 ) ;
F_4 ( V_36 + V_3 -> V_12 , 0x00000007 ) ;
F_4 ( V_37 + V_3 -> V_12 , 0 ) ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
F_4 ( V_38 + V_3 -> V_12 ,
( V_3 -> V_24 [ V_9 ] << 20 ) |
( V_3 -> V_25 [ V_9 ] << 10 ) |
( V_3 -> V_26 [ V_9 ] << 0 ) ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
F_3 ( L_1 , V_3 -> V_10 ) ;
F_4 ( V_39 + V_3 -> V_12 ,
( F_8 ( V_40 ) |
F_9 ( V_40 ) ) ) ;
F_4 ( V_41 + V_3 -> V_12 ,
V_42 ) ;
F_4 ( V_43 + V_3 -> V_12 ,
V_44 ) ;
F_4 ( V_45 + V_3 -> V_12 ,
( F_10 ( V_46 ) |
F_11 ( V_46 ) ) ) ;
F_4 ( V_28 + V_3 -> V_12 , 0 ) ;
F_4 ( V_29 + V_3 -> V_12 , 0 ) ;
F_4 ( V_30 + V_3 -> V_12 , 0 ) ;
F_4 ( V_31 + V_3 -> V_12 , 0 ) ;
F_4 ( V_32 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_33 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_34 + V_3 -> V_12 , 0xffff ) ;
F_4 ( V_35 + V_3 -> V_12 , 0 ) ;
F_4 ( V_36 + V_3 -> V_12 , 0x00000007 ) ;
F_4 ( V_37 + V_3 -> V_12 , 0 ) ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
F_4 ( V_38 + V_3 -> V_12 ,
( V_3 -> V_24 [ V_9 ] << 20 ) |
( V_3 -> V_25 [ V_9 ] << 10 ) |
( V_3 -> V_26 [ V_9 ] << 0 ) ) ;
}
F_4 ( V_47 + V_3 -> V_12 ,
( F_12 ( V_48 ) |
F_13 ( V_48 ) |
F_14 ( V_48 ) |
F_15 ( V_48 ) ) ) ;
F_4 ( V_49 + V_3 -> V_12 ,
( F_16 ( V_50 ) |
F_17 ( V_50 ) ) ) ;
F_4 ( V_51 + V_3 -> V_12 ,
( F_18 ( V_52 ) |
F_19 ( V_52 ) ) ) ;
F_4 ( V_53 + V_3 -> V_12 ,
( F_20 ( V_54 ) |
F_21 ( V_54 ) ) ) ;
F_4 ( 0x6940 + V_3 -> V_12 , 0 ) ;
if ( F_22 ( V_7 ) ) {
F_4 ( V_55 + V_3 -> V_12 ,
V_56 ) ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
T_1 V_57 ;
V_57 = F_24 ( V_58 ) ;
if ( V_3 -> V_10 == 0 )
V_57 &= ( T_1 ) ~ V_59 ;
else
V_57 |= V_59 ;
F_4 ( V_58 , V_57 ) ;
F_5 ( V_60 , 0 ) ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
F_4 ( V_61 ,
( V_3 -> V_24 [ V_9 ] << 20 ) |
( V_3 -> V_25 [ V_9 ] << 10 ) |
( V_3 -> V_26 [ V_9 ] << 0 ) ) ;
}
}
void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! V_2 -> V_62 )
return;
if ( F_26 ( V_7 ) )
F_7 ( V_2 ) ;
else if ( F_27 ( V_7 ) )
F_6 ( V_2 ) ;
else if ( F_28 ( V_7 ) )
F_1 ( V_2 ) ;
else
F_23 ( V_2 ) ;
}
void F_29 ( struct V_1 * V_2 , T_2 V_63 , T_2 V_64 ,
T_2 V_65 , int V_66 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_24 [ V_66 ] = V_63 >> 6 ;
V_3 -> V_25 [ V_66 ] = V_64 >> 6 ;
V_3 -> V_26 [ V_66 ] = V_65 >> 6 ;
}
void F_30 ( struct V_1 * V_2 , T_2 * V_63 , T_2 * V_64 ,
T_2 * V_65 , int V_66 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_63 = V_3 -> V_24 [ V_66 ] << 6 ;
* V_64 = V_3 -> V_25 [ V_66 ] << 6 ;
* V_65 = V_3 -> V_26 [ V_66 ] << 6 ;
}
static void F_31 ( struct V_1 * V_2 , T_2 * V_63 , T_2 * V_64 ,
T_2 * V_65 , T_1 V_67 , T_1 V_68 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_69 = ( V_67 + V_68 > 256 ) ? 256 : V_67 + V_68 , V_9 ;
for ( V_9 = V_67 ; V_9 < V_69 ; V_9 ++ ) {
V_3 -> V_24 [ V_9 ] = V_63 [ V_9 ] >> 6 ;
V_3 -> V_25 [ V_9 ] = V_64 [ V_9 ] >> 6 ;
V_3 -> V_26 [ V_9 ] = V_65 [ V_9 ] >> 6 ;
}
F_25 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_3 ) ;
}
static void F_35 ( struct V_70 * V_71 )
{
struct V_72 * V_73 =
F_36 ( V_71 , struct V_72 , V_73 ) ;
int V_74 ;
V_74 = F_37 ( V_73 -> V_75 , false ) ;
if ( F_38 ( V_74 == 0 ) ) {
V_74 = F_39 ( V_73 -> V_75 ) ;
if ( F_40 ( V_74 != 0 ) ) {
F_41 ( L_2 ) ;
}
F_42 ( V_73 -> V_75 ) ;
} else
F_41 ( L_3 ) ;
F_43 ( & V_73 -> V_75 -> V_76 ) ;
F_34 ( V_73 ) ;
}
void F_44 ( struct V_6 * V_7 , int V_10 )
{
struct V_3 * V_3 = V_7 -> V_77 . V_78 [ V_10 ] ;
struct V_72 * V_73 ;
unsigned long V_79 ;
T_3 V_80 ;
int V_81 , V_82 ;
F_45 ( & V_7 -> V_83 -> V_84 , V_79 ) ;
V_73 = V_3 -> V_85 ;
if ( V_73 == NULL ||
( V_73 -> V_86 && ! F_46 ( V_73 -> V_86 ) ) ) {
F_47 ( & V_7 -> V_83 -> V_84 , V_79 ) ;
return;
}
if ( ! V_3 -> V_87 ) {
V_80 = F_48 ( V_7 , V_10 , V_73 -> V_88 ) ;
} else {
V_80 = 0 ;
V_3 -> V_87 = 0 ;
}
if ( V_80 &&
( V_89 & F_49 ( V_7 -> V_83 , V_10 ,
& V_81 , & V_82 , NULL , NULL ) ) &&
( ( V_81 >= ( 99 * V_7 -> V_77 . V_78 [ V_10 ] -> V_90 . V_91 . V_92 ) / 100 ) ||
( V_81 < 0 && ! F_28 ( V_7 ) ) ) ) {
V_80 = 0 ;
}
if ( V_80 ) {
V_3 -> V_87 = 1 ;
F_47 ( & V_7 -> V_83 -> V_84 , V_79 ) ;
return;
}
V_3 -> V_85 = NULL ;
if ( V_73 -> V_93 )
F_50 ( V_7 -> V_83 , V_10 , V_73 -> V_93 ) ;
F_47 ( & V_7 -> V_83 -> V_84 , V_79 ) ;
F_51 ( V_7 -> V_83 , V_3 -> V_10 ) ;
F_52 ( & V_73 -> V_86 ) ;
F_53 ( V_73 -> V_7 , V_73 -> V_10 ) ;
F_54 ( & V_73 -> V_73 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
struct V_96 * V_93 ,
T_1 V_97 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_98 * V_99 ;
struct V_98 * V_100 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_72 * V_73 ;
unsigned long V_79 ;
T_3 V_105 , V_106 ;
T_4 V_90 ;
int V_74 ;
V_73 = F_56 ( sizeof *V_73 , V_107 ) ;
if ( V_73 == NULL )
return - V_108 ;
V_73 -> V_93 = V_93 ;
V_73 -> V_7 = V_7 ;
V_73 -> V_10 = V_3 -> V_10 ;
V_99 = F_57 ( V_2 -> V_95 ) ;
V_100 = F_57 ( V_95 ) ;
V_102 = V_99 -> V_102 ;
F_58 ( V_102 ) ;
V_104 = F_59 ( V_102 ) ;
V_73 -> V_75 = V_104 ;
V_102 = V_100 -> V_102 ;
V_104 = F_59 ( V_102 ) ;
F_60 ( & V_104 -> V_109 . V_110 -> V_111 ) ;
if ( V_104 -> V_109 . V_112 )
V_73 -> V_86 = F_61 ( V_104 -> V_109 . V_112 ) ;
F_62 ( & V_104 -> V_109 . V_110 -> V_111 ) ;
F_63 ( & V_73 -> V_73 , F_35 ) ;
F_45 ( & V_5 -> V_84 , V_79 ) ;
if ( V_3 -> V_85 ) {
F_64 ( L_4 ) ;
V_74 = - V_113 ;
goto V_114;
}
V_3 -> V_85 = V_73 ;
V_3 -> V_87 = 0 ;
F_47 ( & V_5 -> V_84 , V_79 ) ;
F_64 ( L_5 ,
V_73 -> V_75 , V_104 ) ;
V_74 = F_37 ( V_104 , false ) ;
if ( F_40 ( V_74 != 0 ) ) {
F_41 ( L_6 ) ;
goto V_115;
}
V_74 = F_65 ( V_104 , V_116 ,
F_28 ( V_7 ) ? 0 : 1 << 27 , & V_90 ) ;
if ( F_40 ( V_74 != 0 ) ) {
F_42 ( V_104 ) ;
V_74 = - V_117 ;
F_41 ( L_7 ) ;
goto V_115;
}
F_66 ( V_104 , & V_105 , NULL ) ;
F_42 ( V_104 ) ;
if ( ! F_28 ( V_7 ) ) {
V_90 -= V_3 -> V_118 ;
V_106 = V_95 -> V_119 [ 0 ] / ( V_95 -> V_120 / 8 ) ;
if ( V_105 & V_121 ) {
if ( F_67 ( V_7 ) ) {
V_90 &= ~ 0x7ff ;
} else {
int V_122 = V_95 -> V_120 >> 4 ;
int V_123 = ( ( ( V_2 -> V_124 >> 3 ) * V_106 + V_2 -> V_125 ) >> ( 8 - V_122 ) ) << 11 ;
V_90 += V_123 + ( ( V_2 -> V_125 << V_122 ) % 256 ) + ( ( V_2 -> V_124 % 8 ) << 8 ) ;
}
} else {
int V_126 = V_2 -> V_124 * V_106 + V_2 -> V_125 ;
switch ( V_95 -> V_120 ) {
case 8 :
default:
V_126 *= 1 ;
break;
case 15 :
case 16 :
V_126 *= 2 ;
break;
case 24 :
V_126 *= 3 ;
break;
case 32 :
V_126 *= 4 ;
break;
}
V_90 += V_126 ;
}
V_90 &= ~ 7 ;
}
F_45 ( & V_5 -> V_84 , V_79 ) ;
V_73 -> V_88 = V_90 ;
F_47 ( & V_5 -> V_84 , V_79 ) ;
V_2 -> V_95 = V_95 ;
V_74 = F_68 ( V_5 , V_3 -> V_10 ) ;
if ( V_74 ) {
F_41 ( L_8 ) ;
goto V_127;
}
F_69 ( V_7 , V_3 -> V_10 ) ;
return 0 ;
V_127:
if ( F_40 ( F_37 ( V_104 , false ) != 0 ) ) {
F_41 ( L_9 ) ;
goto V_115;
}
if ( F_40 ( F_39 ( V_104 ) != 0 ) ) {
F_41 ( L_10 ) ;
}
F_42 ( V_104 ) ;
V_115:
F_45 ( & V_5 -> V_84 , V_79 ) ;
V_3 -> V_85 = NULL ;
V_114:
F_47 ( & V_5 -> V_84 , V_79 ) ;
F_43 ( V_99 -> V_102 ) ;
F_52 ( & V_73 -> V_86 ) ;
F_34 ( V_73 ) ;
return V_74 ;
}
static int
F_70 ( struct V_128 * V_129 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
bool V_130 = false ;
int V_131 ;
if ( ! V_129 || ! V_129 -> V_2 )
return - V_117 ;
V_5 = V_129 -> V_2 -> V_5 ;
V_131 = F_71 ( V_5 -> V_5 ) ;
if ( V_131 < 0 )
return V_131 ;
V_131 = F_72 ( V_129 ) ;
F_73 (crtc, &dev->mode_config.crtc_list, head)
if ( V_2 -> V_62 )
V_130 = true ;
F_74 ( V_5 -> V_5 ) ;
V_7 = V_5 -> V_8 ;
if ( V_130 && ! V_7 -> V_132 ) {
V_7 -> V_132 = true ;
return V_131 ;
}
if ( ! V_130 && V_7 -> V_132 ) {
F_75 ( V_5 -> V_5 ) ;
V_7 -> V_132 = false ;
}
F_75 ( V_5 -> V_5 ) ;
return V_131 ;
}
static void F_76 ( struct V_4 * V_5 , int V_133 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_3 * V_3 ;
int V_9 ;
V_3 = F_56 ( sizeof( struct V_3 ) + ( V_134 * sizeof( struct V_135 * ) ) , V_107 ) ;
if ( V_3 == NULL )
return;
F_77 ( V_5 , & V_3 -> V_90 , & V_136 ) ;
F_78 ( & V_3 -> V_90 , 256 ) ;
V_3 -> V_10 = V_133 ;
V_7 -> V_77 . V_78 [ V_133 ] = V_3 ;
if ( V_7 -> V_137 >= V_138 ) {
V_3 -> V_139 = V_140 ;
V_3 -> V_141 = V_142 ;
} else {
V_3 -> V_139 = V_143 ;
V_3 -> V_141 = V_144 ;
}
#if 0
radeon_crtc->mode_set.crtc = &radeon_crtc->base;
radeon_crtc->mode_set.connectors = (struct drm_connector **)(radeon_crtc + 1);
radeon_crtc->mode_set.num_connectors = 0;
#endif
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
V_3 -> V_24 [ V_9 ] = V_9 << 2 ;
V_3 -> V_25 [ V_9 ] = V_9 << 2 ;
V_3 -> V_26 [ V_9 ] = V_9 << 2 ;
}
if ( V_7 -> V_145 && ( F_28 ( V_7 ) || V_146 ) )
F_79 ( V_5 , V_3 ) ;
else
F_80 ( V_5 , V_3 ) ;
}
static void F_81 ( struct V_4 * V_5 )
{
struct V_135 * V_147 ;
struct V_148 * V_148 ;
struct V_149 * V_150 ;
struct V_151 * V_151 ;
T_1 V_152 ;
int V_9 = 0 ;
F_82 ( L_11 ) ;
F_73 (connector, &dev->mode_config.connector_list, head) {
V_148 = F_83 ( V_147 ) ;
F_82 ( L_12 , V_9 ) ;
F_82 ( L_13 , F_84 ( V_147 ) ) ;
if ( V_148 -> V_153 . V_153 != V_154 )
F_82 ( L_13 , V_155 [ V_148 -> V_153 . V_153 ] ) ;
if ( V_148 -> V_156 ) {
F_82 ( L_14 ,
V_148 -> V_156 -> V_157 . V_158 ,
V_148 -> V_156 -> V_157 . V_159 ,
V_148 -> V_156 -> V_157 . V_160 ,
V_148 -> V_156 -> V_157 . V_161 ,
V_148 -> V_156 -> V_157 . V_162 ,
V_148 -> V_156 -> V_157 . V_163 ,
V_148 -> V_156 -> V_157 . V_164 ,
V_148 -> V_156 -> V_157 . V_165 ) ;
if ( V_148 -> V_166 . V_167 )
F_82 ( L_15 ,
V_148 -> V_166 . V_168 ,
V_148 -> V_166 . V_169 ) ;
if ( V_148 -> V_166 . V_170 )
F_82 ( L_16 ,
V_148 -> V_166 . V_171 ,
V_148 -> V_166 . V_172 ) ;
} else {
if ( V_147 -> V_173 == V_174 ||
V_147 -> V_173 == V_175 ||
V_147 -> V_173 == V_176 ||
V_147 -> V_173 == V_177 ||
V_147 -> V_173 == V_178 ||
V_147 -> V_173 == V_179 )
F_82 ( L_17 ) ;
}
F_82 ( L_18 ) ;
F_73 (encoder, &dev->mode_config.encoder_list, head) {
V_151 = F_85 ( V_150 ) ;
V_152 = V_151 -> V_152 & V_148 -> V_152 ;
if ( V_152 ) {
if ( V_152 & V_180 )
F_82 ( L_19 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_183 )
F_82 ( L_20 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_184 )
F_82 ( L_21 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_185 )
F_82 ( L_22 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_186 )
F_82 ( L_23 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_187 )
F_82 ( L_24 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_188 )
F_82 ( L_25 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_189 )
F_82 ( L_26 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_190 )
F_82 ( L_27 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_191 )
F_82 ( L_28 , V_181 [ V_151 -> V_182 ] ) ;
if ( V_152 & V_192 )
F_82 ( L_29 , V_181 [ V_151 -> V_182 ] ) ;
}
}
V_9 ++ ;
}
}
static bool F_86 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
bool V_131 = false ;
if ( V_7 -> V_193 ) {
if ( V_7 -> V_145 ) {
V_131 = F_87 ( V_5 ) ;
if ( V_131 == false )
V_131 = F_88 ( V_5 ) ;
} else {
V_131 = F_89 ( V_5 ) ;
if ( V_131 == false )
V_131 = F_90 ( V_5 ) ;
}
} else {
if ( ! F_28 ( V_7 ) )
V_131 = F_90 ( V_5 ) ;
}
if ( V_131 ) {
F_91 ( V_5 ) ;
F_81 ( V_5 ) ;
}
return V_131 ;
}
int F_92 ( struct V_148 * V_148 )
{
struct V_4 * V_5 = V_148 -> V_90 . V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_131 = 0 ;
if ( V_148 -> V_166 . V_167 )
F_93 ( V_148 ) ;
if ( F_94 ( & V_148 -> V_90 ) !=
V_194 ) {
struct V_195 * V_196 = V_148 -> V_197 ;
if ( V_196 -> V_198 )
V_148 -> V_199 = F_95 ( & V_148 -> V_90 ,
& V_196 -> V_198 -> V_200 ) ;
} else if ( ( V_148 -> V_90 . V_173 == V_201 ) ||
( V_148 -> V_90 . V_173 == V_202 ) ) {
struct V_195 * V_196 = V_148 -> V_197 ;
if ( ( V_196 -> V_203 == V_204 ||
V_196 -> V_203 == V_205 ) && V_196 -> V_198 )
V_148 -> V_199 = F_95 ( & V_148 -> V_90 ,
& V_196 -> V_198 -> V_200 ) ;
else if ( V_148 -> V_156 && ! V_148 -> V_199 )
V_148 -> V_199 = F_95 ( & V_148 -> V_90 ,
& V_148 -> V_156 -> V_200 ) ;
} else {
if ( V_148 -> V_156 && ! V_148 -> V_199 )
V_148 -> V_199 = F_95 ( & V_148 -> V_90 ,
& V_148 -> V_156 -> V_200 ) ;
}
if ( ! V_148 -> V_199 ) {
if ( V_7 -> V_145 ) {
if ( ( ( V_148 -> V_90 . V_173 == V_206 ) ||
( V_148 -> V_90 . V_173 == V_202 ) ) )
V_148 -> V_199 = F_96 ( V_7 ) ;
} else
V_148 -> V_199 = F_96 ( V_7 ) ;
}
if ( V_148 -> V_199 ) {
F_97 ( & V_148 -> V_90 , V_148 -> V_199 ) ;
V_131 = F_98 ( & V_148 -> V_90 , V_148 -> V_199 ) ;
return V_131 ;
}
F_97 ( & V_148 -> V_90 , NULL ) ;
return 0 ;
}
static void F_99 ( struct V_207 * V_208 ,
T_3 V_209 ,
T_3 V_210 ,
T_3 V_211 ,
T_3 * V_212 ,
T_3 * V_213 )
{
T_3 V_214 = V_210 * V_211 ;
V_214 *= V_209 ;
* V_212 = V_214 / V_208 -> V_215 ;
* V_213 = V_214 % V_208 -> V_215 ;
if ( * V_212 > V_208 -> V_216 )
* V_212 = V_208 -> V_216 ;
else if ( * V_212 < V_208 -> V_217 )
* V_212 = V_208 -> V_217 ;
}
static T_3 F_100 ( struct V_207 * V_208 ,
T_3 V_209 )
{
T_3 V_218 , V_210 , V_214 ;
if ( V_208 -> V_79 & V_219 )
return V_208 -> V_210 ;
if ( V_208 -> V_79 & V_220 ) {
if ( V_208 -> V_79 & V_221 )
V_218 = V_208 -> V_222 ;
else
V_218 = V_208 -> V_223 ;
} else {
if ( V_208 -> V_79 & V_221 )
V_218 = V_208 -> V_224 ;
else
V_218 = V_208 -> V_225 ;
}
V_210 = V_218 / V_209 ;
V_214 = V_218 % V_209 ;
if ( V_208 -> V_79 & V_220 ) {
if ( V_214 )
V_210 ++ ;
} else {
if ( ! V_214 )
V_210 -- ;
}
if ( V_210 > V_208 -> V_226 )
V_210 = V_208 -> V_226 ;
else if ( V_210 < V_208 -> V_227 )
V_210 = V_208 -> V_227 ;
return V_210 ;
}
void F_101 ( struct V_207 * V_208 ,
T_3 V_228 ,
T_3 * V_229 ,
T_3 * V_230 ,
T_3 * V_231 ,
T_3 * V_232 ,
T_3 * V_233 )
{
T_3 V_209 = V_228 / 10 ;
T_3 V_210 = F_100 ( V_208 , V_209 ) ;
T_3 V_211 = V_208 -> V_234 ;
T_3 V_212 = 0 , V_213 = 0 , V_214 ;
if ( V_208 -> V_79 & V_235 )
V_211 = V_208 -> V_236 ;
if ( V_208 -> V_79 & V_237 ) {
F_99 ( V_208 , V_209 , V_210 , V_211 , & V_212 , & V_213 ) ;
V_213 = ( 100 * V_213 ) / V_208 -> V_215 ;
if ( V_213 >= 5 ) {
V_213 -= 5 ;
V_213 = V_213 / 10 ;
V_213 ++ ;
}
if ( V_213 >= 10 ) {
V_212 ++ ;
V_213 = 0 ;
}
} else {
while ( V_211 <= V_208 -> V_238 ) {
F_99 ( V_208 , V_209 , V_210 , V_211 ,
& V_212 , & V_213 ) ;
if ( V_213 >= ( V_208 -> V_215 / 2 ) )
V_212 ++ ;
V_213 = 0 ;
V_214 = ( V_208 -> V_215 * V_212 ) / ( V_210 * V_211 ) ;
V_214 = ( V_214 * 10000 ) / V_209 ;
if ( V_214 > ( 10000 + V_239 ) )
V_211 ++ ;
else if ( V_214 >= ( 10000 - V_239 ) )
break;
else
V_211 ++ ;
}
}
* V_229 = ( ( V_208 -> V_215 * V_212 * 10 ) + ( V_208 -> V_215 * V_213 ) ) /
( V_211 * V_210 * 10 ) ;
* V_230 = V_212 ;
* V_231 = V_213 ;
* V_232 = V_211 ;
* V_233 = V_210 ;
F_3 ( L_30 ,
* V_229 , V_212 , V_213 , V_211 , V_210 ) ;
}
static inline T_1 F_102 ( T_5 V_240 , T_1 V_241 )
{
T_5 V_242 ;
V_240 += V_241 / 2 ;
V_242 = F_103 ( V_240 , V_241 ) ;
return V_240 ;
}
void F_104 ( struct V_207 * V_208 ,
T_5 V_228 ,
T_1 * V_229 ,
T_1 * V_230 ,
T_1 * V_231 ,
T_1 * V_232 ,
T_1 * V_233 )
{
T_1 V_234 = V_208 -> V_234 ;
T_1 V_238 = V_208 -> V_238 ;
T_1 V_227 = V_208 -> V_227 ;
T_1 V_226 = V_208 -> V_226 ;
T_1 V_243 = 0 ;
T_1 V_244 = 0 ;
T_1 V_245 = V_208 -> V_245 ;
T_1 V_246 = 1 ;
T_1 V_247 = 1 ;
T_1 V_248 = 1 ;
T_1 V_249 = 0 ;
T_1 V_250 = - 1 ;
T_1 V_251 = 0xffffffff ;
T_1 V_252 = 1 ;
T_1 V_210 ;
T_3 V_223 , V_225 ;
F_3 ( L_31 , V_228 , V_208 -> V_234 , V_208 -> V_238 ) ;
V_228 = V_228 * 1000 ;
if ( V_208 -> V_79 & V_221 ) {
V_223 = V_208 -> V_222 ;
V_225 = V_208 -> V_224 ;
} else {
V_223 = V_208 -> V_223 ;
V_225 = V_208 -> V_225 ;
}
if ( V_223 > 64800 )
V_223 = 64800 ;
if ( V_208 -> V_79 & V_235 )
V_234 = V_238 = V_208 -> V_236 ;
else {
while ( V_234 < V_238 - 1 ) {
T_1 V_253 = ( V_234 + V_238 ) / 2 ;
T_1 V_254 = V_208 -> V_215 / V_253 ;
if ( V_254 < V_208 -> V_255 )
V_238 = V_253 ;
else if ( V_254 > V_208 -> V_256 )
V_234 = V_253 ;
else
break;
}
}
if ( V_208 -> V_79 & V_219 )
V_227 = V_226 = V_208 -> V_210 ;
if ( V_208 -> V_79 & V_237 ) {
V_243 = V_208 -> V_257 ;
V_244 = V_208 -> V_258 ;
}
for ( V_210 = V_226 ; V_210 >= V_227 ; -- V_210 ) {
T_1 V_211 ;
if ( ( V_208 -> V_79 & V_259 ) && ( V_210 & 1 ) )
continue;
if ( V_208 -> V_79 & V_260 ) {
if ( ( V_210 == 5 ) ||
( V_210 == 7 ) ||
( V_210 == 9 ) ||
( V_210 == 10 ) ||
( V_210 == 11 ) ||
( V_210 == 13 ) ||
( V_210 == 14 ) ||
( V_210 == 15 ) )
continue;
}
for ( V_211 = V_234 ; V_211 <= V_238 ; ++ V_211 ) {
T_1 V_261 , V_262 = 0 , error , V_263 ;
T_1 V_254 = V_208 -> V_215 / V_211 ;
T_1 V_264 = V_208 -> V_217 ;
T_1 V_265 = V_208 -> V_216 + 1 ;
if ( V_254 < V_208 -> V_255 || V_254 > V_208 -> V_256 )
continue;
while ( V_264 < V_265 ) {
T_1 V_218 ;
T_1 V_266 = V_243 ;
T_1 V_267 = V_244 + 1 ;
T_1 V_268 ;
T_5 V_214 ;
V_261 = ( V_264 + V_265 ) / 2 ;
V_214 = ( T_5 ) V_208 -> V_215 * V_261 ;
V_218 = F_102 ( V_214 , V_211 ) ;
if ( V_218 < V_223 ) {
V_264 = V_261 + 1 ;
continue;
} else if ( V_218 > V_225 ) {
V_265 = V_261 ;
continue;
}
while ( V_266 < V_267 ) {
V_268 = ( V_266 + V_267 ) / 2 ;
V_214 = ( T_5 ) V_208 -> V_215 * 10000 * V_261 ;
V_214 += ( T_5 ) V_208 -> V_215 * 1000 * V_268 ;
V_262 = F_102 ( V_214 , V_211 * V_210 ) ;
if ( V_208 -> V_79 & V_269 ) {
if ( V_228 < V_262 )
error = 0xffffffff ;
else
error = V_228 - V_262 ;
} else
error = abs ( V_262 - V_228 ) ;
V_263 = abs ( V_218 - V_245 ) ;
if ( ( V_245 == 0 && error < V_251 ) ||
( V_245 != 0 &&
( ( V_251 > 100 && error < V_251 - 100 ) ||
( abs ( error - V_251 ) < 100 && V_263 < V_252 ) ) ) ) {
V_246 = V_210 ;
V_247 = V_211 ;
V_248 = V_261 ;
V_249 = V_268 ;
V_250 = V_262 ;
V_251 = error ;
V_252 = V_263 ;
} else if ( V_262 == V_228 ) {
if ( V_250 == - 1 ) {
V_246 = V_210 ;
V_247 = V_211 ;
V_248 = V_261 ;
V_249 = V_268 ;
V_250 = V_262 ;
V_251 = error ;
V_252 = V_263 ;
} else if ( ( ( V_208 -> V_79 & V_270 ) && ( V_211 < V_247 ) ) ||
( ( V_208 -> V_79 & V_271 ) && ( V_211 > V_247 ) ) ||
( ( V_208 -> V_79 & V_272 ) && ( V_261 < V_248 ) ) ||
( ( V_208 -> V_79 & V_273 ) && ( V_261 > V_248 ) ) ||
( ( V_208 -> V_79 & V_274 ) && ( V_210 < V_246 ) ) ||
( ( V_208 -> V_79 & V_275 ) && ( V_210 > V_246 ) ) ) {
V_246 = V_210 ;
V_247 = V_211 ;
V_248 = V_261 ;
V_249 = V_268 ;
V_250 = V_262 ;
V_251 = error ;
V_252 = V_263 ;
}
}
if ( V_262 < V_228 )
V_266 = V_268 + 1 ;
else
V_267 = V_268 ;
}
if ( V_262 < V_228 )
V_264 = V_261 + 1 ;
else
V_265 = V_261 ;
}
}
}
* V_229 = V_250 / 10000 ;
* V_230 = V_248 ;
* V_231 = V_249 ;
* V_232 = V_247 ;
* V_233 = V_246 ;
F_3 ( L_32 ,
( long long ) V_228 ,
V_250 / 1000 , V_248 , V_249 ,
V_247 , V_246 ) ;
}
static void F_105 ( struct V_94 * V_95 )
{
struct V_98 * V_276 = F_57 ( V_95 ) ;
if ( V_276 -> V_102 ) {
F_43 ( V_276 -> V_102 ) ;
}
F_106 ( V_95 ) ;
F_34 ( V_276 ) ;
}
static int F_107 ( struct V_94 * V_95 ,
struct V_277 * V_278 ,
unsigned int * V_279 )
{
struct V_98 * V_276 = F_57 ( V_95 ) ;
return F_108 ( V_278 , V_276 -> V_102 , V_279 ) ;
}
int
F_109 ( struct V_4 * V_5 ,
struct V_98 * V_280 ,
struct V_281 * V_282 ,
struct V_101 * V_102 )
{
int V_131 ;
V_280 -> V_102 = V_102 ;
F_110 ( & V_280 -> V_90 , V_282 ) ;
V_131 = F_111 ( V_5 , & V_280 -> V_90 , & V_283 ) ;
if ( V_131 ) {
V_280 -> V_102 = NULL ;
return V_131 ;
}
return 0 ;
}
static struct V_94 *
F_112 ( struct V_4 * V_5 ,
struct V_277 * V_278 ,
struct V_281 * V_282 )
{
struct V_101 * V_102 ;
struct V_98 * V_276 ;
int V_131 ;
V_102 = F_113 ( V_5 , V_278 , V_282 -> V_284 [ 0 ] ) ;
if ( V_102 == NULL ) {
F_114 ( & V_5 -> V_285 -> V_5 , L_33
L_34 , V_282 -> V_284 [ 0 ] ) ;
return F_115 ( - V_286 ) ;
}
V_276 = F_56 ( sizeof( * V_276 ) , V_107 ) ;
if ( V_276 == NULL ) {
F_43 ( V_102 ) ;
return F_115 ( - V_108 ) ;
}
V_131 = F_109 ( V_5 , V_276 , V_282 , V_102 ) ;
if ( V_131 ) {
F_34 ( V_276 ) ;
F_43 ( V_102 ) ;
return F_115 ( V_131 ) ;
}
return & V_276 -> V_90 ;
}
static void F_116 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_117 ( V_7 ) ;
}
static int F_118 ( struct V_6 * V_7 )
{
int V_287 ;
if ( V_7 -> V_145 ) {
V_7 -> V_77 . V_288 =
F_119 ( V_7 -> V_83 , 0 , L_35 , 0 , 1 ) ;
if ( ! V_7 -> V_77 . V_288 )
return - V_108 ;
}
if ( ! F_28 ( V_7 ) ) {
V_287 = F_120 ( V_289 ) ;
V_7 -> V_77 . V_290 =
F_121 ( V_7 -> V_83 , 0 ,
L_36 ,
V_289 , V_287 ) ;
}
V_7 -> V_77 . V_291 =
F_119 ( V_7 -> V_83 , 0 , L_37 , 0 , 1 ) ;
if ( ! V_7 -> V_77 . V_291 )
return - V_108 ;
F_122 ( V_7 -> V_83 ) ;
V_287 = F_120 ( V_292 ) ;
V_7 -> V_77 . V_293 =
F_121 ( V_7 -> V_83 , 0 ,
L_38 ,
V_292 , V_287 ) ;
V_287 = F_120 ( V_294 ) ;
V_7 -> V_77 . V_295 =
F_121 ( V_7 -> V_83 , 0 ,
L_39 ,
V_294 , V_287 ) ;
V_7 -> V_77 . V_296 =
F_119 ( V_7 -> V_83 , 0 ,
L_40 , 0 , 128 ) ;
if ( ! V_7 -> V_77 . V_296 )
return - V_108 ;
V_7 -> V_77 . V_297 =
F_119 ( V_7 -> V_83 , 0 ,
L_41 , 0 , 128 ) ;
if ( ! V_7 -> V_77 . V_297 )
return - V_108 ;
V_287 = F_120 ( V_298 ) ;
V_7 -> V_77 . V_299 =
F_121 ( V_7 -> V_83 , 0 ,
L_42 ,
V_298 , V_287 ) ;
V_287 = F_120 ( V_300 ) ;
V_7 -> V_77 . V_301 =
F_121 ( V_7 -> V_83 , 0 ,
L_43 ,
V_300 , V_287 ) ;
return 0 ;
}
void F_123 ( struct V_6 * V_7 )
{
if ( ( V_302 == 0 ) || ( V_302 > 2 ) ) {
if ( ( F_67 ( V_7 ) || ( V_7 -> V_137 == V_303 ) ) &&
! ( V_7 -> V_79 & V_304 ) )
V_7 -> V_305 = 2 ;
else
V_7 -> V_305 = 0 ;
} else
V_7 -> V_305 = V_302 ;
}
static void F_124 ( struct V_6 * V_7 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_306 ; V_9 ++ )
V_7 -> V_77 . V_307 [ V_9 ] = NULL ;
if ( F_125 ( V_7 ) ) {
} else if ( F_27 ( V_7 ) ) {
static T_1 V_308 [] = {
V_309 ,
V_310 ,
V_311 ,
V_312 ,
V_313 ,
V_314 ,
0x13830 - 0x7030 ,
} ;
int V_315 ;
if ( F_22 ( V_7 ) )
V_315 = 7 ;
else if ( F_126 ( V_7 ) )
V_315 = 6 ;
else if ( F_26 ( V_7 ) )
V_315 = 6 ;
else if ( F_127 ( V_7 ) )
V_315 = 2 ;
else
V_315 = 6 ;
F_128 ( V_315 > F_120 ( V_308 ) ) ;
for ( V_9 = 0 ; V_9 < V_315 ; V_9 ++ ) {
V_7 -> V_77 . V_307 [ V_9 ] = F_56 ( sizeof( struct V_316 ) , V_107 ) ;
if ( V_7 -> V_77 . V_307 [ V_9 ] ) {
V_7 -> V_77 . V_307 [ V_9 ] -> V_126 = V_308 [ V_9 ] ;
V_7 -> V_77 . V_307 [ V_9 ] -> V_317 = V_9 ;
}
}
} else if ( F_129 ( V_7 ) ) {
V_7 -> V_77 . V_307 [ 0 ] = F_56 ( sizeof( struct V_316 ) , V_107 ) ;
if ( V_7 -> V_77 . V_307 [ 0 ] ) {
V_7 -> V_77 . V_307 [ 0 ] -> V_126 = V_318 ;
V_7 -> V_77 . V_307 [ 0 ] -> V_317 = 0 ;
}
V_7 -> V_77 . V_307 [ 1 ] = F_56 ( sizeof( struct V_316 ) , V_107 ) ;
if ( V_7 -> V_77 . V_307 [ 1 ] ) {
V_7 -> V_77 . V_307 [ 1 ] -> V_126 = V_319 ;
V_7 -> V_77 . V_307 [ 1 ] -> V_317 = 1 ;
}
} else if ( F_130 ( V_7 ) ) {
V_7 -> V_77 . V_307 [ 0 ] = F_56 ( sizeof( struct V_316 ) , V_107 ) ;
if ( V_7 -> V_77 . V_307 [ 0 ] ) {
V_7 -> V_77 . V_307 [ 0 ] -> V_126 = V_320 ;
V_7 -> V_77 . V_307 [ 0 ] -> V_317 = 0 ;
}
if ( V_7 -> V_137 >= V_321 ) {
V_7 -> V_77 . V_307 [ 1 ] = F_56 ( sizeof( struct V_316 ) , V_107 ) ;
if ( V_7 -> V_77 . V_307 [ 1 ] ) {
V_7 -> V_77 . V_307 [ 1 ] -> V_126 = V_322 ;
V_7 -> V_77 . V_307 [ 1 ] -> V_317 = 1 ;
}
}
}
}
static void F_131 ( struct V_6 * V_7 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_306 ; V_9 ++ ) {
F_34 ( V_7 -> V_77 . V_307 [ V_9 ] ) ;
V_7 -> V_77 . V_307 [ V_9 ] = NULL ;
}
}
int F_132 ( struct V_6 * V_7 )
{
int V_9 ;
int V_131 ;
F_133 ( V_7 -> V_83 ) ;
V_7 -> V_77 . V_323 = true ;
V_7 -> V_83 -> V_324 . V_325 = & V_326 ;
if ( F_26 ( V_7 ) ) {
V_7 -> V_83 -> V_324 . V_327 = 16384 ;
V_7 -> V_83 -> V_324 . V_328 = 16384 ;
} else if ( F_28 ( V_7 ) ) {
V_7 -> V_83 -> V_324 . V_327 = 8192 ;
V_7 -> V_83 -> V_324 . V_328 = 8192 ;
} else {
V_7 -> V_83 -> V_324 . V_327 = 4096 ;
V_7 -> V_83 -> V_324 . V_328 = 4096 ;
}
V_7 -> V_83 -> V_324 . V_329 = 24 ;
V_7 -> V_83 -> V_324 . V_330 = 1 ;
V_7 -> V_83 -> V_324 . V_331 = V_7 -> V_332 . V_333 ;
V_131 = F_118 ( V_7 ) ;
if ( V_131 ) {
return V_131 ;
}
F_134 ( V_7 ) ;
if ( ! V_7 -> V_145 ) {
F_135 ( V_7 ) ;
}
for ( V_9 = 0 ; V_9 < V_7 -> V_334 ; V_9 ++ ) {
F_76 ( V_7 -> V_83 , V_9 ) ;
}
V_131 = F_86 ( V_7 -> V_83 ) ;
if ( ! V_131 ) {
return V_131 ;
}
if ( V_7 -> V_145 ) {
F_136 ( V_7 ) ;
F_137 ( V_7 ) ;
}
F_138 ( V_7 ) ;
F_124 ( V_7 ) ;
F_139 ( V_7 ) ;
F_140 ( V_7 ) ;
F_141 ( V_7 -> V_83 ) ;
return 0 ;
}
void F_142 ( struct V_6 * V_7 )
{
F_143 ( V_7 ) ;
F_34 ( V_7 -> V_77 . V_335 ) ;
F_144 ( V_7 ) ;
if ( V_7 -> V_77 . V_323 ) {
F_131 ( V_7 ) ;
F_145 ( V_7 -> V_83 ) ;
F_146 ( V_7 ) ;
F_147 ( V_7 -> V_83 ) ;
V_7 -> V_77 . V_323 = false ;
}
F_148 ( V_7 ) ;
}
static bool F_149 ( const struct V_336 * V_337 )
{
if ( ( V_337 -> V_338 == 480 && V_337 -> V_339 == 720 ) ||
( V_337 -> V_338 == 576 ) ||
( V_337 -> V_338 == 720 ) ||
( V_337 -> V_338 == 1080 ) )
return true ;
else
return false ;
}
bool F_150 ( struct V_1 * V_2 ,
const struct V_336 * V_337 ,
struct V_336 * V_340 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_149 * V_150 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_151 * V_151 ;
struct V_135 * V_147 ;
struct V_148 * V_148 ;
bool V_341 = true ;
T_3 V_342 = 1 , V_343 = 1 ;
T_3 V_344 = 1 , V_345 = 1 ;
V_3 -> V_346 = 0 ;
V_3 -> V_347 = 0 ;
F_73 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_150 -> V_2 != V_2 )
continue;
V_151 = F_85 ( V_150 ) ;
V_147 = F_151 ( V_150 ) ;
V_148 = F_83 ( V_147 ) ;
if ( V_341 ) {
if ( V_151 -> V_348 == V_349 )
V_3 -> V_348 = V_349 ;
else if ( V_337 -> V_339 < V_151 -> V_350 . V_339 ||
V_337 -> V_338 < V_151 -> V_350 . V_338 )
V_3 -> V_348 = V_151 -> V_348 ;
else
V_3 -> V_348 = V_349 ;
memcpy ( & V_3 -> V_350 ,
& V_151 -> V_350 ,
sizeof( struct V_336 ) ) ;
V_342 = V_2 -> V_337 . V_338 ;
V_343 = V_3 -> V_350 . V_338 ;
V_344 = V_2 -> V_337 . V_339 ;
V_345 = V_3 -> V_350 . V_339 ;
if ( F_28 ( V_7 ) &&
( ! ( V_337 -> V_79 & V_351 ) ) &&
( ( V_151 -> V_352 == V_353 ) ||
( ( V_151 -> V_352 == V_354 ) &&
F_152 ( V_148 -> V_199 ) &&
F_149 ( V_337 ) ) ) ) {
if ( V_151 -> V_355 != 0 )
V_3 -> V_346 = V_151 -> V_355 ;
else
V_3 -> V_346 = ( V_337 -> V_339 >> 5 ) + 16 ;
if ( V_151 -> V_356 != 0 )
V_3 -> V_347 = V_151 -> V_356 ;
else
V_3 -> V_347 = ( V_337 -> V_338 >> 5 ) + 16 ;
V_3 -> V_348 = V_357 ;
V_342 = V_2 -> V_337 . V_338 ;
V_343 = V_2 -> V_337 . V_338 - ( V_3 -> V_347 * 2 ) ;
V_344 = V_2 -> V_337 . V_339 ;
V_345 = V_2 -> V_337 . V_339 - ( V_3 -> V_346 * 2 ) ;
}
V_341 = false ;
} else {
if ( V_3 -> V_348 != V_151 -> V_348 ) {
F_41 ( L_44 ) ;
return false ;
}
}
}
if ( V_3 -> V_348 != V_349 ) {
T_6 V_358 , V_359 ;
V_358 . V_360 = F_153 ( V_342 ) ;
V_359 . V_360 = F_153 ( V_343 ) ;
V_3 -> V_361 . V_360 = F_154 ( V_358 , V_359 ) ;
V_358 . V_360 = F_153 ( V_344 ) ;
V_359 . V_360 = F_153 ( V_345 ) ;
V_3 -> V_362 . V_360 = F_154 ( V_358 , V_359 ) ;
} else {
V_3 -> V_361 . V_360 = F_153 ( 1 ) ;
V_3 -> V_362 . V_360 = F_153 ( 1 ) ;
}
return true ;
}
int F_49 ( struct V_4 * V_5 , int V_2 , int * V_81 , int * V_82 ,
T_7 * V_363 , T_7 * V_364 )
{
T_3 V_365 = 0 , V_366 = 0 , V_367 = 0 ;
int V_368 , V_369 , V_370 , V_131 = 0 ;
bool V_371 = true ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_363 )
* V_363 = F_155 () ;
if ( F_27 ( V_7 ) ) {
if ( V_2 == 0 ) {
V_366 = F_24 ( V_372 +
V_309 ) ;
V_367 = F_24 ( V_373 +
V_309 ) ;
V_131 |= V_89 ;
}
if ( V_2 == 1 ) {
V_366 = F_24 ( V_372 +
V_310 ) ;
V_367 = F_24 ( V_373 +
V_310 ) ;
V_131 |= V_89 ;
}
if ( V_2 == 2 ) {
V_366 = F_24 ( V_372 +
V_311 ) ;
V_367 = F_24 ( V_373 +
V_311 ) ;
V_131 |= V_89 ;
}
if ( V_2 == 3 ) {
V_366 = F_24 ( V_372 +
V_312 ) ;
V_367 = F_24 ( V_373 +
V_312 ) ;
V_131 |= V_89 ;
}
if ( V_2 == 4 ) {
V_366 = F_24 ( V_372 +
V_313 ) ;
V_367 = F_24 ( V_373 +
V_313 ) ;
V_131 |= V_89 ;
}
if ( V_2 == 5 ) {
V_366 = F_24 ( V_372 +
V_314 ) ;
V_367 = F_24 ( V_373 +
V_314 ) ;
V_131 |= V_89 ;
}
} else if ( F_28 ( V_7 ) ) {
if ( V_2 == 0 ) {
V_366 = F_24 ( V_374 ) ;
V_367 = F_24 ( V_375 ) ;
V_131 |= V_89 ;
}
if ( V_2 == 1 ) {
V_366 = F_24 ( V_376 ) ;
V_367 = F_24 ( V_377 ) ;
V_131 |= V_89 ;
}
} else {
if ( V_2 == 0 ) {
V_366 = ( F_24 ( V_378 ) &
V_379 ) >> V_380 ;
V_367 = ( F_24 ( V_381 ) >> 16 ) & V_382 ;
V_365 = F_24 ( V_383 ) ;
if ( ! ( V_365 & 1 ) )
V_371 = false ;
V_131 |= V_89 ;
}
if ( V_2 == 1 ) {
V_366 = ( F_24 ( V_384 ) &
V_379 ) >> V_380 ;
V_367 = ( F_24 ( V_385 ) >> 16 ) & V_382 ;
V_365 = F_24 ( V_386 ) ;
if ( ! ( V_365 & 1 ) )
V_371 = false ;
V_131 |= V_89 ;
}
}
if ( V_364 )
* V_364 = F_155 () ;
* V_81 = V_367 & 0x1fff ;
* V_82 = ( V_367 >> 16 ) & 0x1fff ;
if ( V_366 > 0 ) {
V_131 |= V_387 ;
V_368 = V_366 & 0x1fff ;
V_369 = ( V_366 >> 16 ) & 0x1fff ;
}
else {
V_368 = V_7 -> V_77 . V_78 [ V_2 ] -> V_90 . V_91 . V_92 ;
V_369 = 0 ;
}
if ( ( * V_81 < V_368 ) && ( * V_81 >= V_369 ) )
V_371 = false ;
if ( V_371 && ( * V_81 >= V_368 ) ) {
V_370 = V_7 -> V_77 . V_78 [ V_2 ] -> V_90 . V_91 . V_388 ;
* V_81 = * V_81 - V_370 ;
}
* V_81 = * V_81 - V_369 ;
if ( V_371 )
V_131 |= V_389 ;
return V_131 ;
}
