static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( (struct V_5 * ) V_2 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_4 ( (struct V_7 * ) V_2 -> V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_6 ( (struct V_8 * ) V_2 -> V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_9 * V_10 = V_2 -> V_6 ;
struct V_11 * V_12 =
F_8 ( V_2 , struct V_11 , V_13 . V_2 ) ;
int V_14 ;
if ( V_4 == V_15 ) {
if ( ! F_9 ( & V_12 -> V_16 ) )
return - V_17 ;
} else if ( V_10 == V_10 -> V_18 ) {
F_10 ( V_10 , V_12 ) ;
}
V_14 = F_11 ( V_10 ) ;
if ( V_14 && V_4 == V_15 )
return V_14 ;
if ( V_12 -> V_19 )
F_12 ( & V_12 -> V_19 -> V_20 ) ;
F_13 ( V_2 -> V_21 -> V_22 , & V_12 -> V_13 ) ;
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_23 * V_24 = V_2 -> V_6 ;
struct V_25 * * V_26 = V_24 -> V_26 ;
int V_14 ;
V_14 = F_15 ( V_24 ) ;
if ( ! V_14 || V_4 != V_15 )
F_16 ( V_26 ) ;
return V_14 ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_25 * V_27 = V_2 -> V_6 ;
struct V_28 * V_29 =
F_8 ( V_2 , struct V_28 , V_13 . V_2 ) ;
int V_14 ;
V_14 = F_18 ( V_27 ) ;
if ( ! V_14 || V_4 != V_15 )
F_13 ( V_2 -> V_21 -> V_22 , & V_29 -> V_13 ) ;
return V_14 ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_30 * V_31 = V_2 -> V_6 ;
struct V_32 * V_13 =
F_8 ( V_2 , struct V_32 , V_2 ) ;
enum V_33 V_34 = V_31 -> V_34 ;
int V_14 ;
V_14 = F_20 ( V_31 ) ;
if ( V_14 && V_4 == V_15 )
return V_14 ;
if ( V_34 == V_35 ) {
struct V_36 * V_37 =
F_8 ( V_13 , struct V_36 , V_13 ) ;
F_12 ( & V_37 -> V_19 -> V_20 ) ;
}
F_13 ( V_2 -> V_21 -> V_22 , V_13 ) ;
return V_14 ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_38 * V_39 = V_2 -> V_6 ;
struct V_40 * V_41 = V_39 -> V_42 ;
struct V_43 * V_44 =
F_8 ( V_2 , struct V_43 , V_2 ) ;
int V_14 ;
V_14 = F_22 ( V_39 ) ;
if ( ! V_14 || V_4 != V_15 )
F_23 ( V_2 -> V_21 -> V_22 , V_41 ?
F_8 ( V_41 ,
struct V_45 ,
V_41 ) : NULL ,
V_44 ) ;
return V_14 ;
}
static int F_24 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_25 ( (struct V_46 * ) V_2 -> V_6 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_47 * V_48 = V_2 -> V_6 ;
struct V_49 * V_19 =
F_8 ( V_2 , struct V_49 , V_2 ) ;
int V_14 ;
F_27 ( & V_2 -> V_21 -> V_22 -> V_50 -> V_51 ) ;
if ( V_4 == V_15 && F_28 ( & V_19 -> V_20 ) )
V_14 = - V_17 ;
else
V_14 = F_29 ( V_2 -> V_21 -> V_22 -> V_50 ,
V_48 , V_4 ) ;
F_30 ( & V_2 -> V_21 -> V_22 -> V_50 -> V_51 ) ;
return V_14 ;
}
static int F_31 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_52 * V_53 = V_2 -> V_6 ;
if ( V_4 == V_15 && F_28 ( & V_53 -> V_54 ) )
return - V_17 ;
F_32 ( (struct V_52 * ) V_2 -> V_6 ) ;
return 0 ;
}
static int F_33 ( struct V_55 * V_56 ,
enum V_3 V_4 )
{
struct V_45 * V_57 =
F_8 ( V_56 , struct V_45 ,
V_56 ) ;
struct V_40 * V_58 = & V_57 -> V_41 ;
F_34 ( & V_58 -> V_59 ) ;
V_58 -> V_60 = 1 ;
F_35 ( & V_58 -> V_59 ) ;
if ( V_4 == V_61 ) {
F_36 ( & V_58 -> V_62 ) ;
F_37 ( & V_58 -> V_63 , V_64 , V_65 ) ;
}
return 0 ;
}
static void F_38 ( struct V_66 * V_67 ,
struct V_68 * V_69 )
{
void T_1 * V_70 ;
T_2 V_71 = 0 ;
void T_1 * V_72 ;
T_2 V_73 = 0 ;
const struct V_74 * V_75 =
F_39 ( V_67 , V_76 ) ;
const struct V_74 * V_77 =
F_39 ( V_67 , V_78 ) ;
if ( ! F_40 ( V_75 ) ) {
V_70 = V_75 -> V_79 . V_80 ;
V_71 = V_75 -> V_79 . V_81 ;
}
if ( ! F_40 ( V_77 ) ) {
V_72 = V_77 -> V_79 . V_80 ;
V_73 = V_77 -> V_79 . V_81 ;
}
F_41 ( V_69 , V_70 , V_72 , V_71 , V_73 ) ;
}
static int F_42 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
struct V_66 * V_86 )
{
struct V_87 * V_88 = V_85 -> V_88 ;
struct V_43 * V_89 ;
struct V_68 V_90 ;
int V_14 ;
T_3 V_91 ;
struct V_92 V_93 = {} ;
struct V_38 * V_39 ;
struct V_45 * V_94 = NULL ;
const struct V_74 * V_95 ;
struct V_1 * V_96 ;
if ( ! ( V_83 -> V_97 & 1ULL << V_98 ) )
return - V_99 ;
V_14 = F_43 ( & V_93 . V_100 , V_86 , V_101 ) ;
if ( ! V_14 )
V_14 = F_43 ( & V_93 . V_102 , V_86 , V_103 ) ;
if ( ! V_14 )
V_14 = F_43 ( & V_91 , V_86 , V_104 ) ;
if ( V_14 )
return V_14 ;
if ( F_43 ( & V_93 . V_105 , V_86 , V_106 ) == - V_107 )
return - V_107 ;
V_95 = F_39 ( V_86 , V_108 ) ;
if ( ! F_40 ( V_95 ) ) {
V_96 = V_95 -> V_109 . V_2 ;
V_94 = F_8 ( V_96 ,
struct V_45 ,
V_56 . V_110 ) ;
F_44 ( V_96 ) ;
}
if ( V_93 . V_100 >= V_88 -> V_22 -> V_50 -> V_111 ) {
V_14 = - V_112 ;
goto V_113;
}
V_89 = F_8 ( F_39 ( V_86 , V_114 ) -> V_109 . V_2 ,
F_45 ( * V_89 ) , V_2 ) ;
V_89 -> V_115 = V_88 -> V_22 ;
V_89 -> V_116 = 0 ;
V_89 -> V_117 = 0 ;
F_46 ( & V_89 -> V_118 ) ;
F_46 ( & V_89 -> V_119 ) ;
F_38 ( V_86 , & V_90 ) ;
V_39 = V_83 -> V_120 ( V_83 , & V_93 , V_88 , & V_90 ) ;
if ( F_40 ( V_39 ) ) {
V_14 = F_47 ( V_39 ) ;
goto V_113;
}
V_39 -> V_50 = V_83 ;
V_39 -> V_2 = & V_89 -> V_2 ;
V_39 -> V_121 = V_122 ;
V_39 -> V_123 = V_124 ;
V_39 -> V_42 = & V_94 -> V_41 ;
V_89 -> V_2 . V_6 = V_39 ;
V_89 -> V_2 . V_91 = V_91 ;
F_48 ( & V_39 -> V_54 , 0 ) ;
V_14 = F_49 ( V_86 , V_125 , & V_39 -> V_102 ) ;
if ( V_14 )
goto V_126;
return 0 ;
V_126:
F_22 ( V_39 ) ;
V_113:
if ( V_94 )
F_50 ( V_96 ) ;
return V_14 ;
}
static int F_51 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
struct V_66 * V_86 )
{
struct V_127 V_128 ;
struct V_1 * V_110 =
F_39 ( V_86 , V_129 ) -> V_109 . V_2 ;
struct V_43 * V_89 = F_8 ( V_110 , struct V_43 ,
V_2 ) ;
int V_14 ;
if ( ! ( V_83 -> V_97 & 1ULL << V_130 ) )
return - V_99 ;
V_14 = F_52 ( V_110 ) ;
if ( V_14 )
return V_14 ;
V_128 . V_116 = V_89 -> V_116 ;
V_128 . V_117 = V_89 -> V_117 ;
return F_49 ( V_86 , V_131 , & V_128 ) ;
}
