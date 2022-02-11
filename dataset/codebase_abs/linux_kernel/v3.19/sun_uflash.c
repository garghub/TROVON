int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( V_2 -> V_7 [ 1 ] . V_8 ) {
F_2 (KERN_ERR PFX L_1 ,
dp->full_name, (unsigned long long)op->resource[0].start) ;
return - V_9 ;
}
V_6 = F_3 ( sizeof( struct V_5 ) , V_10 ) ;
if ( ! V_6 ) {
F_2 (KERN_ERR PFX L_2 ) ;
return - V_11 ;
}
memcpy ( & V_6 -> V_12 , & V_13 , sizeof( V_13 ) ) ;
V_6 -> V_12 . V_14 = F_4 ( & V_2 -> V_7 [ 0 ] ) ;
V_6 -> V_15 = F_5 ( V_4 , L_3 , NULL ) ;
if ( V_6 -> V_15 && 0 < strlen ( V_6 -> V_15 ) )
V_6 -> V_12 . V_15 = V_6 -> V_15 ;
V_6 -> V_12 . V_16 = V_2 -> V_7 [ 0 ] . V_17 ;
V_6 -> V_12 . V_18 = F_6 ( & V_2 -> V_7 [ 0 ] , 0 , V_6 -> V_12 . V_14 ,
V_19 ) ;
if ( ! V_6 -> V_12 . V_18 ) {
F_2 (KERN_ERR PFX L_4 ) ;
F_7 ( V_6 ) ;
return - V_20 ;
}
F_8 ( & V_6 -> V_12 ) ;
V_6 -> V_21 = F_9 ( L_5 , & V_6 -> V_12 ) ;
if ( ! V_6 -> V_21 ) {
F_10 ( & V_2 -> V_7 [ 0 ] , V_6 -> V_12 . V_18 , V_6 -> V_12 . V_14 ) ;
F_7 ( V_6 ) ;
return - V_22 ;
}
V_6 -> V_21 -> V_23 = V_24 ;
F_11 ( V_6 -> V_21 , NULL , 0 ) ;
F_12 ( & V_2 -> V_25 , V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_25 . V_26 ;
if ( ! F_14 ( V_4 , L_6 , NULL ) )
return - V_9 ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_16 ( & V_2 -> V_25 ) ;
if ( V_6 -> V_21 ) {
F_17 ( V_6 -> V_21 ) ;
F_18 ( V_6 -> V_21 ) ;
}
if ( V_6 -> V_12 . V_18 ) {
F_10 ( & V_2 -> V_7 [ 0 ] , V_6 -> V_12 . V_18 , V_6 -> V_12 . V_14 ) ;
V_6 -> V_12 . V_18 = NULL ;
}
F_7 ( V_6 ) ;
return 0 ;
}
