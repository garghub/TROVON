int F_1 ( struct V_1 * V_2 , const T_1 * V_3 , T_1 * V_4 ,
const T_1 * V_5 , T_2 V_6 , T_1 * V_7 )
{
struct V_8 V_9 [ 4 ] ;
char V_10 [ sizeof( struct V_11 ) +
F_2 ( V_2 ) ]
V_12 ( F_3 ( struct V_11 ) ) ;
struct V_11 * V_13 = ( void * ) V_10 ;
T_1 V_14 [ V_15 ] , V_16 [ V_17 ] ;
if ( V_6 < V_15 )
return - V_18 ;
memset ( V_13 , 0 , sizeof( V_10 ) ) ;
memset ( V_14 , 0 , V_15 ) ;
F_4 ( V_9 , 4 ) ;
F_5 ( & V_9 [ 0 ] , V_3 , V_19 ) ;
F_5 ( & V_9 [ 1 ] , V_5 , V_6 - V_15 ) ;
F_5 ( & V_9 [ 2 ] , V_14 , V_15 ) ;
F_5 ( & V_9 [ 3 ] , V_7 , V_15 ) ;
memcpy ( V_16 , V_4 , V_20 ) ;
memset ( V_16 + V_20 , 0 , sizeof( V_16 ) - V_20 ) ;
V_16 [ V_17 - 1 ] = 0x01 ;
F_6 ( V_13 , V_2 ) ;
F_7 ( V_13 , V_9 , V_9 , 0 , V_16 ) ;
F_8 ( V_13 , V_19 + V_6 ) ;
F_9 ( V_13 ) ;
return 0 ;
}
struct V_1 * F_10 ( const T_1 V_21 [] ,
T_2 V_22 )
{
struct V_1 * V_2 ;
int V_23 ;
V_2 = F_11 ( L_1 , 0 , V_24 ) ;
if ( F_12 ( V_2 ) )
return V_2 ;
V_23 = F_13 ( V_2 , V_21 , V_22 ) ;
if ( ! V_23 )
V_23 = F_14 ( V_2 , V_15 ) ;
if ( ! V_23 )
return V_2 ;
F_15 ( V_2 ) ;
return F_16 ( V_23 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
}
