T_1
F_1 ( const T_2 V_1 )
{
return F_2 ( V_1 , 0 ) ;
}
T_1 F_2 ( const T_2 V_1 , const T_3 V_2 )
{
T_3 V_3 = V_2 & V_4 ;
F_3 ( V_2 & V_5 ) ;
if ( V_3 & V_6 ) {
if ( V_3 & V_7 )
return ( V_8 ) F_4 ( V_1 ) ;
else
return ( V_8 ) F_5 ( V_1 ) ;
} else {
if ( V_3 & V_7 )
return ( V_8 ) F_6 ( V_1 ) ;
else
return ( V_8 ) F_7 ( V_1 ) ;
}
}
T_1
F_8 ( const T_2 V_9 , const T_2 V_1 )
{
return F_2 ( V_1 * V_9 , V_6 ) ;
}
void F_9 ( T_1 V_10 , const T_2 V_1 )
{
if ( V_10 )
F_10 ( V_10 , 0 , V_1 ) ;
}
void F_11 ( const T_1 V_10 , void * V_11 , const T_2 V_1 )
{
if ( V_10 && V_11 )
F_12 ( V_10 , V_11 , V_1 ) ;
}
void
F_13 ( const T_1 V_10 , const void * V_11 , const T_2 V_1 )
{
if ( V_10 && V_11 )
F_14 ( V_10 , V_11 , V_1 ) ;
}
T_1
F_15 ( const void * V_12 , const T_2 V_1 ,
T_3 V_13 , void * V_14 )
{
struct V_15 * V_16 = V_14 ;
return F_16 (
V_1 , ( void * ) V_12 , V_16 -> V_17 ,
V_16 -> type ,
V_13 & V_18 ) ;
}
