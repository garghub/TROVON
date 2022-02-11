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
if ( F_4 ( V_11 ) )
V_2 -> V_13 . V_17 += V_8 -> V_12 -> V_13 . V_17 - V_10 . V_17 ;
if ( F_5 ( V_11 ) )
V_2 -> V_13 . V_18 += V_8 -> V_12 -> V_13 . V_18 - V_10 . V_18 ;
}
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_5 , void * * V_19 , T_4 * V_20 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_3 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_3 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_3 ;
return V_8 -> V_12 -> V_21 ( V_8 -> V_12 , V_3 + V_8 -> V_16 ,
V_4 , V_5 , V_19 , V_20 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_12 -> V_22 ( V_8 -> V_12 , V_3 + V_8 -> V_16 , V_4 ) ;
}
static unsigned long F_8 ( struct V_1 * V_2 ,
unsigned long V_4 ,
unsigned long V_16 ,
unsigned long V_23 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_16 += V_8 -> V_16 ;
return V_8 -> V_12 -> V_24 ( V_8 -> V_12 , V_4 , V_16 ,
V_23 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_25 * V_26 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
if ( V_3 >= V_2 -> V_14 )
return - V_27 ;
if ( V_26 -> V_28 && V_3 + V_26 -> V_4 > V_2 -> V_14 )
return - V_27 ;
if ( V_26 -> V_29 ) {
T_2 V_4 , V_30 ;
if ( V_26 -> V_31 == V_32 )
V_4 = V_2 -> V_33 ;
else
V_4 = V_2 -> V_34 ;
V_30 = F_10 ( V_2 -> V_14 , V_2 ) ;
V_30 -= F_10 ( V_3 , V_2 ) ;
if ( V_26 -> V_35 + V_26 -> V_36 > V_30 * V_4 )
return - V_27 ;
}
V_11 = V_8 -> V_12 -> V_37 ( V_8 -> V_12 , V_3 + V_8 -> V_16 , V_26 ) ;
if ( F_3 ( V_11 ) ) {
if ( F_4 ( V_11 ) )
V_2 -> V_13 . V_17 ++ ;
if ( F_5 ( V_11 ) )
V_2 -> V_13 . V_18 ++ ;
}
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_38 ( V_8 -> V_12 , V_3 ,
V_4 , V_5 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_39 * V_6 , T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_40 ( V_8 -> V_12 , V_6 , V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_41 ( V_8 -> V_12 , V_3 ,
V_4 , V_5 , V_6 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_39 * V_6 ,
T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_42 ( V_8 -> V_12 , V_6 , V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_43 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_23 & V_44 ) )
return - V_45 ;
if ( V_43 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_43 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_43 ;
return V_8 -> V_12 -> V_46 ( V_8 -> V_12 , V_43 + V_8 -> V_16 ,
V_4 , V_5 , V_6 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_43 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_23 & V_44 ) )
return - V_45 ;
if ( V_43 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_43 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_43 ;
return V_8 -> V_12 -> V_47 ( V_8 -> V_12 , V_43 + V_8 -> V_16 ,
V_4 , V_5 , V_6 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_43 ,
struct V_25 * V_26 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_23 & V_44 ) )
return - V_45 ;
if ( V_43 >= V_2 -> V_14 )
return - V_27 ;
if ( V_26 -> V_28 && V_43 + V_26 -> V_4 > V_2 -> V_14 )
return - V_27 ;
return V_8 -> V_12 -> V_48 ( V_8 -> V_12 , V_43 + V_8 -> V_16 , V_26 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_49 ( V_8 -> V_12 , V_3 ,
V_4 , V_5 , V_6 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_50 ( V_8 -> V_12 , V_3 , V_4 ) ;
}
static int F_20 ( struct V_1 * V_2 , const struct V_51 * V_52 ,
unsigned long V_53 , T_1 V_43 , T_2 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_23 & V_44 ) )
return - V_45 ;
return V_8 -> V_12 -> V_54 ( V_8 -> V_12 , V_52 , V_53 ,
V_43 + V_8 -> V_16 , V_5 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_57 ;
if ( ! ( V_2 -> V_23 & V_44 ) )
return - V_45 ;
if ( V_56 -> V_58 >= V_2 -> V_14 )
return - V_27 ;
V_56 -> V_58 += V_8 -> V_16 ;
V_57 = V_8 -> V_12 -> V_59 ( V_8 -> V_12 , V_56 ) ;
if ( V_57 ) {
if ( V_56 -> V_60 != V_61 )
V_56 -> V_60 -= V_8 -> V_16 ;
V_56 -> V_58 -= V_8 -> V_16 ;
}
return V_57 ;
}
void F_22 ( struct V_55 * V_56 )
{
if ( V_56 -> V_2 -> V_59 == F_21 ) {
struct V_7 * V_8 = F_2 ( V_56 -> V_2 ) ;
if ( V_56 -> V_60 != V_61 )
V_56 -> V_60 -= V_8 -> V_16 ;
V_56 -> V_58 -= V_8 -> V_16 ;
}
if ( V_56 -> V_62 )
V_56 -> V_62 ( V_56 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_63 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_4 + V_63 ) > V_2 -> V_14 )
return - V_27 ;
return V_8 -> V_12 -> V_64 ( V_8 -> V_12 , V_63 + V_8 -> V_16 , V_4 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_63 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_4 + V_63 ) > V_2 -> V_14 )
return - V_27 ;
return V_8 -> V_12 -> V_65 ( V_8 -> V_12 , V_63 + V_8 -> V_16 , V_4 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_63 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_4 + V_63 ) > V_2 -> V_14 )
return - V_27 ;
return V_8 -> V_12 -> V_66 ( V_8 -> V_12 , V_63 + V_8 -> V_16 , V_4 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_12 -> V_67 ( V_8 -> V_12 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_68 ( V_8 -> V_12 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_12 -> V_69 ( V_8 -> V_12 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_63 >= V_2 -> V_14 )
return - V_27 ;
V_63 += V_8 -> V_16 ;
return V_8 -> V_12 -> V_70 ( V_8 -> V_12 , V_63 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
if ( ! ( V_2 -> V_23 & V_44 ) )
return - V_45 ;
if ( V_63 >= V_2 -> V_14 )
return - V_27 ;
V_63 += V_8 -> V_16 ;
V_11 = V_8 -> V_12 -> V_71 ( V_8 -> V_12 , V_63 ) ;
if ( ! V_11 )
V_2 -> V_13 . V_72 ++ ;
return V_11 ;
}
static inline void F_31 ( struct V_7 * V_73 )
{
F_32 ( V_73 -> V_2 . V_74 ) ;
F_32 ( V_73 ) ;
}
int F_33 ( struct V_1 * V_12 )
{
struct V_7 * V_75 , * V_76 ;
int V_57 , V_77 = 0 ;
F_34 ( & V_78 ) ;
F_35 (slave, next, &mtd_partitions, list)
if ( V_75 -> V_12 == V_12 ) {
V_57 = F_36 ( & V_75 -> V_2 ) ;
if ( V_57 < 0 ) {
V_77 = V_57 ;
continue;
}
F_37 ( & V_75 -> V_79 ) ;
F_31 ( V_75 ) ;
}
F_38 ( & V_78 ) ;
return V_77 ;
}
static struct V_7 * F_39 ( struct V_1 * V_12 ,
const struct V_80 * V_8 , int V_81 ,
T_5 V_82 )
{
struct V_7 * V_75 ;
char * V_74 ;
V_75 = F_40 ( sizeof( * V_75 ) , V_83 ) ;
V_74 = F_41 ( V_8 -> V_74 , V_83 ) ;
if ( ! V_74 || ! V_75 ) {
F_42 ( V_84 L_1 ,
V_12 -> V_74 ) ;
F_32 ( V_74 ) ;
F_32 ( V_75 ) ;
return F_43 ( - V_85 ) ;
}
V_75 -> V_2 . type = V_12 -> type ;
V_75 -> V_2 . V_23 = V_12 -> V_23 & ~ V_8 -> V_86 ;
V_75 -> V_2 . V_14 = V_8 -> V_14 ;
V_75 -> V_2 . V_87 = V_12 -> V_87 ;
V_75 -> V_2 . V_88 = V_12 -> V_88 ;
V_75 -> V_2 . V_34 = V_12 -> V_34 ;
V_75 -> V_2 . V_33 = V_12 -> V_33 ;
V_75 -> V_2 . V_89 = V_12 -> V_89 ;
V_75 -> V_2 . V_74 = V_74 ;
V_75 -> V_2 . V_90 = V_12 -> V_90 ;
V_75 -> V_2 . V_91 = V_12 -> V_91 ;
V_75 -> V_2 . V_92 . V_93 = V_12 -> V_92 . V_93 ;
V_75 -> V_2 . V_15 = F_1 ;
V_75 -> V_2 . V_46 = F_15 ;
if ( V_12 -> V_47 )
V_75 -> V_2 . V_47 = F_16 ;
if ( V_12 -> V_21 && V_12 -> V_22 ) {
V_75 -> V_2 . V_21 = F_6 ;
V_75 -> V_2 . V_22 = F_7 ;
}
if ( V_12 -> V_24 )
V_75 -> V_2 . V_24 = F_8 ;
if ( V_12 -> V_37 )
V_75 -> V_2 . V_37 = F_9 ;
if ( V_12 -> V_48 )
V_75 -> V_2 . V_48 = F_17 ;
if ( V_12 -> V_38 )
V_75 -> V_2 . V_38 = F_11 ;
if ( V_12 -> V_41 )
V_75 -> V_2 . V_41 = F_13 ;
if ( V_12 -> V_49 )
V_75 -> V_2 . V_49 = F_18 ;
if ( V_12 -> V_50 )
V_75 -> V_2 . V_50 = F_19 ;
if ( V_12 -> V_40 )
V_75 -> V_2 . V_40 = F_12 ;
if ( V_12 -> V_42 )
V_75 -> V_2 . V_42 = F_14 ;
if ( V_12 -> V_67 )
V_75 -> V_2 . V_67 = F_26 ;
if ( ! V_81 && ! V_12 -> V_92 . V_94 && V_12 -> V_68 && V_12 -> V_69 ) {
V_75 -> V_2 . V_68 = F_27 ;
V_75 -> V_2 . V_69 = F_28 ;
}
if ( V_12 -> V_54 )
V_75 -> V_2 . V_54 = F_20 ;
if ( V_12 -> V_64 )
V_75 -> V_2 . V_64 = F_23 ;
if ( V_12 -> V_65 )
V_75 -> V_2 . V_65 = F_24 ;
if ( V_12 -> V_66 )
V_75 -> V_2 . V_66 = F_25 ;
if ( V_12 -> V_70 )
V_75 -> V_2 . V_70 = F_29 ;
if ( V_12 -> V_71 )
V_75 -> V_2 . V_71 = F_30 ;
V_75 -> V_2 . V_59 = F_21 ;
V_75 -> V_12 = V_12 ;
V_75 -> V_16 = V_8 -> V_16 ;
if ( V_75 -> V_16 == V_95 )
V_75 -> V_16 = V_82 ;
if ( V_75 -> V_16 == V_96 ) {
V_75 -> V_16 = V_82 ;
if ( F_44 ( V_82 , V_12 ) != 0 ) {
V_75 -> V_16 = ( F_45 ( V_82 , V_12 ) + 1 ) * V_12 -> V_97 ;
F_42 ( V_98 L_2
L_3 , V_81 ,
( unsigned long long ) V_82 , ( unsigned long long ) V_75 -> V_16 ) ;
}
}
if ( V_75 -> V_16 == V_99 ) {
V_75 -> V_16 = V_82 ;
if ( V_12 -> V_14 - V_75 -> V_16 >= V_75 -> V_2 . V_14 ) {
V_75 -> V_2 . V_14 = V_12 -> V_14 - V_75 -> V_16
- V_75 -> V_2 . V_14 ;
} else {
F_42 ( V_84 L_4 ,
V_8 -> V_74 , V_12 -> V_14 - V_75 -> V_16 ,
V_75 -> V_2 . V_14 ) ;
goto V_100;
}
}
if ( V_75 -> V_2 . V_14 == V_101 )
V_75 -> V_2 . V_14 = V_12 -> V_14 - V_75 -> V_16 ;
F_42 ( V_98 L_5 , ( unsigned long long ) V_75 -> V_16 ,
( unsigned long long ) ( V_75 -> V_16 + V_75 -> V_2 . V_14 ) , V_75 -> V_2 . V_74 ) ;
if ( V_75 -> V_16 >= V_12 -> V_14 ) {
V_75 -> V_16 = 0 ;
V_75 -> V_2 . V_14 = 0 ;
F_42 ( V_84 L_6 ,
V_8 -> V_74 ) ;
goto V_100;
}
if ( V_75 -> V_16 + V_75 -> V_2 . V_14 > V_12 -> V_14 ) {
V_75 -> V_2 . V_14 = V_12 -> V_14 - V_75 -> V_16 ;
F_42 ( V_102 L_7 ,
V_8 -> V_74 , V_12 -> V_74 , ( unsigned long long ) V_75 -> V_2 . V_14 ) ;
}
if ( V_12 -> V_103 > 1 ) {
int V_104 , V_105 = V_12 -> V_103 ;
T_6 V_106 = V_75 -> V_16 + V_75 -> V_2 . V_14 ;
struct V_107 * V_108 = V_12 -> V_109 ;
for ( V_104 = 0 ; V_104 < V_105 && V_108 [ V_104 ] . V_16 <= V_75 -> V_16 ; V_104 ++ )
;
if ( V_104 > 0 )
V_104 -- ;
for (; V_104 < V_105 && V_108 [ V_104 ] . V_16 < V_106 ; V_104 ++ ) {
if ( V_75 -> V_2 . V_97 < V_108 [ V_104 ] . V_97 ) {
V_75 -> V_2 . V_97 = V_108 [ V_104 ] . V_97 ;
}
}
F_46 ( V_75 -> V_2 . V_97 == 0 ) ;
} else {
V_75 -> V_2 . V_97 = V_12 -> V_97 ;
}
if ( ( V_75 -> V_2 . V_23 & V_44 ) &&
F_44 ( V_75 -> V_16 , & V_75 -> V_2 ) ) {
V_75 -> V_2 . V_23 &= ~ V_44 ;
F_42 ( V_102 L_8 ,
V_8 -> V_74 ) ;
}
if ( ( V_75 -> V_2 . V_23 & V_44 ) &&
F_44 ( V_75 -> V_2 . V_14 , & V_75 -> V_2 ) ) {
V_75 -> V_2 . V_23 &= ~ V_44 ;
F_42 ( V_102 L_9 ,
V_8 -> V_74 ) ;
}
V_75 -> V_2 . V_110 = V_12 -> V_110 ;
if ( V_12 -> V_70 ) {
T_5 V_111 = 0 ;
while ( V_111 < V_75 -> V_2 . V_14 ) {
if ( V_12 -> V_70 ( V_12 ,
V_111 + V_75 -> V_16 ) )
V_75 -> V_2 . V_13 . V_72 ++ ;
V_111 += V_75 -> V_2 . V_97 ;
}
}
V_100:
return V_75 ;
}
int F_47 ( struct V_1 * V_12 , char * V_74 ,
long long V_16 , long long V_112 )
{
struct V_80 V_8 ;
struct V_7 * V_73 , * V_113 ;
T_5 V_114 , V_106 ;
int V_57 = 0 ;
if ( V_16 == V_95 ||
V_16 == V_96 )
return - V_27 ;
if ( V_112 == V_101 )
V_112 = V_12 -> V_14 - V_16 ;
if ( V_112 <= 0 )
return - V_27 ;
V_8 . V_74 = V_74 ;
V_8 . V_14 = V_112 ;
V_8 . V_16 = V_16 ;
V_8 . V_86 = 0 ;
V_8 . V_110 = NULL ;
V_113 = F_39 ( V_12 , & V_8 , - 1 , V_16 ) ;
if ( F_48 ( V_113 ) )
return F_49 ( V_113 ) ;
V_114 = V_16 ;
V_106 = V_16 + V_112 ;
F_34 ( & V_78 ) ;
F_50 (p, &mtd_partitions, list)
if ( V_73 -> V_12 == V_12 ) {
if ( ( V_114 >= V_73 -> V_16 ) &&
( V_114 < ( V_73 -> V_16 + V_73 -> V_2 . V_14 ) ) )
goto V_115;
if ( ( V_106 >= V_73 -> V_16 ) &&
( V_106 < ( V_73 -> V_16 + V_73 -> V_2 . V_14 ) ) )
goto V_115;
}
F_51 ( & V_113 -> V_79 , & V_116 ) ;
F_38 ( & V_78 ) ;
F_52 ( & V_113 -> V_2 ) ;
return V_57 ;
V_115:
F_38 ( & V_78 ) ;
F_31 ( V_113 ) ;
return - V_27 ;
}
int F_53 ( struct V_1 * V_12 , int V_81 )
{
struct V_7 * V_75 , * V_76 ;
int V_57 = - V_27 ;
F_34 ( & V_78 ) ;
F_35 (slave, next, &mtd_partitions, list)
if ( ( V_75 -> V_12 == V_12 ) &&
( V_75 -> V_2 . V_117 == V_81 ) ) {
V_57 = F_36 ( & V_75 -> V_2 ) ;
if ( V_57 < 0 )
break;
F_37 ( & V_75 -> V_79 ) ;
F_31 ( V_75 ) ;
break;
}
F_38 ( & V_78 ) ;
return V_57 ;
}
int F_54 ( struct V_1 * V_12 ,
const struct V_80 * V_118 ,
int V_119 )
{
struct V_7 * V_75 ;
T_5 V_82 = 0 ;
int V_104 ;
F_42 ( V_98 L_10 , V_119 , V_12 -> V_74 ) ;
for ( V_104 = 0 ; V_104 < V_119 ; V_104 ++ ) {
V_75 = F_39 ( V_12 , V_118 + V_104 , V_104 , V_82 ) ;
if ( F_48 ( V_75 ) )
return F_49 ( V_75 ) ;
F_34 ( & V_78 ) ;
F_51 ( & V_75 -> V_79 , & V_116 ) ;
F_38 ( & V_78 ) ;
F_52 ( & V_75 -> V_2 ) ;
V_82 = V_75 -> V_16 + V_75 -> V_2 . V_14 ;
}
return 0 ;
}
static struct V_120 * F_55 ( const char * V_74 )
{
struct V_120 * V_73 , * V_57 = NULL ;
F_56 ( & V_121 ) ;
F_50 (p, &part_parsers, list)
if ( ! strcmp ( V_73 -> V_74 , V_74 ) && F_57 ( V_73 -> V_90 ) ) {
V_57 = V_73 ;
break;
}
F_58 ( & V_121 ) ;
return V_57 ;
}
int F_59 ( struct V_120 * V_73 )
{
F_56 ( & V_121 ) ;
F_51 ( & V_73 -> V_79 , & V_122 ) ;
F_58 ( & V_121 ) ;
return 0 ;
}
int F_60 ( struct V_120 * V_73 )
{
F_56 ( & V_121 ) ;
F_37 ( & V_73 -> V_79 ) ;
F_58 ( & V_121 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_12 , const char * * V_123 ,
struct V_80 * * V_124 ,
struct V_125 * V_126 )
{
struct V_120 * V_127 ;
int V_57 = 0 ;
if ( ! V_123 )
V_123 = V_128 ;
for ( ; V_57 <= 0 && * V_123 ; V_123 ++ ) {
V_127 = F_55 ( * V_123 ) ;
if ( ! V_127 && ! F_62 ( L_11 , * V_123 ) )
V_127 = F_55 ( * V_123 ) ;
if ( ! V_127 )
continue;
V_57 = (* V_127 -> V_129 )( V_12 , V_124 , V_126 ) ;
if ( V_57 > 0 ) {
F_42 ( V_98 L_12 ,
V_57 , V_127 -> V_74 , V_12 -> V_74 ) ;
}
F_63 ( V_127 ) ;
}
return V_57 ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_130 = 0 ;
F_34 ( & V_78 ) ;
F_50 (part, &mtd_partitions, list)
if ( & V_8 -> V_2 == V_2 ) {
V_130 = 1 ;
break;
}
F_38 ( & V_78 ) ;
return V_130 ;
}
