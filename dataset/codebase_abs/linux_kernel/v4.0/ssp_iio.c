int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 -> V_7 . V_8 -> V_8 ) ;
V_4 -> V_9 = F_4 ( V_2 -> V_10 , V_11 | V_12 ) ;
if ( ! V_4 -> V_9 )
return - V_13 ;
return F_5 ( V_6 , V_4 -> type ,
F_6 ( V_6 , V_4 -> type ) ) ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 -> V_7 . V_8 -> V_8 ) ;
V_14 = F_8 ( V_6 , V_4 -> type ) ;
if ( V_14 < 0 )
return V_14 ;
F_9 ( V_4 -> V_9 ) ;
return V_14 ;
}
int F_10 ( struct V_1 * V_2 , void * V_15 ,
unsigned int V_16 , T_1 V_17 )
{
T_2 time ;
T_1 V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_10 == 0 )
return 0 ;
memcpy ( V_4 -> V_9 , V_15 , V_16 ) ;
if ( V_2 -> V_19 ) {
memcpy ( & time , & ( ( char * ) V_15 ) [ V_16 ] , V_20 ) ;
V_18 =
V_17 + ( T_1 ) F_11 ( time ) * 1000000 ;
}
return F_12 ( V_2 , V_4 -> V_9 ,
V_18 ) ;
}
