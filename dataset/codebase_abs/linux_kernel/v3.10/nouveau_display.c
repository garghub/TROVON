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
struct V_47 * V_48 = V_47 ( V_17 -> V_20 ) ;
struct V_49 * V_50 ;
int V_19 ;
V_19 = V_46 -> V_51 ( V_11 ) ;
if ( V_19 )
return V_19 ;
F_20 ( V_11 ) ;
F_21 (connector, &dev->mode_config.connector_list, head) {
struct V_52 * V_53 = V_52 ( V_50 ) ;
if ( V_48 && V_53 -> V_54 . V_55 != V_56 ) {
F_22 ( V_48 -> V_57 , V_53 -> V_54 . line ,
& V_53 -> V_58 ) ;
}
}
return V_19 ;
}
void
F_23 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_45 * V_46 = V_45 ( V_11 ) ;
struct V_47 * V_48 = V_47 ( V_17 -> V_20 ) ;
struct V_49 * V_50 ;
F_21 (connector, &dev->mode_config.connector_list, head) {
struct V_52 * V_53 = V_52 ( V_50 ) ;
if ( V_48 && V_53 -> V_54 . V_55 != V_56 ) {
F_24 ( V_48 -> V_57 , V_53 -> V_54 . line ,
& V_53 -> V_58 ) ;
}
}
F_25 ( V_11 ) ;
V_46 -> V_59 ( V_11 ) ;
}
int
F_26 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_45 * V_46 ;
T_1 V_60 = V_11 -> V_61 -> V_62 >> 8 ;
int V_19 , V_63 ;
V_46 = V_17 -> V_64 = F_16 ( sizeof( * V_46 ) , V_43 ) ;
if ( ! V_46 )
return - V_44 ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_29 ( V_11 ) ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 )
V_63 = 0 ;
else
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_32 )
V_63 = 1 ;
else
V_63 = 2 ;
F_30 ( V_46 -> V_65 , V_63 , L_2 , V_66 ) ;
F_30 ( V_46 -> V_67 , V_63 , L_3 , V_68 ) ;
F_30 ( V_46 -> V_69 , V_63 , L_4 , V_70 ) ;
V_46 -> V_71 =
F_31 ( V_11 , 0 , L_5 , 0 , 128 ) ;
V_46 -> V_72 =
F_31 ( V_11 , 0 , L_6 , 0 , 128 ) ;
if ( V_63 >= 1 ) {
V_46 -> V_73 =
F_31 ( V_11 , 0 , L_7 , 0 , 180 ) ;
V_46 -> V_74 =
F_31 ( V_11 , 0 , L_8 , 0 , 200 ) ;
}
V_11 -> V_75 . V_76 = & V_77 ;
V_11 -> V_75 . V_78 = F_32 ( V_11 -> V_61 , 1 ) ;
V_11 -> V_75 . V_79 = 0 ;
V_11 -> V_75 . V_80 = 0 ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_81 ) {
V_11 -> V_75 . V_82 = 2048 ;
V_11 -> V_75 . V_83 = 2048 ;
} else
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 ) {
V_11 -> V_75 . V_82 = 4096 ;
V_11 -> V_75 . V_83 = 4096 ;
} else {
V_11 -> V_75 . V_82 = 8192 ;
V_11 -> V_75 . V_83 = 8192 ;
}
V_11 -> V_75 . V_84 = 24 ;
V_11 -> V_75 . V_85 = 1 ;
F_33 ( V_11 ) ;
F_25 ( V_11 ) ;
if ( V_86 == 1 ||
( V_86 < 0 && V_60 == V_87 ) ) {
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 )
V_19 = F_34 ( V_11 ) ;
else
V_19 = F_35 ( V_11 ) ;
if ( V_19 )
goto V_88;
if ( V_11 -> V_75 . V_89 ) {
V_19 = F_36 ( V_11 , V_11 -> V_75 . V_89 ) ;
if ( V_19 )
goto V_90;
}
F_37 ( V_11 ) ;
}
return 0 ;
V_90:
V_46 -> V_91 ( V_11 ) ;
V_88:
F_38 ( V_11 ) ;
F_39 ( V_11 ) ;
return V_19 ;
}
void
F_40 ( struct V_10 * V_11 )
{
struct V_45 * V_46 = V_45 ( V_11 ) ;
F_41 ( V_11 ) ;
F_42 ( V_11 ) ;
F_38 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_46 -> V_91 )
V_46 -> V_91 ( V_11 ) ;
V_16 ( V_11 ) -> V_64 = NULL ;
F_4 ( V_46 ) ;
}
int
F_43 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_92 * V_93 ;
F_23 ( V_11 ) ;
F_44 ( V_17 , L_9 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_39 ;
V_39 = V_3 ( V_93 -> V_4 ) ;
if ( ! V_39 || ! V_39 -> V_5 )
continue;
F_45 ( V_39 -> V_5 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_94 * V_95 = V_94 ( V_93 ) ;
F_46 ( V_95 -> V_96 . V_5 ) ;
F_45 ( V_95 -> V_96 . V_5 ) ;
}
return 0 ;
}
void
F_47 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_92 * V_93 ;
int V_19 ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_3 * V_39 ;
V_39 = V_3 ( V_93 -> V_4 ) ;
if ( ! V_39 || ! V_39 -> V_5 )
continue;
F_48 ( V_39 -> V_5 , V_97 ) ;
}
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_94 * V_95 = V_94 ( V_93 ) ;
V_19 = F_48 ( V_95 -> V_96 . V_5 , V_97 ) ;
if ( ! V_19 )
V_19 = F_49 ( V_95 -> V_96 . V_5 ) ;
if ( V_19 )
F_11 ( V_17 , L_10 ) ;
}
F_50 ( V_11 , 0 ) ;
F_51 ( V_11 ) ;
F_19 ( V_11 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_94 * V_95 = V_94 ( V_93 ) ;
V_95 -> V_98 . V_28 = 0 ;
}
F_52 ( V_11 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, head) {
struct V_94 * V_95 = V_94 ( V_93 ) ;
T_1 V_99 = V_95 -> V_96 . V_5 -> V_100 . V_99 ;
V_95 -> V_96 . V_101 ( V_95 , V_99 ) ;
V_95 -> V_96 . V_102 ( V_95 , V_95 -> V_103 ,
V_95 -> V_104 ) ;
}
}
static int
F_53 ( struct V_15 * V_105 ,
struct V_15 * V_106 )
{
int V_19 ;
V_19 = F_48 ( V_106 , V_97 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_54 ( & V_106 -> V_100 , false , false , false , 0 ) ;
if ( V_19 )
goto V_107;
if ( F_55 ( V_105 != V_106 ) ) {
V_19 = F_54 ( & V_105 -> V_100 , false , false , false , 0 ) ;
if ( V_19 )
goto V_108;
}
return 0 ;
V_108:
F_56 ( & V_106 -> V_100 ) ;
V_107:
F_45 ( V_106 ) ;
return V_19 ;
}
static void
F_57 ( struct V_15 * V_105 ,
struct V_15 * V_106 ,
struct V_109 * V_110 )
{
F_58 ( V_106 , V_110 ) ;
F_56 ( & V_106 -> V_100 ) ;
if ( F_55 ( V_105 != V_106 ) ) {
F_58 ( V_105 , V_110 ) ;
F_56 ( & V_105 -> V_100 ) ;
}
F_45 ( V_105 ) ;
}
static int
F_59 ( struct V_111 * V_112 ,
struct V_15 * V_105 ,
struct V_15 * V_106 ,
struct V_113 * V_114 ,
struct V_109 * * V_115 )
{
struct V_116 * V_117 = V_112 -> V_110 ;
struct V_16 * V_17 = V_112 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
unsigned long V_118 ;
int V_19 ;
F_60 ( & V_11 -> V_119 , V_118 ) ;
F_61 ( & V_114 -> V_120 , & V_117 -> V_121 ) ;
F_62 ( & V_11 -> V_119 , V_118 ) ;
V_19 = F_63 ( V_105 -> V_100 . V_122 , V_112 ) ;
if ( V_19 )
goto V_107;
V_19 = F_64 ( V_112 , 3 ) ;
if ( V_19 )
goto V_107;
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_37 ) {
F_65 ( V_112 , V_123 , V_124 , 1 ) ;
F_66 ( V_112 , 0x00000000 ) ;
F_66 ( V_112 , 0x00000000 ) ;
} else {
F_67 ( V_112 , 0 , V_125 , 1 ) ;
F_66 ( V_112 , 0 ) ;
F_68 ( V_112 , 0 , V_126 , 0x0000 ) ;
}
F_69 ( V_112 ) ;
V_19 = F_70 ( V_112 , false , V_115 ) ;
if ( V_19 )
goto V_107;
return 0 ;
V_107:
F_60 ( & V_11 -> V_119 , V_118 ) ;
F_71 ( & V_114 -> V_120 ) ;
F_62 ( & V_11 -> V_119 , V_118 ) ;
return V_19 ;
}
int
F_72 ( struct V_92 * V_93 , struct V_1 * V_4 ,
struct V_127 * V_128 )
{
struct V_10 * V_11 = V_93 -> V_11 ;
struct V_16 * V_17 = V_16 ( V_11 ) ;
struct V_15 * V_105 = V_3 ( V_93 -> V_4 ) -> V_5 ;
struct V_15 * V_106 = V_3 ( V_4 ) -> V_5 ;
struct V_113 * V_114 ;
struct V_111 * V_112 = NULL ;
struct V_109 * V_110 ;
int V_19 ;
if ( ! V_17 -> V_129 )
return - V_130 ;
V_114 = F_16 ( sizeof( * V_114 ) , V_43 ) ;
if ( ! V_114 )
return - V_44 ;
V_19 = F_53 ( V_105 , V_106 ) ;
if ( V_19 )
goto V_131;
* V_114 = (struct V_113 )
{ { } , V_128 , V_94 ( V_93 ) -> V_132 ,
V_4 -> V_133 , V_4 -> V_34 [ 0 ] , V_93 -> V_134 , V_93 -> V_135 ,
V_106 -> V_100 . V_99 } ;
V_110 = V_106 -> V_100 . V_122 ;
if ( V_110 )
V_112 = V_110 -> V_129 ;
if ( ! V_112 )
V_112 = V_17 -> V_129 ;
F_73 ( & V_112 -> V_136 -> V_137 ) ;
if ( F_9 ( V_17 -> V_20 ) -> V_21 >= V_22 ) {
V_19 = F_74 ( V_93 , V_4 , V_112 , 0 ) ;
if ( V_19 ) {
F_75 ( & V_112 -> V_136 -> V_137 ) ;
goto V_108;
}
}
V_19 = F_59 ( V_112 , V_105 , V_106 , V_114 , & V_110 ) ;
F_75 ( & V_112 -> V_136 -> V_137 ) ;
if ( V_19 )
goto V_108;
V_93 -> V_4 = V_4 ;
F_57 ( V_105 , V_106 , V_110 ) ;
F_76 ( & V_110 ) ;
return 0 ;
V_108:
F_57 ( V_105 , V_106 , NULL ) ;
V_131:
F_4 ( V_114 ) ;
return V_19 ;
}
int
F_77 ( struct V_111 * V_112 ,
struct V_113 * V_138 )
{
struct V_116 * V_117 = V_112 -> V_110 ;
struct V_16 * V_17 = V_112 -> V_17 ;
struct V_10 * V_11 = V_17 -> V_11 ;
struct V_113 * V_114 ;
unsigned long V_118 ;
F_60 ( & V_11 -> V_119 , V_118 ) ;
if ( F_78 ( & V_117 -> V_121 ) ) {
F_11 ( V_17 , L_11 ) ;
F_62 ( & V_11 -> V_119 , V_118 ) ;
return - V_30 ;
}
V_114 = F_79 ( & V_117 -> V_121 , struct V_113 , V_120 ) ;
if ( V_114 -> V_128 )
F_80 ( V_11 , - 1 , V_114 -> V_128 ) ;
F_71 ( & V_114 -> V_120 ) ;
if ( V_138 )
* V_138 = * V_114 ;
F_4 ( V_114 ) ;
F_62 ( & V_11 -> V_119 , V_118 ) ;
return 0 ;
}
int
F_81 ( void * V_139 )
{
struct V_111 * V_112 = V_139 ;
struct V_16 * V_17 = V_112 -> V_17 ;
struct V_113 V_140 ;
if ( ! F_77 ( V_112 , & V_140 ) ) {
if ( F_9 ( V_17 -> V_20 ) -> V_21 < V_22 ) {
F_82 ( V_17 -> V_11 , V_140 . V_93 , V_140 . V_99 +
V_140 . V_135 * V_140 . V_141 +
V_140 . V_134 * V_140 . V_142 / 8 ) ;
}
}
return 0 ;
}
int
F_83 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_143 * args )
{
struct V_15 * V_100 ;
int V_19 ;
args -> V_141 = F_84 ( args -> V_144 * ( args -> V_142 / 8 ) , 256 ) ;
args -> V_145 = args -> V_141 * args -> V_146 ;
args -> V_145 = F_84 ( args -> V_145 , V_147 ) ;
V_19 = F_85 ( V_11 , args -> V_145 , 0 , V_148 , 0 , 0 , & V_100 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_6 ( V_8 , V_100 -> V_6 , & args -> V_9 ) ;
F_2 ( V_100 -> V_6 ) ;
return V_19 ;
}
int
F_86 ( struct V_7 * V_8 , struct V_10 * V_11 ,
T_2 V_9 )
{
return F_87 ( V_8 , V_9 ) ;
}
int
F_88 ( struct V_7 * V_8 ,
struct V_10 * V_11 ,
T_2 V_9 , T_3 * V_149 )
{
struct V_40 * V_6 ;
V_6 = F_14 ( V_11 , V_8 , V_9 ) ;
if ( V_6 ) {
struct V_15 * V_100 = V_6 -> V_150 ;
* V_149 = V_100 -> V_100 . V_151 ;
F_2 ( V_6 ) ;
return 0 ;
}
return - V_42 ;
}
