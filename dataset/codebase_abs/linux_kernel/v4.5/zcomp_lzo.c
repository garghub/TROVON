static void * F_1 ( T_1 V_1 )
{
void * V_2 ;
V_2 = F_2 ( V_3 , V_1 ) ;
if ( ! V_2 )
V_2 = F_3 ( V_3 ,
V_1 | V_4 ,
V_5 ) ;
return V_2 ;
}
static void F_4 ( void * V_6 )
{
F_5 ( V_6 ) ;
}
static int F_6 ( const unsigned char * V_7 , unsigned char * V_8 ,
T_2 * V_9 , void * V_6 )
{
int V_2 = F_7 ( V_7 , V_10 , V_8 , V_9 , V_6 ) ;
return V_2 == V_11 ? 0 : V_2 ;
}
static int F_8 ( const unsigned char * V_7 , T_2 V_12 ,
unsigned char * V_8 )
{
T_2 V_9 = V_10 ;
int V_2 = F_9 ( V_7 , V_12 , V_8 , & V_9 ) ;
return V_2 == V_11 ? 0 : V_2 ;
}
