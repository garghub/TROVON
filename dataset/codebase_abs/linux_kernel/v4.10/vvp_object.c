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
F_7 ( & V_2 -> V_16 ) ,
F_7 ( & V_2 -> V_17 ) , V_3 ) ;
if ( V_3 ) {
V_5 = F_3 ( V_3 ) ;
(* V_11)( V_9 , V_10 , L_2 V_18 ,
V_3 -> V_19 , V_3 -> V_20 , V_3 -> V_6 ,
V_3 -> V_21 , F_7 ( & V_3 -> V_22 ) ,
V_5 -> V_7 , F_8 ( & V_5 -> V_23 ) ) ;
}
return 0 ;
}
static int F_9 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_25 -> V_26 = F_10 ( V_3 ) ;
V_25 -> V_27 = V_3 -> V_28 . V_29 ;
V_25 -> V_30 = V_3 -> V_31 . V_29 ;
V_25 -> V_32 = V_3 -> V_33 . V_29 ;
V_25 -> V_34 = V_3 -> V_35 ;
V_25 -> V_36 = F_11 ( & V_37 , V_3 -> V_38 ) ;
V_25 -> V_39 = F_12 ( & V_37 , V_3 -> V_40 ) ;
return 0 ;
}
static int F_13 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
const struct V_24 * V_25 , unsigned int V_41 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_41 & V_42 )
V_3 -> V_38 = F_14 ( & V_37 , V_25 -> V_36 ) ;
if ( V_41 & V_43 )
V_3 -> V_40 = F_15 ( & V_37 , V_25 -> V_39 ) ;
if ( V_41 & V_44 )
V_3 -> V_31 . V_29 = V_25 -> V_30 ;
if ( V_41 & V_45 )
V_3 -> V_28 . V_29 = V_25 -> V_27 ;
if ( V_41 & V_46 )
V_3 -> V_33 . V_29 = V_25 -> V_32 ;
if ( 0 && V_41 & V_47 )
F_16 ( V_3 , V_25 -> V_26 ) ;
if ( 0 && V_41 & ( V_42 | V_43 | V_47 ) )
F_17 ( V_3 ) ;
return 0 ;
}
static int F_18 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
const struct V_48 * V_49 )
{
struct V_4 * V_5 = F_3 ( V_49 -> V_50 ) ;
if ( V_49 -> V_51 == V_52 ) {
F_19 ( V_53 , V_18 L_3 ,
F_8 ( & V_5 -> V_23 ) ) ;
F_20 ( V_5 , V_54 ) ;
F_21 ( V_49 -> V_50 -> V_55 ,
0 , V_56 , 0 ) ;
}
return 0 ;
}
static int F_22 ( const struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_57 ;
V_57 = F_23 ( V_3 , 0 , V_56 , V_58 , 1 ) ;
if ( V_57 < 0 ) {
F_19 ( V_53 , V_18 L_4 ,
F_8 ( F_24 ( & V_2 -> V_59 ) ) , V_57 ) ;
return V_57 ;
}
F_25 ( V_3 -> V_55 , 0 ) ;
return 0 ;
}
static int F_26 ( const struct V_8 * V_9 ,
const struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_61 -> V_62 = F_27 ( V_3 -> V_28 ) ;
V_61 -> V_63 = F_27 ( V_3 -> V_31 ) ;
V_61 -> V_64 = F_27 ( V_3 -> V_33 ) ;
if ( V_61 -> V_65 > 0 && V_61 -> V_66 == 0 )
V_61 -> V_66 = F_28 ( V_3 ) ;
return 0 ;
}
static void F_29 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_67 * V_25 )
{
T_2 V_68 = V_69 ;
struct V_3 * V_3 ;
struct V_70 * V_71 ;
V_71 = V_25 -> V_72 ;
V_3 = F_2 ( V_2 ) ;
if ( V_25 -> V_73 == V_74 )
V_68 |= V_75 | V_76 |
V_77 | V_78 ;
F_30 ( V_71 , V_3 , V_68 & V_25 -> V_79 ) ;
F_31 ( V_71 , & F_3 ( V_3 ) -> V_23 ) ;
if ( F_32 ( V_80 ) )
V_71 -> V_81 ++ ;
memcpy ( V_25 -> V_82 , F_3 ( V_3 ) -> V_83 , V_84 ) ;
}
static int F_33 ( const struct V_8 * V_9 ,
struct V_14 * V_85 ,
const struct V_48 * V_49 )
{
V_85 -> V_15 = V_49 -> V_50 ;
F_34 ( & V_85 -> V_16 , 0 ) ;
F_35 ( & V_85 -> V_86 , sizeof( struct V_87 ) ) ;
return 0 ;
}
static int F_36 ( const struct V_8 * V_9 , struct V_12 * V_2 ,
const struct V_88 * V_49 )
{
struct V_89 * V_90 = F_37 ( V_2 -> V_91 ) ;
struct V_14 * V_85 = F_6 ( V_2 ) ;
struct V_12 * V_92 ;
struct V_93 * V_94 ;
int V_95 ;
V_94 = & V_90 -> V_96 -> V_97 ;
V_92 = V_94 -> V_98 -> V_99 ( V_9 , V_2 -> V_100 , V_94 ) ;
if ( V_92 ) {
const struct V_48 * V_101 ;
V_101 = F_38 ( V_49 ) ;
F_39 ( V_2 , V_92 ) ;
V_95 = F_33 ( V_9 , V_85 , V_101 ) ;
} else {
V_95 = - V_102 ;
}
return V_95 ;
}
static void F_40 ( const struct V_8 * V_9 , struct V_12 * V_2 )
{
struct V_14 * V_85 = F_6 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 -> V_100 ) ;
F_43 ( V_103 , V_85 ) ;
}
struct V_14 * F_44 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct V_1 * V_2 = V_5 -> V_7 ;
struct V_12 * V_104 ;
V_104 = F_45 ( V_2 -> V_59 . V_100 , & V_105 ) ;
F_46 ( V_104 ) ;
return F_6 ( V_104 ) ;
}
struct V_12 * F_47 ( const struct V_8 * V_9 ,
const struct V_106 * V_107 ,
struct V_93 * V_90 )
{
struct V_14 * V_85 ;
struct V_12 * V_2 ;
V_85 = F_48 ( V_103 , V_108 ) ;
if ( V_85 ) {
struct V_109 * V_110 ;
V_2 = & V_85 -> V_86 . V_59 ;
V_110 = & V_85 -> V_111 ;
F_49 ( V_110 ) ;
V_110 -> V_112 = F_50 ( sizeof( struct V_113 ) ) ;
F_51 ( V_2 , & V_110 -> V_114 , V_90 ) ;
F_52 ( & V_110 -> V_114 , V_2 ) ;
V_85 -> V_86 . V_115 = & V_116 ;
V_2 -> V_117 = & V_118 ;
} else {
V_2 = NULL ;
}
return V_2 ;
}
