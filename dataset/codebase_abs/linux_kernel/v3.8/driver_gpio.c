static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ! ! F_4 ( & V_5 -> V_6 , 1 << V_4 ) ;
}
static void F_5 ( struct V_2 * V_3 , unsigned V_4 ,
int V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_6 ( & V_5 -> V_6 , 1 << V_4 , V_7 ? 1 << V_4 : 0 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_8 ( & V_5 -> V_6 , 1 << V_4 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 ,
unsigned V_4 , int V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_8 ( & V_5 -> V_6 , 1 << V_4 , 1 << V_4 ) ;
F_6 ( & V_5 -> V_6 , 1 << V_4 , V_7 ? 1 << V_4 : 0 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_11 ( & V_5 -> V_6 , 1 << V_4 , 0 ) ;
F_12 ( & V_5 -> V_6 , 1 << V_4 , 0 ) ;
F_13 ( & V_5 -> V_6 , 1 << V_4 , 1 << V_4 ) ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_13 ( & V_5 -> V_6 , 1 << V_4 , 0 ) ;
}
static int F_15 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_4 ;
V_3 -> V_8 = L_1 ;
V_3 -> V_9 = V_10 ;
V_3 -> V_11 = F_10 ;
V_3 -> free = F_14 ;
V_3 -> V_12 = F_3 ;
V_3 -> V_13 = F_5 ;
V_3 -> V_14 = F_7 ;
V_3 -> V_15 = F_9 ;
V_3 -> V_16 = 16 ;
if ( V_5 -> V_17 == V_18 )
V_3 -> V_19 = 0 ;
else
V_3 -> V_19 = - 1 ;
return F_16 ( V_3 ) ;
}
static int F_17 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ! ! F_18 ( & V_5 -> V_20 , 1 << V_4 ) ;
}
static void F_19 ( struct V_2 * V_3 , unsigned V_4 ,
int V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_20 ( & V_5 -> V_20 , 1 << V_4 , V_7 ? 1 << V_4 : 0 ) ;
}
static int F_21 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_22 ( & V_5 -> V_20 , 1 << V_4 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
unsigned V_4 , int V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_22 ( & V_5 -> V_20 , 1 << V_4 , 1 << V_4 ) ;
F_20 ( & V_5 -> V_20 , 1 << V_4 , V_7 ? 1 << V_4 : 0 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = & V_5 -> V_4 ;
V_3 -> V_8 = L_2 ;
V_3 -> V_9 = V_10 ;
V_3 -> V_12 = F_17 ;
V_3 -> V_13 = F_19 ;
V_3 -> V_14 = F_21 ;
V_3 -> V_15 = F_23 ;
V_3 -> V_16 = 5 ;
if ( V_5 -> V_17 == V_18 )
V_3 -> V_19 = 0 ;
else
V_3 -> V_19 = - 1 ;
return F_16 ( V_3 ) ;
}
static int F_24 ( struct V_1 * V_5 )
{
return - V_21 ;
}
int F_25 ( struct V_1 * V_5 )
{
if ( F_26 ( & V_5 -> V_6 ) )
return F_15 ( V_5 ) ;
else if ( F_27 ( & V_5 -> V_20 ) )
return F_24 ( V_5 ) ;
else
F_28 ( 1 ) ;
return - 1 ;
}
int F_29 ( struct V_1 * V_5 )
{
if ( F_26 ( & V_5 -> V_6 ) ||
F_27 ( & V_5 -> V_20 ) ) {
return F_30 ( & V_5 -> V_4 ) ;
} else {
F_28 ( 1 ) ;
}
return - 1 ;
}
