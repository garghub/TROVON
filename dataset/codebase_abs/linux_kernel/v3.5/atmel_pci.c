static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( F_2 ( V_2 ) )
return - V_7 ;
F_3 ( V_2 ) ;
V_6 = F_4 ( V_2 -> V_8 , V_2 -> V_9 [ 1 ] . V_10 ,
V_11 ,
& V_2 -> V_6 , NULL , NULL ) ;
if ( ! V_6 )
return - V_7 ;
F_5 ( V_2 , V_6 ) ;
return 0 ;
}
static void T_2 F_6 ( struct V_1 * V_2 )
{
F_7 ( F_8 ( V_2 ) ) ;
}
