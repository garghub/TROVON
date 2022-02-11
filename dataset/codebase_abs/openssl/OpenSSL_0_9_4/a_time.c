int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
#ifdef F_2
char V_3 [ 24 ] ;
T_2 V_4 ;
if( V_1 -> type == V_5 || V_1 -> type == V_6 ) {
int V_7 ;
V_4 = * ( T_2 * ) V_1 ;
V_7 = V_4 . V_8 ;
F_3 ( V_3 , V_4 . V_9 , ( V_7 >= sizeof V_3 ) ? sizeof V_3 : V_7 ) ;
V_4 . V_9 = V_3 ;
V_1 = ( V_10 * ) & V_4 ;
}
#endif
if( V_1 -> type == V_5 || V_1 -> type == V_6 )
return ( F_4 ( ( T_2 * ) V_1 , V_2 ,
V_1 -> type , V_11 ) ) ;
F_5 ( V_12 , V_13 ) ;
return - 1 ;
}
T_1 * F_6 ( T_1 * * V_1 , unsigned char * * V_2 , long V_8 )
{
unsigned char V_14 ;
V_14 = * * V_2 & ~ V_15 ;
if( V_14 == ( V_5 | V_11 ) )
return F_7 ( V_1 , V_2 , V_8 ) ;
if( V_14 == ( V_6 | V_11 ) )
return F_8 ( V_1 , V_2 , V_8 ) ;
F_5 ( V_16 , V_13 ) ;
return ( NULL ) ;
}
T_1 * F_9 ( T_1 * V_17 , T_3 V_18 )
{
struct V_19 * V_20 ;
#if F_10 ( V_21 ) && ! F_10 ( V_22 )
struct V_19 V_9 ;
#endif
#if F_10 ( V_21 ) && ! F_10 ( V_22 )
gmtime_r ( & V_18 , & V_9 ) ;
V_20 = & V_9 ;
#else
V_20 = gmtime ( & V_18 ) ;
#endif
if( ( V_20 -> V_23 >= 50 ) && ( V_20 -> V_23 < 150 ) )
return F_11 ( V_17 , V_18 ) ;
return F_12 ( V_17 , V_18 ) ;
}
