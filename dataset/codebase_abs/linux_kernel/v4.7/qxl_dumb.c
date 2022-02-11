int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * args )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 ;
T_1 V_11 ;
int V_12 ;
struct V_13 V_14 ;
T_1 V_15 , V_16 ;
V_15 = args -> V_17 * ( ( args -> V_18 + 1 ) / 8 ) ;
args -> V_19 = V_15 * args -> V_20 ;
args -> V_19 = F_2 ( args -> V_19 , V_21 ) ;
switch ( args -> V_18 ) {
case 16 :
V_16 = V_22 ;
break;
case 32 :
V_16 = V_23 ;
break;
default:
return - V_24 ;
}
V_14 . V_17 = args -> V_17 ;
V_14 . V_20 = args -> V_20 ;
V_14 . V_25 = V_15 ;
V_14 . V_16 = V_16 ;
V_12 = F_3 ( V_7 , V_2 ,
V_26 ,
args -> V_19 , & V_14 , & V_10 ,
& V_11 ) ;
if ( V_12 )
return V_12 ;
args -> V_15 = V_15 ;
args -> V_11 = V_11 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_11 , T_2 * V_27 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
F_5 ( ! V_27 ) ;
V_29 = F_6 ( V_2 , V_11 ) ;
if ( V_29 == NULL )
return - V_30 ;
V_10 = F_7 ( V_29 ) ;
* V_27 = F_8 ( V_10 ) ;
F_9 ( V_29 ) ;
return 0 ;
}
