static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
return (struct V_1 * )
F_2 ( V_3 ) -> V_4 ;
}
static bool F_3 ( struct V_5 * V_6 )
{
F_4 ( L_1 , __FILE__ ) ;
return true ;
}
static void * F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
F_4 ( L_1 , __FILE__ ) ;
return V_8 -> V_9 ;
}
static int F_7 ( struct V_5 * V_6 , void * V_10 )
{
F_4 ( L_1 , __FILE__ ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , int V_11 )
{
F_4 ( L_1 , __FILE__ ) ;
return 0 ;
}
static void F_9 ( struct V_5 * V_12 , int V_11 )
{
struct V_7 * V_8 = F_6 ( V_12 ) ;
F_4 ( L_2 , __FILE__ , V_11 ) ;
F_10 ( & V_8 -> V_13 ) ;
switch ( V_11 ) {
case V_14 :
if ( V_8 -> V_15 )
F_11 ( V_12 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
if ( ! V_8 -> V_15 )
F_12 ( V_12 ) ;
break;
default:
F_4 ( L_3 , V_11 ) ;
break;
}
F_13 ( & V_8 -> V_13 ) ;
}
static void F_14 ( struct V_5 * V_12 )
{
struct V_7 * V_8 = F_6 ( V_12 ) ;
struct V_19 * V_20 = V_8 -> V_21 . V_22 ;
struct V_23 * V_24 = V_20 -> V_25 ;
struct V_26 * V_27 = V_20 -> V_28 ;
struct V_29 * V_30 ;
int V_31 ;
F_4 ( L_1 , __FILE__ ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_30 = & V_8 -> V_30 [ V_31 ] ;
if ( V_30 -> V_33 && ( V_27 && V_27 -> V_34 ) )
V_27 -> V_34 ( V_12 , V_31 ) ;
}
if ( V_24 && V_24 -> V_34 )
V_24 -> V_34 ( V_12 ) ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_35 * V_9 = V_8 -> V_9 ;
struct V_36 * V_10 = & V_9 -> V_10 ;
struct V_1 * V_4 ;
struct V_2 * V_3 = F_16 ( V_6 ) ;
T_1 V_37 ;
V_4 = F_1 ( V_3 ) ;
if ( V_8 -> V_15 )
return;
F_4 ( L_1 , __FILE__ ) ;
F_17 ( V_8 -> V_38 , V_8 -> V_39 + V_4 -> V_40 + V_41 ) ;
V_37 = F_18 ( V_10 -> V_42 - 1 ) |
F_19 ( V_10 -> V_43 - 1 ) |
F_20 ( V_10 -> V_44 - 1 ) ;
F_17 ( V_37 , V_8 -> V_39 + V_4 -> V_40 + V_45 ) ;
V_37 = F_21 ( V_10 -> V_46 - 1 ) |
F_22 ( V_10 -> V_47 - 1 ) |
F_23 ( V_10 -> V_48 - 1 ) ;
F_17 ( V_37 , V_8 -> V_39 + V_4 -> V_40 + V_49 ) ;
V_37 = F_24 ( V_10 -> V_50 - 1 ) |
F_25 ( V_10 -> V_51 - 1 ) ;
F_17 ( V_37 , V_8 -> V_39 + V_4 -> V_40 + V_52 ) ;
V_37 = V_8 -> V_53 ;
V_37 &= ~ ( V_54 | V_55 ) ;
if ( V_8 -> V_56 > 1 )
V_37 |= F_26 ( V_8 -> V_56 - 1 ) | V_55 ;
else
V_37 &= ~ V_55 ;
V_37 |= V_57 | V_58 ;
F_17 ( V_37 , V_8 -> V_39 + V_59 ) ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
T_1 V_37 ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_8 -> V_15 )
return - V_60 ;
if ( ! F_28 ( 0 , & V_8 -> V_61 ) ) {
V_37 = F_29 ( V_8 -> V_39 + V_62 ) ;
V_37 |= V_63 ;
V_37 |= V_64 ;
V_37 &= ~ V_65 ;
V_37 |= V_66 ;
V_37 &= ~ V_67 ;
V_37 |= V_68 ;
F_17 ( V_37 , V_8 -> V_39 + V_62 ) ;
}
return 0 ;
}
static void F_30 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
T_1 V_37 ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_8 -> V_15 )
return;
if ( F_31 ( 0 , & V_8 -> V_61 ) ) {
V_37 = F_29 ( V_8 -> V_39 + V_62 ) ;
V_37 &= ~ V_64 ;
V_37 &= ~ V_63 ;
F_17 ( V_37 , V_8 -> V_39 + V_62 ) ;
}
}
static void F_32 ( struct V_5 * V_6 ,
struct V_69 * V_70 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_29 * V_30 ;
int V_71 ;
unsigned long V_72 ;
F_4 ( L_1 , __FILE__ ) ;
if ( ! V_70 ) {
F_33 ( V_6 , L_4 ) ;
return;
}
V_71 = V_70 -> V_73 ;
if ( V_71 == V_74 )
V_71 = V_8 -> V_75 ;
if ( V_71 < 0 || V_71 > V_32 )
return;
V_72 = V_70 -> V_76 * ( V_70 -> V_77 >> 3 ) ;
V_72 += V_70 -> V_78 * V_70 -> V_79 ;
F_4 ( L_5 , V_72 , V_70 -> V_79 ) ;
V_30 = & V_8 -> V_30 [ V_71 ] ;
V_30 -> V_80 = V_70 -> V_81 ;
V_30 -> V_82 = V_70 -> V_83 ;
V_30 -> V_84 = V_70 -> V_85 ;
V_30 -> V_86 = V_70 -> V_87 ;
V_30 -> V_88 = V_70 -> V_88 ;
V_30 -> V_89 = V_70 -> V_89 ;
V_30 -> V_90 = V_70 -> V_90 [ 0 ] + V_72 ;
V_30 -> V_91 = V_70 -> V_91 [ 0 ] + V_72 ;
V_30 -> V_77 = V_70 -> V_77 ;
V_30 -> V_92 = ( V_70 -> V_88 - V_70 -> V_85 ) *
( V_70 -> V_77 >> 3 ) ;
V_30 -> V_93 = V_70 -> V_85 * ( V_70 -> V_77 >> 3 ) ;
F_4 ( L_6 ,
V_30 -> V_80 , V_30 -> V_82 ) ;
F_4 ( L_7 ,
V_30 -> V_84 , V_30 -> V_86 ) ;
F_4 ( L_8 ,
( unsigned long ) V_30 -> V_90 ,
( unsigned long ) V_30 -> V_91 ) ;
F_4 ( L_9 ,
V_70 -> V_88 , V_70 -> V_85 ) ;
}
static void F_34 ( struct V_5 * V_6 , unsigned int V_71 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_29 * V_30 = & V_8 -> V_30 [ V_71 ] ;
unsigned long V_37 ;
F_4 ( L_1 , __FILE__ ) ;
V_37 = V_94 ;
switch ( V_30 -> V_77 ) {
case 1 :
V_37 |= V_95 ;
V_37 |= V_96 ;
V_37 |= V_97 ;
break;
case 2 :
V_37 |= V_98 ;
V_37 |= V_96 ;
V_37 |= V_99 ;
break;
case 4 :
V_37 |= V_100 ;
V_37 |= V_96 ;
V_37 |= V_99 ;
break;
case 8 :
V_37 |= V_101 ;
V_37 |= V_99 ;
V_37 |= V_102 ;
break;
case 16 :
V_37 |= V_103 ;
V_37 |= V_104 ;
V_37 |= V_105 ;
break;
case 24 :
V_37 |= V_106 ;
V_37 |= V_107 ;
V_37 |= V_105 ;
break;
case 32 :
V_37 |= V_108
| V_109 | V_110 ;
V_37 |= V_107 ;
V_37 |= V_105 ;
break;
default:
F_4 ( L_10 ) ;
V_37 |= V_106 ;
V_37 |= V_107 ;
V_37 |= V_105 ;
break;
}
F_4 ( L_11 , V_30 -> V_77 ) ;
F_17 ( V_37 , V_8 -> V_39 + F_35 ( V_71 ) ) ;
}
static void F_36 ( struct V_5 * V_6 , unsigned int V_71 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
unsigned int V_111 = 0 , V_112 = 0 ;
F_4 ( L_1 , __FILE__ ) ;
V_111 = ~ ( V_113 | V_114 |
V_115 ) | F_37 ( 0 ) ;
V_112 = F_38 ( 0xffffffff ) ;
F_17 ( V_111 , V_8 -> V_39 + F_39 ( V_71 ) ) ;
F_17 ( V_112 , V_8 -> V_39 + F_40 ( V_71 ) ) ;
}
static void F_41 ( struct V_5 * V_6 , int V_73 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_29 * V_30 ;
int V_71 = V_73 ;
unsigned long V_37 , V_116 , V_117 ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_8 -> V_15 )
return;
if ( V_71 == V_74 )
V_71 = V_8 -> V_75 ;
if ( V_71 < 0 || V_71 > V_32 )
return;
V_30 = & V_8 -> V_30 [ V_71 ] ;
V_37 = F_29 ( V_8 -> V_39 + V_118 ) ;
V_37 |= F_42 ( V_71 ) ;
F_17 ( V_37 , V_8 -> V_39 + V_118 ) ;
V_37 = ( unsigned long ) V_30 -> V_90 ;
F_17 ( V_37 , V_8 -> V_39 + F_43 ( V_71 , 0 ) ) ;
V_117 = V_30 -> V_88 * V_30 -> V_86 * ( V_30 -> V_77 >> 3 ) ;
V_37 = ( unsigned long ) ( V_30 -> V_90 + V_117 ) ;
F_17 ( V_37 , V_8 -> V_39 + F_44 ( V_71 , 0 ) ) ;
F_4 ( L_12 ,
( unsigned long ) V_30 -> V_90 , V_37 , V_117 ) ;
F_4 ( L_7 ,
V_30 -> V_84 , V_30 -> V_86 ) ;
V_37 = F_45 ( V_30 -> V_92 ) |
F_46 ( V_30 -> V_93 ) ;
F_17 ( V_37 , V_8 -> V_39 + F_47 ( V_71 , 0 ) ) ;
V_37 = F_48 ( V_30 -> V_80 ) |
F_49 ( V_30 -> V_82 ) ;
F_17 ( V_37 , V_8 -> V_39 + F_50 ( V_71 ) ) ;
V_37 = F_51 ( V_30 -> V_80 +
V_30 -> V_84 - 1 ) |
F_52 ( V_30 -> V_82 +
V_30 -> V_86 - 1 ) ;
F_17 ( V_37 , V_8 -> V_39 + F_53 ( V_71 ) ) ;
F_4 ( L_13 ,
V_30 -> V_80 , V_30 -> V_82 ,
V_30 -> V_80 + V_30 -> V_84 - 1 ,
V_30 -> V_82 + V_30 -> V_86 - 1 ) ;
if ( V_71 != 0 ) {
V_116 = F_54 ( 0xf ) |
F_55 ( 0xf ) |
F_56 ( 0xf ) ;
F_17 ( V_116 , V_8 -> V_39 + F_57 ( V_71 ) ) ;
}
if ( V_71 != 3 && V_71 != 4 ) {
T_1 V_72 = F_58 ( V_71 ) ;
if ( V_71 == 0 )
V_72 = V_119 ;
V_37 = V_30 -> V_84 * V_30 -> V_86 ;
F_17 ( V_37 , V_8 -> V_39 + V_72 ) ;
F_4 ( L_14 , ( unsigned int ) V_37 ) ;
}
F_34 ( V_6 , V_71 ) ;
if ( V_71 != 0 )
F_36 ( V_6 , V_71 ) ;
V_37 = F_29 ( V_8 -> V_39 + F_35 ( V_71 ) ) ;
V_37 |= V_94 ;
F_17 ( V_37 , V_8 -> V_39 + F_35 ( V_71 ) ) ;
V_37 = F_29 ( V_8 -> V_39 + V_118 ) ;
V_37 |= F_59 ( V_71 ) ;
V_37 &= ~ F_42 ( V_71 ) ;
F_17 ( V_37 , V_8 -> V_39 + V_118 ) ;
V_30 -> V_33 = true ;
}
static void F_60 ( struct V_5 * V_6 , int V_73 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
struct V_29 * V_30 ;
int V_71 = V_73 ;
T_1 V_37 ;
F_4 ( L_1 , __FILE__ ) ;
if ( V_71 == V_74 )
V_71 = V_8 -> V_75 ;
if ( V_71 < 0 || V_71 > V_32 )
return;
V_30 = & V_8 -> V_30 [ V_71 ] ;
V_37 = F_29 ( V_8 -> V_39 + V_118 ) ;
V_37 |= F_42 ( V_71 ) ;
F_17 ( V_37 , V_8 -> V_39 + V_118 ) ;
V_37 = F_29 ( V_8 -> V_39 + F_35 ( V_71 ) ) ;
V_37 &= ~ V_94 ;
F_17 ( V_37 , V_8 -> V_39 + F_35 ( V_71 ) ) ;
V_37 = F_29 ( V_8 -> V_39 + V_118 ) ;
V_37 &= ~ F_59 ( V_71 ) ;
V_37 &= ~ F_42 ( V_71 ) ;
F_17 ( V_37 , V_8 -> V_39 + V_118 ) ;
V_30 -> V_33 = false ;
}
static void F_61 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
int V_120 ;
V_120 = F_62 ( ( F_63 ( V_8 -> V_39 + V_41 ) &
V_121 ) , 50 ) ;
if ( V_120 < 0 )
F_4 ( L_15 ) ;
}
static void F_64 ( struct V_122 * V_123 , int V_124 )
{
struct V_125 * V_126 = V_123 -> V_127 ;
struct V_128 * V_129 , * V_130 ;
struct V_131 V_132 ;
unsigned long V_133 ;
bool V_134 = false ;
F_65 ( & V_123 -> V_135 , V_133 ) ;
F_66 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_124 != V_129 -> V_136 )
continue;
V_134 = true ;
F_67 ( & V_132 ) ;
V_129 -> V_137 . V_138 = 0 ;
V_129 -> V_137 . V_139 = V_132 . V_139 ;
V_129 -> V_137 . V_140 = V_132 . V_140 ;
F_68 ( & V_129 -> V_141 . V_142 , & V_129 -> V_141 . V_143 -> V_144 ) ;
F_69 ( & V_129 -> V_141 . V_143 -> V_145 ) ;
}
if ( V_134 ) {
if ( F_70 ( & V_123 -> V_146 [ V_124 ] ) > 0 )
F_71 ( V_123 , V_124 ) ;
if ( ! V_123 -> V_147 )
F_72 ( V_123 , V_124 ) ;
}
F_73 ( & V_123 -> V_135 , V_133 ) ;
}
static T_2 F_74 ( int V_148 , void * V_149 )
{
struct V_7 * V_8 = (struct V_7 * ) V_149 ;
struct V_150 * V_21 = & V_8 -> V_21 ;
struct V_122 * V_123 = V_21 -> V_123 ;
struct V_19 * V_22 = V_21 -> V_22 ;
T_1 V_37 ;
V_37 = F_29 ( V_8 -> V_39 + V_151 ) ;
if ( V_37 & V_152 )
F_17 ( V_152 , V_8 -> V_39 + V_151 ) ;
if ( V_22 -> V_136 < 0 )
goto V_153;
F_75 ( V_123 , V_22 -> V_136 ) ;
F_64 ( V_123 , V_22 -> V_136 ) ;
V_153:
return V_154 ;
}
static int F_76 ( struct V_122 * V_123 , struct V_5 * V_6 )
{
F_4 ( L_1 , __FILE__ ) ;
V_123 -> V_155 = 1 ;
V_123 -> V_147 = 1 ;
return 0 ;
}
static void F_77 ( struct V_122 * V_123 , struct V_5 * V_6 )
{
F_4 ( L_1 , __FILE__ ) ;
}
static int F_78 ( struct V_7 * V_8 ,
struct V_36 * V_10 )
{
unsigned long V_156 = F_79 ( V_8 -> V_157 ) ;
T_1 V_158 ;
T_1 V_56 ;
T_1 V_159 = 0 ;
T_1 V_160 ;
F_4 ( L_1 , __FILE__ ) ;
V_158 = V_10 -> V_46 + V_10 -> V_48 +
V_10 -> V_47 + V_10 -> V_51 ;
V_158 *= V_10 -> V_42 + V_10 -> V_44 +
V_10 -> V_43 + V_10 -> V_50 ;
if ( ! V_10 -> V_161 )
V_10 -> V_161 = 60 ;
V_156 /= V_158 ;
for ( V_56 = 1 ; V_56 < 0x100 ; V_56 ++ ) {
int V_162 ;
V_160 = V_156 / V_56 ;
V_162 = V_10 -> V_161 - V_160 ;
if ( V_162 < 0 ) {
V_159 = V_160 ;
continue;
} else {
if ( ! V_159 )
V_159 = V_160 ;
else if ( V_162 < ( V_159 - V_160 ) )
V_159 = V_160 ;
break;
}
}
return V_56 ;
}
static void F_80 ( struct V_7 * V_8 , int V_71 )
{
T_1 V_37 ;
F_4 ( L_1 , __FILE__ ) ;
F_17 ( 0 , V_8 -> V_39 + F_35 ( V_71 ) ) ;
F_17 ( 0 , V_8 -> V_39 + F_50 ( V_71 ) ) ;
F_17 ( 0 , V_8 -> V_39 + F_53 ( V_71 ) ) ;
F_17 ( 0 , V_8 -> V_39 + F_57 ( V_71 ) ) ;
if ( V_71 == 1 || V_71 == 2 )
F_17 ( 0 , V_8 -> V_39 + F_58 ( V_71 ) ) ;
V_37 = F_29 ( V_8 -> V_39 + V_118 ) ;
V_37 &= ~ F_42 ( V_71 ) ;
F_17 ( V_37 , V_8 -> V_39 + V_118 ) ;
}
static int F_81 ( struct V_7 * V_8 , bool V_163 )
{
F_4 ( L_1 , __FILE__ ) ;
if ( V_163 ) {
int V_120 ;
V_120 = F_82 ( V_8 -> V_164 ) ;
if ( V_120 < 0 )
return V_120 ;
V_120 = F_82 ( V_8 -> V_157 ) ;
if ( V_120 < 0 ) {
F_83 ( V_8 -> V_164 ) ;
return V_120 ;
}
} else {
F_83 ( V_8 -> V_157 ) ;
F_83 ( V_8 -> V_164 ) ;
}
return 0 ;
}
static int F_84 ( struct V_7 * V_8 , bool V_163 )
{
if ( V_163 ) {
int V_120 ;
struct V_5 * V_6 = V_8 -> V_21 . V_6 ;
V_120 = F_81 ( V_8 , true ) ;
if ( V_120 < 0 )
return V_120 ;
V_8 -> V_15 = false ;
if ( F_31 ( 0 , & V_8 -> V_61 ) )
F_27 ( V_6 ) ;
} else {
F_81 ( V_8 , false ) ;
V_8 -> V_15 = true ;
}
return 0 ;
}
static int T_3 F_85 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = & V_3 -> V_6 ;
struct V_7 * V_8 ;
struct V_150 * V_21 ;
struct V_165 * V_166 ;
struct V_35 * V_9 ;
struct V_167 * V_168 ;
int V_71 ;
int V_120 = - V_169 ;
F_4 ( L_1 , __FILE__ ) ;
V_166 = V_3 -> V_6 . V_170 ;
if ( ! V_166 ) {
F_33 ( V_6 , L_16 ) ;
return - V_169 ;
}
V_9 = & V_166 -> V_9 ;
if ( ! V_9 ) {
F_33 ( V_6 , L_17 ) ;
return - V_169 ;
}
V_8 = F_86 ( & V_3 -> V_6 , sizeof( * V_8 ) , V_171 ) ;
if ( ! V_8 )
return - V_172 ;
V_8 -> V_164 = F_87 ( V_6 , L_18 ) ;
if ( F_88 ( V_8 -> V_164 ) ) {
F_33 ( V_6 , L_19 ) ;
V_120 = F_89 ( V_8 -> V_164 ) ;
goto V_173;
}
V_8 -> V_157 = F_87 ( V_6 , L_20 ) ;
if ( F_88 ( V_8 -> V_157 ) ) {
F_33 ( V_6 , L_21 ) ;
V_120 = F_89 ( V_8 -> V_157 ) ;
goto V_174;
}
V_168 = F_90 ( V_3 , V_175 , 0 ) ;
V_8 -> V_39 = F_91 ( & V_3 -> V_6 , V_168 ) ;
if ( ! V_8 -> V_39 ) {
F_33 ( V_6 , L_22 ) ;
V_120 = - V_176 ;
goto V_177;
}
V_168 = F_90 ( V_3 , V_178 , 0 ) ;
if ( ! V_168 ) {
F_33 ( V_6 , L_23 ) ;
goto V_177;
}
V_8 -> V_148 = V_168 -> V_179 ;
V_120 = F_92 ( & V_3 -> V_6 , V_8 -> V_148 , F_74 ,
0 , L_24 , V_8 ) ;
if ( V_120 ) {
F_33 ( V_6 , L_23 ) ;
goto V_177;
}
V_8 -> V_53 = V_166 -> V_53 ;
V_8 -> V_38 = V_166 -> V_38 ;
V_8 -> V_75 = V_166 -> V_75 ;
V_8 -> V_9 = V_9 ;
V_21 = & V_8 -> V_21 ;
V_21 -> V_6 = V_6 ;
V_21 -> V_22 = & V_180 ;
V_21 -> V_181 = F_76 ;
V_21 -> remove = F_77 ;
F_93 ( & V_8 -> V_13 ) ;
F_94 ( V_3 , V_8 ) ;
F_95 ( V_6 ) ;
F_11 ( V_6 ) ;
V_8 -> V_56 = F_78 ( V_8 , & V_9 -> V_10 ) ;
V_9 -> V_10 . V_182 = F_79 ( V_8 -> V_157 ) / V_8 -> V_56 ;
F_4 ( L_25 ,
V_9 -> V_10 . V_182 , V_8 -> V_56 ) ;
for ( V_71 = 0 ; V_71 < V_32 ; V_71 ++ )
F_80 ( V_8 , V_71 ) ;
F_96 ( V_21 ) ;
return 0 ;
V_177:
F_83 ( V_8 -> V_157 ) ;
F_97 ( V_8 -> V_157 ) ;
V_174:
F_83 ( V_8 -> V_164 ) ;
F_97 ( V_8 -> V_164 ) ;
V_173:
return V_120 ;
}
static int T_4 F_98 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = & V_3 -> V_6 ;
struct V_7 * V_8 = F_99 ( V_3 ) ;
F_4 ( L_1 , __FILE__ ) ;
F_100 ( & V_8 -> V_21 ) ;
if ( V_8 -> V_15 )
goto V_153;
F_83 ( V_8 -> V_157 ) ;
F_83 ( V_8 -> V_164 ) ;
F_101 ( V_6 ) ;
F_12 ( V_6 ) ;
V_153:
F_102 ( V_6 ) ;
F_97 ( V_8 -> V_157 ) ;
F_97 ( V_8 -> V_164 ) ;
return 0 ;
}
static int F_103 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
if ( ! F_104 ( V_6 ) )
return F_84 ( V_8 , false ) ;
return 0 ;
}
static int F_105 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
if ( F_104 ( V_6 ) ) {
int V_120 ;
V_120 = F_84 ( V_8 , true ) ;
if ( V_120 < 0 )
return V_120 ;
F_14 ( V_6 ) ;
}
return 0 ;
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
F_4 ( L_1 , __FILE__ ) ;
return F_84 ( V_8 , false ) ;
}
static int F_107 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_6 ( V_6 ) ;
F_4 ( L_1 , __FILE__ ) ;
return F_84 ( V_8 , true ) ;
}
