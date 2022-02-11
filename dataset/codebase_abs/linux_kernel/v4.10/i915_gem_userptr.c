static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , F_3 ( * V_4 ) , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 . V_8 ;
F_4 ( V_6 , V_10 , V_11 , NULL ) ;
F_5 ( & V_8 -> V_12 ) ;
V_6 -> V_13 . V_2 = NULL ;
if ( F_6 ( V_6 ) == 0 )
F_7 ( V_6 , V_14 ) ;
F_8 ( V_6 -> V_15 . V_16 ,
L_1 ,
V_6 -> V_17 ,
F_9 ( & V_6 -> V_15 . V_18 ) ,
V_6 -> V_19 ) ;
F_10 ( V_6 ) ;
F_11 ( & V_8 -> V_12 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
if ( V_4 -> V_20 )
return;
F_13 ( & V_4 -> V_21 , & V_4 -> V_22 -> V_23 ) ;
V_4 -> V_20 = true ;
}
static void F_14 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_20 )
return;
F_15 ( & V_4 -> V_21 , & V_4 -> V_22 -> V_23 ) ;
V_4 -> V_20 = false ;
}
static void F_16 ( struct V_24 * V_25 ,
struct V_26 * V_15 ,
unsigned long V_27 ,
unsigned long V_28 )
{
struct V_29 * V_22 =
F_2 ( V_25 , struct V_29 , V_22 ) ;
struct V_3 * V_4 ;
struct V_30 * V_21 ;
F_17 ( V_31 ) ;
if ( F_18 ( & V_22 -> V_23 ) )
return;
V_28 -- ;
F_19 ( & V_22 -> V_32 ) ;
V_21 = F_20 ( & V_22 -> V_23 , V_27 , V_28 ) ;
while ( V_21 ) {
V_4 = F_2 ( V_21 , struct V_3 , V_21 ) ;
if ( F_21 ( & V_4 -> V_6 -> V_9 . V_33 ) )
F_22 ( V_22 -> V_34 , & V_4 -> V_2 ) ;
F_23 ( & V_4 -> V_35 , & V_31 ) ;
V_21 = F_24 ( V_21 , V_27 , V_28 ) ;
}
F_25 (mo, &cancelled, link)
F_14 ( V_4 ) ;
F_26 ( & V_22 -> V_32 ) ;
F_27 ( V_22 -> V_34 ) ;
}
static struct V_29 *
F_28 ( struct V_26 * V_15 )
{
struct V_29 * V_22 ;
int V_36 ;
V_22 = F_29 ( sizeof( * V_22 ) , V_37 ) ;
if ( V_22 == NULL )
return F_30 ( - V_38 ) ;
F_31 ( & V_22 -> V_32 ) ;
V_22 -> V_22 . V_39 = & V_40 ;
V_22 -> V_23 = V_41 ;
V_22 -> V_34 = F_32 ( L_2 , V_42 , 0 ) ;
if ( V_22 -> V_34 == NULL ) {
F_33 ( V_22 ) ;
return F_30 ( - V_38 ) ;
}
V_36 = F_34 ( & V_22 -> V_22 , V_15 ) ;
if ( V_36 ) {
F_35 ( V_22 -> V_34 ) ;
F_33 ( V_22 ) ;
return F_30 ( V_36 ) ;
}
return V_22 ;
}
static void
F_36 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
V_4 = V_6 -> V_13 . V_43 ;
if ( V_4 == NULL )
return;
F_19 ( & V_4 -> V_22 -> V_32 ) ;
F_14 ( V_4 ) ;
F_26 ( & V_4 -> V_22 -> V_32 ) ;
F_33 ( V_4 ) ;
V_6 -> V_13 . V_43 = NULL ;
}
static struct V_29 *
F_37 ( struct V_44 * V_15 )
{
struct V_29 * V_22 = V_15 -> V_22 ;
V_22 = V_15 -> V_22 ;
if ( V_22 )
return V_22 ;
F_38 ( & V_15 -> V_15 -> V_45 ) ;
F_5 ( & V_15 -> V_46 -> V_47 ) ;
if ( ( V_22 = V_15 -> V_22 ) == NULL ) {
V_22 = F_28 ( V_15 -> V_15 ) ;
if ( ! F_39 ( V_22 ) )
V_15 -> V_22 = V_22 ;
}
F_11 ( & V_15 -> V_46 -> V_47 ) ;
F_40 ( & V_15 -> V_15 -> V_45 ) ;
return V_22 ;
}
static int
F_41 ( struct V_5 * V_6 ,
unsigned V_48 )
{
struct V_29 * V_22 ;
struct V_3 * V_4 ;
if ( V_48 & V_49 )
return F_42 ( V_50 ) ? 0 : - V_51 ;
if ( F_43 ( V_6 -> V_13 . V_15 == NULL ) )
return - V_52 ;
V_22 = F_37 ( V_6 -> V_13 . V_15 ) ;
if ( F_39 ( V_22 ) )
return F_44 ( V_22 ) ;
V_4 = F_45 ( sizeof( * V_4 ) , V_37 ) ;
if ( V_4 == NULL )
return - V_38 ;
V_4 -> V_22 = V_22 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_21 . V_27 = V_6 -> V_13 . V_53 ;
V_4 -> V_21 . V_54 = V_6 -> V_13 . V_53 + V_6 -> V_9 . V_55 - 1 ;
F_46 ( & V_4 -> V_2 , F_1 ) ;
V_6 -> V_13 . V_43 = V_4 ;
return 0 ;
}
static void
F_47 ( struct V_29 * V_22 ,
struct V_26 * V_15 )
{
if ( V_22 == NULL )
return;
F_48 ( & V_22 -> V_22 , V_15 ) ;
F_35 ( V_22 -> V_34 ) ;
F_33 ( V_22 ) ;
}
static void
F_36 ( struct V_5 * V_6 )
{
}
static int
F_41 ( struct V_5 * V_6 ,
unsigned V_48 )
{
if ( ( V_48 & V_49 ) == 0 )
return - V_56 ;
if ( ! F_42 ( V_50 ) )
return - V_51 ;
return 0 ;
}
static void
F_47 ( struct V_29 * V_22 ,
struct V_26 * V_15 )
{
}
static struct V_44 *
F_49 ( struct V_57 * V_58 , struct V_26 * V_59 )
{
struct V_44 * V_15 ;
F_50 (dev_priv->mm_structs, mm, node, (unsigned long)real)
if ( V_15 -> V_15 == V_59 )
return V_15 ;
return NULL ;
}
static int
F_51 ( struct V_5 * V_6 )
{
struct V_57 * V_58 = F_52 ( V_6 -> V_9 . V_8 ) ;
struct V_44 * V_15 ;
int V_36 = 0 ;
F_5 ( & V_58 -> V_47 ) ;
V_15 = F_49 ( V_58 , V_60 -> V_15 ) ;
if ( V_15 == NULL ) {
V_15 = F_29 ( sizeof( * V_15 ) , V_37 ) ;
if ( V_15 == NULL ) {
V_36 = - V_38 ;
goto V_61;
}
F_53 ( & V_15 -> V_62 ) ;
V_15 -> V_46 = F_52 ( V_6 -> V_9 . V_8 ) ;
V_15 -> V_15 = V_60 -> V_15 ;
F_54 ( & V_60 -> V_15 -> V_63 ) ;
V_15 -> V_22 = NULL ;
F_55 ( V_58 -> V_64 ,
& V_15 -> V_65 , ( unsigned long ) V_15 -> V_15 ) ;
} else
F_56 ( & V_15 -> V_62 ) ;
V_6 -> V_13 . V_15 = V_15 ;
V_61:
F_11 ( & V_58 -> V_47 ) ;
return V_36 ;
}
static void
F_57 ( struct V_1 * V_2 )
{
struct V_44 * V_15 = F_2 ( V_2 , F_3 ( * V_15 ) , V_2 ) ;
F_47 ( V_15 -> V_22 , V_15 -> V_15 ) ;
F_58 ( V_15 -> V_15 ) ;
F_33 ( V_15 ) ;
}
static void
F_59 ( struct V_62 * V_62 )
{
struct V_44 * V_15 = F_2 ( V_62 , F_3 ( * V_15 ) , V_62 ) ;
F_60 ( & V_15 -> V_65 ) ;
F_11 ( & V_15 -> V_46 -> V_47 ) ;
F_46 ( & V_15 -> V_2 , F_57 ) ;
F_61 ( & V_15 -> V_2 ) ;
}
static void
F_62 ( struct V_5 * V_6 )
{
if ( V_6 -> V_13 . V_15 == NULL )
return;
F_63 ( & V_6 -> V_13 . V_15 -> V_62 ,
F_59 ,
& F_52 ( V_6 -> V_9 . V_8 ) -> V_47 ) ;
V_6 -> V_13 . V_15 = NULL ;
}
static int
F_64 ( struct V_66 * * V_67 , struct V_68 * * V_69 , int V_70 )
{
struct V_71 * V_72 ;
int V_36 , V_73 ;
* V_67 = F_29 ( sizeof( * * V_67 ) , V_37 ) ;
if ( * V_67 == NULL )
return - V_38 ;
if ( F_65 () ) {
V_36 = F_66 ( * V_67 , V_70 , V_37 ) ;
if ( V_36 )
goto V_74;
F_67 ((*st)->sgl, sg, num_pages, n)
F_68 ( V_72 , V_69 [ V_73 ] , V_75 , 0 ) ;
} else {
V_36 = F_69 ( * V_67 , V_69 , V_70 ,
0 , V_70 << V_76 ,
V_37 ) ;
if ( V_36 )
goto V_74;
}
return 0 ;
V_74:
F_33 ( * V_67 ) ;
* V_67 = NULL ;
return V_36 ;
}
static struct V_66 *
F_70 ( struct V_5 * V_6 ,
struct V_68 * * V_69 , int V_70 )
{
struct V_66 * V_16 ;
int V_36 ;
V_36 = F_64 ( & V_16 , V_69 , V_70 ) ;
if ( V_36 )
return F_30 ( V_36 ) ;
V_36 = F_71 ( V_6 , V_16 ) ;
if ( V_36 ) {
F_72 ( V_16 ) ;
F_33 ( V_16 ) ;
return F_30 ( V_36 ) ;
}
return V_16 ;
}
static int
F_73 ( struct V_5 * V_6 ,
bool V_77 )
{
int V_36 = 0 ;
#if F_74 ( V_78 )
if ( V_6 -> V_13 . V_43 == NULL )
return 0 ;
F_19 ( & V_6 -> V_13 . V_43 -> V_22 -> V_32 ) ;
if ( ! V_77 )
F_14 ( V_6 -> V_13 . V_43 ) ;
else if ( ! F_75 ( & V_6 -> V_13 . V_43 -> V_2 ) )
F_12 ( V_6 -> V_13 . V_43 ) ;
else
V_36 = - V_79 ;
F_26 ( & V_6 -> V_13 . V_43 -> V_22 -> V_32 ) ;
#endif
return V_36 ;
}
static void
F_76 ( struct V_1 * V_80 )
{
struct V_81 * V_2 = F_2 ( V_80 , F_3 ( * V_2 ) , V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
const int V_82 = V_6 -> V_9 . V_55 >> V_76 ;
struct V_68 * * V_69 ;
int V_83 , V_36 ;
V_36 = - V_38 ;
V_83 = 0 ;
V_69 = F_77 ( V_82 , sizeof( struct V_68 * ) , V_84 ) ;
if ( V_69 != NULL ) {
struct V_26 * V_15 = V_6 -> V_13 . V_15 -> V_15 ;
unsigned int V_48 = 0 ;
if ( ! V_6 -> V_13 . V_85 )
V_48 |= V_86 ;
V_36 = - V_87 ;
if ( F_78 ( & V_15 -> V_88 ) ) {
F_79 ( & V_15 -> V_45 ) ;
while ( V_83 < V_82 ) {
V_36 = F_80
( V_2 -> V_89 , V_15 ,
V_6 -> V_13 . V_53 + V_83 * V_75 ,
V_82 - V_83 ,
V_48 ,
V_69 + V_83 , NULL , NULL ) ;
if ( V_36 < 0 )
break;
V_83 += V_36 ;
}
F_81 ( & V_15 -> V_45 ) ;
F_82 ( V_15 ) ;
}
}
F_5 ( & V_6 -> V_15 . V_32 ) ;
if ( V_6 -> V_13 . V_2 == & V_2 -> V_2 ) {
struct V_66 * V_16 = F_30 ( V_36 ) ;
if ( V_83 == V_82 ) {
V_16 = F_70 ( V_6 , V_69 , V_82 ) ;
if ( ! F_39 ( V_16 ) ) {
F_83 ( V_6 , V_16 ) ;
V_83 = 0 ;
V_16 = NULL ;
}
}
V_6 -> V_13 . V_2 = F_84 ( V_16 ) ;
}
F_11 ( & V_6 -> V_15 . V_32 ) ;
F_85 ( V_69 , V_83 , 0 ) ;
F_86 ( V_69 ) ;
F_10 ( V_6 ) ;
F_87 ( V_2 -> V_89 ) ;
F_33 ( V_2 ) ;
}
static struct V_66 *
F_88 ( struct V_5 * V_6 ,
bool * V_90 )
{
struct V_81 * V_2 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_37 ) ;
if ( V_2 == NULL )
return F_30 ( - V_38 ) ;
V_6 -> V_13 . V_2 = & V_2 -> V_2 ;
V_2 -> V_6 = F_89 ( V_6 ) ;
V_2 -> V_89 = V_60 ;
F_90 ( V_2 -> V_89 ) ;
F_46 ( & V_2 -> V_2 , F_76 ) ;
F_61 ( & V_2 -> V_2 ) ;
* V_90 = true ;
return F_30 ( - V_79 ) ;
}
static struct V_66 *
F_91 ( struct V_5 * V_6 )
{
const int V_70 = V_6 -> V_9 . V_55 >> V_76 ;
struct V_68 * * V_69 ;
struct V_66 * V_16 ;
int V_83 , V_36 ;
bool V_90 ;
if ( V_6 -> V_13 . V_2 ) {
if ( F_39 ( V_6 -> V_13 . V_2 ) )
return F_84 ( V_6 -> V_13 . V_2 ) ;
else
return F_30 ( - V_79 ) ;
}
V_36 = F_73 ( V_6 , true ) ;
if ( V_36 )
return F_30 ( V_36 ) ;
V_69 = NULL ;
V_83 = 0 ;
if ( V_6 -> V_13 . V_15 -> V_15 == V_60 -> V_15 ) {
V_69 = F_77 ( V_70 , sizeof( struct V_68 * ) ,
V_84 ) ;
if ( V_69 == NULL ) {
F_73 ( V_6 , false ) ;
return F_30 ( - V_38 ) ;
}
V_83 = F_92 ( V_6 -> V_13 . V_53 , V_70 ,
! V_6 -> V_13 . V_85 , V_69 ) ;
}
V_90 = false ;
if ( V_83 < 0 )
V_16 = F_30 ( V_83 ) , V_83 = 0 ;
else if ( V_83 < V_70 )
V_16 = F_88 ( V_6 , & V_90 ) ;
else
V_16 = F_70 ( V_6 , V_69 , V_70 ) ;
if ( F_39 ( V_16 ) ) {
F_73 ( V_6 , V_90 ) ;
F_85 ( V_69 , V_83 , 0 ) ;
}
F_86 ( V_69 ) ;
return V_16 ;
}
static void
F_93 ( struct V_5 * V_6 ,
struct V_66 * V_16 )
{
struct V_91 V_91 ;
struct V_68 * V_68 ;
F_94 ( V_6 -> V_13 . V_2 != NULL ) ;
F_73 ( V_6 , false ) ;
if ( V_6 -> V_15 . V_92 != V_93 )
V_6 -> V_15 . V_94 = false ;
F_95 ( V_6 , V_16 ) ;
F_96 (page, sgt_iter, pages) {
if ( V_6 -> V_15 . V_94 )
F_97 ( V_68 ) ;
F_98 ( V_68 ) ;
F_99 ( V_68 ) ;
}
V_6 -> V_15 . V_94 = false ;
F_72 ( V_16 ) ;
F_33 ( V_16 ) ;
}
static void
F_100 ( struct V_5 * V_6 )
{
F_36 ( V_6 ) ;
F_62 ( V_6 ) ;
}
static int
F_101 ( struct V_5 * V_6 )
{
if ( V_6 -> V_13 . V_43 )
return 0 ;
return F_41 ( V_6 , 0 ) ;
}
int
F_102 ( struct V_7 * V_8 , void * V_95 , struct V_96 * V_97 )
{
struct V_57 * V_58 = F_52 ( V_8 ) ;
struct V_98 * args = V_95 ;
struct V_5 * V_6 ;
int V_36 ;
T_1 V_99 ;
if ( ! F_103 ( V_58 ) && ! F_104 ( V_58 ) ) {
return - V_56 ;
}
if ( args -> V_48 & ~ ( V_100 |
V_49 ) )
return - V_52 ;
if ( F_105 ( args -> V_101 | args -> V_102 ) )
return - V_52 ;
if ( ! F_106 ( args -> V_48 & V_100 ? V_103 : V_104 ,
( char V_105 * ) ( unsigned long ) args -> V_101 , args -> V_102 ) )
return - V_87 ;
if ( args -> V_48 & V_100 ) {
return - V_56 ;
}
V_6 = F_107 ( V_8 ) ;
if ( V_6 == NULL )
return - V_38 ;
F_108 ( V_8 , & V_6 -> V_9 , args -> V_102 ) ;
F_109 ( V_6 , & V_106 ) ;
V_6 -> V_107 = V_108 ;
V_6 -> V_9 . V_109 = V_110 ;
V_6 -> V_9 . V_111 = V_110 ;
V_6 -> V_13 . V_53 = args -> V_101 ;
V_6 -> V_13 . V_85 = ! ! ( args -> V_48 & V_100 ) ;
V_36 = F_51 ( V_6 ) ;
if ( V_36 == 0 )
V_36 = F_41 ( V_6 , args -> V_48 ) ;
if ( V_36 == 0 )
V_36 = F_110 ( V_97 , & V_6 -> V_9 , & V_99 ) ;
F_10 ( V_6 ) ;
if ( V_36 )
return V_36 ;
args -> V_99 = V_99 ;
return 0 ;
}
void F_111 ( struct V_57 * V_58 )
{
F_112 ( & V_58 -> V_47 ) ;
F_113 ( V_58 -> V_64 ) ;
}
