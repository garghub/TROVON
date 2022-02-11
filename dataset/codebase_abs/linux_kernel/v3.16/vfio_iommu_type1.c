static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 , T_2 V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 . V_6 ;
while ( V_7 ) {
struct V_1 * V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
if ( V_4 + V_5 <= V_9 -> V_10 )
V_7 = V_7 -> V_11 ;
else if ( V_4 >= V_9 -> V_10 + V_9 -> V_5 )
V_7 = V_7 -> V_12 ;
else
return V_9 ;
}
return NULL ;
}
static void F_3 ( struct V_2 * V_3 , struct V_1 * V_13 )
{
struct V_6 * * V_14 = & V_3 -> V_8 . V_6 , * V_15 = NULL ;
struct V_1 * V_9 ;
while ( * V_14 ) {
V_15 = * V_14 ;
V_9 = F_2 ( V_15 , struct V_1 , V_7 ) ;
if ( V_13 -> V_10 + V_13 -> V_5 <= V_9 -> V_10 )
V_14 = & ( * V_14 ) -> V_11 ;
else
V_14 = & ( * V_14 ) -> V_12 ;
}
F_4 ( & V_13 -> V_7 , V_15 , V_14 ) ;
F_5 ( & V_13 -> V_7 , & V_3 -> V_8 ) ;
}
static void F_6 ( struct V_2 * V_3 , struct V_1 * V_16 )
{
F_7 ( & V_16 -> V_7 , & V_3 -> V_8 ) ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_19 * V_19 = F_9 ( V_18 , struct V_19 , V_18 ) ;
struct V_20 * V_21 ;
V_21 = V_19 -> V_21 ;
F_10 ( & V_21 -> V_22 ) ;
V_21 -> V_23 += V_19 -> V_24 ;
F_11 ( & V_21 -> V_22 ) ;
F_12 ( V_21 ) ;
F_13 ( V_19 ) ;
}
static void F_14 ( long V_24 )
{
struct V_19 * V_19 ;
struct V_20 * V_21 ;
if ( ! V_25 -> V_21 || ! V_24 )
return;
if ( F_15 ( & V_25 -> V_21 -> V_22 ) ) {
V_25 -> V_21 -> V_23 += V_24 ;
F_11 ( & V_25 -> V_21 -> V_22 ) ;
return;
}
V_19 = F_16 ( sizeof( struct V_19 ) , V_26 ) ;
if ( ! V_19 )
return;
V_21 = F_17 ( V_25 ) ;
if ( ! V_21 ) {
F_13 ( V_19 ) ;
return;
}
F_18 ( & V_19 -> V_18 , F_8 ) ;
V_19 -> V_21 = V_21 ;
V_19 -> V_24 = V_24 ;
F_19 ( & V_19 -> V_18 ) ;
}
static bool F_20 ( unsigned long V_27 )
{
if ( F_21 ( V_27 ) ) {
bool V_28 ;
struct V_29 * V_30 = F_22 ( V_27 ) ;
struct V_29 * V_31 = F_23 ( V_30 ) ;
V_28 = ! ! ( F_24 ( V_31 ) ) ;
if ( V_31 != V_30 ) {
F_25 () ;
if ( F_26 ( V_30 ) )
return V_28 ;
}
return F_24 ( V_30 ) ;
}
return true ;
}
static int F_27 ( unsigned long V_27 , int V_32 )
{
if ( ! F_20 ( V_27 ) ) {
struct V_29 * V_29 = F_22 ( V_27 ) ;
if ( V_32 & V_33 )
F_28 ( V_29 ) ;
F_29 ( V_29 ) ;
return 1 ;
}
return 0 ;
}
static int F_30 ( unsigned long V_34 , int V_32 , unsigned long * V_27 )
{
struct V_29 * V_29 [ 1 ] ;
struct V_35 * V_36 ;
int V_37 = - V_38 ;
if ( F_31 ( V_34 , 1 , ! ! ( V_32 & V_33 ) , V_29 ) == 1 ) {
* V_27 = F_32 ( V_29 [ 0 ] ) ;
return 0 ;
}
F_33 ( & V_25 -> V_21 -> V_22 ) ;
V_36 = F_34 ( V_25 -> V_21 , V_34 , V_34 + 1 ) ;
if ( V_36 && V_36 -> V_39 & V_40 ) {
* V_27 = ( ( V_34 - V_36 -> V_41 ) >> V_42 ) + V_36 -> V_43 ;
if ( F_20 ( * V_27 ) )
V_37 = 0 ;
}
F_35 ( & V_25 -> V_21 -> V_22 ) ;
return V_37 ;
}
static long F_36 ( unsigned long V_34 , long V_24 ,
int V_32 , unsigned long * V_44 )
{
unsigned long V_45 = F_37 ( V_46 ) >> V_42 ;
bool V_47 = F_38 ( V_48 ) ;
long V_37 , V_49 ;
if ( ! V_25 -> V_21 )
return - V_50 ;
V_37 = F_30 ( V_34 , V_32 , V_44 ) ;
if ( V_37 )
return V_37 ;
if ( F_20 ( * V_44 ) )
return 1 ;
if ( ! V_47 && V_25 -> V_21 -> V_23 + 1 > V_45 ) {
F_27 ( * V_44 , V_32 ) ;
F_39 ( L_1 , V_51 ,
V_45 << V_42 ) ;
return - V_52 ;
}
if ( F_40 ( V_53 ) ) {
F_14 ( 1 ) ;
return 1 ;
}
for ( V_49 = 1 , V_34 += V_54 ; V_49 < V_24 ; V_49 ++ , V_34 += V_54 ) {
unsigned long V_27 = 0 ;
V_37 = F_30 ( V_34 , V_32 , & V_27 ) ;
if ( V_37 )
break;
if ( V_27 != * V_44 + V_49 || F_20 ( V_27 ) ) {
F_27 ( V_27 , V_32 ) ;
break;
}
if ( ! V_47 && V_25 -> V_21 -> V_23 + V_49 + 1 > V_45 ) {
F_27 ( V_27 , V_32 ) ;
F_39 ( L_1 ,
V_51 , V_45 << V_42 ) ;
break;
}
}
F_14 ( V_49 ) ;
return V_49 ;
}
static long F_41 ( unsigned long V_27 , long V_24 ,
int V_32 , bool V_55 )
{
unsigned long V_56 = 0 ;
long V_49 ;
for ( V_49 = 0 ; V_49 < V_24 ; V_49 ++ )
V_56 += F_27 ( V_27 ++ , V_32 ) ;
if ( V_55 )
F_14 ( - V_56 ) ;
return V_56 ;
}
static void F_42 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
T_1 V_10 = V_9 -> V_10 , V_57 = V_9 -> V_10 + V_9 -> V_5 ;
struct V_58 * V_59 , * V_60 ;
long V_56 = 0 ;
if ( ! V_9 -> V_5 )
return;
V_59 = V_60 = F_43 ( & V_3 -> V_61 ,
struct V_58 , V_62 ) ;
F_44 (d, &iommu->domain_list, next)
F_45 ( V_60 -> V_59 , V_9 -> V_10 , V_9 -> V_5 ) ;
while ( V_10 < V_57 ) {
T_2 V_63 ;
T_3 V_64 ;
V_64 = F_46 ( V_59 -> V_59 , V_10 ) ;
if ( F_47 ( ! V_64 ) ) {
V_10 += V_54 ;
continue;
}
V_63 = F_45 ( V_59 -> V_59 , V_10 , V_54 ) ;
if ( F_47 ( ! V_63 ) )
break;
V_56 += F_41 ( V_64 >> V_42 ,
V_63 >> V_42 ,
V_9 -> V_32 , false ) ;
V_10 += V_63 ;
}
F_14 ( - V_56 ) ;
}
static void F_48 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
F_42 ( V_3 , V_9 ) ;
F_6 ( V_3 , V_9 ) ;
F_13 ( V_9 ) ;
}
static unsigned long F_49 ( struct V_2 * V_3 )
{
struct V_58 * V_59 ;
unsigned long V_65 = V_66 ;
F_50 ( & V_3 -> V_67 ) ;
F_51 (domain, &iommu->domain_list, next)
V_65 &= V_59 -> V_59 -> V_68 -> V_69 ;
F_52 ( & V_3 -> V_67 ) ;
return V_65 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_70 * V_71 )
{
T_4 V_72 ;
struct V_1 * V_9 ;
T_2 V_63 = 0 ;
int V_37 = 0 ;
V_72 = ( ( T_4 ) 1 << F_54 ( F_49 ( V_3 ) ) ) - 1 ;
if ( V_71 -> V_10 & V_72 )
return - V_73 ;
if ( ! V_71 -> V_5 || V_71 -> V_5 & V_72 )
return - V_73 ;
F_47 ( V_72 & V_66 ) ;
F_50 ( & V_3 -> V_67 ) ;
if ( V_3 -> V_74 ) {
V_9 = F_1 ( V_3 , V_71 -> V_10 , 0 ) ;
if ( V_9 && V_9 -> V_10 != V_71 -> V_10 ) {
V_37 = - V_73 ;
goto V_75;
}
V_9 = F_1 ( V_3 , V_71 -> V_10 + V_71 -> V_5 - 1 , 0 ) ;
if ( V_9 && V_9 -> V_10 + V_9 -> V_5 != V_71 -> V_10 + V_71 -> V_5 ) {
V_37 = - V_73 ;
goto V_75;
}
}
while ( ( V_9 = F_1 ( V_3 , V_71 -> V_10 , V_71 -> V_5 ) ) ) {
if ( ! V_3 -> V_74 && V_71 -> V_10 > V_9 -> V_10 )
break;
V_63 += V_9 -> V_5 ;
F_48 ( V_3 , V_9 ) ;
}
V_75:
F_52 ( & V_3 -> V_67 ) ;
V_71 -> V_5 = V_63 ;
return V_37 ;
}
static int F_55 ( struct V_58 * V_59 , T_1 V_10 ,
unsigned long V_27 , long V_24 , int V_32 )
{
long V_49 ;
int V_37 ;
for ( V_49 = 0 ; V_49 < V_24 ; V_49 ++ , V_27 ++ , V_10 += V_54 ) {
V_37 = F_56 ( V_59 -> V_59 , V_10 ,
( T_3 ) V_27 << V_42 ,
V_54 , V_32 | V_59 -> V_32 ) ;
if ( V_37 )
break;
}
for (; V_49 < V_24 && V_49 > 0 ; V_49 -- , V_10 -= V_54 )
F_45 ( V_59 -> V_59 , V_10 , V_54 ) ;
return V_37 ;
}
static int F_57 ( struct V_2 * V_3 , T_1 V_10 ,
unsigned long V_27 , long V_24 , int V_32 )
{
struct V_58 * V_60 ;
int V_37 ;
F_51 (d, &iommu->domain_list, next) {
V_37 = F_56 ( V_60 -> V_59 , V_10 , ( T_3 ) V_27 << V_42 ,
V_24 << V_42 , V_32 | V_60 -> V_32 ) ;
if ( V_37 ) {
if ( V_37 != - V_76 ||
F_55 ( V_60 , V_10 , V_27 , V_24 , V_32 ) )
goto V_77;
}
}
return 0 ;
V_77:
F_58 (d, &iommu->domain_list, next)
F_45 ( V_60 -> V_59 , V_10 , V_24 << V_42 ) ;
return V_37 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_78 * V_79 )
{
T_1 V_10 = V_79 -> V_10 ;
unsigned long V_34 = V_79 -> V_34 ;
T_2 V_5 = V_79 -> V_5 ;
long V_24 ;
int V_37 = 0 , V_32 = 0 ;
T_4 V_72 ;
struct V_1 * V_9 ;
unsigned long V_27 ;
if ( V_79 -> V_5 != V_5 || V_79 -> V_34 != V_34 || V_79 -> V_10 != V_10 )
return - V_73 ;
V_72 = ( ( T_4 ) 1 << F_54 ( F_49 ( V_3 ) ) ) - 1 ;
F_47 ( V_72 & V_66 ) ;
if ( V_79 -> V_80 & V_81 )
V_32 |= V_33 ;
if ( V_79 -> V_80 & V_82 )
V_32 |= V_83 ;
if ( ! V_32 || ! V_5 || ( V_5 | V_10 | V_34 ) & V_72 )
return - V_73 ;
if ( V_10 + V_5 - 1 < V_10 || V_34 + V_5 - 1 < V_34 )
return - V_73 ;
F_50 ( & V_3 -> V_67 ) ;
if ( F_1 ( V_3 , V_10 , V_5 ) ) {
F_52 ( & V_3 -> V_67 ) ;
return - V_84 ;
}
V_9 = F_60 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 ) {
F_52 ( & V_3 -> V_67 ) ;
return - V_52 ;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_32 = V_32 ;
F_3 ( V_3 , V_9 ) ;
while ( V_5 ) {
V_24 = F_36 ( V_34 + V_9 -> V_5 ,
V_5 >> V_42 , V_32 , & V_27 ) ;
if ( V_24 <= 0 ) {
F_47 ( ! V_24 ) ;
V_37 = ( int ) V_24 ;
break;
}
V_37 = F_57 ( V_3 , V_10 + V_9 -> V_5 , V_27 , V_24 , V_32 ) ;
if ( V_37 ) {
F_41 ( V_27 , V_24 , V_32 , true ) ;
break;
}
V_5 -= V_24 << V_42 ;
V_9 -> V_5 += V_24 << V_42 ;
}
if ( V_37 )
F_48 ( V_3 , V_9 ) ;
F_52 ( & V_3 -> V_67 ) ;
return V_37 ;
}
static int F_61 ( struct V_85 * V_86 , void * V_87 )
{
struct V_88 * * V_89 = V_87 ;
if ( * V_89 && * V_89 != V_86 -> V_89 )
return - V_73 ;
* V_89 = V_86 -> V_89 ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_58 * V_59 )
{
struct V_58 * V_60 ;
struct V_6 * V_90 ;
int V_37 ;
V_60 = F_43 ( & V_3 -> V_61 , struct V_58 , V_62 ) ;
V_90 = F_63 ( & V_3 -> V_8 ) ;
if ( F_47 ( V_90 && ! V_60 ) )
return - V_73 ;
for (; V_90 ; V_90 = F_64 ( V_90 ) ) {
struct V_1 * V_9 ;
T_1 V_10 ;
V_9 = F_2 ( V_90 , struct V_1 , V_7 ) ;
V_10 = V_9 -> V_10 ;
while ( V_10 < V_9 -> V_10 + V_9 -> V_5 ) {
T_3 V_64 = F_46 ( V_60 -> V_59 , V_10 ) ;
T_2 V_5 ;
if ( F_47 ( ! V_64 ) ) {
V_10 += V_54 ;
continue;
}
V_5 = V_54 ;
while ( V_10 + V_5 < V_9 -> V_10 + V_9 -> V_5 &&
V_64 + V_5 == F_46 ( V_60 -> V_59 ,
V_10 + V_5 ) )
V_5 += V_54 ;
V_37 = F_56 ( V_59 -> V_59 , V_10 , V_64 ,
V_5 , V_9 -> V_32 | V_59 -> V_32 ) ;
if ( V_37 )
return V_37 ;
V_10 += V_5 ;
}
}
return 0 ;
}
static int F_65 ( void * V_91 ,
struct V_92 * V_92 )
{
struct V_2 * V_3 = V_91 ;
struct V_93 * V_94 , * V_95 ;
struct V_58 * V_59 , * V_60 ;
struct V_88 * V_89 = NULL ;
int V_37 ;
F_50 ( & V_3 -> V_67 ) ;
F_51 (d, &iommu->domain_list, next) {
F_51 (g, &d->group_list, next) {
if ( V_95 -> V_92 != V_92 )
continue;
F_52 ( & V_3 -> V_67 ) ;
return - V_73 ;
}
}
V_94 = F_60 ( sizeof( * V_94 ) , V_26 ) ;
V_59 = F_60 ( sizeof( * V_59 ) , V_26 ) ;
if ( ! V_94 || ! V_59 ) {
V_37 = - V_52 ;
goto V_96;
}
V_94 -> V_92 = V_92 ;
V_37 = F_66 ( V_92 , & V_89 , F_61 ) ;
if ( V_37 )
goto V_96;
V_59 -> V_59 = F_67 ( V_89 ) ;
if ( ! V_59 -> V_59 ) {
V_37 = - V_97 ;
goto V_96;
}
V_37 = F_68 ( V_59 -> V_59 , V_92 ) ;
if ( V_37 )
goto V_98;
F_69 ( & V_59 -> V_99 ) ;
F_70 ( & V_94 -> V_62 , & V_59 -> V_99 ) ;
if ( ! V_100 &&
! F_71 ( V_59 -> V_59 , V_101 ) ) {
F_39 ( L_2 ,
V_51 ) ;
V_37 = - V_102 ;
goto V_103;
}
if ( F_71 ( V_59 -> V_59 , V_104 ) )
V_59 -> V_32 |= V_105 ;
F_51 (d, &iommu->domain_list, next) {
if ( V_60 -> V_59 -> V_68 == V_59 -> V_59 -> V_68 &&
V_60 -> V_32 == V_59 -> V_32 ) {
F_72 ( V_59 -> V_59 , V_92 ) ;
if ( ! F_68 ( V_60 -> V_59 , V_92 ) ) {
F_70 ( & V_94 -> V_62 , & V_60 -> V_99 ) ;
F_73 ( V_59 -> V_59 ) ;
F_13 ( V_59 ) ;
F_52 ( & V_3 -> V_67 ) ;
return 0 ;
}
V_37 = F_68 ( V_59 -> V_59 , V_92 ) ;
if ( V_37 )
goto V_98;
}
}
V_37 = F_62 ( V_3 , V_59 ) ;
if ( V_37 )
goto V_103;
F_70 ( & V_59 -> V_62 , & V_3 -> V_61 ) ;
F_52 ( & V_3 -> V_67 ) ;
return 0 ;
V_103:
F_72 ( V_59 -> V_59 , V_92 ) ;
V_98:
F_73 ( V_59 -> V_59 ) ;
V_96:
F_13 ( V_59 ) ;
F_13 ( V_94 ) ;
F_52 ( & V_3 -> V_67 ) ;
return V_37 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_63 ( & V_3 -> V_8 ) ) )
F_48 ( V_3 , F_2 ( V_7 , struct V_1 , V_7 ) ) ;
}
static void F_75 ( void * V_91 ,
struct V_92 * V_92 )
{
struct V_2 * V_3 = V_91 ;
struct V_58 * V_59 ;
struct V_93 * V_94 ;
F_50 ( & V_3 -> V_67 ) ;
F_51 (domain, &iommu->domain_list, next) {
F_51 (group, &domain->group_list, next) {
if ( V_94 -> V_92 != V_92 )
continue;
F_72 ( V_59 -> V_59 , V_92 ) ;
F_76 ( & V_94 -> V_62 ) ;
F_13 ( V_94 ) ;
if ( F_77 ( & V_59 -> V_99 ) ) {
if ( F_78 ( & V_3 -> V_61 ) )
F_74 ( V_3 ) ;
F_73 ( V_59 -> V_59 ) ;
F_76 ( & V_59 -> V_62 ) ;
F_13 ( V_59 ) ;
}
goto V_106;
}
}
V_106:
F_52 ( & V_3 -> V_67 ) ;
}
static void * F_79 ( unsigned long V_107 )
{
struct V_2 * V_3 ;
if ( V_107 != V_108 && V_107 != V_109 )
return F_80 ( - V_73 ) ;
V_3 = F_60 ( sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
return F_80 ( - V_52 ) ;
F_69 ( & V_3 -> V_61 ) ;
V_3 -> V_8 = V_110 ;
F_81 ( & V_3 -> V_67 ) ;
V_3 -> V_74 = ( V_107 == V_109 ) ;
return V_3 ;
}
static void F_82 ( void * V_91 )
{
struct V_2 * V_3 = V_91 ;
struct V_58 * V_59 , * V_111 ;
struct V_93 * V_94 , * V_112 ;
F_74 ( V_3 ) ;
F_83 (domain, domain_tmp,
&iommu->domain_list, next) {
F_83 (group, group_tmp,
&domain->group_list, next) {
F_72 ( V_59 -> V_59 , V_94 -> V_92 ) ;
F_76 ( & V_94 -> V_62 ) ;
F_13 ( V_94 ) ;
}
F_73 ( V_59 -> V_59 ) ;
F_76 ( & V_59 -> V_62 ) ;
F_13 ( V_59 ) ;
}
F_13 ( V_3 ) ;
}
static int F_84 ( struct V_2 * V_3 )
{
struct V_58 * V_59 ;
int V_37 = 1 ;
F_50 ( & V_3 -> V_67 ) ;
F_51 (domain, &iommu->domain_list, next) {
if ( ! ( V_59 -> V_32 & V_105 ) ) {
V_37 = 0 ;
break;
}
}
F_52 ( & V_3 -> V_67 ) ;
return V_37 ;
}
static long F_85 ( void * V_91 ,
unsigned int V_113 , unsigned long V_107 )
{
struct V_2 * V_3 = V_91 ;
unsigned long V_114 ;
if ( V_113 == V_115 ) {
switch ( V_107 ) {
case V_108 :
case V_109 :
return 1 ;
case V_116 :
if ( ! V_3 )
return 0 ;
return F_84 ( V_3 ) ;
default:
return 0 ;
}
} else if ( V_113 == V_117 ) {
struct V_118 V_119 ;
V_114 = F_86 ( struct V_118 , V_120 ) ;
if ( F_87 ( & V_119 , ( void V_121 * ) V_107 , V_114 ) )
return - V_38 ;
if ( V_119 . V_122 < V_114 )
return - V_73 ;
V_119 . V_80 = 0 ;
V_119 . V_120 = F_49 ( V_3 ) ;
return F_88 ( ( void V_121 * ) V_107 , & V_119 , V_114 ) ;
} else if ( V_113 == V_123 ) {
struct V_78 V_79 ;
T_5 V_72 = V_82 |
V_81 ;
V_114 = F_86 ( struct V_78 , V_5 ) ;
if ( F_87 ( & V_79 , ( void V_121 * ) V_107 , V_114 ) )
return - V_38 ;
if ( V_79 . V_122 < V_114 || V_79 . V_80 & ~ V_72 )
return - V_73 ;
return F_59 ( V_3 , & V_79 ) ;
} else if ( V_113 == V_124 ) {
struct V_70 V_71 ;
long V_37 ;
V_114 = F_86 ( struct V_70 , V_5 ) ;
if ( F_87 ( & V_71 , ( void V_121 * ) V_107 , V_114 ) )
return - V_38 ;
if ( V_71 . V_122 < V_114 || V_71 . V_80 )
return - V_73 ;
V_37 = F_53 ( V_3 , & V_71 ) ;
if ( V_37 )
return V_37 ;
return F_88 ( ( void V_121 * ) V_107 , & V_71 , V_114 ) ;
}
return - V_125 ;
}
static int T_6 F_89 ( void )
{
return F_90 ( & V_126 ) ;
}
static void T_7 F_91 ( void )
{
F_92 ( & V_126 ) ;
}
