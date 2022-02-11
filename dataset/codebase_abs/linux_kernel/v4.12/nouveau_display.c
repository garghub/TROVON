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
int V_31 , V_32 = 20 ;
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
F_44 ( V_74 -> V_9 ) ;
F_45 ( V_74 -> V_9 -> V_9 ) ;
F_46 ( V_74 -> V_9 -> V_9 ) ;
}
static int
F_47 ( struct V_76 * V_77 , unsigned long V_78 ,
void * V_79 )
{
struct V_73 * V_74 = F_2 ( V_77 , F_3 ( * V_74 ) , V_80 ) ;
struct V_81 * V_82 = V_79 ;
if ( ! strcmp ( V_82 -> V_83 , V_84 ) ) {
if ( V_82 -> type == V_85 ) {
F_48 ( & V_74 -> V_75 ) ;
return V_86 ;
}
}
return V_87 ;
}
int
F_49 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_88 * V_89 ;
int V_31 ;
V_31 = V_29 -> V_90 ( V_9 ) ;
if ( V_31 )
return V_31 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
struct V_91 * V_92 = V_91 ( V_89 ) ;
F_7 ( & V_92 -> V_93 ) ;
}
F_7 ( & V_74 -> V_94 ) ;
return V_31 ;
}
void
F_50 ( struct V_8 * V_9 , bool V_95 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_88 * V_89 ;
struct V_11 * V_12 ;
if ( ! V_95 ) {
if ( F_19 ( V_9 ) )
F_51 ( V_9 ) ;
else
F_52 ( V_9 ) ;
}
F_53 (crtc, dev)
F_54 ( V_12 ) ;
F_9 ( & V_74 -> V_94 ) ;
F_17 (connector, &dev->mode_config.connector_list, head) {
struct V_91 * V_92 = V_91 ( V_89 ) ;
F_9 ( & V_92 -> V_93 ) ;
}
F_55 ( V_9 ) ;
V_29 -> V_96 ( V_9 ) ;
}
static void
F_56 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
int V_97 ;
if ( V_29 -> V_29 . V_98 < V_99 )
V_97 = 0 ;
else
if ( V_29 -> V_29 . V_98 < V_100 )
V_97 = 1 ;
else
V_97 = 2 ;
F_57 ( V_29 -> V_101 , V_97 , L_1 , V_102 ) ;
F_57 ( V_29 -> V_103 , V_97 , L_2 , V_104 ) ;
F_57 ( V_29 -> V_105 , V_97 , L_3 , V_106 ) ;
V_29 -> V_107 =
F_58 ( V_9 , 0 , L_4 , 0 , 128 ) ;
V_29 -> V_108 =
F_58 ( V_9 , 0 , L_5 , 0 , 128 ) ;
if ( V_97 < 1 )
return;
V_29 -> V_109 =
F_58 ( V_9 , 0 , L_6 , 0 , 180 ) ;
V_29 -> V_110 =
F_58 ( V_9 , 0 , L_7 , 0 , 200 ) ;
}
int
F_59 ( struct V_8 * V_9 )
{
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_111 * V_112 = F_60 ( & V_74 -> V_113 . V_112 ) ;
struct V_28 * V_29 ;
int V_31 ;
V_29 = V_74 -> V_114 = F_34 ( sizeof( * V_29 ) , V_65 ) ;
if ( ! V_29 )
return - V_66 ;
F_61 ( V_9 ) ;
F_62 ( V_9 ) ;
F_63 ( V_9 ) ;
V_9 -> V_50 . V_115 = & V_116 ;
V_9 -> V_50 . V_117 = V_112 -> V_118 -> V_119 ( V_112 , 1 ) ;
V_9 -> V_50 . V_120 = 0 ;
V_9 -> V_50 . V_121 = 0 ;
if ( V_74 -> V_113 . V_112 . V_82 . V_122 < V_123 ) {
V_9 -> V_50 . V_124 = 2048 ;
V_9 -> V_50 . V_125 = 2048 ;
} else
if ( V_74 -> V_113 . V_112 . V_82 . V_122 < V_126 ) {
V_9 -> V_50 . V_124 = 4096 ;
V_9 -> V_50 . V_125 = 4096 ;
} else
if ( V_74 -> V_113 . V_112 . V_82 . V_122 < V_127 ) {
V_9 -> V_50 . V_124 = 8192 ;
V_9 -> V_50 . V_125 = 8192 ;
} else {
V_9 -> V_50 . V_124 = 16384 ;
V_9 -> V_50 . V_125 = 16384 ;
}
V_9 -> V_50 . V_128 = 24 ;
V_9 -> V_50 . V_129 = 1 ;
if ( V_74 -> V_113 . V_112 . V_82 . V_130 < 0x11 )
V_9 -> V_50 . V_131 = false ;
else
V_9 -> V_50 . V_131 = true ;
F_64 ( V_9 ) ;
F_55 ( V_9 ) ;
if ( V_132 != 2 && V_74 -> V_133 . V_134 . V_135 ) {
static const T_2 V_98 [] = {
V_136 ,
V_137 ,
V_138 ,
V_139 ,
V_140 ,
V_141 ,
V_100 ,
V_142 ,
V_143 ,
V_144 ,
V_145 ,
V_99 ,
V_146 ,
} ;
int V_147 ;
for ( V_147 = 0 , V_31 = - V_148 ; V_31 && V_147 < F_65 ( V_98 ) ; V_147 ++ ) {
V_31 = F_66 ( & V_74 -> V_113 . V_112 . V_149 , 0 ,
V_98 [ V_147 ] , NULL , 0 , & V_29 -> V_29 ) ;
}
if ( V_31 == 0 ) {
F_56 ( V_9 ) ;
if ( V_29 -> V_29 . V_98 < V_99 )
V_31 = F_67 ( V_9 ) ;
else
V_31 = F_68 ( V_9 ) ;
}
} else {
V_31 = 0 ;
}
if ( V_31 )
goto V_150;
F_69 ( V_9 ) ;
if ( V_9 -> V_50 . V_51 ) {
V_31 = F_24 ( V_9 ) ;
if ( V_31 )
goto V_151;
}
F_70 ( V_9 ) ;
F_71 ( & V_74 -> V_75 , F_41 ) ;
#ifdef F_72
V_74 -> V_80 . V_152 = F_47 ;
F_73 ( & V_74 -> V_80 ) ;
#endif
return 0 ;
V_151:
V_29 -> V_153 ( V_9 ) ;
V_150:
F_74 ( V_9 ) ;
F_75 ( V_9 ) ;
return V_31 ;
}
void
F_76 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
#ifdef F_72
F_77 ( & V_73 ( V_9 ) -> V_80 ) ;
#endif
F_78 ( V_9 ) ;
F_21 ( V_9 ) ;
F_74 ( V_9 ) ;
F_75 ( V_9 ) ;
if ( V_29 -> V_153 )
V_29 -> V_153 ( V_9 ) ;
F_79 ( & V_29 -> V_29 ) ;
V_73 ( V_9 ) -> V_114 = NULL ;
F_30 ( V_29 ) ;
}
int
F_80 ( struct V_8 * V_9 , bool V_154 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_11 * V_12 ;
if ( F_19 ( V_9 ) ) {
if ( ! V_154 ) {
V_29 -> V_95 = F_81 ( V_9 ) ;
if ( F_82 ( V_29 -> V_95 ) ) {
int V_31 = F_83 ( V_29 -> V_95 ) ;
V_29 -> V_95 = NULL ;
return V_31 ;
}
}
F_50 ( V_9 , true ) ;
return 0 ;
}
F_50 ( V_9 , true ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_54 * V_155 ;
V_155 = V_54 ( V_12 -> V_156 -> V_55 ) ;
if ( ! V_155 || ! V_155 -> V_56 )
continue;
F_84 ( V_155 -> V_56 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( V_4 -> V_157 . V_56 ) {
if ( V_4 -> V_157 . V_158 )
F_85 ( V_4 -> V_157 . V_56 ) ;
F_84 ( V_4 -> V_157 . V_56 ) ;
}
}
return 0 ;
}
void
F_86 ( struct V_8 * V_9 , bool V_154 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_11 * V_12 ;
int V_31 ;
if ( F_19 ( V_9 ) ) {
F_49 ( V_9 ) ;
if ( V_29 -> V_95 ) {
F_87 ( V_9 , V_29 -> V_95 ) ;
V_29 -> V_95 = NULL ;
}
return;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_54 * V_155 ;
V_155 = V_54 ( V_12 -> V_156 -> V_55 ) ;
if ( ! V_155 || ! V_155 -> V_56 )
continue;
V_31 = F_88 ( V_155 -> V_56 , V_159 , true ) ;
if ( V_31 )
F_89 ( V_74 , L_8 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_157 . V_56 )
continue;
V_31 = F_88 ( V_4 -> V_157 . V_56 , V_159 , true ) ;
if ( ! V_31 && V_4 -> V_157 . V_158 )
V_31 = F_90 ( V_4 -> V_157 . V_56 ) ;
if ( V_31 )
F_89 ( V_74 , L_9 ) ;
}
F_49 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
V_4 -> V_160 . V_161 = 0 ;
}
if ( V_154 )
return;
F_91 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_157 . V_56 )
continue;
if ( V_4 -> V_157 . V_158 )
V_4 -> V_157 . V_158 ( V_4 , V_4 -> V_157 . V_56 -> V_162 . V_163 ) ;
V_4 -> V_157 . V_164 ( V_4 , V_4 -> V_165 ,
V_4 -> V_166 ) ;
}
}
static int
F_92 ( struct V_167 * V_168 ,
struct V_63 * V_169 ,
struct V_63 * V_170 ,
struct V_171 * V_172 ,
struct V_173 * * V_174 )
{
struct V_175 * V_176 = V_168 -> V_177 ;
struct V_73 * V_74 = V_168 -> V_74 ;
struct V_8 * V_9 = V_74 -> V_9 ;
unsigned long V_42 ;
int V_31 ;
F_93 ( & V_9 -> V_178 , V_42 ) ;
F_94 ( & V_172 -> V_26 , & V_176 -> V_94 ) ;
F_95 ( & V_9 -> V_178 , V_42 ) ;
V_31 = F_96 ( V_169 , V_168 , false , false ) ;
if ( V_31 )
goto V_179;
V_31 = F_97 ( V_168 , 2 ) ;
if ( V_31 )
goto V_179;
F_98 ( V_168 , V_180 , V_181 , 1 ) ;
F_99 ( V_168 , 0x00000000 ) ;
F_100 ( V_168 ) ;
V_31 = F_101 ( V_168 , false , V_174 ) ;
if ( V_31 )
goto V_179;
return 0 ;
V_179:
F_93 ( & V_9 -> V_178 , V_42 ) ;
F_102 ( & V_172 -> V_26 ) ;
F_95 ( & V_9 -> V_178 , V_42 ) ;
return V_31 ;
}
int
F_103 ( struct V_11 * V_12 , struct V_52 * V_55 ,
struct V_182 * V_183 , T_3 V_42 ,
struct V_184 * V_185 )
{
const int V_186 = ( V_42 & V_187 ) ? 0 : 1 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_73 * V_74 = V_73 ( V_9 ) ;
struct V_63 * V_169 = V_54 ( V_12 -> V_156 -> V_55 ) -> V_56 ;
struct V_63 * V_170 = V_54 ( V_55 ) -> V_56 ;
struct V_171 * V_172 ;
struct V_167 * V_168 ;
struct V_188 * V_189 ;
struct V_173 * V_177 ;
struct V_190 * V_191 = V_190 ( V_9 ) ;
int V_26 = V_3 ( V_12 ) -> V_27 ;
int V_31 ;
V_168 = V_74 -> V_192 ;
if ( ! V_168 )
return - V_148 ;
V_189 = ( void * ) V_168 -> V_193 . V_113 ;
V_172 = F_34 ( sizeof( * V_172 ) , V_65 ) ;
if ( ! V_172 )
return - V_66 ;
if ( V_170 != V_169 ) {
V_31 = F_88 ( V_170 , V_159 , true ) ;
if ( V_31 )
goto V_194;
}
F_104 ( & V_189 -> V_195 ) ;
V_31 = F_105 ( & V_170 -> V_162 , true , false , NULL ) ;
if ( V_31 )
goto V_196;
V_31 = F_96 ( V_170 , V_168 , false , true ) ;
if ( V_31 ) {
F_106 ( & V_170 -> V_162 ) ;
goto V_196;
}
if ( V_170 != V_169 ) {
F_106 ( & V_170 -> V_162 ) ;
V_31 = F_105 ( & V_169 -> V_162 , true , false , NULL ) ;
if ( V_31 )
goto V_196;
}
* V_172 = (struct V_171 )
{ { } , V_183 , V_12 , V_55 -> V_197 -> V_198 [ 0 ] * 8 , V_55 -> V_199 [ 0 ] ,
V_170 -> V_162 . V_163 } ;
F_107 ( V_12 ) ;
if ( V_186 ) {
V_31 = F_97 ( V_168 , 8 ) ;
if ( V_31 )
goto V_200;
F_98 ( V_168 , V_201 , 0x012c , 1 ) ;
F_99 ( V_168 , 0 ) ;
F_98 ( V_168 , V_201 , 0x0134 , 1 ) ;
F_99 ( V_168 , V_26 ) ;
F_98 ( V_168 , V_201 , 0x0100 , 1 ) ;
F_99 ( V_168 , 0 ) ;
F_98 ( V_168 , V_201 , 0x0130 , 1 ) ;
F_99 ( V_168 , 0 ) ;
}
F_108 ( V_170 , & V_191 -> V_202 [ V_26 ] ) ;
V_31 = F_92 ( V_168 , V_169 , V_170 , V_172 , & V_177 ) ;
if ( V_31 )
goto V_200;
F_109 ( & V_189 -> V_195 ) ;
V_12 -> V_156 -> V_55 = V_55 ;
F_110 ( V_169 , V_177 , false ) ;
F_106 ( & V_169 -> V_162 ) ;
if ( V_169 != V_170 )
F_84 ( V_169 ) ;
F_111 ( & V_177 ) ;
return 0 ;
V_200:
F_112 ( V_12 ) ;
F_106 ( & V_169 -> V_162 ) ;
V_196:
F_109 ( & V_189 -> V_195 ) ;
if ( V_169 != V_170 )
F_84 ( V_170 ) ;
V_194:
F_30 ( V_172 ) ;
return V_31 ;
}
int
F_113 ( struct V_167 * V_168 ,
struct V_171 * V_203 )
{
struct V_175 * V_176 = V_168 -> V_177 ;
struct V_73 * V_74 = V_168 -> V_74 ;
struct V_8 * V_9 = V_74 -> V_9 ;
struct V_171 * V_172 ;
unsigned long V_42 ;
F_93 ( & V_9 -> V_178 , V_42 ) ;
if ( F_114 ( & V_176 -> V_94 ) ) {
F_89 ( V_74 , L_10 ) ;
F_95 ( & V_9 -> V_178 , V_42 ) ;
return - V_13 ;
}
V_172 = F_115 ( & V_176 -> V_94 , struct V_171 , V_26 ) ;
if ( V_172 -> V_183 ) {
F_116 ( V_172 -> V_12 , V_172 -> V_183 ) ;
} else {
F_112 ( V_172 -> V_12 ) ;
}
F_102 ( & V_172 -> V_26 ) ;
if ( V_203 )
* V_203 = * V_172 ;
F_30 ( V_172 ) ;
F_95 ( & V_9 -> V_178 , V_42 ) ;
return 0 ;
}
int
F_117 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = F_2 ( V_2 , F_3 ( * V_74 ) , V_94 ) ;
struct V_167 * V_168 = V_74 -> V_192 ;
struct V_171 V_47 ;
if ( ! F_113 ( V_168 , & V_47 ) ) {
F_118 ( V_74 -> V_9 , F_12 ( V_47 . V_12 ) ,
V_47 . V_163 + V_47 . V_12 -> V_204 *
V_47 . V_205 + V_47 . V_12 -> V_206 *
V_47 . V_207 / 8 ) ;
}
return V_7 ;
}
int
F_119 ( struct V_58 * V_59 , struct V_8 * V_9 ,
struct V_208 * args )
{
struct V_188 * V_189 = V_188 ( V_59 ) ;
struct V_63 * V_162 ;
T_4 V_209 ;
int V_31 ;
args -> V_205 = F_120 ( args -> V_210 * ( args -> V_207 / 8 ) , 256 ) ;
args -> V_211 = args -> V_205 * args -> V_212 ;
args -> V_211 = F_120 ( args -> V_211 , V_213 ) ;
if ( V_73 ( V_9 ) -> V_113 . V_112 . V_82 . V_214 != 0 )
V_209 = V_215 ;
else
V_209 = V_216 ;
V_31 = F_121 ( V_189 , args -> V_211 , 0 , V_209 , 0 , 0 , & V_162 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_32 ( V_59 , & V_162 -> V_57 , & args -> V_60 ) ;
F_28 ( & V_162 -> V_57 ) ;
return V_31 ;
}
int
F_122 ( struct V_58 * V_59 ,
struct V_8 * V_9 ,
T_4 V_60 , T_5 * V_217 )
{
struct V_68 * V_57 ;
V_57 = F_38 ( V_59 , V_60 ) ;
if ( V_57 ) {
struct V_63 * V_162 = F_40 ( V_57 ) ;
* V_217 = F_123 ( & V_162 -> V_162 . V_218 ) ;
F_28 ( V_57 ) ;
return 0 ;
}
return - V_70 ;
}
