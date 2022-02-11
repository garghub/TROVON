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
unsigned long V_36 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_35 = V_35 ;
F_14 ( & V_35 -> V_37 . V_38 ) ;
F_15 ( & V_1 -> V_39 , & V_35 -> V_37 . V_40 ) ;
if ( F_16 ( & V_35 -> V_37 . V_40 ) )
V_36 = V_1 -> V_30 ;
else
V_36 = - 1UL ;
F_17 ( V_35 -> V_37 . V_36 , V_36 ) ;
F_18 ( & V_35 -> V_37 . V_38 ) ;
return V_1 ;
}
static void F_19 ( struct V_1 * V_1 )
{
if ( V_41 )
F_20 ( V_1 -> V_30 ) ;
else
F_21 () ;
}
static void F_22 ( struct V_42 * V_43 )
{
struct V_44 V_45 ;
unsigned long V_46 [ 16 ] ;
unsigned long V_28 ;
void * * V_47 ;
int V_48 , V_49 ;
V_28 = 0 ;
do {
V_49 = 0 ;
F_23 (slot, root, &iter, index) {
V_46 [ V_49 ] = V_45 . V_28 ;
if ( ++ V_49 == 16 )
break;
}
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_28 = V_46 [ V_48 ] ;
F_24 ( V_43 , V_28 ) ;
}
} while ( V_49 > 0 );
}
static void F_25 ( struct V_42 * V_43 )
{
struct V_50 * V_51 , * V_52 , * V_53 ;
struct V_44 V_45 ;
unsigned long V_46 [ 16 ] ;
unsigned long V_28 ;
void * * V_47 ;
int V_48 , V_49 ;
V_28 = 0 ;
do {
V_49 = 0 ;
F_23 (slot, root, &iter, index) {
V_46 [ V_49 ] = V_45 . V_28 ;
if ( ++ V_49 == 16 )
break;
}
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_28 = V_46 [ V_48 ] ;
V_53 = F_24 ( V_43 , V_28 ) ;
F_26 (rmap, rnext, head)
F_12 ( V_51 ) ;
}
} while ( V_49 > 0 );
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_3 * V_3 , * V_54 ;
if ( ! ( F_28 ( V_1 ) && V_1 -> V_55 ) )
F_19 ( V_1 ) ;
F_29 (page, next, &gmap->crst_list, lru)
F_30 ( V_3 , 2 ) ;
F_22 ( & V_1 -> V_20 ) ;
F_22 ( & V_1 -> V_21 ) ;
if ( F_28 ( V_1 ) ) {
F_29 (page, next, &gmap->pt_list, lru)
F_31 ( V_3 ) ;
F_25 ( & V_1 -> V_23 ) ;
F_32 ( V_1 -> V_56 ) ;
}
F_12 ( V_1 ) ;
}
struct V_1 * F_33 ( struct V_1 * V_1 )
{
F_34 ( & V_1 -> V_26 ) ;
return V_1 ;
}
void F_32 ( struct V_1 * V_1 )
{
if ( F_35 ( & V_1 -> V_26 ) == 0 )
F_27 ( V_1 ) ;
}
void F_36 ( struct V_1 * V_1 )
{
struct V_1 * V_57 , * V_54 ;
unsigned long V_36 ;
if ( ! F_37 ( & V_1 -> V_18 ) ) {
F_14 ( & V_1 -> V_25 ) ;
F_29 (sg, next, &gmap->children, list) {
F_38 ( & V_57 -> V_39 ) ;
F_32 ( V_57 ) ;
}
F_18 ( & V_1 -> V_25 ) ;
}
F_14 ( & V_1 -> V_35 -> V_37 . V_38 ) ;
F_39 ( & V_1 -> V_39 ) ;
if ( F_37 ( & V_1 -> V_35 -> V_37 . V_40 ) )
V_36 = 0 ;
else if ( F_16 ( & V_1 -> V_35 -> V_37 . V_40 ) )
V_36 = F_40 ( & V_1 -> V_35 -> V_37 . V_40 ,
struct V_1 , V_39 ) -> V_30 ;
else
V_36 = - 1UL ;
F_17 ( V_1 -> V_35 -> V_37 . V_36 , V_36 ) ;
F_18 ( & V_1 -> V_35 -> V_37 . V_38 ) ;
F_41 () ;
F_32 ( V_1 ) ;
}
void F_42 ( struct V_1 * V_1 )
{
V_58 . V_1 = ( unsigned long ) V_1 ;
}
void F_43 ( struct V_1 * V_1 )
{
V_58 . V_1 = 0UL ;
}
struct V_1 * F_44 ( void )
{
return (struct V_1 * ) V_58 . V_1 ;
}
static int F_45 ( struct V_1 * V_1 , unsigned long * V_4 ,
unsigned long V_59 , unsigned long V_60 )
{
struct V_3 * V_3 ;
unsigned long * V_61 ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_62 ;
V_61 = ( unsigned long * ) F_9 ( V_3 ) ;
F_10 ( V_61 , V_59 ) ;
F_14 ( & V_1 -> V_24 ) ;
if ( * V_4 & V_63 ) {
F_8 ( & V_3 -> V_29 , & V_1 -> V_17 ) ;
* V_4 = ( unsigned long ) V_61 | V_64 |
( * V_4 & V_65 ) ;
V_3 -> V_28 = V_60 ;
V_3 = NULL ;
}
F_18 ( & V_1 -> V_24 ) ;
if ( V_3 )
F_30 ( V_3 , 2 ) ;
return 0 ;
}
static unsigned long F_46 ( unsigned long * V_66 )
{
struct V_3 * V_3 ;
unsigned long V_67 , V_68 ;
V_67 = ( unsigned long ) V_66 / sizeof( unsigned long ) ;
V_67 = ( V_67 & ( V_69 - 1 ) ) * V_70 ;
V_68 = ~ ( V_69 * sizeof( V_71 ) - 1 ) ;
V_3 = F_47 ( ( void * ) ( ( unsigned long ) V_66 & V_68 ) ) ;
return V_3 -> V_28 + V_67 ;
}
static int F_48 ( struct V_1 * V_1 , unsigned long V_72 )
{
unsigned long * V_66 ;
int V_73 = 0 ;
F_49 ( F_28 ( V_1 ) ) ;
F_14 ( & V_1 -> V_24 ) ;
V_66 = F_24 ( & V_1 -> V_21 , V_72 >> V_74 ) ;
if ( V_66 ) {
V_73 = ( * V_66 != V_8 ) ;
* V_66 = V_8 ;
}
F_18 ( & V_1 -> V_24 ) ;
return V_73 ;
}
static int F_50 ( struct V_1 * V_1 , unsigned long V_60 )
{
unsigned long V_72 ;
V_72 = ( unsigned long ) F_24 ( & V_1 -> V_20 ,
V_60 >> V_74 ) ;
return V_72 ? F_48 ( V_1 , V_72 ) : 0 ;
}
int F_51 ( struct V_1 * V_1 , unsigned long V_75 , unsigned long V_76 )
{
unsigned long V_77 ;
int V_73 ;
F_49 ( F_28 ( V_1 ) ) ;
if ( ( V_75 | V_76 ) & ( V_70 - 1 ) )
return - V_78 ;
if ( V_76 == 0 || V_75 + V_76 < V_75 )
return - V_78 ;
V_73 = 0 ;
F_52 ( & V_1 -> V_35 -> V_79 ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 += V_70 )
V_73 |= F_50 ( V_1 , V_75 + V_77 ) ;
F_53 ( & V_1 -> V_35 -> V_79 ) ;
if ( V_73 )
F_19 ( V_1 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_1 , unsigned long V_80 ,
unsigned long V_75 , unsigned long V_76 )
{
unsigned long V_77 ;
int V_73 ;
F_49 ( F_28 ( V_1 ) ) ;
if ( ( V_80 | V_75 | V_76 ) & ( V_70 - 1 ) )
return - V_78 ;
if ( V_76 == 0 || V_80 + V_76 < V_80 || V_75 + V_76 < V_75 ||
V_80 + V_76 - 1 > V_81 || V_75 + V_76 - 1 > V_1 -> V_33 )
return - V_78 ;
V_73 = 0 ;
F_52 ( & V_1 -> V_35 -> V_79 ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 += V_70 ) {
V_73 |= F_50 ( V_1 , V_75 + V_77 ) ;
if ( F_55 ( & V_1 -> V_20 ,
( V_75 + V_77 ) >> V_74 ,
( void * ) V_80 + V_77 ) )
break;
}
F_53 ( & V_1 -> V_35 -> V_79 ) ;
if ( V_73 )
F_19 ( V_1 ) ;
if ( V_77 >= V_76 )
return 0 ;
F_51 ( V_1 , V_75 , V_76 ) ;
return - V_62 ;
}
unsigned long F_56 ( struct V_1 * V_1 , unsigned long V_60 )
{
unsigned long V_72 ;
V_72 = ( unsigned long )
F_57 ( & V_1 -> V_20 , V_60 >> V_74 ) ;
return V_72 ? ( V_72 | ( V_60 & ~ V_82 ) ) : - V_83 ;
}
unsigned long F_58 ( struct V_1 * V_1 , unsigned long V_60 )
{
unsigned long V_84 ;
F_59 ( & V_1 -> V_35 -> V_79 ) ;
V_84 = F_56 ( V_1 , V_60 ) ;
F_60 ( & V_1 -> V_35 -> V_79 ) ;
return V_84 ;
}
void F_61 ( struct V_34 * V_35 , unsigned long * V_4 ,
unsigned long V_72 )
{
struct V_1 * V_1 ;
int V_73 ;
F_62 () ;
F_63 (gmap, &mm->context.gmap_list, list) {
V_73 = F_48 ( V_1 , V_72 ) ;
if ( V_73 )
F_19 ( V_1 ) ;
}
F_64 () ;
}
int F_65 ( struct V_1 * V_1 , unsigned long V_60 , unsigned long V_72 )
{
struct V_34 * V_35 ;
unsigned long * V_4 ;
T_1 * V_85 ;
T_2 * V_86 ;
T_3 * V_87 ;
V_71 * V_88 ;
int V_84 ;
F_49 ( F_28 ( V_1 ) ) ;
V_4 = V_1 -> V_4 ;
if ( ( V_1 -> V_30 & V_89 ) >= V_13 ) {
V_4 += ( V_60 >> 53 ) & 0x7ff ;
if ( ( * V_4 & V_63 ) &&
F_45 ( V_1 , V_4 , V_12 ,
V_60 & 0xffe0000000000000UL ) )
return - V_62 ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
}
if ( ( V_1 -> V_30 & V_89 ) >= V_11 ) {
V_4 += ( V_60 >> 42 ) & 0x7ff ;
if ( ( * V_4 & V_63 ) &&
F_45 ( V_1 , V_4 , V_10 ,
V_60 & 0xfffffc0000000000UL ) )
return - V_62 ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
}
if ( ( V_1 -> V_30 & V_89 ) >= V_9 ) {
V_4 += ( V_60 >> 31 ) & 0x7ff ;
if ( ( * V_4 & V_63 ) &&
F_45 ( V_1 , V_4 , V_8 ,
V_60 & 0xffffffff80000000UL ) )
return - V_62 ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
}
V_4 += ( V_60 >> 20 ) & 0x7ff ;
V_35 = V_1 -> V_35 ;
V_86 = F_66 ( V_35 , V_72 ) ;
F_67 ( F_68 ( * V_86 ) ) ;
V_87 = F_69 ( V_86 , V_72 ) ;
F_67 ( F_70 ( * V_87 ) ) ;
if ( F_71 ( * V_87 ) )
return - V_83 ;
V_88 = F_72 ( V_87 , V_72 ) ;
F_67 ( F_73 ( * V_88 ) ) ;
if ( F_74 ( * V_88 ) )
return - V_83 ;
V_84 = F_75 ( V_15 ) ;
if ( V_84 )
return V_84 ;
V_85 = F_76 ( V_35 , V_88 ) ;
F_14 ( & V_1 -> V_24 ) ;
if ( * V_4 == V_8 ) {
V_84 = F_55 ( & V_1 -> V_21 ,
V_72 >> V_74 , V_4 ) ;
if ( ! V_84 )
* V_4 = F_77 ( * V_88 ) ;
} else
V_84 = 0 ;
F_18 ( & V_1 -> V_24 ) ;
F_18 ( V_85 ) ;
F_78 () ;
return V_84 ;
}
int F_79 ( struct V_1 * V_1 , unsigned long V_60 ,
unsigned int V_91 )
{
unsigned long V_72 ;
int V_84 ;
bool V_92 ;
F_59 ( & V_1 -> V_35 -> V_79 ) ;
V_93:
V_92 = false ;
V_72 = F_56 ( V_1 , V_60 ) ;
if ( F_80 ( V_72 ) ) {
V_84 = V_72 ;
goto V_94;
}
if ( F_81 ( V_95 , V_1 -> V_35 , V_72 , V_91 ,
& V_92 ) ) {
V_84 = - V_83 ;
goto V_94;
}
if ( V_92 )
goto V_93;
V_84 = F_65 ( V_1 , V_60 , V_72 ) ;
V_94:
F_60 ( & V_1 -> V_35 -> V_79 ) ;
return V_84 ;
}
void F_82 ( struct V_1 * V_1 , unsigned long V_60 )
{
unsigned long V_72 ;
T_1 * V_85 ;
T_4 * V_96 ;
V_72 = ( unsigned long ) F_57 ( & V_1 -> V_20 ,
V_60 >> V_74 ) ;
if ( V_72 ) {
V_72 |= V_60 & ~ V_82 ;
V_96 = F_83 ( V_1 -> V_35 , V_72 , & V_85 ) ;
if ( F_84 ( V_96 ) )
F_85 ( V_1 -> V_35 , V_72 , V_96 , 0 ) ;
F_86 ( V_96 , V_85 ) ;
}
}
void F_87 ( struct V_1 * V_1 , unsigned long V_80 , unsigned long V_75 )
{
unsigned long V_60 , V_72 , V_97 ;
struct V_98 * V_99 ;
F_59 ( & V_1 -> V_35 -> V_79 ) ;
for ( V_60 = V_80 ; V_60 < V_75 ;
V_60 = ( V_60 + V_70 ) & V_82 ) {
V_72 = ( unsigned long )
F_57 ( & V_1 -> V_20 ,
V_60 >> V_74 ) ;
if ( ! V_72 )
continue;
V_72 |= V_60 & ~ V_82 ;
V_99 = F_88 ( V_1 -> V_35 , V_72 ) ;
V_97 = F_89 ( V_75 - V_60 , V_70 - ( V_60 & ~ V_82 ) ) ;
F_90 ( V_99 , V_72 , V_97 ) ;
}
F_60 ( & V_1 -> V_35 -> V_79 ) ;
}
void F_91 ( struct V_100 * V_101 )
{
F_14 ( & V_102 ) ;
F_15 ( & V_101 -> V_39 , & V_103 ) ;
F_18 ( & V_102 ) ;
}
void F_92 ( struct V_100 * V_101 )
{
F_14 ( & V_102 ) ;
F_39 ( & V_101 -> V_39 ) ;
F_18 ( & V_102 ) ;
F_41 () ;
}
static void F_93 ( struct V_1 * V_1 , unsigned long V_104 ,
unsigned long V_105 )
{
struct V_100 * V_101 ;
F_94 (nb, &gmap_notifier_list, list)
V_101 -> V_106 ( V_1 , V_104 , V_105 ) ;
}
static inline unsigned long * F_95 ( struct V_1 * V_1 ,
unsigned long V_60 , int V_107 )
{
unsigned long * V_4 ;
if ( ( V_1 -> V_30 & V_89 ) + 4 < ( V_107 * 4 ) )
return NULL ;
if ( F_28 ( V_1 ) && V_1 -> V_55 )
return NULL ;
if ( V_60 & ( - 1UL << ( 31 + ( ( V_1 -> V_30 & V_89 ) >> 2 ) * 11 ) ) )
return NULL ;
V_4 = V_1 -> V_4 ;
switch ( V_1 -> V_30 & V_89 ) {
case V_13 :
V_4 += ( V_60 >> 53 ) & 0x7ff ;
if ( V_107 == 4 )
break;
if ( * V_4 & V_63 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
case V_11 :
V_4 += ( V_60 >> 42 ) & 0x7ff ;
if ( V_107 == 3 )
break;
if ( * V_4 & V_63 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
case V_9 :
V_4 += ( V_60 >> 31 ) & 0x7ff ;
if ( V_107 == 2 )
break;
if ( * V_4 & V_63 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_90 ) ;
case V_7 :
V_4 += ( V_60 >> 20 ) & 0x7ff ;
if ( V_107 == 1 )
break;
if ( * V_4 & V_63 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_108 ) ;
V_4 += ( V_60 >> 12 ) & 0xff ;
}
return V_4 ;
}
static T_4 * F_96 ( struct V_1 * V_1 , unsigned long V_60 ,
T_1 * * V_85 )
{
unsigned long * V_4 ;
if ( F_28 ( V_1 ) )
F_14 ( & V_1 -> V_24 ) ;
V_4 = F_95 ( V_1 , V_60 , 1 ) ;
if ( ! V_4 || * V_4 & V_109 ) {
if ( F_28 ( V_1 ) )
F_18 ( & V_1 -> V_24 ) ;
return NULL ;
}
if ( F_28 ( V_1 ) ) {
* V_85 = & V_1 -> V_24 ;
return F_97 ( ( V_71 * ) V_4 , V_60 ) ;
}
return F_98 ( V_1 -> V_35 , ( V_71 * ) V_4 , V_60 , V_85 ) ;
}
static int F_99 ( struct V_1 * V_1 , unsigned long V_60 ,
unsigned long V_72 , int V_110 )
{
struct V_34 * V_35 = V_1 -> V_35 ;
unsigned int V_91 ;
bool V_92 = false ;
F_49 ( F_28 ( V_1 ) ) ;
V_91 = ( V_110 == V_111 ) ? V_112 : 0 ;
if ( F_81 ( V_95 , V_35 , V_72 , V_91 , & V_92 ) )
return - V_83 ;
if ( V_92 )
return 0 ;
return F_65 ( V_1 , V_60 , V_72 ) ;
}
static void F_100 ( T_1 * V_85 )
{
F_18 ( V_85 ) ;
}
static int F_101 ( struct V_1 * V_1 , unsigned long V_60 ,
unsigned long V_76 , int V_110 , unsigned long V_113 )
{
unsigned long V_72 ;
T_1 * V_85 ;
T_4 * V_96 ;
int V_84 ;
while ( V_76 ) {
V_84 = - V_114 ;
V_96 = F_96 ( V_1 , V_60 , & V_85 ) ;
if ( V_96 ) {
V_84 = F_102 ( V_1 -> V_35 , V_60 , V_96 , V_110 , V_113 ) ;
F_100 ( V_85 ) ;
}
if ( V_84 ) {
V_72 = F_56 ( V_1 , V_60 ) ;
if ( F_80 ( V_72 ) )
return V_72 ;
V_84 = F_99 ( V_1 , V_60 , V_72 , V_110 ) ;
if ( V_84 )
return V_84 ;
continue;
}
V_60 += V_115 ;
V_76 -= V_115 ;
}
return 0 ;
}
int F_103 ( struct V_1 * V_1 , unsigned long V_60 ,
unsigned long V_76 , int V_110 )
{
int V_84 ;
if ( ( V_60 & ~ V_116 ) || ( V_76 & ~ V_116 ) || F_28 ( V_1 ) )
return - V_78 ;
if ( ! V_117 && V_110 == V_118 )
return - V_78 ;
F_59 ( & V_1 -> V_35 -> V_79 ) ;
V_84 = F_101 ( V_1 , V_60 , V_76 , V_110 , V_119 ) ;
F_60 ( & V_1 -> V_35 -> V_79 ) ;
return V_84 ;
}
int F_104 ( struct V_1 * V_1 , unsigned long V_60 , unsigned long * V_120 )
{
unsigned long V_121 , V_72 ;
T_1 * V_85 ;
T_4 * V_96 , V_122 ;
int V_84 ;
while ( 1 ) {
V_84 = - V_114 ;
V_96 = F_96 ( V_1 , V_60 , & V_85 ) ;
if ( V_96 ) {
V_122 = * V_96 ;
if ( F_105 ( V_122 ) && ( F_106 ( V_122 ) & V_123 ) ) {
V_121 = F_106 ( V_122 ) & V_116 ;
V_121 += V_60 & ~ V_116 ;
* V_120 = * ( unsigned long * ) V_121 ;
F_106 ( * V_96 ) |= V_124 ;
V_84 = 0 ;
}
F_100 ( V_85 ) ;
}
if ( ! V_84 )
break;
V_72 = F_56 ( V_1 , V_60 ) ;
if ( F_80 ( V_72 ) ) {
V_84 = V_72 ;
break;
}
V_84 = F_99 ( V_1 , V_60 , V_72 , V_118 ) ;
if ( V_84 )
break;
}
return V_84 ;
}
static inline void F_107 ( struct V_1 * V_57 , unsigned long V_72 ,
struct V_50 * V_51 )
{
void * * V_47 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_47 = F_108 ( & V_57 -> V_23 , V_72 >> V_125 ) ;
if ( V_47 ) {
V_51 -> V_54 = F_109 ( V_47 ,
& V_57 -> V_24 ) ;
F_110 ( & V_57 -> V_23 , V_47 , V_51 ) ;
} else {
V_51 -> V_54 = NULL ;
F_55 ( & V_57 -> V_23 , V_72 >> V_125 ,
V_51 ) ;
}
}
static int F_111 ( struct V_1 * V_57 , unsigned long V_126 ,
unsigned long V_127 , unsigned long V_76 , int V_110 )
{
struct V_1 * V_56 ;
struct V_50 * V_51 ;
unsigned long V_72 ;
T_1 * V_85 ;
T_4 * V_96 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_56 = V_57 -> V_56 ;
while ( V_76 ) {
V_72 = F_56 ( V_56 , V_127 ) ;
if ( F_80 ( V_72 ) )
return V_72 ;
V_51 = F_2 ( sizeof( * V_51 ) , V_15 ) ;
if ( ! V_51 )
return - V_62 ;
V_51 -> V_126 = V_126 ;
V_84 = F_75 ( V_15 ) ;
if ( V_84 ) {
F_12 ( V_51 ) ;
return V_84 ;
}
V_84 = - V_114 ;
V_96 = F_96 ( V_56 , V_127 , & V_85 ) ;
if ( V_96 ) {
F_14 ( & V_57 -> V_24 ) ;
V_84 = F_102 ( V_56 -> V_35 , V_127 , V_96 , V_110 ,
V_128 ) ;
if ( ! V_84 )
F_107 ( V_57 , V_72 , V_51 ) ;
F_18 ( & V_57 -> V_24 ) ;
F_100 ( V_85 ) ;
}
F_78 () ;
if ( V_84 ) {
F_12 ( V_51 ) ;
V_84 = F_99 ( V_56 , V_127 , V_72 , V_110 ) ;
if ( V_84 )
return V_84 ;
continue;
}
V_127 += V_115 ;
V_76 -= V_115 ;
}
return 0 ;
}
static inline void F_112 ( unsigned long V_30 , unsigned long V_129 )
{
asm volatile(
" .insn rrf,0xb98e0000,%0,%1,0,0"
: : "a" (asce), "a" (vaddr) : "cc", "memory");
}
static void F_113 ( struct V_1 * V_57 , unsigned long V_126 )
{
unsigned long * V_4 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_4 = F_95 ( V_57 , V_126 , 0 ) ;
if ( ! V_4 || * V_4 & V_130 )
return;
F_93 ( V_57 , V_126 , V_126 + ( 1UL << 12 ) - 1 ) ;
F_114 ( V_57 -> V_35 , V_126 , ( T_4 * ) V_4 ) ;
}
static void F_115 ( struct V_1 * V_57 , unsigned long V_126 ,
unsigned long * V_131 )
{
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
for ( V_48 = 0 ; V_48 < 256 ; V_48 ++ , V_126 += 1UL << 12 )
V_131 [ V_48 ] = V_130 ;
}
static void F_116 ( struct V_1 * V_57 , unsigned long V_126 )
{
unsigned long V_132 , * V_133 , * V_131 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_133 = F_95 ( V_57 , V_126 , 1 ) ;
if ( ! V_133 || ! ( * V_133 & V_108 ) )
return;
F_93 ( V_57 , V_126 , V_126 + ( 1UL << 20 ) - 1 ) ;
V_132 = ( unsigned long ) ( V_133 - ( ( V_126 >> 20 ) & 0x7ff ) ) ;
F_112 ( V_132 | V_7 , V_126 ) ;
V_131 = ( unsigned long * ) ( * V_133 & V_108 ) ;
* V_133 = V_8 ;
F_115 ( V_57 , V_126 , V_131 ) ;
V_3 = F_117 ( F_11 ( V_131 ) >> V_125 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_31 ( V_3 ) ;
}
static void F_118 ( struct V_1 * V_57 , unsigned long V_126 ,
unsigned long * V_134 )
{
unsigned long V_30 , * V_131 ;
struct V_3 * V_3 ;
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_30 = ( unsigned long ) V_134 | V_7 ;
for ( V_48 = 0 ; V_48 < 2048 ; V_48 ++ , V_126 += 1UL << 20 ) {
if ( ! ( V_134 [ V_48 ] & V_108 ) )
continue;
V_131 = ( unsigned long * ) ( V_134 [ V_48 ] & V_90 ) ;
V_134 [ V_48 ] = V_8 ;
F_115 ( V_57 , V_126 , V_131 ) ;
V_3 = F_117 ( F_11 ( V_131 ) >> V_125 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_31 ( V_3 ) ;
}
}
static void F_119 ( struct V_1 * V_57 , unsigned long V_126 )
{
unsigned long V_135 , * V_136 , * V_134 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_136 = F_95 ( V_57 , V_126 , 2 ) ;
if ( ! V_136 || ! ( * V_136 & V_90 ) )
return;
F_93 ( V_57 , V_126 , V_126 + ( 1UL << 31 ) - 1 ) ;
V_135 = ( unsigned long ) ( V_136 - ( ( V_126 >> 31 ) & 0x7ff ) ) ;
F_112 ( V_135 | V_9 , V_126 ) ;
V_134 = ( unsigned long * ) ( * V_136 & V_90 ) ;
* V_136 = V_10 ;
F_118 ( V_57 , V_126 , V_134 ) ;
V_3 = F_117 ( F_11 ( V_134 ) >> V_125 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
static void F_120 ( struct V_1 * V_57 , unsigned long V_126 ,
unsigned long * V_137 )
{
unsigned long V_30 , * V_134 ;
struct V_3 * V_3 ;
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_30 = ( unsigned long ) V_137 | V_9 ;
for ( V_48 = 0 ; V_48 < 2048 ; V_48 ++ , V_126 += 1UL << 31 ) {
if ( ! ( V_137 [ V_48 ] & V_90 ) )
continue;
V_134 = ( unsigned long * ) ( V_137 [ V_48 ] & V_90 ) ;
V_137 [ V_48 ] = V_10 ;
F_118 ( V_57 , V_126 , V_134 ) ;
V_3 = F_117 ( F_11 ( V_134 ) >> V_125 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
}
static void F_121 ( struct V_1 * V_57 , unsigned long V_126 )
{
unsigned long V_138 , * V_139 , * V_137 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_139 = F_95 ( V_57 , V_126 , 3 ) ;
if ( ! V_139 || ! ( * V_139 & V_90 ) )
return;
F_93 ( V_57 , V_126 , V_126 + ( 1UL << 42 ) - 1 ) ;
V_138 = ( unsigned long ) ( V_139 - ( ( V_126 >> 42 ) & 0x7ff ) ) ;
F_112 ( V_138 | V_11 , V_126 ) ;
V_137 = ( unsigned long * ) ( * V_139 & V_90 ) ;
* V_139 = V_12 ;
F_120 ( V_57 , V_126 , V_137 ) ;
V_3 = F_117 ( F_11 ( V_137 ) >> V_125 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
static void F_122 ( struct V_1 * V_57 , unsigned long V_126 ,
unsigned long * V_140 )
{
unsigned long V_30 , * V_137 ;
struct V_3 * V_3 ;
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_30 = ( unsigned long ) V_140 | V_11 ;
for ( V_48 = 0 ; V_48 < 2048 ; V_48 ++ , V_126 += 1UL << 42 ) {
if ( ! ( V_140 [ V_48 ] & V_90 ) )
continue;
V_137 = ( unsigned long * ) ( V_140 [ V_48 ] & V_90 ) ;
V_140 [ V_48 ] = V_12 ;
F_120 ( V_57 , V_126 , V_137 ) ;
V_3 = F_117 ( F_11 ( V_137 ) >> V_125 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
}
static void F_123 ( struct V_1 * V_57 , unsigned long V_126 )
{
unsigned long V_141 , * V_142 , * V_140 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_142 = F_95 ( V_57 , V_126 , 4 ) ;
if ( ! V_142 || ! ( * V_142 & V_90 ) )
return;
F_93 ( V_57 , V_126 , V_126 + ( 1UL << 53 ) - 1 ) ;
V_141 = ( unsigned long ) ( V_142 - ( ( V_126 >> 53 ) & 0x7ff ) ) ;
F_112 ( V_141 | V_13 , V_126 ) ;
V_140 = ( unsigned long * ) ( * V_142 & V_90 ) ;
* V_142 = V_14 ;
F_122 ( V_57 , V_126 , V_140 ) ;
V_3 = F_117 ( F_11 ( V_140 ) >> V_125 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
static void F_124 ( struct V_1 * V_57 , unsigned long V_126 ,
unsigned long * V_143 )
{
unsigned long V_30 , * V_140 ;
struct V_3 * V_3 ;
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_30 = ( unsigned long ) V_143 | V_13 ;
for ( V_48 = 0 ; V_48 < 2048 ; V_48 ++ , V_126 += 1UL << 53 ) {
if ( ! ( V_143 [ V_48 ] & V_90 ) )
continue;
V_140 = ( unsigned long * ) ( V_143 [ V_48 ] & V_90 ) ;
F_122 ( V_57 , V_126 , V_140 ) ;
F_112 ( V_30 , V_126 ) ;
V_143 [ V_48 ] = V_14 ;
V_3 = F_117 ( F_11 ( V_140 ) >> V_125 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
}
static void F_125 ( struct V_1 * V_57 )
{
unsigned long * V_4 ;
F_49 ( ! F_28 ( V_57 ) ) ;
if ( V_57 -> V_55 )
return;
V_57 -> V_55 = 1 ;
F_93 ( V_57 , 0 , - 1UL ) ;
F_19 ( V_57 ) ;
V_4 = ( unsigned long * ) ( V_57 -> V_30 & V_144 ) ;
switch ( V_57 -> V_30 & V_89 ) {
case V_13 :
F_124 ( V_57 , 0 , V_4 ) ;
break;
case V_11 :
F_122 ( V_57 , 0 , V_4 ) ;
break;
case V_9 :
F_120 ( V_57 , 0 , V_4 ) ;
break;
case V_7 :
F_118 ( V_57 , 0 , V_4 ) ;
break;
}
}
static struct V_1 * F_126 ( struct V_1 * V_56 , unsigned long V_30 ,
int V_145 )
{
struct V_1 * V_57 ;
F_94 (sg, &parent->children, list) {
if ( V_57 -> V_146 != V_30 || V_57 -> V_145 != V_145 ||
V_57 -> V_55 )
continue;
if ( ! V_57 -> V_147 )
return F_127 ( - V_114 ) ;
F_34 ( & V_57 -> V_26 ) ;
return V_57 ;
}
return NULL ;
}
int F_128 ( struct V_1 * V_57 , unsigned long V_30 , int V_145 )
{
if ( V_57 -> V_55 )
return 0 ;
return V_57 -> V_146 == V_30 && V_57 -> V_145 == V_145 ;
}
struct V_1 * F_129 ( struct V_1 * V_56 , unsigned long V_30 ,
int V_145 )
{
struct V_1 * V_57 , * V_61 ;
unsigned long V_2 ;
int V_84 ;
F_49 ( F_28 ( V_56 ) ) ;
F_14 ( & V_56 -> V_25 ) ;
V_57 = F_126 ( V_56 , V_30 , V_145 ) ;
F_18 ( & V_56 -> V_25 ) ;
if ( V_57 )
return V_57 ;
V_2 = - 1UL >> ( 33 - ( ( ( V_30 & V_89 ) >> 2 ) * 11 ) ) ;
if ( V_30 & V_148 )
V_2 = - 1UL ;
V_61 = F_1 ( V_2 ) ;
if ( ! V_61 )
return F_127 ( - V_62 ) ;
V_61 -> V_35 = V_56 -> V_35 ;
V_61 -> V_56 = F_33 ( V_56 ) ;
V_61 -> V_146 = V_30 ;
V_61 -> V_145 = V_145 ;
V_61 -> V_147 = false ;
F_14 ( & V_56 -> V_25 ) ;
V_57 = F_126 ( V_56 , V_30 , V_145 ) ;
if ( V_57 ) {
F_18 ( & V_56 -> V_25 ) ;
F_27 ( V_61 ) ;
return V_57 ;
}
if ( V_30 & V_148 ) {
F_94 (sg, &parent->children, list) {
if ( V_57 -> V_146 & V_148 ) {
F_14 ( & V_57 -> V_24 ) ;
F_125 ( V_57 ) ;
F_18 ( & V_57 -> V_24 ) ;
F_38 ( & V_57 -> V_39 ) ;
F_32 ( V_57 ) ;
break;
}
}
}
F_6 ( & V_61 -> V_26 , 2 ) ;
F_8 ( & V_61 -> V_39 , & V_56 -> V_18 ) ;
if ( V_30 & V_148 ) {
V_61 -> V_147 = true ;
F_18 ( & V_56 -> V_25 ) ;
return V_61 ;
}
F_18 ( & V_56 -> V_25 ) ;
F_59 ( & V_56 -> V_35 -> V_79 ) ;
V_84 = F_101 ( V_56 , V_30 & V_144 ,
( ( V_30 & V_31 ) + 1 ) * 4096 ,
V_118 , V_128 ) ;
F_60 ( & V_56 -> V_35 -> V_79 ) ;
F_14 ( & V_56 -> V_25 ) ;
V_61 -> V_147 = true ;
if ( V_84 ) {
F_38 ( & V_61 -> V_39 ) ;
F_27 ( V_61 ) ;
V_61 = F_127 ( V_84 ) ;
}
F_18 ( & V_56 -> V_25 ) ;
return V_61 ;
}
int F_130 ( struct V_1 * V_57 , unsigned long V_149 , unsigned long V_140 ,
int V_150 )
{
unsigned long V_126 , V_151 , V_67 , V_76 ;
unsigned long * V_152 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_28 = V_140 & V_90 ;
if ( V_150 )
V_3 -> V_28 |= V_153 ;
V_152 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_95 ( V_57 , V_149 , 4 ) ;
if ( ! V_4 ) {
V_84 = - V_114 ;
goto V_27;
}
if ( ! ( * V_4 & V_63 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_90 ) {
V_84 = - V_114 ;
goto V_27;
}
F_10 ( V_152 , V_12 ) ;
* V_4 = ( unsigned long ) V_152 | V_64 |
V_154 | V_63 ;
if ( V_57 -> V_145 >= 1 )
* V_4 |= ( V_140 & V_155 ) ;
F_8 ( & V_3 -> V_29 , & V_57 -> V_17 ) ;
if ( V_150 ) {
* V_4 &= ~ V_63 ;
F_18 ( & V_57 -> V_24 ) ;
return 0 ;
}
F_18 ( & V_57 -> V_24 ) ;
V_126 = ( V_149 & 0xffe0000000000000UL ) | V_156 ;
V_151 = V_140 & V_90 ;
V_67 = ( ( V_140 & V_157 ) >> 6 ) * 4096 ;
V_76 = ( ( V_140 & V_64 ) + 1 ) * 4096 - V_67 ;
V_84 = F_111 ( V_57 , V_126 , V_151 + V_67 , V_76 , V_118 ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_95 ( V_57 , V_149 , 4 ) ;
if ( ! V_4 || ( * V_4 & V_90 ) !=
( unsigned long ) V_152 )
V_84 = - V_114 ;
else
* V_4 &= ~ V_63 ;
} else {
F_123 ( V_57 , V_126 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
V_27:
F_18 ( & V_57 -> V_24 ) ;
F_30 ( V_3 , 2 ) ;
return V_84 ;
}
int F_131 ( struct V_1 * V_57 , unsigned long V_149 , unsigned long V_137 ,
int V_150 )
{
unsigned long V_126 , V_151 , V_67 , V_76 ;
unsigned long * V_158 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_28 = V_137 & V_90 ;
if ( V_150 )
V_3 -> V_28 |= V_153 ;
V_158 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_95 ( V_57 , V_149 , 3 ) ;
if ( ! V_4 ) {
V_84 = - V_114 ;
goto V_27;
}
if ( ! ( * V_4 & V_63 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_90 ) {
V_84 = - V_114 ;
}
F_10 ( V_158 , V_10 ) ;
* V_4 = ( unsigned long ) V_158 | V_64 |
V_159 | V_63 ;
if ( V_57 -> V_145 >= 1 )
* V_4 |= ( V_137 & V_155 ) ;
F_8 ( & V_3 -> V_29 , & V_57 -> V_17 ) ;
if ( V_150 ) {
* V_4 &= ~ V_63 ;
F_18 ( & V_57 -> V_24 ) ;
return 0 ;
}
F_18 ( & V_57 -> V_24 ) ;
V_126 = ( V_149 & 0xfffffc0000000000UL ) | V_160 ;
V_151 = V_137 & V_90 ;
V_67 = ( ( V_137 & V_157 ) >> 6 ) * 4096 ;
V_76 = ( ( V_137 & V_64 ) + 1 ) * 4096 - V_67 ;
V_84 = F_111 ( V_57 , V_126 , V_151 + V_67 , V_76 , V_118 ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_95 ( V_57 , V_149 , 3 ) ;
if ( ! V_4 || ( * V_4 & V_90 ) !=
( unsigned long ) V_158 )
V_84 = - V_114 ;
else
* V_4 &= ~ V_63 ;
} else {
F_121 ( V_57 , V_126 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
V_27:
F_18 ( & V_57 -> V_24 ) ;
F_30 ( V_3 , 2 ) ;
return V_84 ;
}
int F_132 ( struct V_1 * V_57 , unsigned long V_149 , unsigned long V_134 ,
int V_150 )
{
unsigned long V_126 , V_151 , V_67 , V_76 ;
unsigned long * V_161 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) || ( V_134 & V_162 ) ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_28 = V_134 & V_90 ;
if ( V_150 )
V_3 -> V_28 |= V_153 ;
V_161 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_95 ( V_57 , V_149 , 2 ) ;
if ( ! V_4 ) {
V_84 = - V_114 ;
goto V_27;
}
if ( ! ( * V_4 & V_63 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_90 ) {
V_84 = - V_114 ;
goto V_27;
}
F_10 ( V_161 , V_8 ) ;
* V_4 = ( unsigned long ) V_161 | V_64 |
V_163 | V_63 ;
if ( V_57 -> V_145 >= 1 )
* V_4 |= V_134 & V_155 ;
F_8 ( & V_3 -> V_29 , & V_57 -> V_17 ) ;
if ( V_150 ) {
* V_4 &= ~ V_63 ;
F_18 ( & V_57 -> V_24 ) ;
return 0 ;
}
F_18 ( & V_57 -> V_24 ) ;
V_126 = ( V_149 & 0xffffffff80000000UL ) | V_164 ;
V_151 = V_134 & V_90 ;
V_67 = ( ( V_134 & V_157 ) >> 6 ) * 4096 ;
V_76 = ( ( V_134 & V_64 ) + 1 ) * 4096 - V_67 ;
V_84 = F_111 ( V_57 , V_126 , V_151 + V_67 , V_76 , V_118 ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_95 ( V_57 , V_149 , 2 ) ;
if ( ! V_4 || ( * V_4 & V_90 ) !=
( unsigned long ) V_161 )
V_84 = - V_114 ;
else
* V_4 &= ~ V_63 ;
} else {
F_119 ( V_57 , V_126 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
V_27:
F_18 ( & V_57 -> V_24 ) ;
F_30 ( V_3 , 2 ) ;
return V_84 ;
}
int F_133 ( struct V_1 * V_57 , unsigned long V_149 ,
unsigned long * V_131 , int * V_165 ,
int * V_150 )
{
unsigned long * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_95 ( V_57 , V_149 , 1 ) ;
if ( V_4 && ! ( * V_4 & V_109 ) ) {
V_3 = F_117 ( * V_4 >> V_125 ) ;
* V_131 = V_3 -> V_28 & ~ V_153 ;
* V_165 = ! ! ( * V_4 & V_166 ) ;
* V_150 = ! ! ( V_3 -> V_28 & V_153 ) ;
V_84 = 0 ;
} else {
V_84 = - V_114 ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
}
int F_134 ( struct V_1 * V_57 , unsigned long V_149 , unsigned long V_131 ,
int V_150 )
{
unsigned long V_126 , V_151 ;
unsigned long * V_167 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) || ( V_131 & V_168 ) ) ;
V_3 = F_135 ( V_57 -> V_35 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_28 = V_131 & V_108 ;
if ( V_150 )
V_3 -> V_28 |= V_153 ;
V_167 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_95 ( V_57 , V_149 , 1 ) ;
if ( ! V_4 ) {
V_84 = - V_114 ;
goto V_27;
}
if ( ! ( * V_4 & V_109 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_108 ) {
V_84 = - V_114 ;
goto V_27;
}
* V_4 = ( unsigned long ) V_167 | V_169 |
( V_131 & V_166 ) | V_109 ;
F_8 ( & V_3 -> V_29 , & V_57 -> V_19 ) ;
if ( V_150 ) {
* V_4 &= ~ V_109 ;
F_18 ( & V_57 -> V_24 ) ;
return 0 ;
}
F_18 ( & V_57 -> V_24 ) ;
V_126 = ( V_149 & 0xfffffffffff00000UL ) | V_170 ;
V_151 = V_131 & V_108 & V_116 ;
V_84 = F_111 ( V_57 , V_126 , V_151 , V_115 , V_118 ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_95 ( V_57 , V_149 , 1 ) ;
if ( ! V_4 || ( * V_4 & V_108 ) !=
( unsigned long ) V_167 )
V_84 = - V_114 ;
else
* V_4 &= ~ V_109 ;
} else {
F_116 ( V_57 , V_126 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
V_27:
F_18 ( & V_57 -> V_24 ) ;
F_31 ( V_3 ) ;
return V_84 ;
}
int F_136 ( struct V_1 * V_57 , unsigned long V_149 , T_4 V_122 )
{
struct V_1 * V_56 ;
struct V_50 * V_51 ;
unsigned long V_72 , V_127 ;
T_1 * V_85 ;
T_4 * V_171 , * V_172 ;
int V_110 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_56 = V_57 -> V_56 ;
V_110 = ( F_106 ( V_122 ) & V_173 ) ? V_118 : V_111 ;
V_51 = F_2 ( sizeof( * V_51 ) , V_15 ) ;
if ( ! V_51 )
return - V_62 ;
V_51 -> V_126 = ( V_149 & V_116 ) | V_174 ;
while ( 1 ) {
V_127 = F_106 ( V_122 ) & V_116 ;
V_72 = F_56 ( V_56 , V_127 ) ;
if ( F_80 ( V_72 ) ) {
V_84 = V_72 ;
break;
}
V_84 = F_75 ( V_15 ) ;
if ( V_84 )
break;
V_84 = - V_114 ;
V_171 = F_96 ( V_56 , V_127 , & V_85 ) ;
if ( V_171 ) {
F_14 ( & V_57 -> V_24 ) ;
V_172 = ( T_4 * ) F_95 ( V_57 , V_149 , 0 ) ;
if ( ! V_172 ) {
F_18 ( & V_57 -> V_24 ) ;
F_100 ( V_85 ) ;
F_78 () ;
break;
}
V_84 = F_137 ( V_57 -> V_35 , V_149 , V_171 , V_172 , V_122 ) ;
if ( V_84 > 0 ) {
F_107 ( V_57 , V_72 , V_51 ) ;
V_51 = NULL ;
V_84 = 0 ;
}
F_100 ( V_85 ) ;
F_18 ( & V_57 -> V_24 ) ;
}
F_78 () ;
if ( ! V_84 )
break;
V_84 = F_99 ( V_56 , V_127 , V_72 , V_110 ) ;
if ( V_84 )
break;
}
F_12 ( V_51 ) ;
return V_84 ;
}
static void F_138 ( struct V_1 * V_57 , unsigned long V_72 ,
unsigned long V_60 , T_4 * V_122 )
{
struct V_50 * V_51 , * V_52 , * V_53 ;
unsigned long V_104 , V_105 , V_113 , V_126 ;
F_49 ( ! F_28 ( V_57 ) ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( V_57 -> V_55 ) {
F_18 ( & V_57 -> V_24 ) ;
return;
}
V_104 = V_57 -> V_146 & V_144 ;
V_105 = V_104 + ( ( V_57 -> V_146 & V_31 ) + 1 ) * 4096 ;
if ( ! ( V_57 -> V_146 & V_148 ) && V_60 >= V_104 &&
V_60 < V_105 ) {
F_125 ( V_57 ) ;
F_18 ( & V_57 -> V_24 ) ;
F_38 ( & V_57 -> V_39 ) ;
F_32 ( V_57 ) ;
return;
}
V_53 = F_24 ( & V_57 -> V_23 , V_72 >> 12 ) ;
F_26 (rmap, rnext, head) {
V_113 = V_51 -> V_126 & V_175 ;
V_126 = V_51 -> V_126 ^ V_113 ;
switch ( V_113 ) {
case V_156 :
F_123 ( V_57 , V_126 ) ;
break;
case V_160 :
F_121 ( V_57 , V_126 ) ;
break;
case V_164 :
F_119 ( V_57 , V_126 ) ;
break;
case V_170 :
F_116 ( V_57 , V_126 ) ;
break;
case V_174 :
F_113 ( V_57 , V_126 ) ;
break;
}
F_12 ( V_51 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
}
void F_139 ( struct V_34 * V_35 , unsigned long V_72 ,
T_4 * V_122 , unsigned long V_113 )
{
unsigned long V_67 , V_60 = 0 ;
unsigned long * V_4 ;
struct V_1 * V_1 , * V_57 , * V_54 ;
V_67 = ( ( unsigned long ) V_122 ) & ( 255 * sizeof( T_4 ) ) ;
V_67 = V_67 * ( 4096 / sizeof( T_4 ) ) ;
F_62 () ;
F_63 (gmap, &mm->context.gmap_list, list) {
F_14 ( & V_1 -> V_24 ) ;
V_4 = F_57 ( & V_1 -> V_21 ,
V_72 >> V_74 ) ;
if ( V_4 )
V_60 = F_46 ( V_4 ) + V_67 ;
F_18 ( & V_1 -> V_24 ) ;
if ( ! V_4 )
continue;
if ( ! F_37 ( & V_1 -> V_18 ) && ( V_113 & V_128 ) ) {
F_14 ( & V_1 -> V_25 ) ;
F_29 (sg, next,
&gmap->children, list)
F_138 ( V_57 , V_72 , V_60 , V_122 ) ;
F_18 ( & V_1 -> V_25 ) ;
}
if ( V_113 & V_119 )
F_93 ( V_1 , V_60 , V_60 + V_115 - 1 ) ;
}
F_64 () ;
}
static inline void F_140 ( struct V_34 * V_35 )
{
#ifdef F_141
struct V_98 * V_99 ;
unsigned long V_176 ;
for ( V_99 = V_35 -> V_177 ; V_99 != NULL ; V_99 = V_99 -> V_178 ) {
for ( V_176 = V_99 -> V_179 ;
V_176 < V_99 -> V_180 ;
V_176 += V_115 )
F_142 ( V_99 , V_176 , V_181 ) ;
V_99 -> V_182 &= ~ V_183 ;
V_99 -> V_182 |= V_184 ;
}
V_35 -> V_185 |= V_184 ;
#endif
}
int F_143 ( void )
{
struct V_34 * V_35 = V_95 -> V_35 ;
if ( F_144 ( V_35 ) )
return 0 ;
if ( ! F_145 ( V_35 ) )
return - V_78 ;
F_52 ( & V_35 -> V_79 ) ;
V_35 -> V_37 . V_186 = 1 ;
F_140 ( V_35 ) ;
F_53 ( & V_35 -> V_79 ) ;
return 0 ;
}
static int F_146 ( T_4 * V_122 , unsigned long V_176 ,
unsigned long V_54 , struct V_187 * V_188 )
{
if ( F_147 ( F_148 ( * V_122 ) ) )
F_149 ( V_188 -> V_35 , V_176 , V_122 , F_150 ( V_130 ) ) ;
F_151 ( V_188 -> V_35 , V_176 , V_122 ) ;
return 0 ;
}
int F_152 ( void )
{
struct V_187 V_188 = { . V_189 = F_146 } ;
struct V_34 * V_35 = V_95 -> V_35 ;
struct V_98 * V_99 ;
int V_84 = 0 ;
F_52 ( & V_35 -> V_79 ) ;
if ( F_153 ( V_35 ) )
goto V_94;
V_35 -> V_37 . V_190 = 1 ;
for ( V_99 = V_35 -> V_177 ; V_99 ; V_99 = V_99 -> V_178 ) {
if ( F_154 ( V_99 , V_99 -> V_179 , V_99 -> V_180 ,
V_191 , & V_99 -> V_182 ) ) {
V_35 -> V_37 . V_190 = 0 ;
V_84 = - V_62 ;
goto V_94;
}
}
V_35 -> V_185 &= ~ V_192 ;
V_188 . V_35 = V_35 ;
F_155 ( 0 , V_193 , & V_188 ) ;
V_94:
F_53 ( & V_35 -> V_79 ) ;
return V_84 ;
}
static int F_156 ( T_4 * V_122 , unsigned long V_176 ,
unsigned long V_54 , struct V_187 * V_188 )
{
F_85 ( V_188 -> V_35 , V_176 , V_122 , 1 ) ;
return 0 ;
}
void F_157 ( struct V_34 * V_35 )
{
struct V_187 V_188 = { . V_189 = F_156 } ;
F_52 ( & V_35 -> V_79 ) ;
V_188 . V_35 = V_35 ;
F_155 ( 0 , V_193 , & V_188 ) ;
F_53 ( & V_35 -> V_79 ) ;
}
