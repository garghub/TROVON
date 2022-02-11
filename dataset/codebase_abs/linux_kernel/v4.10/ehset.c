static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 = - V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_7 * V_9 = V_8 -> V_10 ;
struct V_11 * V_12 ;
T_1 V_13 = V_8 -> V_13 ;
T_2 V_14 = F_3 ( V_8 -> V_15 . V_16 ) ;
switch ( V_14 ) {
case V_17 :
V_5 = F_4 ( V_9 , F_5 ( V_9 , 0 ) ,
V_18 , V_19 ,
V_20 ,
( V_21 << 8 ) | V_13 ,
NULL , 0 , 1000 ) ;
break;
case V_22 :
V_5 = F_4 ( V_9 , F_5 ( V_9 , 0 ) ,
V_18 , V_19 ,
V_20 ,
( V_23 << 8 ) | V_13 ,
NULL , 0 , 1000 ) ;
break;
case V_24 :
V_5 = F_4 ( V_9 , F_5 ( V_9 , 0 ) ,
V_18 , V_19 ,
V_20 ,
( V_25 << 8 ) | V_13 ,
NULL , 0 , 1000 ) ;
break;
case V_26 :
V_5 = F_4 ( V_9 , F_5 ( V_9 , 0 ) ,
V_18 , V_19 ,
V_20 ,
( V_27 << 8 ) | V_13 ,
NULL , 0 , 1000 ) ;
break;
case V_28 :
F_6 ( 15 * 1000 ) ;
V_5 = F_4 ( V_9 , F_5 ( V_9 , 0 ) ,
V_18 , V_19 ,
V_29 , V_13 ,
NULL , 0 , 1000 ) ;
if ( V_5 < 0 )
break;
F_6 ( 15 * 1000 ) ;
V_5 = F_4 ( V_9 , F_5 ( V_9 , 0 ) ,
V_30 , V_19 ,
V_29 , V_13 ,
NULL , 0 , 1000 ) ;
break;
case V_31 :
F_6 ( 15 * 1000 ) ;
V_12 = F_7 ( V_32 , V_33 ) ;
if ( ! V_12 )
return - V_34 ;
V_5 = F_4 ( V_8 , F_8 ( V_8 , 0 ) ,
V_35 , V_36 ,
V_37 << 8 , 0 ,
V_12 , V_32 ,
V_38 ) ;
F_9 ( V_12 ) ;
break;
case V_39 :
if ( V_9 != V_8 -> V_40 -> V_41 ) {
F_10 ( & V_2 -> V_8 , L_1 ) ;
break;
}
V_5 = F_4 ( V_9 , F_5 ( V_9 , 0 ) ,
V_18 , V_19 ,
V_20 ,
( 6 << 8 ) | V_13 ,
NULL , 0 , 60 * 1000 ) ;
break;
default:
F_10 ( & V_2 -> V_8 , L_2 ,
V_42 , V_14 ) ;
}
return ( V_5 < 0 ) ? V_5 : 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
}
