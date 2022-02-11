static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned char V_3 , bool V_4 , unsigned int V_5 )
{
return F_2 ( V_1 , V_6 ,
F_3 ( V_6 ) , V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned char V_3 , int V_7 , enum V_8 V_9 )
{
if ( V_9 == V_10 )
return F_5 ( V_1 , V_11 ,
F_3 ( V_11 ) , V_2 , V_3 , V_7 ) ;
else if ( V_9 == V_12 )
return F_5 ( V_1 , V_13 ,
F_3 ( V_13 ) , V_2 , V_3 , V_7 ) ;
return - V_14 ;
}
static int F_6 ( struct V_15 * V_16 )
{
return F_7 ( V_16 , & V_17 , NULL ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_18 ) ;
}
