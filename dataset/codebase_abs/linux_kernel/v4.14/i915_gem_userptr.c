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
if ( F_19 ( & V_24 -> V_25 . V_34 ) )
return;
V_30 -- ;
F_20 ( & V_24 -> V_9 ) ;
V_23 = F_21 ( & V_24 -> V_25 , V_29 , V_30 ) ;
while ( V_23 ) {
V_4 = F_2 ( V_23 , struct V_3 , V_23 ) ;
if ( F_22 ( & V_4 -> V_6 -> V_14 . V_35 ) )
F_23 ( V_24 -> V_36 , & V_4 -> V_2 ) ;
F_24 ( & V_4 -> V_37 , & V_33 ) ;
V_23 = F_25 ( V_23 , V_29 , V_30 ) ;
}
F_26 (mo, &cancelled, link)
F_15 ( V_4 ) ;
F_27 ( & V_24 -> V_9 ) ;
if ( ! F_28 ( & V_33 ) )
F_29 ( V_24 -> V_36 ) ;
}
static struct V_31 *
F_30 ( struct V_28 * V_8 )
{
struct V_31 * V_24 ;
int V_38 ;
V_24 = F_31 ( sizeof( * V_24 ) , V_39 ) ;
if ( V_24 == NULL )
return F_32 ( - V_40 ) ;
F_33 ( & V_24 -> V_9 ) ;
V_24 -> V_24 . V_41 = & V_42 ;
V_24 -> V_25 = V_43 ;
V_24 -> V_36 = F_34 ( L_2 , V_44 , 0 ) ;
if ( V_24 -> V_36 == NULL ) {
F_35 ( V_24 ) ;
return F_32 ( - V_40 ) ;
}
V_38 = F_36 ( & V_24 -> V_24 , V_8 ) ;
if ( V_38 ) {
F_37 ( V_24 -> V_36 ) ;
F_35 ( V_24 ) ;
return F_32 ( V_38 ) ;
}
return V_24 ;
}
static void
F_38 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_10 . V_45 ;
if ( V_4 == NULL )
return;
F_20 ( & V_4 -> V_24 -> V_9 ) ;
F_15 ( V_4 ) ;
F_27 ( & V_4 -> V_24 -> V_9 ) ;
F_35 ( V_4 ) ;
V_6 -> V_10 . V_45 = NULL ;
}
static struct V_31 *
F_39 ( struct V_46 * V_8 )
{
struct V_31 * V_24 = V_8 -> V_24 ;
V_24 = V_8 -> V_24 ;
if ( V_24 )
return V_24 ;
F_40 ( & V_8 -> V_8 -> V_47 ) ;
F_4 ( & V_8 -> V_48 -> V_49 ) ;
if ( ( V_24 = V_8 -> V_24 ) == NULL ) {
V_24 = F_30 ( V_8 -> V_8 ) ;
if ( ! F_41 ( V_24 ) )
V_8 -> V_24 = V_24 ;
}
F_6 ( & V_8 -> V_48 -> V_49 ) ;
F_42 ( & V_8 -> V_8 -> V_47 ) ;
return V_24 ;
}
static int
F_43 ( struct V_5 * V_6 ,
unsigned V_50 )
{
struct V_31 * V_24 ;
struct V_3 * V_4 ;
if ( V_50 & V_51 )
return F_44 ( V_52 ) ? 0 : - V_53 ;
if ( F_45 ( V_6 -> V_10 . V_8 == NULL ) )
return - V_54 ;
V_24 = F_39 ( V_6 -> V_10 . V_8 ) ;
if ( F_41 ( V_24 ) )
return F_46 ( V_24 ) ;
V_4 = F_47 ( sizeof( * V_4 ) , V_39 ) ;
if ( V_4 == NULL )
return - V_40 ;
V_4 -> V_24 = V_24 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_23 . V_29 = V_6 -> V_10 . V_55 ;
V_4 -> V_23 . V_56 = V_6 -> V_10 . V_55 + V_6 -> V_14 . V_57 - 1 ;
F_48 ( & V_4 -> V_2 , F_1 ) ;
V_6 -> V_10 . V_45 = V_4 ;
return 0 ;
}
static void
F_49 ( struct V_31 * V_24 ,
struct V_28 * V_8 )
{
if ( V_24 == NULL )
return;
F_50 ( & V_24 -> V_24 , V_8 ) ;
F_37 ( V_24 -> V_36 ) ;
F_35 ( V_24 ) ;
}
static void
F_38 ( struct V_5 * V_6 )
{
}
static int
F_43 ( struct V_5 * V_6 ,
unsigned V_50 )
{
if ( ( V_50 & V_51 ) == 0 )
return - V_58 ;
if ( ! F_44 ( V_52 ) )
return - V_53 ;
return 0 ;
}
static void
F_49 ( struct V_31 * V_24 ,
struct V_28 * V_8 )
{
}
static struct V_46 *
F_51 ( struct V_59 * V_60 , struct V_28 * V_61 )
{
struct V_46 * V_8 ;
F_52 (dev_priv->mm_structs, mm, node, (unsigned long)real)
if ( V_8 -> V_8 == V_61 )
return V_8 ;
return NULL ;
}
static int
F_53 ( struct V_5 * V_6 )
{
struct V_59 * V_60 = F_54 ( V_6 -> V_14 . V_15 ) ;
struct V_46 * V_8 ;
int V_38 = 0 ;
F_4 ( & V_60 -> V_49 ) ;
V_8 = F_51 ( V_60 , V_62 -> V_8 ) ;
if ( V_8 == NULL ) {
V_8 = F_31 ( sizeof( * V_8 ) , V_39 ) ;
if ( V_8 == NULL ) {
V_38 = - V_40 ;
goto V_11;
}
F_55 ( & V_8 -> V_63 ) ;
V_8 -> V_48 = F_54 ( V_6 -> V_14 . V_15 ) ;
V_8 -> V_8 = V_62 -> V_8 ;
F_56 ( V_62 -> V_8 ) ;
V_8 -> V_24 = NULL ;
F_57 ( V_60 -> V_64 ,
& V_8 -> V_65 , ( unsigned long ) V_8 -> V_8 ) ;
} else
F_58 ( & V_8 -> V_63 ) ;
V_6 -> V_10 . V_8 = V_8 ;
V_11:
F_6 ( & V_60 -> V_49 ) ;
return V_38 ;
}
static void
F_59 ( struct V_1 * V_2 )
{
struct V_46 * V_8 = F_2 ( V_2 , F_3 ( * V_8 ) , V_2 ) ;
F_49 ( V_8 -> V_24 , V_8 -> V_8 ) ;
F_60 ( V_8 -> V_8 ) ;
F_35 ( V_8 ) ;
}
static void
F_61 ( struct V_63 * V_63 )
{
struct V_46 * V_8 = F_2 ( V_63 , F_3 ( * V_8 ) , V_63 ) ;
F_62 ( & V_8 -> V_65 ) ;
F_6 ( & V_8 -> V_48 -> V_49 ) ;
F_48 ( & V_8 -> V_2 , F_59 ) ;
F_23 ( V_8 -> V_48 -> V_8 . V_66 , & V_8 -> V_2 ) ;
}
static void
F_63 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 . V_8 == NULL )
return;
F_64 ( & V_6 -> V_10 . V_8 -> V_63 ,
F_61 ,
& F_54 ( V_6 -> V_14 . V_15 ) -> V_49 ) ;
V_6 -> V_10 . V_8 = NULL ;
}
static int
F_65 ( struct V_67 * * V_68 , struct V_69 * * V_70 , int V_71 )
{
struct V_72 * V_73 ;
int V_38 , V_74 ;
* V_68 = F_31 ( sizeof( * * V_68 ) , V_39 ) ;
if ( * V_68 == NULL )
return - V_40 ;
if ( F_66 () ) {
V_38 = F_67 ( * V_68 , V_71 , V_39 ) ;
if ( V_38 )
goto V_75;
F_68 ((*st)->sgl, sg, num_pages, n)
F_69 ( V_73 , V_70 [ V_74 ] , V_76 , 0 ) ;
} else {
V_38 = F_70 ( * V_68 , V_70 , V_71 ,
0 , V_71 << V_77 ,
V_39 ) ;
if ( V_38 )
goto V_75;
}
return 0 ;
V_75:
F_35 ( * V_68 ) ;
* V_68 = NULL ;
return V_38 ;
}
static struct V_67 *
F_71 ( struct V_5 * V_6 ,
struct V_69 * * V_70 , int V_71 )
{
struct V_67 * V_18 ;
int V_38 ;
V_38 = F_65 ( & V_18 , V_70 , V_71 ) ;
if ( V_38 )
return F_32 ( V_38 ) ;
V_38 = F_72 ( V_6 , V_18 ) ;
if ( V_38 ) {
F_73 ( V_18 ) ;
F_35 ( V_18 ) ;
return F_32 ( V_38 ) ;
}
return V_18 ;
}
static int
F_74 ( struct V_5 * V_6 ,
bool V_78 )
{
int V_38 = 0 ;
#if F_75 ( V_79 )
if ( V_6 -> V_10 . V_45 == NULL )
return 0 ;
F_20 ( & V_6 -> V_10 . V_45 -> V_24 -> V_9 ) ;
if ( ! V_78 )
F_15 ( V_6 -> V_10 . V_45 ) ;
else if ( ! F_76 ( & V_6 -> V_10 . V_45 -> V_2 ) )
F_13 ( V_6 -> V_10 . V_45 ) ;
else
V_38 = - V_80 ;
F_27 ( & V_6 -> V_10 . V_45 -> V_24 -> V_9 ) ;
#endif
return V_38 ;
}
static void
F_77 ( struct V_1 * V_81 )
{
struct V_82 * V_2 = F_2 ( V_81 , F_3 ( * V_2 ) , V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
const int V_83 = V_6 -> V_14 . V_57 >> V_77 ;
struct V_69 * * V_70 ;
int V_84 , V_38 ;
V_38 = - V_40 ;
V_84 = 0 ;
V_70 = F_78 ( V_83 , sizeof( struct V_69 * ) , V_39 ) ;
if ( V_70 != NULL ) {
struct V_28 * V_8 = V_6 -> V_10 . V_8 -> V_8 ;
unsigned int V_50 = 0 ;
if ( ! V_6 -> V_10 . V_85 )
V_50 |= V_86 ;
V_38 = - V_87 ;
if ( F_79 ( V_8 ) ) {
F_80 ( & V_8 -> V_47 ) ;
while ( V_84 < V_83 ) {
V_38 = F_81
( V_2 -> V_88 , V_8 ,
V_6 -> V_10 . V_55 + V_84 * V_76 ,
V_83 - V_84 ,
V_50 ,
V_70 + V_84 , NULL , NULL ) ;
if ( V_38 < 0 )
break;
V_84 += V_38 ;
}
F_82 ( & V_8 -> V_47 ) ;
F_83 ( V_8 ) ;
}
}
F_4 ( & V_6 -> V_8 . V_9 ) ;
if ( V_6 -> V_10 . V_2 == & V_2 -> V_2 ) {
struct V_67 * V_18 = F_32 ( V_38 ) ;
if ( V_84 == V_83 ) {
V_18 = F_71 ( V_6 , V_70 , V_83 ) ;
if ( ! F_41 ( V_18 ) ) {
F_84 ( V_6 , V_18 ) ;
V_84 = 0 ;
V_18 = NULL ;
}
}
V_6 -> V_10 . V_2 = F_85 ( V_18 ) ;
if ( F_41 ( V_18 ) )
F_74 ( V_6 , false ) ;
}
F_6 ( & V_6 -> V_8 . V_9 ) ;
F_86 ( V_70 , V_84 , 0 ) ;
F_87 ( V_70 ) ;
F_12 ( V_6 ) ;
F_88 ( V_2 -> V_88 ) ;
F_35 ( V_2 ) ;
}
static struct V_67 *
F_89 ( struct V_5 * V_6 )
{
struct V_82 * V_2 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_39 ) ;
if ( V_2 == NULL )
return F_32 ( - V_40 ) ;
V_6 -> V_10 . V_2 = & V_2 -> V_2 ;
V_2 -> V_6 = F_90 ( V_6 ) ;
V_2 -> V_88 = V_62 ;
F_91 ( V_2 -> V_88 ) ;
F_48 ( & V_2 -> V_2 , F_77 ) ;
F_23 ( F_54 ( V_6 -> V_14 . V_15 ) -> V_8 . V_66 , & V_2 -> V_2 ) ;
return F_32 ( - V_80 ) ;
}
static struct V_67 *
F_92 ( struct V_5 * V_6 )
{
const int V_71 = V_6 -> V_14 . V_57 >> V_77 ;
struct V_28 * V_8 = V_6 -> V_10 . V_8 -> V_8 ;
struct V_69 * * V_70 ;
struct V_67 * V_18 ;
bool V_7 ;
int V_84 ;
if ( V_6 -> V_10 . V_2 ) {
if ( F_41 ( V_6 -> V_10 . V_2 ) )
return F_85 ( V_6 -> V_10 . V_2 ) ;
else
return F_32 ( - V_80 ) ;
}
V_70 = NULL ;
V_84 = 0 ;
if ( V_8 == V_62 -> V_8 ) {
V_70 = F_78 ( V_71 , sizeof( struct V_69 * ) ,
V_39 |
V_89 |
V_90 ) ;
if ( V_70 )
V_84 = F_93 ( V_6 -> V_10 . V_55 ,
V_71 ,
! V_6 -> V_10 . V_85 ,
V_70 ) ;
}
V_7 = false ;
if ( V_84 < 0 ) {
V_18 = F_32 ( V_84 ) ;
V_84 = 0 ;
} else if ( V_84 < V_71 ) {
V_18 = F_89 ( V_6 ) ;
V_7 = V_18 == F_32 ( - V_80 ) ;
} else {
V_18 = F_71 ( V_6 , V_70 , V_71 ) ;
V_7 = ! F_41 ( V_18 ) ;
}
if ( V_7 )
F_74 ( V_6 , true ) ;
if ( F_41 ( V_18 ) )
F_86 ( V_70 , V_84 , 0 ) ;
F_87 ( V_70 ) ;
return V_18 ;
}
static void
F_94 ( struct V_5 * V_6 ,
struct V_67 * V_18 )
{
struct V_91 V_91 ;
struct V_69 * V_69 ;
F_95 ( V_6 -> V_10 . V_2 != NULL ) ;
F_74 ( V_6 , false ) ;
if ( V_6 -> V_8 . V_92 != V_93 )
V_6 -> V_8 . V_94 = false ;
F_96 ( V_6 , V_18 ) ;
F_97 (page, sgt_iter, pages) {
if ( V_6 -> V_8 . V_94 )
F_98 ( V_69 ) ;
F_99 ( V_69 ) ;
F_100 ( V_69 ) ;
}
V_6 -> V_8 . V_94 = false ;
F_73 ( V_18 ) ;
F_35 ( V_18 ) ;
}
static void
F_101 ( struct V_5 * V_6 )
{
F_38 ( V_6 ) ;
F_63 ( V_6 ) ;
}
static int
F_102 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 . V_45 )
return 0 ;
return F_43 ( V_6 , 0 ) ;
}
int
F_103 ( struct V_95 * V_15 , void * V_96 , struct V_97 * V_98 )
{
struct V_59 * V_60 = F_54 ( V_15 ) ;
struct V_99 * args = V_96 ;
struct V_5 * V_6 ;
int V_38 ;
T_1 V_100 ;
if ( ! F_104 ( V_60 ) && ! F_105 ( V_60 ) ) {
return - V_58 ;
}
if ( args -> V_50 & ~ ( V_101 |
V_51 ) )
return - V_54 ;
if ( F_106 ( args -> V_102 | args -> V_103 ) )
return - V_54 ;
if ( ! F_107 ( args -> V_50 & V_101 ? V_104 : V_105 ,
( char V_106 * ) ( unsigned long ) args -> V_102 , args -> V_103 ) )
return - V_87 ;
if ( args -> V_50 & V_101 ) {
return - V_58 ;
}
V_6 = F_108 ( V_60 ) ;
if ( V_6 == NULL )
return - V_40 ;
F_109 ( V_15 , & V_6 -> V_14 , args -> V_103 ) ;
F_110 ( V_6 , & V_107 ) ;
V_6 -> V_14 . V_108 = V_109 ;
V_6 -> V_14 . V_110 = V_109 ;
F_111 ( V_6 , V_111 ) ;
V_6 -> V_10 . V_55 = args -> V_102 ;
V_6 -> V_10 . V_85 = ! ! ( args -> V_50 & V_101 ) ;
V_38 = F_53 ( V_6 ) ;
if ( V_38 == 0 )
V_38 = F_43 ( V_6 , args -> V_50 ) ;
if ( V_38 == 0 )
V_38 = F_112 ( V_98 , & V_6 -> V_14 , & V_100 ) ;
F_12 ( V_6 ) ;
if ( V_38 )
return V_38 ;
args -> V_100 = V_100 ;
return 0 ;
}
int F_113 ( struct V_59 * V_60 )
{
F_114 ( & V_60 -> V_49 ) ;
F_115 ( V_60 -> V_64 ) ;
V_60 -> V_8 . V_66 =
F_34 ( L_3 , V_112 , 0 ) ;
if ( ! V_60 -> V_8 . V_66 )
return - V_40 ;
return 0 ;
}
void F_116 ( struct V_59 * V_60 )
{
F_37 ( V_60 -> V_8 . V_66 ) ;
}
