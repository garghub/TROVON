int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_4 L_1 , V_3 . V_5 ) ;
return - V_6 ;
}
int F_3 ( struct V_1 * V_7 , T_1 V_3 )
{
struct V_8 * V_2 = F_4 ( V_7 ) ;
struct V_9 * V_10 = F_5 ( V_2 ) ;
T_2 V_11 ;
F_6 ( V_12 , L_2 ) ;
if ( ! F_7 ( V_2 ) )
goto V_13;
if ( V_2 -> V_14 -> V_15 )
V_2 -> V_14 -> V_15 ( V_2 ) ;
if( ! V_10 -> V_16 -> V_17 ) {
F_8 ( V_10 , V_18 , V_19 ) ;
V_11 = F_9 ( V_10 , V_20 ) ;
V_11 |= V_21 ;
F_10 ( V_10 , V_20 , V_11 ) ;
} else {
F_10 ( V_10 , V_22 , 0xffffffff ) ;
F_10 ( V_10 , V_23 , 0xffffffff ) ;
F_10 ( V_10 , V_24 , 0xffffffff ) ;
F_11 ( V_10 , V_25 , 0x5 ) ;
F_11 ( V_10 , V_26 , 0xa ) ;
}
V_13:
F_6 ( V_12 , L_3 ) ;
if( V_10 -> V_16 -> V_17 ) {
F_6 ( V_12 , L_4 ) ;
}
F_12 ( V_2 ) ;
F_13 ( V_7 ) ;
F_14 ( V_7 ) ;
F_15 ( V_7 , F_16 ( V_7 , V_3 ) ,
V_10 -> V_16 -> V_17 ? 1 : 0 ) ;
F_17 ( V_7 , F_16 ( V_7 , V_3 ) ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_7 )
{
struct V_8 * V_2 = F_4 ( V_7 ) ;
int V_27 ;
T_2 V_28 ;
F_6 ( V_12 , L_5 ) ;
F_17 ( V_7 , V_29 ) ;
V_27 = F_19 ( V_7 ) ;
if( V_27 ) {
F_2 ( V_30 L_6 ,
V_2 -> V_31 ) ;
return V_27 ;
}
F_20 ( V_7 ) ;
F_21 ( V_7 , 0x40 , & V_28 ) ;
if ( ( V_28 & 0x0000ff00 ) != 0 ) {
F_22 ( V_7 , 0x40 , V_28 & 0xffff00ff ) ;
}
F_15 ( V_7 , V_29 , 0 ) ;
if( ! F_7 ( V_2 ) )
goto V_32;
F_23 ( V_2 ) ;
if ( V_2 -> V_14 -> V_33 )
V_2 -> V_14 -> V_33 ( V_2 ) ;
V_32:
F_6 ( V_12 , L_7 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , T_1 V_3 , int V_34 )
{
F_2 ( V_4 L_8 ,
V_3 . V_5 , V_34 ) ;
return - V_6 ;
}
