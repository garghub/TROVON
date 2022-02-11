int F_1 ( T_1 V_1 , char * V_2 , int V_3 )
{
unsigned long V_4 ;
if ( F_2 ( V_1 , & V_4 , V_2 ) == V_5 )
return V_4 ;
return 0 ;
}
int F_3 ( T_1 V_1 , const char * V_2 , int V_3 )
{
unsigned long * V_6 = ( unsigned long * ) V_2 ;
long V_7 ;
if ( V_3 > V_8 )
V_3 = V_8 ;
V_7 = F_4 ( V_9 , V_1 , V_3 , V_6 [ 0 ] ,
V_6 [ 1 ] ) ;
if ( V_7 == V_5 )
return V_3 ;
if ( V_7 == V_10 )
return - V_11 ;
return - V_12 ;
}
