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
F_6 ( V_2 , V_24 , V_23 ) ;
F_1 ( V_2 , ~ 0 , V_25 ) ;
F_11 ( V_2 , V_26 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
if ( ! ( F_3 ( V_2 , V_27 ) & V_28 ) )
return true ;
F_6 ( V_2 , V_28 , V_27 ) ;
F_11 ( V_2 , V_29 ) ;
return false ;
}
static void F_19 ( struct V_1 * V_2 , int V_30 )
{
T_1 V_6 = V_31 | V_32 ;
if ( V_2 -> V_33 && V_30 )
F_5 ( V_2 , V_6 , V_27 ) ;
else
F_6 ( V_2 , V_6 , V_27 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_7 = F_3 ( V_2 , V_27 ) ;
V_7 &= ~ V_34 ;
V_7 |= F_21 ( V_2 -> V_35 ) ;
F_1 ( V_2 , V_7 | V_36 , V_27 ) ;
if ( ! V_2 -> V_35 )
F_6 ( V_2 , V_36 , V_27 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_37 ++ ;
F_5 ( V_2 , V_38 , V_39 ) ;
F_5 ( V_2 , V_40 , V_39 ) ;
F_19 ( V_2 , 1 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_41 ) & V_42 ;
}
static bool F_24 ( struct V_1 * V_2 )
{
if ( ! F_23 ( V_2 ) )
return true ;
F_5 ( V_2 , V_43 , V_41 ) ;
F_11 ( V_2 , V_44 ) ;
return false ;
}
static T_2 F_25 ( struct V_1 * V_2 )
{
T_1 V_45 = V_46 | V_47 ;
T_1 V_48 = V_49 | V_50 ;
T_1 V_7 = F_3 ( V_2 , V_51 ) ;
T_2 V_52 = 0 ;
if ( ! ( V_7 & V_45 ) )
V_52 |= 1 << V_53 ;
if ( ! ( V_7 & V_48 ) )
V_52 |= 1 << V_54 ;
return V_52 ;
}
static void F_26 ( struct V_1 * V_2 , bool V_55 )
{
T_1 V_6 = V_46 | V_47 ;
if ( V_55 )
F_6 ( V_2 , V_6 , V_51 ) ;
else
F_5 ( V_2 , V_6 , V_51 ) ;
}
static void F_27 ( struct V_1 * V_2 , bool V_55 )
{
T_1 V_6 = V_49 | V_50 ;
if ( V_55 )
F_6 ( V_2 , V_6 , V_51 ) ;
else
F_5 ( V_2 , V_6 , V_51 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_38 , V_39 ) ;
F_6 ( V_2 , V_40 , V_39 ) ;
F_5 ( V_2 , V_56 , V_41 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
F_5 ( V_2 , V_57 , V_39 ) ;
F_11 ( V_2 , V_58 | V_59 |
V_60 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_56 , V_41 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
bool V_61 )
{
F_5 ( V_2 , F_14 ( 0 ) , V_16 ) ;
F_1 ( V_2 , V_62 , V_63 ) ;
F_5 ( V_2 , V_62 , V_64 ) ;
if ( V_61 )
F_11 ( V_2 , V_65 |
V_66 ) ;
else
F_11 ( V_2 , V_67 |
V_68 | V_69 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
F_29 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_70 , V_39 ) ;
F_6 ( V_2 , V_38 , V_39 ) ;
F_5 ( V_2 , V_71 , V_39 ) ;
V_2 -> V_35 = 0 ;
F_20 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_37 = 0 ;
F_19 ( V_2 , 0 ) ;
F_6 ( V_2 , V_56 , V_41 ) ;
F_33 ( V_2 ) ;
if ( V_2 -> V_72 )
V_2 -> V_72 -> V_73 ( & V_2 -> V_74 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 ) {
F_32 ( V_2 ) ;
} else {
if ( F_3 ( V_2 , V_76 ) & V_77 )
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
F_1 ( V_2 , 0 , V_64 ) ;
F_1 ( V_2 , 0 , V_78 ) ;
F_1 ( V_2 , 0 , V_14 ) ;
F_1 ( V_2 , 0 , V_16 ) ;
F_1 ( V_2 , 0 , V_21 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_44 ) ;
F_6 ( V_2 , V_43 , V_41 ) ;
F_29 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_31 ( V_2 , true ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_29 ) ;
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
if ( V_2 -> V_37 < 3 )
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
F_5 ( V_2 , V_38 , V_39 ) ;
F_5 ( V_2 , V_79 , V_41 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_5 ( V_2 , V_38 , V_39 ) ;
F_28 ( V_2 ) ;
F_11 ( V_2 , V_60 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
T_1 V_80 = F_3 ( V_2 , V_76 ) & V_81 ;
switch ( V_80 ) {
case V_82 :
V_2 -> V_74 . V_80 = V_83 ;
break;
case V_84 :
V_2 -> V_74 . V_80 = V_85 ;
break;
case V_86 :
V_2 -> V_74 . V_80 = V_87 ;
break;
default:
V_2 -> V_74 . V_80 = V_88 ;
break;
}
}
static void F_47 ( struct V_1 * V_2 , T_1 V_89 )
{
if ( V_89 & V_44 )
F_38 ( V_2 ) ;
if ( V_89 & V_58 )
F_39 ( V_2 ) ;
if ( V_89 & V_66 )
F_44 ( V_2 ) ;
if ( V_89 & V_65 )
F_45 ( V_2 ) ;
if ( V_89 & V_59 )
F_41 ( V_2 ) ;
if ( V_89 & V_69 )
F_42 ( V_2 ) ;
if ( V_89 & V_29 )
F_40 ( V_2 ) ;
if ( V_89 & V_60 )
F_46 ( V_2 ) ;
if ( V_89 & V_26 )
F_43 ( V_2 ) ;
}
static struct V_90 * F_48 ( struct V_91
* V_92 )
{
return F_49 ( & V_92 -> V_93 ,
struct V_90 , V_93 ) ;
}
static struct V_90 * F_50 ( struct V_91
* V_92 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
struct V_90 * V_94 ;
unsigned long V_95 ;
F_52 ( & V_2 -> V_96 , V_95 ) ;
V_94 = F_48 ( V_92 ) ;
F_53 ( & V_2 -> V_96 , V_95 ) ;
return V_94 ;
}
static void F_54 ( struct V_91 * V_92 ,
struct V_90 * V_94 , int V_97 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
unsigned long V_95 ;
F_9 ( F_10 ( V_2 ) , L_2 ,
V_92 -> V_15 , V_94 -> V_98 . V_99 , V_94 -> V_98 . V_100 ,
V_97 ) ;
V_94 -> V_98 . V_97 = V_97 ;
F_52 ( & V_2 -> V_96 , V_95 ) ;
V_92 -> V_101 = false ;
F_55 ( & V_94 -> V_93 ) ;
F_53 ( & V_2 -> V_96 , V_95 ) ;
F_56 ( & V_92 -> V_102 , & V_94 -> V_98 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_91 * V_92 = F_58 ( V_2 , 0 ) ;
struct V_90 * V_94 = F_50 ( V_92 ) ;
if ( V_94 )
F_54 ( V_92 , V_94 , 0 ) ;
if ( V_2 -> V_35 )
F_20 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_91 * V_92 = F_58 ( V_2 , 0 ) ;
T_1 * V_3 = ( T_1 * ) V_104 ;
* V_3 ++ = F_3 ( V_2 , V_105 ) ;
* V_3 = F_3 ( V_2 , V_106 ) ;
V_92 -> V_107 = ! ! ( V_104 -> V_108 & V_109 ) ;
}
static void F_60 ( struct V_1 * V_2 , T_1 V_110 )
{
T_1 V_7 = F_3 ( V_2 , V_111 ) ;
V_7 &= ~ ( V_112 | V_113 | V_114 ) ;
V_7 |= V_110 | V_115 ;
F_1 ( V_2 , V_7 , V_111 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_116 |
V_117 |
V_118 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_119 |
V_117 |
V_118 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_116 |
V_120 |
V_121 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_119 |
V_120 |
V_121 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_119 |
V_117 |
V_121 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_122 |
V_117 |
V_121 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_60 ( V_2 , V_116 |
V_123 |
V_124 ) ;
}
static int F_68 ( struct V_1 * V_2 , int V_15 )
{
if ( V_15 == 0 || V_15 > V_2 -> V_125 )
return - V_126 ;
F_1 ( V_2 , V_15 , V_127 ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 , T_1 V_110 )
{
T_1 V_7 = F_3 ( V_2 , V_128 ) ;
V_7 &= ~ V_129 ;
V_7 |= V_110 & V_129 ;
V_7 |= V_130 ;
F_1 ( V_2 , V_7 , V_128 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_69 ( V_2 , V_131 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_69 ( V_2 , V_132 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_69 ( V_2 , V_133 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_134 , V_128 ) ;
return F_7 ( V_2 , V_128 , V_134 , 0 ) ;
}
static bool F_74 ( struct V_91 * V_92 ,
struct V_90 * V_94 )
{
struct V_135 * V_98 = & V_94 -> V_98 ;
if ( ( ! V_98 -> V_136 && V_98 -> V_100 == V_98 -> V_99 ) ||
( V_98 -> V_100 % V_92 -> V_102 . V_137 ) || ( V_98 -> V_99 == 0 ) )
return true ;
else
return false ;
}
static int F_75 ( struct V_91 * V_92 , T_1 V_8 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
T_1 V_138 = V_92 -> V_15 ? V_139 : V_140 ;
return F_7 ( V_2 , V_138 , V_8 , V_8 ) ;
}
static void F_76 ( struct V_91 * V_92 , int V_141 ,
bool V_142 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
T_1 V_143 = V_92 -> V_15 ? V_128 : V_111 ;
T_1 V_7 = F_3 ( V_2 , V_143 ) ;
V_7 |= V_144 | F_77 ( V_141 ) ;
V_7 |= ( V_92 -> V_15 && V_142 ) ? V_145 : 0 ;
F_1 ( V_2 , V_7 , V_143 ) ;
}
static int F_78 ( struct V_91 * V_92 ,
struct V_90 * V_94 ,
T_1 V_146 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
int V_10 ;
int V_147 = F_79 ( unsigned , V_94 -> V_98 . V_99 - V_94 -> V_98 . V_100 ,
V_92 -> V_102 . V_137 ) ;
T_3 * V_148 = V_94 -> V_98 . V_148 + V_94 -> V_98 . V_100 ;
T_1 V_149 = 0 ;
bool V_150 ;
if ( F_75 ( V_92 , V_151 ) < 0 )
return - V_13 ;
V_94 -> V_98 . V_100 += V_147 ;
if ( V_147 >= 4 ) {
F_80 ( V_2 -> V_5 + V_146 , V_148 , V_147 / 4 ) ;
V_148 += ( V_147 / 4 ) * 4 ;
V_147 %= 4 ;
}
if ( V_147 ) {
for ( V_10 = 0 ; V_10 < V_147 ; V_10 ++ )
V_149 |= V_148 [ V_10 ] << ( 8 * V_10 ) ;
F_1 ( V_2 , V_149 , V_146 ) ;
}
V_150 = F_74 ( V_92 , V_94 ) ;
F_76 ( V_92 , V_147 , V_150 ) ;
return V_150 ? 0 : - V_152 ;
}
static T_1 F_81 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
T_1 V_153 = V_92 -> V_15 ? V_154 : V_155 ;
return F_3 ( V_2 , V_153 ) ;
}
static int F_82 ( struct V_91 * V_92 ,
struct V_90 * V_94 , T_1 V_146 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
int V_10 ;
int V_147 = F_79 ( unsigned , V_94 -> V_98 . V_99 - V_94 -> V_98 . V_100 ,
F_81 ( V_92 ) ) ;
T_3 * V_148 = V_94 -> V_98 . V_148 + V_94 -> V_98 . V_100 ;
T_1 V_149 = 0 ;
if ( ! V_147 )
return 0 ;
V_94 -> V_98 . V_100 += V_147 ;
if ( V_147 >= 4 ) {
F_83 ( V_2 -> V_5 + V_146 , V_148 , V_147 / 4 ) ;
V_148 += ( V_147 / 4 ) * 4 ;
V_147 %= 4 ;
}
if ( V_147 ) {
V_149 = F_3 ( V_2 , V_146 ) ;
for ( V_10 = 0 ; V_10 < V_147 ; V_10 ++ )
V_148 [ V_10 ] = ( V_149 >> ( 8 * V_10 ) ) & 0xff ;
}
return F_74 ( V_92 , V_94 ) ? 0 : - V_152 ;
}
static void F_84 ( struct V_91 * V_92 ,
struct V_90 * V_94 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
if ( V_92 -> V_107 ) {
F_62 ( V_2 ) ;
} else {
if ( ! V_94 -> V_98 . V_99 )
F_65 ( V_2 ) ;
else
F_64 ( V_2 ) ;
}
}
static void F_85 ( struct V_91 * V_92 ,
struct V_90 * V_94 )
{
int V_52 = - V_152 ;
if ( V_92 -> V_107 )
V_52 = F_78 ( V_92 , V_94 , V_156 ) ;
else
V_52 = F_82 ( V_92 , V_94 , V_157 ) ;
if ( ! V_52 )
F_84 ( V_92 , V_94 ) ;
}
static void F_86 ( struct V_91 * V_92 ,
struct V_90 * V_94 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
if ( V_92 -> V_101 )
return;
V_92 -> V_101 = true ;
if ( V_92 -> V_107 ) {
F_5 ( V_2 , V_158 , V_159 ) ;
F_61 ( V_2 ) ;
} else {
F_6 ( V_2 , V_158 , V_159 ) ;
F_63 ( V_2 ) ;
}
F_85 ( V_92 , V_94 ) ;
}
static void F_87 ( struct V_91 * V_92 ,
struct V_90 * V_94 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
struct V_90 * V_160 = F_50 ( V_92 ) ;
unsigned long V_95 ;
int V_52 = - V_152 ;
T_1 V_161 = 0 ;
if ( V_92 -> V_162 || V_92 -> V_101 )
return;
if ( V_94 != V_160 )
return;
F_52 ( & V_2 -> V_96 , V_95 ) ;
if ( F_68 ( V_2 , V_92 -> V_15 ) < 0 )
goto V_163;
V_92 -> V_101 = true ;
F_70 ( V_2 ) ;
if ( V_92 -> V_107 ) {
V_52 = F_78 ( V_92 , V_94 , V_164 ) ;
V_161 |= V_165 ;
}
if ( V_52 < 0 )
V_161 |= V_166 ;
if ( V_161 ) {
F_5 ( V_2 , V_161 , V_78 ) ;
F_13 ( V_2 , V_92 -> V_15 ) ;
}
V_163:
F_53 ( & V_2 -> V_96 , V_95 ) ;
}
static int F_88 ( struct V_167 * V_168 , struct V_135 * V_169 ,
T_4 V_170 )
{
struct V_91 * V_92 = F_89 ( V_168 ) ;
struct V_90 * V_94 = F_90 ( V_169 ) ;
struct V_1 * V_2 = F_51 ( V_92 ) ;
unsigned long V_95 ;
F_9 ( F_10 ( V_2 ) , L_3 , V_92 -> V_15 ,
V_169 -> V_99 ) ;
V_169 -> V_97 = - V_171 ;
V_169 -> V_100 = 0 ;
F_52 ( & V_2 -> V_96 , V_95 ) ;
F_91 ( & V_94 -> V_93 , & V_92 -> V_93 ) ;
F_53 ( & V_2 -> V_96 , V_95 ) ;
if ( ! V_92 -> V_15 )
F_86 ( V_92 , V_94 ) ;
else
F_87 ( V_92 , V_94 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 , T_2 V_172 )
{
F_5 ( V_2 , F_93 ( V_172 ) , V_39 ) ;
}
static bool F_94 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
if ( V_104 -> V_173 >= 128 )
return true ;
F_92 ( V_2 , V_104 -> V_173 ) ;
F_65 ( V_2 ) ;
return false ;
}
static void F_95 ( struct V_1 * V_2 ,
void * V_174 , T_5 V_147 ,
void (* F_96)( struct V_167 * V_102 ,
struct V_135 * V_98 ) )
{
struct V_91 * V_92 = F_58 ( V_2 , 0 ) ;
if ( V_174 )
memcpy ( V_2 -> V_175 , V_174 ,
F_79 ( T_5 , V_147 , V_176 ) ) ;
V_2 -> V_177 -> V_148 = & V_2 -> V_175 ;
V_2 -> V_177 -> V_99 = V_147 ;
V_2 -> V_177 -> F_96 = F_96 ;
F_88 ( & V_92 -> V_102 , V_2 -> V_177 , V_178 ) ;
}
static void F_97 ( struct V_167 * V_102 ,
struct V_135 * V_98 )
{
}
static bool F_98 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
bool V_179 = false ;
struct V_91 * V_92 ;
int V_15 ;
T_2 V_97 = 0 ;
switch ( V_104 -> V_108 & V_180 ) {
case V_181 :
if ( V_2 -> V_74 . V_182 )
V_97 |= 1 << V_183 ;
if ( V_2 -> V_74 . V_80 == V_83 )
V_97 |= F_25 ( V_2 ) ;
break;
case V_184 :
break;
case V_185 :
V_15 = F_99 ( V_104 -> V_186 ) & V_187 ;
V_92 = F_58 ( V_2 , V_15 ) ;
if ( V_92 -> V_162 )
V_97 |= 1 << V_188 ;
break;
default:
V_179 = true ;
break;
}
if ( ! V_179 ) {
V_97 = F_100 ( V_97 ) ;
F_9 ( F_10 ( V_2 ) , L_4 ,
F_90 ( V_2 -> V_177 ) ) ;
F_95 ( V_2 , & V_97 , sizeof( V_97 ) ,
F_97 ) ;
}
return V_179 ;
}
static bool F_101 ( struct V_1 * V_2 ,
struct V_103 * V_104 , bool V_189 )
{
bool V_179 = true ;
T_2 V_190 = F_99 ( V_104 -> V_173 ) ;
switch ( V_190 ) {
case V_191 :
if ( ! V_189 )
break;
V_2 -> V_35 = F_99 ( V_104 -> V_186 ) >> 8 ;
V_179 = false ;
break;
case V_192 :
case V_193 :
if ( V_2 -> V_74 . V_80 != V_83 )
break;
if ( V_190 == V_192 )
F_27 ( V_2 , V_189 ) ;
if ( V_190 == V_193 )
F_26 ( V_2 , V_189 ) ;
V_179 = false ;
break;
default:
break;
}
return V_179 ;
}
static int F_102 ( struct V_91 * V_92 , bool V_162 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
if ( F_103 ( V_92 -> V_15 ) )
return - V_194 ;
V_92 -> V_162 = V_162 ;
if ( V_162 )
F_66 ( V_2 ) ;
else
F_67 ( V_2 ) ;
return 0 ;
}
static int F_104 ( struct V_91 * V_92 , bool V_162 ,
bool V_195 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
unsigned long V_95 ;
F_52 ( & V_2 -> V_96 , V_95 ) ;
if ( ! F_68 ( V_2 , V_92 -> V_15 ) ) {
V_92 -> V_162 = V_162 ;
if ( V_162 ) {
F_72 ( V_2 ) ;
} else if ( ! V_195 || ! V_92 -> V_196 ) {
F_73 ( V_2 ) ;
F_5 ( V_2 , V_197 , V_128 ) ;
F_71 ( V_2 ) ;
}
}
F_53 ( & V_2 -> V_96 , V_95 ) ;
return 0 ;
}
static int F_105 ( struct V_91 * V_92 , bool V_162 ,
bool V_195 )
{
int V_52 = 0 ;
if ( V_162 && V_92 -> V_101 )
return - V_152 ;
if ( V_92 -> V_15 )
V_52 = F_104 ( V_92 , V_162 , V_195 ) ;
else
V_52 = F_102 ( V_92 , V_162 ) ;
return V_52 ;
}
static bool F_106 ( struct V_1 * V_2 ,
struct V_103 * V_104 ,
bool V_189 )
{
int V_15 = F_99 ( V_104 -> V_186 ) & V_187 ;
struct V_91 * V_92 ;
struct V_90 * V_94 ;
if ( F_99 ( V_104 -> V_173 ) != V_188 )
return true ;
V_92 = F_58 ( V_2 , V_15 ) ;
F_105 ( V_92 , V_189 , true ) ;
if ( ! V_189 ) {
V_92 -> V_101 = false ;
V_94 = F_50 ( V_92 ) ;
if ( V_94 )
F_87 ( V_92 , V_94 ) ;
}
return false ;
}
static bool F_107 ( struct V_1 * V_2 ,
struct V_103 * V_104 , bool V_189 )
{
bool V_179 = false ;
switch ( V_104 -> V_108 & V_180 ) {
case V_181 :
V_179 = F_101 ( V_2 , V_104 , V_189 ) ;
break;
case V_184 :
break;
case V_185 :
V_179 = F_106 ( V_2 , V_104 , V_189 ) ;
break;
default:
V_179 = true ;
break;
}
if ( ! V_179 )
F_65 ( V_2 ) ;
return V_179 ;
}
static void F_108 ( struct V_167 * V_102 ,
struct V_135 * V_98 )
{
}
static bool F_109 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
T_2 V_198 = F_99 ( V_104 -> V_199 ) ;
if ( V_198 != 6 )
return true ;
F_9 ( F_10 ( V_2 ) , L_5 ,
F_90 ( V_2 -> V_177 ) ) ;
F_95 ( V_2 , NULL , 6 , F_108 ) ;
return false ;
}
static bool F_110 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
if ( V_104 -> V_173 > 0 )
F_5 ( V_2 , V_70 , V_39 ) ;
else
F_6 ( V_2 , V_70 , V_39 ) ;
return false ;
}
static bool F_111 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
bool V_52 = false ;
bool V_179 = false ;
if ( ( V_104 -> V_108 & V_200 ) == V_201 ) {
switch ( V_104 -> V_202 ) {
case V_203 :
V_179 = F_94 ( V_2 , V_104 ) ;
V_52 = true ;
break;
case V_204 :
V_179 = F_98 ( V_2 , V_104 ) ;
V_52 = true ;
break;
case V_205 :
V_179 = F_107 ( V_2 , V_104 , false ) ;
V_52 = true ;
break;
case V_206 :
V_179 = F_107 ( V_2 , V_104 , true ) ;
V_52 = true ;
break;
case V_207 :
V_179 = F_109 ( V_2 , V_104 ) ;
V_52 = true ;
break;
case V_208 :
V_179 = true ;
V_52 = true ;
break;
case V_209 :
F_110 ( V_2 , V_104 ) ;
break;
default:
break;
}
}
if ( V_179 )
F_66 ( V_2 ) ;
return V_52 ;
}
static int F_112 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_210 , V_111 ) ;
return F_7 ( V_2 , V_111 , V_210 , 0 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_103 V_104 ;
struct V_91 * V_92 = F_58 ( V_2 , 0 ) ;
if ( V_92 -> V_101 )
F_54 ( V_92 , F_50 ( V_92 ) ,
- V_211 ) ;
F_112 ( V_2 ) ;
F_59 ( V_2 , & V_104 ) ;
if ( ! F_111 ( V_2 , & V_104 ) )
if ( V_2 -> V_72 -> V_212 ( & V_2 -> V_74 , & V_104 ) < 0 )
F_66 ( V_2 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_91 * V_92 = F_58 ( V_2 , 0 ) ;
struct V_90 * V_94 = F_50 ( V_92 ) ;
if ( ! V_94 )
return;
F_85 ( V_92 , V_94 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
T_1 V_213 = F_3 ( V_2 , V_63 ) ;
V_213 &= F_3 ( V_2 , V_64 ) ;
F_1 ( V_2 , V_213 , V_63 ) ;
if ( V_213 & V_214 )
F_57 ( V_2 ) ;
if ( V_213 & V_215 )
F_113 ( V_2 ) ;
if ( V_213 & V_216 )
F_114 ( V_2 ) ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_90 * V_94 ,
int V_97 )
{
F_71 ( V_2 ) ;
F_15 ( V_2 , V_92 -> V_15 ) ;
F_54 ( V_92 , V_94 , V_97 ) ;
V_94 = F_50 ( V_92 ) ;
if ( V_94 )
F_87 ( V_92 , V_94 ) ;
}
static void F_117 ( struct V_1 * V_2 , int V_15 )
{
struct V_91 * V_92 = F_58 ( V_2 , V_15 ) ;
struct V_90 * V_94 = F_50 ( V_92 ) ;
if ( ! V_94 )
return;
if ( V_92 -> V_107 ) {
F_9 ( F_10 ( V_2 ) , L_6 ,
V_12 , V_94 -> V_98 . V_99 , V_94 -> V_98 . V_100 ) ;
F_116 ( V_2 , V_92 , V_94 , 0 ) ;
}
}
static void F_118 ( struct V_1 * V_2 , int V_15 )
{
struct V_91 * V_92 = F_58 ( V_2 , V_15 ) ;
struct V_90 * V_94 = F_50 ( V_92 ) ;
if ( ! V_94 )
return;
if ( V_92 -> V_107 ) {
if ( ! F_78 ( V_92 , V_94 , V_164 ) )
F_6 ( V_2 , V_166 , V_78 ) ;
} else {
if ( ! F_82 ( V_92 , V_94 , V_217 ) )
F_116 ( V_2 , V_92 , V_94 , 0 ) ;
}
}
static void F_119 ( struct V_1 * V_2 , int V_15 )
{
T_1 V_218 ;
if ( F_68 ( V_2 , V_15 ) < 0 )
return;
V_218 = F_3 ( V_2 , V_219 ) ;
V_218 &= F_3 ( V_2 , V_78 ) ;
F_1 ( V_2 , V_218 , V_219 ) ;
if ( V_218 & V_165 )
F_117 ( V_2 , V_15 ) ;
if ( V_218 & V_166 )
F_118 ( V_2 , V_15 ) ;
}
static void F_120 ( struct V_1 * V_2 , T_1 V_220 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_125 ; V_10 ++ ) {
if ( V_220 & F_14 ( V_10 ) ) {
if ( ! V_10 )
F_115 ( V_2 ) ;
else
F_119 ( V_2 , V_10 ) ;
}
}
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_89 = F_3 ( V_2 , V_25 ) ;
T_1 V_220 = F_3 ( V_2 , V_221 ) ;
V_89 &= F_3 ( V_2 , V_14 ) ;
if ( V_89 ) {
F_1 ( V_2 , V_89 , V_25 ) ;
F_47 ( V_2 , V_89 ) ;
}
V_220 &= F_3 ( V_2 , V_16 ) ;
if ( V_220 )
F_120 ( V_2 , V_220 ) ;
}
static T_6 F_122 ( int V_222 , void * V_223 )
{
struct V_1 * V_2 = V_223 ;
T_6 V_52 = V_224 ;
T_1 V_225 = F_3 ( V_2 , V_226 ) ;
if ( V_225 & V_20 ) {
F_121 ( V_2 ) ;
V_52 = V_227 ;
}
return V_52 ;
}
static void F_123 ( struct V_91 * V_92 ,
const struct V_228 * V_229 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
T_1 V_7 = 0 ;
V_7 |= V_92 -> V_107 ? V_230 : 0 ;
V_7 |= F_124 ( F_125 ( V_229 ) ) ;
V_7 |= F_126 ( F_127 ( V_229 ) ) ;
F_1 ( V_2 , V_7 , V_231 ) ;
}
static T_1 F_128 ( int V_232 )
{
F_129 ( V_232 > V_233 ) ;
if ( V_232 <= V_234 )
return V_235 ;
else if ( V_232 <= V_236 )
return V_237 ;
else if ( V_232 <= V_238 )
return V_239 ;
else if ( V_232 <= V_240 )
return V_241 ;
else
return V_242 ;
}
static T_1 F_130 ( struct V_91 * V_92 ,
const struct V_228 * V_229 )
{
return V_92 -> V_243 | F_131 ( F_132 ( V_229 ) ) ;
}
static int F_133 ( struct V_91 * V_92 ,
const struct V_228 * V_229 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
unsigned long V_95 ;
V_92 -> V_107 = F_134 ( V_229 ) ;
F_52 ( & V_2 -> V_96 , V_95 ) ;
if ( ! F_68 ( V_2 , V_92 -> V_15 ) ) {
F_123 ( V_92 , V_229 ) ;
F_1 ( V_2 , F_130 ( V_92 , V_229 ) ,
V_244 ) ;
F_73 ( V_2 ) ;
F_5 ( V_2 , V_197 , V_128 ) ;
}
F_53 ( & V_2 -> V_96 , V_95 ) ;
return 0 ;
}
static int F_135 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_51 ( V_92 ) ;
unsigned long V_95 ;
V_92 -> V_162 = false ;
F_52 ( & V_2 -> V_96 , V_95 ) ;
if ( ! F_68 ( V_2 , V_92 -> V_15 ) ) {
F_1 ( V_2 , 0 , V_244 ) ;
F_6 ( V_2 , V_197 , V_128 ) ;
}
F_53 ( & V_2 -> V_96 , V_95 ) ;
return 0 ;
}
static int F_136 ( struct V_167 * V_168 ,
const struct V_228 * V_229 )
{
struct V_91 * V_92 = F_89 ( V_168 ) ;
return F_133 ( V_92 , V_229 ) ;
}
static int F_137 ( struct V_167 * V_168 )
{
struct V_91 * V_92 = F_89 ( V_168 ) ;
struct V_90 * V_94 ;
do {
V_94 = F_50 ( V_92 ) ;
if ( ! V_94 )
break;
F_54 ( V_92 , V_94 , - V_245 ) ;
} while ( 1 );
return F_135 ( V_92 ) ;
}
static struct V_135 * F_138 ( T_4 V_170 )
{
struct V_90 * V_94 ;
V_94 = F_139 ( sizeof( struct V_90 ) , V_170 ) ;
if ( ! V_94 )
return NULL ;
F_140 ( & V_94 -> V_93 ) ;
return & V_94 -> V_98 ;
}
static void F_141 ( struct V_135 * V_169 )
{
struct V_90 * V_94 = F_90 ( V_169 ) ;
F_142 ( V_94 ) ;
}
static struct V_135 * F_143 ( struct V_167 * V_168 ,
T_4 V_170 )
{
return F_138 ( V_170 ) ;
}
static void F_144 ( struct V_167 * V_168 ,
struct V_135 * V_169 )
{
F_141 ( V_169 ) ;
}
static int F_145 ( struct V_167 * V_168 , struct V_135 * V_169 )
{
struct V_91 * V_92 = F_89 ( V_168 ) ;
struct V_90 * V_94 = F_90 ( V_169 ) ;
struct V_1 * V_2 = F_51 ( V_92 ) ;
F_9 ( F_10 ( V_2 ) , L_7 , V_92 -> V_15 ,
V_169 -> V_99 ) ;
F_116 ( V_2 , V_92 , V_94 , - V_211 ) ;
return 0 ;
}
static int F_146 ( struct V_167 * V_168 , int V_246 )
{
return F_105 ( F_89 ( V_168 ) , ! ! V_246 , false ) ;
}
static int F_147 ( struct V_167 * V_168 )
{
struct V_91 * V_92 = F_89 ( V_168 ) ;
V_92 -> V_196 = true ;
return F_105 ( V_92 , true , false ) ;
}
static void F_148 ( struct V_167 * V_168 )
{
struct V_91 * V_92 = F_89 ( V_168 ) ;
struct V_1 * V_2 = F_51 ( V_92 ) ;
unsigned long V_95 ;
if ( V_92 -> V_15 ) {
F_52 ( & V_2 -> V_96 , V_95 ) ;
if ( ! F_68 ( V_2 , V_92 -> V_15 ) ) {
F_73 ( V_2 ) ;
F_5 ( V_2 , V_197 , V_128 ) ;
}
F_53 ( & V_2 -> V_96 , V_95 ) ;
} else {
F_112 ( V_2 ) ;
}
}
static int F_149 ( struct V_247 * V_74 ,
struct V_248 * V_72 )
{
struct V_1 * V_2 ;
if ( ! V_72 || V_72 -> V_249 < V_87 ||
! V_72 -> V_212 )
return - V_194 ;
V_2 = F_150 ( V_74 ) ;
V_2 -> V_72 = V_72 ;
F_36 ( V_2 ) ;
return 0 ;
}
static int F_151 ( struct V_247 * V_74 )
{
struct V_1 * V_2 = F_150 ( V_74 ) ;
unsigned long V_95 ;
F_52 ( & V_2 -> V_96 , V_95 ) ;
V_2 -> V_33 = false ;
V_2 -> V_74 . V_80 = V_88 ;
V_2 -> V_72 = NULL ;
F_37 ( V_2 ) ;
F_53 ( & V_2 -> V_96 , V_95 ) ;
return 0 ;
}
static int F_152 ( struct V_247 * V_250 )
{
return - V_251 ;
}
static int F_153 ( struct V_247 * V_74 , int V_252 )
{
struct V_1 * V_2 = F_150 ( V_74 ) ;
V_2 -> V_33 = ! ! V_252 ;
return 0 ;
}
static int F_154 ( struct V_247 * V_74 , int V_253 )
{
V_74 -> V_182 = ! ! V_253 ;
return 0 ;
}
static int F_155 ( struct V_254 * V_255 )
{
struct V_1 * V_2 = F_156 ( V_255 ) ;
F_157 ( & V_255 -> V_256 ) ;
F_158 ( & V_255 -> V_256 ) ;
F_159 ( & V_2 -> V_74 ) ;
F_141 ( V_2 -> V_177 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 , struct V_257 * V_256 ,
const struct V_258 * V_259 )
{
struct V_91 * V_92 ;
int V_10 ;
V_2 -> V_125 = V_259 -> V_260 * V_259 -> V_261 * 2 /
V_259 -> V_262 + 1 ;
if ( V_2 -> V_125 > V_263 )
V_2 -> V_125 = V_263 ;
V_2 -> V_92 = F_161 ( V_256 , sizeof( * V_92 ) * V_2 -> V_125 ,
V_264 ) ;
if ( ! V_2 -> V_92 )
return - V_265 ;
F_9 ( V_256 , L_8 , V_12 , V_2 -> V_125 ) ;
F_162 (usb3_ep, usb3, i) {
snprintf ( V_92 -> V_266 , sizeof( V_92 -> V_266 ) , L_9 , V_10 ) ;
V_92 -> V_2 = V_2 ;
V_92 -> V_15 = V_10 ;
V_92 -> V_102 . V_267 = V_92 -> V_266 ;
V_92 -> V_102 . V_268 = & V_269 ;
F_140 ( & V_92 -> V_93 ) ;
F_140 ( & V_92 -> V_102 . V_270 ) ;
if ( ! V_10 ) {
V_2 -> V_74 . V_271 = & V_92 -> V_102 ;
F_163 ( & V_92 -> V_102 ,
V_272 ) ;
V_92 -> V_102 . V_273 . V_274 = true ;
V_92 -> V_102 . V_273 . V_107 = true ;
V_92 -> V_102 . V_273 . V_275 = true ;
continue;
}
F_163 ( & V_92 -> V_102 , ~ 0 ) ;
F_91 ( & V_92 -> V_102 . V_270 , & V_2 -> V_74 . V_270 ) ;
V_92 -> V_102 . V_273 . V_276 = true ;
V_92 -> V_102 . V_273 . V_277 = true ;
if ( V_10 & 1 )
V_92 -> V_102 . V_273 . V_107 = true ;
else
V_92 -> V_102 . V_273 . V_275 = true ;
}
return 0 ;
}
static void F_164 ( struct V_1 * V_2 , struct V_257 * V_256 ,
const struct V_258 * V_259 )
{
struct V_91 * V_92 ;
int V_10 ;
T_1 V_278 [ 2 ] , V_279 [ 2 ] ;
T_1 * V_280 , * V_281 ;
T_1 V_7 ;
memset ( V_278 , 0 , sizeof( V_278 ) ) ;
memset ( V_279 , 0 , sizeof( V_279 ) ) ;
F_162 (usb3_ep, usb3, i) {
if ( ! V_10 )
continue;
if ( V_92 -> V_102 . V_273 . V_107 ) {
V_280 = & V_278 [ 0 ] ;
V_281 = & V_279 [ 0 ] ;
} else {
V_280 = & V_278 [ 1 ] ;
V_281 = & V_279 [ 1 ] ;
}
if ( * V_281 > V_259 -> V_260 )
continue;
V_7 = F_165 ( * V_280 ) ;
V_7 |= F_128 ( V_259 -> V_262 ) ;
V_7 |= F_166 ( * V_281 ) ;
V_92 -> V_243 = V_7 ;
F_9 ( V_256 , L_10 ,
V_10 , V_7 , * V_280 , * V_281 ) ;
if ( * V_280 + 1 == V_259 -> V_261 ) {
* V_280 = 0 ;
* V_281 += V_259 -> V_262 ;
} else {
( * V_280 ) ++ ;
}
}
}
static int F_167 ( struct V_254 * V_255 )
{
struct V_1 * V_2 ;
struct V_282 * V_110 ;
const struct V_283 * V_284 ;
int V_222 , V_52 ;
const struct V_258 * V_259 ;
V_284 = F_168 ( V_285 , V_255 -> V_256 . V_286 ) ;
if ( ! V_284 )
return - V_287 ;
V_259 = V_284 -> V_3 ;
V_222 = F_169 ( V_255 , 0 ) ;
if ( V_222 < 0 )
return - V_287 ;
V_2 = F_161 ( & V_255 -> V_256 , sizeof( * V_2 ) , V_264 ) ;
if ( ! V_2 )
return - V_265 ;
V_110 = F_170 ( V_255 , V_288 , 0 ) ;
V_2 -> V_5 = F_171 ( & V_255 -> V_256 , V_110 ) ;
if ( F_172 ( V_2 -> V_5 ) )
return F_173 ( V_2 -> V_5 ) ;
F_174 ( V_255 , V_2 ) ;
F_175 ( & V_2 -> V_96 ) ;
V_2 -> V_74 . V_268 = & V_289 ;
V_2 -> V_74 . V_267 = V_290 ;
V_2 -> V_74 . V_249 = V_83 ;
F_140 ( & V_2 -> V_74 . V_270 ) ;
V_52 = F_160 ( V_2 , & V_255 -> V_256 , V_259 ) ;
if ( V_52 < 0 )
return V_52 ;
F_164 ( V_2 , & V_255 -> V_256 , V_259 ) ;
V_52 = F_176 ( & V_255 -> V_256 , V_222 , F_122 , 0 ,
F_177 ( & V_255 -> V_256 ) , V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
V_2 -> V_177 = F_138 ( V_264 ) ;
if ( ! V_2 -> V_177 )
return - V_265 ;
V_52 = F_178 ( & V_255 -> V_256 , & V_2 -> V_74 ) ;
if ( V_52 < 0 )
goto V_291;
V_2 -> V_75 = V_259 -> V_75 ;
F_179 ( & V_255 -> V_256 ) ;
F_180 ( & V_255 -> V_256 ) ;
F_181 ( & V_255 -> V_256 , L_11 ) ;
return 0 ;
V_291:
F_141 ( V_2 -> V_177 ) ;
return V_52 ;
}
