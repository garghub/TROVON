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
if ( V_25 -> V_31 == V_32 )
V_5 = V_3 -> V_33 ;
else
V_5 = V_3 -> V_34 ;
V_30 = F_10 ( V_3 -> V_26 , V_3 ) ;
V_30 -= F_10 ( V_4 , V_3 ) ;
if ( V_25 -> V_35 + V_25 -> V_36 > V_30 * V_5 )
return - V_27 ;
}
V_11 = V_8 -> V_12 -> V_37 ( V_8 -> V_12 , V_4 + V_8 -> V_15 , V_25 ) ;
if ( F_4 ( V_11 ) ) {
if ( F_11 ( V_11 ) )
V_3 -> V_13 . V_17 ++ ;
if ( F_5 ( V_11 ) )
V_3 -> V_13 . V_16 ++ ;
}
return V_11 ;
}
static int F_12 ( struct V_2 * V_3 , T_1 V_4 ,
T_2 V_5 , T_2 * V_6 , T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_38 ( V_8 -> V_12 , V_4 , V_5 ,
V_6 , V_7 ) ;
}
static int F_13 ( struct V_2 * V_3 , T_2 V_5 ,
T_2 * V_6 , struct V_39 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_40 ( V_8 -> V_12 , V_5 , V_6 ,
V_7 ) ;
}
static int F_14 ( struct V_2 * V_3 , T_1 V_4 ,
T_2 V_5 , T_2 * V_6 , T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_41 ( V_8 -> V_12 , V_4 , V_5 ,
V_6 , V_7 ) ;
}
static int F_15 ( struct V_2 * V_3 , T_2 V_5 ,
T_2 * V_6 , struct V_39 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_42 ( V_8 -> V_12 , V_5 , V_6 ,
V_7 ) ;
}
static int F_16 ( struct V_2 * V_3 , T_1 V_43 , T_2 V_5 ,
T_2 * V_6 , const T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_44 ( V_8 -> V_12 , V_43 + V_8 -> V_15 , V_5 ,
V_6 , V_7 ) ;
}
static int F_17 ( struct V_2 * V_3 , T_1 V_43 , T_2 V_5 ,
T_2 * V_6 , const T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_45 ( V_8 -> V_12 , V_43 + V_8 -> V_15 , V_5 ,
V_6 , V_7 ) ;
}
static int F_18 ( struct V_2 * V_3 , T_1 V_43 ,
struct V_24 * V_25 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_43 >= V_3 -> V_26 )
return - V_27 ;
if ( V_25 -> V_28 && V_43 + V_25 -> V_5 > V_3 -> V_26 )
return - V_27 ;
return V_8 -> V_12 -> V_46 ( V_8 -> V_12 , V_43 + V_8 -> V_15 , V_25 ) ;
}
static int F_19 ( struct V_2 * V_3 , T_1 V_4 ,
T_2 V_5 , T_2 * V_6 , T_3 * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_47 ( V_8 -> V_12 , V_4 , V_5 ,
V_6 , V_7 ) ;
}
static int F_20 ( struct V_2 * V_3 , T_1 V_4 ,
T_2 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_48 ( V_8 -> V_12 , V_4 , V_5 ) ;
}
static int F_21 ( struct V_2 * V_3 , const struct V_49 * V_50 ,
unsigned long V_51 , T_1 V_43 , T_2 * V_6 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_52 ( V_8 -> V_12 , V_50 , V_51 ,
V_43 + V_8 -> V_15 , V_6 ) ;
}
static int F_22 ( struct V_2 * V_3 , struct V_53 * V_54 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
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
void F_23 ( struct V_53 * V_54 )
{
if ( V_54 -> V_3 -> V_57 == F_22 ) {
struct V_1 * V_8 = F_1 ( V_54 -> V_3 ) ;
if ( V_54 -> V_58 != V_59 )
V_54 -> V_58 -= V_8 -> V_15 ;
V_54 -> V_56 -= V_8 -> V_15 ;
}
if ( V_54 -> V_60 )
V_54 -> V_60 ( V_54 ) ;
}
static int F_24 ( struct V_2 * V_3 , T_1 V_61 , T_5 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_62 ( V_8 -> V_12 , V_61 + V_8 -> V_15 , V_5 ) ;
}
static int F_25 ( struct V_2 * V_3 , T_1 V_61 , T_5 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_63 ( V_8 -> V_12 , V_61 + V_8 -> V_15 , V_5 ) ;
}
static int F_26 ( struct V_2 * V_3 , T_1 V_61 , T_5 V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_64 ( V_8 -> V_12 , V_61 + V_8 -> V_15 , V_5 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_12 -> V_65 ( V_8 -> V_12 ) ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return V_8 -> V_12 -> V_66 ( V_8 -> V_12 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_12 -> V_67 ( V_8 -> V_12 ) ;
}
static int F_30 ( struct V_2 * V_3 , T_1 V_61 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_61 += V_8 -> V_15 ;
return V_8 -> V_12 -> V_68 ( V_8 -> V_12 , V_61 ) ;
}
static int F_31 ( struct V_2 * V_3 , T_1 V_61 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_61 += V_8 -> V_15 ;
return V_8 -> V_12 -> V_69 ( V_8 -> V_12 , V_61 ) ;
}
static int F_32 ( struct V_2 * V_3 , T_1 V_61 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_11 ;
V_61 += V_8 -> V_15 ;
V_11 = V_8 -> V_12 -> V_70 ( V_8 -> V_12 , V_61 ) ;
if ( ! V_11 )
V_3 -> V_13 . V_71 ++ ;
return V_11 ;
}
static inline void F_33 ( struct V_1 * V_72 )
{
F_34 ( V_72 -> V_3 . V_73 ) ;
F_34 ( V_72 ) ;
}
int F_35 ( struct V_2 * V_12 )
{
struct V_1 * V_74 , * V_75 ;
int V_55 , V_76 = 0 ;
F_36 ( & V_77 ) ;
F_37 (slave, next, &mtd_partitions, list)
if ( V_74 -> V_12 == V_12 ) {
V_55 = F_38 ( & V_74 -> V_3 ) ;
if ( V_55 < 0 ) {
V_76 = V_55 ;
continue;
}
F_39 ( & V_74 -> V_78 ) ;
F_33 ( V_74 ) ;
}
F_40 ( & V_77 ) ;
return V_76 ;
}
static struct V_1 * F_41 ( struct V_2 * V_12 ,
const struct V_79 * V_8 , int V_80 ,
T_5 V_81 )
{
struct V_1 * V_74 ;
char * V_73 ;
V_74 = F_42 ( sizeof( * V_74 ) , V_82 ) ;
V_73 = F_43 ( V_8 -> V_73 , V_82 ) ;
if ( ! V_73 || ! V_74 ) {
F_44 ( V_83 L_1 ,
V_12 -> V_73 ) ;
F_34 ( V_73 ) ;
F_34 ( V_74 ) ;
return F_45 ( - V_84 ) ;
}
V_74 -> V_3 . type = V_12 -> type ;
V_74 -> V_3 . V_22 = V_12 -> V_22 & ~ V_8 -> V_85 ;
V_74 -> V_3 . V_26 = V_8 -> V_26 ;
V_74 -> V_3 . V_86 = V_12 -> V_86 ;
V_74 -> V_3 . V_87 = V_12 -> V_87 ;
V_74 -> V_3 . V_34 = V_12 -> V_34 ;
V_74 -> V_3 . V_33 = V_12 -> V_33 ;
V_74 -> V_3 . V_88 = V_12 -> V_88 ;
V_74 -> V_3 . V_73 = V_73 ;
V_74 -> V_3 . V_89 = V_12 -> V_89 ;
V_74 -> V_3 . V_90 . V_91 = F_46 ( V_92 ) ?
& V_12 -> V_90 :
V_12 -> V_90 . V_91 ;
V_74 -> V_3 . V_14 = F_3 ;
V_74 -> V_3 . V_44 = F_16 ;
if ( V_12 -> V_45 )
V_74 -> V_3 . V_45 = F_17 ;
if ( V_12 -> V_20 && V_12 -> V_21 ) {
V_74 -> V_3 . V_20 = F_6 ;
V_74 -> V_3 . V_21 = F_7 ;
}
if ( V_12 -> V_23 )
V_74 -> V_3 . V_23 = F_8 ;
if ( V_12 -> V_37 )
V_74 -> V_3 . V_37 = F_9 ;
if ( V_12 -> V_46 )
V_74 -> V_3 . V_46 = F_18 ;
if ( V_12 -> V_38 )
V_74 -> V_3 . V_38 = F_12 ;
if ( V_12 -> V_41 )
V_74 -> V_3 . V_41 = F_14 ;
if ( V_12 -> V_47 )
V_74 -> V_3 . V_47 = F_19 ;
if ( V_12 -> V_48 )
V_74 -> V_3 . V_48 = F_20 ;
if ( V_12 -> V_40 )
V_74 -> V_3 . V_40 = F_13 ;
if ( V_12 -> V_42 )
V_74 -> V_3 . V_42 = F_15 ;
if ( V_12 -> V_65 )
V_74 -> V_3 . V_65 = F_27 ;
if ( ! V_80 && ! V_12 -> V_90 . V_93 && V_12 -> V_66 &&
V_12 -> V_67 ) {
V_74 -> V_3 . V_66 = F_28 ;
V_74 -> V_3 . V_67 = F_29 ;
}
if ( V_12 -> V_52 )
V_74 -> V_3 . V_52 = F_21 ;
if ( V_12 -> V_62 )
V_74 -> V_3 . V_62 = F_24 ;
if ( V_12 -> V_63 )
V_74 -> V_3 . V_63 = F_25 ;
if ( V_12 -> V_64 )
V_74 -> V_3 . V_64 = F_26 ;
if ( V_12 -> V_68 )
V_74 -> V_3 . V_68 = F_30 ;
if ( V_12 -> V_69 )
V_74 -> V_3 . V_69 = F_31 ;
if ( V_12 -> V_70 )
V_74 -> V_3 . V_70 = F_32 ;
V_74 -> V_3 . V_57 = F_22 ;
V_74 -> V_12 = V_12 ;
V_74 -> V_15 = V_8 -> V_15 ;
if ( V_74 -> V_15 == V_94 )
V_74 -> V_15 = V_81 ;
if ( V_74 -> V_15 == V_95 ) {
V_74 -> V_15 = V_81 ;
if ( F_47 ( V_81 , V_12 ) != 0 ) {
V_74 -> V_15 = ( F_48 ( V_81 , V_12 ) + 1 ) * V_12 -> V_96 ;
F_44 ( V_97 L_2
L_3 , V_80 ,
( unsigned long long ) V_81 , ( unsigned long long ) V_74 -> V_15 ) ;
}
}
if ( V_74 -> V_15 == V_98 ) {
V_74 -> V_15 = V_81 ;
if ( V_12 -> V_26 - V_74 -> V_15 >= V_74 -> V_3 . V_26 ) {
V_74 -> V_3 . V_26 = V_12 -> V_26 - V_74 -> V_15
- V_74 -> V_3 . V_26 ;
} else {
F_44 ( V_83 L_4 ,
V_8 -> V_73 , V_12 -> V_26 - V_74 -> V_15 ,
V_74 -> V_3 . V_26 ) ;
goto V_99;
}
}
if ( V_74 -> V_3 . V_26 == V_100 )
V_74 -> V_3 . V_26 = V_12 -> V_26 - V_74 -> V_15 ;
F_44 ( V_97 L_5 , ( unsigned long long ) V_74 -> V_15 ,
( unsigned long long ) ( V_74 -> V_15 + V_74 -> V_3 . V_26 ) , V_74 -> V_3 . V_73 ) ;
if ( V_74 -> V_15 >= V_12 -> V_26 ) {
V_74 -> V_15 = 0 ;
V_74 -> V_3 . V_26 = 0 ;
F_44 ( V_83 L_6 ,
V_8 -> V_73 ) ;
goto V_99;
}
if ( V_74 -> V_15 + V_74 -> V_3 . V_26 > V_12 -> V_26 ) {
V_74 -> V_3 . V_26 = V_12 -> V_26 - V_74 -> V_15 ;
F_44 ( V_101 L_7 ,
V_8 -> V_73 , V_12 -> V_73 , ( unsigned long long ) V_74 -> V_3 . V_26 ) ;
}
if ( V_12 -> V_102 > 1 ) {
int V_103 , V_104 = V_12 -> V_102 ;
T_6 V_105 = V_74 -> V_15 + V_74 -> V_3 . V_26 ;
struct V_106 * V_107 = V_12 -> V_108 ;
for ( V_103 = 0 ; V_103 < V_104 && V_107 [ V_103 ] . V_15 <= V_74 -> V_15 ; V_103 ++ )
;
if ( V_103 > 0 )
V_103 -- ;
for (; V_103 < V_104 && V_107 [ V_103 ] . V_15 < V_105 ; V_103 ++ ) {
if ( V_74 -> V_3 . V_96 < V_107 [ V_103 ] . V_96 ) {
V_74 -> V_3 . V_96 = V_107 [ V_103 ] . V_96 ;
}
}
F_49 ( V_74 -> V_3 . V_96 == 0 ) ;
} else {
V_74 -> V_3 . V_96 = V_12 -> V_96 ;
}
if ( ( V_74 -> V_3 . V_22 & V_109 ) &&
F_47 ( V_74 -> V_15 , & V_74 -> V_3 ) ) {
V_74 -> V_3 . V_22 &= ~ V_109 ;
F_44 ( V_101 L_8 ,
V_8 -> V_73 ) ;
}
if ( ( V_74 -> V_3 . V_22 & V_109 ) &&
F_47 ( V_74 -> V_3 . V_26 , & V_74 -> V_3 ) ) {
V_74 -> V_3 . V_22 &= ~ V_109 ;
F_44 ( V_101 L_9 ,
V_8 -> V_73 ) ;
}
V_74 -> V_3 . V_110 = V_12 -> V_110 ;
V_74 -> V_3 . V_111 = V_12 -> V_111 ;
V_74 -> V_3 . V_112 = V_12 -> V_112 ;
V_74 -> V_3 . V_113 = V_12 -> V_113 ;
if ( V_12 -> V_69 ) {
T_5 V_114 = 0 ;
while ( V_114 < V_74 -> V_3 . V_26 ) {
if ( F_50 ( V_12 , V_114 + V_74 -> V_15 ) )
V_74 -> V_3 . V_13 . V_115 ++ ;
else if ( F_51 ( V_12 , V_114 + V_74 -> V_15 ) )
V_74 -> V_3 . V_13 . V_71 ++ ;
V_114 += V_74 -> V_3 . V_96 ;
}
}
V_99:
return V_74 ;
}
static T_7 F_52 ( struct V_116 * V_90 ,
struct V_117 * V_118 , char * V_7 )
{
struct V_2 * V_3 = F_53 ( V_90 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
return snprintf ( V_7 , V_119 , L_10 , V_8 -> V_15 ) ;
}
static int F_54 ( struct V_1 * V_120 )
{
int V_55 = F_55 ( & V_120 -> V_3 . V_90 . V_121 , V_122 ) ;
if ( V_55 )
F_44 ( V_101
L_11 , V_55 ) ;
return V_55 ;
}
int F_56 ( struct V_2 * V_12 , const char * V_73 ,
long long V_15 , long long V_123 )
{
struct V_79 V_8 ;
struct V_1 * V_120 ;
int V_55 = 0 ;
if ( V_15 == V_94 ||
V_15 == V_95 )
return - V_27 ;
if ( V_123 == V_100 )
V_123 = V_12 -> V_26 - V_15 ;
if ( V_123 <= 0 )
return - V_27 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_73 = V_73 ;
V_8 . V_26 = V_123 ;
V_8 . V_15 = V_15 ;
V_120 = F_41 ( V_12 , & V_8 , - 1 , V_15 ) ;
if ( F_57 ( V_120 ) )
return F_58 ( V_120 ) ;
F_36 ( & V_77 ) ;
F_59 ( & V_120 -> V_78 , & V_124 ) ;
F_40 ( & V_77 ) ;
F_60 ( & V_120 -> V_3 ) ;
F_54 ( V_120 ) ;
return V_55 ;
}
int F_61 ( struct V_2 * V_12 , int V_80 )
{
struct V_1 * V_74 , * V_75 ;
int V_55 = - V_27 ;
F_36 ( & V_77 ) ;
F_37 (slave, next, &mtd_partitions, list)
if ( ( V_74 -> V_12 == V_12 ) &&
( V_74 -> V_3 . V_125 == V_80 ) ) {
F_62 ( & V_74 -> V_3 . V_90 . V_121 ,
V_122 ) ;
V_55 = F_38 ( & V_74 -> V_3 ) ;
if ( V_55 < 0 )
break;
F_39 ( & V_74 -> V_78 ) ;
F_33 ( V_74 ) ;
break;
}
F_40 ( & V_77 ) ;
return V_55 ;
}
int F_63 ( struct V_2 * V_12 ,
const struct V_79 * V_126 ,
int V_127 )
{
struct V_1 * V_74 ;
T_5 V_81 = 0 ;
int V_103 ;
F_44 ( V_97 L_12 , V_127 , V_12 -> V_73 ) ;
for ( V_103 = 0 ; V_103 < V_127 ; V_103 ++ ) {
V_74 = F_41 ( V_12 , V_126 + V_103 , V_103 , V_81 ) ;
if ( F_57 ( V_74 ) ) {
F_35 ( V_12 ) ;
return F_58 ( V_74 ) ;
}
F_36 ( & V_77 ) ;
F_59 ( & V_74 -> V_78 , & V_124 ) ;
F_40 ( & V_77 ) ;
F_60 ( & V_74 -> V_3 ) ;
F_54 ( V_74 ) ;
V_81 = V_74 -> V_15 + V_74 -> V_3 . V_26 ;
}
return 0 ;
}
static struct V_128 * F_64 ( const char * V_73 )
{
struct V_128 * V_72 , * V_55 = NULL ;
F_65 ( & V_129 ) ;
F_66 (p, &part_parsers, list)
if ( ! strcmp ( V_72 -> V_73 , V_73 ) && F_67 ( V_72 -> V_89 ) ) {
V_55 = V_72 ;
break;
}
F_68 ( & V_129 ) ;
return V_55 ;
}
static inline void F_69 ( const struct V_128 * V_72 )
{
F_70 ( V_72 -> V_89 ) ;
}
static void F_71 ( const struct V_79 * V_130 ,
int V_131 )
{
F_34 ( V_130 ) ;
}
int F_72 ( struct V_128 * V_72 , struct V_132 * V_89 )
{
V_72 -> V_89 = V_89 ;
if ( ! V_72 -> V_133 )
V_72 -> V_133 = & F_71 ;
F_65 ( & V_129 ) ;
F_59 ( & V_72 -> V_78 , & V_134 ) ;
F_68 ( & V_129 ) ;
return 0 ;
}
void F_73 ( struct V_128 * V_72 )
{
F_65 ( & V_129 ) ;
F_39 ( & V_72 -> V_78 ) ;
F_68 ( & V_129 ) ;
}
int F_74 ( struct V_2 * V_12 , const char * const * V_135 ,
struct V_124 * V_130 ,
struct V_136 * V_137 )
{
struct V_128 * V_138 ;
int V_55 , V_76 = 0 ;
if ( ! V_135 )
V_135 = V_139 ;
for ( ; * V_135 ; V_135 ++ ) {
F_75 ( L_13 , V_12 -> V_73 , * V_135 ) ;
V_138 = F_64 ( * V_135 ) ;
if ( ! V_138 && ! F_76 ( L_14 , * V_135 ) )
V_138 = F_64 ( * V_135 ) ;
F_75 ( L_15 , V_12 -> V_73 ,
V_138 ? V_138 -> V_73 : NULL ) ;
if ( ! V_138 )
continue;
V_55 = (* V_138 -> V_140 )( V_12 , & V_130 -> V_126 , V_137 ) ;
F_75 ( L_16 ,
V_12 -> V_73 , V_138 -> V_73 , V_55 ) ;
if ( V_55 > 0 ) {
F_44 ( V_97 L_17 ,
V_55 , V_138 -> V_73 , V_12 -> V_73 ) ;
V_130 -> V_131 = V_55 ;
V_130 -> V_138 = V_138 ;
return 0 ;
}
F_69 ( V_138 ) ;
if ( V_55 < 0 && ! V_76 )
V_76 = V_55 ;
}
return V_76 ;
}
void F_77 ( struct V_124 * V_126 )
{
const struct V_128 * V_138 ;
if ( ! V_126 )
return;
V_138 = V_126 -> V_138 ;
if ( V_138 ) {
if ( V_138 -> V_133 )
V_138 -> V_133 ( V_126 -> V_126 , V_126 -> V_131 ) ;
F_69 ( V_138 ) ;
}
}
int F_78 ( const struct V_2 * V_3 )
{
struct V_1 * V_8 ;
int V_141 = 0 ;
F_36 ( & V_77 ) ;
F_66 (part, &mtd_partitions, list)
if ( & V_8 -> V_3 == V_3 ) {
V_141 = 1 ;
break;
}
F_40 ( & V_77 ) ;
return V_141 ;
}
T_5 F_79 ( const struct V_2 * V_3 )
{
if ( ! F_78 ( V_3 ) )
return V_3 -> V_26 ;
return F_1 ( V_3 ) -> V_12 -> V_26 ;
}
