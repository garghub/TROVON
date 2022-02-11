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
T_1 V_21 , V_22 ;
V_21 = 1000 / V_11 -> V_23 + 0x01 ;
V_22 = 8000 / V_11 -> V_23 + 0x01 ;
V_17 = V_24 | V_25 << 8 | V_26 << 16 | V_27 << 24 ;
V_18 = 4 * V_24 | ( 3 * V_24 / 2 ) << 8 | 5 * V_24 << 16 |
V_28 << 24 ;
V_19 = ( ( F_9 ( 0x64 , V_22 ) + 0xa ) << 24 ) |
( F_9 ( 0x150 , V_22 ) << 16 ) ;
V_20 = F_9 ( 0x40 , V_22 ) | ( 2 * V_24 ) << 16 |
F_9 ( 80 + 52 * V_21 , V_22 ) << 8 ;
F_7 ( V_17 , V_11 -> V_16 + V_29 ) ;
F_7 ( V_18 , V_11 -> V_16 + V_30 ) ;
F_7 ( V_19 , V_11 -> V_16 + V_31 ) ;
F_7 ( V_20 , V_11 -> V_16 + V_32 ) ;
}
static void F_10 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_33 , V_34 , V_34 ) ;
}
static void F_11 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_33 , V_34 , 0 ) ;
}
static void F_12 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_33 , V_35 , V_35 ) ;
F_5 ( V_11 , V_33 , V_35 , 0 ) ;
}
static int F_13 ( struct V_1 * V_11 )
{
struct V_36 * V_37 = V_11 -> V_37 ;
int V_38 ;
T_2 V_39 , V_40 ;
T_1 V_41 , V_42 , V_43 , V_44 , V_45 ;
if ( ++ V_11 -> V_46 != 1 )
return 0 ;
switch ( V_11 -> V_47 ) {
case V_48 :
V_43 = 16 ;
break;
case V_49 :
V_43 = 18 ;
break;
case V_50 :
case V_51 :
default:
V_43 = 24 ;
break;
}
V_39 = V_11 -> V_52 . V_53 * 1000 ;
V_41 = V_11 -> V_52 . V_54 + V_11 -> V_52 . V_55 + V_11 -> V_52 . V_56 +
V_11 -> V_52 . V_57 ;
V_42 = V_41 * V_43 ;
V_44 = V_24 + V_25 + V_26 + V_27 +
V_28 ;
V_45 = V_44 * V_11 -> V_58 * 8 ;
V_40 = V_42 + V_45 ;
V_11 -> V_23 = F_14 ( V_39 * V_40 ,
V_41 * V_11 -> V_58 ) ;
V_38 = F_15 ( V_11 -> V_59 , V_11 -> V_23 ) ;
if ( V_38 < 0 ) {
F_16 ( V_37 , L_1 , V_38 ) ;
goto V_60;
}
F_17 ( V_11 -> V_61 ) ;
V_38 = F_18 ( V_11 -> V_62 ) ;
if ( V_38 < 0 ) {
F_16 ( V_37 , L_2 , V_38 ) ;
goto V_63;
}
V_38 = F_18 ( V_11 -> V_64 ) ;
if ( V_38 < 0 ) {
F_16 ( V_37 , L_3 , V_38 ) ;
goto V_65;
}
F_10 ( V_11 ) ;
F_12 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
V_65:
F_19 ( V_11 -> V_62 ) ;
V_63:
F_20 ( V_11 -> V_61 ) ;
V_60:
V_11 -> V_46 -- ;
return V_38 ;
}
static void F_21 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_66 , V_67 , 0 ) ;
F_5 ( V_11 , V_66 , V_68 , 0 ) ;
}
static void F_22 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_66 , V_68 , 0 ) ;
F_5 ( V_11 , V_66 , V_69 , V_69 ) ;
F_5 ( V_11 , V_66 , V_69 , 0 ) ;
}
static void F_23 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_70 , V_71 , 0 ) ;
F_5 ( V_11 , V_70 , V_72 , 0 ) ;
}
static void F_24 ( struct V_1 * V_11 )
{
F_5 ( V_11 , V_70 , V_72 , 0 ) ;
F_5 ( V_11 , V_70 , V_73 , V_73 ) ;
F_5 ( V_11 , V_70 , V_73 , 0 ) ;
}
static bool F_25 ( struct V_1 * V_11 )
{
T_1 V_74 ;
V_74 = F_6 ( V_11 -> V_16 + V_66 ) ;
return ( ( V_74 & V_67 ) == 1 ) ? true : false ;
}
static void F_26 ( struct V_1 * V_11 , bool V_75 )
{
if ( V_75 && ! F_25 ( V_11 ) )
F_5 ( V_11 , V_66 , V_67 , V_67 ) ;
else if ( ! V_75 && F_25 ( V_11 ) )
F_5 ( V_11 , V_66 , V_67 , 0 ) ;
}
static void F_27 ( struct V_1 * V_11 )
{
T_1 V_76 = V_77 ;
if ( V_11 -> V_78 & V_79 ) {
V_76 = V_80 ;
if ( ( V_11 -> V_78 & V_81 ) &&
! ( V_11 -> V_78 & V_82 ) )
V_76 = V_83 ;
}
F_7 ( V_76 , V_11 -> V_16 + V_84 ) ;
}
static void F_28 ( struct V_1 * V_11 )
{
struct V_85 * V_52 = & V_11 -> V_52 ;
T_1 V_86 , V_87 ;
T_1 V_88 ;
if ( V_11 -> V_47 == V_48 )
V_86 = 2 ;
else
V_86 = 3 ;
V_87 = V_52 -> V_54 * V_86 ;
V_88 = V_87 ;
switch ( V_11 -> V_47 ) {
case V_51 :
V_88 |= V_89 ;
break;
case V_50 :
V_88 |= V_90 ;
break;
case V_49 :
V_88 |= V_91 ;
break;
case V_48 :
V_88 |= V_92 ;
break;
}
F_7 ( V_52 -> V_93 , V_11 -> V_16 + V_94 ) ;
F_7 ( V_88 , V_11 -> V_16 + V_95 ) ;
F_7 ( V_87 , V_11 -> V_16 + V_96 ) ;
}
static void F_29 ( struct V_1 * V_11 )
{
T_1 V_97 ;
switch ( V_11 -> V_58 ) {
case 1 :
V_97 = 1 << 2 ;
break;
case 2 :
V_97 = 3 << 2 ;
break;
case 3 :
V_97 = 7 << 2 ;
break;
case 4 :
V_97 = 0xf << 2 ;
break;
default:
V_97 = 0xf << 2 ;
break;
}
F_7 ( V_97 , V_11 -> V_16 + V_98 ) ;
}
static void F_30 ( struct V_1 * V_11 )
{
unsigned int V_99 ;
T_1 V_97 ;
switch ( V_11 -> V_47 ) {
case V_51 :
V_97 = V_89 ;
V_99 = 3 ;
break;
case V_50 :
V_97 = V_91 ;
V_99 = 3 ;
break;
case V_49 :
V_97 = V_90 ;
V_99 = 3 ;
break;
case V_48 :
V_97 = V_92 ;
V_99 = 2 ;
break;
default:
V_97 = V_89 ;
V_99 = 3 ;
break;
}
V_97 += V_11 -> V_52 . V_54 * V_99 & V_100 ;
F_7 ( V_97 , V_11 -> V_16 + V_95 ) ;
}
static void F_31 ( struct V_1 * V_11 )
{
unsigned int V_101 ;
unsigned int V_102 ;
unsigned int V_103 ;
unsigned int V_99 ;
struct V_85 * V_52 = & V_11 -> V_52 ;
if ( V_11 -> V_47 == V_48 )
V_99 = 2 ;
else
V_99 = 3 ;
F_7 ( V_52 -> V_104 , V_11 -> V_16 + V_105 ) ;
F_7 ( V_52 -> V_106 , V_11 -> V_16 + V_107 ) ;
F_7 ( V_52 -> V_108 , V_11 -> V_16 + V_109 ) ;
F_7 ( V_52 -> V_93 , V_11 -> V_16 + V_94 ) ;
V_101 = ( V_52 -> V_57 * V_99 - 10 ) ;
if ( V_11 -> V_78 & V_82 )
V_102 =
( V_52 -> V_55 * V_99 - 10 ) ;
else
V_102 = ( ( V_52 -> V_55 + V_52 -> V_57 ) *
V_99 - 10 ) ;
V_103 = ( V_52 -> V_56 * V_99 - 12 ) ;
F_7 ( V_101 , V_11 -> V_16 + V_110 ) ;
F_7 ( V_102 , V_11 -> V_16 + V_111 ) ;
F_7 ( V_103 , V_11 -> V_16 + V_112 ) ;
F_30 ( V_11 ) ;
}
static void F_32 ( struct V_1 * V_11 )
{
F_7 ( 0 , V_11 -> V_16 + V_113 ) ;
F_7 ( 1 , V_11 -> V_16 + V_113 ) ;
}
static void F_33 ( struct V_1 * V_11 )
{
if ( F_34 ( V_11 -> V_46 == 0 ) )
return;
if ( -- V_11 -> V_46 != 0 )
return;
F_23 ( V_11 ) ;
F_21 ( V_11 ) ;
F_11 ( V_11 ) ;
F_19 ( V_11 -> V_62 ) ;
F_19 ( V_11 -> V_64 ) ;
F_20 ( V_11 -> V_61 ) ;
}
static void F_35 ( struct V_1 * V_11 )
{
int V_38 ;
if ( V_11 -> V_114 )
return;
if ( V_11 -> V_115 ) {
if ( F_36 ( V_11 -> V_115 ) ) {
F_37 ( L_4 ) ;
return;
}
}
V_38 = F_13 ( V_11 ) ;
if ( V_38 < 0 ) {
F_37 ( L_5 ) ;
return;
}
F_29 ( V_11 ) ;
F_22 ( V_11 ) ;
F_24 ( V_11 ) ;
F_26 ( V_11 , 0 ) ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
F_31 ( V_11 ) ;
F_27 ( V_11 ) ;
F_26 ( V_11 , 1 ) ;
F_32 ( V_11 ) ;
V_11 -> V_114 = true ;
}
static void F_38 ( struct V_1 * V_11 )
{
if ( ! V_11 -> V_114 )
return;
if ( V_11 -> V_115 ) {
if ( F_39 ( V_11 -> V_115 ) ) {
F_37 ( L_6 ) ;
return;
}
}
F_33 ( V_11 ) ;
V_11 -> V_114 = false ;
}
static void F_40 ( struct V_2 * V_4 )
{
F_41 ( V_4 ) ;
}
static bool F_42 ( struct V_2 * V_4 ,
const struct V_116 * V_117 ,
struct V_116 * V_118 )
{
return true ;
}
static void F_43 ( struct V_2 * V_4 ,
struct V_116 * V_117 ,
struct V_116 * V_119 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
V_11 -> V_52 . V_53 = V_119 -> clock ;
V_11 -> V_52 . V_54 = V_119 -> V_120 ;
V_11 -> V_52 . V_55 = V_119 -> V_41 - V_119 -> V_121 ;
V_11 -> V_52 . V_56 = V_119 -> V_122 - V_119 -> V_120 ;
V_11 -> V_52 . V_57 = V_119 -> V_121 - V_119 -> V_122 ;
V_11 -> V_52 . V_93 = V_119 -> V_123 ;
V_11 -> V_52 . V_106 = V_119 -> V_124 - V_119 -> V_125 ;
V_11 -> V_52 . V_108 = V_119 -> V_126 - V_119 -> V_123 ;
V_11 -> V_52 . V_104 = V_119 -> V_125 - V_119 -> V_126 ;
}
static void F_44 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_38 ( V_11 ) ;
}
static void F_45 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_35 ( V_11 ) ;
}
static int F_46 ( struct V_5 * V_127 )
{
struct V_1 * V_11 = F_3 ( V_127 ) ;
return F_47 ( V_11 -> V_115 ) ;
}
static int F_48 ( struct V_128 * V_129 ,
struct V_2 * V_4 )
{
int V_38 ;
if ( ! V_129 )
return - V_130 ;
V_4 -> V_129 = V_129 ;
V_129 -> V_4 = V_4 ;
V_38 = F_49 ( V_4 -> V_37 , V_129 ) ;
if ( V_38 ) {
F_37 ( L_7 ) ;
V_4 -> V_129 = NULL ;
V_129 -> V_4 = NULL ;
}
return V_38 ;
}
static int F_50 ( struct V_131 * V_132 , struct V_1 * V_11 )
{
int V_38 ;
V_38 = F_51 ( V_132 , & V_11 -> V_7 , & V_133 ,
V_134 ) ;
if ( V_38 ) {
F_37 ( L_8 ) ;
return V_38 ;
}
F_52 ( & V_11 -> V_7 , & V_135 ) ;
V_11 -> V_7 . V_136 = V_137 ;
F_53 ( & V_11 -> V_7 , & V_11 -> V_4 ) ;
if ( V_11 -> V_115 ) {
V_38 = F_54 ( V_11 -> V_115 , & V_11 -> V_7 ) ;
if ( V_38 ) {
F_37 ( L_9 ) ;
goto V_138;
}
}
return 0 ;
V_138:
F_55 ( & V_11 -> V_7 ) ;
return V_38 ;
}
static int F_56 ( struct V_131 * V_132 , struct V_1 * V_11 )
{
int V_38 ;
V_38 = F_57 ( V_132 , & V_11 -> V_4 , & V_139 ,
V_140 , NULL ) ;
if ( V_38 ) {
F_37 ( L_10 ) ;
return V_38 ;
}
F_58 ( & V_11 -> V_4 , & V_141 ) ;
V_11 -> V_4 . V_142 = 1 ;
V_38 = F_48 ( V_11 -> V_129 , & V_11 -> V_4 ) ;
if ( V_38 ) {
V_38 = F_50 ( V_132 , V_11 ) ;
if ( V_38 )
goto V_143;
}
return 0 ;
V_143:
F_41 ( & V_11 -> V_4 ) ;
return V_38 ;
}
static void F_59 ( struct V_1 * V_11 )
{
F_41 ( & V_11 -> V_4 ) ;
if ( V_11 -> V_7 . V_37 )
F_55 ( & V_11 -> V_7 ) ;
}
static void F_60 ( struct V_144 * V_145 )
{
struct V_1 * V_11 = F_2 ( V_145 , struct V_1 , V_146 ) ;
F_13 ( V_11 ) ;
}
static void F_61 ( struct V_144 * V_145 )
{
struct V_1 * V_11 = F_2 ( V_145 , struct V_1 , V_146 ) ;
F_33 ( V_11 ) ;
}
static int F_62 ( struct V_8 * V_10 ,
struct V_147 * V_36 )
{
struct V_1 * V_11 = F_4 ( V_10 ) ;
V_11 -> V_58 = V_36 -> V_58 ;
V_11 -> V_47 = V_36 -> V_47 ;
V_11 -> V_78 = V_36 -> V_78 ;
if ( V_11 -> V_7 . V_37 )
F_63 ( V_11 -> V_7 . V_37 ) ;
return 0 ;
}
static int F_64 ( struct V_8 * V_10 ,
struct V_147 * V_36 )
{
struct V_1 * V_11 = F_4 ( V_10 ) ;
if ( V_11 -> V_7 . V_37 )
F_63 ( V_11 -> V_7 . V_37 ) ;
return 0 ;
}
static int F_65 ( struct V_36 * V_37 , struct V_36 * V_148 , void * V_14 )
{
int V_38 ;
struct V_131 * V_132 = V_14 ;
struct V_1 * V_11 = F_66 ( V_37 ) ;
V_38 = F_67 ( V_132 , & V_11 -> V_146 ) ;
if ( V_38 < 0 ) {
F_16 ( V_37 , L_11 ,
V_37 -> V_149 -> V_150 , V_38 ) ;
return V_38 ;
}
V_38 = F_68 ( & V_11 -> V_10 ) ;
if ( V_38 < 0 ) {
F_16 ( V_37 , L_12 , V_38 ) ;
goto V_151;
}
V_38 = F_56 ( V_132 , V_11 ) ;
if ( V_38 ) {
F_37 ( L_13 , V_38 ) ;
goto V_152;
}
return 0 ;
V_152:
F_69 ( & V_11 -> V_10 ) ;
V_151:
F_70 ( V_132 , & V_11 -> V_146 ) ;
return V_38 ;
}
static void F_71 ( struct V_36 * V_37 , struct V_36 * V_148 ,
void * V_14 )
{
struct V_131 * V_132 = V_14 ;
struct V_1 * V_11 = F_66 ( V_37 ) ;
F_59 ( V_11 ) ;
F_69 ( & V_11 -> V_10 ) ;
F_70 ( V_132 , & V_11 -> V_146 ) ;
}
static int F_72 ( struct V_153 * V_154 )
{
struct V_1 * V_11 ;
struct V_36 * V_37 = & V_154 -> V_37 ;
struct V_155 * V_156 , * V_157 ;
struct V_158 * V_16 ;
int V_159 ;
int V_38 ;
V_11 = F_73 ( V_37 , sizeof( * V_11 ) , V_160 ) ;
if ( ! V_11 )
return - V_161 ;
V_11 -> V_10 . V_162 = & V_163 ;
V_11 -> V_10 . V_37 = V_37 ;
V_157 = F_74 ( V_37 -> V_149 , NULL ) ;
if ( V_157 ) {
V_156 = F_75 ( V_157 ) ;
if ( ! V_156 ) {
F_16 ( V_37 , L_14 ) ;
return - V_164 ;
}
V_11 -> V_129 = F_76 ( V_156 ) ;
V_11 -> V_115 = F_77 ( V_156 ) ;
F_78 ( V_156 ) ;
if ( ! V_11 -> V_129 && ! V_11 -> V_115 ) {
F_79 ( V_37 , L_15 ) ;
return - V_165 ;
}
}
V_11 -> V_62 = F_80 ( V_37 , L_16 ) ;
if ( F_81 ( V_11 -> V_62 ) ) {
V_38 = F_82 ( V_11 -> V_62 ) ;
F_16 ( V_37 , L_17 , V_38 ) ;
return V_38 ;
}
V_11 -> V_64 = F_80 ( V_37 , L_18 ) ;
if ( F_81 ( V_11 -> V_64 ) ) {
V_38 = F_82 ( V_11 -> V_64 ) ;
F_16 ( V_37 , L_19 , V_38 ) ;
return V_38 ;
}
V_11 -> V_59 = F_80 ( V_37 , L_20 ) ;
if ( F_81 ( V_11 -> V_59 ) ) {
V_38 = F_82 ( V_11 -> V_59 ) ;
F_16 ( V_37 , L_21 , V_38 ) ;
return V_38 ;
}
V_16 = F_83 ( V_154 , V_166 , 0 ) ;
V_11 -> V_16 = F_84 ( V_37 , V_16 ) ;
if ( F_81 ( V_11 -> V_16 ) ) {
V_38 = F_82 ( V_11 -> V_16 ) ;
F_16 ( V_37 , L_22 , V_38 ) ;
return V_38 ;
}
V_11 -> V_61 = F_85 ( V_37 , L_23 ) ;
if ( F_81 ( V_11 -> V_61 ) ) {
V_38 = F_82 ( V_11 -> V_61 ) ;
F_16 ( V_37 , L_24 , V_38 ) ;
return V_38 ;
}
V_159 = F_86 ( V_37 -> V_149 , V_167 ) ;
if ( V_159 < 0 ) {
F_16 ( V_37 , L_25 , V_159 ) ;
return V_159 ;
}
V_38 = F_87 ( V_37 , V_37 -> V_149 , & V_11 -> V_146 , V_159 ,
& V_168 ) ;
if ( V_38 ) {
F_16 ( V_37 , L_26 , V_38 ) ;
return V_38 ;
}
F_88 ( V_154 , V_11 ) ;
return F_89 ( & V_154 -> V_37 , & V_169 ) ;
}
static int F_90 ( struct V_153 * V_154 )
{
struct V_1 * V_11 = F_91 ( V_154 ) ;
F_38 ( V_11 ) ;
F_92 ( & V_154 -> V_37 , & V_169 ) ;
return 0 ;
}
