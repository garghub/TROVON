static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
V_6 = F_2 ( V_2 , & V_7 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
for ( V_5 = 0 ; V_5 < F_5 ( V_8 ) ; V_5 ++ )
F_6 ( V_6 , V_8 [ V_5 ] . V_9 , V_8 [ V_5 ] . V_10 ) ;
return F_7 ( & V_2 -> V_11 , & V_12 , NULL , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_11 ) ;
return 0 ;
}
