static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_2 -> V_10 -> V_10 ;
int V_11 = - V_12 ;
T_1 V_13 ;
T_1 V_14 ;
int V_15 = - 1 ;
V_13 = V_2 -> V_10 -> V_16 -> V_17 . V_18 ;
F_2 ( V_10 , L_1 , V_13 ) ;
V_14 = V_6 -> V_17 . V_19 ;
F_2 ( V_10 , L_2 , V_14 ) ;
if ( V_13 == 1 ) {
if ( V_2 -> V_7 -> V_20 == 2 )
V_6 = & V_2 -> V_7 -> V_15 [ 1 ] ;
else if ( V_2 -> V_7 -> V_20 > 2 )
goto V_21;
if ( V_6 -> V_17 . V_22 == 2 &&
F_3 ( & V_6 -> V_23 [ 0 ] . V_17 ) &&
F_4 ( & V_6 -> V_23 [ 1 ] . V_17 ) ) {
F_2 ( V_10 , L_3 ) ;
if ( V_2 -> V_7 -> V_20 == 1 )
V_11 = 0 ;
else
V_15 = 1 ;
}
goto V_21;
}
V_15 = 0 ;
switch ( V_4 -> V_24 ) {
case V_25 :
if ( V_13 < 3 || V_13 > 4 ) {
F_5 ( V_10 , L_4 , V_13 ) ;
V_15 = - 1 ;
goto V_21;
}
if ( V_14 == 0 ) {
F_2 ( V_10 , L_5 ) ;
V_15 = 1 ;
} else if ( V_14 == 2 )
F_2 ( V_10 , L_6 ) ;
else
V_15 = - 1 ;
break;
case V_26 :
if ( V_13 < 3 || V_13 > 4 ) {
F_5 ( V_10 , L_4 , V_13 ) ;
V_15 = - 1 ;
goto V_21;
}
switch ( V_14 ) {
case 0 :
V_15 = - 1 ;
break;
case 1 :
F_2 ( V_10 , L_7 ) ;
break;
case 2 :
F_2 ( V_10 , L_6 ) ;
break;
case 3 :
F_2 ( V_10 , L_8 ) ;
break;
}
break;
case V_27 :
switch ( V_14 ) {
case 0 :
F_2 ( V_10 , L_9 ) ;
break;
case 2 :
F_2 ( V_10 , L_10 ) ;
break;
case 3 :
F_2 ( V_10 , L_6 ) ;
break;
default:
V_15 = - 1 ;
break;
}
break;
case V_28 :
switch ( V_14 ) {
case 0 :
case 2 :
F_2 ( V_10 , L_6 ) ;
break;
case 1 :
F_2 ( V_10 , L_9 ) ;
break;
case 5 :
F_2 ( V_10 , L_10 ) ;
break;
default:
V_15 = - 1 ;
break;
}
break;
default:
F_5 ( V_10 , L_11 ,
V_4 -> V_24 ) ;
break;
}
V_21:
if ( V_15 >= 0 ) {
V_11 = F_6 ( V_2 -> V_10 , V_14 , V_15 ) ;
if ( V_11 < 0 ) {
F_5 ( V_10 ,
L_12 ,
V_11 ) ;
V_11 = - V_12 ;
}
}
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
V_30 = F_8 ( sizeof( * V_30 ) , V_31 ) ;
if ( ! V_30 )
return - V_32 ;
F_9 ( & V_30 -> V_33 ) ;
F_10 ( V_2 , V_30 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_29 * V_34 = F_12 ( V_2 ) ;
F_10 ( V_2 , NULL ) ;
F_13 ( V_34 ) ;
}
