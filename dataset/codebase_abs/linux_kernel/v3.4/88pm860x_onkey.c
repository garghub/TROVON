static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
V_5 = F_2 ( V_4 -> V_6 , V_7 ) ;
V_5 &= V_8 ;
F_3 ( V_4 -> V_9 , V_10 , V_5 ) ;
F_4 ( V_4 -> V_9 ) ;
F_5 ( V_4 -> V_6 , V_11 , 3 , V_12 ) ;
return V_13 ;
}
static int T_2 F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_7 ( V_15 -> V_18 . V_19 ) ;
struct V_3 * V_4 ;
int V_1 , V_5 ;
V_1 = F_8 ( V_15 , 0 ) ;
if ( V_1 < 0 ) {
F_9 ( & V_15 -> V_18 , L_1 ) ;
return - V_20 ;
}
V_4 = F_10 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_4 )
return - V_22 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_6 = ( V_17 -> V_23 == V_24 ) ? V_17 -> V_25 : V_17 -> V_26 ;
V_4 -> V_18 = & V_15 -> V_18 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_9 = F_11 () ;
if ( ! V_4 -> V_9 ) {
F_9 ( V_17 -> V_18 , L_2 ) ;
V_5 = - V_22 ;
goto V_27;
}
V_4 -> V_9 -> V_28 = L_3 ;
V_4 -> V_9 -> V_29 = L_4 ;
V_4 -> V_9 -> V_23 . V_30 = V_31 ;
V_4 -> V_9 -> V_18 . V_19 = & V_15 -> V_18 ;
V_4 -> V_9 -> V_32 [ 0 ] = F_12 ( V_33 ) ;
V_4 -> V_9 -> V_34 [ F_13 ( V_10 ) ] = F_12 ( V_10 ) ;
V_5 = F_14 ( V_4 -> V_9 ) ;
if ( V_5 ) {
F_9 ( V_17 -> V_18 , L_5 , V_5 ) ;
goto V_35;
}
V_5 = F_15 ( V_4 -> V_1 , NULL , F_1 ,
V_36 , L_6 , V_4 ) ;
if ( V_5 < 0 ) {
F_9 ( V_17 -> V_18 , L_7 ,
V_4 -> V_1 , V_5 ) ;
goto V_37;
}
F_16 ( V_15 , V_4 ) ;
F_17 ( & V_15 -> V_18 , 1 ) ;
return 0 ;
V_37:
F_18 ( V_4 -> V_9 ) ;
F_19 ( V_4 ) ;
return V_5 ;
V_35:
F_20 ( V_4 -> V_9 ) ;
V_27:
F_19 ( V_4 ) ;
return V_5 ;
}
static int T_3 F_21 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_22 ( V_15 ) ;
F_23 ( V_4 -> V_1 , V_4 ) ;
F_18 ( V_4 -> V_9 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_38 * V_18 )
{
struct V_14 * V_15 = F_25 ( V_18 ) ;
struct V_16 * V_17 = F_7 ( V_15 -> V_18 . V_19 ) ;
if ( F_26 ( V_18 ) )
V_17 -> V_39 |= 1 << V_40 ;
return 0 ;
}
static int F_27 ( struct V_38 * V_18 )
{
struct V_14 * V_15 = F_25 ( V_18 ) ;
struct V_16 * V_17 = F_7 ( V_15 -> V_18 . V_19 ) ;
if ( F_26 ( V_18 ) )
V_17 -> V_39 &= ~ ( 1 << V_40 ) ;
return 0 ;
}
