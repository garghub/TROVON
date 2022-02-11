void F_1 ( const struct V_1 * * V_2 , int V_3 ,
const char * V_4 , int V_5 )
{
const struct V_1 * V_6 ;
const struct V_1 * V_7 = ( const struct V_1 * ) V_4 ;
int V_8 ;
memset ( V_2 , 0 , sizeof( struct V_1 * ) * ( V_3 + 1 ) ) ;
F_2 (tlv, head, buf_len, rem) {
T_1 type = F_3 ( V_6 ) ;
if ( type > 0 && type <= V_3 )
V_2 [ type ] = V_6 ;
}
}
int F_4 ( struct V_9 * V_10 ,
int V_11 , int V_12 , const void * V_13 )
{
int V_14 = V_10 -> V_15 - V_10 -> V_16 ;
int V_17 = F_5 ( V_12 ) ;
struct V_1 * V_6 ;
if ( F_6 ( V_14 < V_17 ) )
return - V_18 ;
V_6 = F_7 ( V_10 ) ;
V_10 -> V_16 += V_17 ;
V_6 -> type = V_11 ;
V_6 -> V_19 = F_8 ( V_12 ) ;
memcpy ( F_9 ( V_6 ) , V_13 , V_12 ) ;
memset ( ( char * ) V_6 + V_6 -> V_19 , 0 , F_10 ( V_12 ) ) ;
return 0 ;
}
