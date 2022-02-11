static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . V_6 . type = F_2 ( V_7 ) ;
V_4 -> V_5 . V_8 = 0 ;
F_3 ( V_2 , V_4 ) ;
}
static int F_4 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
T_1 V_13 ,
T_1 V_14 ,
T_1 V_15 ,
T_2 V_16 , T_2 V_17 )
{
struct V_1 * V_2 = V_10 -> V_18 -> V_19 ;
struct V_3 * V_4 =
F_5 ( V_10 , struct V_3 , V_10 ) ;
struct V_20 * V_21 = NULL ;
struct V_22 * V_23 = NULL ;
struct V_24 * V_25 = NULL ;
int V_26 = 0 ;
if ( V_13 == 0 ) {
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
V_21 = F_6 ( V_12 , V_13 ) ;
if ( V_21 == NULL )
return - V_27 ;
V_23 = F_7 ( V_21 ) ;
if ( ! V_23 -> V_28 ) {
V_26 = - V_29 ;
goto V_30;
}
F_8 ( V_2 , V_23 -> V_28 , 0 ,
F_2 ( 64 ) ,
F_2 ( 64 ) ,
0 , 0 , & V_25 ) ;
V_26 = F_9 ( V_23 , false ) ;
if ( ! V_26 ) {
F_10 ( V_23 -> V_31 . V_32 ,
& V_25 -> V_33 ) ;
F_11 ( & V_25 -> V_33 ) ;
F_12 ( V_23 ) ;
F_13 ( V_23 , false ) ;
}
V_4 -> V_5 . V_6 . type = F_2 ( V_7 ) ;
V_4 -> V_5 . V_8 = F_2 ( V_23 -> V_28 ) ;
V_4 -> V_5 . V_16 = F_2 ( V_16 ) ;
V_4 -> V_5 . V_17 = F_2 ( V_17 ) ;
F_3 ( V_2 , V_4 ) ;
V_26 = 0 ;
V_30:
F_14 ( V_21 ) ;
return V_26 ;
}
static int F_15 ( struct V_9 * V_10 ,
int V_34 , int V_35 )
{
struct V_1 * V_2 = V_10 -> V_18 -> V_19 ;
struct V_3 * V_4 =
F_5 ( V_10 , struct V_3 , V_10 ) ;
V_4 -> V_5 . V_6 . type = F_2 ( V_36 ) ;
V_4 -> V_5 . V_37 . V_34 = F_2 ( V_34 ) ;
V_4 -> V_5 . V_37 . V_35 = F_2 ( V_35 ) ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 ,
struct V_38 * V_39 ,
struct V_40 * V_41 ,
T_1 V_42 )
{
struct V_1 * V_2 = V_10 -> V_18 -> V_19 ;
struct V_3 * V_4 =
F_5 ( V_10 , struct V_3 , V_10 ) ;
struct V_43 * V_44 = V_10 -> V_45 ;
struct V_46 * V_47 ;
struct V_22 * V_48 ;
unsigned long V_49 ;
T_1 V_13 ;
V_44 -> V_39 = V_39 ;
V_47 = F_17 ( V_44 -> V_39 ) ;
V_48 = F_7 ( V_47 -> V_50 ) ;
V_13 = V_48 -> V_28 ;
F_18 ( L_1 , V_13 ,
V_48 -> V_51 ? L_2 : L_3 ,
V_10 -> V_52 . V_53 , V_10 -> V_52 . V_54 ) ;
if ( V_48 -> V_51 ) {
F_8
( V_2 , V_13 , 0 ,
F_2 ( V_10 -> V_52 . V_53 ) ,
F_2 ( V_10 -> V_52 . V_54 ) ,
0 , 0 , NULL ) ;
}
F_19 ( V_2 , V_4 -> V_55 , V_13 ,
V_10 -> V_52 . V_53 ,
V_10 -> V_52 . V_54 , 0 , 0 ) ;
F_20 ( V_2 , V_13 , 0 , 0 ,
V_10 -> V_52 . V_53 ,
V_10 -> V_52 . V_54 ) ;
if ( V_41 ) {
F_21 ( & V_10 -> V_18 -> V_56 , V_49 ) ;
F_22 ( V_10 -> V_18 , - 1 , V_41 ) ;
F_23 ( & V_10 -> V_18 -> V_56 , V_49 ) ;
}
return 0 ;
}
static void F_24 ( struct V_38 * V_39 )
{
struct V_46 * V_57
= F_17 ( V_39 ) ;
if ( V_57 -> V_50 )
F_14 ( V_57 -> V_50 ) ;
F_25 ( V_39 ) ;
F_26 ( V_57 ) ;
}
static int
F_27 ( struct V_38 * V_39 ,
struct V_11 * V_12 ,
unsigned V_42 , unsigned V_58 ,
struct V_59 * V_60 ,
unsigned V_61 )
{
struct V_46 * V_57
= F_17 ( V_39 ) ;
return F_28 ( V_57 , V_60 , V_61 ) ;
}
int
F_29 ( struct V_62 * V_18 ,
struct V_46 * V_47 ,
const struct V_63 * V_64 ,
struct V_20 * V_50 )
{
int V_26 ;
struct V_22 * V_48 ;
V_47 -> V_50 = V_50 ;
V_48 = F_7 ( V_50 ) ;
V_26 = F_30 ( V_18 , & V_47 -> V_65 , & V_66 ) ;
if ( V_26 ) {
V_47 -> V_50 = NULL ;
return V_26 ;
}
F_31 ( & V_47 -> V_65 , V_64 ) ;
F_32 ( & V_47 -> V_67 ) ;
V_47 -> V_68 = V_47 -> y1 = V_69 ;
V_47 -> V_70 = V_47 -> V_71 = 0 ;
return 0 ;
}
static void F_33 ( struct V_9 * V_10 )
{
struct V_62 * V_18 = V_10 -> V_18 ;
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_3 * V_4 = F_34 ( V_10 ) ;
F_19 ( V_2 , V_4 -> V_55 , 0 ,
V_10 -> V_52 . V_53 ,
V_10 -> V_52 . V_54 , 0 , 0 ) ;
}
static void F_35 ( struct V_9 * V_10 )
{
}
static void F_36 ( struct V_9 * V_10 )
{
struct V_62 * V_18 = V_10 -> V_18 ;
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_3 * V_4 = F_34 ( V_10 ) ;
F_19 ( V_2 , V_4 -> V_55 , 0 , 0 , 0 , 0 , 0 ) ;
}
static int F_37 ( struct V_9 * V_10 ,
struct V_72 * V_73 )
{
return 0 ;
}
static void F_38 ( struct V_9 * V_10 ,
struct V_72 * V_74 )
{
unsigned long V_42 ;
F_21 ( & V_10 -> V_18 -> V_56 , V_42 ) ;
if ( V_10 -> V_73 -> V_41 )
F_39 ( V_10 , V_10 -> V_73 -> V_41 ) ;
F_23 ( & V_10 -> V_18 -> V_56 , V_42 ) ;
}
static void F_40 ( struct V_75 * V_76 ,
struct V_77 * V_52 ,
struct V_77 * V_78 )
{
}
static void F_41 ( struct V_75 * V_76 )
{
}
static void F_42 ( struct V_75 * V_76 )
{
}
static int F_43 ( struct V_79 * V_80 )
{
struct V_3 * V_4 =
F_44 ( V_80 ) ;
struct V_77 * V_52 = NULL ;
int V_81 , V_14 , V_15 ;
V_14 = F_45 ( V_4 -> V_82 . V_83 . V_14 ) ;
V_15 = F_45 ( V_4 -> V_82 . V_83 . V_15 ) ;
V_81 = F_46 ( V_80 , V_84 , V_85 ) ;
if ( V_14 == 0 || V_15 == 0 ) {
V_14 = V_86 ;
V_15 = V_87 ;
F_47 ( V_80 , V_86 , V_87 ) ;
} else {
F_18 ( L_4 , V_14 , V_15 ) ;
V_52 = F_48 ( V_80 -> V_18 , V_14 , V_15 , 60 ,
false , false , false ) ;
V_52 -> type |= V_88 ;
F_49 ( V_80 , V_52 ) ;
V_81 ++ ;
}
return V_81 ;
}
static int F_50 ( struct V_79 * V_80 ,
struct V_77 * V_52 )
{
struct V_3 * V_4 =
F_44 ( V_80 ) ;
int V_14 , V_15 ;
V_14 = F_45 ( V_4 -> V_82 . V_83 . V_14 ) ;
V_15 = F_45 ( V_4 -> V_82 . V_83 . V_15 ) ;
if ( ! ( V_52 -> type & V_88 ) )
return V_89 ;
if ( V_52 -> V_53 == V_86 && V_52 -> V_54 == V_87 )
return V_89 ;
if ( V_52 -> V_53 <= V_14 && V_52 -> V_53 >= V_14 - 16 &&
V_52 -> V_54 <= V_15 && V_52 -> V_54 >= V_15 - 16 )
return V_89 ;
F_18 ( L_5 , V_52 -> V_53 , V_52 -> V_54 ) ;
return V_90 ;
}
static struct V_75 *
F_51 ( struct V_79 * V_80 )
{
struct V_3 * V_3 =
F_44 ( V_80 ) ;
return & V_3 -> V_91 ;
}
static enum V_92 F_52 (
struct V_79 * V_80 ,
bool V_93 )
{
struct V_3 * V_4 =
F_44 ( V_80 ) ;
if ( V_4 -> V_82 . V_94 )
return V_95 ;
else
return V_96 ;
}
static void F_53 ( struct V_79 * V_80 )
{
struct V_3 * V_3 =
F_44 ( V_80 ) ;
F_54 ( V_80 ) ;
F_55 ( V_80 ) ;
F_26 ( V_3 ) ;
}
static int F_56 ( struct V_1 * V_2 , int V_55 )
{
struct V_62 * V_18 = V_2 -> V_97 ;
struct V_3 * V_4 = V_2 -> V_98 + V_55 ;
struct V_79 * V_80 = & V_4 -> V_99 ;
struct V_75 * V_76 = & V_4 -> V_91 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_43 * V_44 ;
V_4 -> V_55 = V_55 ;
if ( V_55 == 0 ) {
V_4 -> V_82 . V_94 = F_2 ( true ) ;
V_4 -> V_82 . V_83 . V_14 = F_2 ( V_86 ) ;
V_4 -> V_82 . V_83 . V_15 = F_2 ( V_87 ) ;
}
V_44 = F_57 ( V_2 , V_55 ) ;
if ( F_58 ( V_44 ) )
return F_59 ( V_44 ) ;
F_60 ( V_18 , V_10 , V_44 , NULL ,
& V_100 , NULL ) ;
F_61 ( V_10 , & V_101 ) ;
V_44 -> V_10 = V_10 ;
F_62 ( V_18 , V_80 , & V_102 ,
V_103 ) ;
F_63 ( V_80 , & V_104 ) ;
F_64 ( V_18 , V_76 , & V_105 ,
V_106 , NULL ) ;
F_65 ( V_76 , & V_107 ) ;
V_76 -> V_108 = 1 << V_55 ;
F_66 ( V_80 , V_76 ) ;
F_67 ( V_80 ) ;
return 0 ;
}
static struct V_38 *
F_68 ( struct V_62 * V_18 ,
struct V_11 * V_12 ,
const struct V_63 * V_64 )
{
struct V_20 * V_50 = NULL ;
struct V_46 * V_57 ;
int V_26 ;
V_50 = F_6 ( V_12 , V_64 -> V_109 [ 0 ] ) ;
if ( ! V_50 )
return F_69 ( - V_29 ) ;
V_57 = F_70 ( sizeof( * V_57 ) , V_110 ) ;
if ( V_57 == NULL )
return F_69 ( - V_111 ) ;
V_26 = F_29 ( V_18 , V_57 , V_64 , V_50 ) ;
if ( V_26 ) {
F_26 ( V_57 ) ;
if ( V_50 )
F_14 ( V_50 ) ;
return NULL ;
}
return & V_57 -> V_65 ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_112 ;
F_72 ( V_2 -> V_97 ) ;
V_2 -> V_97 -> V_113 . V_114 = ( void * ) & V_115 ;
V_2 -> V_97 -> V_113 . V_116 = V_117 ;
V_2 -> V_97 -> V_113 . V_118 = V_119 ;
V_2 -> V_97 -> V_113 . V_120 = V_84 ;
V_2 -> V_97 -> V_113 . V_121 = V_85 ;
for ( V_112 = 0 ; V_112 < V_2 -> V_122 ; ++ V_112 )
F_56 ( V_2 , V_112 ) ;
F_73 ( V_2 -> V_97 ) ;
return 0 ;
}
void F_74 ( struct V_1 * V_2 )
{
F_75 ( V_2 ) ;
F_76 ( V_2 -> V_97 ) ;
}
