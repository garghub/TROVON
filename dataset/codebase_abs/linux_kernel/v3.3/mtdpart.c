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
V_11 = F_3 ( V_8 -> V_12 , V_3 + V_8 -> V_15 , V_4 , V_5 , V_6 ) ;
if ( F_4 ( V_11 ) ) {
if ( F_5 ( V_11 ) )
V_2 -> V_13 . V_16 += V_8 -> V_12 -> V_13 . V_16 - V_10 . V_16 ;
if ( F_6 ( V_11 ) )
V_2 -> V_13 . V_17 += V_8 -> V_12 -> V_13 . V_17 - V_10 . V_17 ;
}
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_5 , void * * V_18 , T_4 * V_19 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_3 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_3 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_3 ;
return F_8 ( V_8 -> V_12 , V_3 + V_8 -> V_15 , V_4 , V_5 ,
V_18 , V_19 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_10 ( V_8 -> V_12 , V_3 + V_8 -> V_15 , V_4 ) ;
}
static unsigned long F_11 ( struct V_1 * V_2 ,
unsigned long V_4 ,
unsigned long V_15 ,
unsigned long V_20 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_15 += V_8 -> V_15 ;
return F_12 ( V_8 -> V_12 , V_4 , V_15 , V_20 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_21 * V_22 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
if ( V_3 >= V_2 -> V_14 )
return - V_23 ;
if ( V_22 -> V_24 && V_3 + V_22 -> V_4 > V_2 -> V_14 )
return - V_23 ;
if ( V_22 -> V_25 ) {
T_2 V_4 , V_26 ;
if ( V_22 -> V_27 == V_28 )
V_4 = V_2 -> V_29 ;
else
V_4 = V_2 -> V_30 ;
V_26 = F_14 ( V_2 -> V_14 , V_2 ) ;
V_26 -= F_14 ( V_3 , V_2 ) ;
if ( V_22 -> V_31 + V_22 -> V_32 > V_26 * V_4 )
return - V_23 ;
}
V_11 = F_15 ( V_8 -> V_12 , V_3 + V_8 -> V_15 , V_22 ) ;
if ( F_4 ( V_11 ) ) {
if ( F_5 ( V_11 ) )
V_2 -> V_13 . V_16 ++ ;
if ( F_6 ( V_11 ) )
V_2 -> V_13 . V_17 ++ ;
}
return V_11 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_17 ( V_8 -> V_12 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_33 * V_6 , T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_19 ( V_8 -> V_12 , V_6 , V_4 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_21 ( V_8 -> V_12 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_33 * V_6 ,
T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_23 ( V_8 -> V_12 , V_6 , V_4 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_34 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_20 & V_35 ) )
return - V_36 ;
if ( V_34 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_34 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_34 ;
return F_25 ( V_8 -> V_12 , V_34 + V_8 -> V_15 , V_4 , V_5 , V_6 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_34 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_20 & V_35 ) )
return - V_36 ;
if ( V_34 >= V_2 -> V_14 )
V_4 = 0 ;
else if ( V_34 + V_4 > V_2 -> V_14 )
V_4 = V_2 -> V_14 - V_34 ;
return F_27 ( V_8 -> V_12 , V_34 + V_8 -> V_15 , V_4 , V_5 ,
V_6 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_34 ,
struct V_21 * V_22 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_20 & V_35 ) )
return - V_36 ;
if ( V_34 >= V_2 -> V_14 )
return - V_23 ;
if ( V_22 -> V_24 && V_34 + V_22 -> V_4 > V_2 -> V_14 )
return - V_23 ;
return F_29 ( V_8 -> V_12 , V_34 + V_8 -> V_15 , V_22 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_31 ( V_8 -> V_12 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_33 ( V_8 -> V_12 , V_3 , V_4 ) ;
}
static int F_34 ( struct V_1 * V_2 , const struct V_37 * V_38 ,
unsigned long V_39 , T_1 V_34 , T_2 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_20 & V_35 ) )
return - V_36 ;
return F_35 ( V_8 -> V_12 , V_38 , V_39 , V_34 + V_8 -> V_15 ,
V_5 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_42 ;
if ( ! ( V_2 -> V_20 & V_35 ) )
return - V_36 ;
if ( V_41 -> V_43 >= V_2 -> V_14 )
return - V_23 ;
V_41 -> V_43 += V_8 -> V_15 ;
V_42 = F_37 ( V_8 -> V_12 , V_41 ) ;
if ( V_42 ) {
if ( V_41 -> V_44 != V_45 )
V_41 -> V_44 -= V_8 -> V_15 ;
V_41 -> V_43 -= V_8 -> V_15 ;
}
return V_42 ;
}
void F_38 ( struct V_40 * V_41 )
{
if ( V_41 -> V_2 -> V_46 == F_36 ) {
struct V_7 * V_8 = F_2 ( V_41 -> V_2 ) ;
if ( V_41 -> V_44 != V_45 )
V_41 -> V_44 -= V_8 -> V_15 ;
V_41 -> V_43 -= V_8 -> V_15 ;
}
if ( V_41 -> V_47 )
V_41 -> V_47 ( V_41 ) ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_48 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_4 + V_48 ) > V_2 -> V_14 )
return - V_23 ;
return F_40 ( V_8 -> V_12 , V_48 + V_8 -> V_15 , V_4 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_48 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_4 + V_48 ) > V_2 -> V_14 )
return - V_23 ;
return F_42 ( V_8 -> V_12 , V_48 + V_8 -> V_15 , V_4 ) ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_48 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ( V_4 + V_48 ) > V_2 -> V_14 )
return - V_23 ;
return F_44 ( V_8 -> V_12 , V_48 + V_8 -> V_15 , V_4 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_46 ( V_8 -> V_12 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_48 ( V_8 -> V_12 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_50 ( V_8 -> V_12 ) ;
}
static int F_51 ( struct V_1 * V_2 , T_1 V_48 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_48 >= V_2 -> V_14 )
return - V_23 ;
V_48 += V_8 -> V_15 ;
return F_52 ( V_8 -> V_12 , V_48 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_48 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
if ( ! ( V_2 -> V_20 & V_35 ) )
return - V_36 ;
if ( V_48 >= V_2 -> V_14 )
return - V_23 ;
V_48 += V_8 -> V_15 ;
V_11 = F_54 ( V_8 -> V_12 , V_48 ) ;
if ( ! V_11 )
V_2 -> V_13 . V_49 ++ ;
return V_11 ;
}
static inline void F_55 ( struct V_7 * V_50 )
{
F_56 ( V_50 -> V_2 . V_51 ) ;
F_56 ( V_50 ) ;
}
int F_57 ( struct V_1 * V_12 )
{
struct V_7 * V_52 , * V_53 ;
int V_42 , V_54 = 0 ;
F_58 ( & V_55 ) ;
F_59 (slave, next, &mtd_partitions, list)
if ( V_52 -> V_12 == V_12 ) {
V_42 = F_60 ( & V_52 -> V_2 ) ;
if ( V_42 < 0 ) {
V_54 = V_42 ;
continue;
}
F_61 ( & V_52 -> V_56 ) ;
F_55 ( V_52 ) ;
}
F_62 ( & V_55 ) ;
return V_54 ;
}
static struct V_7 * F_63 ( struct V_1 * V_12 ,
const struct V_57 * V_8 , int V_58 ,
T_5 V_59 )
{
struct V_7 * V_52 ;
char * V_51 ;
V_52 = F_64 ( sizeof( * V_52 ) , V_60 ) ;
V_51 = F_65 ( V_8 -> V_51 , V_60 ) ;
if ( ! V_51 || ! V_52 ) {
F_66 ( V_61 L_1 ,
V_12 -> V_51 ) ;
F_56 ( V_51 ) ;
F_56 ( V_52 ) ;
return F_67 ( - V_62 ) ;
}
V_52 -> V_2 . type = V_12 -> type ;
V_52 -> V_2 . V_20 = V_12 -> V_20 & ~ V_8 -> V_63 ;
V_52 -> V_2 . V_14 = V_8 -> V_14 ;
V_52 -> V_2 . V_64 = V_12 -> V_64 ;
V_52 -> V_2 . V_65 = V_12 -> V_65 ;
V_52 -> V_2 . V_30 = V_12 -> V_30 ;
V_52 -> V_2 . V_29 = V_12 -> V_29 ;
V_52 -> V_2 . V_66 = V_12 -> V_66 ;
V_52 -> V_2 . V_51 = V_51 ;
V_52 -> V_2 . V_67 = V_12 -> V_67 ;
V_52 -> V_2 . V_68 = V_12 -> V_68 ;
V_52 -> V_2 . V_69 . V_70 = V_12 -> V_69 . V_70 ;
V_52 -> V_2 . V_71 = F_1 ;
V_52 -> V_2 . V_72 = F_24 ;
if ( V_12 -> V_73 )
V_52 -> V_2 . V_73 = F_26 ;
if ( V_12 -> V_74 && V_12 -> V_75 ) {
V_52 -> V_2 . V_74 = F_7 ;
V_52 -> V_2 . V_75 = F_9 ;
}
if ( V_12 -> V_76 )
V_52 -> V_2 . V_76 = F_11 ;
if ( V_12 -> V_77 )
V_52 -> V_2 . V_77 = F_13 ;
if ( V_12 -> V_78 )
V_52 -> V_2 . V_78 = F_28 ;
if ( V_12 -> V_79 )
V_52 -> V_2 . V_79 = F_16 ;
if ( V_12 -> V_80 )
V_52 -> V_2 . V_80 = F_20 ;
if ( V_12 -> V_81 )
V_52 -> V_2 . V_81 = F_30 ;
if ( V_12 -> V_82 )
V_52 -> V_2 . V_82 = F_32 ;
if ( V_12 -> V_83 )
V_52 -> V_2 . V_83 = F_18 ;
if ( V_12 -> V_84 )
V_52 -> V_2 . V_84 = F_22 ;
if ( V_12 -> V_85 )
V_52 -> V_2 . V_85 = F_45 ;
if ( ! V_58 && ! V_12 -> V_69 . V_86 && V_12 -> V_87 && V_12 -> V_88 ) {
V_52 -> V_2 . V_87 = F_47 ;
V_52 -> V_2 . V_88 = F_49 ;
}
if ( V_12 -> V_89 )
V_52 -> V_2 . V_89 = F_34 ;
if ( V_12 -> V_90 )
V_52 -> V_2 . V_90 = F_39 ;
if ( V_12 -> V_91 )
V_52 -> V_2 . V_91 = F_41 ;
if ( V_12 -> V_92 )
V_52 -> V_2 . V_92 = F_43 ;
if ( V_12 -> V_93 )
V_52 -> V_2 . V_93 = F_51 ;
if ( V_12 -> V_94 )
V_52 -> V_2 . V_94 = F_53 ;
V_52 -> V_2 . V_46 = F_36 ;
V_52 -> V_12 = V_12 ;
V_52 -> V_15 = V_8 -> V_15 ;
if ( V_52 -> V_15 == V_95 )
V_52 -> V_15 = V_59 ;
if ( V_52 -> V_15 == V_96 ) {
V_52 -> V_15 = V_59 ;
if ( F_68 ( V_59 , V_12 ) != 0 ) {
V_52 -> V_15 = ( F_69 ( V_59 , V_12 ) + 1 ) * V_12 -> V_97 ;
F_66 ( V_98 L_2
L_3 , V_58 ,
( unsigned long long ) V_59 , ( unsigned long long ) V_52 -> V_15 ) ;
}
}
if ( V_52 -> V_15 == V_99 ) {
V_52 -> V_15 = V_59 ;
if ( V_12 -> V_14 - V_52 -> V_15 >= V_52 -> V_2 . V_14 ) {
V_52 -> V_2 . V_14 = V_12 -> V_14 - V_52 -> V_15
- V_52 -> V_2 . V_14 ;
} else {
F_66 ( V_61 L_4 ,
V_8 -> V_51 , V_12 -> V_14 - V_52 -> V_15 ,
V_52 -> V_2 . V_14 ) ;
goto V_100;
}
}
if ( V_52 -> V_2 . V_14 == V_101 )
V_52 -> V_2 . V_14 = V_12 -> V_14 - V_52 -> V_15 ;
F_66 ( V_98 L_5 , ( unsigned long long ) V_52 -> V_15 ,
( unsigned long long ) ( V_52 -> V_15 + V_52 -> V_2 . V_14 ) , V_52 -> V_2 . V_51 ) ;
if ( V_52 -> V_15 >= V_12 -> V_14 ) {
V_52 -> V_15 = 0 ;
V_52 -> V_2 . V_14 = 0 ;
F_66 ( V_61 L_6 ,
V_8 -> V_51 ) ;
goto V_100;
}
if ( V_52 -> V_15 + V_52 -> V_2 . V_14 > V_12 -> V_14 ) {
V_52 -> V_2 . V_14 = V_12 -> V_14 - V_52 -> V_15 ;
F_66 ( V_102 L_7 ,
V_8 -> V_51 , V_12 -> V_51 , ( unsigned long long ) V_52 -> V_2 . V_14 ) ;
}
if ( V_12 -> V_103 > 1 ) {
int V_104 , V_105 = V_12 -> V_103 ;
T_6 V_106 = V_52 -> V_15 + V_52 -> V_2 . V_14 ;
struct V_107 * V_108 = V_12 -> V_109 ;
for ( V_104 = 0 ; V_104 < V_105 && V_108 [ V_104 ] . V_15 <= V_52 -> V_15 ; V_104 ++ )
;
if ( V_104 > 0 )
V_104 -- ;
for (; V_104 < V_105 && V_108 [ V_104 ] . V_15 < V_106 ; V_104 ++ ) {
if ( V_52 -> V_2 . V_97 < V_108 [ V_104 ] . V_97 ) {
V_52 -> V_2 . V_97 = V_108 [ V_104 ] . V_97 ;
}
}
F_70 ( V_52 -> V_2 . V_97 == 0 ) ;
} else {
V_52 -> V_2 . V_97 = V_12 -> V_97 ;
}
if ( ( V_52 -> V_2 . V_20 & V_35 ) &&
F_68 ( V_52 -> V_15 , & V_52 -> V_2 ) ) {
V_52 -> V_2 . V_20 &= ~ V_35 ;
F_66 ( V_102 L_8 ,
V_8 -> V_51 ) ;
}
if ( ( V_52 -> V_2 . V_20 & V_35 ) &&
F_68 ( V_52 -> V_2 . V_14 , & V_52 -> V_2 ) ) {
V_52 -> V_2 . V_20 &= ~ V_35 ;
F_66 ( V_102 L_9 ,
V_8 -> V_51 ) ;
}
V_52 -> V_2 . V_110 = V_12 -> V_110 ;
if ( V_12 -> V_93 ) {
T_5 V_111 = 0 ;
while ( V_111 < V_52 -> V_2 . V_14 ) {
if ( F_52 ( V_12 , V_111 + V_52 -> V_15 ) )
V_52 -> V_2 . V_13 . V_49 ++ ;
V_111 += V_52 -> V_2 . V_97 ;
}
}
V_100:
return V_52 ;
}
int F_71 ( struct V_1 * V_12 , char * V_51 ,
long long V_15 , long long V_112 )
{
struct V_57 V_8 ;
struct V_7 * V_50 , * V_113 ;
T_5 V_114 , V_106 ;
int V_42 = 0 ;
if ( V_15 == V_95 ||
V_15 == V_96 )
return - V_23 ;
if ( V_112 == V_101 )
V_112 = V_12 -> V_14 - V_15 ;
if ( V_112 <= 0 )
return - V_23 ;
V_8 . V_51 = V_51 ;
V_8 . V_14 = V_112 ;
V_8 . V_15 = V_15 ;
V_8 . V_63 = 0 ;
V_8 . V_110 = NULL ;
V_113 = F_63 ( V_12 , & V_8 , - 1 , V_15 ) ;
if ( F_72 ( V_113 ) )
return F_73 ( V_113 ) ;
V_114 = V_15 ;
V_106 = V_15 + V_112 ;
F_58 ( & V_55 ) ;
F_74 (p, &mtd_partitions, list)
if ( V_50 -> V_12 == V_12 ) {
if ( ( V_114 >= V_50 -> V_15 ) &&
( V_114 < ( V_50 -> V_15 + V_50 -> V_2 . V_14 ) ) )
goto V_115;
if ( ( V_106 >= V_50 -> V_15 ) &&
( V_106 < ( V_50 -> V_15 + V_50 -> V_2 . V_14 ) ) )
goto V_115;
}
F_75 ( & V_113 -> V_56 , & V_116 ) ;
F_62 ( & V_55 ) ;
F_76 ( & V_113 -> V_2 ) ;
return V_42 ;
V_115:
F_62 ( & V_55 ) ;
F_55 ( V_113 ) ;
return - V_23 ;
}
int F_77 ( struct V_1 * V_12 , int V_58 )
{
struct V_7 * V_52 , * V_53 ;
int V_42 = - V_23 ;
F_58 ( & V_55 ) ;
F_59 (slave, next, &mtd_partitions, list)
if ( ( V_52 -> V_12 == V_12 ) &&
( V_52 -> V_2 . V_117 == V_58 ) ) {
V_42 = F_60 ( & V_52 -> V_2 ) ;
if ( V_42 < 0 )
break;
F_61 ( & V_52 -> V_56 ) ;
F_55 ( V_52 ) ;
break;
}
F_62 ( & V_55 ) ;
return V_42 ;
}
int F_78 ( struct V_1 * V_12 ,
const struct V_57 * V_118 ,
int V_119 )
{
struct V_7 * V_52 ;
T_5 V_59 = 0 ;
int V_104 ;
F_66 ( V_98 L_10 , V_119 , V_12 -> V_51 ) ;
for ( V_104 = 0 ; V_104 < V_119 ; V_104 ++ ) {
V_52 = F_63 ( V_12 , V_118 + V_104 , V_104 , V_59 ) ;
if ( F_72 ( V_52 ) )
return F_73 ( V_52 ) ;
F_58 ( & V_55 ) ;
F_75 ( & V_52 -> V_56 , & V_116 ) ;
F_62 ( & V_55 ) ;
F_76 ( & V_52 -> V_2 ) ;
V_59 = V_52 -> V_15 + V_52 -> V_2 . V_14 ;
}
return 0 ;
}
static struct V_120 * F_79 ( const char * V_51 )
{
struct V_120 * V_50 , * V_42 = NULL ;
F_80 ( & V_121 ) ;
F_74 (p, &part_parsers, list)
if ( ! strcmp ( V_50 -> V_51 , V_51 ) && F_81 ( V_50 -> V_67 ) ) {
V_42 = V_50 ;
break;
}
F_82 ( & V_121 ) ;
return V_42 ;
}
int F_83 ( struct V_120 * V_50 )
{
F_80 ( & V_121 ) ;
F_75 ( & V_50 -> V_56 , & V_122 ) ;
F_82 ( & V_121 ) ;
return 0 ;
}
int F_84 ( struct V_120 * V_50 )
{
F_80 ( & V_121 ) ;
F_61 ( & V_50 -> V_56 ) ;
F_82 ( & V_121 ) ;
return 0 ;
}
int F_85 ( struct V_1 * V_12 , const char * * V_123 ,
struct V_57 * * V_124 ,
struct V_125 * V_126 )
{
struct V_120 * V_127 ;
int V_42 = 0 ;
if ( ! V_123 )
V_123 = V_128 ;
for ( ; V_42 <= 0 && * V_123 ; V_123 ++ ) {
V_127 = F_79 ( * V_123 ) ;
if ( ! V_127 && ! F_86 ( L_11 , * V_123 ) )
V_127 = F_79 ( * V_123 ) ;
if ( ! V_127 )
continue;
V_42 = (* V_127 -> V_129 )( V_12 , V_124 , V_126 ) ;
if ( V_42 > 0 ) {
F_66 ( V_98 L_12 ,
V_42 , V_127 -> V_51 , V_12 -> V_51 ) ;
}
F_87 ( V_127 ) ;
}
return V_42 ;
}
int F_88 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_130 = 0 ;
F_58 ( & V_55 ) ;
F_74 (part, &mtd_partitions, list)
if ( & V_8 -> V_2 == V_2 ) {
V_130 = 1 ;
break;
}
F_62 ( & V_55 ) ;
return V_130 ;
}
