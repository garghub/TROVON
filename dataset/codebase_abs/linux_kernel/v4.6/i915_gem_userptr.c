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
F_6 (vma, tmp, &obj->vma_list, obj_link) {
int V_21 = F_7 ( V_16 ) ;
F_8 ( V_21 && V_21 != - V_22 ) ;
}
F_8 ( F_9 ( V_6 ) ) ;
V_14 -> V_19 . V_20 = V_18 ;
}
F_10 ( & V_6 -> V_9 ) ;
F_11 ( & V_8 -> V_10 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
if ( V_4 -> V_23 )
return;
F_13 ( & V_4 -> V_24 , & V_4 -> V_25 -> V_26 ) ;
V_4 -> V_23 = true ;
}
static void F_14 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_23 )
return;
F_15 ( & V_4 -> V_24 , & V_4 -> V_25 -> V_26 ) ;
V_4 -> V_23 = false ;
}
static void F_16 ( struct V_27 * V_28 ,
struct V_29 * V_19 ,
unsigned long V_30 ,
unsigned long V_31 )
{
struct V_32 * V_25 =
F_2 ( V_28 , struct V_32 , V_25 ) ;
struct V_3 * V_4 ;
struct V_33 * V_24 ;
F_17 ( V_34 ) ;
if ( F_18 ( & V_25 -> V_26 ) )
return;
V_31 -- ;
F_19 ( & V_25 -> V_35 ) ;
V_24 = F_20 ( & V_25 -> V_26 , V_30 , V_31 ) ;
while ( V_24 ) {
V_4 = F_2 ( V_24 , struct V_3 , V_24 ) ;
if ( F_21 ( & V_4 -> V_6 -> V_9 . V_36 ) )
F_22 ( & V_4 -> V_2 ) ;
F_23 ( & V_4 -> V_37 , & V_34 ) ;
V_24 = F_24 ( V_24 , V_30 , V_31 ) ;
}
F_25 (mo, &cancelled, link)
F_14 ( V_4 ) ;
F_26 ( & V_25 -> V_35 ) ;
}
static struct V_32 *
F_27 ( struct V_29 * V_19 )
{
struct V_32 * V_25 ;
int V_21 ;
V_25 = F_28 ( sizeof( * V_25 ) , V_38 ) ;
if ( V_25 == NULL )
return F_29 ( - V_39 ) ;
F_30 ( & V_25 -> V_35 ) ;
V_25 -> V_25 . V_40 = & V_41 ;
V_25 -> V_26 = V_42 ;
V_21 = F_31 ( & V_25 -> V_25 , V_19 ) ;
if ( V_21 ) {
F_32 ( V_25 ) ;
return F_29 ( V_21 ) ;
}
return V_25 ;
}
static void
F_33 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_11 . V_43 ;
if ( V_4 == NULL )
return;
F_19 ( & V_4 -> V_25 -> V_35 ) ;
F_14 ( V_4 ) ;
F_26 ( & V_4 -> V_25 -> V_35 ) ;
F_32 ( V_4 ) ;
V_6 -> V_11 . V_43 = NULL ;
}
static struct V_32 *
F_34 ( struct V_44 * V_19 )
{
struct V_32 * V_25 = V_19 -> V_25 ;
V_25 = V_19 -> V_25 ;
if ( V_25 )
return V_25 ;
F_35 ( & V_19 -> V_19 -> V_45 ) ;
F_4 ( & F_5 ( V_19 -> V_8 ) -> V_46 ) ;
if ( ( V_25 = V_19 -> V_25 ) == NULL ) {
V_25 = F_27 ( V_19 -> V_19 ) ;
if ( ! F_36 ( V_25 ) )
V_19 -> V_25 = V_25 ;
}
F_11 ( & F_5 ( V_19 -> V_8 ) -> V_46 ) ;
F_37 ( & V_19 -> V_19 -> V_45 ) ;
return V_25 ;
}
static int
F_38 ( struct V_5 * V_6 ,
unsigned V_47 )
{
struct V_32 * V_25 ;
struct V_3 * V_4 ;
if ( V_47 & V_48 )
return F_39 ( V_49 ) ? 0 : - V_50 ;
if ( F_8 ( V_6 -> V_11 . V_19 == NULL ) )
return - V_51 ;
V_25 = F_34 ( V_6 -> V_11 . V_19 ) ;
if ( F_36 ( V_25 ) )
return F_40 ( V_25 ) ;
V_4 = F_41 ( sizeof( * V_4 ) , V_38 ) ;
if ( V_4 == NULL )
return - V_39 ;
V_4 -> V_25 = V_25 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_24 . V_30 = V_6 -> V_11 . V_52 ;
V_4 -> V_24 . V_53 = V_6 -> V_11 . V_52 + V_6 -> V_9 . V_54 - 1 ;
F_42 ( & V_4 -> V_2 , F_1 ) ;
V_6 -> V_11 . V_43 = V_4 ;
return 0 ;
}
static void
F_43 ( struct V_32 * V_25 ,
struct V_29 * V_19 )
{
if ( V_25 == NULL )
return;
F_44 ( & V_25 -> V_25 , V_19 ) ;
F_32 ( V_25 ) ;
}
static void
F_33 ( struct V_5 * V_6 )
{
}
static int
F_38 ( struct V_5 * V_6 ,
unsigned V_47 )
{
if ( ( V_47 & V_48 ) == 0 )
return - V_55 ;
if ( ! F_39 ( V_49 ) )
return - V_50 ;
return 0 ;
}
static void
F_43 ( struct V_32 * V_25 ,
struct V_29 * V_19 )
{
}
static struct V_44 *
F_45 ( struct V_13 * V_14 , struct V_29 * V_56 )
{
struct V_44 * V_19 ;
F_46 (dev_priv->mm_structs, mm, node, (unsigned long)real)
if ( V_19 -> V_19 == V_56 )
return V_19 ;
return NULL ;
}
static int
F_47 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = F_5 ( V_6 -> V_9 . V_8 ) ;
struct V_44 * V_19 ;
int V_21 = 0 ;
F_4 ( & V_14 -> V_46 ) ;
V_19 = F_45 ( V_14 , V_57 -> V_19 ) ;
if ( V_19 == NULL ) {
V_19 = F_28 ( sizeof( * V_19 ) , V_38 ) ;
if ( V_19 == NULL ) {
V_21 = - V_39 ;
goto V_58;
}
F_48 ( & V_19 -> V_59 ) ;
V_19 -> V_8 = V_6 -> V_9 . V_8 ;
V_19 -> V_19 = V_57 -> V_19 ;
F_49 ( & V_57 -> V_19 -> V_60 ) ;
V_19 -> V_25 = NULL ;
F_50 ( V_14 -> V_61 ,
& V_19 -> V_62 , ( unsigned long ) V_19 -> V_19 ) ;
} else
F_51 ( & V_19 -> V_59 ) ;
V_6 -> V_11 . V_19 = V_19 ;
V_58:
F_11 ( & V_14 -> V_46 ) ;
return V_21 ;
}
static void
F_52 ( struct V_1 * V_2 )
{
struct V_44 * V_19 = F_2 ( V_2 , F_3 ( * V_19 ) , V_2 ) ;
F_43 ( V_19 -> V_25 , V_19 -> V_19 ) ;
F_53 ( V_19 -> V_19 ) ;
F_32 ( V_19 ) ;
}
static void
F_54 ( struct V_59 * V_59 )
{
struct V_44 * V_19 = F_2 ( V_59 , F_3 ( * V_19 ) , V_59 ) ;
F_55 ( & V_19 -> V_62 ) ;
F_11 ( & F_5 ( V_19 -> V_8 ) -> V_46 ) ;
F_42 ( & V_19 -> V_2 , F_52 ) ;
F_22 ( & V_19 -> V_2 ) ;
}
static void
F_56 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 . V_19 == NULL )
return;
F_57 ( & V_6 -> V_11 . V_19 -> V_59 ,
F_54 ,
& F_5 ( V_6 -> V_9 . V_8 ) -> V_46 ) ;
V_6 -> V_11 . V_19 = NULL ;
}
static int
F_58 ( struct V_63 * * V_64 , struct V_65 * * V_66 , int V_67 )
{
struct V_68 * V_69 ;
int V_21 , V_70 ;
* V_64 = F_28 ( sizeof( * * V_64 ) , V_38 ) ;
if ( * V_64 == NULL )
return - V_39 ;
if ( F_59 () ) {
V_21 = F_60 ( * V_64 , V_67 , V_38 ) ;
if ( V_21 )
goto V_71;
F_61 ((*st)->sgl, sg, num_pages, n)
F_62 ( V_69 , V_66 [ V_70 ] , V_72 , 0 ) ;
} else {
V_21 = F_63 ( * V_64 , V_66 , V_67 ,
0 , V_67 << V_73 ,
V_38 ) ;
if ( V_21 )
goto V_71;
}
return 0 ;
V_71:
F_32 ( * V_64 ) ;
* V_64 = NULL ;
return V_21 ;
}
static int
F_64 ( struct V_5 * V_6 ,
struct V_65 * * V_66 , int V_67 )
{
int V_21 ;
V_21 = F_58 ( & V_6 -> V_12 , V_66 , V_67 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_65 ( V_6 ) ;
if ( V_21 ) {
F_66 ( V_6 -> V_12 ) ;
F_32 ( V_6 -> V_12 ) ;
V_6 -> V_12 = NULL ;
}
return V_21 ;
}
static int
F_67 ( struct V_5 * V_6 ,
bool V_74 )
{
int V_21 = 0 ;
#if F_68 ( V_75 )
if ( V_6 -> V_11 . V_43 == NULL )
return 0 ;
F_19 ( & V_6 -> V_11 . V_43 -> V_25 -> V_35 ) ;
if ( ! V_74 )
F_14 ( V_6 -> V_11 . V_43 ) ;
else if ( ! F_69 ( & V_6 -> V_11 . V_43 -> V_2 ) )
F_12 ( V_6 -> V_11 . V_43 ) ;
else
V_21 = - V_76 ;
F_26 ( & V_6 -> V_11 . V_43 -> V_25 -> V_35 ) ;
#endif
return V_21 ;
}
static void
F_70 ( struct V_1 * V_77 )
{
struct V_78 * V_2 = F_2 ( V_77 , F_3 ( * V_2 ) , V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 . V_8 ;
const int V_79 = V_6 -> V_9 . V_54 >> V_73 ;
struct V_65 * * V_66 ;
int V_80 , V_21 ;
V_21 = - V_39 ;
V_80 = 0 ;
V_66 = F_28 ( V_79 * sizeof( struct V_65 * ) ,
V_81 | V_82 | V_83 ) ;
if ( V_66 == NULL )
V_66 = F_71 ( V_79 , sizeof( struct V_65 * ) ) ;
if ( V_66 != NULL ) {
struct V_29 * V_19 = V_6 -> V_11 . V_19 -> V_19 ;
V_21 = - V_84 ;
if ( F_72 ( & V_19 -> V_85 ) ) {
F_73 ( & V_19 -> V_45 ) ;
while ( V_80 < V_79 ) {
V_21 = F_74
( V_2 -> V_86 , V_19 ,
V_6 -> V_11 . V_52 + V_80 * V_72 ,
V_79 - V_80 ,
! V_6 -> V_11 . V_87 , 0 ,
V_66 + V_80 , NULL ) ;
if ( V_21 < 0 )
break;
V_80 += V_21 ;
}
F_75 ( & V_19 -> V_45 ) ;
F_76 ( V_19 ) ;
}
}
F_4 ( & V_8 -> V_10 ) ;
if ( V_6 -> V_11 . V_2 == & V_2 -> V_2 ) {
if ( V_80 == V_79 ) {
V_21 = F_64 ( V_6 , V_66 , V_79 ) ;
if ( V_21 == 0 ) {
F_77 ( & V_6 -> V_88 ,
& F_5 ( V_8 ) -> V_19 . V_89 ) ;
V_6 -> V_90 . V_69 = V_6 -> V_12 -> V_91 ;
V_6 -> V_90 . V_53 = 0 ;
V_80 = 0 ;
}
}
V_6 -> V_11 . V_2 = F_29 ( V_21 ) ;
if ( V_21 )
F_67 ( V_6 , false ) ;
}
V_6 -> V_11 . V_92 -- ;
F_10 ( & V_6 -> V_9 ) ;
F_11 ( & V_8 -> V_10 ) ;
F_78 ( V_66 , V_80 , 0 ) ;
F_79 ( V_66 ) ;
F_80 ( V_2 -> V_86 ) ;
F_32 ( V_2 ) ;
}
static int
F_81 ( struct V_5 * V_6 ,
bool * V_93 )
{
struct V_78 * V_2 ;
if ( V_6 -> V_11 . V_92 >= V_94 )
return - V_76 ;
V_2 = F_28 ( sizeof( * V_2 ) , V_38 ) ;
if ( V_2 == NULL )
return - V_39 ;
V_6 -> V_11 . V_2 = & V_2 -> V_2 ;
V_6 -> V_11 . V_92 ++ ;
V_2 -> V_6 = V_6 ;
F_82 ( & V_6 -> V_9 ) ;
V_2 -> V_86 = V_57 ;
F_83 ( V_2 -> V_86 ) ;
F_42 ( & V_2 -> V_2 , F_70 ) ;
F_22 ( & V_2 -> V_2 ) ;
* V_93 = true ;
return - V_76 ;
}
static int
F_84 ( struct V_5 * V_6 )
{
const int V_67 = V_6 -> V_9 . V_54 >> V_73 ;
struct V_65 * * V_66 ;
int V_80 , V_21 ;
bool V_93 ;
if ( F_36 ( V_6 -> V_11 . V_2 ) ) {
V_21 = F_40 ( V_6 -> V_11 . V_2 ) ;
V_6 -> V_11 . V_2 = NULL ;
return V_21 ;
}
if ( V_6 -> V_11 . V_2 )
return - V_76 ;
V_21 = F_67 ( V_6 , true ) ;
if ( V_21 )
return V_21 ;
V_66 = NULL ;
V_80 = 0 ;
if ( V_6 -> V_11 . V_19 -> V_19 == V_57 -> V_19 ) {
V_66 = F_28 ( V_67 * sizeof( struct V_65 * ) ,
V_81 | V_82 | V_83 ) ;
if ( V_66 == NULL ) {
V_66 = F_71 ( V_67 , sizeof( struct V_65 * ) ) ;
if ( V_66 == NULL ) {
F_67 ( V_6 , false ) ;
return - V_39 ;
}
}
V_80 = F_85 ( V_6 -> V_11 . V_52 , V_67 ,
! V_6 -> V_11 . V_87 , V_66 ) ;
}
V_93 = false ;
if ( V_80 < 0 )
V_21 = V_80 , V_80 = 0 ;
else if ( V_80 < V_67 )
V_21 = F_81 ( V_6 , & V_93 ) ;
else
V_21 = F_64 ( V_6 , V_66 , V_67 ) ;
if ( V_21 ) {
F_67 ( V_6 , V_93 ) ;
F_78 ( V_66 , V_80 , 0 ) ;
}
F_79 ( V_66 ) ;
return V_21 ;
}
static void
F_86 ( struct V_5 * V_6 )
{
struct V_95 V_96 ;
F_87 ( V_6 -> V_11 . V_2 != NULL ) ;
F_67 ( V_6 , false ) ;
if ( V_6 -> V_97 != V_98 )
V_6 -> V_99 = 0 ;
F_88 ( V_6 ) ;
F_89 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_65 * V_65 = F_90 ( & V_96 ) ;
if ( V_6 -> V_99 )
F_91 ( V_65 ) ;
F_92 ( V_65 ) ;
F_93 ( V_65 ) ;
}
V_6 -> V_99 = 0 ;
F_66 ( V_6 -> V_12 ) ;
F_32 ( V_6 -> V_12 ) ;
}
static void
F_94 ( struct V_5 * V_6 )
{
F_33 ( V_6 ) ;
F_56 ( V_6 ) ;
}
static int
F_95 ( struct V_5 * V_6 )
{
if ( V_6 -> V_11 . V_43 )
return 0 ;
return F_38 ( V_6 , 0 ) ;
}
int
F_96 ( struct V_7 * V_8 , void * V_100 , struct V_101 * V_102 )
{
struct V_103 * args = V_100 ;
struct V_5 * V_6 ;
int V_21 ;
T_1 V_104 ;
if ( args -> V_47 & ~ ( V_105 |
V_48 ) )
return - V_51 ;
if ( F_97 ( args -> V_106 | args -> V_107 ) )
return - V_51 ;
if ( ! F_98 ( args -> V_47 & V_105 ? V_108 : V_109 ,
( char V_110 * ) ( unsigned long ) args -> V_106 , args -> V_107 ) )
return - V_84 ;
if ( args -> V_47 & V_105 ) {
return - V_55 ;
}
V_6 = F_99 ( V_8 ) ;
if ( V_6 == NULL )
return - V_39 ;
F_100 ( V_8 , & V_6 -> V_9 , args -> V_107 ) ;
F_101 ( V_6 , & V_111 ) ;
V_6 -> V_112 = V_113 ;
V_6 -> V_9 . V_114 = V_115 ;
V_6 -> V_9 . V_116 = V_115 ;
V_6 -> V_11 . V_52 = args -> V_106 ;
V_6 -> V_11 . V_87 = ! ! ( args -> V_47 & V_105 ) ;
V_21 = F_47 ( V_6 ) ;
if ( V_21 == 0 )
V_21 = F_38 ( V_6 , args -> V_47 ) ;
if ( V_21 == 0 )
V_21 = F_102 ( V_102 , & V_6 -> V_9 , & V_104 ) ;
F_103 ( & V_6 -> V_9 ) ;
if ( V_21 )
return V_21 ;
args -> V_104 = V_104 ;
return 0 ;
}
int
F_104 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_5 ( V_8 ) ;
F_105 ( & V_14 -> V_46 ) ;
F_106 ( V_14 -> V_61 ) ;
return 0 ;
}
