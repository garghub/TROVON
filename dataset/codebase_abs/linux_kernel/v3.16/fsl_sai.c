static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
T_2 V_8 , V_9 , V_10 ;
bool V_11 = true ;
V_10 = ( V_12 >> V_13 ) << V_14 ;
F_2 ( V_4 -> V_15 , V_16 , & V_9 ) ;
V_8 = V_9 & V_10 ;
if ( V_8 )
V_11 = false ;
else
goto V_17;
if ( V_8 & V_18 )
F_3 ( V_6 , L_1 ) ;
if ( V_8 & V_19 )
F_4 ( V_6 , L_2 ) ;
if ( V_8 & V_20 ) {
F_4 ( V_6 , L_3 ) ;
V_9 |= V_21 ;
}
if ( V_8 & V_22 )
F_3 ( V_6 , L_4 ) ;
if ( V_8 & V_23 )
F_3 ( V_6 , L_5 ) ;
V_8 &= V_24 ;
V_9 &= ~ V_25 ;
if ( V_8 )
F_5 ( V_4 -> V_15 , V_16 , V_8 | V_9 ) ;
V_17:
F_2 ( V_4 -> V_15 , V_26 , & V_9 ) ;
V_8 = V_9 & V_10 ;
if ( V_8 )
V_11 = false ;
else
goto V_27;
if ( V_8 & V_18 )
F_3 ( V_6 , L_6 ) ;
if ( V_8 & V_19 )
F_4 ( V_6 , L_7 ) ;
if ( V_8 & V_20 ) {
F_4 ( V_6 , L_8 ) ;
V_9 |= V_21 ;
}
if ( V_8 & V_22 )
F_3 ( V_6 , L_9 ) ;
if ( V_8 & V_23 )
F_3 ( V_6 , L_10 ) ;
V_8 &= V_24 ;
V_9 &= ~ V_25 ;
if ( V_8 )
F_5 ( V_4 -> V_15 , V_16 , V_8 | V_9 ) ;
V_27:
if ( V_11 )
return V_28 ;
else
return V_29 ;
}
static int F_6 ( struct V_30 * V_31 ,
int V_32 , unsigned int V_33 , int V_34 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_34 == V_36 ;
T_2 V_37 = 0 ;
switch ( V_32 ) {
case V_38 :
V_37 |= V_39 ;
break;
case V_40 :
V_37 |= V_41 ;
break;
case V_42 :
V_37 |= V_43 ;
break;
case V_44 :
V_37 |= V_45 ;
break;
default:
return - V_46 ;
}
F_8 ( V_4 -> V_15 , F_9 ( V_35 ) ,
V_47 , V_37 ) ;
return 0 ;
}
static int F_10 ( struct V_30 * V_31 ,
int V_32 , unsigned int V_33 , int V_48 )
{
int V_49 ;
if ( V_48 == V_50 )
return 0 ;
V_49 = F_6 ( V_31 , V_32 , V_33 ,
V_36 ) ;
if ( V_49 ) {
F_11 ( V_31 -> V_6 , L_11 , V_49 ) ;
return V_49 ;
}
V_49 = F_6 ( V_31 , V_32 , V_33 ,
V_51 ) ;
if ( V_49 )
F_11 ( V_31 -> V_6 , L_12 , V_49 ) ;
return V_49 ;
}
static int F_12 ( struct V_30 * V_31 ,
unsigned int V_52 , int V_34 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_34 == V_36 ;
T_2 V_37 = 0 , V_53 = 0 ;
if ( ! V_4 -> V_54 )
V_53 |= V_55 ;
switch ( V_52 & V_56 ) {
case V_57 :
V_37 |= V_58 ;
V_53 |= V_59 | V_60 ;
break;
case V_61 :
V_37 |= V_58 ;
break;
case V_62 :
V_37 |= V_58 ;
V_53 |= V_59 ;
V_4 -> V_63 = true ;
break;
case V_64 :
V_37 |= V_58 ;
V_4 -> V_63 = true ;
break;
case V_65 :
default:
return - V_46 ;
}
switch ( V_52 & V_66 ) {
case V_67 :
V_37 ^= V_58 ;
V_53 ^= V_60 ;
break;
case V_68 :
V_37 ^= V_58 ;
break;
case V_69 :
V_53 ^= V_60 ;
break;
case V_70 :
break;
default:
return - V_46 ;
}
switch ( V_52 & V_71 ) {
case V_72 :
V_37 |= V_73 ;
V_53 |= V_74 ;
break;
case V_75 :
break;
case V_76 :
V_37 |= V_73 ;
break;
case V_77 :
V_53 |= V_74 ;
break;
default:
return - V_46 ;
}
F_8 ( V_4 -> V_15 , F_9 ( V_35 ) ,
V_58 | V_73 , V_37 ) ;
F_8 ( V_4 -> V_15 , F_13 ( V_35 ) ,
V_55 | V_59 |
V_60 | V_74 , V_53 ) ;
return 0 ;
}
static int F_14 ( struct V_30 * V_31 , unsigned int V_52 )
{
int V_49 ;
V_49 = F_12 ( V_31 , V_52 , V_36 ) ;
if ( V_49 ) {
F_11 ( V_31 -> V_6 , L_13 , V_49 ) ;
return V_49 ;
}
V_49 = F_12 ( V_31 , V_52 , V_51 ) ;
if ( V_49 )
F_11 ( V_31 -> V_6 , L_14 , V_49 ) ;
return V_49 ;
}
static int F_15 ( struct V_78 * V_79 ,
struct V_80 * V_81 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_79 -> V_82 == V_83 ;
unsigned int V_84 = F_16 ( V_81 ) ;
T_2 V_85 = F_17 ( F_18 ( V_81 ) ) ;
T_2 V_53 = 0 , V_86 = 0 ;
if ( ! V_4 -> V_63 )
V_53 |= F_19 ( V_85 ) ;
V_86 |= F_20 ( V_85 ) ;
V_86 |= F_21 ( V_85 ) ;
if ( V_4 -> V_54 )
V_86 |= F_22 ( 0 ) ;
else
V_86 |= F_22 ( V_85 - 1 ) ;
V_53 |= F_23 ( V_84 ) ;
F_8 ( V_4 -> V_15 , F_13 ( V_35 ) ,
V_87 | V_88 ,
V_53 ) ;
F_8 ( V_4 -> V_15 , F_24 ( V_35 ) ,
V_89 | V_90 |
V_91 , V_86 ) ;
F_5 ( V_4 -> V_15 , F_25 ( V_35 ) , ~ 0UL - ( ( 1 << V_84 ) - 1 ) ) ;
return 0 ;
}
static int F_26 ( struct V_78 * V_79 , int V_92 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_79 -> V_82 == V_83 ;
T_2 V_93 , V_94 ;
F_8 ( V_4 -> V_15 , V_95 , V_96 ,
~ V_96 ) ;
F_8 ( V_4 -> V_15 , V_97 , V_96 ,
V_96 ) ;
F_2 ( V_4 -> V_15 , V_16 , & V_93 ) ;
F_2 ( V_4 -> V_15 , V_26 , & V_94 ) ;
switch ( V_92 ) {
case V_98 :
case V_99 :
case V_100 :
if ( ! ( V_93 & V_101 || V_94 & V_101 ) ) {
F_8 ( V_4 -> V_15 , V_26 ,
V_102 , V_102 ) ;
F_8 ( V_4 -> V_15 , V_16 ,
V_102 , V_102 ) ;
}
F_8 ( V_4 -> V_15 , F_27 ( V_35 ) ,
V_103 , V_12 ) ;
F_8 ( V_4 -> V_15 , F_27 ( V_35 ) ,
V_101 , V_101 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
F_8 ( V_4 -> V_15 , F_27 ( V_35 ) ,
V_101 , 0 ) ;
F_8 ( V_4 -> V_15 , F_27 ( V_35 ) ,
V_103 , 0 ) ;
if ( ! ( V_35 ? V_94 & V_101 : V_93 & V_101 ) ) {
F_8 ( V_4 -> V_15 , V_16 ,
V_102 , 0 ) ;
F_8 ( V_4 -> V_15 , V_26 ,
V_102 , 0 ) ;
}
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_28 ( struct V_78 * V_79 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_79 -> V_82 == V_83 ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
int V_49 ;
V_49 = F_29 ( V_4 -> V_107 ) ;
if ( V_49 ) {
F_11 ( V_6 , L_15 , V_49 ) ;
return V_49 ;
}
F_8 ( V_4 -> V_15 , F_30 ( V_35 ) , V_108 ,
V_108 ) ;
return 0 ;
}
static void F_31 ( struct V_78 * V_79 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_79 -> V_82 == V_83 ;
F_8 ( V_4 -> V_15 , F_30 ( V_35 ) , V_108 , 0 ) ;
F_32 ( V_4 -> V_107 ) ;
}
static int F_33 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_34 ( V_31 -> V_6 ) ;
F_8 ( V_4 -> V_15 , V_16 , 0xffffffff , 0x0 ) ;
F_8 ( V_4 -> V_15 , V_26 , 0xffffffff , 0x0 ) ;
F_8 ( V_4 -> V_15 , V_109 , V_110 ,
V_111 * 2 ) ;
F_8 ( V_4 -> V_15 , V_112 , V_110 ,
V_113 - 1 ) ;
F_35 ( V_31 , & V_4 -> V_114 ,
& V_4 -> V_115 ) ;
F_36 ( V_31 , V_4 ) ;
return 0 ;
}
static bool F_37 ( struct V_5 * V_6 , unsigned int V_116 )
{
switch ( V_116 ) {
case V_16 :
case V_109 :
case V_95 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_26 :
case V_112 :
case V_97 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
return true ;
default:
return false ;
}
}
static bool F_38 ( struct V_5 * V_6 , unsigned int V_116 )
{
switch ( V_116 ) {
case V_120 :
case V_126 :
case V_128 :
case V_125 :
return true ;
default:
return false ;
}
}
static bool F_39 ( struct V_5 * V_6 , unsigned int V_116 )
{
switch ( V_116 ) {
case V_16 :
case V_109 :
case V_95 :
case V_117 :
case V_118 :
case V_119 :
case V_128 :
case V_121 :
case V_26 :
case V_112 :
case V_97 :
case V_122 :
case V_123 :
case V_124 :
case V_127 :
return true ;
default:
return false ;
}
}
static int F_40 ( struct V_129 * V_7 )
{
struct V_130 * V_131 = V_7 -> V_6 . V_132 ;
struct V_3 * V_4 ;
struct V_133 * V_134 ;
void T_3 * V_135 ;
char V_136 [ 8 ] ;
int V_1 , V_49 , V_137 ;
V_4 = F_41 ( & V_7 -> V_6 , sizeof( * V_4 ) , V_138 ) ;
if ( ! V_4 )
return - V_139 ;
V_4 -> V_7 = V_7 ;
if ( F_42 ( V_7 -> V_6 . V_132 , L_16 ) )
V_4 -> V_140 = true ;
V_4 -> V_141 = F_43 ( V_131 , L_17 ) ;
if ( V_4 -> V_141 )
V_142 . V_143 = V_144 ;
V_4 -> V_54 = F_43 ( V_131 , L_18 ) ;
V_134 = F_44 ( V_7 , V_145 , 0 ) ;
V_135 = F_45 ( & V_7 -> V_6 , V_134 ) ;
if ( F_46 ( V_135 ) )
return F_47 ( V_135 ) ;
V_4 -> V_15 = F_48 ( & V_7 -> V_6 ,
L_19 , V_135 , & V_142 ) ;
if ( F_46 ( V_4 -> V_15 ) )
V_4 -> V_15 = F_48 ( & V_7 -> V_6 ,
L_20 , V_135 , & V_142 ) ;
if ( F_46 ( V_4 -> V_15 ) ) {
F_11 ( & V_7 -> V_6 , L_21 ) ;
return F_47 ( V_4 -> V_15 ) ;
}
V_4 -> V_107 = F_49 ( & V_7 -> V_6 , L_19 ) ;
if ( F_46 ( V_4 -> V_107 ) ) {
F_11 ( & V_7 -> V_6 , L_22 ,
F_47 ( V_4 -> V_107 ) ) ;
V_4 -> V_107 = NULL ;
}
for ( V_137 = 0 ; V_137 < V_146 ; V_137 ++ ) {
sprintf ( V_136 , L_23 , V_137 + 1 ) ;
V_4 -> V_147 [ V_137 ] = F_49 ( & V_7 -> V_6 , V_136 ) ;
if ( F_46 ( V_4 -> V_147 [ V_137 ] ) ) {
F_11 ( & V_7 -> V_6 , L_24 ,
V_137 + 1 , F_47 ( V_4 -> V_147 [ V_137 ] ) ) ;
V_4 -> V_147 [ V_137 ] = NULL ;
}
}
V_1 = F_50 ( V_7 , 0 ) ;
if ( V_1 < 0 ) {
F_11 ( & V_7 -> V_6 , L_25 , V_131 -> V_148 ) ;
return V_1 ;
}
V_49 = F_51 ( & V_7 -> V_6 , V_1 , F_1 , 0 , V_131 -> V_149 , V_4 ) ;
if ( V_49 ) {
F_11 ( & V_7 -> V_6 , L_26 , V_1 ) ;
return V_49 ;
}
V_4 -> V_115 . V_150 = V_134 -> V_151 + V_125 ;
V_4 -> V_114 . V_150 = V_134 -> V_151 + V_128 ;
V_4 -> V_115 . V_152 = V_113 ;
V_4 -> V_114 . V_152 = V_111 ;
F_52 ( V_7 , V_4 ) ;
V_49 = F_53 ( & V_7 -> V_6 , & V_153 ,
& V_154 , 1 ) ;
if ( V_49 )
return V_49 ;
if ( V_4 -> V_140 )
return F_54 ( V_7 ) ;
else
return F_55 ( & V_7 -> V_6 , NULL ,
V_155 ) ;
}
