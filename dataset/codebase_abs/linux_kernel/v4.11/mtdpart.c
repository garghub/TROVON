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
static int F_40 ( struct V_2 * V_3 , T_1 V_57 , T_2 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_73 ( V_8 -> V_12 ,
V_57 + V_8 -> V_15 , V_5 ) ;
}
static inline void F_41 ( struct V_1 * V_74 )
{
F_42 ( V_74 -> V_3 . V_75 ) ;
F_42 ( V_74 ) ;
}
int F_43 ( struct V_2 * V_12 )
{
struct V_1 * V_76 , * V_77 ;
int V_51 , V_78 = 0 ;
F_44 ( & V_79 ) ;
F_45 (slave, next, &mtd_partitions, list)
if ( V_76 -> V_12 == V_12 ) {
V_51 = F_46 ( & V_76 -> V_3 ) ;
if ( V_51 < 0 ) {
V_78 = V_51 ;
continue;
}
F_47 ( & V_76 -> V_80 ) ;
F_41 ( V_76 ) ;
}
F_48 ( & V_79 ) ;
return V_78 ;
}
static struct V_1 * F_49 ( struct V_2 * V_12 ,
const struct V_81 * V_8 , int V_82 ,
T_5 V_83 )
{
struct V_1 * V_76 ;
char * V_75 ;
V_76 = F_50 ( sizeof( * V_76 ) , V_84 ) ;
V_75 = F_51 ( V_8 -> V_75 , V_84 ) ;
if ( ! V_75 || ! V_76 ) {
F_52 ( V_85 L_1 ,
V_12 -> V_75 ) ;
F_42 ( V_75 ) ;
F_42 ( V_76 ) ;
return F_53 ( - V_86 ) ;
}
V_76 -> V_3 . type = V_12 -> type ;
V_76 -> V_3 . V_22 = V_12 -> V_22 & ~ V_8 -> V_87 ;
V_76 -> V_3 . V_26 = V_8 -> V_26 ;
V_76 -> V_3 . V_88 = V_12 -> V_88 ;
V_76 -> V_3 . V_89 = V_12 -> V_89 ;
V_76 -> V_3 . V_90 = V_12 -> V_90 ;
V_76 -> V_3 . V_91 = V_12 -> V_91 ;
V_76 -> V_3 . V_92 = V_12 -> V_92 ;
V_76 -> V_3 . V_93 = V_12 -> V_93 ;
V_76 -> V_3 . V_75 = V_75 ;
V_76 -> V_3 . V_94 = V_12 -> V_94 ;
V_76 -> V_3 . V_95 . V_96 = F_54 ( V_97 ) ?
& V_12 -> V_95 :
V_12 -> V_95 . V_96 ;
V_76 -> V_3 . V_95 . V_98 = V_8 -> V_98 ;
V_76 -> V_3 . V_14 = F_3 ;
V_76 -> V_3 . V_40 = F_17 ;
if ( V_12 -> V_41 )
V_76 -> V_3 . V_41 = F_18 ;
if ( V_12 -> V_20 && V_12 -> V_21 ) {
V_76 -> V_3 . V_20 = F_6 ;
V_76 -> V_3 . V_21 = F_7 ;
}
if ( V_12 -> V_23 )
V_76 -> V_3 . V_23 = F_8 ;
if ( V_12 -> V_33 )
V_76 -> V_3 . V_33 = F_9 ;
if ( V_12 -> V_42 )
V_76 -> V_3 . V_42 = F_19 ;
if ( V_12 -> V_34 )
V_76 -> V_3 . V_34 = F_13 ;
if ( V_12 -> V_37 )
V_76 -> V_3 . V_37 = F_15 ;
if ( V_12 -> V_43 )
V_76 -> V_3 . V_43 = F_20 ;
if ( V_12 -> V_44 )
V_76 -> V_3 . V_44 = F_21 ;
if ( V_12 -> V_36 )
V_76 -> V_3 . V_36 = F_14 ;
if ( V_12 -> V_38 )
V_76 -> V_3 . V_38 = F_16 ;
if ( V_12 -> V_61 )
V_76 -> V_3 . V_61 = F_28 ;
if ( ! V_82 && ! V_12 -> V_95 . V_99 && V_12 -> V_62 &&
V_12 -> V_63 ) {
V_76 -> V_3 . V_62 = F_29 ;
V_76 -> V_3 . V_63 = F_30 ;
}
if ( V_12 -> V_48 )
V_76 -> V_3 . V_48 = F_22 ;
if ( V_12 -> V_58 )
V_76 -> V_3 . V_58 = F_25 ;
if ( V_12 -> V_59 )
V_76 -> V_3 . V_59 = F_26 ;
if ( V_12 -> V_60 )
V_76 -> V_3 . V_60 = F_27 ;
if ( V_12 -> V_64 )
V_76 -> V_3 . V_64 = F_31 ;
if ( V_12 -> V_65 )
V_76 -> V_3 . V_65 = F_32 ;
if ( V_12 -> V_66 )
V_76 -> V_3 . V_66 = F_33 ;
if ( V_12 -> V_73 )
V_76 -> V_3 . V_73 = F_40 ;
if ( V_12 -> V_68 )
V_76 -> V_3 . V_68 = F_34 ;
if ( V_12 -> V_69 )
V_76 -> V_3 . V_69 = F_35 ;
V_76 -> V_3 . V_53 = F_23 ;
V_76 -> V_12 = V_12 ;
V_76 -> V_15 = V_8 -> V_15 ;
if ( V_76 -> V_15 == V_100 )
V_76 -> V_15 = V_83 ;
if ( V_76 -> V_15 == V_101 ) {
V_76 -> V_15 = V_83 ;
if ( F_55 ( V_83 , V_12 ) != 0 ) {
V_76 -> V_15 = ( F_56 ( V_83 , V_12 ) + 1 ) * V_12 -> V_102 ;
F_52 ( V_103 L_2
L_3 , V_82 ,
( unsigned long long ) V_83 , ( unsigned long long ) V_76 -> V_15 ) ;
}
}
if ( V_76 -> V_15 == V_104 ) {
V_76 -> V_15 = V_83 ;
if ( V_12 -> V_26 - V_76 -> V_15 >= V_76 -> V_3 . V_26 ) {
V_76 -> V_3 . V_26 = V_12 -> V_26 - V_76 -> V_15
- V_76 -> V_3 . V_26 ;
} else {
F_52 ( V_85 L_4 ,
V_8 -> V_75 , V_12 -> V_26 - V_76 -> V_15 ,
V_76 -> V_3 . V_26 ) ;
goto V_105;
}
}
if ( V_76 -> V_3 . V_26 == V_106 )
V_76 -> V_3 . V_26 = V_12 -> V_26 - V_76 -> V_15 ;
F_52 ( V_103 L_5 , ( unsigned long long ) V_76 -> V_15 ,
( unsigned long long ) ( V_76 -> V_15 + V_76 -> V_3 . V_26 ) , V_76 -> V_3 . V_75 ) ;
if ( V_76 -> V_15 >= V_12 -> V_26 ) {
V_76 -> V_15 = 0 ;
V_76 -> V_3 . V_26 = 0 ;
F_52 ( V_85 L_6 ,
V_8 -> V_75 ) ;
goto V_105;
}
if ( V_76 -> V_15 + V_76 -> V_3 . V_26 > V_12 -> V_26 ) {
V_76 -> V_3 . V_26 = V_12 -> V_26 - V_76 -> V_15 ;
F_52 ( V_107 L_7 ,
V_8 -> V_75 , V_12 -> V_75 , ( unsigned long long ) V_76 -> V_3 . V_26 ) ;
}
if ( V_12 -> V_108 > 1 ) {
int V_109 , V_110 = V_12 -> V_108 ;
T_6 V_111 = V_76 -> V_15 + V_76 -> V_3 . V_26 ;
struct V_112 * V_113 = V_12 -> V_114 ;
for ( V_109 = 0 ; V_109 < V_110 && V_113 [ V_109 ] . V_15 <= V_76 -> V_15 ; V_109 ++ )
;
if ( V_109 > 0 )
V_109 -- ;
for (; V_109 < V_110 && V_113 [ V_109 ] . V_15 < V_111 ; V_109 ++ ) {
if ( V_76 -> V_3 . V_102 < V_113 [ V_109 ] . V_102 ) {
V_76 -> V_3 . V_102 = V_113 [ V_109 ] . V_102 ;
}
}
F_57 ( V_76 -> V_3 . V_102 == 0 ) ;
} else {
V_76 -> V_3 . V_102 = V_12 -> V_102 ;
}
if ( ( V_76 -> V_3 . V_22 & V_115 ) &&
F_55 ( V_76 -> V_15 , & V_76 -> V_3 ) ) {
V_76 -> V_3 . V_22 &= ~ V_115 ;
F_52 ( V_107 L_8 ,
V_8 -> V_75 ) ;
}
if ( ( V_76 -> V_3 . V_22 & V_115 ) &&
F_55 ( V_76 -> V_3 . V_26 , & V_76 -> V_3 ) ) {
V_76 -> V_3 . V_22 &= ~ V_115 ;
F_52 ( V_107 L_9 ,
V_8 -> V_75 ) ;
}
F_58 ( & V_76 -> V_3 , & V_116 ) ;
V_76 -> V_3 . V_117 = V_12 -> V_117 ;
V_76 -> V_3 . V_118 = V_12 -> V_118 ;
V_76 -> V_3 . V_119 = V_12 -> V_119 ;
if ( V_12 -> V_65 ) {
T_5 V_120 = 0 ;
while ( V_120 < V_76 -> V_3 . V_26 ) {
if ( F_59 ( V_12 , V_120 + V_76 -> V_15 ) )
V_76 -> V_3 . V_13 . V_121 ++ ;
else if ( F_60 ( V_12 , V_120 + V_76 -> V_15 ) )
V_76 -> V_3 . V_13 . V_67 ++ ;
V_120 += V_76 -> V_3 . V_102 ;
}
}
V_105:
return V_76 ;
}
static T_7 F_61 ( struct V_122 * V_95 ,
struct V_123 * V_124 , char * V_7 )
{
struct V_2 * V_3 = F_62 ( V_95 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
return snprintf ( V_7 , V_125 , L_10 , V_8 -> V_15 ) ;
}
static int F_63 ( struct V_1 * V_126 )
{
int V_51 = F_64 ( & V_126 -> V_3 . V_95 . V_127 , V_128 ) ;
if ( V_51 )
F_52 ( V_107
L_11 , V_51 ) ;
return V_51 ;
}
int F_65 ( struct V_2 * V_12 , const char * V_75 ,
long long V_15 , long long V_129 )
{
struct V_81 V_8 ;
struct V_1 * V_126 ;
int V_51 = 0 ;
if ( V_15 == V_100 ||
V_15 == V_101 )
return - V_27 ;
if ( V_129 == V_106 )
V_129 = V_12 -> V_26 - V_15 ;
if ( V_129 <= 0 )
return - V_27 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_75 = V_75 ;
V_8 . V_26 = V_129 ;
V_8 . V_15 = V_15 ;
V_126 = F_49 ( V_12 , & V_8 , - 1 , V_15 ) ;
if ( F_66 ( V_126 ) )
return F_67 ( V_126 ) ;
F_44 ( & V_79 ) ;
F_68 ( & V_126 -> V_80 , & V_130 ) ;
F_48 ( & V_79 ) ;
F_69 ( & V_126 -> V_3 ) ;
F_63 ( V_126 ) ;
return V_51 ;
}
int F_70 ( struct V_2 * V_12 , int V_82 )
{
struct V_1 * V_76 , * V_77 ;
int V_51 = - V_27 ;
F_44 ( & V_79 ) ;
F_45 (slave, next, &mtd_partitions, list)
if ( ( V_76 -> V_12 == V_12 ) &&
( V_76 -> V_3 . V_131 == V_82 ) ) {
F_71 ( & V_76 -> V_3 . V_95 . V_127 ,
V_128 ) ;
V_51 = F_46 ( & V_76 -> V_3 ) ;
if ( V_51 < 0 )
break;
F_47 ( & V_76 -> V_80 ) ;
F_41 ( V_76 ) ;
break;
}
F_48 ( & V_79 ) ;
return V_51 ;
}
int F_72 ( struct V_2 * V_12 ,
const struct V_81 * V_132 ,
int V_133 )
{
struct V_1 * V_76 ;
T_5 V_83 = 0 ;
int V_109 ;
F_52 ( V_103 L_12 , V_133 , V_12 -> V_75 ) ;
for ( V_109 = 0 ; V_109 < V_133 ; V_109 ++ ) {
V_76 = F_49 ( V_12 , V_132 + V_109 , V_109 , V_83 ) ;
if ( F_66 ( V_76 ) ) {
F_43 ( V_12 ) ;
return F_67 ( V_76 ) ;
}
F_44 ( & V_79 ) ;
F_68 ( & V_76 -> V_80 , & V_130 ) ;
F_48 ( & V_79 ) ;
F_69 ( & V_76 -> V_3 ) ;
F_63 ( V_76 ) ;
V_83 = V_76 -> V_15 + V_76 -> V_3 . V_26 ;
}
return 0 ;
}
static struct V_134 * F_73 ( const char * V_75 )
{
struct V_134 * V_74 , * V_51 = NULL ;
F_74 ( & V_135 ) ;
F_75 (p, &part_parsers, list)
if ( ! strcmp ( V_74 -> V_75 , V_75 ) && F_76 ( V_74 -> V_94 ) ) {
V_51 = V_74 ;
break;
}
F_77 ( & V_135 ) ;
return V_51 ;
}
static inline void F_78 ( const struct V_134 * V_74 )
{
F_79 ( V_74 -> V_94 ) ;
}
static void F_80 ( const struct V_81 * V_136 ,
int V_137 )
{
F_42 ( V_136 ) ;
}
int F_81 ( struct V_134 * V_74 , struct V_138 * V_94 )
{
V_74 -> V_94 = V_94 ;
if ( ! V_74 -> V_139 )
V_74 -> V_139 = & F_80 ;
F_74 ( & V_135 ) ;
F_68 ( & V_74 -> V_80 , & V_140 ) ;
F_77 ( & V_135 ) ;
return 0 ;
}
void F_82 ( struct V_134 * V_74 )
{
F_74 ( & V_135 ) ;
F_47 ( & V_74 -> V_80 ) ;
F_77 ( & V_135 ) ;
}
int F_83 ( struct V_2 * V_12 , const char * const * V_141 ,
struct V_130 * V_136 ,
struct V_142 * V_143 )
{
struct V_134 * V_144 ;
int V_51 , V_78 = 0 ;
if ( ! V_141 )
V_141 = V_145 ;
for ( ; * V_141 ; V_141 ++ ) {
F_84 ( L_13 , V_12 -> V_75 , * V_141 ) ;
V_144 = F_73 ( * V_141 ) ;
if ( ! V_144 && ! F_85 ( L_14 , * V_141 ) )
V_144 = F_73 ( * V_141 ) ;
F_84 ( L_15 , V_12 -> V_75 ,
V_144 ? V_144 -> V_75 : NULL ) ;
if ( ! V_144 )
continue;
V_51 = (* V_144 -> V_146 )( V_12 , & V_136 -> V_132 , V_143 ) ;
F_84 ( L_16 ,
V_12 -> V_75 , V_144 -> V_75 , V_51 ) ;
if ( V_51 > 0 ) {
F_52 ( V_103 L_17 ,
V_51 , V_144 -> V_75 , V_12 -> V_75 ) ;
V_136 -> V_137 = V_51 ;
V_136 -> V_144 = V_144 ;
return 0 ;
}
F_78 ( V_144 ) ;
if ( V_51 < 0 && ! V_78 )
V_78 = V_51 ;
}
return V_78 ;
}
void F_86 ( struct V_130 * V_132 )
{
const struct V_134 * V_144 ;
if ( ! V_132 )
return;
V_144 = V_132 -> V_144 ;
if ( V_144 ) {
if ( V_144 -> V_139 )
V_144 -> V_139 ( V_132 -> V_132 , V_132 -> V_137 ) ;
F_78 ( V_144 ) ;
}
}
int F_87 ( const struct V_2 * V_3 )
{
struct V_1 * V_8 ;
int V_147 = 0 ;
F_44 ( & V_79 ) ;
F_75 (part, &mtd_partitions, list)
if ( & V_8 -> V_3 == V_3 ) {
V_147 = 1 ;
break;
}
F_48 ( & V_79 ) ;
return V_147 ;
}
T_5 F_88 ( const struct V_2 * V_3 )
{
if ( ! F_87 ( V_3 ) )
return V_3 -> V_26 ;
return F_1 ( V_3 ) -> V_12 -> V_26 ;
}
