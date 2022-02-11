T_1 *
F_1 ( void )
{
T_1 * V_1 ;
V_1 = F_2 ( T_1 , 1 ) ;
return V_1 ;
}
void
F_3 ( T_1 * V_1 )
{
F_4 ( V_1 ) ;
}
void
F_5 ( T_1 * V_1 , const T_2 V_2 )
{
V_1 -> V_3 = V_2 ;
}
void
F_6 ( T_1 * V_1 , const T_2 V_2 )
{
V_1 -> V_3 = F_7 ( V_2 ) ;
}
void
F_8 ( T_1 * V_1 , const T_3 V_4 )
{
V_1 -> V_5 = F_9 ( V_4 ) ;
}
T_2
F_10 ( T_1 * V_1 )
{
return F_11 ( V_1 -> V_3 ) ;
}
T_2
F_12 ( T_1 * V_1 )
{
return V_1 -> V_3 ;
}
void
F_13 ( const T_1 * V_1 , T_4 * V_6 )
{
T_2 V_7 = F_11 ( V_1 -> V_3 ) ;
F_14 ( ( V_8 * ) & V_7 , V_6 , V_9 ) ;
}
T_5
F_15 ( const T_1 * V_10 , const T_1 * V_11 )
{
T_2 V_12 , V_13 , V_5 ;
V_5 = F_16 ( V_10 -> V_5 , V_11 -> V_5 ) ;
V_12 = V_10 -> V_3 & V_5 ;
V_13 = V_11 -> V_3 & V_5 ;
return ( V_12 == V_13 ) ;
}
T_5
F_17 ( const T_1 * V_10 , const T_1 * V_11 )
{
T_2 V_12 , V_13 , V_5 ;
V_5 = F_16 ( V_10 -> V_5 , V_11 -> V_5 ) ;
V_12 = V_10 -> V_3 & V_5 ;
V_13 = V_11 -> V_3 & V_5 ;
return ( V_12 > V_13 ) ;
}
T_5
F_18 ( const T_1 * V_10 , const T_1 * V_11 )
{
T_2 V_12 , V_13 , V_5 ;
V_5 = F_16 ( V_10 -> V_5 , V_11 -> V_5 ) ;
V_12 = V_10 -> V_3 & V_5 ;
V_13 = V_11 -> V_3 & V_5 ;
return ( V_12 >= V_13 ) ;
}
T_5
F_19 ( const T_1 * V_10 , const T_1 * V_11 )
{
T_2 V_12 , V_13 , V_5 ;
V_5 = F_16 ( V_10 -> V_5 , V_11 -> V_5 ) ;
V_12 = V_10 -> V_3 & V_5 ;
V_13 = V_11 -> V_3 & V_5 ;
return ( V_12 < V_13 ) ;
}
T_5
F_20 ( const T_1 * V_10 , const T_1 * V_11 )
{
T_2 V_12 , V_13 , V_5 ;
V_5 = F_16 ( V_10 -> V_5 , V_11 -> V_5 ) ;
V_12 = V_10 -> V_3 & V_5 ;
V_13 = V_11 -> V_3 & V_5 ;
return ( V_12 <= V_13 ) ;
}
