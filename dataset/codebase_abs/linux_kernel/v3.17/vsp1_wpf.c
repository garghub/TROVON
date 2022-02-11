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
V_29 |= V_24 -> V_33 == 1
? F_13 ( V_34 -> V_4 . V_6 )
: F_14 ( V_34 -> V_4 . V_6 ) ;
}
if ( V_24 -> V_33 > 1 )
V_29 |= V_36 ;
F_3 ( V_2 , V_32 , V_29 ) ;
if ( ! V_24 -> V_37 ) {
struct V_38 * V_39 = & V_2 -> V_40 . V_39 ;
F_3 ( V_2 , V_41 ,
V_39 -> V_42 [ 0 ] . V_43 ) ;
if ( V_39 -> V_44 > 1 )
F_3 ( V_2 , V_45 ,
V_39 -> V_42 [ 1 ] . V_43 ) ;
}
F_3 ( V_2 , V_46 , V_47 |
( V_27 -> V_48 << V_49 ) |
( V_27 -> V_50 << V_51 ) ) ;
F_3 ( V_2 , V_52 , V_47 |
( V_27 -> V_53 << V_49 ) |
( V_27 -> V_54 << V_51 ) ) ;
if ( ! V_24 -> V_37 ) {
const struct V_55 * V_56 = V_2 -> V_40 . V_56 ;
V_30 = V_56 -> V_57 << V_58 ;
if ( V_56 -> V_59 )
V_30 |= V_60 ;
if ( V_56 -> V_61 )
V_30 |= V_62 ;
if ( V_56 -> V_63 )
V_30 |= V_64 ;
F_3 ( V_2 , V_65 , V_56 -> V_66 ) ;
}
if ( V_2 -> V_4 . V_67 [ V_68 ] . V_69 !=
V_2 -> V_4 . V_67 [ V_70 ] . V_69 )
V_30 |= V_71 ;
F_15 ( V_2 -> V_12 . V_72 ) ;
V_30 |= F_1 ( V_2 , V_16 ) & V_17 ;
F_3 ( V_2 , V_16 , V_30 ) ;
F_16 ( V_2 -> V_12 . V_72 ) ;
F_4 ( V_5 , F_17 ( V_2 -> V_4 . V_6 ) ,
V_73 ) ;
F_4 ( V_5 , V_74 , 0 ) ;
F_4 ( V_5 , F_18 ( V_2 -> V_4 . V_6 ) , 0 ) ;
F_4 ( V_5 , F_12 ( V_2 -> V_4 . V_6 ) ,
V_75 ) ;
return 0 ;
}
static void F_19 ( struct V_76 * V_40 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_6 ( V_40 , struct V_1 , V_40 ) ;
F_3 ( V_2 , V_79 , V_78 -> V_80 [ 0 ] ) ;
if ( V_78 -> V_78 . V_44 > 1 )
F_3 ( V_2 , V_81 , V_78 -> V_80 [ 1 ] ) ;
if ( V_78 -> V_78 . V_44 > 2 )
F_3 ( V_2 , V_82 , V_78 -> V_80 [ 2 ] ) ;
}
struct V_1 * F_20 ( struct V_25 * V_5 , unsigned int V_6 )
{
struct V_20 * V_21 ;
struct V_76 * V_40 ;
struct V_1 * V_2 ;
unsigned int V_83 ;
int V_31 ;
V_2 = F_21 ( V_5 -> V_84 , sizeof( * V_2 ) , V_85 ) ;
if ( V_2 == NULL )
return F_22 ( - V_86 ) ;
V_2 -> V_87 = V_88 ;
V_2 -> V_89 = V_90 ;
V_2 -> V_4 . type = V_91 ;
V_2 -> V_4 . V_6 = V_6 ;
V_31 = F_23 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_31 < 0 )
return F_22 ( V_31 ) ;
V_21 = & V_2 -> V_4 . V_21 ;
F_24 ( V_21 , & V_92 ) ;
V_21 -> V_4 . V_93 = & V_94 ;
V_21 -> V_95 = & V_96 ;
snprintf ( V_21 -> V_97 , sizeof( V_21 -> V_97 ) , L_1 ,
F_25 ( V_5 -> V_84 ) , V_6 ) ;
F_26 ( V_21 , V_2 ) ;
V_21 -> V_83 |= V_98 ;
F_27 ( V_21 , NULL ) ;
F_28 ( & V_2 -> V_12 , 1 ) ;
F_29 ( & V_2 -> V_12 , & V_99 , V_15 ,
0 , 255 , 1 , 255 ) ;
V_2 -> V_4 . V_21 . V_100 = & V_2 -> V_12 ;
if ( V_2 -> V_12 . error ) {
F_30 ( V_5 -> V_84 , L_2 ,
V_6 ) ;
V_31 = V_2 -> V_12 . error ;
goto error;
}
V_40 = & V_2 -> V_40 ;
V_40 -> type = V_101 ;
V_40 -> V_5 = V_5 ;
V_40 -> V_93 = & V_102 ;
V_31 = F_31 ( V_40 , & V_2 -> V_4 ) ;
if ( V_31 < 0 )
goto error;
V_2 -> V_4 . V_40 = V_40 ;
V_83 = V_103 ;
if ( ! ( V_5 -> V_104 -> V_105 & V_106 ) || V_6 != 0 )
V_83 |= V_107 ;
V_31 = F_32 ( & V_2 -> V_4 . V_21 . V_4 ,
V_70 ,
& V_2 -> V_40 . V_40 . V_4 , 0 , V_83 ) ;
if ( V_31 < 0 )
goto error;
V_2 -> V_4 . V_108 = & V_2 -> V_40 . V_40 . V_4 ;
return V_2 ;
error:
F_33 ( & V_2 -> V_4 ) ;
return F_22 ( V_31 ) ;
}
