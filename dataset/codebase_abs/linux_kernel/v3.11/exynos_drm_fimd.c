static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
#ifdef F_2
const struct V_4 * V_5 =
F_3 ( V_6 , & V_3 -> V_7 ) ;
if ( V_5 )
return (struct V_1 * ) V_5 -> V_8 ;
#endif
return (struct V_1 * )
F_4 ( V_3 ) -> V_9 ;
}
static bool F_5 ( struct V_10 * V_7 )
{
return true ;
}
static void * F_6 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
return V_12 -> V_13 ;
}
static int F_8 ( struct V_10 * V_7 , struct V_14 * V_15 )
{
return 0 ;
}
static int F_9 ( struct V_10 * V_7 , int V_15 )
{
return 0 ;
}
static void F_10 ( struct V_10 * V_16 , int V_15 )
{
struct V_11 * V_12 = F_7 ( V_16 ) ;
F_11 ( L_1 , V_15 ) ;
F_12 ( & V_12 -> V_17 ) ;
switch ( V_15 ) {
case V_18 :
if ( V_12 -> V_19 )
F_13 ( V_16 ) ;
break;
case V_20 :
case V_21 :
case V_22 :
if ( ! V_12 -> V_19 )
F_14 ( V_16 ) ;
break;
default:
F_11 ( L_2 , V_15 ) ;
break;
}
F_15 ( & V_12 -> V_17 ) ;
}
static void F_16 ( struct V_10 * V_16 )
{
struct V_11 * V_12 = F_7 ( V_16 ) ;
struct V_23 * V_24 = V_12 -> V_25 . V_26 ;
struct V_27 * V_28 = V_24 -> V_29 ;
struct V_30 * V_31 = V_24 -> V_32 ;
struct V_33 * V_34 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_34 = & V_12 -> V_34 [ V_35 ] ;
if ( V_34 -> V_37 && ( V_31 && V_31 -> V_38 ) )
V_31 -> V_38 ( V_16 , V_35 ) ;
}
if ( V_28 && V_28 -> V_38 )
V_28 -> V_38 ( V_16 ) ;
}
static void F_17 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_39 * V_13 = V_12 -> V_13 ;
struct V_40 * V_41 = & V_13 -> V_41 ;
struct V_1 * V_9 ;
T_1 V_42 ;
V_9 = V_12 -> V_9 ;
if ( V_12 -> V_19 )
return;
F_18 ( V_12 -> V_43 , V_12 -> V_44 + V_9 -> V_45 + V_46 ) ;
V_42 = F_19 ( V_41 -> V_47 - 1 ) |
F_20 ( V_41 -> V_48 - 1 ) |
F_21 ( V_41 -> V_49 - 1 ) ;
F_18 ( V_42 , V_12 -> V_44 + V_9 -> V_45 + V_50 ) ;
V_42 = F_22 ( V_41 -> V_51 - 1 ) |
F_23 ( V_41 -> V_52 - 1 ) |
F_24 ( V_41 -> V_53 - 1 ) ;
F_18 ( V_42 , V_12 -> V_44 + V_9 -> V_45 + V_54 ) ;
V_42 = F_25 ( V_41 -> V_55 - 1 ) |
F_26 ( V_41 -> V_56 - 1 ) |
F_27 ( V_41 -> V_55 - 1 ) |
F_28 ( V_41 -> V_56 - 1 ) ;
F_18 ( V_42 , V_12 -> V_44 + V_9 -> V_45 + V_57 ) ;
V_42 = V_12 -> V_58 ;
V_42 &= ~ ( V_59 | V_60 ) ;
if ( V_12 -> V_9 -> V_61 ) {
V_42 &= ~ V_62 ;
V_42 |= V_63 ;
}
if ( V_12 -> V_64 > 1 )
V_42 |= F_29 ( V_12 -> V_64 - 1 ) | V_60 ;
else
V_42 &= ~ V_60 ;
V_42 |= V_65 | V_66 ;
F_18 ( V_42 , V_12 -> V_44 + V_67 ) ;
}
static int F_30 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
T_1 V_42 ;
if ( V_12 -> V_19 )
return - V_68 ;
if ( ! F_31 ( 0 , & V_12 -> V_69 ) ) {
V_42 = F_32 ( V_12 -> V_44 + V_70 ) ;
V_42 |= V_71 ;
V_42 |= V_72 ;
V_42 &= ~ V_73 ;
V_42 |= V_74 ;
V_42 &= ~ V_75 ;
V_42 |= V_76 ;
F_18 ( V_42 , V_12 -> V_44 + V_70 ) ;
}
return 0 ;
}
static void F_33 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
T_1 V_42 ;
if ( V_12 -> V_19 )
return;
if ( F_34 ( 0 , & V_12 -> V_69 ) ) {
V_42 = F_32 ( V_12 -> V_44 + V_70 ) ;
V_42 &= ~ V_72 ;
V_42 &= ~ V_71 ;
F_18 ( V_42 , V_12 -> V_44 + V_70 ) ;
}
}
static void F_35 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
if ( V_12 -> V_19 )
return;
F_36 ( & V_12 -> V_77 , 1 ) ;
if ( ! F_37 ( V_12 -> V_78 ,
! F_38 ( & V_12 -> V_77 ) ,
V_79 / 20 ) )
F_11 ( L_3 ) ;
}
static void F_39 ( struct V_10 * V_7 ,
struct V_80 * V_81 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_33 * V_34 ;
int V_82 ;
unsigned long V_83 ;
if ( ! V_81 ) {
F_40 ( V_7 , L_4 ) ;
return;
}
V_82 = V_81 -> V_84 ;
if ( V_82 == V_85 )
V_82 = V_12 -> V_86 ;
if ( V_82 < 0 || V_82 >= V_36 )
return;
V_83 = V_81 -> V_87 * ( V_81 -> V_88 >> 3 ) ;
V_83 += V_81 -> V_89 * V_81 -> V_90 ;
F_11 ( L_5 , V_83 , V_81 -> V_90 ) ;
V_34 = & V_12 -> V_34 [ V_82 ] ;
V_34 -> V_91 = V_81 -> V_92 ;
V_34 -> V_93 = V_81 -> V_94 ;
V_34 -> V_95 = V_81 -> V_96 ;
V_34 -> V_97 = V_81 -> V_98 ;
V_34 -> V_99 = V_81 -> V_99 ;
V_34 -> V_100 = V_81 -> V_100 ;
V_34 -> V_101 = V_81 -> V_101 [ 0 ] + V_83 ;
V_34 -> V_88 = V_81 -> V_88 ;
V_34 -> V_102 = ( V_81 -> V_99 - V_81 -> V_96 ) *
( V_81 -> V_88 >> 3 ) ;
V_34 -> V_103 = V_81 -> V_96 * ( V_81 -> V_88 >> 3 ) ;
F_11 ( L_6 ,
V_34 -> V_91 , V_34 -> V_93 ) ;
F_11 ( L_7 ,
V_34 -> V_95 , V_34 -> V_97 ) ;
F_11 ( L_8 , ( unsigned long ) V_34 -> V_101 ) ;
F_11 ( L_9 ,
V_81 -> V_99 , V_81 -> V_96 ) ;
}
static void F_41 ( struct V_10 * V_7 , unsigned int V_82 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_33 * V_34 = & V_12 -> V_34 [ V_82 ] ;
unsigned long V_42 ;
V_42 = V_104 ;
switch ( V_34 -> V_88 ) {
case 1 :
V_42 |= V_105 ;
V_42 |= V_106 ;
V_42 |= V_107 ;
break;
case 2 :
V_42 |= V_108 ;
V_42 |= V_106 ;
V_42 |= V_109 ;
break;
case 4 :
V_42 |= V_110 ;
V_42 |= V_106 ;
V_42 |= V_109 ;
break;
case 8 :
V_42 |= V_111 ;
V_42 |= V_109 ;
V_42 |= V_112 ;
break;
case 16 :
V_42 |= V_113 ;
V_42 |= V_114 ;
V_42 |= V_115 ;
break;
case 24 :
V_42 |= V_116 ;
V_42 |= V_117 ;
V_42 |= V_115 ;
break;
case 32 :
V_42 |= V_118
| V_119 | V_120 ;
V_42 |= V_117 ;
V_42 |= V_115 ;
break;
default:
F_11 ( L_10 ) ;
V_42 |= V_116 ;
V_42 |= V_117 ;
V_42 |= V_115 ;
break;
}
F_11 ( L_11 , V_34 -> V_88 ) ;
F_18 ( V_42 , V_12 -> V_44 + F_42 ( V_82 ) ) ;
}
static void F_43 ( struct V_10 * V_7 , unsigned int V_82 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
unsigned int V_121 = 0 , V_122 = 0 ;
V_121 = ~ ( V_123 | V_124 |
V_125 ) | F_44 ( 0 ) ;
V_122 = F_45 ( 0xffffffff ) ;
F_18 ( V_121 , V_12 -> V_44 + F_46 ( V_82 ) ) ;
F_18 ( V_122 , V_12 -> V_44 + F_47 ( V_82 ) ) ;
}
static void F_48 ( struct V_11 * V_12 ,
int V_82 , bool V_126 )
{
T_1 V_127 , V_128 , V_42 ;
if ( V_12 -> V_9 -> V_129 ) {
V_127 = V_130 ;
V_128 = F_49 ( V_82 ) ;
} else {
V_127 = V_131 ;
V_128 = V_132 ;
}
V_42 = F_32 ( V_12 -> V_44 + V_127 ) ;
if ( V_126 )
V_42 |= V_128 ;
else
V_42 &= ~ V_128 ;
F_18 ( V_42 , V_12 -> V_44 + V_127 ) ;
}
static void F_50 ( struct V_10 * V_7 , int V_84 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_33 * V_34 ;
int V_82 = V_84 ;
unsigned long V_42 , V_133 , V_134 ;
unsigned int V_135 ;
unsigned int V_136 ;
if ( V_12 -> V_19 )
return;
if ( V_82 == V_85 )
V_82 = V_12 -> V_86 ;
if ( V_82 < 0 || V_82 >= V_36 )
return;
V_34 = & V_12 -> V_34 [ V_82 ] ;
F_48 ( V_12 , V_82 , true ) ;
V_42 = ( unsigned long ) V_34 -> V_101 ;
F_18 ( V_42 , V_12 -> V_44 + F_51 ( V_82 , 0 ) ) ;
V_134 = V_34 -> V_99 * V_34 -> V_97 * ( V_34 -> V_88 >> 3 ) ;
V_42 = ( unsigned long ) ( V_34 -> V_101 + V_134 ) ;
F_18 ( V_42 , V_12 -> V_44 + F_52 ( V_82 , 0 ) ) ;
F_11 ( L_12 ,
( unsigned long ) V_34 -> V_101 , V_42 , V_134 ) ;
F_11 ( L_7 ,
V_34 -> V_95 , V_34 -> V_97 ) ;
V_42 = F_53 ( V_34 -> V_102 ) |
F_54 ( V_34 -> V_103 ) |
F_55 ( V_34 -> V_102 ) |
F_56 ( V_34 -> V_103 ) ;
F_18 ( V_42 , V_12 -> V_44 + F_57 ( V_82 , 0 ) ) ;
V_42 = F_58 ( V_34 -> V_91 ) |
F_59 ( V_34 -> V_93 ) |
F_60 ( V_34 -> V_91 ) |
F_61 ( V_34 -> V_93 ) ;
F_18 ( V_42 , V_12 -> V_44 + F_62 ( V_82 ) ) ;
V_135 = V_34 -> V_91 + V_34 -> V_95 ;
if ( V_135 )
V_135 -- ;
V_136 = V_34 -> V_93 + V_34 -> V_97 ;
if ( V_136 )
V_136 -- ;
V_42 = F_63 ( V_135 ) | F_64 ( V_136 ) |
F_65 ( V_135 ) | F_66 ( V_136 ) ;
F_18 ( V_42 , V_12 -> V_44 + F_67 ( V_82 ) ) ;
F_11 ( L_13 ,
V_34 -> V_91 , V_34 -> V_93 , V_135 , V_136 ) ;
if ( V_82 != 0 ) {
V_133 = F_68 ( 0xf ) |
F_69 ( 0xf ) |
F_70 ( 0xf ) ;
F_18 ( V_133 , V_12 -> V_44 + F_71 ( V_82 ) ) ;
}
if ( V_82 != 3 && V_82 != 4 ) {
T_1 V_83 = F_72 ( V_82 ) ;
if ( V_82 == 0 )
V_83 = F_71 ( V_82 ) ;
V_42 = V_34 -> V_95 * V_34 -> V_97 ;
F_18 ( V_42 , V_12 -> V_44 + V_83 ) ;
F_11 ( L_14 , ( unsigned int ) V_42 ) ;
}
F_41 ( V_7 , V_82 ) ;
if ( V_82 != 0 )
F_43 ( V_7 , V_82 ) ;
V_42 = F_32 ( V_12 -> V_44 + F_42 ( V_82 ) ) ;
V_42 |= V_104 ;
F_18 ( V_42 , V_12 -> V_44 + F_42 ( V_82 ) ) ;
F_48 ( V_12 , V_82 , false ) ;
if ( V_12 -> V_9 -> V_129 ) {
V_42 = F_32 ( V_12 -> V_44 + V_130 ) ;
V_42 |= F_73 ( V_82 ) ;
F_18 ( V_42 , V_12 -> V_44 + V_130 ) ;
}
V_34 -> V_37 = true ;
}
static void F_74 ( struct V_10 * V_7 , int V_84 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_33 * V_34 ;
int V_82 = V_84 ;
T_1 V_42 ;
if ( V_82 == V_85 )
V_82 = V_12 -> V_86 ;
if ( V_82 < 0 || V_82 >= V_36 )
return;
V_34 = & V_12 -> V_34 [ V_82 ] ;
if ( V_12 -> V_19 ) {
V_34 -> V_137 = false ;
return;
}
F_48 ( V_12 , V_82 , true ) ;
V_42 = F_32 ( V_12 -> V_44 + F_42 ( V_82 ) ) ;
V_42 &= ~ V_104 ;
F_18 ( V_42 , V_12 -> V_44 + F_42 ( V_82 ) ) ;
if ( V_12 -> V_9 -> V_129 ) {
V_42 = F_32 ( V_12 -> V_44 + V_130 ) ;
V_42 &= ~ F_73 ( V_82 ) ;
F_18 ( V_42 , V_12 -> V_44 + V_130 ) ;
}
F_48 ( V_12 , V_82 , false ) ;
V_34 -> V_37 = false ;
}
static T_2 F_75 ( int V_138 , void * V_139 )
{
struct V_11 * V_12 = (struct V_11 * ) V_139 ;
struct V_140 * V_25 = & V_12 -> V_25 ;
struct V_141 * V_142 = V_25 -> V_142 ;
struct V_23 * V_26 = V_25 -> V_26 ;
T_1 V_42 ;
V_42 = F_32 ( V_12 -> V_44 + V_143 ) ;
if ( V_42 & V_144 )
F_18 ( V_144 , V_12 -> V_44 + V_143 ) ;
if ( V_26 -> V_145 < 0 )
goto V_146;
F_76 ( V_142 , V_26 -> V_145 ) ;
F_77 ( V_142 , V_26 -> V_145 ) ;
if ( F_38 ( & V_12 -> V_77 ) ) {
F_36 ( & V_12 -> V_77 , 0 ) ;
F_78 ( & V_12 -> V_78 ) ;
}
V_146:
return V_147 ;
}
static int F_79 ( struct V_141 * V_142 , struct V_10 * V_7 )
{
V_142 -> V_148 = 1 ;
V_142 -> V_149 = 1 ;
if ( F_80 ( V_142 ) )
F_81 ( V_142 , V_7 ) ;
return 0 ;
}
static void F_82 ( struct V_141 * V_142 , struct V_10 * V_7 )
{
if ( F_80 ( V_142 ) )
F_83 ( V_142 , V_7 ) ;
}
static int F_84 ( struct V_11 * V_12 ,
struct V_40 * V_41 )
{
unsigned long V_150 = F_85 ( V_12 -> V_151 ) ;
T_1 V_152 ;
T_1 V_64 ;
T_1 V_153 = 0 ;
T_1 V_154 ;
V_152 = V_41 -> V_51 + V_41 -> V_53 +
V_41 -> V_52 + V_41 -> V_56 ;
V_152 *= V_41 -> V_47 + V_41 -> V_49 +
V_41 -> V_48 + V_41 -> V_55 ;
if ( ! V_41 -> V_155 )
V_41 -> V_155 = 60 ;
V_150 /= V_152 ;
for ( V_64 = 1 ; V_64 < 0x100 ; V_64 ++ ) {
int V_156 ;
V_154 = V_150 / V_64 ;
V_156 = V_41 -> V_155 - V_154 ;
if ( V_156 < 0 ) {
V_153 = V_154 ;
continue;
} else {
if ( ! V_153 )
V_153 = V_154 ;
else if ( V_156 < ( V_153 - V_154 ) )
V_153 = V_154 ;
break;
}
}
return V_64 ;
}
static void F_86 ( struct V_11 * V_12 , int V_82 )
{
F_18 ( 0 , V_12 -> V_44 + F_42 ( V_82 ) ) ;
F_18 ( 0 , V_12 -> V_44 + F_62 ( V_82 ) ) ;
F_18 ( 0 , V_12 -> V_44 + F_67 ( V_82 ) ) ;
F_18 ( 0 , V_12 -> V_44 + F_71 ( V_82 ) ) ;
if ( V_82 == 1 || V_82 == 2 )
F_18 ( 0 , V_12 -> V_44 + F_72 ( V_82 ) ) ;
F_48 ( V_12 , V_82 , false ) ;
}
static int F_87 ( struct V_11 * V_12 , bool V_157 )
{
if ( V_157 ) {
int V_158 ;
V_158 = F_88 ( V_12 -> V_159 ) ;
if ( V_158 < 0 )
return V_158 ;
V_158 = F_88 ( V_12 -> V_151 ) ;
if ( V_158 < 0 ) {
F_89 ( V_12 -> V_159 ) ;
return V_158 ;
}
} else {
F_89 ( V_12 -> V_151 ) ;
F_89 ( V_12 -> V_159 ) ;
}
return 0 ;
}
static void F_90 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_33 * V_34 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_34 = & V_12 -> V_34 [ V_35 ] ;
V_34 -> V_137 = V_34 -> V_37 ;
F_74 ( V_7 , V_35 ) ;
}
F_35 ( V_7 ) ;
}
static void F_91 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_33 * V_34 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_34 = & V_12 -> V_34 [ V_35 ] ;
V_34 -> V_37 = V_34 -> V_137 ;
V_34 -> V_137 = false ;
}
}
static int F_92 ( struct V_11 * V_12 , bool V_157 )
{
struct V_10 * V_7 = V_12 -> V_25 . V_7 ;
if ( V_157 ) {
int V_158 ;
V_158 = F_87 ( V_12 , true ) ;
if ( V_158 < 0 )
return V_158 ;
V_12 -> V_19 = false ;
if ( F_34 ( 0 , & V_12 -> V_69 ) )
F_30 ( V_7 ) ;
F_91 ( V_7 ) ;
} else {
F_90 ( V_7 ) ;
F_87 ( V_12 , false ) ;
V_12 -> V_19 = true ;
}
return 0 ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_10 * V_7 = & V_3 -> V_7 ;
struct V_11 * V_12 ;
struct V_140 * V_25 ;
struct V_160 * V_161 ;
struct V_39 * V_13 ;
struct V_162 * V_163 ;
int V_82 ;
int V_158 = - V_164 ;
if ( V_7 -> V_165 ) {
V_161 = F_94 ( V_7 , sizeof( * V_161 ) , V_166 ) ;
if ( ! V_161 ) {
F_95 ( L_15 ) ;
return - V_167 ;
}
V_158 = F_96 ( V_7 -> V_165 , & V_161 -> V_13 . V_41 ,
V_168 ) ;
if ( V_158 ) {
F_95 ( L_16 , V_158 ) ;
return V_158 ;
}
} else {
V_161 = V_7 -> V_169 ;
if ( ! V_161 ) {
F_95 ( L_17 ) ;
return - V_164 ;
}
}
V_13 = & V_161 -> V_13 ;
if ( ! V_13 ) {
F_40 ( V_7 , L_18 ) ;
return - V_164 ;
}
V_12 = F_94 ( V_7 , sizeof( * V_12 ) , V_166 ) ;
if ( ! V_12 )
return - V_167 ;
V_12 -> V_159 = F_97 ( V_7 , L_19 ) ;
if ( F_98 ( V_12 -> V_159 ) ) {
F_40 ( V_7 , L_20 ) ;
return F_99 ( V_12 -> V_159 ) ;
}
V_12 -> V_151 = F_97 ( V_7 , L_21 ) ;
if ( F_98 ( V_12 -> V_151 ) ) {
F_40 ( V_7 , L_22 ) ;
return F_99 ( V_12 -> V_151 ) ;
}
V_163 = F_100 ( V_3 , V_170 , 0 ) ;
V_12 -> V_44 = F_101 ( V_7 , V_163 ) ;
if ( F_98 ( V_12 -> V_44 ) )
return F_99 ( V_12 -> V_44 ) ;
V_163 = F_102 ( V_3 , V_171 , L_23 ) ;
if ( ! V_163 ) {
F_40 ( V_7 , L_24 ) ;
return - V_172 ;
}
V_12 -> V_138 = V_163 -> V_173 ;
V_158 = F_103 ( V_7 , V_12 -> V_138 , F_75 ,
0 , L_25 , V_12 ) ;
if ( V_158 ) {
F_40 ( V_7 , L_24 ) ;
return V_158 ;
}
V_12 -> V_9 = F_1 ( V_3 ) ;
V_12 -> V_58 = V_161 -> V_58 ;
V_12 -> V_43 = V_161 -> V_43 ;
V_12 -> V_86 = V_161 -> V_86 ;
V_12 -> V_13 = V_13 ;
F_104 ( & V_12 -> V_78 ) ;
F_36 ( & V_12 -> V_77 , 0 ) ;
V_25 = & V_12 -> V_25 ;
V_25 -> V_7 = V_7 ;
V_25 -> V_26 = & V_174 ;
V_25 -> V_175 = F_79 ;
V_25 -> remove = F_82 ;
F_105 ( & V_12 -> V_17 ) ;
F_106 ( V_3 , V_12 ) ;
F_107 ( V_7 ) ;
F_13 ( V_7 ) ;
V_12 -> V_64 = F_84 ( V_12 , & V_13 -> V_41 ) ;
V_13 -> V_41 . V_176 = F_85 ( V_12 -> V_151 ) / V_12 -> V_64 ;
F_11 ( L_26 ,
V_13 -> V_41 . V_176 , V_12 -> V_64 ) ;
for ( V_82 = 0 ; V_82 < V_36 ; V_82 ++ )
F_86 ( V_12 , V_82 ) ;
F_108 ( V_25 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_10 * V_7 = & V_3 -> V_7 ;
struct V_11 * V_12 = F_110 ( V_3 ) ;
F_111 ( & V_12 -> V_25 ) ;
if ( V_12 -> V_19 )
goto V_146;
F_112 ( V_7 ) ;
F_14 ( V_7 ) ;
V_146:
F_113 ( V_7 ) ;
return 0 ;
}
static int F_114 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
if ( ! F_115 ( V_7 ) )
return F_92 ( V_12 , false ) ;
return 0 ;
}
static int F_116 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
if ( ! F_115 ( V_7 ) ) {
int V_158 ;
V_158 = F_92 ( V_12 , true ) ;
if ( V_158 < 0 )
return V_158 ;
F_16 ( V_7 ) ;
}
return 0 ;
}
static int F_117 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
return F_92 ( V_12 , false ) ;
}
static int F_118 ( struct V_10 * V_7 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
return F_92 ( V_12 , true ) ;
}
