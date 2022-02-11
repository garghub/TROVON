static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL ;
struct V_14 * V_15 ;
int V_16 = 0 ;
T_1 V_17 = 0 ;
V_11 = F_2 ( & V_2 -> V_6 , sizeof( * V_11 ) , V_18 ) ;
if ( ! V_11 )
return - V_19 ;
V_4 = F_3 ( V_20 , & V_2 -> V_6 ) ;
if ( ! V_4 )
return - V_21 ;
V_11 -> V_22 = (enum V_23 ) V_4 -> V_24 ;
V_11 -> V_25 = F_4 ( & V_2 -> V_6 , NULL ) ;
if ( F_5 ( V_11 -> V_25 ) ) {
F_6 ( V_6 , L_1 ) ;
return F_7 ( V_11 -> V_25 ) ;
}
V_16 = F_8 ( V_11 -> V_25 ) ;
if ( V_16 ) {
F_6 ( V_6 , L_2 ) ;
return V_16 ;
}
V_16 = F_9 ( V_8 , L_3 ,
& V_17 ) ;
if ( ! V_16 ) {
V_11 -> V_26 = V_27 ;
switch ( V_17 ) {
case 4 :
V_11 -> V_28 = V_29 ;
break;
case 5 :
if ( V_11 -> V_22 == V_30 ) {
V_11 -> V_28 =
V_31 ;
break;
}
default:
F_6 ( & V_2 -> V_6 ,
L_4
, V_17 ) ;
V_16 = - V_21 ;
goto V_32;
}
} else {
V_11 -> V_26 = V_33 ;
}
F_10 ( V_2 , V_11 ) ;
V_15 = F_11 ( V_2 , V_34 , 0 ) ;
if ( ! V_15 )
return - V_19 ;
switch ( V_11 -> V_22 ) {
case V_35 :
V_36 [ V_37 ] = * V_15 ;
V_38 [ V_37 ] = * V_15 ;
V_13 = V_39 ;
break;
case V_30 :
V_40 [ V_37 ] = * V_15 ;
V_41 [ V_37 ] = * V_15 ;
V_13 = V_42 ;
break;
default:
F_6 ( V_6 , L_5 ) ;
V_16 = - V_43 ;
goto V_32;
}
V_16 = F_12 ( & V_2 -> V_6 , V_44 ,
& V_13 [ V_45 ] , 1 , NULL , 0 , NULL ) ;
if ( V_16 ) {
F_6 ( & V_2 -> V_6 , L_6 ) ;
goto V_32;
}
if ( ! V_11 -> V_28 )
return 0 ;
V_16 = F_12 ( & V_2 -> V_6 , V_44 ,
& V_13 [ V_46 ] , 1 , NULL , 0 , NULL ) ;
if ( V_16 ) {
F_6 ( & V_2 -> V_6 ,
L_7 ) ;
goto V_32;
}
return 0 ;
V_32:
F_13 ( V_11 -> V_25 ) ;
return V_16 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_15 ( V_2 ) ;
F_13 ( V_11 -> V_25 ) ;
return 0 ;
}
