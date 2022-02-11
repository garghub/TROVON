static int F_1 ( const struct V_1 * V_2 , void * V_3 ,
T_1 V_4 , const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 * V_9 = V_8 -> V_10 ;
struct V_11 * V_12 ;
(* V_4)( V_2 , V_3 , L_1 ,
F_3 ( & V_8 -> V_13 ) ? L_2 : L_3 ,
V_8 -> V_14 , F_4 ( & V_8 -> V_15 ) ,
V_9 ) ;
if ( V_9 ) {
V_12 = F_5 ( V_9 ) ;
(* V_4)( V_2 , V_3 , L_4 V_16 ,
V_9 -> V_17 , V_9 -> V_18 , V_9 -> V_19 ,
V_9 -> V_20 , F_4 ( & V_9 -> V_21 ) ,
V_12 -> V_22 , F_6 ( & V_12 -> V_23 ) ) ;
}
return 0 ;
}
static int F_7 ( const struct V_1 * V_2 , struct V_24 * V_8 ,
struct V_25 * V_26 )
{
struct V_9 * V_9 = F_8 ( V_8 ) ;
V_26 -> V_27 = F_9 ( V_9 ) ;
V_26 -> V_28 = F_10 ( V_9 -> V_29 ) ;
V_26 -> V_30 = F_10 ( V_9 -> V_31 ) ;
V_26 -> V_32 = F_10 ( V_9 -> V_33 ) ;
V_26 -> V_34 = V_9 -> V_35 ;
V_26 -> V_36 = V_9 -> V_37 ;
V_26 -> V_38 = V_9 -> V_39 ;
return 0 ;
}
static int F_11 ( const struct V_1 * V_2 , struct V_24 * V_8 ,
const struct V_25 * V_26 , unsigned V_40 )
{
struct V_9 * V_9 = F_8 ( V_8 ) ;
if ( V_40 & V_41 )
V_9 -> V_37 = V_26 -> V_36 ;
if ( V_40 & V_42 )
V_9 -> V_39 = V_26 -> V_38 ;
if ( V_40 & V_43 )
F_10 ( V_9 -> V_31 ) = V_26 -> V_30 ;
if ( V_40 & V_44 )
F_10 ( V_9 -> V_29 ) = V_26 -> V_28 ;
if ( V_40 & V_45 )
F_10 ( V_9 -> V_33 ) = V_26 -> V_32 ;
if ( 0 && V_40 & V_46 )
F_12 ( V_9 , V_26 -> V_27 ) ;
if ( 0 && V_40 & ( V_41 | V_42 | V_46 ) )
F_13 ( V_9 ) ;
return 0 ;
}
int F_14 ( const struct V_1 * V_2 , struct V_24 * V_8 ,
const struct V_47 * V_48 )
{
struct V_11 * V_12 = F_5 ( V_48 -> V_49 ) ;
if ( V_48 -> V_50 == V_51 ) {
V_12 -> V_52 = V_53 ;
return 0 ;
}
if ( V_48 -> V_50 != V_54 )
return 0 ;
if ( V_48 -> V_55 . V_56 != NULL && V_48 -> V_55 . V_56 -> V_57 != NULL ) {
F_15 ( V_58 , L_5 ,
V_12 -> V_52 ,
V_48 -> V_55 . V_56 -> V_57 -> V_59 ) ;
V_12 -> V_60 = true ;
V_12 -> V_52 = V_48 -> V_55 . V_56 -> V_57 -> V_59 ;
} else {
F_15 ( V_58 , L_6 ,
V_12 -> V_52 ) ;
V_12 -> V_60 = false ;
V_12 -> V_52 = V_61 ;
}
return 0 ;
}
struct V_7 * F_16 ( struct V_9 * V_9 )
{
struct V_62 * V_12 = F_17 ( V_9 ) ;
struct V_24 * V_8 = V_12 -> V_22 ;
struct V_5 * V_63 ;
F_18 ( V_8 != NULL ) ;
V_63 = F_19 ( V_8 -> V_64 . V_65 , & V_66 ) ;
F_18 ( V_63 != NULL ) ;
return F_2 ( V_63 ) ;
}
struct V_5 * F_20 ( const struct V_1 * V_2 ,
const struct V_67 * V_68 ,
struct V_69 * V_70 )
{
return F_21 ( V_2 , V_68 , V_70 , & V_71 , & V_72 ) ;
}
