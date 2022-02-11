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
error = F_5 ( V_2 -> V_9 ,
V_10 ,
V_11 ,
V_8 << V_12 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 , L_2 ,
V_8 ? L_3 : L_4 , error ) ;
return error ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , bool V_13 )
{
unsigned int V_14 ;
int error ;
V_14 = ( V_2 -> type << V_15 ) |
( V_13 << V_16 ) |
( V_2 -> V_17 << V_18 ) ;
error = F_7 ( V_2 -> V_9 ,
V_19 , V_14 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_5 , error ) ;
return error ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_20 )
return 0 ;
error = F_9 ( V_2 -> V_4 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_6 , error ) ;
return error ;
}
error = F_6 ( V_2 , true ) ;
if ( error )
goto V_21;
V_2 -> V_20 = true ;
return 0 ;
V_21:
F_10 ( V_2 -> V_4 ) ;
return error ;
}
static int F_11 ( struct V_1 * V_2 )
{
int error ;
if ( ! V_2 -> V_20 )
return 0 ;
error = F_6 ( V_2 , false ) ;
if ( error )
return error ;
F_10 ( V_2 -> V_4 ) ;
V_2 -> V_20 = false ;
return 0 ;
}
static void F_12 ( struct V_22 * V_23 )
{
struct V_1 * V_2 =
F_13 ( V_23 , struct V_1 , V_23 ) ;
int error ;
F_14 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_25 )
goto V_26;
if ( V_2 -> V_27 ) {
error = F_1 ( V_2 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_7 , error ) ;
goto V_26;
}
error = F_8 ( V_2 ) ;
if ( error )
F_3 ( V_2 -> V_7 ,
L_8 , error ) ;
} else {
error = F_11 ( V_2 ) ;
if ( error )
F_3 ( V_2 -> V_7 ,
L_9 , error ) ;
}
V_26:
F_15 ( & V_2 -> V_24 ) ;
}
static int F_16 ( struct V_28 * V_7 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
T_1 V_32 ;
V_2 -> V_27 = V_31 -> V_33 . V_34 . V_35 ;
if ( ! V_2 -> V_27 )
V_2 -> V_27 = V_31 -> V_33 . V_34 . V_36 ;
V_32 = ( T_1 ) V_2 -> V_4 -> V_5 * V_2 -> V_27 ;
V_2 -> V_6 = ( unsigned int ) ( V_32 >>
V_37 ) ;
F_18 ( & V_2 -> V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
int error ;
error = F_4 ( V_2 , true ) ;
if ( error )
return error ;
error = F_20 ( V_2 -> V_38 ) ;
if ( error ) {
F_3 ( V_2 -> V_7 ,
L_10 , error ) ;
return error ;
}
return 0 ;
}
static void F_21 ( struct V_28 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
int error ;
F_22 ( & V_2 -> V_23 ) ;
F_11 ( V_2 ) ;
error = F_23 ( V_2 -> V_38 ) ;
if ( error )
F_3 ( V_2 -> V_7 ,
L_11 , error ) ;
F_4 ( V_2 , false ) ;
}
static int F_24 ( struct V_39 * V_40 )
{
struct V_41 * V_41 = F_25 ( V_40 -> V_7 . V_42 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_26 ( & V_40 -> V_7 , sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_9 = V_41 -> V_45 ;
V_2 -> V_7 = & V_40 -> V_7 ;
V_2 -> type = V_46 ;
V_2 -> V_17 = V_47 ;
F_27 ( & V_2 -> V_23 , F_12 ) ;
F_28 ( & V_2 -> V_24 ) ;
V_2 -> V_4 = F_29 ( & V_40 -> V_7 , NULL ) ;
if ( F_30 ( V_2 -> V_4 ) ) {
F_3 ( & V_40 -> V_7 , L_12 ) ;
return F_31 ( V_2 -> V_4 ) ;
}
V_2 -> V_38 = F_32 ( & V_40 -> V_7 , L_13 ) ;
if ( F_30 ( V_2 -> V_38 ) ) {
F_3 ( & V_40 -> V_7 , L_14 ) ;
return F_31 ( V_2 -> V_38 ) ;
}
V_2 -> V_28 = F_33 ( & V_40 -> V_7 ) ;
if ( ! V_2 -> V_28 ) {
F_3 ( & V_40 -> V_7 , L_15 ) ;
return - V_44 ;
}
V_2 -> V_28 -> V_48 = L_16 ;
V_2 -> V_28 -> V_49 . V_50 = 1 ;
V_2 -> V_28 -> V_7 . V_42 = & V_40 -> V_7 ;
V_2 -> V_28 -> V_51 = F_19 ;
V_2 -> V_28 -> V_52 = F_21 ;
F_34 ( V_2 -> V_28 , V_2 ) ;
F_35 ( V_2 -> V_28 , V_53 , V_54 ) ;
error = F_36 ( V_2 -> V_28 , NULL ,
F_16 ) ;
if ( error ) {
F_3 ( & V_40 -> V_7 , L_17 ) ;
return error ;
}
error = F_37 ( V_2 -> V_28 ) ;
if ( error ) {
F_3 ( & V_40 -> V_7 , L_18 ) ;
return error ;
}
F_38 ( V_40 , V_2 ) ;
return 0 ;
}
static int T_2 F_39 ( struct V_55 * V_7 )
{
struct V_39 * V_40 = F_40 ( V_7 ) ;
struct V_1 * V_2 = F_41 ( V_40 ) ;
int error ;
error = F_42 ( & V_2 -> V_24 ) ;
if ( error )
return error ;
F_11 ( V_2 ) ;
V_2 -> V_25 = true ;
F_15 ( & V_2 -> V_24 ) ;
return 0 ;
}
static int T_2 F_43 ( struct V_55 * V_7 )
{
struct V_39 * V_40 = F_40 ( V_7 ) ;
struct V_1 * V_2 = F_41 ( V_40 ) ;
unsigned int V_27 ;
F_14 ( & V_2 -> V_24 ) ;
V_2 -> V_25 = false ;
V_27 = F_44 ( V_2 -> V_27 ) ;
if ( V_27 )
F_8 ( V_2 ) ;
F_15 ( & V_2 -> V_24 ) ;
return 0 ;
}
