static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 , V_2 -> V_4 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_3 , V_2 -> V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_3 , V_2 -> V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 & V_6 )
return F_3 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
bool V_7 = false ;
V_7 = F_11 ( V_2 -> V_3 , V_2 -> V_4 ) ;
if ( ! V_7 && ( V_2 -> V_5 & V_8 ) )
F_1 ( V_2 ) ;
return 0 ;
}
