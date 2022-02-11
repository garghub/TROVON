static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const char * V_7 , T_2 V_8 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
int V_9 ;
unsigned V_10 ;
V_9 = sscanf ( V_7 , L_1 , & V_10 ) ;
if ( V_9 == 0 )
return V_8 ;
V_10 = V_10 / ( V_11 >> 10 ) ;
if ( V_6 == & V_12 )
V_4 -> V_13 . V_14 = V_10 ;
else if ( V_6 == & V_15 )
V_4 -> V_13 . V_16 = V_10 ;
else if ( V_6 == & V_17 ) {
if ( V_10 > V_18 * 8 ) {
F_5 ( L_2 ,
V_18 * ( V_11 >> 7 ) ,
V_18 * ( V_11 >> 10 ) ) ;
return V_8 ;
} else if ( V_10 > V_18 ) {
F_6 ( L_3 ,
V_18 * ( V_11 >> 10 ) ) ;
}
V_4 -> V_13 . V_19 = V_10 ;
}
return V_8 ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
unsigned V_10 = 0 ;
if ( V_6 == & V_12 )
V_10 = V_4 -> V_13 . V_14 ;
else if ( V_6 == & V_15 )
V_10 = V_4 -> V_13 . V_16 ;
else if ( V_6 == & V_17 )
V_10 = V_4 -> V_13 . V_19 ;
V_10 = V_10 * ( V_11 >> 10 ) ;
return snprintf ( V_7 , V_11 , L_4 , V_10 ) ;
}
static int F_8 ( struct V_20 * * V_21 , int V_22 )
{
#ifdef F_9
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
F_10 ( V_21 [ V_23 ] ) ;
#endif
return 0 ;
}
static int F_11 ( struct V_20 * * V_21 , int V_22 )
{
#ifdef F_9
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
F_12 ( V_21 [ V_23 ] ) ;
#endif
return 0 ;
}
static int F_13 ( struct V_20 * * V_21 , int V_22 )
{
#ifdef F_9
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
F_12 ( V_21 [ V_23 ] ) ;
#endif
return 0 ;
}
static int F_14 ( struct V_24 * V_25 ,
struct V_20 * * V_21 , unsigned V_26 )
{
int V_27 = 0 ;
if ( V_25 -> type & V_28 ) {
V_27 = F_13 ( V_21 , V_26 ) ;
if ( V_27 )
F_5 ( L_5 ,
V_25 -> V_29 , V_26 ) ;
}
if ( V_25 -> type & V_30 ) {
V_27 = F_11 ( V_21 , V_26 ) ;
if ( V_27 )
F_5 ( L_6 ,
V_25 -> V_29 , V_26 ) ;
}
return V_27 ;
}
static void F_15 ( struct V_24 * V_25 , struct V_31 * V_32 )
{
T_3 V_33 = V_32 -> V_33 ;
F_16 ( V_25 -> V_34 , V_25 -> V_8 , V_32 -> V_35 , V_33 ) ;
F_3 ( V_32 ) ;
V_32 = NULL ;
}
static struct V_31 * F_17 ( struct V_24 * V_25 )
{
struct V_31 * V_32 ;
V_32 = F_18 ( sizeof( struct V_31 ) , V_36 ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_35 = F_19 ( V_25 -> V_34 , V_25 -> V_8 ,
& V_32 -> V_33 ,
V_25 -> V_37 ) ;
if ( V_32 -> V_35 )
V_32 -> V_38 = F_20 ( V_32 -> V_35 ) ;
else {
F_3 ( V_32 ) ;
V_32 = NULL ;
}
return V_32 ;
}
static enum V_39 F_21 ( int V_40 , enum V_41 V_42 )
{
enum V_39 type = V_43 ;
if ( V_40 & V_44 )
type |= V_45 ;
if ( V_42 == V_46 )
type |= V_47 ;
else if ( V_42 == V_48 )
type |= V_28 ;
else
type |= V_30 ;
return type ;
}
static void F_22 ( struct V_24 * V_25 ,
unsigned V_49 )
{
V_25 -> V_50 -= V_49 ;
V_25 -> V_51 += V_49 ;
}
static void F_23 ( struct V_24 * V_25 , struct V_52 * V_53 ,
struct V_20 * V_21 [] , unsigned V_54 )
{
struct V_31 * V_32 , * V_55 ;
if ( V_54 && ! ( V_25 -> type & V_47 ) &&
F_8 ( V_21 , V_54 ) )
F_5 ( L_7 ,
V_25 -> V_29 , V_54 ) ;
F_24 (d_page, tmp, d_pages, page_list) {
F_25 ( & V_32 -> V_56 ) ;
F_15 ( V_25 , V_32 ) ;
}
}
static void F_26 ( struct V_24 * V_25 , struct V_31 * V_32 )
{
if ( ! ( V_25 -> type & V_47 ) && F_8 ( & V_32 -> V_38 , 1 ) )
F_5 ( L_7 ,
V_25 -> V_29 , 1 ) ;
F_25 ( & V_32 -> V_56 ) ;
F_15 ( V_25 , V_32 ) ;
}
static unsigned F_27 ( struct V_24 * V_25 , unsigned V_57 )
{
unsigned long V_58 ;
struct V_31 * V_59 , * V_55 ;
struct V_20 * * V_60 ;
struct V_52 V_53 ;
unsigned V_49 = 0 ,
V_61 = V_57 ;
if ( V_18 < V_57 )
V_61 = V_18 ;
#if 0
if (nr_free > 1) {
pr_debug("%s: (%s:%d) Attempting to free %d (%d) pages\n",
pool->dev_name, pool->name, current->pid,
npages_to_free, nr_free);
}
#endif
V_60 = F_18 ( V_61 * sizeof( struct V_20 * ) ,
V_36 ) ;
if ( ! V_60 ) {
F_5 ( L_8 ,
V_25 -> V_29 ) ;
return 0 ;
}
F_28 ( & V_53 ) ;
V_62:
F_29 ( & V_25 -> V_63 , V_58 ) ;
F_30 (dma_p, tmp, &pool->free_list,
page_list) {
if ( V_49 >= V_61 )
break;
F_31 ( & V_59 -> V_56 , & V_53 ) ;
V_60 [ V_49 ++ ] = V_59 -> V_38 ;
if ( V_49 >= V_18 ) {
F_22 ( V_25 , V_49 ) ;
F_32 ( & V_25 -> V_63 , V_58 ) ;
F_23 ( V_25 , & V_53 , V_60 ,
V_49 ) ;
F_28 ( & V_53 ) ;
if ( F_33 ( V_57 != V_64 ) )
V_57 -= V_49 ;
if ( V_18 >= V_57 )
V_61 = V_57 ;
else
V_61 = V_18 ;
V_49 = 0 ;
if ( V_57 )
goto V_62;
goto V_65;
}
}
if ( V_49 ) {
F_22 ( V_25 , V_49 ) ;
V_57 -= V_49 ;
}
F_32 ( & V_25 -> V_63 , V_58 ) ;
if ( V_49 )
F_23 ( V_25 , & V_53 , V_60 , V_49 ) ;
V_65:
F_3 ( V_60 ) ;
return V_57 ;
}
static void F_34 ( struct V_66 * V_34 , enum V_39 type )
{
struct V_67 * V_38 ;
struct V_24 * V_25 ;
if ( ! V_34 )
return;
F_35 ( & V_68 -> V_63 ) ;
F_36 (p, &_manager->pools, pools) {
if ( V_38 -> V_34 != V_34 )
continue;
V_25 = V_38 -> V_25 ;
if ( V_25 -> type != type )
continue;
F_25 ( & V_38 -> V_69 ) ;
F_3 ( V_38 ) ;
V_68 -> V_70 -- ;
break;
}
F_36 (pool, &dev->dma_pools, pools) {
if ( V_25 -> type != type )
continue;
F_27 ( V_25 , V_64 ) ;
F_37 ( ( ( V_25 -> V_71 + V_25 -> V_50 ) != 0 ) ) ;
F_25 ( & V_25 -> V_69 ) ;
F_3 ( V_25 ) ;
break;
}
F_38 ( & V_68 -> V_63 ) ;
}
static void F_39 ( struct V_66 * V_34 , void * V_72 )
{
struct V_24 * V_25 = * (struct V_24 * * ) V_72 ;
if ( V_25 )
F_34 ( V_34 , V_25 -> type ) ;
}
static int F_40 ( struct V_66 * V_34 , void * V_72 , void * V_73 )
{
return * (struct V_24 * * ) V_72 == V_73 ;
}
static struct V_24 * F_41 ( struct V_66 * V_34 , T_4 V_40 ,
enum V_39 type )
{
char * V_74 [] = { L_9 , L_10 , L_11 , L_12 , L_13 ,} ;
enum V_39 V_75 [] = { V_30 , V_28 , V_47 , V_45 , V_43 } ;
struct V_67 * V_76 = NULL ;
struct V_24 * V_25 = NULL , * * V_77 ;
unsigned V_23 ;
int V_78 = - V_79 ;
char * V_38 ;
if ( ! V_34 )
return NULL ;
V_77 = F_42 ( F_39 , sizeof( * V_77 ) , V_36 ) ;
if ( ! V_77 )
return NULL ;
V_78 = - V_80 ;
V_25 = F_43 ( sizeof( struct V_24 ) , V_36 ,
F_44 ( V_34 ) ) ;
if ( ! V_25 )
goto V_81;
V_76 = F_43 ( sizeof( struct V_67 ) , V_36 ,
F_44 ( V_34 ) ) ;
if ( ! V_76 )
goto V_81;
F_28 ( & V_76 -> V_69 ) ;
V_76 -> V_34 = V_34 ;
V_76 -> V_25 = V_25 ;
F_28 ( & V_25 -> V_82 ) ;
F_28 ( & V_25 -> V_83 ) ;
F_28 ( & V_25 -> V_69 ) ;
F_45 ( & V_25 -> V_63 ) ;
V_25 -> V_34 = V_34 ;
V_25 -> V_50 = V_25 -> V_71 = 0 ;
V_25 -> V_51 = 0 ;
V_25 -> V_37 = V_40 ;
V_25 -> V_8 = V_11 ;
V_25 -> type = type ;
V_25 -> V_84 = 0 ;
V_38 = V_25 -> V_85 ;
for ( V_23 = 0 ; V_23 < 5 ; V_23 ++ ) {
if ( type & V_75 [ V_23 ] ) {
V_38 += snprintf ( V_38 , sizeof( V_25 -> V_85 ) - ( V_38 - V_25 -> V_85 ) ,
L_14 , V_74 [ V_23 ] ) ;
}
}
* V_38 = 0 ;
snprintf ( V_25 -> V_29 , sizeof( V_25 -> V_29 ) , L_15 ,
F_46 ( V_34 ) , V_29 ( V_34 ) ) ;
F_35 ( & V_68 -> V_63 ) ;
F_47 ( & V_76 -> V_69 , & V_68 -> V_69 ) ;
V_68 -> V_70 ++ ;
F_47 ( & V_25 -> V_69 , & V_34 -> V_86 ) ;
F_38 ( & V_68 -> V_63 ) ;
* V_77 = V_25 ;
F_48 ( V_34 , V_77 ) ;
return V_25 ;
V_81:
F_49 ( V_77 ) ;
F_3 ( V_76 ) ;
F_3 ( V_25 ) ;
return F_50 ( V_78 ) ;
}
static struct V_24 * F_51 ( struct V_66 * V_34 ,
enum V_39 type )
{
struct V_24 * V_25 , * V_55 , * V_87 = NULL ;
if ( type == V_43 )
return V_87 ;
F_24 (pool, tmp, &dev->dma_pools, pools) {
if ( V_25 -> type != type )
continue;
V_87 = V_25 ;
break;
}
return V_87 ;
}
static void F_52 ( struct V_24 * V_25 ,
struct V_52 * V_53 ,
struct V_20 * * V_88 ,
unsigned V_26 )
{
struct V_31 * V_32 , * V_55 ;
struct V_20 * V_38 ;
unsigned V_23 = 0 ;
V_38 = V_88 [ 0 ] ;
if ( ! V_38 )
return;
F_24 (d_page, tmp, d_pages, page_list) {
if ( V_32 -> V_38 != V_38 )
continue;
F_25 ( & V_32 -> V_56 ) ;
F_15 ( V_25 , V_32 ) ;
if ( ++ V_23 < V_26 )
V_38 = V_88 [ V_23 ] ;
else
break;
}
}
static int F_53 ( struct V_24 * V_25 ,
struct V_52 * V_53 ,
unsigned V_89 )
{
struct V_20 * * V_90 ;
struct V_31 * V_59 ;
struct V_20 * V_38 ;
int V_27 = 0 ;
unsigned V_23 , V_26 ;
unsigned V_91 = F_54 ( V_89 ,
( unsigned ) ( V_11 / sizeof( struct V_20 * ) ) ) ;
V_90 = F_18 ( V_91 * sizeof( struct V_20 * ) , V_36 ) ;
if ( ! V_90 ) {
F_5 ( L_16 ,
V_25 -> V_29 ) ;
return - V_80 ;
}
if ( V_89 > 1 ) {
F_55 ( L_17 ,
V_25 -> V_29 , V_25 -> V_85 , V_92 -> V_93 , V_89 ) ;
}
for ( V_23 = 0 , V_26 = 0 ; V_23 < V_89 ; ++ V_23 ) {
V_59 = F_17 ( V_25 ) ;
if ( ! V_59 ) {
F_5 ( L_18 ,
V_25 -> V_29 , V_23 ) ;
if ( V_26 ) {
V_27 = F_14 ( V_25 , V_90 ,
V_26 ) ;
if ( V_27 )
F_52 (
V_25 , V_53 , V_90 ,
V_26 ) ;
}
V_27 = - V_80 ;
goto V_65;
}
V_38 = V_59 -> V_38 ;
#ifdef F_56
if ( ! F_57 ( V_38 ) )
#endif
{
V_90 [ V_26 ++ ] = V_38 ;
if ( V_26 == V_91 ) {
V_27 = F_14 ( V_25 , V_90 ,
V_26 ) ;
if ( V_27 ) {
F_52 (
V_25 , V_53 , V_90 ,
V_26 ) ;
goto V_65;
}
V_26 = 0 ;
}
}
F_47 ( & V_59 -> V_56 , V_53 ) ;
}
if ( V_26 ) {
V_27 = F_14 ( V_25 , V_90 , V_26 ) ;
if ( V_27 )
F_52 ( V_25 , V_53 ,
V_90 , V_26 ) ;
}
V_65:
F_3 ( V_90 ) ;
return V_27 ;
}
static int F_58 ( struct V_24 * V_25 ,
unsigned long * V_58 )
{
unsigned V_89 = V_68 -> V_13 . V_16 ;
int V_27 = V_25 -> V_50 ;
if ( V_89 > V_25 -> V_50 ) {
struct V_52 V_53 ;
F_28 ( & V_53 ) ;
F_32 ( & V_25 -> V_63 , * V_58 ) ;
V_27 = F_53 ( V_25 , & V_53 , V_89 ) ;
F_29 ( & V_25 -> V_63 , * V_58 ) ;
if ( ! V_27 ) {
F_59 ( & V_53 , & V_25 -> V_82 ) ;
++ V_25 -> V_84 ;
V_25 -> V_50 += V_89 ;
V_27 = V_89 ;
} else {
struct V_31 * V_32 ;
unsigned V_26 = 0 ;
F_5 ( L_19 ,
V_25 -> V_29 , V_25 -> V_85 , V_27 ) ;
F_60 (d_page, &d_pages, page_list) {
V_26 ++ ;
}
F_61 ( & V_53 , & V_25 -> V_82 ) ;
V_25 -> V_50 += V_26 ;
V_27 = V_26 ;
}
}
return V_27 ;
}
static int F_62 ( struct V_24 * V_25 ,
struct V_94 * V_95 ,
unsigned V_96 )
{
struct V_31 * V_32 ;
struct V_97 * V_98 = & V_95 -> V_98 ;
unsigned long V_58 ;
int V_89 , V_27 = - V_80 ;
F_29 ( & V_25 -> V_63 , V_58 ) ;
V_89 = F_58 ( V_25 , & V_58 ) ;
if ( V_89 ) {
V_32 = F_63 ( & V_25 -> V_82 , struct V_31 , V_56 ) ;
V_98 -> V_21 [ V_96 ] = V_32 -> V_38 ;
V_95 -> V_99 [ V_96 ] = V_32 -> V_33 ;
F_64 ( & V_32 -> V_56 , & V_95 -> V_100 ) ;
V_27 = 0 ;
V_25 -> V_71 += 1 ;
V_25 -> V_50 -= 1 ;
}
F_32 ( & V_25 -> V_63 , V_58 ) ;
return V_27 ;
}
int F_65 ( struct V_94 * V_95 , struct V_66 * V_34 )
{
struct V_97 * V_98 = & V_95 -> V_98 ;
struct V_101 * V_102 = V_98 -> V_103 -> V_102 ;
struct V_24 * V_25 ;
enum V_39 type ;
unsigned V_23 ;
T_4 V_37 ;
int V_78 ;
if ( V_98 -> V_104 != V_105 )
return 0 ;
type = F_21 ( V_98 -> V_106 , V_98 -> V_107 ) ;
if ( V_98 -> V_106 & V_44 )
V_37 = V_108 | V_109 ;
else
V_37 = V_110 ;
if ( V_98 -> V_106 & V_111 )
V_37 |= V_112 ;
V_25 = F_51 ( V_34 , type ) ;
if ( ! V_25 ) {
V_25 = F_41 ( V_34 , V_37 , type ) ;
if ( F_66 ( V_25 ) ) {
return - V_80 ;
}
}
F_28 ( & V_95 -> V_100 ) ;
for ( V_23 = 0 ; V_23 < V_98 -> V_113 ; ++ V_23 ) {
V_78 = F_62 ( V_25 , V_95 , V_23 ) ;
if ( V_78 != 0 ) {
F_67 ( V_95 , V_34 ) ;
return - V_80 ;
}
V_78 = F_68 ( V_102 , V_98 -> V_21 [ V_23 ] ,
false , false ) ;
if ( F_69 ( V_78 != 0 ) ) {
F_67 ( V_95 , V_34 ) ;
return - V_80 ;
}
}
if ( F_69 ( V_98 -> V_106 & V_114 ) ) {
V_78 = F_70 ( V_98 ) ;
if ( F_69 ( V_78 != 0 ) ) {
F_67 ( V_95 , V_34 ) ;
return V_78 ;
}
}
V_98 -> V_104 = V_115 ;
return 0 ;
}
static int F_71 ( void )
{
struct V_67 * V_38 ;
unsigned V_116 = 0 ;
F_35 ( & V_68 -> V_63 ) ;
F_60 (p, &_manager->pools, pools)
V_116 += V_38 -> V_25 -> V_50 ;
F_38 ( & V_68 -> V_63 ) ;
return V_116 ;
}
void F_67 ( struct V_94 * V_95 , struct V_66 * V_34 )
{
struct V_97 * V_98 = & V_95 -> V_98 ;
struct V_24 * V_25 ;
struct V_31 * V_32 , * V_117 ;
enum V_39 type ;
bool V_118 = false ;
unsigned V_89 = 0 , V_23 , V_54 = 0 ;
unsigned long V_58 ;
type = F_21 ( V_98 -> V_106 , V_98 -> V_107 ) ;
V_25 = F_51 ( V_34 , type ) ;
if ( ! V_25 )
return;
V_118 = ( F_51 ( V_25 -> V_34 ,
F_21 ( V_98 -> V_106 , V_46 ) ) == V_25 ) ;
F_60 (d_page, &ttm_dma->pages_list, page_list) {
V_98 -> V_21 [ V_89 ] = V_32 -> V_38 ;
V_89 ++ ;
}
F_29 ( & V_25 -> V_63 , V_58 ) ;
V_25 -> V_71 -= V_89 ;
if ( V_118 ) {
V_25 -> V_51 += V_89 ;
} else {
V_25 -> V_50 += V_89 ;
F_59 ( & V_95 -> V_100 , & V_25 -> V_82 ) ;
V_54 = V_89 ;
if ( V_25 -> V_50 > V_68 -> V_13 . V_14 ) {
V_54 = V_25 -> V_50 - V_68 -> V_13 . V_14 ;
if ( V_54 < V_18 )
V_54 = V_18 ;
}
}
F_32 ( & V_25 -> V_63 , V_58 ) ;
if ( V_118 ) {
F_24 (d_page, next, &ttm_dma->pages_list, page_list) {
F_72 ( V_98 -> V_103 -> V_102 ,
V_32 -> V_38 ) ;
F_26 ( V_25 , V_32 ) ;
}
} else {
for ( V_23 = 0 ; V_23 < V_89 ; V_23 ++ ) {
F_72 ( V_98 -> V_103 -> V_102 ,
V_98 -> V_21 [ V_23 ] ) ;
}
}
F_28 ( & V_95 -> V_100 ) ;
for ( V_23 = 0 ; V_23 < V_98 -> V_113 ; V_23 ++ ) {
V_98 -> V_21 [ V_23 ] = NULL ;
V_95 -> V_99 [ V_23 ] = 0 ;
}
if ( V_54 )
F_27 ( V_25 , V_54 ) ;
V_98 -> V_104 = V_105 ;
}
static int F_73 ( struct V_119 * V_120 ,
struct V_121 * V_122 )
{
static T_5 V_123 = F_74 ( 0 ) ;
unsigned V_124 = 0 ;
unsigned V_125 = F_75 ( 1 , & V_123 ) ;
unsigned V_126 = V_122 -> V_127 ;
struct V_67 * V_38 ;
if ( F_76 ( & V_68 -> V_69 ) )
return 0 ;
F_35 ( & V_68 -> V_63 ) ;
V_125 = V_125 % V_68 -> V_70 ;
F_60 (p, &_manager->pools, pools) {
unsigned V_57 ;
if ( ! V_38 -> V_34 )
continue;
if ( V_126 == 0 )
break;
if ( ++ V_124 < V_125 )
continue;
V_57 = V_126 ;
V_126 = F_27 ( V_38 -> V_25 , V_57 ) ;
F_55 ( L_20 ,
V_38 -> V_25 -> V_29 , V_38 -> V_25 -> V_85 , V_92 -> V_93 ,
V_57 , V_126 ) ;
}
F_38 ( & V_68 -> V_63 ) ;
return F_71 () ;
}
static void F_77 ( struct V_3 * V_128 )
{
V_128 -> V_129 . V_120 = & F_73 ;
V_128 -> V_129 . V_130 = 1 ;
F_78 ( & V_128 -> V_129 ) ;
}
static void F_79 ( struct V_3 * V_128 )
{
F_80 ( & V_128 -> V_129 ) ;
}
int F_81 ( struct V_101 * V_103 , unsigned V_131 )
{
int V_78 = - V_80 ;
F_37 ( V_68 ) ;
F_82 ( L_21 ) ;
V_68 = F_83 ( sizeof( * V_68 ) , V_36 ) ;
if ( ! V_68 )
goto V_132;
F_84 ( & V_68 -> V_63 ) ;
F_28 ( & V_68 -> V_69 ) ;
V_68 -> V_13 . V_14 = V_131 ;
V_68 -> V_13 . V_16 = V_133 ;
V_68 -> V_13 . V_19 = V_18 ;
V_78 = F_85 ( & V_68 -> V_2 , & V_134 ,
& V_103 -> V_2 , L_22 ) ;
if ( F_69 ( V_78 != 0 ) ) {
F_86 ( & V_68 -> V_2 ) ;
goto V_135;
}
F_77 ( V_68 ) ;
return 0 ;
V_132:
F_3 ( V_68 ) ;
V_68 = NULL ;
V_135:
return V_78 ;
}
void F_87 ( void )
{
struct V_67 * V_38 , * V_75 ;
F_82 ( L_23 ) ;
F_79 ( V_68 ) ;
F_30 (p, t, &_manager->pools, pools) {
F_88 ( V_38 -> V_34 , L_24 , V_38 -> V_25 -> V_85 ,
V_92 -> V_93 ) ;
F_37 ( F_89 ( V_38 -> V_34 , F_39 ,
F_40 , V_38 -> V_25 ) ) ;
F_34 ( V_38 -> V_34 , V_38 -> V_25 -> type ) ;
}
F_86 ( & V_68 -> V_2 ) ;
V_68 = NULL ;
}
int F_90 ( struct V_136 * V_4 , void * V_137 )
{
struct V_67 * V_38 ;
struct V_24 * V_25 = NULL ;
char * V_138 [] = { L_25 , L_26 , L_27 , L_28 , L_29 ,
L_30 , L_31 , L_32 } ;
if ( ! V_68 ) {
F_91 ( V_4 , L_33 ) ;
return 0 ;
}
F_91 ( V_4 , L_34 ,
V_138 [ 0 ] , V_138 [ 1 ] , V_138 [ 2 ] , V_138 [ 3 ] , V_138 [ 4 ] , V_138 [ 5 ] ) ;
F_35 ( & V_68 -> V_63 ) ;
F_60 (p, &_manager->pools, pools) {
struct V_66 * V_34 = V_38 -> V_34 ;
if ( ! V_34 )
continue;
V_25 = V_38 -> V_25 ;
F_91 ( V_4 , L_35 ,
V_25 -> V_85 , V_25 -> V_84 ,
V_25 -> V_51 , V_25 -> V_71 ,
V_25 -> V_50 ,
V_25 -> V_29 ) ;
}
F_38 ( & V_68 -> V_63 ) ;
return 0 ;
}
