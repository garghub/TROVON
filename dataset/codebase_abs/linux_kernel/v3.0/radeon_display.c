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
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
T_1 V_55 ;
V_55 = F_23 ( V_56 ) ;
if ( V_3 -> V_10 == 0 )
V_55 &= ( T_1 ) ~ V_57 ;
else
V_55 |= V_57 ;
F_4 ( V_56 , V_55 ) ;
F_5 ( V_58 , 0 ) ;
for ( V_9 = 0 ; V_9 < 256 ; V_9 ++ ) {
F_4 ( V_59 ,
( V_3 -> V_24 [ V_9 ] << 20 ) |
( V_3 -> V_25 [ V_9 ] << 10 ) |
( V_3 -> V_26 [ V_9 ] << 0 ) ) ;
}
}
void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ! V_2 -> V_60 )
return;
if ( F_25 ( V_7 ) )
F_7 ( V_2 ) ;
else if ( F_26 ( V_7 ) )
F_6 ( V_2 ) ;
else if ( F_27 ( V_7 ) )
F_1 ( V_2 ) ;
else
F_22 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 , T_2 V_61 , T_2 V_62 ,
T_2 V_63 , int V_64 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_24 [ V_64 ] = V_61 >> 6 ;
V_3 -> V_25 [ V_64 ] = V_62 >> 6 ;
V_3 -> V_26 [ V_64 ] = V_63 >> 6 ;
}
void F_29 ( struct V_1 * V_2 , T_2 * V_61 , T_2 * V_62 ,
T_2 * V_63 , int V_64 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
* V_61 = V_3 -> V_24 [ V_64 ] << 6 ;
* V_62 = V_3 -> V_25 [ V_64 ] << 6 ;
* V_63 = V_3 -> V_26 [ V_64 ] << 6 ;
}
static void F_30 ( struct V_1 * V_2 , T_2 * V_61 , T_2 * V_62 ,
T_2 * V_63 , T_1 V_65 , T_1 V_66 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_67 = ( V_65 + V_66 > 256 ) ? 256 : V_65 + V_66 , V_9 ;
for ( V_9 = V_65 ; V_9 < V_67 ; V_9 ++ ) {
V_3 -> V_24 [ V_9 ] = V_61 [ V_9 ] >> 6 ;
V_3 -> V_25 [ V_9 ] = V_62 [ V_9 ] >> 6 ;
V_3 -> V_26 [ V_9 ] = V_63 [ V_9 ] >> 6 ;
}
F_24 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_3 ) ;
}
static void F_34 ( struct V_68 * V_69 )
{
struct V_70 * V_71 =
F_35 ( V_69 , struct V_70 , V_71 ) ;
int V_72 ;
V_72 = F_36 ( V_71 -> V_73 , false ) ;
if ( F_37 ( V_72 == 0 ) ) {
V_72 = F_38 ( V_71 -> V_73 ) ;
if ( F_39 ( V_72 != 0 ) ) {
F_40 ( L_2 ) ;
}
F_41 ( V_71 -> V_73 ) ;
} else
F_40 ( L_3 ) ;
F_42 ( & V_71 -> V_73 -> V_74 ) ;
F_33 ( V_71 ) ;
}
void F_43 ( struct V_6 * V_7 , int V_10 )
{
struct V_3 * V_3 = V_7 -> V_75 . V_76 [ V_10 ] ;
struct V_70 * V_71 ;
struct V_77 * V_78 ;
struct V_79 V_80 ;
unsigned long V_81 ;
T_3 V_82 ;
int V_83 , V_84 ;
F_44 ( & V_7 -> V_85 -> V_86 , V_81 ) ;
V_71 = V_3 -> V_87 ;
if ( V_71 == NULL ||
! F_45 ( V_71 -> V_88 ) ) {
F_46 ( & V_7 -> V_85 -> V_86 , V_81 ) ;
return;
}
if ( ! V_3 -> V_89 ) {
V_82 = F_47 ( V_7 , V_10 , V_71 -> V_90 ) ;
} else {
V_82 = 0 ;
V_3 -> V_89 = 0 ;
}
if ( V_82 &&
( V_91 & F_48 ( V_7 -> V_85 , V_10 ,
& V_83 , & V_84 ) ) &&
( V_83 >= 0 ) &&
( V_83 < ( 99 * V_7 -> V_75 . V_76 [ V_10 ] -> V_92 . V_93 . V_94 ) / 100 ) ) {
V_3 -> V_89 = 1 ;
F_46 ( & V_7 -> V_85 -> V_86 , V_81 ) ;
return;
}
V_3 -> V_87 = NULL ;
if ( V_71 -> V_95 ) {
V_78 = V_71 -> V_95 ;
V_78 -> V_95 . V_96 = F_49 ( V_7 -> V_85 , V_10 , & V_80 ) ;
V_78 -> V_95 . V_97 = V_80 . V_97 ;
V_78 -> V_95 . V_98 = V_80 . V_98 ;
F_50 ( & V_78 -> V_92 . V_99 , & V_78 -> V_92 . V_100 -> V_101 ) ;
F_51 ( & V_78 -> V_92 . V_100 -> V_102 ) ;
}
F_46 ( & V_7 -> V_85 -> V_86 , V_81 ) ;
F_52 ( V_7 -> V_85 , V_3 -> V_10 ) ;
F_53 ( & V_71 -> V_88 ) ;
F_54 ( V_71 -> V_7 , V_71 -> V_10 ) ;
F_55 ( & V_71 -> V_71 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_103 * V_104 ,
struct V_77 * V_95 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_105 * V_106 ;
struct V_105 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_88 ;
struct V_70 * V_71 ;
unsigned long V_81 ;
T_3 V_113 , V_114 ;
T_4 V_92 ;
int V_72 ;
V_71 = F_57 ( sizeof *V_71 , V_115 ) ;
if ( V_71 == NULL )
return - V_116 ;
V_72 = F_58 ( V_7 , & V_88 ) ;
if ( F_39 ( V_72 != 0 ) ) {
F_33 ( V_71 ) ;
F_40 ( L_4 ) ;
return - V_116 ;
}
V_71 -> V_95 = V_95 ;
V_71 -> V_7 = V_7 ;
V_71 -> V_10 = V_3 -> V_10 ;
V_71 -> V_88 = F_59 ( V_88 ) ;
V_106 = F_60 ( V_2 -> V_104 ) ;
V_107 = F_60 ( V_104 ) ;
V_109 = V_106 -> V_109 ;
F_61 ( V_109 ) ;
V_111 = F_62 ( V_109 ) ;
V_71 -> V_73 = V_111 ;
F_63 ( & V_71 -> V_71 , F_34 ) ;
F_44 ( & V_5 -> V_86 , V_81 ) ;
if ( V_3 -> V_87 ) {
F_64 ( L_5 ) ;
V_72 = - V_117 ;
goto V_118;
}
V_3 -> V_87 = V_71 ;
V_3 -> V_89 = 0 ;
F_46 ( & V_5 -> V_86 , V_81 ) ;
V_109 = V_107 -> V_109 ;
V_111 = F_62 ( V_109 ) ;
F_64 ( L_6 ,
V_71 -> V_73 , V_111 ) ;
V_72 = F_36 ( V_111 , false ) ;
if ( F_39 ( V_72 != 0 ) ) {
F_40 ( L_7 ) ;
goto V_119;
}
V_72 = F_65 ( V_111 , V_120 , & V_92 ) ;
if ( F_39 ( V_72 != 0 ) ) {
F_41 ( V_111 ) ;
V_72 = - V_121 ;
F_40 ( L_8 ) ;
goto V_119;
}
F_66 ( V_111 , & V_113 , NULL ) ;
F_41 ( V_111 ) ;
if ( ! F_27 ( V_7 ) ) {
V_92 -= V_3 -> V_122 ;
V_114 = V_104 -> V_123 / ( V_104 -> V_124 / 8 ) ;
if ( V_113 & V_125 ) {
if ( F_67 ( V_7 ) ) {
V_92 &= ~ 0x7ff ;
} else {
int V_126 = V_104 -> V_124 >> 4 ;
int V_127 = ( ( ( V_2 -> V_128 >> 3 ) * V_114 + V_2 -> V_129 ) >> ( 8 - V_126 ) ) << 11 ;
V_92 += V_127 + ( ( V_2 -> V_129 << V_126 ) % 256 ) + ( ( V_2 -> V_128 % 8 ) << 8 ) ;
}
} else {
int V_130 = V_2 -> V_128 * V_114 + V_2 -> V_129 ;
switch ( V_104 -> V_124 ) {
case 8 :
default:
V_130 *= 1 ;
break;
case 15 :
case 16 :
V_130 *= 2 ;
break;
case 24 :
V_130 *= 3 ;
break;
case 32 :
V_130 *= 4 ;
break;
}
V_92 += V_130 ;
}
V_92 &= ~ 7 ;
}
F_44 ( & V_5 -> V_86 , V_81 ) ;
V_71 -> V_90 = V_92 ;
F_46 ( & V_5 -> V_86 , V_81 ) ;
V_2 -> V_104 = V_104 ;
V_72 = F_68 ( V_5 , V_3 -> V_10 ) ;
if ( V_72 ) {
F_40 ( L_9 ) ;
goto V_131;
}
V_72 = F_69 ( V_7 , 32 ) ;
if ( V_72 ) {
F_40 ( L_10 ) ;
goto V_132;
}
F_70 ( V_7 , V_88 ) ;
F_71 ( V_7 , V_3 -> V_10 ) ;
F_72 ( V_7 ) ;
return 0 ;
V_132:
F_52 ( V_5 , V_3 -> V_10 ) ;
V_131:
V_72 = F_36 ( V_111 , false ) ;
if ( F_39 ( V_72 != 0 ) ) {
F_40 ( L_11 ) ;
goto V_119;
}
V_72 = F_38 ( V_111 ) ;
if ( F_39 ( V_72 != 0 ) ) {
F_41 ( V_111 ) ;
V_72 = - V_121 ;
F_40 ( L_12 ) ;
goto V_119;
}
F_41 ( V_111 ) ;
V_119:
F_44 ( & V_5 -> V_86 , V_81 ) ;
V_3 -> V_87 = NULL ;
V_118:
F_42 ( V_106 -> V_109 ) ;
F_46 ( & V_5 -> V_86 , V_81 ) ;
F_53 ( & V_88 ) ;
F_33 ( V_71 ) ;
return V_72 ;
}
static void F_73 ( struct V_4 * V_5 , int V_133 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_3 * V_3 ;
int V_9 ;
V_3 = F_57 ( sizeof( struct V_3 ) + ( V_134 * sizeof( struct V_135 * ) ) , V_115 ) ;
if ( V_3 == NULL )
return;
F_74 ( V_5 , & V_3 -> V_92 , & V_136 ) ;
F_75 ( & V_3 -> V_92 , 256 ) ;
V_3 -> V_10 = V_133 ;
V_7 -> V_75 . V_76 [ V_133 ] = V_3 ;
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
if ( V_7 -> V_137 && ( F_27 ( V_7 ) || V_138 ) )
F_76 ( V_5 , V_3 ) ;
else
F_77 ( V_5 , V_3 ) ;
}
static void F_78 ( struct V_4 * V_5 )
{
struct V_135 * V_139 ;
struct V_140 * V_140 ;
struct V_141 * V_142 ;
struct V_143 * V_143 ;
T_1 V_144 ;
int V_9 = 0 ;
F_79 ( L_13 ) ;
F_80 (connector, &dev->mode_config.connector_list, head) {
V_140 = F_81 ( V_139 ) ;
F_79 ( L_14 , V_9 ) ;
F_79 ( L_15 , V_145 [ V_139 -> V_146 ] ) ;
if ( V_140 -> V_147 . V_147 != V_148 )
F_79 ( L_15 , V_149 [ V_140 -> V_147 . V_147 ] ) ;
if ( V_140 -> V_150 ) {
F_79 ( L_16 ,
V_140 -> V_150 -> V_151 . V_152 ,
V_140 -> V_150 -> V_151 . V_153 ,
V_140 -> V_150 -> V_151 . V_154 ,
V_140 -> V_150 -> V_151 . V_155 ,
V_140 -> V_150 -> V_151 . V_156 ,
V_140 -> V_150 -> V_151 . V_157 ,
V_140 -> V_150 -> V_151 . V_158 ,
V_140 -> V_150 -> V_151 . V_159 ) ;
if ( V_140 -> V_160 . V_161 )
F_79 ( L_17 ,
V_140 -> V_160 . V_162 ,
V_140 -> V_160 . V_163 ) ;
if ( V_140 -> V_160 . V_164 )
F_79 ( L_18 ,
V_140 -> V_160 . V_165 ,
V_140 -> V_160 . V_166 ) ;
} else {
if ( V_139 -> V_146 == V_167 ||
V_139 -> V_146 == V_168 ||
V_139 -> V_146 == V_169 ||
V_139 -> V_146 == V_170 ||
V_139 -> V_146 == V_171 ||
V_139 -> V_146 == V_172 )
F_79 ( L_19 ) ;
}
F_79 ( L_20 ) ;
F_80 (encoder, &dev->mode_config.encoder_list, head) {
V_143 = F_82 ( V_142 ) ;
V_144 = V_143 -> V_144 & V_140 -> V_144 ;
if ( V_144 ) {
if ( V_144 & V_173 )
F_79 ( L_21 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_176 )
F_79 ( L_22 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_177 )
F_79 ( L_23 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_178 )
F_79 ( L_24 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_179 )
F_79 ( L_25 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_180 )
F_79 ( L_26 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_181 )
F_79 ( L_27 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_182 )
F_79 ( L_28 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_183 )
F_79 ( L_29 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_184 )
F_79 ( L_30 , V_174 [ V_143 -> V_175 ] ) ;
if ( V_144 & V_185 )
F_79 ( L_31 , V_174 [ V_143 -> V_175 ] ) ;
}
}
V_9 ++ ;
}
}
static bool F_83 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_135 * V_135 ;
bool V_186 = false ;
if ( V_7 -> V_187 ) {
if ( V_7 -> V_137 ) {
V_186 = F_84 ( V_5 ) ;
if ( V_186 == false )
V_186 = F_85 ( V_5 ) ;
} else {
V_186 = F_86 ( V_5 ) ;
if ( V_186 == false )
V_186 = F_87 ( V_5 ) ;
}
} else {
if ( ! F_27 ( V_7 ) )
V_186 = F_87 ( V_5 ) ;
}
if ( V_186 ) {
F_88 ( V_5 ) ;
F_78 ( V_5 ) ;
F_80 (drm_connector, &dev->mode_config.connector_list, head)
F_89 ( V_135 ) ;
}
return V_186 ;
}
int F_90 ( struct V_140 * V_140 )
{
struct V_4 * V_5 = V_140 -> V_92 . V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_186 = 0 ;
if ( V_140 -> V_160 . V_161 )
F_91 ( V_140 ) ;
if ( ( V_140 -> V_92 . V_146 == V_188 ) ||
( V_140 -> V_92 . V_146 == V_189 ) ) {
struct V_190 * V_191 = V_140 -> V_192 ;
if ( ( V_191 -> V_193 == V_194 ||
V_191 -> V_193 == V_195 ) && V_191 -> V_196 )
V_140 -> V_197 = F_92 ( & V_140 -> V_92 , & V_191 -> V_196 -> V_198 ) ;
}
if ( ! V_140 -> V_150 )
return - 1 ;
if ( ! V_140 -> V_197 ) {
V_140 -> V_197 = F_92 ( & V_140 -> V_92 , & V_140 -> V_150 -> V_198 ) ;
}
if ( ! V_140 -> V_197 ) {
if ( V_7 -> V_137 ) {
if ( ( ( V_140 -> V_92 . V_146 == V_199 ) ||
( V_140 -> V_92 . V_146 == V_189 ) ) )
V_140 -> V_197 = F_93 ( V_7 ) ;
} else
V_140 -> V_197 = F_93 ( V_7 ) ;
}
if ( V_140 -> V_197 ) {
F_94 ( & V_140 -> V_92 , V_140 -> V_197 ) ;
V_186 = F_95 ( & V_140 -> V_92 , V_140 -> V_197 ) ;
return V_186 ;
}
F_94 ( & V_140 -> V_92 , NULL ) ;
return 0 ;
}
static int F_89 ( struct V_135 * V_139 )
{
struct V_197 * V_197 ;
struct V_140 * V_140 = F_81 ( V_139 ) ;
int V_186 = 0 ;
if ( V_140 -> V_160 . V_161 )
F_91 ( V_140 ) ;
if ( ! V_140 -> V_150 )
return - 1 ;
V_197 = F_92 ( V_139 , & V_140 -> V_150 -> V_198 ) ;
if ( V_197 ) {
F_33 ( V_197 ) ;
}
return V_186 ;
}
static void F_96 ( struct V_200 * V_201 ,
T_3 V_202 ,
T_3 V_203 ,
T_3 V_204 ,
T_3 * V_205 ,
T_3 * V_206 )
{
T_3 V_207 = V_203 * V_204 ;
V_207 *= V_202 ;
* V_205 = V_207 / V_201 -> V_208 ;
* V_206 = V_207 % V_201 -> V_208 ;
if ( * V_205 > V_201 -> V_209 )
* V_205 = V_201 -> V_209 ;
else if ( * V_205 < V_201 -> V_210 )
* V_205 = V_201 -> V_210 ;
}
static T_3 F_97 ( struct V_200 * V_201 ,
T_3 V_202 )
{
T_3 V_211 , V_203 , V_207 ;
if ( V_201 -> V_81 & V_212 )
return V_201 -> V_203 ;
if ( V_201 -> V_81 & V_213 ) {
if ( V_201 -> V_81 & V_214 )
V_211 = V_201 -> V_215 ;
else
V_211 = V_201 -> V_216 ;
} else {
if ( V_201 -> V_81 & V_214 )
V_211 = V_201 -> V_217 ;
else
V_211 = V_201 -> V_218 ;
}
V_203 = V_211 / V_202 ;
V_207 = V_211 % V_202 ;
if ( V_201 -> V_81 & V_213 ) {
if ( V_207 )
V_203 ++ ;
} else {
if ( ! V_207 )
V_203 -- ;
}
if ( V_203 > V_201 -> V_219 )
V_203 = V_201 -> V_219 ;
else if ( V_203 < V_201 -> V_220 )
V_203 = V_201 -> V_220 ;
return V_203 ;
}
void F_98 ( struct V_200 * V_201 ,
T_3 V_221 ,
T_3 * V_222 ,
T_3 * V_223 ,
T_3 * V_224 ,
T_3 * V_225 ,
T_3 * V_226 )
{
T_3 V_202 = V_221 / 10 ;
T_3 V_203 = F_97 ( V_201 , V_202 ) ;
T_3 V_204 = V_201 -> V_227 ;
T_3 V_205 = 0 , V_206 = 0 , V_207 ;
if ( V_201 -> V_81 & V_228 )
V_204 = V_201 -> V_229 ;
if ( V_201 -> V_81 & V_230 ) {
F_96 ( V_201 , V_202 , V_203 , V_204 , & V_205 , & V_206 ) ;
V_206 = ( 100 * V_206 ) / V_201 -> V_208 ;
if ( V_206 >= 5 ) {
V_206 -= 5 ;
V_206 = V_206 / 10 ;
V_206 ++ ;
}
if ( V_206 >= 10 ) {
V_205 ++ ;
V_206 = 0 ;
}
} else {
while ( V_204 <= V_201 -> V_231 ) {
F_96 ( V_201 , V_202 , V_203 , V_204 ,
& V_205 , & V_206 ) ;
if ( V_206 >= ( V_201 -> V_208 / 2 ) )
V_205 ++ ;
V_206 = 0 ;
V_207 = ( V_201 -> V_208 * V_205 ) / ( V_203 * V_204 ) ;
V_207 = ( V_207 * 10000 ) / V_202 ;
if ( V_207 > ( 10000 + V_232 ) )
V_204 ++ ;
else if ( V_207 >= ( 10000 - V_232 ) )
break;
else
V_204 ++ ;
}
}
* V_222 = ( ( V_201 -> V_208 * V_205 * 10 ) + ( V_201 -> V_208 * V_206 ) ) /
( V_204 * V_203 * 10 ) ;
* V_223 = V_205 ;
* V_224 = V_206 ;
* V_225 = V_204 ;
* V_226 = V_203 ;
F_3 ( L_32 ,
* V_222 , V_205 , V_206 , V_204 , V_203 ) ;
}
static inline T_1 F_99 ( T_5 V_233 , T_1 V_234 )
{
T_5 V_235 ;
V_233 += V_234 / 2 ;
V_235 = F_100 ( V_233 , V_234 ) ;
return V_233 ;
}
void F_101 ( struct V_200 * V_201 ,
T_5 V_221 ,
T_1 * V_222 ,
T_1 * V_223 ,
T_1 * V_224 ,
T_1 * V_225 ,
T_1 * V_226 )
{
T_1 V_227 = V_201 -> V_227 ;
T_1 V_231 = V_201 -> V_231 ;
T_1 V_220 = V_201 -> V_220 ;
T_1 V_219 = V_201 -> V_219 ;
T_1 V_236 = 0 ;
T_1 V_237 = 0 ;
T_1 V_238 = V_201 -> V_238 ;
T_1 V_239 = 1 ;
T_1 V_240 = 1 ;
T_1 V_241 = 1 ;
T_1 V_242 = 0 ;
T_1 V_243 = - 1 ;
T_1 V_244 = 0xffffffff ;
T_1 V_245 = 1 ;
T_1 V_203 ;
T_3 V_216 , V_218 ;
F_3 ( L_33 , V_221 , V_201 -> V_227 , V_201 -> V_231 ) ;
V_221 = V_221 * 1000 ;
if ( V_201 -> V_81 & V_214 ) {
V_216 = V_201 -> V_215 ;
V_218 = V_201 -> V_217 ;
} else {
V_216 = V_201 -> V_216 ;
V_218 = V_201 -> V_218 ;
}
if ( V_216 > 64800 )
V_216 = 64800 ;
if ( V_201 -> V_81 & V_228 )
V_227 = V_231 = V_201 -> V_229 ;
else {
while ( V_227 < V_231 - 1 ) {
T_1 V_246 = ( V_227 + V_231 ) / 2 ;
T_1 V_247 = V_201 -> V_208 / V_246 ;
if ( V_247 < V_201 -> V_248 )
V_231 = V_246 ;
else if ( V_247 > V_201 -> V_249 )
V_227 = V_246 ;
else
break;
}
}
if ( V_201 -> V_81 & V_212 )
V_220 = V_219 = V_201 -> V_203 ;
if ( V_201 -> V_81 & V_230 ) {
V_236 = V_201 -> V_250 ;
V_237 = V_201 -> V_251 ;
}
for ( V_203 = V_219 ; V_203 >= V_220 ; -- V_203 ) {
T_1 V_204 ;
if ( ( V_201 -> V_81 & V_252 ) && ( V_203 & 1 ) )
continue;
if ( V_201 -> V_81 & V_253 ) {
if ( ( V_203 == 5 ) ||
( V_203 == 7 ) ||
( V_203 == 9 ) ||
( V_203 == 10 ) ||
( V_203 == 11 ) ||
( V_203 == 13 ) ||
( V_203 == 14 ) ||
( V_203 == 15 ) )
continue;
}
for ( V_204 = V_227 ; V_204 <= V_231 ; ++ V_204 ) {
T_1 V_254 , V_255 = 0 , error , V_256 ;
T_1 V_247 = V_201 -> V_208 / V_204 ;
T_1 V_257 = V_201 -> V_210 ;
T_1 V_258 = V_201 -> V_209 + 1 ;
if ( V_247 < V_201 -> V_248 || V_247 > V_201 -> V_249 )
continue;
while ( V_257 < V_258 ) {
T_1 V_211 ;
T_1 V_259 = V_236 ;
T_1 V_260 = V_237 + 1 ;
T_1 V_261 ;
T_5 V_207 ;
V_254 = ( V_257 + V_258 ) / 2 ;
V_207 = ( T_5 ) V_201 -> V_208 * V_254 ;
V_211 = F_99 ( V_207 , V_204 ) ;
if ( V_211 < V_216 ) {
V_257 = V_254 + 1 ;
continue;
} else if ( V_211 > V_218 ) {
V_258 = V_254 ;
continue;
}
while ( V_259 < V_260 ) {
V_261 = ( V_259 + V_260 ) / 2 ;
V_207 = ( T_5 ) V_201 -> V_208 * 10000 * V_254 ;
V_207 += ( T_5 ) V_201 -> V_208 * 1000 * V_261 ;
V_255 = F_99 ( V_207 , V_204 * V_203 ) ;
if ( V_201 -> V_81 & V_262 ) {
if ( V_221 < V_255 )
error = 0xffffffff ;
else
error = V_221 - V_255 ;
} else
error = abs ( V_255 - V_221 ) ;
V_256 = abs ( V_211 - V_238 ) ;
if ( ( V_238 == 0 && error < V_244 ) ||
( V_238 != 0 &&
( ( V_244 > 100 && error < V_244 - 100 ) ||
( abs ( error - V_244 ) < 100 && V_256 < V_245 ) ) ) ) {
V_239 = V_203 ;
V_240 = V_204 ;
V_241 = V_254 ;
V_242 = V_261 ;
V_243 = V_255 ;
V_244 = error ;
V_245 = V_256 ;
} else if ( V_255 == V_221 ) {
if ( V_243 == - 1 ) {
V_239 = V_203 ;
V_240 = V_204 ;
V_241 = V_254 ;
V_242 = V_261 ;
V_243 = V_255 ;
V_244 = error ;
V_245 = V_256 ;
} else if ( ( ( V_201 -> V_81 & V_263 ) && ( V_204 < V_240 ) ) ||
( ( V_201 -> V_81 & V_264 ) && ( V_204 > V_240 ) ) ||
( ( V_201 -> V_81 & V_265 ) && ( V_254 < V_241 ) ) ||
( ( V_201 -> V_81 & V_266 ) && ( V_254 > V_241 ) ) ||
( ( V_201 -> V_81 & V_267 ) && ( V_203 < V_239 ) ) ||
( ( V_201 -> V_81 & V_268 ) && ( V_203 > V_239 ) ) ) {
V_239 = V_203 ;
V_240 = V_204 ;
V_241 = V_254 ;
V_242 = V_261 ;
V_243 = V_255 ;
V_244 = error ;
V_245 = V_256 ;
}
}
if ( V_255 < V_221 )
V_259 = V_261 + 1 ;
else
V_260 = V_261 ;
}
if ( V_255 < V_221 )
V_257 = V_254 + 1 ;
else
V_258 = V_254 ;
}
}
}
* V_222 = V_243 / 10000 ;
* V_223 = V_241 ;
* V_224 = V_242 ;
* V_225 = V_240 ;
* V_226 = V_239 ;
F_3 ( L_34 ,
( long long ) V_221 ,
V_243 / 1000 , V_241 , V_242 ,
V_240 , V_239 ) ;
}
static void F_102 ( struct V_103 * V_104 )
{
struct V_105 * V_269 = F_60 ( V_104 ) ;
if ( V_269 -> V_109 ) {
F_42 ( V_269 -> V_109 ) ;
}
F_103 ( V_104 ) ;
F_33 ( V_269 ) ;
}
static int F_104 ( struct V_103 * V_104 ,
struct V_270 * V_100 ,
unsigned int * V_271 )
{
struct V_105 * V_269 = F_60 ( V_104 ) ;
return F_105 ( V_100 , V_269 -> V_109 , V_271 ) ;
}
void
F_106 ( struct V_4 * V_5 ,
struct V_105 * V_272 ,
struct V_273 * V_274 ,
struct V_108 * V_109 )
{
V_272 -> V_109 = V_109 ;
F_107 ( V_5 , & V_272 -> V_92 , & V_275 ) ;
F_108 ( & V_272 -> V_92 , V_274 ) ;
}
static struct V_103 *
F_109 ( struct V_4 * V_5 ,
struct V_270 * V_100 ,
struct V_273 * V_274 )
{
struct V_108 * V_109 ;
struct V_105 * V_269 ;
V_109 = F_110 ( V_5 , V_100 , V_274 -> V_271 ) ;
if ( V_109 == NULL ) {
F_111 ( & V_5 -> V_276 -> V_5 , L_35
L_36 , V_274 -> V_271 ) ;
return F_112 ( - V_277 ) ;
}
V_269 = F_57 ( sizeof( * V_269 ) , V_115 ) ;
if ( V_269 == NULL )
return F_112 ( - V_116 ) ;
F_106 ( V_5 , V_269 , V_274 , V_109 ) ;
return & V_269 -> V_92 ;
}
static void F_113 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_114 ( V_7 ) ;
}
static int F_115 ( struct V_6 * V_7 )
{
int V_9 , V_278 ;
if ( V_7 -> V_137 ) {
V_7 -> V_75 . V_279 =
F_116 ( V_7 -> V_85 ,
V_280 ,
L_37 , 2 ) ;
if ( ! V_7 -> V_75 . V_279 )
return - V_116 ;
V_7 -> V_75 . V_279 -> V_281 [ 0 ] = 0 ;
V_7 -> V_75 . V_279 -> V_281 [ 1 ] = 1 ;
}
if ( ! F_27 ( V_7 ) ) {
V_278 = F_117 ( V_282 ) ;
V_7 -> V_75 . V_283 =
F_116 ( V_7 -> V_85 ,
V_284 ,
L_38 , V_278 ) ;
for ( V_9 = 0 ; V_9 < V_278 ; V_9 ++ ) {
F_118 ( V_7 -> V_75 . V_283 ,
V_9 ,
V_282 [ V_9 ] . type ,
V_282 [ V_9 ] . V_285 ) ;
}
}
V_7 -> V_75 . V_286 =
F_116 ( V_7 -> V_85 ,
V_280 ,
L_39 , 2 ) ;
if ( ! V_7 -> V_75 . V_286 )
return - V_116 ;
V_7 -> V_75 . V_286 -> V_281 [ 0 ] = 0 ;
V_7 -> V_75 . V_286 -> V_281 [ 1 ] = 1 ;
F_119 ( V_7 -> V_85 ) ;
V_278 = F_117 ( V_287 ) ;
V_7 -> V_75 . V_288 =
F_116 ( V_7 -> V_85 ,
V_284 ,
L_40 , V_278 ) ;
for ( V_9 = 0 ; V_9 < V_278 ; V_9 ++ ) {
F_118 ( V_7 -> V_75 . V_288 ,
V_9 ,
V_287 [ V_9 ] . type ,
V_287 [ V_9 ] . V_285 ) ;
}
V_278 = F_117 ( V_289 ) ;
V_7 -> V_75 . V_290 =
F_116 ( V_7 -> V_85 ,
V_284 ,
L_41 , V_278 ) ;
for ( V_9 = 0 ; V_9 < V_278 ; V_9 ++ ) {
F_118 ( V_7 -> V_75 . V_290 ,
V_9 ,
V_289 [ V_9 ] . type ,
V_289 [ V_9 ] . V_285 ) ;
}
V_7 -> V_75 . V_291 =
F_116 ( V_7 -> V_85 ,
V_280 ,
L_42 , 2 ) ;
if ( ! V_7 -> V_75 . V_291 )
return - V_116 ;
V_7 -> V_75 . V_291 -> V_281 [ 0 ] = 0 ;
V_7 -> V_75 . V_291 -> V_281 [ 1 ] = 128 ;
V_7 -> V_75 . V_292 =
F_116 ( V_7 -> V_85 ,
V_280 ,
L_43 , 2 ) ;
if ( ! V_7 -> V_75 . V_292 )
return - V_116 ;
V_7 -> V_75 . V_292 -> V_281 [ 0 ] = 0 ;
V_7 -> V_75 . V_292 -> V_281 [ 1 ] = 128 ;
return 0 ;
}
void F_120 ( struct V_6 * V_7 )
{
if ( ( V_293 == 0 ) || ( V_293 > 2 ) ) {
if ( ( F_67 ( V_7 ) || ( V_7 -> V_294 == V_295 ) ) &&
! ( V_7 -> V_81 & V_296 ) )
V_7 -> V_297 = 2 ;
else
V_7 -> V_297 = 0 ;
} else
V_7 -> V_297 = V_293 ;
}
int F_121 ( struct V_6 * V_7 )
{
int V_9 ;
int V_186 ;
F_122 ( V_7 -> V_85 ) ;
V_7 -> V_75 . V_298 = true ;
V_7 -> V_85 -> V_299 . V_300 = ( void * ) & V_301 ;
if ( F_25 ( V_7 ) ) {
V_7 -> V_85 -> V_299 . V_302 = 16384 ;
V_7 -> V_85 -> V_299 . V_303 = 16384 ;
} else if ( F_27 ( V_7 ) ) {
V_7 -> V_85 -> V_299 . V_302 = 8192 ;
V_7 -> V_85 -> V_299 . V_303 = 8192 ;
} else {
V_7 -> V_85 -> V_299 . V_302 = 4096 ;
V_7 -> V_85 -> V_299 . V_303 = 4096 ;
}
V_7 -> V_85 -> V_299 . V_304 = V_7 -> V_305 . V_306 ;
V_186 = F_115 ( V_7 ) ;
if ( V_186 ) {
return V_186 ;
}
F_123 ( V_7 ) ;
if ( ! V_7 -> V_137 ) {
F_124 ( V_7 ) ;
}
for ( V_9 = 0 ; V_9 < V_7 -> V_307 ; V_9 ++ ) {
F_73 ( V_7 -> V_85 , V_9 ) ;
}
V_186 = F_83 ( V_7 -> V_85 ) ;
if ( ! V_186 ) {
return V_186 ;
}
if ( V_7 -> V_137 )
F_125 ( V_7 ) ;
F_126 ( V_7 ) ;
F_127 ( V_7 ) ;
F_128 ( V_7 ) ;
F_129 ( V_7 -> V_85 ) ;
return 0 ;
}
void F_130 ( struct V_6 * V_7 )
{
F_131 ( V_7 ) ;
F_33 ( V_7 -> V_75 . V_308 ) ;
F_132 ( V_7 ) ;
if ( V_7 -> V_75 . V_298 ) {
F_133 ( V_7 -> V_85 ) ;
F_134 ( V_7 ) ;
F_135 ( V_7 -> V_85 ) ;
V_7 -> V_75 . V_298 = false ;
}
F_136 ( V_7 ) ;
}
static bool F_137 ( struct V_309 * V_310 )
{
if ( ( V_310 -> V_311 == 480 && V_310 -> V_312 == 720 ) ||
( V_310 -> V_311 == 576 ) ||
( V_310 -> V_311 == 720 ) ||
( V_310 -> V_311 == 1080 ) )
return true ;
else
return false ;
}
bool F_138 ( struct V_1 * V_2 ,
struct V_309 * V_310 ,
struct V_309 * V_313 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_141 * V_142 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_143 * V_143 ;
struct V_135 * V_139 ;
struct V_140 * V_140 ;
bool V_314 = true ;
T_3 V_315 = 1 , V_316 = 1 ;
T_3 V_317 = 1 , V_318 = 1 ;
V_3 -> V_319 = 0 ;
V_3 -> V_320 = 0 ;
F_80 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_142 -> V_2 != V_2 )
continue;
V_143 = F_82 ( V_142 ) ;
V_139 = F_139 ( V_142 ) ;
V_140 = F_81 ( V_139 ) ;
if ( V_314 ) {
if ( V_143 -> V_321 == V_322 )
V_3 -> V_321 = V_322 ;
else if ( V_310 -> V_312 < V_143 -> V_323 . V_312 ||
V_310 -> V_311 < V_143 -> V_323 . V_311 )
V_3 -> V_321 = V_143 -> V_321 ;
else
V_3 -> V_321 = V_322 ;
memcpy ( & V_3 -> V_323 ,
& V_143 -> V_323 ,
sizeof( struct V_309 ) ) ;
V_315 = V_2 -> V_310 . V_311 ;
V_316 = V_3 -> V_323 . V_311 ;
V_317 = V_2 -> V_310 . V_312 ;
V_318 = V_3 -> V_323 . V_312 ;
if ( F_27 ( V_7 ) &&
( ! ( V_310 -> V_81 & V_324 ) ) &&
( ( V_143 -> V_325 == V_326 ) ||
( ( V_143 -> V_325 == V_327 ) &&
F_140 ( V_140 -> V_197 ) &&
F_137 ( V_310 ) ) ) ) {
if ( V_143 -> V_328 != 0 )
V_3 -> V_319 = V_143 -> V_328 ;
else
V_3 -> V_319 = ( V_310 -> V_312 >> 5 ) + 16 ;
if ( V_143 -> V_329 != 0 )
V_3 -> V_320 = V_143 -> V_329 ;
else
V_3 -> V_320 = ( V_310 -> V_311 >> 5 ) + 16 ;
V_3 -> V_321 = V_330 ;
V_315 = V_2 -> V_310 . V_311 ;
V_316 = V_2 -> V_310 . V_311 - ( V_3 -> V_320 * 2 ) ;
V_317 = V_2 -> V_310 . V_312 ;
V_318 = V_2 -> V_310 . V_312 - ( V_3 -> V_319 * 2 ) ;
}
V_314 = false ;
} else {
if ( V_3 -> V_321 != V_143 -> V_321 ) {
F_40 ( L_44 ) ;
return false ;
}
}
}
if ( V_3 -> V_321 != V_322 ) {
T_6 V_331 , V_332 ;
V_331 . V_333 = F_141 ( V_315 ) ;
V_332 . V_333 = F_141 ( V_316 ) ;
V_3 -> V_334 . V_333 = F_142 ( V_331 , V_332 ) ;
V_331 . V_333 = F_141 ( V_317 ) ;
V_332 . V_333 = F_141 ( V_318 ) ;
V_3 -> V_335 . V_333 = F_142 ( V_331 , V_332 ) ;
} else {
V_3 -> V_334 . V_333 = F_141 ( 1 ) ;
V_3 -> V_335 . V_333 = F_141 ( 1 ) ;
}
return true ;
}
int F_48 ( struct V_4 * V_5 , int V_2 , int * V_83 , int * V_84 )
{
T_3 V_336 = 0 , V_337 = 0 , V_338 = 0 ;
int V_339 , V_340 , V_341 , V_186 = 0 ;
bool V_342 = true ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_26 ( V_7 ) ) {
if ( V_2 == 0 ) {
V_337 = F_23 ( V_343 +
V_344 ) ;
V_338 = F_23 ( V_345 +
V_344 ) ;
V_186 |= V_91 ;
}
if ( V_2 == 1 ) {
V_337 = F_23 ( V_343 +
V_346 ) ;
V_338 = F_23 ( V_345 +
V_346 ) ;
V_186 |= V_91 ;
}
if ( V_2 == 2 ) {
V_337 = F_23 ( V_343 +
V_347 ) ;
V_338 = F_23 ( V_345 +
V_347 ) ;
V_186 |= V_91 ;
}
if ( V_2 == 3 ) {
V_337 = F_23 ( V_343 +
V_348 ) ;
V_338 = F_23 ( V_345 +
V_348 ) ;
V_186 |= V_91 ;
}
if ( V_2 == 4 ) {
V_337 = F_23 ( V_343 +
V_349 ) ;
V_338 = F_23 ( V_345 +
V_349 ) ;
V_186 |= V_91 ;
}
if ( V_2 == 5 ) {
V_337 = F_23 ( V_343 +
V_350 ) ;
V_338 = F_23 ( V_345 +
V_350 ) ;
V_186 |= V_91 ;
}
} else if ( F_27 ( V_7 ) ) {
if ( V_2 == 0 ) {
V_337 = F_23 ( V_351 ) ;
V_338 = F_23 ( V_352 ) ;
V_186 |= V_91 ;
}
if ( V_2 == 1 ) {
V_337 = F_23 ( V_353 ) ;
V_338 = F_23 ( V_354 ) ;
V_186 |= V_91 ;
}
} else {
if ( V_2 == 0 ) {
V_337 = ( F_23 ( V_355 ) &
V_356 ) >> V_357 ;
V_338 = ( F_23 ( V_358 ) >> 16 ) & V_359 ;
V_336 = F_23 ( V_360 ) ;
if ( ! ( V_336 & 1 ) )
V_342 = false ;
V_186 |= V_91 ;
}
if ( V_2 == 1 ) {
V_337 = ( F_23 ( V_361 ) &
V_356 ) >> V_357 ;
V_338 = ( F_23 ( V_362 ) >> 16 ) & V_359 ;
V_336 = F_23 ( V_363 ) ;
if ( ! ( V_336 & 1 ) )
V_342 = false ;
V_186 |= V_91 ;
}
}
* V_83 = V_338 & 0x1fff ;
* V_84 = ( V_338 >> 16 ) & 0x1fff ;
if ( V_337 > 0 ) {
V_186 |= V_364 ;
V_339 = V_337 & 0x1fff ;
V_340 = ( V_337 >> 16 ) & 0x1fff ;
}
else {
V_339 = V_7 -> V_75 . V_76 [ V_2 ] -> V_92 . V_93 . V_94 ;
V_340 = 0 ;
}
if ( ( * V_83 < V_339 ) && ( * V_83 >= V_340 ) )
V_342 = false ;
if ( V_342 && ( * V_83 >= V_339 ) ) {
V_341 = V_7 -> V_75 . V_76 [ V_2 ] -> V_92 . V_93 . V_365 ;
* V_83 = * V_83 - V_341 ;
}
* V_83 = * V_83 - V_340 ;
if ( V_342 )
V_186 |= V_366 ;
return V_186 ;
}
