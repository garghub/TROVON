void F_1 ( enum V_1 V_2 ,
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
void F_4 ( enum V_1 V_2 ,
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
static int F_7 ( struct V_21 * V_22 , const struct V_23 * V_24 )
{
struct V_3 * V_4 ;
V_4 = F_8 ( sizeof( struct V_3 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
if ( F_9 ( V_22 ) )
goto V_27;
if ( F_10 ( V_22 , L_1 ) )
goto V_28;
V_4 -> V_29 = L_1 ;
V_4 -> V_30 = L_2 ;
V_4 -> V_6 [ 0 ] . V_29 = L_3
L_4 ;
V_4 -> V_6 [ 0 ] . V_31 = F_11 ( V_22 , 0 ) ;
if ( ! V_4 -> V_6 [ 0 ] . V_31 )
goto V_32;
V_4 -> V_6 [ 0 ] . V_33 = F_12 ( V_22 , 0 ) ;
V_4 -> V_6 [ 0 ] . V_34 = V_35 ;
V_4 -> V_6 [ 0 ] . V_7 = F_13 ( V_22 , 0 ) ;
if ( ! V_4 -> V_6 [ 0 ] . V_7 )
goto V_32;
V_4 -> V_6 [ 1 ] . V_29 = L_5 ;
V_4 -> V_6 [ 1 ] . V_31 = F_11 ( V_22 , 2 ) ;
if ( ! V_4 -> V_6 [ 1 ] . V_31 )
goto V_36;
V_4 -> V_6 [ 1 ] . V_33 = F_12 ( V_22 , 2 ) ;
V_4 -> V_6 [ 1 ] . V_34 = V_35 ;
V_4 -> V_6 [ 1 ] . V_7 = F_13 ( V_22 , 2 ) ;
if ( ! V_4 -> V_6 [ 1 ] . V_7 )
goto V_36;
V_4 -> V_6 [ 2 ] . V_29 = L_6 ;
V_4 -> V_6 [ 2 ] . V_31 = F_11 ( V_22 , 4 ) ;
if ( ! V_4 -> V_6 [ 2 ] . V_31 )
goto V_37;
V_4 -> V_6 [ 2 ] . V_33 = F_12 ( V_22 , 4 ) ;
V_4 -> V_6 [ 2 ] . V_34 = V_35 ;
V_4 -> V_6 [ 2 ] . V_7 = F_13 ( V_22 , 4 ) ;
if ( ! V_4 -> V_6 [ 2 ] . V_7 )
goto V_37;
V_4 -> V_15 = V_22 -> V_15 ;
V_4 -> V_38 = V_39 ;
V_4 -> V_40 = F_5 ;
V_4 -> V_41 = F_6 ;
if ( F_14 ( & V_22 -> V_22 , V_4 ) )
goto V_42;
F_15 ( V_22 , V_4 ) ;
return 0 ;
V_42:
F_16 ( V_4 -> V_6 [ 2 ] . V_7 ) ;
V_37:
F_16 ( V_4 -> V_6 [ 1 ] . V_7 ) ;
V_36:
F_16 ( V_4 -> V_6 [ 0 ] . V_7 ) ;
V_32:
F_17 ( V_22 ) ;
V_28:
F_18 ( V_22 ) ;
V_27:
F_19 ( V_4 ) ;
return - V_43 ;
}
static void F_20 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_21 ( V_22 ) ;
F_1 ( V_14 , V_4 ) ;
F_22 ( V_4 ) ;
F_17 ( V_22 ) ;
F_18 ( V_22 ) ;
F_15 ( V_22 , NULL ) ;
F_16 ( V_4 -> V_6 [ 0 ] . V_7 ) ;
F_16 ( V_4 -> V_6 [ 1 ] . V_7 ) ;
F_16 ( V_4 -> V_6 [ 2 ] . V_7 ) ;
F_19 ( V_4 ) ;
}
