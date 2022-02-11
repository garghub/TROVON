static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 )
{
if ( V_5 ) {
F_2 ( V_2 -> V_6 , V_7 , V_3 ) ;
F_2 ( V_2 -> V_6 , V_8 , V_4 ) ;
F_2 ( V_2 -> V_6 , V_9 , V_5 ) ;
if ( ! V_2 -> V_10 ) {
F_3 ( V_2 -> V_6 , V_11 , ! ! V_5 ) ;
V_2 -> V_10 = true ;
}
} else {
F_2 ( V_2 -> V_6 , V_9 , 0 ) ;
if ( V_2 -> V_10 ) {
F_3 ( V_2 -> V_6 , V_11 , 0 ) ;
V_2 -> V_10 = false ;
}
}
F_4 ( V_2 -> V_6 ) ;
F_5 ( V_2 -> V_12 , L_1 , V_3 , V_4 ,
V_5 ) ;
}
static T_1 F_6 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
unsigned long V_15 ;
unsigned int V_5 ;
struct V_16 V_17 ;
int error ;
error = F_7 ( V_2 -> V_18 , V_19 , & V_17 ,
V_20 ) ;
if ( F_8 ( error ) )
goto V_21;
if ( F_8 ( V_17 . V_3 > V_22 || V_17 . V_4 > V_22 ) )
goto V_21;
if ( F_8 ( V_17 . V_23 == 0 || V_17 . V_24 > V_22 ) )
goto V_21;
if ( F_8 ( V_17 . V_23 >= V_17 . V_24 ) )
goto V_21;
if ( ! V_2 -> V_10 &&
V_2 -> V_25 == V_17 . V_3 && V_2 -> V_26 == V_17 . V_4 &&
V_2 -> V_27 == V_17 . V_23 && V_2 -> V_28 == V_17 . V_24 ) {
goto V_21;
}
V_2 -> V_25 = V_17 . V_3 ;
V_2 -> V_26 = V_17 . V_4 ;
V_2 -> V_27 = V_17 . V_23 ;
V_2 -> V_28 = V_17 . V_24 ;
V_5 = V_17 . V_3 * ( V_17 . V_24 - V_17 . V_23 ) / V_17 . V_23 ;
V_5 = V_5 * V_2 -> V_29 / 4096 ;
if ( F_8 ( V_5 > V_22 ) )
goto V_21;
F_9 ( & V_2 -> V_30 , V_15 ) ;
F_1 ( V_2 , V_17 . V_3 , V_17 . V_4 , V_5 ) ;
F_10 ( & V_2 -> V_31 ,
V_32 + F_11 ( V_33 ) ) ;
F_12 ( & V_2 -> V_30 , V_15 ) ;
V_2 -> V_34 = V_32 ;
V_21:
return V_35 ;
}
static void F_13 ( unsigned long V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
unsigned long V_15 ;
F_9 ( & V_2 -> V_30 , V_15 ) ;
F_1 ( V_2 , 0 , 0 , 0 ) ;
F_12 ( & V_2 -> V_30 , V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_18 , V_37 , V_38 ) ;
F_15 ( V_2 -> V_18 , V_39 , V_40 ) ;
F_15 ( V_2 -> V_18 , V_41 , V_42 ) ;
V_2 -> V_43 ( V_2 -> V_12 , V_44 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_43 ( V_2 -> V_12 , V_45 ) ;
}
static void F_17 ( struct V_1 * V_2 , bool V_46 )
{
if ( V_2 -> V_47 )
F_18 ( V_2 -> V_47 , V_46 ) ;
else if ( V_2 -> V_48 )
V_2 -> V_48 ( V_46 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_20 ( V_2 -> V_13 ) ;
F_21 ( & V_2 -> V_31 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_23 ( V_2 -> V_13 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
if ( V_2 -> V_50 && ( V_2 -> V_48 || V_2 -> V_47 ) ) {
V_2 -> V_34 = V_32 ;
F_25 ( & V_2 -> V_49 ,
F_26 (
F_11 ( V_2 -> V_50 ) ) ) ;
}
}
static T_2 F_27 ( struct V_51 * V_12 ,
struct V_52 * V_53 ,
char * V_54 )
{
struct V_1 * V_2 = F_28 ( V_12 ) ;
unsigned int V_55 ;
unsigned int V_56 ;
unsigned int V_57 ;
bool V_58 = true ;
int error ;
F_29 ( & V_2 -> V_59 ) ;
F_19 ( V_2 ) ;
error = F_30 ( V_2 -> V_18 , V_60 , & V_56 ) ;
if ( error ) {
F_31 ( V_12 , L_2 , error ) ;
V_58 = false ;
goto V_21;
}
V_57 = ( V_56 - 1 ) & V_22 ;
error = F_15 ( V_2 -> V_18 , V_60 , V_57 ) ;
if ( error ) {
F_31 ( V_12 , L_3 , error ) ;
V_58 = false ;
goto V_21;
}
error = F_30 ( V_2 -> V_18 , V_60 , & V_55 ) ;
if ( error ) {
F_31 ( V_12 , L_4 ,
error ) ;
V_58 = false ;
goto V_21;
}
if ( V_55 != V_57 ) {
F_31 ( V_12 , L_5 ,
V_55 , V_57 ) ;
V_58 = false ;
}
F_17 ( V_2 , false ) ;
F_32 ( 100 , 500 ) ;
F_17 ( V_2 , true ) ;
if ( ! V_58 )
goto V_21;
error = F_30 ( V_2 -> V_18 , V_60 , & V_55 ) ;
if ( error ) {
F_31 ( V_12 , L_6 ,
error ) ;
V_58 = false ;
goto V_21;
}
if ( V_55 != V_56 ) {
F_31 ( V_12 , L_7 ,
V_55 , V_56 ) ;
V_58 = false ;
}
V_21:
F_24 ( V_2 ) ;
F_33 ( & V_2 -> V_59 ) ;
return sprintf ( V_54 , L_8 , V_58 ) ;
}
static T_3 F_34 ( struct V_61 * V_62 ,
struct V_63 * V_53 , int V_64 )
{
struct V_51 * V_12 = F_35 ( V_62 , struct V_51 , V_62 ) ;
struct V_1 * V_2 = F_28 ( V_12 ) ;
T_3 V_65 = V_53 -> V_65 ;
if ( V_53 == & V_66 . V_53 ) {
if ( ! V_2 -> V_48 && ! V_2 -> V_47 )
V_65 = 0 ;
}
return V_65 ;
}
static void F_36 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_35 ( V_68 , struct V_1 , V_49 . V_68 ) ;
int error ;
unsigned int V_69 ;
if ( ! F_37 ( & V_2 -> V_59 ) ) {
goto V_70;
}
if ( F_38 ( V_2 -> V_34 +
F_11 ( V_2 -> V_50 ) ) )
goto V_21;
error = F_30 ( V_2 -> V_18 , V_37 , & V_69 ) ;
if ( ! error &&
! ( ( V_69 ^ V_38 ) & V_71 ) ) {
goto V_21;
}
F_39 ( V_2 -> V_12 , L_9 ) ;
F_20 ( V_2 -> V_13 ) ;
F_21 ( & V_2 -> V_31 ) ;
F_1 ( V_2 , 0 , 0 , 0 ) ;
F_17 ( V_2 , false ) ;
F_32 ( 100 , 500 ) ;
F_17 ( V_2 , true ) ;
F_23 ( V_2 -> V_13 ) ;
F_14 ( V_2 ) ;
V_21:
F_33 ( & V_2 -> V_59 ) ;
V_70:
F_25 ( & V_2 -> V_49 ,
F_26 (
F_11 ( V_2 -> V_50 ) ) ) ;
}
static int F_40 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_41 ( V_73 ) ;
F_29 ( & V_2 -> V_59 ) ;
if ( ! V_2 -> V_74 )
F_24 ( V_2 ) ;
V_2 -> V_75 = true ;
F_33 ( & V_2 -> V_59 ) ;
return 0 ;
}
static void F_42 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_41 ( V_73 ) ;
F_29 ( & V_2 -> V_59 ) ;
if ( ! V_2 -> V_74 )
F_19 ( V_2 ) ;
V_2 -> V_75 = false ;
F_33 ( & V_2 -> V_59 ) ;
}
int F_43 ( struct V_51 * V_12 , int V_13 , const struct V_76 * V_77 ,
struct V_18 * V_18 ,
int (* V_43)( struct V_51 * V_12 , T_4 V_78 ) )
{
const struct V_79 * V_80 = F_44 ( V_12 ) ;
struct V_81 * V_82 = V_12 -> V_83 ;
struct V_1 * V_2 ;
struct V_72 * V_72 ;
unsigned int V_84 = V_22 ;
unsigned int V_85 = V_22 ;
unsigned int V_86 = V_22 ;
unsigned int V_87 = V_88 ;
unsigned int V_89 = V_90 ;
unsigned int V_91 = V_92 ;
unsigned int V_29 = V_93 ;
unsigned int V_50 ;
int error ;
if ( ! V_82 && ! V_80 ) {
F_45 ( V_12 , L_10 ) ;
return - V_94 ;
}
if ( V_13 <= 0 ) {
F_45 ( V_12 , L_11 ) ;
return - V_94 ;
}
if ( F_46 ( V_18 ) )
return F_47 ( V_18 ) ;
if ( ! V_43 ) {
F_45 ( V_12 , L_12 ) ;
return - V_94 ;
}
if ( V_80 ) {
V_87 = V_80 -> V_95 ;
V_89 = V_80 -> V_96 ;
V_91 = V_80 -> V_97 ;
V_84 = V_80 -> V_98 ;
V_85 = V_80 -> V_99 ;
V_86 = V_80 -> V_100 ;
V_29 = V_80 -> V_101 ;
V_50 = V_80 -> V_102 ;
} else {
V_29 = V_93 ;
F_48 ( V_82 , L_13 , & V_29 ) ;
V_50 = 0 ;
F_48 ( V_82 , L_14 ,
& V_50 ) ;
}
V_2 = F_49 ( V_12 , sizeof( * V_2 ) , V_103 ) ;
if ( ! V_2 )
return - V_104 ;
V_72 = F_50 ( V_12 ) ;
if ( ! V_72 )
return - V_104 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_6 = V_72 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_47 = F_51 ( V_12 , L_15 , V_105 ) ;
if ( F_46 ( V_2 -> V_47 ) ) {
error = F_47 ( V_2 -> V_47 ) ;
F_45 ( V_12 , L_16 , error ) ;
return error ;
}
V_2 -> V_106 = F_52 ( V_12 , L_17 ) ;
if ( F_46 ( V_2 -> V_106 ) ) {
error = F_47 ( V_2 -> V_106 ) ;
F_45 ( V_12 , L_18 , error ) ;
return error ;
}
if ( ! V_2 -> V_47 && V_80 )
V_2 -> V_48 = V_80 -> V_48 ;
F_53 ( & V_2 -> V_59 ) ;
F_54 ( & V_2 -> V_30 ) ;
F_55 ( & V_2 -> V_31 , F_13 , ( unsigned long ) V_2 ) ;
F_56 ( & V_2 -> V_49 , F_36 ) ;
snprintf ( V_2 -> V_107 , sizeof( V_2 -> V_107 ) ,
L_19 , F_57 ( V_12 ) ) ;
if ( V_77 -> V_108 == 2004 ) {
V_72 -> V_109 = L_20 ;
} else {
V_72 -> V_109 = F_58 ( V_12 , V_103 ,
L_21 ,
V_77 -> V_108 ) ;
if ( ! V_72 -> V_109 )
return - V_104 ;
}
V_72 -> V_107 = V_2 -> V_107 ;
V_72 -> V_110 = * V_77 ;
V_72 -> V_12 . V_111 = V_12 ;
V_72 -> V_112 [ 0 ] = F_59 ( V_113 ) | F_59 ( V_114 ) ;
V_72 -> V_115 [ F_60 ( V_11 ) ] = F_61 ( V_11 ) ;
F_62 ( V_72 , V_7 , 0 , V_84 , V_87 , 0 ) ;
F_62 ( V_72 , V_8 , 0 , V_85 , V_89 , 0 ) ;
F_62 ( V_72 , V_9 , 0 , V_86 , V_91 , 0 ) ;
if ( V_82 )
F_63 ( V_72 , false , NULL ) ;
V_72 -> V_116 = F_40 ;
V_72 -> V_117 = F_42 ;
F_64 ( V_72 , V_2 ) ;
F_16 ( V_2 ) ;
error = F_65 ( V_12 , V_13 , NULL ,
F_6 ,
V_118 | V_119 ,
L_22 , V_2 ) ;
if ( error ) {
F_45 ( V_12 , L_23 , error ) ;
return error ;
}
if ( V_2 -> V_106 ) {
error = F_66 ( V_2 -> V_106 ) ;
if ( error )
return error ;
}
F_67 ( V_12 , V_2 ) ;
error = F_68 ( & V_12 -> V_62 , & V_120 ) ;
if ( error ) {
F_45 ( V_12 ,
L_24 , error ) ;
goto V_121;
}
error = F_69 ( V_2 -> V_6 ) ;
if ( error ) {
F_45 ( V_12 ,
L_25 , error ) ;
goto V_122;
}
F_70 ( V_13 , 1 ) ;
return 0 ;
V_122:
F_71 ( & V_12 -> V_62 , & V_120 ) ;
V_121:
if ( V_2 -> V_106 )
F_72 ( V_2 -> V_106 ) ;
return error ;
}
int F_73 ( struct V_51 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_12 ) ;
F_71 ( & V_12 -> V_62 , & V_120 ) ;
if ( V_2 -> V_106 )
F_72 ( V_2 -> V_106 ) ;
return 0 ;
}
static int T_5 F_74 ( struct V_51 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_12 ) ;
F_29 ( & V_2 -> V_59 ) ;
if ( ! V_2 -> V_74 && V_2 -> V_75 )
F_19 ( V_2 ) ;
V_2 -> V_74 = true ;
F_33 ( & V_2 -> V_59 ) ;
return 0 ;
}
static int T_5 F_75 ( struct V_51 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_12 ) ;
F_29 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_74 && V_2 -> V_75 )
F_24 ( V_2 ) ;
V_2 -> V_74 = false ;
F_33 ( & V_2 -> V_59 ) ;
return 0 ;
}
