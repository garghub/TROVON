static T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
void T_2 * V_4 = V_3 -> V_5 [ 0 ] . V_6
+ V_7 ;
if ( ( F_2 ( V_4 ) & V_8 )
!= V_8 )
return V_9 ;
F_3 ( F_2 ( V_4 ) & ~ V_10 , V_4 ) ;
return V_11 ;
}
static int F_4 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_2 * V_16 ;
V_16 = F_5 ( sizeof( struct V_2 ) , V_17 ) ;
if ( ! V_16 )
return - V_18 ;
if ( F_6 ( V_13 ) )
goto V_19;
if ( F_7 ( V_13 , L_1 ) )
goto V_20;
V_16 -> V_5 [ 0 ] . V_21 = F_8 ( V_13 , 0 ) ;
if ( ! V_16 -> V_5 [ 0 ] . V_21 )
goto V_22;
V_16 -> V_5 [ 0 ] . V_6 = F_9 ( V_13 , 0 ) ;
if ( ! V_16 -> V_5 [ 0 ] . V_6 )
goto V_22;
V_16 -> V_5 [ 0 ] . V_23 = F_10 ( V_13 , 0 ) ;
V_16 -> V_5 [ 0 ] . V_24 = V_25 ;
V_16 -> V_5 [ 1 ] . V_21 = F_8 ( V_13 , 2 ) ;
V_16 -> V_5 [ 1 ] . V_23 = F_10 ( V_13 , 2 ) ;
V_16 -> V_5 [ 1 ] . V_24 = V_25 ;
switch ( V_15 -> V_26 ) {
case V_27 :
V_16 -> V_28 = L_2 ;
break;
case V_29 :
V_16 -> V_28 = L_3 ;
break;
default:
V_16 -> V_28 = L_4 ;
}
V_16 -> V_30 = L_5 ;
V_16 -> V_1 = V_13 -> V_1 ;
V_16 -> V_31 = V_32 ;
V_16 -> V_33 = F_1 ;
if ( F_11 ( & V_13 -> V_13 , V_16 ) )
goto V_34;
F_12 ( V_13 , V_16 ) ;
return 0 ;
V_34:
F_13 ( V_16 -> V_5 [ 0 ] . V_6 ) ;
V_22:
F_14 ( V_13 ) ;
V_20:
F_15 ( V_13 ) ;
V_19:
F_16 ( V_16 ) ;
return - V_35 ;
}
static void F_17 ( struct V_12 * V_13 )
{
struct V_2 * V_16 = F_18 ( V_13 ) ;
F_19 ( V_16 ) ;
F_14 ( V_13 ) ;
F_15 ( V_13 ) ;
F_13 ( V_16 -> V_5 [ 0 ] . V_6 ) ;
F_16 ( V_16 ) ;
}
