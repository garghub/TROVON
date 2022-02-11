static T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ! V_3 ( V_2 , 'P' , & V_4 ) ) {
if ( V_4 . V_5 == 2 )
return F_2 ( V_2 , V_4 . V_6 + 0x38 ) ;
}
return 0x0000 ;
}
int
F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
if ( ! V_8 )
return - V_9 ;
V_8 -> V_6 = F_1 ( V_2 ) ;
if ( ! V_8 -> V_6 )
return - V_10 ;
V_8 -> V_5 = F_4 ( V_2 , V_8 -> V_6 ) ;
switch ( V_8 -> V_5 ) {
case 0x10 :
V_8 -> V_11 = F_4 ( V_2 , V_8 -> V_6 + 0x1 ) ;
V_8 -> V_12 = F_4 ( V_2 , V_8 -> V_6 + 0x2 ) ;
V_8 -> V_13 = F_4 ( V_2 , V_8 -> V_6 + 0x3 ) ;
V_8 -> V_14 = F_4 ( V_2 , V_8 -> V_6 + 0x4 ) ;
V_8 -> V_15 = F_4 ( V_2 , V_8 -> V_6 + 0x5 ) ;
V_8 -> V_16 = F_4 ( V_2 , V_8 -> V_6 + 0x0f ) ;
V_8 -> V_17 = F_4 ( V_2 , V_8 -> V_6 + 0x10 ) ;
V_8 -> V_18 = F_4 ( V_2 , V_8 -> V_6 + 0x11 ) ;
return 0 ;
default:
return - V_9 ;
}
}
int
F_5 ( struct V_1 * V_2 , struct V_7 * V_8 ,
T_2 V_19 , struct F_5 * V_20 )
{
T_1 V_6 ;
if ( ! V_20 || ! V_8 || V_19 > V_8 -> V_15 )
return - V_9 ;
V_6 = V_8 -> V_6 + V_8 -> V_11 + V_19 * ( V_8 -> V_12 + ( V_8 -> V_13 * V_8 -> V_14 ) ) ;
V_20 -> V_21 = F_4 ( V_2 , V_6 ) ;
V_20 -> V_22 = F_6 ( V_2 , V_6 + 0x5 ) ;
return 0 ;
}
