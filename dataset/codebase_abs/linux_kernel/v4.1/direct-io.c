static inline unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 ;
}
static inline int F_2 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_3 ( V_2 -> V_7 , V_5 -> V_8 , V_9 , V_10 ,
& V_2 -> V_11 ) ;
if ( V_6 < 0 && V_2 -> V_12 && ( V_5 -> V_13 & V_14 ) ) {
struct V_15 * V_15 = F_4 ( 0 ) ;
if ( V_5 -> V_16 == 0 )
V_5 -> V_16 = V_6 ;
F_5 ( V_15 ) ;
V_5 -> V_8 [ 0 ] = V_15 ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = 1 ;
V_2 -> V_11 = 0 ;
V_2 -> V_17 = V_18 ;
return 0 ;
}
if ( V_6 >= 0 ) {
F_6 ( V_2 -> V_7 , V_6 ) ;
V_6 += V_2 -> V_11 ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = ( V_6 + V_18 - 1 ) / V_18 ;
V_2 -> V_17 = ( ( V_6 - 1 ) & ( V_18 - 1 ) ) + 1 ;
return 0 ;
}
return V_6 ;
}
static inline struct V_15 * F_7 ( struct V_5 * V_5 ,
struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) == 0 ) {
int V_6 ;
V_6 = F_2 ( V_5 , V_2 ) ;
if ( V_6 )
return F_8 ( V_6 ) ;
F_9 ( F_1 ( V_2 ) == 0 ) ;
}
return V_5 -> V_8 [ V_2 -> V_4 ] ;
}
static T_1 F_10 ( struct V_5 * V_5 , T_2 V_19 , T_1 V_6 ,
bool V_20 )
{
T_1 V_21 = 0 ;
if ( V_6 == - V_22 )
V_6 = 0 ;
if ( V_5 -> V_23 ) {
V_21 = V_5 -> V_23 ;
if ( ( V_5 -> V_13 == V_24 ) && ( ( V_19 + V_21 ) > V_5 -> V_25 ) )
V_21 = V_5 -> V_25 - V_19 ;
}
if ( V_6 == 0 )
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 )
V_6 = V_5 -> V_26 ;
if ( V_6 == 0 )
V_6 = V_21 ;
if ( V_5 -> V_27 && V_5 -> V_23 )
V_5 -> V_27 ( V_5 -> V_28 , V_19 , V_21 , V_5 -> V_29 ) ;
if ( ! ( V_5 -> V_30 & V_31 ) )
F_11 ( V_5 -> V_32 ) ;
if ( V_20 ) {
if ( V_5 -> V_13 & V_14 ) {
int V_33 ;
V_33 = F_12 ( V_5 -> V_28 -> V_34 , V_19 ,
V_21 ) ;
if ( V_33 < 0 && V_6 > 0 )
V_6 = V_33 ;
}
V_5 -> V_28 -> V_35 ( V_5 -> V_28 , V_6 , 0 ) ;
}
F_13 ( V_36 , V_5 ) ;
return V_6 ;
}
static void F_14 ( struct V_37 * V_38 )
{
struct V_5 * V_5 = F_15 ( V_38 , struct V_5 , V_39 ) ;
F_10 ( V_5 , V_5 -> V_28 -> V_40 , 0 , true ) ;
}
static void F_16 ( struct V_41 * V_41 , int error )
{
struct V_5 * V_5 = V_41 -> V_42 ;
unsigned long V_43 ;
unsigned long V_30 ;
F_17 ( V_5 , V_41 ) ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_43 = -- V_5 -> V_45 ;
if ( V_43 == 1 && V_5 -> V_46 )
F_19 ( V_5 -> V_46 ) ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
if ( V_43 == 0 ) {
if ( V_5 -> V_23 && V_5 -> V_47 ) {
F_21 ( & V_5 -> V_39 , F_14 ) ;
F_22 ( V_5 -> V_32 -> V_48 -> V_49 ,
& V_5 -> V_39 ) ;
} else {
F_10 ( V_5 , V_5 -> V_28 -> V_40 , 0 , true ) ;
}
}
}
static void F_23 ( struct V_41 * V_41 , int error )
{
struct V_5 * V_5 = V_41 -> V_42 ;
unsigned long V_30 ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_41 -> V_42 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 ;
if ( -- V_5 -> V_45 == 1 && V_5 -> V_46 )
F_19 ( V_5 -> V_46 ) ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
}
void F_24 ( struct V_41 * V_41 , int error )
{
struct V_5 * V_5 = V_41 -> V_42 ;
if ( V_5 -> V_20 )
F_16 ( V_41 , error ) ;
else
F_23 ( V_41 , error ) ;
}
static inline void
F_25 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_51 * V_52 ,
T_3 V_53 , int V_54 )
{
struct V_41 * V_41 ;
V_41 = F_26 ( V_55 , V_54 ) ;
V_41 -> V_56 = V_52 ;
V_41 -> V_57 . V_58 = V_53 ;
if ( V_5 -> V_20 )
V_41 -> V_59 = F_16 ;
else
V_41 -> V_59 = F_23 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_60 = V_2 -> V_61 ;
}
static inline void F_27 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
struct V_41 * V_41 = V_2 -> V_41 ;
unsigned long V_30 ;
V_41 -> V_42 = V_5 ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_5 -> V_45 ++ ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
if ( V_5 -> V_20 && V_5 -> V_13 == V_24 )
F_28 ( V_41 ) ;
if ( V_2 -> V_62 )
V_2 -> V_62 ( V_5 -> V_13 , V_41 , V_5 -> V_32 ,
V_2 -> V_60 ) ;
else
F_29 ( V_5 -> V_13 , V_41 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_63 = 0 ;
V_2 -> V_60 = 0 ;
}
static inline void F_30 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
while ( V_2 -> V_4 < V_2 -> V_3 )
F_31 ( V_5 -> V_8 [ V_2 -> V_4 ++ ] ) ;
}
static struct V_41 * F_32 ( struct V_5 * V_5 )
{
unsigned long V_30 ;
struct V_41 * V_41 = NULL ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
while ( V_5 -> V_45 > 1 && V_5 -> V_50 == NULL ) {
F_33 ( V_64 ) ;
V_5 -> V_46 = V_65 ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
F_34 () ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_5 -> V_46 = NULL ;
}
if ( V_5 -> V_50 ) {
V_41 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 -> V_42 ;
}
F_20 ( & V_5 -> V_44 , V_30 ) ;
return V_41 ;
}
static int F_17 ( struct V_5 * V_5 , struct V_41 * V_41 )
{
const int V_66 = F_35 ( V_67 , & V_41 -> V_68 ) ;
struct V_69 * V_70 ;
unsigned V_71 ;
if ( ! V_66 )
V_5 -> V_26 = - V_72 ;
if ( V_5 -> V_20 && V_5 -> V_13 == V_24 ) {
F_36 ( V_41 ) ;
} else {
F_37 (bvec, bio, i) {
struct V_15 * V_15 = V_70 -> V_73 ;
if ( V_5 -> V_13 == V_24 && ! F_38 ( V_15 ) )
F_39 ( V_15 ) ;
F_31 ( V_15 ) ;
}
F_40 ( V_41 ) ;
}
return V_66 ? 0 : - V_72 ;
}
static void F_41 ( struct V_5 * V_5 )
{
struct V_41 * V_41 ;
do {
V_41 = F_32 ( V_5 ) ;
if ( V_41 )
F_17 ( V_5 , V_41 ) ;
} while ( V_41 );
}
static inline int F_42 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_74 ++ >= 64 ) {
while ( V_5 -> V_50 ) {
unsigned long V_30 ;
struct V_41 * V_41 ;
int V_75 ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_41 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 -> V_42 ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
V_75 = F_17 ( V_5 , V_41 ) ;
if ( V_6 == 0 )
V_6 = V_75 ;
}
V_2 -> V_74 = 0 ;
}
return V_6 ;
}
static int F_43 ( struct V_76 * V_77 )
{
struct V_78 * V_79 ;
struct V_78 * V_80 = F_44 ( L_1 ,
V_81 , 0 ,
V_77 -> V_82 ) ;
if ( ! V_80 )
return - V_83 ;
V_79 = F_45 ( & V_77 -> V_49 , NULL , V_80 ) ;
if ( V_79 )
F_46 ( V_80 ) ;
return 0 ;
}
static int F_47 ( struct V_5 * V_5 )
{
struct V_76 * V_77 = V_5 -> V_32 -> V_48 ;
if ( V_5 -> V_47 )
return 0 ;
V_5 -> V_47 = true ;
if ( ! V_77 -> V_49 )
return F_43 ( V_77 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_84 * V_85 )
{
int V_6 ;
T_3 V_86 ;
T_3 V_87 ;
unsigned long V_88 ;
int V_89 ;
unsigned int V_90 = V_2 -> V_91 + V_2 -> V_92 ;
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_93 >= V_2 -> V_94 ) ;
V_86 = V_2 -> V_93 >> V_2 -> V_92 ;
V_87 = ( V_2 -> V_94 - 1 ) >>
V_2 -> V_92 ;
V_88 = V_87 - V_86 + 1 ;
V_85 -> V_95 = 0 ;
V_85 -> V_96 = V_88 << V_90 ;
V_89 = V_5 -> V_13 & V_14 ;
if ( V_5 -> V_30 & V_97 ) {
if ( V_2 -> V_93 < ( F_49 ( V_5 -> V_32 ) >>
V_2 -> V_91 ) )
V_89 = 0 ;
}
V_6 = (* V_2 -> V_98 )( V_5 -> V_32 , V_86 ,
V_85 , V_89 ) ;
V_5 -> V_29 = V_85 -> V_99 ;
if ( V_6 == 0 && F_50 ( V_85 ) )
V_6 = F_47 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_51 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_100 , struct V_84 * V_85 )
{
T_3 V_101 ;
int V_6 , V_102 ;
V_6 = F_42 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_103;
V_101 = V_100 << ( V_2 -> V_91 - 9 ) ;
V_102 = F_52 ( V_2 -> V_104 , F_53 ( V_85 -> V_105 ) ) ;
F_9 ( V_102 <= 0 ) ;
F_25 ( V_5 , V_2 , V_85 -> V_105 , V_101 , V_102 ) ;
V_2 -> V_63 = 0 ;
V_103:
return V_6 ;
}
static inline int F_54 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_55 ( V_2 -> V_41 , V_2 -> V_106 ,
V_2 -> V_107 , V_2 -> V_108 ) ;
if ( V_6 == V_2 -> V_107 ) {
if ( ( V_2 -> V_107 + V_2 -> V_108 ) == V_18 )
V_2 -> V_104 -- ;
F_5 ( V_2 -> V_106 ) ;
V_2 -> V_109 = V_2 -> V_110 +
( V_2 -> V_107 >> V_2 -> V_91 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_56 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_84 * V_85 )
{
int V_6 = 0 ;
if ( V_2 -> V_41 ) {
T_2 V_111 = V_2 -> V_61 ;
T_2 V_112 = V_2 -> V_60 +
V_2 -> V_41 -> V_57 . V_113 ;
if ( V_2 -> V_109 != V_2 -> V_110 ||
V_111 != V_112 )
F_27 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_41 == NULL ) {
V_6 = F_51 ( V_5 , V_2 , V_2 -> V_110 , V_85 ) ;
if ( V_6 )
goto V_103;
}
if ( F_54 ( V_2 ) != 0 ) {
F_27 ( V_5 , V_2 ) ;
V_6 = F_51 ( V_5 , V_2 , V_2 -> V_110 , V_85 ) ;
if ( V_6 == 0 ) {
V_6 = F_54 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_103:
return V_6 ;
}
static inline int
F_57 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned V_19 , unsigned V_114 , T_3 V_115 ,
struct V_84 * V_85 )
{
int V_6 = 0 ;
if ( V_5 -> V_13 & V_14 ) {
F_58 ( V_114 ) ;
}
if ( V_2 -> V_106 == V_15 &&
V_2 -> V_108 + V_2 -> V_107 == V_19 &&
V_2 -> V_110 +
( V_2 -> V_107 >> V_2 -> V_91 ) == V_115 ) {
V_2 -> V_107 += V_114 ;
goto V_103;
}
if ( V_2 -> V_106 ) {
V_6 = F_56 ( V_5 , V_2 , V_85 ) ;
F_31 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
if ( V_6 )
return V_6 ;
}
F_5 ( V_15 ) ;
V_2 -> V_106 = V_15 ;
V_2 -> V_108 = V_19 ;
V_2 -> V_107 = V_114 ;
V_2 -> V_110 = V_115 ;
V_2 -> V_61 = V_2 -> V_93 << V_2 -> V_91 ;
V_103:
if ( V_2 -> V_63 ) {
V_6 = F_56 ( V_5 , V_2 , V_85 ) ;
F_27 ( V_5 , V_2 ) ;
F_31 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
}
return V_6 ;
}
static void F_59 ( struct V_5 * V_5 , struct V_84 * V_85 )
{
unsigned V_71 ;
unsigned V_116 ;
V_116 = V_85 -> V_96 >> V_5 -> V_32 -> V_90 ;
for ( V_71 = 0 ; V_71 < V_116 ; V_71 ++ ) {
F_60 ( V_85 -> V_105 ,
V_85 -> V_117 + V_71 ) ;
}
}
static inline void F_61 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_118 , struct V_84 * V_85 )
{
unsigned V_119 ;
unsigned V_120 ;
unsigned V_121 ;
struct V_15 * V_15 ;
V_2 -> V_122 = 1 ;
if ( ! V_2 -> V_92 || ! F_62 ( V_85 ) )
return;
V_119 = 1 << V_2 -> V_92 ;
V_120 = V_2 -> V_93 & ( V_119 - 1 ) ;
if ( ! V_120 )
return;
if ( V_118 )
V_120 = V_119 - V_120 ;
V_121 = V_120 << V_2 -> V_91 ;
V_15 = F_4 ( 0 ) ;
if ( F_57 ( V_5 , V_2 , V_15 , 0 , V_121 ,
V_2 -> V_123 , V_85 ) )
return;
V_2 -> V_123 += V_120 ;
}
static int F_63 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_84 * V_85 )
{
const unsigned V_91 = V_2 -> V_91 ;
int V_6 = 0 ;
while ( V_2 -> V_93 < V_2 -> V_94 ) {
struct V_15 * V_15 ;
T_4 V_11 , V_17 ;
V_15 = F_7 ( V_5 , V_2 ) ;
if ( F_64 ( V_15 ) ) {
V_6 = F_65 ( V_15 ) ;
goto V_103;
}
V_11 = V_2 -> V_4 ? 0 : V_2 -> V_11 ;
V_17 = ( V_2 -> V_4 == V_2 -> V_3 - 1 ) ? V_2 -> V_17 : V_18 ;
V_2 -> V_4 ++ ;
while ( V_11 < V_17 ) {
unsigned V_121 ;
unsigned V_120 ;
unsigned V_124 ;
if ( V_2 -> V_12 == 0 ) {
unsigned long V_125 ;
unsigned long V_126 ;
V_6 = F_48 ( V_5 , V_2 , V_85 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_103;
}
if ( ! F_66 ( V_85 ) )
goto V_127;
V_2 -> V_12 =
V_85 -> V_96 >> V_2 -> V_91 ;
V_2 -> V_123 =
V_85 -> V_117 << V_2 -> V_92 ;
if ( F_62 ( V_85 ) )
F_59 ( V_5 , V_85 ) ;
if ( ! V_2 -> V_92 )
goto V_127;
V_125 = ( 1 << V_2 -> V_92 ) - 1 ;
V_126 = ( V_2 -> V_93 & V_125 ) ;
if ( ! F_62 ( V_85 ) )
V_2 -> V_123 += V_126 ;
V_2 -> V_12 -= V_126 ;
}
V_127:
if ( ! F_66 ( V_85 ) ) {
T_2 V_128 ;
if ( V_5 -> V_13 & V_14 ) {
F_31 ( V_15 ) ;
return - V_129 ;
}
V_128 = F_67 ( F_49 ( V_5 -> V_32 ) ,
1 << V_91 ) ;
if ( V_2 -> V_93 >=
V_128 >> V_91 ) {
F_31 ( V_15 ) ;
goto V_103;
}
F_68 ( V_15 , V_11 , 1 << V_91 ) ;
V_2 -> V_93 ++ ;
V_11 += 1 << V_91 ;
V_5 -> V_23 += 1 << V_91 ;
goto V_130;
}
if ( F_69 ( V_2 -> V_92 && ! V_2 -> V_122 ) )
F_61 ( V_5 , V_2 , 0 , V_85 ) ;
V_120 = V_2 -> V_12 ;
V_124 = ( V_17 - V_11 ) >> V_91 ;
if ( V_120 > V_124 )
V_120 = V_124 ;
V_124 = V_2 -> V_94 - V_2 -> V_93 ;
if ( V_120 > V_124 )
V_120 = V_124 ;
V_121 = V_120 << V_91 ;
F_9 ( V_121 == 0 ) ;
if ( V_120 == V_2 -> V_12 )
V_2 -> V_63 = F_70 ( V_85 ) ;
V_6 = F_57 ( V_5 , V_2 , V_15 ,
V_11 ,
V_121 ,
V_2 -> V_123 ,
V_85 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_103;
}
V_2 -> V_123 += V_120 ;
V_2 -> V_93 += V_120 ;
V_11 += V_121 ;
V_5 -> V_23 += V_121 ;
V_2 -> V_12 -= V_120 ;
V_130:
F_9 ( V_2 -> V_93 > V_2 -> V_94 ) ;
if ( V_2 -> V_93 == V_2 -> V_94 )
break;
}
F_31 ( V_15 ) ;
}
V_103:
return V_6 ;
}
static inline int F_71 ( struct V_5 * V_5 )
{
int V_75 ;
unsigned long V_30 ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_75 = -- V_5 -> V_45 ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
return V_75 ;
}
static inline T_1
F_72 ( struct V_131 * V_28 , struct V_32 * V_32 ,
struct V_51 * V_52 , struct V_132 * V_7 ,
T_2 V_19 , T_5 V_98 , T_6 V_27 ,
T_7 V_62 , int V_30 )
{
unsigned V_90 = F_73 ( V_32 -> V_90 ) ;
unsigned V_91 = V_90 ;
unsigned V_133 = ( 1 << V_91 ) - 1 ;
T_1 V_134 = - V_135 ;
T_4 V_136 = F_74 ( V_7 ) ;
T_2 V_118 = V_19 + V_136 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
struct V_84 V_85 = { 0 , } ;
struct V_137 V_138 ;
unsigned long V_139 = V_19 | F_75 ( V_7 ) ;
if ( V_139 & V_133 ) {
if ( V_52 )
V_91 = F_76 ( F_77 ( V_52 ) ) ;
V_133 = ( 1 << V_91 ) - 1 ;
if ( V_139 & V_133 )
goto V_103;
}
if ( F_78 ( V_7 ) == V_24 && ! F_74 ( V_7 ) )
return 0 ;
V_5 = F_79 ( V_36 , V_55 ) ;
V_134 = - V_83 ;
if ( ! V_5 )
goto V_103;
memset ( V_5 , 0 , F_80 ( struct V_5 , V_8 ) ) ;
V_5 -> V_30 = V_30 ;
if ( V_5 -> V_30 & V_140 ) {
if ( F_78 ( V_7 ) == V_24 ) {
struct V_141 * V_142 =
V_28 -> V_34 -> V_143 ;
F_81 ( & V_32 -> V_144 ) ;
V_134 = F_82 ( V_142 , V_19 ,
V_118 - 1 ) ;
if ( V_134 ) {
F_83 ( & V_32 -> V_144 ) ;
F_13 ( V_36 , V_5 ) ;
goto V_103;
}
}
}
if ( F_84 ( V_28 ) )
V_5 -> V_20 = false ;
else if ( ! ( V_5 -> V_30 & V_145 ) &&
F_78 ( V_7 ) == V_14 && V_118 > F_49 ( V_32 ) )
V_5 -> V_20 = false ;
else
V_5 -> V_20 = true ;
V_5 -> V_32 = V_32 ;
V_5 -> V_13 = F_78 ( V_7 ) == V_14 ? V_146 : V_24 ;
if ( V_5 -> V_20 && F_78 ( V_7 ) == V_14 &&
( ( V_28 -> V_34 -> V_147 & V_148 ) ||
F_85 ( V_28 -> V_34 -> V_143 -> V_149 ) ) ) {
V_134 = F_47 ( V_5 ) ;
if ( V_134 ) {
F_13 ( V_36 , V_5 ) ;
goto V_103;
}
}
if ( ! ( V_5 -> V_30 & V_31 ) )
F_86 ( V_32 ) ;
V_134 = 0 ;
V_2 . V_91 = V_91 ;
V_2 . V_92 = V_90 - V_91 ;
V_2 . V_93 = V_19 >> V_91 ;
V_2 . V_98 = V_98 ;
V_5 -> V_27 = V_27 ;
V_2 . V_62 = V_62 ;
V_2 . V_109 = - 1 ;
V_2 . V_123 = - 1 ;
V_5 -> V_28 = V_28 ;
V_5 -> V_25 = F_49 ( V_32 ) ;
F_87 ( & V_5 -> V_44 ) ;
V_5 -> V_45 = 1 ;
V_2 . V_7 = V_7 ;
V_2 . V_94 =
( V_19 + F_74 ( V_7 ) ) >> V_91 ;
if ( F_69 ( V_2 . V_92 ) )
V_2 . V_104 = 2 ;
V_2 . V_104 += F_88 ( V_7 , V_150 ) ;
F_89 ( & V_138 ) ;
V_134 = F_63 ( V_5 , & V_2 , & V_85 ) ;
if ( V_134 )
F_30 ( V_5 , & V_2 ) ;
if ( V_134 == - V_129 ) {
V_134 = 0 ;
}
F_61 ( V_5 , & V_2 , 1 , & V_85 ) ;
if ( V_2 . V_106 ) {
T_1 V_75 ;
V_75 = F_56 ( V_5 , & V_2 , & V_85 ) ;
if ( V_134 == 0 )
V_134 = V_75 ;
F_31 ( V_2 . V_106 ) ;
V_2 . V_106 = NULL ;
}
if ( V_2 . V_41 )
F_27 ( V_5 , & V_2 ) ;
F_90 ( & V_138 ) ;
F_30 ( V_5 , & V_2 ) ;
if ( F_78 ( V_7 ) == V_24 && ( V_5 -> V_30 & V_140 ) )
F_83 ( & V_5 -> V_32 -> V_144 ) ;
F_9 ( V_134 == - V_22 ) ;
if ( V_5 -> V_20 && V_134 == 0 && V_5 -> V_23 &&
( F_78 ( V_7 ) == V_24 || V_5 -> V_23 == V_136 ) )
V_134 = - V_22 ;
else
F_41 ( V_5 ) ;
if ( F_71 ( V_5 ) == 0 ) {
V_134 = F_10 ( V_5 , V_19 , V_134 , false ) ;
} else
F_9 ( V_134 != - V_22 ) ;
V_103:
return V_134 ;
}
T_1 F_91 ( struct V_131 * V_28 , struct V_32 * V_32 ,
struct V_51 * V_52 , struct V_132 * V_7 ,
T_2 V_19 , T_5 V_98 ,
T_6 V_27 , T_7 V_62 ,
int V_30 )
{
F_92 ( & V_52 -> V_151 -> V_152 ) ;
F_92 ( V_52 -> V_153 ) ;
F_92 ( ( char * ) V_52 -> V_153 + V_154 ) ;
return F_72 ( V_28 , V_32 , V_52 , V_7 , V_19 , V_98 ,
V_27 , V_62 , V_30 ) ;
}
static T_8 int F_93 ( void )
{
V_36 = F_94 ( V_5 , V_155 ) ;
return 0 ;
}
