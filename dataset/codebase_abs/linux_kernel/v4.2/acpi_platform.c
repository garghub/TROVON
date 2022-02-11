struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_2 * V_5 ;
struct V_6 V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 = NULL ;
int V_14 ;
if ( V_3 -> V_15 )
return NULL ;
if ( ! F_2 ( V_3 , V_16 ) )
return F_3 ( - V_17 ) ;
F_4 ( & V_11 ) ;
V_14 = F_5 ( V_3 , & V_11 , NULL , NULL ) ;
if ( V_14 < 0 ) {
return NULL ;
} else if ( V_14 > 0 ) {
V_13 = F_6 ( V_14 * sizeof( struct V_12 ) ,
V_18 ) ;
if ( ! V_13 ) {
F_7 ( & V_3 -> V_19 , L_1 ) ;
F_8 ( & V_11 ) ;
return F_3 ( - V_20 ) ;
}
V_14 = 0 ;
F_9 (rentry, &resource_list, node)
V_13 [ V_14 ++ ] = * V_9 -> V_21 ;
F_8 ( & V_11 ) ;
}
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_22 = NULL ;
V_5 = V_3 -> V_22 ;
if ( V_5 ) {
struct V_23 * V_24 ;
struct V_10 * V_25 ;
F_10 ( & V_5 -> V_26 ) ;
V_25 = & V_5 -> V_27 ;
if ( ! F_11 ( V_25 ) ) {
V_24 = F_12 ( V_25 ,
struct V_23 ,
V_28 ) ;
V_7 . V_22 = V_24 -> V_19 ;
}
F_13 ( & V_5 -> V_26 ) ;
}
V_7 . V_29 = F_14 ( & V_3 -> V_19 ) ;
V_7 . V_30 = - 1 ;
V_7 . V_21 = V_13 ;
V_7 . V_31 = V_14 ;
V_7 . V_32 = F_15 ( V_3 ) ;
V_7 . V_33 = F_16 ( V_3 , NULL ) ? F_17 ( 32 ) : 0 ;
V_4 = F_18 ( & V_7 ) ;
if ( F_19 ( V_4 ) )
F_7 ( & V_3 -> V_19 , L_2 ,
F_20 ( V_4 ) ) ;
else
F_21 ( & V_3 -> V_19 , L_3 ,
F_14 ( & V_4 -> V_19 ) ) ;
F_22 ( V_13 ) ;
return V_4 ;
}
