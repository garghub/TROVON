static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = V_5 | V_6 | V_3 ;
struct V_7 V_8 = {
. V_9 = & V_4 ,
. V_10 = 1 ,
. V_11 = 8 ,
} ;
struct V_12 V_13 ;
int error ;
F_2 ( & V_13 ) ;
F_3 ( & V_8 , & V_13 ) ;
error = F_4 ( V_2 -> V_14 , & V_13 ) ;
if ( error ) {
F_5 ( & V_2 -> V_14 -> V_15 , L_1 ,
V_16 , V_3 , error ) ;
return error ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_17 , T_2 V_18 )
{
T_3 V_4 = ( ( V_17 | V_19 ) << 16 ) | V_18 ;
struct V_7 V_8 = {
. V_9 = & V_4 ,
. V_10 = 4 ,
. V_11 = 24 ,
} ;
struct V_12 V_13 ;
int error ;
F_2 ( & V_13 ) ;
F_3 ( & V_8 , & V_13 ) ;
error = F_4 ( V_2 -> V_14 , & V_13 ) ;
if ( error ) {
F_5 ( & V_2 -> V_14 -> V_15 ,
L_2 ,
V_16 , V_17 , V_18 , error ) ;
return error ;
}
return 0 ;
}
static void F_7 ( struct V_20 * V_21 , T_1 V_17 , bool V_22 )
{
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_23 = ( V_17 | V_24 ) << 16 ;
V_21 -> V_25 . V_9 = & V_21 -> V_23 ;
V_21 -> V_25 . V_26 = & V_21 -> V_27 ;
V_21 -> V_25 . V_10 = 4 ;
V_21 -> V_25 . V_11 = 24 ;
V_21 -> V_25 . V_28 = ! V_22 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_17 , T_2 * V_18 )
{
struct V_20 V_29 ;
struct V_12 V_13 ;
int error ;
F_7 ( & V_29 , V_17 , true ) ;
F_2 ( & V_13 ) ;
F_3 ( & V_29 . V_25 , & V_13 ) ;
error = F_4 ( V_2 -> V_14 , & V_13 ) ;
if ( error )
return error ;
* V_18 = V_29 . V_27 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
int V_30 , int V_31 , int V_32 )
{
if ( V_32 ) {
F_10 ( V_2 -> V_33 , V_34 , V_30 ) ;
F_10 ( V_2 -> V_33 , V_35 , V_31 ) ;
F_10 ( V_2 -> V_33 , V_36 , V_32 ) ;
if ( ! V_2 -> V_37 ) {
F_11 ( V_2 -> V_33 , V_38 , ! ! V_32 ) ;
V_2 -> V_37 = true ;
}
} else {
F_10 ( V_2 -> V_33 , V_36 , 0 ) ;
if ( V_2 -> V_37 ) {
F_11 ( V_2 -> V_33 , V_38 , 0 ) ;
V_2 -> V_37 = false ;
}
}
F_12 ( V_2 -> V_33 ) ;
F_13 ( & V_2 -> V_14 -> V_15 , L_3 , V_30 , V_31 ,
V_32 ) ;
}
static T_4 F_14 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
unsigned long V_41 ;
unsigned int V_32 ;
T_3 V_30 , V_31 ;
T_3 V_42 , V_43 ;
int error ;
error = F_4 ( V_2 -> V_14 , & V_2 -> V_44 ) ;
if ( F_15 ( error ) )
goto V_45;
V_30 = V_2 -> V_46 . V_27 ;
V_31 = V_2 -> V_47 . V_27 ;
V_42 = V_2 -> V_48 . V_27 ;
V_43 = V_2 -> V_49 . V_27 ;
if ( F_15 ( V_30 > V_50 || V_31 > V_50 ) )
goto V_45;
if ( F_15 ( V_42 == 0 || V_43 > V_50 || V_42 >= V_43 ) )
goto V_45;
if ( ! V_2 -> V_37 &&
V_2 -> V_51 == V_30 && V_2 -> V_52 == V_31 &&
V_2 -> V_53 == V_42 && V_2 -> V_54 == V_43 ) {
goto V_45;
}
V_2 -> V_51 = V_30 ;
V_2 -> V_52 = V_31 ;
V_2 -> V_53 = V_42 ;
V_2 -> V_54 = V_43 ;
V_32 = V_30 * ( V_43 - V_42 ) / V_42 ;
V_32 = V_32 * V_2 -> V_55 / 4096 ;
if ( F_15 ( V_32 > V_50 ) )
goto V_45;
F_16 ( & V_2 -> V_56 , V_41 ) ;
F_9 ( V_2 , V_30 , V_31 , V_32 ) ;
F_17 ( & V_2 -> V_57 ,
V_58 + F_18 ( V_59 ) ) ;
F_19 ( & V_2 -> V_56 , V_41 ) ;
V_2 -> V_60 = V_58 ;
V_45:
return V_61 ;
}
static void F_20 ( unsigned long V_62 )
{
struct V_1 * V_2 = (struct V_1 * ) V_62 ;
unsigned long V_41 ;
F_16 ( & V_2 -> V_56 , V_41 ) ;
F_9 ( V_2 , 0 , 0 , 0 ) ;
F_19 ( & V_2 -> V_56 , V_41 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_63 , V_64 ) ;
F_6 ( V_2 , V_65 , V_66 ) ;
F_6 ( V_2 , V_67 , V_68 ) ;
F_1 ( V_2 , V_69 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_70 ) ;
}
static void F_23 ( struct V_1 * V_2 , bool V_71 )
{
if ( V_2 -> V_72 >= 0 )
F_24 ( V_2 -> V_72 , V_71 ) ;
else if ( V_2 -> V_73 )
V_2 -> V_73 ( V_71 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_26 ( V_2 -> V_14 -> V_39 ) ;
F_27 ( & V_2 -> V_57 ) ;
F_28 ( & V_2 -> V_74 ) ;
F_29 ( V_2 -> V_14 -> V_39 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( V_2 -> V_75 && ( V_2 -> V_73 || V_2 -> V_72 ) ) {
V_2 -> V_60 = V_58 ;
F_31 ( & V_2 -> V_74 ,
F_32 (
F_18 ( V_2 -> V_75 ) ) ) ;
}
}
static T_5 F_33 ( struct V_76 * V_15 ,
struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_14 = F_34 ( V_15 ) ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
T_2 V_81 ;
T_2 V_82 ;
T_2 V_83 ;
bool V_84 = true ;
int error ;
F_36 ( & V_2 -> V_85 ) ;
F_25 ( V_2 ) ;
error = F_8 ( V_2 , V_86 , & V_82 ) ;
if ( error ) {
F_37 ( V_15 , L_4 , error ) ;
V_84 = false ;
goto V_45;
}
V_83 = ( V_82 - 1 ) & V_50 ;
error = F_6 ( V_2 , V_86 , V_83 ) ;
if ( error ) {
F_37 ( V_15 , L_5 , error ) ;
V_84 = false ;
goto V_45;
}
error = F_8 ( V_2 , V_86 , & V_81 ) ;
if ( error ) {
F_37 ( V_15 , L_6 ,
error ) ;
V_84 = false ;
goto V_45;
}
if ( V_81 != V_83 ) {
F_37 ( V_15 , L_7 ,
V_81 , V_83 ) ;
V_84 = false ;
}
F_23 ( V_2 , false ) ;
F_38 ( 100 , 500 ) ;
F_23 ( V_2 , true ) ;
if ( ! V_84 )
goto V_45;
error = F_8 ( V_2 , V_86 , & V_81 ) ;
if ( error ) {
F_37 ( V_15 , L_8 ,
error ) ;
V_84 = false ;
goto V_45;
}
if ( V_81 != V_82 ) {
F_37 ( V_15 , L_9 ,
V_81 , V_82 ) ;
V_84 = false ;
}
V_45:
F_30 ( V_2 ) ;
F_39 ( & V_2 -> V_85 ) ;
return sprintf ( V_79 , L_10 , V_84 ) ;
}
static T_6 F_40 ( struct V_87 * V_88 ,
struct V_89 * V_78 , int V_90 )
{
struct V_76 * V_15 = F_41 ( V_88 , struct V_76 , V_88 ) ;
struct V_80 * V_14 = F_34 ( V_15 ) ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
T_6 V_91 = V_78 -> V_91 ;
if ( V_78 == & V_92 . V_78 ) {
if ( ! V_2 -> V_73 && ! V_2 -> V_72 )
V_91 = 0 ;
}
return V_91 ;
}
static void F_42 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_41 ( V_94 , struct V_1 , V_74 . V_94 ) ;
int error ;
T_2 V_95 ;
if ( ! F_43 ( & V_2 -> V_85 ) ) {
goto V_96;
}
if ( F_44 ( V_2 -> V_60 +
F_18 ( V_2 -> V_75 ) ) )
goto V_45;
error = F_8 ( V_2 , V_63 , & V_95 ) ;
if ( ! error &&
! ( ( V_95 ^ V_64 ) & V_97 ) ) {
goto V_45;
}
F_45 ( & V_2 -> V_14 -> V_15 , L_11 ) ;
F_26 ( V_2 -> V_14 -> V_39 ) ;
F_27 ( & V_2 -> V_57 ) ;
F_9 ( V_2 , 0 , 0 , 0 ) ;
F_23 ( V_2 , false ) ;
F_38 ( 100 , 500 ) ;
F_23 ( V_2 , true ) ;
F_29 ( V_2 -> V_14 -> V_39 ) ;
F_21 ( V_2 ) ;
V_45:
F_39 ( & V_2 -> V_85 ) ;
V_96:
F_31 ( & V_2 -> V_74 ,
F_32 (
F_18 ( V_2 -> V_75 ) ) ) ;
}
static int F_46 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_47 ( V_99 ) ;
F_36 ( & V_2 -> V_85 ) ;
if ( ! V_2 -> V_100 )
F_30 ( V_2 ) ;
V_2 -> V_101 = true ;
F_39 ( & V_2 -> V_85 ) ;
return 0 ;
}
static void F_48 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_47 ( V_99 ) ;
F_36 ( & V_2 -> V_85 ) ;
if ( ! V_2 -> V_100 )
F_25 ( V_2 ) ;
V_2 -> V_101 = false ;
F_39 ( & V_2 -> V_85 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_46 , V_102 , false ) ;
F_7 ( & V_2 -> V_47 , V_103 , false ) ;
F_7 ( & V_2 -> V_48 , V_104 , false ) ;
F_7 ( & V_2 -> V_49 , V_105 , true ) ;
F_2 ( & V_2 -> V_44 ) ;
F_3 ( & V_2 -> V_46 . V_25 , & V_2 -> V_44 ) ;
F_3 ( & V_2 -> V_47 . V_25 , & V_2 -> V_44 ) ;
F_3 ( & V_2 -> V_48 . V_25 , & V_2 -> V_44 ) ;
F_3 ( & V_2 -> V_49 . V_25 , & V_2 -> V_44 ) ;
}
static int F_50 ( struct V_80 * V_14 )
{
const struct V_106 * V_107 = F_51 ( & V_14 -> V_15 ) ;
struct V_108 * V_109 = V_14 -> V_15 . V_110 ;
struct V_1 * V_2 ;
struct V_98 * V_98 ;
unsigned int V_111 = V_50 ;
unsigned int V_112 = V_50 ;
unsigned int V_113 = V_50 ;
unsigned int V_114 = V_115 ;
unsigned int V_116 = V_117 ;
unsigned int V_118 = V_119 ;
unsigned int V_55 = V_120 ;
unsigned int V_75 ;
int error ;
if ( ! V_109 && ! V_107 ) {
F_5 ( & V_14 -> V_15 , L_12 ) ;
return - V_121 ;
}
if ( V_14 -> V_39 <= 0 ) {
F_5 ( & V_14 -> V_15 , L_13 ) ;
return - V_121 ;
}
if ( V_107 ) {
V_114 = V_107 -> V_122 ;
V_116 = V_107 -> V_123 ;
V_118 = V_107 -> V_124 ;
V_111 = V_107 -> V_125 ;
V_112 = V_107 -> V_126 ;
V_113 = V_107 -> V_127 ;
V_55 = V_107 -> V_128 ;
V_75 = V_107 -> V_129 ;
} else {
V_55 = V_120 ;
F_52 ( V_109 , L_14 , & V_55 ) ;
V_75 = 0 ;
F_52 ( V_109 , L_15 ,
& V_75 ) ;
}
V_14 -> V_91 = V_130 ;
V_14 -> V_11 = 8 ;
if ( ! V_14 -> V_131 )
V_14 -> V_131 = V_132 ;
error = F_53 ( V_14 ) ;
if ( error )
return error ;
V_2 = F_54 ( & V_14 -> V_15 , sizeof( * V_2 ) , V_133 ) ;
if ( ! V_2 )
return - V_134 ;
V_98 = F_55 ( & V_14 -> V_15 ) ;
if ( ! V_98 )
return - V_134 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_33 = V_98 ;
V_2 -> V_55 = V_55 ;
V_2 -> V_75 = V_75 ;
if ( V_109 ) {
V_2 -> V_72 = F_56 ( V_109 , L_16 , 0 ) ;
if ( V_2 -> V_72 == - V_135 )
return V_2 -> V_72 ;
if ( V_2 -> V_72 < 0 ) {
F_5 ( & V_14 -> V_15 , L_17 ,
V_2 -> V_72 ) ;
return V_2 -> V_72 ;
}
error = F_57 ( & V_14 -> V_15 , V_2 -> V_72 , 0 ,
L_16 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 , L_18 ,
error ) ;
return error ;
}
V_2 -> V_136 = F_58 ( & V_14 -> V_15 , L_19 ) ;
if ( F_59 ( V_2 -> V_136 ) ) {
error = F_60 ( V_2 -> V_136 ) ;
F_5 ( & V_14 -> V_15 , L_20 , error ) ;
return error ;
}
} else {
V_2 -> V_72 = - 1 ;
V_2 -> V_73 = V_107 -> V_73 ;
}
F_61 ( & V_2 -> V_85 ) ;
F_62 ( & V_2 -> V_56 ) ;
F_63 ( & V_2 -> V_57 , F_20 , ( unsigned long ) V_2 ) ;
F_64 ( & V_2 -> V_74 , F_42 ) ;
F_49 ( V_2 ) ;
snprintf ( V_2 -> V_137 , sizeof( V_2 -> V_137 ) ,
L_21 , F_65 ( & V_14 -> V_15 ) ) ;
V_98 -> V_138 = L_22 ;
V_98 -> V_137 = V_2 -> V_137 ;
V_98 -> V_139 . V_140 = V_141 ;
V_98 -> V_15 . V_142 = & V_14 -> V_15 ;
V_98 -> V_143 [ 0 ] = F_66 ( V_144 ) | F_66 ( V_145 ) ;
V_98 -> V_146 [ F_67 ( V_38 ) ] = F_68 ( V_38 ) ;
F_69 ( V_98 , V_34 , 0 , V_111 , V_114 , 0 ) ;
F_69 ( V_98 , V_35 , 0 , V_112 , V_116 , 0 ) ;
F_69 ( V_98 , V_36 , 0 , V_113 , V_118 , 0 ) ;
if ( V_109 )
F_70 ( V_98 , false ) ;
V_98 -> V_147 = F_46 ;
V_98 -> V_148 = F_48 ;
F_71 ( V_98 , V_2 ) ;
F_22 ( V_2 ) ;
error = F_72 ( & V_14 -> V_15 , V_14 -> V_39 , NULL ,
F_14 ,
V_149 | V_150 ,
L_23 , V_2 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 , L_24 , error ) ;
return error ;
}
if ( V_2 -> V_136 ) {
error = F_73 ( V_2 -> V_136 ) ;
if ( error )
return error ;
}
F_74 ( V_14 , V_2 ) ;
error = F_75 ( & V_14 -> V_15 . V_88 , & V_151 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 ,
L_25 , error ) ;
goto V_152;
}
error = F_76 ( V_2 -> V_33 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 ,
L_26 , error ) ;
goto V_153;
}
F_77 ( V_14 -> V_39 , 1 ) ;
return 0 ;
V_153:
F_78 ( & V_14 -> V_15 . V_88 , & V_151 ) ;
V_152:
if ( V_2 -> V_136 )
F_79 ( V_2 -> V_136 ) ;
return error ;
}
static int F_80 ( struct V_80 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_78 ( & V_14 -> V_15 . V_88 , & V_151 ) ;
if ( V_2 -> V_136 )
F_79 ( V_2 -> V_136 ) ;
return 0 ;
}
static int T_7 F_81 ( struct V_76 * V_15 )
{
struct V_80 * V_14 = F_34 ( V_15 ) ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_36 ( & V_2 -> V_85 ) ;
if ( ! V_2 -> V_100 && V_2 -> V_101 )
F_25 ( V_2 ) ;
V_2 -> V_100 = true ;
F_39 ( & V_2 -> V_85 ) ;
return 0 ;
}
static int T_7 F_82 ( struct V_76 * V_15 )
{
struct V_80 * V_14 = F_34 ( V_15 ) ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_36 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_100 && V_2 -> V_101 )
F_30 ( V_2 ) ;
V_2 -> V_100 = false ;
F_39 ( & V_2 -> V_85 ) ;
return 0 ;
}
