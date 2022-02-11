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
T_1 V_15 ;
V_6 = F_2 ( V_8 , & V_15 ,
V_16 ) ;
if ( V_6 < 0 )
return 0 ;
F_8 ( V_14 -> V_17 , L_1 , V_15 ) ;
if ( ( V_15 & V_18 ) && ! ( V_15 & V_19 ) )
return 1 ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 , bool V_20 )
{
int V_6 ;
if ( V_20 ) {
if ( ! F_7 ( V_14 ) )
return - V_21 ;
if ( ! V_22 ) {
F_10 ( V_14 -> V_17 , L_2 ) ;
return - V_23 ;
}
if ( ! V_14 -> V_24 ) {
V_6 = F_11 ( V_14 -> V_25 ) ;
if ( V_6 ) {
F_12 ( V_14 -> V_17 ,
L_3 ) ;
return V_6 ;
}
V_14 -> V_24 = 1 ;
}
V_6 = F_5 ( 0 , V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_7 , 0 ,
V_27 , V_28 ) ;
} else {
V_6 = F_5 ( V_26 , 0 ) ;
if ( V_14 -> V_24 ) {
F_13 ( V_14 -> V_25 ) ;
V_14 -> V_24 = 0 ;
}
}
return V_6 ;
}
static int F_14 ( bool V_20 )
{
int V_6 ;
if ( V_20 )
V_6 = F_5 ( 0 , V_29 ) ;
else
V_6 = F_5 ( V_29 , 0 ) ;
return V_6 ;
}
static int F_15 ( int V_30 , int V_31 )
{
int V_6 ;
T_1 V_32 ;
if ( V_30 < 2500000 ||
V_31 < 25 ) {
V_6 = F_1 ( V_33 ,
V_34 , 0 , V_35 ) ;
return V_6 ;
}
V_32 = V_34 ;
if ( V_30 >= 3200000 )
V_32 |= V_36 ;
else if ( V_30 >= 3100000 )
V_32 |= V_37 ;
else if ( V_30 >= 3000000 )
V_32 |= V_38 ;
else
V_32 |= V_39 ;
if ( V_31 >= 1000 )
V_32 |= V_40 ;
else if ( V_31 >= 500 )
V_32 |= V_41 ;
else if ( V_31 >= 150 )
V_32 |= V_42 ;
else
V_32 |= V_43 ;
V_6 = F_1 ( V_33 ,
V_44 | V_45 ,
V_32 ,
V_35 ) ;
return V_6 ;
}
static T_2 F_16 ( int V_46 , void * V_47 )
{
struct V_13 * V_14 = V_47 ;
F_8 ( V_14 -> V_17 , L_4 ) ;
F_17 ( & V_14 -> V_48 ) ;
F_17 ( & V_14 -> V_49 ) ;
return V_50 ;
}
static T_2 F_18 ( int V_46 , void * V_47 )
{
struct V_13 * V_14 = V_47 ;
T_1 V_51 , V_52 ;
int V_6 ;
V_6 = F_2 ( V_53 , & V_51 ,
V_54 ) ;
if ( V_6 < 0 )
return V_50 ;
V_6 = F_2 ( V_53 , & V_52 ,
V_55 ) ;
if ( V_6 < 0 )
return V_50 ;
F_8 ( V_14 -> V_17 , L_5 , V_52 , V_51 ) ;
if ( V_51 & ( V_56 | V_57 ) ) {
F_17 ( & V_14 -> V_48 ) ;
F_17 ( & V_14 -> V_49 ) ;
}
if ( V_51 & ( V_58 | V_59 ) )
F_10 ( V_14 -> V_17 , L_6 ) ;
if ( V_51 & V_60 )
F_19 ( V_14 -> V_17 , L_7 ) ;
if ( V_52 & V_61 )
F_19 ( V_14 -> V_17 , L_8 ) ;
if ( V_52 & V_62 )
F_19 ( V_14 -> V_17 , L_9 ) ;
if ( V_52 & V_63 )
F_19 ( V_14 -> V_17 , L_10 ) ;
return V_50 ;
}
static void F_20 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_21 ( V_65 , struct V_13 , V_66 ) ;
switch ( V_14 -> V_67 ) {
case V_68 :
case V_69 :
F_9 ( V_14 , true ) ;
break;
case V_70 :
F_9 ( V_14 , false ) ;
break;
}
}
static int F_22 ( struct V_71 * V_72 , unsigned long V_5 ,
void * V_73 )
{
struct V_13 * V_14 = F_21 ( V_72 , struct V_13 , V_74 ) ;
F_8 ( V_14 -> V_17 , L_11 , V_5 ) ;
V_14 -> V_67 = V_5 ;
F_23 ( & V_14 -> V_66 ) ;
return V_75 ;
}
static int F_24 ( void )
{
int V_76 ;
int V_6 ;
T_1 V_77 ;
V_76 = F_6 ( V_78 ) ;
if ( V_76 < 0 )
return V_76 ;
V_6 = F_4 ( V_79 , & V_77 ) ;
if ( V_6 )
return V_6 ;
V_6 = ( V_76 * 16618 - 850 * 10000 ) / 10 ;
if ( V_77 & V_80 )
V_6 *= 2 ;
return V_6 ;
}
static int F_25 ( struct V_13 * V_14 )
{
int V_6 ;
T_1 V_81 ;
V_6 = F_4 ( V_82 , & V_81 ) ;
if ( V_6 ) {
F_26 ( L_12 ) ;
return V_6 ;
}
F_8 ( V_14 -> V_17 , L_13 , V_81 ) ;
return V_81 ;
}
static int F_27 ( int V_81 )
{
V_81 &= V_83 ;
if ( V_84 <= V_81 && V_81 <= V_85 )
return V_86 ;
else if ( V_87 <= V_81 &&
V_81 <= V_88 )
return V_89 ;
else
return V_90 ;
}
static int F_28 ( struct V_91 * V_92 ,
enum V_93 V_94 ,
union V_95 * V_5 )
{
struct V_13 * V_14 = F_29 ( V_92 -> V_17 -> V_96 ) ;
int V_97 ;
int V_81 ;
int V_6 ;
V_81 = F_25 ( V_14 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_92 -> type == V_98 )
V_97 = V_81 & V_99 ;
else
V_97 = V_81 & V_100 ;
switch ( V_94 ) {
case V_101 :
if ( V_97 )
V_5 -> V_102 = F_27 ( V_81 ) ;
else
V_5 -> V_102 = V_90 ;
break;
case V_103 :
if ( ! V_97 )
return - V_104 ;
if ( V_92 -> type == V_98 ) {
V_6 = F_6 ( V_105 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_102 = V_6 * 6843 ;
} else {
V_6 = F_6 ( V_106 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_102 = V_6 * 9775 ;
}
break;
case V_107 :
if ( ! V_97 )
return - V_104 ;
V_6 = F_24 () ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_102 = V_6 ;
break;
case V_108 :
V_5 -> V_102 = V_97 &&
F_27 ( V_81 ) !=
V_90 ;
break;
default:
return - V_109 ;
}
return 0 ;
}
static const struct V_110 *
F_30 ( struct V_111 * V_17 )
{
struct V_112 * V_113 = V_17 -> V_114 ;
struct V_110 * V_115 ;
T_3 V_116 ;
if ( ! V_113 )
return NULL ;
V_115 = F_31 ( V_17 , sizeof( * V_115 ) , V_117 ) ;
if ( ! V_115 )
return V_115 ;
if ( F_32 ( V_113 , L_14 , & V_116 ) == 0 )
V_115 -> V_118 = V_116 ;
if ( F_32 ( V_113 , L_15 , & V_116 ) == 0 )
V_115 -> V_119 = V_116 ;
return V_115 ;
}
static inline const struct V_110 *
F_30 ( struct V_111 * V_17 )
{
return NULL ;
}
static int T_4 F_33 ( struct V_120 * V_121 )
{
struct V_13 * V_14 ;
const struct V_110 * V_115 = V_121 -> V_17 . V_122 ;
int V_6 ;
T_3 V_4 ;
V_14 = F_34 ( sizeof( * V_14 ) , V_117 ) ;
if ( V_14 == NULL )
return - V_123 ;
if ( ! V_115 )
V_115 = F_30 ( & V_121 -> V_17 ) ;
V_14 -> V_17 = & V_121 -> V_17 ;
V_14 -> V_124 = F_35 ( V_121 , 0 ) ;
V_14 -> V_125 = F_35 ( V_121 , 1 ) ;
F_36 ( V_121 , V_14 ) ;
V_14 -> V_48 . V_126 = L_16 ;
V_14 -> V_48 . type = V_127 ;
V_14 -> V_48 . V_128 = V_129 ;
V_14 -> V_48 . V_130 = F_37 ( V_129 ) ;
V_14 -> V_48 . V_131 = F_28 ;
V_6 = F_38 ( & V_121 -> V_17 , & V_14 -> V_48 ) ;
if ( V_6 ) {
F_12 ( & V_121 -> V_17 , L_17 , V_6 ) ;
goto V_132;
}
V_14 -> V_49 . V_126 = L_18 ;
V_14 -> V_49 . type = V_98 ;
V_14 -> V_49 . V_128 = V_129 ;
V_14 -> V_49 . V_130 = F_37 ( V_129 ) ;
V_14 -> V_49 . V_131 = F_28 ;
V_14 -> V_25 = F_39 ( V_14 -> V_17 , L_19 ) ;
V_6 = F_38 ( & V_121 -> V_17 , & V_14 -> V_49 ) ;
if ( V_6 ) {
F_12 ( & V_121 -> V_17 , L_20 , V_6 ) ;
goto V_133;
}
V_6 = F_40 ( V_14 -> V_124 , NULL ,
F_16 , V_134 , V_121 -> V_126 ,
V_14 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_121 -> V_17 , L_21 ,
V_14 -> V_124 , V_6 ) ;
goto V_135;
}
V_6 = F_40 ( V_14 -> V_125 , NULL ,
F_18 , V_134 , V_121 -> V_126 , V_14 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_121 -> V_17 , L_21 ,
V_14 -> V_125 , V_6 ) ;
goto V_136;
}
F_41 ( & V_14 -> V_66 , F_20 ) ;
V_14 -> V_137 = F_42 ( V_138 ) ;
if ( ! F_43 ( V_14 -> V_137 ) ) {
V_14 -> V_74 . V_139 = F_22 ;
F_44 ( V_14 -> V_137 , & V_14 -> V_74 ) ;
}
V_4 = ~ ( T_3 ) ( V_56 | V_57 | V_58 |
V_59 | V_60 ) ;
V_6 = F_3 ( V_53 , V_4 ,
V_140 ) ;
if ( V_6 < 0 ) {
F_12 ( & V_121 -> V_17 , L_22 , V_6 ) ;
goto V_141;
}
V_4 = ~ ( T_3 ) ( V_61 | V_62 | V_63 ) ;
V_6 = F_3 ( V_53 , V_4 ,
V_142 ) ;
if ( V_6 < 0 )
F_10 ( & V_121 -> V_17 , L_22 , V_6 ) ;
F_14 ( true ) ;
F_9 ( V_14 , true ) ;
if ( V_115 )
F_15 ( V_115 -> V_118 ,
V_115 -> V_119 ) ;
else
F_15 ( 0 , 0 ) ;
return 0 ;
V_141:
if ( ! F_43 ( V_14 -> V_137 ) ) {
F_45 ( V_14 -> V_137 , & V_14 -> V_74 ) ;
F_46 ( V_14 -> V_137 ) ;
}
F_47 ( V_14 -> V_125 , V_14 ) ;
V_136:
F_47 ( V_14 -> V_124 , V_14 ) ;
V_135:
F_48 ( & V_14 -> V_49 ) ;
V_133:
F_48 ( & V_14 -> V_48 ) ;
V_132:
F_49 ( V_14 ) ;
return V_6 ;
}
static int T_5 F_50 ( struct V_120 * V_121 )
{
struct V_13 * V_14 = F_51 ( V_121 ) ;
F_14 ( false ) ;
F_9 ( V_14 , false ) ;
F_15 ( 0 , 0 ) ;
F_3 ( V_53 , 0xff ,
V_140 ) ;
F_3 ( V_53 , 0xff ,
V_142 ) ;
if ( ! F_43 ( V_14 -> V_137 ) ) {
F_45 ( V_14 -> V_137 , & V_14 -> V_74 ) ;
F_46 ( V_14 -> V_137 ) ;
}
F_47 ( V_14 -> V_125 , V_14 ) ;
F_47 ( V_14 -> V_124 , V_14 ) ;
F_48 ( & V_14 -> V_49 ) ;
F_48 ( & V_14 -> V_48 ) ;
F_49 ( V_14 ) ;
return 0 ;
}
