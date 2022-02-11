static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 ) -> V_4 ;
}
struct V_5 * F_3 ( struct V_6 * V_7 , const char * V_8 ,
const char * V_9 , unsigned long V_10 ,
unsigned long V_4 )
{
struct V_11 * V_12 ;
struct V_5 * V_5 ;
struct V_13 V_14 ;
V_12 = F_4 ( sizeof( struct V_11 ) , V_15 ) ;
if ( ! V_12 ) {
F_5 ( L_1 , V_16 ) ;
return F_6 ( - V_17 ) ;
}
V_14 . V_8 = V_8 ;
V_14 . V_18 = & V_19 ;
V_14 . V_10 = V_10 ;
V_14 . V_20 = ( V_9 ? & V_9 : NULL ) ;
V_14 . V_21 = ( V_9 ? 1 : 0 ) ;
V_12 -> V_4 = V_4 ;
V_12 -> V_2 . V_14 = & V_14 ;
V_5 = F_7 ( V_7 , & V_12 -> V_2 ) ;
if ( F_8 ( V_5 ) )
F_9 ( V_12 ) ;
return V_5 ;
}
