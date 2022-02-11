int
F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
if ( V_3 == 0 ) {
V_4 [ 0 ] = 4 ;
V_4 [ 1 ] = V_8 ;
V_4 [ 2 ] = ( T_1 ) V_2 -> V_9 ;
V_4 [ 3 ] = ( T_1 ) ( V_2 -> V_9 >> 8 ) ;
return 4 ;
}
for ( V_6 = V_2 -> V_10 ; V_6 && V_6 -> V_6 ; V_6 ++ )
if ( V_6 -> V_3 == V_3 )
break;
if ( ! V_6 || ! V_6 -> V_6 )
return - V_11 ;
V_7 = F_2 ( ( V_12 ) 126 , strlen ( V_6 -> V_6 ) ) ;
V_7 = F_3 ( V_6 -> V_6 , V_7 , V_13 ,
( V_14 * ) & V_4 [ 2 ] , 126 ) ;
if ( V_7 < 0 )
return - V_11 ;
V_4 [ 0 ] = ( V_7 + 1 ) * 2 ;
V_4 [ 1 ] = V_8 ;
return V_4 [ 0 ] ;
}
