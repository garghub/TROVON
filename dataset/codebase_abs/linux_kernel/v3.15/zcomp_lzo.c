static void * F_1 ( void )
{
return F_2 ( V_1 , V_2 ) ;
}
static void F_3 ( void * V_3 )
{
F_4 ( V_3 ) ;
}
static int F_5 ( const unsigned char * V_4 , unsigned char * V_5 ,
T_1 * V_6 , void * V_3 )
{
int V_7 = F_6 ( V_4 , V_8 , V_5 , V_6 , V_3 ) ;
return V_7 == V_9 ? 0 : V_7 ;
}
static int F_7 ( const unsigned char * V_4 , T_1 V_10 ,
unsigned char * V_5 )
{
T_1 V_6 = V_8 ;
int V_7 = F_8 ( V_4 , V_10 , V_5 , & V_6 ) ;
return V_7 == V_9 ? 0 : V_7 ;
}
