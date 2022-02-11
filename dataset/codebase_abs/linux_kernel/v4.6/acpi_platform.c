struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
struct V_5 V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 = NULL ;
int V_13 ;
if ( V_3 -> V_14 )
return NULL ;
if ( ! F_2 ( V_3 , V_15 ) )
return F_3 ( - V_16 ) ;
F_4 ( & V_10 ) ;
V_13 = F_5 ( V_3 , & V_10 , NULL , NULL ) ;
if ( V_13 < 0 ) {
return NULL ;
} else if ( V_13 > 0 ) {
V_12 = F_6 ( V_13 * sizeof( struct V_11 ) ,
V_17 ) ;
if ( ! V_12 ) {
F_7 ( & V_3 -> V_18 , L_1 ) ;
F_8 ( & V_10 ) ;
return F_3 ( - V_19 ) ;
}
V_13 = 0 ;
F_9 (rentry, &resource_list, node)
V_12 [ V_13 ++ ] = * V_8 -> V_20 ;
F_8 ( & V_10 ) ;
}
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_21 = V_3 -> V_21 ?
F_10 ( V_3 -> V_21 ) : NULL ;
V_6 . V_22 = F_11 ( & V_3 -> V_18 ) ;
V_6 . V_23 = - 1 ;
V_6 . V_20 = V_12 ;
V_6 . V_24 = V_13 ;
V_6 . V_25 = F_12 ( V_3 ) ;
if ( F_13 ( V_3 ) )
V_6 . V_26 = F_14 ( 32 ) ;
else
V_6 . V_26 = 0 ;
V_4 = F_15 ( & V_6 ) ;
if ( F_16 ( V_4 ) )
F_7 ( & V_3 -> V_18 , L_2 ,
F_17 ( V_4 ) ) ;
else
F_18 ( & V_3 -> V_18 , L_3 ,
F_11 ( & V_4 -> V_18 ) ) ;
F_19 ( V_12 ) ;
return V_4 ;
}
