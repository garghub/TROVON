static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_10 , 0xfffffffc , 0xfffffffc ,
4 , 16 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_3 ( V_10 , V_12 , 26000000 , 0 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_2 ( V_9 , 0x0 , 0xfffffffc , 2 , 16 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int T_1 F_4 ( struct V_13 * V_14 )
{
int V_11 ;
V_15 . V_16 = & V_14 -> V_16 ;
V_11 = F_5 ( & V_15 ) ;
if ( V_11 ) {
F_6 ( & V_14 -> V_16 , L_1 ,
V_11 ) ;
return V_11 ;
}
if ( F_7 () ) {
F_8 ( V_17 ,
V_18 ,
F_9 ( V_19 ) |
F_10 ( 1 ) |
F_11 ( 0xfc ) ) ;
F_8 ( V_19 ,
V_18 |
V_20 |
F_12 ( V_17 ) |
V_21 |
F_13 ( V_17 ) |
V_22 |
F_14 ( V_17 ) |
V_23 |
F_15 ( V_17 ) ,
F_9 ( V_17 ) ) ;
} else if ( F_16 () ) {
F_17 ( V_24 ,
V_25 |
V_26 |
V_27 |
V_28 |
V_29 |
F_18 ( V_30 ) |
F_19 ( V_30 ) |
F_20 ( V_30 )
) ;
F_17 ( V_30 ,
V_25 |
F_20 ( V_24 )
) ;
}
return V_11 ;
}
static int T_2 F_21 ( struct V_13 * V_14 )
{
F_22 ( & V_15 ) ;
return 0 ;
}
