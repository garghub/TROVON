static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 ,
V_3 + V_2 -> V_4 . V_6 * V_7 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
F_4 ( V_2 -> V_4 . V_5 ,
V_3 + V_2 -> V_4 . V_6 * V_7 , V_8 ) ;
}
static int F_5 ( struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_12 * V_13 =
F_7 ( & V_2 -> V_4 . V_10 . V_4 ) ;
struct V_14 * V_5 = V_2 -> V_4 . V_5 ;
const struct V_15 * V_16 = & V_2 -> V_16 ;
unsigned int V_17 ;
T_1 V_18 = 0 ;
T_1 V_19 = 0 ;
if ( ! V_11 ) {
F_4 ( V_5 , F_8 ( V_2 -> V_4 . V_6 ) , 0 ) ;
return 0 ;
}
for ( V_17 = 0 ; V_17 < V_13 -> V_20 ; ++ V_17 ) {
struct V_1 * V_21 = V_13 -> V_22 [ V_17 ] ;
V_18 |= F_9 ( V_21 -> V_4 . V_6 ) ;
}
F_3 ( V_2 , V_23 , V_18 ) ;
if ( ! V_13 -> V_24 ) {
struct V_25 * V_26 = & V_2 -> V_27 . V_26 ;
F_3 ( V_2 , V_28 ,
V_26 -> V_29 [ 0 ] . V_30 ) ;
if ( V_26 -> V_31 > 1 )
F_3 ( V_2 , V_32 ,
V_26 -> V_29 [ 1 ] . V_30 ) ;
}
F_3 ( V_2 , V_33 , V_34 |
( V_16 -> V_35 << V_36 ) |
( V_16 -> V_37 << V_38 ) ) ;
F_3 ( V_2 , V_39 , V_34 |
( V_16 -> V_40 << V_36 ) |
( V_16 -> V_41 << V_38 ) ) ;
if ( ! V_13 -> V_24 ) {
const struct V_42 * V_43 = V_2 -> V_27 . V_43 ;
V_19 = V_43 -> V_44 << V_45 ;
if ( V_43 -> V_46 )
V_19 |= V_47 ;
if ( V_43 -> V_48 )
V_19 |= V_49 ;
F_3 ( V_2 , V_50 , V_43 -> V_51 ) ;
}
if ( V_2 -> V_4 . V_52 [ V_53 ] . V_54 !=
V_2 -> V_4 . V_52 [ V_55 ] . V_54 )
V_19 |= V_56 ;
F_3 ( V_2 , V_57 , V_19 ) ;
F_4 ( V_5 , F_10 ( V_2 -> V_4 . V_6 ) ,
V_58 ) ;
F_4 ( V_5 , V_59 , 0 ) ;
F_4 ( V_5 , F_11 ( V_2 -> V_4 . V_6 ) , 0 ) ;
F_4 ( V_5 , F_8 ( V_2 -> V_4 . V_6 ) ,
V_60 ) ;
return 0 ;
}
static void F_12 ( struct V_61 * V_27 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_13 ( V_27 , struct V_1 , V_27 ) ;
F_3 ( V_2 , V_64 , V_63 -> V_65 [ 0 ] ) ;
if ( V_63 -> V_63 . V_31 > 1 )
F_3 ( V_2 , V_66 , V_63 -> V_65 [ 1 ] ) ;
if ( V_63 -> V_63 . V_31 > 2 )
F_3 ( V_2 , V_67 , V_63 -> V_65 [ 2 ] ) ;
}
struct V_1 * F_14 ( struct V_14 * V_5 , unsigned int V_6 )
{
struct V_9 * V_10 ;
struct V_61 * V_27 ;
struct V_1 * V_2 ;
unsigned int V_68 ;
int V_69 ;
V_2 = F_15 ( V_5 -> V_70 , sizeof( * V_2 ) , V_71 ) ;
if ( V_2 == NULL )
return F_16 ( - V_72 ) ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_4 . type = V_77 ;
V_2 -> V_4 . V_6 = V_6 ;
V_2 -> V_4 . V_78 = F_17 ( V_6 ) ;
V_69 = F_18 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_69 < 0 )
return F_16 ( V_69 ) ;
V_10 = & V_2 -> V_4 . V_10 ;
F_19 ( V_10 , & V_79 ) ;
V_10 -> V_4 . V_80 = & V_81 ;
V_10 -> V_82 = & V_83 ;
snprintf ( V_10 -> V_84 , sizeof( V_10 -> V_84 ) , L_1 ,
F_20 ( V_5 -> V_70 ) , V_6 ) ;
F_21 ( V_10 , V_2 ) ;
V_10 -> V_68 |= V_85 ;
F_22 ( V_10 , NULL ) ;
V_27 = & V_2 -> V_27 ;
V_27 -> type = V_86 ;
V_27 -> V_5 = V_5 ;
V_27 -> V_80 = & V_87 ;
V_69 = F_23 ( V_27 , & V_2 -> V_4 ) ;
if ( V_69 < 0 )
goto V_88;
V_68 = V_89 ;
if ( ! ( V_5 -> V_90 -> V_91 & V_92 ) || V_6 != 0 )
V_68 |= V_93 ;
V_69 = F_24 ( & V_2 -> V_4 . V_10 . V_4 ,
V_55 ,
& V_2 -> V_27 . V_27 . V_4 , 0 , V_68 ) ;
if ( V_69 < 0 )
goto V_94;
V_2 -> V_4 . V_95 = & V_2 -> V_27 . V_27 . V_4 ;
return V_2 ;
V_94:
F_25 ( V_27 ) ;
V_88:
F_26 ( & V_2 -> V_4 . V_10 . V_4 ) ;
return F_16 ( V_69 ) ;
}
