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
static int F_42 ( struct V_2 * V_3 , struct V_1 * V_9 ,
T_1 V_10 , T_2 * V_5 )
{
T_1 V_4 = V_10 , V_57 = V_10 + * V_5 ;
long V_56 = 0 ;
while ( V_10 < V_57 ) {
T_2 V_58 ;
T_3 V_59 ;
V_59 = F_43 ( V_3 -> V_60 , V_10 ) ;
if ( F_44 ( ! V_59 ) ) {
V_10 += V_54 ;
continue;
}
V_58 = F_45 ( V_3 -> V_60 , V_10 , V_54 ) ;
if ( ! V_58 )
break;
V_56 += F_41 ( V_59 >> V_42 ,
V_58 >> V_42 ,
V_9 -> V_32 , false ) ;
V_10 += V_58 ;
}
F_14 ( - V_56 ) ;
* V_5 = V_10 - V_4 ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , T_1 V_4 ,
T_2 * V_5 , struct V_1 * V_9 )
{
T_2 V_61 , V_62 , V_63 ;
struct V_1 * V_64 ;
int V_37 ;
if ( ! * V_5 )
return 0 ;
if ( F_47 ( V_4 <= V_9 -> V_10 &&
V_4 + * V_5 >= V_9 -> V_10 + V_9 -> V_5 ) ) {
* V_5 = V_9 -> V_5 ;
V_37 = F_42 ( V_3 , V_9 , V_9 -> V_10 , V_5 ) ;
if ( V_37 )
return V_37 ;
F_44 ( * V_5 != V_9 -> V_5 ) ;
F_6 ( V_3 , V_9 ) ;
F_13 ( V_9 ) ;
return 0 ;
}
if ( V_4 <= V_9 -> V_10 ) {
V_62 = V_4 + * V_5 - V_9 -> V_10 ;
V_37 = F_42 ( V_3 , V_9 , V_9 -> V_10 , & V_62 ) ;
if ( V_37 )
return V_37 ;
F_6 ( V_3 , V_9 ) ;
if ( V_62 < V_9 -> V_5 ) {
V_9 -> V_10 += V_62 ;
V_9 -> V_34 += V_62 ;
V_9 -> V_5 -= V_62 ;
F_3 ( V_3 , V_9 ) ;
} else
F_13 ( V_9 ) ;
* V_5 = V_62 ;
return 0 ;
}
if ( V_4 + * V_5 >= V_9 -> V_10 + V_9 -> V_5 ) {
V_61 = V_4 - V_9 -> V_10 ;
V_62 = V_9 -> V_5 - V_61 ;
V_37 = F_42 ( V_3 , V_9 , V_4 , & V_62 ) ;
if ( V_37 )
return V_37 ;
V_9 -> V_5 -= V_62 ;
* V_5 = V_62 ;
return 0 ;
}
V_64 = F_48 ( sizeof( * V_64 ) , V_26 ) ;
if ( ! V_64 )
return - V_52 ;
V_61 = V_4 - V_9 -> V_10 ;
V_37 = F_42 ( V_3 , V_9 , V_4 , V_5 ) ;
if ( V_37 || ! * V_5 ) {
F_13 ( V_64 ) ;
return V_37 ;
}
V_63 = V_9 -> V_5 ;
V_9 -> V_5 = V_61 ;
if ( F_47 ( V_61 + * V_5 < V_63 ) ) {
V_64 -> V_5 = V_63 - V_61 - * V_5 ;
V_64 -> V_10 = V_9 -> V_10 + V_61 + * V_5 ;
V_64 -> V_34 = V_9 -> V_34 + V_61 + * V_5 ;
V_64 -> V_32 = V_9 -> V_32 ;
F_3 ( V_3 , V_64 ) ;
} else
F_13 ( V_64 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 ,
struct V_65 * V_66 )
{
T_4 V_67 ;
struct V_1 * V_9 ;
T_2 V_58 = 0 , V_5 ;
int V_37 = 0 ;
V_67 = ( ( T_4 ) 1 << F_50 ( V_3 -> V_60 -> V_68 -> V_69 ) ) - 1 ;
if ( V_66 -> V_10 & V_67 )
return - V_70 ;
if ( ! V_66 -> V_5 || V_66 -> V_5 & V_67 )
return - V_70 ;
F_44 ( V_67 & V_71 ) ;
F_51 ( & V_3 -> V_72 ) ;
while ( ( V_9 = F_1 ( V_3 , V_66 -> V_10 , V_66 -> V_5 ) ) ) {
V_5 = V_66 -> V_5 ;
V_37 = F_46 ( V_3 , V_66 -> V_10 , & V_5 , V_9 ) ;
if ( V_37 || ! V_5 )
break;
V_58 += V_5 ;
}
F_52 ( & V_3 -> V_72 ) ;
V_66 -> V_5 = V_58 ;
return V_37 ;
}
static int F_53 ( struct V_2 * V_3 , T_1 V_10 ,
unsigned long V_27 , long V_24 , int V_32 )
{
long V_49 ;
int V_37 ;
for ( V_49 = 0 ; V_49 < V_24 ; V_49 ++ , V_27 ++ , V_10 += V_54 ) {
V_37 = F_54 ( V_3 -> V_60 , V_10 ,
( T_3 ) V_27 << V_42 ,
V_54 , V_32 ) ;
if ( V_37 )
break;
}
for (; V_49 < V_24 && V_49 > 0 ; V_49 -- , V_10 -= V_54 )
F_45 ( V_3 -> V_60 , V_10 , V_54 ) ;
return V_37 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_73 * V_74 )
{
T_1 V_57 , V_10 ;
unsigned long V_34 = V_74 -> V_34 ;
T_2 V_5 = V_74 -> V_5 ;
long V_24 ;
int V_37 = 0 , V_32 = 0 ;
T_4 V_67 ;
struct V_1 * V_9 = NULL ;
unsigned long V_27 ;
V_57 = V_74 -> V_10 + V_74 -> V_5 ;
V_67 = ( ( T_4 ) 1 << F_50 ( V_3 -> V_60 -> V_68 -> V_69 ) ) - 1 ;
if ( V_74 -> V_75 & V_76 )
V_32 |= V_33 ;
if ( V_74 -> V_75 & V_77 )
V_32 |= V_78 ;
if ( ! V_32 )
return - V_70 ;
if ( V_3 -> V_79 )
V_32 |= V_80 ;
if ( V_34 & V_67 )
return - V_70 ;
if ( V_74 -> V_10 & V_67 )
return - V_70 ;
if ( ! V_74 -> V_5 || V_74 -> V_5 & V_67 )
return - V_70 ;
F_44 ( V_67 & V_71 ) ;
if ( V_57 && V_57 < V_74 -> V_10 )
return - V_70 ;
if ( V_34 + V_74 -> V_5 && V_34 + V_74 -> V_5 < V_34 )
return - V_70 ;
F_51 ( & V_3 -> V_72 ) ;
if ( F_1 ( V_3 , V_74 -> V_10 , V_74 -> V_5 ) ) {
F_52 ( & V_3 -> V_72 ) ;
return - V_81 ;
}
for ( V_10 = V_74 -> V_10 ; V_10 < V_57 ; V_10 += V_5 , V_34 += V_5 ) {
long V_49 ;
V_24 = F_36 ( V_34 , ( V_57 - V_10 ) >> V_42 ,
V_32 , & V_27 ) ;
if ( V_24 <= 0 ) {
F_44 ( ! V_24 ) ;
V_37 = ( int ) V_24 ;
goto V_82;
}
for ( V_49 = 0 ; V_49 < V_24 ; V_49 ++ ) {
if ( F_43 ( V_3 -> V_60 ,
V_10 + ( V_49 << V_42 ) ) ) {
V_37 = - V_83 ;
goto V_84;
}
}
V_37 = F_54 ( V_3 -> V_60 , V_10 ,
( T_3 ) V_27 << V_42 ,
V_24 << V_42 , V_32 ) ;
if ( V_37 ) {
if ( V_37 != - V_83 ||
F_53 ( V_3 , V_10 , V_27 , V_24 , V_32 ) ) {
goto V_84;
}
}
V_5 = V_24 << V_42 ;
if ( F_47 ( V_10 ) ) {
struct V_1 * V_63 ;
V_63 = F_1 ( V_3 , V_10 - 1 , 1 ) ;
if ( V_63 && V_63 -> V_32 == V_32 &&
V_63 -> V_34 + V_63 -> V_5 == V_34 ) {
V_63 -> V_5 += V_5 ;
V_10 = V_63 -> V_10 ;
V_5 = V_63 -> V_5 ;
V_34 = V_63 -> V_34 ;
V_9 = V_63 ;
}
}
if ( F_47 ( V_10 + V_5 ) ) {
struct V_1 * V_63 ;
V_63 = F_1 ( V_3 , V_10 + V_5 , 1 ) ;
if ( V_63 && V_63 -> V_32 == V_32 &&
V_63 -> V_34 == V_34 + V_5 ) {
F_6 ( V_3 , V_63 ) ;
if ( V_9 ) {
V_9 -> V_5 += V_63 -> V_5 ;
F_13 ( V_63 ) ;
} else {
V_5 += V_63 -> V_5 ;
V_63 -> V_5 = V_5 ;
V_63 -> V_10 = V_10 ;
V_63 -> V_34 = V_34 ;
F_3 ( V_3 , V_63 ) ;
V_9 = V_63 ;
}
}
}
if ( ! V_9 ) {
V_9 = F_48 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 ) {
F_45 ( V_3 -> V_60 , V_10 , V_5 ) ;
V_37 = - V_52 ;
goto V_84;
}
V_9 -> V_5 = V_5 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_32 = V_32 ;
F_3 ( V_3 , V_9 ) ;
}
}
F_44 ( V_37 ) ;
F_52 ( & V_3 -> V_72 ) ;
return V_37 ;
V_84:
F_41 ( V_27 , V_24 , V_32 , true ) ;
V_82:
V_10 = V_74 -> V_10 ;
V_5 = V_74 -> V_5 ;
while ( ( V_9 = F_1 ( V_3 , V_10 , V_5 ) ) ) {
int V_85 = F_46 ( V_3 , V_10 ,
& V_5 , V_9 ) ;
if ( F_44 ( V_85 || ! V_5 ) )
break;
}
F_52 ( & V_3 -> V_72 ) ;
return V_37 ;
}
static int F_56 ( void * V_86 ,
struct V_87 * V_87 )
{
struct V_2 * V_3 = V_86 ;
struct V_88 * V_89 , * V_63 ;
int V_37 ;
V_89 = F_48 ( sizeof( * V_89 ) , V_26 ) ;
if ( ! V_89 )
return - V_52 ;
F_51 ( & V_3 -> V_72 ) ;
F_57 (tmp, &iommu->group_list, next) {
if ( V_63 -> V_87 == V_87 ) {
F_52 ( & V_3 -> V_72 ) ;
F_13 ( V_89 ) ;
return - V_70 ;
}
}
V_37 = F_58 ( V_3 -> V_60 , V_87 ) ;
if ( V_37 ) {
F_52 ( & V_3 -> V_72 ) ;
F_13 ( V_89 ) ;
return V_37 ;
}
V_89 -> V_87 = V_87 ;
F_59 ( & V_89 -> V_90 , & V_3 -> V_91 ) ;
F_52 ( & V_3 -> V_72 ) ;
return 0 ;
}
static void F_60 ( void * V_86 ,
struct V_87 * V_87 )
{
struct V_2 * V_3 = V_86 ;
struct V_88 * V_89 ;
F_51 ( & V_3 -> V_72 ) ;
F_57 (group, &iommu->group_list, next) {
if ( V_89 -> V_87 == V_87 ) {
F_61 ( V_3 -> V_60 , V_87 ) ;
F_62 ( & V_89 -> V_90 ) ;
F_13 ( V_89 ) ;
break;
}
}
F_52 ( & V_3 -> V_72 ) ;
}
static void * F_63 ( unsigned long V_92 )
{
struct V_2 * V_3 ;
if ( V_92 != V_93 )
return F_64 ( - V_70 ) ;
V_3 = F_48 ( sizeof( * V_3 ) , V_26 ) ;
if ( ! V_3 )
return F_64 ( - V_52 ) ;
F_65 ( & V_3 -> V_91 ) ;
V_3 -> V_8 = V_94 ;
F_66 ( & V_3 -> V_72 ) ;
V_3 -> V_60 = F_67 ( & V_95 ) ;
if ( ! V_3 -> V_60 ) {
F_13 ( V_3 ) ;
return F_64 ( - V_96 ) ;
}
if ( ! V_97 &&
! F_68 ( V_3 -> V_60 , V_98 ) ) {
F_39 ( L_2 ,
V_51 ) ;
F_69 ( V_3 -> V_60 ) ;
F_13 ( V_3 ) ;
return F_64 ( - V_99 ) ;
}
return V_3 ;
}
static void F_70 ( void * V_86 )
{
struct V_2 * V_3 = V_86 ;
struct V_88 * V_89 , * V_100 ;
struct V_6 * V_7 ;
F_71 (group, group_tmp, &iommu->group_list, next) {
F_61 ( V_3 -> V_60 , V_89 -> V_87 ) ;
F_62 ( & V_89 -> V_90 ) ;
F_13 ( V_89 ) ;
}
while ( ( V_7 = F_72 ( & V_3 -> V_8 ) ) ) {
struct V_1 * V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
T_2 V_5 = V_9 -> V_5 ;
F_46 ( V_3 , V_9 -> V_10 , & V_5 , V_9 ) ;
if ( F_44 ( ! V_5 ) )
break;
}
F_69 ( V_3 -> V_60 ) ;
V_3 -> V_60 = NULL ;
F_13 ( V_3 ) ;
}
static long F_73 ( void * V_86 ,
unsigned int V_101 , unsigned long V_92 )
{
struct V_2 * V_3 = V_86 ;
unsigned long V_102 ;
if ( V_101 == V_103 ) {
switch ( V_92 ) {
case V_93 :
return 1 ;
default:
return 0 ;
}
} else if ( V_101 == V_104 ) {
struct V_105 V_106 ;
V_102 = F_74 ( struct V_105 , V_107 ) ;
if ( F_75 ( & V_106 , ( void V_108 * ) V_92 , V_102 ) )
return - V_38 ;
if ( V_106 . V_109 < V_102 )
return - V_70 ;
V_106 . V_75 = 0 ;
V_106 . V_107 = V_3 -> V_60 -> V_68 -> V_69 ;
return F_76 ( ( void V_108 * ) V_92 , & V_106 , V_102 ) ;
} else if ( V_101 == V_110 ) {
struct V_73 V_74 ;
T_5 V_67 = V_77 |
V_76 ;
V_102 = F_74 ( struct V_73 , V_5 ) ;
if ( F_75 ( & V_74 , ( void V_108 * ) V_92 , V_102 ) )
return - V_38 ;
if ( V_74 . V_109 < V_102 || V_74 . V_75 & ~ V_67 )
return - V_70 ;
return F_55 ( V_3 , & V_74 ) ;
} else if ( V_101 == V_111 ) {
struct V_65 V_66 ;
long V_37 ;
V_102 = F_74 ( struct V_65 , V_5 ) ;
if ( F_75 ( & V_66 , ( void V_108 * ) V_92 , V_102 ) )
return - V_38 ;
if ( V_66 . V_109 < V_102 || V_66 . V_75 )
return - V_70 ;
V_37 = F_49 ( V_3 , & V_66 ) ;
if ( V_37 )
return V_37 ;
return F_76 ( ( void V_108 * ) V_92 , & V_66 , V_102 ) ;
}
return - V_112 ;
}
static int T_6 F_77 ( void )
{
if ( ! F_78 ( & V_95 ) )
return - V_50 ;
return F_79 ( & V_113 ) ;
}
static void T_7 F_80 ( void )
{
F_81 ( & V_113 ) ;
}
