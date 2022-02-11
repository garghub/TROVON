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
static void F_16 ( struct V_41 * V_41 )
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
static void F_23 ( struct V_41 * V_41 )
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
F_16 ( V_41 ) ;
else
F_23 ( V_41 ) ;
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
if ( V_5 -> V_20 && V_5 -> V_13 == V_24 && V_5 -> V_62 )
F_28 ( V_41 ) ;
V_5 -> V_63 = V_41 -> V_56 ;
if ( V_2 -> V_64 ) {
V_2 -> V_64 ( V_5 -> V_13 , V_41 , V_5 -> V_32 ,
V_2 -> V_60 ) ;
V_5 -> V_65 = V_66 ;
} else
V_5 -> V_65 = F_29 ( V_5 -> V_13 , V_41 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_67 = 0 ;
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
F_33 ( V_68 ) ;
V_5 -> V_46 = V_69 ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
if ( ! F_34 ( F_35 ( V_5 -> V_63 ) , V_5 -> V_65 ) )
F_36 () ;
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
struct V_70 * V_71 ;
unsigned V_72 ;
int V_33 ;
if ( V_41 -> V_73 )
V_5 -> V_26 = - V_74 ;
if ( V_5 -> V_20 && V_5 -> V_13 == V_24 && V_5 -> V_62 ) {
V_33 = V_41 -> V_73 ;
F_37 ( V_41 ) ;
} else {
F_38 (bvec, bio, i) {
struct V_15 * V_15 = V_71 -> V_75 ;
if ( V_5 -> V_13 == V_24 && ! F_39 ( V_15 ) &&
V_5 -> V_62 )
F_40 ( V_15 ) ;
F_31 ( V_15 ) ;
}
V_33 = V_41 -> V_73 ;
F_41 ( V_41 ) ;
}
return V_33 ;
}
static void F_42 ( struct V_5 * V_5 )
{
struct V_41 * V_41 ;
do {
V_41 = F_32 ( V_5 ) ;
if ( V_41 )
F_17 ( V_5 , V_41 ) ;
} while ( V_41 );
}
static inline int F_43 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_76 ++ >= 64 ) {
while ( V_5 -> V_50 ) {
unsigned long V_30 ;
struct V_41 * V_41 ;
int V_77 ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_41 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 -> V_42 ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
V_77 = F_17 ( V_5 , V_41 ) ;
if ( V_6 == 0 )
V_6 = V_77 ;
}
V_2 -> V_76 = 0 ;
}
return V_6 ;
}
static int F_44 ( struct V_78 * V_79 )
{
struct V_80 * V_81 ;
struct V_80 * V_82 = F_45 ( L_1 ,
V_83 , 0 ,
V_79 -> V_84 ) ;
if ( ! V_82 )
return - V_85 ;
V_81 = F_46 ( & V_79 -> V_49 , NULL , V_82 ) ;
if ( V_81 )
F_47 ( V_82 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_5 )
{
struct V_78 * V_79 = V_5 -> V_32 -> V_48 ;
if ( V_5 -> V_47 )
return 0 ;
V_5 -> V_47 = true ;
if ( ! V_79 -> V_49 )
return F_44 ( V_79 ) ;
return 0 ;
}
static int F_49 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_86 * V_87 )
{
int V_6 ;
T_3 V_88 ;
T_3 V_89 ;
unsigned long V_90 ;
int V_91 ;
unsigned int V_92 = V_2 -> V_93 + V_2 -> V_94 ;
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_95 >= V_2 -> V_96 ) ;
V_88 = V_2 -> V_95 >> V_2 -> V_94 ;
V_89 = ( V_2 -> V_96 - 1 ) >>
V_2 -> V_94 ;
V_90 = V_89 - V_88 + 1 ;
V_87 -> V_97 = 0 ;
V_87 -> V_98 = V_90 << V_92 ;
V_91 = V_5 -> V_13 & V_14 ;
if ( V_5 -> V_30 & V_99 ) {
if ( V_2 -> V_95 < ( F_50 ( V_5 -> V_32 ) >>
V_2 -> V_93 ) )
V_91 = 0 ;
}
V_6 = (* V_2 -> V_100 )( V_5 -> V_32 , V_88 ,
V_87 , V_91 ) ;
V_5 -> V_29 = V_87 -> V_101 ;
if ( V_6 == 0 && F_51 ( V_87 ) )
V_6 = F_48 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_52 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_102 , struct V_86 * V_87 )
{
T_3 V_103 ;
int V_6 , V_104 ;
V_6 = F_43 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_105;
V_103 = V_102 << ( V_2 -> V_93 - 9 ) ;
V_104 = F_53 ( V_2 -> V_106 , V_107 ) ;
F_9 ( V_104 <= 0 ) ;
F_25 ( V_5 , V_2 , V_87 -> V_108 , V_103 , V_104 ) ;
V_2 -> V_67 = 0 ;
V_105:
return V_6 ;
}
static inline int F_54 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_55 ( V_2 -> V_41 , V_2 -> V_109 ,
V_2 -> V_110 , V_2 -> V_111 ) ;
if ( V_6 == V_2 -> V_110 ) {
if ( ( V_2 -> V_110 + V_2 -> V_111 ) == V_18 )
V_2 -> V_106 -- ;
F_5 ( V_2 -> V_109 ) ;
V_2 -> V_112 = V_2 -> V_113 +
( V_2 -> V_110 >> V_2 -> V_93 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_56 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_86 * V_87 )
{
int V_6 = 0 ;
if ( V_2 -> V_41 ) {
T_2 V_114 = V_2 -> V_61 ;
T_2 V_115 = V_2 -> V_60 +
V_2 -> V_41 -> V_57 . V_116 ;
if ( V_2 -> V_112 != V_2 -> V_113 ||
V_114 != V_115 )
F_27 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_41 == NULL ) {
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_113 , V_87 ) ;
if ( V_6 )
goto V_105;
}
if ( F_54 ( V_2 ) != 0 ) {
F_27 ( V_5 , V_2 ) ;
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_113 , V_87 ) ;
if ( V_6 == 0 ) {
V_6 = F_54 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_105:
return V_6 ;
}
static inline int
F_57 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned V_19 , unsigned V_117 , T_3 V_118 ,
struct V_86 * V_87 )
{
int V_6 = 0 ;
if ( V_5 -> V_13 & V_14 ) {
F_58 ( V_117 ) ;
}
if ( V_2 -> V_109 == V_15 &&
V_2 -> V_111 + V_2 -> V_110 == V_19 &&
V_2 -> V_113 +
( V_2 -> V_110 >> V_2 -> V_93 ) == V_118 ) {
V_2 -> V_110 += V_117 ;
goto V_105;
}
if ( V_2 -> V_109 ) {
V_6 = F_56 ( V_5 , V_2 , V_87 ) ;
F_31 ( V_2 -> V_109 ) ;
V_2 -> V_109 = NULL ;
if ( V_6 )
return V_6 ;
}
F_5 ( V_15 ) ;
V_2 -> V_109 = V_15 ;
V_2 -> V_111 = V_19 ;
V_2 -> V_110 = V_117 ;
V_2 -> V_113 = V_118 ;
V_2 -> V_61 = V_2 -> V_95 << V_2 -> V_93 ;
V_105:
if ( V_2 -> V_67 ) {
V_6 = F_56 ( V_5 , V_2 , V_87 ) ;
F_27 ( V_5 , V_2 ) ;
F_31 ( V_2 -> V_109 ) ;
V_2 -> V_109 = NULL ;
}
return V_6 ;
}
static void F_59 ( struct V_5 * V_5 , struct V_86 * V_87 )
{
unsigned V_72 ;
unsigned V_119 ;
V_119 = V_87 -> V_98 >> V_5 -> V_32 -> V_92 ;
for ( V_72 = 0 ; V_72 < V_119 ; V_72 ++ ) {
F_60 ( V_87 -> V_108 ,
V_87 -> V_120 + V_72 ) ;
}
}
static inline void F_61 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_121 , struct V_86 * V_87 )
{
unsigned V_122 ;
unsigned V_123 ;
unsigned V_124 ;
struct V_15 * V_15 ;
V_2 -> V_125 = 1 ;
if ( ! V_2 -> V_94 || ! F_62 ( V_87 ) )
return;
V_122 = 1 << V_2 -> V_94 ;
V_123 = V_2 -> V_95 & ( V_122 - 1 ) ;
if ( ! V_123 )
return;
if ( V_121 )
V_123 = V_122 - V_123 ;
V_124 = V_123 << V_2 -> V_93 ;
V_15 = F_4 ( 0 ) ;
if ( F_57 ( V_5 , V_2 , V_15 , 0 , V_124 ,
V_2 -> V_126 , V_87 ) )
return;
V_2 -> V_126 += V_123 ;
}
static int F_63 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_86 * V_87 )
{
const unsigned V_93 = V_2 -> V_93 ;
int V_6 = 0 ;
while ( V_2 -> V_95 < V_2 -> V_96 ) {
struct V_15 * V_15 ;
T_4 V_11 , V_17 ;
V_15 = F_7 ( V_5 , V_2 ) ;
if ( F_64 ( V_15 ) ) {
V_6 = F_65 ( V_15 ) ;
goto V_105;
}
V_11 = V_2 -> V_4 ? 0 : V_2 -> V_11 ;
V_17 = ( V_2 -> V_4 == V_2 -> V_3 - 1 ) ? V_2 -> V_17 : V_18 ;
V_2 -> V_4 ++ ;
while ( V_11 < V_17 ) {
unsigned V_124 ;
unsigned V_123 ;
unsigned V_127 ;
if ( V_2 -> V_12 == 0 ) {
unsigned long V_128 ;
unsigned long V_129 ;
V_6 = F_49 ( V_5 , V_2 , V_87 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_105;
}
if ( ! F_66 ( V_87 ) )
goto V_130;
V_2 -> V_12 =
V_87 -> V_98 >> V_2 -> V_93 ;
V_2 -> V_126 =
V_87 -> V_120 << V_2 -> V_94 ;
if ( F_62 ( V_87 ) )
F_59 ( V_5 , V_87 ) ;
if ( ! V_2 -> V_94 )
goto V_130;
V_128 = ( 1 << V_2 -> V_94 ) - 1 ;
V_129 = ( V_2 -> V_95 & V_128 ) ;
if ( ! F_62 ( V_87 ) )
V_2 -> V_126 += V_129 ;
V_2 -> V_12 -= V_129 ;
}
V_130:
if ( ! F_66 ( V_87 ) ) {
T_2 V_131 ;
if ( V_5 -> V_13 & V_14 ) {
F_31 ( V_15 ) ;
return - V_132 ;
}
V_131 = F_67 ( F_50 ( V_5 -> V_32 ) ,
1 << V_93 ) ;
if ( V_2 -> V_95 >=
V_131 >> V_93 ) {
F_31 ( V_15 ) ;
goto V_105;
}
F_68 ( V_15 , V_11 , 1 << V_93 ) ;
V_2 -> V_95 ++ ;
V_11 += 1 << V_93 ;
V_5 -> V_23 += 1 << V_93 ;
goto V_133;
}
if ( F_69 ( V_2 -> V_94 && ! V_2 -> V_125 ) )
F_61 ( V_5 , V_2 , 0 , V_87 ) ;
V_123 = V_2 -> V_12 ;
V_127 = ( V_17 - V_11 ) >> V_93 ;
if ( V_123 > V_127 )
V_123 = V_127 ;
V_127 = V_2 -> V_96 - V_2 -> V_95 ;
if ( V_123 > V_127 )
V_123 = V_127 ;
V_124 = V_123 << V_93 ;
F_9 ( V_124 == 0 ) ;
if ( V_123 == V_2 -> V_12 )
V_2 -> V_67 = F_70 ( V_87 ) ;
V_6 = F_57 ( V_5 , V_2 , V_15 ,
V_11 ,
V_124 ,
V_2 -> V_126 ,
V_87 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_105;
}
V_2 -> V_126 += V_123 ;
V_2 -> V_95 += V_123 ;
V_11 += V_124 ;
V_5 -> V_23 += V_124 ;
V_2 -> V_12 -= V_123 ;
V_133:
F_9 ( V_2 -> V_95 > V_2 -> V_96 ) ;
if ( V_2 -> V_95 == V_2 -> V_96 )
break;
}
F_31 ( V_15 ) ;
}
V_105:
return V_6 ;
}
static inline int F_71 ( struct V_5 * V_5 )
{
int V_77 ;
unsigned long V_30 ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_77 = -- V_5 -> V_45 ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
return V_77 ;
}
static inline T_1
F_72 ( struct V_134 * V_28 , struct V_32 * V_32 ,
struct V_51 * V_52 , struct V_135 * V_7 ,
T_2 V_19 , T_5 V_100 , T_6 V_27 ,
T_7 V_64 , int V_30 )
{
unsigned V_92 = F_73 ( V_32 -> V_92 ) ;
unsigned V_93 = V_92 ;
unsigned V_136 = ( 1 << V_93 ) - 1 ;
T_1 V_137 = - V_138 ;
T_4 V_139 = F_74 ( V_7 ) ;
T_2 V_121 = V_19 + V_139 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
struct V_86 V_87 = { 0 , } ;
struct V_140 V_141 ;
unsigned long V_142 = V_19 | F_75 ( V_7 ) ;
if ( V_142 & V_136 ) {
if ( V_52 )
V_93 = F_76 ( F_77 ( V_52 ) ) ;
V_136 = ( 1 << V_93 ) - 1 ;
if ( V_142 & V_136 )
goto V_105;
}
if ( F_78 ( V_7 ) == V_24 && ! F_74 ( V_7 ) )
return 0 ;
V_5 = F_79 ( V_36 , V_55 ) ;
V_137 = - V_85 ;
if ( ! V_5 )
goto V_105;
memset ( V_5 , 0 , F_80 ( struct V_5 , V_8 ) ) ;
V_5 -> V_30 = V_30 ;
if ( V_5 -> V_30 & V_143 ) {
if ( F_78 ( V_7 ) == V_24 ) {
struct V_144 * V_145 =
V_28 -> V_34 -> V_146 ;
F_81 ( V_32 ) ;
V_137 = F_82 ( V_145 , V_19 ,
V_121 - 1 ) ;
if ( V_137 ) {
F_83 ( V_32 ) ;
F_13 ( V_36 , V_5 ) ;
goto V_105;
}
}
}
V_5 -> V_25 = F_50 ( V_32 ) ;
if ( F_78 ( V_7 ) == V_24 && V_19 >= V_5 -> V_25 ) {
if ( V_5 -> V_30 & V_143 )
F_83 ( V_32 ) ;
F_13 ( V_36 , V_5 ) ;
V_137 = 0 ;
goto V_105;
}
if ( F_84 ( V_28 ) )
V_5 -> V_20 = false ;
else if ( ! ( V_5 -> V_30 & V_147 ) &&
F_78 ( V_7 ) == V_14 && V_121 > F_50 ( V_32 ) )
V_5 -> V_20 = false ;
else
V_5 -> V_20 = true ;
V_5 -> V_32 = V_32 ;
V_5 -> V_13 = F_78 ( V_7 ) == V_14 ? V_148 : V_24 ;
if ( V_5 -> V_20 && F_78 ( V_7 ) == V_14 &&
( ( V_28 -> V_34 -> V_149 & V_150 ) ||
F_85 ( V_28 -> V_34 -> V_146 -> V_151 ) ) ) {
V_137 = F_48 ( V_5 ) ;
if ( V_137 ) {
F_13 ( V_36 , V_5 ) ;
goto V_105;
}
}
if ( ! ( V_5 -> V_30 & V_31 ) )
F_86 ( V_32 ) ;
V_137 = 0 ;
V_2 . V_93 = V_93 ;
V_2 . V_94 = V_92 - V_93 ;
V_2 . V_95 = V_19 >> V_93 ;
V_2 . V_100 = V_100 ;
V_5 -> V_27 = V_27 ;
V_2 . V_64 = V_64 ;
V_2 . V_112 = - 1 ;
V_2 . V_126 = - 1 ;
V_5 -> V_28 = V_28 ;
F_87 ( & V_5 -> V_44 ) ;
V_5 -> V_45 = 1 ;
V_5 -> V_62 = ( V_7 -> type == V_152 ) ;
V_2 . V_7 = V_7 ;
V_2 . V_96 =
( V_19 + F_74 ( V_7 ) ) >> V_93 ;
if ( F_69 ( V_2 . V_94 ) )
V_2 . V_106 = 2 ;
V_2 . V_106 += F_88 ( V_7 , V_153 ) ;
F_89 ( & V_141 ) ;
V_137 = F_63 ( V_5 , & V_2 , & V_87 ) ;
if ( V_137 )
F_30 ( V_5 , & V_2 ) ;
if ( V_137 == - V_132 ) {
V_137 = 0 ;
}
F_61 ( V_5 , & V_2 , 1 , & V_87 ) ;
if ( V_2 . V_109 ) {
T_1 V_77 ;
V_77 = F_56 ( V_5 , & V_2 , & V_87 ) ;
if ( V_137 == 0 )
V_137 = V_77 ;
F_31 ( V_2 . V_109 ) ;
V_2 . V_109 = NULL ;
}
if ( V_2 . V_41 )
F_27 ( V_5 , & V_2 ) ;
F_90 ( & V_141 ) ;
F_30 ( V_5 , & V_2 ) ;
if ( F_78 ( V_7 ) == V_24 && ( V_5 -> V_30 & V_143 ) )
F_83 ( V_5 -> V_32 ) ;
F_9 ( V_137 == - V_22 ) ;
if ( V_5 -> V_20 && V_137 == 0 && V_5 -> V_23 &&
( F_78 ( V_7 ) == V_24 || V_5 -> V_23 == V_139 ) )
V_137 = - V_22 ;
else
F_42 ( V_5 ) ;
if ( F_71 ( V_5 ) == 0 ) {
V_137 = F_10 ( V_5 , V_19 , V_137 , false ) ;
} else
F_9 ( V_137 != - V_22 ) ;
V_105:
return V_137 ;
}
T_1 F_91 ( struct V_134 * V_28 , struct V_32 * V_32 ,
struct V_51 * V_52 , struct V_135 * V_7 ,
T_2 V_19 , T_5 V_100 ,
T_6 V_27 , T_7 V_64 ,
int V_30 )
{
F_92 ( & V_52 -> V_154 -> V_155 ) ;
F_92 ( V_52 -> V_156 ) ;
F_92 ( ( char * ) V_52 -> V_156 + V_157 ) ;
return F_72 ( V_28 , V_32 , V_52 , V_7 , V_19 , V_100 ,
V_27 , V_64 , V_30 ) ;
}
static T_8 int F_93 ( void )
{
V_36 = F_94 ( V_5 , V_158 ) ;
return 0 ;
}
