static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
unsigned int V_12 , V_13 ;
V_13 = V_14 | V_15 ;
V_11 = F_2 ( V_10 , V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_2 ( V_9 , V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 = F_3 ( V_4 ) * 256 ;
return F_4 ( V_9 , 0 , V_12 , V_16 ) ;
}
static int F_5 ( struct V_5 * V_6 )
{
struct V_17 * V_18 = V_6 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
F_6 ( V_20 , V_21 ,
F_7 ( V_21 ) ) ;
F_8 ( V_20 , V_22 , F_7 ( V_22 ) ) ;
F_9 ( V_20 , L_1 ) ;
F_9 ( V_20 , L_2 ) ;
F_9 ( V_20 , L_3 ) ;
return 0 ;
}
static int T_1 F_10 ( void )
{
int V_11 ;
if ( ! F_11 () )
return 0 ;
V_23 = F_12 ( L_4 , - 1 ) ;
if ( ! V_23 )
return - V_24 ;
F_13 ( V_23 ,
& V_25 ) ;
V_11 = F_14 ( V_23 ) ;
if ( V_11 ) {
F_15 ( V_26 L_5 , V_27 ) ;
F_16 ( V_23 ) ;
}
return V_11 ;
}
static void T_2 F_17 ( void )
{
F_18 ( V_23 ) ;
}
