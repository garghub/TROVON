static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
if ( V_6 ) {
V_2 -> V_7 -> V_6 = NULL ;
F_2 ( & V_2 -> V_8 -> V_9 ) ;
if ( F_3 ( V_2 ) == 0 )
F_4 ( V_2 , V_6 ) ;
else
F_5 ( V_2 , V_6 ) ;
F_6 ( & V_2 -> V_8 -> V_9 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_8 = V_2 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_13 ;
F_8 ( V_2 ) ;
F_9 ( V_12 -> V_14 , V_15 ,
V_16 ,
F_10 ( V_17 ) ) ;
F_11 ( V_12 -> V_14 , V_18 ,
V_19 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_8 = V_2 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_13 ;
F_9 ( V_12 -> V_14 , V_15 ,
V_16 ,
F_10 ( V_20 ) ) ;
F_11 ( V_12 -> V_14 , V_18 ,
V_19 ) ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_10 * V_8 = V_2 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_21 * V_22 = & V_12 -> V_23 . V_24 ;
struct V_25 * V_26 = & V_2 -> V_7 -> V_26 ;
unsigned int V_27 , V_28 , V_29 , V_30 , V_31 , V_32 , V_33 , V_34 = 0 ;
V_33 = F_15 ( V_2 ) ;
F_16 ( V_12 -> V_35 , V_26 -> clock * 1000 ) ;
V_27 = V_26 -> V_36 - V_26 -> V_37 ;
V_28 = V_26 -> V_38 - V_26 -> V_39 ;
V_29 = V_26 -> V_37 - V_26 -> V_38 ;
V_30 = V_26 -> V_40 - V_26 -> V_41 ;
V_31 = V_26 -> V_42 - V_26 -> V_43 ;
V_32 = V_26 -> V_41 - V_26 -> V_42 ;
if ( ! ( V_22 -> V_44 . V_45 & V_46 ) )
V_34 |= V_47 ;
if ( V_26 -> V_48 & V_49 )
V_34 |= V_50 ;
if ( V_26 -> V_48 & V_51 )
V_34 |= V_52 ;
F_11 ( V_12 -> V_14 , V_53 ,
F_17 ( V_27 ) |
F_18 ( V_29 ) |
F_19 ( V_28 ) ) ;
F_11 ( V_12 -> V_14 , V_54 ,
F_20 ( V_30 ) |
F_21 ( V_32 ) |
F_22 ( V_31 ) ) ;
F_11 ( V_12 -> V_14 , V_55 ,
F_23 ( V_26 -> V_43 ) |
F_24 ( V_26 -> V_39 ) ) ;
F_11 ( V_12 -> V_14 , V_56 , V_34 ) ;
F_11 ( V_12 -> V_14 , V_57 , F_25 ( 0 ) |
F_26 ( 0 ) | F_27 ( 0 ) ) ;
F_11 ( V_12 -> V_14 , V_15 ,
F_28 ( 1 ) | V_58 ) ;
F_11 ( V_12 -> V_14 , V_59 ,
F_29 ( V_60 ) |
F_30 ( V_61 ) |
F_31 ( V_62 ) ) ;
F_11 ( V_12 -> V_14 , V_18 ,
V_19 ) ;
return;
}
int F_32 ( struct V_11 * V_12 )
{
struct V_63 * V_64 ;
struct V_1 * V_2 = & V_12 -> V_2 ;
int V_65 ;
F_33 ( V_12 -> V_66 ) ;
V_64 = F_34 ( V_12 -> V_66 ) ;
if ( ! V_64 )
return - V_67 ;
V_65 = F_35 ( V_12 -> V_66 , V_2 , V_64 , NULL ,
& V_68 , NULL ) ;
if ( V_65 ) {
V_64 -> V_69 -> V_70 ( V_64 ) ;
return V_65 ;
}
F_36 ( V_2 , & V_71 ) ;
return 0 ;
}
