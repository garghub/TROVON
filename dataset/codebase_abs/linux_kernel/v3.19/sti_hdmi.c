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
V_2 -> V_10 = F_2 ( V_2 -> V_4 + V_11 ) & V_12 ;
if ( V_2 -> V_13 )
F_6 ( V_2 -> V_13 ) ;
}
if ( V_2 -> V_8 & ( V_14 | V_15 ) ) {
V_2 -> V_16 = true ;
F_7 ( & V_2 -> V_17 ) ;
}
return V_18 ;
}
static T_2 F_8 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
V_2 -> V_8 = F_1 ( V_2 , V_19 ) ;
F_3 ( V_2 , V_2 -> V_8 , V_20 ) ;
F_1 ( V_2 , V_19 ) ;
return V_21 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_22 , V_23 ;
T_1 V_24 , V_25 ;
V_22 = F_10 ( V_2 -> V_26 , 0 ) ;
V_23 = F_10 ( V_2 -> V_26 , V_2 -> V_26 . V_27 - 1 ) ;
V_24 = F_11 ( V_2 -> V_26 , 0 ) ;
V_25 = F_11 ( V_2 -> V_26 , V_2 -> V_26 . V_28 - 1 ) ;
F_3 ( V_2 , V_22 , V_29 ) ;
F_3 ( V_2 , V_23 , V_30 ) ;
F_3 ( V_2 , V_24 , V_31 ) ;
F_3 ( V_2 , V_25 , V_32 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_33 ;
F_13 ( L_1 ) ;
V_33 = V_34 | V_35 ;
V_33 |= V_36 | V_37 ;
V_33 |= V_38 ;
if ( V_2 -> V_26 . V_39 & V_40 ) {
F_13 ( L_2 ) ;
V_33 |= V_41 ;
}
if ( V_2 -> V_26 . V_39 & V_42 ) {
F_13 ( L_3 ) ;
V_33 |= V_43 ;
}
V_33 |= V_44 ;
F_3 ( V_2 , V_33 , V_45 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_46 * V_26 = & V_2 -> V_26 ;
struct V_47 V_48 ;
T_3 V_49 [ F_15 ( V_50 ) ] ;
T_3 * V_51 = V_49 + V_52 ;
T_1 V_5 ;
int V_53 ;
F_13 ( L_1 ) ;
V_53 = F_16 ( & V_48 , V_26 ) ;
if ( V_53 < 0 ) {
F_17 ( L_4 , V_53 ) ;
return V_53 ;
}
V_48 . V_54 = V_55 ;
V_48 . V_56 = V_57 ;
V_48 . V_58 = V_59 ;
V_53 = F_18 ( & V_48 , V_49 , sizeof( V_49 ) ) ;
if ( V_53 < 0 ) {
F_17 ( L_5 , V_53 ) ;
return V_53 ;
}
V_5 = F_1 ( V_2 , V_60 ) ;
V_5 &= ~ F_19 ( V_61 , V_62 ) ;
F_3 ( V_2 , V_5 , V_60 ) ;
V_5 = V_49 [ 0 ] ;
V_5 |= V_49 [ 1 ] << 8 ;
V_5 |= V_49 [ 2 ] << 16 ;
F_3 ( V_2 , V_5 , F_20 ( V_62 ) ) ;
V_5 = V_49 [ 3 ] ;
V_5 |= * ( V_51 ++ ) << 8 ;
V_5 |= * ( V_51 ++ ) << 16 ;
V_5 |= * ( V_51 ++ ) << 24 ;
F_3 ( V_2 , V_5 , F_21 ( V_62 ) ) ;
V_5 = * ( V_51 ++ ) ;
V_5 |= * ( V_51 ++ ) << 8 ;
V_5 |= * ( V_51 ++ ) << 16 ;
V_5 |= * ( V_51 ++ ) << 24 ;
F_3 ( V_2 , V_5 , F_22 ( V_62 ) ) ;
V_5 = * ( V_51 ++ ) ;
V_5 |= * ( V_51 ++ ) << 8 ;
V_5 |= * ( V_51 ++ ) << 16 ;
V_5 |= * ( V_51 ++ ) << 24 ;
F_3 ( V_2 , V_5 , F_23 ( V_62 ) ) ;
V_5 = * ( V_51 ++ ) ;
V_5 |= * ( V_51 ) << 8 ;
F_3 ( V_2 , V_5 , F_24 ( V_62 ) ) ;
V_5 = F_1 ( V_2 , V_60 ) ;
V_5 |= F_19 ( V_63 , V_62 ) ;
F_3 ( V_2 , V_5 , V_60 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_13 ( L_1 ) ;
if ( F_26 ( V_2 -> V_64 ) )
F_27 ( L_6 ) ;
V_2 -> V_16 = false ;
V_5 = F_1 ( V_2 , V_45 ) ;
V_5 |= V_65 ;
F_3 ( V_2 , V_5 , V_45 ) ;
F_28 ( V_2 -> V_17 ,
V_2 -> V_16 == true ,
F_29
( V_66 ) ) ;
if ( ( F_1 ( V_2 , V_11 ) & V_67 ) == 0 )
F_13 ( L_7 ) ;
V_5 = F_1 ( V_2 , V_45 ) ;
V_5 &= ~ V_65 ;
F_3 ( V_2 , V_5 , V_45 ) ;
F_30 ( V_2 -> V_64 ) ;
}
static void F_31 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
T_1 V_5 = F_1 ( V_2 , V_45 ) ;
if ( ! V_2 -> V_71 )
return;
F_13 ( L_1 ) ;
V_5 &= ~ V_44 ;
F_3 ( V_2 , V_5 , V_45 ) ;
F_3 ( V_2 , 0xffffffff , V_20 ) ;
V_2 -> V_72 -> V_73 ( V_2 ) ;
F_3 ( V_2 , 0x0000 , V_74 ) ;
F_3 ( V_2 , 0x0000 , V_75 ) ;
F_3 ( V_2 , 0x0060 , V_76 ) ;
F_30 ( V_2 -> V_77 ) ;
F_30 ( V_2 -> V_78 ) ;
F_30 ( V_2 -> V_79 ) ;
V_2 -> V_71 = false ;
}
static void F_32 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
F_13 ( L_1 ) ;
if ( V_2 -> V_71 )
return;
if ( F_26 ( V_2 -> V_79 ) )
F_17 ( L_8 ) ;
if ( F_26 ( V_2 -> V_78 ) )
F_17 ( L_9 ) ;
if ( F_26 ( V_2 -> V_77 ) )
F_17 ( L_10 ) ;
V_2 -> V_71 = true ;
if ( ! V_2 -> V_72 -> V_80 ( V_2 ) ) {
F_17 ( L_11 ) ;
return;
}
F_9 ( V_2 ) ;
F_3 ( V_2 , V_81 , V_82 ) ;
F_12 ( V_2 ) ;
if ( F_14 ( V_2 ) )
F_17 ( L_12 ) ;
F_25 ( V_2 ) ;
}
static void F_33 ( struct V_68 * V_69 ,
struct V_46 * V_26 ,
struct V_46 * V_83 )
{
struct V_1 * V_2 = V_69 -> V_70 ;
int V_53 ;
F_13 ( L_1 ) ;
memcpy ( & V_2 -> V_26 , V_26 , sizeof( struct V_46 ) ) ;
V_53 = F_34 ( V_2 -> V_79 , V_26 -> clock * 1000 ) ;
if ( V_53 < 0 ) {
F_17 ( L_13 ,
V_26 -> clock * 1000 ) ;
return;
}
V_53 = F_34 ( V_2 -> V_77 , V_26 -> clock * 1000 ) ;
if ( V_53 < 0 ) {
F_17 ( L_14 ,
V_26 -> clock * 1000 ) ;
return;
}
}
static void F_35 ( struct V_68 * V_69 )
{
}
static void F_36 ( struct V_68 * V_69 )
{
F_37 ( V_69 ) ;
F_38 ( V_69 ) ;
}
static int F_39 ( struct V_84 * V_85 )
{
struct V_86 * V_87
= F_40 ( V_85 ) ;
struct V_1 * V_2 = V_87 -> V_2 ;
struct V_88 * V_88 ;
int V_89 ;
F_13 ( L_1 ) ;
V_88 = F_41 ( V_85 , V_2 -> V_90 ) ;
if ( ! V_88 )
goto V_91;
V_89 = F_42 ( V_85 , V_88 ) ;
F_43 ( V_85 , V_88 ) ;
F_38 ( V_88 ) ;
return V_89 ;
V_91:
F_17 ( L_15 ) ;
return 0 ;
}
static int F_44 ( struct V_84 * V_85 ,
struct V_46 * V_26 )
{
int V_92 = V_26 -> clock * 1000 ;
int V_93 = V_92 - V_94 ;
int V_95 = V_92 + V_94 ;
int V_96 ;
struct V_86 * V_87
= F_40 ( V_85 ) ;
struct V_1 * V_2 = V_87 -> V_2 ;
V_96 = F_45 ( V_2 -> V_79 , V_92 ) ;
F_13 ( L_16 ,
V_92 , V_96 ) ;
if ( ( V_96 < V_93 ) || ( V_96 > V_95 ) ) {
F_13 ( L_17 , V_92 ) ;
return V_97 ;
}
return V_98 ;
}
struct V_99 * F_46 ( struct V_84 * V_85 )
{
struct V_86 * V_87
= F_40 ( V_85 ) ;
return V_87 -> V_100 ;
}
static enum V_101
F_47 ( struct V_84 * V_85 , bool V_102 )
{
struct V_86 * V_87
= F_40 ( V_85 ) ;
struct V_1 * V_2 = V_87 -> V_2 ;
F_13 ( L_1 ) ;
if ( V_2 -> V_10 ) {
F_13 ( L_18 ) ;
return V_103 ;
}
F_13 ( L_19 ) ;
return V_104 ;
}
static void F_48 ( struct V_84 * V_85 )
{
struct V_86 * V_87
= F_40 ( V_85 ) ;
F_49 ( V_85 ) ;
F_50 ( V_85 ) ;
F_38 ( V_87 ) ;
}
static struct V_99 * F_51 ( struct V_105 * V_106 )
{
struct V_99 * V_100 ;
F_52 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_100 -> V_107 == V_108 )
return V_100 ;
}
return NULL ;
}
static int F_53 ( struct V_109 * V_106 , struct V_109 * V_110 , void * V_111 )
{
struct V_1 * V_2 = F_54 ( V_106 ) ;
struct V_105 * V_13 = V_111 ;
struct V_99 * V_100 ;
struct V_86 * V_85 ;
struct V_84 * V_84 ;
struct V_68 * V_69 ;
struct V_112 * V_113 ;
int V_114 ;
V_113 = F_55 ( V_106 -> V_115 , L_20 , 0 ) ;
if ( V_113 ) {
V_2 -> V_90 = F_56 ( V_113 ) ;
if ( ! V_2 -> V_90 ) {
V_114 = - V_116 ;
F_57 ( V_113 ) ;
return V_114 ;
}
F_57 ( V_113 ) ;
}
V_2 -> V_13 = V_13 ;
V_100 = F_51 ( V_13 ) ;
if ( ! V_100 )
goto V_117;
V_85 = F_58 ( V_106 , sizeof( * V_85 ) , V_118 ) ;
if ( ! V_85 )
goto V_117;
V_85 -> V_2 = V_2 ;
V_69 = F_58 ( V_106 , sizeof( * V_69 ) , V_118 ) ;
if ( ! V_69 )
goto V_117;
V_69 -> V_70 = V_2 ;
F_59 ( V_13 , V_69 , & V_119 ) ;
V_100 -> V_69 = V_69 ;
V_85 -> V_100 = V_100 ;
V_84 = (struct V_84 * ) V_85 ;
V_84 -> V_120 = V_121 ;
F_60 ( V_13 , V_84 ,
& V_122 , V_123 ) ;
F_61 ( V_84 ,
& V_124 ) ;
V_114 = F_62 ( V_84 ) ;
if ( V_114 )
goto V_125;
V_114 = F_63 ( V_84 , V_100 ) ;
if ( V_114 ) {
F_17 ( L_21 ) ;
goto V_126;
}
F_3 ( V_2 , V_127 , V_82 ) ;
return 0 ;
V_126:
F_49 ( V_84 ) ;
V_125:
F_37 ( V_69 ) ;
F_50 ( V_84 ) ;
V_117:
F_64 ( & V_2 -> V_90 -> V_106 ) ;
return - V_128 ;
}
static void F_65 ( struct V_109 * V_106 ,
struct V_109 * V_110 , void * V_111 )
{
}
static int F_66 ( struct V_129 * V_130 )
{
struct V_109 * V_106 = & V_130 -> V_106 ;
struct V_1 * V_2 ;
struct V_112 * V_131 = V_106 -> V_115 ;
struct V_132 * V_133 ;
int V_53 ;
F_27 ( L_22 , V_134 ) ;
V_2 = F_58 ( V_106 , sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 )
return - V_135 ;
V_2 -> V_106 = V_130 -> V_106 ;
V_133 = F_67 ( V_130 , V_136 , L_23 ) ;
if ( ! V_133 ) {
F_17 ( L_24 ) ;
return - V_135 ;
}
V_2 -> V_4 = F_68 ( V_106 , V_133 -> V_80 , F_69 ( V_133 ) ) ;
if ( ! V_2 -> V_4 )
return - V_135 ;
if ( F_70 ( V_131 , L_25 ) ) {
V_133 = F_67 ( V_130 , V_136 ,
L_26 ) ;
if ( ! V_133 ) {
F_17 ( L_27 ) ;
return - V_135 ;
}
V_2 -> V_137 = F_68 ( V_106 , V_133 -> V_80 ,
F_69 ( V_133 ) ) ;
if ( ! V_2 -> V_137 )
return - V_135 ;
}
V_2 -> V_72 = (struct V_138 * )
F_71 ( V_139 , V_131 ) -> V_111 ;
V_2 -> V_79 = F_72 ( V_106 , L_28 ) ;
if ( F_73 ( V_2 -> V_79 ) ) {
F_17 ( L_29 ) ;
return F_74 ( V_2 -> V_79 ) ;
}
V_2 -> V_78 = F_72 ( V_106 , L_30 ) ;
if ( F_73 ( V_2 -> V_78 ) ) {
F_17 ( L_31 ) ;
return F_74 ( V_2 -> V_78 ) ;
}
V_2 -> V_77 = F_72 ( V_106 , L_32 ) ;
if ( F_73 ( V_2 -> V_77 ) ) {
F_17 ( L_33 ) ;
return F_74 ( V_2 -> V_77 ) ;
}
V_2 -> V_64 = F_72 ( V_106 , L_34 ) ;
if ( F_73 ( V_2 -> V_64 ) ) {
F_17 ( L_35 ) ;
return F_74 ( V_2 -> V_64 ) ;
}
V_2 -> V_10 = F_2 ( V_2 -> V_4 + V_11 ) & V_12 ;
F_75 ( & V_2 -> V_17 ) ;
V_2 -> V_6 = F_76 ( V_130 , L_36 ) ;
V_53 = F_77 ( V_106 , V_2 -> V_6 , F_8 ,
F_5 , V_140 , F_78 ( V_106 ) , V_2 ) ;
if ( V_53 ) {
F_17 ( L_37 ) ;
return V_53 ;
}
V_2 -> V_141 = F_79 ( V_106 , L_38 ) ;
if ( ! F_73 ( V_2 -> V_141 ) )
F_80 ( V_2 -> V_141 ) ;
F_81 ( V_130 , V_2 ) ;
return F_82 ( & V_130 -> V_106 , & V_142 ) ;
}
static int F_83 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_54 ( & V_130 -> V_106 ) ;
if ( V_2 -> V_90 )
F_64 ( & V_2 -> V_90 -> V_106 ) ;
F_84 ( & V_130 -> V_106 , & V_142 ) ;
return 0 ;
}
