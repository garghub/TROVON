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
static int F_4 ( struct V_1 * V_2 ,
bool V_8 )
{
unsigned int V_9 ;
int error ;
V_9 = ( ( V_2 -> type << V_10 ) |
( V_8 << V_11 ) |
( V_2 -> V_12 << V_13 ) |
( V_2 -> V_14 ) ) ;
error = F_5 ( V_2 -> V_15 ,
V_16 , V_9 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_2 , error ) ;
return error ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , bool V_8 )
{
int error ;
error = F_7 ( V_2 -> V_17 ,
V_18 ,
V_19 ,
V_8 << V_20 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 , L_3 , error ) ;
return error ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_21 )
return;
error = F_9 ( V_2 -> V_4 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_4 , error ) ;
return;
}
error = F_6 ( V_2 , true ) ;
if ( error )
goto V_22;
error = F_4 ( V_2 , true ) ;
if ( error )
goto V_23;
V_2 -> V_21 = true ;
return;
V_23:
F_6 ( V_2 , false ) ;
V_22:
F_10 ( V_2 -> V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
int error ;
if ( ! V_2 -> V_21 )
return;
error = F_4 ( V_2 , false ) ;
if ( error )
return;
error = F_6 ( V_2 , false ) ;
if ( error )
goto V_24;
F_10 ( V_2 -> V_4 ) ;
V_2 -> V_21 = false ;
return;
V_24:
F_4 ( V_2 , true ) ;
}
static void F_12 ( struct V_25 * V_26 )
{
struct V_1 * V_2 =
F_13 ( V_26 , struct V_1 , V_26 ) ;
int error ;
error = F_1 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 , L_5 , error ) ;
return;
}
if ( V_2 -> V_27 )
F_8 ( V_2 ) ;
else
F_11 ( V_2 ) ;
}
static int F_14 ( struct V_28 * V_7 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_15 ( V_7 ) ;
T_1 V_32 ;
V_2 -> V_27 = V_31 -> V_33 . V_34 . V_35 ;
if ( ! V_2 -> V_27 )
V_2 -> V_27 = V_31 -> V_33 . V_34 . V_36 ;
V_32 = ( T_1 ) V_2 -> V_4 -> V_5 * V_2 -> V_27 ;
V_2 -> V_6 = ( unsigned int ) ( V_32 >>
V_37 ) ;
F_16 ( & V_2 -> V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_28 * V_7 )
{
struct V_1 * V_2 = F_15 ( V_7 ) ;
int error ;
error = F_18 ( V_2 -> V_38 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_6 , error ) ;
return error ;
}
return 0 ;
}
static void F_19 ( struct V_28 * V_7 )
{
struct V_1 * V_2 = F_15 ( V_7 ) ;
int error ;
F_20 ( & V_2 -> V_26 ) ;
F_11 ( V_2 ) ;
error = F_21 ( V_2 -> V_38 ) ;
if ( error )
F_3 ( V_2 -> V_7 ,
L_7 , error ) ;
}
static int F_22 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_23 ( V_40 -> V_7 . V_43 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_24 ( & V_40 -> V_7 , sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_2 -> V_17 = V_42 -> V_46 ;
V_2 -> V_15 = V_42 -> V_15 ;
V_2 -> V_7 = & V_40 -> V_7 ;
V_2 -> type = V_47 ;
V_2 -> V_12 = V_48 ;
V_2 -> V_14 = V_49 ;
V_2 -> V_50 = false ;
F_25 ( & V_2 -> V_26 , F_12 ) ;
V_2 -> V_4 = F_26 ( & V_40 -> V_7 , NULL ) ;
if ( F_27 ( V_2 -> V_4 ) ) {
F_3 ( & V_40 -> V_7 , L_8 ) ;
return F_28 ( V_2 -> V_4 ) ;
}
V_2 -> V_38 = F_29 ( & V_40 -> V_7 , L_9 ) ;
if ( F_27 ( V_2 -> V_38 ) ) {
F_3 ( & V_40 -> V_7 , L_10 ) ;
return F_28 ( V_2 -> V_38 ) ;
}
V_2 -> V_28 = F_30 ( & V_40 -> V_7 ) ;
if ( ! V_2 -> V_28 ) {
F_3 ( & V_40 -> V_7 , L_11 ) ;
return - V_45 ;
}
V_2 -> V_28 -> V_51 = L_12 ;
V_2 -> V_28 -> V_52 . V_53 = 1 ;
V_2 -> V_28 -> V_7 . V_43 = & V_40 -> V_7 ;
V_2 -> V_28 -> V_54 = F_17 ;
V_2 -> V_28 -> V_55 = F_19 ;
F_31 ( V_2 -> V_28 , V_2 ) ;
F_32 ( V_2 -> V_28 , V_56 , V_57 ) ;
error = F_33 ( V_2 -> V_28 , NULL ,
F_14 ) ;
if ( error ) {
F_3 ( & V_40 -> V_7 , L_13 ) ;
return error ;
}
error = F_34 ( V_2 -> V_28 ) ;
if ( error ) {
F_3 ( & V_40 -> V_7 , L_14 ) ;
return error ;
}
F_35 ( V_40 , V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_58 * V_7 )
{
struct V_39 * V_40 = F_37 ( V_7 ) ;
struct V_1 * V_2 = F_38 ( V_40 ) ;
if ( V_2 -> V_21 ) {
F_11 ( V_2 ) ;
V_2 -> V_50 = true ;
}
return 0 ;
}
static int F_39 ( struct V_58 * V_7 )
{
struct V_39 * V_40 = F_37 ( V_7 ) ;
struct V_1 * V_2 = F_38 ( V_40 ) ;
if ( V_2 -> V_50 ) {
F_8 ( V_2 ) ;
V_2 -> V_50 = false ;
}
return 0 ;
}
