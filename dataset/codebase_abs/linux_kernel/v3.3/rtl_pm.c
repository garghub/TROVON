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
F_2 ( V_12 L_2 ) ;
F_6 ( & V_10 -> V_13 ) ;
F_7 ( & V_10 -> V_14 ) ;
V_10 -> V_15 = 0 ;
if ( ! F_8 ( V_2 ) ) {
F_2 ( V_12 L_3
L_4 ) ;
goto V_16;
}
if ( V_2 -> V_17 -> V_18 )
V_2 -> V_17 -> V_18 ( V_2 ) ;
F_9 ( V_2 ) ;
if ( ! V_10 -> V_19 -> V_20 ) {
F_10 ( V_2 , V_21 , V_22 , true ) ;
V_11 = F_11 ( V_2 , V_23 ) ;
V_11 |= V_24 ;
F_12 ( V_2 , V_23 , V_11 ) ;
} else {
F_12 ( V_2 , V_25 , 0xffffffff ) ;
F_12 ( V_2 , V_26 , 0xffffffff ) ;
F_12 ( V_2 , V_27 , 0xffffffff ) ;
F_13 ( V_2 , V_28 , 0x5 ) ;
F_13 ( V_2 , V_29 , 0xa ) ;
}
V_16:
F_2 ( L_5 ) ;
if ( V_10 -> V_19 -> V_20 )
F_14 ( V_30 , L_6
L_7 ) ;
F_15 ( V_7 ) ;
F_16 ( V_7 ) ;
F_17 ( V_7 , F_18 ( V_7 , V_3 ) ,
V_10 -> V_19 -> V_20 ? 1 : 0 ) ;
F_19 ( V_7 , F_18 ( V_7 , V_3 ) ) ;
F_20 ( 20 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_7 )
{
struct V_8 * V_2 = F_4 ( V_7 ) ;
struct V_9 * V_10 = F_5 ( V_2 ) ;
int V_31 ;
T_2 V_32 ;
F_2 ( V_12 L_8 ) ;
F_19 ( V_7 , V_33 ) ;
V_31 = F_22 ( V_7 ) ;
if ( V_31 ) {
F_2 ( V_34 L_9 ,
V_2 -> V_35 ) ;
return V_31 ;
}
F_23 ( V_7 ) ;
F_24 ( V_7 , 0x40 , & V_32 ) ;
if ( ( V_32 & 0x0000ff00 ) != 0 )
F_25 ( V_7 , 0x40 , V_32 & 0xffff00ff ) ;
F_17 ( V_7 , V_33 , 0 ) ;
if ( V_10 -> V_15 == 0 )
F_26 ( ( unsigned long ) V_2 ) ;
if ( ! F_8 ( V_2 ) ) {
F_2 ( V_12 L_10
L_4 ) ;
goto V_36;
}
F_27 ( V_2 ) ;
if ( V_2 -> V_17 -> V_37 )
V_2 -> V_17 -> V_37 ( V_2 ) ;
if ( ! V_10 -> V_19 -> V_20 )
F_10 ( V_2 , V_38 , V_22 , true ) ;
V_36:
F_14 ( V_30 , L_11 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , T_1 V_3 , int V_39 )
{
F_2 ( V_4 L_12 ,
V_3 . V_5 , V_39 ) ;
return - V_6 ;
}
