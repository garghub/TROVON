static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_10 , V_12 |
V_13 |
V_14 ) ;
if ( V_11 ) {
F_3 ( L_1 , V_15 ) ;
return V_11 ;
}
V_11 = F_2 ( V_9 , V_12 |
V_13 |
V_14 ) ;
if ( V_11 ) {
F_3 ( L_2 , V_15 ) ;
return V_11 ;
}
V_11 = F_4 ( V_9 , 0 ,
V_16 , V_17 ) ;
if ( V_11 ) {
F_3 ( L_3 , V_15 ) ;
return V_11 ;
}
F_5 ( V_10 , 0xffffffc , 0xffffffc , 2 , 0 ) ;
V_11 = F_4 ( V_10 , V_18 , 0 ,
V_19 ) ;
if ( V_11 ) {
F_3 ( L_4 ) ;
return V_11 ;
}
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_11 ;
int V_20 = 0 , V_21 ;
if ( F_7 () ) {
F_8 ( V_22 ,
V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
F_9 ( V_28 ) |
F_10 ( V_28 ) |
F_11 ( V_28 )
) ;
F_8 ( V_28 ,
V_23 |
F_11 ( V_22 )
) ;
} else if ( F_12 () ||
F_13 () ||
F_14 () ) {
V_21 = F_12 () ? 4 : 3 ;
F_15 ( V_20 ,
V_29 |
V_30 |
F_16 ( V_21 ) |
V_31 |
F_17 ( V_21 ) ,
F_18 ( V_21 )
) ;
F_15 ( V_21 ,
V_29 ,
F_18 ( V_20 )
) ;
} else {
return 0 ;
}
V_32 = F_19 ( L_5 , - 1 ) ;
if ( ! V_32 )
return - V_33 ;
F_20 ( V_32 , & V_34 ) ;
V_11 = F_21 ( V_32 ) ;
if ( V_11 ) {
F_22 ( V_35 L_6 ) ;
F_23 ( V_32 ) ;
}
return V_11 ;
}
static void T_2 F_24 ( void )
{
F_25 ( V_32 ) ;
}
