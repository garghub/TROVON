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
case 8 : V_12 -> V_30 = 0x1e00 ; break;
case 15 : V_12 -> V_30 = 0xe900 ; break;
case 16 : V_12 -> V_30 = 0xe800 ; break;
case 24 :
case 32 : V_12 -> V_30 = 0xcf00 ; break;
case 30 : V_12 -> V_30 = 0xd100 ; break;
default:
F_12 ( V_17 , L_1 , V_4 -> V_29 ) ;
return - V_31 ;
}
if ( F_10 ( V_17 -> V_21 ) -> V_32 == 0x50 )
V_12 -> V_30 |= ( V_24 << 8 ) ;
if ( ! V_24 ) {
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_33 )
V_12 -> V_34 = 0x00100000 | V_4 -> V_35 [ 0 ] ;
else
V_12 -> V_34 = 0x01000000 | V_4 -> V_35 [ 0 ] ;
} else {
T_1 V_36 = V_5 -> V_37 ;
if ( F_10 ( V_17 -> V_21 ) -> V_22 >= V_38 )
V_36 >>= 4 ;
V_12 -> V_34 = ( ( V_4 -> V_35 [ 0 ] / 4 ) << 4 ) | V_36 ;
}
}
return 0 ;
}
static struct V_1 *
F_13 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
struct V_13 * V_14 )
{
struct V_3 * V_39 ;
struct V_40 * V_6 ;
int V_19 ;
V_6 = F_14 ( V_11 , V_8 , V_14 -> V_41 [ 0 ] ) ;
if ( ! V_6 )
return F_15 ( - V_42 ) ;
V_39 = F_16 ( sizeof( struct V_3 ) , V_43 ) ;
if ( ! V_39 )
return F_15 ( - V_44 ) ;
V_19 = F_7 ( V_11 , V_39 , V_14 , F_17 ( V_6 ) ) ;
if ( V_19 ) {
F_18 ( V_6 ) ;
return F_15 ( V_19 ) ;
}
return & V_39 -> V_18 ;
}
int
F_19 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_45 * V_46 = V_45 ( V_11 ) ;
struct V_47 * V_48 = V_47 ( V_17 -> V_21 ) ;
struct V_49 * V_50 ;
int V_19 ;
V_19 = V_46 -> V_51 ( V_11 ) ;
if ( V_19 )
return V_19 ;
F_20 ( V_11 ) ;
F_21 (connector, &dev->mode_config.connector_list, head) {
struct V_52 * V_53 = V_52 ( V_50 ) ;
if ( V_48 )
V_48 -> V_54 ( V_48 , 0 , V_53 -> V_55 , 0xff , true ) ;
}
return V_19 ;
}
void
F_22 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_45 * V_46 = V_45 ( V_11 ) ;
struct V_47 * V_48 = V_47 ( V_17 -> V_21 ) ;
struct V_49 * V_50 ;
F_21 (connector, &dev->mode_config.connector_list, head) {
struct V_52 * V_53 = V_52 ( V_50 ) ;
if ( V_48 )
V_48 -> V_54 ( V_48 , 0 , V_53 -> V_55 , 0xff , false ) ;
}
F_23 ( V_11 ) ;
V_46 -> V_56 ( V_11 ) ;
}
static void
F_24 ( void * V_57 , int V_58 )
{
F_25 ( V_57 , V_58 ) ;
}
static void
F_26 ( void * V_57 , int V_58 )
{
F_27 ( V_57 , V_58 ) ;
}
static void
F_28 ( void * V_57 , int V_58 )
{
F_29 ( V_57 , V_58 ) ;
}
int
F_30 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_59 * V_60 = V_59 ( V_17 -> V_21 ) ;
struct V_45 * V_46 ;
T_1 V_61 = V_11 -> V_62 -> V_63 >> 8 ;
int V_19 , V_64 ;
V_46 = V_17 -> V_65 = F_16 ( sizeof( * V_46 ) , V_43 ) ;
if ( ! V_46 )
return - V_44 ;
V_60 -> V_66 . V_57 = V_11 ;
V_60 -> V_66 . V_67 = F_24 ;
V_60 -> V_66 . V_68 = F_26 ;
V_60 -> V_66 . V_69 = F_28 ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_23 )
V_64 = 0 ;
else
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_33 )
V_64 = 1 ;
else
V_64 = 2 ;
F_34 ( V_46 -> V_70 , V_64 , L_2 , V_71 ) ;
F_34 ( V_46 -> V_72 , V_64 , L_3 , V_73 ) ;
F_34 ( V_46 -> V_74 , V_64 , L_4 , V_75 ) ;
V_46 -> V_76 =
F_35 ( V_11 , 0 , L_5 , 0 , 128 ) ;
V_46 -> V_77 =
F_35 ( V_11 , 0 , L_6 , 0 , 128 ) ;
if ( V_64 >= 1 ) {
V_46 -> V_78 =
F_36 ( V_11 , V_79 ,
L_7 , 2 ) ;
V_46 -> V_78 -> V_80 [ 0 ] = 0 ;
V_46 -> V_78 -> V_80 [ 1 ] = 180 ;
V_46 -> V_81 =
F_36 ( V_11 , V_79 ,
L_8 , 2 ) ;
V_46 -> V_81 -> V_80 [ 0 ] = 0 ;
V_46 -> V_81 -> V_80 [ 1 ] = 200 ;
}
V_11 -> V_82 . V_83 = & V_84 ;
V_11 -> V_82 . V_85 = F_37 ( V_11 -> V_62 , 1 ) ;
V_11 -> V_82 . V_86 = 0 ;
V_11 -> V_82 . V_87 = 0 ;
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_88 ) {
V_11 -> V_82 . V_89 = 2048 ;
V_11 -> V_82 . V_90 = 2048 ;
} else
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_23 ) {
V_11 -> V_82 . V_89 = 4096 ;
V_11 -> V_82 . V_90 = 4096 ;
} else {
V_11 -> V_82 . V_89 = 8192 ;
V_11 -> V_82 . V_90 = 8192 ;
}
V_11 -> V_82 . V_91 = 24 ;
V_11 -> V_82 . V_92 = 1 ;
F_38 ( V_11 ) ;
F_23 ( V_11 ) ;
if ( V_93 == 1 ||
( V_93 < 0 && V_61 == V_94 ) ) {
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_23 )
V_19 = F_39 ( V_11 ) ;
else
V_19 = F_40 ( V_11 ) ;
if ( V_19 )
goto V_95;
if ( V_11 -> V_82 . V_96 ) {
V_19 = F_41 ( V_11 , V_11 -> V_82 . V_96 ) ;
if ( V_19 )
goto V_97;
}
F_42 ( V_11 ) ;
}
return 0 ;
V_97:
V_46 -> V_98 ( V_11 ) ;
V_95:
F_43 ( V_11 ) ;
F_44 ( V_11 ) ;
return V_19 ;
}
void
F_45 ( struct V_10 * V_11 )
{
struct V_45 * V_46 = V_45 ( V_11 ) ;
F_46 ( V_11 ) ;
F_47 ( V_11 ) ;
F_43 ( V_11 ) ;
F_44 ( V_11 ) ;
if ( V_46 -> V_98 )
V_46 -> V_98 ( V_11 ) ;
V_16 ( V_11 ) -> V_65 = NULL ;
F_4 ( V_46 ) ;
}
int
F_48 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_99 * V_58 ;
F_22 ( V_11 ) ;
F_49 ( V_17 , L_9 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_39 ;
V_39 = V_3 ( V_58 -> V_4 ) ;
if ( ! V_39 || ! V_39 -> V_5 )
continue;
F_50 ( V_39 -> V_5 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_100 * V_101 = V_100 ( V_58 ) ;
F_51 ( V_101 -> V_102 . V_5 ) ;
F_50 ( V_101 -> V_102 . V_5 ) ;
}
return 0 ;
}
void
F_52 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_99 * V_58 ;
int V_19 ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_39 ;
V_39 = V_3 ( V_58 -> V_4 ) ;
if ( ! V_39 || ! V_39 -> V_5 )
continue;
F_53 ( V_39 -> V_5 , V_103 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_100 * V_101 = V_100 ( V_58 ) ;
V_19 = F_53 ( V_101 -> V_102 . V_5 , V_103 ) ;
if ( ! V_19 )
V_19 = F_54 ( V_101 -> V_102 . V_5 ) ;
if ( V_19 )
F_12 ( V_17 , L_10 ) ;
}
F_55 ( V_11 , 0 ) ;
F_56 ( V_11 ) ;
F_19 ( V_11 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_100 * V_101 = V_100 ( V_58 ) ;
V_101 -> V_104 . V_29 = 0 ;
}
F_57 ( V_11 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_100 * V_101 = V_100 ( V_58 ) ;
T_1 V_105 = V_101 -> V_102 . V_5 -> V_106 . V_105 ;
V_101 -> V_102 . V_107 ( V_101 , V_105 ) ;
V_101 -> V_102 . V_108 ( V_101 , V_101 -> V_109 ,
V_101 -> V_110 ) ;
}
}
int
F_58 ( struct V_10 * V_11 , int V_58 )
{
struct V_111 * V_21 = F_59 ( V_11 ) ;
if ( V_21 -> V_22 >= V_33 )
F_60 ( V_21 , 0x6100c0 + ( V_58 * 0x800 ) , 1 , 1 ) ;
else
if ( V_21 -> V_22 >= V_23 )
F_60 ( V_21 , V_112 , 0 ,
F_61 ( V_58 ) ) ;
else
F_62 ( V_11 , V_58 , V_113 ,
V_114 ) ;
return 0 ;
}
void
F_63 ( struct V_10 * V_11 , int V_58 )
{
struct V_111 * V_21 = F_59 ( V_11 ) ;
if ( V_21 -> V_22 >= V_33 )
F_60 ( V_21 , 0x6100c0 + ( V_58 * 0x800 ) , 1 , 0 ) ;
else
if ( V_21 -> V_22 >= V_23 )
F_60 ( V_21 , V_112 ,
F_61 ( V_58 ) , 0 ) ;
else
F_62 ( V_11 , V_58 , V_113 , 0 ) ;
}
static int
F_64 ( struct V_15 * V_115 ,
struct V_15 * V_116 )
{
int V_19 ;
V_19 = F_53 ( V_116 , V_103 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_65 ( & V_116 -> V_106 , false , false , false , 0 ) ;
if ( V_19 )
goto V_117;
if ( F_66 ( V_115 != V_116 ) ) {
V_19 = F_65 ( & V_115 -> V_106 , false , false , false , 0 ) ;
if ( V_19 )
goto V_118;
}
return 0 ;
V_118:
F_67 ( & V_116 -> V_106 ) ;
V_117:
F_50 ( V_116 ) ;
return V_19 ;
}
static void
F_68 ( struct V_15 * V_115 ,
struct V_15 * V_116 ,
struct V_119 * V_120 )
{
F_69 ( V_116 , V_120 ) ;
F_67 ( & V_116 -> V_106 ) ;
if ( F_66 ( V_115 != V_116 ) ) {
F_69 ( V_115 , V_120 ) ;
F_67 ( & V_115 -> V_106 ) ;
}
F_50 ( V_115 ) ;
}
static int
F_70 ( struct V_121 * V_122 ,
struct V_15 * V_115 ,
struct V_15 * V_116 ,
struct V_123 * V_124 ,
struct V_119 * * V_125 )
{
struct V_126 * V_127 = V_122 -> V_120 ;
struct V_16 * V_17 = V_122 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
unsigned long V_128 ;
int V_19 ;
F_71 ( & V_11 -> V_129 , V_128 ) ;
F_72 ( & V_124 -> V_130 , & V_127 -> V_131 ) ;
F_73 ( & V_11 -> V_129 , V_128 ) ;
V_19 = F_74 ( V_115 -> V_106 . V_132 , V_122 ) ;
if ( V_19 )
goto V_117;
V_19 = F_75 ( V_122 , 3 ) ;
if ( V_19 )
goto V_117;
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_38 ) {
F_76 ( V_122 , V_133 , V_134 , 1 ) ;
F_77 ( V_122 , 0x00000000 ) ;
F_77 ( V_122 , 0x00000000 ) ;
} else {
F_78 ( V_122 , 0 , V_135 , 1 ) ;
F_77 ( V_122 , 0 ) ;
F_79 ( V_122 , 0 , V_136 , 0x0000 ) ;
}
F_80 ( V_122 ) ;
V_19 = F_81 ( V_122 , V_125 ) ;
if ( V_19 )
goto V_117;
return 0 ;
V_117:
F_71 ( & V_11 -> V_129 , V_128 ) ;
F_82 ( & V_124 -> V_130 ) ;
F_73 ( & V_11 -> V_129 , V_128 ) ;
return V_19 ;
}
int
F_83 ( struct V_99 * V_58 , struct V_1 * V_4 ,
struct V_137 * V_138 )
{
struct V_10 * V_11 = V_58 -> V_11 ;
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_15 * V_115 = V_3 ( V_58 -> V_4 ) -> V_5 ;
struct V_15 * V_116 = V_3 ( V_4 ) -> V_5 ;
struct V_123 * V_124 ;
struct V_121 * V_122 = NULL ;
struct V_119 * V_120 ;
int V_19 ;
if ( ! V_17 -> V_139 )
return - V_140 ;
V_124 = F_16 ( sizeof( * V_124 ) , V_43 ) ;
if ( ! V_124 )
return - V_44 ;
V_19 = F_64 ( V_115 , V_116 ) ;
if ( V_19 )
goto V_141;
* V_124 = (struct V_123 )
{ { } , V_138 , V_100 ( V_58 ) -> V_142 ,
V_4 -> V_143 , V_4 -> V_35 [ 0 ] , V_58 -> V_144 , V_58 -> V_145 ,
V_116 -> V_106 . V_105 } ;
V_120 = V_116 -> V_106 . V_132 ;
if ( V_120 )
V_122 = V_120 -> V_139 ;
if ( ! V_122 )
V_122 = V_17 -> V_139 ;
F_84 ( & V_122 -> V_146 -> V_147 ) ;
if ( F_10 ( V_17 -> V_21 ) -> V_22 >= V_23 ) {
V_19 = F_85 ( V_58 , V_4 , V_122 , 0 ) ;
if ( V_19 ) {
F_86 ( & V_122 -> V_146 -> V_147 ) ;
goto V_118;
}
}
V_19 = F_70 ( V_122 , V_115 , V_116 , V_124 , & V_120 ) ;
F_86 ( & V_122 -> V_146 -> V_147 ) ;
if ( V_19 )
goto V_118;
V_58 -> V_4 = V_4 ;
F_68 ( V_115 , V_116 , V_120 ) ;
F_87 ( & V_120 ) ;
return 0 ;
V_118:
F_68 ( V_115 , V_116 , NULL ) ;
V_141:
F_4 ( V_124 ) ;
return V_19 ;
}
int
F_88 ( struct V_121 * V_122 ,
struct V_123 * V_148 )
{
struct V_126 * V_127 = V_122 -> V_120 ;
struct V_16 * V_17 = V_122 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
struct V_123 * V_124 ;
unsigned long V_128 ;
F_71 ( & V_11 -> V_129 , V_128 ) ;
if ( F_89 ( & V_127 -> V_131 ) ) {
F_12 ( V_17 , L_11 ) ;
F_73 ( & V_11 -> V_129 , V_128 ) ;
return - V_31 ;
}
V_124 = F_90 ( & V_127 -> V_131 , struct V_123 , V_130 ) ;
if ( V_124 -> V_138 ) {
struct V_137 * V_149 = V_124 -> V_138 ;
struct V_150 V_151 ;
F_91 ( & V_151 ) ;
V_149 -> V_138 . V_152 = 0 ;
V_149 -> V_138 . V_153 = V_151 . V_153 ;
V_149 -> V_138 . V_154 = V_151 . V_154 ;
F_72 ( & V_149 -> V_18 . V_155 , & V_149 -> V_18 . V_8 -> V_156 ) ;
F_92 ( & V_149 -> V_18 . V_8 -> V_157 ) ;
}
F_82 ( & V_124 -> V_130 ) ;
if ( V_148 )
* V_148 = * V_124 ;
F_4 ( V_124 ) ;
F_73 ( & V_11 -> V_129 , V_128 ) ;
return 0 ;
}
int
F_93 ( void * V_57 )
{
struct V_121 * V_122 = V_57 ;
struct V_16 * V_17 = V_122 -> V_17 ;
struct V_123 V_158 ;
if ( ! F_88 ( V_122 , & V_158 ) ) {
if ( F_10 ( V_17 -> V_21 ) -> V_22 < V_23 ) {
F_94 ( V_17 -> V_11 , V_158 . V_58 , V_158 . V_105 +
V_158 . V_145 * V_158 . V_159 +
V_158 . V_144 * V_158 . V_160 / 8 ) ;
}
}
return 0 ;
}
int
F_95 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_161 * args )
{
struct V_15 * V_106 ;
int V_19 ;
args -> V_159 = F_96 ( args -> V_162 * ( args -> V_160 / 8 ) , 256 ) ;
args -> V_163 = args -> V_159 * args -> V_164 ;
args -> V_163 = F_96 ( args -> V_163 , V_165 ) ;
V_19 = F_97 ( V_11 , args -> V_163 , 0 , V_166 , 0 , 0 , & V_106 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_6 ( V_8 , V_106 -> V_6 , & args -> V_9 ) ;
F_2 ( V_106 -> V_6 ) ;
return V_19 ;
}
int
F_98 ( struct V_7 * V_8 , struct V_10 * V_11 ,
T_2 V_9 )
{
return F_99 ( V_8 , V_9 ) ;
}
int
F_100 ( struct V_7 * V_8 ,
struct V_10 * V_11 ,
T_2 V_9 , T_3 * V_167 )
{
struct V_40 * V_6 ;
V_6 = F_14 ( V_11 , V_8 , V_9 ) ;
if ( V_6 ) {
struct V_15 * V_106 = V_6 -> V_168 ;
* V_167 = V_106 -> V_106 . V_169 ;
F_2 ( V_6 ) ;
return 0 ;
}
return - V_42 ;
}
