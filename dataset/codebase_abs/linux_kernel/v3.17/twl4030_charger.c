static int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 = 0 ;
int V_6 ;
V_6 = F_2 ( V_1 , & V_5 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_5 &= ~ V_2 ;
V_5 |= V_3 ;
return F_3 ( V_1 , V_5 , V_4 ) ;
}
static int F_4 ( T_1 V_4 , T_1 * V_5 )
{
return F_2 ( V_7 , V_5 , V_4 ) ;
}
static int F_5 ( T_1 V_2 , T_1 V_3 )
{
return F_1 ( V_8 , V_2 ,
V_9 | V_10 | V_3 ,
V_11 ) ;
}
static int F_6 ( T_1 V_4 )
{
int V_6 , V_12 ;
T_1 V_5 ;
V_6 = F_4 ( V_4 + 1 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_12 = ( int ) ( V_5 & 0x03 ) << 8 ;
V_6 = F_4 ( V_4 , & V_5 ) ;
if ( V_6 )
return V_6 ;
return V_12 | V_5 ;
}
static int F_7 ( struct V_13 * V_14 )
{
int V_6 ;
T_1 V_5 = 0 ;
V_6 = F_2 ( V_7 , & V_5 , V_15 ) ;
if ( V_6 )
return V_6 ;
if ( V_5 & V_16 )
return 0 ;
V_6 = F_2 ( V_17 , & V_5 ,
V_18 ) ;
if ( V_6 )
return V_6 ;
if ( V_5 & V_19 )
return 0 ;
return - V_20 ;
}
static int F_8 ( struct V_13 * V_14 )
{
int V_6 ;
T_1 V_21 ;
V_6 = F_2 ( V_8 , & V_21 ,
V_22 ) ;
if ( V_6 < 0 )
return 0 ;
F_9 ( V_14 -> V_23 , L_1 , V_21 ) ;
if ( ( V_21 & V_24 ) && ! ( V_21 & V_25 ) )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 , bool V_26 )
{
int V_6 ;
if ( V_26 ) {
if ( ! F_8 ( V_14 ) )
return - V_20 ;
if ( ! V_27 ) {
F_11 ( V_14 -> V_23 , L_2 ) ;
return - V_28 ;
}
if ( ! V_14 -> V_29 ) {
V_6 = F_12 ( V_14 -> V_30 ) ;
if ( V_6 ) {
F_13 ( V_14 -> V_23 ,
L_3 ) ;
return V_6 ;
}
V_14 -> V_29 = 1 ;
}
V_6 = F_5 ( 0 , V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_7 , 0 ,
V_32 , V_33 ) ;
} else {
V_6 = F_5 ( V_31 , 0 ) ;
if ( V_14 -> V_29 ) {
F_14 ( V_14 -> V_30 ) ;
V_14 -> V_29 = 0 ;
}
}
return V_6 ;
}
static int F_15 ( bool V_26 )
{
int V_6 ;
if ( V_26 )
V_6 = F_5 ( 0 , V_34 ) ;
else
V_6 = F_5 ( V_34 , 0 ) ;
return V_6 ;
}
static int F_16 ( int V_35 , int V_36 )
{
int V_6 ;
T_1 V_37 ;
if ( V_35 < 2500000 ||
V_36 < 25 ) {
V_6 = F_1 ( V_38 ,
V_39 , 0 , V_40 ) ;
return V_6 ;
}
V_37 = V_39 ;
if ( V_35 >= 3200000 )
V_37 |= V_41 ;
else if ( V_35 >= 3100000 )
V_37 |= V_42 ;
else if ( V_35 >= 3000000 )
V_37 |= V_43 ;
else
V_37 |= V_44 ;
if ( V_36 >= 1000 )
V_37 |= V_45 ;
else if ( V_36 >= 500 )
V_37 |= V_46 ;
else if ( V_36 >= 150 )
V_37 |= V_47 ;
else
V_37 |= V_48 ;
V_6 = F_1 ( V_38 ,
V_49 | V_50 ,
V_37 ,
V_40 ) ;
return V_6 ;
}
static T_2 F_17 ( int V_51 , void * V_52 )
{
struct V_13 * V_14 = V_52 ;
F_9 ( V_14 -> V_23 , L_4 ) ;
F_18 ( & V_14 -> V_53 ) ;
F_18 ( & V_14 -> V_54 ) ;
return V_55 ;
}
static T_2 F_19 ( int V_51 , void * V_52 )
{
struct V_13 * V_14 = V_52 ;
T_1 V_56 , V_57 ;
int V_6 ;
V_6 = F_2 ( V_58 , & V_56 ,
V_59 ) ;
if ( V_6 < 0 )
return V_55 ;
V_6 = F_2 ( V_58 , & V_57 ,
V_60 ) ;
if ( V_6 < 0 )
return V_55 ;
F_9 ( V_14 -> V_23 , L_5 , V_57 , V_56 ) ;
if ( V_56 & ( V_61 | V_62 ) ) {
F_18 ( & V_14 -> V_53 ) ;
F_18 ( & V_14 -> V_54 ) ;
}
if ( V_56 & ( V_63 | V_64 ) )
F_11 ( V_14 -> V_23 , L_6 ) ;
if ( V_56 & V_65 )
F_20 ( V_14 -> V_23 , L_7 ) ;
if ( V_57 & V_66 )
F_20 ( V_14 -> V_23 , L_8 ) ;
if ( V_57 & V_67 )
F_20 ( V_14 -> V_23 , L_9 ) ;
if ( V_57 & V_68 )
F_20 ( V_14 -> V_23 , L_10 ) ;
return V_55 ;
}
static void F_21 ( struct V_69 * V_70 )
{
struct V_13 * V_14 = F_22 ( V_70 , struct V_13 , V_71 ) ;
switch ( V_14 -> V_72 ) {
case V_73 :
case V_74 :
F_10 ( V_14 , true ) ;
break;
case V_75 :
F_10 ( V_14 , false ) ;
break;
}
}
static int F_23 ( struct V_76 * V_77 , unsigned long V_5 ,
void * V_78 )
{
struct V_13 * V_14 = F_22 ( V_77 , struct V_13 , V_79 ) ;
F_9 ( V_14 -> V_23 , L_11 , V_5 ) ;
V_14 -> V_72 = V_5 ;
F_24 ( & V_14 -> V_71 ) ;
return V_80 ;
}
static int F_25 ( void )
{
int V_81 ;
int V_6 ;
T_1 V_82 ;
V_81 = F_6 ( V_83 ) ;
if ( V_81 < 0 )
return V_81 ;
V_6 = F_4 ( V_84 , & V_82 ) ;
if ( V_6 )
return V_6 ;
V_6 = ( V_81 * 16618 - 850 * 10000 ) / 10 ;
if ( V_82 & V_85 )
V_6 *= 2 ;
return V_6 ;
}
static int F_26 ( struct V_13 * V_14 )
{
int V_6 ;
T_1 V_86 ;
V_6 = F_4 ( V_87 , & V_86 ) ;
if ( V_6 ) {
F_27 ( L_12 ) ;
return V_6 ;
}
F_9 ( V_14 -> V_23 , L_13 , V_86 ) ;
return V_86 ;
}
static int F_28 ( int V_86 )
{
V_86 &= V_88 ;
if ( V_89 <= V_86 && V_86 <= V_90 )
return V_91 ;
else if ( V_92 <= V_86 &&
V_86 <= V_93 )
return V_94 ;
else
return V_95 ;
}
static int F_29 ( struct V_96 * V_97 ,
enum V_98 V_99 ,
union V_100 * V_5 )
{
struct V_13 * V_14 = F_30 ( V_97 -> V_23 -> V_101 ) ;
int V_102 ;
int V_86 ;
int V_6 ;
V_86 = F_26 ( V_14 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( V_97 -> type == V_103 )
V_102 = V_86 & V_104 ;
else
V_102 = V_86 & V_105 ;
switch ( V_99 ) {
case V_106 :
if ( V_102 )
V_5 -> V_107 = F_28 ( V_86 ) ;
else
V_5 -> V_107 = V_95 ;
break;
case V_108 :
if ( ! V_102 )
return - V_109 ;
if ( V_97 -> type == V_103 ) {
V_6 = F_6 ( V_110 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_107 = V_6 * 6843 ;
} else {
V_6 = F_6 ( V_111 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_107 = V_6 * 9775 ;
}
break;
case V_112 :
if ( ! V_102 )
return - V_109 ;
V_6 = F_25 () ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_107 = V_6 ;
break;
case V_113 :
V_5 -> V_107 = V_102 &&
F_28 ( V_86 ) !=
V_95 ;
break;
default:
return - V_114 ;
}
return 0 ;
}
static const struct V_115 *
F_31 ( struct V_116 * V_23 )
{
struct V_117 * V_118 = V_23 -> V_119 ;
struct V_115 * V_120 ;
T_3 V_121 ;
if ( ! V_118 )
return NULL ;
V_120 = F_32 ( V_23 , sizeof( * V_120 ) , V_122 ) ;
if ( ! V_120 )
return V_120 ;
if ( F_33 ( V_118 , L_14 , & V_121 ) == 0 )
V_120 -> V_123 = V_121 ;
if ( F_33 ( V_118 , L_15 , & V_121 ) == 0 )
V_120 -> V_124 = V_121 ;
return V_120 ;
}
static inline const struct V_115 *
F_31 ( struct V_116 * V_23 )
{
return NULL ;
}
static int T_4 F_34 ( struct V_125 * V_126 )
{
struct V_13 * V_14 ;
const struct V_115 * V_120 = V_126 -> V_23 . V_127 ;
int V_6 ;
T_3 V_4 ;
V_14 = F_35 ( sizeof( * V_14 ) , V_122 ) ;
if ( V_14 == NULL )
return - V_128 ;
if ( ! V_120 )
V_120 = F_31 ( & V_126 -> V_23 ) ;
V_14 -> V_23 = & V_126 -> V_23 ;
V_14 -> V_129 = F_36 ( V_126 , 0 ) ;
V_14 -> V_130 = F_36 ( V_126 , 1 ) ;
V_6 = F_7 ( V_14 ) ;
if ( V_6 ) {
F_20 ( & V_126 -> V_23 , L_16 , V_6 ) ;
goto V_131;
}
F_37 ( V_126 , V_14 ) ;
V_14 -> V_53 . V_132 = L_17 ;
V_14 -> V_53 . type = V_133 ;
V_14 -> V_53 . V_134 = V_135 ;
V_14 -> V_53 . V_136 = F_38 ( V_135 ) ;
V_14 -> V_53 . V_137 = F_29 ;
V_6 = F_39 ( & V_126 -> V_23 , & V_14 -> V_53 ) ;
if ( V_6 ) {
F_13 ( & V_126 -> V_23 , L_18 , V_6 ) ;
goto V_138;
}
V_14 -> V_54 . V_132 = L_19 ;
V_14 -> V_54 . type = V_103 ;
V_14 -> V_54 . V_134 = V_135 ;
V_14 -> V_54 . V_136 = F_38 ( V_135 ) ;
V_14 -> V_54 . V_137 = F_29 ;
V_14 -> V_30 = F_40 ( V_14 -> V_23 , L_20 ) ;
V_6 = F_39 ( & V_126 -> V_23 , & V_14 -> V_54 ) ;
if ( V_6 ) {
F_13 ( & V_126 -> V_23 , L_21 , V_6 ) ;
goto V_139;
}
V_6 = F_41 ( V_14 -> V_129 , NULL ,
F_17 , V_140 , V_126 -> V_132 ,
V_14 ) ;
if ( V_6 < 0 ) {
F_13 ( & V_126 -> V_23 , L_22 ,
V_14 -> V_129 , V_6 ) ;
goto V_141;
}
V_6 = F_41 ( V_14 -> V_130 , NULL ,
F_19 , V_140 , V_126 -> V_132 , V_14 ) ;
if ( V_6 < 0 ) {
F_13 ( & V_126 -> V_23 , L_22 ,
V_14 -> V_130 , V_6 ) ;
goto V_142;
}
F_42 ( & V_14 -> V_71 , F_21 ) ;
V_14 -> V_143 = F_43 ( V_144 ) ;
if ( ! F_44 ( V_14 -> V_143 ) ) {
V_14 -> V_79 . V_145 = F_23 ;
F_45 ( V_14 -> V_143 , & V_14 -> V_79 ) ;
}
V_4 = ~ ( T_3 ) ( V_61 | V_62 | V_63 |
V_64 | V_65 ) ;
V_6 = F_3 ( V_58 , V_4 ,
V_146 ) ;
if ( V_6 < 0 ) {
F_13 ( & V_126 -> V_23 , L_23 , V_6 ) ;
goto V_147;
}
V_4 = ~ ( T_3 ) ( V_66 | V_67 | V_68 ) ;
V_6 = F_3 ( V_58 , V_4 ,
V_148 ) ;
if ( V_6 < 0 )
F_11 ( & V_126 -> V_23 , L_23 , V_6 ) ;
F_15 ( true ) ;
F_10 ( V_14 , true ) ;
if ( V_120 )
F_16 ( V_120 -> V_123 ,
V_120 -> V_124 ) ;
else
F_16 ( 0 , 0 ) ;
return 0 ;
V_147:
if ( ! F_44 ( V_14 -> V_143 ) ) {
F_46 ( V_14 -> V_143 , & V_14 -> V_79 ) ;
F_47 ( V_14 -> V_143 ) ;
}
F_48 ( V_14 -> V_130 , V_14 ) ;
V_142:
F_48 ( V_14 -> V_129 , V_14 ) ;
V_141:
F_49 ( & V_14 -> V_54 ) ;
V_139:
F_49 ( & V_14 -> V_53 ) ;
V_138:
V_131:
F_50 ( V_14 ) ;
return V_6 ;
}
static int T_5 F_51 ( struct V_125 * V_126 )
{
struct V_13 * V_14 = F_52 ( V_126 ) ;
F_15 ( false ) ;
F_10 ( V_14 , false ) ;
F_16 ( 0 , 0 ) ;
F_3 ( V_58 , 0xff ,
V_146 ) ;
F_3 ( V_58 , 0xff ,
V_148 ) ;
if ( ! F_44 ( V_14 -> V_143 ) ) {
F_46 ( V_14 -> V_143 , & V_14 -> V_79 ) ;
F_47 ( V_14 -> V_143 ) ;
}
F_48 ( V_14 -> V_130 , V_14 ) ;
F_48 ( V_14 -> V_129 , V_14 ) ;
F_49 ( & V_14 -> V_54 ) ;
F_49 ( & V_14 -> V_53 ) ;
F_50 ( V_14 ) ;
return 0 ;
}
