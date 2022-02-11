static bool F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
return true ;
}
static void * F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
F_2 ( L_1 , __FILE__ ) ;
return V_4 -> V_5 ;
}
static int F_5 ( struct V_1 * V_2 , void * V_5 )
{
F_2 ( L_1 , __FILE__ ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_6 )
{
F_2 ( L_1 , __FILE__ ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
struct V_7 * V_5 = V_4 -> V_5 ;
T_1 V_8 ;
F_2 ( L_1 , __FILE__ ) ;
F_8 ( V_4 -> V_9 , V_4 -> V_10 + V_11 ) ;
V_8 = F_9 ( V_5 -> V_12 - 1 ) |
F_10 ( V_5 -> V_13 - 1 ) |
F_11 ( V_5 -> V_14 - 1 ) ;
F_8 ( V_8 , V_4 -> V_10 + V_15 ) ;
V_8 = F_12 ( V_5 -> V_16 - 1 ) |
F_13 ( V_5 -> V_17 - 1 ) |
F_14 ( V_5 -> V_18 - 1 ) ;
F_8 ( V_8 , V_4 -> V_10 + V_19 ) ;
V_8 = F_15 ( V_5 -> V_20 - 1 ) |
F_16 ( V_5 -> V_21 - 1 ) ;
F_8 ( V_8 , V_4 -> V_10 + V_22 ) ;
V_8 = V_4 -> V_23 ;
V_8 &= ~ ( V_24 | V_25 ) ;
if ( V_4 -> V_26 > 1 )
V_8 |= F_17 ( V_4 -> V_26 - 1 ) | V_25 ;
else
V_8 &= ~ V_25 ;
V_8 |= V_27 | V_28 ;
F_8 ( V_8 , V_4 -> V_10 + V_29 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
struct V_30 * V_31 = & V_4 -> V_31 ;
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_34 * V_35 = & V_31 -> V_35 ;
T_1 V_8 ;
F_2 ( L_1 , __FILE__ ) ;
V_8 = F_19 ( V_4 -> V_10 + V_29 ) ;
V_8 &= ~ ( V_27 | V_28 ) ;
F_8 ( V_8 , V_4 -> V_10 + V_29 ) ;
if ( V_33 -> V_36 [ V_35 -> V_37 ] &&
F_20 ( & V_33 -> V_38 [ V_35 -> V_37 ] ) ) {
F_21 ( V_33 , V_35 -> V_37 ) ;
if ( ! V_33 -> V_39 )
F_22 ( V_33 , V_35 -> V_37 ) ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
T_1 V_8 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! F_24 ( 0 , & V_4 -> V_40 ) ) {
V_8 = F_19 ( V_4 -> V_10 + V_41 ) ;
V_8 |= V_42 ;
V_8 |= V_43 ;
V_8 &= ~ V_44 ;
V_8 |= V_45 ;
V_8 &= ~ V_46 ;
V_8 |= V_47 ;
F_8 ( V_8 , V_4 -> V_10 + V_41 ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
T_1 V_8 ;
F_2 ( L_1 , __FILE__ ) ;
if ( F_26 ( 0 , & V_4 -> V_40 ) ) {
V_8 = F_19 ( V_4 -> V_10 + V_41 ) ;
V_8 &= ~ V_43 ;
V_8 &= ~ V_42 ;
F_8 ( V_8 , V_4 -> V_10 + V_41 ) ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
struct V_50 * V_51 ;
unsigned long V_52 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_49 ) {
F_28 ( V_2 , L_2 ) ;
return;
}
V_52 = V_49 -> V_53 * ( V_49 -> V_54 >> 3 ) ;
V_52 += V_49 -> V_55 * V_49 -> V_56 ;
F_2 ( L_3 , V_52 , V_49 -> V_56 ) ;
V_51 = & V_4 -> V_51 [ V_4 -> V_57 ] ;
V_51 -> V_58 = V_49 -> V_59 ;
V_51 -> V_60 = V_49 -> V_61 ;
V_51 -> V_62 = V_49 -> V_63 ;
V_51 -> V_64 = V_49 -> V_65 ;
V_51 -> V_66 = V_49 -> V_66 ;
V_51 -> V_67 = V_49 -> V_67 ;
V_51 -> V_68 = V_49 -> V_68 + V_52 ;
V_51 -> V_69 = V_49 -> V_69 + V_52 ;
V_51 -> V_54 = V_49 -> V_54 ;
V_51 -> V_70 = ( V_49 -> V_66 - V_49 -> V_63 ) *
( V_49 -> V_54 >> 3 ) ;
V_51 -> V_71 = V_49 -> V_63 * ( V_49 -> V_54 >> 3 ) ;
F_2 ( L_4 ,
V_51 -> V_58 , V_51 -> V_60 ) ;
F_2 ( L_5 ,
V_51 -> V_62 , V_51 -> V_64 ) ;
F_2 ( L_6 ,
( unsigned long ) V_51 -> V_68 ,
( unsigned long ) V_51 -> V_69 ) ;
F_2 ( L_7 ,
V_49 -> V_66 , V_49 -> V_63 ) ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_72 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
struct V_50 * V_51 = & V_4 -> V_51 [ V_72 ] ;
unsigned long V_8 ;
F_2 ( L_1 , __FILE__ ) ;
V_8 = V_73 ;
switch ( V_51 -> V_54 ) {
case 1 :
V_8 |= V_74 ;
V_8 |= V_75 ;
V_8 |= V_76 ;
break;
case 2 :
V_8 |= V_77 ;
V_8 |= V_75 ;
V_8 |= V_78 ;
break;
case 4 :
V_8 |= V_79 ;
V_8 |= V_75 ;
V_8 |= V_78 ;
break;
case 8 :
V_8 |= V_80 ;
V_8 |= V_78 ;
V_8 |= V_81 ;
break;
case 16 :
V_8 |= V_82 ;
V_8 |= V_83 ;
V_8 |= V_84 ;
break;
case 24 :
V_8 |= V_85 ;
V_8 |= V_86 ;
V_8 |= V_84 ;
break;
case 32 :
V_8 |= V_87
| V_88 | V_89 ;
V_8 |= V_86 ;
V_8 |= V_84 ;
break;
default:
F_2 ( L_8 ) ;
V_8 |= V_85 ;
V_8 |= V_86 ;
V_8 |= V_84 ;
break;
}
F_2 ( L_9 , V_51 -> V_54 ) ;
F_8 ( V_8 , V_4 -> V_10 + F_30 ( V_72 ) ) ;
}
static void F_31 ( struct V_1 * V_2 , unsigned int V_72 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
unsigned int V_90 = 0 , V_91 = 0 ;
F_2 ( L_1 , __FILE__ ) ;
V_90 = ~ ( V_92 | V_93 |
V_94 ) | F_32 ( 0 ) ;
V_91 = F_33 ( 0xffffffff ) ;
F_8 ( V_90 , V_4 -> V_10 + F_34 ( V_72 ) ) ;
F_8 ( V_91 , V_4 -> V_10 + F_35 ( V_72 ) ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
struct V_50 * V_51 ;
int V_72 = V_4 -> V_57 ;
unsigned long V_8 , V_95 , V_96 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_72 < 0 || V_72 > V_97 )
return;
V_51 = & V_4 -> V_51 [ V_72 ] ;
V_8 = F_19 ( V_4 -> V_10 + V_98 ) ;
V_8 |= F_37 ( V_72 ) ;
F_8 ( V_8 , V_4 -> V_10 + V_98 ) ;
V_8 = ( unsigned long ) V_51 -> V_68 ;
F_8 ( V_8 , V_4 -> V_10 + F_38 ( V_72 , 0 ) ) ;
V_96 = V_51 -> V_66 * V_51 -> V_64 * ( V_51 -> V_54 >> 3 ) ;
V_8 = ( unsigned long ) ( V_51 -> V_68 + V_96 ) ;
F_8 ( V_8 , V_4 -> V_10 + F_39 ( V_72 , 0 ) ) ;
F_2 ( L_10 ,
( unsigned long ) V_51 -> V_68 , V_8 , V_96 ) ;
F_2 ( L_5 ,
V_51 -> V_62 , V_51 -> V_64 ) ;
V_8 = F_40 ( V_51 -> V_70 ) |
F_41 ( V_51 -> V_71 ) ;
F_8 ( V_8 , V_4 -> V_10 + F_42 ( V_72 , 0 ) ) ;
V_8 = F_43 ( V_51 -> V_58 ) |
F_44 ( V_51 -> V_60 ) ;
F_8 ( V_8 , V_4 -> V_10 + F_45 ( V_72 ) ) ;
V_8 = F_46 ( V_51 -> V_58 +
V_51 -> V_62 - 1 ) |
F_47 ( V_51 -> V_60 +
V_51 -> V_64 - 1 ) ;
F_8 ( V_8 , V_4 -> V_10 + F_48 ( V_72 ) ) ;
F_2 ( L_11 ,
V_51 -> V_58 , V_51 -> V_60 ,
V_51 -> V_58 + V_51 -> V_62 - 1 ,
V_51 -> V_60 + V_51 -> V_64 - 1 ) ;
if ( V_72 != 0 ) {
V_95 = F_49 ( 0xf ) |
F_50 ( 0xf ) |
F_51 ( 0xf ) ;
F_8 ( V_95 , V_4 -> V_10 + F_52 ( V_72 ) ) ;
}
if ( V_72 != 3 && V_72 != 4 ) {
T_1 V_52 = F_53 ( V_72 ) ;
if ( V_72 == 0 )
V_52 = V_99 ;
V_8 = V_51 -> V_62 * V_51 -> V_64 ;
F_8 ( V_8 , V_4 -> V_10 + V_52 ) ;
F_2 ( L_12 , ( unsigned int ) V_8 ) ;
}
F_29 ( V_2 , V_72 ) ;
if ( V_72 != 0 )
F_31 ( V_2 , V_72 ) ;
V_8 = F_19 ( V_4 -> V_10 + V_98 ) ;
V_8 |= F_54 ( V_72 ) ;
V_8 &= ~ F_37 ( V_72 ) ;
F_8 ( V_8 , V_4 -> V_10 + V_98 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_4 ( V_2 ) ;
int V_72 = V_4 -> V_57 ;
T_1 V_8 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_72 < 0 || V_72 > V_97 )
return;
V_8 = F_19 ( V_4 -> V_10 + V_98 ) ;
V_8 |= F_37 ( V_72 ) ;
F_8 ( V_8 , V_4 -> V_10 + V_98 ) ;
V_8 = F_19 ( V_4 -> V_10 + F_30 ( V_72 ) ) ;
V_8 &= ~ V_73 ;
F_8 ( V_8 , V_4 -> V_10 + F_30 ( V_72 ) ) ;
V_8 = F_19 ( V_4 -> V_10 + V_98 ) ;
V_8 &= ~ F_54 ( V_72 ) ;
V_8 &= ~ F_37 ( V_72 ) ;
F_8 ( V_8 , V_4 -> V_10 + V_98 ) ;
}
static void F_56 ( struct V_32 * V_33 , int V_100 )
{
struct V_101 * V_102 = V_33 -> V_103 ;
struct V_104 * V_105 , * V_106 ;
struct V_107 V_108 ;
unsigned long V_109 ;
bool V_110 = false ;
F_57 ( & V_33 -> V_111 , V_109 ) ;
F_58 (e, t, &dev_priv->pageflip_event_list,
base.link) {
if ( V_100 != V_105 -> V_37 )
continue;
V_110 = true ;
F_59 ( & V_108 ) ;
V_105 -> V_112 . V_113 = 0 ;
V_105 -> V_112 . V_114 = V_108 . V_114 ;
V_105 -> V_112 . V_115 = V_108 . V_115 ;
F_60 ( & V_105 -> V_116 . V_117 , & V_105 -> V_116 . V_118 -> V_119 ) ;
F_61 ( & V_105 -> V_116 . V_118 -> V_120 ) ;
}
if ( V_110 )
F_21 ( V_33 , V_100 ) ;
F_62 ( & V_33 -> V_111 , V_109 ) ;
}
static T_2 F_63 ( int V_121 , void * V_122 )
{
struct V_3 * V_4 = (struct V_3 * ) V_122 ;
struct V_30 * V_31 = & V_4 -> V_31 ;
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_34 * V_35 = & V_31 -> V_35 ;
T_1 V_8 ;
V_8 = F_19 ( V_4 -> V_10 + V_123 ) ;
if ( V_8 & V_124 )
F_8 ( V_124 , V_4 -> V_10 + V_123 ) ;
if ( V_35 -> V_37 == - 1 )
return V_125 ;
F_64 ( V_33 , V_35 -> V_37 ) ;
F_56 ( V_33 , V_35 -> V_37 ) ;
return V_125 ;
}
static int F_65 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
V_33 -> V_126 = 1 ;
return 0 ;
}
static void F_66 ( struct V_32 * V_33 )
{
F_2 ( L_1 , __FILE__ ) ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_7 * V_5 )
{
unsigned long V_127 = F_68 ( V_4 -> V_128 ) ;
T_1 V_129 ;
T_1 V_26 ;
T_1 V_130 = 0 ;
T_1 V_131 ;
F_2 ( L_1 , __FILE__ ) ;
V_129 = V_5 -> V_16 + V_5 -> V_18 +
V_5 -> V_17 + V_5 -> V_21 ;
V_129 *= V_5 -> V_12 + V_5 -> V_14 +
V_5 -> V_13 + V_5 -> V_20 ;
if ( ! V_5 -> V_132 )
V_5 -> V_132 = 60 ;
V_127 /= V_129 ;
for ( V_26 = 1 ; V_26 < 0x100 ; V_26 ++ ) {
int V_133 ;
V_131 = V_127 / V_26 ;
V_133 = V_5 -> V_132 - V_131 ;
if ( V_133 < 0 ) {
V_130 = V_131 ;
continue;
} else {
if ( ! V_130 )
V_130 = V_131 ;
else if ( V_133 < ( V_130 - V_131 ) )
V_130 = V_131 ;
break;
}
}
return V_26 ;
}
static void F_69 ( struct V_3 * V_4 , int V_72 )
{
T_1 V_8 ;
F_2 ( L_1 , __FILE__ ) ;
F_8 ( 0 , V_4 -> V_10 + F_30 ( V_72 ) ) ;
F_8 ( 0 , V_4 -> V_10 + F_45 ( V_72 ) ) ;
F_8 ( 0 , V_4 -> V_10 + F_48 ( V_72 ) ) ;
F_8 ( 0 , V_4 -> V_10 + F_52 ( V_72 ) ) ;
if ( V_72 == 1 || V_72 == 2 )
F_8 ( 0 , V_4 -> V_10 + F_53 ( V_72 ) ) ;
V_8 = F_19 ( V_4 -> V_10 + V_98 ) ;
V_8 &= ~ F_37 ( V_72 ) ;
F_8 ( V_8 , V_4 -> V_10 + V_98 ) ;
}
static int T_3 F_70 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = & V_135 -> V_2 ;
struct V_3 * V_4 ;
struct V_30 * V_31 ;
struct V_136 * V_137 ;
struct V_7 * V_5 ;
struct V_138 * V_139 ;
int V_72 ;
int V_140 = - V_141 ;
F_2 ( L_1 , __FILE__ ) ;
V_137 = V_135 -> V_2 . V_142 ;
if ( ! V_137 ) {
F_28 ( V_2 , L_13 ) ;
return - V_141 ;
}
V_5 = & V_137 -> V_5 ;
if ( ! V_5 ) {
F_28 ( V_2 , L_14 ) ;
return - V_141 ;
}
V_4 = F_71 ( sizeof( * V_4 ) , V_143 ) ;
if ( ! V_4 )
return - V_144 ;
V_4 -> V_145 = F_72 ( V_2 , L_15 ) ;
if ( F_73 ( V_4 -> V_145 ) ) {
F_28 ( V_2 , L_16 ) ;
V_140 = F_74 ( V_4 -> V_145 ) ;
goto V_146;
}
F_75 ( V_4 -> V_145 ) ;
V_4 -> V_128 = F_72 ( V_2 , L_17 ) ;
if ( F_73 ( V_4 -> V_128 ) ) {
F_28 ( V_2 , L_18 ) ;
V_140 = F_74 ( V_4 -> V_128 ) ;
goto V_147;
}
F_75 ( V_4 -> V_128 ) ;
V_139 = F_76 ( V_135 , V_148 , 0 ) ;
if ( ! V_139 ) {
F_28 ( V_2 , L_19 ) ;
V_140 = - V_149 ;
goto V_150;
}
V_4 -> V_151 = F_77 ( V_139 -> V_152 , F_78 ( V_139 ) ,
F_79 ( V_2 ) ) ;
if ( ! V_4 -> V_151 ) {
F_28 ( V_2 , L_20 ) ;
V_140 = - V_149 ;
goto V_150;
}
V_4 -> V_10 = F_80 ( V_139 -> V_152 , F_78 ( V_139 ) ) ;
if ( ! V_4 -> V_10 ) {
F_28 ( V_2 , L_21 ) ;
V_140 = - V_153 ;
goto V_154;
}
V_139 = F_76 ( V_135 , V_155 , 0 ) ;
if ( ! V_139 ) {
F_28 ( V_2 , L_22 ) ;
goto V_156;
}
V_4 -> V_121 = V_139 -> V_152 ;
for ( V_72 = 0 ; V_72 < V_97 ; V_72 ++ )
F_69 ( V_4 , V_72 ) ;
V_140 = F_81 ( V_4 -> V_121 , F_63 , 0 , L_23 , V_4 ) ;
if ( V_140 < 0 ) {
F_28 ( V_2 , L_22 ) ;
goto V_157;
}
V_4 -> V_26 = F_67 ( V_4 , V_5 ) ;
V_4 -> V_23 = V_137 -> V_23 ;
V_4 -> V_9 = V_137 -> V_9 ;
V_4 -> V_57 = V_137 -> V_57 ;
V_4 -> V_5 = V_5 ;
V_5 -> V_158 = F_68 ( V_4 -> V_128 ) / V_4 -> V_26 ;
F_2 ( L_24 ,
V_5 -> V_158 , V_4 -> V_26 ) ;
V_31 = & V_4 -> V_31 ;
V_31 -> V_159 = F_65 ;
V_31 -> remove = F_66 ;
V_31 -> V_35 . V_37 = - 1 ;
V_31 -> V_35 . V_160 = & V_161 ;
V_31 -> V_35 . V_162 = & V_163 ;
V_31 -> V_35 . V_164 = & V_165 ;
V_31 -> V_35 . V_2 = V_2 ;
F_82 ( V_135 , V_4 ) ;
F_83 ( V_31 ) ;
return 0 ;
V_157:
V_156:
F_84 ( V_4 -> V_10 ) ;
V_154:
F_85 ( V_4 -> V_151 ) ;
F_86 ( V_4 -> V_151 ) ;
V_150:
F_87 ( V_4 -> V_128 ) ;
F_88 ( V_4 -> V_128 ) ;
V_147:
F_87 ( V_4 -> V_145 ) ;
F_88 ( V_4 -> V_145 ) ;
V_146:
F_86 ( V_4 ) ;
return V_140 ;
}
static int T_4 F_89 ( struct V_134 * V_135 )
{
struct V_3 * V_4 = F_90 ( V_135 ) ;
F_2 ( L_1 , __FILE__ ) ;
F_91 ( & V_4 -> V_31 ) ;
F_87 ( V_4 -> V_128 ) ;
F_87 ( V_4 -> V_145 ) ;
F_88 ( V_4 -> V_128 ) ;
F_88 ( V_4 -> V_145 ) ;
F_84 ( V_4 -> V_10 ) ;
F_85 ( V_4 -> V_151 ) ;
F_86 ( V_4 -> V_151 ) ;
F_92 ( V_4 -> V_121 , V_4 ) ;
F_86 ( V_4 ) ;
return 0 ;
}
static int T_5 F_93 ( void )
{
return F_94 ( & V_166 ) ;
}
static void T_6 F_95 ( void )
{
F_96 ( & V_166 ) ;
}
