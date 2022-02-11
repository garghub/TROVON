static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , F_3 ( * V_4 ) , V_5 ) ;
F_4 ( & V_4 -> V_6 ) ;
return V_7 ;
}
int
F_5 ( struct V_8 * V_9 , unsigned int V_10 )
{
struct V_11 * V_12 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( V_4 -> V_13 == V_10 ) {
F_7 ( & V_4 -> V_5 ) ;
return 0 ;
}
}
return - V_14 ;
}
void
F_8 ( struct V_8 * V_9 , unsigned int V_10 )
{
struct V_11 * V_12 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( V_4 -> V_13 == V_10 ) {
F_9 ( & V_4 -> V_5 ) ;
return;
}
}
}
static inline int
F_10 ( int V_15 , int V_16 , int V_17 , int line )
{
if ( V_16 >= V_15 ) {
if ( line >= V_15 )
line -= V_17 ;
} else {
if ( line >= V_15 )
line -= V_17 ;
line -= V_16 + 1 ;
}
return line ;
}
static int
F_11 ( struct V_11 * V_12 , int * V_18 , int * V_19 ,
T_1 * V_20 , T_1 * V_21 )
{
struct {
struct V_22 V_6 ;
struct V_23 V_24 ;
} args = {
. V_6 . V_25 = V_26 ,
. V_6 . V_27 = V_3 ( V_12 ) -> V_13 ,
} ;
struct V_28 * V_29 = V_28 ( V_12 -> V_9 ) ;
struct V_30 * V_5 = & V_12 -> V_9 -> V_5 [ F_12 ( V_12 ) ] ;
int V_31 , V_32 = 1 ;
do {
V_31 = F_13 ( & V_29 -> V_29 , 0 , & args , sizeof( args ) ) ;
if ( V_31 != 0 )
return 0 ;
if ( args . V_24 . V_33 ) {
V_31 |= V_34 ;
V_31 |= V_35 ;
break;
}
if ( V_32 ) F_14 ( V_5 -> V_36 ) ;
} while ( V_32 -- );
* V_19 = args . V_24 . V_37 ;
* V_18 = F_10 ( args . V_24 . V_38 , args . V_24 . V_39 ,
args . V_24 . V_40 , args . V_24 . V_33 ) ;
if ( V_20 ) * V_20 = F_15 ( args . V_24 . time [ 0 ] ) ;
if ( V_21 ) * V_21 = F_15 ( args . V_24 . time [ 1 ] ) ;
if ( * V_18 < 0 )
V_31 |= V_41 ;
return V_31 ;
}
int
F_16 ( struct V_8 * V_9 , unsigned int V_10 ,
unsigned int V_42 , int * V_18 , int * V_19 ,
T_1 * V_20 , T_1 * V_21 ,
const struct V_43 * V_44 )
{
struct V_11 * V_12 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_3 ( V_12 ) -> V_13 == V_10 ) {
return F_11 ( V_12 , V_18 , V_19 ,
V_20 , V_21 ) ;
}
}
return 0 ;
}
int
F_17 ( struct V_8 * V_9 , unsigned int V_10 ,
int * V_45 , struct V_46 * time , unsigned V_42 )
{
struct V_11 * V_12 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_3 ( V_12 ) -> V_13 == V_10 ) {
struct V_43 * V_44 ;
if ( V_9 -> V_47 . V_48 -> V_49 )
V_44 = & V_12 -> V_50 -> V_51 ;
else
V_44 = & V_12 -> V_52 ;
return F_18 ( V_9 ,
V_10 , V_45 , time , V_42 , V_44 ) ;
}
}
return - V_14 ;
}
static void
F_19 ( struct V_8 * V_9 )
{
struct V_11 * V_12 ;
F_20 ( V_9 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
F_21 ( & V_4 -> V_5 ) ;
}
}
static int
F_22 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_11 * V_12 ;
int V_31 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
V_31 = F_23 (&disp->disp,
nouveau_display_vblank_handler, false,
NV04_DISP_NTFY_VBLANK,
&(struct nvif_notify_head_req_v0) {
.head = nv_crtc->index,
},
sizeof(struct nvif_notify_head_req_v0),
sizeof(struct nvif_notify_head_rep_v0),
&nv_crtc->vblank) ;
if ( V_31 ) {
F_19 ( V_9 ) ;
return V_31 ;
}
}
V_31 = F_24 ( V_9 , V_9 -> V_47 . V_53 ) ;
if ( V_31 ) {
F_19 ( V_9 ) ;
return V_31 ;
}
return 0 ;
}
static void
F_25 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = V_56 ( V_55 ) ;
if ( V_57 -> V_58 )
F_26 ( & V_57 -> V_58 -> V_59 ) ;
F_27 ( V_55 ) ;
F_28 ( V_57 ) ;
}
static int
F_29 ( struct V_54 * V_55 ,
struct V_60 * V_61 ,
unsigned int * V_62 )
{
struct V_56 * V_57 = V_56 ( V_55 ) ;
return F_30 ( V_61 , & V_57 -> V_58 -> V_59 , V_62 ) ;
}
int
F_31 ( struct V_8 * V_9 ,
const struct V_63 * V_64 ,
struct V_65 * V_58 ,
struct V_56 * * V_66 )
{
struct V_56 * V_57 ;
int V_31 ;
if ( ! ( V_57 = * V_66 = F_32 ( sizeof( * V_57 ) , V_67 ) ) )
return - V_68 ;
F_33 ( & V_57 -> V_6 , V_64 ) ;
V_57 -> V_58 = V_58 ;
V_31 = F_34 ( V_9 , & V_57 -> V_6 , & V_69 ) ;
if ( V_31 )
F_28 ( V_57 ) ;
return V_31 ;
}
struct V_54 *
F_35 ( struct V_8 * V_9 ,
struct V_60 * V_61 ,
const struct V_63 * V_64 )
{
struct V_56 * V_57 ;
struct V_65 * V_58 ;
struct V_70 * V_59 ;
int V_31 ;
V_59 = F_36 ( V_61 , V_64 -> V_71 [ 0 ] ) ;
if ( ! V_59 )
return F_37 ( - V_72 ) ;
V_58 = F_38 ( V_59 ) ;
V_31 = F_31 ( V_9 , V_64 , V_58 , & V_57 ) ;
if ( V_31 == 0 )
return & V_57 -> V_6 ;
F_26 ( V_59 ) ;
return F_37 ( V_31 ) ;
}
static void
F_39 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_2 ( V_74 , F_3 ( * V_76 ) , V_77 ) ;
F_40 ( V_76 -> V_9 -> V_9 ) ;
F_41 ( V_76 -> V_9 ) ;
F_42 ( V_76 -> V_9 -> V_9 ) ;
F_43 ( V_76 -> V_9 -> V_9 ) ;
}
static int
F_44 ( struct V_78 * V_79 , unsigned long V_80 ,
void * V_81 )
{
struct V_75 * V_76 = F_2 ( V_79 , F_3 ( * V_76 ) , V_82 ) ;
struct V_83 * V_84 = V_81 ;
if ( ! strcmp ( V_84 -> V_85 , V_86 ) ) {
if ( V_84 -> type == V_87 ) {
F_45 ( & V_76 -> V_77 ) ;
return V_88 ;
}
}
return V_89 ;
}
int
F_46 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_75 * V_76 = V_75 ( V_9 ) ;
struct V_90 * V_91 ;
int V_31 ;
V_31 = V_29 -> V_92 ( V_9 ) ;
if ( V_31 )
return V_31 ;
if ( ! V_9 -> V_47 . V_93 )
F_47 ( V_9 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
struct V_94 * V_95 = V_94 ( V_91 ) ;
F_7 ( & V_95 -> V_96 ) ;
}
F_7 ( & V_76 -> V_97 ) ;
return V_31 ;
}
void
F_48 ( struct V_8 * V_9 , bool V_98 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_75 * V_76 = V_75 ( V_9 ) ;
struct V_90 * V_91 ;
struct V_11 * V_12 ;
if ( ! V_98 )
F_49 ( V_9 ) ;
F_50 (crtc, dev)
F_51 ( V_12 ) ;
F_9 ( & V_76 -> V_97 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
struct V_94 * V_95 = V_94 ( V_91 ) ;
F_9 ( & V_95 -> V_96 ) ;
}
F_52 ( V_9 ) ;
V_29 -> V_99 ( V_9 ) ;
}
static void
F_53 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
int V_100 ;
if ( V_29 -> V_29 . V_101 < V_102 )
V_100 = 0 ;
else
if ( V_29 -> V_29 . V_101 < V_103 )
V_100 = 1 ;
else
V_100 = 2 ;
F_54 ( V_29 -> V_104 , V_100 , L_1 , V_105 ) ;
F_54 ( V_29 -> V_106 , V_100 , L_2 , V_107 ) ;
F_54 ( V_29 -> V_108 , V_100 , L_3 , V_109 ) ;
V_29 -> V_110 =
F_55 ( V_9 , 0 , L_4 , 0 , 128 ) ;
V_29 -> V_111 =
F_55 ( V_9 , 0 , L_5 , 0 , 128 ) ;
if ( V_100 < 1 )
return;
V_29 -> V_112 =
F_55 ( V_9 , 0 , L_6 , 0 , 180 ) ;
V_29 -> V_113 =
F_55 ( V_9 , 0 , L_7 , 0 , 200 ) ;
}
int
F_56 ( struct V_8 * V_9 )
{
struct V_75 * V_76 = V_75 ( V_9 ) ;
struct V_114 * V_115 = F_57 ( & V_76 -> V_115 ) ;
struct V_28 * V_29 ;
int V_31 ;
V_29 = V_76 -> V_116 = F_32 ( sizeof( * V_29 ) , V_67 ) ;
if ( ! V_29 )
return - V_68 ;
F_58 ( V_9 ) ;
F_59 ( V_9 ) ;
F_60 ( V_9 ) ;
V_9 -> V_47 . V_48 = & V_117 ;
V_9 -> V_47 . V_118 = V_115 -> V_119 -> V_120 ( V_115 , 1 ) ;
V_9 -> V_47 . V_121 = 0 ;
V_9 -> V_47 . V_122 = 0 ;
if ( V_76 -> V_115 . V_84 . V_123 < V_124 ) {
V_9 -> V_47 . V_125 = 2048 ;
V_9 -> V_47 . V_126 = 2048 ;
} else
if ( V_76 -> V_115 . V_84 . V_123 < V_127 ) {
V_9 -> V_47 . V_125 = 4096 ;
V_9 -> V_47 . V_126 = 4096 ;
} else
if ( V_76 -> V_115 . V_84 . V_123 < V_128 ) {
V_9 -> V_47 . V_125 = 8192 ;
V_9 -> V_47 . V_126 = 8192 ;
} else {
V_9 -> V_47 . V_125 = 16384 ;
V_9 -> V_47 . V_126 = 16384 ;
}
V_9 -> V_47 . V_129 = 24 ;
V_9 -> V_47 . V_130 = 1 ;
if ( V_76 -> V_115 . V_84 . V_131 < 0x11 )
V_9 -> V_47 . V_132 = false ;
else
V_9 -> V_47 . V_132 = true ;
F_61 ( V_9 ) ;
F_52 ( V_9 ) ;
if ( V_133 != 2 && V_76 -> V_134 . V_135 . V_136 ) {
static const T_2 V_101 [] = {
V_137 ,
V_138 ,
V_139 ,
V_140 ,
V_141 ,
V_142 ,
V_103 ,
V_143 ,
V_144 ,
V_145 ,
V_146 ,
V_102 ,
V_147 ,
} ;
int V_148 ;
for ( V_148 = 0 , V_31 = - V_149 ; V_31 && V_148 < F_62 ( V_101 ) ; V_148 ++ ) {
V_31 = F_63 ( & V_76 -> V_115 . V_150 , 0 ,
V_101 [ V_148 ] , NULL , 0 , & V_29 -> V_29 ) ;
}
if ( V_31 == 0 ) {
F_53 ( V_9 ) ;
if ( V_29 -> V_29 . V_101 < V_102 )
V_31 = F_64 ( V_9 ) ;
else
V_31 = F_65 ( V_9 ) ;
}
} else {
V_31 = 0 ;
}
if ( V_31 )
goto V_151;
F_66 ( V_9 ) ;
if ( V_9 -> V_47 . V_53 ) {
V_31 = F_22 ( V_9 ) ;
if ( V_31 )
goto V_152;
}
F_67 ( V_9 ) ;
F_68 ( & V_76 -> V_77 , F_39 ) ;
#ifdef F_69
V_76 -> V_82 . V_153 = F_44 ;
F_70 ( & V_76 -> V_82 ) ;
#endif
return 0 ;
V_152:
V_29 -> V_154 ( V_9 ) ;
V_151:
F_71 ( V_9 ) ;
F_72 ( V_9 ) ;
return V_31 ;
}
void
F_73 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
#ifdef F_69
F_74 ( & V_75 ( V_9 ) -> V_82 ) ;
#endif
F_75 ( V_9 ) ;
F_19 ( V_9 ) ;
F_71 ( V_9 ) ;
F_72 ( V_9 ) ;
if ( V_29 -> V_154 )
V_29 -> V_154 ( V_9 ) ;
F_76 ( & V_29 -> V_29 ) ;
V_75 ( V_9 ) -> V_116 = NULL ;
F_28 ( V_29 ) ;
}
static int
F_77 ( struct V_155 * V_50 ,
struct V_90 * V_91 )
{
struct V_156 * V_157 ;
struct V_11 * V_12 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
int V_31 ;
if ( ! ( V_12 = V_91 -> V_50 -> V_12 ) )
return 0 ;
V_157 = F_78 ( V_50 , V_91 ) ;
if ( F_79 ( V_157 ) )
return F_80 ( V_157 ) ;
V_31 = F_81 ( V_157 , NULL ) ;
if ( V_31 )
return V_31 ;
V_159 = F_82 ( V_50 , V_12 ) ;
if ( F_79 ( V_159 ) )
return F_80 ( V_159 ) ;
V_31 = F_83 ( V_159 , NULL ) ;
if ( V_31 )
return V_31 ;
V_159 -> V_164 = false ;
F_84 (plane, connector->dev, crtc_state->plane_mask) {
V_161 = F_85 ( V_50 , V_163 ) ;
if ( F_79 ( V_161 ) )
return F_80 ( V_161 ) ;
V_31 = F_86 ( V_161 , NULL ) ;
if ( V_31 )
return V_31 ;
F_87 ( V_161 , NULL ) ;
}
return 0 ;
}
static int
F_88 ( struct V_8 * V_9 ,
struct V_165 * V_166 )
{
struct V_155 * V_50 ;
struct V_90 * V_91 ;
int V_31 ;
V_50 = F_89 ( V_9 ) ;
if ( ! V_50 )
return - V_68 ;
V_50 -> V_167 = V_166 ;
F_90 (connector, dev) {
V_31 = F_77 ( V_50 , V_91 ) ;
if ( V_31 )
break;
}
if ( V_31 == 0 )
V_31 = F_91 ( V_50 ) ;
F_92 ( V_50 ) ;
return V_31 ;
}
static struct V_155 *
F_93 ( struct V_8 * V_9 )
{
struct V_165 V_166 ;
struct V_155 * V_50 ;
int V_31 ;
F_94 ( & V_166 , 0 ) ;
V_32:
V_31 = F_95 ( V_9 , & V_166 ) ;
if ( V_31 < 0 ) {
V_50 = F_37 ( V_31 ) ;
goto V_168;
}
V_50 = F_96 ( V_9 , & V_166 ) ;
if ( F_79 ( V_50 ) )
goto V_168;
V_31 = F_88 ( V_9 , & V_166 ) ;
if ( V_31 < 0 ) {
F_92 ( V_50 ) ;
V_50 = F_37 ( V_31 ) ;
goto V_168;
}
V_168:
if ( F_80 ( V_50 ) == - V_169 ) {
F_97 ( & V_166 ) ;
goto V_32;
}
F_98 ( & V_166 ) ;
F_99 ( & V_166 ) ;
return V_50 ;
}
int
F_100 ( struct V_8 * V_9 , bool V_170 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_11 * V_12 ;
if ( V_9 -> V_47 . V_48 -> V_49 ) {
if ( ! V_170 ) {
V_29 -> V_98 = F_93 ( V_9 ) ;
if ( F_79 ( V_29 -> V_98 ) ) {
int V_31 = F_80 ( V_29 -> V_98 ) ;
V_29 -> V_98 = NULL ;
return V_31 ;
}
}
F_48 ( V_9 , true ) ;
return 0 ;
}
F_48 ( V_9 , true ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_56 * V_171 ;
V_171 = V_56 ( V_12 -> V_172 -> V_57 ) ;
if ( ! V_171 || ! V_171 -> V_58 )
continue;
F_101 ( V_171 -> V_58 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( V_4 -> V_173 . V_58 ) {
if ( V_4 -> V_173 . V_174 )
F_102 ( V_4 -> V_173 . V_58 ) ;
F_101 ( V_4 -> V_173 . V_58 ) ;
}
}
return 0 ;
}
void
F_103 ( struct V_8 * V_9 , bool V_170 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_75 * V_76 = V_75 ( V_9 ) ;
struct V_11 * V_12 ;
int V_31 ;
if ( V_9 -> V_47 . V_48 -> V_49 ) {
F_46 ( V_9 ) ;
if ( V_29 -> V_98 ) {
F_104 ( V_9 , V_29 -> V_98 ) ;
V_29 -> V_98 = NULL ;
}
return;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_56 * V_171 ;
V_171 = V_56 ( V_12 -> V_172 -> V_57 ) ;
if ( ! V_171 || ! V_171 -> V_58 )
continue;
V_31 = F_105 ( V_171 -> V_58 , V_175 , true ) ;
if ( V_31 )
F_106 ( V_76 , L_8 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_173 . V_58 )
continue;
V_31 = F_105 ( V_4 -> V_173 . V_58 , V_175 , true ) ;
if ( ! V_31 && V_4 -> V_173 . V_174 )
V_31 = F_107 ( V_4 -> V_173 . V_58 ) ;
if ( V_31 )
F_106 ( V_76 , L_9 ) ;
}
F_46 ( V_9 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
V_4 -> V_176 . V_177 = 0 ;
}
if ( V_170 )
return;
F_108 ( V_9 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_173 . V_58 )
continue;
if ( V_4 -> V_173 . V_174 )
V_4 -> V_173 . V_174 ( V_4 , V_4 -> V_173 . V_58 -> V_178 . V_179 ) ;
V_4 -> V_173 . V_180 ( V_4 , V_4 -> V_181 ,
V_4 -> V_182 ) ;
}
}
static int
F_109 ( struct V_183 * V_184 ,
struct V_65 * V_185 ,
struct V_65 * V_186 ,
struct V_187 * V_188 ,
struct V_189 * * V_190 )
{
struct V_191 * V_192 = V_184 -> V_193 ;
struct V_75 * V_76 = V_184 -> V_76 ;
struct V_8 * V_9 = V_76 -> V_9 ;
unsigned long V_42 ;
int V_31 ;
F_110 ( & V_9 -> V_194 , V_42 ) ;
F_111 ( & V_188 -> V_27 , & V_192 -> V_97 ) ;
F_112 ( & V_9 -> V_194 , V_42 ) ;
V_31 = F_113 ( V_185 , V_184 , false , false ) ;
if ( V_31 )
goto V_195;
V_31 = F_114 ( V_184 , 2 ) ;
if ( V_31 )
goto V_195;
F_115 ( V_184 , V_196 , V_197 , 1 ) ;
F_116 ( V_184 , 0x00000000 ) ;
F_117 ( V_184 ) ;
V_31 = F_118 ( V_184 , false , V_190 ) ;
if ( V_31 )
goto V_195;
return 0 ;
V_195:
F_110 ( & V_9 -> V_194 , V_42 ) ;
F_119 ( & V_188 -> V_27 ) ;
F_112 ( & V_9 -> V_194 , V_42 ) ;
return V_31 ;
}
int
F_120 ( struct V_11 * V_12 , struct V_54 * V_57 ,
struct V_198 * V_199 , T_3 V_42 )
{
const int V_200 = ( V_42 & V_201 ) ? 0 : 1 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_75 * V_76 = V_75 ( V_9 ) ;
struct V_65 * V_185 = V_56 ( V_12 -> V_172 -> V_57 ) -> V_58 ;
struct V_65 * V_186 = V_56 ( V_57 ) -> V_58 ;
struct V_187 * V_188 ;
struct V_183 * V_184 ;
struct V_202 * V_203 ;
struct V_189 * V_193 ;
struct V_204 * V_205 = V_204 ( V_9 ) ;
int V_27 = V_3 ( V_12 ) -> V_13 ;
int V_31 ;
V_184 = V_76 -> V_206 ;
if ( ! V_184 )
return - V_149 ;
V_203 = ( void * ) V_184 -> V_207 . V_208 ;
V_188 = F_32 ( sizeof( * V_188 ) , V_67 ) ;
if ( ! V_188 )
return - V_68 ;
if ( V_186 != V_185 ) {
V_31 = F_105 ( V_186 , V_175 , true ) ;
if ( V_31 )
goto V_209;
}
F_121 ( & V_203 -> V_210 ) ;
V_31 = F_122 ( & V_186 -> V_178 , true , false , NULL ) ;
if ( V_31 )
goto V_211;
V_31 = F_113 ( V_186 , V_184 , false , true ) ;
if ( V_31 ) {
F_123 ( & V_186 -> V_178 ) ;
goto V_211;
}
if ( V_186 != V_185 ) {
F_123 ( & V_186 -> V_178 ) ;
V_31 = F_122 ( & V_185 -> V_178 , true , false , NULL ) ;
if ( V_31 )
goto V_211;
}
* V_188 = (struct V_187 )
{ { } , V_199 , V_12 , V_57 -> V_212 , V_57 -> V_213 [ 0 ] ,
V_186 -> V_178 . V_179 } ;
F_124 ( V_12 ) ;
if ( V_200 ) {
V_31 = F_114 ( V_184 , 8 ) ;
if ( V_31 )
goto V_214;
F_115 ( V_184 , V_215 , 0x012c , 1 ) ;
F_116 ( V_184 , 0 ) ;
F_115 ( V_184 , V_215 , 0x0134 , 1 ) ;
F_116 ( V_184 , V_27 ) ;
F_115 ( V_184 , V_215 , 0x0100 , 1 ) ;
F_116 ( V_184 , 0 ) ;
F_115 ( V_184 , V_215 , 0x0130 , 1 ) ;
F_116 ( V_184 , 0 ) ;
}
F_125 ( V_186 , & V_205 -> V_216 [ V_27 ] ) ;
V_31 = F_109 ( V_184 , V_185 , V_186 , V_188 , & V_193 ) ;
if ( V_31 )
goto V_214;
F_126 ( & V_203 -> V_210 ) ;
V_12 -> V_172 -> V_57 = V_57 ;
F_127 ( V_185 , V_193 , false ) ;
F_123 ( & V_185 -> V_178 ) ;
if ( V_185 != V_186 )
F_101 ( V_185 ) ;
F_128 ( & V_193 ) ;
return 0 ;
V_214:
F_129 ( V_12 ) ;
F_123 ( & V_185 -> V_178 ) ;
V_211:
F_126 ( & V_203 -> V_210 ) ;
if ( V_185 != V_186 )
F_101 ( V_186 ) ;
V_209:
F_28 ( V_188 ) ;
return V_31 ;
}
int
F_130 ( struct V_183 * V_184 ,
struct V_187 * V_217 )
{
struct V_191 * V_192 = V_184 -> V_193 ;
struct V_75 * V_76 = V_184 -> V_76 ;
struct V_8 * V_9 = V_76 -> V_9 ;
struct V_187 * V_188 ;
unsigned long V_42 ;
F_110 ( & V_9 -> V_194 , V_42 ) ;
if ( F_131 ( & V_192 -> V_97 ) ) {
F_106 ( V_76 , L_10 ) ;
F_112 ( & V_9 -> V_194 , V_42 ) ;
return - V_14 ;
}
V_188 = F_132 ( & V_192 -> V_97 , struct V_187 , V_27 ) ;
if ( V_188 -> V_199 ) {
F_133 ( V_188 -> V_12 , V_188 -> V_199 ) ;
} else {
F_129 ( V_188 -> V_12 ) ;
}
F_119 ( & V_188 -> V_27 ) ;
if ( V_217 )
* V_217 = * V_188 ;
F_28 ( V_188 ) ;
F_112 ( & V_9 -> V_194 , V_42 ) ;
return 0 ;
}
int
F_134 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = F_2 ( V_2 , F_3 ( * V_76 ) , V_97 ) ;
struct V_183 * V_184 = V_76 -> V_206 ;
struct V_187 V_50 ;
if ( ! F_130 ( V_184 , & V_50 ) ) {
F_135 ( V_76 -> V_9 , F_12 ( V_50 . V_12 ) ,
V_50 . V_179 + V_50 . V_12 -> V_218 *
V_50 . V_219 + V_50 . V_12 -> V_220 *
V_50 . V_221 / 8 ) ;
}
return V_7 ;
}
int
F_136 ( struct V_60 * V_61 , struct V_8 * V_9 ,
struct V_222 * args )
{
struct V_65 * V_178 ;
T_4 V_223 ;
int V_31 ;
args -> V_219 = F_137 ( args -> V_224 * ( args -> V_221 / 8 ) , 256 ) ;
args -> V_225 = args -> V_219 * args -> V_226 ;
args -> V_225 = F_137 ( args -> V_225 , V_227 ) ;
if ( V_75 ( V_9 ) -> V_115 . V_84 . V_228 != 0 )
V_223 = V_229 ;
else
V_223 = V_230 ;
V_31 = F_138 ( V_9 , args -> V_225 , 0 , V_223 , 0 , 0 , & V_178 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_30 ( V_61 , & V_178 -> V_59 , & args -> V_62 ) ;
F_26 ( & V_178 -> V_59 ) ;
return V_31 ;
}
int
F_139 ( struct V_60 * V_61 ,
struct V_8 * V_9 ,
T_4 V_62 , T_5 * V_231 )
{
struct V_70 * V_59 ;
V_59 = F_36 ( V_61 , V_62 ) ;
if ( V_59 ) {
struct V_65 * V_178 = F_38 ( V_59 ) ;
* V_231 = F_140 ( & V_178 -> V_178 . V_232 ) ;
F_26 ( V_59 ) ;
return 0 ;
}
return - V_72 ;
}
