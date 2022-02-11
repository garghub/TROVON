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
V_29 = F_22 (&disp->disp, NULL,
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
struct V_70 * V_71 ;
int V_29 ;
V_29 = V_28 -> V_72 ( V_7 ) ;
if ( V_29 )
return V_29 ;
F_40 ( V_7 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
struct V_73 * V_74 = V_73 ( V_71 ) ;
F_7 ( & V_74 -> V_75 ) ;
}
return V_29 ;
}
void
F_41 ( struct V_10 * V_7 )
{
struct V_27 * V_28 = V_27 ( V_7 ) ;
struct V_70 * V_71 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_44 . V_45 ; V_11 ++ )
F_42 ( V_7 , V_11 ) ;
F_6 (connector, &dev->mode_config.connector_list, head) {
struct V_73 * V_74 = V_73 ( V_71 ) ;
F_9 ( & V_74 -> V_75 ) ;
}
F_43 ( V_7 ) ;
V_28 -> V_76 ( V_7 ) ;
}
static void
F_44 ( struct V_10 * V_7 )
{
struct V_27 * V_28 = V_27 ( V_7 ) ;
int V_77 ;
if ( V_28 -> V_28 . V_78 < V_79 )
V_77 = 0 ;
else
if ( V_28 -> V_28 . V_78 < V_80 )
V_77 = 1 ;
else
V_77 = 2 ;
F_45 ( V_28 -> V_81 , V_77 , L_1 , V_82 ) ;
F_45 ( V_28 -> V_83 , V_77 , L_2 , V_84 ) ;
F_45 ( V_28 -> V_85 , V_77 , L_3 , V_86 ) ;
V_28 -> V_87 =
F_46 ( V_7 , 0 , L_4 , 0 , 128 ) ;
V_28 -> V_88 =
F_46 ( V_7 , 0 , L_5 , 0 , 128 ) ;
if ( V_77 < 1 )
return;
V_28 -> V_89 =
F_46 ( V_7 , 0 , L_6 , 0 , 180 ) ;
V_28 -> V_90 =
F_46 ( V_7 , 0 , L_7 , 0 , 200 ) ;
}
int
F_47 ( struct V_10 * V_7 )
{
struct V_91 * V_92 = V_91 ( V_7 ) ;
struct V_27 * V_28 ;
int V_29 ;
V_28 = V_92 -> V_93 = F_36 ( sizeof( * V_28 ) , V_67 ) ;
if ( ! V_28 )
return - V_64 ;
F_48 ( V_7 ) ;
F_49 ( V_7 ) ;
F_50 ( V_7 ) ;
V_7 -> V_44 . V_94 = & V_95 ;
V_7 -> V_44 . V_96 = F_51 ( F_52 ( & V_92 -> V_97 ) , 1 ) ;
V_7 -> V_44 . V_98 = 0 ;
V_7 -> V_44 . V_99 = 0 ;
if ( V_92 -> V_97 . V_100 . V_101 < V_102 ) {
V_7 -> V_44 . V_103 = 2048 ;
V_7 -> V_44 . V_104 = 2048 ;
} else
if ( V_92 -> V_97 . V_100 . V_101 < V_105 ) {
V_7 -> V_44 . V_103 = 4096 ;
V_7 -> V_44 . V_104 = 4096 ;
} else {
V_7 -> V_44 . V_103 = 8192 ;
V_7 -> V_44 . V_104 = 8192 ;
}
V_7 -> V_44 . V_106 = 24 ;
V_7 -> V_44 . V_107 = 1 ;
if ( V_92 -> V_97 . V_100 . V_108 < 0x11 )
V_7 -> V_44 . V_109 = false ;
else
V_7 -> V_44 . V_109 = true ;
F_53 ( V_7 ) ;
F_43 ( V_7 ) ;
if ( V_110 != 2 && V_92 -> V_111 . V_112 . V_113 ) {
static const T_2 V_78 [] = {
V_114 ,
V_115 ,
V_116 ,
V_117 ,
V_80 ,
V_118 ,
V_119 ,
V_120 ,
V_121 ,
V_79 ,
V_122 ,
} ;
int V_123 ;
for ( V_123 = 0 , V_29 = - V_124 ; V_29 && V_123 < F_54 ( V_78 ) ; V_123 ++ ) {
V_29 = F_55 ( F_56 ( & V_92 -> V_97 ) , NULL ,
V_125 , V_78 [ V_123 ] ,
NULL , 0 , & V_28 -> V_28 ) ;
}
if ( V_29 == 0 ) {
F_44 ( V_7 ) ;
if ( V_28 -> V_28 . V_78 < V_79 )
V_29 = F_57 ( V_7 ) ;
else
V_29 = F_58 ( V_7 ) ;
}
} else {
V_29 = 0 ;
}
if ( V_29 )
goto V_126;
if ( V_7 -> V_44 . V_45 ) {
V_29 = F_21 ( V_7 ) ;
if ( V_29 )
goto V_127;
}
F_59 ( V_7 ) ;
return 0 ;
V_127:
V_28 -> V_128 ( V_7 ) ;
V_126:
F_60 ( V_7 ) ;
F_61 ( V_7 ) ;
return V_29 ;
}
void
F_62 ( struct V_10 * V_7 )
{
struct V_27 * V_28 = V_27 ( V_7 ) ;
F_63 ( V_7 ) ;
F_18 ( V_7 ) ;
F_60 ( V_7 ) ;
F_61 ( V_7 ) ;
if ( V_28 -> V_128 )
V_28 -> V_128 ( V_7 ) ;
F_64 ( & V_28 -> V_28 ) ;
V_91 ( V_7 ) -> V_93 = NULL ;
F_27 ( V_28 ) ;
}
int
F_65 ( struct V_10 * V_7 , bool V_129 )
{
struct V_12 * V_13 ;
F_41 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_48 * V_62 ;
V_62 = V_48 ( V_13 -> V_130 -> V_49 ) ;
if ( ! V_62 || ! V_62 -> V_51 )
continue;
F_66 ( V_62 -> V_51 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( V_4 -> V_131 . V_51 ) {
if ( V_4 -> V_131 . V_132 )
F_67 ( V_4 -> V_131 . V_51 ) ;
F_66 ( V_4 -> V_131 . V_51 ) ;
}
}
return 0 ;
}
void
F_68 ( struct V_10 * V_7 , bool V_129 )
{
struct V_91 * V_92 = V_91 ( V_7 ) ;
struct V_12 * V_13 ;
int V_29 , V_11 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_48 * V_62 ;
V_62 = V_48 ( V_13 -> V_130 -> V_49 ) ;
if ( ! V_62 || ! V_62 -> V_51 )
continue;
V_29 = F_69 ( V_62 -> V_51 , V_133 , true ) ;
if ( V_29 )
F_70 ( V_92 , L_8 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( ! V_4 -> V_131 . V_51 )
continue;
V_29 = F_69 ( V_4 -> V_131 . V_51 , V_133 , true ) ;
if ( ! V_29 && V_4 -> V_131 . V_132 )
V_29 = F_71 ( V_4 -> V_131 . V_51 ) ;
if ( V_29 )
F_70 ( V_92 , L_9 ) ;
}
F_39 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
V_4 -> V_134 . V_135 = 0 ;
}
for ( V_11 = 0 ; V_11 < V_7 -> V_44 . V_45 ; V_11 ++ )
F_72 ( V_7 , V_11 ) ;
if ( V_129 )
return;
F_73 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
if ( ! V_4 -> V_131 . V_51 )
continue;
if ( V_4 -> V_131 . V_132 )
V_4 -> V_131 . V_132 ( V_4 , V_4 -> V_131 . V_51 -> V_136 . V_137 ) ;
V_4 -> V_131 . V_138 ( V_4 , V_4 -> V_139 ,
V_4 -> V_140 ) ;
}
}
static int
F_74 ( struct V_141 * V_142 ,
struct V_59 * V_143 ,
struct V_59 * V_144 ,
struct V_145 * V_146 ,
struct V_147 * * V_148 )
{
struct V_149 * V_150 = V_142 -> V_151 ;
struct V_91 * V_92 = V_142 -> V_92 ;
struct V_10 * V_7 = V_92 -> V_7 ;
unsigned long V_40 ;
int V_29 ;
F_75 ( & V_7 -> V_152 , V_40 ) ;
F_76 ( & V_146 -> V_11 , & V_150 -> V_153 ) ;
F_77 ( & V_7 -> V_152 , V_40 ) ;
V_29 = F_78 ( V_143 , V_142 , false , false ) ;
if ( V_29 )
goto V_154;
V_29 = F_79 ( V_142 , 2 ) ;
if ( V_29 )
goto V_154;
if ( V_92 -> V_97 . V_100 . V_101 < V_155 )
F_80 ( V_142 , V_156 , V_157 , 1 ) ;
else
F_81 ( V_142 , V_158 , V_157 , 1 ) ;
F_82 ( V_142 , 0x00000000 ) ;
F_83 ( V_142 ) ;
V_29 = F_84 ( V_142 , false , V_148 ) ;
if ( V_29 )
goto V_154;
return 0 ;
V_154:
F_75 ( & V_7 -> V_152 , V_40 ) ;
F_85 ( & V_146 -> V_11 ) ;
F_77 ( & V_7 -> V_152 , V_40 ) ;
return V_29 ;
}
int
F_86 ( struct V_12 * V_13 , struct V_46 * V_49 ,
struct V_159 * V_160 , T_3 V_40 )
{
const int V_161 = ( V_40 & V_162 ) ? 0 : 1 ;
struct V_10 * V_7 = V_13 -> V_7 ;
struct V_91 * V_92 = V_91 ( V_7 ) ;
struct V_59 * V_143 = V_48 ( V_13 -> V_130 -> V_49 ) -> V_51 ;
struct V_59 * V_144 = V_48 ( V_49 ) -> V_51 ;
struct V_145 * V_146 ;
struct V_141 * V_142 ;
struct V_163 * V_164 ;
struct V_147 * V_151 ;
int V_29 ;
V_142 = V_92 -> V_165 ;
if ( ! V_142 )
return - V_124 ;
V_164 = ( void * ) F_87 ( & V_142 -> V_97 -> V_6 ) ;
V_146 = F_36 ( sizeof( * V_146 ) , V_67 ) ;
if ( ! V_146 )
return - V_64 ;
if ( V_144 != V_143 ) {
V_29 = F_69 ( V_144 , V_133 , true ) ;
if ( V_29 )
goto V_166;
}
F_88 ( & V_164 -> V_167 ) ;
V_29 = F_89 ( & V_144 -> V_136 , true , false , false , NULL ) ;
if ( V_29 )
goto V_168;
V_29 = F_78 ( V_144 , V_142 , false , true ) ;
if ( V_29 ) {
F_90 ( & V_144 -> V_136 ) ;
goto V_168;
}
if ( V_144 != V_143 ) {
F_90 ( & V_144 -> V_136 ) ;
V_29 = F_89 ( & V_143 -> V_136 , true , false , false , NULL ) ;
if ( V_29 )
goto V_168;
}
* V_146 = (struct V_145 )
{ { } , V_160 , V_3 ( V_13 ) -> V_8 ,
V_49 -> V_169 , V_49 -> V_170 [ 0 ] , V_13 -> V_171 , V_13 -> V_172 ,
V_144 -> V_136 . V_137 } ;
F_91 ( V_7 , V_3 ( V_13 ) -> V_8 ) ;
if ( V_92 -> V_97 . V_100 . V_101 >= V_105 ) {
V_29 = F_92 ( V_13 , V_49 , V_142 , V_161 ) ;
if ( V_29 )
goto V_173;
} else {
struct V_174 * V_175 = V_174 ( V_7 ) ;
int V_11 = V_3 ( V_13 ) -> V_8 ;
if ( V_161 ) {
V_29 = F_79 ( V_142 , 8 ) ;
if ( V_29 )
goto V_173;
F_80 ( V_142 , V_176 , 0x012c , 1 ) ;
F_82 ( V_142 , 0 ) ;
F_80 ( V_142 , V_176 , 0x0134 , 1 ) ;
F_82 ( V_142 , V_11 ) ;
F_80 ( V_142 , V_176 , 0x0100 , 1 ) ;
F_82 ( V_142 , 0 ) ;
F_80 ( V_142 , V_176 , 0x0130 , 1 ) ;
F_82 ( V_142 , 0 ) ;
}
F_93 ( V_144 , & V_175 -> V_177 [ V_11 ] ) ;
}
V_29 = F_74 ( V_142 , V_143 , V_144 , V_146 , & V_151 ) ;
if ( V_29 )
goto V_173;
F_94 ( & V_164 -> V_167 ) ;
V_13 -> V_130 -> V_49 = V_49 ;
F_95 ( V_143 , V_151 , false ) ;
F_90 ( & V_143 -> V_136 ) ;
if ( V_143 != V_144 )
F_66 ( V_143 ) ;
F_96 ( & V_151 ) ;
return 0 ;
V_173:
F_97 ( V_7 , V_3 ( V_13 ) -> V_8 ) ;
F_90 ( & V_143 -> V_136 ) ;
V_168:
F_94 ( & V_164 -> V_167 ) ;
if ( V_143 != V_144 )
F_66 ( V_144 ) ;
V_166:
F_27 ( V_146 ) ;
return V_29 ;
}
int
F_98 ( struct V_141 * V_142 ,
struct V_145 * V_178 )
{
struct V_149 * V_150 = V_142 -> V_151 ;
struct V_91 * V_92 = V_142 -> V_92 ;
struct V_10 * V_7 = V_92 -> V_7 ;
struct V_145 * V_146 ;
unsigned long V_40 ;
int V_179 = - 1 ;
F_75 ( & V_7 -> V_152 , V_40 ) ;
if ( F_99 ( & V_150 -> V_153 ) ) {
F_70 ( V_92 , L_10 ) ;
F_77 ( & V_7 -> V_152 , V_40 ) ;
return - V_14 ;
}
V_146 = F_100 ( & V_150 -> V_153 , struct V_145 , V_11 ) ;
if ( V_146 -> V_160 ) {
if ( V_92 -> V_97 . V_100 . V_101 >= V_105 )
V_179 = V_146 -> V_13 ;
F_101 ( V_7 , V_179 , V_146 -> V_160 ) ;
}
F_97 ( V_7 , V_146 -> V_13 ) ;
F_85 ( & V_146 -> V_11 ) ;
if ( V_178 )
* V_178 = * V_146 ;
F_27 ( V_146 ) ;
F_77 ( & V_7 -> V_152 , V_40 ) ;
return 0 ;
}
int
F_102 ( void * V_180 )
{
struct V_141 * V_142 = V_180 ;
struct V_91 * V_92 = V_142 -> V_92 ;
struct V_145 V_181 ;
if ( ! F_98 ( V_142 , & V_181 ) ) {
if ( V_92 -> V_97 . V_100 . V_101 < V_105 ) {
F_103 ( V_92 -> V_7 , V_181 . V_13 , V_181 . V_137 +
V_181 . V_172 * V_181 . V_182 +
V_181 . V_171 * V_181 . V_183 / 8 ) ;
}
}
return 0 ;
}
int
F_104 ( struct V_53 * V_54 , struct V_10 * V_7 ,
struct V_184 * args )
{
struct V_59 * V_136 ;
int V_29 ;
args -> V_182 = F_105 ( args -> V_185 * ( args -> V_183 / 8 ) , 256 ) ;
args -> V_186 = args -> V_182 * args -> V_187 ;
args -> V_186 = F_105 ( args -> V_186 , V_188 ) ;
V_29 = F_106 ( V_7 , args -> V_186 , 0 , V_189 , 0 , 0 , & V_136 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_29 ( V_54 , & V_136 -> V_52 , & args -> V_55 ) ;
F_25 ( & V_136 -> V_52 ) ;
return V_29 ;
}
int
F_107 ( struct V_53 * V_54 ,
struct V_10 * V_7 ,
T_4 V_55 , T_5 * V_190 )
{
struct V_63 * V_52 ;
V_52 = F_34 ( V_7 , V_54 , V_55 ) ;
if ( V_52 ) {
struct V_59 * V_136 = F_37 ( V_52 ) ;
* V_190 = F_108 ( & V_136 -> V_136 . V_191 ) ;
F_25 ( V_52 ) ;
return 0 ;
}
return - V_66 ;
}
