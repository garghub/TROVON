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
static void F_6 ( struct V_1 * V_2 ,
int V_17 , int V_18 , int V_19 )
{
if ( V_19 ) {
F_7 ( V_2 -> V_20 , V_21 , V_17 ) ;
F_7 ( V_2 -> V_20 , V_22 , V_18 ) ;
F_7 ( V_2 -> V_20 , V_23 , V_19 ) ;
if ( ! V_2 -> V_24 ) {
F_8 ( V_2 -> V_20 , V_25 , ! ! V_19 ) ;
V_2 -> V_24 = true ;
}
} else {
F_7 ( V_2 -> V_20 , V_23 , 0 ) ;
if ( V_2 -> V_24 ) {
F_8 ( V_2 -> V_20 , V_25 , 0 ) ;
V_2 -> V_24 = false ;
}
}
F_9 ( V_2 -> V_20 ) ;
F_10 ( & V_2 -> V_14 -> V_15 , L_2 , V_17 , V_18 ,
V_19 ) ;
}
static T_2 F_11 ( int V_26 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
unsigned long V_28 ;
unsigned int V_19 ;
struct V_29 V_30 ;
int error ;
error = F_12 ( V_2 -> V_31 , V_32 , & V_30 ,
V_33 ) ;
if ( F_13 ( error ) )
goto V_34;
if ( F_13 ( V_30 . V_17 > V_35 || V_30 . V_18 > V_35 ) )
goto V_34;
if ( F_13 ( V_30 . V_36 == 0 || V_30 . V_37 > V_35 ) )
goto V_34;
if ( F_13 ( V_30 . V_36 >= V_30 . V_37 ) )
goto V_34;
if ( ! V_2 -> V_24 &&
V_2 -> V_38 == V_30 . V_17 && V_2 -> V_39 == V_30 . V_18 &&
V_2 -> V_40 == V_30 . V_36 && V_2 -> V_41 == V_30 . V_37 ) {
goto V_34;
}
V_2 -> V_38 = V_30 . V_17 ;
V_2 -> V_39 = V_30 . V_18 ;
V_2 -> V_40 = V_30 . V_36 ;
V_2 -> V_41 = V_30 . V_37 ;
V_19 = V_30 . V_17 * ( V_30 . V_37 - V_30 . V_36 ) / V_30 . V_36 ;
V_19 = V_19 * V_2 -> V_42 / 4096 ;
if ( F_13 ( V_19 > V_35 ) )
goto V_34;
F_14 ( & V_2 -> V_43 , V_28 ) ;
F_6 ( V_2 , V_30 . V_17 , V_30 . V_18 , V_19 ) ;
F_15 ( & V_2 -> V_44 ,
V_45 + F_16 ( V_46 ) ) ;
F_17 ( & V_2 -> V_43 , V_28 ) ;
V_2 -> V_47 = V_45 ;
V_34:
return V_48 ;
}
static void F_18 ( unsigned long V_49 )
{
struct V_1 * V_2 = (struct V_1 * ) V_49 ;
unsigned long V_28 ;
F_14 ( & V_2 -> V_43 , V_28 ) ;
F_6 ( V_2 , 0 , 0 , 0 ) ;
F_17 ( & V_2 -> V_43 , V_28 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_31 , V_50 , V_51 ) ;
F_20 ( V_2 -> V_31 , V_52 , V_53 ) ;
F_20 ( V_2 -> V_31 , V_54 , V_55 ) ;
F_1 ( V_2 , V_56 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_57 ) ;
}
static void F_22 ( struct V_1 * V_2 , bool V_58 )
{
if ( V_2 -> V_59 )
F_23 ( V_2 -> V_59 , V_58 ) ;
else if ( V_2 -> V_60 )
V_2 -> V_60 ( V_58 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_25 ( V_2 -> V_14 -> V_26 ) ;
F_26 ( & V_2 -> V_44 ) ;
F_27 ( & V_2 -> V_61 ) ;
F_28 ( V_2 -> V_14 -> V_26 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
if ( V_2 -> V_62 && ( V_2 -> V_60 || V_2 -> V_59 ) ) {
V_2 -> V_47 = V_45 ;
F_30 ( & V_2 -> V_61 ,
F_31 (
F_16 ( V_2 -> V_62 ) ) ) ;
}
}
static T_3 F_32 ( struct V_63 * V_15 ,
struct V_64 * V_65 ,
char * V_66 )
{
struct V_1 * V_2 = F_33 ( V_15 ) ;
unsigned int V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
bool V_70 = true ;
int error ;
F_34 ( & V_2 -> V_71 ) ;
F_24 ( V_2 ) ;
error = F_35 ( V_2 -> V_31 , V_72 , & V_68 ) ;
if ( error ) {
F_36 ( V_15 , L_3 , error ) ;
V_70 = false ;
goto V_34;
}
V_69 = ( V_68 - 1 ) & V_35 ;
error = F_20 ( V_2 -> V_31 , V_72 , V_69 ) ;
if ( error ) {
F_36 ( V_15 , L_4 , error ) ;
V_70 = false ;
goto V_34;
}
error = F_35 ( V_2 -> V_31 , V_72 , & V_67 ) ;
if ( error ) {
F_36 ( V_15 , L_5 ,
error ) ;
V_70 = false ;
goto V_34;
}
if ( V_67 != V_69 ) {
F_36 ( V_15 , L_6 ,
V_67 , V_69 ) ;
V_70 = false ;
}
F_22 ( V_2 , false ) ;
F_37 ( 100 , 500 ) ;
F_22 ( V_2 , true ) ;
if ( ! V_70 )
goto V_34;
error = F_35 ( V_2 -> V_31 , V_72 , & V_67 ) ;
if ( error ) {
F_36 ( V_15 , L_7 ,
error ) ;
V_70 = false ;
goto V_34;
}
if ( V_67 != V_68 ) {
F_36 ( V_15 , L_8 ,
V_67 , V_68 ) ;
V_70 = false ;
}
V_34:
F_29 ( V_2 ) ;
F_38 ( & V_2 -> V_71 ) ;
return sprintf ( V_66 , L_9 , V_70 ) ;
}
static T_4 F_39 ( struct V_73 * V_74 ,
struct V_75 * V_65 , int V_76 )
{
struct V_63 * V_15 = F_40 ( V_74 , struct V_63 , V_74 ) ;
struct V_1 * V_2 = F_33 ( V_15 ) ;
T_4 V_77 = V_65 -> V_77 ;
if ( V_65 == & V_78 . V_65 ) {
if ( ! V_2 -> V_60 && ! V_2 -> V_59 )
V_77 = 0 ;
}
return V_77 ;
}
static void F_41 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_40 ( V_80 , struct V_1 , V_61 . V_80 ) ;
int error ;
unsigned int V_81 ;
if ( ! F_42 ( & V_2 -> V_71 ) ) {
goto V_82;
}
if ( F_43 ( V_2 -> V_47 +
F_16 ( V_2 -> V_62 ) ) )
goto V_34;
error = F_35 ( V_2 -> V_31 , V_50 , & V_81 ) ;
if ( ! error &&
! ( ( V_81 ^ V_51 ) & V_83 ) ) {
goto V_34;
}
F_44 ( & V_2 -> V_14 -> V_15 , L_10 ) ;
F_25 ( V_2 -> V_14 -> V_26 ) ;
F_26 ( & V_2 -> V_44 ) ;
F_6 ( V_2 , 0 , 0 , 0 ) ;
F_22 ( V_2 , false ) ;
F_37 ( 100 , 500 ) ;
F_22 ( V_2 , true ) ;
F_28 ( V_2 -> V_14 -> V_26 ) ;
F_19 ( V_2 ) ;
V_34:
F_38 ( & V_2 -> V_71 ) ;
V_82:
F_30 ( & V_2 -> V_61 ,
F_31 (
F_16 ( V_2 -> V_62 ) ) ) ;
}
static int F_45 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_46 ( V_85 ) ;
F_34 ( & V_2 -> V_71 ) ;
if ( ! V_2 -> V_86 )
F_29 ( V_2 ) ;
V_2 -> V_87 = true ;
F_38 ( & V_2 -> V_71 ) ;
return 0 ;
}
static void F_47 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_46 ( V_85 ) ;
F_34 ( & V_2 -> V_71 ) ;
if ( ! V_2 -> V_86 )
F_24 ( V_2 ) ;
V_2 -> V_87 = false ;
F_38 ( & V_2 -> V_71 ) ;
}
static int F_48 ( struct V_88 * V_14 )
{
const struct V_89 * V_90 = F_49 ( & V_14 -> V_15 ) ;
struct V_91 * V_92 = V_14 -> V_15 . V_93 ;
struct V_1 * V_2 ;
struct V_84 * V_84 ;
unsigned int V_94 = V_35 ;
unsigned int V_95 = V_35 ;
unsigned int V_96 = V_35 ;
unsigned int V_97 = V_98 ;
unsigned int V_99 = V_100 ;
unsigned int V_101 = V_102 ;
unsigned int V_42 = V_103 ;
unsigned int V_62 ;
int error ;
if ( ! V_92 && ! V_90 ) {
F_5 ( & V_14 -> V_15 , L_11 ) ;
return - V_104 ;
}
if ( V_14 -> V_26 <= 0 ) {
F_5 ( & V_14 -> V_15 , L_12 ) ;
return - V_104 ;
}
if ( V_90 ) {
V_97 = V_90 -> V_105 ;
V_99 = V_90 -> V_106 ;
V_101 = V_90 -> V_107 ;
V_94 = V_90 -> V_108 ;
V_95 = V_90 -> V_109 ;
V_96 = V_90 -> V_110 ;
V_42 = V_90 -> V_111 ;
V_62 = V_90 -> V_112 ;
} else {
V_42 = V_103 ;
F_50 ( V_92 , L_13 , & V_42 ) ;
V_62 = 0 ;
F_50 ( V_92 , L_14 ,
& V_62 ) ;
}
V_14 -> V_77 = V_113 ;
V_14 -> V_11 = 8 ;
if ( ! V_14 -> V_114 )
V_14 -> V_114 = V_115 ;
error = F_51 ( V_14 ) ;
if ( error )
return error ;
V_2 = F_52 ( & V_14 -> V_15 , sizeof( * V_2 ) , V_116 ) ;
if ( ! V_2 )
return - V_117 ;
V_84 = F_53 ( & V_14 -> V_15 ) ;
if ( ! V_84 )
return - V_117 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_20 = V_84 ;
V_2 -> V_31 = F_54 ( V_14 , & V_118 ) ;
if ( F_55 ( V_2 -> V_31 ) )
return F_56 ( V_2 -> V_31 ) ;
V_2 -> V_42 = V_42 ;
V_2 -> V_62 = V_62 ;
V_2 -> V_59 = F_57 ( & V_14 -> V_15 , L_15 ,
V_119 ) ;
if ( F_55 ( V_2 -> V_59 ) ) {
error = F_56 ( V_2 -> V_59 ) ;
F_5 ( & V_14 -> V_15 , L_16 , error ) ;
return error ;
}
V_2 -> V_120 = F_58 ( & V_14 -> V_15 , L_17 ) ;
if ( F_55 ( V_2 -> V_120 ) ) {
error = F_56 ( V_2 -> V_120 ) ;
F_5 ( & V_14 -> V_15 , L_18 , error ) ;
return error ;
}
if ( ! V_2 -> V_59 && V_90 )
V_2 -> V_60 = V_90 -> V_60 ;
F_59 ( & V_2 -> V_71 ) ;
F_60 ( & V_2 -> V_43 ) ;
F_61 ( & V_2 -> V_44 , F_18 , ( unsigned long ) V_2 ) ;
F_62 ( & V_2 -> V_61 , F_41 ) ;
snprintf ( V_2 -> V_121 , sizeof( V_2 -> V_121 ) ,
L_19 , F_63 ( & V_14 -> V_15 ) ) ;
V_84 -> V_122 = L_20 ;
V_84 -> V_121 = V_2 -> V_121 ;
V_84 -> V_123 . V_124 = V_125 ;
V_84 -> V_15 . V_126 = & V_14 -> V_15 ;
V_84 -> V_127 [ 0 ] = F_64 ( V_128 ) | F_64 ( V_129 ) ;
V_84 -> V_130 [ F_65 ( V_25 ) ] = F_66 ( V_25 ) ;
F_67 ( V_84 , V_21 , 0 , V_94 , V_97 , 0 ) ;
F_67 ( V_84 , V_22 , 0 , V_95 , V_99 , 0 ) ;
F_67 ( V_84 , V_23 , 0 , V_96 , V_101 , 0 ) ;
if ( V_92 )
F_68 ( V_84 , false ) ;
V_84 -> V_131 = F_45 ;
V_84 -> V_132 = F_47 ;
F_69 ( V_84 , V_2 ) ;
F_21 ( V_2 ) ;
error = F_70 ( & V_14 -> V_15 , V_14 -> V_26 , NULL ,
F_11 ,
V_133 | V_134 ,
L_21 , V_2 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 , L_22 , error ) ;
return error ;
}
if ( V_2 -> V_120 ) {
error = F_71 ( V_2 -> V_120 ) ;
if ( error )
return error ;
}
F_72 ( & V_14 -> V_15 , V_2 ) ;
error = F_73 ( & V_14 -> V_15 . V_74 , & V_135 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 ,
L_23 , error ) ;
goto V_136;
}
error = F_74 ( V_2 -> V_20 ) ;
if ( error ) {
F_5 ( & V_14 -> V_15 ,
L_24 , error ) ;
goto V_137;
}
F_75 ( V_14 -> V_26 , 1 ) ;
return 0 ;
V_137:
F_76 ( & V_14 -> V_15 . V_74 , & V_135 ) ;
V_136:
if ( V_2 -> V_120 )
F_77 ( V_2 -> V_120 ) ;
return error ;
}
static int F_78 ( struct V_88 * V_14 )
{
struct V_1 * V_2 = F_33 ( & V_14 -> V_15 ) ;
F_76 ( & V_14 -> V_15 . V_74 , & V_135 ) ;
if ( V_2 -> V_120 )
F_77 ( V_2 -> V_120 ) ;
return 0 ;
}
static int T_5 F_79 ( struct V_63 * V_15 )
{
struct V_1 * V_2 = F_33 ( V_15 ) ;
F_34 ( & V_2 -> V_71 ) ;
if ( ! V_2 -> V_86 && V_2 -> V_87 )
F_24 ( V_2 ) ;
V_2 -> V_86 = true ;
F_38 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int T_5 F_80 ( struct V_63 * V_15 )
{
struct V_1 * V_2 = F_33 ( V_15 ) ;
F_34 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_86 && V_2 -> V_87 )
F_29 ( V_2 ) ;
V_2 -> V_86 = false ;
F_38 ( & V_2 -> V_71 ) ;
return 0 ;
}
