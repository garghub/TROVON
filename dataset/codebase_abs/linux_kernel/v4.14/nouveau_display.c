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
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
F_19 ( & V_4 -> V_5 ) ;
}
}
static int
F_20 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_11 * V_12 ;
int V_32 ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
V_32 = F_21 (&disp->disp,
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
V_32 = F_22 ( V_9 , V_9 -> V_42 . V_43 ) ;
if ( V_32 ) {
F_18 ( V_9 ) ;
return V_32 ;
}
return 0 ;
}
static void
F_23 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_46 ( V_45 ) ;
if ( V_47 -> V_48 )
F_24 ( & V_47 -> V_48 -> V_49 ) ;
F_25 ( V_45 ) ;
F_26 ( V_47 ) ;
}
static int
F_27 ( struct V_44 * V_45 ,
struct V_50 * V_51 ,
unsigned int * V_52 )
{
struct V_46 * V_47 = V_46 ( V_45 ) ;
return F_28 ( V_51 , & V_47 -> V_48 -> V_49 , V_52 ) ;
}
int
F_29 ( struct V_8 * V_9 ,
const struct V_53 * V_54 ,
struct V_55 * V_48 ,
struct V_46 * * V_56 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
struct V_46 * V_47 ;
int V_32 ;
if ( V_58 -> V_59 . V_60 . V_61 . V_62 < V_63 &&
( V_54 -> V_64 == V_65 ||
V_54 -> V_64 == V_66 ||
V_54 -> V_64 == V_67 ||
V_54 -> V_64 == V_68 ) &&
( V_54 -> V_69 [ 0 ] & 0x3f ||
V_54 -> V_69 [ 0 ] >= 0x10000 ||
( V_54 -> V_69 [ 1 ] &&
V_54 -> V_69 [ 0 ] != V_54 -> V_69 [ 1 ] ) ) ) {
struct V_70 V_71 ;
F_30 ( L_1 ,
F_31 ( V_54 -> V_64 ,
& V_71 ) ,
V_54 -> V_69 [ 0 ] ,
V_54 -> V_69 [ 1 ] ) ;
return - V_13 ;
}
if ( ! ( V_47 = * V_56 = F_32 ( sizeof( * V_47 ) , V_72 ) ) )
return - V_73 ;
F_33 ( V_9 , & V_47 -> V_6 , V_54 ) ;
V_47 -> V_48 = V_48 ;
V_32 = F_34 ( V_9 , & V_47 -> V_6 , & V_74 ) ;
if ( V_32 )
F_26 ( V_47 ) ;
return V_32 ;
}
struct V_44 *
F_35 ( struct V_8 * V_9 ,
struct V_50 * V_51 ,
const struct V_53 * V_54 )
{
struct V_46 * V_47 ;
struct V_55 * V_48 ;
struct V_75 * V_49 ;
int V_32 ;
V_49 = F_36 ( V_51 , V_54 -> V_76 [ 0 ] ) ;
if ( ! V_49 )
return F_37 ( - V_77 ) ;
V_48 = F_38 ( V_49 ) ;
V_32 = F_29 ( V_9 , V_54 , V_48 , & V_47 ) ;
if ( V_32 == 0 )
return & V_47 -> V_6 ;
F_24 ( V_49 ) ;
return F_37 ( V_32 ) ;
}
static void
F_39 ( struct V_78 * V_79 )
{
struct V_57 * V_58 = F_2 ( V_79 , F_3 ( * V_58 ) , V_80 ) ;
F_40 ( V_58 -> V_9 -> V_9 ) ;
F_41 ( V_58 -> V_9 ) ;
F_42 ( V_58 -> V_9 ) ;
F_43 ( V_58 -> V_9 -> V_9 ) ;
F_44 ( V_58 -> V_9 -> V_9 ) ;
}
static int
F_45 ( struct V_81 * V_82 , unsigned long V_83 ,
void * V_84 )
{
struct V_57 * V_58 = F_2 ( V_82 , F_3 ( * V_58 ) , V_85 ) ;
struct V_86 * V_61 = V_84 ;
if ( ! strcmp ( V_61 -> V_87 , V_88 ) ) {
if ( V_61 -> type == V_89 ) {
F_46 ( & V_58 -> V_80 ) ;
return V_90 ;
}
}
return V_91 ;
}
int
F_47 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_57 * V_58 = V_57 ( V_9 ) ;
struct V_92 * V_93 ;
int V_32 ;
V_32 = V_29 -> V_94 ( V_9 ) ;
if ( V_32 )
return V_32 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
struct V_95 * V_96 = V_95 ( V_93 ) ;
F_7 ( & V_96 -> V_97 ) ;
}
F_7 ( & V_58 -> V_98 ) ;
return V_32 ;
}
void
F_48 ( struct V_8 * V_9 , bool V_99 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_57 * V_58 = V_57 ( V_9 ) ;
struct V_92 * V_93 ;
if ( ! V_99 ) {
if ( F_49 ( V_9 ) )
F_50 ( V_9 ) ;
else
F_51 ( V_9 ) ;
}
F_9 ( & V_58 -> V_98 ) ;
F_17 (connector, &dev->mode_config.connector_list, head) {
struct V_95 * V_96 = V_95 ( V_93 ) ;
F_9 ( & V_96 -> V_97 ) ;
}
F_52 ( V_9 ) ;
V_29 -> V_100 ( V_9 ) ;
}
static void
F_53 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
int V_101 ;
if ( V_29 -> V_29 . V_102 < V_103 )
V_101 = 0 ;
else
if ( V_29 -> V_29 . V_102 < V_104 )
V_101 = 1 ;
else
V_101 = 2 ;
F_54 ( V_29 -> V_105 , V_101 , L_2 , V_106 ) ;
F_54 ( V_29 -> V_107 , V_101 , L_3 , V_108 ) ;
F_54 ( V_29 -> V_109 , V_101 , L_4 , V_110 ) ;
V_29 -> V_111 =
F_55 ( V_9 , 0 , L_5 , 0 , 128 ) ;
V_29 -> V_112 =
F_55 ( V_9 , 0 , L_6 , 0 , 128 ) ;
if ( V_101 < 1 )
return;
V_29 -> V_113 =
F_55 ( V_9 , 0 , L_7 , 0 , 180 ) ;
V_29 -> V_114 =
F_55 ( V_9 , 0 , L_8 , 0 , 200 ) ;
}
int
F_56 ( struct V_8 * V_9 )
{
struct V_57 * V_58 = V_57 ( V_9 ) ;
struct V_115 * V_60 = F_57 ( & V_58 -> V_59 . V_60 ) ;
struct V_28 * V_29 ;
int V_32 ;
V_29 = V_58 -> V_116 = F_32 ( sizeof( * V_29 ) , V_72 ) ;
if ( ! V_29 )
return - V_73 ;
F_58 ( V_9 ) ;
F_59 ( V_9 ) ;
F_60 ( V_9 ) ;
V_9 -> V_42 . V_117 = & V_118 ;
V_9 -> V_42 . V_119 = V_60 -> V_120 -> V_121 ( V_60 , 1 ) ;
V_9 -> V_42 . V_122 = 0 ;
V_9 -> V_42 . V_123 = 0 ;
if ( V_58 -> V_59 . V_60 . V_61 . V_62 < V_124 ) {
V_9 -> V_42 . V_125 = 2048 ;
V_9 -> V_42 . V_126 = 2048 ;
} else
if ( V_58 -> V_59 . V_60 . V_61 . V_62 < V_63 ) {
V_9 -> V_42 . V_125 = 4096 ;
V_9 -> V_42 . V_126 = 4096 ;
} else
if ( V_58 -> V_59 . V_60 . V_61 . V_62 < V_127 ) {
V_9 -> V_42 . V_125 = 8192 ;
V_9 -> V_42 . V_126 = 8192 ;
} else {
V_9 -> V_42 . V_125 = 16384 ;
V_9 -> V_42 . V_126 = 16384 ;
}
V_9 -> V_42 . V_128 = 24 ;
V_9 -> V_42 . V_129 = 1 ;
if ( V_58 -> V_59 . V_60 . V_61 . V_130 < 0x11 )
V_9 -> V_42 . V_131 = false ;
else
V_9 -> V_42 . V_131 = true ;
F_61 ( V_9 ) ;
F_52 ( V_9 ) ;
if ( V_132 != 2 && V_58 -> V_133 . V_134 . V_135 ) {
static const T_2 V_102 [] = {
V_136 ,
V_137 ,
V_138 ,
V_139 ,
V_140 ,
V_141 ,
V_104 ,
V_142 ,
V_143 ,
V_144 ,
V_145 ,
V_103 ,
V_146 ,
} ;
int V_147 ;
for ( V_147 = 0 , V_32 = - V_148 ; V_32 && V_147 < F_62 ( V_102 ) ; V_147 ++ ) {
V_32 = F_63 ( & V_58 -> V_59 . V_60 . V_149 , 0 ,
V_102 [ V_147 ] , NULL , 0 , & V_29 -> V_29 ) ;
}
if ( V_32 == 0 ) {
F_53 ( V_9 ) ;
if ( V_29 -> V_29 . V_102 < V_103 )
V_32 = F_64 ( V_9 ) ;
else
V_32 = F_65 ( V_9 ) ;
}
} else {
V_32 = 0 ;
}
if ( V_32 )
goto V_150;
F_66 ( V_9 ) ;
if ( V_9 -> V_42 . V_43 ) {
V_32 = F_20 ( V_9 ) ;
if ( V_32 )
goto V_151;
}
F_67 ( V_9 ) ;
F_68 ( & V_58 -> V_80 , F_39 ) ;
#ifdef F_69
V_58 -> V_85 . V_152 = F_45 ;
F_70 ( & V_58 -> V_85 ) ;
#endif
return 0 ;
V_151:
V_29 -> V_153 ( V_9 ) ;
V_150:
F_71 ( V_9 ) ;
F_72 ( V_9 ) ;
return V_32 ;
}
void
F_73 ( struct V_8 * V_9 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
#ifdef F_69
F_74 ( & V_57 ( V_9 ) -> V_85 ) ;
#endif
F_75 ( V_9 ) ;
F_18 ( V_9 ) ;
F_71 ( V_9 ) ;
F_72 ( V_9 ) ;
if ( V_29 -> V_153 )
V_29 -> V_153 ( V_9 ) ;
F_76 ( & V_29 -> V_29 ) ;
V_57 ( V_9 ) -> V_116 = NULL ;
F_26 ( V_29 ) ;
}
int
F_77 ( struct V_8 * V_9 , bool V_154 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_11 * V_12 ;
if ( F_49 ( V_9 ) ) {
if ( ! V_154 ) {
V_29 -> V_99 = F_78 ( V_9 ) ;
if ( F_79 ( V_29 -> V_99 ) ) {
int V_32 = F_80 ( V_29 -> V_99 ) ;
V_29 -> V_99 = NULL ;
return V_32 ;
}
}
F_48 ( V_9 , true ) ;
return 0 ;
}
F_48 ( V_9 , true ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_46 * V_155 ;
V_155 = V_46 ( V_12 -> V_156 -> V_47 ) ;
if ( ! V_155 || ! V_155 -> V_48 )
continue;
F_81 ( V_155 -> V_48 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( V_4 -> V_157 . V_48 ) {
if ( V_4 -> V_157 . V_158 )
F_82 ( V_4 -> V_157 . V_48 ) ;
F_81 ( V_4 -> V_157 . V_48 ) ;
}
}
return 0 ;
}
void
F_83 ( struct V_8 * V_9 , bool V_154 )
{
struct V_28 * V_29 = V_28 ( V_9 ) ;
struct V_57 * V_58 = V_57 ( V_9 ) ;
struct V_11 * V_12 ;
int V_32 ;
if ( F_49 ( V_9 ) ) {
F_47 ( V_9 ) ;
if ( V_29 -> V_99 ) {
F_84 ( V_9 , V_29 -> V_99 ) ;
V_29 -> V_99 = NULL ;
}
return;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_46 * V_155 ;
V_155 = V_46 ( V_12 -> V_156 -> V_47 ) ;
if ( ! V_155 || ! V_155 -> V_48 )
continue;
V_32 = F_85 ( V_155 -> V_48 , V_159 , true ) ;
if ( V_32 )
F_86 ( V_58 , L_9 ) ;
}
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_157 . V_48 )
continue;
V_32 = F_85 ( V_4 -> V_157 . V_48 , V_159 , true ) ;
if ( ! V_32 && V_4 -> V_157 . V_158 )
V_32 = F_87 ( V_4 -> V_157 . V_48 ) ;
if ( V_32 )
F_86 ( V_58 , L_10 ) ;
}
F_47 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
V_4 -> V_160 . V_161 = 0 ;
}
if ( V_154 )
return;
F_88 ( V_9 ) ;
F_17 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_12 ) ;
if ( ! V_4 -> V_157 . V_48 )
continue;
if ( V_4 -> V_157 . V_158 )
V_4 -> V_157 . V_158 ( V_4 , V_4 -> V_157 . V_48 -> V_162 . V_163 ) ;
V_4 -> V_157 . V_164 ( V_4 , V_4 -> V_165 ,
V_4 -> V_166 ) ;
}
}
static int
F_89 ( struct V_167 * V_168 ,
struct V_55 * V_169 ,
struct V_55 * V_170 ,
struct V_171 * V_172 ,
struct V_173 * * V_174 )
{
struct V_175 * V_176 = V_168 -> V_177 ;
struct V_57 * V_58 = V_168 -> V_58 ;
struct V_8 * V_9 = V_58 -> V_9 ;
unsigned long V_178 ;
int V_32 ;
F_90 ( & V_9 -> V_179 , V_178 ) ;
F_91 ( & V_172 -> V_26 , & V_176 -> V_98 ) ;
F_92 ( & V_9 -> V_179 , V_178 ) ;
V_32 = F_93 ( V_169 , V_168 , false , false ) ;
if ( V_32 )
goto V_180;
V_32 = F_94 ( V_168 , 2 ) ;
if ( V_32 )
goto V_180;
F_95 ( V_168 , V_181 , V_182 , 1 ) ;
F_96 ( V_168 , 0x00000000 ) ;
F_97 ( V_168 ) ;
V_32 = F_98 ( V_168 , false , V_174 ) ;
if ( V_32 )
goto V_180;
return 0 ;
V_180:
F_90 ( & V_9 -> V_179 , V_178 ) ;
F_99 ( & V_172 -> V_26 ) ;
F_92 ( & V_9 -> V_179 , V_178 ) ;
return V_32 ;
}
int
F_100 ( struct V_11 * V_12 , struct V_44 * V_47 ,
struct V_183 * V_184 , T_3 V_178 ,
struct V_185 * V_186 )
{
const int V_187 = ( V_178 & V_188 ) ? 0 : 1 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_57 * V_58 = V_57 ( V_9 ) ;
struct V_55 * V_169 = V_46 ( V_12 -> V_156 -> V_47 ) -> V_48 ;
struct V_55 * V_170 = V_46 ( V_47 ) -> V_48 ;
struct V_171 * V_172 ;
struct V_167 * V_168 ;
struct V_189 * V_190 ;
struct V_173 * V_177 ;
struct V_191 * V_192 = V_191 ( V_9 ) ;
int V_26 = V_3 ( V_12 ) -> V_27 ;
int V_32 ;
V_168 = V_58 -> V_193 ;
if ( ! V_168 )
return - V_148 ;
V_190 = ( void * ) V_168 -> V_194 . V_59 ;
V_172 = F_32 ( sizeof( * V_172 ) , V_72 ) ;
if ( ! V_172 )
return - V_73 ;
if ( V_170 != V_169 ) {
V_32 = F_85 ( V_170 , V_159 , true ) ;
if ( V_32 )
goto V_195;
}
F_101 ( & V_190 -> V_196 ) ;
V_32 = F_102 ( & V_170 -> V_162 , true , false , NULL ) ;
if ( V_32 )
goto V_197;
V_32 = F_93 ( V_170 , V_168 , false , true ) ;
if ( V_32 ) {
F_103 ( & V_170 -> V_162 ) ;
goto V_197;
}
if ( V_170 != V_169 ) {
F_103 ( & V_170 -> V_162 ) ;
V_32 = F_102 ( & V_169 -> V_162 , true , false , NULL ) ;
if ( V_32 )
goto V_197;
}
* V_172 = (struct V_171 )
{ { } , V_184 , V_12 , V_47 -> V_198 -> V_199 [ 0 ] * 8 , V_47 -> V_69 [ 0 ] ,
V_170 -> V_162 . V_163 } ;
F_104 ( V_12 ) ;
if ( V_187 ) {
V_32 = F_94 ( V_168 , 8 ) ;
if ( V_32 )
goto V_200;
F_95 ( V_168 , V_201 , 0x012c , 1 ) ;
F_96 ( V_168 , 0 ) ;
F_95 ( V_168 , V_201 , 0x0134 , 1 ) ;
F_96 ( V_168 , V_26 ) ;
F_95 ( V_168 , V_201 , 0x0100 , 1 ) ;
F_96 ( V_168 , 0 ) ;
F_95 ( V_168 , V_201 , 0x0130 , 1 ) ;
F_96 ( V_168 , 0 ) ;
}
F_105 ( V_170 , & V_192 -> V_202 [ V_26 ] ) ;
V_32 = F_89 ( V_168 , V_169 , V_170 , V_172 , & V_177 ) ;
if ( V_32 )
goto V_200;
F_106 ( & V_190 -> V_196 ) ;
V_12 -> V_156 -> V_47 = V_47 ;
F_107 ( V_169 , V_177 , false ) ;
F_103 ( & V_169 -> V_162 ) ;
if ( V_169 != V_170 )
F_81 ( V_169 ) ;
F_108 ( & V_177 ) ;
return 0 ;
V_200:
F_109 ( V_12 ) ;
F_103 ( & V_169 -> V_162 ) ;
V_197:
F_106 ( & V_190 -> V_196 ) ;
if ( V_169 != V_170 )
F_81 ( V_170 ) ;
V_195:
F_26 ( V_172 ) ;
return V_32 ;
}
int
F_110 ( struct V_167 * V_168 ,
struct V_171 * V_203 )
{
struct V_175 * V_176 = V_168 -> V_177 ;
struct V_57 * V_58 = V_168 -> V_58 ;
struct V_8 * V_9 = V_58 -> V_9 ;
struct V_171 * V_172 ;
unsigned long V_178 ;
F_90 ( & V_9 -> V_179 , V_178 ) ;
if ( F_111 ( & V_176 -> V_98 ) ) {
F_86 ( V_58 , L_11 ) ;
F_92 ( & V_9 -> V_179 , V_178 ) ;
return - V_13 ;
}
V_172 = F_112 ( & V_176 -> V_98 , struct V_171 , V_26 ) ;
if ( V_172 -> V_184 ) {
F_113 ( V_172 -> V_12 , V_172 -> V_184 ) ;
} else {
F_109 ( V_172 -> V_12 ) ;
}
F_99 ( & V_172 -> V_26 ) ;
if ( V_203 )
* V_203 = * V_172 ;
F_26 ( V_172 ) ;
F_92 ( & V_9 -> V_179 , V_178 ) ;
return 0 ;
}
int
F_114 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = F_2 ( V_2 , F_3 ( * V_58 ) , V_98 ) ;
struct V_167 * V_168 = V_58 -> V_193 ;
struct V_171 V_204 ;
if ( ! F_110 ( V_168 , & V_204 ) ) {
F_115 ( V_58 -> V_9 , F_12 ( V_204 . V_12 ) ,
V_204 . V_163 + V_204 . V_12 -> V_205 *
V_204 . V_206 + V_204 . V_12 -> V_207 *
V_204 . V_208 / 8 ) ;
}
return V_7 ;
}
int
F_116 ( struct V_50 * V_51 , struct V_8 * V_9 ,
struct V_209 * args )
{
struct V_189 * V_190 = V_189 ( V_51 ) ;
struct V_55 * V_162 ;
T_4 V_210 ;
int V_32 ;
args -> V_206 = F_117 ( args -> V_211 * ( args -> V_208 / 8 ) , 256 ) ;
args -> V_212 = args -> V_206 * args -> V_213 ;
args -> V_212 = F_117 ( args -> V_212 , V_214 ) ;
if ( V_57 ( V_9 ) -> V_59 . V_60 . V_61 . V_215 != 0 )
V_210 = V_216 ;
else
V_210 = V_217 ;
V_32 = F_118 ( V_190 , args -> V_212 , 0 , V_210 , 0 , 0 , & V_162 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_28 ( V_51 , & V_162 -> V_49 , & args -> V_52 ) ;
F_24 ( & V_162 -> V_49 ) ;
return V_32 ;
}
int
F_119 ( struct V_50 * V_51 ,
struct V_8 * V_9 ,
T_4 V_52 , T_5 * V_218 )
{
struct V_75 * V_49 ;
V_49 = F_36 ( V_51 , V_52 ) ;
if ( V_49 ) {
struct V_55 * V_162 = F_38 ( V_49 ) ;
* V_218 = F_120 ( & V_162 -> V_162 . V_219 ) ;
F_24 ( V_49 ) ;
return 0 ;
}
return - V_77 ;
}
