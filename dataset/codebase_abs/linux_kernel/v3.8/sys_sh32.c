T_1 int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 ,
struct V_5 V_6 )
{
struct V_5 * V_7 = F_2 ( & V_6 , 0 ) ;
int V_8 [ 2 ] ;
int error ;
error = F_3 ( V_8 , 0 ) ;
if ( ! error ) {
V_7 -> V_7 [ 1 ] = V_8 [ 1 ] ;
return V_8 [ 0 ] ;
}
return error ;
}
T_1 T_2 F_4 ( unsigned int V_8 , char T_3 * V_9 ,
T_4 V_10 , long V_11 , T_5 V_12 )
{
return F_5 ( V_8 , V_9 , V_10 , V_12 ) ;
}
T_1 T_2 F_6 ( unsigned int V_8 , const char T_3 * V_9 ,
T_4 V_10 , long V_11 , T_5 V_12 )
{
return F_7 ( V_8 , V_9 , V_10 , V_12 ) ;
}
T_1 int F_8 ( int V_8 , T_6 V_13 , T_6 V_14 ,
T_6 V_15 , T_6 V_16 , int V_17 )
{
#ifdef F_9
return F_10 ( V_8 , ( V_18 ) V_14 << 32 | V_13 ,
( V_18 ) V_16 << 32 | V_15 , V_17 ) ;
#else
return F_10 ( V_8 , ( V_18 ) V_13 << 32 | V_14 ,
( V_18 ) V_15 << 32 | V_16 , V_17 ) ;
#endif
}
