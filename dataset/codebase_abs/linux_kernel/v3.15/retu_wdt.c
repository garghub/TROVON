static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 , V_5 ) ;
F_3 ( & V_2 -> V_6 ,
F_4 ( V_5 * V_7 / 2 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 , V_5 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( F_9 ( V_9 ) ,
struct V_1 , V_6 ) ;
F_1 ( V_2 ) ;
}
static int F_10 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
F_5 ( V_2 ) ;
return F_2 ( V_2 -> V_3 , V_4 , V_11 -> V_12 ) ;
}
static int F_12 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
return F_2 ( V_2 -> V_3 , V_4 , V_11 -> V_12 ) ;
}
static int F_14 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
V_11 -> V_12 = V_12 ;
return F_2 ( V_2 -> V_3 , V_4 , V_11 -> V_12 ) ;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_15 * V_3 = F_16 ( V_14 -> V_16 . V_17 ) ;
bool V_18 = V_19 ;
struct V_10 * V_20 ;
struct V_1 * V_2 ;
int V_21 ;
V_20 = F_17 ( & V_14 -> V_16 , sizeof( * V_20 ) , V_22 ) ;
if ( ! V_20 )
return - V_23 ;
V_2 = F_17 ( & V_14 -> V_16 , sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_20 -> V_24 = & V_25 ;
V_20 -> V_26 = & V_27 ;
V_20 -> V_12 = V_5 ;
V_20 -> V_28 = 0 ;
V_20 -> V_29 = V_5 ;
F_18 ( V_20 , V_2 ) ;
F_19 ( V_20 , V_18 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_16 = & V_14 -> V_16 ;
F_20 ( & V_2 -> V_6 , F_7 ) ;
V_21 = F_21 ( V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_18 )
F_13 ( V_20 ) ;
else
F_1 ( V_2 ) ;
F_22 ( V_14 , V_20 ) ;
return 0 ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_10 * V_11 = F_24 ( V_14 ) ;
struct V_1 * V_2 = F_11 ( V_11 ) ;
F_25 ( V_11 ) ;
F_6 ( & V_2 -> V_6 ) ;
return 0 ;
}
