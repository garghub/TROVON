int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
int (* F_2)( void * , void * ) )
{
V_2 -> V_5 = F_3 ( V_3 , V_4 ) ;
if ( ! V_2 -> V_5 )
return - V_6 ;
V_2 -> V_3 = 0 ;
V_2 -> V_7 = V_3 / sizeof( void * ) ;
V_2 -> F_2 = F_2 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_5 ) ;
}
void * F_6 ( struct V_1 * V_2 , void * V_8 )
{
void * V_9 ;
void * * V_5 = V_2 -> V_5 ;
int V_10 ;
if ( V_2 -> V_3 < V_2 -> V_7 ) {
V_10 = V_2 -> V_3 ++ ;
while ( V_10 > 0 && V_2 -> F_2 ( V_8 , V_5 [ ( V_10 - 1 ) / 2 ] ) ) {
V_5 [ V_10 ] = V_5 [ ( V_10 - 1 ) / 2 ] ;
V_10 = ( V_10 - 1 ) / 2 ;
}
V_5 [ V_10 ] = V_8 ;
return NULL ;
}
if ( V_2 -> F_2 ( V_8 , V_5 [ 0 ] ) )
return V_8 ;
V_9 = V_5 [ 0 ] ;
V_5 [ 0 ] = V_8 ;
V_10 = 0 ;
while ( 1 ) {
int V_11 = 2 * V_10 + 1 ;
int V_12 = 2 * V_10 + 2 ;
int V_13 = V_10 ;
if ( V_11 < V_2 -> V_3 && V_2 -> F_2 ( V_5 [ V_11 ] , V_8 ) )
V_13 = V_11 ;
if ( V_12 < V_2 -> V_3 && V_2 -> F_2 ( V_5 [ V_12 ] , V_5 [ V_13 ] ) )
V_13 = V_12 ;
if ( V_13 == V_10 )
break;
V_5 [ V_10 ] = V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_8 ;
V_10 = V_13 ;
}
return V_9 ;
}
