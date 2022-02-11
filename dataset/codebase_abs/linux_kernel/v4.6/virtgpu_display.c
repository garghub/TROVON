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
V_31 = F_10 ( V_28 , false ) ;
if ( ! V_31 ) {
F_11 ( V_28 -> V_36 . V_37 ,
& V_30 -> V_38 ) ;
F_12 ( & V_30 -> V_38 ) ;
F_13 ( V_28 ) ;
F_14 ( V_28 , false ) ;
}
V_11 -> V_12 . V_13 . type = F_3 ( V_14 ) ;
V_11 -> V_12 . V_15 = F_3 ( V_28 -> V_33 ) ;
V_11 -> V_12 . V_21 = F_3 ( V_21 ) ;
V_11 -> V_12 . V_22 = F_3 ( V_22 ) ;
F_4 ( V_9 , V_11 ) ;
V_31 = 0 ;
V_35:
F_15 ( V_26 ) ;
return V_31 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_39 , int V_40 )
{
struct V_8 * V_9 = V_2 -> V_23 -> V_24 ;
struct V_10 * V_11 =
F_6 ( V_2 , struct V_10 , V_2 ) ;
V_11 -> V_12 . V_13 . type = F_3 ( V_41 ) ;
V_11 -> V_12 . V_42 . V_39 = F_3 ( V_39 ) ;
V_11 -> V_12 . V_42 . V_40 = F_3 ( V_40 ) ;
F_4 ( V_9 , V_11 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_45 * V_46 ,
T_2 V_47 )
{
struct V_8 * V_9 = V_2 -> V_23 -> V_24 ;
struct V_10 * V_11 =
F_6 ( V_2 , struct V_10 , V_2 ) ;
struct V_48 * V_49 = V_2 -> V_50 ;
struct V_51 * V_52 ;
struct V_27 * V_53 ;
unsigned long V_54 ;
T_2 V_18 ;
V_49 -> V_44 = V_44 ;
V_52 = F_18 ( V_49 -> V_44 ) ;
V_53 = F_8 ( V_52 -> V_55 ) ;
V_18 = V_53 -> V_33 ;
F_19 ( L_1 , V_18 ,
V_53 -> V_56 ? L_2 : L_3 ,
V_2 -> V_57 . V_58 , V_2 -> V_57 . V_59 ) ;
if ( V_53 -> V_56 ) {
F_9
( V_9 , V_18 , 0 ,
F_3 ( V_2 -> V_57 . V_58 ) ,
F_3 ( V_2 -> V_57 . V_59 ) ,
0 , 0 , NULL ) ;
}
F_20 ( V_9 , V_11 -> V_60 , V_18 ,
V_2 -> V_57 . V_58 ,
V_2 -> V_57 . V_59 , 0 , 0 ) ;
F_21 ( V_9 , V_18 , 0 , 0 ,
V_2 -> V_57 . V_58 ,
V_2 -> V_57 . V_59 ) ;
if ( V_46 ) {
F_22 ( & V_2 -> V_23 -> V_61 , V_54 ) ;
F_23 ( V_2 -> V_23 , - 1 , V_46 ) ;
F_24 ( & V_2 -> V_23 -> V_61 , V_54 ) ;
}
return 0 ;
}
static void F_25 ( struct V_43 * V_44 )
{
struct V_51 * V_62
= F_18 ( V_44 ) ;
if ( V_62 -> V_55 )
F_15 ( V_62 -> V_55 ) ;
F_26 ( V_44 ) ;
F_27 ( V_62 ) ;
}
static int
F_28 ( struct V_43 * V_44 ,
struct V_16 * V_17 ,
unsigned V_47 , unsigned V_63 ,
struct V_64 * V_65 ,
unsigned V_66 )
{
struct V_51 * V_62
= F_18 ( V_44 ) ;
return F_29 ( V_62 , V_65 , V_66 ) ;
}
int
F_30 ( struct V_67 * V_23 ,
struct V_51 * V_52 ,
const struct V_68 * V_69 ,
struct V_25 * V_55 )
{
int V_31 ;
struct V_27 * V_53 ;
V_52 -> V_55 = V_55 ;
V_53 = F_8 ( V_55 ) ;
V_31 = F_31 ( V_23 , & V_52 -> V_70 , & V_71 ) ;
if ( V_31 ) {
V_52 -> V_55 = NULL ;
return V_31 ;
}
F_32 ( & V_52 -> V_70 , V_69 ) ;
F_33 ( & V_52 -> V_72 ) ;
V_52 -> V_73 = V_52 -> y1 = V_74 ;
V_52 -> V_75 = V_52 -> V_76 = 0 ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_67 * V_23 = V_2 -> V_23 ;
struct V_8 * V_9 = V_23 -> V_24 ;
struct V_10 * V_11 = F_35 ( V_2 ) ;
F_20 ( V_9 , V_11 -> V_60 , 0 ,
V_2 -> V_57 . V_58 ,
V_2 -> V_57 . V_59 , 0 , 0 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_67 * V_23 = V_2 -> V_23 ;
struct V_8 * V_9 = V_23 -> V_24 ;
struct V_10 * V_11 = F_35 ( V_2 ) ;
F_20 ( V_9 , V_11 -> V_60 , 0 , 0 , 0 , 0 , 0 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_77 * V_79 )
{
unsigned long V_47 ;
F_22 ( & V_2 -> V_23 -> V_61 , V_47 ) ;
if ( V_2 -> V_78 -> V_46 )
F_40 ( V_2 , V_2 -> V_78 -> V_46 ) ;
F_24 ( & V_2 -> V_23 -> V_61 , V_47 ) ;
}
static void F_41 ( struct V_80 * V_81 ,
struct V_82 * V_57 ,
struct V_82 * V_83 )
{
}
static void F_42 ( struct V_80 * V_81 )
{
}
static void F_43 ( struct V_80 * V_81 )
{
}
static int F_44 ( struct V_84 * V_85 )
{
struct V_10 * V_11 =
F_45 ( V_85 ) ;
struct V_82 * V_57 = NULL ;
int V_86 , V_19 , V_20 ;
V_19 = F_46 ( V_11 -> V_87 . V_88 . V_19 ) ;
V_20 = F_46 ( V_11 -> V_87 . V_88 . V_20 ) ;
V_86 = F_47 ( V_85 , V_89 , V_90 ) ;
if ( V_19 == 0 || V_20 == 0 ) {
V_19 = V_91 ;
V_20 = V_92 ;
F_48 ( V_85 , V_91 , V_92 ) ;
} else {
F_19 ( L_4 , V_19 , V_20 ) ;
V_57 = F_49 ( V_85 -> V_23 , V_19 , V_20 , 60 ,
false , false , false ) ;
V_57 -> type |= V_93 ;
F_50 ( V_85 , V_57 ) ;
V_86 ++ ;
}
return V_86 ;
}
static int F_51 ( struct V_84 * V_85 ,
struct V_82 * V_57 )
{
struct V_10 * V_11 =
F_45 ( V_85 ) ;
int V_19 , V_20 ;
V_19 = F_46 ( V_11 -> V_87 . V_88 . V_19 ) ;
V_20 = F_46 ( V_11 -> V_87 . V_88 . V_20 ) ;
if ( ! ( V_57 -> type & V_93 ) )
return V_94 ;
if ( V_57 -> V_58 == V_91 && V_57 -> V_59 == V_92 )
return V_94 ;
if ( V_57 -> V_58 <= V_19 && V_57 -> V_58 >= V_19 - 16 &&
V_57 -> V_59 <= V_20 && V_57 -> V_59 >= V_20 - 16 )
return V_94 ;
F_19 ( L_5 , V_57 -> V_58 , V_57 -> V_59 ) ;
return V_95 ;
}
static struct V_80 *
F_52 ( struct V_84 * V_85 )
{
struct V_10 * V_10 =
F_45 ( V_85 ) ;
return & V_10 -> V_96 ;
}
static enum V_97 F_53 (
struct V_84 * V_85 ,
bool V_98 )
{
struct V_10 * V_11 =
F_45 ( V_85 ) ;
if ( V_11 -> V_87 . V_99 )
return V_100 ;
else
return V_101 ;
}
static void F_54 ( struct V_84 * V_85 )
{
struct V_10 * V_10 =
F_45 ( V_85 ) ;
F_55 ( V_85 ) ;
F_56 ( V_85 ) ;
F_27 ( V_10 ) ;
}
static int F_57 ( struct V_8 * V_9 , int V_60 )
{
struct V_67 * V_23 = V_9 -> V_102 ;
struct V_10 * V_11 = V_9 -> V_103 + V_60 ;
struct V_84 * V_85 = & V_11 -> V_104 ;
struct V_80 * V_81 = & V_11 -> V_96 ;
struct V_1 * V_2 = & V_11 -> V_2 ;
struct V_48 * V_49 ;
V_11 -> V_60 = V_60 ;
if ( V_60 == 0 ) {
V_11 -> V_87 . V_99 = F_3 ( true ) ;
V_11 -> V_87 . V_88 . V_19 = F_3 ( V_91 ) ;
V_11 -> V_87 . V_88 . V_20 = F_3 ( V_92 ) ;
}
V_49 = F_58 ( V_9 , V_60 ) ;
if ( F_59 ( V_49 ) )
return F_60 ( V_49 ) ;
F_61 ( V_23 , V_2 , V_49 , NULL ,
& V_105 , NULL ) ;
F_62 ( V_2 , 256 ) ;
F_63 ( V_2 , & V_106 ) ;
V_49 -> V_2 = V_2 ;
F_64 ( V_23 , V_85 , & V_107 ,
V_108 ) ;
F_65 ( V_85 , & V_109 ) ;
F_66 ( V_23 , V_81 , & V_110 ,
V_111 , NULL ) ;
F_67 ( V_81 , & V_112 ) ;
V_81 -> V_113 = 1 << V_60 ;
F_68 ( V_85 , V_81 ) ;
F_69 ( V_85 ) ;
return 0 ;
}
static struct V_43 *
F_70 ( struct V_67 * V_23 ,
struct V_16 * V_17 ,
const struct V_68 * V_69 )
{
struct V_25 * V_55 = NULL ;
struct V_51 * V_62 ;
int V_31 ;
V_55 = F_7 ( V_23 , V_17 , V_69 -> V_114 [ 0 ] ) ;
if ( ! V_55 )
return F_71 ( - V_34 ) ;
V_62 = F_72 ( sizeof( * V_62 ) , V_115 ) ;
if ( V_62 == NULL )
return F_71 ( - V_116 ) ;
V_31 = F_30 ( V_23 , V_62 , V_69 , V_55 ) ;
if ( V_31 ) {
F_27 ( V_62 ) ;
if ( V_55 )
F_15 ( V_55 ) ;
return NULL ;
}
return & V_62 -> V_70 ;
}
int F_73 ( struct V_8 * V_9 )
{
int V_117 ;
F_74 ( V_9 -> V_102 ) ;
V_9 -> V_102 -> V_118 . V_119 = ( void * ) & V_120 ;
V_9 -> V_102 -> V_118 . V_121 = V_122 ;
V_9 -> V_102 -> V_118 . V_123 = V_124 ;
V_9 -> V_102 -> V_118 . V_125 = V_89 ;
V_9 -> V_102 -> V_118 . V_126 = V_90 ;
for ( V_117 = 0 ; V_117 < V_9 -> V_127 ; ++ V_117 )
F_57 ( V_9 , V_117 ) ;
F_75 ( V_9 -> V_102 ) ;
return 0 ;
}
void F_76 ( struct V_8 * V_9 )
{
F_77 ( V_9 ) ;
F_78 ( V_9 -> V_102 ) ;
}
