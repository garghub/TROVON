static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 ) ;
}
unsigned int F_3 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
struct V_2 V_7 ;
unsigned long V_8 ;
unsigned int V_9 ;
if ( F_4 ( V_6 , F_1 , & V_7 , 1 ) )
return 0 ;
V_8 = F_5 ( & F_6 ( V_10 , V_6 ) , & V_7 ) ;
F_6 ( V_10 , V_6 ) = V_7 ;
V_9 = ( V_5 -> V_11 . V_12 * V_8 ) >> V_13 ;
return V_9 ;
}
