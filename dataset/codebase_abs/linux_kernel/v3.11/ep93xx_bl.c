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
static int F_6 ( struct V_11 * V_12 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
struct V_13 V_7 ;
struct V_14 * V_15 ;
V_4 = F_7 ( & V_12 -> V_12 , sizeof( * V_4 ) , V_16 ) ;
if ( ! V_4 )
return - V_17 ;
V_15 = F_8 ( V_12 , V_18 , 0 ) ;
if ( ! V_15 )
return - V_19 ;
V_4 -> V_6 = F_9 ( & V_12 -> V_12 , V_15 -> V_20 ,
F_10 ( V_15 ) ) ;
if ( ! V_4 -> V_6 )
return - V_19 ;
memset ( & V_7 , 0 , sizeof( struct V_13 ) ) ;
V_7 . type = V_21 ;
V_7 . V_22 = V_23 ;
V_2 = F_11 ( V_12 -> V_24 , & V_12 -> V_12 , V_4 ,
& V_25 , & V_7 ) ;
if ( F_12 ( V_2 ) )
return F_13 ( V_2 ) ;
V_2 -> V_7 . V_3 = V_26 ;
F_14 ( V_12 , V_2 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_16 ( V_12 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_27 * V_12 )
{
struct V_1 * V_2 = F_19 ( V_12 ) ;
return F_1 ( V_2 , 0 ) ;
}
static int F_20 ( struct V_27 * V_12 )
{
struct V_1 * V_2 = F_19 ( V_12 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
