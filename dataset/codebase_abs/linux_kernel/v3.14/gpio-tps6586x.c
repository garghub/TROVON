static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_1 V_6 ;
int V_7 ;
V_7 = F_4 ( V_1 -> V_8 , V_9 , & V_6 ) ;
if ( V_7 )
return V_7 ;
return ! ! ( V_6 & ( 1 << V_5 ) ) ;
}
static void F_5 ( struct V_2 * V_4 , unsigned V_5 ,
int V_10 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_6 ( V_1 -> V_8 , V_9 ,
V_10 << V_5 , 1 << V_5 ) ;
}
static int F_7 ( struct V_2 * V_4 , unsigned V_5 ,
int V_10 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
T_1 V_6 , V_11 ;
F_5 ( V_4 , V_5 , V_10 ) ;
V_6 = 0x1 << ( V_5 * 2 ) ;
V_11 = 0x3 << ( V_5 * 2 ) ;
return F_6 ( V_1 -> V_8 , V_12 ,
V_6 , V_11 ) ;
}
static int F_8 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
return F_9 ( V_1 -> V_8 ,
V_13 + V_5 ) ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
struct V_1 * V_1 ;
int V_7 ;
V_17 = F_11 ( V_15 -> V_18 . V_8 ) ;
V_1 = F_12 ( & V_15 -> V_18 ,
sizeof( * V_1 ) , V_19 ) ;
if ( ! V_1 ) {
F_13 ( & V_15 -> V_18 , L_1 ) ;
return - V_20 ;
}
V_1 -> V_8 = V_15 -> V_18 . V_8 ;
V_1 -> V_2 . V_21 = V_22 ;
V_1 -> V_2 . V_23 = V_15 -> V_24 ;
V_1 -> V_2 . V_18 = & V_15 -> V_18 ;
V_1 -> V_2 . V_25 = 4 ;
V_1 -> V_2 . V_26 = true ;
V_1 -> V_2 . V_27 = F_7 ;
V_1 -> V_2 . V_28 = F_5 ;
V_1 -> V_2 . V_29 = F_3 ;
V_1 -> V_2 . V_30 = F_8 ;
#ifdef F_14
V_1 -> V_2 . V_31 = V_15 -> V_18 . V_8 -> V_31 ;
#endif
if ( V_17 && V_17 -> V_32 )
V_1 -> V_2 . V_33 = V_17 -> V_32 ;
else
V_1 -> V_2 . V_33 = - 1 ;
V_7 = F_15 ( & V_1 -> V_2 ) ;
if ( V_7 < 0 ) {
F_13 ( & V_15 -> V_18 , L_2 , V_7 ) ;
return V_7 ;
}
F_16 ( V_15 , V_1 ) ;
return V_7 ;
}
static int F_17 ( struct V_14 * V_15 )
{
struct V_1 * V_1 = F_18 ( V_15 ) ;
return F_19 ( & V_1 -> V_2 ) ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_34 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_34 ) ;
}
