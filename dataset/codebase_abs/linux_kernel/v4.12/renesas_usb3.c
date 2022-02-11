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
static void F_11 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 , struct V_1 ,
V_16 ) ;
F_13 ( V_2 -> V_17 , V_18 , V_2 -> V_19 ) ;
F_13 ( V_2 -> V_17 , V_20 , V_2 -> V_21 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_6 )
{
F_5 ( V_2 , V_6 , V_22 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_6 )
{
F_6 ( V_2 , V_6 , V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_23 )
{
F_5 ( V_2 , F_17 ( V_23 ) , V_24 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_23 )
{
F_6 ( V_2 , F_17 ( V_23 ) , V_24 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
return ! ( F_3 ( V_2 , V_25 ) & V_26 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_1 ( V_2 , ~ 0 , V_27 ) ;
F_1 ( V_2 , 0 , V_28 ) ;
F_5 ( V_2 , V_29 | V_30 , V_31 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_1 ( V_2 , ~ 0 , V_32 ) ;
F_14 ( V_2 , V_33 ) ;
}
static bool F_22 ( struct V_1 * V_2 )
{
if ( ! ( F_3 ( V_2 , V_34 ) & V_35 ) )
return true ;
F_6 ( V_2 , V_35 , V_34 ) ;
F_14 ( V_2 , V_36 ) ;
return false ;
}
static void F_23 ( struct V_1 * V_2 , int V_37 )
{
T_1 V_6 = V_38 | V_39 ;
if ( V_2 -> V_40 && V_37 )
F_5 ( V_2 , V_6 , V_34 ) ;
else
F_6 ( V_2 , V_6 , V_34 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_7 = F_3 ( V_2 , V_34 ) ;
V_7 &= ~ V_41 ;
V_7 |= F_25 ( V_2 -> V_42 ) ;
F_1 ( V_2 , V_7 | V_43 , V_34 ) ;
if ( ! V_2 -> V_42 )
F_6 ( V_2 , V_43 , V_34 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_44 ++ ;
F_5 ( V_2 , V_45 , V_46 ) ;
F_5 ( V_2 , V_47 , V_46 ) ;
F_23 ( V_2 , 1 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_48 ) & V_49 ;
}
static bool F_28 ( struct V_1 * V_2 )
{
if ( ! F_27 ( V_2 ) )
return true ;
F_5 ( V_2 , V_50 , V_48 ) ;
F_14 ( V_2 , V_51 ) ;
return false ;
}
static T_2 F_29 ( struct V_1 * V_2 )
{
T_1 V_52 = V_53 | V_54 ;
T_1 V_55 = V_56 | V_57 ;
T_1 V_7 = F_3 ( V_2 , V_58 ) ;
T_2 V_59 = 0 ;
if ( ! ( V_7 & V_52 ) )
V_59 |= 1 << V_60 ;
if ( ! ( V_7 & V_55 ) )
V_59 |= 1 << V_61 ;
return V_59 ;
}
static void F_30 ( struct V_1 * V_2 , bool V_62 )
{
T_1 V_6 = V_53 | V_54 ;
if ( V_62 )
F_6 ( V_2 , V_6 , V_58 ) ;
else
F_5 ( V_2 , V_6 , V_58 ) ;
}
static void F_31 ( struct V_1 * V_2 , bool V_62 )
{
T_1 V_6 = V_56 | V_57 ;
if ( V_62 )
F_6 ( V_2 , V_6 , V_58 ) ;
else
F_5 ( V_2 , V_6 , V_58 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_45 , V_46 ) ;
F_6 ( V_2 , V_47 , V_46 ) ;
F_5 ( V_2 , V_63 , V_48 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
F_5 ( V_2 , V_64 , V_46 ) ;
F_14 ( V_2 , V_65 | V_66 |
V_67 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_63 , V_48 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
bool V_68 )
{
F_5 ( V_2 , F_17 ( 0 ) , V_24 ) ;
F_1 ( V_2 , V_69 , V_70 ) ;
F_5 ( V_2 , V_69 , V_71 ) ;
if ( V_68 )
F_14 ( V_2 , V_72 |
V_73 ) ;
else
F_14 ( V_2 , V_74 |
V_75 | V_76 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( F_28 ( V_2 ) )
F_33 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_77 , V_46 ) ;
F_6 ( V_2 , V_45 , V_46 ) ;
F_5 ( V_2 , V_78 , V_46 ) ;
V_2 -> V_42 = 0 ;
F_24 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_44 = 0 ;
F_23 ( V_2 , 0 ) ;
F_6 ( V_2 , V_63 , V_48 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_79 )
V_2 -> V_79 -> V_80 ( & V_2 -> V_81 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 ) {
F_36 ( V_2 ) ;
} else {
V_2 -> V_21 = ! ! ( F_3 ( V_2 , V_83 ) &
V_84 ) ;
if ( V_2 -> V_21 )
F_36 ( V_2 ) ;
else
F_38 ( V_2 ) ;
F_40 ( & V_2 -> V_16 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , bool V_85 )
{
if ( V_85 )
F_6 ( V_2 , V_26 , V_25 ) ;
else
F_5 ( V_2 , V_26 , V_25 ) ;
}
static void F_42 ( struct V_1 * V_2 , bool V_62 )
{
if ( V_62 )
F_5 ( V_2 , V_86 , V_25 ) ;
else
F_6 ( V_2 , V_86 , V_25 ) ;
}
static void F_43 ( struct V_1 * V_2 , bool V_85 , bool V_87 )
{
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
F_41 ( V_2 , V_85 ) ;
F_42 ( V_2 , V_87 ) ;
if ( ! V_85 && V_87 )
F_36 ( V_2 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
}
static bool F_46 ( struct V_1 * V_2 )
{
return ! ( F_3 ( V_2 , V_90 ) & V_91 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_19 = F_46 ( V_2 ) ;
if ( V_2 -> V_19 )
F_43 ( V_2 , true , true ) ;
else
F_43 ( V_2 , false , false ) ;
F_40 ( & V_2 -> V_16 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_1 ( V_2 , V_91 , V_92 ) ;
F_1 ( V_2 , V_91 , V_93 ) ;
F_47 ( V_2 ) ;
F_39 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_1 ( V_2 , 0 , V_71 ) ;
F_1 ( V_2 , 0 , V_93 ) ;
F_1 ( V_2 , 0 , V_22 ) ;
F_1 ( V_2 , 0 , V_24 ) ;
F_1 ( V_2 , 0 , V_31 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_51 ) ;
F_6 ( V_2 , V_50 , V_48 ) ;
F_33 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_35 ( V_2 , true ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_36 ) ;
F_26 ( V_2 ) ;
F_35 ( V_2 , false ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
if ( F_22 ( V_2 ) )
F_52 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
if ( V_2 -> V_44 < 3 )
F_33 ( V_2 ) ;
else
F_26 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
F_5 ( V_2 , V_45 , V_46 ) ;
F_5 ( V_2 , V_94 , V_48 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
F_5 ( V_2 , V_45 , V_46 ) ;
F_32 ( V_2 ) ;
F_14 ( V_2 , V_67 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_1 V_95 = F_3 ( V_2 , V_83 ) & V_96 ;
switch ( V_95 ) {
case V_97 :
V_2 -> V_81 . V_95 = V_98 ;
break;
case V_99 :
V_2 -> V_81 . V_95 = V_100 ;
break;
case V_101 :
V_2 -> V_81 . V_95 = V_102 ;
break;
default:
V_2 -> V_81 . V_95 = V_103 ;
break;
}
}
static void F_59 ( struct V_1 * V_2 , T_1 V_104 )
{
if ( V_104 & V_51 )
F_50 ( V_2 ) ;
if ( V_104 & V_65 )
F_51 ( V_2 ) ;
if ( V_104 & V_73 )
F_56 ( V_2 ) ;
if ( V_104 & V_72 )
F_57 ( V_2 ) ;
if ( V_104 & V_66 )
F_53 ( V_2 ) ;
if ( V_104 & V_76 )
F_54 ( V_2 ) ;
if ( V_104 & V_36 )
F_52 ( V_2 ) ;
if ( V_104 & V_67 )
F_58 ( V_2 ) ;
if ( V_104 & V_33 )
F_55 ( V_2 ) ;
}
static struct V_105 * F_60 ( struct V_106
* V_107 )
{
return F_61 ( & V_107 -> V_108 ,
struct V_105 , V_108 ) ;
}
static struct V_105 * F_62 ( struct V_106
* V_107 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
struct V_105 * V_109 ;
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
V_109 = F_60 ( V_107 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
return V_109 ;
}
static void F_64 ( struct V_106 * V_107 ,
struct V_105 * V_109 , int V_110 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
unsigned long V_88 ;
F_9 ( F_10 ( V_2 ) , L_2 ,
V_107 -> V_23 , V_109 -> V_111 . V_112 , V_109 -> V_111 . V_113 ,
V_110 ) ;
V_109 -> V_111 . V_110 = V_110 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
V_107 -> V_114 = false ;
F_65 ( & V_109 -> V_108 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
F_66 ( & V_107 -> V_115 , & V_109 -> V_111 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = F_68 ( V_2 , 0 ) ;
struct V_105 * V_109 = F_62 ( V_107 ) ;
if ( V_109 )
F_64 ( V_107 , V_109 , 0 ) ;
if ( V_2 -> V_42 )
F_24 ( V_2 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
struct V_106 * V_107 = F_68 ( V_2 , 0 ) ;
T_1 * V_3 = ( T_1 * ) V_117 ;
* V_3 ++ = F_3 ( V_2 , V_118 ) ;
* V_3 = F_3 ( V_2 , V_119 ) ;
V_107 -> V_120 = ! ! ( V_117 -> V_121 & V_122 ) ;
}
static void F_70 ( struct V_1 * V_2 , T_1 V_123 )
{
T_1 V_7 = F_3 ( V_2 , V_124 ) ;
V_7 &= ~ ( V_125 | V_126 | V_127 ) ;
V_7 |= V_123 | V_128 ;
F_1 ( V_2 , V_7 , V_124 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_129 |
V_130 |
V_131 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_132 |
V_130 |
V_131 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_129 |
V_133 |
V_134 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_132 |
V_133 |
V_134 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_132 |
V_130 |
V_134 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_135 |
V_130 |
V_134 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
F_70 ( V_2 , V_129 |
V_136 |
V_137 ) ;
}
static int F_78 ( struct V_1 * V_2 , int V_23 )
{
if ( V_23 == 0 || V_23 > V_2 -> V_138 )
return - V_139 ;
F_1 ( V_2 , V_23 , V_140 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 , T_1 V_123 )
{
T_1 V_7 = F_3 ( V_2 , V_141 ) ;
V_7 &= ~ V_142 ;
V_7 |= V_123 & V_142 ;
V_7 |= V_143 ;
F_1 ( V_2 , V_7 , V_141 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_79 ( V_2 , V_144 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
F_79 ( V_2 , V_145 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_79 ( V_2 , V_146 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_147 , V_141 ) ;
return F_7 ( V_2 , V_141 , V_147 , 0 ) ;
}
static bool F_84 ( struct V_106 * V_107 ,
struct V_105 * V_109 )
{
struct V_148 * V_111 = & V_109 -> V_111 ;
if ( ( ! V_111 -> V_149 && V_111 -> V_113 == V_111 -> V_112 ) ||
( V_111 -> V_113 % V_107 -> V_115 . V_150 ) || ( V_111 -> V_112 == 0 ) )
return true ;
else
return false ;
}
static int F_85 ( struct V_106 * V_107 , T_1 V_8 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
T_1 V_151 = V_107 -> V_23 ? V_152 : V_153 ;
return F_7 ( V_2 , V_151 , V_8 , V_8 ) ;
}
static void F_86 ( struct V_106 * V_107 , int V_154 ,
bool V_155 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
T_1 V_156 = V_107 -> V_23 ? V_141 : V_124 ;
T_1 V_7 = F_3 ( V_2 , V_156 ) ;
V_7 |= V_157 | F_87 ( V_154 ) ;
V_7 |= ( V_107 -> V_23 && V_155 ) ? V_158 : 0 ;
F_1 ( V_2 , V_7 , V_156 ) ;
}
static int F_88 ( struct V_106 * V_107 ,
struct V_105 * V_109 ,
T_1 V_159 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
int V_10 ;
int V_160 = F_89 ( unsigned , V_109 -> V_111 . V_112 - V_109 -> V_111 . V_113 ,
V_107 -> V_115 . V_150 ) ;
T_3 * V_161 = V_109 -> V_111 . V_161 + V_109 -> V_111 . V_113 ;
T_1 V_162 = 0 ;
bool V_163 ;
if ( F_85 ( V_107 , V_164 ) < 0 )
return - V_13 ;
V_109 -> V_111 . V_113 += V_160 ;
if ( V_160 >= 4 ) {
F_90 ( V_2 -> V_5 + V_159 , V_161 , V_160 / 4 ) ;
V_161 += ( V_160 / 4 ) * 4 ;
V_160 %= 4 ;
}
if ( V_160 ) {
for ( V_10 = 0 ; V_10 < V_160 ; V_10 ++ )
V_162 |= V_161 [ V_10 ] << ( 8 * V_10 ) ;
F_1 ( V_2 , V_162 , V_159 ) ;
}
V_163 = F_84 ( V_107 , V_109 ) ;
F_86 ( V_107 , V_160 , V_163 ) ;
return V_163 ? 0 : - V_165 ;
}
static T_1 F_91 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
T_1 V_166 = V_107 -> V_23 ? V_167 : V_168 ;
return F_3 ( V_2 , V_166 ) ;
}
static int F_92 ( struct V_106 * V_107 ,
struct V_105 * V_109 , T_1 V_159 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
int V_10 ;
int V_160 = F_89 ( unsigned , V_109 -> V_111 . V_112 - V_109 -> V_111 . V_113 ,
F_91 ( V_107 ) ) ;
T_3 * V_161 = V_109 -> V_111 . V_161 + V_109 -> V_111 . V_113 ;
T_1 V_162 = 0 ;
if ( ! V_160 )
return 0 ;
V_109 -> V_111 . V_113 += V_160 ;
if ( V_160 >= 4 ) {
F_93 ( V_2 -> V_5 + V_159 , V_161 , V_160 / 4 ) ;
V_161 += ( V_160 / 4 ) * 4 ;
V_160 %= 4 ;
}
if ( V_160 ) {
V_162 = F_3 ( V_2 , V_159 ) ;
for ( V_10 = 0 ; V_10 < V_160 ; V_10 ++ )
V_161 [ V_10 ] = ( V_162 >> ( 8 * V_10 ) ) & 0xff ;
}
return F_84 ( V_107 , V_109 ) ? 0 : - V_165 ;
}
static void F_94 ( struct V_106 * V_107 ,
struct V_105 * V_109 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
if ( V_107 -> V_120 ) {
F_72 ( V_2 ) ;
} else {
if ( ! V_109 -> V_111 . V_112 )
F_75 ( V_2 ) ;
else
F_74 ( V_2 ) ;
}
}
static void F_95 ( struct V_106 * V_107 ,
struct V_105 * V_109 )
{
int V_59 = - V_165 ;
if ( V_107 -> V_120 )
V_59 = F_88 ( V_107 , V_109 , V_169 ) ;
else
V_59 = F_92 ( V_107 , V_109 , V_170 ) ;
if ( ! V_59 )
F_94 ( V_107 , V_109 ) ;
}
static void F_96 ( struct V_106 * V_107 ,
struct V_105 * V_109 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
if ( V_107 -> V_114 )
return;
V_107 -> V_114 = true ;
if ( V_107 -> V_120 ) {
F_5 ( V_2 , V_171 , V_172 ) ;
F_71 ( V_2 ) ;
} else {
F_6 ( V_2 , V_171 , V_172 ) ;
F_73 ( V_2 ) ;
}
F_95 ( V_107 , V_109 ) ;
}
static void F_97 ( struct V_106 * V_107 ,
struct V_105 * V_109 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
struct V_105 * V_173 = F_62 ( V_107 ) ;
unsigned long V_88 ;
int V_59 = - V_165 ;
T_1 V_174 = 0 ;
if ( V_107 -> V_175 || V_107 -> V_114 )
return;
if ( V_109 != V_173 )
return;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( F_78 ( V_2 , V_107 -> V_23 ) < 0 )
goto V_176;
V_107 -> V_114 = true ;
F_80 ( V_2 ) ;
if ( V_107 -> V_120 ) {
V_59 = F_88 ( V_107 , V_109 , V_177 ) ;
V_174 |= V_178 ;
}
if ( V_59 < 0 )
V_174 |= V_179 ;
if ( V_174 ) {
F_5 ( V_2 , V_174 , V_180 ) ;
F_16 ( V_2 , V_107 -> V_23 ) ;
}
V_176:
F_45 ( & V_2 -> V_89 , V_88 ) ;
}
static int F_98 ( struct V_181 * V_182 , struct V_148 * V_183 ,
T_4 V_184 )
{
struct V_106 * V_107 = F_99 ( V_182 ) ;
struct V_105 * V_109 = F_100 ( V_183 ) ;
struct V_1 * V_2 = F_63 ( V_107 ) ;
unsigned long V_88 ;
F_9 ( F_10 ( V_2 ) , L_3 , V_107 -> V_23 ,
V_183 -> V_112 ) ;
V_183 -> V_110 = - V_185 ;
V_183 -> V_113 = 0 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
F_101 ( & V_109 -> V_108 , & V_107 -> V_108 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
if ( ! V_107 -> V_23 )
F_96 ( V_107 , V_109 ) ;
else
F_97 ( V_107 , V_109 ) ;
return 0 ;
}
static void F_102 ( struct V_1 * V_2 , T_2 V_186 )
{
F_5 ( V_2 , F_103 ( V_186 ) , V_46 ) ;
}
static bool F_104 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
if ( V_117 -> V_187 >= 128 )
return true ;
F_102 ( V_2 , V_117 -> V_187 ) ;
F_75 ( V_2 ) ;
return false ;
}
static void F_105 ( struct V_1 * V_2 ,
void * V_188 , T_5 V_160 ,
void (* F_106)( struct V_181 * V_115 ,
struct V_148 * V_111 ) )
{
struct V_106 * V_107 = F_68 ( V_2 , 0 ) ;
if ( V_188 )
memcpy ( V_2 -> V_189 , V_188 ,
F_89 ( T_5 , V_160 , V_190 ) ) ;
V_2 -> V_191 -> V_161 = & V_2 -> V_189 ;
V_2 -> V_191 -> V_112 = V_160 ;
V_2 -> V_191 -> F_106 = F_106 ;
F_98 ( & V_107 -> V_115 , V_2 -> V_191 , V_192 ) ;
}
static void F_107 ( struct V_181 * V_115 ,
struct V_148 * V_111 )
{
}
static bool F_108 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
bool V_193 = false ;
struct V_106 * V_107 ;
int V_23 ;
T_2 V_110 = 0 ;
switch ( V_117 -> V_121 & V_194 ) {
case V_195 :
if ( V_2 -> V_81 . V_196 )
V_110 |= 1 << V_197 ;
if ( V_2 -> V_81 . V_95 == V_98 )
V_110 |= F_29 ( V_2 ) ;
break;
case V_198 :
break;
case V_199 :
V_23 = F_109 ( V_117 -> V_200 ) & V_201 ;
V_107 = F_68 ( V_2 , V_23 ) ;
if ( V_107 -> V_175 )
V_110 |= 1 << V_202 ;
break;
default:
V_193 = true ;
break;
}
if ( ! V_193 ) {
V_110 = F_110 ( V_110 ) ;
F_9 ( F_10 ( V_2 ) , L_4 ,
F_100 ( V_2 -> V_191 ) ) ;
F_105 ( V_2 , & V_110 , sizeof( V_110 ) ,
F_107 ) ;
}
return V_193 ;
}
static bool F_111 ( struct V_1 * V_2 ,
struct V_116 * V_117 , bool V_203 )
{
bool V_193 = true ;
T_2 V_204 = F_109 ( V_117 -> V_187 ) ;
switch ( V_204 ) {
case V_205 :
if ( ! V_203 )
break;
V_2 -> V_42 = F_109 ( V_117 -> V_200 ) >> 8 ;
V_193 = false ;
break;
case V_206 :
case V_207 :
if ( V_2 -> V_81 . V_95 != V_98 )
break;
if ( V_204 == V_206 )
F_31 ( V_2 , V_203 ) ;
if ( V_204 == V_207 )
F_30 ( V_2 , V_203 ) ;
V_193 = false ;
break;
default:
break;
}
return V_193 ;
}
static int F_112 ( struct V_106 * V_107 , bool V_175 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
if ( F_113 ( V_107 -> V_23 ) )
return - V_208 ;
V_107 -> V_175 = V_175 ;
if ( V_175 )
F_76 ( V_2 ) ;
else
F_77 ( V_2 ) ;
return 0 ;
}
static int F_114 ( struct V_106 * V_107 , bool V_175 ,
bool V_209 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_78 ( V_2 , V_107 -> V_23 ) ) {
V_107 -> V_175 = V_175 ;
if ( V_175 ) {
F_82 ( V_2 ) ;
} else if ( ! V_209 || ! V_107 -> V_210 ) {
F_83 ( V_2 ) ;
F_5 ( V_2 , V_211 , V_141 ) ;
F_81 ( V_2 ) ;
}
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_115 ( struct V_106 * V_107 , bool V_175 ,
bool V_209 )
{
int V_59 = 0 ;
if ( V_175 && V_107 -> V_114 )
return - V_165 ;
if ( V_107 -> V_23 )
V_59 = F_114 ( V_107 , V_175 , V_209 ) ;
else
V_59 = F_112 ( V_107 , V_175 ) ;
return V_59 ;
}
static bool F_116 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
bool V_203 )
{
int V_23 = F_109 ( V_117 -> V_200 ) & V_201 ;
struct V_106 * V_107 ;
struct V_105 * V_109 ;
if ( F_109 ( V_117 -> V_187 ) != V_202 )
return true ;
V_107 = F_68 ( V_2 , V_23 ) ;
F_115 ( V_107 , V_203 , true ) ;
if ( ! V_203 ) {
V_107 -> V_114 = false ;
V_109 = F_62 ( V_107 ) ;
if ( V_109 )
F_97 ( V_107 , V_109 ) ;
}
return false ;
}
static bool F_117 ( struct V_1 * V_2 ,
struct V_116 * V_117 , bool V_203 )
{
bool V_193 = false ;
switch ( V_117 -> V_121 & V_194 ) {
case V_195 :
V_193 = F_111 ( V_2 , V_117 , V_203 ) ;
break;
case V_198 :
break;
case V_199 :
V_193 = F_116 ( V_2 , V_117 , V_203 ) ;
break;
default:
V_193 = true ;
break;
}
if ( ! V_193 )
F_75 ( V_2 ) ;
return V_193 ;
}
static void F_118 ( struct V_181 * V_115 ,
struct V_148 * V_111 )
{
}
static bool F_119 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
T_2 V_212 = F_109 ( V_117 -> V_213 ) ;
if ( V_212 != 6 )
return true ;
F_9 ( F_10 ( V_2 ) , L_5 ,
F_100 ( V_2 -> V_191 ) ) ;
F_105 ( V_2 , NULL , 6 , F_118 ) ;
return false ;
}
static bool F_120 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
if ( V_117 -> V_187 > 0 )
F_5 ( V_2 , V_77 , V_46 ) ;
else
F_6 ( V_2 , V_77 , V_46 ) ;
return false ;
}
static bool F_121 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
bool V_59 = false ;
bool V_193 = false ;
if ( ( V_117 -> V_121 & V_214 ) == V_215 ) {
switch ( V_117 -> V_216 ) {
case V_217 :
V_193 = F_104 ( V_2 , V_117 ) ;
V_59 = true ;
break;
case V_218 :
V_193 = F_108 ( V_2 , V_117 ) ;
V_59 = true ;
break;
case V_219 :
V_193 = F_117 ( V_2 , V_117 , false ) ;
V_59 = true ;
break;
case V_220 :
V_193 = F_117 ( V_2 , V_117 , true ) ;
V_59 = true ;
break;
case V_221 :
V_193 = F_119 ( V_2 , V_117 ) ;
V_59 = true ;
break;
case V_222 :
V_193 = true ;
V_59 = true ;
break;
case V_223 :
F_120 ( V_2 , V_117 ) ;
break;
default:
break;
}
}
if ( V_193 )
F_76 ( V_2 ) ;
return V_59 ;
}
static int F_122 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_224 , V_124 ) ;
return F_7 ( V_2 , V_124 , V_224 , 0 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_116 V_117 ;
struct V_106 * V_107 = F_68 ( V_2 , 0 ) ;
if ( V_107 -> V_114 )
F_64 ( V_107 , F_62 ( V_107 ) ,
- V_225 ) ;
F_122 ( V_2 ) ;
F_69 ( V_2 , & V_117 ) ;
if ( ! F_121 ( V_2 , & V_117 ) )
if ( V_2 -> V_79 -> V_226 ( & V_2 -> V_81 , & V_117 ) < 0 )
F_76 ( V_2 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = F_68 ( V_2 , 0 ) ;
struct V_105 * V_109 = F_62 ( V_107 ) ;
if ( ! V_109 )
return;
F_95 ( V_107 , V_109 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
T_1 V_227 = F_3 ( V_2 , V_70 ) ;
V_227 &= F_3 ( V_2 , V_71 ) ;
F_1 ( V_2 , V_227 , V_70 ) ;
if ( V_227 & V_228 )
F_67 ( V_2 ) ;
if ( V_227 & V_229 )
F_123 ( V_2 ) ;
if ( V_227 & V_230 )
F_124 ( V_2 ) ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_106 * V_107 ,
struct V_105 * V_109 ,
int V_110 )
{
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( F_78 ( V_2 , V_107 -> V_23 ) )
F_81 ( V_2 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
F_18 ( V_2 , V_107 -> V_23 ) ;
F_64 ( V_107 , V_109 , V_110 ) ;
V_109 = F_62 ( V_107 ) ;
if ( V_109 )
F_97 ( V_107 , V_109 ) ;
}
static void F_127 ( struct V_1 * V_2 , int V_23 )
{
struct V_106 * V_107 = F_68 ( V_2 , V_23 ) ;
struct V_105 * V_109 = F_62 ( V_107 ) ;
if ( ! V_109 )
return;
if ( V_107 -> V_120 ) {
F_9 ( F_10 ( V_2 ) , L_6 ,
V_12 , V_109 -> V_111 . V_112 , V_109 -> V_111 . V_113 ) ;
F_126 ( V_2 , V_107 , V_109 , 0 ) ;
}
}
static void F_128 ( struct V_1 * V_2 , int V_23 )
{
struct V_106 * V_107 = F_68 ( V_2 , V_23 ) ;
struct V_105 * V_109 = F_62 ( V_107 ) ;
bool V_231 = false ;
if ( ! V_109 )
return;
F_129 ( & V_2 -> V_89 ) ;
if ( F_78 ( V_2 , V_23 ) )
goto V_176;
if ( V_107 -> V_120 ) {
if ( ! F_88 ( V_107 , V_109 , V_177 ) )
F_6 ( V_2 , V_179 , V_180 ) ;
} else {
if ( ! F_92 ( V_107 , V_109 , V_232 ) )
V_231 = true ;
}
V_176:
F_130 ( & V_2 -> V_89 ) ;
if ( V_231 )
F_126 ( V_2 , V_107 , V_109 , 0 ) ;
}
static void F_131 ( struct V_1 * V_2 , int V_23 )
{
T_1 V_233 ;
F_129 ( & V_2 -> V_89 ) ;
if ( F_78 ( V_2 , V_23 ) < 0 ) {
F_130 ( & V_2 -> V_89 ) ;
return;
}
V_233 = F_3 ( V_2 , V_234 ) ;
V_233 &= F_3 ( V_2 , V_180 ) ;
F_1 ( V_2 , V_233 , V_234 ) ;
F_130 ( & V_2 -> V_89 ) ;
if ( V_233 & V_178 )
F_127 ( V_2 , V_23 ) ;
if ( V_233 & V_179 )
F_128 ( V_2 , V_23 ) ;
}
static void F_132 ( struct V_1 * V_2 , T_1 V_235 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_138 ; V_10 ++ ) {
if ( V_235 & F_17 ( V_10 ) ) {
if ( ! V_10 )
F_125 ( V_2 ) ;
else
F_131 ( V_2 , V_10 ) ;
}
}
}
static void F_133 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
}
static void F_134 ( struct V_1 * V_2 , T_1 V_236 )
{
if ( V_236 & V_91 )
F_133 ( V_2 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
T_1 V_104 = F_3 ( V_2 , V_32 ) ;
T_1 V_235 = F_3 ( V_2 , V_237 ) ;
T_1 V_236 = F_3 ( V_2 , V_92 ) ;
V_104 &= F_3 ( V_2 , V_22 ) ;
if ( V_104 ) {
F_1 ( V_2 , V_104 , V_32 ) ;
F_59 ( V_2 , V_104 ) ;
}
V_235 &= F_3 ( V_2 , V_24 ) ;
if ( V_235 )
F_132 ( V_2 , V_235 ) ;
V_236 &= F_3 ( V_2 , V_93 ) ;
if ( V_236 ) {
F_1 ( V_2 , V_236 , V_92 ) ;
F_134 ( V_2 , V_236 ) ;
}
}
static T_6 F_136 ( int V_238 , void * V_239 )
{
struct V_1 * V_2 = V_239 ;
T_6 V_59 = V_240 ;
T_1 V_241 = F_3 ( V_2 , V_242 ) ;
if ( V_241 & V_30 ) {
F_135 ( V_2 ) ;
V_59 = V_243 ;
}
return V_59 ;
}
static void F_137 ( struct V_106 * V_107 ,
const struct V_244 * V_245 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
T_1 V_7 = 0 ;
V_7 |= V_107 -> V_120 ? V_246 : 0 ;
V_7 |= F_138 ( F_139 ( V_245 ) ) ;
V_7 |= F_140 ( F_141 ( V_245 ) ) ;
F_1 ( V_2 , V_7 , V_247 ) ;
}
static T_1 F_142 ( int V_248 )
{
F_143 ( V_248 > V_249 ) ;
if ( V_248 <= V_250 )
return V_251 ;
else if ( V_248 <= V_252 )
return V_253 ;
else if ( V_248 <= V_254 )
return V_255 ;
else if ( V_248 <= V_256 )
return V_257 ;
else
return V_258 ;
}
static T_1 F_144 ( struct V_106 * V_107 ,
const struct V_244 * V_245 )
{
return V_107 -> V_259 | F_145 ( F_146 ( V_245 ) ) ;
}
static int F_147 ( struct V_106 * V_107 ,
const struct V_244 * V_245 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
unsigned long V_88 ;
V_107 -> V_120 = F_148 ( V_245 ) ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_78 ( V_2 , V_107 -> V_23 ) ) {
F_137 ( V_107 , V_245 ) ;
F_1 ( V_2 , F_144 ( V_107 , V_245 ) ,
V_260 ) ;
F_83 ( V_2 ) ;
F_5 ( V_2 , V_211 , V_141 ) ;
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_149 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_63 ( V_107 ) ;
unsigned long V_88 ;
V_107 -> V_175 = false ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_78 ( V_2 , V_107 -> V_23 ) ) {
F_1 ( V_2 , 0 , V_180 ) ;
F_1 ( V_2 , 0 , V_260 ) ;
F_6 ( V_2 , V_211 , V_141 ) ;
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_150 ( struct V_181 * V_182 ,
const struct V_244 * V_245 )
{
struct V_106 * V_107 = F_99 ( V_182 ) ;
return F_147 ( V_107 , V_245 ) ;
}
static int F_151 ( struct V_181 * V_182 )
{
struct V_106 * V_107 = F_99 ( V_182 ) ;
struct V_105 * V_109 ;
do {
V_109 = F_62 ( V_107 ) ;
if ( ! V_109 )
break;
F_64 ( V_107 , V_109 , - V_261 ) ;
} while ( 1 );
return F_149 ( V_107 ) ;
}
static struct V_148 * F_152 ( T_4 V_184 )
{
struct V_105 * V_109 ;
V_109 = F_153 ( sizeof( struct V_105 ) , V_184 ) ;
if ( ! V_109 )
return NULL ;
F_154 ( & V_109 -> V_108 ) ;
return & V_109 -> V_111 ;
}
static void F_155 ( struct V_148 * V_183 )
{
struct V_105 * V_109 = F_100 ( V_183 ) ;
F_156 ( V_109 ) ;
}
static struct V_148 * F_157 ( struct V_181 * V_182 ,
T_4 V_184 )
{
return F_152 ( V_184 ) ;
}
static void F_158 ( struct V_181 * V_182 ,
struct V_148 * V_183 )
{
F_155 ( V_183 ) ;
}
static int F_159 ( struct V_181 * V_182 , struct V_148 * V_183 )
{
struct V_106 * V_107 = F_99 ( V_182 ) ;
struct V_105 * V_109 = F_100 ( V_183 ) ;
struct V_1 * V_2 = F_63 ( V_107 ) ;
F_9 ( F_10 ( V_2 ) , L_7 , V_107 -> V_23 ,
V_183 -> V_112 ) ;
F_126 ( V_2 , V_107 , V_109 , - V_225 ) ;
return 0 ;
}
static int F_160 ( struct V_181 * V_182 , int V_262 )
{
return F_115 ( F_99 ( V_182 ) , ! ! V_262 , false ) ;
}
static int F_161 ( struct V_181 * V_182 )
{
struct V_106 * V_107 = F_99 ( V_182 ) ;
V_107 -> V_210 = true ;
return F_115 ( V_107 , true , false ) ;
}
static void F_162 ( struct V_181 * V_182 )
{
struct V_106 * V_107 = F_99 ( V_182 ) ;
struct V_1 * V_2 = F_63 ( V_107 ) ;
unsigned long V_88 ;
if ( V_107 -> V_23 ) {
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_78 ( V_2 , V_107 -> V_23 ) ) {
F_83 ( V_2 ) ;
F_5 ( V_2 , V_211 , V_141 ) ;
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
} else {
F_122 ( V_2 ) ;
}
}
static int F_163 ( struct V_263 * V_81 ,
struct V_264 * V_79 )
{
struct V_1 * V_2 ;
if ( ! V_79 || V_79 -> V_265 < V_102 ||
! V_79 -> V_226 )
return - V_208 ;
V_2 = F_164 ( V_81 ) ;
V_2 -> V_79 = V_79 ;
F_165 ( F_10 ( V_2 ) ) ;
F_166 ( F_10 ( V_2 ) ) ;
F_48 ( V_2 ) ;
return 0 ;
}
static int F_167 ( struct V_263 * V_81 )
{
struct V_1 * V_2 = F_164 ( V_81 ) ;
V_2 -> V_40 = false ;
V_2 -> V_81 . V_95 = V_103 ;
V_2 -> V_79 = NULL ;
F_49 ( V_2 ) ;
F_168 ( F_10 ( V_2 ) ) ;
F_169 ( F_10 ( V_2 ) ) ;
return 0 ;
}
static int F_170 ( struct V_263 * V_266 )
{
return - V_267 ;
}
static int F_171 ( struct V_263 * V_81 , int V_268 )
{
struct V_1 * V_2 = F_164 ( V_81 ) ;
V_2 -> V_40 = ! ! V_268 ;
return 0 ;
}
static int F_172 ( struct V_263 * V_81 , int V_269 )
{
V_81 -> V_196 = ! ! V_269 ;
return 0 ;
}
static T_7 F_173 ( struct V_270 * V_271 , struct V_272 * V_273 ,
const char * V_161 , T_5 V_274 )
{
struct V_1 * V_2 = F_174 ( V_271 ) ;
bool V_275 ;
if ( ! V_2 -> V_79 )
return - V_276 ;
if ( ! strncmp ( V_161 , L_8 , strlen ( L_8 ) ) )
V_275 = true ;
else if ( ! strncmp ( V_161 , L_9 , strlen ( L_9 ) ) )
V_275 = false ;
else
return - V_208 ;
if ( V_275 == F_19 ( V_2 ) )
return - V_208 ;
F_43 ( V_2 , V_275 , F_46 ( V_2 ) ) ;
return V_274 ;
}
static T_7 F_175 ( struct V_270 * V_271 , struct V_272 * V_273 ,
char * V_161 )
{
struct V_1 * V_2 = F_174 ( V_271 ) ;
if ( ! V_2 -> V_79 )
return - V_276 ;
return sprintf ( V_161 , L_10 , F_19 ( V_2 ) ? L_8 : L_9 ) ;
}
static int F_176 ( struct V_277 * V_278 )
{
struct V_1 * V_2 = F_177 ( V_278 ) ;
F_178 ( & V_278 -> V_271 , & V_279 ) ;
F_179 ( & V_2 -> V_81 ) ;
F_155 ( V_2 -> V_191 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 , struct V_270 * V_271 ,
const struct V_280 * V_281 )
{
struct V_106 * V_107 ;
int V_10 ;
V_2 -> V_138 = V_281 -> V_282 * V_281 -> V_283 * 2 /
V_281 -> V_284 + 1 ;
if ( V_2 -> V_138 > V_285 )
V_2 -> V_138 = V_285 ;
V_2 -> V_107 = F_181 ( V_271 , sizeof( * V_107 ) * V_2 -> V_138 ,
V_286 ) ;
if ( ! V_2 -> V_107 )
return - V_287 ;
F_9 ( V_271 , L_11 , V_12 , V_2 -> V_138 ) ;
F_182 (usb3_ep, usb3, i) {
snprintf ( V_107 -> V_288 , sizeof( V_107 -> V_288 ) , L_12 , V_10 ) ;
V_107 -> V_2 = V_2 ;
V_107 -> V_23 = V_10 ;
V_107 -> V_115 . V_289 = V_107 -> V_288 ;
V_107 -> V_115 . V_290 = & V_291 ;
F_154 ( & V_107 -> V_108 ) ;
F_154 ( & V_107 -> V_115 . V_292 ) ;
if ( ! V_10 ) {
V_2 -> V_81 . V_293 = & V_107 -> V_115 ;
F_183 ( & V_107 -> V_115 ,
V_294 ) ;
V_107 -> V_115 . V_295 . V_296 = true ;
V_107 -> V_115 . V_295 . V_120 = true ;
V_107 -> V_115 . V_295 . V_297 = true ;
continue;
}
F_183 ( & V_107 -> V_115 , ~ 0 ) ;
F_101 ( & V_107 -> V_115 . V_292 , & V_2 -> V_81 . V_292 ) ;
V_107 -> V_115 . V_295 . V_298 = true ;
V_107 -> V_115 . V_295 . V_299 = true ;
if ( V_10 & 1 )
V_107 -> V_115 . V_295 . V_120 = true ;
else
V_107 -> V_115 . V_295 . V_297 = true ;
}
return 0 ;
}
static void F_184 ( struct V_1 * V_2 , struct V_270 * V_271 ,
const struct V_280 * V_281 )
{
struct V_106 * V_107 ;
int V_10 ;
T_1 V_300 [ 2 ] , V_301 [ 2 ] ;
T_1 * V_302 , * V_303 ;
T_1 V_7 ;
memset ( V_300 , 0 , sizeof( V_300 ) ) ;
memset ( V_301 , 0 , sizeof( V_301 ) ) ;
F_182 (usb3_ep, usb3, i) {
if ( ! V_10 )
continue;
if ( V_107 -> V_115 . V_295 . V_120 ) {
V_302 = & V_300 [ 0 ] ;
V_303 = & V_301 [ 0 ] ;
} else {
V_302 = & V_300 [ 1 ] ;
V_303 = & V_301 [ 1 ] ;
}
if ( * V_303 > V_281 -> V_282 )
continue;
V_7 = F_185 ( * V_302 ) ;
V_7 |= F_142 ( V_281 -> V_284 ) ;
V_7 |= F_186 ( * V_303 ) ;
V_107 -> V_259 = V_7 ;
F_9 ( V_271 , L_13 ,
V_10 , V_7 , * V_302 , * V_303 ) ;
if ( * V_302 + 1 == V_281 -> V_283 ) {
* V_302 = 0 ;
* V_303 += V_281 -> V_284 ;
} else {
( * V_302 ) ++ ;
}
}
}
static int F_187 ( struct V_277 * V_278 )
{
struct V_1 * V_2 ;
struct V_304 * V_123 ;
const struct V_305 * V_306 ;
int V_238 , V_59 ;
const struct V_280 * V_281 ;
V_306 = F_188 ( V_307 , V_278 -> V_271 . V_308 ) ;
if ( ! V_306 )
return - V_276 ;
V_281 = V_306 -> V_3 ;
V_238 = F_189 ( V_278 , 0 ) ;
if ( V_238 < 0 )
return - V_276 ;
V_2 = F_181 ( & V_278 -> V_271 , sizeof( * V_2 ) , V_286 ) ;
if ( ! V_2 )
return - V_287 ;
V_123 = F_190 ( V_278 , V_309 , 0 ) ;
V_2 -> V_5 = F_191 ( & V_278 -> V_271 , V_123 ) ;
if ( F_192 ( V_2 -> V_5 ) )
return F_193 ( V_2 -> V_5 ) ;
F_194 ( V_278 , V_2 ) ;
F_195 ( & V_2 -> V_89 ) ;
V_2 -> V_81 . V_290 = & V_310 ;
V_2 -> V_81 . V_289 = V_311 ;
V_2 -> V_81 . V_265 = V_98 ;
F_154 ( & V_2 -> V_81 . V_292 ) ;
V_59 = F_180 ( V_2 , & V_278 -> V_271 , V_281 ) ;
if ( V_59 < 0 )
return V_59 ;
F_184 ( V_2 , & V_278 -> V_271 , V_281 ) ;
V_59 = F_196 ( & V_278 -> V_271 , V_238 , F_136 , 0 ,
F_197 ( & V_278 -> V_271 ) , V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
F_198 ( & V_2 -> V_16 , F_11 ) ;
V_2 -> V_17 = F_199 ( & V_278 -> V_271 , V_312 ) ;
if ( F_192 ( V_2 -> V_17 ) )
return F_193 ( V_2 -> V_17 ) ;
V_59 = F_200 ( & V_278 -> V_271 , V_2 -> V_17 ) ;
if ( V_59 < 0 ) {
F_201 ( & V_278 -> V_271 , L_14 ) ;
return V_59 ;
}
V_2 -> V_191 = F_152 ( V_286 ) ;
if ( ! V_2 -> V_191 )
return - V_287 ;
V_59 = F_202 ( & V_278 -> V_271 , & V_2 -> V_81 ) ;
if ( V_59 < 0 )
goto V_313;
V_59 = F_203 ( & V_278 -> V_271 , & V_279 ) ;
if ( V_59 < 0 )
goto V_314;
V_2 -> V_82 = V_281 -> V_82 ;
F_204 ( & V_278 -> V_271 , L_15 ) ;
return 0 ;
V_314:
F_179 ( & V_2 -> V_81 ) ;
V_313:
F_155 ( V_2 -> V_191 ) ;
return V_59 ;
}
