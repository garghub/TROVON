static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( V_5 , V_4 -> V_6 + ( V_2 ? V_7 : V_8 ) ) ;
}
static void F_3 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( V_9 , V_4 -> V_6 + ( V_2 ? V_7 : V_8 ) ) ;
}
static int F_4 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return ! ! ( F_5 ( V_4 -> V_6 + V_10 ) & V_5 ) ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return ! ! ( F_5 ( V_4 -> V_6 + V_10 ) & V_9 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_15 ;
V_4 = F_8 ( & V_12 -> V_12 , sizeof( struct V_3 ) , V_16 ) ;
if ( ! V_4 )
return - V_17 ;
V_14 = F_9 ( V_12 , V_18 , 0 ) ;
V_4 -> V_6 = F_10 ( & V_12 -> V_12 , V_14 ) ;
if ( F_11 ( V_4 -> V_6 ) )
return F_12 ( V_4 -> V_6 ) ;
F_2 ( V_9 | V_5 , V_4 -> V_6 + V_7 ) ;
V_4 -> V_19 . V_20 = V_21 ;
F_13 ( V_4 -> V_19 . V_22 , L_1 , sizeof( V_4 -> V_19 . V_22 ) ) ;
V_4 -> V_19 . V_23 = & V_4 -> V_24 ;
V_4 -> V_19 . V_12 . V_25 = & V_12 -> V_12 ;
V_4 -> V_19 . V_12 . V_26 = V_12 -> V_12 . V_26 ;
V_4 -> V_24 = V_27 ;
V_4 -> V_24 . V_1 = V_4 ;
V_4 -> V_19 . V_28 = V_12 -> V_29 ;
V_15 = F_14 ( & V_4 -> V_19 ) ;
if ( V_15 < 0 )
return V_15 ;
F_15 ( V_12 , V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_17 ( V_12 ) ;
F_18 ( & V_4 -> V_19 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_30 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_30 ) ;
}
