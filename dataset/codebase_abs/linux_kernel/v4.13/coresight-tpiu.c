static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_3 ) ;
}
static int F_4 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_7 . V_8 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 -> V_7 , L_1 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_8 ( 0x0 , V_2 -> V_3 + V_9 ) ;
F_8 ( V_10 , V_2 -> V_3 + V_9 ) ;
F_3 ( V_2 -> V_3 ) ;
}
static void F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_7 . V_8 ) ;
F_7 ( V_2 ) ;
F_6 ( V_2 -> V_7 , L_2 ) ;
}
static int F_10 ( struct V_11 * V_12 , const struct V_13 * V_14 )
{
int V_15 ;
void T_2 * V_3 ;
struct V_16 * V_7 = & V_12 -> V_7 ;
struct V_17 * V_18 = NULL ;
struct V_1 * V_2 ;
struct V_19 * V_20 = & V_12 -> V_20 ;
struct V_21 V_22 = { 0 } ;
struct V_23 * V_24 = V_12 -> V_7 . V_25 ;
if ( V_24 ) {
V_18 = F_11 ( V_7 , V_24 ) ;
if ( F_12 ( V_18 ) )
return F_13 ( V_18 ) ;
V_12 -> V_7 . V_26 = V_18 ;
}
V_2 = F_14 ( V_7 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_7 = & V_12 -> V_7 ;
V_2 -> V_29 = F_15 ( & V_12 -> V_7 , L_3 ) ;
if ( ! F_12 ( V_2 -> V_29 ) ) {
V_15 = F_16 ( V_2 -> V_29 ) ;
if ( V_15 )
return V_15 ;
}
F_17 ( V_7 , V_2 ) ;
V_3 = F_18 ( V_7 , V_20 ) ;
if ( F_12 ( V_3 ) )
return F_13 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
F_7 ( V_2 ) ;
F_19 ( & V_12 -> V_7 ) ;
V_22 . type = V_30 ;
V_22 . V_31 . V_32 = V_33 ;
V_22 . V_34 = & V_35 ;
V_22 . V_18 = V_18 ;
V_22 . V_7 = V_7 ;
V_2 -> V_5 = F_20 ( & V_22 ) ;
if ( F_12 ( V_2 -> V_5 ) )
return F_13 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
if ( V_2 && ! F_12 ( V_2 -> V_29 ) )
F_22 ( V_2 -> V_29 ) ;
return 0 ;
}
static int F_23 ( struct V_16 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
if ( V_2 && ! F_12 ( V_2 -> V_29 ) )
F_16 ( V_2 -> V_29 ) ;
return 0 ;
}
