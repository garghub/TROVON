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
F_5 ( V_4 -> V_15 , V_26 , V_8 | V_9 ) ;
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
T_2 V_9 , V_93 = 100 ;
F_8 ( V_4 -> V_15 , V_94 , V_95 ,
~ V_95 ) ;
F_8 ( V_4 -> V_15 , V_96 , V_95 ,
V_95 ) ;
switch ( V_92 ) {
case V_97 :
case V_98 :
case V_99 :
F_8 ( V_4 -> V_15 , F_27 ( V_35 ) ,
V_100 , V_100 ) ;
F_8 ( V_4 -> V_15 , V_26 ,
V_101 , V_101 ) ;
F_8 ( V_4 -> V_15 , V_16 ,
V_101 , V_101 ) ;
F_8 ( V_4 -> V_15 , F_27 ( V_35 ) ,
V_102 , V_12 ) ;
break;
case V_103 :
case V_104 :
case V_105 :
F_8 ( V_4 -> V_15 , F_27 ( V_35 ) ,
V_100 , 0 ) ;
F_8 ( V_4 -> V_15 , F_27 ( V_35 ) ,
V_102 , 0 ) ;
F_2 ( V_4 -> V_15 , F_27 ( ! V_35 ) , & V_9 ) ;
if ( ! ( V_9 & V_100 ) ) {
F_8 ( V_4 -> V_15 , V_16 ,
V_101 , 0 ) ;
F_8 ( V_4 -> V_15 , V_26 ,
V_101 , 0 ) ;
do {
F_28 ( 10 ) ;
F_2 ( V_4 -> V_15 , F_27 ( V_35 ) , & V_9 ) ;
} while ( -- V_93 && V_9 & V_101 );
F_8 ( V_4 -> V_15 , V_16 ,
V_21 , V_21 ) ;
F_8 ( V_4 -> V_15 , V_26 ,
V_21 , V_21 ) ;
}
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_29 ( struct V_78 * V_79 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_79 -> V_82 == V_83 ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
int V_49 ;
V_49 = F_30 ( V_4 -> V_106 ) ;
if ( V_49 ) {
F_11 ( V_6 , L_15 , V_49 ) ;
return V_49 ;
}
F_8 ( V_4 -> V_15 , F_31 ( V_35 ) , V_107 ,
V_107 ) ;
return 0 ;
}
static void F_32 ( struct V_78 * V_79 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_79 -> V_82 == V_83 ;
F_8 ( V_4 -> V_15 , F_31 ( V_35 ) , V_107 , 0 ) ;
F_33 ( V_4 -> V_106 ) ;
}
static int F_34 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_35 ( V_31 -> V_6 ) ;
F_8 ( V_4 -> V_15 , V_16 , 0xffffffff , 0x0 ) ;
F_8 ( V_4 -> V_15 , V_26 , 0xffffffff , 0x0 ) ;
F_8 ( V_4 -> V_15 , V_108 , V_109 ,
V_110 * 2 ) ;
F_8 ( V_4 -> V_15 , V_111 , V_109 ,
V_112 - 1 ) ;
F_36 ( V_31 , & V_4 -> V_113 ,
& V_4 -> V_114 ) ;
F_37 ( V_31 , V_4 ) ;
return 0 ;
}
static bool F_38 ( struct V_5 * V_6 , unsigned int V_115 )
{
switch ( V_115 ) {
case V_16 :
case V_108 :
case V_94 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_26 :
case V_111 :
case V_96 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
return true ;
default:
return false ;
}
}
static bool F_39 ( struct V_5 * V_6 , unsigned int V_115 )
{
switch ( V_115 ) {
case V_119 :
case V_125 :
case V_127 :
case V_124 :
return true ;
default:
return false ;
}
}
static bool F_40 ( struct V_5 * V_6 , unsigned int V_115 )
{
switch ( V_115 ) {
case V_16 :
case V_108 :
case V_94 :
case V_116 :
case V_117 :
case V_118 :
case V_127 :
case V_120 :
case V_26 :
case V_111 :
case V_96 :
case V_121 :
case V_122 :
case V_123 :
case V_126 :
return true ;
default:
return false ;
}
}
static int F_41 ( struct V_128 * V_7 )
{
struct V_129 * V_130 = V_7 -> V_6 . V_131 ;
struct V_3 * V_4 ;
struct V_132 * V_133 ;
void T_3 * V_134 ;
char V_135 [ 8 ] ;
int V_1 , V_49 , V_136 ;
V_4 = F_42 ( & V_7 -> V_6 , sizeof( * V_4 ) , V_137 ) ;
if ( ! V_4 )
return - V_138 ;
V_4 -> V_7 = V_7 ;
if ( F_43 ( V_7 -> V_6 . V_131 , L_16 ) )
V_4 -> V_139 = true ;
V_4 -> V_140 = F_44 ( V_130 , L_17 ) ;
if ( V_4 -> V_140 )
V_141 . V_142 = V_143 ;
V_4 -> V_54 = F_44 ( V_130 , L_18 ) ;
V_133 = F_45 ( V_7 , V_144 , 0 ) ;
V_134 = F_46 ( & V_7 -> V_6 , V_133 ) ;
if ( F_47 ( V_134 ) )
return F_48 ( V_134 ) ;
V_4 -> V_15 = F_49 ( & V_7 -> V_6 ,
L_19 , V_134 , & V_141 ) ;
if ( F_47 ( V_4 -> V_15 ) )
V_4 -> V_15 = F_49 ( & V_7 -> V_6 ,
L_20 , V_134 , & V_141 ) ;
if ( F_47 ( V_4 -> V_15 ) ) {
F_11 ( & V_7 -> V_6 , L_21 ) ;
return F_48 ( V_4 -> V_15 ) ;
}
V_4 -> V_106 = F_50 ( & V_7 -> V_6 , L_19 ) ;
if ( F_47 ( V_4 -> V_106 ) ) {
F_11 ( & V_7 -> V_6 , L_22 ,
F_48 ( V_4 -> V_106 ) ) ;
V_4 -> V_106 = NULL ;
}
for ( V_136 = 0 ; V_136 < V_145 ; V_136 ++ ) {
sprintf ( V_135 , L_23 , V_136 + 1 ) ;
V_4 -> V_146 [ V_136 ] = F_50 ( & V_7 -> V_6 , V_135 ) ;
if ( F_47 ( V_4 -> V_146 [ V_136 ] ) ) {
F_11 ( & V_7 -> V_6 , L_24 ,
V_136 + 1 , F_48 ( V_4 -> V_146 [ V_136 ] ) ) ;
V_4 -> V_146 [ V_136 ] = NULL ;
}
}
V_1 = F_51 ( V_7 , 0 ) ;
if ( V_1 < 0 ) {
F_11 ( & V_7 -> V_6 , L_25 , V_130 -> V_147 ) ;
return V_1 ;
}
V_49 = F_52 ( & V_7 -> V_6 , V_1 , F_1 , 0 , V_130 -> V_148 , V_4 ) ;
if ( V_49 ) {
F_11 ( & V_7 -> V_6 , L_26 , V_1 ) ;
return V_49 ;
}
V_4 -> V_114 . V_149 = V_133 -> V_150 + V_124 ;
V_4 -> V_113 . V_149 = V_133 -> V_150 + V_127 ;
V_4 -> V_114 . V_151 = V_112 ;
V_4 -> V_113 . V_151 = V_110 ;
F_53 ( V_7 , V_4 ) ;
V_49 = F_54 ( & V_7 -> V_6 , & V_152 ,
& V_153 , 1 ) ;
if ( V_49 )
return V_49 ;
if ( V_4 -> V_139 )
return F_55 ( V_7 ) ;
else
return F_56 ( & V_7 -> V_6 , NULL ,
V_154 ) ;
}
