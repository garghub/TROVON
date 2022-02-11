static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned char * V_5 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
V_4 -> V_8 = F_2 ( V_9 ) ;
F_3 ( V_4 , V_7 , V_9 , V_5 , NULL , V_4 -> V_10 ) ;
return F_4 ( V_4 ) ;
}
struct V_1 * F_5 ( void )
{
struct V_1 * V_11 = F_6 ( sizeof( * V_11 ) , V_12 ) ;
if ( V_11 ) {
V_11 -> V_13 = 0 ;
V_11 -> V_14 = F_1 ;
}
return V_11 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
}
