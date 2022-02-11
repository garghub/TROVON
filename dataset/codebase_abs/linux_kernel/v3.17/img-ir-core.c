static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
F_2 ( & V_4 -> V_6 ) ;
V_5 = F_3 ( V_4 , V_7 ) ;
F_4 ( V_4 , V_8 , V_5 ) ;
V_5 &= F_3 ( V_4 , V_9 ) ;
if ( V_5 & V_10 && F_5 ( & V_4 -> V_11 ) )
F_6 ( V_4 , V_5 ) ;
if ( V_5 & ( V_12 |
V_13 |
V_14 ) &&
F_7 ( & V_4 -> V_15 ) )
F_8 ( V_4 , V_5 ) ;
F_9 ( & V_4 -> V_6 ) ;
return V_16 ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_4 ( V_4 , V_9 , 0 ) ;
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
if ( ! F_13 ( V_4 -> V_17 ) )
F_14 ( V_4 -> V_17 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
T_2 V_18 = F_3 ( V_4 , V_19 ) ;
F_16 ( V_4 -> V_20 ,
L_1 ,
( V_18 & V_21 ) >> V_22 ,
( V_18 & V_23 ) >> V_24 ,
( V_18 & V_25 ) >> V_26 ,
( V_18 & V_27 ) >> V_28 ) ;
F_16 ( V_4 -> V_20 , L_2 ,
F_7 ( & V_4 -> V_15 ) ? L_3 : L_4 ,
F_5 ( & V_4 -> V_11 ) ? L_5 : L_4 ) ;
}
static int F_17 ( struct V_29 * V_30 )
{
struct V_3 * V_4 ;
struct V_31 * V_32 ;
int V_1 , error , V_33 ;
V_1 = F_18 ( V_30 , 0 ) ;
if ( V_1 < 0 ) {
F_19 ( & V_30 -> V_20 , L_6 ) ;
return V_1 ;
}
V_4 = F_20 ( & V_30 -> V_20 , sizeof( * V_4 ) , V_34 ) ;
if ( ! V_4 ) {
F_19 ( & V_30 -> V_20 , L_7 ) ;
return - V_35 ;
}
F_21 ( V_30 , V_4 ) ;
V_4 -> V_20 = & V_30 -> V_20 ;
F_22 ( & V_4 -> V_6 ) ;
V_32 = F_23 ( V_30 , V_36 , 0 ) ;
V_4 -> V_37 = F_24 ( & V_30 -> V_20 , V_32 ) ;
if ( F_13 ( V_4 -> V_37 ) )
return F_25 ( V_4 -> V_37 ) ;
V_4 -> V_17 = F_26 ( & V_30 -> V_20 , L_8 ) ;
if ( F_13 ( V_4 -> V_17 ) )
F_27 ( & V_30 -> V_20 , L_9 ) ;
error = F_28 ( V_4 ) ;
V_33 = F_29 ( V_4 ) ;
if ( error && V_33 )
return ( error == - V_38 ) ? V_33 : error ;
V_4 -> V_1 = V_1 ;
error = F_30 ( V_4 -> V_1 , F_1 , 0 , L_10 , V_4 ) ;
if ( error ) {
F_19 ( & V_30 -> V_20 , L_11 ,
V_4 -> V_1 ) ;
error = - V_39 ;
goto V_40;
}
F_15 ( V_4 ) ;
F_10 ( V_4 ) ;
return 0 ;
V_40:
F_31 ( V_4 ) ;
F_32 ( V_4 ) ;
return error ;
}
static int F_33 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_34 ( V_30 ) ;
F_35 ( V_4 -> V_1 , F_1 ) ;
F_31 ( V_4 ) ;
F_32 ( V_4 ) ;
if ( ! F_13 ( V_4 -> V_17 ) )
F_36 ( V_4 -> V_17 ) ;
return 0 ;
}
