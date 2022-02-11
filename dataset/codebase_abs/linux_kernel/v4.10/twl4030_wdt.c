static int F_1 ( unsigned char V_1 )
{
return F_2 ( V_2 , V_1 ,
V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_6 + 1 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
return F_1 ( 0 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
V_5 -> V_6 = V_6 ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
int V_9 = 0 ;
struct V_4 * V_5 ;
V_5 = F_7 ( & V_8 -> V_10 , sizeof( * V_5 ) , V_11 ) ;
if ( ! V_5 )
return - V_12 ;
V_5 -> V_13 = & V_14 ;
V_5 -> V_15 = & V_16 ;
V_5 -> V_17 = 0 ;
V_5 -> V_6 = 30 ;
V_5 -> V_18 = 1 ;
V_5 -> V_19 = 30 ;
V_5 -> V_20 = & V_8 -> V_10 ;
F_8 ( V_5 , V_21 ) ;
F_9 ( V_8 , V_5 ) ;
F_4 ( V_5 ) ;
V_9 = F_10 ( V_5 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_12 ( V_8 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 , T_1 V_22 )
{
struct V_4 * V_5 = F_12 ( V_8 ) ;
if ( F_15 ( V_5 ) )
return F_4 ( V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = F_12 ( V_8 ) ;
if ( F_15 ( V_5 ) )
return F_3 ( V_5 ) ;
return 0 ;
}
