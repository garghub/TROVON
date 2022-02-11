static inline T_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_4 -> V_6 &&
V_2 -> V_7 == V_4 -> V_8 / V_9 )
return ( T_1 * ) ( V_2 -> V_10 + V_4 -> V_8 % V_9 ) ;
return NULL ;
}
static int F_2 ( const char * V_11 , const struct V_12 * V_13 )
{
struct V_14 * V_15 ;
unsigned int V_16 = * ( unsigned int * ) V_13 -> V_17 ;
int V_18 ;
V_18 = F_3 ( V_11 , V_13 ) ;
if ( V_18 < 0 || V_16 == * ( unsigned int * ) V_13 -> V_17 )
return V_18 ;
F_4 ( & V_19 ) ;
F_5 (di, &bq27xxx_battery_devices, list) {
F_6 ( & V_15 -> V_20 ) ;
F_7 ( & V_15 -> V_20 , 0 ) ;
}
F_8 ( & V_19 ) ;
return V_18 ;
}
static inline int F_9 ( struct V_14 * V_15 , int V_21 ,
bool V_22 )
{
int V_18 ;
if ( ! V_15 || V_15 -> V_23 [ V_21 ] == V_24 )
return - V_25 ;
V_18 = V_15 -> V_26 . V_27 ( V_15 , V_15 -> V_23 [ V_21 ] , V_22 ) ;
if ( V_18 < 0 )
F_10 ( V_15 -> V_28 , L_1 ,
V_15 -> V_23 [ V_21 ] , V_21 ) ;
return V_18 ;
}
static inline int F_11 ( struct V_14 * V_15 , int V_21 ,
T_1 V_29 , bool V_22 )
{
int V_18 ;
if ( ! V_15 || V_15 -> V_23 [ V_21 ] == V_24 )
return - V_25 ;
if ( ! V_15 -> V_26 . V_30 )
return - V_31 ;
V_18 = V_15 -> V_26 . V_30 ( V_15 , V_15 -> V_23 [ V_21 ] , V_29 , V_22 ) ;
if ( V_18 < 0 )
F_10 ( V_15 -> V_28 , L_2 ,
V_15 -> V_23 [ V_21 ] , V_21 ) ;
return V_18 ;
}
static inline int F_12 ( struct V_14 * V_15 , int V_21 ,
T_2 * V_10 , int V_32 )
{
int V_18 ;
if ( ! V_15 || V_15 -> V_23 [ V_21 ] == V_24 )
return - V_25 ;
if ( ! V_15 -> V_26 . V_33 )
return - V_31 ;
V_18 = V_15 -> V_26 . V_33 ( V_15 , V_15 -> V_23 [ V_21 ] , V_10 , V_32 ) ;
if ( V_18 < 0 )
F_10 ( V_15 -> V_28 , L_3 ,
V_15 -> V_23 [ V_21 ] , V_21 ) ;
return V_18 ;
}
static inline int F_13 ( struct V_14 * V_15 , int V_21 ,
T_2 * V_10 , int V_32 )
{
int V_18 ;
if ( ! V_15 || V_15 -> V_23 [ V_21 ] == V_24 )
return - V_25 ;
if ( ! V_15 -> V_26 . V_34 )
return - V_31 ;
V_18 = V_15 -> V_26 . V_34 ( V_15 , V_15 -> V_23 [ V_21 ] , V_10 , V_32 ) ;
if ( V_18 < 0 )
F_10 ( V_15 -> V_28 , L_4 ,
V_15 -> V_23 [ V_21 ] , V_21 ) ;
return V_18 ;
}
static int F_14 ( struct V_14 * V_15 )
{
int V_18 ;
V_18 = F_11 ( V_15 , V_35 , V_36 , false ) ;
if ( V_18 < 0 ) {
F_15 ( V_15 -> V_28 , L_5 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_16 ( struct V_14 * V_15 )
{
int V_18 ;
if ( V_15 -> V_37 == 0 ) {
F_15 ( V_15 -> V_28 , L_6 ) ;
return - V_25 ;
}
V_18 = F_11 ( V_15 , V_35 , ( T_1 ) ( V_15 -> V_37 >> 16 ) , false ) ;
if ( V_18 < 0 )
goto V_38;
V_18 = F_11 ( V_15 , V_35 , ( T_1 ) V_15 -> V_37 , false ) ;
if ( V_18 < 0 )
goto V_38;
return 0 ;
V_38:
F_15 ( V_15 -> V_28 , L_7 , V_18 ) ;
return V_18 ;
}
static T_2 F_17 ( struct V_1 * V_2 )
{
T_1 V_39 = 0 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_9 ; V_40 ++ )
V_39 += V_2 -> V_10 [ V_40 ] ;
V_39 &= 0xff ;
return 0xff - V_39 ;
}
static int F_18 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
int V_18 ;
V_2 -> V_41 = false ;
V_18 = F_11 ( V_15 , V_42 , V_2 -> V_5 , true ) ;
if ( V_18 < 0 )
goto V_38;
V_18 = F_11 ( V_15 , V_43 , V_2 -> V_7 , true ) ;
if ( V_18 < 0 )
goto V_38;
F_19 ( 1 ) ;
V_18 = F_12 ( V_15 , V_44 , V_2 -> V_10 , V_9 ) ;
if ( V_18 < 0 )
goto V_38;
V_18 = F_9 ( V_15 , V_45 , true ) ;
if ( V_18 < 0 )
goto V_38;
if ( ( T_2 ) V_18 != F_17 ( V_2 ) ) {
V_18 = - V_25 ;
goto V_38;
}
V_2 -> V_41 = true ;
V_2 -> V_46 = false ;
return 0 ;
V_38:
F_15 ( V_15 -> V_28 , L_8 , V_18 ) ;
return V_18 ;
}
static int F_20 ( struct V_14 * V_15 , bool V_47 )
{
const int V_48 = 100 ;
T_1 V_49 = V_47 ? V_50 : V_51 ;
int V_18 , V_52 = V_48 ;
V_18 = F_11 ( V_15 , V_35 , V_49 , false ) ;
if ( V_18 < 0 )
return V_18 ;
do {
F_19 ( 25 ) ;
V_18 = F_9 ( V_15 , V_53 , false ) ;
if ( V_18 < 0 )
return V_18 ;
} while ( ! ! ( V_18 & V_54 ) != V_47 && -- V_52 );
if ( ! V_52 ) {
F_15 ( V_15 -> V_28 , L_9 , V_47 ) ;
return - V_25 ;
}
if ( V_48 - V_52 > 3 )
F_21 ( V_15 -> V_28 , L_10 , V_47 , V_48 - V_52 ) ;
return 0 ;
}
static inline int F_22 ( struct V_14 * V_15 )
{
int V_18 = F_20 ( V_15 , true ) ;
if ( V_18 < 0 && V_18 != - V_25 )
F_15 ( V_15 -> V_28 , L_11 , V_18 ) ;
return V_18 ;
}
static inline int F_23 ( struct V_14 * V_15 )
{
int V_18 = F_20 ( V_15 , false ) ;
if ( V_18 < 0 && V_18 != - V_25 )
F_15 ( V_15 -> V_28 , L_12 , V_18 ) ;
return V_18 ;
}
static int F_24 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
bool V_55 = V_15 -> V_56 == V_57 ;
int V_18 ;
if ( ! V_2 -> V_46 )
return 0 ;
if ( V_55 ) {
V_18 = F_22 ( V_15 ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_18 = F_11 ( V_15 , V_58 , 0 , true ) ;
if ( V_18 < 0 )
goto V_38;
V_18 = F_11 ( V_15 , V_42 , V_2 -> V_5 , true ) ;
if ( V_18 < 0 )
goto V_38;
V_18 = F_11 ( V_15 , V_43 , V_2 -> V_7 , true ) ;
if ( V_18 < 0 )
goto V_38;
F_19 ( 1 ) ;
V_18 = F_13 ( V_15 , V_44 , V_2 -> V_10 , V_9 ) ;
if ( V_18 < 0 )
goto V_38;
V_18 = F_11 ( V_15 , V_45 ,
F_17 ( V_2 ) , true ) ;
if ( V_18 < 0 )
goto V_38;
if ( V_55 ) {
F_19 ( 1 ) ;
V_18 = F_23 ( V_15 ) ;
if ( V_18 < 0 )
return V_18 ;
} else {
F_19 ( 100 ) ;
}
V_2 -> V_46 = false ;
return 0 ;
V_38:
if ( V_55 )
F_23 ( V_15 ) ;
F_15 ( V_15 -> V_28 , L_13 , V_18 ) ;
return V_18 ;
}
static void F_25 ( struct V_14 * V_15 ,
struct V_59 * V_60 )
{
struct V_1 V_61 = F_26 ( V_15 , V_62 ) ;
struct V_1 V_63 = F_26 ( V_15 , V_64 ) ;
bool V_65 ;
if ( F_16 ( V_15 ) < 0 )
return;
if ( V_60 -> V_66 != - V_25 &&
V_60 -> V_67 != - V_25 ) {
F_18 ( V_15 , & V_61 ) ;
F_27 ( V_15 , & V_61 ,
V_62 ,
V_60 -> V_66 / 1000 ) ;
F_27 ( V_15 , & V_61 ,
V_68 ,
V_60 -> V_67 / 1000 ) ;
}
if ( V_60 -> V_69 != - V_25 ) {
bool V_70 = V_61 . V_5 == V_63 . V_5 && V_61 . V_7 == V_63 . V_7 ;
if ( ! V_70 )
F_18 ( V_15 , & V_63 ) ;
F_27 ( V_15 , V_70 ? & V_61 : & V_63 ,
V_64 ,
V_60 -> V_69 / 1000 ) ;
}
V_65 = V_61 . V_46 || V_63 . V_46 ;
F_24 ( V_15 , & V_61 ) ;
F_24 ( V_15 , & V_63 ) ;
F_14 ( V_15 ) ;
if ( V_65 && V_15 -> V_56 != V_57 ) {
F_11 ( V_15 , V_35 , V_71 , false ) ;
F_19 ( 300 ) ;
}
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_59 V_60 = {} ;
unsigned int V_72 , V_73 ;
if ( F_29 ( V_15 -> V_74 , & V_60 ) < 0 )
return;
if ( ! V_15 -> V_75 ) {
F_21 ( V_15 -> V_28 , L_14 ) ;
return;
}
if ( V_60 . V_67 != V_60 . V_66 ) {
if ( V_60 . V_67 == - V_25 )
F_21 ( V_15 -> V_28 , L_15 ) ;
else if ( V_60 . V_66 == - V_25 )
F_21 ( V_15 -> V_28 , L_16 ) ;
}
V_73 = V_15 -> V_75 [ V_68 ] . V_73 ;
if ( V_60 . V_67 > V_73 * 1000 ) {
F_15 ( V_15 -> V_28 , L_17 ,
V_60 . V_67 ) ;
V_60 . V_67 = - V_25 ;
}
V_73 = V_15 -> V_75 [ V_62 ] . V_73 ;
if ( V_60 . V_66 > V_73 * 1000 ) {
F_15 ( V_15 -> V_28 , L_18 ,
V_60 . V_66 ) ;
V_60 . V_66 = - V_25 ;
}
V_72 = V_15 -> V_75 [ V_64 ] . V_72 ;
V_73 = V_15 -> V_75 [ V_64 ] . V_73 ;
if ( ( V_60 . V_69 < V_72 * 1000 ||
V_60 . V_69 > V_73 * 1000 ) &&
V_60 . V_69 != - V_25 ) {
F_15 ( V_15 -> V_28 , L_19 ,
V_60 . V_69 ) ;
V_60 . V_69 = - V_25 ;
}
if ( ( V_60 . V_67 != - V_25 &&
V_60 . V_66 != - V_25 ) ||
V_60 . V_69 != - V_25 )
F_25 ( V_15 , & V_60 ) ;
}
static int F_30 ( struct V_14 * V_15 )
{
int V_76 ;
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 )
V_76 = F_9 ( V_15 , V_79 , true ) ;
else
V_76 = F_9 ( V_15 , V_79 , false ) ;
if ( V_76 < 0 )
F_10 ( V_15 -> V_28 , L_20 ) ;
return V_76 ;
}
static int F_31 ( struct V_14 * V_15 , T_2 V_4 )
{
int V_80 ;
V_80 = F_9 ( V_15 , V_4 , false ) ;
if ( V_80 < 0 ) {
F_10 ( V_15 -> V_28 , L_21 ,
V_4 , V_80 ) ;
return V_80 ;
}
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 )
V_80 *= V_81 / V_82 ;
else
V_80 *= 1000 ;
return V_80 ;
}
static inline int F_32 ( struct V_14 * V_15 )
{
int V_83 ;
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 ) {
V_83 = F_9 ( V_15 , V_53 , true ) ;
if ( V_83 >= 0 && ( V_83 & V_84 ) )
return - V_85 ;
}
return F_31 ( V_15 , V_86 ) ;
}
static inline int F_33 ( struct V_14 * V_15 )
{
return F_31 ( V_15 , V_87 ) ;
}
static int F_34 ( struct V_14 * V_15 )
{
int V_88 ;
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 )
V_88 = F_9 ( V_15 , V_89 , true ) ;
else
V_88 = F_9 ( V_15 , V_89 , false ) ;
if ( V_88 < 0 ) {
F_10 ( V_15 -> V_28 , L_22 ) ;
return V_88 ;
}
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 )
V_88 = ( V_88 << 8 ) * V_81 / V_82 ;
else
V_88 *= 1000 ;
return V_88 ;
}
static int F_35 ( struct V_14 * V_15 )
{
int V_90 ;
V_90 = F_9 ( V_15 , V_91 , false ) ;
if ( V_90 < 0 ) {
F_10 ( V_15 -> V_28 , L_23 ) ;
return V_90 ;
}
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 )
V_90 *= V_92 / V_82 ;
else
V_90 *= 1000 ;
return V_90 ;
}
static int F_36 ( struct V_14 * V_15 )
{
int V_93 ;
V_93 = F_9 ( V_15 , V_94 , false ) ;
if ( V_93 < 0 ) {
F_15 ( V_15 -> V_28 , L_24 ) ;
return V_93 ;
}
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 )
V_93 = 5 * V_93 / 2 ;
return V_93 ;
}
static int F_37 ( struct V_14 * V_15 )
{
int V_95 ;
V_95 = F_9 ( V_15 , V_96 , false ) ;
if ( V_95 < 0 )
F_15 ( V_15 -> V_28 , L_25 ) ;
return V_95 ;
}
static int F_38 ( struct V_14 * V_15 , T_2 V_4 )
{
int V_97 ;
V_97 = F_9 ( V_15 , V_4 , false ) ;
if ( V_97 < 0 ) {
F_10 ( V_15 -> V_28 , L_26 ,
V_4 , V_97 ) ;
return V_97 ;
}
if ( V_97 == 65535 )
return - V_85 ;
return V_97 * 60 ;
}
static int F_39 ( struct V_14 * V_15 )
{
int V_97 ;
V_97 = F_9 ( V_15 , V_98 , false ) ;
if ( V_97 < 0 ) {
F_15 ( V_15 -> V_28 , L_27 ,
V_98 , V_97 ) ;
return V_97 ;
}
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 )
return ( V_97 * V_92 ) / V_82 ;
else
return V_97 ;
}
static bool F_40 ( struct V_14 * V_15 , T_1 V_83 )
{
switch ( V_15 -> V_56 ) {
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
return V_83 & ( V_111 | V_112 ) ;
case V_113 :
case V_57 :
return V_83 & V_114 ;
default:
return false ;
}
}
static bool F_41 ( struct V_14 * V_15 , T_1 V_83 )
{
if ( V_15 -> V_56 == V_113 || V_15 -> V_56 == V_57 )
return V_83 & V_115 ;
return false ;
}
static bool F_42 ( struct V_14 * V_15 , T_1 V_83 )
{
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 )
return V_83 & ( V_116 | V_117 ) ;
else
return V_83 & ( V_118 | V_119 ) ;
}
static int F_43 ( struct V_14 * V_15 )
{
int V_83 ;
bool V_120 = V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 ;
V_83 = F_9 ( V_15 , V_53 , V_120 ) ;
if ( V_83 < 0 ) {
F_15 ( V_15 -> V_28 , L_28 , V_83 ) ;
return V_83 ;
}
if ( F_44 ( F_40 ( V_15 , V_83 ) ) )
return V_121 ;
if ( F_44 ( F_41 ( V_15 , V_83 ) ) )
return V_122 ;
if ( F_44 ( F_42 ( V_15 , V_83 ) ) )
return V_123 ;
return V_124 ;
}
void F_45 ( struct V_14 * V_15 )
{
struct V_125 V_126 = { 0 , } ;
bool V_127 = V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 ;
bool V_120 = V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 ;
V_126 . V_83 = F_9 ( V_15 , V_53 , V_120 ) ;
if ( ( V_126 . V_83 & 0xff ) == 0xff )
V_126 . V_83 = - 1 ;
if ( V_126 . V_83 >= 0 ) {
V_126 . V_128 = F_36 ( V_15 ) ;
if ( V_127 && ( V_126 . V_83 & V_84 ) ) {
F_46 ( V_15 -> V_28 , L_29 ) ;
V_126 . V_129 = - V_85 ;
V_126 . V_130 = - V_85 ;
V_126 . V_131 = - V_85 ;
V_126 . V_132 = - V_85 ;
V_126 . V_133 = - V_85 ;
V_126 . V_134 = - V_85 ;
V_126 . V_135 = - V_85 ;
} else {
if ( V_15 -> V_23 [ V_136 ] != V_24 )
V_126 . V_131 = F_38 ( V_15 , V_136 ) ;
if ( V_15 -> V_23 [ V_137 ] != V_24 )
V_126 . V_132 = F_38 ( V_15 , V_137 ) ;
if ( V_15 -> V_23 [ V_138 ] != V_24 )
V_126 . V_133 = F_38 ( V_15 , V_138 ) ;
V_126 . V_134 = F_33 ( V_15 ) ;
V_126 . V_129 = F_30 ( V_15 ) ;
if ( V_15 -> V_23 [ V_91 ] != V_24 )
V_126 . V_130 = F_35 ( V_15 ) ;
V_126 . V_135 = F_43 ( V_15 ) ;
}
if ( V_15 -> V_23 [ V_96 ] != V_24 )
V_126 . V_139 = F_37 ( V_15 ) ;
if ( V_15 -> V_23 [ V_98 ] != V_24 )
V_126 . V_140 = F_39 ( V_15 ) ;
if ( V_15 -> V_141 <= 0 )
V_15 -> V_141 = F_34 ( V_15 ) ;
}
if ( V_15 -> V_126 . V_129 != V_126 . V_129 )
F_47 ( V_15 -> V_74 ) ;
if ( memcmp ( & V_15 -> V_126 , & V_126 , sizeof( V_126 ) ) != 0 )
V_15 -> V_126 = V_126 ;
V_15 -> V_142 = V_143 ;
}
static void F_48 ( struct V_144 * V_20 )
{
struct V_14 * V_15 =
F_49 ( V_20 , struct V_14 ,
V_20 . V_20 ) ;
F_45 ( V_15 ) ;
if ( V_145 > 0 )
F_7 ( & V_15 -> V_20 , V_145 * V_146 ) ;
}
static int F_50 ( struct V_14 * V_15 ,
union V_147 * V_11 )
{
int V_148 ;
int V_83 ;
V_148 = F_9 ( V_15 , V_149 , false ) ;
if ( V_148 < 0 ) {
F_15 ( V_15 -> V_28 , L_30 ) ;
return V_148 ;
}
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 ) {
V_83 = F_9 ( V_15 , V_53 , true ) ;
if ( V_83 & V_150 ) {
F_10 ( V_15 -> V_28 , L_31 ) ;
V_148 = - V_148 ;
}
V_11 -> V_151 = V_148 * V_81 / V_82 ;
} else {
V_11 -> V_151 = ( int ) ( ( V_152 ) V_148 ) * 1000 ;
}
return 0 ;
}
static int F_51 ( struct V_14 * V_15 ,
union V_147 * V_11 )
{
int V_153 ;
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 ) {
if ( V_15 -> V_126 . V_83 & V_154 )
V_153 = V_155 ;
else if ( V_15 -> V_126 . V_83 & V_150 )
V_153 = V_156 ;
else if ( F_52 ( V_15 -> V_74 ) )
V_153 = V_157 ;
else
V_153 = V_158 ;
} else {
if ( V_15 -> V_126 . V_83 & V_159 )
V_153 = V_155 ;
else if ( V_15 -> V_126 . V_83 & V_160 )
V_153 = V_158 ;
else
V_153 = V_156 ;
}
V_11 -> V_151 = V_153 ;
return 0 ;
}
static int F_53 ( struct V_14 * V_15 ,
union V_147 * V_11 )
{
int V_161 ;
if ( V_15 -> V_56 == V_77 || V_15 -> V_56 == V_78 ) {
if ( V_15 -> V_126 . V_83 & V_154 )
V_161 = V_162 ;
else if ( V_15 -> V_126 . V_83 & V_116 )
V_161 = V_163 ;
else if ( V_15 -> V_126 . V_83 & V_117 )
V_161 = V_164 ;
else
V_161 = V_165 ;
} else {
if ( V_15 -> V_126 . V_83 & V_159 )
V_161 = V_162 ;
else if ( V_15 -> V_126 . V_83 & V_118 )
V_161 = V_163 ;
else if ( V_15 -> V_126 . V_83 & V_119 )
V_161 = V_164 ;
else
V_161 = V_165 ;
}
V_11 -> V_151 = V_161 ;
return 0 ;
}
static int F_54 ( struct V_14 * V_15 ,
union V_147 * V_11 )
{
int V_166 ;
V_166 = F_9 ( V_15 , V_167 , false ) ;
if ( V_166 < 0 ) {
F_15 ( V_15 -> V_28 , L_32 ) ;
return V_166 ;
}
V_11 -> V_151 = V_166 * 1000 ;
return 0 ;
}
static int F_55 ( int V_29 ,
union V_147 * V_11 )
{
if ( V_29 < 0 )
return V_29 ;
V_11 -> V_151 = V_29 ;
return 0 ;
}
static int F_56 ( struct V_168 * V_169 ,
enum V_170 V_171 ,
union V_147 * V_11 )
{
int V_18 = 0 ;
struct V_14 * V_15 = F_57 ( V_169 ) ;
F_4 ( & V_15 -> V_172 ) ;
if ( F_58 ( V_15 -> V_142 + 5 * V_146 ) ) {
F_6 ( & V_15 -> V_20 ) ;
F_48 ( & V_15 -> V_20 . V_20 ) ;
}
F_8 ( & V_15 -> V_172 ) ;
if ( V_171 != V_173 && V_15 -> V_126 . V_83 < 0 )
return - V_174 ;
switch ( V_171 ) {
case V_175 :
V_18 = F_51 ( V_15 , V_11 ) ;
break;
case V_176 :
V_18 = F_54 ( V_15 , V_11 ) ;
break;
case V_173 :
V_11 -> V_151 = V_15 -> V_126 . V_83 < 0 ? 0 : 1 ;
break;
case V_177 :
V_18 = F_50 ( V_15 , V_11 ) ;
break;
case V_178 :
V_18 = F_55 ( V_15 -> V_126 . V_129 , V_11 ) ;
break;
case V_179 :
V_18 = F_53 ( V_15 , V_11 ) ;
break;
case V_180 :
V_18 = F_55 ( V_15 -> V_126 . V_128 , V_11 ) ;
if ( V_18 == 0 )
V_11 -> V_151 -= 2731 ;
break;
case V_181 :
V_18 = F_55 ( V_15 -> V_126 . V_131 , V_11 ) ;
break;
case V_182 :
V_18 = F_55 ( V_15 -> V_126 . V_132 , V_11 ) ;
break;
case V_183 :
V_18 = F_55 ( V_15 -> V_126 . V_133 , V_11 ) ;
break;
case V_184 :
V_11 -> V_151 = V_185 ;
break;
case V_186 :
V_18 = F_55 ( F_32 ( V_15 ) , V_11 ) ;
break;
case V_187 :
V_18 = F_55 ( V_15 -> V_126 . V_134 , V_11 ) ;
break;
case V_188 :
V_18 = F_55 ( V_15 -> V_141 , V_11 ) ;
break;
case V_189 :
case V_190 :
return - V_25 ;
case V_191 :
V_18 = F_55 ( V_15 -> V_126 . V_139 , V_11 ) ;
break;
case V_192 :
V_18 = F_55 ( V_15 -> V_126 . V_130 , V_11 ) ;
break;
case V_193 :
V_18 = F_55 ( V_15 -> V_126 . V_140 , V_11 ) ;
break;
case V_194 :
V_18 = F_55 ( V_15 -> V_126 . V_135 , V_11 ) ;
break;
case V_195 :
V_11 -> V_196 = V_197 ;
break;
default:
return - V_25 ;
}
return V_18 ;
}
static void F_59 ( struct V_168 * V_169 )
{
struct V_14 * V_15 = F_57 ( V_169 ) ;
F_6 ( & V_15 -> V_20 ) ;
F_7 ( & V_15 -> V_20 , 0 ) ;
}
int F_60 ( struct V_14 * V_15 )
{
struct V_198 * V_199 ;
struct V_200 V_201 = {
. V_202 = V_15 -> V_28 -> V_202 ,
. V_203 = V_15 ,
} ;
F_61 ( & V_15 -> V_20 , F_48 ) ;
F_62 ( & V_15 -> V_172 ) ;
V_15 -> V_23 = V_204 [ V_15 -> V_56 ] ;
V_199 = F_63 ( V_15 -> V_28 , sizeof( * V_199 ) , V_205 ) ;
if ( ! V_199 )
return - V_206 ;
V_199 -> V_207 = V_15 -> V_207 ;
V_199 -> type = V_208 ;
V_199 -> V_209 = V_210 [ V_15 -> V_56 ] . V_211 ;
V_199 -> V_212 = V_210 [ V_15 -> V_56 ] . V_213 ;
V_199 -> V_214 = F_56 ;
V_199 -> V_215 = F_59 ;
V_15 -> V_74 = F_64 ( V_15 -> V_28 , V_199 , & V_201 ) ;
if ( F_65 ( V_15 -> V_74 ) ) {
F_15 ( V_15 -> V_28 , L_33 ) ;
return F_66 ( V_15 -> V_74 ) ;
}
F_67 ( V_15 -> V_28 , L_34 , V_216 ) ;
F_28 ( V_15 ) ;
F_45 ( V_15 ) ;
F_4 ( & V_19 ) ;
F_68 ( & V_15 -> V_217 , & V_218 ) ;
F_8 ( & V_19 ) ;
return 0 ;
}
void F_69 ( struct V_14 * V_15 )
{
V_145 = 0 ;
F_6 ( & V_15 -> V_20 ) ;
F_70 ( V_15 -> V_74 ) ;
F_4 ( & V_19 ) ;
F_71 ( & V_15 -> V_217 ) ;
F_8 ( & V_19 ) ;
F_72 ( & V_15 -> V_172 ) ;
}
static int F_73 ( struct V_14 * V_15 , T_2 V_4 ,
bool V_22 )
{
struct V_219 * V_28 = V_15 -> V_28 ;
struct V_220 * V_221 = V_28 -> V_222 ;
unsigned int V_223 = 3 ;
int V_224 , V_225 ;
int V_93 ;
if ( ! V_22 ) {
V_224 = V_221 -> V_27 ( V_28 , V_4 + 1 ) ;
do {
V_93 = V_224 ;
if ( V_224 < 0 )
return V_224 ;
V_225 = V_221 -> V_27 ( V_28 , V_4 ) ;
if ( V_225 < 0 )
return V_225 ;
V_224 = V_221 -> V_27 ( V_28 , V_4 + 1 ) ;
} while ( V_93 != V_224 && -- V_223 );
if ( V_223 == 0 )
return - V_226 ;
return ( V_224 << 8 ) | V_225 ;
}
return V_221 -> V_27 ( V_28 , V_4 ) ;
}
static int F_74 ( struct V_227 * V_228 )
{
struct V_14 * V_15 ;
struct V_220 * V_221 = V_228 -> V_28 . V_222 ;
if ( ! V_221 ) {
F_15 ( & V_228 -> V_28 , L_35 ) ;
return - V_25 ;
}
if ( ! V_221 -> V_27 ) {
F_15 ( & V_228 -> V_28 , L_36 ) ;
return - V_25 ;
}
if ( ! V_221 -> V_56 ) {
F_15 ( & V_228 -> V_28 , L_37 ) ;
return - V_25 ;
}
V_15 = F_63 ( & V_228 -> V_28 , sizeof( * V_15 ) , V_205 ) ;
if ( ! V_15 )
return - V_206 ;
F_75 ( V_228 , V_15 ) ;
V_15 -> V_28 = & V_228 -> V_28 ;
V_15 -> V_56 = V_221 -> V_56 ;
V_15 -> V_207 = V_221 -> V_207 ? : F_76 ( & V_228 -> V_28 ) ;
V_15 -> V_26 . V_27 = F_73 ;
return F_60 ( V_15 ) ;
}
static int F_77 ( struct V_227 * V_228 )
{
struct V_14 * V_15 = F_78 ( V_228 ) ;
F_69 ( V_15 ) ;
return 0 ;
}
