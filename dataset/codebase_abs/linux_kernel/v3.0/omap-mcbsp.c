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
V_58 = V_9 -> V_77 & V_78 ;
V_53 = V_27 = F_35 ( V_21 ) ;
if ( V_27 == 2 && ( V_58 == V_79 ||
V_58 == V_80 ) ) {
V_51 -> V_81 |= V_82 ;
V_51 -> V_83 |= V_84 ;
V_53 -- ;
V_51 -> V_81 |= F_36 ( V_53 - 1 ) ;
V_51 -> V_83 |= F_37 ( V_53 - 1 ) ;
}
V_51 -> V_85 |= F_38 ( V_53 - 1 ) ;
V_51 -> V_86 |= F_39 ( V_53 - 1 ) ;
switch ( F_30 ( V_21 ) ) {
case V_63 :
V_51 -> V_81 |= F_40 ( V_87 ) ;
V_51 -> V_85 |= F_41 ( V_87 ) ;
V_51 -> V_83 |= F_42 ( V_87 ) ;
V_51 -> V_86 |= F_43 ( V_87 ) ;
break;
case V_66 :
V_51 -> V_81 |= F_40 ( V_88 ) ;
V_51 -> V_85 |= F_41 ( V_88 ) ;
V_51 -> V_83 |= F_42 ( V_88 ) ;
V_51 -> V_86 |= F_43 ( V_88 ) ;
break;
default:
return - V_46 ;
}
V_60 = V_9 -> V_77 & V_89 ;
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
switch ( V_58 ) {
case V_79 :
case V_80 :
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
unsigned int V_77 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_50 * V_51 = & V_9 -> V_51 ;
unsigned int V_99 = V_77 ;
if ( V_9 -> V_37 )
return 0 ;
V_9 -> V_77 = V_77 ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_100 |= F_50 ( 3 ) | FREE ;
V_51 -> V_101 |= F_51 ( 3 ) ;
if ( ! F_15 () && ! F_16 () ) {
V_51 -> V_81 |= V_102 ;
V_51 -> V_83 |= V_103 ;
}
if ( F_52 () || F_15 () || F_16 () ) {
V_51 -> V_104 = F_53 ( 1 ) | V_105 | V_106 ;
V_51 -> V_107 = V_108 | V_109 | V_110 ;
}
switch ( V_77 & V_78 ) {
case V_79 :
V_51 -> V_81 |= F_54 ( 1 ) ;
V_51 -> V_83 |= F_55 ( 1 ) ;
break;
case V_80 :
V_51 -> V_81 |= F_54 ( 0 ) ;
V_51 -> V_83 |= F_55 ( 0 ) ;
V_51 -> V_101 |= F_56 ( 2 ) ;
V_99 ^= V_111 ;
break;
case V_97 :
V_51 -> V_81 |= F_54 ( 1 ) ;
V_51 -> V_83 |= F_55 ( 1 ) ;
V_99 ^= V_111 ;
break;
case V_98 :
V_51 -> V_81 |= F_54 ( 0 ) ;
V_51 -> V_83 |= F_55 ( 0 ) ;
V_99 ^= V_111 ;
break;
default:
return - V_46 ;
}
switch ( V_77 & V_89 ) {
case V_90 :
V_51 -> V_112 |= V_113 | V_114 |
V_115 | V_116 ;
V_51 -> V_95 |= V_117 ;
break;
case V_118 :
break;
default:
return - V_46 ;
}
switch ( V_99 & V_119 ) {
case V_120 :
V_51 -> V_112 |= V_121 | V_122 |
V_123 | V_124 ;
break;
case V_111 :
V_51 -> V_112 |= V_123 | V_124 ;
break;
case V_125 :
V_51 -> V_112 |= V_121 | V_122 ;
break;
case V_126 :
break;
default:
return - V_46 ;
}
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
if ( V_130 == V_133 ||
V_130 == V_134 ||
V_130 == V_135 ||
V_130 == V_136 )
if ( F_60 () || V_9 -> V_13 != 0 )
return - V_46 ;
V_9 -> V_92 = V_131 ;
switch ( V_130 ) {
case V_137 :
V_51 -> V_95 |= V_138 ;
break;
case V_139 :
if ( F_60 () ) {
V_33 = - V_46 ;
break;
}
V_33 = F_61 ( V_9 -> V_13 ,
V_140 ) ;
break;
case V_141 :
if ( F_60 () ) {
V_33 = 0 ;
break;
}
V_33 = F_61 ( V_9 -> V_13 ,
V_142 ) ;
break;
case V_143 :
V_51 -> V_95 |= V_138 ;
case V_144 :
V_51 -> V_112 |= V_145 ;
break;
case V_133 :
if ( F_60 () )
break;
F_62 ( V_146 ) ;
break;
case V_134 :
if ( F_60 () )
break;
F_62 ( V_147 ) ;
break;
case V_135 :
if ( F_60 () )
break;
F_63 ( V_148 ) ;
break;
case V_136 :
if ( F_60 () )
break;
F_63 ( V_149 ) ;
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
static int F_66 ( struct V_150 * V_151 ,
struct V_152 * V_153 )
{
struct V_154 * V_155 =
(struct V_154 * ) V_151 -> V_156 ;
int V_157 = V_155 -> V_157 ;
int V_32 = V_155 -> V_32 ;
V_153 -> type = V_158 ;
V_153 -> V_159 = 1 ;
V_153 -> V_160 . integer . V_32 = V_32 ;
V_153 -> V_160 . integer . V_157 = V_157 ;
return 0 ;
}
static int F_67 ( struct V_150 * V_151 ,
struct V_161 * V_162 )
{
struct V_154 * V_155 =
(struct V_154 * ) V_151 -> V_156 ;
T_3 V_160 = V_162 -> V_160 . integer . V_160 [ 0 ] ;
if ( V_160 == F_68 ( V_155 -> V_163 ) )
return 0 ;
if ( V_160 )
F_69 ( V_155 -> V_163 ) ;
else
F_70 ( V_155 -> V_163 ) ;
return 1 ;
}
static int F_71 ( struct V_150 * V_151 ,
struct V_161 * V_162 )
{
struct V_154 * V_155 =
(struct V_154 * ) V_151 -> V_156 ;
V_162 -> V_160 . integer . V_160 [ 0 ] = F_68 ( V_155 -> V_163 ) ;
return 0 ;
}
int F_72 ( struct V_164 * V_165 , int V_166 )
{
if ( ! F_15 () )
return - V_129 ;
switch ( V_166 ) {
case 1 :
return F_73 ( V_165 , V_167 ,
F_74 ( V_167 ) ) ;
case 2 :
return F_73 ( V_165 , V_168 ,
F_74 ( V_168 ) ) ;
default:
break;
}
return - V_46 ;
}
static T_4 int F_75 ( struct V_169 * V_170 )
{
return F_76 ( & V_170 -> V_171 , & V_172 ) ;
}
static int T_5 F_77 ( struct V_169 * V_170 )
{
F_78 ( & V_170 -> V_171 ) ;
return 0 ;
}
static int T_6 F_79 ( void )
{
return F_80 ( & V_173 ) ;
}
static void T_7 F_81 ( void )
{
F_82 ( & V_173 ) ;
}
