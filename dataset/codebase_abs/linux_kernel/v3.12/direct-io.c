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
V_39 -> V_56 = V_52 ;
if ( V_5 -> V_22 )
V_39 -> V_57 = F_17 ;
else
V_39 -> V_57 = F_24 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_58 = V_2 -> V_59 ;
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
if ( V_2 -> V_60 )
V_2 -> V_60 ( V_5 -> V_12 , V_39 , V_5 -> V_31 ,
V_2 -> V_58 ) ;
else
F_30 ( V_5 -> V_12 , V_39 ) ;
V_2 -> V_39 = NULL ;
V_2 -> V_61 = 0 ;
V_2 -> V_58 = 0 ;
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
F_34 ( V_62 ) ;
V_5 -> V_45 = V_63 ;
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
const int V_64 = F_36 ( V_65 , & V_39 -> V_66 ) ;
struct V_67 * V_68 ;
unsigned V_69 ;
if ( ! V_64 )
V_5 -> V_27 = - V_70 ;
if ( V_5 -> V_22 && V_5 -> V_12 == V_13 ) {
F_37 ( V_39 ) ;
} else {
F_38 (bvec, bio, i) {
struct V_17 * V_17 = V_68 -> V_71 ;
if ( V_5 -> V_12 == V_13 && ! F_39 ( V_17 ) )
F_40 ( V_17 ) ;
F_32 ( V_17 ) ;
}
F_41 ( V_39 ) ;
}
return V_64 ? 0 : - V_70 ;
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
if ( V_2 -> V_72 ++ >= 64 ) {
while ( V_5 -> V_49 ) {
unsigned long V_42 ;
struct V_39 * V_39 ;
int V_73 ;
F_19 ( & V_5 -> V_43 , V_42 ) ;
V_39 = V_5 -> V_49 ;
V_5 -> V_49 = V_39 -> V_40 ;
F_21 ( & V_5 -> V_43 , V_42 ) ;
V_73 = F_18 ( V_5 , V_39 ) ;
if ( V_6 == 0 )
V_6 = V_73 ;
}
V_2 -> V_72 = 0 ;
}
return V_6 ;
}
static int F_44 ( struct V_74 * V_75 )
{
struct V_76 * V_77 ;
struct V_76 * V_78 = F_45 ( L_1 ,
V_79 , 0 ,
V_75 -> V_80 ) ;
if ( ! V_78 )
return - V_81 ;
V_77 = F_46 ( & V_75 -> V_48 , NULL , V_78 ) ;
if ( V_77 )
F_47 ( V_78 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_5 )
{
struct V_74 * V_75 = V_5 -> V_31 -> V_47 ;
if ( V_5 -> V_46 )
return 0 ;
V_5 -> V_46 = true ;
if ( ! V_75 -> V_48 )
return F_44 ( V_75 ) ;
return 0 ;
}
static int F_49 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_82 * V_83 )
{
int V_6 ;
T_3 V_84 ;
T_3 V_85 ;
unsigned long V_86 ;
int V_87 ;
unsigned int V_88 = V_2 -> V_89 + V_2 -> V_90 ;
V_6 = V_5 -> V_18 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_91 >= V_2 -> V_92 ) ;
V_84 = V_2 -> V_91 >> V_2 -> V_90 ;
V_85 = ( V_2 -> V_92 - 1 ) >>
V_2 -> V_90 ;
V_86 = V_85 - V_84 + 1 ;
V_83 -> V_93 = 0 ;
V_83 -> V_94 = V_86 << V_88 ;
V_87 = V_5 -> V_12 & V_16 ;
if ( V_5 -> V_42 & V_95 ) {
if ( V_2 -> V_91 < ( F_50 ( V_5 -> V_31 ) >>
V_2 -> V_89 ) )
V_87 = 0 ;
}
V_6 = (* V_2 -> V_96 )( V_5 -> V_31 , V_84 ,
V_83 , V_87 ) ;
V_5 -> V_30 = V_83 -> V_97 ;
if ( V_6 == 0 && F_51 ( V_83 ) )
V_6 = F_48 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_52 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_98 , struct V_82 * V_83 )
{
T_3 V_99 ;
int V_6 , V_7 ;
V_6 = F_43 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_19;
V_99 = V_98 << ( V_2 -> V_89 - 9 ) ;
V_7 = F_3 ( V_2 -> V_100 , F_53 ( V_83 -> V_101 ) ) ;
V_7 = F_3 ( V_7 , V_102 ) ;
F_9 ( V_7 <= 0 ) ;
F_26 ( V_5 , V_2 , V_83 -> V_101 , V_99 , V_7 ) ;
V_2 -> V_61 = 0 ;
V_19:
return V_6 ;
}
static inline int F_54 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_55 ( V_2 -> V_39 , V_2 -> V_103 ,
V_2 -> V_104 , V_2 -> V_105 ) ;
if ( V_6 == V_2 -> V_104 ) {
if ( ( V_2 -> V_104 + V_2 -> V_105 ) == V_20 )
V_2 -> V_100 -- ;
F_6 ( V_2 -> V_103 ) ;
V_2 -> V_106 = V_2 -> V_107 +
( V_2 -> V_104 >> V_2 -> V_89 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_56 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_82 * V_83 )
{
int V_6 = 0 ;
if ( V_2 -> V_39 ) {
T_2 V_108 = V_2 -> V_59 ;
T_2 V_109 = V_2 -> V_58 +
V_2 -> V_39 -> V_110 ;
if ( V_2 -> V_106 != V_2 -> V_107 ||
V_108 != V_109 )
F_28 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_39 == NULL ) {
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_107 , V_83 ) ;
if ( V_6 )
goto V_19;
}
if ( F_54 ( V_2 ) != 0 ) {
F_28 ( V_5 , V_2 ) ;
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_107 , V_83 ) ;
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
unsigned V_21 , unsigned V_111 , T_3 V_112 ,
struct V_82 * V_83 )
{
int V_6 = 0 ;
if ( V_5 -> V_12 & V_16 ) {
F_58 ( V_111 ) ;
}
if ( V_2 -> V_103 == V_17 &&
V_2 -> V_105 + V_2 -> V_104 == V_21 &&
V_2 -> V_107 +
( V_2 -> V_104 >> V_2 -> V_89 ) == V_112 ) {
V_2 -> V_104 += V_111 ;
goto V_19;
}
if ( V_2 -> V_103 ) {
V_6 = F_56 ( V_5 , V_2 , V_83 ) ;
F_32 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
if ( V_6 )
return V_6 ;
}
F_6 ( V_17 ) ;
V_2 -> V_103 = V_17 ;
V_2 -> V_105 = V_21 ;
V_2 -> V_104 = V_111 ;
V_2 -> V_107 = V_112 ;
V_2 -> V_59 = V_2 -> V_91 << V_2 -> V_89 ;
V_19:
if ( V_2 -> V_61 ) {
V_6 = F_56 ( V_5 , V_2 , V_83 ) ;
F_28 ( V_5 , V_2 ) ;
F_32 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
}
return V_6 ;
}
static void F_59 ( struct V_5 * V_5 , struct V_82 * V_83 )
{
unsigned V_69 ;
unsigned V_113 ;
V_113 = V_83 -> V_94 >> V_5 -> V_31 -> V_88 ;
for ( V_69 = 0 ; V_69 < V_113 ; V_69 ++ ) {
F_60 ( V_83 -> V_101 ,
V_83 -> V_114 + V_69 ) ;
}
}
static inline void F_61 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_115 , struct V_82 * V_83 )
{
unsigned V_116 ;
unsigned V_117 ;
unsigned V_118 ;
struct V_17 * V_17 ;
V_2 -> V_119 = 1 ;
if ( ! V_2 -> V_90 || ! F_62 ( V_83 ) )
return;
V_116 = 1 << V_2 -> V_90 ;
V_117 = V_2 -> V_91 & ( V_116 - 1 ) ;
if ( ! V_117 )
return;
if ( V_115 )
V_117 = V_116 - V_117 ;
V_118 = V_117 << V_2 -> V_89 ;
V_17 = F_5 ( 0 ) ;
if ( F_57 ( V_5 , V_2 , V_17 , 0 , V_118 ,
V_2 -> V_120 , V_83 ) )
return;
V_2 -> V_120 += V_117 ;
}
static int F_63 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_82 * V_83 )
{
const unsigned V_89 = V_2 -> V_89 ;
const unsigned V_121 = V_20 >> V_89 ;
struct V_17 * V_17 ;
unsigned V_122 ;
int V_6 = 0 ;
V_122 = V_2 -> V_123 ;
while ( V_2 -> V_91 < V_2 -> V_92 ) {
V_17 = F_7 ( V_5 , V_2 ) ;
if ( F_64 ( V_17 ) ) {
V_6 = F_65 ( V_17 ) ;
goto V_19;
}
while ( V_122 < V_121 ) {
unsigned V_124 = V_122 << V_89 ;
unsigned V_118 ;
unsigned V_117 ;
unsigned V_125 ;
if ( V_2 -> V_15 == 0 ) {
unsigned long V_126 ;
unsigned long V_127 ;
V_6 = F_49 ( V_5 , V_2 , V_83 ) ;
if ( V_6 ) {
F_32 ( V_17 ) ;
goto V_19;
}
if ( ! F_66 ( V_83 ) )
goto V_128;
V_2 -> V_15 =
V_83 -> V_94 >> V_2 -> V_89 ;
V_2 -> V_120 =
V_83 -> V_114 << V_2 -> V_90 ;
if ( F_62 ( V_83 ) )
F_59 ( V_5 , V_83 ) ;
if ( ! V_2 -> V_90 )
goto V_128;
V_126 = ( 1 << V_2 -> V_90 ) - 1 ;
V_127 = ( V_2 -> V_91 & V_126 ) ;
if ( ! F_62 ( V_83 ) )
V_2 -> V_120 += V_127 ;
V_2 -> V_15 -= V_127 ;
}
V_128:
if ( ! F_66 ( V_83 ) ) {
T_2 V_129 ;
if ( V_5 -> V_12 & V_16 ) {
F_32 ( V_17 ) ;
return - V_130 ;
}
V_129 = F_67 ( F_50 ( V_5 -> V_31 ) ,
1 << V_89 ) ;
if ( V_2 -> V_91 >=
V_129 >> V_89 ) {
F_32 ( V_17 ) ;
goto V_19;
}
F_68 ( V_17 , V_122 << V_89 ,
1 << V_89 ) ;
V_2 -> V_91 ++ ;
V_122 ++ ;
goto V_131;
}
if ( F_69 ( V_2 -> V_90 && ! V_2 -> V_119 ) )
F_61 ( V_5 , V_2 , 0 , V_83 ) ;
V_117 = V_2 -> V_15 ;
V_125 = ( V_20 - V_124 ) >> V_89 ;
if ( V_117 > V_125 )
V_117 = V_125 ;
V_125 = V_2 -> V_92 - V_2 -> V_91 ;
if ( V_117 > V_125 )
V_117 = V_125 ;
V_118 = V_117 << V_89 ;
F_9 ( V_118 == 0 ) ;
if ( V_117 == V_2 -> V_15 )
V_2 -> V_61 = F_70 ( V_83 ) ;
V_6 = F_57 ( V_5 , V_2 , V_17 ,
V_124 ,
V_118 ,
V_2 -> V_120 ,
V_83 ) ;
if ( V_6 ) {
F_32 ( V_17 ) ;
goto V_19;
}
V_2 -> V_120 += V_117 ;
V_2 -> V_91 += V_117 ;
V_122 += V_117 ;
V_2 -> V_15 -= V_117 ;
V_131:
F_9 ( V_2 -> V_91 > V_2 -> V_92 ) ;
if ( V_2 -> V_91 == V_2 -> V_92 )
break;
}
F_32 ( V_17 ) ;
V_122 = 0 ;
}
V_19:
return V_6 ;
}
static inline int F_71 ( struct V_5 * V_5 )
{
int V_73 ;
unsigned long V_42 ;
F_19 ( & V_5 -> V_43 , V_42 ) ;
V_73 = -- V_5 -> V_44 ;
F_21 ( & V_5 -> V_43 , V_42 ) ;
return V_73 ;
}
static inline T_1
F_72 ( int V_12 , struct V_132 * V_29 , struct V_31 * V_31 ,
struct V_50 * V_51 , const struct V_133 * V_134 , T_2 V_21 ,
unsigned long V_135 , T_4 V_96 , T_5 V_28 ,
T_6 V_60 , int V_42 )
{
int V_136 ;
T_7 V_137 ;
unsigned long V_138 ;
unsigned V_88 = F_73 ( V_31 -> V_88 ) ;
unsigned V_89 = V_88 ;
unsigned V_139 = ( 1 << V_89 ) - 1 ;
T_1 V_140 = - V_141 ;
T_2 V_115 = V_21 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
unsigned long V_142 ;
T_7 V_143 ;
struct V_82 V_83 = { 0 , } ;
struct V_144 V_145 ;
if ( V_12 & V_16 )
V_12 = V_146 ;
if ( V_21 & V_139 ) {
if ( V_51 )
V_89 = F_74 ( F_75 ( V_51 ) ) ;
V_139 = ( 1 << V_89 ) - 1 ;
if ( V_21 & V_139 )
goto V_19;
}
for ( V_136 = 0 ; V_136 < V_135 ; V_136 ++ ) {
V_138 = ( unsigned long ) V_134 [ V_136 ] . V_147 ;
V_137 = V_134 [ V_136 ] . V_148 ;
V_115 += V_137 ;
if ( F_69 ( ( V_138 & V_139 ) ||
( V_137 & V_139 ) ) ) {
if ( V_51 )
V_89 = F_74 (
F_75 ( V_51 ) ) ;
V_139 = ( 1 << V_89 ) - 1 ;
if ( ( V_138 & V_139 ) || ( V_137 & V_139 ) )
goto V_19;
}
}
if ( V_12 == V_13 && V_115 == V_21 )
return 0 ;
V_5 = F_76 ( V_34 , V_54 ) ;
V_140 = - V_81 ;
if ( ! V_5 )
goto V_19;
memset ( V_5 , 0 , F_77 ( struct V_5 , V_14 ) ) ;
V_5 -> V_42 = V_42 ;
if ( V_5 -> V_42 & V_149 ) {
if ( V_12 == V_13 ) {
struct V_150 * V_151 =
V_29 -> V_33 -> V_152 ;
F_78 ( & V_31 -> V_153 ) ;
V_140 = F_79 ( V_151 , V_21 ,
V_115 - 1 ) ;
if ( V_140 ) {
F_80 ( & V_31 -> V_153 ) ;
F_14 ( V_34 , V_5 ) ;
goto V_19;
}
}
}
V_5 -> V_22 = ! F_81 ( V_29 ) && ! ( ( V_12 & V_16 ) &&
( V_115 > F_50 ( V_31 ) ) ) ;
V_5 -> V_31 = V_31 ;
V_5 -> V_12 = V_12 ;
if ( V_5 -> V_22 && ( V_12 & V_16 ) &&
( ( V_29 -> V_33 -> V_154 & V_155 ) ||
F_82 ( V_29 -> V_33 -> V_152 -> V_156 ) ) ) {
V_140 = F_48 ( V_5 ) ;
if ( V_140 ) {
F_14 ( V_34 , V_5 ) ;
goto V_19;
}
}
F_83 ( & V_31 -> V_157 ) ;
V_140 = 0 ;
V_2 . V_89 = V_89 ;
V_2 . V_90 = V_88 - V_89 ;
V_2 . V_91 = V_21 >> V_89 ;
V_2 . V_96 = V_96 ;
V_5 -> V_28 = V_28 ;
V_2 . V_60 = V_60 ;
V_2 . V_106 = - 1 ;
V_2 . V_120 = - 1 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_26 = F_50 ( V_31 ) ;
F_84 ( & V_5 -> V_43 ) ;
V_5 -> V_44 = 1 ;
if ( F_69 ( V_2 . V_90 ) )
V_2 . V_100 = 2 ;
for ( V_136 = 0 ; V_136 < V_135 ; V_136 ++ ) {
V_142 = ( unsigned long ) V_134 [ V_136 ] . V_147 ;
V_2 . V_100 +=
( ( V_142 + V_134 [ V_136 ] . V_148 + V_20 - 1 ) /
V_20 - V_142 / V_20 ) ;
}
F_85 ( & V_145 ) ;
for ( V_136 = 0 ; V_136 < V_135 ; V_136 ++ ) {
V_142 = ( unsigned long ) V_134 [ V_136 ] . V_147 ;
V_2 . V_137 += V_143 = V_134 [ V_136 ] . V_148 ;
V_2 . V_123 = ( V_142 & ~ V_158 ) >> V_89 ;
V_2 . V_92 = V_2 . V_91 +
( V_143 >> V_89 ) ;
V_2 . V_4 = 0 ;
V_2 . V_3 = 0 ;
V_2 . V_9 = 0 ;
V_2 . V_8 = 0 ;
if ( V_142 & ( V_20 - 1 ) ) {
V_2 . V_8 ++ ;
V_143 -= V_20 - ( V_142 & ( V_20 - 1 ) ) ;
}
V_2 . V_8 += ( V_143 + V_20 - 1 ) / V_20 ;
V_2 . V_11 = V_142 ;
V_140 = F_63 ( V_5 , & V_2 , & V_83 ) ;
V_5 -> V_25 += V_134 [ V_136 ] . V_148 -
( ( V_2 . V_92 - V_2 . V_91 ) <<
V_89 ) ;
if ( V_140 ) {
F_31 ( V_5 , & V_2 ) ;
break;
}
}
if ( V_140 == - V_130 ) {
V_140 = 0 ;
}
F_61 ( V_5 , & V_2 , 1 , & V_83 ) ;
if ( V_2 . V_103 ) {
T_1 V_73 ;
V_73 = F_56 ( V_5 , & V_2 , & V_83 ) ;
if ( V_140 == 0 )
V_140 = V_73 ;
F_32 ( V_2 . V_103 ) ;
V_2 . V_103 = NULL ;
}
if ( V_2 . V_39 )
F_28 ( V_5 , & V_2 ) ;
F_86 ( & V_145 ) ;
F_31 ( V_5 , & V_2 ) ;
if ( V_12 == V_13 && ( V_5 -> V_42 & V_149 ) )
F_80 ( & V_5 -> V_31 -> V_153 ) ;
F_9 ( V_140 == - V_24 ) ;
if ( V_5 -> V_22 && V_140 == 0 && V_5 -> V_25 &&
( ( V_12 == V_13 ) || ( V_5 -> V_25 == V_2 . V_137 ) ) )
V_140 = - V_24 ;
if ( V_140 != - V_24 )
F_42 ( V_5 ) ;
if ( F_71 ( V_5 ) == 0 ) {
V_140 = F_10 ( V_5 , V_21 , V_140 , false ) ;
} else
F_9 ( V_140 != - V_24 ) ;
V_19:
return V_140 ;
}
T_1
F_87 ( int V_12 , struct V_132 * V_29 , struct V_31 * V_31 ,
struct V_50 * V_51 , const struct V_133 * V_134 , T_2 V_21 ,
unsigned long V_135 , T_4 V_96 , T_5 V_28 ,
T_6 V_60 , int V_42 )
{
F_88 ( & V_51 -> V_159 -> V_160 ) ;
F_88 ( V_51 -> V_161 ) ;
F_88 ( ( char * ) V_51 -> V_161 + V_162 ) ;
return F_72 ( V_12 , V_29 , V_31 , V_51 , V_134 , V_21 ,
V_135 , V_96 , V_28 ,
V_60 , V_42 ) ;
}
static T_8 int F_89 ( void )
{
V_34 = F_90 ( V_5 , V_163 ) ;
return 0 ;
}
