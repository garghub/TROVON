static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 , T_2 V_5 ,
T_2 * V_6 , T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_9 V_10 ;
int V_11 ;
V_10 = V_8 -> V_12 -> V_13 ;
V_11 = V_8 -> V_12 -> V_14 ( V_8 -> V_12 , V_4 + V_8 -> V_15 , V_5 ,
V_6 , V_7 ) ;
if ( F_4 ( F_5 ( V_11 ) ) )
V_3 -> V_13 . V_16 +=
V_8 -> V_12 -> V_13 . V_16 - V_10 . V_16 ;
else
V_3 -> V_13 . V_17 +=
V_8 -> V_12 -> V_13 . V_17 - V_10 . V_17 ;
return V_11 ;
}
static int F_6 ( struct V_2 * V_3 , T_1 V_4 , T_2 V_5 ,
T_2 * V_6 , void * * V_18 , T_4 * V_19 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_20 ( V_8 -> V_12 , V_4 + V_8 -> V_15 , V_5 ,
V_6 , V_18 , V_19 ) ;
}
static int F_7 ( struct V_2 * V_3 , T_1 V_4 , T_2 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_21 ( V_8 -> V_12 , V_4 + V_8 -> V_15 , V_5 ) ;
}
static unsigned long F_8 ( struct V_2 * V_3 ,
unsigned long V_5 ,
unsigned long V_15 ,
unsigned long V_22 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_15 += V_8 -> V_15 ;
return V_8 -> V_12 -> V_23 ( V_8 -> V_12 , V_5 , V_15 ,
V_22 ) ;
}
static int F_9 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_24 * V_25 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_11 ;
if ( V_4 >= V_3 -> V_26 )
return - V_27 ;
if ( V_25 -> V_28 && V_4 + V_25 -> V_5 > V_3 -> V_26 )
return - V_27 ;
if ( V_25 -> V_29 ) {
T_2 V_5 , V_30 ;
V_5 = F_10 ( V_3 , V_25 ) ;
V_30 = F_11 ( V_3 -> V_26 , V_3 ) ;
V_30 -= F_11 ( V_4 , V_3 ) ;
if ( V_25 -> V_31 + V_25 -> V_32 > V_30 * V_5 )
return - V_27 ;
}
V_11 = V_8 -> V_12 -> V_33 ( V_8 -> V_12 , V_4 + V_8 -> V_15 , V_25 ) ;
if ( F_4 ( V_11 ) ) {
if ( F_12 ( V_11 ) )
V_3 -> V_13 . V_17 ++ ;
if ( F_5 ( V_11 ) )
V_3 -> V_13 . V_16 ++ ;
}
return V_11 ;
}
static int F_13 ( struct V_2 * V_3 , T_1 V_4 ,
T_2 V_5 , T_2 * V_6 , T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_34 ( V_8 -> V_12 , V_4 , V_5 ,
V_6 , V_7 ) ;
}
static int F_14 ( struct V_2 * V_3 , T_2 V_5 ,
T_2 * V_6 , struct V_35 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_36 ( V_8 -> V_12 , V_5 , V_6 ,
V_7 ) ;
}
static int F_15 ( struct V_2 * V_3 , T_1 V_4 ,
T_2 V_5 , T_2 * V_6 , T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_37 ( V_8 -> V_12 , V_4 , V_5 ,
V_6 , V_7 ) ;
}
static int F_16 ( struct V_2 * V_3 , T_2 V_5 ,
T_2 * V_6 , struct V_35 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_38 ( V_8 -> V_12 , V_5 , V_6 ,
V_7 ) ;
}
static int F_17 ( struct V_2 * V_3 , T_1 V_39 , T_2 V_5 ,
T_2 * V_6 , const T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_40 ( V_8 -> V_12 , V_39 + V_8 -> V_15 , V_5 ,
V_6 , V_7 ) ;
}
static int F_18 ( struct V_2 * V_3 , T_1 V_39 , T_2 V_5 ,
T_2 * V_6 , const T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_41 ( V_8 -> V_12 , V_39 + V_8 -> V_15 , V_5 ,
V_6 , V_7 ) ;
}
static int F_19 ( struct V_2 * V_3 , T_1 V_39 ,
struct V_24 * V_25 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_39 >= V_3 -> V_26 )
return - V_27 ;
if ( V_25 -> V_28 && V_39 + V_25 -> V_5 > V_3 -> V_26 )
return - V_27 ;
return V_8 -> V_12 -> V_42 ( V_8 -> V_12 , V_39 + V_8 -> V_15 , V_25 ) ;
}
static int F_20 ( struct V_2 * V_3 , T_1 V_4 ,
T_2 V_5 , T_2 * V_6 , T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_43 ( V_8 -> V_12 , V_4 , V_5 ,
V_6 , V_7 ) ;
}
static int F_21 ( struct V_2 * V_3 , T_1 V_4 ,
T_2 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_44 ( V_8 -> V_12 , V_4 , V_5 ) ;
}
static int F_22 ( struct V_2 * V_3 , const struct V_45 * V_46 ,
unsigned long V_47 , T_1 V_39 , T_2 * V_6 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_48 ( V_8 -> V_12 , V_46 , V_47 ,
V_39 + V_8 -> V_15 , V_6 ) ;
}
static int F_23 ( struct V_2 * V_3 , struct V_49 * V_50 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_51 ;
V_50 -> V_52 += V_8 -> V_15 ;
V_51 = V_8 -> V_12 -> V_53 ( V_8 -> V_12 , V_50 ) ;
if ( V_51 ) {
if ( V_50 -> V_54 != V_55 )
V_50 -> V_54 -= V_8 -> V_15 ;
V_50 -> V_52 -= V_8 -> V_15 ;
}
return V_51 ;
}
void F_24 ( struct V_49 * V_50 )
{
if ( V_50 -> V_3 -> V_53 == F_23 ) {
struct V_1 * V_8 = F_1 ( V_50 -> V_3 ) ;
if ( V_50 -> V_54 != V_55 )
V_50 -> V_54 -= V_8 -> V_15 ;
V_50 -> V_52 -= V_8 -> V_15 ;
}
if ( V_50 -> V_56 )
V_50 -> V_56 ( V_50 ) ;
}
static int F_25 ( struct V_2 * V_3 , T_1 V_57 , T_5 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_58 ( V_8 -> V_12 , V_57 + V_8 -> V_15 , V_5 ) ;
}
static int F_26 ( struct V_2 * V_3 , T_1 V_57 , T_5 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_59 ( V_8 -> V_12 , V_57 + V_8 -> V_15 , V_5 ) ;
}
static int F_27 ( struct V_2 * V_3 , T_1 V_57 , T_5 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_60 ( V_8 -> V_12 , V_57 + V_8 -> V_15 , V_5 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_12 -> V_61 ( V_8 -> V_12 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_62 ( V_8 -> V_12 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_12 -> V_63 ( V_8 -> V_12 ) ;
}
static int F_31 ( struct V_2 * V_3 , T_1 V_57 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_57 += V_8 -> V_15 ;
return V_8 -> V_12 -> V_64 ( V_8 -> V_12 , V_57 ) ;
}
static int F_32 ( struct V_2 * V_3 , T_1 V_57 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_57 += V_8 -> V_15 ;
return V_8 -> V_12 -> V_65 ( V_8 -> V_12 , V_57 ) ;
}
static int F_33 ( struct V_2 * V_3 , T_1 V_57 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_11 ;
V_57 += V_8 -> V_15 ;
V_11 = V_8 -> V_12 -> V_66 ( V_8 -> V_12 , V_57 ) ;
if ( ! V_11 )
V_3 -> V_13 . V_67 ++ ;
return V_11 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_68 ( V_8 -> V_12 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_12 -> V_69 ( V_8 -> V_12 ) ;
}
static int F_36 ( struct V_2 * V_3 , int V_70 ,
struct V_71 * V_72 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return F_37 ( V_8 -> V_12 , V_70 , V_72 ) ;
}
static int F_38 ( struct V_2 * V_3 , int V_70 ,
struct V_71 * V_72 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return F_39 ( V_8 -> V_12 , V_70 , V_72 ) ;
}
static inline void F_40 ( struct V_1 * V_73 )
{
F_41 ( V_73 -> V_3 . V_74 ) ;
F_41 ( V_73 ) ;
}
int F_42 ( struct V_2 * V_12 )
{
struct V_1 * V_75 , * V_76 ;
int V_51 , V_77 = 0 ;
F_43 ( & V_78 ) ;
F_44 (slave, next, &mtd_partitions, list)
if ( V_75 -> V_12 == V_12 ) {
V_51 = F_45 ( & V_75 -> V_3 ) ;
if ( V_51 < 0 ) {
V_77 = V_51 ;
continue;
}
F_46 ( & V_75 -> V_79 ) ;
F_40 ( V_75 ) ;
}
F_47 ( & V_78 ) ;
return V_77 ;
}
static struct V_1 * F_48 ( struct V_2 * V_12 ,
const struct V_80 * V_8 , int V_81 ,
T_5 V_82 )
{
struct V_1 * V_75 ;
char * V_74 ;
V_75 = F_49 ( sizeof( * V_75 ) , V_83 ) ;
V_74 = F_50 ( V_8 -> V_74 , V_83 ) ;
if ( ! V_74 || ! V_75 ) {
F_51 ( V_84 L_1 ,
V_12 -> V_74 ) ;
F_41 ( V_74 ) ;
F_41 ( V_75 ) ;
return F_52 ( - V_85 ) ;
}
V_75 -> V_3 . type = V_12 -> type ;
V_75 -> V_3 . V_22 = V_12 -> V_22 & ~ V_8 -> V_86 ;
V_75 -> V_3 . V_26 = V_8 -> V_26 ;
V_75 -> V_3 . V_87 = V_12 -> V_87 ;
V_75 -> V_3 . V_88 = V_12 -> V_88 ;
V_75 -> V_3 . V_89 = V_12 -> V_89 ;
V_75 -> V_3 . V_90 = V_12 -> V_90 ;
V_75 -> V_3 . V_91 = V_12 -> V_91 ;
V_75 -> V_3 . V_92 = V_12 -> V_92 ;
V_75 -> V_3 . V_74 = V_74 ;
V_75 -> V_3 . V_93 = V_12 -> V_93 ;
V_75 -> V_3 . V_94 . V_95 = F_53 ( V_96 ) ?
& V_12 -> V_94 :
V_12 -> V_94 . V_95 ;
V_75 -> V_3 . V_14 = F_3 ;
V_75 -> V_3 . V_40 = F_17 ;
if ( V_12 -> V_41 )
V_75 -> V_3 . V_41 = F_18 ;
if ( V_12 -> V_20 && V_12 -> V_21 ) {
V_75 -> V_3 . V_20 = F_6 ;
V_75 -> V_3 . V_21 = F_7 ;
}
if ( V_12 -> V_23 )
V_75 -> V_3 . V_23 = F_8 ;
if ( V_12 -> V_33 )
V_75 -> V_3 . V_33 = F_9 ;
if ( V_12 -> V_42 )
V_75 -> V_3 . V_42 = F_19 ;
if ( V_12 -> V_34 )
V_75 -> V_3 . V_34 = F_13 ;
if ( V_12 -> V_37 )
V_75 -> V_3 . V_37 = F_15 ;
if ( V_12 -> V_43 )
V_75 -> V_3 . V_43 = F_20 ;
if ( V_12 -> V_44 )
V_75 -> V_3 . V_44 = F_21 ;
if ( V_12 -> V_36 )
V_75 -> V_3 . V_36 = F_14 ;
if ( V_12 -> V_38 )
V_75 -> V_3 . V_38 = F_16 ;
if ( V_12 -> V_61 )
V_75 -> V_3 . V_61 = F_28 ;
if ( ! V_81 && ! V_12 -> V_94 . V_97 && V_12 -> V_62 &&
V_12 -> V_63 ) {
V_75 -> V_3 . V_62 = F_29 ;
V_75 -> V_3 . V_63 = F_30 ;
}
if ( V_12 -> V_48 )
V_75 -> V_3 . V_48 = F_22 ;
if ( V_12 -> V_58 )
V_75 -> V_3 . V_58 = F_25 ;
if ( V_12 -> V_59 )
V_75 -> V_3 . V_59 = F_26 ;
if ( V_12 -> V_60 )
V_75 -> V_3 . V_60 = F_27 ;
if ( V_12 -> V_64 )
V_75 -> V_3 . V_64 = F_31 ;
if ( V_12 -> V_65 )
V_75 -> V_3 . V_65 = F_32 ;
if ( V_12 -> V_66 )
V_75 -> V_3 . V_66 = F_33 ;
if ( V_12 -> V_68 )
V_75 -> V_3 . V_68 = F_34 ;
if ( V_12 -> V_69 )
V_75 -> V_3 . V_69 = F_35 ;
V_75 -> V_3 . V_53 = F_23 ;
V_75 -> V_12 = V_12 ;
V_75 -> V_15 = V_8 -> V_15 ;
if ( V_75 -> V_15 == V_98 )
V_75 -> V_15 = V_82 ;
if ( V_75 -> V_15 == V_99 ) {
V_75 -> V_15 = V_82 ;
if ( F_54 ( V_82 , V_12 ) != 0 ) {
V_75 -> V_15 = ( F_55 ( V_82 , V_12 ) + 1 ) * V_12 -> V_100 ;
F_51 ( V_101 L_2
L_3 , V_81 ,
( unsigned long long ) V_82 , ( unsigned long long ) V_75 -> V_15 ) ;
}
}
if ( V_75 -> V_15 == V_102 ) {
V_75 -> V_15 = V_82 ;
if ( V_12 -> V_26 - V_75 -> V_15 >= V_75 -> V_3 . V_26 ) {
V_75 -> V_3 . V_26 = V_12 -> V_26 - V_75 -> V_15
- V_75 -> V_3 . V_26 ;
} else {
F_51 ( V_84 L_4 ,
V_8 -> V_74 , V_12 -> V_26 - V_75 -> V_15 ,
V_75 -> V_3 . V_26 ) ;
goto V_103;
}
}
if ( V_75 -> V_3 . V_26 == V_104 )
V_75 -> V_3 . V_26 = V_12 -> V_26 - V_75 -> V_15 ;
F_51 ( V_101 L_5 , ( unsigned long long ) V_75 -> V_15 ,
( unsigned long long ) ( V_75 -> V_15 + V_75 -> V_3 . V_26 ) , V_75 -> V_3 . V_74 ) ;
if ( V_75 -> V_15 >= V_12 -> V_26 ) {
V_75 -> V_15 = 0 ;
V_75 -> V_3 . V_26 = 0 ;
F_51 ( V_84 L_6 ,
V_8 -> V_74 ) ;
goto V_103;
}
if ( V_75 -> V_15 + V_75 -> V_3 . V_26 > V_12 -> V_26 ) {
V_75 -> V_3 . V_26 = V_12 -> V_26 - V_75 -> V_15 ;
F_51 ( V_105 L_7 ,
V_8 -> V_74 , V_12 -> V_74 , ( unsigned long long ) V_75 -> V_3 . V_26 ) ;
}
if ( V_12 -> V_106 > 1 ) {
int V_107 , V_108 = V_12 -> V_106 ;
T_6 V_109 = V_75 -> V_15 + V_75 -> V_3 . V_26 ;
struct V_110 * V_111 = V_12 -> V_112 ;
for ( V_107 = 0 ; V_107 < V_108 && V_111 [ V_107 ] . V_15 <= V_75 -> V_15 ; V_107 ++ )
;
if ( V_107 > 0 )
V_107 -- ;
for (; V_107 < V_108 && V_111 [ V_107 ] . V_15 < V_109 ; V_107 ++ ) {
if ( V_75 -> V_3 . V_100 < V_111 [ V_107 ] . V_100 ) {
V_75 -> V_3 . V_100 = V_111 [ V_107 ] . V_100 ;
}
}
F_56 ( V_75 -> V_3 . V_100 == 0 ) ;
} else {
V_75 -> V_3 . V_100 = V_12 -> V_100 ;
}
if ( ( V_75 -> V_3 . V_22 & V_113 ) &&
F_54 ( V_75 -> V_15 , & V_75 -> V_3 ) ) {
V_75 -> V_3 . V_22 &= ~ V_113 ;
F_51 ( V_105 L_8 ,
V_8 -> V_74 ) ;
}
if ( ( V_75 -> V_3 . V_22 & V_113 ) &&
F_54 ( V_75 -> V_3 . V_26 , & V_75 -> V_3 ) ) {
V_75 -> V_3 . V_22 &= ~ V_113 ;
F_51 ( V_105 L_9 ,
V_8 -> V_74 ) ;
}
F_57 ( & V_75 -> V_3 , & V_114 ) ;
V_75 -> V_3 . V_115 = V_12 -> V_115 ;
V_75 -> V_3 . V_116 = V_12 -> V_116 ;
V_75 -> V_3 . V_117 = V_12 -> V_117 ;
if ( V_12 -> V_65 ) {
T_5 V_118 = 0 ;
while ( V_118 < V_75 -> V_3 . V_26 ) {
if ( F_58 ( V_12 , V_118 + V_75 -> V_15 ) )
V_75 -> V_3 . V_13 . V_119 ++ ;
else if ( F_59 ( V_12 , V_118 + V_75 -> V_15 ) )
V_75 -> V_3 . V_13 . V_67 ++ ;
V_118 += V_75 -> V_3 . V_100 ;
}
}
V_103:
return V_75 ;
}
static T_7 F_60 ( struct V_120 * V_94 ,
struct V_121 * V_122 , char * V_7 )
{
struct V_2 * V_3 = F_61 ( V_94 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
return snprintf ( V_7 , V_123 , L_10 , V_8 -> V_15 ) ;
}
static int F_62 ( struct V_1 * V_124 )
{
int V_51 = F_63 ( & V_124 -> V_3 . V_94 . V_125 , V_126 ) ;
if ( V_51 )
F_51 ( V_105
L_11 , V_51 ) ;
return V_51 ;
}
int F_64 ( struct V_2 * V_12 , const char * V_74 ,
long long V_15 , long long V_127 )
{
struct V_80 V_8 ;
struct V_1 * V_124 ;
int V_51 = 0 ;
if ( V_15 == V_98 ||
V_15 == V_99 )
return - V_27 ;
if ( V_127 == V_104 )
V_127 = V_12 -> V_26 - V_15 ;
if ( V_127 <= 0 )
return - V_27 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_74 = V_74 ;
V_8 . V_26 = V_127 ;
V_8 . V_15 = V_15 ;
V_124 = F_48 ( V_12 , & V_8 , - 1 , V_15 ) ;
if ( F_65 ( V_124 ) )
return F_66 ( V_124 ) ;
F_43 ( & V_78 ) ;
F_67 ( & V_124 -> V_79 , & V_128 ) ;
F_47 ( & V_78 ) ;
F_68 ( & V_124 -> V_3 ) ;
F_62 ( V_124 ) ;
return V_51 ;
}
int F_69 ( struct V_2 * V_12 , int V_81 )
{
struct V_1 * V_75 , * V_76 ;
int V_51 = - V_27 ;
F_43 ( & V_78 ) ;
F_44 (slave, next, &mtd_partitions, list)
if ( ( V_75 -> V_12 == V_12 ) &&
( V_75 -> V_3 . V_129 == V_81 ) ) {
F_70 ( & V_75 -> V_3 . V_94 . V_125 ,
V_126 ) ;
V_51 = F_45 ( & V_75 -> V_3 ) ;
if ( V_51 < 0 )
break;
F_46 ( & V_75 -> V_79 ) ;
F_40 ( V_75 ) ;
break;
}
F_47 ( & V_78 ) ;
return V_51 ;
}
int F_71 ( struct V_2 * V_12 ,
const struct V_80 * V_130 ,
int V_131 )
{
struct V_1 * V_75 ;
T_5 V_82 = 0 ;
int V_107 ;
F_51 ( V_101 L_12 , V_131 , V_12 -> V_74 ) ;
for ( V_107 = 0 ; V_107 < V_131 ; V_107 ++ ) {
V_75 = F_48 ( V_12 , V_130 + V_107 , V_107 , V_82 ) ;
if ( F_65 ( V_75 ) ) {
F_42 ( V_12 ) ;
return F_66 ( V_75 ) ;
}
F_43 ( & V_78 ) ;
F_67 ( & V_75 -> V_79 , & V_128 ) ;
F_47 ( & V_78 ) ;
F_68 ( & V_75 -> V_3 ) ;
F_62 ( V_75 ) ;
V_82 = V_75 -> V_15 + V_75 -> V_3 . V_26 ;
}
return 0 ;
}
static struct V_132 * F_72 ( const char * V_74 )
{
struct V_132 * V_73 , * V_51 = NULL ;
F_73 ( & V_133 ) ;
F_74 (p, &part_parsers, list)
if ( ! strcmp ( V_73 -> V_74 , V_74 ) && F_75 ( V_73 -> V_93 ) ) {
V_51 = V_73 ;
break;
}
F_76 ( & V_133 ) ;
return V_51 ;
}
static inline void F_77 ( const struct V_132 * V_73 )
{
F_78 ( V_73 -> V_93 ) ;
}
static void F_79 ( const struct V_80 * V_134 ,
int V_135 )
{
F_41 ( V_134 ) ;
}
int F_80 ( struct V_132 * V_73 , struct V_136 * V_93 )
{
V_73 -> V_93 = V_93 ;
if ( ! V_73 -> V_137 )
V_73 -> V_137 = & F_79 ;
F_73 ( & V_133 ) ;
F_67 ( & V_73 -> V_79 , & V_138 ) ;
F_76 ( & V_133 ) ;
return 0 ;
}
void F_81 ( struct V_132 * V_73 )
{
F_73 ( & V_133 ) ;
F_46 ( & V_73 -> V_79 ) ;
F_76 ( & V_133 ) ;
}
int F_82 ( struct V_2 * V_12 , const char * const * V_139 ,
struct V_128 * V_134 ,
struct V_140 * V_141 )
{
struct V_132 * V_142 ;
int V_51 , V_77 = 0 ;
if ( ! V_139 )
V_139 = V_143 ;
for ( ; * V_139 ; V_139 ++ ) {
F_83 ( L_13 , V_12 -> V_74 , * V_139 ) ;
V_142 = F_72 ( * V_139 ) ;
if ( ! V_142 && ! F_84 ( L_14 , * V_139 ) )
V_142 = F_72 ( * V_139 ) ;
F_83 ( L_15 , V_12 -> V_74 ,
V_142 ? V_142 -> V_74 : NULL ) ;
if ( ! V_142 )
continue;
V_51 = (* V_142 -> V_144 )( V_12 , & V_134 -> V_130 , V_141 ) ;
F_83 ( L_16 ,
V_12 -> V_74 , V_142 -> V_74 , V_51 ) ;
if ( V_51 > 0 ) {
F_51 ( V_101 L_17 ,
V_51 , V_142 -> V_74 , V_12 -> V_74 ) ;
V_134 -> V_135 = V_51 ;
V_134 -> V_142 = V_142 ;
return 0 ;
}
F_77 ( V_142 ) ;
if ( V_51 < 0 && ! V_77 )
V_77 = V_51 ;
}
return V_77 ;
}
void F_85 ( struct V_128 * V_130 )
{
const struct V_132 * V_142 ;
if ( ! V_130 )
return;
V_142 = V_130 -> V_142 ;
if ( V_142 ) {
if ( V_142 -> V_137 )
V_142 -> V_137 ( V_130 -> V_130 , V_130 -> V_135 ) ;
F_77 ( V_142 ) ;
}
}
int F_86 ( const struct V_2 * V_3 )
{
struct V_1 * V_8 ;
int V_145 = 0 ;
F_43 ( & V_78 ) ;
F_74 (part, &mtd_partitions, list)
if ( & V_8 -> V_3 == V_3 ) {
V_145 = 1 ;
break;
}
F_47 ( & V_78 ) ;
return V_145 ;
}
T_5 F_87 ( const struct V_2 * V_3 )
{
if ( ! F_86 ( V_3 ) )
return V_3 -> V_26 ;
return F_1 ( V_3 ) -> V_12 -> V_26 ;
}
