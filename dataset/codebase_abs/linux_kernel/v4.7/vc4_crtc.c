static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static inline struct V_4 *
F_2 ( struct V_5 * V_6 )
{
return (struct V_4 * ) V_6 ;
}
static void F_3 ( struct V_1 * V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ ) {
F_5 ( L_1 ,
V_8 [ V_7 ] . V_9 , V_8 [ V_7 ] . V_10 ,
F_6 ( V_8 [ V_7 ] . V_9 ) ) ;
}
}
int F_7 ( struct V_11 * V_12 , void * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_12 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_19 -> V_18 ;
int V_20 = ( V_21 ) V_15 -> V_22 -> V_23 ;
struct V_2 * V_3 ;
struct V_1 * V_1 ;
int V_7 ;
V_7 = 0 ;
F_8 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_7 == V_20 )
break;
V_7 ++ ;
}
if ( ! V_3 )
return 0 ;
V_1 = F_1 ( V_3 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ ) {
F_9 ( V_12 , L_2 ,
V_8 [ V_7 ] . V_10 , V_8 [ V_7 ] . V_9 ,
F_6 ( V_8 [ V_7 ] . V_9 ) ) ;
}
return 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
}
static void
F_12 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_7 ;
F_14 ( V_26 ,
V_27 |
( V_1 -> V_28 * 3 * V_3 -> V_29 ) ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_29 ; V_7 ++ )
F_14 ( V_30 , V_1 -> V_31 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_29 ; V_7 ++ )
F_14 ( V_30 , V_1 -> V_32 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_29 ; V_7 ++ )
F_14 ( V_30 , V_1 -> V_33 [ V_7 ] ) ;
}
static void
F_15 ( struct V_2 * V_3 , T_2 * V_34 , T_2 * V_35 , T_2 * V_36 ,
T_3 V_37 , T_3 V_38 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_7 ;
for ( V_7 = V_37 ; V_7 < V_37 + V_38 ; V_7 ++ ) {
V_1 -> V_31 [ V_7 ] = V_34 [ V_7 ] >> 8 ;
V_1 -> V_32 [ V_7 ] = V_35 [ V_7 ] >> 8 ;
V_1 -> V_33 [ V_7 ] = V_36 [ V_7 ] >> 8 ;
}
F_12 ( V_3 ) ;
}
static T_1 F_16 ( T_1 V_39 )
{
static const T_1 V_40 = 64 ;
static const T_1 V_41 = 6 ;
switch ( V_39 ) {
case V_42 :
case V_43 :
return V_40 - 2 * V_41 ;
case V_44 :
return V_40 - 14 ;
case V_45 :
case V_46 :
default:
return V_40 - 3 * V_41 ;
}
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_47 * V_48 ;
F_18 (connector, crtc->dev) {
if ( V_48 -> V_49 -> V_3 == V_3 ) {
struct V_50 * V_51 = V_48 -> V_51 ;
struct V_52 * V_52 =
F_19 ( V_51 ) ;
return V_52 -> V_53 ;
}
}
return - 1 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_49 = V_3 -> V_49 ;
struct V_54 * V_55 = & V_49 -> V_56 ;
bool V_57 = V_55 -> V_58 & V_59 ;
T_1 V_60 = ( V_55 -> V_61 >> ( V_57 ? 1 : 0 ) ) ;
T_1 V_39 = V_45 ;
bool V_62 = false ;
int V_53 = F_17 ( V_3 ) ;
if ( V_62 ) {
F_5 ( L_3 , F_21 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
F_22 ( V_63 , 0 ) ;
F_22 ( V_63 , V_64 | V_65 ) ;
F_22 ( V_63 , 0 ) ;
F_22 ( V_66 ,
F_23 ( V_55 -> V_67 - V_55 -> V_68 ,
V_69 ) |
F_23 ( V_55 -> V_68 - V_55 -> V_70 ,
V_71 ) ) ;
F_22 ( V_72 ,
F_23 ( V_55 -> V_70 - V_55 -> V_73 ,
V_74 ) |
F_23 ( V_55 -> V_73 , V_75 ) ) ;
F_22 ( V_76 ,
F_23 ( V_55 -> V_77 - V_55 -> V_78 ,
V_79 ) |
F_23 ( V_55 -> V_78 - V_55 -> V_80 ,
V_81 ) ) ;
F_22 ( V_82 ,
F_23 ( V_55 -> V_80 - V_55 -> V_61 ,
V_83 ) |
F_23 ( V_60 , V_84 ) ) ;
if ( V_57 ) {
F_22 ( V_85 ,
F_23 ( V_55 -> V_77 - V_55 -> V_78 - 1 ,
V_79 ) |
F_23 ( V_55 -> V_78 - V_55 -> V_80 ,
V_81 ) ) ;
F_22 ( V_86 ,
F_23 ( V_55 -> V_80 - V_55 -> V_61 ,
V_83 ) |
F_23 ( V_60 , V_84 ) ) ;
}
F_22 ( V_87 , V_55 -> V_73 ) ;
F_22 ( V_88 ,
V_89 |
( V_57 ? V_90 : 0 ) ) ;
F_22 ( V_63 ,
F_23 ( V_39 , V_91 ) |
F_23 ( F_16 ( V_39 ) ,
V_92 ) |
V_93 |
V_94 |
V_95 |
F_23 ( V_53 , V_96 ) |
V_64 |
V_65 ) ;
F_14 ( F_24 ( V_1 -> V_28 ) ,
V_97 |
V_98 |
( V_57 ? V_99 : 0 ) ) ;
F_12 ( V_3 ) ;
if ( V_62 ) {
F_5 ( L_4 , F_21 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
}
static void F_25 ( struct V_17 * V_18 )
{
struct V_24 * V_25 = F_13 ( V_18 ) ;
F_26 ( ( F_27 ( V_100 ) & V_101 ) !=
V_101 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_102 = V_1 -> V_28 ;
int V_103 ;
F_25 ( V_18 ) ;
F_22 ( V_88 ,
F_6 ( V_88 ) & ~ V_104 ) ;
V_103 = F_29 ( ! ( F_6 ( V_88 ) & V_104 ) , 1 ) ;
F_30 ( V_103 , L_5 ) ;
if ( F_27 ( F_31 ( V_102 ) ) &
V_105 ) {
F_14 ( F_31 ( V_102 ) ,
V_106 ) ;
F_14 ( F_31 ( V_102 ) , 0 ) ;
}
F_26 ( F_27 ( F_31 ( V_102 ) ) & V_106 ) ;
F_26 ( F_32 ( F_27 ( F_33 ( V_102 ) ) ,
V_107 ) !=
V_108 ) ;
F_26 ( ( F_27 ( F_33 ( V_102 ) ) &
( V_109 | V_110 ) ) !=
V_110 ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_49 = V_3 -> V_49 ;
struct V_54 * V_55 = & V_49 -> V_56 ;
F_25 ( V_18 ) ;
F_14 ( F_31 ( V_1 -> V_28 ) ,
F_23 ( V_55 -> V_73 , V_111 ) |
F_23 ( V_55 -> V_61 , V_112 ) |
V_105 ) ;
F_22 ( V_88 ,
F_6 ( V_88 ) | V_104 ) ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_5 * V_49 )
{
struct V_4 * V_113 = F_2 ( V_49 ) ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_114 * V_115 ;
unsigned long V_58 ;
T_1 V_116 = 0 ;
int V_103 ;
if ( F_36 ( V_49 -> V_117 ) > 1 )
return - V_118 ;
F_37 (plane, state) {
struct V_119 * V_120 =
V_49 -> V_49 -> V_121 [ F_38 ( V_115 ) ] ;
if ( ! V_120 )
V_120 = V_115 -> V_49 ;
V_116 += F_39 ( V_120 ) ;
}
V_116 ++ ;
F_40 ( & V_25 -> V_122 -> V_123 , V_58 ) ;
V_103 = F_41 ( & V_25 -> V_122 -> V_124 , & V_113 -> V_125 ,
V_116 , 1 , 0 ) ;
F_42 ( & V_25 -> V_122 -> V_123 , V_58 ) ;
if ( V_103 )
return V_103 ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_5 * V_126 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_113 = F_2 ( V_3 -> V_49 ) ;
struct V_114 * V_115 ;
bool V_62 = false ;
T_1 T_4 * V_127 = V_25 -> V_122 -> V_128 + V_113 -> V_125 . V_37 ;
T_1 T_4 * V_129 = V_127 ;
if ( V_62 ) {
F_5 ( L_6 , F_21 ( V_3 ) ) ;
F_44 ( V_18 ) ;
}
F_45 (plane, crtc) {
V_129 += F_46 ( V_115 , V_129 ) ;
}
F_47 ( V_130 , V_129 ) ;
V_129 ++ ;
F_26 ( V_129 - V_127 != V_113 -> V_125 . V_38 ) ;
if ( V_3 -> V_49 -> V_131 ) {
unsigned long V_58 ;
V_3 -> V_49 -> V_131 -> V_132 = F_21 ( V_3 ) ;
F_48 ( F_49 ( V_3 ) != 0 ) ;
F_40 ( & V_18 -> V_133 , V_58 ) ;
V_1 -> V_131 = V_3 -> V_49 -> V_131 ;
V_3 -> V_49 -> V_131 = NULL ;
F_14 ( F_50 ( V_1 -> V_28 ) ,
V_113 -> V_125 . V_37 ) ;
F_42 ( & V_18 -> V_133 , V_58 ) ;
} else {
F_14 ( F_50 ( V_1 -> V_28 ) ,
V_113 -> V_125 . V_37 ) ;
}
if ( V_62 ) {
F_5 ( L_7 , F_21 ( V_3 ) ) ;
F_44 ( V_18 ) ;
}
}
int F_51 ( struct V_17 * V_18 , unsigned int V_134 )
{
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_1 * V_1 = V_25 -> V_3 [ V_134 ] ;
F_22 ( V_135 , V_136 ) ;
return 0 ;
}
void F_52 ( struct V_17 * V_18 , unsigned int V_134 )
{
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_1 * V_1 = V_25 -> V_3 [ V_134 ] ;
F_22 ( V_135 , 0 ) ;
}
static void F_53 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_137 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_4 * V_113 = F_2 ( V_3 -> V_49 ) ;
T_1 V_102 = V_1 -> V_28 ;
unsigned long V_58 ;
F_40 ( & V_18 -> V_133 , V_58 ) ;
if ( V_1 -> V_131 &&
( V_113 -> V_125 . V_37 == F_27 ( F_54 ( V_102 ) ) ) ) {
F_55 ( V_3 , V_1 -> V_131 ) ;
V_1 -> V_131 = NULL ;
F_56 ( V_3 ) ;
}
F_42 ( & V_18 -> V_133 , V_58 ) ;
}
static T_5 F_57 ( int V_138 , void * V_23 )
{
struct V_1 * V_1 = V_23 ;
T_1 V_139 = F_6 ( V_140 ) ;
T_5 V_103 = V_141 ;
if ( V_139 & V_136 ) {
F_22 ( V_140 , V_136 ) ;
F_58 ( & V_1 -> V_137 ) ;
F_53 ( V_1 ) ;
V_103 = V_142 ;
}
return V_103 ;
}
static void
F_59 ( struct V_143 * V_144 )
{
struct V_145 * V_146 =
F_60 ( V_144 , struct V_145 , V_144 ) ;
struct V_2 * V_3 = V_146 -> V_3 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_114 * V_115 = V_3 -> V_147 ;
F_61 ( V_115 , V_146 -> V_148 ) ;
if ( V_146 -> V_131 ) {
unsigned long V_58 ;
F_40 ( & V_18 -> V_133 , V_58 ) ;
F_55 ( V_3 , V_146 -> V_131 ) ;
F_42 ( & V_18 -> V_133 , V_58 ) ;
}
F_56 ( V_3 ) ;
F_62 ( V_146 -> V_148 ) ;
F_63 ( V_146 ) ;
F_64 ( & V_25 -> V_149 ) ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_150 * V_148 ,
struct V_151 * V_131 ,
T_3 V_58 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_24 * V_25 = F_13 ( V_18 ) ;
struct V_114 * V_115 = V_3 -> V_147 ;
int V_103 = 0 ;
struct V_145 * V_146 ;
struct V_152 * V_153 = F_66 ( V_148 , 0 ) ;
struct V_154 * V_155 = F_67 ( & V_153 -> V_137 ) ;
V_146 = F_68 ( sizeof( * V_146 ) , V_156 ) ;
if ( ! V_146 )
return - V_157 ;
F_69 ( V_148 ) ;
V_146 -> V_148 = V_148 ;
V_146 -> V_3 = V_3 ;
V_146 -> V_131 = V_131 ;
V_103 = F_70 ( & V_25 -> V_149 ) ;
if ( V_103 ) {
F_62 ( V_148 ) ;
F_63 ( V_146 ) ;
return V_103 ;
}
F_48 ( F_49 ( V_3 ) != 0 ) ;
F_71 ( V_115 -> V_49 , V_148 ) ;
V_115 -> V_148 = V_148 ;
F_72 ( V_18 , & V_146 -> V_144 , V_155 -> V_158 ,
F_59 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_150 * V_148 ,
struct V_151 * V_131 ,
T_3 V_58 )
{
if ( V_58 & V_159 )
return F_65 ( V_3 , V_148 , V_131 , V_58 ) ;
else
return F_74 ( V_3 , V_148 , V_131 , V_58 ) ;
}
static struct V_5 * F_75 ( struct V_2 * V_3 )
{
struct V_4 * V_113 ;
V_113 = F_68 ( sizeof( * V_113 ) , V_156 ) ;
if ( ! V_113 )
return NULL ;
F_76 ( V_3 , & V_113 -> V_137 ) ;
return & V_113 -> V_137 ;
}
static void F_77 ( struct V_2 * V_3 ,
struct V_5 * V_49 )
{
struct V_24 * V_25 = F_13 ( V_3 -> V_18 ) ;
struct V_4 * V_113 = F_2 ( V_49 ) ;
if ( V_113 -> V_125 . V_160 ) {
unsigned long V_58 ;
F_40 ( & V_25 -> V_122 -> V_123 , V_58 ) ;
F_78 ( & V_113 -> V_125 ) ;
F_42 ( & V_25 -> V_122 -> V_123 , V_58 ) ;
}
F_79 ( V_49 ) ;
}
static void F_80 ( struct V_17 * V_161 ,
struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_50 * V_51 ;
F_81 (encoder, drm) {
struct V_52 * V_52 = F_19 ( V_51 ) ;
if ( V_52 -> type == V_1 -> V_23 -> V_162 ) {
V_52 -> V_53 = 0 ;
V_51 -> V_163 |= F_82 ( V_3 ) ;
} else if ( V_52 -> type == V_1 -> V_23 -> V_164 ) {
V_52 -> V_53 = 1 ;
V_51 -> V_163 |= F_82 ( V_3 ) ;
}
}
}
static int F_83 ( struct V_165 * V_18 , struct V_165 * V_166 , void * V_23 )
{
struct V_167 * V_168 = F_84 ( V_18 ) ;
struct V_17 * V_161 = F_85 ( V_166 ) ;
struct V_24 * V_25 = F_13 ( V_161 ) ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_114 * V_169 , * V_170 , * V_171 , * V_172 ;
const struct V_173 * V_174 ;
int V_103 , V_7 ;
V_1 = F_86 ( V_18 , sizeof( * V_1 ) , V_156 ) ;
if ( ! V_1 )
return - V_157 ;
V_3 = & V_1 -> V_137 ;
V_174 = F_87 ( V_175 , V_18 ) ;
if ( ! V_174 )
return - V_176 ;
V_1 -> V_23 = V_174 -> V_23 ;
V_1 -> V_177 = F_88 ( V_168 , 0 ) ;
if ( F_89 ( V_1 -> V_177 ) )
return F_90 ( V_1 -> V_177 ) ;
V_169 = F_91 ( V_161 , V_178 ) ;
if ( F_89 ( V_169 ) ) {
F_92 ( V_18 , L_8 ) ;
V_103 = F_90 ( V_169 ) ;
goto V_179;
}
F_93 ( V_161 , V_3 , V_169 , NULL ,
& V_180 , NULL ) ;
F_94 ( V_3 , & V_181 ) ;
V_169 -> V_3 = V_3 ;
V_25 -> V_3 [ F_21 ( V_3 ) ] = V_1 ;
V_1 -> V_28 = V_1 -> V_23 -> V_182 ;
F_95 ( V_3 , F_4 ( V_1 -> V_31 ) ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
struct V_114 * V_115 =
F_91 ( V_161 , V_183 ) ;
if ( F_89 ( V_115 ) )
continue;
V_115 -> V_163 = 1 << F_21 ( V_3 ) ;
}
V_170 = F_91 ( V_161 , V_184 ) ;
if ( ! F_89 ( V_170 ) ) {
V_170 -> V_163 = 1 << F_21 ( V_3 ) ;
V_170 -> V_3 = V_3 ;
V_3 -> V_185 = V_170 ;
}
F_22 ( V_135 , 0 ) ;
F_22 ( V_140 , V_136 ) ;
V_103 = F_96 ( V_18 , F_97 ( V_168 , 0 ) ,
F_57 , 0 , L_9 , V_1 ) ;
if ( V_103 )
goto V_186;
F_80 ( V_161 , V_3 ) ;
for ( V_7 = 0 ; V_7 < V_3 -> V_29 ; V_7 ++ ) {
V_1 -> V_31 [ V_7 ] = V_7 ;
V_1 -> V_32 [ V_7 ] = V_7 ;
V_1 -> V_33 [ V_7 ] = V_7 ;
}
F_98 ( V_168 , V_1 ) ;
return 0 ;
V_186:
F_99 (destroy_plane, temp,
&drm->mode_config.plane_list, head) {
if ( V_171 -> V_163 == 1 << F_21 ( V_3 ) )
V_171 -> V_187 -> V_188 ( V_171 ) ;
}
V_179:
return V_103 ;
}
static void F_100 ( struct V_165 * V_18 , struct V_165 * V_166 ,
void * V_23 )
{
struct V_167 * V_168 = F_84 ( V_18 ) ;
struct V_1 * V_1 = F_85 ( V_18 ) ;
F_10 ( & V_1 -> V_137 ) ;
F_22 ( V_135 , 0 ) ;
F_98 ( V_168 , NULL ) ;
}
static int F_101 ( struct V_167 * V_168 )
{
return F_102 ( & V_168 -> V_18 , & V_189 ) ;
}
static int F_103 ( struct V_167 * V_168 )
{
F_104 ( & V_168 -> V_18 , & V_189 ) ;
return 0 ;
}
