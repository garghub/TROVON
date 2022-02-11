static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
T_2 V_6 ;
V_5 = F_2 ( V_7 , & V_6 ) ;
F_3 ( V_4 -> V_8 . V_9 , L_1 , V_6 ) ;
if ( V_5 < 0 ) {
F_4 ( V_4 -> V_8 . V_9 , L_2
L_3 , V_5 ) ;
} else {
F_5 ( V_4 , V_10 , V_11 ,
! ( V_6 & V_12 ) ) ;
F_6 ( V_4 ) ;
}
return V_13 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_3 * V_4 ;
int V_1 = F_8 ( V_15 , 0 ) ;
int error ;
if ( V_1 < 0 )
return - V_16 ;
V_4 = F_9 () ;
if ( ! V_4 )
return - V_17 ;
V_4 -> V_18 = V_15 -> V_18 ;
V_4 -> V_19 = L_4 ;
V_4 -> V_20 . V_21 = V_22 ;
V_4 -> V_8 . V_9 = & V_15 -> V_8 ;
F_10 ( V_4 , V_10 , V_11 ) ;
error = F_11 ( V_1 , NULL , F_1 , V_23 ,
V_24 , V_4 ) ;
if ( error ) {
F_4 ( & V_15 -> V_8 , L_5
L_6 , V_1 ) ;
goto V_25;
}
F_12 ( & V_15 -> V_8 , true ) ;
F_13 ( & V_15 -> V_8 , V_1 ) ;
error = F_14 ( V_4 ) ;
if ( error ) {
F_4 ( & V_15 -> V_8 , L_7
L_8 , error ) ;
goto V_26;
}
F_15 ( V_15 , V_4 ) ;
error = F_16 ( V_27 , 0 , V_28 ) ;
if ( error ) {
F_4 ( & V_15 -> V_8 , L_9
L_10 , error ) ;
goto V_26;
}
return 0 ;
V_26:
F_17 ( V_1 , V_4 ) ;
V_25:
F_18 ( V_4 ) ;
return error ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_20 ( V_15 ) ;
int V_1 = F_8 ( V_15 , 0 ) ;
F_21 ( & V_15 -> V_8 ) ;
F_12 ( & V_15 -> V_8 , false ) ;
F_17 ( V_1 , V_4 ) ;
F_22 ( V_4 ) ;
return 0 ;
}
