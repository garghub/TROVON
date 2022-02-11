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
V_61 += V_8 -> V_15 ;
return V_8 -> V_12 -> V_69 ( V_8 -> V_12 , V_61 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_61 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
V_61 += V_8 -> V_15 ;
V_11 = V_8 -> V_12 -> V_70 ( V_8 -> V_12 , V_61 ) ;
if ( ! V_11 )
V_2 -> V_13 . V_71 ++ ;
return V_11 ;
}
static inline void F_32 ( struct V_7 * V_72 )
{
F_33 ( V_72 -> V_2 . V_73 ) ;
F_33 ( V_72 ) ;
}
int F_34 ( struct V_1 * V_12 )
{
struct V_7 * V_74 , * V_75 ;
int V_55 , V_76 = 0 ;
F_35 ( & V_77 ) ;
F_36 (slave, next, &mtd_partitions, list)
if ( V_74 -> V_12 == V_12 ) {
V_55 = F_37 ( & V_74 -> V_2 ) ;
if ( V_55 < 0 ) {
V_76 = V_55 ;
continue;
}
F_38 ( & V_74 -> V_78 ) ;
F_32 ( V_74 ) ;
}
F_39 ( & V_77 ) ;
return V_76 ;
}
static struct V_7 * F_40 ( struct V_1 * V_12 ,
const struct V_79 * V_8 , int V_80 ,
T_5 V_81 )
{
struct V_7 * V_74 ;
char * V_73 ;
V_74 = F_41 ( sizeof( * V_74 ) , V_82 ) ;
V_73 = F_42 ( V_8 -> V_73 , V_82 ) ;
if ( ! V_73 || ! V_74 ) {
F_43 ( V_83 L_1 ,
V_12 -> V_73 ) ;
F_33 ( V_73 ) ;
F_33 ( V_74 ) ;
return F_44 ( - V_84 ) ;
}
V_74 -> V_2 . type = V_12 -> type ;
V_74 -> V_2 . V_22 = V_12 -> V_22 & ~ V_8 -> V_85 ;
V_74 -> V_2 . V_26 = V_8 -> V_26 ;
V_74 -> V_2 . V_86 = V_12 -> V_86 ;
V_74 -> V_2 . V_87 = V_12 -> V_87 ;
V_74 -> V_2 . V_34 = V_12 -> V_34 ;
V_74 -> V_2 . V_33 = V_12 -> V_33 ;
V_74 -> V_2 . V_88 = V_12 -> V_88 ;
V_74 -> V_2 . V_73 = V_73 ;
V_74 -> V_2 . V_89 = V_12 -> V_89 ;
V_74 -> V_2 . V_90 . V_91 = F_45 ( V_92 ) ?
& V_12 -> V_90 :
V_12 -> V_90 . V_91 ;
V_74 -> V_2 . V_14 = F_1 ;
V_74 -> V_2 . V_44 = F_15 ;
if ( V_12 -> V_45 )
V_74 -> V_2 . V_45 = F_16 ;
if ( V_12 -> V_20 && V_12 -> V_21 ) {
V_74 -> V_2 . V_20 = F_5 ;
V_74 -> V_2 . V_21 = F_6 ;
}
if ( V_12 -> V_23 )
V_74 -> V_2 . V_23 = F_7 ;
if ( V_12 -> V_37 )
V_74 -> V_2 . V_37 = F_8 ;
if ( V_12 -> V_46 )
V_74 -> V_2 . V_46 = F_17 ;
if ( V_12 -> V_38 )
V_74 -> V_2 . V_38 = F_11 ;
if ( V_12 -> V_41 )
V_74 -> V_2 . V_41 = F_13 ;
if ( V_12 -> V_47 )
V_74 -> V_2 . V_47 = F_18 ;
if ( V_12 -> V_48 )
V_74 -> V_2 . V_48 = F_19 ;
if ( V_12 -> V_40 )
V_74 -> V_2 . V_40 = F_12 ;
if ( V_12 -> V_42 )
V_74 -> V_2 . V_42 = F_14 ;
if ( V_12 -> V_65 )
V_74 -> V_2 . V_65 = F_26 ;
if ( ! V_80 && ! V_12 -> V_90 . V_93 && V_12 -> V_66 &&
V_12 -> V_67 ) {
V_74 -> V_2 . V_66 = F_27 ;
V_74 -> V_2 . V_67 = F_28 ;
}
if ( V_12 -> V_52 )
V_74 -> V_2 . V_52 = F_20 ;
if ( V_12 -> V_62 )
V_74 -> V_2 . V_62 = F_23 ;
if ( V_12 -> V_63 )
V_74 -> V_2 . V_63 = F_24 ;
if ( V_12 -> V_64 )
V_74 -> V_2 . V_64 = F_25 ;
if ( V_12 -> V_68 )
V_74 -> V_2 . V_68 = F_29 ;
if ( V_12 -> V_69 )
V_74 -> V_2 . V_69 = F_30 ;
if ( V_12 -> V_70 )
V_74 -> V_2 . V_70 = F_31 ;
V_74 -> V_2 . V_57 = F_21 ;
V_74 -> V_12 = V_12 ;
V_74 -> V_15 = V_8 -> V_15 ;
if ( V_74 -> V_15 == V_94 )
V_74 -> V_15 = V_81 ;
if ( V_74 -> V_15 == V_95 ) {
V_74 -> V_15 = V_81 ;
if ( F_46 ( V_81 , V_12 ) != 0 ) {
V_74 -> V_15 = ( F_47 ( V_81 , V_12 ) + 1 ) * V_12 -> V_96 ;
F_43 ( V_97 L_2
L_3 , V_80 ,
( unsigned long long ) V_81 , ( unsigned long long ) V_74 -> V_15 ) ;
}
}
if ( V_74 -> V_15 == V_98 ) {
V_74 -> V_15 = V_81 ;
if ( V_12 -> V_26 - V_74 -> V_15 >= V_74 -> V_2 . V_26 ) {
V_74 -> V_2 . V_26 = V_12 -> V_26 - V_74 -> V_15
- V_74 -> V_2 . V_26 ;
} else {
F_43 ( V_83 L_4 ,
V_8 -> V_73 , V_12 -> V_26 - V_74 -> V_15 ,
V_74 -> V_2 . V_26 ) ;
goto V_99;
}
}
if ( V_74 -> V_2 . V_26 == V_100 )
V_74 -> V_2 . V_26 = V_12 -> V_26 - V_74 -> V_15 ;
F_43 ( V_97 L_5 , ( unsigned long long ) V_74 -> V_15 ,
( unsigned long long ) ( V_74 -> V_15 + V_74 -> V_2 . V_26 ) , V_74 -> V_2 . V_73 ) ;
if ( V_74 -> V_15 >= V_12 -> V_26 ) {
V_74 -> V_15 = 0 ;
V_74 -> V_2 . V_26 = 0 ;
F_43 ( V_83 L_6 ,
V_8 -> V_73 ) ;
goto V_99;
}
if ( V_74 -> V_15 + V_74 -> V_2 . V_26 > V_12 -> V_26 ) {
V_74 -> V_2 . V_26 = V_12 -> V_26 - V_74 -> V_15 ;
F_43 ( V_101 L_7 ,
V_8 -> V_73 , V_12 -> V_73 , ( unsigned long long ) V_74 -> V_2 . V_26 ) ;
}
if ( V_12 -> V_102 > 1 ) {
int V_103 , V_104 = V_12 -> V_102 ;
T_6 V_105 = V_74 -> V_15 + V_74 -> V_2 . V_26 ;
struct V_106 * V_107 = V_12 -> V_108 ;
for ( V_103 = 0 ; V_103 < V_104 && V_107 [ V_103 ] . V_15 <= V_74 -> V_15 ; V_103 ++ )
;
if ( V_103 > 0 )
V_103 -- ;
for (; V_103 < V_104 && V_107 [ V_103 ] . V_15 < V_105 ; V_103 ++ ) {
if ( V_74 -> V_2 . V_96 < V_107 [ V_103 ] . V_96 ) {
V_74 -> V_2 . V_96 = V_107 [ V_103 ] . V_96 ;
}
}
F_48 ( V_74 -> V_2 . V_96 == 0 ) ;
} else {
V_74 -> V_2 . V_96 = V_12 -> V_96 ;
}
if ( ( V_74 -> V_2 . V_22 & V_109 ) &&
F_46 ( V_74 -> V_15 , & V_74 -> V_2 ) ) {
V_74 -> V_2 . V_22 &= ~ V_109 ;
F_43 ( V_101 L_8 ,
V_8 -> V_73 ) ;
}
if ( ( V_74 -> V_2 . V_22 & V_109 ) &&
F_46 ( V_74 -> V_2 . V_26 , & V_74 -> V_2 ) ) {
V_74 -> V_2 . V_22 &= ~ V_109 ;
F_43 ( V_101 L_9 ,
V_8 -> V_73 ) ;
}
V_74 -> V_2 . V_110 = V_12 -> V_110 ;
V_74 -> V_2 . V_111 = V_12 -> V_111 ;
V_74 -> V_2 . V_112 = V_12 -> V_112 ;
V_74 -> V_2 . V_113 = V_12 -> V_113 ;
if ( V_12 -> V_69 ) {
T_5 V_114 = 0 ;
while ( V_114 < V_74 -> V_2 . V_26 ) {
if ( F_49 ( V_12 , V_114 + V_74 -> V_15 ) )
V_74 -> V_2 . V_13 . V_115 ++ ;
else if ( F_50 ( V_12 , V_114 + V_74 -> V_15 ) )
V_74 -> V_2 . V_13 . V_71 ++ ;
V_114 += V_74 -> V_2 . V_96 ;
}
}
V_99:
return V_74 ;
}
static T_7 F_51 ( struct V_116 * V_90 ,
struct V_117 * V_118 , char * V_6 )
{
struct V_1 * V_2 = F_52 ( V_90 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
return snprintf ( V_6 , V_119 , L_10 , V_8 -> V_15 ) ;
}
static int F_53 ( struct V_7 * V_120 )
{
int V_55 = F_54 ( & V_120 -> V_2 . V_90 . V_121 , V_122 ) ;
if ( V_55 )
F_43 ( V_101
L_11 , V_55 ) ;
return V_55 ;
}
int F_55 ( struct V_1 * V_12 , const char * V_73 ,
long long V_15 , long long V_123 )
{
struct V_79 V_8 ;
struct V_7 * V_120 ;
int V_55 = 0 ;
if ( V_15 == V_94 ||
V_15 == V_95 )
return - V_27 ;
if ( V_123 == V_100 )
V_123 = V_12 -> V_26 - V_15 ;
if ( V_123 <= 0 )
return - V_27 ;
V_8 . V_73 = V_73 ;
V_8 . V_26 = V_123 ;
V_8 . V_15 = V_15 ;
V_8 . V_85 = 0 ;
V_8 . V_110 = NULL ;
V_120 = F_40 ( V_12 , & V_8 , - 1 , V_15 ) ;
if ( F_56 ( V_120 ) )
return F_57 ( V_120 ) ;
F_35 ( & V_77 ) ;
F_58 ( & V_120 -> V_78 , & V_124 ) ;
F_39 ( & V_77 ) ;
F_59 ( & V_120 -> V_2 ) ;
F_53 ( V_120 ) ;
return V_55 ;
}
int F_60 ( struct V_1 * V_12 , int V_80 )
{
struct V_7 * V_74 , * V_75 ;
int V_55 = - V_27 ;
F_35 ( & V_77 ) ;
F_36 (slave, next, &mtd_partitions, list)
if ( ( V_74 -> V_12 == V_12 ) &&
( V_74 -> V_2 . V_125 == V_80 ) ) {
F_61 ( & V_74 -> V_2 . V_90 . V_121 ,
V_122 ) ;
V_55 = F_37 ( & V_74 -> V_2 ) ;
if ( V_55 < 0 )
break;
F_38 ( & V_74 -> V_78 ) ;
F_32 ( V_74 ) ;
break;
}
F_39 ( & V_77 ) ;
return V_55 ;
}
int F_62 ( struct V_1 * V_12 ,
const struct V_79 * V_126 ,
int V_127 )
{
struct V_7 * V_74 ;
T_5 V_81 = 0 ;
int V_103 ;
F_43 ( V_97 L_12 , V_127 , V_12 -> V_73 ) ;
for ( V_103 = 0 ; V_103 < V_127 ; V_103 ++ ) {
V_74 = F_40 ( V_12 , V_126 + V_103 , V_103 , V_81 ) ;
if ( F_56 ( V_74 ) )
return F_57 ( V_74 ) ;
F_35 ( & V_77 ) ;
F_58 ( & V_74 -> V_78 , & V_124 ) ;
F_39 ( & V_77 ) ;
F_59 ( & V_74 -> V_2 ) ;
F_53 ( V_74 ) ;
V_81 = V_74 -> V_15 + V_74 -> V_2 . V_26 ;
}
return 0 ;
}
static struct V_128 * F_63 ( const char * V_73 )
{
struct V_128 * V_72 , * V_55 = NULL ;
F_64 ( & V_129 ) ;
F_65 (p, &part_parsers, list)
if ( ! strcmp ( V_72 -> V_73 , V_73 ) && F_66 ( V_72 -> V_89 ) ) {
V_55 = V_72 ;
break;
}
F_67 ( & V_129 ) ;
return V_55 ;
}
void F_68 ( struct V_128 * V_72 )
{
F_64 ( & V_129 ) ;
F_58 ( & V_72 -> V_78 , & V_130 ) ;
F_67 ( & V_129 ) ;
}
void F_69 ( struct V_128 * V_72 )
{
F_64 ( & V_129 ) ;
F_38 ( & V_72 -> V_78 ) ;
F_67 ( & V_129 ) ;
}
int F_70 ( struct V_1 * V_12 , const char * const * V_131 ,
struct V_79 * * V_132 ,
struct V_133 * V_134 )
{
struct V_128 * V_135 ;
int V_55 = 0 ;
if ( ! V_131 )
V_131 = V_136 ;
for ( ; V_55 <= 0 && * V_131 ; V_131 ++ ) {
V_135 = F_63 ( * V_131 ) ;
if ( ! V_135 && ! F_71 ( L_13 , * V_131 ) )
V_135 = F_63 ( * V_131 ) ;
if ( ! V_135 )
continue;
V_55 = (* V_135 -> V_137 )( V_12 , V_132 , V_134 ) ;
F_72 ( V_135 ) ;
if ( V_55 > 0 ) {
F_43 ( V_97 L_14 ,
V_55 , V_135 -> V_73 , V_12 -> V_73 ) ;
break;
}
}
return V_55 ;
}
int F_73 ( const struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_138 = 0 ;
F_35 ( & V_77 ) ;
F_65 (part, &mtd_partitions, list)
if ( & V_8 -> V_2 == V_2 ) {
V_138 = 1 ;
break;
}
F_39 ( & V_77 ) ;
return V_138 ;
}
T_5 F_74 ( const struct V_1 * V_2 )
{
if ( ! F_73 ( V_2 ) )
return V_2 -> V_26 ;
return F_2 ( V_2 ) -> V_12 -> V_26 ;
}
