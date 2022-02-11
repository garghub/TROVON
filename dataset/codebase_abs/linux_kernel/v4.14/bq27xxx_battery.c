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
if ( ! V_52 && V_15 -> V_55 != V_56 ) {
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
bool V_57 = V_15 -> V_58 & V_59 ;
int V_18 ;
if ( ! V_2 -> V_46 )
return 0 ;
if ( V_57 ) {
V_18 = F_22 ( V_15 ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_18 = F_11 ( V_15 , V_60 , 0 , true ) ;
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
if ( V_57 ) {
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
if ( V_57 )
F_23 ( V_15 ) ;
F_15 ( V_15 -> V_28 , L_13 , V_18 ) ;
return V_18 ;
}
static void F_25 ( struct V_14 * V_15 ,
struct V_61 * V_62 )
{
struct V_1 V_63 = F_26 ( V_15 , V_64 ) ;
struct V_1 V_65 = F_26 ( V_15 , V_66 ) ;
bool V_67 ;
if ( F_16 ( V_15 ) < 0 )
return;
if ( V_62 -> V_68 != - V_25 &&
V_62 -> V_69 != - V_25 ) {
F_18 ( V_15 , & V_63 ) ;
F_27 ( V_15 , & V_63 ,
V_64 ,
V_62 -> V_68 / 1000 ) ;
F_27 ( V_15 , & V_63 ,
V_70 ,
V_62 -> V_69 / 1000 ) ;
}
if ( V_62 -> V_71 != - V_25 ) {
bool V_72 = V_63 . V_5 == V_65 . V_5 && V_63 . V_7 == V_65 . V_7 ;
if ( ! V_72 )
F_18 ( V_15 , & V_65 ) ;
F_27 ( V_15 , V_72 ? & V_63 : & V_65 ,
V_66 ,
V_62 -> V_71 / 1000 ) ;
}
V_67 = V_63 . V_46 || V_65 . V_46 ;
F_24 ( V_15 , & V_63 ) ;
F_24 ( V_15 , & V_65 ) ;
F_14 ( V_15 ) ;
if ( V_67 && ! ( V_15 -> V_58 & V_59 ) ) {
F_11 ( V_15 , V_35 , V_73 , false ) ;
F_19 ( 300 ) ;
}
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_61 V_62 = {} ;
unsigned int V_74 , V_75 ;
if ( F_29 ( V_15 -> V_76 , & V_62 ) < 0 )
return;
if ( ! V_15 -> V_77 ) {
F_21 ( V_15 -> V_28 , L_14 ) ;
return;
}
if ( V_62 . V_69 != V_62 . V_68 ) {
if ( V_62 . V_69 == - V_25 )
F_21 ( V_15 -> V_28 , L_15 ) ;
else if ( V_62 . V_68 == - V_25 )
F_21 ( V_15 -> V_28 , L_16 ) ;
}
V_75 = V_15 -> V_77 [ V_70 ] . V_75 ;
if ( V_62 . V_69 > V_75 * 1000 ) {
F_15 ( V_15 -> V_28 , L_17 ,
V_62 . V_69 ) ;
V_62 . V_69 = - V_25 ;
}
V_75 = V_15 -> V_77 [ V_64 ] . V_75 ;
if ( V_62 . V_68 > V_75 * 1000 ) {
F_15 ( V_15 -> V_28 , L_18 ,
V_62 . V_68 ) ;
V_62 . V_68 = - V_25 ;
}
V_74 = V_15 -> V_77 [ V_66 ] . V_74 ;
V_75 = V_15 -> V_77 [ V_66 ] . V_75 ;
if ( ( V_62 . V_71 < V_74 * 1000 ||
V_62 . V_71 > V_75 * 1000 ) &&
V_62 . V_71 != - V_25 ) {
F_15 ( V_15 -> V_28 , L_19 ,
V_62 . V_71 ) ;
V_62 . V_71 = - V_25 ;
}
if ( ( V_62 . V_69 != - V_25 &&
V_62 . V_68 != - V_25 ) ||
V_62 . V_71 != - V_25 )
F_25 ( V_15 , & V_62 ) ;
}
static int F_30 ( struct V_14 * V_15 )
{
int V_78 ;
if ( V_15 -> V_58 & V_79 )
V_78 = F_9 ( V_15 , V_80 , true ) ;
else
V_78 = F_9 ( V_15 , V_80 , false ) ;
if ( V_78 < 0 )
F_10 ( V_15 -> V_28 , L_20 ) ;
return V_78 ;
}
static int F_31 ( struct V_14 * V_15 , T_2 V_4 )
{
int V_81 ;
V_81 = F_9 ( V_15 , V_4 , false ) ;
if ( V_81 < 0 ) {
F_10 ( V_15 -> V_28 , L_21 ,
V_4 , V_81 ) ;
return V_81 ;
}
if ( V_15 -> V_58 & V_79 )
V_81 *= V_82 / V_83 ;
else
V_81 *= 1000 ;
return V_81 ;
}
static inline int F_32 ( struct V_14 * V_15 )
{
int V_84 ;
if ( V_15 -> V_58 & V_79 ) {
V_84 = F_9 ( V_15 , V_53 , true ) ;
if ( V_84 >= 0 && ( V_84 & V_85 ) )
return - V_86 ;
}
return F_31 ( V_15 , V_87 ) ;
}
static inline int F_33 ( struct V_14 * V_15 )
{
return F_31 ( V_15 , V_88 ) ;
}
static int F_34 ( struct V_14 * V_15 )
{
int V_89 ;
if ( V_15 -> V_58 & V_79 )
V_89 = F_9 ( V_15 , V_90 , true ) ;
else
V_89 = F_9 ( V_15 , V_90 , false ) ;
if ( V_89 < 0 ) {
F_10 ( V_15 -> V_28 , L_22 ) ;
return V_89 ;
}
if ( V_15 -> V_58 & V_79 )
V_89 = ( V_89 << 8 ) * V_82 / V_83 ;
else
V_89 *= 1000 ;
return V_89 ;
}
static int F_35 ( struct V_14 * V_15 )
{
int V_91 ;
V_91 = F_9 ( V_15 , V_92 , false ) ;
if ( V_91 < 0 ) {
F_10 ( V_15 -> V_28 , L_23 ) ;
return V_91 ;
}
if ( V_15 -> V_58 & V_79 )
V_91 *= V_93 / V_83 ;
else
V_91 *= 1000 ;
return V_91 ;
}
static int F_36 ( struct V_14 * V_15 )
{
int V_94 ;
V_94 = F_9 ( V_15 , V_95 , false ) ;
if ( V_94 < 0 ) {
F_15 ( V_15 -> V_28 , L_24 ) ;
return V_94 ;
}
if ( V_15 -> V_58 & V_79 )
V_94 = 5 * V_94 / 2 ;
return V_94 ;
}
static int F_37 ( struct V_14 * V_15 )
{
int V_96 ;
V_96 = F_9 ( V_15 , V_97 , false ) ;
if ( V_96 < 0 )
F_15 ( V_15 -> V_28 , L_25 ) ;
return V_96 ;
}
static int F_38 ( struct V_14 * V_15 , T_2 V_4 )
{
int V_98 ;
V_98 = F_9 ( V_15 , V_4 , false ) ;
if ( V_98 < 0 ) {
F_10 ( V_15 -> V_28 , L_26 ,
V_4 , V_98 ) ;
return V_98 ;
}
if ( V_98 == 65535 )
return - V_86 ;
return V_98 * 60 ;
}
static int F_39 ( struct V_14 * V_15 )
{
int V_98 ;
V_98 = F_9 ( V_15 , V_99 , false ) ;
if ( V_98 < 0 ) {
F_15 ( V_15 -> V_28 , L_27 ,
V_99 , V_98 ) ;
return V_98 ;
}
if ( V_15 -> V_58 & V_79 )
return ( V_98 * V_93 ) / V_83 ;
else
return V_98 ;
}
static bool F_40 ( struct V_14 * V_15 , T_1 V_84 )
{
if ( V_15 -> V_58 & V_100 )
return V_84 & ( V_101 | V_102 ) ;
if ( V_15 -> V_58 & V_103 )
return V_84 & V_104 ;
return false ;
}
static bool F_41 ( struct V_14 * V_15 , T_1 V_84 )
{
if ( V_15 -> V_58 & V_103 )
return V_84 & V_105 ;
return false ;
}
static bool F_42 ( struct V_14 * V_15 , T_1 V_84 )
{
if ( V_15 -> V_58 & V_79 )
return V_84 & ( V_106 | V_107 ) ;
else
return V_84 & ( V_108 | V_109 ) ;
}
static int F_43 ( struct V_14 * V_15 )
{
int V_84 ;
bool V_110 = V_15 -> V_58 & V_79 ;
V_84 = F_9 ( V_15 , V_53 , V_110 ) ;
if ( V_84 < 0 ) {
F_15 ( V_15 -> V_28 , L_28 , V_84 ) ;
return V_84 ;
}
if ( F_44 ( F_40 ( V_15 , V_84 ) ) )
return V_111 ;
if ( F_44 ( F_41 ( V_15 , V_84 ) ) )
return V_112 ;
if ( F_44 ( F_42 ( V_15 , V_84 ) ) )
return V_113 ;
return V_114 ;
}
void F_45 ( struct V_14 * V_15 )
{
struct V_115 V_116 = { 0 , } ;
bool V_117 = V_15 -> V_58 & V_79 ;
bool V_110 = V_15 -> V_58 & V_79 ;
V_116 . V_84 = F_9 ( V_15 , V_53 , V_110 ) ;
if ( ( V_116 . V_84 & 0xff ) == 0xff )
V_116 . V_84 = - 1 ;
if ( V_116 . V_84 >= 0 ) {
V_116 . V_118 = F_36 ( V_15 ) ;
if ( V_117 && ( V_116 . V_84 & V_85 ) ) {
F_46 ( V_15 -> V_28 , L_29 ) ;
V_116 . V_119 = - V_86 ;
V_116 . V_120 = - V_86 ;
V_116 . V_121 = - V_86 ;
V_116 . V_122 = - V_86 ;
V_116 . V_123 = - V_86 ;
V_116 . V_124 = - V_86 ;
V_116 . V_125 = - V_86 ;
} else {
if ( V_15 -> V_23 [ V_126 ] != V_24 )
V_116 . V_121 = F_38 ( V_15 , V_126 ) ;
if ( V_15 -> V_23 [ V_127 ] != V_24 )
V_116 . V_122 = F_38 ( V_15 , V_127 ) ;
if ( V_15 -> V_23 [ V_128 ] != V_24 )
V_116 . V_123 = F_38 ( V_15 , V_128 ) ;
V_116 . V_124 = F_33 ( V_15 ) ;
V_116 . V_119 = F_30 ( V_15 ) ;
if ( V_15 -> V_23 [ V_92 ] != V_24 )
V_116 . V_120 = F_35 ( V_15 ) ;
V_116 . V_125 = F_43 ( V_15 ) ;
}
if ( V_15 -> V_23 [ V_97 ] != V_24 )
V_116 . V_129 = F_37 ( V_15 ) ;
if ( V_15 -> V_23 [ V_99 ] != V_24 )
V_116 . V_130 = F_39 ( V_15 ) ;
if ( V_15 -> V_131 <= 0 )
V_15 -> V_131 = F_34 ( V_15 ) ;
}
if ( V_15 -> V_116 . V_119 != V_116 . V_119 )
F_47 ( V_15 -> V_76 ) ;
if ( memcmp ( & V_15 -> V_116 , & V_116 , sizeof( V_116 ) ) != 0 )
V_15 -> V_116 = V_116 ;
V_15 -> V_132 = V_133 ;
}
static void F_48 ( struct V_134 * V_20 )
{
struct V_14 * V_15 =
F_49 ( V_20 , struct V_14 ,
V_20 . V_20 ) ;
F_45 ( V_15 ) ;
if ( V_135 > 0 )
F_7 ( & V_15 -> V_20 , V_135 * V_136 ) ;
}
static int F_50 ( struct V_14 * V_15 ,
union V_137 * V_11 )
{
int V_138 ;
int V_84 ;
V_138 = F_9 ( V_15 , V_139 , false ) ;
if ( V_138 < 0 ) {
F_15 ( V_15 -> V_28 , L_30 ) ;
return V_138 ;
}
if ( V_15 -> V_58 & V_79 ) {
V_84 = F_9 ( V_15 , V_53 , true ) ;
if ( V_84 & V_140 ) {
F_10 ( V_15 -> V_28 , L_31 ) ;
V_138 = - V_138 ;
}
V_11 -> V_141 = V_138 * V_82 / V_83 ;
} else {
V_11 -> V_141 = ( int ) ( ( V_142 ) V_138 ) * 1000 ;
}
return 0 ;
}
static int F_51 ( struct V_14 * V_15 ,
union V_137 * V_11 )
{
int V_143 ;
if ( V_15 -> V_58 & V_79 ) {
if ( V_15 -> V_116 . V_84 & V_144 )
V_143 = V_145 ;
else if ( V_15 -> V_116 . V_84 & V_140 )
V_143 = V_146 ;
else if ( F_52 ( V_15 -> V_76 ) )
V_143 = V_147 ;
else
V_143 = V_148 ;
} else {
if ( V_15 -> V_116 . V_84 & V_149 )
V_143 = V_145 ;
else if ( V_15 -> V_116 . V_84 & V_150 )
V_143 = V_148 ;
else
V_143 = V_146 ;
}
V_11 -> V_141 = V_143 ;
return 0 ;
}
static int F_53 ( struct V_14 * V_15 ,
union V_137 * V_11 )
{
int V_151 ;
if ( V_15 -> V_58 & V_79 ) {
if ( V_15 -> V_116 . V_84 & V_144 )
V_151 = V_152 ;
else if ( V_15 -> V_116 . V_84 & V_106 )
V_151 = V_153 ;
else if ( V_15 -> V_116 . V_84 & V_107 )
V_151 = V_154 ;
else
V_151 = V_155 ;
} else {
if ( V_15 -> V_116 . V_84 & V_149 )
V_151 = V_152 ;
else if ( V_15 -> V_116 . V_84 & V_108 )
V_151 = V_153 ;
else if ( V_15 -> V_116 . V_84 & V_109 )
V_151 = V_154 ;
else
V_151 = V_155 ;
}
V_11 -> V_141 = V_151 ;
return 0 ;
}
static int F_54 ( struct V_14 * V_15 ,
union V_137 * V_11 )
{
int V_156 ;
V_156 = F_9 ( V_15 , V_157 , false ) ;
if ( V_156 < 0 ) {
F_15 ( V_15 -> V_28 , L_32 ) ;
return V_156 ;
}
V_11 -> V_141 = V_156 * 1000 ;
return 0 ;
}
static int F_55 ( int V_29 ,
union V_137 * V_11 )
{
if ( V_29 < 0 )
return V_29 ;
V_11 -> V_141 = V_29 ;
return 0 ;
}
static int F_56 ( struct V_158 * V_159 ,
enum V_160 V_161 ,
union V_137 * V_11 )
{
int V_18 = 0 ;
struct V_14 * V_15 = F_57 ( V_159 ) ;
F_4 ( & V_15 -> V_162 ) ;
if ( F_58 ( V_15 -> V_132 + 5 * V_136 ) ) {
F_6 ( & V_15 -> V_20 ) ;
F_48 ( & V_15 -> V_20 . V_20 ) ;
}
F_8 ( & V_15 -> V_162 ) ;
if ( V_161 != V_163 && V_15 -> V_116 . V_84 < 0 )
return - V_164 ;
switch ( V_161 ) {
case V_165 :
V_18 = F_51 ( V_15 , V_11 ) ;
break;
case V_166 :
V_18 = F_54 ( V_15 , V_11 ) ;
break;
case V_163 :
V_11 -> V_141 = V_15 -> V_116 . V_84 < 0 ? 0 : 1 ;
break;
case V_167 :
V_18 = F_50 ( V_15 , V_11 ) ;
break;
case V_168 :
V_18 = F_55 ( V_15 -> V_116 . V_119 , V_11 ) ;
break;
case V_169 :
V_18 = F_53 ( V_15 , V_11 ) ;
break;
case V_170 :
V_18 = F_55 ( V_15 -> V_116 . V_118 , V_11 ) ;
if ( V_18 == 0 )
V_11 -> V_141 -= 2731 ;
break;
case V_171 :
V_18 = F_55 ( V_15 -> V_116 . V_121 , V_11 ) ;
break;
case V_172 :
V_18 = F_55 ( V_15 -> V_116 . V_122 , V_11 ) ;
break;
case V_173 :
V_18 = F_55 ( V_15 -> V_116 . V_123 , V_11 ) ;
break;
case V_174 :
V_11 -> V_141 = V_175 ;
break;
case V_176 :
V_18 = F_55 ( F_32 ( V_15 ) , V_11 ) ;
break;
case V_177 :
V_18 = F_55 ( V_15 -> V_116 . V_124 , V_11 ) ;
break;
case V_178 :
V_18 = F_55 ( V_15 -> V_131 , V_11 ) ;
break;
case V_179 :
case V_180 :
return - V_25 ;
case V_181 :
V_18 = F_55 ( V_15 -> V_116 . V_129 , V_11 ) ;
break;
case V_182 :
V_18 = F_55 ( V_15 -> V_116 . V_120 , V_11 ) ;
break;
case V_183 :
V_18 = F_55 ( V_15 -> V_116 . V_130 , V_11 ) ;
break;
case V_184 :
V_18 = F_55 ( V_15 -> V_116 . V_125 , V_11 ) ;
break;
case V_185 :
V_11 -> V_186 = V_187 ;
break;
default:
return - V_25 ;
}
return V_18 ;
}
static void F_59 ( struct V_158 * V_159 )
{
struct V_14 * V_15 = F_57 ( V_159 ) ;
F_6 ( & V_15 -> V_20 ) ;
F_7 ( & V_15 -> V_20 , 0 ) ;
}
int F_60 ( struct V_14 * V_15 )
{
struct V_188 * V_189 ;
struct V_190 V_191 = {
. V_192 = V_15 -> V_28 -> V_192 ,
. V_193 = V_15 ,
} ;
F_61 ( & V_15 -> V_20 , F_48 ) ;
F_62 ( & V_15 -> V_162 ) ;
V_15 -> V_23 = V_194 [ V_15 -> V_55 ] . V_23 ;
V_15 -> V_37 = V_194 [ V_15 -> V_55 ] . V_37 ;
V_15 -> V_77 = V_194 [ V_15 -> V_55 ] . V_77 ;
V_15 -> V_58 = V_194 [ V_15 -> V_55 ] . V_58 ;
V_189 = F_63 ( V_15 -> V_28 , sizeof( * V_189 ) , V_195 ) ;
if ( ! V_189 )
return - V_196 ;
V_189 -> V_197 = V_15 -> V_197 ;
V_189 -> type = V_198 ;
V_189 -> V_199 = V_194 [ V_15 -> V_55 ] . V_200 ;
V_189 -> V_201 = V_194 [ V_15 -> V_55 ] . V_202 ;
V_189 -> V_203 = F_56 ;
V_189 -> V_204 = F_59 ;
V_15 -> V_76 = F_64 ( V_15 -> V_28 , V_189 , & V_191 ) ;
if ( F_65 ( V_15 -> V_76 ) ) {
F_15 ( V_15 -> V_28 , L_33 ) ;
return F_66 ( V_15 -> V_76 ) ;
}
F_28 ( V_15 ) ;
F_45 ( V_15 ) ;
F_4 ( & V_19 ) ;
F_67 ( & V_15 -> V_205 , & V_206 ) ;
F_8 ( & V_19 ) ;
return 0 ;
}
void F_68 ( struct V_14 * V_15 )
{
V_135 = 0 ;
F_6 ( & V_15 -> V_20 ) ;
F_69 ( V_15 -> V_76 ) ;
F_4 ( & V_19 ) ;
F_70 ( & V_15 -> V_205 ) ;
F_8 ( & V_19 ) ;
F_71 ( & V_15 -> V_162 ) ;
}
