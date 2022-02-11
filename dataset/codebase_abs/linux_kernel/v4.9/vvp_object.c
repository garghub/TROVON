int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_3 ) ;
return ( F_4 ( V_3 -> V_6 ) || V_3 -> V_6 == 0 ) &&
V_5 -> V_7 == V_2 ;
}
static int F_5 ( const struct V_8 * V_9 , void * V_10 ,
T_1 V_11 , const struct V_12 * V_13 )
{
struct V_14 * V_2 = F_6 ( V_13 ) ;
struct V_3 * V_3 = V_2 -> V_15 ;
struct V_4 * V_5 ;
(* V_11)( V_9 , V_10 , L_1 ,
F_7 ( & V_2 -> V_16 ) ? L_2 : L_3 ,
F_8 ( & V_2 -> V_17 ) ,
F_8 ( & V_2 -> V_18 ) , V_3 ) ;
if ( V_3 ) {
V_5 = F_3 ( V_3 ) ;
(* V_11)( V_9 , V_10 , L_4 V_19 ,
V_3 -> V_20 , V_3 -> V_21 , V_3 -> V_6 ,
V_3 -> V_22 , F_8 ( & V_3 -> V_23 ) ,
V_5 -> V_7 , F_9 ( & V_5 -> V_24 ) ) ;
}
return 0 ;
}
static int F_10 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_26 -> V_27 = F_11 ( V_3 ) ;
V_26 -> V_28 = V_3 -> V_29 . V_30 ;
V_26 -> V_31 = V_3 -> V_32 . V_30 ;
V_26 -> V_33 = V_3 -> V_34 . V_30 ;
V_26 -> V_35 = V_3 -> V_36 ;
V_26 -> V_37 = F_12 ( & V_38 , V_3 -> V_39 ) ;
V_26 -> V_40 = F_13 ( & V_38 , V_3 -> V_41 ) ;
return 0 ;
}
static int F_14 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
const struct V_25 * V_26 , unsigned int V_42 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_42 & V_43 )
V_3 -> V_39 = F_15 ( & V_38 , V_26 -> V_37 ) ;
if ( V_42 & V_44 )
V_3 -> V_41 = F_16 ( & V_38 , V_26 -> V_40 ) ;
if ( V_42 & V_45 )
V_3 -> V_32 . V_30 = V_26 -> V_31 ;
if ( V_42 & V_46 )
V_3 -> V_29 . V_30 = V_26 -> V_28 ;
if ( V_42 & V_47 )
V_3 -> V_34 . V_30 = V_26 -> V_33 ;
if ( 0 && V_42 & V_48 )
F_17 ( V_3 , V_26 -> V_27 ) ;
if ( 0 && V_42 & ( V_43 | V_44 | V_48 ) )
F_18 ( V_3 ) ;
return 0 ;
}
static int F_19 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
const struct V_49 * V_50 )
{
struct V_4 * V_5 = F_3 ( V_50 -> V_51 ) ;
if ( V_50 -> V_52 == V_53 ) {
F_20 ( V_54 , V_19 L_5 ,
F_9 ( & V_5 -> V_24 ) ) ;
F_21 ( V_5 , V_55 ) ;
F_22 ( V_50 -> V_51 -> V_56 ,
0 , V_57 , 0 ) ;
return 0 ;
}
if ( V_50 -> V_52 != V_58 )
return 0 ;
if ( V_50 -> V_59 . V_60 && V_50 -> V_59 . V_60 -> V_61 ) {
F_20 ( V_54 , V_19 L_6 ,
F_9 ( & V_5 -> V_24 ) , V_5 -> V_62 ,
V_50 -> V_59 . V_60 -> V_61 -> V_63 ) ;
V_5 -> V_64 = F_23 ( V_50 -> V_59 . V_60 -> V_61 ) ;
F_21 ( V_5 , V_50 -> V_59 . V_60 -> V_61 -> V_63 ) ;
} else {
F_20 ( V_54 , V_19 L_7 ,
F_9 ( & V_5 -> V_24 ) , V_5 -> V_62 ) ;
V_5 -> V_64 = false ;
F_21 ( V_5 , V_65 ) ;
}
return 0 ;
}
static int F_24 ( const struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_66 ;
V_66 = F_25 ( V_3 , 0 , V_57 , V_67 , 1 ) ;
if ( V_66 < 0 ) {
F_20 ( V_54 , V_19 L_8 ,
F_9 ( F_26 ( & V_2 -> V_68 ) ) , V_66 ) ;
return V_66 ;
}
F_27 ( V_3 -> V_56 , 0 ) ;
return 0 ;
}
static int F_28 ( const struct V_8 * V_9 ,
const struct V_1 * V_2 , struct V_69 * V_70 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_70 -> V_71 = F_29 ( V_3 -> V_29 ) ;
V_70 -> V_72 = F_29 ( V_3 -> V_32 ) ;
V_70 -> V_73 = F_29 ( V_3 -> V_34 ) ;
if ( V_70 -> V_74 > 0 && V_70 -> V_75 == 0 )
V_70 -> V_75 = F_30 ( V_3 ) ;
return 0 ;
}
static int F_31 ( const struct V_8 * V_9 ,
struct V_14 * V_76 ,
const struct V_49 * V_50 )
{
V_76 -> V_15 = V_50 -> V_51 ;
F_32 ( & V_76 -> V_17 , 0 ) ;
F_33 ( & V_76 -> V_77 , sizeof( struct V_78 ) ) ;
return 0 ;
}
static int F_34 ( const struct V_8 * V_9 , struct V_12 * V_2 ,
const struct V_79 * V_50 )
{
struct V_80 * V_81 = F_35 ( V_2 -> V_82 ) ;
struct V_14 * V_76 = F_6 ( V_2 ) ;
struct V_12 * V_83 ;
struct V_84 * V_85 ;
int V_86 ;
V_85 = & V_81 -> V_87 -> V_88 ;
V_83 = V_85 -> V_89 -> V_90 ( V_9 , V_2 -> V_91 , V_85 ) ;
if ( V_83 ) {
const struct V_49 * V_92 ;
V_92 = F_36 ( V_50 ) ;
F_37 ( & V_76 -> V_16 ) ;
F_38 ( V_2 , V_83 ) ;
V_86 = F_31 ( V_9 , V_76 , V_92 ) ;
} else {
V_86 = - V_93 ;
}
return V_86 ;
}
static void F_39 ( const struct V_8 * V_9 , struct V_12 * V_2 )
{
struct V_14 * V_76 = F_6 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 -> V_91 ) ;
F_42 ( V_94 , V_76 ) ;
}
struct V_14 * F_43 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct V_1 * V_2 = V_5 -> V_7 ;
struct V_12 * V_95 ;
V_95 = F_44 ( V_2 -> V_68 . V_91 , & V_96 ) ;
F_45 ( V_95 ) ;
return F_6 ( V_95 ) ;
}
struct V_12 * F_46 ( const struct V_8 * V_9 ,
const struct V_97 * V_98 ,
struct V_84 * V_81 )
{
struct V_14 * V_76 ;
struct V_12 * V_2 ;
V_76 = F_47 ( V_94 , V_99 ) ;
if ( V_76 ) {
struct V_100 * V_101 ;
V_2 = & V_76 -> V_77 . V_68 ;
V_101 = & V_76 -> V_102 ;
F_48 ( V_101 ) ;
V_101 -> V_103 = F_49 ( sizeof( struct V_104 ) ) ;
F_50 ( V_2 , & V_101 -> V_105 , V_81 ) ;
F_51 ( & V_101 -> V_105 , V_2 ) ;
V_76 -> V_77 . V_106 = & V_107 ;
V_2 -> V_108 = & V_109 ;
} else {
V_2 = NULL ;
}
return V_2 ;
}
