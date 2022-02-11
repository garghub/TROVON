int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_2 V_8 ;
F_4 ( V_9 L_1 ) ;
F_5 ( & V_7 -> V_10 ) ;
F_6 ( & V_7 -> V_11 ) ;
V_7 -> V_12 = 0 ;
if ( ! F_7 ( V_5 ) ) {
F_4 ( V_9 L_2
L_3 ) ;
goto V_13;
}
if ( V_5 -> V_14 -> V_15 )
V_5 -> V_14 -> V_15 ( V_5 ) ;
F_8 ( V_5 ) ;
if ( ! V_7 -> V_16 -> V_17 ) {
F_9 ( V_5 , V_18 , V_19 , true ) ;
V_8 = F_10 ( V_5 , V_20 ) ;
V_8 |= V_21 ;
F_11 ( V_5 , V_20 , V_8 ) ;
} else {
F_11 ( V_5 , V_22 , 0xffffffff ) ;
F_11 ( V_5 , V_23 , 0xffffffff ) ;
F_11 ( V_5 , V_24 , 0xffffffff ) ;
F_12 ( V_5 , V_25 , 0x5 ) ;
F_12 ( V_5 , V_26 , 0xa ) ;
}
V_13:
F_4 ( L_4 ) ;
if ( V_7 -> V_16 -> V_17 )
F_13 ( V_27 , L_5
L_6 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 , F_17 ( V_2 , V_3 ) ,
V_7 -> V_16 -> V_17 ? 1 : 0 ) ;
F_18 ( V_2 , F_17 ( V_2 , V_3 ) ) ;
F_19 ( 20 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_28 ;
T_2 V_29 ;
F_4 ( V_9 L_7 ) ;
F_18 ( V_2 , V_30 ) ;
V_28 = F_21 ( V_2 ) ;
if ( V_28 ) {
F_4 ( V_31 L_8 ,
V_5 -> V_32 ) ;
return V_28 ;
}
F_22 ( V_2 ) ;
F_23 ( V_2 , 0x40 , & V_29 ) ;
if ( ( V_29 & 0x0000ff00 ) != 0 )
F_24 ( V_2 , 0x40 , V_29 & 0xffff00ff ) ;
F_16 ( V_2 , V_30 , 0 ) ;
if ( V_7 -> V_12 == 0 )
F_25 ( ( unsigned long ) V_5 ) ;
if ( ! F_7 ( V_5 ) ) {
F_4 ( V_9 L_9
L_3 ) ;
goto V_33;
}
F_26 ( V_5 ) ;
if ( V_5 -> V_14 -> V_34 )
V_5 -> V_14 -> V_34 ( V_5 ) ;
if ( ! V_7 -> V_16 -> V_17 )
F_9 ( V_5 , V_35 , V_19 , true ) ;
V_33:
F_13 ( V_27 , L_10 ) ;
return 0 ;
}
