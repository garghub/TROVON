int F_1 ( struct V_1 * V_2 )
{
long V_3 = V_2 -> V_4 ;
F_2 ( & V_5 , & V_3 ) ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
long V_3 = V_2 -> V_6 ;
long V_7 = 0 ;
F_4 ( & V_7 , sizeof( V_7 ) , ( void * ) ( V_2 -> V_8 + sizeof( V_7 ) ) ) ;
struct V_9 V_10 = {
. V_11 = F_5 () ,
. V_7 = V_7 ,
} ;
F_6 ( & V_5 , & V_3 , & V_10 , V_12 ) ;
return 0 ;
}
