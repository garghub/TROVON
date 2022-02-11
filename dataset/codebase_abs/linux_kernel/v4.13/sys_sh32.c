T_1 int F_1 ( void )
{
int V_1 [ 2 ] ;
int error ;
error = F_2 ( V_1 , 0 ) ;
if ( ! error ) {
F_3 () -> V_2 [ 1 ] = V_1 [ 1 ] ;
return V_1 [ 0 ] ;
}
return error ;
}
T_1 T_2 F_4 ( unsigned int V_1 , char T_3 * V_3 ,
T_4 V_4 , long V_5 , T_5 V_6 )
{
return F_5 ( V_1 , V_3 , V_4 , V_6 ) ;
}
T_1 T_2 F_6 ( unsigned int V_1 , const char T_3 * V_3 ,
T_4 V_4 , long V_5 , T_5 V_6 )
{
return F_7 ( V_1 , V_3 , V_4 , V_6 ) ;
}
T_1 int F_8 ( int V_1 , T_6 V_7 , T_6 V_8 ,
T_6 V_9 , T_6 V_10 , int V_11 )
{
#ifdef F_9
return F_10 ( V_1 , ( V_12 ) V_8 << 32 | V_7 ,
( V_12 ) V_10 << 32 | V_9 , V_11 ) ;
#else
return F_10 ( V_1 , ( V_12 ) V_7 << 32 | V_8 ,
( V_12 ) V_9 << 32 | V_10 , V_11 ) ;
#endif
}
