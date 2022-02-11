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
static struct V_17 * F_8 ( struct V_1 * V_9 , T_1 V_10 )
{
struct V_17 * V_18 ;
struct V_6 * V_7 = V_9 -> V_19 . V_6 ;
while ( V_7 ) {
V_18 = F_2 ( V_7 , struct V_17 , V_7 ) ;
if ( V_10 < V_18 -> V_10 )
V_7 = V_7 -> V_11 ;
else if ( V_10 > V_18 -> V_10 )
V_7 = V_7 -> V_12 ;
else
return V_18 ;
}
return NULL ;
}
static void F_9 ( struct V_1 * V_9 ,
struct V_17 * V_13 )
{
struct V_6 * * V_14 , * V_15 = NULL ;
struct V_17 * V_18 ;
V_14 = & V_9 -> V_19 . V_6 ;
while ( * V_14 ) {
V_15 = * V_14 ;
V_18 = F_2 ( V_15 , struct V_17 , V_7 ) ;
if ( V_13 -> V_10 < V_18 -> V_10 )
V_14 = & ( * V_14 ) -> V_11 ;
else
V_14 = & ( * V_14 ) -> V_12 ;
}
F_4 ( & V_13 -> V_7 , V_15 , V_14 ) ;
F_5 ( & V_13 -> V_7 , & V_9 -> V_19 ) ;
}
static void F_10 ( struct V_1 * V_9 , struct V_17 * V_16 )
{
F_7 ( & V_16 -> V_7 , & V_9 -> V_19 ) ;
}
static int F_11 ( struct V_1 * V_9 , T_1 V_10 ,
unsigned long V_20 )
{
struct V_17 * V_18 ;
V_18 = F_12 ( sizeof( * V_18 ) , V_21 ) ;
if ( ! V_18 )
return - V_22 ;
V_18 -> V_10 = V_10 ;
V_18 -> V_20 = V_20 ;
F_13 ( & V_18 -> V_23 , 1 ) ;
F_9 ( V_9 , V_18 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_9 ,
struct V_17 * V_18 )
{
F_10 ( V_9 , V_18 ) ;
F_15 ( V_18 ) ;
}
static struct V_17 * F_16 ( struct V_1 * V_9 ,
unsigned long V_10 )
{
struct V_17 * V_18 = F_8 ( V_9 , V_10 ) ;
if ( V_18 )
F_17 ( & V_18 -> V_23 ) ;
return V_18 ;
}
static int F_18 ( struct V_1 * V_9 , struct V_17 * V_18 )
{
int V_24 = 0 ;
if ( F_19 ( & V_18 -> V_23 ) ) {
V_24 = F_20 ( V_18 -> V_20 , V_9 -> V_25 ) ;
F_14 ( V_9 , V_18 ) ;
}
return V_24 ;
}
static void F_21 ( struct V_26 * V_27 )
{
struct V_28 * V_28 = F_22 ( V_27 , struct V_28 , V_27 ) ;
struct V_29 * V_30 ;
V_30 = V_28 -> V_30 ;
F_23 ( & V_30 -> V_31 ) ;
V_30 -> V_32 += V_28 -> V_33 ;
F_24 ( & V_30 -> V_31 ) ;
F_25 ( V_30 ) ;
F_15 ( V_28 ) ;
}
static void F_26 ( struct V_34 * V_35 , long V_33 )
{
struct V_28 * V_28 ;
struct V_29 * V_30 ;
bool V_36 ;
if ( ! V_33 )
return;
V_36 = ( V_35 -> V_30 == V_37 -> V_30 ) ;
V_30 = V_36 ? V_35 -> V_30 : F_27 ( V_35 ) ;
if ( ! V_30 )
return;
if ( F_28 ( & V_30 -> V_31 ) ) {
V_30 -> V_32 += V_33 ;
F_24 ( & V_30 -> V_31 ) ;
if ( ! V_36 )
F_25 ( V_30 ) ;
return;
}
if ( V_36 ) {
V_30 = F_27 ( V_35 ) ;
if ( ! V_30 )
return;
}
V_28 = F_29 ( sizeof( struct V_28 ) , V_21 ) ;
if ( F_30 ( ! V_28 ) ) {
F_25 ( V_30 ) ;
return;
}
F_31 ( & V_28 -> V_27 , F_21 ) ;
V_28 -> V_30 = V_30 ;
V_28 -> V_33 = V_33 ;
F_32 ( & V_28 -> V_27 ) ;
}
static bool F_33 ( unsigned long V_20 )
{
if ( F_34 ( V_20 ) ) {
bool V_38 ;
struct V_39 * V_40 = F_35 ( V_20 ) ;
struct V_39 * V_41 = F_36 ( V_40 ) ;
V_38 = ! ! ( F_37 ( V_41 ) ) ;
if ( V_41 != V_40 ) {
F_38 () ;
if ( F_39 ( V_40 ) )
return V_38 ;
}
return F_37 ( V_40 ) ;
}
return true ;
}
static int F_20 ( unsigned long V_20 , int V_25 )
{
if ( ! F_33 ( V_20 ) ) {
struct V_39 * V_39 = F_35 ( V_20 ) ;
if ( V_25 & V_42 )
F_40 ( V_39 ) ;
F_41 ( V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_29 * V_30 , unsigned long V_43 ,
int V_25 , unsigned long * V_20 )
{
struct V_39 * V_39 [ 1 ] ;
struct V_44 * V_45 ;
int V_24 ;
if ( V_30 == V_37 -> V_30 ) {
V_24 = F_43 ( V_43 , 1 , ! ! ( V_25 & V_42 ) ,
V_39 ) ;
} else {
unsigned int V_46 = 0 ;
if ( V_25 & V_42 )
V_46 |= V_47 ;
F_44 ( & V_30 -> V_31 ) ;
V_24 = F_45 ( NULL , V_30 , V_43 , 1 , V_46 , V_39 ,
NULL , NULL ) ;
F_46 ( & V_30 -> V_31 ) ;
}
if ( V_24 == 1 ) {
* V_20 = F_47 ( V_39 [ 0 ] ) ;
return 0 ;
}
F_44 ( & V_30 -> V_31 ) ;
V_45 = F_48 ( V_30 , V_43 , V_43 + 1 ) ;
if ( V_45 && V_45 -> V_48 & V_49 ) {
* V_20 = ( ( V_43 - V_45 -> V_50 ) >> V_51 ) + V_45 -> V_52 ;
if ( F_33 ( * V_20 ) )
V_24 = 0 ;
}
F_46 ( & V_30 -> V_31 ) ;
return V_24 ;
}
static long F_49 ( struct V_1 * V_9 , unsigned long V_43 ,
long V_33 , unsigned long * V_53 )
{
unsigned long V_54 = F_50 ( V_55 ) >> V_51 ;
bool V_56 = F_51 ( V_57 ) ;
long V_24 , V_58 = 0 , V_59 = 0 ;
bool V_60 ;
T_1 V_10 = V_43 - V_9 -> V_43 + V_9 -> V_10 ;
if ( ! V_37 -> V_30 )
return - V_61 ;
V_24 = F_42 ( V_37 -> V_30 , V_43 , V_9 -> V_25 , V_53 ) ;
if ( V_24 )
return V_24 ;
V_58 ++ ;
V_60 = F_33 ( * V_53 ) ;
if ( ! V_60 && ! F_8 ( V_9 , V_10 ) ) {
if ( ! V_56 && V_37 -> V_30 -> V_32 + 1 > V_54 ) {
F_20 ( * V_53 , V_9 -> V_25 ) ;
F_52 ( L_1 , V_62 ,
V_54 << V_51 ) ;
return - V_22 ;
}
V_59 ++ ;
}
if ( F_53 ( V_63 ) )
goto V_64;
for ( V_43 += V_65 , V_10 += V_65 ; V_58 < V_33 ;
V_58 ++ , V_43 += V_65 , V_10 += V_65 ) {
unsigned long V_20 = 0 ;
V_24 = F_42 ( V_37 -> V_30 , V_43 , V_9 -> V_25 , & V_20 ) ;
if ( V_24 )
break;
if ( V_20 != * V_53 + V_58 ||
V_60 != F_33 ( V_20 ) ) {
F_20 ( V_20 , V_9 -> V_25 ) ;
break;
}
if ( ! V_60 && ! F_8 ( V_9 , V_10 ) ) {
if ( ! V_56 &&
V_37 -> V_30 -> V_32 + V_59 + 1 > V_54 ) {
F_20 ( V_20 , V_9 -> V_25 ) ;
F_52 ( L_1 ,
V_62 , V_54 << V_51 ) ;
break;
}
V_59 ++ ;
}
}
V_64:
F_26 ( V_37 , V_59 ) ;
return V_58 ;
}
static long F_54 ( struct V_1 * V_9 , T_1 V_10 ,
unsigned long V_20 , long V_33 ,
bool V_66 )
{
long V_67 = 0 , V_68 = 0 ;
long V_69 ;
for ( V_69 = 0 ; V_69 < V_33 ; V_69 ++ , V_10 += V_65 ) {
if ( F_20 ( V_20 ++ , V_9 -> V_25 ) ) {
V_67 ++ ;
if ( F_8 ( V_9 , V_10 ) )
V_68 ++ ;
}
}
if ( V_66 )
F_26 ( V_9 -> V_35 , V_68 - V_67 ) ;
return V_67 ;
}
static int F_55 ( struct V_1 * V_9 , unsigned long V_43 ,
unsigned long * V_53 , bool V_66 )
{
unsigned long V_54 ;
bool V_56 = F_56 ( V_9 -> V_35 , V_57 ) ;
struct V_29 * V_30 ;
int V_24 ;
bool V_60 ;
V_30 = F_27 ( V_9 -> V_35 ) ;
if ( ! V_30 )
return - V_61 ;
V_24 = F_42 ( V_30 , V_43 , V_9 -> V_25 , V_53 ) ;
if ( V_24 )
goto V_70;
V_60 = F_33 ( * V_53 ) ;
V_54 = F_57 ( V_9 -> V_35 , V_55 ) >> V_51 ;
if ( ! V_60 && ! V_56 && V_30 -> V_32 + 1 > V_54 ) {
F_20 ( * V_53 , V_9 -> V_25 ) ;
F_52 ( L_2 ,
V_62 , V_9 -> V_35 -> V_71 , F_58 ( V_9 -> V_35 ) ,
V_54 << V_51 ) ;
V_24 = - V_22 ;
goto V_70;
}
if ( ! V_60 && V_66 )
F_26 ( V_9 -> V_35 , 1 ) ;
V_24 = 1 ;
V_70:
F_25 ( V_30 ) ;
return V_24 ;
}
static int F_59 ( struct V_1 * V_9 , T_1 V_10 ,
bool V_66 )
{
int V_67 ;
struct V_17 * V_18 = F_8 ( V_9 , V_10 ) ;
if ( ! V_18 )
return 0 ;
V_67 = F_18 ( V_9 , V_18 ) ;
if ( V_66 )
F_26 ( V_9 -> V_35 , - V_67 ) ;
return V_67 ;
}
static int F_60 ( void * V_72 ,
unsigned long * V_73 ,
int V_33 , int V_25 ,
unsigned long * V_74 )
{
struct V_2 * V_3 = V_72 ;
int V_69 , V_75 , V_24 ;
unsigned long V_76 ;
struct V_1 * V_9 ;
bool V_66 ;
if ( ! V_3 || ! V_73 || ! V_74 )
return - V_77 ;
if ( ! V_3 -> V_78 )
return - V_79 ;
F_61 ( & V_3 -> V_80 ) ;
if ( ( ! V_3 -> V_81 ) || ( ! V_3 -> V_82 . V_41 ) ) {
V_24 = - V_77 ;
goto V_83;
}
V_66 = ! F_62 ( V_3 ) ;
for ( V_69 = 0 ; V_69 < V_33 ; V_69 ++ ) {
T_1 V_10 ;
struct V_17 * V_18 ;
V_10 = V_73 [ V_69 ] << V_51 ;
V_9 = F_1 ( V_3 , V_10 , V_65 ) ;
if ( ! V_9 ) {
V_24 = - V_77 ;
goto V_84;
}
if ( ( V_9 -> V_25 & V_25 ) != V_25 ) {
V_24 = - V_85 ;
goto V_84;
}
V_18 = F_16 ( V_9 , V_10 ) ;
if ( V_18 ) {
V_74 [ V_69 ] = V_18 -> V_20 ;
continue;
}
V_76 = V_9 -> V_43 + V_10 - V_9 -> V_10 ;
V_24 = F_55 ( V_9 , V_76 , & V_74 [ V_69 ] ,
V_66 ) ;
if ( V_24 <= 0 ) {
F_30 ( ! V_24 ) ;
goto V_84;
}
V_24 = F_11 ( V_9 , V_10 , V_74 [ V_69 ] ) ;
if ( V_24 ) {
F_59 ( V_9 , V_10 , V_66 ) ;
goto V_84;
}
}
V_24 = V_69 ;
goto V_83;
V_84:
V_74 [ V_69 ] = 0 ;
for ( V_75 = 0 ; V_75 < V_69 ; V_75 ++ ) {
T_1 V_10 ;
V_10 = V_73 [ V_75 ] << V_51 ;
V_9 = F_1 ( V_3 , V_10 , V_65 ) ;
F_59 ( V_9 , V_10 , V_66 ) ;
V_74 [ V_75 ] = 0 ;
}
V_83:
F_63 ( & V_3 -> V_80 ) ;
return V_24 ;
}
static int F_64 ( void * V_72 ,
unsigned long * V_73 ,
int V_33 )
{
struct V_2 * V_3 = V_72 ;
bool V_66 ;
int V_69 ;
if ( ! V_3 || ! V_73 )
return - V_77 ;
if ( ! V_3 -> V_78 )
return - V_79 ;
F_61 ( & V_3 -> V_80 ) ;
if ( ! V_3 -> V_81 ) {
F_63 ( & V_3 -> V_80 ) ;
return - V_77 ;
}
V_66 = ! F_62 ( V_3 ) ;
for ( V_69 = 0 ; V_69 < V_33 ; V_69 ++ ) {
struct V_1 * V_9 ;
T_1 V_10 ;
V_10 = V_73 [ V_69 ] << V_51 ;
V_9 = F_1 ( V_3 , V_10 , V_65 ) ;
if ( ! V_9 )
goto V_86;
F_59 ( V_9 , V_10 , V_66 ) ;
}
V_86:
F_63 ( & V_3 -> V_80 ) ;
return V_69 > V_33 ? V_33 : ( V_69 > 0 ? V_69 : - V_77 ) ;
}
static long F_65 ( struct V_2 * V_3 , struct V_1 * V_9 ,
bool V_66 )
{
T_1 V_10 = V_9 -> V_10 , V_87 = V_9 -> V_10 + V_9 -> V_5 ;
struct V_88 * V_89 , * V_90 ;
long V_67 = 0 ;
if ( ! V_9 -> V_5 )
return 0 ;
if ( ! F_62 ( V_3 ) )
return 0 ;
V_89 = V_90 = F_66 ( & V_3 -> V_91 ,
struct V_88 , V_92 ) ;
F_67 (d, &iommu->domain_list, next) {
F_68 ( V_90 -> V_89 , V_9 -> V_10 , V_9 -> V_5 ) ;
F_69 () ;
}
while ( V_10 < V_87 ) {
T_2 V_93 , V_94 ;
T_3 V_95 , V_92 ;
V_95 = F_70 ( V_89 -> V_89 , V_10 ) ;
if ( F_30 ( ! V_95 ) ) {
V_10 += V_65 ;
continue;
}
for ( V_94 = V_65 ;
! V_89 -> V_96 && V_10 + V_94 < V_87 ; V_94 += V_65 ) {
V_92 = F_70 ( V_89 -> V_89 , V_10 + V_94 ) ;
if ( V_92 != V_95 + V_94 )
break;
}
V_93 = F_68 ( V_89 -> V_89 , V_10 , V_94 ) ;
if ( F_30 ( ! V_93 ) )
break;
V_67 += F_54 ( V_9 , V_10 ,
V_95 >> V_51 ,
V_93 >> V_51 ,
false ) ;
V_10 += V_93 ;
F_69 () ;
}
V_9 -> V_97 = false ;
if ( V_66 ) {
F_26 ( V_9 -> V_35 , - V_67 ) ;
return 0 ;
}
return V_67 ;
}
static void F_71 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
F_65 ( V_3 , V_9 , true ) ;
F_6 ( V_3 , V_9 ) ;
F_72 ( V_9 -> V_35 ) ;
F_15 ( V_9 ) ;
}
static unsigned long F_73 ( struct V_2 * V_3 )
{
struct V_88 * V_89 ;
unsigned long V_98 = V_99 ;
F_61 ( & V_3 -> V_80 ) ;
F_74 (domain, &iommu->domain_list, next)
V_98 &= V_89 -> V_89 -> V_100 ;
F_63 ( & V_3 -> V_80 ) ;
if ( V_98 & ~ V_101 ) {
V_98 &= V_101 ;
V_98 |= V_65 ;
}
return V_98 ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_102 * V_103 )
{
T_4 V_104 ;
struct V_1 * V_9 , * V_105 = NULL ;
T_2 V_93 = 0 ;
int V_24 = 0 , V_106 = 0 ;
V_104 = ( ( T_4 ) 1 << F_76 ( F_73 ( V_3 ) ) ) - 1 ;
if ( V_103 -> V_10 & V_104 )
return - V_77 ;
if ( ! V_103 -> V_5 || V_103 -> V_5 & V_104 )
return - V_77 ;
F_30 ( V_104 & V_101 ) ;
V_107:
F_61 ( & V_3 -> V_80 ) ;
if ( V_3 -> V_78 ) {
V_9 = F_1 ( V_3 , V_103 -> V_10 , 1 ) ;
if ( V_9 && V_9 -> V_10 != V_103 -> V_10 ) {
V_24 = - V_77 ;
goto V_108;
}
V_9 = F_1 ( V_3 , V_103 -> V_10 + V_103 -> V_5 - 1 , 0 ) ;
if ( V_9 && V_9 -> V_10 + V_9 -> V_5 != V_103 -> V_10 + V_103 -> V_5 ) {
V_24 = - V_77 ;
goto V_108;
}
}
while ( ( V_9 = F_1 ( V_3 , V_103 -> V_10 , V_103 -> V_5 ) ) ) {
if ( ! V_3 -> V_78 && V_103 -> V_10 > V_9 -> V_10 )
break;
if ( V_9 -> V_35 -> V_30 != V_37 -> V_30 )
break;
if ( ! F_77 ( & V_9 -> V_19 ) ) {
struct V_102 V_109 ;
if ( V_105 == V_9 ) {
F_78 ( ++ V_106 > 10 ) ;
} else {
V_105 = V_9 ;
V_106 = 0 ;
}
V_109 . V_10 = V_9 -> V_10 ;
V_109 . V_5 = V_9 -> V_5 ;
F_63 ( & V_3 -> V_80 ) ;
F_79 ( & V_3 -> V_82 ,
V_110 ,
& V_109 ) ;
goto V_107;
}
V_93 += V_9 -> V_5 ;
F_71 ( V_3 , V_9 ) ;
}
V_108:
F_63 ( & V_3 -> V_80 ) ;
V_103 -> V_5 = V_93 ;
return V_24 ;
}
static int F_80 ( struct V_88 * V_89 , T_1 V_10 ,
unsigned long V_20 , long V_33 , int V_25 )
{
long V_69 ;
int V_24 = 0 ;
for ( V_69 = 0 ; V_69 < V_33 ; V_69 ++ , V_20 ++ , V_10 += V_65 ) {
V_24 = F_81 ( V_89 -> V_89 , V_10 ,
( T_3 ) V_20 << V_51 ,
V_65 , V_25 | V_89 -> V_25 ) ;
if ( V_24 )
break;
}
for (; V_69 < V_33 && V_69 > 0 ; V_69 -- , V_10 -= V_65 )
F_68 ( V_89 -> V_89 , V_10 , V_65 ) ;
return V_24 ;
}
static int F_82 ( struct V_2 * V_3 , T_1 V_10 ,
unsigned long V_20 , long V_33 , int V_25 )
{
struct V_88 * V_90 ;
int V_24 ;
F_74 (d, &iommu->domain_list, next) {
V_24 = F_81 ( V_90 -> V_89 , V_10 , ( T_3 ) V_20 << V_51 ,
V_33 << V_51 , V_25 | V_90 -> V_25 ) ;
if ( V_24 ) {
if ( V_24 != - V_111 ||
F_80 ( V_90 , V_10 , V_20 , V_33 , V_25 ) )
goto V_112;
}
F_69 () ;
}
return 0 ;
V_112:
F_83 (d, &iommu->domain_list, next)
F_68 ( V_90 -> V_89 , V_10 , V_33 << V_51 ) ;
return V_24 ;
}
static int F_84 ( struct V_2 * V_3 , struct V_1 * V_9 ,
T_2 V_113 )
{
T_1 V_10 = V_9 -> V_10 ;
unsigned long V_43 = V_9 -> V_43 ;
T_2 V_5 = V_113 ;
long V_33 ;
unsigned long V_20 ;
int V_24 = 0 ;
while ( V_5 ) {
V_33 = F_49 ( V_9 , V_43 + V_9 -> V_5 ,
V_5 >> V_51 , & V_20 ) ;
if ( V_33 <= 0 ) {
F_30 ( ! V_33 ) ;
V_24 = ( int ) V_33 ;
break;
}
V_24 = F_82 ( V_3 , V_10 + V_9 -> V_5 , V_20 , V_33 ,
V_9 -> V_25 ) ;
if ( V_24 ) {
F_54 ( V_9 , V_10 + V_9 -> V_5 , V_20 ,
V_33 , true ) ;
break;
}
V_5 -= V_33 << V_51 ;
V_9 -> V_5 += V_33 << V_51 ;
}
V_9 -> V_97 = true ;
if ( V_24 )
F_71 ( V_3 , V_9 ) ;
return V_24 ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_114 * V_115 )
{
T_1 V_10 = V_115 -> V_10 ;
unsigned long V_43 = V_115 -> V_43 ;
T_2 V_5 = V_115 -> V_5 ;
int V_24 = 0 , V_25 = 0 ;
T_4 V_104 ;
struct V_1 * V_9 ;
if ( V_115 -> V_5 != V_5 || V_115 -> V_43 != V_43 || V_115 -> V_10 != V_10 )
return - V_77 ;
V_104 = ( ( T_4 ) 1 << F_76 ( F_73 ( V_3 ) ) ) - 1 ;
F_30 ( V_104 & V_101 ) ;
if ( V_115 -> V_46 & V_116 )
V_25 |= V_42 ;
if ( V_115 -> V_46 & V_117 )
V_25 |= V_118 ;
if ( ! V_25 || ! V_5 || ( V_5 | V_10 | V_43 ) & V_104 )
return - V_77 ;
if ( V_10 + V_5 - 1 < V_10 || V_43 + V_5 - 1 < V_43 )
return - V_77 ;
F_61 ( & V_3 -> V_80 ) ;
if ( F_1 ( V_3 , V_10 , V_5 ) ) {
V_24 = - V_119 ;
goto V_120;
}
V_9 = F_12 ( sizeof( * V_9 ) , V_21 ) ;
if ( ! V_9 ) {
V_24 = - V_22 ;
goto V_120;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_43 = V_43 ;
V_9 -> V_25 = V_25 ;
F_86 ( V_37 ) ;
V_9 -> V_35 = V_37 ;
V_9 -> V_19 = V_121 ;
F_3 ( V_3 , V_9 ) ;
if ( ! F_62 ( V_3 ) )
V_9 -> V_5 = V_5 ;
else
V_24 = F_84 ( V_3 , V_9 , V_5 ) ;
V_120:
F_63 ( & V_3 -> V_80 ) ;
return V_24 ;
}
static int F_87 ( struct V_122 * V_123 , void * V_124 )
{
struct V_125 * * V_126 = V_124 ;
if ( * V_126 && * V_126 != V_123 -> V_126 )
return - V_77 ;
* V_126 = V_123 -> V_126 ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 ,
struct V_88 * V_89 )
{
struct V_88 * V_90 ;
struct V_6 * V_127 ;
int V_24 ;
V_90 = F_66 ( & V_3 -> V_91 , struct V_88 , V_92 ) ;
V_127 = F_89 ( & V_3 -> V_8 ) ;
for (; V_127 ; V_127 = F_90 ( V_127 ) ) {
struct V_1 * V_9 ;
T_1 V_10 ;
V_9 = F_2 ( V_127 , struct V_1 , V_7 ) ;
V_10 = V_9 -> V_10 ;
while ( V_10 < V_9 -> V_10 + V_9 -> V_5 ) {
T_3 V_95 ;
T_2 V_5 ;
if ( V_9 -> V_97 ) {
T_3 V_128 ;
T_1 V_69 ;
V_95 = F_70 ( V_90 -> V_89 , V_10 ) ;
if ( F_30 ( ! V_95 ) ) {
V_10 += V_65 ;
continue;
}
V_5 = V_65 ;
V_128 = V_95 + V_5 ;
V_69 = V_10 + V_5 ;
while ( V_69 < V_9 -> V_10 + V_9 -> V_5 &&
V_128 == F_70 ( V_90 -> V_89 , V_69 ) ) {
V_5 += V_65 ;
V_128 += V_65 ;
V_69 += V_65 ;
}
} else {
unsigned long V_20 ;
unsigned long V_43 = V_9 -> V_43 +
( V_10 - V_9 -> V_10 ) ;
T_2 V_127 = V_9 -> V_10 + V_9 -> V_5 - V_10 ;
long V_33 ;
V_33 = F_49 ( V_9 , V_43 ,
V_127 >> V_51 ,
& V_20 ) ;
if ( V_33 <= 0 ) {
F_30 ( ! V_33 ) ;
V_24 = ( int ) V_33 ;
return V_24 ;
}
V_95 = V_20 << V_51 ;
V_5 = V_33 << V_51 ;
}
V_24 = F_81 ( V_89 -> V_89 , V_10 , V_95 ,
V_5 , V_9 -> V_25 | V_89 -> V_25 ) ;
if ( V_24 )
return V_24 ;
V_10 += V_5 ;
}
V_9 -> V_97 = true ;
}
return 0 ;
}
static void F_91 ( struct V_88 * V_89 )
{
struct V_39 * V_129 ;
int V_24 , V_130 = F_92 ( V_65 * 2 ) ;
V_129 = F_93 ( V_21 | V_131 , V_130 ) ;
if ( ! V_129 )
return;
V_24 = F_81 ( V_89 -> V_89 , 0 , F_94 ( V_129 ) , V_65 * 2 ,
V_118 | V_42 | V_89 -> V_25 ) ;
if ( ! V_24 ) {
T_2 V_93 = F_68 ( V_89 -> V_89 , 0 , V_65 ) ;
if ( V_93 == V_65 )
F_68 ( V_89 -> V_89 , V_65 , V_65 ) ;
else
V_89 -> V_96 = true ;
}
F_95 ( V_129 , V_130 ) ;
}
static struct V_132 * F_96 ( struct V_88 * V_89 ,
struct V_133 * V_133 )
{
struct V_132 * V_134 ;
F_74 (g, &domain->group_list, next) {
if ( V_134 -> V_133 == V_133 )
return V_134 ;
}
return NULL ;
}
static bool F_97 ( struct V_133 * V_135 , T_3 * V_136 )
{
struct V_137 V_138 ;
struct V_139 * V_140 , * V_92 ;
bool V_24 = false ;
F_98 ( & V_138 ) ;
F_99 ( V_135 , & V_138 ) ;
F_74 (region, &group_resv_regions, list) {
if ( V_140 -> type == V_141 ) {
* V_136 = V_140 -> V_4 ;
V_24 = true ;
goto V_64;
}
}
V_64:
F_100 (region, next, &group_resv_regions, list)
F_15 ( V_140 ) ;
return V_24 ;
}
static int F_101 ( void * V_72 ,
struct V_133 * V_133 )
{
struct V_2 * V_3 = V_72 ;
struct V_132 * V_135 ;
struct V_88 * V_89 , * V_90 ;
struct V_125 * V_126 = NULL , * V_142 ;
int V_24 ;
bool V_143 , V_144 ;
T_3 V_145 ;
F_61 ( & V_3 -> V_80 ) ;
F_74 (d, &iommu->domain_list, next) {
if ( F_96 ( V_90 , V_133 ) ) {
F_63 ( & V_3 -> V_80 ) ;
return - V_77 ;
}
}
if ( V_3 -> V_81 ) {
if ( F_96 ( V_3 -> V_81 , V_133 ) ) {
F_63 ( & V_3 -> V_80 ) ;
return - V_77 ;
}
}
V_135 = F_12 ( sizeof( * V_135 ) , V_21 ) ;
V_89 = F_12 ( sizeof( * V_89 ) , V_21 ) ;
if ( ! V_135 || ! V_89 ) {
V_24 = - V_22 ;
goto V_146;
}
V_135 -> V_133 = V_133 ;
V_24 = F_102 ( V_133 , & V_126 , F_87 ) ;
if ( V_24 )
goto V_146;
V_142 = F_103 ( V_147 ) ;
if ( V_142 ) {
if ( ( V_126 == V_142 ) && ! F_104 ( V_126 ) ) {
F_105 ( V_147 ) ;
if ( ! V_3 -> V_81 ) {
F_98 ( & V_89 -> V_148 ) ;
V_3 -> V_81 = V_89 ;
} else
F_15 ( V_89 ) ;
F_106 ( & V_135 -> V_92 ,
& V_3 -> V_81 -> V_148 ) ;
F_63 ( & V_3 -> V_80 ) ;
return 0 ;
}
F_105 ( V_147 ) ;
}
V_89 -> V_89 = F_107 ( V_126 ) ;
if ( ! V_89 -> V_89 ) {
V_24 = - V_149 ;
goto V_146;
}
if ( V_3 -> V_150 ) {
int V_151 = 1 ;
V_24 = F_108 ( V_89 -> V_89 , V_152 ,
& V_151 ) ;
if ( V_24 )
goto V_153;
}
V_24 = F_109 ( V_89 -> V_89 , V_133 ) ;
if ( V_24 )
goto V_153;
V_143 = F_97 ( V_133 , & V_145 ) ;
F_98 ( & V_89 -> V_148 ) ;
F_106 ( & V_135 -> V_92 , & V_89 -> V_148 ) ;
V_144 = V_143 ? F_110 () :
F_111 ( V_126 , V_154 ) ;
if ( ! V_155 && ! V_144 ) {
F_52 ( L_3 ,
V_62 ) ;
V_24 = - V_85 ;
goto V_156;
}
if ( F_111 ( V_126 , V_157 ) )
V_89 -> V_25 |= V_158 ;
F_74 (d, &iommu->domain_list, next) {
if ( V_90 -> V_89 -> V_159 == V_89 -> V_89 -> V_159 &&
V_90 -> V_25 == V_89 -> V_25 ) {
F_112 ( V_89 -> V_89 , V_133 ) ;
if ( ! F_109 ( V_90 -> V_89 , V_133 ) ) {
F_106 ( & V_135 -> V_92 , & V_90 -> V_148 ) ;
F_113 ( V_89 -> V_89 ) ;
F_15 ( V_89 ) ;
F_63 ( & V_3 -> V_80 ) ;
return 0 ;
}
V_24 = F_109 ( V_89 -> V_89 , V_133 ) ;
if ( V_24 )
goto V_153;
}
}
F_91 ( V_89 ) ;
V_24 = F_88 ( V_3 , V_89 ) ;
if ( V_24 )
goto V_156;
if ( V_143 ) {
V_24 = F_114 ( V_89 -> V_89 , V_145 ) ;
if ( V_24 )
goto V_156;
}
F_106 ( & V_89 -> V_92 , & V_3 -> V_91 ) ;
F_63 ( & V_3 -> V_80 ) ;
return 0 ;
V_156:
F_112 ( V_89 -> V_89 , V_133 ) ;
V_153:
F_113 ( V_89 -> V_89 ) ;
V_146:
F_15 ( V_89 ) ;
F_15 ( V_135 ) ;
F_63 ( & V_3 -> V_80 ) ;
return V_24 ;
}
static void F_115 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_89 ( & V_3 -> V_8 ) ) )
F_71 ( V_3 , F_2 ( V_7 , struct V_1 , V_7 ) ) ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_6 * V_127 , * V_128 ;
V_127 = F_89 ( & V_3 -> V_8 ) ;
for (; V_127 ; V_127 = F_90 ( V_127 ) ) {
struct V_1 * V_9 ;
long V_68 = 0 , V_67 = 0 ;
V_9 = F_2 ( V_127 , struct V_1 , V_7 ) ;
V_67 += F_65 ( V_3 , V_9 , false ) ;
V_128 = F_89 ( & V_9 -> V_19 ) ;
for (; V_128 ; V_128 = F_90 ( V_128 ) ) {
struct V_17 * V_18 = F_2 ( V_128 , struct V_17 ,
V_7 ) ;
if ( ! F_33 ( V_18 -> V_20 ) )
V_68 ++ ;
}
F_26 ( V_9 -> V_35 , V_68 - V_67 ) ;
}
}
static void F_117 ( struct V_2 * V_3 )
{
struct V_6 * V_127 ;
V_127 = F_89 ( & V_3 -> V_8 ) ;
for (; V_127 ; V_127 = F_90 ( V_127 ) ) {
struct V_1 * V_9 ;
V_9 = F_2 ( V_127 , struct V_1 , V_7 ) ;
if ( F_30 ( ! F_77 ( & V_9 -> V_19 ) ) )
break;
}
F_30 ( V_3 -> V_82 . V_41 ) ;
}
static void F_118 ( void * V_72 ,
struct V_133 * V_133 )
{
struct V_2 * V_3 = V_72 ;
struct V_88 * V_89 ;
struct V_132 * V_135 ;
F_61 ( & V_3 -> V_80 ) ;
if ( V_3 -> V_81 ) {
V_135 = F_96 ( V_3 -> V_81 , V_133 ) ;
if ( V_135 ) {
F_119 ( & V_135 -> V_92 ) ;
F_15 ( V_135 ) ;
if ( F_120 ( & V_3 -> V_81 -> V_148 ) ) {
F_117 ( V_3 ) ;
if ( ! F_62 ( V_3 ) )
F_115 ( V_3 ) ;
F_15 ( V_3 -> V_81 ) ;
V_3 -> V_81 = NULL ;
}
goto V_160;
}
}
F_74 (domain, &iommu->domain_list, next) {
V_135 = F_96 ( V_89 , V_133 ) ;
if ( ! V_135 )
continue;
F_112 ( V_89 -> V_89 , V_133 ) ;
F_119 ( & V_135 -> V_92 ) ;
F_15 ( V_135 ) ;
if ( F_120 ( & V_89 -> V_148 ) ) {
if ( F_121 ( & V_3 -> V_91 ) ) {
if ( ! V_3 -> V_81 )
F_115 ( V_3 ) ;
else
F_116 ( V_3 ) ;
}
F_113 ( V_89 -> V_89 ) ;
F_119 ( & V_89 -> V_92 ) ;
F_15 ( V_89 ) ;
}
break;
}
V_160:
F_63 ( & V_3 -> V_80 ) ;
}
static void * F_122 ( unsigned long V_161 )
{
struct V_2 * V_3 ;
V_3 = F_12 ( sizeof( * V_3 ) , V_21 ) ;
if ( ! V_3 )
return F_123 ( - V_22 ) ;
switch ( V_161 ) {
case V_162 :
break;
case V_163 :
V_3 -> V_150 = true ;
case V_164 :
V_3 -> V_78 = true ;
break;
default:
F_15 ( V_3 ) ;
return F_123 ( - V_77 ) ;
}
F_98 ( & V_3 -> V_91 ) ;
V_3 -> V_8 = V_121 ;
F_124 ( & V_3 -> V_80 ) ;
F_125 ( & V_3 -> V_82 ) ;
return V_3 ;
}
static void F_126 ( struct V_88 * V_89 , bool V_165 )
{
struct V_132 * V_135 , * V_166 ;
F_100 (group, group_tmp,
&domain->group_list, next) {
if ( ! V_165 )
F_112 ( V_89 -> V_89 , V_135 -> V_133 ) ;
F_119 ( & V_135 -> V_92 ) ;
F_15 ( V_135 ) ;
}
if ( ! V_165 )
F_113 ( V_89 -> V_89 ) ;
}
static void F_127 ( void * V_72 )
{
struct V_2 * V_3 = V_72 ;
struct V_88 * V_89 , * V_167 ;
if ( V_3 -> V_81 ) {
F_126 ( V_3 -> V_81 , true ) ;
F_117 ( V_3 ) ;
F_15 ( V_3 -> V_81 ) ;
}
F_115 ( V_3 ) ;
F_100 (domain, domain_tmp,
&iommu->domain_list, next) {
F_126 ( V_89 , false ) ;
F_119 ( & V_89 -> V_92 ) ;
F_15 ( V_89 ) ;
}
F_15 ( V_3 ) ;
}
static int F_128 ( struct V_2 * V_3 )
{
struct V_88 * V_89 ;
int V_24 = 1 ;
F_61 ( & V_3 -> V_80 ) ;
F_74 (domain, &iommu->domain_list, next) {
if ( ! ( V_89 -> V_25 & V_158 ) ) {
V_24 = 0 ;
break;
}
}
F_63 ( & V_3 -> V_80 ) ;
return V_24 ;
}
static long F_129 ( void * V_72 ,
unsigned int V_168 , unsigned long V_161 )
{
struct V_2 * V_3 = V_72 ;
unsigned long V_169 ;
if ( V_168 == V_170 ) {
switch ( V_161 ) {
case V_162 :
case V_164 :
case V_163 :
return 1 ;
case V_171 :
if ( ! V_3 )
return 0 ;
return F_128 ( V_3 ) ;
default:
return 0 ;
}
} else if ( V_168 == V_172 ) {
struct V_173 V_174 ;
V_169 = F_130 ( struct V_173 , V_175 ) ;
if ( F_131 ( & V_174 , ( void V_176 * ) V_161 , V_169 ) )
return - V_177 ;
if ( V_174 . V_178 < V_169 )
return - V_77 ;
V_174 . V_46 = V_179 ;
V_174 . V_175 = F_73 ( V_3 ) ;
return F_132 ( ( void V_176 * ) V_161 , & V_174 , V_169 ) ?
- V_177 : 0 ;
} else if ( V_168 == V_180 ) {
struct V_114 V_115 ;
T_5 V_104 = V_117 |
V_116 ;
V_169 = F_130 ( struct V_114 , V_5 ) ;
if ( F_131 ( & V_115 , ( void V_176 * ) V_161 , V_169 ) )
return - V_177 ;
if ( V_115 . V_178 < V_169 || V_115 . V_46 & ~ V_104 )
return - V_77 ;
return F_85 ( V_3 , & V_115 ) ;
} else if ( V_168 == V_181 ) {
struct V_102 V_103 ;
long V_24 ;
V_169 = F_130 ( struct V_102 , V_5 ) ;
if ( F_131 ( & V_103 , ( void V_176 * ) V_161 , V_169 ) )
return - V_177 ;
if ( V_103 . V_178 < V_169 || V_103 . V_46 )
return - V_77 ;
V_24 = F_75 ( V_3 , & V_103 ) ;
if ( V_24 )
return V_24 ;
return F_132 ( ( void V_176 * ) V_161 , & V_103 , V_169 ) ?
- V_177 : 0 ;
}
return - V_182 ;
}
static int F_133 ( void * V_72 ,
unsigned long * V_183 ,
struct V_184 * V_185 )
{
struct V_2 * V_3 = V_72 ;
* V_183 &= ~ V_110 ;
if ( * V_183 )
return - V_77 ;
return F_134 ( & V_3 -> V_82 , V_185 ) ;
}
static int F_135 ( void * V_72 ,
struct V_184 * V_185 )
{
struct V_2 * V_3 = V_72 ;
return F_136 ( & V_3 -> V_82 , V_185 ) ;
}
static int T_6 F_137 ( void )
{
return F_138 ( & V_186 ) ;
}
static void T_7 F_139 ( void )
{
F_140 ( & V_186 ) ;
}
