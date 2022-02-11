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
if ( ( ! V_85 && V_87 ) ||
( V_2 -> V_82 && V_2 -> V_90 ) )
F_36 ( V_2 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
}
static bool F_46 ( struct V_1 * V_2 )
{
return ! ( F_3 ( V_2 , V_91 ) & V_92 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_19 = F_46 ( V_2 ) ;
if ( V_2 -> V_19 && ! V_2 -> V_90 )
F_43 ( V_2 , true , true ) ;
else
F_43 ( V_2 , false , false ) ;
F_40 ( & V_2 -> V_16 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_5 ( V_2 , V_93 |
V_94 | V_95 ,
V_46 ) ;
F_1 ( V_2 , V_92 , V_96 ) ;
F_1 ( V_2 , V_92 , V_97 ) ;
F_47 ( V_2 ) ;
F_39 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_1 ( V_2 , 0 , V_71 ) ;
F_1 ( V_2 , 0 , V_97 ) ;
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
F_5 ( V_2 , V_98 , V_48 ) ;
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
T_1 V_99 = F_3 ( V_2 , V_83 ) & V_100 ;
switch ( V_99 ) {
case V_101 :
V_2 -> V_81 . V_99 = V_102 ;
break;
case V_103 :
V_2 -> V_81 . V_99 = V_104 ;
break;
case V_105 :
V_2 -> V_81 . V_99 = V_106 ;
break;
default:
V_2 -> V_81 . V_99 = V_107 ;
break;
}
}
static void F_59 ( struct V_1 * V_2 , T_1 V_108 )
{
if ( V_108 & V_51 )
F_50 ( V_2 ) ;
if ( V_108 & V_65 )
F_51 ( V_2 ) ;
if ( V_108 & V_73 )
F_56 ( V_2 ) ;
if ( V_108 & V_72 )
F_57 ( V_2 ) ;
if ( V_108 & V_66 )
F_53 ( V_2 ) ;
if ( V_108 & V_76 )
F_54 ( V_2 ) ;
if ( V_108 & V_36 )
F_52 ( V_2 ) ;
if ( V_108 & V_67 )
F_58 ( V_2 ) ;
if ( V_108 & V_33 )
F_55 ( V_2 ) ;
}
static struct V_109 * F_60 ( struct V_110
* V_111 )
{
return F_61 ( & V_111 -> V_112 ,
struct V_109 , V_112 ) ;
}
static struct V_109 * F_62 ( struct V_110
* V_111 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
struct V_109 * V_113 ;
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
V_113 = F_60 ( V_111 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
return V_113 ;
}
static void F_64 ( struct V_110 * V_111 ,
struct V_109 * V_113 ,
int V_114 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
F_9 ( F_10 ( V_2 ) , L_2 ,
V_111 -> V_23 , V_113 -> V_115 . V_116 , V_113 -> V_115 . V_117 ,
V_114 ) ;
V_113 -> V_115 . V_114 = V_114 ;
V_111 -> V_118 = false ;
F_65 ( & V_113 -> V_112 ) ;
F_66 ( & V_2 -> V_89 ) ;
F_67 ( & V_111 -> V_119 , & V_113 -> V_115 ) ;
F_68 ( & V_2 -> V_89 ) ;
}
static void F_69 ( struct V_110 * V_111 ,
struct V_109 * V_113 , int V_114 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
F_64 ( V_111 , V_113 , V_114 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = F_71 ( V_2 , 0 ) ;
struct V_109 * V_113 = F_62 ( V_111 ) ;
if ( V_113 )
F_69 ( V_111 , V_113 , 0 ) ;
if ( V_2 -> V_42 )
F_24 ( V_2 ) ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_110 * V_111 = F_71 ( V_2 , 0 ) ;
T_1 * V_3 = ( T_1 * ) V_121 ;
* V_3 ++ = F_3 ( V_2 , V_122 ) ;
* V_3 = F_3 ( V_2 , V_123 ) ;
V_111 -> V_124 = ! ! ( V_121 -> V_125 & V_126 ) ;
}
static void F_73 ( struct V_1 * V_2 , T_1 V_127 )
{
T_1 V_7 = F_3 ( V_2 , V_128 ) ;
V_7 &= ~ ( V_129 | V_130 | V_131 ) ;
V_7 |= V_127 | V_132 ;
F_1 ( V_2 , V_7 , V_128 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_133 |
V_134 |
V_135 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_136 |
V_134 |
V_135 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_133 |
V_137 |
V_138 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_136 |
V_137 |
V_138 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_136 |
V_134 |
V_138 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_139 |
V_134 |
V_138 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_73 ( V_2 , V_133 |
V_140 |
V_141 ) ;
}
static int F_81 ( struct V_1 * V_2 , int V_23 )
{
if ( V_23 == 0 || V_23 > V_2 -> V_142 )
return - V_143 ;
F_1 ( V_2 , V_23 , V_144 ) ;
return 0 ;
}
static void F_82 ( struct V_1 * V_2 , T_1 V_127 )
{
T_1 V_7 = F_3 ( V_2 , V_145 ) ;
V_7 &= ~ V_146 ;
V_7 |= V_127 & V_146 ;
V_7 |= V_147 ;
F_1 ( V_2 , V_7 , V_145 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_82 ( V_2 , V_148 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_82 ( V_2 , V_149 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_82 ( V_2 , V_150 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_151 , V_145 ) ;
return F_7 ( V_2 , V_145 , V_151 , 0 ) ;
}
static bool F_87 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_152 * V_115 = & V_113 -> V_115 ;
if ( ( ! V_115 -> V_153 && V_115 -> V_117 == V_115 -> V_116 ) ||
( V_115 -> V_117 % V_111 -> V_119 . V_154 ) || ( V_115 -> V_116 == 0 ) )
return true ;
else
return false ;
}
static int F_88 ( struct V_110 * V_111 , T_1 V_8 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
T_1 V_155 = V_111 -> V_23 ? V_156 : V_157 ;
return F_7 ( V_2 , V_155 , V_8 , V_8 ) ;
}
static void F_89 ( struct V_110 * V_111 , int V_158 ,
bool V_159 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
T_1 V_160 = V_111 -> V_23 ? V_145 : V_128 ;
T_1 V_7 = F_3 ( V_2 , V_160 ) ;
V_7 |= V_161 | F_90 ( V_158 ) ;
V_7 |= ( V_111 -> V_23 && V_159 ) ? V_162 : 0 ;
F_1 ( V_2 , V_7 , V_160 ) ;
}
static int F_91 ( struct V_110 * V_111 ,
struct V_109 * V_113 ,
T_1 V_163 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
int V_10 ;
int V_164 = F_92 ( unsigned , V_113 -> V_115 . V_116 - V_113 -> V_115 . V_117 ,
V_111 -> V_119 . V_154 ) ;
T_3 * V_165 = V_113 -> V_115 . V_165 + V_113 -> V_115 . V_117 ;
T_1 V_166 = 0 ;
bool V_167 = ! V_164 ? true : false ;
if ( F_88 ( V_111 , V_168 ) < 0 )
return - V_13 ;
V_113 -> V_115 . V_117 += V_164 ;
if ( V_164 >= 4 ) {
F_93 ( V_2 -> V_5 + V_163 , V_165 , V_164 / 4 ) ;
V_165 += ( V_164 / 4 ) * 4 ;
V_164 %= 4 ;
}
if ( V_164 ) {
for ( V_10 = 0 ; V_10 < V_164 ; V_10 ++ )
V_166 |= V_165 [ V_10 ] << ( 8 * V_10 ) ;
F_1 ( V_2 , V_166 , V_163 ) ;
}
if ( ! V_167 )
V_167 = F_87 ( V_111 , V_113 ) ;
F_89 ( V_111 , V_164 , V_167 ) ;
return V_167 ? 0 : - V_169 ;
}
static T_1 F_94 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
T_1 V_170 = V_111 -> V_23 ? V_171 : V_172 ;
return F_3 ( V_2 , V_170 ) ;
}
static int F_95 ( struct V_110 * V_111 ,
struct V_109 * V_113 , T_1 V_163 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
int V_10 ;
int V_164 = F_92 ( unsigned , V_113 -> V_115 . V_116 - V_113 -> V_115 . V_117 ,
F_94 ( V_111 ) ) ;
T_3 * V_165 = V_113 -> V_115 . V_165 + V_113 -> V_115 . V_117 ;
T_1 V_166 = 0 ;
if ( ! V_164 )
return 0 ;
V_113 -> V_115 . V_117 += V_164 ;
if ( V_164 >= 4 ) {
F_96 ( V_2 -> V_5 + V_163 , V_165 , V_164 / 4 ) ;
V_165 += ( V_164 / 4 ) * 4 ;
V_164 %= 4 ;
}
if ( V_164 ) {
V_166 = F_3 ( V_2 , V_163 ) ;
for ( V_10 = 0 ; V_10 < V_164 ; V_10 ++ )
V_165 [ V_10 ] = ( V_166 >> ( 8 * V_10 ) ) & 0xff ;
}
return F_87 ( V_111 , V_113 ) ? 0 : - V_169 ;
}
static void F_97 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
if ( V_111 -> V_124 ) {
F_75 ( V_2 ) ;
} else {
if ( ! V_113 -> V_115 . V_116 )
F_78 ( V_2 ) ;
else
F_77 ( V_2 ) ;
}
}
static void F_98 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
int V_59 = - V_169 ;
if ( V_111 -> V_124 )
V_59 = F_91 ( V_111 , V_113 , V_173 ) ;
else
V_59 = F_95 ( V_111 , V_113 , V_174 ) ;
if ( ! V_59 )
F_97 ( V_111 , V_113 ) ;
}
static void F_99 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
if ( V_111 -> V_118 )
return;
V_111 -> V_118 = true ;
if ( V_111 -> V_124 ) {
F_5 ( V_2 , V_175 , V_176 ) ;
F_74 ( V_2 ) ;
} else {
F_6 ( V_2 , V_175 , V_176 ) ;
if ( V_113 -> V_115 . V_116 )
F_76 ( V_2 ) ;
}
F_98 ( V_111 , V_113 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_177 , V_145 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_177 , V_145 ) ;
}
static void F_102 ( struct V_1 * V_2 , int V_23 )
{
F_5 ( V_2 , F_103 ( V_23 ) , V_28 ) ;
}
static void F_104 ( struct V_1 * V_2 , int V_23 )
{
F_6 ( V_2 , F_103 ( V_23 ) , V_28 ) ;
}
static T_1 F_105 ( struct V_110 * V_111 )
{
switch ( V_111 -> V_119 . V_154 ) {
case 8 :
return V_178 ;
case 16 :
return V_179 ;
case 32 :
return V_180 ;
case 64 :
return V_181 ;
case 512 :
return V_182 ;
case 1024 :
return V_183 ;
default:
return V_184 ;
}
}
static bool F_106 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
struct V_185 * V_186 ;
int V_10 ;
bool V_59 = false ;
if ( V_113 -> V_115 . V_116 > V_187 ) {
F_9 ( F_10 ( V_2 ) , L_3 ,
V_12 , V_113 -> V_115 . V_116 ) ;
return false ;
}
if ( ! V_113 -> V_115 . V_116 )
return false ;
if ( F_105 ( V_111 ) == V_184 )
return false ;
F_107 (usb3, dma, i) {
if ( V_186 -> V_188 )
continue;
if ( F_108 ( & V_2 -> V_81 , & V_113 -> V_115 ,
V_111 -> V_124 ) < 0 )
break;
V_186 -> V_188 = true ;
V_111 -> V_186 = V_186 ;
V_59 = true ;
break;
}
return V_59 ;
}
static void F_109 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
int V_10 ;
struct V_185 * V_186 ;
F_107 (usb3, dma, i) {
if ( V_111 -> V_186 == V_186 ) {
F_110 ( & V_2 -> V_81 , & V_113 -> V_115 ,
V_111 -> V_124 ) ;
V_186 -> V_188 = false ;
V_111 -> V_186 = NULL ;
break;
}
}
}
static void F_111 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_189 * V_190 = V_111 -> V_186 -> V_191 ;
T_1 V_192 = V_113 -> V_115 . V_116 ;
T_1 V_186 = V_113 -> V_115 . V_186 ;
T_1 V_164 ;
int V_10 = 0 ;
do {
V_164 = F_92 ( T_1 , V_192 , V_193 ) &
V_194 ;
V_190 -> V_195 = F_105 ( V_111 ) |
V_196 | V_164 ;
V_190 -> V_197 = V_186 ;
V_192 -= V_164 ;
V_186 += V_164 ;
if ( ! V_192 || ( V_10 + 1 ) < V_198 )
break;
V_190 ++ ;
V_10 ++ ;
} while ( 1 );
V_190 -> V_195 |= V_199 | V_200 ;
if ( V_111 -> V_124 )
V_190 -> V_195 |= V_201 ;
}
static void F_112 ( struct V_110 * V_111 )
{
struct V_185 * V_186 = V_111 -> V_186 ;
struct V_1 * V_2 = F_63 ( V_111 ) ;
T_1 V_202 = F_113 ( V_111 -> V_23 ) | V_203 ;
if ( V_111 -> V_124 )
V_202 |= V_204 ;
F_114 () ;
F_1 ( V_2 , 1 << V_111 -> V_23 , V_27 ) ;
F_1 ( V_2 , F_115 ( V_186 -> V_23 ) |
F_116 ( V_186 -> V_23 ) , V_205 ) ;
F_1 ( V_2 , V_186 -> V_206 , F_117 ( V_186 -> V_23 ) ) ;
F_1 ( V_2 , V_202 , F_118 ( V_186 -> V_23 ) ) ;
F_102 ( V_2 , V_111 -> V_23 ) ;
}
static void F_119 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
struct V_185 * V_186 = V_111 -> V_186 ;
F_104 ( V_2 , V_111 -> V_23 ) ;
F_1 ( V_2 , 0 , F_118 ( V_186 -> V_23 ) ) ;
}
static int F_120 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_189 * V_190 = V_111 -> V_186 -> V_191 ;
struct V_152 * V_115 = & V_113 -> V_115 ;
T_1 V_192 , V_164 ;
int V_10 = 0 ;
int V_114 = 0 ;
F_121 () ;
do {
if ( V_190 -> V_195 & V_207 )
V_114 = - V_208 ;
if ( V_190 -> V_195 & V_199 )
V_164 = V_115 -> V_116 % V_193 ;
else
V_164 = V_193 ;
V_192 = V_190 -> V_195 & V_194 ;
V_115 -> V_117 += V_164 - V_192 ;
if ( V_190 -> V_195 & V_199 ||
( V_10 + 1 ) < V_198 )
break;
V_190 ++ ;
V_10 ++ ;
} while ( 1 );
return V_114 ;
}
static bool F_122 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
if ( ! V_209 )
return false ;
if ( F_106 ( V_111 , V_113 ) ) {
F_84 ( V_2 ) ;
F_100 ( V_2 ) ;
F_111 ( V_111 , V_113 ) ;
F_112 ( V_111 ) ;
F_83 ( V_2 ) ;
return true ;
}
return false ;
}
static int F_123 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
unsigned long V_88 ;
int V_114 = 0 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! V_111 -> V_186 )
goto V_210;
if ( ! F_81 ( V_2 , V_111 -> V_23 ) )
F_101 ( V_2 ) ;
F_119 ( V_111 ) ;
V_114 = F_120 ( V_111 , V_113 ) ;
F_109 ( V_111 , V_113 ) ;
V_210:
F_45 ( & V_2 -> V_89 , V_88 ) ;
return V_114 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_211 * V_212 )
{
int V_10 ;
struct V_185 * V_186 ;
F_107 (usb3, dma, i) {
if ( V_186 -> V_191 ) {
F_125 ( V_212 , V_213 ,
V_186 -> V_191 , V_186 -> V_206 ) ;
V_186 -> V_191 = NULL ;
}
}
return 0 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_211 * V_212 )
{
int V_10 ;
struct V_185 * V_186 ;
if ( ! V_209 )
return 0 ;
F_107 (usb3, dma, i) {
V_186 -> V_191 = F_127 ( V_212 , V_213 ,
& V_186 -> V_206 , V_214 ) ;
if ( ! V_186 -> V_191 ) {
F_124 ( V_2 , V_212 ) ;
return - V_215 ;
}
V_186 -> V_23 = V_10 + 1 ;
}
return 0 ;
}
static void F_128 ( struct V_110 * V_111 ,
struct V_109 * V_113 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
struct V_109 * V_216 = F_62 ( V_111 ) ;
unsigned long V_88 ;
int V_59 = - V_169 ;
T_1 V_217 = 0 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( V_111 -> V_218 || V_111 -> V_118 )
goto V_210;
if ( V_113 != V_216 )
goto V_210;
if ( F_81 ( V_2 , V_111 -> V_23 ) < 0 )
goto V_210;
V_111 -> V_118 = true ;
if ( F_122 ( V_111 , V_113 ) )
goto V_210;
F_83 ( V_2 ) ;
if ( V_111 -> V_124 ) {
V_59 = F_91 ( V_111 , V_113 , V_219 ) ;
V_217 |= V_220 ;
}
if ( V_59 < 0 )
V_217 |= V_221 ;
if ( V_217 ) {
F_5 ( V_2 , V_217 , V_222 ) ;
F_16 ( V_2 , V_111 -> V_23 ) ;
}
V_210:
F_45 ( & V_2 -> V_89 , V_88 ) ;
}
static int F_129 ( struct V_223 * V_224 , struct V_152 * V_225 ,
T_4 V_226 )
{
struct V_110 * V_111 = F_130 ( V_224 ) ;
struct V_109 * V_113 = F_131 ( V_225 ) ;
struct V_1 * V_2 = F_63 ( V_111 ) ;
unsigned long V_88 ;
F_9 ( F_10 ( V_2 ) , L_4 , V_111 -> V_23 ,
V_225 -> V_116 ) ;
V_225 -> V_114 = - V_227 ;
V_225 -> V_117 = 0 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
F_132 ( & V_113 -> V_112 , & V_111 -> V_112 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
if ( ! V_111 -> V_23 )
F_99 ( V_111 , V_113 ) ;
else
F_128 ( V_111 , V_113 ) ;
return 0 ;
}
static void F_133 ( struct V_1 * V_2 , T_2 V_228 )
{
F_5 ( V_2 , F_134 ( V_228 ) , V_46 ) ;
}
static bool F_135 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
if ( V_121 -> V_229 >= 128 )
return true ;
F_133 ( V_2 , V_121 -> V_229 ) ;
F_78 ( V_2 ) ;
return false ;
}
static void F_136 ( struct V_1 * V_2 ,
void * V_230 , T_5 V_164 ,
void (* F_137)( struct V_223 * V_119 ,
struct V_152 * V_115 ) )
{
struct V_110 * V_111 = F_71 ( V_2 , 0 ) ;
if ( V_230 )
memcpy ( V_2 -> V_231 , V_230 ,
F_92 ( T_5 , V_164 , V_232 ) ) ;
V_2 -> V_233 -> V_165 = & V_2 -> V_231 ;
V_2 -> V_233 -> V_116 = V_164 ;
V_2 -> V_233 -> F_137 = F_137 ;
F_129 ( & V_111 -> V_119 , V_2 -> V_233 , V_234 ) ;
}
static void F_138 ( struct V_223 * V_119 ,
struct V_152 * V_115 )
{
}
static bool F_139 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
bool V_235 = false ;
struct V_110 * V_111 ;
int V_23 ;
T_2 V_114 = 0 ;
switch ( V_121 -> V_125 & V_236 ) {
case V_237 :
if ( V_2 -> V_81 . V_238 )
V_114 |= 1 << V_239 ;
if ( V_2 -> V_81 . V_99 == V_102 )
V_114 |= F_29 ( V_2 ) ;
break;
case V_240 :
break;
case V_241 :
V_23 = F_140 ( V_121 -> V_242 ) & V_243 ;
V_111 = F_71 ( V_2 , V_23 ) ;
if ( V_111 -> V_218 )
V_114 |= 1 << V_244 ;
break;
default:
V_235 = true ;
break;
}
if ( ! V_235 ) {
V_114 = F_141 ( V_114 ) ;
F_9 ( F_10 ( V_2 ) , L_5 ,
F_131 ( V_2 -> V_233 ) ) ;
F_136 ( V_2 , & V_114 , sizeof( V_114 ) ,
F_138 ) ;
}
return V_235 ;
}
static bool F_142 ( struct V_1 * V_2 ,
struct V_120 * V_121 , bool V_245 )
{
bool V_235 = true ;
T_2 V_246 = F_140 ( V_121 -> V_229 ) ;
switch ( V_246 ) {
case V_247 :
if ( ! V_245 )
break;
V_2 -> V_42 = F_140 ( V_121 -> V_242 ) >> 8 ;
V_235 = false ;
break;
case V_248 :
case V_249 :
if ( V_2 -> V_81 . V_99 != V_102 )
break;
if ( V_246 == V_248 )
F_31 ( V_2 , V_245 ) ;
if ( V_246 == V_249 )
F_30 ( V_2 , V_245 ) ;
V_235 = false ;
break;
default:
break;
}
return V_235 ;
}
static int F_143 ( struct V_110 * V_111 , bool V_218 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
if ( F_144 ( V_111 -> V_23 ) )
return - V_250 ;
V_111 -> V_218 = V_218 ;
if ( V_218 )
F_79 ( V_2 ) ;
else
F_80 ( V_2 ) ;
return 0 ;
}
static int F_145 ( struct V_110 * V_111 , bool V_218 ,
bool V_251 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_81 ( V_2 , V_111 -> V_23 ) ) {
V_111 -> V_218 = V_218 ;
if ( V_218 ) {
F_85 ( V_2 ) ;
} else if ( ! V_251 || ! V_111 -> V_252 ) {
F_86 ( V_2 ) ;
F_5 ( V_2 , V_253 , V_145 ) ;
F_84 ( V_2 ) ;
}
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_146 ( struct V_110 * V_111 , bool V_218 ,
bool V_251 )
{
int V_59 = 0 ;
if ( V_218 && V_111 -> V_118 )
return - V_169 ;
if ( V_111 -> V_23 )
V_59 = F_145 ( V_111 , V_218 , V_251 ) ;
else
V_59 = F_143 ( V_111 , V_218 ) ;
return V_59 ;
}
static bool F_147 ( struct V_1 * V_2 ,
struct V_120 * V_121 ,
bool V_245 )
{
int V_23 = F_140 ( V_121 -> V_242 ) & V_243 ;
struct V_110 * V_111 ;
struct V_109 * V_113 ;
if ( F_140 ( V_121 -> V_229 ) != V_244 )
return true ;
V_111 = F_71 ( V_2 , V_23 ) ;
F_146 ( V_111 , V_245 , true ) ;
if ( ! V_245 ) {
V_111 -> V_118 = false ;
V_113 = F_62 ( V_111 ) ;
if ( V_113 )
F_128 ( V_111 , V_113 ) ;
}
return false ;
}
static bool F_148 ( struct V_1 * V_2 ,
struct V_120 * V_121 , bool V_245 )
{
bool V_235 = false ;
switch ( V_121 -> V_125 & V_236 ) {
case V_237 :
V_235 = F_142 ( V_2 , V_121 , V_245 ) ;
break;
case V_240 :
break;
case V_241 :
V_235 = F_147 ( V_2 , V_121 , V_245 ) ;
break;
default:
V_235 = true ;
break;
}
if ( ! V_235 )
F_78 ( V_2 ) ;
return V_235 ;
}
static void F_149 ( struct V_223 * V_119 ,
struct V_152 * V_115 )
{
}
static bool F_150 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
T_2 V_254 = F_140 ( V_121 -> V_255 ) ;
if ( V_254 != 6 )
return true ;
F_9 ( F_10 ( V_2 ) , L_6 ,
F_131 ( V_2 -> V_233 ) ) ;
F_136 ( V_2 , NULL , 6 , F_149 ) ;
return false ;
}
static bool F_151 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
if ( V_121 -> V_229 > 0 )
F_5 ( V_2 , V_77 , V_46 ) ;
else
F_6 ( V_2 , V_77 , V_46 ) ;
return false ;
}
static bool F_152 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
bool V_59 = false ;
bool V_235 = false ;
if ( ( V_121 -> V_125 & V_256 ) == V_257 ) {
switch ( V_121 -> V_258 ) {
case V_259 :
V_235 = F_135 ( V_2 , V_121 ) ;
V_59 = true ;
break;
case V_260 :
V_235 = F_139 ( V_2 , V_121 ) ;
V_59 = true ;
break;
case V_261 :
V_235 = F_148 ( V_2 , V_121 , false ) ;
V_59 = true ;
break;
case V_262 :
V_235 = F_148 ( V_2 , V_121 , true ) ;
V_59 = true ;
break;
case V_263 :
V_235 = F_150 ( V_2 , V_121 ) ;
V_59 = true ;
break;
case V_264 :
V_235 = true ;
V_59 = true ;
break;
case V_265 :
F_151 ( V_2 , V_121 ) ;
break;
default:
break;
}
}
if ( V_235 )
F_79 ( V_2 ) ;
return V_59 ;
}
static int F_153 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_266 , V_128 ) ;
return F_7 ( V_2 , V_128 , V_266 , 0 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
struct V_120 V_121 ;
struct V_110 * V_111 = F_71 ( V_2 , 0 ) ;
if ( V_111 -> V_118 )
F_69 ( V_111 , F_62 ( V_111 ) ,
- V_267 ) ;
F_153 ( V_2 ) ;
F_72 ( V_2 , & V_121 ) ;
if ( ! F_152 ( V_2 , & V_121 ) )
if ( V_2 -> V_79 -> V_268 ( & V_2 -> V_81 , & V_121 ) < 0 )
F_79 ( V_2 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = F_71 ( V_2 , 0 ) ;
struct V_109 * V_113 = F_62 ( V_111 ) ;
if ( ! V_113 )
return;
F_98 ( V_111 , V_113 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
T_1 V_269 = F_3 ( V_2 , V_70 ) ;
V_269 &= F_3 ( V_2 , V_71 ) ;
F_1 ( V_2 , V_269 , V_70 ) ;
if ( V_269 & V_270 )
F_70 ( V_2 ) ;
if ( V_269 & V_271 )
F_154 ( V_2 ) ;
if ( V_269 & V_272 )
F_155 ( V_2 ) ;
}
static void F_157 ( struct V_1 * V_2 ,
struct V_110 * V_111 ,
struct V_109 * V_113 ,
int V_114 )
{
unsigned long V_88 ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( F_81 ( V_2 , V_111 -> V_23 ) )
F_84 ( V_2 ) ;
F_45 ( & V_2 -> V_89 , V_88 ) ;
F_18 ( V_2 , V_111 -> V_23 ) ;
F_69 ( V_111 , V_113 , V_114 ) ;
V_113 = F_62 ( V_111 ) ;
if ( V_113 )
F_128 ( V_111 , V_113 ) ;
}
static void F_158 ( struct V_1 * V_2 , int V_23 )
{
struct V_110 * V_111 = F_71 ( V_2 , V_23 ) ;
struct V_109 * V_113 = F_62 ( V_111 ) ;
if ( ! V_113 )
return;
if ( V_111 -> V_124 ) {
F_9 ( F_10 ( V_2 ) , L_7 ,
V_12 , V_113 -> V_115 . V_116 , V_113 -> V_115 . V_117 ) ;
F_157 ( V_2 , V_111 , V_113 , 0 ) ;
}
}
static void F_159 ( struct V_1 * V_2 , int V_23 )
{
struct V_110 * V_111 = F_71 ( V_2 , V_23 ) ;
struct V_109 * V_113 = F_62 ( V_111 ) ;
bool V_273 = false ;
if ( ! V_113 )
return;
F_68 ( & V_2 -> V_89 ) ;
if ( F_81 ( V_2 , V_23 ) )
goto V_210;
if ( V_111 -> V_124 ) {
if ( ! F_91 ( V_111 , V_113 , V_219 ) )
F_6 ( V_2 , V_221 , V_222 ) ;
} else {
if ( ! F_95 ( V_111 , V_113 , V_274 ) )
V_273 = true ;
}
V_210:
F_66 ( & V_2 -> V_89 ) ;
if ( V_273 )
F_157 ( V_2 , V_111 , V_113 , 0 ) ;
}
static void F_160 ( struct V_1 * V_2 , int V_23 )
{
T_1 V_275 ;
F_68 ( & V_2 -> V_89 ) ;
if ( F_81 ( V_2 , V_23 ) < 0 ) {
F_66 ( & V_2 -> V_89 ) ;
return;
}
V_275 = F_3 ( V_2 , V_276 ) ;
V_275 &= F_3 ( V_2 , V_222 ) ;
F_1 ( V_2 , V_275 , V_276 ) ;
F_66 ( & V_2 -> V_89 ) ;
if ( V_275 & V_220 )
F_158 ( V_2 , V_23 ) ;
if ( V_275 & V_221 )
F_159 ( V_2 , V_23 ) ;
}
static void F_161 ( struct V_1 * V_2 , T_1 V_277 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_142 ; V_10 ++ ) {
if ( V_277 & F_17 ( V_10 ) ) {
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
static void F_163 ( struct V_1 * V_2 , T_1 V_278 )
{
if ( V_278 & V_92 )
F_162 ( V_2 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
T_1 V_108 = F_3 ( V_2 , V_32 ) ;
T_1 V_277 = F_3 ( V_2 , V_279 ) ;
T_1 V_278 = F_3 ( V_2 , V_96 ) ;
V_108 &= F_3 ( V_2 , V_22 ) ;
if ( V_108 ) {
F_1 ( V_2 , V_108 , V_32 ) ;
F_59 ( V_2 , V_108 ) ;
}
V_277 &= F_3 ( V_2 , V_24 ) ;
if ( V_277 )
F_161 ( V_2 , V_277 ) ;
V_278 &= F_3 ( V_2 , V_97 ) ;
if ( V_278 ) {
F_1 ( V_2 , V_278 , V_96 ) ;
F_163 ( V_2 , V_278 ) ;
}
}
static void F_165 ( struct V_1 * V_2 , T_1 V_280 )
{
struct V_110 * V_111 ;
struct V_109 * V_113 ;
int V_10 , V_114 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_142 ; V_10 ++ ) {
if ( ! ( V_280 & F_103 ( V_10 ) ) )
continue;
V_111 = F_71 ( V_2 , V_10 ) ;
if ( ! ( F_3 ( V_2 , V_205 ) &
F_115 ( V_111 -> V_186 -> V_23 ) ) )
continue;
V_113 = F_62 ( V_111 ) ;
V_114 = F_123 ( V_111 , V_113 ) ;
F_157 ( V_2 , V_111 , V_113 , V_114 ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
T_1 V_280 = F_3 ( V_2 , V_27 ) ;
V_280 &= F_3 ( V_2 , V_28 ) ;
if ( V_280 ) {
F_1 ( V_2 , V_280 , V_27 ) ;
F_165 ( V_2 , V_280 ) ;
}
}
static T_6 F_167 ( int V_281 , void * V_282 )
{
struct V_1 * V_2 = V_282 ;
T_6 V_59 = V_283 ;
T_1 V_284 = F_3 ( V_2 , V_205 ) ;
if ( V_284 & V_29 ) {
F_166 ( V_2 ) ;
V_59 = V_285 ;
}
if ( V_284 & V_30 ) {
F_164 ( V_2 ) ;
V_59 = V_285 ;
}
return V_59 ;
}
static void F_168 ( struct V_110 * V_111 ,
const struct V_286 * V_287 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
T_1 V_7 = 0 ;
V_7 |= V_111 -> V_124 ? V_288 : 0 ;
V_7 |= F_169 ( F_170 ( V_287 ) ) ;
V_7 |= F_171 ( F_172 ( V_287 ) ) ;
F_1 ( V_2 , V_7 , V_289 ) ;
}
static T_1 F_173 ( int V_290 )
{
F_174 ( V_290 > V_291 ) ;
if ( V_290 <= V_292 )
return V_293 ;
else if ( V_290 <= V_294 )
return V_295 ;
else if ( V_290 <= V_296 )
return V_297 ;
else if ( V_290 <= V_298 )
return V_299 ;
else
return V_300 ;
}
static T_1 F_175 ( struct V_110 * V_111 ,
const struct V_286 * V_287 )
{
int V_10 ;
const T_1 V_301 [] = { 8 , 16 , 32 , 64 , 512 } ;
T_1 V_302 = F_176 ( 1024 ) ;
for ( V_10 = 0 ; V_10 < F_177 ( V_301 ) ; V_10 ++ ) {
if ( F_178 ( V_287 ) <= V_301 [ V_10 ] )
V_302 = F_176 ( V_301 [ V_10 ] ) ;
}
return V_111 -> V_303 | V_302 ;
}
static int F_179 ( struct V_110 * V_111 ,
const struct V_286 * V_287 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
unsigned long V_88 ;
V_111 -> V_124 = F_180 ( V_287 ) ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_81 ( V_2 , V_111 -> V_23 ) ) {
F_168 ( V_111 , V_287 ) ;
F_1 ( V_2 , F_175 ( V_111 , V_287 ) ,
V_304 ) ;
F_86 ( V_2 ) ;
F_5 ( V_2 , V_253 , V_145 ) ;
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_181 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_63 ( V_111 ) ;
unsigned long V_88 ;
V_111 -> V_218 = false ;
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_81 ( V_2 , V_111 -> V_23 ) ) {
F_1 ( V_2 , 0 , V_222 ) ;
F_1 ( V_2 , 0 , V_304 ) ;
F_6 ( V_2 , V_253 , V_145 ) ;
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
return 0 ;
}
static int F_182 ( struct V_223 * V_224 ,
const struct V_286 * V_287 )
{
struct V_110 * V_111 = F_130 ( V_224 ) ;
return F_179 ( V_111 , V_287 ) ;
}
static int F_183 ( struct V_223 * V_224 )
{
struct V_110 * V_111 = F_130 ( V_224 ) ;
struct V_109 * V_113 ;
do {
V_113 = F_62 ( V_111 ) ;
if ( ! V_113 )
break;
F_123 ( V_111 , V_113 ) ;
F_69 ( V_111 , V_113 , - V_305 ) ;
} while ( 1 );
return F_181 ( V_111 ) ;
}
static struct V_152 * F_184 ( T_4 V_226 )
{
struct V_109 * V_113 ;
V_113 = F_185 ( sizeof( struct V_109 ) , V_226 ) ;
if ( ! V_113 )
return NULL ;
F_186 ( & V_113 -> V_112 ) ;
return & V_113 -> V_115 ;
}
static void F_187 ( struct V_152 * V_225 )
{
struct V_109 * V_113 = F_131 ( V_225 ) ;
F_188 ( V_113 ) ;
}
static struct V_152 * F_189 ( struct V_223 * V_224 ,
T_4 V_226 )
{
return F_184 ( V_226 ) ;
}
static void F_190 ( struct V_223 * V_224 ,
struct V_152 * V_225 )
{
F_187 ( V_225 ) ;
}
static int F_191 ( struct V_223 * V_224 , struct V_152 * V_225 )
{
struct V_110 * V_111 = F_130 ( V_224 ) ;
struct V_109 * V_113 = F_131 ( V_225 ) ;
struct V_1 * V_2 = F_63 ( V_111 ) ;
F_9 ( F_10 ( V_2 ) , L_8 , V_111 -> V_23 ,
V_225 -> V_116 ) ;
F_123 ( V_111 , V_113 ) ;
F_157 ( V_2 , V_111 , V_113 , - V_267 ) ;
return 0 ;
}
static int F_192 ( struct V_223 * V_224 , int V_306 )
{
return F_146 ( F_130 ( V_224 ) , ! ! V_306 , false ) ;
}
static int F_193 ( struct V_223 * V_224 )
{
struct V_110 * V_111 = F_130 ( V_224 ) ;
V_111 -> V_252 = true ;
return F_146 ( V_111 , true , false ) ;
}
static void F_194 ( struct V_223 * V_224 )
{
struct V_110 * V_111 = F_130 ( V_224 ) ;
struct V_1 * V_2 = F_63 ( V_111 ) ;
unsigned long V_88 ;
if ( V_111 -> V_23 ) {
F_44 ( & V_2 -> V_89 , V_88 ) ;
if ( ! F_81 ( V_2 , V_111 -> V_23 ) ) {
F_86 ( V_2 ) ;
F_5 ( V_2 , V_253 , V_145 ) ;
}
F_45 ( & V_2 -> V_89 , V_88 ) ;
} else {
F_153 ( V_2 ) ;
}
}
static int F_195 ( struct V_307 * V_81 ,
struct V_308 * V_79 )
{
struct V_1 * V_2 ;
if ( ! V_79 || V_79 -> V_309 < V_106 ||
! V_79 -> V_268 )
return - V_250 ;
V_2 = F_196 ( V_81 ) ;
V_2 -> V_79 = V_79 ;
F_197 ( F_10 ( V_2 ) ) ;
F_198 ( F_10 ( V_2 ) ) ;
F_48 ( V_2 ) ;
return 0 ;
}
static int F_199 ( struct V_307 * V_81 )
{
struct V_1 * V_2 = F_196 ( V_81 ) ;
V_2 -> V_40 = false ;
V_2 -> V_81 . V_99 = V_107 ;
V_2 -> V_79 = NULL ;
F_49 ( V_2 ) ;
F_200 ( F_10 ( V_2 ) ) ;
F_201 ( F_10 ( V_2 ) ) ;
return 0 ;
}
static int F_202 ( struct V_307 * V_310 )
{
return - V_311 ;
}
static int F_203 ( struct V_307 * V_81 , int V_312 )
{
struct V_1 * V_2 = F_196 ( V_81 ) ;
V_2 -> V_40 = ! ! V_312 ;
return 0 ;
}
static int F_204 ( struct V_307 * V_81 , int V_313 )
{
V_81 -> V_238 = ! ! V_313 ;
return 0 ;
}
static T_7 F_205 ( struct V_211 * V_212 , struct V_314 * V_315 ,
const char * V_165 , T_5 V_316 )
{
struct V_1 * V_2 = F_206 ( V_212 ) ;
bool V_317 ;
if ( ! V_2 -> V_79 )
return - V_318 ;
if ( V_2 -> V_90 )
return - V_13 ;
if ( ! strncmp ( V_165 , L_9 , strlen ( L_9 ) ) )
V_317 = true ;
else if ( ! strncmp ( V_165 , L_10 , strlen ( L_10 ) ) )
V_317 = false ;
else
return - V_250 ;
if ( V_317 == F_19 ( V_2 ) )
return - V_250 ;
F_43 ( V_2 , V_317 , F_46 ( V_2 ) ) ;
return V_316 ;
}
static T_7 F_207 ( struct V_211 * V_212 , struct V_314 * V_315 ,
char * V_165 )
{
struct V_1 * V_2 = F_206 ( V_212 ) ;
if ( ! V_2 -> V_79 )
return - V_318 ;
return sprintf ( V_165 , L_11 , F_19 ( V_2 ) ? L_9 : L_10 ) ;
}
static int F_208 ( struct V_319 * V_320 , void * V_321 )
{
struct V_1 * V_2 = V_320 -> V_322 ;
F_209 ( V_320 , L_12 , V_2 -> V_90 ) ;
return 0 ;
}
static int F_210 ( struct V_323 * V_323 , struct V_324 * V_324 )
{
return F_211 ( V_324 , F_208 , V_323 -> V_325 ) ;
}
static T_7 F_212 ( struct V_324 * V_324 ,
const char T_8 * V_326 ,
T_5 V_316 , T_9 * V_327 )
{
struct V_319 * V_320 = V_324 -> V_328 ;
struct V_1 * V_2 = V_320 -> V_322 ;
char V_165 [ 32 ] ;
if ( ! V_2 -> V_79 )
return - V_318 ;
if ( F_213 ( & V_165 , V_326 , F_92 ( T_5 , sizeof( V_165 ) - 1 , V_316 ) ) )
return - V_329 ;
if ( ! strncmp ( V_165 , L_13 , 1 ) )
V_2 -> V_90 = true ;
else
V_2 -> V_90 = false ;
F_47 ( V_2 ) ;
return V_316 ;
}
static void F_214 ( struct V_1 * V_2 ,
struct V_211 * V_212 )
{
struct V_330 * V_331 , * V_324 ;
V_331 = F_215 ( F_216 ( V_212 ) , NULL ) ;
if ( F_217 ( V_331 ) ) {
F_218 ( V_212 , L_14 , V_12 ) ;
return;
}
V_324 = F_219 ( L_15 , 0644 , V_331 , V_2 ,
& V_332 ) ;
if ( ! V_324 )
F_218 ( V_212 , L_16 , V_12 ) ;
}
static int F_220 ( struct V_333 * V_334 )
{
struct V_1 * V_2 = F_221 ( V_334 ) ;
F_222 ( & V_334 -> V_212 , & V_335 ) ;
F_223 ( & V_2 -> V_81 ) ;
F_124 ( V_2 , & V_334 -> V_212 ) ;
F_187 ( V_2 -> V_233 ) ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 , struct V_211 * V_212 ,
const struct V_336 * V_337 )
{
struct V_110 * V_111 ;
int V_10 ;
V_2 -> V_142 = V_337 -> V_338 * V_337 -> V_339 * 2 /
V_337 -> V_340 + 1 ;
if ( V_2 -> V_142 > V_341 )
V_2 -> V_142 = V_341 ;
V_2 -> V_111 = F_225 ( V_212 , sizeof( * V_111 ) * V_2 -> V_142 ,
V_214 ) ;
if ( ! V_2 -> V_111 )
return - V_215 ;
F_9 ( V_212 , L_17 , V_12 , V_2 -> V_142 ) ;
F_226 (usb3_ep, usb3, i) {
snprintf ( V_111 -> V_342 , sizeof( V_111 -> V_342 ) , L_18 , V_10 ) ;
V_111 -> V_2 = V_2 ;
V_111 -> V_23 = V_10 ;
V_111 -> V_119 . V_343 = V_111 -> V_342 ;
V_111 -> V_119 . V_344 = & V_345 ;
F_186 ( & V_111 -> V_112 ) ;
F_186 ( & V_111 -> V_119 . V_346 ) ;
if ( ! V_10 ) {
V_2 -> V_81 . V_347 = & V_111 -> V_119 ;
F_227 ( & V_111 -> V_119 ,
V_348 ) ;
V_111 -> V_119 . V_349 . V_350 = true ;
V_111 -> V_119 . V_349 . V_124 = true ;
V_111 -> V_119 . V_349 . V_351 = true ;
continue;
}
F_227 ( & V_111 -> V_119 , ~ 0 ) ;
F_132 ( & V_111 -> V_119 . V_346 , & V_2 -> V_81 . V_346 ) ;
V_111 -> V_119 . V_349 . V_352 = true ;
V_111 -> V_119 . V_349 . V_353 = true ;
if ( V_10 & 1 )
V_111 -> V_119 . V_349 . V_124 = true ;
else
V_111 -> V_119 . V_349 . V_351 = true ;
}
return 0 ;
}
static void F_228 ( struct V_1 * V_2 , struct V_211 * V_212 ,
const struct V_336 * V_337 )
{
struct V_110 * V_111 ;
int V_10 ;
T_1 V_354 [ 2 ] , V_355 [ 2 ] ;
T_1 * V_356 , * V_357 ;
T_1 V_7 ;
memset ( V_354 , 0 , sizeof( V_354 ) ) ;
memset ( V_355 , 0 , sizeof( V_355 ) ) ;
F_226 (usb3_ep, usb3, i) {
if ( ! V_10 )
continue;
if ( V_111 -> V_119 . V_349 . V_124 ) {
V_356 = & V_354 [ 0 ] ;
V_357 = & V_355 [ 0 ] ;
} else {
V_356 = & V_354 [ 1 ] ;
V_357 = & V_355 [ 1 ] ;
}
if ( * V_357 > V_337 -> V_338 )
continue;
V_7 = F_229 ( * V_356 ) ;
V_7 |= F_173 ( V_337 -> V_340 ) ;
V_7 |= F_230 ( * V_357 ) ;
V_111 -> V_303 = V_7 ;
F_9 ( V_212 , L_19 ,
V_10 , V_7 , * V_356 , * V_357 ) ;
if ( * V_356 + 1 == V_337 -> V_339 ) {
* V_356 = 0 ;
* V_357 += V_337 -> V_340 ;
} else {
( * V_356 ) ++ ;
}
}
}
static int F_231 ( struct V_333 * V_334 )
{
struct V_1 * V_2 ;
struct V_358 * V_127 ;
const struct V_359 * V_360 ;
int V_281 , V_59 ;
const struct V_336 * V_337 ;
const struct V_361 * V_315 ;
V_360 = F_232 ( V_362 , V_334 -> V_212 . V_363 ) ;
if ( ! V_360 )
return - V_318 ;
V_315 = F_233 ( V_364 ) ;
if ( V_315 )
V_337 = V_315 -> V_3 ;
else
V_337 = V_360 -> V_3 ;
V_281 = F_234 ( V_334 , 0 ) ;
if ( V_281 < 0 ) {
F_235 ( & V_334 -> V_212 , L_20 , V_281 ) ;
return V_281 ;
}
V_2 = F_225 ( & V_334 -> V_212 , sizeof( * V_2 ) , V_214 ) ;
if ( ! V_2 )
return - V_215 ;
V_127 = F_236 ( V_334 , V_365 , 0 ) ;
V_2 -> V_5 = F_237 ( & V_334 -> V_212 , V_127 ) ;
if ( F_238 ( V_2 -> V_5 ) )
return F_239 ( V_2 -> V_5 ) ;
F_240 ( V_334 , V_2 ) ;
F_241 ( & V_2 -> V_89 ) ;
V_2 -> V_81 . V_344 = & V_366 ;
V_2 -> V_81 . V_343 = V_367 ;
V_2 -> V_81 . V_309 = V_102 ;
F_186 ( & V_2 -> V_81 . V_346 ) ;
V_59 = F_224 ( V_2 , & V_334 -> V_212 , V_337 ) ;
if ( V_59 < 0 )
return V_59 ;
F_228 ( V_2 , & V_334 -> V_212 , V_337 ) ;
V_59 = F_242 ( & V_334 -> V_212 , V_281 , F_167 , 0 ,
F_216 ( & V_334 -> V_212 ) , V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
F_243 ( & V_2 -> V_16 , F_11 ) ;
V_2 -> V_17 = F_244 ( & V_334 -> V_212 , V_368 ) ;
if ( F_238 ( V_2 -> V_17 ) )
return F_239 ( V_2 -> V_17 ) ;
V_59 = F_245 ( & V_334 -> V_212 , V_2 -> V_17 ) ;
if ( V_59 < 0 ) {
F_235 ( & V_334 -> V_212 , L_21 ) ;
return V_59 ;
}
V_2 -> V_233 = F_184 ( V_214 ) ;
if ( ! V_2 -> V_233 )
return - V_215 ;
V_59 = F_126 ( V_2 , & V_334 -> V_212 ) ;
if ( V_59 < 0 )
goto V_369;
V_59 = F_246 ( & V_334 -> V_212 , & V_2 -> V_81 ) ;
if ( V_59 < 0 )
goto V_370;
V_59 = F_247 ( & V_334 -> V_212 , & V_335 ) ;
if ( V_59 < 0 )
goto V_371;
V_2 -> V_82 = V_337 -> V_82 ;
F_214 ( V_2 , & V_334 -> V_212 ) ;
F_218 ( & V_334 -> V_212 , L_22 ) ;
return 0 ;
V_371:
F_223 ( & V_2 -> V_81 ) ;
V_370:
F_124 ( V_2 , & V_334 -> V_212 ) ;
V_369:
F_187 ( V_2 -> V_233 ) ;
return V_59 ;
}
