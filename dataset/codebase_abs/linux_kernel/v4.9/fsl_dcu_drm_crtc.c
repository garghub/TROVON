static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 -> V_11 ;
F_2 ( V_8 -> V_13 ,
V_14 , V_15 ) ;
if ( V_11 ) {
V_2 -> V_12 -> V_11 = NULL ;
F_3 ( & V_2 -> V_6 -> V_16 ) ;
if ( F_4 ( V_2 ) == 0 )
F_5 ( V_2 , V_11 ) ;
else
F_6 ( V_2 , V_11 ) ;
F_7 ( & V_2 -> V_6 -> V_16 ) ;
}
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_9 ( V_4 , true ) ;
F_10 ( V_2 ) ;
F_11 ( V_8 -> V_13 , V_17 ,
V_18 ,
F_12 ( V_19 ) ) ;
F_2 ( V_8 -> V_13 , V_14 ,
V_15 ) ;
F_13 ( V_8 -> V_20 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_15 ( V_8 -> V_20 ) ;
F_11 ( V_8 -> V_13 , V_17 ,
V_18 ,
F_12 ( V_21 ) ) ;
F_2 ( V_8 -> V_13 , V_14 ,
V_15 ) ;
F_16 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_22 * V_23 = & V_8 -> V_24 . V_25 ;
struct V_26 * V_27 = & V_2 -> V_12 -> V_27 ;
unsigned int V_28 , V_29 , V_30 , V_31 , V_32 , V_33 , V_34 , V_35 = 0 ;
V_34 = F_18 ( V_2 ) ;
F_19 ( V_8 -> V_20 , V_27 -> clock * 1000 ) ;
V_28 = V_27 -> V_36 - V_27 -> V_37 ;
V_29 = V_27 -> V_38 - V_27 -> V_39 ;
V_30 = V_27 -> V_37 - V_27 -> V_38 ;
V_31 = V_27 -> V_40 - V_27 -> V_41 ;
V_32 = V_27 -> V_42 - V_27 -> V_43 ;
V_33 = V_27 -> V_41 - V_27 -> V_42 ;
if ( ! ( V_23 -> V_44 . V_45 & V_46 ) )
V_35 |= V_47 ;
if ( V_27 -> V_48 & V_49 )
V_35 |= V_50 ;
if ( V_27 -> V_48 & V_51 )
V_35 |= V_52 ;
F_2 ( V_8 -> V_13 , V_53 ,
F_20 ( V_28 ) |
F_21 ( V_30 ) |
F_22 ( V_29 ) ) ;
F_2 ( V_8 -> V_13 , V_54 ,
F_23 ( V_31 ) |
F_24 ( V_33 ) |
F_25 ( V_32 ) ) ;
F_2 ( V_8 -> V_13 , V_55 ,
F_26 ( V_27 -> V_43 ) |
F_27 ( V_27 -> V_39 ) ) ;
F_2 ( V_8 -> V_13 , V_56 , V_35 ) ;
F_2 ( V_8 -> V_13 , V_57 , F_28 ( 0 ) |
F_29 ( 0 ) | F_30 ( 0 ) ) ;
F_2 ( V_8 -> V_13 , V_17 ,
F_31 ( 1 ) | V_58 ) ;
F_2 ( V_8 -> V_13 , V_59 ,
F_32 ( V_60 ) |
F_33 ( V_61 ) |
F_34 ( V_62 ) ) ;
return;
}
int F_35 ( struct V_7 * V_8 )
{
struct V_63 * V_64 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_65 ;
F_36 ( V_8 -> V_66 ) ;
V_64 = F_37 ( V_8 -> V_66 ) ;
if ( ! V_64 )
return - V_67 ;
V_65 = F_38 ( V_8 -> V_66 , V_2 , V_64 , NULL ,
& V_68 , NULL ) ;
if ( V_65 ) {
V_64 -> V_69 -> V_70 ( V_64 ) ;
return V_65 ;
}
F_39 ( V_2 , & V_71 ) ;
return 0 ;
}
