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
static bool
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
int V_31 = 20 ;
bool V_32 = false ;
do {
V_32 = F_13 ( & V_29 -> V_29 , 0 , & args , sizeof( args ) ) ;
if ( V_32 != 0 )
return false ;
if ( args . V_23 . V_33 ) {
V_32 = true ;
break;
}
if ( V_31 ) F_14 ( V_5 -> V_34 ) ;
} while ( V_31 -- );
* V_18 = args . V_23 . V_35 ;
* V_17 = F_10 ( args . V_23 . V_36 , args . V_23 . V_37 ,
args . V_23 . V_38 , args . V_23 . V_33 ) ;
if ( V_19 ) * V_19 = F_15 ( args . V_23 . time [ 0 ] ) ;
if ( V_20 ) * V_20 = F_15 ( args . V_23 . time [ 1 ] ) ;
return V_32 ;
}
bool
F_16 ( struct V_8 * V_9 , unsigned int V_10 ,
bool V_39 , int * V_17 , int * V_18 ,
T_1 * V_19 , T_1 * V_20 ,
const struct V_40 * V_41 )
{
struct V_11 * V_12 ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_3 ( V_12 ) -> V_27 == V_10 ) {
return F_11 ( V_12 , V_17 , V_18 ,
V_19 , V_20 ) ;
}
}
return false ;
}
static void
F_18 ( struct V_8 * V_9 )
{
struct V_11 * V_12 ;
F_19 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
F_20 ( & V_4 -> V_5 ) ;
}
}
static int
F_21 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_11 * V_12 ;
int V_32 ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
V_32 = F_22 (&disp->disp,
nouveau_display_vblank_handler, false,
NV04_DISP_NTFY_VBLANK,
&(struct nvif_notify_head_req_v0) {
.head = nv_crtc->index,
},
sizeof(struct nvif_notify_head_req_v0),
sizeof(struct nvif_notify_head_rep_v0),
&nv_crtc->vblank) ;
if ( V_32 ) {
F_18 ( V_9 ) ;
return V_32 ;
}
}
V_32 = F_23 ( V_9 , V_9 -> V_42 . V_43 ) ;
if ( V_32 ) {
F_18 ( V_9 ) ;
return V_32 ;
}
return 0 ;
}
static void
F_24 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_46 ( V_45 ) ;
if ( V_47 -> V_48 )
F_25 ( & V_47 -> V_48 -> V_49 ) ;
F_26 ( V_45 ) ;
F_27 ( V_47 ) ;
}
static int
F_28 ( struct V_44 * V_45 ,
struct V_50 * V_51 ,
unsigned int * V_52 )
{
struct V_46 * V_47 = V_46 ( V_45 ) ;
return F_29 ( V_51 , & V_47 -> V_48 -> V_49 , V_52 ) ;
}
int
F_30 ( struct V_8 * V_9 ,
const struct V_53 * V_54 ,
struct V_55 * V_48 ,
struct V_46 * * V_56 )
{
struct V_46 * V_47 ;
int V_32 ;
if ( ! ( V_47 = * V_56 = F_31 ( sizeof( * V_47 ) , V_57 ) ) )
return - V_58 ;
F_32 ( V_9 , & V_47 -> V_6 , V_54 ) ;
V_47 -> V_48 = V_48 ;
V_32 = F_33 ( V_9 , & V_47 -> V_6 , & V_59 ) ;
if ( V_32 )
F_27 ( V_47 ) ;
return V_32 ;
}
struct V_44 *
F_34 ( struct V_8 * V_9 ,
struct V_50 * V_51 ,
const struct V_53 * V_54 )
{
struct V_46 * V_47 ;
struct V_55 * V_48 ;
struct V_60 * V_49 ;
int V_32 ;
V_49 = F_35 ( V_51 , V_54 -> V_61 [ 0 ] ) ;
if ( ! V_49 )
return F_36 ( - V_62 ) ;
V_48 = F_37 ( V_49 ) ;
V_32 = F_30 ( V_9 , V_54 , V_48 , & V_47 ) ;
if ( V_32 == 0 )
return & V_47 -> V_6 ;
F_25 ( V_49 ) ;
return F_36 ( V_32 ) ;
}
static void
F_38 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_2 ( V_64 , F_3 ( * V_66 ) , V_67 ) ;
F_39 ( V_66 -> V_9 -> V_9 ) ;
F_40 ( V_66 -> V_9 ) ;
F_41 ( V_66 -> V_9 ) ;
F_42 ( V_66 -> V_9 -> V_9 ) ;
F_43 ( V_66 -> V_9 -> V_9 ) ;
}
static int
F_44 ( struct V_68 * V_69 , unsigned long V_70 ,
void * V_71 )
{
struct V_65 * V_66 = F_2 ( V_69 , F_3 ( * V_66 ) , V_72 ) ;
struct V_73 * V_74 = V_71 ;
if ( ! strcmp ( V_74 -> V_75 , V_76 ) ) {
if ( V_74 -> type == V_77 ) {
F_45 ( & V_66 -> V_67 ) ;
return V_78 ;
}
}
return V_79 ;
}
int
F_46 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_65 * V_66 = V_65 ( V_9 ) ;
struct V_80 * V_81 ;
int V_32 ;
V_32 = V_29 -> V_82 ( V_9 ) ;
if ( V_32 )
return V_32 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
struct V_83 * V_84 = V_83 ( V_81 ) ;
F_7 ( & V_84 -> V_85 ) ;
}
F_7 ( & V_66 -> V_86 ) ;
return V_32 ;
}
void
F_47 ( struct V_8 * V_9 , bool V_87 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_65 * V_66 = V_65 ( V_9 ) ;
struct V_80 * V_81 ;
if ( ! V_87 ) {
if ( F_48 ( V_9 ) )
F_49 ( V_9 ) ;
else
F_50 ( V_9 ) ;
}
F_9 ( & V_66 -> V_86 ) ;
F_17 (connector, &dev->mode_config.connector_list, head) {
struct V_83 * V_84 = V_83 ( V_81 ) ;
F_9 ( & V_84 -> V_85 ) ;
}
F_51 ( V_9 ) ;
V_29 -> V_88 ( V_9 ) ;
}
static void
F_52 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
int V_89 ;
if ( V_29 -> V_29 . V_90 < V_91 )
V_89 = 0 ;
else
if ( V_29 -> V_29 . V_90 < V_92 )
V_89 = 1 ;
else
V_89 = 2 ;
F_53 ( V_29 -> V_93 , V_89 , L_1 , V_94 ) ;
F_53 ( V_29 -> V_95 , V_89 , L_2 , V_96 ) ;
F_53 ( V_29 -> V_97 , V_89 , L_3 , V_98 ) ;
V_29 -> V_99 =
F_54 ( V_9 , 0 , L_4 , 0 , 128 ) ;
V_29 -> V_100 =
F_54 ( V_9 , 0 , L_5 , 0 , 128 ) ;
if ( V_89 < 1 )
return;
V_29 -> V_101 =
F_54 ( V_9 , 0 , L_6 , 0 , 180 ) ;
V_29 -> V_102 =
F_54 ( V_9 , 0 , L_7 , 0 , 200 ) ;
}
int
F_55 ( struct V_8 * V_9 )
{
struct V_65 * V_66 = V_65 ( V_9 ) ;
struct V_103 * V_104 = F_56 ( & V_66 -> V_105 . V_104 ) ;
struct V_28 * V_29 ;
int V_32 ;
V_29 = V_66 -> V_106 = F_31 ( sizeof( * V_29 ) , V_57 ) ;
if ( ! V_29 )
return - V_58 ;
F_57 ( V_9 ) ;
F_58 ( V_9 ) ;
F_59 ( V_9 ) ;
V_9 -> V_42 . V_107 = & V_108 ;
V_9 -> V_42 . V_109 = V_104 -> V_110 -> V_111 ( V_104 , 1 ) ;
V_9 -> V_42 . V_112 = 0 ;
V_9 -> V_42 . V_113 = 0 ;
if ( V_66 -> V_105 . V_104 . V_74 . V_114 < V_115 ) {
V_9 -> V_42 . V_116 = 2048 ;
V_9 -> V_42 . V_117 = 2048 ;
} else
if ( V_66 -> V_105 . V_104 . V_74 . V_114 < V_118 ) {
V_9 -> V_42 . V_116 = 4096 ;
V_9 -> V_42 . V_117 = 4096 ;
} else
if ( V_66 -> V_105 . V_104 . V_74 . V_114 < V_119 ) {
V_9 -> V_42 . V_116 = 8192 ;
V_9 -> V_42 . V_117 = 8192 ;
} else {
V_9 -> V_42 . V_116 = 16384 ;
V_9 -> V_42 . V_117 = 16384 ;
}
V_9 -> V_42 . V_120 = 24 ;
V_9 -> V_42 . V_121 = 1 ;
if ( V_66 -> V_105 . V_104 . V_74 . V_122 < 0x11 )
V_9 -> V_42 . V_123 = false ;
else
V_9 -> V_42 . V_123 = true ;
F_60 ( V_9 ) ;
F_51 ( V_9 ) ;
if ( V_124 != 2 && V_66 -> V_125 . V_126 . V_127 ) {
static const T_2 V_90 [] = {
V_128 ,
V_129 ,
V_130 ,
V_131 ,
V_132 ,
V_133 ,
V_92 ,
V_134 ,
V_135 ,
V_136 ,
V_137 ,
V_91 ,
V_138 ,
} ;
int V_139 ;
for ( V_139 = 0 , V_32 = - V_140 ; V_32 && V_139 < F_61 ( V_90 ) ; V_139 ++ ) {
V_32 = F_62 ( & V_66 -> V_105 . V_104 . V_141 , 0 ,
V_90 [ V_139 ] , NULL , 0 , & V_29 -> V_29 ) ;
}
if ( V_32 == 0 ) {
F_52 ( V_9 ) ;
if ( V_29 -> V_29 . V_90 < V_91 )
V_32 = F_63 ( V_9 ) ;
else
V_32 = F_64 ( V_9 ) ;
}
} else {
V_32 = 0 ;
}
if ( V_32 )
goto V_142;
F_65 ( V_9 ) ;
if ( V_9 -> V_42 . V_43 ) {
V_32 = F_21 ( V_9 ) ;
if ( V_32 )
goto V_143;
}
F_66 ( V_9 ) ;
F_67 ( & V_66 -> V_67 , F_38 ) ;
#ifdef F_68
V_66 -> V_72 . V_144 = F_44 ;
F_69 ( & V_66 -> V_72 ) ;
#endif
return 0 ;
V_143:
V_29 -> V_145 ( V_9 ) ;
V_142:
F_70 ( V_9 ) ;
F_71 ( V_9 ) ;
return V_32 ;
}
void
F_72 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
#ifdef F_68
F_73 ( & V_65 ( V_9 ) -> V_72 ) ;
#endif
F_74 ( V_9 ) ;
F_18 ( V_9 ) ;
F_70 ( V_9 ) ;
F_71 ( V_9 ) ;
if ( V_29 -> V_145 )
V_29 -> V_145 ( V_9 ) ;
F_75 ( & V_29 -> V_29 ) ;
V_65 ( V_9 ) -> V_106 = NULL ;
F_27 ( V_29 ) ;
}
int
F_76 ( struct V_8 * V_9 , bool V_146 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_11 * V_12 ;
if ( F_48 ( V_9 ) ) {
if ( ! V_146 ) {
V_29 -> V_87 = F_77 ( V_9 ) ;
if ( F_78 ( V_29 -> V_87 ) ) {
int V_32 = F_79 ( V_29 -> V_87 ) ;
V_29 -> V_87 = NULL ;
return V_32 ;
}
}
F_47 ( V_9 , true ) ;
return 0 ;
}
F_47 ( V_9 , true ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_46 * V_147 ;
V_147 = V_46 ( V_12 -> V_148 -> V_47 ) ;
if ( ! V_147 || ! V_147 -> V_48 )
continue;
F_80 ( V_147 -> V_48 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( V_4 -> V_149 . V_48 ) {
if ( V_4 -> V_149 . V_150 )
F_81 ( V_4 -> V_149 . V_48 ) ;
F_80 ( V_4 -> V_149 . V_48 ) ;
}
}
return 0 ;
}
void
F_82 ( struct V_8 * V_9 , bool V_146 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_65 * V_66 = V_65 ( V_9 ) ;
struct V_11 * V_12 ;
int V_32 ;
if ( F_48 ( V_9 ) ) {
F_46 ( V_9 ) ;
if ( V_29 -> V_87 ) {
F_83 ( V_9 , V_29 -> V_87 ) ;
V_29 -> V_87 = NULL ;
}
return;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_46 * V_147 ;
V_147 = V_46 ( V_12 -> V_148 -> V_47 ) ;
if ( ! V_147 || ! V_147 -> V_48 )
continue;
V_32 = F_84 ( V_147 -> V_48 , V_151 , true ) ;
if ( V_32 )
F_85 ( V_66 , L_8 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_149 . V_48 )
continue;
V_32 = F_84 ( V_4 -> V_149 . V_48 , V_151 , true ) ;
if ( ! V_32 && V_4 -> V_149 . V_150 )
V_32 = F_86 ( V_4 -> V_149 . V_48 ) ;
if ( V_32 )
F_85 ( V_66 , L_9 ) ;
}
F_46 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
V_4 -> V_152 . V_153 = 0 ;
}
if ( V_146 )
return;
F_87 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_149 . V_48 )
continue;
if ( V_4 -> V_149 . V_150 )
V_4 -> V_149 . V_150 ( V_4 , V_4 -> V_149 . V_48 -> V_154 . V_155 ) ;
V_4 -> V_149 . V_156 ( V_4 , V_4 -> V_157 ,
V_4 -> V_158 ) ;
}
}
static int
F_88 ( struct V_159 * V_160 ,
struct V_55 * V_161 ,
struct V_55 * V_162 ,
struct V_163 * V_164 ,
struct V_165 * * V_166 )
{
struct V_167 * V_168 = V_160 -> V_169 ;
struct V_65 * V_66 = V_160 -> V_66 ;
struct V_8 * V_9 = V_66 -> V_9 ;
unsigned long V_170 ;
int V_32 ;
F_89 ( & V_9 -> V_171 , V_170 ) ;
F_90 ( & V_164 -> V_26 , & V_168 -> V_86 ) ;
F_91 ( & V_9 -> V_171 , V_170 ) ;
V_32 = F_92 ( V_161 , V_160 , false , false ) ;
if ( V_32 )
goto V_172;
V_32 = F_93 ( V_160 , 2 ) ;
if ( V_32 )
goto V_172;
F_94 ( V_160 , V_173 , V_174 , 1 ) ;
F_95 ( V_160 , 0x00000000 ) ;
F_96 ( V_160 ) ;
V_32 = F_97 ( V_160 , false , V_166 ) ;
if ( V_32 )
goto V_172;
return 0 ;
V_172:
F_89 ( & V_9 -> V_171 , V_170 ) ;
F_98 ( & V_164 -> V_26 ) ;
F_91 ( & V_9 -> V_171 , V_170 ) ;
return V_32 ;
}
int
F_99 ( struct V_11 * V_12 , struct V_44 * V_47 ,
struct V_175 * V_176 , T_3 V_170 ,
struct V_177 * V_178 )
{
const int V_179 = ( V_170 & V_180 ) ? 0 : 1 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_65 * V_66 = V_65 ( V_9 ) ;
struct V_55 * V_161 = V_46 ( V_12 -> V_148 -> V_47 ) -> V_48 ;
struct V_55 * V_162 = V_46 ( V_47 ) -> V_48 ;
struct V_163 * V_164 ;
struct V_159 * V_160 ;
struct V_181 * V_182 ;
struct V_165 * V_169 ;
struct V_183 * V_184 = V_183 ( V_9 ) ;
int V_26 = V_3 ( V_12 ) -> V_27 ;
int V_32 ;
V_160 = V_66 -> V_185 ;
if ( ! V_160 )
return - V_140 ;
V_182 = ( void * ) V_160 -> V_186 . V_105 ;
V_164 = F_31 ( sizeof( * V_164 ) , V_57 ) ;
if ( ! V_164 )
return - V_58 ;
if ( V_162 != V_161 ) {
V_32 = F_84 ( V_162 , V_151 , true ) ;
if ( V_32 )
goto V_187;
}
F_100 ( & V_182 -> V_188 ) ;
V_32 = F_101 ( & V_162 -> V_154 , true , false , NULL ) ;
if ( V_32 )
goto V_189;
V_32 = F_92 ( V_162 , V_160 , false , true ) ;
if ( V_32 ) {
F_102 ( & V_162 -> V_154 ) ;
goto V_189;
}
if ( V_162 != V_161 ) {
F_102 ( & V_162 -> V_154 ) ;
V_32 = F_101 ( & V_161 -> V_154 , true , false , NULL ) ;
if ( V_32 )
goto V_189;
}
* V_164 = (struct V_163 )
{ { } , V_176 , V_12 , V_47 -> V_190 -> V_191 [ 0 ] * 8 , V_47 -> V_192 [ 0 ] ,
V_162 -> V_154 . V_155 } ;
F_103 ( V_12 ) ;
if ( V_179 ) {
V_32 = F_93 ( V_160 , 8 ) ;
if ( V_32 )
goto V_193;
F_94 ( V_160 , V_194 , 0x012c , 1 ) ;
F_95 ( V_160 , 0 ) ;
F_94 ( V_160 , V_194 , 0x0134 , 1 ) ;
F_95 ( V_160 , V_26 ) ;
F_94 ( V_160 , V_194 , 0x0100 , 1 ) ;
F_95 ( V_160 , 0 ) ;
F_94 ( V_160 , V_194 , 0x0130 , 1 ) ;
F_95 ( V_160 , 0 ) ;
}
F_104 ( V_162 , & V_184 -> V_195 [ V_26 ] ) ;
V_32 = F_88 ( V_160 , V_161 , V_162 , V_164 , & V_169 ) ;
if ( V_32 )
goto V_193;
F_105 ( & V_182 -> V_188 ) ;
V_12 -> V_148 -> V_47 = V_47 ;
F_106 ( V_161 , V_169 , false ) ;
F_102 ( & V_161 -> V_154 ) ;
if ( V_161 != V_162 )
F_80 ( V_161 ) ;
F_107 ( & V_169 ) ;
return 0 ;
V_193:
F_108 ( V_12 ) ;
F_102 ( & V_161 -> V_154 ) ;
V_189:
F_105 ( & V_182 -> V_188 ) ;
if ( V_161 != V_162 )
F_80 ( V_162 ) ;
V_187:
F_27 ( V_164 ) ;
return V_32 ;
}
int
F_109 ( struct V_159 * V_160 ,
struct V_163 * V_196 )
{
struct V_167 * V_168 = V_160 -> V_169 ;
struct V_65 * V_66 = V_160 -> V_66 ;
struct V_8 * V_9 = V_66 -> V_9 ;
struct V_163 * V_164 ;
unsigned long V_170 ;
F_89 ( & V_9 -> V_171 , V_170 ) ;
if ( F_110 ( & V_168 -> V_86 ) ) {
F_85 ( V_66 , L_10 ) ;
F_91 ( & V_9 -> V_171 , V_170 ) ;
return - V_13 ;
}
V_164 = F_111 ( & V_168 -> V_86 , struct V_163 , V_26 ) ;
if ( V_164 -> V_176 ) {
F_112 ( V_164 -> V_12 , V_164 -> V_176 ) ;
} else {
F_108 ( V_164 -> V_12 ) ;
}
F_98 ( & V_164 -> V_26 ) ;
if ( V_196 )
* V_196 = * V_164 ;
F_27 ( V_164 ) ;
F_91 ( & V_9 -> V_171 , V_170 ) ;
return 0 ;
}
int
F_113 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_2 ( V_2 , F_3 ( * V_66 ) , V_86 ) ;
struct V_159 * V_160 = V_66 -> V_185 ;
struct V_163 V_197 ;
if ( ! F_109 ( V_160 , & V_197 ) ) {
F_114 ( V_66 -> V_9 , F_12 ( V_197 . V_12 ) ,
V_197 . V_155 + V_197 . V_12 -> V_198 *
V_197 . V_199 + V_197 . V_12 -> V_200 *
V_197 . V_201 / 8 ) ;
}
return V_7 ;
}
int
F_115 ( struct V_50 * V_51 , struct V_8 * V_9 ,
struct V_202 * args )
{
struct V_181 * V_182 = V_181 ( V_51 ) ;
struct V_55 * V_154 ;
T_4 V_203 ;
int V_32 ;
args -> V_199 = F_116 ( args -> V_204 * ( args -> V_201 / 8 ) , 256 ) ;
args -> V_205 = args -> V_199 * args -> V_206 ;
args -> V_205 = F_116 ( args -> V_205 , V_207 ) ;
if ( V_65 ( V_9 ) -> V_105 . V_104 . V_74 . V_208 != 0 )
V_203 = V_209 ;
else
V_203 = V_210 ;
V_32 = F_117 ( V_182 , args -> V_205 , 0 , V_203 , 0 , 0 , & V_154 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_29 ( V_51 , & V_154 -> V_49 , & args -> V_52 ) ;
F_25 ( & V_154 -> V_49 ) ;
return V_32 ;
}
int
F_118 ( struct V_50 * V_51 ,
struct V_8 * V_9 ,
T_4 V_52 , T_5 * V_211 )
{
struct V_60 * V_49 ;
V_49 = F_35 ( V_51 , V_52 ) ;
if ( V_49 ) {
struct V_55 * V_154 = F_37 ( V_49 ) ;
* V_211 = F_119 ( & V_154 -> V_154 . V_212 ) ;
F_25 ( V_49 ) ;
return 0 ;
}
return - V_62 ;
}
