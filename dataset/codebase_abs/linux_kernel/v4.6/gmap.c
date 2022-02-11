struct V_1 * F_1 ( struct V_2 * V_3 , unsigned long V_4 )
{
struct V_1 * V_1 ;
struct V_5 * V_5 ;
unsigned long * V_6 ;
unsigned long V_7 , V_8 ;
if ( V_4 < ( 1UL << 31 ) ) {
V_4 = ( 1UL << 31 ) - 1 ;
V_8 = V_9 ;
V_7 = V_10 ;
} else if ( V_4 < ( 1UL << 42 ) ) {
V_4 = ( 1UL << 42 ) - 1 ;
V_8 = V_11 ;
V_7 = V_12 ;
} else if ( V_4 < ( 1UL << 53 ) ) {
V_4 = ( 1UL << 53 ) - 1 ;
V_8 = V_13 ;
V_7 = V_14 ;
} else {
V_4 = - 1UL ;
V_8 = V_15 ;
V_7 = V_16 ;
}
V_1 = F_2 ( sizeof( struct V_1 ) , V_17 ) ;
if ( ! V_1 )
goto V_18;
F_3 ( & V_1 -> V_19 ) ;
F_4 ( & V_1 -> V_20 , V_17 ) ;
F_4 ( & V_1 -> V_21 , V_22 ) ;
F_5 ( & V_1 -> V_23 ) ;
V_1 -> V_3 = V_3 ;
V_5 = F_6 ( V_17 , 2 ) ;
if ( ! V_5 )
goto V_24;
V_5 -> V_25 = 0 ;
F_7 ( & V_5 -> V_26 , & V_1 -> V_19 ) ;
V_6 = ( unsigned long * ) F_8 ( V_5 ) ;
F_9 ( V_6 , V_7 ) ;
V_1 -> V_6 = V_6 ;
V_1 -> V_27 = V_8 | V_28 |
V_29 | F_10 ( V_6 ) ;
V_1 -> V_30 = V_4 ;
F_11 ( & V_3 -> V_31 ) ;
F_7 ( & V_1 -> V_32 , & V_3 -> V_33 . V_34 ) ;
F_12 ( & V_3 -> V_31 ) ;
return V_1 ;
V_24:
F_13 ( V_1 ) ;
V_18:
return NULL ;
}
static void F_14 ( struct V_1 * V_1 )
{
if ( V_35 )
F_15 ( V_1 -> V_3 , V_1 -> V_27 ) ;
else
F_16 () ;
}
static void F_17 ( struct V_36 * V_37 )
{
struct V_38 V_39 ;
unsigned long V_40 [ 16 ] ;
unsigned long V_25 ;
void * * V_41 ;
int V_42 , V_43 ;
V_25 = 0 ;
do {
V_43 = 0 ;
F_18 (slot, root, &iter, index) {
V_40 [ V_43 ] = V_39 . V_25 ;
if ( ++ V_43 == 16 )
break;
}
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
V_25 = V_40 [ V_42 ] ;
F_19 ( V_37 , V_25 ) ;
}
} while ( V_43 > 0 );
}
void F_20 ( struct V_1 * V_1 )
{
struct V_5 * V_5 , * V_44 ;
if ( V_35 )
F_15 ( V_1 -> V_3 , V_1 -> V_27 ) ;
else
F_16 () ;
F_21 (page, next, &gmap->crst_list, lru)
F_22 ( V_5 , 2 ) ;
F_17 ( & V_1 -> V_20 ) ;
F_17 ( & V_1 -> V_21 ) ;
F_11 ( & V_1 -> V_3 -> V_31 ) ;
F_23 ( & V_1 -> V_32 ) ;
F_12 ( & V_1 -> V_3 -> V_31 ) ;
F_13 ( V_1 ) ;
}
void F_24 ( struct V_1 * V_1 )
{
V_45 . V_1 = ( unsigned long ) V_1 ;
}
void F_25 ( struct V_1 * V_1 )
{
V_45 . V_1 = 0UL ;
}
static int F_26 ( struct V_1 * V_1 , unsigned long * V_6 ,
unsigned long V_46 , unsigned long V_47 )
{
struct V_5 * V_5 ;
unsigned long * V_48 ;
V_5 = F_6 ( V_17 , 2 ) ;
if ( ! V_5 )
return - V_49 ;
V_48 = ( unsigned long * ) F_8 ( V_5 ) ;
F_9 ( V_48 , V_46 ) ;
F_27 ( & V_1 -> V_3 -> V_50 ) ;
if ( * V_6 & V_51 ) {
F_7 ( & V_5 -> V_26 , & V_1 -> V_19 ) ;
* V_6 = ( unsigned long ) V_48 | V_52 |
( * V_6 & V_53 ) ;
V_5 -> V_25 = V_47 ;
V_5 = NULL ;
}
F_28 ( & V_1 -> V_3 -> V_50 ) ;
if ( V_5 )
F_22 ( V_5 , 2 ) ;
return 0 ;
}
static unsigned long F_29 ( unsigned long * V_54 )
{
struct V_5 * V_5 ;
unsigned long V_55 , V_56 ;
V_55 = ( unsigned long ) V_54 / sizeof( unsigned long ) ;
V_55 = ( V_55 & ( V_57 - 1 ) ) * V_58 ;
V_56 = ~ ( V_57 * sizeof( V_59 ) - 1 ) ;
V_5 = F_30 ( ( void * ) ( ( unsigned long ) V_54 & V_56 ) ) ;
return V_5 -> V_25 + V_55 ;
}
static int F_31 ( struct V_1 * V_1 , unsigned long V_60 )
{
unsigned long * V_54 ;
int V_61 = 0 ;
F_27 ( & V_1 -> V_23 ) ;
V_54 = F_19 ( & V_1 -> V_21 , V_60 >> V_62 ) ;
if ( V_54 ) {
V_61 = ( * V_54 != V_63 ) ;
* V_54 = V_63 ;
}
F_28 ( & V_1 -> V_23 ) ;
return V_61 ;
}
static int F_32 ( struct V_1 * V_1 , unsigned long V_47 )
{
unsigned long V_60 ;
V_60 = ( unsigned long ) F_19 ( & V_1 -> V_20 ,
V_47 >> V_62 ) ;
return V_60 ? F_31 ( V_1 , V_60 ) : 0 ;
}
int F_33 ( struct V_1 * V_1 , unsigned long V_64 , unsigned long V_65 )
{
unsigned long V_66 ;
int V_61 ;
if ( ( V_64 | V_65 ) & ( V_58 - 1 ) )
return - V_67 ;
if ( V_65 == 0 || V_64 + V_65 < V_64 )
return - V_67 ;
V_61 = 0 ;
F_11 ( & V_1 -> V_3 -> V_31 ) ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 += V_58 )
V_61 |= F_32 ( V_1 , V_64 + V_66 ) ;
F_12 ( & V_1 -> V_3 -> V_31 ) ;
if ( V_61 )
F_14 ( V_1 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_1 , unsigned long V_68 ,
unsigned long V_64 , unsigned long V_65 )
{
unsigned long V_66 ;
int V_61 ;
if ( ( V_68 | V_64 | V_65 ) & ( V_58 - 1 ) )
return - V_67 ;
if ( V_65 == 0 || V_68 + V_65 < V_68 || V_64 + V_65 < V_64 ||
V_68 + V_65 - 1 > V_69 || V_64 + V_65 - 1 > V_1 -> V_30 )
return - V_67 ;
V_61 = 0 ;
F_11 ( & V_1 -> V_3 -> V_31 ) ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 += V_58 ) {
V_61 |= F_32 ( V_1 , V_64 + V_66 ) ;
if ( F_35 ( & V_1 -> V_20 ,
( V_64 + V_66 ) >> V_62 ,
( void * ) V_68 + V_66 ) )
break;
}
F_12 ( & V_1 -> V_3 -> V_31 ) ;
if ( V_61 )
F_14 ( V_1 ) ;
if ( V_66 >= V_65 )
return 0 ;
F_33 ( V_1 , V_64 , V_65 ) ;
return - V_49 ;
}
unsigned long F_36 ( struct V_1 * V_1 , unsigned long V_47 )
{
unsigned long V_60 ;
V_60 = ( unsigned long )
F_37 ( & V_1 -> V_20 , V_47 >> V_62 ) ;
return V_60 ? ( V_60 | ( V_47 & ~ V_70 ) ) : - V_71 ;
}
unsigned long F_38 ( struct V_1 * V_1 , unsigned long V_47 )
{
unsigned long V_72 ;
F_39 ( & V_1 -> V_3 -> V_31 ) ;
V_72 = F_36 ( V_1 , V_47 ) ;
F_40 ( & V_1 -> V_3 -> V_31 ) ;
return V_72 ;
}
void F_41 ( struct V_2 * V_3 , unsigned long * V_6 ,
unsigned long V_60 )
{
struct V_1 * V_1 ;
int V_61 ;
F_42 (gmap, &mm->context.gmap_list, list) {
V_61 = F_31 ( V_1 , V_60 ) ;
if ( V_61 )
F_14 ( V_1 ) ;
}
}
int F_43 ( struct V_1 * V_1 , unsigned long V_47 , unsigned long V_60 )
{
struct V_2 * V_3 ;
unsigned long * V_6 ;
T_1 * V_73 ;
T_2 * V_74 ;
T_3 * V_75 ;
V_59 * V_76 ;
int V_72 ;
V_6 = V_1 -> V_6 ;
if ( ( V_1 -> V_27 & V_77 ) >= V_15 ) {
V_6 += ( V_47 >> 53 ) & 0x7ff ;
if ( ( * V_6 & V_51 ) &&
F_26 ( V_1 , V_6 , V_14 ,
V_47 & 0xffe0000000000000UL ) )
return - V_49 ;
V_6 = ( unsigned long * ) ( * V_6 & V_78 ) ;
}
if ( ( V_1 -> V_27 & V_77 ) >= V_13 ) {
V_6 += ( V_47 >> 42 ) & 0x7ff ;
if ( ( * V_6 & V_51 ) &&
F_26 ( V_1 , V_6 , V_12 ,
V_47 & 0xfffffc0000000000UL ) )
return - V_49 ;
V_6 = ( unsigned long * ) ( * V_6 & V_78 ) ;
}
if ( ( V_1 -> V_27 & V_77 ) >= V_11 ) {
V_6 += ( V_47 >> 31 ) & 0x7ff ;
if ( ( * V_6 & V_51 ) &&
F_26 ( V_1 , V_6 , V_10 ,
V_47 & 0xffffffff80000000UL ) )
return - V_49 ;
V_6 = ( unsigned long * ) ( * V_6 & V_78 ) ;
}
V_6 += ( V_47 >> 20 ) & 0x7ff ;
V_3 = V_1 -> V_3 ;
V_74 = F_44 ( V_3 , V_60 ) ;
F_45 ( F_46 ( * V_74 ) ) ;
V_75 = F_47 ( V_74 , V_60 ) ;
F_45 ( F_48 ( * V_75 ) ) ;
V_76 = F_49 ( V_75 , V_60 ) ;
F_45 ( F_50 ( * V_76 ) ) ;
if ( F_51 ( * V_76 ) )
return - V_71 ;
V_72 = F_52 ( V_17 ) ;
if ( V_72 )
return V_72 ;
V_73 = F_53 ( V_3 , V_76 ) ;
F_27 ( & V_1 -> V_23 ) ;
if ( * V_6 == V_63 ) {
V_72 = F_35 ( & V_1 -> V_21 ,
V_60 >> V_62 , V_6 ) ;
if ( ! V_72 )
* V_6 = F_54 ( * V_76 ) ;
} else
V_72 = 0 ;
F_28 ( & V_1 -> V_23 ) ;
F_28 ( V_73 ) ;
F_55 () ;
return V_72 ;
}
int F_56 ( struct V_1 * V_1 , unsigned long V_47 ,
unsigned int V_79 )
{
unsigned long V_60 ;
int V_72 ;
bool V_80 ;
F_39 ( & V_1 -> V_3 -> V_31 ) ;
V_81:
V_80 = false ;
V_60 = F_36 ( V_1 , V_47 ) ;
if ( F_57 ( V_60 ) ) {
V_72 = V_60 ;
goto V_82;
}
if ( F_58 ( V_83 , V_1 -> V_3 , V_60 , V_79 ,
& V_80 ) ) {
V_72 = - V_71 ;
goto V_82;
}
if ( V_80 )
goto V_81;
V_72 = F_43 ( V_1 , V_47 , V_60 ) ;
V_82:
F_40 ( & V_1 -> V_3 -> V_31 ) ;
return V_72 ;
}
void F_59 ( struct V_1 * V_1 , unsigned long V_47 )
{
unsigned long V_60 ;
T_1 * V_73 ;
T_4 * V_84 ;
V_60 = ( unsigned long ) F_37 ( & V_1 -> V_20 ,
V_47 >> V_62 ) ;
if ( V_60 ) {
V_60 |= V_47 & ~ V_70 ;
V_84 = F_60 ( V_1 -> V_3 , V_60 , & V_73 ) ;
if ( F_61 ( V_84 ) )
F_62 ( V_1 -> V_3 , V_60 , V_84 , 0 ) ;
F_63 ( V_84 , V_73 ) ;
}
}
void F_64 ( struct V_1 * V_1 , unsigned long V_68 , unsigned long V_64 )
{
unsigned long V_47 , V_60 , V_85 ;
struct V_86 * V_87 ;
F_39 ( & V_1 -> V_3 -> V_31 ) ;
for ( V_47 = V_68 ; V_47 < V_64 ;
V_47 = ( V_47 + V_58 ) & V_70 ) {
V_60 = ( unsigned long )
F_37 ( & V_1 -> V_20 ,
V_47 >> V_62 ) ;
if ( ! V_60 )
continue;
V_60 |= V_47 & ~ V_70 ;
V_87 = F_65 ( V_1 -> V_3 , V_60 ) ;
V_85 = F_66 ( V_64 - V_47 , V_58 - ( V_47 & ~ V_70 ) ) ;
F_67 ( V_87 , V_60 , V_85 , NULL ) ;
}
F_40 ( & V_1 -> V_3 -> V_31 ) ;
}
void F_68 ( struct V_88 * V_89 )
{
F_27 ( & V_90 ) ;
F_7 ( & V_89 -> V_32 , & V_91 ) ;
F_28 ( & V_90 ) ;
}
void F_69 ( struct V_88 * V_89 )
{
F_27 ( & V_90 ) ;
F_70 ( & V_89 -> V_32 ) ;
F_28 ( & V_90 ) ;
}
int F_71 ( struct V_1 * V_1 , unsigned long V_47 , unsigned long V_65 )
{
unsigned long V_92 ;
T_1 * V_73 ;
T_4 * V_84 ;
bool V_80 ;
int V_72 = 0 ;
if ( ( V_47 & ~ V_93 ) || ( V_65 & ~ V_93 ) )
return - V_67 ;
F_39 ( & V_1 -> V_3 -> V_31 ) ;
while ( V_65 ) {
V_80 = false ;
V_92 = F_36 ( V_1 , V_47 ) ;
if ( F_57 ( V_92 ) ) {
V_72 = V_92 ;
break;
}
if ( F_58 ( V_83 , V_1 -> V_3 , V_92 , V_94 ,
& V_80 ) ) {
V_72 = - V_71 ;
break;
}
if ( V_80 )
continue;
V_72 = F_43 ( V_1 , V_47 , V_92 ) ;
if ( V_72 )
break;
V_84 = F_60 ( V_1 -> V_3 , V_92 , & V_73 ) ;
F_45 ( ! V_84 ) ;
if ( ( F_72 ( * V_84 ) & ( V_95 | V_96 ) ) == 0 ) {
F_73 ( V_1 -> V_3 , V_92 , V_84 ) ;
V_47 += V_97 ;
V_65 -= V_97 ;
}
F_63 ( V_84 , V_73 ) ;
}
F_40 ( & V_1 -> V_3 -> V_31 ) ;
return V_72 ;
}
void F_74 ( struct V_2 * V_3 , unsigned long V_60 , T_4 * V_98 )
{
unsigned long V_55 , V_47 ;
unsigned long * V_6 ;
struct V_88 * V_89 ;
struct V_1 * V_1 ;
V_55 = ( ( unsigned long ) V_98 ) & ( 255 * sizeof( T_4 ) ) ;
V_55 = V_55 * ( 4096 / sizeof( T_4 ) ) ;
F_27 ( & V_90 ) ;
F_42 (gmap, &mm->context.gmap_list, list) {
V_6 = F_37 ( & V_1 -> V_21 ,
V_60 >> V_62 ) ;
if ( ! V_6 )
continue;
V_47 = F_29 ( V_6 ) + V_55 ;
F_42 (nb, &gmap_notifier_list, list)
V_89 -> V_99 ( V_1 , V_47 ) ;
}
F_28 ( & V_90 ) ;
}
static inline void F_75 ( struct V_2 * V_3 )
{
#ifdef F_76
struct V_86 * V_87 ;
unsigned long V_92 ;
for ( V_87 = V_3 -> V_100 ; V_87 != NULL ; V_87 = V_87 -> V_101 ) {
for ( V_92 = V_87 -> V_102 ;
V_92 < V_87 -> V_103 ;
V_92 += V_97 )
F_77 ( V_87 , V_92 , V_104 ) ;
V_87 -> V_105 &= ~ V_106 ;
V_87 -> V_105 |= V_107 ;
}
V_3 -> V_108 |= V_107 ;
#endif
}
int F_78 ( void )
{
struct V_2 * V_3 = V_83 -> V_3 ;
if ( F_79 ( V_3 ) )
return 0 ;
if ( ! F_80 ( V_3 ) )
return - V_67 ;
F_11 ( & V_3 -> V_31 ) ;
V_3 -> V_33 . V_109 = 1 ;
F_75 ( V_3 ) ;
F_12 ( & V_3 -> V_31 ) ;
return 0 ;
}
static int F_81 ( T_4 * V_98 , unsigned long V_92 ,
unsigned long V_44 , struct V_110 * V_111 )
{
if ( F_82 ( F_83 ( * V_98 ) ) )
F_84 ( V_111 -> V_3 , V_92 , V_98 , F_85 ( V_95 ) ) ;
F_86 ( V_111 -> V_3 , V_92 , V_98 ) ;
return 0 ;
}
int F_87 ( void )
{
struct V_110 V_111 = { . V_112 = F_81 } ;
struct V_2 * V_3 = V_83 -> V_3 ;
struct V_86 * V_87 ;
int V_72 = 0 ;
F_11 ( & V_3 -> V_31 ) ;
if ( F_88 ( V_3 ) )
goto V_82;
V_3 -> V_33 . V_113 = 1 ;
for ( V_87 = V_3 -> V_100 ; V_87 ; V_87 = V_87 -> V_101 ) {
if ( F_89 ( V_87 , V_87 -> V_102 , V_87 -> V_103 ,
V_114 , & V_87 -> V_105 ) ) {
V_3 -> V_33 . V_113 = 0 ;
V_72 = - V_49 ;
goto V_82;
}
}
V_3 -> V_108 &= ~ V_115 ;
V_111 . V_3 = V_3 ;
F_90 ( 0 , V_116 , & V_111 ) ;
V_82:
F_12 ( & V_3 -> V_31 ) ;
return V_72 ;
}
static int F_91 ( T_4 * V_98 , unsigned long V_92 ,
unsigned long V_44 , struct V_110 * V_111 )
{
F_62 ( V_111 -> V_3 , V_92 , V_98 , 1 ) ;
return 0 ;
}
void F_92 ( struct V_2 * V_3 )
{
struct V_110 V_111 = { . V_112 = F_91 } ;
F_11 ( & V_3 -> V_31 ) ;
V_111 . V_3 = V_3 ;
F_90 ( 0 , V_116 , & V_111 ) ;
F_12 ( & V_3 -> V_31 ) ;
}
