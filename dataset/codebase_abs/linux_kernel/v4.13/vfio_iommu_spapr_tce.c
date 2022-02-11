static long F_1 ( struct V_1 * V_2 , long V_3 )
{
long V_4 = 0 , V_5 , V_6 ;
if ( F_2 ( ! V_2 ) )
return - V_7 ;
if ( ! V_3 )
return 0 ;
F_3 ( & V_2 -> V_8 ) ;
V_5 = V_2 -> V_9 + V_3 ;
V_6 = F_4 ( V_10 ) >> V_11 ;
if ( V_5 > V_6 && ! F_5 ( V_12 ) )
V_4 = - V_13 ;
else
V_2 -> V_9 += V_3 ;
F_6 ( L_1 , V_14 -> V_15 ,
V_3 << V_11 ,
V_2 -> V_9 << V_11 ,
F_4 ( V_10 ) ,
V_4 ? L_2 : L_3 ) ;
F_7 ( & V_2 -> V_8 ) ;
return V_4 ;
}
static void F_8 ( struct V_1 * V_2 , long V_3 )
{
if ( ! V_2 || ! V_3 )
return;
F_3 ( & V_2 -> V_8 ) ;
if ( F_2 ( V_3 > V_2 -> V_9 ) )
V_3 = V_2 -> V_9 ;
V_2 -> V_9 -= V_3 ;
F_6 ( L_4 , V_14 -> V_15 ,
V_3 << V_11 ,
V_2 -> V_9 << V_11 ,
F_4 ( V_10 ) ) ;
F_7 ( & V_2 -> V_8 ) ;
}
static long F_9 ( struct V_16 * V_17 )
{
if ( V_17 -> V_2 ) {
if ( V_17 -> V_2 == V_14 -> V_2 )
return 0 ;
return - V_7 ;
}
F_10 ( ! V_14 -> V_2 ) ;
V_17 -> V_2 = V_14 -> V_2 ;
F_11 ( & V_17 -> V_2 -> V_18 ) ;
return 0 ;
}
static long F_12 ( struct V_16 * V_17 ,
struct V_19 * V_20 )
{
long V_4 ;
V_4 = F_13 ( V_17 -> V_2 , V_20 -> V_21 ) ;
if ( V_4 )
return V_4 ;
F_14 ( & V_20 -> V_22 ) ;
F_15 ( V_20 ) ;
return 0 ;
}
static long F_16 ( struct V_16 * V_17 ,
T_1 V_23 , T_1 V_24 )
{
struct V_25 * V_21 ;
struct V_19 * V_20 ;
bool V_26 = false ;
if ( ( V_23 & ~ V_27 ) || ( V_24 & ~ V_27 ) )
return - V_28 ;
V_21 = F_17 ( V_17 -> V_2 , V_23 , V_24 >> V_11 ) ;
if ( ! V_21 )
return - V_29 ;
F_18 (tcemem, &container->prereg_list, next) {
if ( V_20 -> V_21 == V_21 ) {
V_26 = true ;
break;
}
}
if ( ! V_26 )
return - V_29 ;
return F_12 ( V_17 , V_20 ) ;
}
static long F_19 ( struct V_16 * V_17 ,
T_1 V_23 , T_1 V_24 )
{
long V_4 = 0 ;
struct V_25 * V_21 = NULL ;
struct V_19 * V_20 ;
unsigned long V_30 = V_24 >> V_11 ;
if ( ( V_23 & ~ V_27 ) || ( V_24 & ~ V_27 ) ||
( ( V_23 + V_24 ) < V_23 ) )
return - V_28 ;
V_21 = F_17 ( V_17 -> V_2 , V_23 , V_30 ) ;
if ( V_21 ) {
F_18 (tcemem, &container->prereg_list, next) {
if ( V_20 -> V_21 == V_21 )
return - V_31 ;
}
}
V_4 = F_20 ( V_17 -> V_2 , V_23 , V_30 , & V_21 ) ;
if ( V_4 )
return V_4 ;
V_20 = F_21 ( sizeof( * V_20 ) , V_32 ) ;
if ( ! V_20 ) {
F_13 ( V_17 -> V_2 , V_21 ) ;
return - V_13 ;
}
V_20 -> V_21 = V_21 ;
F_22 ( & V_20 -> V_22 , & V_17 -> V_33 ) ;
V_17 -> V_34 = true ;
return 0 ;
}
static long F_23 ( struct V_35 * V_36 ,
struct V_1 * V_2 )
{
unsigned long V_37 = F_24 ( sizeof( V_36 -> V_38 [ 0 ] ) *
V_36 -> V_39 , V_40 ) ;
unsigned long * V_41 ;
long V_4 ;
F_10 ( V_36 -> V_38 ) ;
V_4 = F_1 ( V_2 , V_37 >> V_11 ) ;
if ( V_4 )
return V_4 ;
V_41 = F_25 ( V_37 ) ;
if ( ! V_41 ) {
F_8 ( V_2 , V_37 >> V_11 ) ;
return - V_13 ;
}
V_36 -> V_38 = V_41 ;
return 0 ;
}
static void F_26 ( struct V_35 * V_36 ,
struct V_1 * V_2 )
{
unsigned long V_37 = F_24 ( sizeof( V_36 -> V_38 [ 0 ] ) *
V_36 -> V_39 , V_40 ) ;
if ( ! V_36 -> V_38 )
return;
F_27 ( V_36 -> V_38 ) ;
V_36 -> V_38 = NULL ;
F_8 ( V_2 , V_37 >> V_11 ) ;
}
static bool F_28 ( struct V_42 * V_42 , unsigned V_43 )
{
return ( V_11 + F_29 ( F_30 ( V_42 ) ) ) >= V_43 ;
}
static inline bool F_31 ( struct V_16 * V_17 )
{
return ! F_32 ( & V_17 -> V_44 ) ;
}
static long F_33 ( struct V_16 * V_17 ,
T_2 V_45 , struct V_35 * * V_46 )
{
long V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; ++ V_47 ) {
struct V_35 * V_36 = V_17 -> V_49 [ V_47 ] ;
if ( V_36 ) {
unsigned long V_50 = V_45 >> V_36 -> V_51 ;
unsigned long V_52 = V_36 -> V_53 ;
unsigned long V_54 = V_52 + V_36 -> V_39 ;
if ( ( V_52 <= V_50 ) && ( V_50 < V_54 ) ) {
* V_46 = V_36 ;
return V_47 ;
}
}
}
return - 1 ;
}
static int F_34 ( struct V_16 * V_17 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; ++ V_47 ) {
if ( ! V_17 -> V_49 [ V_47 ] )
return V_47 ;
}
return - V_55 ;
}
static int F_35 ( struct V_16 * V_17 )
{
int V_4 = 0 ;
unsigned long V_5 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
if ( V_17 -> V_34 )
return - V_31 ;
if ( ! F_31 ( V_17 ) )
return - V_60 ;
V_59 = F_36 ( & V_17 -> V_44 ,
struct V_58 , V_22 ) ;
V_57 = F_37 ( V_59 -> V_61 ) ;
if ( ! V_57 )
return - V_60 ;
if ( ! V_57 -> V_62 )
return - V_7 ;
V_4 = F_9 ( V_17 ) ;
if ( V_4 )
return V_4 ;
V_5 = V_57 -> V_62 >> V_11 ;
V_4 = F_1 ( V_17 -> V_2 , V_5 ) ;
if ( V_4 )
return V_4 ;
V_17 -> V_63 = V_5 ;
V_17 -> V_34 = true ;
return V_4 ;
}
static void F_38 ( struct V_16 * V_17 )
{
if ( ! V_17 -> V_34 )
return;
V_17 -> V_34 = false ;
F_10 ( ! V_17 -> V_2 ) ;
F_8 ( V_17 -> V_2 , V_17 -> V_63 ) ;
}
static void * F_39 ( unsigned long V_64 )
{
struct V_16 * V_17 ;
if ( ( V_64 != V_65 ) && ( V_64 != V_66 ) ) {
F_40 ( L_5 ) ;
return F_41 ( - V_28 ) ;
}
V_17 = F_21 ( sizeof( * V_17 ) , V_32 ) ;
if ( ! V_17 )
return F_41 ( - V_13 ) ;
F_42 ( & V_17 -> V_67 ) ;
F_43 ( & V_17 -> V_44 ) ;
F_43 ( & V_17 -> V_33 ) ;
V_17 -> V_68 = V_64 == V_66 ;
return V_17 ;
}
static void F_44 ( void * V_69 )
{
struct V_16 * V_17 = V_69 ;
struct V_58 * V_59 ;
long V_47 ;
while ( F_31 ( V_17 ) ) {
V_59 = F_36 ( & V_17 -> V_44 ,
struct V_58 , V_22 ) ;
F_45 ( V_69 , V_59 -> V_61 ) ;
}
for ( V_47 = 0 ; V_47 < V_48 ; ++ V_47 ) {
struct V_35 * V_36 = V_17 -> V_49 [ V_47 ] ;
if ( ! V_36 )
continue;
F_46 ( V_17 , V_36 , V_36 -> V_53 , V_36 -> V_39 ) ;
F_47 ( V_17 , V_36 ) ;
}
while ( ! F_32 ( & V_17 -> V_33 ) ) {
struct V_19 * V_20 ;
V_20 = F_36 ( & V_17 -> V_33 ,
struct V_19 , V_22 ) ;
F_2 ( F_12 ( V_17 , V_20 ) ) ;
}
F_38 ( V_17 ) ;
if ( V_17 -> V_2 )
F_48 ( V_17 -> V_2 ) ;
F_49 ( & V_17 -> V_67 ) ;
F_15 ( V_17 ) ;
}
static void F_50 ( struct V_16 * V_17 ,
unsigned long V_70 )
{
struct V_42 * V_42 ;
V_42 = F_51 ( V_70 >> V_11 ) ;
F_52 ( V_42 ) ;
}
static int F_53 ( struct V_16 * V_17 ,
unsigned long V_71 , unsigned long V_24 ,
unsigned long * V_72 , struct V_25 * * V_73 )
{
long V_4 = 0 ;
struct V_25 * V_21 ;
V_21 = F_54 ( V_17 -> V_2 , V_71 , V_24 ) ;
if ( ! V_21 )
return - V_28 ;
V_4 = F_55 ( V_21 , V_71 , V_72 ) ;
if ( V_4 )
return - V_28 ;
* V_73 = V_21 ;
return 0 ;
}
static void F_56 ( struct V_16 * V_17 ,
struct V_35 * V_36 , unsigned long V_50 )
{
struct V_25 * V_21 = NULL ;
int V_4 ;
unsigned long V_70 = 0 ;
unsigned long * V_74 = F_57 ( V_36 , V_50 ) ;
if ( ! V_74 )
return;
V_4 = F_53 ( V_17 , * V_74 , F_58 ( V_36 ) ,
& V_70 , & V_21 ) ;
if ( V_4 )
F_6 ( L_6 ,
V_75 , * V_74 , V_50 , V_4 ) ;
if ( V_21 )
F_59 ( V_21 ) ;
* V_74 = 0 ;
}
static int F_46 ( struct V_16 * V_17 ,
struct V_35 * V_36 ,
unsigned long V_50 , unsigned long V_76 )
{
unsigned long V_77 ;
long V_4 ;
enum V_78 V_79 ;
for ( ; V_76 ; -- V_76 , ++ V_50 ) {
V_79 = V_80 ;
V_77 = 0 ;
V_4 = F_60 ( V_36 , V_50 , & V_77 , & V_79 ) ;
if ( V_4 )
continue;
if ( V_79 == V_80 )
continue;
if ( V_17 -> V_68 ) {
F_56 ( V_17 , V_36 , V_50 ) ;
continue;
}
F_50 ( V_17 , V_77 ) ;
}
return 0 ;
}
static int F_61 ( unsigned long V_71 , unsigned long * V_70 )
{
struct V_42 * V_42 = NULL ;
enum V_78 V_79 = F_62 ( V_71 ) ;
if ( F_63 ( V_71 & V_27 , 1 ,
V_79 != V_81 , & V_42 ) != 1 )
return - V_82 ;
* V_70 = F_64 ( ( unsigned long ) F_65 ( V_42 ) ) ;
return 0 ;
}
static long F_66 ( struct V_16 * V_17 ,
struct V_35 * V_36 ,
unsigned long V_50 , unsigned long V_71 , unsigned long V_76 ,
enum V_78 V_79 )
{
long V_47 , V_4 = 0 ;
struct V_42 * V_42 ;
unsigned long V_70 ;
enum V_78 V_83 ;
for ( V_47 = 0 ; V_47 < V_76 ; ++ V_47 ) {
unsigned long V_84 = V_71 & F_67 ( V_36 ) & ~ V_27 ;
V_4 = F_61 ( V_71 , & V_70 ) ;
if ( V_4 )
break;
V_42 = F_51 ( V_70 >> V_11 ) ;
if ( ! F_28 ( V_42 , V_36 -> V_51 ) ) {
V_4 = - V_7 ;
break;
}
V_70 |= V_84 ;
V_83 = V_79 ;
V_4 = F_60 ( V_36 , V_50 + V_47 , & V_70 , & V_83 ) ;
if ( V_4 ) {
F_50 ( V_17 , V_70 ) ;
F_40 ( L_7 ,
V_75 , V_50 << V_36 -> V_51 ,
V_71 , V_4 ) ;
break;
}
if ( V_83 != V_80 )
F_50 ( V_17 , V_70 ) ;
V_71 += F_58 ( V_36 ) ;
}
if ( V_4 )
F_46 ( V_17 , V_36 , V_50 , V_47 ) ;
return V_4 ;
}
static long F_68 ( struct V_16 * V_17 ,
struct V_35 * V_36 ,
unsigned long V_50 , unsigned long V_71 , unsigned long V_76 ,
enum V_78 V_79 )
{
long V_47 , V_4 = 0 ;
struct V_42 * V_42 ;
unsigned long V_70 ;
enum V_78 V_83 ;
if ( ! V_36 -> V_38 ) {
V_4 = F_23 ( V_36 , V_17 -> V_2 ) ;
if ( V_4 )
return V_4 ;
}
for ( V_47 = 0 ; V_47 < V_76 ; ++ V_47 ) {
struct V_25 * V_21 = NULL ;
unsigned long * V_74 = F_57 ( V_36 ,
V_50 + V_47 ) ;
V_4 = F_53 ( V_17 ,
V_71 , F_58 ( V_36 ) , & V_70 , & V_21 ) ;
if ( V_4 )
break;
V_42 = F_51 ( V_70 >> V_11 ) ;
if ( ! F_28 ( V_42 , V_36 -> V_51 ) ) {
V_4 = - V_7 ;
break;
}
V_70 |= V_71 & F_67 ( V_36 ) & ~ V_27 ;
V_83 = V_79 ;
if ( F_69 ( V_21 ) )
break;
V_4 = F_60 ( V_36 , V_50 + V_47 , & V_70 , & V_83 ) ;
if ( V_4 ) {
F_56 ( V_17 , V_36 , V_50 + V_47 ) ;
F_40 ( L_7 ,
V_75 , V_50 << V_36 -> V_51 ,
V_71 , V_4 ) ;
break;
}
if ( V_83 != V_80 )
F_56 ( V_17 , V_36 , V_50 + V_47 ) ;
* V_74 = V_71 ;
V_71 += F_58 ( V_36 ) ;
}
if ( V_4 )
F_46 ( V_17 , V_36 , V_50 , V_47 ) ;
return V_4 ;
}
static long F_70 ( struct V_16 * V_17 ,
struct V_56 * V_57 ,
int V_85 ,
T_3 V_43 ,
T_1 V_86 ,
T_3 V_87 ,
struct V_35 * * V_46 )
{
long V_4 , V_88 ;
V_88 = V_57 -> V_89 -> V_90 ( V_43 , V_86 ,
V_87 ) ;
if ( ! V_88 )
return - V_28 ;
V_4 = F_1 ( V_17 -> V_2 , V_88 >> V_11 ) ;
if ( V_4 )
return V_4 ;
V_4 = V_57 -> V_89 -> V_91 ( V_57 , V_85 ,
V_43 , V_86 , V_87 , V_46 ) ;
F_71 ( ! V_4 && ! ( * V_46 ) -> V_92 -> free ) ;
F_71 ( ! V_4 && ( ( * V_46 ) -> V_93 != V_88 ) ) ;
return V_4 ;
}
static void F_47 ( struct V_16 * V_17 ,
struct V_35 * V_36 )
{
unsigned long V_76 = V_36 -> V_93 >> V_11 ;
F_26 ( V_36 , V_17 -> V_2 ) ;
F_72 ( V_36 ) ;
F_8 ( V_17 -> V_2 , V_76 ) ;
}
static long F_73 ( struct V_16 * V_17 ,
T_3 V_43 , T_1 V_86 , T_3 V_87 ,
T_1 * V_94 )
{
struct V_58 * V_59 ;
struct V_56 * V_57 ;
struct V_35 * V_36 = NULL ;
long V_4 , V_85 ;
V_85 = F_34 ( V_17 ) ;
if ( V_85 < 0 )
return V_85 ;
V_59 = F_36 ( & V_17 -> V_44 ,
struct V_58 , V_22 ) ;
V_57 = F_37 ( V_59 -> V_61 ) ;
if ( ! V_57 )
return - V_82 ;
if ( ! ( V_57 -> V_95 & ( 1ULL << V_43 ) ) )
return - V_28 ;
if ( ! V_57 -> V_89 -> V_96 || ! V_57 -> V_89 -> V_97 ||
! V_57 -> V_89 -> V_90 ||
! V_57 -> V_89 -> V_91 )
return - V_7 ;
V_4 = F_70 ( V_17 , V_57 , V_85 ,
V_43 , V_86 , V_87 , & V_36 ) ;
if ( V_4 )
return V_4 ;
F_10 ( ! V_36 -> V_92 -> free ) ;
F_18 (tcegrp, &container->group_list, next) {
V_57 = F_37 ( V_59 -> V_61 ) ;
V_4 = V_57 -> V_89 -> V_96 ( V_57 , V_85 , V_36 ) ;
if ( V_4 )
goto V_98;
}
V_17 -> V_49 [ V_85 ] = V_36 ;
* V_94 = V_36 -> V_53 << V_36 -> V_51 ;
return 0 ;
V_98:
F_18 (tcegrp, &container->group_list, next) {
V_57 = F_37 ( V_59 -> V_61 ) ;
V_57 -> V_89 -> V_97 ( V_57 , V_85 ) ;
}
F_47 ( V_17 , V_36 ) ;
return V_4 ;
}
static long F_74 ( struct V_16 * V_17 ,
T_1 V_94 )
{
struct V_56 * V_57 = NULL ;
struct V_35 * V_36 ;
struct V_58 * V_59 ;
int V_85 ;
V_85 = F_33 ( V_17 , V_94 , & V_36 ) ;
if ( V_85 < 0 )
return - V_28 ;
F_10 ( ! V_36 -> V_39 ) ;
F_18 (tcegrp, &container->group_list, next) {
V_57 = F_37 ( V_59 -> V_61 ) ;
if ( ! V_57 -> V_89 || ! V_57 -> V_89 -> V_97 )
return - V_7 ;
V_57 -> V_89 -> V_97 ( V_57 , V_85 ) ;
}
F_46 ( V_17 , V_36 , V_36 -> V_53 , V_36 -> V_39 ) ;
F_47 ( V_17 , V_36 ) ;
V_17 -> V_49 [ V_85 ] = NULL ;
return 0 ;
}
static long F_75 ( struct V_16 * V_17 )
{
long V_4 ;
T_1 V_94 = 0 ;
struct V_58 * V_59 ;
struct V_56 * V_57 ;
if ( ! V_17 -> V_99 )
return 0 ;
if ( ! F_31 ( V_17 ) )
return - V_60 ;
V_59 = F_36 ( & V_17 -> V_44 ,
struct V_58 , V_22 ) ;
V_57 = F_37 ( V_59 -> V_61 ) ;
if ( ! V_57 )
return - V_60 ;
V_4 = F_73 ( V_17 , V_100 ,
V_57 -> V_62 , 1 , & V_94 ) ;
F_2 ( ! V_4 && V_94 ) ;
if ( ! V_4 )
V_17 -> V_99 = false ;
return V_4 ;
}
static long F_76 ( void * V_69 ,
unsigned int V_101 , unsigned long V_64 )
{
struct V_16 * V_17 = V_69 ;
unsigned long V_102 , V_103 ;
long V_4 ;
switch ( V_101 ) {
case V_104 :
switch ( V_64 ) {
case V_65 :
case V_66 :
V_4 = 1 ;
break;
default:
V_4 = F_77 ( NULL , V_101 , V_64 ) ;
break;
}
return ( V_4 < 0 ) ? 0 : V_4 ;
}
F_10 ( ! V_17 ) ;
if ( V_17 -> V_2 && V_17 -> V_2 != V_14 -> V_2 )
return - V_7 ;
switch ( V_101 ) {
case V_105 : {
struct V_106 V_107 ;
struct V_58 * V_59 ;
struct V_56 * V_57 ;
if ( ! F_31 ( V_17 ) )
return - V_108 ;
V_59 = F_36 ( & V_17 -> V_44 ,
struct V_58 , V_22 ) ;
V_57 = F_37 ( V_59 -> V_61 ) ;
if ( ! V_57 )
return - V_108 ;
V_102 = F_78 ( struct V_106 ,
V_109 ) ;
if ( F_79 ( & V_107 , ( void V_110 * ) V_64 , V_102 ) )
return - V_82 ;
if ( V_107 . V_111 < V_102 )
return - V_28 ;
V_107 . V_112 = V_57 -> V_113 ;
V_107 . V_109 = V_57 -> V_62 ;
V_107 . V_114 = 0 ;
memset ( & V_107 . V_115 , 0 , sizeof( V_107 . V_115 ) ) ;
if ( V_57 -> V_116 &&
V_17 -> V_68 ) {
V_107 . V_114 |= V_117 ;
V_107 . V_115 . V_95 = V_57 -> V_95 ;
V_107 . V_115 . V_116 =
V_57 -> V_116 ;
V_107 . V_115 . V_87 = V_57 -> V_118 ;
}
V_103 = F_78 ( struct V_106 , V_115 ) ;
if ( V_107 . V_111 >= V_103 )
V_102 = V_103 ;
if ( F_80 ( ( void V_110 * ) V_64 , & V_107 , V_102 ) )
return - V_82 ;
return 0 ;
}
case V_119 : {
struct V_120 V_121 ;
struct V_35 * V_36 = NULL ;
long V_85 ;
enum V_78 V_79 ;
if ( ! V_17 -> V_34 )
return - V_7 ;
V_102 = F_78 ( struct V_120 , V_24 ) ;
if ( F_79 ( & V_121 , ( void V_110 * ) V_64 , V_102 ) )
return - V_82 ;
if ( V_121 . V_111 < V_102 )
return - V_28 ;
if ( V_121 . V_114 & ~ ( V_122 |
V_123 ) )
return - V_28 ;
V_4 = F_75 ( V_17 ) ;
if ( V_4 )
return V_4 ;
V_85 = F_33 ( V_17 , V_121 . V_124 , & V_36 ) ;
if ( V_85 < 0 )
return - V_108 ;
if ( ( V_121 . V_24 & ~ F_67 ( V_36 ) ) ||
( V_121 . V_23 & ~ F_67 ( V_36 ) ) )
return - V_28 ;
if ( V_121 . V_114 & V_122 ) {
if ( V_121 . V_114 & V_123 )
V_79 = V_125 ;
else
V_79 = V_81 ;
} else {
if ( V_121 . V_114 & V_123 )
V_79 = V_126 ;
else
return - V_28 ;
}
V_4 = F_81 ( V_36 , V_121 . V_124 , V_121 . V_23 ) ;
if ( V_4 )
return V_4 ;
if ( V_17 -> V_68 )
V_4 = F_68 ( V_17 , V_36 ,
V_121 . V_124 >> V_36 -> V_51 ,
V_121 . V_23 ,
V_121 . V_24 >> V_36 -> V_51 ,
V_79 ) ;
else
V_4 = F_66 ( V_17 , V_36 ,
V_121 . V_124 >> V_36 -> V_51 ,
V_121 . V_23 ,
V_121 . V_24 >> V_36 -> V_51 ,
V_79 ) ;
F_82 ( V_36 ) ;
return V_4 ;
}
case V_127 : {
struct V_128 V_121 ;
struct V_35 * V_36 = NULL ;
long V_85 ;
if ( ! V_17 -> V_34 )
return - V_7 ;
V_102 = F_78 ( struct V_128 ,
V_24 ) ;
if ( F_79 ( & V_121 , ( void V_110 * ) V_64 , V_102 ) )
return - V_82 ;
if ( V_121 . V_111 < V_102 )
return - V_28 ;
if ( V_121 . V_114 )
return - V_28 ;
V_4 = F_75 ( V_17 ) ;
if ( V_4 )
return V_4 ;
V_85 = F_33 ( V_17 , V_121 . V_124 , & V_36 ) ;
if ( V_85 < 0 )
return - V_108 ;
if ( V_121 . V_24 & ~ F_67 ( V_36 ) )
return - V_28 ;
V_4 = F_83 ( V_36 , V_121 . V_124 , 0 ,
V_121 . V_24 >> V_36 -> V_51 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_46 ( V_17 , V_36 ,
V_121 . V_124 >> V_36 -> V_51 ,
V_121 . V_24 >> V_36 -> V_51 ) ;
F_82 ( V_36 ) ;
return V_4 ;
}
case V_129 : {
struct V_130 V_121 ;
if ( ! V_17 -> V_68 )
break;
V_102 = F_78 ( struct V_130 ,
V_24 ) ;
V_4 = F_9 ( V_17 ) ;
if ( V_4 )
return V_4 ;
if ( F_79 ( & V_121 , ( void V_110 * ) V_64 , V_102 ) )
return - V_82 ;
if ( V_121 . V_111 < V_102 )
return - V_28 ;
if ( V_121 . V_114 )
return - V_28 ;
F_84 ( & V_17 -> V_67 ) ;
V_4 = F_19 ( V_17 , V_121 . V_23 ,
V_121 . V_24 ) ;
F_85 ( & V_17 -> V_67 ) ;
return V_4 ;
}
case V_131 : {
struct V_130 V_121 ;
if ( ! V_17 -> V_68 )
break;
if ( ! V_17 -> V_2 )
return - V_7 ;
V_102 = F_78 ( struct V_130 ,
V_24 ) ;
if ( F_79 ( & V_121 , ( void V_110 * ) V_64 , V_102 ) )
return - V_82 ;
if ( V_121 . V_111 < V_102 )
return - V_28 ;
if ( V_121 . V_114 )
return - V_28 ;
F_84 ( & V_17 -> V_67 ) ;
V_4 = F_16 ( V_17 , V_121 . V_23 ,
V_121 . V_24 ) ;
F_85 ( & V_17 -> V_67 ) ;
return V_4 ;
}
case V_132 :
if ( V_17 -> V_68 )
break;
F_84 ( & V_17 -> V_67 ) ;
V_4 = F_35 ( V_17 ) ;
F_85 ( & V_17 -> V_67 ) ;
return V_4 ;
case V_133 :
if ( V_17 -> V_68 )
break;
F_84 ( & V_17 -> V_67 ) ;
F_38 ( V_17 ) ;
F_85 ( & V_17 -> V_67 ) ;
return 0 ;
case V_134 : {
struct V_58 * V_59 ;
V_4 = 0 ;
F_18 (tcegrp, &container->group_list, next) {
V_4 = F_77 ( V_59 -> V_61 ,
V_101 , V_64 ) ;
if ( V_4 )
return V_4 ;
}
return V_4 ;
}
case V_135 : {
struct V_136 V_137 ;
if ( ! V_17 -> V_68 )
break;
V_4 = F_9 ( V_17 ) ;
if ( V_4 )
return V_4 ;
if ( ! F_31 ( V_17 ) )
return - V_108 ;
V_102 = F_78 ( struct V_136 ,
V_94 ) ;
if ( F_79 ( & V_137 , ( void V_110 * ) V_64 , V_102 ) )
return - V_82 ;
if ( V_137 . V_111 < V_102 )
return - V_28 ;
if ( V_137 . V_114 )
return - V_28 ;
F_84 ( & V_17 -> V_67 ) ;
V_4 = F_75 ( V_17 ) ;
if ( ! V_4 )
V_4 = F_73 ( V_17 ,
V_137 . V_43 ,
V_137 . V_86 , V_137 . V_87 ,
& V_137 . V_94 ) ;
F_85 ( & V_17 -> V_67 ) ;
if ( ! V_4 && F_80 ( ( void V_110 * ) V_64 , & V_137 , V_102 ) )
V_4 = - V_82 ;
return V_4 ;
}
case V_138 : {
struct V_139 remove ;
if ( ! V_17 -> V_68 )
break;
V_4 = F_9 ( V_17 ) ;
if ( V_4 )
return V_4 ;
if ( ! F_31 ( V_17 ) )
return - V_108 ;
V_102 = F_78 ( struct V_139 ,
V_94 ) ;
if ( F_79 ( & remove , ( void V_110 * ) V_64 , V_102 ) )
return - V_82 ;
if ( remove . V_111 < V_102 )
return - V_28 ;
if ( remove . V_114 )
return - V_28 ;
if ( V_17 -> V_99 && ! remove . V_94 ) {
V_17 -> V_99 = false ;
return 0 ;
}
F_84 ( & V_17 -> V_67 ) ;
V_4 = F_74 ( V_17 , remove . V_94 ) ;
F_85 ( & V_17 -> V_67 ) ;
return V_4 ;
}
}
return - V_140 ;
}
static void F_86 ( struct V_16 * V_17 ,
struct V_56 * V_57 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; ++ V_47 ) {
struct V_35 * V_36 = V_17 -> V_49 [ V_47 ] ;
if ( ! V_36 )
continue;
F_46 ( V_17 , V_36 , V_36 -> V_53 , V_36 -> V_39 ) ;
F_26 ( V_36 , V_17 -> V_2 ) ;
if ( V_36 -> V_141 )
F_87 ( V_36 ) ;
V_17 -> V_49 [ V_47 ] = NULL ;
}
}
static int F_88 ( struct V_16 * V_17 ,
struct V_56 * V_57 )
{
int V_47 , V_142 , V_143 = 0 ;
for ( V_47 = 0 ; V_47 < V_48 ; ++ V_47 ) {
struct V_35 * V_36 = V_57 -> V_49 [ V_47 ] ;
if ( ! V_36 || ! V_36 -> V_141 )
continue;
V_143 = F_89 ( V_36 ) ;
if ( V_143 ) {
for ( V_142 = 0 ; V_142 < V_47 ; ++ V_142 )
F_87 (
V_57 -> V_49 [ V_142 ] ) ;
return V_143 ;
}
}
for ( V_47 = 0 ; V_47 < V_48 ; ++ V_47 )
V_17 -> V_49 [ V_47 ] = V_57 -> V_49 [ V_47 ] ;
return 0 ;
}
static void F_90 ( struct V_16 * V_17 ,
struct V_56 * V_57 )
{
long V_47 ;
if ( ! V_57 -> V_89 -> V_97 ) {
F_2 ( 1 ) ;
return;
}
for ( V_47 = 0 ; V_47 < V_48 ; ++ V_47 )
V_57 -> V_89 -> V_97 ( V_57 , V_47 ) ;
V_57 -> V_89 -> V_144 ( V_57 ) ;
}
static long F_91 ( struct V_16 * V_17 ,
struct V_56 * V_57 )
{
long V_47 , V_4 = 0 ;
if ( ! V_57 -> V_89 -> V_91 || ! V_57 -> V_89 -> V_96 ||
! V_57 -> V_89 -> V_144 ) {
F_2 ( 1 ) ;
return - V_82 ;
}
V_57 -> V_89 -> V_145 ( V_57 ) ;
for ( V_47 = 0 ; V_47 < V_48 ; ++ V_47 ) {
struct V_35 * V_36 = V_17 -> V_49 [ V_47 ] ;
if ( ! V_36 )
continue;
V_4 = V_57 -> V_89 -> V_96 ( V_57 , V_47 , V_36 ) ;
if ( V_4 )
goto V_146;
}
return 0 ;
V_146:
for ( V_47 = 0 ; V_47 < V_48 ; ++ V_47 )
V_57 -> V_89 -> V_97 ( V_57 , V_47 ) ;
V_57 -> V_89 -> V_144 ( V_57 ) ;
return V_4 ;
}
static int F_92 ( void * V_69 ,
struct V_147 * V_147 )
{
int V_4 ;
struct V_16 * V_17 = V_69 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = NULL ;
F_84 ( & V_17 -> V_67 ) ;
V_57 = F_37 ( V_147 ) ;
if ( ! V_57 ) {
V_4 = - V_60 ;
goto V_148;
}
if ( F_31 ( V_17 ) && ( ! V_57 -> V_89 ||
! V_57 -> V_89 -> V_145 ||
! V_57 -> V_89 -> V_144 ) ) {
V_4 = - V_31 ;
goto V_148;
}
F_18 (tcegrp, &container->group_list, next) {
struct V_56 * V_149 ;
if ( V_59 -> V_61 == V_147 ) {
F_93 ( L_8 ,
F_94 ( V_147 ) ) ;
V_4 = - V_31 ;
goto V_148;
}
V_149 = F_37 ( V_59 -> V_61 ) ;
if ( V_149 -> V_89 -> V_91 !=
V_57 -> V_89 -> V_91 ) {
F_93 ( L_9 ,
F_94 ( V_147 ) ,
F_94 ( V_59 -> V_61 ) ) ;
V_4 = - V_7 ;
goto V_148;
}
}
V_59 = F_21 ( sizeof( * V_59 ) , V_32 ) ;
if ( ! V_59 ) {
V_4 = - V_13 ;
goto V_148;
}
if ( ! V_57 -> V_89 || ! V_57 -> V_89 -> V_145 ||
! V_57 -> V_89 -> V_144 ) {
if ( V_17 -> V_68 ) {
V_4 = - V_7 ;
goto V_148;
}
V_4 = F_88 ( V_17 , V_57 ) ;
} else {
if ( ! V_17 -> V_68 ) {
V_4 = - V_7 ;
goto V_148;
}
V_4 = F_91 ( V_17 , V_57 ) ;
if ( ! F_31 ( V_17 ) && ! V_17 -> V_49 [ 0 ] )
V_17 -> V_99 = true ;
}
if ( ! V_4 ) {
V_59 -> V_61 = V_147 ;
F_22 ( & V_59 -> V_22 , & V_17 -> V_44 ) ;
}
V_148:
if ( V_4 && V_59 )
F_15 ( V_59 ) ;
F_85 ( & V_17 -> V_67 ) ;
return V_4 ;
}
static void F_45 ( void * V_69 ,
struct V_147 * V_147 )
{
struct V_16 * V_17 = V_69 ;
struct V_56 * V_57 ;
bool V_26 = false ;
struct V_58 * V_59 ;
F_84 ( & V_17 -> V_67 ) ;
F_18 (tcegrp, &container->group_list, next) {
if ( V_59 -> V_61 == V_147 ) {
V_26 = true ;
break;
}
}
if ( ! V_26 ) {
F_93 ( L_10 ,
F_94 ( V_147 ) ) ;
goto V_148;
}
F_14 ( & V_59 -> V_22 ) ;
F_15 ( V_59 ) ;
V_57 = F_37 ( V_147 ) ;
F_10 ( ! V_57 ) ;
if ( ! V_57 -> V_89 || ! V_57 -> V_89 -> V_144 )
F_86 ( V_17 , V_57 ) ;
else
F_90 ( V_17 , V_57 ) ;
V_148:
F_85 ( & V_17 -> V_67 ) ;
}
static int T_4 F_95 ( void )
{
return F_96 ( & V_150 ) ;
}
static void T_5 F_97 ( void )
{
F_98 ( & V_150 ) ;
}
