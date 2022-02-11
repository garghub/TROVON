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
static void
F_7 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
int V_12 ;
if ( V_9 -> V_10 ) {
for ( V_12 = 0 ; V_12 < V_5 -> V_13 . V_14 ; V_12 ++ )
F_8 ( NULL , & V_9 -> V_10 [ V_12 ] ) ;
F_9 ( V_9 -> V_10 ) ;
V_9 -> V_10 = NULL ;
}
F_10 ( V_5 ) ;
}
static int
F_11 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_15 * V_16 = V_15 ( V_4 -> V_17 ) ;
int V_18 , V_12 ;
V_9 -> V_10 = F_12 ( V_5 -> V_13 . V_14 *
sizeof( * V_9 -> V_10 ) , V_19 ) ;
if ( ! V_9 -> V_10 )
return - V_20 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_13 . V_14 ; V_12 ++ ) {
V_18 = F_13 ( V_16 -> V_10 , V_12 ,
F_1 ,
V_4 , & V_9 -> V_10 [ V_12 ] ) ;
if ( V_18 ) {
F_7 ( V_5 ) ;
return V_18 ;
}
}
V_18 = F_14 ( V_5 , V_5 -> V_13 . V_14 ) ;
if ( V_18 ) {
F_7 ( V_5 ) ;
return V_18 ;
}
return 0 ;
}
static void
F_15 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_23 ( V_22 ) ;
if ( V_24 -> V_25 )
F_16 ( & V_24 -> V_25 -> V_26 ) ;
F_17 ( V_22 ) ;
F_9 ( V_24 ) ;
}
static int
F_18 ( struct V_21 * V_22 ,
struct V_27 * V_28 ,
unsigned int * V_29 )
{
struct V_23 * V_24 = V_23 ( V_22 ) ;
return F_19 ( V_28 , & V_24 -> V_25 -> V_26 , V_29 ) ;
}
int
F_20 ( struct V_7 * V_5 ,
struct V_23 * V_30 ,
struct V_31 * V_32 ,
struct V_33 * V_25 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_21 * V_24 = & V_30 -> V_34 ;
int V_18 ;
F_21 ( V_24 , V_32 ) ;
V_30 -> V_25 = V_25 ;
if ( F_22 ( V_4 -> V_17 ) -> V_35 >= V_36 ) {
T_1 V_37 = F_23 ( V_25 ) ;
if ( V_37 == 0x7a00 ||
V_37 == 0xfe00 )
V_30 -> V_38 = V_39 ;
else
if ( V_37 == 0x7000 )
V_30 -> V_38 = V_40 ;
else
V_30 -> V_38 = V_41 ;
switch ( V_24 -> V_42 ) {
case 8 : V_30 -> V_43 = 0x1e00 ; break;
case 15 : V_30 -> V_43 = 0xe900 ; break;
case 16 : V_30 -> V_43 = 0xe800 ; break;
case 24 :
case 32 : V_30 -> V_43 = 0xcf00 ; break;
case 30 : V_30 -> V_43 = 0xd100 ; break;
default:
F_24 ( V_4 , L_1 , V_24 -> V_42 ) ;
return - V_44 ;
}
if ( V_25 -> V_37 & V_45 ) {
F_24 ( V_4 , L_2 ) ;
return - V_44 ;
}
if ( F_22 ( V_4 -> V_17 ) -> V_46 == 0x50 )
V_30 -> V_43 |= ( V_37 << 8 ) ;
if ( ! V_37 ) {
if ( F_22 ( V_4 -> V_17 ) -> V_35 < V_47 )
V_30 -> V_48 = 0x00100000 | V_24 -> V_49 [ 0 ] ;
else
V_30 -> V_48 = 0x01000000 | V_24 -> V_49 [ 0 ] ;
} else {
T_1 V_50 = V_25 -> V_51 ;
if ( F_22 ( V_4 -> V_17 ) -> V_35 >= V_52 )
V_50 >>= 4 ;
V_30 -> V_48 = ( ( V_24 -> V_49 [ 0 ] / 4 ) << 4 ) | V_50 ;
}
}
V_18 = F_25 ( V_5 , V_24 , & V_53 ) ;
if ( V_18 ) {
return V_18 ;
}
return 0 ;
}
static struct V_21 *
F_26 ( struct V_7 * V_5 ,
struct V_27 * V_28 ,
struct V_31 * V_32 )
{
struct V_23 * V_54 ;
struct V_55 * V_26 ;
int V_18 = - V_20 ;
V_26 = F_27 ( V_5 , V_28 , V_32 -> V_56 [ 0 ] ) ;
if ( ! V_26 )
return F_28 ( - V_57 ) ;
V_54 = F_12 ( sizeof( struct V_23 ) , V_19 ) ;
if ( ! V_54 )
goto V_58;
V_18 = F_20 ( V_5 , V_54 , V_32 , F_29 ( V_26 ) ) ;
if ( V_18 )
goto V_59;
return & V_54 -> V_34 ;
V_59:
F_9 ( V_54 ) ;
V_58:
F_30 ( V_26 ) ;
return F_28 ( V_18 ) ;
}
int
F_31 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_60 * V_61 ;
int V_18 ;
V_18 = V_9 -> V_62 ( V_5 ) ;
if ( V_18 )
return V_18 ;
F_32 ( V_5 ) ;
F_33 (connector, &dev->mode_config.connector_list, head) {
struct V_63 * V_64 = V_63 ( V_61 ) ;
if ( V_64 -> V_65 ) F_4 ( V_64 -> V_65 ) ;
}
return V_18 ;
}
void
F_34 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_60 * V_61 ;
F_33 (connector, &dev->mode_config.connector_list, head) {
struct V_63 * V_64 = V_63 ( V_61 ) ;
if ( V_64 -> V_65 ) F_6 ( V_64 -> V_65 ) ;
}
F_35 ( V_5 ) ;
V_9 -> V_66 ( V_5 ) ;
}
int
F_36 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_8 * V_9 ;
int V_18 , V_67 ;
V_9 = V_4 -> V_68 = F_12 ( sizeof( * V_9 ) , V_19 ) ;
if ( ! V_9 )
return - V_20 ;
F_37 ( V_5 ) ;
F_38 ( V_5 ) ;
F_39 ( V_5 ) ;
if ( F_22 ( V_4 -> V_17 ) -> V_35 < V_36 )
V_67 = 0 ;
else
if ( F_22 ( V_4 -> V_17 ) -> V_35 < V_47 )
V_67 = 1 ;
else
V_67 = 2 ;
F_40 ( V_9 -> V_69 , V_67 , L_3 , V_70 ) ;
F_40 ( V_9 -> V_71 , V_67 , L_4 , V_72 ) ;
F_40 ( V_9 -> V_73 , V_67 , L_5 , V_74 ) ;
V_9 -> V_75 =
F_41 ( V_5 , 0 , L_6 , 0 , 128 ) ;
V_9 -> V_76 =
F_41 ( V_5 , 0 , L_7 , 0 , 128 ) ;
if ( V_67 >= 1 ) {
V_9 -> V_77 =
F_41 ( V_5 , 0 , L_8 , 0 , 180 ) ;
V_9 -> V_78 =
F_41 ( V_5 , 0 , L_9 , 0 , 200 ) ;
}
V_5 -> V_13 . V_79 = & V_80 ;
V_5 -> V_13 . V_81 = F_42 ( V_5 -> V_82 , 1 ) ;
V_5 -> V_13 . V_83 = 0 ;
V_5 -> V_13 . V_84 = 0 ;
if ( F_22 ( V_4 -> V_17 ) -> V_35 < V_85 ) {
V_5 -> V_13 . V_86 = 2048 ;
V_5 -> V_13 . V_87 = 2048 ;
} else
if ( F_22 ( V_4 -> V_17 ) -> V_35 < V_36 ) {
V_5 -> V_13 . V_86 = 4096 ;
V_5 -> V_13 . V_87 = 4096 ;
} else {
V_5 -> V_13 . V_86 = 8192 ;
V_5 -> V_13 . V_87 = 8192 ;
}
V_5 -> V_13 . V_88 = 24 ;
V_5 -> V_13 . V_89 = 1 ;
if ( F_22 ( V_4 -> V_17 ) -> V_46 < 0x11 )
V_5 -> V_13 . V_90 = false ;
else
V_5 -> V_13 . V_90 = true ;
F_43 ( V_5 ) ;
F_35 ( V_5 ) ;
if ( V_4 -> V_91 . V_92 . V_93 ) {
if ( F_22 ( V_4 -> V_17 ) -> V_35 < V_36 )
V_18 = F_44 ( V_5 ) ;
else
V_18 = F_45 ( V_5 ) ;
} else {
V_18 = 0 ;
}
if ( V_18 )
goto V_94;
if ( V_5 -> V_13 . V_14 ) {
V_18 = F_11 ( V_5 ) ;
if ( V_18 )
goto V_95;
}
F_46 ( V_5 ) ;
return 0 ;
V_95:
V_9 -> V_96 ( V_5 ) ;
V_94:
F_47 ( V_5 ) ;
F_48 ( V_5 ) ;
return V_18 ;
}
void
F_49 ( struct V_7 * V_5 )
{
struct V_8 * V_9 = V_8 ( V_5 ) ;
F_50 ( V_5 ) ;
F_7 ( V_5 ) ;
F_47 ( V_5 ) ;
F_48 ( V_5 ) ;
if ( V_9 -> V_96 )
V_9 -> V_96 ( V_5 ) ;
V_3 ( V_5 ) -> V_68 = NULL ;
F_9 ( V_9 ) ;
}
int
F_51 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_97 * V_98 ;
F_34 ( V_5 ) ;
F_52 ( V_4 , L_10 ) ;
F_33 (crtc, &dev->mode_config.crtc_list, head) {
struct V_23 * V_54 ;
V_54 = V_23 ( V_98 -> V_24 ) ;
if ( ! V_54 || ! V_54 -> V_25 )
continue;
F_53 ( V_54 -> V_25 ) ;
}
F_33 (crtc, &dev->mode_config.crtc_list, head) {
struct V_99 * V_100 = V_99 ( V_98 ) ;
F_54 ( V_100 -> V_101 . V_25 ) ;
F_53 ( V_100 -> V_101 . V_25 ) ;
}
return 0 ;
}
void
F_55 ( struct V_7 * V_5 )
{
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_97 * V_98 ;
int V_18 ;
F_33 (crtc, &dev->mode_config.crtc_list, head) {
struct V_23 * V_54 ;
V_54 = V_23 ( V_98 -> V_24 ) ;
if ( ! V_54 || ! V_54 -> V_25 )
continue;
F_56 ( V_54 -> V_25 , V_102 ) ;
}
F_33 (crtc, &dev->mode_config.crtc_list, head) {
struct V_99 * V_100 = V_99 ( V_98 ) ;
V_18 = F_56 ( V_100 -> V_101 . V_25 , V_102 ) ;
if ( ! V_18 )
V_18 = F_57 ( V_100 -> V_101 . V_25 ) ;
if ( V_18 )
F_24 ( V_4 , L_11 ) ;
}
}
void
F_58 ( struct V_7 * V_5 )
{
struct V_97 * V_98 ;
F_31 ( V_5 ) ;
F_33 (crtc, &dev->mode_config.crtc_list, head) {
struct V_99 * V_100 = V_99 ( V_98 ) ;
V_100 -> V_103 . V_42 = 0 ;
}
F_59 ( V_5 ) ;
F_33 (crtc, &dev->mode_config.crtc_list, head) {
struct V_99 * V_100 = V_99 ( V_98 ) ;
T_1 V_104 = V_100 -> V_101 . V_25 -> V_105 . V_104 ;
V_100 -> V_101 . V_106 ( V_100 , V_104 ) ;
V_100 -> V_101 . V_107 ( V_100 , V_100 -> V_108 ,
V_100 -> V_109 ) ;
}
}
static int
F_60 ( struct V_110 * V_111 ,
struct V_33 * V_112 ,
struct V_33 * V_113 ,
struct V_114 * V_115 ,
struct V_116 * * V_117 )
{
struct V_118 * V_119 = V_111 -> V_120 ;
struct V_3 * V_4 = V_111 -> V_4 ;
struct V_7 * V_5 = V_4 -> V_5 ;
unsigned long V_121 ;
int V_18 ;
F_61 ( & V_5 -> V_122 , V_121 ) ;
F_62 ( & V_115 -> V_2 , & V_119 -> V_123 ) ;
F_63 ( & V_5 -> V_122 , V_121 ) ;
V_18 = F_64 ( V_112 -> V_105 . V_124 , V_111 ) ;
if ( V_18 )
goto V_125;
V_18 = F_65 ( V_111 , 2 ) ;
if ( V_18 )
goto V_125;
if ( F_22 ( V_4 -> V_17 ) -> V_35 < V_52 )
F_66 ( V_111 , V_126 , V_127 , 1 ) ;
else
F_67 ( V_111 , V_128 , V_127 , 1 ) ;
F_68 ( V_111 , 0x00000000 ) ;
F_69 ( V_111 ) ;
V_18 = F_70 ( V_111 , false , V_117 ) ;
if ( V_18 )
goto V_125;
return 0 ;
V_125:
F_61 ( & V_5 -> V_122 , V_121 ) ;
F_71 ( & V_115 -> V_2 ) ;
F_63 ( & V_5 -> V_122 , V_121 ) ;
return V_18 ;
}
int
F_72 ( struct V_97 * V_98 , struct V_21 * V_24 ,
struct V_129 * V_130 , T_1 V_121 )
{
const int V_131 = ( V_121 & V_132 ) ? 0 : 1 ;
struct V_7 * V_5 = V_98 -> V_5 ;
struct V_3 * V_4 = V_3 ( V_5 ) ;
struct V_33 * V_112 = V_23 ( V_98 -> V_24 ) -> V_25 ;
struct V_33 * V_113 = V_23 ( V_24 ) -> V_25 ;
struct V_114 * V_115 ;
struct V_110 * V_111 = V_4 -> V_133 ;
struct V_116 * V_120 ;
int V_18 ;
if ( ! V_4 -> V_133 )
return - V_134 ;
V_115 = F_12 ( sizeof( * V_115 ) , V_19 ) ;
if ( ! V_115 )
return - V_20 ;
F_73 ( & V_113 -> V_105 . V_135 -> V_136 ) ;
V_120 = F_74 ( V_113 -> V_105 . V_124 ) ;
F_75 ( & V_113 -> V_105 . V_135 -> V_136 ) ;
V_18 = F_64 ( V_120 , V_111 ) ;
F_76 ( & V_120 ) ;
if ( V_18 )
goto V_137;
if ( V_113 != V_112 ) {
V_18 = F_56 ( V_113 , V_102 ) ;
if ( V_18 )
goto V_137;
}
F_77 ( & V_111 -> V_138 -> V_139 ) ;
V_18 = F_78 ( & V_112 -> V_105 , true , false , false , NULL ) ;
if ( V_18 )
goto V_140;
* V_115 = (struct V_114 )
{ { } , V_130 , V_99 ( V_98 ) -> V_141 ,
V_24 -> V_142 , V_24 -> V_49 [ 0 ] , V_98 -> V_143 , V_98 -> V_144 ,
V_113 -> V_105 . V_104 } ;
if ( F_22 ( V_4 -> V_17 ) -> V_35 >= V_36 ) {
V_18 = F_79 ( V_98 , V_24 , V_111 , V_131 ) ;
if ( V_18 )
goto V_145;
} else {
struct V_146 * V_147 = V_146 ( V_5 ) ;
int V_2 = V_99 ( V_98 ) -> V_141 ;
if ( V_131 ) {
V_18 = F_65 ( V_111 , 8 ) ;
if ( V_18 )
goto V_145;
F_66 ( V_111 , V_148 , 0x012c , 1 ) ;
F_68 ( V_111 , 0 ) ;
F_66 ( V_111 , V_148 , 0x0134 , 1 ) ;
F_68 ( V_111 , V_2 ) ;
F_66 ( V_111 , V_148 , 0x0100 , 1 ) ;
F_68 ( V_111 , 0 ) ;
F_66 ( V_111 , V_148 , 0x0130 , 1 ) ;
F_68 ( V_111 , 0 ) ;
}
F_80 ( V_113 , & V_147 -> V_149 [ V_2 ] ) ;
}
V_18 = F_60 ( V_111 , V_112 , V_113 , V_115 , & V_120 ) ;
F_81 ( & V_111 -> V_138 -> V_139 ) ;
if ( V_18 )
goto V_145;
V_98 -> V_24 = V_24 ;
F_82 ( V_112 , V_120 ) ;
F_83 ( & V_112 -> V_105 ) ;
if ( V_112 != V_113 )
F_53 ( V_112 ) ;
F_76 ( & V_120 ) ;
return 0 ;
V_145:
F_83 ( & V_112 -> V_105 ) ;
V_140:
F_81 ( & V_111 -> V_138 -> V_139 ) ;
if ( V_112 != V_113 )
F_53 ( V_113 ) ;
V_137:
F_9 ( V_115 ) ;
return V_18 ;
}
int
F_84 ( struct V_110 * V_111 ,
struct V_114 * V_150 )
{
struct V_118 * V_119 = V_111 -> V_120 ;
struct V_3 * V_4 = V_111 -> V_4 ;
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_114 * V_115 ;
unsigned long V_121 ;
F_61 ( & V_5 -> V_122 , V_121 ) ;
if ( F_85 ( & V_119 -> V_123 ) ) {
F_24 ( V_4 , L_12 ) ;
F_63 ( & V_5 -> V_122 , V_121 ) ;
return - V_44 ;
}
V_115 = F_86 ( & V_119 -> V_123 , struct V_114 , V_2 ) ;
if ( V_115 -> V_130 )
F_87 ( V_5 , V_115 -> V_98 , V_115 -> V_130 ) ;
F_71 ( & V_115 -> V_2 ) ;
if ( V_150 )
* V_150 = * V_115 ;
F_9 ( V_115 ) ;
F_63 ( & V_5 -> V_122 , V_121 ) ;
return 0 ;
}
int
F_88 ( void * V_1 )
{
struct V_110 * V_111 = V_1 ;
struct V_3 * V_4 = V_111 -> V_4 ;
struct V_114 V_151 ;
if ( ! F_84 ( V_111 , & V_151 ) ) {
if ( F_22 ( V_4 -> V_17 ) -> V_35 < V_36 ) {
F_89 ( V_4 -> V_5 , V_151 . V_98 , V_151 . V_104 +
V_151 . V_144 * V_151 . V_152 +
V_151 . V_143 * V_151 . V_153 / 8 ) ;
}
}
return 0 ;
}
int
F_90 ( struct V_27 * V_28 , struct V_7 * V_5 ,
struct V_154 * args )
{
struct V_33 * V_105 ;
int V_18 ;
args -> V_152 = F_91 ( args -> V_155 * ( args -> V_153 / 8 ) , 256 ) ;
args -> V_156 = args -> V_152 * args -> V_157 ;
args -> V_156 = F_91 ( args -> V_156 , V_158 ) ;
V_18 = F_92 ( V_5 , args -> V_156 , 0 , V_159 , 0 , 0 , & V_105 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_19 ( V_28 , & V_105 -> V_26 , & args -> V_29 ) ;
F_16 ( & V_105 -> V_26 ) ;
return V_18 ;
}
int
F_93 ( struct V_27 * V_28 ,
struct V_7 * V_5 ,
T_2 V_29 , T_3 * V_160 )
{
struct V_55 * V_26 ;
V_26 = F_27 ( V_5 , V_28 , V_29 ) ;
if ( V_26 ) {
struct V_33 * V_105 = F_29 ( V_26 ) ;
* V_160 = F_94 ( & V_105 -> V_105 . V_161 ) ;
F_16 ( V_26 ) ;
return 0 ;
}
return - V_57 ;
}
