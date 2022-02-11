static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_6 * V_7 [ V_8 ] ;
int V_9 , V_10 ;
if ( ! V_2 -> V_11 )
return;
V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
struct V_6 * V_12 ;
V_12 = V_2 -> V_13 [ V_9 ] ;
if ( V_12 == NULL )
continue;
V_7 [ V_10 ++ ] = F_2 ( V_12 ) ;
}
F_3 ( & V_4 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_4 ( V_7 [ V_9 ] , false , NULL , NULL ) ;
F_5 ( & V_4 -> V_14 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_6 ( V_7 [ V_9 ] ) ;
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_8 ( V_16 , F_9 ( * V_18 ) , V_16 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
F_5 ( & V_4 -> V_14 ) ;
V_2 -> V_19 . V_16 = NULL ;
if ( V_2 -> V_20 != NULL ) {
struct V_21 * V_22 = F_10 ( V_4 ) ;
struct V_23 * V_24 , * V_25 ;
bool V_26 ;
F_1 ( V_2 ) ;
V_26 = V_22 -> V_27 . V_28 ;
V_22 -> V_27 . V_28 = false ;
F_11 (vma, tmp, &obj->vma_list, obj_link)
F_12 ( F_13 ( V_24 ) ) ;
F_12 ( F_14 ( V_2 ) ) ;
V_22 -> V_27 . V_28 = V_26 ;
}
F_15 ( & V_2 -> V_5 ) ;
F_3 ( & V_4 -> V_14 ) ;
}
static void F_16 ( struct V_17 * V_18 )
{
if ( V_18 -> V_29 )
return;
F_17 ( & V_18 -> V_30 , & V_18 -> V_31 -> V_32 ) ;
V_18 -> V_29 = true ;
}
static void F_18 ( struct V_17 * V_18 )
{
if ( ! V_18 -> V_29 )
return;
F_19 ( & V_18 -> V_30 , & V_18 -> V_31 -> V_32 ) ;
V_18 -> V_29 = false ;
}
static void F_20 ( struct V_33 * V_34 ,
struct V_35 * V_27 ,
unsigned long V_36 ,
unsigned long V_37 )
{
struct V_38 * V_31 =
F_8 ( V_34 , struct V_38 , V_31 ) ;
struct V_17 * V_18 ;
struct V_39 * V_30 ;
F_21 ( V_40 ) ;
if ( F_22 ( & V_31 -> V_32 ) )
return;
V_37 -- ;
F_23 ( & V_31 -> V_41 ) ;
V_30 = F_24 ( & V_31 -> V_32 , V_36 , V_37 ) ;
while ( V_30 ) {
V_18 = F_8 ( V_30 , struct V_17 , V_30 ) ;
if ( F_25 ( & V_18 -> V_2 -> V_5 . V_42 ) )
F_26 ( V_31 -> V_43 , & V_18 -> V_16 ) ;
F_27 ( & V_18 -> V_44 , & V_40 ) ;
V_30 = F_28 ( V_30 , V_36 , V_37 ) ;
}
F_29 (mo, &cancelled, link)
F_18 ( V_18 ) ;
F_30 ( & V_31 -> V_41 ) ;
F_31 ( V_31 -> V_43 ) ;
}
static struct V_38 *
F_32 ( struct V_35 * V_27 )
{
struct V_38 * V_31 ;
int V_45 ;
V_31 = F_33 ( sizeof( * V_31 ) , V_46 ) ;
if ( V_31 == NULL )
return F_34 ( - V_47 ) ;
F_35 ( & V_31 -> V_41 ) ;
V_31 -> V_31 . V_48 = & V_49 ;
V_31 -> V_32 = V_50 ;
V_31 -> V_43 = F_36 ( L_1 , V_51 , 0 ) ;
if ( V_31 -> V_43 == NULL ) {
F_37 ( V_31 ) ;
return F_34 ( - V_47 ) ;
}
V_45 = F_38 ( & V_31 -> V_31 , V_27 ) ;
if ( V_45 ) {
F_39 ( V_31 -> V_43 ) ;
F_37 ( V_31 ) ;
return F_34 ( V_45 ) ;
}
return V_31 ;
}
static void
F_40 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
V_18 = V_2 -> V_19 . V_52 ;
if ( V_18 == NULL )
return;
F_23 ( & V_18 -> V_31 -> V_41 ) ;
F_18 ( V_18 ) ;
F_30 ( & V_18 -> V_31 -> V_41 ) ;
F_37 ( V_18 ) ;
V_2 -> V_19 . V_52 = NULL ;
}
static struct V_38 *
F_41 ( struct V_53 * V_27 )
{
struct V_38 * V_31 = V_27 -> V_31 ;
V_31 = V_27 -> V_31 ;
if ( V_31 )
return V_31 ;
F_42 ( & V_27 -> V_27 -> V_54 ) ;
F_5 ( & V_27 -> V_55 -> V_56 ) ;
if ( ( V_31 = V_27 -> V_31 ) == NULL ) {
V_31 = F_32 ( V_27 -> V_27 ) ;
if ( ! F_43 ( V_31 ) )
V_27 -> V_31 = V_31 ;
}
F_3 ( & V_27 -> V_55 -> V_56 ) ;
F_44 ( & V_27 -> V_27 -> V_54 ) ;
return V_31 ;
}
static int
F_45 ( struct V_1 * V_2 ,
unsigned V_57 )
{
struct V_38 * V_31 ;
struct V_17 * V_18 ;
if ( V_57 & V_58 )
return F_46 ( V_59 ) ? 0 : - V_60 ;
if ( F_12 ( V_2 -> V_19 . V_27 == NULL ) )
return - V_61 ;
V_31 = F_41 ( V_2 -> V_19 . V_27 ) ;
if ( F_43 ( V_31 ) )
return F_47 ( V_31 ) ;
V_18 = F_48 ( sizeof( * V_18 ) , V_46 ) ;
if ( V_18 == NULL )
return - V_47 ;
V_18 -> V_31 = V_31 ;
V_18 -> V_2 = V_2 ;
V_18 -> V_30 . V_36 = V_2 -> V_19 . V_62 ;
V_18 -> V_30 . V_63 = V_2 -> V_19 . V_62 + V_2 -> V_5 . V_64 - 1 ;
F_49 ( & V_18 -> V_16 , F_7 ) ;
V_2 -> V_19 . V_52 = V_18 ;
return 0 ;
}
static void
F_50 ( struct V_38 * V_31 ,
struct V_35 * V_27 )
{
if ( V_31 == NULL )
return;
F_51 ( & V_31 -> V_31 , V_27 ) ;
F_39 ( V_31 -> V_43 ) ;
F_37 ( V_31 ) ;
}
static void
F_40 ( struct V_1 * V_2 )
{
}
static int
F_45 ( struct V_1 * V_2 ,
unsigned V_57 )
{
if ( ( V_57 & V_58 ) == 0 )
return - V_65 ;
if ( ! F_46 ( V_59 ) )
return - V_60 ;
return 0 ;
}
static void
F_50 ( struct V_38 * V_31 ,
struct V_35 * V_27 )
{
}
static struct V_53 *
F_52 ( struct V_21 * V_22 , struct V_35 * V_66 )
{
struct V_53 * V_27 ;
F_53 (dev_priv->mm_structs, mm, node, (unsigned long)real)
if ( V_27 -> V_27 == V_66 )
return V_27 ;
return NULL ;
}
static int
F_54 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_10 ( V_2 -> V_5 . V_4 ) ;
struct V_53 * V_27 ;
int V_45 = 0 ;
F_5 ( & V_22 -> V_56 ) ;
V_27 = F_52 ( V_22 , V_67 -> V_27 ) ;
if ( V_27 == NULL ) {
V_27 = F_33 ( sizeof( * V_27 ) , V_46 ) ;
if ( V_27 == NULL ) {
V_45 = - V_47 ;
goto V_68;
}
F_55 ( & V_27 -> V_69 ) ;
V_27 -> V_55 = F_10 ( V_2 -> V_5 . V_4 ) ;
V_27 -> V_27 = V_67 -> V_27 ;
F_56 ( & V_67 -> V_27 -> V_70 ) ;
V_27 -> V_31 = NULL ;
F_57 ( V_22 -> V_71 ,
& V_27 -> V_72 , ( unsigned long ) V_27 -> V_27 ) ;
} else
F_58 ( & V_27 -> V_69 ) ;
V_2 -> V_19 . V_27 = V_27 ;
V_68:
F_3 ( & V_22 -> V_56 ) ;
return V_45 ;
}
static void
F_59 ( struct V_15 * V_16 )
{
struct V_53 * V_27 = F_8 ( V_16 , F_9 ( * V_27 ) , V_16 ) ;
F_50 ( V_27 -> V_31 , V_27 -> V_27 ) ;
F_60 ( V_27 -> V_27 ) ;
F_37 ( V_27 ) ;
}
static void
F_61 ( struct V_69 * V_69 )
{
struct V_53 * V_27 = F_8 ( V_69 , F_9 ( * V_27 ) , V_69 ) ;
F_62 ( & V_27 -> V_72 ) ;
F_3 ( & V_27 -> V_55 -> V_56 ) ;
F_49 ( & V_27 -> V_16 , F_59 ) ;
F_63 ( & V_27 -> V_16 ) ;
}
static void
F_64 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 . V_27 == NULL )
return;
F_65 ( & V_2 -> V_19 . V_27 -> V_69 ,
F_61 ,
& F_10 ( V_2 -> V_5 . V_4 ) -> V_56 ) ;
V_2 -> V_19 . V_27 = NULL ;
}
static int
F_66 ( struct V_73 * * V_74 , struct V_75 * * V_76 , int V_77 )
{
struct V_78 * V_79 ;
int V_45 , V_10 ;
* V_74 = F_33 ( sizeof( * * V_74 ) , V_46 ) ;
if ( * V_74 == NULL )
return - V_47 ;
if ( F_67 () ) {
V_45 = F_68 ( * V_74 , V_77 , V_46 ) ;
if ( V_45 )
goto V_80;
F_69 ((*st)->sgl, sg, num_pages, n)
F_70 ( V_79 , V_76 [ V_10 ] , V_81 , 0 ) ;
} else {
V_45 = F_71 ( * V_74 , V_76 , V_77 ,
0 , V_77 << V_82 ,
V_46 ) ;
if ( V_45 )
goto V_80;
}
return 0 ;
V_80:
F_37 ( * V_74 ) ;
* V_74 = NULL ;
return V_45 ;
}
static int
F_72 ( struct V_1 * V_2 ,
struct V_75 * * V_76 , int V_77 )
{
int V_45 ;
V_45 = F_66 ( & V_2 -> V_20 , V_76 , V_77 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_73 ( V_2 ) ;
if ( V_45 ) {
F_74 ( V_2 -> V_20 ) ;
F_37 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
}
return V_45 ;
}
static int
F_75 ( struct V_1 * V_2 ,
bool V_83 )
{
int V_45 = 0 ;
#if F_76 ( V_84 )
if ( V_2 -> V_19 . V_52 == NULL )
return 0 ;
F_23 ( & V_2 -> V_19 . V_52 -> V_31 -> V_41 ) ;
if ( ! V_83 )
F_18 ( V_2 -> V_19 . V_52 ) ;
else if ( ! F_77 ( & V_2 -> V_19 . V_52 -> V_16 ) )
F_16 ( V_2 -> V_19 . V_52 ) ;
else
V_45 = - V_85 ;
F_30 ( & V_2 -> V_19 . V_52 -> V_31 -> V_41 ) ;
#endif
return V_45 ;
}
static void
F_78 ( struct V_15 * V_86 )
{
struct V_87 * V_16 = F_8 ( V_86 , F_9 ( * V_16 ) , V_16 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
const int V_88 = V_2 -> V_5 . V_64 >> V_82 ;
struct V_75 * * V_76 ;
int V_89 , V_45 ;
V_45 = - V_47 ;
V_89 = 0 ;
V_76 = F_79 ( V_88 , sizeof( struct V_75 * ) , V_90 ) ;
if ( V_76 != NULL ) {
struct V_35 * V_27 = V_2 -> V_19 . V_27 -> V_27 ;
V_45 = - V_91 ;
if ( F_80 ( & V_27 -> V_92 ) ) {
F_81 ( & V_27 -> V_54 ) ;
while ( V_89 < V_88 ) {
V_45 = F_82
( V_16 -> V_93 , V_27 ,
V_2 -> V_19 . V_62 + V_89 * V_81 ,
V_88 - V_89 ,
! V_2 -> V_19 . V_94 , 0 ,
V_76 + V_89 , NULL ) ;
if ( V_45 < 0 )
break;
V_89 += V_45 ;
}
F_83 ( & V_27 -> V_54 ) ;
F_84 ( V_27 ) ;
}
}
F_5 ( & V_4 -> V_14 ) ;
if ( V_2 -> V_19 . V_16 == & V_16 -> V_16 ) {
if ( V_89 == V_88 ) {
V_45 = F_72 ( V_2 , V_76 , V_88 ) ;
if ( V_45 == 0 ) {
F_85 ( & V_2 -> V_95 ,
& F_10 ( V_4 ) -> V_27 . V_96 ) ;
V_2 -> V_97 . V_79 = V_2 -> V_20 -> V_98 ;
V_2 -> V_97 . V_63 = 0 ;
V_89 = 0 ;
}
}
V_2 -> V_19 . V_16 = F_34 ( V_45 ) ;
if ( V_45 )
F_75 ( V_2 , false ) ;
}
V_2 -> V_19 . V_99 -- ;
F_15 ( & V_2 -> V_5 ) ;
F_3 ( & V_4 -> V_14 ) ;
F_86 ( V_76 , V_89 , 0 ) ;
F_87 ( V_76 ) ;
F_88 ( V_16 -> V_93 ) ;
F_37 ( V_16 ) ;
}
static int
F_89 ( struct V_1 * V_2 ,
bool * V_11 )
{
struct V_87 * V_16 ;
if ( V_2 -> V_19 . V_99 >= V_100 )
return - V_85 ;
V_16 = F_33 ( sizeof( * V_16 ) , V_46 ) ;
if ( V_16 == NULL )
return - V_47 ;
V_2 -> V_19 . V_16 = & V_16 -> V_16 ;
V_2 -> V_19 . V_99 ++ ;
V_16 -> V_2 = V_2 ;
F_90 ( & V_2 -> V_5 ) ;
V_16 -> V_93 = V_67 ;
F_91 ( V_16 -> V_93 ) ;
F_49 ( & V_16 -> V_16 , F_78 ) ;
F_63 ( & V_16 -> V_16 ) ;
* V_11 = true ;
return - V_85 ;
}
static int
F_92 ( struct V_1 * V_2 )
{
const int V_77 = V_2 -> V_5 . V_64 >> V_82 ;
struct V_75 * * V_76 ;
int V_89 , V_45 ;
bool V_11 ;
if ( F_43 ( V_2 -> V_19 . V_16 ) ) {
V_45 = F_47 ( V_2 -> V_19 . V_16 ) ;
V_2 -> V_19 . V_16 = NULL ;
return V_45 ;
}
if ( V_2 -> V_19 . V_16 )
return - V_85 ;
V_45 = F_75 ( V_2 , true ) ;
if ( V_45 )
return V_45 ;
V_76 = NULL ;
V_89 = 0 ;
if ( V_2 -> V_19 . V_27 -> V_27 == V_67 -> V_27 ) {
V_76 = F_79 ( V_77 , sizeof( struct V_75 * ) ,
V_90 ) ;
if ( V_76 == NULL ) {
F_75 ( V_2 , false ) ;
return - V_47 ;
}
V_89 = F_93 ( V_2 -> V_19 . V_62 , V_77 ,
! V_2 -> V_19 . V_94 , V_76 ) ;
}
V_11 = false ;
if ( V_89 < 0 )
V_45 = V_89 , V_89 = 0 ;
else if ( V_89 < V_77 )
V_45 = F_89 ( V_2 , & V_11 ) ;
else
V_45 = F_72 ( V_2 , V_76 , V_77 ) ;
if ( V_45 ) {
F_75 ( V_2 , V_11 ) ;
F_86 ( V_76 , V_89 , 0 ) ;
}
F_87 ( V_76 ) ;
return V_45 ;
}
static void
F_94 ( struct V_1 * V_2 )
{
struct V_101 V_102 ;
F_95 ( V_2 -> V_19 . V_16 != NULL ) ;
F_75 ( V_2 , false ) ;
if ( V_2 -> V_103 != V_104 )
V_2 -> V_105 = 0 ;
F_96 ( V_2 ) ;
F_97 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
struct V_75 * V_75 = F_98 ( & V_102 ) ;
if ( V_2 -> V_105 )
F_99 ( V_75 ) ;
F_100 ( V_75 ) ;
F_101 ( V_75 ) ;
}
V_2 -> V_105 = 0 ;
F_74 ( V_2 -> V_20 ) ;
F_37 ( V_2 -> V_20 ) ;
}
static void
F_102 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
F_64 ( V_2 ) ;
}
static int
F_103 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 . V_52 )
return 0 ;
return F_45 ( V_2 , 0 ) ;
}
int
F_104 ( struct V_3 * V_4 , void * V_106 , struct V_107 * V_108 )
{
struct V_109 * args = V_106 ;
struct V_1 * V_2 ;
int V_45 ;
T_1 V_110 ;
if ( ! F_105 ( V_4 ) && ! F_106 ( V_4 ) ) {
return - V_65 ;
}
if ( args -> V_57 & ~ ( V_111 |
V_58 ) )
return - V_61 ;
if ( F_107 ( args -> V_112 | args -> V_113 ) )
return - V_61 ;
if ( ! F_108 ( args -> V_57 & V_111 ? V_114 : V_115 ,
( char V_116 * ) ( unsigned long ) args -> V_112 , args -> V_113 ) )
return - V_91 ;
if ( args -> V_57 & V_111 ) {
return - V_65 ;
}
V_2 = F_109 ( V_4 ) ;
if ( V_2 == NULL )
return - V_47 ;
F_110 ( V_4 , & V_2 -> V_5 , args -> V_113 ) ;
F_111 ( V_2 , & V_117 ) ;
V_2 -> V_118 = V_119 ;
V_2 -> V_5 . V_120 = V_121 ;
V_2 -> V_5 . V_122 = V_121 ;
V_2 -> V_19 . V_62 = args -> V_112 ;
V_2 -> V_19 . V_94 = ! ! ( args -> V_57 & V_111 ) ;
V_45 = F_54 ( V_2 ) ;
if ( V_45 == 0 )
V_45 = F_45 ( V_2 , args -> V_57 ) ;
if ( V_45 == 0 )
V_45 = F_112 ( V_108 , & V_2 -> V_5 , & V_110 ) ;
F_113 ( & V_2 -> V_5 ) ;
if ( V_45 )
return V_45 ;
args -> V_110 = V_110 ;
return 0 ;
}
int
F_114 ( struct V_3 * V_4 )
{
struct V_21 * V_22 = F_10 ( V_4 ) ;
F_115 ( & V_22 -> V_56 ) ;
F_116 ( V_22 -> V_71 ) ;
return 0 ;
}
