struct V_1 * F_1 ( T_1 V_2 , const T_2 * V_3 ,
const T_2 type )
{
struct V_1 * V_4 ;
if ( ! V_3 )
return NULL ;
V_4 = F_2 ( V_5 , V_2 ) ;
if ( ! V_4 )
return NULL ;
memcpy ( V_4 -> V_3 , V_3 , sizeof( V_4 -> V_3 ) ) ;
V_4 -> type = type ;
V_4 -> V_6 = F_3 ( sizeof( V_4 -> V_7 ) ) ;
return V_4 ;
}
void F_4 ( struct V_1 * V_4 )
{
F_5 ( V_4 ) ;
}
int F_6 ( struct V_1 * V_4 , T_3 type , T_3 V_6 ,
const void * V_8 )
{
struct V_9 * V_10 ;
if ( ! V_4 || ! V_8 )
return - V_11 ;
if ( F_7 ( V_4 -> V_6 ) + F_8 ( struct V_9 , V_8 ) +
V_6 > V_12 )
return - V_13 ;
V_10 = (struct V_9 * ) ( ( T_2 * ) V_4 -> V_10 +
F_7 ( V_4 -> V_6 ) - sizeof( V_4 -> V_7 ) ) ;
V_10 -> type = F_9 ( type ) ;
V_10 -> V_6 = F_9 ( V_6 ) ;
memcpy ( V_10 -> V_8 , V_8 , V_6 ) ;
V_4 -> V_7 = F_3 ( F_7 ( V_4 -> V_7 ) + 1 ) ;
V_4 -> V_6 = F_3 ( F_7 ( V_4 -> V_6 ) +
F_8 ( struct V_9 , V_8 ) + V_6 ) ;
return 0 ;
}
T_4 F_10 ( struct V_1 * V_4 )
{
return V_4 ? F_7 ( V_4 -> V_6 ) + sizeof( * V_4 ) - sizeof( V_4 -> V_7 ) : 0 ;
}
