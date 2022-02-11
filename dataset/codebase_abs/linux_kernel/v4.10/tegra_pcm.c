int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , & V_3 , 0 ) ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
char * V_6 , char * V_7 )
{
* V_5 = V_3 ;
V_5 -> V_8 = V_2 -> V_9 ;
V_5 -> V_10 [ 0 ] = V_6 ;
V_5 -> V_10 [ 1 ] = V_7 ;
return F_2 ( V_2 , V_5 , 0 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
return F_5 ( V_2 ) ;
}
