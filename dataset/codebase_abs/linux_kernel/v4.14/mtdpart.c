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
static int F_43 ( struct V_1 * V_76 , const char * const * V_77 )
{
struct V_78 V_79 ;
int V_80 ;
V_80 = F_44 ( & V_76 -> V_3 , V_77 , & V_79 , NULL ) ;
if ( V_80 )
return V_80 ;
else if ( ! V_79 . V_81 )
return - V_82 ;
V_80 = F_45 ( & V_76 -> V_3 , V_79 . V_83 , V_79 . V_81 ) ;
F_46 ( & V_79 ) ;
return V_80 ;
}
static struct V_1 * F_47 ( struct V_2 * V_12 ,
const struct V_84 * V_8 , int V_85 ,
T_5 V_86 )
{
int V_87 = ( V_12 -> V_22 & V_88 ) ? V_12 -> V_89 :
V_12 -> V_90 ;
struct V_1 * V_76 ;
T_6 V_91 ;
char * V_75 ;
T_7 V_92 ;
V_76 = F_48 ( sizeof( * V_76 ) , V_93 ) ;
V_75 = F_49 ( V_8 -> V_75 , V_93 ) ;
if ( ! V_75 || ! V_76 ) {
F_50 ( V_94 L_1 ,
V_12 -> V_75 ) ;
F_42 ( V_75 ) ;
F_42 ( V_76 ) ;
return F_51 ( - V_95 ) ;
}
V_76 -> V_3 . type = V_12 -> type ;
V_76 -> V_3 . V_22 = V_12 -> V_22 & ~ V_8 -> V_96 ;
V_76 -> V_3 . V_26 = V_8 -> V_26 ;
V_76 -> V_3 . V_89 = V_12 -> V_89 ;
V_76 -> V_3 . V_97 = V_12 -> V_97 ;
V_76 -> V_3 . V_98 = V_12 -> V_98 ;
V_76 -> V_3 . V_99 = V_12 -> V_99 ;
V_76 -> V_3 . V_100 = V_12 -> V_100 ;
V_76 -> V_3 . V_101 = V_12 -> V_101 ;
V_76 -> V_3 . V_75 = V_75 ;
V_76 -> V_3 . V_102 = V_12 -> V_102 ;
V_76 -> V_3 . V_103 . V_12 = F_52 ( V_104 ) || F_53 ( V_12 ) ?
& V_12 -> V_103 :
V_12 -> V_103 . V_12 ;
V_76 -> V_3 . V_103 . V_105 = V_8 -> V_105 ;
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
if ( ! V_85 && ! V_12 -> V_103 . V_106 && V_12 -> V_62 &&
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
if ( V_76 -> V_15 == V_107 )
V_76 -> V_15 = V_86 ;
if ( V_76 -> V_15 == V_108 ) {
V_92 = V_86 ;
V_76 -> V_15 = V_86 ;
V_91 = F_54 ( V_92 , V_87 ) ;
if ( V_91 ) {
V_76 -> V_15 += V_87 - V_91 ;
F_50 ( V_109 L_2
L_3 , V_85 ,
( unsigned long long ) V_86 , ( unsigned long long ) V_76 -> V_15 ) ;
}
}
if ( V_76 -> V_15 == V_110 ) {
V_76 -> V_15 = V_86 ;
if ( V_12 -> V_26 - V_76 -> V_15 >= V_76 -> V_3 . V_26 ) {
V_76 -> V_3 . V_26 = V_12 -> V_26 - V_76 -> V_15
- V_76 -> V_3 . V_26 ;
} else {
F_50 ( V_94 L_4 ,
V_8 -> V_75 , V_12 -> V_26 - V_76 -> V_15 ,
V_76 -> V_3 . V_26 ) ;
goto V_111;
}
}
if ( V_76 -> V_3 . V_26 == V_112 )
V_76 -> V_3 . V_26 = V_12 -> V_26 - V_76 -> V_15 ;
F_50 ( V_109 L_5 , ( unsigned long long ) V_76 -> V_15 ,
( unsigned long long ) ( V_76 -> V_15 + V_76 -> V_3 . V_26 ) , V_76 -> V_3 . V_75 ) ;
if ( V_76 -> V_15 >= V_12 -> V_26 ) {
V_76 -> V_15 = 0 ;
V_76 -> V_3 . V_26 = 0 ;
F_50 ( V_94 L_6 ,
V_8 -> V_75 ) ;
goto V_111;
}
if ( V_76 -> V_15 + V_76 -> V_3 . V_26 > V_12 -> V_26 ) {
V_76 -> V_3 . V_26 = V_12 -> V_26 - V_76 -> V_15 ;
F_50 ( V_113 L_7 ,
V_8 -> V_75 , V_12 -> V_75 , ( unsigned long long ) V_76 -> V_3 . V_26 ) ;
}
if ( V_12 -> V_114 > 1 ) {
int V_115 , V_116 = V_12 -> V_114 ;
T_7 V_117 = V_76 -> V_15 + V_76 -> V_3 . V_26 ;
struct V_118 * V_119 = V_12 -> V_120 ;
for ( V_115 = 0 ; V_115 < V_116 && V_119 [ V_115 ] . V_15 <= V_76 -> V_15 ; V_115 ++ )
;
if ( V_115 > 0 )
V_115 -- ;
for (; V_115 < V_116 && V_119 [ V_115 ] . V_15 < V_117 ; V_115 ++ ) {
if ( V_76 -> V_3 . V_90 < V_119 [ V_115 ] . V_90 ) {
V_76 -> V_3 . V_90 = V_119 [ V_115 ] . V_90 ;
}
}
F_55 ( V_76 -> V_3 . V_90 == 0 ) ;
} else {
V_76 -> V_3 . V_90 = V_12 -> V_90 ;
}
if ( ! ( V_76 -> V_3 . V_22 & V_88 ) )
V_87 = V_76 -> V_3 . V_90 ;
V_92 = V_76 -> V_15 ;
V_91 = F_54 ( V_92 , V_87 ) ;
if ( ( V_76 -> V_3 . V_22 & V_121 ) && V_91 ) {
V_76 -> V_3 . V_22 &= ~ V_121 ;
F_50 ( V_113 L_8 ,
V_8 -> V_75 ) ;
}
V_92 = V_76 -> V_3 . V_26 ;
V_91 = F_54 ( V_92 , V_87 ) ;
if ( ( V_76 -> V_3 . V_22 & V_121 ) && V_91 ) {
V_76 -> V_3 . V_22 &= ~ V_121 ;
F_50 ( V_113 L_9 ,
V_8 -> V_75 ) ;
}
F_56 ( & V_76 -> V_3 , & V_122 ) ;
V_76 -> V_3 . V_123 = V_12 -> V_123 ;
V_76 -> V_3 . V_124 = V_12 -> V_124 ;
V_76 -> V_3 . V_125 = V_12 -> V_125 ;
if ( V_12 -> V_65 ) {
T_5 V_126 = 0 ;
while ( V_126 < V_76 -> V_3 . V_26 ) {
if ( F_57 ( V_12 , V_126 + V_76 -> V_15 ) )
V_76 -> V_3 . V_13 . V_127 ++ ;
else if ( F_58 ( V_12 , V_126 + V_76 -> V_15 ) )
V_76 -> V_3 . V_13 . V_67 ++ ;
V_126 += V_76 -> V_3 . V_90 ;
}
}
V_111:
return V_76 ;
}
static T_8 F_59 ( struct V_128 * V_103 ,
struct V_129 * V_130 , char * V_7 )
{
struct V_2 * V_3 = F_60 ( V_103 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
return snprintf ( V_7 , V_131 , L_10 , V_8 -> V_15 ) ;
}
static int F_61 ( struct V_1 * V_132 )
{
int V_51 = F_62 ( & V_132 -> V_3 . V_103 . V_133 , V_134 ) ;
if ( V_51 )
F_50 ( V_113
L_11 , V_51 ) ;
return V_51 ;
}
int F_63 ( struct V_2 * V_12 , const char * V_75 ,
long long V_15 , long long V_135 )
{
struct V_84 V_8 ;
struct V_1 * V_132 ;
int V_51 = 0 ;
if ( V_15 == V_107 ||
V_15 == V_108 )
return - V_27 ;
if ( V_135 == V_112 )
V_135 = V_12 -> V_26 - V_15 ;
if ( V_135 <= 0 )
return - V_27 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_75 = V_75 ;
V_8 . V_26 = V_135 ;
V_8 . V_15 = V_15 ;
V_132 = F_47 ( V_12 , & V_8 , - 1 , V_15 ) ;
if ( F_64 ( V_132 ) )
return F_65 ( V_132 ) ;
F_66 ( & V_136 ) ;
F_67 ( & V_132 -> V_137 , & V_78 ) ;
F_68 ( & V_136 ) ;
F_69 ( & V_132 -> V_3 ) ;
F_61 ( V_132 ) ;
return V_51 ;
}
static int F_70 ( struct V_1 * V_138 )
{
struct V_1 * V_139 , * V_140 ;
int V_80 ;
F_71 (child, next, &mtd_partitions, list) {
if ( V_139 -> V_12 == & V_138 -> V_3 ) {
V_80 = F_70 ( V_139 ) ;
if ( V_80 )
return V_80 ;
}
}
F_72 ( & V_138 -> V_3 . V_103 . V_133 , V_134 ) ;
V_80 = F_73 ( & V_138 -> V_3 ) ;
if ( V_80 )
return V_80 ;
F_74 ( & V_138 -> V_137 ) ;
F_41 ( V_138 ) ;
return 0 ;
}
int F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_76 , * V_140 ;
int V_51 , V_80 = 0 ;
F_66 ( & V_136 ) ;
F_71 (slave, next, &mtd_partitions, list)
if ( V_76 -> V_12 == V_3 ) {
V_51 = F_70 ( V_76 ) ;
if ( V_51 < 0 )
V_80 = V_51 ;
}
F_68 ( & V_136 ) ;
return V_80 ;
}
int F_76 ( struct V_2 * V_3 , int V_85 )
{
struct V_1 * V_76 , * V_140 ;
int V_51 = - V_27 ;
F_66 ( & V_136 ) ;
F_71 (slave, next, &mtd_partitions, list)
if ( ( V_76 -> V_12 == V_3 ) &&
( V_76 -> V_3 . V_141 == V_85 ) ) {
V_51 = F_70 ( V_76 ) ;
break;
}
F_68 ( & V_136 ) ;
return V_51 ;
}
int F_45 ( struct V_2 * V_142 ,
const struct V_84 * V_83 ,
int V_143 )
{
struct V_1 * V_76 ;
T_5 V_86 = 0 ;
int V_115 ;
F_50 ( V_109 L_12 , V_143 , V_142 -> V_75 ) ;
for ( V_115 = 0 ; V_115 < V_143 ; V_115 ++ ) {
V_76 = F_47 ( V_142 , V_83 + V_115 , V_115 , V_86 ) ;
if ( F_64 ( V_76 ) ) {
F_75 ( V_142 ) ;
return F_65 ( V_76 ) ;
}
F_66 ( & V_136 ) ;
F_67 ( & V_76 -> V_137 , & V_78 ) ;
F_68 ( & V_136 ) ;
F_69 ( & V_76 -> V_3 ) ;
F_61 ( V_76 ) ;
if ( V_83 [ V_115 ] . V_77 )
F_43 ( V_76 , V_83 [ V_115 ] . V_77 ) ;
V_86 = V_76 -> V_15 + V_76 -> V_3 . V_26 ;
}
return 0 ;
}
static struct V_144 * F_77 ( const char * V_75 )
{
struct V_144 * V_74 , * V_51 = NULL ;
F_78 ( & V_145 ) ;
F_79 (p, &part_parsers, list)
if ( ! strcmp ( V_74 -> V_75 , V_75 ) && F_80 ( V_74 -> V_102 ) ) {
V_51 = V_74 ;
break;
}
F_81 ( & V_145 ) ;
return V_51 ;
}
static inline void F_82 ( const struct V_144 * V_74 )
{
F_83 ( V_74 -> V_102 ) ;
}
static void F_84 ( const struct V_84 * V_146 ,
int V_81 )
{
F_42 ( V_146 ) ;
}
int F_85 ( struct V_144 * V_74 , struct V_147 * V_102 )
{
V_74 -> V_102 = V_102 ;
if ( ! V_74 -> V_148 )
V_74 -> V_148 = & F_84 ;
F_78 ( & V_145 ) ;
F_67 ( & V_74 -> V_137 , & V_149 ) ;
F_81 ( & V_145 ) ;
return 0 ;
}
void F_86 ( struct V_144 * V_74 )
{
F_78 ( & V_145 ) ;
F_74 ( & V_74 -> V_137 ) ;
F_81 ( & V_145 ) ;
}
static int F_87 ( struct V_144 * V_150 ,
struct V_2 * V_142 ,
struct V_78 * V_146 ,
struct V_151 * V_152 )
{
int V_51 ;
V_51 = (* V_150 -> V_153 )( V_142 , & V_146 -> V_83 , V_152 ) ;
F_88 ( L_13 , V_142 -> V_75 , V_150 -> V_75 , V_51 ) ;
if ( V_51 <= 0 )
return V_51 ;
F_89 ( L_14 , V_51 ,
V_150 -> V_75 , V_142 -> V_75 ) ;
V_146 -> V_81 = V_51 ;
V_146 -> V_150 = V_150 ;
return V_51 ;
}
int F_44 ( struct V_2 * V_142 , const char * const * V_77 ,
struct V_78 * V_146 ,
struct V_151 * V_152 )
{
struct V_144 * V_150 ;
int V_51 , V_80 = 0 ;
if ( ! V_77 )
V_77 = V_154 ;
for ( ; * V_77 ; V_77 ++ ) {
F_88 ( L_15 , V_142 -> V_75 , * V_77 ) ;
V_150 = F_77 ( * V_77 ) ;
if ( ! V_150 && ! F_90 ( L_16 , * V_77 ) )
V_150 = F_77 ( * V_77 ) ;
F_88 ( L_17 , V_142 -> V_75 ,
V_150 ? V_150 -> V_75 : NULL ) ;
if ( ! V_150 )
continue;
V_51 = F_87 ( V_150 , V_142 , V_146 , V_152 ) ;
if ( V_51 > 0 )
return 0 ;
F_82 ( V_150 ) ;
if ( V_51 < 0 && ! V_80 )
V_80 = V_51 ;
}
return V_80 ;
}
void F_46 ( struct V_78 * V_83 )
{
const struct V_144 * V_150 ;
if ( ! V_83 )
return;
V_150 = V_83 -> V_150 ;
if ( V_150 ) {
if ( V_150 -> V_148 )
V_150 -> V_148 ( V_83 -> V_83 , V_83 -> V_81 ) ;
F_82 ( V_150 ) ;
}
}
int F_53 ( const struct V_2 * V_3 )
{
struct V_1 * V_8 ;
int V_155 = 0 ;
F_66 ( & V_136 ) ;
F_79 (part, &mtd_partitions, list)
if ( & V_8 -> V_3 == V_3 ) {
V_155 = 1 ;
break;
}
F_68 ( & V_136 ) ;
return V_155 ;
}
T_5 F_91 ( const struct V_2 * V_3 )
{
if ( ! F_53 ( V_3 ) )
return V_3 -> V_26 ;
return F_91 ( F_1 ( V_3 ) -> V_12 ) ;
}
