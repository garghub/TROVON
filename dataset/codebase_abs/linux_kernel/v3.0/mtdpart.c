static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 ;
int V_11 ;
V_10 = V_8 -> V_12 -> V_13 ;
if ( V_3 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_3 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_3 ;
V_11 = V_8 -> V_12 -> V_15 ( V_8 -> V_12 , V_3 + V_8 -> V_16 ,
V_4 , V_5 , V_6 ) ;
if ( F_3 ( V_11 ) ) {
if ( V_11 == - V_17 )
V_2 -> V_13 . V_18 += V_8 -> V_12 -> V_13 . V_18 - V_10 . V_18 ;
if ( V_11 == - V_19 )
V_2 -> V_13 . V_20 += V_8 -> V_12 -> V_13 . V_20 - V_10 . V_20 ;
}
return V_11 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_5 , void * * V_21 , T_4 * V_22 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_3 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_3 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_3 ;
return V_8 -> V_12 -> V_23 ( V_8 -> V_12 , V_3 + V_8 -> V_16 ,
V_4 , V_5 , V_21 , V_22 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_12 -> V_24 ( V_8 -> V_12 , V_3 + V_8 -> V_16 , V_4 ) ;
}
static unsigned long F_6 ( struct V_1 * V_2 ,
unsigned long V_4 ,
unsigned long V_16 ,
unsigned long V_25 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_16 += V_8 -> V_16 ;
return V_8 -> V_12 -> V_26 ( V_8 -> V_12 , V_4 , V_16 ,
V_25 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_27 * V_28 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
if ( V_3 >= V_2 -> V_14 )
return - V_29 ;
if ( V_28 -> V_30 && V_3 + V_28 -> V_4 > V_2 -> V_14 )
return - V_29 ;
if ( V_28 -> V_31 ) {
T_2 V_4 , V_32 ;
if ( V_28 -> V_33 == V_34 )
V_4 = V_2 -> V_35 ;
else
V_4 = V_2 -> V_36 ;
V_32 = F_8 ( V_2 -> V_14 , V_2 ) ;
V_32 -= F_8 ( V_3 , V_2 ) ;
if ( V_28 -> V_37 + V_28 -> V_38 > V_32 * V_4 )
return - V_29 ;
}
V_11 = V_8 -> V_12 -> V_39 ( V_8 -> V_12 , V_3 + V_8 -> V_16 , V_28 ) ;
if ( F_3 ( V_11 ) ) {
if ( V_11 == - V_17 )
V_2 -> V_13 . V_18 ++ ;
if ( V_11 == - V_19 )
V_2 -> V_13 . V_20 ++ ;
}
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_40 ( V_8 -> V_12 , V_3 ,
V_4 , V_5 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_41 * V_6 , T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_42 ( V_8 -> V_12 , V_6 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_43 ( V_8 -> V_12 , V_3 ,
V_4 , V_5 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_41 * V_6 ,
T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_44 ( V_8 -> V_12 , V_6 , V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_45 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_25 & V_46 ) )
return - V_47 ;
if ( V_45 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_45 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_45 ;
return V_8 -> V_12 -> V_48 ( V_8 -> V_12 , V_45 + V_8 -> V_16 ,
V_4 , V_5 , V_6 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_45 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_25 & V_46 ) )
return - V_47 ;
if ( V_45 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_45 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_45 ;
return V_8 -> V_12 -> V_49 ( V_8 -> V_12 , V_45 + V_8 -> V_16 ,
V_4 , V_5 , V_6 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_45 ,
struct V_27 * V_28 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_25 & V_46 ) )
return - V_47 ;
if ( V_45 >= V_2 -> V_14 )
return - V_29 ;
if ( V_28 -> V_30 && V_45 + V_28 -> V_4 > V_2 -> V_14 )
return - V_29 ;
return V_8 -> V_12 -> V_50 ( V_8 -> V_12 , V_45 + V_8 -> V_16 , V_28 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_51 ( V_8 -> V_12 , V_3 ,
V_4 , V_5 , V_6 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_52 ( V_8 -> V_12 , V_3 , V_4 ) ;
}
static int F_18 ( struct V_1 * V_2 , const struct V_53 * V_54 ,
unsigned long V_55 , T_1 V_45 , T_2 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_25 & V_46 ) )
return - V_47 ;
return V_8 -> V_12 -> V_56 ( V_8 -> V_12 , V_54 , V_55 ,
V_45 + V_8 -> V_16 , V_5 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_59 ;
if ( ! ( V_2 -> V_25 & V_46 ) )
return - V_47 ;
if ( V_58 -> V_60 >= V_2 -> V_14 )
return - V_29 ;
V_58 -> V_60 += V_8 -> V_16 ;
V_59 = V_8 -> V_12 -> V_61 ( V_8 -> V_12 , V_58 ) ;
if ( V_59 ) {
if ( V_58 -> V_62 != V_63 )
V_58 -> V_62 -= V_8 -> V_16 ;
V_58 -> V_60 -= V_8 -> V_16 ;
}
return V_59 ;
}
void F_20 ( struct V_57 * V_58 )
{
if ( V_58 -> V_2 -> V_61 == F_19 ) {
struct V_7 * V_8 = F_2 ( V_58 -> V_2 ) ;
if ( V_58 -> V_62 != V_63 )
V_58 -> V_62 -= V_8 -> V_16 ;
V_58 -> V_60 -= V_8 -> V_16 ;
}
if ( V_58 -> V_64 )
V_58 -> V_64 ( V_58 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_65 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_4 + V_65 ) > V_2 -> V_14 )
return - V_29 ;
return V_8 -> V_12 -> V_66 ( V_8 -> V_12 , V_65 + V_8 -> V_16 , V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_65 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_4 + V_65 ) > V_2 -> V_14 )
return - V_29 ;
return V_8 -> V_12 -> V_67 ( V_8 -> V_12 , V_65 + V_8 -> V_16 , V_4 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_65 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_4 + V_65 ) > V_2 -> V_14 )
return - V_29 ;
return V_8 -> V_12 -> V_68 ( V_8 -> V_12 , V_65 + V_8 -> V_16 , V_4 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_12 -> V_69 ( V_8 -> V_12 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_70 ( V_8 -> V_12 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_12 -> V_71 ( V_8 -> V_12 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_65 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_65 >= V_2 -> V_14 )
return - V_29 ;
V_65 += V_8 -> V_16 ;
return V_8 -> V_12 -> V_72 ( V_8 -> V_12 , V_65 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_65 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
if ( ! ( V_2 -> V_25 & V_46 ) )
return - V_47 ;
if ( V_65 >= V_2 -> V_14 )
return - V_29 ;
V_65 += V_8 -> V_16 ;
V_11 = V_8 -> V_12 -> V_73 ( V_8 -> V_12 , V_65 ) ;
if ( ! V_11 )
V_2 -> V_13 . V_74 ++ ;
return V_11 ;
}
static inline void F_29 ( struct V_7 * V_75 )
{
F_30 ( V_75 -> V_2 . V_76 ) ;
F_30 ( V_75 ) ;
}
int F_31 ( struct V_1 * V_12 )
{
struct V_7 * V_77 , * V_78 ;
int V_59 , V_79 = 0 ;
F_32 ( & V_80 ) ;
F_33 (slave, next, &mtd_partitions, list)
if ( V_77 -> V_12 == V_12 ) {
V_59 = F_34 ( & V_77 -> V_2 ) ;
if ( V_59 < 0 ) {
V_79 = V_59 ;
continue;
}
F_35 ( & V_77 -> V_81 ) ;
F_29 ( V_77 ) ;
}
F_36 ( & V_80 ) ;
return V_79 ;
}
static struct V_7 * F_37 ( struct V_1 * V_12 ,
const struct V_82 * V_8 , int V_83 ,
T_5 V_84 )
{
struct V_7 * V_77 ;
char * V_76 ;
V_77 = F_38 ( sizeof( * V_77 ) , V_85 ) ;
V_76 = F_39 ( V_8 -> V_76 , V_85 ) ;
if ( ! V_76 || ! V_77 ) {
F_40 ( V_86 L_1 ,
V_12 -> V_76 ) ;
F_30 ( V_76 ) ;
F_30 ( V_77 ) ;
return F_41 ( - V_87 ) ;
}
V_77 -> V_2 . type = V_12 -> type ;
V_77 -> V_2 . V_25 = V_12 -> V_25 & ~ V_8 -> V_88 ;
V_77 -> V_2 . V_14 = V_8 -> V_14 ;
V_77 -> V_2 . V_89 = V_12 -> V_89 ;
V_77 -> V_2 . V_90 = V_12 -> V_90 ;
V_77 -> V_2 . V_36 = V_12 -> V_36 ;
V_77 -> V_2 . V_35 = V_12 -> V_35 ;
V_77 -> V_2 . V_91 = V_12 -> V_91 ;
V_77 -> V_2 . V_76 = V_76 ;
V_77 -> V_2 . V_92 = V_12 -> V_92 ;
V_77 -> V_2 . V_93 = V_12 -> V_93 ;
V_77 -> V_2 . V_94 . V_95 = V_12 -> V_94 . V_95 ;
V_77 -> V_2 . V_15 = F_1 ;
V_77 -> V_2 . V_48 = F_13 ;
if ( V_12 -> V_49 )
V_77 -> V_2 . V_49 = F_14 ;
if ( V_12 -> V_23 && V_12 -> V_24 ) {
V_77 -> V_2 . V_23 = F_4 ;
V_77 -> V_2 . V_24 = F_5 ;
}
if ( V_12 -> V_26 )
V_77 -> V_2 . V_26 = F_6 ;
if ( V_12 -> V_39 )
V_77 -> V_2 . V_39 = F_7 ;
if ( V_12 -> V_50 )
V_77 -> V_2 . V_50 = F_15 ;
if ( V_12 -> V_40 )
V_77 -> V_2 . V_40 = F_9 ;
if ( V_12 -> V_43 )
V_77 -> V_2 . V_43 = F_11 ;
if ( V_12 -> V_51 )
V_77 -> V_2 . V_51 = F_16 ;
if ( V_12 -> V_52 )
V_77 -> V_2 . V_52 = F_17 ;
if ( V_12 -> V_42 )
V_77 -> V_2 . V_42 = F_10 ;
if ( V_12 -> V_44 )
V_77 -> V_2 . V_44 = F_12 ;
if ( V_12 -> V_69 )
V_77 -> V_2 . V_69 = F_24 ;
if ( ! V_83 && ! V_12 -> V_94 . V_96 && V_12 -> V_70 && V_12 -> V_71 ) {
V_77 -> V_2 . V_70 = F_25 ;
V_77 -> V_2 . V_71 = F_26 ;
}
if ( V_12 -> V_56 )
V_77 -> V_2 . V_56 = F_18 ;
if ( V_12 -> V_66 )
V_77 -> V_2 . V_66 = F_21 ;
if ( V_12 -> V_67 )
V_77 -> V_2 . V_67 = F_22 ;
if ( V_12 -> V_68 )
V_77 -> V_2 . V_68 = F_23 ;
if ( V_12 -> V_72 )
V_77 -> V_2 . V_72 = F_27 ;
if ( V_12 -> V_73 )
V_77 -> V_2 . V_73 = F_28 ;
V_77 -> V_2 . V_61 = F_19 ;
V_77 -> V_12 = V_12 ;
V_77 -> V_16 = V_8 -> V_16 ;
if ( V_77 -> V_16 == V_97 )
V_77 -> V_16 = V_84 ;
if ( V_77 -> V_16 == V_98 ) {
V_77 -> V_16 = V_84 ;
if ( F_42 ( V_84 , V_12 ) != 0 ) {
V_77 -> V_16 = ( F_43 ( V_84 , V_12 ) + 1 ) * V_12 -> V_99 ;
F_40 ( V_100 L_2
L_3 , V_83 ,
( unsigned long long ) V_84 , ( unsigned long long ) V_77 -> V_16 ) ;
}
}
if ( V_77 -> V_2 . V_14 == V_101 )
V_77 -> V_2 . V_14 = V_12 -> V_14 - V_77 -> V_16 ;
F_40 ( V_100 L_4 , ( unsigned long long ) V_77 -> V_16 ,
( unsigned long long ) ( V_77 -> V_16 + V_77 -> V_2 . V_14 ) , V_77 -> V_2 . V_76 ) ;
if ( V_77 -> V_16 >= V_12 -> V_14 ) {
V_77 -> V_16 = 0 ;
V_77 -> V_2 . V_14 = 0 ;
F_40 ( V_86 L_5 ,
V_8 -> V_76 ) ;
goto V_102;
}
if ( V_77 -> V_16 + V_77 -> V_2 . V_14 > V_12 -> V_14 ) {
V_77 -> V_2 . V_14 = V_12 -> V_14 - V_77 -> V_16 ;
F_40 ( V_103 L_6 ,
V_8 -> V_76 , V_12 -> V_76 , ( unsigned long long ) V_77 -> V_2 . V_14 ) ;
}
if ( V_12 -> V_104 > 1 ) {
int V_105 , V_106 = V_12 -> V_104 ;
T_6 V_107 = V_77 -> V_16 + V_77 -> V_2 . V_14 ;
struct V_108 * V_109 = V_12 -> V_110 ;
for ( V_105 = 0 ; V_105 < V_106 && V_109 [ V_105 ] . V_16 <= V_77 -> V_16 ; V_105 ++ )
;
if ( V_105 > 0 )
V_105 -- ;
for (; V_105 < V_106 && V_109 [ V_105 ] . V_16 < V_107 ; V_105 ++ ) {
if ( V_77 -> V_2 . V_99 < V_109 [ V_105 ] . V_99 ) {
V_77 -> V_2 . V_99 = V_109 [ V_105 ] . V_99 ;
}
}
F_44 ( V_77 -> V_2 . V_99 == 0 ) ;
} else {
V_77 -> V_2 . V_99 = V_12 -> V_99 ;
}
if ( ( V_77 -> V_2 . V_25 & V_46 ) &&
F_42 ( V_77 -> V_16 , & V_77 -> V_2 ) ) {
V_77 -> V_2 . V_25 &= ~ V_46 ;
F_40 ( V_103 L_7 ,
V_8 -> V_76 ) ;
}
if ( ( V_77 -> V_2 . V_25 & V_46 ) &&
F_42 ( V_77 -> V_2 . V_14 , & V_77 -> V_2 ) ) {
V_77 -> V_2 . V_25 &= ~ V_46 ;
F_40 ( V_103 L_8 ,
V_8 -> V_76 ) ;
}
V_77 -> V_2 . V_111 = V_12 -> V_111 ;
if ( V_12 -> V_72 ) {
T_5 V_112 = 0 ;
while ( V_112 < V_77 -> V_2 . V_14 ) {
if ( V_12 -> V_72 ( V_12 ,
V_112 + V_77 -> V_16 ) )
V_77 -> V_2 . V_13 . V_74 ++ ;
V_112 += V_77 -> V_2 . V_99 ;
}
}
V_102:
return V_77 ;
}
int F_45 ( struct V_1 * V_12 , char * V_76 ,
long long V_16 , long long V_113 )
{
struct V_82 V_8 ;
struct V_7 * V_75 , * V_114 ;
T_5 V_115 , V_107 ;
int V_59 = 0 ;
if ( V_16 == V_97 ||
V_16 == V_98 )
return - V_29 ;
if ( V_113 == V_101 )
V_113 = V_12 -> V_14 - V_16 ;
if ( V_113 <= 0 )
return - V_29 ;
V_8 . V_76 = V_76 ;
V_8 . V_14 = V_113 ;
V_8 . V_16 = V_16 ;
V_8 . V_88 = 0 ;
V_8 . V_111 = NULL ;
V_114 = F_37 ( V_12 , & V_8 , - 1 , V_16 ) ;
if ( F_46 ( V_114 ) )
return F_47 ( V_114 ) ;
V_115 = V_16 ;
V_107 = V_16 + V_113 ;
F_32 ( & V_80 ) ;
F_48 (p, &mtd_partitions, list)
if ( V_75 -> V_12 == V_12 ) {
if ( ( V_115 >= V_75 -> V_16 ) &&
( V_115 < ( V_75 -> V_16 + V_75 -> V_2 . V_14 ) ) )
goto V_116;
if ( ( V_107 >= V_75 -> V_16 ) &&
( V_107 < ( V_75 -> V_16 + V_75 -> V_2 . V_14 ) ) )
goto V_116;
}
F_49 ( & V_114 -> V_81 , & V_117 ) ;
F_36 ( & V_80 ) ;
F_50 ( & V_114 -> V_2 ) ;
return V_59 ;
V_116:
F_36 ( & V_80 ) ;
F_29 ( V_114 ) ;
return - V_29 ;
}
int F_51 ( struct V_1 * V_12 , int V_83 )
{
struct V_7 * V_77 , * V_78 ;
int V_59 = - V_29 ;
F_32 ( & V_80 ) ;
F_33 (slave, next, &mtd_partitions, list)
if ( ( V_77 -> V_12 == V_12 ) &&
( V_77 -> V_2 . V_118 == V_83 ) ) {
V_59 = F_34 ( & V_77 -> V_2 ) ;
if ( V_59 < 0 )
break;
F_35 ( & V_77 -> V_81 ) ;
F_29 ( V_77 ) ;
break;
}
F_36 ( & V_80 ) ;
return V_59 ;
}
int F_52 ( struct V_1 * V_12 ,
const struct V_82 * V_119 ,
int V_120 )
{
struct V_7 * V_77 ;
T_5 V_84 = 0 ;
int V_105 ;
F_40 ( V_100 L_9 , V_120 , V_12 -> V_76 ) ;
for ( V_105 = 0 ; V_105 < V_120 ; V_105 ++ ) {
V_77 = F_37 ( V_12 , V_119 + V_105 , V_105 , V_84 ) ;
if ( F_46 ( V_77 ) )
return F_47 ( V_77 ) ;
F_32 ( & V_80 ) ;
F_49 ( & V_77 -> V_81 , & V_117 ) ;
F_36 ( & V_80 ) ;
F_50 ( & V_77 -> V_2 ) ;
V_84 = V_77 -> V_16 + V_77 -> V_2 . V_14 ;
}
return 0 ;
}
static struct V_121 * F_53 ( const char * V_76 )
{
struct V_121 * V_75 , * V_59 = NULL ;
F_54 ( & V_122 ) ;
F_48 (p, &part_parsers, list)
if ( ! strcmp ( V_75 -> V_76 , V_76 ) && F_55 ( V_75 -> V_92 ) ) {
V_59 = V_75 ;
break;
}
F_56 ( & V_122 ) ;
return V_59 ;
}
int F_57 ( struct V_121 * V_75 )
{
F_54 ( & V_122 ) ;
F_49 ( & V_75 -> V_81 , & V_123 ) ;
F_56 ( & V_122 ) ;
return 0 ;
}
int F_58 ( struct V_121 * V_75 )
{
F_54 ( & V_122 ) ;
F_35 ( & V_75 -> V_81 ) ;
F_56 ( & V_122 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_12 , const char * * V_124 ,
struct V_82 * * V_125 , unsigned long V_126 )
{
struct V_121 * V_127 ;
int V_59 = 0 ;
for ( ; V_59 <= 0 && * V_124 ; V_124 ++ ) {
V_127 = F_53 ( * V_124 ) ;
if ( ! V_127 && ! F_60 ( L_10 , * V_124 ) )
V_127 = F_53 ( * V_124 ) ;
if ( ! V_127 )
continue;
V_59 = (* V_127 -> V_128 )( V_12 , V_125 , V_126 ) ;
if ( V_59 > 0 ) {
F_40 ( V_100 L_11 ,
V_59 , V_127 -> V_76 , V_12 -> V_76 ) ;
}
F_61 ( V_127 ) ;
}
return V_59 ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_129 = 0 ;
F_32 ( & V_80 ) ;
F_48 (part, &mtd_partitions, list)
if ( & V_8 -> V_2 == V_2 ) {
V_129 = 1 ;
break;
}
F_36 ( & V_80 ) ;
return V_129 ;
}
