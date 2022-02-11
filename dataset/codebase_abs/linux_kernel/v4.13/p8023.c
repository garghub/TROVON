static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned char * V_5 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
F_2 ( V_4 , V_7 , V_8 , V_5 , NULL , V_4 -> V_9 ) ;
return F_3 ( V_4 ) ;
}
struct V_1 * F_4 ( void )
{
struct V_1 * V_10 = F_5 ( sizeof( * V_10 ) , V_11 ) ;
if ( V_10 ) {
V_10 -> V_12 = 0 ;
V_10 -> V_13 = F_1 ;
}
return V_10 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
}
