int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
if( V_1 -> type == V_3 || V_1 -> type == V_4 )
return ( F_2 ( ( V_5 * ) V_1 , V_2 ,
V_1 -> type , V_6 ) ) ;
F_3 ( V_7 , V_8 ) ;
return - 1 ;
}
T_1 * F_4 ( T_1 * * V_1 , unsigned char * * V_2 , long V_9 )
{
unsigned char V_10 ;
V_10 = * * V_2 & ~ V_11 ;
if( V_10 == ( V_3 | V_6 ) )
return F_5 ( V_1 , V_2 , V_9 ) ;
if( V_10 == ( V_4 | V_6 ) )
return F_6 ( V_1 , V_2 , V_9 ) ;
F_3 ( V_12 , V_8 ) ;
return ( NULL ) ;
}
T_1 * F_7 ( T_1 * V_13 , T_2 V_14 )
{
struct V_15 * V_16 ;
#if F_8 ( V_17 ) && ! F_8 ( V_18 )
struct V_15 V_19 ;
#endif
#if F_8 ( V_17 ) && ! F_8 ( V_18 )
gmtime_r ( & V_14 , & V_19 ) ;
V_16 = & V_19 ;
#else
V_16 = gmtime ( & V_14 ) ;
#endif
if( ( V_16 -> V_20 >= 50 ) && ( V_16 -> V_20 < 150 ) )
return F_9 ( V_13 , V_14 ) ;
return F_10 ( V_13 , V_14 ) ;
}
