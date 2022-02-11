static T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ! V_3 ( V_2 , 'P' , & V_4 ) ) {
if ( V_4 . V_5 == 2 && V_4 . V_6 >= 0x3c )
return F_2 ( V_2 , V_4 . V_7 + 0x38 ) ;
}
return 0x0000 ;
}
int
F_3 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( ! V_9 )
return - V_10 ;
V_9 -> V_7 = F_1 ( V_2 ) ;
if ( ! V_9 -> V_7 )
return - V_11 ;
V_9 -> V_5 = F_4 ( V_2 , V_9 -> V_7 ) ;
switch ( V_9 -> V_5 ) {
case 0x10 :
V_9 -> V_12 = F_4 ( V_2 , V_9 -> V_7 + 0x1 ) ;
V_9 -> V_13 = F_4 ( V_2 , V_9 -> V_7 + 0x2 ) ;
V_9 -> V_14 = F_4 ( V_2 , V_9 -> V_7 + 0x3 ) ;
V_9 -> V_15 = F_4 ( V_2 , V_9 -> V_7 + 0x4 ) ;
V_9 -> V_16 = F_4 ( V_2 , V_9 -> V_7 + 0x5 ) ;
V_9 -> V_17 = F_4 ( V_2 , V_9 -> V_7 + 0x0f ) ;
V_9 -> V_18 = F_4 ( V_2 , V_9 -> V_7 + 0x10 ) ;
V_9 -> V_19 = F_4 ( V_2 , V_9 -> V_7 + 0x11 ) ;
return 0 ;
default:
return - V_10 ;
}
}
int
F_5 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_2 V_20 , struct F_5 * V_21 )
{
T_1 V_7 ;
if ( ! V_21 || ! V_9 || V_20 > V_9 -> V_16 )
return - V_10 ;
V_7 = V_9 -> V_7 + V_9 -> V_12 + V_20 * ( V_9 -> V_13 + ( V_9 -> V_14 * V_9 -> V_15 ) ) ;
V_21 -> V_22 = F_4 ( V_2 , V_7 ) ;
V_21 -> V_23 = F_6 ( V_2 , V_7 + 0x5 ) ;
return 0 ;
}
