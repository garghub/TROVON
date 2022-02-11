static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int error ;
V_2 -> V_6 = F_2 ( V_4 ) ;
if ( ! V_2 -> V_6 ) {
F_3 ( V_4 ,
L_1 ) ;
return - V_7 ;
}
F_4 ( V_2 -> V_6 , V_8 , 0 , 4095 , 0 , 0 ) ;
F_4 ( V_2 -> V_6 , V_9 , 0 , 4095 , 0 , 0 ) ;
F_5 ( V_2 -> V_6 , true , & V_2 -> V_10 ) ;
F_6 ( V_2 -> V_6 , V_2 -> V_11 ,
V_12 | V_13 |
V_14 ) ;
V_2 -> V_6 -> V_15 = V_16 ;
V_2 -> V_6 -> V_17 = L_2 ;
V_2 -> V_6 -> V_18 . V_19 = V_20 ;
error = F_7 ( V_2 -> V_6 ) ;
if ( error ) {
F_3 ( V_4 , L_3 , error ) ;
return error ;
}
return 0 ;
}
static void F_8 ( struct V_21 * V_5 ,
enum V_22 V_23 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
if ( V_2 -> V_24 ) {
F_10 ( V_2 -> V_24 , V_23 ) ;
F_11 ( V_25 ) ;
}
}
static void F_12 ( struct V_21 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
struct V_26 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 = & V_5 -> V_4 ;
T_1 * V_27 , V_28 [ V_29 ] ;
int V_30 , error , V_31 ;
error = F_13 ( V_5 , V_32 ,
V_29 , V_28 ) ;
if ( error < 0 ) {
F_3 ( V_4 , L_4 , error ) ;
return;
}
V_30 = V_28 [ 0 ] ;
if ( V_30 > V_2 -> V_11 ) {
F_14 ( V_4 , L_5 ,
V_30 , V_2 -> V_11 ) ;
V_30 = V_2 -> V_11 ;
}
V_27 = V_28 + V_33 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ , V_27 += V_33 ) {
V_2 -> V_18 [ V_31 ] = ( V_27 [ V_34 ] &
V_35 ) >> 4 ;
F_15 ( & V_2 -> V_36 [ V_31 ] , & V_2 -> V_10 ,
F_16 ( & V_27 [ V_37 ] ) & 0xfff ,
F_16 ( & V_27 [ V_38 ] ) & 0xfff ) ;
}
F_17 ( V_6 , V_2 -> V_39 , V_2 -> V_36 , V_30 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
F_18 ( V_6 , V_2 -> V_39 [ V_31 ] ) ;
F_19 ( V_6 , V_40 , true ) ;
F_20 ( V_6 , V_8 , V_2 -> V_36 [ V_31 ] . V_41 ) ;
F_20 ( V_6 , V_9 , V_2 -> V_36 [ V_31 ] . V_42 ) ;
F_21 ( V_4 , L_6 , V_2 -> V_36 [ V_31 ] . V_41 ,
V_2 -> V_36 [ V_31 ] . V_42 , V_2 -> V_18 [ V_31 ] , V_2 -> V_39 [ V_31 ] ) ;
}
F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
}
static int F_24 ( struct V_21 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
int error ;
error = F_25 ( V_5 , V_43 ,
V_44 ) ;
if ( error )
goto V_45;
F_26 ( V_46 , V_47 ) ;
error = F_25 ( V_5 , V_48 ,
V_2 -> V_11 ) ;
if ( error )
goto V_45;
F_26 ( V_46 , V_47 ) ;
error = F_25 ( V_5 , V_49 ,
V_50 ) ;
if ( error )
goto V_45;
F_26 ( V_46 , V_47 ) ;
error = F_25 ( V_5 , V_43 ,
V_51 ) ;
if ( error )
goto V_45;
F_26 ( V_46 , V_47 ) ;
return 0 ;
V_45:
F_3 ( & V_5 -> V_4 , L_7 , error ) ;
return error ;
}
static int F_27 ( struct V_21 * V_5 )
{
int error ;
error = F_25 ( V_5 , V_43 ,
V_44 ) ;
if ( error )
goto V_45;
F_26 ( V_46 , V_47 ) ;
error = F_25 ( V_5 , V_49 ,
V_50 ) ;
if ( error )
goto V_45;
F_26 ( V_46 , V_47 ) ;
error = F_25 ( V_5 , V_52 ,
V_51 ) ;
if ( error )
goto V_45;
F_26 ( V_46 , V_47 ) ;
return 0 ;
V_45:
F_3 ( & V_5 -> V_4 , L_8 , error ) ;
return error ;
}
static int F_28 ( struct V_21 * V_5 )
{
int error ;
error = F_25 ( V_5 , V_43 , 0x00 ) ;
if ( error ) {
F_3 ( & V_5 -> V_4 , L_9 , error ) ;
return error ;
}
F_11 ( V_53 ) ;
return 0 ;
}
static int F_29 ( struct V_21 * V_5 )
{
struct V_3 * V_4 = & V_5 -> V_4 ;
struct V_1 * V_2 = F_9 ( V_5 ) ;
unsigned int V_54 , V_31 ;
const struct V_55 * V_56 ;
struct V_57 * V_58 ;
int error ;
F_21 ( V_4 , L_10 , V_2 -> V_59 ) ;
error = F_30 ( & V_56 , V_2 -> V_59 , V_4 ) ;
if ( error ) {
F_3 ( V_4 , L_11 , error ) ;
return error ;
}
V_54 = V_56 -> V_60 / sizeof( * V_58 ) ;
V_58 = (struct V_57 * ) V_56 -> V_2 ;
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ ) {
error = F_31 ( V_5 ,
V_58 [ V_31 ] . V_61 ,
4 ,
( T_1 * ) & V_58 [ V_31 ] . V_62 ) ;
if ( error ) {
F_3 ( V_4 , L_12 , error ) ;
break;
}
}
F_32 ( V_56 ) ;
return error ? : 0 ;
}
static T_2 F_33 ( struct V_21 * V_5 )
{
int error ;
T_3 V_63 ;
error = F_13 ( V_5 , V_64 ,
sizeof( V_63 ) , ( T_1 * ) & V_63 ) ;
if ( error < 0 ) {
F_3 ( & V_5 -> V_4 , L_13 , error ) ;
return error ;
}
return F_34 ( V_63 ) ;
}
static int F_35 ( struct V_21 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
T_3 V_65 ;
int error ;
error = F_13 ( V_5 , V_66 ,
sizeof( V_65 ) , ( T_1 * ) & V_65 ) ;
if ( error < 0 ) {
F_3 ( & V_5 -> V_4 , L_14 , error ) ;
return error ;
}
V_2 -> V_65 = F_34 ( V_65 ) ;
F_36 ( & V_5 -> V_4 , L_15 , V_2 -> V_65 ) ;
return 0 ;
}
static int F_37 ( struct V_21 * V_5 )
{
int error ;
T_2 V_63 ;
F_8 ( V_5 , V_67 ) ;
F_8 ( V_5 , V_68 ) ;
error = F_35 ( V_5 ) ;
if ( error )
return error ;
error = F_24 ( V_5 ) ;
if ( error )
return error ;
error = F_27 ( V_5 ) ;
if ( error )
return error ;
error = F_29 ( V_5 ) ;
if ( error )
return error ;
error = F_28 ( V_5 ) ;
if ( error )
return error ;
V_63 = F_33 ( V_5 ) ;
if ( V_63 != V_69 ) {
F_3 ( & V_5 -> V_4 ,
L_16 , V_63 ) ;
return - V_70 ;
}
return 0 ;
}
static T_4 F_38 ( int V_71 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
struct V_21 * V_5 = V_2 -> V_5 ;
F_12 ( V_5 ) ;
return V_72 ;
}
static void F_39 ( struct V_21 * V_5 )
{
struct V_1 * V_2 = F_9 ( V_5 ) ;
struct V_3 * V_4 = & V_5 -> V_4 ;
const char * V_73 ;
int error ;
error = F_40 ( V_4 , L_17 ,
& V_2 -> V_11 ) ;
if ( error ) {
F_21 ( V_4 , L_18 , error ) ;
V_2 -> V_11 = 5 ;
}
error = F_41 ( V_4 , L_19 , & V_73 ) ;
if ( ! error )
snprintf ( V_2 -> V_59 , sizeof( V_2 -> V_59 ) ,
L_20 , V_73 ) ;
else
F_21 ( V_4 , L_21 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_74 * V_18 )
{
const struct V_75 * V_76 ;
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
int V_31 ;
if ( F_43 ( V_4 ) ) {
V_76 = F_44 ( V_4 -> V_77 -> V_78 , V_4 ) ;
if ( ! V_76 )
return - V_70 ;
snprintf ( V_2 -> V_59 , sizeof( V_2 -> V_59 ) ,
L_22 , V_76 -> V_18 ) ;
for ( V_31 = 0 ; V_31 < strlen ( V_2 -> V_59 ) ; V_31 ++ )
V_2 -> V_59 [ V_31 ] = tolower ( V_2 -> V_59 [ V_31 ] ) ;
} else {
snprintf ( V_2 -> V_59 , sizeof( V_2 -> V_59 ) ,
L_22 , V_18 -> V_15 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_74 * V_18 )
{
snprintf ( V_2 -> V_59 , sizeof( V_2 -> V_59 ) ,
L_22 , V_18 -> V_15 ) ;
return 0 ;
}
static int F_45 ( struct V_21 * V_5 ,
const struct V_74 * V_18 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_5 -> V_4 ;
int error ;
if ( ! F_46 ( V_5 -> V_79 ,
V_80 |
V_81 |
V_82 ) ) {
F_3 ( V_4 , L_23 ) ;
return - V_83 ;
}
V_2 = F_47 ( V_4 , sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_7 ;
F_48 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
error = F_42 ( V_2 , V_18 ) ;
if ( error )
return error ;
F_39 ( V_5 ) ;
if ( V_5 -> V_71 <= 0 )
return - V_70 ;
V_2 -> V_24 = F_49 ( V_4 , L_24 , V_85 ) ;
if ( F_50 ( V_2 -> V_24 ) ) {
if ( F_51 ( V_2 -> V_24 ) != - V_86 )
F_3 ( V_4 , L_25 ) ;
return F_51 ( V_2 -> V_24 ) ;
}
error = F_37 ( V_5 ) ;
if ( error )
return error ;
error = F_1 ( V_2 ) ;
if ( error )
return error ;
error = F_52 ( V_4 , V_5 -> V_71 ,
NULL , F_38 ,
V_87 , V_5 -> V_15 , V_2 ) ;
if ( error ) {
if ( error != - V_86 )
F_3 ( V_4 , L_26 , error ) ;
return error ;
}
return 0 ;
}
static int T_5 F_53 ( struct V_3 * V_4 )
{
struct V_21 * V_5 = F_54 ( V_4 ) ;
F_8 ( V_5 , V_67 ) ;
return 0 ;
}
static int T_5 F_55 ( struct V_3 * V_4 )
{
struct V_21 * V_5 = F_54 ( V_4 ) ;
int error , V_63 ;
F_8 ( V_5 , V_68 ) ;
error = F_27 ( V_5 ) ;
if ( error )
return error ;
error = F_28 ( V_5 ) ;
if ( error )
return error ;
V_63 = F_33 ( V_5 ) ;
if ( V_63 != V_69 ) {
F_3 ( V_4 , L_27 , V_63 ) ;
return - V_70 ;
}
return 0 ;
}
