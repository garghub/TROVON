int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_5 -> V_8 . V_9 ) ;
struct V_10 * V_11 = F_3 ( V_7 , V_3 ) ;
if ( V_11 ) {
return F_4 ( V_11 , L_1 ,
V_12 ,
NULL , NULL ) ;
}
return - V_13 ;
}
static void F_5 ( struct V_14 * V_15 , int V_16 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_17 * V_18 = V_17 ( V_15 ) ;
struct V_19 * V_20 = & F_6 ( V_2 ) -> V_21 ;
T_1 V_22 ;
F_7 ( V_5 , L_2 ,
V_16 , V_18 -> V_23 -> V_24 ) ;
V_20 -> V_25 &= ~ ( V_26 | V_27 ) ;
if ( V_16 == V_28 ) {
int V_29 = F_8 ( V_15 -> V_30 ) -> V_24 ;
V_22 = F_9 ( V_2 , V_29 , V_31 ) ;
V_20 -> V_25 |= V_29 ? V_27 :
V_26 ;
V_22 |= 0x80 ;
F_10 ( V_2 , V_29 , V_31 , V_22 ) ;
}
F_11 ( V_2 , 0 , V_32 , V_20 -> V_25 ) ;
F_12 ( V_15 ) -> F_13 ( V_15 , V_16 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_29 , bool V_33 )
{
struct V_34 * V_20 = & F_6 ( V_2 ) -> V_21 . V_35 [ V_29 ] ;
V_20 -> V_36 = 0 ;
if ( V_33 )
V_20 -> V_37 [ V_38 ] |= 0x10 ;
else
V_20 -> V_37 [ V_38 ] &= ~ 0x10 ;
F_10 ( V_2 , V_29 , V_39 ,
V_20 -> V_37 [ V_39 ] ) ;
F_10 ( V_2 , V_29 , V_38 ,
V_20 -> V_37 [ V_38 ] ) ;
F_11 ( V_2 , V_29 , V_40 ,
V_20 -> V_36 ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
int V_29 = F_8 ( V_15 -> V_30 ) -> V_24 ;
const struct V_41 * V_42 = V_15 -> V_43 ;
V_42 -> F_13 ( V_15 , V_44 ) ;
F_16 ( V_2 , V_29 ) ;
if ( F_17 ( V_2 ) )
F_14 ( V_2 , V_29 ^ 1 , false ) ;
F_14 ( V_2 , V_29 , true ) ;
}
static void F_18 ( struct V_14 * V_15 ,
struct V_45 * V_16 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct F_8 * V_47 = F_8 ( V_15 -> V_30 ) ;
struct V_34 * V_48 = & F_6 ( V_2 ) -> V_21 . V_35 [ V_47 -> V_24 ] ;
V_48 -> V_49 = V_46 -> V_50 ;
V_48 -> V_51 = V_46 -> V_52 ;
V_48 -> V_53 = 1 ;
V_48 -> V_54 = 1 ;
V_48 -> V_55 = 64 ;
V_48 -> V_56 = 1 ;
V_48 -> V_57 = 1 ;
F_12 ( V_15 ) -> F_19 ( V_15 , V_16 , V_46 ) ;
}
static void F_20 ( struct V_14 * V_15 )
{
struct V_17 * V_18 = V_17 ( V_15 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct F_8 * V_47 = F_8 ( V_15 -> V_30 ) ;
const struct V_41 * V_42 = V_15 -> V_43 ;
V_42 -> F_13 ( V_15 , V_28 ) ;
F_7 ( V_5 , L_3 ,
F_21 ( V_18 ) -> V_58 . V_59 ,
V_47 -> V_24 , '@' + F_22 ( V_18 -> V_23 -> V_60 ) ) ;
}
static void F_23 ( struct V_14 * V_15 )
{
F_12 ( V_15 ) -> F_24 ( V_15 ) ;
F_25 ( V_15 ) ;
F_26 ( V_15 -> V_43 ) ;
F_26 ( V_17 ( V_15 ) ) ;
}
int
F_27 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_17 * V_18 ;
struct V_14 * V_15 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = F_2 ( & V_5 -> V_8 . V_9 ) ;
struct V_10 * V_11 = F_3 ( V_7 , V_64 -> V_3 ) ;
int type , V_65 ;
type = F_1 ( V_2 , V_64 -> V_3 ) ;
if ( type < 0 )
return type ;
V_18 = F_28 ( sizeof( * V_18 ) , V_66 ) ;
if ( ! V_18 )
return - V_67 ;
V_15 = F_29 ( V_18 ) ;
F_30 ( V_2 , V_15 , & V_68 , V_69 ,
NULL ) ;
F_31 ( V_15 , & V_70 ) ;
V_18 -> V_71 = V_72 ;
V_18 -> V_73 = V_74 ;
V_15 -> V_75 = V_64 -> V_76 ;
V_15 -> V_77 = 0 ;
V_18 -> V_23 = V_64 ;
V_18 -> V_60 = F_22 ( V_64 -> V_60 ) - 1 ;
V_65 = F_32 ( V_2 , F_33 ( V_15 ) ,
& V_11 -> V_7 ,
& V_12 [ type ] . V_2 ) ;
if ( V_65 < 0 )
goto V_78;
F_12 ( V_15 ) -> F_34 ( V_15 , V_62 ) ;
F_35 ( V_62 , V_15 ) ;
return 0 ;
V_78:
F_25 ( V_15 ) ;
F_26 ( V_18 ) ;
return V_65 ;
}
