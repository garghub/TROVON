int F_1 ( T_1 V_1 , char * V_2 , int V_3 )
{
long V_4 ;
unsigned long V_5 [ V_6 ] ;
unsigned long * V_7 = ( unsigned long * ) V_2 ;
V_4 = F_2 ( V_8 , V_5 , V_1 ) ;
V_7 [ 0 ] = F_3 ( V_5 [ 1 ] ) ;
V_7 [ 1 ] = F_3 ( V_5 [ 2 ] ) ;
if ( V_4 == V_9 )
return V_5 [ 0 ] ;
return 0 ;
}
int F_4 ( T_1 V_1 , const char * V_2 , int V_3 )
{
unsigned long * V_7 = ( unsigned long * ) V_2 ;
long V_4 ;
if ( V_3 > V_10 )
V_3 = V_10 ;
V_4 = F_5 ( V_11 , V_1 , V_3 ,
F_6 ( V_7 [ 0 ] ) ,
F_6 ( V_7 [ 1 ] ) ) ;
if ( V_4 == V_9 )
return V_3 ;
if ( V_4 == V_12 )
return - V_13 ;
return - V_14 ;
}
