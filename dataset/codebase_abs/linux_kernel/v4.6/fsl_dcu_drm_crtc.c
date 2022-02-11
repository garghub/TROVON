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
struct V_18 * V_19 = & V_2 -> V_5 -> V_19 ;
unsigned int V_20 , V_21 , V_22 , V_23 , V_24 , V_25 , div , V_26 , V_27 = 0 ;
unsigned long V_28 ;
V_26 = F_10 ( V_2 ) ;
V_28 = F_11 ( V_9 -> V_29 ) ;
div = V_28 / V_19 -> clock / 1000 ;
V_20 = V_19 -> V_30 - V_19 -> V_31 ;
V_21 = V_19 -> V_32 - V_19 -> V_33 ;
V_22 = V_19 -> V_31 - V_19 -> V_32 ;
V_23 = V_19 -> V_34 - V_19 -> V_35 ;
V_24 = V_19 -> V_36 - V_19 -> V_37 ;
V_25 = V_19 -> V_35 - V_19 -> V_36 ;
if ( V_19 -> V_38 & V_39 )
V_27 |= V_40 ;
if ( V_19 -> V_38 & V_41 )
V_27 |= V_42 ;
F_7 ( V_9 -> V_11 , V_43 ,
F_12 ( V_20 ) |
F_13 ( V_22 ) |
F_14 ( V_21 ) ) ;
F_7 ( V_9 -> V_11 , V_44 ,
F_15 ( V_23 ) |
F_16 ( V_25 ) |
F_17 ( V_24 ) ) ;
F_7 ( V_9 -> V_11 , V_45 ,
F_18 ( V_19 -> V_37 ) |
F_19 ( V_19 -> V_33 ) ) ;
F_7 ( V_9 -> V_11 , V_46 , div ) ;
F_7 ( V_9 -> V_11 , V_47 , V_27 ) ;
F_7 ( V_9 -> V_11 , V_48 , F_20 ( 0 ) |
F_21 ( 0 ) | F_22 ( 0 ) ) ;
F_7 ( V_9 -> V_11 , V_12 ,
F_23 ( 1 ) | V_49 ) ;
F_7 ( V_9 -> V_11 , V_50 ,
F_24 ( V_51 ) |
F_25 ( V_52 ) |
F_26 ( V_53 ) ) ;
F_7 ( V_9 -> V_11 , V_15 ,
V_16 ) ;
return;
}
int F_27 ( struct V_8 * V_9 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
unsigned int V_56 , V_57 , V_58 ;
int V_59 ;
V_55 = F_28 ( V_9 -> V_60 ) ;
if ( ! V_55 )
return - V_61 ;
V_59 = F_29 ( V_9 -> V_60 , V_2 , V_55 , NULL ,
& V_62 , NULL ) ;
if ( V_59 ) {
V_55 -> V_63 -> V_64 ( V_55 ) ;
return V_59 ;
}
F_30 ( V_2 , & V_65 ) ;
if ( ! strcmp ( V_9 -> V_66 -> V_67 , L_1 ) )
V_58 = V_68 ;
else
V_58 = V_69 ;
for ( V_56 = 0 ; V_56 < V_9 -> V_66 -> V_70 ; V_56 ++ ) {
for ( V_57 = 1 ; V_57 <= V_58 ; V_57 ++ )
F_7 ( V_9 -> V_11 , F_31 ( V_56 , V_57 ) , 0 ) ;
}
F_5 ( V_9 -> V_11 , V_12 ,
V_13 ,
F_6 ( V_14 ) ) ;
F_7 ( V_9 -> V_11 , V_15 ,
V_16 ) ;
return 0 ;
}
