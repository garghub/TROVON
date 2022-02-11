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
const struct V_15 * V_16 =
& V_2 -> V_4 . V_17 [ V_18 ] ;
unsigned int V_19 ;
T_1 V_20 = 0 ;
T_1 V_21 = 0 ;
if ( ! V_11 ) {
F_4 ( V_5 , F_8 ( V_2 -> V_4 . V_6 ) , 0 ) ;
return 0 ;
}
for ( V_19 = 0 ; V_19 < V_13 -> V_22 ; ++ V_19 ) {
struct V_1 * V_23 = V_13 -> V_24 [ V_19 ] ;
V_20 |= F_9 ( V_23 -> V_4 . V_6 ) ;
}
F_3 ( V_2 , V_25 , V_20 ) ;
if ( ! V_13 -> V_26 ) {
struct V_27 * V_16 = & V_2 -> V_28 . V_16 ;
F_3 ( V_2 , V_29 ,
V_16 -> V_30 [ 0 ] . V_31 ) ;
if ( V_16 -> V_32 > 1 )
F_3 ( V_2 , V_33 ,
V_16 -> V_30 [ 1 ] . V_31 ) ;
}
F_3 ( V_2 , V_34 ,
V_16 -> V_35 << V_36 ) ;
F_3 ( V_2 , V_37 ,
V_16 -> V_38 << V_36 ) ;
if ( ! V_13 -> V_26 ) {
const struct V_39 * V_40 = V_2 -> V_28 . V_40 ;
V_21 = V_40 -> V_41 << V_42 ;
if ( V_40 -> V_43 )
V_21 |= V_44 ;
if ( V_40 -> V_45 )
V_21 |= V_46 ;
F_3 ( V_2 , V_47 , V_40 -> V_48 ) ;
}
if ( V_2 -> V_4 . V_17 [ V_49 ] . V_50 !=
V_2 -> V_4 . V_17 [ V_18 ] . V_50 )
V_21 |= V_51 ;
F_3 ( V_2 , V_52 , V_21 ) ;
F_4 ( V_5 , F_10 ( V_2 -> V_4 . V_6 ) ,
V_53 ) ;
F_4 ( V_5 , V_54 , 0 ) ;
F_4 ( V_5 , F_11 ( V_2 -> V_4 . V_6 ) , 0 ) ;
F_4 ( V_5 , F_8 ( V_2 -> V_4 . V_6 ) ,
V_55 ) ;
return 0 ;
}
static void F_12 ( struct V_56 * V_28 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_13 ( V_28 , struct V_1 , V_28 ) ;
F_3 ( V_2 , V_59 , V_58 -> V_60 [ 0 ] ) ;
if ( V_58 -> V_58 . V_32 > 1 )
F_3 ( V_2 , V_61 , V_58 -> V_60 [ 1 ] ) ;
if ( V_58 -> V_58 . V_32 > 2 )
F_3 ( V_2 , V_62 , V_58 -> V_60 [ 2 ] ) ;
}
struct V_1 * F_14 ( struct V_14 * V_5 , unsigned int V_6 )
{
struct V_9 * V_10 ;
struct V_56 * V_28 ;
struct V_1 * V_2 ;
unsigned int V_63 ;
int V_64 ;
V_2 = F_15 ( V_5 -> V_65 , sizeof( * V_2 ) , V_66 ) ;
if ( V_2 == NULL )
return F_16 ( - V_67 ) ;
V_2 -> V_68 = V_69 ;
V_2 -> V_70 = V_71 ;
V_2 -> V_4 . type = V_72 ;
V_2 -> V_4 . V_6 = V_6 ;
V_2 -> V_4 . V_73 = F_17 ( V_6 ) ;
V_64 = F_18 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_64 < 0 )
return F_16 ( V_64 ) ;
V_10 = & V_2 -> V_4 . V_10 ;
F_19 ( V_10 , & V_74 ) ;
V_10 -> V_4 . V_75 = & V_76 ;
V_10 -> V_77 = & V_78 ;
snprintf ( V_10 -> V_79 , sizeof( V_10 -> V_79 ) , L_1 ,
F_20 ( V_5 -> V_65 ) , V_6 ) ;
F_21 ( V_10 , V_2 ) ;
V_10 -> V_63 |= V_80 ;
F_22 ( V_10 , NULL ) ;
V_28 = & V_2 -> V_28 ;
V_28 -> type = V_81 ;
V_28 -> V_5 = V_5 ;
V_28 -> V_75 = & V_82 ;
V_64 = F_23 ( V_28 , & V_2 -> V_4 ) ;
if ( V_64 < 0 )
goto V_83;
V_63 = V_84 ;
if ( ! ( V_5 -> V_85 -> V_86 & V_87 ) || V_6 != 0 )
V_63 |= V_88 ;
V_64 = F_24 ( & V_2 -> V_4 . V_10 . V_4 ,
V_18 ,
& V_2 -> V_28 . V_28 . V_4 , 0 , V_63 ) ;
if ( V_64 < 0 )
goto V_89;
V_2 -> V_4 . V_90 = & V_2 -> V_28 . V_28 . V_4 ;
return V_2 ;
V_89:
F_25 ( V_28 ) ;
V_83:
F_26 ( & V_2 -> V_4 . V_10 . V_4 ) ;
return F_16 ( V_64 ) ;
}
