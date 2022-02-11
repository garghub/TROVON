static void F_1 ( void * V_1 )
{
unsigned short * V_2 = V_1 ;
unsigned short V_3 [ 3 ] ;
V_3 [ 0 ] = V_2 [ 0 ] ;
V_3 [ 1 ] = V_2 [ 1 ] ;
V_3 [ 2 ] = V_2 [ 2 ] ;
V_2 [ 0 ] = V_2 [ 3 ] ;
V_2 [ 1 ] = V_2 [ 4 ] ;
V_2 [ 2 ] = V_2 [ 5 ] ;
V_2 [ 3 ] = V_3 [ 0 ] ;
V_2 [ 4 ] = V_3 [ 1 ] ;
V_2 [ 5 ] = V_3 [ 2 ] ;
}
int F_2 ( struct V_4 * V_5 )
{
void * V_6 = ( void * ) ( long ) V_5 -> V_6 ;
void * V_1 = ( void * ) ( long ) V_5 -> V_1 ;
struct V_7 * V_8 = V_1 ;
int V_9 = V_10 ;
int V_11 , V_12 = 0 , V_13 = 0 ;
long * V_14 ;
T_1 V_15 = 0 ;
T_2 V_16 ;
V_16 = sizeof( * V_8 ) ;
if ( V_1 + V_16 > V_6 )
return V_9 ;
V_11 = 0 ;
V_14 = F_3 ( & V_17 , & V_15 ) ;
if ( V_14 )
* V_14 += 1 ;
F_1 ( V_1 ) ;
return F_4 ( & V_18 , V_11 , 0 ) ;
}
int F_5 ( struct V_4 * V_5 )
{
return V_19 ;
}
