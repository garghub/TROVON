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
else
V_12 = 1 ;
if ( V_2 -> V_14 == V_15 )
F_4 ( V_9 , V_12 ) ;
else
F_5 ( V_9 , V_12 ) ;
}
static int F_6 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_7 ( V_17 ,
V_22 ) ;
struct V_20 * V_23 = F_7 ( V_17 ,
V_24 ) ;
struct V_8 * V_9 = V_19 -> V_25 ;
struct V_20 V_26 ;
int V_27 ;
F_8 ( & V_26 ) ;
V_27 = V_9 -> V_28 -> V_21 ;
V_26 . V_29 = V_27 / V_23 -> V_29 ;
V_26 . integer = 1 ;
return F_9 ( V_21 , & V_26 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_30 = 0 ;
if ( ! V_7 -> V_31 )
V_30 = F_11 ( V_9 ) ;
if ( V_9 -> V_28 -> V_21 ) {
if ( V_2 -> V_14 == V_15 )
F_12 ( V_2 -> V_32 , 0 ,
V_22 ,
F_6 ,
V_9 ,
V_24 , - 1 ) ;
F_13 ( V_2 -> V_32 , 0 ,
V_33 , 2 ) ;
}
F_14 ( V_7 , V_2 ,
& V_9 -> V_11 [ V_2 -> V_14 ] ) ;
return V_30 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
if ( ! V_7 -> V_31 ) {
F_16 ( V_9 ) ;
V_9 -> V_34 = 0 ;
}
}
static int F_17 ( struct V_1 * V_2 , int V_35 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_30 = 0 , V_36 = ( V_2 -> V_14 == V_15 ) ;
switch ( V_35 ) {
case V_37 :
case V_38 :
case V_39 :
V_9 -> V_31 ++ ;
F_18 ( V_9 , V_36 , ! V_36 ) ;
break;
case V_40 :
case V_41 :
case V_42 :
F_19 ( V_9 , V_36 , ! V_36 ) ;
V_9 -> V_31 -- ;
break;
default:
V_30 = - V_43 ;
}
return V_30 ;
}
static T_1 F_20 (
struct V_1 * V_2 ,
struct V_6 * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_2 V_45 ;
T_1 V_46 ;
if ( V_2 -> V_14 == V_15 )
V_45 = F_21 ( V_9 ) ;
else
V_45 = F_22 ( V_9 ) ;
V_46 = V_45 / V_2 -> V_32 -> V_23 ;
return V_46 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_47 * V_48 = & V_9 -> V_49 ;
struct V_10 * V_11 ;
int V_50 , V_23 , V_51 ;
int V_52 = 0 ;
unsigned int V_53 , div , V_54 , V_55 ;
V_11 = F_3 ( V_7 , V_2 ) ;
V_23 = F_24 ( V_17 ) ;
switch ( F_25 ( V_17 ) ) {
case V_56 :
V_50 = 16 ;
break;
case V_57 :
V_50 = 32 ;
break;
default:
return - V_43 ;
}
if ( V_9 -> V_28 -> V_21 ) {
V_11 -> V_58 = F_1 ;
if ( V_9 -> V_59 == V_60 ) {
int V_61 , V_62 ;
int V_63 = 0 ;
V_61 = F_26 ( V_17 ) / ( V_50 / 8 ) ;
if ( V_2 -> V_14 == V_15 )
V_62 = V_9 -> V_64 ;
else
V_62 = V_9 -> V_65 ;
V_63 = V_61 / V_62 ;
if ( V_61 % V_62 )
V_63 ++ ;
while ( V_61 % V_63 &&
V_63 < V_61 )
V_63 ++ ;
if ( V_63 == V_61 )
return - V_43 ;
V_52 = V_61 / V_63 ;
} else if ( V_23 > 1 ) {
V_52 = V_23 ;
}
}
V_11 -> V_13 = V_52 ;
if ( V_9 -> V_34 ) {
return 0 ;
}
V_48 -> V_66 &= ~ ( V_67 | F_27 ( 0x7f ) | F_28 ( 7 ) ) ;
V_48 -> V_68 &= ~ ( V_67 | F_29 ( 0x7f ) | F_30 ( 7 ) ) ;
V_48 -> V_69 &= ~ ( F_31 ( 0x7f ) | F_32 ( 7 ) ) ;
V_48 -> V_70 &= ~ ( F_33 ( 0x7f ) | F_34 ( 7 ) ) ;
V_53 = V_9 -> V_71 & V_72 ;
V_51 = V_23 ;
if ( V_23 == 2 && ( V_53 == V_73 ||
V_53 == V_74 ) ) {
V_48 -> V_66 |= V_67 ;
V_48 -> V_68 |= V_75 ;
V_51 -- ;
V_48 -> V_66 |= F_27 ( V_51 - 1 ) ;
V_48 -> V_68 |= F_29 ( V_51 - 1 ) ;
}
V_48 -> V_69 |= F_31 ( V_51 - 1 ) ;
V_48 -> V_70 |= F_33 ( V_51 - 1 ) ;
switch ( F_25 ( V_17 ) ) {
case V_56 :
V_48 -> V_66 |= F_28 ( V_76 ) ;
V_48 -> V_69 |= F_32 ( V_76 ) ;
V_48 -> V_68 |= F_30 ( V_76 ) ;
V_48 -> V_70 |= F_34 ( V_76 ) ;
break;
case V_57 :
V_48 -> V_66 |= F_28 ( V_77 ) ;
V_48 -> V_69 |= F_32 ( V_77 ) ;
V_48 -> V_68 |= F_30 ( V_77 ) ;
V_48 -> V_70 |= F_34 ( V_77 ) ;
break;
default:
return - V_43 ;
}
V_55 = V_9 -> V_71 & V_78 ;
if ( V_55 == V_79 ) {
div = V_9 -> V_80 ? V_9 -> V_80 : 1 ;
V_54 = ( V_9 -> V_81 / div ) / F_35 ( V_17 ) ;
if ( V_54 < V_50 * V_23 ) {
F_36 ( V_82 L_1
L_2 , V_83 ) ;
return - V_43 ;
}
} else
V_54 = V_50 * V_23 ;
V_48 -> V_84 &= ~ F_37 ( 0xfff ) ;
V_48 -> V_85 &= ~ F_38 ( 0xff ) ;
switch ( V_53 ) {
case V_73 :
case V_74 :
V_48 -> V_84 |= F_37 ( V_54 - 1 ) ;
V_48 -> V_85 |= F_38 ( ( V_54 >> 1 ) - 1 ) ;
break;
case V_86 :
case V_87 :
V_48 -> V_84 |= F_37 ( V_54 - 1 ) ;
V_48 -> V_85 |= F_38 ( 0 ) ;
break;
}
F_39 ( V_9 , & V_9 -> V_49 ) ;
V_9 -> V_50 = V_50 ;
V_9 -> V_34 = 1 ;
return 0 ;
}
static int F_40 ( struct V_6 * V_7 ,
unsigned int V_71 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_47 * V_48 = & V_9 -> V_49 ;
bool V_88 = false ;
if ( V_9 -> V_34 )
return 0 ;
V_9 -> V_71 = V_71 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_89 |= F_41 ( 3 ) | FREE ;
V_48 -> V_90 |= F_42 ( 3 ) ;
if ( ! V_9 -> V_28 -> V_91 ) {
V_48 -> V_66 |= V_92 ;
V_48 -> V_68 |= V_93 ;
}
if ( V_9 -> V_28 -> V_91 ) {
V_48 -> V_94 = F_43 ( 1 ) | V_95 | V_96 ;
V_48 -> V_97 = V_98 | V_99 | V_100 ;
}
switch ( V_71 & V_72 ) {
case V_73 :
V_48 -> V_66 |= F_44 ( 1 ) ;
V_48 -> V_68 |= F_45 ( 1 ) ;
break;
case V_74 :
V_48 -> V_66 |= F_44 ( 0 ) ;
V_48 -> V_68 |= F_45 ( 0 ) ;
V_48 -> V_90 |= F_46 ( 2 ) ;
V_88 = true ;
break;
case V_86 :
V_48 -> V_66 |= F_44 ( 1 ) ;
V_48 -> V_68 |= F_45 ( 1 ) ;
V_88 = true ;
break;
case V_87 :
V_48 -> V_66 |= F_44 ( 0 ) ;
V_48 -> V_68 |= F_45 ( 0 ) ;
V_88 = true ;
break;
default:
return - V_43 ;
}
switch ( V_71 & V_78 ) {
case V_79 :
V_48 -> V_101 |= V_102 | V_103 |
V_104 | V_105 ;
V_48 -> V_84 |= V_106 ;
break;
case V_107 :
break;
default:
return - V_43 ;
}
switch ( V_71 & V_108 ) {
case V_109 :
V_48 -> V_101 |= V_110 | V_111 |
V_112 | V_113 ;
break;
case V_114 :
V_48 -> V_101 |= V_112 | V_113 ;
break;
case V_115 :
V_48 -> V_101 |= V_110 | V_111 ;
break;
case V_116 :
break;
default:
return - V_43 ;
}
if ( V_88 == true )
V_48 -> V_101 ^= V_110 | V_111 ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 ,
int V_117 , int div )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_47 * V_48 = & V_9 -> V_49 ;
if ( V_117 != V_118 )
return - V_119 ;
V_9 -> V_80 = div ;
V_48 -> V_85 &= ~ F_48 ( 0xff ) ;
V_48 -> V_85 |= F_48 ( div - 1 ) ;
return 0 ;
}
static int F_49 ( struct V_6 * V_7 ,
int V_120 , unsigned int V_121 ,
int V_122 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_47 * V_48 = & V_9 -> V_49 ;
int V_30 = 0 ;
if ( V_9 -> V_31 ) {
if ( V_121 == V_9 -> V_81 )
return 0 ;
else
return - V_123 ;
}
V_9 -> V_81 = V_121 ;
V_48 -> V_84 &= ~ V_124 ;
V_48 -> V_101 &= ~ V_125 ;
switch ( V_120 ) {
case V_126 :
V_48 -> V_84 |= V_124 ;
break;
case V_127 :
if ( F_50 () ) {
V_30 = - V_43 ;
break;
}
V_30 = F_51 ( V_9 ,
V_128 ) ;
break;
case V_129 :
if ( F_50 () ) {
V_30 = 0 ;
break;
}
V_30 = F_51 ( V_9 ,
V_130 ) ;
break;
case V_131 :
V_48 -> V_84 |= V_124 ;
case V_132 :
V_48 -> V_101 |= V_125 ;
break;
default:
V_30 = - V_119 ;
}
return V_30 ;
}
static int F_52 ( struct V_6 * V_44 )
{
struct V_8 * V_9 = F_2 ( V_44 ) ;
F_53 ( V_9 -> V_133 ) ;
return 0 ;
}
static int F_54 ( struct V_6 * V_44 )
{
struct V_8 * V_9 = F_2 ( V_44 ) ;
F_55 ( V_9 -> V_133 ) ;
return 0 ;
}
static int F_56 ( struct V_134 * V_135 ,
struct V_136 * V_137 )
{
struct V_138 * V_139 =
(struct V_138 * ) V_135 -> V_140 ;
int V_141 = V_139 -> V_141 ;
int V_29 = V_139 -> V_29 ;
V_137 -> type = V_142 ;
V_137 -> V_143 = 1 ;
V_137 -> V_144 . integer . V_29 = V_29 ;
V_137 -> V_144 . integer . V_141 = V_141 ;
return 0 ;
}
static int F_57 ( struct V_134 * V_135 ,
struct V_145 * V_146 )
{
struct V_6 * V_7 = F_58 ( V_135 ) ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_3 V_144 = V_146 -> V_144 . integer . V_144 [ 0 ] ;
if ( V_144 == F_59 ( V_9 ) )
return 0 ;
if ( V_144 )
F_60 ( V_9 ) ;
else
F_61 ( V_9 ) ;
return 1 ;
}
static int F_62 ( struct V_134 * V_135 ,
struct V_145 * V_146 )
{
struct V_6 * V_7 = F_58 ( V_135 ) ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_146 -> V_144 . integer . V_144 [ 0 ] = F_59 ( V_9 ) ;
return 0 ;
}
int F_63 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
if ( ! V_9 -> V_147 ) {
F_64 ( V_9 -> V_133 , L_3 ) ;
return 0 ;
}
switch ( V_9 -> V_148 ) {
case 2 :
return F_65 ( V_7 ,
V_149 ,
F_66 ( V_149 ) ) ;
case 3 :
return F_65 ( V_7 ,
V_150 ,
F_66 ( V_150 ) ) ;
default:
break;
}
return - V_43 ;
}
static int F_67 ( struct V_151 * V_152 )
{
struct V_153 * V_28 = F_68 ( & V_152 -> V_133 ) ;
struct V_8 * V_9 ;
const struct V_154 * V_155 ;
int V_156 ;
V_155 = F_69 ( V_157 , & V_152 -> V_133 ) ;
if ( V_155 ) {
struct V_158 * V_159 = V_152 -> V_133 . V_160 ;
int V_21 ;
V_28 = F_70 ( & V_152 -> V_133 ,
sizeof( struct V_153 ) ,
V_161 ) ;
if ( ! V_28 )
return - V_162 ;
memcpy ( V_28 , V_155 -> V_163 , sizeof( * V_28 ) ) ;
if ( ! F_71 ( V_159 , L_4 , & V_21 ) )
V_28 -> V_21 = V_21 ;
} else if ( ! V_28 ) {
F_72 ( & V_152 -> V_133 , L_5 ) ;
return - V_43 ;
}
V_9 = F_70 ( & V_152 -> V_133 , sizeof( struct V_8 ) , V_161 ) ;
if ( ! V_9 )
return - V_162 ;
V_9 -> V_148 = V_152 -> V_148 ;
V_9 -> V_28 = V_28 ;
V_9 -> V_133 = & V_152 -> V_133 ;
F_73 ( V_152 , V_9 ) ;
V_156 = F_74 ( V_152 ) ;
if ( ! V_156 )
return F_75 ( & V_152 -> V_133 , & V_164 ) ;
return V_156 ;
}
static int F_76 ( struct V_151 * V_152 )
{
struct V_8 * V_9 = F_77 ( V_152 ) ;
F_78 ( & V_152 -> V_133 ) ;
if ( V_9 -> V_28 -> V_165 && V_9 -> V_28 -> V_165 -> free )
V_9 -> V_28 -> V_165 -> free ( V_9 -> V_148 ) ;
F_79 ( V_9 ) ;
F_80 ( V_9 -> V_166 ) ;
F_73 ( V_152 , NULL ) ;
return 0 ;
}
