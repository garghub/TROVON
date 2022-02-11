T_1 F_1 ( struct V_1 * V_1 ,
const struct V_2 * V_3 ,
T_2 V_4 , int V_5 )
{
T_1 V_6 ;
struct V_7 * V_8 = F_2 ( V_1 ) ;
struct V_9 * V_9 = F_3 ( V_1 , struct V_9 , V_1 ) ;
int V_10 = V_3 == NULL ? - 1 : F_4 ( V_3 ) ;
struct V_2 * V_11 ;
T_2 V_12 = F_5 ( V_4 , V_13 ) ;
F_6 ( 5 , V_8 , L_1 ,
V_1 , V_3 , V_4 ) ;
V_6 = - V_14 ;
if ( V_4 > V_15 )
goto V_16;
if ( V_3 != V_1 -> V_17 )
memmove ( V_1 -> V_17 , V_3 , V_4 ) ;
V_11 = V_1 -> V_17 ;
if ( V_12 > V_4 )
memset ( V_1 -> V_17 + V_4 , 0 , V_12 - V_4 ) ;
if ( ( V_5 & V_18 ) == 0 ) {
if ( F_7 ( F_8 ( V_11 ) == 0 ) )
F_9 ( V_8 , L_2 ) ;
F_10 ( V_11 ) ;
}
F_11 ( 4 , V_8 , L_3 ,
V_10 , V_4 , V_12 ) ;
F_12 ( 5 , V_8 , V_11 , V_4 ) ;
F_13 ( V_9 -> V_19 ) ;
V_6 = F_14 ( V_9 -> V_19 , V_20 ,
V_1 -> V_17 , V_12 ) ;
F_15 ( V_9 -> V_19 ) ;
if ( V_6 < 0 ) {
F_16 ( V_8 , L_4 ,
V_10 , ( long ) V_6 ) ;
goto V_21;
}
V_6 = V_4 ;
V_21:
V_16:
F_17 ( 5 , V_8 , L_5 ,
V_1 , V_3 , V_4 , ( int ) V_6 ) ;
return V_6 ;
}
T_1 F_18 ( struct V_1 * V_1 ,
struct V_2 * V_22 ,
T_2 V_23 )
{
T_1 V_6 ;
struct V_9 * V_9 = F_3 ( V_1 , struct V_9 , V_1 ) ;
struct V_24 * V_19 = V_9 -> V_19 ;
struct V_7 * V_8 = & V_19 -> V_8 ;
int V_25 ;
F_19 ( sizeof( * V_22 ) > V_23 ) ;
F_6 ( 5 , V_8 , L_6 ,
V_1 , V_22 , V_23 ) ;
V_6 = F_20 ( V_9 -> V_26 ,
V_9 -> V_27 != - V_28 ,
2 * V_29 ) ;
if ( V_6 == 0 ) {
V_6 = - V_30 ;
F_16 ( V_8 , L_7 ) ;
goto V_31;
}
F_21 ( & V_1 -> V_32 ) ;
V_6 = V_9 -> V_27 ;
F_19 ( V_6 == - V_28 ) ;
if ( V_6 < 0 )
F_16 ( V_8 , L_8 , V_33 , V_6 ) ;
else {
V_25 = F_22 ( V_23 , V_9 -> V_27 ) ;
memcpy ( V_22 , V_1 -> V_34 , V_25 ) ;
}
V_9 -> V_27 = - V_28 ;
F_23 ( & V_1 -> V_32 ) ;
V_31:
F_17 ( 5 , V_8 , L_9 ,
V_1 , V_22 , V_23 , V_6 ) ;
return V_6 ;
}
