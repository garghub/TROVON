static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 = 0 ;
unsigned int V_6 ;
V_5 = F_2 ( V_4 -> V_7 , V_8 , & V_6 ) ;
if ( V_5 < 0 ) {
F_3 ( V_4 -> V_9 -> V_10 . V_11 , L_1 , V_5 ) ;
return V_12 ;
}
V_6 &= V_13 ;
F_4 ( V_4 -> V_9 , V_14 , V_6 ) ;
F_5 ( V_4 -> V_9 ) ;
return V_15 ;
}
static int T_2 F_6 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_7 ( V_17 -> V_10 . V_11 ) ;
struct V_3 * V_4 ;
int V_20 ;
V_4 = F_8 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_4 )
return - V_22 ;
V_4 -> V_23 = V_19 ;
V_4 -> V_1 = F_9 ( V_17 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
F_3 ( & V_17 -> V_10 , L_2 ) ;
V_20 = - V_24 ;
goto V_25;
}
V_4 -> V_7 = V_4 -> V_23 -> V_26 ;
if ( ! V_4 -> V_7 ) {
F_3 ( & V_17 -> V_10 , L_3 ) ;
V_20 = - V_24 ;
goto V_25;
}
V_4 -> V_9 = F_10 () ;
if ( ! V_4 -> V_9 ) {
F_3 ( & V_17 -> V_10 , L_4 ) ;
V_20 = - V_22 ;
goto V_25;
}
V_4 -> V_9 -> V_27 = L_5 ;
V_4 -> V_9 -> V_28 = L_6 ;
V_4 -> V_9 -> V_29 . V_30 = V_31 ;
V_4 -> V_9 -> V_10 . V_11 = & V_17 -> V_10 ;
V_4 -> V_9 -> V_32 [ 0 ] = F_11 ( V_33 ) ;
F_12 ( V_14 , V_4 -> V_9 -> V_34 ) ;
V_20 = F_13 ( V_4 -> V_23 , V_4 -> V_1 , F_1 ,
V_35 , L_7 , V_4 ) ;
if ( V_20 < 0 ) {
F_3 ( & V_17 -> V_10 , L_8 ,
V_4 -> V_1 , V_20 ) ;
goto V_36;
}
V_20 = F_14 ( V_4 -> V_9 ) ;
if ( V_20 ) {
F_3 ( & V_17 -> V_10 , L_9 , V_20 ) ;
goto V_37;
}
F_15 ( V_17 , V_4 ) ;
F_16 ( V_4 -> V_7 , V_38 , V_39 ,
V_39 ) ;
F_16 ( V_4 -> V_7 , V_40 ,
V_41 ,
V_42 ) ;
F_17 ( & V_17 -> V_10 , 1 ) ;
return 0 ;
V_37:
F_18 ( V_4 -> V_23 , V_4 -> V_1 , V_4 ) ;
V_36:
F_19 ( V_4 -> V_9 ) ;
V_25:
F_20 ( V_4 ) ;
return V_20 ;
}
static int T_3 F_21 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_22 ( V_17 ) ;
F_17 ( & V_17 -> V_10 , 0 ) ;
F_18 ( V_4 -> V_23 , V_4 -> V_1 , V_4 ) ;
F_23 ( V_4 -> V_9 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
