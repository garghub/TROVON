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
bool V_50 ;
if ( ! V_25 -> V_21 )
return - V_51 ;
V_37 = F_30 ( V_34 , V_32 , V_44 ) ;
if ( V_37 )
return V_37 ;
V_50 = F_20 ( * V_44 ) ;
if ( ! V_50 && ! V_47 && V_25 -> V_21 -> V_23 + 1 > V_45 ) {
F_27 ( * V_44 , V_32 ) ;
F_39 ( L_1 , V_52 ,
V_45 << V_42 ) ;
return - V_53 ;
}
if ( F_40 ( V_54 ) ) {
if ( ! V_50 )
F_14 ( 1 ) ;
return 1 ;
}
for ( V_49 = 1 , V_34 += V_55 ; V_49 < V_24 ; V_49 ++ , V_34 += V_55 ) {
unsigned long V_27 = 0 ;
V_37 = F_30 ( V_34 , V_32 , & V_27 ) ;
if ( V_37 )
break;
if ( V_27 != * V_44 + V_49 ||
V_50 != F_20 ( V_27 ) ) {
F_27 ( V_27 , V_32 ) ;
break;
}
if ( ! V_50 && ! V_47 &&
V_25 -> V_21 -> V_23 + V_49 + 1 > V_45 ) {
F_27 ( V_27 , V_32 ) ;
F_39 ( L_1 ,
V_52 , V_45 << V_42 ) ;
break;
}
}
if ( ! V_50 )
F_14 ( V_49 ) ;
return V_49 ;
}
static long F_41 ( unsigned long V_27 , long V_24 ,
int V_32 , bool V_56 )
{
unsigned long V_57 = 0 ;
long V_49 ;
for ( V_49 = 0 ; V_49 < V_24 ; V_49 ++ )
V_57 += F_27 ( V_27 ++ , V_32 ) ;
if ( V_56 )
F_14 ( - V_57 ) ;
return V_57 ;
}
static void F_42 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
T_1 V_10 = V_9 -> V_10 , V_58 = V_9 -> V_10 + V_9 -> V_5 ;
struct V_59 * V_60 , * V_61 ;
long V_57 = 0 ;
if ( ! V_9 -> V_5 )
return;
V_60 = V_61 = F_43 ( & V_3 -> V_62 ,
struct V_59 , V_63 ) ;
F_44 (d, &iommu->domain_list, next) {
F_45 ( V_61 -> V_60 , V_9 -> V_10 , V_9 -> V_5 ) ;
F_46 () ;
}
while ( V_10 < V_58 ) {
T_2 V_64 , V_65 ;
T_3 V_66 , V_63 ;
V_66 = F_47 ( V_60 -> V_60 , V_10 ) ;
if ( F_48 ( ! V_66 ) ) {
V_10 += V_55 ;
continue;
}
for ( V_65 = V_55 ;
! V_60 -> V_67 && V_10 + V_65 < V_58 ; V_65 += V_55 ) {
V_63 = F_47 ( V_60 -> V_60 , V_10 + V_65 ) ;
if ( V_63 != V_66 + V_65 )
break;
}
V_64 = F_45 ( V_60 -> V_60 , V_10 , V_65 ) ;
if ( F_48 ( ! V_64 ) )
break;
V_57 += F_41 ( V_66 >> V_42 ,
V_64 >> V_42 ,
V_9 -> V_32 , false ) ;
V_10 += V_64 ;
F_46 () ;
}
F_14 ( - V_57 ) ;
}
static void F_49 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
F_42 ( V_3 , V_9 ) ;
F_6 ( V_3 , V_9 ) ;
F_13 ( V_9 ) ;
}
static unsigned long F_50 ( struct V_2 * V_3 )
{
struct V_59 * V_60 ;
unsigned long V_68 = V_69 ;
F_51 ( & V_3 -> V_70 ) ;
F_52 (domain, &iommu->domain_list, next)
V_68 &= V_60 -> V_60 -> V_71 ;
F_53 ( & V_3 -> V_70 ) ;
if ( V_68 & ~ V_72 ) {
V_68 &= V_72 ;
V_68 |= V_55 ;
}
return V_68 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_73 * V_74 )
{
T_4 V_75 ;
struct V_1 * V_9 ;
T_2 V_64 = 0 ;
int V_37 = 0 ;
V_75 = ( ( T_4 ) 1 << F_55 ( F_50 ( V_3 ) ) ) - 1 ;
if ( V_74 -> V_10 & V_75 )
return - V_76 ;
if ( ! V_74 -> V_5 || V_74 -> V_5 & V_75 )
return - V_76 ;
F_48 ( V_75 & V_72 ) ;
F_51 ( & V_3 -> V_70 ) ;
if ( V_3 -> V_77 ) {
V_9 = F_1 ( V_3 , V_74 -> V_10 , 0 ) ;
if ( V_9 && V_9 -> V_10 != V_74 -> V_10 ) {
V_37 = - V_76 ;
goto V_78;
}
V_9 = F_1 ( V_3 , V_74 -> V_10 + V_74 -> V_5 - 1 , 0 ) ;
if ( V_9 && V_9 -> V_10 + V_9 -> V_5 != V_74 -> V_10 + V_74 -> V_5 ) {
V_37 = - V_76 ;
goto V_78;
}
}
while ( ( V_9 = F_1 ( V_3 , V_74 -> V_10 , V_74 -> V_5 ) ) ) {
if ( ! V_3 -> V_77 && V_74 -> V_10 > V_9 -> V_10 )
break;
V_64 += V_9 -> V_5 ;
F_49 ( V_3 , V_9 ) ;
}
V_78:
F_53 ( & V_3 -> V_70 ) ;
V_74 -> V_5 = V_64 ;
return V_37 ;
}
static int F_56 ( struct V_59 * V_60 , T_1 V_10 ,
unsigned long V_27 , long V_24 , int V_32 )
{
long V_49 ;
int V_37 = 0 ;
for ( V_49 = 0 ; V_49 < V_24 ; V_49 ++ , V_27 ++ , V_10 += V_55 ) {
V_37 = F_57 ( V_60 -> V_60 , V_10 ,
( T_3 ) V_27 << V_42 ,
V_55 , V_32 | V_60 -> V_32 ) ;
if ( V_37 )
break;
}
for (; V_49 < V_24 && V_49 > 0 ; V_49 -- , V_10 -= V_55 )
F_45 ( V_60 -> V_60 , V_10 , V_55 ) ;
return V_37 ;
}
static int F_58 ( struct V_2 * V_3 , T_1 V_10 ,
unsigned long V_27 , long V_24 , int V_32 )
{
struct V_59 * V_61 ;
int V_37 ;
F_52 (d, &iommu->domain_list, next) {
V_37 = F_57 ( V_61 -> V_60 , V_10 , ( T_3 ) V_27 << V_42 ,
V_24 << V_42 , V_32 | V_61 -> V_32 ) ;
if ( V_37 ) {
if ( V_37 != - V_79 ||
F_56 ( V_61 , V_10 , V_27 , V_24 , V_32 ) )
goto V_80;
}
F_46 () ;
}
return 0 ;
V_80:
F_59 (d, &iommu->domain_list, next)
F_45 ( V_61 -> V_60 , V_10 , V_24 << V_42 ) ;
return V_37 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_81 * V_82 )
{
T_1 V_10 = V_82 -> V_10 ;
unsigned long V_34 = V_82 -> V_34 ;
T_2 V_5 = V_82 -> V_5 ;
long V_24 ;
int V_37 = 0 , V_32 = 0 ;
T_4 V_75 ;
struct V_1 * V_9 ;
unsigned long V_27 ;
if ( V_82 -> V_5 != V_5 || V_82 -> V_34 != V_34 || V_82 -> V_10 != V_10 )
return - V_76 ;
V_75 = ( ( T_4 ) 1 << F_55 ( F_50 ( V_3 ) ) ) - 1 ;
F_48 ( V_75 & V_72 ) ;
if ( V_82 -> V_83 & V_84 )
V_32 |= V_33 ;
if ( V_82 -> V_83 & V_85 )
V_32 |= V_86 ;
if ( ! V_32 || ! V_5 || ( V_5 | V_10 | V_34 ) & V_75 )
return - V_76 ;
if ( V_10 + V_5 - 1 < V_10 || V_34 + V_5 - 1 < V_34 )
return - V_76 ;
F_51 ( & V_3 -> V_70 ) ;
if ( F_1 ( V_3 , V_10 , V_5 ) ) {
F_53 ( & V_3 -> V_70 ) ;
return - V_87 ;
}
V_9 = F_61 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 ) {
F_53 ( & V_3 -> V_70 ) ;
return - V_53 ;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_32 = V_32 ;
F_3 ( V_3 , V_9 ) ;
while ( V_5 ) {
V_24 = F_36 ( V_34 + V_9 -> V_5 ,
V_5 >> V_42 , V_32 , & V_27 ) ;
if ( V_24 <= 0 ) {
F_48 ( ! V_24 ) ;
V_37 = ( int ) V_24 ;
break;
}
V_37 = F_58 ( V_3 , V_10 + V_9 -> V_5 , V_27 , V_24 , V_32 ) ;
if ( V_37 ) {
F_41 ( V_27 , V_24 , V_32 , true ) ;
break;
}
V_5 -= V_24 << V_42 ;
V_9 -> V_5 += V_24 << V_42 ;
}
if ( V_37 )
F_49 ( V_3 , V_9 ) ;
F_53 ( & V_3 -> V_70 ) ;
return V_37 ;
}
static int F_62 ( struct V_88 * V_89 , void * V_90 )
{
struct V_91 * * V_92 = V_90 ;
if ( * V_92 && * V_92 != V_89 -> V_92 )
return - V_76 ;
* V_92 = V_89 -> V_92 ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_59 * V_61 ;
struct V_6 * V_93 ;
int V_37 ;
V_61 = F_43 ( & V_3 -> V_62 , struct V_59 , V_63 ) ;
V_93 = F_64 ( & V_3 -> V_8 ) ;
if ( F_48 ( V_93 && ! V_61 ) )
return - V_76 ;
for (; V_93 ; V_93 = F_65 ( V_93 ) ) {
struct V_1 * V_9 ;
T_1 V_10 ;
V_9 = F_2 ( V_93 , struct V_1 , V_7 ) ;
V_10 = V_9 -> V_10 ;
while ( V_10 < V_9 -> V_10 + V_9 -> V_5 ) {
T_3 V_66 = F_47 ( V_61 -> V_60 , V_10 ) ;
T_2 V_5 ;
if ( F_48 ( ! V_66 ) ) {
V_10 += V_55 ;
continue;
}
V_5 = V_55 ;
while ( V_10 + V_5 < V_9 -> V_10 + V_9 -> V_5 &&
V_66 + V_5 == F_47 ( V_61 -> V_60 ,
V_10 + V_5 ) )
V_5 += V_55 ;
V_37 = F_57 ( V_60 -> V_60 , V_10 , V_66 ,
V_5 , V_9 -> V_32 | V_60 -> V_32 ) ;
if ( V_37 )
return V_37 ;
V_10 += V_5 ;
}
}
return 0 ;
}
static void F_66 ( struct V_59 * V_60 )
{
struct V_29 * V_94 ;
int V_37 , V_95 = F_67 ( V_55 * 2 ) ;
V_94 = F_68 ( V_26 | V_96 , V_95 ) ;
if ( ! V_94 )
return;
V_37 = F_57 ( V_60 -> V_60 , 0 , F_69 ( V_94 ) , V_55 * 2 ,
V_86 | V_33 | V_60 -> V_32 ) ;
if ( ! V_37 ) {
T_2 V_64 = F_45 ( V_60 -> V_60 , 0 , V_55 ) ;
if ( V_64 == V_55 )
F_45 ( V_60 -> V_60 , V_55 , V_55 ) ;
else
V_60 -> V_67 = true ;
}
F_70 ( V_94 , V_95 ) ;
}
static int F_71 ( void * V_97 ,
struct V_98 * V_98 )
{
struct V_2 * V_3 = V_97 ;
struct V_99 * V_100 , * V_101 ;
struct V_59 * V_60 , * V_61 ;
struct V_91 * V_92 = NULL ;
int V_37 ;
F_51 ( & V_3 -> V_70 ) ;
F_52 (d, &iommu->domain_list, next) {
F_52 (g, &d->group_list, next) {
if ( V_101 -> V_98 != V_98 )
continue;
F_53 ( & V_3 -> V_70 ) ;
return - V_76 ;
}
}
V_100 = F_61 ( sizeof( * V_100 ) , V_26 ) ;
V_60 = F_61 ( sizeof( * V_60 ) , V_26 ) ;
if ( ! V_100 || ! V_60 ) {
V_37 = - V_53 ;
goto V_102;
}
V_100 -> V_98 = V_98 ;
V_37 = F_72 ( V_98 , & V_92 , F_62 ) ;
if ( V_37 )
goto V_102;
V_60 -> V_60 = F_73 ( V_92 ) ;
if ( ! V_60 -> V_60 ) {
V_37 = - V_103 ;
goto V_102;
}
if ( V_3 -> V_104 ) {
int V_105 = 1 ;
V_37 = F_74 ( V_60 -> V_60 , V_106 ,
& V_105 ) ;
if ( V_37 )
goto V_107;
}
V_37 = F_75 ( V_60 -> V_60 , V_98 ) ;
if ( V_37 )
goto V_107;
F_76 ( & V_60 -> V_108 ) ;
F_77 ( & V_100 -> V_63 , & V_60 -> V_108 ) ;
if ( ! V_109 &&
! F_78 ( V_92 , V_110 ) ) {
F_39 ( L_2 ,
V_52 ) ;
V_37 = - V_111 ;
goto V_112;
}
if ( F_78 ( V_92 , V_113 ) )
V_60 -> V_32 |= V_114 ;
F_52 (d, &iommu->domain_list, next) {
if ( V_61 -> V_60 -> V_115 == V_60 -> V_60 -> V_115 &&
V_61 -> V_32 == V_60 -> V_32 ) {
F_79 ( V_60 -> V_60 , V_98 ) ;
if ( ! F_75 ( V_61 -> V_60 , V_98 ) ) {
F_77 ( & V_100 -> V_63 , & V_61 -> V_108 ) ;
F_80 ( V_60 -> V_60 ) ;
F_13 ( V_60 ) ;
F_53 ( & V_3 -> V_70 ) ;
return 0 ;
}
V_37 = F_75 ( V_60 -> V_60 , V_98 ) ;
if ( V_37 )
goto V_107;
}
}
F_66 ( V_60 ) ;
V_37 = F_63 ( V_3 , V_60 ) ;
if ( V_37 )
goto V_112;
F_77 ( & V_60 -> V_63 , & V_3 -> V_62 ) ;
F_53 ( & V_3 -> V_70 ) ;
return 0 ;
V_112:
F_79 ( V_60 -> V_60 , V_98 ) ;
V_107:
F_80 ( V_60 -> V_60 ) ;
V_102:
F_13 ( V_60 ) ;
F_13 ( V_100 ) ;
F_53 ( & V_3 -> V_70 ) ;
return V_37 ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_64 ( & V_3 -> V_8 ) ) )
F_49 ( V_3 , F_2 ( V_7 , struct V_1 , V_7 ) ) ;
}
static void F_82 ( void * V_97 ,
struct V_98 * V_98 )
{
struct V_2 * V_3 = V_97 ;
struct V_59 * V_60 ;
struct V_99 * V_100 ;
F_51 ( & V_3 -> V_70 ) ;
F_52 (domain, &iommu->domain_list, next) {
F_52 (group, &domain->group_list, next) {
if ( V_100 -> V_98 != V_98 )
continue;
F_79 ( V_60 -> V_60 , V_98 ) ;
F_83 ( & V_100 -> V_63 ) ;
F_13 ( V_100 ) ;
if ( F_84 ( & V_60 -> V_108 ) ) {
if ( F_85 ( & V_3 -> V_62 ) )
F_81 ( V_3 ) ;
F_80 ( V_60 -> V_60 ) ;
F_83 ( & V_60 -> V_63 ) ;
F_13 ( V_60 ) ;
}
goto V_116;
}
}
V_116:
F_53 ( & V_3 -> V_70 ) ;
}
static void * F_86 ( unsigned long V_117 )
{
struct V_2 * V_3 ;
V_3 = F_61 ( sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
return F_87 ( - V_53 ) ;
switch ( V_117 ) {
case V_118 :
break;
case V_119 :
V_3 -> V_104 = true ;
case V_120 :
V_3 -> V_77 = true ;
break;
default:
F_13 ( V_3 ) ;
return F_87 ( - V_76 ) ;
}
F_76 ( & V_3 -> V_62 ) ;
V_3 -> V_8 = V_121 ;
F_88 ( & V_3 -> V_70 ) ;
return V_3 ;
}
static void F_89 ( void * V_97 )
{
struct V_2 * V_3 = V_97 ;
struct V_59 * V_60 , * V_122 ;
struct V_99 * V_100 , * V_123 ;
F_81 ( V_3 ) ;
F_90 (domain, domain_tmp,
&iommu->domain_list, next) {
F_90 (group, group_tmp,
&domain->group_list, next) {
F_79 ( V_60 -> V_60 , V_100 -> V_98 ) ;
F_83 ( & V_100 -> V_63 ) ;
F_13 ( V_100 ) ;
}
F_80 ( V_60 -> V_60 ) ;
F_83 ( & V_60 -> V_63 ) ;
F_13 ( V_60 ) ;
}
F_13 ( V_3 ) ;
}
static int F_91 ( struct V_2 * V_3 )
{
struct V_59 * V_60 ;
int V_37 = 1 ;
F_51 ( & V_3 -> V_70 ) ;
F_52 (domain, &iommu->domain_list, next) {
if ( ! ( V_60 -> V_32 & V_114 ) ) {
V_37 = 0 ;
break;
}
}
F_53 ( & V_3 -> V_70 ) ;
return V_37 ;
}
static long F_92 ( void * V_97 ,
unsigned int V_124 , unsigned long V_117 )
{
struct V_2 * V_3 = V_97 ;
unsigned long V_125 ;
if ( V_124 == V_126 ) {
switch ( V_117 ) {
case V_118 :
case V_120 :
case V_119 :
return 1 ;
case V_127 :
if ( ! V_3 )
return 0 ;
return F_91 ( V_3 ) ;
default:
return 0 ;
}
} else if ( V_124 == V_128 ) {
struct V_129 V_130 ;
V_125 = F_93 ( struct V_129 , V_131 ) ;
if ( F_94 ( & V_130 , ( void V_132 * ) V_117 , V_125 ) )
return - V_38 ;
if ( V_130 . V_133 < V_125 )
return - V_76 ;
V_130 . V_83 = V_134 ;
V_130 . V_131 = F_50 ( V_3 ) ;
return F_95 ( ( void V_132 * ) V_117 , & V_130 , V_125 ) ?
- V_38 : 0 ;
} else if ( V_124 == V_135 ) {
struct V_81 V_82 ;
T_5 V_75 = V_85 |
V_84 ;
V_125 = F_93 ( struct V_81 , V_5 ) ;
if ( F_94 ( & V_82 , ( void V_132 * ) V_117 , V_125 ) )
return - V_38 ;
if ( V_82 . V_133 < V_125 || V_82 . V_83 & ~ V_75 )
return - V_76 ;
return F_60 ( V_3 , & V_82 ) ;
} else if ( V_124 == V_136 ) {
struct V_73 V_74 ;
long V_37 ;
V_125 = F_93 ( struct V_73 , V_5 ) ;
if ( F_94 ( & V_74 , ( void V_132 * ) V_117 , V_125 ) )
return - V_38 ;
if ( V_74 . V_133 < V_125 || V_74 . V_83 )
return - V_76 ;
V_37 = F_54 ( V_3 , & V_74 ) ;
if ( V_37 )
return V_37 ;
return F_95 ( ( void V_132 * ) V_117 , & V_74 , V_125 ) ?
- V_38 : 0 ;
}
return - V_137 ;
}
static int T_6 F_96 ( void )
{
return F_97 ( & V_138 ) ;
}
static void T_7 F_98 ( void )
{
F_99 ( & V_138 ) ;
}
