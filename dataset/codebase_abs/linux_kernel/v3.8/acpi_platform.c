struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_2 * V_5 ;
struct V_6 V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
int V_14 ;
if ( V_3 -> V_15 )
return NULL ;
F_2 ( & V_11 ) ;
V_14 = F_3 ( V_3 , & V_11 , NULL , NULL ) ;
if ( V_14 <= 0 )
return NULL ;
V_13 = F_4 ( V_14 * sizeof( struct V_12 ) , V_16 ) ;
if ( ! V_13 ) {
F_5 ( & V_3 -> V_17 , L_1 ) ;
F_6 ( & V_11 ) ;
return NULL ;
}
V_14 = 0 ;
F_7 (rentry, &resource_list, node)
V_13 [ V_14 ++ ] = V_9 -> V_18 ;
F_6 ( & V_11 ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_19 = NULL ;
V_5 = V_3 -> V_19 ;
if ( V_5 ) {
struct V_20 * V_21 ;
struct V_10 * V_22 ;
F_8 ( & V_5 -> V_23 ) ;
V_22 = & V_5 -> V_24 ;
if ( ! F_9 ( V_22 ) ) {
V_21 = F_10 ( V_22 ,
struct V_20 ,
V_25 ) ;
V_7 . V_19 = V_21 -> V_17 ;
}
F_11 ( & V_5 -> V_23 ) ;
}
V_7 . V_26 = F_12 ( & V_3 -> V_17 ) ;
V_7 . V_27 = - 1 ;
V_7 . V_18 = V_13 ;
V_7 . V_28 = V_14 ;
V_7 . V_29 . V_30 = V_3 -> V_30 ;
V_4 = F_13 ( & V_7 ) ;
if ( F_14 ( V_4 ) ) {
F_5 ( & V_3 -> V_17 , L_2 ,
F_15 ( V_4 ) ) ;
V_4 = NULL ;
} else {
F_16 ( & V_3 -> V_17 , L_3 ,
F_12 ( & V_4 -> V_17 ) ) ;
}
F_17 ( V_13 ) ;
return V_4 ;
}
