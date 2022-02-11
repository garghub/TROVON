static long F_1 ( long V_1 )
{
long V_2 = 0 , V_3 , V_4 ;
if ( ! V_5 || ! V_5 -> V_6 )
return - V_7 ;
if ( ! V_1 )
return 0 ;
F_2 ( & V_5 -> V_6 -> V_8 ) ;
V_3 = V_5 -> V_6 -> V_9 + V_1 ;
V_4 = F_3 ( V_10 ) >> V_11 ;
if ( V_3 > V_4 && ! F_4 ( V_12 ) )
V_2 = - V_13 ;
else
V_5 -> V_6 -> V_9 += V_1 ;
F_5 ( L_1 , V_5 -> V_14 ,
V_1 << V_11 ,
V_5 -> V_6 -> V_9 << V_11 ,
F_3 ( V_10 ) ,
V_2 ? L_2 : L_3 ) ;
F_6 ( & V_5 -> V_6 -> V_8 ) ;
return V_2 ;
}
static void F_7 ( long V_1 )
{
if ( ! V_5 || ! V_5 -> V_6 || ! V_1 )
return;
F_2 ( & V_5 -> V_6 -> V_8 ) ;
if ( F_8 ( V_1 > V_5 -> V_6 -> V_9 ) )
V_1 = V_5 -> V_6 -> V_9 ;
V_5 -> V_6 -> V_9 -= V_1 ;
F_5 ( L_4 , V_5 -> V_14 ,
V_1 << V_11 ,
V_5 -> V_6 -> V_9 << V_11 ,
F_3 ( V_10 ) ) ;
F_6 ( & V_5 -> V_6 -> V_8 ) ;
}
static long F_9 ( struct V_15 * V_16 ,
T_1 V_17 , T_1 V_18 )
{
struct V_19 * V_20 ;
if ( ( V_17 & ~ V_21 ) || ( V_18 & ~ V_21 ) )
return - V_22 ;
V_20 = F_10 ( V_17 , V_18 >> V_11 ) ;
if ( ! V_20 )
return - V_23 ;
return F_11 ( V_20 ) ;
}
static long F_12 ( struct V_15 * V_16 ,
T_1 V_17 , T_1 V_18 )
{
long V_2 = 0 ;
struct V_19 * V_20 = NULL ;
unsigned long V_24 = V_18 >> V_11 ;
if ( ( V_17 & ~ V_21 ) || ( V_18 & ~ V_21 ) ||
( ( V_17 + V_18 ) < V_17 ) )
return - V_22 ;
V_2 = F_13 ( V_17 , V_24 , & V_20 ) ;
if ( V_2 )
return V_2 ;
V_16 -> V_25 = true ;
return 0 ;
}
static long F_14 ( struct V_26 * V_27 )
{
unsigned long V_28 = F_15 ( sizeof( V_27 -> V_29 [ 0 ] ) *
V_27 -> V_30 , V_31 ) ;
unsigned long * V_32 ;
long V_2 ;
F_16 ( V_27 -> V_29 ) ;
V_2 = F_1 ( V_28 >> V_11 ) ;
if ( V_2 )
return V_2 ;
V_32 = F_17 ( V_28 ) ;
if ( ! V_32 ) {
F_7 ( V_28 >> V_11 ) ;
return - V_13 ;
}
V_27 -> V_29 = V_32 ;
return 0 ;
}
static void F_18 ( struct V_26 * V_27 )
{
unsigned long V_28 = F_15 ( sizeof( V_27 -> V_29 [ 0 ] ) *
V_27 -> V_30 , V_31 ) ;
if ( ! V_27 -> V_29 )
return;
F_19 ( V_27 -> V_29 ) ;
V_27 -> V_29 = NULL ;
F_7 ( V_28 >> V_11 ) ;
}
static bool F_20 ( struct V_33 * V_33 , unsigned V_34 )
{
return ( V_11 + F_21 ( F_22 ( V_33 ) ) ) >= V_34 ;
}
static inline bool F_23 ( struct V_15 * V_16 )
{
return ! F_24 ( & V_16 -> V_35 ) ;
}
static long F_25 ( struct V_15 * V_16 ,
T_2 V_36 , struct V_26 * * V_37 )
{
long V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
struct V_26 * V_27 = V_16 -> V_40 [ V_38 ] ;
if ( V_27 ) {
unsigned long V_41 = V_36 >> V_27 -> V_42 ;
unsigned long V_43 = V_27 -> V_44 ;
unsigned long V_45 = V_43 + V_27 -> V_30 ;
if ( ( V_43 <= V_41 ) && ( V_41 < V_45 ) ) {
* V_37 = V_27 ;
return V_38 ;
}
}
}
return - 1 ;
}
static int F_26 ( struct V_15 * V_16 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
if ( ! V_16 -> V_40 [ V_38 ] )
return V_38 ;
}
return - V_46 ;
}
static int F_27 ( struct V_15 * V_16 )
{
int V_2 = 0 ;
unsigned long V_3 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
if ( ! V_5 -> V_6 )
return - V_7 ;
if ( V_16 -> V_25 )
return - V_51 ;
if ( ! F_23 ( V_16 ) )
return - V_52 ;
V_50 = F_28 ( & V_16 -> V_35 ,
struct V_49 , V_53 ) ;
V_48 = F_29 ( V_50 -> V_54 ) ;
if ( ! V_48 )
return - V_52 ;
if ( ! V_48 -> V_55 )
return - V_56 ;
V_3 = V_48 -> V_55 >> V_11 ;
V_2 = F_1 ( V_3 ) ;
if ( V_2 )
return V_2 ;
V_16 -> V_57 = V_3 ;
V_16 -> V_25 = true ;
return V_2 ;
}
static void F_30 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_25 )
return;
V_16 -> V_25 = false ;
if ( ! V_5 -> V_6 )
return;
F_7 ( V_16 -> V_57 ) ;
}
static void * F_31 ( unsigned long V_58 )
{
struct V_15 * V_16 ;
if ( ( V_58 != V_59 ) && ( V_58 != V_60 ) ) {
F_32 ( L_5 ) ;
return F_33 ( - V_22 ) ;
}
V_16 = F_34 ( sizeof( * V_16 ) , V_61 ) ;
if ( ! V_16 )
return F_33 ( - V_13 ) ;
F_35 ( & V_16 -> V_62 ) ;
F_36 ( & V_16 -> V_35 ) ;
V_16 -> V_63 = V_58 == V_60 ;
return V_16 ;
}
static void F_37 ( void * V_64 )
{
struct V_15 * V_16 = V_64 ;
struct V_49 * V_50 ;
long V_38 ;
while ( F_23 ( V_16 ) ) {
V_50 = F_28 ( & V_16 -> V_35 ,
struct V_49 , V_53 ) ;
F_38 ( V_64 , V_50 -> V_54 ) ;
}
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
struct V_26 * V_27 = V_16 -> V_40 [ V_38 ] ;
if ( ! V_27 )
continue;
F_39 ( V_16 , V_27 , V_27 -> V_44 , V_27 -> V_30 ) ;
F_40 ( V_27 ) ;
}
F_30 ( V_16 ) ;
F_41 ( & V_16 -> V_62 ) ;
F_42 ( V_16 ) ;
}
static void F_43 ( struct V_15 * V_16 ,
unsigned long V_65 )
{
struct V_33 * V_33 ;
V_33 = F_44 ( V_65 >> V_11 ) ;
F_45 ( V_33 ) ;
}
static int F_46 ( unsigned long V_66 , unsigned long V_18 ,
unsigned long * V_67 , struct V_19 * * V_68 )
{
long V_2 = 0 ;
struct V_19 * V_20 ;
V_20 = F_47 ( V_66 , V_18 ) ;
if ( ! V_20 )
return - V_22 ;
V_2 = F_48 ( V_20 , V_66 , V_67 ) ;
if ( V_2 )
return - V_22 ;
* V_68 = V_20 ;
return 0 ;
}
static void F_49 ( struct V_26 * V_27 ,
unsigned long V_41 )
{
struct V_19 * V_20 = NULL ;
int V_2 ;
unsigned long V_65 = 0 ;
unsigned long * V_69 = F_50 ( V_27 , V_41 ) ;
if ( ! V_69 || ! V_5 || ! V_5 -> V_6 )
return;
V_2 = F_46 ( * V_69 , F_51 ( V_27 ) ,
& V_65 , & V_20 ) ;
if ( V_2 )
F_5 ( L_6 ,
V_70 , * V_69 , V_41 , V_2 ) ;
if ( V_20 )
F_52 ( V_20 ) ;
* V_69 = 0 ;
}
static int F_39 ( struct V_15 * V_16 ,
struct V_26 * V_27 ,
unsigned long V_41 , unsigned long V_71 )
{
unsigned long V_72 ;
long V_2 ;
enum V_73 V_74 ;
for ( ; V_71 ; -- V_71 , ++ V_41 ) {
V_74 = V_75 ;
V_72 = 0 ;
V_2 = F_53 ( V_27 , V_41 , & V_72 , & V_74 ) ;
if ( V_2 )
continue;
if ( V_74 == V_75 )
continue;
if ( V_16 -> V_63 ) {
F_49 ( V_27 , V_41 ) ;
continue;
}
F_43 ( V_16 , V_72 ) ;
}
return 0 ;
}
static int F_54 ( unsigned long V_66 , unsigned long * V_65 )
{
struct V_33 * V_33 = NULL ;
enum V_73 V_74 = F_55 ( V_66 ) ;
if ( F_56 ( V_66 & V_21 , 1 ,
V_74 != V_76 , & V_33 ) != 1 )
return - V_77 ;
* V_65 = F_57 ( ( unsigned long ) F_58 ( V_33 ) ) ;
return 0 ;
}
static long F_59 ( struct V_15 * V_16 ,
struct V_26 * V_27 ,
unsigned long V_41 , unsigned long V_66 , unsigned long V_71 ,
enum V_73 V_74 )
{
long V_38 , V_2 = 0 ;
struct V_33 * V_33 ;
unsigned long V_65 ;
enum V_73 V_78 ;
for ( V_38 = 0 ; V_38 < V_71 ; ++ V_38 ) {
unsigned long V_79 = V_66 & F_60 ( V_27 ) & ~ V_21 ;
V_2 = F_54 ( V_66 , & V_65 ) ;
if ( V_2 )
break;
V_33 = F_44 ( V_65 >> V_11 ) ;
if ( ! F_20 ( V_33 , V_27 -> V_42 ) ) {
V_2 = - V_56 ;
break;
}
V_65 |= V_79 ;
V_78 = V_74 ;
V_2 = F_53 ( V_27 , V_41 + V_38 , & V_65 , & V_78 ) ;
if ( V_2 ) {
F_43 ( V_16 , V_65 ) ;
F_32 ( L_7 ,
V_70 , V_41 << V_27 -> V_42 ,
V_66 , V_2 ) ;
break;
}
if ( V_78 != V_75 )
F_43 ( V_16 , V_65 ) ;
V_66 += F_51 ( V_27 ) ;
}
if ( V_2 )
F_39 ( V_16 , V_27 , V_41 , V_38 ) ;
return V_2 ;
}
static long F_61 ( struct V_15 * V_16 ,
struct V_26 * V_27 ,
unsigned long V_41 , unsigned long V_66 , unsigned long V_71 ,
enum V_73 V_74 )
{
long V_38 , V_2 = 0 ;
struct V_33 * V_33 ;
unsigned long V_65 ;
enum V_73 V_78 ;
for ( V_38 = 0 ; V_38 < V_71 ; ++ V_38 ) {
struct V_19 * V_20 = NULL ;
unsigned long * V_69 = F_50 ( V_27 ,
V_41 + V_38 ) ;
V_2 = F_46 ( V_66 , F_51 ( V_27 ) ,
& V_65 , & V_20 ) ;
if ( V_2 )
break;
V_33 = F_44 ( V_65 >> V_11 ) ;
if ( ! F_20 ( V_33 , V_27 -> V_42 ) ) {
V_2 = - V_56 ;
break;
}
V_65 |= V_66 & F_60 ( V_27 ) & ~ V_21 ;
V_78 = V_74 ;
if ( F_62 ( V_20 ) )
break;
V_2 = F_53 ( V_27 , V_41 + V_38 , & V_65 , & V_78 ) ;
if ( V_2 ) {
F_49 ( V_27 , V_41 + V_38 ) ;
F_32 ( L_7 ,
V_70 , V_41 << V_27 -> V_42 ,
V_66 , V_2 ) ;
break;
}
if ( V_78 != V_75 )
F_49 ( V_27 , V_41 + V_38 ) ;
* V_69 = V_66 ;
V_66 += F_51 ( V_27 ) ;
}
if ( V_2 )
F_39 ( V_16 , V_27 , V_41 , V_38 ) ;
return V_2 ;
}
static long F_63 ( struct V_15 * V_16 ,
struct V_47 * V_48 ,
int V_80 ,
T_3 V_34 ,
T_1 V_81 ,
T_3 V_82 ,
struct V_26 * * V_37 )
{
long V_2 , V_83 ;
V_83 = V_48 -> V_84 -> V_85 ( V_34 , V_81 ,
V_82 ) ;
if ( ! V_83 )
return - V_22 ;
V_2 = F_1 ( V_83 >> V_11 ) ;
if ( V_2 )
return V_2 ;
V_2 = V_48 -> V_84 -> V_86 ( V_48 , V_80 ,
V_34 , V_81 , V_82 , V_37 ) ;
F_64 ( ! V_2 && ! ( * V_37 ) -> V_87 -> free ) ;
F_64 ( ! V_2 && ( ( * V_37 ) -> V_88 != V_83 ) ) ;
if ( ! V_2 && V_16 -> V_63 ) {
V_2 = F_14 ( * V_37 ) ;
if ( V_2 )
( * V_37 ) -> V_87 -> free ( * V_37 ) ;
}
if ( V_2 )
F_7 ( V_83 >> V_11 ) ;
return V_2 ;
}
static void F_40 ( struct V_26 * V_27 )
{
unsigned long V_71 = V_27 -> V_88 >> V_11 ;
F_18 ( V_27 ) ;
V_27 -> V_87 -> free ( V_27 ) ;
F_7 ( V_71 ) ;
}
static long F_65 ( struct V_15 * V_16 ,
T_3 V_34 , T_1 V_81 , T_3 V_82 ,
T_1 * V_89 )
{
struct V_49 * V_50 ;
struct V_47 * V_48 ;
struct V_26 * V_27 = NULL ;
long V_2 , V_80 ;
V_80 = F_26 ( V_16 ) ;
if ( V_80 < 0 )
return V_80 ;
V_50 = F_28 ( & V_16 -> V_35 ,
struct V_49 , V_53 ) ;
V_48 = F_29 ( V_50 -> V_54 ) ;
if ( ! V_48 )
return - V_77 ;
if ( ! ( V_48 -> V_90 & ( 1ULL << V_34 ) ) )
return - V_22 ;
if ( ! V_48 -> V_84 -> V_91 || ! V_48 -> V_84 -> V_92 ||
! V_48 -> V_84 -> V_85 ||
! V_48 -> V_84 -> V_86 )
return - V_56 ;
V_2 = F_63 ( V_16 , V_48 , V_80 ,
V_34 , V_81 , V_82 , & V_27 ) ;
if ( V_2 )
return V_2 ;
F_16 ( ! V_27 -> V_87 -> free ) ;
F_66 (tcegrp, &container->group_list, next) {
V_48 = F_29 ( V_50 -> V_54 ) ;
V_2 = V_48 -> V_84 -> V_91 ( V_48 , V_80 , V_27 ) ;
if ( V_2 )
goto V_93;
}
V_16 -> V_40 [ V_80 ] = V_27 ;
* V_89 = V_27 -> V_44 << V_27 -> V_42 ;
return 0 ;
V_93:
F_66 (tcegrp, &container->group_list, next) {
V_48 = F_29 ( V_50 -> V_54 ) ;
V_48 -> V_84 -> V_92 ( V_48 , V_80 ) ;
}
F_40 ( V_27 ) ;
return V_2 ;
}
static long F_67 ( struct V_15 * V_16 ,
T_1 V_89 )
{
struct V_47 * V_48 = NULL ;
struct V_26 * V_27 ;
struct V_49 * V_50 ;
int V_80 ;
V_80 = F_25 ( V_16 , V_89 , & V_27 ) ;
if ( V_80 < 0 )
return - V_22 ;
F_16 ( ! V_27 -> V_30 ) ;
F_66 (tcegrp, &container->group_list, next) {
V_48 = F_29 ( V_50 -> V_54 ) ;
if ( ! V_48 -> V_84 || ! V_48 -> V_84 -> V_92 )
return - V_56 ;
V_48 -> V_84 -> V_92 ( V_48 , V_80 ) ;
}
F_39 ( V_16 , V_27 , V_27 -> V_44 , V_27 -> V_30 ) ;
F_40 ( V_27 ) ;
V_16 -> V_40 [ V_80 ] = NULL ;
return 0 ;
}
static long F_68 ( void * V_64 ,
unsigned int V_94 , unsigned long V_58 )
{
struct V_15 * V_16 = V_64 ;
unsigned long V_95 , V_96 ;
long V_2 ;
switch ( V_94 ) {
case V_97 :
switch ( V_58 ) {
case V_59 :
case V_60 :
V_2 = 1 ;
break;
default:
V_2 = F_69 ( NULL , V_94 , V_58 ) ;
break;
}
return ( V_2 < 0 ) ? 0 : V_2 ;
case V_98 : {
struct V_99 V_100 ;
struct V_49 * V_50 ;
struct V_47 * V_48 ;
if ( ! F_23 ( V_16 ) )
return - V_101 ;
V_50 = F_28 ( & V_16 -> V_35 ,
struct V_49 , V_53 ) ;
V_48 = F_29 ( V_50 -> V_54 ) ;
if ( ! V_48 )
return - V_101 ;
V_95 = F_70 ( struct V_99 ,
V_102 ) ;
if ( F_71 ( & V_100 , ( void V_103 * ) V_58 , V_95 ) )
return - V_77 ;
if ( V_100 . V_104 < V_95 )
return - V_22 ;
V_100 . V_105 = V_48 -> V_106 ;
V_100 . V_102 = V_48 -> V_55 ;
V_100 . V_107 = 0 ;
memset ( & V_100 . V_108 , 0 , sizeof( V_100 . V_108 ) ) ;
if ( V_48 -> V_109 &&
V_16 -> V_63 ) {
V_100 . V_107 |= V_110 ;
V_100 . V_108 . V_90 = V_48 -> V_90 ;
V_100 . V_108 . V_109 =
V_48 -> V_109 ;
V_100 . V_108 . V_82 = V_48 -> V_111 ;
}
V_96 = F_70 ( struct V_99 , V_108 ) ;
if ( V_100 . V_104 >= V_96 )
V_95 = V_96 ;
if ( F_72 ( ( void V_103 * ) V_58 , & V_100 , V_95 ) )
return - V_77 ;
return 0 ;
}
case V_112 : {
struct V_113 V_114 ;
struct V_26 * V_27 = NULL ;
long V_80 ;
enum V_73 V_74 ;
if ( ! V_16 -> V_25 )
return - V_56 ;
V_95 = F_70 ( struct V_113 , V_18 ) ;
if ( F_71 ( & V_114 , ( void V_103 * ) V_58 , V_95 ) )
return - V_77 ;
if ( V_114 . V_104 < V_95 )
return - V_22 ;
if ( V_114 . V_107 & ~ ( V_115 |
V_116 ) )
return - V_22 ;
V_80 = F_25 ( V_16 , V_114 . V_117 , & V_27 ) ;
if ( V_80 < 0 )
return - V_101 ;
if ( ( V_114 . V_18 & ~ F_60 ( V_27 ) ) ||
( V_114 . V_17 & ~ F_60 ( V_27 ) ) )
return - V_22 ;
if ( V_114 . V_107 & V_115 ) {
if ( V_114 . V_107 & V_116 )
V_74 = V_118 ;
else
V_74 = V_76 ;
} else {
if ( V_114 . V_107 & V_116 )
V_74 = V_119 ;
else
return - V_22 ;
}
V_2 = F_73 ( V_27 , V_114 . V_117 , V_114 . V_17 ) ;
if ( V_2 )
return V_2 ;
if ( V_16 -> V_63 )
V_2 = F_61 ( V_16 , V_27 ,
V_114 . V_117 >> V_27 -> V_42 ,
V_114 . V_17 ,
V_114 . V_18 >> V_27 -> V_42 ,
V_74 ) ;
else
V_2 = F_59 ( V_16 , V_27 ,
V_114 . V_117 >> V_27 -> V_42 ,
V_114 . V_17 ,
V_114 . V_18 >> V_27 -> V_42 ,
V_74 ) ;
F_74 ( V_27 ) ;
return V_2 ;
}
case V_120 : {
struct V_121 V_114 ;
struct V_26 * V_27 = NULL ;
long V_80 ;
if ( ! V_16 -> V_25 )
return - V_56 ;
V_95 = F_70 ( struct V_121 ,
V_18 ) ;
if ( F_71 ( & V_114 , ( void V_103 * ) V_58 , V_95 ) )
return - V_77 ;
if ( V_114 . V_104 < V_95 )
return - V_22 ;
if ( V_114 . V_107 )
return - V_22 ;
V_80 = F_25 ( V_16 , V_114 . V_117 , & V_27 ) ;
if ( V_80 < 0 )
return - V_101 ;
if ( V_114 . V_18 & ~ F_60 ( V_27 ) )
return - V_22 ;
V_2 = F_75 ( V_27 , V_114 . V_117 , 0 ,
V_114 . V_18 >> V_27 -> V_42 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_39 ( V_16 , V_27 ,
V_114 . V_117 >> V_27 -> V_42 ,
V_114 . V_18 >> V_27 -> V_42 ) ;
F_74 ( V_27 ) ;
return V_2 ;
}
case V_122 : {
struct V_123 V_114 ;
if ( ! V_16 -> V_63 )
break;
V_95 = F_70 ( struct V_123 ,
V_18 ) ;
if ( F_71 ( & V_114 , ( void V_103 * ) V_58 , V_95 ) )
return - V_77 ;
if ( V_114 . V_104 < V_95 )
return - V_22 ;
if ( V_114 . V_107 )
return - V_22 ;
F_76 ( & V_16 -> V_62 ) ;
V_2 = F_12 ( V_16 , V_114 . V_17 ,
V_114 . V_18 ) ;
F_77 ( & V_16 -> V_62 ) ;
return V_2 ;
}
case V_124 : {
struct V_123 V_114 ;
if ( ! V_16 -> V_63 )
break;
V_95 = F_70 ( struct V_123 ,
V_18 ) ;
if ( F_71 ( & V_114 , ( void V_103 * ) V_58 , V_95 ) )
return - V_77 ;
if ( V_114 . V_104 < V_95 )
return - V_22 ;
if ( V_114 . V_107 )
return - V_22 ;
F_76 ( & V_16 -> V_62 ) ;
V_2 = F_9 ( V_16 , V_114 . V_17 ,
V_114 . V_18 ) ;
F_77 ( & V_16 -> V_62 ) ;
return V_2 ;
}
case V_125 :
if ( V_16 -> V_63 )
break;
F_76 ( & V_16 -> V_62 ) ;
V_2 = F_27 ( V_16 ) ;
F_77 ( & V_16 -> V_62 ) ;
return V_2 ;
case V_126 :
if ( V_16 -> V_63 )
break;
F_76 ( & V_16 -> V_62 ) ;
F_30 ( V_16 ) ;
F_77 ( & V_16 -> V_62 ) ;
return 0 ;
case V_127 : {
struct V_49 * V_50 ;
V_2 = 0 ;
F_66 (tcegrp, &container->group_list, next) {
V_2 = F_69 ( V_50 -> V_54 ,
V_94 , V_58 ) ;
if ( V_2 )
return V_2 ;
}
return V_2 ;
}
case V_128 : {
struct V_129 V_130 ;
if ( ! V_16 -> V_63 )
break;
if ( ! F_23 ( V_16 ) )
return - V_101 ;
V_95 = F_70 ( struct V_129 ,
V_89 ) ;
if ( F_71 ( & V_130 , ( void V_103 * ) V_58 , V_95 ) )
return - V_77 ;
if ( V_130 . V_104 < V_95 )
return - V_22 ;
if ( V_130 . V_107 )
return - V_22 ;
F_76 ( & V_16 -> V_62 ) ;
V_2 = F_65 ( V_16 , V_130 . V_34 ,
V_130 . V_81 , V_130 . V_82 ,
& V_130 . V_89 ) ;
F_77 ( & V_16 -> V_62 ) ;
if ( ! V_2 && F_72 ( ( void V_103 * ) V_58 , & V_130 , V_95 ) )
V_2 = - V_77 ;
return V_2 ;
}
case V_131 : {
struct V_132 remove ;
if ( ! V_16 -> V_63 )
break;
if ( ! F_23 ( V_16 ) )
return - V_101 ;
V_95 = F_70 ( struct V_132 ,
V_89 ) ;
if ( F_71 ( & remove , ( void V_103 * ) V_58 , V_95 ) )
return - V_77 ;
if ( remove . V_104 < V_95 )
return - V_22 ;
if ( remove . V_107 )
return - V_22 ;
F_76 ( & V_16 -> V_62 ) ;
V_2 = F_67 ( V_16 , remove . V_89 ) ;
F_77 ( & V_16 -> V_62 ) ;
return V_2 ;
}
}
return - V_133 ;
}
static void F_78 ( struct V_15 * V_16 ,
struct V_47 * V_48 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
struct V_26 * V_27 = V_16 -> V_40 [ V_38 ] ;
if ( ! V_27 )
continue;
F_39 ( V_16 , V_27 , V_27 -> V_44 , V_27 -> V_30 ) ;
F_18 ( V_27 ) ;
if ( V_27 -> V_134 )
F_79 ( V_27 ) ;
V_16 -> V_40 [ V_38 ] = NULL ;
}
}
static int F_80 ( struct V_15 * V_16 ,
struct V_47 * V_48 )
{
int V_38 , V_135 , V_136 = 0 ;
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
struct V_26 * V_27 = V_48 -> V_40 [ V_38 ] ;
if ( ! V_27 || ! V_27 -> V_134 )
continue;
V_136 = F_14 ( V_27 ) ;
if ( ! V_136 )
V_136 = F_81 ( V_27 ) ;
if ( V_136 ) {
for ( V_135 = 0 ; V_135 < V_38 ; ++ V_135 )
F_79 (
V_48 -> V_40 [ V_135 ] ) ;
return V_136 ;
}
}
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 )
V_16 -> V_40 [ V_38 ] = V_48 -> V_40 [ V_38 ] ;
return 0 ;
}
static void F_82 ( struct V_15 * V_16 ,
struct V_47 * V_48 )
{
long V_38 ;
if ( ! V_48 -> V_84 -> V_92 ) {
F_8 ( 1 ) ;
return;
}
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 )
V_48 -> V_84 -> V_92 ( V_48 , V_38 ) ;
V_48 -> V_84 -> V_137 ( V_48 ) ;
}
static long F_83 ( struct V_15 * V_16 ,
struct V_47 * V_48 )
{
long V_38 , V_2 = 0 ;
struct V_26 * V_27 = NULL ;
if ( ! V_48 -> V_84 -> V_86 || ! V_48 -> V_84 -> V_91 ||
! V_48 -> V_84 -> V_137 ) {
F_8 ( 1 ) ;
return - V_77 ;
}
V_48 -> V_84 -> V_138 ( V_48 ) ;
if ( ! F_23 ( V_16 ) && ! V_16 -> V_40 [ 0 ] ) {
V_2 = F_63 ( V_16 ,
V_48 ,
0 ,
V_139 ,
V_48 -> V_55 ,
1 ,
& V_27 ) ;
if ( V_2 )
goto V_140;
else
V_16 -> V_40 [ 0 ] = V_27 ;
}
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 ) {
V_27 = V_16 -> V_40 [ V_38 ] ;
if ( ! V_27 )
continue;
V_2 = V_48 -> V_84 -> V_91 ( V_48 , V_38 , V_27 ) ;
if ( V_2 )
goto V_140;
}
return 0 ;
V_140:
for ( V_38 = 0 ; V_38 < V_39 ; ++ V_38 )
V_48 -> V_84 -> V_92 ( V_48 , V_38 ) ;
V_48 -> V_84 -> V_137 ( V_48 ) ;
return V_2 ;
}
static int F_84 ( void * V_64 ,
struct V_141 * V_141 )
{
int V_2 ;
struct V_15 * V_16 = V_64 ;
struct V_47 * V_48 ;
struct V_49 * V_50 = NULL ;
F_76 ( & V_16 -> V_62 ) ;
V_48 = F_29 ( V_141 ) ;
if ( F_23 ( V_16 ) && ( ! V_48 -> V_84 ||
! V_48 -> V_84 -> V_138 ||
! V_48 -> V_84 -> V_137 ) ) {
V_2 = - V_51 ;
goto V_142;
}
F_66 (tcegrp, &container->group_list, next) {
struct V_47 * V_143 ;
if ( V_50 -> V_54 == V_141 ) {
F_85 ( L_8 ,
F_86 ( V_141 ) ) ;
V_2 = - V_51 ;
goto V_142;
}
V_143 = F_29 ( V_50 -> V_54 ) ;
if ( V_143 -> V_84 -> V_86 !=
V_48 -> V_84 -> V_86 ) {
F_85 ( L_9 ,
F_86 ( V_141 ) ,
F_86 ( V_50 -> V_54 ) ) ;
V_2 = - V_56 ;
goto V_142;
}
}
V_50 = F_34 ( sizeof( * V_50 ) , V_61 ) ;
if ( ! V_50 ) {
V_2 = - V_13 ;
goto V_142;
}
if ( ! V_48 -> V_84 || ! V_48 -> V_84 -> V_138 ||
! V_48 -> V_84 -> V_137 )
V_2 = F_80 ( V_16 , V_48 ) ;
else
V_2 = F_83 ( V_16 , V_48 ) ;
if ( ! V_2 ) {
V_50 -> V_54 = V_141 ;
F_87 ( & V_50 -> V_53 , & V_16 -> V_35 ) ;
}
V_142:
if ( V_2 && V_50 )
F_42 ( V_50 ) ;
F_77 ( & V_16 -> V_62 ) ;
return V_2 ;
}
static void F_38 ( void * V_64 ,
struct V_141 * V_141 )
{
struct V_15 * V_16 = V_64 ;
struct V_47 * V_48 ;
bool V_144 = false ;
struct V_49 * V_50 ;
F_76 ( & V_16 -> V_62 ) ;
F_66 (tcegrp, &container->group_list, next) {
if ( V_50 -> V_54 == V_141 ) {
V_144 = true ;
break;
}
}
if ( ! V_144 ) {
F_85 ( L_10 ,
F_86 ( V_141 ) ) ;
goto V_142;
}
F_88 ( & V_50 -> V_53 ) ;
F_42 ( V_50 ) ;
V_48 = F_29 ( V_141 ) ;
F_16 ( ! V_48 ) ;
if ( ! V_48 -> V_84 || ! V_48 -> V_84 -> V_137 )
F_78 ( V_16 , V_48 ) ;
else
F_82 ( V_16 , V_48 ) ;
V_142:
F_77 ( & V_16 -> V_62 ) ;
}
static int T_4 F_89 ( void )
{
return F_90 ( & V_145 ) ;
}
static void T_5 F_91 ( void )
{
F_92 ( & V_145 ) ;
}
