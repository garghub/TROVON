static void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 , T_1 * V_5 ,
T_2 V_6 , T_2 V_7 )
{
}
static void
F_2 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_12 . V_13 . type = F_3 ( V_14 ) ;
V_11 -> V_12 . V_15 = 0 ;
F_4 ( V_9 , V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
T_2 V_18 ,
T_2 V_19 ,
T_2 V_20 ,
T_3 V_21 , T_3 V_22 )
{
struct V_8 * V_9 = V_2 -> V_23 -> V_24 ;
struct V_10 * V_11 =
F_6 ( V_2 , struct V_10 , V_2 ) ;
struct V_25 * V_26 = NULL ;
struct V_27 * V_28 = NULL ;
struct V_29 * V_30 = NULL ;
int V_31 = 0 ;
if ( V_18 == 0 ) {
F_2 ( V_9 , V_11 ) ;
return 0 ;
}
V_26 = F_7 ( V_2 -> V_23 , V_17 , V_18 ) ;
if ( V_26 == NULL )
return - V_32 ;
V_28 = F_8 ( V_26 ) ;
if ( ! V_28 -> V_33 ) {
V_31 = - V_34 ;
goto V_35;
}
F_9 ( V_9 , V_28 -> V_33 , 0 ,
F_3 ( 64 ) ,
F_3 ( 64 ) ,
0 , 0 , & V_30 ) ;
V_11 -> V_12 . V_13 . type = F_3 ( V_14 ) ;
V_11 -> V_12 . V_15 = F_3 ( V_28 -> V_33 ) ;
V_11 -> V_12 . V_21 = F_3 ( V_21 ) ;
V_11 -> V_12 . V_22 = F_3 ( V_22 ) ;
F_4 ( V_9 , V_11 ) ;
V_31 = 0 ;
V_35:
F_10 ( V_26 ) ;
return V_31 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_36 , int V_37 )
{
struct V_8 * V_9 = V_2 -> V_23 -> V_24 ;
struct V_10 * V_11 =
F_6 ( V_2 , struct V_10 , V_2 ) ;
V_11 -> V_12 . V_13 . type = F_3 ( V_38 ) ;
V_11 -> V_12 . V_39 . V_36 = F_3 ( V_36 ) ;
V_11 -> V_12 . V_39 . V_37 = F_3 ( V_37 ) ;
F_4 ( V_9 , V_11 ) ;
return 0 ;
}
static void F_12 ( struct V_40 * V_41 )
{
struct V_42 * V_43
= F_13 ( V_41 ) ;
if ( V_43 -> V_44 )
F_10 ( V_43 -> V_44 ) ;
F_14 ( V_41 ) ;
F_15 ( V_43 ) ;
}
static int
F_16 ( struct V_40 * V_41 ,
struct V_16 * V_17 ,
unsigned V_45 , unsigned V_46 ,
struct V_47 * V_48 ,
unsigned V_49 )
{
struct V_42 * V_43
= F_13 ( V_41 ) ;
return F_17 ( V_43 , V_48 , V_49 ) ;
}
int
F_18 ( struct V_50 * V_23 ,
struct V_42 * V_51 ,
struct V_52 * V_53 ,
struct V_25 * V_44 )
{
int V_31 ;
struct V_27 * V_54 ;
V_51 -> V_44 = V_44 ;
V_54 = F_8 ( V_44 ) ;
V_31 = F_19 ( V_23 , & V_51 -> V_55 , & V_56 ) ;
if ( V_31 ) {
V_51 -> V_44 = NULL ;
return V_31 ;
}
F_20 ( & V_51 -> V_55 , V_53 ) ;
F_21 ( & V_51 -> V_57 ) ;
V_51 -> V_58 = V_51 -> y1 = V_59 ;
V_51 -> V_60 = V_51 -> V_61 = 0 ;
return 0 ;
}
static bool F_22 ( struct V_1 * V_2 ,
const struct V_62 * V_63 ,
struct V_62 * V_64 )
{
return true ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_50 * V_23 = V_2 -> V_23 ;
struct V_8 * V_9 = V_23 -> V_24 ;
struct V_10 * V_11 = F_24 ( V_2 ) ;
F_25 ( V_9 , V_11 -> V_65 , 0 ,
V_2 -> V_63 . V_66 ,
V_2 -> V_63 . V_67 , 0 , 0 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_50 * V_23 = V_2 -> V_23 ;
struct V_8 * V_9 = V_23 -> V_24 ;
struct V_10 * V_11 = F_24 ( V_2 ) ;
F_25 ( V_9 , V_11 -> V_65 , 0 , 0 , 0 , 0 , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
return 0 ;
}
static bool F_29 ( struct V_70 * V_71 ,
const struct V_62 * V_63 ,
struct V_62 * V_64 )
{
return true ;
}
static void F_30 ( struct V_70 * V_71 ,
struct V_62 * V_63 ,
struct V_62 * V_64 )
{
}
static void F_31 ( struct V_70 * V_71 )
{
}
static void F_32 ( struct V_70 * V_71 )
{
}
static int F_33 ( struct V_72 * V_73 )
{
struct V_10 * V_11 =
F_34 ( V_73 ) ;
struct V_62 * V_63 = NULL ;
int V_74 , V_19 , V_20 ;
V_19 = F_35 ( V_11 -> V_75 . V_76 . V_19 ) ;
V_20 = F_35 ( V_11 -> V_75 . V_76 . V_20 ) ;
V_74 = F_36 ( V_73 , V_77 , V_78 ) ;
if ( V_19 == 0 || V_20 == 0 ) {
V_19 = V_79 ;
V_20 = V_80 ;
F_37 ( V_73 , V_79 , V_80 ) ;
} else {
F_38 ( L_1 , V_19 , V_20 ) ;
V_63 = F_39 ( V_73 -> V_23 , V_19 , V_20 , 60 ,
false , false , false ) ;
V_63 -> type |= V_81 ;
F_40 ( V_73 , V_63 ) ;
V_74 ++ ;
}
return V_74 ;
}
static int F_41 ( struct V_72 * V_73 ,
struct V_62 * V_63 )
{
struct V_10 * V_11 =
F_34 ( V_73 ) ;
int V_19 , V_20 ;
V_19 = F_35 ( V_11 -> V_75 . V_76 . V_19 ) ;
V_20 = F_35 ( V_11 -> V_75 . V_76 . V_20 ) ;
if ( ! ( V_63 -> type & V_81 ) )
return V_82 ;
if ( V_63 -> V_66 == V_79 && V_63 -> V_67 == V_80 )
return V_82 ;
if ( V_63 -> V_66 <= V_19 && V_63 -> V_66 >= V_19 - 16 &&
V_63 -> V_67 <= V_20 && V_63 -> V_67 >= V_20 - 16 )
return V_82 ;
F_38 ( L_2 , V_63 -> V_66 , V_63 -> V_67 ) ;
return V_83 ;
}
static struct V_70 *
F_42 ( struct V_72 * V_73 )
{
struct V_10 * V_10 =
F_34 ( V_73 ) ;
return & V_10 -> V_84 ;
}
static void F_43 ( struct V_72 * V_73 )
{
F_38 ( L_3 ) ;
}
static void F_44 ( struct V_72 * V_73 )
{
F_38 ( L_3 ) ;
}
static enum V_85 F_45 (
struct V_72 * V_73 ,
bool V_86 )
{
struct V_10 * V_11 =
F_34 ( V_73 ) ;
if ( V_11 -> V_75 . V_87 )
return V_88 ;
else
return V_89 ;
}
static void F_46 ( struct V_72 * V_73 )
{
struct V_10 * V_10 =
F_34 ( V_73 ) ;
F_47 ( V_73 ) ;
F_48 ( V_73 ) ;
F_15 ( V_10 ) ;
}
static int F_49 ( struct V_8 * V_9 , int V_65 )
{
struct V_50 * V_23 = V_9 -> V_90 ;
struct V_10 * V_11 = V_9 -> V_91 + V_65 ;
struct V_72 * V_73 = & V_11 -> V_92 ;
struct V_70 * V_71 = & V_11 -> V_84 ;
struct V_1 * V_2 = & V_11 -> V_2 ;
struct V_93 * V_94 ;
V_11 -> V_65 = V_65 ;
if ( V_65 == 0 ) {
V_11 -> V_75 . V_87 = F_3 ( true ) ;
V_11 -> V_75 . V_76 . V_19 = F_3 ( V_79 ) ;
V_11 -> V_75 . V_76 . V_20 = F_3 ( V_80 ) ;
}
V_94 = F_50 ( V_9 , V_65 ) ;
if ( F_51 ( V_94 ) )
return F_52 ( V_94 ) ;
F_53 ( V_23 , V_2 , V_94 , NULL ,
& V_95 ) ;
F_54 ( V_2 , 256 ) ;
F_55 ( V_2 , & V_96 ) ;
V_94 -> V_2 = V_2 ;
F_56 ( V_23 , V_73 , & V_97 ,
V_98 ) ;
F_57 ( V_73 , & V_99 ) ;
F_58 ( V_23 , V_71 , & V_100 ,
V_101 ) ;
F_59 ( V_71 , & V_102 ) ;
V_71 -> V_103 = 1 << V_65 ;
F_60 ( V_73 , V_71 ) ;
F_61 ( V_73 ) ;
return 0 ;
}
static struct V_40 *
F_62 ( struct V_50 * V_23 ,
struct V_16 * V_17 ,
struct V_52 * V_53 )
{
struct V_25 * V_44 = NULL ;
struct V_42 * V_43 ;
int V_31 ;
V_44 = F_7 ( V_23 , V_17 , V_53 -> V_104 [ 0 ] ) ;
if ( ! V_44 )
return F_63 ( - V_34 ) ;
V_43 = F_64 ( sizeof( * V_43 ) , V_105 ) ;
if ( V_43 == NULL )
return F_63 ( - V_106 ) ;
V_31 = F_18 ( V_23 , V_43 , V_53 , V_44 ) ;
if ( V_31 ) {
F_15 ( V_43 ) ;
if ( V_44 )
F_10 ( V_44 ) ;
return NULL ;
}
return & V_43 -> V_55 ;
}
int F_65 ( struct V_8 * V_9 )
{
int V_107 ;
F_66 ( V_9 -> V_90 ) ;
V_9 -> V_90 -> V_108 . V_109 = ( void * ) & V_110 ;
V_9 -> V_90 -> V_108 . V_111 = V_112 ;
V_9 -> V_90 -> V_108 . V_113 = V_114 ;
V_9 -> V_90 -> V_108 . V_115 = V_77 ;
V_9 -> V_90 -> V_108 . V_116 = V_78 ;
for ( V_107 = 0 ; V_107 < V_9 -> V_117 ; ++ V_107 )
F_49 ( V_9 , V_107 ) ;
F_67 ( V_9 -> V_90 ) ;
return 0 ;
}
void F_68 ( struct V_8 * V_9 )
{
F_69 ( V_9 ) ;
F_70 ( V_9 -> V_90 ) ;
}
