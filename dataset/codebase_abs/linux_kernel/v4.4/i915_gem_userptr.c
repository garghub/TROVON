static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , F_3 ( * V_4 ) , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 . V_8 ;
F_4 ( & V_8 -> V_10 ) ;
V_6 -> V_11 . V_2 = NULL ;
if ( V_6 -> V_12 != NULL ) {
struct V_13 * V_14 = F_5 ( V_8 ) ;
struct V_15 * V_16 , * V_17 ;
bool V_18 ;
V_18 = V_14 -> V_19 . V_20 ;
V_14 -> V_19 . V_20 = false ;
F_6 (vma, tmp, &obj->vma_list, vma_link) {
int V_21 = F_7 ( V_16 ) ;
F_8 ( V_21 && V_21 != - V_22 ) ;
}
F_8 ( F_9 ( V_6 ) ) ;
V_14 -> V_19 . V_20 = V_18 ;
}
F_10 ( & V_6 -> V_9 ) ;
F_11 ( & V_8 -> V_10 ) ;
}
static unsigned long F_12 ( struct V_3 * V_4 )
{
unsigned long V_23 = V_4 -> V_6 -> V_11 . V_24 + V_4 -> V_6 -> V_9 . V_25 ;
if ( V_4 -> V_26 && F_13 ( & V_4 -> V_6 -> V_9 . V_27 ) ) {
F_14 ( & V_4 -> V_2 ) ;
V_4 -> V_26 = false ;
}
return V_23 ;
}
static void F_15 ( struct V_28 * V_29 ,
struct V_30 * V_19 ,
unsigned long V_31 ,
unsigned long V_23 )
{
struct V_32 * V_33 =
F_2 ( V_29 , struct V_32 , V_33 ) ;
struct V_3 * V_4 ;
V_23 -- ;
F_16 ( & V_33 -> V_34 ) ;
if ( V_33 -> V_35 ) {
F_17 (mo, &mn->linear, link) {
if ( V_4 -> V_36 . V_37 < V_31 || V_4 -> V_36 . V_31 > V_23 )
continue;
F_12 ( V_4 ) ;
}
} else {
struct V_38 * V_36 ;
V_36 = F_18 ( & V_33 -> V_39 , V_31 , V_23 ) ;
while ( V_36 ) {
V_4 = F_2 ( V_36 , struct V_3 , V_36 ) ;
V_31 = F_12 ( V_4 ) ;
V_36 = F_19 ( V_36 , V_31 , V_23 ) ;
}
}
F_20 ( & V_33 -> V_34 ) ;
}
static struct V_32 *
F_21 ( struct V_30 * V_19 )
{
struct V_32 * V_33 ;
int V_21 ;
V_33 = F_22 ( sizeof( * V_33 ) , V_40 ) ;
if ( V_33 == NULL )
return F_23 ( - V_41 ) ;
F_24 ( & V_33 -> V_34 ) ;
V_33 -> V_33 . V_42 = & V_43 ;
V_33 -> V_39 = V_44 ;
F_25 ( & V_33 -> V_45 ) ;
V_33 -> V_35 = false ;
V_21 = F_26 ( & V_33 -> V_33 , V_19 ) ;
if ( V_21 ) {
F_27 ( V_33 ) ;
return F_23 ( V_21 ) ;
}
return V_33 ;
}
static int
F_28 ( struct V_7 * V_8 ,
struct V_32 * V_33 ,
struct V_3 * V_4 )
{
struct V_38 * V_36 ;
int V_21 = 0 ;
F_4 ( & V_8 -> V_10 ) ;
F_29 ( V_8 ) ;
F_16 ( & V_33 -> V_34 ) ;
V_36 = F_18 ( & V_33 -> V_39 ,
V_4 -> V_36 . V_31 , V_4 -> V_36 . V_37 ) ;
if ( V_36 ) {
struct V_5 * V_6 ;
V_6 = F_2 ( V_36 , struct V_3 , V_36 ) -> V_6 ;
if ( ! V_6 -> V_11 . V_46 )
V_33 -> V_35 = V_4 -> V_47 = true ;
else
V_21 = - V_48 ;
} else
F_30 ( & V_4 -> V_36 , & V_33 -> V_39 ) ;
if ( V_21 == 0 )
F_31 ( & V_4 -> V_49 , & V_33 -> V_45 ) ;
F_20 ( & V_33 -> V_34 ) ;
F_11 ( & V_8 -> V_10 ) ;
return V_21 ;
}
static bool F_32 ( struct V_32 * V_33 )
{
struct V_3 * V_4 ;
F_17 (mo, &mn->linear, link)
if ( V_4 -> V_47 )
return true ;
return false ;
}
static void
F_33 ( struct V_32 * V_33 ,
struct V_3 * V_4 )
{
F_16 ( & V_33 -> V_34 ) ;
F_34 ( & V_4 -> V_49 ) ;
if ( V_4 -> V_47 )
V_33 -> V_35 = F_32 ( V_33 ) ;
else
F_35 ( & V_4 -> V_36 , & V_33 -> V_39 ) ;
F_20 ( & V_33 -> V_34 ) ;
}
static void
F_36 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_11 . V_50 ;
if ( V_4 == NULL )
return;
F_33 ( V_4 -> V_33 , V_4 ) ;
F_27 ( V_4 ) ;
V_6 -> V_11 . V_50 = NULL ;
}
static struct V_32 *
F_37 ( struct V_51 * V_19 )
{
struct V_32 * V_33 = V_19 -> V_33 ;
V_33 = V_19 -> V_33 ;
if ( V_33 )
return V_33 ;
F_38 ( & V_19 -> V_19 -> V_52 ) ;
F_4 ( & F_5 ( V_19 -> V_8 ) -> V_53 ) ;
if ( ( V_33 = V_19 -> V_33 ) == NULL ) {
V_33 = F_21 ( V_19 -> V_19 ) ;
if ( ! F_39 ( V_33 ) )
V_19 -> V_33 = V_33 ;
}
F_11 ( & F_5 ( V_19 -> V_8 ) -> V_53 ) ;
F_40 ( & V_19 -> V_19 -> V_52 ) ;
return V_33 ;
}
static int
F_41 ( struct V_5 * V_6 ,
unsigned V_54 )
{
struct V_32 * V_33 ;
struct V_3 * V_4 ;
int V_21 ;
if ( V_54 & V_55 )
return F_42 ( V_56 ) ? 0 : - V_57 ;
if ( F_8 ( V_6 -> V_11 . V_19 == NULL ) )
return - V_58 ;
V_33 = F_37 ( V_6 -> V_11 . V_19 ) ;
if ( F_39 ( V_33 ) )
return F_43 ( V_33 ) ;
V_4 = F_44 ( sizeof( * V_4 ) , V_40 ) ;
if ( V_4 == NULL )
return - V_41 ;
V_4 -> V_33 = V_33 ;
V_4 -> V_36 . V_31 = V_6 -> V_11 . V_24 ;
V_4 -> V_36 . V_37 = V_4 -> V_36 . V_31 + V_6 -> V_9 . V_25 - 1 ;
V_4 -> V_6 = V_6 ;
F_45 ( & V_4 -> V_2 , F_1 ) ;
V_21 = F_28 ( V_6 -> V_9 . V_8 , V_33 , V_4 ) ;
if ( V_21 ) {
F_27 ( V_4 ) ;
return V_21 ;
}
V_6 -> V_11 . V_50 = V_4 ;
return 0 ;
}
static void
F_46 ( struct V_32 * V_33 ,
struct V_30 * V_19 )
{
if ( V_33 == NULL )
return;
F_47 ( & V_33 -> V_33 , V_19 ) ;
F_27 ( V_33 ) ;
}
static void
F_36 ( struct V_5 * V_6 )
{
}
static int
F_41 ( struct V_5 * V_6 ,
unsigned V_54 )
{
if ( ( V_54 & V_55 ) == 0 )
return - V_59 ;
if ( ! F_42 ( V_56 ) )
return - V_57 ;
return 0 ;
}
static void
F_46 ( struct V_32 * V_33 ,
struct V_30 * V_19 )
{
}
static struct V_51 *
F_48 ( struct V_13 * V_14 , struct V_30 * V_60 )
{
struct V_51 * V_19 ;
F_49 (dev_priv->mm_structs, mm, node, (unsigned long)real)
if ( V_19 -> V_19 == V_60 )
return V_19 ;
return NULL ;
}
static int
F_50 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = F_5 ( V_6 -> V_9 . V_8 ) ;
struct V_51 * V_19 ;
int V_21 = 0 ;
F_4 ( & V_14 -> V_53 ) ;
V_19 = F_48 ( V_14 , V_61 -> V_19 ) ;
if ( V_19 == NULL ) {
V_19 = F_22 ( sizeof( * V_19 ) , V_40 ) ;
if ( V_19 == NULL ) {
V_21 = - V_41 ;
goto V_62;
}
F_51 ( & V_19 -> V_63 ) ;
V_19 -> V_8 = V_6 -> V_9 . V_8 ;
V_19 -> V_19 = V_61 -> V_19 ;
F_52 ( & V_61 -> V_19 -> V_64 ) ;
V_19 -> V_33 = NULL ;
F_53 ( V_14 -> V_65 ,
& V_19 -> V_66 , ( unsigned long ) V_19 -> V_19 ) ;
} else
F_54 ( & V_19 -> V_63 ) ;
V_6 -> V_11 . V_19 = V_19 ;
V_62:
F_11 ( & V_14 -> V_53 ) ;
return V_21 ;
}
static void
F_55 ( struct V_1 * V_2 )
{
struct V_51 * V_19 = F_2 ( V_2 , F_3 ( * V_19 ) , V_2 ) ;
F_46 ( V_19 -> V_33 , V_19 -> V_19 ) ;
F_56 ( V_19 -> V_19 ) ;
F_27 ( V_19 ) ;
}
static void
F_57 ( struct V_63 * V_63 )
{
struct V_51 * V_19 = F_2 ( V_63 , F_3 ( * V_19 ) , V_63 ) ;
F_58 ( & V_19 -> V_66 ) ;
F_11 ( & F_5 ( V_19 -> V_8 ) -> V_53 ) ;
F_45 ( & V_19 -> V_2 , F_55 ) ;
F_14 ( & V_19 -> V_2 ) ;
}
static void
F_59 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 . V_19 == NULL )
return;
F_60 ( & V_6 -> V_11 . V_19 -> V_63 ,
F_57 ,
& F_5 ( V_6 -> V_9 . V_8 ) -> V_53 ) ;
V_6 -> V_11 . V_19 = NULL ;
}
static int
F_61 ( struct V_67 * * V_68 , struct V_69 * * V_70 , int V_71 )
{
struct V_72 * V_73 ;
int V_21 , V_74 ;
* V_68 = F_22 ( sizeof( * * V_68 ) , V_40 ) ;
if ( * V_68 == NULL )
return - V_41 ;
if ( F_62 () ) {
V_21 = F_63 ( * V_68 , V_71 , V_40 ) ;
if ( V_21 )
goto V_75;
F_64 ((*st)->sgl, sg, num_pages, n)
F_65 ( V_73 , V_70 [ V_74 ] , V_76 , 0 ) ;
} else {
V_21 = F_66 ( * V_68 , V_70 , V_71 ,
0 , V_71 << V_77 ,
V_40 ) ;
if ( V_21 )
goto V_75;
}
return 0 ;
V_75:
F_27 ( * V_68 ) ;
* V_68 = NULL ;
return V_21 ;
}
static int
F_67 ( struct V_5 * V_6 ,
struct V_69 * * V_70 , int V_71 )
{
int V_21 ;
V_21 = F_61 ( & V_6 -> V_12 , V_70 , V_71 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_68 ( V_6 ) ;
if ( V_21 ) {
F_69 ( V_6 -> V_12 ) ;
F_27 ( V_6 -> V_12 ) ;
V_6 -> V_12 = NULL ;
}
return V_21 ;
}
static int
F_70 ( struct V_5 * V_6 ,
bool V_78 )
{
int V_21 = 0 ;
#if F_71 ( V_79 )
if ( V_6 -> V_11 . V_50 == NULL )
return 0 ;
F_16 ( & V_6 -> V_11 . V_50 -> V_33 -> V_34 ) ;
if ( ! V_78 || ! F_72 ( & V_6 -> V_11 . V_50 -> V_2 ) )
V_6 -> V_11 . V_50 -> V_26 = V_78 ;
else
V_21 = - V_48 ;
F_20 ( & V_6 -> V_11 . V_50 -> V_33 -> V_34 ) ;
#endif
return V_21 ;
}
static void
F_73 ( struct V_1 * V_80 )
{
struct V_81 * V_2 = F_2 ( V_80 , F_3 ( * V_2 ) , V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 . V_8 ;
const int V_82 = V_6 -> V_9 . V_25 >> V_77 ;
struct V_69 * * V_70 ;
int V_83 , V_21 ;
V_21 = - V_41 ;
V_83 = 0 ;
V_70 = F_22 ( V_82 * sizeof( struct V_69 * ) ,
V_84 | V_85 | V_86 ) ;
if ( V_70 == NULL )
V_70 = F_74 ( V_82 , sizeof( struct V_69 * ) ) ;
if ( V_70 != NULL ) {
struct V_30 * V_19 = V_6 -> V_11 . V_19 -> V_19 ;
F_75 ( & V_19 -> V_52 ) ;
while ( V_83 < V_82 ) {
V_21 = F_76 ( V_2 -> V_87 , V_19 ,
V_6 -> V_11 . V_24 + V_83 * V_76 ,
V_82 - V_83 ,
! V_6 -> V_11 . V_88 , 0 ,
V_70 + V_83 , NULL ) ;
if ( V_21 < 0 )
break;
V_83 += V_21 ;
}
F_77 ( & V_19 -> V_52 ) ;
}
F_4 ( & V_8 -> V_10 ) ;
if ( V_6 -> V_11 . V_2 == & V_2 -> V_2 ) {
if ( V_83 == V_82 ) {
V_21 = F_67 ( V_6 , V_70 , V_82 ) ;
if ( V_21 == 0 ) {
F_78 ( & V_6 -> V_89 ,
& F_5 ( V_8 ) -> V_19 . V_90 ) ;
V_6 -> V_91 . V_73 = V_6 -> V_12 -> V_92 ;
V_6 -> V_91 . V_37 = 0 ;
V_83 = 0 ;
}
}
V_6 -> V_11 . V_2 = F_23 ( V_21 ) ;
if ( V_21 )
F_70 ( V_6 , false ) ;
}
V_6 -> V_11 . V_46 -- ;
F_10 ( & V_6 -> V_9 ) ;
F_11 ( & V_8 -> V_10 ) ;
F_79 ( V_70 , V_83 , 0 ) ;
F_80 ( V_70 ) ;
F_81 ( V_2 -> V_87 ) ;
F_27 ( V_2 ) ;
}
static int
F_82 ( struct V_5 * V_6 ,
bool * V_26 )
{
struct V_81 * V_2 ;
if ( V_6 -> V_11 . V_46 >= V_93 )
return - V_48 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_40 ) ;
if ( V_2 == NULL )
return - V_41 ;
V_6 -> V_11 . V_2 = & V_2 -> V_2 ;
V_6 -> V_11 . V_46 ++ ;
V_2 -> V_6 = V_6 ;
F_83 ( & V_6 -> V_9 ) ;
V_2 -> V_87 = V_61 ;
F_84 ( V_2 -> V_87 ) ;
F_45 ( & V_2 -> V_2 , F_73 ) ;
F_14 ( & V_2 -> V_2 ) ;
* V_26 = true ;
return - V_48 ;
}
static int
F_85 ( struct V_5 * V_6 )
{
const int V_71 = V_6 -> V_9 . V_25 >> V_77 ;
struct V_69 * * V_70 ;
int V_83 , V_21 ;
bool V_26 ;
if ( F_39 ( V_6 -> V_11 . V_2 ) ) {
V_21 = F_43 ( V_6 -> V_11 . V_2 ) ;
V_6 -> V_11 . V_2 = NULL ;
return V_21 ;
}
if ( V_6 -> V_11 . V_2 )
return - V_48 ;
V_21 = F_70 ( V_6 , true ) ;
if ( V_21 )
return V_21 ;
V_70 = NULL ;
V_83 = 0 ;
if ( V_6 -> V_11 . V_19 -> V_19 == V_61 -> V_19 ) {
V_70 = F_22 ( V_71 * sizeof( struct V_69 * ) ,
V_84 | V_85 | V_86 ) ;
if ( V_70 == NULL ) {
V_70 = F_74 ( V_71 , sizeof( struct V_69 * ) ) ;
if ( V_70 == NULL ) {
F_70 ( V_6 , false ) ;
return - V_41 ;
}
}
V_83 = F_86 ( V_6 -> V_11 . V_24 , V_71 ,
! V_6 -> V_11 . V_88 , V_70 ) ;
}
V_26 = false ;
if ( V_83 < 0 )
V_21 = V_83 , V_83 = 0 ;
else if ( V_83 < V_71 )
V_21 = F_82 ( V_6 , & V_26 ) ;
else
V_21 = F_67 ( V_6 , V_70 , V_71 ) ;
if ( V_21 ) {
F_70 ( V_6 , V_26 ) ;
F_79 ( V_70 , V_83 , 0 ) ;
}
F_80 ( V_70 ) ;
return V_21 ;
}
static void
F_87 ( struct V_5 * V_6 )
{
struct V_94 V_95 ;
F_88 ( V_6 -> V_11 . V_2 != NULL ) ;
F_70 ( V_6 , false ) ;
if ( V_6 -> V_96 != V_97 )
V_6 -> V_98 = 0 ;
F_89 ( V_6 ) ;
F_90 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_69 * V_69 = F_91 ( & V_95 ) ;
if ( V_6 -> V_98 )
F_92 ( V_69 ) ;
F_93 ( V_69 ) ;
F_94 ( V_69 ) ;
}
V_6 -> V_98 = 0 ;
F_69 ( V_6 -> V_12 ) ;
F_27 ( V_6 -> V_12 ) ;
}
static void
F_95 ( struct V_5 * V_6 )
{
F_36 ( V_6 ) ;
F_59 ( V_6 ) ;
}
static int
F_96 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 . V_50 )
return 0 ;
return F_41 ( V_6 , 0 ) ;
}
int
F_97 ( struct V_7 * V_8 , void * V_99 , struct V_100 * V_101 )
{
struct V_102 * args = V_99 ;
struct V_5 * V_6 ;
int V_21 ;
T_1 V_103 ;
if ( args -> V_54 & ~ ( V_104 |
V_55 ) )
return - V_58 ;
if ( F_98 ( args -> V_105 | args -> V_106 ) )
return - V_58 ;
if ( ! F_99 ( args -> V_54 & V_104 ? V_107 : V_108 ,
( char V_109 * ) ( unsigned long ) args -> V_105 , args -> V_106 ) )
return - V_110 ;
if ( args -> V_54 & V_104 ) {
return - V_59 ;
}
V_6 = F_100 ( V_8 ) ;
if ( V_6 == NULL )
return - V_41 ;
F_101 ( V_8 , & V_6 -> V_9 , args -> V_106 ) ;
F_102 ( V_6 , & V_111 ) ;
V_6 -> V_112 = V_113 ;
V_6 -> V_9 . V_114 = V_115 ;
V_6 -> V_9 . V_116 = V_115 ;
V_6 -> V_11 . V_24 = args -> V_105 ;
V_6 -> V_11 . V_88 = ! ! ( args -> V_54 & V_104 ) ;
V_21 = F_50 ( V_6 ) ;
if ( V_21 == 0 )
V_21 = F_41 ( V_6 , args -> V_54 ) ;
if ( V_21 == 0 )
V_21 = F_103 ( V_101 , & V_6 -> V_9 , & V_103 ) ;
F_104 ( & V_6 -> V_9 ) ;
if ( V_21 )
return V_21 ;
args -> V_103 = V_103 ;
return 0 ;
}
int
F_105 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_5 ( V_8 ) ;
F_106 ( & V_14 -> V_53 ) ;
F_107 ( V_14 -> V_65 ) ;
return 0 ;
}
