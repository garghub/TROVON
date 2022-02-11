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
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
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
if ( V_10 )
F_1 ( V_4 -> V_2 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
V_4 -> V_16 = V_16 ;
F_6 ( V_4 -> V_2 ) ;
return F_11 ( V_16 , V_4 -> V_17 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_13 ( V_4 -> V_16 , V_4 -> V_17 ) ;
}
static T_1 F_14 ( struct V_3 * V_4 ,
const struct V_18 * V_19 )
{
unsigned long V_20 = V_19 -> V_21 * V_19 -> V_22 * V_19 -> V_23 ;
T_1 V_24 ;
V_24 = F_15 ( F_16 ( V_4 -> V_25 ) , V_20 ) ;
return ( V_24 < 0x100 ) ? V_24 : 0xff ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_18 * V_19 = & V_2 -> V_26 . V_27 -> V_28 ;
T_1 V_12 , V_24 ;
if ( V_4 -> V_5 )
return;
if ( V_19 -> V_21 == 0 || V_19 -> V_22 == 0 )
return;
if ( ! V_4 -> V_29 ) {
int V_30 , V_31 , V_32 , V_33 , V_34 , V_35 ;
V_30 = V_19 -> V_36 - V_19 -> V_37 ;
V_31 = V_19 -> V_38 - V_19 -> V_36 ;
V_32 = V_19 -> V_37 - V_19 -> V_39 ;
V_12 = F_18 ( V_31 - 1 ) | F_19 ( V_32 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_40 ) ;
V_12 = F_20 ( V_30 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_41 ) ;
V_33 = V_19 -> V_42 - V_19 -> V_43 ;
V_34 = V_19 -> V_44 - V_19 -> V_42 ;
V_35 = V_19 -> V_43 - V_19 -> V_45 ;
V_12 = F_21 ( V_34 - 1 ) | F_22 ( V_35 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_46 ) ;
V_12 = F_23 ( V_33 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_47 ) ;
}
V_12 = F_24 ( V_19 -> V_48 - 1 ) |
F_25 ( V_19 -> V_49 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_50 ) ;
F_9 ( V_19 -> V_48 - 1 , V_4 -> V_13 + V_51 ) ;
V_12 = V_52 | V_53 ;
F_9 ( V_12 , V_4 -> V_13 + V_54 ) ;
V_24 = F_14 ( V_4 , V_19 ) ;
if ( V_24 > 1 ) {
V_12 = F_26 ( V_24 - 1 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_55 ) ;
F_9 ( V_12 , V_4 -> V_13 + V_56 ) ;
}
V_12 = F_7 ( V_4 -> V_13 + V_57 ) ;
V_12 |= V_58 ;
F_9 ( V_12 , V_4 -> V_13 + V_57 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return - V_59 ;
if ( ! F_28 ( 0 , & V_4 -> V_60 ) ) {
V_12 = F_7 ( V_4 -> V_13 + V_61 ) ;
V_12 |= V_62 ;
if ( ! V_4 -> V_29 ) {
V_12 |= V_63 ;
V_12 &= ~ V_64 ;
V_12 |= V_65 ;
}
F_9 ( V_12 , V_4 -> V_13 + V_61 ) ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return;
if ( F_30 ( 0 , & V_4 -> V_60 ) ) {
V_12 = F_7 ( V_4 -> V_13 + V_61 ) ;
V_12 &= ~ V_62 ;
if ( ! V_4 -> V_29 )
V_12 &= ~ V_63 ;
F_9 ( V_12 , V_4 -> V_13 + V_61 ) ;
}
}
static void F_31 ( struct V_3 * V_4 , unsigned int V_9 ,
struct V_66 * V_67 )
{
unsigned long V_12 ;
int V_68 ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 &= ~ V_69 ;
switch ( V_67 -> V_70 -> V_70 ) {
case V_71 :
V_12 |= V_72 ;
V_12 |= V_73 ;
break;
case V_74 :
V_12 |= V_75 ;
V_12 |= V_73 ;
break;
case V_76 :
V_12 |= V_77 ;
V_12 |= V_73 ;
break;
case V_78 :
V_12 |= V_79 ;
V_12 |= V_73 ;
break;
case V_80 :
V_12 |= V_81 ;
V_12 |= V_73 ;
break;
case V_82 :
V_12 |= V_83 | V_84 |
V_85 ;
V_12 |= V_73 ;
break;
case V_86 :
V_12 |= V_87 | V_84 |
V_85 ;
V_12 |= V_73 ;
break;
case V_88 :
V_12 |= V_89 | V_84 |
V_85 ;
V_12 |= V_73 ;
break;
case V_90 :
V_12 |= V_91 | V_84 |
V_85 ;
V_12 |= V_73 ;
break;
default:
F_5 ( L_3 ) ;
V_12 |= V_75 ;
V_12 |= V_73 ;
break;
}
F_5 ( L_4 , V_67 -> V_70 -> V_92 [ 0 ] * 8 ) ;
V_68 = ( V_67 -> V_93 [ 0 ] / V_67 -> V_70 -> V_92 [ 0 ] ) - V_67 -> V_94 ;
if ( V_67 -> V_94 + V_68 < V_95 ) {
V_12 &= ~ V_96 ;
V_12 |= V_97 ;
}
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
}
static void F_32 ( struct V_3 * V_4 , unsigned int V_9 )
{
unsigned int V_98 = 0 , V_99 = 0 ;
V_98 = ~ ( V_100 | V_101 |
V_102 ) | F_33 ( 0 ) ;
V_99 = F_34 ( 0xffffffff ) ;
F_9 ( V_98 , V_4 -> V_13 + F_35 ( V_9 ) ) ;
F_9 ( V_99 , V_4 -> V_13 + F_36 ( V_9 ) ) ;
}
static void F_37 ( struct V_3 * V_4 ,
unsigned int V_9 , bool V_103 )
{
T_1 V_104 , V_12 ;
V_104 = F_38 ( V_9 ) ;
V_12 = F_7 ( V_4 -> V_13 + V_105 ) ;
if ( V_103 )
V_12 |= V_104 ;
else
V_12 &= ~ V_104 ;
F_9 ( V_12 , V_4 -> V_13 + V_105 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_106 ;
if ( V_4 -> V_5 )
return;
for ( V_106 = 0 ; V_106 < V_11 ; V_106 ++ )
F_37 ( V_4 , V_106 , true ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
struct V_109 * V_27 =
F_41 ( V_108 -> V_26 . V_27 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_66 * V_67 = V_27 -> V_26 . V_67 ;
int V_68 ;
unsigned long V_12 , V_110 ;
unsigned int V_111 ;
unsigned int V_112 ;
unsigned int V_9 = V_108 -> V_113 ;
unsigned int V_114 = V_67 -> V_70 -> V_92 [ 0 ] ;
unsigned int V_115 = V_67 -> V_93 [ 0 ] ;
if ( V_4 -> V_5 )
return;
V_12 = ( unsigned long ) F_42 ( V_67 , 0 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_43 ( V_9 ) ) ;
V_68 = ( V_115 / V_114 ) - V_67 -> V_94 ;
F_9 ( V_67 -> V_94 + V_68 , V_4 -> V_13 + F_44 ( V_9 ) ) ;
F_9 ( V_67 -> V_116 , V_4 -> V_13 + F_45 ( V_9 ) ) ;
F_9 ( V_27 -> V_117 . V_118 , V_4 -> V_13 + F_46 ( V_9 ) ) ;
F_9 ( V_27 -> V_117 . V_119 , V_4 -> V_13 + F_47 ( V_9 ) ) ;
F_5 ( L_5 ,
( unsigned long ) V_12 ) ;
F_5 ( L_6 ,
V_27 -> V_2 . V_120 , V_27 -> V_2 . V_121 ) ;
V_12 = F_48 ( V_27 -> V_2 . V_118 ) |
F_49 ( V_27 -> V_2 . V_119 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_50 ( V_9 ) ) ;
V_111 = V_27 -> V_2 . V_118 + V_27 -> V_2 . V_120 ;
if ( V_111 )
V_111 -- ;
V_112 = V_27 -> V_2 . V_119 + V_27 -> V_2 . V_121 ;
if ( V_112 )
V_112 -- ;
V_12 = F_51 ( V_111 ) | F_52 ( V_112 ) ;
F_9 ( V_12 , V_4 -> V_13 + F_53 ( V_9 ) ) ;
F_5 ( L_7 ,
V_27 -> V_2 . V_118 , V_27 -> V_2 . V_119 , V_111 , V_112 ) ;
V_110 = F_54 ( 0x0 ) |
F_55 ( 0x0 ) |
F_56 ( 0x0 ) ;
F_9 ( V_110 , V_4 -> V_13 + F_57 ( V_9 ) ) ;
V_110 = F_58 ( 0xff ) |
F_59 ( 0xff ) |
F_60 ( 0xff ) ;
F_9 ( V_110 , V_4 -> V_13 + F_61 ( V_9 ) ) ;
F_31 ( V_4 , V_9 , V_67 ) ;
if ( V_9 != 0 )
F_32 ( V_4 , V_9 ) ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 |= V_122 ;
V_12 |= V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
F_37 ( V_4 , V_9 , false ) ;
V_12 = F_7 ( V_4 -> V_13 + V_57 ) ;
V_12 |= V_58 ;
F_9 ( V_12 , V_4 -> V_13 + V_57 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_9 = V_108 -> V_113 ;
T_1 V_12 ;
if ( V_4 -> V_5 )
return;
F_37 ( V_4 , V_9 , true ) ;
V_12 = F_7 ( V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 &= ~ V_14 ;
F_9 ( V_12 , V_4 -> V_13 + F_8 ( V_9 ) ) ;
V_12 = F_7 ( V_4 -> V_13 + V_57 ) ;
V_12 |= V_58 ;
F_9 ( V_12 , V_4 -> V_13 + V_57 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_106 ;
if ( V_4 -> V_5 )
return;
for ( V_106 = 0 ; V_106 < V_11 ; V_106 ++ )
F_37 ( V_4 , V_106 , false ) ;
F_64 ( V_2 ) ;
}
static void F_65 ( struct V_3 * V_4 )
{
T_1 V_12 ;
F_9 ( V_123 , V_4 -> V_13 + V_54 ) ;
V_12 = V_124 ;
if ( ! V_4 -> V_29 )
V_12 |= V_125 ;
F_9 ( V_12 , V_4 -> V_13 + V_126 ) ;
F_9 ( V_127 | V_128 , V_4 -> V_13 + V_129 ) ;
if ( ! V_4 -> V_29 )
F_9 ( V_130 , V_4 -> V_13 + F_66 ( 0 ) ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_5 )
return;
F_68 ( V_4 -> V_17 ) ;
F_65 ( V_4 ) ;
if ( F_30 ( 0 , & V_4 -> V_60 ) )
F_27 ( V_4 -> V_2 ) ;
F_17 ( V_4 -> V_2 ) ;
V_4 -> V_5 = false ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_106 ;
if ( V_4 -> V_5 )
return;
for ( V_106 = 0 ; V_106 < V_11 ; V_106 ++ )
F_62 ( V_2 , & V_4 -> V_131 [ V_106 ] ) ;
F_70 ( V_4 -> V_17 ) ;
V_4 -> V_5 = true ;
}
static T_2 F_71 ( int V_132 , void * V_133 )
{
struct V_3 * V_4 = (struct V_3 * ) V_133 ;
T_1 V_12 , V_134 ;
V_12 = F_7 ( V_4 -> V_13 + V_135 ) ;
V_134 = V_4 -> V_29 ? V_136 : V_137 ;
if ( V_12 & V_134 )
F_9 ( V_134 , V_4 -> V_13 + V_135 ) ;
if ( ! V_4 -> V_16 )
goto V_138;
if ( ! V_4 -> V_29 ) {
F_72 ( & V_4 -> V_2 -> V_26 ) ;
if ( F_4 ( & V_4 -> V_6 ) ) {
F_2 ( & V_4 -> V_6 , 0 ) ;
F_73 ( & V_4 -> V_7 ) ;
}
}
V_138:
return V_139 ;
}
static int F_74 ( struct V_140 * V_17 , struct V_140 * V_141 , void * V_142 )
{
struct V_3 * V_4 = F_75 ( V_17 ) ;
struct V_15 * V_16 = V_142 ;
struct V_107 * V_143 ;
unsigned int V_106 ;
int V_144 ;
V_144 = F_10 ( V_4 , V_16 ) ;
if ( V_144 ) {
F_76 ( L_8 ) ;
return V_144 ;
}
for ( V_106 = 0 ; V_106 < V_11 ; V_106 ++ ) {
V_4 -> V_145 [ V_106 ] . V_146 = V_147 ;
V_4 -> V_145 [ V_106 ] . V_148 = F_77 ( V_147 ) ;
V_4 -> V_145 [ V_106 ] . V_149 = V_106 ;
V_4 -> V_145 [ V_106 ] . type = V_150 [ V_106 ] ;
V_144 = F_78 ( V_16 , & V_4 -> V_131 [ V_106 ] , V_106 ,
& V_4 -> V_145 [ V_106 ] ) ;
if ( V_144 )
return V_144 ;
}
V_143 = & V_4 -> V_131 [ V_151 ] ;
V_4 -> V_2 = F_79 ( V_16 , & V_143 -> V_26 ,
V_152 , & V_153 , V_4 ) ;
if ( F_80 ( V_4 -> V_2 ) ) {
F_12 ( V_4 ) ;
return F_81 ( V_4 -> V_2 ) ;
}
if ( V_4 -> V_154 )
F_82 ( V_16 , V_4 -> V_154 ) ;
return 0 ;
}
static void F_83 ( struct V_140 * V_17 , struct V_140 * V_141 ,
void * V_142 )
{
struct V_3 * V_4 = F_75 ( V_17 ) ;
F_69 ( V_4 -> V_2 ) ;
if ( V_4 -> V_154 )
F_84 ( V_4 -> V_154 ) ;
F_12 ( V_4 ) ;
}
static int F_85 ( struct V_155 * V_156 )
{
struct V_140 * V_17 = & V_156 -> V_17 ;
struct V_3 * V_4 ;
struct V_157 * V_158 ;
struct V_159 * V_160 ;
int V_144 ;
if ( ! V_17 -> V_161 )
return - V_162 ;
V_4 = F_86 ( V_17 , sizeof( * V_4 ) , V_163 ) ;
if ( ! V_4 )
return - V_164 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_5 = true ;
V_158 = F_87 ( V_17 -> V_161 , L_9 ) ;
if ( V_158 )
V_4 -> V_29 = true ;
F_88 ( V_158 ) ;
V_4 -> V_13 = F_89 ( V_17 -> V_161 , 0 ) ;
if ( ! V_4 -> V_13 )
return - V_164 ;
V_4 -> V_165 = F_90 ( V_17 , L_10 ) ;
if ( F_80 ( V_4 -> V_165 ) ) {
F_91 ( V_17 , L_11 ) ;
V_144 = F_81 ( V_4 -> V_165 ) ;
goto V_166;
}
V_4 -> V_167 = F_90 ( V_17 , L_12 ) ;
if ( F_80 ( V_4 -> V_167 ) ) {
F_91 ( V_17 , L_13 ) ;
V_144 = F_81 ( V_4 -> V_167 ) ;
goto V_166;
}
V_4 -> V_168 = F_90 ( V_17 , L_14 ) ;
if ( F_80 ( V_4 -> V_168 ) ) {
F_91 ( V_17 , L_15 ) ;
V_144 = F_81 ( V_4 -> V_168 ) ;
goto V_166;
}
V_4 -> V_25 = F_90 ( V_17 , L_16 ) ;
if ( F_80 ( V_4 -> V_25 ) ) {
F_91 ( V_17 , L_17 ) ;
V_144 = F_81 ( V_4 -> V_25 ) ;
goto V_166;
}
V_160 = F_92 ( V_156 , V_169 ,
V_4 -> V_29 ? L_18 : L_19 ) ;
if ( ! V_160 ) {
F_91 ( V_17 , L_20 ) ;
V_144 = - V_170 ;
goto V_166;
}
V_144 = F_93 ( V_17 , V_160 -> V_171 , F_71 ,
0 , L_21 , V_4 ) ;
if ( V_144 ) {
F_91 ( V_17 , L_20 ) ;
goto V_166;
}
F_94 ( & V_4 -> V_7 ) ;
F_2 ( & V_4 -> V_6 , 0 ) ;
F_95 ( V_156 , V_4 ) ;
V_4 -> V_154 = F_96 ( V_17 ) ;
if ( F_80 ( V_4 -> V_154 ) ) {
V_144 = F_81 ( V_4 -> V_154 ) ;
goto V_166;
}
F_97 ( V_17 ) ;
V_144 = F_98 ( V_17 , & V_172 ) ;
if ( V_144 )
goto V_173;
return V_144 ;
V_173:
F_99 ( V_17 ) ;
V_166:
F_100 ( V_4 -> V_13 ) ;
return V_144 ;
}
static int F_101 ( struct V_155 * V_156 )
{
struct V_3 * V_4 = F_75 ( & V_156 -> V_17 ) ;
F_99 ( & V_156 -> V_17 ) ;
F_100 ( V_4 -> V_13 ) ;
F_102 ( & V_156 -> V_17 , & V_172 ) ;
return 0 ;
}
static int F_103 ( struct V_140 * V_17 )
{
struct V_3 * V_4 = F_75 ( V_17 ) ;
F_104 ( V_4 -> V_25 ) ;
F_104 ( V_4 -> V_168 ) ;
F_104 ( V_4 -> V_167 ) ;
F_104 ( V_4 -> V_165 ) ;
return 0 ;
}
static int F_105 ( struct V_140 * V_17 )
{
struct V_3 * V_4 = F_75 ( V_17 ) ;
int V_144 ;
V_144 = F_106 ( V_4 -> V_165 ) ;
if ( V_144 < 0 ) {
F_76 ( L_22 , V_144 ) ;
return V_144 ;
}
V_144 = F_106 ( V_4 -> V_167 ) ;
if ( V_144 < 0 ) {
F_76 ( L_23 , V_144 ) ;
return V_144 ;
}
V_144 = F_106 ( V_4 -> V_168 ) ;
if ( V_144 < 0 ) {
F_76 ( L_24 , V_144 ) ;
return V_144 ;
}
V_144 = F_106 ( V_4 -> V_25 ) ;
if ( V_144 < 0 ) {
F_76 ( L_25 , V_144 ) ;
return V_144 ;
}
return 0 ;
}
