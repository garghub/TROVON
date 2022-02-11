static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 ;
V_9 = F_3 ( V_8 -> V_10 + V_11 ) ;
V_9 &= ~ V_12 ;
V_9 |= F_4 ( V_5 - 1 ) ;
F_5 ( V_9 , V_8 -> V_10 + V_11 ) ;
V_9 = F_3 ( V_8 -> V_10 + V_13 ) ;
V_9 &= ~ V_12 ;
V_9 |= F_4 ( V_5 - 1 ) ;
F_5 ( V_9 , V_8 -> V_10 + V_13 ) ;
F_5 ( V_3 , V_8 -> V_10 + V_14 ) ;
F_5 ( V_4 , V_8 -> V_10 + V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_16 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_17 = 0 , V_18 ;
V_18 = F_3 ( V_8 -> V_10 + V_19 ) & ~ ( V_20 | V_21 ) ;
switch ( V_16 & V_22 ) {
case V_23 :
V_17 |= V_24 | V_25 | V_26 ;
V_18 |= V_21 ;
if ( V_8 -> V_27 & V_28 ) {
V_18 &= ~ V_29 ;
V_18 |= V_30 ;
}
break;
case V_31 :
V_17 |= V_26 ;
break;
case V_32 :
V_17 |= V_33 | V_26 ;
break;
case V_34 :
V_17 |= V_33 | V_26 | V_25 ;
break;
}
switch ( V_16 & V_35 ) {
case V_36 :
V_17 |= V_24 ;
V_17 &= ~ V_37 ;
break;
case V_38 :
V_17 &= ~ ( V_37 | V_24 ) ;
break;
case V_39 :
V_17 |= V_24 | V_37 ;
break;
case V_40 :
V_17 &= ~ V_24 ;
V_17 |= V_37 ;
break;
}
switch ( V_16 & V_41 ) {
case V_42 :
break;
default:
return - V_43 ;
}
V_17 |= V_44 ;
if ( V_8 -> V_27 & V_45 )
V_18 |= V_21 ;
if ( V_8 -> V_27 & V_46 )
V_18 |= V_20 ;
F_5 ( V_17 , V_8 -> V_10 + V_47 ) ;
F_5 ( V_17 , V_8 -> V_10 + V_48 ) ;
F_5 ( V_18 , V_8 -> V_10 + V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_49 , unsigned int V_50 , int V_51 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_18 ;
V_18 = F_3 ( V_8 -> V_10 + V_19 ) ;
switch ( V_49 ) {
case V_52 :
if ( V_51 == V_53 )
V_18 |= V_54 ;
else
V_18 &= ~ V_54 ;
break;
default:
return - V_43 ;
}
F_5 ( V_18 , V_8 -> V_10 + V_19 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_55 , int div )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_56 , V_57 ;
V_56 = F_3 ( V_8 -> V_10 + V_11 ) ;
V_57 = F_3 ( V_8 -> V_10 + V_13 ) ;
switch ( V_55 ) {
case V_58 :
V_56 &= ~ V_59 ;
V_56 |= div ;
break;
case V_60 :
V_56 &= ~ V_61 ;
V_56 |= div ;
break;
case V_62 :
V_56 &= ~ 0xff ;
V_56 |= F_9 ( div ) ;
break;
case V_63 :
V_56 &= ~ V_59 ;
V_56 |= div ;
break;
case V_64 :
V_56 &= ~ V_61 ;
V_56 |= div ;
break;
case V_65 :
V_56 &= ~ 0xff ;
V_56 |= F_9 ( div ) ;
break;
default:
return - V_43 ;
}
F_5 ( V_56 , V_8 -> V_10 + V_11 ) ;
F_5 ( V_57 , V_8 -> V_10 + V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_66 * V_67 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_68 * V_69 ;
if ( V_67 -> V_70 == V_71 )
V_69 = & V_8 -> V_72 ;
else
V_69 = & V_8 -> V_73 ;
F_11 ( V_2 , V_67 , V_69 ) ;
return 0 ;
}
static int F_12 ( struct V_66 * V_67 ,
struct V_74 * V_75 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_76 , V_9 ;
if ( V_67 -> V_70 == V_71 )
V_76 = V_11 ;
else
V_76 = V_13 ;
if ( V_8 -> V_27 & V_46 )
V_76 = V_11 ;
V_9 = F_3 ( V_8 -> V_10 + V_76 ) & ~ V_77 ;
switch ( F_13 ( V_75 ) ) {
case V_78 :
V_9 |= F_14 ( 16 ) ;
break;
case V_79 :
V_9 |= F_14 ( 20 ) ;
break;
case V_80 :
V_9 |= F_14 ( 24 ) ;
break;
}
F_5 ( V_9 , V_8 -> V_10 + V_76 ) ;
return 0 ;
}
static int F_15 ( struct V_66 * V_67 , int V_81 ,
struct V_1 * V_82 )
{
struct V_7 * V_8 = F_2 ( V_82 ) ;
unsigned int V_83 , V_84 ;
unsigned int V_18 ;
V_18 = F_3 ( V_8 -> V_10 + V_19 ) ;
V_84 = F_3 ( V_8 -> V_10 + V_85 ) ;
if ( V_67 -> V_70 == V_71 ) {
if ( V_8 -> V_27 & V_86 )
V_83 = V_87 ;
else
V_83 = V_88 | V_89 ;
} else {
if ( V_8 -> V_27 & V_86 )
V_83 = V_90 ;
else
V_83 = V_91 | V_92 ;
}
switch ( V_81 ) {
case V_93 :
case V_94 :
case V_95 :
if ( V_67 -> V_70 == V_71 )
V_18 |= V_96 ;
else
V_18 |= V_97 ;
V_84 |= V_83 ;
if ( ++ V_8 -> V_98 == 1 )
V_18 |= V_99 ;
break;
case V_100 :
case V_101 :
case V_102 :
if ( V_67 -> V_70 == V_71 )
V_18 &= ~ V_96 ;
else
V_18 &= ~ V_97 ;
V_84 &= ~ V_83 ;
if ( -- V_8 -> V_98 == 0 )
V_18 &= ~ V_99 ;
break;
default:
return - V_43 ;
}
if ( ! ( V_8 -> V_27 & V_103 ) )
F_5 ( V_18 , V_8 -> V_10 + V_19 ) ;
F_5 ( V_84 , V_8 -> V_10 + V_85 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_82 )
{
struct V_7 * V_8 = F_17 ( V_82 -> V_104 ) ;
T_2 V_105 ;
F_18 ( V_82 , V_8 ) ;
V_105 = F_19 ( V_8 -> V_72 . V_106 ) |
F_20 ( V_8 -> V_73 . V_106 ) ;
F_5 ( V_105 , V_8 -> V_10 + V_107 ) ;
return 0 ;
}
static void F_21 ( struct V_7 * V_7 )
{
void T_3 * V_10 = V_7 -> V_10 ;
F_5 ( 0x0 , V_10 + V_19 ) ;
F_5 ( 0x0 , V_10 + V_47 ) ;
F_5 ( 0x0 , V_10 + V_48 ) ;
F_5 ( V_20 | V_21 , V_10 + V_19 ) ;
F_5 ( F_20 ( 8 ) |
F_19 ( 8 ) |
F_22 ( 8 ) |
F_23 ( 8 ) , V_10 + V_107 ) ;
F_5 ( F_24 ( 16 ) | F_4 ( 12 ) , V_10 + V_11 ) ;
F_5 ( F_24 ( 16 ) | F_4 ( 12 ) , V_10 + V_13 ) ;
F_5 ( V_20 | V_21 | V_99 , V_10 + V_19 ) ;
F_5 ( F_25 ( 3 ) , V_10 + V_108 ) ;
F_5 ( V_20 | V_21 | V_99 |
V_96 | V_97 ,
V_10 + V_19 ) ;
F_5 ( V_109 , V_10 + V_110 ) ;
F_5 ( 0xff , V_10 + V_111 ) ;
F_5 ( 0x300 , V_10 + V_112 ) ;
}
static void F_26 ( struct V_113 * V_114 , unsigned short V_76 ,
unsigned short V_105 )
{
struct V_7 * V_7 = V_115 ;
void T_3 * V_10 = V_7 -> V_10 ;
unsigned int V_116 ;
unsigned int V_117 ;
if ( V_76 > 0x7f )
return;
F_27 ( L_1 , V_118 , V_76 , V_105 ) ;
V_116 = V_76 << 12 ;
F_5 ( V_116 , V_10 + V_119 ) ;
V_117 = V_105 << 4 ;
F_5 ( V_117 , V_10 + V_120 ) ;
F_5 ( V_109 | V_121 , V_10 + V_110 ) ;
F_28 ( 100 ) ;
}
static unsigned short F_29 ( struct V_113 * V_114 ,
unsigned short V_76 )
{
struct V_7 * V_7 = V_115 ;
void T_3 * V_10 = V_7 -> V_10 ;
unsigned short V_105 = - 1 ;
unsigned int V_116 ;
V_116 = ( V_76 & 0x7f ) << 12 ;
F_5 ( V_116 , V_10 + V_119 ) ;
F_5 ( V_109 | V_122 , V_10 + V_110 ) ;
F_28 ( 100 ) ;
V_105 = ( F_3 ( V_10 + V_120 ) >> 4 ) & 0xffff ;
F_27 ( L_1 , V_118 , V_76 , V_105 ) ;
return V_105 ;
}
static void F_30 ( struct V_113 * V_114 )
{
struct V_7 * V_7 = V_115 ;
if ( V_7 -> V_123 )
V_7 -> V_123 ( V_114 ) ;
}
static void F_31 ( struct V_113 * V_114 )
{
struct V_7 * V_7 = V_115 ;
if ( V_7 -> V_124 )
V_7 -> V_124 ( V_114 ) ;
}
static int F_32 ( struct V_125 * V_126 )
{
struct V_127 * V_128 ;
struct V_7 * V_8 ;
struct V_129 * V_130 = V_126 -> V_104 . V_131 ;
int V_132 = 0 ;
struct V_133 * V_82 ;
V_8 = F_33 ( sizeof( * V_8 ) , V_134 ) ;
if ( ! V_8 )
return - V_135 ;
F_34 ( & V_126 -> V_104 , V_8 ) ;
if ( V_130 ) {
V_8 -> V_123 = V_130 -> V_123 ;
V_8 -> V_124 = V_130 -> V_124 ;
V_8 -> V_27 = V_130 -> V_27 ;
}
V_8 -> V_136 = F_35 ( V_126 , 0 ) ;
V_8 -> V_137 = F_36 ( & V_126 -> V_104 , NULL ) ;
if ( F_37 ( V_8 -> V_137 ) ) {
V_132 = F_38 ( V_8 -> V_137 ) ;
F_39 ( & V_126 -> V_104 , L_2 ,
V_132 ) ;
goto V_138;
}
F_40 ( V_8 -> V_137 ) ;
V_128 = F_41 ( V_126 , V_139 , 0 ) ;
if ( ! V_128 ) {
V_132 = - V_140 ;
goto V_141;
}
if ( ! F_42 ( V_128 -> V_142 , F_43 ( V_128 ) , V_143 ) ) {
F_39 ( & V_126 -> V_104 , L_3 ) ;
V_132 = - V_144 ;
goto V_141;
}
V_8 -> V_10 = F_44 ( V_128 -> V_142 , F_43 ( V_128 ) ) ;
if ( ! V_8 -> V_10 ) {
F_39 ( & V_126 -> V_104 , L_4 ) ;
V_132 = - V_140 ;
goto V_145;
}
if ( V_8 -> V_27 & V_103 ) {
if ( V_115 ) {
V_132 = - V_144 ;
goto V_146;
}
V_115 = V_8 ;
F_21 ( V_8 ) ;
V_82 = & V_147 ;
} else
V_82 = & V_148 ;
F_5 ( 0x0 , V_8 -> V_10 + V_85 ) ;
V_8 -> V_73 . V_149 = V_128 -> V_142 + V_150 ;
V_8 -> V_72 . V_149 = V_128 -> V_142 + V_151 ;
V_8 -> V_72 . V_106 = 6 ;
V_8 -> V_73 . V_106 = 4 ;
V_128 = F_45 ( V_126 , V_152 , L_5 ) ;
if ( V_128 )
V_8 -> V_72 . V_153 = V_128 -> V_142 ;
V_128 = F_45 ( V_126 , V_152 , L_6 ) ;
if ( V_128 )
V_8 -> V_73 . V_153 = V_128 -> V_142 ;
F_46 ( V_126 , V_8 ) ;
V_132 = F_47 ( & V_126 -> V_104 , V_82 ) ;
if ( V_132 ) {
F_39 ( & V_126 -> V_104 , L_7 ) ;
goto V_154;
}
V_8 -> V_155 = F_48 ( L_8 , V_126 -> V_156 ) ;
if ( ! V_8 -> V_155 ) {
V_132 = - V_135 ;
goto V_157;
}
F_46 ( V_8 -> V_155 , V_8 ) ;
V_132 = F_49 ( V_8 -> V_155 ) ;
if ( V_132 ) {
F_39 ( & V_126 -> V_104 , L_9 ) ;
goto V_158;
}
V_8 -> V_159 = F_48 ( L_10 , V_126 -> V_156 ) ;
if ( ! V_8 -> V_159 ) {
V_132 = - V_135 ;
goto V_160;
}
F_46 ( V_8 -> V_159 , V_8 ) ;
V_132 = F_49 ( V_8 -> V_159 ) ;
if ( V_132 ) {
F_39 ( & V_126 -> V_104 , L_9 ) ;
goto V_161;
}
return 0 ;
V_161:
F_50 ( V_8 -> V_159 ) ;
V_160:
F_51 ( V_8 -> V_155 ) ;
V_158:
F_50 ( V_8 -> V_155 ) ;
V_157:
F_52 ( & V_126 -> V_104 ) ;
V_154:
V_146:
F_53 ( V_8 -> V_10 ) ;
V_145:
F_54 ( V_128 -> V_142 , F_43 ( V_128 ) ) ;
V_141:
F_55 ( V_8 -> V_137 ) ;
F_56 ( V_8 -> V_137 ) ;
V_138:
F_57 ( V_8 ) ;
return V_132 ;
}
static int T_4 F_58 ( struct V_125 * V_126 )
{
struct V_127 * V_128 = F_41 ( V_126 , V_139 , 0 ) ;
struct V_7 * V_8 = F_59 ( V_126 ) ;
F_60 ( V_8 -> V_159 ) ;
F_60 ( V_8 -> V_155 ) ;
F_52 ( & V_126 -> V_104 ) ;
if ( V_8 -> V_27 & V_103 )
V_115 = NULL ;
F_53 ( V_8 -> V_10 ) ;
F_54 ( V_128 -> V_142 , F_43 ( V_128 ) ) ;
F_55 ( V_8 -> V_137 ) ;
F_56 ( V_8 -> V_137 ) ;
F_57 ( V_8 ) ;
return 0 ;
}
