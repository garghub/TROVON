static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_5 = V_4 -> V_6 [ 0 ] . V_7 + V_8 ;
switch ( V_2 ) {
case V_9 :
F_2 ( F_3 ( V_5 )
& ~ ( V_10 | V_11 ) ,
V_5 ) ;
break;
case V_12 :
F_2 ( F_3 ( V_5 )
& ~ ( V_13 | V_11 ) ,
V_5 ) ;
break;
case V_14 :
default:
F_2 ( F_3 ( V_5 )
& ~ ( V_10 | V_13
| V_11 ) ,
V_5 ) ;
break;
}
}
static void F_4 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_5 = V_4 -> V_6 [ 0 ] . V_7 + V_8 ;
switch ( V_2 ) {
case V_9 :
F_2 ( F_3 ( V_5 )
| V_10 | V_11 ,
V_5 ) ;
break;
case V_12 :
F_2 ( F_3 ( V_5 )
| V_13 | V_11 ,
V_5 ) ;
break;
case V_14 :
default:
F_2 ( F_3 ( V_5 )
| V_10 | V_13
| V_11 ,
V_5 ) ;
break;
}
}
static T_2 F_5 ( int V_15 , struct V_3 * V_4 )
{
void T_1 * V_5 = V_4 -> V_6 [ 0 ] . V_7 + V_8 ;
if ( ( F_3 ( V_5 ) & V_10 )
&& ( F_3 ( V_5 ) & V_16 ) ) {
F_1 ( V_9 , V_4 ) ;
return V_17 ;
}
if ( ( F_3 ( V_5 ) & V_13 )
&& ( F_3 ( V_5 ) & V_18 ) ) {
F_1 ( V_12 , V_4 ) ;
return V_17 ;
}
return V_19 ;
}
static int F_6 ( struct V_3 * V_4 , T_3 V_20 )
{
if ( V_20 == 0 )
F_1 ( V_14 , V_4 ) ;
else if ( V_20 == 1 )
F_4 ( V_14 , V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_21 * V_22 , int V_23 , struct V_24 * V_6 , const char * V_25 )
{
T_4 V_26 = F_8 ( V_22 , V_23 ) ;
T_4 V_27 = F_9 ( V_22 , V_23 ) ;
V_6 -> V_25 = V_25 ;
V_6 -> V_28 = V_26 & V_29 ;
V_6 -> V_30 = V_26 & ~ V_29 ;
if ( ! V_6 -> V_28 )
return - V_31 ;
V_6 -> V_32 = ( ( V_26 & ~ V_29 ) + V_27 + V_33 - 1 ) & V_29 ;
V_6 -> V_34 = V_35 ;
V_6 -> V_7 = F_10 ( V_22 , V_23 ) ;
if ( ! V_6 -> V_7 )
return - V_31 ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 , const struct V_36 * V_37 )
{
struct V_3 * V_4 ;
V_4 = F_12 ( sizeof( struct V_3 ) , V_38 ) ;
if ( ! V_4 )
return - V_39 ;
if ( F_13 ( V_22 ) )
goto V_40;
if ( F_14 ( V_22 , L_1 ) )
goto V_41;
V_4 -> V_25 = L_1 ;
V_4 -> V_42 = L_2 ;
if ( F_7 ( V_22 , 0 , & V_4 -> V_6 [ 0 ] , L_3
L_4 ) )
goto V_43;
if ( F_7 ( V_22 , 2 , & V_4 -> V_6 [ 1 ] , L_5 ) )
goto V_44;
if ( F_7 ( V_22 , 4 , & V_4 -> V_6 [ 2 ] , L_6 ) )
goto V_45;
V_4 -> V_15 = V_22 -> V_15 ;
V_4 -> V_46 = V_47 ;
V_4 -> V_48 = F_5 ;
V_4 -> V_49 = F_6 ;
if ( F_15 ( & V_22 -> V_22 , V_4 ) )
goto V_50;
F_16 ( V_22 , V_4 ) ;
return 0 ;
V_50:
F_17 ( V_4 -> V_6 [ 2 ] . V_7 ) ;
V_45:
F_17 ( V_4 -> V_6 [ 1 ] . V_7 ) ;
V_44:
F_17 ( V_4 -> V_6 [ 0 ] . V_7 ) ;
V_43:
F_18 ( V_22 ) ;
V_41:
F_19 ( V_22 ) ;
V_40:
F_20 ( V_4 ) ;
return - V_31 ;
}
static void F_21 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_22 ( V_22 ) ;
F_1 ( V_14 , V_4 ) ;
F_23 ( V_4 ) ;
F_18 ( V_22 ) ;
F_19 ( V_22 ) ;
F_17 ( V_4 -> V_6 [ 0 ] . V_7 ) ;
F_17 ( V_4 -> V_6 [ 1 ] . V_7 ) ;
F_17 ( V_4 -> V_6 [ 2 ] . V_7 ) ;
F_20 ( V_4 ) ;
}
