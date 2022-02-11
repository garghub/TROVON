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
struct V_15 * V_2 = & V_14 -> V_2 ;
struct V_10 * V_11 ;
F_6 ( V_16 ) ;
struct V_17 V_18 ;
int V_19 ;
V_11 = F_7 ( V_2 , sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 )
return - V_21 ;
V_11 -> V_2 = V_2 ;
V_11 -> type = V_22 ;
V_11 -> V_23 = V_14 -> V_24 ;
if ( ! V_11 -> V_23 ) {
F_8 ( V_2 , L_1 ) ;
return - V_21 ;
}
V_11 -> V_25 = V_14 -> V_26 ;
V_18 . V_27 = V_14 -> V_28 [ 0 ] ;
V_18 . V_29 = V_14 -> V_28 [ 0 ] + V_30 - 1 ;
V_18 . V_31 = L_2 ;
V_18 . V_32 = V_33 ;
F_9 ( & V_16 , & V_18 ) ;
V_11 -> V_34 = F_2 ;
V_19 = F_10 ( V_11 , & V_16 ) ;
if ( V_19 )
F_8 ( V_2 , L_3 ) ;
F_11 ( & V_16 ) ;
F_12 ( V_14 , V_11 ) ;
return V_19 ;
}
static void F_13 ( struct V_13 * V_14 )
{
struct V_10 * V_11 = F_14 ( V_14 ) ;
F_15 ( V_11 ) ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_35 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_35 ) ;
}
