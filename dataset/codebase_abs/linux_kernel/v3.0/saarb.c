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
V_12 = F_5 ( V_10 , V_15 |
V_16 | V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_9 , V_15 |
V_16 | V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_10 , 3 , 3 , 2 , V_11 ) ;
return V_12 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_19 ;
struct V_20 * V_21 = & V_19 -> V_21 ;
int V_12 ;
F_8 ( V_21 , V_22 ,
F_9 ( V_22 ) ) ;
F_10 ( V_21 , V_23 , F_9 ( V_23 ) ) ;
F_11 ( V_21 , L_1 ) ;
F_11 ( V_21 , L_2 ) ;
F_11 ( V_21 , L_3 ) ;
F_12 ( V_21 , L_4 ) ;
F_12 ( V_21 , L_5 ) ;
V_12 = F_13 ( V_21 ) ;
if ( V_12 )
return V_12 ;
F_14 ( V_19 , L_6 , V_24
| V_25 | V_26 | V_27 ,
& V_28 ) ;
F_15 ( & V_28 , F_9 ( V_29 ) ,
V_29 ) ;
F_14 ( V_19 , L_7 , V_30 ,
& V_31 ) ;
F_15 ( & V_31 , F_9 ( V_32 ) ,
V_32 ) ;
F_16 ( V_19 , & V_28 , V_24 ,
V_25 , V_26 , V_27 ) ;
F_17 ( V_19 , & V_28 , V_30 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
int V_12 ;
if ( ! F_19 () )
return - V_33 ;
V_34 = F_20 ( L_8 , - 1 ) ;
if ( ! V_34 )
return - V_35 ;
F_21 ( V_34 , & V_36 ) ;
V_12 = F_22 ( V_34 ) ;
if ( V_12 )
F_23 ( V_34 ) ;
return V_12 ;
}
static void T_2 F_24 ( void )
{
F_25 ( V_34 ) ;
}
