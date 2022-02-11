static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
return F_3 ( V_6 , V_7 ,
1 << V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_8 ;
V_8 = F_5 ( V_6 , V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & ( 1 << V_3 ) )
return 1 ;
else
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
if ( V_10 )
F_3 ( V_6 , V_9 , 1 << V_3 ) ;
else
F_7 ( V_6 , V_9 , 1 << V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_8 ;
V_8 = F_7 ( V_6 , V_7 ,
1 << V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
F_6 ( V_2 , V_3 , V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
if ( ! V_6 -> V_11 )
return - V_12 ;
return V_6 -> V_11 + F_10 ( V_3 ) ;
}
static int F_11 ( struct V_13 * V_14 )
{
struct V_6 * V_6 = F_12 ( V_14 -> V_15 . V_16 ) ;
struct V_17 * V_18 = F_13 ( V_6 -> V_15 ) ;
struct V_4 * V_5 ;
int V_8 ;
V_5 = F_14 ( & V_14 -> V_15 , sizeof( * V_5 ) ,
V_19 ) ;
if ( V_5 == NULL )
return - V_20 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_1 = V_21 ;
V_5 -> V_1 . V_22 = 13 ;
V_5 -> V_1 . V_16 = & V_14 -> V_15 ;
if ( V_18 && V_18 -> V_23 )
V_5 -> V_1 . V_24 = V_18 -> V_23 ;
else
V_5 -> V_1 . V_24 = - 1 ;
V_8 = F_15 ( & V_14 -> V_15 , & V_5 -> V_1 ,
V_5 ) ;
if ( V_8 < 0 ) {
F_16 ( & V_14 -> V_15 , L_1 , V_8 ) ;
return V_8 ;
}
F_17 ( V_14 , V_5 ) ;
return V_8 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_25 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_25 ) ;
}
