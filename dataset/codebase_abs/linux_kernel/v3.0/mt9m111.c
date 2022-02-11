static const struct V_1 * F_1 (
enum V_2 V_3 , const struct V_1 * V_4 ,
int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( V_4 [ V_6 ] . V_3 == V_3 )
return V_4 + V_6 ;
return NULL ;
}
static struct V_7 * F_2 ( const struct V_8 * V_9 )
{
return F_3 ( F_4 ( V_9 ) , struct V_7 , V_10 ) ;
}
static int F_5 ( struct V_8 * V_9 , const T_1 V_11 )
{
int V_12 ;
T_1 V_13 ;
static int V_14 = - 1 ;
V_13 = ( V_11 >> 8 ) ;
if ( V_13 == V_14 )
return 0 ;
if ( V_13 > 2 )
return - V_15 ;
V_12 = F_6 ( V_9 , V_16 , F_7 ( V_13 ) ) ;
if ( ! V_12 )
V_14 = V_13 ;
return V_12 ;
}
static int F_8 ( struct V_8 * V_9 , const T_1 V_11 )
{
int V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( ! V_12 )
V_12 = F_7 ( F_9 ( V_9 , V_11 & 0xff ) ) ;
F_10 ( & V_9 -> V_17 , L_1 , V_11 , V_12 ) ;
return V_12 ;
}
static int F_11 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 )
{
int V_12 ;
V_12 = F_5 ( V_9 , V_11 ) ;
if ( ! V_12 )
V_12 = F_6 ( V_9 , V_11 & 0xff ,
F_7 ( V_18 ) ) ;
F_10 ( & V_9 -> V_17 , L_2 , V_11 , V_18 , V_12 ) ;
return V_12 ;
}
static int F_12 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 )
{
int V_12 ;
V_12 = F_8 ( V_9 , V_11 ) ;
if ( V_12 >= 0 )
V_12 = F_11 ( V_9 , V_11 , V_12 | V_18 ) ;
return V_12 ;
}
static int F_13 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_1 V_18 )
{
int V_12 ;
V_12 = F_8 ( V_9 , V_11 ) ;
return F_11 ( V_9 , V_11 , V_12 & ~ V_18 ) ;
}
static int F_14 ( struct V_8 * V_9 ,
enum V_19 V_20 )
{
int V_21 = V_22 | V_23
| V_24 | V_25
| V_26 | V_27
| V_28
| V_29 ;
int V_30 = V_22 ;
if ( V_20 == V_31 )
return F_15 ( V_32 , V_21 ) ;
else
return F_15 ( V_32 , V_30 ) ;
}
static int F_16 ( struct V_8 * V_9 ,
struct V_33 * V_34 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 , V_35 ;
int V_36 = V_34 -> V_36 ;
int V_37 = V_34 -> V_37 ;
if ( V_7 -> V_4 -> V_3 == V_38 ||
V_7 -> V_4 -> V_3 == V_39 )
V_35 = 1 ;
else
V_35 = 0 ;
V_12 = F_15 ( V_40 , V_34 -> V_41 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_42 , V_34 -> V_43 ) ;
if ( V_35 ) {
if ( ! V_12 )
V_12 = F_15 ( V_44 , V_36 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_45 , V_37 ) ;
} else {
if ( ! V_12 )
V_12 = F_15 ( V_46 , V_47 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_48 , V_49 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_50 , V_36 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_51 , V_37 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_52 , V_47 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_53 , V_49 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_54 , V_36 ) ;
if ( ! V_12 )
V_12 = F_15 ( V_55 , V_37 ) ;
}
return V_12 ;
}
static int F_17 ( struct V_8 * V_9 , T_1 V_56 )
{
int V_12 ;
T_1 V_57 = V_58 | V_59 |
V_60 | V_61 |
V_62 | V_63 |
V_64 |
V_65 ;
V_12 = F_18 ( V_66 ) ;
if ( V_12 >= 0 )
V_12 = F_15 ( V_66 , ( V_12 & ~ V_57 ) | V_56 ) ;
if ( ! V_12 )
V_12 = F_18 ( V_67 ) ;
if ( V_12 >= 0 )
V_12 = F_15 ( V_67 , ( V_12 & ~ V_57 ) | V_56 ) ;
return V_12 ;
}
static int F_19 ( struct V_8 * V_9 )
{
return F_17 ( V_9 , V_58 |
V_59 ) ;
}
static int F_20 ( struct V_8 * V_9 )
{
return F_17 ( V_9 , V_60 ) ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_68 = 0 ;
if ( V_7 -> V_69 )
V_68 |= V_64 ;
if ( V_7 -> V_70 )
V_68 |= V_61 ;
V_68 |= V_59 | V_62 ;
return F_17 ( V_9 , V_68 ) ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_68 = 0 ;
if ( V_7 -> V_69 )
V_68 |= V_64 ;
if ( V_7 -> V_70 )
V_68 |= V_61 ;
V_68 |= V_59 | V_63 ;
return F_17 ( V_9 , V_68 ) ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_68 = 0 ;
if ( V_7 -> V_71 )
V_68 |= V_64 ;
if ( V_7 -> V_72 )
V_68 |= V_65 ;
return F_17 ( V_9 , V_68 ) ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
V_12 = F_25 ( V_73 , V_74 ) ;
if ( ! V_12 )
V_7 -> V_75 = 1 ;
return V_12 ;
}
static int F_26 ( struct V_8 * V_9 )
{
int V_12 ;
V_12 = F_25 ( V_73 , V_76 ) ;
if ( ! V_12 )
V_12 = F_25 ( V_73 , V_77 ) ;
if ( ! V_12 )
V_12 = F_27 ( V_73 , V_76
| V_77 ) ;
return V_12 ;
}
static unsigned long F_28 ( struct V_78 * V_79 )
{
struct V_80 * V_81 = F_29 ( V_79 ) ;
unsigned long V_82 = V_83 | V_84 |
V_85 | V_86 |
V_87 | V_88 ;
return F_30 ( V_81 , V_82 ) ;
}
static int F_31 ( struct V_78 * V_79 , unsigned long V_89 )
{
return 0 ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_33 * V_34 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_7 -> V_4 -> V_3 == V_38 ||
V_7 -> V_4 -> V_3 == V_39 ) {
V_34 -> V_36 = F_33 ( V_34 -> V_36 , 2 ) ;
V_34 -> V_37 = F_33 ( V_34 -> V_37 , 2 ) ;
}
F_34 ( & V_34 -> V_41 , & V_34 -> V_36 ,
V_90 , 2 , V_47 ) ;
F_34 ( & V_34 -> V_43 , & V_34 -> V_37 ,
V_91 , 2 , V_49 ) ;
return F_16 ( V_9 , V_34 ) ;
}
static int F_35 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
struct V_33 V_34 = V_95 -> V_96 ;
struct V_8 * V_9 = F_36 ( V_93 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
F_10 ( & V_9 -> V_17 , L_3 ,
V_97 , V_34 . V_41 , V_34 . V_43 , V_34 . V_36 , V_34 . V_37 ) ;
if ( V_95 -> type != V_98 )
return - V_15 ;
V_12 = F_32 ( V_9 , & V_34 ) ;
if ( ! V_12 )
V_7 -> V_34 = V_34 ;
return V_12 ;
}
static int F_37 ( struct V_92 * V_93 , struct V_94 * V_95 )
{
struct V_8 * V_9 = F_36 ( V_93 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_95 -> V_96 = V_7 -> V_34 ;
V_95 -> type = V_98 ;
return 0 ;
}
static int F_38 ( struct V_92 * V_93 , struct V_99 * V_95 )
{
if ( V_95 -> type != V_98 )
return - V_15 ;
V_95 -> V_100 . V_41 = V_90 ;
V_95 -> V_100 . V_43 = V_91 ;
V_95 -> V_100 . V_36 = V_47 ;
V_95 -> V_100 . V_37 = V_49 ;
V_95 -> V_101 = V_95 -> V_100 ;
V_95 -> V_102 . V_103 = 1 ;
V_95 -> V_102 . V_104 = 1 ;
return 0 ;
}
static int F_39 ( struct V_92 * V_93 ,
struct V_105 * V_106 )
{
struct V_8 * V_9 = F_36 ( V_93 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_106 -> V_36 = V_7 -> V_34 . V_36 ;
V_106 -> V_37 = V_7 -> V_34 . V_37 ;
V_106 -> V_3 = V_7 -> V_4 -> V_3 ;
V_106 -> V_107 = V_7 -> V_4 -> V_107 ;
V_106 -> V_108 = V_109 ;
return 0 ;
}
static int F_40 ( struct V_8 * V_9 ,
enum V_2 V_3 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
switch ( V_3 ) {
case V_38 :
V_12 = F_19 ( V_9 ) ;
break;
case V_39 :
V_12 = F_20 ( V_9 ) ;
break;
case V_110 :
V_12 = F_22 ( V_9 ) ;
break;
case V_111 :
V_12 = F_21 ( V_9 ) ;
break;
case V_112 :
V_7 -> V_72 = 0 ;
V_7 -> V_71 = 0 ;
V_12 = F_23 ( V_9 ) ;
break;
case V_113 :
V_7 -> V_72 = 0 ;
V_7 -> V_71 = 1 ;
V_12 = F_23 ( V_9 ) ;
break;
case V_114 :
V_7 -> V_72 = 1 ;
V_7 -> V_71 = 0 ;
V_12 = F_23 ( V_9 ) ;
break;
case V_115 :
V_7 -> V_72 = 1 ;
V_7 -> V_71 = 1 ;
V_12 = F_23 ( V_9 ) ;
break;
default:
F_41 ( & V_9 -> V_17 , L_4 ,
V_3 ) ;
V_12 = - V_15 ;
}
return V_12 ;
}
static int F_42 ( struct V_92 * V_93 ,
struct V_105 * V_106 )
{
struct V_8 * V_9 = F_36 ( V_93 ) ;
const struct V_1 * V_4 ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_33 V_34 = {
. V_41 = V_7 -> V_34 . V_41 ,
. V_43 = V_7 -> V_34 . V_43 ,
. V_36 = V_106 -> V_36 ,
. V_37 = V_106 -> V_37 ,
} ;
int V_12 ;
V_4 = F_1 ( V_106 -> V_3 , V_116 ,
F_43 ( V_116 ) ) ;
if ( ! V_4 )
return - V_15 ;
F_10 ( & V_9 -> V_17 ,
L_5 , V_97 ,
V_106 -> V_3 , V_34 . V_41 , V_34 . V_43 , V_34 . V_36 , V_34 . V_37 ) ;
V_12 = F_32 ( V_9 , & V_34 ) ;
if ( ! V_12 )
V_12 = F_40 ( V_9 , V_106 -> V_3 ) ;
if ( ! V_12 ) {
V_7 -> V_34 = V_34 ;
V_7 -> V_4 = V_4 ;
V_106 -> V_107 = V_4 -> V_107 ;
}
return V_12 ;
}
static int F_44 ( struct V_92 * V_93 ,
struct V_105 * V_106 )
{
struct V_8 * V_9 = F_36 ( V_93 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
bool V_117 = V_106 -> V_3 == V_38 ||
V_106 -> V_3 == V_39 ;
V_4 = F_1 ( V_106 -> V_3 , V_116 ,
F_43 ( V_116 ) ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_106 -> V_3 = V_4 -> V_3 ;
}
if ( V_106 -> V_37 > V_49 )
V_106 -> V_37 = V_49 ;
else if ( V_106 -> V_37 < 2 )
V_106 -> V_37 = 2 ;
else if ( V_117 )
V_106 -> V_37 = F_33 ( V_106 -> V_37 , 2 ) ;
if ( V_106 -> V_36 > V_47 )
V_106 -> V_36 = V_47 ;
else if ( V_106 -> V_36 < 2 )
V_106 -> V_36 = 2 ;
else if ( V_117 )
V_106 -> V_36 = F_33 ( V_106 -> V_36 , 2 ) ;
V_106 -> V_107 = V_4 -> V_107 ;
return 0 ;
}
static int F_45 ( struct V_92 * V_93 ,
struct V_118 * V_119 )
{
struct V_8 * V_9 = F_36 ( V_93 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_119 -> V_120 . type != V_121 )
return - V_15 ;
if ( V_119 -> V_120 . V_122 != V_9 -> V_122 )
return - V_123 ;
V_119 -> V_124 = V_7 -> V_125 ;
V_119 -> V_126 = 0 ;
return 0 ;
}
static int F_46 ( struct V_92 * V_93 ,
struct V_127 * V_11 )
{
struct V_8 * V_9 = F_36 ( V_93 ) ;
int V_68 ;
if ( V_11 -> V_120 . type != V_121 || V_11 -> V_11 > 0x2ff )
return - V_15 ;
if ( V_11 -> V_120 . V_122 != V_9 -> V_122 )
return - V_123 ;
V_68 = F_8 ( V_9 , V_11 -> V_11 ) ;
V_11 -> V_128 = 2 ;
V_11 -> V_68 = ( V_129 ) V_68 ;
if ( V_11 -> V_68 > 0xffff )
return - V_130 ;
return 0 ;
}
static int F_47 ( struct V_92 * V_93 ,
struct V_127 * V_11 )
{
struct V_8 * V_9 = F_36 ( V_93 ) ;
if ( V_11 -> V_120 . type != V_121 || V_11 -> V_11 > 0x2ff )
return - V_15 ;
if ( V_11 -> V_120 . V_122 != V_9 -> V_122 )
return - V_123 ;
if ( F_11 ( V_9 , V_11 -> V_11 , V_11 -> V_68 ) < 0 )
return - V_130 ;
return 0 ;
}
static int F_48 ( struct V_8 * V_9 , int V_131 , int V_57 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
if ( V_7 -> V_132 == V_31 ) {
if ( V_131 )
V_12 = F_25 ( V_133 , V_57 ) ;
else
V_12 = F_27 ( V_133 , V_57 ) ;
} else {
if ( V_131 )
V_12 = F_25 ( V_134 , V_57 ) ;
else
V_12 = F_27 ( V_134 , V_57 ) ;
}
return V_12 ;
}
static int F_49 ( struct V_8 * V_9 )
{
int V_18 ;
V_18 = F_18 ( V_135 ) ;
if ( V_18 >= 0 )
return ( V_18 & 0x2f ) * ( 1 << ( ( V_18 >> 10 ) & 1 ) ) *
( 1 << ( ( V_18 >> 9 ) & 1 ) ) ;
return V_18 ;
}
static int F_50 ( struct V_8 * V_9 , int V_136 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
T_1 V_68 ;
if ( V_136 > 63 * 2 * 2 )
return - V_15 ;
V_7 -> V_136 = V_136 ;
if ( ( V_136 >= 64 * 2 ) && ( V_136 < 63 * 2 * 2 ) )
V_68 = ( 1 << 10 ) | ( 1 << 9 ) | ( V_136 / 4 ) ;
else if ( ( V_136 >= 64 ) && ( V_136 < 64 * 2 ) )
V_68 = ( 1 << 9 ) | ( V_136 / 2 ) ;
else
V_68 = V_136 ;
return F_15 ( V_135 , V_68 ) ;
}
static int F_51 ( struct V_8 * V_9 , int V_137 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
if ( V_137 )
V_12 = F_25 ( V_138 , V_139 ) ;
else
V_12 = F_27 ( V_138 , V_139 ) ;
if ( ! V_12 )
V_7 -> V_140 = V_137 ;
return V_12 ;
}
static int F_52 ( struct V_8 * V_9 , int V_137 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
if ( V_137 )
V_12 = F_25 ( V_138 , V_141 ) ;
else
V_12 = F_27 ( V_138 , V_141 ) ;
if ( ! V_12 )
V_7 -> V_142 = V_137 ;
return V_12 ;
}
static int F_53 ( struct V_92 * V_93 , struct V_143 * V_144 )
{
struct V_8 * V_9 = F_36 ( V_93 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_18 ;
switch ( V_144 -> V_119 ) {
case V_145 :
if ( V_7 -> V_132 == V_31 )
V_18 = F_18 ( V_133 ) ;
else
V_18 = F_18 ( V_134 ) ;
if ( V_18 < 0 )
return - V_130 ;
V_144 -> V_146 = ! ! ( V_18 & V_147 ) ;
break;
case V_148 :
if ( V_7 -> V_132 == V_31 )
V_18 = F_18 ( V_133 ) ;
else
V_18 = F_18 ( V_134 ) ;
if ( V_18 < 0 )
return - V_130 ;
V_144 -> V_146 = ! ! ( V_18 & V_149 ) ;
break;
case V_150 :
V_18 = F_49 ( V_9 ) ;
if ( V_18 < 0 )
return V_18 ;
V_144 -> V_146 = V_18 ;
break;
case V_151 :
V_144 -> V_146 = V_7 -> V_140 ;
break;
case V_152 :
V_144 -> V_146 = V_7 -> V_142 ;
break;
}
return 0 ;
}
static int F_54 ( struct V_92 * V_93 , struct V_143 * V_144 )
{
struct V_8 * V_9 = F_36 ( V_93 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_153 * V_154 ;
int V_12 ;
V_154 = F_55 ( & V_155 , V_144 -> V_119 ) ;
if ( ! V_154 )
return - V_15 ;
switch ( V_144 -> V_119 ) {
case V_145 :
V_7 -> V_156 = V_144 -> V_146 ;
V_12 = F_48 ( V_9 , V_144 -> V_146 ,
V_147 ) ;
break;
case V_148 :
V_7 -> V_157 = V_144 -> V_146 ;
V_12 = F_48 ( V_9 , V_144 -> V_146 ,
V_149 ) ;
break;
case V_150 :
V_12 = F_50 ( V_9 , V_144 -> V_146 ) ;
break;
case V_151 :
V_12 = F_51 ( V_9 , V_144 -> V_146 ) ;
break;
case V_152 :
V_12 = F_52 ( V_9 , V_144 -> V_146 ) ;
break;
default:
V_12 = - V_15 ;
}
return V_12 ;
}
static int F_56 ( struct V_78 * V_79 , T_2 V_158 )
{
struct V_8 * V_9 = F_57 ( F_58 ( V_79 ) ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_7 -> V_136 = F_49 ( V_9 ) ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
F_14 ( V_9 , V_7 -> V_132 ) ;
F_40 ( V_9 , V_7 -> V_4 -> V_3 ) ;
F_16 ( V_9 , & V_7 -> V_34 ) ;
F_48 ( V_9 , V_7 -> V_157 , V_149 ) ;
F_48 ( V_9 , V_7 -> V_156 , V_147 ) ;
F_50 ( V_9 , V_7 -> V_136 ) ;
F_51 ( V_9 , V_7 -> V_140 ) ;
F_52 ( V_9 , V_7 -> V_142 ) ;
return 0 ;
}
static int F_60 ( struct V_78 * V_79 )
{
struct V_8 * V_9 = F_57 ( F_58 ( V_79 ) ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 = 0 ;
if ( V_7 -> V_75 ) {
V_12 = F_24 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_26 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_59 ( V_9 ) ;
}
return V_12 ;
}
static int F_61 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
V_7 -> V_132 = V_31 ;
V_12 = F_24 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_26 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_14 ( V_9 , V_7 -> V_132 ) ;
if ( ! V_12 )
V_12 = F_51 ( V_9 , V_7 -> V_140 ) ;
if ( V_12 )
F_41 ( & V_9 -> V_17 , L_6 , V_12 ) ;
return V_12 ;
}
static int F_62 ( struct V_78 * V_79 ,
struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
T_3 V_18 ;
int V_12 ;
if ( ! V_79 -> V_17 . V_159 ||
F_63 ( V_79 -> V_17 . V_159 ) -> V_160 != V_79 -> V_161 )
return - V_123 ;
V_7 -> V_140 = 1 ;
V_7 -> V_142 = 1 ;
V_7 -> V_70 = 1 ;
V_7 -> V_69 = 1 ;
V_18 = F_18 ( V_162 ) ;
switch ( V_18 ) {
case 0x143a :
V_7 -> V_125 = V_163 ;
F_64 ( & V_9 -> V_17 ,
L_7 , V_18 ) ;
break;
case 0x148c :
V_7 -> V_125 = V_164 ;
F_64 ( & V_9 -> V_17 , L_8 , V_18 ) ;
break;
default:
V_12 = - V_123 ;
F_41 ( & V_9 -> V_17 ,
L_9 ,
V_18 ) ;
goto V_165;
}
V_12 = F_61 ( V_9 ) ;
V_165:
return V_12 ;
}
static int F_65 ( struct V_92 * V_93 , unsigned int V_166 ,
enum V_2 * V_3 )
{
if ( V_166 >= F_43 ( V_116 ) )
return - V_15 ;
* V_3 = V_116 [ V_166 ] . V_3 ;
return 0 ;
}
static int F_66 ( struct V_8 * V_9 ,
const struct V_167 * V_168 )
{
struct V_7 * V_7 ;
struct V_78 * V_79 = V_9 -> V_17 . V_169 ;
struct V_170 * V_171 = F_67 ( V_9 -> V_17 . V_159 ) ;
struct V_80 * V_81 ;
int V_12 ;
if ( ! V_79 ) {
F_41 ( & V_9 -> V_17 , L_10 ) ;
return - V_15 ;
}
V_81 = F_29 ( V_79 ) ;
if ( ! V_81 ) {
F_41 ( & V_9 -> V_17 , L_11 ) ;
return - V_15 ;
}
if ( ! F_68 ( V_171 , V_172 ) ) {
F_69 ( & V_171 -> V_17 ,
L_12 ) ;
return - V_130 ;
}
V_7 = F_70 ( sizeof( struct V_7 ) , V_173 ) ;
if ( ! V_7 )
return - V_174 ;
F_71 ( & V_7 -> V_10 , V_9 , & V_175 ) ;
V_79 -> V_176 = & V_155 ;
V_7 -> V_34 . V_41 = V_90 ;
V_7 -> V_34 . V_43 = V_91 ;
V_7 -> V_34 . V_36 = V_47 ;
V_7 -> V_34 . V_37 = V_49 ;
V_7 -> V_4 = & V_116 [ 0 ] ;
V_12 = F_62 ( V_79 , V_9 ) ;
if ( V_12 ) {
V_79 -> V_176 = NULL ;
F_72 ( V_7 ) ;
}
return V_12 ;
}
static int F_73 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_78 * V_79 = V_9 -> V_17 . V_169 ;
V_79 -> V_176 = NULL ;
F_72 ( V_7 ) ;
return 0 ;
}
static int T_4 F_74 ( void )
{
return F_75 ( & V_177 ) ;
}
static void T_5 F_76 ( void )
{
F_77 ( & V_177 ) ;
}
