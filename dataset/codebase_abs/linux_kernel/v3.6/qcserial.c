static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
struct V_11 * V_12 = & V_2 -> V_12 -> V_12 ;
int V_13 = - V_14 ;
T_1 V_15 ;
T_1 V_16 ;
bool V_17 = V_4 -> V_18 ? true : false ;
int V_19 = - 1 ;
F_2 ( V_12 , L_1 , V_17 ) ;
V_15 = V_2 -> V_12 -> V_20 -> V_21 . V_22 ;
F_2 ( V_12 , L_2 , V_15 ) ;
V_16 = V_8 -> V_21 . V_23 ;
F_2 ( V_12 , L_3 , V_16 ) ;
V_6 = F_3 ( sizeof( struct V_5 ) ,
V_24 ) ;
if ( ! V_6 )
return - V_25 ;
F_4 ( & V_6 -> V_26 ) ;
if ( V_15 == 1 ) {
if ( V_2 -> V_9 -> V_27 == 2 )
V_8 = & V_2 -> V_9 -> V_19 [ 1 ] ;
else if ( V_2 -> V_9 -> V_27 > 2 )
goto V_28;
if ( V_8 -> V_21 . V_29 == 2 &&
F_5 ( & V_8 -> V_30 [ 0 ] . V_21 ) &&
F_6 ( & V_8 -> V_30 [ 1 ] . V_21 ) ) {
F_2 ( V_12 , L_4 ) ;
if ( V_2 -> V_9 -> V_27 == 1 )
V_13 = 0 ;
else
V_19 = 1 ;
}
goto V_28;
}
if ( V_4 -> V_31 & V_32 ) {
F_2 ( V_12 , L_5 ) ;
V_19 = 0 ;
goto V_28;
}
if ( V_15 < 3 || V_15 > 4 ) {
F_7 ( V_12 , L_6 , V_15 ) ;
goto V_28;
}
V_19 = 0 ;
if ( V_17 ) {
if ( V_16 == 2 )
F_2 ( V_12 , L_7 ) ;
else
V_19 = - 1 ;
} else {
switch ( V_16 ) {
case 0 :
V_19 = - 1 ;
break;
case 1 :
F_2 ( V_12 , L_8 ) ;
break;
case 2 :
F_2 ( V_12 , L_7 ) ;
break;
case 3 :
F_2 ( V_12 , L_9 ) ;
break;
}
}
V_28:
if ( V_19 >= 0 ) {
V_13 = F_8 ( V_2 -> V_12 , V_16 , V_19 ) ;
if ( V_13 < 0 ) {
F_7 ( V_12 ,
L_10 ,
V_13 ) ;
V_13 = - V_14 ;
}
}
if ( V_13 == 0 )
F_9 ( V_2 , V_6 ) ;
else
F_10 ( V_6 ) ;
return V_13 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_33 = F_12 ( V_2 ) ;
F_9 ( V_2 , NULL ) ;
F_10 ( V_33 ) ;
}
