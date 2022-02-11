static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
const struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_6 = F_2 ( V_2 -> V_11 . V_12 -> V_13 , & V_2 -> V_11 ) ;
if ( ! V_6 )
return - V_14 ;
V_4 = ( const struct V_3 * ) V_6 -> V_15 ;
V_10 = F_3 ( V_2 , V_16 , 0 ) ;
V_8 = F_4 ( & V_2 -> V_11 , V_10 , V_4 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
F_7 ( V_2 , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_9 ( V_2 ) ;
return F_10 ( V_8 ) ;
}
