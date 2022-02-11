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
V_22 = F_10 ( V_2 -> V_26 , 1 ) ;
V_23 = F_10 ( V_2 -> V_26 , V_2 -> V_26 . V_27 ) ;
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
static inline unsigned int F_14 ( const T_3 * V_46 , T_4 V_47 )
{
unsigned long V_48 = 0 ;
T_4 V_49 ;
for ( V_49 = V_47 ; V_49 > 0 ; V_49 -- )
V_48 = ( V_48 << 8 ) | V_46 [ V_49 - 1 ] ;
return V_48 ;
}
static void F_15 ( struct V_1 * V_2 , const T_3 * V_50 )
{
const T_3 * V_46 = V_50 ;
T_1 V_5 , V_51 , V_26 , V_49 ;
T_1 V_52 , V_53 ;
T_4 V_47 ;
switch ( * V_46 ) {
case V_54 :
V_51 = V_55 ;
V_26 = V_56 ;
V_52 = F_16 ( V_55 ) ;
V_53 = F_17 ( V_55 ) ;
V_47 = V_57 ;
break;
case V_58 :
V_51 = V_59 ;
V_26 = V_60 ;
V_52 = F_16 ( V_59 ) ;
V_53 = F_17 ( V_59 ) ;
V_47 = V_61 ;
break;
default:
F_18 ( L_4 , * V_46 ) ;
return;
}
V_5 = F_1 ( V_2 , V_62 ) ;
V_5 &= ~ F_19 ( V_63 , V_51 ) ;
F_3 ( V_2 , V_5 , V_62 ) ;
V_5 = F_20 ( * V_46 ++ ) ;
V_5 |= F_21 ( * V_46 ++ ) ;
V_5 |= F_22 ( * V_46 ++ ) ;
F_4 ( V_5 , V_2 -> V_4 + V_52 ) ;
for ( V_49 = 0 ; V_49 < V_47 ; V_49 += sizeof( T_1 ) ) {
T_4 V_64 ;
V_64 = F_23 ( T_4 , V_47 - V_49 , sizeof( T_1 ) ) ;
V_5 = F_14 ( V_46 , V_64 ) ;
V_46 += sizeof( T_1 ) ;
F_4 ( V_5 , V_2 -> V_4 + V_53 + V_49 ) ;
}
V_5 = F_1 ( V_2 , V_62 ) ;
V_5 |= F_19 ( V_56 , V_51 ) ;
F_3 ( V_2 , V_5 , V_62 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_65 * V_26 = & V_2 -> V_26 ;
struct V_66 V_67 ;
T_3 V_68 [ F_25 ( V_69 ) ] ;
int V_70 ;
F_13 ( L_1 ) ;
V_70 = F_26 ( & V_67 , V_26 ) ;
if ( V_70 < 0 ) {
F_18 ( L_5 , V_70 ) ;
return V_70 ;
}
V_67 . V_71 = V_72 ;
V_67 . V_73 = V_74 ;
V_67 . V_75 = V_76 ;
V_70 = F_27 ( & V_67 , V_68 , sizeof( V_68 ) ) ;
if ( V_70 < 0 ) {
F_18 ( L_6 , V_70 ) ;
return V_70 ;
}
F_15 ( V_2 , V_68 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_77 V_78 ;
T_3 V_68 [ F_25 ( V_79 ) ] ;
int V_70 ;
V_70 = F_29 ( & V_78 ) ;
if ( V_70 < 0 ) {
F_18 ( L_7 , V_70 ) ;
return V_70 ;
}
V_78 . V_80 = 2 ;
V_70 = F_30 ( & V_78 , V_68 , sizeof( V_68 ) ) ;
if ( V_70 < 0 ) {
F_18 ( L_8 , V_70 ) ;
return V_70 ;
}
F_15 ( V_2 , V_68 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_13 ( L_1 ) ;
if ( F_32 ( V_2 -> V_81 ) )
F_33 ( L_9 ) ;
V_2 -> V_16 = false ;
V_5 = F_1 ( V_2 , V_45 ) ;
V_5 |= V_82 ;
F_3 ( V_2 , V_5 , V_45 ) ;
F_34 ( V_2 -> V_17 ,
V_2 -> V_16 == true ,
F_35
( V_83 ) ) ;
if ( ( F_1 ( V_2 , V_11 ) & V_84 ) == 0 )
F_13 ( L_10 ) ;
V_5 = F_1 ( V_2 , V_45 ) ;
V_5 &= ~ V_82 ;
F_3 ( V_2 , V_5 , V_45 ) ;
F_36 ( V_2 -> V_81 ) ;
}
static void F_37 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_87 ;
T_1 V_5 = F_1 ( V_2 , V_45 ) ;
if ( ! V_2 -> V_88 )
return;
F_13 ( L_1 ) ;
V_5 &= ~ V_44 ;
F_3 ( V_2 , V_5 , V_45 ) ;
F_3 ( V_2 , 0xffffffff , V_20 ) ;
V_2 -> V_89 -> V_90 ( V_2 ) ;
F_3 ( V_2 , 0x0000 , V_91 ) ;
F_3 ( V_2 , 0x0000 , V_92 ) ;
F_3 ( V_2 , 0x0060 , V_93 ) ;
F_36 ( V_2 -> V_94 ) ;
F_36 ( V_2 -> V_95 ) ;
F_36 ( V_2 -> V_96 ) ;
V_2 -> V_88 = false ;
}
static void F_38 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = V_86 -> V_87 ;
F_13 ( L_1 ) ;
if ( V_2 -> V_88 )
return;
if ( F_32 ( V_2 -> V_96 ) )
F_18 ( L_11 ) ;
if ( F_32 ( V_2 -> V_95 ) )
F_18 ( L_12 ) ;
if ( F_32 ( V_2 -> V_94 ) )
F_18 ( L_13 ) ;
V_2 -> V_88 = true ;
if ( ! V_2 -> V_89 -> V_97 ( V_2 ) ) {
F_18 ( L_14 ) ;
return;
}
F_9 ( V_2 ) ;
F_3 ( V_2 , V_98 , V_99 ) ;
F_12 ( V_2 ) ;
if ( F_24 ( V_2 ) )
F_18 ( L_15 ) ;
if ( F_28 ( V_2 ) )
F_18 ( L_16 ) ;
F_31 ( V_2 ) ;
}
static void F_39 ( struct V_85 * V_86 ,
struct V_65 * V_26 ,
struct V_65 * V_100 )
{
struct V_1 * V_2 = V_86 -> V_87 ;
int V_70 ;
F_13 ( L_1 ) ;
memcpy ( & V_2 -> V_26 , V_26 , sizeof( struct V_65 ) ) ;
V_70 = F_40 ( V_2 -> V_96 , V_26 -> clock * 1000 ) ;
if ( V_70 < 0 ) {
F_18 ( L_17 ,
V_26 -> clock * 1000 ) ;
return;
}
V_70 = F_40 ( V_2 -> V_94 , V_26 -> clock * 1000 ) ;
if ( V_70 < 0 ) {
F_18 ( L_18 ,
V_26 -> clock * 1000 ) ;
return;
}
}
static void F_41 ( struct V_85 * V_86 )
{
}
static int F_42 ( struct V_101 * V_102 )
{
struct V_103 * V_104
= F_43 ( V_102 ) ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_105 * V_105 ;
int V_106 ;
F_13 ( L_1 ) ;
V_105 = F_44 ( V_102 , V_2 -> V_107 ) ;
if ( ! V_105 )
goto V_108;
V_106 = F_45 ( V_102 , V_105 ) ;
F_46 ( V_102 , V_105 ) ;
F_47 ( V_105 ) ;
return V_106 ;
V_108:
F_18 ( L_19 ) ;
return 0 ;
}
static int F_48 ( struct V_101 * V_102 ,
struct V_65 * V_26 )
{
int V_109 = V_26 -> clock * 1000 ;
int V_110 = V_109 - V_111 ;
int V_112 = V_109 + V_111 ;
int V_113 ;
struct V_103 * V_104
= F_43 ( V_102 ) ;
struct V_1 * V_2 = V_104 -> V_2 ;
V_113 = F_49 ( V_2 -> V_96 , V_109 ) ;
F_13 ( L_20 ,
V_109 , V_113 ) ;
if ( ( V_113 < V_110 ) || ( V_113 > V_112 ) ) {
F_13 ( L_21 , V_109 ) ;
return V_114 ;
}
return V_115 ;
}
struct V_116 * F_50 ( struct V_101 * V_102 )
{
struct V_103 * V_104
= F_43 ( V_102 ) ;
return V_104 -> V_117 ;
}
static enum V_118
F_51 ( struct V_101 * V_102 , bool V_119 )
{
struct V_103 * V_104
= F_43 ( V_102 ) ;
struct V_1 * V_2 = V_104 -> V_2 ;
F_13 ( L_1 ) ;
if ( V_2 -> V_10 ) {
F_13 ( L_22 ) ;
return V_120 ;
}
F_13 ( L_23 ) ;
return V_121 ;
}
static void F_52 ( struct V_101 * V_102 )
{
struct V_103 * V_104
= F_43 ( V_102 ) ;
F_53 ( V_102 ) ;
F_54 ( V_102 ) ;
F_47 ( V_104 ) ;
}
static struct V_116 * F_55 ( struct V_122 * V_123 )
{
struct V_116 * V_117 ;
F_56 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_117 -> V_124 == V_125 )
return V_117 ;
}
return NULL ;
}
static int F_57 ( struct V_126 * V_123 , struct V_126 * V_127 , void * V_50 )
{
struct V_1 * V_2 = F_58 ( V_123 ) ;
struct V_122 * V_13 = V_50 ;
struct V_116 * V_117 ;
struct V_103 * V_102 ;
struct V_101 * V_101 ;
struct V_85 * V_86 ;
int V_128 ;
V_2 -> V_13 = V_13 ;
V_117 = F_55 ( V_13 ) ;
if ( ! V_117 )
goto V_129;
V_102 = F_59 ( V_123 , sizeof( * V_102 ) , V_130 ) ;
if ( ! V_102 )
goto V_129;
V_102 -> V_2 = V_2 ;
V_86 = F_59 ( V_123 , sizeof( * V_86 ) , V_130 ) ;
if ( ! V_86 )
goto V_129;
V_86 -> V_87 = V_2 ;
V_86 -> V_131 = & V_132 ;
F_60 ( V_13 , V_86 ) ;
V_117 -> V_86 = V_86 ;
V_102 -> V_117 = V_117 ;
V_101 = (struct V_101 * ) V_102 ;
V_101 -> V_133 = V_134 ;
F_61 ( V_13 , V_101 ,
& V_135 , V_136 ) ;
F_62 ( V_101 ,
& V_137 ) ;
V_128 = F_63 ( V_101 ) ;
if ( V_128 )
goto V_138;
V_128 = F_64 ( V_101 , V_117 ) ;
if ( V_128 ) {
F_18 ( L_24 ) ;
goto V_139;
}
F_3 ( V_2 , V_140 , V_99 ) ;
return 0 ;
V_139:
F_53 ( V_101 ) ;
V_138:
F_54 ( V_101 ) ;
V_129:
F_65 ( & V_2 -> V_107 -> V_123 ) ;
return - V_141 ;
}
static void F_66 ( struct V_126 * V_123 ,
struct V_126 * V_127 , void * V_50 )
{
}
static int F_67 ( struct V_142 * V_143 )
{
struct V_126 * V_123 = & V_143 -> V_123 ;
struct V_1 * V_2 ;
struct V_144 * V_145 = V_123 -> V_146 ;
struct V_147 * V_148 ;
struct V_144 * V_149 ;
int V_70 ;
F_33 ( L_25 , V_150 ) ;
V_2 = F_59 ( V_123 , sizeof( * V_2 ) , V_130 ) ;
if ( ! V_2 )
return - V_151 ;
V_149 = F_68 ( V_143 -> V_123 . V_146 , L_26 , 0 ) ;
if ( V_149 ) {
V_2 -> V_107 = F_69 ( V_149 ) ;
if ( ! V_2 -> V_107 ) {
F_70 ( V_149 ) ;
return - V_152 ;
}
F_70 ( V_149 ) ;
}
V_2 -> V_123 = V_143 -> V_123 ;
V_148 = F_71 ( V_143 , V_153 , L_27 ) ;
if ( ! V_148 ) {
F_18 ( L_28 ) ;
return - V_151 ;
}
V_2 -> V_4 = F_72 ( V_123 , V_148 -> V_97 , F_73 ( V_148 ) ) ;
if ( ! V_2 -> V_4 )
return - V_151 ;
if ( F_74 ( V_145 , L_29 ) ) {
V_148 = F_71 ( V_143 , V_153 ,
L_30 ) ;
if ( ! V_148 ) {
F_18 ( L_31 ) ;
return - V_151 ;
}
V_2 -> V_154 = F_72 ( V_123 , V_148 -> V_97 ,
F_73 ( V_148 ) ) ;
if ( ! V_2 -> V_154 )
return - V_151 ;
}
V_2 -> V_89 = (struct V_155 * )
F_75 ( V_156 , V_145 ) -> V_50 ;
V_2 -> V_96 = F_76 ( V_123 , L_32 ) ;
if ( F_77 ( V_2 -> V_96 ) ) {
F_18 ( L_33 ) ;
return F_78 ( V_2 -> V_96 ) ;
}
V_2 -> V_95 = F_76 ( V_123 , L_34 ) ;
if ( F_77 ( V_2 -> V_95 ) ) {
F_18 ( L_35 ) ;
return F_78 ( V_2 -> V_95 ) ;
}
V_2 -> V_94 = F_76 ( V_123 , L_36 ) ;
if ( F_77 ( V_2 -> V_94 ) ) {
F_18 ( L_37 ) ;
return F_78 ( V_2 -> V_94 ) ;
}
V_2 -> V_81 = F_76 ( V_123 , L_38 ) ;
if ( F_77 ( V_2 -> V_81 ) ) {
F_18 ( L_39 ) ;
return F_78 ( V_2 -> V_81 ) ;
}
V_2 -> V_10 = F_2 ( V_2 -> V_4 + V_11 ) & V_12 ;
F_79 ( & V_2 -> V_17 ) ;
V_2 -> V_6 = F_80 ( V_143 , L_40 ) ;
V_70 = F_81 ( V_123 , V_2 -> V_6 , F_8 ,
F_5 , V_157 , F_82 ( V_123 ) , V_2 ) ;
if ( V_70 ) {
F_18 ( L_41 ) ;
return V_70 ;
}
V_2 -> V_158 = F_83 ( V_123 , L_42 ) ;
if ( ! F_77 ( V_2 -> V_158 ) )
F_84 ( V_2 -> V_158 ) ;
F_85 ( V_143 , V_2 ) ;
return F_86 ( & V_143 -> V_123 , & V_159 ) ;
}
static int F_87 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = F_58 ( & V_143 -> V_123 ) ;
if ( V_2 -> V_107 )
F_65 ( & V_2 -> V_107 -> V_123 ) ;
F_88 ( & V_143 -> V_123 , & V_159 ) ;
return 0 ;
}
