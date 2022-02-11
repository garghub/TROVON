long F_1 ( int V_1 , const struct V_2 T_1 * V_3 ,
struct V_2 T_1 * V_4 )
{
struct V_5 V_6 , V_7 ;
int V_8 ;
if ( V_3 ) {
T_2 V_9 ;
if ( ! F_2 ( V_10 , V_3 , sizeof( * V_3 ) ) ||
F_3 ( V_6 . V_11 . V_12 , & V_3 -> V_12 ) ||
F_3 ( V_6 . V_11 . V_13 , & V_3 -> V_13 ) ||
F_3 ( V_6 . V_11 . V_14 , & V_3 -> V_14 ) ||
F_3 ( V_9 , & V_3 -> V_15 ) )
return - V_16 ;
F_4 ( & V_6 . V_11 . V_15 , V_9 ) ;
}
V_8 = F_5 ( V_1 , V_3 ? & V_6 : NULL , V_4 ? & V_7 : NULL ) ;
if ( ! V_8 && V_4 ) {
if ( ! F_2 ( V_17 , V_4 , sizeof( * V_4 ) ) ||
F_6 ( V_7 . V_11 . V_12 , & V_4 -> V_12 ) ||
F_6 ( V_7 . V_11 . V_13 , & V_4 -> V_13 ) ||
F_6 ( V_7 . V_11 . V_14 , & V_4 -> V_14 ) ||
F_6 ( V_7 . V_11 . V_15 . V_1 [ 0 ] , & V_4 -> V_15 ) )
return - V_16 ;
}
return V_8 ;
}
