static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
V_6 -> V_8 ( V_4 -> V_9 , V_2 -> V_10 * V_11 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
V_6 -> V_8 ( V_4 -> V_9 , 0 ) ;
return 0 ;
}
static int V_8 ( struct V_1 * V_2 , unsigned V_12 )
{
V_2 -> V_10 = V_12 ;
return F_1 ( V_2 ) ;
}
static int F_4 ( struct V_13 * V_14 )
{
int V_15 ;
F_5 ( & V_16 , & V_14 -> V_4 ) ;
V_16 . V_10 = F_6 ( unsigned , V_17 , 1 , V_18 ) ;
V_15 = F_7 ( & V_16 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_14 -> V_4 , L_1 ) ;
return V_15 ;
}
F_9 ( & V_14 -> V_4 , L_2 ,
V_16 . V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 )
{
F_11 ( & V_16 ) ;
return 0 ;
}
