int F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , int V_4 )
{
T_2 * V_5 , * V_6 , * V_7 ;
T_1 * V_8 ;
int V_9 , V_10 , V_11 , V_12 ;
int V_13 , V_14 , V_15 ;
T_3 V_16 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
#ifdef F_3
printf ( L_1 , V_2 -> V_17 , V_3 -> V_17 , V_4 ) ;
#endif
V_14 = V_2 -> V_17 ;
V_15 = V_3 -> V_17 ;
if ( ( V_14 == 0 ) || ( V_15 == 0 ) )
{
V_1 -> V_17 = 0 ;
return ( 1 ) ;
}
if ( ( V_18 > 0 ) && ( V_4 > V_19 ) )
{
V_11 = F_4 ( V_4 * 2 ) - V_18 ;
V_11 *= 2 ;
V_8 = ( T_1 * ) Malloc ( sizeof( T_1 ) * V_11 ) ;
memset ( V_8 , 0 , sizeof( T_1 ) * V_11 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_12 = F_5 ( V_1 , V_2 , V_3 , V_4 , & ( V_8 [ 0 ] ) , & V_16 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 += 2 )
{
F_6 ( & V_8 [ V_10 ] ) ;
F_6 ( & V_8 [ V_10 + 1 ] ) ;
}
Free ( V_8 ) ;
return ( V_12 ) ;
}
V_13 = ( V_14 + V_15 ) ;
if ( F_7 ( V_1 , V_13 ) == NULL ) return ( 0 ) ;
V_1 -> V_20 = V_2 -> V_20 ^ V_3 -> V_20 ;
V_5 = V_2 -> V_21 ;
V_6 = V_3 -> V_21 ;
V_7 = V_1 -> V_21 ;
V_1 -> V_17 = ( V_13 > V_4 ) ? V_4 : V_13 ;
V_7 [ V_14 ] = F_8 ( V_7 , V_5 , V_14 , * ( V_6 ++ ) ) ;
V_7 ++ ;
V_9 = V_15 ;
for ( V_10 = 1 ; V_10 < V_9 ; V_10 ++ )
{
if ( V_14 >= V_4 -- )
{
V_14 -- ;
if ( V_14 <= 0 ) break;
}
V_7 [ V_14 ] = F_9 ( V_7 , V_5 , V_14 , * ( V_6 ++ ) ) ;
V_7 ++ ;
}
while ( ( V_1 -> V_17 > 0 ) && ( V_1 -> V_21 [ V_1 -> V_17 - 1 ] == 0 ) )
V_1 -> V_17 -- ;
return ( 1 ) ;
}
int F_5 ( T_1 * V_22 , T_1 * V_23 , T_1 * V_24 , int V_4 , T_1 * V_8 ,
T_3 * V_16 )
{
int V_11 ;
int V_25 , V_26 ;
T_1 V_27 , V_14 , V_28 , V_15 ;
F_7 ( V_22 , V_4 + 3 ) ;
V_25 = V_23 -> V_17 ;
V_26 = V_24 -> V_17 ;
#ifdef F_3
printf ( L_2 , V_23 -> V_17 , V_24 -> V_17 , V_4 ) ;
#endif
V_11 = ( V_4 + 1 ) / 2 ;
F_10 ( & V_27 ) ; F_10 ( & V_14 ) ; F_10 ( & V_28 ) ; F_10 ( & V_15 ) ;
F_11 ( & V_14 , V_23 , V_11 ) ;
F_12 ( & V_27 , V_23 , V_11 ) ;
F_11 ( & V_15 , V_24 , V_11 ) ;
F_12 ( & V_28 , V_24 , V_11 ) ;
if ( V_4 <= ( V_19 + V_19 ) )
{
F_13 ( V_22 , & V_14 , & V_15 ) ;
F_1 ( & V_29 , & V_14 , & V_28 , V_11 ) ;
F_1 ( & V_30 , & V_27 , & V_15 , V_11 ) ;
}
else
{
F_14 ( V_22 , & V_14 , & V_15 , & ( V_8 [ 2 ] ) , V_16 ) ;
F_5 ( & V_29 , & V_14 , & V_28 , V_11 , & ( V_8 [ 2 ] ) , V_16 ) ;
F_5 ( & V_30 , & V_27 , & V_15 , V_11 , & ( V_8 [ 2 ] ) , V_16 ) ;
}
F_15 ( & V_29 , & V_29 , & V_30 ) ;
F_12 ( & V_27 , V_22 , V_11 ) ; V_27 . V_13 = V_4 + 2 ;
F_15 ( & V_27 , & V_27 , & V_29 ) ;
V_22 -> V_17 = V_4 ;
V_22 -> V_20 = V_23 -> V_20 ^ V_24 -> V_20 ;
return ( 1 ) ;
}
