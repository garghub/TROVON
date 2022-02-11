static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
const struct V_4 * V_5 =
F_2 ( V_6 , & V_3 -> V_7 ) ;
return (struct V_1 * ) V_5 -> V_8 ;
}
static int F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 , int V_13 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
V_15 -> V_12 = V_12 ;
V_15 -> V_13 = V_13 ;
V_12 -> V_16 = true ;
V_12 -> V_17 = true ;
if ( F_4 ( V_15 -> V_12 ) )
F_5 ( V_15 -> V_12 , V_15 -> V_7 ) ;
return 0 ;
}
static void F_6 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
if ( F_4 ( V_15 -> V_12 ) )
F_7 ( V_15 -> V_12 , V_15 -> V_7 ) ;
}
static T_1 F_8 ( struct V_14 * V_15 ,
const struct V_18 * V_19 )
{
unsigned long V_20 = V_19 -> V_21 * V_19 -> V_22 * V_19 -> V_23 ;
T_1 V_24 ;
V_24 = F_9 ( F_10 ( V_15 -> V_25 ) , V_20 ) ;
return ( V_24 < 0x100 ) ? V_24 : 0xff ;
}
static bool F_11 ( struct V_9 * V_10 ,
const struct V_18 * V_19 ,
struct V_18 * V_26 )
{
if ( V_26 -> V_23 == 0 )
V_26 -> V_23 = V_27 ;
return true ;
}
static void F_12 ( struct V_9 * V_10 ,
const struct V_18 * V_28 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
F_13 ( & V_15 -> V_19 , V_28 ) ;
}
static void F_14 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_18 * V_19 = & V_15 -> V_19 ;
struct V_1 * V_29 ;
T_1 V_30 , V_24 , V_31 ;
int V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ;
V_29 = V_15 -> V_29 ;
if ( V_15 -> V_38 )
return;
if ( V_19 -> V_21 == 0 || V_19 -> V_22 == 0 )
return;
V_31 = V_15 -> V_31 ;
if ( V_19 -> V_39 & V_40 )
V_31 |= V_41 ;
if ( V_19 -> V_39 & V_42 )
V_31 |= V_43 ;
F_15 ( V_31 , V_15 -> V_44 + V_29 -> V_45 + V_46 ) ;
V_32 = V_19 -> V_47 - V_19 -> V_48 ;
V_33 = V_19 -> V_49 - V_19 -> V_47 ;
V_34 = V_19 -> V_48 - V_19 -> V_50 ;
V_30 = F_16 ( V_33 - 1 ) |
F_17 ( V_34 - 1 ) |
F_18 ( V_32 - 1 ) ;
F_15 ( V_30 , V_15 -> V_44 + V_29 -> V_45 + V_51 ) ;
V_35 = V_19 -> V_52 - V_19 -> V_53 ;
V_36 = V_19 -> V_54 - V_19 -> V_52 ;
V_37 = V_19 -> V_53 - V_19 -> V_55 ;
V_30 = F_19 ( V_36 - 1 ) |
F_20 ( V_37 - 1 ) |
F_21 ( V_35 - 1 ) ;
F_15 ( V_30 , V_15 -> V_44 + V_29 -> V_45 + V_56 ) ;
V_30 = F_22 ( V_19 -> V_57 - 1 ) |
F_23 ( V_19 -> V_58 - 1 ) |
F_24 ( V_19 -> V_57 - 1 ) |
F_25 ( V_19 -> V_58 - 1 ) ;
F_15 ( V_30 , V_15 -> V_44 + V_29 -> V_45 + V_59 ) ;
V_30 = V_60 | V_61 ;
if ( V_15 -> V_29 -> V_62 )
V_30 |= V_63 ;
V_24 = F_8 ( V_15 , V_19 ) ;
if ( V_24 > 1 )
V_30 |= F_26 ( V_24 - 1 ) | V_64 ;
F_15 ( V_30 , V_15 -> V_44 + V_65 ) ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
T_1 V_30 ;
if ( V_15 -> V_38 )
return - V_66 ;
if ( ! F_28 ( 0 , & V_15 -> V_67 ) ) {
V_30 = F_29 ( V_15 -> V_44 + V_68 ) ;
V_30 |= V_69 ;
V_30 |= V_70 ;
V_30 &= ~ V_71 ;
V_30 |= V_72 ;
V_30 &= ~ V_73 ;
V_30 |= V_74 ;
F_15 ( V_30 , V_15 -> V_44 + V_68 ) ;
}
return 0 ;
}
static void F_30 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
T_1 V_30 ;
if ( V_15 -> V_38 )
return;
if ( F_31 ( 0 , & V_15 -> V_67 ) ) {
V_30 = F_29 ( V_15 -> V_44 + V_68 ) ;
V_30 &= ~ V_70 ;
V_30 &= ~ V_69 ;
F_15 ( V_30 , V_15 -> V_44 + V_68 ) ;
}
}
static void F_32 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
if ( V_15 -> V_38 )
return;
F_33 ( & V_15 -> V_75 , 1 ) ;
if ( ! F_34 ( V_15 -> V_76 ,
! F_35 ( & V_15 -> V_75 ) ,
V_77 / 20 ) )
F_36 ( L_1 ) ;
}
static void F_37 ( struct V_9 * V_10 ,
struct V_78 * V_79 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_80 * V_81 ;
int V_82 ;
unsigned long V_83 ;
if ( ! V_79 ) {
F_38 ( L_2 ) ;
return;
}
V_82 = V_79 -> V_84 ;
if ( V_82 == V_85 )
V_82 = V_15 -> V_86 ;
if ( V_82 < 0 || V_82 >= V_87 )
return;
V_83 = V_79 -> V_88 * ( V_79 -> V_89 >> 3 ) ;
V_83 += V_79 -> V_90 * V_79 -> V_91 ;
F_36 ( L_3 , V_83 , V_79 -> V_91 ) ;
V_81 = & V_15 -> V_81 [ V_82 ] ;
V_81 -> V_92 = V_79 -> V_93 ;
V_81 -> V_94 = V_79 -> V_95 ;
V_81 -> V_96 = V_79 -> V_97 ;
V_81 -> V_98 = V_79 -> V_99 ;
V_81 -> V_100 = V_79 -> V_100 ;
V_81 -> V_101 = V_79 -> V_101 ;
V_81 -> V_102 = V_79 -> V_102 [ 0 ] + V_83 ;
V_81 -> V_89 = V_79 -> V_89 ;
V_81 -> V_103 = V_79 -> V_103 ;
V_81 -> V_104 = ( V_79 -> V_100 - V_79 -> V_97 ) *
( V_79 -> V_89 >> 3 ) ;
V_81 -> V_105 = V_79 -> V_97 * ( V_79 -> V_89 >> 3 ) ;
F_36 ( L_4 ,
V_81 -> V_92 , V_81 -> V_94 ) ;
F_36 ( L_5 ,
V_81 -> V_96 , V_81 -> V_98 ) ;
F_36 ( L_6 , ( unsigned long ) V_81 -> V_102 ) ;
F_36 ( L_7 ,
V_79 -> V_100 , V_79 -> V_97 ) ;
}
static void F_39 ( struct V_14 * V_15 , unsigned int V_82 )
{
struct V_80 * V_81 = & V_15 -> V_81 [ V_82 ] ;
unsigned long V_30 ;
V_30 = V_106 ;
if ( V_15 -> V_29 -> V_107 && ! V_82 ) {
if ( V_81 -> V_103 == V_108 )
V_81 -> V_103 = V_109 ;
}
switch ( V_81 -> V_103 ) {
case V_110 :
V_30 |= V_111 ;
V_30 |= V_112 ;
V_30 |= V_113 ;
break;
case V_114 :
V_30 |= V_115 ;
V_30 |= V_116 ;
V_30 |= V_117 ;
break;
case V_118 :
V_30 |= V_119 ;
V_30 |= V_116 ;
V_30 |= V_117 ;
break;
case V_109 :
V_30 |= V_120 ;
V_30 |= V_121 ;
V_30 |= V_117 ;
break;
case V_108 :
V_30 |= V_122
| V_123 | V_124 ;
V_30 |= V_121 ;
V_30 |= V_117 ;
break;
default:
F_36 ( L_8 ) ;
V_30 |= V_120 ;
V_30 |= V_121 ;
V_30 |= V_117 ;
break;
}
F_36 ( L_9 , V_81 -> V_89 ) ;
F_15 ( V_30 , V_15 -> V_44 + F_40 ( V_82 ) ) ;
}
static void F_41 ( struct V_14 * V_15 , unsigned int V_82 )
{
unsigned int V_125 = 0 , V_126 = 0 ;
V_125 = ~ ( V_127 | V_128 |
V_129 ) | F_42 ( 0 ) ;
V_126 = F_43 ( 0xffffffff ) ;
F_15 ( V_125 , V_15 -> V_44 + F_44 ( V_82 ) ) ;
F_15 ( V_126 , V_15 -> V_44 + F_45 ( V_82 ) ) ;
}
static void F_46 ( struct V_14 * V_15 ,
int V_82 , bool V_130 )
{
T_1 V_131 , V_132 , V_30 ;
if ( V_15 -> V_29 -> V_133 ) {
V_131 = V_134 ;
V_132 = F_47 ( V_82 ) ;
} else {
V_131 = V_135 ;
V_132 = V_136 ;
}
V_30 = F_29 ( V_15 -> V_44 + V_131 ) ;
if ( V_130 )
V_30 |= V_132 ;
else
V_30 &= ~ V_132 ;
F_15 ( V_30 , V_15 -> V_44 + V_131 ) ;
}
static void F_48 ( struct V_9 * V_10 , int V_84 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_80 * V_81 ;
int V_82 = V_84 ;
unsigned long V_30 , V_137 , V_138 ;
unsigned int V_139 ;
unsigned int V_140 ;
if ( V_15 -> V_38 )
return;
if ( V_82 == V_85 )
V_82 = V_15 -> V_86 ;
if ( V_82 < 0 || V_82 >= V_87 )
return;
V_81 = & V_15 -> V_81 [ V_82 ] ;
if ( V_15 -> V_38 ) {
V_81 -> V_141 = true ;
return;
}
F_46 ( V_15 , V_82 , true ) ;
V_30 = ( unsigned long ) V_81 -> V_102 ;
F_15 ( V_30 , V_15 -> V_44 + F_49 ( V_82 , 0 ) ) ;
V_138 = V_81 -> V_100 * V_81 -> V_98 * ( V_81 -> V_89 >> 3 ) ;
V_30 = ( unsigned long ) ( V_81 -> V_102 + V_138 ) ;
F_15 ( V_30 , V_15 -> V_44 + F_50 ( V_82 , 0 ) ) ;
F_36 ( L_10 ,
( unsigned long ) V_81 -> V_102 , V_30 , V_138 ) ;
F_36 ( L_5 ,
V_81 -> V_96 , V_81 -> V_98 ) ;
V_30 = F_51 ( V_81 -> V_104 ) |
F_52 ( V_81 -> V_105 ) |
F_53 ( V_81 -> V_104 ) |
F_54 ( V_81 -> V_105 ) ;
F_15 ( V_30 , V_15 -> V_44 + F_55 ( V_82 , 0 ) ) ;
V_30 = F_56 ( V_81 -> V_92 ) |
F_57 ( V_81 -> V_94 ) |
F_58 ( V_81 -> V_92 ) |
F_59 ( V_81 -> V_94 ) ;
F_15 ( V_30 , V_15 -> V_44 + F_60 ( V_82 ) ) ;
V_139 = V_81 -> V_92 + V_81 -> V_96 ;
if ( V_139 )
V_139 -- ;
V_140 = V_81 -> V_94 + V_81 -> V_98 ;
if ( V_140 )
V_140 -- ;
V_30 = F_61 ( V_139 ) | F_62 ( V_140 ) |
F_63 ( V_139 ) | F_64 ( V_140 ) ;
F_15 ( V_30 , V_15 -> V_44 + F_65 ( V_82 ) ) ;
F_36 ( L_11 ,
V_81 -> V_92 , V_81 -> V_94 , V_139 , V_140 ) ;
if ( V_82 != 0 ) {
V_137 = F_66 ( 0xf ) |
F_67 ( 0xf ) |
F_68 ( 0xf ) ;
F_15 ( V_137 , V_15 -> V_44 + F_69 ( V_82 ) ) ;
}
if ( V_82 != 3 && V_82 != 4 ) {
T_1 V_83 = F_70 ( V_82 ) ;
if ( V_82 == 0 )
V_83 = F_69 ( V_82 ) ;
V_30 = V_81 -> V_96 * V_81 -> V_98 ;
F_15 ( V_30 , V_15 -> V_44 + V_83 ) ;
F_36 ( L_12 , ( unsigned int ) V_30 ) ;
}
F_39 ( V_15 , V_82 ) ;
if ( V_82 != 0 )
F_41 ( V_15 , V_82 ) ;
V_30 = F_29 ( V_15 -> V_44 + F_40 ( V_82 ) ) ;
V_30 |= V_106 ;
F_15 ( V_30 , V_15 -> V_44 + F_40 ( V_82 ) ) ;
F_46 ( V_15 , V_82 , false ) ;
if ( V_15 -> V_29 -> V_133 ) {
V_30 = F_29 ( V_15 -> V_44 + V_134 ) ;
V_30 |= F_71 ( V_82 ) ;
F_15 ( V_30 , V_15 -> V_44 + V_134 ) ;
}
V_81 -> V_142 = true ;
}
static void F_72 ( struct V_9 * V_10 , int V_84 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_80 * V_81 ;
int V_82 = V_84 ;
T_1 V_30 ;
if ( V_82 == V_85 )
V_82 = V_15 -> V_86 ;
if ( V_82 < 0 || V_82 >= V_87 )
return;
V_81 = & V_15 -> V_81 [ V_82 ] ;
if ( V_15 -> V_38 ) {
V_81 -> V_141 = false ;
return;
}
F_46 ( V_15 , V_82 , true ) ;
V_30 = F_29 ( V_15 -> V_44 + F_40 ( V_82 ) ) ;
V_30 &= ~ V_106 ;
F_15 ( V_30 , V_15 -> V_44 + F_40 ( V_82 ) ) ;
if ( V_15 -> V_29 -> V_133 ) {
V_30 = F_29 ( V_15 -> V_44 + V_134 ) ;
V_30 &= ~ F_71 ( V_82 ) ;
F_15 ( V_30 , V_15 -> V_44 + V_134 ) ;
}
F_46 ( V_15 , V_82 , false ) ;
V_81 -> V_142 = false ;
}
static void F_73 ( struct V_14 * V_15 , int V_82 )
{
F_15 ( 0 , V_15 -> V_44 + F_40 ( V_82 ) ) ;
F_15 ( 0 , V_15 -> V_44 + F_60 ( V_82 ) ) ;
F_15 ( 0 , V_15 -> V_44 + F_65 ( V_82 ) ) ;
F_15 ( 0 , V_15 -> V_44 + F_69 ( V_82 ) ) ;
if ( V_82 == 1 || V_82 == 2 )
F_15 ( 0 , V_15 -> V_44 + F_70 ( V_82 ) ) ;
F_46 ( V_15 , V_82 , false ) ;
}
static void F_74 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_80 * V_81 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < V_87 ; V_143 ++ ) {
V_81 = & V_15 -> V_81 [ V_143 ] ;
V_81 -> V_141 = V_81 -> V_142 ;
if ( V_81 -> V_142 )
F_72 ( V_10 , V_143 ) ;
}
F_32 ( V_10 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_80 * V_81 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < V_87 ; V_143 ++ ) {
V_81 = & V_15 -> V_81 [ V_143 ] ;
V_81 -> V_142 = V_81 -> V_141 ;
V_81 -> V_141 = false ;
}
}
static void F_76 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_80 * V_81 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < V_87 ; V_143 ++ ) {
V_81 = & V_15 -> V_81 [ V_143 ] ;
if ( V_81 -> V_142 )
F_48 ( V_10 , V_143 ) ;
}
F_14 ( V_10 ) ;
}
static int F_77 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
int V_144 ;
if ( ! V_15 -> V_38 )
return 0 ;
V_15 -> V_38 = false ;
F_78 ( V_15 -> V_7 ) ;
V_144 = F_79 ( V_15 -> V_145 ) ;
if ( V_144 < 0 ) {
F_38 ( L_13 , V_144 ) ;
goto V_146;
}
V_144 = F_79 ( V_15 -> V_25 ) ;
if ( V_144 < 0 ) {
F_38 ( L_14 , V_144 ) ;
goto V_147;
}
if ( F_31 ( 0 , & V_15 -> V_67 ) ) {
V_144 = F_27 ( V_10 ) ;
if ( V_144 ) {
F_38 ( L_15 , V_144 ) ;
goto V_148;
}
}
F_75 ( V_10 ) ;
F_76 ( V_10 ) ;
return 0 ;
V_148:
F_80 ( V_15 -> V_25 ) ;
V_147:
F_80 ( V_15 -> V_145 ) ;
V_146:
V_15 -> V_38 = true ;
return V_144 ;
}
static int F_81 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
if ( V_15 -> V_38 )
return 0 ;
F_74 ( V_10 ) ;
F_80 ( V_15 -> V_25 ) ;
F_80 ( V_15 -> V_145 ) ;
F_82 ( V_15 -> V_7 ) ;
V_15 -> V_38 = true ;
return 0 ;
}
static void F_83 ( struct V_9 * V_10 , int V_19 )
{
F_36 ( L_16 , __FILE__ , V_19 ) ;
switch ( V_19 ) {
case V_149 :
F_77 ( V_10 ) ;
break;
case V_150 :
case V_151 :
case V_152 :
F_81 ( V_10 ) ;
break;
default:
F_36 ( L_17 , V_19 ) ;
break;
}
}
static T_2 F_84 ( int V_153 , void * V_154 )
{
struct V_14 * V_15 = (struct V_14 * ) V_154 ;
T_1 V_30 ;
V_30 = F_29 ( V_15 -> V_44 + V_155 ) ;
if ( V_30 & V_156 )
F_15 ( V_156 , V_15 -> V_44 + V_155 ) ;
if ( V_15 -> V_13 < 0 || ! V_15 -> V_12 )
goto V_157;
F_85 ( V_15 -> V_12 , V_15 -> V_13 ) ;
F_86 ( V_15 -> V_12 , V_15 -> V_13 ) ;
if ( F_35 ( & V_15 -> V_75 ) ) {
F_33 ( & V_15 -> V_75 , 0 ) ;
F_87 ( & V_15 -> V_76 ) ;
}
V_157:
return V_158 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_159 * V_7 = & V_3 -> V_7 ;
struct V_14 * V_15 ;
struct V_160 * V_161 ;
int V_82 ;
int V_144 = - V_162 ;
if ( ! V_7 -> V_163 )
return - V_164 ;
V_15 = F_89 ( V_7 , sizeof( * V_15 ) , V_165 ) ;
if ( ! V_15 )
return - V_166 ;
V_15 -> V_7 = V_7 ;
V_15 -> V_38 = true ;
if ( F_90 ( V_7 -> V_163 , L_18 ) )
V_15 -> V_31 |= V_167 ;
if ( F_90 ( V_7 -> V_163 , L_19 ) )
V_15 -> V_31 |= V_168 ;
V_15 -> V_145 = F_91 ( V_7 , L_20 ) ;
if ( F_92 ( V_15 -> V_145 ) ) {
F_93 ( V_7 , L_21 ) ;
return F_94 ( V_15 -> V_145 ) ;
}
V_15 -> V_25 = F_91 ( V_7 , L_22 ) ;
if ( F_92 ( V_15 -> V_25 ) ) {
F_93 ( V_7 , L_23 ) ;
return F_94 ( V_15 -> V_25 ) ;
}
V_161 = F_95 ( V_3 , V_169 , 0 ) ;
V_15 -> V_44 = F_96 ( V_7 , V_161 ) ;
if ( F_92 ( V_15 -> V_44 ) )
return F_94 ( V_15 -> V_44 ) ;
V_161 = F_97 ( V_3 , V_170 , L_24 ) ;
if ( ! V_161 ) {
F_93 ( V_7 , L_25 ) ;
return - V_171 ;
}
V_144 = F_98 ( V_7 , V_161 -> V_172 , F_84 ,
0 , L_26 , V_15 ) ;
if ( V_144 ) {
F_93 ( V_7 , L_25 ) ;
return V_144 ;
}
V_15 -> V_29 = F_1 ( V_3 ) ;
F_99 ( & V_15 -> V_76 ) ;
F_33 ( & V_15 -> V_75 , 0 ) ;
F_100 ( V_3 , & V_173 ) ;
V_173 . V_15 = V_15 ;
F_101 ( & V_173 ) ;
F_102 ( V_15 -> V_7 ) ;
F_103 ( V_7 ) ;
for ( V_82 = 0 ; V_82 < V_87 ; V_82 ++ )
F_73 ( V_15 , V_82 ) ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_105 ( V_3 ) ;
F_106 ( & V_3 -> V_7 ) ;
F_107 ( & V_173 ) ;
F_83 ( V_10 , V_152 ) ;
F_108 ( & V_3 -> V_7 ) ;
return 0 ;
}
