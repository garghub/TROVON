static inline unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 ;
}
static inline int F_2 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 ;
int V_7 ;
V_7 = F_3 ( V_2 -> V_8 - V_2 -> V_9 , V_10 ) ;
V_6 = F_4 (
V_2 -> V_11 ,
V_7 ,
V_5 -> V_12 == V_13 ,
& V_5 -> V_14 [ 0 ] ) ;
if ( V_6 < 0 && V_2 -> V_15 && ( V_5 -> V_12 & V_16 ) ) {
struct V_17 * V_17 = F_5 ( 0 ) ;
if ( V_5 -> V_18 == 0 )
V_5 -> V_18 = V_6 ;
F_6 ( V_17 ) ;
V_5 -> V_14 [ 0 ] = V_17 ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = 1 ;
V_6 = 0 ;
goto V_19;
}
if ( V_6 >= 0 ) {
V_2 -> V_11 += V_6 * V_20 ;
V_2 -> V_9 += V_6 ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = V_6 ;
V_6 = 0 ;
}
V_19:
return V_6 ;
}
static inline struct V_17 * F_7 ( struct V_5 * V_5 ,
struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) == 0 ) {
int V_6 ;
V_6 = F_2 ( V_5 , V_2 ) ;
if ( V_6 )
return F_8 ( V_6 ) ;
F_9 ( F_1 ( V_2 ) == 0 ) ;
}
return V_5 -> V_14 [ V_2 -> V_4 ++ ] ;
}
static T_1 F_10 ( struct V_5 * V_5 , T_2 V_21 , T_1 V_6 ,
bool V_22 )
{
T_1 V_23 = 0 ;
if ( V_6 == - V_24 )
V_6 = 0 ;
if ( V_5 -> V_25 ) {
V_23 = V_5 -> V_25 ;
if ( ( V_5 -> V_12 == V_13 ) && ( ( V_21 + V_23 ) > V_5 -> V_26 ) )
V_23 = V_5 -> V_26 - V_21 ;
}
if ( V_6 == 0 )
V_6 = V_5 -> V_18 ;
if ( V_6 == 0 )
V_6 = V_5 -> V_27 ;
if ( V_6 == 0 )
V_6 = V_23 ;
if ( V_5 -> V_28 && V_5 -> V_25 )
V_5 -> V_28 ( V_5 -> V_29 , V_21 , V_23 , V_5 -> V_30 ) ;
F_11 ( V_5 -> V_31 ) ;
if ( V_22 ) {
if ( V_5 -> V_12 & V_16 ) {
int V_32 ;
V_32 = F_12 ( V_5 -> V_29 -> V_33 , V_21 ,
V_23 ) ;
if ( V_32 < 0 && V_6 > 0 )
V_6 = V_32 ;
}
F_13 ( V_5 -> V_29 , V_6 , 0 ) ;
}
F_14 ( V_34 , V_5 ) ;
return V_6 ;
}
static void F_15 ( struct V_35 * V_36 )
{
struct V_5 * V_5 = F_16 ( V_36 , struct V_5 , V_37 ) ;
F_10 ( V_5 , V_5 -> V_29 -> V_38 , 0 , true ) ;
}
static void F_17 ( struct V_39 * V_39 , int error )
{
struct V_5 * V_5 = V_39 -> V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
F_18 ( V_5 , V_39 ) ;
F_19 ( & V_5 -> V_43 , V_42 ) ;
V_41 = -- V_5 -> V_44 ;
if ( V_41 == 1 && V_5 -> V_45 )
F_20 ( V_5 -> V_45 ) ;
F_21 ( & V_5 -> V_43 , V_42 ) ;
if ( V_41 == 0 ) {
if ( V_5 -> V_25 && V_5 -> V_46 ) {
F_22 ( & V_5 -> V_37 , F_15 ) ;
F_23 ( V_5 -> V_31 -> V_47 -> V_48 ,
& V_5 -> V_37 ) ;
} else {
F_10 ( V_5 , V_5 -> V_29 -> V_38 , 0 , true ) ;
}
}
}
static void F_24 ( struct V_39 * V_39 , int error )
{
struct V_5 * V_5 = V_39 -> V_40 ;
unsigned long V_42 ;
F_19 ( & V_5 -> V_43 , V_42 ) ;
V_39 -> V_40 = V_5 -> V_49 ;
V_5 -> V_49 = V_39 ;
if ( -- V_5 -> V_44 == 1 && V_5 -> V_45 )
F_20 ( V_5 -> V_45 ) ;
F_21 ( & V_5 -> V_43 , V_42 ) ;
}
void F_25 ( struct V_39 * V_39 , int error )
{
struct V_5 * V_5 = V_39 -> V_40 ;
if ( V_5 -> V_22 )
F_17 ( V_39 , error ) ;
else
F_24 ( V_39 , error ) ;
}
static inline void
F_26 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_50 * V_51 ,
T_3 V_52 , int V_53 )
{
struct V_39 * V_39 ;
V_39 = F_27 ( V_54 , V_53 ) ;
V_39 -> V_55 = V_51 ;
V_39 -> V_56 . V_57 = V_52 ;
if ( V_5 -> V_22 )
V_39 -> V_58 = F_17 ;
else
V_39 -> V_58 = F_24 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_59 = V_2 -> V_60 ;
}
static inline void F_28 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
struct V_39 * V_39 = V_2 -> V_39 ;
unsigned long V_42 ;
V_39 -> V_40 = V_5 ;
F_19 ( & V_5 -> V_43 , V_42 ) ;
V_5 -> V_44 ++ ;
F_21 ( & V_5 -> V_43 , V_42 ) ;
if ( V_5 -> V_22 && V_5 -> V_12 == V_13 )
F_29 ( V_39 ) ;
if ( V_2 -> V_61 )
V_2 -> V_61 ( V_5 -> V_12 , V_39 , V_5 -> V_31 ,
V_2 -> V_59 ) ;
else
F_30 ( V_5 -> V_12 , V_39 ) ;
V_2 -> V_39 = NULL ;
V_2 -> V_62 = 0 ;
V_2 -> V_59 = 0 ;
}
static inline void F_31 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
while ( F_1 ( V_2 ) )
F_32 ( F_7 ( V_5 , V_2 ) ) ;
}
static struct V_39 * F_33 ( struct V_5 * V_5 )
{
unsigned long V_42 ;
struct V_39 * V_39 = NULL ;
F_19 ( & V_5 -> V_43 , V_42 ) ;
while ( V_5 -> V_44 > 1 && V_5 -> V_49 == NULL ) {
F_34 ( V_63 ) ;
V_5 -> V_45 = V_64 ;
F_21 ( & V_5 -> V_43 , V_42 ) ;
F_35 () ;
F_19 ( & V_5 -> V_43 , V_42 ) ;
V_5 -> V_45 = NULL ;
}
if ( V_5 -> V_49 ) {
V_39 = V_5 -> V_49 ;
V_5 -> V_49 = V_39 -> V_40 ;
}
F_21 ( & V_5 -> V_43 , V_42 ) ;
return V_39 ;
}
static int F_18 ( struct V_5 * V_5 , struct V_39 * V_39 )
{
const int V_65 = F_36 ( V_66 , & V_39 -> V_67 ) ;
struct V_68 * V_69 ;
unsigned V_70 ;
if ( ! V_65 )
V_5 -> V_27 = - V_71 ;
if ( V_5 -> V_22 && V_5 -> V_12 == V_13 ) {
F_37 ( V_39 ) ;
} else {
F_38 (bvec, bio, i) {
struct V_17 * V_17 = V_69 -> V_72 ;
if ( V_5 -> V_12 == V_13 && ! F_39 ( V_17 ) )
F_40 ( V_17 ) ;
F_32 ( V_17 ) ;
}
F_41 ( V_39 ) ;
}
return V_65 ? 0 : - V_71 ;
}
static void F_42 ( struct V_5 * V_5 )
{
struct V_39 * V_39 ;
do {
V_39 = F_33 ( V_5 ) ;
if ( V_39 )
F_18 ( V_5 , V_39 ) ;
} while ( V_39 );
}
static inline int F_43 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_73 ++ >= 64 ) {
while ( V_5 -> V_49 ) {
unsigned long V_42 ;
struct V_39 * V_39 ;
int V_74 ;
F_19 ( & V_5 -> V_43 , V_42 ) ;
V_39 = V_5 -> V_49 ;
V_5 -> V_49 = V_39 -> V_40 ;
F_21 ( & V_5 -> V_43 , V_42 ) ;
V_74 = F_18 ( V_5 , V_39 ) ;
if ( V_6 == 0 )
V_6 = V_74 ;
}
V_2 -> V_73 = 0 ;
}
return V_6 ;
}
static int F_44 ( struct V_75 * V_76 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 = F_45 ( L_1 ,
V_80 , 0 ,
V_76 -> V_81 ) ;
if ( ! V_79 )
return - V_82 ;
V_78 = F_46 ( & V_76 -> V_48 , NULL , V_79 ) ;
if ( V_78 )
F_47 ( V_79 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_5 )
{
struct V_75 * V_76 = V_5 -> V_31 -> V_47 ;
if ( V_5 -> V_46 )
return 0 ;
V_5 -> V_46 = true ;
if ( ! V_76 -> V_48 )
return F_44 ( V_76 ) ;
return 0 ;
}
static int F_49 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_83 * V_84 )
{
int V_6 ;
T_3 V_85 ;
T_3 V_86 ;
unsigned long V_87 ;
int V_88 ;
unsigned int V_89 = V_2 -> V_90 + V_2 -> V_91 ;
V_6 = V_5 -> V_18 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_92 >= V_2 -> V_93 ) ;
V_85 = V_2 -> V_92 >> V_2 -> V_91 ;
V_86 = ( V_2 -> V_93 - 1 ) >>
V_2 -> V_91 ;
V_87 = V_86 - V_85 + 1 ;
V_84 -> V_94 = 0 ;
V_84 -> V_95 = V_87 << V_89 ;
V_88 = V_5 -> V_12 & V_16 ;
if ( V_5 -> V_42 & V_96 ) {
if ( V_2 -> V_92 < ( F_50 ( V_5 -> V_31 ) >>
V_2 -> V_90 ) )
V_88 = 0 ;
}
V_6 = (* V_2 -> V_97 )( V_5 -> V_31 , V_85 ,
V_84 , V_88 ) ;
V_5 -> V_30 = V_84 -> V_98 ;
if ( V_6 == 0 && F_51 ( V_84 ) )
V_6 = F_48 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_52 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_99 , struct V_83 * V_84 )
{
T_3 V_100 ;
int V_6 , V_7 ;
V_6 = F_43 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_19;
V_100 = V_99 << ( V_2 -> V_90 - 9 ) ;
V_7 = F_3 ( V_2 -> V_101 , F_53 ( V_84 -> V_102 ) ) ;
V_7 = F_3 ( V_7 , V_103 ) ;
F_9 ( V_7 <= 0 ) ;
F_26 ( V_5 , V_2 , V_84 -> V_102 , V_100 , V_7 ) ;
V_2 -> V_62 = 0 ;
V_19:
return V_6 ;
}
static inline int F_54 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_55 ( V_2 -> V_39 , V_2 -> V_104 ,
V_2 -> V_105 , V_2 -> V_106 ) ;
if ( V_6 == V_2 -> V_105 ) {
if ( ( V_2 -> V_105 + V_2 -> V_106 ) == V_20 )
V_2 -> V_101 -- ;
F_6 ( V_2 -> V_104 ) ;
V_2 -> V_107 = V_2 -> V_108 +
( V_2 -> V_105 >> V_2 -> V_90 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_56 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_83 * V_84 )
{
int V_6 = 0 ;
if ( V_2 -> V_39 ) {
T_2 V_109 = V_2 -> V_60 ;
T_2 V_110 = V_2 -> V_59 +
V_2 -> V_39 -> V_56 . V_111 ;
if ( V_2 -> V_107 != V_2 -> V_108 ||
V_109 != V_110 )
F_28 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_39 == NULL ) {
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_108 , V_84 ) ;
if ( V_6 )
goto V_19;
}
if ( F_54 ( V_2 ) != 0 ) {
F_28 ( V_5 , V_2 ) ;
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_108 , V_84 ) ;
if ( V_6 == 0 ) {
V_6 = F_54 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_19:
return V_6 ;
}
static inline int
F_57 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_17 * V_17 ,
unsigned V_21 , unsigned V_112 , T_3 V_113 ,
struct V_83 * V_84 )
{
int V_6 = 0 ;
if ( V_5 -> V_12 & V_16 ) {
F_58 ( V_112 ) ;
}
if ( V_2 -> V_104 == V_17 &&
V_2 -> V_106 + V_2 -> V_105 == V_21 &&
V_2 -> V_108 +
( V_2 -> V_105 >> V_2 -> V_90 ) == V_113 ) {
V_2 -> V_105 += V_112 ;
goto V_19;
}
if ( V_2 -> V_104 ) {
V_6 = F_56 ( V_5 , V_2 , V_84 ) ;
F_32 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
if ( V_6 )
return V_6 ;
}
F_6 ( V_17 ) ;
V_2 -> V_104 = V_17 ;
V_2 -> V_106 = V_21 ;
V_2 -> V_105 = V_112 ;
V_2 -> V_108 = V_113 ;
V_2 -> V_60 = V_2 -> V_92 << V_2 -> V_90 ;
V_19:
if ( V_2 -> V_62 ) {
V_6 = F_56 ( V_5 , V_2 , V_84 ) ;
F_28 ( V_5 , V_2 ) ;
F_32 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
}
return V_6 ;
}
static void F_59 ( struct V_5 * V_5 , struct V_83 * V_84 )
{
unsigned V_70 ;
unsigned V_114 ;
V_114 = V_84 -> V_95 >> V_5 -> V_31 -> V_89 ;
for ( V_70 = 0 ; V_70 < V_114 ; V_70 ++ ) {
F_60 ( V_84 -> V_102 ,
V_84 -> V_115 + V_70 ) ;
}
}
static inline void F_61 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_116 , struct V_83 * V_84 )
{
unsigned V_117 ;
unsigned V_118 ;
unsigned V_119 ;
struct V_17 * V_17 ;
V_2 -> V_120 = 1 ;
if ( ! V_2 -> V_91 || ! F_62 ( V_84 ) )
return;
V_117 = 1 << V_2 -> V_91 ;
V_118 = V_2 -> V_92 & ( V_117 - 1 ) ;
if ( ! V_118 )
return;
if ( V_116 )
V_118 = V_117 - V_118 ;
V_119 = V_118 << V_2 -> V_90 ;
V_17 = F_5 ( 0 ) ;
if ( F_57 ( V_5 , V_2 , V_17 , 0 , V_119 ,
V_2 -> V_121 , V_84 ) )
return;
V_2 -> V_121 += V_118 ;
}
static int F_63 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_83 * V_84 )
{
const unsigned V_90 = V_2 -> V_90 ;
const unsigned V_122 = V_20 >> V_90 ;
struct V_17 * V_17 ;
unsigned V_123 ;
int V_6 = 0 ;
V_123 = V_2 -> V_124 ;
while ( V_2 -> V_92 < V_2 -> V_93 ) {
V_17 = F_7 ( V_5 , V_2 ) ;
if ( F_64 ( V_17 ) ) {
V_6 = F_65 ( V_17 ) ;
goto V_19;
}
while ( V_123 < V_122 ) {
unsigned V_125 = V_123 << V_90 ;
unsigned V_119 ;
unsigned V_118 ;
unsigned V_126 ;
if ( V_2 -> V_15 == 0 ) {
unsigned long V_127 ;
unsigned long V_128 ;
V_6 = F_49 ( V_5 , V_2 , V_84 ) ;
if ( V_6 ) {
F_32 ( V_17 ) ;
goto V_19;
}
if ( ! F_66 ( V_84 ) )
goto V_129;
V_2 -> V_15 =
V_84 -> V_95 >> V_2 -> V_90 ;
V_2 -> V_121 =
V_84 -> V_115 << V_2 -> V_91 ;
if ( F_62 ( V_84 ) )
F_59 ( V_5 , V_84 ) ;
if ( ! V_2 -> V_91 )
goto V_129;
V_127 = ( 1 << V_2 -> V_91 ) - 1 ;
V_128 = ( V_2 -> V_92 & V_127 ) ;
if ( ! F_62 ( V_84 ) )
V_2 -> V_121 += V_128 ;
V_2 -> V_15 -= V_128 ;
}
V_129:
if ( ! F_66 ( V_84 ) ) {
T_2 V_130 ;
if ( V_5 -> V_12 & V_16 ) {
F_32 ( V_17 ) ;
return - V_131 ;
}
V_130 = F_67 ( F_50 ( V_5 -> V_31 ) ,
1 << V_90 ) ;
if ( V_2 -> V_92 >=
V_130 >> V_90 ) {
F_32 ( V_17 ) ;
goto V_19;
}
F_68 ( V_17 , V_123 << V_90 ,
1 << V_90 ) ;
V_2 -> V_92 ++ ;
V_123 ++ ;
goto V_132;
}
if ( F_69 ( V_2 -> V_91 && ! V_2 -> V_120 ) )
F_61 ( V_5 , V_2 , 0 , V_84 ) ;
V_118 = V_2 -> V_15 ;
V_126 = ( V_20 - V_125 ) >> V_90 ;
if ( V_118 > V_126 )
V_118 = V_126 ;
V_126 = V_2 -> V_93 - V_2 -> V_92 ;
if ( V_118 > V_126 )
V_118 = V_126 ;
V_119 = V_118 << V_90 ;
F_9 ( V_119 == 0 ) ;
if ( V_118 == V_2 -> V_15 )
V_2 -> V_62 = F_70 ( V_84 ) ;
V_6 = F_57 ( V_5 , V_2 , V_17 ,
V_125 ,
V_119 ,
V_2 -> V_121 ,
V_84 ) ;
if ( V_6 ) {
F_32 ( V_17 ) ;
goto V_19;
}
V_2 -> V_121 += V_118 ;
V_2 -> V_92 += V_118 ;
V_123 += V_118 ;
V_2 -> V_15 -= V_118 ;
V_132:
F_9 ( V_2 -> V_92 > V_2 -> V_93 ) ;
if ( V_2 -> V_92 == V_2 -> V_93 )
break;
}
F_32 ( V_17 ) ;
V_123 = 0 ;
}
V_19:
return V_6 ;
}
static inline int F_71 ( struct V_5 * V_5 )
{
int V_74 ;
unsigned long V_42 ;
F_19 ( & V_5 -> V_43 , V_42 ) ;
V_74 = -- V_5 -> V_44 ;
F_21 ( & V_5 -> V_43 , V_42 ) ;
return V_74 ;
}
static inline T_1
F_72 ( int V_12 , struct V_133 * V_29 , struct V_31 * V_31 ,
struct V_50 * V_51 , const struct V_134 * V_135 , T_2 V_21 ,
unsigned long V_136 , T_4 V_97 , T_5 V_28 ,
T_6 V_61 , int V_42 )
{
int V_137 ;
T_7 V_138 ;
unsigned long V_139 ;
unsigned V_89 = F_73 ( V_31 -> V_89 ) ;
unsigned V_90 = V_89 ;
unsigned V_140 = ( 1 << V_90 ) - 1 ;
T_1 V_141 = - V_142 ;
T_2 V_116 = V_21 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
unsigned long V_143 ;
T_7 V_144 ;
struct V_83 V_84 = { 0 , } ;
struct V_145 V_146 ;
if ( V_12 & V_16 )
V_12 = V_147 ;
if ( V_21 & V_140 ) {
if ( V_51 )
V_90 = F_74 ( F_75 ( V_51 ) ) ;
V_140 = ( 1 << V_90 ) - 1 ;
if ( V_21 & V_140 )
goto V_19;
}
for ( V_137 = 0 ; V_137 < V_136 ; V_137 ++ ) {
V_139 = ( unsigned long ) V_135 [ V_137 ] . V_148 ;
V_138 = V_135 [ V_137 ] . V_149 ;
V_116 += V_138 ;
if ( F_69 ( ( V_139 & V_140 ) ||
( V_138 & V_140 ) ) ) {
if ( V_51 )
V_90 = F_74 (
F_75 ( V_51 ) ) ;
V_140 = ( 1 << V_90 ) - 1 ;
if ( ( V_139 & V_140 ) || ( V_138 & V_140 ) )
goto V_19;
}
}
if ( V_12 == V_13 && V_116 == V_21 )
return 0 ;
V_5 = F_76 ( V_34 , V_54 ) ;
V_141 = - V_82 ;
if ( ! V_5 )
goto V_19;
memset ( V_5 , 0 , F_77 ( struct V_5 , V_14 ) ) ;
V_5 -> V_42 = V_42 ;
if ( V_5 -> V_42 & V_150 ) {
if ( V_12 == V_13 ) {
struct V_151 * V_152 =
V_29 -> V_33 -> V_153 ;
F_78 ( & V_31 -> V_154 ) ;
V_141 = F_79 ( V_152 , V_21 ,
V_116 - 1 ) ;
if ( V_141 ) {
F_80 ( & V_31 -> V_154 ) ;
F_14 ( V_34 , V_5 ) ;
goto V_19;
}
}
}
V_5 -> V_22 = ! F_81 ( V_29 ) && ! ( ( V_12 & V_16 ) &&
( V_116 > F_50 ( V_31 ) ) ) ;
V_5 -> V_31 = V_31 ;
V_5 -> V_12 = V_12 ;
if ( V_5 -> V_22 && ( V_12 & V_16 ) &&
( ( V_29 -> V_33 -> V_155 & V_156 ) ||
F_82 ( V_29 -> V_33 -> V_153 -> V_157 ) ) ) {
V_141 = F_48 ( V_5 ) ;
if ( V_141 ) {
F_14 ( V_34 , V_5 ) ;
goto V_19;
}
}
F_83 ( & V_31 -> V_158 ) ;
V_141 = 0 ;
V_2 . V_90 = V_90 ;
V_2 . V_91 = V_89 - V_90 ;
V_2 . V_92 = V_21 >> V_90 ;
V_2 . V_97 = V_97 ;
V_5 -> V_28 = V_28 ;
V_2 . V_61 = V_61 ;
V_2 . V_107 = - 1 ;
V_2 . V_121 = - 1 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_26 = F_50 ( V_31 ) ;
F_84 ( & V_5 -> V_43 ) ;
V_5 -> V_44 = 1 ;
if ( F_69 ( V_2 . V_91 ) )
V_2 . V_101 = 2 ;
for ( V_137 = 0 ; V_137 < V_136 ; V_137 ++ ) {
V_143 = ( unsigned long ) V_135 [ V_137 ] . V_148 ;
V_2 . V_101 +=
( ( V_143 + V_135 [ V_137 ] . V_149 + V_20 - 1 ) /
V_20 - V_143 / V_20 ) ;
}
F_85 ( & V_146 ) ;
for ( V_137 = 0 ; V_137 < V_136 ; V_137 ++ ) {
V_143 = ( unsigned long ) V_135 [ V_137 ] . V_148 ;
V_2 . V_138 += V_144 = V_135 [ V_137 ] . V_149 ;
V_2 . V_124 = ( V_143 & ~ V_159 ) >> V_90 ;
V_2 . V_93 = V_2 . V_92 +
( V_144 >> V_90 ) ;
V_2 . V_4 = 0 ;
V_2 . V_3 = 0 ;
V_2 . V_9 = 0 ;
V_2 . V_8 = 0 ;
if ( V_143 & ( V_20 - 1 ) ) {
V_2 . V_8 ++ ;
V_144 -= V_20 - ( V_143 & ( V_20 - 1 ) ) ;
}
V_2 . V_8 += ( V_144 + V_20 - 1 ) / V_20 ;
V_2 . V_11 = V_143 ;
V_141 = F_63 ( V_5 , & V_2 , & V_84 ) ;
V_5 -> V_25 += V_135 [ V_137 ] . V_149 -
( ( V_2 . V_93 - V_2 . V_92 ) <<
V_90 ) ;
if ( V_141 ) {
F_31 ( V_5 , & V_2 ) ;
break;
}
}
if ( V_141 == - V_131 ) {
V_141 = 0 ;
}
F_61 ( V_5 , & V_2 , 1 , & V_84 ) ;
if ( V_2 . V_104 ) {
T_1 V_74 ;
V_74 = F_56 ( V_5 , & V_2 , & V_84 ) ;
if ( V_141 == 0 )
V_141 = V_74 ;
F_32 ( V_2 . V_104 ) ;
V_2 . V_104 = NULL ;
}
if ( V_2 . V_39 )
F_28 ( V_5 , & V_2 ) ;
F_86 ( & V_146 ) ;
F_31 ( V_5 , & V_2 ) ;
if ( V_12 == V_13 && ( V_5 -> V_42 & V_150 ) )
F_80 ( & V_5 -> V_31 -> V_154 ) ;
F_9 ( V_141 == - V_24 ) ;
if ( V_5 -> V_22 && V_141 == 0 && V_5 -> V_25 &&
( ( V_12 == V_13 ) || ( V_5 -> V_25 == V_2 . V_138 ) ) )
V_141 = - V_24 ;
if ( V_141 != - V_24 )
F_42 ( V_5 ) ;
if ( F_71 ( V_5 ) == 0 ) {
V_141 = F_10 ( V_5 , V_21 , V_141 , false ) ;
} else
F_9 ( V_141 != - V_24 ) ;
V_19:
return V_141 ;
}
T_1
F_87 ( int V_12 , struct V_133 * V_29 , struct V_31 * V_31 ,
struct V_50 * V_51 , const struct V_134 * V_135 , T_2 V_21 ,
unsigned long V_136 , T_4 V_97 , T_5 V_28 ,
T_6 V_61 , int V_42 )
{
F_88 ( & V_51 -> V_160 -> V_161 ) ;
F_88 ( V_51 -> V_162 ) ;
F_88 ( ( char * ) V_51 -> V_162 + V_163 ) ;
return F_72 ( V_12 , V_29 , V_31 , V_51 , V_135 , V_21 ,
V_136 , V_97 , V_28 ,
V_61 , V_42 ) ;
}
static T_8 int F_89 ( void )
{
V_34 = F_90 ( V_5 , V_164 ) ;
return 0 ;
}
