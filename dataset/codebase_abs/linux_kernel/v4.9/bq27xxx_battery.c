static int F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_6 = F_2 ( V_1 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
F_3 ( & V_7 ) ;
F_4 (di, &bq27xxx_battery_devices, list) {
F_5 ( & V_5 -> V_8 ) ;
F_6 ( & V_5 -> V_8 , 0 ) ;
}
F_7 ( & V_7 ) ;
return V_6 ;
}
static inline int F_8 ( struct V_4 * V_5 , int V_9 ,
bool V_10 )
{
if ( ! V_5 || V_5 -> V_11 [ V_9 ] == V_12 )
return - V_13 ;
return V_5 -> V_14 . V_15 ( V_5 , V_5 -> V_11 [ V_9 ] , V_10 ) ;
}
static int F_9 ( struct V_4 * V_5 )
{
int V_16 ;
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 )
V_16 = F_8 ( V_5 , V_20 , true ) ;
else
V_16 = F_8 ( V_5 , V_20 , false ) ;
if ( V_16 < 0 )
F_10 ( V_5 -> V_21 , L_1 ) ;
return V_16 ;
}
static int F_11 ( struct V_4 * V_5 , T_1 V_22 )
{
int V_23 ;
V_23 = F_8 ( V_5 , V_22 , false ) ;
if ( V_23 < 0 ) {
F_10 ( V_5 -> V_21 , L_2 ,
V_22 , V_23 ) ;
return V_23 ;
}
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 )
V_23 *= V_24 / V_25 ;
else
V_23 *= 1000 ;
return V_23 ;
}
static inline int F_12 ( struct V_4 * V_5 )
{
int V_26 ;
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 ) {
V_26 = F_8 ( V_5 , V_27 , true ) ;
if ( V_26 >= 0 && ( V_26 & V_28 ) )
return - V_29 ;
}
return F_11 ( V_5 , V_30 ) ;
}
static inline int F_13 ( struct V_4 * V_5 )
{
return F_11 ( V_5 , V_31 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
int V_32 ;
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 )
V_32 = F_8 ( V_5 , V_33 , true ) ;
else
V_32 = F_8 ( V_5 , V_33 , false ) ;
if ( V_32 < 0 ) {
F_10 ( V_5 -> V_21 , L_3 ) ;
return V_32 ;
}
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 )
V_32 = ( V_32 << 8 ) * V_24 / V_25 ;
else
V_32 *= 1000 ;
return V_32 ;
}
static int F_15 ( struct V_4 * V_5 )
{
int V_34 ;
V_34 = F_8 ( V_5 , V_35 , false ) ;
if ( V_34 < 0 ) {
F_10 ( V_5 -> V_21 , L_4 ) ;
return V_34 ;
}
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 )
V_34 *= V_36 / V_25 ;
else
V_34 *= 1000 ;
return V_34 ;
}
static int F_16 ( struct V_4 * V_5 )
{
int V_37 ;
V_37 = F_8 ( V_5 , V_38 , false ) ;
if ( V_37 < 0 ) {
F_17 ( V_5 -> V_21 , L_5 ) ;
return V_37 ;
}
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 )
V_37 = 5 * V_37 / 2 ;
return V_37 ;
}
static int F_18 ( struct V_4 * V_5 )
{
int V_39 ;
V_39 = F_8 ( V_5 , V_40 , false ) ;
if ( V_39 < 0 )
F_17 ( V_5 -> V_21 , L_6 ) ;
return V_39 ;
}
static int F_19 ( struct V_4 * V_5 , T_1 V_22 )
{
int V_41 ;
V_41 = F_8 ( V_5 , V_22 , false ) ;
if ( V_41 < 0 ) {
F_10 ( V_5 -> V_21 , L_7 ,
V_22 , V_41 ) ;
return V_41 ;
}
if ( V_41 == 65535 )
return - V_29 ;
return V_41 * 60 ;
}
static int F_20 ( struct V_4 * V_5 )
{
int V_41 ;
V_41 = F_8 ( V_5 , V_42 , false ) ;
if ( V_41 < 0 ) {
F_17 ( V_5 -> V_21 , L_8 ,
V_42 , V_41 ) ;
return V_41 ;
}
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 )
return ( V_41 * V_36 ) / V_25 ;
else
return V_41 ;
}
static bool F_21 ( struct V_4 * V_5 , T_2 V_26 )
{
if ( V_5 -> V_17 == V_43 || V_5 -> V_17 == V_44 || V_5 -> V_17 == V_45 )
return V_26 & ( V_46 | V_47 ) ;
if ( V_5 -> V_17 == V_48 || V_5 -> V_17 == V_49 )
return V_26 & V_50 ;
return false ;
}
static bool F_22 ( struct V_4 * V_5 , T_2 V_26 )
{
if ( V_5 -> V_17 == V_48 || V_5 -> V_17 == V_49 )
return V_26 & V_51 ;
return false ;
}
static bool F_23 ( struct V_4 * V_5 , T_2 V_26 )
{
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 )
return V_26 & ( V_52 | V_53 ) ;
else
return V_26 & ( V_54 | V_55 ) ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_26 ;
bool V_56 = V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 ;
V_26 = F_8 ( V_5 , V_27 , V_56 ) ;
if ( V_26 < 0 ) {
F_17 ( V_5 -> V_21 , L_9 , V_26 ) ;
return V_26 ;
}
if ( F_25 ( F_21 ( V_5 , V_26 ) ) )
return V_57 ;
if ( F_25 ( F_22 ( V_5 , V_26 ) ) )
return V_58 ;
if ( F_25 ( F_23 ( V_5 , V_26 ) ) )
return V_59 ;
return V_60 ;
}
void F_26 ( struct V_4 * V_5 )
{
struct V_61 V_62 = { 0 , } ;
bool V_63 = V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 ;
bool V_56 = V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 ;
V_62 . V_26 = F_8 ( V_5 , V_27 , V_56 ) ;
if ( ( V_62 . V_26 & 0xff ) == 0xff )
V_62 . V_26 = - 1 ;
if ( V_62 . V_26 >= 0 ) {
V_62 . V_64 = F_16 ( V_5 ) ;
if ( V_63 && ( V_62 . V_26 & V_28 ) ) {
F_27 ( V_5 -> V_21 , L_10 ) ;
V_62 . V_65 = - V_29 ;
V_62 . V_66 = - V_29 ;
V_62 . V_67 = - V_29 ;
V_62 . V_68 = - V_29 ;
V_62 . V_69 = - V_29 ;
V_62 . V_70 = - V_29 ;
V_62 . V_71 = - V_29 ;
} else {
if ( V_5 -> V_11 [ V_72 ] != V_12 )
V_62 . V_67 = F_19 ( V_5 , V_72 ) ;
if ( V_5 -> V_11 [ V_73 ] != V_12 )
V_62 . V_68 = F_19 ( V_5 , V_73 ) ;
if ( V_5 -> V_11 [ V_74 ] != V_12 )
V_62 . V_69 = F_19 ( V_5 , V_74 ) ;
V_62 . V_70 = F_13 ( V_5 ) ;
V_62 . V_65 = F_9 ( V_5 ) ;
if ( V_5 -> V_11 [ V_35 ] != V_12 )
V_62 . V_66 = F_15 ( V_5 ) ;
V_62 . V_71 = F_24 ( V_5 ) ;
}
if ( V_5 -> V_11 [ V_40 ] != V_12 )
V_62 . V_75 = F_18 ( V_5 ) ;
if ( V_5 -> V_11 [ V_42 ] != V_12 )
V_62 . V_76 = F_20 ( V_5 ) ;
if ( V_5 -> V_77 <= 0 )
V_5 -> V_77 = F_14 ( V_5 ) ;
}
if ( V_5 -> V_62 . V_65 != V_62 . V_65 )
F_28 ( V_5 -> V_78 ) ;
if ( memcmp ( & V_5 -> V_62 , & V_62 , sizeof( V_62 ) ) != 0 )
V_5 -> V_62 = V_62 ;
V_5 -> V_79 = V_80 ;
}
static void F_29 ( struct V_81 * V_8 )
{
struct V_4 * V_5 =
F_30 ( V_8 , struct V_4 ,
V_8 . V_8 ) ;
F_26 ( V_5 ) ;
if ( V_82 > 0 )
F_6 ( & V_5 -> V_8 , V_82 * V_83 ) ;
}
static int F_31 ( struct V_4 * V_5 ,
union V_84 * V_1 )
{
int V_85 ;
int V_26 ;
V_85 = F_8 ( V_5 , V_86 , false ) ;
if ( V_85 < 0 ) {
F_17 ( V_5 -> V_21 , L_11 ) ;
return V_85 ;
}
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 ) {
V_26 = F_8 ( V_5 , V_27 , true ) ;
if ( V_26 & V_87 ) {
F_10 ( V_5 -> V_21 , L_12 ) ;
V_85 = - V_85 ;
}
V_1 -> V_88 = V_85 * V_24 / V_25 ;
} else {
V_1 -> V_88 = ( int ) ( ( V_89 ) V_85 ) * 1000 ;
}
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
union V_84 * V_1 )
{
int V_90 ;
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 ) {
if ( V_5 -> V_62 . V_26 & V_91 )
V_90 = V_92 ;
else if ( V_5 -> V_62 . V_26 & V_87 )
V_90 = V_93 ;
else if ( F_33 ( V_5 -> V_78 ) )
V_90 = V_94 ;
else
V_90 = V_95 ;
} else {
if ( V_5 -> V_62 . V_26 & V_96 )
V_90 = V_92 ;
else if ( V_5 -> V_62 . V_26 & V_97 )
V_90 = V_95 ;
else
V_90 = V_93 ;
}
V_1 -> V_88 = V_90 ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 ,
union V_84 * V_1 )
{
int V_98 ;
if ( V_5 -> V_17 == V_18 || V_5 -> V_17 == V_19 ) {
if ( V_5 -> V_62 . V_26 & V_91 )
V_98 = V_99 ;
else if ( V_5 -> V_62 . V_26 & V_52 )
V_98 = V_100 ;
else if ( V_5 -> V_62 . V_26 & V_53 )
V_98 = V_101 ;
else
V_98 = V_102 ;
} else {
if ( V_5 -> V_62 . V_26 & V_96 )
V_98 = V_99 ;
else if ( V_5 -> V_62 . V_26 & V_54 )
V_98 = V_100 ;
else if ( V_5 -> V_62 . V_26 & V_55 )
V_98 = V_101 ;
else
V_98 = V_102 ;
}
V_1 -> V_88 = V_98 ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 ,
union V_84 * V_1 )
{
int V_103 ;
V_103 = F_8 ( V_5 , V_104 , false ) ;
if ( V_103 < 0 ) {
F_17 ( V_5 -> V_21 , L_13 ) ;
return V_103 ;
}
V_1 -> V_88 = V_103 * 1000 ;
return 0 ;
}
static int F_36 ( int V_105 ,
union V_84 * V_1 )
{
if ( V_105 < 0 )
return V_105 ;
V_1 -> V_88 = V_105 ;
return 0 ;
}
static int F_37 ( struct V_106 * V_107 ,
enum V_108 V_109 ,
union V_84 * V_1 )
{
int V_6 = 0 ;
struct V_4 * V_5 = F_38 ( V_107 ) ;
F_3 ( & V_5 -> V_110 ) ;
if ( F_39 ( V_5 -> V_79 + 5 * V_83 ) ) {
F_5 ( & V_5 -> V_8 ) ;
F_29 ( & V_5 -> V_8 . V_8 ) ;
}
F_7 ( & V_5 -> V_110 ) ;
if ( V_109 != V_111 && V_5 -> V_62 . V_26 < 0 )
return - V_112 ;
switch ( V_109 ) {
case V_113 :
V_6 = F_32 ( V_5 , V_1 ) ;
break;
case V_114 :
V_6 = F_35 ( V_5 , V_1 ) ;
break;
case V_111 :
V_1 -> V_88 = V_5 -> V_62 . V_26 < 0 ? 0 : 1 ;
break;
case V_115 :
V_6 = F_31 ( V_5 , V_1 ) ;
break;
case V_116 :
V_6 = F_36 ( V_5 -> V_62 . V_65 , V_1 ) ;
break;
case V_117 :
V_6 = F_34 ( V_5 , V_1 ) ;
break;
case V_118 :
V_6 = F_36 ( V_5 -> V_62 . V_64 , V_1 ) ;
if ( V_6 == 0 )
V_1 -> V_88 -= 2731 ;
break;
case V_119 :
V_6 = F_36 ( V_5 -> V_62 . V_67 , V_1 ) ;
break;
case V_120 :
V_6 = F_36 ( V_5 -> V_62 . V_68 , V_1 ) ;
break;
case V_121 :
V_6 = F_36 ( V_5 -> V_62 . V_69 , V_1 ) ;
break;
case V_122 :
V_1 -> V_88 = V_123 ;
break;
case V_124 :
V_6 = F_36 ( F_12 ( V_5 ) , V_1 ) ;
break;
case V_125 :
V_6 = F_36 ( V_5 -> V_62 . V_70 , V_1 ) ;
break;
case V_126 :
V_6 = F_36 ( V_5 -> V_77 , V_1 ) ;
break;
case V_127 :
V_6 = F_36 ( V_5 -> V_62 . V_75 , V_1 ) ;
break;
case V_128 :
V_6 = F_36 ( V_5 -> V_62 . V_66 , V_1 ) ;
break;
case V_129 :
V_6 = F_36 ( V_5 -> V_62 . V_76 , V_1 ) ;
break;
case V_130 :
V_6 = F_36 ( V_5 -> V_62 . V_71 , V_1 ) ;
break;
case V_131 :
V_1 -> V_132 = V_133 ;
break;
default:
return - V_13 ;
}
return V_6 ;
}
static void F_40 ( struct V_106 * V_107 )
{
struct V_4 * V_5 = F_38 ( V_107 ) ;
F_5 ( & V_5 -> V_8 ) ;
F_6 ( & V_5 -> V_8 , 0 ) ;
}
int F_41 ( struct V_4 * V_5 )
{
struct V_134 * V_135 ;
struct V_136 V_137 = { . V_138 = V_5 , } ;
F_42 ( & V_5 -> V_8 , F_29 ) ;
F_43 ( & V_5 -> V_110 ) ;
V_5 -> V_11 = V_139 [ V_5 -> V_17 ] ;
V_135 = F_44 ( V_5 -> V_21 , sizeof( * V_135 ) , V_140 ) ;
if ( ! V_135 )
return - V_141 ;
V_135 -> V_142 = V_5 -> V_142 ;
V_135 -> type = V_143 ;
V_135 -> V_144 = V_145 [ V_5 -> V_17 ] . V_146 ;
V_135 -> V_147 = V_145 [ V_5 -> V_17 ] . V_148 ;
V_135 -> V_149 = F_37 ;
V_135 -> V_150 = F_40 ;
V_5 -> V_78 = F_45 ( V_5 -> V_21 , V_135 , & V_137 ) ;
if ( F_46 ( V_5 -> V_78 ) ) {
F_17 ( V_5 -> V_21 , L_14 ) ;
return F_47 ( V_5 -> V_78 ) ;
}
F_48 ( V_5 -> V_21 , L_15 , V_151 ) ;
F_26 ( V_5 ) ;
F_3 ( & V_7 ) ;
F_49 ( & V_5 -> V_152 , & V_153 ) ;
F_7 ( & V_7 ) ;
return 0 ;
}
void F_50 ( struct V_4 * V_5 )
{
V_82 = 0 ;
F_5 ( & V_5 -> V_8 ) ;
F_51 ( V_5 -> V_78 ) ;
F_3 ( & V_7 ) ;
F_52 ( & V_5 -> V_152 ) ;
F_7 ( & V_7 ) ;
F_53 ( & V_5 -> V_110 ) ;
}
static int F_54 ( struct V_4 * V_5 , T_1 V_22 ,
bool V_10 )
{
struct V_154 * V_21 = V_5 -> V_21 ;
struct V_155 * V_156 = V_21 -> V_157 ;
unsigned int V_158 = 3 ;
int V_159 , V_160 ;
int V_37 ;
if ( ! V_10 ) {
V_159 = V_156 -> V_15 ( V_21 , V_22 + 1 ) ;
do {
V_37 = V_159 ;
if ( V_159 < 0 )
return V_159 ;
V_160 = V_156 -> V_15 ( V_21 , V_22 ) ;
if ( V_160 < 0 )
return V_160 ;
V_159 = V_156 -> V_15 ( V_21 , V_22 + 1 ) ;
} while ( V_37 != V_159 && -- V_158 );
if ( V_158 == 0 )
return - V_161 ;
return ( V_159 << 8 ) | V_160 ;
}
return V_156 -> V_15 ( V_21 , V_22 ) ;
}
static int F_55 ( struct V_162 * V_163 )
{
struct V_4 * V_5 ;
struct V_155 * V_156 = V_163 -> V_21 . V_157 ;
if ( ! V_156 ) {
F_17 ( & V_163 -> V_21 , L_16 ) ;
return - V_13 ;
}
if ( ! V_156 -> V_15 ) {
F_17 ( & V_163 -> V_21 , L_17 ) ;
return - V_13 ;
}
if ( ! V_156 -> V_17 ) {
F_17 ( & V_163 -> V_21 , L_18 ) ;
return - V_13 ;
}
V_5 = F_44 ( & V_163 -> V_21 , sizeof( * V_5 ) , V_140 ) ;
if ( ! V_5 )
return - V_141 ;
F_56 ( V_163 , V_5 ) ;
V_5 -> V_21 = & V_163 -> V_21 ;
V_5 -> V_17 = V_156 -> V_17 ;
V_5 -> V_142 = V_156 -> V_142 ? : F_57 ( & V_163 -> V_21 ) ;
V_5 -> V_14 . V_15 = F_54 ;
return F_41 ( V_5 ) ;
}
static int F_58 ( struct V_162 * V_163 )
{
struct V_4 * V_5 = F_59 ( V_163 ) ;
F_50 ( V_5 ) ;
return 0 ;
}
