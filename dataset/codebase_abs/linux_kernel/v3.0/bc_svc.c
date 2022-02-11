int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
F_2 ( L_1 , V_2 ) ;
V_4 = F_3 ( V_2 , & V_6 ) ;
if ( F_4 ( V_4 ) )
V_5 = F_5 ( V_4 ) ;
else {
F_6 ( F_7 ( & V_4 -> V_7 ) != 1 ) ;
V_5 = V_4 -> V_8 ;
F_8 ( V_4 ) ;
}
F_2 ( L_2 , V_5 ) ;
return V_5 ;
}
