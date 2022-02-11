static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = V_5 | V_6 | V_3 ;
struct V_7 V_8 = {
. V_9 = & V_4 ,
. V_10 = 1 ,
. V_11 = 8 ,
} ;
struct V_12 V_13 ;
struct V_14 * V_15 = F_2 ( V_2 ) ;
int error ;
F_3 ( & V_13 ) ;
F_4 ( & V_8 , & V_13 ) ;
error = F_5 ( V_15 , & V_13 ) ;
if ( error ) {
F_6 ( V_2 , L_1 ,
V_16 , V_3 , error ) ;
return error ;
}
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
int error ;
V_15 -> V_17 = V_18 ;
V_15 -> V_11 = 8 ;
if ( ! V_15 -> V_19 )
V_15 -> V_19 = V_20 ;
error = F_8 ( V_15 ) ;
if ( error )
return error ;
return F_9 ( & V_15 -> V_2 , V_15 -> V_21 , & V_22 ,
F_10 ( V_15 , & V_23 ) ,
F_1 ) ;
}
static int F_11 ( struct V_14 * V_15 )
{
return F_12 ( & V_15 -> V_2 ) ;
}
