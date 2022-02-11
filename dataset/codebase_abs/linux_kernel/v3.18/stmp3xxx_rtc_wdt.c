static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_6 -> V_7 ( V_4 -> V_8 , V_2 -> V_9 * V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_6 -> V_7 ( V_4 -> V_8 , 0 ) ;
return 0 ;
}
static int V_7 ( struct V_1 * V_2 , unsigned V_11 )
{
V_2 -> V_9 = V_11 ;
return F_1 ( V_2 ) ;
}
static int F_5 ( struct V_12 * V_13 )
{
int V_14 ;
F_6 ( & V_15 , & V_13 -> V_4 ) ;
V_15 . V_9 = F_7 ( unsigned , V_16 , 1 , V_17 ) ;
V_14 = F_8 ( & V_15 ) ;
if ( V_14 < 0 ) {
F_9 ( & V_13 -> V_4 , L_1 ) ;
return V_14 ;
}
F_10 ( & V_13 -> V_4 , L_2 ,
V_15 . V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 )
{
F_12 ( & V_15 ) ;
return 0 ;
}
static int T_1 F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_15 ;
if ( F_14 ( V_2 ) )
return F_4 ( V_2 ) ;
return 0 ;
}
static int T_1 F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_15 ;
if ( F_14 ( V_2 ) )
return F_1 ( V_2 ) ;
return 0 ;
}
