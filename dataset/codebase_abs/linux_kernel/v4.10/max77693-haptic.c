static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_5 ;
int error ;
F_2 ( V_2 -> V_6 , & V_4 ) ;
V_5 = ( V_4 . V_7 + V_2 -> V_8 ) / 2 ;
error = F_3 ( V_2 -> V_6 , V_5 , V_4 . V_7 ) ;
if ( error ) {
F_4 ( V_2 -> V_9 , L_1 , error ) ;
return error ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , bool V_10 )
{
int error ;
if ( V_2 -> V_11 != V_12 )
return 0 ;
error = F_6 ( V_2 -> V_13 ,
V_14 ,
V_15 ,
V_10 << V_16 ) ;
if ( error ) {
F_4 ( V_2 -> V_9 , L_2 ,
V_10 ? L_3 : L_4 , error ) ;
return error ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
bool V_17 )
{
unsigned int V_18 , V_19 ;
int error ;
switch ( V_2 -> V_11 ) {
case V_20 :
V_18 = ( ( V_2 -> type << V_21 ) |
( V_17 << V_22 ) |
( V_2 -> V_23 << V_24 ) |
V_25 ) ;
V_19 = V_26 ;
break;
case V_12 :
V_18 = ( V_2 -> type << V_27 ) |
( V_17 << V_28 ) |
V_25 ;
V_19 = V_29 ;
break;
default:
return - V_30 ;
}
error = F_8 ( V_2 -> V_13 ,
V_19 , V_18 ) ;
if ( error ) {
F_4 ( V_2 -> V_9 ,
L_5 , error ) ;
return error ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_17 )
{
int error ;
if ( V_2 -> V_11 != V_20 )
return 0 ;
error = F_6 ( V_2 -> V_31 ,
V_32 ,
V_33 ,
V_17 << V_34 ) ;
if ( error ) {
F_4 ( V_2 -> V_9 , L_6 , error ) ;
return error ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_35 )
return;
error = F_11 ( V_2 -> V_6 ) ;
if ( error ) {
F_4 ( V_2 -> V_9 ,
L_7 , error ) ;
return;
}
error = F_9 ( V_2 , true ) ;
if ( error )
goto V_36;
error = F_7 ( V_2 , true ) ;
if ( error )
goto V_37;
V_2 -> V_35 = true ;
return;
V_37:
F_9 ( V_2 , false ) ;
V_36:
F_12 ( V_2 -> V_6 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
int error ;
if ( ! V_2 -> V_35 )
return;
error = F_7 ( V_2 , false ) ;
if ( error )
return;
error = F_9 ( V_2 , false ) ;
if ( error )
goto V_38;
F_12 ( V_2 -> V_6 ) ;
V_2 -> V_35 = false ;
return;
V_38:
F_7 ( V_2 , true ) ;
}
static void F_14 ( struct V_39 * V_40 )
{
struct V_1 * V_2 =
F_15 ( V_40 , struct V_1 , V_40 ) ;
int error ;
error = F_1 ( V_2 ) ;
if ( error ) {
F_4 ( V_2 -> V_9 , L_8 , error ) ;
return;
}
if ( V_2 -> V_41 )
F_10 ( V_2 ) ;
else
F_13 ( V_2 ) ;
}
static int F_16 ( struct V_42 * V_9 , void * V_43 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_17 ( V_9 ) ;
struct V_3 V_4 ;
T_1 V_46 ;
V_2 -> V_41 = V_45 -> V_47 . V_48 . V_49 ;
if ( ! V_2 -> V_41 )
V_2 -> V_41 = V_45 -> V_47 . V_48 . V_50 ;
F_2 ( V_2 -> V_6 , & V_4 ) ;
V_46 = ( T_1 ) V_4 . V_7 * V_2 -> V_41 ;
V_2 -> V_8 = ( unsigned int ) ( V_46 >>
V_51 ) ;
F_18 ( & V_2 -> V_40 ) ;
return 0 ;
}
static int F_19 ( struct V_42 * V_9 )
{
struct V_1 * V_2 = F_17 ( V_9 ) ;
int error ;
error = F_5 ( V_2 , true ) ;
if ( error )
return error ;
error = F_20 ( V_2 -> V_52 ) ;
if ( error ) {
F_4 ( V_2 -> V_9 ,
L_9 , error ) ;
return error ;
}
return 0 ;
}
static void F_21 ( struct V_42 * V_9 )
{
struct V_1 * V_2 = F_17 ( V_9 ) ;
int error ;
F_22 ( & V_2 -> V_40 ) ;
F_13 ( V_2 ) ;
error = F_23 ( V_2 -> V_52 ) ;
if ( error )
F_4 ( V_2 -> V_9 ,
L_10 , error ) ;
F_5 ( V_2 , false ) ;
}
static int F_24 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_25 ( V_54 -> V_9 . V_57 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_26 ( & V_54 -> V_9 , sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_31 = V_56 -> V_60 ;
V_2 -> V_9 = & V_54 -> V_9 ;
V_2 -> type = V_61 ;
V_2 -> V_23 = V_62 ;
V_2 -> V_63 = false ;
V_2 -> V_11 = F_27 ( V_54 ) -> V_64 ;
switch ( V_2 -> V_11 ) {
case V_20 :
V_2 -> V_13 = V_56 -> V_13 ;
break;
case V_12 :
V_2 -> V_13 = V_56 -> V_60 ;
break;
default:
F_4 ( & V_54 -> V_9 , L_11 ,
V_2 -> V_11 ) ;
return - V_30 ;
}
F_28 ( & V_2 -> V_40 , F_14 ) ;
V_2 -> V_6 = F_29 ( & V_54 -> V_9 , NULL ) ;
if ( F_30 ( V_2 -> V_6 ) ) {
F_4 ( & V_54 -> V_9 , L_12 ) ;
return F_31 ( V_2 -> V_6 ) ;
}
F_32 ( V_2 -> V_6 ) ;
V_2 -> V_52 = F_33 ( & V_54 -> V_9 , L_13 ) ;
if ( F_30 ( V_2 -> V_52 ) ) {
F_4 ( & V_54 -> V_9 , L_14 ) ;
return F_31 ( V_2 -> V_52 ) ;
}
V_2 -> V_42 = F_34 ( & V_54 -> V_9 ) ;
if ( ! V_2 -> V_42 ) {
F_4 ( & V_54 -> V_9 , L_15 ) ;
return - V_59 ;
}
V_2 -> V_42 -> V_65 = L_16 ;
V_2 -> V_42 -> V_66 . V_67 = 1 ;
V_2 -> V_42 -> V_9 . V_57 = & V_54 -> V_9 ;
V_2 -> V_42 -> V_68 = F_19 ;
V_2 -> V_42 -> V_69 = F_21 ;
F_35 ( V_2 -> V_42 , V_2 ) ;
F_36 ( V_2 -> V_42 , V_70 , V_71 ) ;
error = F_37 ( V_2 -> V_42 , NULL ,
F_16 ) ;
if ( error ) {
F_4 ( & V_54 -> V_9 , L_17 ) ;
return error ;
}
error = F_38 ( V_2 -> V_42 ) ;
if ( error ) {
F_4 ( & V_54 -> V_9 , L_18 ) ;
return error ;
}
F_39 ( V_54 , V_2 ) ;
return 0 ;
}
static int T_2 F_40 ( struct V_72 * V_9 )
{
struct V_53 * V_54 = F_41 ( V_9 ) ;
struct V_1 * V_2 = F_42 ( V_54 ) ;
if ( V_2 -> V_35 ) {
F_13 ( V_2 ) ;
V_2 -> V_63 = true ;
}
return 0 ;
}
static int T_2 F_43 ( struct V_72 * V_9 )
{
struct V_53 * V_54 = F_41 ( V_9 ) ;
struct V_1 * V_2 = F_42 ( V_54 ) ;
if ( V_2 -> V_63 ) {
F_10 ( V_2 ) ;
V_2 -> V_63 = false ;
}
return 0 ;
}
