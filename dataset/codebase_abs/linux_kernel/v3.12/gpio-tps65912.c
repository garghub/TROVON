static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_5 ) ;
int V_6 ;
V_6 = F_3 ( V_4 , V_7 + V_3 ) ;
if ( V_6 & V_8 )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_9 )
{
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_5 ) ;
if ( V_9 )
F_5 ( V_4 , V_7 + V_3 ,
V_10 ) ;
else
F_6 ( V_4 , V_7 + V_3 ,
V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 ,
int V_9 )
{
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_5 ) ;
F_4 ( V_2 , V_3 , V_9 ) ;
return F_5 ( V_4 , V_7 + V_3 ,
V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_5 ) ;
return F_6 ( V_4 , V_7 + V_3 ,
V_11 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_4 * V_4 = F_10 ( V_13 -> V_14 . V_15 ) ;
struct V_16 * V_17 = F_11 ( V_4 -> V_14 ) ;
struct V_18 * V_19 ;
int V_20 ;
V_19 = F_12 ( & V_13 -> V_14 , sizeof( * V_19 ) ,
V_21 ) ;
if ( V_19 == NULL )
return - V_22 ;
V_19 -> V_4 = V_4 ;
V_19 -> V_1 = V_23 ;
V_19 -> V_1 . V_14 = & V_13 -> V_14 ;
if ( V_17 && V_17 -> V_24 )
V_19 -> V_1 . V_25 = V_17 -> V_24 ;
V_20 = F_13 ( & V_19 -> V_1 ) ;
if ( V_20 < 0 ) {
F_14 ( & V_13 -> V_14 , L_1 , V_20 ) ;
return V_20 ;
}
F_15 ( V_13 , V_19 ) ;
return V_20 ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_18 * V_19 = F_17 ( V_13 ) ;
return F_18 ( & V_19 -> V_1 ) ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_26 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_26 ) ;
}
