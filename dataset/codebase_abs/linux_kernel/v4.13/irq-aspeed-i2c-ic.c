static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned long V_7 , V_8 ;
unsigned int V_9 ;
F_4 ( V_6 , V_2 ) ;
V_8 = F_5 ( V_4 -> V_10 ) ;
F_6 (bit, &status, ASPEED_I2C_IC_NUM_BUS) {
V_9 = F_7 ( V_4 -> V_11 , V_7 ) ;
F_8 ( V_9 ) ;
}
F_9 ( V_6 , V_2 ) ;
}
static int F_10 ( struct V_11 * V_12 ,
unsigned int V_13 , T_1 V_14 )
{
F_11 ( V_13 , & V_15 , V_16 ) ;
F_12 ( V_13 , V_12 -> V_17 ) ;
return 0 ;
}
static int T_2 F_13 ( struct V_18 * V_19 ,
struct V_18 * V_20 )
{
struct V_3 * V_4 ;
int V_21 = 0 ;
V_4 = F_14 ( sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_10 = F_15 ( V_19 , 0 ) ;
if ( F_16 ( V_4 -> V_10 ) ) {
V_21 = F_17 ( V_4 -> V_10 ) ;
goto V_24;
}
V_4 -> V_25 = F_18 ( V_19 , 0 ) ;
if ( V_4 -> V_25 < 0 ) {
V_21 = V_4 -> V_25 ;
goto V_26;
}
V_4 -> V_11 = F_19 ( V_19 , V_27 ,
& V_28 ,
NULL ) ;
if ( ! V_4 -> V_11 ) {
V_21 = - V_23 ;
goto V_26;
}
V_4 -> V_11 -> V_29 = L_1 ;
F_20 ( V_4 -> V_25 ,
F_1 , V_4 ) ;
F_21 ( L_2 , V_4 -> V_25 ) ;
return 0 ;
V_26:
F_22 ( V_4 -> V_10 ) ;
V_24:
F_23 ( V_4 ) ;
return V_21 ;
}
