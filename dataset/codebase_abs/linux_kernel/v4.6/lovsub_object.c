int F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
struct V_3 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_12 = & V_8 -> V_14 -> V_15 ;
V_10 = V_12 -> V_16 -> V_17 ( V_2 , V_4 -> V_18 , V_12 ) ;
if ( V_10 ) {
F_3 ( V_4 , V_10 ) ;
F_4 ( F_5 ( V_4 ) , sizeof( struct V_19 ) ) ;
V_13 = 0 ;
} else
V_13 = - V_20 ;
return V_13 ;
}
static void F_6 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_21 * V_22 = F_7 ( V_4 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
if ( V_24 ) {
F_8 ( V_24 -> V_26 == V_27 ) ;
F_8 ( V_24 -> V_28 . V_29 . V_30 [ V_22 -> V_31 ] == V_22 ) ;
F_9 ( & V_24 -> V_28 . V_29 . V_32 ) ;
V_24 -> V_28 . V_29 . V_30 [ V_22 -> V_31 ] = NULL ;
F_10 ( & V_24 -> V_28 . V_29 . V_32 ) ;
}
F_11 ( V_4 ) ;
F_12 ( & V_22 -> V_33 . V_34 ) ;
F_13 ( V_35 , V_22 ) ;
}
static int F_14 ( const struct V_1 * V_2 , void * V_36 ,
T_1 V_37 , const struct V_3 * V_4 )
{
struct V_21 * V_22 = F_7 ( V_4 ) ;
return (* V_37)( V_2 , V_36 , L_1 , V_22 -> V_31 ) ;
}
static int F_15 ( const struct V_1 * V_2 , struct V_38 * V_4 ,
const struct V_39 * V_40 , unsigned V_41 )
{
struct V_23 * V_24 = F_16 ( V_4 ) -> V_25 ;
F_17 ( V_24 ) -> V_42 = 0 ;
return 0 ;
}
static int F_18 ( const struct V_1 * V_2 ,
const struct V_38 * V_4 ,
struct V_43 * V_44 )
{
struct V_21 * V_22 = F_16 ( V_4 ) ;
return F_19 ( V_2 , & V_22 -> V_25 -> V_45 , V_44 ) ;
}
struct V_3 * F_20 ( const struct V_1 * V_2 ,
const struct V_46 * V_47 ,
struct V_11 * V_8 )
{
struct V_21 * V_22 ;
struct V_3 * V_4 ;
V_22 = F_21 ( V_35 , V_48 ) ;
if ( V_22 ) {
struct V_49 * V_50 ;
V_4 = F_22 ( V_22 ) ;
V_50 = & V_22 -> V_33 ;
F_23 ( V_50 ) ;
F_24 ( V_4 , & V_50 -> V_34 , V_8 ) ;
F_25 ( & V_50 -> V_34 , V_4 ) ;
V_22 -> V_51 . V_52 = & V_53 ;
V_4 -> V_54 = & V_55 ;
} else
V_4 = NULL ;
return V_4 ;
}
