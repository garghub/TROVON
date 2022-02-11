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
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_18 ( V_2 -> V_46 , 1 ) ;
F_19 ( 100 , 500 ) ;
F_18 ( V_2 -> V_46 , 0 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_21 ( V_2 -> V_13 ) ;
F_22 ( & V_2 -> V_31 ) ;
F_23 ( & V_2 -> V_47 ) ;
F_24 ( V_2 -> V_13 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
if ( V_2 -> V_48 && V_2 -> V_46 ) {
V_2 -> V_34 = V_32 ;
F_26 ( & V_2 -> V_47 ,
F_27 (
F_11 ( V_2 -> V_48 ) ) ) ;
}
}
static T_2 F_28 ( struct V_49 * V_12 ,
struct V_50 * V_51 ,
char * V_52 )
{
struct V_1 * V_2 = F_29 ( V_12 ) ;
unsigned int V_53 ;
unsigned int V_54 ;
unsigned int V_55 ;
bool V_56 = true ;
int error ;
F_30 ( & V_2 -> V_57 ) ;
F_20 ( V_2 ) ;
error = F_31 ( V_2 -> V_18 , V_58 , & V_54 ) ;
if ( error ) {
F_32 ( V_12 , L_2 , error ) ;
V_56 = false ;
goto V_21;
}
V_55 = ( V_54 - 1 ) & V_22 ;
error = F_15 ( V_2 -> V_18 , V_58 , V_55 ) ;
if ( error ) {
F_32 ( V_12 , L_3 , error ) ;
V_56 = false ;
goto V_21;
}
error = F_31 ( V_2 -> V_18 , V_58 , & V_53 ) ;
if ( error ) {
F_32 ( V_12 , L_4 ,
error ) ;
V_56 = false ;
goto V_21;
}
if ( V_53 != V_55 ) {
F_32 ( V_12 , L_5 ,
V_53 , V_55 ) ;
V_56 = false ;
}
F_17 ( V_2 ) ;
if ( ! V_56 )
goto V_21;
error = F_31 ( V_2 -> V_18 , V_58 , & V_53 ) ;
if ( error ) {
F_32 ( V_12 , L_6 ,
error ) ;
V_56 = false ;
goto V_21;
}
if ( V_53 != V_54 ) {
F_32 ( V_12 , L_7 ,
V_53 , V_54 ) ;
V_56 = false ;
}
V_21:
F_25 ( V_2 ) ;
F_33 ( & V_2 -> V_57 ) ;
return sprintf ( V_52 , L_8 , V_56 ) ;
}
static T_3 F_34 ( struct V_59 * V_60 ,
struct V_61 * V_51 , int V_62 )
{
struct V_49 * V_12 = F_35 ( V_60 , struct V_49 , V_60 ) ;
struct V_1 * V_2 = F_29 ( V_12 ) ;
T_3 V_63 = V_51 -> V_63 ;
if ( V_51 == & V_64 . V_51 ) {
if ( ! V_2 -> V_46 )
V_63 = 0 ;
}
return V_63 ;
}
static void F_36 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_35 ( V_66 , struct V_1 , V_47 . V_66 ) ;
int error ;
unsigned int V_67 ;
if ( ! F_37 ( & V_2 -> V_57 ) ) {
goto V_68;
}
if ( F_38 ( V_2 -> V_34 +
F_11 ( V_2 -> V_48 ) ) )
goto V_21;
error = F_31 ( V_2 -> V_18 , V_37 , & V_67 ) ;
if ( ! error &&
! ( ( V_67 ^ V_38 ) & V_69 ) ) {
goto V_21;
}
F_39 ( V_2 -> V_12 , L_9 ) ;
F_21 ( V_2 -> V_13 ) ;
F_22 ( & V_2 -> V_31 ) ;
F_1 ( V_2 , 0 , 0 , 0 ) ;
F_17 ( V_2 ) ;
F_24 ( V_2 -> V_13 ) ;
F_14 ( V_2 ) ;
V_21:
F_33 ( & V_2 -> V_57 ) ;
V_68:
F_26 ( & V_2 -> V_47 ,
F_27 (
F_11 ( V_2 -> V_48 ) ) ) ;
}
static int F_40 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_41 ( V_71 ) ;
F_30 ( & V_2 -> V_57 ) ;
if ( ! V_2 -> V_72 )
F_25 ( V_2 ) ;
V_2 -> V_73 = true ;
F_33 ( & V_2 -> V_57 ) ;
return 0 ;
}
static void F_42 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_41 ( V_71 ) ;
F_30 ( & V_2 -> V_57 ) ;
if ( ! V_2 -> V_72 )
F_20 ( V_2 ) ;
V_2 -> V_73 = false ;
F_33 ( & V_2 -> V_57 ) ;
}
int F_43 ( struct V_49 * V_12 , int V_13 , const struct V_74 * V_75 ,
struct V_18 * V_18 ,
int (* V_43)( struct V_49 * V_12 , T_4 V_76 ) )
{
struct V_1 * V_2 ;
struct V_70 * V_70 ;
T_5 V_29 ;
T_5 V_48 ;
int error ;
if ( V_13 <= 0 ) {
F_44 ( V_12 , L_10 ) ;
return - V_77 ;
}
if ( F_45 ( V_18 ) )
return F_46 ( V_18 ) ;
if ( ! V_43 ) {
F_44 ( V_12 , L_11 ) ;
return - V_77 ;
}
V_2 = F_47 ( V_12 , sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
V_70 = F_48 ( V_12 ) ;
if ( ! V_70 )
return - V_79 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_6 = V_70 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_43 = V_43 ;
error = F_49 ( V_12 , L_12 , & V_29 ) ;
V_2 -> V_29 = error ? V_80 : V_29 ;
error = F_49 ( V_12 , L_13 ,
& V_48 ) ;
V_2 -> V_48 = error ? 0 : V_48 ;
V_2 -> V_46 = F_50 ( V_12 , L_14 , V_81 ) ;
if ( F_45 ( V_2 -> V_46 ) ) {
error = F_46 ( V_2 -> V_46 ) ;
F_44 ( V_12 , L_15 , error ) ;
return error ;
}
V_2 -> V_82 = F_51 ( V_12 , L_16 ) ;
if ( F_45 ( V_2 -> V_82 ) ) {
error = F_46 ( V_2 -> V_82 ) ;
F_44 ( V_12 , L_17 , error ) ;
return error ;
}
F_52 ( & V_2 -> V_57 ) ;
F_53 ( & V_2 -> V_30 ) ;
F_54 ( & V_2 -> V_31 , F_13 , ( unsigned long ) V_2 ) ;
F_55 ( & V_2 -> V_47 , F_36 ) ;
snprintf ( V_2 -> V_83 , sizeof( V_2 -> V_83 ) ,
L_18 , F_56 ( V_12 ) ) ;
if ( V_75 -> V_84 == 2004 ) {
V_70 -> V_85 = L_19 ;
} else {
V_70 -> V_85 = F_57 ( V_12 , V_78 ,
L_20 ,
V_75 -> V_84 ) ;
if ( ! V_70 -> V_85 )
return - V_79 ;
}
V_70 -> V_83 = V_2 -> V_83 ;
V_70 -> V_86 = * V_75 ;
V_70 -> V_87 = F_40 ;
V_70 -> V_88 = F_42 ;
F_58 ( V_70 , V_2 ) ;
F_59 ( V_89 , V_70 -> V_90 ) ;
F_60 ( V_70 , V_91 , V_11 ) ;
F_61 ( V_70 , V_7 ,
0 , V_22 , V_92 , 0 ) ;
F_61 ( V_70 , V_8 ,
0 , V_22 , V_93 , 0 ) ;
F_61 ( V_70 , V_9 ,
0 , V_22 , V_94 , 0 ) ;
F_62 ( V_70 , false , NULL ) ;
F_16 ( V_2 ) ;
error = F_63 ( V_12 , V_13 , NULL ,
F_6 ,
V_95 | V_96 ,
L_21 , V_2 ) ;
if ( error ) {
F_44 ( V_12 , L_22 , error ) ;
return error ;
}
error = F_64 ( V_2 -> V_82 ) ;
if ( error )
return error ;
F_65 ( V_12 , V_2 ) ;
error = F_66 ( & V_12 -> V_60 , & V_97 ) ;
if ( error ) {
F_44 ( V_12 ,
L_23 , error ) ;
goto V_98;
}
error = F_67 ( V_2 -> V_6 ) ;
if ( error ) {
F_44 ( V_12 ,
L_24 , error ) ;
goto V_99;
}
F_68 ( V_13 , 1 ) ;
return 0 ;
V_99:
F_69 ( & V_12 -> V_60 , & V_97 ) ;
V_98:
F_70 ( V_2 -> V_82 ) ;
return error ;
}
int F_71 ( struct V_49 * V_12 )
{
struct V_1 * V_2 = F_29 ( V_12 ) ;
F_69 ( & V_12 -> V_60 , & V_97 ) ;
F_70 ( V_2 -> V_82 ) ;
return 0 ;
}
static int T_6 F_72 ( struct V_49 * V_12 )
{
struct V_1 * V_2 = F_29 ( V_12 ) ;
F_30 ( & V_2 -> V_57 ) ;
if ( ! V_2 -> V_72 && V_2 -> V_73 )
F_20 ( V_2 ) ;
V_2 -> V_72 = true ;
F_33 ( & V_2 -> V_57 ) ;
return 0 ;
}
static int T_6 F_73 ( struct V_49 * V_12 )
{
struct V_1 * V_2 = F_29 ( V_12 ) ;
F_30 ( & V_2 -> V_57 ) ;
if ( V_2 -> V_72 && V_2 -> V_73 )
F_25 ( V_2 ) ;
V_2 -> V_72 = false ;
F_33 ( & V_2 -> V_57 ) ;
return 0 ;
}
