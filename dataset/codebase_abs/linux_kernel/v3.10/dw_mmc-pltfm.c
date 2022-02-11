int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_6 = F_2 ( & V_2 -> V_10 , sizeof( struct V_5 ) , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
V_8 = F_3 ( V_2 , V_13 , 0 ) ;
if ( ! V_8 )
return - V_14 ;
V_6 -> V_15 = F_4 ( V_2 , 0 ) ;
if ( V_6 -> V_15 < 0 )
return V_6 -> V_15 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_10 = & V_2 -> V_10 ;
V_6 -> V_16 = 0 ;
V_6 -> V_17 = V_2 -> V_10 . V_18 ;
V_6 -> V_8 = F_5 ( & V_2 -> V_10 , V_8 ) ;
if ( F_6 ( V_6 -> V_8 ) )
return F_7 ( V_6 -> V_8 ) ;
if ( V_4 && V_4 -> V_19 ) {
V_9 = V_4 -> V_19 ( V_6 ) ;
if ( V_9 )
return V_9 ;
}
F_8 ( V_2 , V_6 ) ;
V_9 = F_9 ( V_6 ) ;
return V_9 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , NULL ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_12 ( V_2 ) ;
F_8 ( V_2 , NULL ) ;
F_13 ( V_6 ) ;
return 0 ;
}
static int F_14 ( struct V_20 * V_10 )
{
int V_9 ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
V_9 = F_16 ( V_6 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_17 ( struct V_20 * V_10 )
{
int V_9 ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
V_9 = F_18 ( V_6 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
