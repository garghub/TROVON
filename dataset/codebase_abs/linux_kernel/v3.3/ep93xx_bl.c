static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_3 ( ( V_3 << 8 ) | V_5 , V_4 -> V_6 ) ;
V_4 -> V_3 = V_3 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_7 . V_3 ;
if ( V_2 -> V_7 . V_8 != V_9 ||
V_2 -> V_7 . V_10 != V_9 )
V_3 = 0 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_3 ;
}
static int T_1 F_6 ( struct V_11 * V_12 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
struct V_13 V_7 ;
V_4 = F_7 ( & V_12 -> V_12 , sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> V_6 = V_16 ;
memset ( & V_7 , 0 , sizeof( struct V_13 ) ) ;
V_7 . type = V_17 ;
V_7 . V_18 = V_19 ;
V_2 = F_8 ( V_12 -> V_20 , & V_12 -> V_12 , V_4 ,
& V_21 , & V_7 ) ;
if ( F_9 ( V_2 ) )
return F_10 ( V_2 ) ;
V_2 -> V_7 . V_3 = V_22 ;
F_11 ( V_12 , V_2 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
F_14 ( V_2 ) ;
F_11 ( V_12 , NULL ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 , T_2 V_23 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
return F_1 ( V_2 , 0 ) ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
