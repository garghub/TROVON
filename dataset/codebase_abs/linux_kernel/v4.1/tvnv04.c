int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_5 -> V_8 ) ;
return V_7 -> V_9 ( V_7 , V_3 , L_1 ,
V_10 , NULL , NULL ) ;
}
static void F_3 ( struct V_11 * V_12 , int V_13 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_14 * V_15 = V_14 ( V_12 ) ;
struct V_16 * V_17 = & F_4 ( V_2 ) -> V_18 ;
T_1 V_19 ;
F_5 ( V_5 , L_2 ,
V_13 , V_15 -> V_20 -> V_21 ) ;
V_17 -> V_22 &= ~ ( V_23 | V_24 ) ;
if ( V_13 == V_25 ) {
int V_26 = F_6 ( V_12 -> V_27 ) -> V_21 ;
V_19 = F_7 ( V_2 , V_26 , V_28 ) ;
V_17 -> V_22 |= V_26 ? V_24 :
V_23 ;
V_19 |= 0x80 ;
F_8 ( V_2 , V_26 , V_28 , V_19 ) ;
}
F_9 ( V_2 , 0 , V_29 , V_17 -> V_22 ) ;
F_10 ( V_12 ) -> F_11 ( V_12 , V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_26 , bool V_30 )
{
struct V_31 * V_17 = & F_4 ( V_2 ) -> V_18 . V_32 [ V_26 ] ;
V_17 -> V_33 = 0 ;
if ( V_30 )
V_17 -> V_34 [ V_35 ] |= 0x10 ;
else
V_17 -> V_34 [ V_35 ] &= ~ 0x10 ;
F_8 ( V_2 , V_26 , V_36 ,
V_17 -> V_34 [ V_36 ] ) ;
F_8 ( V_2 , V_26 , V_35 ,
V_17 -> V_34 [ V_35 ] ) ;
F_9 ( V_2 , V_26 , V_37 ,
V_17 -> V_33 ) ;
}
static void F_13 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
int V_26 = F_6 ( V_12 -> V_27 ) -> V_21 ;
const struct V_38 * V_39 = V_12 -> V_40 ;
V_39 -> F_11 ( V_12 , V_41 ) ;
F_14 ( V_2 , V_26 ) ;
if ( F_15 ( V_2 ) )
F_12 ( V_2 , V_26 ^ 1 , false ) ;
F_12 ( V_2 , V_26 , true ) ;
}
static void F_16 ( struct V_11 * V_12 ,
struct V_42 * V_13 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct F_6 * V_44 = F_6 ( V_12 -> V_27 ) ;
struct V_31 * V_45 = & F_4 ( V_2 ) -> V_18 . V_32 [ V_44 -> V_21 ] ;
V_45 -> V_46 = V_43 -> V_47 ;
V_45 -> V_48 = V_43 -> V_49 ;
V_45 -> V_50 = 1 ;
V_45 -> V_51 = 1 ;
V_45 -> V_52 = 64 ;
V_45 -> V_53 = 1 ;
V_45 -> V_54 = 1 ;
F_10 ( V_12 ) -> F_17 ( V_12 , V_13 , V_43 ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_14 * V_15 = V_14 ( V_12 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct F_6 * V_44 = F_6 ( V_12 -> V_27 ) ;
const struct V_38 * V_39 = V_12 -> V_40 ;
V_39 -> F_11 ( V_12 , V_25 ) ;
F_5 ( V_5 , L_3 ,
F_19 ( V_15 ) -> V_55 . V_56 ,
V_44 -> V_21 , '@' + F_20 ( V_15 -> V_20 -> V_57 ) ) ;
}
static void F_21 ( struct V_11 * V_12 )
{
F_10 ( V_12 ) -> F_22 ( V_12 ) ;
F_23 ( V_12 ) ;
F_24 ( V_12 -> V_40 ) ;
F_24 ( V_14 ( V_12 ) ) ;
}
int
F_25 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
struct V_14 * V_15 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_5 -> V_8 ) ;
struct V_62 * V_63 = V_7 -> V_64 ( V_7 , V_61 -> V_3 ) ;
int type , V_65 ;
type = F_1 ( V_2 , V_61 -> V_3 ) ;
if ( type < 0 )
return type ;
V_15 = F_26 ( sizeof( * V_15 ) , V_66 ) ;
if ( ! V_15 )
return - V_67 ;
V_12 = F_27 ( V_15 ) ;
F_28 ( V_2 , V_12 , & V_68 , V_69 ) ;
F_29 ( V_12 , & V_70 ) ;
V_12 -> V_71 = V_61 -> V_72 ;
V_12 -> V_73 = 0 ;
V_15 -> V_20 = V_61 ;
V_15 -> V_57 = F_20 ( V_61 -> V_57 ) - 1 ;
V_65 = F_30 ( V_2 , F_31 ( V_12 ) ,
& V_63 -> V_74 ,
& V_10 [ type ] . V_2 ) ;
if ( V_65 < 0 )
goto V_75;
F_10 ( V_12 ) -> F_32 ( V_12 , V_59 ) ;
F_33 ( V_59 , V_12 ) ;
return 0 ;
V_75:
F_23 ( V_12 ) ;
F_24 ( V_15 ) ;
return V_65 ;
}
