int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_5 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_3 ) ;
if ( V_10 ) {
return F_4 ( V_10 , L_1 ,
V_11 ,
NULL , NULL ) ;
}
return - V_12 ;
}
static void F_5 ( struct V_13 * V_14 , int V_15 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_16 * V_17 = V_16 ( V_14 ) ;
struct V_18 * V_19 = & F_6 ( V_2 ) -> V_20 ;
T_1 V_21 ;
F_7 ( V_5 , L_2 ,
V_15 , V_17 -> V_22 -> V_23 ) ;
V_19 -> V_24 &= ~ ( V_25 | V_26 ) ;
if ( V_15 == V_27 ) {
int V_28 = F_8 ( V_14 -> V_29 ) -> V_23 ;
V_21 = F_9 ( V_2 , V_28 , V_30 ) ;
V_19 -> V_24 |= V_28 ? V_26 :
V_25 ;
V_21 |= 0x80 ;
F_10 ( V_2 , V_28 , V_30 , V_21 ) ;
}
F_11 ( V_2 , 0 , V_31 , V_19 -> V_24 ) ;
F_12 ( V_14 ) -> F_13 ( V_14 , V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_28 , bool V_32 )
{
struct V_33 * V_19 = & F_6 ( V_2 ) -> V_20 . V_34 [ V_28 ] ;
V_19 -> V_35 = 0 ;
if ( V_32 )
V_19 -> V_36 [ V_37 ] |= 0x10 ;
else
V_19 -> V_36 [ V_37 ] &= ~ 0x10 ;
F_10 ( V_2 , V_28 , V_38 ,
V_19 -> V_36 [ V_38 ] ) ;
F_10 ( V_2 , V_28 , V_37 ,
V_19 -> V_36 [ V_37 ] ) ;
F_11 ( V_2 , V_28 , V_39 ,
V_19 -> V_35 ) ;
}
static void F_15 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
int V_28 = F_8 ( V_14 -> V_29 ) -> V_23 ;
const struct V_40 * V_41 = V_14 -> V_42 ;
V_41 -> F_13 ( V_14 , V_43 ) ;
F_16 ( V_2 , V_28 ) ;
if ( F_17 ( V_2 ) )
F_14 ( V_2 , V_28 ^ 1 , false ) ;
F_14 ( V_2 , V_28 , true ) ;
}
static void F_18 ( struct V_13 * V_14 ,
struct V_44 * V_15 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct F_8 * V_46 = F_8 ( V_14 -> V_29 ) ;
struct V_33 * V_47 = & F_6 ( V_2 ) -> V_20 . V_34 [ V_46 -> V_23 ] ;
V_47 -> V_48 = V_45 -> V_49 ;
V_47 -> V_50 = V_45 -> V_51 ;
V_47 -> V_52 = 1 ;
V_47 -> V_53 = 1 ;
V_47 -> V_54 = 64 ;
V_47 -> V_55 = 1 ;
V_47 -> V_56 = 1 ;
F_12 ( V_14 ) -> F_19 ( V_14 , V_15 , V_45 ) ;
}
static void F_20 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = V_16 ( V_14 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct F_8 * V_46 = F_8 ( V_14 -> V_29 ) ;
const struct V_40 * V_41 = V_14 -> V_42 ;
V_41 -> F_13 ( V_14 , V_27 ) ;
F_7 ( V_5 , L_3 ,
F_21 ( V_17 ) -> V_57 . V_58 ,
V_46 -> V_23 , '@' + F_22 ( V_17 -> V_22 -> V_59 ) ) ;
}
static void F_23 ( struct V_13 * V_14 )
{
F_12 ( V_14 ) -> F_24 ( V_14 ) ;
F_25 ( V_14 ) ;
F_26 ( V_14 -> V_42 ) ;
F_26 ( V_16 ( V_14 ) ) ;
}
int
F_27 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_16 * V_17 ;
struct V_13 * V_14 ;
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_5 -> V_8 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_63 -> V_3 ) ;
int type , V_64 ;
type = F_1 ( V_2 , V_63 -> V_3 ) ;
if ( type < 0 )
return type ;
V_17 = F_28 ( sizeof( * V_17 ) , V_65 ) ;
if ( ! V_17 )
return - V_66 ;
V_14 = F_29 ( V_17 ) ;
F_30 ( V_2 , V_14 , & V_67 , V_68 ,
NULL ) ;
F_31 ( V_14 , & V_69 ) ;
V_17 -> V_70 = V_71 ;
V_17 -> V_72 = V_73 ;
V_14 -> V_74 = V_63 -> V_75 ;
V_14 -> V_76 = 0 ;
V_17 -> V_22 = V_63 ;
V_17 -> V_59 = F_22 ( V_63 -> V_59 ) - 1 ;
V_64 = F_32 ( V_2 , F_33 ( V_14 ) ,
& V_10 -> V_7 ,
& V_11 [ type ] . V_2 ) ;
if ( V_64 < 0 )
goto V_77;
F_12 ( V_14 ) -> F_34 ( V_14 , V_61 ) ;
F_35 ( V_61 , V_14 ) ;
return 0 ;
V_77:
F_25 ( V_14 ) ;
F_26 ( V_17 ) ;
return V_64 ;
}
