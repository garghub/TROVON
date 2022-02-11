static int F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 -> V_5 + V_2 -> V_6 ) / 2 ;
int error ;
error = F_2 ( V_2 -> V_4 , V_3 , V_2 -> V_4 -> V_5 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 , L_1 , error ) ;
return error ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , bool V_8 )
{
int error ;
if ( V_2 -> V_9 != V_10 )
return 0 ;
error = F_5 ( V_2 -> V_11 ,
V_12 ,
V_13 ,
V_8 << V_14 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 , L_2 ,
V_8 ? L_3 : L_4 , error ) ;
return error ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
bool V_15 )
{
unsigned int V_16 , V_17 ;
int error ;
switch ( V_2 -> V_9 ) {
case V_18 :
V_16 = ( ( V_2 -> type << V_19 ) |
( V_15 << V_20 ) |
( V_2 -> V_21 << V_22 ) |
V_23 ) ;
V_17 = V_24 ;
break;
case V_10 :
V_16 = ( V_2 -> type << V_25 ) |
( V_15 << V_26 ) |
V_23 ;
V_17 = V_27 ;
break;
default:
return - V_28 ;
}
error = F_7 ( V_2 -> V_11 ,
V_17 , V_16 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_5 , error ) ;
return error ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , bool V_15 )
{
int error ;
if ( V_2 -> V_9 != V_18 )
return 0 ;
error = F_5 ( V_2 -> V_29 ,
V_30 ,
V_31 ,
V_15 << V_32 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 , L_6 , error ) ;
return error ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_33 )
return;
error = F_10 ( V_2 -> V_4 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_7 , error ) ;
return;
}
error = F_8 ( V_2 , true ) ;
if ( error )
goto V_34;
error = F_6 ( V_2 , true ) ;
if ( error )
goto V_35;
V_2 -> V_33 = true ;
return;
V_35:
F_8 ( V_2 , false ) ;
V_34:
F_11 ( V_2 -> V_4 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
int error ;
if ( ! V_2 -> V_33 )
return;
error = F_6 ( V_2 , false ) ;
if ( error )
return;
error = F_8 ( V_2 , false ) ;
if ( error )
goto V_36;
F_11 ( V_2 -> V_4 ) ;
V_2 -> V_33 = false ;
return;
V_36:
F_6 ( V_2 , true ) ;
}
static void F_13 ( struct V_37 * V_38 )
{
struct V_1 * V_2 =
F_14 ( V_38 , struct V_1 , V_38 ) ;
int error ;
error = F_1 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 , L_8 , error ) ;
return;
}
if ( V_2 -> V_39 )
F_9 ( V_2 ) ;
else
F_12 ( V_2 ) ;
}
static int F_15 ( struct V_40 * V_7 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_16 ( V_7 ) ;
T_1 V_44 ;
V_2 -> V_39 = V_43 -> V_45 . V_46 . V_47 ;
if ( ! V_2 -> V_39 )
V_2 -> V_39 = V_43 -> V_45 . V_46 . V_48 ;
V_44 = ( T_1 ) V_2 -> V_4 -> V_5 * V_2 -> V_39 ;
V_2 -> V_6 = ( unsigned int ) ( V_44 >>
V_49 ) ;
F_17 ( & V_2 -> V_38 ) ;
return 0 ;
}
static int F_18 ( struct V_40 * V_7 )
{
struct V_1 * V_2 = F_16 ( V_7 ) ;
int error ;
error = F_4 ( V_2 , true ) ;
if ( error )
return error ;
error = F_19 ( V_2 -> V_50 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_9 , error ) ;
return error ;
}
return 0 ;
}
static void F_20 ( struct V_40 * V_7 )
{
struct V_1 * V_2 = F_16 ( V_7 ) ;
int error ;
F_21 ( & V_2 -> V_38 ) ;
F_12 ( V_2 ) ;
error = F_22 ( V_2 -> V_50 ) ;
if ( error )
F_3 ( V_2 -> V_7 ,
L_10 , error ) ;
F_4 ( V_2 , false ) ;
}
static int F_23 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_24 ( V_52 -> V_7 . V_55 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_25 ( & V_52 -> V_7 , sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_29 = V_54 -> V_58 ;
V_2 -> V_7 = & V_52 -> V_7 ;
V_2 -> type = V_59 ;
V_2 -> V_21 = V_60 ;
V_2 -> V_61 = false ;
V_2 -> V_9 = F_26 ( V_52 ) -> V_62 ;
switch ( V_2 -> V_9 ) {
case V_18 :
V_2 -> V_11 = V_54 -> V_11 ;
break;
case V_10 :
V_2 -> V_11 = V_54 -> V_58 ;
break;
default:
F_3 ( & V_52 -> V_7 , L_11 ,
V_2 -> V_9 ) ;
return - V_28 ;
}
F_27 ( & V_2 -> V_38 , F_13 ) ;
V_2 -> V_4 = F_28 ( & V_52 -> V_7 , NULL ) ;
if ( F_29 ( V_2 -> V_4 ) ) {
F_3 ( & V_52 -> V_7 , L_12 ) ;
return F_30 ( V_2 -> V_4 ) ;
}
V_2 -> V_50 = F_31 ( & V_52 -> V_7 , L_13 ) ;
if ( F_29 ( V_2 -> V_50 ) ) {
F_3 ( & V_52 -> V_7 , L_14 ) ;
return F_30 ( V_2 -> V_50 ) ;
}
V_2 -> V_40 = F_32 ( & V_52 -> V_7 ) ;
if ( ! V_2 -> V_40 ) {
F_3 ( & V_52 -> V_7 , L_15 ) ;
return - V_57 ;
}
V_2 -> V_40 -> V_63 = L_16 ;
V_2 -> V_40 -> V_64 . V_65 = 1 ;
V_2 -> V_40 -> V_7 . V_55 = & V_52 -> V_7 ;
V_2 -> V_40 -> V_66 = F_18 ;
V_2 -> V_40 -> V_67 = F_20 ;
F_33 ( V_2 -> V_40 , V_2 ) ;
F_34 ( V_2 -> V_40 , V_68 , V_69 ) ;
error = F_35 ( V_2 -> V_40 , NULL ,
F_15 ) ;
if ( error ) {
F_3 ( & V_52 -> V_7 , L_17 ) ;
return error ;
}
error = F_36 ( V_2 -> V_40 ) ;
if ( error ) {
F_3 ( & V_52 -> V_7 , L_18 ) ;
return error ;
}
F_37 ( V_52 , V_2 ) ;
return 0 ;
}
static int T_2 F_38 ( struct V_70 * V_7 )
{
struct V_51 * V_52 = F_39 ( V_7 ) ;
struct V_1 * V_2 = F_40 ( V_52 ) ;
if ( V_2 -> V_33 ) {
F_12 ( V_2 ) ;
V_2 -> V_61 = true ;
}
return 0 ;
}
static int T_2 F_41 ( struct V_70 * V_7 )
{
struct V_51 * V_52 = F_39 ( V_7 ) ;
struct V_1 * V_2 = F_40 ( V_52 ) ;
if ( V_2 -> V_61 ) {
F_9 ( V_2 ) ;
V_2 -> V_61 = false ;
}
return 0 ;
}
