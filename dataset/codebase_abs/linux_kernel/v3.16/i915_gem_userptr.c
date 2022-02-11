static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_5 ,
unsigned long V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 , V_8 ) ;
struct V_9 * V_10 = NULL ;
unsigned long V_11 = 0 ;
V_6 -- ;
while ( V_5 < V_6 ) {
struct V_12 * V_13 ;
V_13 = NULL ;
F_3 ( & V_8 -> V_14 ) ;
if ( V_11 == V_8 -> V_11 )
V_10 = F_4 ( V_10 , V_5 , V_6 ) ;
else
V_10 = F_5 ( & V_8 -> V_15 , V_5 , V_6 ) ;
if ( V_10 != NULL ) {
V_13 = F_2 ( V_10 , struct V_16 , V_10 ) -> V_13 ;
F_6 ( & V_13 -> V_17 ) ;
V_11 = V_8 -> V_11 ;
}
F_7 ( & V_8 -> V_14 ) ;
if ( V_13 == NULL )
return;
F_8 ( & V_8 -> V_18 -> V_19 ) ;
V_13 -> V_20 . V_21 = NULL ;
if ( V_13 -> V_22 != NULL ) {
struct V_23 * V_24 = F_9 ( V_8 -> V_18 ) ;
struct V_25 * V_26 , * V_27 ;
bool V_28 ;
V_28 = V_24 -> V_4 . V_29 ;
V_24 -> V_4 . V_29 = false ;
F_10 (vma, tmp, &obj->vma_list, vma_link) {
int V_30 = F_11 ( V_26 ) ;
F_12 ( V_30 && V_30 != - V_31 ) ;
}
F_12 ( F_13 ( V_13 ) ) ;
V_24 -> V_4 . V_29 = V_28 ;
}
V_5 = V_13 -> V_20 . V_32 + V_13 -> V_17 . V_33 ;
F_14 ( & V_13 -> V_17 ) ;
F_15 ( & V_8 -> V_18 -> V_19 ) ;
}
}
static struct V_7 *
F_16 ( struct V_34 * V_18 , struct V_3 * V_4 )
{
struct V_23 * V_24 = F_9 ( V_18 ) ;
struct V_7 * V_35 ;
F_17 (dev_priv->mmu_notifiers, mmu, node, (unsigned long)mm)
if ( V_35 -> V_4 == V_4 )
return V_35 ;
return NULL ;
}
static struct V_7 *
F_18 ( struct V_34 * V_18 , struct V_3 * V_4 )
{
struct V_23 * V_24 = F_9 ( V_18 ) ;
struct V_7 * V_35 ;
int V_30 ;
F_19 ( & V_18 -> V_19 ) ;
V_35 = F_16 ( V_18 , V_4 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_20 ( sizeof( * V_35 ) , V_36 ) ;
if ( V_35 == NULL )
return F_21 ( - V_37 ) ;
F_22 ( & V_35 -> V_14 ) ;
V_35 -> V_18 = V_18 ;
V_35 -> V_8 . V_38 = & V_39 ;
V_35 -> V_4 = V_4 ;
V_35 -> V_15 = V_40 ;
V_35 -> V_41 = 0 ;
V_35 -> V_11 = 0 ;
V_30 = F_23 ( & V_35 -> V_8 , V_4 ) ;
if ( V_30 ) {
F_24 ( V_35 ) ;
return F_21 ( V_30 ) ;
}
F_25 ( V_24 -> V_42 , & V_35 -> V_43 , ( unsigned long ) V_4 ) ;
return V_35 ;
}
static void
F_26 ( struct V_44 * V_21 )
{
struct V_7 * V_35 = F_2 ( V_21 , F_27 ( * V_35 ) , V_21 ) ;
F_28 ( & V_35 -> V_8 , V_35 -> V_4 ) ;
F_24 ( V_35 ) ;
}
static void
F_29 ( struct V_7 * V_35 )
{
F_19 ( & V_35 -> V_18 -> V_19 ) ;
F_30 ( & V_35 -> V_43 ) ;
F_31 ( & V_35 -> V_21 , F_26 ) ;
F_32 ( & V_35 -> V_21 ) ;
}
static void F_33 ( struct V_7 * V_35 )
{
if ( ++ V_35 -> V_11 == 0 )
V_35 -> V_11 = 1 ;
}
static void
F_34 ( struct V_7 * V_35 ,
struct V_16 * V_8 )
{
F_19 ( & V_35 -> V_18 -> V_19 ) ;
F_3 ( & V_35 -> V_14 ) ;
F_35 ( & V_8 -> V_10 , & V_35 -> V_15 ) ;
F_33 ( V_35 ) ;
F_7 ( & V_35 -> V_14 ) ;
if ( -- V_35 -> V_41 == 0 )
F_29 ( V_35 ) ;
}
static int
F_36 ( struct V_7 * V_35 ,
struct V_16 * V_8 )
{
struct V_9 * V_10 ;
int V_30 ;
V_30 = F_37 ( V_35 -> V_18 ) ;
if ( V_30 )
return V_30 ;
F_38 ( V_35 -> V_18 ) ;
F_3 ( & V_35 -> V_14 ) ;
V_10 = F_5 ( & V_35 -> V_15 ,
V_8 -> V_10 . V_5 , V_8 -> V_10 . V_45 ) ;
if ( V_10 ) {
struct V_12 * V_13 ;
V_13 = F_2 ( V_10 , struct V_16 , V_10 ) -> V_13 ;
V_30 = V_13 -> V_20 . V_46 ? - V_47 : - V_48 ;
} else {
F_39 ( & V_8 -> V_10 , & V_35 -> V_15 ) ;
F_33 ( V_35 ) ;
V_30 = 0 ;
}
F_7 ( & V_35 -> V_14 ) ;
F_15 ( & V_35 -> V_18 -> V_19 ) ;
return V_30 ;
}
static void
F_40 ( struct V_12 * V_13 )
{
struct V_16 * V_8 ;
V_8 = V_13 -> V_20 . V_8 ;
if ( V_8 == NULL )
return;
F_34 ( V_8 -> V_35 , V_8 ) ;
V_13 -> V_20 . V_8 = NULL ;
}
static int
F_41 ( struct V_12 * V_13 ,
unsigned V_49 )
{
struct V_7 * V_35 ;
struct V_16 * V_8 ;
int V_30 ;
if ( V_49 & V_50 )
return F_42 ( V_51 ) ? 0 : - V_52 ;
F_43 ( & V_13 -> V_20 . V_4 -> V_53 ) ;
V_30 = F_37 ( V_13 -> V_17 . V_18 ) ;
if ( V_30 == 0 ) {
V_35 = F_18 ( V_13 -> V_17 . V_18 , V_13 -> V_20 . V_4 ) ;
if ( ! F_44 ( V_35 ) )
V_35 -> V_41 ++ ;
else
V_30 = F_45 ( V_35 ) ;
F_15 ( & V_13 -> V_17 . V_18 -> V_19 ) ;
}
F_46 ( & V_13 -> V_20 . V_4 -> V_53 ) ;
if ( V_30 )
return V_30 ;
V_8 = F_47 ( sizeof( * V_8 ) , V_36 ) ;
if ( V_8 == NULL ) {
V_30 = - V_37 ;
goto V_54;
}
V_8 -> V_35 = V_35 ;
V_8 -> V_10 . V_5 = V_13 -> V_20 . V_32 ;
V_8 -> V_10 . V_45 = V_8 -> V_10 . V_5 + V_13 -> V_17 . V_33 - 1 ;
V_8 -> V_13 = V_13 ;
V_30 = F_36 ( V_35 , V_8 ) ;
if ( V_30 )
goto V_55;
V_13 -> V_20 . V_8 = V_8 ;
return 0 ;
V_55:
F_24 ( V_8 ) ;
V_54:
F_8 ( & V_13 -> V_17 . V_18 -> V_19 ) ;
if ( -- V_35 -> V_41 == 0 )
F_29 ( V_35 ) ;
F_15 ( & V_13 -> V_17 . V_18 -> V_19 ) ;
return V_30 ;
}
static void
F_40 ( struct V_12 * V_13 )
{
}
static int
F_41 ( struct V_12 * V_13 ,
unsigned V_49 )
{
if ( ( V_49 & V_50 ) == 0 )
return - V_56 ;
if ( ! F_42 ( V_51 ) )
return - V_52 ;
return 0 ;
}
static int
F_48 ( struct V_57 * * V_58 , struct V_59 * * V_60 , int V_61 )
{
struct V_62 * V_63 ;
int V_30 , V_64 ;
* V_58 = F_20 ( sizeof( * * V_58 ) , V_36 ) ;
if ( * V_58 == NULL )
return - V_37 ;
if ( F_49 () ) {
V_30 = F_50 ( * V_58 , V_61 , V_36 ) ;
if ( V_30 )
goto V_65;
F_51 ((*st)->sgl, sg, num_pages, n)
F_52 ( V_63 , V_60 [ V_64 ] , V_66 , 0 ) ;
} else {
V_30 = F_53 ( * V_58 , V_60 , V_61 ,
0 , V_61 << V_67 ,
V_36 ) ;
if ( V_30 )
goto V_65;
}
return 0 ;
V_65:
F_24 ( * V_58 ) ;
* V_58 = NULL ;
return V_30 ;
}
static void
F_54 ( struct V_44 * V_68 )
{
struct V_69 * V_21 = F_2 ( V_68 , F_27 ( * V_21 ) , V_21 ) ;
struct V_12 * V_13 = V_21 -> V_13 ;
struct V_34 * V_18 = V_13 -> V_17 . V_18 ;
const int V_61 = V_13 -> V_17 . V_33 >> V_67 ;
struct V_59 * * V_60 ;
int V_70 , V_30 ;
V_30 = - V_37 ;
V_70 = 0 ;
V_60 = F_20 ( V_61 * sizeof( struct V_59 * ) ,
V_71 | V_72 | V_73 ) ;
if ( V_60 == NULL )
V_60 = F_55 ( V_61 , sizeof( struct V_59 * ) ) ;
if ( V_60 != NULL ) {
struct V_3 * V_4 = V_13 -> V_20 . V_4 ;
F_56 ( & V_4 -> V_53 ) ;
while ( V_70 < V_61 ) {
V_30 = F_57 ( V_21 -> V_74 , V_4 ,
V_13 -> V_20 . V_32 + V_70 * V_66 ,
V_61 - V_70 ,
! V_13 -> V_20 . V_75 , 0 ,
V_60 + V_70 , NULL ) ;
if ( V_30 < 0 )
break;
V_70 += V_30 ;
}
F_58 ( & V_4 -> V_53 ) ;
}
F_8 ( & V_18 -> V_19 ) ;
if ( V_13 -> V_20 . V_21 != & V_21 -> V_21 ) {
V_30 = 0 ;
} else if ( V_70 == V_61 ) {
V_30 = F_48 ( & V_13 -> V_22 , V_60 , V_61 ) ;
if ( V_30 == 0 ) {
F_59 ( & V_13 -> V_76 , & F_9 ( V_18 ) -> V_4 . V_77 ) ;
V_70 = 0 ;
}
}
V_13 -> V_20 . V_21 = F_21 ( V_30 ) ;
V_13 -> V_20 . V_46 -- ;
F_14 ( & V_13 -> V_17 ) ;
F_15 ( & V_18 -> V_19 ) ;
F_60 ( V_60 , V_70 , 0 ) ;
F_61 ( V_60 ) ;
F_62 ( V_21 -> V_74 ) ;
F_24 ( V_21 ) ;
}
static int
F_63 ( struct V_12 * V_13 )
{
const int V_61 = V_13 -> V_17 . V_33 >> V_67 ;
struct V_59 * * V_60 ;
int V_70 , V_30 ;
V_60 = NULL ;
V_70 = 0 ;
if ( V_13 -> V_20 . V_4 == V_78 -> V_4 ) {
V_60 = F_20 ( V_61 * sizeof( struct V_59 * ) ,
V_71 | V_72 | V_73 ) ;
if ( V_60 == NULL ) {
V_60 = F_55 ( V_61 , sizeof( struct V_59 * ) ) ;
if ( V_60 == NULL )
return - V_37 ;
}
V_70 = F_64 ( V_13 -> V_20 . V_32 , V_61 ,
! V_13 -> V_20 . V_75 , V_60 ) ;
}
if ( V_70 < V_61 ) {
if ( V_70 < 0 ) {
V_30 = V_70 ;
V_70 = 0 ;
} else {
V_30 = - V_47 ;
if ( V_13 -> V_20 . V_21 == NULL &&
V_13 -> V_20 . V_46 < V_79 ) {
struct V_69 * V_21 ;
V_21 = F_20 ( sizeof( * V_21 ) , V_36 ) ;
if ( V_21 != NULL ) {
V_13 -> V_20 . V_21 = & V_21 -> V_21 ;
V_13 -> V_20 . V_46 ++ ;
V_21 -> V_13 = V_13 ;
F_6 ( & V_13 -> V_17 ) ;
V_21 -> V_74 = V_78 ;
F_65 ( V_21 -> V_74 ) ;
F_31 ( & V_21 -> V_21 , F_54 ) ;
F_32 ( & V_21 -> V_21 ) ;
} else
V_30 = - V_37 ;
} else {
if ( F_44 ( V_13 -> V_20 . V_21 ) ) {
V_30 = F_45 ( V_13 -> V_20 . V_21 ) ;
V_13 -> V_20 . V_21 = NULL ;
}
}
}
} else {
V_30 = F_48 ( & V_13 -> V_22 , V_60 , V_61 ) ;
if ( V_30 == 0 ) {
V_13 -> V_20 . V_21 = NULL ;
V_70 = 0 ;
}
}
F_60 ( V_60 , V_70 , 0 ) ;
F_61 ( V_60 ) ;
return V_30 ;
}
static void
F_66 ( struct V_12 * V_13 )
{
struct V_62 * V_63 ;
int V_80 ;
F_67 ( V_13 -> V_20 . V_21 != NULL ) ;
if ( V_13 -> V_81 != V_82 )
V_13 -> V_83 = 0 ;
F_51 (obj->pages->sgl, sg, obj->pages->nents, i) {
struct V_59 * V_59 = F_68 ( V_63 ) ;
if ( V_13 -> V_83 )
F_69 ( V_59 ) ;
F_70 ( V_59 ) ;
F_71 ( V_59 ) ;
}
V_13 -> V_83 = 0 ;
F_72 ( V_13 -> V_22 ) ;
F_24 ( V_13 -> V_22 ) ;
}
static void
F_73 ( struct V_12 * V_13 )
{
F_40 ( V_13 ) ;
if ( V_13 -> V_20 . V_4 ) {
F_74 ( V_13 -> V_20 . V_4 ) ;
V_13 -> V_20 . V_4 = NULL ;
}
}
static int
F_75 ( struct V_12 * V_13 )
{
if ( V_13 -> V_20 . V_8 )
return 0 ;
return F_41 ( V_13 , 0 ) ;
}
int
F_76 ( struct V_34 * V_18 , void * V_84 , struct V_85 * V_86 )
{
struct V_23 * V_24 = V_18 -> V_87 ;
struct V_88 * args = V_84 ;
struct V_12 * V_13 ;
int V_30 ;
T_1 V_89 ;
if ( args -> V_49 & ~ ( V_90 |
V_50 ) )
return - V_48 ;
if ( F_77 ( args -> V_91 | args -> V_92 ) )
return - V_48 ;
if ( args -> V_92 > V_24 -> V_93 . V_17 . V_94 )
return - V_95 ;
if ( ! F_78 ( args -> V_49 & V_90 ? V_96 : V_97 ,
( char V_98 * ) ( unsigned long ) args -> V_91 , args -> V_92 ) )
return - V_99 ;
if ( args -> V_49 & V_90 ) {
return - V_56 ;
}
V_13 = F_79 ( V_18 ) ;
if ( V_13 == NULL )
return - V_37 ;
F_80 ( V_18 , & V_13 -> V_17 , args -> V_92 ) ;
F_81 ( V_13 , & V_100 ) ;
V_13 -> V_101 = V_102 ;
V_13 -> V_17 . V_103 = V_104 ;
V_13 -> V_17 . V_105 = V_104 ;
V_13 -> V_20 . V_32 = args -> V_91 ;
V_13 -> V_20 . V_75 = ! ! ( args -> V_49 & V_90 ) ;
V_30 = - V_37 ;
if ( ( V_13 -> V_20 . V_4 = F_82 ( V_78 ) ) )
V_30 = F_41 ( V_13 , args -> V_49 ) ;
if ( V_30 == 0 )
V_30 = F_83 ( V_86 , & V_13 -> V_17 , & V_89 ) ;
F_84 ( & V_13 -> V_17 ) ;
if ( V_30 )
return V_30 ;
args -> V_89 = V_89 ;
return 0 ;
}
int
F_85 ( struct V_34 * V_18 )
{
#if F_86 ( V_106 )
struct V_23 * V_24 = F_9 ( V_18 ) ;
F_87 ( V_24 -> V_42 ) ;
#endif
return 0 ;
}
