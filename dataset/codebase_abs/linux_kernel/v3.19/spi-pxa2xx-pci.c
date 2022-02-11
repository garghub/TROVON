static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_6 != V_2 -> V_7 -> V_8 )
return false ;
V_2 -> V_9 = V_5 ;
return true ;
}
static int F_2 ( struct V_10 * V_8 ,
const struct V_11 * V_12 )
{
struct V_13 V_14 ;
int V_15 ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
char V_24 [ 40 ] ;
struct V_10 * V_6 ;
V_15 = F_3 ( V_8 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_4 ( V_8 , 1 << 0 , L_1 ) ;
if ( V_15 )
return V_15 ;
V_23 = & V_25 [ V_12 -> V_26 ] ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_27 = ( V_23 -> V_27 > 0 ) ?
V_23 -> V_27 : V_8 -> V_28 ;
V_6 = F_5 ( V_8 -> V_29 , F_6 ( F_7 ( V_8 -> V_28 ) , 0 ) ) ;
if ( V_23 -> V_30 ) {
struct V_4 * V_31 = V_23 -> V_30 ;
V_31 -> V_6 = & V_6 -> V_8 ;
V_31 -> V_32 = 1 ;
V_31 -> V_33 = 0 ;
}
if ( V_23 -> V_34 ) {
struct V_4 * V_31 = V_23 -> V_34 ;
V_31 -> V_6 = & V_6 -> V_8 ;
V_31 -> V_32 = 1 ;
V_31 -> V_33 = 0 ;
}
V_19 . V_35 = F_1 ;
V_19 . V_30 = V_23 -> V_30 ;
V_19 . V_34 = V_23 -> V_34 ;
V_19 . V_36 = V_23 -> V_34 && V_23 -> V_30 ;
V_21 = & V_19 . V_21 ;
V_21 -> V_37 = F_8 ( V_8 , 0 ) ;
V_21 -> V_38 = F_9 ( V_8 ) [ 0 ] ;
if ( ! V_21 -> V_38 ) {
F_10 ( & V_8 -> V_8 , L_2 ) ;
return - V_39 ;
}
V_21 -> V_40 = V_8 -> V_40 ;
V_21 -> V_41 = ( V_23 -> V_41 >= 0 ) ? V_23 -> V_41 : V_8 -> V_28 ;
V_21 -> type = V_23 -> type ;
snprintf ( V_24 , sizeof( V_24 ) , L_3 , V_21 -> V_41 ) ;
V_21 -> V_42 = F_11 ( & V_8 -> V_8 , V_24 , NULL ,
V_43 , V_23 -> V_44 ) ;
if ( F_12 ( V_21 -> V_42 ) )
return F_13 ( V_21 -> V_42 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_45 = & V_8 -> V_8 ;
V_14 . V_46 = L_4 ;
V_14 . V_47 = V_21 -> V_41 ;
V_14 . V_48 = & V_19 ;
V_14 . V_49 = sizeof( V_19 ) ;
V_17 = F_14 ( & V_14 ) ;
if ( F_12 ( V_17 ) ) {
F_15 ( V_21 -> V_42 ) ;
return F_13 ( V_17 ) ;
}
F_16 ( V_8 , V_17 ) ;
return 0 ;
}
static void F_17 ( struct V_10 * V_8 )
{
struct V_16 * V_17 = F_18 ( V_8 ) ;
struct V_18 * V_19 ;
V_19 = F_19 ( & V_17 -> V_8 ) ;
F_20 ( V_17 ) ;
F_15 ( V_19 -> V_21 . V_42 ) ;
}
