static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
int error ;
V_4 = ( V_2 -> V_5 * 1000 ) / 78125 ;
if ( V_4 <= 0 ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_1 , V_4 ) ;
return - V_8 ;
}
error = F_3 ( V_2 -> V_9 , V_10 , & V_3 ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_2 , error ) ;
return - V_11 ;
}
if ( V_3 == V_12 ||
V_2 -> V_13 != V_3 ) {
error = F_4 ( V_2 -> V_9 ,
V_10 , V_2 -> V_13 ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_3 , error ) ;
return - V_11 ;
}
}
error = F_4 ( V_2 -> V_9 , V_14 , V_4 ) ;
if ( error )
F_2 ( & V_2 -> V_6 -> V_7 ,
L_4 , error ) ;
if ( V_3 == V_12 ||
V_2 -> V_13 != V_3 ) {
error = F_4 ( V_2 -> V_9 , V_10 , V_3 ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_3 , error ) ;
return - V_11 ;
}
}
return error ;
}
static void F_5 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 , struct V_1 , V_16 ) ;
int error ;
if ( V_2 -> V_17 ) {
error = F_4 ( V_2 -> V_9 ,
V_10 , V_2 -> V_13 ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_3 , error ) ;
return;
}
error = F_4 ( V_2 -> V_9 , V_18 ,
V_2 -> V_17 ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_5 , error ) ;
return;
}
error = F_4 ( V_2 -> V_9 ,
V_10 , V_12 ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_3 , error ) ;
return;
}
error = F_4 ( V_2 -> V_9 ,
V_19 , V_20 ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_6 , error ) ;
}
} else {
error = F_7 ( V_2 -> V_9 , V_19 ,
V_20 , 0 ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_7 , error ) ;
}
}
}
static int F_8 ( struct V_21 * V_22 , void * V_23 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
if ( V_25 -> V_26 . V_27 . V_28 > 0 )
V_2 -> V_17 = V_25 -> V_26 . V_27 . V_28 ;
else if ( V_25 -> V_26 . V_27 . V_29 > 0 )
V_2 -> V_17 = V_25 -> V_26 . V_27 . V_29 ;
else
V_2 -> V_17 = 0 ;
F_10 ( & V_2 -> V_16 ) ;
return 0 ;
}
static void F_11 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
int error ;
F_12 ( & V_2 -> V_16 ) ;
error = F_7 ( V_2 -> V_9 , V_19 ,
V_30 , 1 ) ;
if ( error )
F_2 ( & V_2 -> V_6 -> V_7 ,
L_8 , error ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int error ;
V_2 -> V_5 = 195 ;
V_2 -> V_13 = V_31 ;
error = F_14 ( V_2 -> V_9 ,
V_32 ,
F_15 ( V_32 ) ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_9 ,
error ) ;
return error ;
}
error = F_4 ( V_2 -> V_9 , V_10 , V_2 -> V_13 ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 , L_10 ,
error ) ;
goto V_33;
}
error = F_1 ( V_2 ) ;
if ( error )
goto V_34;
error = F_14 ( V_2 -> V_9 ,
V_35 ,
F_15 ( V_35 ) ) ;
if ( error ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_11 ,
error ) ;
return error ;
}
error = F_4 ( V_2 -> V_9 , V_10 , V_12 ) ;
return error ;
V_34:
F_4 ( V_2 -> V_9 , V_10 , V_12 ) ;
V_33:
return error ;
}
static int F_16 ( struct V_36 * V_6 ,
const struct V_37 * V_38 )
{
struct V_1 * V_2 ;
int error ;
V_2 = F_17 ( & V_6 -> V_7 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
V_2 -> V_41 = F_18 ( & V_6 -> V_7 , L_12 ) ;
if ( F_19 ( V_2 -> V_41 ) ) {
error = F_20 ( V_2 -> V_41 ) ;
F_2 ( & V_6 -> V_7 ,
L_13 , error ) ;
return error ;
}
V_2 -> V_21 = F_21 ( & V_6 -> V_7 ) ;
if ( ! V_2 -> V_21 ) {
F_2 ( & V_6 -> V_7 , L_14 ) ;
return - V_40 ;
}
V_2 -> V_21 -> V_42 = L_15 ;
V_2 -> V_21 -> V_7 . V_43 = V_6 -> V_7 . V_43 ;
V_2 -> V_21 -> V_44 = F_11 ;
F_22 ( V_2 -> V_21 , V_2 ) ;
F_23 ( V_2 -> V_21 , V_45 , V_46 ) ;
error = F_24 ( V_2 -> V_21 , NULL ,
F_8 ) ;
if ( error ) {
F_2 ( & V_6 -> V_7 , L_16 ,
error ) ;
return error ;
}
F_25 ( & V_2 -> V_16 , F_5 ) ;
V_2 -> V_6 = V_6 ;
F_26 ( V_6 , V_2 ) ;
V_2 -> V_9 = F_27 ( V_6 , & V_47 ) ;
if ( F_19 ( V_2 -> V_9 ) ) {
error = F_20 ( V_2 -> V_9 ) ;
F_2 ( & V_6 -> V_7 , L_17 ,
error ) ;
return error ;
}
error = F_13 ( V_2 ) ;
if ( error ) {
F_2 ( & V_6 -> V_7 , L_18 , error ) ;
return error ;
}
error = F_28 ( V_2 -> V_21 ) ;
if ( error ) {
F_2 ( & V_6 -> V_7 , L_19 ,
error ) ;
return error ;
}
return 0 ;
}
static int T_1 F_29 ( struct V_48 * V_7 )
{
struct V_1 * V_2 = F_30 ( V_7 ) ;
int V_49 = 0 ;
F_31 ( & V_2 -> V_21 -> V_50 ) ;
if ( V_2 -> V_21 -> V_51 ) {
V_49 = F_7 ( V_2 -> V_9 , V_19 ,
V_30 , 1 ) ;
if ( V_49 ) {
F_2 ( V_7 , L_20 ) ;
F_32 ( V_2 -> V_41 ) ;
goto V_52;
}
V_49 = F_32 ( V_2 -> V_41 ) ;
if ( V_49 ) {
F_2 ( V_7 , L_21 ) ;
F_7 ( V_2 -> V_9 ,
V_19 ,
V_30 , 0 ) ;
}
}
V_52:
F_33 ( & V_2 -> V_21 -> V_50 ) ;
return V_49 ;
}
static int T_1 F_34 ( struct V_48 * V_7 )
{
struct V_1 * V_2 = F_30 ( V_7 ) ;
int V_49 = 0 ;
F_31 ( & V_2 -> V_21 -> V_50 ) ;
if ( V_2 -> V_21 -> V_51 ) {
V_49 = F_35 ( V_2 -> V_41 ) ;
if ( V_49 ) {
F_2 ( V_7 , L_22 ) ;
goto V_52;
}
V_49 = F_7 ( V_2 -> V_9 , V_19 ,
V_30 , 0 ) ;
if ( V_49 ) {
F_2 ( V_7 , L_23 ) ;
F_32 ( V_2 -> V_41 ) ;
goto V_52;
}
}
V_52:
F_33 ( & V_2 -> V_21 -> V_50 ) ;
return V_49 ;
}
