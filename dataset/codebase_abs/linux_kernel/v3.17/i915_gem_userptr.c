static unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
unsigned long V_6 ;
F_2 ( & V_4 -> V_7 ) ;
V_2 -> V_8 . V_9 = NULL ;
if ( V_2 -> V_10 != NULL ) {
struct V_11 * V_12 = F_3 ( V_4 ) ;
struct V_13 * V_14 , * V_15 ;
bool V_16 ;
V_16 = V_12 -> V_17 . V_18 ;
V_12 -> V_17 . V_18 = false ;
F_4 (vma, tmp, &obj->vma_list, vma_link) {
int V_19 = F_5 ( V_14 ) ;
F_6 ( V_19 && V_19 != - V_20 ) ;
}
F_6 ( F_7 ( V_2 ) ) ;
V_12 -> V_17 . V_18 = V_16 ;
}
V_6 = V_2 -> V_8 . V_21 + V_2 -> V_5 . V_22 ;
F_8 ( & V_2 -> V_5 ) ;
F_9 ( & V_4 -> V_7 ) ;
return V_6 ;
}
static void * F_10 ( struct V_23 * V_24 ,
struct V_25 * V_17 ,
unsigned long V_26 ,
unsigned long V_6 )
{
struct V_27 * V_28 ;
unsigned long V_29 ;
V_30:
V_29 = V_24 -> V_29 ;
F_11 (mo, &mn->linear, link) {
struct V_1 * V_2 ;
if ( V_28 -> V_31 . V_32 < V_26 || V_28 -> V_31 . V_26 > V_6 )
continue;
V_2 = V_28 -> V_2 ;
F_12 ( & V_2 -> V_5 ) ;
F_13 ( & V_24 -> V_33 ) ;
F_1 ( V_2 ) ;
F_14 ( & V_24 -> V_33 ) ;
if ( V_29 != V_24 -> V_29 )
goto V_30;
}
return NULL ;
}
static void F_15 ( struct V_34 * V_35 ,
struct V_25 * V_17 ,
unsigned long V_26 ,
unsigned long V_6 )
{
struct V_23 * V_24 = F_16 ( V_35 , struct V_23 , V_24 ) ;
struct V_36 * V_31 = NULL ;
unsigned long V_37 = V_26 ;
unsigned long V_29 = 0 ;
V_6 -- ;
while ( V_37 < V_6 ) {
struct V_1 * V_2 = NULL ;
F_14 ( & V_24 -> V_33 ) ;
if ( V_24 -> V_38 )
V_31 = F_10 ( V_24 , V_17 , V_26 , V_6 ) ;
else if ( V_29 == V_24 -> V_29 )
V_31 = F_17 ( V_31 , V_37 , V_6 ) ;
else
V_31 = F_18 ( & V_24 -> V_39 , V_26 , V_6 ) ;
if ( V_31 != NULL ) {
V_2 = F_16 ( V_31 , struct V_27 , V_31 ) -> V_2 ;
F_12 ( & V_2 -> V_5 ) ;
V_29 = V_24 -> V_29 ;
}
F_13 ( & V_24 -> V_33 ) ;
if ( V_2 == NULL )
return;
V_37 = F_1 ( V_2 ) ;
}
}
static struct V_23 *
F_19 ( struct V_25 * V_17 )
{
struct V_23 * V_24 ;
int V_19 ;
V_24 = F_20 ( sizeof( * V_24 ) , V_40 ) ;
if ( V_24 == NULL )
return F_21 ( - V_41 ) ;
F_22 ( & V_24 -> V_33 ) ;
V_24 -> V_24 . V_42 = & V_43 ;
V_24 -> V_39 = V_44 ;
V_24 -> V_29 = 1 ;
F_23 ( & V_24 -> V_45 ) ;
V_24 -> V_38 = false ;
V_19 = F_24 ( & V_24 -> V_24 , V_17 ) ;
if ( V_19 ) {
F_25 ( V_24 ) ;
return F_21 ( V_19 ) ;
}
return V_24 ;
}
static void F_26 ( struct V_23 * V_24 )
{
if ( ++ V_24 -> V_29 == 0 )
V_24 -> V_29 = 1 ;
}
static int
F_27 ( struct V_3 * V_4 ,
struct V_23 * V_24 ,
struct V_27 * V_28 )
{
struct V_36 * V_31 ;
int V_19 ;
V_19 = F_28 ( V_4 ) ;
if ( V_19 )
return V_19 ;
F_29 ( V_4 ) ;
F_14 ( & V_24 -> V_33 ) ;
V_31 = F_18 ( & V_24 -> V_39 ,
V_28 -> V_31 . V_26 , V_28 -> V_31 . V_32 ) ;
if ( V_31 ) {
struct V_1 * V_2 ;
V_2 = F_16 ( V_31 , struct V_27 , V_31 ) -> V_2 ;
if ( ! V_2 -> V_8 . V_46 )
V_24 -> V_38 = V_28 -> V_47 = true ;
else
V_19 = - V_48 ;
} else
F_30 ( & V_28 -> V_31 , & V_24 -> V_39 ) ;
if ( V_19 == 0 ) {
F_31 ( & V_28 -> V_49 , & V_24 -> V_45 ) ;
F_26 ( V_24 ) ;
}
F_13 ( & V_24 -> V_33 ) ;
F_9 ( & V_4 -> V_7 ) ;
return V_19 ;
}
static bool F_32 ( struct V_23 * V_24 )
{
struct V_27 * V_28 ;
F_11 (mo, &mn->linear, link)
if ( V_28 -> V_47 )
return true ;
return false ;
}
static void
F_33 ( struct V_23 * V_24 ,
struct V_27 * V_28 )
{
F_14 ( & V_24 -> V_33 ) ;
F_34 ( & V_28 -> V_49 ) ;
if ( V_28 -> V_47 )
V_24 -> V_38 = F_32 ( V_24 ) ;
else
F_35 ( & V_28 -> V_31 , & V_24 -> V_39 ) ;
F_26 ( V_24 ) ;
F_13 ( & V_24 -> V_33 ) ;
}
static void
F_36 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
V_28 = V_2 -> V_8 . V_50 ;
if ( V_28 == NULL )
return;
F_33 ( V_28 -> V_24 , V_28 ) ;
F_25 ( V_28 ) ;
V_2 -> V_8 . V_50 = NULL ;
}
static struct V_23 *
F_37 ( struct V_51 * V_17 )
{
if ( V_17 -> V_24 == NULL ) {
F_38 ( & V_17 -> V_17 -> V_52 ) ;
F_2 ( & F_3 ( V_17 -> V_4 ) -> V_53 ) ;
if ( V_17 -> V_24 == NULL )
V_17 -> V_24 = F_19 ( V_17 -> V_17 ) ;
F_9 ( & F_3 ( V_17 -> V_4 ) -> V_53 ) ;
F_39 ( & V_17 -> V_17 -> V_52 ) ;
}
return V_17 -> V_24 ;
}
static int
F_40 ( struct V_1 * V_2 ,
unsigned V_54 )
{
struct V_23 * V_24 ;
struct V_27 * V_28 ;
int V_19 ;
if ( V_54 & V_55 )
return F_41 ( V_56 ) ? 0 : - V_57 ;
if ( F_6 ( V_2 -> V_8 . V_17 == NULL ) )
return - V_58 ;
V_24 = F_37 ( V_2 -> V_8 . V_17 ) ;
if ( F_42 ( V_24 ) )
return F_43 ( V_24 ) ;
V_28 = F_44 ( sizeof( * V_28 ) , V_40 ) ;
if ( V_28 == NULL )
return - V_41 ;
V_28 -> V_24 = V_24 ;
V_28 -> V_31 . V_26 = V_2 -> V_8 . V_21 ;
V_28 -> V_31 . V_32 = V_28 -> V_31 . V_26 + V_2 -> V_5 . V_22 - 1 ;
V_28 -> V_2 = V_2 ;
V_19 = F_27 ( V_2 -> V_5 . V_4 , V_24 , V_28 ) ;
if ( V_19 ) {
F_25 ( V_28 ) ;
return V_19 ;
}
V_2 -> V_8 . V_50 = V_28 ;
return 0 ;
}
static void
F_45 ( struct V_23 * V_24 ,
struct V_25 * V_17 )
{
if ( V_24 == NULL )
return;
F_46 ( & V_24 -> V_24 , V_17 ) ;
F_25 ( V_24 ) ;
}
static void
F_36 ( struct V_1 * V_2 )
{
}
static int
F_40 ( struct V_1 * V_2 ,
unsigned V_54 )
{
if ( ( V_54 & V_55 ) == 0 )
return - V_59 ;
if ( ! F_41 ( V_56 ) )
return - V_57 ;
return 0 ;
}
static void
F_45 ( struct V_23 * V_24 ,
struct V_25 * V_17 )
{
}
static struct V_51 *
F_47 ( struct V_11 * V_12 , struct V_25 * V_60 )
{
struct V_51 * V_17 ;
F_48 (dev_priv->mm_structs, mm, node, (unsigned long)real)
if ( V_17 -> V_17 == V_60 )
return V_17 ;
return NULL ;
}
static int
F_49 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_5 . V_4 ) ;
struct V_51 * V_17 ;
int V_19 = 0 ;
F_2 ( & V_12 -> V_53 ) ;
V_17 = F_47 ( V_12 , V_61 -> V_17 ) ;
if ( V_17 == NULL ) {
V_17 = F_20 ( sizeof( * V_17 ) , V_40 ) ;
if ( V_17 == NULL ) {
V_19 = - V_41 ;
goto V_62;
}
F_50 ( & V_17 -> V_63 ) ;
V_17 -> V_4 = V_2 -> V_5 . V_4 ;
V_17 -> V_17 = V_61 -> V_17 ;
F_51 ( & V_61 -> V_17 -> V_64 ) ;
V_17 -> V_24 = NULL ;
F_52 ( V_12 -> V_65 ,
& V_17 -> V_66 , ( unsigned long ) V_17 -> V_17 ) ;
} else
F_53 ( & V_17 -> V_63 ) ;
V_2 -> V_8 . V_17 = V_17 ;
V_62:
F_9 ( & V_12 -> V_53 ) ;
return V_19 ;
}
static void
F_54 ( struct V_67 * V_9 )
{
struct V_51 * V_17 = F_16 ( V_9 , F_55 ( * V_17 ) , V_9 ) ;
F_45 ( V_17 -> V_24 , V_17 -> V_17 ) ;
F_56 ( V_17 -> V_17 ) ;
F_25 ( V_17 ) ;
}
static void
F_57 ( struct V_63 * V_63 )
{
struct V_51 * V_17 = F_16 ( V_63 , F_55 ( * V_17 ) , V_63 ) ;
F_58 ( & V_17 -> V_66 ) ;
F_9 ( & F_3 ( V_17 -> V_4 ) -> V_53 ) ;
F_59 ( & V_17 -> V_9 , F_54 ) ;
F_60 ( & V_17 -> V_9 ) ;
}
static void
F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_17 == NULL )
return;
F_62 ( & V_2 -> V_8 . V_17 -> V_63 ,
F_57 ,
& F_3 ( V_2 -> V_5 . V_4 ) -> V_53 ) ;
V_2 -> V_8 . V_17 = NULL ;
}
static int
F_63 ( struct V_68 * * V_69 , struct V_70 * * V_71 , int V_72 )
{
struct V_73 * V_74 ;
int V_19 , V_75 ;
* V_69 = F_20 ( sizeof( * * V_69 ) , V_40 ) ;
if ( * V_69 == NULL )
return - V_41 ;
if ( F_64 () ) {
V_19 = F_65 ( * V_69 , V_72 , V_40 ) ;
if ( V_19 )
goto V_76;
F_66 ((*st)->sgl, sg, num_pages, n)
F_67 ( V_74 , V_71 [ V_75 ] , V_77 , 0 ) ;
} else {
V_19 = F_68 ( * V_69 , V_71 , V_72 ,
0 , V_72 << V_78 ,
V_40 ) ;
if ( V_19 )
goto V_76;
}
return 0 ;
V_76:
F_25 ( * V_69 ) ;
* V_69 = NULL ;
return V_19 ;
}
static void
F_69 ( struct V_67 * V_79 )
{
struct V_80 * V_9 = F_16 ( V_79 , F_55 ( * V_9 ) , V_9 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
const int V_72 = V_2 -> V_5 . V_22 >> V_78 ;
struct V_70 * * V_71 ;
int V_81 , V_19 ;
V_19 = - V_41 ;
V_81 = 0 ;
V_71 = F_20 ( V_72 * sizeof( struct V_70 * ) ,
V_82 | V_83 | V_84 ) ;
if ( V_71 == NULL )
V_71 = F_70 ( V_72 , sizeof( struct V_70 * ) ) ;
if ( V_71 != NULL ) {
struct V_25 * V_17 = V_2 -> V_8 . V_17 -> V_17 ;
F_71 ( & V_17 -> V_52 ) ;
while ( V_81 < V_72 ) {
V_19 = F_72 ( V_9 -> V_85 , V_17 ,
V_2 -> V_8 . V_21 + V_81 * V_77 ,
V_72 - V_81 ,
! V_2 -> V_8 . V_86 , 0 ,
V_71 + V_81 , NULL ) ;
if ( V_19 < 0 )
break;
V_81 += V_19 ;
}
F_73 ( & V_17 -> V_52 ) ;
}
F_2 ( & V_4 -> V_7 ) ;
if ( V_2 -> V_8 . V_9 != & V_9 -> V_9 ) {
V_19 = 0 ;
} else if ( V_81 == V_72 ) {
V_19 = F_63 ( & V_2 -> V_10 , V_71 , V_72 ) ;
if ( V_19 == 0 ) {
F_74 ( & V_2 -> V_87 , & F_3 ( V_4 ) -> V_17 . V_88 ) ;
V_81 = 0 ;
}
}
V_2 -> V_8 . V_9 = F_21 ( V_19 ) ;
V_2 -> V_8 . V_46 -- ;
F_8 ( & V_2 -> V_5 ) ;
F_9 ( & V_4 -> V_7 ) ;
F_75 ( V_71 , V_81 , 0 ) ;
F_76 ( V_71 ) ;
F_77 ( V_9 -> V_85 ) ;
F_25 ( V_9 ) ;
}
static int
F_78 ( struct V_1 * V_2 )
{
const int V_72 = V_2 -> V_5 . V_22 >> V_78 ;
struct V_70 * * V_71 ;
int V_81 , V_19 ;
V_71 = NULL ;
V_81 = 0 ;
if ( V_2 -> V_8 . V_17 -> V_17 == V_61 -> V_17 ) {
V_71 = F_20 ( V_72 * sizeof( struct V_70 * ) ,
V_82 | V_83 | V_84 ) ;
if ( V_71 == NULL ) {
V_71 = F_70 ( V_72 , sizeof( struct V_70 * ) ) ;
if ( V_71 == NULL )
return - V_41 ;
}
V_81 = F_79 ( V_2 -> V_8 . V_21 , V_72 ,
! V_2 -> V_8 . V_86 , V_71 ) ;
}
if ( V_81 < V_72 ) {
if ( V_81 < 0 ) {
V_19 = V_81 ;
V_81 = 0 ;
} else {
V_19 = - V_48 ;
if ( V_2 -> V_8 . V_9 == NULL &&
V_2 -> V_8 . V_46 < V_89 ) {
struct V_80 * V_9 ;
V_9 = F_20 ( sizeof( * V_9 ) , V_40 ) ;
if ( V_9 != NULL ) {
V_2 -> V_8 . V_9 = & V_9 -> V_9 ;
V_2 -> V_8 . V_46 ++ ;
V_9 -> V_2 = V_2 ;
F_12 ( & V_2 -> V_5 ) ;
V_9 -> V_85 = V_61 ;
F_80 ( V_9 -> V_85 ) ;
F_59 ( & V_9 -> V_9 , F_69 ) ;
F_60 ( & V_9 -> V_9 ) ;
} else
V_19 = - V_41 ;
} else {
if ( F_42 ( V_2 -> V_8 . V_9 ) ) {
V_19 = F_43 ( V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_9 = NULL ;
}
}
}
} else {
V_19 = F_63 ( & V_2 -> V_10 , V_71 , V_72 ) ;
if ( V_19 == 0 ) {
V_2 -> V_8 . V_9 = NULL ;
V_81 = 0 ;
}
}
F_75 ( V_71 , V_81 , 0 ) ;
F_76 ( V_71 ) ;
return V_19 ;
}
static void
F_81 ( struct V_1 * V_2 )
{
struct V_73 * V_74 ;
int V_90 ;
F_82 ( V_2 -> V_8 . V_9 != NULL ) ;
if ( V_2 -> V_91 != V_92 )
V_2 -> V_93 = 0 ;
F_66 (obj->pages->sgl, sg, obj->pages->nents, i) {
struct V_70 * V_70 = F_83 ( V_74 ) ;
if ( V_2 -> V_93 )
F_84 ( V_70 ) ;
F_85 ( V_70 ) ;
F_86 ( V_70 ) ;
}
V_2 -> V_93 = 0 ;
F_87 ( V_2 -> V_10 ) ;
F_25 ( V_2 -> V_10 ) ;
}
static void
F_88 ( struct V_1 * V_2 )
{
F_36 ( V_2 ) ;
F_61 ( V_2 ) ;
}
static int
F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 . V_50 )
return 0 ;
return F_40 ( V_2 , 0 ) ;
}
int
F_90 ( struct V_3 * V_4 , void * V_94 , struct V_95 * V_96 )
{
struct V_11 * V_12 = V_4 -> V_97 ;
struct V_98 * args = V_94 ;
struct V_1 * V_2 ;
int V_19 ;
T_1 V_99 ;
if ( args -> V_54 & ~ ( V_100 |
V_55 ) )
return - V_58 ;
if ( F_91 ( args -> V_101 | args -> V_102 ) )
return - V_58 ;
if ( args -> V_102 > V_12 -> V_103 . V_5 . V_104 )
return - V_105 ;
if ( ! F_92 ( args -> V_54 & V_100 ? V_106 : V_107 ,
( char V_108 * ) ( unsigned long ) args -> V_101 , args -> V_102 ) )
return - V_109 ;
if ( args -> V_54 & V_100 ) {
return - V_59 ;
}
V_2 = F_93 ( V_4 ) ;
if ( V_2 == NULL )
return - V_41 ;
F_94 ( V_4 , & V_2 -> V_5 , args -> V_102 ) ;
F_95 ( V_2 , & V_110 ) ;
V_2 -> V_111 = V_112 ;
V_2 -> V_5 . V_113 = V_114 ;
V_2 -> V_5 . V_115 = V_114 ;
V_2 -> V_8 . V_21 = args -> V_101 ;
V_2 -> V_8 . V_86 = ! ! ( args -> V_54 & V_100 ) ;
V_19 = F_49 ( V_2 ) ;
if ( V_19 == 0 )
V_19 = F_40 ( V_2 , args -> V_54 ) ;
if ( V_19 == 0 )
V_19 = F_96 ( V_96 , & V_2 -> V_5 , & V_99 ) ;
F_97 ( & V_2 -> V_5 ) ;
if ( V_19 )
return V_19 ;
args -> V_99 = V_99 ;
return 0 ;
}
int
F_98 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = F_3 ( V_4 ) ;
F_99 ( & V_12 -> V_53 ) ;
F_100 ( V_12 -> V_65 ) ;
return 0 ;
}
