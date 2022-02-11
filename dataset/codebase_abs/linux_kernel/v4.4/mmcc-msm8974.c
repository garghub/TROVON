static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 , & V_5 ) ;
if ( F_3 ( V_3 ) )
return F_4 ( V_3 ) ;
F_5 ( & V_6 , V_3 , & V_7 , true ) ;
F_5 ( & V_8 , V_3 , & V_9 , false ) ;
V_4 = F_6 ( V_2 , & V_5 , V_3 ) ;
if ( V_4 )
return V_4 ;
return F_7 ( & V_10 . V_11 , & V_12 . V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_10 . V_11 , & V_12 . V_11 ) ;
return 0 ;
}
