int F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 , L_1 , V_4 ,
NULL , V_3 ) ;
}
static void F_3 ( struct V_5 * V_6 , int V_7 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_8 * V_9 = V_8 ( V_6 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
T_1 V_16 ;
F_4 ( V_2 , L_2 ,
V_7 , V_9 -> V_17 -> V_18 ) ;
V_14 -> V_19 &= ~ ( V_20 | V_21 ) ;
if ( V_7 == V_22 ) {
int V_23 = F_5 ( V_6 -> V_24 ) -> V_18 ;
V_16 = F_6 ( V_2 , V_23 , V_25 ) ;
V_14 -> V_19 |= V_23 ? V_21 :
V_20 ;
V_16 |= 0x80 ;
F_7 ( V_2 , V_23 , V_25 , V_16 ) ;
}
F_8 ( V_2 , 0 , V_26 , V_14 -> V_19 ) ;
F_9 ( V_6 ) -> F_10 ( V_6 , V_7 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_23 , bool V_27 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_28 * V_14 = & V_11 -> V_15 . V_29 [ V_23 ] ;
V_14 -> V_30 = 0 ;
if ( V_27 )
V_14 -> V_31 [ V_32 ] |= 0x10 ;
else
V_14 -> V_31 [ V_32 ] &= ~ 0x10 ;
F_7 ( V_2 , V_23 , V_33 ,
V_14 -> V_31 [ V_33 ] ) ;
F_7 ( V_2 , V_23 , V_32 ,
V_14 -> V_31 [ V_32 ] ) ;
F_8 ( V_2 , V_23 , V_34 ,
V_14 -> V_30 ) ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
int V_23 = F_5 ( V_6 -> V_24 ) -> V_18 ;
struct V_35 * V_36 = V_6 -> V_37 ;
V_36 -> F_10 ( V_6 , V_38 ) ;
F_13 ( V_2 , V_23 ) ;
if ( F_14 ( V_2 ) )
F_11 ( V_2 , V_23 ^ 1 , false ) ;
F_11 ( V_2 , V_23 , true ) ;
}
static void F_15 ( struct V_5 * V_6 ,
struct V_39 * V_7 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct F_5 * V_41 = F_5 ( V_6 -> V_24 ) ;
struct V_28 * V_42 = & V_11 -> V_15 . V_29 [ V_41 -> V_18 ] ;
V_42 -> V_43 = V_40 -> V_44 ;
V_42 -> V_45 = V_40 -> V_46 ;
V_42 -> V_47 = 1 ;
V_42 -> V_48 = 1 ;
V_42 -> V_49 = 64 ;
V_42 -> V_50 = 1 ;
V_42 -> V_51 = 1 ;
F_9 ( V_6 ) -> F_16 ( V_6 , V_7 , V_40 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_8 ( V_6 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct F_5 * V_41 = F_5 ( V_6 -> V_24 ) ;
struct V_35 * V_36 = V_6 -> V_37 ;
V_36 -> F_10 ( V_6 , V_22 ) ;
F_4 ( V_2 , L_3 ,
F_18 ( & F_19 ( V_9 ) -> V_52 ) , V_41 -> V_18 ,
'@' + F_20 ( V_9 -> V_17 -> V_53 ) ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
F_9 ( V_6 ) -> F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
F_24 ( V_6 -> V_37 ) ;
F_24 ( V_8 ( V_6 ) ) ;
}
int
F_25 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
struct V_8 * V_9 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = V_55 -> V_2 ;
struct V_35 * V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 =
F_26 ( V_2 , V_57 -> V_3 ) ;
int type , V_63 ;
type = F_1 ( V_2 , V_57 -> V_3 ) ;
if ( type < 0 )
return type ;
V_9 = F_27 ( sizeof( * V_9 ) , V_64 ) ;
if ( ! V_9 )
return - V_65 ;
V_58 = F_27 ( sizeof( * V_58 ) , V_64 ) ;
if ( ! V_58 ) {
V_63 = - V_65 ;
goto V_66;
}
V_6 = F_28 ( V_9 ) ;
F_29 ( V_2 , V_6 , & V_67 , V_68 ) ;
F_30 ( V_6 , V_58 ) ;
V_6 -> V_69 = V_57 -> V_70 ;
V_6 -> V_71 = 0 ;
V_9 -> V_17 = V_57 ;
V_9 -> V_53 = F_20 ( V_57 -> V_53 ) - 1 ;
V_63 = F_31 ( V_2 , F_32 ( V_6 ) ,
& V_62 -> V_72 , & V_4 [ type ] ) ;
if ( V_63 < 0 )
goto V_73;
V_60 = F_9 ( V_6 ) ;
* V_58 = (struct V_35 ) {
. F_10 = F_3 ,
. V_74 = V_60 -> V_74 ,
. V_75 = V_60 -> V_75 ,
. V_76 = V_60 -> V_76 ,
. V_77 = F_12 ,
. V_78 = F_17 ,
. F_16 = F_15 ,
. V_79 = V_60 -> V_79 ,
} ;
V_60 -> V_80 ( V_6 , V_55 ) ;
F_33 ( V_55 , V_6 ) ;
return 0 ;
V_73:
F_23 ( V_6 ) ;
F_24 ( V_58 ) ;
V_66:
F_24 ( V_9 ) ;
return V_63 ;
}
