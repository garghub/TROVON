static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_6 . V_7 ) ;
F_6 ( V_5 -> V_6 . V_7 ) ;
F_1 ( V_2 ) ;
F_7 ( V_2 -> V_6 , L_1 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_9 ( 0x0 , V_2 -> V_3 + V_8 ) ;
F_9 ( V_9 , V_2 -> V_3 + V_8 ) ;
F_3 ( V_2 -> V_3 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_6 . V_7 ) ;
F_8 ( V_2 ) ;
F_11 ( V_5 -> V_6 . V_7 ) ;
F_7 ( V_2 -> V_6 , L_2 ) ;
}
static int F_12 ( struct V_10 * V_11 , const struct V_12 * V_13 )
{
int V_14 ;
void T_1 * V_3 ;
struct V_15 * V_6 = & V_11 -> V_6 ;
struct V_16 * V_17 = NULL ;
struct V_1 * V_2 ;
struct V_18 * V_19 = & V_11 -> V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 = V_11 -> V_6 . V_24 ;
if ( V_23 ) {
V_17 = F_13 ( V_6 , V_23 ) ;
if ( F_14 ( V_17 ) )
return F_15 ( V_17 ) ;
V_11 -> V_6 . V_25 = V_17 ;
}
V_2 = F_16 ( V_6 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return - V_27 ;
V_2 -> V_6 = & V_11 -> V_6 ;
V_2 -> V_28 = F_17 ( & V_11 -> V_6 , L_3 ) ;
if ( ! F_14 ( V_2 -> V_28 ) ) {
V_14 = F_18 ( V_2 -> V_28 ) ;
if ( V_14 )
return V_14 ;
}
F_19 ( V_6 , V_2 ) ;
V_3 = F_20 ( V_6 , V_19 ) ;
if ( F_14 ( V_3 ) )
return F_15 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
F_8 ( V_2 ) ;
F_11 ( & V_11 -> V_6 ) ;
V_21 = F_16 ( V_6 , sizeof( * V_21 ) , V_26 ) ;
if ( ! V_21 )
return - V_27 ;
V_21 -> type = V_29 ;
V_21 -> V_30 . V_31 = V_32 ;
V_21 -> V_33 = & V_34 ;
V_21 -> V_17 = V_17 ;
V_21 -> V_6 = V_6 ;
V_2 -> V_5 = F_21 ( V_21 ) ;
if ( F_14 ( V_2 -> V_5 ) )
return F_15 ( V_2 -> V_5 ) ;
F_7 ( V_6 , L_4 ) ;
return 0 ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_23 ( V_11 ) ;
F_24 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_25 ( struct V_15 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
if ( V_2 && ! F_14 ( V_2 -> V_28 ) )
F_26 ( V_2 -> V_28 ) ;
return 0 ;
}
static int F_27 ( struct V_15 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
if ( V_2 && ! F_14 ( V_2 -> V_28 ) )
F_18 ( V_2 -> V_28 ) ;
return 0 ;
}
