static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
T_1 V_12 ;
V_12 = V_13 | V_14 |
V_15 ;
F_2 ( V_9 , V_12 ) ;
F_2 ( V_10 , V_12 ) ;
V_11 = F_3 ( V_9 , 0 ,
25000000 , V_16 ) ;
if ( V_11 ) {
F_4 ( L_1 , V_17 ) ;
return V_11 ;
}
V_11 = F_3 ( V_10 , V_18 , 0 ,
V_19 ) ;
if ( V_11 ) {
F_4 ( L_2 ) ;
return V_11 ;
}
return 0 ;
}
static int T_2 F_5 ( void )
{
int V_11 ;
V_20 = F_6 ( L_3 , - 1 ) ;
if ( ! V_20 )
return - V_21 ;
F_7 ( V_20 , & V_22 ) ;
V_11 = F_8 ( V_20 ) ;
if ( V_11 ) {
F_9 ( V_23 L_4 ) ;
F_10 ( V_20 ) ;
}
F_11 ( V_24 ,
V_25 |
V_26 |
V_27 |
F_12 ( V_28 ) |
F_13 ( V_28 )
) ;
F_11 ( V_28 ,
V_25 |
F_13 ( V_24 )
) ;
return V_11 ;
}
static void T_3 F_14 ( void )
{
F_15 ( V_20 ) ;
}
