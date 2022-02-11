static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
if ( V_4 -> V_5 )
F_2 ( V_4 -> V_5 -> V_6 ) ;
F_3 ( V_2 ) ;
F_4 ( V_4 ) ;
}
static int
F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
return F_6 ( V_8 , V_4 -> V_5 -> V_6 , V_9 ) ;
}
int
F_7 ( struct V_10 * V_11 ,
struct V_3 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_5 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_1 * V_4 = & V_12 -> V_18 ;
int V_19 ;
V_19 = F_8 ( V_11 , V_4 , & V_20 ) ;
if ( V_19 ) {
return V_19 ;
}
F_9 ( V_4 , V_14 ) ;
V_12 -> V_5 = V_5 ;
if ( F_10 ( V_17 -> V_21 ) -> V_22 >= V_23 ) {
T_1 V_24 = F_11 ( V_5 ) ;
if ( V_24 == 0x7a00 ||
V_24 == 0xfe00 )
V_12 -> V_25 = V_26 ;
else
if ( V_24 == 0x7000 )
V_12 -> V_25 = V_27 ;
else
V_12 -> V_25 = V_28 ;
switch ( V_4 -> V_29 ) {
case 8 : V_12 -> V_30 = V_31 ; break;
case 15 : V_12 -> V_30 = V_32 ; break;
case 16 : V_12 -> V_30 = V_33 ; break;
case 24 :
case 32 : V_12 -> V_30 = V_34 ; break;
case 30 : V_12 -> V_30 = V_35 ; break;
default:
F_12 ( V_17 , L_1 , V_4 -> V_29 ) ;
return - V_36 ;
}
if ( F_10 ( V_17 -> V_21 ) -> V_37 == 0x50 )
V_12 -> V_30 |= ( V_24 << 8 ) ;
if ( ! V_24 ) {
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_38 )
V_12 -> V_39 = 0x00100000 | V_4 -> V_40 [ 0 ] ;
else
V_12 -> V_39 = 0x01000000 | V_4 -> V_40 [ 0 ] ;
} else {
T_1 V_41 = V_5 -> V_42 ;
if ( F_10 ( V_17 -> V_21 ) -> V_22 >= V_43 )
V_41 >>= 4 ;
V_12 -> V_39 = ( ( V_4 -> V_40 [ 0 ] / 4 ) << 4 ) | V_41 ;
}
}
return 0 ;
}
static struct V_1 *
F_13 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
struct V_13 * V_14 )
{
struct V_3 * V_44 ;
struct V_45 * V_6 ;
int V_19 ;
V_6 = F_14 ( V_11 , V_8 , V_14 -> V_46 [ 0 ] ) ;
if ( ! V_6 )
return F_15 ( - V_47 ) ;
V_44 = F_16 ( sizeof( struct V_3 ) , V_48 ) ;
if ( ! V_44 )
return F_15 ( - V_49 ) ;
V_19 = F_7 ( V_11 , V_44 , V_14 , F_17 ( V_6 ) ) ;
if ( V_19 ) {
F_18 ( V_6 ) ;
return F_15 ( V_19 ) ;
}
return & V_44 -> V_18 ;
}
int
F_19 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_50 * V_51 = V_50 ( V_11 ) ;
struct V_52 * V_53 = V_52 ( V_17 -> V_21 ) ;
struct V_54 * V_55 ;
int V_19 ;
V_19 = V_51 -> V_56 ( V_11 ) ;
if ( V_19 )
return V_19 ;
if ( V_53 && V_53 -> V_57 ( V_53 , 0 , V_58 , 0xff ) == 0 ) {
V_53 -> V_59 ( V_53 , 0 , V_58 , 0xff , 1 ) ;
F_20 ( 300 ) ;
}
F_21 ( V_11 ) ;
F_22 (connector, &dev->mode_config.connector_list, head) {
struct V_60 * V_61 = V_60 ( V_55 ) ;
if ( V_53 )
V_53 -> V_62 ( V_53 , 0 , V_61 -> V_63 , 0xff , true ) ;
}
return V_19 ;
}
void
F_23 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_50 * V_51 = V_50 ( V_11 ) ;
struct V_52 * V_53 = V_52 ( V_17 -> V_21 ) ;
struct V_54 * V_55 ;
F_22 (connector, &dev->mode_config.connector_list, head) {
struct V_60 * V_61 = V_60 ( V_55 ) ;
if ( V_53 )
V_53 -> V_62 ( V_53 , 0 , V_61 -> V_63 , 0xff , false ) ;
}
F_24 ( V_11 ) ;
V_51 -> V_64 ( V_11 ) ;
}
static void
F_25 ( void * V_65 , int V_66 )
{
F_26 ( V_65 , V_66 ) ;
}
static void
F_27 ( void * V_65 , int V_66 )
{
F_28 ( V_65 , V_66 ) ;
}
static void
F_29 ( void * V_65 , int V_66 )
{
F_30 ( V_65 , V_66 ) ;
}
int
F_31 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_67 * V_68 = V_67 ( V_17 -> V_21 ) ;
struct V_50 * V_51 ;
T_1 V_69 = V_11 -> V_70 -> V_71 >> 8 ;
int V_19 , V_72 ;
V_51 = V_17 -> V_73 = F_16 ( sizeof( * V_51 ) , V_48 ) ;
if ( ! V_51 )
return - V_49 ;
V_68 -> V_74 . V_65 = V_11 ;
V_68 -> V_74 . V_75 = F_25 ;
V_68 -> V_74 . V_57 = F_27 ;
V_68 -> V_74 . V_76 = F_29 ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
F_34 ( V_11 ) ;
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_23 )
V_72 = 0 ;
else
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_38 )
V_72 = 1 ;
else
V_72 = 2 ;
F_35 ( V_51 -> V_77 , V_72 , L_2 , V_78 ) ;
F_35 ( V_51 -> V_79 , V_72 , L_3 , V_80 ) ;
F_35 ( V_51 -> V_81 , V_72 , L_4 , V_82 ) ;
V_51 -> V_83 =
F_36 ( V_11 , 0 , L_5 , 0 , 128 ) ;
V_51 -> V_84 =
F_36 ( V_11 , 0 , L_6 , 0 , 128 ) ;
if ( V_72 == 1 ) {
V_51 -> V_85 =
F_37 ( V_11 , V_86 ,
L_7 , 2 ) ;
V_51 -> V_85 -> V_87 [ 0 ] = 0 ;
V_51 -> V_85 -> V_87 [ 1 ] = 180 ;
V_51 -> V_88 =
F_37 ( V_11 , V_86 ,
L_8 , 2 ) ;
V_51 -> V_88 -> V_87 [ 0 ] = 0 ;
V_51 -> V_88 -> V_87 [ 1 ] = 200 ;
}
V_11 -> V_89 . V_90 = & V_91 ;
V_11 -> V_89 . V_92 = F_38 ( V_11 -> V_70 , 1 ) ;
V_11 -> V_89 . V_93 = 0 ;
V_11 -> V_89 . V_94 = 0 ;
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_95 ) {
V_11 -> V_89 . V_96 = 2048 ;
V_11 -> V_89 . V_97 = 2048 ;
} else
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_23 ) {
V_11 -> V_89 . V_96 = 4096 ;
V_11 -> V_89 . V_97 = 4096 ;
} else {
V_11 -> V_89 . V_96 = 8192 ;
V_11 -> V_89 . V_97 = 8192 ;
}
V_11 -> V_89 . V_98 = 24 ;
V_11 -> V_89 . V_99 = 1 ;
F_39 ( V_11 ) ;
F_24 ( V_11 ) ;
if ( V_100 == 1 ||
( V_100 < 0 && V_69 == V_101 ) ) {
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_23 )
V_19 = F_40 ( V_11 ) ;
else
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_38 )
V_19 = F_41 ( V_11 ) ;
else
V_19 = F_42 ( V_11 ) ;
if ( V_19 )
goto V_102;
if ( V_11 -> V_89 . V_103 ) {
V_19 = F_43 ( V_11 , V_11 -> V_89 . V_103 ) ;
if ( V_19 )
goto V_104;
}
F_44 ( V_11 ) ;
}
return 0 ;
V_104:
V_51 -> V_105 ( V_11 ) ;
V_102:
F_45 ( V_11 ) ;
F_46 ( V_11 ) ;
return V_19 ;
}
void
F_47 ( struct V_10 * V_11 )
{
struct V_50 * V_51 = V_50 ( V_11 ) ;
F_48 ( V_11 ) ;
F_49 ( V_11 ) ;
if ( V_51 -> V_105 )
V_51 -> V_105 ( V_11 ) ;
F_45 ( V_11 ) ;
F_46 ( V_11 ) ;
V_16 ( V_11 ) -> V_73 = NULL ;
F_4 ( V_51 ) ;
}
int
F_50 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_106 * V_66 ;
F_23 ( V_11 ) ;
F_51 ( V_17 , L_9 ) ;
F_22 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_44 ;
V_44 = V_3 ( V_66 -> V_4 ) ;
if ( ! V_44 || ! V_44 -> V_5 )
continue;
F_52 ( V_44 -> V_5 ) ;
}
F_22 (crtc, &dev->mode_config.crtc_list, head) {
struct V_107 * V_108 = V_107 ( V_66 ) ;
F_53 ( V_108 -> V_109 . V_5 ) ;
F_52 ( V_108 -> V_109 . V_5 ) ;
}
return 0 ;
}
void
F_54 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_106 * V_66 ;
int V_19 ;
F_22 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_44 ;
V_44 = V_3 ( V_66 -> V_4 ) ;
if ( ! V_44 || ! V_44 -> V_5 )
continue;
F_55 ( V_44 -> V_5 , V_110 ) ;
}
F_22 (crtc, &dev->mode_config.crtc_list, head) {
struct V_107 * V_108 = V_107 ( V_66 ) ;
V_19 = F_55 ( V_108 -> V_109 . V_5 , V_110 ) ;
if ( ! V_19 )
V_19 = F_56 ( V_108 -> V_109 . V_5 ) ;
if ( V_19 )
F_12 ( V_17 , L_10 ) ;
}
F_57 ( V_11 , 0 ) ;
F_58 ( V_11 ) ;
F_19 ( V_11 ) ;
F_22 (crtc, &dev->mode_config.crtc_list, head) {
struct V_107 * V_108 = V_107 ( V_66 ) ;
V_108 -> V_111 . V_29 = 0 ;
}
F_59 ( V_11 ) ;
F_22 (crtc, &dev->mode_config.crtc_list, head) {
struct V_107 * V_108 = V_107 ( V_66 ) ;
T_1 V_112 = V_108 -> V_109 . V_5 -> V_113 . V_112 ;
V_108 -> V_109 . V_114 ( V_108 , V_112 ) ;
V_108 -> V_109 . V_115 ( V_108 , V_108 -> V_116 ,
V_108 -> V_117 ) ;
}
}
int
F_60 ( struct V_10 * V_11 , int V_66 )
{
struct V_118 * V_21 = F_61 ( V_11 ) ;
if ( V_21 -> V_22 >= V_38 )
F_62 ( V_21 , 0x6100c0 + ( V_66 * 0x800 ) , 1 , 1 ) ;
else
if ( V_21 -> V_22 >= V_23 )
F_62 ( V_21 , V_119 , 0 ,
F_63 ( V_66 ) ) ;
else
F_64 ( V_11 , V_66 , V_120 ,
V_121 ) ;
return 0 ;
}
void
F_65 ( struct V_10 * V_11 , int V_66 )
{
struct V_118 * V_21 = F_61 ( V_11 ) ;
if ( V_21 -> V_22 >= V_38 )
F_62 ( V_21 , 0x6100c0 + ( V_66 * 0x800 ) , 1 , 0 ) ;
else
if ( V_21 -> V_22 >= V_23 )
F_62 ( V_21 , V_119 ,
F_63 ( V_66 ) , 0 ) ;
else
F_64 ( V_11 , V_66 , V_120 , 0 ) ;
}
static int
F_66 ( struct V_15 * V_122 ,
struct V_15 * V_123 )
{
int V_19 ;
V_19 = F_55 ( V_123 , V_110 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_67 ( & V_123 -> V_113 , false , false , false , 0 ) ;
if ( V_19 )
goto V_124;
if ( F_68 ( V_122 != V_123 ) ) {
V_19 = F_67 ( & V_122 -> V_113 , false , false , false , 0 ) ;
if ( V_19 )
goto V_125;
}
return 0 ;
V_125:
F_69 ( & V_123 -> V_113 ) ;
V_124:
F_52 ( V_123 ) ;
return V_19 ;
}
static void
F_70 ( struct V_15 * V_122 ,
struct V_15 * V_123 ,
struct V_126 * V_127 )
{
F_71 ( V_123 , V_127 ) ;
F_69 ( & V_123 -> V_113 ) ;
if ( F_68 ( V_122 != V_123 ) ) {
F_71 ( V_122 , V_127 ) ;
F_69 ( & V_122 -> V_113 ) ;
}
F_52 ( V_122 ) ;
}
static int
F_72 ( struct V_128 * V_129 ,
struct V_15 * V_122 ,
struct V_15 * V_123 ,
struct V_130 * V_131 ,
struct V_126 * * V_132 )
{
struct V_133 * V_134 = V_129 -> V_127 ;
struct V_16 * V_17 = V_129 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
unsigned long V_135 ;
int V_19 ;
F_73 ( & V_11 -> V_136 , V_135 ) ;
F_74 ( & V_131 -> V_137 , & V_134 -> V_138 ) ;
F_75 ( & V_11 -> V_136 , V_135 ) ;
V_19 = F_76 ( V_122 -> V_113 . V_139 , V_129 ) ;
if ( V_19 )
goto V_124;
V_19 = F_77 ( V_129 , 3 ) ;
if ( V_19 )
goto V_124;
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_43 ) {
F_78 ( V_129 , V_140 , V_141 , 1 ) ;
F_79 ( V_129 , 0x00000000 ) ;
F_79 ( V_129 , 0x00000000 ) ;
} else {
F_80 ( V_129 , 0 , V_142 , 1 ) ;
F_79 ( V_129 , 0 ) ;
F_81 ( V_129 , 0 , V_143 , 0x0000 ) ;
}
F_82 ( V_129 ) ;
V_19 = F_83 ( V_129 , V_132 ) ;
if ( V_19 )
goto V_124;
return 0 ;
V_124:
F_73 ( & V_11 -> V_136 , V_135 ) ;
F_84 ( & V_131 -> V_137 ) ;
F_75 ( & V_11 -> V_136 , V_135 ) ;
return V_19 ;
}
int
F_85 ( struct V_106 * V_66 , struct V_1 * V_4 ,
struct V_144 * V_145 )
{
struct V_10 * V_11 = V_66 -> V_11 ;
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_15 * V_122 = V_3 ( V_66 -> V_4 ) -> V_5 ;
struct V_15 * V_123 = V_3 ( V_4 ) -> V_5 ;
struct V_130 * V_131 ;
struct V_128 * V_129 = NULL ;
struct V_126 * V_127 ;
int V_19 ;
if ( ! V_17 -> V_146 )
return - V_147 ;
V_131 = F_16 ( sizeof( * V_131 ) , V_48 ) ;
if ( ! V_131 )
return - V_49 ;
V_19 = F_66 ( V_122 , V_123 ) ;
if ( V_19 )
goto V_148;
* V_131 = (struct V_130 )
{ { } , V_145 , V_107 ( V_66 ) -> V_149 ,
V_4 -> V_150 , V_4 -> V_40 [ 0 ] , V_66 -> V_151 , V_66 -> V_152 ,
V_123 -> V_113 . V_112 } ;
V_127 = V_123 -> V_113 . V_139 ;
if ( V_127 )
V_129 = V_127 -> V_146 ;
if ( ! V_129 )
V_129 = V_17 -> V_146 ;
F_86 ( & V_129 -> V_153 -> V_154 ) ;
if ( F_10 ( V_17 -> V_21 ) -> V_22 >= V_23 ) {
if ( F_10 ( V_17 -> V_21 ) -> V_22 >= V_38 )
V_19 = F_87 ( V_66 , V_4 , V_129 , 0 ) ;
else
V_19 = F_88 ( V_66 , V_4 , V_129 ) ;
if ( V_19 ) {
F_89 ( & V_129 -> V_153 -> V_154 ) ;
goto V_125;
}
}
V_19 = F_72 ( V_129 , V_122 , V_123 , V_131 , & V_127 ) ;
F_89 ( & V_129 -> V_153 -> V_154 ) ;
if ( V_19 )
goto V_125;
V_66 -> V_4 = V_4 ;
F_70 ( V_122 , V_123 , V_127 ) ;
F_90 ( & V_127 ) ;
return 0 ;
V_125:
F_70 ( V_122 , V_123 , NULL ) ;
V_148:
F_4 ( V_131 ) ;
return V_19 ;
}
int
F_91 ( struct V_128 * V_129 ,
struct V_130 * V_155 )
{
struct V_133 * V_134 = V_129 -> V_127 ;
struct V_16 * V_17 = V_129 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
struct V_130 * V_131 ;
unsigned long V_135 ;
F_73 ( & V_11 -> V_136 , V_135 ) ;
if ( F_92 ( & V_134 -> V_138 ) ) {
F_12 ( V_17 , L_11 ) ;
F_75 ( & V_11 -> V_136 , V_135 ) ;
return - V_36 ;
}
V_131 = F_93 ( & V_134 -> V_138 , struct V_130 , V_137 ) ;
if ( V_131 -> V_145 ) {
struct V_144 * V_156 = V_131 -> V_145 ;
struct V_157 V_158 ;
F_94 ( & V_158 ) ;
V_156 -> V_145 . V_159 = 0 ;
V_156 -> V_145 . V_160 = V_158 . V_160 ;
V_156 -> V_145 . V_161 = V_158 . V_161 ;
F_74 ( & V_156 -> V_18 . V_162 , & V_156 -> V_18 . V_8 -> V_163 ) ;
F_95 ( & V_156 -> V_18 . V_8 -> V_164 ) ;
}
F_84 ( & V_131 -> V_137 ) ;
if ( V_155 )
* V_155 = * V_131 ;
F_4 ( V_131 ) ;
F_75 ( & V_11 -> V_136 , V_135 ) ;
return 0 ;
}
int
F_96 ( void * V_65 )
{
struct V_128 * V_129 = V_65 ;
struct V_16 * V_17 = V_129 -> V_17 ;
struct V_130 V_165 ;
if ( ! F_91 ( V_129 , & V_165 ) ) {
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_23 ) {
F_97 ( V_17 -> V_11 , V_165 . V_66 , V_165 . V_112 +
V_165 . V_152 * V_165 . V_166 +
V_165 . V_151 * V_165 . V_167 / 8 ) ;
}
}
return 0 ;
}
int
F_98 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_168 * args )
{
struct V_15 * V_113 ;
int V_19 ;
args -> V_166 = F_99 ( args -> V_169 * ( args -> V_167 / 8 ) , 256 ) ;
args -> V_170 = args -> V_166 * args -> V_171 ;
args -> V_170 = F_99 ( args -> V_170 , V_172 ) ;
V_19 = F_100 ( V_11 , args -> V_170 , 0 , V_173 , 0 , 0 , & V_113 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_6 ( V_8 , V_113 -> V_6 , & args -> V_9 ) ;
F_2 ( V_113 -> V_6 ) ;
return V_19 ;
}
int
F_101 ( struct V_7 * V_8 , struct V_10 * V_11 ,
T_2 V_9 )
{
return F_102 ( V_8 , V_9 ) ;
}
int
F_103 ( struct V_7 * V_8 ,
struct V_10 * V_11 ,
T_2 V_9 , T_3 * V_174 )
{
struct V_45 * V_6 ;
V_6 = F_14 ( V_11 , V_8 , V_9 ) ;
if ( V_6 ) {
struct V_15 * V_113 = V_6 -> V_175 ;
* V_174 = V_113 -> V_113 . V_176 ;
F_2 ( V_6 ) ;
return 0 ;
}
return - V_47 ;
}
