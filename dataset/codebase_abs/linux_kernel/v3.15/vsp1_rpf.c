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
const struct V_17 * V_18 = & V_2 -> V_18 ;
T_1 V_19 ;
T_1 V_20 ;
if ( ! V_11 )
return 0 ;
F_3 ( V_2 , V_21 ,
( V_18 -> V_22 << V_23 ) |
( V_18 -> V_24 << V_25 ) ) ;
F_3 ( V_2 , V_26 ,
( V_18 -> V_22 << V_27 ) |
( V_18 -> V_24 << V_28 ) ) ;
V_2 -> V_29 [ 0 ] = V_18 -> V_30 * V_16 -> V_31 [ 0 ] . V_32
+ V_18 -> V_33 * V_13 -> V_34 [ 0 ] / 8 ;
V_19 = V_16 -> V_31 [ 0 ] . V_32
<< V_35 ;
if ( V_16 -> V_36 > 1 ) {
V_2 -> V_29 [ 1 ] = V_18 -> V_30 * V_16 -> V_31 [ 1 ] . V_32
+ V_18 -> V_33 * V_13 -> V_34 [ 1 ] / 8 ;
V_19 |= V_16 -> V_31 [ 1 ] . V_32
<< V_37 ;
}
F_3 ( V_2 , V_38 , V_19 ) ;
V_20 = V_39
| ( V_13 -> V_40 << V_41 ) ;
if ( V_13 -> V_42 )
V_20 |= V_43 ;
if ( V_13 -> V_44 )
V_20 |= V_45 ;
if ( V_2 -> V_4 . V_46 [ V_47 ] . V_48 !=
V_2 -> V_4 . V_46 [ V_49 ] . V_48 )
V_20 |= V_50 ;
F_3 ( V_2 , V_51 , V_20 ) ;
F_3 ( V_2 , V_52 , V_13 -> V_53 ) ;
F_3 ( V_2 , V_54 , 0 ) ;
F_3 ( V_2 , V_55 , V_56 ) ;
F_3 ( V_2 , V_57 ,
255 << V_58 ) ;
F_3 ( V_2 , V_59 , 0 ) ;
F_3 ( V_2 , V_60 , 0 ) ;
return 0 ;
}
static void F_7 ( struct V_61 * V_14 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_8 ( V_14 , struct V_1 , V_14 ) ;
F_3 ( V_2 , V_64 ,
V_63 -> V_65 [ 0 ] + V_2 -> V_29 [ 0 ] ) ;
if ( V_63 -> V_63 . V_36 > 1 )
F_3 ( V_2 , V_66 ,
V_63 -> V_65 [ 1 ] + V_2 -> V_29 [ 1 ] ) ;
if ( V_63 -> V_63 . V_36 > 2 )
F_3 ( V_2 , V_67 ,
V_63 -> V_65 [ 2 ] + V_2 -> V_29 [ 1 ] ) ;
}
struct V_1 * F_9 ( struct V_68 * V_5 , unsigned int V_6 )
{
struct V_9 * V_10 ;
struct V_61 * V_14 ;
struct V_1 * V_2 ;
int V_69 ;
V_2 = F_10 ( V_5 -> V_70 , sizeof( * V_2 ) , V_71 ) ;
if ( V_2 == NULL )
return F_11 ( - V_72 ) ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_4 . type = V_77 ;
V_2 -> V_4 . V_6 = V_6 ;
V_2 -> V_4 . V_78 = F_12 ( V_6 ) ;
V_69 = F_13 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_69 < 0 )
return F_11 ( V_69 ) ;
V_10 = & V_2 -> V_4 . V_10 ;
F_14 ( V_10 , & V_79 ) ;
V_10 -> V_4 . V_80 = & V_81 ;
V_10 -> V_82 = & V_83 ;
snprintf ( V_10 -> V_84 , sizeof( V_10 -> V_84 ) , L_1 ,
F_15 ( V_5 -> V_70 ) , V_6 ) ;
F_16 ( V_10 , V_2 ) ;
V_10 -> V_85 |= V_86 ;
F_17 ( V_10 , NULL ) ;
V_14 = & V_2 -> V_14 ;
V_14 -> type = V_87 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_80 = & V_88 ;
V_69 = F_18 ( V_14 , & V_2 -> V_4 ) ;
if ( V_69 < 0 )
goto V_89;
V_69 = F_19 ( & V_2 -> V_14 . V_14 . V_4 , 0 ,
& V_2 -> V_4 . V_10 . V_4 ,
V_47 ,
V_90 |
V_91 ) ;
if ( V_69 < 0 )
goto V_92;
return V_2 ;
V_92:
F_20 ( V_14 ) ;
V_89:
F_21 ( & V_2 -> V_4 . V_10 . V_4 ) ;
return F_11 ( V_69 ) ;
}
