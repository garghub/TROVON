static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , F_3 ( * V_4 ) , V_5 ) ;
F_4 ( V_4 -> V_6 . V_7 , V_4 -> V_8 ) ;
return V_9 ;
}
int
F_5 ( struct V_10 * V_7 , int V_11 )
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
F_8 ( struct V_10 * V_7 , int V_11 )
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
. V_6 . V_11 = V_3 ( V_13 ) -> V_8 ,
} ;
struct V_27 * V_28 = V_27 ( V_13 -> V_7 ) ;
int V_29 , V_30 = 1 ;
do {
V_29 = F_12 ( & V_28 -> V_28 , 0 , & args , sizeof( args ) ) ;
if ( V_29 != 0 )
return 0 ;
if ( args . V_24 . V_31 ) {
V_29 |= V_32 ;
V_29 |= V_33 ;
break;
}
if ( V_30 ) F_13 ( V_13 -> V_34 ) ;
} while ( V_30 -- );
* V_19 = args . V_24 . V_35 ;
* V_18 = F_10 ( args . V_24 . V_36 , args . V_24 . V_37 ,
args . V_24 . V_38 , args . V_24 . V_31 ) ;
if ( V_20 ) * V_20 = F_14 ( args . V_24 . time [ 0 ] ) ;
if ( V_21 ) * V_21 = F_14 ( args . V_24 . time [ 1 ] ) ;
if ( * V_18 < 0 )
V_29 |= V_39 ;
return V_29 ;
}
int
F_15 ( struct V_10 * V_7 , int V_11 , unsigned int V_40 ,
int * V_18 , int * V_19 , T_1 * V_20 , T_1 * V_21 )
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
F_16 ( struct V_10 * V_7 , int V_11 , int * V_41 ,
struct V_42 * time , unsigned V_40 )
{
struct V_12 * V_13 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_3 ( V_13 ) -> V_8 == V_11 ) {
return F_17 ( V_7 ,
V_11 , V_41 , time , V_40 , V_13 ,
& V_13 -> V_43 ) ;
}
}
return - V_14 ;
}
static void
F_18 ( struct V_10 * V_7 )
{
struct V_12 * V_13 ;
F_19 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
F_20 ( & V_4 -> V_5 ) ;
}
}
static int
F_21 ( struct V_10 * V_7 )
{
struct V_27 * V_28 = V_27 ( V_7 ) ;
struct V_12 * V_13 ;
int V_29 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
V_29 = F_22 (&disp->disp,
nouveau_display_vblank_handler, false,
NV04_DISP_NTFY_VBLANK,
&(struct nvif_notify_head_req_v0) {
.head = nv_crtc->index,
},
sizeof(struct nvif_notify_head_req_v0),
sizeof(struct nvif_notify_head_rep_v0),
&nv_crtc->vblank) ;
if ( V_29 ) {
F_18 ( V_7 ) ;
return V_29 ;
}
}
V_29 = F_23 ( V_7 , V_7 -> V_44 . V_45 ) ;
if ( V_29 ) {
F_18 ( V_7 ) ;
return V_29 ;
}
return 0 ;
}
static void
F_24 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_48 ( V_47 ) ;
struct V_27 * V_28 = V_27 ( V_47 -> V_7 ) ;
if ( V_28 -> V_50 )
V_28 -> V_50 ( V_47 ) ;
if ( V_49 -> V_51 )
F_25 ( & V_49 -> V_51 -> V_52 ) ;
F_26 ( V_47 ) ;
F_27 ( V_49 ) ;
}
static int
F_28 ( struct V_46 * V_47 ,
struct V_53 * V_54 ,
unsigned int * V_55 )
{
struct V_48 * V_49 = V_48 ( V_47 ) ;
return F_29 ( V_54 , & V_49 -> V_51 -> V_52 , V_55 ) ;
}
int
F_30 ( struct V_10 * V_7 ,
struct V_48 * V_56 ,
struct V_57 * V_58 ,
struct V_59 * V_51 )
{
struct V_27 * V_28 = V_27 ( V_7 ) ;
struct V_46 * V_49 = & V_56 -> V_6 ;
int V_29 ;
F_31 ( V_49 , V_58 ) ;
V_56 -> V_51 = V_51 ;
V_29 = F_32 ( V_7 , V_49 , & V_60 ) ;
if ( V_29 )
return V_29 ;
if ( V_28 -> V_61 ) {
V_29 = V_28 -> V_61 ( V_49 ) ;
if ( V_29 )
V_28 -> V_50 ( V_49 ) ;
}
return V_29 ;
}
static struct V_46 *
F_33 ( struct V_10 * V_7 ,
struct V_53 * V_54 ,
struct V_57 * V_58 )
{
struct V_48 * V_62 ;
struct V_63 * V_52 ;
int V_29 = - V_64 ;
V_52 = F_34 ( V_7 , V_54 , V_58 -> V_65 [ 0 ] ) ;
if ( ! V_52 )
return F_35 ( - V_66 ) ;
V_62 = F_36 ( sizeof( struct V_48 ) , V_67 ) ;
if ( ! V_62 )
goto V_68;
V_29 = F_30 ( V_7 , V_62 , V_58 , F_37 ( V_52 ) ) ;
if ( V_29 )
goto V_69;
return & V_62 -> V_6 ;
V_69:
F_27 ( V_62 ) ;
V_68:
F_38 ( V_52 ) ;
return F_35 ( V_29 ) ;
}
int
F_39 ( struct V_10 * V_7 )
{
struct V_27 * V_28 = V_27 ( V_7 ) ;
struct V_70 * V_71 = V_70 ( V_7 ) ;
struct V_72 * V_73 ;
int V_29 ;
V_29 = V_28 -> V_74 ( V_7 ) ;
if ( V_29 )
return V_29 ;
F_40 ( V_7 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
struct V_75 * V_76 = V_75 ( V_73 ) ;
F_7 ( & V_76 -> V_77 ) ;
}
F_7 ( & V_71 -> V_78 ) ;
return V_29 ;
}
void
F_41 ( struct V_10 * V_7 )
{
struct V_27 * V_28 = V_27 ( V_7 ) ;
struct V_70 * V_71 = V_70 ( V_7 ) ;
struct V_72 * V_73 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_44 . V_45 ; V_11 ++ )
F_42 ( V_7 , V_11 ) ;
F_9 ( & V_71 -> V_78 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
struct V_75 * V_76 = V_75 ( V_73 ) ;
F_9 ( & V_76 -> V_77 ) ;
}
F_43 ( V_7 ) ;
V_28 -> V_79 ( V_7 ) ;
}
static void
F_44 ( struct V_10 * V_7 )
{
struct V_27 * V_28 = V_27 ( V_7 ) ;
int V_80 ;
if ( V_28 -> V_28 . V_81 < V_82 )
V_80 = 0 ;
else
if ( V_28 -> V_28 . V_81 < V_83 )
V_80 = 1 ;
else
V_80 = 2 ;
F_45 ( V_28 -> V_84 , V_80 , L_1 , V_85 ) ;
F_45 ( V_28 -> V_86 , V_80 , L_2 , V_87 ) ;
F_45 ( V_28 -> V_88 , V_80 , L_3 , V_89 ) ;
V_28 -> V_90 =
F_46 ( V_7 , 0 , L_4 , 0 , 128 ) ;
V_28 -> V_91 =
F_46 ( V_7 , 0 , L_5 , 0 , 128 ) ;
if ( V_80 < 1 )
return;
V_28 -> V_92 =
F_46 ( V_7 , 0 , L_6 , 0 , 180 ) ;
V_28 -> V_93 =
F_46 ( V_7 , 0 , L_7 , 0 , 200 ) ;
}
int
F_47 ( struct V_10 * V_7 )
{
struct V_70 * V_71 = V_70 ( V_7 ) ;
struct V_94 * V_95 = F_48 ( & V_71 -> V_95 ) ;
struct V_27 * V_28 ;
int V_29 ;
V_28 = V_71 -> V_96 = F_36 ( sizeof( * V_28 ) , V_67 ) ;
if ( ! V_28 )
return - V_64 ;
F_49 ( V_7 ) ;
F_50 ( V_7 ) ;
F_51 ( V_7 ) ;
V_7 -> V_44 . V_97 = & V_98 ;
V_7 -> V_44 . V_99 = V_95 -> V_100 -> V_101 ( V_95 , 1 ) ;
V_7 -> V_44 . V_102 = 0 ;
V_7 -> V_44 . V_103 = 0 ;
if ( V_71 -> V_95 . V_104 . V_105 < V_106 ) {
V_7 -> V_44 . V_107 = 2048 ;
V_7 -> V_44 . V_108 = 2048 ;
} else
if ( V_71 -> V_95 . V_104 . V_105 < V_109 ) {
V_7 -> V_44 . V_107 = 4096 ;
V_7 -> V_44 . V_108 = 4096 ;
} else
if ( V_71 -> V_95 . V_104 . V_105 < V_110 ) {
V_7 -> V_44 . V_107 = 8192 ;
V_7 -> V_44 . V_108 = 8192 ;
} else {
V_7 -> V_44 . V_107 = 16384 ;
V_7 -> V_44 . V_108 = 16384 ;
}
V_7 -> V_44 . V_111 = 24 ;
V_7 -> V_44 . V_112 = 1 ;
if ( V_71 -> V_95 . V_104 . V_113 < 0x11 )
V_7 -> V_44 . V_114 = false ;
else
V_7 -> V_44 . V_114 = true ;
F_52 ( V_7 ) ;
F_43 ( V_7 ) ;
if ( V_115 != 2 && V_71 -> V_116 . V_117 . V_118 ) {
static const T_2 V_81 [] = {
V_119 ,
V_120 ,
V_121 ,
V_122 ,
V_83 ,
V_123 ,
V_124 ,
V_125 ,
V_126 ,
V_82 ,
V_127 ,
} ;
int V_128 ;
for ( V_128 = 0 , V_29 = - V_129 ; V_29 && V_128 < F_53 ( V_81 ) ; V_128 ++ ) {
V_29 = F_54 ( & V_71 -> V_95 . V_130 ,
V_131 , V_81 [ V_128 ] ,
NULL , 0 , & V_28 -> V_28 ) ;
}
if ( V_29 == 0 ) {
F_44 ( V_7 ) ;
if ( V_28 -> V_28 . V_81 < V_82 )
V_29 = F_55 ( V_7 ) ;
else
V_29 = F_56 ( V_7 ) ;
}
} else {
V_29 = 0 ;
}
if ( V_29 )
goto V_132;
if ( V_7 -> V_44 . V_45 ) {
V_29 = F_21 ( V_7 ) ;
if ( V_29 )
goto V_133;
}
F_57 ( V_7 ) ;
return 0 ;
V_133:
V_28 -> V_134 ( V_7 ) ;
V_132:
F_58 ( V_7 ) ;
F_59 ( V_7 ) ;
return V_29 ;
}
void
F_60 ( struct V_10 * V_7 )
{
struct V_27 * V_28 = V_27 ( V_7 ) ;
F_61 ( V_7 ) ;
F_18 ( V_7 ) ;
F_58 ( V_7 ) ;
F_59 ( V_7 ) ;
if ( V_28 -> V_134 )
V_28 -> V_134 ( V_7 ) ;
F_62 ( & V_28 -> V_28 ) ;
V_70 ( V_7 ) -> V_96 = NULL ;
F_27 ( V_28 ) ;
}
int
F_63 ( struct V_10 * V_7 , bool V_135 )
{
struct V_12 * V_13 ;
F_41 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_48 * V_62 ;
V_62 = V_48 ( V_13 -> V_136 -> V_49 ) ;
if ( ! V_62 || ! V_62 -> V_51 )
continue;
F_64 ( V_62 -> V_51 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( V_4 -> V_137 . V_51 ) {
if ( V_4 -> V_137 . V_138 )
F_65 ( V_4 -> V_137 . V_51 ) ;
F_64 ( V_4 -> V_137 . V_51 ) ;
}
}
return 0 ;
}
void
F_66 ( struct V_10 * V_7 , bool V_135 )
{
struct V_70 * V_71 = V_70 ( V_7 ) ;
struct V_12 * V_13 ;
int V_29 , V_11 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_48 * V_62 ;
V_62 = V_48 ( V_13 -> V_136 -> V_49 ) ;
if ( ! V_62 || ! V_62 -> V_51 )
continue;
V_29 = F_67 ( V_62 -> V_51 , V_139 , true ) ;
if ( V_29 )
F_68 ( V_71 , L_8 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( ! V_4 -> V_137 . V_51 )
continue;
V_29 = F_67 ( V_4 -> V_137 . V_51 , V_139 , true ) ;
if ( ! V_29 && V_4 -> V_137 . V_138 )
V_29 = F_69 ( V_4 -> V_137 . V_51 ) ;
if ( V_29 )
F_68 ( V_71 , L_9 ) ;
}
F_39 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
V_4 -> V_140 . V_141 = 0 ;
}
for ( V_11 = 0 ; V_11 < V_7 -> V_44 . V_45 ; V_11 ++ )
F_70 ( V_7 , V_11 ) ;
if ( V_135 )
return;
F_71 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( ! V_4 -> V_137 . V_51 )
continue;
if ( V_4 -> V_137 . V_138 )
V_4 -> V_137 . V_138 ( V_4 , V_4 -> V_137 . V_51 -> V_142 . V_143 ) ;
V_4 -> V_137 . V_144 ( V_4 , V_4 -> V_145 ,
V_4 -> V_146 ) ;
}
}
static int
F_72 ( struct V_147 * V_148 ,
struct V_59 * V_149 ,
struct V_59 * V_150 ,
struct V_151 * V_152 ,
struct V_153 * * V_154 )
{
struct V_155 * V_156 = V_148 -> V_157 ;
struct V_70 * V_71 = V_148 -> V_71 ;
struct V_10 * V_7 = V_71 -> V_7 ;
unsigned long V_40 ;
int V_29 ;
F_73 ( & V_7 -> V_158 , V_40 ) ;
F_74 ( & V_152 -> V_11 , & V_156 -> V_78 ) ;
F_75 ( & V_7 -> V_158 , V_40 ) ;
V_29 = F_76 ( V_149 , V_148 , false , false ) ;
if ( V_29 )
goto V_159;
V_29 = F_77 ( V_148 , 2 ) ;
if ( V_29 )
goto V_159;
if ( V_71 -> V_95 . V_104 . V_105 < V_110 )
F_78 ( V_148 , V_160 , V_161 , 1 ) ;
else
F_79 ( V_148 , V_162 , V_161 , 1 ) ;
F_80 ( V_148 , 0x00000000 ) ;
F_81 ( V_148 ) ;
V_29 = F_82 ( V_148 , false , V_154 ) ;
if ( V_29 )
goto V_159;
return 0 ;
V_159:
F_73 ( & V_7 -> V_158 , V_40 ) ;
F_83 ( & V_152 -> V_11 ) ;
F_75 ( & V_7 -> V_158 , V_40 ) ;
return V_29 ;
}
int
F_84 ( struct V_12 * V_13 , struct V_46 * V_49 ,
struct V_163 * V_164 , T_3 V_40 )
{
const int V_165 = ( V_40 & V_166 ) ? 0 : 1 ;
struct V_10 * V_7 = V_13 -> V_7 ;
struct V_70 * V_71 = V_70 ( V_7 ) ;
struct V_59 * V_149 = V_48 ( V_13 -> V_136 -> V_49 ) -> V_51 ;
struct V_59 * V_150 = V_48 ( V_49 ) -> V_51 ;
struct V_151 * V_152 ;
struct V_147 * V_148 ;
struct V_167 * V_168 ;
struct V_153 * V_157 ;
int V_29 ;
V_148 = V_71 -> V_169 ;
if ( ! V_148 )
return - V_129 ;
V_168 = ( void * ) V_148 -> V_170 . V_171 ;
V_152 = F_36 ( sizeof( * V_152 ) , V_67 ) ;
if ( ! V_152 )
return - V_64 ;
if ( V_150 != V_149 ) {
V_29 = F_67 ( V_150 , V_139 , true ) ;
if ( V_29 )
goto V_172;
}
F_85 ( & V_168 -> V_173 ) ;
V_29 = F_86 ( & V_150 -> V_142 , true , false , false , NULL ) ;
if ( V_29 )
goto V_174;
V_29 = F_76 ( V_150 , V_148 , false , true ) ;
if ( V_29 ) {
F_87 ( & V_150 -> V_142 ) ;
goto V_174;
}
if ( V_150 != V_149 ) {
F_87 ( & V_150 -> V_142 ) ;
V_29 = F_86 ( & V_149 -> V_142 , true , false , false , NULL ) ;
if ( V_29 )
goto V_174;
}
* V_152 = (struct V_151 )
{ { } , V_164 , V_3 ( V_13 ) -> V_8 ,
V_49 -> V_175 , V_49 -> V_176 [ 0 ] , V_13 -> V_177 , V_13 -> V_178 ,
V_150 -> V_142 . V_143 } ;
F_88 ( V_7 , V_3 ( V_13 ) -> V_8 ) ;
if ( V_71 -> V_95 . V_104 . V_105 >= V_109 ) {
V_29 = F_89 ( V_13 , V_49 , V_148 , V_165 ) ;
if ( V_29 )
goto V_179;
} else {
struct V_180 * V_181 = V_180 ( V_7 ) ;
int V_11 = V_3 ( V_13 ) -> V_8 ;
if ( V_165 ) {
V_29 = F_77 ( V_148 , 8 ) ;
if ( V_29 )
goto V_179;
F_78 ( V_148 , V_182 , 0x012c , 1 ) ;
F_80 ( V_148 , 0 ) ;
F_78 ( V_148 , V_182 , 0x0134 , 1 ) ;
F_80 ( V_148 , V_11 ) ;
F_78 ( V_148 , V_182 , 0x0100 , 1 ) ;
F_80 ( V_148 , 0 ) ;
F_78 ( V_148 , V_182 , 0x0130 , 1 ) ;
F_80 ( V_148 , 0 ) ;
}
F_90 ( V_150 , & V_181 -> V_183 [ V_11 ] ) ;
}
V_29 = F_72 ( V_148 , V_149 , V_150 , V_152 , & V_157 ) ;
if ( V_29 )
goto V_179;
F_91 ( & V_168 -> V_173 ) ;
V_13 -> V_136 -> V_49 = V_49 ;
F_92 ( V_149 , V_157 , false ) ;
F_87 ( & V_149 -> V_142 ) ;
if ( V_149 != V_150 )
F_64 ( V_149 ) ;
F_93 ( & V_157 ) ;
return 0 ;
V_179:
F_94 ( V_7 , V_3 ( V_13 ) -> V_8 ) ;
F_87 ( & V_149 -> V_142 ) ;
V_174:
F_91 ( & V_168 -> V_173 ) ;
if ( V_149 != V_150 )
F_64 ( V_150 ) ;
V_172:
F_27 ( V_152 ) ;
return V_29 ;
}
int
F_95 ( struct V_147 * V_148 ,
struct V_151 * V_184 )
{
struct V_155 * V_156 = V_148 -> V_157 ;
struct V_70 * V_71 = V_148 -> V_71 ;
struct V_10 * V_7 = V_71 -> V_7 ;
struct V_151 * V_152 ;
unsigned long V_40 ;
int V_185 = - 1 ;
F_73 ( & V_7 -> V_158 , V_40 ) ;
if ( F_96 ( & V_156 -> V_78 ) ) {
F_68 ( V_71 , L_10 ) ;
F_75 ( & V_7 -> V_158 , V_40 ) ;
return - V_14 ;
}
V_152 = F_97 ( & V_156 -> V_78 , struct V_151 , V_11 ) ;
if ( V_152 -> V_164 ) {
if ( V_71 -> V_95 . V_104 . V_105 >= V_109 )
V_185 = V_152 -> V_13 ;
F_98 ( V_7 , V_185 , V_152 -> V_164 ) ;
}
F_94 ( V_7 , V_152 -> V_13 ) ;
F_83 ( & V_152 -> V_11 ) ;
if ( V_184 )
* V_184 = * V_152 ;
F_27 ( V_152 ) ;
F_75 ( & V_7 -> V_158 , V_40 ) ;
return 0 ;
}
int
F_99 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = F_2 ( V_2 , F_3 ( * V_71 ) , V_78 ) ;
struct V_147 * V_148 = V_71 -> V_169 ;
struct V_151 V_186 ;
if ( ! F_95 ( V_148 , & V_186 ) ) {
if ( V_71 -> V_95 . V_104 . V_105 < V_109 ) {
F_100 ( V_71 -> V_7 , V_186 . V_13 , V_186 . V_143 +
V_186 . V_178 * V_186 . V_187 +
V_186 . V_177 * V_186 . V_188 / 8 ) ;
}
}
return V_9 ;
}
int
F_101 ( struct V_53 * V_54 , struct V_10 * V_7 ,
struct V_189 * args )
{
struct V_59 * V_142 ;
T_4 V_190 ;
int V_29 ;
args -> V_187 = F_102 ( args -> V_191 * ( args -> V_188 / 8 ) , 256 ) ;
args -> V_192 = args -> V_187 * args -> V_193 ;
args -> V_192 = F_102 ( args -> V_192 , V_194 ) ;
if ( V_70 ( V_7 ) -> V_95 . V_104 . V_195 != 0 )
V_190 = V_196 ;
else
V_190 = V_197 ;
V_29 = F_103 ( V_7 , args -> V_192 , 0 , V_190 , 0 , 0 , & V_142 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_29 ( V_54 , & V_142 -> V_52 , & args -> V_55 ) ;
F_25 ( & V_142 -> V_52 ) ;
return V_29 ;
}
int
F_104 ( struct V_53 * V_54 ,
struct V_10 * V_7 ,
T_4 V_55 , T_5 * V_198 )
{
struct V_63 * V_52 ;
V_52 = F_34 ( V_7 , V_54 , V_55 ) ;
if ( V_52 ) {
struct V_59 * V_142 = F_37 ( V_52 ) ;
* V_198 = F_105 ( & V_142 -> V_142 . V_199 ) ;
F_25 ( V_52 ) ;
return 0 ;
}
return - V_66 ;
}
