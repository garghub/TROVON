static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_2 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_6 = (struct V_5 * ) V_4 -> V_10 ;
V_8 = F_3 ( & V_2 -> V_11 , & V_2 -> V_12 [ 0 ] , V_6 ) ;
if ( F_4 ( V_8 ) )
return F_5 ( V_8 ) ;
F_6 ( V_2 , V_8 ) ;
F_7 ( & V_2 -> V_11 ) ;
F_8 ( & V_2 -> V_11 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_10 ( V_2 ) ;
F_11 ( & V_2 -> V_11 ) ;
F_12 ( & V_2 -> V_11 ) ;
F_13 ( V_8 ) ;
}
static int F_14 ( struct V_13 * V_11 )
{
return 0 ;
}
static int F_15 ( struct V_13 * V_11 )
{
return 0 ;
}
