static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
int V_11 ;
if ( V_3 )
V_11 = V_3 ;
else
V_11 = 1 ;
if ( V_2 -> V_12 == V_13 )
F_3 ( V_10 , V_11 ) ;
else
F_4 ( V_10 , V_11 ) ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_6 ( V_15 ,
V_20 ) ;
struct V_18 * V_21 = F_6 ( V_15 ,
V_22 ) ;
struct V_9 * V_10 = V_17 -> V_23 ;
struct V_18 V_24 ;
int V_25 ;
F_7 ( & V_24 ) ;
V_25 = V_10 -> V_26 -> V_19 ;
V_24 . V_27 = V_25 / V_21 -> V_27 ;
V_24 . integer = 1 ;
return F_8 ( V_19 , & V_24 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
int V_28 = 0 ;
if ( ! V_8 -> V_29 )
V_28 = F_10 ( V_10 ) ;
if ( V_10 -> V_26 -> V_19 ) {
if ( V_2 -> V_12 == V_13 )
F_11 ( V_2 -> V_30 , 0 ,
V_20 ,
F_5 ,
V_10 ,
V_22 , - 1 ) ;
F_12 ( V_2 -> V_30 , 0 ,
V_31 , 2 ) ;
}
return V_28 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
if ( ! V_8 -> V_29 ) {
F_14 ( V_10 ) ;
V_10 -> V_32 = 0 ;
}
}
static int F_15 ( struct V_1 * V_2 , int V_33 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
int V_28 = 0 , V_34 = ( V_2 -> V_12 == V_13 ) ;
switch ( V_33 ) {
case V_35 :
case V_36 :
case V_37 :
V_10 -> V_29 ++ ;
F_16 ( V_10 , V_34 , ! V_34 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
F_17 ( V_10 , V_34 , ! V_34 ) ;
V_10 -> V_29 -- ;
break;
default:
V_28 = - V_41 ;
}
return V_28 ;
}
static T_1 F_18 (
struct V_1 * V_2 ,
struct V_7 * V_42 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
T_2 V_43 ;
T_1 V_44 ;
if ( V_2 -> V_12 == V_13 )
V_43 = F_19 ( V_10 ) ;
else
V_43 = F_20 ( V_10 ) ;
V_44 = V_43 / V_2 -> V_30 -> V_21 ;
return V_44 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_45 * V_46 = & V_10 -> V_47 ;
struct V_48 * V_49 ;
int V_50 , V_21 , V_51 ;
int V_52 = 0 ;
unsigned int V_53 , div , V_54 , V_55 ;
V_49 = F_22 ( V_8 , V_2 ) ;
V_21 = F_23 ( V_15 ) ;
switch ( F_24 ( V_15 ) ) {
case V_56 :
V_50 = 16 ;
break;
case V_57 :
V_50 = 32 ;
break;
default:
return - V_41 ;
}
if ( V_10 -> V_26 -> V_19 ) {
if ( V_10 -> V_58 == V_59 ) {
int V_60 , V_61 ;
int V_62 = 0 ;
V_60 = F_25 ( V_15 ) / ( V_50 / 8 ) ;
if ( V_2 -> V_12 == V_13 )
V_61 = V_10 -> V_63 ;
else
V_61 = V_10 -> V_64 ;
V_62 = V_60 / V_61 ;
if ( V_60 % V_61 )
V_62 ++ ;
while ( V_60 % V_62 &&
V_62 < V_60 )
V_62 ++ ;
if ( V_62 == V_60 )
return - V_41 ;
V_52 = V_60 / V_62 ;
} else if ( V_21 > 1 ) {
V_52 = V_21 ;
}
F_1 ( V_2 , V_52 ) ;
}
V_49 -> V_65 = V_52 ;
if ( V_10 -> V_32 ) {
return 0 ;
}
V_46 -> V_66 &= ~ ( V_67 | F_26 ( 0x7f ) | F_27 ( 7 ) ) ;
V_46 -> V_68 &= ~ ( V_67 | F_28 ( 0x7f ) | F_29 ( 7 ) ) ;
V_46 -> V_69 &= ~ ( F_30 ( 0x7f ) | F_31 ( 7 ) ) ;
V_46 -> V_70 &= ~ ( F_32 ( 0x7f ) | F_33 ( 7 ) ) ;
V_53 = V_10 -> V_71 & V_72 ;
V_51 = V_21 ;
if ( V_21 == 2 && ( V_53 == V_73 ||
V_53 == V_74 ) ) {
V_46 -> V_66 |= V_67 ;
V_46 -> V_68 |= V_75 ;
V_51 -- ;
V_46 -> V_66 |= F_26 ( V_51 - 1 ) ;
V_46 -> V_68 |= F_28 ( V_51 - 1 ) ;
}
V_46 -> V_69 |= F_30 ( V_51 - 1 ) ;
V_46 -> V_70 |= F_32 ( V_51 - 1 ) ;
switch ( F_24 ( V_15 ) ) {
case V_56 :
V_46 -> V_66 |= F_27 ( V_76 ) ;
V_46 -> V_69 |= F_31 ( V_76 ) ;
V_46 -> V_68 |= F_29 ( V_76 ) ;
V_46 -> V_70 |= F_33 ( V_76 ) ;
break;
case V_57 :
V_46 -> V_66 |= F_27 ( V_77 ) ;
V_46 -> V_69 |= F_31 ( V_77 ) ;
V_46 -> V_68 |= F_29 ( V_77 ) ;
V_46 -> V_70 |= F_33 ( V_77 ) ;
break;
default:
return - V_41 ;
}
V_55 = V_10 -> V_71 & V_78 ;
if ( V_55 == V_79 ) {
div = V_10 -> V_80 ? V_10 -> V_80 : 1 ;
V_54 = ( V_10 -> V_81 / div ) / F_34 ( V_15 ) ;
if ( V_54 < V_50 * V_21 ) {
F_35 ( V_82 L_1
L_2 , V_83 ) ;
return - V_41 ;
}
} else
V_54 = V_50 * V_21 ;
V_46 -> V_84 &= ~ F_36 ( 0xfff ) ;
V_46 -> V_85 &= ~ F_37 ( 0xff ) ;
switch ( V_53 ) {
case V_73 :
case V_74 :
V_46 -> V_84 |= F_36 ( V_54 - 1 ) ;
V_46 -> V_85 |= F_37 ( ( V_54 >> 1 ) - 1 ) ;
break;
case V_86 :
case V_87 :
V_46 -> V_84 |= F_36 ( V_54 - 1 ) ;
V_46 -> V_85 |= F_37 ( 0 ) ;
break;
}
F_38 ( V_10 , & V_10 -> V_47 ) ;
V_10 -> V_50 = V_50 ;
V_10 -> V_32 = 1 ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 ,
unsigned int V_71 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_45 * V_46 = & V_10 -> V_47 ;
bool V_88 = false ;
if ( V_10 -> V_32 )
return 0 ;
V_10 -> V_71 = V_71 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_46 -> V_89 |= F_40 ( 3 ) | FREE ;
V_46 -> V_90 |= F_41 ( 3 ) ;
if ( ! V_10 -> V_26 -> V_91 ) {
V_46 -> V_66 |= V_92 ;
V_46 -> V_68 |= V_93 ;
}
if ( V_10 -> V_26 -> V_91 ) {
V_46 -> V_94 = F_42 ( 1 ) | V_95 | V_96 ;
V_46 -> V_97 = V_98 | V_99 | V_100 ;
}
switch ( V_71 & V_72 ) {
case V_73 :
V_46 -> V_66 |= F_43 ( 1 ) ;
V_46 -> V_68 |= F_44 ( 1 ) ;
break;
case V_74 :
V_46 -> V_66 |= F_43 ( 0 ) ;
V_46 -> V_68 |= F_44 ( 0 ) ;
V_46 -> V_90 |= F_45 ( 2 ) ;
V_88 = true ;
break;
case V_86 :
V_46 -> V_66 |= F_43 ( 1 ) ;
V_46 -> V_68 |= F_44 ( 1 ) ;
V_88 = true ;
break;
case V_87 :
V_46 -> V_66 |= F_43 ( 0 ) ;
V_46 -> V_68 |= F_44 ( 0 ) ;
V_88 = true ;
break;
default:
return - V_41 ;
}
switch ( V_71 & V_78 ) {
case V_79 :
V_46 -> V_101 |= V_102 | V_103 |
V_104 | V_105 ;
V_46 -> V_84 |= V_106 ;
break;
case V_107 :
V_46 -> V_84 |= V_106 ;
V_46 -> V_101 |= V_102 | V_103 ;
break;
case V_108 :
break;
default:
return - V_41 ;
}
switch ( V_71 & V_109 ) {
case V_110 :
V_46 -> V_101 |= V_111 | V_112 |
V_113 | V_114 ;
break;
case V_115 :
V_46 -> V_101 |= V_113 | V_114 ;
break;
case V_116 :
V_46 -> V_101 |= V_111 | V_112 ;
break;
case V_117 :
break;
default:
return - V_41 ;
}
if ( V_88 == true )
V_46 -> V_101 ^= V_111 | V_112 ;
return 0 ;
}
static int F_46 ( struct V_7 * V_8 ,
int V_118 , int div )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_45 * V_46 = & V_10 -> V_47 ;
if ( V_118 != V_119 )
return - V_120 ;
V_10 -> V_80 = div ;
V_46 -> V_85 &= ~ F_47 ( 0xff ) ;
V_46 -> V_85 |= F_47 ( div - 1 ) ;
return 0 ;
}
static int F_48 ( struct V_7 * V_8 ,
int V_121 , unsigned int V_122 ,
int V_123 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_45 * V_46 = & V_10 -> V_47 ;
int V_28 = 0 ;
if ( V_10 -> V_29 ) {
if ( V_122 == V_10 -> V_81 )
return 0 ;
else
return - V_124 ;
}
V_10 -> V_81 = V_122 ;
V_46 -> V_84 &= ~ V_125 ;
V_46 -> V_101 &= ~ V_126 ;
switch ( V_121 ) {
case V_127 :
V_46 -> V_84 |= V_125 ;
break;
case V_128 :
if ( F_49 () ) {
V_28 = - V_41 ;
break;
}
V_28 = F_50 ( V_10 ,
V_129 ) ;
break;
case V_130 :
if ( F_49 () ) {
V_28 = 0 ;
break;
}
V_28 = F_50 ( V_10 ,
V_131 ) ;
break;
case V_132 :
V_46 -> V_84 |= V_125 ;
case V_133 :
V_46 -> V_101 |= V_126 ;
break;
default:
V_28 = - V_120 ;
}
return V_28 ;
}
static int F_51 ( struct V_7 * V_42 )
{
struct V_9 * V_10 = F_2 ( V_42 ) ;
F_52 ( V_10 -> V_134 ) ;
F_53 ( V_42 ,
& V_10 -> V_49 [ V_13 ] ,
& V_10 -> V_49 [ V_135 ] ) ;
return 0 ;
}
static int F_54 ( struct V_7 * V_42 )
{
struct V_9 * V_10 = F_2 ( V_42 ) ;
F_55 ( V_10 -> V_134 ) ;
return 0 ;
}
static int F_56 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_140 * V_141 =
(struct V_140 * ) V_137 -> V_142 ;
int V_143 = V_141 -> V_143 ;
int V_27 = V_141 -> V_27 ;
V_139 -> type = V_144 ;
V_139 -> V_145 = 1 ;
V_139 -> V_146 . integer . V_27 = V_27 ;
V_139 -> V_146 . integer . V_143 = V_143 ;
return 0 ;
}
static int F_57 ( struct V_136 * V_137 ,
struct V_147 * V_148 )
{
struct V_7 * V_8 = F_58 ( V_137 ) ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
T_3 V_146 = V_148 -> V_146 . integer . V_146 [ 0 ] ;
if ( V_146 == F_59 ( V_10 ) )
return 0 ;
if ( V_146 )
F_60 ( V_10 ) ;
else
F_61 ( V_10 ) ;
return 1 ;
}
static int F_62 ( struct V_136 * V_137 ,
struct V_147 * V_148 )
{
struct V_7 * V_8 = F_58 ( V_137 ) ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
V_148 -> V_146 . integer . V_146 [ 0 ] = F_59 ( V_10 ) ;
return 0 ;
}
int F_63 ( struct V_4 * V_5 , int V_149 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
if ( ! V_10 -> V_150 ) {
F_64 ( V_10 -> V_134 , L_3 ) ;
return 0 ;
}
switch ( V_149 ) {
case 2 :
return F_65 ( V_8 ,
V_151 ,
F_66 ( V_151 ) ) ;
case 3 :
return F_65 ( V_8 ,
V_152 ,
F_66 ( V_152 ) ) ;
default:
F_67 ( V_10 -> V_134 , L_4 , V_149 ) ;
break;
}
return - V_41 ;
}
static int F_68 ( struct V_153 * V_154 )
{
struct V_155 * V_26 = F_69 ( & V_154 -> V_134 ) ;
struct V_9 * V_10 ;
const struct V_156 * V_157 ;
int V_158 ;
V_157 = F_70 ( V_159 , & V_154 -> V_134 ) ;
if ( V_157 ) {
struct V_160 * V_161 = V_154 -> V_134 . V_162 ;
int V_19 ;
V_26 = F_71 ( & V_154 -> V_134 ,
sizeof( struct V_155 ) ,
V_163 ) ;
if ( ! V_26 )
return - V_164 ;
memcpy ( V_26 , V_157 -> V_165 , sizeof( * V_26 ) ) ;
if ( ! F_72 ( V_161 , L_5 , & V_19 ) )
V_26 -> V_19 = V_19 ;
} else if ( ! V_26 ) {
F_67 ( & V_154 -> V_134 , L_6 ) ;
return - V_41 ;
}
V_10 = F_71 ( & V_154 -> V_134 , sizeof( struct V_9 ) , V_163 ) ;
if ( ! V_10 )
return - V_164 ;
V_10 -> V_166 = V_154 -> V_166 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_134 = & V_154 -> V_134 ;
F_73 ( V_154 , V_10 ) ;
V_158 = F_74 ( V_154 ) ;
if ( V_158 )
return V_158 ;
V_158 = F_75 ( & V_154 -> V_134 ,
& V_167 ,
& V_168 , 1 ) ;
if ( V_158 )
return V_158 ;
return F_76 ( & V_154 -> V_134 ) ;
}
static int F_77 ( struct V_153 * V_154 )
{
struct V_9 * V_10 = F_78 ( V_154 ) ;
if ( V_10 -> V_26 -> V_169 && V_10 -> V_26 -> V_169 -> free )
V_10 -> V_26 -> V_169 -> free ( V_10 -> V_166 ) ;
F_79 ( V_10 ) ;
F_80 ( V_10 -> V_170 ) ;
return 0 ;
}
