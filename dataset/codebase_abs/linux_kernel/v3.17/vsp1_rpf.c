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
static int F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 =
F_6 ( V_10 -> V_11 , struct V_1 , V_12 ) ;
struct V_13 * V_14 ;
if ( ! F_7 ( & V_2 -> V_4 ) )
return 0 ;
switch ( V_10 -> V_15 ) {
case V_16 :
F_3 ( V_2 , V_17 ,
V_10 -> V_18 << V_19 ) ;
V_14 = F_8 ( & V_2 -> V_4 . V_20 . V_4 ) ;
F_9 ( V_14 , & V_2 -> V_4 , V_10 -> V_18 ) ;
break;
}
return 0 ;
}
static int F_10 ( struct V_21 * V_20 , int V_22 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
const struct V_23 * V_24 = V_2 -> V_25 . V_24 ;
const struct V_26 * V_27 = & V_2 -> V_25 . V_27 ;
const struct V_28 * V_29 = & V_2 -> V_29 ;
T_1 V_30 ;
T_1 V_31 ;
int V_32 ;
V_32 = F_12 ( & V_2 -> V_4 , V_22 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ! V_22 )
return 0 ;
F_3 ( V_2 , V_33 ,
( V_29 -> V_34 << V_35 ) |
( V_29 -> V_36 << V_37 ) ) ;
F_3 ( V_2 , V_38 ,
( V_29 -> V_34 << V_39 ) |
( V_29 -> V_36 << V_40 ) ) ;
V_2 -> V_41 [ 0 ] = V_29 -> V_42 * V_27 -> V_43 [ 0 ] . V_44
+ V_29 -> V_45 * V_24 -> V_46 [ 0 ] / 8 ;
V_30 = V_27 -> V_43 [ 0 ] . V_44
<< V_47 ;
if ( V_27 -> V_48 > 1 ) {
V_2 -> V_41 [ 1 ] = V_29 -> V_42 * V_27 -> V_43 [ 1 ] . V_44
+ V_29 -> V_45 * V_24 -> V_46 [ 1 ] / 8 ;
V_30 |= V_27 -> V_43 [ 1 ] . V_44
<< V_49 ;
}
F_3 ( V_2 , V_50 , V_30 ) ;
V_31 = V_51
| ( V_24 -> V_52 << V_53 ) ;
if ( V_24 -> V_54 )
V_31 |= V_55 ;
if ( V_24 -> V_56 )
V_31 |= V_57 ;
if ( V_2 -> V_4 . V_58 [ V_59 ] . V_60 !=
V_2 -> V_4 . V_58 [ V_61 ] . V_60 )
V_31 |= V_62 ;
F_3 ( V_2 , V_63 , V_31 ) ;
F_3 ( V_2 , V_64 , V_24 -> V_65 ) ;
F_3 ( V_2 , V_66 ,
( V_2 -> V_67 . V_45 << V_68 ) |
( V_2 -> V_67 . V_42 << V_69 ) ) ;
F_3 ( V_2 , V_70 , V_71 |
( V_24 -> V_72 ? V_73
: V_74 ) ) ;
F_3 ( V_2 , V_75 , 0 ) ;
F_3 ( V_2 , V_76 , 0 ) ;
return 0 ;
}
static void F_13 ( struct V_77 * V_25 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_6 ( V_25 , struct V_1 , V_25 ) ;
F_3 ( V_2 , V_80 ,
V_79 -> V_81 [ 0 ] + V_2 -> V_41 [ 0 ] ) ;
if ( V_79 -> V_79 . V_48 > 1 )
F_3 ( V_2 , V_82 ,
V_79 -> V_81 [ 1 ] + V_2 -> V_41 [ 1 ] ) ;
if ( V_79 -> V_79 . V_48 > 2 )
F_3 ( V_2 , V_83 ,
V_79 -> V_81 [ 2 ] + V_2 -> V_41 [ 1 ] ) ;
}
struct V_1 * F_14 ( struct V_84 * V_5 , unsigned int V_6 )
{
struct V_21 * V_20 ;
struct V_77 * V_25 ;
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_15 ( V_5 -> V_85 , sizeof( * V_2 ) , V_86 ) ;
if ( V_2 == NULL )
return F_16 ( - V_87 ) ;
V_2 -> V_88 = V_89 ;
V_2 -> V_90 = V_91 ;
V_2 -> V_4 . type = V_92 ;
V_2 -> V_4 . V_6 = V_6 ;
V_32 = F_17 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_32 < 0 )
return F_16 ( V_32 ) ;
V_20 = & V_2 -> V_4 . V_20 ;
F_18 ( V_20 , & V_93 ) ;
V_20 -> V_4 . V_94 = & V_95 ;
V_20 -> V_96 = & V_97 ;
snprintf ( V_20 -> V_98 , sizeof( V_20 -> V_98 ) , L_1 ,
F_19 ( V_5 -> V_85 ) , V_6 ) ;
F_20 ( V_20 , V_2 ) ;
V_20 -> V_99 |= V_100 ;
F_21 ( V_20 , NULL ) ;
F_22 ( & V_2 -> V_12 , 1 ) ;
F_23 ( & V_2 -> V_12 , & V_101 , V_16 ,
0 , 255 , 1 , 255 ) ;
V_2 -> V_4 . V_20 . V_102 = & V_2 -> V_12 ;
if ( V_2 -> V_12 . error ) {
F_24 ( V_5 -> V_85 , L_2 ,
V_6 ) ;
V_32 = V_2 -> V_12 . error ;
goto error;
}
V_25 = & V_2 -> V_25 ;
V_25 -> type = V_103 ;
V_25 -> V_5 = V_5 ;
V_25 -> V_94 = & V_104 ;
V_32 = F_25 ( V_25 , & V_2 -> V_4 ) ;
if ( V_32 < 0 )
goto error;
V_2 -> V_4 . V_25 = V_25 ;
V_32 = F_26 ( & V_2 -> V_25 . V_25 . V_4 , 0 ,
& V_2 -> V_4 . V_20 . V_4 ,
V_59 ,
V_105 |
V_106 ) ;
if ( V_32 < 0 )
goto error;
return V_2 ;
error:
F_27 ( & V_2 -> V_4 ) ;
return F_16 ( V_32 ) ;
}
