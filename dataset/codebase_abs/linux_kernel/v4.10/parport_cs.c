static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( sizeof( * V_3 ) , V_5 ) ;
if ( ! V_3 ) return - V_6 ;
V_2 -> V_7 = V_3 ;
V_3 -> V_8 = V_2 ;
V_2 -> V_9 |= V_10 | V_11 ;
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_4 , L_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_7 ) ;
}
static int F_8 ( struct V_1 * V_8 , void * V_12 )
{
V_8 -> V_13 [ 0 ] -> V_14 &= ~ V_15 ;
V_8 -> V_13 [ 0 ] -> V_14 |= V_16 ;
V_8 -> V_13 [ 1 ] -> V_14 &= ~ V_15 ;
V_8 -> V_13 [ 1 ] -> V_14 |= V_16 ;
return F_9 ( V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_7 ;
struct V_17 * V_18 ;
int V_19 ;
F_2 ( & V_2 -> V_4 , L_3 ) ;
if ( V_20 )
V_2 -> V_21 |= V_22 ;
V_19 = F_10 ( V_2 , F_8 , NULL ) ;
if ( V_19 )
goto V_23;
if ( ! V_2 -> V_24 )
goto V_23;
V_19 = F_11 ( V_2 ) ;
if ( V_19 )
goto V_23;
V_18 = F_12 ( V_2 -> V_13 [ 0 ] -> V_25 ,
V_2 -> V_13 [ 1 ] -> V_25 ,
V_2 -> V_24 , V_26 ,
& V_2 -> V_4 , V_27 ) ;
if ( V_18 == NULL ) {
F_13 ( V_28 L_4
L_5 ,
( unsigned int ) V_2 -> V_13 [ 0 ] -> V_25 ,
V_2 -> V_24 ) ;
goto V_23;
}
V_18 -> V_29 |= V_30 ;
if ( V_20 )
V_18 -> V_29 |= V_31 | V_32 ;
V_3 -> V_33 = 1 ;
V_3 -> V_34 = V_18 ;
return 0 ;
V_23:
F_6 ( V_2 ) ;
return - V_35 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_7 ;
F_2 ( & V_2 -> V_4 , L_6 ) ;
if ( V_3 -> V_33 ) {
struct V_17 * V_18 = V_3 -> V_34 ;
F_14 ( V_18 ) ;
}
V_3 -> V_33 = 0 ;
F_15 ( V_2 ) ;
}
