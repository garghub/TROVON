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
static T_1 F_12 ( T_1 V_24 )
{
static const T_1 V_25 = 64 ;
static const T_1 V_26 = 6 ;
switch ( V_24 ) {
case V_27 :
case V_28 :
return V_25 - 2 * V_26 ;
case V_29 :
return V_25 - 14 ;
case V_30 :
case V_31 :
default:
return V_25 - 3 * V_26 ;
}
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
F_14 (connector, crtc->dev) {
if ( V_33 -> V_34 -> V_3 == V_3 ) {
struct V_35 * V_36 = V_33 -> V_36 ;
struct V_37 * V_37 =
F_15 ( V_36 ) ;
return V_37 -> V_38 ;
}
}
return - 1 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_39 * V_40 = F_17 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_34 = V_3 -> V_34 ;
struct V_41 * V_42 = & V_34 -> V_43 ;
bool V_44 = V_42 -> V_45 & V_46 ;
T_1 V_47 = ( V_42 -> V_48 >> ( V_44 ? 1 : 0 ) ) ;
T_1 V_24 = V_30 ;
bool V_49 = false ;
int V_38 = F_13 ( V_3 ) ;
if ( V_49 ) {
F_5 ( L_3 , F_18 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
F_19 ( V_50 , 0 ) ;
F_19 ( V_50 , V_51 | V_52 ) ;
F_19 ( V_50 , 0 ) ;
F_19 ( V_53 ,
F_20 ( V_42 -> V_54 - V_42 -> V_55 ,
V_56 ) |
F_20 ( V_42 -> V_55 - V_42 -> V_57 ,
V_58 ) ) ;
F_19 ( V_59 ,
F_20 ( V_42 -> V_57 - V_42 -> V_60 ,
V_61 ) |
F_20 ( V_42 -> V_60 , V_62 ) ) ;
F_19 ( V_63 ,
F_20 ( V_42 -> V_64 - V_42 -> V_65 ,
V_66 ) |
F_20 ( V_42 -> V_65 - V_42 -> V_67 ,
V_68 ) ) ;
F_19 ( V_69 ,
F_20 ( V_42 -> V_67 - V_42 -> V_48 ,
V_70 ) |
F_20 ( V_47 , V_71 ) ) ;
if ( V_44 ) {
F_19 ( V_72 ,
F_20 ( V_42 -> V_64 - V_42 -> V_65 - 1 ,
V_66 ) |
F_20 ( V_42 -> V_65 - V_42 -> V_67 ,
V_68 ) ) ;
F_19 ( V_73 ,
F_20 ( V_42 -> V_67 - V_42 -> V_48 ,
V_70 ) |
F_20 ( V_47 , V_71 ) ) ;
}
F_19 ( V_74 , V_42 -> V_60 ) ;
F_19 ( V_75 ,
V_76 |
( V_44 ? V_77 : 0 ) ) ;
F_19 ( V_50 ,
F_20 ( V_24 , V_78 ) |
F_20 ( F_12 ( V_24 ) ,
V_79 ) |
V_80 |
V_81 |
V_82 |
F_20 ( V_38 , V_83 ) |
V_51 |
V_52 ) ;
F_21 ( F_22 ( V_1 -> V_84 ) ,
V_85 |
( V_44 ? V_86 : 0 ) ) ;
if ( V_49 ) {
F_5 ( L_4 , F_18 ( V_3 ) ) ;
F_3 ( V_1 ) ;
}
}
static void F_23 ( struct V_17 * V_18 )
{
struct V_39 * V_40 = F_17 ( V_18 ) ;
F_24 ( ( F_25 ( V_87 ) & V_88 ) !=
V_88 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_39 * V_40 = F_17 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_89 = V_1 -> V_84 ;
int V_90 ;
F_23 ( V_18 ) ;
F_19 ( V_75 ,
F_6 ( V_75 ) & ~ V_91 ) ;
V_90 = F_27 ( ! ( F_6 ( V_75 ) & V_91 ) , 1 ) ;
F_28 ( V_90 , L_5 ) ;
if ( F_25 ( F_29 ( V_89 ) ) &
V_92 ) {
F_21 ( F_29 ( V_89 ) ,
V_93 ) ;
F_21 ( F_29 ( V_89 ) , 0 ) ;
}
F_24 ( F_25 ( F_29 ( V_89 ) ) & V_93 ) ;
F_24 ( F_30 ( F_25 ( F_31 ( V_89 ) ) ,
V_94 ) !=
V_95 ) ;
F_24 ( ( F_25 ( F_31 ( V_89 ) ) &
( V_96 | V_97 ) ) !=
V_97 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_39 * V_40 = F_17 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_34 = V_3 -> V_34 ;
struct V_41 * V_42 = & V_34 -> V_43 ;
F_23 ( V_18 ) ;
F_21 ( F_29 ( V_1 -> V_84 ) ,
F_20 ( V_42 -> V_60 , V_98 ) |
F_20 ( V_42 -> V_48 , V_99 ) |
V_92 ) ;
F_19 ( V_75 ,
F_6 ( V_75 ) | V_91 ) ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_5 * V_34 )
{
struct V_4 * V_100 = F_2 ( V_34 ) ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_39 * V_40 = F_17 ( V_18 ) ;
struct V_101 * V_102 ;
unsigned long V_45 ;
T_1 V_103 = 0 ;
int V_90 ;
if ( F_34 ( V_34 -> V_104 ) > 1 )
return - V_105 ;
F_35 (plane, state) {
struct V_106 * V_107 =
V_34 -> V_34 -> V_108 [ F_36 ( V_102 ) ] ;
if ( ! V_107 )
V_107 = V_102 -> V_34 ;
V_103 += F_37 ( V_107 ) ;
}
V_103 ++ ;
F_38 ( & V_40 -> V_109 -> V_110 , V_45 ) ;
V_90 = F_39 ( & V_40 -> V_109 -> V_111 , & V_100 -> V_112 ,
V_103 , 1 , 0 ) ;
F_40 ( & V_40 -> V_109 -> V_110 , V_45 ) ;
if ( V_90 )
return V_90 ;
return 0 ;
}
static void F_41 ( struct V_2 * V_3 ,
struct V_5 * V_113 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_39 * V_40 = F_17 ( V_18 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_100 = F_2 ( V_3 -> V_34 ) ;
struct V_101 * V_102 ;
bool V_49 = false ;
T_1 T_2 * V_114 = V_40 -> V_109 -> V_115 + V_100 -> V_112 . V_116 ;
T_1 T_2 * V_117 = V_114 ;
if ( V_49 ) {
F_5 ( L_6 , F_18 ( V_3 ) ) ;
F_42 ( V_18 ) ;
}
F_43 (plane, crtc) {
V_117 += F_44 ( V_102 , V_117 ) ;
}
F_45 ( V_118 , V_117 ) ;
V_117 ++ ;
F_24 ( V_117 - V_114 != V_100 -> V_112 . V_119 ) ;
F_21 ( F_46 ( V_1 -> V_84 ) ,
V_100 -> V_112 . V_116 ) ;
if ( V_49 ) {
F_5 ( L_7 , F_18 ( V_3 ) ) ;
F_42 ( V_18 ) ;
}
if ( V_3 -> V_34 -> V_120 ) {
unsigned long V_45 ;
V_3 -> V_34 -> V_120 -> V_121 = F_18 ( V_3 ) ;
F_47 ( F_48 ( V_3 ) != 0 ) ;
F_38 ( & V_18 -> V_122 , V_45 ) ;
V_1 -> V_120 = V_3 -> V_34 -> V_120 ;
F_40 ( & V_18 -> V_122 , V_45 ) ;
V_3 -> V_34 -> V_120 = NULL ;
}
}
int F_49 ( struct V_17 * V_18 , unsigned int V_123 )
{
struct V_39 * V_40 = F_17 ( V_18 ) ;
struct V_1 * V_1 = V_40 -> V_3 [ V_123 ] ;
F_19 ( V_124 , V_125 ) ;
return 0 ;
}
void F_50 ( struct V_17 * V_18 , unsigned int V_123 )
{
struct V_39 * V_40 = F_17 ( V_18 ) ;
struct V_1 * V_1 = V_40 -> V_3 [ V_123 ] ;
F_19 ( V_124 , 0 ) ;
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_126 ;
struct V_17 * V_18 = V_3 -> V_18 ;
unsigned long V_45 ;
F_38 ( & V_18 -> V_122 , V_45 ) ;
if ( V_1 -> V_120 ) {
F_52 ( V_3 , V_1 -> V_120 ) ;
V_1 -> V_120 = NULL ;
}
F_40 ( & V_18 -> V_122 , V_45 ) ;
}
static T_3 F_53 ( int V_127 , void * V_23 )
{
struct V_1 * V_1 = V_23 ;
T_1 V_128 = F_6 ( V_129 ) ;
T_3 V_90 = V_130 ;
if ( V_128 & V_125 ) {
F_19 ( V_129 , V_125 ) ;
F_54 ( & V_1 -> V_126 ) ;
F_51 ( V_1 ) ;
V_90 = V_131 ;
}
return V_90 ;
}
static void
F_55 ( struct V_132 * V_133 )
{
struct V_134 * V_135 =
F_56 ( V_133 , struct V_134 , V_133 ) ;
struct V_2 * V_3 = V_135 -> V_3 ;
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_39 * V_40 = F_17 ( V_18 ) ;
struct V_101 * V_102 = V_3 -> V_136 ;
F_57 ( V_102 , V_135 -> V_137 ) ;
if ( V_135 -> V_120 ) {
unsigned long V_45 ;
F_38 ( & V_18 -> V_122 , V_45 ) ;
F_52 ( V_3 , V_135 -> V_120 ) ;
F_40 ( & V_18 -> V_122 , V_45 ) ;
}
F_58 ( V_135 -> V_137 ) ;
F_59 ( V_135 ) ;
F_60 ( & V_40 -> V_138 ) ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_139 * V_137 ,
struct V_140 * V_120 ,
T_4 V_45 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_39 * V_40 = F_17 ( V_18 ) ;
struct V_101 * V_102 = V_3 -> V_136 ;
int V_90 = 0 ;
struct V_134 * V_135 ;
struct V_141 * V_142 = F_62 ( V_137 , 0 ) ;
struct V_143 * V_144 = F_63 ( & V_142 -> V_126 ) ;
V_135 = F_64 ( sizeof( * V_135 ) , V_145 ) ;
if ( ! V_135 )
return - V_146 ;
F_65 ( V_137 ) ;
V_135 -> V_137 = V_137 ;
V_135 -> V_3 = V_3 ;
V_135 -> V_120 = V_120 ;
V_90 = F_66 ( & V_40 -> V_138 ) ;
if ( V_90 ) {
F_58 ( V_137 ) ;
F_59 ( V_135 ) ;
return V_90 ;
}
F_67 ( V_102 -> V_34 , V_137 ) ;
V_102 -> V_137 = V_137 ;
F_68 ( V_18 , & V_135 -> V_133 , V_144 -> V_147 ,
F_55 ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_139 * V_137 ,
struct V_140 * V_120 ,
T_4 V_45 )
{
if ( V_45 & V_148 )
return F_61 ( V_3 , V_137 , V_120 , V_45 ) ;
else
return F_70 ( V_3 , V_137 , V_120 , V_45 ) ;
}
static struct V_5 * F_71 ( struct V_2 * V_3 )
{
struct V_4 * V_100 ;
V_100 = F_64 ( sizeof( * V_100 ) , V_145 ) ;
if ( ! V_100 )
return NULL ;
F_72 ( V_3 , & V_100 -> V_126 ) ;
return & V_100 -> V_126 ;
}
static void F_73 ( struct V_2 * V_3 ,
struct V_5 * V_34 )
{
struct V_39 * V_40 = F_17 ( V_3 -> V_18 ) ;
struct V_4 * V_100 = F_2 ( V_34 ) ;
if ( V_100 -> V_112 . V_149 ) {
unsigned long V_45 ;
F_38 ( & V_40 -> V_109 -> V_110 , V_45 ) ;
F_74 ( & V_100 -> V_112 ) ;
F_40 ( & V_40 -> V_109 -> V_110 , V_45 ) ;
}
F_75 ( V_3 , V_34 ) ;
}
static void F_76 ( struct V_17 * V_150 ,
struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_35 * V_36 ;
F_77 (encoder, drm) {
struct V_37 * V_37 = F_15 ( V_36 ) ;
if ( V_37 -> type == V_1 -> V_23 -> V_151 ) {
V_37 -> V_38 = 0 ;
V_36 -> V_152 |= F_78 ( V_3 ) ;
} else if ( V_37 -> type == V_1 -> V_23 -> V_153 ) {
V_37 -> V_38 = 1 ;
V_36 -> V_152 |= F_78 ( V_3 ) ;
}
}
}
static int F_79 ( struct V_154 * V_18 , struct V_154 * V_155 , void * V_23 )
{
struct V_156 * V_157 = F_80 ( V_18 ) ;
struct V_17 * V_150 = F_81 ( V_155 ) ;
struct V_39 * V_40 = F_17 ( V_150 ) ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_101 * V_158 , * V_159 , * V_160 , * V_161 ;
const struct V_162 * V_163 ;
int V_90 , V_7 ;
V_1 = F_82 ( V_18 , sizeof( * V_1 ) , V_145 ) ;
if ( ! V_1 )
return - V_146 ;
V_3 = & V_1 -> V_126 ;
V_163 = F_83 ( V_164 , V_18 ) ;
if ( ! V_163 )
return - V_165 ;
V_1 -> V_23 = V_163 -> V_23 ;
V_1 -> V_166 = F_84 ( V_157 , 0 ) ;
if ( F_85 ( V_1 -> V_166 ) )
return F_86 ( V_1 -> V_166 ) ;
V_158 = F_87 ( V_150 , V_167 ) ;
if ( F_85 ( V_158 ) ) {
F_88 ( V_18 , L_8 ) ;
V_90 = F_86 ( V_158 ) ;
goto V_168;
}
F_89 ( V_150 , V_3 , V_158 , NULL ,
& V_169 , NULL ) ;
F_90 ( V_3 , & V_170 ) ;
V_158 -> V_3 = V_3 ;
V_40 -> V_3 [ F_18 ( V_3 ) ] = V_1 ;
V_1 -> V_84 = V_1 -> V_23 -> V_171 ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
struct V_101 * V_102 =
F_87 ( V_150 , V_172 ) ;
if ( F_85 ( V_102 ) )
continue;
V_102 -> V_152 = 1 << F_18 ( V_3 ) ;
}
V_159 = F_87 ( V_150 , V_173 ) ;
if ( ! F_85 ( V_159 ) ) {
V_159 -> V_152 = 1 << F_18 ( V_3 ) ;
V_159 -> V_3 = V_3 ;
V_3 -> V_174 = V_159 ;
}
F_19 ( V_124 , 0 ) ;
F_19 ( V_129 , V_125 ) ;
V_90 = F_91 ( V_18 , F_92 ( V_157 , 0 ) ,
F_53 , 0 , L_9 , V_1 ) ;
if ( V_90 )
goto V_175;
F_76 ( V_150 , V_3 ) ;
F_93 ( V_157 , V_1 ) ;
return 0 ;
V_175:
F_94 (destroy_plane, temp,
&drm->mode_config.plane_list, head) {
if ( V_160 -> V_152 == 1 << F_18 ( V_3 ) )
V_160 -> V_176 -> V_177 ( V_160 ) ;
}
V_168:
return V_90 ;
}
static void F_95 ( struct V_154 * V_18 , struct V_154 * V_155 ,
void * V_23 )
{
struct V_156 * V_157 = F_80 ( V_18 ) ;
struct V_1 * V_1 = F_81 ( V_18 ) ;
F_10 ( & V_1 -> V_126 ) ;
F_19 ( V_124 , 0 ) ;
F_93 ( V_157 , NULL ) ;
}
static int F_96 ( struct V_156 * V_157 )
{
return F_97 ( & V_157 -> V_18 , & V_178 ) ;
}
static int F_98 ( struct V_156 * V_157 )
{
F_99 ( & V_157 -> V_18 , & V_178 ) ;
return 0 ;
}
