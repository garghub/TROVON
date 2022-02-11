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
void T_1 * * V_47 ;
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
void T_1 * * V_47 ;
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
T_2 * V_85 ;
T_3 * V_86 ;
T_4 * V_87 ;
T_5 * V_88 ;
V_71 * V_89 ;
int V_84 ;
F_49 ( F_28 ( V_1 ) ) ;
V_4 = V_1 -> V_4 ;
if ( ( V_1 -> V_30 & V_90 ) >= V_13 ) {
V_4 += ( V_60 >> 53 ) & 0x7ff ;
if ( ( * V_4 & V_63 ) &&
F_45 ( V_1 , V_4 , V_12 ,
V_60 & 0xffe0000000000000UL ) )
return - V_62 ;
V_4 = ( unsigned long * ) ( * V_4 & V_91 ) ;
}
if ( ( V_1 -> V_30 & V_90 ) >= V_11 ) {
V_4 += ( V_60 >> 42 ) & 0x7ff ;
if ( ( * V_4 & V_63 ) &&
F_45 ( V_1 , V_4 , V_10 ,
V_60 & 0xfffffc0000000000UL ) )
return - V_62 ;
V_4 = ( unsigned long * ) ( * V_4 & V_91 ) ;
}
if ( ( V_1 -> V_30 & V_90 ) >= V_9 ) {
V_4 += ( V_60 >> 31 ) & 0x7ff ;
if ( ( * V_4 & V_63 ) &&
F_45 ( V_1 , V_4 , V_8 ,
V_60 & 0xffffffff80000000UL ) )
return - V_62 ;
V_4 = ( unsigned long * ) ( * V_4 & V_91 ) ;
}
V_4 += ( V_60 >> 20 ) & 0x7ff ;
V_35 = V_1 -> V_35 ;
V_86 = F_66 ( V_35 , V_72 ) ;
F_67 ( F_68 ( * V_86 ) ) ;
V_87 = F_69 ( V_86 , V_72 ) ;
F_67 ( F_70 ( * V_87 ) ) ;
V_88 = F_71 ( V_87 , V_72 ) ;
F_67 ( F_72 ( * V_88 ) ) ;
if ( F_73 ( * V_88 ) )
return - V_83 ;
V_89 = F_74 ( V_88 , V_72 ) ;
F_67 ( F_75 ( * V_89 ) ) ;
if ( F_76 ( * V_89 ) )
return - V_83 ;
V_84 = F_77 ( V_15 ) ;
if ( V_84 )
return V_84 ;
V_85 = F_78 ( V_35 , V_89 ) ;
F_14 ( & V_1 -> V_24 ) ;
if ( * V_4 == V_8 ) {
V_84 = F_55 ( & V_1 -> V_21 ,
V_72 >> V_74 , V_4 ) ;
if ( ! V_84 )
* V_4 = F_79 ( * V_89 ) ;
} else
V_84 = 0 ;
F_18 ( & V_1 -> V_24 ) ;
F_18 ( V_85 ) ;
F_80 () ;
return V_84 ;
}
int F_81 ( struct V_1 * V_1 , unsigned long V_60 ,
unsigned int V_92 )
{
unsigned long V_72 ;
int V_84 ;
bool V_93 ;
F_59 ( & V_1 -> V_35 -> V_79 ) ;
V_94:
V_93 = false ;
V_72 = F_56 ( V_1 , V_60 ) ;
if ( F_82 ( V_72 ) ) {
V_84 = V_72 ;
goto V_95;
}
if ( F_83 ( V_96 , V_1 -> V_35 , V_72 , V_92 ,
& V_93 ) ) {
V_84 = - V_83 ;
goto V_95;
}
if ( V_93 )
goto V_94;
V_84 = F_65 ( V_1 , V_60 , V_72 ) ;
V_95:
F_60 ( & V_1 -> V_35 -> V_79 ) ;
return V_84 ;
}
void F_84 ( struct V_1 * V_1 , unsigned long V_60 )
{
unsigned long V_72 ;
T_2 * V_85 ;
T_6 * V_97 ;
V_72 = ( unsigned long ) F_57 ( & V_1 -> V_20 ,
V_60 >> V_74 ) ;
if ( V_72 ) {
V_72 |= V_60 & ~ V_82 ;
V_97 = F_85 ( V_1 -> V_35 , V_72 , & V_85 ) ;
if ( F_86 ( V_97 ) )
F_87 ( V_1 -> V_35 , V_72 , V_97 , 0 ) ;
F_88 ( V_97 , V_85 ) ;
}
}
void F_89 ( struct V_1 * V_1 , unsigned long V_80 , unsigned long V_75 )
{
unsigned long V_60 , V_72 , V_98 ;
struct V_99 * V_100 ;
F_59 ( & V_1 -> V_35 -> V_79 ) ;
for ( V_60 = V_80 ; V_60 < V_75 ;
V_60 = ( V_60 + V_70 ) & V_82 ) {
V_72 = ( unsigned long )
F_57 ( & V_1 -> V_20 ,
V_60 >> V_74 ) ;
if ( ! V_72 )
continue;
V_72 |= V_60 & ~ V_82 ;
V_100 = F_90 ( V_1 -> V_35 , V_72 ) ;
V_98 = F_91 ( V_75 - V_60 , V_70 - ( V_60 & ~ V_82 ) ) ;
F_92 ( V_100 , V_72 , V_98 ) ;
}
F_60 ( & V_1 -> V_35 -> V_79 ) ;
}
void F_93 ( struct V_101 * V_102 )
{
F_14 ( & V_103 ) ;
F_15 ( & V_102 -> V_39 , & V_104 ) ;
F_18 ( & V_103 ) ;
}
void F_94 ( struct V_101 * V_102 )
{
F_14 ( & V_103 ) ;
F_39 ( & V_102 -> V_39 ) ;
F_18 ( & V_103 ) ;
F_41 () ;
}
static void F_95 ( struct V_1 * V_1 , unsigned long V_105 ,
unsigned long V_106 )
{
struct V_101 * V_102 ;
F_96 (nb, &gmap_notifier_list, list)
V_102 -> V_107 ( V_1 , V_105 , V_106 ) ;
}
static inline unsigned long * F_97 ( struct V_1 * V_1 ,
unsigned long V_60 , int V_108 )
{
unsigned long * V_4 ;
if ( ( V_1 -> V_30 & V_90 ) + 4 < ( V_108 * 4 ) )
return NULL ;
if ( F_28 ( V_1 ) && V_1 -> V_55 )
return NULL ;
if ( V_60 & ( - 1UL << ( 31 + ( ( V_1 -> V_30 & V_90 ) >> 2 ) * 11 ) ) )
return NULL ;
V_4 = V_1 -> V_4 ;
switch ( V_1 -> V_30 & V_90 ) {
case V_13 :
V_4 += ( V_60 >> 53 ) & 0x7ff ;
if ( V_108 == 4 )
break;
if ( * V_4 & V_63 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_91 ) ;
case V_11 :
V_4 += ( V_60 >> 42 ) & 0x7ff ;
if ( V_108 == 3 )
break;
if ( * V_4 & V_63 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_91 ) ;
case V_9 :
V_4 += ( V_60 >> 31 ) & 0x7ff ;
if ( V_108 == 2 )
break;
if ( * V_4 & V_63 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_91 ) ;
case V_7 :
V_4 += ( V_60 >> 20 ) & 0x7ff ;
if ( V_108 == 1 )
break;
if ( * V_4 & V_63 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_109 ) ;
V_4 += ( V_60 >> 12 ) & 0xff ;
}
return V_4 ;
}
static T_6 * F_98 ( struct V_1 * V_1 , unsigned long V_60 ,
T_2 * * V_85 )
{
unsigned long * V_4 ;
if ( F_28 ( V_1 ) )
F_14 ( & V_1 -> V_24 ) ;
V_4 = F_97 ( V_1 , V_60 , 1 ) ;
if ( ! V_4 || * V_4 & V_110 ) {
if ( F_28 ( V_1 ) )
F_18 ( & V_1 -> V_24 ) ;
return NULL ;
}
if ( F_28 ( V_1 ) ) {
* V_85 = & V_1 -> V_24 ;
return F_99 ( ( V_71 * ) V_4 , V_60 ) ;
}
return F_100 ( V_1 -> V_35 , ( V_71 * ) V_4 , V_60 , V_85 ) ;
}
static int F_101 ( struct V_1 * V_1 , unsigned long V_60 ,
unsigned long V_72 , int V_111 )
{
struct V_34 * V_35 = V_1 -> V_35 ;
unsigned int V_92 ;
bool V_93 = false ;
F_49 ( F_28 ( V_1 ) ) ;
V_92 = ( V_111 == V_112 ) ? V_113 : 0 ;
if ( F_83 ( V_96 , V_35 , V_72 , V_92 , & V_93 ) )
return - V_83 ;
if ( V_93 )
return 0 ;
return F_65 ( V_1 , V_60 , V_72 ) ;
}
static void F_102 ( T_2 * V_85 )
{
F_18 ( V_85 ) ;
}
static int F_103 ( struct V_1 * V_1 , unsigned long V_60 ,
unsigned long V_76 , int V_111 , unsigned long V_114 )
{
unsigned long V_72 ;
T_2 * V_85 ;
T_6 * V_97 ;
int V_84 ;
while ( V_76 ) {
V_84 = - V_115 ;
V_97 = F_98 ( V_1 , V_60 , & V_85 ) ;
if ( V_97 ) {
V_84 = F_104 ( V_1 -> V_35 , V_60 , V_97 , V_111 , V_114 ) ;
F_102 ( V_85 ) ;
}
if ( V_84 ) {
V_72 = F_56 ( V_1 , V_60 ) ;
if ( F_82 ( V_72 ) )
return V_72 ;
V_84 = F_101 ( V_1 , V_60 , V_72 , V_111 ) ;
if ( V_84 )
return V_84 ;
continue;
}
V_60 += V_116 ;
V_76 -= V_116 ;
}
return 0 ;
}
int F_105 ( struct V_1 * V_1 , unsigned long V_60 ,
unsigned long V_76 , int V_111 )
{
int V_84 ;
if ( ( V_60 & ~ V_117 ) || ( V_76 & ~ V_117 ) || F_28 ( V_1 ) )
return - V_78 ;
if ( ! V_118 && V_111 == V_119 )
return - V_78 ;
F_59 ( & V_1 -> V_35 -> V_79 ) ;
V_84 = F_103 ( V_1 , V_60 , V_76 , V_111 , V_120 ) ;
F_60 ( & V_1 -> V_35 -> V_79 ) ;
return V_84 ;
}
int F_106 ( struct V_1 * V_1 , unsigned long V_60 , unsigned long * V_121 )
{
unsigned long V_122 , V_72 ;
T_2 * V_85 ;
T_6 * V_97 , V_123 ;
int V_84 ;
while ( 1 ) {
V_84 = - V_115 ;
V_97 = F_98 ( V_1 , V_60 , & V_85 ) ;
if ( V_97 ) {
V_123 = * V_97 ;
if ( F_107 ( V_123 ) && ( F_108 ( V_123 ) & V_124 ) ) {
V_122 = F_108 ( V_123 ) & V_117 ;
V_122 += V_60 & ~ V_117 ;
* V_121 = * ( unsigned long * ) V_122 ;
F_108 ( * V_97 ) |= V_125 ;
V_84 = 0 ;
}
F_102 ( V_85 ) ;
}
if ( ! V_84 )
break;
V_72 = F_56 ( V_1 , V_60 ) ;
if ( F_82 ( V_72 ) ) {
V_84 = V_72 ;
break;
}
V_84 = F_101 ( V_1 , V_60 , V_72 , V_119 ) ;
if ( V_84 )
break;
}
return V_84 ;
}
static inline void F_109 ( struct V_1 * V_57 , unsigned long V_72 ,
struct V_50 * V_51 )
{
void T_1 * * V_47 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_47 = F_110 ( & V_57 -> V_23 , V_72 >> V_126 ) ;
if ( V_47 ) {
V_51 -> V_54 = F_111 ( V_47 ,
& V_57 -> V_24 ) ;
F_112 ( & V_57 -> V_23 , V_47 , V_51 ) ;
} else {
V_51 -> V_54 = NULL ;
F_55 ( & V_57 -> V_23 , V_72 >> V_126 ,
V_51 ) ;
}
}
static int F_113 ( struct V_1 * V_57 , unsigned long V_127 ,
unsigned long V_128 , unsigned long V_76 , int V_111 )
{
struct V_1 * V_56 ;
struct V_50 * V_51 ;
unsigned long V_72 ;
T_2 * V_85 ;
T_6 * V_97 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_56 = V_57 -> V_56 ;
while ( V_76 ) {
V_72 = F_56 ( V_56 , V_128 ) ;
if ( F_82 ( V_72 ) )
return V_72 ;
V_51 = F_2 ( sizeof( * V_51 ) , V_15 ) ;
if ( ! V_51 )
return - V_62 ;
V_51 -> V_127 = V_127 ;
V_84 = F_77 ( V_15 ) ;
if ( V_84 ) {
F_12 ( V_51 ) ;
return V_84 ;
}
V_84 = - V_115 ;
V_97 = F_98 ( V_56 , V_128 , & V_85 ) ;
if ( V_97 ) {
F_14 ( & V_57 -> V_24 ) ;
V_84 = F_104 ( V_56 -> V_35 , V_128 , V_97 , V_111 ,
V_129 ) ;
if ( ! V_84 )
F_109 ( V_57 , V_72 , V_51 ) ;
F_18 ( & V_57 -> V_24 ) ;
F_102 ( V_85 ) ;
}
F_80 () ;
if ( V_84 ) {
F_12 ( V_51 ) ;
V_84 = F_101 ( V_56 , V_128 , V_72 , V_111 ) ;
if ( V_84 )
return V_84 ;
continue;
}
V_128 += V_116 ;
V_76 -= V_116 ;
}
return 0 ;
}
static inline void F_114 ( unsigned long V_30 , unsigned long V_130 )
{
asm volatile(
" .insn rrf,0xb98e0000,%0,%1,0,0"
: : "a" (asce), "a" (vaddr) : "cc", "memory");
}
static void F_115 ( struct V_1 * V_57 , unsigned long V_127 )
{
unsigned long * V_4 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_4 = F_97 ( V_57 , V_127 , 0 ) ;
if ( ! V_4 || * V_4 & V_131 )
return;
F_95 ( V_57 , V_127 , V_127 + ( 1UL << 12 ) - 1 ) ;
F_116 ( V_57 -> V_35 , V_127 , ( T_6 * ) V_4 ) ;
}
static void F_117 ( struct V_1 * V_57 , unsigned long V_127 ,
unsigned long * V_132 )
{
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
for ( V_48 = 0 ; V_48 < 256 ; V_48 ++ , V_127 += 1UL << 12 )
V_132 [ V_48 ] = V_131 ;
}
static void F_118 ( struct V_1 * V_57 , unsigned long V_127 )
{
unsigned long V_133 , * V_134 , * V_132 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_134 = F_97 ( V_57 , V_127 , 1 ) ;
if ( ! V_134 || ! ( * V_134 & V_109 ) )
return;
F_95 ( V_57 , V_127 , V_127 + ( 1UL << 20 ) - 1 ) ;
V_133 = ( unsigned long ) ( V_134 - ( ( V_127 >> 20 ) & 0x7ff ) ) ;
F_114 ( V_133 | V_7 , V_127 ) ;
V_132 = ( unsigned long * ) ( * V_134 & V_109 ) ;
* V_134 = V_8 ;
F_117 ( V_57 , V_127 , V_132 ) ;
V_3 = F_119 ( F_11 ( V_132 ) >> V_126 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_31 ( V_3 ) ;
}
static void F_120 ( struct V_1 * V_57 , unsigned long V_127 ,
unsigned long * V_135 )
{
unsigned long V_30 , * V_132 ;
struct V_3 * V_3 ;
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_30 = ( unsigned long ) V_135 | V_7 ;
for ( V_48 = 0 ; V_48 < 2048 ; V_48 ++ , V_127 += 1UL << 20 ) {
if ( ! ( V_135 [ V_48 ] & V_109 ) )
continue;
V_132 = ( unsigned long * ) ( V_135 [ V_48 ] & V_91 ) ;
V_135 [ V_48 ] = V_8 ;
F_117 ( V_57 , V_127 , V_132 ) ;
V_3 = F_119 ( F_11 ( V_132 ) >> V_126 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_31 ( V_3 ) ;
}
}
static void F_121 ( struct V_1 * V_57 , unsigned long V_127 )
{
unsigned long V_136 , * V_137 , * V_135 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_137 = F_97 ( V_57 , V_127 , 2 ) ;
if ( ! V_137 || ! ( * V_137 & V_91 ) )
return;
F_95 ( V_57 , V_127 , V_127 + ( 1UL << 31 ) - 1 ) ;
V_136 = ( unsigned long ) ( V_137 - ( ( V_127 >> 31 ) & 0x7ff ) ) ;
F_114 ( V_136 | V_9 , V_127 ) ;
V_135 = ( unsigned long * ) ( * V_137 & V_91 ) ;
* V_137 = V_10 ;
F_120 ( V_57 , V_127 , V_135 ) ;
V_3 = F_119 ( F_11 ( V_135 ) >> V_126 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
static void F_122 ( struct V_1 * V_57 , unsigned long V_127 ,
unsigned long * V_138 )
{
unsigned long V_30 , * V_135 ;
struct V_3 * V_3 ;
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_30 = ( unsigned long ) V_138 | V_9 ;
for ( V_48 = 0 ; V_48 < 2048 ; V_48 ++ , V_127 += 1UL << 31 ) {
if ( ! ( V_138 [ V_48 ] & V_91 ) )
continue;
V_135 = ( unsigned long * ) ( V_138 [ V_48 ] & V_91 ) ;
V_138 [ V_48 ] = V_10 ;
F_120 ( V_57 , V_127 , V_135 ) ;
V_3 = F_119 ( F_11 ( V_135 ) >> V_126 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
}
static void F_123 ( struct V_1 * V_57 , unsigned long V_127 )
{
unsigned long V_139 , * V_140 , * V_138 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_140 = F_97 ( V_57 , V_127 , 3 ) ;
if ( ! V_140 || ! ( * V_140 & V_91 ) )
return;
F_95 ( V_57 , V_127 , V_127 + ( 1UL << 42 ) - 1 ) ;
V_139 = ( unsigned long ) ( V_140 - ( ( V_127 >> 42 ) & 0x7ff ) ) ;
F_114 ( V_139 | V_11 , V_127 ) ;
V_138 = ( unsigned long * ) ( * V_140 & V_91 ) ;
* V_140 = V_12 ;
F_122 ( V_57 , V_127 , V_138 ) ;
V_3 = F_119 ( F_11 ( V_138 ) >> V_126 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
static void F_124 ( struct V_1 * V_57 , unsigned long V_127 ,
unsigned long * V_141 )
{
unsigned long V_30 , * V_138 ;
struct V_3 * V_3 ;
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_30 = ( unsigned long ) V_141 | V_11 ;
for ( V_48 = 0 ; V_48 < 2048 ; V_48 ++ , V_127 += 1UL << 42 ) {
if ( ! ( V_141 [ V_48 ] & V_91 ) )
continue;
V_138 = ( unsigned long * ) ( V_141 [ V_48 ] & V_91 ) ;
V_141 [ V_48 ] = V_12 ;
F_122 ( V_57 , V_127 , V_138 ) ;
V_3 = F_119 ( F_11 ( V_138 ) >> V_126 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
}
static void F_125 ( struct V_1 * V_57 , unsigned long V_127 )
{
unsigned long V_142 , * V_143 , * V_141 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_143 = F_97 ( V_57 , V_127 , 4 ) ;
if ( ! V_143 || ! ( * V_143 & V_91 ) )
return;
F_95 ( V_57 , V_127 , V_127 + ( 1UL << 53 ) - 1 ) ;
V_142 = ( unsigned long ) ( V_143 - ( ( V_127 >> 53 ) & 0x7ff ) ) ;
F_114 ( V_142 | V_13 , V_127 ) ;
V_141 = ( unsigned long * ) ( * V_143 & V_91 ) ;
* V_143 = V_14 ;
F_124 ( V_57 , V_127 , V_141 ) ;
V_3 = F_119 ( F_11 ( V_141 ) >> V_126 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
static void F_126 ( struct V_1 * V_57 , unsigned long V_127 ,
unsigned long * V_144 )
{
unsigned long V_30 , * V_141 ;
struct V_3 * V_3 ;
int V_48 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_30 = ( unsigned long ) V_144 | V_13 ;
for ( V_48 = 0 ; V_48 < 2048 ; V_48 ++ , V_127 += 1UL << 53 ) {
if ( ! ( V_144 [ V_48 ] & V_91 ) )
continue;
V_141 = ( unsigned long * ) ( V_144 [ V_48 ] & V_91 ) ;
F_124 ( V_57 , V_127 , V_141 ) ;
F_114 ( V_30 , V_127 ) ;
V_144 [ V_48 ] = V_14 ;
V_3 = F_119 ( F_11 ( V_141 ) >> V_126 ) ;
F_38 ( & V_3 -> V_29 ) ;
F_30 ( V_3 , 2 ) ;
}
}
static void F_127 ( struct V_1 * V_57 )
{
unsigned long * V_4 ;
F_49 ( ! F_28 ( V_57 ) ) ;
if ( V_57 -> V_55 )
return;
V_57 -> V_55 = 1 ;
F_95 ( V_57 , 0 , - 1UL ) ;
F_19 ( V_57 ) ;
V_4 = ( unsigned long * ) ( V_57 -> V_30 & V_145 ) ;
switch ( V_57 -> V_30 & V_90 ) {
case V_13 :
F_126 ( V_57 , 0 , V_4 ) ;
break;
case V_11 :
F_124 ( V_57 , 0 , V_4 ) ;
break;
case V_9 :
F_122 ( V_57 , 0 , V_4 ) ;
break;
case V_7 :
F_120 ( V_57 , 0 , V_4 ) ;
break;
}
}
static struct V_1 * F_128 ( struct V_1 * V_56 , unsigned long V_30 ,
int V_146 )
{
struct V_1 * V_57 ;
F_96 (sg, &parent->children, list) {
if ( V_57 -> V_147 != V_30 || V_57 -> V_146 != V_146 ||
V_57 -> V_55 )
continue;
if ( ! V_57 -> V_148 )
return F_129 ( - V_115 ) ;
F_34 ( & V_57 -> V_26 ) ;
return V_57 ;
}
return NULL ;
}
int F_130 ( struct V_1 * V_57 , unsigned long V_30 , int V_146 )
{
if ( V_57 -> V_55 )
return 0 ;
return V_57 -> V_147 == V_30 && V_57 -> V_146 == V_146 ;
}
struct V_1 * F_131 ( struct V_1 * V_56 , unsigned long V_30 ,
int V_146 )
{
struct V_1 * V_57 , * V_61 ;
unsigned long V_2 ;
int V_84 ;
F_49 ( F_28 ( V_56 ) ) ;
F_14 ( & V_56 -> V_25 ) ;
V_57 = F_128 ( V_56 , V_30 , V_146 ) ;
F_18 ( & V_56 -> V_25 ) ;
if ( V_57 )
return V_57 ;
V_2 = - 1UL >> ( 33 - ( ( ( V_30 & V_90 ) >> 2 ) * 11 ) ) ;
if ( V_30 & V_149 )
V_2 = - 1UL ;
V_61 = F_1 ( V_2 ) ;
if ( ! V_61 )
return F_129 ( - V_62 ) ;
V_61 -> V_35 = V_56 -> V_35 ;
V_61 -> V_56 = F_33 ( V_56 ) ;
V_61 -> V_147 = V_30 ;
V_61 -> V_146 = V_146 ;
V_61 -> V_148 = false ;
F_14 ( & V_56 -> V_25 ) ;
V_57 = F_128 ( V_56 , V_30 , V_146 ) ;
if ( V_57 ) {
F_18 ( & V_56 -> V_25 ) ;
F_27 ( V_61 ) ;
return V_57 ;
}
if ( V_30 & V_149 ) {
F_96 (sg, &parent->children, list) {
if ( V_57 -> V_147 & V_149 ) {
F_14 ( & V_57 -> V_24 ) ;
F_127 ( V_57 ) ;
F_18 ( & V_57 -> V_24 ) ;
F_38 ( & V_57 -> V_39 ) ;
F_32 ( V_57 ) ;
break;
}
}
}
F_6 ( & V_61 -> V_26 , 2 ) ;
F_8 ( & V_61 -> V_39 , & V_56 -> V_18 ) ;
if ( V_30 & V_149 ) {
V_61 -> V_148 = true ;
F_18 ( & V_56 -> V_25 ) ;
return V_61 ;
}
F_18 ( & V_56 -> V_25 ) ;
F_59 ( & V_56 -> V_35 -> V_79 ) ;
V_84 = F_103 ( V_56 , V_30 & V_145 ,
( ( V_30 & V_31 ) + 1 ) * 4096 ,
V_119 , V_129 ) ;
F_60 ( & V_56 -> V_35 -> V_79 ) ;
F_14 ( & V_56 -> V_25 ) ;
V_61 -> V_148 = true ;
if ( V_84 ) {
F_38 ( & V_61 -> V_39 ) ;
F_27 ( V_61 ) ;
V_61 = F_129 ( V_84 ) ;
}
F_18 ( & V_56 -> V_25 ) ;
return V_61 ;
}
int F_132 ( struct V_1 * V_57 , unsigned long V_150 , unsigned long V_141 ,
int V_151 )
{
unsigned long V_127 , V_152 , V_67 , V_76 ;
unsigned long * V_153 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_28 = V_141 & V_91 ;
if ( V_151 )
V_3 -> V_28 |= V_154 ;
V_153 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_97 ( V_57 , V_150 , 4 ) ;
if ( ! V_4 ) {
V_84 = - V_115 ;
goto V_27;
}
if ( ! ( * V_4 & V_63 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_91 ) {
V_84 = - V_115 ;
goto V_27;
}
F_10 ( V_153 , V_12 ) ;
* V_4 = ( unsigned long ) V_153 | V_64 |
V_155 | V_63 ;
if ( V_57 -> V_146 >= 1 )
* V_4 |= ( V_141 & V_156 ) ;
F_8 ( & V_3 -> V_29 , & V_57 -> V_17 ) ;
if ( V_151 ) {
* V_4 &= ~ V_63 ;
F_18 ( & V_57 -> V_24 ) ;
return 0 ;
}
F_18 ( & V_57 -> V_24 ) ;
V_127 = ( V_150 & 0xffe0000000000000UL ) | V_157 ;
V_152 = V_141 & V_91 ;
V_67 = ( ( V_141 & V_158 ) >> 6 ) * 4096 ;
V_76 = ( ( V_141 & V_64 ) + 1 ) * 4096 - V_67 ;
V_84 = F_113 ( V_57 , V_127 , V_152 + V_67 , V_76 , V_119 ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_97 ( V_57 , V_150 , 4 ) ;
if ( ! V_4 || ( * V_4 & V_91 ) !=
( unsigned long ) V_153 )
V_84 = - V_115 ;
else
* V_4 &= ~ V_63 ;
} else {
F_125 ( V_57 , V_127 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
V_27:
F_18 ( & V_57 -> V_24 ) ;
F_30 ( V_3 , 2 ) ;
return V_84 ;
}
int F_133 ( struct V_1 * V_57 , unsigned long V_150 , unsigned long V_138 ,
int V_151 )
{
unsigned long V_127 , V_152 , V_67 , V_76 ;
unsigned long * V_159 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_28 = V_138 & V_91 ;
if ( V_151 )
V_3 -> V_28 |= V_154 ;
V_159 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_97 ( V_57 , V_150 , 3 ) ;
if ( ! V_4 ) {
V_84 = - V_115 ;
goto V_27;
}
if ( ! ( * V_4 & V_63 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_91 ) {
V_84 = - V_115 ;
}
F_10 ( V_159 , V_10 ) ;
* V_4 = ( unsigned long ) V_159 | V_64 |
V_160 | V_63 ;
if ( V_57 -> V_146 >= 1 )
* V_4 |= ( V_138 & V_156 ) ;
F_8 ( & V_3 -> V_29 , & V_57 -> V_17 ) ;
if ( V_151 ) {
* V_4 &= ~ V_63 ;
F_18 ( & V_57 -> V_24 ) ;
return 0 ;
}
F_18 ( & V_57 -> V_24 ) ;
V_127 = ( V_150 & 0xfffffc0000000000UL ) | V_161 ;
V_152 = V_138 & V_91 ;
V_67 = ( ( V_138 & V_158 ) >> 6 ) * 4096 ;
V_76 = ( ( V_138 & V_64 ) + 1 ) * 4096 - V_67 ;
V_84 = F_113 ( V_57 , V_127 , V_152 + V_67 , V_76 , V_119 ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_97 ( V_57 , V_150 , 3 ) ;
if ( ! V_4 || ( * V_4 & V_91 ) !=
( unsigned long ) V_159 )
V_84 = - V_115 ;
else
* V_4 &= ~ V_63 ;
} else {
F_123 ( V_57 , V_127 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
V_27:
F_18 ( & V_57 -> V_24 ) ;
F_30 ( V_3 , 2 ) ;
return V_84 ;
}
int F_134 ( struct V_1 * V_57 , unsigned long V_150 , unsigned long V_135 ,
int V_151 )
{
unsigned long V_127 , V_152 , V_67 , V_76 ;
unsigned long * V_162 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) || ( V_135 & V_163 ) ) ;
V_3 = F_7 ( V_15 , 2 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_28 = V_135 & V_91 ;
if ( V_151 )
V_3 -> V_28 |= V_154 ;
V_162 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_97 ( V_57 , V_150 , 2 ) ;
if ( ! V_4 ) {
V_84 = - V_115 ;
goto V_27;
}
if ( ! ( * V_4 & V_63 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_91 ) {
V_84 = - V_115 ;
goto V_27;
}
F_10 ( V_162 , V_8 ) ;
* V_4 = ( unsigned long ) V_162 | V_64 |
V_164 | V_63 ;
if ( V_57 -> V_146 >= 1 )
* V_4 |= V_135 & V_156 ;
F_8 ( & V_3 -> V_29 , & V_57 -> V_17 ) ;
if ( V_151 ) {
* V_4 &= ~ V_63 ;
F_18 ( & V_57 -> V_24 ) ;
return 0 ;
}
F_18 ( & V_57 -> V_24 ) ;
V_127 = ( V_150 & 0xffffffff80000000UL ) | V_165 ;
V_152 = V_135 & V_91 ;
V_67 = ( ( V_135 & V_158 ) >> 6 ) * 4096 ;
V_76 = ( ( V_135 & V_64 ) + 1 ) * 4096 - V_67 ;
V_84 = F_113 ( V_57 , V_127 , V_152 + V_67 , V_76 , V_119 ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_97 ( V_57 , V_150 , 2 ) ;
if ( ! V_4 || ( * V_4 & V_91 ) !=
( unsigned long ) V_162 )
V_84 = - V_115 ;
else
* V_4 &= ~ V_63 ;
} else {
F_121 ( V_57 , V_127 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
V_27:
F_18 ( & V_57 -> V_24 ) ;
F_30 ( V_3 , 2 ) ;
return V_84 ;
}
int F_135 ( struct V_1 * V_57 , unsigned long V_150 ,
unsigned long * V_132 , int * V_166 ,
int * V_151 )
{
unsigned long * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_97 ( V_57 , V_150 , 1 ) ;
if ( V_4 && ! ( * V_4 & V_110 ) ) {
V_3 = F_119 ( * V_4 >> V_126 ) ;
* V_132 = V_3 -> V_28 & ~ V_154 ;
* V_166 = ! ! ( * V_4 & V_167 ) ;
* V_151 = ! ! ( V_3 -> V_28 & V_154 ) ;
V_84 = 0 ;
} else {
V_84 = - V_115 ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
}
int F_136 ( struct V_1 * V_57 , unsigned long V_150 , unsigned long V_132 ,
int V_151 )
{
unsigned long V_127 , V_152 ;
unsigned long * V_168 , * V_4 ;
struct V_3 * V_3 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) || ( V_132 & V_169 ) ) ;
V_3 = F_137 ( V_57 -> V_35 ) ;
if ( ! V_3 )
return - V_62 ;
V_3 -> V_28 = V_132 & V_109 ;
if ( V_151 )
V_3 -> V_28 |= V_154 ;
V_168 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_57 -> V_24 ) ;
V_4 = F_97 ( V_57 , V_150 , 1 ) ;
if ( ! V_4 ) {
V_84 = - V_115 ;
goto V_27;
}
if ( ! ( * V_4 & V_110 ) ) {
V_84 = 0 ;
goto V_27;
} else if ( * V_4 & V_109 ) {
V_84 = - V_115 ;
goto V_27;
}
* V_4 = ( unsigned long ) V_168 | V_170 |
( V_132 & V_167 ) | V_110 ;
F_8 ( & V_3 -> V_29 , & V_57 -> V_19 ) ;
if ( V_151 ) {
* V_4 &= ~ V_110 ;
F_18 ( & V_57 -> V_24 ) ;
return 0 ;
}
F_18 ( & V_57 -> V_24 ) ;
V_127 = ( V_150 & 0xfffffffffff00000UL ) | V_171 ;
V_152 = V_132 & V_109 & V_117 ;
V_84 = F_113 ( V_57 , V_127 , V_152 , V_116 , V_119 ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( ! V_84 ) {
V_4 = F_97 ( V_57 , V_150 , 1 ) ;
if ( ! V_4 || ( * V_4 & V_109 ) !=
( unsigned long ) V_168 )
V_84 = - V_115 ;
else
* V_4 &= ~ V_110 ;
} else {
F_118 ( V_57 , V_127 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
return V_84 ;
V_27:
F_18 ( & V_57 -> V_24 ) ;
F_31 ( V_3 ) ;
return V_84 ;
}
int F_138 ( struct V_1 * V_57 , unsigned long V_150 , T_6 V_123 )
{
struct V_1 * V_56 ;
struct V_50 * V_51 ;
unsigned long V_72 , V_128 ;
T_2 * V_85 ;
T_6 * V_172 , * V_173 ;
int V_111 ;
int V_84 ;
F_49 ( ! F_28 ( V_57 ) ) ;
V_56 = V_57 -> V_56 ;
V_111 = ( F_108 ( V_123 ) & V_174 ) ? V_119 : V_112 ;
V_51 = F_2 ( sizeof( * V_51 ) , V_15 ) ;
if ( ! V_51 )
return - V_62 ;
V_51 -> V_127 = ( V_150 & V_117 ) | V_175 ;
while ( 1 ) {
V_128 = F_108 ( V_123 ) & V_117 ;
V_72 = F_56 ( V_56 , V_128 ) ;
if ( F_82 ( V_72 ) ) {
V_84 = V_72 ;
break;
}
V_84 = F_77 ( V_15 ) ;
if ( V_84 )
break;
V_84 = - V_115 ;
V_172 = F_98 ( V_56 , V_128 , & V_85 ) ;
if ( V_172 ) {
F_14 ( & V_57 -> V_24 ) ;
V_173 = ( T_6 * ) F_97 ( V_57 , V_150 , 0 ) ;
if ( ! V_173 ) {
F_18 ( & V_57 -> V_24 ) ;
F_102 ( V_85 ) ;
F_80 () ;
break;
}
V_84 = F_139 ( V_57 -> V_35 , V_150 , V_172 , V_173 , V_123 ) ;
if ( V_84 > 0 ) {
F_109 ( V_57 , V_72 , V_51 ) ;
V_51 = NULL ;
V_84 = 0 ;
}
F_102 ( V_85 ) ;
F_18 ( & V_57 -> V_24 ) ;
}
F_80 () ;
if ( ! V_84 )
break;
V_84 = F_101 ( V_56 , V_128 , V_72 , V_111 ) ;
if ( V_84 )
break;
}
F_12 ( V_51 ) ;
return V_84 ;
}
static void F_140 ( struct V_1 * V_57 , unsigned long V_72 ,
unsigned long V_60 , T_6 * V_123 )
{
struct V_50 * V_51 , * V_52 , * V_53 ;
unsigned long V_105 , V_106 , V_114 , V_127 ;
F_49 ( ! F_28 ( V_57 ) ) ;
F_14 ( & V_57 -> V_24 ) ;
if ( V_57 -> V_55 ) {
F_18 ( & V_57 -> V_24 ) ;
return;
}
V_105 = V_57 -> V_147 & V_145 ;
V_106 = V_105 + ( ( V_57 -> V_147 & V_31 ) + 1 ) * 4096 ;
if ( ! ( V_57 -> V_147 & V_149 ) && V_60 >= V_105 &&
V_60 < V_106 ) {
F_127 ( V_57 ) ;
F_18 ( & V_57 -> V_24 ) ;
F_38 ( & V_57 -> V_39 ) ;
F_32 ( V_57 ) ;
return;
}
V_53 = F_24 ( & V_57 -> V_23 , V_72 >> 12 ) ;
F_26 (rmap, rnext, head) {
V_114 = V_51 -> V_127 & V_176 ;
V_127 = V_51 -> V_127 ^ V_114 ;
switch ( V_114 ) {
case V_157 :
F_125 ( V_57 , V_127 ) ;
break;
case V_161 :
F_123 ( V_57 , V_127 ) ;
break;
case V_165 :
F_121 ( V_57 , V_127 ) ;
break;
case V_171 :
F_118 ( V_57 , V_127 ) ;
break;
case V_175 :
F_115 ( V_57 , V_127 ) ;
break;
}
F_12 ( V_51 ) ;
}
F_18 ( & V_57 -> V_24 ) ;
}
void F_141 ( struct V_34 * V_35 , unsigned long V_72 ,
T_6 * V_123 , unsigned long V_114 )
{
unsigned long V_67 , V_60 = 0 ;
unsigned long * V_4 ;
struct V_1 * V_1 , * V_57 , * V_54 ;
V_67 = ( ( unsigned long ) V_123 ) & ( 255 * sizeof( T_6 ) ) ;
V_67 = V_67 * ( 4096 / sizeof( T_6 ) ) ;
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
if ( ! F_37 ( & V_1 -> V_18 ) && ( V_114 & V_129 ) ) {
F_14 ( & V_1 -> V_25 ) ;
F_29 (sg, next,
&gmap->children, list)
F_140 ( V_57 , V_72 , V_60 , V_123 ) ;
F_18 ( & V_1 -> V_25 ) ;
}
if ( V_114 & V_120 )
F_95 ( V_1 , V_60 , V_60 + V_116 - 1 ) ;
}
F_64 () ;
}
static inline void F_142 ( struct V_34 * V_35 )
{
#ifdef F_143
struct V_99 * V_100 ;
unsigned long V_177 ;
for ( V_100 = V_35 -> V_178 ; V_100 != NULL ; V_100 = V_100 -> V_179 ) {
for ( V_177 = V_100 -> V_180 ;
V_177 < V_100 -> V_181 ;
V_177 += V_116 )
F_144 ( V_100 , V_177 , V_182 ) ;
V_100 -> V_183 &= ~ V_184 ;
V_100 -> V_183 |= V_185 ;
}
V_35 -> V_186 |= V_185 ;
#endif
}
int F_145 ( void )
{
struct V_34 * V_35 = V_96 -> V_35 ;
if ( F_146 ( V_35 ) )
return 0 ;
if ( ! F_147 ( V_35 ) )
return - V_78 ;
F_52 ( & V_35 -> V_79 ) ;
V_35 -> V_37 . V_187 = 1 ;
F_142 ( V_35 ) ;
F_53 ( & V_35 -> V_79 ) ;
return 0 ;
}
static int F_148 ( T_6 * V_123 , unsigned long V_177 ,
unsigned long V_54 , struct V_188 * V_189 )
{
if ( F_149 ( F_150 ( * V_123 ) ) )
F_151 ( V_189 -> V_35 , V_177 , V_123 , F_152 ( V_131 ) ) ;
F_153 ( V_189 -> V_35 , V_177 , V_123 ) ;
return 0 ;
}
int F_154 ( void )
{
struct V_188 V_189 = { . V_190 = F_148 } ;
struct V_34 * V_35 = V_96 -> V_35 ;
struct V_99 * V_100 ;
int V_84 = 0 ;
F_52 ( & V_35 -> V_79 ) ;
if ( F_155 ( V_35 ) )
goto V_95;
V_35 -> V_37 . V_191 = 1 ;
for ( V_100 = V_35 -> V_178 ; V_100 ; V_100 = V_100 -> V_179 ) {
if ( F_156 ( V_100 , V_100 -> V_180 , V_100 -> V_181 ,
V_192 , & V_100 -> V_183 ) ) {
V_35 -> V_37 . V_191 = 0 ;
V_84 = - V_62 ;
goto V_95;
}
}
V_35 -> V_186 &= ~ V_193 ;
V_189 . V_35 = V_35 ;
F_157 ( 0 , V_194 , & V_189 ) ;
V_95:
F_53 ( & V_35 -> V_79 ) ;
return V_84 ;
}
static int F_158 ( T_6 * V_123 , unsigned long V_177 ,
unsigned long V_54 , struct V_188 * V_189 )
{
F_87 ( V_189 -> V_35 , V_177 , V_123 , 1 ) ;
return 0 ;
}
void F_159 ( struct V_34 * V_35 )
{
struct V_188 V_189 = { . V_190 = F_158 } ;
F_52 ( & V_35 -> V_79 ) ;
V_189 . V_35 = V_35 ;
F_157 ( 0 , V_194 , & V_189 ) ;
F_53 ( & V_35 -> V_79 ) ;
}
