static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 ;
int V_11 ;
V_10 = V_8 -> V_12 -> V_13 ;
V_11 = V_8 -> V_12 -> V_14 ( V_8 -> V_12 , V_3 + V_8 -> V_15 , V_4 ,
V_5 , V_6 ) ;
if ( F_3 ( F_4 ( V_11 ) ) )
V_2 -> V_13 . V_16 +=
V_8 -> V_12 -> V_13 . V_16 - V_10 . V_16 ;
else
V_2 -> V_13 . V_17 +=
V_8 -> V_12 -> V_13 . V_17 - V_10 . V_17 ;
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 * V_5 , void * * V_18 , T_4 * V_19 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_20 ( V_8 -> V_12 , V_3 + V_8 -> V_15 , V_4 ,
V_5 , V_18 , V_19 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_21 ( V_8 -> V_12 , V_3 + V_8 -> V_15 , V_4 ) ;
}
static unsigned long F_7 ( struct V_1 * V_2 ,
unsigned long V_4 ,
unsigned long V_15 ,
unsigned long V_22 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_15 += V_8 -> V_15 ;
return V_8 -> V_12 -> V_23 ( V_8 -> V_12 , V_4 , V_15 ,
V_22 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_24 * V_25 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
if ( V_3 >= V_2 -> V_26 )
return - V_27 ;
if ( V_25 -> V_28 && V_3 + V_25 -> V_4 > V_2 -> V_26 )
return - V_27 ;
if ( V_25 -> V_29 ) {
T_2 V_4 , V_30 ;
if ( V_25 -> V_31 == V_32 )
V_4 = V_2 -> V_33 ;
else
V_4 = V_2 -> V_34 ;
V_30 = F_9 ( V_2 -> V_26 , V_2 ) ;
V_30 -= F_9 ( V_3 , V_2 ) ;
if ( V_25 -> V_35 + V_25 -> V_36 > V_30 * V_4 )
return - V_27 ;
}
V_11 = V_8 -> V_12 -> V_37 ( V_8 -> V_12 , V_3 + V_8 -> V_15 , V_25 ) ;
if ( F_3 ( V_11 ) ) {
if ( F_10 ( V_11 ) )
V_2 -> V_13 . V_17 ++ ;
if ( F_4 ( V_11 ) )
V_2 -> V_13 . V_16 ++ ;
}
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_38 ( V_8 -> V_12 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_4 ,
T_2 * V_5 , struct V_39 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_40 ( V_8 -> V_12 , V_4 , V_5 ,
V_6 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_41 ( V_8 -> V_12 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_4 ,
T_2 * V_5 , struct V_39 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_42 ( V_8 -> V_12 , V_4 , V_5 ,
V_6 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_43 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_44 ( V_8 -> V_12 , V_43 + V_8 -> V_15 , V_4 ,
V_5 , V_6 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_43 , T_2 V_4 ,
T_2 * V_5 , const T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_45 ( V_8 -> V_12 , V_43 + V_8 -> V_15 , V_4 ,
V_5 , V_6 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_43 ,
struct V_24 * V_25 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_43 >= V_2 -> V_26 )
return - V_27 ;
if ( V_25 -> V_28 && V_43 + V_25 -> V_4 > V_2 -> V_26 )
return - V_27 ;
return V_8 -> V_12 -> V_46 ( V_8 -> V_12 , V_43 + V_8 -> V_15 , V_25 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 * V_5 , T_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_47 ( V_8 -> V_12 , V_3 , V_4 ,
V_5 , V_6 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_48 ( V_8 -> V_12 , V_3 , V_4 ) ;
}
static int F_20 ( struct V_1 * V_2 , const struct V_49 * V_50 ,
unsigned long V_51 , T_1 V_43 , T_2 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_52 ( V_8 -> V_12 , V_50 , V_51 ,
V_43 + V_8 -> V_15 , V_5 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_55 ;
V_54 -> V_56 += V_8 -> V_15 ;
V_55 = V_8 -> V_12 -> V_57 ( V_8 -> V_12 , V_54 ) ;
if ( V_55 ) {
if ( V_54 -> V_58 != V_59 )
V_54 -> V_58 -= V_8 -> V_15 ;
V_54 -> V_56 -= V_8 -> V_15 ;
}
return V_55 ;
}
void F_22 ( struct V_53 * V_54 )
{
if ( V_54 -> V_2 -> V_57 == F_21 ) {
struct V_7 * V_8 = F_2 ( V_54 -> V_2 ) ;
if ( V_54 -> V_58 != V_59 )
V_54 -> V_58 -= V_8 -> V_15 ;
V_54 -> V_56 -= V_8 -> V_15 ;
}
if ( V_54 -> V_60 )
V_54 -> V_60 ( V_54 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_61 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_62 ( V_8 -> V_12 , V_61 + V_8 -> V_15 , V_4 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_61 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_63 ( V_8 -> V_12 , V_61 + V_8 -> V_15 , V_4 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_61 , T_5 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_64 ( V_8 -> V_12 , V_61 + V_8 -> V_15 , V_4 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_12 -> V_65 ( V_8 -> V_12 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_12 -> V_66 ( V_8 -> V_12 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_12 -> V_67 ( V_8 -> V_12 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_61 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_61 += V_8 -> V_15 ;
return V_8 -> V_12 -> V_68 ( V_8 -> V_12 , V_61 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_61 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
V_61 += V_8 -> V_15 ;
V_11 = V_8 -> V_12 -> V_69 ( V_8 -> V_12 , V_61 ) ;
if ( ! V_11 )
V_2 -> V_13 . V_70 ++ ;
return V_11 ;
}
static inline void F_31 ( struct V_7 * V_71 )
{
F_32 ( V_71 -> V_2 . V_72 ) ;
F_32 ( V_71 ) ;
}
int F_33 ( struct V_1 * V_12 )
{
struct V_7 * V_73 , * V_74 ;
int V_55 , V_75 = 0 ;
F_34 ( & V_76 ) ;
F_35 (slave, next, &mtd_partitions, list)
if ( V_73 -> V_12 == V_12 ) {
V_55 = F_36 ( & V_73 -> V_2 ) ;
if ( V_55 < 0 ) {
V_75 = V_55 ;
continue;
}
F_37 ( & V_73 -> V_77 ) ;
F_31 ( V_73 ) ;
}
F_38 ( & V_76 ) ;
return V_75 ;
}
static struct V_7 * F_39 ( struct V_1 * V_12 ,
const struct V_78 * V_8 , int V_79 ,
T_5 V_80 )
{
struct V_7 * V_73 ;
char * V_72 ;
V_73 = F_40 ( sizeof( * V_73 ) , V_81 ) ;
V_72 = F_41 ( V_8 -> V_72 , V_81 ) ;
if ( ! V_72 || ! V_73 ) {
F_42 ( V_82 L_1 ,
V_12 -> V_72 ) ;
F_32 ( V_72 ) ;
F_32 ( V_73 ) ;
return F_43 ( - V_83 ) ;
}
V_73 -> V_2 . type = V_12 -> type ;
V_73 -> V_2 . V_22 = V_12 -> V_22 & ~ V_8 -> V_84 ;
V_73 -> V_2 . V_26 = V_8 -> V_26 ;
V_73 -> V_2 . V_85 = V_12 -> V_85 ;
V_73 -> V_2 . V_86 = V_12 -> V_86 ;
V_73 -> V_2 . V_34 = V_12 -> V_34 ;
V_73 -> V_2 . V_33 = V_12 -> V_33 ;
V_73 -> V_2 . V_87 = V_12 -> V_87 ;
V_73 -> V_2 . V_72 = V_72 ;
V_73 -> V_2 . V_88 = V_12 -> V_88 ;
V_73 -> V_2 . V_89 = V_12 -> V_89 ;
V_73 -> V_2 . V_90 . V_91 = V_12 -> V_90 . V_91 ;
V_73 -> V_2 . V_14 = F_1 ;
V_73 -> V_2 . V_44 = F_15 ;
if ( V_12 -> V_45 )
V_73 -> V_2 . V_45 = F_16 ;
if ( V_12 -> V_20 && V_12 -> V_21 ) {
V_73 -> V_2 . V_20 = F_5 ;
V_73 -> V_2 . V_21 = F_6 ;
}
if ( V_12 -> V_23 )
V_73 -> V_2 . V_23 = F_7 ;
if ( V_12 -> V_37 )
V_73 -> V_2 . V_37 = F_8 ;
if ( V_12 -> V_46 )
V_73 -> V_2 . V_46 = F_17 ;
if ( V_12 -> V_38 )
V_73 -> V_2 . V_38 = F_11 ;
if ( V_12 -> V_41 )
V_73 -> V_2 . V_41 = F_13 ;
if ( V_12 -> V_47 )
V_73 -> V_2 . V_47 = F_18 ;
if ( V_12 -> V_48 )
V_73 -> V_2 . V_48 = F_19 ;
if ( V_12 -> V_40 )
V_73 -> V_2 . V_40 = F_12 ;
if ( V_12 -> V_42 )
V_73 -> V_2 . V_42 = F_14 ;
if ( V_12 -> V_65 )
V_73 -> V_2 . V_65 = F_26 ;
if ( ! V_79 && ! V_12 -> V_90 . V_92 && V_12 -> V_66 &&
V_12 -> V_67 ) {
V_73 -> V_2 . V_66 = F_27 ;
V_73 -> V_2 . V_67 = F_28 ;
}
if ( V_12 -> V_52 )
V_73 -> V_2 . V_52 = F_20 ;
if ( V_12 -> V_62 )
V_73 -> V_2 . V_62 = F_23 ;
if ( V_12 -> V_63 )
V_73 -> V_2 . V_63 = F_24 ;
if ( V_12 -> V_64 )
V_73 -> V_2 . V_64 = F_25 ;
if ( V_12 -> V_68 )
V_73 -> V_2 . V_68 = F_29 ;
if ( V_12 -> V_69 )
V_73 -> V_2 . V_69 = F_30 ;
V_73 -> V_2 . V_57 = F_21 ;
V_73 -> V_12 = V_12 ;
V_73 -> V_15 = V_8 -> V_15 ;
if ( V_73 -> V_15 == V_93 )
V_73 -> V_15 = V_80 ;
if ( V_73 -> V_15 == V_94 ) {
V_73 -> V_15 = V_80 ;
if ( F_44 ( V_80 , V_12 ) != 0 ) {
V_73 -> V_15 = ( F_45 ( V_80 , V_12 ) + 1 ) * V_12 -> V_95 ;
F_42 ( V_96 L_2
L_3 , V_79 ,
( unsigned long long ) V_80 , ( unsigned long long ) V_73 -> V_15 ) ;
}
}
if ( V_73 -> V_15 == V_97 ) {
V_73 -> V_15 = V_80 ;
if ( V_12 -> V_26 - V_73 -> V_15 >= V_73 -> V_2 . V_26 ) {
V_73 -> V_2 . V_26 = V_12 -> V_26 - V_73 -> V_15
- V_73 -> V_2 . V_26 ;
} else {
F_42 ( V_82 L_4 ,
V_8 -> V_72 , V_12 -> V_26 - V_73 -> V_15 ,
V_73 -> V_2 . V_26 ) ;
goto V_98;
}
}
if ( V_73 -> V_2 . V_26 == V_99 )
V_73 -> V_2 . V_26 = V_12 -> V_26 - V_73 -> V_15 ;
F_42 ( V_96 L_5 , ( unsigned long long ) V_73 -> V_15 ,
( unsigned long long ) ( V_73 -> V_15 + V_73 -> V_2 . V_26 ) , V_73 -> V_2 . V_72 ) ;
if ( V_73 -> V_15 >= V_12 -> V_26 ) {
V_73 -> V_15 = 0 ;
V_73 -> V_2 . V_26 = 0 ;
F_42 ( V_82 L_6 ,
V_8 -> V_72 ) ;
goto V_98;
}
if ( V_73 -> V_15 + V_73 -> V_2 . V_26 > V_12 -> V_26 ) {
V_73 -> V_2 . V_26 = V_12 -> V_26 - V_73 -> V_15 ;
F_42 ( V_100 L_7 ,
V_8 -> V_72 , V_12 -> V_72 , ( unsigned long long ) V_73 -> V_2 . V_26 ) ;
}
if ( V_12 -> V_101 > 1 ) {
int V_102 , V_103 = V_12 -> V_101 ;
T_6 V_104 = V_73 -> V_15 + V_73 -> V_2 . V_26 ;
struct V_105 * V_106 = V_12 -> V_107 ;
for ( V_102 = 0 ; V_102 < V_103 && V_106 [ V_102 ] . V_15 <= V_73 -> V_15 ; V_102 ++ )
;
if ( V_102 > 0 )
V_102 -- ;
for (; V_102 < V_103 && V_106 [ V_102 ] . V_15 < V_104 ; V_102 ++ ) {
if ( V_73 -> V_2 . V_95 < V_106 [ V_102 ] . V_95 ) {
V_73 -> V_2 . V_95 = V_106 [ V_102 ] . V_95 ;
}
}
F_46 ( V_73 -> V_2 . V_95 == 0 ) ;
} else {
V_73 -> V_2 . V_95 = V_12 -> V_95 ;
}
if ( ( V_73 -> V_2 . V_22 & V_108 ) &&
F_44 ( V_73 -> V_15 , & V_73 -> V_2 ) ) {
V_73 -> V_2 . V_22 &= ~ V_108 ;
F_42 ( V_100 L_8 ,
V_8 -> V_72 ) ;
}
if ( ( V_73 -> V_2 . V_22 & V_108 ) &&
F_44 ( V_73 -> V_2 . V_26 , & V_73 -> V_2 ) ) {
V_73 -> V_2 . V_22 &= ~ V_108 ;
F_42 ( V_100 L_9 ,
V_8 -> V_72 ) ;
}
V_73 -> V_2 . V_109 = V_12 -> V_109 ;
V_73 -> V_2 . V_110 = V_12 -> V_110 ;
V_73 -> V_2 . V_111 = V_12 -> V_111 ;
V_73 -> V_2 . V_112 = V_12 -> V_112 ;
if ( V_12 -> V_68 ) {
T_5 V_113 = 0 ;
while ( V_113 < V_73 -> V_2 . V_26 ) {
if ( F_47 ( V_12 , V_113 + V_73 -> V_15 ) )
V_73 -> V_2 . V_13 . V_70 ++ ;
V_113 += V_73 -> V_2 . V_95 ;
}
}
V_98:
return V_73 ;
}
int F_48 ( struct V_1 * V_12 , const char * V_72 ,
long long V_15 , long long V_114 )
{
struct V_78 V_8 ;
struct V_7 * V_71 , * V_115 ;
T_5 V_116 , V_104 ;
int V_55 = 0 ;
if ( V_15 == V_93 ||
V_15 == V_94 )
return - V_27 ;
if ( V_114 == V_99 )
V_114 = V_12 -> V_26 - V_15 ;
if ( V_114 <= 0 )
return - V_27 ;
V_8 . V_72 = V_72 ;
V_8 . V_26 = V_114 ;
V_8 . V_15 = V_15 ;
V_8 . V_84 = 0 ;
V_8 . V_109 = NULL ;
V_115 = F_39 ( V_12 , & V_8 , - 1 , V_15 ) ;
if ( F_49 ( V_115 ) )
return F_50 ( V_115 ) ;
V_116 = V_15 ;
V_104 = V_15 + V_114 ;
F_34 ( & V_76 ) ;
F_51 (p, &mtd_partitions, list)
if ( V_71 -> V_12 == V_12 ) {
if ( ( V_116 >= V_71 -> V_15 ) &&
( V_116 < ( V_71 -> V_15 + V_71 -> V_2 . V_26 ) ) )
goto V_117;
if ( ( V_104 >= V_71 -> V_15 ) &&
( V_104 < ( V_71 -> V_15 + V_71 -> V_2 . V_26 ) ) )
goto V_117;
}
F_52 ( & V_115 -> V_77 , & V_118 ) ;
F_38 ( & V_76 ) ;
F_53 ( & V_115 -> V_2 ) ;
return V_55 ;
V_117:
F_38 ( & V_76 ) ;
F_31 ( V_115 ) ;
return - V_27 ;
}
int F_54 ( struct V_1 * V_12 , int V_79 )
{
struct V_7 * V_73 , * V_74 ;
int V_55 = - V_27 ;
F_34 ( & V_76 ) ;
F_35 (slave, next, &mtd_partitions, list)
if ( ( V_73 -> V_12 == V_12 ) &&
( V_73 -> V_2 . V_119 == V_79 ) ) {
V_55 = F_36 ( & V_73 -> V_2 ) ;
if ( V_55 < 0 )
break;
F_37 ( & V_73 -> V_77 ) ;
F_31 ( V_73 ) ;
break;
}
F_38 ( & V_76 ) ;
return V_55 ;
}
int F_55 ( struct V_1 * V_12 ,
const struct V_78 * V_120 ,
int V_121 )
{
struct V_7 * V_73 ;
T_5 V_80 = 0 ;
int V_102 ;
F_42 ( V_96 L_10 , V_121 , V_12 -> V_72 ) ;
for ( V_102 = 0 ; V_102 < V_121 ; V_102 ++ ) {
V_73 = F_39 ( V_12 , V_120 + V_102 , V_102 , V_80 ) ;
if ( F_49 ( V_73 ) )
return F_50 ( V_73 ) ;
F_34 ( & V_76 ) ;
F_52 ( & V_73 -> V_77 , & V_118 ) ;
F_38 ( & V_76 ) ;
F_53 ( & V_73 -> V_2 ) ;
V_80 = V_73 -> V_15 + V_73 -> V_2 . V_26 ;
}
return 0 ;
}
static struct V_122 * F_56 ( const char * V_72 )
{
struct V_122 * V_71 , * V_55 = NULL ;
F_57 ( & V_123 ) ;
F_51 (p, &part_parsers, list)
if ( ! strcmp ( V_71 -> V_72 , V_72 ) && F_58 ( V_71 -> V_88 ) ) {
V_55 = V_71 ;
break;
}
F_59 ( & V_123 ) ;
return V_55 ;
}
void F_60 ( struct V_122 * V_71 )
{
F_57 ( & V_123 ) ;
F_52 ( & V_71 -> V_77 , & V_124 ) ;
F_59 ( & V_123 ) ;
}
void F_61 ( struct V_122 * V_71 )
{
F_57 ( & V_123 ) ;
F_37 ( & V_71 -> V_77 ) ;
F_59 ( & V_123 ) ;
}
int F_62 ( struct V_1 * V_12 , const char * const * V_125 ,
struct V_78 * * V_126 ,
struct V_127 * V_128 )
{
struct V_122 * V_129 ;
int V_55 = 0 ;
if ( ! V_125 )
V_125 = V_130 ;
for ( ; V_55 <= 0 && * V_125 ; V_125 ++ ) {
V_129 = F_56 ( * V_125 ) ;
if ( ! V_129 && ! F_63 ( L_11 , * V_125 ) )
V_129 = F_56 ( * V_125 ) ;
if ( ! V_129 )
continue;
V_55 = (* V_129 -> V_131 )( V_12 , V_126 , V_128 ) ;
F_64 ( V_129 ) ;
if ( V_55 > 0 ) {
F_42 ( V_96 L_12 ,
V_55 , V_129 -> V_72 , V_12 -> V_72 ) ;
break;
}
}
return V_55 ;
}
int F_65 ( const struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_132 = 0 ;
F_34 ( & V_76 ) ;
F_51 (part, &mtd_partitions, list)
if ( & V_8 -> V_2 == V_2 ) {
V_132 = 1 ;
break;
}
F_38 ( & V_76 ) ;
return V_132 ;
}
T_5 F_66 ( const struct V_1 * V_2 )
{
if ( ! F_65 ( V_2 ) )
return V_2 -> V_26 ;
return F_2 ( V_2 ) -> V_12 -> V_26 ;
}
