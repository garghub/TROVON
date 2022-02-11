static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 ,
V_3 + V_2 -> V_4 . V_6 * V_7 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
F_4 ( & V_2 -> V_4 ,
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
F_12 ( V_5 , F_13 ( V_2 -> V_4 . V_6 ) , 0 ) ;
F_12 ( V_5 , V_2 -> V_4 . V_6 * V_7 +
V_32 , 0 ) ;
return 0 ;
}
for ( V_28 = 0 ; V_28 < V_5 -> V_33 -> V_34 ; ++ V_28 ) {
struct V_1 * V_35 = V_24 -> V_36 [ V_28 ] ;
if ( ! V_35 )
continue;
V_29 |= ( ! V_24 -> V_37 && V_24 -> V_38 == 1 )
? F_14 ( V_35 -> V_4 . V_6 )
: F_15 ( V_35 -> V_4 . V_6 ) ;
}
if ( V_24 -> V_37 || V_24 -> V_38 > 1 )
V_29 |= V_39 ;
F_3 ( V_2 , V_32 , V_29 ) ;
if ( ! V_24 -> V_40 ) {
struct V_41 * V_42 = & V_2 -> V_42 ;
F_3 ( V_2 , V_43 ,
V_42 -> V_44 [ 0 ] . V_45 ) ;
if ( V_42 -> V_46 > 1 )
F_3 ( V_2 , V_47 ,
V_42 -> V_44 [ 1 ] . V_45 ) ;
}
F_3 ( V_2 , V_48 , V_49 |
( V_27 -> V_50 << V_51 ) |
( V_27 -> V_52 << V_53 ) ) ;
F_3 ( V_2 , V_54 , V_49 |
( V_27 -> V_55 << V_51 ) |
( V_27 -> V_56 << V_53 ) ) ;
if ( ! V_24 -> V_40 ) {
const struct V_57 * V_58 = V_2 -> V_58 ;
V_30 = V_58 -> V_59 << V_60 ;
if ( V_58 -> V_61 )
V_30 |= V_62 ;
if ( V_58 -> V_63 )
V_30 |= V_64 ;
if ( V_58 -> V_65 )
V_30 |= V_66 ;
F_3 ( V_2 , V_67 , V_58 -> V_68 ) ;
}
if ( V_2 -> V_4 . V_69 [ V_70 ] . V_71 !=
V_2 -> V_4 . V_69 [ V_72 ] . V_71 )
V_30 |= V_73 ;
if ( V_5 -> V_33 -> V_74 )
F_16 ( V_2 -> V_12 . V_75 ) ;
V_30 |= V_2 -> V_61 -> V_76 . V_18 << V_19 ;
F_3 ( V_2 , V_16 , V_30 ) ;
if ( V_5 -> V_33 -> V_74 )
F_17 ( V_2 -> V_12 . V_75 ) ;
F_4 ( & V_2 -> V_4 , F_18 ( V_2 -> V_4 . V_6 ) ,
V_77 ) ;
F_4 ( & V_2 -> V_4 , V_78 , 0 ) ;
F_12 ( V_5 , F_19 ( V_2 -> V_4 . V_6 ) , 0 ) ;
F_12 ( V_5 , F_13 ( V_2 -> V_4 . V_6 ) ,
V_79 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
F_3 ( V_2 , V_82 , V_81 -> V_83 [ 0 ] ) ;
if ( V_81 -> V_46 > 1 )
F_3 ( V_2 , V_84 , V_81 -> V_83 [ 1 ] ) ;
if ( V_81 -> V_46 > 2 )
F_3 ( V_2 , V_85 , V_81 -> V_83 [ 2 ] ) ;
}
struct V_1 * F_21 ( struct V_25 * V_5 , unsigned int V_6 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_31 ;
V_2 = F_22 ( V_5 -> V_86 , sizeof( * V_2 ) , V_87 ) ;
if ( V_2 == NULL )
return F_23 ( - V_88 ) ;
V_2 -> V_89 = & V_90 ;
V_2 -> V_91 = V_92 ;
V_2 -> V_93 = V_94 ;
V_2 -> V_4 . type = V_95 ;
V_2 -> V_4 . V_6 = V_6 ;
V_31 = F_24 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_31 < 0 )
return F_23 ( V_31 ) ;
V_21 = & V_2 -> V_4 . V_21 ;
F_25 ( V_21 , & V_96 ) ;
V_21 -> V_4 . V_89 = & V_5 -> V_97 ;
V_21 -> V_98 = & V_99 ;
snprintf ( V_21 -> V_100 , sizeof( V_21 -> V_100 ) , L_1 ,
F_26 ( V_5 -> V_86 ) , V_6 ) ;
F_27 ( V_21 , V_2 ) ;
V_21 -> V_101 |= V_102 ;
F_28 ( V_21 , NULL ) ;
F_29 ( & V_2 -> V_12 , 1 ) ;
V_2 -> V_61 = F_30 ( & V_2 -> V_12 , & V_103 ,
V_15 ,
0 , 255 , 1 , 255 ) ;
V_2 -> V_4 . V_21 . V_104 = & V_2 -> V_12 ;
if ( V_2 -> V_12 . error ) {
F_31 ( V_5 -> V_86 , L_2 ,
V_6 ) ;
V_31 = V_2 -> V_12 . error ;
goto error;
}
return V_2 ;
error:
F_32 ( & V_2 -> V_4 ) ;
return F_23 ( V_31 ) ;
}
