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
struct V_68 * V_69 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_70 , V_9 ;
if ( V_67 -> V_71 == V_72 )
V_70 = V_11 ;
else
V_70 = V_13 ;
if ( V_8 -> V_27 & V_46 )
V_70 = V_11 ;
V_9 = F_3 ( V_8 -> V_10 + V_70 ) & ~ V_73 ;
switch ( F_11 ( V_69 ) ) {
case V_74 :
V_9 |= F_12 ( 16 ) ;
break;
case V_75 :
V_9 |= F_12 ( 20 ) ;
break;
case V_76 :
V_9 |= F_12 ( 24 ) ;
break;
}
F_5 ( V_9 , V_8 -> V_10 + V_70 ) ;
return 0 ;
}
static int F_13 ( struct V_66 * V_67 , int V_77 ,
struct V_1 * V_78 )
{
struct V_7 * V_8 = F_2 ( V_78 ) ;
unsigned int V_79 , V_80 ;
unsigned int V_18 ;
V_18 = F_3 ( V_8 -> V_10 + V_19 ) ;
V_80 = F_3 ( V_8 -> V_10 + V_81 ) ;
if ( V_67 -> V_71 == V_72 ) {
if ( V_8 -> V_27 & V_82 )
V_79 = V_83 ;
else
V_79 = V_84 | V_85 ;
} else {
if ( V_8 -> V_27 & V_82 )
V_79 = V_86 ;
else
V_79 = V_87 | V_88 ;
}
switch ( V_77 ) {
case V_89 :
case V_90 :
case V_91 :
if ( V_67 -> V_71 == V_72 )
V_18 |= V_92 ;
else
V_18 |= V_93 ;
V_80 |= V_79 ;
if ( ++ V_8 -> V_94 == 1 )
V_18 |= V_95 ;
break;
case V_96 :
case V_97 :
case V_98 :
if ( V_67 -> V_71 == V_72 )
V_18 &= ~ V_92 ;
else
V_18 &= ~ V_93 ;
V_80 &= ~ V_79 ;
if ( -- V_8 -> V_94 == 0 )
V_18 &= ~ V_95 ;
break;
default:
return - V_43 ;
}
if ( ! ( V_8 -> V_27 & V_99 ) )
F_5 ( V_18 , V_8 -> V_10 + V_19 ) ;
F_5 ( V_80 , V_8 -> V_10 + V_81 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_78 )
{
struct V_7 * V_8 = F_15 ( V_78 -> V_100 ) ;
T_2 V_101 ;
F_16 ( V_78 , V_8 ) ;
V_101 = F_17 ( V_8 -> V_102 . V_103 ) |
F_18 ( V_8 -> V_104 . V_103 ) ;
F_5 ( V_101 , V_8 -> V_10 + V_105 ) ;
V_78 -> V_106 = & V_8 -> V_102 ;
V_78 -> V_107 = & V_8 -> V_104 ;
return 0 ;
}
static void F_19 ( struct V_7 * V_7 )
{
void T_3 * V_10 = V_7 -> V_10 ;
F_5 ( 0x0 , V_10 + V_19 ) ;
F_5 ( 0x0 , V_10 + V_47 ) ;
F_5 ( 0x0 , V_10 + V_48 ) ;
F_5 ( V_20 | V_21 , V_10 + V_19 ) ;
F_5 ( F_18 ( 8 ) |
F_17 ( 8 ) |
F_20 ( 8 ) |
F_21 ( 8 ) , V_10 + V_105 ) ;
F_5 ( F_22 ( 16 ) | F_4 ( 12 ) , V_10 + V_11 ) ;
F_5 ( F_22 ( 16 ) | F_4 ( 12 ) , V_10 + V_13 ) ;
F_5 ( V_20 | V_21 | V_95 , V_10 + V_19 ) ;
F_5 ( F_23 ( 3 ) , V_10 + V_108 ) ;
F_5 ( V_20 | V_21 | V_95 |
V_92 | V_93 ,
V_10 + V_19 ) ;
F_5 ( V_109 , V_10 + V_110 ) ;
F_5 ( 0xff , V_10 + V_111 ) ;
F_5 ( 0x300 , V_10 + V_112 ) ;
}
static void F_24 ( struct V_113 * V_114 , unsigned short V_70 ,
unsigned short V_101 )
{
struct V_7 * V_7 = V_115 ;
void T_3 * V_10 = V_7 -> V_10 ;
unsigned int V_116 ;
unsigned int V_117 ;
if ( V_70 > 0x7f )
return;
F_25 ( L_1 , V_118 , V_70 , V_101 ) ;
V_116 = V_70 << 12 ;
F_5 ( V_116 , V_10 + V_119 ) ;
V_117 = V_101 << 4 ;
F_5 ( V_117 , V_10 + V_120 ) ;
F_5 ( V_109 | V_121 , V_10 + V_110 ) ;
F_26 ( 100 ) ;
}
static unsigned short F_27 ( struct V_113 * V_114 ,
unsigned short V_70 )
{
struct V_7 * V_7 = V_115 ;
void T_3 * V_10 = V_7 -> V_10 ;
unsigned short V_101 = - 1 ;
unsigned int V_116 ;
V_116 = ( V_70 & 0x7f ) << 12 ;
F_5 ( V_116 , V_10 + V_119 ) ;
F_5 ( V_109 | V_122 , V_10 + V_110 ) ;
F_26 ( 100 ) ;
V_101 = ( F_3 ( V_10 + V_120 ) >> 4 ) & 0xffff ;
F_25 ( L_1 , V_118 , V_70 , V_101 ) ;
return V_101 ;
}
static void F_28 ( struct V_113 * V_114 )
{
struct V_7 * V_7 = V_115 ;
if ( V_7 -> V_123 )
V_7 -> V_123 ( V_114 ) ;
F_27 ( V_114 , 0 ) ;
}
static void F_29 ( struct V_113 * V_114 )
{
struct V_7 * V_7 = V_115 ;
if ( V_7 -> V_124 )
V_7 -> V_124 ( V_114 ) ;
F_27 ( V_114 , 0 ) ;
}
static int F_30 ( struct V_125 * V_126 )
{
struct V_127 * V_128 ;
struct V_7 * V_8 ;
struct V_129 * V_130 = V_126 -> V_100 . V_131 ;
int V_132 = 0 ;
struct V_133 * V_78 ;
V_8 = F_31 ( & V_126 -> V_100 , sizeof( * V_8 ) , V_134 ) ;
if ( ! V_8 )
return - V_135 ;
F_32 ( & V_126 -> V_100 , V_8 ) ;
if ( V_130 ) {
V_8 -> V_123 = V_130 -> V_123 ;
V_8 -> V_124 = V_130 -> V_124 ;
V_8 -> V_27 = V_130 -> V_27 ;
}
V_8 -> V_136 = F_33 ( V_126 , 0 ) ;
V_8 -> V_137 = F_34 ( & V_126 -> V_100 , NULL ) ;
if ( F_35 ( V_8 -> V_137 ) ) {
V_132 = F_36 ( V_8 -> V_137 ) ;
F_37 ( & V_126 -> V_100 , L_2 ,
V_132 ) ;
goto V_138;
}
F_38 ( V_8 -> V_137 ) ;
V_128 = F_39 ( V_126 , V_139 , 0 ) ;
V_8 -> V_10 = F_40 ( & V_126 -> V_100 , V_128 ) ;
if ( F_35 ( V_8 -> V_10 ) ) {
V_132 = F_36 ( V_8 -> V_10 ) ;
goto V_140;
}
if ( V_8 -> V_27 & V_99 ) {
if ( V_115 ) {
F_37 ( & V_126 -> V_100 , L_3 ) ;
V_132 = - V_141 ;
goto V_140;
}
V_115 = V_8 ;
F_19 ( V_8 ) ;
V_78 = & V_142 ;
} else
V_78 = & V_143 ;
F_5 ( 0x0 , V_8 -> V_10 + V_81 ) ;
V_8 -> V_104 . V_144 = V_128 -> V_145 + V_146 ;
V_8 -> V_102 . V_144 = V_128 -> V_145 + V_147 ;
V_8 -> V_102 . V_103 = 6 ;
V_8 -> V_104 . V_103 = 4 ;
V_8 -> V_102 . V_148 = & V_8 -> V_149 ;
V_8 -> V_104 . V_148 = & V_8 -> V_150 ;
V_128 = F_41 ( V_126 , V_151 , L_4 ) ;
if ( V_128 ) {
F_42 ( & V_8 -> V_149 , V_128 -> V_145 ,
false ) ;
}
V_128 = F_41 ( V_126 , V_151 , L_5 ) ;
if ( V_128 ) {
F_42 ( & V_8 -> V_150 , V_128 -> V_145 ,
false ) ;
}
F_43 ( V_126 , V_8 ) ;
V_132 = F_44 ( & V_126 -> V_100 , & V_152 ,
V_78 , 1 ) ;
if ( V_132 ) {
F_37 ( & V_126 -> V_100 , L_6 ) ;
goto V_140;
}
V_8 -> V_153 = F_45 ( L_7 , V_126 -> V_154 ) ;
if ( ! V_8 -> V_153 ) {
V_132 = - V_135 ;
goto V_155;
}
F_43 ( V_8 -> V_153 , V_8 ) ;
V_132 = F_46 ( V_8 -> V_153 ) ;
if ( V_132 ) {
F_37 ( & V_126 -> V_100 , L_8 ) ;
goto V_156;
}
V_8 -> V_157 = F_45 ( L_9 , V_126 -> V_154 ) ;
if ( ! V_8 -> V_157 ) {
V_132 = - V_135 ;
goto V_158;
}
F_43 ( V_8 -> V_157 , V_8 ) ;
V_132 = F_46 ( V_8 -> V_157 ) ;
if ( V_132 ) {
F_37 ( & V_126 -> V_100 , L_8 ) ;
goto V_159;
}
return 0 ;
V_159:
F_47 ( V_8 -> V_157 ) ;
V_158:
F_48 ( V_8 -> V_153 ) ;
V_156:
F_47 ( V_8 -> V_153 ) ;
V_155:
F_49 ( & V_126 -> V_100 ) ;
V_140:
F_50 ( V_128 -> V_145 , F_51 ( V_128 ) ) ;
F_52 ( V_8 -> V_137 ) ;
V_138:
return V_132 ;
}
static int F_53 ( struct V_125 * V_126 )
{
struct V_127 * V_128 = F_39 ( V_126 , V_139 , 0 ) ;
struct V_7 * V_8 = F_54 ( V_126 ) ;
F_55 ( V_8 -> V_157 ) ;
F_55 ( V_8 -> V_153 ) ;
F_49 ( & V_126 -> V_100 ) ;
if ( V_8 -> V_27 & V_99 )
V_115 = NULL ;
F_50 ( V_128 -> V_145 , F_51 ( V_128 ) ) ;
F_52 ( V_8 -> V_137 ) ;
return 0 ;
}
