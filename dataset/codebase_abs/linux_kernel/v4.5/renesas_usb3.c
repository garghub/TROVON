static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_4 )
{
T_1 V_7 = F_3 ( V_2 , V_4 ) ;
V_7 |= V_6 ;
F_1 ( V_2 , V_7 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_4 )
{
T_1 V_7 = F_3 ( V_2 , V_4 ) ;
V_7 &= ~ V_6 ;
F_1 ( V_2 , V_7 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_8 ,
T_1 V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( ( F_3 ( V_2 , V_5 ) & V_8 ) == V_9 )
return 0 ;
F_8 ( 1 ) ;
}
F_9 ( F_10 ( V_2 ) , L_1 ,
V_12 , V_5 , V_8 , V_9 ) ;
return - V_13 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_6 )
{
F_5 ( V_2 , V_6 , V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_6 )
{
F_6 ( V_2 , V_6 , V_14 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_15 )
{
F_5 ( V_2 , F_14 ( V_15 ) , V_16 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_15 )
{
F_6 ( V_2 , F_14 ( V_15 ) , V_16 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_1 ( V_2 , ~ 0 , V_17 ) ;
F_1 ( V_2 , 0 , V_18 ) ;
F_5 ( V_2 , V_19 | V_20 , V_21 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_22 , V_23 ) ;
F_1 ( V_2 , ~ 0 , V_24 ) ;
F_11 ( V_2 , V_25 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
if ( ! ( F_3 ( V_2 , V_26 ) & V_27 ) )
return true ;
F_6 ( V_2 , V_27 , V_26 ) ;
F_11 ( V_2 , V_28 ) ;
return false ;
}
static void F_19 ( struct V_1 * V_2 , int V_29 )
{
T_1 V_6 = V_30 | V_31 ;
if ( V_2 -> V_32 && V_29 )
F_5 ( V_2 , V_6 , V_26 ) ;
else
F_6 ( V_2 , V_6 , V_26 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_7 = F_3 ( V_2 , V_26 ) ;
V_7 &= ~ V_33 ;
V_7 |= F_21 ( V_2 -> V_34 ) ;
F_1 ( V_2 , V_7 | V_35 , V_26 ) ;
if ( ! V_2 -> V_34 )
F_6 ( V_2 , V_35 , V_26 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_36 ++ ;
F_5 ( V_2 , V_37 , V_38 ) ;
F_5 ( V_2 , V_39 , V_38 ) ;
F_19 ( V_2 , 1 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_40 ) & V_41 ;
}
static bool F_24 ( struct V_1 * V_2 )
{
if ( ! F_23 ( V_2 ) )
return true ;
F_5 ( V_2 , V_42 , V_40 ) ;
F_11 ( V_2 , V_43 ) ;
return false ;
}
static T_2 F_25 ( struct V_1 * V_2 )
{
T_1 V_44 = V_45 | V_46 ;
T_1 V_47 = V_48 | V_49 ;
T_1 V_7 = F_3 ( V_2 , V_50 ) ;
T_2 V_51 = 0 ;
if ( ! ( V_7 & V_44 ) )
V_51 |= 1 << V_52 ;
if ( ! ( V_7 & V_47 ) )
V_51 |= 1 << V_53 ;
return V_51 ;
}
static void F_26 ( struct V_1 * V_2 , bool V_54 )
{
T_1 V_6 = V_45 | V_46 ;
if ( V_54 )
F_6 ( V_2 , V_6 , V_50 ) ;
else
F_5 ( V_2 , V_6 , V_50 ) ;
}
static void F_27 ( struct V_1 * V_2 , bool V_54 )
{
T_1 V_6 = V_48 | V_49 ;
if ( V_54 )
F_6 ( V_2 , V_6 , V_50 ) ;
else
F_5 ( V_2 , V_6 , V_50 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_37 , V_38 ) ;
F_6 ( V_2 , V_39 , V_38 ) ;
F_5 ( V_2 , V_55 , V_40 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
F_5 ( V_2 , V_56 , V_38 ) ;
F_11 ( V_2 , V_57 | V_58 |
V_59 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_55 , V_40 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
bool V_60 )
{
F_5 ( V_2 , F_14 ( 0 ) , V_16 ) ;
F_1 ( V_2 , V_61 , V_62 ) ;
F_5 ( V_2 , V_61 , V_63 ) ;
if ( V_60 )
F_11 ( V_2 , V_64 |
V_65 ) ;
else
F_11 ( V_2 , V_66 |
V_67 | V_68 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
F_29 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_69 , V_38 ) ;
F_6 ( V_2 , V_37 , V_38 ) ;
F_5 ( V_2 , V_70 , V_38 ) ;
V_2 -> V_34 = 0 ;
F_20 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_36 = 0 ;
F_19 ( V_2 , 0 ) ;
F_6 ( V_2 , V_55 , V_40 ) ;
F_33 ( V_2 ) ;
if ( V_2 -> V_71 )
V_2 -> V_71 -> V_72 ( & V_2 -> V_73 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 ) {
F_32 ( V_2 ) ;
} else {
if ( F_3 ( V_2 , V_75 ) & V_76 )
F_32 ( V_2 ) ;
else
F_34 ( V_2 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
F_35 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
F_1 ( V_2 , 0 , V_63 ) ;
F_1 ( V_2 , 0 , V_77 ) ;
F_1 ( V_2 , 0 , V_14 ) ;
F_1 ( V_2 , 0 , V_16 ) ;
F_1 ( V_2 , 0 , V_21 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_43 ) ;
F_6 ( V_2 , V_42 , V_40 ) ;
F_29 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_31 ( V_2 , true ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_28 ) ;
F_22 ( V_2 ) ;
F_31 ( V_2 , false ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
if ( F_18 ( V_2 ) )
F_40 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
if ( V_2 -> V_36 < 3 )
F_29 ( V_2 ) ;
else
F_22 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_35 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_5 ( V_2 , V_37 , V_38 ) ;
F_5 ( V_2 , V_78 , V_40 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_5 ( V_2 , V_37 , V_38 ) ;
F_28 ( V_2 ) ;
F_11 ( V_2 , V_59 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_79 = F_3 ( V_2 , V_75 ) & V_80 ;
switch ( V_79 ) {
case V_81 :
V_2 -> V_73 . V_79 = V_82 ;
break;
case V_83 :
V_2 -> V_73 . V_79 = V_84 ;
break;
case V_85 :
V_2 -> V_73 . V_79 = V_86 ;
break;
default:
V_2 -> V_73 . V_79 = V_87 ;
break;
}
}
static void F_47 ( struct V_1 * V_2 , T_1 V_88 )
{
if ( V_88 & V_43 )
F_38 ( V_2 ) ;
if ( V_88 & V_57 )
F_39 ( V_2 ) ;
if ( V_88 & V_65 )
F_44 ( V_2 ) ;
if ( V_88 & V_64 )
F_45 ( V_2 ) ;
if ( V_88 & V_58 )
F_41 ( V_2 ) ;
if ( V_88 & V_68 )
F_42 ( V_2 ) ;
if ( V_88 & V_28 )
F_40 ( V_2 ) ;
if ( V_88 & V_59 )
F_46 ( V_2 ) ;
if ( V_88 & V_25 )
F_43 ( V_2 ) ;
}
static struct V_89 * F_48 ( struct V_90
* V_91 )
{
return F_49 ( & V_91 -> V_92 ,
struct V_89 , V_92 ) ;
}
static struct V_89 * F_50 ( struct V_90
* V_91 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
struct V_89 * V_93 ;
unsigned long V_94 ;
F_52 ( & V_2 -> V_95 , V_94 ) ;
V_93 = F_48 ( V_91 ) ;
F_53 ( & V_2 -> V_95 , V_94 ) ;
return V_93 ;
}
static void F_54 ( struct V_90 * V_91 ,
struct V_89 * V_93 , int V_96 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
unsigned long V_94 ;
F_9 ( F_10 ( V_2 ) , L_2 ,
V_91 -> V_15 , V_93 -> V_97 . V_98 , V_93 -> V_97 . V_99 ,
V_96 ) ;
V_93 -> V_97 . V_96 = V_96 ;
F_52 ( & V_2 -> V_95 , V_94 ) ;
V_91 -> V_100 = false ;
F_55 ( & V_93 -> V_92 ) ;
F_53 ( & V_2 -> V_95 , V_94 ) ;
F_56 ( & V_91 -> V_101 , & V_93 -> V_97 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = F_58 ( V_2 , 0 ) ;
struct V_89 * V_93 = F_50 ( V_91 ) ;
if ( V_93 )
F_54 ( V_91 , V_93 , 0 ) ;
if ( V_2 -> V_34 )
F_20 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_90 * V_91 = F_58 ( V_2 , 0 ) ;
T_1 * V_3 = ( T_1 * ) V_103 ;
* V_3 ++ = F_3 ( V_2 , V_104 ) ;
* V_3 = F_3 ( V_2 , V_105 ) ;
V_91 -> V_106 = ! ! ( V_103 -> V_107 & V_108 ) ;
}
static void F_60 ( struct V_1 * V_2 , T_1 V_109 )
{
T_1 V_7 = F_3 ( V_2 , V_110 ) ;
V_7 &= ~ ( V_111 | V_112 | V_113 ) ;
V_7 |= V_109 | V_114 ;
F_1 ( V_2 , V_7 , V_110 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_115 |
V_116 |
V_117 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_118 |
V_116 |
V_117 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_115 |
V_119 |
V_120 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_118 |
V_119 |
V_120 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_118 |
V_116 |
V_120 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_121 |
V_116 |
V_120 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_115 |
V_122 |
V_123 ) ;
}
static int F_68 ( struct V_1 * V_2 , int V_15 )
{
if ( V_15 == 0 || V_15 > V_2 -> V_124 )
return - V_125 ;
F_1 ( V_2 , V_15 , V_126 ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 , T_1 V_109 )
{
T_1 V_7 = F_3 ( V_2 , V_127 ) ;
V_7 &= ~ V_128 ;
V_7 |= V_109 & V_128 ;
V_7 |= V_129 ;
F_1 ( V_2 , V_7 , V_127 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_69 ( V_2 , V_130 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_69 ( V_2 , V_131 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_69 ( V_2 , V_132 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_133 , V_127 ) ;
return F_7 ( V_2 , V_127 , V_133 , 0 ) ;
}
static bool F_74 ( struct V_90 * V_91 ,
struct V_89 * V_93 )
{
struct V_134 * V_97 = & V_93 -> V_97 ;
if ( ( ! V_97 -> V_135 && V_97 -> V_99 == V_97 -> V_98 ) ||
( V_97 -> V_99 % V_91 -> V_101 . V_136 ) || ( V_97 -> V_98 == 0 ) )
return true ;
else
return false ;
}
static int F_75 ( struct V_90 * V_91 , T_1 V_8 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
T_1 V_137 = V_91 -> V_15 ? V_138 : V_139 ;
return F_7 ( V_2 , V_137 , V_8 , V_8 ) ;
}
static void F_76 ( struct V_90 * V_91 , int V_140 ,
bool V_141 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
T_1 V_142 = V_91 -> V_15 ? V_127 : V_110 ;
T_1 V_7 = F_3 ( V_2 , V_142 ) ;
V_7 |= V_143 | F_77 ( V_140 ) ;
V_7 |= ( V_91 -> V_15 && V_141 ) ? V_144 : 0 ;
F_1 ( V_2 , V_7 , V_142 ) ;
}
static int F_78 ( struct V_90 * V_91 ,
struct V_89 * V_93 ,
T_1 V_145 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
int V_10 ;
int V_146 = F_79 ( unsigned , V_93 -> V_97 . V_98 - V_93 -> V_97 . V_99 ,
V_91 -> V_101 . V_136 ) ;
T_3 * V_147 = V_93 -> V_97 . V_147 + V_93 -> V_97 . V_99 ;
T_1 V_148 = 0 ;
bool V_149 ;
if ( F_75 ( V_91 , V_150 ) < 0 )
return - V_13 ;
V_93 -> V_97 . V_99 += V_146 ;
if ( V_146 >= 4 ) {
F_80 ( V_2 -> V_5 + V_145 , V_147 , V_146 / 4 ) ;
V_147 += ( V_146 / 4 ) * 4 ;
V_146 %= 4 ;
}
if ( V_146 ) {
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ )
V_148 |= V_147 [ V_10 ] << ( 8 * V_10 ) ;
F_1 ( V_2 , V_148 , V_145 ) ;
}
V_149 = F_74 ( V_91 , V_93 ) ;
F_76 ( V_91 , V_146 , V_149 ) ;
return V_149 ? 0 : - V_151 ;
}
static T_1 F_81 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
T_1 V_152 = V_91 -> V_15 ? V_153 : V_154 ;
return F_3 ( V_2 , V_152 ) ;
}
static int F_82 ( struct V_90 * V_91 ,
struct V_89 * V_93 , T_1 V_145 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
int V_10 ;
int V_146 = F_79 ( unsigned , V_93 -> V_97 . V_98 - V_93 -> V_97 . V_99 ,
F_81 ( V_91 ) ) ;
T_3 * V_147 = V_93 -> V_97 . V_147 + V_93 -> V_97 . V_99 ;
T_1 V_148 = 0 ;
if ( ! V_146 )
return 0 ;
V_93 -> V_97 . V_99 += V_146 ;
if ( V_146 >= 4 ) {
F_83 ( V_2 -> V_5 + V_145 , V_147 , V_146 / 4 ) ;
V_147 += ( V_146 / 4 ) * 4 ;
V_146 %= 4 ;
}
if ( V_146 ) {
V_148 = F_3 ( V_2 , V_145 ) ;
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ )
V_147 [ V_10 ] = ( V_148 >> ( 8 * V_10 ) ) & 0xff ;
}
return F_74 ( V_91 , V_93 ) ? 0 : - V_151 ;
}
static void F_84 ( struct V_90 * V_91 ,
struct V_89 * V_93 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
if ( V_91 -> V_106 ) {
F_62 ( V_2 ) ;
} else {
if ( ! V_93 -> V_97 . V_98 )
F_65 ( V_2 ) ;
else
F_64 ( V_2 ) ;
}
}
static void F_85 ( struct V_90 * V_91 ,
struct V_89 * V_93 )
{
int V_51 = - V_151 ;
if ( V_91 -> V_106 )
V_51 = F_78 ( V_91 , V_93 , V_155 ) ;
else
V_51 = F_82 ( V_91 , V_93 , V_156 ) ;
if ( ! V_51 )
F_84 ( V_91 , V_93 ) ;
}
static void F_86 ( struct V_90 * V_91 ,
struct V_89 * V_93 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
if ( V_91 -> V_100 )
return;
V_91 -> V_100 = true ;
if ( V_91 -> V_106 ) {
F_5 ( V_2 , V_157 , V_158 ) ;
F_61 ( V_2 ) ;
} else {
F_6 ( V_2 , V_157 , V_158 ) ;
F_63 ( V_2 ) ;
}
F_85 ( V_91 , V_93 ) ;
}
static void F_87 ( struct V_90 * V_91 ,
struct V_89 * V_93 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
struct V_89 * V_159 = F_50 ( V_91 ) ;
unsigned long V_94 ;
int V_51 = - V_151 ;
T_1 V_160 = 0 ;
if ( V_91 -> V_161 || V_91 -> V_100 )
return;
if ( V_93 != V_159 )
return;
F_52 ( & V_2 -> V_95 , V_94 ) ;
if ( F_68 ( V_2 , V_91 -> V_15 ) < 0 )
goto V_162;
V_91 -> V_100 = true ;
F_70 ( V_2 ) ;
if ( V_91 -> V_106 ) {
V_51 = F_78 ( V_91 , V_93 , V_163 ) ;
V_160 |= V_164 ;
}
if ( V_51 < 0 )
V_160 |= V_165 ;
if ( V_160 ) {
F_5 ( V_2 , V_160 , V_77 ) ;
F_13 ( V_2 , V_91 -> V_15 ) ;
}
V_162:
F_53 ( & V_2 -> V_95 , V_94 ) ;
}
static int F_88 ( struct V_166 * V_167 , struct V_134 * V_168 ,
T_4 V_169 )
{
struct V_90 * V_91 = F_89 ( V_167 ) ;
struct V_89 * V_93 = F_90 ( V_168 ) ;
struct V_1 * V_2 = F_51 ( V_91 ) ;
unsigned long V_94 ;
F_9 ( F_10 ( V_2 ) , L_3 , V_91 -> V_15 ,
V_168 -> V_98 ) ;
V_168 -> V_96 = - V_170 ;
V_168 -> V_99 = 0 ;
F_52 ( & V_2 -> V_95 , V_94 ) ;
F_91 ( & V_93 -> V_92 , & V_91 -> V_92 ) ;
F_53 ( & V_2 -> V_95 , V_94 ) ;
if ( ! V_91 -> V_15 )
F_86 ( V_91 , V_93 ) ;
else
F_87 ( V_91 , V_93 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 , T_2 V_171 )
{
F_5 ( V_2 , F_93 ( V_171 ) , V_38 ) ;
}
static bool F_94 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
if ( V_103 -> V_172 >= 128 )
return true ;
F_92 ( V_2 , V_103 -> V_172 ) ;
F_65 ( V_2 ) ;
return false ;
}
static void F_95 ( struct V_1 * V_2 ,
void * V_173 , T_5 V_146 ,
void (* F_96)( struct V_166 * V_101 ,
struct V_134 * V_97 ) )
{
struct V_90 * V_91 = F_58 ( V_2 , 0 ) ;
if ( V_173 )
memcpy ( V_2 -> V_174 , V_173 ,
F_79 ( T_5 , V_146 , V_175 ) ) ;
V_2 -> V_176 -> V_147 = & V_2 -> V_174 ;
V_2 -> V_176 -> V_98 = V_146 ;
V_2 -> V_176 -> F_96 = F_96 ;
F_88 ( & V_91 -> V_101 , V_2 -> V_176 , V_177 ) ;
}
static void F_97 ( struct V_166 * V_101 ,
struct V_134 * V_97 )
{
}
static bool F_98 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
bool V_178 = false ;
struct V_90 * V_91 ;
int V_15 ;
T_2 V_96 = 0 ;
switch ( V_103 -> V_107 & V_179 ) {
case V_180 :
if ( V_2 -> V_73 . V_181 )
V_96 |= 1 << V_182 ;
if ( V_2 -> V_73 . V_79 == V_82 )
V_96 |= F_25 ( V_2 ) ;
break;
case V_183 :
break;
case V_184 :
V_15 = F_99 ( V_103 -> V_185 ) & V_186 ;
V_91 = F_58 ( V_2 , V_15 ) ;
if ( V_91 -> V_161 )
V_96 |= 1 << V_187 ;
break;
default:
V_178 = true ;
break;
}
if ( ! V_178 ) {
V_96 = F_100 ( V_96 ) ;
F_9 ( F_10 ( V_2 ) , L_4 ,
F_90 ( V_2 -> V_176 ) ) ;
F_95 ( V_2 , & V_96 , sizeof( V_96 ) ,
F_97 ) ;
}
return V_178 ;
}
static bool F_101 ( struct V_1 * V_2 ,
struct V_102 * V_103 , bool V_188 )
{
bool V_178 = true ;
T_2 V_189 = F_99 ( V_103 -> V_172 ) ;
switch ( V_189 ) {
case V_190 :
if ( ! V_188 )
break;
V_2 -> V_34 = F_99 ( V_103 -> V_185 ) >> 8 ;
V_178 = false ;
break;
case V_191 :
case V_192 :
if ( V_2 -> V_73 . V_79 != V_82 )
break;
if ( V_189 == V_191 )
F_27 ( V_2 , V_188 ) ;
if ( V_189 == V_192 )
F_26 ( V_2 , V_188 ) ;
V_178 = false ;
break;
default:
break;
}
return V_178 ;
}
static int F_102 ( struct V_90 * V_91 , bool V_161 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
if ( F_103 ( V_91 -> V_15 ) )
return - V_193 ;
V_91 -> V_161 = V_161 ;
if ( V_161 )
F_66 ( V_2 ) ;
else
F_67 ( V_2 ) ;
return 0 ;
}
static int F_104 ( struct V_90 * V_91 , bool V_161 ,
bool V_194 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
unsigned long V_94 ;
F_52 ( & V_2 -> V_95 , V_94 ) ;
if ( ! F_68 ( V_2 , V_91 -> V_15 ) ) {
V_91 -> V_161 = V_161 ;
if ( V_161 ) {
F_72 ( V_2 ) ;
} else if ( ! V_194 || ! V_91 -> V_195 ) {
F_73 ( V_2 ) ;
F_5 ( V_2 , V_196 , V_127 ) ;
F_71 ( V_2 ) ;
}
}
F_53 ( & V_2 -> V_95 , V_94 ) ;
return 0 ;
}
static int F_105 ( struct V_90 * V_91 , bool V_161 ,
bool V_194 )
{
int V_51 = 0 ;
if ( V_161 && V_91 -> V_100 )
return - V_151 ;
if ( V_91 -> V_15 )
V_51 = F_104 ( V_91 , V_161 , V_194 ) ;
else
V_51 = F_102 ( V_91 , V_161 ) ;
return V_51 ;
}
static bool F_106 ( struct V_1 * V_2 ,
struct V_102 * V_103 ,
bool V_188 )
{
int V_15 = F_99 ( V_103 -> V_185 ) & V_186 ;
struct V_90 * V_91 ;
struct V_89 * V_93 ;
if ( F_99 ( V_103 -> V_172 ) != V_187 )
return true ;
V_91 = F_58 ( V_2 , V_15 ) ;
F_105 ( V_91 , V_188 , true ) ;
if ( ! V_188 ) {
V_91 -> V_100 = false ;
V_93 = F_50 ( V_91 ) ;
if ( V_93 )
F_87 ( V_91 , V_93 ) ;
}
return false ;
}
static bool F_107 ( struct V_1 * V_2 ,
struct V_102 * V_103 , bool V_188 )
{
bool V_178 = false ;
switch ( V_103 -> V_107 & V_179 ) {
case V_180 :
V_178 = F_101 ( V_2 , V_103 , V_188 ) ;
break;
case V_183 :
break;
case V_184 :
V_178 = F_106 ( V_2 , V_103 , V_188 ) ;
break;
default:
V_178 = true ;
break;
}
if ( ! V_178 )
F_65 ( V_2 ) ;
return V_178 ;
}
static void F_108 ( struct V_166 * V_101 ,
struct V_134 * V_97 )
{
}
static bool F_109 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
T_2 V_197 = F_99 ( V_103 -> V_198 ) ;
if ( V_197 != 6 )
return true ;
F_9 ( F_10 ( V_2 ) , L_5 ,
F_90 ( V_2 -> V_176 ) ) ;
F_95 ( V_2 , NULL , 6 , F_108 ) ;
return false ;
}
static bool F_110 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
if ( V_103 -> V_172 > 0 )
F_5 ( V_2 , V_69 , V_38 ) ;
else
F_6 ( V_2 , V_69 , V_38 ) ;
return false ;
}
static bool F_111 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
bool V_51 = false ;
bool V_178 = false ;
if ( ( V_103 -> V_107 & V_199 ) == V_200 ) {
switch ( V_103 -> V_201 ) {
case V_202 :
V_178 = F_94 ( V_2 , V_103 ) ;
V_51 = true ;
break;
case V_203 :
V_178 = F_98 ( V_2 , V_103 ) ;
V_51 = true ;
break;
case V_204 :
V_178 = F_107 ( V_2 , V_103 , false ) ;
V_51 = true ;
break;
case V_205 :
V_178 = F_107 ( V_2 , V_103 , true ) ;
V_51 = true ;
break;
case V_206 :
V_178 = F_109 ( V_2 , V_103 ) ;
V_51 = true ;
break;
case V_207 :
V_178 = true ;
V_51 = true ;
break;
case V_208 :
F_110 ( V_2 , V_103 ) ;
break;
default:
break;
}
}
if ( V_178 )
F_66 ( V_2 ) ;
return V_51 ;
}
static int F_112 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_209 , V_110 ) ;
return F_7 ( V_2 , V_110 , V_209 , 0 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_102 V_103 ;
struct V_90 * V_91 = F_58 ( V_2 , 0 ) ;
if ( V_91 -> V_100 )
F_54 ( V_91 , F_50 ( V_91 ) ,
- V_210 ) ;
F_112 ( V_2 ) ;
F_59 ( V_2 , & V_103 ) ;
if ( ! F_111 ( V_2 , & V_103 ) )
if ( V_2 -> V_71 -> V_211 ( & V_2 -> V_73 , & V_103 ) < 0 )
F_66 ( V_2 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = F_58 ( V_2 , 0 ) ;
struct V_89 * V_93 = F_50 ( V_91 ) ;
if ( ! V_93 )
return;
F_85 ( V_91 , V_93 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
T_1 V_212 = F_3 ( V_2 , V_62 ) ;
V_212 &= F_3 ( V_2 , V_63 ) ;
F_1 ( V_2 , V_212 , V_62 ) ;
if ( V_212 & V_213 )
F_57 ( V_2 ) ;
if ( V_212 & V_214 )
F_113 ( V_2 ) ;
if ( V_212 & V_215 )
F_114 ( V_2 ) ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_90 * V_91 ,
struct V_89 * V_93 ,
int V_96 )
{
F_71 ( V_2 ) ;
F_15 ( V_2 , V_91 -> V_15 ) ;
F_54 ( V_91 , V_93 , V_96 ) ;
V_93 = F_50 ( V_91 ) ;
if ( V_93 )
F_87 ( V_91 , V_93 ) ;
}
static void F_117 ( struct V_1 * V_2 , int V_15 )
{
struct V_90 * V_91 = F_58 ( V_2 , V_15 ) ;
struct V_89 * V_93 = F_50 ( V_91 ) ;
if ( ! V_93 )
return;
if ( V_91 -> V_106 ) {
F_9 ( F_10 ( V_2 ) , L_6 ,
V_12 , V_93 -> V_97 . V_98 , V_93 -> V_97 . V_99 ) ;
F_116 ( V_2 , V_91 , V_93 , 0 ) ;
}
}
static void F_118 ( struct V_1 * V_2 , int V_15 )
{
struct V_90 * V_91 = F_58 ( V_2 , V_15 ) ;
struct V_89 * V_93 = F_50 ( V_91 ) ;
if ( ! V_93 )
return;
if ( V_91 -> V_106 ) {
if ( ! F_78 ( V_91 , V_93 , V_163 ) )
F_6 ( V_2 , V_165 , V_77 ) ;
} else {
if ( ! F_82 ( V_91 , V_93 , V_216 ) )
F_116 ( V_2 , V_91 , V_93 , 0 ) ;
}
}
static void F_119 ( struct V_1 * V_2 , int V_15 )
{
T_1 V_217 ;
if ( F_68 ( V_2 , V_15 ) < 0 )
return;
V_217 = F_3 ( V_2 , V_218 ) ;
V_217 &= F_3 ( V_2 , V_77 ) ;
F_1 ( V_2 , V_217 , V_218 ) ;
if ( V_217 & V_164 )
F_117 ( V_2 , V_15 ) ;
if ( V_217 & V_165 )
F_118 ( V_2 , V_15 ) ;
}
static void F_120 ( struct V_1 * V_2 , T_1 V_219 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_124 ; V_10 ++ ) {
if ( V_219 & F_14 ( V_10 ) ) {
if ( ! V_10 )
F_115 ( V_2 ) ;
else
F_119 ( V_2 , V_10 ) ;
}
}
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_88 = F_3 ( V_2 , V_24 ) ;
T_1 V_219 = F_3 ( V_2 , V_220 ) ;
V_88 &= F_3 ( V_2 , V_14 ) ;
if ( V_88 ) {
F_1 ( V_2 , V_88 , V_24 ) ;
F_47 ( V_2 , V_88 ) ;
}
V_219 &= F_3 ( V_2 , V_16 ) ;
if ( V_219 )
F_120 ( V_2 , V_219 ) ;
}
static T_6 F_122 ( int V_221 , void * V_222 )
{
struct V_1 * V_2 = V_222 ;
T_6 V_51 = V_223 ;
T_1 V_224 = F_3 ( V_2 , V_225 ) ;
if ( V_224 & V_20 ) {
F_121 ( V_2 ) ;
V_51 = V_226 ;
}
return V_51 ;
}
static void F_123 ( struct V_90 * V_91 ,
const struct V_227 * V_228 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
T_1 V_7 = 0 ;
V_7 |= V_91 -> V_106 ? V_229 : 0 ;
V_7 |= F_124 ( F_125 ( V_228 ) ) ;
V_7 |= F_126 ( F_127 ( V_228 ) ) ;
F_1 ( V_2 , V_7 , V_230 ) ;
}
static T_1 F_128 ( int V_231 )
{
F_129 ( V_231 > V_232 ) ;
if ( V_231 <= V_233 )
return V_234 ;
else if ( V_231 <= V_235 )
return V_236 ;
else if ( V_231 <= V_237 )
return V_238 ;
else if ( V_231 <= V_239 )
return V_240 ;
else
return V_241 ;
}
static T_1 F_130 ( struct V_90 * V_91 ,
const struct V_227 * V_228 )
{
return V_91 -> V_242 | F_131 ( F_132 ( V_228 ) ) ;
}
static int F_133 ( struct V_90 * V_91 ,
const struct V_227 * V_228 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
unsigned long V_94 ;
V_91 -> V_106 = F_134 ( V_228 ) ;
F_52 ( & V_2 -> V_95 , V_94 ) ;
if ( ! F_68 ( V_2 , V_91 -> V_15 ) ) {
F_123 ( V_91 , V_228 ) ;
F_1 ( V_2 , F_130 ( V_91 , V_228 ) ,
V_243 ) ;
F_73 ( V_2 ) ;
F_5 ( V_2 , V_196 , V_127 ) ;
}
F_53 ( & V_2 -> V_95 , V_94 ) ;
return 0 ;
}
static int F_135 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_51 ( V_91 ) ;
unsigned long V_94 ;
V_91 -> V_161 = false ;
F_52 ( & V_2 -> V_95 , V_94 ) ;
if ( ! F_68 ( V_2 , V_91 -> V_15 ) ) {
F_1 ( V_2 , 0 , V_243 ) ;
F_6 ( V_2 , V_196 , V_127 ) ;
}
F_53 ( & V_2 -> V_95 , V_94 ) ;
return 0 ;
}
static int F_136 ( struct V_166 * V_167 ,
const struct V_227 * V_228 )
{
struct V_90 * V_91 = F_89 ( V_167 ) ;
return F_133 ( V_91 , V_228 ) ;
}
static int F_137 ( struct V_166 * V_167 )
{
struct V_90 * V_91 = F_89 ( V_167 ) ;
struct V_89 * V_93 ;
do {
V_93 = F_50 ( V_91 ) ;
if ( ! V_93 )
break;
F_54 ( V_91 , V_93 , - V_244 ) ;
} while ( 1 );
return F_135 ( V_91 ) ;
}
static struct V_134 * F_138 ( T_4 V_169 )
{
struct V_89 * V_93 ;
V_93 = F_139 ( sizeof( struct V_89 ) , V_169 ) ;
if ( ! V_93 )
return NULL ;
F_140 ( & V_93 -> V_92 ) ;
return & V_93 -> V_97 ;
}
static void F_141 ( struct V_134 * V_168 )
{
struct V_89 * V_93 = F_90 ( V_168 ) ;
F_142 ( V_93 ) ;
}
static struct V_134 * F_143 ( struct V_166 * V_167 ,
T_4 V_169 )
{
return F_138 ( V_169 ) ;
}
static void F_144 ( struct V_166 * V_167 ,
struct V_134 * V_168 )
{
F_141 ( V_168 ) ;
}
static int F_145 ( struct V_166 * V_167 , struct V_134 * V_168 )
{
struct V_90 * V_91 = F_89 ( V_167 ) ;
struct V_89 * V_93 = F_90 ( V_168 ) ;
struct V_1 * V_2 = F_51 ( V_91 ) ;
F_9 ( F_10 ( V_2 ) , L_7 , V_91 -> V_15 ,
V_168 -> V_98 ) ;
F_116 ( V_2 , V_91 , V_93 , - V_210 ) ;
return 0 ;
}
static int F_146 ( struct V_166 * V_167 , int V_245 )
{
return F_105 ( F_89 ( V_167 ) , ! ! V_245 , false ) ;
}
static int F_147 ( struct V_166 * V_167 )
{
struct V_90 * V_91 = F_89 ( V_167 ) ;
V_91 -> V_195 = true ;
return F_105 ( V_91 , true , false ) ;
}
static void F_148 ( struct V_166 * V_167 )
{
struct V_90 * V_91 = F_89 ( V_167 ) ;
struct V_1 * V_2 = F_51 ( V_91 ) ;
unsigned long V_94 ;
if ( V_91 -> V_15 ) {
F_52 ( & V_2 -> V_95 , V_94 ) ;
if ( ! F_68 ( V_2 , V_91 -> V_15 ) ) {
F_73 ( V_2 ) ;
F_5 ( V_2 , V_196 , V_127 ) ;
}
F_53 ( & V_2 -> V_95 , V_94 ) ;
} else {
F_112 ( V_2 ) ;
}
}
static int F_149 ( struct V_246 * V_73 ,
struct V_247 * V_71 )
{
struct V_1 * V_2 ;
if ( ! V_71 || V_71 -> V_248 < V_86 ||
! V_71 -> V_211 )
return - V_193 ;
V_2 = F_150 ( V_73 ) ;
V_2 -> V_71 = V_71 ;
F_36 ( V_2 ) ;
return 0 ;
}
static int F_151 ( struct V_246 * V_73 )
{
struct V_1 * V_2 = F_150 ( V_73 ) ;
unsigned long V_94 ;
F_52 ( & V_2 -> V_95 , V_94 ) ;
V_2 -> V_32 = false ;
V_2 -> V_73 . V_79 = V_87 ;
V_2 -> V_71 = NULL ;
F_37 ( V_2 ) ;
F_53 ( & V_2 -> V_95 , V_94 ) ;
return 0 ;
}
static int F_152 ( struct V_246 * V_249 )
{
return - V_250 ;
}
static int F_153 ( struct V_246 * V_73 , int V_251 )
{
struct V_1 * V_2 = F_150 ( V_73 ) ;
V_2 -> V_32 = ! ! V_251 ;
return 0 ;
}
static int F_154 ( struct V_246 * V_73 , int V_252 )
{
V_73 -> V_181 = ! ! V_252 ;
return 0 ;
}
static int F_155 ( struct V_253 * V_254 )
{
struct V_1 * V_2 = F_156 ( V_254 ) ;
F_157 ( & V_254 -> V_255 ) ;
F_158 ( & V_254 -> V_255 ) ;
F_159 ( & V_2 -> V_73 ) ;
F_141 ( V_2 -> V_176 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 , struct V_256 * V_255 ,
const struct V_257 * V_258 )
{
struct V_90 * V_91 ;
int V_10 ;
V_2 -> V_124 = V_258 -> V_259 * V_258 -> V_260 * 2 /
V_258 -> V_261 + 1 ;
if ( V_2 -> V_124 > V_262 )
V_2 -> V_124 = V_262 ;
V_2 -> V_91 = F_161 ( V_255 , sizeof( * V_91 ) * V_2 -> V_124 ,
V_263 ) ;
if ( ! V_2 -> V_91 )
return - V_264 ;
F_9 ( V_255 , L_8 , V_12 , V_2 -> V_124 ) ;
F_162 (usb3_ep, usb3, i) {
snprintf ( V_91 -> V_265 , sizeof( V_91 -> V_265 ) , L_9 , V_10 ) ;
V_91 -> V_2 = V_2 ;
V_91 -> V_15 = V_10 ;
V_91 -> V_101 . V_266 = V_91 -> V_265 ;
V_91 -> V_101 . V_267 = & V_268 ;
F_140 ( & V_91 -> V_92 ) ;
F_140 ( & V_91 -> V_101 . V_269 ) ;
if ( ! V_10 ) {
V_2 -> V_73 . V_270 = & V_91 -> V_101 ;
F_163 ( & V_91 -> V_101 ,
V_271 ) ;
V_91 -> V_101 . V_272 . V_273 = true ;
V_91 -> V_101 . V_272 . V_106 = true ;
V_91 -> V_101 . V_272 . V_274 = true ;
continue;
}
F_163 ( & V_91 -> V_101 , ~ 0 ) ;
F_91 ( & V_91 -> V_101 . V_269 , & V_2 -> V_73 . V_269 ) ;
V_91 -> V_101 . V_272 . V_275 = true ;
V_91 -> V_101 . V_272 . V_276 = true ;
if ( V_10 & 1 )
V_91 -> V_101 . V_272 . V_106 = true ;
else
V_91 -> V_101 . V_272 . V_274 = true ;
}
return 0 ;
}
static void F_164 ( struct V_1 * V_2 , struct V_256 * V_255 ,
const struct V_257 * V_258 )
{
struct V_90 * V_91 ;
int V_10 ;
T_1 V_277 [ 2 ] , V_278 [ 2 ] ;
T_1 * V_279 , * V_280 ;
T_1 V_7 ;
memset ( V_277 , 0 , sizeof( V_277 ) ) ;
memset ( V_278 , 0 , sizeof( V_278 ) ) ;
F_162 (usb3_ep, usb3, i) {
if ( ! V_10 )
continue;
if ( V_91 -> V_101 . V_272 . V_106 ) {
V_279 = & V_277 [ 0 ] ;
V_280 = & V_278 [ 0 ] ;
} else {
V_279 = & V_277 [ 1 ] ;
V_280 = & V_278 [ 1 ] ;
}
if ( * V_280 > V_258 -> V_259 )
continue;
V_7 = F_165 ( * V_279 ) ;
V_7 |= F_128 ( V_258 -> V_261 ) ;
V_7 |= F_166 ( * V_280 ) ;
V_91 -> V_242 = V_7 ;
F_9 ( V_255 , L_10 ,
V_10 , V_7 , * V_279 , * V_280 ) ;
if ( * V_279 + 1 == V_258 -> V_260 ) {
* V_279 = 0 ;
* V_280 += V_258 -> V_261 ;
} else {
( * V_279 ) ++ ;
}
}
}
static int F_167 ( struct V_253 * V_254 )
{
struct V_1 * V_2 ;
struct V_281 * V_109 ;
const struct V_282 * V_283 ;
int V_221 , V_51 ;
const struct V_257 * V_258 ;
V_283 = F_168 ( V_284 , V_254 -> V_255 . V_285 ) ;
if ( ! V_283 )
return - V_286 ;
V_258 = V_283 -> V_3 ;
V_221 = F_169 ( V_254 , 0 ) ;
if ( V_221 < 0 )
return - V_286 ;
V_2 = F_161 ( & V_254 -> V_255 , sizeof( * V_2 ) , V_263 ) ;
if ( ! V_2 )
return - V_264 ;
V_109 = F_170 ( V_254 , V_287 , 0 ) ;
V_2 -> V_5 = F_171 ( & V_254 -> V_255 , V_109 ) ;
if ( F_172 ( V_2 -> V_5 ) )
return F_173 ( V_2 -> V_5 ) ;
F_174 ( V_254 , V_2 ) ;
F_175 ( & V_2 -> V_95 ) ;
V_2 -> V_73 . V_267 = & V_288 ;
V_2 -> V_73 . V_266 = V_289 ;
V_2 -> V_73 . V_248 = V_82 ;
F_140 ( & V_2 -> V_73 . V_269 ) ;
V_51 = F_160 ( V_2 , & V_254 -> V_255 , V_258 ) ;
if ( V_51 < 0 )
return V_51 ;
F_164 ( V_2 , & V_254 -> V_255 , V_258 ) ;
V_51 = F_176 ( & V_254 -> V_255 , V_221 , F_122 , 0 ,
F_177 ( & V_254 -> V_255 ) , V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
V_2 -> V_176 = F_138 ( V_263 ) ;
if ( ! V_2 -> V_176 )
return - V_264 ;
V_51 = F_178 ( & V_254 -> V_255 , & V_2 -> V_73 ) ;
if ( V_51 < 0 )
goto V_290;
V_2 -> V_74 = V_258 -> V_74 ;
F_179 ( & V_254 -> V_255 ) ;
F_180 ( & V_254 -> V_255 ) ;
F_181 ( & V_254 -> V_255 , L_11 ) ;
return 0 ;
V_290:
F_141 ( V_2 -> V_176 ) ;
return V_51 ;
}
