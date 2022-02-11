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
static unsigned F_27 ( struct V_24 * V_25 , unsigned V_57 ,
bool V_58 )
{
static struct V_20 * V_59 [ V_18 ] ;
unsigned long V_60 ;
struct V_31 * V_61 , * V_55 ;
struct V_20 * * V_62 ;
struct V_52 V_53 ;
unsigned V_49 = 0 ,
V_63 = V_57 ;
if ( V_18 < V_57 )
V_63 = V_18 ;
#if 0
if (nr_free > 1) {
pr_debug("%s: (%s:%d) Attempting to free %d (%d) pages\n",
pool->dev_name, pool->name, current->pid,
npages_to_free, nr_free);
}
#endif
if ( V_58 )
V_62 = V_59 ;
else
V_62 = F_18 ( V_63 * sizeof( struct V_20 * ) ,
V_36 ) ;
if ( ! V_62 ) {
F_5 ( L_8 ,
V_25 -> V_29 ) ;
return 0 ;
}
F_28 ( & V_53 ) ;
V_64:
F_29 ( & V_25 -> V_65 , V_60 ) ;
F_30 (dma_p, tmp, &pool->free_list,
page_list) {
if ( V_49 >= V_63 )
break;
F_31 ( & V_61 -> V_56 , & V_53 ) ;
V_62 [ V_49 ++ ] = V_61 -> V_38 ;
if ( V_49 >= V_18 ) {
F_22 ( V_25 , V_49 ) ;
F_32 ( & V_25 -> V_65 , V_60 ) ;
F_23 ( V_25 , & V_53 , V_62 ,
V_49 ) ;
F_28 ( & V_53 ) ;
if ( F_33 ( V_57 != V_66 ) )
V_57 -= V_49 ;
if ( V_18 >= V_57 )
V_63 = V_57 ;
else
V_63 = V_18 ;
V_49 = 0 ;
if ( V_57 )
goto V_64;
goto V_67;
}
}
if ( V_49 ) {
F_22 ( V_25 , V_49 ) ;
V_57 -= V_49 ;
}
F_32 ( & V_25 -> V_65 , V_60 ) ;
if ( V_49 )
F_23 ( V_25 , & V_53 , V_62 , V_49 ) ;
V_67:
if ( V_62 != V_59 )
F_3 ( V_62 ) ;
return V_57 ;
}
static void F_34 ( struct V_68 * V_34 , enum V_39 type )
{
struct V_69 * V_38 ;
struct V_24 * V_25 ;
if ( ! V_34 )
return;
F_35 ( & V_70 -> V_65 ) ;
F_36 (p, &_manager->pools, pools) {
if ( V_38 -> V_34 != V_34 )
continue;
V_25 = V_38 -> V_25 ;
if ( V_25 -> type != type )
continue;
F_25 ( & V_38 -> V_71 ) ;
F_3 ( V_38 ) ;
V_70 -> V_72 -- ;
break;
}
F_36 (pool, &dev->dma_pools, pools) {
if ( V_25 -> type != type )
continue;
F_27 ( V_25 , V_66 , true ) ;
F_37 ( ( ( V_25 -> V_73 + V_25 -> V_50 ) != 0 ) ) ;
F_25 ( & V_25 -> V_71 ) ;
F_3 ( V_25 ) ;
break;
}
F_38 ( & V_70 -> V_65 ) ;
}
static void F_39 ( struct V_68 * V_34 , void * V_74 )
{
struct V_24 * V_25 = * (struct V_24 * * ) V_74 ;
if ( V_25 )
F_34 ( V_34 , V_25 -> type ) ;
}
static int F_40 ( struct V_68 * V_34 , void * V_74 , void * V_75 )
{
return * (struct V_24 * * ) V_74 == V_75 ;
}
static struct V_24 * F_41 ( struct V_68 * V_34 , T_4 V_40 ,
enum V_39 type )
{
char * V_76 [] = { L_9 , L_10 , L_11 , L_12 , L_13 ,} ;
enum V_39 V_77 [] = { V_30 , V_28 , V_47 , V_45 , V_43 } ;
struct V_69 * V_78 = NULL ;
struct V_24 * V_25 = NULL , * * V_79 ;
unsigned V_23 ;
int V_80 = - V_81 ;
char * V_38 ;
if ( ! V_34 )
return NULL ;
V_79 = F_42 ( F_39 , sizeof( * V_79 ) , V_36 ) ;
if ( ! V_79 )
return NULL ;
V_80 = - V_82 ;
V_25 = F_43 ( sizeof( struct V_24 ) , V_36 ,
F_44 ( V_34 ) ) ;
if ( ! V_25 )
goto V_83;
V_78 = F_43 ( sizeof( struct V_69 ) , V_36 ,
F_44 ( V_34 ) ) ;
if ( ! V_78 )
goto V_83;
F_28 ( & V_78 -> V_71 ) ;
V_78 -> V_34 = V_34 ;
V_78 -> V_25 = V_25 ;
F_28 ( & V_25 -> V_84 ) ;
F_28 ( & V_25 -> V_85 ) ;
F_28 ( & V_25 -> V_71 ) ;
F_45 ( & V_25 -> V_65 ) ;
V_25 -> V_34 = V_34 ;
V_25 -> V_50 = V_25 -> V_73 = 0 ;
V_25 -> V_51 = 0 ;
V_25 -> V_37 = V_40 ;
V_25 -> V_8 = V_11 ;
V_25 -> type = type ;
V_25 -> V_86 = 0 ;
V_38 = V_25 -> V_87 ;
for ( V_23 = 0 ; V_23 < 5 ; V_23 ++ ) {
if ( type & V_77 [ V_23 ] ) {
V_38 += snprintf ( V_38 , sizeof( V_25 -> V_87 ) - ( V_38 - V_25 -> V_87 ) ,
L_14 , V_76 [ V_23 ] ) ;
}
}
* V_38 = 0 ;
snprintf ( V_25 -> V_29 , sizeof( V_25 -> V_29 ) , L_15 ,
F_46 ( V_34 ) , V_29 ( V_34 ) ) ;
F_35 ( & V_70 -> V_65 ) ;
F_47 ( & V_78 -> V_71 , & V_70 -> V_71 ) ;
V_70 -> V_72 ++ ;
F_47 ( & V_25 -> V_71 , & V_34 -> V_88 ) ;
F_38 ( & V_70 -> V_65 ) ;
* V_79 = V_25 ;
F_48 ( V_34 , V_79 ) ;
return V_25 ;
V_83:
F_49 ( V_79 ) ;
F_3 ( V_78 ) ;
F_3 ( V_25 ) ;
return F_50 ( V_80 ) ;
}
static struct V_24 * F_51 ( struct V_68 * V_34 ,
enum V_39 type )
{
struct V_24 * V_25 , * V_55 , * V_89 = NULL ;
if ( type == V_43 )
return V_89 ;
F_24 (pool, tmp, &dev->dma_pools, pools) {
if ( V_25 -> type != type )
continue;
V_89 = V_25 ;
break;
}
return V_89 ;
}
static void F_52 ( struct V_24 * V_25 ,
struct V_52 * V_53 ,
struct V_20 * * V_90 ,
unsigned V_26 )
{
struct V_31 * V_32 , * V_55 ;
struct V_20 * V_38 ;
unsigned V_23 = 0 ;
V_38 = V_90 [ 0 ] ;
if ( ! V_38 )
return;
F_24 (d_page, tmp, d_pages, page_list) {
if ( V_32 -> V_38 != V_38 )
continue;
F_25 ( & V_32 -> V_56 ) ;
F_15 ( V_25 , V_32 ) ;
if ( ++ V_23 < V_26 )
V_38 = V_90 [ V_23 ] ;
else
break;
}
}
static int F_53 ( struct V_24 * V_25 ,
struct V_52 * V_53 ,
unsigned V_91 )
{
struct V_20 * * V_92 ;
struct V_31 * V_61 ;
struct V_20 * V_38 ;
int V_27 = 0 ;
unsigned V_23 , V_26 ;
unsigned V_93 = F_54 ( V_91 ,
( unsigned ) ( V_11 / sizeof( struct V_20 * ) ) ) ;
V_92 = F_18 ( V_93 * sizeof( struct V_20 * ) , V_36 ) ;
if ( ! V_92 ) {
F_5 ( L_16 ,
V_25 -> V_29 ) ;
return - V_82 ;
}
if ( V_91 > 1 ) {
F_55 ( L_17 ,
V_25 -> V_29 , V_25 -> V_87 , V_94 -> V_95 , V_91 ) ;
}
for ( V_23 = 0 , V_26 = 0 ; V_23 < V_91 ; ++ V_23 ) {
V_61 = F_17 ( V_25 ) ;
if ( ! V_61 ) {
F_5 ( L_18 ,
V_25 -> V_29 , V_23 ) ;
if ( V_26 ) {
V_27 = F_14 ( V_25 , V_92 ,
V_26 ) ;
if ( V_27 )
F_52 (
V_25 , V_53 , V_92 ,
V_26 ) ;
}
V_27 = - V_82 ;
goto V_67;
}
V_38 = V_61 -> V_38 ;
#ifdef F_56
if ( ! F_57 ( V_38 ) )
#endif
{
V_92 [ V_26 ++ ] = V_38 ;
if ( V_26 == V_93 ) {
V_27 = F_14 ( V_25 , V_92 ,
V_26 ) ;
if ( V_27 ) {
F_52 (
V_25 , V_53 , V_92 ,
V_26 ) ;
goto V_67;
}
V_26 = 0 ;
}
}
F_47 ( & V_61 -> V_56 , V_53 ) ;
}
if ( V_26 ) {
V_27 = F_14 ( V_25 , V_92 , V_26 ) ;
if ( V_27 )
F_52 ( V_25 , V_53 ,
V_92 , V_26 ) ;
}
V_67:
F_3 ( V_92 ) ;
return V_27 ;
}
static int F_58 ( struct V_24 * V_25 ,
unsigned long * V_60 )
{
unsigned V_91 = V_70 -> V_13 . V_16 ;
int V_27 = V_25 -> V_50 ;
if ( V_91 > V_25 -> V_50 ) {
struct V_52 V_53 ;
F_28 ( & V_53 ) ;
F_32 ( & V_25 -> V_65 , * V_60 ) ;
V_27 = F_53 ( V_25 , & V_53 , V_91 ) ;
F_29 ( & V_25 -> V_65 , * V_60 ) ;
if ( ! V_27 ) {
F_59 ( & V_53 , & V_25 -> V_84 ) ;
++ V_25 -> V_86 ;
V_25 -> V_50 += V_91 ;
V_27 = V_91 ;
} else {
struct V_31 * V_32 ;
unsigned V_26 = 0 ;
F_5 ( L_19 ,
V_25 -> V_29 , V_25 -> V_87 , V_27 ) ;
F_60 (d_page, &d_pages, page_list) {
V_26 ++ ;
}
F_61 ( & V_53 , & V_25 -> V_84 ) ;
V_25 -> V_50 += V_26 ;
V_27 = V_26 ;
}
}
return V_27 ;
}
static int F_62 ( struct V_24 * V_25 ,
struct V_96 * V_97 ,
unsigned V_98 )
{
struct V_31 * V_32 ;
struct V_99 * V_100 = & V_97 -> V_100 ;
unsigned long V_60 ;
int V_91 , V_27 = - V_82 ;
F_29 ( & V_25 -> V_65 , V_60 ) ;
V_91 = F_58 ( V_25 , & V_60 ) ;
if ( V_91 ) {
V_32 = F_63 ( & V_25 -> V_84 , struct V_31 , V_56 ) ;
V_100 -> V_21 [ V_98 ] = V_32 -> V_38 ;
V_97 -> V_101 [ V_98 ] = V_32 -> V_35 ;
V_97 -> V_102 [ V_98 ] = V_32 -> V_33 ;
F_64 ( & V_32 -> V_56 , & V_97 -> V_103 ) ;
V_27 = 0 ;
V_25 -> V_73 += 1 ;
V_25 -> V_50 -= 1 ;
}
F_32 ( & V_25 -> V_65 , V_60 ) ;
return V_27 ;
}
int F_65 ( struct V_96 * V_97 , struct V_68 * V_34 )
{
struct V_99 * V_100 = & V_97 -> V_100 ;
struct V_104 * V_105 = V_100 -> V_106 -> V_105 ;
struct V_24 * V_25 ;
enum V_39 type ;
unsigned V_23 ;
T_4 V_37 ;
int V_80 ;
if ( V_100 -> V_107 != V_108 )
return 0 ;
type = F_21 ( V_100 -> V_109 , V_100 -> V_110 ) ;
if ( V_100 -> V_109 & V_44 )
V_37 = V_111 | V_112 ;
else
V_37 = V_113 ;
if ( V_100 -> V_109 & V_114 )
V_37 |= V_115 ;
V_25 = F_51 ( V_34 , type ) ;
if ( ! V_25 ) {
V_25 = F_41 ( V_34 , V_37 , type ) ;
if ( F_66 ( V_25 ) ) {
return - V_82 ;
}
}
F_28 ( & V_97 -> V_103 ) ;
for ( V_23 = 0 ; V_23 < V_100 -> V_116 ; ++ V_23 ) {
V_80 = F_62 ( V_25 , V_97 , V_23 ) ;
if ( V_80 != 0 ) {
F_67 ( V_97 , V_34 ) ;
return - V_82 ;
}
V_80 = F_68 ( V_105 , V_100 -> V_21 [ V_23 ] ,
false , false ) ;
if ( F_69 ( V_80 != 0 ) ) {
F_67 ( V_97 , V_34 ) ;
return - V_82 ;
}
}
if ( F_69 ( V_100 -> V_109 & V_117 ) ) {
V_80 = F_70 ( V_100 ) ;
if ( F_69 ( V_80 != 0 ) ) {
F_67 ( V_97 , V_34 ) ;
return V_80 ;
}
}
V_100 -> V_107 = V_118 ;
return 0 ;
}
void F_67 ( struct V_96 * V_97 , struct V_68 * V_34 )
{
struct V_99 * V_100 = & V_97 -> V_100 ;
struct V_24 * V_25 ;
struct V_31 * V_32 , * V_119 ;
enum V_39 type ;
bool V_120 = false ;
unsigned V_91 = 0 , V_23 , V_54 = 0 ;
unsigned long V_60 ;
type = F_21 ( V_100 -> V_109 , V_100 -> V_110 ) ;
V_25 = F_51 ( V_34 , type ) ;
if ( ! V_25 )
return;
V_120 = ( F_51 ( V_25 -> V_34 ,
F_21 ( V_100 -> V_109 , V_46 ) ) == V_25 ) ;
F_60 (d_page, &ttm_dma->pages_list, page_list) {
V_100 -> V_21 [ V_91 ] = V_32 -> V_38 ;
V_91 ++ ;
}
F_29 ( & V_25 -> V_65 , V_60 ) ;
V_25 -> V_73 -= V_91 ;
if ( V_120 ) {
V_25 -> V_51 += V_91 ;
} else {
V_25 -> V_50 += V_91 ;
F_59 ( & V_97 -> V_103 , & V_25 -> V_84 ) ;
V_54 = V_91 ;
if ( V_25 -> V_50 > V_70 -> V_13 . V_14 ) {
V_54 = V_25 -> V_50 - V_70 -> V_13 . V_14 ;
if ( V_54 < V_18 )
V_54 = V_18 ;
}
}
F_32 ( & V_25 -> V_65 , V_60 ) ;
if ( V_120 ) {
F_24 (d_page, next, &ttm_dma->pages_list, page_list) {
F_71 ( V_100 -> V_106 -> V_105 ,
V_32 -> V_38 ) ;
F_26 ( V_25 , V_32 ) ;
}
} else {
for ( V_23 = 0 ; V_23 < V_91 ; V_23 ++ ) {
F_71 ( V_100 -> V_106 -> V_105 ,
V_100 -> V_21 [ V_23 ] ) ;
}
}
F_28 ( & V_97 -> V_103 ) ;
for ( V_23 = 0 ; V_23 < V_100 -> V_116 ; V_23 ++ ) {
V_100 -> V_21 [ V_23 ] = NULL ;
V_97 -> V_101 [ V_23 ] = 0 ;
V_97 -> V_102 [ V_23 ] = 0 ;
}
if ( V_54 )
F_27 ( V_25 , V_54 , false ) ;
V_100 -> V_107 = V_108 ;
}
static unsigned long
F_72 ( struct V_121 * V_122 , struct V_123 * V_124 )
{
static unsigned V_125 ;
unsigned V_126 = 0 ;
unsigned V_127 ;
unsigned V_128 = V_124 -> V_129 ;
struct V_69 * V_38 ;
unsigned long V_130 = 0 ;
if ( F_73 ( & V_70 -> V_71 ) )
return V_131 ;
if ( ! F_74 ( & V_70 -> V_65 ) )
return V_131 ;
if ( ! V_70 -> V_72 )
goto V_67;
V_127 = ++ V_125 % V_70 -> V_72 ;
F_60 (p, &_manager->pools, pools) {
unsigned V_57 ;
if ( ! V_38 -> V_34 )
continue;
if ( V_128 == 0 )
break;
if ( ++ V_126 < V_127 )
continue;
V_57 = V_128 ;
V_128 = F_27 ( V_38 -> V_25 , V_57 , true ) ;
V_130 += V_57 - V_128 ;
F_55 ( L_20 ,
V_38 -> V_25 -> V_29 , V_38 -> V_25 -> V_87 , V_94 -> V_95 ,
V_57 , V_128 ) ;
}
V_67:
F_38 ( & V_70 -> V_65 ) ;
return V_130 ;
}
static unsigned long
F_75 ( struct V_121 * V_122 , struct V_123 * V_124 )
{
struct V_69 * V_38 ;
unsigned long V_91 = 0 ;
if ( ! F_74 ( & V_70 -> V_65 ) )
return 0 ;
F_60 (p, &_manager->pools, pools)
V_91 += V_38 -> V_25 -> V_50 ;
F_38 ( & V_70 -> V_65 ) ;
return V_91 ;
}
static void F_76 ( struct V_3 * V_132 )
{
V_132 -> V_133 . V_134 = F_75 ;
V_132 -> V_133 . V_135 = & F_72 ;
V_132 -> V_133 . V_136 = 1 ;
F_77 ( & V_132 -> V_133 ) ;
}
static void F_78 ( struct V_3 * V_132 )
{
F_79 ( & V_132 -> V_133 ) ;
}
int F_80 ( struct V_104 * V_106 , unsigned V_137 )
{
int V_80 = - V_82 ;
F_37 ( V_70 ) ;
F_81 ( L_21 ) ;
V_70 = F_82 ( sizeof( * V_70 ) , V_36 ) ;
if ( ! V_70 )
goto V_138;
F_83 ( & V_70 -> V_65 ) ;
F_28 ( & V_70 -> V_71 ) ;
V_70 -> V_13 . V_14 = V_137 ;
V_70 -> V_13 . V_16 = V_139 ;
V_70 -> V_13 . V_19 = V_18 ;
V_80 = F_84 ( & V_70 -> V_2 , & V_140 ,
& V_106 -> V_2 , L_22 ) ;
if ( F_69 ( V_80 != 0 ) ) {
F_85 ( & V_70 -> V_2 ) ;
goto V_138;
}
F_76 ( V_70 ) ;
return 0 ;
V_138:
return V_80 ;
}
void F_86 ( void )
{
struct V_69 * V_38 , * V_77 ;
F_81 ( L_23 ) ;
F_78 ( V_70 ) ;
F_30 (p, t, &_manager->pools, pools) {
F_87 ( V_38 -> V_34 , L_24 , V_38 -> V_25 -> V_87 ,
V_94 -> V_95 ) ;
F_37 ( F_88 ( V_38 -> V_34 , F_39 ,
F_40 , V_38 -> V_25 ) ) ;
F_34 ( V_38 -> V_34 , V_38 -> V_25 -> type ) ;
}
F_85 ( & V_70 -> V_2 ) ;
V_70 = NULL ;
}
int F_89 ( struct V_141 * V_4 , void * V_142 )
{
struct V_69 * V_38 ;
struct V_24 * V_25 = NULL ;
char * V_143 [] = { L_25 , L_26 , L_27 , L_28 , L_29 ,
L_30 , L_31 , L_32 } ;
if ( ! V_70 ) {
F_90 ( V_4 , L_33 ) ;
return 0 ;
}
F_90 ( V_4 , L_34 ,
V_143 [ 0 ] , V_143 [ 1 ] , V_143 [ 2 ] , V_143 [ 3 ] , V_143 [ 4 ] , V_143 [ 5 ] ) ;
F_35 ( & V_70 -> V_65 ) ;
F_60 (p, &_manager->pools, pools) {
struct V_68 * V_34 = V_38 -> V_34 ;
if ( ! V_34 )
continue;
V_25 = V_38 -> V_25 ;
F_90 ( V_4 , L_35 ,
V_25 -> V_87 , V_25 -> V_86 ,
V_25 -> V_51 , V_25 -> V_73 ,
V_25 -> V_50 ,
V_25 -> V_29 ) ;
}
F_38 ( & V_70 -> V_65 ) ;
return 0 ;
}
