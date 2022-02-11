int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_2 V_8 ;
F_4 ( V_5 , L_1 ) ;
F_5 ( & V_7 -> V_9 ) ;
F_6 ( & V_7 -> V_10 ) ;
V_7 -> V_11 = 0 ;
if ( ! F_7 ( V_5 ) ) {
F_4 ( V_5 ,
L_2 ) ;
goto V_12;
}
if ( V_5 -> V_13 -> V_14 )
V_5 -> V_13 -> V_14 ( V_5 ) ;
F_8 ( V_5 ) ;
if ( ! V_7 -> V_15 -> V_16 ) {
F_9 ( V_5 , V_17 , V_18 , true ) ;
V_8 = F_10 ( V_5 , V_19 ) ;
V_8 |= V_20 ;
F_11 ( V_5 , V_19 , V_8 ) ;
} else {
F_11 ( V_5 , V_21 , 0xffffffff ) ;
F_11 ( V_5 , V_22 , 0xffffffff ) ;
F_11 ( V_5 , V_23 , 0xffffffff ) ;
F_12 ( V_5 , V_24 , 0x5 ) ;
F_12 ( V_5 , V_25 , 0xa ) ;
}
V_12:
F_4 ( V_5 , L_3 , V_7 -> V_15 -> V_16 ?
L_4 : L_5 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 , F_16 ( V_2 , V_3 ) ,
V_7 -> V_15 -> V_16 ? 1 : 0 ) ;
F_17 ( V_2 , F_16 ( V_2 , V_3 ) ) ;
F_18 ( 20 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_26 ;
T_2 V_27 ;
F_4 ( V_5 , L_6 ) ;
F_17 ( V_2 , V_28 ) ;
V_26 = F_20 ( V_2 ) ;
if ( V_26 ) {
F_21 ( V_5 , L_7 ) ;
return V_26 ;
}
F_22 ( V_2 ) ;
F_23 ( V_2 , 0x40 , & V_27 ) ;
if ( ( V_27 & 0x0000ff00 ) != 0 )
F_24 ( V_2 , 0x40 , V_27 & 0xffff00ff ) ;
F_15 ( V_2 , V_28 , 0 ) ;
if ( V_7 -> V_11 == 0 )
F_25 ( ( unsigned long ) V_5 ) ;
if ( ! F_7 ( V_5 ) ) {
F_4 ( V_5 ,
L_8 ) ;
goto V_29;
}
F_26 ( V_5 ) ;
if ( V_5 -> V_13 -> V_30 )
V_5 -> V_13 -> V_30 ( V_5 ) ;
if ( ! V_7 -> V_15 -> V_16 )
F_9 ( V_5 , V_31 , V_18 , true ) ;
V_29:
F_27 ( V_32 , L_9 ) ;
return 0 ;
}
