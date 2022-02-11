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
F_13 ( V_8 , V_2 ,
& V_10 -> V_32 [ V_2 -> V_12 ] ) ;
return V_28 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
if ( ! V_8 -> V_29 ) {
F_15 ( V_10 ) ;
V_10 -> V_33 = 0 ;
}
}
static int F_16 ( struct V_1 * V_2 , int V_34 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
int V_28 = 0 , V_35 = ( V_2 -> V_12 == V_13 ) ;
switch ( V_34 ) {
case V_36 :
case V_37 :
case V_38 :
V_10 -> V_29 ++ ;
F_17 ( V_10 , V_35 , ! V_35 ) ;
break;
case V_39 :
case V_40 :
case V_41 :
F_18 ( V_10 , V_35 , ! V_35 ) ;
V_10 -> V_29 -- ;
break;
default:
V_28 = - V_42 ;
}
return V_28 ;
}
static T_1 F_19 (
struct V_1 * V_2 ,
struct V_7 * V_43 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
T_2 V_44 ;
T_1 V_45 ;
if ( V_2 -> V_12 == V_13 )
V_44 = F_20 ( V_10 ) ;
else
V_44 = F_21 ( V_10 ) ;
V_45 = V_44 / V_2 -> V_30 -> V_21 ;
return V_45 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_46 * V_47 = & V_10 -> V_48 ;
struct V_49 * V_32 ;
int V_50 , V_21 , V_51 ;
int V_52 = 0 ;
unsigned int V_53 , div , V_54 , V_55 ;
V_32 = F_23 ( V_8 , V_2 ) ;
V_21 = F_24 ( V_15 ) ;
switch ( F_25 ( V_15 ) ) {
case V_56 :
V_50 = 16 ;
break;
case V_57 :
V_50 = 32 ;
break;
default:
return - V_42 ;
}
if ( V_10 -> V_26 -> V_19 ) {
if ( V_10 -> V_58 == V_59 ) {
int V_60 , V_61 ;
int V_62 = 0 ;
V_60 = F_26 ( V_15 ) / ( V_50 / 8 ) ;
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
return - V_42 ;
V_52 = V_60 / V_62 ;
} else if ( V_21 > 1 ) {
V_52 = V_21 ;
}
F_1 ( V_2 , V_52 ) ;
}
V_32 -> V_65 = V_52 ;
if ( V_10 -> V_33 ) {
return 0 ;
}
V_47 -> V_66 &= ~ ( V_67 | F_27 ( 0x7f ) | F_28 ( 7 ) ) ;
V_47 -> V_68 &= ~ ( V_67 | F_29 ( 0x7f ) | F_30 ( 7 ) ) ;
V_47 -> V_69 &= ~ ( F_31 ( 0x7f ) | F_32 ( 7 ) ) ;
V_47 -> V_70 &= ~ ( F_33 ( 0x7f ) | F_34 ( 7 ) ) ;
V_53 = V_10 -> V_71 & V_72 ;
V_51 = V_21 ;
if ( V_21 == 2 && ( V_53 == V_73 ||
V_53 == V_74 ) ) {
V_47 -> V_66 |= V_67 ;
V_47 -> V_68 |= V_75 ;
V_51 -- ;
V_47 -> V_66 |= F_27 ( V_51 - 1 ) ;
V_47 -> V_68 |= F_29 ( V_51 - 1 ) ;
}
V_47 -> V_69 |= F_31 ( V_51 - 1 ) ;
V_47 -> V_70 |= F_33 ( V_51 - 1 ) ;
switch ( F_25 ( V_15 ) ) {
case V_56 :
V_47 -> V_66 |= F_28 ( V_76 ) ;
V_47 -> V_69 |= F_32 ( V_76 ) ;
V_47 -> V_68 |= F_30 ( V_76 ) ;
V_47 -> V_70 |= F_34 ( V_76 ) ;
break;
case V_57 :
V_47 -> V_66 |= F_28 ( V_77 ) ;
V_47 -> V_69 |= F_32 ( V_77 ) ;
V_47 -> V_68 |= F_30 ( V_77 ) ;
V_47 -> V_70 |= F_34 ( V_77 ) ;
break;
default:
return - V_42 ;
}
V_55 = V_10 -> V_71 & V_78 ;
if ( V_55 == V_79 ) {
div = V_10 -> V_80 ? V_10 -> V_80 : 1 ;
V_54 = ( V_10 -> V_81 / div ) / F_35 ( V_15 ) ;
if ( V_54 < V_50 * V_21 ) {
F_36 ( V_82 L_1
L_2 , V_83 ) ;
return - V_42 ;
}
} else
V_54 = V_50 * V_21 ;
V_47 -> V_84 &= ~ F_37 ( 0xfff ) ;
V_47 -> V_85 &= ~ F_38 ( 0xff ) ;
switch ( V_53 ) {
case V_73 :
case V_74 :
V_47 -> V_84 |= F_37 ( V_54 - 1 ) ;
V_47 -> V_85 |= F_38 ( ( V_54 >> 1 ) - 1 ) ;
break;
case V_86 :
case V_87 :
V_47 -> V_84 |= F_37 ( V_54 - 1 ) ;
V_47 -> V_85 |= F_38 ( 0 ) ;
break;
}
F_39 ( V_10 , & V_10 -> V_48 ) ;
V_10 -> V_50 = V_50 ;
V_10 -> V_33 = 1 ;
return 0 ;
}
static int F_40 ( struct V_7 * V_8 ,
unsigned int V_71 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_46 * V_47 = & V_10 -> V_48 ;
bool V_88 = false ;
if ( V_10 -> V_33 )
return 0 ;
V_10 -> V_71 = V_71 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_89 |= F_41 ( 3 ) | FREE ;
V_47 -> V_90 |= F_42 ( 3 ) ;
if ( ! V_10 -> V_26 -> V_91 ) {
V_47 -> V_66 |= V_92 ;
V_47 -> V_68 |= V_93 ;
}
if ( V_10 -> V_26 -> V_91 ) {
V_47 -> V_94 = F_43 ( 1 ) | V_95 | V_96 ;
V_47 -> V_97 = V_98 | V_99 | V_100 ;
}
switch ( V_71 & V_72 ) {
case V_73 :
V_47 -> V_66 |= F_44 ( 1 ) ;
V_47 -> V_68 |= F_45 ( 1 ) ;
break;
case V_74 :
V_47 -> V_66 |= F_44 ( 0 ) ;
V_47 -> V_68 |= F_45 ( 0 ) ;
V_47 -> V_90 |= F_46 ( 2 ) ;
V_88 = true ;
break;
case V_86 :
V_47 -> V_66 |= F_44 ( 1 ) ;
V_47 -> V_68 |= F_45 ( 1 ) ;
V_88 = true ;
break;
case V_87 :
V_47 -> V_66 |= F_44 ( 0 ) ;
V_47 -> V_68 |= F_45 ( 0 ) ;
V_88 = true ;
break;
default:
return - V_42 ;
}
switch ( V_71 & V_78 ) {
case V_79 :
V_47 -> V_101 |= V_102 | V_103 |
V_104 | V_105 ;
V_47 -> V_84 |= V_106 ;
break;
case V_107 :
V_47 -> V_84 |= V_106 ;
V_47 -> V_101 |= V_102 ;
break;
case V_108 :
break;
default:
return - V_42 ;
}
switch ( V_71 & V_109 ) {
case V_110 :
V_47 -> V_101 |= V_111 | V_112 |
V_113 | V_114 ;
break;
case V_115 :
V_47 -> V_101 |= V_113 | V_114 ;
break;
case V_116 :
V_47 -> V_101 |= V_111 | V_112 ;
break;
case V_117 :
break;
default:
return - V_42 ;
}
if ( V_88 == true )
V_47 -> V_101 ^= V_111 | V_112 ;
return 0 ;
}
static int F_47 ( struct V_7 * V_8 ,
int V_118 , int div )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_46 * V_47 = & V_10 -> V_48 ;
if ( V_118 != V_119 )
return - V_120 ;
V_10 -> V_80 = div ;
V_47 -> V_85 &= ~ F_48 ( 0xff ) ;
V_47 -> V_85 |= F_48 ( div - 1 ) ;
return 0 ;
}
static int F_49 ( struct V_7 * V_8 ,
int V_121 , unsigned int V_122 ,
int V_123 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_46 * V_47 = & V_10 -> V_48 ;
int V_28 = 0 ;
if ( V_10 -> V_29 ) {
if ( V_122 == V_10 -> V_81 )
return 0 ;
else
return - V_124 ;
}
V_10 -> V_81 = V_122 ;
V_47 -> V_84 &= ~ V_125 ;
V_47 -> V_101 &= ~ V_126 ;
switch ( V_121 ) {
case V_127 :
V_47 -> V_84 |= V_125 ;
break;
case V_128 :
if ( F_50 () ) {
V_28 = - V_42 ;
break;
}
V_28 = F_51 ( V_10 ,
V_129 ) ;
break;
case V_130 :
if ( F_50 () ) {
V_28 = 0 ;
break;
}
V_28 = F_51 ( V_10 ,
V_131 ) ;
break;
case V_132 :
V_47 -> V_84 |= V_125 ;
case V_133 :
V_47 -> V_101 |= V_126 ;
break;
default:
V_28 = - V_120 ;
}
return V_28 ;
}
static int F_52 ( struct V_7 * V_43 )
{
struct V_9 * V_10 = F_2 ( V_43 ) ;
F_53 ( V_10 -> V_134 ) ;
return 0 ;
}
static int F_54 ( struct V_7 * V_43 )
{
struct V_9 * V_10 = F_2 ( V_43 ) ;
F_55 ( V_10 -> V_134 ) ;
return 0 ;
}
static int F_56 ( struct V_135 * V_136 ,
struct V_137 * V_138 )
{
struct V_139 * V_140 =
(struct V_139 * ) V_136 -> V_141 ;
int V_142 = V_140 -> V_142 ;
int V_27 = V_140 -> V_27 ;
V_138 -> type = V_143 ;
V_138 -> V_144 = 1 ;
V_138 -> V_145 . integer . V_27 = V_27 ;
V_138 -> V_145 . integer . V_142 = V_142 ;
return 0 ;
}
static int F_57 ( struct V_135 * V_136 ,
struct V_146 * V_147 )
{
struct V_7 * V_8 = F_58 ( V_136 ) ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
T_3 V_145 = V_147 -> V_145 . integer . V_145 [ 0 ] ;
if ( V_145 == F_59 ( V_10 ) )
return 0 ;
if ( V_145 )
F_60 ( V_10 ) ;
else
F_61 ( V_10 ) ;
return 1 ;
}
static int F_62 ( struct V_135 * V_136 ,
struct V_146 * V_147 )
{
struct V_7 * V_8 = F_58 ( V_136 ) ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
V_147 -> V_145 . integer . V_145 [ 0 ] = F_59 ( V_10 ) ;
return 0 ;
}
int F_63 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
if ( ! V_10 -> V_148 ) {
F_64 ( V_10 -> V_134 , L_3 ) ;
return 0 ;
}
switch ( V_10 -> V_149 ) {
case 2 :
return F_65 ( V_8 ,
V_150 ,
F_66 ( V_150 ) ) ;
case 3 :
return F_65 ( V_8 ,
V_151 ,
F_66 ( V_151 ) ) ;
default:
break;
}
return - V_42 ;
}
static int F_67 ( struct V_152 * V_153 )
{
struct V_154 * V_26 = F_68 ( & V_153 -> V_134 ) ;
struct V_9 * V_10 ;
const struct V_155 * V_156 ;
int V_157 ;
V_156 = F_69 ( V_158 , & V_153 -> V_134 ) ;
if ( V_156 ) {
struct V_159 * V_160 = V_153 -> V_134 . V_161 ;
int V_19 ;
V_26 = F_70 ( & V_153 -> V_134 ,
sizeof( struct V_154 ) ,
V_162 ) ;
if ( ! V_26 )
return - V_163 ;
memcpy ( V_26 , V_156 -> V_164 , sizeof( * V_26 ) ) ;
if ( ! F_71 ( V_160 , L_4 , & V_19 ) )
V_26 -> V_19 = V_19 ;
} else if ( ! V_26 ) {
F_72 ( & V_153 -> V_134 , L_5 ) ;
return - V_42 ;
}
V_10 = F_70 ( & V_153 -> V_134 , sizeof( struct V_9 ) , V_162 ) ;
if ( ! V_10 )
return - V_163 ;
V_10 -> V_149 = V_153 -> V_149 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_134 = & V_153 -> V_134 ;
F_73 ( V_153 , V_10 ) ;
V_157 = F_74 ( V_153 ) ;
if ( ! V_157 )
return F_75 ( & V_153 -> V_134 , & V_165 ,
& V_166 , 1 ) ;
return V_157 ;
}
static int F_76 ( struct V_152 * V_153 )
{
struct V_9 * V_10 = F_77 ( V_153 ) ;
F_78 ( & V_153 -> V_134 ) ;
if ( V_10 -> V_26 -> V_167 && V_10 -> V_26 -> V_167 -> free )
V_10 -> V_26 -> V_167 -> free ( V_10 -> V_149 ) ;
F_79 ( V_10 ) ;
F_80 ( V_10 -> V_168 ) ;
return 0 ;
}
