int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_1 * V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 ;
struct V_12 V_13 ;
struct V_14 * V_15 = NULL ;
int V_16 ;
if ( V_2 -> V_17 )
return 0 ;
F_2 ( & V_13 ) ;
V_16 = F_3 ( V_2 , & V_13 , NULL , NULL ) ;
if ( V_16 < 0 ) {
return 0 ;
} else if ( V_16 > 0 ) {
V_15 = F_4 ( V_16 * sizeof( struct V_14 ) ,
V_18 ) ;
if ( ! V_15 ) {
F_5 ( & V_2 -> V_19 , L_1 ) ;
F_6 ( & V_13 ) ;
return - V_20 ;
}
V_16 = 0 ;
F_7 (rentry, &resource_list, node)
V_15 [ V_16 ++ ] = V_11 -> V_21 ;
F_6 ( & V_13 ) ;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_22 = NULL ;
V_7 = V_2 -> V_22 ;
if ( V_7 ) {
struct V_23 * V_24 ;
struct V_12 * V_25 ;
F_8 ( & V_7 -> V_26 ) ;
V_25 = & V_7 -> V_27 ;
if ( ! F_9 ( V_25 ) ) {
V_24 = F_10 ( V_25 ,
struct V_23 ,
V_28 ) ;
V_9 . V_22 = V_24 -> V_19 ;
}
F_11 ( & V_7 -> V_26 ) ;
}
V_9 . V_29 = F_12 ( & V_2 -> V_19 ) ;
V_9 . V_4 = - 1 ;
V_9 . V_21 = V_15 ;
V_9 . V_30 = V_16 ;
V_9 . V_31 . V_32 = V_2 ;
V_6 = F_13 ( & V_9 ) ;
if ( F_14 ( V_6 ) ) {
F_5 ( & V_2 -> V_19 , L_2 ,
F_15 ( V_6 ) ) ;
V_6 = NULL ;
} else {
F_16 ( & V_2 -> V_19 , L_3 ,
F_12 ( & V_6 -> V_19 ) ) ;
}
F_17 ( V_15 ) ;
return 1 ;
}
void T_1 F_18 ( void )
{
F_19 ( & V_33 ) ;
}
