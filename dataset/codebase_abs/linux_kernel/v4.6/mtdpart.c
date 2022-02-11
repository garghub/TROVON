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
static inline void F_34 ( struct V_1 * V_68 )
{
F_35 ( V_68 -> V_3 . V_69 ) ;
F_35 ( V_68 ) ;
}
int F_36 ( struct V_2 * V_12 )
{
struct V_1 * V_70 , * V_71 ;
int V_51 , V_72 = 0 ;
F_37 ( & V_73 ) ;
F_38 (slave, next, &mtd_partitions, list)
if ( V_70 -> V_12 == V_12 ) {
V_51 = F_39 ( & V_70 -> V_3 ) ;
if ( V_51 < 0 ) {
V_72 = V_51 ;
continue;
}
F_40 ( & V_70 -> V_74 ) ;
F_34 ( V_70 ) ;
}
F_41 ( & V_73 ) ;
return V_72 ;
}
static struct V_1 * F_42 ( struct V_2 * V_12 ,
const struct V_75 * V_8 , int V_76 ,
T_5 V_77 )
{
struct V_1 * V_70 ;
char * V_69 ;
V_70 = F_43 ( sizeof( * V_70 ) , V_78 ) ;
V_69 = F_44 ( V_8 -> V_69 , V_78 ) ;
if ( ! V_69 || ! V_70 ) {
F_45 ( V_79 L_1 ,
V_12 -> V_69 ) ;
F_35 ( V_69 ) ;
F_35 ( V_70 ) ;
return F_46 ( - V_80 ) ;
}
V_70 -> V_3 . type = V_12 -> type ;
V_70 -> V_3 . V_22 = V_12 -> V_22 & ~ V_8 -> V_81 ;
V_70 -> V_3 . V_26 = V_8 -> V_26 ;
V_70 -> V_3 . V_82 = V_12 -> V_82 ;
V_70 -> V_3 . V_83 = V_12 -> V_83 ;
V_70 -> V_3 . V_84 = V_12 -> V_84 ;
V_70 -> V_3 . V_85 = V_12 -> V_85 ;
V_70 -> V_3 . V_86 = V_12 -> V_86 ;
V_70 -> V_3 . V_69 = V_69 ;
V_70 -> V_3 . V_87 = V_12 -> V_87 ;
V_70 -> V_3 . V_88 . V_89 = F_47 ( V_90 ) ?
& V_12 -> V_88 :
V_12 -> V_88 . V_89 ;
V_70 -> V_3 . V_14 = F_3 ;
V_70 -> V_3 . V_40 = F_17 ;
if ( V_12 -> V_41 )
V_70 -> V_3 . V_41 = F_18 ;
if ( V_12 -> V_20 && V_12 -> V_21 ) {
V_70 -> V_3 . V_20 = F_6 ;
V_70 -> V_3 . V_21 = F_7 ;
}
if ( V_12 -> V_23 )
V_70 -> V_3 . V_23 = F_8 ;
if ( V_12 -> V_33 )
V_70 -> V_3 . V_33 = F_9 ;
if ( V_12 -> V_42 )
V_70 -> V_3 . V_42 = F_19 ;
if ( V_12 -> V_34 )
V_70 -> V_3 . V_34 = F_13 ;
if ( V_12 -> V_37 )
V_70 -> V_3 . V_37 = F_15 ;
if ( V_12 -> V_43 )
V_70 -> V_3 . V_43 = F_20 ;
if ( V_12 -> V_44 )
V_70 -> V_3 . V_44 = F_21 ;
if ( V_12 -> V_36 )
V_70 -> V_3 . V_36 = F_14 ;
if ( V_12 -> V_38 )
V_70 -> V_3 . V_38 = F_16 ;
if ( V_12 -> V_61 )
V_70 -> V_3 . V_61 = F_28 ;
if ( ! V_76 && ! V_12 -> V_88 . V_91 && V_12 -> V_62 &&
V_12 -> V_63 ) {
V_70 -> V_3 . V_62 = F_29 ;
V_70 -> V_3 . V_63 = F_30 ;
}
if ( V_12 -> V_48 )
V_70 -> V_3 . V_48 = F_22 ;
if ( V_12 -> V_58 )
V_70 -> V_3 . V_58 = F_25 ;
if ( V_12 -> V_59 )
V_70 -> V_3 . V_59 = F_26 ;
if ( V_12 -> V_60 )
V_70 -> V_3 . V_60 = F_27 ;
if ( V_12 -> V_64 )
V_70 -> V_3 . V_64 = F_31 ;
if ( V_12 -> V_65 )
V_70 -> V_3 . V_65 = F_32 ;
if ( V_12 -> V_66 )
V_70 -> V_3 . V_66 = F_33 ;
V_70 -> V_3 . V_53 = F_23 ;
V_70 -> V_12 = V_12 ;
V_70 -> V_15 = V_8 -> V_15 ;
if ( V_70 -> V_15 == V_92 )
V_70 -> V_15 = V_77 ;
if ( V_70 -> V_15 == V_93 ) {
V_70 -> V_15 = V_77 ;
if ( F_48 ( V_77 , V_12 ) != 0 ) {
V_70 -> V_15 = ( F_49 ( V_77 , V_12 ) + 1 ) * V_12 -> V_94 ;
F_45 ( V_95 L_2
L_3 , V_76 ,
( unsigned long long ) V_77 , ( unsigned long long ) V_70 -> V_15 ) ;
}
}
if ( V_70 -> V_15 == V_96 ) {
V_70 -> V_15 = V_77 ;
if ( V_12 -> V_26 - V_70 -> V_15 >= V_70 -> V_3 . V_26 ) {
V_70 -> V_3 . V_26 = V_12 -> V_26 - V_70 -> V_15
- V_70 -> V_3 . V_26 ;
} else {
F_45 ( V_79 L_4 ,
V_8 -> V_69 , V_12 -> V_26 - V_70 -> V_15 ,
V_70 -> V_3 . V_26 ) ;
goto V_97;
}
}
if ( V_70 -> V_3 . V_26 == V_98 )
V_70 -> V_3 . V_26 = V_12 -> V_26 - V_70 -> V_15 ;
F_45 ( V_95 L_5 , ( unsigned long long ) V_70 -> V_15 ,
( unsigned long long ) ( V_70 -> V_15 + V_70 -> V_3 . V_26 ) , V_70 -> V_3 . V_69 ) ;
if ( V_70 -> V_15 >= V_12 -> V_26 ) {
V_70 -> V_15 = 0 ;
V_70 -> V_3 . V_26 = 0 ;
F_45 ( V_79 L_6 ,
V_8 -> V_69 ) ;
goto V_97;
}
if ( V_70 -> V_15 + V_70 -> V_3 . V_26 > V_12 -> V_26 ) {
V_70 -> V_3 . V_26 = V_12 -> V_26 - V_70 -> V_15 ;
F_45 ( V_99 L_7 ,
V_8 -> V_69 , V_12 -> V_69 , ( unsigned long long ) V_70 -> V_3 . V_26 ) ;
}
if ( V_12 -> V_100 > 1 ) {
int V_101 , V_102 = V_12 -> V_100 ;
T_6 V_103 = V_70 -> V_15 + V_70 -> V_3 . V_26 ;
struct V_104 * V_105 = V_12 -> V_106 ;
for ( V_101 = 0 ; V_101 < V_102 && V_105 [ V_101 ] . V_15 <= V_70 -> V_15 ; V_101 ++ )
;
if ( V_101 > 0 )
V_101 -- ;
for (; V_101 < V_102 && V_105 [ V_101 ] . V_15 < V_103 ; V_101 ++ ) {
if ( V_70 -> V_3 . V_94 < V_105 [ V_101 ] . V_94 ) {
V_70 -> V_3 . V_94 = V_105 [ V_101 ] . V_94 ;
}
}
F_50 ( V_70 -> V_3 . V_94 == 0 ) ;
} else {
V_70 -> V_3 . V_94 = V_12 -> V_94 ;
}
if ( ( V_70 -> V_3 . V_22 & V_107 ) &&
F_48 ( V_70 -> V_15 , & V_70 -> V_3 ) ) {
V_70 -> V_3 . V_22 &= ~ V_107 ;
F_45 ( V_99 L_8 ,
V_8 -> V_69 ) ;
}
if ( ( V_70 -> V_3 . V_22 & V_107 ) &&
F_48 ( V_70 -> V_3 . V_26 , & V_70 -> V_3 ) ) {
V_70 -> V_3 . V_22 &= ~ V_107 ;
F_45 ( V_99 L_9 ,
V_8 -> V_69 ) ;
}
V_70 -> V_3 . V_108 = V_12 -> V_108 ;
V_70 -> V_3 . V_109 = V_12 -> V_109 ;
V_70 -> V_3 . V_110 = V_12 -> V_110 ;
V_70 -> V_3 . V_111 = V_12 -> V_111 ;
if ( V_12 -> V_65 ) {
T_5 V_112 = 0 ;
while ( V_112 < V_70 -> V_3 . V_26 ) {
if ( F_51 ( V_12 , V_112 + V_70 -> V_15 ) )
V_70 -> V_3 . V_13 . V_113 ++ ;
else if ( F_52 ( V_12 , V_112 + V_70 -> V_15 ) )
V_70 -> V_3 . V_13 . V_67 ++ ;
V_112 += V_70 -> V_3 . V_94 ;
}
}
V_97:
return V_70 ;
}
static T_7 F_53 ( struct V_114 * V_88 ,
struct V_115 * V_116 , char * V_7 )
{
struct V_2 * V_3 = F_54 ( V_88 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
return snprintf ( V_7 , V_117 , L_10 , V_8 -> V_15 ) ;
}
static int F_55 ( struct V_1 * V_118 )
{
int V_51 = F_56 ( & V_118 -> V_3 . V_88 . V_119 , V_120 ) ;
if ( V_51 )
F_45 ( V_99
L_11 , V_51 ) ;
return V_51 ;
}
int F_57 ( struct V_2 * V_12 , const char * V_69 ,
long long V_15 , long long V_121 )
{
struct V_75 V_8 ;
struct V_1 * V_118 ;
int V_51 = 0 ;
if ( V_15 == V_92 ||
V_15 == V_93 )
return - V_27 ;
if ( V_121 == V_98 )
V_121 = V_12 -> V_26 - V_15 ;
if ( V_121 <= 0 )
return - V_27 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_69 = V_69 ;
V_8 . V_26 = V_121 ;
V_8 . V_15 = V_15 ;
V_118 = F_42 ( V_12 , & V_8 , - 1 , V_15 ) ;
if ( F_58 ( V_118 ) )
return F_59 ( V_118 ) ;
F_37 ( & V_73 ) ;
F_60 ( & V_118 -> V_74 , & V_122 ) ;
F_41 ( & V_73 ) ;
F_61 ( & V_118 -> V_3 ) ;
F_55 ( V_118 ) ;
return V_51 ;
}
int F_62 ( struct V_2 * V_12 , int V_76 )
{
struct V_1 * V_70 , * V_71 ;
int V_51 = - V_27 ;
F_37 ( & V_73 ) ;
F_38 (slave, next, &mtd_partitions, list)
if ( ( V_70 -> V_12 == V_12 ) &&
( V_70 -> V_3 . V_123 == V_76 ) ) {
F_63 ( & V_70 -> V_3 . V_88 . V_119 ,
V_120 ) ;
V_51 = F_39 ( & V_70 -> V_3 ) ;
if ( V_51 < 0 )
break;
F_40 ( & V_70 -> V_74 ) ;
F_34 ( V_70 ) ;
break;
}
F_41 ( & V_73 ) ;
return V_51 ;
}
int F_64 ( struct V_2 * V_12 ,
const struct V_75 * V_124 ,
int V_125 )
{
struct V_1 * V_70 ;
T_5 V_77 = 0 ;
int V_101 ;
F_45 ( V_95 L_12 , V_125 , V_12 -> V_69 ) ;
for ( V_101 = 0 ; V_101 < V_125 ; V_101 ++ ) {
V_70 = F_42 ( V_12 , V_124 + V_101 , V_101 , V_77 ) ;
if ( F_58 ( V_70 ) ) {
F_36 ( V_12 ) ;
return F_59 ( V_70 ) ;
}
F_37 ( & V_73 ) ;
F_60 ( & V_70 -> V_74 , & V_122 ) ;
F_41 ( & V_73 ) ;
F_61 ( & V_70 -> V_3 ) ;
F_55 ( V_70 ) ;
V_77 = V_70 -> V_15 + V_70 -> V_3 . V_26 ;
}
return 0 ;
}
static struct V_126 * F_65 ( const char * V_69 )
{
struct V_126 * V_68 , * V_51 = NULL ;
F_66 ( & V_127 ) ;
F_67 (p, &part_parsers, list)
if ( ! strcmp ( V_68 -> V_69 , V_69 ) && F_68 ( V_68 -> V_87 ) ) {
V_51 = V_68 ;
break;
}
F_69 ( & V_127 ) ;
return V_51 ;
}
static inline void F_70 ( const struct V_126 * V_68 )
{
F_71 ( V_68 -> V_87 ) ;
}
static void F_72 ( const struct V_75 * V_128 ,
int V_129 )
{
F_35 ( V_128 ) ;
}
int F_73 ( struct V_126 * V_68 , struct V_130 * V_87 )
{
V_68 -> V_87 = V_87 ;
if ( ! V_68 -> V_131 )
V_68 -> V_131 = & F_72 ;
F_66 ( & V_127 ) ;
F_60 ( & V_68 -> V_74 , & V_132 ) ;
F_69 ( & V_127 ) ;
return 0 ;
}
void F_74 ( struct V_126 * V_68 )
{
F_66 ( & V_127 ) ;
F_40 ( & V_68 -> V_74 ) ;
F_69 ( & V_127 ) ;
}
int F_75 ( struct V_2 * V_12 , const char * const * V_133 ,
struct V_122 * V_128 ,
struct V_134 * V_135 )
{
struct V_126 * V_136 ;
int V_51 , V_72 = 0 ;
if ( ! V_133 )
V_133 = V_137 ;
for ( ; * V_133 ; V_133 ++ ) {
F_76 ( L_13 , V_12 -> V_69 , * V_133 ) ;
V_136 = F_65 ( * V_133 ) ;
if ( ! V_136 && ! F_77 ( L_14 , * V_133 ) )
V_136 = F_65 ( * V_133 ) ;
F_76 ( L_15 , V_12 -> V_69 ,
V_136 ? V_136 -> V_69 : NULL ) ;
if ( ! V_136 )
continue;
V_51 = (* V_136 -> V_138 )( V_12 , & V_128 -> V_124 , V_135 ) ;
F_76 ( L_16 ,
V_12 -> V_69 , V_136 -> V_69 , V_51 ) ;
if ( V_51 > 0 ) {
F_45 ( V_95 L_17 ,
V_51 , V_136 -> V_69 , V_12 -> V_69 ) ;
V_128 -> V_129 = V_51 ;
V_128 -> V_136 = V_136 ;
return 0 ;
}
F_70 ( V_136 ) ;
if ( V_51 < 0 && ! V_72 )
V_72 = V_51 ;
}
return V_72 ;
}
void F_78 ( struct V_122 * V_124 )
{
const struct V_126 * V_136 ;
if ( ! V_124 )
return;
V_136 = V_124 -> V_136 ;
if ( V_136 ) {
if ( V_136 -> V_131 )
V_136 -> V_131 ( V_124 -> V_124 , V_124 -> V_129 ) ;
F_70 ( V_136 ) ;
}
}
int F_79 ( const struct V_2 * V_3 )
{
struct V_1 * V_8 ;
int V_139 = 0 ;
F_37 ( & V_73 ) ;
F_67 (part, &mtd_partitions, list)
if ( & V_8 -> V_3 == V_3 ) {
V_139 = 1 ;
break;
}
F_41 ( & V_73 ) ;
return V_139 ;
}
T_5 F_80 ( const struct V_2 * V_3 )
{
if ( ! F_79 ( V_3 ) )
return V_3 -> V_26 ;
return F_1 ( V_3 ) -> V_12 -> V_26 ;
}
