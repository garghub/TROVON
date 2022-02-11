int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_2 -> V_4 ;
return F_2 ( & V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 ) ;
}
int F_5 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
enum V_7 V_8 )
{
return F_6 ( & V_6 -> V_9 , & V_2 -> V_3 ,
V_8 ) ;
}
void F_7 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
enum V_7 V_8 )
{
F_8 ( V_6 -> V_9 , & V_2 -> V_3 ,
V_8 ) ;
}
