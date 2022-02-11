static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 ) ;
V_6 = F_3 ( V_2 ) ;
if ( ! V_6 ) {
F_4 ( L_2 ) ;
return - V_8 ;
}
V_7 = F_5 ( V_6 , & V_9 , V_10 ,
V_11 , 0 , V_12 ,
& V_6 -> V_13 ) ;
if ( V_7 < 0 ) {
F_6 ( V_6 ) ;
return V_7 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
F_9 ( V_6 -> V_13 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
