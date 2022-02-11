static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 , & V_7 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
for ( V_6 = 0 ; V_6 < F_5 ( V_8 ) ; V_6 ++ )
F_6 ( V_5 , V_8 [ V_6 ] . V_9 , V_8 [ V_6 ] . V_10 ) ;
return F_7 ( & V_2 -> V_11 ,
& V_12 , NULL , 0 ) ;
}
