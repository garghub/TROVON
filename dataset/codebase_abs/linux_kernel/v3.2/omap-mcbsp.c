static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_10 * V_11 ;
int V_12 = F_3 ( V_9 -> V_13 ) ;
int V_14 ;
V_11 = F_4 ( V_4 -> V_7 , V_2 ) ;
if ( V_12 == V_15 )
if ( V_11 -> V_16 )
V_14 = V_11 -> V_16 ;
else
V_14 = F_5 ( V_2 ) /
( V_9 -> V_17 / 8 ) ;
else
V_14 = 1 ;
if ( V_2 -> V_18 == V_19 )
F_6 ( V_9 -> V_13 , V_14 ) ;
else
F_7 ( V_9 -> V_13 , V_14 ) ;
}
static int F_8 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = F_9 ( V_21 ,
V_26 ) ;
struct V_24 * V_27 = F_9 ( V_21 ,
V_28 ) ;
struct V_8 * V_9 = V_23 -> V_29 ;
struct V_24 V_30 ;
int V_31 ;
F_10 ( & V_30 ) ;
V_31 = F_11 ( V_9 -> V_13 ) ;
V_30 . V_32 = V_31 / V_27 -> V_32 ;
V_30 . integer = 1 ;
return F_12 ( V_25 , & V_30 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_13 = V_9 -> V_13 ;
int V_33 = 0 ;
if ( ! V_7 -> V_34 )
V_33 = F_14 ( V_13 ) ;
if ( F_15 () || F_16 () ) {
F_17 ( V_2 -> V_35 , 0 ,
V_28 ,
F_8 ,
V_9 ,
V_26 , - 1 ) ;
F_18 ( V_2 -> V_35 , 0 ,
V_36 , 2 ) ;
}
return V_33 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
if ( ! V_7 -> V_34 ) {
F_20 ( V_9 -> V_13 ) ;
V_9 -> V_37 = 0 ;
}
}
static int F_21 ( struct V_1 * V_2 , int V_38 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_33 = 0 , V_39 = ( V_2 -> V_18 == V_19 ) ;
switch ( V_38 ) {
case V_40 :
case V_41 :
case V_42 :
V_9 -> V_34 ++ ;
F_22 ( V_9 -> V_13 , V_39 , ! V_39 ) ;
break;
case V_43 :
case V_44 :
case V_45 :
F_23 ( V_9 -> V_13 , V_39 , ! V_39 ) ;
V_9 -> V_34 -- ;
break;
default:
V_33 = - V_46 ;
}
return V_33 ;
}
static T_1 F_24 (
struct V_1 * V_2 ,
struct V_6 * V_47 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_2 V_48 ;
T_1 V_49 ;
if ( V_2 -> V_18 == V_19 )
V_48 = F_25 ( V_9 -> V_13 ) ;
else
V_48 = F_26 ( V_9 -> V_13 ) ;
V_49 = V_48 / V_2 -> V_35 -> V_27 ;
return V_49 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_50 * V_51 = & V_9 -> V_51 ;
struct V_10 * V_11 ;
int V_52 , V_13 = V_9 -> V_13 ;
int V_17 , V_27 , V_53 , V_54 = V_55 ;
int V_56 = 0 ;
unsigned long V_57 ;
unsigned int V_58 , div , V_59 , V_60 ;
V_11 = & V_61 [ V_7 -> V_62 ] [ V_2 -> V_18 ] ;
V_52 = F_28 ( V_13 , V_2 -> V_18 ) ;
V_57 = F_29 ( V_13 , V_2 -> V_18 ) ;
switch ( F_30 ( V_21 ) ) {
case V_63 :
V_11 -> V_64 = V_65 ;
V_17 = 16 ;
break;
case V_66 :
V_11 -> V_64 = V_67 ;
V_17 = 32 ;
break;
default:
return - V_46 ;
}
if ( F_15 () ) {
V_11 -> V_68 = F_1 ;
if ( F_3 ( V_13 ) ==
V_15 ) {
int V_69 , V_70 ;
V_69 = F_31 ( V_21 ) / ( V_17 / 8 ) ;
if ( V_2 -> V_18 == V_19 )
V_70 = F_32 (
V_9 -> V_13 ) ;
else
V_70 = F_33 (
V_9 -> V_13 ) ;
if ( V_69 > V_70 ) {
int V_71 = 0 ;
V_71 = V_69 / V_70 ;
if ( V_69 % V_70 )
V_71 ++ ;
while ( V_69 % V_71 &&
V_71 < V_69 )
V_71 ++ ;
if ( V_71 == V_69 )
return - V_46 ;
V_56 = V_69 / V_71 ;
V_54 = V_72 ;
} else {
V_54 = V_73 ;
}
}
}
V_11 -> V_74 = V_2 -> V_18 ? L_1 : L_2 ;
V_11 -> V_75 = V_52 ;
V_11 -> V_76 = V_57 ;
V_11 -> V_54 = V_54 ;
V_11 -> V_16 = V_56 ;
F_34 ( V_7 , V_2 , V_11 ) ;
if ( V_9 -> V_37 ) {
return 0 ;
}
V_51 -> V_77 &= ~ ( V_78 | F_35 ( 0x7f ) | F_36 ( 7 ) ) ;
V_51 -> V_79 &= ~ ( V_78 | F_37 ( 0x7f ) | F_38 ( 7 ) ) ;
V_51 -> V_80 &= ~ ( F_39 ( 0x7f ) | F_40 ( 7 ) ) ;
V_51 -> V_81 &= ~ ( F_41 ( 0x7f ) | F_42 ( 7 ) ) ;
V_58 = V_9 -> V_82 & V_83 ;
V_53 = V_27 = F_43 ( V_21 ) ;
if ( V_27 == 2 && ( V_58 == V_84 ||
V_58 == V_85 ) ) {
V_51 -> V_77 |= V_78 ;
V_51 -> V_79 |= V_86 ;
V_53 -- ;
V_51 -> V_77 |= F_35 ( V_53 - 1 ) ;
V_51 -> V_79 |= F_37 ( V_53 - 1 ) ;
}
V_51 -> V_80 |= F_39 ( V_53 - 1 ) ;
V_51 -> V_81 |= F_41 ( V_53 - 1 ) ;
switch ( F_30 ( V_21 ) ) {
case V_63 :
V_51 -> V_77 |= F_36 ( V_87 ) ;
V_51 -> V_80 |= F_40 ( V_87 ) ;
V_51 -> V_79 |= F_38 ( V_87 ) ;
V_51 -> V_81 |= F_42 ( V_87 ) ;
break;
case V_66 :
V_51 -> V_77 |= F_36 ( V_88 ) ;
V_51 -> V_80 |= F_40 ( V_88 ) ;
V_51 -> V_79 |= F_38 ( V_88 ) ;
V_51 -> V_81 |= F_42 ( V_88 ) ;
break;
default:
return - V_46 ;
}
V_60 = V_9 -> V_82 & V_89 ;
if ( V_60 == V_90 ) {
div = V_9 -> V_91 ? V_9 -> V_91 : 1 ;
V_59 = ( V_9 -> V_92 / div ) / F_44 ( V_21 ) ;
if ( V_59 < V_17 * V_27 ) {
F_45 ( V_93 L_3
L_4 , V_94 ) ;
return - V_46 ;
}
} else
V_59 = V_17 * V_27 ;
V_51 -> V_95 &= ~ F_46 ( 0xfff ) ;
V_51 -> V_96 &= ~ F_47 ( 0xff ) ;
switch ( V_58 ) {
case V_84 :
case V_85 :
V_51 -> V_95 |= F_46 ( V_59 - 1 ) ;
V_51 -> V_96 |= F_47 ( ( V_59 >> 1 ) - 1 ) ;
break;
case V_97 :
case V_98 :
V_51 -> V_95 |= F_46 ( V_59 - 1 ) ;
V_51 -> V_96 |= F_47 ( 0 ) ;
break;
}
F_48 ( V_13 , & V_9 -> V_51 ) ;
V_9 -> V_17 = V_17 ;
V_9 -> V_37 = 1 ;
return 0 ;
}
static int F_49 ( struct V_6 * V_7 ,
unsigned int V_82 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_50 * V_51 = & V_9 -> V_51 ;
bool V_99 = false ;
if ( V_9 -> V_37 )
return 0 ;
V_9 -> V_82 = V_82 ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_100 |= F_50 ( 3 ) | FREE ;
V_51 -> V_101 |= F_51 ( 3 ) ;
if ( ! F_15 () && ! F_16 () ) {
V_51 -> V_77 |= V_102 ;
V_51 -> V_79 |= V_103 ;
}
if ( F_52 () || F_15 () || F_16 () ) {
V_51 -> V_104 = F_53 ( 1 ) | V_105 | V_106 ;
V_51 -> V_107 = V_108 | V_109 | V_110 ;
}
switch ( V_82 & V_83 ) {
case V_84 :
V_51 -> V_77 |= F_54 ( 1 ) ;
V_51 -> V_79 |= F_55 ( 1 ) ;
break;
case V_85 :
V_51 -> V_77 |= F_54 ( 0 ) ;
V_51 -> V_79 |= F_55 ( 0 ) ;
V_51 -> V_101 |= F_56 ( 2 ) ;
V_99 = true ;
break;
case V_97 :
V_51 -> V_77 |= F_54 ( 1 ) ;
V_51 -> V_79 |= F_55 ( 1 ) ;
V_99 = true ;
break;
case V_98 :
V_51 -> V_77 |= F_54 ( 0 ) ;
V_51 -> V_79 |= F_55 ( 0 ) ;
V_99 = true ;
break;
default:
return - V_46 ;
}
switch ( V_82 & V_89 ) {
case V_90 :
V_51 -> V_111 |= V_112 | V_113 |
V_114 | V_115 ;
V_51 -> V_95 |= V_116 ;
break;
case V_117 :
break;
default:
return - V_46 ;
}
switch ( V_82 & V_118 ) {
case V_119 :
V_51 -> V_111 |= V_120 | V_121 |
V_122 | V_123 ;
break;
case V_124 :
V_51 -> V_111 |= V_122 | V_123 ;
break;
case V_125 :
V_51 -> V_111 |= V_120 | V_121 ;
break;
case V_126 :
break;
default:
return - V_46 ;
}
if ( V_99 == true )
V_51 -> V_111 ^= V_120 | V_121 ;
return 0 ;
}
static int F_57 ( struct V_6 * V_7 ,
int V_127 , int div )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_50 * V_51 = & V_9 -> V_51 ;
if ( V_127 != V_128 )
return - V_129 ;
V_9 -> V_91 = div ;
V_51 -> V_96 &= ~ F_58 ( 0xff ) ;
V_51 -> V_96 |= F_58 ( div - 1 ) ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 ,
int V_130 , unsigned int V_131 ,
int V_132 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_50 * V_51 = & V_9 -> V_51 ;
int V_33 = 0 ;
if ( V_9 -> V_34 ) {
if ( V_131 == V_9 -> V_92 )
return 0 ;
else
return - V_133 ;
}
if ( V_130 == V_134 ||
V_130 == V_135 ||
V_130 == V_136 ||
V_130 == V_137 )
if ( F_60 () || V_9 -> V_13 != 0 )
return - V_46 ;
V_9 -> V_92 = V_131 ;
V_51 -> V_95 &= ~ V_138 ;
V_51 -> V_111 &= ~ V_139 ;
switch ( V_130 ) {
case V_140 :
V_51 -> V_95 |= V_138 ;
break;
case V_141 :
if ( F_60 () ) {
V_33 = - V_46 ;
break;
}
V_33 = F_61 ( V_9 -> V_13 ,
V_142 ) ;
break;
case V_143 :
if ( F_60 () ) {
V_33 = 0 ;
break;
}
V_33 = F_61 ( V_9 -> V_13 ,
V_144 ) ;
break;
case V_145 :
V_51 -> V_95 |= V_138 ;
case V_146 :
V_51 -> V_111 |= V_139 ;
break;
case V_134 :
if ( F_60 () )
break;
F_62 ( V_147 ) ;
break;
case V_135 :
if ( F_60 () )
break;
F_62 ( V_148 ) ;
break;
case V_136 :
if ( F_60 () )
break;
F_63 ( V_149 ) ;
break;
case V_137 :
if ( F_60 () )
break;
F_63 ( V_150 ) ;
break;
default:
V_33 = - V_129 ;
}
return V_33 ;
}
static int F_64 ( struct V_6 * V_47 )
{
V_9 [ V_47 -> V_62 ] . V_13 = V_47 -> V_62 ;
F_65 ( V_47 , & V_9 [ V_47 -> V_62 ] . V_13 ) ;
return 0 ;
}
static int F_66 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_155 * V_156 =
(struct V_155 * ) V_152 -> V_157 ;
int V_158 = V_156 -> V_158 ;
int V_32 = V_156 -> V_32 ;
V_154 -> type = V_159 ;
V_154 -> V_160 = 1 ;
V_154 -> V_161 . integer . V_32 = V_32 ;
V_154 -> V_161 . integer . V_158 = V_158 ;
return 0 ;
}
static int F_67 ( struct V_151 * V_152 ,
struct V_162 * V_163 )
{
struct V_155 * V_156 =
(struct V_155 * ) V_152 -> V_157 ;
T_3 V_161 = V_163 -> V_161 . integer . V_161 [ 0 ] ;
if ( V_161 == F_68 ( V_156 -> V_164 ) )
return 0 ;
if ( V_161 )
F_69 ( V_156 -> V_164 ) ;
else
F_70 ( V_156 -> V_164 ) ;
return 1 ;
}
static int F_71 ( struct V_151 * V_152 ,
struct V_162 * V_163 )
{
struct V_155 * V_156 =
(struct V_155 * ) V_152 -> V_157 ;
V_163 -> V_161 . integer . V_161 [ 0 ] = F_68 ( V_156 -> V_164 ) ;
return 0 ;
}
int F_72 ( struct V_165 * V_166 , int V_167 )
{
if ( ! F_15 () )
return - V_129 ;
switch ( V_167 ) {
case 1 :
return F_73 ( V_166 , V_168 ,
F_74 ( V_168 ) ) ;
case 2 :
return F_73 ( V_166 , V_169 ,
F_74 ( V_169 ) ) ;
default:
break;
}
return - V_46 ;
}
static T_4 int F_75 ( struct V_170 * V_171 )
{
return F_76 ( & V_171 -> V_172 , & V_173 ) ;
}
static int T_5 F_77 ( struct V_170 * V_171 )
{
F_78 ( & V_171 -> V_172 ) ;
return 0 ;
}
static int T_6 F_79 ( void )
{
return F_80 ( & V_174 ) ;
}
static void T_7 F_81 ( void )
{
F_82 ( & V_174 ) ;
}
