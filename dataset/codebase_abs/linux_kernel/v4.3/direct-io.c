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
struct V_66 * V_67 ;
unsigned V_68 ;
int V_33 ;
if ( V_41 -> V_69 )
V_5 -> V_26 = - V_70 ;
if ( V_5 -> V_20 && V_5 -> V_13 == V_24 ) {
F_35 ( V_41 ) ;
V_33 = V_41 -> V_69 ;
} else {
F_36 (bvec, bio, i) {
struct V_15 * V_15 = V_67 -> V_71 ;
if ( V_5 -> V_13 == V_24 && ! F_37 ( V_15 ) )
F_38 ( V_15 ) ;
F_31 ( V_15 ) ;
}
V_33 = V_41 -> V_69 ;
F_39 ( V_41 ) ;
}
return V_33 ;
}
static void F_40 ( struct V_5 * V_5 )
{
struct V_41 * V_41 ;
do {
V_41 = F_32 ( V_5 ) ;
if ( V_41 )
F_17 ( V_5 , V_41 ) ;
} while ( V_41 );
}
static inline int F_41 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_72 ++ >= 64 ) {
while ( V_5 -> V_50 ) {
unsigned long V_30 ;
struct V_41 * V_41 ;
int V_73 ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_41 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 -> V_42 ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
V_73 = F_17 ( V_5 , V_41 ) ;
if ( V_6 == 0 )
V_6 = V_73 ;
}
V_2 -> V_72 = 0 ;
}
return V_6 ;
}
static int F_42 ( struct V_74 * V_75 )
{
struct V_76 * V_77 ;
struct V_76 * V_78 = F_43 ( L_1 ,
V_79 , 0 ,
V_75 -> V_80 ) ;
if ( ! V_78 )
return - V_81 ;
V_77 = F_44 ( & V_75 -> V_49 , NULL , V_78 ) ;
if ( V_77 )
F_45 ( V_78 ) ;
return 0 ;
}
static int F_46 ( struct V_5 * V_5 )
{
struct V_74 * V_75 = V_5 -> V_32 -> V_48 ;
if ( V_5 -> V_47 )
return 0 ;
V_5 -> V_47 = true ;
if ( ! V_75 -> V_49 )
return F_42 ( V_75 ) ;
return 0 ;
}
static int F_47 ( struct V_5 * V_5 , struct V_1 * V_2 ,
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
if ( V_5 -> V_30 & V_95 ) {
if ( V_2 -> V_91 < ( F_48 ( V_5 -> V_32 ) >>
V_2 -> V_89 ) )
V_87 = 0 ;
}
V_6 = (* V_2 -> V_96 )( V_5 -> V_32 , V_84 ,
V_83 , V_87 ) ;
V_5 -> V_29 = V_83 -> V_97 ;
if ( V_6 == 0 && F_49 ( V_83 ) )
V_6 = F_46 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_50 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_98 , struct V_82 * V_83 )
{
T_3 V_99 ;
int V_6 , V_100 ;
V_6 = F_41 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_101;
V_99 = V_98 << ( V_2 -> V_89 - 9 ) ;
V_100 = F_51 ( V_2 -> V_102 , V_103 ) ;
F_9 ( V_100 <= 0 ) ;
F_25 ( V_5 , V_2 , V_83 -> V_104 , V_99 , V_100 ) ;
V_2 -> V_63 = 0 ;
V_101:
return V_6 ;
}
static inline int F_52 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_53 ( V_2 -> V_41 , V_2 -> V_105 ,
V_2 -> V_106 , V_2 -> V_107 ) ;
if ( V_6 == V_2 -> V_106 ) {
if ( ( V_2 -> V_106 + V_2 -> V_107 ) == V_18 )
V_2 -> V_102 -- ;
F_5 ( V_2 -> V_105 ) ;
V_2 -> V_108 = V_2 -> V_109 +
( V_2 -> V_106 >> V_2 -> V_89 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_54 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_82 * V_83 )
{
int V_6 = 0 ;
if ( V_2 -> V_41 ) {
T_2 V_110 = V_2 -> V_61 ;
T_2 V_111 = V_2 -> V_60 +
V_2 -> V_41 -> V_57 . V_112 ;
if ( V_2 -> V_108 != V_2 -> V_109 ||
V_110 != V_111 )
F_27 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_41 == NULL ) {
V_6 = F_50 ( V_5 , V_2 , V_2 -> V_109 , V_83 ) ;
if ( V_6 )
goto V_101;
}
if ( F_52 ( V_2 ) != 0 ) {
F_27 ( V_5 , V_2 ) ;
V_6 = F_50 ( V_5 , V_2 , V_2 -> V_109 , V_83 ) ;
if ( V_6 == 0 ) {
V_6 = F_52 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_101:
return V_6 ;
}
static inline int
F_55 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned V_19 , unsigned V_113 , T_3 V_114 ,
struct V_82 * V_83 )
{
int V_6 = 0 ;
if ( V_5 -> V_13 & V_14 ) {
F_56 ( V_113 ) ;
}
if ( V_2 -> V_105 == V_15 &&
V_2 -> V_107 + V_2 -> V_106 == V_19 &&
V_2 -> V_109 +
( V_2 -> V_106 >> V_2 -> V_89 ) == V_114 ) {
V_2 -> V_106 += V_113 ;
goto V_101;
}
if ( V_2 -> V_105 ) {
V_6 = F_54 ( V_5 , V_2 , V_83 ) ;
F_31 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
if ( V_6 )
return V_6 ;
}
F_5 ( V_15 ) ;
V_2 -> V_105 = V_15 ;
V_2 -> V_107 = V_19 ;
V_2 -> V_106 = V_113 ;
V_2 -> V_109 = V_114 ;
V_2 -> V_61 = V_2 -> V_91 << V_2 -> V_89 ;
V_101:
if ( V_2 -> V_63 ) {
V_6 = F_54 ( V_5 , V_2 , V_83 ) ;
F_27 ( V_5 , V_2 ) ;
F_31 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
}
return V_6 ;
}
static void F_57 ( struct V_5 * V_5 , struct V_82 * V_83 )
{
unsigned V_68 ;
unsigned V_115 ;
V_115 = V_83 -> V_94 >> V_5 -> V_32 -> V_88 ;
for ( V_68 = 0 ; V_68 < V_115 ; V_68 ++ ) {
F_58 ( V_83 -> V_104 ,
V_83 -> V_116 + V_68 ) ;
}
}
static inline void F_59 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_117 , struct V_82 * V_83 )
{
unsigned V_118 ;
unsigned V_119 ;
unsigned V_120 ;
struct V_15 * V_15 ;
V_2 -> V_121 = 1 ;
if ( ! V_2 -> V_90 || ! F_60 ( V_83 ) )
return;
V_118 = 1 << V_2 -> V_90 ;
V_119 = V_2 -> V_91 & ( V_118 - 1 ) ;
if ( ! V_119 )
return;
if ( V_117 )
V_119 = V_118 - V_119 ;
V_120 = V_119 << V_2 -> V_89 ;
V_15 = F_4 ( 0 ) ;
if ( F_55 ( V_5 , V_2 , V_15 , 0 , V_120 ,
V_2 -> V_122 , V_83 ) )
return;
V_2 -> V_122 += V_119 ;
}
static int F_61 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_82 * V_83 )
{
const unsigned V_89 = V_2 -> V_89 ;
int V_6 = 0 ;
while ( V_2 -> V_91 < V_2 -> V_92 ) {
struct V_15 * V_15 ;
T_4 V_11 , V_17 ;
V_15 = F_7 ( V_5 , V_2 ) ;
if ( F_62 ( V_15 ) ) {
V_6 = F_63 ( V_15 ) ;
goto V_101;
}
V_11 = V_2 -> V_4 ? 0 : V_2 -> V_11 ;
V_17 = ( V_2 -> V_4 == V_2 -> V_3 - 1 ) ? V_2 -> V_17 : V_18 ;
V_2 -> V_4 ++ ;
while ( V_11 < V_17 ) {
unsigned V_120 ;
unsigned V_119 ;
unsigned V_123 ;
if ( V_2 -> V_12 == 0 ) {
unsigned long V_124 ;
unsigned long V_125 ;
V_6 = F_47 ( V_5 , V_2 , V_83 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_101;
}
if ( ! F_64 ( V_83 ) )
goto V_126;
V_2 -> V_12 =
V_83 -> V_94 >> V_2 -> V_89 ;
V_2 -> V_122 =
V_83 -> V_116 << V_2 -> V_90 ;
if ( F_60 ( V_83 ) )
F_57 ( V_5 , V_83 ) ;
if ( ! V_2 -> V_90 )
goto V_126;
V_124 = ( 1 << V_2 -> V_90 ) - 1 ;
V_125 = ( V_2 -> V_91 & V_124 ) ;
if ( ! F_60 ( V_83 ) )
V_2 -> V_122 += V_125 ;
V_2 -> V_12 -= V_125 ;
}
V_126:
if ( ! F_64 ( V_83 ) ) {
T_2 V_127 ;
if ( V_5 -> V_13 & V_14 ) {
F_31 ( V_15 ) ;
return - V_128 ;
}
V_127 = F_65 ( F_48 ( V_5 -> V_32 ) ,
1 << V_89 ) ;
if ( V_2 -> V_91 >=
V_127 >> V_89 ) {
F_31 ( V_15 ) ;
goto V_101;
}
F_66 ( V_15 , V_11 , 1 << V_89 ) ;
V_2 -> V_91 ++ ;
V_11 += 1 << V_89 ;
V_5 -> V_23 += 1 << V_89 ;
goto V_129;
}
if ( F_67 ( V_2 -> V_90 && ! V_2 -> V_121 ) )
F_59 ( V_5 , V_2 , 0 , V_83 ) ;
V_119 = V_2 -> V_12 ;
V_123 = ( V_17 - V_11 ) >> V_89 ;
if ( V_119 > V_123 )
V_119 = V_123 ;
V_123 = V_2 -> V_92 - V_2 -> V_91 ;
if ( V_119 > V_123 )
V_119 = V_123 ;
V_120 = V_119 << V_89 ;
F_9 ( V_120 == 0 ) ;
if ( V_119 == V_2 -> V_12 )
V_2 -> V_63 = F_68 ( V_83 ) ;
V_6 = F_55 ( V_5 , V_2 , V_15 ,
V_11 ,
V_120 ,
V_2 -> V_122 ,
V_83 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_101;
}
V_2 -> V_122 += V_119 ;
V_2 -> V_91 += V_119 ;
V_11 += V_120 ;
V_5 -> V_23 += V_120 ;
V_2 -> V_12 -= V_119 ;
V_129:
F_9 ( V_2 -> V_91 > V_2 -> V_92 ) ;
if ( V_2 -> V_91 == V_2 -> V_92 )
break;
}
F_31 ( V_15 ) ;
}
V_101:
return V_6 ;
}
static inline int F_69 ( struct V_5 * V_5 )
{
int V_73 ;
unsigned long V_30 ;
F_18 ( & V_5 -> V_44 , V_30 ) ;
V_73 = -- V_5 -> V_45 ;
F_20 ( & V_5 -> V_44 , V_30 ) ;
return V_73 ;
}
static inline T_1
F_70 ( struct V_130 * V_28 , struct V_32 * V_32 ,
struct V_51 * V_52 , struct V_131 * V_7 ,
T_2 V_19 , T_5 V_96 , T_6 V_27 ,
T_7 V_62 , int V_30 )
{
unsigned V_88 = F_71 ( V_32 -> V_88 ) ;
unsigned V_89 = V_88 ;
unsigned V_132 = ( 1 << V_89 ) - 1 ;
T_1 V_133 = - V_134 ;
T_4 V_135 = F_72 ( V_7 ) ;
T_2 V_117 = V_19 + V_135 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
struct V_82 V_83 = { 0 , } ;
struct V_136 V_137 ;
unsigned long V_138 = V_19 | F_73 ( V_7 ) ;
if ( V_138 & V_132 ) {
if ( V_52 )
V_89 = F_74 ( F_75 ( V_52 ) ) ;
V_132 = ( 1 << V_89 ) - 1 ;
if ( V_138 & V_132 )
goto V_101;
}
if ( F_76 ( V_7 ) == V_24 && ! F_72 ( V_7 ) )
return 0 ;
V_5 = F_77 ( V_36 , V_55 ) ;
V_133 = - V_81 ;
if ( ! V_5 )
goto V_101;
memset ( V_5 , 0 , F_78 ( struct V_5 , V_8 ) ) ;
V_5 -> V_30 = V_30 ;
if ( V_5 -> V_30 & V_139 ) {
if ( F_76 ( V_7 ) == V_24 ) {
struct V_140 * V_141 =
V_28 -> V_34 -> V_142 ;
F_79 ( & V_32 -> V_143 ) ;
V_133 = F_80 ( V_141 , V_19 ,
V_117 - 1 ) ;
if ( V_133 ) {
F_81 ( & V_32 -> V_143 ) ;
F_13 ( V_36 , V_5 ) ;
goto V_101;
}
}
}
if ( F_82 ( V_28 ) )
V_5 -> V_20 = false ;
else if ( ! ( V_5 -> V_30 & V_144 ) &&
F_76 ( V_7 ) == V_14 && V_117 > F_48 ( V_32 ) )
V_5 -> V_20 = false ;
else
V_5 -> V_20 = true ;
V_5 -> V_32 = V_32 ;
V_5 -> V_13 = F_76 ( V_7 ) == V_14 ? V_145 : V_24 ;
if ( V_5 -> V_20 && F_76 ( V_7 ) == V_14 &&
( ( V_28 -> V_34 -> V_146 & V_147 ) ||
F_83 ( V_28 -> V_34 -> V_142 -> V_148 ) ) ) {
V_133 = F_46 ( V_5 ) ;
if ( V_133 ) {
F_13 ( V_36 , V_5 ) ;
goto V_101;
}
}
if ( ! ( V_5 -> V_30 & V_31 ) )
F_84 ( V_32 ) ;
V_133 = 0 ;
V_2 . V_89 = V_89 ;
V_2 . V_90 = V_88 - V_89 ;
V_2 . V_91 = V_19 >> V_89 ;
V_2 . V_96 = V_96 ;
V_5 -> V_27 = V_27 ;
V_2 . V_62 = V_62 ;
V_2 . V_108 = - 1 ;
V_2 . V_122 = - 1 ;
V_5 -> V_28 = V_28 ;
V_5 -> V_25 = F_48 ( V_32 ) ;
F_85 ( & V_5 -> V_44 ) ;
V_5 -> V_45 = 1 ;
V_2 . V_7 = V_7 ;
V_2 . V_92 =
( V_19 + F_72 ( V_7 ) ) >> V_89 ;
if ( F_67 ( V_2 . V_90 ) )
V_2 . V_102 = 2 ;
V_2 . V_102 += F_86 ( V_7 , V_149 ) ;
F_87 ( & V_137 ) ;
V_133 = F_61 ( V_5 , & V_2 , & V_83 ) ;
if ( V_133 )
F_30 ( V_5 , & V_2 ) ;
if ( V_133 == - V_128 ) {
V_133 = 0 ;
}
F_59 ( V_5 , & V_2 , 1 , & V_83 ) ;
if ( V_2 . V_105 ) {
T_1 V_73 ;
V_73 = F_54 ( V_5 , & V_2 , & V_83 ) ;
if ( V_133 == 0 )
V_133 = V_73 ;
F_31 ( V_2 . V_105 ) ;
V_2 . V_105 = NULL ;
}
if ( V_2 . V_41 )
F_27 ( V_5 , & V_2 ) ;
F_88 ( & V_137 ) ;
F_30 ( V_5 , & V_2 ) ;
if ( F_76 ( V_7 ) == V_24 && ( V_5 -> V_30 & V_139 ) )
F_81 ( & V_5 -> V_32 -> V_143 ) ;
F_9 ( V_133 == - V_22 ) ;
if ( V_5 -> V_20 && V_133 == 0 && V_5 -> V_23 &&
( F_76 ( V_7 ) == V_24 || V_5 -> V_23 == V_135 ) )
V_133 = - V_22 ;
else
F_40 ( V_5 ) ;
if ( F_69 ( V_5 ) == 0 ) {
V_133 = F_10 ( V_5 , V_19 , V_133 , false ) ;
} else
F_9 ( V_133 != - V_22 ) ;
V_101:
return V_133 ;
}
T_1 F_89 ( struct V_130 * V_28 , struct V_32 * V_32 ,
struct V_51 * V_52 , struct V_131 * V_7 ,
T_2 V_19 , T_5 V_96 ,
T_6 V_27 , T_7 V_62 ,
int V_30 )
{
F_90 ( & V_52 -> V_150 -> V_151 ) ;
F_90 ( V_52 -> V_152 ) ;
F_90 ( ( char * ) V_52 -> V_152 + V_153 ) ;
return F_70 ( V_28 , V_32 , V_52 , V_7 , V_19 , V_96 ,
V_27 , V_62 , V_30 ) ;
}
static T_8 int F_91 ( void )
{
V_36 = F_92 ( V_5 , V_154 ) ;
return 0 ;
}
