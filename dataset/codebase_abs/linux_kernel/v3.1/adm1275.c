static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
if ( V_3 )
return - V_6 ;
switch ( V_4 ) {
case V_7 :
V_5 = F_2 ( V_2 , 0 , V_8 ) ;
break;
case V_9 :
V_5 = F_2 ( V_2 , 0 , V_10 ) ;
break;
case V_11 :
V_5 = F_2 ( V_2 , 0 , V_12 ) ;
break;
case V_13 :
case V_14 :
case V_15 :
V_5 = 0 ;
break;
default:
V_5 = - V_16 ;
break;
}
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_17 )
{
int V_5 ;
if ( V_3 )
return - V_6 ;
switch ( V_4 ) {
case V_13 :
V_5 = F_4 ( V_2 , 0 , V_8 , 0 ) ;
break;
case V_14 :
V_5 = F_4 ( V_2 , 0 , V_10 , 0 ) ;
break;
case V_15 :
V_5 = F_4 ( V_2 , 0 , V_12 , 0 ) ;
break;
default:
V_5 = - V_16 ;
break;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_18 * V_19 )
{
int V_20 ;
int V_5 ;
struct V_21 * V_22 ;
if ( ! F_6 ( V_2 -> V_23 ,
V_24 ) )
return - V_25 ;
V_22 = F_7 ( sizeof( struct V_21 ) , V_26 ) ;
if ( ! V_22 )
return - V_27 ;
V_20 = F_8 ( V_2 , V_28 ) ;
if ( V_20 < 0 ) {
V_5 = V_20 ;
goto V_29;
}
V_22 -> V_30 = 1 ;
V_22 -> V_31 [ V_32 ] = V_33 ;
V_22 -> V_31 [ V_34 ] = V_33 ;
V_22 -> V_31 [ V_35 ] = V_33 ;
V_22 -> V_36 [ V_35 ] = 807 ;
V_22 -> V_37 [ V_35 ] = 20475 ;
V_22 -> V_38 [ V_35 ] = - 1 ;
V_22 -> V_39 [ 0 ] = V_40 | V_41 ;
V_22 -> V_42 = F_1 ;
V_22 -> V_43 = F_3 ;
if ( V_20 & V_44 ) {
V_22 -> V_36 [ V_32 ] = 19199 ;
V_22 -> V_37 [ V_32 ] = 0 ;
V_22 -> V_38 [ V_32 ] = - 2 ;
V_22 -> V_36 [ V_34 ] = 19199 ;
V_22 -> V_37 [ V_34 ] = 0 ;
V_22 -> V_38 [ V_34 ] = - 2 ;
} else {
V_22 -> V_36 [ V_32 ] = 6720 ;
V_22 -> V_37 [ V_32 ] = 0 ;
V_22 -> V_38 [ V_32 ] = - 1 ;
V_22 -> V_36 [ V_34 ] = 6720 ;
V_22 -> V_37 [ V_34 ] = 0 ;
V_22 -> V_38 [ V_34 ] = - 1 ;
}
if ( V_20 & V_45 )
V_22 -> V_39 [ 0 ] |= V_46 | V_47 ;
else
V_22 -> V_39 [ 0 ] |= V_48 | V_49 ;
V_5 = F_9 ( V_2 , V_19 , V_22 ) ;
if ( V_5 )
goto V_29;
return 0 ;
V_29:
F_10 ( V_22 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 )
{
const struct V_21 * V_22 = F_12 ( V_2 ) ;
int V_5 ;
V_5 = F_13 ( V_2 ) ;
F_10 ( V_22 ) ;
return V_5 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_50 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_50 ) ;
}
