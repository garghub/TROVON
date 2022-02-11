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
static int F_34 ( struct V_2 * V_3 , int V_68 ,
struct V_69 * V_70 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return F_35 ( V_8 -> V_12 , V_68 , V_70 ) ;
}
static int F_36 ( struct V_2 * V_3 , int V_68 ,
struct V_69 * V_70 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return F_37 ( V_8 -> V_12 , V_68 , V_70 ) ;
}
static inline void F_38 ( struct V_1 * V_71 )
{
F_39 ( V_71 -> V_3 . V_72 ) ;
F_39 ( V_71 ) ;
}
int F_40 ( struct V_2 * V_12 )
{
struct V_1 * V_73 , * V_74 ;
int V_51 , V_75 = 0 ;
F_41 ( & V_76 ) ;
F_42 (slave, next, &mtd_partitions, list)
if ( V_73 -> V_12 == V_12 ) {
V_51 = F_43 ( & V_73 -> V_3 ) ;
if ( V_51 < 0 ) {
V_75 = V_51 ;
continue;
}
F_44 ( & V_73 -> V_77 ) ;
F_38 ( V_73 ) ;
}
F_45 ( & V_76 ) ;
return V_75 ;
}
static struct V_1 * F_46 ( struct V_2 * V_12 ,
const struct V_78 * V_8 , int V_79 ,
T_5 V_80 )
{
struct V_1 * V_73 ;
char * V_72 ;
V_73 = F_47 ( sizeof( * V_73 ) , V_81 ) ;
V_72 = F_48 ( V_8 -> V_72 , V_81 ) ;
if ( ! V_72 || ! V_73 ) {
F_49 ( V_82 L_1 ,
V_12 -> V_72 ) ;
F_39 ( V_72 ) ;
F_39 ( V_73 ) ;
return F_50 ( - V_83 ) ;
}
V_73 -> V_3 . type = V_12 -> type ;
V_73 -> V_3 . V_22 = V_12 -> V_22 & ~ V_8 -> V_84 ;
V_73 -> V_3 . V_26 = V_8 -> V_26 ;
V_73 -> V_3 . V_85 = V_12 -> V_85 ;
V_73 -> V_3 . V_86 = V_12 -> V_86 ;
V_73 -> V_3 . V_87 = V_12 -> V_87 ;
V_73 -> V_3 . V_88 = V_12 -> V_88 ;
V_73 -> V_3 . V_89 = V_12 -> V_89 ;
V_73 -> V_3 . V_72 = V_72 ;
V_73 -> V_3 . V_90 = V_12 -> V_90 ;
V_73 -> V_3 . V_91 . V_92 = F_51 ( V_93 ) ?
& V_12 -> V_91 :
V_12 -> V_91 . V_92 ;
V_73 -> V_3 . V_14 = F_3 ;
V_73 -> V_3 . V_40 = F_17 ;
if ( V_12 -> V_41 )
V_73 -> V_3 . V_41 = F_18 ;
if ( V_12 -> V_20 && V_12 -> V_21 ) {
V_73 -> V_3 . V_20 = F_6 ;
V_73 -> V_3 . V_21 = F_7 ;
}
if ( V_12 -> V_23 )
V_73 -> V_3 . V_23 = F_8 ;
if ( V_12 -> V_33 )
V_73 -> V_3 . V_33 = F_9 ;
if ( V_12 -> V_42 )
V_73 -> V_3 . V_42 = F_19 ;
if ( V_12 -> V_34 )
V_73 -> V_3 . V_34 = F_13 ;
if ( V_12 -> V_37 )
V_73 -> V_3 . V_37 = F_15 ;
if ( V_12 -> V_43 )
V_73 -> V_3 . V_43 = F_20 ;
if ( V_12 -> V_44 )
V_73 -> V_3 . V_44 = F_21 ;
if ( V_12 -> V_36 )
V_73 -> V_3 . V_36 = F_14 ;
if ( V_12 -> V_38 )
V_73 -> V_3 . V_38 = F_16 ;
if ( V_12 -> V_61 )
V_73 -> V_3 . V_61 = F_28 ;
if ( ! V_79 && ! V_12 -> V_91 . V_94 && V_12 -> V_62 &&
V_12 -> V_63 ) {
V_73 -> V_3 . V_62 = F_29 ;
V_73 -> V_3 . V_63 = F_30 ;
}
if ( V_12 -> V_48 )
V_73 -> V_3 . V_48 = F_22 ;
if ( V_12 -> V_58 )
V_73 -> V_3 . V_58 = F_25 ;
if ( V_12 -> V_59 )
V_73 -> V_3 . V_59 = F_26 ;
if ( V_12 -> V_60 )
V_73 -> V_3 . V_60 = F_27 ;
if ( V_12 -> V_64 )
V_73 -> V_3 . V_64 = F_31 ;
if ( V_12 -> V_65 )
V_73 -> V_3 . V_65 = F_32 ;
if ( V_12 -> V_66 )
V_73 -> V_3 . V_66 = F_33 ;
V_73 -> V_3 . V_53 = F_23 ;
V_73 -> V_12 = V_12 ;
V_73 -> V_15 = V_8 -> V_15 ;
if ( V_73 -> V_15 == V_95 )
V_73 -> V_15 = V_80 ;
if ( V_73 -> V_15 == V_96 ) {
V_73 -> V_15 = V_80 ;
if ( F_52 ( V_80 , V_12 ) != 0 ) {
V_73 -> V_15 = ( F_53 ( V_80 , V_12 ) + 1 ) * V_12 -> V_97 ;
F_49 ( V_98 L_2
L_3 , V_79 ,
( unsigned long long ) V_80 , ( unsigned long long ) V_73 -> V_15 ) ;
}
}
if ( V_73 -> V_15 == V_99 ) {
V_73 -> V_15 = V_80 ;
if ( V_12 -> V_26 - V_73 -> V_15 >= V_73 -> V_3 . V_26 ) {
V_73 -> V_3 . V_26 = V_12 -> V_26 - V_73 -> V_15
- V_73 -> V_3 . V_26 ;
} else {
F_49 ( V_82 L_4 ,
V_8 -> V_72 , V_12 -> V_26 - V_73 -> V_15 ,
V_73 -> V_3 . V_26 ) ;
goto V_100;
}
}
if ( V_73 -> V_3 . V_26 == V_101 )
V_73 -> V_3 . V_26 = V_12 -> V_26 - V_73 -> V_15 ;
F_49 ( V_98 L_5 , ( unsigned long long ) V_73 -> V_15 ,
( unsigned long long ) ( V_73 -> V_15 + V_73 -> V_3 . V_26 ) , V_73 -> V_3 . V_72 ) ;
if ( V_73 -> V_15 >= V_12 -> V_26 ) {
V_73 -> V_15 = 0 ;
V_73 -> V_3 . V_26 = 0 ;
F_49 ( V_82 L_6 ,
V_8 -> V_72 ) ;
goto V_100;
}
if ( V_73 -> V_15 + V_73 -> V_3 . V_26 > V_12 -> V_26 ) {
V_73 -> V_3 . V_26 = V_12 -> V_26 - V_73 -> V_15 ;
F_49 ( V_102 L_7 ,
V_8 -> V_72 , V_12 -> V_72 , ( unsigned long long ) V_73 -> V_3 . V_26 ) ;
}
if ( V_12 -> V_103 > 1 ) {
int V_104 , V_105 = V_12 -> V_103 ;
T_6 V_106 = V_73 -> V_15 + V_73 -> V_3 . V_26 ;
struct V_107 * V_108 = V_12 -> V_109 ;
for ( V_104 = 0 ; V_104 < V_105 && V_108 [ V_104 ] . V_15 <= V_73 -> V_15 ; V_104 ++ )
;
if ( V_104 > 0 )
V_104 -- ;
for (; V_104 < V_105 && V_108 [ V_104 ] . V_15 < V_106 ; V_104 ++ ) {
if ( V_73 -> V_3 . V_97 < V_108 [ V_104 ] . V_97 ) {
V_73 -> V_3 . V_97 = V_108 [ V_104 ] . V_97 ;
}
}
F_54 ( V_73 -> V_3 . V_97 == 0 ) ;
} else {
V_73 -> V_3 . V_97 = V_12 -> V_97 ;
}
if ( ( V_73 -> V_3 . V_22 & V_110 ) &&
F_52 ( V_73 -> V_15 , & V_73 -> V_3 ) ) {
V_73 -> V_3 . V_22 &= ~ V_110 ;
F_49 ( V_102 L_8 ,
V_8 -> V_72 ) ;
}
if ( ( V_73 -> V_3 . V_22 & V_110 ) &&
F_52 ( V_73 -> V_3 . V_26 , & V_73 -> V_3 ) ) {
V_73 -> V_3 . V_22 &= ~ V_110 ;
F_49 ( V_102 L_9 ,
V_8 -> V_72 ) ;
}
F_55 ( & V_73 -> V_3 , & V_111 ) ;
V_73 -> V_3 . V_112 = V_12 -> V_112 ;
V_73 -> V_3 . V_113 = V_12 -> V_113 ;
V_73 -> V_3 . V_114 = V_12 -> V_114 ;
if ( V_12 -> V_65 ) {
T_5 V_115 = 0 ;
while ( V_115 < V_73 -> V_3 . V_26 ) {
if ( F_56 ( V_12 , V_115 + V_73 -> V_15 ) )
V_73 -> V_3 . V_13 . V_116 ++ ;
else if ( F_57 ( V_12 , V_115 + V_73 -> V_15 ) )
V_73 -> V_3 . V_13 . V_67 ++ ;
V_115 += V_73 -> V_3 . V_97 ;
}
}
V_100:
return V_73 ;
}
static T_7 F_58 ( struct V_117 * V_91 ,
struct V_118 * V_119 , char * V_7 )
{
struct V_2 * V_3 = F_59 ( V_91 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
return snprintf ( V_7 , V_120 , L_10 , V_8 -> V_15 ) ;
}
static int F_60 ( struct V_1 * V_121 )
{
int V_51 = F_61 ( & V_121 -> V_3 . V_91 . V_122 , V_123 ) ;
if ( V_51 )
F_49 ( V_102
L_11 , V_51 ) ;
return V_51 ;
}
int F_62 ( struct V_2 * V_12 , const char * V_72 ,
long long V_15 , long long V_124 )
{
struct V_78 V_8 ;
struct V_1 * V_121 ;
int V_51 = 0 ;
if ( V_15 == V_95 ||
V_15 == V_96 )
return - V_27 ;
if ( V_124 == V_101 )
V_124 = V_12 -> V_26 - V_15 ;
if ( V_124 <= 0 )
return - V_27 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_72 = V_72 ;
V_8 . V_26 = V_124 ;
V_8 . V_15 = V_15 ;
V_121 = F_46 ( V_12 , & V_8 , - 1 , V_15 ) ;
if ( F_63 ( V_121 ) )
return F_64 ( V_121 ) ;
F_41 ( & V_76 ) ;
F_65 ( & V_121 -> V_77 , & V_125 ) ;
F_45 ( & V_76 ) ;
F_66 ( & V_121 -> V_3 ) ;
F_60 ( V_121 ) ;
return V_51 ;
}
int F_67 ( struct V_2 * V_12 , int V_79 )
{
struct V_1 * V_73 , * V_74 ;
int V_51 = - V_27 ;
F_41 ( & V_76 ) ;
F_42 (slave, next, &mtd_partitions, list)
if ( ( V_73 -> V_12 == V_12 ) &&
( V_73 -> V_3 . V_126 == V_79 ) ) {
F_68 ( & V_73 -> V_3 . V_91 . V_122 ,
V_123 ) ;
V_51 = F_43 ( & V_73 -> V_3 ) ;
if ( V_51 < 0 )
break;
F_44 ( & V_73 -> V_77 ) ;
F_38 ( V_73 ) ;
break;
}
F_45 ( & V_76 ) ;
return V_51 ;
}
int F_69 ( struct V_2 * V_12 ,
const struct V_78 * V_127 ,
int V_128 )
{
struct V_1 * V_73 ;
T_5 V_80 = 0 ;
int V_104 ;
F_49 ( V_98 L_12 , V_128 , V_12 -> V_72 ) ;
for ( V_104 = 0 ; V_104 < V_128 ; V_104 ++ ) {
V_73 = F_46 ( V_12 , V_127 + V_104 , V_104 , V_80 ) ;
if ( F_63 ( V_73 ) ) {
F_40 ( V_12 ) ;
return F_64 ( V_73 ) ;
}
F_41 ( & V_76 ) ;
F_65 ( & V_73 -> V_77 , & V_125 ) ;
F_45 ( & V_76 ) ;
F_66 ( & V_73 -> V_3 ) ;
F_60 ( V_73 ) ;
V_80 = V_73 -> V_15 + V_73 -> V_3 . V_26 ;
}
return 0 ;
}
static struct V_129 * F_70 ( const char * V_72 )
{
struct V_129 * V_71 , * V_51 = NULL ;
F_71 ( & V_130 ) ;
F_72 (p, &part_parsers, list)
if ( ! strcmp ( V_71 -> V_72 , V_72 ) && F_73 ( V_71 -> V_90 ) ) {
V_51 = V_71 ;
break;
}
F_74 ( & V_130 ) ;
return V_51 ;
}
static inline void F_75 ( const struct V_129 * V_71 )
{
F_76 ( V_71 -> V_90 ) ;
}
static void F_77 ( const struct V_78 * V_131 ,
int V_132 )
{
F_39 ( V_131 ) ;
}
int F_78 ( struct V_129 * V_71 , struct V_133 * V_90 )
{
V_71 -> V_90 = V_90 ;
if ( ! V_71 -> V_134 )
V_71 -> V_134 = & F_77 ;
F_71 ( & V_130 ) ;
F_65 ( & V_71 -> V_77 , & V_135 ) ;
F_74 ( & V_130 ) ;
return 0 ;
}
void F_79 ( struct V_129 * V_71 )
{
F_71 ( & V_130 ) ;
F_44 ( & V_71 -> V_77 ) ;
F_74 ( & V_130 ) ;
}
int F_80 ( struct V_2 * V_12 , const char * const * V_136 ,
struct V_125 * V_131 ,
struct V_137 * V_138 )
{
struct V_129 * V_139 ;
int V_51 , V_75 = 0 ;
if ( ! V_136 )
V_136 = V_140 ;
for ( ; * V_136 ; V_136 ++ ) {
F_81 ( L_13 , V_12 -> V_72 , * V_136 ) ;
V_139 = F_70 ( * V_136 ) ;
if ( ! V_139 && ! F_82 ( L_14 , * V_136 ) )
V_139 = F_70 ( * V_136 ) ;
F_81 ( L_15 , V_12 -> V_72 ,
V_139 ? V_139 -> V_72 : NULL ) ;
if ( ! V_139 )
continue;
V_51 = (* V_139 -> V_141 )( V_12 , & V_131 -> V_127 , V_138 ) ;
F_81 ( L_16 ,
V_12 -> V_72 , V_139 -> V_72 , V_51 ) ;
if ( V_51 > 0 ) {
F_49 ( V_98 L_17 ,
V_51 , V_139 -> V_72 , V_12 -> V_72 ) ;
V_131 -> V_132 = V_51 ;
V_131 -> V_139 = V_139 ;
return 0 ;
}
F_75 ( V_139 ) ;
if ( V_51 < 0 && ! V_75 )
V_75 = V_51 ;
}
return V_75 ;
}
void F_83 ( struct V_125 * V_127 )
{
const struct V_129 * V_139 ;
if ( ! V_127 )
return;
V_139 = V_127 -> V_139 ;
if ( V_139 ) {
if ( V_139 -> V_134 )
V_139 -> V_134 ( V_127 -> V_127 , V_127 -> V_132 ) ;
F_75 ( V_139 ) ;
}
}
int F_84 ( const struct V_2 * V_3 )
{
struct V_1 * V_8 ;
int V_142 = 0 ;
F_41 ( & V_76 ) ;
F_72 (part, &mtd_partitions, list)
if ( & V_8 -> V_3 == V_3 ) {
V_142 = 1 ;
break;
}
F_45 ( & V_76 ) ;
return V_142 ;
}
T_5 F_85 ( const struct V_2 * V_3 )
{
if ( ! F_84 ( V_3 ) )
return V_3 -> V_26 ;
return F_1 ( V_3 ) -> V_12 -> V_26 ;
}
