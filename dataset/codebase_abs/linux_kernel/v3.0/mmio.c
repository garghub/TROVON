static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
T_1 F_3 ( struct V_2 * V_3 )
{
return F_4 ( F_1 ( V_3 ) -> V_5 ) ;
}
T_1 F_5 ( struct V_2 * V_3 )
{
return ~ F_4 ( F_1 ( V_3 ) -> V_5 ) ;
}
T_1 F_6 ( struct V_2 * V_3 )
{
return F_7 ( F_1 ( V_3 ) -> V_5 ) ;
}
T_1 F_8 ( struct V_2 * V_3 )
{
return ~ ( unsigned ) F_7 ( F_1 ( V_3 ) -> V_5 ) ;
}
int T_2 F_9 ( void T_3 * V_6 , const char * V_7 ,
unsigned long V_8 , int V_9 , unsigned V_10 ,
T_1 (* F_10)( struct V_2 * ) )
{
struct V_1 * V_11 ;
if ( V_10 > 32 || V_10 < 16 )
return - V_12 ;
V_11 = F_11 ( sizeof( struct V_1 ) , V_13 ) ;
if ( ! V_11 )
return - V_14 ;
V_11 -> V_5 = V_6 ;
V_11 -> V_4 . V_7 = V_7 ;
V_11 -> V_4 . V_9 = V_9 ;
V_11 -> V_4 . F_10 = F_10 ;
V_11 -> V_4 . V_15 = F_12 ( V_10 ) ;
V_11 -> V_4 . V_16 = V_17 ;
return F_13 ( & V_11 -> V_4 , V_8 ) ;
}
