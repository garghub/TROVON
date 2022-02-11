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
#if F_9 ( V_23 )
int V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
F_10 ( V_21 [ V_24 ] ) ;
#endif
return 0 ;
}
static int F_11 ( struct V_20 * * V_21 , int V_22 )
{
#if F_9 ( V_23 )
int V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
F_12 ( V_21 [ V_24 ] ) ;
#endif
return 0 ;
}
static int F_13 ( struct V_20 * * V_21 , int V_22 )
{
#if F_9 ( V_23 )
int V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
F_12 ( V_21 [ V_24 ] ) ;
#endif
return 0 ;
}
static int F_14 ( struct V_25 * V_26 ,
struct V_20 * * V_21 , unsigned V_27 )
{
int V_28 = 0 ;
if ( V_26 -> type & V_29 ) {
V_28 = F_13 ( V_21 , V_27 ) ;
if ( V_28 )
F_5 ( L_5 ,
V_26 -> V_30 , V_27 ) ;
}
if ( V_26 -> type & V_31 ) {
V_28 = F_11 ( V_21 , V_27 ) ;
if ( V_28 )
F_5 ( L_6 ,
V_26 -> V_30 , V_27 ) ;
}
return V_28 ;
}
static void F_15 ( struct V_25 * V_26 , struct V_32 * V_33 )
{
T_3 V_34 = V_33 -> V_34 ;
F_16 ( V_26 -> V_35 , V_26 -> V_8 , V_33 -> V_36 , V_34 ) ;
F_3 ( V_33 ) ;
V_33 = NULL ;
}
static struct V_32 * F_17 ( struct V_25 * V_26 )
{
struct V_32 * V_33 ;
V_33 = F_18 ( sizeof( struct V_32 ) , V_37 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_36 = F_19 ( V_26 -> V_35 , V_26 -> V_8 ,
& V_33 -> V_34 ,
V_26 -> V_38 ) ;
if ( V_33 -> V_36 ) {
if ( F_20 ( V_33 -> V_36 ) )
V_33 -> V_39 = F_21 ( V_33 -> V_36 ) ;
else
V_33 -> V_39 = F_22 ( V_33 -> V_36 ) ;
} else {
F_3 ( V_33 ) ;
V_33 = NULL ;
}
return V_33 ;
}
static enum V_40 F_23 ( int V_41 , enum V_42 V_43 )
{
enum V_40 type = V_44 ;
if ( V_41 & V_45 )
type |= V_46 ;
if ( V_43 == V_47 )
type |= V_48 ;
else if ( V_43 == V_49 )
type |= V_29 ;
else
type |= V_31 ;
return type ;
}
static void F_24 ( struct V_25 * V_26 ,
unsigned V_50 )
{
V_26 -> V_51 -= V_50 ;
V_26 -> V_52 += V_50 ;
}
static void F_25 ( struct V_25 * V_26 , struct V_53 * V_54 ,
struct V_20 * V_21 [] , unsigned V_55 )
{
struct V_32 * V_33 , * V_56 ;
if ( V_55 && ! ( V_26 -> type & V_48 ) &&
F_8 ( V_21 , V_55 ) )
F_5 ( L_7 ,
V_26 -> V_30 , V_55 ) ;
F_26 (d_page, tmp, d_pages, page_list) {
F_27 ( & V_33 -> V_57 ) ;
F_15 ( V_26 , V_33 ) ;
}
}
static void F_28 ( struct V_25 * V_26 , struct V_32 * V_33 )
{
if ( ! ( V_26 -> type & V_48 ) && F_8 ( & V_33 -> V_39 , 1 ) )
F_5 ( L_7 ,
V_26 -> V_30 , 1 ) ;
F_27 ( & V_33 -> V_57 ) ;
F_15 ( V_26 , V_33 ) ;
}
static unsigned F_29 ( struct V_25 * V_26 , unsigned V_58 ,
bool V_59 )
{
static struct V_20 * V_60 [ V_18 ] ;
unsigned long V_61 ;
struct V_32 * V_62 , * V_56 ;
struct V_20 * * V_63 ;
struct V_53 V_54 ;
unsigned V_50 = 0 ,
V_64 = V_58 ;
if ( V_18 < V_58 )
V_64 = V_18 ;
#if 0
if (nr_free > 1) {
pr_debug("%s: (%s:%d) Attempting to free %d (%d) pages\n",
pool->dev_name, pool->name, current->pid,
npages_to_free, nr_free);
}
#endif
if ( V_59 )
V_63 = V_60 ;
else
V_63 = F_18 ( V_64 * sizeof( struct V_20 * ) ,
V_37 ) ;
if ( ! V_63 ) {
F_5 ( L_8 ,
V_26 -> V_30 ) ;
return 0 ;
}
F_30 ( & V_54 ) ;
V_65:
F_31 ( & V_26 -> V_66 , V_61 ) ;
F_32 (dma_p, tmp, &pool->free_list,
page_list) {
if ( V_50 >= V_64 )
break;
F_33 ( & V_62 -> V_57 , & V_54 ) ;
V_63 [ V_50 ++ ] = V_62 -> V_39 ;
if ( V_50 >= V_18 ) {
F_24 ( V_26 , V_50 ) ;
F_34 ( & V_26 -> V_66 , V_61 ) ;
F_25 ( V_26 , & V_54 , V_63 ,
V_50 ) ;
F_30 ( & V_54 ) ;
if ( F_35 ( V_58 != V_67 ) )
V_58 -= V_50 ;
if ( V_18 >= V_58 )
V_64 = V_58 ;
else
V_64 = V_18 ;
V_50 = 0 ;
if ( V_58 )
goto V_65;
goto V_68;
}
}
if ( V_50 ) {
F_24 ( V_26 , V_50 ) ;
V_58 -= V_50 ;
}
F_34 ( & V_26 -> V_66 , V_61 ) ;
if ( V_50 )
F_25 ( V_26 , & V_54 , V_63 , V_50 ) ;
V_68:
if ( V_63 != V_60 )
F_3 ( V_63 ) ;
return V_58 ;
}
static void F_36 ( struct V_69 * V_35 , enum V_40 type )
{
struct V_70 * V_39 ;
struct V_25 * V_26 ;
if ( ! V_35 )
return;
F_37 ( & V_71 -> V_66 ) ;
F_38 (p, &_manager->pools, pools) {
if ( V_39 -> V_35 != V_35 )
continue;
V_26 = V_39 -> V_26 ;
if ( V_26 -> type != type )
continue;
F_27 ( & V_39 -> V_72 ) ;
F_3 ( V_39 ) ;
V_71 -> V_73 -- ;
break;
}
F_38 (pool, &dev->dma_pools, pools) {
if ( V_26 -> type != type )
continue;
F_29 ( V_26 , V_67 , true ) ;
F_39 ( ( ( V_26 -> V_74 + V_26 -> V_51 ) != 0 ) ) ;
F_27 ( & V_26 -> V_72 ) ;
F_3 ( V_26 ) ;
break;
}
F_40 ( & V_71 -> V_66 ) ;
}
static void F_41 ( struct V_69 * V_35 , void * V_75 )
{
struct V_25 * V_26 = * (struct V_25 * * ) V_75 ;
if ( V_26 )
F_36 ( V_35 , V_26 -> type ) ;
}
static int F_42 ( struct V_69 * V_35 , void * V_75 , void * V_76 )
{
return * (struct V_25 * * ) V_75 == V_76 ;
}
static struct V_25 * F_43 ( struct V_69 * V_35 , T_4 V_41 ,
enum V_40 type )
{
char * V_77 [] = { L_9 , L_10 , L_11 , L_12 , L_13 ,} ;
enum V_40 V_78 [] = { V_31 , V_29 , V_48 , V_46 , V_44 } ;
struct V_70 * V_79 = NULL ;
struct V_25 * V_26 = NULL , * * V_80 ;
unsigned V_24 ;
int V_81 = - V_82 ;
char * V_39 ;
if ( ! V_35 )
return NULL ;
V_80 = F_44 ( F_41 , sizeof( * V_80 ) , V_37 ) ;
if ( ! V_80 )
return NULL ;
V_81 = - V_83 ;
V_26 = F_45 ( sizeof( struct V_25 ) , V_37 ,
F_46 ( V_35 ) ) ;
if ( ! V_26 )
goto V_84;
V_79 = F_45 ( sizeof( struct V_70 ) , V_37 ,
F_46 ( V_35 ) ) ;
if ( ! V_79 )
goto V_84;
F_30 ( & V_79 -> V_72 ) ;
V_79 -> V_35 = V_35 ;
V_79 -> V_26 = V_26 ;
F_30 ( & V_26 -> V_85 ) ;
F_30 ( & V_26 -> V_86 ) ;
F_30 ( & V_26 -> V_72 ) ;
F_47 ( & V_26 -> V_66 ) ;
V_26 -> V_35 = V_35 ;
V_26 -> V_51 = V_26 -> V_74 = 0 ;
V_26 -> V_52 = 0 ;
V_26 -> V_38 = V_41 ;
V_26 -> V_8 = V_11 ;
V_26 -> type = type ;
V_26 -> V_87 = 0 ;
V_39 = V_26 -> V_88 ;
for ( V_24 = 0 ; V_24 < 5 ; V_24 ++ ) {
if ( type & V_78 [ V_24 ] ) {
V_39 += snprintf ( V_39 , sizeof( V_26 -> V_88 ) - ( V_39 - V_26 -> V_88 ) ,
L_14 , V_77 [ V_24 ] ) ;
}
}
* V_39 = 0 ;
snprintf ( V_26 -> V_30 , sizeof( V_26 -> V_30 ) , L_15 ,
F_48 ( V_35 ) , V_30 ( V_35 ) ) ;
F_37 ( & V_71 -> V_66 ) ;
F_49 ( & V_79 -> V_72 , & V_71 -> V_72 ) ;
V_71 -> V_73 ++ ;
F_49 ( & V_26 -> V_72 , & V_35 -> V_89 ) ;
F_40 ( & V_71 -> V_66 ) ;
* V_80 = V_26 ;
F_50 ( V_35 , V_80 ) ;
return V_26 ;
V_84:
F_51 ( V_80 ) ;
F_3 ( V_79 ) ;
F_3 ( V_26 ) ;
return F_52 ( V_81 ) ;
}
static struct V_25 * F_53 ( struct V_69 * V_35 ,
enum V_40 type )
{
struct V_25 * V_26 , * V_56 , * V_90 = NULL ;
if ( type == V_44 )
return V_90 ;
F_26 (pool, tmp, &dev->dma_pools, pools) {
if ( V_26 -> type != type )
continue;
V_90 = V_26 ;
break;
}
return V_90 ;
}
static void F_54 ( struct V_25 * V_26 ,
struct V_53 * V_54 ,
struct V_20 * * V_91 ,
unsigned V_27 )
{
struct V_32 * V_33 , * V_56 ;
struct V_20 * V_39 ;
unsigned V_24 = 0 ;
V_39 = V_91 [ 0 ] ;
if ( ! V_39 )
return;
F_26 (d_page, tmp, d_pages, page_list) {
if ( V_33 -> V_39 != V_39 )
continue;
F_27 ( & V_33 -> V_57 ) ;
F_15 ( V_26 , V_33 ) ;
if ( ++ V_24 < V_27 )
V_39 = V_91 [ V_24 ] ;
else
break;
}
}
static int F_55 ( struct V_25 * V_26 ,
struct V_53 * V_54 ,
unsigned V_92 )
{
struct V_20 * * V_93 ;
struct V_32 * V_62 ;
struct V_20 * V_39 ;
int V_28 = 0 ;
unsigned V_24 , V_27 ;
unsigned V_94 = F_56 ( V_92 ,
( unsigned ) ( V_11 / sizeof( struct V_20 * ) ) ) ;
V_93 = F_18 ( V_94 * sizeof( struct V_20 * ) , V_37 ) ;
if ( ! V_93 ) {
F_5 ( L_16 ,
V_26 -> V_30 ) ;
return - V_83 ;
}
if ( V_92 > 1 ) {
F_57 ( L_17 ,
V_26 -> V_30 , V_26 -> V_88 , V_95 -> V_96 , V_92 ) ;
}
for ( V_24 = 0 , V_27 = 0 ; V_24 < V_92 ; ++ V_24 ) {
V_62 = F_17 ( V_26 ) ;
if ( ! V_62 ) {
F_5 ( L_18 ,
V_26 -> V_30 , V_24 ) ;
if ( V_27 ) {
V_28 = F_14 ( V_26 , V_93 ,
V_27 ) ;
if ( V_28 )
F_54 (
V_26 , V_54 , V_93 ,
V_27 ) ;
}
V_28 = - V_83 ;
goto V_68;
}
V_39 = V_62 -> V_39 ;
#ifdef F_58
if ( ! F_59 ( V_39 ) )
#endif
{
V_93 [ V_27 ++ ] = V_39 ;
if ( V_27 == V_94 ) {
V_28 = F_14 ( V_26 , V_93 ,
V_27 ) ;
if ( V_28 ) {
F_54 (
V_26 , V_54 , V_93 ,
V_27 ) ;
goto V_68;
}
V_27 = 0 ;
}
}
F_49 ( & V_62 -> V_57 , V_54 ) ;
}
if ( V_27 ) {
V_28 = F_14 ( V_26 , V_93 , V_27 ) ;
if ( V_28 )
F_54 ( V_26 , V_54 ,
V_93 , V_27 ) ;
}
V_68:
F_3 ( V_93 ) ;
return V_28 ;
}
static int F_60 ( struct V_25 * V_26 ,
unsigned long * V_61 )
{
unsigned V_92 = V_71 -> V_13 . V_16 ;
int V_28 = V_26 -> V_51 ;
if ( V_92 > V_26 -> V_51 ) {
struct V_53 V_54 ;
F_30 ( & V_54 ) ;
F_34 ( & V_26 -> V_66 , * V_61 ) ;
V_28 = F_55 ( V_26 , & V_54 , V_92 ) ;
F_31 ( & V_26 -> V_66 , * V_61 ) ;
if ( ! V_28 ) {
F_61 ( & V_54 , & V_26 -> V_85 ) ;
++ V_26 -> V_87 ;
V_26 -> V_51 += V_92 ;
V_28 = V_92 ;
} else {
struct V_32 * V_33 ;
unsigned V_27 = 0 ;
F_5 ( L_19 ,
V_26 -> V_30 , V_26 -> V_88 , V_28 ) ;
F_62 (d_page, &d_pages, page_list) {
V_27 ++ ;
}
F_63 ( & V_54 , & V_26 -> V_85 ) ;
V_26 -> V_51 += V_27 ;
V_28 = V_27 ;
}
}
return V_28 ;
}
static int F_64 ( struct V_25 * V_26 ,
struct V_97 * V_98 ,
unsigned V_99 )
{
struct V_32 * V_33 ;
struct V_100 * V_101 = & V_98 -> V_101 ;
unsigned long V_61 ;
int V_92 , V_28 = - V_83 ;
F_31 ( & V_26 -> V_66 , V_61 ) ;
V_92 = F_60 ( V_26 , & V_61 ) ;
if ( V_92 ) {
V_33 = F_65 ( & V_26 -> V_85 , struct V_32 , V_57 ) ;
V_101 -> V_21 [ V_99 ] = V_33 -> V_39 ;
V_98 -> V_102 [ V_99 ] = V_33 -> V_34 ;
F_66 ( & V_33 -> V_57 , & V_98 -> V_103 ) ;
V_28 = 0 ;
V_26 -> V_74 += 1 ;
V_26 -> V_51 -= 1 ;
}
F_34 ( & V_26 -> V_66 , V_61 ) ;
return V_28 ;
}
int F_67 ( struct V_97 * V_98 , struct V_69 * V_35 )
{
struct V_100 * V_101 = & V_98 -> V_101 ;
struct V_104 * V_105 = V_101 -> V_106 -> V_105 ;
struct V_25 * V_26 ;
enum V_40 type ;
unsigned V_24 ;
T_4 V_38 ;
int V_81 ;
if ( V_101 -> V_107 != V_108 )
return 0 ;
type = F_23 ( V_101 -> V_109 , V_101 -> V_110 ) ;
if ( V_101 -> V_109 & V_45 )
V_38 = V_111 | V_112 ;
else
V_38 = V_113 ;
if ( V_101 -> V_109 & V_114 )
V_38 |= V_115 ;
V_26 = F_53 ( V_35 , type ) ;
if ( ! V_26 ) {
V_26 = F_43 ( V_35 , V_38 , type ) ;
if ( F_68 ( V_26 ) ) {
return - V_83 ;
}
}
F_30 ( & V_98 -> V_103 ) ;
for ( V_24 = 0 ; V_24 < V_101 -> V_116 ; ++ V_24 ) {
V_81 = F_64 ( V_26 , V_98 , V_24 ) ;
if ( V_81 != 0 ) {
F_69 ( V_98 , V_35 ) ;
return - V_83 ;
}
V_81 = F_70 ( V_105 , V_101 -> V_21 [ V_24 ] ,
false , false ) ;
if ( F_71 ( V_81 != 0 ) ) {
F_69 ( V_98 , V_35 ) ;
return - V_83 ;
}
}
if ( F_71 ( V_101 -> V_109 & V_117 ) ) {
V_81 = F_72 ( V_101 ) ;
if ( F_71 ( V_81 != 0 ) ) {
F_69 ( V_98 , V_35 ) ;
return V_81 ;
}
}
V_101 -> V_107 = V_118 ;
return 0 ;
}
void F_69 ( struct V_97 * V_98 , struct V_69 * V_35 )
{
struct V_100 * V_101 = & V_98 -> V_101 ;
struct V_25 * V_26 ;
struct V_32 * V_33 , * V_119 ;
enum V_40 type ;
bool V_120 = false ;
unsigned V_92 = 0 , V_24 , V_55 = 0 ;
unsigned long V_61 ;
type = F_23 ( V_101 -> V_109 , V_101 -> V_110 ) ;
V_26 = F_53 ( V_35 , type ) ;
if ( ! V_26 )
return;
V_120 = ( F_53 ( V_26 -> V_35 ,
F_23 ( V_101 -> V_109 , V_47 ) ) == V_26 ) ;
F_62 (d_page, &ttm_dma->pages_list, page_list) {
V_101 -> V_21 [ V_92 ] = V_33 -> V_39 ;
V_92 ++ ;
}
F_31 ( & V_26 -> V_66 , V_61 ) ;
V_26 -> V_74 -= V_92 ;
if ( V_120 ) {
V_26 -> V_52 += V_92 ;
} else {
V_26 -> V_51 += V_92 ;
F_61 ( & V_98 -> V_103 , & V_26 -> V_85 ) ;
if ( V_26 -> V_51 >= ( V_71 -> V_13 . V_14 +
V_18 ) )
V_55 = V_26 -> V_51 - V_71 -> V_13 . V_14 ;
}
F_34 ( & V_26 -> V_66 , V_61 ) ;
if ( V_120 ) {
F_26 (d_page, next, &ttm_dma->pages_list, page_list) {
F_73 ( V_101 -> V_106 -> V_105 ,
V_33 -> V_39 ) ;
F_28 ( V_26 , V_33 ) ;
}
} else {
for ( V_24 = 0 ; V_24 < V_92 ; V_24 ++ ) {
F_73 ( V_101 -> V_106 -> V_105 ,
V_101 -> V_21 [ V_24 ] ) ;
}
}
F_30 ( & V_98 -> V_103 ) ;
for ( V_24 = 0 ; V_24 < V_101 -> V_116 ; V_24 ++ ) {
V_101 -> V_21 [ V_24 ] = NULL ;
V_98 -> V_102 [ V_24 ] = 0 ;
}
if ( V_55 )
F_29 ( V_26 , V_55 , false ) ;
V_101 -> V_107 = V_108 ;
}
static unsigned long
F_74 ( struct V_121 * V_122 , struct V_123 * V_124 )
{
static unsigned V_125 ;
unsigned V_126 = 0 ;
unsigned V_127 ;
unsigned V_128 = V_124 -> V_129 ;
struct V_70 * V_39 ;
unsigned long V_130 = 0 ;
if ( F_75 ( & V_71 -> V_72 ) )
return V_131 ;
if ( ! F_76 ( & V_71 -> V_66 ) )
return V_131 ;
if ( ! V_71 -> V_73 )
goto V_68;
V_127 = ++ V_125 % V_71 -> V_73 ;
F_62 (p, &_manager->pools, pools) {
unsigned V_58 ;
if ( ! V_39 -> V_35 )
continue;
if ( V_128 == 0 )
break;
if ( ++ V_126 < V_127 )
continue;
V_58 = V_128 ;
V_128 = F_29 ( V_39 -> V_26 , V_58 , true ) ;
V_130 += V_58 - V_128 ;
F_57 ( L_20 ,
V_39 -> V_26 -> V_30 , V_39 -> V_26 -> V_88 , V_95 -> V_96 ,
V_58 , V_128 ) ;
}
V_68:
F_40 ( & V_71 -> V_66 ) ;
return V_130 ;
}
static unsigned long
F_77 ( struct V_121 * V_122 , struct V_123 * V_124 )
{
struct V_70 * V_39 ;
unsigned long V_92 = 0 ;
if ( ! F_76 ( & V_71 -> V_66 ) )
return 0 ;
F_62 (p, &_manager->pools, pools)
V_92 += V_39 -> V_26 -> V_51 ;
F_40 ( & V_71 -> V_66 ) ;
return V_92 ;
}
static void F_78 ( struct V_3 * V_132 )
{
V_132 -> V_133 . V_134 = F_77 ;
V_132 -> V_133 . V_135 = & F_74 ;
V_132 -> V_133 . V_136 = 1 ;
F_79 ( & V_132 -> V_133 ) ;
}
static void F_80 ( struct V_3 * V_132 )
{
F_81 ( & V_132 -> V_133 ) ;
}
int F_82 ( struct V_104 * V_106 , unsigned V_137 )
{
int V_81 = - V_83 ;
F_39 ( V_71 ) ;
F_83 ( L_21 ) ;
V_71 = F_84 ( sizeof( * V_71 ) , V_37 ) ;
if ( ! V_71 )
goto V_138;
F_85 ( & V_71 -> V_66 ) ;
F_30 ( & V_71 -> V_72 ) ;
V_71 -> V_13 . V_14 = V_137 ;
V_71 -> V_13 . V_16 = V_139 ;
V_71 -> V_13 . V_19 = V_18 ;
V_81 = F_86 ( & V_71 -> V_2 , & V_140 ,
& V_106 -> V_2 , L_22 ) ;
if ( F_71 ( V_81 != 0 ) ) {
F_87 ( & V_71 -> V_2 ) ;
goto V_138;
}
F_78 ( V_71 ) ;
return 0 ;
V_138:
return V_81 ;
}
void F_88 ( void )
{
struct V_70 * V_39 , * V_78 ;
F_83 ( L_23 ) ;
F_80 ( V_71 ) ;
F_32 (p, t, &_manager->pools, pools) {
F_89 ( V_39 -> V_35 , L_24 , V_39 -> V_26 -> V_88 ,
V_95 -> V_96 ) ;
F_39 ( F_90 ( V_39 -> V_35 , F_41 ,
F_42 , V_39 -> V_26 ) ) ;
F_36 ( V_39 -> V_35 , V_39 -> V_26 -> type ) ;
}
F_87 ( & V_71 -> V_2 ) ;
V_71 = NULL ;
}
int F_91 ( struct V_141 * V_4 , void * V_142 )
{
struct V_70 * V_39 ;
struct V_25 * V_26 = NULL ;
char * V_143 [] = { L_25 , L_26 , L_27 , L_28 , L_29 ,
L_30 , L_31 , L_32 } ;
if ( ! V_71 ) {
F_92 ( V_4 , L_33 ) ;
return 0 ;
}
F_92 ( V_4 , L_34 ,
V_143 [ 0 ] , V_143 [ 1 ] , V_143 [ 2 ] , V_143 [ 3 ] , V_143 [ 4 ] , V_143 [ 5 ] ) ;
F_37 ( & V_71 -> V_66 ) ;
F_62 (p, &_manager->pools, pools) {
struct V_69 * V_35 = V_39 -> V_35 ;
if ( ! V_35 )
continue;
V_26 = V_39 -> V_26 ;
F_92 ( V_4 , L_35 ,
V_26 -> V_88 , V_26 -> V_87 ,
V_26 -> V_52 , V_26 -> V_74 ,
V_26 -> V_51 ,
V_26 -> V_30 ) ;
}
F_40 ( & V_71 -> V_66 ) ;
return 0 ;
}
