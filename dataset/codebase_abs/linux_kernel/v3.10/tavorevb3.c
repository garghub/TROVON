static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 = F_2 ( F_3 ( V_4 ) ) ;
int V_12 ;
V_12 = F_4 ( V_10 , V_13 , 0 ,
V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_9 , 0 , 0 , V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_10 , 3 , 3 , 2 , V_11 ) ;
return V_12 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_17 * V_18 = & V_16 -> V_18 ;
F_7 ( V_18 , L_1 ) ;
F_7 ( V_18 , L_2 ) ;
F_7 ( V_18 , L_3 ) ;
F_8 ( V_18 , L_4 ) ;
F_8 ( V_18 , L_5 ) ;
F_9 ( V_16 , L_6 , V_19
| V_20 | V_21 | V_22 ,
& V_23 ) ;
F_10 ( & V_23 , F_11 ( V_24 ) ,
V_24 ) ;
F_9 ( V_16 , L_7 , V_25 ,
& V_26 ) ;
F_10 ( & V_26 , F_11 ( V_27 ) ,
V_27 ) ;
F_12 ( V_16 , & V_23 , V_19 ,
V_20 , V_21 , V_22 ) ;
F_13 ( V_16 , & V_23 , V_25 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
int V_12 ;
if ( ! F_15 () )
return - V_28 ;
V_29 = F_16 ( L_8 , - 1 ) ;
if ( ! V_29 )
return - V_30 ;
F_17 ( V_29 , & V_31 ) ;
V_12 = F_18 ( V_29 ) ;
if ( V_12 )
F_19 ( V_29 ) ;
return V_12 ;
}
static void T_2 F_20 ( void )
{
F_21 ( V_29 ) ;
}
