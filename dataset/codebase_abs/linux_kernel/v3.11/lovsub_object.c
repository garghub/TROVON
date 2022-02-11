int F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
struct V_3 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_14 ;
V_12 = & V_8 -> V_15 -> V_16 ;
V_10 = V_12 -> V_17 -> V_18 ( V_2 , V_4 -> V_19 , V_12 ) ;
if ( V_10 != NULL ) {
F_3 ( V_4 , V_10 ) ;
F_4 ( F_5 ( V_4 ) , sizeof( struct V_20 ) ) ;
V_13 = 0 ;
} else
V_13 = - V_21 ;
RETURN ( V_13 ) ;
}
static void F_6 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_22 * V_23 = F_7 ( V_4 ) ;
struct V_24 * V_25 = V_23 -> V_26 ;
V_14 ;
if ( V_25 ) {
F_8 ( V_25 -> V_27 == V_28 ) ;
F_8 ( V_25 -> V_29 . V_30 . V_31 [ V_23 -> V_32 ] == V_23 ) ;
F_9 ( & V_25 -> V_29 . V_30 . V_33 ) ;
V_25 -> V_29 . V_30 . V_31 [ V_23 -> V_32 ] = NULL ;
F_10 ( & V_25 -> V_29 . V_30 . V_33 ) ;
}
F_11 ( V_4 ) ;
F_12 ( & V_23 -> V_34 . V_35 ) ;
F_13 ( V_23 , V_36 ) ;
EXIT ;
}
static int F_14 ( const struct V_1 * V_2 , void * V_37 ,
T_1 V_38 , const struct V_3 * V_4 )
{
struct V_22 * V_23 = F_7 ( V_4 ) ;
return (* V_38)( V_2 , V_37 , L_1 , V_23 -> V_32 ) ;
}
static int F_15 ( const struct V_1 * V_2 , struct V_39 * V_4 ,
const struct V_40 * V_41 , unsigned V_42 )
{
struct V_24 * V_25 = F_16 ( V_4 ) -> V_26 ;
V_14 ;
F_17 ( V_25 ) -> V_43 = 0 ;
RETURN ( 0 ) ;
}
static int F_18 ( const struct V_1 * V_2 ,
const struct V_39 * V_4 ,
struct V_44 * V_45 )
{
struct V_22 * V_23 = F_16 ( V_4 ) ;
V_14 ;
RETURN ( F_19 ( V_2 , & V_23 -> V_26 -> V_46 , V_45 ) ) ;
}
struct V_3 * F_20 ( const struct V_1 * V_2 ,
const struct V_47 * V_48 ,
struct V_11 * V_8 )
{
struct V_22 * V_23 ;
struct V_3 * V_4 ;
V_14 ;
F_21 ( V_23 , V_36 , V_49 ) ;
if ( V_23 != NULL ) {
struct V_50 * V_51 ;
V_4 = F_22 ( V_23 ) ;
V_51 = & V_23 -> V_34 ;
F_23 ( V_51 ) ;
F_24 ( V_4 , & V_51 -> V_35 , V_8 ) ;
F_25 ( & V_51 -> V_35 , V_4 ) ;
V_23 -> V_52 . V_53 = & V_54 ;
V_4 -> V_55 = & V_56 ;
} else
V_4 = NULL ;
RETURN ( V_4 ) ;
}
