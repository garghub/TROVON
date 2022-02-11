static struct V_1 * F_1 ( unsigned long V_2 )
{
struct V_1 * V_1 ;
struct V_3 * V_3 ;
unsigned long * V_4 ;
unsigned long V_5 , V_6 ;
if ( V_2 < ( 1UL << 31 ) ) {
V_2 = ( 1UL << 31 ) - 1 ;
V_6 = V_7 ;
V_5 = V_8 ;
} else if ( V_2 < ( 1UL << 42 ) ) {
V_2 = ( 1UL << 42 ) - 1 ;
V_6 = V_9 ;
V_5 = V_10 ;
} else if ( V_2 < ( 1UL << 53 ) ) {
V_2 = ( 1UL << 53 ) - 1 ;
V_6 = V_11 ;
V_5 = V_12 ;
} else {
V_2 = - 1UL ;
V_6 = V_13 ;
V_5 = V_14 ;
}
V_1 = F_2 ( sizeof( struct V_1 ) , V_15 ) ;
if ( ! V_1 )
goto V_16;
F_3 ( & V_1 -> V_17 ) ;
F_3 ( & V_1 -> V_18 ) ;
F_3 ( & V_1 -> V_19 ) ;
F_4 ( & V_1 -> V_20 , V_15 ) ;
F_4 ( & V_1 -> V_21 , V_22 ) ;
F_4 ( & V_1 -> V_23 , V_22 ) ;
F_5 ( & V_1 -> V_24 ) ;
F_5 ( & V_1 -> V_25 ) ;
F_6 ( & V_1 -> V_26 , 1 ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
goto V_27;
V_3 -> V_28 = 0 ;
F_8 ( & V_3 -> V_29 , & V_1 -> V_17 ) ;
V_4 = ( unsigned long * ) F_9 ( V_3 ) ;
F_10 ( V_4 , V_5 ) ;
V_1 -> V_4 = V_4 ;
V_1 -> V_30 = V_6 | V_31 |
V_32 | F_11 ( V_4 ) ;
V_1 -> V_33 = V_2 ;
return V_1 ;
V_27:
F_12 ( V_1 ) ;
V_16:
return NULL ;
}
struct V_1 * F_13 ( struct V_34 * V_35 , unsigned long V_2 )
{
struct V_1 * V_1 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_35 = V_35 ;
F_14 ( & V_35 -> V_36 . V_37 ) ;
F_15 ( & V_1 -> V_38 , & V_35 -> V_36 . V_39 ) ;
F_16 ( & V_35 -> V_36 . V_37 ) ;
return V_1 ;
}
static void F_17 ( struct V_1 * V_1 )
{
if ( V_40 )
F_18 ( V_1 -> V_30 ) ;
else
F_19 () ;
}
static void F_20 ( struct V_41 * V_42 )
{
struct V_43 V_44 ;
unsigned long V_45 [ 16 ] ;
unsigned long V_28 ;
void * * V_46 ;
int V_47 , V_48 ;
V_28 = 0 ;
do {
V_48 = 0 ;
F_21 (slot, root, &iter, index) {
V_45 [ V_48 ] = V_44 . V_28 ;
if ( ++ V_48 == 16 )
break;
}
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_28 = V_45 [ V_47 ] ;
F_22 ( V_42 , V_28 ) ;
}
} while ( V_48 > 0 );
}
static void F_23 ( struct V_41 * V_42 )
{
struct V_49 * V_50 , * V_51 , * V_52 ;
struct V_43 V_44 ;
unsigned long V_45 [ 16 ] ;
unsigned long V_28 ;
void * * V_46 ;
int V_47 , V_48 ;
V_28 = 0 ;
do {
V_48 = 0 ;
F_21 (slot, root, &iter, index) {
V_45 [ V_48 ] = V_44 . V_28 ;
if ( ++ V_48 == 16 )
break;
}
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_28 = V_45 [ V_47 ] ;
V_52 = F_22 ( V_42 , V_28 ) ;
F_24 (rmap, rnext, head)
F_12 ( V_50 ) ;
}
} while ( V_48 > 0 );
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_3 * V_3 , * V_53 ;
if ( ! ( F_26 ( V_1 ) && V_1 -> V_54 ) )
F_17 ( V_1 ) ;
F_27 (page, next, &gmap->crst_list, lru)
F_28 ( V_3 , 2 ) ;
F_20 ( & V_1 -> V_20 ) ;
F_20 ( & V_1 -> V_21 ) ;
if ( F_26 ( V_1 ) ) {
F_27 (page, next, &gmap->pt_list, lru)
F_29 ( V_3 ) ;
F_23 ( & V_1 -> V_23 ) ;
F_30 ( V_1 -> V_55 ) ;
}
F_12 ( V_1 ) ;
}
struct V_1 * F_31 ( struct V_1 * V_1 )
{
F_32 ( & V_1 -> V_26 ) ;
return V_1 ;
}
void F_30 ( struct V_1 * V_1 )
{
if ( F_33 ( & V_1 -> V_26 ) == 0 )
F_25 ( V_1 ) ;
}
void F_34 ( struct V_1 * V_1 )
{
struct V_1 * V_56 , * V_53 ;
if ( ! F_35 ( & V_1 -> V_18 ) ) {
F_14 ( & V_1 -> V_25 ) ;
F_27 (sg, next, &gmap->children, list) {
F_36 ( & V_56 -> V_38 ) ;
F_30 ( V_56 ) ;
}
F_16 ( & V_1 -> V_25 ) ;
}
F_14 ( & V_1 -> V_35 -> V_36 . V_37 ) ;
F_37 ( & V_1 -> V_38 ) ;
F_16 ( & V_1 -> V_35 -> V_36 . V_37 ) ;
F_38 () ;
F_30 ( V_1 ) ;
}
void F_39 ( struct V_1 * V_1 )
{
V_57 . V_1 = ( unsigned long ) V_1 ;
}
void F_40 ( struct V_1 * V_1 )
{
V_57 . V_1 = 0UL ;
}
struct V_1 * F_41 ( void )
{
return (struct V_1 * ) V_57 . V_1 ;
}
static int F_42 ( struct V_1 * V_1 , unsigned long * V_4 ,
unsigned long V_58 , unsigned long V_59 )
{
struct V_3 * V_3 ;
unsigned long * V_60 ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_61 ;
V_60 = ( unsigned long * ) F_9 ( V_3 ) ;
F_10 ( V_60 , V_58 ) ;
F_14 ( & V_1 -> V_24 ) ;
if ( * V_4 & V_62 ) {
F_8 ( & V_3 -> V_29 , & V_1 -> V_17 ) ;
* V_4 = ( unsigned long ) V_60 | V_63 |
( * V_4 & V_64 ) ;
V_3 -> V_28 = V_59 ;
V_3 = NULL ;
}
F_16 ( & V_1 -> V_24 ) ;
if ( V_3 )
F_28 ( V_3 , 2 ) ;
return 0 ;
}
static unsigned long F_43 ( unsigned long * V_65 )
{
struct V_3 * V_3 ;
unsigned long V_66 , V_67 ;
V_66 = ( unsigned long ) V_65 / sizeof( unsigned long ) ;
V_66 = ( V_66 & ( V_68 - 1 ) ) * V_69 ;
V_67 = ~ ( V_68 * sizeof( V_70 ) - 1 ) ;
V_3 = F_44 ( ( void * ) ( ( unsigned long ) V_65 & V_67 ) ) ;
return V_3 -> V_28 + V_66 ;
}
static int F_45 ( struct V_1 * V_1 , unsigned long V_71 )
{
unsigned long * V_65 ;
int V_72 = 0 ;
F_46 ( F_26 ( V_1 ) ) ;
F_14 ( & V_1 -> V_24 ) ;
V_65 = F_22 ( & V_1 -> V_21 , V_71 >> V_73 ) ;
if ( V_65 ) {
V_72 = ( * V_65 != V_74 ) ;
* V_65 = V_74 ;
}
F_16 ( & V_1 -> V_24 ) ;
return V_72 ;
}
static int F_47 ( struct V_1 * V_1 , unsigned long V_59 )
{
unsigned long V_71 ;
V_71 = ( unsigned long ) F_22 ( & V_1 -> V_20 ,
V_59 >> V_73 ) ;
return V_71 ? F_45 ( V_1 , V_71 ) : 0 ;
}
int F_48 ( struct V_1 * V_1 , unsigned long V_75 , unsigned long V_76 )
{
unsigned long V_77 ;
int V_72 ;
F_46 ( F_26 ( V_1 ) ) ;
if ( ( V_75 | V_76 ) & ( V_69 - 1 ) )
return - V_78 ;
if ( V_76 == 0 || V_75 + V_76 < V_75 )
return - V_78 ;
V_72 = 0 ;
F_49 ( & V_1 -> V_35 -> V_79 ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 += V_69 )
V_72 |= F_47 ( V_1 , V_75 + V_77 ) ;
F_50 ( & V_1 -> V_35 -> V_79 ) ;
if ( V_72 )
F_17 ( V_1 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_1 , unsigned long V_80 ,
unsigned long V_75 , unsigned long V_76 )
{
unsigned long V_77 ;
int V_72 ;
F_46 ( F_26 ( V_1 ) ) ;
if ( ( V_80 | V_75 | V_76 ) & ( V_69 - 1 ) )
return - V_78 ;
if ( V_76 == 0 || V_80 + V_76 < V_80 || V_75 + V_76 < V_75 ||
V_80 + V_76 - 1 > V_81 || V_75 + V_76 - 1 > V_1 -> V_33 )
return - V_78 ;
V_72 = 0 ;
F_49 ( & V_1 -> V_35 -> V_79 ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 += V_69 ) {
V_72 |= F_47 ( V_1 , V_75 + V_77 ) ;
if ( F_52 ( & V_1 -> V_20 ,
( V_75 + V_77 ) >> V_73 ,
( void * ) V_80 + V_77 ) )
break;
}
F_50 ( & V_1 -> V_35 -> V_79 ) ;
if ( V_72 )
F_17 ( V_1 ) ;
if ( V_77 >= V_76 )
return 0 ;
F_48 ( V_1 , V_75 , V_76 ) ;
return - V_61 ;
}
unsigned long F_53 ( struct V_1 * V_1 , unsigned long V_59 )
{
unsigned long V_71 ;
V_71 = ( unsigned long )
F_54 ( & V_1 -> V_20 , V_59 >> V_73 ) ;
return V_71 ? ( V_71 | ( V_59 & ~ V_82 ) ) : - V_83 ;
}
unsigned long F_55 ( struct V_1 * V_1 , unsigned long V_59 )
{
unsigned long V_84 ;
F_56 ( & V_1 -> V_35 -> V_79 ) ;
V_84 = F_53 ( V_1 , V_59 ) ;
F_57 ( & V_1 -> V_35 -> V_79 ) ;
return V_84 ;
}
void F_58 ( struct V_34 * V_35 , unsigned long * V_4 ,
unsigned long V_71 )
{
struct V_1 * V_1 ;
int V_72 ;
F_59 () ;
F_60 (gmap, &mm->context.gmap_list, list) {
V_72 = F_45 ( V_1 , V_71 ) ;
if ( V_72 )
F_17 ( V_1 ) ;
}
F_61 () ;
}
int F_62 ( struct V_1 * V_1 , unsigned long V_59 , unsigned long V_71 )
{
struct V_34 * V_35 ;
unsigned long * V_4 ;
T_1 * V_85 ;
T_2 * V_86 ;
T_3 * V_87 ;
V_70 * V_88 ;
int V_84 ;
F_46 ( F_26 ( V_1 ) ) ;
V_4 = V_1 -> V_4 ;
if ( ( V_1 -> V_30 & V_89 ) >= V_13 ) {
V_4 += ( V_59 >> 53 ) & 0x7ff ;
if ( ( * V_4 & V_62 ) &&
F_42 ( V_1 , V_4 , V_12 ,
V_59 & 0xffe0000000000000UL ) )
return - V_61 ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
}
if ( ( V_1 -> V_30 & V_89 ) >= V_11 ) {
V_4 += ( V_59 >> 42 ) & 0x7ff ;
if ( ( * V_4 & V_62 ) &&
F_42 ( V_1 , V_4 , V_10 ,
V_59 & 0xfffffc0000000000UL ) )
return - V_61 ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
}
if ( ( V_1 -> V_30 & V_89 ) >= V_9 ) {
V_4 += ( V_59 >> 31 ) & 0x7ff ;
if ( ( * V_4 & V_62 ) &&
F_42 ( V_1 , V_4 , V_8 ,
V_59 & 0xffffffff80000000UL ) )
return - V_61 ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
}
V_4 += ( V_59 >> 20 ) & 0x7ff ;
V_35 = V_1 -> V_35 ;
V_86 = F_63 ( V_35 , V_71 ) ;
F_64 ( F_65 ( * V_86 ) ) ;
V_87 = F_66 ( V_86 , V_71 ) ;
F_64 ( F_67 ( * V_87 ) ) ;
if ( F_68 ( * V_87 ) )
return - V_83 ;
V_88 = F_69 ( V_87 , V_71 ) ;
F_64 ( F_70 ( * V_88 ) ) ;
if ( F_71 ( * V_88 ) )
return - V_83 ;
V_84 = F_72 ( V_15 ) ;
if ( V_84 )
return V_84 ;
V_85 = F_73 ( V_35 , V_88 ) ;
F_14 ( & V_1 -> V_24 ) ;
if ( * V_4 == V_74 ) {
V_84 = F_52 ( & V_1 -> V_21 ,
V_71 >> V_73 , V_4 ) ;
if ( ! V_84 )
* V_4 = F_74 ( * V_88 ) ;
} else
V_84 = 0 ;
F_16 ( & V_1 -> V_24 ) ;
F_16 ( V_85 ) ;
F_75 () ;
return V_84 ;
}
int F_76 ( struct V_1 * V_1 , unsigned long V_59 ,
unsigned int V_91 )
{
unsigned long V_71 ;
int V_84 ;
bool V_92 ;
F_56 ( & V_1 -> V_35 -> V_79 ) ;
V_93:
V_92 = false ;
V_71 = F_53 ( V_1 , V_59 ) ;
if ( F_77 ( V_71 ) ) {
V_84 = V_71 ;
goto V_94;
}
if ( F_78 ( V_95 , V_1 -> V_35 , V_71 , V_91 ,
& V_92 ) ) {
V_84 = - V_83 ;
goto V_94;
}
if ( V_92 )
goto V_93;
V_84 = F_62 ( V_1 , V_59 , V_71 ) ;
V_94:
F_57 ( & V_1 -> V_35 -> V_79 ) ;
return V_84 ;
}
void F_79 ( struct V_1 * V_1 , unsigned long V_59 )
{
unsigned long V_71 ;
T_1 * V_85 ;
T_4 * V_96 ;
V_71 = ( unsigned long ) F_54 ( & V_1 -> V_20 ,
V_59 >> V_73 ) ;
if ( V_71 ) {
V_71 |= V_59 & ~ V_82 ;
V_96 = F_80 ( V_1 -> V_35 , V_71 , & V_85 ) ;
if ( F_81 ( V_96 ) )
F_82 ( V_1 -> V_35 , V_71 , V_96 , 0 ) ;
F_83 ( V_96 , V_85 ) ;
}
}
void F_84 ( struct V_1 * V_1 , unsigned long V_80 , unsigned long V_75 )
{
unsigned long V_59 , V_71 , V_97 ;
struct V_98 * V_99 ;
F_56 ( & V_1 -> V_35 -> V_79 ) ;
for ( V_59 = V_80 ; V_59 < V_75 ;
V_59 = ( V_59 + V_69 ) & V_82 ) {
V_71 = ( unsigned long )
F_54 ( & V_1 -> V_20 ,
V_59 >> V_73 ) ;
if ( ! V_71 )
continue;
V_71 |= V_59 & ~ V_82 ;
V_99 = F_85 ( V_1 -> V_35 , V_71 ) ;
V_97 = F_86 ( V_75 - V_59 , V_69 - ( V_59 & ~ V_82 ) ) ;
F_87 ( V_99 , V_71 , V_97 , NULL ) ;
}
F_57 ( & V_1 -> V_35 -> V_79 ) ;
}
void F_88 ( struct V_100 * V_101 )
{
F_14 ( & V_102 ) ;
F_15 ( & V_101 -> V_38 , & V_103 ) ;
F_16 ( & V_102 ) ;
}
void F_89 ( struct V_100 * V_101 )
{
F_14 ( & V_102 ) ;
F_37 ( & V_101 -> V_38 ) ;
F_16 ( & V_102 ) ;
F_38 () ;
}
static void F_90 ( struct V_1 * V_1 , unsigned long V_104 ,
unsigned long V_105 )
{
struct V_100 * V_101 ;
F_91 (nb, &gmap_notifier_list, list)
V_101 -> V_106 ( V_1 , V_104 , V_105 ) ;
}
static inline unsigned long * F_92 ( struct V_1 * V_1 ,
unsigned long V_59 , int V_107 )
{
unsigned long * V_4 ;
if ( ( V_1 -> V_30 & V_89 ) + 4 < ( V_107 * 4 ) )
return NULL ;
if ( F_26 ( V_1 ) && V_1 -> V_54 )
return NULL ;
if ( V_59 & ( - 1UL << ( 31 + ( ( V_1 -> V_30 & V_89 ) >> 2 ) * 11 ) ) )
return NULL ;
V_4 = V_1 -> V_4 ;
switch ( V_1 -> V_30 & V_89 ) {
case V_13 :
V_4 += ( V_59 >> 53 ) & 0x7ff ;
if ( V_107 == 4 )
break;
if ( * V_4 & V_62 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
case V_11 :
V_4 += ( V_59 >> 42 ) & 0x7ff ;
if ( V_107 == 3 )
break;
if ( * V_4 & V_62 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
case V_9 :
V_4 += ( V_59 >> 31 ) & 0x7ff ;
if ( V_107 == 2 )
break;
if ( * V_4 & V_62 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
case V_7 :
V_4 += ( V_59 >> 20 ) & 0x7ff ;
if ( V_107 == 1 )
break;
if ( * V_4 & V_62 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_108 ) ;
V_4 += ( V_59 >> 12 ) & 0xff ;
}
return V_4 ;
}
static T_4 * F_93 ( struct V_1 * V_1 , unsigned long V_59 ,
T_1 * * V_85 )
{
unsigned long * V_4 ;
if ( F_26 ( V_1 ) )
F_14 ( & V_1 -> V_24 ) ;
V_4 = F_92 ( V_1 , V_59 , 1 ) ;
if ( ! V_4 || * V_4 & V_74 ) {
if ( F_26 ( V_1 ) )
F_16 ( & V_1 -> V_24 ) ;
return NULL ;
}
if ( F_26 ( V_1 ) ) {
* V_85 = & V_1 -> V_24 ;
return F_94 ( ( V_70 * ) V_4 , V_59 ) ;
}
return F_95 ( V_1 -> V_35 , ( V_70 * ) V_4 , V_59 , V_85 ) ;
}
static int F_96 ( struct V_1 * V_1 , unsigned long V_59 ,
unsigned long V_71 , int V_109 )
{
struct V_34 * V_35 = V_1 -> V_35 ;
unsigned int V_91 ;
bool V_92 = false ;
F_46 ( F_26 ( V_1 ) ) ;
V_91 = ( V_109 == V_110 ) ? V_111 : 0 ;
if ( F_78 ( V_95 , V_35 , V_71 , V_91 , & V_92 ) )
return - V_83 ;
if ( V_92 )
return 0 ;
return F_62 ( V_1 , V_59 , V_71 ) ;
}
static void F_97 ( T_1 * V_85 )
{
F_16 ( V_85 ) ;
}
static int F_98 ( struct V_1 * V_1 , unsigned long V_59 ,
unsigned long V_76 , int V_109 , unsigned long V_112 )
{
unsigned long V_71 ;
T_1 * V_85 ;
T_4 * V_96 ;
int V_84 ;
while ( V_76 ) {
V_84 = - V_113 ;
V_96 = F_93 ( V_1 , V_59 , & V_85 ) ;
if ( V_96 ) {
V_84 = F_99 ( V_1 -> V_35 , V_59 , V_96 , V_109 , V_112 ) ;
F_97 ( V_85 ) ;
}
if ( V_84 ) {
V_71 = F_53 ( V_1 , V_59 ) ;
if ( F_77 ( V_71 ) )
return V_71 ;
V_84 = F_96 ( V_1 , V_59 , V_71 , V_109 ) ;
if ( V_84 )
return V_84 ;
continue;
}
V_59 += V_114 ;
V_76 -= V_114 ;
}
return 0 ;
}
int F_100 ( struct V_1 * V_1 , unsigned long V_59 ,
unsigned long V_76 , int V_109 )
{
int V_84 ;
if ( ( V_59 & ~ V_115 ) || ( V_76 & ~ V_115 ) || F_26 ( V_1 ) )
return - V_78 ;
if ( ! V_116 && V_109 == V_117 )
return - V_78 ;
F_56 ( & V_1 -> V_35 -> V_79 ) ;
V_84 = F_98 ( V_1 , V_59 , V_76 , V_109 , V_118 ) ;
F_57 ( & V_1 -> V_35 -> V_79 ) ;
return V_84 ;
}
int F_101 ( struct V_1 * V_1 , unsigned long V_59 , unsigned long * V_119 )
{
unsigned long V_120 , V_71 ;
T_1 * V_85 ;
T_4 * V_96 , V_121 ;
int V_84 ;
while ( 1 ) {
V_84 = - V_113 ;
V_96 = F_93 ( V_1 , V_59 , & V_85 ) ;
if ( V_96 ) {
V_121 = * V_96 ;
if ( F_102 ( V_121 ) && ( F_103 ( V_121 ) & V_122 ) ) {
V_120 = F_103 ( V_121 ) & V_115 ;
V_120 += V_59 & ~ V_115 ;
* V_119 = * ( unsigned long * ) V_120 ;
F_103 ( * V_96 ) |= V_123 ;
V_84 = 0 ;
}
F_97 ( V_85 ) ;
}
if ( ! V_84 )
break;
V_71 = F_53 ( V_1 , V_59 ) ;
if ( F_77 ( V_71 ) ) {
V_84 = V_71 ;
break;
}
V_84 = F_96 ( V_1 , V_59 , V_71 , V_117 ) ;
if ( V_84 )
break;
}
return V_84 ;
}
static inline void F_104 ( struct V_1 * V_56 , unsigned long V_71 ,
struct V_49 * V_50 )
{
void * * V_46 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_46 = F_105 ( & V_56 -> V_23 , V_71 >> V_124 ) ;
if ( V_46 ) {
V_50 -> V_53 = F_106 ( V_46 ,
& V_56 -> V_24 ) ;
F_107 ( V_46 , V_50 ) ;
} else {
V_50 -> V_53 = NULL ;
F_52 ( & V_56 -> V_23 , V_71 >> V_124 ,
V_50 ) ;
}
}
static int F_108 ( struct V_1 * V_56 , unsigned long V_125 ,
unsigned long V_126 , unsigned long V_76 , int V_109 )
{
struct V_1 * V_55 ;
struct V_49 * V_50 ;
unsigned long V_71 ;
T_1 * V_85 ;
T_4 * V_96 ;
int V_84 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_55 = V_56 -> V_55 ;
while ( V_76 ) {
V_71 = F_53 ( V_55 , V_126 ) ;
if ( F_77 ( V_71 ) )
return V_71 ;
V_50 = F_2 ( sizeof( * V_50 ) , V_15 ) ;
if ( ! V_50 )
return - V_61 ;
V_50 -> V_125 = V_125 ;
V_84 = F_72 ( V_15 ) ;
if ( V_84 ) {
F_12 ( V_50 ) ;
return V_84 ;
}
V_84 = - V_113 ;
V_96 = F_93 ( V_55 , V_126 , & V_85 ) ;
if ( V_96 ) {
F_14 ( & V_56 -> V_24 ) ;
V_84 = F_99 ( V_55 -> V_35 , V_126 , V_96 , V_109 ,
V_127 ) ;
if ( ! V_84 )
F_104 ( V_56 , V_71 , V_50 ) ;
F_16 ( & V_56 -> V_24 ) ;
F_97 ( V_85 ) ;
}
F_75 () ;
if ( V_84 ) {
F_12 ( V_50 ) ;
V_84 = F_96 ( V_55 , V_126 , V_71 , V_109 ) ;
if ( V_84 )
return V_84 ;
continue;
}
V_126 += V_114 ;
V_76 -= V_114 ;
}
return 0 ;
}
static inline void F_109 ( unsigned long V_30 , unsigned long V_128 )
{
asm volatile(
" .insn rrf,0xb98e0000,%0,%1,0,0"
: : "a" (asce), "a" (vaddr) : "cc", "memory");
}
static void F_110 ( struct V_1 * V_56 , unsigned long V_125 )
{
unsigned long * V_4 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_4 = F_92 ( V_56 , V_125 , 0 ) ;
if ( ! V_4 || * V_4 & V_129 )
return;
F_90 ( V_56 , V_125 , V_125 + ( 1UL << 12 ) - 1 ) ;
F_111 ( V_56 -> V_35 , V_125 , ( T_4 * ) V_4 ) ;
}
static void F_112 ( struct V_1 * V_56 , unsigned long V_125 ,
unsigned long * V_130 )
{
int V_47 ;
F_46 ( ! F_26 ( V_56 ) ) ;
for ( V_47 = 0 ; V_47 < 256 ; V_47 ++ , V_125 += 1UL << 12 )
V_130 [ V_47 ] = V_129 ;
}
static void F_113 ( struct V_1 * V_56 , unsigned long V_125 )
{
unsigned long V_131 , * V_132 , * V_130 ;
struct V_3 * V_3 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_132 = F_92 ( V_56 , V_125 , 1 ) ;
if ( ! V_132 || ! ( * V_132 & V_108 ) )
return;
F_90 ( V_56 , V_125 , V_125 + ( 1UL << 20 ) - 1 ) ;
V_131 = ( unsigned long ) ( V_132 - ( ( V_125 >> 20 ) & 0x7ff ) ) ;
F_109 ( V_131 | V_7 , V_125 ) ;
V_130 = ( unsigned long * ) ( * V_132 & V_108 ) ;
* V_132 = V_8 ;
F_112 ( V_56 , V_125 , V_130 ) ;
V_3 = F_114 ( F_11 ( V_130 ) >> V_124 ) ;
F_36 ( & V_3 -> V_29 ) ;
F_29 ( V_3 ) ;
}
static void F_115 ( struct V_1 * V_56 , unsigned long V_125 ,
unsigned long * V_133 )
{
unsigned long V_30 , * V_130 ;
struct V_3 * V_3 ;
int V_47 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_30 = ( unsigned long ) V_133 | V_7 ;
for ( V_47 = 0 ; V_47 < 2048 ; V_47 ++ , V_125 += 1UL << 20 ) {
if ( ! ( V_133 [ V_47 ] & V_108 ) )
continue;
V_130 = ( unsigned long * ) ( V_133 [ V_47 ] & V_90 ) ;
V_133 [ V_47 ] = V_8 ;
F_112 ( V_56 , V_125 , V_130 ) ;
V_3 = F_114 ( F_11 ( V_130 ) >> V_124 ) ;
F_36 ( & V_3 -> V_29 ) ;
F_29 ( V_3 ) ;
}
}
static void F_116 ( struct V_1 * V_56 , unsigned long V_125 )
{
unsigned long V_134 , * V_135 , * V_133 ;
struct V_3 * V_3 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_135 = F_92 ( V_56 , V_125 , 2 ) ;
if ( ! V_135 || ! ( * V_135 & V_90 ) )
return;
F_90 ( V_56 , V_125 , V_125 + ( 1UL << 31 ) - 1 ) ;
V_134 = ( unsigned long ) ( V_135 - ( ( V_125 >> 31 ) & 0x7ff ) ) ;
F_109 ( V_134 | V_9 , V_125 ) ;
V_133 = ( unsigned long * ) ( * V_135 & V_90 ) ;
* V_135 = V_10 ;
F_115 ( V_56 , V_125 , V_133 ) ;
V_3 = F_114 ( F_11 ( V_133 ) >> V_124 ) ;
F_36 ( & V_3 -> V_29 ) ;
F_28 ( V_3 , 2 ) ;
}
static void F_117 ( struct V_1 * V_56 , unsigned long V_125 ,
unsigned long * V_136 )
{
unsigned long V_30 , * V_133 ;
struct V_3 * V_3 ;
int V_47 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_30 = ( unsigned long ) V_136 | V_9 ;
for ( V_47 = 0 ; V_47 < 2048 ; V_47 ++ , V_125 += 1UL << 31 ) {
if ( ! ( V_136 [ V_47 ] & V_90 ) )
continue;
V_133 = ( unsigned long * ) ( V_136 [ V_47 ] & V_90 ) ;
V_136 [ V_47 ] = V_10 ;
F_115 ( V_56 , V_125 , V_133 ) ;
V_3 = F_114 ( F_11 ( V_133 ) >> V_124 ) ;
F_36 ( & V_3 -> V_29 ) ;
F_28 ( V_3 , 2 ) ;
}
}
static void F_118 ( struct V_1 * V_56 , unsigned long V_125 )
{
unsigned long V_137 , * V_138 , * V_136 ;
struct V_3 * V_3 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_138 = F_92 ( V_56 , V_125 , 3 ) ;
if ( ! V_138 || ! ( * V_138 & V_90 ) )
return;
F_90 ( V_56 , V_125 , V_125 + ( 1UL << 42 ) - 1 ) ;
V_137 = ( unsigned long ) ( V_138 - ( ( V_125 >> 42 ) & 0x7ff ) ) ;
F_109 ( V_137 | V_11 , V_125 ) ;
V_136 = ( unsigned long * ) ( * V_138 & V_90 ) ;
* V_138 = V_12 ;
F_117 ( V_56 , V_125 , V_136 ) ;
V_3 = F_114 ( F_11 ( V_136 ) >> V_124 ) ;
F_36 ( & V_3 -> V_29 ) ;
F_28 ( V_3 , 2 ) ;
}
static void F_119 ( struct V_1 * V_56 , unsigned long V_125 ,
unsigned long * V_139 )
{
unsigned long V_30 , * V_136 ;
struct V_3 * V_3 ;
int V_47 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_30 = ( unsigned long ) V_139 | V_11 ;
for ( V_47 = 0 ; V_47 < 2048 ; V_47 ++ , V_125 += 1UL << 42 ) {
if ( ! ( V_139 [ V_47 ] & V_90 ) )
continue;
V_136 = ( unsigned long * ) ( V_139 [ V_47 ] & V_90 ) ;
V_139 [ V_47 ] = V_12 ;
F_117 ( V_56 , V_125 , V_136 ) ;
V_3 = F_114 ( F_11 ( V_136 ) >> V_124 ) ;
F_36 ( & V_3 -> V_29 ) ;
F_28 ( V_3 , 2 ) ;
}
}
static void F_120 ( struct V_1 * V_56 , unsigned long V_125 )
{
unsigned long V_140 , * V_141 , * V_139 ;
struct V_3 * V_3 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_141 = F_92 ( V_56 , V_125 , 4 ) ;
if ( ! V_141 || ! ( * V_141 & V_90 ) )
return;
F_90 ( V_56 , V_125 , V_125 + ( 1UL << 53 ) - 1 ) ;
V_140 = ( unsigned long ) ( V_141 - ( ( V_125 >> 53 ) & 0x7ff ) ) ;
F_109 ( V_140 | V_13 , V_125 ) ;
V_139 = ( unsigned long * ) ( * V_141 & V_90 ) ;
* V_141 = V_14 ;
F_119 ( V_56 , V_125 , V_139 ) ;
V_3 = F_114 ( F_11 ( V_139 ) >> V_124 ) ;
F_36 ( & V_3 -> V_29 ) ;
F_28 ( V_3 , 2 ) ;
}
static void F_121 ( struct V_1 * V_56 , unsigned long V_125 ,
unsigned long * V_142 )
{
unsigned long V_30 , * V_139 ;
struct V_3 * V_3 ;
int V_47 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_30 = ( unsigned long ) V_142 | V_13 ;
for ( V_47 = 0 ; V_47 < 2048 ; V_47 ++ , V_125 += 1UL << 53 ) {
if ( ! ( V_142 [ V_47 ] & V_90 ) )
continue;
V_139 = ( unsigned long * ) ( V_142 [ V_47 ] & V_90 ) ;
F_119 ( V_56 , V_125 , V_139 ) ;
F_109 ( V_30 , V_125 ) ;
V_142 [ V_47 ] = V_14 ;
V_3 = F_114 ( F_11 ( V_139 ) >> V_124 ) ;
F_36 ( & V_3 -> V_29 ) ;
F_28 ( V_3 , 2 ) ;
}
}
static void F_122 ( struct V_1 * V_56 )
{
unsigned long * V_4 ;
F_46 ( ! F_26 ( V_56 ) ) ;
if ( V_56 -> V_54 )
return;
V_56 -> V_54 = 1 ;
F_90 ( V_56 , 0 , - 1UL ) ;
F_17 ( V_56 ) ;
V_4 = ( unsigned long * ) ( V_56 -> V_30 & V_143 ) ;
switch ( V_56 -> V_30 & V_89 ) {
case V_13 :
F_121 ( V_56 , 0 , V_4 ) ;
break;
case V_11 :
F_119 ( V_56 , 0 , V_4 ) ;
break;
case V_9 :
F_117 ( V_56 , 0 , V_4 ) ;
break;
case V_7 :
F_115 ( V_56 , 0 , V_4 ) ;
break;
}
}
static struct V_1 * F_123 ( struct V_1 * V_55 , unsigned long V_30 ,
int V_144 )
{
struct V_1 * V_56 ;
F_91 (sg, &parent->children, list) {
if ( V_56 -> V_145 != V_30 || V_56 -> V_144 != V_144 ||
V_56 -> V_54 )
continue;
if ( ! V_56 -> V_146 )
return F_124 ( - V_113 ) ;
F_32 ( & V_56 -> V_26 ) ;
return V_56 ;
}
return NULL ;
}
int F_125 ( struct V_1 * V_56 , unsigned long V_30 , int V_144 )
{
if ( V_56 -> V_54 )
return 0 ;
return V_56 -> V_145 == V_30 && V_56 -> V_144 == V_144 ;
}
struct V_1 * F_126 ( struct V_1 * V_55 , unsigned long V_30 ,
int V_144 )
{
struct V_1 * V_56 , * V_60 ;
unsigned long V_2 ;
int V_84 ;
F_46 ( F_26 ( V_55 ) ) ;
F_14 ( & V_55 -> V_25 ) ;
V_56 = F_123 ( V_55 , V_30 , V_144 ) ;
F_16 ( & V_55 -> V_25 ) ;
if ( V_56 )
return V_56 ;
V_2 = - 1UL >> ( 33 - ( ( ( V_30 & V_89 ) >> 2 ) * 11 ) ) ;
if ( V_30 & V_147 )
V_2 = - 1UL ;
V_60 = F_1 ( V_2 ) ;
if ( ! V_60 )
return F_124 ( - V_61 ) ;
V_60 -> V_35 = V_55 -> V_35 ;
V_60 -> V_55 = F_31 ( V_55 ) ;
V_60 -> V_145 = V_30 ;
V_60 -> V_144 = V_144 ;
V_60 -> V_146 = false ;
F_14 ( & V_55 -> V_25 ) ;
V_56 = F_123 ( V_55 , V_30 , V_144 ) ;
if ( V_56 ) {
F_16 ( & V_55 -> V_25 ) ;
F_25 ( V_60 ) ;
return V_56 ;
}
if ( V_30 & V_147 ) {
F_91 (sg, &parent->children, list) {
if ( V_56 -> V_145 & V_147 ) {
F_14 ( & V_56 -> V_24 ) ;
F_122 ( V_56 ) ;
F_16 ( & V_56 -> V_24 ) ;
F_36 ( & V_56 -> V_38 ) ;
F_30 ( V_56 ) ;
break;
}
}
}
F_6 ( & V_60 -> V_26 , 2 ) ;
F_8 ( & V_60 -> V_38 , & V_55 -> V_18 ) ;
if ( V_30 & V_147 ) {
V_60 -> V_146 = true ;
F_16 ( & V_55 -> V_25 ) ;
return V_60 ;
}
F_16 ( & V_55 -> V_25 ) ;
F_56 ( & V_55 -> V_35 -> V_79 ) ;
V_84 = F_98 ( V_55 , V_30 & V_143 ,
( ( V_30 & V_31 ) + 1 ) * 4096 ,
V_117 , V_127 ) ;
F_57 ( & V_55 -> V_35 -> V_79 ) ;
F_14 ( & V_55 -> V_25 ) ;
V_60 -> V_146 = true ;
if ( V_84 ) {
F_36 ( & V_60 -> V_38 ) ;
F_25 ( V_60 ) ;
V_60 = F_124 ( V_84 ) ;
}
F_16 ( & V_55 -> V_25 ) ;
return V_60 ;
}
int F_127 ( struct V_1 * V_56 , unsigned long V_148 , unsigned long V_139 ,
int V_149 )
{
unsigned long V_125 , V_150 , V_66 , V_76 ;
unsigned long * V_151 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_61 ;
V_3 -> V_28 = V_139 & V_90 ;
if ( V_149 )
V_3 -> V_28 |= V_152 ;
V_151 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_56 -> V_24 ) ;
V_4 = F_92 ( V_56 , V_148 , 4 ) ;
if ( ! V_4 ) {
V_84 = - V_113 ;
goto V_27;
}
if ( ! ( * V_4 & V_62 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_90 ) {
V_84 = - V_113 ;
goto V_27;
}
F_10 ( V_151 , V_12 ) ;
* V_4 = ( unsigned long ) V_151 | V_63 |
V_153 | V_62 ;
if ( V_56 -> V_144 >= 1 )
* V_4 |= ( V_139 & V_154 ) ;
F_8 ( & V_3 -> V_29 , & V_56 -> V_17 ) ;
if ( V_149 ) {
* V_4 &= ~ V_62 ;
F_16 ( & V_56 -> V_24 ) ;
return 0 ;
}
F_16 ( & V_56 -> V_24 ) ;
V_125 = ( V_148 & 0xffe0000000000000UL ) | V_155 ;
V_150 = V_139 & V_90 ;
V_66 = ( ( V_139 & V_156 ) >> 6 ) * 4096 ;
V_76 = ( ( V_139 & V_63 ) + 1 ) * 4096 - V_66 ;
V_84 = F_108 ( V_56 , V_125 , V_150 + V_66 , V_76 , V_117 ) ;
F_14 ( & V_56 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_92 ( V_56 , V_148 , 4 ) ;
if ( ! V_4 || ( * V_4 & V_90 ) !=
( unsigned long ) V_151 )
V_84 = - V_113 ;
else
* V_4 &= ~ V_62 ;
} else {
F_120 ( V_56 , V_125 ) ;
}
F_16 ( & V_56 -> V_24 ) ;
return V_84 ;
V_27:
F_16 ( & V_56 -> V_24 ) ;
F_28 ( V_3 , 2 ) ;
return V_84 ;
}
int F_128 ( struct V_1 * V_56 , unsigned long V_148 , unsigned long V_136 ,
int V_149 )
{
unsigned long V_125 , V_150 , V_66 , V_76 ;
unsigned long * V_157 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_61 ;
V_3 -> V_28 = V_136 & V_90 ;
if ( V_149 )
V_3 -> V_28 |= V_152 ;
V_157 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_56 -> V_24 ) ;
V_4 = F_92 ( V_56 , V_148 , 3 ) ;
if ( ! V_4 ) {
V_84 = - V_113 ;
goto V_27;
}
if ( ! ( * V_4 & V_62 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_90 ) {
V_84 = - V_113 ;
}
F_10 ( V_157 , V_10 ) ;
* V_4 = ( unsigned long ) V_157 | V_63 |
V_158 | V_62 ;
if ( V_56 -> V_144 >= 1 )
* V_4 |= ( V_136 & V_154 ) ;
F_8 ( & V_3 -> V_29 , & V_56 -> V_17 ) ;
if ( V_149 ) {
* V_4 &= ~ V_62 ;
F_16 ( & V_56 -> V_24 ) ;
return 0 ;
}
F_16 ( & V_56 -> V_24 ) ;
V_125 = ( V_148 & 0xfffffc0000000000UL ) | V_159 ;
V_150 = V_136 & V_90 ;
V_66 = ( ( V_136 & V_156 ) >> 6 ) * 4096 ;
V_76 = ( ( V_136 & V_63 ) + 1 ) * 4096 - V_66 ;
V_84 = F_108 ( V_56 , V_125 , V_150 + V_66 , V_76 , V_117 ) ;
F_14 ( & V_56 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_92 ( V_56 , V_148 , 3 ) ;
if ( ! V_4 || ( * V_4 & V_90 ) !=
( unsigned long ) V_157 )
V_84 = - V_113 ;
else
* V_4 &= ~ V_62 ;
} else {
F_118 ( V_56 , V_125 ) ;
}
F_16 ( & V_56 -> V_24 ) ;
return V_84 ;
V_27:
F_16 ( & V_56 -> V_24 ) ;
F_28 ( V_3 , 2 ) ;
return V_84 ;
}
int F_129 ( struct V_1 * V_56 , unsigned long V_148 , unsigned long V_133 ,
int V_149 )
{
unsigned long V_125 , V_150 , V_66 , V_76 ;
unsigned long * V_160 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_46 ( ! F_26 ( V_56 ) || ( V_133 & V_161 ) ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_61 ;
V_3 -> V_28 = V_133 & V_90 ;
if ( V_149 )
V_3 -> V_28 |= V_152 ;
V_160 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_56 -> V_24 ) ;
V_4 = F_92 ( V_56 , V_148 , 2 ) ;
if ( ! V_4 ) {
V_84 = - V_113 ;
goto V_27;
}
if ( ! ( * V_4 & V_62 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_90 ) {
V_84 = - V_113 ;
goto V_27;
}
F_10 ( V_160 , V_8 ) ;
* V_4 = ( unsigned long ) V_160 | V_63 |
V_162 | V_62 ;
if ( V_56 -> V_144 >= 1 )
* V_4 |= V_133 & V_154 ;
F_8 ( & V_3 -> V_29 , & V_56 -> V_17 ) ;
if ( V_149 ) {
* V_4 &= ~ V_62 ;
F_16 ( & V_56 -> V_24 ) ;
return 0 ;
}
F_16 ( & V_56 -> V_24 ) ;
V_125 = ( V_148 & 0xffffffff80000000UL ) | V_163 ;
V_150 = V_133 & V_90 ;
V_66 = ( ( V_133 & V_156 ) >> 6 ) * 4096 ;
V_76 = ( ( V_133 & V_63 ) + 1 ) * 4096 - V_66 ;
V_84 = F_108 ( V_56 , V_125 , V_150 + V_66 , V_76 , V_117 ) ;
F_14 ( & V_56 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_92 ( V_56 , V_148 , 2 ) ;
if ( ! V_4 || ( * V_4 & V_90 ) !=
( unsigned long ) V_160 )
V_84 = - V_113 ;
else
* V_4 &= ~ V_62 ;
} else {
F_116 ( V_56 , V_125 ) ;
}
F_16 ( & V_56 -> V_24 ) ;
return V_84 ;
V_27:
F_16 ( & V_56 -> V_24 ) ;
F_28 ( V_3 , 2 ) ;
return V_84 ;
}
int F_130 ( struct V_1 * V_56 , unsigned long V_148 ,
unsigned long * V_130 , int * V_164 ,
int * V_149 )
{
unsigned long * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_46 ( ! F_26 ( V_56 ) ) ;
F_14 ( & V_56 -> V_24 ) ;
V_4 = F_92 ( V_56 , V_148 , 1 ) ;
if ( V_4 && ! ( * V_4 & V_74 ) ) {
V_3 = F_114 ( * V_4 >> V_124 ) ;
* V_130 = V_3 -> V_28 & ~ V_152 ;
* V_164 = ! ! ( * V_4 & V_165 ) ;
* V_149 = ! ! ( V_3 -> V_28 & V_152 ) ;
V_84 = 0 ;
} else {
V_84 = - V_113 ;
}
F_16 ( & V_56 -> V_24 ) ;
return V_84 ;
}
int F_131 ( struct V_1 * V_56 , unsigned long V_148 , unsigned long V_130 ,
int V_149 )
{
unsigned long V_125 , V_150 ;
unsigned long * V_166 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_46 ( ! F_26 ( V_56 ) || ( V_130 & V_167 ) ) ;
V_3 = F_132 ( V_56 -> V_35 ) ;
if ( ! V_3 )
return - V_61 ;
V_3 -> V_28 = V_130 & V_108 ;
if ( V_149 )
V_3 -> V_28 |= V_152 ;
V_166 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_56 -> V_24 ) ;
V_4 = F_92 ( V_56 , V_148 , 1 ) ;
if ( ! V_4 ) {
V_84 = - V_113 ;
goto V_27;
}
if ( ! ( * V_4 & V_74 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_108 ) {
V_84 = - V_113 ;
goto V_27;
}
* V_4 = ( unsigned long ) V_166 | V_168 |
( V_130 & V_165 ) | V_74 ;
F_8 ( & V_3 -> V_29 , & V_56 -> V_19 ) ;
if ( V_149 ) {
* V_4 &= ~ V_74 ;
F_16 ( & V_56 -> V_24 ) ;
return 0 ;
}
F_16 ( & V_56 -> V_24 ) ;
V_125 = ( V_148 & 0xfffffffffff00000UL ) | V_169 ;
V_150 = V_130 & V_108 & V_115 ;
V_84 = F_108 ( V_56 , V_125 , V_150 , V_114 , V_117 ) ;
F_14 ( & V_56 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_92 ( V_56 , V_148 , 1 ) ;
if ( ! V_4 || ( * V_4 & V_108 ) !=
( unsigned long ) V_166 )
V_84 = - V_113 ;
else
* V_4 &= ~ V_74 ;
} else {
F_113 ( V_56 , V_125 ) ;
}
F_16 ( & V_56 -> V_24 ) ;
return V_84 ;
V_27:
F_16 ( & V_56 -> V_24 ) ;
F_29 ( V_3 ) ;
return V_84 ;
}
int F_133 ( struct V_1 * V_56 , unsigned long V_148 , T_4 V_121 )
{
struct V_1 * V_55 ;
struct V_49 * V_50 ;
unsigned long V_71 , V_126 ;
T_1 * V_85 ;
T_4 * V_170 , * V_171 ;
int V_109 ;
int V_84 ;
F_46 ( ! F_26 ( V_56 ) ) ;
V_55 = V_56 -> V_55 ;
V_109 = ( F_103 ( V_121 ) & V_172 ) ? V_117 : V_110 ;
V_50 = F_2 ( sizeof( * V_50 ) , V_15 ) ;
if ( ! V_50 )
return - V_61 ;
V_50 -> V_125 = ( V_148 & V_115 ) | V_173 ;
while ( 1 ) {
V_126 = F_103 ( V_121 ) & V_115 ;
V_71 = F_53 ( V_55 , V_126 ) ;
if ( F_77 ( V_71 ) ) {
V_84 = V_71 ;
break;
}
V_84 = F_72 ( V_15 ) ;
if ( V_84 )
break;
V_84 = - V_113 ;
V_170 = F_93 ( V_55 , V_126 , & V_85 ) ;
if ( V_170 ) {
F_14 ( & V_56 -> V_24 ) ;
V_171 = ( T_4 * ) F_92 ( V_56 , V_148 , 0 ) ;
if ( ! V_171 ) {
F_16 ( & V_56 -> V_24 ) ;
F_97 ( V_85 ) ;
F_75 () ;
break;
}
V_84 = F_134 ( V_56 -> V_35 , V_148 , V_170 , V_171 , V_121 ) ;
if ( V_84 > 0 ) {
F_104 ( V_56 , V_71 , V_50 ) ;
V_50 = NULL ;
V_84 = 0 ;
}
F_97 ( V_85 ) ;
F_16 ( & V_56 -> V_24 ) ;
}
F_75 () ;
if ( ! V_84 )
break;
V_84 = F_96 ( V_55 , V_126 , V_71 , V_109 ) ;
if ( V_84 )
break;
}
F_12 ( V_50 ) ;
return V_84 ;
}
static void F_135 ( struct V_1 * V_56 , unsigned long V_71 ,
unsigned long V_66 , T_4 * V_121 )
{
struct V_49 * V_50 , * V_51 , * V_52 ;
unsigned long V_59 , V_104 , V_105 , V_112 , V_125 ;
unsigned long * V_4 ;
F_46 ( ! F_26 ( V_56 ) ) ;
F_14 ( & V_56 -> V_55 -> V_24 ) ;
V_4 = F_54 ( & V_56 -> V_55 -> V_21 ,
V_71 >> V_73 ) ;
V_59 = V_4 ? F_43 ( V_4 ) + V_66 : 0 ;
F_16 ( & V_56 -> V_55 -> V_24 ) ;
if ( ! V_4 )
return;
F_14 ( & V_56 -> V_24 ) ;
if ( V_56 -> V_54 ) {
F_16 ( & V_56 -> V_24 ) ;
return;
}
V_104 = V_56 -> V_145 & V_143 ;
V_105 = V_104 + ( ( V_56 -> V_145 & V_31 ) + 1 ) * 4096 ;
if ( ! ( V_56 -> V_145 & V_147 ) && V_59 >= V_104 &&
V_59 < V_105 ) {
F_122 ( V_56 ) ;
F_16 ( & V_56 -> V_24 ) ;
F_36 ( & V_56 -> V_38 ) ;
F_30 ( V_56 ) ;
return;
}
V_52 = F_22 ( & V_56 -> V_23 , V_71 >> 12 ) ;
F_24 (rmap, rnext, head) {
V_112 = V_50 -> V_125 & V_174 ;
V_125 = V_50 -> V_125 ^ V_112 ;
switch ( V_112 ) {
case V_155 :
F_120 ( V_56 , V_125 ) ;
break;
case V_159 :
F_118 ( V_56 , V_125 ) ;
break;
case V_163 :
F_116 ( V_56 , V_125 ) ;
break;
case V_169 :
F_113 ( V_56 , V_125 ) ;
break;
case V_173 :
F_110 ( V_56 , V_125 ) ;
break;
}
F_12 ( V_50 ) ;
}
F_16 ( & V_56 -> V_24 ) ;
}
void F_136 ( struct V_34 * V_35 , unsigned long V_71 ,
T_4 * V_121 , unsigned long V_112 )
{
unsigned long V_66 , V_59 ;
unsigned long * V_4 ;
struct V_1 * V_1 , * V_56 , * V_53 ;
V_66 = ( ( unsigned long ) V_121 ) & ( 255 * sizeof( T_4 ) ) ;
V_66 = V_66 * ( 4096 / sizeof( T_4 ) ) ;
F_59 () ;
F_60 (gmap, &mm->context.gmap_list, list) {
if ( ! F_35 ( & V_1 -> V_18 ) && ( V_112 & V_127 ) ) {
F_14 ( & V_1 -> V_25 ) ;
F_27 (sg, next,
&gmap->children, list)
F_135 ( V_56 , V_71 , V_66 , V_121 ) ;
F_16 ( & V_1 -> V_25 ) ;
}
if ( ! ( V_112 & V_118 ) )
continue;
F_14 ( & V_1 -> V_24 ) ;
V_4 = F_54 ( & V_1 -> V_21 ,
V_71 >> V_73 ) ;
if ( V_4 )
V_59 = F_43 ( V_4 ) + V_66 ;
F_16 ( & V_1 -> V_24 ) ;
if ( V_4 )
F_90 ( V_1 , V_59 , V_59 + V_114 - 1 ) ;
}
F_61 () ;
}
static inline void F_137 ( struct V_34 * V_35 )
{
#ifdef F_138
struct V_98 * V_99 ;
unsigned long V_175 ;
for ( V_99 = V_35 -> V_176 ; V_99 != NULL ; V_99 = V_99 -> V_177 ) {
for ( V_175 = V_99 -> V_178 ;
V_175 < V_99 -> V_179 ;
V_175 += V_114 )
F_139 ( V_99 , V_175 , V_180 ) ;
V_99 -> V_181 &= ~ V_182 ;
V_99 -> V_181 |= V_183 ;
}
V_35 -> V_184 |= V_183 ;
#endif
}
int F_140 ( void )
{
struct V_34 * V_35 = V_95 -> V_35 ;
if ( F_141 ( V_35 ) )
return 0 ;
if ( ! F_142 ( V_35 ) )
return - V_78 ;
F_49 ( & V_35 -> V_79 ) ;
V_35 -> V_36 . V_185 = 1 ;
F_137 ( V_35 ) ;
F_50 ( & V_35 -> V_79 ) ;
return 0 ;
}
static int F_143 ( T_4 * V_121 , unsigned long V_175 ,
unsigned long V_53 , struct V_186 * V_187 )
{
if ( F_144 ( F_145 ( * V_121 ) ) )
F_146 ( V_187 -> V_35 , V_175 , V_121 , F_147 ( V_129 ) ) ;
F_148 ( V_187 -> V_35 , V_175 , V_121 ) ;
return 0 ;
}
int F_149 ( void )
{
struct V_186 V_187 = { . V_188 = F_143 } ;
struct V_34 * V_35 = V_95 -> V_35 ;
struct V_98 * V_99 ;
int V_84 = 0 ;
F_49 ( & V_35 -> V_79 ) ;
if ( F_150 ( V_35 ) )
goto V_94;
V_35 -> V_36 . V_189 = 1 ;
for ( V_99 = V_35 -> V_176 ; V_99 ; V_99 = V_99 -> V_177 ) {
if ( F_151 ( V_99 , V_99 -> V_178 , V_99 -> V_179 ,
V_190 , & V_99 -> V_181 ) ) {
V_35 -> V_36 . V_189 = 0 ;
V_84 = - V_61 ;
goto V_94;
}
}
V_35 -> V_184 &= ~ V_191 ;
V_187 . V_35 = V_35 ;
F_152 ( 0 , V_192 , & V_187 ) ;
V_94:
F_50 ( & V_35 -> V_79 ) ;
return V_84 ;
}
static int F_153 ( T_4 * V_121 , unsigned long V_175 ,
unsigned long V_53 , struct V_186 * V_187 )
{
F_82 ( V_187 -> V_35 , V_175 , V_121 , 1 ) ;
return 0 ;
}
void F_154 ( struct V_34 * V_35 )
{
struct V_186 V_187 = { . V_188 = F_153 } ;
F_49 ( & V_35 -> V_79 ) ;
V_187 . V_35 = V_35 ;
F_152 ( 0 , V_192 , & V_187 ) ;
F_50 ( & V_35 -> V_79 ) ;
}
