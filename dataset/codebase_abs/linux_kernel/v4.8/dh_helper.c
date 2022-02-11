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
static inline int F_3 ( const struct V_4 * V_5 )
{
return V_5 -> V_6 + V_5 -> V_7 + V_5 -> V_8 ;
}
int F_4 ( const struct V_4 * V_5 )
{
return V_9 + F_3 ( V_5 ) ;
}
int F_5 ( char * V_10 , unsigned int V_11 , const struct V_4 * V_12 )
{
T_1 * V_13 = V_10 ;
struct V_14 V_15 = {
. type = V_16 ,
. V_11 = V_11
} ;
if ( F_6 ( ! V_10 ) )
return - V_17 ;
if ( V_11 != F_4 ( V_12 ) )
return - V_17 ;
V_13 = F_1 ( V_13 , & V_15 , sizeof( V_15 ) ) ;
V_13 = F_1 ( V_13 , & V_12 -> V_6 , sizeof( V_12 -> V_6 ) ) ;
V_13 = F_1 ( V_13 , & V_12 -> V_7 , sizeof( V_12 -> V_7 ) ) ;
V_13 = F_1 ( V_13 , & V_12 -> V_8 , sizeof( V_12 -> V_8 ) ) ;
V_13 = F_1 ( V_13 , V_12 -> V_18 , V_12 -> V_6 ) ;
V_13 = F_1 ( V_13 , V_12 -> V_5 , V_12 -> V_7 ) ;
F_1 ( V_13 , V_12 -> V_19 , V_12 -> V_8 ) ;
return 0 ;
}
int F_7 ( const char * V_10 , unsigned int V_11 , struct V_4 * V_12 )
{
const T_1 * V_13 = V_10 ;
struct V_14 V_15 ;
if ( F_6 ( ! V_10 || V_11 < V_9 ) )
return - V_17 ;
V_13 = F_2 ( & V_15 , V_13 , sizeof( V_15 ) ) ;
if ( V_15 . type != V_16 )
return - V_17 ;
V_13 = F_2 ( & V_12 -> V_6 , V_13 , sizeof( V_12 -> V_6 ) ) ;
V_13 = F_2 ( & V_12 -> V_7 , V_13 , sizeof( V_12 -> V_7 ) ) ;
V_13 = F_2 ( & V_12 -> V_8 , V_13 , sizeof( V_12 -> V_8 ) ) ;
if ( V_15 . V_11 != F_4 ( V_12 ) )
return - V_17 ;
V_12 -> V_18 = ( void * ) V_13 ;
V_12 -> V_5 = ( void * ) ( V_13 + V_12 -> V_6 ) ;
V_12 -> V_19 = ( void * ) ( V_13 + V_12 -> V_6 + V_12 -> V_7 ) ;
return 0 ;
}
