static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
T_1 F_3 ( struct V_2 * V_3 )
{
return ( T_1 ) F_4 ( F_1 ( V_3 ) -> V_5 ) ;
}
T_1 F_5 ( struct V_2 * V_3 )
{
return ~ ( T_1 ) F_4 ( F_1 ( V_3 ) -> V_5 ) & V_3 -> V_6 ;
}
T_1 F_6 ( struct V_2 * V_3 )
{
return ( T_1 ) F_7 ( F_1 ( V_3 ) -> V_5 ) ;
}
T_1 F_8 ( struct V_2 * V_3 )
{
return ~ ( T_1 ) F_7 ( F_1 ( V_3 ) -> V_5 ) & V_3 -> V_6 ;
}
int T_2 F_9 ( void T_3 * V_7 , const char * V_8 ,
unsigned long V_9 , int V_10 , unsigned V_11 ,
T_1 (* F_10)( struct V_2 * ) )
{
struct V_1 * V_12 ;
if ( V_11 > 32 || V_11 < 16 )
return - V_13 ;
V_12 = F_11 ( sizeof( struct V_1 ) , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
V_12 -> V_5 = V_7 ;
V_12 -> V_4 . V_8 = V_8 ;
V_12 -> V_4 . V_10 = V_10 ;
V_12 -> V_4 . F_10 = F_10 ;
V_12 -> V_4 . V_6 = F_12 ( V_11 ) ;
V_12 -> V_4 . V_16 = V_17 ;
return F_13 ( & V_12 -> V_4 , V_9 ) ;
}
