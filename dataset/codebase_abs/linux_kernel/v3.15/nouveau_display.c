static int
F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( V_4 -> V_5 , V_2 ) ;
return V_6 ;
}
int
F_3 ( struct V_7 * V_5 , int V_2 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
if ( V_9 ) {
F_4 ( V_9 -> V_10 [ V_2 ] ) ;
return 0 ;
}
return - V_11 ;
}
void
F_5 ( struct V_7 * V_5 , int V_2 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
if ( V_9 )
F_6 ( V_9 -> V_10 [ V_2 ] ) ;
}
static inline int
F_7 ( int V_12 , int V_13 , int V_14 , int line )
{
if ( V_13 >= V_12 ) {
if ( line >= V_12 )
line -= V_14 ;
} else {
if ( line >= V_12 )
line -= V_14 ;
line -= V_13 + 1 ;
}
return line ;
}
int
F_8 ( struct V_15 * V_16 , int * V_17 , int * V_18 ,
T_1 * V_19 , T_1 * V_20 )
{
const T_2 V_21 = V_22 + F_9 ( V_16 ) -> V_23 ;
struct V_8 * V_9 = V_8 ( V_16 -> V_5 ) ;
struct V_24 args ;
int V_25 , V_26 = 1 ;
do {
V_25 = F_10 ( V_9 -> V_27 , V_21 , & args , sizeof( args ) ) ;
if ( V_25 != 0 )
return 0 ;
if ( args . V_28 ) {
V_25 |= V_29 ;
V_25 |= V_30 ;
break;
}
if ( V_26 ) F_11 ( V_16 -> V_31 ) ;
} while ( V_26 -- );
* V_18 = args . V_32 ;
* V_17 = F_7 ( args . V_33 , args . V_34 , args . V_35 , args . V_28 ) ;
if ( V_19 ) * V_19 = F_12 ( args . time [ 0 ] ) ;
if ( V_20 ) * V_20 = F_12 ( args . time [ 1 ] ) ;
if ( * V_17 < 0 )
V_25 |= V_36 ;
return V_25 ;
}
int
F_13 ( struct V_7 * V_5 , int V_2 , unsigned int V_37 ,
int * V_17 , int * V_18 , T_1 * V_19 , T_1 * V_20 )
{
struct V_15 * V_16 ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( F_9 ( V_16 ) -> V_23 == V_2 ) {
return F_8 ( V_16 , V_17 , V_18 ,
V_19 , V_20 ) ;
}
}
return 0 ;
}
int
F_15 ( struct V_7 * V_5 , int V_2 , int * V_38 ,
struct V_39 * time , unsigned V_37 )
{
struct V_15 * V_16 ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( F_9 ( V_16 ) -> V_23 == V_2 ) {
return F_16 ( V_5 ,
V_2 , V_38 , time , V_37 , V_16 ,
& V_16 -> V_40 ) ;
}
}
return - V_41 ;
}
static void
F_17 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
int V_42 ;
F_18 ( V_5 ) ;
if ( V_9 -> V_10 ) {
for ( V_42 = 0 ; V_42 < V_5 -> V_43 . V_44 ; V_42 ++ )
F_19 ( NULL , & V_9 -> V_10 [ V_42 ] ) ;
F_20 ( V_9 -> V_10 ) ;
V_9 -> V_10 = NULL ;
}
}
static int
F_21 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_45 * V_46 = V_45 ( V_4 -> V_47 ) ;
int V_25 , V_42 ;
V_9 -> V_10 = F_22 ( V_5 -> V_43 . V_44 *
sizeof( * V_9 -> V_10 ) , V_48 ) ;
if ( ! V_9 -> V_10 )
return - V_49 ;
for ( V_42 = 0 ; V_42 < V_5 -> V_43 . V_44 ; V_42 ++ ) {
V_25 = F_23 ( V_46 -> V_10 , V_42 ,
F_1 ,
V_4 , & V_9 -> V_10 [ V_42 ] ) ;
if ( V_25 ) {
F_17 ( V_5 ) ;
return V_25 ;
}
}
V_25 = F_24 ( V_5 , V_5 -> V_43 . V_44 ) ;
if ( V_25 ) {
F_17 ( V_5 ) ;
return V_25 ;
}
return 0 ;
}
static void
F_25 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_52 ( V_51 ) ;
if ( V_53 -> V_54 )
F_26 ( & V_53 -> V_54 -> V_55 ) ;
F_27 ( V_51 ) ;
F_20 ( V_53 ) ;
}
static int
F_28 ( struct V_50 * V_51 ,
struct V_56 * V_57 ,
unsigned int * V_58 )
{
struct V_52 * V_53 = V_52 ( V_51 ) ;
return F_29 ( V_57 , & V_53 -> V_54 -> V_55 , V_58 ) ;
}
int
F_30 ( struct V_7 * V_5 ,
struct V_52 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_54 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_50 * V_53 = & V_59 -> V_63 ;
int V_25 ;
F_31 ( V_53 , V_61 ) ;
V_59 -> V_54 = V_54 ;
if ( F_32 ( V_4 -> V_47 ) -> V_64 >= V_65 ) {
T_2 V_66 = F_33 ( V_54 ) ;
if ( V_66 == 0x7a00 ||
V_66 == 0xfe00 )
V_59 -> V_67 = V_68 ;
else
if ( V_66 == 0x7000 )
V_59 -> V_67 = V_69 ;
else
V_59 -> V_67 = V_70 ;
switch ( V_53 -> V_71 ) {
case 8 : V_59 -> V_72 = 0x1e00 ; break;
case 15 : V_59 -> V_72 = 0xe900 ; break;
case 16 : V_59 -> V_72 = 0xe800 ; break;
case 24 :
case 32 : V_59 -> V_72 = 0xcf00 ; break;
case 30 : V_59 -> V_72 = 0xd100 ; break;
default:
F_34 ( V_4 , L_1 , V_53 -> V_71 ) ;
return - V_41 ;
}
if ( V_54 -> V_66 & V_73 ) {
F_34 ( V_4 , L_2 ) ;
return - V_41 ;
}
if ( F_32 ( V_4 -> V_47 ) -> V_74 == 0x50 )
V_59 -> V_72 |= ( V_66 << 8 ) ;
if ( ! V_66 ) {
if ( F_32 ( V_4 -> V_47 ) -> V_64 < V_75 )
V_59 -> V_76 = 0x00100000 | V_53 -> V_77 [ 0 ] ;
else
V_59 -> V_76 = 0x01000000 | V_53 -> V_77 [ 0 ] ;
} else {
T_2 V_78 = V_54 -> V_79 ;
if ( F_32 ( V_4 -> V_47 ) -> V_64 >= V_80 )
V_78 >>= 4 ;
V_59 -> V_76 = ( ( V_53 -> V_77 [ 0 ] / 4 ) << 4 ) | V_78 ;
}
}
V_25 = F_35 ( V_5 , V_53 , & V_81 ) ;
if ( V_25 ) {
return V_25 ;
}
return 0 ;
}
static struct V_50 *
F_36 ( struct V_7 * V_5 ,
struct V_56 * V_57 ,
struct V_60 * V_61 )
{
struct V_52 * V_82 ;
struct V_83 * V_55 ;
int V_25 = - V_49 ;
V_55 = F_37 ( V_5 , V_57 , V_61 -> V_84 [ 0 ] ) ;
if ( ! V_55 )
return F_38 ( - V_85 ) ;
V_82 = F_22 ( sizeof( struct V_52 ) , V_48 ) ;
if ( ! V_82 )
goto V_86;
V_25 = F_30 ( V_5 , V_82 , V_61 , F_39 ( V_55 ) ) ;
if ( V_25 )
goto V_87;
return & V_82 -> V_63 ;
V_87:
F_20 ( V_82 ) ;
V_86:
F_40 ( V_55 ) ;
return F_38 ( V_25 ) ;
}
int
F_41 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_88 * V_89 ;
int V_25 ;
V_25 = V_9 -> V_90 ( V_5 ) ;
if ( V_25 )
return V_25 ;
F_42 ( V_5 ) ;
F_14 (connector, &dev->mode_config.connector_list, head) {
struct V_91 * V_92 = V_91 ( V_89 ) ;
if ( V_92 -> V_93 ) F_4 ( V_92 -> V_93 ) ;
}
return V_25 ;
}
void
F_43 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_88 * V_89 ;
F_14 (connector, &dev->mode_config.connector_list, head) {
struct V_91 * V_92 = V_91 ( V_89 ) ;
if ( V_92 -> V_93 ) F_6 ( V_92 -> V_93 ) ;
}
F_44 ( V_5 ) ;
V_9 -> V_94 ( V_5 ) ;
}
int
F_45 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_95 * V_47 = F_46 ( V_5 ) ;
struct V_8 * V_9 ;
int V_25 , V_96 ;
V_9 = V_4 -> V_97 = F_22 ( sizeof( * V_9 ) , V_48 ) ;
if ( ! V_9 )
return - V_49 ;
F_47 ( V_5 ) ;
F_48 ( V_5 ) ;
F_49 ( V_5 ) ;
if ( F_32 ( V_4 -> V_47 ) -> V_64 < V_65 )
V_96 = 0 ;
else
if ( F_32 ( V_4 -> V_47 ) -> V_64 < V_75 )
V_96 = 1 ;
else
V_96 = 2 ;
F_50 ( V_9 -> V_98 , V_96 , L_3 , V_99 ) ;
F_50 ( V_9 -> V_100 , V_96 , L_4 , V_101 ) ;
F_50 ( V_9 -> V_102 , V_96 , L_5 , V_103 ) ;
V_9 -> V_104 =
F_51 ( V_5 , 0 , L_6 , 0 , 128 ) ;
V_9 -> V_105 =
F_51 ( V_5 , 0 , L_7 , 0 , 128 ) ;
if ( V_96 >= 1 ) {
V_9 -> V_106 =
F_51 ( V_5 , 0 , L_8 , 0 , 180 ) ;
V_9 -> V_107 =
F_51 ( V_5 , 0 , L_9 , 0 , 200 ) ;
}
V_5 -> V_43 . V_108 = & V_109 ;
V_5 -> V_43 . V_110 = F_52 ( V_47 , 1 ) ;
V_5 -> V_43 . V_111 = 0 ;
V_5 -> V_43 . V_112 = 0 ;
if ( F_32 ( V_4 -> V_47 ) -> V_64 < V_113 ) {
V_5 -> V_43 . V_114 = 2048 ;
V_5 -> V_43 . V_115 = 2048 ;
} else
if ( F_32 ( V_4 -> V_47 ) -> V_64 < V_65 ) {
V_5 -> V_43 . V_114 = 4096 ;
V_5 -> V_43 . V_115 = 4096 ;
} else {
V_5 -> V_43 . V_114 = 8192 ;
V_5 -> V_43 . V_115 = 8192 ;
}
V_5 -> V_43 . V_116 = 24 ;
V_5 -> V_43 . V_117 = 1 ;
if ( F_32 ( V_4 -> V_47 ) -> V_74 < 0x11 )
V_5 -> V_43 . V_118 = false ;
else
V_5 -> V_43 . V_118 = true ;
F_53 ( V_5 ) ;
F_44 ( V_5 ) ;
if ( V_4 -> V_119 . V_120 . V_121 ) {
static const T_3 V_122 [] = {
V_123 ,
V_124 ,
V_125 ,
V_126 ,
V_127 ,
V_128 ,
V_129 ,
V_130 ,
V_131 ,
V_132 ,
} ;
int V_42 ;
for ( V_42 = 0 , V_25 = - V_133 ; V_25 && V_42 < F_54 ( V_122 ) ; V_42 ++ ) {
V_25 = F_55 ( F_56 ( V_4 ) , V_134 ,
V_135 , V_122 [ V_42 ] ,
NULL , 0 , & V_9 -> V_27 ) ;
}
if ( V_25 == 0 ) {
if ( F_57 ( V_9 -> V_27 ) < V_131 )
V_25 = F_58 ( V_5 ) ;
else
V_25 = F_59 ( V_5 ) ;
}
} else {
V_25 = 0 ;
}
if ( V_25 )
goto V_136;
if ( V_5 -> V_43 . V_44 ) {
V_25 = F_21 ( V_5 ) ;
if ( V_25 )
goto V_137;
}
F_60 ( V_5 ) ;
return 0 ;
V_137:
V_9 -> V_138 ( V_5 ) ;
V_136:
F_61 ( V_5 ) ;
F_62 ( V_5 ) ;
return V_25 ;
}
void
F_63 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_3 * V_4 = V_3 ( V_5 ) ;
F_64 ( V_5 ) ;
F_17 ( V_5 ) ;
F_61 ( V_5 ) ;
F_62 ( V_5 ) ;
if ( V_9 -> V_138 )
V_9 -> V_138 ( V_5 ) ;
F_65 ( F_56 ( V_4 ) , V_134 , V_135 ) ;
V_3 ( V_5 ) -> V_97 = NULL ;
F_20 ( V_9 ) ;
}
int
F_66 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_15 * V_16 ;
F_43 ( V_5 ) ;
F_67 ( V_4 , L_10 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct V_52 * V_82 ;
V_82 = V_52 ( V_16 -> V_139 -> V_53 ) ;
if ( ! V_82 || ! V_82 -> V_54 )
continue;
F_68 ( V_82 -> V_54 ) ;
}
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct F_9 * V_140 = F_9 ( V_16 ) ;
F_69 ( V_140 -> V_141 . V_54 ) ;
F_68 ( V_140 -> V_141 . V_54 ) ;
}
return 0 ;
}
void
F_70 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_15 * V_16 ;
int V_25 ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct V_52 * V_82 ;
V_82 = V_52 ( V_16 -> V_139 -> V_53 ) ;
if ( ! V_82 || ! V_82 -> V_54 )
continue;
F_71 ( V_82 -> V_54 , V_142 ) ;
}
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct F_9 * V_140 = F_9 ( V_16 ) ;
V_25 = F_71 ( V_140 -> V_141 . V_54 , V_142 ) ;
if ( ! V_25 )
V_25 = F_72 ( V_140 -> V_141 . V_54 ) ;
if ( V_25 )
F_34 ( V_4 , L_11 ) ;
}
}
void
F_73 ( struct V_7 * V_5 )
{
struct V_15 * V_16 ;
F_41 ( V_5 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct F_9 * V_140 = F_9 ( V_16 ) ;
V_140 -> V_143 . V_71 = 0 ;
}
F_74 ( V_5 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct F_9 * V_140 = F_9 ( V_16 ) ;
T_2 V_144 = V_140 -> V_141 . V_54 -> V_145 . V_144 ;
V_140 -> V_141 . V_146 ( V_140 , V_144 ) ;
V_140 -> V_141 . V_147 ( V_140 , V_140 -> V_148 ,
V_140 -> V_149 ) ;
}
}
static int
F_75 ( struct V_150 * V_151 ,
struct V_62 * V_152 ,
struct V_62 * V_153 ,
struct V_154 * V_155 ,
struct V_156 * * V_157 )
{
struct V_158 * V_159 = V_151 -> V_160 ;
struct V_3 * V_4 = V_151 -> V_4 ;
struct V_7 * V_5 = V_4 -> V_5 ;
unsigned long V_37 ;
int V_25 ;
F_76 ( & V_5 -> V_161 , V_37 ) ;
F_77 ( & V_155 -> V_2 , & V_159 -> V_162 ) ;
F_78 ( & V_5 -> V_161 , V_37 ) ;
V_25 = F_79 ( V_152 -> V_145 . V_163 , V_151 ) ;
if ( V_25 )
goto V_164;
V_25 = F_80 ( V_151 , 2 ) ;
if ( V_25 )
goto V_164;
if ( F_32 ( V_4 -> V_47 ) -> V_64 < V_80 )
F_81 ( V_151 , V_165 , V_166 , 1 ) ;
else
F_82 ( V_151 , V_167 , V_166 , 1 ) ;
F_83 ( V_151 , 0x00000000 ) ;
F_84 ( V_151 ) ;
V_25 = F_85 ( V_151 , false , V_157 ) ;
if ( V_25 )
goto V_164;
return 0 ;
V_164:
F_76 ( & V_5 -> V_161 , V_37 ) ;
F_86 ( & V_155 -> V_2 ) ;
F_78 ( & V_5 -> V_161 , V_37 ) ;
return V_25 ;
}
int
F_87 ( struct V_15 * V_16 , struct V_50 * V_53 ,
struct V_168 * V_169 , T_2 V_37 )
{
const int V_170 = ( V_37 & V_171 ) ? 0 : 1 ;
struct V_7 * V_5 = V_16 -> V_5 ;
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_62 * V_152 = V_52 ( V_16 -> V_139 -> V_53 ) -> V_54 ;
struct V_62 * V_153 = V_52 ( V_53 ) -> V_54 ;
struct V_154 * V_155 ;
struct V_150 * V_151 = V_4 -> V_172 ;
struct V_156 * V_160 ;
int V_25 ;
if ( ! V_4 -> V_172 )
return - V_133 ;
V_155 = F_22 ( sizeof( * V_155 ) , V_48 ) ;
if ( ! V_155 )
return - V_49 ;
if ( V_153 != V_152 ) {
V_25 = F_71 ( V_153 , V_142 ) ;
if ( V_25 )
goto V_173;
}
F_88 ( & V_151 -> V_174 -> V_175 ) ;
F_89 ( & V_153 -> V_145 . V_176 -> V_177 ) ;
V_160 = F_90 ( V_153 -> V_145 . V_163 ) ;
F_91 ( & V_153 -> V_145 . V_176 -> V_177 ) ;
V_25 = F_79 ( V_160 , V_151 ) ;
F_92 ( & V_160 ) ;
if ( V_25 )
goto V_178;
V_25 = F_93 ( & V_152 -> V_145 , true , false , false , NULL ) ;
if ( V_25 )
goto V_178;
* V_155 = (struct V_154 )
{ { } , V_169 , F_9 ( V_16 ) -> V_23 ,
V_53 -> V_179 , V_53 -> V_77 [ 0 ] , V_16 -> V_180 , V_16 -> V_181 ,
V_153 -> V_145 . V_144 } ;
if ( F_32 ( V_4 -> V_47 ) -> V_64 >= V_65 ) {
V_25 = F_94 ( V_16 , V_53 , V_151 , V_170 ) ;
if ( V_25 )
goto V_182;
} else {
struct V_183 * V_184 = V_183 ( V_5 ) ;
int V_2 = F_9 ( V_16 ) -> V_23 ;
if ( V_170 ) {
V_25 = F_80 ( V_151 , 8 ) ;
if ( V_25 )
goto V_182;
F_81 ( V_151 , V_185 , 0x012c , 1 ) ;
F_83 ( V_151 , 0 ) ;
F_81 ( V_151 , V_185 , 0x0134 , 1 ) ;
F_83 ( V_151 , V_2 ) ;
F_81 ( V_151 , V_185 , 0x0100 , 1 ) ;
F_83 ( V_151 , 0 ) ;
F_81 ( V_151 , V_185 , 0x0130 , 1 ) ;
F_83 ( V_151 , 0 ) ;
}
F_95 ( V_153 , & V_184 -> V_186 [ V_2 ] ) ;
}
V_25 = F_75 ( V_151 , V_152 , V_153 , V_155 , & V_160 ) ;
if ( V_25 )
goto V_182;
F_96 ( & V_151 -> V_174 -> V_175 ) ;
V_16 -> V_139 -> V_53 = V_53 ;
F_97 ( V_152 , V_160 ) ;
F_98 ( & V_152 -> V_145 ) ;
if ( V_152 != V_153 )
F_68 ( V_152 ) ;
F_92 ( & V_160 ) ;
return 0 ;
V_182:
F_98 ( & V_152 -> V_145 ) ;
V_178:
F_96 ( & V_151 -> V_174 -> V_175 ) ;
if ( V_152 != V_153 )
F_68 ( V_153 ) ;
V_173:
F_20 ( V_155 ) ;
return V_25 ;
}
int
F_99 ( struct V_150 * V_151 ,
struct V_154 * V_187 )
{
struct V_158 * V_159 = V_151 -> V_160 ;
struct V_3 * V_4 = V_151 -> V_4 ;
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_154 * V_155 ;
unsigned long V_37 ;
F_76 ( & V_5 -> V_161 , V_37 ) ;
if ( F_100 ( & V_159 -> V_162 ) ) {
F_34 ( V_4 , L_12 ) ;
F_78 ( & V_5 -> V_161 , V_37 ) ;
return - V_41 ;
}
V_155 = F_101 ( & V_159 -> V_162 , struct V_154 , V_2 ) ;
if ( V_155 -> V_169 )
F_102 ( V_5 , V_155 -> V_16 , V_155 -> V_169 ) ;
F_86 ( & V_155 -> V_2 ) ;
if ( V_187 )
* V_187 = * V_155 ;
F_20 ( V_155 ) ;
F_78 ( & V_5 -> V_161 , V_37 ) ;
return 0 ;
}
int
F_103 ( void * V_1 )
{
struct V_150 * V_151 = V_1 ;
struct V_3 * V_4 = V_151 -> V_4 ;
struct V_154 V_188 ;
if ( ! F_99 ( V_151 , & V_188 ) ) {
if ( F_32 ( V_4 -> V_47 ) -> V_64 < V_65 ) {
F_104 ( V_4 -> V_5 , V_188 . V_16 , V_188 . V_144 +
V_188 . V_181 * V_188 . V_189 +
V_188 . V_180 * V_188 . V_190 / 8 ) ;
}
}
return 0 ;
}
int
F_105 ( struct V_56 * V_57 , struct V_7 * V_5 ,
struct V_191 * args )
{
struct V_62 * V_145 ;
int V_25 ;
args -> V_189 = F_106 ( args -> V_192 * ( args -> V_190 / 8 ) , 256 ) ;
args -> V_193 = args -> V_189 * args -> V_194 ;
args -> V_193 = F_106 ( args -> V_193 , V_195 ) ;
V_25 = F_107 ( V_5 , args -> V_193 , 0 , V_196 , 0 , 0 , & V_145 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_57 , & V_145 -> V_55 , & args -> V_58 ) ;
F_26 ( & V_145 -> V_55 ) ;
return V_25 ;
}
int
F_108 ( struct V_56 * V_57 ,
struct V_7 * V_5 ,
T_4 V_58 , T_5 * V_197 )
{
struct V_83 * V_55 ;
V_55 = F_37 ( V_5 , V_57 , V_58 ) ;
if ( V_55 ) {
struct V_62 * V_145 = F_39 ( V_55 ) ;
* V_197 = F_109 ( & V_145 -> V_145 . V_198 ) ;
F_26 ( V_55 ) ;
return 0 ;
}
return - V_85 ;
}
