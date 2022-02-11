static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned int V_5 ;
int error ;
error = F_2 ( V_4 -> V_6 , V_7 , & V_5 ) ;
if ( error ) {
F_3 ( V_4 -> V_8 , L_1 , error ) ;
goto V_9;
}
if ( V_5 & V_10 ) {
F_4 ( V_4 -> V_11 , V_12 , 1 ) ;
F_5 ( V_4 -> V_8 , 0 ) ;
} else {
F_4 ( V_4 -> V_11 , V_12 , 0 ) ;
}
F_6 ( V_4 -> V_11 ) ;
V_9:
return V_13 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_6 = F_8 ( V_15 -> V_8 . V_17 ) ;
struct V_18 * V_8 = & V_15 -> V_8 ;
struct V_3 * V_4 ;
struct V_19 * V_11 ;
int error ;
int V_1 ;
V_4 = F_9 ( V_8 , sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_11 = F_10 ( V_8 ) ;
if ( ! V_11 )
return - V_21 ;
V_11 -> V_22 = L_2 ;
V_11 -> V_23 = L_3 ;
V_11 -> V_8 . V_17 = V_8 ;
V_11 -> V_24 . V_25 = V_26 ;
F_11 ( V_11 , V_27 , V_12 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_11 = V_11 ;
F_12 ( V_15 , V_4 ) ;
F_13 ( V_8 , true ) ;
V_1 = F_14 ( V_15 , 0 ) ;
error = F_15 ( V_8 , V_1 , NULL , F_1 ,
V_28 |
V_29 |
V_30 ,
L_4 , V_4 ) ;
if ( error ) {
F_3 ( V_8 , L_5 ,
V_1 , error ) ;
return error ;
}
error = F_16 ( V_11 ) ;
if ( error ) {
F_3 ( V_8 , L_6 , error ) ;
return error ;
}
return 0 ;
}
