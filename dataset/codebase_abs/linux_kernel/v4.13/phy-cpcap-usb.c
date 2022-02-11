static bool F_1 ( struct V_1 * V_2 )
{
int error , V_3 = 0 ;
error = F_2 ( V_2 -> V_4 , & V_3 ) ;
if ( error >= 0 )
return V_3 > 3900 ? true : false ;
F_3 ( V_2 -> V_5 , L_1 , error ) ;
return false ;
}
static int F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
V_7 -> V_9 = V_9 ;
if ( ! V_9 )
V_7 -> V_10 = V_11 ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 ,
struct V_12 * V_13 )
{
V_7 -> V_13 = V_13 ;
if ( ! V_13 )
V_7 -> V_10 = V_11 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_16 , error ;
error = F_7 ( V_2 -> V_17 , V_18 , & V_16 ) ;
if ( error )
return error ;
V_15 -> V_19 = V_16 & F_8 ( 15 ) ;
V_15 -> V_20 = V_16 & F_8 ( 14 ) ;
V_15 -> V_21 = V_16 & F_8 ( 11 ) ;
error = F_7 ( V_2 -> V_17 , V_22 , & V_16 ) ;
if ( error )
return error ;
V_15 -> V_23 = V_16 & F_8 ( 3 ) ;
V_15 -> V_24 = V_16 & F_8 ( 2 ) ;
V_15 -> V_25 = V_16 & F_8 ( 1 ) ;
V_15 -> V_26 = V_16 & F_8 ( 0 ) ;
error = F_7 ( V_2 -> V_17 , V_27 , & V_16 ) ;
if ( error )
return error ;
V_15 -> V_28 = V_16 & F_8 ( 1 ) ;
V_15 -> V_29 = V_16 & F_8 ( 0 ) ;
return 0 ;
}
static void F_9 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_14 V_15 ;
bool V_4 = false ;
int error ;
V_2 = F_10 ( V_31 , struct V_1 , V_32 . V_31 ) ;
error = F_6 ( V_2 , & V_15 ) ;
if ( error )
return;
if ( V_15 . V_19 ) {
F_11 ( V_2 -> V_5 , L_2 ) ;
error = F_12 ( V_2 ) ;
if ( error )
goto V_33;
error = F_13 ( V_34 ) ;
if ( error )
goto V_33;
error = F_14 ( V_2 -> V_17 , V_35 ,
V_36 ,
V_36 ) ;
if ( error )
goto V_33;
return;
}
error = F_14 ( V_2 -> V_17 , V_35 ,
V_36 , 0 ) ;
if ( error )
goto V_33;
V_4 = F_1 ( V_2 ) ;
if ( V_4 ) {
if ( V_15 . V_19 ) {
F_11 ( V_2 -> V_5 , L_3 ) ;
error = F_12 ( V_2 ) ;
if ( error )
goto V_33;
error = F_13 ( V_34 ) ;
if ( error )
goto V_33;
return;
}
F_11 ( V_2 -> V_5 , L_4 ) ;
error = F_12 ( V_2 ) ;
if ( error )
goto V_33;
error = F_13 ( V_37 ) ;
if ( error )
goto V_33;
return;
}
error = F_15 ( V_2 ) ;
if ( error )
goto V_33;
error = F_13 ( V_38 ) ;
if ( error )
goto V_33;
F_11 ( V_2 -> V_5 , L_5 ) ;
return;
V_33:
F_3 ( V_2 -> V_5 , L_6 , error ) ;
}
static T_1 F_16 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
if ( ! F_17 ( & V_2 -> V_41 ) )
return V_42 ;
F_18 ( & V_2 -> V_32 , F_19 ( 1 ) ) ;
return V_43 ;
}
static int F_20 ( struct V_44 * V_45 ,
struct V_1 * V_2 ,
const char * V_46 )
{
int V_39 , error ;
V_39 = F_21 ( V_45 , V_46 ) ;
if ( ! V_39 )
return - V_47 ;
error = F_22 ( V_2 -> V_5 , V_39 , NULL ,
F_16 ,
V_48 ,
V_46 , V_2 ) ;
if ( error ) {
F_3 ( V_2 -> V_5 , L_7 ,
V_46 , error ) ;
return error ;
}
return 0 ;
}
static int F_23 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
int V_49 , error ;
for ( V_49 = 0 ; V_49 < F_24 ( V_50 ) ; V_49 ++ ) {
error = F_20 ( V_45 , V_2 , V_50 [ V_49 ] ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_51 V_52 )
{
if ( ! V_2 -> V_53 [ 0 ] || ! V_2 -> V_53 [ 1 ] )
return 0 ;
F_26 ( V_2 -> V_53 [ 0 ] , V_52 & 1 ) ;
F_26 ( V_2 -> V_53 [ 1 ] , V_52 >> 1 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int error ;
error = F_25 ( V_2 , V_54 ) ;
if ( error )
goto V_33;
if ( V_2 -> V_55 ) {
error = F_27 ( V_2 -> V_56 , V_2 -> V_55 ) ;
if ( error )
goto V_33;
}
error = F_14 ( V_2 -> V_17 , V_57 ,
V_58 ,
V_58 ) ;
if ( error )
goto V_33;
error = F_14 ( V_2 -> V_17 , V_59 ,
0xffff , V_60 |
V_61 ) ;
if ( error )
goto V_33;
error = F_14 ( V_2 -> V_17 , V_35 , 0x7fff ,
V_62 ) ;
if ( error )
goto V_33;
return 0 ;
V_33:
F_3 ( V_2 -> V_5 , L_8 , V_63 , error ) ;
return error ;
}
static int F_12 ( struct V_1 * V_2 )
{
int error ;
error = F_25 ( V_2 , V_64 ) ;
if ( error )
return error ;
if ( V_2 -> V_65 ) {
error = F_27 ( V_2 -> V_56 , V_2 -> V_65 ) ;
if ( error ) {
F_3 ( V_2 -> V_5 , L_9 ,
error ) ;
return error ;
}
}
error = F_14 ( V_2 -> V_17 , V_57 ,
V_58 , 0 ) ;
if ( error )
goto V_33;
error = F_14 ( V_2 -> V_17 , V_59 ,
V_66 ,
V_66 ) ;
if ( error )
goto V_33;
error = F_14 ( V_2 -> V_17 , V_35 ,
V_67 |
V_68 |
V_69 |
V_70 |
V_71 , 0 ) ;
if ( error )
goto V_33;
error = F_14 ( V_2 -> V_17 , V_59 ,
V_66 ,
V_66 ) ;
if ( error )
goto V_33;
return 0 ;
V_33:
F_3 ( V_2 -> V_5 , L_8 , V_63 , error ) ;
return error ;
}
static int F_28 ( struct V_1 * V_2 )
{
V_2 -> V_56 = F_29 ( V_2 -> V_5 ) ;
if ( F_30 ( V_2 -> V_56 ) ) {
F_31 ( V_2 -> V_5 , L_10 ,
F_32 ( V_2 -> V_56 ) ) ;
V_2 -> V_56 = NULL ;
return 0 ;
}
V_2 -> V_72 = F_33 ( V_2 -> V_56 , L_11 ) ;
if ( F_30 ( V_2 -> V_72 ) ) {
F_31 ( V_2 -> V_5 , L_12 ) ;
V_2 -> V_72 = NULL ;
}
V_2 -> V_65 = F_33 ( V_2 -> V_56 , L_13 ) ;
if ( F_30 ( V_2 -> V_65 ) ) {
F_31 ( V_2 -> V_5 , L_14 ) ;
V_2 -> V_65 = NULL ;
}
V_2 -> V_55 = F_33 ( V_2 -> V_56 , L_15 ) ;
if ( F_30 ( V_2 -> V_55 ) ) {
F_31 ( V_2 -> V_5 , L_16 ) ;
V_2 -> V_55 = NULL ;
}
if ( V_2 -> V_55 )
return F_27 ( V_2 -> V_56 , V_2 -> V_55 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
V_2 -> V_53 [ V_49 ] = F_35 ( V_2 -> V_5 , L_17 ,
V_49 , V_73 ) ;
if ( F_30 ( V_2 -> V_53 [ V_49 ] ) ) {
F_31 ( V_2 -> V_5 , L_18 ,
V_49 , F_32 ( V_2 -> V_53 [ V_49 ] ) ) ;
V_2 -> V_53 [ V_49 ] = NULL ;
}
}
}
static int F_36 ( struct V_1 * V_2 )
{
enum V_74 type ;
int error ;
V_2 -> V_4 = F_37 ( V_2 -> V_5 , L_19 ) ;
if ( F_30 ( V_2 -> V_4 ) ) {
error = F_32 ( V_2 -> V_4 ) ;
goto V_33;
}
if ( ! V_2 -> V_4 -> V_75 ) {
error = - V_76 ;
goto V_33;
}
error = F_38 ( V_2 -> V_4 , & type ) ;
if ( error < 0 )
goto V_33;
if ( type != V_77 ) {
error = - V_78 ;
goto V_33;
}
return 0 ;
V_33:
F_3 ( V_2 -> V_5 , L_20 ,
error ) ;
return error ;
}
static int F_39 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
struct V_79 * V_80 ;
struct V_81 * V_81 ;
struct V_6 * V_7 ;
const struct V_82 * V_83 ;
int error ;
V_83 = F_40 ( F_41 ( V_84 ) ,
& V_45 -> V_5 ) ;
if ( ! V_83 )
return - V_78 ;
V_2 = F_42 ( & V_45 -> V_5 , sizeof( * V_2 ) , V_85 ) ;
if ( ! V_2 )
return - V_86 ;
V_2 -> V_17 = F_43 ( V_45 -> V_5 . V_87 , NULL ) ;
if ( ! V_2 -> V_17 )
return - V_47 ;
V_7 = F_42 ( & V_45 -> V_5 , sizeof( * V_7 ) , V_85 ) ;
if ( ! V_7 )
return - V_86 ;
V_2 -> V_5 = & V_45 -> V_5 ;
V_2 -> V_79 . V_5 = V_2 -> V_5 ;
V_2 -> V_79 . V_88 = L_21 ;
V_2 -> V_79 . V_7 = V_7 ;
V_2 -> V_79 . type = V_89 ;
V_7 -> V_90 = F_4 ;
V_7 -> V_91 = F_5 ;
V_7 -> V_92 = & V_2 -> V_79 ;
F_44 ( & V_2 -> V_32 , F_9 ) ;
F_45 ( V_45 , V_2 ) ;
V_2 -> V_93 = F_46 ( & V_45 -> V_5 , L_22 ) ;
if ( F_30 ( V_2 -> V_93 ) )
return F_32 ( V_2 -> V_93 ) ;
error = F_47 ( V_2 -> V_93 ) ;
if ( error )
return error ;
V_80 = F_48 ( V_2 -> V_5 , NULL , & V_94 ) ;
if ( F_30 ( V_80 ) ) {
error = F_32 ( V_80 ) ;
return F_32 ( V_80 ) ;
}
F_49 ( V_80 , V_2 ) ;
V_81 = F_50 ( V_2 -> V_5 ,
V_95 ) ;
if ( F_30 ( V_81 ) )
return F_32 ( V_81 ) ;
error = F_28 ( V_2 ) ;
if ( error )
return error ;
F_34 ( V_2 ) ;
error = F_36 ( V_2 ) ;
if ( error )
return error ;
error = F_23 ( V_45 , V_2 ) ;
if ( error )
return error ;
F_51 ( & V_2 -> V_79 ) ;
F_52 ( & V_2 -> V_41 , 1 ) ;
F_18 ( & V_2 -> V_32 , F_19 ( 1 ) ) ;
return 0 ;
}
static int F_53 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_54 ( V_45 ) ;
int error ;
F_52 ( & V_2 -> V_41 , 0 ) ;
error = F_15 ( V_2 ) ;
if ( error )
F_3 ( V_2 -> V_5 , L_23 ) ;
error = F_13 ( V_38 ) ;
if ( error )
F_3 ( V_2 -> V_5 , L_24 ) ;
F_55 ( & V_2 -> V_79 ) ;
F_56 ( & V_2 -> V_32 ) ;
F_57 ( V_2 -> V_96 ) ;
F_58 ( V_2 -> V_93 ) ;
return 0 ;
}
