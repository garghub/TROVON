static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_1 ) ;
return V_5 ;
}
V_7 . V_8 = V_2 ;
V_9 . V_8 = V_2 ;
return F_4 ( & V_2 -> V_6 , - 1 ,
V_10 ,
F_5 ( V_10 ) ,
NULL , 0 , NULL ) ;
}
