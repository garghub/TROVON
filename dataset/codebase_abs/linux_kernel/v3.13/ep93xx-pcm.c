static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_6 == F_2 ( V_2 ) ) {
V_2 -> V_7 = V_5 ;
return true ;
}
return false ;
}
static struct V_1 * F_3 (
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_13 = F_4 ( V_9 -> V_14 , V_11 ) ;
return F_5 ( F_1 ,
V_13 ) ;
}
static int F_6 ( struct V_15 * V_16 )
{
return F_7 ( & V_16 -> V_17 ,
& V_18 ,
V_19 |
V_20 |
V_21 ) ;
}
static int F_8 ( struct V_15 * V_16 )
{
F_9 ( & V_16 -> V_17 ) ;
return 0 ;
}
