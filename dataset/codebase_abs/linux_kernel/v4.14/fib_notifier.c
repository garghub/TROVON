int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
enum V_4 V_5 ,
struct V_6 * V_7 )
{
V_7 -> V_8 = V_9 ;
return F_2 ( V_2 , V_3 , V_5 , V_7 ) ;
}
int F_3 ( struct V_3 * V_3 , enum V_4 V_5 ,
struct V_6 * V_7 )
{
F_4 () ;
V_7 -> V_8 = V_9 ;
V_3 -> V_10 . V_11 ++ ;
return F_5 ( V_3 , V_5 , V_7 ) ;
}
static unsigned int F_6 ( struct V_3 * V_3 )
{
F_4 () ;
return V_3 -> V_10 . V_11 + F_7 ( V_3 ) ;
}
static int F_8 ( struct V_3 * V_3 , struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_9 ( V_3 , V_2 ) ;
if ( V_12 )
return V_12 ;
F_10 ( V_3 , V_2 ) ;
return 0 ;
}
int T_1 F_11 ( struct V_3 * V_3 )
{
struct V_13 * V_14 ;
V_3 -> V_10 . V_11 = 0 ;
V_14 = F_12 ( & V_15 , V_3 ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
V_3 -> V_10 . V_16 = V_14 ;
return 0 ;
}
void T_2 F_15 ( struct V_3 * V_3 )
{
F_16 ( V_3 -> V_10 . V_16 ) ;
}
