static void F_1 ( void )
{
if ( V_1 -> V_2 == V_3 )
return;
F_2 ( V_1 -> V_4 , V_5 ,
V_6 ) ;
}
int F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
const struct V_11 * V_12 ;
const struct V_13 * V_14 ;
if ( V_10 -> V_15 ) {
V_14 = F_4 ( V_10 -> V_16 -> V_17 , V_10 ) ;
if ( ! V_14 ) {
F_5 ( V_10 , L_1 ) ;
return - V_18 ;
}
V_8 -> V_2 = ( long ) V_14 -> V_19 ;
} else {
V_12 = F_6 ( V_10 -> V_16 -> V_20 , V_10 ) ;
if ( ! V_12 || ! V_12 -> V_21 ) {
F_5 ( V_10 , L_2 ) ;
return - V_18 ;
}
V_8 -> V_2 = ( long ) V_12 -> V_21 ;
}
switch ( V_8 -> V_2 ) {
case V_22 :
V_8 -> V_23 = F_7 ( V_24 ) ;
V_8 -> V_25 = V_24 ;
V_8 -> V_26 = & V_27 ;
V_8 -> V_28 = & V_29 ;
break;
case V_30 :
case V_31 :
V_8 -> V_23 = F_7 ( V_32 ) ;
V_8 -> V_25 = V_32 ;
V_8 -> V_26 = & V_33 ;
V_8 -> V_28 = & V_34 ;
break;
case V_35 :
case V_36 :
V_8 -> V_23 = F_7 ( V_37 ) ;
V_8 -> V_25 = V_37 ;
V_8 -> V_26 = & V_38 ;
V_8 -> V_28 = & V_39 ;
break;
case V_3 :
V_8 -> V_25 = V_40 ;
V_8 -> V_23 = F_7 ( V_40 ) ;
V_8 -> V_26 = & V_41 ;
V_8 -> V_28 = & V_42 ;
break;
default:
F_5 ( V_10 , L_3 , V_8 -> V_2 ) ;
return - V_43 ;
}
F_8 ( V_10 , L_4 ,
V_44 [ V_8 -> V_2 ] ) ;
return 0 ;
}
int F_9 ( struct V_7 * V_8 )
{
int V_45 ;
V_45 = F_10 ( V_8 -> V_4 , V_8 -> V_46 ,
V_47 | V_48 , - 1 ,
V_8 -> V_28 ,
& V_8 -> V_49 ) ;
if ( V_45 ) {
F_5 ( V_8 -> V_10 , L_5 , V_45 ) ;
return V_45 ;
}
V_45 = F_11 ( V_8 -> V_10 , - 1 , V_8 -> V_25 ,
V_8 -> V_23 , NULL , 0 , NULL ) ;
if ( V_45 ) {
F_5 ( V_8 -> V_10 , L_6 , V_45 ) ;
F_12 ( V_8 -> V_46 , V_8 -> V_49 ) ;
return V_45 ;
}
if ( ! V_50 ) {
V_1 = V_8 ;
V_50 = F_1 ;
}
F_8 ( V_8 -> V_10 , L_7 ) ;
return 0 ;
}
int F_13 ( struct V_7 * V_8 )
{
if ( V_8 == V_1 ) {
V_1 = NULL ;
V_50 = NULL ;
}
F_14 ( V_8 -> V_10 ) ;
F_12 ( V_8 -> V_46 , V_8 -> V_49 ) ;
return 0 ;
}
