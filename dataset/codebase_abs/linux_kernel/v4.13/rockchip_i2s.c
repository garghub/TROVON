static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , true ) ;
F_4 ( V_4 -> V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
V_7 = F_6 ( V_4 -> V_6 ) ;
if ( V_7 ) {
F_7 ( V_4 -> V_2 , L_1 , V_7 ) ;
return V_7 ;
}
F_3 ( V_4 -> V_5 , false ) ;
F_8 ( V_4 -> V_5 ) ;
V_7 = F_9 ( V_4 -> V_5 ) ;
if ( V_7 )
F_4 ( V_4 -> V_6 ) ;
return V_7 ;
}
static inline struct V_3 * F_10 ( struct V_8 * V_9 )
{
return F_11 ( V_9 ) ;
}
static void F_12 ( struct V_3 * V_4 , int V_10 )
{
unsigned int V_11 = 0 ;
int V_12 = 10 ;
if ( V_10 ) {
F_13 ( V_4 -> V_5 , V_13 ,
V_14 , V_14 ) ;
F_13 ( V_4 -> V_5 , V_15 ,
V_16 | V_17 ,
V_16 | V_17 ) ;
V_4 -> V_18 = true ;
} else {
V_4 -> V_18 = false ;
F_13 ( V_4 -> V_5 , V_13 ,
V_14 , V_19 ) ;
if ( ! V_4 -> V_20 ) {
F_13 ( V_4 -> V_5 , V_15 ,
V_16 |
V_17 ,
V_21 |
V_22 ) ;
F_14 ( 150 ) ;
F_13 ( V_4 -> V_5 , V_23 ,
V_24 | V_25 ,
V_24 | V_25 ) ;
F_15 ( V_4 -> V_5 , V_23 , & V_11 ) ;
while ( V_11 ) {
F_15 ( V_4 -> V_5 , V_23 , & V_11 ) ;
V_12 -- ;
if ( ! V_12 ) {
F_16 ( V_4 -> V_2 , L_2 ) ;
break;
}
}
}
}
}
static void F_17 ( struct V_3 * V_4 , int V_10 )
{
unsigned int V_11 = 0 ;
int V_12 = 10 ;
if ( V_10 ) {
F_13 ( V_4 -> V_5 , V_13 ,
V_26 , V_26 ) ;
F_13 ( V_4 -> V_5 , V_15 ,
V_16 | V_17 ,
V_16 | V_17 ) ;
V_4 -> V_20 = true ;
} else {
V_4 -> V_20 = false ;
F_13 ( V_4 -> V_5 , V_13 ,
V_26 , V_27 ) ;
if ( ! V_4 -> V_18 ) {
F_13 ( V_4 -> V_5 , V_15 ,
V_16 |
V_17 ,
V_21 |
V_22 ) ;
F_14 ( 150 ) ;
F_13 ( V_4 -> V_5 , V_23 ,
V_24 | V_25 ,
V_24 | V_25 ) ;
F_15 ( V_4 -> V_5 , V_23 , & V_11 ) ;
while ( V_11 ) {
F_15 ( V_4 -> V_5 , V_23 , & V_11 ) ;
V_12 -- ;
if ( ! V_12 ) {
F_16 ( V_4 -> V_2 , L_2 ) ;
break;
}
}
}
}
}
static int F_18 ( struct V_8 * V_28 ,
unsigned int V_29 )
{
struct V_3 * V_4 = F_10 ( V_28 ) ;
unsigned int V_30 = 0 , V_11 = 0 ;
V_30 = V_31 ;
switch ( V_29 & V_32 ) {
case V_33 :
V_11 = V_34 ;
V_4 -> V_35 = true ;
break;
case V_36 :
V_11 = V_37 ;
V_4 -> V_35 = false ;
break;
default:
return - V_38 ;
}
F_13 ( V_4 -> V_5 , V_39 , V_30 , V_11 ) ;
V_30 = V_40 ;
switch ( V_29 & V_41 ) {
case V_42 :
V_11 = V_43 ;
break;
case V_44 :
V_11 = V_45 ;
break;
default:
return - V_38 ;
}
F_13 ( V_4 -> V_5 , V_39 , V_30 , V_11 ) ;
V_30 = V_46 | V_47 | V_48 ;
switch ( V_29 & V_49 ) {
case V_50 :
V_11 = V_51 ;
break;
case V_52 :
V_11 = V_53 ;
break;
case V_54 :
V_11 = V_55 ;
break;
case V_56 :
V_11 = V_57 ;
break;
case V_58 :
V_11 = V_57 | F_19 ( 1 ) ;
break;
default:
return - V_38 ;
}
F_13 ( V_4 -> V_5 , V_59 , V_30 , V_11 ) ;
V_30 = V_60 | V_61 | V_62 ;
switch ( V_29 & V_49 ) {
case V_50 :
V_11 = V_63 ;
break;
case V_52 :
V_11 = V_64 ;
break;
case V_54 :
V_11 = V_65 ;
break;
case V_56 :
V_11 = V_66 ;
break;
case V_58 :
V_11 = V_66 | F_20 ( 1 ) ;
break;
default:
return - V_38 ;
}
F_13 ( V_4 -> V_5 , V_67 , V_30 , V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = F_10 ( V_9 ) ;
struct V_72 * V_73 = V_69 -> V_74 ;
unsigned int V_11 = 0 ;
unsigned int V_75 , V_76 , V_77 , V_78 ;
if ( V_4 -> V_35 ) {
V_75 = F_22 ( V_4 -> V_6 ) ;
V_76 = 2 * 32 * F_23 ( V_71 ) ;
if ( V_76 && V_75 % V_76 )
return - V_38 ;
V_77 = V_75 / V_76 ;
V_78 = V_76 / F_23 ( V_71 ) ;
F_13 ( V_4 -> V_5 , V_39 ,
V_79 ,
F_24 ( V_77 ) ) ;
F_13 ( V_4 -> V_5 , V_39 ,
V_80 |
V_81 ,
F_25 ( V_78 ) |
F_26 ( V_78 ) ) ;
}
switch ( F_27 ( V_71 ) ) {
case V_82 :
V_11 |= F_28 ( 8 ) ;
break;
case V_83 :
V_11 |= F_28 ( 16 ) ;
break;
case V_84 :
V_11 |= F_28 ( 20 ) ;
break;
case V_85 :
V_11 |= F_28 ( 24 ) ;
break;
case V_86 :
V_11 |= F_28 ( 32 ) ;
break;
default:
return - V_38 ;
}
switch ( F_29 ( V_71 ) ) {
case 8 :
V_11 |= V_87 ;
break;
case 6 :
V_11 |= V_88 ;
break;
case 4 :
V_11 |= V_89 ;
break;
case 2 :
V_11 |= V_90 ;
break;
default:
F_7 ( V_4 -> V_2 , L_3 ,
F_29 ( V_71 ) ) ;
return - V_38 ;
}
if ( V_69 -> V_91 == V_92 )
F_13 ( V_4 -> V_5 , V_67 ,
V_93 | V_94 ,
V_11 ) ;
else
F_13 ( V_4 -> V_5 , V_59 ,
V_95 | V_96 ,
V_11 ) ;
if ( ! F_30 ( V_4 -> V_97 ) && V_4 -> V_98 ) {
F_15 ( V_4 -> V_5 , V_59 , & V_11 ) ;
V_11 &= V_96 ;
switch ( V_11 ) {
case V_89 :
V_11 = V_99 ;
break;
case V_88 :
V_11 = V_100 ;
break;
case V_87 :
V_11 = V_101 ;
break;
default:
V_11 = V_102 ;
break;
}
V_11 <<= V_4 -> V_98 -> V_103 ;
V_11 |= ( V_104 << V_4 -> V_98 -> V_103 ) << 16 ;
F_31 ( V_4 -> V_97 , V_4 -> V_98 -> V_105 , V_11 ) ;
}
F_13 ( V_4 -> V_5 , V_13 , V_106 ,
F_32 ( 16 ) ) ;
F_13 ( V_4 -> V_5 , V_13 , V_107 ,
F_33 ( 16 ) ) ;
V_11 = V_108 ;
if ( V_9 -> V_109 -> V_110 && V_73 -> V_111 -> V_110 )
V_11 = V_112 ;
F_13 ( V_4 -> V_5 , V_39 ,
V_113 ,
V_11 ) ;
return 0 ;
}
static int F_34 ( struct V_68 * V_69 ,
int V_114 , struct V_8 * V_9 )
{
struct V_3 * V_4 = F_10 ( V_9 ) ;
int V_7 = 0 ;
switch ( V_114 ) {
case V_115 :
case V_116 :
case V_117 :
if ( V_69 -> V_91 == V_92 )
F_17 ( V_4 , 1 ) ;
else
F_12 ( V_4 , 1 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
if ( V_69 -> V_91 == V_92 )
F_17 ( V_4 , 0 ) ;
else
F_12 ( V_4 , 0 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static int F_35 ( struct V_8 * V_28 , int V_121 ,
unsigned int V_122 , int V_123 )
{
struct V_3 * V_4 = F_10 ( V_28 ) ;
int V_7 ;
V_7 = F_36 ( V_4 -> V_6 , V_122 ) ;
if ( V_7 )
F_7 ( V_4 -> V_2 , L_4 , V_7 ) ;
return V_7 ;
}
static int F_37 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_11 ( V_9 ) ;
V_9 -> V_124 = & V_4 -> V_124 ;
V_9 -> V_125 = & V_4 -> V_125 ;
return 0 ;
}
static bool F_38 ( struct V_1 * V_2 , unsigned int V_126 )
{
switch ( V_126 ) {
case V_59 :
case V_67 :
case V_39 :
case V_13 :
case V_127 :
case V_15 :
case V_23 :
case V_128 :
return true ;
default:
return false ;
}
}
static bool F_39 ( struct V_1 * V_2 , unsigned int V_126 )
{
switch ( V_126 ) {
case V_59 :
case V_67 :
case V_39 :
case V_13 :
case V_127 :
case V_15 :
case V_23 :
case V_129 :
case V_130 :
case V_131 :
return true ;
default:
return false ;
}
}
static bool F_40 ( struct V_1 * V_2 , unsigned int V_126 )
{
switch ( V_126 ) {
case V_131 :
case V_23 :
return true ;
default:
return false ;
}
}
static bool F_41 ( struct V_1 * V_2 , unsigned int V_126 )
{
switch ( V_126 ) {
default:
return false ;
}
}
static int F_42 ( struct V_132 * V_133 )
{
struct V_134 * V_135 = V_133 -> V_2 . V_136 ;
const struct V_137 * V_138 ;
struct V_3 * V_4 ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
void T_1 * V_143 ;
int V_7 ;
int V_11 ;
V_4 = F_43 ( & V_133 -> V_2 , sizeof( * V_4 ) , V_144 ) ;
if ( ! V_4 ) {
F_7 ( & V_133 -> V_2 , L_5 ) ;
return - V_145 ;
}
V_4 -> V_2 = & V_133 -> V_2 ;
V_4 -> V_97 = F_44 ( V_135 , L_6 ) ;
if ( ! F_30 ( V_4 -> V_97 ) ) {
V_138 = F_45 ( V_146 , & V_133 -> V_2 ) ;
if ( ! V_138 || ! V_138 -> V_147 )
return - V_38 ;
V_4 -> V_98 = V_138 -> V_147 ;
}
V_4 -> V_148 = F_46 ( & V_133 -> V_2 , L_7 ) ;
if ( F_30 ( V_4 -> V_148 ) ) {
F_7 ( & V_133 -> V_2 , L_8 ) ;
return F_47 ( V_4 -> V_148 ) ;
}
V_7 = F_6 ( V_4 -> V_148 ) ;
if ( V_7 ) {
F_7 ( V_4 -> V_2 , L_9 , V_7 ) ;
return V_7 ;
}
V_4 -> V_6 = F_46 ( & V_133 -> V_2 , L_10 ) ;
if ( F_30 ( V_4 -> V_6 ) ) {
F_7 ( & V_133 -> V_2 , L_11 ) ;
return F_47 ( V_4 -> V_6 ) ;
}
V_142 = F_48 ( V_133 , V_149 , 0 ) ;
V_143 = F_49 ( & V_133 -> V_2 , V_142 ) ;
if ( F_30 ( V_143 ) )
return F_47 ( V_143 ) ;
V_4 -> V_5 = F_50 ( & V_133 -> V_2 , V_143 ,
& V_150 ) ;
if ( F_30 ( V_4 -> V_5 ) ) {
F_7 ( & V_133 -> V_2 ,
L_12 ) ;
return F_47 ( V_4 -> V_5 ) ;
}
V_4 -> V_125 . V_151 = V_142 -> V_152 + V_128 ;
V_4 -> V_125 . V_153 = V_154 ;
V_4 -> V_125 . V_155 = 4 ;
V_4 -> V_124 . V_151 = V_142 -> V_152 + V_129 ;
V_4 -> V_124 . V_153 = V_154 ;
V_4 -> V_124 . V_155 = 4 ;
F_51 ( & V_133 -> V_2 , V_4 ) ;
F_52 ( & V_133 -> V_2 ) ;
if ( ! F_53 ( & V_133 -> V_2 ) ) {
V_7 = F_5 ( & V_133 -> V_2 ) ;
if ( V_7 )
goto V_156;
}
V_140 = F_54 ( & V_133 -> V_2 , & V_157 ,
sizeof( * V_140 ) , V_144 ) ;
if ( ! V_140 ) {
V_7 = - V_145 ;
goto V_156;
}
if ( ! F_55 ( V_135 , L_13 , & V_11 ) ) {
if ( V_11 >= 2 && V_11 <= 8 )
V_140 -> V_158 . V_159 = V_11 ;
}
if ( ! F_55 ( V_135 , L_14 , & V_11 ) ) {
if ( V_11 >= 2 && V_11 <= 8 )
V_140 -> V_160 . V_159 = V_11 ;
}
V_7 = F_56 ( & V_133 -> V_2 ,
& V_161 ,
V_140 , 1 ) ;
if ( V_7 ) {
F_7 ( & V_133 -> V_2 , L_15 ) ;
goto V_162;
}
V_7 = F_57 ( & V_133 -> V_2 , NULL , 0 ) ;
if ( V_7 ) {
F_7 ( & V_133 -> V_2 , L_16 ) ;
return V_7 ;
}
return 0 ;
V_162:
if ( ! F_58 ( & V_133 -> V_2 ) )
F_1 ( & V_133 -> V_2 ) ;
V_156:
F_59 ( & V_133 -> V_2 ) ;
return V_7 ;
}
static int F_60 ( struct V_132 * V_133 )
{
struct V_3 * V_4 = F_2 ( & V_133 -> V_2 ) ;
F_59 ( & V_133 -> V_2 ) ;
if ( ! F_58 ( & V_133 -> V_2 ) )
F_1 ( & V_133 -> V_2 ) ;
F_4 ( V_4 -> V_6 ) ;
F_4 ( V_4 -> V_148 ) ;
return 0 ;
}
