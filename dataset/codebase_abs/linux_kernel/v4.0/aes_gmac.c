int F_1 ( struct V_1 * V_2 , const T_1 * V_3 , T_1 * V_4 ,
const T_1 * V_5 , T_2 V_6 , T_1 * V_7 )
{
struct V_8 V_9 [ 3 ] , V_10 [ 1 ] ;
char V_11 [ sizeof( struct V_12 ) +
F_2 ( V_2 ) ]
V_13 ( F_3 ( struct V_12 ) ) ;
struct V_12 * V_14 = ( void * ) V_11 ;
T_1 V_15 [ V_16 ] , V_17 [ V_18 ] ;
if ( V_6 < V_16 )
return - V_19 ;
memset ( V_14 , 0 , sizeof( V_11 ) ) ;
memset ( V_15 , 0 , V_16 ) ;
F_4 ( V_9 , 3 ) ;
F_5 ( & V_9 [ 0 ] , V_3 , V_20 ) ;
F_5 ( & V_9 [ 1 ] , V_5 , V_6 - V_16 ) ;
F_5 ( & V_9 [ 2 ] , V_15 , V_16 ) ;
memcpy ( V_17 , V_4 , V_21 ) ;
memset ( V_17 + V_21 , 0 , sizeof( V_17 ) - V_21 ) ;
V_17 [ V_18 - 1 ] = 0x01 ;
F_4 ( V_10 , 1 ) ;
F_5 ( & V_10 [ 0 ] , V_7 , V_16 ) ;
F_6 ( V_14 , V_2 ) ;
F_7 ( V_14 , V_9 , V_20 + V_6 ) ;
F_8 ( V_14 , NULL , V_10 , 0 , V_17 ) ;
F_9 ( V_14 ) ;
return 0 ;
}
struct V_1 * F_10 ( const T_1 V_22 [] ,
T_2 V_23 )
{
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_11 ( L_1 , 0 , V_25 ) ;
if ( F_12 ( V_2 ) )
return V_2 ;
V_24 = F_13 ( V_2 , V_22 , V_23 ) ;
if ( ! V_24 )
return V_2 ;
if ( ! V_24 )
V_24 = F_14 ( V_2 , V_16 ) ;
F_15 ( V_2 ) ;
return F_16 ( V_24 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
}
