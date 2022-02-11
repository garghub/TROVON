static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( & V_2 -> V_6 , NULL ) ;
if ( F_3 ( V_4 ) ) {
F_4 ( & V_2 -> V_6 , L_1 ) ;
return F_5 ( V_4 ) ;
}
V_5 = F_6 ( V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_7 ( V_2 ,
& V_7 ) ;
if ( V_5 )
F_8 ( V_4 ) ;
return V_5 ;
}
