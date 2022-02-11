static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
return F_4 ( V_6 , V_7 ,
1 << V_4 ) ;
}
static int F_5 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_8 ;
V_8 = F_6 ( V_6 , V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & ( 1 << V_4 ) )
return 1 ;
else
return 0 ;
}
static void F_7 ( struct V_2 * V_3 , unsigned V_4 , int V_10 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
if ( V_10 )
F_4 ( V_6 , V_9 , 1 << V_4 ) ;
else
F_8 ( V_6 , V_9 , 1 << V_4 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
unsigned V_4 , int V_10 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_8 ;
V_8 = F_8 ( V_6 , V_7 ,
1 << V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
F_7 ( V_3 , V_4 , V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
if ( ! V_6 -> V_11 )
return - V_12 ;
return V_6 -> V_11 + F_11 ( V_4 ) ;
}
static int T_1 F_12 ( struct V_13 * V_14 )
{
struct V_6 * V_6 = F_13 ( V_14 -> V_15 . V_16 ) ;
struct V_17 * V_18 = V_6 -> V_15 -> V_19 ;
struct V_1 * V_5 ;
int V_8 ;
V_5 = F_14 ( sizeof( * V_5 ) , V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_2 = V_22 ;
V_5 -> V_2 . V_23 = 13 ;
V_5 -> V_2 . V_15 = & V_14 -> V_15 ;
if ( V_18 && V_18 -> V_24 )
V_5 -> V_2 . V_25 = V_18 -> V_24 ;
else
V_5 -> V_2 . V_25 = - 1 ;
V_8 = F_15 ( & V_5 -> V_2 ) ;
if ( V_8 < 0 ) {
F_16 ( & V_14 -> V_15 , L_1 ,
V_8 ) ;
goto V_26;
}
F_17 ( V_14 , V_5 ) ;
return V_8 ;
V_26:
F_18 ( V_5 ) ;
return V_8 ;
}
static int T_2 F_19 ( struct V_13 * V_14 )
{
struct V_1 * V_5 = F_20 ( V_14 ) ;
int V_8 ;
V_8 = F_21 ( & V_5 -> V_2 ) ;
if ( V_8 == 0 )
F_18 ( V_5 ) ;
return V_8 ;
}
static int T_3 F_22 ( void )
{
return F_23 ( & V_27 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_27 ) ;
}
