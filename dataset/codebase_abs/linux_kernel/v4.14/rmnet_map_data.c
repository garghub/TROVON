struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 , int V_5 )
{
struct V_1 * V_6 ;
T_1 V_7 , V_8 ;
T_2 * V_9 ;
if ( F_2 ( V_3 ) < sizeof( struct V_1 ) )
return NULL ;
V_8 = V_3 -> V_10 - V_4 ;
V_6 = (struct V_1 * )
F_3 ( V_3 , sizeof( struct V_1 ) ) ;
memset ( V_6 , 0 , sizeof( struct V_1 ) ) ;
if ( V_5 == V_11 ) {
V_6 -> V_12 = F_4 ( V_8 ) ;
return V_6 ;
}
V_7 = F_5 ( V_8 , 4 ) - V_8 ;
if ( V_7 == 0 )
goto V_13;
if ( F_6 ( V_3 ) < V_7 )
return NULL ;
V_9 = ( T_2 * ) F_7 ( V_3 , V_7 ) ;
memset ( V_9 , 0 , V_7 ) ;
V_13:
V_6 -> V_12 = F_4 ( V_8 + V_7 ) ;
V_6 -> V_14 = V_7 & 0x3F ;
return V_6 ;
}
struct V_2 * F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_15 ;
struct V_2 * V_16 ;
T_1 V_17 ;
if ( V_3 -> V_10 == 0 )
return NULL ;
V_15 = (struct V_1 * ) V_3 -> V_18 ;
V_17 = F_9 ( V_15 -> V_12 ) + sizeof( struct V_1 ) ;
if ( ( ( int ) V_3 -> V_10 - ( int ) V_17 ) < 0 )
return NULL ;
if ( F_9 ( V_15 -> V_12 ) == 0 )
return NULL ;
V_16 = F_10 ( V_17 + V_19 , V_20 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_21 = V_3 -> V_21 ;
F_11 ( V_16 , V_22 ) ;
F_7 ( V_16 , V_17 ) ;
memcpy ( V_16 -> V_18 , V_3 -> V_18 , V_17 ) ;
F_12 ( V_3 , V_17 ) ;
return V_16 ;
}
