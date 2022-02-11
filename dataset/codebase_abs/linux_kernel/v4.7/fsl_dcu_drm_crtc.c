static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_5 ( V_9 -> V_11 , V_12 ,
V_13 ,
F_6 ( V_14 ) ) ;
F_7 ( V_9 -> V_11 , V_15 ,
V_16 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_5 ( V_9 -> V_11 , V_12 ,
V_13 ,
F_6 ( V_17 ) ) ;
F_7 ( V_9 -> V_11 , V_15 ,
V_16 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_18 * V_19 = & V_9 -> V_20 . V_21 ;
struct V_22 * V_23 = & V_2 -> V_5 -> V_23 ;
unsigned int V_24 , V_25 , V_26 , V_27 , V_28 , V_29 , V_30 , V_31 = 0 ;
V_30 = F_10 ( V_2 ) ;
F_11 ( V_9 -> V_32 , V_23 -> clock * 1000 ) ;
V_24 = V_23 -> V_33 - V_23 -> V_34 ;
V_25 = V_23 -> V_35 - V_23 -> V_36 ;
V_26 = V_23 -> V_34 - V_23 -> V_35 ;
V_27 = V_23 -> V_37 - V_23 -> V_38 ;
V_28 = V_23 -> V_39 - V_23 -> V_40 ;
V_29 = V_23 -> V_38 - V_23 -> V_39 ;
if ( ! ( V_19 -> V_41 . V_42 & V_43 ) )
V_31 |= V_44 ;
if ( V_23 -> V_45 & V_46 )
V_31 |= V_47 ;
if ( V_23 -> V_45 & V_48 )
V_31 |= V_49 ;
F_7 ( V_9 -> V_11 , V_50 ,
F_12 ( V_24 ) |
F_13 ( V_26 ) |
F_14 ( V_25 ) ) ;
F_7 ( V_9 -> V_11 , V_51 ,
F_15 ( V_27 ) |
F_16 ( V_29 ) |
F_17 ( V_28 ) ) ;
F_7 ( V_9 -> V_11 , V_52 ,
F_18 ( V_23 -> V_40 ) |
F_19 ( V_23 -> V_36 ) ) ;
F_7 ( V_9 -> V_11 , V_53 , V_31 ) ;
F_7 ( V_9 -> V_11 , V_54 , F_20 ( 0 ) |
F_21 ( 0 ) | F_22 ( 0 ) ) ;
F_7 ( V_9 -> V_11 , V_12 ,
F_23 ( 1 ) | V_55 ) ;
F_7 ( V_9 -> V_11 , V_56 ,
F_24 ( V_57 ) |
F_25 ( V_58 ) |
F_26 ( V_59 ) ) ;
F_7 ( V_9 -> V_11 , V_15 ,
V_16 ) ;
return;
}
int F_27 ( struct V_8 * V_9 )
{
struct V_60 * V_61 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
unsigned int V_62 , V_63 , V_64 ;
int V_65 ;
V_61 = F_28 ( V_9 -> V_66 ) ;
if ( ! V_61 )
return - V_67 ;
V_65 = F_29 ( V_9 -> V_66 , V_2 , V_61 , NULL ,
& V_68 , NULL ) ;
if ( V_65 ) {
V_61 -> V_69 -> V_70 ( V_61 ) ;
return V_65 ;
}
F_30 ( V_2 , & V_71 ) ;
if ( ! strcmp ( V_9 -> V_72 -> V_73 , L_1 ) )
V_64 = V_74 ;
else
V_64 = V_75 ;
for ( V_62 = 0 ; V_62 < V_9 -> V_72 -> V_76 ; V_62 ++ ) {
for ( V_63 = 1 ; V_63 <= V_64 ; V_63 ++ )
F_7 ( V_9 -> V_11 , F_31 ( V_62 , V_63 ) , 0 ) ;
}
F_5 ( V_9 -> V_11 , V_12 ,
V_13 ,
F_6 ( V_14 ) ) ;
F_7 ( V_9 -> V_11 , V_15 ,
V_16 ) ;
return 0 ;
}
