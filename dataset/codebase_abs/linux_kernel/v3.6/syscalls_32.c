long F_1 ( unsigned long V_1 , unsigned long V_2 ,
int T_1 * V_3 , void * V_4 , int T_1 * V_5 )
{
return F_2 ( V_1 , V_2 , V_3 , V_5 ) ;
}
long F_3 ( int V_6 , const struct V_7 T_1 * V_8 ,
struct V_7 T_1 * V_9 )
{
struct V_10 V_11 , V_12 ;
int V_13 ;
if ( V_8 ) {
T_2 V_14 ;
if ( ! F_4 ( V_15 , V_8 , sizeof( * V_8 ) ) ||
F_5 ( V_11 . V_16 . V_17 , & V_8 -> V_17 ) ||
F_5 ( V_11 . V_16 . V_18 , & V_8 -> V_18 ) ||
F_5 ( V_11 . V_16 . V_19 , & V_8 -> V_19 ) ||
F_5 ( V_14 , & V_8 -> V_20 ) )
return - V_21 ;
F_6 ( & V_11 . V_16 . V_20 , V_14 ) ;
}
V_13 = F_7 ( V_6 , V_8 ? & V_11 : NULL , V_9 ? & V_12 : NULL ) ;
if ( ! V_13 && V_9 ) {
if ( ! F_4 ( V_22 , V_9 , sizeof( * V_9 ) ) ||
F_8 ( V_12 . V_16 . V_17 , & V_9 -> V_17 ) ||
F_8 ( V_12 . V_16 . V_18 , & V_9 -> V_18 ) ||
F_8 ( V_12 . V_16 . V_19 , & V_9 -> V_19 ) ||
F_8 ( V_12 . V_16 . V_20 . V_6 [ 0 ] , & V_9 -> V_20 ) )
return - V_21 ;
}
return V_13 ;
}
