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
int V_32 = ( V_2 -> V_12 == V_13 ) ;
int V_33 = V_32 ? V_13 : V_34 ;
int V_35 = V_32 ? V_34 : V_13 ;
if ( V_10 -> V_36 [ V_35 ] )
F_14 ( & V_10 -> V_37 ,
V_10 -> V_36 [ V_35 ] ) ;
else if ( V_10 -> V_36 [ V_33 ] )
F_15 ( & V_10 -> V_37 ) ;
V_10 -> V_36 [ V_33 ] = 0 ;
if ( ! V_8 -> V_29 ) {
F_16 ( V_10 ) ;
V_10 -> V_38 = 0 ;
}
}
static int F_17 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_39 * V_37 = & V_10 -> V_37 ;
int V_32 = ( V_2 -> V_12 == V_13 ) ;
int V_33 = V_32 ? V_13 : V_34 ;
int V_35 = V_32 ? V_34 : V_13 ;
int V_36 = V_10 -> V_36 [ V_35 ] ;
if ( ! V_36 || V_10 -> V_36 [ V_33 ] < V_36 )
V_36 = V_10 -> V_36 [ V_33 ] ;
if ( F_18 ( V_37 ) )
F_14 ( V_37 , V_36 ) ;
else if ( V_36 )
F_19 ( V_37 , V_40 , V_36 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_41 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
int V_28 = 0 , V_42 = ( V_2 -> V_12 == V_13 ) ;
switch ( V_41 ) {
case V_43 :
case V_44 :
case V_45 :
V_10 -> V_29 ++ ;
F_21 ( V_10 , V_42 , ! V_42 ) ;
break;
case V_46 :
case V_47 :
case V_48 :
F_22 ( V_10 , V_42 , ! V_42 ) ;
V_10 -> V_29 -- ;
break;
default:
V_28 = - V_49 ;
}
return V_28 ;
}
static T_1 F_23 (
struct V_1 * V_2 ,
struct V_7 * V_50 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
T_2 V_51 ;
T_1 V_52 ;
if ( V_2 -> V_12 == V_13 )
V_51 = F_24 ( V_10 ) ;
else
V_51 = F_25 ( V_10 ) ;
V_52 = V_51 / V_2 -> V_30 -> V_21 ;
return V_52 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_53 * V_54 = & V_10 -> V_55 ;
struct V_56 * V_57 ;
int V_58 , V_21 , V_59 ;
int V_60 = 0 ;
unsigned int V_61 , div , V_62 , V_63 ;
unsigned int V_19 = V_10 -> V_26 -> V_19 ;
V_57 = F_27 ( V_8 , V_2 ) ;
V_21 = F_28 ( V_15 ) ;
switch ( F_29 ( V_15 ) ) {
case V_64 :
V_58 = 16 ;
break;
case V_65 :
V_58 = 32 ;
break;
default:
return - V_49 ;
}
if ( V_19 ) {
int V_36 ;
if ( V_10 -> V_66 == V_67 ) {
int V_68 , V_69 ;
int V_70 = 0 ;
V_68 = F_30 ( V_15 ) / ( V_58 / 8 ) ;
if ( V_2 -> V_12 == V_13 )
V_69 = V_10 -> V_71 ;
else
V_69 = V_10 -> V_72 ;
V_70 = V_68 / V_69 ;
if ( V_68 % V_69 )
V_70 ++ ;
while ( V_68 % V_70 &&
V_70 < V_68 )
V_70 ++ ;
if ( V_70 == V_68 )
return - V_49 ;
V_60 = V_68 / V_70 ;
} else if ( V_21 > 1 ) {
V_60 = V_21 ;
}
V_36 = ( ( ( ( V_19 - V_60 ) / V_21 ) * 1000 )
/ ( V_15 -> V_73 / V_15 -> V_74 ) ) ;
V_10 -> V_36 [ V_2 -> V_12 ] = V_36 ;
F_1 ( V_2 , V_60 ) ;
}
V_57 -> V_75 = V_60 ;
if ( V_10 -> V_38 ) {
return 0 ;
}
V_54 -> V_76 &= ~ ( V_77 | F_31 ( 0x7f ) | F_32 ( 7 ) ) ;
V_54 -> V_78 &= ~ ( V_77 | F_33 ( 0x7f ) | F_34 ( 7 ) ) ;
V_54 -> V_79 &= ~ ( F_35 ( 0x7f ) | F_36 ( 7 ) ) ;
V_54 -> V_80 &= ~ ( F_37 ( 0x7f ) | F_38 ( 7 ) ) ;
V_61 = V_10 -> V_81 & V_82 ;
V_59 = V_21 ;
if ( V_21 == 2 && ( V_61 == V_83 ||
V_61 == V_84 ) ) {
V_54 -> V_76 |= V_77 ;
V_54 -> V_78 |= V_85 ;
V_59 -- ;
V_54 -> V_76 |= F_31 ( V_59 - 1 ) ;
V_54 -> V_78 |= F_33 ( V_59 - 1 ) ;
}
V_54 -> V_79 |= F_35 ( V_59 - 1 ) ;
V_54 -> V_80 |= F_37 ( V_59 - 1 ) ;
switch ( F_29 ( V_15 ) ) {
case V_64 :
V_54 -> V_76 |= F_32 ( V_86 ) ;
V_54 -> V_79 |= F_36 ( V_86 ) ;
V_54 -> V_78 |= F_34 ( V_86 ) ;
V_54 -> V_80 |= F_38 ( V_86 ) ;
break;
case V_65 :
V_54 -> V_76 |= F_32 ( V_87 ) ;
V_54 -> V_79 |= F_36 ( V_87 ) ;
V_54 -> V_78 |= F_34 ( V_87 ) ;
V_54 -> V_80 |= F_38 ( V_87 ) ;
break;
default:
return - V_49 ;
}
V_63 = V_10 -> V_81 & V_88 ;
if ( V_63 == V_89 ) {
div = V_10 -> V_90 ? V_10 -> V_90 : 1 ;
V_62 = ( V_10 -> V_91 / div ) / F_39 ( V_15 ) ;
if ( V_62 < V_58 * V_21 ) {
F_40 ( V_92 L_1
L_2 , V_93 ) ;
return - V_49 ;
}
} else
V_62 = V_58 * V_21 ;
V_54 -> V_94 &= ~ F_41 ( 0xfff ) ;
V_54 -> V_95 &= ~ F_42 ( 0xff ) ;
switch ( V_61 ) {
case V_83 :
case V_84 :
V_54 -> V_94 |= F_41 ( V_62 - 1 ) ;
V_54 -> V_95 |= F_42 ( ( V_62 >> 1 ) - 1 ) ;
break;
case V_96 :
case V_97 :
V_54 -> V_94 |= F_41 ( V_62 - 1 ) ;
V_54 -> V_95 |= F_42 ( 0 ) ;
break;
}
F_43 ( V_10 , & V_10 -> V_55 ) ;
V_10 -> V_58 = V_58 ;
V_10 -> V_38 = 1 ;
return 0 ;
}
static int F_44 ( struct V_7 * V_8 ,
unsigned int V_81 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_53 * V_54 = & V_10 -> V_55 ;
bool V_98 = false ;
if ( V_10 -> V_38 )
return 0 ;
V_10 -> V_81 = V_81 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_99 |= F_45 ( 3 ) | FREE ;
V_54 -> V_100 |= F_46 ( 3 ) ;
if ( ! V_10 -> V_26 -> V_101 ) {
V_54 -> V_76 |= V_102 ;
V_54 -> V_78 |= V_103 ;
}
if ( V_10 -> V_26 -> V_101 ) {
V_54 -> V_104 = F_47 ( 1 ) | V_105 | V_106 ;
V_54 -> V_107 = V_108 | V_109 | V_110 ;
}
switch ( V_81 & V_82 ) {
case V_83 :
V_54 -> V_76 |= F_48 ( 1 ) ;
V_54 -> V_78 |= F_49 ( 1 ) ;
break;
case V_84 :
V_54 -> V_76 |= F_48 ( 0 ) ;
V_54 -> V_78 |= F_49 ( 0 ) ;
V_54 -> V_100 |= F_50 ( 2 ) ;
V_98 = true ;
break;
case V_96 :
V_54 -> V_76 |= F_48 ( 1 ) ;
V_54 -> V_78 |= F_49 ( 1 ) ;
V_98 = true ;
break;
case V_97 :
V_54 -> V_76 |= F_48 ( 0 ) ;
V_54 -> V_78 |= F_49 ( 0 ) ;
V_98 = true ;
break;
default:
return - V_49 ;
}
switch ( V_81 & V_88 ) {
case V_89 :
V_54 -> V_111 |= V_112 | V_113 |
V_114 | V_115 ;
V_54 -> V_94 |= V_116 ;
break;
case V_117 :
V_54 -> V_94 |= V_116 ;
V_54 -> V_111 |= V_112 | V_113 ;
break;
case V_118 :
break;
default:
return - V_49 ;
}
switch ( V_81 & V_119 ) {
case V_120 :
V_54 -> V_111 |= V_121 | V_122 |
V_123 | V_124 ;
break;
case V_125 :
V_54 -> V_111 |= V_123 | V_124 ;
break;
case V_126 :
V_54 -> V_111 |= V_121 | V_122 ;
break;
case V_127 :
break;
default:
return - V_49 ;
}
if ( V_98 == true )
V_54 -> V_111 ^= V_121 | V_122 ;
return 0 ;
}
static int F_51 ( struct V_7 * V_8 ,
int V_128 , int div )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_53 * V_54 = & V_10 -> V_55 ;
if ( V_128 != V_129 )
return - V_130 ;
V_10 -> V_90 = div ;
V_54 -> V_95 &= ~ F_52 ( 0xff ) ;
V_54 -> V_95 |= F_52 ( div - 1 ) ;
return 0 ;
}
static int F_53 ( struct V_7 * V_8 ,
int V_131 , unsigned int V_132 ,
int V_133 )
{
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_53 * V_54 = & V_10 -> V_55 ;
int V_28 = 0 ;
if ( V_10 -> V_29 ) {
if ( V_132 == V_10 -> V_91 )
return 0 ;
else
return - V_134 ;
}
V_10 -> V_91 = V_132 ;
V_54 -> V_94 &= ~ V_135 ;
V_54 -> V_111 &= ~ V_136 ;
switch ( V_131 ) {
case V_137 :
V_54 -> V_94 |= V_135 ;
break;
case V_138 :
if ( F_54 () ) {
V_28 = - V_49 ;
break;
}
V_28 = F_55 ( V_10 ,
V_139 ) ;
break;
case V_140 :
if ( F_54 () ) {
V_28 = 0 ;
break;
}
V_28 = F_55 ( V_10 ,
V_141 ) ;
break;
case V_142 :
V_54 -> V_94 |= V_135 ;
V_54 -> V_111 |= V_136 ;
V_54 -> V_111 &= ~ V_114 ;
break;
case V_143 :
V_54 -> V_111 |= V_136 ;
V_54 -> V_111 &= ~ V_115 ;
break;
default:
V_28 = - V_130 ;
}
return V_28 ;
}
static int F_56 ( struct V_7 * V_50 )
{
struct V_9 * V_10 = F_2 ( V_50 ) ;
F_57 ( V_10 -> V_144 ) ;
F_58 ( V_50 ,
& V_10 -> V_57 [ V_13 ] ,
& V_10 -> V_57 [ V_34 ] ) ;
return 0 ;
}
static int F_59 ( struct V_7 * V_50 )
{
struct V_9 * V_10 = F_2 ( V_50 ) ;
F_60 ( V_10 -> V_144 ) ;
return 0 ;
}
static int F_61 ( struct V_145 * V_146 ,
struct V_147 * V_148 )
{
struct V_149 * V_150 =
(struct V_149 * ) V_146 -> V_151 ;
int V_152 = V_150 -> V_152 ;
int V_27 = V_150 -> V_27 ;
V_148 -> type = V_153 ;
V_148 -> V_154 = 1 ;
V_148 -> V_155 . integer . V_27 = V_27 ;
V_148 -> V_155 . integer . V_152 = V_152 ;
return 0 ;
}
static int F_62 ( struct V_145 * V_146 ,
struct V_156 * V_157 )
{
struct V_7 * V_8 = F_63 ( V_146 ) ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
T_3 V_155 = V_157 -> V_155 . integer . V_155 [ 0 ] ;
if ( V_155 == F_64 ( V_10 ) )
return 0 ;
if ( V_155 )
F_65 ( V_10 ) ;
else
F_66 ( V_10 ) ;
return 1 ;
}
static int F_67 ( struct V_145 * V_146 ,
struct V_156 * V_157 )
{
struct V_7 * V_8 = F_63 ( V_146 ) ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
V_157 -> V_155 . integer . V_155 [ 0 ] = F_64 ( V_10 ) ;
return 0 ;
}
int F_68 ( struct V_4 * V_5 , int V_158 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
if ( ! V_10 -> V_159 ) {
F_69 ( V_10 -> V_144 , L_3 ) ;
return 0 ;
}
switch ( V_158 ) {
case 2 :
return F_70 ( V_8 ,
V_160 ,
F_71 ( V_160 ) ) ;
case 3 :
return F_70 ( V_8 ,
V_161 ,
F_71 ( V_161 ) ) ;
default:
F_72 ( V_10 -> V_144 , L_4 , V_158 ) ;
break;
}
return - V_49 ;
}
static int F_73 ( struct V_162 * V_163 )
{
struct V_164 * V_26 = F_74 ( & V_163 -> V_144 ) ;
struct V_9 * V_10 ;
const struct V_165 * V_166 ;
int V_167 ;
V_166 = F_75 ( V_168 , & V_163 -> V_144 ) ;
if ( V_166 ) {
struct V_169 * V_170 = V_163 -> V_144 . V_171 ;
struct V_164 * V_172 = V_26 ;
int V_19 ;
V_26 = F_76 ( & V_163 -> V_144 ,
sizeof( struct V_164 ) ,
V_173 ) ;
if ( ! V_26 )
return - V_174 ;
memcpy ( V_26 , V_166 -> V_175 , sizeof( * V_26 ) ) ;
if ( ! F_77 ( V_170 , L_5 , & V_19 ) )
V_26 -> V_19 = V_19 ;
if ( V_172 )
V_26 -> V_176 = V_172 -> V_176 ;
} else if ( ! V_26 ) {
F_72 ( & V_163 -> V_144 , L_6 ) ;
return - V_49 ;
}
V_10 = F_76 ( & V_163 -> V_144 , sizeof( struct V_9 ) , V_173 ) ;
if ( ! V_10 )
return - V_174 ;
V_10 -> V_177 = V_163 -> V_177 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_144 = & V_163 -> V_144 ;
F_78 ( V_163 , V_10 ) ;
V_167 = F_79 ( V_163 ) ;
if ( V_167 )
return V_167 ;
V_167 = F_80 ( & V_163 -> V_144 ,
& V_178 ,
& V_179 , 1 ) ;
if ( V_167 )
return V_167 ;
return F_81 ( & V_163 -> V_144 ) ;
}
static int F_82 ( struct V_162 * V_163 )
{
struct V_9 * V_10 = F_83 ( V_163 ) ;
if ( V_10 -> V_26 -> V_180 && V_10 -> V_26 -> V_180 -> free )
V_10 -> V_26 -> V_180 -> free ( V_10 -> V_177 ) ;
if ( F_18 ( & V_10 -> V_37 ) )
F_15 ( & V_10 -> V_37 ) ;
F_84 ( V_10 ) ;
F_85 ( V_10 -> V_181 ) ;
return 0 ;
}
