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
F_11 ( V_5 -> V_30 ) ;
if ( V_20 ) {
if ( V_5 -> V_13 & V_14 ) {
int V_31 ;
V_31 = F_12 ( V_5 -> V_28 -> V_32 , V_19 ,
V_21 ) ;
if ( V_31 < 0 && V_6 > 0 )
V_6 = V_31 ;
}
F_13 ( V_5 -> V_28 , V_6 , 0 ) ;
}
F_14 ( V_33 , V_5 ) ;
return V_6 ;
}
static void F_15 ( struct V_34 * V_35 )
{
struct V_5 * V_5 = F_16 ( V_35 , struct V_5 , V_36 ) ;
F_10 ( V_5 , V_5 -> V_28 -> V_37 , 0 , true ) ;
}
static void F_17 ( struct V_38 * V_38 , int error )
{
struct V_5 * V_5 = V_38 -> V_39 ;
unsigned long V_40 ;
unsigned long V_41 ;
F_18 ( V_5 , V_38 ) ;
F_19 ( & V_5 -> V_42 , V_41 ) ;
V_40 = -- V_5 -> V_43 ;
if ( V_40 == 1 && V_5 -> V_44 )
F_20 ( V_5 -> V_44 ) ;
F_21 ( & V_5 -> V_42 , V_41 ) ;
if ( V_40 == 0 ) {
if ( V_5 -> V_23 && V_5 -> V_45 ) {
F_22 ( & V_5 -> V_36 , F_15 ) ;
F_23 ( V_5 -> V_30 -> V_46 -> V_47 ,
& V_5 -> V_36 ) ;
} else {
F_10 ( V_5 , V_5 -> V_28 -> V_37 , 0 , true ) ;
}
}
}
static void F_24 ( struct V_38 * V_38 , int error )
{
struct V_5 * V_5 = V_38 -> V_39 ;
unsigned long V_41 ;
F_19 ( & V_5 -> V_42 , V_41 ) ;
V_38 -> V_39 = V_5 -> V_48 ;
V_5 -> V_48 = V_38 ;
if ( -- V_5 -> V_43 == 1 && V_5 -> V_44 )
F_20 ( V_5 -> V_44 ) ;
F_21 ( & V_5 -> V_42 , V_41 ) ;
}
void F_25 ( struct V_38 * V_38 , int error )
{
struct V_5 * V_5 = V_38 -> V_39 ;
if ( V_5 -> V_20 )
F_17 ( V_38 , error ) ;
else
F_24 ( V_38 , error ) ;
}
static inline void
F_26 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_49 * V_50 ,
T_3 V_51 , int V_52 )
{
struct V_38 * V_38 ;
V_38 = F_27 ( V_53 , V_52 ) ;
V_38 -> V_54 = V_50 ;
V_38 -> V_55 . V_56 = V_51 ;
if ( V_5 -> V_20 )
V_38 -> V_57 = F_17 ;
else
V_38 -> V_57 = F_24 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_58 = V_2 -> V_59 ;
}
static inline void F_28 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
struct V_38 * V_38 = V_2 -> V_38 ;
unsigned long V_41 ;
V_38 -> V_39 = V_5 ;
F_19 ( & V_5 -> V_42 , V_41 ) ;
V_5 -> V_43 ++ ;
F_21 ( & V_5 -> V_42 , V_41 ) ;
if ( V_5 -> V_20 && V_5 -> V_13 == V_24 )
F_29 ( V_38 ) ;
if ( V_2 -> V_60 )
V_2 -> V_60 ( V_5 -> V_13 , V_38 , V_5 -> V_30 ,
V_2 -> V_58 ) ;
else
F_30 ( V_5 -> V_13 , V_38 ) ;
V_2 -> V_38 = NULL ;
V_2 -> V_61 = 0 ;
V_2 -> V_58 = 0 ;
}
static inline void F_31 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
while ( V_2 -> V_4 < V_2 -> V_3 )
F_32 ( V_5 -> V_8 [ V_2 -> V_4 ++ ] ) ;
}
static struct V_38 * F_33 ( struct V_5 * V_5 )
{
unsigned long V_41 ;
struct V_38 * V_38 = NULL ;
F_19 ( & V_5 -> V_42 , V_41 ) ;
while ( V_5 -> V_43 > 1 && V_5 -> V_48 == NULL ) {
F_34 ( V_62 ) ;
V_5 -> V_44 = V_63 ;
F_21 ( & V_5 -> V_42 , V_41 ) ;
F_35 () ;
F_19 ( & V_5 -> V_42 , V_41 ) ;
V_5 -> V_44 = NULL ;
}
if ( V_5 -> V_48 ) {
V_38 = V_5 -> V_48 ;
V_5 -> V_48 = V_38 -> V_39 ;
}
F_21 ( & V_5 -> V_42 , V_41 ) ;
return V_38 ;
}
static int F_18 ( struct V_5 * V_5 , struct V_38 * V_38 )
{
const int V_64 = F_36 ( V_65 , & V_38 -> V_66 ) ;
struct V_67 * V_68 ;
unsigned V_69 ;
if ( ! V_64 )
V_5 -> V_26 = - V_70 ;
if ( V_5 -> V_20 && V_5 -> V_13 == V_24 ) {
F_37 ( V_38 ) ;
} else {
F_38 (bvec, bio, i) {
struct V_15 * V_15 = V_68 -> V_71 ;
if ( V_5 -> V_13 == V_24 && ! F_39 ( V_15 ) )
F_40 ( V_15 ) ;
F_32 ( V_15 ) ;
}
F_41 ( V_38 ) ;
}
return V_64 ? 0 : - V_70 ;
}
static void F_42 ( struct V_5 * V_5 )
{
struct V_38 * V_38 ;
do {
V_38 = F_33 ( V_5 ) ;
if ( V_38 )
F_18 ( V_5 , V_38 ) ;
} while ( V_38 );
}
static inline int F_43 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_72 ++ >= 64 ) {
while ( V_5 -> V_48 ) {
unsigned long V_41 ;
struct V_38 * V_38 ;
int V_73 ;
F_19 ( & V_5 -> V_42 , V_41 ) ;
V_38 = V_5 -> V_48 ;
V_5 -> V_48 = V_38 -> V_39 ;
F_21 ( & V_5 -> V_42 , V_41 ) ;
V_73 = F_18 ( V_5 , V_38 ) ;
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
V_77 = F_46 ( & V_75 -> V_47 , NULL , V_78 ) ;
if ( V_77 )
F_47 ( V_78 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_5 )
{
struct V_74 * V_75 = V_5 -> V_30 -> V_46 ;
if ( V_5 -> V_45 )
return 0 ;
V_5 -> V_45 = true ;
if ( ! V_75 -> V_47 )
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
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_91 >= V_2 -> V_92 ) ;
V_84 = V_2 -> V_91 >> V_2 -> V_90 ;
V_85 = ( V_2 -> V_92 - 1 ) >>
V_2 -> V_90 ;
V_86 = V_85 - V_84 + 1 ;
V_83 -> V_93 = 0 ;
V_83 -> V_94 = V_86 << V_88 ;
V_87 = V_5 -> V_13 & V_14 ;
if ( V_5 -> V_41 & V_95 ) {
if ( V_2 -> V_91 < ( F_50 ( V_5 -> V_30 ) >>
V_2 -> V_89 ) )
V_87 = 0 ;
}
V_6 = (* V_2 -> V_96 )( V_5 -> V_30 , V_84 ,
V_83 , V_87 ) ;
V_5 -> V_29 = V_83 -> V_97 ;
if ( V_6 == 0 && F_51 ( V_83 ) )
V_6 = F_48 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_52 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_98 , struct V_82 * V_83 )
{
T_3 V_99 ;
int V_6 , V_100 ;
V_6 = F_43 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_101;
V_99 = V_98 << ( V_2 -> V_89 - 9 ) ;
V_100 = F_53 ( V_2 -> V_102 , F_54 ( V_83 -> V_103 ) ) ;
F_9 ( V_100 <= 0 ) ;
F_26 ( V_5 , V_2 , V_83 -> V_103 , V_99 , V_100 ) ;
V_2 -> V_61 = 0 ;
V_101:
return V_6 ;
}
static inline int F_55 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_56 ( V_2 -> V_38 , V_2 -> V_104 ,
V_2 -> V_105 , V_2 -> V_106 ) ;
if ( V_6 == V_2 -> V_105 ) {
if ( ( V_2 -> V_105 + V_2 -> V_106 ) == V_18 )
V_2 -> V_102 -- ;
F_5 ( V_2 -> V_104 ) ;
V_2 -> V_107 = V_2 -> V_108 +
( V_2 -> V_105 >> V_2 -> V_89 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_57 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_82 * V_83 )
{
int V_6 = 0 ;
if ( V_2 -> V_38 ) {
T_2 V_109 = V_2 -> V_59 ;
T_2 V_110 = V_2 -> V_58 +
V_2 -> V_38 -> V_55 . V_111 ;
if ( V_2 -> V_107 != V_2 -> V_108 ||
V_109 != V_110 )
F_28 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_38 == NULL ) {
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_108 , V_83 ) ;
if ( V_6 )
goto V_101;
}
if ( F_55 ( V_2 ) != 0 ) {
F_28 ( V_5 , V_2 ) ;
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_108 , V_83 ) ;
if ( V_6 == 0 ) {
V_6 = F_55 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_101:
return V_6 ;
}
static inline int
F_58 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned V_19 , unsigned V_112 , T_3 V_113 ,
struct V_82 * V_83 )
{
int V_6 = 0 ;
if ( V_5 -> V_13 & V_14 ) {
F_59 ( V_112 ) ;
}
if ( V_2 -> V_104 == V_15 &&
V_2 -> V_106 + V_2 -> V_105 == V_19 &&
V_2 -> V_108 +
( V_2 -> V_105 >> V_2 -> V_89 ) == V_113 ) {
V_2 -> V_105 += V_112 ;
goto V_101;
}
if ( V_2 -> V_104 ) {
V_6 = F_57 ( V_5 , V_2 , V_83 ) ;
F_32 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
if ( V_6 )
return V_6 ;
}
F_5 ( V_15 ) ;
V_2 -> V_104 = V_15 ;
V_2 -> V_106 = V_19 ;
V_2 -> V_105 = V_112 ;
V_2 -> V_108 = V_113 ;
V_2 -> V_59 = V_2 -> V_91 << V_2 -> V_89 ;
V_101:
if ( V_2 -> V_61 ) {
V_6 = F_57 ( V_5 , V_2 , V_83 ) ;
F_28 ( V_5 , V_2 ) ;
F_32 ( V_2 -> V_104 ) ;
V_2 -> V_104 = NULL ;
}
return V_6 ;
}
static void F_60 ( struct V_5 * V_5 , struct V_82 * V_83 )
{
unsigned V_69 ;
unsigned V_114 ;
V_114 = V_83 -> V_94 >> V_5 -> V_30 -> V_88 ;
for ( V_69 = 0 ; V_69 < V_114 ; V_69 ++ ) {
F_61 ( V_83 -> V_103 ,
V_83 -> V_115 + V_69 ) ;
}
}
static inline void F_62 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_116 , struct V_82 * V_83 )
{
unsigned V_117 ;
unsigned V_118 ;
unsigned V_119 ;
struct V_15 * V_15 ;
V_2 -> V_120 = 1 ;
if ( ! V_2 -> V_90 || ! F_63 ( V_83 ) )
return;
V_117 = 1 << V_2 -> V_90 ;
V_118 = V_2 -> V_91 & ( V_117 - 1 ) ;
if ( ! V_118 )
return;
if ( V_116 )
V_118 = V_117 - V_118 ;
V_119 = V_118 << V_2 -> V_89 ;
V_15 = F_4 ( 0 ) ;
if ( F_58 ( V_5 , V_2 , V_15 , 0 , V_119 ,
V_2 -> V_121 , V_83 ) )
return;
V_2 -> V_121 += V_118 ;
}
static int F_64 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_82 * V_83 )
{
const unsigned V_89 = V_2 -> V_89 ;
int V_6 = 0 ;
while ( V_2 -> V_91 < V_2 -> V_92 ) {
struct V_15 * V_15 ;
T_4 V_11 , V_17 ;
V_15 = F_7 ( V_5 , V_2 ) ;
if ( F_65 ( V_15 ) ) {
V_6 = F_66 ( V_15 ) ;
goto V_101;
}
V_11 = V_2 -> V_4 ? 0 : V_2 -> V_11 ;
V_17 = ( V_2 -> V_4 == V_2 -> V_3 - 1 ) ? V_2 -> V_17 : V_18 ;
V_2 -> V_4 ++ ;
while ( V_11 < V_17 ) {
unsigned V_119 ;
unsigned V_118 ;
unsigned V_122 ;
if ( V_2 -> V_12 == 0 ) {
unsigned long V_123 ;
unsigned long V_124 ;
V_6 = F_49 ( V_5 , V_2 , V_83 ) ;
if ( V_6 ) {
F_32 ( V_15 ) ;
goto V_101;
}
if ( ! F_67 ( V_83 ) )
goto V_125;
V_2 -> V_12 =
V_83 -> V_94 >> V_2 -> V_89 ;
V_2 -> V_121 =
V_83 -> V_115 << V_2 -> V_90 ;
if ( F_63 ( V_83 ) )
F_60 ( V_5 , V_83 ) ;
if ( ! V_2 -> V_90 )
goto V_125;
V_123 = ( 1 << V_2 -> V_90 ) - 1 ;
V_124 = ( V_2 -> V_91 & V_123 ) ;
if ( ! F_63 ( V_83 ) )
V_2 -> V_121 += V_124 ;
V_2 -> V_12 -= V_124 ;
}
V_125:
if ( ! F_67 ( V_83 ) ) {
T_2 V_126 ;
if ( V_5 -> V_13 & V_14 ) {
F_32 ( V_15 ) ;
return - V_127 ;
}
V_126 = F_68 ( F_50 ( V_5 -> V_30 ) ,
1 << V_89 ) ;
if ( V_2 -> V_91 >=
V_126 >> V_89 ) {
F_32 ( V_15 ) ;
goto V_101;
}
F_69 ( V_15 , V_11 , 1 << V_89 ) ;
V_2 -> V_91 ++ ;
V_11 += 1 << V_89 ;
V_5 -> V_23 += 1 << V_89 ;
goto V_128;
}
if ( F_70 ( V_2 -> V_90 && ! V_2 -> V_120 ) )
F_62 ( V_5 , V_2 , 0 , V_83 ) ;
V_118 = V_2 -> V_12 ;
V_122 = ( V_17 - V_11 ) >> V_89 ;
if ( V_118 > V_122 )
V_118 = V_122 ;
V_122 = V_2 -> V_92 - V_2 -> V_91 ;
if ( V_118 > V_122 )
V_118 = V_122 ;
V_119 = V_118 << V_89 ;
F_9 ( V_119 == 0 ) ;
if ( V_118 == V_2 -> V_12 )
V_2 -> V_61 = F_71 ( V_83 ) ;
V_6 = F_58 ( V_5 , V_2 , V_15 ,
V_11 ,
V_119 ,
V_2 -> V_121 ,
V_83 ) ;
if ( V_6 ) {
F_32 ( V_15 ) ;
goto V_101;
}
V_2 -> V_121 += V_118 ;
V_2 -> V_91 += V_118 ;
V_11 += V_119 ;
V_5 -> V_23 += V_119 ;
V_2 -> V_12 -= V_118 ;
V_128:
F_9 ( V_2 -> V_91 > V_2 -> V_92 ) ;
if ( V_2 -> V_91 == V_2 -> V_92 )
break;
}
F_32 ( V_15 ) ;
}
V_101:
return V_6 ;
}
static inline int F_72 ( struct V_5 * V_5 )
{
int V_73 ;
unsigned long V_41 ;
F_19 ( & V_5 -> V_42 , V_41 ) ;
V_73 = -- V_5 -> V_43 ;
F_21 ( & V_5 -> V_42 , V_41 ) ;
return V_73 ;
}
static inline T_1
F_73 ( int V_13 , struct V_129 * V_28 , struct V_30 * V_30 ,
struct V_49 * V_50 , struct V_130 * V_7 , T_2 V_19 ,
T_5 V_96 , T_6 V_27 ,
T_7 V_60 , int V_41 )
{
unsigned V_88 = F_74 ( V_30 -> V_88 ) ;
unsigned V_89 = V_88 ;
unsigned V_131 = ( 1 << V_89 ) - 1 ;
T_1 V_132 = - V_133 ;
T_4 V_134 = F_75 ( V_7 ) ;
T_2 V_116 = V_19 + V_134 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
struct V_82 V_83 = { 0 , } ;
struct V_135 V_136 ;
unsigned long V_137 = V_19 | F_76 ( V_7 ) ;
if ( V_13 & V_14 )
V_13 = V_138 ;
if ( V_137 & V_131 ) {
if ( V_50 )
V_89 = F_77 ( F_78 ( V_50 ) ) ;
V_131 = ( 1 << V_89 ) - 1 ;
if ( V_137 & V_131 )
goto V_101;
}
if ( V_13 == V_24 && ! F_75 ( V_7 ) )
return 0 ;
V_5 = F_79 ( V_33 , V_53 ) ;
V_132 = - V_81 ;
if ( ! V_5 )
goto V_101;
memset ( V_5 , 0 , F_80 ( struct V_5 , V_8 ) ) ;
V_5 -> V_41 = V_41 ;
if ( V_5 -> V_41 & V_139 ) {
if ( V_13 == V_24 ) {
struct V_140 * V_141 =
V_28 -> V_32 -> V_142 ;
F_81 ( & V_30 -> V_143 ) ;
V_132 = F_82 ( V_141 , V_19 ,
V_116 - 1 ) ;
if ( V_132 ) {
F_83 ( & V_30 -> V_143 ) ;
F_14 ( V_33 , V_5 ) ;
goto V_101;
}
}
}
if ( F_84 ( V_28 ) )
V_5 -> V_20 = false ;
else if ( ! ( V_5 -> V_41 & V_144 ) &&
( V_13 & V_14 ) && V_116 > F_50 ( V_30 ) )
V_5 -> V_20 = false ;
else
V_5 -> V_20 = true ;
V_5 -> V_30 = V_30 ;
V_5 -> V_13 = V_13 ;
if ( V_5 -> V_20 && ( V_13 & V_14 ) &&
( ( V_28 -> V_32 -> V_145 & V_146 ) ||
F_85 ( V_28 -> V_32 -> V_142 -> V_147 ) ) ) {
V_132 = F_48 ( V_5 ) ;
if ( V_132 ) {
F_14 ( V_33 , V_5 ) ;
goto V_101;
}
}
F_86 ( & V_30 -> V_148 ) ;
V_132 = 0 ;
V_2 . V_89 = V_89 ;
V_2 . V_90 = V_88 - V_89 ;
V_2 . V_91 = V_19 >> V_89 ;
V_2 . V_96 = V_96 ;
V_5 -> V_27 = V_27 ;
V_2 . V_60 = V_60 ;
V_2 . V_107 = - 1 ;
V_2 . V_121 = - 1 ;
V_5 -> V_28 = V_28 ;
V_5 -> V_25 = F_50 ( V_30 ) ;
F_87 ( & V_5 -> V_42 ) ;
V_5 -> V_43 = 1 ;
V_2 . V_7 = V_7 ;
V_2 . V_92 =
( V_19 + F_75 ( V_7 ) ) >> V_89 ;
if ( F_70 ( V_2 . V_90 ) )
V_2 . V_102 = 2 ;
V_2 . V_102 += F_88 ( V_7 , V_149 ) ;
F_89 ( & V_136 ) ;
V_132 = F_64 ( V_5 , & V_2 , & V_83 ) ;
if ( V_132 )
F_31 ( V_5 , & V_2 ) ;
if ( V_132 == - V_127 ) {
V_132 = 0 ;
}
F_62 ( V_5 , & V_2 , 1 , & V_83 ) ;
if ( V_2 . V_104 ) {
T_1 V_73 ;
V_73 = F_57 ( V_5 , & V_2 , & V_83 ) ;
if ( V_132 == 0 )
V_132 = V_73 ;
F_32 ( V_2 . V_104 ) ;
V_2 . V_104 = NULL ;
}
if ( V_2 . V_38 )
F_28 ( V_5 , & V_2 ) ;
F_90 ( & V_136 ) ;
F_31 ( V_5 , & V_2 ) ;
if ( V_13 == V_24 && ( V_5 -> V_41 & V_139 ) )
F_83 ( & V_5 -> V_30 -> V_143 ) ;
F_9 ( V_132 == - V_22 ) ;
if ( V_5 -> V_20 && V_132 == 0 && V_5 -> V_23 &&
( V_13 == V_24 || V_5 -> V_23 == V_134 ) )
V_132 = - V_22 ;
else
F_42 ( V_5 ) ;
if ( F_72 ( V_5 ) == 0 ) {
V_132 = F_10 ( V_5 , V_19 , V_132 , false ) ;
} else
F_9 ( V_132 != - V_22 ) ;
V_101:
return V_132 ;
}
T_1
F_91 ( int V_13 , struct V_129 * V_28 , struct V_30 * V_30 ,
struct V_49 * V_50 , struct V_130 * V_7 , T_2 V_19 ,
T_5 V_96 , T_6 V_27 ,
T_7 V_60 , int V_41 )
{
F_92 ( & V_50 -> V_150 -> V_151 ) ;
F_92 ( V_50 -> V_152 ) ;
F_92 ( ( char * ) V_50 -> V_152 + V_153 ) ;
return F_73 ( V_13 , V_28 , V_30 , V_50 , V_7 , V_19 ,
V_96 , V_27 , V_60 , V_41 ) ;
}
static T_8 int F_93 ( void )
{
V_33 = F_94 ( V_5 , V_154 ) ;
return 0 ;
}
