static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , F_3 ( * V_4 ) , V_5 ) ;
F_4 ( V_4 -> V_6 . V_7 , V_4 -> V_8 ) ;
return V_9 ;
}
int
F_5 ( struct V_10 * V_7 , unsigned int V_11 )
{
struct V_12 * V_13 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( V_4 -> V_8 == V_11 ) {
F_7 ( & V_4 -> V_5 ) ;
return 0 ;
}
}
return - V_14 ;
}
void
F_8 ( struct V_10 * V_7 , unsigned int V_11 )
{
struct V_12 * V_13 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( V_4 -> V_8 == V_11 ) {
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
int
F_11 ( struct V_12 * V_13 , int * V_18 , int * V_19 ,
T_1 * V_20 , T_1 * V_21 )
{
struct {
struct V_22 V_6 ;
struct V_23 V_24 ;
} args = {
. V_6 . V_25 = V_26 ,
. V_6 . V_27 = V_3 ( V_13 ) -> V_8 ,
} ;
struct V_28 * V_29 = V_28 ( V_13 -> V_7 ) ;
struct V_30 * V_5 = & V_13 -> V_7 -> V_5 [ F_12 ( V_13 ) ] ;
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
F_16 ( struct V_10 * V_7 , unsigned int V_11 ,
unsigned int V_42 , int * V_18 , int * V_19 ,
T_1 * V_20 , T_1 * V_21 ,
const struct V_43 * V_44 )
{
struct V_12 * V_13 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_3 ( V_13 ) -> V_8 == V_11 ) {
return F_11 ( V_13 , V_18 , V_19 ,
V_20 , V_21 ) ;
}
}
return 0 ;
}
int
F_17 ( struct V_10 * V_7 , unsigned int V_11 ,
int * V_45 , struct V_46 * time , unsigned V_42 )
{
struct V_12 * V_13 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_3 ( V_13 ) -> V_8 == V_11 ) {
return F_18 ( V_7 ,
V_11 , V_45 , time , V_42 ,
& V_13 -> V_47 ) ;
}
}
return - V_14 ;
}
static void
F_19 ( struct V_10 * V_7 )
{
struct V_12 * V_13 ;
F_20 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
F_21 ( & V_4 -> V_5 ) ;
}
}
static int
F_22 ( struct V_10 * V_7 )
{
struct V_28 * V_29 = V_28 ( V_7 ) ;
struct V_12 * V_13 ;
int V_31 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
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
F_19 ( V_7 ) ;
return V_31 ;
}
}
V_31 = F_24 ( V_7 , V_7 -> V_48 . V_49 ) ;
if ( V_31 ) {
F_19 ( V_7 ) ;
return V_31 ;
}
return 0 ;
}
static void
F_25 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_52 ( V_51 ) ;
struct V_28 * V_29 = V_28 ( V_51 -> V_7 ) ;
if ( V_29 -> V_54 )
V_29 -> V_54 ( V_51 ) ;
if ( V_53 -> V_55 )
F_26 ( & V_53 -> V_55 -> V_56 ) ;
F_27 ( V_51 ) ;
F_28 ( V_53 ) ;
}
static int
F_29 ( struct V_50 * V_51 ,
struct V_57 * V_58 ,
unsigned int * V_59 )
{
struct V_52 * V_53 = V_52 ( V_51 ) ;
return F_30 ( V_58 , & V_53 -> V_55 -> V_56 , V_59 ) ;
}
int
F_31 ( struct V_10 * V_7 ,
struct V_52 * V_60 ,
const struct V_61 * V_62 ,
struct V_63 * V_55 )
{
struct V_28 * V_29 = V_28 ( V_7 ) ;
struct V_50 * V_53 = & V_60 -> V_6 ;
int V_31 ;
F_32 ( V_53 , V_62 ) ;
V_60 -> V_55 = V_55 ;
V_31 = F_33 ( V_7 , V_53 , & V_64 ) ;
if ( V_31 )
return V_31 ;
if ( V_29 -> V_65 ) {
V_31 = V_29 -> V_65 ( V_53 ) ;
if ( V_31 )
V_29 -> V_54 ( V_53 ) ;
}
return V_31 ;
}
static struct V_50 *
F_34 ( struct V_10 * V_7 ,
struct V_57 * V_58 ,
const struct V_61 * V_62 )
{
struct V_52 * V_66 ;
struct V_67 * V_56 ;
int V_31 = - V_68 ;
V_56 = F_35 ( V_58 , V_62 -> V_69 [ 0 ] ) ;
if ( ! V_56 )
return F_36 ( - V_70 ) ;
V_66 = F_37 ( sizeof( struct V_52 ) , V_71 ) ;
if ( ! V_66 )
goto V_72;
V_31 = F_31 ( V_7 , V_66 , V_62 , F_38 ( V_56 ) ) ;
if ( V_31 )
goto V_73;
return & V_66 -> V_6 ;
V_73:
F_28 ( V_66 ) ;
V_72:
F_26 ( V_56 ) ;
return F_36 ( V_31 ) ;
}
int
F_39 ( struct V_10 * V_7 )
{
struct V_28 * V_29 = V_28 ( V_7 ) ;
struct V_74 * V_75 = V_74 ( V_7 ) ;
struct V_76 * V_77 ;
int V_31 ;
V_31 = V_29 -> V_78 ( V_7 ) ;
if ( V_31 )
return V_31 ;
F_40 ( V_7 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
struct V_79 * V_80 = V_79 ( V_77 ) ;
F_7 ( & V_80 -> V_81 ) ;
}
F_7 ( & V_75 -> V_82 ) ;
return V_31 ;
}
void
F_41 ( struct V_10 * V_7 )
{
struct V_28 * V_29 = V_28 ( V_7 ) ;
struct V_74 * V_75 = V_74 ( V_7 ) ;
struct V_76 * V_77 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_7 -> V_48 . V_49 ; V_27 ++ )
F_42 ( V_7 , V_27 ) ;
F_9 ( & V_75 -> V_82 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
struct V_79 * V_80 = V_79 ( V_77 ) ;
F_9 ( & V_80 -> V_81 ) ;
}
F_43 ( V_7 ) ;
V_29 -> V_83 ( V_7 ) ;
}
static void
F_44 ( struct V_10 * V_7 )
{
struct V_28 * V_29 = V_28 ( V_7 ) ;
int V_84 ;
if ( V_29 -> V_29 . V_85 < V_86 )
V_84 = 0 ;
else
if ( V_29 -> V_29 . V_85 < V_87 )
V_84 = 1 ;
else
V_84 = 2 ;
F_45 ( V_29 -> V_88 , V_84 , L_1 , V_89 ) ;
F_45 ( V_29 -> V_90 , V_84 , L_2 , V_91 ) ;
F_45 ( V_29 -> V_92 , V_84 , L_3 , V_93 ) ;
V_29 -> V_94 =
F_46 ( V_7 , 0 , L_4 , 0 , 128 ) ;
V_29 -> V_95 =
F_46 ( V_7 , 0 , L_5 , 0 , 128 ) ;
if ( V_84 < 1 )
return;
V_29 -> V_96 =
F_46 ( V_7 , 0 , L_6 , 0 , 180 ) ;
V_29 -> V_97 =
F_46 ( V_7 , 0 , L_7 , 0 , 200 ) ;
}
int
F_47 ( struct V_10 * V_7 )
{
struct V_74 * V_75 = V_74 ( V_7 ) ;
struct V_98 * V_99 = F_48 ( & V_75 -> V_99 ) ;
struct V_28 * V_29 ;
int V_31 ;
V_29 = V_75 -> V_100 = F_37 ( sizeof( * V_29 ) , V_71 ) ;
if ( ! V_29 )
return - V_68 ;
F_49 ( V_7 ) ;
F_50 ( V_7 ) ;
F_51 ( V_7 ) ;
V_7 -> V_48 . V_101 = & V_102 ;
V_7 -> V_48 . V_103 = V_99 -> V_104 -> V_105 ( V_99 , 1 ) ;
V_7 -> V_48 . V_106 = 0 ;
V_7 -> V_48 . V_107 = 0 ;
if ( V_75 -> V_99 . V_108 . V_109 < V_110 ) {
V_7 -> V_48 . V_111 = 2048 ;
V_7 -> V_48 . V_112 = 2048 ;
} else
if ( V_75 -> V_99 . V_108 . V_109 < V_113 ) {
V_7 -> V_48 . V_111 = 4096 ;
V_7 -> V_48 . V_112 = 4096 ;
} else
if ( V_75 -> V_99 . V_108 . V_109 < V_114 ) {
V_7 -> V_48 . V_111 = 8192 ;
V_7 -> V_48 . V_112 = 8192 ;
} else {
V_7 -> V_48 . V_111 = 16384 ;
V_7 -> V_48 . V_112 = 16384 ;
}
V_7 -> V_48 . V_115 = 24 ;
V_7 -> V_48 . V_116 = 1 ;
if ( V_75 -> V_99 . V_108 . V_117 < 0x11 )
V_7 -> V_48 . V_118 = false ;
else
V_7 -> V_48 . V_118 = true ;
F_52 ( V_7 ) ;
F_43 ( V_7 ) ;
if ( V_119 != 2 && V_75 -> V_120 . V_121 . V_122 ) {
static const T_2 V_85 [] = {
V_123 ,
V_124 ,
V_125 ,
V_126 ,
V_87 ,
V_127 ,
V_128 ,
V_129 ,
V_130 ,
V_86 ,
V_131 ,
} ;
int V_132 ;
for ( V_132 = 0 , V_31 = - V_133 ; V_31 && V_132 < F_53 ( V_85 ) ; V_132 ++ ) {
V_31 = F_54 ( & V_75 -> V_99 . V_134 , 0 ,
V_85 [ V_132 ] , NULL , 0 , & V_29 -> V_29 ) ;
}
if ( V_31 == 0 ) {
F_44 ( V_7 ) ;
if ( V_29 -> V_29 . V_85 < V_86 )
V_31 = F_55 ( V_7 ) ;
else
V_31 = F_56 ( V_7 ) ;
}
} else {
V_31 = 0 ;
}
if ( V_31 )
goto V_135;
if ( V_7 -> V_48 . V_49 ) {
V_31 = F_22 ( V_7 ) ;
if ( V_31 )
goto V_136;
}
F_57 ( V_7 ) ;
return 0 ;
V_136:
V_29 -> V_137 ( V_7 ) ;
V_135:
F_58 ( V_7 ) ;
F_59 ( V_7 ) ;
return V_31 ;
}
void
F_60 ( struct V_10 * V_7 )
{
struct V_28 * V_29 = V_28 ( V_7 ) ;
F_61 ( V_7 ) ;
F_19 ( V_7 ) ;
F_58 ( V_7 ) ;
F_59 ( V_7 ) ;
if ( V_29 -> V_137 )
V_29 -> V_137 ( V_7 ) ;
F_62 ( & V_29 -> V_29 ) ;
V_74 ( V_7 ) -> V_100 = NULL ;
F_28 ( V_29 ) ;
}
int
F_63 ( struct V_10 * V_7 , bool V_138 )
{
struct V_12 * V_13 ;
F_41 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_52 * V_66 ;
V_66 = V_52 ( V_13 -> V_139 -> V_53 ) ;
if ( ! V_66 || ! V_66 -> V_55 )
continue;
F_64 ( V_66 -> V_55 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( V_4 -> V_140 . V_55 ) {
if ( V_4 -> V_140 . V_141 )
F_65 ( V_4 -> V_140 . V_55 ) ;
F_64 ( V_4 -> V_140 . V_55 ) ;
}
}
return 0 ;
}
void
F_66 ( struct V_10 * V_7 , bool V_138 )
{
struct V_74 * V_75 = V_74 ( V_7 ) ;
struct V_12 * V_13 ;
int V_31 , V_27 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_52 * V_66 ;
V_66 = V_52 ( V_13 -> V_139 -> V_53 ) ;
if ( ! V_66 || ! V_66 -> V_55 )
continue;
V_31 = F_67 ( V_66 -> V_55 , V_142 , true ) ;
if ( V_31 )
F_68 ( V_75 , L_8 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( ! V_4 -> V_140 . V_55 )
continue;
V_31 = F_67 ( V_4 -> V_140 . V_55 , V_142 , true ) ;
if ( ! V_31 && V_4 -> V_140 . V_141 )
V_31 = F_69 ( V_4 -> V_140 . V_55 ) ;
if ( V_31 )
F_68 ( V_75 , L_9 ) ;
}
F_39 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
V_4 -> V_143 . V_144 = 0 ;
}
if ( V_138 )
return;
F_70 ( V_7 ) ;
for ( V_27 = 0 ; V_27 < V_7 -> V_48 . V_49 ; V_27 ++ )
F_71 ( V_7 , V_27 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( ! V_4 -> V_140 . V_55 )
continue;
if ( V_4 -> V_140 . V_141 )
V_4 -> V_140 . V_141 ( V_4 , V_4 -> V_140 . V_55 -> V_145 . V_146 ) ;
V_4 -> V_140 . V_147 ( V_4 , V_4 -> V_148 ,
V_4 -> V_149 ) ;
}
}
static int
F_72 ( struct V_150 * V_151 ,
struct V_63 * V_152 ,
struct V_63 * V_153 ,
struct V_154 * V_155 ,
struct V_156 * * V_157 )
{
struct V_158 * V_159 = V_151 -> V_160 ;
struct V_74 * V_75 = V_151 -> V_75 ;
struct V_10 * V_7 = V_75 -> V_7 ;
unsigned long V_42 ;
int V_31 ;
F_73 ( & V_7 -> V_161 , V_42 ) ;
F_74 ( & V_155 -> V_27 , & V_159 -> V_82 ) ;
F_75 ( & V_7 -> V_161 , V_42 ) ;
V_31 = F_76 ( V_152 , V_151 , false , false ) ;
if ( V_31 )
goto V_162;
V_31 = F_77 ( V_151 , 2 ) ;
if ( V_31 )
goto V_162;
if ( V_75 -> V_99 . V_108 . V_109 < V_114 )
F_78 ( V_151 , V_163 , V_164 , 1 ) ;
else
F_79 ( V_151 , V_165 , V_164 , 1 ) ;
F_80 ( V_151 , 0x00000000 ) ;
F_81 ( V_151 ) ;
V_31 = F_82 ( V_151 , false , V_157 ) ;
if ( V_31 )
goto V_162;
return 0 ;
V_162:
F_73 ( & V_7 -> V_161 , V_42 ) ;
F_83 ( & V_155 -> V_27 ) ;
F_75 ( & V_7 -> V_161 , V_42 ) ;
return V_31 ;
}
int
F_84 ( struct V_12 * V_13 , struct V_50 * V_53 ,
struct V_166 * V_167 , T_3 V_42 )
{
const int V_168 = ( V_42 & V_169 ) ? 0 : 1 ;
struct V_10 * V_7 = V_13 -> V_7 ;
struct V_74 * V_75 = V_74 ( V_7 ) ;
struct V_63 * V_152 = V_52 ( V_13 -> V_139 -> V_53 ) -> V_55 ;
struct V_63 * V_153 = V_52 ( V_53 ) -> V_55 ;
struct V_154 * V_155 ;
struct V_150 * V_151 ;
struct V_170 * V_171 ;
struct V_156 * V_160 ;
int V_31 ;
V_151 = V_75 -> V_172 ;
if ( ! V_151 )
return - V_133 ;
V_171 = ( void * ) V_151 -> V_173 . V_174 ;
V_155 = F_37 ( sizeof( * V_155 ) , V_71 ) ;
if ( ! V_155 )
return - V_68 ;
if ( V_153 != V_152 ) {
V_31 = F_67 ( V_153 , V_142 , true ) ;
if ( V_31 )
goto V_175;
}
F_85 ( & V_171 -> V_176 ) ;
V_31 = F_86 ( & V_153 -> V_145 , true , false , NULL ) ;
if ( V_31 )
goto V_177;
V_31 = F_76 ( V_153 , V_151 , false , true ) ;
if ( V_31 ) {
F_87 ( & V_153 -> V_145 ) ;
goto V_177;
}
if ( V_153 != V_152 ) {
F_87 ( & V_153 -> V_145 ) ;
V_31 = F_86 ( & V_152 -> V_145 , true , false , NULL ) ;
if ( V_31 )
goto V_177;
}
* V_155 = (struct V_154 )
{ { } , V_167 , V_3 ( V_13 ) -> V_8 ,
V_53 -> V_178 , V_53 -> V_179 [ 0 ] , V_13 -> V_180 , V_13 -> V_181 ,
V_153 -> V_145 . V_146 } ;
F_88 ( V_7 , V_3 ( V_13 ) -> V_8 ) ;
if ( V_75 -> V_99 . V_108 . V_109 >= V_113 ) {
V_31 = F_89 ( V_13 , V_53 , V_151 , V_168 ) ;
if ( V_31 )
goto V_182;
} else {
struct V_183 * V_184 = V_183 ( V_7 ) ;
int V_27 = V_3 ( V_13 ) -> V_8 ;
if ( V_168 ) {
V_31 = F_77 ( V_151 , 8 ) ;
if ( V_31 )
goto V_182;
F_78 ( V_151 , V_185 , 0x012c , 1 ) ;
F_80 ( V_151 , 0 ) ;
F_78 ( V_151 , V_185 , 0x0134 , 1 ) ;
F_80 ( V_151 , V_27 ) ;
F_78 ( V_151 , V_185 , 0x0100 , 1 ) ;
F_80 ( V_151 , 0 ) ;
F_78 ( V_151 , V_185 , 0x0130 , 1 ) ;
F_80 ( V_151 , 0 ) ;
}
F_90 ( V_153 , & V_184 -> V_186 [ V_27 ] ) ;
}
V_31 = F_72 ( V_151 , V_152 , V_153 , V_155 , & V_160 ) ;
if ( V_31 )
goto V_182;
F_91 ( & V_171 -> V_176 ) ;
V_13 -> V_139 -> V_53 = V_53 ;
F_92 ( V_152 , V_160 , false ) ;
F_87 ( & V_152 -> V_145 ) ;
if ( V_152 != V_153 )
F_64 ( V_152 ) ;
F_93 ( & V_160 ) ;
return 0 ;
V_182:
F_94 ( V_7 , V_3 ( V_13 ) -> V_8 ) ;
F_87 ( & V_152 -> V_145 ) ;
V_177:
F_91 ( & V_171 -> V_176 ) ;
if ( V_152 != V_153 )
F_64 ( V_153 ) ;
V_175:
F_28 ( V_155 ) ;
return V_31 ;
}
int
F_95 ( struct V_150 * V_151 ,
struct V_154 * V_187 )
{
struct V_158 * V_159 = V_151 -> V_160 ;
struct V_74 * V_75 = V_151 -> V_75 ;
struct V_10 * V_7 = V_75 -> V_7 ;
struct V_154 * V_155 ;
unsigned long V_42 ;
F_73 ( & V_7 -> V_161 , V_42 ) ;
if ( F_96 ( & V_159 -> V_82 ) ) {
F_68 ( V_75 , L_10 ) ;
F_75 ( & V_7 -> V_161 , V_42 ) ;
return - V_14 ;
}
V_155 = F_97 ( & V_159 -> V_82 , struct V_154 , V_27 ) ;
if ( V_155 -> V_167 ) {
if ( V_75 -> V_99 . V_108 . V_109 < V_113 ) {
F_98 ( V_7 , V_155 -> V_13 , V_155 -> V_167 ) ;
} else {
F_99 ( V_7 , V_155 -> V_13 , V_155 -> V_167 ) ;
F_94 ( V_7 , V_155 -> V_13 ) ;
}
}
else {
F_94 ( V_7 , V_155 -> V_13 ) ;
}
F_83 ( & V_155 -> V_27 ) ;
if ( V_187 )
* V_187 = * V_155 ;
F_28 ( V_155 ) ;
F_75 ( & V_7 -> V_161 , V_42 ) ;
return 0 ;
}
int
F_100 ( struct V_1 * V_2 )
{
struct V_74 * V_75 = F_2 ( V_2 , F_3 ( * V_75 ) , V_82 ) ;
struct V_150 * V_151 = V_75 -> V_172 ;
struct V_154 V_188 ;
if ( ! F_95 ( V_151 , & V_188 ) ) {
if ( V_75 -> V_99 . V_108 . V_109 < V_113 ) {
F_101 ( V_75 -> V_7 , V_188 . V_13 , V_188 . V_146 +
V_188 . V_181 * V_188 . V_189 +
V_188 . V_180 * V_188 . V_190 / 8 ) ;
}
}
return V_9 ;
}
int
F_102 ( struct V_57 * V_58 , struct V_10 * V_7 ,
struct V_191 * args )
{
struct V_63 * V_145 ;
T_4 V_192 ;
int V_31 ;
args -> V_189 = F_103 ( args -> V_193 * ( args -> V_190 / 8 ) , 256 ) ;
args -> V_194 = args -> V_189 * args -> V_195 ;
args -> V_194 = F_103 ( args -> V_194 , V_196 ) ;
if ( V_74 ( V_7 ) -> V_99 . V_108 . V_197 != 0 )
V_192 = V_198 ;
else
V_192 = V_199 ;
V_31 = F_104 ( V_7 , args -> V_194 , 0 , V_192 , 0 , 0 , & V_145 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_30 ( V_58 , & V_145 -> V_56 , & args -> V_59 ) ;
F_26 ( & V_145 -> V_56 ) ;
return V_31 ;
}
int
F_105 ( struct V_57 * V_58 ,
struct V_10 * V_7 ,
T_4 V_59 , T_5 * V_200 )
{
struct V_67 * V_56 ;
V_56 = F_35 ( V_58 , V_59 ) ;
if ( V_56 ) {
struct V_63 * V_145 = F_38 ( V_56 ) ;
* V_200 = F_106 ( & V_145 -> V_145 . V_201 ) ;
F_26 ( V_56 ) ;
return 0 ;
}
return - V_70 ;
}
