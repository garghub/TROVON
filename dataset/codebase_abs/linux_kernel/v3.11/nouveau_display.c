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
if ( F_9 ( V_17 -> V_20 ) -> V_31 == 0x50 )
V_12 -> V_29 |= ( V_23 << 8 ) ;
if ( ! V_23 ) {
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_32 )
V_12 -> V_33 = 0x00100000 | V_4 -> V_34 [ 0 ] ;
else
V_12 -> V_33 = 0x01000000 | V_4 -> V_34 [ 0 ] ;
} else {
T_1 V_35 = V_5 -> V_36 ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 >= V_37 )
V_35 >>= 4 ;
V_12 -> V_33 = ( ( V_4 -> V_34 [ 0 ] / 4 ) << 4 ) | V_35 ;
}
}
V_19 = F_12 ( V_11 , V_4 , & V_38 ) ;
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
struct V_3 * V_39 ;
struct V_40 * V_6 ;
int V_19 = - V_41 ;
V_6 = F_14 ( V_11 , V_8 , V_14 -> V_42 [ 0 ] ) ;
if ( ! V_6 )
return F_15 ( - V_43 ) ;
V_39 = F_16 ( sizeof( struct V_3 ) , V_44 ) ;
if ( ! V_39 )
goto V_45;
V_19 = F_7 ( V_11 , V_39 , V_14 , F_17 ( V_6 ) ) ;
if ( V_19 )
goto V_46;
return & V_39 -> V_18 ;
V_46:
F_4 ( V_39 ) ;
V_45:
F_18 ( V_6 ) ;
return F_15 ( V_19 ) ;
}
int
F_19 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_47 * V_48 = V_47 ( V_11 ) ;
struct V_49 * V_50 = V_49 ( V_17 -> V_20 ) ;
struct V_51 * V_52 ;
int V_19 ;
V_19 = V_48 -> V_53 ( V_11 ) ;
if ( V_19 )
return V_19 ;
F_20 ( V_11 ) ;
F_21 (connector, &dev->mode_config.connector_list, head) {
struct V_54 * V_55 = V_54 ( V_52 ) ;
if ( V_50 && V_55 -> V_56 . V_57 != V_58 ) {
F_22 ( V_50 -> V_59 , V_55 -> V_56 . line ,
& V_55 -> V_60 ) ;
}
}
return V_19 ;
}
void
F_23 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_47 * V_48 = V_47 ( V_11 ) ;
struct V_49 * V_50 = V_49 ( V_17 -> V_20 ) ;
struct V_51 * V_52 ;
F_21 (connector, &dev->mode_config.connector_list, head) {
struct V_54 * V_55 = V_54 ( V_52 ) ;
if ( V_50 && V_55 -> V_56 . V_57 != V_58 ) {
F_24 ( V_50 -> V_59 , V_55 -> V_56 . line ,
& V_55 -> V_60 ) ;
}
}
F_25 ( V_11 ) ;
V_48 -> V_61 ( V_11 ) ;
}
int
F_26 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_47 * V_48 ;
T_1 V_62 = V_11 -> V_63 -> V_64 >> 8 ;
int V_19 , V_65 ;
V_48 = V_17 -> V_66 = F_16 ( sizeof( * V_48 ) , V_44 ) ;
if ( ! V_48 )
return - V_41 ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_29 ( V_11 ) ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 )
V_65 = 0 ;
else
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_32 )
V_65 = 1 ;
else
V_65 = 2 ;
F_30 ( V_48 -> V_67 , V_65 , L_2 , V_68 ) ;
F_30 ( V_48 -> V_69 , V_65 , L_3 , V_70 ) ;
F_30 ( V_48 -> V_71 , V_65 , L_4 , V_72 ) ;
V_48 -> V_73 =
F_31 ( V_11 , 0 , L_5 , 0 , 128 ) ;
V_48 -> V_74 =
F_31 ( V_11 , 0 , L_6 , 0 , 128 ) ;
if ( V_65 >= 1 ) {
V_48 -> V_75 =
F_31 ( V_11 , 0 , L_7 , 0 , 180 ) ;
V_48 -> V_76 =
F_31 ( V_11 , 0 , L_8 , 0 , 200 ) ;
}
V_11 -> V_77 . V_78 = & V_79 ;
V_11 -> V_77 . V_80 = F_32 ( V_11 -> V_63 , 1 ) ;
V_11 -> V_77 . V_81 = 0 ;
V_11 -> V_77 . V_82 = 0 ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_83 ) {
V_11 -> V_77 . V_84 = 2048 ;
V_11 -> V_77 . V_85 = 2048 ;
} else
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 ) {
V_11 -> V_77 . V_84 = 4096 ;
V_11 -> V_77 . V_85 = 4096 ;
} else {
V_11 -> V_77 . V_84 = 8192 ;
V_11 -> V_77 . V_85 = 8192 ;
}
V_11 -> V_77 . V_86 = 24 ;
V_11 -> V_77 . V_87 = 1 ;
F_33 ( V_11 ) ;
F_25 ( V_11 ) ;
if ( V_88 == 1 ||
( V_88 < 0 && V_62 == V_89 ) ) {
if ( V_17 -> V_90 . V_91 . V_92 ) {
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 )
V_19 = F_34 ( V_11 ) ;
else
V_19 = F_35 ( V_11 ) ;
} else {
V_19 = 0 ;
}
if ( V_19 )
goto V_93;
if ( V_11 -> V_77 . V_94 ) {
V_19 = F_36 ( V_11 , V_11 -> V_77 . V_94 ) ;
if ( V_19 )
goto V_95;
}
F_37 ( V_11 ) ;
}
return 0 ;
V_95:
V_48 -> V_96 ( V_11 ) ;
V_93:
F_38 ( V_11 ) ;
F_39 ( V_11 ) ;
return V_19 ;
}
void
F_40 ( struct V_10 * V_11 )
{
struct V_47 * V_48 = V_47 ( V_11 ) ;
F_41 ( V_11 ) ;
F_42 ( V_11 ) ;
F_38 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_48 -> V_96 )
V_48 -> V_96 ( V_11 ) ;
V_16 ( V_11 ) -> V_66 = NULL ;
F_4 ( V_48 ) ;
}
int
F_43 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_97 * V_98 ;
F_23 ( V_11 ) ;
F_44 ( V_17 , L_9 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_39 ;
V_39 = V_3 ( V_98 -> V_4 ) ;
if ( ! V_39 || ! V_39 -> V_5 )
continue;
F_45 ( V_39 -> V_5 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_99 * V_100 = V_99 ( V_98 ) ;
F_46 ( V_100 -> V_101 . V_5 ) ;
F_45 ( V_100 -> V_101 . V_5 ) ;
}
return 0 ;
}
void
F_47 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_97 * V_98 ;
int V_19 ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_39 ;
V_39 = V_3 ( V_98 -> V_4 ) ;
if ( ! V_39 || ! V_39 -> V_5 )
continue;
F_48 ( V_39 -> V_5 , V_102 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_99 * V_100 = V_99 ( V_98 ) ;
V_19 = F_48 ( V_100 -> V_101 . V_5 , V_102 ) ;
if ( ! V_19 )
V_19 = F_49 ( V_100 -> V_101 . V_5 ) ;
if ( V_19 )
F_11 ( V_17 , L_10 ) ;
}
F_50 ( V_11 , 0 ) ;
F_51 ( V_11 ) ;
F_19 ( V_11 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_99 * V_100 = V_99 ( V_98 ) ;
V_100 -> V_103 . V_28 = 0 ;
}
F_52 ( V_11 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_99 * V_100 = V_99 ( V_98 ) ;
T_1 V_104 = V_100 -> V_101 . V_5 -> V_105 . V_104 ;
V_100 -> V_101 . V_106 ( V_100 , V_104 ) ;
V_100 -> V_101 . V_107 ( V_100 , V_100 -> V_108 ,
V_100 -> V_109 ) ;
}
}
static int
F_53 ( struct V_110 * V_111 ,
struct V_15 * V_112 ,
struct V_15 * V_113 ,
struct V_114 * V_115 ,
struct V_116 * * V_117 )
{
struct V_118 * V_119 = V_111 -> V_120 ;
struct V_16 * V_17 = V_111 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
unsigned long V_121 ;
int V_19 ;
F_54 ( & V_11 -> V_122 , V_121 ) ;
F_55 ( & V_115 -> V_123 , & V_119 -> V_124 ) ;
F_56 ( & V_11 -> V_122 , V_121 ) ;
V_19 = F_57 ( V_112 -> V_105 . V_125 , V_111 ) ;
if ( V_19 )
goto V_126;
V_19 = F_58 ( V_111 , 3 ) ;
if ( V_19 )
goto V_126;
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_37 ) {
F_59 ( V_111 , V_127 , V_128 , 1 ) ;
F_60 ( V_111 , 0x00000000 ) ;
F_60 ( V_111 , 0x00000000 ) ;
} else {
F_61 ( V_111 , 0 , V_129 , 1 ) ;
F_60 ( V_111 , 0 ) ;
F_62 ( V_111 , 0 , V_130 , 0x0000 ) ;
}
F_63 ( V_111 ) ;
V_19 = F_64 ( V_111 , false , V_117 ) ;
if ( V_19 )
goto V_126;
return 0 ;
V_126:
F_54 ( & V_11 -> V_122 , V_121 ) ;
F_65 ( & V_115 -> V_123 ) ;
F_56 ( & V_11 -> V_122 , V_121 ) ;
return V_19 ;
}
int
F_66 ( struct V_97 * V_98 , struct V_1 * V_4 ,
struct V_131 * V_132 )
{
struct V_10 * V_11 = V_98 -> V_11 ;
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_15 * V_112 = V_3 ( V_98 -> V_4 ) -> V_5 ;
struct V_15 * V_113 = V_3 ( V_4 ) -> V_5 ;
struct V_114 * V_115 ;
struct V_110 * V_111 = NULL ;
struct V_116 * V_120 ;
struct V_133 V_134 [ 2 ] = {
{ . V_105 = & V_112 -> V_105 } ,
{ . V_105 = & V_113 -> V_105 } ,
} ;
struct V_135 V_136 ;
F_67 ( V_137 ) ;
int V_19 ;
if ( ! V_17 -> V_138 )
return - V_139 ;
V_115 = F_16 ( sizeof( * V_115 ) , V_44 ) ;
if ( ! V_115 )
return - V_41 ;
F_68 ( & V_112 -> V_105 . V_140 -> V_141 ) ;
V_120 = V_113 -> V_105 . V_125 ;
if ( V_120 )
V_111 = V_120 -> V_138 ;
if ( ! V_111 )
V_111 = V_17 -> V_138 ;
F_69 ( & V_112 -> V_105 . V_140 -> V_141 ) ;
if ( V_113 != V_112 ) {
V_19 = F_48 ( V_113 , V_102 ) ;
if ( V_19 )
goto V_142;
F_70 ( & V_134 [ 1 ] . V_123 , & V_137 ) ;
}
F_70 ( & V_134 [ 0 ] . V_123 , & V_137 ) ;
F_71 ( & V_111 -> V_143 -> V_144 ) ;
V_19 = F_72 ( & V_136 , & V_137 ) ;
if ( V_19 )
goto V_145;
* V_115 = (struct V_114 )
{ { } , V_132 , V_99 ( V_98 ) -> V_146 ,
V_4 -> V_147 , V_4 -> V_34 [ 0 ] , V_98 -> V_148 , V_98 -> V_149 ,
V_113 -> V_105 . V_104 } ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 >= V_22 ) {
V_19 = F_73 ( V_98 , V_4 , V_111 , 0 ) ;
if ( V_19 )
goto V_150;
} else {
struct V_151 * V_152 = V_151 ( V_11 ) ;
F_74 ( V_113 , & V_152 -> V_153 [ V_99 ( V_98 ) -> V_146 ] ) ;
}
V_19 = F_53 ( V_111 , V_112 , V_113 , V_115 , & V_120 ) ;
F_75 ( & V_111 -> V_143 -> V_144 ) ;
if ( V_19 )
goto V_150;
V_98 -> V_4 = V_4 ;
F_76 ( & V_136 , & V_137 , V_120 ) ;
if ( V_112 != V_113 )
F_45 ( V_112 ) ;
F_77 ( & V_120 ) ;
return 0 ;
V_150:
F_78 ( & V_136 , & V_137 ) ;
V_145:
F_75 ( & V_111 -> V_143 -> V_144 ) ;
if ( V_112 != V_113 )
F_45 ( V_113 ) ;
V_142:
F_4 ( V_115 ) ;
return V_19 ;
}
int
F_79 ( struct V_110 * V_111 ,
struct V_114 * V_154 )
{
struct V_118 * V_119 = V_111 -> V_120 ;
struct V_16 * V_17 = V_111 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
struct V_114 * V_115 ;
unsigned long V_121 ;
F_54 ( & V_11 -> V_122 , V_121 ) ;
if ( F_80 ( & V_119 -> V_124 ) ) {
F_11 ( V_17 , L_11 ) ;
F_56 ( & V_11 -> V_122 , V_121 ) ;
return - V_30 ;
}
V_115 = F_81 ( & V_119 -> V_124 , struct V_114 , V_123 ) ;
if ( V_115 -> V_132 )
F_82 ( V_11 , - 1 , V_115 -> V_132 ) ;
F_65 ( & V_115 -> V_123 ) ;
if ( V_154 )
* V_154 = * V_115 ;
F_4 ( V_115 ) ;
F_56 ( & V_11 -> V_122 , V_121 ) ;
return 0 ;
}
int
F_83 ( void * V_155 )
{
struct V_110 * V_111 = V_155 ;
struct V_16 * V_17 = V_111 -> V_17 ;
struct V_114 V_156 ;
if ( ! F_79 ( V_111 , & V_156 ) ) {
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 ) {
F_84 ( V_17 -> V_11 , V_156 . V_98 , V_156 . V_104 +
V_156 . V_149 * V_156 . V_157 +
V_156 . V_148 * V_156 . V_158 / 8 ) ;
}
}
return 0 ;
}
int
F_85 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_159 * args )
{
struct V_15 * V_105 ;
int V_19 ;
args -> V_157 = F_86 ( args -> V_160 * ( args -> V_158 / 8 ) , 256 ) ;
args -> V_161 = args -> V_157 * args -> V_162 ;
args -> V_161 = F_86 ( args -> V_161 , V_163 ) ;
V_19 = F_87 ( V_11 , args -> V_161 , 0 , V_164 , 0 , 0 , & V_105 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_6 ( V_8 , V_105 -> V_6 , & args -> V_9 ) ;
F_2 ( V_105 -> V_6 ) ;
return V_19 ;
}
int
F_88 ( struct V_7 * V_8 , struct V_10 * V_11 ,
T_2 V_9 )
{
return F_89 ( V_8 , V_9 ) ;
}
int
F_90 ( struct V_7 * V_8 ,
struct V_10 * V_11 ,
T_2 V_9 , T_3 * V_165 )
{
struct V_40 * V_6 ;
V_6 = F_14 ( V_11 , V_8 , V_9 ) ;
if ( V_6 ) {
struct V_15 * V_105 = V_6 -> V_166 ;
* V_165 = V_105 -> V_105 . V_167 ;
F_2 ( V_6 ) ;
return 0 ;
}
return - V_43 ;
}
