int F_1 ( T_1 * V_1 , T_1 * V_2 )
{
register T_2 * V_3 , * V_4 , V_5 , V_6 ;
int V_7 ;
if ( V_1 != V_2 )
{
V_1 -> V_8 = V_2 -> V_8 ;
if ( F_2 ( V_1 , V_2 -> V_9 + 1 ) == NULL ) return ( 0 ) ;
V_1 -> V_9 = V_2 -> V_9 ;
}
else
{
if ( F_2 ( V_1 , V_2 -> V_9 + 1 ) == NULL ) return ( 0 ) ;
}
V_3 = V_2 -> V_10 ;
V_4 = V_1 -> V_10 ;
V_6 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_9 ; V_7 ++ )
{
V_5 = * ( V_3 ++ ) ;
* ( V_4 ++ ) = ( ( V_5 << 1 ) | V_6 ) & V_11 ;
V_6 = ( V_5 & V_12 ) ? 1 : 0 ;
}
if ( V_6 )
{
* V_4 = 1 ;
V_1 -> V_9 ++ ;
}
return ( 1 ) ;
}
int F_3 ( T_1 * V_1 , T_1 * V_2 )
{
T_2 * V_3 , * V_4 , V_5 , V_6 ;
int V_7 ;
if ( F_4 ( V_2 ) )
{
F_5 ( V_1 ) ;
return ( 1 ) ;
}
if ( V_2 != V_1 )
{
if ( F_2 ( V_1 , V_2 -> V_9 ) == NULL ) return ( 0 ) ;
V_1 -> V_9 = V_2 -> V_9 ;
V_1 -> V_8 = V_2 -> V_8 ;
}
V_3 = V_2 -> V_10 ;
V_4 = V_1 -> V_10 ;
V_6 = 0 ;
for ( V_7 = V_2 -> V_9 - 1 ; V_7 >= 0 ; V_7 -- )
{
V_5 = V_3 [ V_7 ] ;
V_4 [ V_7 ] = ( ( V_5 >> 1 ) & V_11 ) | V_6 ;
V_6 = ( V_5 & 1 ) ? V_12 : 0 ;
}
F_6 ( V_1 ) ;
return ( 1 ) ;
}
int F_7 ( T_1 * V_1 , const T_1 * V_2 , int V_13 )
{
int V_7 , V_14 , V_15 , V_16 ;
T_2 * V_5 , * V_17 ;
T_2 V_18 ;
V_1 -> V_8 = V_2 -> V_8 ;
if ( F_2 ( V_1 , V_2 -> V_9 + ( V_13 / V_19 ) + 1 ) == NULL ) return ( 0 ) ;
V_14 = V_13 / V_19 ;
V_15 = V_13 % V_19 ;
V_16 = V_19 - V_15 ;
V_17 = V_2 -> V_10 ;
V_5 = V_1 -> V_10 ;
V_5 [ V_2 -> V_9 + V_14 ] = 0 ;
if ( V_15 == 0 )
for ( V_7 = V_2 -> V_9 - 1 ; V_7 >= 0 ; V_7 -- )
V_5 [ V_14 + V_7 ] = V_17 [ V_7 ] ;
else
for ( V_7 = V_2 -> V_9 - 1 ; V_7 >= 0 ; V_7 -- )
{
V_18 = V_17 [ V_7 ] ;
V_5 [ V_14 + V_7 + 1 ] |= ( V_18 >> V_16 ) & V_11 ;
V_5 [ V_14 + V_7 ] = ( V_18 << V_15 ) & V_11 ;
}
memset ( V_5 , 0 , V_14 * sizeof( V_5 [ 0 ] ) ) ;
V_1 -> V_9 = V_2 -> V_9 + V_14 + 1 ;
F_6 ( V_1 ) ;
return ( 1 ) ;
}
int F_8 ( T_1 * V_1 , T_1 * V_2 , int V_13 )
{
int V_7 , V_20 , V_14 , V_15 , V_16 ;
T_2 * V_5 , * V_17 ;
T_2 V_18 , V_21 ;
V_14 = V_13 / V_19 ;
V_16 = V_13 % V_19 ;
V_15 = V_19 - V_16 ;
if ( V_14 > V_2 -> V_9 || V_2 -> V_9 == 0 )
{
F_5 ( V_1 ) ;
return ( 1 ) ;
}
if ( V_1 != V_2 )
{
V_1 -> V_8 = V_2 -> V_8 ;
if ( F_2 ( V_1 , V_2 -> V_9 - V_14 + 1 ) == NULL ) return ( 0 ) ;
}
V_17 = & ( V_2 -> V_10 [ V_14 ] ) ;
V_5 = V_1 -> V_10 ;
V_20 = V_2 -> V_9 - V_14 ;
V_1 -> V_9 = V_20 ;
if ( V_16 == 0 )
{
for ( V_7 = V_20 + 1 ; V_7 > 0 ; V_7 -- )
* ( V_5 ++ ) = * ( V_17 ++ ) ;
}
else
{
V_18 = * ( V_17 ++ ) ;
for ( V_7 = 1 ; V_7 < V_20 ; V_7 ++ )
{
V_21 = ( V_18 >> V_16 ) & V_11 ;
V_18 = * ( V_17 ++ ) ;
* ( V_5 ++ ) = ( V_21 | ( V_18 << V_15 ) ) & V_11 ;
}
* ( V_5 ++ ) = ( V_18 >> V_16 ) & V_11 ;
}
* V_5 = 0 ;
F_6 ( V_1 ) ;
return ( 1 ) ;
}
