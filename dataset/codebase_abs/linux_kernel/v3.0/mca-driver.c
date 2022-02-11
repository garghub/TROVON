int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_4 ) {
V_2 -> V_5 . V_6 = & V_7 ;
if ( ( V_3 = F_2 ( & V_2 -> V_5 ) ) < 0 )
return V_3 ;
V_2 -> V_8 = 0 ;
}
return 0 ;
}
int F_3 ( struct V_1 * V_1 ,
int V_8 )
{
int V_3 = F_1 ( V_1 ) ;
if ( ! V_3 )
V_1 -> V_8 = V_8 ;
return V_3 ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( V_4 )
F_5 ( & V_2 -> V_5 ) ;
}
