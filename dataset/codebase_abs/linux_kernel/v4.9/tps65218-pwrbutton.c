static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
const struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_8 ;
int error ;
error = F_2 ( V_4 -> V_9 , V_6 -> V_10 , & V_8 ) ;
if ( error ) {
F_3 ( V_4 -> V_11 , L_1 , error ) ;
goto V_12;
}
if ( V_8 & V_6 -> V_13 ) {
F_4 ( V_4 -> V_14 , V_15 , 1 ) ;
F_5 ( V_4 -> V_11 , 0 ) ;
} else {
F_4 ( V_4 -> V_14 , V_15 , 0 ) ;
}
F_6 ( V_4 -> V_14 ) ;
V_12:
return V_16 ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_11 = & V_18 -> V_11 ;
struct V_3 * V_4 ;
struct V_20 * V_14 ;
const struct V_21 * V_22 ;
int error ;
int V_1 ;
V_22 = F_8 ( V_23 , V_18 -> V_11 . V_24 ) ;
if ( ! V_22 )
return - V_25 ;
V_4 = F_9 ( V_11 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_7 = V_22 -> V_7 ;
V_14 = F_10 ( V_11 ) ;
if ( ! V_14 )
return - V_27 ;
V_14 -> V_28 = V_4 -> V_7 -> V_28 ;
snprintf ( V_4 -> V_29 , sizeof( V_4 -> V_29 ) , L_2 ,
V_4 -> V_7 -> V_28 ) ;
V_14 -> V_29 = V_4 -> V_29 ;
V_14 -> V_11 . V_30 = V_11 ;
V_14 -> V_31 . V_32 = V_33 ;
F_11 ( V_14 , V_34 , V_15 ) ;
V_4 -> V_9 = F_12 ( V_18 -> V_11 . V_30 , NULL ) ;
V_4 -> V_11 = V_11 ;
V_4 -> V_14 = V_14 ;
F_13 ( V_18 , V_4 ) ;
F_14 ( V_11 , true ) ;
V_1 = F_15 ( V_18 , 0 ) ;
if ( V_1 < 0 ) {
F_3 ( V_11 , L_3 ) ;
return - V_35 ;
}
error = F_16 ( V_11 , V_1 , NULL , F_1 ,
V_36 |
V_37 |
V_38 ,
V_4 -> V_7 -> V_28 , V_4 ) ;
if ( error ) {
F_3 ( V_11 , L_4 ,
V_1 , error ) ;
return error ;
}
error = F_17 ( V_14 ) ;
if ( error ) {
F_3 ( V_11 , L_5 , error ) ;
return error ;
}
return 0 ;
}
