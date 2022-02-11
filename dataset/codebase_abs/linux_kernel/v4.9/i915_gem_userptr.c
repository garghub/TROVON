static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = F_2 ( V_2 ) ;
int V_4 ;
F_3 (active, idx)
F_4 ( & V_2 -> V_5 [ V_4 ] ,
0 , NULL , NULL ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 , F_7 ( * V_9 ) , V_7 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_12 . V_11 ;
F_1 ( V_2 ) ;
F_8 ( & V_11 -> V_13 ) ;
V_2 -> V_14 . V_7 = NULL ;
if ( V_2 -> V_15 != NULL ) {
F_9 ( F_10 ( V_2 ) ) ;
F_9 ( F_11 ( V_2 ) ) ;
}
F_12 ( V_2 ) ;
F_13 ( & V_11 -> V_13 ) ;
}
static void F_14 ( struct V_8 * V_9 )
{
if ( V_9 -> V_16 )
return;
F_15 ( & V_9 -> V_17 , & V_9 -> V_18 -> V_19 ) ;
V_9 -> V_16 = true ;
}
static void F_16 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_16 )
return;
F_17 ( & V_9 -> V_17 , & V_9 -> V_18 -> V_19 ) ;
V_9 -> V_16 = false ;
}
static void F_18 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
unsigned long V_24 ,
unsigned long V_25 )
{
struct V_26 * V_18 =
F_6 ( V_21 , struct V_26 , V_18 ) ;
struct V_8 * V_9 ;
struct V_27 * V_17 ;
F_19 ( V_28 ) ;
if ( F_20 ( & V_18 -> V_19 ) )
return;
V_25 -- ;
F_21 ( & V_18 -> V_29 ) ;
V_17 = F_22 ( & V_18 -> V_19 , V_24 , V_25 ) ;
while ( V_17 ) {
V_9 = F_6 ( V_17 , struct V_8 , V_17 ) ;
if ( F_23 ( & V_9 -> V_2 -> V_12 . V_30 ) )
F_24 ( V_18 -> V_31 , & V_9 -> V_7 ) ;
F_25 ( & V_9 -> V_32 , & V_28 ) ;
V_17 = F_26 ( V_17 , V_24 , V_25 ) ;
}
F_27 (mo, &cancelled, link)
F_16 ( V_9 ) ;
F_28 ( & V_18 -> V_29 ) ;
F_29 ( V_18 -> V_31 ) ;
}
static struct V_26 *
F_30 ( struct V_22 * V_23 )
{
struct V_26 * V_18 ;
int V_33 ;
V_18 = F_31 ( sizeof( * V_18 ) , V_34 ) ;
if ( V_18 == NULL )
return F_32 ( - V_35 ) ;
F_33 ( & V_18 -> V_29 ) ;
V_18 -> V_18 . V_36 = & V_37 ;
V_18 -> V_19 = V_38 ;
V_18 -> V_31 = F_34 ( L_1 , V_39 , 0 ) ;
if ( V_18 -> V_31 == NULL ) {
F_35 ( V_18 ) ;
return F_32 ( - V_35 ) ;
}
V_33 = F_36 ( & V_18 -> V_18 , V_23 ) ;
if ( V_33 ) {
F_37 ( V_18 -> V_31 ) ;
F_35 ( V_18 ) ;
return F_32 ( V_33 ) ;
}
return V_18 ;
}
static void
F_38 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = V_2 -> V_14 . V_40 ;
if ( V_9 == NULL )
return;
F_21 ( & V_9 -> V_18 -> V_29 ) ;
F_16 ( V_9 ) ;
F_28 ( & V_9 -> V_18 -> V_29 ) ;
F_35 ( V_9 ) ;
V_2 -> V_14 . V_40 = NULL ;
}
static struct V_26 *
F_39 ( struct V_41 * V_23 )
{
struct V_26 * V_18 = V_23 -> V_18 ;
V_18 = V_23 -> V_18 ;
if ( V_18 )
return V_18 ;
F_40 ( & V_23 -> V_23 -> V_42 ) ;
F_8 ( & V_23 -> V_43 -> V_44 ) ;
if ( ( V_18 = V_23 -> V_18 ) == NULL ) {
V_18 = F_30 ( V_23 -> V_23 ) ;
if ( ! F_41 ( V_18 ) )
V_23 -> V_18 = V_18 ;
}
F_13 ( & V_23 -> V_43 -> V_44 ) ;
F_42 ( & V_23 -> V_23 -> V_42 ) ;
return V_18 ;
}
static int
F_43 ( struct V_1 * V_2 ,
unsigned V_45 )
{
struct V_26 * V_18 ;
struct V_8 * V_9 ;
if ( V_45 & V_46 )
return F_44 ( V_47 ) ? 0 : - V_48 ;
if ( F_9 ( V_2 -> V_14 . V_23 == NULL ) )
return - V_49 ;
V_18 = F_39 ( V_2 -> V_14 . V_23 ) ;
if ( F_41 ( V_18 ) )
return F_45 ( V_18 ) ;
V_9 = F_46 ( sizeof( * V_9 ) , V_34 ) ;
if ( V_9 == NULL )
return - V_35 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_17 . V_24 = V_2 -> V_14 . V_50 ;
V_9 -> V_17 . V_51 = V_2 -> V_14 . V_50 + V_2 -> V_12 . V_52 - 1 ;
F_47 ( & V_9 -> V_7 , F_5 ) ;
V_2 -> V_14 . V_40 = V_9 ;
return 0 ;
}
static void
F_48 ( struct V_26 * V_18 ,
struct V_22 * V_23 )
{
if ( V_18 == NULL )
return;
F_49 ( & V_18 -> V_18 , V_23 ) ;
F_37 ( V_18 -> V_31 ) ;
F_35 ( V_18 ) ;
}
static void
F_38 ( struct V_1 * V_2 )
{
}
static int
F_43 ( struct V_1 * V_2 ,
unsigned V_45 )
{
if ( ( V_45 & V_46 ) == 0 )
return - V_53 ;
if ( ! F_44 ( V_47 ) )
return - V_48 ;
return 0 ;
}
static void
F_48 ( struct V_26 * V_18 ,
struct V_22 * V_23 )
{
}
static struct V_41 *
F_50 ( struct V_54 * V_55 , struct V_22 * V_56 )
{
struct V_41 * V_23 ;
F_51 (dev_priv->mm_structs, mm, node, (unsigned long)real)
if ( V_23 -> V_23 == V_56 )
return V_23 ;
return NULL ;
}
static int
F_52 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_53 ( V_2 -> V_12 . V_11 ) ;
struct V_41 * V_23 ;
int V_33 = 0 ;
F_8 ( & V_55 -> V_44 ) ;
V_23 = F_50 ( V_55 , V_57 -> V_23 ) ;
if ( V_23 == NULL ) {
V_23 = F_31 ( sizeof( * V_23 ) , V_34 ) ;
if ( V_23 == NULL ) {
V_33 = - V_35 ;
goto V_58;
}
F_54 ( & V_23 -> V_59 ) ;
V_23 -> V_43 = F_53 ( V_2 -> V_12 . V_11 ) ;
V_23 -> V_23 = V_57 -> V_23 ;
F_55 ( & V_57 -> V_23 -> V_60 ) ;
V_23 -> V_18 = NULL ;
F_56 ( V_55 -> V_61 ,
& V_23 -> V_62 , ( unsigned long ) V_23 -> V_23 ) ;
} else
F_57 ( & V_23 -> V_59 ) ;
V_2 -> V_14 . V_23 = V_23 ;
V_58:
F_13 ( & V_55 -> V_44 ) ;
return V_33 ;
}
static void
F_58 ( struct V_6 * V_7 )
{
struct V_41 * V_23 = F_6 ( V_7 , F_7 ( * V_23 ) , V_7 ) ;
F_48 ( V_23 -> V_18 , V_23 -> V_23 ) ;
F_59 ( V_23 -> V_23 ) ;
F_35 ( V_23 ) ;
}
static void
F_60 ( struct V_59 * V_59 )
{
struct V_41 * V_23 = F_6 ( V_59 , F_7 ( * V_23 ) , V_59 ) ;
F_61 ( & V_23 -> V_62 ) ;
F_13 ( & V_23 -> V_43 -> V_44 ) ;
F_47 ( & V_23 -> V_7 , F_58 ) ;
F_62 ( & V_23 -> V_7 ) ;
}
static void
F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_23 == NULL )
return;
F_64 ( & V_2 -> V_14 . V_23 -> V_59 ,
F_60 ,
& F_53 ( V_2 -> V_12 . V_11 ) -> V_44 ) ;
V_2 -> V_14 . V_23 = NULL ;
}
static int
F_65 ( struct V_63 * * V_64 , struct V_65 * * V_66 , int V_67 )
{
struct V_68 * V_69 ;
int V_33 , V_70 ;
* V_64 = F_31 ( sizeof( * * V_64 ) , V_34 ) ;
if ( * V_64 == NULL )
return - V_35 ;
if ( F_66 () ) {
V_33 = F_67 ( * V_64 , V_67 , V_34 ) ;
if ( V_33 )
goto V_71;
F_68 ((*st)->sgl, sg, num_pages, n)
F_69 ( V_69 , V_66 [ V_70 ] , V_72 , 0 ) ;
} else {
V_33 = F_70 ( * V_64 , V_66 , V_67 ,
0 , V_67 << V_73 ,
V_34 ) ;
if ( V_33 )
goto V_71;
}
return 0 ;
V_71:
F_35 ( * V_64 ) ;
* V_64 = NULL ;
return V_33 ;
}
static int
F_71 ( struct V_1 * V_2 ,
struct V_65 * * V_66 , int V_67 )
{
int V_33 ;
V_33 = F_65 ( & V_2 -> V_15 , V_66 , V_67 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_72 ( V_2 ) ;
if ( V_33 ) {
F_73 ( V_2 -> V_15 ) ;
F_35 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
}
return V_33 ;
}
static int
F_74 ( struct V_1 * V_2 ,
bool V_74 )
{
int V_33 = 0 ;
#if F_75 ( V_75 )
if ( V_2 -> V_14 . V_40 == NULL )
return 0 ;
F_21 ( & V_2 -> V_14 . V_40 -> V_18 -> V_29 ) ;
if ( ! V_74 )
F_16 ( V_2 -> V_14 . V_40 ) ;
else if ( ! F_76 ( & V_2 -> V_14 . V_40 -> V_7 ) )
F_14 ( V_2 -> V_14 . V_40 ) ;
else
V_33 = - V_76 ;
F_28 ( & V_2 -> V_14 . V_40 -> V_18 -> V_29 ) ;
#endif
return V_33 ;
}
static void
F_77 ( struct V_6 * V_77 )
{
struct V_78 * V_7 = F_6 ( V_77 , F_7 ( * V_7 ) , V_7 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_10 * V_11 = V_2 -> V_12 . V_11 ;
const int V_79 = V_2 -> V_12 . V_52 >> V_73 ;
struct V_65 * * V_66 ;
int V_80 , V_33 ;
V_33 = - V_35 ;
V_80 = 0 ;
V_66 = F_78 ( V_79 , sizeof( struct V_65 * ) , V_81 ) ;
if ( V_66 != NULL ) {
struct V_22 * V_23 = V_2 -> V_14 . V_23 -> V_23 ;
unsigned int V_45 = 0 ;
if ( ! V_2 -> V_14 . V_82 )
V_45 |= V_83 ;
V_33 = - V_84 ;
if ( F_79 ( & V_23 -> V_85 ) ) {
F_80 ( & V_23 -> V_42 ) ;
while ( V_80 < V_79 ) {
V_33 = F_81
( V_7 -> V_86 , V_23 ,
V_2 -> V_14 . V_50 + V_80 * V_72 ,
V_79 - V_80 ,
V_45 ,
V_66 + V_80 , NULL ) ;
if ( V_33 < 0 )
break;
V_80 += V_33 ;
}
F_82 ( & V_23 -> V_42 ) ;
F_83 ( V_23 ) ;
}
}
F_8 ( & V_11 -> V_13 ) ;
if ( V_2 -> V_14 . V_7 == & V_7 -> V_7 ) {
if ( V_80 == V_79 ) {
V_33 = F_71 ( V_2 , V_66 , V_79 ) ;
if ( V_33 == 0 ) {
F_84 ( & V_2 -> V_87 ,
& F_53 ( V_11 ) -> V_23 . V_88 ) ;
V_2 -> V_89 . V_69 = V_2 -> V_15 -> V_90 ;
V_2 -> V_89 . V_51 = 0 ;
V_80 = 0 ;
}
}
V_2 -> V_14 . V_7 = F_32 ( V_33 ) ;
}
V_2 -> V_14 . V_91 -- ;
F_12 ( V_2 ) ;
F_13 ( & V_11 -> V_13 ) ;
F_85 ( V_66 , V_80 , 0 ) ;
F_86 ( V_66 ) ;
F_87 ( V_7 -> V_86 ) ;
F_35 ( V_7 ) ;
}
static int
F_88 ( struct V_1 * V_2 ,
bool * V_3 )
{
struct V_78 * V_7 ;
if ( V_2 -> V_14 . V_91 >= V_92 )
return - V_76 ;
V_7 = F_31 ( sizeof( * V_7 ) , V_34 ) ;
if ( V_7 == NULL )
return - V_35 ;
V_2 -> V_14 . V_7 = & V_7 -> V_7 ;
V_2 -> V_14 . V_91 ++ ;
V_7 -> V_2 = F_89 ( V_2 ) ;
V_7 -> V_86 = V_57 ;
F_90 ( V_7 -> V_86 ) ;
F_47 ( & V_7 -> V_7 , F_77 ) ;
F_62 ( & V_7 -> V_7 ) ;
* V_3 = true ;
return - V_76 ;
}
static int
F_91 ( struct V_1 * V_2 )
{
const int V_67 = V_2 -> V_12 . V_52 >> V_73 ;
struct V_65 * * V_66 ;
int V_80 , V_33 ;
bool V_3 ;
if ( V_2 -> V_14 . V_7 ) {
if ( F_41 ( V_2 -> V_14 . V_7 ) )
return F_45 ( V_2 -> V_14 . V_7 ) ;
else
return - V_76 ;
}
V_33 = F_74 ( V_2 , true ) ;
if ( V_33 )
return V_33 ;
V_66 = NULL ;
V_80 = 0 ;
if ( V_2 -> V_14 . V_23 -> V_23 == V_57 -> V_23 ) {
V_66 = F_78 ( V_67 , sizeof( struct V_65 * ) ,
V_81 ) ;
if ( V_66 == NULL ) {
F_74 ( V_2 , false ) ;
return - V_35 ;
}
V_80 = F_92 ( V_2 -> V_14 . V_50 , V_67 ,
! V_2 -> V_14 . V_82 , V_66 ) ;
}
V_3 = false ;
if ( V_80 < 0 )
V_33 = V_80 , V_80 = 0 ;
else if ( V_80 < V_67 )
V_33 = F_88 ( V_2 , & V_3 ) ;
else
V_33 = F_71 ( V_2 , V_66 , V_67 ) ;
if ( V_33 ) {
F_74 ( V_2 , V_3 ) ;
F_85 ( V_66 , V_80 , 0 ) ;
}
F_86 ( V_66 ) ;
return V_33 ;
}
static void
F_93 ( struct V_1 * V_2 )
{
struct V_93 V_93 ;
struct V_65 * V_65 ;
F_94 ( V_2 -> V_14 . V_7 != NULL ) ;
F_74 ( V_2 , false ) ;
if ( V_2 -> V_94 != V_95 )
V_2 -> V_96 = 0 ;
F_95 ( V_2 ) ;
F_96 (page, sgt_iter, obj->pages) {
if ( V_2 -> V_96 )
F_97 ( V_65 ) ;
F_98 ( V_65 ) ;
F_99 ( V_65 ) ;
}
V_2 -> V_96 = 0 ;
F_73 ( V_2 -> V_15 ) ;
F_35 ( V_2 -> V_15 ) ;
}
static void
F_100 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
F_63 ( V_2 ) ;
}
static int
F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_40 )
return 0 ;
return F_43 ( V_2 , 0 ) ;
}
int
F_102 ( struct V_10 * V_11 , void * V_97 , struct V_98 * V_99 )
{
struct V_100 * args = V_97 ;
struct V_1 * V_2 ;
int V_33 ;
T_1 V_101 ;
if ( ! F_103 ( V_11 ) && ! F_104 ( V_11 ) ) {
return - V_53 ;
}
if ( args -> V_45 & ~ ( V_102 |
V_46 ) )
return - V_49 ;
if ( F_105 ( args -> V_103 | args -> V_104 ) )
return - V_49 ;
if ( ! F_106 ( args -> V_45 & V_102 ? V_105 : V_106 ,
( char V_107 * ) ( unsigned long ) args -> V_103 , args -> V_104 ) )
return - V_84 ;
if ( args -> V_45 & V_102 ) {
return - V_53 ;
}
V_2 = F_107 ( V_11 ) ;
if ( V_2 == NULL )
return - V_35 ;
F_108 ( V_11 , & V_2 -> V_12 , args -> V_104 ) ;
F_109 ( V_2 , & V_108 ) ;
V_2 -> V_109 = V_110 ;
V_2 -> V_12 . V_111 = V_112 ;
V_2 -> V_12 . V_113 = V_112 ;
V_2 -> V_14 . V_50 = args -> V_103 ;
V_2 -> V_14 . V_82 = ! ! ( args -> V_45 & V_102 ) ;
V_33 = F_52 ( V_2 ) ;
if ( V_33 == 0 )
V_33 = F_43 ( V_2 , args -> V_45 ) ;
if ( V_33 == 0 )
V_33 = F_110 ( V_99 , & V_2 -> V_12 , & V_101 ) ;
F_111 ( V_2 ) ;
if ( V_33 )
return V_33 ;
args -> V_101 = V_101 ;
return 0 ;
}
void F_112 ( struct V_54 * V_55 )
{
F_113 ( & V_55 -> V_44 ) ;
F_114 ( V_55 -> V_61 ) ;
}
