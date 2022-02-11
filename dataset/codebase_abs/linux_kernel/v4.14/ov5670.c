static int F_1 ( struct V_1 * V_1 , T_1 V_2 , unsigned int V_3 ,
T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
struct V_8 V_9 [ 2 ] ;
T_3 * V_10 ;
T_2 V_11 = 0 ;
T_1 V_12 = F_3 ( V_2 ) ;
int V_13 ;
if ( V_3 > 4 )
return - V_14 ;
V_10 = ( T_3 * ) & V_11 ;
V_9 [ 0 ] . V_15 = V_6 -> V_15 ;
V_9 [ 0 ] . V_16 = 0 ;
V_9 [ 0 ] . V_3 = 2 ;
V_9 [ 0 ] . V_17 = ( T_3 * ) & V_12 ;
V_9 [ 1 ] . V_15 = V_6 -> V_15 ;
V_9 [ 1 ] . V_16 = V_18 ;
V_9 [ 1 ] . V_3 = V_3 ;
V_9 [ 1 ] . V_17 = & V_10 [ 4 - V_3 ] ;
V_13 = F_4 ( V_6 -> V_19 , V_9 , F_5 ( V_9 ) ) ;
if ( V_13 != F_5 ( V_9 ) )
return - V_20 ;
* V_4 = F_6 ( V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , T_1 V_2 , unsigned int V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
int V_21 ;
int V_22 ;
T_3 V_17 [ 6 ] ;
T_3 * V_23 ;
if ( V_3 > 4 )
return - V_14 ;
V_17 [ 0 ] = V_2 >> 8 ;
V_17 [ 1 ] = V_2 & 0xff ;
V_4 = F_8 ( V_4 ) ;
V_23 = ( T_3 * ) & V_4 ;
V_21 = 2 ;
V_22 = 4 - V_3 ;
while ( V_22 < 4 )
V_17 [ V_21 ++ ] = V_23 [ V_22 ++ ] ;
if ( F_9 ( V_6 , V_17 , V_3 + 2 ) != V_3 + 2 )
return - V_20 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 ,
const struct V_24 * V_25 , unsigned int V_3 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
unsigned int V_26 ;
int V_13 ;
for ( V_26 = 0 ; V_26 < V_3 ; V_26 ++ ) {
V_13 = F_7 ( V_1 , V_25 [ V_26 ] . V_27 , 1 , V_25 [ V_26 ] . V_4 ) ;
if ( V_13 ) {
F_11 (
& V_6 -> V_28 ,
L_1 ,
V_25 [ V_26 ] . V_27 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 ,
const struct V_29 * V_30 )
{
return F_10 ( V_1 , V_30 -> V_25 , V_30 -> V_31 ) ;
}
static int F_13 ( struct V_32 * V_7 , struct V_33 * V_34 )
{
struct V_1 * V_1 = F_14 ( V_7 ) ;
struct V_35 * V_36 =
F_15 ( V_7 , V_34 -> V_37 , 0 ) ;
F_16 ( & V_1 -> V_38 ) ;
V_36 -> V_39 = V_1 -> V_40 -> V_39 ;
V_36 -> V_41 = V_1 -> V_40 -> V_41 ;
V_36 -> V_42 = V_43 ;
V_36 -> V_44 = V_45 ;
F_17 ( & V_1 -> V_38 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 , T_2 V_46 )
{
int V_13 ;
V_13 = F_7 ( V_1 , V_47 ,
V_48 , V_46 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_7 ( V_1 , V_49 ,
V_48 , V_46 ) ;
if ( V_13 )
return V_13 ;
return F_7 ( V_1 , V_50 ,
V_48 , V_46 ) ;
}
static int F_19 ( struct V_1 * V_1 , T_2 V_51 )
{
T_2 V_4 ;
int V_13 ;
V_13 = F_7 ( V_1 , V_52 ,
V_53 , 0 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_1 ( V_1 , V_54 ,
V_53 , & V_4 ) ;
if ( V_13 )
return V_13 ;
if ( V_51 )
V_4 |= V_55 ;
else
V_4 &= ~ V_55 ;
return F_7 ( V_1 , V_54 ,
V_53 , V_4 ) ;
}
static int F_20 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = F_21 ( V_57 -> V_58 ,
struct V_1 , V_59 ) ;
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
T_4 V_60 ;
int V_13 = 0 ;
switch ( V_57 -> V_61 ) {
case V_62 :
V_60 = V_1 -> V_40 -> V_41 + V_57 -> V_4 - 8 ;
F_22 ( V_1 -> V_63 ,
V_1 -> V_63 -> V_64 , V_60 ,
V_1 -> V_63 -> V_65 , V_60 ) ;
break;
}
if ( F_23 ( & V_6 -> V_28 ) <= 0 )
return 0 ;
switch ( V_57 -> V_61 ) {
case V_66 :
V_13 = F_7 ( V_1 , V_67 ,
V_48 , V_57 -> V_4 ) ;
break;
case V_68 :
V_13 = F_18 ( V_1 , V_57 -> V_4 ) ;
break;
case V_69 :
V_13 = F_7 ( V_1 , V_70 ,
V_71 , V_57 -> V_4 << 4 ) ;
break;
case V_62 :
V_13 = F_7 ( V_1 , V_72 ,
V_48 ,
V_1 -> V_40 -> V_41 + V_57 -> V_4 ) ;
break;
case V_73 :
V_13 = F_19 ( V_1 , V_57 -> V_4 ) ;
break;
default:
F_24 ( & V_6 -> V_28 , L_2 ,
V_74 , V_57 -> V_61 , V_57 -> V_4 ) ;
break;
}
F_25 ( & V_6 -> V_28 ) ;
return V_13 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_75 * V_76 ;
T_4 V_77 ;
T_4 V_78 ;
T_4 V_79 ;
T_4 V_80 ;
int V_13 ;
V_76 = & V_1 -> V_59 ;
V_13 = F_27 ( V_76 , 8 ) ;
if ( V_13 )
return V_13 ;
V_76 -> V_81 = & V_1 -> V_38 ;
V_1 -> V_82 = F_28 ( V_76 ,
& V_83 ,
V_84 ,
0 , 0 , V_85 ) ;
if ( V_1 -> V_82 )
V_1 -> V_82 -> V_16 |= V_86 ;
V_1 -> V_87 = F_29 ( V_76 , & V_83 ,
V_88 , 0 ,
V_89 [ 0 ] . V_87 ,
1 ,
V_89 [ 0 ] . V_87 ) ;
V_77 = V_90 - V_1 -> V_40 -> V_41 ;
V_78 = V_1 -> V_40 -> V_91 - V_1 -> V_40 -> V_41 ;
V_79 = V_1 -> V_40 -> V_92 - V_1 -> V_40 -> V_41 ;
V_1 -> V_93 = F_29 ( V_76 , & V_83 ,
V_62 , V_79 ,
V_77 , 1 , V_78 ) ;
V_1 -> V_94 = F_29 (
V_76 , & V_83 , V_95 ,
V_96 - V_1 -> V_40 -> V_39 ,
V_96 - V_1 -> V_40 -> V_39 , 1 ,
V_96 - V_1 -> V_40 -> V_39 ) ;
if ( V_1 -> V_94 )
V_1 -> V_94 -> V_16 |= V_86 ;
F_29 ( V_76 , & V_83 , V_66 ,
V_97 , V_98 , V_99 ,
V_100 ) ;
F_29 ( V_76 , & V_83 , V_68 ,
V_101 , V_102 ,
V_103 , V_104 ) ;
V_80 = V_1 -> V_40 -> V_91 - 8 ;
V_1 -> V_63 = F_29 ( V_76 , & V_83 ,
V_69 ,
V_105 ,
V_80 , V_106 ,
V_80 ) ;
F_30 ( V_76 , & V_83 ,
V_73 ,
F_5 ( V_107 ) - 1 ,
0 , 0 , V_107 ) ;
if ( V_76 -> error ) {
V_13 = V_76 -> error ;
goto error;
}
V_1 -> V_7 . V_59 = V_76 ;
return 0 ;
error:
F_31 ( V_76 ) ;
return V_13 ;
}
static int F_32 ( struct V_32 * V_7 ,
struct V_108 * V_109 ,
struct V_110 * V_42 )
{
if ( V_42 -> V_111 > 0 )
return - V_14 ;
V_42 -> V_42 = V_43 ;
return 0 ;
}
static int F_33 ( struct V_32 * V_7 ,
struct V_108 * V_109 ,
struct V_112 * V_113 )
{
if ( V_113 -> V_111 >= F_5 ( V_114 ) )
return - V_14 ;
if ( V_113 -> V_42 != V_43 )
return - V_14 ;
V_113 -> V_115 = V_114 [ V_113 -> V_111 ] . V_39 ;
V_113 -> V_116 = V_113 -> V_115 ;
V_113 -> V_117 = V_114 [ V_113 -> V_111 ] . V_41 ;
V_113 -> V_118 = V_113 -> V_117 ;
return 0 ;
}
static int F_34 ( const struct V_119 * V_120 ,
struct V_35 * V_121 )
{
return abs ( V_120 -> V_39 - V_121 -> V_39 ) +
abs ( V_120 -> V_41 - V_121 -> V_41 ) ;
}
static const struct V_119 * F_35 (
struct V_1 * V_1 ,
struct V_122 * V_123 )
{
struct V_35 * V_121 = & V_123 -> V_124 ;
int V_125 ;
int V_126 = 0 ;
int V_127 = - 1 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < F_5 ( V_114 ) ; V_26 ++ ) {
V_125 = F_34 ( & V_114 [ V_26 ] , V_121 ) ;
if ( V_127 == - 1 || V_125 < V_127 ) {
V_127 = V_125 ;
V_126 = V_26 ;
}
}
return & V_114 [ V_126 ] ;
}
static void F_36 ( const struct V_119 * V_120 ,
struct V_122 * V_123 )
{
V_123 -> V_124 . V_39 = V_120 -> V_39 ;
V_123 -> V_124 . V_41 = V_120 -> V_41 ;
V_123 -> V_124 . V_42 = V_43 ;
V_123 -> V_124 . V_44 = V_45 ;
}
static int F_37 ( struct V_1 * V_1 ,
struct V_108 * V_109 ,
struct V_122 * V_123 )
{
if ( V_123 -> V_128 == V_129 )
V_123 -> V_124 = * F_15 ( & V_1 -> V_7 , V_109 ,
V_123 -> V_37 ) ;
else
F_36 ( V_1 -> V_40 , V_123 ) ;
return 0 ;
}
static int F_38 ( struct V_32 * V_7 ,
struct V_108 * V_109 ,
struct V_122 * V_123 )
{
struct V_1 * V_1 = F_14 ( V_7 ) ;
int V_13 ;
F_16 ( & V_1 -> V_38 ) ;
V_13 = F_37 ( V_1 , V_109 , V_123 ) ;
F_17 ( & V_1 -> V_38 ) ;
return V_13 ;
}
static int F_39 ( struct V_32 * V_7 ,
struct V_108 * V_109 ,
struct V_122 * V_123 )
{
struct V_1 * V_1 = F_14 ( V_7 ) ;
const struct V_119 * V_120 ;
T_5 V_78 ;
T_5 V_130 ;
F_16 ( & V_1 -> V_38 ) ;
V_123 -> V_124 . V_42 = V_43 ;
V_120 = F_35 ( V_1 , V_123 ) ;
F_36 ( V_120 , V_123 ) ;
if ( V_123 -> V_128 == V_129 ) {
* F_15 ( V_7 , V_109 , V_123 -> V_37 ) = V_123 -> V_124 ;
} else {
V_1 -> V_40 = V_120 ;
F_40 ( V_1 -> V_82 , V_120 -> V_131 ) ;
F_41 (
V_1 -> V_87 ,
V_89 [ V_120 -> V_131 ] . V_87 ) ;
V_78 = V_1 -> V_40 -> V_91 -
V_1 -> V_40 -> V_41 ;
F_22 (
V_1 -> V_93 ,
V_1 -> V_40 -> V_92 - V_1 -> V_40 -> V_41 ,
V_90 - V_1 -> V_40 -> V_41 , 1 ,
V_78 ) ;
F_40 ( V_1 -> V_93 , V_78 ) ;
V_130 = V_96 - V_1 -> V_40 -> V_39 ;
F_22 ( V_1 -> V_94 , V_130 , V_130 , 1 ,
V_130 ) ;
}
F_17 ( & V_1 -> V_38 ) ;
return 0 ;
}
static int F_42 ( struct V_32 * V_7 , T_2 * V_132 )
{
* V_132 = V_133 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
const struct V_29 * V_134 ;
int V_131 ;
int V_13 ;
V_13 = F_7 ( V_1 , V_135 ,
V_53 , V_136 ) ;
if ( V_13 ) {
F_44 ( & V_6 -> V_28 , L_3 ,
V_74 ) ;
return V_13 ;
}
V_131 = V_1 -> V_40 -> V_131 ;
V_134 = & V_89 [ V_131 ] . V_134 ;
V_13 = F_12 ( V_1 , V_134 ) ;
if ( V_13 ) {
F_44 ( & V_6 -> V_28 , L_4 , V_74 ) ;
return V_13 ;
}
V_134 = & V_1 -> V_40 -> V_134 ;
V_13 = F_12 ( V_1 , V_134 ) ;
if ( V_13 ) {
F_44 ( & V_6 -> V_28 , L_5 , V_74 ) ;
return V_13 ;
}
V_13 = F_45 ( V_1 -> V_7 . V_59 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_7 ( V_1 , V_137 ,
V_53 , V_138 ) ;
if ( V_13 ) {
F_44 ( & V_6 -> V_28 , L_6 , V_74 ) ;
return V_13 ;
}
V_1 -> V_139 = true ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
int V_13 ;
V_13 = F_7 ( V_1 , V_137 ,
V_53 , V_140 ) ;
if ( V_13 )
F_44 ( & V_6 -> V_28 , L_6 , V_74 ) ;
V_1 -> V_139 = false ;
return 0 ;
}
static int F_47 ( struct V_32 * V_7 , int V_141 )
{
struct V_1 * V_1 = F_14 ( V_7 ) ;
struct V_5 * V_6 = F_2 ( V_7 ) ;
int V_13 = 0 ;
F_16 ( & V_1 -> V_38 ) ;
if ( V_1 -> V_139 == V_141 )
goto V_142;
if ( V_141 ) {
V_13 = F_48 ( & V_6 -> V_28 ) ;
if ( V_13 < 0 ) {
F_49 ( & V_6 -> V_28 ) ;
goto V_142;
}
V_13 = F_43 ( V_1 ) ;
if ( V_13 )
goto error;
} else {
V_13 = F_46 ( V_1 ) ;
F_25 ( & V_6 -> V_28 ) ;
}
goto V_142;
error:
F_25 ( & V_6 -> V_28 ) ;
V_142:
F_17 ( & V_1 -> V_38 ) ;
return V_13 ;
}
static int T_6 F_50 ( struct V_143 * V_28 )
{
struct V_5 * V_6 = F_51 ( V_28 ) ;
struct V_32 * V_7 = F_52 ( V_6 ) ;
struct V_1 * V_1 = F_14 ( V_7 ) ;
if ( V_1 -> V_139 )
F_46 ( V_1 ) ;
return 0 ;
}
static int T_6 F_53 ( struct V_143 * V_28 )
{
struct V_5 * V_6 = F_51 ( V_28 ) ;
struct V_32 * V_7 = F_52 ( V_6 ) ;
struct V_1 * V_1 = F_14 ( V_7 ) ;
int V_13 ;
if ( V_1 -> V_139 ) {
V_13 = F_43 ( V_1 ) ;
if ( V_13 ) {
F_46 ( V_1 ) ;
return V_13 ;
}
}
return 0 ;
}
static int F_54 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( & V_1 -> V_7 ) ;
int V_13 ;
T_2 V_4 ;
V_13 = F_1 ( V_1 , V_144 ,
V_71 , & V_4 ) ;
if ( V_13 )
return V_13 ;
if ( V_4 != V_145 ) {
F_44 ( & V_6 -> V_28 , L_7 ,
V_145 , V_4 ) ;
return - V_146 ;
}
return 0 ;
}
static int F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_1 ;
const char * V_147 ;
T_2 V_148 = 0 ;
int V_13 ;
F_56 ( & V_6 -> V_28 , L_8 , & V_148 ) ;
if ( V_148 != 19200000 )
return - V_14 ;
V_1 = F_57 ( & V_6 -> V_28 , sizeof( * V_1 ) , V_149 ) ;
if ( ! V_1 ) {
V_13 = - V_150 ;
V_147 = L_9 ;
goto V_151;
}
F_58 ( & V_1 -> V_7 , V_6 , & V_152 ) ;
V_13 = F_54 ( V_1 ) ;
if ( V_13 ) {
V_147 = L_10 ;
goto V_151;
}
F_59 ( & V_1 -> V_38 ) ;
V_1 -> V_40 = & V_114 [ 0 ] ;
V_13 = F_26 ( V_1 ) ;
if ( V_13 ) {
V_147 = L_11 ;
goto V_153;
}
V_1 -> V_7 . V_154 = & V_155 ;
V_1 -> V_7 . V_16 |= V_156 ;
V_1 -> V_7 . V_157 . V_158 = & V_159 ;
V_1 -> V_7 . V_157 . V_160 = V_161 ;
V_1 -> V_37 . V_16 = V_162 ;
V_13 = F_60 ( & V_1 -> V_7 . V_157 , 1 , & V_1 -> V_37 ) ;
if ( V_13 ) {
V_147 = L_12 ;
goto V_163;
}
V_13 = F_61 ( & V_1 -> V_7 ) ;
if ( V_13 < 0 ) {
V_147 = L_13 ;
goto V_164;
}
V_1 -> V_139 = false ;
F_62 ( & V_6 -> V_28 ) ;
F_63 ( & V_6 -> V_28 ) ;
F_64 ( & V_6 -> V_28 ) ;
F_25 ( & V_6 -> V_28 ) ;
return 0 ;
V_164:
F_65 ( & V_1 -> V_7 . V_157 ) ;
V_163:
F_31 ( V_1 -> V_7 . V_59 ) ;
V_153:
F_66 ( & V_1 -> V_38 ) ;
V_151:
F_44 ( & V_6 -> V_28 , L_14 , V_74 , V_147 , V_13 ) ;
return V_13 ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_32 * V_7 = F_52 ( V_6 ) ;
struct V_1 * V_1 = F_14 ( V_7 ) ;
F_68 ( V_7 ) ;
F_65 ( & V_7 -> V_157 ) ;
F_31 ( V_7 -> V_59 ) ;
F_66 ( & V_1 -> V_38 ) ;
F_48 ( & V_6 -> V_28 ) ;
F_69 ( & V_6 -> V_28 ) ;
F_70 ( & V_6 -> V_28 ) ;
F_49 ( & V_6 -> V_28 ) ;
return 0 ;
}
