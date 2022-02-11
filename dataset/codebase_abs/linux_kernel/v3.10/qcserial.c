static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = & V_2 -> V_10 -> V_10 ;
int V_11 = - V_12 ;
T_1 V_13 ;
T_1 V_14 ;
bool V_15 = V_4 -> V_16 ? true : false ;
int V_17 = - 1 ;
F_2 ( V_10 , L_1 , V_15 ) ;
V_13 = V_2 -> V_10 -> V_18 -> V_19 . V_20 ;
F_2 ( V_10 , L_2 , V_13 ) ;
V_14 = V_6 -> V_19 . V_21 ;
F_2 ( V_10 , L_3 , V_14 ) ;
if ( V_13 == 1 ) {
if ( V_2 -> V_7 -> V_22 == 2 )
V_6 = & V_2 -> V_7 -> V_17 [ 1 ] ;
else if ( V_2 -> V_7 -> V_22 > 2 )
goto V_23;
if ( V_6 -> V_19 . V_24 == 2 &&
F_3 ( & V_6 -> V_25 [ 0 ] . V_19 ) &&
F_4 ( & V_6 -> V_25 [ 1 ] . V_19 ) ) {
F_2 ( V_10 , L_4 ) ;
if ( V_2 -> V_7 -> V_22 == 1 )
V_11 = 0 ;
else
V_17 = 1 ;
}
goto V_23;
}
if ( V_4 -> V_26 & V_27 ) {
F_2 ( V_10 , L_5 ) ;
V_17 = 0 ;
goto V_23;
}
if ( V_13 < 3 || V_13 > 4 ) {
F_5 ( V_10 , L_6 , V_13 ) ;
goto V_23;
}
V_17 = 0 ;
if ( V_15 ) {
if ( V_14 == 0 ) {
F_2 ( V_10 , L_7 ) ;
V_17 = 1 ;
} else if ( V_14 == 2 )
F_2 ( V_10 , L_8 ) ;
else
V_17 = - 1 ;
} else {
switch ( V_14 ) {
case 0 :
V_17 = - 1 ;
break;
case 1 :
F_2 ( V_10 , L_9 ) ;
break;
case 2 :
F_2 ( V_10 , L_8 ) ;
break;
case 3 :
F_2 ( V_10 , L_10 ) ;
break;
}
}
V_23:
if ( V_17 >= 0 ) {
V_11 = F_6 ( V_2 -> V_10 , V_14 , V_17 ) ;
if ( V_11 < 0 ) {
F_5 ( V_10 ,
L_11 ,
V_11 ) ;
V_11 = - V_12 ;
}
}
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
V_29 = F_8 ( sizeof( * V_29 ) , V_30 ) ;
if ( ! V_29 )
return - V_31 ;
F_9 ( & V_29 -> V_32 ) ;
F_10 ( V_2 , V_29 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_28 * V_33 = F_12 ( V_2 ) ;
F_10 ( V_2 , NULL ) ;
F_13 ( V_33 ) ;
}
