static T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 ,
T_2 * V_6 )
{
struct V_7 V_8 ;
T_1 V_9 ;
if ( V_7 ( V_2 , 'P' , & V_8 ) || V_8 . V_10 != 2 ||
V_8 . V_11 < 0x2c )
return 0 ;
V_9 = F_2 ( V_2 , V_8 . V_12 + 0x2c ) ;
if ( ! V_9 )
return 0 ;
* V_3 = F_3 ( V_2 , V_9 ) ;
switch ( * V_3 ) {
case 0x20 :
case 0x30 :
* V_4 = F_3 ( V_2 , V_9 + 0x1 ) ;
* V_6 = F_3 ( V_2 , V_9 + 0x2 ) ;
* V_5 = F_3 ( V_2 , V_9 + 0x3 ) ;
return V_9 ;
default:
break;
}
return 0 ;
}
int
F_4 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_2 V_3 , V_4 , V_5 , V_6 , V_17 ;
T_1 V_18 ;
if ( ! V_2 || ! V_14 )
return - V_19 ;
V_18 = F_1 ( V_2 , & V_3 , & V_4 , & V_5 , & V_6 ) ;
if ( ! V_18 || ! V_5 )
return - V_20 ;
switch ( V_3 ) {
case 0x20 :
V_17 = F_3 ( V_2 , V_18 + 0x9 ) ;
break;
case 0x30 :
V_17 = F_3 ( V_2 , V_18 + 0xa ) ;
break;
default:
V_17 = 0xff ;
}
if ( V_17 >= V_5 && V_17 != 0xff ) {
F_5 ( V_16 ,
L_1 ) ;
V_14 -> V_17 = 0xff ;
return - V_19 ;
}
V_14 -> V_12 = V_18 ;
V_14 -> V_3 = V_3 ;
V_14 -> V_21 = V_4 ;
V_14 -> V_22 = V_6 ;
V_14 -> V_23 = V_5 ;
V_14 -> V_17 = V_17 ;
return 0 ;
}
int
F_6 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
T_2 V_24 , struct F_6 * V_25 )
{
T_1 V_26 ;
if ( ! V_2 || ! V_14 || ! V_14 -> V_12 || V_24 >= V_14 -> V_23
|| ! V_25 )
return - V_19 ;
V_26 = V_14 -> V_12 + V_14 -> V_21 + V_24 * V_14 -> V_22 ;
if ( V_14 -> V_3 >= 0x20 ) {
V_25 -> V_27 = F_2 ( V_2 , V_26 + 0x2 ) ;
V_25 -> V_28 = F_2 ( V_2 , V_26 + 0x6 ) ;
V_25 -> V_29 = F_2 ( V_2 , V_26 + 0xa ) ;
} else {
V_25 -> V_27 = 0 ;
V_25 -> V_29 = F_2 ( V_2 , V_26 + 0x2 ) ;
V_25 -> V_28 = V_25 -> V_29 ;
}
return 0 ;
}
