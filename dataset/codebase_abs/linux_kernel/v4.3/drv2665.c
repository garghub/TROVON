static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
unsigned int V_5 ;
int error ;
error = F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
if ( error ) {
F_4 ( & V_4 -> V_8 -> V_9 ,
L_1 , error ) ;
return;
}
if ( V_5 & V_10 ) {
error = F_5 ( V_4 -> V_6 ,
V_11 ,
V_12 ,
F_6 ( V_12 ) ) ;
if ( error ) {
F_4 ( & V_4 -> V_8 -> V_9 ,
L_2 , error ) ;
return;
}
}
}
static int F_7 ( struct V_13 * V_14 , void * V_15 ,
struct V_16 * V_17 )
{
struct V_3 * V_4 = F_8 ( V_14 ) ;
F_9 ( & V_4 -> V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_8 ( V_14 ) ;
int error ;
F_11 ( & V_4 -> V_2 ) ;
error = F_12 ( V_4 -> V_6 ,
V_18 , V_19 , 1 ) ;
if ( error )
F_4 ( & V_4 -> V_8 -> V_9 ,
L_3 , error ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
int error ;
error = F_14 ( V_4 -> V_6 ,
V_20 ,
F_6 ( V_20 ) ) ;
if ( error ) {
F_4 ( & V_4 -> V_8 -> V_9 ,
L_4 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_15 ( struct V_21 * V_8 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 ;
int error ;
V_4 = F_16 ( & V_8 -> V_9 , sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_4 -> V_26 = F_17 ( & V_8 -> V_9 , L_5 ) ;
if ( F_18 ( V_4 -> V_26 ) ) {
error = F_19 ( V_4 -> V_26 ) ;
F_4 ( & V_8 -> V_9 ,
L_6 , error ) ;
return error ;
}
V_4 -> V_13 = F_20 ( & V_8 -> V_9 ) ;
if ( ! V_4 -> V_13 ) {
F_4 ( & V_8 -> V_9 , L_7 ) ;
return - V_25 ;
}
V_4 -> V_13 -> V_27 = L_8 ;
V_4 -> V_13 -> V_9 . V_28 = V_8 -> V_9 . V_28 ;
V_4 -> V_13 -> V_29 = F_10 ;
F_21 ( V_4 -> V_13 , V_4 ) ;
F_22 ( V_4 -> V_13 , V_30 , V_31 ) ;
error = F_23 ( V_4 -> V_13 , NULL ,
F_7 ) ;
if ( error ) {
F_4 ( & V_8 -> V_9 , L_9 ,
error ) ;
return error ;
}
F_24 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_8 = V_8 ;
F_25 ( V_8 , V_4 ) ;
V_4 -> V_6 = F_26 ( V_8 , & V_32 ) ;
if ( F_18 ( V_4 -> V_6 ) ) {
error = F_19 ( V_4 -> V_6 ) ;
F_4 ( & V_8 -> V_9 , L_10 ,
error ) ;
return error ;
}
error = F_13 ( V_4 ) ;
if ( error ) {
F_4 ( & V_8 -> V_9 , L_11 , error ) ;
return error ;
}
error = F_27 ( V_4 -> V_13 ) ;
if ( error ) {
F_4 ( & V_8 -> V_9 , L_12 ,
error ) ;
return error ;
}
return 0 ;
}
static int T_1 F_28 ( struct V_33 * V_9 )
{
struct V_3 * V_4 = F_29 ( V_9 ) ;
int V_34 = 0 ;
F_30 ( & V_4 -> V_13 -> V_35 ) ;
if ( V_4 -> V_13 -> V_36 ) {
V_34 = F_12 ( V_4 -> V_6 , V_18 ,
V_19 , 1 ) ;
if ( V_34 ) {
F_4 ( V_9 , L_13 ) ;
F_31 ( V_4 -> V_26 ) ;
goto V_37;
}
V_34 = F_31 ( V_4 -> V_26 ) ;
if ( V_34 ) {
F_4 ( V_9 , L_14 ) ;
F_12 ( V_4 -> V_6 ,
V_18 ,
V_19 , 0 ) ;
}
}
V_37:
F_32 ( & V_4 -> V_13 -> V_35 ) ;
return V_34 ;
}
static int T_1 F_33 ( struct V_33 * V_9 )
{
struct V_3 * V_4 = F_29 ( V_9 ) ;
int V_34 = 0 ;
F_30 ( & V_4 -> V_13 -> V_35 ) ;
if ( V_4 -> V_13 -> V_36 ) {
V_34 = F_34 ( V_4 -> V_26 ) ;
if ( V_34 ) {
F_4 ( V_9 , L_15 ) ;
goto V_37;
}
V_34 = F_12 ( V_4 -> V_6 , V_18 ,
V_19 , 0 ) ;
if ( V_34 ) {
F_4 ( V_9 , L_16 ) ;
F_31 ( V_4 -> V_26 ) ;
goto V_37;
}
}
V_37:
F_32 ( & V_4 -> V_13 -> V_35 ) ;
return V_34 ;
}
