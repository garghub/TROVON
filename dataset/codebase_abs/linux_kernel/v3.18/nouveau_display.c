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
V_80 ,
V_117 ,
V_118 ,
V_119 ,
V_120 ,
V_79 ,
V_121 ,
} ;
int V_122 ;
for ( V_122 = 0 , V_29 = - V_123 ; V_29 && V_122 < F_54 ( V_78 ) ; V_122 ++ ) {
V_29 = F_55 ( F_56 ( & V_92 -> V_97 ) , NULL ,
V_124 , V_78 [ V_122 ] ,
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
goto V_125;
if ( V_7 -> V_44 . V_45 ) {
V_29 = F_21 ( V_7 ) ;
if ( V_29 )
goto V_126;
}
F_59 ( V_7 ) ;
return 0 ;
V_126:
V_28 -> V_127 ( V_7 ) ;
V_125:
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
if ( V_28 -> V_127 )
V_28 -> V_127 ( V_7 ) ;
F_64 ( & V_28 -> V_28 ) ;
V_91 ( V_7 ) -> V_93 = NULL ;
F_27 ( V_28 ) ;
}
int
F_65 ( struct V_10 * V_7 , bool V_128 )
{
struct V_12 * V_13 ;
F_41 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_48 * V_62 ;
V_62 = V_48 ( V_13 -> V_129 -> V_49 ) ;
if ( ! V_62 || ! V_62 -> V_51 )
continue;
F_66 ( V_62 -> V_51 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
F_67 ( V_4 -> V_130 . V_51 ) ;
F_66 ( V_4 -> V_130 . V_51 ) ;
}
return 0 ;
}
void
F_68 ( struct V_10 * V_7 , bool V_128 )
{
struct V_91 * V_92 = V_91 ( V_7 ) ;
struct V_12 * V_13 ;
int V_29 , V_11 ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_48 * V_62 ;
V_62 = V_48 ( V_13 -> V_129 -> V_49 ) ;
if ( ! V_62 || ! V_62 -> V_51 )
continue;
V_29 = F_69 ( V_62 -> V_51 , V_131 ) ;
if ( V_29 )
F_70 ( V_92 , L_8 ) ;
}
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
V_29 = F_69 ( V_4 -> V_130 . V_51 , V_131 ) ;
if ( ! V_29 )
V_29 = F_71 ( V_4 -> V_130 . V_51 ) ;
if ( V_29 )
F_70 ( V_92 , L_9 ) ;
}
F_39 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
V_4 -> V_132 . V_133 = 0 ;
}
for ( V_11 = 0 ; V_11 < V_7 -> V_44 . V_45 ; V_11 ++ )
F_72 ( V_7 , V_11 ) ;
if ( V_128 )
return;
F_73 ( V_7 ) ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_4 = V_3 ( V_13 ) ;
T_3 V_134 = V_4 -> V_130 . V_51 -> V_135 . V_134 ;
V_4 -> V_130 . V_136 ( V_4 , V_134 ) ;
V_4 -> V_130 . V_137 ( V_4 , V_4 -> V_138 ,
V_4 -> V_139 ) ;
}
}
static int
F_74 ( struct V_140 * V_141 ,
struct V_59 * V_142 ,
struct V_59 * V_143 ,
struct V_144 * V_145 ,
struct V_146 * * V_147 )
{
struct V_148 * V_149 = V_141 -> V_150 ;
struct V_91 * V_92 = V_141 -> V_92 ;
struct V_10 * V_7 = V_92 -> V_7 ;
unsigned long V_40 ;
int V_29 ;
F_75 ( & V_7 -> V_151 , V_40 ) ;
F_76 ( & V_145 -> V_11 , & V_149 -> V_152 ) ;
F_77 ( & V_7 -> V_151 , V_40 ) ;
V_29 = F_78 ( V_142 , V_141 , false , false ) ;
if ( V_29 )
goto V_153;
V_29 = F_79 ( V_141 , 2 ) ;
if ( V_29 )
goto V_153;
if ( V_92 -> V_97 . V_100 . V_101 < V_154 )
F_80 ( V_141 , V_155 , V_156 , 1 ) ;
else
F_81 ( V_141 , V_157 , V_156 , 1 ) ;
F_82 ( V_141 , 0x00000000 ) ;
F_83 ( V_141 ) ;
V_29 = F_84 ( V_141 , false , V_147 ) ;
if ( V_29 )
goto V_153;
return 0 ;
V_153:
F_75 ( & V_7 -> V_151 , V_40 ) ;
F_85 ( & V_145 -> V_11 ) ;
F_77 ( & V_7 -> V_151 , V_40 ) ;
return V_29 ;
}
int
F_86 ( struct V_12 * V_13 , struct V_46 * V_49 ,
struct V_158 * V_159 , T_3 V_40 )
{
const int V_160 = ( V_40 & V_161 ) ? 0 : 1 ;
struct V_10 * V_7 = V_13 -> V_7 ;
struct V_91 * V_92 = V_91 ( V_7 ) ;
struct V_59 * V_142 = V_48 ( V_13 -> V_129 -> V_49 ) -> V_51 ;
struct V_59 * V_143 = V_48 ( V_49 ) -> V_51 ;
struct V_144 * V_145 ;
struct V_140 * V_141 ;
struct V_162 * V_163 ;
struct V_146 * V_150 ;
int V_29 ;
V_141 = V_92 -> V_164 ;
if ( ! V_141 )
return - V_123 ;
V_163 = ( void * ) F_87 ( & V_141 -> V_97 -> V_6 ) ;
V_145 = F_36 ( sizeof( * V_145 ) , V_67 ) ;
if ( ! V_145 )
return - V_64 ;
if ( V_143 != V_142 ) {
V_29 = F_69 ( V_143 , V_131 ) ;
if ( V_29 )
goto V_165;
}
F_88 ( & V_163 -> V_166 ) ;
V_29 = F_89 ( & V_143 -> V_135 , true , false , false , NULL ) ;
if ( V_29 )
goto V_167;
V_29 = F_78 ( V_143 , V_141 , false , true ) ;
if ( V_29 ) {
F_90 ( & V_143 -> V_135 ) ;
goto V_167;
}
if ( V_143 != V_142 ) {
F_90 ( & V_143 -> V_135 ) ;
V_29 = F_89 ( & V_142 -> V_135 , true , false , false , NULL ) ;
if ( V_29 )
goto V_167;
}
* V_145 = (struct V_144 )
{ { } , V_159 , V_3 ( V_13 ) -> V_8 ,
V_49 -> V_168 , V_49 -> V_169 [ 0 ] , V_13 -> V_170 , V_13 -> V_171 ,
V_143 -> V_135 . V_134 } ;
F_91 ( V_7 , V_3 ( V_13 ) -> V_8 ) ;
if ( V_92 -> V_97 . V_100 . V_101 >= V_105 ) {
V_29 = F_92 ( V_13 , V_49 , V_141 , V_160 ) ;
if ( V_29 )
goto V_172;
} else {
struct V_173 * V_174 = V_173 ( V_7 ) ;
int V_11 = V_3 ( V_13 ) -> V_8 ;
if ( V_160 ) {
V_29 = F_79 ( V_141 , 8 ) ;
if ( V_29 )
goto V_172;
F_80 ( V_141 , V_175 , 0x012c , 1 ) ;
F_82 ( V_141 , 0 ) ;
F_80 ( V_141 , V_175 , 0x0134 , 1 ) ;
F_82 ( V_141 , V_11 ) ;
F_80 ( V_141 , V_175 , 0x0100 , 1 ) ;
F_82 ( V_141 , 0 ) ;
F_80 ( V_141 , V_175 , 0x0130 , 1 ) ;
F_82 ( V_141 , 0 ) ;
}
F_93 ( V_143 , & V_174 -> V_176 [ V_11 ] ) ;
}
V_29 = F_74 ( V_141 , V_142 , V_143 , V_145 , & V_150 ) ;
if ( V_29 )
goto V_172;
F_94 ( & V_163 -> V_166 ) ;
V_13 -> V_129 -> V_49 = V_49 ;
F_95 ( V_142 , V_150 , false ) ;
F_90 ( & V_142 -> V_135 ) ;
if ( V_142 != V_143 )
F_66 ( V_142 ) ;
F_96 ( & V_150 ) ;
return 0 ;
V_172:
F_97 ( V_7 , V_3 ( V_13 ) -> V_8 ) ;
F_90 ( & V_142 -> V_135 ) ;
V_167:
F_94 ( & V_163 -> V_166 ) ;
if ( V_142 != V_143 )
F_66 ( V_143 ) ;
V_165:
F_27 ( V_145 ) ;
return V_29 ;
}
int
F_98 ( struct V_140 * V_141 ,
struct V_144 * V_177 )
{
struct V_148 * V_149 = V_141 -> V_150 ;
struct V_91 * V_92 = V_141 -> V_92 ;
struct V_10 * V_7 = V_92 -> V_7 ;
struct V_144 * V_145 ;
unsigned long V_40 ;
int V_178 = - 1 ;
F_75 ( & V_7 -> V_151 , V_40 ) ;
if ( F_99 ( & V_149 -> V_152 ) ) {
F_70 ( V_92 , L_10 ) ;
F_77 ( & V_7 -> V_151 , V_40 ) ;
return - V_14 ;
}
V_145 = F_100 ( & V_149 -> V_152 , struct V_144 , V_11 ) ;
if ( V_145 -> V_159 ) {
if ( V_92 -> V_97 . V_100 . V_101 >= V_105 )
V_178 = V_145 -> V_13 ;
F_101 ( V_7 , V_178 , V_145 -> V_159 ) ;
}
F_97 ( V_7 , V_145 -> V_13 ) ;
F_85 ( & V_145 -> V_11 ) ;
if ( V_177 )
* V_177 = * V_145 ;
F_27 ( V_145 ) ;
F_77 ( & V_7 -> V_151 , V_40 ) ;
return 0 ;
}
int
F_102 ( void * V_179 )
{
struct V_140 * V_141 = V_179 ;
struct V_91 * V_92 = V_141 -> V_92 ;
struct V_144 V_180 ;
if ( ! F_98 ( V_141 , & V_180 ) ) {
if ( V_92 -> V_97 . V_100 . V_101 < V_105 ) {
F_103 ( V_92 -> V_7 , V_180 . V_13 , V_180 . V_134 +
V_180 . V_171 * V_180 . V_181 +
V_180 . V_170 * V_180 . V_182 / 8 ) ;
}
}
return 0 ;
}
int
F_104 ( struct V_53 * V_54 , struct V_10 * V_7 ,
struct V_183 * args )
{
struct V_59 * V_135 ;
int V_29 ;
args -> V_181 = F_105 ( args -> V_184 * ( args -> V_182 / 8 ) , 256 ) ;
args -> V_185 = args -> V_181 * args -> V_186 ;
args -> V_185 = F_105 ( args -> V_185 , V_187 ) ;
V_29 = F_106 ( V_7 , args -> V_185 , 0 , V_188 , 0 , 0 , & V_135 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_29 ( V_54 , & V_135 -> V_52 , & args -> V_55 ) ;
F_25 ( & V_135 -> V_52 ) ;
return V_29 ;
}
int
F_107 ( struct V_53 * V_54 ,
struct V_10 * V_7 ,
T_4 V_55 , T_5 * V_189 )
{
struct V_63 * V_52 ;
V_52 = F_34 ( V_7 , V_54 , V_55 ) ;
if ( V_52 ) {
struct V_59 * V_135 = F_37 ( V_52 ) ;
* V_189 = F_108 ( & V_135 -> V_135 . V_190 ) ;
F_25 ( V_52 ) ;
return 0 ;
}
return - V_66 ;
}
