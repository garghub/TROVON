static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 ,
V_12 |
V_13 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_1 ) ;
return V_11 ;
}
V_11 = F_2 ( V_10 ,
V_12 |
V_13 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_2 ) ;
return V_11 ;
}
V_11 = F_4 ( V_9 , 0 , 26000000 ,
V_16 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_3 ) ;
return V_11 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 ,
V_17 |
V_18 |
V_14 ) ;
if ( V_11 ) {
F_3 ( V_15 L_1 ) ;
return V_11 ;
}
V_11 = F_2 ( V_10 ,
V_17 |
V_18 |
V_14 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_2 ) ;
return V_11 ;
}
V_11 = F_4 ( V_9 , 0 , 26000000 ,
V_16 ) ;
if ( V_11 < 0 ) {
F_3 ( V_15 L_3 ) ;
return V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_20 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
int V_11 ;
V_11 = F_7 ( V_22 , V_23 ,
F_8 ( V_23 ) ) ;
if ( V_11 )
return V_11 ;
F_9 ( V_22 , V_24 , F_8 ( V_24 ) ) ;
F_10 ( V_22 , L_4 ) ;
F_10 ( V_22 , L_5 ) ;
F_10 ( V_22 , L_6 ) ;
F_10 ( V_22 , L_7 ) ;
F_10 ( V_22 , L_8 ) ;
F_11 ( V_22 , L_9 ) ;
F_11 ( V_22 , L_10 ) ;
F_11 ( V_22 , L_11 ) ;
F_11 ( V_22 , L_12 ) ;
F_11 ( V_22 , L_13 ) ;
F_11 ( V_22 , L_14 ) ;
F_11 ( V_22 , L_15 ) ;
F_11 ( V_22 , L_16 ) ;
V_11 = F_12 ( V_22 ) ;
return V_11 ;
}
static int F_13 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_20 ;
unsigned short V_25 ;
V_25 = V_20 -> V_26 -> V_27 ( V_20 , V_28 ) ;
V_25 |= V_29 | V_30 | V_31 ;
V_20 -> V_26 -> V_32 ( V_20 , V_28 , V_25 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
int V_11 ;
if ( ! F_15 () )
return - V_33 ;
F_3 ( V_34 L_17 ) ;
V_35 = F_16 ( L_18 , - 1 ) ;
if ( ! V_35 ) {
F_3 ( V_15 L_19 ) ;
return - V_36 ;
}
F_17 ( V_35 , & V_37 ) ;
V_11 = F_18 ( V_35 ) ;
if ( V_11 )
goto V_38;
F_19 ( F_20 ( V_39 , L_20 ) < 0 ) ;
F_21 ( V_39 , 0 ) ;
F_19 ( F_20 ( V_40 , L_21 ) < 0 ) ;
F_21 ( V_40 , 0 ) ;
return 0 ;
V_38:
F_3 ( V_15 L_22 ) ;
F_22 ( V_35 ) ;
return V_11 ;
}
static void T_2 F_23 ( void )
{
F_24 ( V_39 ) ;
F_24 ( V_40 ) ;
F_25 ( V_35 ) ;
}
