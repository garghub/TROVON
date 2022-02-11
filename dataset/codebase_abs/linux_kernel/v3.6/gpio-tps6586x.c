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
static int T_2 F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
struct V_1 * V_1 ;
int V_7 ;
V_16 = F_9 ( V_14 -> V_17 . V_8 ) ;
V_1 = F_10 ( & V_14 -> V_17 ,
sizeof( * V_1 ) , V_18 ) ;
if ( ! V_1 ) {
F_11 ( & V_14 -> V_17 , L_1 ) ;
return - V_19 ;
}
V_1 -> V_8 = V_14 -> V_17 . V_8 ;
V_1 -> V_2 . V_20 = V_21 ;
V_1 -> V_2 . V_22 = V_14 -> V_23 ;
V_1 -> V_2 . V_17 = & V_14 -> V_17 ;
V_1 -> V_2 . V_24 = 4 ;
V_1 -> V_2 . V_25 = 1 ;
V_1 -> V_2 . V_26 = F_7 ;
V_1 -> V_2 . V_27 = F_5 ;
V_1 -> V_2 . V_28 = F_3 ;
#ifdef F_12
V_1 -> V_2 . V_29 = V_14 -> V_17 . V_8 -> V_29 ;
#endif
if ( V_16 && V_16 -> V_30 )
V_1 -> V_2 . V_31 = V_16 -> V_30 ;
else
V_1 -> V_2 . V_31 = - 1 ;
V_7 = F_13 ( & V_1 -> V_2 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_14 -> V_17 , L_2 , V_7 ) ;
return V_7 ;
}
F_14 ( V_14 , V_1 ) ;
return V_7 ;
}
static int T_3 F_15 ( struct V_13 * V_14 )
{
struct V_1 * V_1 = F_16 ( V_14 ) ;
return F_17 ( & V_1 -> V_2 ) ;
}
static int T_4 F_18 ( void )
{
return F_19 ( & V_32 ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( & V_32 ) ;
}
