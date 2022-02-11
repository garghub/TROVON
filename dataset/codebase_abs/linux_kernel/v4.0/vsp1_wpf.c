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
T_1 V_13 ;
if ( ! F_7 ( & V_2 -> V_4 ) )
return 0 ;
switch ( V_10 -> V_14 ) {
case V_15 :
V_13 = F_1 ( V_2 , V_16 ) ;
V_13 &= ~ V_17 ;
V_13 |= V_10 -> V_18 << V_19 ;
F_3 ( V_2 , V_16 , V_13 ) ;
break;
}
return 0 ;
}
static int F_8 ( struct V_20 * V_21 , int V_22 )
{
struct V_23 * V_24 = F_9 ( & V_21 -> V_4 ) ;
struct V_1 * V_2 = F_10 ( V_21 ) ;
struct V_25 * V_5 = V_2 -> V_4 . V_5 ;
const struct V_26 * V_27 = & V_2 -> V_27 ;
unsigned int V_28 ;
T_1 V_29 = 0 ;
T_1 V_30 = 0 ;
int V_31 ;
V_31 = F_11 ( & V_2 -> V_4 , V_22 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( ! V_22 ) {
F_4 ( V_5 , F_12 ( V_2 -> V_4 . V_6 ) , 0 ) ;
F_3 ( V_2 , V_32 , 0 ) ;
return 0 ;
}
for ( V_28 = 0 ; V_28 < V_24 -> V_33 ; ++ V_28 ) {
struct V_1 * V_34 = V_24 -> V_35 [ V_28 ] ;
V_29 |= ( ! V_24 -> V_36 && V_24 -> V_33 == 1 )
? F_13 ( V_34 -> V_4 . V_6 )
: F_14 ( V_34 -> V_4 . V_6 ) ;
}
if ( V_24 -> V_36 || V_24 -> V_33 > 1 )
V_29 |= V_37 ;
F_3 ( V_2 , V_32 , V_29 ) ;
if ( ! V_24 -> V_38 ) {
struct V_39 * V_40 = & V_2 -> V_41 . V_40 ;
F_3 ( V_2 , V_42 ,
V_40 -> V_43 [ 0 ] . V_44 ) ;
if ( V_40 -> V_45 > 1 )
F_3 ( V_2 , V_46 ,
V_40 -> V_43 [ 1 ] . V_44 ) ;
}
F_3 ( V_2 , V_47 , V_48 |
( V_27 -> V_49 << V_50 ) |
( V_27 -> V_51 << V_52 ) ) ;
F_3 ( V_2 , V_53 , V_48 |
( V_27 -> V_54 << V_50 ) |
( V_27 -> V_55 << V_52 ) ) ;
if ( ! V_24 -> V_38 ) {
const struct V_56 * V_57 = V_2 -> V_41 . V_57 ;
V_30 = V_57 -> V_58 << V_59 ;
if ( V_57 -> V_60 )
V_30 |= V_61 ;
if ( V_57 -> V_62 )
V_30 |= V_63 ;
if ( V_57 -> V_64 )
V_30 |= V_65 ;
F_3 ( V_2 , V_66 , V_57 -> V_67 ) ;
}
if ( V_2 -> V_4 . V_68 [ V_69 ] . V_70 !=
V_2 -> V_4 . V_68 [ V_71 ] . V_70 )
V_30 |= V_72 ;
F_15 ( V_2 -> V_12 . V_73 ) ;
V_30 |= F_1 ( V_2 , V_16 ) & V_17 ;
F_3 ( V_2 , V_16 , V_30 ) ;
F_16 ( V_2 -> V_12 . V_73 ) ;
F_4 ( V_5 , F_17 ( V_2 -> V_4 . V_6 ) ,
V_74 ) ;
F_4 ( V_5 , V_75 , 0 ) ;
F_4 ( V_5 , F_18 ( V_2 -> V_4 . V_6 ) , 0 ) ;
F_4 ( V_5 , F_12 ( V_2 -> V_4 . V_6 ) ,
V_76 ) ;
return 0 ;
}
static void F_19 ( struct V_77 * V_41 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_6 ( V_41 , struct V_1 , V_41 ) ;
F_3 ( V_2 , V_80 , V_79 -> V_81 [ 0 ] ) ;
if ( V_79 -> V_79 . V_45 > 1 )
F_3 ( V_2 , V_82 , V_79 -> V_81 [ 1 ] ) ;
if ( V_79 -> V_79 . V_45 > 2 )
F_3 ( V_2 , V_83 , V_79 -> V_81 [ 2 ] ) ;
}
struct V_1 * F_20 ( struct V_25 * V_5 , unsigned int V_6 )
{
struct V_20 * V_21 ;
struct V_77 * V_41 ;
struct V_1 * V_2 ;
unsigned int V_84 ;
int V_31 ;
V_2 = F_21 ( V_5 -> V_85 , sizeof( * V_2 ) , V_86 ) ;
if ( V_2 == NULL )
return F_22 ( - V_87 ) ;
V_2 -> V_88 = V_89 ;
V_2 -> V_90 = V_91 ;
V_2 -> V_4 . type = V_92 ;
V_2 -> V_4 . V_6 = V_6 ;
V_31 = F_23 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_31 < 0 )
return F_22 ( V_31 ) ;
V_21 = & V_2 -> V_4 . V_21 ;
F_24 ( V_21 , & V_93 ) ;
V_21 -> V_4 . V_94 = & V_95 ;
V_21 -> V_96 = & V_97 ;
snprintf ( V_21 -> V_98 , sizeof( V_21 -> V_98 ) , L_1 ,
F_25 ( V_5 -> V_85 ) , V_6 ) ;
F_26 ( V_21 , V_2 ) ;
V_21 -> V_84 |= V_99 ;
F_27 ( V_21 , NULL ) ;
F_28 ( & V_2 -> V_12 , 1 ) ;
F_29 ( & V_2 -> V_12 , & V_100 , V_15 ,
0 , 255 , 1 , 255 ) ;
V_2 -> V_4 . V_21 . V_101 = & V_2 -> V_12 ;
if ( V_2 -> V_12 . error ) {
F_30 ( V_5 -> V_85 , L_2 ,
V_6 ) ;
V_31 = V_2 -> V_12 . error ;
goto error;
}
V_41 = & V_2 -> V_41 ;
V_41 -> type = V_102 ;
V_41 -> V_5 = V_5 ;
V_41 -> V_94 = & V_103 ;
V_31 = F_31 ( V_41 , & V_2 -> V_4 ) ;
if ( V_31 < 0 )
goto error;
V_2 -> V_4 . V_41 = V_41 ;
V_84 = V_104 ;
if ( ! ( V_5 -> V_105 . V_106 & V_107 ) || V_6 != 0 )
V_84 |= V_108 ;
V_31 = F_32 ( & V_2 -> V_4 . V_21 . V_4 ,
V_71 ,
& V_2 -> V_41 . V_41 . V_4 , 0 , V_84 ) ;
if ( V_31 < 0 )
goto error;
V_2 -> V_4 . V_109 = & V_2 -> V_41 . V_41 . V_4 ;
return V_2 ;
error:
F_33 ( & V_2 -> V_4 ) ;
return F_22 ( V_31 ) ;
}
