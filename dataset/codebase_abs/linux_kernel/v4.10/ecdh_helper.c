static inline T_1 * F_1 ( void * V_1 , const void * V_2 , T_2 V_3 )
{
memcpy ( V_1 , V_2 , V_3 ) ;
return V_1 + V_3 ;
}
static inline const T_1 * F_2 ( void * V_1 , const void * V_2 , T_2 V_3 )
{
memcpy ( V_1 , V_2 , V_3 ) ;
return V_2 + V_3 ;
}
int F_3 ( const struct V_4 * V_5 )
{
return V_6 + V_5 -> V_7 ;
}
int F_4 ( char * V_8 , unsigned int V_9 ,
const struct V_4 * V_5 )
{
T_1 * V_10 = V_8 ;
struct V_11 V_12 = {
. type = V_13 ,
. V_9 = V_9
} ;
if ( F_5 ( ! V_8 ) )
return - V_14 ;
if ( V_9 != F_3 ( V_5 ) )
return - V_14 ;
V_10 = F_1 ( V_10 , & V_12 , sizeof( V_12 ) ) ;
V_10 = F_1 ( V_10 , & V_5 -> V_15 , sizeof( V_5 -> V_15 ) ) ;
V_10 = F_1 ( V_10 , & V_5 -> V_7 , sizeof( V_5 -> V_7 ) ) ;
F_1 ( V_10 , V_5 -> V_16 , V_5 -> V_7 ) ;
return 0 ;
}
int F_6 ( const char * V_8 , unsigned int V_9 ,
struct V_4 * V_5 )
{
const T_1 * V_10 = V_8 ;
struct V_11 V_12 ;
if ( F_5 ( ! V_8 || V_9 < V_6 ) )
return - V_14 ;
V_10 = F_2 ( & V_12 , V_10 , sizeof( V_12 ) ) ;
if ( V_12 . type != V_13 )
return - V_14 ;
V_10 = F_2 ( & V_5 -> V_15 , V_10 , sizeof( V_5 -> V_15 ) ) ;
V_10 = F_2 ( & V_5 -> V_7 , V_10 , sizeof( V_5 -> V_7 ) ) ;
if ( V_12 . V_9 != F_3 ( V_5 ) )
return - V_14 ;
V_5 -> V_16 = ( void * ) V_10 ;
return 0 ;
}
