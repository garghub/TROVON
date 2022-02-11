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
const struct V_12 * V_13 = V_2 -> V_14 . V_13 ;
const struct V_15 * V_16 = & V_2 -> V_14 . V_16 ;
T_1 V_17 ;
T_1 V_18 ;
if ( ! V_11 )
return 0 ;
F_3 ( V_2 , V_19 ,
( V_16 -> V_20 << V_21 ) |
( V_16 -> V_22 << V_23 ) ) ;
F_3 ( V_2 , V_24 ,
( V_16 -> V_20 << V_25 ) |
( V_16 -> V_22 << V_26 ) ) ;
V_17 = V_16 -> V_27 [ 0 ] . V_28
<< V_29 ;
if ( V_16 -> V_30 > 1 )
V_17 |= V_16 -> V_27 [ 1 ] . V_28
<< V_31 ;
F_3 ( V_2 , V_32 , V_17 ) ;
V_18 = V_33
| ( V_13 -> V_34 << V_35 ) ;
if ( V_13 -> V_36 )
V_18 |= V_37 ;
if ( V_13 -> V_38 )
V_18 |= V_39 ;
if ( V_2 -> V_4 . V_40 [ V_41 ] . V_42 !=
V_2 -> V_4 . V_40 [ V_43 ] . V_42 )
V_18 |= V_44 ;
F_3 ( V_2 , V_45 , V_18 ) ;
F_3 ( V_2 , V_46 , V_13 -> V_47 ) ;
F_3 ( V_2 , V_48 , 0 ) ;
F_3 ( V_2 , V_49 , V_50 ) ;
F_3 ( V_2 , V_51 ,
255 << V_52 ) ;
F_3 ( V_2 , V_53 , 0 ) ;
F_3 ( V_2 , V_54 , 0 ) ;
return 0 ;
}
static void F_7 ( struct V_55 * V_14 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_8 ( V_14 , struct V_1 , V_14 ) ;
F_3 ( V_2 , V_58 , V_57 -> V_59 [ 0 ] ) ;
if ( V_57 -> V_57 . V_30 > 1 )
F_3 ( V_2 , V_60 , V_57 -> V_59 [ 1 ] ) ;
if ( V_57 -> V_57 . V_30 > 2 )
F_3 ( V_2 , V_61 , V_57 -> V_59 [ 2 ] ) ;
}
struct V_1 * F_9 ( struct V_62 * V_5 , unsigned int V_6 )
{
struct V_9 * V_10 ;
struct V_55 * V_14 ;
struct V_1 * V_2 ;
int V_63 ;
V_2 = F_10 ( V_5 -> V_64 , sizeof( * V_2 ) , V_65 ) ;
if ( V_2 == NULL )
return F_11 ( - V_66 ) ;
V_2 -> V_67 = V_68 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_4 . type = V_71 ;
V_2 -> V_4 . V_6 = V_6 ;
V_2 -> V_4 . V_72 = F_12 ( V_6 ) ;
V_63 = F_13 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_63 < 0 )
return F_11 ( V_63 ) ;
V_10 = & V_2 -> V_4 . V_10 ;
F_14 ( V_10 , & V_73 ) ;
V_10 -> V_4 . V_74 = & V_75 ;
V_10 -> V_76 = & V_77 ;
snprintf ( V_10 -> V_78 , sizeof( V_10 -> V_78 ) , L_1 ,
F_15 ( V_5 -> V_64 ) , V_6 ) ;
F_16 ( V_10 , V_2 ) ;
V_10 -> V_79 |= V_80 ;
F_17 ( V_10 , NULL ) ;
V_14 = & V_2 -> V_14 ;
V_14 -> type = V_81 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_74 = & V_82 ;
V_63 = F_18 ( V_14 , & V_2 -> V_4 ) ;
if ( V_63 < 0 )
goto V_83;
V_63 = F_19 ( & V_2 -> V_14 . V_14 . V_4 , 0 ,
& V_2 -> V_4 . V_10 . V_4 ,
V_41 ,
V_84 |
V_85 ) ;
if ( V_63 < 0 )
goto V_86;
return V_2 ;
V_86:
F_20 ( V_14 ) ;
V_83:
F_21 ( & V_2 -> V_4 . V_10 . V_4 ) ;
return F_11 ( V_63 ) ;
}
