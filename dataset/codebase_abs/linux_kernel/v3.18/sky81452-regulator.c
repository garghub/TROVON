static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_3 -> V_7 -> V_8 , L_1 ) ;
if ( F_3 ( ! V_6 ) ) {
F_4 ( V_3 , L_2 ) ;
return NULL ;
}
V_4 = F_5 ( V_3 , V_6 ) ;
F_6 ( V_6 ) ;
return V_4 ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_7 ( - V_9 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = & V_11 -> V_3 ;
const struct V_1 * V_4 = F_9 ( V_3 ) ;
struct V_12 V_13 = { } ;
struct V_14 * V_15 ;
if ( ! V_4 ) {
V_4 = F_1 ( V_3 ) ;
if ( F_10 ( V_4 ) )
return F_11 ( V_4 ) ;
}
V_13 . V_3 = V_3 ;
V_13 . V_4 = V_4 ;
V_13 . V_8 = V_3 -> V_8 ;
V_13 . V_16 = F_12 ( V_3 -> V_7 ) ;
V_15 = F_13 ( V_3 , & V_17 , & V_13 ) ;
if ( F_10 ( V_15 ) )
return F_11 ( V_15 ) ;
F_14 ( V_11 , V_15 ) ;
return 0 ;
}
