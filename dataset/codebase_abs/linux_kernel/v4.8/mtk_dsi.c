static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static inline struct V_1 * F_4 ( struct V_8 * V_9 )
{
return F_2 ( V_9 , struct V_1 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_11 , T_1 V_12 , T_1 V_13 , T_1 V_14 )
{
T_1 V_15 = F_6 ( V_11 -> V_16 + V_12 ) ;
F_7 ( ( V_15 & ~ V_13 ) | ( V_14 & V_13 ) , V_11 -> V_16 + V_12 ) ;
}
static void F_8 ( struct V_1 * V_11 )
{
T_1 V_17 , V_18 , V_19 , V_20 ;
unsigned int V_21 , V_22 ;
unsigned int V_23 ;
V_21 = 1000 / V_11 -> V_24 + 0x01 ;
V_22 = 8000 / V_11 -> V_24 + 0x01 ;
V_23 = 5 ;
V_17 = ( 8 << 24 ) | ( 0xa << 16 ) | ( 0x6 << 8 ) | V_23 ;
V_18 = ( 7 << 24 ) | ( 5 * V_23 << 16 ) | ( ( 3 * V_23 ) / 2 ) << 8 |
( 4 * V_23 ) ;
V_19 = ( ( F_9 ( 0x64 , V_22 ) + 0xa ) << 24 ) |
( F_9 ( 0x150 , V_22 ) << 16 ) ;
V_20 = ( 2 * V_23 ) << 16 | F_9 ( 80 + 52 * V_21 , V_22 ) << 8 |
F_9 ( 0x40 , V_22 ) ;
F_7 ( V_17 , V_11 -> V_16 + V_25 ) ;
F_7 ( V_18 , V_11 -> V_16 + V_26 ) ;
F_7 ( V_19 , V_11 -> V_16 + V_27 ) ;
F_7 ( V_20 , V_11 -> V_16 + V_28 ) ;
}
static void F_10 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_29 , V_30 , V_30 ) ;
}
static void F_11 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_29 , V_30 , 0 ) ;
}
static void F_12 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_29 , V_31 , V_31 ) ;
F_5 ( V_11 , V_29 , V_31 , 0 ) ;
}
static int F_13 ( struct V_1 * V_11 )
{
struct V_32 * V_33 = V_11 -> V_33 ;
int V_34 ;
if ( ++ V_11 -> V_35 != 1 )
return 0 ;
V_11 -> V_24 = V_11 -> V_36 . V_37 * 3 * 21 / ( 1 * 1000 * 10 ) ;
V_34 = F_14 ( V_11 -> V_38 , V_11 -> V_24 * 1000000 ) ;
if ( V_34 < 0 ) {
F_15 ( V_33 , L_1 , V_34 ) ;
goto V_39;
}
F_16 ( V_11 -> V_40 ) ;
V_34 = F_17 ( V_11 -> V_41 ) ;
if ( V_34 < 0 ) {
F_15 ( V_33 , L_2 , V_34 ) ;
goto V_42;
}
V_34 = F_17 ( V_11 -> V_43 ) ;
if ( V_34 < 0 ) {
F_15 ( V_33 , L_3 , V_34 ) ;
goto V_44;
}
F_10 ( V_11 ) ;
F_12 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
V_44:
F_18 ( V_11 -> V_41 ) ;
V_42:
F_19 ( V_11 -> V_40 ) ;
V_39:
V_11 -> V_35 -- ;
return V_34 ;
}
static void F_20 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_45 , V_46 , 0 ) ;
F_5 ( V_11 , V_45 , V_47 , 0 ) ;
}
static void F_21 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_45 , V_47 , 0 ) ;
F_5 ( V_11 , V_45 , V_48 , V_48 ) ;
F_5 ( V_11 , V_45 , V_48 , 0 ) ;
}
static void F_22 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_49 , V_50 , 0 ) ;
F_5 ( V_11 , V_49 , V_51 , 0 ) ;
}
static void F_23 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_49 , V_51 , 0 ) ;
F_5 ( V_11 , V_49 , V_52 , V_52 ) ;
F_5 ( V_11 , V_49 , V_52 , 0 ) ;
}
static bool F_24 ( struct V_1 * V_11 )
{
T_1 V_53 ;
V_53 = F_6 ( V_11 -> V_16 + V_45 ) ;
return ( ( V_53 & V_46 ) == 1 ) ? true : false ;
}
static void F_25 ( struct V_1 * V_11 , bool V_54 )
{
if ( V_54 && ! F_24 ( V_11 ) )
F_5 ( V_11 , V_45 , V_46 , V_46 ) ;
else if ( ! V_54 && F_24 ( V_11 ) )
F_5 ( V_11 , V_45 , V_46 , 0 ) ;
}
static void F_26 ( struct V_1 * V_11 )
{
T_1 V_55 = V_56 ;
if ( V_11 -> V_57 & V_58 ) {
V_55 = V_59 ;
if ( ( V_11 -> V_57 & V_60 ) &&
! ( V_11 -> V_57 & V_61 ) )
V_55 = V_62 ;
}
F_7 ( V_55 , V_11 -> V_16 + V_63 ) ;
}
static void F_27 ( struct V_1 * V_11 )
{
struct V_64 * V_36 = & V_11 -> V_36 ;
T_1 V_65 , V_66 ;
T_1 V_67 ;
if ( V_11 -> V_68 == V_69 )
V_65 = 2 ;
else
V_65 = 3 ;
V_66 = V_36 -> V_70 * V_65 ;
V_67 = V_66 ;
switch ( V_11 -> V_68 ) {
case V_71 :
V_67 |= V_72 ;
break;
case V_73 :
V_67 |= V_74 ;
break;
case V_75 :
V_67 |= V_76 ;
break;
case V_69 :
V_67 |= V_77 ;
break;
}
F_7 ( V_36 -> V_78 , V_11 -> V_16 + V_79 ) ;
F_7 ( V_67 , V_11 -> V_16 + V_80 ) ;
F_7 ( V_66 , V_11 -> V_16 + V_81 ) ;
}
static void F_28 ( struct V_1 * V_11 )
{
T_1 V_82 ;
switch ( V_11 -> V_83 ) {
case 1 :
V_82 = 1 << 2 ;
break;
case 2 :
V_82 = 3 << 2 ;
break;
case 3 :
V_82 = 7 << 2 ;
break;
case 4 :
V_82 = 0xf << 2 ;
break;
default:
V_82 = 0xf << 2 ;
break;
}
F_7 ( V_82 , V_11 -> V_16 + V_84 ) ;
}
static void F_29 ( struct V_1 * V_11 )
{
unsigned int V_85 ;
T_1 V_82 ;
switch ( V_11 -> V_68 ) {
case V_71 :
V_82 = V_72 ;
V_85 = 3 ;
break;
case V_73 :
V_82 = V_76 ;
V_85 = 3 ;
break;
case V_75 :
V_82 = V_74 ;
V_85 = 3 ;
break;
case V_69 :
V_82 = V_77 ;
V_85 = 2 ;
break;
default:
V_82 = V_72 ;
V_85 = 3 ;
break;
}
V_82 += V_11 -> V_36 . V_70 * V_85 & V_86 ;
F_7 ( V_82 , V_11 -> V_16 + V_80 ) ;
}
static void F_30 ( struct V_1 * V_11 )
{
unsigned int V_87 ;
unsigned int V_88 ;
unsigned int V_89 ;
unsigned int V_85 ;
struct V_64 * V_36 = & V_11 -> V_36 ;
if ( V_11 -> V_68 == V_69 )
V_85 = 2 ;
else
V_85 = 3 ;
F_7 ( V_36 -> V_90 , V_11 -> V_16 + V_91 ) ;
F_7 ( V_36 -> V_92 , V_11 -> V_16 + V_93 ) ;
F_7 ( V_36 -> V_94 , V_11 -> V_16 + V_95 ) ;
F_7 ( V_36 -> V_78 , V_11 -> V_16 + V_79 ) ;
V_87 = ( V_36 -> V_96 * V_85 - 10 ) ;
if ( V_11 -> V_57 & V_61 )
V_88 =
( V_36 -> V_97 * V_85 - 10 ) ;
else
V_88 = ( ( V_36 -> V_97 + V_36 -> V_96 ) *
V_85 - 10 ) ;
V_89 = ( V_36 -> V_98 * V_85 - 12 ) ;
F_7 ( V_87 , V_11 -> V_16 + V_99 ) ;
F_7 ( V_88 , V_11 -> V_16 + V_100 ) ;
F_7 ( V_89 , V_11 -> V_16 + V_101 ) ;
F_29 ( V_11 ) ;
}
static void F_31 ( struct V_1 * V_11 )
{
F_7 ( 0 , V_11 -> V_16 + V_102 ) ;
F_7 ( 1 , V_11 -> V_16 + V_102 ) ;
}
static void F_32 ( struct V_1 * V_11 )
{
if ( F_33 ( V_11 -> V_35 == 0 ) )
return;
if ( -- V_11 -> V_35 != 0 )
return;
F_22 ( V_11 ) ;
F_20 ( V_11 ) ;
F_11 ( V_11 ) ;
F_18 ( V_11 -> V_41 ) ;
F_18 ( V_11 -> V_43 ) ;
F_19 ( V_11 -> V_40 ) ;
}
static void F_34 ( struct V_1 * V_11 )
{
int V_34 ;
if ( V_11 -> V_103 )
return;
if ( V_11 -> V_104 ) {
if ( F_35 ( V_11 -> V_104 ) ) {
F_36 ( L_4 ) ;
return;
}
}
V_34 = F_13 ( V_11 ) ;
if ( V_34 < 0 ) {
F_36 ( L_5 ) ;
return;
}
F_28 ( V_11 ) ;
F_21 ( V_11 ) ;
F_23 ( V_11 ) ;
F_25 ( V_11 , 0 ) ;
F_26 ( V_11 ) ;
F_27 ( V_11 ) ;
F_30 ( V_11 ) ;
F_26 ( V_11 ) ;
F_25 ( V_11 , 1 ) ;
F_31 ( V_11 ) ;
V_11 -> V_103 = true ;
}
static void F_37 ( struct V_1 * V_11 )
{
if ( ! V_11 -> V_103 )
return;
if ( V_11 -> V_104 ) {
if ( F_38 ( V_11 -> V_104 ) ) {
F_36 ( L_6 ) ;
return;
}
}
F_32 ( V_11 ) ;
V_11 -> V_103 = false ;
}
static void F_39 ( struct V_2 * V_4 )
{
F_40 ( V_4 ) ;
}
static bool F_41 ( struct V_2 * V_4 ,
const struct V_105 * V_106 ,
struct V_105 * V_107 )
{
return true ;
}
static void F_42 ( struct V_2 * V_4 ,
struct V_105 * V_106 ,
struct V_105 * V_108 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
V_11 -> V_36 . V_37 = V_108 -> clock ;
V_11 -> V_36 . V_70 = V_108 -> V_109 ;
V_11 -> V_36 . V_97 = V_108 -> V_110 - V_108 -> V_111 ;
V_11 -> V_36 . V_98 = V_108 -> V_112 - V_108 -> V_109 ;
V_11 -> V_36 . V_96 = V_108 -> V_111 - V_108 -> V_112 ;
V_11 -> V_36 . V_78 = V_108 -> V_113 ;
V_11 -> V_36 . V_92 = V_108 -> V_114 - V_108 -> V_115 ;
V_11 -> V_36 . V_94 = V_108 -> V_116 - V_108 -> V_113 ;
V_11 -> V_36 . V_90 = V_108 -> V_115 - V_108 -> V_116 ;
}
static void F_43 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_37 ( V_11 ) ;
}
static void F_44 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_34 ( V_11 ) ;
}
static enum V_117 F_45 (
struct V_5 * V_118 , bool V_119 )
{
return V_120 ;
}
static int F_46 ( struct V_5 * V_118 )
{
struct V_1 * V_11 = F_3 ( V_118 ) ;
return F_47 ( V_11 -> V_104 ) ;
}
static int F_48 ( struct V_121 * V_122 ,
struct V_2 * V_4 )
{
int V_34 ;
if ( ! V_122 )
return - V_123 ;
V_4 -> V_122 = V_122 ;
V_122 -> V_4 = V_4 ;
V_34 = F_49 ( V_4 -> V_33 , V_122 ) ;
if ( V_34 ) {
F_36 ( L_7 ) ;
V_4 -> V_122 = NULL ;
V_122 -> V_4 = NULL ;
}
return V_34 ;
}
static int F_50 ( struct V_124 * V_125 , struct V_1 * V_11 )
{
int V_34 ;
V_34 = F_51 ( V_125 , & V_11 -> V_7 , & V_126 ,
V_127 ) ;
if ( V_34 ) {
F_36 ( L_8 ) ;
return V_34 ;
}
F_52 ( & V_11 -> V_7 , & V_128 ) ;
V_11 -> V_7 . V_129 = V_130 ;
F_53 ( & V_11 -> V_7 , & V_11 -> V_4 ) ;
if ( V_11 -> V_104 ) {
V_34 = F_54 ( V_11 -> V_104 , & V_11 -> V_7 ) ;
if ( V_34 ) {
F_36 ( L_9 ) ;
goto V_131;
}
}
return 0 ;
V_131:
F_55 ( & V_11 -> V_7 ) ;
return V_34 ;
}
static int F_56 ( struct V_124 * V_125 , struct V_1 * V_11 )
{
int V_34 ;
V_34 = F_57 ( V_125 , & V_11 -> V_4 , & V_132 ,
V_133 , NULL ) ;
if ( V_34 ) {
F_36 ( L_10 ) ;
return V_34 ;
}
F_58 ( & V_11 -> V_4 , & V_134 ) ;
V_11 -> V_4 . V_135 = 1 ;
V_34 = F_48 ( V_11 -> V_122 , & V_11 -> V_4 ) ;
if ( V_34 ) {
V_34 = F_50 ( V_125 , V_11 ) ;
if ( V_34 )
goto V_136;
}
return 0 ;
V_136:
F_40 ( & V_11 -> V_4 ) ;
return V_34 ;
}
static void F_59 ( struct V_1 * V_11 )
{
F_40 ( & V_11 -> V_4 ) ;
if ( V_11 -> V_7 . V_33 )
F_55 ( & V_11 -> V_7 ) ;
}
static void F_60 ( struct V_137 * V_138 )
{
struct V_1 * V_11 = F_2 ( V_138 , struct V_1 , V_139 ) ;
F_13 ( V_11 ) ;
}
static void F_61 ( struct V_137 * V_138 )
{
struct V_1 * V_11 = F_2 ( V_138 , struct V_1 , V_139 ) ;
F_32 ( V_11 ) ;
}
static int F_62 ( struct V_8 * V_10 ,
struct V_140 * V_32 )
{
struct V_1 * V_11 = F_4 ( V_10 ) ;
V_11 -> V_83 = V_32 -> V_83 ;
V_11 -> V_68 = V_32 -> V_68 ;
V_11 -> V_57 = V_32 -> V_57 ;
if ( V_11 -> V_7 . V_33 )
F_63 ( V_11 -> V_7 . V_33 ) ;
return 0 ;
}
static int F_64 ( struct V_8 * V_10 ,
struct V_140 * V_32 )
{
struct V_1 * V_11 = F_4 ( V_10 ) ;
if ( V_11 -> V_7 . V_33 )
F_63 ( V_11 -> V_7 . V_33 ) ;
return 0 ;
}
static int F_65 ( struct V_32 * V_33 , struct V_32 * V_141 , void * V_14 )
{
int V_34 ;
struct V_124 * V_125 = V_14 ;
struct V_1 * V_11 = F_66 ( V_33 ) ;
V_34 = F_67 ( V_125 , & V_11 -> V_139 ) ;
if ( V_34 < 0 ) {
F_15 ( V_33 , L_11 ,
V_33 -> V_142 -> V_143 , V_34 ) ;
return V_34 ;
}
V_34 = F_68 ( & V_11 -> V_10 ) ;
if ( V_34 < 0 ) {
F_15 ( V_33 , L_12 , V_34 ) ;
goto V_144;
}
V_34 = F_56 ( V_125 , V_11 ) ;
if ( V_34 ) {
F_36 ( L_13 , V_34 ) ;
goto V_145;
}
return 0 ;
V_145:
F_69 ( & V_11 -> V_10 ) ;
V_144:
F_70 ( V_125 , & V_11 -> V_139 ) ;
return V_34 ;
}
static void F_71 ( struct V_32 * V_33 , struct V_32 * V_141 ,
void * V_14 )
{
struct V_124 * V_125 = V_14 ;
struct V_1 * V_11 = F_66 ( V_33 ) ;
F_59 ( V_11 ) ;
F_69 ( & V_11 -> V_10 ) ;
F_70 ( V_125 , & V_11 -> V_139 ) ;
}
static int F_72 ( struct V_146 * V_147 )
{
struct V_1 * V_11 ;
struct V_32 * V_33 = & V_147 -> V_33 ;
struct V_148 * V_149 , * V_150 ;
struct V_151 * V_16 ;
int V_152 ;
int V_34 ;
V_11 = F_73 ( V_33 , sizeof( * V_11 ) , V_153 ) ;
if ( ! V_11 )
return - V_154 ;
V_11 -> V_10 . V_155 = & V_156 ;
V_11 -> V_10 . V_33 = V_33 ;
V_150 = F_74 ( V_33 -> V_142 , NULL ) ;
if ( V_150 ) {
V_149 = F_75 ( V_150 ) ;
if ( ! V_149 ) {
F_15 ( V_33 , L_14 ) ;
return - V_157 ;
}
V_11 -> V_122 = F_76 ( V_149 ) ;
V_11 -> V_104 = F_77 ( V_149 ) ;
F_78 ( V_149 ) ;
if ( ! V_11 -> V_122 && ! V_11 -> V_104 ) {
F_79 ( V_33 , L_15 ) ;
return - V_158 ;
}
}
V_11 -> V_41 = F_80 ( V_33 , L_16 ) ;
if ( F_81 ( V_11 -> V_41 ) ) {
V_34 = F_82 ( V_11 -> V_41 ) ;
F_15 ( V_33 , L_17 , V_34 ) ;
return V_34 ;
}
V_11 -> V_43 = F_80 ( V_33 , L_18 ) ;
if ( F_81 ( V_11 -> V_43 ) ) {
V_34 = F_82 ( V_11 -> V_43 ) ;
F_15 ( V_33 , L_19 , V_34 ) ;
return V_34 ;
}
V_11 -> V_38 = F_80 ( V_33 , L_20 ) ;
if ( F_81 ( V_11 -> V_38 ) ) {
V_34 = F_82 ( V_11 -> V_38 ) ;
F_15 ( V_33 , L_21 , V_34 ) ;
return V_34 ;
}
V_16 = F_83 ( V_147 , V_159 , 0 ) ;
V_11 -> V_16 = F_84 ( V_33 , V_16 ) ;
if ( F_81 ( V_11 -> V_16 ) ) {
V_34 = F_82 ( V_11 -> V_16 ) ;
F_15 ( V_33 , L_22 , V_34 ) ;
return V_34 ;
}
V_11 -> V_40 = F_85 ( V_33 , L_23 ) ;
if ( F_81 ( V_11 -> V_40 ) ) {
V_34 = F_82 ( V_11 -> V_40 ) ;
F_15 ( V_33 , L_24 , V_34 ) ;
return V_34 ;
}
V_152 = F_86 ( V_33 -> V_142 , V_160 ) ;
if ( V_152 < 0 ) {
F_15 ( V_33 , L_25 , V_152 ) ;
return V_152 ;
}
V_34 = F_87 ( V_33 , V_33 -> V_142 , & V_11 -> V_139 , V_152 ,
& V_161 ) ;
if ( V_34 ) {
F_15 ( V_33 , L_26 , V_34 ) ;
return V_34 ;
}
F_88 ( V_147 , V_11 ) ;
return F_89 ( & V_147 -> V_33 , & V_162 ) ;
}
static int F_90 ( struct V_146 * V_147 )
{
struct V_1 * V_11 = F_91 ( V_147 ) ;
F_37 ( V_11 ) ;
F_92 ( & V_147 -> V_33 , & V_162 ) ;
return 0 ;
}
