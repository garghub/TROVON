T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_5 , int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_2 F_5 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
if ( V_2 -> V_8 & V_9 ) {
V_2 -> V_10 = F_6 ( V_2 -> V_11 ) ;
if ( V_2 -> V_12 )
F_7 ( V_2 -> V_12 ) ;
}
if ( V_2 -> V_8 & ( V_13 | V_14 ) ) {
V_2 -> V_15 = true ;
F_8 ( & V_2 -> V_16 ) ;
}
return V_17 ;
}
static T_2 F_9 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
V_2 -> V_8 = F_1 ( V_2 , V_18 ) ;
F_3 ( V_2 , V_2 -> V_8 , V_19 ) ;
F_1 ( V_2 , V_18 ) ;
return V_20 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_21 , V_22 ;
T_1 V_23 , V_24 ;
V_21 = F_11 ( V_2 -> V_25 , 0 ) ;
V_22 = F_11 ( V_2 -> V_25 , V_2 -> V_25 . V_26 - 1 ) ;
V_23 = F_12 ( V_2 -> V_25 , 0 ) ;
V_24 = F_12 ( V_2 -> V_25 , V_2 -> V_25 . V_27 - 1 ) ;
F_3 ( V_2 , V_21 , V_28 ) ;
F_3 ( V_2 , V_22 , V_29 ) ;
F_3 ( V_2 , V_23 , V_30 ) ;
F_3 ( V_2 , V_24 , V_31 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_32 ;
F_14 ( L_1 ) ;
V_32 = V_33 | V_34 ;
V_32 |= V_35 | V_36 ;
V_32 |= V_37 ;
if ( V_2 -> V_25 . V_38 & V_39 ) {
F_14 ( L_2 ) ;
V_32 |= V_40 ;
}
if ( V_2 -> V_25 . V_38 & V_41 ) {
F_14 ( L_3 ) ;
V_32 |= V_42 ;
}
V_32 |= V_43 ;
F_3 ( V_2 , V_32 , V_44 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_45 * V_25 = & V_2 -> V_25 ;
struct V_46 V_47 ;
T_3 V_48 [ F_16 ( V_49 ) ] ;
T_3 * V_50 = V_48 + V_51 ;
T_1 V_5 ;
int V_52 ;
F_14 ( L_1 ) ;
V_52 = F_17 ( & V_47 , V_25 ) ;
if ( V_52 < 0 ) {
F_18 ( L_4 , V_52 ) ;
return V_52 ;
}
V_47 . V_53 = V_54 ;
V_47 . V_55 = V_56 ;
V_47 . V_57 = V_58 ;
V_52 = F_19 ( & V_47 , V_48 , sizeof( V_48 ) ) ;
if ( V_52 < 0 ) {
F_18 ( L_5 , V_52 ) ;
return V_52 ;
}
V_5 = F_1 ( V_2 , V_59 ) ;
V_5 &= ~ F_20 ( V_60 , V_61 ) ;
F_3 ( V_2 , V_5 , V_59 ) ;
V_5 = V_48 [ 0x0 ] ;
V_5 |= V_48 [ 0x1 ] << 8 ;
V_5 |= V_48 [ 0x2 ] << 16 ;
F_3 ( V_2 , V_5 , F_21 ( V_61 ) ) ;
V_5 = V_50 [ 0x0 ] ;
V_5 |= V_50 [ 0x1 ] << 8 ;
V_5 |= V_50 [ 0x2 ] << 16 ;
V_5 |= V_50 [ 0x3 ] << 24 ;
F_3 ( V_2 , V_5 , F_22 ( V_61 ) ) ;
V_5 = V_50 [ 0x4 ] ;
V_5 |= V_50 [ 0x5 ] << 8 ;
V_5 |= V_50 [ 0x6 ] << 16 ;
V_5 |= V_50 [ 0x7 ] << 24 ;
F_3 ( V_2 , V_5 , F_23 ( V_61 ) ) ;
V_5 = V_50 [ 0x8 ] ;
V_5 |= V_50 [ 0x9 ] << 8 ;
V_5 |= V_50 [ 0xA ] << 16 ;
V_5 |= V_50 [ 0xB ] << 24 ;
F_3 ( V_2 , V_5 , F_24 ( V_61 ) ) ;
V_5 = V_50 [ 0xC ] ;
F_3 ( V_2 , V_5 , F_25 ( V_61 ) ) ;
V_5 = F_1 ( V_2 , V_59 ) ;
V_5 |= F_20 ( V_62 , V_61 ) ;
F_3 ( V_2 , V_5 , V_59 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_14 ( L_1 ) ;
if ( F_27 ( V_2 -> V_63 ) )
F_28 ( L_6 ) ;
V_2 -> V_15 = false ;
V_5 = F_1 ( V_2 , V_44 ) ;
V_5 |= V_64 ;
F_3 ( V_2 , V_5 , V_44 ) ;
F_29 ( V_2 -> V_16 ,
V_2 -> V_15 == true ,
F_30
( V_65 ) ) ;
if ( ( F_1 ( V_2 , V_66 ) & V_67 ) == 0 )
F_14 ( L_7 ) ;
V_5 = F_1 ( V_2 , V_44 ) ;
V_5 &= ~ V_64 ;
F_3 ( V_2 , V_5 , V_44 ) ;
F_31 ( V_2 -> V_63 ) ;
}
static void F_32 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
T_1 V_5 = F_1 ( V_2 , V_44 ) ;
if ( ! V_2 -> V_71 )
return;
F_14 ( L_1 ) ;
V_5 &= ~ V_43 ;
F_3 ( V_2 , V_5 , V_44 ) ;
F_3 ( V_2 , 0xffffffff , V_19 ) ;
V_2 -> V_72 -> V_73 ( V_2 ) ;
F_3 ( V_2 , 0x0000 , V_74 ) ;
F_3 ( V_2 , 0x0000 , V_75 ) ;
F_3 ( V_2 , 0x0060 , V_76 ) ;
F_31 ( V_2 -> V_77 ) ;
F_31 ( V_2 -> V_78 ) ;
F_31 ( V_2 -> V_79 ) ;
V_2 -> V_71 = false ;
}
static void F_33 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
F_14 ( L_1 ) ;
if ( V_2 -> V_71 )
return;
if ( F_27 ( V_2 -> V_79 ) )
F_18 ( L_8 ) ;
if ( F_27 ( V_2 -> V_78 ) )
F_18 ( L_9 ) ;
if ( F_27 ( V_2 -> V_77 ) )
F_18 ( L_10 ) ;
V_2 -> V_71 = true ;
if ( ! V_2 -> V_72 -> V_80 ( V_2 ) ) {
F_18 ( L_11 ) ;
return;
}
F_10 ( V_2 ) ;
F_3 ( V_2 , V_81 , V_82 ) ;
F_13 ( V_2 ) ;
if ( F_15 ( V_2 ) )
F_18 ( L_12 ) ;
F_26 ( V_2 ) ;
}
static void F_34 ( struct V_68 * V_69 ,
struct V_45 * V_25 ,
struct V_45 * V_83 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
int V_52 ;
F_14 ( L_1 ) ;
memcpy ( & V_2 -> V_25 , V_25 , sizeof( struct V_45 ) ) ;
V_52 = F_35 ( V_2 -> V_79 , V_25 -> clock * 1000 ) ;
if ( V_52 < 0 ) {
F_18 ( L_13 ,
V_25 -> clock * 1000 ) ;
return;
}
V_52 = F_35 ( V_2 -> V_77 , V_25 -> clock * 1000 ) ;
if ( V_52 < 0 ) {
F_18 ( L_14 ,
V_25 -> clock * 1000 ) ;
return;
}
}
static void F_36 ( struct V_68 * V_69 )
{
}
static void F_37 ( struct V_68 * V_69 )
{
F_38 ( V_69 ) ;
F_39 ( V_69 ) ;
}
static int F_40 ( struct V_84 * V_85 )
{
struct V_86 * V_87 ;
struct V_88 * V_88 ;
int V_89 ;
F_14 ( L_1 ) ;
V_87 = F_41 ( 1 ) ;
if ( ! V_87 )
goto V_90;
V_88 = F_42 ( V_85 , V_87 ) ;
if ( ! V_88 )
goto V_90;
V_89 = F_43 ( V_85 , V_88 ) ;
F_44 ( V_85 , V_88 ) ;
F_39 ( V_88 ) ;
return V_89 ;
V_90:
F_18 ( L_15 ) ;
return 0 ;
}
static int F_45 ( struct V_84 * V_85 ,
struct V_45 * V_25 )
{
int V_91 = V_25 -> clock * 1000 ;
int V_92 = V_91 - V_93 ;
int V_94 = V_91 + V_93 ;
int V_95 ;
struct V_96 * V_97
= F_46 ( V_85 ) ;
struct V_1 * V_2 = V_97 -> V_2 ;
V_95 = F_47 ( V_2 -> V_79 , V_91 ) ;
F_14 ( L_16 ,
V_91 , V_95 ) ;
if ( ( V_95 < V_92 ) || ( V_95 > V_94 ) ) {
F_14 ( L_17 , V_91 ) ;
return V_98 ;
}
return V_99 ;
}
struct V_100 * F_48 ( struct V_84 * V_85 )
{
struct V_96 * V_97
= F_46 ( V_85 ) ;
return V_97 -> V_101 ;
}
static enum V_102
F_49 ( struct V_84 * V_85 , bool V_103 )
{
struct V_96 * V_97
= F_46 ( V_85 ) ;
struct V_1 * V_2 = V_97 -> V_2 ;
F_14 ( L_1 ) ;
if ( V_2 -> V_10 ) {
F_14 ( L_18 ) ;
return V_104 ;
}
F_14 ( L_19 ) ;
return V_105 ;
}
static void F_50 ( struct V_84 * V_85 )
{
struct V_96 * V_97
= F_46 ( V_85 ) ;
F_51 ( V_85 ) ;
F_52 ( V_85 ) ;
F_39 ( V_97 ) ;
}
static struct V_100 * F_53 ( struct V_106 * V_107 )
{
struct V_100 * V_101 ;
F_54 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_101 -> V_108 == V_109 )
return V_101 ;
}
return NULL ;
}
static int F_55 ( struct V_110 * V_107 , struct V_110 * V_111 , void * V_112 )
{
struct V_1 * V_2 = F_56 ( V_107 ) ;
struct V_106 * V_12 = V_112 ;
struct V_100 * V_101 ;
struct V_96 * V_85 ;
struct V_84 * V_84 ;
struct V_68 * V_69 ;
struct V_86 * V_87 ;
int V_113 ;
V_87 = F_41 ( 1 ) ;
if ( ! V_87 )
return - V_114 ;
V_2 -> V_12 = V_12 ;
V_101 = F_53 ( V_12 ) ;
if ( ! V_101 )
return - V_115 ;
V_85 = F_57 ( V_107 , sizeof( * V_85 ) , V_116 ) ;
if ( ! V_85 )
return - V_115 ;
V_85 -> V_2 = V_2 ;
V_69 = F_57 ( V_107 , sizeof( * V_69 ) , V_116 ) ;
if ( ! V_69 )
return - V_115 ;
V_69 -> V_70 = V_2 ;
F_58 ( V_12 , V_69 , & V_117 ) ;
V_101 -> V_69 = V_69 ;
V_85 -> V_101 = V_101 ;
V_84 = (struct V_84 * ) V_85 ;
V_84 -> V_118 = V_119 ;
F_59 ( V_12 , V_84 ,
& V_120 , V_121 ) ;
F_60 ( V_84 ,
& V_122 ) ;
V_113 = F_61 ( V_84 ) ;
if ( V_113 )
goto V_123;
V_113 = F_62 ( V_84 , V_101 ) ;
if ( V_113 ) {
F_18 ( L_20 ) ;
goto V_124;
}
F_3 ( V_2 , V_125 , V_82 ) ;
return 0 ;
V_124:
F_51 ( V_84 ) ;
V_123:
F_38 ( V_69 ) ;
F_52 ( V_84 ) ;
return - V_126 ;
}
static void F_63 ( struct V_110 * V_107 ,
struct V_110 * V_111 , void * V_112 )
{
}
static int F_64 ( struct V_127 * V_128 )
{
struct V_110 * V_107 = & V_128 -> V_107 ;
struct V_1 * V_2 ;
struct V_129 * V_130 = V_107 -> V_131 ;
struct V_132 * V_133 ;
int V_52 ;
F_28 ( L_21 , V_134 ) ;
V_2 = F_57 ( V_107 , sizeof( * V_2 ) , V_116 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_107 = V_128 -> V_107 ;
V_133 = F_65 ( V_128 , V_135 , L_22 ) ;
if ( ! V_133 ) {
F_18 ( L_23 ) ;
return - V_115 ;
}
V_2 -> V_4 = F_66 ( V_107 , V_133 -> V_80 , F_67 ( V_133 ) ) ;
if ( ! V_2 -> V_4 )
return - V_115 ;
if ( F_68 ( V_130 , L_24 ) ) {
V_133 = F_65 ( V_128 , V_135 ,
L_25 ) ;
if ( ! V_133 ) {
F_18 ( L_26 ) ;
return - V_115 ;
}
V_2 -> V_136 = F_66 ( V_107 , V_133 -> V_80 ,
F_67 ( V_133 ) ) ;
if ( ! V_2 -> V_136 )
return - V_115 ;
}
V_2 -> V_72 = (struct V_137 * )
F_69 ( V_138 , V_130 ) -> V_112 ;
V_2 -> V_79 = F_70 ( V_107 , L_27 ) ;
if ( F_71 ( V_2 -> V_79 ) ) {
F_18 ( L_28 ) ;
return F_72 ( V_2 -> V_79 ) ;
}
V_2 -> V_78 = F_70 ( V_107 , L_29 ) ;
if ( F_71 ( V_2 -> V_78 ) ) {
F_18 ( L_30 ) ;
return F_72 ( V_2 -> V_78 ) ;
}
V_2 -> V_77 = F_70 ( V_107 , L_31 ) ;
if ( F_71 ( V_2 -> V_77 ) ) {
F_18 ( L_32 ) ;
return F_72 ( V_2 -> V_77 ) ;
}
V_2 -> V_63 = F_70 ( V_107 , L_33 ) ;
if ( F_71 ( V_2 -> V_63 ) ) {
F_18 ( L_34 ) ;
return F_72 ( V_2 -> V_63 ) ;
}
V_2 -> V_11 = F_73 ( V_130 , L_35 , 0 ) ;
if ( V_2 -> V_11 < 0 ) {
F_18 ( L_36 ) ;
return - V_139 ;
}
V_2 -> V_10 = F_6 ( V_2 -> V_11 ) ;
F_74 ( & V_2 -> V_16 ) ;
V_2 -> V_6 = F_75 ( V_128 , L_37 ) ;
V_52 = F_76 ( V_107 , V_2 -> V_6 , F_9 ,
F_5 , V_140 , F_77 ( V_107 ) , V_2 ) ;
if ( V_52 ) {
F_18 ( L_38 ) ;
return V_52 ;
}
V_2 -> V_141 = F_78 ( V_107 , L_39 ) ;
if ( ! F_71 ( V_2 -> V_141 ) )
F_79 ( V_2 -> V_141 ) ;
F_80 ( V_128 , V_2 ) ;
return F_81 ( & V_128 -> V_107 , & V_142 ) ;
}
static int F_82 ( struct V_127 * V_128 )
{
F_83 ( & V_128 -> V_107 , & V_142 ) ;
return 0 ;
}
