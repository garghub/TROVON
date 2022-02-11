int F_1 ( struct V_1 * V_2 , const T_1 * V_3 , T_1 * V_4 ,
const T_1 * V_5 , T_2 V_6 , T_1 * V_7 )
{
struct V_8 V_9 [ 4 ] ;
T_1 * V_10 , * V_11 , V_12 [ V_13 ] ;
struct V_14 * V_15 ;
int V_16 = sizeof( * V_15 ) + F_2 ( V_2 ) ;
if ( V_6 < V_17 )
return - V_18 ;
V_15 = F_3 ( V_16 + V_17 + V_19 , V_20 ) ;
if ( ! V_15 )
return - V_21 ;
V_10 = ( T_1 * ) V_15 + V_16 ;
V_11 = V_10 + V_17 ;
memcpy ( V_11 , V_3 , V_19 ) ;
F_4 ( V_9 , 4 ) ;
F_5 ( & V_9 [ 0 ] , V_11 , V_19 ) ;
F_5 ( & V_9 [ 1 ] , V_5 , V_6 - V_17 ) ;
F_5 ( & V_9 [ 2 ] , V_10 , V_17 ) ;
F_5 ( & V_9 [ 3 ] , V_7 , V_17 ) ;
memcpy ( V_12 , V_4 , V_22 ) ;
memset ( V_12 + V_22 , 0 , sizeof( V_12 ) - V_22 ) ;
V_12 [ V_13 - 1 ] = 0x01 ;
F_6 ( V_15 , V_2 ) ;
F_7 ( V_15 , V_9 , V_9 , 0 , V_12 ) ;
F_8 ( V_15 , V_19 + V_6 ) ;
F_9 ( V_15 ) ;
F_10 ( V_15 ) ;
return 0 ;
}
struct V_1 * F_11 ( const T_1 V_23 [] ,
T_2 V_24 )
{
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_12 ( L_1 , 0 , V_26 ) ;
if ( F_13 ( V_2 ) )
return V_2 ;
V_25 = F_14 ( V_2 , V_23 , V_24 ) ;
if ( ! V_25 )
V_25 = F_15 ( V_2 , V_17 ) ;
if ( ! V_25 )
return V_2 ;
F_16 ( V_2 ) ;
return F_17 ( V_25 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
}
