static struct V_1 * F_1 ( unsigned long V_2 )
{
struct V_1 * V_1 ;
struct V_3 * V_3 ;
unsigned long * V_4 ;
unsigned long V_5 , V_6 ;
if ( V_2 < V_7 ) {
V_2 = V_7 - 1 ;
V_6 = V_8 ;
V_5 = V_9 ;
} else if ( V_2 < V_10 ) {
V_2 = V_10 - 1 ;
V_6 = V_11 ;
V_5 = V_12 ;
} else if ( V_2 < V_13 ) {
V_2 = V_13 - 1 ;
V_6 = V_14 ;
V_5 = V_15 ;
} else {
V_2 = - 1UL ;
V_6 = V_16 ;
V_5 = V_17 ;
}
V_1 = F_2 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_1 )
goto V_19;
F_3 ( & V_1 -> V_20 ) ;
F_3 ( & V_1 -> V_21 ) ;
F_3 ( & V_1 -> V_22 ) ;
F_4 ( & V_1 -> V_23 , V_18 ) ;
F_4 ( & V_1 -> V_24 , V_25 ) ;
F_4 ( & V_1 -> V_26 , V_25 ) ;
F_5 ( & V_1 -> V_27 ) ;
F_5 ( & V_1 -> V_28 ) ;
F_6 ( & V_1 -> V_29 , 1 ) ;
V_3 = F_7 ( V_18 , V_30 ) ;
if ( ! V_3 )
goto V_31;
V_3 -> V_32 = 0 ;
F_8 ( & V_3 -> V_33 , & V_1 -> V_20 ) ;
V_4 = ( unsigned long * ) F_9 ( V_3 ) ;
F_10 ( V_4 , V_5 ) ;
V_1 -> V_4 = V_4 ;
V_1 -> V_34 = V_6 | V_35 |
V_36 | F_11 ( V_4 ) ;
V_1 -> V_37 = V_2 ;
return V_1 ;
V_31:
F_12 ( V_1 ) ;
V_19:
return NULL ;
}
struct V_1 * F_13 ( struct V_38 * V_39 , unsigned long V_2 )
{
struct V_1 * V_1 ;
unsigned long V_40 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_39 = V_39 ;
F_14 ( & V_39 -> V_41 . V_42 ) ;
F_15 ( & V_1 -> V_43 , & V_39 -> V_41 . V_44 ) ;
if ( F_16 ( & V_39 -> V_41 . V_44 ) )
V_40 = V_1 -> V_34 ;
else
V_40 = - 1UL ;
F_17 ( V_39 -> V_41 . V_40 , V_40 ) ;
F_18 ( & V_39 -> V_41 . V_42 ) ;
return V_1 ;
}
static void F_19 ( struct V_1 * V_1 )
{
if ( V_45 )
F_20 ( V_1 -> V_34 ) ;
else
F_21 () ;
}
static void F_22 ( struct V_46 * V_47 )
{
struct V_48 V_49 ;
unsigned long V_50 [ 16 ] ;
unsigned long V_32 ;
void T_1 * * V_51 ;
int V_52 , V_53 ;
V_32 = 0 ;
do {
V_53 = 0 ;
F_23 (slot, root, &iter, index) {
V_50 [ V_53 ] = V_49 . V_32 ;
if ( ++ V_53 == 16 )
break;
}
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_32 = V_50 [ V_52 ] ;
F_24 ( V_47 , V_32 ) ;
}
} while ( V_53 > 0 );
}
static void F_25 ( struct V_46 * V_47 )
{
struct V_54 * V_55 , * V_56 , * V_57 ;
struct V_48 V_49 ;
unsigned long V_50 [ 16 ] ;
unsigned long V_32 ;
void T_1 * * V_51 ;
int V_52 , V_53 ;
V_32 = 0 ;
do {
V_53 = 0 ;
F_23 (slot, root, &iter, index) {
V_50 [ V_53 ] = V_49 . V_32 ;
if ( ++ V_53 == 16 )
break;
}
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_32 = V_50 [ V_52 ] ;
V_57 = F_24 ( V_47 , V_32 ) ;
F_26 (rmap, rnext, head)
F_12 ( V_55 ) ;
}
} while ( V_53 > 0 );
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_3 * V_3 , * V_58 ;
if ( ! ( F_28 ( V_1 ) && V_1 -> V_59 ) )
F_19 ( V_1 ) ;
F_29 (page, next, &gmap->crst_list, lru)
F_30 ( V_3 , V_30 ) ;
F_22 ( & V_1 -> V_23 ) ;
F_22 ( & V_1 -> V_24 ) ;
if ( F_28 ( V_1 ) ) {
F_29 (page, next, &gmap->pt_list, lru)
F_31 ( V_3 ) ;
F_25 ( & V_1 -> V_26 ) ;
F_32 ( V_1 -> V_60 ) ;
}
F_12 ( V_1 ) ;
}
struct V_1 * F_33 ( struct V_1 * V_1 )
{
F_34 ( & V_1 -> V_29 ) ;
return V_1 ;
}
void F_32 ( struct V_1 * V_1 )
{
if ( F_35 ( & V_1 -> V_29 ) == 0 )
F_27 ( V_1 ) ;
}
void F_36 ( struct V_1 * V_1 )
{
struct V_1 * V_61 , * V_58 ;
unsigned long V_40 ;
if ( ! F_37 ( & V_1 -> V_21 ) ) {
F_14 ( & V_1 -> V_28 ) ;
F_29 (sg, next, &gmap->children, list) {
F_38 ( & V_61 -> V_43 ) ;
F_32 ( V_61 ) ;
}
F_18 ( & V_1 -> V_28 ) ;
}
F_14 ( & V_1 -> V_39 -> V_41 . V_42 ) ;
F_39 ( & V_1 -> V_43 ) ;
if ( F_37 ( & V_1 -> V_39 -> V_41 . V_44 ) )
V_40 = 0 ;
else if ( F_16 ( & V_1 -> V_39 -> V_41 . V_44 ) )
V_40 = F_40 ( & V_1 -> V_39 -> V_41 . V_44 ,
struct V_1 , V_43 ) -> V_34 ;
else
V_40 = - 1UL ;
F_17 ( V_1 -> V_39 -> V_41 . V_40 , V_40 ) ;
F_18 ( & V_1 -> V_39 -> V_41 . V_42 ) ;
F_41 () ;
F_32 ( V_1 ) ;
}
void F_42 ( struct V_1 * V_1 )
{
V_62 . V_1 = ( unsigned long ) V_1 ;
}
void F_43 ( struct V_1 * V_1 )
{
V_62 . V_1 = 0UL ;
}
struct V_1 * F_44 ( void )
{
return (struct V_1 * ) V_62 . V_1 ;
}
static int F_45 ( struct V_1 * V_1 , unsigned long * V_4 ,
unsigned long V_63 , unsigned long V_64 )
{
struct V_3 * V_3 ;
unsigned long * V_65 ;
V_3 = F_7 ( V_18 , V_30 ) ;
if ( ! V_3 )
return - V_66 ;
V_65 = ( unsigned long * ) F_9 ( V_3 ) ;
F_10 ( V_65 , V_63 ) ;
F_14 ( & V_1 -> V_27 ) ;
if ( * V_4 & V_67 ) {
F_8 ( & V_3 -> V_33 , & V_1 -> V_20 ) ;
* V_4 = ( unsigned long ) V_65 | V_68 |
( * V_4 & V_69 ) ;
V_3 -> V_32 = V_64 ;
V_3 = NULL ;
}
F_18 ( & V_1 -> V_27 ) ;
if ( V_3 )
F_30 ( V_3 , V_30 ) ;
return 0 ;
}
static unsigned long F_46 ( unsigned long * V_70 )
{
struct V_3 * V_3 ;
unsigned long V_71 , V_72 ;
V_71 = ( unsigned long ) V_70 / sizeof( unsigned long ) ;
V_71 = ( V_71 & ( V_73 - 1 ) ) * V_74 ;
V_72 = ~ ( V_73 * sizeof( V_75 ) - 1 ) ;
V_3 = F_47 ( ( void * ) ( ( unsigned long ) V_70 & V_72 ) ) ;
return V_3 -> V_32 + V_71 ;
}
static int F_48 ( struct V_1 * V_1 , unsigned long V_76 )
{
unsigned long * V_70 ;
int V_77 = 0 ;
F_49 ( F_28 ( V_1 ) ) ;
F_14 ( & V_1 -> V_27 ) ;
V_70 = F_24 ( & V_1 -> V_24 , V_76 >> V_78 ) ;
if ( V_70 ) {
V_77 = ( * V_70 != V_9 ) ;
* V_70 = V_9 ;
}
F_18 ( & V_1 -> V_27 ) ;
return V_77 ;
}
static int F_50 ( struct V_1 * V_1 , unsigned long V_64 )
{
unsigned long V_76 ;
V_76 = ( unsigned long ) F_24 ( & V_1 -> V_23 ,
V_64 >> V_78 ) ;
return V_76 ? F_48 ( V_1 , V_76 ) : 0 ;
}
int F_51 ( struct V_1 * V_1 , unsigned long V_79 , unsigned long V_80 )
{
unsigned long V_81 ;
int V_77 ;
F_49 ( F_28 ( V_1 ) ) ;
if ( ( V_79 | V_80 ) & ( V_74 - 1 ) )
return - V_82 ;
if ( V_80 == 0 || V_79 + V_80 < V_79 )
return - V_82 ;
V_77 = 0 ;
F_52 ( & V_1 -> V_39 -> V_83 ) ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 += V_74 )
V_77 |= F_50 ( V_1 , V_79 + V_81 ) ;
F_53 ( & V_1 -> V_39 -> V_83 ) ;
if ( V_77 )
F_19 ( V_1 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_1 , unsigned long V_84 ,
unsigned long V_79 , unsigned long V_80 )
{
unsigned long V_81 ;
int V_77 ;
F_49 ( F_28 ( V_1 ) ) ;
if ( ( V_84 | V_79 | V_80 ) & ( V_74 - 1 ) )
return - V_82 ;
if ( V_80 == 0 || V_84 + V_80 < V_84 || V_79 + V_80 < V_79 ||
V_84 + V_80 - 1 > V_85 || V_79 + V_80 - 1 > V_1 -> V_37 )
return - V_82 ;
V_77 = 0 ;
F_52 ( & V_1 -> V_39 -> V_83 ) ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 += V_74 ) {
V_77 |= F_50 ( V_1 , V_79 + V_81 ) ;
if ( F_55 ( & V_1 -> V_23 ,
( V_79 + V_81 ) >> V_78 ,
( void * ) V_84 + V_81 ) )
break;
}
F_53 ( & V_1 -> V_39 -> V_83 ) ;
if ( V_77 )
F_19 ( V_1 ) ;
if ( V_81 >= V_80 )
return 0 ;
F_51 ( V_1 , V_79 , V_80 ) ;
return - V_66 ;
}
unsigned long F_56 ( struct V_1 * V_1 , unsigned long V_64 )
{
unsigned long V_76 ;
V_76 = ( unsigned long )
F_57 ( & V_1 -> V_23 , V_64 >> V_78 ) ;
return V_76 ? ( V_76 | ( V_64 & ~ V_86 ) ) : - V_87 ;
}
unsigned long F_58 ( struct V_1 * V_1 , unsigned long V_64 )
{
unsigned long V_88 ;
F_59 ( & V_1 -> V_39 -> V_83 ) ;
V_88 = F_56 ( V_1 , V_64 ) ;
F_60 ( & V_1 -> V_39 -> V_83 ) ;
return V_88 ;
}
void F_61 ( struct V_38 * V_39 , unsigned long * V_4 ,
unsigned long V_76 )
{
struct V_1 * V_1 ;
int V_77 ;
F_62 () ;
F_63 (gmap, &mm->context.gmap_list, list) {
V_77 = F_48 ( V_1 , V_76 ) ;
if ( V_77 )
F_19 ( V_1 ) ;
}
F_64 () ;
}
int F_65 ( struct V_1 * V_1 , unsigned long V_64 , unsigned long V_76 )
{
struct V_38 * V_39 ;
unsigned long * V_4 ;
T_2 * V_89 ;
T_3 * V_90 ;
T_4 * V_91 ;
T_5 * V_92 ;
V_75 * V_93 ;
int V_88 ;
F_49 ( F_28 ( V_1 ) ) ;
V_4 = V_1 -> V_4 ;
if ( ( V_1 -> V_34 & V_94 ) >= V_16 ) {
V_4 += ( V_64 & V_95 ) >> V_96 ;
if ( ( * V_4 & V_67 ) &&
F_45 ( V_1 , V_4 , V_15 ,
V_64 & V_97 ) )
return - V_66 ;
V_4 = ( unsigned long * ) ( * V_4 & V_98 ) ;
}
if ( ( V_1 -> V_34 & V_94 ) >= V_14 ) {
V_4 += ( V_64 & V_99 ) >> V_100 ;
if ( ( * V_4 & V_67 ) &&
F_45 ( V_1 , V_4 , V_12 ,
V_64 & V_101 ) )
return - V_66 ;
V_4 = ( unsigned long * ) ( * V_4 & V_98 ) ;
}
if ( ( V_1 -> V_34 & V_94 ) >= V_11 ) {
V_4 += ( V_64 & V_102 ) >> V_103 ;
if ( ( * V_4 & V_67 ) &&
F_45 ( V_1 , V_4 , V_9 ,
V_64 & V_104 ) )
return - V_66 ;
V_4 = ( unsigned long * ) ( * V_4 & V_98 ) ;
}
V_4 += ( V_64 & V_105 ) >> V_106 ;
V_39 = V_1 -> V_39 ;
V_90 = F_66 ( V_39 , V_76 ) ;
F_67 ( F_68 ( * V_90 ) ) ;
V_91 = F_69 ( V_90 , V_76 ) ;
F_67 ( F_70 ( * V_91 ) ) ;
V_92 = F_71 ( V_91 , V_76 ) ;
F_67 ( F_72 ( * V_92 ) ) ;
if ( F_73 ( * V_92 ) )
return - V_87 ;
V_93 = F_74 ( V_92 , V_76 ) ;
F_67 ( F_75 ( * V_93 ) ) ;
if ( F_76 ( * V_93 ) )
return - V_87 ;
V_88 = F_77 ( V_18 ) ;
if ( V_88 )
return V_88 ;
V_89 = F_78 ( V_39 , V_93 ) ;
F_14 ( & V_1 -> V_27 ) ;
if ( * V_4 == V_9 ) {
V_88 = F_55 ( & V_1 -> V_24 ,
V_76 >> V_78 , V_4 ) ;
if ( ! V_88 )
* V_4 = F_79 ( * V_93 ) ;
} else
V_88 = 0 ;
F_18 ( & V_1 -> V_27 ) ;
F_18 ( V_89 ) ;
F_80 () ;
return V_88 ;
}
int F_81 ( struct V_1 * V_1 , unsigned long V_64 ,
unsigned int V_107 )
{
unsigned long V_76 ;
int V_88 ;
bool V_108 ;
F_59 ( & V_1 -> V_39 -> V_83 ) ;
V_109:
V_108 = false ;
V_76 = F_56 ( V_1 , V_64 ) ;
if ( F_82 ( V_76 ) ) {
V_88 = V_76 ;
goto V_110;
}
if ( F_83 ( V_111 , V_1 -> V_39 , V_76 , V_107 ,
& V_108 ) ) {
V_88 = - V_87 ;
goto V_110;
}
if ( V_108 )
goto V_109;
V_88 = F_65 ( V_1 , V_64 , V_76 ) ;
V_110:
F_60 ( & V_1 -> V_39 -> V_83 ) ;
return V_88 ;
}
void F_84 ( struct V_1 * V_1 , unsigned long V_64 )
{
unsigned long V_76 ;
T_2 * V_89 ;
T_6 * V_112 ;
V_76 = ( unsigned long ) F_57 ( & V_1 -> V_23 ,
V_64 >> V_78 ) ;
if ( V_76 ) {
V_76 |= V_64 & ~ V_86 ;
V_112 = F_85 ( V_1 -> V_39 , V_76 , & V_89 ) ;
if ( F_86 ( V_112 ) )
F_87 ( V_1 -> V_39 , V_76 , V_112 , 0 ) ;
F_88 ( V_112 , V_89 ) ;
}
}
void F_89 ( struct V_1 * V_1 , unsigned long V_84 , unsigned long V_79 )
{
unsigned long V_64 , V_76 , V_113 ;
struct V_114 * V_115 ;
F_59 ( & V_1 -> V_39 -> V_83 ) ;
for ( V_64 = V_84 ; V_64 < V_79 ;
V_64 = ( V_64 + V_74 ) & V_86 ) {
V_76 = ( unsigned long )
F_57 ( & V_1 -> V_23 ,
V_64 >> V_78 ) ;
if ( ! V_76 )
continue;
V_76 |= V_64 & ~ V_86 ;
V_115 = F_90 ( V_1 -> V_39 , V_76 ) ;
V_113 = F_91 ( V_79 - V_64 , V_74 - ( V_64 & ~ V_86 ) ) ;
F_92 ( V_115 , V_76 , V_113 ) ;
}
F_60 ( & V_1 -> V_39 -> V_83 ) ;
}
void F_93 ( struct V_116 * V_117 )
{
F_14 ( & V_118 ) ;
F_15 ( & V_117 -> V_43 , & V_119 ) ;
F_18 ( & V_118 ) ;
}
void F_94 ( struct V_116 * V_117 )
{
F_14 ( & V_118 ) ;
F_39 ( & V_117 -> V_43 ) ;
F_18 ( & V_118 ) ;
F_41 () ;
}
static void F_95 ( struct V_1 * V_1 , unsigned long V_120 ,
unsigned long V_121 )
{
struct V_116 * V_117 ;
F_96 (nb, &gmap_notifier_list, list)
V_117 -> V_122 ( V_1 , V_120 , V_121 ) ;
}
static inline unsigned long * F_97 ( struct V_1 * V_1 ,
unsigned long V_64 , int V_123 )
{
unsigned long * V_4 ;
if ( ( V_1 -> V_34 & V_94 ) + 4 < ( V_123 * 4 ) )
return NULL ;
if ( F_28 ( V_1 ) && V_1 -> V_59 )
return NULL ;
if ( V_64 & ( - 1UL << ( 31 + ( ( V_1 -> V_34 & V_94 ) >> 2 ) * 11 ) ) )
return NULL ;
V_4 = V_1 -> V_4 ;
switch ( V_1 -> V_34 & V_94 ) {
case V_16 :
V_4 += ( V_64 & V_95 ) >> V_96 ;
if ( V_123 == 4 )
break;
if ( * V_4 & V_67 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_98 ) ;
case V_14 :
V_4 += ( V_64 & V_99 ) >> V_100 ;
if ( V_123 == 3 )
break;
if ( * V_4 & V_67 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_98 ) ;
case V_11 :
V_4 += ( V_64 & V_102 ) >> V_103 ;
if ( V_123 == 2 )
break;
if ( * V_4 & V_67 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_98 ) ;
case V_8 :
V_4 += ( V_64 & V_105 ) >> V_106 ;
if ( V_123 == 1 )
break;
if ( * V_4 & V_67 )
return NULL ;
V_4 = ( unsigned long * ) ( * V_4 & V_124 ) ;
V_4 += ( V_64 & V_125 ) >> V_126 ;
}
return V_4 ;
}
static T_6 * F_98 ( struct V_1 * V_1 , unsigned long V_64 ,
T_2 * * V_89 )
{
unsigned long * V_4 ;
if ( F_28 ( V_1 ) )
F_14 ( & V_1 -> V_27 ) ;
V_4 = F_97 ( V_1 , V_64 , 1 ) ;
if ( ! V_4 || * V_4 & V_127 ) {
if ( F_28 ( V_1 ) )
F_18 ( & V_1 -> V_27 ) ;
return NULL ;
}
if ( F_28 ( V_1 ) ) {
* V_89 = & V_1 -> V_27 ;
return F_99 ( ( V_75 * ) V_4 , V_64 ) ;
}
return F_100 ( V_1 -> V_39 , ( V_75 * ) V_4 , V_64 , V_89 ) ;
}
static int F_101 ( struct V_1 * V_1 , unsigned long V_64 ,
unsigned long V_76 , int V_128 )
{
struct V_38 * V_39 = V_1 -> V_39 ;
unsigned int V_107 ;
bool V_108 = false ;
F_49 ( F_28 ( V_1 ) ) ;
V_107 = ( V_128 == V_129 ) ? V_130 : 0 ;
if ( F_83 ( V_111 , V_39 , V_76 , V_107 , & V_108 ) )
return - V_87 ;
if ( V_108 )
return 0 ;
return F_65 ( V_1 , V_64 , V_76 ) ;
}
static void F_102 ( T_2 * V_89 )
{
F_18 ( V_89 ) ;
}
static int F_103 ( struct V_1 * V_1 , unsigned long V_64 ,
unsigned long V_80 , int V_128 , unsigned long V_131 )
{
unsigned long V_76 ;
T_2 * V_89 ;
T_6 * V_112 ;
int V_88 ;
while ( V_80 ) {
V_88 = - V_132 ;
V_112 = F_98 ( V_1 , V_64 , & V_89 ) ;
if ( V_112 ) {
V_88 = F_104 ( V_1 -> V_39 , V_64 , V_112 , V_128 , V_131 ) ;
F_102 ( V_89 ) ;
}
if ( V_88 ) {
V_76 = F_56 ( V_1 , V_64 ) ;
if ( F_82 ( V_76 ) )
return V_76 ;
V_88 = F_101 ( V_1 , V_64 , V_76 , V_128 ) ;
if ( V_88 )
return V_88 ;
continue;
}
V_64 += V_133 ;
V_80 -= V_133 ;
}
return 0 ;
}
int F_105 ( struct V_1 * V_1 , unsigned long V_64 ,
unsigned long V_80 , int V_128 )
{
int V_88 ;
if ( ( V_64 & ~ V_134 ) || ( V_80 & ~ V_134 ) || F_28 ( V_1 ) )
return - V_82 ;
if ( ! V_135 && V_128 == V_136 )
return - V_82 ;
F_59 ( & V_1 -> V_39 -> V_83 ) ;
V_88 = F_103 ( V_1 , V_64 , V_80 , V_128 , V_137 ) ;
F_60 ( & V_1 -> V_39 -> V_83 ) ;
return V_88 ;
}
int F_106 ( struct V_1 * V_1 , unsigned long V_64 , unsigned long * V_138 )
{
unsigned long V_139 , V_76 ;
T_2 * V_89 ;
T_6 * V_112 , V_140 ;
int V_88 ;
while ( 1 ) {
V_88 = - V_132 ;
V_112 = F_98 ( V_1 , V_64 , & V_89 ) ;
if ( V_112 ) {
V_140 = * V_112 ;
if ( F_107 ( V_140 ) && ( F_108 ( V_140 ) & V_141 ) ) {
V_139 = F_108 ( V_140 ) & V_134 ;
V_139 += V_64 & ~ V_134 ;
* V_138 = * ( unsigned long * ) V_139 ;
F_108 ( * V_112 ) |= V_142 ;
V_88 = 0 ;
}
F_102 ( V_89 ) ;
}
if ( ! V_88 )
break;
V_76 = F_56 ( V_1 , V_64 ) ;
if ( F_82 ( V_76 ) ) {
V_88 = V_76 ;
break;
}
V_88 = F_101 ( V_1 , V_64 , V_76 , V_136 ) ;
if ( V_88 )
break;
}
return V_88 ;
}
static inline void F_109 ( struct V_1 * V_61 , unsigned long V_76 ,
struct V_54 * V_55 )
{
void T_1 * * V_51 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_51 = F_110 ( & V_61 -> V_26 , V_76 >> V_143 ) ;
if ( V_51 ) {
V_55 -> V_58 = F_111 ( V_51 ,
& V_61 -> V_27 ) ;
F_112 ( & V_61 -> V_26 , V_51 , V_55 ) ;
} else {
V_55 -> V_58 = NULL ;
F_55 ( & V_61 -> V_26 , V_76 >> V_143 ,
V_55 ) ;
}
}
static int F_113 ( struct V_1 * V_61 , unsigned long V_144 ,
unsigned long V_145 , unsigned long V_80 , int V_128 )
{
struct V_1 * V_60 ;
struct V_54 * V_55 ;
unsigned long V_76 ;
T_2 * V_89 ;
T_6 * V_112 ;
int V_88 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_60 = V_61 -> V_60 ;
while ( V_80 ) {
V_76 = F_56 ( V_60 , V_145 ) ;
if ( F_82 ( V_76 ) )
return V_76 ;
V_55 = F_2 ( sizeof( * V_55 ) , V_18 ) ;
if ( ! V_55 )
return - V_66 ;
V_55 -> V_144 = V_144 ;
V_88 = F_77 ( V_18 ) ;
if ( V_88 ) {
F_12 ( V_55 ) ;
return V_88 ;
}
V_88 = - V_132 ;
V_112 = F_98 ( V_60 , V_145 , & V_89 ) ;
if ( V_112 ) {
F_14 ( & V_61 -> V_27 ) ;
V_88 = F_104 ( V_60 -> V_39 , V_145 , V_112 , V_128 ,
V_146 ) ;
if ( ! V_88 )
F_109 ( V_61 , V_76 , V_55 ) ;
F_18 ( & V_61 -> V_27 ) ;
F_102 ( V_89 ) ;
}
F_80 () ;
if ( V_88 ) {
F_12 ( V_55 ) ;
V_88 = F_101 ( V_60 , V_145 , V_76 , V_128 ) ;
if ( V_88 )
return V_88 ;
continue;
}
V_145 += V_133 ;
V_80 -= V_133 ;
}
return 0 ;
}
static inline void F_114 ( unsigned long V_34 , unsigned long V_147 )
{
asm volatile(
" .insn rrf,0xb98e0000,%0,%1,0,0"
: : "a" (asce), "a" (vaddr) : "cc", "memory");
}
static void F_115 ( struct V_1 * V_61 , unsigned long V_144 )
{
unsigned long * V_4 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_4 = F_97 ( V_61 , V_144 , 0 ) ;
if ( ! V_4 || * V_4 & V_148 )
return;
F_95 ( V_61 , V_144 , V_144 + V_149 - 1 ) ;
F_116 ( V_61 -> V_39 , V_144 , ( T_6 * ) V_4 ) ;
}
static void F_117 ( struct V_1 * V_61 , unsigned long V_144 ,
unsigned long * V_150 )
{
int V_52 ;
F_49 ( ! F_28 ( V_61 ) ) ;
for ( V_52 = 0 ; V_52 < V_151 ; V_52 ++ , V_144 += V_149 )
V_150 [ V_52 ] = V_148 ;
}
static void F_118 ( struct V_1 * V_61 , unsigned long V_144 )
{
unsigned long V_152 , * V_153 , * V_150 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_153 = F_97 ( V_61 , V_144 , 1 ) ;
if ( ! V_153 || ! ( * V_153 & V_124 ) )
return;
F_95 ( V_61 , V_144 , V_144 + V_154 - 1 ) ;
V_152 = ( unsigned long ) ( V_153 - ( ( V_144 & V_105 ) >> V_106 ) ) ;
F_114 ( V_152 | V_8 , V_144 ) ;
V_150 = ( unsigned long * ) ( * V_153 & V_124 ) ;
* V_153 = V_9 ;
F_117 ( V_61 , V_144 , V_150 ) ;
V_3 = F_119 ( F_11 ( V_150 ) >> V_143 ) ;
F_38 ( & V_3 -> V_33 ) ;
F_31 ( V_3 ) ;
}
static void F_120 ( struct V_1 * V_61 , unsigned long V_144 ,
unsigned long * V_155 )
{
unsigned long V_34 , * V_150 ;
struct V_3 * V_3 ;
int V_52 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_34 = ( unsigned long ) V_155 | V_8 ;
for ( V_52 = 0 ; V_52 < V_156 ; V_52 ++ , V_144 += V_154 ) {
if ( ! ( V_155 [ V_52 ] & V_124 ) )
continue;
V_150 = ( unsigned long * ) ( V_155 [ V_52 ] & V_98 ) ;
V_155 [ V_52 ] = V_9 ;
F_117 ( V_61 , V_144 , V_150 ) ;
V_3 = F_119 ( F_11 ( V_150 ) >> V_143 ) ;
F_38 ( & V_3 -> V_33 ) ;
F_31 ( V_3 ) ;
}
}
static void F_121 ( struct V_1 * V_61 , unsigned long V_144 )
{
unsigned long V_157 , * V_158 , * V_155 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_158 = F_97 ( V_61 , V_144 , 2 ) ;
if ( ! V_158 || ! ( * V_158 & V_98 ) )
return;
F_95 ( V_61 , V_144 , V_144 + V_7 - 1 ) ;
V_157 = ( unsigned long ) ( V_158 - ( ( V_144 & V_102 ) >> V_103 ) ) ;
F_114 ( V_157 | V_11 , V_144 ) ;
V_155 = ( unsigned long * ) ( * V_158 & V_98 ) ;
* V_158 = V_12 ;
F_120 ( V_61 , V_144 , V_155 ) ;
V_3 = F_119 ( F_11 ( V_155 ) >> V_143 ) ;
F_38 ( & V_3 -> V_33 ) ;
F_30 ( V_3 , V_30 ) ;
}
static void F_122 ( struct V_1 * V_61 , unsigned long V_144 ,
unsigned long * V_159 )
{
unsigned long V_34 , * V_155 ;
struct V_3 * V_3 ;
int V_52 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_34 = ( unsigned long ) V_159 | V_11 ;
for ( V_52 = 0 ; V_52 < V_156 ; V_52 ++ , V_144 += V_7 ) {
if ( ! ( V_159 [ V_52 ] & V_98 ) )
continue;
V_155 = ( unsigned long * ) ( V_159 [ V_52 ] & V_98 ) ;
V_159 [ V_52 ] = V_12 ;
F_120 ( V_61 , V_144 , V_155 ) ;
V_3 = F_119 ( F_11 ( V_155 ) >> V_143 ) ;
F_38 ( & V_3 -> V_33 ) ;
F_30 ( V_3 , V_30 ) ;
}
}
static void F_123 ( struct V_1 * V_61 , unsigned long V_144 )
{
unsigned long V_160 , * V_161 , * V_159 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_161 = F_97 ( V_61 , V_144 , 3 ) ;
if ( ! V_161 || ! ( * V_161 & V_98 ) )
return;
F_95 ( V_61 , V_144 , V_144 + V_10 - 1 ) ;
V_160 = ( unsigned long ) ( V_161 - ( ( V_144 & V_99 ) >> V_100 ) ) ;
F_114 ( V_160 | V_14 , V_144 ) ;
V_159 = ( unsigned long * ) ( * V_161 & V_98 ) ;
* V_161 = V_15 ;
F_122 ( V_61 , V_144 , V_159 ) ;
V_3 = F_119 ( F_11 ( V_159 ) >> V_143 ) ;
F_38 ( & V_3 -> V_33 ) ;
F_30 ( V_3 , V_30 ) ;
}
static void F_124 ( struct V_1 * V_61 , unsigned long V_144 ,
unsigned long * V_162 )
{
unsigned long V_34 , * V_159 ;
struct V_3 * V_3 ;
int V_52 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_34 = ( unsigned long ) V_162 | V_14 ;
for ( V_52 = 0 ; V_52 < V_156 ; V_52 ++ , V_144 += V_10 ) {
if ( ! ( V_162 [ V_52 ] & V_98 ) )
continue;
V_159 = ( unsigned long * ) ( V_162 [ V_52 ] & V_98 ) ;
V_162 [ V_52 ] = V_15 ;
F_122 ( V_61 , V_144 , V_159 ) ;
V_3 = F_119 ( F_11 ( V_159 ) >> V_143 ) ;
F_38 ( & V_3 -> V_33 ) ;
F_30 ( V_3 , V_30 ) ;
}
}
static void F_125 ( struct V_1 * V_61 , unsigned long V_144 )
{
unsigned long V_163 , * V_164 , * V_162 ;
struct V_3 * V_3 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_164 = F_97 ( V_61 , V_144 , 4 ) ;
if ( ! V_164 || ! ( * V_164 & V_98 ) )
return;
F_95 ( V_61 , V_144 , V_144 + V_13 - 1 ) ;
V_163 = ( unsigned long ) ( V_164 - ( ( V_144 & V_95 ) >> V_96 ) ) ;
F_114 ( V_163 | V_16 , V_144 ) ;
V_162 = ( unsigned long * ) ( * V_164 & V_98 ) ;
* V_164 = V_17 ;
F_124 ( V_61 , V_144 , V_162 ) ;
V_3 = F_119 ( F_11 ( V_162 ) >> V_143 ) ;
F_38 ( & V_3 -> V_33 ) ;
F_30 ( V_3 , V_30 ) ;
}
static void F_126 ( struct V_1 * V_61 , unsigned long V_144 ,
unsigned long * V_165 )
{
unsigned long V_34 , * V_162 ;
struct V_3 * V_3 ;
int V_52 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_34 = ( unsigned long ) V_165 | V_16 ;
for ( V_52 = 0 ; V_52 < V_156 ; V_52 ++ , V_144 += V_13 ) {
if ( ! ( V_165 [ V_52 ] & V_98 ) )
continue;
V_162 = ( unsigned long * ) ( V_165 [ V_52 ] & V_98 ) ;
F_124 ( V_61 , V_144 , V_162 ) ;
F_114 ( V_34 , V_144 ) ;
V_165 [ V_52 ] = V_17 ;
V_3 = F_119 ( F_11 ( V_162 ) >> V_143 ) ;
F_38 ( & V_3 -> V_33 ) ;
F_30 ( V_3 , V_30 ) ;
}
}
static void F_127 ( struct V_1 * V_61 )
{
unsigned long * V_4 ;
F_49 ( ! F_28 ( V_61 ) ) ;
if ( V_61 -> V_59 )
return;
V_61 -> V_59 = 1 ;
F_95 ( V_61 , 0 , - 1UL ) ;
F_19 ( V_61 ) ;
V_4 = ( unsigned long * ) ( V_61 -> V_34 & V_166 ) ;
switch ( V_61 -> V_34 & V_94 ) {
case V_16 :
F_126 ( V_61 , 0 , V_4 ) ;
break;
case V_14 :
F_124 ( V_61 , 0 , V_4 ) ;
break;
case V_11 :
F_122 ( V_61 , 0 , V_4 ) ;
break;
case V_8 :
F_120 ( V_61 , 0 , V_4 ) ;
break;
}
}
static struct V_1 * F_128 ( struct V_1 * V_60 , unsigned long V_34 ,
int V_167 )
{
struct V_1 * V_61 ;
F_96 (sg, &parent->children, list) {
if ( V_61 -> V_168 != V_34 || V_61 -> V_167 != V_167 ||
V_61 -> V_59 )
continue;
if ( ! V_61 -> V_169 )
return F_129 ( - V_132 ) ;
F_34 ( & V_61 -> V_29 ) ;
return V_61 ;
}
return NULL ;
}
int F_130 ( struct V_1 * V_61 , unsigned long V_34 , int V_167 )
{
if ( V_61 -> V_59 )
return 0 ;
return V_61 -> V_168 == V_34 && V_61 -> V_167 == V_167 ;
}
struct V_1 * F_131 ( struct V_1 * V_60 , unsigned long V_34 ,
int V_167 )
{
struct V_1 * V_61 , * V_65 ;
unsigned long V_2 ;
int V_88 ;
F_49 ( F_28 ( V_60 ) ) ;
F_14 ( & V_60 -> V_28 ) ;
V_61 = F_128 ( V_60 , V_34 , V_167 ) ;
F_18 ( & V_60 -> V_28 ) ;
if ( V_61 )
return V_61 ;
V_2 = - 1UL >> ( 33 - ( ( ( V_34 & V_94 ) >> 2 ) * 11 ) ) ;
if ( V_34 & V_170 )
V_2 = - 1UL ;
V_65 = F_1 ( V_2 ) ;
if ( ! V_65 )
return F_129 ( - V_66 ) ;
V_65 -> V_39 = V_60 -> V_39 ;
V_65 -> V_60 = F_33 ( V_60 ) ;
V_65 -> V_168 = V_34 ;
V_65 -> V_167 = V_167 ;
V_65 -> V_169 = false ;
F_14 ( & V_60 -> V_28 ) ;
V_61 = F_128 ( V_60 , V_34 , V_167 ) ;
if ( V_61 ) {
F_18 ( & V_60 -> V_28 ) ;
F_27 ( V_65 ) ;
return V_61 ;
}
if ( V_34 & V_170 ) {
F_96 (sg, &parent->children, list) {
if ( V_61 -> V_168 & V_170 ) {
F_14 ( & V_61 -> V_27 ) ;
F_127 ( V_61 ) ;
F_18 ( & V_61 -> V_27 ) ;
F_38 ( & V_61 -> V_43 ) ;
F_32 ( V_61 ) ;
break;
}
}
}
F_6 ( & V_65 -> V_29 , 2 ) ;
F_8 ( & V_65 -> V_43 , & V_60 -> V_21 ) ;
if ( V_34 & V_170 ) {
V_65 -> V_169 = true ;
F_18 ( & V_60 -> V_28 ) ;
return V_65 ;
}
F_18 ( & V_60 -> V_28 ) ;
F_59 ( & V_60 -> V_39 -> V_83 ) ;
V_88 = F_103 ( V_60 , V_34 & V_166 ,
( ( V_34 & V_35 ) + 1 ) * V_133 ,
V_136 , V_146 ) ;
F_60 ( & V_60 -> V_39 -> V_83 ) ;
F_14 ( & V_60 -> V_28 ) ;
V_65 -> V_169 = true ;
if ( V_88 ) {
F_38 ( & V_65 -> V_43 ) ;
F_27 ( V_65 ) ;
V_65 = F_129 ( V_88 ) ;
}
F_18 ( & V_60 -> V_28 ) ;
return V_65 ;
}
int F_132 ( struct V_1 * V_61 , unsigned long V_171 , unsigned long V_162 ,
int V_172 )
{
unsigned long V_144 , V_173 , V_71 , V_80 ;
unsigned long * V_174 , * V_4 ;
struct V_3 * V_3 ;
int V_88 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_3 = F_7 ( V_18 , V_30 ) ;
if ( ! V_3 )
return - V_66 ;
V_3 -> V_32 = V_162 & V_98 ;
if ( V_172 )
V_3 -> V_32 |= V_175 ;
V_174 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_61 -> V_27 ) ;
V_4 = F_97 ( V_61 , V_171 , 4 ) ;
if ( ! V_4 ) {
V_88 = - V_132 ;
goto V_31;
}
if ( ! ( * V_4 & V_67 ) ) {
V_88 = 0 ;
goto V_31;
} else if ( * V_4 & V_98 ) {
V_88 = - V_132 ;
goto V_31;
}
F_10 ( V_174 , V_15 ) ;
* V_4 = ( unsigned long ) V_174 | V_68 |
V_176 | V_67 ;
if ( V_61 -> V_167 >= 1 )
* V_4 |= ( V_162 & V_177 ) ;
F_8 ( & V_3 -> V_33 , & V_61 -> V_20 ) ;
if ( V_172 ) {
* V_4 &= ~ V_67 ;
F_18 ( & V_61 -> V_27 ) ;
return 0 ;
}
F_18 ( & V_61 -> V_27 ) ;
V_144 = ( V_171 & V_97 ) | V_178 ;
V_173 = V_162 & V_98 ;
V_71 = ( ( V_162 & V_179 ) >> 6 ) * V_133 ;
V_80 = ( ( V_162 & V_68 ) + 1 ) * V_133 - V_71 ;
V_88 = F_113 ( V_61 , V_144 , V_173 + V_71 , V_80 , V_136 ) ;
F_14 ( & V_61 -> V_27 ) ;
if ( ! V_88 ) {
V_4 = F_97 ( V_61 , V_171 , 4 ) ;
if ( ! V_4 || ( * V_4 & V_98 ) !=
( unsigned long ) V_174 )
V_88 = - V_132 ;
else
* V_4 &= ~ V_67 ;
} else {
F_125 ( V_61 , V_144 ) ;
}
F_18 ( & V_61 -> V_27 ) ;
return V_88 ;
V_31:
F_18 ( & V_61 -> V_27 ) ;
F_30 ( V_3 , V_30 ) ;
return V_88 ;
}
int F_133 ( struct V_1 * V_61 , unsigned long V_171 , unsigned long V_159 ,
int V_172 )
{
unsigned long V_144 , V_173 , V_71 , V_80 ;
unsigned long * V_180 , * V_4 ;
struct V_3 * V_3 ;
int V_88 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_3 = F_7 ( V_18 , V_30 ) ;
if ( ! V_3 )
return - V_66 ;
V_3 -> V_32 = V_159 & V_98 ;
if ( V_172 )
V_3 -> V_32 |= V_175 ;
V_180 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_61 -> V_27 ) ;
V_4 = F_97 ( V_61 , V_171 , 3 ) ;
if ( ! V_4 ) {
V_88 = - V_132 ;
goto V_31;
}
if ( ! ( * V_4 & V_67 ) ) {
V_88 = 0 ;
goto V_31;
} else if ( * V_4 & V_98 ) {
V_88 = - V_132 ;
}
F_10 ( V_180 , V_12 ) ;
* V_4 = ( unsigned long ) V_180 | V_68 |
V_181 | V_67 ;
if ( V_61 -> V_167 >= 1 )
* V_4 |= ( V_159 & V_177 ) ;
F_8 ( & V_3 -> V_33 , & V_61 -> V_20 ) ;
if ( V_172 ) {
* V_4 &= ~ V_67 ;
F_18 ( & V_61 -> V_27 ) ;
return 0 ;
}
F_18 ( & V_61 -> V_27 ) ;
V_144 = ( V_171 & V_101 ) | V_182 ;
V_173 = V_159 & V_98 ;
V_71 = ( ( V_159 & V_179 ) >> 6 ) * V_133 ;
V_80 = ( ( V_159 & V_68 ) + 1 ) * V_133 - V_71 ;
V_88 = F_113 ( V_61 , V_144 , V_173 + V_71 , V_80 , V_136 ) ;
F_14 ( & V_61 -> V_27 ) ;
if ( ! V_88 ) {
V_4 = F_97 ( V_61 , V_171 , 3 ) ;
if ( ! V_4 || ( * V_4 & V_98 ) !=
( unsigned long ) V_180 )
V_88 = - V_132 ;
else
* V_4 &= ~ V_67 ;
} else {
F_123 ( V_61 , V_144 ) ;
}
F_18 ( & V_61 -> V_27 ) ;
return V_88 ;
V_31:
F_18 ( & V_61 -> V_27 ) ;
F_30 ( V_3 , V_30 ) ;
return V_88 ;
}
int F_134 ( struct V_1 * V_61 , unsigned long V_171 , unsigned long V_155 ,
int V_172 )
{
unsigned long V_144 , V_173 , V_71 , V_80 ;
unsigned long * V_183 , * V_4 ;
struct V_3 * V_3 ;
int V_88 ;
F_49 ( ! F_28 ( V_61 ) || ( V_155 & V_184 ) ) ;
V_3 = F_7 ( V_18 , V_30 ) ;
if ( ! V_3 )
return - V_66 ;
V_3 -> V_32 = V_155 & V_98 ;
if ( V_172 )
V_3 -> V_32 |= V_175 ;
V_183 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_61 -> V_27 ) ;
V_4 = F_97 ( V_61 , V_171 , 2 ) ;
if ( ! V_4 ) {
V_88 = - V_132 ;
goto V_31;
}
if ( ! ( * V_4 & V_67 ) ) {
V_88 = 0 ;
goto V_31;
} else if ( * V_4 & V_98 ) {
V_88 = - V_132 ;
goto V_31;
}
F_10 ( V_183 , V_9 ) ;
* V_4 = ( unsigned long ) V_183 | V_68 |
V_185 | V_67 ;
if ( V_61 -> V_167 >= 1 )
* V_4 |= V_155 & V_177 ;
F_8 ( & V_3 -> V_33 , & V_61 -> V_20 ) ;
if ( V_172 ) {
* V_4 &= ~ V_67 ;
F_18 ( & V_61 -> V_27 ) ;
return 0 ;
}
F_18 ( & V_61 -> V_27 ) ;
V_144 = ( V_171 & V_104 ) | V_186 ;
V_173 = V_155 & V_98 ;
V_71 = ( ( V_155 & V_179 ) >> 6 ) * V_133 ;
V_80 = ( ( V_155 & V_68 ) + 1 ) * V_133 - V_71 ;
V_88 = F_113 ( V_61 , V_144 , V_173 + V_71 , V_80 , V_136 ) ;
F_14 ( & V_61 -> V_27 ) ;
if ( ! V_88 ) {
V_4 = F_97 ( V_61 , V_171 , 2 ) ;
if ( ! V_4 || ( * V_4 & V_98 ) !=
( unsigned long ) V_183 )
V_88 = - V_132 ;
else
* V_4 &= ~ V_67 ;
} else {
F_121 ( V_61 , V_144 ) ;
}
F_18 ( & V_61 -> V_27 ) ;
return V_88 ;
V_31:
F_18 ( & V_61 -> V_27 ) ;
F_30 ( V_3 , V_30 ) ;
return V_88 ;
}
int F_135 ( struct V_1 * V_61 , unsigned long V_171 ,
unsigned long * V_150 , int * V_187 ,
int * V_172 )
{
unsigned long * V_4 ;
struct V_3 * V_3 ;
int V_88 ;
F_49 ( ! F_28 ( V_61 ) ) ;
F_14 ( & V_61 -> V_27 ) ;
V_4 = F_97 ( V_61 , V_171 , 1 ) ;
if ( V_4 && ! ( * V_4 & V_127 ) ) {
V_3 = F_119 ( * V_4 >> V_143 ) ;
* V_150 = V_3 -> V_32 & ~ V_175 ;
* V_187 = ! ! ( * V_4 & V_188 ) ;
* V_172 = ! ! ( V_3 -> V_32 & V_175 ) ;
V_88 = 0 ;
} else {
V_88 = - V_132 ;
}
F_18 ( & V_61 -> V_27 ) ;
return V_88 ;
}
int F_136 ( struct V_1 * V_61 , unsigned long V_171 , unsigned long V_150 ,
int V_172 )
{
unsigned long V_144 , V_173 ;
unsigned long * V_189 , * V_4 ;
struct V_3 * V_3 ;
int V_88 ;
F_49 ( ! F_28 ( V_61 ) || ( V_150 & V_190 ) ) ;
V_3 = F_137 ( V_61 -> V_39 ) ;
if ( ! V_3 )
return - V_66 ;
V_3 -> V_32 = V_150 & V_124 ;
if ( V_172 )
V_3 -> V_32 |= V_175 ;
V_189 = ( unsigned long * ) F_9 ( V_3 ) ;
F_14 ( & V_61 -> V_27 ) ;
V_4 = F_97 ( V_61 , V_171 , 1 ) ;
if ( ! V_4 ) {
V_88 = - V_132 ;
goto V_31;
}
if ( ! ( * V_4 & V_127 ) ) {
V_88 = 0 ;
goto V_31;
} else if ( * V_4 & V_124 ) {
V_88 = - V_132 ;
goto V_31;
}
* V_4 = ( unsigned long ) V_189 | V_191 |
( V_150 & V_188 ) | V_127 ;
F_8 ( & V_3 -> V_33 , & V_61 -> V_22 ) ;
if ( V_172 ) {
* V_4 &= ~ V_127 ;
F_18 ( & V_61 -> V_27 ) ;
return 0 ;
}
F_18 ( & V_61 -> V_27 ) ;
V_144 = ( V_171 & V_192 ) | V_193 ;
V_173 = V_150 & V_124 & V_134 ;
V_88 = F_113 ( V_61 , V_144 , V_173 , V_133 , V_136 ) ;
F_14 ( & V_61 -> V_27 ) ;
if ( ! V_88 ) {
V_4 = F_97 ( V_61 , V_171 , 1 ) ;
if ( ! V_4 || ( * V_4 & V_124 ) !=
( unsigned long ) V_189 )
V_88 = - V_132 ;
else
* V_4 &= ~ V_127 ;
} else {
F_118 ( V_61 , V_144 ) ;
}
F_18 ( & V_61 -> V_27 ) ;
return V_88 ;
V_31:
F_18 ( & V_61 -> V_27 ) ;
F_31 ( V_3 ) ;
return V_88 ;
}
int F_138 ( struct V_1 * V_61 , unsigned long V_171 , T_6 V_140 )
{
struct V_1 * V_60 ;
struct V_54 * V_55 ;
unsigned long V_76 , V_145 ;
T_2 * V_89 ;
T_6 * V_194 , * V_195 ;
int V_128 ;
int V_88 ;
F_49 ( ! F_28 ( V_61 ) ) ;
V_60 = V_61 -> V_60 ;
V_128 = ( F_108 ( V_140 ) & V_196 ) ? V_136 : V_129 ;
V_55 = F_2 ( sizeof( * V_55 ) , V_18 ) ;
if ( ! V_55 )
return - V_66 ;
V_55 -> V_144 = ( V_171 & V_134 ) | V_197 ;
while ( 1 ) {
V_145 = F_108 ( V_140 ) & V_134 ;
V_76 = F_56 ( V_60 , V_145 ) ;
if ( F_82 ( V_76 ) ) {
V_88 = V_76 ;
break;
}
V_88 = F_77 ( V_18 ) ;
if ( V_88 )
break;
V_88 = - V_132 ;
V_194 = F_98 ( V_60 , V_145 , & V_89 ) ;
if ( V_194 ) {
F_14 ( & V_61 -> V_27 ) ;
V_195 = ( T_6 * ) F_97 ( V_61 , V_171 , 0 ) ;
if ( ! V_195 ) {
F_18 ( & V_61 -> V_27 ) ;
F_102 ( V_89 ) ;
F_80 () ;
break;
}
V_88 = F_139 ( V_61 -> V_39 , V_171 , V_194 , V_195 , V_140 ) ;
if ( V_88 > 0 ) {
F_109 ( V_61 , V_76 , V_55 ) ;
V_55 = NULL ;
V_88 = 0 ;
}
F_102 ( V_89 ) ;
F_18 ( & V_61 -> V_27 ) ;
}
F_80 () ;
if ( ! V_88 )
break;
V_88 = F_101 ( V_60 , V_145 , V_76 , V_128 ) ;
if ( V_88 )
break;
}
F_12 ( V_55 ) ;
return V_88 ;
}
static void F_140 ( struct V_1 * V_61 , unsigned long V_76 ,
unsigned long V_64 , T_6 * V_140 )
{
struct V_54 * V_55 , * V_56 , * V_57 ;
unsigned long V_120 , V_121 , V_131 , V_144 ;
F_49 ( ! F_28 ( V_61 ) ) ;
F_14 ( & V_61 -> V_27 ) ;
if ( V_61 -> V_59 ) {
F_18 ( & V_61 -> V_27 ) ;
return;
}
V_120 = V_61 -> V_168 & V_166 ;
V_121 = V_120 + ( ( V_61 -> V_168 & V_35 ) + 1 ) * V_133 ;
if ( ! ( V_61 -> V_168 & V_170 ) && V_64 >= V_120 &&
V_64 < V_121 ) {
F_127 ( V_61 ) ;
F_18 ( & V_61 -> V_27 ) ;
F_38 ( & V_61 -> V_43 ) ;
F_32 ( V_61 ) ;
return;
}
V_57 = F_24 ( & V_61 -> V_26 , V_76 >> V_143 ) ;
F_26 (rmap, rnext, head) {
V_131 = V_55 -> V_144 & V_198 ;
V_144 = V_55 -> V_144 ^ V_131 ;
switch ( V_131 ) {
case V_178 :
F_125 ( V_61 , V_144 ) ;
break;
case V_182 :
F_123 ( V_61 , V_144 ) ;
break;
case V_186 :
F_121 ( V_61 , V_144 ) ;
break;
case V_193 :
F_118 ( V_61 , V_144 ) ;
break;
case V_197 :
F_115 ( V_61 , V_144 ) ;
break;
}
F_12 ( V_55 ) ;
}
F_18 ( & V_61 -> V_27 ) ;
}
void F_141 ( struct V_38 * V_39 , unsigned long V_76 ,
T_6 * V_140 , unsigned long V_131 )
{
unsigned long V_71 , V_64 = 0 ;
unsigned long * V_4 ;
struct V_1 * V_1 , * V_61 , * V_58 ;
V_71 = ( ( unsigned long ) V_140 ) & ( 255 * sizeof( T_6 ) ) ;
V_71 = V_71 * ( V_133 / sizeof( T_6 ) ) ;
F_62 () ;
F_63 (gmap, &mm->context.gmap_list, list) {
F_14 ( & V_1 -> V_27 ) ;
V_4 = F_57 ( & V_1 -> V_24 ,
V_76 >> V_78 ) ;
if ( V_4 )
V_64 = F_46 ( V_4 ) + V_71 ;
F_18 ( & V_1 -> V_27 ) ;
if ( ! V_4 )
continue;
if ( ! F_37 ( & V_1 -> V_21 ) && ( V_131 & V_146 ) ) {
F_14 ( & V_1 -> V_28 ) ;
F_29 (sg, next,
&gmap->children, list)
F_140 ( V_61 , V_76 , V_64 , V_140 ) ;
F_18 ( & V_1 -> V_28 ) ;
}
if ( V_131 & V_137 )
F_95 ( V_1 , V_64 , V_64 + V_133 - 1 ) ;
}
F_64 () ;
}
static inline void F_142 ( struct V_38 * V_39 )
{
#ifdef F_143
struct V_114 * V_115 ;
unsigned long V_199 ;
for ( V_115 = V_39 -> V_200 ; V_115 != NULL ; V_115 = V_115 -> V_201 ) {
for ( V_199 = V_115 -> V_202 ;
V_199 < V_115 -> V_203 ;
V_199 += V_133 )
F_144 ( V_115 , V_199 , V_204 ) ;
V_115 -> V_205 &= ~ V_206 ;
V_115 -> V_205 |= V_207 ;
}
V_39 -> V_208 |= V_207 ;
#endif
}
static int F_145 ( V_75 * V_93 , unsigned long V_120 ,
unsigned long V_121 , struct V_209 * V_210 )
{
unsigned long V_199 ;
for ( V_199 = V_120 ; V_199 != V_121 ; V_199 += V_133 ) {
T_6 * V_112 ;
T_2 * V_89 ;
V_112 = F_146 ( V_210 -> V_39 , V_93 , V_199 , & V_89 ) ;
if ( F_147 ( F_148 ( * V_112 ) ) )
F_149 ( V_210 -> V_39 , V_199 , V_112 , F_150 ( V_148 ) ) ;
F_88 ( V_112 , V_89 ) ;
}
return 0 ;
}
static inline void F_151 ( struct V_38 * V_39 )
{
struct V_209 V_210 = { . V_211 = F_145 } ;
V_210 . V_39 = V_39 ;
F_152 ( 0 , V_212 , & V_210 ) ;
}
int F_153 ( void )
{
struct V_38 * V_39 = V_111 -> V_39 ;
if ( F_154 ( V_39 ) )
return 0 ;
if ( ! F_155 ( V_39 ) )
return - V_82 ;
F_52 ( & V_39 -> V_83 ) ;
V_39 -> V_41 . V_213 = 1 ;
F_142 ( V_39 ) ;
F_151 ( V_39 ) ;
F_53 ( & V_39 -> V_83 ) ;
return 0 ;
}
static int F_156 ( T_6 * V_140 , unsigned long V_199 ,
unsigned long V_58 , struct V_209 * V_210 )
{
F_157 ( V_210 -> V_39 , V_199 , V_140 ) ;
return 0 ;
}
int F_158 ( void )
{
struct V_209 V_210 = { . V_214 = F_156 } ;
struct V_38 * V_39 = V_111 -> V_39 ;
struct V_114 * V_115 ;
int V_88 = 0 ;
F_52 ( & V_39 -> V_83 ) ;
if ( F_159 ( V_39 ) )
goto V_110;
V_39 -> V_41 . V_215 = 1 ;
for ( V_115 = V_39 -> V_200 ; V_115 ; V_115 = V_115 -> V_201 ) {
if ( F_160 ( V_115 , V_115 -> V_202 , V_115 -> V_203 ,
V_216 , & V_115 -> V_205 ) ) {
V_39 -> V_41 . V_215 = 0 ;
V_88 = - V_66 ;
goto V_110;
}
}
V_39 -> V_208 &= ~ V_217 ;
V_210 . V_39 = V_39 ;
F_152 ( 0 , V_212 , & V_210 ) ;
V_110:
F_53 ( & V_39 -> V_83 ) ;
return V_88 ;
}
static int F_161 ( T_6 * V_140 , unsigned long V_199 ,
unsigned long V_58 , struct V_209 * V_210 )
{
F_87 ( V_210 -> V_39 , V_199 , V_140 , 1 ) ;
return 0 ;
}
void F_162 ( struct V_38 * V_39 )
{
struct V_209 V_210 = { . V_214 = F_161 } ;
F_52 ( & V_39 -> V_83 ) ;
V_210 . V_39 = V_39 ;
F_152 ( 0 , V_212 , & V_210 ) ;
F_53 ( & V_39 -> V_83 ) ;
}
