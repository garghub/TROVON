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
F_8 ( V_4 , V_14 ) ;
V_12 -> V_5 = V_5 ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 >= V_22 ) {
T_1 V_23 = F_10 ( V_5 ) ;
if ( V_23 == 0x7a00 ||
V_23 == 0xfe00 )
V_12 -> V_24 = V_25 ;
else
if ( V_23 == 0x7000 )
V_12 -> V_24 = V_26 ;
else
V_12 -> V_24 = V_27 ;
switch ( V_4 -> V_28 ) {
case 8 : V_12 -> V_29 = 0x1e00 ; break;
case 15 : V_12 -> V_29 = 0xe900 ; break;
case 16 : V_12 -> V_29 = 0xe800 ; break;
case 24 :
case 32 : V_12 -> V_29 = 0xcf00 ; break;
case 30 : V_12 -> V_29 = 0xd100 ; break;
default:
F_11 ( V_17 , L_1 , V_4 -> V_28 ) ;
return - V_30 ;
}
if ( V_5 -> V_23 & V_31 ) {
F_11 ( V_17 , L_2 ) ;
return - V_30 ;
}
if ( F_9 ( V_17 -> V_20 ) -> V_32 == 0x50 )
V_12 -> V_29 |= ( V_23 << 8 ) ;
if ( ! V_23 ) {
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_33 )
V_12 -> V_34 = 0x00100000 | V_4 -> V_35 [ 0 ] ;
else
V_12 -> V_34 = 0x01000000 | V_4 -> V_35 [ 0 ] ;
} else {
T_1 V_36 = V_5 -> V_37 ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 >= V_38 )
V_36 >>= 4 ;
V_12 -> V_34 = ( ( V_4 -> V_35 [ 0 ] / 4 ) << 4 ) | V_36 ;
}
}
V_19 = F_12 ( V_11 , V_4 , & V_39 ) ;
if ( V_19 ) {
return V_19 ;
}
return 0 ;
}
static struct V_1 *
F_13 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
struct V_13 * V_14 )
{
struct V_3 * V_40 ;
struct V_41 * V_6 ;
int V_19 = - V_42 ;
V_6 = F_14 ( V_11 , V_8 , V_14 -> V_43 [ 0 ] ) ;
if ( ! V_6 )
return F_15 ( - V_44 ) ;
V_40 = F_16 ( sizeof( struct V_3 ) , V_45 ) ;
if ( ! V_40 )
goto V_46;
V_19 = F_7 ( V_11 , V_40 , V_14 , F_17 ( V_6 ) ) ;
if ( V_19 )
goto V_47;
return & V_40 -> V_18 ;
V_47:
F_4 ( V_40 ) ;
V_46:
F_18 ( V_6 ) ;
return F_15 ( V_19 ) ;
}
int
F_19 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_48 * V_49 = V_48 ( V_11 ) ;
struct V_50 * V_51 = V_50 ( V_17 -> V_20 ) ;
struct V_52 * V_53 ;
int V_19 ;
V_19 = V_49 -> V_54 ( V_11 ) ;
if ( V_19 )
return V_19 ;
F_20 ( V_11 ) ;
F_21 (connector, &dev->mode_config.connector_list, head) {
struct V_55 * V_56 = V_55 ( V_53 ) ;
if ( V_51 && V_56 -> V_57 . V_58 != V_59 ) {
F_22 ( V_51 -> V_60 , V_56 -> V_57 . line ,
& V_56 -> V_61 ) ;
}
}
return V_19 ;
}
void
F_23 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_48 * V_49 = V_48 ( V_11 ) ;
struct V_50 * V_51 = V_50 ( V_17 -> V_20 ) ;
struct V_52 * V_53 ;
F_21 (connector, &dev->mode_config.connector_list, head) {
struct V_55 * V_56 = V_55 ( V_53 ) ;
if ( V_51 && V_56 -> V_57 . V_58 != V_59 ) {
F_24 ( V_51 -> V_60 , V_56 -> V_57 . line ,
& V_56 -> V_61 ) ;
}
}
F_25 ( V_11 ) ;
V_49 -> V_62 ( V_11 ) ;
}
int
F_26 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_48 * V_49 ;
int V_19 , V_63 ;
V_49 = V_17 -> V_64 = F_16 ( sizeof( * V_49 ) , V_45 ) ;
if ( ! V_49 )
return - V_42 ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_29 ( V_11 ) ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 )
V_63 = 0 ;
else
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_33 )
V_63 = 1 ;
else
V_63 = 2 ;
F_30 ( V_49 -> V_65 , V_63 , L_3 , V_66 ) ;
F_30 ( V_49 -> V_67 , V_63 , L_4 , V_68 ) ;
F_30 ( V_49 -> V_69 , V_63 , L_5 , V_70 ) ;
V_49 -> V_71 =
F_31 ( V_11 , 0 , L_6 , 0 , 128 ) ;
V_49 -> V_72 =
F_31 ( V_11 , 0 , L_7 , 0 , 128 ) ;
if ( V_63 >= 1 ) {
V_49 -> V_73 =
F_31 ( V_11 , 0 , L_8 , 0 , 180 ) ;
V_49 -> V_74 =
F_31 ( V_11 , 0 , L_9 , 0 , 200 ) ;
}
V_11 -> V_75 . V_76 = & V_77 ;
V_11 -> V_75 . V_78 = F_32 ( V_11 -> V_79 , 1 ) ;
V_11 -> V_75 . V_80 = 0 ;
V_11 -> V_75 . V_81 = 0 ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_82 ) {
V_11 -> V_75 . V_83 = 2048 ;
V_11 -> V_75 . V_84 = 2048 ;
} else
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 ) {
V_11 -> V_75 . V_83 = 4096 ;
V_11 -> V_75 . V_84 = 4096 ;
} else {
V_11 -> V_75 . V_83 = 8192 ;
V_11 -> V_75 . V_84 = 8192 ;
}
V_11 -> V_75 . V_85 = 24 ;
V_11 -> V_75 . V_86 = 1 ;
F_33 ( V_11 ) ;
F_25 ( V_11 ) ;
if ( V_17 -> V_87 . V_88 . V_89 ) {
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 )
V_19 = F_34 ( V_11 ) ;
else
V_19 = F_35 ( V_11 ) ;
} else {
V_19 = 0 ;
}
if ( V_19 )
goto V_90;
if ( V_11 -> V_75 . V_91 ) {
V_19 = F_36 ( V_11 , V_11 -> V_75 . V_91 ) ;
if ( V_19 )
goto V_92;
}
F_37 ( V_11 ) ;
return 0 ;
V_92:
V_49 -> V_93 ( V_11 ) ;
V_90:
F_38 ( V_11 ) ;
F_39 ( V_11 ) ;
return V_19 ;
}
void
F_40 ( struct V_10 * V_11 )
{
struct V_48 * V_49 = V_48 ( V_11 ) ;
F_41 ( V_11 ) ;
F_42 ( V_11 ) ;
F_38 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_49 -> V_93 )
V_49 -> V_93 ( V_11 ) ;
V_16 ( V_11 ) -> V_64 = NULL ;
F_4 ( V_49 ) ;
}
int
F_43 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_94 * V_95 ;
F_23 ( V_11 ) ;
F_44 ( V_17 , L_10 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_40 ;
V_40 = V_3 ( V_95 -> V_4 ) ;
if ( ! V_40 || ! V_40 -> V_5 )
continue;
F_45 ( V_40 -> V_5 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_96 * V_97 = V_96 ( V_95 ) ;
F_46 ( V_97 -> V_98 . V_5 ) ;
F_45 ( V_97 -> V_98 . V_5 ) ;
}
return 0 ;
}
void
F_47 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_94 * V_95 ;
int V_19 ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_40 ;
V_40 = V_3 ( V_95 -> V_4 ) ;
if ( ! V_40 || ! V_40 -> V_5 )
continue;
F_48 ( V_40 -> V_5 , V_99 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_96 * V_97 = V_96 ( V_95 ) ;
V_19 = F_48 ( V_97 -> V_98 . V_5 , V_99 ) ;
if ( ! V_19 )
V_19 = F_49 ( V_97 -> V_98 . V_5 ) ;
if ( V_19 )
F_11 ( V_17 , L_11 ) ;
}
}
void
F_50 ( struct V_10 * V_11 )
{
struct V_94 * V_95 ;
F_19 ( V_11 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_96 * V_97 = V_96 ( V_95 ) ;
V_97 -> V_100 . V_28 = 0 ;
}
F_51 ( V_11 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_96 * V_97 = V_96 ( V_95 ) ;
T_1 V_101 = V_97 -> V_98 . V_5 -> V_102 . V_101 ;
V_97 -> V_98 . V_103 ( V_97 , V_101 ) ;
V_97 -> V_98 . V_104 ( V_97 , V_97 -> V_105 ,
V_97 -> V_106 ) ;
}
}
static int
F_52 ( struct V_107 * V_108 ,
struct V_15 * V_109 ,
struct V_15 * V_110 ,
struct V_111 * V_112 ,
struct V_113 * * V_114 )
{
struct V_115 * V_116 = V_108 -> V_117 ;
struct V_16 * V_17 = V_108 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
unsigned long V_118 ;
int V_19 ;
F_53 ( & V_11 -> V_119 , V_118 ) ;
F_54 ( & V_112 -> V_120 , & V_116 -> V_121 ) ;
F_55 ( & V_11 -> V_119 , V_118 ) ;
V_19 = F_56 ( V_109 -> V_102 . V_122 , V_108 ) ;
if ( V_19 )
goto V_123;
V_19 = F_57 ( V_108 , 3 ) ;
if ( V_19 )
goto V_123;
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_38 ) {
F_58 ( V_108 , V_124 , V_125 , 1 ) ;
F_59 ( V_108 , 0x00000000 ) ;
F_59 ( V_108 , 0x00000000 ) ;
} else {
F_60 ( V_108 , 0 , V_126 , 1 ) ;
F_59 ( V_108 , 0 ) ;
F_61 ( V_108 , 0 , V_127 , 0x0000 ) ;
}
F_62 ( V_108 ) ;
V_19 = F_63 ( V_108 , false , V_114 ) ;
if ( V_19 )
goto V_123;
return 0 ;
V_123:
F_53 ( & V_11 -> V_119 , V_118 ) ;
F_64 ( & V_112 -> V_120 ) ;
F_55 ( & V_11 -> V_119 , V_118 ) ;
return V_19 ;
}
int
F_65 ( struct V_94 * V_95 , struct V_1 * V_4 ,
struct V_128 * V_129 ,
T_2 V_130 )
{
struct V_10 * V_11 = V_95 -> V_11 ;
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_15 * V_109 = V_3 ( V_95 -> V_4 ) -> V_5 ;
struct V_15 * V_110 = V_3 ( V_4 ) -> V_5 ;
struct V_111 * V_112 ;
struct V_107 * V_108 = NULL ;
struct V_113 * V_117 ;
struct V_131 V_132 [ 2 ] = {
{ . V_102 = & V_109 -> V_102 } ,
{ . V_102 = & V_110 -> V_102 } ,
} ;
struct V_133 V_134 ;
F_66 ( V_135 ) ;
int V_19 ;
if ( ! V_17 -> V_136 )
return - V_137 ;
V_112 = F_16 ( sizeof( * V_112 ) , V_45 ) ;
if ( ! V_112 )
return - V_42 ;
F_67 ( & V_109 -> V_102 . V_138 -> V_139 ) ;
V_117 = V_110 -> V_102 . V_122 ;
if ( V_117 )
V_108 = V_117 -> V_136 ;
if ( ! V_108 )
V_108 = V_17 -> V_136 ;
F_68 ( & V_109 -> V_102 . V_138 -> V_139 ) ;
if ( V_110 != V_109 ) {
V_19 = F_48 ( V_110 , V_99 ) ;
if ( V_19 )
goto V_140;
F_69 ( & V_132 [ 1 ] . V_120 , & V_135 ) ;
}
F_69 ( & V_132 [ 0 ] . V_120 , & V_135 ) ;
F_70 ( & V_108 -> V_141 -> V_142 ) ;
V_19 = F_71 ( & V_134 , & V_135 ) ;
if ( V_19 )
goto V_143;
* V_112 = (struct V_111 )
{ { } , V_129 , V_96 ( V_95 ) -> V_144 ,
V_4 -> V_145 , V_4 -> V_35 [ 0 ] , V_95 -> V_146 , V_95 -> V_147 ,
V_110 -> V_102 . V_101 } ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 >= V_22 ) {
V_19 = F_72 ( V_95 , V_4 , V_108 , 0 ) ;
if ( V_19 )
goto V_148;
} else {
struct V_149 * V_150 = V_149 ( V_11 ) ;
F_73 ( V_110 , & V_150 -> V_151 [ V_96 ( V_95 ) -> V_144 ] ) ;
}
V_19 = F_52 ( V_108 , V_109 , V_110 , V_112 , & V_117 ) ;
F_74 ( & V_108 -> V_141 -> V_142 ) ;
if ( V_19 )
goto V_148;
V_95 -> V_4 = V_4 ;
F_75 ( & V_134 , & V_135 , V_117 ) ;
if ( V_109 != V_110 )
F_45 ( V_109 ) ;
F_76 ( & V_117 ) ;
return 0 ;
V_148:
F_77 ( & V_134 , & V_135 ) ;
V_143:
F_74 ( & V_108 -> V_141 -> V_142 ) ;
if ( V_109 != V_110 )
F_45 ( V_110 ) ;
V_140:
F_4 ( V_112 ) ;
return V_19 ;
}
int
F_78 ( struct V_107 * V_108 ,
struct V_111 * V_152 )
{
struct V_115 * V_116 = V_108 -> V_117 ;
struct V_16 * V_17 = V_108 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
struct V_111 * V_112 ;
unsigned long V_118 ;
F_53 ( & V_11 -> V_119 , V_118 ) ;
if ( F_79 ( & V_116 -> V_121 ) ) {
F_11 ( V_17 , L_12 ) ;
F_55 ( & V_11 -> V_119 , V_118 ) ;
return - V_30 ;
}
V_112 = F_80 ( & V_116 -> V_121 , struct V_111 , V_120 ) ;
if ( V_112 -> V_129 )
F_81 ( V_11 , - 1 , V_112 -> V_129 ) ;
F_64 ( & V_112 -> V_120 ) ;
if ( V_152 )
* V_152 = * V_112 ;
F_4 ( V_112 ) ;
F_55 ( & V_11 -> V_119 , V_118 ) ;
return 0 ;
}
int
F_82 ( void * V_153 )
{
struct V_107 * V_108 = V_153 ;
struct V_16 * V_17 = V_108 -> V_17 ;
struct V_111 V_154 ;
if ( ! F_78 ( V_108 , & V_154 ) ) {
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 ) {
F_83 ( V_17 -> V_11 , V_154 . V_95 , V_154 . V_101 +
V_154 . V_147 * V_154 . V_155 +
V_154 . V_146 * V_154 . V_156 / 8 ) ;
}
}
return 0 ;
}
int
F_84 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_157 * args )
{
struct V_15 * V_102 ;
int V_19 ;
args -> V_155 = F_85 ( args -> V_158 * ( args -> V_156 / 8 ) , 256 ) ;
args -> V_159 = args -> V_155 * args -> V_160 ;
args -> V_159 = F_85 ( args -> V_159 , V_161 ) ;
V_19 = F_86 ( V_11 , args -> V_159 , 0 , V_162 , 0 , 0 , & V_102 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_6 ( V_8 , V_102 -> V_6 , & args -> V_9 ) ;
F_2 ( V_102 -> V_6 ) ;
return V_19 ;
}
int
F_87 ( struct V_7 * V_8 ,
struct V_10 * V_11 ,
T_2 V_9 , T_3 * V_163 )
{
struct V_41 * V_6 ;
V_6 = F_14 ( V_11 , V_8 , V_9 ) ;
if ( V_6 ) {
struct V_15 * V_102 = V_6 -> V_164 ;
* V_163 = F_88 ( & V_102 -> V_102 . V_165 ) ;
F_2 ( V_6 ) ;
return 0 ;
}
return - V_44 ;
}
