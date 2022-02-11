static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 << 8 ;
}
static int F_2 ( const struct V_1 * V_2 , T_1 V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_14 = F_3 ( V_11 -> V_2 , struct V_13 , V_2 ) ;
return F_4 ( V_14 , 5 ) ;
}
static int F_5 ( struct V_13 * V_14 )
{
struct V_10 * V_11 ;
F_6 ( V_15 ) ;
struct V_16 V_17 ;
int V_18 ;
V_11 = F_7 ( & V_14 -> V_2 , sizeof( * V_11 ) , V_19 ) ;
if ( ! V_11 )
return - V_20 ;
V_11 -> V_2 = & V_14 -> V_2 ;
F_8 ( V_14 , V_11 ) ;
V_11 -> V_21 = V_14 -> V_22 ;
V_11 -> V_23 = V_14 -> V_24 ;
V_17 . V_25 = V_14 -> V_26 [ 0 ] ;
V_17 . V_27 = V_14 -> V_26 [ 0 ] + V_28 - 1 ;
V_17 . V_29 = L_1 ;
V_17 . V_30 = V_31 ;
F_9 ( & V_15 , & V_17 ) ;
V_11 -> V_32 = F_2 ;
V_18 = F_10 ( V_11 , & V_15 ) ;
if ( V_18 )
F_11 ( V_11 -> V_2 , L_2 ) ;
F_12 ( & V_15 ) ;
return V_18 ;
}
static void F_13 ( struct V_13 * V_14 )
{
struct V_10 * V_11 = F_14 ( V_14 ) ;
F_15 ( V_11 ) ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_33 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_33 ) ;
}
