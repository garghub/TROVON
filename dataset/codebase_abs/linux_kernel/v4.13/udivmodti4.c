void
F_1 ( T_1 V_1 [ 2 ] , T_1 V_2 [ 2 ] ,
T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 )
{
T_1 V_7 , V_8 , V_9 , V_10 ;
T_2 V_11 , V_12 ;
if ( V_5 == 0 )
{
#if ! V_13
if ( V_6 > V_3 )
{
F_2 ( V_7 , V_4 , V_3 , V_4 , V_6 ) ;
V_8 = 0 ;
}
else
{
if ( V_6 == 0 )
V_6 = 1 / V_6 ;
F_2 ( V_8 , V_3 , 0 , V_3 , V_6 ) ;
F_2 ( V_7 , V_4 , V_3 , V_4 , V_6 ) ;
}
V_9 = V_4 ;
V_10 = 0 ;
#else
if ( V_6 > V_3 )
{
F_3 ( V_12 , V_6 ) ;
if ( V_12 != 0 )
{
V_6 = V_6 << V_12 ;
V_3 = ( V_3 << V_12 ) | ( V_4 >> ( V_14 - V_12 ) ) ;
V_4 = V_4 << V_12 ;
}
F_2 ( V_7 , V_4 , V_3 , V_4 , V_6 ) ;
V_8 = 0 ;
}
else
{
if ( V_6 == 0 )
V_6 = 1 / V_6 ;
F_3 ( V_12 , V_6 ) ;
if ( V_12 == 0 )
{
V_3 -= V_6 ;
V_8 = 1 ;
}
else
{
T_1 V_15 ;
V_11 = V_14 - V_12 ;
V_6 = V_6 << V_12 ;
V_15 = V_3 >> V_11 ;
V_3 = ( V_3 << V_12 ) | ( V_4 >> V_11 ) ;
V_4 = V_4 << V_12 ;
F_2 ( V_8 , V_3 , V_15 , V_3 , V_6 ) ;
}
F_2 ( V_7 , V_4 , V_3 , V_4 , V_6 ) ;
}
V_9 = V_4 >> V_12 ;
V_10 = 0 ;
#endif
}
else
{
if ( V_5 > V_3 )
{
V_7 = 0 ;
V_8 = 0 ;
V_9 = V_4 ;
V_10 = V_3 ;
}
else
{
F_3 ( V_12 , V_5 ) ;
if ( V_12 == 0 )
{
if ( V_3 > V_5 || V_4 >= V_6 )
{
V_7 = 1 ;
F_4 ( V_3 , V_4 , V_3 , V_4 , V_5 , V_6 ) ;
}
else
V_7 = 0 ;
V_8 = 0 ;
V_9 = V_4 ;
V_10 = V_3 ;
}
else
{
T_1 V_16 , V_17 , V_15 ;
V_11 = V_14 - V_12 ;
V_5 = ( V_5 << V_12 ) | ( V_6 >> V_11 ) ;
V_6 = V_6 << V_12 ;
V_15 = V_3 >> V_11 ;
V_3 = ( V_3 << V_12 ) | ( V_4 >> V_11 ) ;
V_4 = V_4 << V_12 ;
F_2 ( V_7 , V_3 , V_15 , V_3 , V_5 ) ;
F_5 ( V_16 , V_17 , V_7 , V_6 ) ;
if ( V_16 > V_3 || ( V_16 == V_3 && V_17 > V_4 ) )
{
V_7 -- ;
F_4 ( V_16 , V_17 , V_16 , V_17 , V_5 , V_6 ) ;
}
V_8 = 0 ;
F_4 ( V_3 , V_4 , V_3 , V_4 , V_16 , V_17 ) ;
V_9 = ( V_3 << V_11 ) | ( V_4 >> V_12 ) ;
V_10 = V_3 >> V_12 ;
}
}
}
V_1 [ 0 ] = V_7 ; V_1 [ 1 ] = V_8 ;
V_2 [ 0 ] = V_9 , V_2 [ 1 ] = V_10 ;
}
