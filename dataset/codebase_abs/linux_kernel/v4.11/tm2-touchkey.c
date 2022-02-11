static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
T_1 V_7 ;
T_2 V_8 ;
if ( V_4 == V_9 ) {
V_7 = V_10 ;
V_8 = V_11 ;
} else {
V_7 = V_12 ;
V_8 = V_13 ;
}
F_3 ( V_6 -> V_14 , V_7 , V_7 ) ;
F_4 ( V_6 -> V_15 ,
V_16 , V_8 ) ;
}
static int F_5 ( struct V_5 * V_6 )
{
int error ;
error = F_6 ( F_7 ( V_6 -> V_17 ) ,
V_6 -> V_17 ) ;
if ( error )
return error ;
F_8 ( 150 ) ;
return 0 ;
}
static void F_9 ( void * V_8 )
{
struct V_5 * V_6 = V_8 ;
F_10 ( F_7 ( V_6 -> V_17 ) ,
V_6 -> V_17 ) ;
}
static T_3 F_11 ( int V_18 , void * V_19 )
{
struct V_5 * V_6 = V_19 ;
int V_8 ;
int V_20 ;
V_8 = F_12 ( V_6 -> V_15 ,
V_21 ) ;
if ( V_8 < 0 ) {
F_13 ( & V_6 -> V_15 -> V_22 ,
L_1 , V_8 ) ;
goto V_23;
}
switch ( V_8 & V_24 ) {
case V_25 :
V_20 = V_26 ;
break;
case V_27 :
V_20 = V_28 ;
break;
default:
F_14 ( & V_6 -> V_15 -> V_22 ,
L_2 , V_8 ) ;
goto V_23;
}
if ( V_8 & V_29 ) {
F_15 ( V_6 -> V_30 , V_26 , 0 ) ;
F_15 ( V_6 -> V_30 , V_28 , 0 ) ;
} else {
F_15 ( V_6 -> V_30 , V_20 , 1 ) ;
}
F_16 ( V_6 -> V_30 ) ;
V_23:
return V_31 ;
}
static int F_17 ( struct V_32 * V_15 ,
const struct V_33 * V_34 )
{
struct V_5 * V_6 ;
int error ;
if ( ! F_18 ( V_15 -> V_35 ,
V_36 | V_37 ) ) {
F_13 ( & V_15 -> V_22 , L_3 ) ;
return - V_38 ;
}
V_6 = F_19 ( & V_15 -> V_22 , sizeof( * V_6 ) , V_39 ) ;
if ( ! V_6 )
return - V_40 ;
V_6 -> V_15 = V_15 ;
F_20 ( V_15 , V_6 ) ;
V_6 -> V_17 [ 0 ] . V_41 = L_4 ;
V_6 -> V_17 [ 1 ] . V_41 = L_5 ;
error = F_21 ( & V_15 -> V_22 ,
F_7 ( V_6 -> V_17 ) ,
V_6 -> V_17 ) ;
if ( error ) {
F_13 ( & V_15 -> V_22 , L_6 , error ) ;
return error ;
}
V_6 -> V_14 = V_6 -> V_17 [ 1 ] . V_42 ;
error = F_5 ( V_6 ) ;
if ( error ) {
F_13 ( & V_15 -> V_22 , L_7 , error ) ;
return error ;
}
error = F_22 ( & V_15 -> V_22 ,
F_9 , V_6 ) ;
if ( error ) {
F_13 ( & V_15 -> V_22 ,
L_8 , error ) ;
return error ;
}
V_6 -> V_30 = F_23 ( & V_15 -> V_22 ) ;
if ( ! V_6 -> V_30 ) {
F_13 ( & V_15 -> V_22 , L_9 ) ;
return - V_40 ;
}
V_6 -> V_30 -> V_43 = V_44 ;
V_6 -> V_30 -> V_34 . V_45 = V_46 ;
F_24 ( V_6 -> V_30 , V_47 , V_26 ) ;
F_24 ( V_6 -> V_30 , V_47 , V_28 ) ;
error = F_25 ( V_6 -> V_30 ) ;
if ( error ) {
F_13 ( & V_15 -> V_22 ,
L_10 , error ) ;
return error ;
}
error = F_26 ( & V_15 -> V_22 , V_15 -> V_18 ,
NULL , F_11 ,
V_48 ,
V_44 , V_6 ) ;
if ( error ) {
F_13 ( & V_15 -> V_22 ,
L_11 , error ) ;
return error ;
}
V_6 -> V_2 . V_43 = V_44 ;
V_6 -> V_2 . V_4 = V_49 ;
V_6 -> V_2 . V_50 = V_49 ;
V_6 -> V_2 . V_51 = F_1 ;
error = F_27 ( & V_15 -> V_22 , & V_6 -> V_2 ) ;
if ( error ) {
F_13 ( & V_15 -> V_22 ,
L_12 , error ) ;
return error ;
}
return 0 ;
}
static int T_4 F_28 ( struct V_52 * V_22 )
{
struct V_32 * V_15 = F_29 ( V_22 ) ;
struct V_5 * V_6 = F_30 ( V_15 ) ;
F_31 ( V_15 -> V_18 ) ;
F_9 ( V_6 ) ;
return 0 ;
}
static int T_4 F_32 ( struct V_52 * V_22 )
{
struct V_32 * V_15 = F_29 ( V_22 ) ;
struct V_5 * V_6 = F_30 ( V_15 ) ;
int V_53 ;
F_33 ( V_15 -> V_18 ) ;
V_53 = F_5 ( V_6 ) ;
if ( V_53 )
F_13 ( V_22 , L_13 , V_53 ) ;
return V_53 ;
}
