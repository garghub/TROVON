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
static T_1 F_10 ( struct V_5 * V_5 , T_1 V_6 , bool V_19 )
{
T_2 V_20 = V_5 -> V_21 -> V_22 ;
T_1 V_23 = 0 ;
if ( V_6 == - V_24 )
V_6 = 0 ;
if ( V_5 -> V_25 ) {
V_23 = V_5 -> V_25 ;
if ( ( V_5 -> V_13 == V_26 ) && ( ( V_20 + V_23 ) > V_5 -> V_27 ) )
V_23 = V_5 -> V_27 - V_20 ;
}
if ( V_6 == 0 )
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 )
V_6 = V_5 -> V_28 ;
if ( V_6 == 0 )
V_6 = V_23 ;
if ( V_5 -> V_29 ) {
int V_30 ;
V_30 = V_5 -> V_29 ( V_5 -> V_21 , V_20 , V_6 , V_5 -> V_31 ) ;
if ( V_30 )
V_6 = V_30 ;
}
if ( ! ( V_5 -> V_32 & V_33 ) )
F_11 ( V_5 -> V_34 ) ;
if ( V_19 ) {
V_5 -> V_21 -> V_22 += V_23 ;
if ( V_5 -> V_13 & V_14 )
V_6 = F_12 ( V_5 -> V_21 , V_23 ) ;
V_5 -> V_21 -> V_35 ( V_5 -> V_21 , V_6 , 0 ) ;
}
F_13 ( V_36 , V_5 ) ;
return V_6 ;
}
static void F_14 ( struct V_37 * V_38 )
{
struct V_5 * V_5 = F_15 ( V_38 , struct V_5 , V_39 ) ;
F_10 ( V_5 , 0 , true ) ;
}
static void F_16 ( struct V_40 * V_40 )
{
struct V_5 * V_5 = V_40 -> V_41 ;
unsigned long V_42 ;
unsigned long V_32 ;
F_17 ( V_5 , V_40 ) ;
F_18 ( & V_5 -> V_43 , V_32 ) ;
V_42 = -- V_5 -> V_44 ;
if ( V_42 == 1 && V_5 -> V_45 )
F_19 ( V_5 -> V_45 ) ;
F_20 ( & V_5 -> V_43 , V_32 ) ;
if ( V_42 == 0 ) {
if ( V_5 -> V_25 && V_5 -> V_46 ) {
F_21 ( & V_5 -> V_39 , F_14 ) ;
F_22 ( V_5 -> V_34 -> V_47 -> V_48 ,
& V_5 -> V_39 ) ;
} else {
F_10 ( V_5 , 0 , true ) ;
}
}
}
static void F_23 ( struct V_40 * V_40 )
{
struct V_5 * V_5 = V_40 -> V_41 ;
unsigned long V_32 ;
F_18 ( & V_5 -> V_43 , V_32 ) ;
V_40 -> V_41 = V_5 -> V_49 ;
V_5 -> V_49 = V_40 ;
if ( -- V_5 -> V_44 == 1 && V_5 -> V_45 )
F_19 ( V_5 -> V_45 ) ;
F_20 ( & V_5 -> V_43 , V_32 ) ;
}
void F_24 ( struct V_40 * V_40 , int error )
{
struct V_5 * V_5 = V_40 -> V_41 ;
if ( V_5 -> V_19 )
F_16 ( V_40 ) ;
else
F_23 ( V_40 ) ;
}
static inline void
F_25 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_50 * V_51 ,
T_3 V_52 , int V_53 )
{
struct V_40 * V_40 ;
V_40 = F_26 ( V_54 , V_53 ) ;
V_40 -> V_55 = V_51 ;
V_40 -> V_56 . V_57 = V_52 ;
if ( V_5 -> V_19 )
V_40 -> V_58 = F_16 ;
else
V_40 -> V_58 = F_23 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_59 = V_2 -> V_60 ;
}
static inline void F_27 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
struct V_40 * V_40 = V_2 -> V_40 ;
unsigned long V_32 ;
V_40 -> V_41 = V_5 ;
F_18 ( & V_5 -> V_43 , V_32 ) ;
V_5 -> V_44 ++ ;
F_20 ( & V_5 -> V_43 , V_32 ) ;
if ( V_5 -> V_19 && V_5 -> V_13 == V_26 && V_5 -> V_61 )
F_28 ( V_40 ) ;
V_5 -> V_62 = V_40 -> V_55 ;
if ( V_2 -> V_63 ) {
V_2 -> V_63 ( V_5 -> V_13 , V_40 , V_5 -> V_34 ,
V_2 -> V_59 ) ;
V_5 -> V_64 = V_65 ;
} else
V_5 -> V_64 = F_29 ( V_5 -> V_13 , V_40 ) ;
V_2 -> V_40 = NULL ;
V_2 -> V_66 = 0 ;
V_2 -> V_59 = 0 ;
}
static inline void F_30 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
while ( V_2 -> V_4 < V_2 -> V_3 )
F_31 ( V_5 -> V_8 [ V_2 -> V_4 ++ ] ) ;
}
static struct V_40 * F_32 ( struct V_5 * V_5 )
{
unsigned long V_32 ;
struct V_40 * V_40 = NULL ;
F_18 ( & V_5 -> V_43 , V_32 ) ;
while ( V_5 -> V_44 > 1 && V_5 -> V_49 == NULL ) {
F_33 ( V_67 ) ;
V_5 -> V_45 = V_68 ;
F_20 ( & V_5 -> V_43 , V_32 ) ;
if ( ! ( V_5 -> V_21 -> V_69 & V_70 ) ||
! F_34 ( F_35 ( V_5 -> V_62 ) , V_5 -> V_64 ) )
F_36 () ;
F_18 ( & V_5 -> V_43 , V_32 ) ;
V_5 -> V_45 = NULL ;
}
if ( V_5 -> V_49 ) {
V_40 = V_5 -> V_49 ;
V_5 -> V_49 = V_40 -> V_41 ;
}
F_20 ( & V_5 -> V_43 , V_32 ) ;
return V_40 ;
}
static int F_17 ( struct V_5 * V_5 , struct V_40 * V_40 )
{
struct V_71 * V_72 ;
unsigned V_73 ;
int V_30 ;
if ( V_40 -> V_74 )
V_5 -> V_28 = - V_75 ;
if ( V_5 -> V_19 && V_5 -> V_13 == V_26 && V_5 -> V_61 ) {
V_30 = V_40 -> V_74 ;
F_37 ( V_40 ) ;
} else {
F_38 (bvec, bio, i) {
struct V_15 * V_15 = V_72 -> V_76 ;
if ( V_5 -> V_13 == V_26 && ! F_39 ( V_15 ) &&
V_5 -> V_61 )
F_40 ( V_15 ) ;
F_31 ( V_15 ) ;
}
V_30 = V_40 -> V_74 ;
F_41 ( V_40 ) ;
}
return V_30 ;
}
static void F_42 ( struct V_5 * V_5 )
{
struct V_40 * V_40 ;
do {
V_40 = F_32 ( V_5 ) ;
if ( V_40 )
F_17 ( V_5 , V_40 ) ;
} while ( V_40 );
}
static inline int F_43 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_77 ++ >= 64 ) {
while ( V_5 -> V_49 ) {
unsigned long V_32 ;
struct V_40 * V_40 ;
int V_78 ;
F_18 ( & V_5 -> V_43 , V_32 ) ;
V_40 = V_5 -> V_49 ;
V_5 -> V_49 = V_40 -> V_41 ;
F_20 ( & V_5 -> V_43 , V_32 ) ;
V_78 = F_17 ( V_5 , V_40 ) ;
if ( V_6 == 0 )
V_6 = V_78 ;
}
V_2 -> V_77 = 0 ;
}
return V_6 ;
}
static int F_44 ( struct V_79 * V_80 )
{
struct V_81 * V_82 ;
struct V_81 * V_83 = F_45 ( L_1 ,
V_84 , 0 ,
V_80 -> V_85 ) ;
if ( ! V_83 )
return - V_86 ;
V_82 = F_46 ( & V_80 -> V_48 , NULL , V_83 ) ;
if ( V_82 )
F_47 ( V_83 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_5 )
{
struct V_79 * V_80 = V_5 -> V_34 -> V_47 ;
if ( V_5 -> V_46 )
return 0 ;
V_5 -> V_46 = true ;
if ( ! V_80 -> V_48 )
return F_44 ( V_80 ) ;
return 0 ;
}
static int F_49 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_87 * V_88 )
{
int V_6 ;
T_3 V_89 ;
T_3 V_90 ;
unsigned long V_91 ;
int V_92 ;
unsigned int V_93 = V_2 -> V_94 + V_2 -> V_95 ;
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_96 >= V_2 -> V_97 ) ;
V_89 = V_2 -> V_96 >> V_2 -> V_95 ;
V_90 = ( V_2 -> V_97 - 1 ) >>
V_2 -> V_95 ;
V_91 = V_90 - V_89 + 1 ;
V_88 -> V_98 = 0 ;
V_88 -> V_99 = V_91 << V_93 ;
V_92 = V_5 -> V_13 & V_14 ;
if ( V_5 -> V_32 & V_100 ) {
if ( V_89 <= ( ( F_50 ( V_5 -> V_34 ) - 1 ) >>
V_93 ) )
V_92 = 0 ;
}
V_6 = (* V_2 -> V_101 )( V_5 -> V_34 , V_89 ,
V_88 , V_92 ) ;
V_5 -> V_31 = V_88 -> V_102 ;
if ( V_6 == 0 && F_51 ( V_88 ) )
V_6 = F_48 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_52 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_103 , struct V_87 * V_88 )
{
T_3 V_104 ;
int V_6 , V_105 ;
V_6 = F_43 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_106;
V_104 = V_103 << ( V_2 -> V_94 - 9 ) ;
V_105 = F_53 ( V_2 -> V_107 , V_108 ) ;
F_9 ( V_105 <= 0 ) ;
F_25 ( V_5 , V_2 , V_88 -> V_109 , V_104 , V_105 ) ;
V_2 -> V_66 = 0 ;
V_106:
return V_6 ;
}
static inline int F_54 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_55 ( V_2 -> V_40 , V_2 -> V_110 ,
V_2 -> V_111 , V_2 -> V_112 ) ;
if ( V_6 == V_2 -> V_111 ) {
if ( ( V_2 -> V_111 + V_2 -> V_112 ) == V_18 )
V_2 -> V_107 -- ;
F_5 ( V_2 -> V_110 ) ;
V_2 -> V_113 = V_2 -> V_114 +
( V_2 -> V_111 >> V_2 -> V_94 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_56 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_87 * V_88 )
{
int V_6 = 0 ;
if ( V_2 -> V_40 ) {
T_2 V_115 = V_2 -> V_60 ;
T_2 V_116 = V_2 -> V_59 +
V_2 -> V_40 -> V_56 . V_117 ;
if ( V_2 -> V_113 != V_2 -> V_114 ||
V_115 != V_116 )
F_27 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_40 == NULL ) {
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_114 , V_88 ) ;
if ( V_6 )
goto V_106;
}
if ( F_54 ( V_2 ) != 0 ) {
F_27 ( V_5 , V_2 ) ;
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_114 , V_88 ) ;
if ( V_6 == 0 ) {
V_6 = F_54 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_106:
return V_6 ;
}
static inline int
F_57 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned V_20 , unsigned V_118 , T_3 V_119 ,
struct V_87 * V_88 )
{
int V_6 = 0 ;
if ( V_5 -> V_13 & V_14 ) {
F_58 ( V_118 ) ;
}
if ( V_2 -> V_110 == V_15 &&
V_2 -> V_112 + V_2 -> V_111 == V_20 &&
V_2 -> V_114 +
( V_2 -> V_111 >> V_2 -> V_94 ) == V_119 ) {
V_2 -> V_111 += V_118 ;
goto V_106;
}
if ( V_2 -> V_110 ) {
V_6 = F_56 ( V_5 , V_2 , V_88 ) ;
F_31 ( V_2 -> V_110 ) ;
V_2 -> V_110 = NULL ;
if ( V_6 )
return V_6 ;
}
F_5 ( V_15 ) ;
V_2 -> V_110 = V_15 ;
V_2 -> V_112 = V_20 ;
V_2 -> V_111 = V_118 ;
V_2 -> V_114 = V_119 ;
V_2 -> V_60 = V_2 -> V_96 << V_2 -> V_94 ;
V_106:
if ( V_2 -> V_66 ) {
V_6 = F_56 ( V_5 , V_2 , V_88 ) ;
F_27 ( V_5 , V_2 ) ;
F_31 ( V_2 -> V_110 ) ;
V_2 -> V_110 = NULL ;
}
return V_6 ;
}
static void F_59 ( struct V_5 * V_5 , struct V_87 * V_88 )
{
unsigned V_73 ;
unsigned V_120 ;
V_120 = V_88 -> V_99 >> V_5 -> V_34 -> V_93 ;
for ( V_73 = 0 ; V_73 < V_120 ; V_73 ++ ) {
F_60 ( V_88 -> V_109 ,
V_88 -> V_121 + V_73 ) ;
}
}
static inline void F_61 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_122 , struct V_87 * V_88 )
{
unsigned V_123 ;
unsigned V_124 ;
unsigned V_125 ;
struct V_15 * V_15 ;
V_2 -> V_126 = 1 ;
if ( ! V_2 -> V_95 || ! F_62 ( V_88 ) )
return;
V_123 = 1 << V_2 -> V_95 ;
V_124 = V_2 -> V_96 & ( V_123 - 1 ) ;
if ( ! V_124 )
return;
if ( V_122 )
V_124 = V_123 - V_124 ;
V_125 = V_124 << V_2 -> V_94 ;
V_15 = F_4 ( 0 ) ;
if ( F_57 ( V_5 , V_2 , V_15 , 0 , V_125 ,
V_2 -> V_127 , V_88 ) )
return;
V_2 -> V_127 += V_124 ;
}
static int F_63 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_87 * V_88 )
{
const unsigned V_94 = V_2 -> V_94 ;
int V_6 = 0 ;
while ( V_2 -> V_96 < V_2 -> V_97 ) {
struct V_15 * V_15 ;
T_4 V_11 , V_17 ;
V_15 = F_7 ( V_5 , V_2 ) ;
if ( F_64 ( V_15 ) ) {
V_6 = F_65 ( V_15 ) ;
goto V_106;
}
V_11 = V_2 -> V_4 ? 0 : V_2 -> V_11 ;
V_17 = ( V_2 -> V_4 == V_2 -> V_3 - 1 ) ? V_2 -> V_17 : V_18 ;
V_2 -> V_4 ++ ;
while ( V_11 < V_17 ) {
unsigned V_125 ;
unsigned V_124 ;
unsigned V_128 ;
if ( V_2 -> V_12 == 0 ) {
unsigned long V_129 ;
unsigned long V_130 ;
V_6 = F_49 ( V_5 , V_2 , V_88 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_106;
}
if ( ! F_66 ( V_88 ) )
goto V_131;
V_2 -> V_12 =
V_88 -> V_99 >> V_2 -> V_94 ;
V_2 -> V_127 =
V_88 -> V_121 << V_2 -> V_95 ;
if ( F_62 ( V_88 ) )
F_59 ( V_5 , V_88 ) ;
if ( ! V_2 -> V_95 )
goto V_131;
V_129 = ( 1 << V_2 -> V_95 ) - 1 ;
V_130 = ( V_2 -> V_96 & V_129 ) ;
if ( ! F_62 ( V_88 ) )
V_2 -> V_127 += V_130 ;
V_2 -> V_12 -= V_130 ;
}
V_131:
if ( ! F_66 ( V_88 ) ) {
T_2 V_132 ;
if ( V_5 -> V_13 & V_14 ) {
F_31 ( V_15 ) ;
return - V_133 ;
}
V_132 = F_67 ( F_50 ( V_5 -> V_34 ) ,
1 << V_94 ) ;
if ( V_2 -> V_96 >=
V_132 >> V_94 ) {
F_31 ( V_15 ) ;
goto V_106;
}
F_68 ( V_15 , V_11 , 1 << V_94 ) ;
V_2 -> V_96 ++ ;
V_11 += 1 << V_94 ;
V_5 -> V_25 += 1 << V_94 ;
goto V_134;
}
if ( F_69 ( V_2 -> V_95 && ! V_2 -> V_126 ) )
F_61 ( V_5 , V_2 , 0 , V_88 ) ;
V_124 = V_2 -> V_12 ;
V_128 = ( V_17 - V_11 ) >> V_94 ;
if ( V_124 > V_128 )
V_124 = V_128 ;
V_128 = V_2 -> V_97 - V_2 -> V_96 ;
if ( V_124 > V_128 )
V_124 = V_128 ;
V_125 = V_124 << V_94 ;
F_9 ( V_125 == 0 ) ;
if ( V_124 == V_2 -> V_12 )
V_2 -> V_66 = F_70 ( V_88 ) ;
V_6 = F_57 ( V_5 , V_2 , V_15 ,
V_11 ,
V_125 ,
V_2 -> V_127 ,
V_88 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_106;
}
V_2 -> V_127 += V_124 ;
V_2 -> V_96 += V_124 ;
V_11 += V_125 ;
V_5 -> V_25 += V_125 ;
V_2 -> V_12 -= V_124 ;
V_134:
F_9 ( V_2 -> V_96 > V_2 -> V_97 ) ;
if ( V_2 -> V_96 == V_2 -> V_97 )
break;
}
F_31 ( V_15 ) ;
}
V_106:
return V_6 ;
}
static inline int F_71 ( struct V_5 * V_5 )
{
int V_78 ;
unsigned long V_32 ;
F_18 ( & V_5 -> V_43 , V_32 ) ;
V_78 = -- V_5 -> V_44 ;
F_20 ( & V_5 -> V_43 , V_32 ) ;
return V_78 ;
}
static inline T_1
F_72 ( struct V_135 * V_21 , struct V_34 * V_34 ,
struct V_50 * V_51 , struct V_136 * V_7 ,
T_5 V_101 , T_6 V_29 ,
T_7 V_63 , int V_32 )
{
unsigned V_93 = F_73 ( V_34 -> V_93 ) ;
unsigned V_94 = V_93 ;
unsigned V_137 = ( 1 << V_94 ) - 1 ;
T_1 V_138 = - V_139 ;
T_4 V_140 = F_74 ( V_7 ) ;
T_2 V_20 = V_21 -> V_22 ;
T_2 V_122 = V_20 + V_140 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
struct V_87 V_88 = { 0 , } ;
struct V_141 V_142 ;
unsigned long V_143 = V_20 | F_75 ( V_7 ) ;
if ( V_143 & V_137 ) {
if ( V_51 )
V_94 = F_76 ( F_77 ( V_51 ) ) ;
V_137 = ( 1 << V_94 ) - 1 ;
if ( V_143 & V_137 )
goto V_106;
}
if ( F_78 ( V_7 ) == V_26 && ! F_74 ( V_7 ) )
return 0 ;
V_5 = F_79 ( V_36 , V_54 ) ;
V_138 = - V_86 ;
if ( ! V_5 )
goto V_106;
memset ( V_5 , 0 , F_80 ( struct V_5 , V_8 ) ) ;
V_5 -> V_32 = V_32 ;
if ( V_5 -> V_32 & V_144 ) {
if ( F_78 ( V_7 ) == V_26 ) {
struct V_145 * V_146 =
V_21 -> V_147 -> V_148 ;
F_81 ( V_34 ) ;
V_138 = F_82 ( V_146 , V_20 ,
V_122 - 1 ) ;
if ( V_138 ) {
F_83 ( V_34 ) ;
F_13 ( V_36 , V_5 ) ;
goto V_106;
}
}
}
V_5 -> V_27 = F_50 ( V_34 ) ;
if ( F_78 ( V_7 ) == V_26 && V_20 >= V_5 -> V_27 ) {
if ( V_5 -> V_32 & V_144 )
F_83 ( V_34 ) ;
F_13 ( V_36 , V_5 ) ;
V_138 = 0 ;
goto V_106;
}
if ( F_84 ( V_21 ) )
V_5 -> V_19 = false ;
else if ( ! ( V_5 -> V_32 & V_149 ) &&
F_78 ( V_7 ) == V_14 && V_122 > F_50 ( V_34 ) )
V_5 -> V_19 = false ;
else
V_5 -> V_19 = true ;
V_5 -> V_34 = V_34 ;
V_5 -> V_13 = F_78 ( V_7 ) == V_14 ? V_150 : V_26 ;
if ( V_5 -> V_19 && F_78 ( V_7 ) == V_14 &&
( ( V_21 -> V_147 -> V_151 & V_152 ) ||
F_85 ( V_21 -> V_147 -> V_148 -> V_153 ) ) ) {
V_138 = F_48 ( V_5 ) ;
if ( V_138 ) {
F_13 ( V_36 , V_5 ) ;
goto V_106;
}
}
if ( ! ( V_5 -> V_32 & V_33 ) )
F_86 ( V_34 ) ;
V_138 = 0 ;
V_2 . V_94 = V_94 ;
V_2 . V_95 = V_93 - V_94 ;
V_2 . V_96 = V_20 >> V_94 ;
V_2 . V_101 = V_101 ;
V_5 -> V_29 = V_29 ;
V_2 . V_63 = V_63 ;
V_2 . V_113 = - 1 ;
V_2 . V_127 = - 1 ;
V_5 -> V_21 = V_21 ;
F_87 ( & V_5 -> V_43 ) ;
V_5 -> V_44 = 1 ;
V_5 -> V_61 = ( V_7 -> type == V_154 ) ;
V_2 . V_7 = V_7 ;
V_2 . V_97 =
( V_20 + F_74 ( V_7 ) ) >> V_94 ;
if ( F_69 ( V_2 . V_95 ) )
V_2 . V_107 = 2 ;
V_2 . V_107 += F_88 ( V_7 , V_155 ) ;
F_89 ( & V_142 ) ;
V_138 = F_63 ( V_5 , & V_2 , & V_88 ) ;
if ( V_138 )
F_30 ( V_5 , & V_2 ) ;
if ( V_138 == - V_133 ) {
V_138 = 0 ;
}
F_61 ( V_5 , & V_2 , 1 , & V_88 ) ;
if ( V_2 . V_110 ) {
T_1 V_78 ;
V_78 = F_56 ( V_5 , & V_2 , & V_88 ) ;
if ( V_138 == 0 )
V_138 = V_78 ;
F_31 ( V_2 . V_110 ) ;
V_2 . V_110 = NULL ;
}
if ( V_2 . V_40 )
F_27 ( V_5 , & V_2 ) ;
F_90 ( & V_142 ) ;
F_30 ( V_5 , & V_2 ) ;
if ( F_78 ( V_7 ) == V_26 && ( V_5 -> V_32 & V_144 ) )
F_83 ( V_5 -> V_34 ) ;
F_9 ( V_138 == - V_24 ) ;
if ( V_5 -> V_19 && V_138 == 0 && V_5 -> V_25 &&
( F_78 ( V_7 ) == V_26 || V_5 -> V_25 == V_140 ) )
V_138 = - V_24 ;
else
F_42 ( V_5 ) ;
if ( F_71 ( V_5 ) == 0 ) {
V_138 = F_10 ( V_5 , V_138 , false ) ;
} else
F_9 ( V_138 != - V_24 ) ;
V_106:
return V_138 ;
}
T_1 F_91 ( struct V_135 * V_21 , struct V_34 * V_34 ,
struct V_50 * V_51 , struct V_136 * V_7 ,
T_5 V_101 ,
T_6 V_29 , T_7 V_63 ,
int V_32 )
{
F_92 ( & V_51 -> V_156 -> V_157 ) ;
F_92 ( V_51 -> V_158 ) ;
F_92 ( ( char * ) V_51 -> V_158 + V_159 ) ;
return F_72 ( V_21 , V_34 , V_51 , V_7 , V_101 ,
V_29 , V_63 , V_32 ) ;
}
static T_8 int F_93 ( void )
{
V_36 = F_94 ( V_5 , V_160 ) ;
return 0 ;
}
