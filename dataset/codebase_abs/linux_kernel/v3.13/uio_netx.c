static T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
void T_2 * V_4 = V_3 -> V_5 [ 0 ] . V_6
+ V_7 ;
void T_2 * V_8 = V_3 -> V_5 [ 0 ] . V_6
+ V_9 ;
if ( ! ( F_2 ( V_4 ) & F_2 ( V_8 )
& V_10 ) )
return V_11 ;
F_3 ( F_2 ( V_4 ) & ~ V_12 ,
V_4 ) ;
return V_13 ;
}
static int F_4 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
struct V_2 * V_18 ;
int V_19 ;
V_18 = F_5 ( sizeof( struct V_2 ) , V_20 ) ;
if ( ! V_18 )
return - V_21 ;
if ( F_6 ( V_15 ) )
goto V_22;
if ( F_7 ( V_15 , L_1 ) )
goto V_23;
switch ( V_17 -> V_24 ) {
case V_25 :
V_19 = 0 ;
V_18 -> V_26 = L_1 ;
break;
case V_27 :
V_19 = 0 ;
V_18 -> V_26 = L_2 ;
break;
default:
V_19 = 2 ;
V_18 -> V_26 = L_3 ;
}
V_18 -> V_5 [ 0 ] . V_28 = F_8 ( V_15 , V_19 ) ;
if ( ! V_18 -> V_5 [ 0 ] . V_28 )
goto V_29;
V_18 -> V_5 [ 0 ] . V_6 = F_9 ( F_8 ( V_15 , V_19 ) ,
F_10 ( V_15 , V_19 ) ) ;
if ( ! V_18 -> V_5 [ 0 ] . V_6 )
goto V_29;
V_18 -> V_5 [ 0 ] . V_30 = F_10 ( V_15 , V_19 ) ;
V_18 -> V_5 [ 0 ] . V_31 = V_32 ;
V_18 -> V_1 = V_15 -> V_1 ;
V_18 -> V_33 = V_34 ;
V_18 -> V_35 = F_1 ;
V_18 -> V_36 = L_4 ;
F_3 ( 0 , V_18 -> V_5 [ 0 ] . V_6 + V_7 ) ;
if ( F_11 ( & V_15 -> V_15 , V_18 ) )
goto V_37;
F_12 ( V_15 , V_18 ) ;
V_3 ( & V_15 -> V_15 , L_5 ,
V_18 -> V_26 ) ;
return 0 ;
V_37:
F_13 ( V_18 -> V_5 [ 0 ] . V_6 ) ;
V_29:
F_14 ( V_15 ) ;
V_23:
F_15 ( V_15 ) ;
V_22:
F_16 ( V_18 ) ;
return - V_38 ;
}
static void F_17 ( struct V_14 * V_15 )
{
struct V_2 * V_18 = F_18 ( V_15 ) ;
F_3 ( 0 , V_18 -> V_5 [ 0 ] . V_6 + V_7 ) ;
F_19 ( V_18 ) ;
F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
F_13 ( V_18 -> V_5 [ 0 ] . V_6 ) ;
F_16 ( V_18 ) ;
}
