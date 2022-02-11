T_1 int
F_1 ( unsigned long V_1 , int V_2 , int V_3 , unsigned long V_4 )
{
return - V_5 ;
}
T_1 int F_2 ( void )
{
return V_6 ;
}
T_1 void F_3 ( void * V_7 , ... )
{
struct V_8 * V_9 = (struct V_8 * ) ( ( unsigned char * ) & V_7 - 4 ) ;
F_4 ( L_1 ,
( ( V_9 -> V_10 ) & 0xffffff ) - 2 , V_9 -> V_11 , V_9 -> V_12 , V_9 -> V_13 , V_9 -> V_14 , V_9 -> V_15 ) ;
}
