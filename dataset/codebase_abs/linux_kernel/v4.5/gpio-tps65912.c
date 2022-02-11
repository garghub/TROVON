static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
int V_7 ;
V_7 = F_3 ( V_6 , V_8 + V_3 ) ;
if ( V_7 & V_9 )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
if ( V_10 )
F_5 ( V_6 , V_8 + V_3 ,
V_11 ) ;
else
F_6 ( V_6 , V_8 + V_3 ,
V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 ,
int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
F_4 ( V_2 , V_3 , V_10 ) ;
return F_5 ( V_6 , V_8 + V_3 ,
V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
return F_6 ( V_6 , V_8 + V_3 ,
V_12 ) ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_6 * V_6 = F_10 ( V_14 -> V_15 . V_16 ) ;
struct V_17 * V_18 = F_11 ( V_6 -> V_15 ) ;
struct V_4 * V_5 ;
int V_19 ;
V_5 = F_12 ( & V_14 -> V_15 , sizeof( * V_5 ) ,
V_20 ) ;
if ( V_5 == NULL )
return - V_21 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_1 = V_22 ;
V_5 -> V_1 . V_16 = & V_14 -> V_15 ;
if ( V_18 && V_18 -> V_23 )
V_5 -> V_1 . V_24 = V_18 -> V_23 ;
V_19 = F_13 ( & V_5 -> V_1 , V_5 ) ;
if ( V_19 < 0 ) {
F_14 ( & V_14 -> V_15 , L_1 , V_19 ) ;
return V_19 ;
}
F_15 ( V_14 , V_5 ) ;
return V_19 ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = F_17 ( V_14 ) ;
F_18 ( & V_5 -> V_1 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_25 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_25 ) ;
}
