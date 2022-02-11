static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 )
return;
F_2 ( & V_4 -> V_6 , 1 ) ;
if ( ! F_3 ( V_4 -> V_7 ,
! F_4 ( & V_4 -> V_6 ) ,
V_8 / 20 ) )
F_5 ( L_1 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
unsigned int V_9 , V_10 = 0 ;
F_5 ( L_2 , __FILE__ ) ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
T_1 V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
if ( V_12 & V_14 ) {
V_12 &= ~ V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_10 = 1 ;
}
}
if ( V_10 ) {
unsigned int V_15 = V_4 -> V_5 ;
V_4 -> V_5 = 0 ;
F_1 ( V_4 -> V_2 ) ;
V_4 -> V_5 = V_15 ;
}
}
static int F_10 ( struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_21 = V_19 -> V_21 ++ ;
if ( F_11 ( V_4 -> V_17 ) ) {
int V_22 ;
F_6 ( V_4 ) ;
V_22 = F_12 ( V_4 -> V_17 , V_4 -> V_23 ) ;
if ( V_22 ) {
F_13 ( L_3 ) ;
return V_22 ;
}
}
return 0 ;
}
static void F_14 ( struct V_3 * V_4 )
{
if ( F_11 ( V_4 -> V_17 ) )
F_15 ( V_4 -> V_17 , V_4 -> V_23 ) ;
}
static T_1 F_16 ( struct V_3 * V_4 ,
const struct V_24 * V_25 )
{
unsigned long V_26 = V_25 -> V_27 * V_25 -> V_28 * V_25 -> V_29 ;
T_1 V_30 ;
V_30 = F_17 ( F_18 ( V_4 -> V_31 ) , V_26 ) ;
return ( V_30 < 0x100 ) ? V_30 : 0xff ;
}
static bool F_19 ( struct V_1 * V_2 ,
const struct V_24 * V_25 ,
struct V_24 * V_32 )
{
if ( V_32 -> V_29 == 0 )
V_32 -> V_29 = V_33 ;
return true ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = & V_2 -> V_34 . V_25 ;
T_1 V_12 , V_30 ;
if ( V_4 -> V_5 )
return;
if ( V_25 -> V_27 == 0 || V_25 -> V_28 == 0 )
return;
if ( ! V_4 -> V_35 ) {
int V_36 , V_37 , V_38 , V_39 , V_40 , V_41 ;
V_36 = V_25 -> V_42 - V_25 -> V_43 ;
V_37 = V_25 -> V_44 - V_25 -> V_42 ;
V_38 = V_25 -> V_43 - V_25 -> V_45 ;
V_12 = F_21 ( V_37 - 1 ) | F_22 ( V_38 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_46 ) ;
V_12 = F_23 ( V_36 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_47 ) ;
V_39 = V_25 -> V_48 - V_25 -> V_49 ;
V_40 = V_25 -> V_50 - V_25 -> V_48 ;
V_41 = V_25 -> V_49 - V_25 -> V_51 ;
V_12 = F_24 ( V_40 - 1 ) | F_25 ( V_41 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_52 ) ;
V_12 = F_26 ( V_39 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_53 ) ;
}
V_12 = F_27 ( V_25 -> V_54 - 1 ) |
F_28 ( V_25 -> V_55 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_56 ) ;
F_9 ( V_25 -> V_54 - 1 , V_4 -> V_13 + V_57 ) ;
V_12 = V_58 | V_59 ;
F_9 ( V_12 , V_4 -> V_13 + V_60 ) ;
V_30 = F_16 ( V_4 , V_25 ) ;
if ( V_30 > 1 ) {
V_12 = F_29 ( V_30 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_61 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_62 ) ;
}
V_12 = F_7 ( V_4 -> V_13 + V_63 ) ;
V_12 |= V_64 ;
F_9 ( V_12 , V_4 -> V_13 + V_63 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return - V_65 ;
if ( ! F_31 ( 0 , & V_4 -> V_66 ) ) {
V_12 = F_7 ( V_4 -> V_13 + V_67 ) ;
V_12 |= V_68 ;
if ( ! V_4 -> V_35 ) {
V_12 |= V_69 ;
V_12 &= ~ V_70 ;
V_12 |= V_71 ;
}
F_9 ( V_12 , V_4 -> V_13 + V_67 ) ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return;
if ( F_33 ( 0 , & V_4 -> V_66 ) ) {
V_12 = F_7 ( V_4 -> V_13 + V_67 ) ;
V_12 &= ~ V_68 ;
if ( ! V_4 -> V_35 )
V_12 &= ~ V_69 ;
F_9 ( V_12 , V_4 -> V_13 + V_67 ) ;
}
}
static void F_34 ( struct V_3 * V_4 , unsigned int V_9 )
{
struct V_72 * V_73 = & V_4 -> V_74 [ V_9 ] ;
unsigned long V_12 ;
int V_75 ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 &= ~ V_76 ;
switch ( V_73 -> V_77 ) {
case V_78 :
V_12 |= V_79 ;
V_12 |= V_80 ;
break;
case V_81 :
V_12 |= V_82 ;
V_12 |= V_80 ;
break;
case V_83 :
V_12 |= V_84 ;
V_12 |= V_80 ;
break;
case V_85 :
V_12 |= V_86 ;
V_12 |= V_80 ;
break;
case V_87 :
V_12 |= V_88 ;
V_12 |= V_80 ;
break;
case V_89 :
V_12 |= V_90 | V_91 |
V_92 ;
V_12 |= V_80 ;
break;
case V_93 :
V_12 |= V_94 | V_91 |
V_92 ;
V_12 |= V_80 ;
break;
case V_95 :
V_12 |= V_96 | V_91 |
V_92 ;
V_12 |= V_80 ;
break;
case V_97 :
V_12 |= V_98 | V_91 |
V_92 ;
V_12 |= V_80 ;
break;
default:
F_5 ( L_4 ) ;
V_12 |= V_82 ;
V_12 |= V_80 ;
break;
}
F_5 ( L_5 , V_73 -> V_99 ) ;
V_75 = ( V_73 -> V_100 / ( V_73 -> V_99 >> 3 ) ) - V_73 -> V_101 ;
if ( V_73 -> V_101 + V_75 < V_102 ) {
V_12 &= ~ V_103 ;
V_12 |= V_104 ;
}
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
}
static void F_35 ( struct V_3 * V_4 , unsigned int V_9 )
{
unsigned int V_105 = 0 , V_106 = 0 ;
V_105 = ~ ( V_107 | V_108 |
V_109 ) | F_36 ( 0 ) ;
V_106 = F_37 ( 0xffffffff ) ;
F_9 ( V_105 , V_4 -> V_13 + F_38 ( V_9 ) ) ;
F_9 ( V_106 , V_4 -> V_13 + F_39 ( V_9 ) ) ;
}
static void F_40 ( struct V_3 * V_4 ,
unsigned int V_9 , bool V_110 )
{
T_1 V_111 , V_12 ;
V_111 = F_41 ( V_9 ) ;
V_12 = F_7 ( V_4 -> V_13 + V_112 ) ;
if ( V_110 )
V_12 |= V_111 ;
else
V_12 &= ~ V_111 ;
F_9 ( V_12 , V_4 -> V_13 + V_112 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned int V_9 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = & V_2 -> V_34 . V_25 ;
struct V_72 * V_73 ;
int V_75 ;
unsigned long V_12 , V_113 ;
unsigned int V_114 ;
unsigned int V_115 ;
if ( V_4 -> V_5 )
return;
if ( V_9 < 0 || V_9 >= V_11 )
return;
V_73 = & V_4 -> V_74 [ V_9 ] ;
if ( V_4 -> V_5 ) {
V_73 -> V_116 = true ;
return;
}
F_40 ( V_4 , V_9 , true ) ;
V_12 = ( unsigned long ) V_73 -> V_117 [ 0 ] ;
F_9 ( V_12 , V_4 -> V_13 + F_43 ( V_9 ) ) ;
V_75 = ( V_73 -> V_100 / ( V_73 -> V_99 >> 3 ) ) - V_73 -> V_101 ;
F_9 ( V_73 -> V_101 + V_75 , V_4 -> V_13 + F_44 ( V_9 ) ) ;
F_9 ( V_73 -> V_118 , V_4 -> V_13 + F_45 ( V_9 ) ) ;
F_9 ( V_73 -> V_119 , V_4 -> V_13 + F_46 ( V_9 ) ) ;
F_9 ( V_73 -> V_120 , V_4 -> V_13 + F_47 ( V_9 ) ) ;
F_5 ( L_6 ,
( unsigned long ) V_12 ) ;
F_5 ( L_7 ,
V_73 -> V_121 , V_73 -> V_122 ) ;
if ( ( V_73 -> V_123 + V_73 -> V_121 ) > V_25 -> V_55 )
V_73 -> V_123 = V_25 -> V_55 - V_73 -> V_121 ;
if ( ( V_73 -> V_124 + V_73 -> V_122 ) > V_25 -> V_54 )
V_73 -> V_124 = V_25 -> V_54 - V_73 -> V_122 ;
V_12 = F_48 ( V_73 -> V_123 ) |
F_49 ( V_73 -> V_124 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_50 ( V_9 ) ) ;
V_114 = V_73 -> V_123 + V_73 -> V_121 ;
if ( V_114 )
V_114 -- ;
V_115 = V_73 -> V_124 + V_73 -> V_122 ;
if ( V_115 )
V_115 -- ;
V_12 = F_51 ( V_114 ) | F_52 ( V_115 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_53 ( V_9 ) ) ;
F_5 ( L_8 ,
V_73 -> V_123 , V_73 -> V_124 , V_114 , V_115 ) ;
V_113 = F_54 ( 0x0 ) |
F_55 ( 0x0 ) |
F_56 ( 0x0 ) ;
F_9 ( V_113 , V_4 -> V_13 + F_57 ( V_9 ) ) ;
V_113 = F_58 ( 0xff ) |
F_59 ( 0xff ) |
F_60 ( 0xff ) ;
F_9 ( V_113 , V_4 -> V_13 + F_61 ( V_9 ) ) ;
F_34 ( V_4 , V_9 ) ;
if ( V_9 != 0 )
F_35 ( V_4 , V_9 ) ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 |= V_125 ;
V_12 |= V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
F_40 ( V_4 , V_9 , false ) ;
V_12 = F_7 ( V_4 -> V_13 + V_63 ) ;
V_12 |= V_64 ;
F_9 ( V_12 , V_4 -> V_13 + V_63 ) ;
V_73 -> V_126 = true ;
}
static void F_62 ( struct V_1 * V_2 , unsigned int V_9 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_72 * V_73 ;
T_1 V_12 ;
if ( V_9 < 0 || V_9 >= V_11 )
return;
V_73 = & V_4 -> V_74 [ V_9 ] ;
if ( V_4 -> V_5 ) {
V_73 -> V_116 = false ;
return;
}
F_40 ( V_4 , V_9 , true ) ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 &= ~ V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
F_40 ( V_4 , V_9 , false ) ;
V_12 = F_7 ( V_4 -> V_13 + V_63 ) ;
V_12 |= V_64 ;
F_9 ( V_12 , V_4 -> V_13 + V_63 ) ;
V_73 -> V_126 = false ;
}
static void F_63 ( struct V_3 * V_4 )
{
struct V_72 * V_73 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_11 ; V_127 ++ ) {
V_73 = & V_4 -> V_74 [ V_127 ] ;
V_73 -> V_116 = V_73 -> V_126 ;
if ( V_73 -> V_126 )
F_62 ( V_4 -> V_2 , V_127 ) ;
}
}
static void F_64 ( struct V_3 * V_4 )
{
struct V_72 * V_73 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_11 ; V_127 ++ ) {
V_73 = & V_4 -> V_74 [ V_127 ] ;
V_73 -> V_126 = V_73 -> V_116 ;
V_73 -> V_116 = false ;
}
}
static void F_65 ( struct V_3 * V_4 )
{
struct V_72 * V_73 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_11 ; V_127 ++ ) {
V_73 = & V_4 -> V_74 [ V_127 ] ;
if ( V_73 -> V_126 )
F_42 ( V_4 -> V_2 , V_127 ) ;
else
F_62 ( V_4 -> V_2 , V_127 ) ;
}
F_20 ( V_4 -> V_2 ) ;
}
static void F_66 ( struct V_3 * V_4 )
{
T_1 V_12 ;
F_9 ( V_128 , V_4 -> V_13 + V_60 ) ;
V_12 = V_129 ;
if ( ! V_4 -> V_35 )
V_12 |= V_130 ;
F_9 ( V_12 , V_4 -> V_13 + V_131 ) ;
F_9 ( V_132 | V_133 , V_4 -> V_13 + V_134 ) ;
if ( ! V_4 -> V_35 )
F_9 ( V_135 , V_4 -> V_13 + F_67 ( 0 ) ) ;
}
static int F_68 ( struct V_3 * V_4 )
{
int V_22 ;
if ( ! V_4 -> V_5 )
return 0 ;
V_4 -> V_5 = false ;
F_69 ( V_4 -> V_23 ) ;
V_22 = F_70 ( V_4 -> V_136 ) ;
if ( V_22 < 0 ) {
F_13 ( L_9 , V_22 ) ;
goto V_137;
}
V_22 = F_70 ( V_4 -> V_138 ) ;
if ( V_22 < 0 ) {
F_13 ( L_10 , V_22 ) ;
goto V_139;
}
V_22 = F_70 ( V_4 -> V_140 ) ;
if ( V_22 < 0 ) {
F_13 ( L_11 , V_22 ) ;
goto V_141;
}
V_22 = F_70 ( V_4 -> V_31 ) ;
if ( V_22 < 0 ) {
F_13 ( L_12 , V_22 ) ;
goto V_142;
}
F_66 ( V_4 ) ;
if ( F_33 ( 0 , & V_4 -> V_66 ) ) {
V_22 = F_30 ( V_4 -> V_2 ) ;
if ( V_22 ) {
F_13 ( L_13 , V_22 ) ;
goto V_143;
}
}
F_64 ( V_4 ) ;
F_65 ( V_4 ) ;
return 0 ;
V_143:
F_71 ( V_4 -> V_31 ) ;
V_142:
F_71 ( V_4 -> V_140 ) ;
V_141:
F_71 ( V_4 -> V_138 ) ;
V_139:
F_71 ( V_4 -> V_136 ) ;
V_137:
V_4 -> V_5 = true ;
return V_22 ;
}
static int F_72 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 )
return 0 ;
F_63 ( V_4 ) ;
F_71 ( V_4 -> V_31 ) ;
F_71 ( V_4 -> V_140 ) ;
F_71 ( V_4 -> V_138 ) ;
F_71 ( V_4 -> V_136 ) ;
F_73 ( V_4 -> V_23 ) ;
V_4 -> V_5 = true ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 , int V_25 )
{
F_5 ( L_14 , __FILE__ , V_25 ) ;
switch ( V_25 ) {
case V_144 :
F_68 ( V_2 -> V_4 ) ;
break;
case V_145 :
case V_146 :
case V_147 :
F_72 ( V_2 -> V_4 ) ;
break;
default:
F_5 ( L_15 , V_25 ) ;
break;
}
}
static T_2 F_75 ( int V_148 , void * V_149 )
{
struct V_3 * V_4 = (struct V_3 * ) V_149 ;
T_1 V_12 , V_150 ;
V_12 = F_7 ( V_4 -> V_13 + V_151 ) ;
V_150 = V_4 -> V_35 ? V_152 : V_153 ;
if ( V_12 & V_150 )
F_9 ( V_150 , V_4 -> V_13 + V_151 ) ;
if ( V_4 -> V_21 < 0 || ! V_4 -> V_17 )
goto V_154;
if ( ! V_4 -> V_35 ) {
F_76 ( V_4 -> V_17 , V_4 -> V_21 ) ;
F_77 ( V_4 -> V_17 , V_4 -> V_21 ) ;
if ( F_4 ( & V_4 -> V_6 ) ) {
F_2 ( & V_4 -> V_6 , 0 ) ;
F_78 ( & V_4 -> V_7 ) ;
}
}
V_154:
return V_155 ;
}
static int F_79 ( struct V_156 * V_23 , struct V_156 * V_157 , void * V_158 )
{
struct V_3 * V_4 = F_80 ( V_23 ) ;
struct V_16 * V_17 = V_158 ;
struct V_72 * V_159 ;
enum V_160 type ;
unsigned int V_161 ;
int V_22 ;
V_22 = F_10 ( V_4 , V_17 ) ;
if ( V_22 ) {
F_13 ( L_16 ) ;
return V_22 ;
}
for ( V_161 = 0 ; V_161 < V_11 ; V_161 ++ ) {
type = ( V_161 == V_4 -> V_162 ) ? V_163 :
V_164 ;
V_22 = F_81 ( V_17 , & V_4 -> V_74 [ V_161 ] ,
1 << V_4 -> V_21 , type , V_161 ) ;
if ( V_22 )
return V_22 ;
}
V_159 = & V_4 -> V_74 [ V_4 -> V_162 ] ;
V_4 -> V_2 = F_82 ( V_17 , & V_159 -> V_34 ,
V_4 -> V_21 , V_165 ,
& V_166 , V_4 ) ;
if ( F_83 ( V_4 -> V_2 ) ) {
F_14 ( V_4 ) ;
return F_84 ( V_4 -> V_2 ) ;
}
if ( V_4 -> V_167 )
F_85 ( V_17 , V_4 -> V_167 ) ;
return 0 ;
}
static void F_86 ( struct V_156 * V_23 , struct V_156 * V_157 ,
void * V_158 )
{
struct V_3 * V_4 = F_80 ( V_23 ) ;
F_74 ( V_4 -> V_2 , V_147 ) ;
if ( V_4 -> V_167 )
F_87 ( V_4 -> V_167 ) ;
F_14 ( V_4 ) ;
}
static int F_88 ( struct V_168 * V_169 )
{
struct V_156 * V_23 = & V_169 -> V_23 ;
struct V_3 * V_4 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
int V_22 ;
if ( ! V_23 -> V_174 )
return - V_175 ;
V_4 = F_89 ( V_23 , sizeof( * V_4 ) , V_176 ) ;
if ( ! V_4 )
return - V_177 ;
V_22 = F_90 ( V_23 , V_178 ,
V_165 ) ;
if ( V_22 )
return V_22 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_5 = true ;
V_171 = F_91 ( V_23 -> V_174 , L_17 ) ;
if ( V_171 )
V_4 -> V_35 = true ;
F_92 ( V_171 ) ;
V_4 -> V_13 = F_93 ( V_23 -> V_174 , 0 ) ;
if ( ! V_4 -> V_13 ) {
V_22 = - V_177 ;
goto V_179;
}
V_4 -> V_136 = F_94 ( V_23 , L_18 ) ;
if ( F_83 ( V_4 -> V_136 ) ) {
F_95 ( V_23 , L_19 ) ;
V_22 = F_84 ( V_4 -> V_136 ) ;
goto V_180;
}
V_4 -> V_138 = F_94 ( V_23 , L_20 ) ;
if ( F_83 ( V_4 -> V_138 ) ) {
F_95 ( V_23 , L_21 ) ;
V_22 = F_84 ( V_4 -> V_138 ) ;
goto V_180;
}
V_4 -> V_140 = F_94 ( V_23 , L_22 ) ;
if ( F_83 ( V_4 -> V_140 ) ) {
F_95 ( V_23 , L_23 ) ;
V_22 = F_84 ( V_4 -> V_140 ) ;
goto V_180;
}
V_4 -> V_31 = F_94 ( V_23 , L_24 ) ;
if ( F_83 ( V_4 -> V_31 ) ) {
F_95 ( V_23 , L_25 ) ;
V_22 = F_84 ( V_4 -> V_31 ) ;
goto V_180;
}
V_173 = F_96 ( V_169 , V_181 ,
V_4 -> V_35 ? L_26 : L_27 ) ;
if ( ! V_173 ) {
F_95 ( V_23 , L_28 ) ;
V_22 = - V_182 ;
goto V_180;
}
V_22 = F_97 ( V_23 , V_173 -> V_183 , F_75 ,
0 , L_29 , V_4 ) ;
if ( V_22 ) {
F_95 ( V_23 , L_28 ) ;
goto V_180;
}
F_98 ( & V_4 -> V_7 ) ;
F_2 ( & V_4 -> V_6 , 0 ) ;
F_99 ( V_169 , V_4 ) ;
V_4 -> V_167 = F_100 ( V_23 ) ;
if ( F_83 ( V_4 -> V_167 ) ) {
V_22 = F_84 ( V_4 -> V_167 ) ;
goto V_180;
}
F_101 ( V_23 ) ;
V_22 = F_102 ( V_23 , & V_184 ) ;
if ( V_22 )
goto V_185;
return V_22 ;
V_185:
F_103 ( V_23 ) ;
V_180:
F_104 ( V_4 -> V_13 ) ;
V_179:
F_105 ( V_23 , V_178 ) ;
return V_22 ;
}
static int F_106 ( struct V_168 * V_169 )
{
struct V_3 * V_4 = F_80 ( & V_169 -> V_23 ) ;
F_103 ( & V_169 -> V_23 ) ;
F_104 ( V_4 -> V_13 ) ;
F_107 ( & V_169 -> V_23 , & V_184 ) ;
F_105 ( & V_169 -> V_23 , V_178 ) ;
return 0 ;
}
