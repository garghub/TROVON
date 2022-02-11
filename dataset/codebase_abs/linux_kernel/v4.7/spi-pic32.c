static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 | V_4 , & V_2 -> V_5 -> V_6 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_3 | V_4 , & V_2 -> V_5 -> V_7 ) ;
F_4 ( 20 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_8 )
{
T_1 div ;
div = F_6 ( F_7 ( V_2 -> V_9 ) , 2 * V_8 ) - 1 ;
F_2 ( div & V_10 , & V_2 -> V_5 -> V_11 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_12 = F_9 ( & V_2 -> V_5 -> V_13 ) ;
return ( V_12 >> V_14 ) & V_15 ;
}
static inline T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_12 = F_9 ( & V_2 -> V_5 -> V_13 ) ;
return ( V_12 >> V_16 ) & V_17 ;
}
static T_1 F_11 ( struct V_1 * V_2 , int V_18 )
{
T_1 V_19 , V_20 , V_21 ;
V_19 = ( V_2 -> V_22 - V_2 -> V_23 ) / V_18 ;
V_20 = V_2 -> V_24 - F_10 ( V_2 ) ;
V_21 = ( ( V_2 -> V_25 - V_2 -> V_26 ) -
( V_2 -> V_22 - V_2 -> V_23 ) ) / V_18 ;
return F_12 ( V_19 , V_20 , ( T_1 ) ( V_2 -> V_24 - V_21 ) ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , int V_18 )
{
T_1 V_27 = ( V_2 -> V_25 - V_2 -> V_26 ) / V_18 ;
return F_14 ( T_1 , V_27 , F_8 ( V_2 ) ) ;
}
static void F_15 ( struct V_1 * V_2 , const char * V_28 )
{
F_16 ( V_2 -> V_29 ) ;
F_16 ( V_2 -> V_30 ) ;
F_16 ( V_2 -> V_31 ) ;
F_17 ( & V_2 -> V_32 -> V_33 , L_1 , V_28 ) ;
if ( V_2 -> V_32 -> V_34 )
V_2 -> V_32 -> V_34 -> V_13 = - V_35 ;
F_18 ( & V_2 -> V_36 ) ;
}
static T_2 F_19 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
T_1 V_13 ;
V_13 = F_9 ( & V_2 -> V_5 -> V_13 ) ;
if ( V_13 & ( V_39 | V_40 ) ) {
F_2 ( V_39 , & V_2 -> V_5 -> V_41 ) ;
F_2 ( V_40 , & V_2 -> V_5 -> V_41 ) ;
F_15 ( V_2 , L_2 ) ;
return V_42 ;
}
if ( V_13 & V_43 ) {
F_15 ( V_2 , L_3 ) ;
return V_42 ;
}
if ( ! V_2 -> V_32 -> V_34 ) {
F_15 ( V_2 , L_4 ) ;
return V_44 ;
}
return V_44 ;
}
static T_2 F_20 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
V_2 -> V_45 ( V_2 ) ;
if ( V_2 -> V_25 == V_2 -> V_26 ) {
F_16 ( V_2 -> V_29 ) ;
F_16 ( V_2 -> V_30 ) ;
F_18 ( & V_2 -> V_36 ) ;
}
return V_42 ;
}
static T_2 F_21 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
V_2 -> V_46 ( V_2 ) ;
if ( V_2 -> V_22 == V_2 -> V_23 )
F_16 ( V_2 -> V_31 ) ;
return V_42 ;
}
static void F_22 ( void * V_47 )
{
struct V_1 * V_2 = V_47 ;
F_18 ( & V_2 -> V_36 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_50 * V_32 = V_2 -> V_32 ;
struct V_51 * V_52 ;
struct V_51 * V_53 ;
T_3 V_54 ;
int V_55 ;
if ( ! V_32 -> V_56 || ! V_32 -> V_57 )
return - V_58 ;
V_52 = F_24 ( V_32 -> V_56 ,
V_49 -> V_59 . V_60 ,
V_49 -> V_59 . V_61 ,
V_62 ,
V_63 | V_64 ) ;
if ( ! V_52 ) {
V_55 = - V_65 ;
goto V_66;
}
V_53 = F_24 ( V_32 -> V_57 ,
V_49 -> V_67 . V_60 ,
V_49 -> V_67 . V_61 ,
V_68 ,
V_63 | V_64 ) ;
if ( ! V_53 ) {
V_55 = - V_65 ;
goto V_66;
}
V_52 -> V_69 = F_22 ;
V_52 -> V_70 = V_2 ;
V_54 = F_25 ( V_52 ) ;
V_55 = F_26 ( V_54 ) ;
if ( V_55 )
goto V_66;
V_54 = F_25 ( V_53 ) ;
V_55 = F_26 ( V_54 ) ;
if ( V_55 )
goto V_71;
F_27 ( V_32 -> V_56 ) ;
F_27 ( V_32 -> V_57 ) ;
return 0 ;
V_71:
F_28 ( V_32 -> V_56 ) ;
V_66:
return V_55 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_72 )
{
int V_73 = F_30 ( struct V_74 , V_75 ) ;
struct V_50 * V_32 = V_2 -> V_32 ;
struct V_76 V_77 ;
int V_55 ;
V_77 . V_78 = true ;
V_77 . V_79 = V_2 -> V_80 + V_73 ;
V_77 . V_81 = V_2 -> V_80 + V_73 ;
V_77 . V_82 = V_2 -> V_24 / 2 ;
V_77 . V_83 = V_2 -> V_24 / 2 ;
V_77 . V_84 = V_72 ;
V_77 . V_85 = V_72 ;
V_77 . V_86 = V_2 -> V_31 ;
V_77 . V_87 = V_88 ;
V_55 = F_31 ( V_32 -> V_57 , & V_77 ) ;
if ( V_55 ) {
F_17 ( & V_32 -> V_33 , L_5 ) ;
return V_55 ;
}
V_77 . V_86 = V_2 -> V_30 ;
V_77 . V_87 = V_89 ;
V_55 = F_31 ( V_32 -> V_56 , & V_77 ) ;
if ( V_55 )
F_17 ( & V_32 -> V_33 , L_6 ) ;
return V_55 ;
}
static int F_32 ( struct V_1 * V_2 , T_4 V_90 )
{
enum V_91 V_92 ;
T_1 V_93 , V_94 ;
switch ( V_90 ) {
case 8 :
V_2 -> V_45 = V_95 ;
V_2 -> V_46 = V_96 ;
V_93 = V_97 ;
V_92 = V_98 ;
break;
case 16 :
V_2 -> V_45 = V_99 ;
V_2 -> V_46 = V_100 ;
V_93 = V_101 ;
V_92 = V_102 ;
break;
case 32 :
V_2 -> V_45 = V_103 ;
V_2 -> V_46 = V_104 ;
V_93 = V_105 ;
V_92 = V_106 ;
break;
default:
return - V_65 ;
}
V_2 -> V_24 = F_33 ( V_2 -> V_107 ,
V_90 / 8 ) ;
V_94 = F_9 ( & V_2 -> V_5 -> V_108 ) ;
V_94 &= ~ ( V_109 << V_110 ) ;
V_94 |= V_93 << V_110 ;
F_2 ( V_94 , & V_2 -> V_5 -> V_108 ) ;
if ( F_34 ( V_111 , & V_2 -> V_112 ) )
F_29 ( V_2 , V_92 ) ;
return 0 ;
}
static int F_35 ( struct V_50 * V_32 )
{
struct V_1 * V_2 = F_36 ( V_32 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_50 * V_32 ,
struct V_113 * V_28 )
{
struct V_1 * V_2 = F_36 ( V_32 ) ;
struct V_114 * V_115 = V_28 -> V_115 ;
T_1 V_116 ;
if ( V_2 -> V_90 != V_115 -> V_90 ) {
F_32 ( V_2 , V_115 -> V_90 ) ;
V_2 -> V_90 = V_115 -> V_90 ;
}
if ( V_2 -> V_117 != V_115 -> V_118 ) {
F_5 ( V_2 , V_115 -> V_118 ) ;
V_2 -> V_117 = V_115 -> V_118 ;
}
if ( V_2 -> V_119 != V_115 -> V_119 ) {
V_116 = F_9 ( & V_2 -> V_5 -> V_108 ) ;
if ( V_115 -> V_119 & V_120 )
V_116 |= V_121 ;
else
V_116 &= ~ V_121 ;
if ( V_115 -> V_119 & V_122 )
V_116 &= ~ V_123 ;
else
V_116 |= V_123 ;
V_116 |= V_124 ;
F_2 ( V_116 , & V_2 -> V_5 -> V_108 ) ;
V_2 -> V_119 = V_115 -> V_119 ;
}
return 0 ;
}
static bool F_38 ( struct V_50 * V_32 ,
struct V_114 * V_115 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_36 ( V_32 ) ;
return ( V_49 -> V_125 >= V_126 ) &&
F_34 ( V_111 , & V_2 -> V_112 ) ;
}
static int F_39 ( struct V_50 * V_32 ,
struct V_114 * V_115 ,
struct V_48 * V_127 )
{
struct V_1 * V_2 ;
bool V_128 = false ;
int V_55 ;
V_2 = F_36 ( V_32 ) ;
if ( V_127 -> V_90 &&
( V_127 -> V_90 != V_2 -> V_90 ) ) {
V_55 = F_32 ( V_2 , V_127 -> V_90 ) ;
if ( V_55 )
return V_55 ;
V_2 -> V_90 = V_127 -> V_90 ;
}
if ( V_127 -> V_117 && ( V_127 -> V_117 != V_2 -> V_117 ) ) {
F_5 ( V_2 , V_127 -> V_117 ) ;
V_2 -> V_117 = V_127 -> V_117 ;
}
F_40 ( & V_2 -> V_36 ) ;
if ( V_127 -> V_59 . V_61 && V_127 -> V_67 . V_61 ) {
V_55 = F_23 ( V_2 , V_127 ) ;
if ( V_55 ) {
F_17 ( & V_115 -> V_33 , L_7 ) ;
return V_55 ;
}
V_128 = true ;
} else {
V_2 -> V_23 = ( const void * ) V_127 -> V_129 ;
V_2 -> V_26 = ( const void * ) V_127 -> V_130 ;
V_2 -> V_22 = V_2 -> V_23 + V_127 -> V_125 ;
V_2 -> V_25 = V_2 -> V_26 + V_127 -> V_125 ;
V_2 -> V_125 = V_127 -> V_125 ;
F_41 ( V_2 -> V_29 ) ;
F_41 ( V_2 -> V_30 ) ;
F_41 ( V_2 -> V_31 ) ;
}
V_55 = F_42 ( & V_2 -> V_36 , 2 * V_131 ) ;
if ( V_55 <= 0 ) {
F_17 ( & V_115 -> V_33 , L_8 ) ;
if ( V_128 ) {
F_28 ( V_32 -> V_56 ) ;
F_28 ( V_32 -> V_56 ) ;
}
V_55 = - V_132 ;
} else {
V_55 = 0 ;
}
return V_55 ;
}
static int F_43 ( struct V_50 * V_32 ,
struct V_113 * V_28 )
{
return 0 ;
}
static int F_44 ( struct V_50 * V_32 )
{
struct V_1 * V_2 = F_36 ( V_32 ) ;
F_3 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_114 * V_115 )
{
if ( ! V_115 -> V_118 ) {
F_17 ( & V_115 -> V_33 , L_9 ) ;
return - V_65 ;
}
if ( ! F_46 ( V_115 -> V_133 ) )
return - V_65 ;
F_47 ( V_115 -> V_133 , ! ( V_115 -> V_119 & V_134 ) ) ;
return 0 ;
}
static void F_48 ( struct V_114 * V_115 )
{
F_47 ( V_115 -> V_133 , ! ( V_115 -> V_119 & V_134 ) ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_135 * V_33 )
{
struct V_50 * V_32 = V_2 -> V_32 ;
T_5 V_136 ;
F_50 ( V_136 ) ;
F_51 ( V_137 , V_136 ) ;
V_32 -> V_56 = F_52 ( V_136 , NULL , NULL ,
V_33 , L_10 ) ;
if ( ! V_32 -> V_56 ) {
F_53 ( V_33 , L_11 ) ;
goto V_138;
}
V_32 -> V_57 = F_52 ( V_136 , NULL , NULL ,
V_33 , L_12 ) ;
if ( ! V_32 -> V_57 ) {
F_53 ( V_33 , L_13 ) ;
goto V_138;
}
if ( F_29 ( V_2 , V_98 ) )
goto V_138;
F_54 ( V_111 , & V_2 -> V_112 ) ;
return;
V_138:
if ( V_32 -> V_56 )
F_55 ( V_32 -> V_56 ) ;
if ( V_32 -> V_57 )
F_55 ( V_32 -> V_57 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( ! F_34 ( V_111 , & V_2 -> V_112 ) )
return;
F_57 ( V_111 , & V_2 -> V_112 ) ;
if ( V_2 -> V_32 -> V_56 )
F_55 ( V_2 -> V_32 -> V_56 ) ;
if ( V_2 -> V_32 -> V_57 )
F_55 ( V_2 -> V_32 -> V_57 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_1 V_108 ;
F_3 ( V_2 ) ;
V_108 = F_9 ( & V_2 -> V_5 -> V_108 ) ;
V_108 |= V_139 ;
V_2 -> V_107 = 16 ;
V_108 &= ~ V_140 ;
V_108 |= V_141 ;
V_108 &= ~ ( 0x3 << V_142 ) ;
V_108 |= ( V_143 << V_142 ) ;
V_108 &= ~ ( 0x3 << V_144 ) ;
V_108 |= ( V_145 << V_144 ) ;
V_108 &= ~ V_146 ;
V_108 &= ~ V_147 ;
F_2 ( V_108 , & V_2 -> V_5 -> V_108 ) ;
V_108 = V_148 | V_149 | V_150 ;
F_2 ( V_108 , & V_2 -> V_5 -> V_151 ) ;
}
static int F_59 ( struct V_152 * V_153 ,
struct V_1 * V_2 )
{
struct V_154 * V_155 ;
int V_55 ;
V_155 = F_60 ( V_153 , V_156 , 0 ) ;
V_2 -> V_5 = F_61 ( & V_153 -> V_33 , V_155 ) ;
if ( F_62 ( V_2 -> V_5 ) )
return F_63 ( V_2 -> V_5 ) ;
V_2 -> V_80 = V_155 -> V_157 ;
V_2 -> V_29 = F_64 ( V_153 , L_14 ) ;
if ( V_2 -> V_29 < 0 ) {
F_17 ( & V_153 -> V_33 , L_15 ) ;
return V_2 -> V_29 ;
}
V_2 -> V_30 = F_64 ( V_153 , L_16 ) ;
if ( V_2 -> V_30 < 0 ) {
F_17 ( & V_153 -> V_33 , L_17 ) ;
return V_2 -> V_30 ;
}
V_2 -> V_31 = F_64 ( V_153 , L_18 ) ;
if ( V_2 -> V_31 < 0 ) {
F_17 ( & V_153 -> V_33 , L_19 ) ;
return V_2 -> V_31 ;
}
V_2 -> V_9 = F_65 ( & V_153 -> V_33 , L_20 ) ;
if ( F_62 ( V_2 -> V_9 ) ) {
F_17 ( & V_153 -> V_33 , L_21 ) ;
V_55 = F_63 ( V_2 -> V_9 ) ;
goto V_158;
}
V_55 = F_66 ( V_2 -> V_9 ) ;
if ( V_55 )
goto V_158;
F_58 ( V_2 ) ;
return 0 ;
V_158:
F_17 ( & V_153 -> V_33 , L_22 , V_159 , V_55 ) ;
return V_55 ;
}
static int F_67 ( struct V_152 * V_153 )
{
struct V_50 * V_32 ;
struct V_1 * V_2 ;
int V_55 ;
V_32 = F_68 ( & V_153 -> V_33 , sizeof( * V_2 ) ) ;
if ( ! V_32 )
return - V_160 ;
V_2 = F_36 ( V_32 ) ;
V_2 -> V_32 = V_32 ;
V_55 = F_59 ( V_153 , V_2 ) ;
if ( V_55 )
goto V_161;
V_32 -> V_33 . V_162 = F_69 ( V_153 -> V_33 . V_162 ) ;
V_32 -> V_163 = V_164 | V_165 | V_134 ;
V_32 -> V_166 = 1 ;
V_32 -> V_118 = F_7 ( V_2 -> V_9 ) ;
V_32 -> V_167 = F_45 ;
V_32 -> V_168 = F_48 ;
V_32 -> V_112 = V_169 | V_170 ;
V_32 -> V_171 = F_70 ( 8 ) | F_70 ( 16 ) |
F_70 ( 32 ) ;
V_32 -> V_172 = F_39 ;
V_32 -> V_173 = F_37 ;
V_32 -> V_174 = F_43 ;
V_32 -> V_175 = F_35 ;
V_32 -> V_176 = F_44 ;
F_49 ( V_2 , & V_153 -> V_33 ) ;
if ( F_34 ( V_111 , & V_2 -> V_112 ) )
V_32 -> V_177 = F_38 ;
F_71 ( & V_2 -> V_36 ) ;
V_2 -> V_119 = - 1 ;
F_72 ( V_2 -> V_29 , V_178 ) ;
V_55 = F_73 ( & V_153 -> V_33 , V_2 -> V_29 ,
F_19 , V_179 ,
F_74 ( & V_153 -> V_33 ) , V_2 ) ;
if ( V_55 < 0 ) {
F_17 ( & V_153 -> V_33 , L_23 , V_2 -> V_30 ) ;
goto V_180;
}
F_72 ( V_2 -> V_30 , V_178 ) ;
V_55 = F_73 ( & V_153 -> V_33 , V_2 -> V_30 ,
F_20 , V_179 ,
F_74 ( & V_153 -> V_33 ) , V_2 ) ;
if ( V_55 < 0 ) {
F_17 ( & V_153 -> V_33 , L_24 , V_2 -> V_30 ) ;
goto V_180;
}
F_72 ( V_2 -> V_31 , V_178 ) ;
V_55 = F_73 ( & V_153 -> V_33 , V_2 -> V_31 ,
F_21 , V_179 ,
F_74 ( & V_153 -> V_33 ) , V_2 ) ;
if ( V_55 < 0 ) {
F_17 ( & V_153 -> V_33 , L_25 , V_2 -> V_31 ) ;
goto V_180;
}
V_55 = F_75 ( & V_153 -> V_33 , V_32 ) ;
if ( V_55 ) {
F_17 ( & V_32 -> V_33 , L_26 ) ;
goto V_180;
}
F_76 ( V_153 , V_2 ) ;
return 0 ;
V_180:
F_77 ( V_2 -> V_9 ) ;
V_161:
F_78 ( V_32 ) ;
return V_55 ;
}
static int F_79 ( struct V_152 * V_153 )
{
struct V_1 * V_2 ;
V_2 = F_80 ( V_153 ) ;
F_3 ( V_2 ) ;
F_77 ( V_2 -> V_9 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
