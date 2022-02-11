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
static void F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_24 ( V_2 -> V_14 -> V_39 ) ;
F_25 ( & V_2 -> V_57 ) ;
F_26 ( & V_2 -> V_71 ) ;
F_27 ( V_2 -> V_14 -> V_39 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
if ( V_2 -> V_72 && V_2 -> V_73 ) {
V_2 -> V_60 = V_58 ;
F_29 ( & V_2 -> V_71 ,
F_30 (
F_18 ( V_2 -> V_72 ) ) ) ;
}
}
static T_5 F_31 ( struct V_74 * V_15 ,
struct V_75 * V_76 ,
char * V_77 )
{
struct V_78 * V_14 = F_32 ( V_15 ) ;
struct V_1 * V_2 = F_33 ( V_14 ) ;
T_2 V_79 ;
T_2 V_80 ;
T_2 V_81 ;
bool V_82 = true ;
int error ;
F_34 ( & V_2 -> V_83 ) ;
F_23 ( V_2 ) ;
error = F_8 ( V_2 , V_84 , & V_80 ) ;
if ( error ) {
F_35 ( V_15 , L_4 , error ) ;
V_82 = false ;
goto V_45;
}
V_81 = ( V_80 - 1 ) & V_50 ;
error = F_6 ( V_2 , V_84 , V_81 ) ;
if ( error ) {
F_35 ( V_15 , L_5 , error ) ;
V_82 = false ;
goto V_45;
}
error = F_8 ( V_2 , V_84 , & V_79 ) ;
if ( error ) {
F_35 ( V_15 , L_6 ,
error ) ;
V_82 = false ;
goto V_45;
}
if ( V_79 != V_81 ) {
F_35 ( V_15 , L_7 ,
V_79 , V_81 ) ;
V_82 = false ;
}
V_2 -> V_73 ( false ) ;
F_36 ( 100 , 500 ) ;
V_2 -> V_73 ( true ) ;
if ( ! V_82 )
goto V_45;
error = F_8 ( V_2 , V_84 , & V_79 ) ;
if ( error ) {
F_35 ( V_15 , L_8 ,
error ) ;
V_82 = false ;
goto V_45;
}
if ( V_79 != V_80 ) {
F_35 ( V_15 , L_9 ,
V_79 , V_80 ) ;
V_82 = false ;
}
V_45:
F_28 ( V_2 ) ;
F_37 ( & V_2 -> V_83 ) ;
return sprintf ( V_77 , L_10 , V_82 ) ;
}
static T_6 F_38 ( struct V_85 * V_86 ,
struct V_87 * V_76 , int V_88 )
{
struct V_74 * V_15 = F_39 ( V_86 , struct V_74 , V_86 ) ;
struct V_78 * V_14 = F_32 ( V_15 ) ;
struct V_1 * V_2 = F_33 ( V_14 ) ;
T_6 V_89 = V_76 -> V_89 ;
if ( V_76 == & V_90 . V_76 ) {
if ( ! V_2 -> V_73 )
V_89 = 0 ;
}
return V_89 ;
}
static void F_40 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_39 ( V_92 , struct V_1 , V_71 . V_92 ) ;
int error ;
T_2 V_93 ;
if ( ! F_41 ( & V_2 -> V_83 ) ) {
goto V_94;
}
if ( F_42 ( V_2 -> V_60 +
F_18 ( V_2 -> V_72 ) ) )
goto V_45;
error = F_8 ( V_2 , V_63 , & V_93 ) ;
if ( ! error &&
! ( ( V_93 ^ V_64 ) & V_95 ) ) {
goto V_45;
}
F_43 ( & V_2 -> V_14 -> V_15 , L_11 ) ;
F_24 ( V_2 -> V_14 -> V_39 ) ;
F_25 ( & V_2 -> V_57 ) ;
F_9 ( V_2 , 0 , 0 , 0 ) ;
V_2 -> V_73 ( false ) ;
F_36 ( 100 , 500 ) ;
V_2 -> V_73 ( true ) ;
F_27 ( V_2 -> V_14 -> V_39 ) ;
F_21 ( V_2 ) ;
V_45:
F_37 ( & V_2 -> V_83 ) ;
V_94:
F_29 ( & V_2 -> V_71 ,
F_30 (
F_18 ( V_2 -> V_72 ) ) ) ;
}
static int F_44 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_45 ( V_97 ) ;
F_34 ( & V_2 -> V_83 ) ;
if ( ! V_2 -> V_98 )
F_28 ( V_2 ) ;
V_2 -> V_99 = true ;
F_37 ( & V_2 -> V_83 ) ;
return 0 ;
}
static void F_46 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_45 ( V_97 ) ;
F_34 ( & V_2 -> V_83 ) ;
if ( ! V_2 -> V_98 )
F_23 ( V_2 ) ;
V_2 -> V_99 = false ;
F_37 ( & V_2 -> V_83 ) ;
}
static void T_7 F_47 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_46 , V_100 , false ) ;
F_7 ( & V_2 -> V_47 , V_101 , false ) ;
F_7 ( & V_2 -> V_48 , V_102 , false ) ;
F_7 ( & V_2 -> V_49 , V_103 , true ) ;
F_2 ( & V_2 -> V_44 ) ;
F_3 ( & V_2 -> V_46 . V_25 , & V_2 -> V_44 ) ;
F_3 ( & V_2 -> V_47 . V_25 , & V_2 -> V_44 ) ;
F_3 ( & V_2 -> V_48 . V_25 , & V_2 -> V_44 ) ;
F_3 ( & V_2 -> V_49 . V_25 , & V_2 -> V_44 ) ;
}
static int T_7 F_48 ( struct V_78 * V_14 )
{
const struct V_104 * V_105 = V_14 -> V_15 . V_106 ;
struct V_1 * V_2 ;
struct V_96 * V_96 ;
unsigned int V_107 , V_108 , V_109 ;
unsigned int V_110 , V_111 , V_112 ;
int error ;
if ( ! V_105 ) {
F_13 ( & V_14 -> V_15 , L_12 ) ;
return - V_113 ;
}
V_110 = V_105 -> V_114 ? : 4 ;
V_111 = V_105 -> V_115 ? : 8 ;
V_112 = V_105 -> V_116 ? : 2 ;
V_107 = V_105 -> V_117 ? : V_50 ;
V_108 = V_105 -> V_118 ? : V_50 ;
V_109 = V_105 -> V_119 ? : V_50 ;
if ( V_14 -> V_39 <= 0 ) {
F_13 ( & V_14 -> V_15 , L_13 ) ;
return - V_113 ;
}
V_14 -> V_89 = V_120 ;
V_14 -> V_11 = 8 ;
if ( ! V_14 -> V_121 )
V_14 -> V_121 = V_122 ;
error = F_49 ( V_14 ) ;
if ( error )
return error ;
V_2 = F_50 ( sizeof( * V_2 ) , V_123 ) ;
V_96 = F_51 () ;
if ( ! V_2 || ! V_96 ) {
error = - V_124 ;
goto V_125;
}
V_2 -> V_14 = V_14 ;
V_2 -> V_33 = V_96 ;
V_2 -> V_55 = V_105 -> V_126 ? : 280 ;
V_2 -> V_72 = V_105 -> V_127 ;
V_2 -> V_73 = V_105 -> V_73 ;
F_52 ( & V_2 -> V_83 ) ;
F_53 ( & V_2 -> V_56 ) ;
F_54 ( & V_2 -> V_57 , F_20 , ( unsigned long ) V_2 ) ;
F_55 ( & V_2 -> V_71 , F_40 ) ;
F_47 ( V_2 ) ;
snprintf ( V_2 -> V_128 , sizeof( V_2 -> V_128 ) ,
L_14 , F_56 ( & V_14 -> V_15 ) ) ;
V_96 -> V_129 = L_15 ;
V_96 -> V_128 = V_2 -> V_128 ;
V_96 -> V_130 . V_131 = V_132 ;
V_96 -> V_15 . V_133 = & V_14 -> V_15 ;
V_96 -> V_134 [ 0 ] = F_57 ( V_135 ) | F_57 ( V_136 ) ;
V_96 -> V_137 [ F_58 ( V_38 ) ] = F_59 ( V_38 ) ;
F_60 ( V_96 , V_34 , 0 , V_107 , V_110 , 0 ) ;
F_60 ( V_96 , V_35 , 0 , V_108 , V_111 , 0 ) ;
F_60 ( V_96 , V_36 , 0 , V_109 , V_112 , 0 ) ;
V_96 -> V_138 = F_44 ;
V_96 -> V_139 = F_46 ;
F_61 ( V_96 , V_2 ) ;
F_22 ( V_2 ) ;
error = F_62 ( V_14 -> V_39 , NULL , F_14 ,
V_140 , L_16 , V_2 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 , L_17 , error ) ;
goto V_125;
}
F_63 ( V_14 , V_2 ) ;
error = F_64 ( & V_14 -> V_15 . V_86 , & V_141 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 ,
L_18 , error ) ;
goto V_142;
}
error = F_65 ( V_2 -> V_33 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 ,
L_19 , error ) ;
goto V_143;
}
F_66 ( V_14 -> V_39 , 1 ) ;
return 0 ;
V_143:
F_67 ( & V_14 -> V_15 . V_86 , & V_141 ) ;
V_142:
F_63 ( V_14 , NULL ) ;
F_68 ( V_14 -> V_39 , V_2 ) ;
V_125:
F_69 ( V_96 ) ;
F_70 ( V_2 ) ;
return error ;
}
static int T_8 F_71 ( struct V_78 * V_14 )
{
struct V_1 * V_2 = F_33 ( V_14 ) ;
F_67 ( & V_2 -> V_14 -> V_15 . V_86 , & V_141 ) ;
F_68 ( V_2 -> V_14 -> V_39 , V_2 ) ;
F_72 ( V_2 -> V_33 ) ;
F_70 ( V_2 ) ;
F_63 ( V_14 , NULL ) ;
return 0 ;
}
static int F_73 ( struct V_74 * V_15 )
{
struct V_78 * V_14 = F_32 ( V_15 ) ;
struct V_1 * V_2 = F_33 ( V_14 ) ;
F_34 ( & V_2 -> V_83 ) ;
if ( ! V_2 -> V_98 && V_2 -> V_99 )
F_23 ( V_2 ) ;
V_2 -> V_98 = true ;
F_37 ( & V_2 -> V_83 ) ;
return 0 ;
}
static int F_74 ( struct V_74 * V_15 )
{
struct V_78 * V_14 = F_32 ( V_15 ) ;
struct V_1 * V_2 = F_33 ( V_14 ) ;
F_34 ( & V_2 -> V_83 ) ;
if ( V_2 -> V_98 && V_2 -> V_99 )
F_28 ( V_2 ) ;
V_2 -> V_98 = false ;
F_37 ( & V_2 -> V_83 ) ;
return 0 ;
}
