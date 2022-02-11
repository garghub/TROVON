static void F_1 ( void )
{
if ( V_1 -> V_2 == V_3 )
return;
F_2 ( V_1 -> V_4 , V_5 ,
V_6 ) ;
F_3 ( 500 ) ;
}
int F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
const struct V_11 * V_12 ;
const struct V_13 * V_14 ;
if ( V_10 -> V_15 ) {
V_14 = F_5 ( V_10 -> V_16 -> V_17 , V_10 ) ;
if ( ! V_14 ) {
F_6 ( V_10 , L_1 ) ;
return - V_18 ;
}
V_8 -> V_2 = ( long ) V_14 -> V_19 ;
} else {
V_12 = F_7 ( V_10 -> V_16 -> V_20 , V_10 ) ;
if ( ! V_12 || ! V_12 -> V_21 ) {
F_6 ( V_10 , L_2 ) ;
return - V_18 ;
}
V_8 -> V_2 = ( long ) V_12 -> V_21 ;
}
switch ( V_8 -> V_2 ) {
case V_22 :
V_8 -> V_23 = F_8 ( V_24 ) ;
V_8 -> V_25 = V_24 ;
V_8 -> V_26 = & V_27 ;
V_8 -> V_28 = & V_29 ;
break;
case V_30 :
case V_31 :
V_8 -> V_23 = F_8 ( V_32 ) ;
V_8 -> V_25 = V_32 ;
V_8 -> V_26 = & V_33 ;
V_8 -> V_28 = & V_34 ;
break;
case V_35 :
V_8 -> V_23 = F_8 ( V_36 ) ;
V_8 -> V_25 = V_36 ;
V_8 -> V_26 = & V_37 ;
V_8 -> V_28 = & V_38 ;
break;
case V_39 :
V_8 -> V_23 = F_8 ( V_40 ) ;
V_8 -> V_25 = V_40 ;
V_8 -> V_26 = & V_37 ;
V_8 -> V_28 = & V_38 ;
break;
case V_3 :
V_8 -> V_25 = V_41 ;
V_8 -> V_23 = F_8 ( V_41 ) ;
V_8 -> V_26 = & V_42 ;
V_8 -> V_28 = & V_43 ;
V_8 -> V_44 = V_45 ;
break;
case V_46 :
V_8 -> V_23 = F_8 ( V_47 ) ;
V_8 -> V_25 = V_47 ;
V_8 -> V_26 = & V_42 ;
V_8 -> V_28 = & V_48 ;
break;
case V_49 :
V_8 -> V_23 = F_8 ( V_50 ) ;
V_8 -> V_25 = V_50 ;
V_8 -> V_26 = & V_51 ;
V_8 -> V_28 = & V_52 ;
break;
case V_53 :
V_8 -> V_23 = F_8 ( V_54 ) ;
V_8 -> V_25 = V_54 ;
V_8 -> V_26 = & V_37 ;
V_8 -> V_28 = & V_55 ;
break;
default:
F_6 ( V_10 , L_3 , V_8 -> V_2 ) ;
return - V_56 ;
}
F_9 ( V_10 , L_4 ,
V_57 [ V_8 -> V_2 ] ) ;
return 0 ;
}
int F_10 ( struct V_7 * V_8 )
{
int V_58 ;
if ( V_8 -> V_2 == V_49 ) {
if ( F_11 ( V_8 -> V_10 -> V_15 ,
L_5 ) )
F_2 ( V_8 -> V_4 , V_59 ,
V_60 ) ;
else
F_2 ( V_8 -> V_4 , V_59 ,
V_61 ) ;
}
V_58 = F_12 ( V_8 -> V_4 , V_8 -> V_62 ,
V_63 | V_64 | V_8 -> V_44 ,
- 1 , V_8 -> V_28 , & V_8 -> V_65 ) ;
if ( V_58 ) {
F_6 ( V_8 -> V_10 , L_6 , V_58 ) ;
return V_58 ;
}
V_58 = F_13 ( V_8 -> V_10 , - 1 , V_8 -> V_25 ,
V_8 -> V_23 , NULL , 0 , NULL ) ;
if ( V_58 ) {
F_6 ( V_8 -> V_10 , L_7 , V_58 ) ;
F_14 ( V_8 -> V_62 , V_8 -> V_65 ) ;
return V_58 ;
}
if ( ! V_66 ) {
V_1 = V_8 ;
V_66 = F_1 ;
}
F_9 ( V_8 -> V_10 , L_8 ) ;
return 0 ;
}
int F_15 ( struct V_7 * V_8 )
{
if ( V_8 == V_1 ) {
V_1 = NULL ;
V_66 = NULL ;
}
F_16 ( V_8 -> V_10 ) ;
F_14 ( V_8 -> V_62 , V_8 -> V_65 ) ;
return 0 ;
}
