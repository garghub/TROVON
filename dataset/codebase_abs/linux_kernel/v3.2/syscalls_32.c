long F_1 ( unsigned long V_1 , unsigned long V_2 ,
int T_1 * V_3 , void * V_4 , int T_1 * V_5 )
{
long V_6 ;
if ( ! V_2 )
V_2 = F_2 ( & V_7 -> V_8 . V_9 . V_9 ) ;
V_7 -> V_8 . V_10 = 1 ;
V_6 = F_3 ( V_1 , V_2 , & V_7 -> V_8 . V_9 , 0 , V_3 ,
V_5 ) ;
V_7 -> V_8 . V_10 = 0 ;
return V_6 ;
}
long F_4 ( int V_11 , const struct V_12 T_1 * V_13 ,
struct V_12 T_1 * V_14 )
{
struct V_15 V_16 , V_17 ;
int V_6 ;
if ( V_13 ) {
T_2 V_18 ;
if ( ! F_5 ( V_19 , V_13 , sizeof( * V_13 ) ) ||
F_6 ( V_16 . V_20 . V_21 , & V_13 -> V_21 ) ||
F_6 ( V_16 . V_20 . V_22 , & V_13 -> V_22 ) )
return - V_23 ;
F_6 ( V_16 . V_20 . V_24 , & V_13 -> V_24 ) ;
F_6 ( V_18 , & V_13 -> V_25 ) ;
F_7 ( & V_16 . V_20 . V_25 , V_18 ) ;
}
V_6 = F_8 ( V_11 , V_13 ? & V_16 : NULL , V_14 ? & V_17 : NULL ) ;
if ( ! V_6 && V_14 ) {
if ( ! F_5 ( V_26 , V_14 , sizeof( * V_14 ) ) ||
F_9 ( V_17 . V_20 . V_21 , & V_14 -> V_21 ) ||
F_9 ( V_17 . V_20 . V_22 , & V_14 -> V_22 ) )
return - V_23 ;
F_9 ( V_17 . V_20 . V_24 , & V_14 -> V_24 ) ;
F_9 ( V_17 . V_20 . V_25 . V_11 [ 0 ] , & V_14 -> V_25 ) ;
}
return V_6 ;
}
