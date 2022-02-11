static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static void F_2 ( struct V_1 * V_1 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
F_4 ( L_1 ,
V_5 [ V_4 ] . V_6 , V_5 [ V_4 ] . V_7 ,
F_5 ( V_5 [ V_4 ] . V_6 ) ) ;
}
}
int F_6 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_9 -> V_13 ;
struct V_14 * V_15 = V_12 -> V_16 -> V_15 ;
int V_17 = ( V_18 ) V_12 -> V_19 -> V_20 ;
struct V_2 * V_3 ;
struct V_1 * V_1 ;
int V_4 ;
V_4 = 0 ;
F_7 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_4 == V_17 )
break;
V_4 ++ ;
}
if ( ! V_3 )
return 0 ;
V_1 = F_1 ( V_3 ) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
F_8 ( V_9 , L_2 ,
V_5 [ V_4 ] . V_7 , V_5 [ V_4 ] . V_6 ,
F_5 ( V_5 [ V_4 ] . V_6 ) ) ;
}
return 0 ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_10 ( V_3 ) ;
}
static T_1 F_11 ( T_1 V_21 )
{
static const T_1 V_22 = 64 ;
static const T_1 V_23 = 6 ;
switch ( V_21 ) {
case V_24 :
case V_25 :
return V_22 - 2 * V_23 ;
case V_26 :
return V_22 - 14 ;
case V_27 :
case V_28 :
default:
return V_22 - 3 * V_23 ;
}
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_29 * V_30 ;
F_13 (connector, crtc->dev) {
if ( V_30 -> V_31 -> V_3 == V_3 ) {
struct V_32 * V_33 = V_30 -> V_33 ;
struct V_34 * V_34 =
F_14 ( V_33 ) ;
return V_34 -> V_35 ;
}
}
return - 1 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_36 * V_31 = V_3 -> V_31 ;
struct V_37 * V_38 = & V_31 -> V_39 ;
bool V_40 = V_38 -> V_41 & V_42 ;
T_1 V_43 = ( V_38 -> V_44 >> ( V_40 ? 1 : 0 ) ) ;
T_1 V_21 = V_27 ;
bool V_45 = false ;
int V_35 = F_12 ( V_3 ) ;
if ( V_45 ) {
F_4 ( L_3 , F_16 ( V_3 ) ) ;
F_2 ( V_1 ) ;
}
F_17 ( V_46 , 0 ) ;
F_17 ( V_46 , V_47 | V_48 ) ;
F_17 ( V_46 , 0 ) ;
F_17 ( V_49 ,
F_18 ( V_38 -> V_50 - V_38 -> V_51 ,
V_52 ) |
F_18 ( V_38 -> V_51 - V_38 -> V_53 ,
V_54 ) ) ;
F_17 ( V_55 ,
F_18 ( V_38 -> V_53 - V_38 -> V_56 ,
V_57 ) |
F_18 ( V_38 -> V_56 , V_58 ) ) ;
if ( V_40 ) {
F_17 ( V_59 ,
F_18 ( V_38 -> V_60 - V_38 -> V_61 - 1 ,
V_62 ) |
F_18 ( V_38 -> V_61 - V_38 -> V_63 ,
V_64 ) ) ;
F_17 ( V_65 ,
F_18 ( V_38 -> V_63 - V_38 -> V_44 ,
V_66 ) |
F_18 ( V_43 , V_67 ) ) ;
}
F_17 ( V_68 , V_38 -> V_56 ) ;
F_17 ( V_69 ,
V_70 |
( V_40 ? V_71 : 0 ) ) ;
F_17 ( V_46 ,
F_18 ( V_21 , V_72 ) |
F_18 ( F_11 ( V_21 ) ,
V_73 ) |
V_74 |
V_75 |
V_76 |
F_18 ( V_35 , V_77 ) |
V_47 |
V_48 ) ;
if ( V_45 ) {
F_4 ( L_4 , F_16 ( V_3 ) ) ;
F_2 ( V_1 ) ;
}
}
static void F_19 ( struct V_14 * V_15 )
{
struct V_78 * V_79 = F_20 ( V_15 ) ;
F_21 ( ( F_22 ( V_80 ) & V_81 ) !=
V_81 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_78 * V_79 = F_20 ( V_15 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_82 = V_1 -> V_83 ;
int V_84 ;
F_19 ( V_15 ) ;
F_17 ( V_69 ,
F_5 ( V_69 ) & ~ V_85 ) ;
V_84 = F_24 ( ! ( F_5 ( V_69 ) & V_85 ) , 1 ) ;
F_25 ( V_84 , L_5 ) ;
if ( F_22 ( F_26 ( V_82 ) ) &
V_86 ) {
F_27 ( F_26 ( V_82 ) ,
V_87 ) ;
F_27 ( F_26 ( V_82 ) , 0 ) ;
}
F_21 ( F_22 ( F_26 ( V_82 ) ) & V_87 ) ;
F_21 ( F_28 ( F_22 ( F_29 ( V_82 ) ) ,
V_88 ) !=
V_89 ) ;
F_21 ( ( F_22 ( F_29 ( V_82 ) ) &
( V_90 | V_91 ) ) !=
V_91 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_78 * V_79 = F_20 ( V_15 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_36 * V_31 = V_3 -> V_31 ;
struct V_37 * V_38 = & V_31 -> V_39 ;
F_19 ( V_15 ) ;
F_27 ( F_26 ( V_1 -> V_83 ) ,
F_18 ( V_38 -> V_56 , V_92 ) |
F_18 ( V_38 -> V_44 , V_93 ) |
V_86 ) ;
F_17 ( V_69 ,
F_5 ( V_69 ) | V_85 ) ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_36 * V_31 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_78 * V_79 = F_20 ( V_15 ) ;
struct V_94 * V_95 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_96 = 0 ;
if ( F_32 ( V_31 -> V_31 , V_3 ) > 1 )
return - V_97 ;
F_33 (plane, state) {
struct V_98 * V_99 =
V_31 -> V_31 -> V_100 [ F_34 ( V_95 ) ] ;
if ( ! V_99 )
V_99 = V_95 -> V_31 ;
V_96 += F_35 ( V_99 ) ;
}
V_96 ++ ;
if ( ! V_1 -> V_101 || V_96 > V_1 -> V_102 ) {
V_1 -> V_101 = ( ( T_1 V_103 * ) V_79 -> V_104 -> V_101 +
V_105 ) ;
V_1 -> V_102 = ( ( V_106 >> 2 ) -
V_105 ) ;
if ( V_96 > V_1 -> V_102 ) {
F_36 ( L_6 ,
V_96 , V_1 -> V_102 ) ;
return - V_97 ;
}
}
return 0 ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_36 * V_107 )
{
struct V_14 * V_15 = V_3 -> V_15 ;
struct V_78 * V_79 = F_20 ( V_15 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_94 * V_95 ;
bool V_45 = false ;
T_1 V_103 * V_108 = V_1 -> V_101 ;
if ( V_45 ) {
F_4 ( L_7 , F_16 ( V_3 ) ) ;
F_38 ( V_15 ) ;
}
F_39 (plane, crtc) {
V_108 += F_40 ( V_95 , V_108 ) ;
}
if ( V_108 == V_1 -> V_101 ) {
F_41 ( V_109 , V_79 -> V_104 -> V_101 ) ;
F_27 ( F_42 ( V_1 -> V_83 ) , 0 ) ;
} else {
F_41 ( V_109 , V_108 ) ;
V_108 ++ ;
F_27 ( F_42 ( V_1 -> V_83 ) ,
( T_1 V_103 * ) V_1 -> V_101 -
( T_1 V_103 * ) V_79 -> V_104 -> V_101 ) ;
V_1 -> V_102 -= ( V_108 - V_1 -> V_101 ) ;
V_1 -> V_101 = V_108 ;
}
if ( V_45 ) {
F_4 ( L_8 , F_16 ( V_3 ) ) ;
F_38 ( V_15 ) ;
}
if ( V_3 -> V_31 -> V_110 ) {
unsigned long V_41 ;
V_3 -> V_31 -> V_110 -> V_111 = F_16 ( V_3 ) ;
F_43 ( F_44 ( V_3 ) != 0 ) ;
F_45 ( & V_15 -> V_112 , V_41 ) ;
V_1 -> V_110 = V_3 -> V_31 -> V_110 ;
F_46 ( & V_15 -> V_112 , V_41 ) ;
V_3 -> V_31 -> V_110 = NULL ;
}
}
int F_47 ( struct V_14 * V_15 , unsigned int V_113 )
{
struct V_78 * V_79 = F_20 ( V_15 ) ;
struct V_1 * V_1 = V_79 -> V_3 [ V_113 ] ;
F_17 ( V_114 , V_115 ) ;
return 0 ;
}
void F_48 ( struct V_14 * V_15 , unsigned int V_113 )
{
struct V_78 * V_79 = F_20 ( V_15 ) ;
struct V_1 * V_1 = V_79 -> V_3 [ V_113 ] ;
F_17 ( V_114 , 0 ) ;
}
static void F_49 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_116 ;
struct V_14 * V_15 = V_3 -> V_15 ;
unsigned long V_41 ;
F_45 ( & V_15 -> V_112 , V_41 ) ;
if ( V_1 -> V_110 ) {
F_50 ( V_3 , V_1 -> V_110 ) ;
V_1 -> V_110 = NULL ;
}
F_46 ( & V_15 -> V_112 , V_41 ) ;
}
static T_2 F_51 ( int V_117 , void * V_20 )
{
struct V_1 * V_1 = V_20 ;
T_1 V_118 = F_5 ( V_119 ) ;
T_2 V_84 = V_120 ;
if ( V_118 & V_115 ) {
F_17 ( V_119 , V_115 ) ;
F_52 ( & V_1 -> V_116 ) ;
F_49 ( V_1 ) ;
V_84 = V_121 ;
}
return V_84 ;
}
void F_53 ( struct V_2 * V_3 , struct V_122 * V_123 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_3 -> V_15 ;
unsigned long V_41 ;
F_45 ( & V_15 -> V_112 , V_41 ) ;
if ( V_1 -> V_110 && V_1 -> V_110 -> V_116 . V_124 == V_123 ) {
V_1 -> V_110 -> V_116 . V_125 ( & V_1 -> V_110 -> V_116 ) ;
F_54 ( V_3 ) ;
V_1 -> V_110 = NULL ;
}
F_46 ( & V_15 -> V_112 , V_41 ) ;
}
static void F_55 ( struct V_14 * V_126 ,
struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_32 * V_33 ;
F_56 (encoder, drm) {
struct V_34 * V_34 = F_14 ( V_33 ) ;
if ( V_34 -> type == V_1 -> V_20 -> V_127 ) {
V_34 -> V_35 = 0 ;
V_33 -> V_128 |= F_57 ( V_3 ) ;
} else if ( V_34 -> type == V_1 -> V_20 -> V_129 ) {
V_34 -> V_35 = 1 ;
V_33 -> V_128 |= F_57 ( V_3 ) ;
}
}
}
static int F_58 ( struct V_130 * V_15 , struct V_130 * V_131 , void * V_20 )
{
struct V_132 * V_133 = F_59 ( V_15 ) ;
struct V_14 * V_126 = F_60 ( V_131 ) ;
struct V_78 * V_79 = F_20 ( V_126 ) ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
struct V_94 * V_134 , * V_135 ;
const struct V_136 * V_137 ;
int V_84 ;
V_1 = F_61 ( V_15 , sizeof( * V_1 ) , V_138 ) ;
if ( ! V_1 )
return - V_139 ;
V_3 = & V_1 -> V_116 ;
V_137 = F_62 ( V_140 , V_15 ) ;
if ( ! V_137 )
return - V_141 ;
V_1 -> V_20 = V_137 -> V_20 ;
V_1 -> V_142 = F_63 ( V_133 , 0 ) ;
if ( F_64 ( V_1 -> V_142 ) )
return F_65 ( V_1 -> V_142 ) ;
V_134 = F_66 ( V_126 , V_143 ) ;
if ( F_64 ( V_134 ) ) {
F_67 ( V_15 , L_9 ) ;
V_84 = F_65 ( V_134 ) ;
goto V_144;
}
V_135 = F_66 ( V_126 , V_145 ) ;
if ( F_64 ( V_135 ) ) {
F_67 ( V_15 , L_10 ) ;
V_84 = F_65 ( V_135 ) ;
goto V_146;
}
F_68 ( V_126 , V_3 , V_134 , V_135 ,
& V_147 ) ;
F_69 ( V_3 , & V_148 ) ;
V_134 -> V_3 = V_3 ;
V_135 -> V_3 = V_3 ;
V_79 -> V_3 [ F_16 ( V_3 ) ] = V_1 ;
V_1 -> V_83 = V_1 -> V_20 -> V_149 ;
F_17 ( V_114 , 0 ) ;
F_17 ( V_119 , V_115 ) ;
V_84 = F_70 ( V_15 , F_71 ( V_133 , 0 ) ,
F_51 , 0 , L_11 , V_1 ) ;
if ( V_84 )
goto V_150;
F_55 ( V_126 , V_3 ) ;
F_72 ( V_133 , V_1 ) ;
return 0 ;
V_150:
V_135 -> V_151 -> V_125 ( V_135 ) ;
V_146:
V_134 -> V_151 -> V_125 ( V_134 ) ;
V_144:
return V_84 ;
}
static void F_73 ( struct V_130 * V_15 , struct V_130 * V_131 ,
void * V_20 )
{
struct V_132 * V_133 = F_59 ( V_15 ) ;
struct V_1 * V_1 = F_60 ( V_15 ) ;
F_9 ( & V_1 -> V_116 ) ;
F_17 ( V_114 , 0 ) ;
F_72 ( V_133 , NULL ) ;
}
static int F_74 ( struct V_132 * V_133 )
{
return F_75 ( & V_133 -> V_15 , & V_152 ) ;
}
static int F_76 ( struct V_132 * V_133 )
{
F_77 ( & V_133 -> V_15 , & V_152 ) ;
return 0 ;
}
