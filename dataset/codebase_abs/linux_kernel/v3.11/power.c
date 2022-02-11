static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_6 , V_7 ,
sizeof( struct V_3 ) , V_4 ) ;
if ( ! V_5 ) {
F_3 ( V_2 , L_1 ,
V_4 -> V_8 ) ;
F_3 ( V_2 , L_2 ,
V_4 -> V_9 ) ;
F_3 ( V_2 , L_3 ,
V_4 -> V_10 ) ;
F_3 ( V_2 , L_4 ,
V_4 -> V_11 ) ;
F_3 ( V_2 , L_5 ,
V_4 -> V_12 ) ;
F_3 ( V_2 , L_6 ,
V_4 -> V_13 ) ;
F_3 ( V_2 , L_7 ,
V_4 -> V_14 ) ;
F_3 ( V_2 , L_8 ,
V_4 -> V_15 ) ;
F_3 ( V_2 , L_9 ,
V_4 -> V_16 ) ;
}
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_17 * V_18 , bool V_19 )
{
struct V_20 * V_21 = F_5 ( V_18 ) ;
struct V_3 V_4 = {
V_22 ,
. V_11 = 1 ,
. V_8 = V_19 ,
} ;
if ( ! V_21 -> V_23 )
return 0 ;
F_6 ( V_18 , & V_4 ) ;
return F_1 ( V_2 , & V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_24 * V_4 )
{
F_3 ( V_2 ,
L_10 ,
V_25 . V_26 ,
F_8 ( V_4 -> V_27 ) ) ;
F_3 ( V_2 , L_11 , V_4 -> V_28 ) ;
if ( V_4 -> V_27 & F_9 ( V_29 ) ) {
F_3 ( V_2 , L_12 ,
F_10 ( V_4 -> V_30 ) ) ;
F_3 ( V_2 , L_13 ,
F_10 ( V_4 -> V_31 ) ) ;
if ( V_4 -> V_27 & F_9 ( V_32 ) )
F_3 ( V_2 , L_14 ,
F_10 ( V_4 -> V_33 ) ) ;
if ( V_4 -> V_27 & F_9 ( V_34 ) )
F_3 ( V_2 , L_15 ,
F_10 ( V_4 -> V_35 ) ) ;
}
}
void F_11 ( struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_24 * V_4 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
int V_42 , V_43 ;
int V_44 ;
bool V_45 = false ;
struct V_20 * V_21 V_46 =
F_5 ( V_18 ) ;
V_4 -> V_28 = V_47 ;
if ( V_25 . V_26 == V_48 )
return;
V_4 -> V_27 |= F_9 ( V_49 ) ;
if ( ! V_18 -> V_50 . V_51 )
V_4 -> V_27 |= F_9 ( V_29 ) ;
#ifdef F_12
if ( V_21 -> V_52 . V_53 & V_54 &&
V_21 -> V_52 . V_55 )
V_4 -> V_27 &= F_9 ( ~ V_49 ) ;
#endif
if ( ! V_18 -> V_50 . V_56 )
return;
V_4 -> V_27 |= F_9 ( V_29 ) ;
if ( V_18 -> V_50 . V_57 &&
( V_18 -> V_50 . V_57 -> V_58 == 10 ||
V_18 -> V_50 . V_57 -> V_58 == 60 ) ) {
V_4 -> V_27 |= F_9 ( V_34 ) ;
V_4 -> V_35 =
F_13 ( V_59 ) ;
}
V_42 = V_37 -> V_60 . V_61 ? : 1 ;
F_14 () ;
V_39 = F_15 ( V_18 -> V_39 ) ;
F_16 ( ! V_39 ) ;
if ( V_39 ) {
V_41 = V_39 -> V_62 . V_41 ;
V_45 = V_41 -> V_27 & V_63 ;
}
F_17 () ;
if ( ! V_45 && ( V_42 <= 10 ) &&
( V_25 . V_26 == V_64 ||
V_2 -> V_65 == V_66 ) ) {
V_4 -> V_27 |= F_9 ( V_32 ) ;
V_4 -> V_33 = F_13 ( 3 ) ;
}
V_43 = V_42 * V_18 -> V_50 . V_67 ;
V_44 = F_18 ( int , 3 * V_43 ,
V_68 * V_4 -> V_28 ) ;
V_44 = F_19 ( V_44 , V_68 ) ;
V_4 -> V_28 = V_44 ;
if ( V_2 -> V_65 != V_66 ) {
V_4 -> V_30 = F_13 ( 100 * V_69 ) ;
V_4 -> V_31 = F_13 ( 100 * V_69 ) ;
} else {
V_4 -> V_30 = F_13 ( 10 * V_69 ) ;
V_4 -> V_31 = F_13 ( 10 * V_69 ) ;
}
#ifdef F_12
if ( V_21 -> V_52 . V_53 & V_70 )
V_4 -> V_28 = V_21 -> V_52 . V_28 ;
if ( V_21 -> V_52 . V_53 & V_71 ) {
if ( V_21 -> V_52 . V_72 )
V_4 -> V_27 |=
F_9 ( V_32 ) ;
else
V_4 -> V_27 &=
F_9 ( ~ V_32 ) ;
}
if ( V_21 -> V_52 . V_53 & V_73 )
V_4 -> V_30 =
F_13 ( V_21 -> V_52 . V_30 ) ;
if ( V_21 -> V_52 . V_53 & V_74 )
V_4 -> V_31 =
F_13 ( V_21 -> V_52 . V_31 ) ;
if ( V_21 -> V_52 . V_53 & V_75 )
V_4 -> V_33 =
F_13 ( V_21 -> V_52 . V_33 ) ;
if ( V_21 -> V_52 . V_53 & V_76 ) {
if ( V_21 -> V_52 . V_77 )
V_4 -> V_27 |= F_9 ( V_34 ) ;
else
V_4 -> V_27 &= F_9 ( ~ V_34 ) ;
}
if ( V_21 -> V_52 . V_53 & V_78 )
V_4 -> V_35 =
F_13 ( V_21 -> V_52 . V_35 ) ;
#endif
}
int F_20 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_5 ;
bool V_79 ;
struct V_24 V_4 = {} ;
if ( V_18 -> type != V_80 || V_18 -> V_81 )
return 0 ;
F_3 ( V_2 , L_16 ,
V_2 -> V_82 ) ;
if ( V_2 -> V_82 > 1 )
return 0 ;
F_11 ( V_2 , V_18 , & V_4 ) ;
F_7 ( V_2 , & V_4 ) ;
V_5 = F_2 ( V_2 , V_83 , V_7 ,
sizeof( V_4 ) , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_79 = ! ! ( V_4 . V_27 &
F_9 ( V_29 ) ) ;
return F_4 ( V_2 , V_18 , V_79 ) ;
}
int F_21 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_24 V_4 = {} ;
struct V_20 * V_21 V_46 =
F_5 ( V_18 ) ;
if ( V_18 -> type != V_80 || V_18 -> V_81 )
return 0 ;
if ( V_25 . V_26 != V_48 )
V_4 . V_27 |= F_9 ( V_49 ) ;
#ifdef F_12
if ( V_21 -> V_52 . V_53 & V_54 &&
V_21 -> V_52 . V_55 )
V_4 . V_27 &= F_9 ( ~ V_49 ) ;
#endif
F_7 ( V_2 , & V_4 ) ;
return F_2 ( V_2 , V_83 , V_84 ,
sizeof( V_4 ) , & V_4 ) ;
}
void
F_6 ( struct V_17 * V_18 ,
struct V_3 * V_4 )
{
struct V_20 * V_21 = F_5 ( V_18 ) ;
struct V_85 * V_86 = & V_21 -> V_86 ;
if ( V_86 -> V_53 & V_87 )
V_4 -> V_12 = V_86 -> V_12 ;
if ( V_86 -> V_53 & V_88 )
V_4 -> V_14 =
V_86 -> V_14 ;
if ( V_86 -> V_53 & V_89 )
V_4 -> V_15 = V_86 -> V_15 ;
if ( V_86 -> V_53 & V_90 )
V_4 -> V_16 = V_86 -> V_16 ;
if ( V_86 -> V_53 & V_91 )
V_4 -> V_10 = V_86 -> V_10 ;
if ( V_86 -> V_53 & V_92 )
V_4 -> V_13 = F_13 ( V_86 -> V_13 ) ;
if ( V_86 -> V_53 & V_93 )
V_4 -> V_9 = F_13 ( V_86 -> V_9 ) ;
if ( V_86 -> V_53 & V_94 )
V_4 -> V_8 = V_86 -> V_8 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_20 * V_21 = F_5 ( V_18 ) ;
struct V_3 V_4 = {
V_22 ,
. V_11 = 1 ,
} ;
int V_5 ;
if ( V_21 != V_2 -> V_95 ||
V_18 -> type != V_80 || V_18 -> V_81 )
return 0 ;
F_6 ( V_18 , & V_4 ) ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( ! V_5 )
V_21 -> V_23 = true ;
return V_5 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_3 V_4 = {} ;
struct V_20 * V_21 = F_5 ( V_18 ) ;
int V_5 ;
if ( V_18 -> type != V_80 || V_18 -> V_81 )
return 0 ;
V_5 = F_1 ( V_2 , & V_4 ) ;
if ( ! V_5 )
V_21 -> V_23 = false ;
return V_5 ;
}
