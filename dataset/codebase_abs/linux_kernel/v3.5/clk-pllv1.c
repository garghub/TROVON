static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( F_4 ( V_5 -> V_6 ) , V_3 ) ;
}
struct V_7 * F_5 ( const char * V_8 , const char * V_9 ,
void T_1 * V_6 )
{
struct V_4 * V_5 ;
struct V_7 * V_7 ;
struct V_10 V_11 ;
V_5 = F_6 ( sizeof( * V_5 ) , V_12 ) ;
if ( ! V_5 )
return F_7 ( - V_13 ) ;
V_5 -> V_6 = V_6 ;
V_11 . V_8 = V_8 ;
V_11 . V_14 = & V_15 ;
V_11 . V_16 = 0 ;
V_11 . V_17 = & V_9 ;
V_11 . V_18 = 1 ;
V_5 -> V_2 . V_11 = & V_11 ;
V_7 = F_8 ( NULL , & V_5 -> V_2 ) ;
if ( F_9 ( V_7 ) )
F_10 ( V_5 ) ;
return V_7 ;
}
