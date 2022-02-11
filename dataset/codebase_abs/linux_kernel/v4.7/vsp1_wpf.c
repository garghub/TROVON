static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 + V_2 -> V_7 . V_8 * V_9 , V_6 ) ;
}
static int F_3 ( struct V_10 * V_11 , int V_12 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
struct V_13 * V_14 = V_2 -> V_7 . V_14 ;
if ( V_12 )
return 0 ;
F_5 ( V_14 , F_6 ( V_2 -> V_7 . V_8 ) , 0 ) ;
F_5 ( V_14 , V_2 -> V_7 . V_8 * V_9 +
V_15 , 0 ) ;
return 0 ;
}
static void F_7 ( struct V_16 * V_7 )
{
struct V_1 * V_2 = F_8 ( V_7 ) ;
F_9 ( V_2 -> V_17 ) ;
}
static void F_10 ( struct V_16 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_8 ( V_7 ) ;
F_1 ( V_2 , V_4 , V_18 , V_2 -> V_19 . V_20 [ 0 ] ) ;
F_1 ( V_2 , V_4 , V_21 , V_2 -> V_19 . V_20 [ 1 ] ) ;
F_1 ( V_2 , V_4 , V_22 , V_2 -> V_19 . V_20 [ 2 ] ) ;
}
static void F_11 ( struct V_16 * V_7 ,
struct V_23 * V_24 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_4 ( & V_7 -> V_11 ) ;
struct V_13 * V_14 = V_2 -> V_7 . V_14 ;
const struct V_25 * V_26 ;
const struct V_25 * V_27 ;
const struct V_28 * V_29 ;
unsigned int V_30 ;
T_1 V_31 = 0 ;
T_1 V_32 = 0 ;
V_29 = F_12 ( V_2 , V_2 -> V_7 . V_33 ) ;
F_1 ( V_2 , V_4 , V_34 , V_35 |
( V_29 -> V_36 << V_37 ) |
( V_29 -> V_38 << V_39 ) ) ;
F_1 ( V_2 , V_4 , V_40 , V_35 |
( V_29 -> V_41 << V_37 ) |
( V_29 -> V_42 << V_39 ) ) ;
V_27 = F_13 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_33 ,
V_43 ) ;
V_26 = F_13 ( & V_2 -> V_7 ,
V_2 -> V_7 . V_33 ,
V_44 ) ;
if ( ! V_24 -> V_45 ) {
const struct V_46 * V_47 = & V_2 -> V_47 ;
const struct V_48 * V_49 = V_2 -> V_49 ;
V_31 = V_49 -> V_50 << V_51 ;
if ( V_49 -> V_52 )
V_31 |= V_53 ;
if ( V_49 -> V_54 )
V_31 |= V_55 ;
if ( V_49 -> V_56 )
V_31 |= V_57 ;
F_1 ( V_2 , V_4 , V_58 ,
V_47 -> V_59 [ 0 ] . V_60 ) ;
if ( V_47 -> V_61 > 1 )
F_1 ( V_2 , V_4 , V_62 ,
V_47 -> V_59 [ 1 ] . V_60 ) ;
F_1 ( V_2 , V_4 , V_63 , V_49 -> V_64 ) ;
}
if ( V_27 -> V_65 != V_26 -> V_65 )
V_31 |= V_66 ;
V_31 |= V_2 -> V_52 << V_67 ;
F_1 ( V_2 , V_4 , V_68 , V_31 ) ;
F_2 ( V_4 , F_14 ( V_2 -> V_7 . V_8 ) ,
V_69 ) ;
F_2 ( V_4 , V_70 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_14 -> V_71 -> V_72 ; ++ V_30 ) {
struct V_1 * V_73 = V_24 -> V_74 [ V_30 ] ;
if ( ! V_73 )
continue;
V_32 |= ( ! V_24 -> V_75 && V_24 -> V_76 == 1 )
? F_15 ( V_73 -> V_7 . V_8 )
: F_16 ( V_73 -> V_7 . V_8 ) ;
}
if ( V_24 -> V_75 || V_24 -> V_76 > 1 )
V_32 |= V_77 ;
F_1 ( V_2 , V_4 , V_15 , V_32 ) ;
F_2 ( V_4 , F_17 ( V_2 -> V_7 . V_8 ) , 0 ) ;
F_2 ( V_4 , F_6 ( V_2 -> V_7 . V_8 ) ,
V_78 ) ;
}
struct V_1 * F_18 ( struct V_13 * V_14 , unsigned int V_8 )
{
struct V_1 * V_2 ;
char V_79 [ 6 ] ;
int V_80 ;
V_2 = F_19 ( V_14 -> V_81 , sizeof( * V_2 ) , V_82 ) ;
if ( V_2 == NULL )
return F_20 ( - V_83 ) ;
if ( V_14 -> V_71 -> V_84 == 2 ) {
V_2 -> V_85 = V_86 ;
V_2 -> V_87 = V_88 ;
} else {
V_2 -> V_85 = V_89 ;
V_2 -> V_87 = V_90 ;
}
V_2 -> V_7 . V_91 = & V_92 ;
V_2 -> V_7 . type = V_93 ;
V_2 -> V_7 . V_8 = V_8 ;
sprintf ( V_79 , L_1 , V_8 ) ;
V_80 = F_21 ( V_14 , & V_2 -> V_7 , V_79 , 2 , & V_94 ) ;
if ( V_80 < 0 )
return F_20 ( V_80 ) ;
V_2 -> V_17 = F_22 ( V_14 , V_8 , 4 ) ;
if ( ! V_2 -> V_17 ) {
V_80 = - V_83 ;
goto error;
}
V_80 = F_23 ( V_2 ) ;
if ( V_80 < 0 ) {
F_24 ( V_14 -> V_81 , L_2 ,
V_8 ) ;
goto error;
}
return V_2 ;
error:
F_25 ( & V_2 -> V_7 ) ;
return F_20 ( V_80 ) ;
}
