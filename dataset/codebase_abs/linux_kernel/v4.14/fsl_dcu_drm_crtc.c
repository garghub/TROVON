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
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_21 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_15 ( V_8 -> V_20 ) ;
F_11 ( V_8 -> V_13 , V_17 ,
V_18 ,
F_12 ( V_22 ) ) ;
F_2 ( V_8 -> V_13 , V_14 ,
V_15 ) ;
F_16 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_23 * V_24 = & V_8 -> V_25 . V_26 ;
struct V_27 * V_28 = & V_2 -> V_12 -> V_28 ;
unsigned int V_29 , V_30 , V_31 , V_32 , V_33 , V_34 , V_35 , V_36 = 0 ;
V_35 = F_18 ( V_2 ) ;
F_19 ( V_8 -> V_20 , V_28 -> clock * 1000 ) ;
V_29 = V_28 -> V_37 - V_28 -> V_38 ;
V_30 = V_28 -> V_39 - V_28 -> V_40 ;
V_31 = V_28 -> V_38 - V_28 -> V_39 ;
V_32 = V_28 -> V_41 - V_28 -> V_42 ;
V_33 = V_28 -> V_43 - V_28 -> V_44 ;
V_34 = V_28 -> V_42 - V_28 -> V_43 ;
if ( ! ( V_24 -> V_45 . V_46 & V_47 ) )
V_36 |= V_48 ;
if ( V_28 -> V_49 & V_50 )
V_36 |= V_51 ;
if ( V_28 -> V_49 & V_52 )
V_36 |= V_53 ;
F_2 ( V_8 -> V_13 , V_54 ,
F_20 ( V_29 ) |
F_21 ( V_31 ) |
F_22 ( V_30 ) ) ;
F_2 ( V_8 -> V_13 , V_55 ,
F_23 ( V_32 ) |
F_24 ( V_34 ) |
F_25 ( V_33 ) ) ;
F_2 ( V_8 -> V_13 , V_56 ,
F_26 ( V_28 -> V_44 ) |
F_27 ( V_28 -> V_40 ) ) ;
F_2 ( V_8 -> V_13 , V_57 , V_36 ) ;
F_2 ( V_8 -> V_13 , V_58 , F_28 ( 0 ) |
F_29 ( 0 ) | F_30 ( 0 ) ) ;
F_2 ( V_8 -> V_13 , V_17 ,
F_31 ( 1 ) | V_59 ) ;
F_2 ( V_8 -> V_13 , V_60 ,
F_32 ( V_61 ) |
F_33 ( V_62 ) |
F_34 ( V_63 ) ) ;
return;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
unsigned int V_64 ;
F_36 ( V_8 -> V_13 , V_65 , & V_64 ) ;
V_64 &= ~ V_66 ;
F_2 ( V_8 -> V_13 , V_65 , V_64 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
unsigned int V_64 ;
F_36 ( V_8 -> V_13 , V_65 , & V_64 ) ;
V_64 |= V_66 ;
F_2 ( V_8 -> V_13 , V_65 , V_64 ) ;
}
int F_38 ( struct V_7 * V_8 )
{
struct V_67 * V_68 ;
struct V_1 * V_2 = & V_8 -> V_2 ;
int V_69 ;
F_39 ( V_8 -> V_70 ) ;
V_68 = F_40 ( V_8 -> V_70 ) ;
if ( ! V_68 )
return - V_71 ;
V_69 = F_41 ( V_8 -> V_70 , V_2 , V_68 , NULL ,
& V_72 , NULL ) ;
if ( V_69 ) {
V_68 -> V_73 -> V_74 ( V_68 ) ;
return V_69 ;
}
F_42 ( V_2 , & V_75 ) ;
return 0 ;
}
