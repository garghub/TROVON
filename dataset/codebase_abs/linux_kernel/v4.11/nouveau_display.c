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
struct V_3 * V_4 ;
V_12 = F_6 ( V_9 , V_10 ) ;
if ( ! V_12 )
return - V_13 ;
V_4 = V_3 ( V_12 ) ;
F_7 ( & V_4 -> V_5 ) ;
return 0 ;
}
void
F_8 ( struct V_8 * V_9 , unsigned int V_10 )
{
struct V_11 * V_12 ;
struct V_3 * V_4 ;
V_12 = F_6 ( V_9 , V_10 ) ;
if ( ! V_12 )
return;
V_4 = V_3 ( V_12 ) ;
F_9 ( & V_4 -> V_5 ) ;
}
static inline int
F_10 ( int V_14 , int V_15 , int V_16 , int line )
{
if ( V_15 >= V_14 ) {
if ( line >= V_14 )
line -= V_16 ;
} else {
if ( line >= V_14 )
line -= V_16 ;
line -= V_15 + 1 ;
}
return line ;
}
static int
F_11 ( struct V_11 * V_12 , int * V_17 , int * V_18 ,
T_1 * V_19 , T_1 * V_20 )
{
struct {
struct V_21 V_6 ;
struct V_22 V_23 ;
} args = {
. V_6 . V_24 = V_25 ,
. V_6 . V_26 = V_3 ( V_12 ) -> V_27 ,
} ;
struct V_28 * V_29 = V_28 ( V_12 -> V_9 ) ;
struct V_30 * V_5 = & V_12 -> V_9 -> V_5 [ F_12 ( V_12 ) ] ;
int V_31 , V_32 = 1 ;
do {
V_31 = F_13 ( & V_29 -> V_29 , 0 , & args , sizeof( args ) ) ;
if ( V_31 != 0 )
return 0 ;
if ( args . V_23 . V_33 ) {
V_31 |= V_34 ;
V_31 |= V_35 ;
break;
}
if ( V_32 ) F_14 ( V_5 -> V_36 ) ;
} while ( V_32 -- );
* V_18 = args . V_23 . V_37 ;
* V_17 = F_10 ( args . V_23 . V_38 , args . V_23 . V_39 ,
args . V_23 . V_40 , args . V_23 . V_33 ) ;
if ( V_19 ) * V_19 = F_15 ( args . V_23 . time [ 0 ] ) ;
if ( V_20 ) * V_20 = F_15 ( args . V_23 . time [ 1 ] ) ;
if ( * V_17 < 0 )
V_31 |= V_41 ;
return V_31 ;
}
int
F_16 ( struct V_8 * V_9 , unsigned int V_10 ,
unsigned int V_42 , int * V_17 , int * V_18 ,
T_1 * V_19 , T_1 * V_20 ,
const struct V_43 * V_44 )
{
struct V_11 * V_12 ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_3 ( V_12 ) -> V_27 == V_10 ) {
return F_11 ( V_12 , V_17 , V_18 ,
V_19 , V_20 ) ;
}
}
return 0 ;
}
int
F_18 ( struct V_8 * V_9 , unsigned int V_10 ,
int * V_45 , struct V_46 * time , unsigned V_42 )
{
struct V_11 * V_12 ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_3 ( V_12 ) -> V_27 == V_10 ) {
struct V_43 * V_44 ;
if ( F_19 ( V_9 ) )
V_44 = & V_12 -> V_47 -> V_48 ;
else
V_44 = & V_12 -> V_49 ;
return F_20 ( V_9 ,
V_10 , V_45 , time , V_42 , V_44 ) ;
}
}
return - V_13 ;
}
static void
F_21 ( struct V_8 * V_9 )
{
struct V_11 * V_12 ;
F_22 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
F_23 ( & V_4 -> V_5 ) ;
}
}
static int
F_24 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_11 * V_12 ;
int V_31 ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
V_31 = F_25 (&disp->disp,
nouveau_display_vblank_handler, false,
NV04_DISP_NTFY_VBLANK,
&(struct nvif_notify_head_req_v0) {
.head = nv_crtc->index,
},
sizeof(struct nvif_notify_head_req_v0),
sizeof(struct nvif_notify_head_rep_v0),
&nv_crtc->vblank) ;
if ( V_31 ) {
F_21 ( V_9 ) ;
return V_31 ;
}
}
V_31 = F_26 ( V_9 , V_9 -> V_50 . V_51 ) ;
if ( V_31 ) {
F_21 ( V_9 ) ;
return V_31 ;
}
return 0 ;
}
static void
F_27 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_54 ( V_53 ) ;
if ( V_55 -> V_56 )
F_28 ( & V_55 -> V_56 -> V_57 ) ;
F_29 ( V_53 ) ;
F_30 ( V_55 ) ;
}
static int
F_31 ( struct V_52 * V_53 ,
struct V_58 * V_59 ,
unsigned int * V_60 )
{
struct V_54 * V_55 = V_54 ( V_53 ) ;
return F_32 ( V_59 , & V_55 -> V_56 -> V_57 , V_60 ) ;
}
int
F_33 ( struct V_8 * V_9 ,
const struct V_61 * V_62 ,
struct V_63 * V_56 ,
struct V_54 * * V_64 )
{
struct V_54 * V_55 ;
int V_31 ;
if ( ! ( V_55 = * V_64 = F_34 ( sizeof( * V_55 ) , V_65 ) ) )
return - V_66 ;
F_35 ( V_9 , & V_55 -> V_6 , V_62 ) ;
V_55 -> V_56 = V_56 ;
V_31 = F_36 ( V_9 , & V_55 -> V_6 , & V_67 ) ;
if ( V_31 )
F_30 ( V_55 ) ;
return V_31 ;
}
struct V_52 *
F_37 ( struct V_8 * V_9 ,
struct V_58 * V_59 ,
const struct V_61 * V_62 )
{
struct V_54 * V_55 ;
struct V_63 * V_56 ;
struct V_68 * V_57 ;
int V_31 ;
V_57 = F_38 ( V_59 , V_62 -> V_69 [ 0 ] ) ;
if ( ! V_57 )
return F_39 ( - V_70 ) ;
V_56 = F_40 ( V_57 ) ;
V_31 = F_33 ( V_9 , V_62 , V_56 , & V_55 ) ;
if ( V_31 == 0 )
return & V_55 -> V_6 ;
F_28 ( V_57 ) ;
return F_39 ( V_31 ) ;
}
static void
F_41 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_2 ( V_72 , F_3 ( * V_74 ) , V_75 ) ;
F_42 ( V_74 -> V_9 -> V_9 ) ;
F_43 ( V_74 -> V_9 ) ;
F_44 ( V_74 -> V_9 -> V_9 ) ;
F_45 ( V_74 -> V_9 -> V_9 ) ;
}
static int
F_46 ( struct V_76 * V_77 , unsigned long V_78 ,
void * V_79 )
{
struct V_73 * V_74 = F_2 ( V_77 , F_3 ( * V_74 ) , V_80 ) ;
struct V_81 * V_82 = V_79 ;
if ( ! strcmp ( V_82 -> V_83 , V_84 ) ) {
if ( V_82 -> type == V_85 ) {
F_47 ( & V_74 -> V_75 ) ;
return V_86 ;
}
}
return V_87 ;
}
int
F_48 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_88 * V_89 ;
int V_31 ;
V_31 = V_29 -> V_90 ( V_9 ) ;
if ( V_31 )
return V_31 ;
if ( ! V_9 -> V_50 . V_91 )
F_49 ( V_9 ) ;
F_17 (connector, &dev->mode_config.connector_list, head) {
struct V_92 * V_93 = V_92 ( V_89 ) ;
F_7 ( & V_93 -> V_94 ) ;
}
F_7 ( & V_74 -> V_95 ) ;
return V_31 ;
}
void
F_50 ( struct V_8 * V_9 , bool V_96 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_88 * V_89 ;
struct V_11 * V_12 ;
if ( ! V_96 )
F_51 ( V_9 ) ;
F_52 (crtc, dev)
F_53 ( V_12 ) ;
F_9 ( & V_74 -> V_95 ) ;
F_17 (connector, &dev->mode_config.connector_list, head) {
struct V_92 * V_93 = V_92 ( V_89 ) ;
F_9 ( & V_93 -> V_94 ) ;
}
F_54 ( V_9 ) ;
V_29 -> V_97 ( V_9 ) ;
}
static void
F_55 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
int V_98 ;
if ( V_29 -> V_29 . V_99 < V_100 )
V_98 = 0 ;
else
if ( V_29 -> V_29 . V_99 < V_101 )
V_98 = 1 ;
else
V_98 = 2 ;
F_56 ( V_29 -> V_102 , V_98 , L_1 , V_103 ) ;
F_56 ( V_29 -> V_104 , V_98 , L_2 , V_105 ) ;
F_56 ( V_29 -> V_106 , V_98 , L_3 , V_107 ) ;
V_29 -> V_108 =
F_57 ( V_9 , 0 , L_4 , 0 , 128 ) ;
V_29 -> V_109 =
F_57 ( V_9 , 0 , L_5 , 0 , 128 ) ;
if ( V_98 < 1 )
return;
V_29 -> V_110 =
F_57 ( V_9 , 0 , L_6 , 0 , 180 ) ;
V_29 -> V_111 =
F_57 ( V_9 , 0 , L_7 , 0 , 200 ) ;
}
int
F_58 ( struct V_8 * V_9 )
{
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_112 * V_113 = F_59 ( & V_74 -> V_114 . V_113 ) ;
struct V_28 * V_29 ;
int V_31 ;
V_29 = V_74 -> V_115 = F_34 ( sizeof( * V_29 ) , V_65 ) ;
if ( ! V_29 )
return - V_66 ;
F_60 ( V_9 ) ;
F_61 ( V_9 ) ;
F_62 ( V_9 ) ;
V_9 -> V_50 . V_116 = & V_117 ;
V_9 -> V_50 . V_118 = V_113 -> V_119 -> V_120 ( V_113 , 1 ) ;
V_9 -> V_50 . V_121 = 0 ;
V_9 -> V_50 . V_122 = 0 ;
if ( V_74 -> V_114 . V_113 . V_82 . V_123 < V_124 ) {
V_9 -> V_50 . V_125 = 2048 ;
V_9 -> V_50 . V_126 = 2048 ;
} else
if ( V_74 -> V_114 . V_113 . V_82 . V_123 < V_127 ) {
V_9 -> V_50 . V_125 = 4096 ;
V_9 -> V_50 . V_126 = 4096 ;
} else
if ( V_74 -> V_114 . V_113 . V_82 . V_123 < V_128 ) {
V_9 -> V_50 . V_125 = 8192 ;
V_9 -> V_50 . V_126 = 8192 ;
} else {
V_9 -> V_50 . V_125 = 16384 ;
V_9 -> V_50 . V_126 = 16384 ;
}
V_9 -> V_50 . V_129 = 24 ;
V_9 -> V_50 . V_130 = 1 ;
if ( V_74 -> V_114 . V_113 . V_82 . V_131 < 0x11 )
V_9 -> V_50 . V_132 = false ;
else
V_9 -> V_50 . V_132 = true ;
F_63 ( V_9 ) ;
F_54 ( V_9 ) ;
if ( V_133 != 2 && V_74 -> V_134 . V_135 . V_136 ) {
static const T_2 V_99 [] = {
V_137 ,
V_138 ,
V_139 ,
V_140 ,
V_141 ,
V_142 ,
V_101 ,
V_143 ,
V_144 ,
V_145 ,
V_146 ,
V_100 ,
V_147 ,
} ;
int V_148 ;
for ( V_148 = 0 , V_31 = - V_149 ; V_31 && V_148 < F_64 ( V_99 ) ; V_148 ++ ) {
V_31 = F_65 ( & V_74 -> V_114 . V_113 . V_150 , 0 ,
V_99 [ V_148 ] , NULL , 0 , & V_29 -> V_29 ) ;
}
if ( V_31 == 0 ) {
F_55 ( V_9 ) ;
if ( V_29 -> V_29 . V_99 < V_100 )
V_31 = F_66 ( V_9 ) ;
else
V_31 = F_67 ( V_9 ) ;
}
} else {
V_31 = 0 ;
}
if ( V_31 )
goto V_151;
F_68 ( V_9 ) ;
if ( V_9 -> V_50 . V_51 ) {
V_31 = F_24 ( V_9 ) ;
if ( V_31 )
goto V_152;
}
F_69 ( V_9 ) ;
F_70 ( & V_74 -> V_75 , F_41 ) ;
#ifdef F_71
V_74 -> V_80 . V_153 = F_46 ;
F_72 ( & V_74 -> V_80 ) ;
#endif
return 0 ;
V_152:
V_29 -> V_154 ( V_9 ) ;
V_151:
F_73 ( V_9 ) ;
F_74 ( V_9 ) ;
return V_31 ;
}
void
F_75 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
#ifdef F_71
F_76 ( & V_73 ( V_9 ) -> V_80 ) ;
#endif
F_77 ( V_9 ) ;
F_21 ( V_9 ) ;
F_73 ( V_9 ) ;
F_74 ( V_9 ) ;
if ( V_29 -> V_154 )
V_29 -> V_154 ( V_9 ) ;
F_78 ( & V_29 -> V_29 ) ;
V_73 ( V_9 ) -> V_115 = NULL ;
F_30 ( V_29 ) ;
}
static int
F_79 ( struct V_155 * V_47 ,
struct V_88 * V_89 )
{
struct V_156 * V_157 ;
struct V_11 * V_12 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
int V_31 ;
if ( ! ( V_12 = V_89 -> V_47 -> V_12 ) )
return 0 ;
V_157 = F_80 ( V_47 , V_89 ) ;
if ( F_81 ( V_157 ) )
return F_82 ( V_157 ) ;
V_31 = F_83 ( V_157 , NULL ) ;
if ( V_31 )
return V_31 ;
V_159 = F_84 ( V_47 , V_12 ) ;
if ( F_81 ( V_159 ) )
return F_82 ( V_159 ) ;
V_31 = F_85 ( V_159 , NULL ) ;
if ( V_31 )
return V_31 ;
V_159 -> V_164 = false ;
F_86 (plane, connector->dev, crtc_state->plane_mask) {
V_161 = F_87 ( V_47 , V_163 ) ;
if ( F_81 ( V_161 ) )
return F_82 ( V_161 ) ;
V_31 = F_88 ( V_161 , NULL ) ;
if ( V_31 )
return V_31 ;
F_89 ( V_161 , NULL ) ;
}
return 0 ;
}
static int
F_90 ( struct V_8 * V_9 ,
struct V_165 * V_166 )
{
struct V_155 * V_47 ;
struct V_88 * V_89 ;
int V_31 ;
V_47 = F_91 ( V_9 ) ;
if ( ! V_47 )
return - V_66 ;
V_47 -> V_167 = V_166 ;
F_92 (connector, dev) {
V_31 = F_79 ( V_47 , V_89 ) ;
if ( V_31 )
break;
}
if ( V_31 == 0 )
V_31 = F_93 ( V_47 ) ;
F_94 ( V_47 ) ;
return V_31 ;
}
static struct V_155 *
F_95 ( struct V_8 * V_9 )
{
struct V_165 V_166 ;
struct V_155 * V_47 ;
int V_31 ;
F_96 ( & V_166 , 0 ) ;
V_32:
V_31 = F_97 ( V_9 , & V_166 ) ;
if ( V_31 < 0 ) {
V_47 = F_39 ( V_31 ) ;
goto V_168;
}
V_47 = F_98 ( V_9 , & V_166 ) ;
if ( F_81 ( V_47 ) )
goto V_168;
V_31 = F_90 ( V_9 , & V_166 ) ;
if ( V_31 < 0 ) {
F_94 ( V_47 ) ;
V_47 = F_39 ( V_31 ) ;
goto V_168;
}
V_168:
if ( F_82 ( V_47 ) == - V_169 ) {
F_99 ( & V_166 ) ;
goto V_32;
}
F_100 ( & V_166 ) ;
F_101 ( & V_166 ) ;
return V_47 ;
}
int
F_102 ( struct V_8 * V_9 , bool V_170 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_11 * V_12 ;
if ( F_19 ( V_9 ) ) {
if ( ! V_170 ) {
V_29 -> V_96 = F_95 ( V_9 ) ;
if ( F_81 ( V_29 -> V_96 ) ) {
int V_31 = F_82 ( V_29 -> V_96 ) ;
V_29 -> V_96 = NULL ;
return V_31 ;
}
}
F_50 ( V_9 , true ) ;
return 0 ;
}
F_50 ( V_9 , true ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_54 * V_171 ;
V_171 = V_54 ( V_12 -> V_172 -> V_55 ) ;
if ( ! V_171 || ! V_171 -> V_56 )
continue;
F_103 ( V_171 -> V_56 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( V_4 -> V_173 . V_56 ) {
if ( V_4 -> V_173 . V_174 )
F_104 ( V_4 -> V_173 . V_56 ) ;
F_103 ( V_4 -> V_173 . V_56 ) ;
}
}
return 0 ;
}
void
F_105 ( struct V_8 * V_9 , bool V_170 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_11 * V_12 ;
int V_31 ;
if ( F_19 ( V_9 ) ) {
F_48 ( V_9 ) ;
if ( V_29 -> V_96 ) {
F_106 ( V_9 , V_29 -> V_96 ) ;
V_29 -> V_96 = NULL ;
}
return;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_54 * V_171 ;
V_171 = V_54 ( V_12 -> V_172 -> V_55 ) ;
if ( ! V_171 || ! V_171 -> V_56 )
continue;
V_31 = F_107 ( V_171 -> V_56 , V_175 , true ) ;
if ( V_31 )
F_108 ( V_74 , L_8 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_173 . V_56 )
continue;
V_31 = F_107 ( V_4 -> V_173 . V_56 , V_175 , true ) ;
if ( ! V_31 && V_4 -> V_173 . V_174 )
V_31 = F_109 ( V_4 -> V_173 . V_56 ) ;
if ( V_31 )
F_108 ( V_74 , L_9 ) ;
}
F_48 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
V_4 -> V_176 . V_177 = 0 ;
}
if ( V_170 )
return;
F_110 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_173 . V_56 )
continue;
if ( V_4 -> V_173 . V_174 )
V_4 -> V_173 . V_174 ( V_4 , V_4 -> V_173 . V_56 -> V_178 . V_179 ) ;
V_4 -> V_173 . V_180 ( V_4 , V_4 -> V_181 ,
V_4 -> V_182 ) ;
}
}
static int
F_111 ( struct V_183 * V_184 ,
struct V_63 * V_185 ,
struct V_63 * V_186 ,
struct V_187 * V_188 ,
struct V_189 * * V_190 )
{
struct V_191 * V_192 = V_184 -> V_193 ;
struct V_73 * V_74 = V_184 -> V_74 ;
struct V_8 * V_9 = V_74 -> V_9 ;
unsigned long V_42 ;
int V_31 ;
F_112 ( & V_9 -> V_194 , V_42 ) ;
F_113 ( & V_188 -> V_26 , & V_192 -> V_95 ) ;
F_114 ( & V_9 -> V_194 , V_42 ) ;
V_31 = F_115 ( V_185 , V_184 , false , false ) ;
if ( V_31 )
goto V_195;
V_31 = F_116 ( V_184 , 2 ) ;
if ( V_31 )
goto V_195;
F_117 ( V_184 , V_196 , V_197 , 1 ) ;
F_118 ( V_184 , 0x00000000 ) ;
F_119 ( V_184 ) ;
V_31 = F_120 ( V_184 , false , V_190 ) ;
if ( V_31 )
goto V_195;
return 0 ;
V_195:
F_112 ( & V_9 -> V_194 , V_42 ) ;
F_121 ( & V_188 -> V_26 ) ;
F_114 ( & V_9 -> V_194 , V_42 ) ;
return V_31 ;
}
int
F_122 ( struct V_11 * V_12 , struct V_52 * V_55 ,
struct V_198 * V_199 , T_3 V_42 )
{
const int V_200 = ( V_42 & V_201 ) ? 0 : 1 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_63 * V_185 = V_54 ( V_12 -> V_172 -> V_55 ) -> V_56 ;
struct V_63 * V_186 = V_54 ( V_55 ) -> V_56 ;
struct V_187 * V_188 ;
struct V_183 * V_184 ;
struct V_202 * V_203 ;
struct V_189 * V_193 ;
struct V_204 * V_205 = V_204 ( V_9 ) ;
int V_26 = V_3 ( V_12 ) -> V_27 ;
int V_31 ;
V_184 = V_74 -> V_206 ;
if ( ! V_184 )
return - V_149 ;
V_203 = ( void * ) V_184 -> V_207 . V_114 ;
V_188 = F_34 ( sizeof( * V_188 ) , V_65 ) ;
if ( ! V_188 )
return - V_66 ;
if ( V_186 != V_185 ) {
V_31 = F_107 ( V_186 , V_175 , true ) ;
if ( V_31 )
goto V_208;
}
F_123 ( & V_203 -> V_209 ) ;
V_31 = F_124 ( & V_186 -> V_178 , true , false , NULL ) ;
if ( V_31 )
goto V_210;
V_31 = F_115 ( V_186 , V_184 , false , true ) ;
if ( V_31 ) {
F_125 ( & V_186 -> V_178 ) ;
goto V_210;
}
if ( V_186 != V_185 ) {
F_125 ( & V_186 -> V_178 ) ;
V_31 = F_124 ( & V_185 -> V_178 , true , false , NULL ) ;
if ( V_31 )
goto V_210;
}
* V_188 = (struct V_187 )
{ { } , V_199 , V_12 , V_55 -> V_211 -> V_212 [ 0 ] * 8 , V_55 -> V_213 [ 0 ] ,
V_186 -> V_178 . V_179 } ;
F_126 ( V_12 ) ;
if ( V_200 ) {
V_31 = F_116 ( V_184 , 8 ) ;
if ( V_31 )
goto V_214;
F_117 ( V_184 , V_215 , 0x012c , 1 ) ;
F_118 ( V_184 , 0 ) ;
F_117 ( V_184 , V_215 , 0x0134 , 1 ) ;
F_118 ( V_184 , V_26 ) ;
F_117 ( V_184 , V_215 , 0x0100 , 1 ) ;
F_118 ( V_184 , 0 ) ;
F_117 ( V_184 , V_215 , 0x0130 , 1 ) ;
F_118 ( V_184 , 0 ) ;
}
F_127 ( V_186 , & V_205 -> V_216 [ V_26 ] ) ;
V_31 = F_111 ( V_184 , V_185 , V_186 , V_188 , & V_193 ) ;
if ( V_31 )
goto V_214;
F_128 ( & V_203 -> V_209 ) ;
V_12 -> V_172 -> V_55 = V_55 ;
F_129 ( V_185 , V_193 , false ) ;
F_125 ( & V_185 -> V_178 ) ;
if ( V_185 != V_186 )
F_103 ( V_185 ) ;
F_130 ( & V_193 ) ;
return 0 ;
V_214:
F_131 ( V_12 ) ;
F_125 ( & V_185 -> V_178 ) ;
V_210:
F_128 ( & V_203 -> V_209 ) ;
if ( V_185 != V_186 )
F_103 ( V_186 ) ;
V_208:
F_30 ( V_188 ) ;
return V_31 ;
}
int
F_132 ( struct V_183 * V_184 ,
struct V_187 * V_217 )
{
struct V_191 * V_192 = V_184 -> V_193 ;
struct V_73 * V_74 = V_184 -> V_74 ;
struct V_8 * V_9 = V_74 -> V_9 ;
struct V_187 * V_188 ;
unsigned long V_42 ;
F_112 ( & V_9 -> V_194 , V_42 ) ;
if ( F_133 ( & V_192 -> V_95 ) ) {
F_108 ( V_74 , L_10 ) ;
F_114 ( & V_9 -> V_194 , V_42 ) ;
return - V_13 ;
}
V_188 = F_134 ( & V_192 -> V_95 , struct V_187 , V_26 ) ;
if ( V_188 -> V_199 ) {
F_135 ( V_188 -> V_12 , V_188 -> V_199 ) ;
} else {
F_131 ( V_188 -> V_12 ) ;
}
F_121 ( & V_188 -> V_26 ) ;
if ( V_217 )
* V_217 = * V_188 ;
F_30 ( V_188 ) ;
F_114 ( & V_9 -> V_194 , V_42 ) ;
return 0 ;
}
int
F_136 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = F_2 ( V_2 , F_3 ( * V_74 ) , V_95 ) ;
struct V_183 * V_184 = V_74 -> V_206 ;
struct V_187 V_47 ;
if ( ! F_132 ( V_184 , & V_47 ) ) {
F_137 ( V_74 -> V_9 , F_12 ( V_47 . V_12 ) ,
V_47 . V_179 + V_47 . V_12 -> V_218 *
V_47 . V_219 + V_47 . V_12 -> V_220 *
V_47 . V_221 / 8 ) ;
}
return V_7 ;
}
int
F_138 ( struct V_58 * V_59 , struct V_8 * V_9 ,
struct V_222 * args )
{
struct V_202 * V_203 = V_202 ( V_59 ) ;
struct V_63 * V_178 ;
T_4 V_223 ;
int V_31 ;
args -> V_219 = F_139 ( args -> V_224 * ( args -> V_221 / 8 ) , 256 ) ;
args -> V_225 = args -> V_219 * args -> V_226 ;
args -> V_225 = F_139 ( args -> V_225 , V_227 ) ;
if ( V_73 ( V_9 ) -> V_114 . V_113 . V_82 . V_228 != 0 )
V_223 = V_229 ;
else
V_223 = V_230 ;
V_31 = F_140 ( V_203 , args -> V_225 , 0 , V_223 , 0 , 0 , & V_178 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_32 ( V_59 , & V_178 -> V_57 , & args -> V_60 ) ;
F_28 ( & V_178 -> V_57 ) ;
return V_31 ;
}
int
F_141 ( struct V_58 * V_59 ,
struct V_8 * V_9 ,
T_4 V_60 , T_5 * V_231 )
{
struct V_68 * V_57 ;
V_57 = F_38 ( V_59 , V_60 ) ;
if ( V_57 ) {
struct V_63 * V_178 = F_40 ( V_57 ) ;
* V_231 = F_142 ( & V_178 -> V_178 . V_232 ) ;
F_28 ( V_57 ) ;
return 0 ;
}
return - V_70 ;
}
