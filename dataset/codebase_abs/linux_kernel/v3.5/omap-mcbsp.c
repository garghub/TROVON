static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_10 * V_11 ;
int V_12 ;
V_11 = F_3 ( V_4 -> V_7 , V_2 ) ;
if ( V_11 -> V_13 )
V_12 = V_11 -> V_13 ;
else if ( V_9 -> V_14 == V_15 )
V_12 = F_4 ( V_2 ) /
( V_9 -> V_16 / 8 ) ;
else
V_12 = 1 ;
if ( V_2 -> V_17 == V_18 )
F_5 ( V_9 , V_12 ) ;
else
F_6 ( V_9 , V_12 ) ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_8 ( V_20 ,
V_25 ) ;
struct V_23 * V_26 = F_8 ( V_20 ,
V_27 ) ;
struct V_8 * V_9 = V_22 -> V_28 ;
struct V_23 V_29 ;
int V_30 ;
F_9 ( & V_29 ) ;
V_30 = V_9 -> V_31 -> V_24 ;
V_29 . V_32 = V_30 / V_26 -> V_32 ;
V_29 . integer = 1 ;
return F_10 ( V_24 , & V_29 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_33 = 0 ;
if ( ! V_7 -> V_34 )
V_33 = F_12 ( V_9 ) ;
if ( V_9 -> V_31 -> V_24 ) {
if ( V_2 -> V_17 == V_18 )
F_13 ( V_2 -> V_35 , 0 ,
V_25 ,
F_7 ,
V_9 ,
V_27 , - 1 ) ;
F_14 ( V_2 -> V_35 , 0 ,
V_36 , 2 ) ;
}
return V_33 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
if ( ! V_7 -> V_34 ) {
F_16 ( V_9 ) ;
V_9 -> V_37 = 0 ;
}
}
static int F_17 ( struct V_1 * V_2 , int V_38 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_33 = 0 , V_39 = ( V_2 -> V_17 == V_18 ) ;
switch ( V_38 ) {
case V_40 :
case V_41 :
case V_42 :
V_9 -> V_34 ++ ;
F_18 ( V_9 , V_39 , ! V_39 ) ;
break;
case V_43 :
case V_44 :
case V_45 :
F_19 ( V_9 , V_39 , ! V_39 ) ;
V_9 -> V_34 -- ;
break;
default:
V_33 = - V_46 ;
}
return V_33 ;
}
static T_1 F_20 (
struct V_1 * V_2 ,
struct V_6 * V_47 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_2 V_48 ;
T_1 V_49 ;
if ( V_2 -> V_17 == V_18 )
V_48 = F_21 ( V_9 ) ;
else
V_48 = F_22 ( V_9 ) ;
V_49 = V_48 / V_2 -> V_35 -> V_26 ;
return V_49 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_50 * V_51 = & V_9 -> V_52 ;
struct V_10 * V_11 ;
int V_16 , V_26 , V_53 , V_54 = V_55 ;
int V_56 = 0 ;
unsigned int V_57 , div , V_58 , V_59 ;
V_11 = & V_9 -> V_11 [ V_2 -> V_17 ] ;
V_26 = F_24 ( V_20 ) ;
switch ( F_25 ( V_20 ) ) {
case V_60 :
V_11 -> V_61 = V_62 ;
V_16 = 16 ;
break;
case V_63 :
V_11 -> V_61 = V_64 ;
V_16 = 32 ;
break;
default:
return - V_46 ;
}
if ( V_9 -> V_31 -> V_24 ) {
V_11 -> V_65 = F_1 ;
if ( V_9 -> V_14 == V_15 ) {
int V_66 , V_67 ;
V_66 = F_26 ( V_20 ) / ( V_16 / 8 ) ;
if ( V_2 -> V_17 == V_18 )
V_67 = V_9 -> V_68 ;
else
V_67 = V_9 -> V_69 ;
if ( V_66 > V_67 ) {
int V_70 = 0 ;
V_70 = V_66 / V_67 ;
if ( V_66 % V_67 )
V_70 ++ ;
while ( V_66 % V_70 &&
V_70 < V_66 )
V_70 ++ ;
if ( V_70 == V_66 )
return - V_46 ;
V_56 = V_66 / V_70 ;
V_54 = V_71 ;
} else {
V_54 = V_72 ;
}
} else if ( V_26 > 1 ) {
V_56 = V_26 ;
V_54 = V_71 ;
}
}
V_11 -> V_54 = V_54 ;
V_11 -> V_13 = V_56 ;
F_27 ( V_7 , V_2 , V_11 ) ;
if ( V_9 -> V_37 ) {
return 0 ;
}
V_51 -> V_73 &= ~ ( V_74 | F_28 ( 0x7f ) | F_29 ( 7 ) ) ;
V_51 -> V_75 &= ~ ( V_74 | F_30 ( 0x7f ) | F_31 ( 7 ) ) ;
V_51 -> V_76 &= ~ ( F_32 ( 0x7f ) | F_33 ( 7 ) ) ;
V_51 -> V_77 &= ~ ( F_34 ( 0x7f ) | F_35 ( 7 ) ) ;
V_57 = V_9 -> V_78 & V_79 ;
V_53 = V_26 ;
if ( V_26 == 2 && ( V_57 == V_80 ||
V_57 == V_81 ) ) {
V_51 -> V_73 |= V_74 ;
V_51 -> V_75 |= V_82 ;
V_53 -- ;
V_51 -> V_73 |= F_28 ( V_53 - 1 ) ;
V_51 -> V_75 |= F_30 ( V_53 - 1 ) ;
}
V_51 -> V_76 |= F_32 ( V_53 - 1 ) ;
V_51 -> V_77 |= F_34 ( V_53 - 1 ) ;
switch ( F_25 ( V_20 ) ) {
case V_60 :
V_51 -> V_73 |= F_29 ( V_83 ) ;
V_51 -> V_76 |= F_33 ( V_83 ) ;
V_51 -> V_75 |= F_31 ( V_83 ) ;
V_51 -> V_77 |= F_35 ( V_83 ) ;
break;
case V_63 :
V_51 -> V_73 |= F_29 ( V_84 ) ;
V_51 -> V_76 |= F_33 ( V_84 ) ;
V_51 -> V_75 |= F_31 ( V_84 ) ;
V_51 -> V_77 |= F_35 ( V_84 ) ;
break;
default:
return - V_46 ;
}
V_59 = V_9 -> V_78 & V_85 ;
if ( V_59 == V_86 ) {
div = V_9 -> V_87 ? V_9 -> V_87 : 1 ;
V_58 = ( V_9 -> V_88 / div ) / F_36 ( V_20 ) ;
if ( V_58 < V_16 * V_26 ) {
F_37 ( V_89 L_1
L_2 , V_90 ) ;
return - V_46 ;
}
} else
V_58 = V_16 * V_26 ;
V_51 -> V_91 &= ~ F_38 ( 0xfff ) ;
V_51 -> V_92 &= ~ F_39 ( 0xff ) ;
switch ( V_57 ) {
case V_80 :
case V_81 :
V_51 -> V_91 |= F_38 ( V_58 - 1 ) ;
V_51 -> V_92 |= F_39 ( ( V_58 >> 1 ) - 1 ) ;
break;
case V_93 :
case V_94 :
V_51 -> V_91 |= F_38 ( V_58 - 1 ) ;
V_51 -> V_92 |= F_39 ( 0 ) ;
break;
}
F_40 ( V_9 , & V_9 -> V_52 ) ;
V_9 -> V_16 = V_16 ;
V_9 -> V_37 = 1 ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 ,
unsigned int V_78 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_50 * V_51 = & V_9 -> V_52 ;
bool V_95 = false ;
if ( V_9 -> V_37 )
return 0 ;
V_9 -> V_78 = V_78 ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_96 |= F_42 ( 3 ) | FREE ;
V_51 -> V_97 |= F_43 ( 3 ) ;
if ( ! F_44 () && ! F_45 () ) {
V_51 -> V_73 |= V_98 ;
V_51 -> V_75 |= V_99 ;
}
if ( F_46 () || F_44 () || F_45 () ) {
V_51 -> V_100 = F_47 ( 1 ) | V_101 | V_102 ;
V_51 -> V_103 = V_104 | V_105 | V_106 ;
}
switch ( V_78 & V_79 ) {
case V_80 :
V_51 -> V_73 |= F_48 ( 1 ) ;
V_51 -> V_75 |= F_49 ( 1 ) ;
break;
case V_81 :
V_51 -> V_73 |= F_48 ( 0 ) ;
V_51 -> V_75 |= F_49 ( 0 ) ;
V_51 -> V_97 |= F_50 ( 2 ) ;
V_95 = true ;
break;
case V_93 :
V_51 -> V_73 |= F_48 ( 1 ) ;
V_51 -> V_75 |= F_49 ( 1 ) ;
V_95 = true ;
break;
case V_94 :
V_51 -> V_73 |= F_48 ( 0 ) ;
V_51 -> V_75 |= F_49 ( 0 ) ;
V_95 = true ;
break;
default:
return - V_46 ;
}
switch ( V_78 & V_85 ) {
case V_86 :
V_51 -> V_107 |= V_108 | V_109 |
V_110 | V_111 ;
V_51 -> V_91 |= V_112 ;
break;
case V_113 :
break;
default:
return - V_46 ;
}
switch ( V_78 & V_114 ) {
case V_115 :
V_51 -> V_107 |= V_116 | V_117 |
V_118 | V_119 ;
break;
case V_120 :
V_51 -> V_107 |= V_118 | V_119 ;
break;
case V_121 :
V_51 -> V_107 |= V_116 | V_117 ;
break;
case V_122 :
break;
default:
return - V_46 ;
}
if ( V_95 == true )
V_51 -> V_107 ^= V_116 | V_117 ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 ,
int V_123 , int div )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_50 * V_51 = & V_9 -> V_52 ;
if ( V_123 != V_124 )
return - V_125 ;
V_9 -> V_87 = div ;
V_51 -> V_92 &= ~ F_52 ( 0xff ) ;
V_51 -> V_92 |= F_52 ( div - 1 ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 ,
int V_126 , unsigned int V_127 ,
int V_128 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_50 * V_51 = & V_9 -> V_52 ;
int V_33 = 0 ;
if ( V_9 -> V_34 ) {
if ( V_127 == V_9 -> V_88 )
return 0 ;
else
return - V_129 ;
}
if ( V_126 == V_130 ||
V_126 == V_131 ||
V_126 == V_132 ||
V_126 == V_133 ||
V_126 == V_134 ) {
V_9 -> V_88 = V_127 ;
V_51 -> V_91 &= ~ V_135 ;
V_51 -> V_107 &= ~ V_136 ;
} else if ( F_54 () ) {
return - V_46 ;
}
switch ( V_126 ) {
case V_130 :
V_51 -> V_91 |= V_135 ;
break;
case V_131 :
if ( F_54 () ) {
V_33 = - V_46 ;
break;
}
V_33 = F_55 ( V_9 ,
V_137 ) ;
break;
case V_132 :
if ( F_54 () ) {
V_33 = 0 ;
break;
}
V_33 = F_55 ( V_9 ,
V_138 ) ;
break;
case V_133 :
V_51 -> V_91 |= V_135 ;
case V_134 :
V_51 -> V_107 |= V_136 ;
break;
case V_139 :
V_33 = F_56 ( V_9 , V_140 ) ;
break;
case V_141 :
V_33 = F_56 ( V_9 , V_142 ) ;
break;
case V_143 :
V_33 = F_56 ( V_9 , V_144 ) ;
break;
case V_145 :
V_33 = F_56 ( V_9 , V_146 ) ;
break;
default:
V_33 = - V_125 ;
}
return V_33 ;
}
static int F_57 ( struct V_6 * V_47 )
{
struct V_8 * V_9 = F_2 ( V_47 ) ;
F_58 ( V_9 -> V_147 ) ;
return 0 ;
}
static int F_59 ( struct V_6 * V_47 )
{
struct V_8 * V_9 = F_2 ( V_47 ) ;
F_60 ( V_9 -> V_147 ) ;
return 0 ;
}
static int F_61 ( struct V_148 * V_149 ,
struct V_150 * V_151 )
{
struct V_152 * V_153 =
(struct V_152 * ) V_149 -> V_154 ;
int V_155 = V_153 -> V_155 ;
int V_32 = V_153 -> V_32 ;
V_151 -> type = V_156 ;
V_151 -> V_157 = 1 ;
V_151 -> V_158 . integer . V_32 = V_32 ;
V_151 -> V_158 . integer . V_155 = V_155 ;
return 0 ;
}
static int F_62 ( struct V_148 * V_149 ,
struct V_159 * V_160 )
{
struct V_6 * V_7 = F_63 ( V_149 ) ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_3 V_158 = V_160 -> V_158 . integer . V_158 [ 0 ] ;
if ( V_158 == F_64 ( V_9 ) )
return 0 ;
if ( V_158 )
F_65 ( V_9 ) ;
else
F_66 ( V_9 ) ;
return 1 ;
}
static int F_67 ( struct V_148 * V_149 ,
struct V_159 * V_160 )
{
struct V_6 * V_7 = F_63 ( V_149 ) ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_160 -> V_158 . integer . V_158 [ 0 ] = F_64 ( V_9 ) ;
return 0 ;
}
int F_68 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
if ( ! V_9 -> V_161 )
return - V_125 ;
switch ( V_7 -> V_162 ) {
case 2 :
return F_69 ( V_7 ,
V_163 ,
F_70 ( V_163 ) ) ;
case 3 :
return F_69 ( V_7 ,
V_164 ,
F_70 ( V_164 ) ) ;
default:
break;
}
return - V_46 ;
}
static T_4 int F_71 ( struct V_165 * V_166 )
{
struct V_167 * V_31 = F_72 ( & V_166 -> V_147 ) ;
struct V_8 * V_9 ;
int V_168 ;
if ( ! V_31 ) {
F_73 ( & V_166 -> V_147 , L_3 ) ;
return - V_46 ;
}
V_9 = F_74 ( & V_166 -> V_147 , sizeof( struct V_8 ) , V_169 ) ;
if ( ! V_9 )
return - V_170 ;
V_9 -> V_162 = V_166 -> V_162 ;
V_9 -> V_31 = V_31 ;
V_9 -> V_147 = & V_166 -> V_147 ;
F_75 ( V_166 , V_9 ) ;
V_168 = F_76 ( V_166 ) ;
if ( ! V_168 )
return F_77 ( & V_166 -> V_147 , & V_171 ) ;
return V_168 ;
}
static int T_5 F_78 ( struct V_165 * V_166 )
{
struct V_8 * V_9 = F_79 ( V_166 ) ;
F_80 ( & V_166 -> V_147 ) ;
if ( V_9 -> V_31 -> V_172 && V_9 -> V_31 -> V_172 -> free )
V_9 -> V_31 -> V_172 -> free ( V_9 -> V_162 ) ;
F_81 ( V_9 ) ;
F_82 ( V_9 -> V_173 ) ;
F_75 ( V_166 , NULL ) ;
return 0 ;
}
