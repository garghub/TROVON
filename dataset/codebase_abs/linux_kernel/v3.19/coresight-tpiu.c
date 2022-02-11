static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_6 . V_7 ) ;
int V_8 ;
V_8 = F_6 ( V_2 -> V_9 ) ;
if ( V_8 )
return V_8 ;
F_1 ( V_2 ) ;
F_7 ( V_2 -> V_6 , L_1 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_9 ( 0x0 , V_2 -> V_3 + V_10 ) ;
F_9 ( V_11 , V_2 -> V_3 + V_10 ) ;
F_3 ( V_2 -> V_3 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_6 . V_7 ) ;
F_8 ( V_2 ) ;
F_11 ( V_2 -> V_9 ) ;
F_7 ( V_2 -> V_6 , L_2 ) ;
}
static int F_12 ( struct V_12 * V_13 , const struct V_14 * V_15 )
{
int V_8 ;
void T_1 * V_3 ;
struct V_16 * V_6 = & V_13 -> V_6 ;
struct V_17 * V_18 = NULL ;
struct V_1 * V_2 ;
struct V_19 * V_20 = & V_13 -> V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 = V_13 -> V_6 . V_25 ;
if ( V_24 ) {
V_18 = F_13 ( V_6 , V_24 ) ;
if ( F_14 ( V_18 ) )
return F_15 ( V_18 ) ;
V_13 -> V_6 . V_26 = V_18 ;
}
V_2 = F_16 ( V_6 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_6 = & V_13 -> V_6 ;
F_17 ( V_6 , V_2 ) ;
V_3 = F_18 ( V_6 , V_20 ) ;
if ( F_14 ( V_3 ) )
return F_15 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_9 = V_13 -> V_29 ;
V_8 = F_6 ( V_2 -> V_9 ) ;
if ( V_8 )
return V_8 ;
F_8 ( V_2 ) ;
F_11 ( V_2 -> V_9 ) ;
V_22 = F_16 ( V_6 , sizeof( * V_22 ) , V_27 ) ;
if ( ! V_22 )
return - V_28 ;
V_22 -> type = V_30 ;
V_22 -> V_31 . V_32 = V_33 ;
V_22 -> V_34 = & V_35 ;
V_22 -> V_18 = V_18 ;
V_22 -> V_6 = V_6 ;
V_2 -> V_5 = F_19 ( V_22 ) ;
if ( F_14 ( V_2 -> V_5 ) )
return F_15 ( V_2 -> V_5 ) ;
F_7 ( V_6 , L_3 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_21 ( V_13 ) ;
F_22 ( V_2 -> V_5 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_36 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_36 ) ;
}
