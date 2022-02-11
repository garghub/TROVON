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
static int F_21 ( struct V_26 * V_27 , long V_28 , bool * V_29 )
{
struct V_30 * V_31 ;
bool V_32 ;
int V_24 ;
if ( ! V_28 )
return 0 ;
V_32 = ( V_27 -> V_31 == V_33 -> V_31 ) ;
V_31 = V_32 ? V_27 -> V_31 : F_22 ( V_27 ) ;
if ( ! V_31 )
return - V_34 ;
V_24 = F_23 ( & V_31 -> V_35 ) ;
if ( ! V_24 ) {
if ( V_28 > 0 ) {
if ( V_29 ? ! * V_29 :
! F_24 ( V_27 , V_36 ) ) {
unsigned long V_37 ;
V_37 = F_25 ( V_27 ,
V_38 ) >> V_39 ;
if ( V_31 -> V_40 + V_28 > V_37 )
V_24 = - V_22 ;
}
}
if ( ! V_24 )
V_31 -> V_40 += V_28 ;
F_26 ( & V_31 -> V_35 ) ;
}
if ( ! V_32 )
F_27 ( V_31 ) ;
return V_24 ;
}
static bool F_28 ( unsigned long V_20 )
{
if ( F_29 ( V_20 ) ) {
bool V_41 ;
struct V_42 * V_43 = F_30 ( V_20 ) ;
struct V_42 * V_44 = F_31 ( V_43 ) ;
V_41 = ! ! ( F_32 ( V_44 ) ) ;
if ( V_44 != V_43 ) {
F_33 () ;
if ( F_34 ( V_43 ) )
return V_41 ;
}
return F_32 ( V_43 ) ;
}
return true ;
}
static int F_20 ( unsigned long V_20 , int V_25 )
{
if ( ! F_28 ( V_20 ) ) {
struct V_42 * V_42 = F_30 ( V_20 ) ;
if ( V_25 & V_45 )
F_35 ( V_42 ) ;
F_36 ( V_42 ) ;
return 1 ;
}
return 0 ;
}
static int F_37 ( struct V_30 * V_31 , unsigned long V_46 ,
int V_25 , unsigned long * V_20 )
{
struct V_42 * V_42 [ 1 ] ;
struct V_47 * V_48 ;
int V_24 ;
if ( V_31 == V_33 -> V_31 ) {
V_24 = F_38 ( V_46 , 1 , ! ! ( V_25 & V_45 ) ,
V_42 ) ;
} else {
unsigned int V_49 = 0 ;
if ( V_25 & V_45 )
V_49 |= V_50 ;
F_39 ( & V_31 -> V_35 ) ;
V_24 = F_40 ( NULL , V_31 , V_46 , 1 , V_49 , V_42 ,
NULL , NULL ) ;
F_41 ( & V_31 -> V_35 ) ;
}
if ( V_24 == 1 ) {
* V_20 = F_42 ( V_42 [ 0 ] ) ;
return 0 ;
}
F_39 ( & V_31 -> V_35 ) ;
V_48 = F_43 ( V_31 , V_46 , V_46 + 1 ) ;
if ( V_48 && V_48 -> V_51 & V_52 ) {
* V_20 = ( ( V_46 - V_48 -> V_53 ) >> V_39 ) + V_48 -> V_54 ;
if ( F_28 ( * V_20 ) )
V_24 = 0 ;
}
F_41 ( & V_31 -> V_35 ) ;
return V_24 ;
}
static long F_44 ( struct V_1 * V_9 , unsigned long V_46 ,
long V_28 , unsigned long * V_55 ,
bool V_29 , unsigned long V_37 )
{
unsigned long V_20 = 0 ;
long V_24 , V_56 = 0 , V_57 = 0 ;
bool V_58 ;
T_1 V_10 = V_46 - V_9 -> V_46 + V_9 -> V_10 ;
if ( ! V_33 -> V_31 )
return - V_59 ;
V_24 = F_37 ( V_33 -> V_31 , V_46 , V_9 -> V_25 , V_55 ) ;
if ( V_24 )
return V_24 ;
V_56 ++ ;
V_58 = F_28 ( * V_55 ) ;
if ( ! V_58 && ! F_8 ( V_9 , V_10 ) ) {
if ( ! V_29 && V_33 -> V_31 -> V_40 + 1 > V_37 ) {
F_20 ( * V_55 , V_9 -> V_25 ) ;
F_45 ( L_1 , V_60 ,
V_37 << V_39 ) ;
return - V_22 ;
}
V_57 ++ ;
}
if ( F_46 ( V_61 ) )
goto V_62;
for ( V_46 += V_63 , V_10 += V_63 ; V_56 < V_28 ;
V_56 ++ , V_46 += V_63 , V_10 += V_63 ) {
V_24 = F_37 ( V_33 -> V_31 , V_46 , V_9 -> V_25 , & V_20 ) ;
if ( V_24 )
break;
if ( V_20 != * V_55 + V_56 ||
V_58 != F_28 ( V_20 ) ) {
F_20 ( V_20 , V_9 -> V_25 ) ;
break;
}
if ( ! V_58 && ! F_8 ( V_9 , V_10 ) ) {
if ( ! V_29 &&
V_33 -> V_31 -> V_40 + V_57 + 1 > V_37 ) {
F_20 ( V_20 , V_9 -> V_25 ) ;
F_45 ( L_1 ,
V_60 , V_37 << V_39 ) ;
V_24 = - V_22 ;
goto V_64;
}
V_57 ++ ;
}
}
V_62:
V_24 = F_21 ( V_33 , V_57 , & V_29 ) ;
V_64:
if ( V_24 ) {
if ( ! V_58 ) {
for ( V_20 = * V_55 ; V_56 ; V_20 ++ , V_56 -- )
F_20 ( V_20 , V_9 -> V_25 ) ;
}
return V_24 ;
}
return V_56 ;
}
static long F_47 ( struct V_1 * V_9 , T_1 V_10 ,
unsigned long V_20 , long V_28 ,
bool V_65 )
{
long V_66 = 0 , V_67 = 0 ;
long V_68 ;
for ( V_68 = 0 ; V_68 < V_28 ; V_68 ++ , V_10 += V_63 ) {
if ( F_20 ( V_20 ++ , V_9 -> V_25 ) ) {
V_66 ++ ;
if ( F_8 ( V_9 , V_10 ) )
V_67 ++ ;
}
}
if ( V_65 )
F_21 ( V_9 -> V_27 , V_67 - V_66 , NULL ) ;
return V_66 ;
}
static int F_48 ( struct V_1 * V_9 , unsigned long V_46 ,
unsigned long * V_55 , bool V_65 )
{
struct V_30 * V_31 ;
int V_24 ;
V_31 = F_22 ( V_9 -> V_27 ) ;
if ( ! V_31 )
return - V_59 ;
V_24 = F_37 ( V_31 , V_46 , V_9 -> V_25 , V_55 ) ;
if ( ! V_24 && V_65 && ! F_28 ( * V_55 ) ) {
V_24 = F_21 ( V_9 -> V_27 , 1 , NULL ) ;
if ( V_24 ) {
F_20 ( * V_55 , V_9 -> V_25 ) ;
if ( V_24 == - V_22 )
F_45 ( L_2
L_3 , V_60 ,
V_9 -> V_27 -> V_69 , F_49 ( V_9 -> V_27 ) ,
F_25 ( V_9 -> V_27 , V_38 ) ) ;
}
}
F_27 ( V_31 ) ;
return V_24 ;
}
static int F_50 ( struct V_1 * V_9 , T_1 V_10 ,
bool V_65 )
{
int V_66 ;
struct V_17 * V_18 = F_8 ( V_9 , V_10 ) ;
if ( ! V_18 )
return 0 ;
V_66 = F_18 ( V_9 , V_18 ) ;
if ( V_65 )
F_21 ( V_9 -> V_27 , - V_66 , NULL ) ;
return V_66 ;
}
static int F_51 ( void * V_70 ,
unsigned long * V_71 ,
int V_28 , int V_25 ,
unsigned long * V_72 )
{
struct V_2 * V_3 = V_70 ;
int V_68 , V_73 , V_24 ;
unsigned long V_74 ;
struct V_1 * V_9 ;
bool V_65 ;
if ( ! V_3 || ! V_71 || ! V_72 )
return - V_75 ;
if ( ! V_3 -> V_76 )
return - V_77 ;
F_52 ( & V_3 -> V_78 ) ;
if ( ( ! V_3 -> V_79 ) || ( ! V_3 -> V_80 . V_44 ) ) {
V_24 = - V_75 ;
goto V_81;
}
V_65 = ! F_53 ( V_3 ) ;
for ( V_68 = 0 ; V_68 < V_28 ; V_68 ++ ) {
T_1 V_10 ;
struct V_17 * V_18 ;
V_10 = V_71 [ V_68 ] << V_39 ;
V_9 = F_1 ( V_3 , V_10 , V_63 ) ;
if ( ! V_9 ) {
V_24 = - V_75 ;
goto V_82;
}
if ( ( V_9 -> V_25 & V_25 ) != V_25 ) {
V_24 = - V_83 ;
goto V_82;
}
V_18 = F_16 ( V_9 , V_10 ) ;
if ( V_18 ) {
V_72 [ V_68 ] = V_18 -> V_20 ;
continue;
}
V_74 = V_9 -> V_46 + V_10 - V_9 -> V_10 ;
V_24 = F_48 ( V_9 , V_74 , & V_72 [ V_68 ] ,
V_65 ) ;
if ( V_24 )
goto V_82;
V_24 = F_11 ( V_9 , V_10 , V_72 [ V_68 ] ) ;
if ( V_24 ) {
F_50 ( V_9 , V_10 , V_65 ) ;
goto V_82;
}
}
V_24 = V_68 ;
goto V_81;
V_82:
V_72 [ V_68 ] = 0 ;
for ( V_73 = 0 ; V_73 < V_68 ; V_73 ++ ) {
T_1 V_10 ;
V_10 = V_71 [ V_73 ] << V_39 ;
V_9 = F_1 ( V_3 , V_10 , V_63 ) ;
F_50 ( V_9 , V_10 , V_65 ) ;
V_72 [ V_73 ] = 0 ;
}
V_81:
F_54 ( & V_3 -> V_78 ) ;
return V_24 ;
}
static int F_55 ( void * V_70 ,
unsigned long * V_71 ,
int V_28 )
{
struct V_2 * V_3 = V_70 ;
bool V_65 ;
int V_68 ;
if ( ! V_3 || ! V_71 )
return - V_75 ;
if ( ! V_3 -> V_76 )
return - V_77 ;
F_52 ( & V_3 -> V_78 ) ;
if ( ! V_3 -> V_79 ) {
F_54 ( & V_3 -> V_78 ) ;
return - V_75 ;
}
V_65 = ! F_53 ( V_3 ) ;
for ( V_68 = 0 ; V_68 < V_28 ; V_68 ++ ) {
struct V_1 * V_9 ;
T_1 V_10 ;
V_10 = V_71 [ V_68 ] << V_39 ;
V_9 = F_1 ( V_3 , V_10 , V_63 ) ;
if ( ! V_9 )
goto V_84;
F_50 ( V_9 , V_10 , V_65 ) ;
}
V_84:
F_54 ( & V_3 -> V_78 ) ;
return V_68 > V_28 ? V_28 : ( V_68 > 0 ? V_68 : - V_75 ) ;
}
static long F_56 ( struct V_2 * V_3 , struct V_1 * V_9 ,
bool V_65 )
{
T_1 V_10 = V_9 -> V_10 , V_85 = V_9 -> V_10 + V_9 -> V_5 ;
struct V_86 * V_87 , * V_88 ;
long V_66 = 0 ;
if ( ! V_9 -> V_5 )
return 0 ;
if ( ! F_53 ( V_3 ) )
return 0 ;
V_87 = V_88 = F_57 ( & V_3 -> V_89 ,
struct V_86 , V_90 ) ;
F_58 (d, &iommu->domain_list, next) {
F_59 ( V_88 -> V_87 , V_9 -> V_10 , V_9 -> V_5 ) ;
F_60 () ;
}
while ( V_10 < V_85 ) {
T_2 V_91 , V_92 ;
T_3 V_93 , V_90 ;
V_93 = F_61 ( V_87 -> V_87 , V_10 ) ;
if ( F_62 ( ! V_93 ) ) {
V_10 += V_63 ;
continue;
}
for ( V_92 = V_63 ;
! V_87 -> V_94 && V_10 + V_92 < V_85 ; V_92 += V_63 ) {
V_90 = F_61 ( V_87 -> V_87 , V_10 + V_92 ) ;
if ( V_90 != V_93 + V_92 )
break;
}
V_91 = F_59 ( V_87 -> V_87 , V_10 , V_92 ) ;
if ( F_62 ( ! V_91 ) )
break;
V_66 += F_47 ( V_9 , V_10 ,
V_93 >> V_39 ,
V_91 >> V_39 ,
false ) ;
V_10 += V_91 ;
F_60 () ;
}
V_9 -> V_95 = false ;
if ( V_65 ) {
F_21 ( V_9 -> V_27 , - V_66 , NULL ) ;
return 0 ;
}
return V_66 ;
}
static void F_63 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
F_56 ( V_3 , V_9 , true ) ;
F_6 ( V_3 , V_9 ) ;
F_64 ( V_9 -> V_27 ) ;
F_15 ( V_9 ) ;
}
static unsigned long F_65 ( struct V_2 * V_3 )
{
struct V_86 * V_87 ;
unsigned long V_96 = V_97 ;
F_52 ( & V_3 -> V_78 ) ;
F_66 (domain, &iommu->domain_list, next)
V_96 &= V_87 -> V_87 -> V_98 ;
F_54 ( & V_3 -> V_78 ) ;
if ( V_96 & ~ V_99 ) {
V_96 &= V_99 ;
V_96 |= V_63 ;
}
return V_96 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_100 * V_101 )
{
T_4 V_102 ;
struct V_1 * V_9 , * V_103 = NULL ;
T_2 V_91 = 0 ;
int V_24 = 0 , V_104 = 0 ;
V_102 = ( ( T_4 ) 1 << F_68 ( F_65 ( V_3 ) ) ) - 1 ;
if ( V_101 -> V_10 & V_102 )
return - V_75 ;
if ( ! V_101 -> V_5 || V_101 -> V_5 & V_102 )
return - V_75 ;
F_62 ( V_102 & V_99 ) ;
V_105:
F_52 ( & V_3 -> V_78 ) ;
if ( V_3 -> V_76 ) {
V_9 = F_1 ( V_3 , V_101 -> V_10 , 1 ) ;
if ( V_9 && V_9 -> V_10 != V_101 -> V_10 ) {
V_24 = - V_75 ;
goto V_106;
}
V_9 = F_1 ( V_3 , V_101 -> V_10 + V_101 -> V_5 - 1 , 0 ) ;
if ( V_9 && V_9 -> V_10 + V_9 -> V_5 != V_101 -> V_10 + V_101 -> V_5 ) {
V_24 = - V_75 ;
goto V_106;
}
}
while ( ( V_9 = F_1 ( V_3 , V_101 -> V_10 , V_101 -> V_5 ) ) ) {
if ( ! V_3 -> V_76 && V_101 -> V_10 > V_9 -> V_10 )
break;
if ( V_9 -> V_27 -> V_31 != V_33 -> V_31 )
break;
if ( ! F_69 ( & V_9 -> V_19 ) ) {
struct V_100 V_107 ;
if ( V_103 == V_9 ) {
F_70 ( ++ V_104 > 10 ) ;
} else {
V_103 = V_9 ;
V_104 = 0 ;
}
V_107 . V_10 = V_9 -> V_10 ;
V_107 . V_5 = V_9 -> V_5 ;
F_54 ( & V_3 -> V_78 ) ;
F_71 ( & V_3 -> V_80 ,
V_108 ,
& V_107 ) ;
goto V_105;
}
V_91 += V_9 -> V_5 ;
F_63 ( V_3 , V_9 ) ;
}
V_106:
F_54 ( & V_3 -> V_78 ) ;
V_101 -> V_5 = V_91 ;
return V_24 ;
}
static int F_72 ( struct V_86 * V_87 , T_1 V_10 ,
unsigned long V_20 , long V_28 , int V_25 )
{
long V_68 ;
int V_24 = 0 ;
for ( V_68 = 0 ; V_68 < V_28 ; V_68 ++ , V_20 ++ , V_10 += V_63 ) {
V_24 = F_73 ( V_87 -> V_87 , V_10 ,
( T_3 ) V_20 << V_39 ,
V_63 , V_25 | V_87 -> V_25 ) ;
if ( V_24 )
break;
}
for (; V_68 < V_28 && V_68 > 0 ; V_68 -- , V_10 -= V_63 )
F_59 ( V_87 -> V_87 , V_10 , V_63 ) ;
return V_24 ;
}
static int F_74 ( struct V_2 * V_3 , T_1 V_10 ,
unsigned long V_20 , long V_28 , int V_25 )
{
struct V_86 * V_88 ;
int V_24 ;
F_66 (d, &iommu->domain_list, next) {
V_24 = F_73 ( V_88 -> V_87 , V_10 , ( T_3 ) V_20 << V_39 ,
V_28 << V_39 , V_25 | V_88 -> V_25 ) ;
if ( V_24 ) {
if ( V_24 != - V_109 ||
F_72 ( V_88 , V_10 , V_20 , V_28 , V_25 ) )
goto V_110;
}
F_60 () ;
}
return 0 ;
V_110:
F_75 (d, &iommu->domain_list, next)
F_59 ( V_88 -> V_87 , V_10 , V_28 << V_39 ) ;
return V_24 ;
}
static int F_76 ( struct V_2 * V_3 , struct V_1 * V_9 ,
T_2 V_111 )
{
T_1 V_10 = V_9 -> V_10 ;
unsigned long V_46 = V_9 -> V_46 ;
T_2 V_5 = V_111 ;
long V_28 ;
unsigned long V_20 , V_37 = F_77 ( V_38 ) >> V_39 ;
bool V_29 = F_78 ( V_36 ) ;
int V_24 = 0 ;
while ( V_5 ) {
V_28 = F_44 ( V_9 , V_46 + V_9 -> V_5 ,
V_5 >> V_39 , & V_20 ,
V_29 , V_37 ) ;
if ( V_28 <= 0 ) {
F_62 ( ! V_28 ) ;
V_24 = ( int ) V_28 ;
break;
}
V_24 = F_74 ( V_3 , V_10 + V_9 -> V_5 , V_20 , V_28 ,
V_9 -> V_25 ) ;
if ( V_24 ) {
F_47 ( V_9 , V_10 + V_9 -> V_5 , V_20 ,
V_28 , true ) ;
break;
}
V_5 -= V_28 << V_39 ;
V_9 -> V_5 += V_28 << V_39 ;
}
V_9 -> V_95 = true ;
if ( V_24 )
F_63 ( V_3 , V_9 ) ;
return V_24 ;
}
static int F_79 ( struct V_2 * V_3 ,
struct V_112 * V_113 )
{
T_1 V_10 = V_113 -> V_10 ;
unsigned long V_46 = V_113 -> V_46 ;
T_2 V_5 = V_113 -> V_5 ;
int V_24 = 0 , V_25 = 0 ;
T_4 V_102 ;
struct V_1 * V_9 ;
if ( V_113 -> V_5 != V_5 || V_113 -> V_46 != V_46 || V_113 -> V_10 != V_10 )
return - V_75 ;
V_102 = ( ( T_4 ) 1 << F_68 ( F_65 ( V_3 ) ) ) - 1 ;
F_62 ( V_102 & V_99 ) ;
if ( V_113 -> V_49 & V_114 )
V_25 |= V_45 ;
if ( V_113 -> V_49 & V_115 )
V_25 |= V_116 ;
if ( ! V_25 || ! V_5 || ( V_5 | V_10 | V_46 ) & V_102 )
return - V_75 ;
if ( V_10 + V_5 - 1 < V_10 || V_46 + V_5 - 1 < V_46 )
return - V_75 ;
F_52 ( & V_3 -> V_78 ) ;
if ( F_1 ( V_3 , V_10 , V_5 ) ) {
V_24 = - V_117 ;
goto V_118;
}
V_9 = F_12 ( sizeof( * V_9 ) , V_21 ) ;
if ( ! V_9 ) {
V_24 = - V_22 ;
goto V_118;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_46 = V_46 ;
V_9 -> V_25 = V_25 ;
F_80 ( V_33 ) ;
V_9 -> V_27 = V_33 ;
V_9 -> V_19 = V_119 ;
F_3 ( V_3 , V_9 ) ;
if ( ! F_53 ( V_3 ) )
V_9 -> V_5 = V_5 ;
else
V_24 = F_76 ( V_3 , V_9 , V_5 ) ;
V_118:
F_54 ( & V_3 -> V_78 ) ;
return V_24 ;
}
static int F_81 ( struct V_120 * V_121 , void * V_122 )
{
struct V_123 * * V_124 = V_122 ;
if ( * V_124 && * V_124 != V_121 -> V_124 )
return - V_75 ;
* V_124 = V_121 -> V_124 ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_86 * V_87 )
{
struct V_86 * V_88 ;
struct V_6 * V_125 ;
unsigned long V_37 = F_77 ( V_38 ) >> V_39 ;
bool V_29 = F_78 ( V_36 ) ;
int V_24 ;
V_88 = F_57 ( & V_3 -> V_89 , struct V_86 , V_90 ) ;
V_125 = F_83 ( & V_3 -> V_8 ) ;
for (; V_125 ; V_125 = F_84 ( V_125 ) ) {
struct V_1 * V_9 ;
T_1 V_10 ;
V_9 = F_2 ( V_125 , struct V_1 , V_7 ) ;
V_10 = V_9 -> V_10 ;
while ( V_10 < V_9 -> V_10 + V_9 -> V_5 ) {
T_3 V_93 ;
T_2 V_5 ;
if ( V_9 -> V_95 ) {
T_3 V_126 ;
T_1 V_68 ;
V_93 = F_61 ( V_88 -> V_87 , V_10 ) ;
if ( F_62 ( ! V_93 ) ) {
V_10 += V_63 ;
continue;
}
V_5 = V_63 ;
V_126 = V_93 + V_5 ;
V_68 = V_10 + V_5 ;
while ( V_68 < V_9 -> V_10 + V_9 -> V_5 &&
V_126 == F_61 ( V_88 -> V_87 , V_68 ) ) {
V_5 += V_63 ;
V_126 += V_63 ;
V_68 += V_63 ;
}
} else {
unsigned long V_20 ;
unsigned long V_46 = V_9 -> V_46 +
( V_10 - V_9 -> V_10 ) ;
T_2 V_125 = V_9 -> V_10 + V_9 -> V_5 - V_10 ;
long V_28 ;
V_28 = F_44 ( V_9 , V_46 ,
V_125 >> V_39 ,
& V_20 , V_29 ,
V_37 ) ;
if ( V_28 <= 0 ) {
F_62 ( ! V_28 ) ;
V_24 = ( int ) V_28 ;
return V_24 ;
}
V_93 = V_20 << V_39 ;
V_5 = V_28 << V_39 ;
}
V_24 = F_73 ( V_87 -> V_87 , V_10 , V_93 ,
V_5 , V_9 -> V_25 | V_87 -> V_25 ) ;
if ( V_24 )
return V_24 ;
V_10 += V_5 ;
}
V_9 -> V_95 = true ;
}
return 0 ;
}
static void F_85 ( struct V_86 * V_87 )
{
struct V_42 * V_127 ;
int V_24 , V_128 = F_86 ( V_63 * 2 ) ;
V_127 = F_87 ( V_21 | V_129 , V_128 ) ;
if ( ! V_127 )
return;
V_24 = F_73 ( V_87 -> V_87 , 0 , F_88 ( V_127 ) , V_63 * 2 ,
V_116 | V_45 | V_87 -> V_25 ) ;
if ( ! V_24 ) {
T_2 V_91 = F_59 ( V_87 -> V_87 , 0 , V_63 ) ;
if ( V_91 == V_63 )
F_59 ( V_87 -> V_87 , V_63 , V_63 ) ;
else
V_87 -> V_94 = true ;
}
F_89 ( V_127 , V_128 ) ;
}
static struct V_130 * F_90 ( struct V_86 * V_87 ,
struct V_131 * V_131 )
{
struct V_130 * V_132 ;
F_66 (g, &domain->group_list, next) {
if ( V_132 -> V_131 == V_131 )
return V_132 ;
}
return NULL ;
}
static bool F_91 ( struct V_131 * V_133 , T_3 * V_134 )
{
struct V_135 V_136 ;
struct V_137 * V_138 , * V_90 ;
bool V_24 = false ;
F_92 ( & V_136 ) ;
F_93 ( V_133 , & V_136 ) ;
F_66 (region, &group_resv_regions, list) {
if ( V_138 -> type == V_139 ) {
* V_134 = V_138 -> V_4 ;
V_24 = true ;
goto V_62;
}
}
V_62:
F_94 (region, next, &group_resv_regions, list)
F_15 ( V_138 ) ;
return V_24 ;
}
static int F_95 ( void * V_70 ,
struct V_131 * V_131 )
{
struct V_2 * V_3 = V_70 ;
struct V_130 * V_133 ;
struct V_86 * V_87 , * V_88 ;
struct V_123 * V_124 = NULL , * V_140 ;
int V_24 ;
bool V_141 , V_142 ;
T_3 V_143 ;
F_52 ( & V_3 -> V_78 ) ;
F_66 (d, &iommu->domain_list, next) {
if ( F_90 ( V_88 , V_131 ) ) {
F_54 ( & V_3 -> V_78 ) ;
return - V_75 ;
}
}
if ( V_3 -> V_79 ) {
if ( F_90 ( V_3 -> V_79 , V_131 ) ) {
F_54 ( & V_3 -> V_78 ) ;
return - V_75 ;
}
}
V_133 = F_12 ( sizeof( * V_133 ) , V_21 ) ;
V_87 = F_12 ( sizeof( * V_87 ) , V_21 ) ;
if ( ! V_133 || ! V_87 ) {
V_24 = - V_22 ;
goto V_144;
}
V_133 -> V_131 = V_131 ;
V_24 = F_96 ( V_131 , & V_124 , F_81 ) ;
if ( V_24 )
goto V_144;
V_140 = F_97 ( V_145 ) ;
if ( V_140 ) {
if ( ( V_124 == V_140 ) && ! F_98 ( V_124 ) ) {
F_99 ( V_145 ) ;
if ( ! V_3 -> V_79 ) {
F_92 ( & V_87 -> V_146 ) ;
V_3 -> V_79 = V_87 ;
} else
F_15 ( V_87 ) ;
F_100 ( & V_133 -> V_90 ,
& V_3 -> V_79 -> V_146 ) ;
F_54 ( & V_3 -> V_78 ) ;
return 0 ;
}
F_99 ( V_145 ) ;
}
V_87 -> V_87 = F_101 ( V_124 ) ;
if ( ! V_87 -> V_87 ) {
V_24 = - V_147 ;
goto V_144;
}
if ( V_3 -> V_148 ) {
int V_149 = 1 ;
V_24 = F_102 ( V_87 -> V_87 , V_150 ,
& V_149 ) ;
if ( V_24 )
goto V_151;
}
V_24 = F_103 ( V_87 -> V_87 , V_131 ) ;
if ( V_24 )
goto V_151;
V_141 = F_91 ( V_131 , & V_143 ) ;
F_92 ( & V_87 -> V_146 ) ;
F_100 ( & V_133 -> V_90 , & V_87 -> V_146 ) ;
V_142 = V_141 ? F_104 () :
F_105 ( V_124 , V_152 ) ;
if ( ! V_153 && ! V_142 ) {
F_45 ( L_4 ,
V_60 ) ;
V_24 = - V_83 ;
goto V_154;
}
if ( F_105 ( V_124 , V_155 ) )
V_87 -> V_25 |= V_156 ;
F_66 (d, &iommu->domain_list, next) {
if ( V_88 -> V_87 -> V_157 == V_87 -> V_87 -> V_157 &&
V_88 -> V_25 == V_87 -> V_25 ) {
F_106 ( V_87 -> V_87 , V_131 ) ;
if ( ! F_103 ( V_88 -> V_87 , V_131 ) ) {
F_100 ( & V_133 -> V_90 , & V_88 -> V_146 ) ;
F_107 ( V_87 -> V_87 ) ;
F_15 ( V_87 ) ;
F_54 ( & V_3 -> V_78 ) ;
return 0 ;
}
V_24 = F_103 ( V_87 -> V_87 , V_131 ) ;
if ( V_24 )
goto V_151;
}
}
F_85 ( V_87 ) ;
V_24 = F_82 ( V_3 , V_87 ) ;
if ( V_24 )
goto V_154;
if ( V_141 ) {
V_24 = F_108 ( V_87 -> V_87 , V_143 ) ;
if ( V_24 )
goto V_154;
}
F_100 ( & V_87 -> V_90 , & V_3 -> V_89 ) ;
F_54 ( & V_3 -> V_78 ) ;
return 0 ;
V_154:
F_106 ( V_87 -> V_87 , V_131 ) ;
V_151:
F_107 ( V_87 -> V_87 ) ;
V_144:
F_15 ( V_87 ) ;
F_15 ( V_133 ) ;
F_54 ( & V_3 -> V_78 ) ;
return V_24 ;
}
static void F_109 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
while ( ( V_7 = F_83 ( & V_3 -> V_8 ) ) )
F_63 ( V_3 , F_2 ( V_7 , struct V_1 , V_7 ) ) ;
}
static void F_110 ( struct V_2 * V_3 )
{
struct V_6 * V_125 , * V_126 ;
V_125 = F_83 ( & V_3 -> V_8 ) ;
for (; V_125 ; V_125 = F_84 ( V_125 ) ) {
struct V_1 * V_9 ;
long V_67 = 0 , V_66 = 0 ;
V_9 = F_2 ( V_125 , struct V_1 , V_7 ) ;
V_66 += F_56 ( V_3 , V_9 , false ) ;
V_126 = F_83 ( & V_9 -> V_19 ) ;
for (; V_126 ; V_126 = F_84 ( V_126 ) ) {
struct V_17 * V_18 = F_2 ( V_126 , struct V_17 ,
V_7 ) ;
if ( ! F_28 ( V_18 -> V_20 ) )
V_67 ++ ;
}
F_21 ( V_9 -> V_27 , V_67 - V_66 , NULL ) ;
}
}
static void F_111 ( struct V_2 * V_3 )
{
struct V_6 * V_125 ;
V_125 = F_83 ( & V_3 -> V_8 ) ;
for (; V_125 ; V_125 = F_84 ( V_125 ) ) {
struct V_1 * V_9 ;
V_9 = F_2 ( V_125 , struct V_1 , V_7 ) ;
if ( F_62 ( ! F_69 ( & V_9 -> V_19 ) ) )
break;
}
F_62 ( V_3 -> V_80 . V_44 ) ;
}
static void F_112 ( void * V_70 ,
struct V_131 * V_131 )
{
struct V_2 * V_3 = V_70 ;
struct V_86 * V_87 ;
struct V_130 * V_133 ;
F_52 ( & V_3 -> V_78 ) ;
if ( V_3 -> V_79 ) {
V_133 = F_90 ( V_3 -> V_79 , V_131 ) ;
if ( V_133 ) {
F_113 ( & V_133 -> V_90 ) ;
F_15 ( V_133 ) ;
if ( F_114 ( & V_3 -> V_79 -> V_146 ) ) {
F_111 ( V_3 ) ;
if ( ! F_53 ( V_3 ) )
F_109 ( V_3 ) ;
F_15 ( V_3 -> V_79 ) ;
V_3 -> V_79 = NULL ;
}
goto V_158;
}
}
F_66 (domain, &iommu->domain_list, next) {
V_133 = F_90 ( V_87 , V_131 ) ;
if ( ! V_133 )
continue;
F_106 ( V_87 -> V_87 , V_131 ) ;
F_113 ( & V_133 -> V_90 ) ;
F_15 ( V_133 ) ;
if ( F_114 ( & V_87 -> V_146 ) ) {
if ( F_115 ( & V_3 -> V_89 ) ) {
if ( ! V_3 -> V_79 )
F_109 ( V_3 ) ;
else
F_110 ( V_3 ) ;
}
F_107 ( V_87 -> V_87 ) ;
F_113 ( & V_87 -> V_90 ) ;
F_15 ( V_87 ) ;
}
break;
}
V_158:
F_54 ( & V_3 -> V_78 ) ;
}
static void * F_116 ( unsigned long V_159 )
{
struct V_2 * V_3 ;
V_3 = F_12 ( sizeof( * V_3 ) , V_21 ) ;
if ( ! V_3 )
return F_117 ( - V_22 ) ;
switch ( V_159 ) {
case V_160 :
break;
case V_161 :
V_3 -> V_148 = true ;
case V_162 :
V_3 -> V_76 = true ;
break;
default:
F_15 ( V_3 ) ;
return F_117 ( - V_75 ) ;
}
F_92 ( & V_3 -> V_89 ) ;
V_3 -> V_8 = V_119 ;
F_118 ( & V_3 -> V_78 ) ;
F_119 ( & V_3 -> V_80 ) ;
return V_3 ;
}
static void F_120 ( struct V_86 * V_87 , bool V_163 )
{
struct V_130 * V_133 , * V_164 ;
F_94 (group, group_tmp,
&domain->group_list, next) {
if ( ! V_163 )
F_106 ( V_87 -> V_87 , V_133 -> V_131 ) ;
F_113 ( & V_133 -> V_90 ) ;
F_15 ( V_133 ) ;
}
if ( ! V_163 )
F_107 ( V_87 -> V_87 ) ;
}
static void F_121 ( void * V_70 )
{
struct V_2 * V_3 = V_70 ;
struct V_86 * V_87 , * V_165 ;
if ( V_3 -> V_79 ) {
F_120 ( V_3 -> V_79 , true ) ;
F_111 ( V_3 ) ;
F_15 ( V_3 -> V_79 ) ;
}
F_109 ( V_3 ) ;
F_94 (domain, domain_tmp,
&iommu->domain_list, next) {
F_120 ( V_87 , false ) ;
F_113 ( & V_87 -> V_90 ) ;
F_15 ( V_87 ) ;
}
F_15 ( V_3 ) ;
}
static int F_122 ( struct V_2 * V_3 )
{
struct V_86 * V_87 ;
int V_24 = 1 ;
F_52 ( & V_3 -> V_78 ) ;
F_66 (domain, &iommu->domain_list, next) {
if ( ! ( V_87 -> V_25 & V_156 ) ) {
V_24 = 0 ;
break;
}
}
F_54 ( & V_3 -> V_78 ) ;
return V_24 ;
}
static long F_123 ( void * V_70 ,
unsigned int V_166 , unsigned long V_159 )
{
struct V_2 * V_3 = V_70 ;
unsigned long V_167 ;
if ( V_166 == V_168 ) {
switch ( V_159 ) {
case V_160 :
case V_162 :
case V_161 :
return 1 ;
case V_169 :
if ( ! V_3 )
return 0 ;
return F_122 ( V_3 ) ;
default:
return 0 ;
}
} else if ( V_166 == V_170 ) {
struct V_171 V_172 ;
V_167 = F_124 ( struct V_171 , V_173 ) ;
if ( F_125 ( & V_172 , ( void V_174 * ) V_159 , V_167 ) )
return - V_175 ;
if ( V_172 . V_176 < V_167 )
return - V_75 ;
V_172 . V_49 = V_177 ;
V_172 . V_173 = F_65 ( V_3 ) ;
return F_126 ( ( void V_174 * ) V_159 , & V_172 , V_167 ) ?
- V_175 : 0 ;
} else if ( V_166 == V_178 ) {
struct V_112 V_113 ;
T_5 V_102 = V_115 |
V_114 ;
V_167 = F_124 ( struct V_112 , V_5 ) ;
if ( F_125 ( & V_113 , ( void V_174 * ) V_159 , V_167 ) )
return - V_175 ;
if ( V_113 . V_176 < V_167 || V_113 . V_49 & ~ V_102 )
return - V_75 ;
return F_79 ( V_3 , & V_113 ) ;
} else if ( V_166 == V_179 ) {
struct V_100 V_101 ;
long V_24 ;
V_167 = F_124 ( struct V_100 , V_5 ) ;
if ( F_125 ( & V_101 , ( void V_174 * ) V_159 , V_167 ) )
return - V_175 ;
if ( V_101 . V_176 < V_167 || V_101 . V_49 )
return - V_75 ;
V_24 = F_67 ( V_3 , & V_101 ) ;
if ( V_24 )
return V_24 ;
return F_126 ( ( void V_174 * ) V_159 , & V_101 , V_167 ) ?
- V_175 : 0 ;
}
return - V_180 ;
}
static int F_127 ( void * V_70 ,
unsigned long * V_181 ,
struct V_182 * V_183 )
{
struct V_2 * V_3 = V_70 ;
* V_181 &= ~ V_108 ;
if ( * V_181 )
return - V_75 ;
return F_128 ( & V_3 -> V_80 , V_183 ) ;
}
static int F_129 ( void * V_70 ,
struct V_182 * V_183 )
{
struct V_2 * V_3 = V_70 ;
return F_130 ( & V_3 -> V_80 , V_183 ) ;
}
static int T_6 F_131 ( void )
{
return F_132 ( & V_184 ) ;
}
static void T_7 F_133 ( void )
{
F_134 ( & V_184 ) ;
}
