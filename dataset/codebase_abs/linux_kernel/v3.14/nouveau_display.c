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
* V_18 = F_7 ( args . V_32 , args . V_33 , args . V_34 , args . V_35 ) ;
* V_17 = F_7 ( args . V_36 , args . V_37 , args . V_38 , args . V_28 ) ;
if ( V_19 ) * V_19 = F_12 ( args . time [ 0 ] ) ;
if ( V_20 ) * V_20 = F_12 ( args . time [ 1 ] ) ;
if ( * V_17 < 0 )
V_25 |= V_39 ;
return V_25 ;
}
int
F_13 ( struct V_7 * V_5 , int V_2 , unsigned int V_40 ,
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
F_15 ( struct V_7 * V_5 , int V_2 , int * V_41 ,
struct V_42 * time , unsigned V_40 )
{
struct V_15 * V_16 ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
if ( F_9 ( V_16 ) -> V_23 == V_2 ) {
return F_16 ( V_5 ,
V_2 , V_41 , time , V_40 , V_16 ,
& V_16 -> V_43 ) ;
}
}
return - V_44 ;
}
static void
F_17 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
int V_45 ;
F_18 ( V_5 ) ;
if ( V_9 -> V_10 ) {
for ( V_45 = 0 ; V_45 < V_5 -> V_46 . V_47 ; V_45 ++ )
F_19 ( NULL , & V_9 -> V_10 [ V_45 ] ) ;
F_20 ( V_9 -> V_10 ) ;
V_9 -> V_10 = NULL ;
}
}
static int
F_21 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_48 * V_49 = V_48 ( V_4 -> V_50 ) ;
int V_25 , V_45 ;
V_9 -> V_10 = F_22 ( V_5 -> V_46 . V_47 *
sizeof( * V_9 -> V_10 ) , V_51 ) ;
if ( ! V_9 -> V_10 )
return - V_52 ;
for ( V_45 = 0 ; V_45 < V_5 -> V_46 . V_47 ; V_45 ++ ) {
V_25 = F_23 ( V_49 -> V_10 , V_45 ,
F_1 ,
V_4 , & V_9 -> V_10 [ V_45 ] ) ;
if ( V_25 ) {
F_17 ( V_5 ) ;
return V_25 ;
}
}
V_25 = F_24 ( V_5 , V_5 -> V_46 . V_47 ) ;
if ( V_25 ) {
F_17 ( V_5 ) ;
return V_25 ;
}
return 0 ;
}
static void
F_25 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_55 ( V_54 ) ;
if ( V_56 -> V_57 )
F_26 ( & V_56 -> V_57 -> V_58 ) ;
F_27 ( V_54 ) ;
F_20 ( V_56 ) ;
}
static int
F_28 ( struct V_53 * V_54 ,
struct V_59 * V_60 ,
unsigned int * V_61 )
{
struct V_55 * V_56 = V_55 ( V_54 ) ;
return F_29 ( V_60 , & V_56 -> V_57 -> V_58 , V_61 ) ;
}
int
F_30 ( struct V_7 * V_5 ,
struct V_55 * V_62 ,
struct V_63 * V_64 ,
struct V_65 * V_57 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_53 * V_56 = & V_62 -> V_66 ;
int V_25 ;
F_31 ( V_56 , V_64 ) ;
V_62 -> V_57 = V_57 ;
if ( F_32 ( V_4 -> V_50 ) -> V_67 >= V_68 ) {
T_2 V_69 = F_33 ( V_57 ) ;
if ( V_69 == 0x7a00 ||
V_69 == 0xfe00 )
V_62 -> V_70 = V_71 ;
else
if ( V_69 == 0x7000 )
V_62 -> V_70 = V_72 ;
else
V_62 -> V_70 = V_73 ;
switch ( V_56 -> V_74 ) {
case 8 : V_62 -> V_75 = 0x1e00 ; break;
case 15 : V_62 -> V_75 = 0xe900 ; break;
case 16 : V_62 -> V_75 = 0xe800 ; break;
case 24 :
case 32 : V_62 -> V_75 = 0xcf00 ; break;
case 30 : V_62 -> V_75 = 0xd100 ; break;
default:
F_34 ( V_4 , L_1 , V_56 -> V_74 ) ;
return - V_44 ;
}
if ( V_57 -> V_69 & V_76 ) {
F_34 ( V_4 , L_2 ) ;
return - V_44 ;
}
if ( F_32 ( V_4 -> V_50 ) -> V_77 == 0x50 )
V_62 -> V_75 |= ( V_69 << 8 ) ;
if ( ! V_69 ) {
if ( F_32 ( V_4 -> V_50 ) -> V_67 < V_78 )
V_62 -> V_79 = 0x00100000 | V_56 -> V_80 [ 0 ] ;
else
V_62 -> V_79 = 0x01000000 | V_56 -> V_80 [ 0 ] ;
} else {
T_2 V_81 = V_57 -> V_82 ;
if ( F_32 ( V_4 -> V_50 ) -> V_67 >= V_83 )
V_81 >>= 4 ;
V_62 -> V_79 = ( ( V_56 -> V_80 [ 0 ] / 4 ) << 4 ) | V_81 ;
}
}
V_25 = F_35 ( V_5 , V_56 , & V_84 ) ;
if ( V_25 ) {
return V_25 ;
}
return 0 ;
}
static struct V_53 *
F_36 ( struct V_7 * V_5 ,
struct V_59 * V_60 ,
struct V_63 * V_64 )
{
struct V_55 * V_85 ;
struct V_86 * V_58 ;
int V_25 = - V_52 ;
V_58 = F_37 ( V_5 , V_60 , V_64 -> V_87 [ 0 ] ) ;
if ( ! V_58 )
return F_38 ( - V_88 ) ;
V_85 = F_22 ( sizeof( struct V_55 ) , V_51 ) ;
if ( ! V_85 )
goto V_89;
V_25 = F_30 ( V_5 , V_85 , V_64 , F_39 ( V_58 ) ) ;
if ( V_25 )
goto V_90;
return & V_85 -> V_66 ;
V_90:
F_20 ( V_85 ) ;
V_89:
F_40 ( V_58 ) ;
return F_38 ( V_25 ) ;
}
int
F_41 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_91 * V_92 ;
int V_25 ;
V_25 = V_9 -> V_93 ( V_5 ) ;
if ( V_25 )
return V_25 ;
F_42 ( V_5 ) ;
F_14 (connector, &dev->mode_config.connector_list, head) {
struct V_94 * V_95 = V_94 ( V_92 ) ;
if ( V_95 -> V_96 ) F_4 ( V_95 -> V_96 ) ;
}
return V_25 ;
}
void
F_43 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_91 * V_92 ;
F_14 (connector, &dev->mode_config.connector_list, head) {
struct V_94 * V_95 = V_94 ( V_92 ) ;
if ( V_95 -> V_96 ) F_6 ( V_95 -> V_96 ) ;
}
F_44 ( V_5 ) ;
V_9 -> V_97 ( V_5 ) ;
}
int
F_45 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_8 * V_9 ;
int V_25 , V_98 ;
V_9 = V_4 -> V_99 = F_22 ( sizeof( * V_9 ) , V_51 ) ;
if ( ! V_9 )
return - V_52 ;
F_46 ( V_5 ) ;
F_47 ( V_5 ) ;
F_48 ( V_5 ) ;
if ( F_32 ( V_4 -> V_50 ) -> V_67 < V_68 )
V_98 = 0 ;
else
if ( F_32 ( V_4 -> V_50 ) -> V_67 < V_78 )
V_98 = 1 ;
else
V_98 = 2 ;
F_49 ( V_9 -> V_100 , V_98 , L_3 , V_101 ) ;
F_49 ( V_9 -> V_102 , V_98 , L_4 , V_103 ) ;
F_49 ( V_9 -> V_104 , V_98 , L_5 , V_105 ) ;
V_9 -> V_106 =
F_50 ( V_5 , 0 , L_6 , 0 , 128 ) ;
V_9 -> V_107 =
F_50 ( V_5 , 0 , L_7 , 0 , 128 ) ;
if ( V_98 >= 1 ) {
V_9 -> V_108 =
F_50 ( V_5 , 0 , L_8 , 0 , 180 ) ;
V_9 -> V_109 =
F_50 ( V_5 , 0 , L_9 , 0 , 200 ) ;
}
V_5 -> V_46 . V_110 = & V_111 ;
V_5 -> V_46 . V_112 = F_51 ( V_5 -> V_113 , 1 ) ;
V_5 -> V_46 . V_114 = 0 ;
V_5 -> V_46 . V_115 = 0 ;
if ( F_32 ( V_4 -> V_50 ) -> V_67 < V_116 ) {
V_5 -> V_46 . V_117 = 2048 ;
V_5 -> V_46 . V_118 = 2048 ;
} else
if ( F_32 ( V_4 -> V_50 ) -> V_67 < V_68 ) {
V_5 -> V_46 . V_117 = 4096 ;
V_5 -> V_46 . V_118 = 4096 ;
} else {
V_5 -> V_46 . V_117 = 8192 ;
V_5 -> V_46 . V_118 = 8192 ;
}
V_5 -> V_46 . V_119 = 24 ;
V_5 -> V_46 . V_120 = 1 ;
if ( F_32 ( V_4 -> V_50 ) -> V_77 < 0x11 )
V_5 -> V_46 . V_121 = false ;
else
V_5 -> V_46 . V_121 = true ;
F_52 ( V_5 ) ;
F_44 ( V_5 ) ;
if ( V_4 -> V_122 . V_123 . V_124 ) {
static const T_3 V_125 [] = {
V_126 ,
V_127 ,
V_128 ,
V_129 ,
V_130 ,
V_131 ,
V_132 ,
V_133 ,
V_134 ,
} ;
int V_45 ;
for ( V_45 = 0 , V_25 = - V_135 ; V_25 && V_45 < F_53 ( V_125 ) ; V_45 ++ ) {
V_25 = F_54 ( F_55 ( V_4 ) , V_136 ,
V_137 , V_125 [ V_45 ] ,
NULL , 0 , & V_9 -> V_27 ) ;
}
if ( V_25 == 0 ) {
if ( F_56 ( V_9 -> V_27 ) < V_133 )
V_25 = F_57 ( V_5 ) ;
else
V_25 = F_58 ( V_5 ) ;
}
} else {
V_25 = 0 ;
}
if ( V_25 )
goto V_138;
if ( V_5 -> V_46 . V_47 ) {
V_25 = F_21 ( V_5 ) ;
if ( V_25 )
goto V_139;
}
F_59 ( V_5 ) ;
return 0 ;
V_139:
V_9 -> V_140 ( V_5 ) ;
V_138:
F_60 ( V_5 ) ;
F_61 ( V_5 ) ;
return V_25 ;
}
void
F_62 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_3 * V_4 = V_3 ( V_5 ) ;
F_63 ( V_5 ) ;
F_17 ( V_5 ) ;
F_60 ( V_5 ) ;
F_61 ( V_5 ) ;
if ( V_9 -> V_140 )
V_9 -> V_140 ( V_5 ) ;
F_64 ( F_55 ( V_4 ) , V_136 , V_137 ) ;
V_3 ( V_5 ) -> V_99 = NULL ;
F_20 ( V_9 ) ;
}
int
F_65 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_15 * V_16 ;
F_43 ( V_5 ) ;
F_66 ( V_4 , L_10 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct V_55 * V_85 ;
V_85 = V_55 ( V_16 -> V_56 ) ;
if ( ! V_85 || ! V_85 -> V_57 )
continue;
F_67 ( V_85 -> V_57 ) ;
}
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct F_9 * V_141 = F_9 ( V_16 ) ;
F_68 ( V_141 -> V_142 . V_57 ) ;
F_67 ( V_141 -> V_142 . V_57 ) ;
}
return 0 ;
}
void
F_69 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_15 * V_16 ;
int V_25 ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct V_55 * V_85 ;
V_85 = V_55 ( V_16 -> V_56 ) ;
if ( ! V_85 || ! V_85 -> V_57 )
continue;
F_70 ( V_85 -> V_57 , V_143 ) ;
}
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct F_9 * V_141 = F_9 ( V_16 ) ;
V_25 = F_70 ( V_141 -> V_142 . V_57 , V_143 ) ;
if ( ! V_25 )
V_25 = F_71 ( V_141 -> V_142 . V_57 ) ;
if ( V_25 )
F_34 ( V_4 , L_11 ) ;
}
}
void
F_72 ( struct V_7 * V_5 )
{
struct V_15 * V_16 ;
F_41 ( V_5 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct F_9 * V_141 = F_9 ( V_16 ) ;
V_141 -> V_144 . V_74 = 0 ;
}
F_73 ( V_5 ) ;
F_14 (crtc, &dev->mode_config.crtc_list, head) {
struct F_9 * V_141 = F_9 ( V_16 ) ;
T_2 V_145 = V_141 -> V_142 . V_57 -> V_146 . V_145 ;
V_141 -> V_142 . V_147 ( V_141 , V_145 ) ;
V_141 -> V_142 . V_148 ( V_141 , V_141 -> V_149 ,
V_141 -> V_150 ) ;
}
}
static int
F_74 ( struct V_151 * V_152 ,
struct V_65 * V_153 ,
struct V_65 * V_154 ,
struct V_155 * V_156 ,
struct V_157 * * V_158 )
{
struct V_159 * V_160 = V_152 -> V_161 ;
struct V_3 * V_4 = V_152 -> V_4 ;
struct V_7 * V_5 = V_4 -> V_5 ;
unsigned long V_40 ;
int V_25 ;
F_75 ( & V_5 -> V_162 , V_40 ) ;
F_76 ( & V_156 -> V_2 , & V_160 -> V_163 ) ;
F_77 ( & V_5 -> V_162 , V_40 ) ;
V_25 = F_78 ( V_153 -> V_146 . V_164 , V_152 ) ;
if ( V_25 )
goto V_165;
V_25 = F_79 ( V_152 , 2 ) ;
if ( V_25 )
goto V_165;
if ( F_32 ( V_4 -> V_50 ) -> V_67 < V_83 )
F_80 ( V_152 , V_166 , V_167 , 1 ) ;
else
F_81 ( V_152 , V_168 , V_167 , 1 ) ;
F_82 ( V_152 , 0x00000000 ) ;
F_83 ( V_152 ) ;
V_25 = F_84 ( V_152 , false , V_158 ) ;
if ( V_25 )
goto V_165;
return 0 ;
V_165:
F_75 ( & V_5 -> V_162 , V_40 ) ;
F_85 ( & V_156 -> V_2 ) ;
F_77 ( & V_5 -> V_162 , V_40 ) ;
return V_25 ;
}
int
F_86 ( struct V_15 * V_16 , struct V_53 * V_56 ,
struct V_169 * V_170 , T_2 V_40 )
{
const int V_171 = ( V_40 & V_172 ) ? 0 : 1 ;
struct V_7 * V_5 = V_16 -> V_5 ;
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_65 * V_153 = V_55 ( V_16 -> V_56 ) -> V_57 ;
struct V_65 * V_154 = V_55 ( V_56 ) -> V_57 ;
struct V_155 * V_156 ;
struct V_151 * V_152 = V_4 -> V_173 ;
struct V_157 * V_161 ;
int V_25 ;
if ( ! V_4 -> V_173 )
return - V_135 ;
V_156 = F_22 ( sizeof( * V_156 ) , V_51 ) ;
if ( ! V_156 )
return - V_52 ;
if ( V_154 != V_153 ) {
V_25 = F_70 ( V_154 , V_143 ) ;
if ( V_25 )
goto V_174;
}
F_87 ( & V_152 -> V_175 -> V_176 ) ;
F_88 ( & V_154 -> V_146 . V_177 -> V_178 ) ;
V_161 = F_89 ( V_154 -> V_146 . V_164 ) ;
F_90 ( & V_154 -> V_146 . V_177 -> V_178 ) ;
V_25 = F_78 ( V_161 , V_152 ) ;
F_91 ( & V_161 ) ;
if ( V_25 )
goto V_179;
V_25 = F_92 ( & V_153 -> V_146 , true , false , false , NULL ) ;
if ( V_25 )
goto V_179;
* V_156 = (struct V_155 )
{ { } , V_170 , F_9 ( V_16 ) -> V_23 ,
V_56 -> V_180 , V_56 -> V_80 [ 0 ] , V_16 -> V_181 , V_16 -> V_182 ,
V_154 -> V_146 . V_145 } ;
if ( F_32 ( V_4 -> V_50 ) -> V_67 >= V_68 ) {
V_25 = F_93 ( V_16 , V_56 , V_152 , V_171 ) ;
if ( V_25 )
goto V_183;
} else {
struct V_184 * V_185 = V_184 ( V_5 ) ;
int V_2 = F_9 ( V_16 ) -> V_23 ;
if ( V_171 ) {
V_25 = F_79 ( V_152 , 8 ) ;
if ( V_25 )
goto V_183;
F_80 ( V_152 , V_186 , 0x012c , 1 ) ;
F_82 ( V_152 , 0 ) ;
F_80 ( V_152 , V_186 , 0x0134 , 1 ) ;
F_82 ( V_152 , V_2 ) ;
F_80 ( V_152 , V_186 , 0x0100 , 1 ) ;
F_82 ( V_152 , 0 ) ;
F_80 ( V_152 , V_186 , 0x0130 , 1 ) ;
F_82 ( V_152 , 0 ) ;
}
F_94 ( V_154 , & V_185 -> V_187 [ V_2 ] ) ;
}
V_25 = F_74 ( V_152 , V_153 , V_154 , V_156 , & V_161 ) ;
F_95 ( & V_152 -> V_175 -> V_176 ) ;
if ( V_25 )
goto V_183;
V_16 -> V_56 = V_56 ;
F_96 ( V_153 , V_161 ) ;
F_97 ( & V_153 -> V_146 ) ;
if ( V_153 != V_154 )
F_67 ( V_153 ) ;
F_91 ( & V_161 ) ;
return 0 ;
V_183:
F_97 ( & V_153 -> V_146 ) ;
V_179:
F_95 ( & V_152 -> V_175 -> V_176 ) ;
if ( V_153 != V_154 )
F_67 ( V_154 ) ;
V_174:
F_20 ( V_156 ) ;
return V_25 ;
}
int
F_98 ( struct V_151 * V_152 ,
struct V_155 * V_188 )
{
struct V_159 * V_160 = V_152 -> V_161 ;
struct V_3 * V_4 = V_152 -> V_4 ;
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_155 * V_156 ;
unsigned long V_40 ;
F_75 ( & V_5 -> V_162 , V_40 ) ;
if ( F_99 ( & V_160 -> V_163 ) ) {
F_34 ( V_4 , L_12 ) ;
F_77 ( & V_5 -> V_162 , V_40 ) ;
return - V_44 ;
}
V_156 = F_100 ( & V_160 -> V_163 , struct V_155 , V_2 ) ;
if ( V_156 -> V_170 )
F_101 ( V_5 , V_156 -> V_16 , V_156 -> V_170 ) ;
F_85 ( & V_156 -> V_2 ) ;
if ( V_188 )
* V_188 = * V_156 ;
F_20 ( V_156 ) ;
F_77 ( & V_5 -> V_162 , V_40 ) ;
return 0 ;
}
int
F_102 ( void * V_1 )
{
struct V_151 * V_152 = V_1 ;
struct V_3 * V_4 = V_152 -> V_4 ;
struct V_155 V_189 ;
if ( ! F_98 ( V_152 , & V_189 ) ) {
if ( F_32 ( V_4 -> V_50 ) -> V_67 < V_68 ) {
F_103 ( V_4 -> V_5 , V_189 . V_16 , V_189 . V_145 +
V_189 . V_182 * V_189 . V_190 +
V_189 . V_181 * V_189 . V_191 / 8 ) ;
}
}
return 0 ;
}
int
F_104 ( struct V_59 * V_60 , struct V_7 * V_5 ,
struct V_192 * args )
{
struct V_65 * V_146 ;
int V_25 ;
args -> V_190 = F_105 ( args -> V_193 * ( args -> V_191 / 8 ) , 256 ) ;
args -> V_194 = args -> V_190 * args -> V_195 ;
args -> V_194 = F_105 ( args -> V_194 , V_196 ) ;
V_25 = F_106 ( V_5 , args -> V_194 , 0 , V_197 , 0 , 0 , & V_146 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_60 , & V_146 -> V_58 , & args -> V_61 ) ;
F_26 ( & V_146 -> V_58 ) ;
return V_25 ;
}
int
F_107 ( struct V_59 * V_60 ,
struct V_7 * V_5 ,
T_4 V_61 , T_5 * V_198 )
{
struct V_86 * V_58 ;
V_58 = F_37 ( V_5 , V_60 , V_61 ) ;
if ( V_58 ) {
struct V_65 * V_146 = F_39 ( V_58 ) ;
* V_198 = F_108 ( & V_146 -> V_146 . V_199 ) ;
F_26 ( V_58 ) ;
return 0 ;
}
return - V_88 ;
}
