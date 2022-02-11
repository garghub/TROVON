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
F_5 ( V_2 , V_92 |
V_93 | V_94 ,
V_46 ) ;
F_1 ( V_2 , V_91 , V_95 ) ;
F_1 ( V_2 , V_91 , V_96 ) ;
F_47 ( V_2 ) ;
F_39 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_1 ( V_2 , 0 , V_71 ) ;
F_1 ( V_2 , 0 , V_96 ) ;
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
F_5 ( V_2 , V_97 , V_48 ) ;
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
T_1 V_98 = F_3 ( V_2 , V_83 ) & V_99 ;
switch ( V_98 ) {
case V_100 :
V_2 -> V_81 . V_98 = V_101 ;
break;
case V_102 :
V_2 -> V_81 . V_98 = V_103 ;
break;
case V_104 :
V_2 -> V_81 . V_98 = V_105 ;
break;
default:
V_2 -> V_81 . V_98 = V_106 ;
break;
}
}
static void F_59 ( struct V_1 * V_2 , T_1 V_107 )
{
if ( V_107 & V_51 )
F_50 ( V_2 ) ;
if ( V_107 & V_65 )
F_51 ( V_2 ) ;
if ( V_107 & V_73 )
F_56 ( V_2 ) ;
if ( V_107 & V_72 )
F_57 ( V_2 ) ;
if ( V_107 & V_66 )
F_53 ( V_2 ) ;
if ( V_107 & V_76 )
F_54 ( V_2 ) ;
if ( V_107 & V_36 )
F_52 ( V_2 ) ;
if ( V_107 & V_67 )
F_58 ( V_2 ) ;
if ( V_107 & V_33 )
F_55 ( V_2 ) ;
}
static struct V_108 * F_60 ( struct V_109
* V_110 )
{
return F_61 ( & V_110 -> V_111 ,
struct V_108 , V_111 ) ;
}
static struct V_108 * F_62 ( struct V_109
* V_110 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
struct V_108 * V_112 ;
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
V_112 = F_60 ( V_110 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
return V_112 ;
}
static void F_64 ( struct V_109 * V_110 ,
struct V_108 * V_112 ,
int V_113 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
F_9 ( F_10 ( V_2 ) , L_2 ,
V_110 -> V_23 , V_112 -> V_114 . V_115 , V_112 -> V_114 . V_116 ,
V_113 ) ;
V_112 -> V_114 . V_113 = V_113 ;
V_110 -> V_117 = false ;
F_65 ( & V_112 -> V_111 ) ;
F_66 ( & V_2 -> V_89 ) ;
F_67 ( & V_110 -> V_118 , & V_112 -> V_114 ) ;
F_68 ( & V_2 -> V_89 ) ;
}
static void F_69 ( struct V_109 * V_110 ,
struct V_108 * V_112 , int V_113 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
F_64 ( V_110 , V_112 , V_113 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = F_71 ( V_2 , 0 ) ;
struct V_108 * V_112 = F_62 ( V_110 ) ;
if ( V_112 )
F_69 ( V_110 , V_112 , 0 ) ;
if ( V_2 -> V_42 )
F_24 ( V_2 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
struct V_109 * V_110 = F_71 ( V_2 , 0 ) ;
T_1 * V_3 = ( T_1 * ) V_120 ;
* V_3 ++ = F_3 ( V_2 , V_121 ) ;
* V_3 = F_3 ( V_2 , V_122 ) ;
V_110 -> V_123 = ! ! ( V_120 -> V_124 & V_125 ) ;
}
static void F_73 ( struct V_1 * V_2 , T_1 V_126 )
{
T_1 V_7 = F_3 ( V_2 , V_127 ) ;
V_7 &= ~ ( V_128 | V_129 | V_130 ) ;
V_7 |= V_126 | V_131 ;
F_1 ( V_2 , V_7 , V_127 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_132 |
V_133 |
V_134 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_135 |
V_133 |
V_134 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_132 |
V_136 |
V_137 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_135 |
V_136 |
V_137 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_135 |
V_133 |
V_137 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_138 |
V_133 |
V_137 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_132 |
V_139 |
V_140 ) ;
}
static int F_81 ( struct V_1 * V_2 , int V_23 )
{
if ( V_23 == 0 || V_23 > V_2 -> V_141 )
return - V_142 ;
F_1 ( V_2 , V_23 , V_143 ) ;
return 0 ;
}
static void F_82 ( struct V_1 * V_2 , T_1 V_126 )
{
T_1 V_7 = F_3 ( V_2 , V_144 ) ;
V_7 &= ~ V_145 ;
V_7 |= V_126 & V_145 ;
V_7 |= V_146 ;
F_1 ( V_2 , V_7 , V_144 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_82 ( V_2 , V_147 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_82 ( V_2 , V_148 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_82 ( V_2 , V_149 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_150 , V_144 ) ;
return F_7 ( V_2 , V_144 , V_150 , 0 ) ;
}
static bool F_87 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_151 * V_114 = & V_112 -> V_114 ;
if ( ( ! V_114 -> V_152 && V_114 -> V_116 == V_114 -> V_115 ) ||
( V_114 -> V_116 % V_110 -> V_118 . V_153 ) || ( V_114 -> V_115 == 0 ) )
return true ;
else
return false ;
}
static int F_88 ( struct V_109 * V_110 , T_1 V_8 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
T_1 V_154 = V_110 -> V_23 ? V_155 : V_156 ;
return F_7 ( V_2 , V_154 , V_8 , V_8 ) ;
}
static void F_89 ( struct V_109 * V_110 , int V_157 ,
bool V_158 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
T_1 V_159 = V_110 -> V_23 ? V_144 : V_127 ;
T_1 V_7 = F_3 ( V_2 , V_159 ) ;
V_7 |= V_160 | F_90 ( V_157 ) ;
V_7 |= ( V_110 -> V_23 && V_158 ) ? V_161 : 0 ;
F_1 ( V_2 , V_7 , V_159 ) ;
}
static int F_91 ( struct V_109 * V_110 ,
struct V_108 * V_112 ,
T_1 V_162 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
int V_10 ;
int V_163 = F_92 ( unsigned , V_112 -> V_114 . V_115 - V_112 -> V_114 . V_116 ,
V_110 -> V_118 . V_153 ) ;
T_3 * V_164 = V_112 -> V_114 . V_164 + V_112 -> V_114 . V_116 ;
T_1 V_165 = 0 ;
bool V_166 ;
if ( F_88 ( V_110 , V_167 ) < 0 )
return - V_13 ;
V_112 -> V_114 . V_116 += V_163 ;
if ( V_163 >= 4 ) {
F_93 ( V_2 -> V_5 + V_162 , V_164 , V_163 / 4 ) ;
V_164 += ( V_163 / 4 ) * 4 ;
V_163 %= 4 ;
}
if ( V_163 ) {
for ( V_10 = 0 ; V_10 < V_163 ; V_10 ++ )
V_165 |= V_164 [ V_10 ] << ( 8 * V_10 ) ;
F_1 ( V_2 , V_165 , V_162 ) ;
}
V_166 = F_87 ( V_110 , V_112 ) ;
F_89 ( V_110 , V_163 , V_166 ) ;
return V_166 ? 0 : - V_168 ;
}
static T_1 F_94 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
T_1 V_169 = V_110 -> V_23 ? V_170 : V_171 ;
return F_3 ( V_2 , V_169 ) ;
}
static int F_95 ( struct V_109 * V_110 ,
struct V_108 * V_112 , T_1 V_162 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
int V_10 ;
int V_163 = F_92 ( unsigned , V_112 -> V_114 . V_115 - V_112 -> V_114 . V_116 ,
F_94 ( V_110 ) ) ;
T_3 * V_164 = V_112 -> V_114 . V_164 + V_112 -> V_114 . V_116 ;
T_1 V_165 = 0 ;
if ( ! V_163 )
return 0 ;
V_112 -> V_114 . V_116 += V_163 ;
if ( V_163 >= 4 ) {
F_96 ( V_2 -> V_5 + V_162 , V_164 , V_163 / 4 ) ;
V_164 += ( V_163 / 4 ) * 4 ;
V_163 %= 4 ;
}
if ( V_163 ) {
V_165 = F_3 ( V_2 , V_162 ) ;
for ( V_10 = 0 ; V_10 < V_163 ; V_10 ++ )
V_164 [ V_10 ] = ( V_165 >> ( 8 * V_10 ) ) & 0xff ;
}
return F_87 ( V_110 , V_112 ) ? 0 : - V_168 ;
}
static void F_97 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
if ( V_110 -> V_123 ) {
F_75 ( V_2 ) ;
} else {
if ( ! V_112 -> V_114 . V_115 )
F_78 ( V_2 ) ;
else
F_77 ( V_2 ) ;
}
}
static void F_98 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
int V_59 = - V_168 ;
if ( V_110 -> V_123 )
V_59 = F_91 ( V_110 , V_112 , V_172 ) ;
else
V_59 = F_95 ( V_110 , V_112 , V_173 ) ;
if ( ! V_59 )
F_97 ( V_110 , V_112 ) ;
}
static void F_99 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
if ( V_110 -> V_117 )
return;
V_110 -> V_117 = true ;
if ( V_110 -> V_123 ) {
F_5 ( V_2 , V_174 , V_175 ) ;
F_74 ( V_2 ) ;
} else {
F_6 ( V_2 , V_174 , V_175 ) ;
F_76 ( V_2 ) ;
}
F_98 ( V_110 , V_112 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_176 , V_144 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_176 , V_144 ) ;
}
static void F_102 ( struct V_1 * V_2 , int V_23 )
{
F_5 ( V_2 , F_103 ( V_23 ) , V_28 ) ;
}
static void F_104 ( struct V_1 * V_2 , int V_23 )
{
F_6 ( V_2 , F_103 ( V_23 ) , V_28 ) ;
}
static T_1 F_105 ( struct V_109 * V_110 )
{
switch ( V_110 -> V_118 . V_153 ) {
case 8 :
return V_177 ;
case 16 :
return V_178 ;
case 32 :
return V_179 ;
case 64 :
return V_180 ;
case 512 :
return V_181 ;
case 1024 :
return V_182 ;
default:
return V_183 ;
}
}
static bool F_106 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
struct V_184 * V_185 ;
int V_10 ;
bool V_59 = false ;
if ( V_112 -> V_114 . V_115 > V_186 ) {
F_9 ( F_10 ( V_2 ) , L_3 ,
V_12 , V_112 -> V_114 . V_115 ) ;
return false ;
}
if ( ! V_112 -> V_114 . V_115 )
return false ;
if ( F_105 ( V_110 ) == V_183 )
return false ;
F_107 (usb3, dma, i) {
if ( V_185 -> V_187 )
continue;
if ( F_108 ( & V_2 -> V_81 , & V_112 -> V_114 ,
V_110 -> V_123 ) < 0 )
break;
V_185 -> V_187 = true ;
V_110 -> V_185 = V_185 ;
V_59 = true ;
break;
}
return V_59 ;
}
static void F_109 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
int V_10 ;
struct V_184 * V_185 ;
F_107 (usb3, dma, i) {
if ( V_110 -> V_185 == V_185 ) {
F_110 ( & V_2 -> V_81 , & V_112 -> V_114 ,
V_110 -> V_123 ) ;
V_185 -> V_187 = false ;
V_110 -> V_185 = NULL ;
break;
}
}
}
static void F_111 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_188 * V_189 = V_110 -> V_185 -> V_190 ;
T_1 V_191 = V_112 -> V_114 . V_115 ;
T_1 V_185 = V_112 -> V_114 . V_185 ;
T_1 V_163 ;
int V_10 = 0 ;
do {
V_163 = F_92 ( T_1 , V_191 , V_192 ) &
V_193 ;
V_189 -> V_194 = F_105 ( V_110 ) |
V_195 | V_163 ;
V_189 -> V_196 = V_185 ;
V_191 -= V_163 ;
V_185 += V_163 ;
if ( ! V_191 || ( V_10 + 1 ) < V_197 )
break;
V_189 ++ ;
V_10 ++ ;
} while ( 1 );
V_189 -> V_194 |= V_198 | V_199 ;
if ( V_110 -> V_123 )
V_189 -> V_194 |= V_200 ;
}
static void F_112 ( struct V_109 * V_110 )
{
struct V_184 * V_185 = V_110 -> V_185 ;
struct V_1 * V_2 = F_63 ( V_110 ) ;
T_1 V_201 = F_113 ( V_110 -> V_23 ) | V_202 ;
if ( V_110 -> V_123 )
V_201 |= V_203 ;
F_114 () ;
F_1 ( V_2 , 1 << V_110 -> V_23 , V_27 ) ;
F_1 ( V_2 , F_115 ( V_185 -> V_23 ) |
F_116 ( V_185 -> V_23 ) , V_204 ) ;
F_1 ( V_2 , V_185 -> V_205 , F_117 ( V_185 -> V_23 ) ) ;
F_1 ( V_2 , V_201 , F_118 ( V_185 -> V_23 ) ) ;
F_102 ( V_2 , V_110 -> V_23 ) ;
}
static void F_119 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
struct V_184 * V_185 = V_110 -> V_185 ;
F_104 ( V_2 , V_110 -> V_23 ) ;
F_1 ( V_2 , 0 , F_118 ( V_185 -> V_23 ) ) ;
}
static int F_120 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_188 * V_189 = V_110 -> V_185 -> V_190 ;
struct V_151 * V_114 = & V_112 -> V_114 ;
T_1 V_191 , V_163 ;
int V_10 = 0 ;
int V_113 = 0 ;
F_121 () ;
do {
if ( V_189 -> V_194 & V_206 )
V_113 = - V_207 ;
if ( V_189 -> V_194 & V_198 )
V_163 = V_114 -> V_115 % V_192 ;
else
V_163 = V_192 ;
V_191 = V_189 -> V_194 & V_193 ;
V_114 -> V_116 += V_163 - V_191 ;
if ( V_189 -> V_194 & V_198 ||
( V_10 + 1 ) < V_197 )
break;
V_189 ++ ;
V_10 ++ ;
} while ( 1 );
return V_113 ;
}
static bool F_122 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
if ( ! V_208 )
return false ;
if ( F_106 ( V_110 , V_112 ) ) {
F_84 ( V_2 ) ;
F_100 ( V_2 ) ;
F_111 ( V_110 , V_112 ) ;
F_112 ( V_110 ) ;
F_83 ( V_2 ) ;
return true ;
}
return false ;
}
static int F_123 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
unsigned long V_88 ;
int V_113 = 0 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! V_110 -> V_185 )
goto V_209;
if ( ! F_81 ( V_2 , V_110 -> V_23 ) )
F_101 ( V_2 ) ;
F_119 ( V_110 ) ;
V_113 = F_120 ( V_110 , V_112 ) ;
F_109 ( V_110 , V_112 ) ;
V_209:
F_45 ( & V_2 -> V_89 , V_88 ) ;
return V_113 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_210 * V_211 )
{
int V_10 ;
struct V_184 * V_185 ;
F_107 (usb3, dma, i) {
if ( V_185 -> V_190 ) {
F_125 ( V_211 , V_212 ,
V_185 -> V_190 , V_185 -> V_205 ) ;
V_185 -> V_190 = NULL ;
}
}
return 0 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_210 * V_211 )
{
int V_10 ;
struct V_184 * V_185 ;
if ( ! V_208 )
return 0 ;
F_107 (usb3, dma, i) {
V_185 -> V_190 = F_127 ( V_211 , V_212 ,
& V_185 -> V_205 , V_213 ) ;
if ( ! V_185 -> V_190 ) {
F_124 ( V_2 , V_211 ) ;
return - V_214 ;
}
V_185 -> V_23 = V_10 + 1 ;
}
return 0 ;
}
static void F_128 ( struct V_109 * V_110 ,
struct V_108 * V_112 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
struct V_108 * V_215 = F_62 ( V_110 ) ;
unsigned long V_88 ;
int V_59 = - V_168 ;
T_1 V_216 = 0 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( V_110 -> V_217 || V_110 -> V_117 )
goto V_209;
if ( V_112 != V_215 )
goto V_209;
if ( F_81 ( V_2 , V_110 -> V_23 ) < 0 )
goto V_209;
V_110 -> V_117 = true ;
if ( F_122 ( V_110 , V_112 ) )
goto V_209;
F_83 ( V_2 ) ;
if ( V_110 -> V_123 ) {
V_59 = F_91 ( V_110 , V_112 , V_218 ) ;
V_216 |= V_219 ;
}
if ( V_59 < 0 )
V_216 |= V_220 ;
if ( V_216 ) {
F_5 ( V_2 , V_216 , V_221 ) ;
F_16 ( V_2 , V_110 -> V_23 ) ;
}
V_209:
F_45 ( & V_2 -> V_89 , V_88 ) ;
}
static int F_129 ( struct V_222 * V_223 , struct V_151 * V_224 ,
T_4 V_225 )
{
struct V_109 * V_110 = F_130 ( V_223 ) ;
struct V_108 * V_112 = F_131 ( V_224 ) ;
struct V_1 * V_2 = F_63 ( V_110 ) ;
unsigned long V_88 ;
F_9 ( F_10 ( V_2 ) , L_4 , V_110 -> V_23 ,
V_224 -> V_115 ) ;
V_224 -> V_113 = - V_226 ;
V_224 -> V_116 = 0 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
F_132 ( & V_112 -> V_111 , & V_110 -> V_111 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
if ( ! V_110 -> V_23 )
F_99 ( V_110 , V_112 ) ;
else
F_128 ( V_110 , V_112 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 , T_2 V_227 )
{
F_5 ( V_2 , F_134 ( V_227 ) , V_46 ) ;
}
static bool F_135 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
if ( V_120 -> V_228 >= 128 )
return true ;
F_133 ( V_2 , V_120 -> V_228 ) ;
F_78 ( V_2 ) ;
return false ;
}
static void F_136 ( struct V_1 * V_2 ,
void * V_229 , T_5 V_163 ,
void (* F_137)( struct V_222 * V_118 ,
struct V_151 * V_114 ) )
{
struct V_109 * V_110 = F_71 ( V_2 , 0 ) ;
if ( V_229 )
memcpy ( V_2 -> V_230 , V_229 ,
F_92 ( T_5 , V_163 , V_231 ) ) ;
V_2 -> V_232 -> V_164 = & V_2 -> V_230 ;
V_2 -> V_232 -> V_115 = V_163 ;
V_2 -> V_232 -> F_137 = F_137 ;
F_129 ( & V_110 -> V_118 , V_2 -> V_232 , V_233 ) ;
}
static void F_138 ( struct V_222 * V_118 ,
struct V_151 * V_114 )
{
}
static bool F_139 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
bool V_234 = false ;
struct V_109 * V_110 ;
int V_23 ;
T_2 V_113 = 0 ;
switch ( V_120 -> V_124 & V_235 ) {
case V_236 :
if ( V_2 -> V_81 . V_237 )
V_113 |= 1 << V_238 ;
if ( V_2 -> V_81 . V_98 == V_101 )
V_113 |= F_29 ( V_2 ) ;
break;
case V_239 :
break;
case V_240 :
V_23 = F_140 ( V_120 -> V_241 ) & V_242 ;
V_110 = F_71 ( V_2 , V_23 ) ;
if ( V_110 -> V_217 )
V_113 |= 1 << V_243 ;
break;
default:
V_234 = true ;
break;
}
if ( ! V_234 ) {
V_113 = F_141 ( V_113 ) ;
F_9 ( F_10 ( V_2 ) , L_5 ,
F_131 ( V_2 -> V_232 ) ) ;
F_136 ( V_2 , & V_113 , sizeof( V_113 ) ,
F_138 ) ;
}
return V_234 ;
}
static bool F_142 ( struct V_1 * V_2 ,
struct V_119 * V_120 , bool V_244 )
{
bool V_234 = true ;
T_2 V_245 = F_140 ( V_120 -> V_228 ) ;
switch ( V_245 ) {
case V_246 :
if ( ! V_244 )
break;
V_2 -> V_42 = F_140 ( V_120 -> V_241 ) >> 8 ;
V_234 = false ;
break;
case V_247 :
case V_248 :
if ( V_2 -> V_81 . V_98 != V_101 )
break;
if ( V_245 == V_247 )
F_31 ( V_2 , V_244 ) ;
if ( V_245 == V_248 )
F_30 ( V_2 , V_244 ) ;
V_234 = false ;
break;
default:
break;
}
return V_234 ;
}
static int F_143 ( struct V_109 * V_110 , bool V_217 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
if ( F_144 ( V_110 -> V_23 ) )
return - V_249 ;
V_110 -> V_217 = V_217 ;
if ( V_217 )
F_79 ( V_2 ) ;
else
F_80 ( V_2 ) ;
return 0 ;
}
static int F_145 ( struct V_109 * V_110 , bool V_217 ,
bool V_250 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_81 ( V_2 , V_110 -> V_23 ) ) {
V_110 -> V_217 = V_217 ;
if ( V_217 ) {
F_85 ( V_2 ) ;
} else if ( ! V_250 || ! V_110 -> V_251 ) {
F_86 ( V_2 ) ;
F_5 ( V_2 , V_252 , V_144 ) ;
F_84 ( V_2 ) ;
}
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_146 ( struct V_109 * V_110 , bool V_217 ,
bool V_250 )
{
int V_59 = 0 ;
if ( V_217 && V_110 -> V_117 )
return - V_168 ;
if ( V_110 -> V_23 )
V_59 = F_145 ( V_110 , V_217 , V_250 ) ;
else
V_59 = F_143 ( V_110 , V_217 ) ;
return V_59 ;
}
static bool F_147 ( struct V_1 * V_2 ,
struct V_119 * V_120 ,
bool V_244 )
{
int V_23 = F_140 ( V_120 -> V_241 ) & V_242 ;
struct V_109 * V_110 ;
struct V_108 * V_112 ;
if ( F_140 ( V_120 -> V_228 ) != V_243 )
return true ;
V_110 = F_71 ( V_2 , V_23 ) ;
F_146 ( V_110 , V_244 , true ) ;
if ( ! V_244 ) {
V_110 -> V_117 = false ;
V_112 = F_62 ( V_110 ) ;
if ( V_112 )
F_128 ( V_110 , V_112 ) ;
}
return false ;
}
static bool F_148 ( struct V_1 * V_2 ,
struct V_119 * V_120 , bool V_244 )
{
bool V_234 = false ;
switch ( V_120 -> V_124 & V_235 ) {
case V_236 :
V_234 = F_142 ( V_2 , V_120 , V_244 ) ;
break;
case V_239 :
break;
case V_240 :
V_234 = F_147 ( V_2 , V_120 , V_244 ) ;
break;
default:
V_234 = true ;
break;
}
if ( ! V_234 )
F_78 ( V_2 ) ;
return V_234 ;
}
static void F_149 ( struct V_222 * V_118 ,
struct V_151 * V_114 )
{
}
static bool F_150 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
T_2 V_253 = F_140 ( V_120 -> V_254 ) ;
if ( V_253 != 6 )
return true ;
F_9 ( F_10 ( V_2 ) , L_6 ,
F_131 ( V_2 -> V_232 ) ) ;
F_136 ( V_2 , NULL , 6 , F_149 ) ;
return false ;
}
static bool F_151 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
if ( V_120 -> V_228 > 0 )
F_5 ( V_2 , V_77 , V_46 ) ;
else
F_6 ( V_2 , V_77 , V_46 ) ;
return false ;
}
static bool F_152 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
bool V_59 = false ;
bool V_234 = false ;
if ( ( V_120 -> V_124 & V_255 ) == V_256 ) {
switch ( V_120 -> V_257 ) {
case V_258 :
V_234 = F_135 ( V_2 , V_120 ) ;
V_59 = true ;
break;
case V_259 :
V_234 = F_139 ( V_2 , V_120 ) ;
V_59 = true ;
break;
case V_260 :
V_234 = F_148 ( V_2 , V_120 , false ) ;
V_59 = true ;
break;
case V_261 :
V_234 = F_148 ( V_2 , V_120 , true ) ;
V_59 = true ;
break;
case V_262 :
V_234 = F_150 ( V_2 , V_120 ) ;
V_59 = true ;
break;
case V_263 :
V_234 = true ;
V_59 = true ;
break;
case V_264 :
F_151 ( V_2 , V_120 ) ;
break;
default:
break;
}
}
if ( V_234 )
F_79 ( V_2 ) ;
return V_59 ;
}
static int F_153 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_265 , V_127 ) ;
return F_7 ( V_2 , V_127 , V_265 , 0 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_119 V_120 ;
struct V_109 * V_110 = F_71 ( V_2 , 0 ) ;
if ( V_110 -> V_117 )
F_69 ( V_110 , F_62 ( V_110 ) ,
- V_266 ) ;
F_153 ( V_2 ) ;
F_72 ( V_2 , & V_120 ) ;
if ( ! F_152 ( V_2 , & V_120 ) )
if ( V_2 -> V_79 -> V_267 ( & V_2 -> V_81 , & V_120 ) < 0 )
F_79 ( V_2 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_109 * V_110 = F_71 ( V_2 , 0 ) ;
struct V_108 * V_112 = F_62 ( V_110 ) ;
if ( ! V_112 )
return;
F_98 ( V_110 , V_112 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
T_1 V_268 = F_3 ( V_2 , V_70 ) ;
V_268 &= F_3 ( V_2 , V_71 ) ;
F_1 ( V_2 , V_268 , V_70 ) ;
if ( V_268 & V_269 )
F_70 ( V_2 ) ;
if ( V_268 & V_270 )
F_154 ( V_2 ) ;
if ( V_268 & V_271 )
F_155 ( V_2 ) ;
}
static void F_157 ( struct V_1 * V_2 ,
struct V_109 * V_110 ,
struct V_108 * V_112 ,
int V_113 )
{
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( F_81 ( V_2 , V_110 -> V_23 ) )
F_84 ( V_2 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
F_18 ( V_2 , V_110 -> V_23 ) ;
F_69 ( V_110 , V_112 , V_113 ) ;
V_112 = F_62 ( V_110 ) ;
if ( V_112 )
F_128 ( V_110 , V_112 ) ;
}
static void F_158 ( struct V_1 * V_2 , int V_23 )
{
struct V_109 * V_110 = F_71 ( V_2 , V_23 ) ;
struct V_108 * V_112 = F_62 ( V_110 ) ;
if ( ! V_112 )
return;
if ( V_110 -> V_123 ) {
F_9 ( F_10 ( V_2 ) , L_7 ,
V_12 , V_112 -> V_114 . V_115 , V_112 -> V_114 . V_116 ) ;
F_157 ( V_2 , V_110 , V_112 , 0 ) ;
}
}
static void F_159 ( struct V_1 * V_2 , int V_23 )
{
struct V_109 * V_110 = F_71 ( V_2 , V_23 ) ;
struct V_108 * V_112 = F_62 ( V_110 ) ;
bool V_272 = false ;
if ( ! V_112 )
return;
F_68 ( & V_2 -> V_89 ) ;
if ( F_81 ( V_2 , V_23 ) )
goto V_209;
if ( V_110 -> V_123 ) {
if ( ! F_91 ( V_110 , V_112 , V_218 ) )
F_6 ( V_2 , V_220 , V_221 ) ;
} else {
if ( ! F_95 ( V_110 , V_112 , V_273 ) )
V_272 = true ;
}
V_209:
F_66 ( & V_2 -> V_89 ) ;
if ( V_272 )
F_157 ( V_2 , V_110 , V_112 , 0 ) ;
}
static void F_160 ( struct V_1 * V_2 , int V_23 )
{
T_1 V_274 ;
F_68 ( & V_2 -> V_89 ) ;
if ( F_81 ( V_2 , V_23 ) < 0 ) {
F_66 ( & V_2 -> V_89 ) ;
return;
}
V_274 = F_3 ( V_2 , V_275 ) ;
V_274 &= F_3 ( V_2 , V_221 ) ;
F_1 ( V_2 , V_274 , V_275 ) ;
F_66 ( & V_2 -> V_89 ) ;
if ( V_274 & V_219 )
F_158 ( V_2 , V_23 ) ;
if ( V_274 & V_220 )
F_159 ( V_2 , V_23 ) ;
}
static void F_161 ( struct V_1 * V_2 , T_1 V_276 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_141 ; V_10 ++ ) {
if ( V_276 & F_17 ( V_10 ) ) {
if ( ! V_10 )
F_156 ( V_2 ) ;
else
F_160 ( V_2 , V_10 ) ;
}
}
}
static void F_162 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
}
static void F_163 ( struct V_1 * V_2 , T_1 V_277 )
{
if ( V_277 & V_91 )
F_162 ( V_2 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
T_1 V_107 = F_3 ( V_2 , V_32 ) ;
T_1 V_276 = F_3 ( V_2 , V_278 ) ;
T_1 V_277 = F_3 ( V_2 , V_95 ) ;
V_107 &= F_3 ( V_2 , V_22 ) ;
if ( V_107 ) {
F_1 ( V_2 , V_107 , V_32 ) ;
F_59 ( V_2 , V_107 ) ;
}
V_276 &= F_3 ( V_2 , V_24 ) ;
if ( V_276 )
F_161 ( V_2 , V_276 ) ;
V_277 &= F_3 ( V_2 , V_96 ) ;
if ( V_277 ) {
F_1 ( V_2 , V_277 , V_95 ) ;
F_163 ( V_2 , V_277 ) ;
}
}
static void F_165 ( struct V_1 * V_2 , T_1 V_279 )
{
struct V_109 * V_110 ;
struct V_108 * V_112 ;
int V_10 , V_113 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_141 ; V_10 ++ ) {
if ( ! ( V_279 & F_103 ( V_10 ) ) )
continue;
V_110 = F_71 ( V_2 , V_10 ) ;
if ( ! ( F_3 ( V_2 , V_204 ) &
F_115 ( V_110 -> V_185 -> V_23 ) ) )
continue;
V_112 = F_62 ( V_110 ) ;
V_113 = F_123 ( V_110 , V_112 ) ;
F_157 ( V_2 , V_110 , V_112 , V_113 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
T_1 V_279 = F_3 ( V_2 , V_27 ) ;
V_279 &= F_3 ( V_2 , V_28 ) ;
if ( V_279 ) {
F_1 ( V_2 , V_279 , V_27 ) ;
F_165 ( V_2 , V_279 ) ;
}
}
static T_6 F_167 ( int V_280 , void * V_281 )
{
struct V_1 * V_2 = V_281 ;
T_6 V_59 = V_282 ;
T_1 V_283 = F_3 ( V_2 , V_204 ) ;
if ( V_283 & V_29 ) {
F_166 ( V_2 ) ;
V_59 = V_284 ;
}
if ( V_283 & V_30 ) {
F_164 ( V_2 ) ;
V_59 = V_284 ;
}
return V_59 ;
}
static void F_168 ( struct V_109 * V_110 ,
const struct V_285 * V_286 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
T_1 V_7 = 0 ;
V_7 |= V_110 -> V_123 ? V_287 : 0 ;
V_7 |= F_169 ( F_170 ( V_286 ) ) ;
V_7 |= F_171 ( F_172 ( V_286 ) ) ;
F_1 ( V_2 , V_7 , V_288 ) ;
}
static T_1 F_173 ( int V_289 )
{
F_174 ( V_289 > V_290 ) ;
if ( V_289 <= V_291 )
return V_292 ;
else if ( V_289 <= V_293 )
return V_294 ;
else if ( V_289 <= V_295 )
return V_296 ;
else if ( V_289 <= V_297 )
return V_298 ;
else
return V_299 ;
}
static T_1 F_175 ( struct V_109 * V_110 ,
const struct V_285 * V_286 )
{
return V_110 -> V_300 | F_176 ( F_177 ( V_286 ) ) ;
}
static int F_178 ( struct V_109 * V_110 ,
const struct V_285 * V_286 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
unsigned long V_88 ;
V_110 -> V_123 = F_179 ( V_286 ) ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_81 ( V_2 , V_110 -> V_23 ) ) {
F_168 ( V_110 , V_286 ) ;
F_1 ( V_2 , F_175 ( V_110 , V_286 ) ,
V_301 ) ;
F_86 ( V_2 ) ;
F_5 ( V_2 , V_252 , V_144 ) ;
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_180 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = F_63 ( V_110 ) ;
unsigned long V_88 ;
V_110 -> V_217 = false ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_81 ( V_2 , V_110 -> V_23 ) ) {
F_1 ( V_2 , 0 , V_221 ) ;
F_1 ( V_2 , 0 , V_301 ) ;
F_6 ( V_2 , V_252 , V_144 ) ;
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_181 ( struct V_222 * V_223 ,
const struct V_285 * V_286 )
{
struct V_109 * V_110 = F_130 ( V_223 ) ;
return F_178 ( V_110 , V_286 ) ;
}
static int F_182 ( struct V_222 * V_223 )
{
struct V_109 * V_110 = F_130 ( V_223 ) ;
struct V_108 * V_112 ;
do {
V_112 = F_62 ( V_110 ) ;
if ( ! V_112 )
break;
F_123 ( V_110 , V_112 ) ;
F_69 ( V_110 , V_112 , - V_302 ) ;
} while ( 1 );
return F_180 ( V_110 ) ;
}
static struct V_151 * F_183 ( T_4 V_225 )
{
struct V_108 * V_112 ;
V_112 = F_184 ( sizeof( struct V_108 ) , V_225 ) ;
if ( ! V_112 )
return NULL ;
F_185 ( & V_112 -> V_111 ) ;
return & V_112 -> V_114 ;
}
static void F_186 ( struct V_151 * V_224 )
{
struct V_108 * V_112 = F_131 ( V_224 ) ;
F_187 ( V_112 ) ;
}
static struct V_151 * F_188 ( struct V_222 * V_223 ,
T_4 V_225 )
{
return F_183 ( V_225 ) ;
}
static void F_189 ( struct V_222 * V_223 ,
struct V_151 * V_224 )
{
F_186 ( V_224 ) ;
}
static int F_190 ( struct V_222 * V_223 , struct V_151 * V_224 )
{
struct V_109 * V_110 = F_130 ( V_223 ) ;
struct V_108 * V_112 = F_131 ( V_224 ) ;
struct V_1 * V_2 = F_63 ( V_110 ) ;
F_9 ( F_10 ( V_2 ) , L_8 , V_110 -> V_23 ,
V_224 -> V_115 ) ;
F_123 ( V_110 , V_112 ) ;
F_157 ( V_2 , V_110 , V_112 , - V_266 ) ;
return 0 ;
}
static int F_191 ( struct V_222 * V_223 , int V_303 )
{
return F_146 ( F_130 ( V_223 ) , ! ! V_303 , false ) ;
}
static int F_192 ( struct V_222 * V_223 )
{
struct V_109 * V_110 = F_130 ( V_223 ) ;
V_110 -> V_251 = true ;
return F_146 ( V_110 , true , false ) ;
}
static void F_193 ( struct V_222 * V_223 )
{
struct V_109 * V_110 = F_130 ( V_223 ) ;
struct V_1 * V_2 = F_63 ( V_110 ) ;
unsigned long V_88 ;
if ( V_110 -> V_23 ) {
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_81 ( V_2 , V_110 -> V_23 ) ) {
F_86 ( V_2 ) ;
F_5 ( V_2 , V_252 , V_144 ) ;
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
} else {
F_153 ( V_2 ) ;
}
}
static int F_194 ( struct V_304 * V_81 ,
struct V_305 * V_79 )
{
struct V_1 * V_2 ;
if ( ! V_79 || V_79 -> V_306 < V_105 ||
! V_79 -> V_267 )
return - V_249 ;
V_2 = F_195 ( V_81 ) ;
V_2 -> V_79 = V_79 ;
F_196 ( F_10 ( V_2 ) ) ;
F_197 ( F_10 ( V_2 ) ) ;
F_48 ( V_2 ) ;
return 0 ;
}
static int F_198 ( struct V_304 * V_81 )
{
struct V_1 * V_2 = F_195 ( V_81 ) ;
V_2 -> V_40 = false ;
V_2 -> V_81 . V_98 = V_106 ;
V_2 -> V_79 = NULL ;
F_49 ( V_2 ) ;
F_199 ( F_10 ( V_2 ) ) ;
F_200 ( F_10 ( V_2 ) ) ;
return 0 ;
}
static int F_201 ( struct V_304 * V_307 )
{
return - V_308 ;
}
static int F_202 ( struct V_304 * V_81 , int V_309 )
{
struct V_1 * V_2 = F_195 ( V_81 ) ;
V_2 -> V_40 = ! ! V_309 ;
return 0 ;
}
static int F_203 ( struct V_304 * V_81 , int V_310 )
{
V_81 -> V_237 = ! ! V_310 ;
return 0 ;
}
static T_7 F_204 ( struct V_210 * V_211 , struct V_311 * V_312 ,
const char * V_164 , T_5 V_313 )
{
struct V_1 * V_2 = F_205 ( V_211 ) ;
bool V_314 ;
if ( ! V_2 -> V_79 )
return - V_315 ;
if ( ! strncmp ( V_164 , L_9 , strlen ( L_9 ) ) )
V_314 = true ;
else if ( ! strncmp ( V_164 , L_10 , strlen ( L_10 ) ) )
V_314 = false ;
else
return - V_249 ;
if ( V_314 == F_19 ( V_2 ) )
return - V_249 ;
F_43 ( V_2 , V_314 , F_46 ( V_2 ) ) ;
return V_313 ;
}
static T_7 F_206 ( struct V_210 * V_211 , struct V_311 * V_312 ,
char * V_164 )
{
struct V_1 * V_2 = F_205 ( V_211 ) ;
if ( ! V_2 -> V_79 )
return - V_315 ;
return sprintf ( V_164 , L_11 , F_19 ( V_2 ) ? L_9 : L_10 ) ;
}
static int F_207 ( struct V_316 * V_317 )
{
struct V_1 * V_2 = F_208 ( V_317 ) ;
F_209 ( & V_317 -> V_211 , & V_318 ) ;
F_210 ( & V_2 -> V_81 ) ;
F_124 ( V_2 , & V_317 -> V_211 ) ;
F_186 ( V_2 -> V_232 ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 , struct V_210 * V_211 ,
const struct V_319 * V_320 )
{
struct V_109 * V_110 ;
int V_10 ;
V_2 -> V_141 = V_320 -> V_321 * V_320 -> V_322 * 2 /
V_320 -> V_323 + 1 ;
if ( V_2 -> V_141 > V_324 )
V_2 -> V_141 = V_324 ;
V_2 -> V_110 = F_212 ( V_211 , sizeof( * V_110 ) * V_2 -> V_141 ,
V_213 ) ;
if ( ! V_2 -> V_110 )
return - V_214 ;
F_9 ( V_211 , L_12 , V_12 , V_2 -> V_141 ) ;
F_213 (usb3_ep, usb3, i) {
snprintf ( V_110 -> V_325 , sizeof( V_110 -> V_325 ) , L_13 , V_10 ) ;
V_110 -> V_2 = V_2 ;
V_110 -> V_23 = V_10 ;
V_110 -> V_118 . V_326 = V_110 -> V_325 ;
V_110 -> V_118 . V_327 = & V_328 ;
F_185 ( & V_110 -> V_111 ) ;
F_185 ( & V_110 -> V_118 . V_329 ) ;
if ( ! V_10 ) {
V_2 -> V_81 . V_330 = & V_110 -> V_118 ;
F_214 ( & V_110 -> V_118 ,
V_331 ) ;
V_110 -> V_118 . V_332 . V_333 = true ;
V_110 -> V_118 . V_332 . V_123 = true ;
V_110 -> V_118 . V_332 . V_334 = true ;
continue;
}
F_214 ( & V_110 -> V_118 , ~ 0 ) ;
F_132 ( & V_110 -> V_118 . V_329 , & V_2 -> V_81 . V_329 ) ;
V_110 -> V_118 . V_332 . V_335 = true ;
V_110 -> V_118 . V_332 . V_336 = true ;
if ( V_10 & 1 )
V_110 -> V_118 . V_332 . V_123 = true ;
else
V_110 -> V_118 . V_332 . V_334 = true ;
}
return 0 ;
}
static void F_215 ( struct V_1 * V_2 , struct V_210 * V_211 ,
const struct V_319 * V_320 )
{
struct V_109 * V_110 ;
int V_10 ;
T_1 V_337 [ 2 ] , V_338 [ 2 ] ;
T_1 * V_339 , * V_340 ;
T_1 V_7 ;
memset ( V_337 , 0 , sizeof( V_337 ) ) ;
memset ( V_338 , 0 , sizeof( V_338 ) ) ;
F_213 (usb3_ep, usb3, i) {
if ( ! V_10 )
continue;
if ( V_110 -> V_118 . V_332 . V_123 ) {
V_339 = & V_337 [ 0 ] ;
V_340 = & V_338 [ 0 ] ;
} else {
V_339 = & V_337 [ 1 ] ;
V_340 = & V_338 [ 1 ] ;
}
if ( * V_340 > V_320 -> V_321 )
continue;
V_7 = F_216 ( * V_339 ) ;
V_7 |= F_173 ( V_320 -> V_323 ) ;
V_7 |= F_217 ( * V_340 ) ;
V_110 -> V_300 = V_7 ;
F_9 ( V_211 , L_14 ,
V_10 , V_7 , * V_339 , * V_340 ) ;
if ( * V_339 + 1 == V_320 -> V_322 ) {
* V_339 = 0 ;
* V_340 += V_320 -> V_323 ;
} else {
( * V_339 ) ++ ;
}
}
}
static int F_218 ( struct V_316 * V_317 )
{
struct V_1 * V_2 ;
struct V_341 * V_126 ;
const struct V_342 * V_343 ;
int V_280 , V_59 ;
const struct V_319 * V_320 ;
V_343 = F_219 ( V_344 , V_317 -> V_211 . V_345 ) ;
if ( ! V_343 )
return - V_315 ;
V_320 = V_343 -> V_3 ;
V_280 = F_220 ( V_317 , 0 ) ;
if ( V_280 < 0 )
return - V_315 ;
V_2 = F_212 ( & V_317 -> V_211 , sizeof( * V_2 ) , V_213 ) ;
if ( ! V_2 )
return - V_214 ;
V_126 = F_221 ( V_317 , V_346 , 0 ) ;
V_2 -> V_5 = F_222 ( & V_317 -> V_211 , V_126 ) ;
if ( F_223 ( V_2 -> V_5 ) )
return F_224 ( V_2 -> V_5 ) ;
F_225 ( V_317 , V_2 ) ;
F_226 ( & V_2 -> V_89 ) ;
V_2 -> V_81 . V_327 = & V_347 ;
V_2 -> V_81 . V_326 = V_348 ;
V_2 -> V_81 . V_306 = V_101 ;
F_185 ( & V_2 -> V_81 . V_329 ) ;
V_59 = F_211 ( V_2 , & V_317 -> V_211 , V_320 ) ;
if ( V_59 < 0 )
return V_59 ;
F_215 ( V_2 , & V_317 -> V_211 , V_320 ) ;
V_59 = F_227 ( & V_317 -> V_211 , V_280 , F_167 , 0 ,
F_228 ( & V_317 -> V_211 ) , V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
F_229 ( & V_2 -> V_16 , F_11 ) ;
V_2 -> V_17 = F_230 ( & V_317 -> V_211 , V_349 ) ;
if ( F_223 ( V_2 -> V_17 ) )
return F_224 ( V_2 -> V_17 ) ;
V_59 = F_231 ( & V_317 -> V_211 , V_2 -> V_17 ) ;
if ( V_59 < 0 ) {
F_232 ( & V_317 -> V_211 , L_15 ) ;
return V_59 ;
}
V_2 -> V_232 = F_183 ( V_213 ) ;
if ( ! V_2 -> V_232 )
return - V_214 ;
V_59 = F_126 ( V_2 , & V_317 -> V_211 ) ;
if ( V_59 < 0 )
goto V_350;
V_59 = F_233 ( & V_317 -> V_211 , & V_2 -> V_81 ) ;
if ( V_59 < 0 )
goto V_351;
V_59 = F_234 ( & V_317 -> V_211 , & V_318 ) ;
if ( V_59 < 0 )
goto V_352;
V_2 -> V_82 = V_320 -> V_82 ;
F_235 ( & V_317 -> V_211 , L_16 ) ;
return 0 ;
V_352:
F_210 ( & V_2 -> V_81 ) ;
V_351:
F_124 ( V_2 , & V_317 -> V_211 ) ;
V_350:
F_186 ( V_2 -> V_232 ) ;
return V_59 ;
}
