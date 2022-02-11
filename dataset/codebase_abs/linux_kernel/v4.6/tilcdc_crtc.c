static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_3 ( & V_7 -> V_9 . V_10 ) ;
F_4 ( V_3 ) ;
F_5 ( & V_7 -> V_9 . V_10 ) ;
}
static void F_6 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_15 * V_16 ;
unsigned int V_17 , V_18 ;
T_1 V_19 , V_20 ;
F_8 ( V_14 -> V_21 , & V_17 , & V_18 ) ;
V_16 = F_9 ( V_14 , 0 ) ;
V_19 = V_16 -> V_22 + V_14 -> V_23 [ 0 ] +
V_12 -> V_24 * V_14 -> V_25 [ 0 ] +
V_12 -> V_26 * V_18 / 8 ;
V_20 = V_19 + ( V_12 -> V_27 . V_28 * V_14 -> V_25 [ 0 ] ) ;
F_10 ( V_7 , V_29 , V_19 ) ;
F_10 ( V_7 , V_30 , V_20 ) ;
if ( V_4 -> V_31 )
F_11 ( & V_4 -> V_5 ,
V_4 -> V_31 ) ;
V_4 -> V_31 = V_14 ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
if ( V_33 -> V_35 != 2 )
return;
F_13 ( V_7 , V_36 , V_37 ) ;
F_14 ( 250 , 1000 ) ;
F_15 ( V_7 , V_36 , V_37 ) ;
}
static void V_19 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
F_12 ( V_12 ) ;
F_15 ( V_7 , V_38 , V_39 ) ;
F_13 ( V_7 , V_40 , F_16 ( V_41 ) ) ;
F_13 ( V_7 , V_40 , V_42 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
F_15 ( V_7 , V_40 , V_42 ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
F_19 ( V_12 , V_43 ) ;
F_20 ( V_12 -> V_44 ) ;
F_21 ( V_12 ) ;
F_22 ( & V_4 -> V_5 ) ;
}
static int F_23 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
unsigned int V_17 , V_18 ;
F_8 ( V_14 -> V_21 , & V_17 , & V_18 ) ;
if ( V_14 -> V_25 [ 0 ] != V_12 -> V_27 . V_45 * V_18 / 8 ) {
F_24 ( V_7 -> V_7 ,
L_1 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_25 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_47 * V_48 ,
T_2 V_49 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
int V_50 ;
unsigned long V_51 ;
T_3 V_52 ;
T_4 V_53 ;
V_50 = F_23 ( V_12 , V_14 ) ;
if ( V_50 )
return V_50 ;
if ( V_4 -> V_48 ) {
F_24 ( V_7 -> V_7 , L_2 ) ;
return - V_54 ;
}
F_26 ( V_14 ) ;
V_12 -> V_55 -> V_14 = V_14 ;
F_27 ( V_7 -> V_7 ) ;
F_28 ( & V_4 -> V_56 , V_51 ) ;
V_53 = F_29 ( V_4 -> V_57 ,
1000000 / V_12 -> V_58 . V_59 ) ;
V_52 = F_30 ( F_31 ( V_53 , F_32 () ) ) ;
if ( V_52 >= V_60 )
F_6 ( V_12 , V_14 ) ;
else
V_4 -> V_61 = V_14 ;
V_4 -> V_48 = V_48 ;
F_33 ( & V_4 -> V_56 , V_51 ) ;
F_34 ( V_7 -> V_7 ) ;
return 0 ;
}
void F_19 ( struct V_11 * V_12 , int V_27 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
if ( V_27 != V_62 )
V_27 = V_43 ;
if ( V_4 -> V_63 == V_27 )
return;
V_4 -> V_63 = V_27 ;
if ( V_27 == V_62 ) {
F_27 ( V_7 -> V_7 ) ;
V_19 ( V_12 ) ;
} else {
V_4 -> V_64 = false ;
F_17 ( V_12 ) ;
if ( V_33 -> V_35 == 2 ) {
int V_65 = F_35 (
V_4 -> V_66 ,
V_4 -> V_64 ,
F_36 ( 50 ) ) ;
if ( V_65 == 0 )
F_24 ( V_7 -> V_7 , L_3 ) ;
}
F_34 ( V_7 -> V_7 ) ;
if ( V_4 -> V_61 ) {
F_11 ( & V_4 -> V_5 ,
V_4 -> V_61 ) ;
V_4 -> V_61 = NULL ;
}
if ( V_4 -> V_31 ) {
F_11 ( & V_4 -> V_5 ,
V_4 -> V_31 ) ;
V_4 -> V_31 = NULL ;
}
F_37 ( & V_4 -> V_5 , V_33 -> V_67 ) ;
}
}
static bool F_38 ( struct V_11 * V_12 ,
const struct V_68 * V_27 ,
struct V_68 * V_69 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
if ( ! V_4 -> V_70 )
return true ;
V_69 -> V_71 = V_27 -> V_72 - V_27 -> V_73 ;
V_69 -> V_51 |= V_74 ;
if ( V_27 -> V_51 & V_75 ) {
V_69 -> V_51 |= V_76 ;
V_69 -> V_51 &= ~ V_75 ;
} else {
V_69 -> V_51 |= V_75 ;
V_69 -> V_51 &= ~ V_76 ;
}
return true ;
}
static void F_39 ( struct V_11 * V_12 )
{
F_19 ( V_12 , V_43 ) ;
}
static void F_40 ( struct V_11 * V_12 )
{
F_19 ( V_12 , V_62 ) ;
}
static int F_41 ( struct V_11 * V_12 ,
struct V_68 * V_27 ,
struct V_68 * V_69 ,
int V_26 , int V_24 ,
struct V_13 * V_77 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
const struct V_78 * V_79 = V_4 -> V_79 ;
T_2 V_80 , V_81 , V_82 , V_83 , V_84 , V_85 , V_86 ;
int V_65 ;
V_65 = F_42 ( V_12 , V_27 ) ;
if ( F_43 ( V_65 ) )
return V_65 ;
if ( F_43 ( ! V_79 ) )
return - V_46 ;
V_65 = F_23 ( V_12 , V_12 -> V_55 -> V_14 ) ;
if ( V_65 )
return V_65 ;
F_27 ( V_7 -> V_7 ) ;
V_80 = F_44 ( V_7 , V_38 ) & ~ 0x00000770 ;
switch ( V_79 -> V_87 ) {
case 1 :
V_80 |= F_45 ( V_88 ) ;
break;
case 2 :
V_80 |= F_45 ( V_89 ) ;
break;
case 4 :
V_80 |= F_45 ( V_90 ) ;
break;
case 8 :
V_80 |= F_45 ( V_91 ) ;
break;
case 16 :
V_80 |= F_45 ( V_92 ) ;
break;
default:
return - V_46 ;
}
V_80 |= ( V_79 -> V_93 << 8 ) ;
F_10 ( V_7 , V_38 , V_80 ) ;
V_81 = V_27 -> V_94 - V_27 -> V_72 ;
V_82 = V_27 -> V_73 - V_27 -> V_45 ;
V_83 = V_27 -> V_72 - V_27 -> V_73 ;
V_84 = V_27 -> V_95 - V_27 -> V_96 ;
V_85 = V_27 -> V_97 - V_27 -> V_28 ;
V_86 = V_27 -> V_96 - V_27 -> V_97 ;
F_46 ( L_4 ,
V_27 -> V_45 , V_27 -> V_28 , V_81 , V_82 , V_83 , V_84 , V_85 , V_86 ) ;
V_80 = F_44 ( V_7 , V_98 ) & ~ 0x000fff00 ;
V_80 |= F_47 ( V_79 -> V_99 ) |
F_48 ( V_79 -> V_100 ) ;
if ( V_33 -> V_35 == 2 ) {
V_80 &= ~ 0x78000033 ;
V_80 |= ( ( V_82 - 1 ) & 0x300 ) >> 8 ;
V_80 |= ( ( V_81 - 1 ) & 0x300 ) >> 4 ;
V_80 |= ( ( V_83 - 1 ) & 0x3c0 ) << 21 ;
}
F_10 ( V_7 , V_98 , V_80 ) ;
V_80 = ( ( ( V_27 -> V_45 >> 4 ) - 1 ) << 4 ) |
( ( ( V_81 - 1 ) & 0xff ) << 24 ) |
( ( ( V_82 - 1 ) & 0xff ) << 16 ) |
( ( ( V_83 - 1 ) & 0x3f ) << 10 ) ;
if ( V_33 -> V_35 == 2 )
V_80 |= ( ( ( V_27 -> V_45 >> 4 ) - 1 ) & 0x40 ) >> 3 ;
F_10 ( V_7 , V_101 , V_80 ) ;
V_80 = ( ( V_27 -> V_28 - 1 ) & 0x3ff ) |
( ( V_84 & 0xff ) << 24 ) |
( ( V_85 & 0xff ) << 16 ) |
( ( ( V_86 - 1 ) & 0x3f ) << 10 ) ;
F_10 ( V_7 , V_102 , V_80 ) ;
if ( V_33 -> V_35 == 2 ) {
if ( ( V_27 -> V_28 - 1 ) & 0x400 ) {
F_13 ( V_7 , V_98 ,
V_103 ) ;
} else {
F_15 ( V_7 , V_98 ,
V_103 ) ;
}
}
V_80 = F_44 ( V_7 , V_40 ) &
~ ( V_104 | V_105 | V_106 |
V_107 | V_108 | 0x000ff000 ) ;
V_80 |= V_104 ;
if ( V_79 -> V_109 )
V_80 |= V_110 ;
if ( V_33 -> V_35 == 2 ) {
unsigned int V_17 , V_18 ;
F_8 ( V_12 -> V_55 -> V_14 -> V_21 , & V_17 , & V_18 ) ;
switch ( V_18 ) {
case 16 :
break;
case 32 :
V_80 |= V_108 ;
case 24 :
V_80 |= V_107 ;
break;
default:
F_24 ( V_7 -> V_7 , L_5 ) ;
return - V_46 ;
}
}
V_80 |= V_79 -> V_111 < 12 ;
F_10 ( V_7 , V_40 , V_80 ) ;
if ( V_79 -> V_112 )
F_13 ( V_7 , V_98 , V_113 ) ;
else
F_15 ( V_7 , V_98 , V_113 ) ;
if ( V_79 -> V_114 )
F_13 ( V_7 , V_98 , V_115 ) ;
else
F_15 ( V_7 , V_98 , V_115 ) ;
if ( V_79 -> V_116 )
F_13 ( V_7 , V_98 , V_117 ) ;
else
F_15 ( V_7 , V_98 , V_117 ) ;
if ( V_69 -> V_51 & V_75 )
F_13 ( V_7 , V_98 , V_118 ) ;
else
F_15 ( V_7 , V_98 , V_118 ) ;
if ( V_27 -> V_51 & V_119 )
F_13 ( V_7 , V_98 , V_120 ) ;
else
F_15 ( V_7 , V_98 , V_120 ) ;
if ( V_79 -> V_121 )
F_13 ( V_7 , V_40 , V_122 ) ;
else
F_15 ( V_7 , V_40 , V_122 ) ;
F_26 ( V_12 -> V_55 -> V_14 ) ;
F_6 ( V_12 , V_12 -> V_55 -> V_14 ) ;
F_49 ( V_12 ) ;
F_34 ( V_7 -> V_7 ) ;
return 0 ;
}
static int F_50 ( struct V_11 * V_12 , int V_26 , int V_24 ,
struct V_13 * V_77 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
int V_50 ;
V_50 = F_23 ( V_12 , V_12 -> V_55 -> V_14 ) ;
if ( V_50 )
return V_50 ;
F_26 ( V_12 -> V_55 -> V_14 ) ;
F_27 ( V_7 -> V_7 ) ;
F_6 ( V_12 , V_12 -> V_55 -> V_14 ) ;
F_34 ( V_7 -> V_7 ) ;
return 0 ;
}
int F_51 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
int V_123 = 0 ;
if ( V_33 -> V_35 == 1 )
V_123 = 1024 ;
else if ( V_33 -> V_35 == 2 )
V_123 = 2048 ;
return V_123 ;
}
int F_42 ( struct V_11 * V_12 , struct V_68 * V_27 )
{
struct V_32 * V_33 = V_12 -> V_7 -> V_34 ;
unsigned int V_124 ;
T_2 V_81 , V_82 , V_83 , V_84 , V_85 , V_86 ;
if ( V_27 -> V_45 > F_51 ( V_12 ) )
return V_125 ;
if ( V_27 -> V_45 & 0xf )
return V_125 ;
if ( V_27 -> V_28 > 2048 )
return V_126 ;
F_46 ( L_6 ,
V_27 -> V_45 , V_27 -> V_28 ,
F_52 ( V_27 ) , V_27 -> clock ) ;
V_81 = V_27 -> V_94 - V_27 -> V_72 ;
V_82 = V_27 -> V_73 - V_27 -> V_45 ;
V_83 = V_27 -> V_72 - V_27 -> V_73 ;
V_84 = V_27 -> V_95 - V_27 -> V_96 ;
V_85 = V_27 -> V_97 - V_27 -> V_28 ;
V_86 = V_27 -> V_96 - V_27 -> V_97 ;
if ( ( V_81 - 1 ) & ~ 0x3ff ) {
F_46 ( L_7 ) ;
return V_127 ;
}
if ( ( V_82 - 1 ) & ~ 0x3ff ) {
F_46 ( L_8 ) ;
return V_127 ;
}
if ( ( V_83 - 1 ) & ~ 0x3ff ) {
F_46 ( L_9 ) ;
return V_128 ;
}
if ( V_84 & ~ 0xff ) {
F_46 ( L_10 ) ;
return V_129 ;
}
if ( V_85 & ~ 0xff ) {
F_46 ( L_11 ) ;
return V_129 ;
}
if ( ( V_86 - 1 ) & ~ 0x3f ) {
F_46 ( L_12 ) ;
return V_130 ;
}
if ( V_27 -> clock > V_33 -> V_131 ) {
F_46 ( L_13 ) ;
return V_132 ;
}
if ( V_27 -> V_45 > V_33 -> V_123 )
return V_133 ;
V_124 = V_27 -> V_45 * V_27 -> V_28 *
F_52 ( V_27 ) ;
if ( V_124 > V_33 -> V_134 ) {
F_46 ( L_14 ) ;
return V_135 ;
}
return V_136 ;
}
void F_53 ( struct V_11 * V_12 ,
const struct V_78 * V_79 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_79 = V_79 ;
}
void F_54 ( struct V_11 * V_12 ,
bool V_70 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
V_4 -> V_70 = V_70 ;
}
void F_49 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
int V_63 = V_4 -> V_63 ;
unsigned long V_137 ;
const unsigned V_138 = 2 ;
int V_65 ;
F_27 ( V_7 -> V_7 ) ;
if ( V_63 == V_62 )
F_19 ( V_12 , V_43 ) ;
V_65 = F_55 ( V_33 -> V_139 , V_12 -> V_27 . clock * 1000 * V_138 ) ;
if ( V_65 < 0 ) {
F_24 ( V_7 -> V_7 , L_15 ,
V_12 -> V_27 . clock ) ;
goto V_140;
}
V_137 = F_56 ( V_33 -> V_139 ) ;
F_46 ( L_16 ,
V_137 , V_12 -> V_27 . clock , V_138 ) ;
F_10 ( V_7 , V_141 , F_57 ( V_138 ) |
V_142 ) ;
if ( V_33 -> V_35 == 2 )
F_13 ( V_7 , V_143 ,
V_144 | V_145 |
V_146 ) ;
if ( V_63 == V_62 )
F_19 ( V_12 , V_62 ) ;
V_140:
F_34 ( V_7 -> V_7 ) ;
}
T_5 F_58 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_7 ( V_12 ) ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_32 * V_33 = V_7 -> V_34 ;
T_2 V_147 ;
V_147 = F_59 ( V_7 ) ;
F_60 ( V_7 , V_147 ) ;
if ( V_147 & V_148 ) {
unsigned long V_51 ;
bool V_149 = false ;
T_4 V_150 ;
V_150 = F_32 () ;
F_37 ( & V_4 -> V_5 , V_33 -> V_67 ) ;
F_28 ( & V_4 -> V_56 , V_51 ) ;
V_4 -> V_57 = V_150 ;
if ( V_4 -> V_61 ) {
F_6 ( V_12 , V_4 -> V_61 ) ;
V_4 -> V_61 = NULL ;
V_149 = true ;
}
F_33 ( & V_4 -> V_56 , V_51 ) ;
F_61 ( V_7 , 0 ) ;
if ( ! V_149 ) {
struct V_47 * V_48 ;
F_28 ( & V_7 -> V_151 , V_51 ) ;
V_48 = V_4 -> V_48 ;
V_4 -> V_48 = NULL ;
if ( V_48 )
F_62 ( V_7 , 0 , V_48 ) ;
F_33 ( & V_7 -> V_151 , V_51 ) ;
}
if ( V_4 -> V_152 )
V_4 -> V_153 = 0 ;
else
V_4 -> V_152 = true ;
}
if ( V_33 -> V_35 == 2 ) {
if ( V_147 & V_154 ) {
V_4 -> V_64 = true ;
F_63 ( & V_4 -> V_66 ) ;
}
F_10 ( V_7 , V_155 , 0 ) ;
}
if ( V_147 & V_156 ) {
F_64 ( V_7 -> V_7 , L_17 ,
V_157 , V_147 ) ;
V_4 -> V_152 = false ;
if ( V_4 -> V_153 ++ > V_158 ) {
F_24 ( V_7 -> V_7 ,
L_18 ,
V_157 , V_147 ) ;
F_10 ( V_7 , V_159 ,
V_156 ) ;
}
}
if ( V_147 & V_160 )
F_64 ( V_7 -> V_7 , L_19 ,
V_157 , V_147 ) ;
return V_161 ;
}
struct V_11 * F_65 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = V_7 -> V_34 ;
struct V_4 * V_4 ;
struct V_11 * V_12 ;
int V_65 ;
V_4 = F_66 ( V_7 -> V_7 , sizeof( * V_4 ) , V_162 ) ;
if ( ! V_4 ) {
F_24 ( V_7 -> V_7 , L_20 ) ;
return NULL ;
}
V_12 = & V_4 -> V_8 ;
V_4 -> V_63 = V_43 ;
F_67 ( & V_4 -> V_66 ) ;
F_68 ( & V_4 -> V_5 ,
L_21 , F_1 ) ;
F_69 ( & V_4 -> V_56 ) ;
V_65 = F_70 ( V_7 , V_12 , & V_163 ) ;
if ( V_65 < 0 )
goto V_164;
F_71 ( V_12 , & V_165 ) ;
if ( V_33 -> V_166 ) {
struct V_167 * V_168 =
F_72 ( V_7 -> V_7 -> V_169 , L_22 ) ;
if ( V_168 ) {
V_12 -> V_44 = F_72 ( V_168 , L_23 ) ;
F_20 ( V_168 ) ;
} else {
V_12 -> V_44 =
F_72 ( V_7 -> V_7 -> V_169 , L_23 ) ;
}
if ( ! V_12 -> V_44 ) {
F_24 ( V_7 -> V_7 , L_24 ,
V_7 -> V_7 -> V_169 -> V_170 ) ;
goto V_164;
}
}
return V_12 ;
V_164:
F_18 ( V_12 ) ;
return NULL ;
}
