static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , F_3 ( * V_4 ) , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 ;
F_4 ( & V_6 -> V_8 . V_9 ) ;
V_7 = F_5 ( & V_6 -> V_10 . V_2 ) ;
F_6 ( & V_6 -> V_8 . V_9 ) ;
if ( V_7 )
goto V_11;
F_7 ( V_6 , V_12 , V_13 , NULL ) ;
F_4 ( & V_6 -> V_14 . V_15 -> V_16 ) ;
if ( F_8 ( V_6 ) == 0 )
F_9 ( V_6 , V_17 ) ;
F_10 ( V_6 -> V_8 . V_18 ,
L_1 ,
V_6 -> V_19 ,
F_11 ( & V_6 -> V_8 . V_20 ) ,
V_6 -> V_21 ) ;
F_6 ( & V_6 -> V_14 . V_15 -> V_16 ) ;
V_11:
F_12 ( V_6 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
if ( V_4 -> V_22 )
return;
F_14 ( & V_4 -> V_23 , & V_4 -> V_24 -> V_25 ) ;
V_4 -> V_22 = true ;
}
static void F_15 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_22 )
return;
F_16 ( & V_4 -> V_23 , & V_4 -> V_24 -> V_25 ) ;
V_4 -> V_22 = false ;
}
static void F_17 ( struct V_26 * V_27 ,
struct V_28 * V_8 ,
unsigned long V_29 ,
unsigned long V_30 )
{
struct V_31 * V_24 =
F_2 ( V_27 , struct V_31 , V_24 ) ;
struct V_3 * V_4 ;
struct V_32 * V_23 ;
F_18 ( V_33 ) ;
if ( F_19 ( & V_24 -> V_25 ) )
return;
V_30 -- ;
F_20 ( & V_24 -> V_9 ) ;
V_23 = F_21 ( & V_24 -> V_25 , V_29 , V_30 ) ;
while ( V_23 ) {
V_4 = F_2 ( V_23 , struct V_3 , V_23 ) ;
if ( F_22 ( & V_4 -> V_6 -> V_14 . V_34 ) )
F_23 ( V_24 -> V_35 , & V_4 -> V_2 ) ;
F_24 ( & V_4 -> V_36 , & V_33 ) ;
V_23 = F_25 ( V_23 , V_29 , V_30 ) ;
}
F_26 (mo, &cancelled, link)
F_15 ( V_4 ) ;
F_27 ( & V_24 -> V_9 ) ;
if ( ! F_28 ( & V_33 ) )
F_29 ( V_24 -> V_35 ) ;
}
static struct V_31 *
F_30 ( struct V_28 * V_8 )
{
struct V_31 * V_24 ;
int V_37 ;
V_24 = F_31 ( sizeof( * V_24 ) , V_38 ) ;
if ( V_24 == NULL )
return F_32 ( - V_39 ) ;
F_33 ( & V_24 -> V_9 ) ;
V_24 -> V_24 . V_40 = & V_41 ;
V_24 -> V_25 = V_42 ;
V_24 -> V_35 = F_34 ( L_2 , V_43 , 0 ) ;
if ( V_24 -> V_35 == NULL ) {
F_35 ( V_24 ) ;
return F_32 ( - V_39 ) ;
}
V_37 = F_36 ( & V_24 -> V_24 , V_8 ) ;
if ( V_37 ) {
F_37 ( V_24 -> V_35 ) ;
F_35 ( V_24 ) ;
return F_32 ( V_37 ) ;
}
return V_24 ;
}
static void
F_38 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_10 . V_44 ;
if ( V_4 == NULL )
return;
F_20 ( & V_4 -> V_24 -> V_9 ) ;
F_15 ( V_4 ) ;
F_27 ( & V_4 -> V_24 -> V_9 ) ;
F_35 ( V_4 ) ;
V_6 -> V_10 . V_44 = NULL ;
}
static struct V_31 *
F_39 ( struct V_45 * V_8 )
{
struct V_31 * V_24 = V_8 -> V_24 ;
V_24 = V_8 -> V_24 ;
if ( V_24 )
return V_24 ;
F_40 ( & V_8 -> V_8 -> V_46 ) ;
F_4 ( & V_8 -> V_47 -> V_48 ) ;
if ( ( V_24 = V_8 -> V_24 ) == NULL ) {
V_24 = F_30 ( V_8 -> V_8 ) ;
if ( ! F_41 ( V_24 ) )
V_8 -> V_24 = V_24 ;
}
F_6 ( & V_8 -> V_47 -> V_48 ) ;
F_42 ( & V_8 -> V_8 -> V_46 ) ;
return V_24 ;
}
static int
F_43 ( struct V_5 * V_6 ,
unsigned V_49 )
{
struct V_31 * V_24 ;
struct V_3 * V_4 ;
if ( V_49 & V_50 )
return F_44 ( V_51 ) ? 0 : - V_52 ;
if ( F_45 ( V_6 -> V_10 . V_8 == NULL ) )
return - V_53 ;
V_24 = F_39 ( V_6 -> V_10 . V_8 ) ;
if ( F_41 ( V_24 ) )
return F_46 ( V_24 ) ;
V_4 = F_47 ( sizeof( * V_4 ) , V_38 ) ;
if ( V_4 == NULL )
return - V_39 ;
V_4 -> V_24 = V_24 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_23 . V_29 = V_6 -> V_10 . V_54 ;
V_4 -> V_23 . V_55 = V_6 -> V_10 . V_54 + V_6 -> V_14 . V_56 - 1 ;
F_48 ( & V_4 -> V_2 , F_1 ) ;
V_6 -> V_10 . V_44 = V_4 ;
return 0 ;
}
static void
F_49 ( struct V_31 * V_24 ,
struct V_28 * V_8 )
{
if ( V_24 == NULL )
return;
F_50 ( & V_24 -> V_24 , V_8 ) ;
F_37 ( V_24 -> V_35 ) ;
F_35 ( V_24 ) ;
}
static void
F_38 ( struct V_5 * V_6 )
{
}
static int
F_43 ( struct V_5 * V_6 ,
unsigned V_49 )
{
if ( ( V_49 & V_50 ) == 0 )
return - V_57 ;
if ( ! F_44 ( V_51 ) )
return - V_52 ;
return 0 ;
}
static void
F_49 ( struct V_31 * V_24 ,
struct V_28 * V_8 )
{
}
static struct V_45 *
F_51 ( struct V_58 * V_59 , struct V_28 * V_60 )
{
struct V_45 * V_8 ;
F_52 (dev_priv->mm_structs, mm, node, (unsigned long)real)
if ( V_8 -> V_8 == V_60 )
return V_8 ;
return NULL ;
}
static int
F_53 ( struct V_5 * V_6 )
{
struct V_58 * V_59 = F_54 ( V_6 -> V_14 . V_15 ) ;
struct V_45 * V_8 ;
int V_37 = 0 ;
F_4 ( & V_59 -> V_48 ) ;
V_8 = F_51 ( V_59 , V_61 -> V_8 ) ;
if ( V_8 == NULL ) {
V_8 = F_31 ( sizeof( * V_8 ) , V_38 ) ;
if ( V_8 == NULL ) {
V_37 = - V_39 ;
goto V_11;
}
F_55 ( & V_8 -> V_62 ) ;
V_8 -> V_47 = F_54 ( V_6 -> V_14 . V_15 ) ;
V_8 -> V_8 = V_61 -> V_8 ;
F_56 ( V_61 -> V_8 ) ;
V_8 -> V_24 = NULL ;
F_57 ( V_59 -> V_63 ,
& V_8 -> V_64 , ( unsigned long ) V_8 -> V_8 ) ;
} else
F_58 ( & V_8 -> V_62 ) ;
V_6 -> V_10 . V_8 = V_8 ;
V_11:
F_6 ( & V_59 -> V_48 ) ;
return V_37 ;
}
static void
F_59 ( struct V_1 * V_2 )
{
struct V_45 * V_8 = F_2 ( V_2 , F_3 ( * V_8 ) , V_2 ) ;
F_49 ( V_8 -> V_24 , V_8 -> V_8 ) ;
F_60 ( V_8 -> V_8 ) ;
F_35 ( V_8 ) ;
}
static void
F_61 ( struct V_62 * V_62 )
{
struct V_45 * V_8 = F_2 ( V_62 , F_3 ( * V_8 ) , V_62 ) ;
F_62 ( & V_8 -> V_64 ) ;
F_6 ( & V_8 -> V_47 -> V_48 ) ;
F_48 ( & V_8 -> V_2 , F_59 ) ;
F_63 ( & V_8 -> V_2 ) ;
}
static void
F_64 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 . V_8 == NULL )
return;
F_65 ( & V_6 -> V_10 . V_8 -> V_62 ,
F_61 ,
& F_54 ( V_6 -> V_14 . V_15 ) -> V_48 ) ;
V_6 -> V_10 . V_8 = NULL ;
}
static int
F_66 ( struct V_65 * * V_66 , struct V_67 * * V_68 , int V_69 )
{
struct V_70 * V_71 ;
int V_37 , V_72 ;
* V_66 = F_31 ( sizeof( * * V_66 ) , V_38 ) ;
if ( * V_66 == NULL )
return - V_39 ;
if ( F_67 () ) {
V_37 = F_68 ( * V_66 , V_69 , V_38 ) ;
if ( V_37 )
goto V_73;
F_69 ((*st)->sgl, sg, num_pages, n)
F_70 ( V_71 , V_68 [ V_72 ] , V_74 , 0 ) ;
} else {
V_37 = F_71 ( * V_66 , V_68 , V_69 ,
0 , V_69 << V_75 ,
V_38 ) ;
if ( V_37 )
goto V_73;
}
return 0 ;
V_73:
F_35 ( * V_66 ) ;
* V_66 = NULL ;
return V_37 ;
}
static struct V_65 *
F_72 ( struct V_5 * V_6 ,
struct V_67 * * V_68 , int V_69 )
{
struct V_65 * V_18 ;
int V_37 ;
V_37 = F_66 ( & V_18 , V_68 , V_69 ) ;
if ( V_37 )
return F_32 ( V_37 ) ;
V_37 = F_73 ( V_6 , V_18 ) ;
if ( V_37 ) {
F_74 ( V_18 ) ;
F_35 ( V_18 ) ;
return F_32 ( V_37 ) ;
}
return V_18 ;
}
static int
F_75 ( struct V_5 * V_6 ,
bool V_76 )
{
int V_37 = 0 ;
#if F_76 ( V_77 )
if ( V_6 -> V_10 . V_44 == NULL )
return 0 ;
F_20 ( & V_6 -> V_10 . V_44 -> V_24 -> V_9 ) ;
if ( ! V_76 )
F_15 ( V_6 -> V_10 . V_44 ) ;
else if ( ! F_77 ( & V_6 -> V_10 . V_44 -> V_2 ) )
F_13 ( V_6 -> V_10 . V_44 ) ;
else
V_37 = - V_78 ;
F_27 ( & V_6 -> V_10 . V_44 -> V_24 -> V_9 ) ;
#endif
return V_37 ;
}
static void
F_78 ( struct V_1 * V_79 )
{
struct V_80 * V_2 = F_2 ( V_79 , F_3 ( * V_2 ) , V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
const int V_81 = V_6 -> V_14 . V_56 >> V_75 ;
struct V_67 * * V_68 ;
int V_82 , V_37 ;
V_37 = - V_39 ;
V_82 = 0 ;
V_68 = F_79 ( V_81 , sizeof( struct V_67 * ) , V_83 ) ;
if ( V_68 != NULL ) {
struct V_28 * V_8 = V_6 -> V_10 . V_8 -> V_8 ;
unsigned int V_49 = 0 ;
if ( ! V_6 -> V_10 . V_84 )
V_49 |= V_85 ;
V_37 = - V_86 ;
if ( F_80 ( V_8 ) ) {
F_81 ( & V_8 -> V_46 ) ;
while ( V_82 < V_81 ) {
V_37 = F_82
( V_2 -> V_87 , V_8 ,
V_6 -> V_10 . V_54 + V_82 * V_74 ,
V_81 - V_82 ,
V_49 ,
V_68 + V_82 , NULL , NULL ) ;
if ( V_37 < 0 )
break;
V_82 += V_37 ;
}
F_83 ( & V_8 -> V_46 ) ;
F_84 ( V_8 ) ;
}
}
F_4 ( & V_6 -> V_8 . V_9 ) ;
if ( V_6 -> V_10 . V_2 == & V_2 -> V_2 ) {
struct V_65 * V_18 = F_32 ( V_37 ) ;
if ( V_82 == V_81 ) {
V_18 = F_72 ( V_6 , V_68 , V_81 ) ;
if ( ! F_41 ( V_18 ) ) {
F_85 ( V_6 , V_18 ) ;
V_82 = 0 ;
V_18 = NULL ;
}
}
V_6 -> V_10 . V_2 = F_86 ( V_18 ) ;
if ( F_41 ( V_18 ) )
F_75 ( V_6 , false ) ;
}
F_6 ( & V_6 -> V_8 . V_9 ) ;
F_87 ( V_68 , V_82 , 0 ) ;
F_88 ( V_68 ) ;
F_12 ( V_6 ) ;
F_89 ( V_2 -> V_87 ) ;
F_35 ( V_2 ) ;
}
static struct V_65 *
F_90 ( struct V_5 * V_6 )
{
struct V_80 * V_2 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_38 ) ;
if ( V_2 == NULL )
return F_32 ( - V_39 ) ;
V_6 -> V_10 . V_2 = & V_2 -> V_2 ;
V_2 -> V_6 = F_91 ( V_6 ) ;
V_2 -> V_87 = V_61 ;
F_92 ( V_2 -> V_87 ) ;
F_48 ( & V_2 -> V_2 , F_78 ) ;
F_63 ( & V_2 -> V_2 ) ;
return F_32 ( - V_78 ) ;
}
static struct V_65 *
F_93 ( struct V_5 * V_6 )
{
const int V_69 = V_6 -> V_14 . V_56 >> V_75 ;
struct V_28 * V_8 = V_6 -> V_10 . V_8 -> V_8 ;
struct V_67 * * V_68 ;
struct V_65 * V_18 ;
bool V_7 ;
int V_82 ;
if ( V_6 -> V_10 . V_2 ) {
if ( F_41 ( V_6 -> V_10 . V_2 ) )
return F_86 ( V_6 -> V_10 . V_2 ) ;
else
return F_32 ( - V_78 ) ;
}
V_68 = NULL ;
V_82 = 0 ;
if ( V_8 == V_61 -> V_8 ) {
V_68 = F_79 ( V_69 , sizeof( struct V_67 * ) ,
V_83 |
V_88 |
V_89 ) ;
if ( V_68 )
V_82 = F_94 ( V_6 -> V_10 . V_54 ,
V_69 ,
! V_6 -> V_10 . V_84 ,
V_68 ) ;
}
V_7 = false ;
if ( V_82 < 0 ) {
V_18 = F_32 ( V_82 ) ;
V_82 = 0 ;
} else if ( V_82 < V_69 ) {
V_18 = F_90 ( V_6 ) ;
V_7 = V_18 == F_32 ( - V_78 ) ;
} else {
V_18 = F_72 ( V_6 , V_68 , V_69 ) ;
V_7 = ! F_41 ( V_18 ) ;
}
if ( V_7 )
F_75 ( V_6 , true ) ;
if ( F_41 ( V_18 ) )
F_87 ( V_68 , V_82 , 0 ) ;
F_88 ( V_68 ) ;
return V_18 ;
}
static void
F_95 ( struct V_5 * V_6 ,
struct V_65 * V_18 )
{
struct V_90 V_90 ;
struct V_67 * V_67 ;
F_96 ( V_6 -> V_10 . V_2 != NULL ) ;
F_75 ( V_6 , false ) ;
if ( V_6 -> V_8 . V_91 != V_92 )
V_6 -> V_8 . V_93 = false ;
F_97 ( V_6 , V_18 ) ;
F_98 (page, sgt_iter, pages) {
if ( V_6 -> V_8 . V_93 )
F_99 ( V_67 ) ;
F_100 ( V_67 ) ;
F_101 ( V_67 ) ;
}
V_6 -> V_8 . V_93 = false ;
F_74 ( V_18 ) ;
F_35 ( V_18 ) ;
}
static void
F_102 ( struct V_5 * V_6 )
{
F_38 ( V_6 ) ;
F_64 ( V_6 ) ;
}
static int
F_103 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 . V_44 )
return 0 ;
return F_43 ( V_6 , 0 ) ;
}
int
F_104 ( struct V_94 * V_15 , void * V_95 , struct V_96 * V_97 )
{
struct V_58 * V_59 = F_54 ( V_15 ) ;
struct V_98 * args = V_95 ;
struct V_5 * V_6 ;
int V_37 ;
T_1 V_99 ;
if ( ! F_105 ( V_59 ) && ! F_106 ( V_59 ) ) {
return - V_57 ;
}
if ( args -> V_49 & ~ ( V_100 |
V_50 ) )
return - V_53 ;
if ( F_107 ( args -> V_101 | args -> V_102 ) )
return - V_53 ;
if ( ! F_108 ( args -> V_49 & V_100 ? V_103 : V_104 ,
( char V_105 * ) ( unsigned long ) args -> V_101 , args -> V_102 ) )
return - V_86 ;
if ( args -> V_49 & V_100 ) {
return - V_57 ;
}
V_6 = F_109 ( V_59 ) ;
if ( V_6 == NULL )
return - V_39 ;
F_110 ( V_15 , & V_6 -> V_14 , args -> V_102 ) ;
F_111 ( V_6 , & V_106 ) ;
V_6 -> V_107 = V_108 ;
V_6 -> V_14 . V_109 = V_110 ;
V_6 -> V_14 . V_111 = V_110 ;
V_6 -> V_10 . V_54 = args -> V_101 ;
V_6 -> V_10 . V_84 = ! ! ( args -> V_49 & V_100 ) ;
V_37 = F_53 ( V_6 ) ;
if ( V_37 == 0 )
V_37 = F_43 ( V_6 , args -> V_49 ) ;
if ( V_37 == 0 )
V_37 = F_112 ( V_97 , & V_6 -> V_14 , & V_99 ) ;
F_12 ( V_6 ) ;
if ( V_37 )
return V_37 ;
args -> V_99 = V_99 ;
return 0 ;
}
void F_113 ( struct V_58 * V_59 )
{
F_114 ( & V_59 -> V_48 ) ;
F_115 ( V_59 -> V_63 ) ;
}
