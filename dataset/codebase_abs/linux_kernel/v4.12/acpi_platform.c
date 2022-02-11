static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , struct V_3 * V_5 )
{
struct V_6 * V_7 ;
* V_5 = * V_4 ;
V_7 = F_2 ( V_2 -> V_7 ) ;
if ( V_7 && F_3 ( V_7 ) )
V_5 -> V_7 = F_4 ( F_5 ( V_7 ) , V_5 ) ;
}
struct V_8 * F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_8 * V_11 = NULL ;
struct V_12 V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 ;
struct V_3 * V_18 = NULL ;
int V_19 ;
if ( V_2 -> V_20 )
return NULL ;
if ( ! F_7 ( V_2 , V_21 ) )
return F_8 ( - V_22 ) ;
F_9 ( & V_17 ) ;
V_19 = F_10 ( V_2 , & V_17 , NULL , NULL ) ;
if ( V_19 < 0 ) {
return NULL ;
} else if ( V_19 > 0 ) {
V_18 = F_11 ( V_19 * sizeof( struct V_3 ) ,
V_23 ) ;
if ( ! V_18 ) {
F_12 ( & V_2 -> V_24 , L_1 ) ;
F_13 ( & V_17 ) ;
return F_8 ( - V_25 ) ;
}
V_19 = 0 ;
F_14 (rentry, &resource_list, node)
F_1 ( V_2 , V_15 -> V_26 ,
& V_18 [ V_19 ++ ] ) ;
F_13 ( & V_17 ) ;
}
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_7 = V_2 -> V_7 ?
F_2 ( V_2 -> V_7 ) : NULL ;
V_13 . V_27 = F_15 ( & V_2 -> V_24 ) ;
V_13 . V_28 = - 1 ;
V_13 . V_26 = V_18 ;
V_13 . V_29 = V_19 ;
V_13 . V_30 = F_16 ( V_2 ) ;
V_13 . V_10 = V_10 ;
if ( F_17 ( V_2 ) )
V_13 . V_31 = F_18 ( 32 ) ;
else
V_13 . V_31 = 0 ;
V_11 = F_19 ( & V_13 ) ;
if ( F_20 ( V_11 ) )
F_12 ( & V_2 -> V_24 , L_2 ,
F_21 ( V_11 ) ) ;
else {
F_22 ( & V_11 -> V_24 , F_23 ( V_2 -> V_32 ) ) ;
F_24 ( & V_2 -> V_24 , L_3 ,
F_15 ( & V_11 -> V_24 ) ) ;
}
F_25 ( V_18 ) ;
return V_11 ;
}
