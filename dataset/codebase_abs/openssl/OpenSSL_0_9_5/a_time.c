T_1 * F_1 ( void )
{ return F_2 () ; }
void F_3 ( T_1 * V_1 )
{ F_4 ( V_1 ) ; }
int F_5 ( T_1 * V_2 , unsigned char * * V_3 )
{
#ifdef F_6
char V_4 [ 24 ] ;
T_2 V_5 ;
if( V_2 -> type == V_6 || V_2 -> type == V_7 ) {
int V_8 ;
V_5 = * ( T_2 * ) V_2 ;
V_8 = V_5 . V_9 ;
F_7 ( V_4 , V_5 . V_10 , ( V_8 >= sizeof V_4 ) ? sizeof V_4 : V_8 ) ;
V_5 . V_10 = V_4 ;
V_2 = ( V_11 * ) & V_5 ;
}
#endif
if( V_2 -> type == V_6 || V_2 -> type == V_7 )
return ( F_8 ( ( T_2 * ) V_2 , V_3 ,
V_2 -> type , V_12 ) ) ;
F_9 ( V_13 , V_14 ) ;
return - 1 ;
}
T_1 * F_10 ( T_1 * * V_2 , unsigned char * * V_3 , long V_9 )
{
unsigned char V_15 ;
V_15 = * * V_3 & ~ V_16 ;
if( V_15 == ( V_6 | V_12 ) )
return F_11 ( V_2 , V_3 , V_9 ) ;
if( V_15 == ( V_7 | V_12 ) )
return F_12 ( V_2 , V_3 , V_9 ) ;
F_9 ( V_17 , V_14 ) ;
return ( NULL ) ;
}
T_1 * F_13 ( T_1 * V_18 , T_3 V_19 )
{
struct V_20 * V_21 ;
#if F_14 ( V_22 ) && ! F_14 ( V_23 )
struct V_20 V_10 ;
#endif
#if F_14 ( V_22 ) && ! F_14 ( V_23 )
gmtime_r ( & V_19 , & V_10 ) ;
V_21 = & V_10 ;
#else
V_21 = gmtime ( & V_19 ) ;
#endif
if( ( V_21 -> V_24 >= 50 ) && ( V_21 -> V_24 < 150 ) )
return F_15 ( V_18 , V_19 ) ;
return F_16 ( V_18 , V_19 ) ;
}
