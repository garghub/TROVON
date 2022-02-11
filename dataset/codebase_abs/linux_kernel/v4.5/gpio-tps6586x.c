static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
int V_6 ;
V_6 = F_3 ( V_4 -> V_7 , V_8 , & V_5 ) ;
if ( V_6 )
return V_6 ;
return ! ! ( V_5 & ( 1 << V_3 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_9 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_7 , V_8 ,
V_9 << V_3 , 1 << V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 ,
int V_9 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 , V_10 ;
F_4 ( V_2 , V_3 , V_9 ) ;
V_5 = 0x1 << ( V_3 * 2 ) ;
V_10 = 0x3 << ( V_3 * 2 ) ;
return F_5 ( V_4 -> V_7 , V_11 ,
V_5 , V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
return F_8 ( V_4 -> V_7 ,
V_12 + V_3 ) ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
struct V_4 * V_4 ;
int V_6 ;
V_16 = F_10 ( V_14 -> V_17 . V_7 ) ;
V_4 = F_11 ( & V_14 -> V_17 ,
sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
V_4 -> V_7 = V_14 -> V_17 . V_7 ;
V_4 -> V_1 . V_20 = V_21 ;
V_4 -> V_1 . V_22 = V_14 -> V_23 ;
V_4 -> V_1 . V_7 = & V_14 -> V_17 ;
V_4 -> V_1 . V_24 = 4 ;
V_4 -> V_1 . V_25 = true ;
V_4 -> V_1 . V_26 = F_6 ;
V_4 -> V_1 . V_27 = F_4 ;
V_4 -> V_1 . V_28 = F_1 ;
V_4 -> V_1 . V_29 = F_7 ;
#ifdef F_12
V_4 -> V_1 . V_30 = V_14 -> V_17 . V_7 -> V_30 ;
#endif
if ( V_16 && V_16 -> V_31 )
V_4 -> V_1 . V_32 = V_16 -> V_31 ;
else
V_4 -> V_1 . V_32 = - 1 ;
V_6 = F_13 ( & V_4 -> V_1 , V_4 ) ;
if ( V_6 < 0 ) {
F_14 ( & V_14 -> V_17 , L_1 , V_6 ) ;
return V_6 ;
}
F_15 ( V_14 , V_4 ) ;
return V_6 ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_4 * V_4 = F_17 ( V_14 ) ;
F_18 ( & V_4 -> V_1 ) ;
return 0 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_33 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_33 ) ;
}
