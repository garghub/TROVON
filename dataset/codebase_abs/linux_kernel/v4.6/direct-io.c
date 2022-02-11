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
if ( V_5 -> V_27 ) {
int V_28 ;
V_28 = V_5 -> V_27 ( V_5 -> V_29 , V_19 , V_6 , V_5 -> V_30 ) ;
if ( V_28 )
V_6 = V_28 ;
}
if ( ! ( V_5 -> V_31 & V_32 ) )
F_11 ( V_5 -> V_33 ) ;
if ( V_20 ) {
if ( V_5 -> V_13 & V_14 ) {
int V_28 ;
V_28 = F_12 ( V_5 -> V_29 -> V_34 , V_19 ,
V_21 ) ;
if ( V_28 < 0 && V_6 > 0 )
V_6 = V_28 ;
}
V_5 -> V_29 -> V_35 ( V_5 -> V_29 , V_6 , 0 ) ;
}
F_13 ( V_36 , V_5 ) ;
return V_6 ;
}
static void F_14 ( struct V_37 * V_38 )
{
struct V_5 * V_5 = F_15 ( V_38 , struct V_5 , V_39 ) ;
F_10 ( V_5 , V_5 -> V_29 -> V_40 , 0 , true ) ;
}
static void F_16 ( struct V_41 * V_41 )
{
struct V_5 * V_5 = V_41 -> V_42 ;
unsigned long V_43 ;
unsigned long V_31 ;
F_17 ( V_5 , V_41 ) ;
F_18 ( & V_5 -> V_44 , V_31 ) ;
V_43 = -- V_5 -> V_45 ;
if ( V_43 == 1 && V_5 -> V_46 )
F_19 ( V_5 -> V_46 ) ;
F_20 ( & V_5 -> V_44 , V_31 ) ;
if ( V_43 == 0 ) {
if ( V_5 -> V_23 && V_5 -> V_47 ) {
F_21 ( & V_5 -> V_39 , F_14 ) ;
F_22 ( V_5 -> V_33 -> V_48 -> V_49 ,
& V_5 -> V_39 ) ;
} else {
F_10 ( V_5 , V_5 -> V_29 -> V_40 , 0 , true ) ;
}
}
}
static void F_23 ( struct V_41 * V_41 )
{
struct V_5 * V_5 = V_41 -> V_42 ;
unsigned long V_31 ;
F_18 ( & V_5 -> V_44 , V_31 ) ;
V_41 -> V_42 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 ;
if ( -- V_5 -> V_45 == 1 && V_5 -> V_46 )
F_19 ( V_5 -> V_46 ) ;
F_20 ( & V_5 -> V_44 , V_31 ) ;
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
unsigned long V_31 ;
V_41 -> V_42 = V_5 ;
F_18 ( & V_5 -> V_44 , V_31 ) ;
V_5 -> V_45 ++ ;
F_20 ( & V_5 -> V_44 , V_31 ) ;
if ( V_5 -> V_20 && V_5 -> V_13 == V_24 && V_5 -> V_62 )
F_28 ( V_41 ) ;
V_5 -> V_63 = V_41 -> V_56 ;
if ( V_2 -> V_64 ) {
V_2 -> V_64 ( V_5 -> V_13 , V_41 , V_5 -> V_33 ,
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
unsigned long V_31 ;
struct V_41 * V_41 = NULL ;
F_18 ( & V_5 -> V_44 , V_31 ) ;
while ( V_5 -> V_45 > 1 && V_5 -> V_50 == NULL ) {
F_33 ( V_68 ) ;
V_5 -> V_46 = V_69 ;
F_20 ( & V_5 -> V_44 , V_31 ) ;
if ( ! ( V_5 -> V_29 -> V_70 & V_71 ) ||
! F_34 ( F_35 ( V_5 -> V_63 ) , V_5 -> V_65 ) )
F_36 () ;
F_18 ( & V_5 -> V_44 , V_31 ) ;
V_5 -> V_46 = NULL ;
}
if ( V_5 -> V_50 ) {
V_41 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 -> V_42 ;
}
F_20 ( & V_5 -> V_44 , V_31 ) ;
return V_41 ;
}
static int F_17 ( struct V_5 * V_5 , struct V_41 * V_41 )
{
struct V_72 * V_73 ;
unsigned V_74 ;
int V_28 ;
if ( V_41 -> V_75 )
V_5 -> V_26 = - V_76 ;
if ( V_5 -> V_20 && V_5 -> V_13 == V_24 && V_5 -> V_62 ) {
V_28 = V_41 -> V_75 ;
F_37 ( V_41 ) ;
} else {
F_38 (bvec, bio, i) {
struct V_15 * V_15 = V_73 -> V_77 ;
if ( V_5 -> V_13 == V_24 && ! F_39 ( V_15 ) &&
V_5 -> V_62 )
F_40 ( V_15 ) ;
F_31 ( V_15 ) ;
}
V_28 = V_41 -> V_75 ;
F_41 ( V_41 ) ;
}
return V_28 ;
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
if ( V_2 -> V_78 ++ >= 64 ) {
while ( V_5 -> V_50 ) {
unsigned long V_31 ;
struct V_41 * V_41 ;
int V_79 ;
F_18 ( & V_5 -> V_44 , V_31 ) ;
V_41 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 -> V_42 ;
F_20 ( & V_5 -> V_44 , V_31 ) ;
V_79 = F_17 ( V_5 , V_41 ) ;
if ( V_6 == 0 )
V_6 = V_79 ;
}
V_2 -> V_78 = 0 ;
}
return V_6 ;
}
static int F_44 ( struct V_80 * V_81 )
{
struct V_82 * V_83 ;
struct V_82 * V_84 = F_45 ( L_1 ,
V_85 , 0 ,
V_81 -> V_86 ) ;
if ( ! V_84 )
return - V_87 ;
V_83 = F_46 ( & V_81 -> V_49 , NULL , V_84 ) ;
if ( V_83 )
F_47 ( V_84 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_5 )
{
struct V_80 * V_81 = V_5 -> V_33 -> V_48 ;
if ( V_5 -> V_47 )
return 0 ;
V_5 -> V_47 = true ;
if ( ! V_81 -> V_49 )
return F_44 ( V_81 ) ;
return 0 ;
}
static int F_49 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_88 * V_89 )
{
int V_6 ;
T_3 V_90 ;
T_3 V_91 ;
unsigned long V_92 ;
int V_93 ;
unsigned int V_94 = V_2 -> V_95 + V_2 -> V_96 ;
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_97 >= V_2 -> V_98 ) ;
V_90 = V_2 -> V_97 >> V_2 -> V_96 ;
V_91 = ( V_2 -> V_98 - 1 ) >>
V_2 -> V_96 ;
V_92 = V_91 - V_90 + 1 ;
V_89 -> V_99 = 0 ;
V_89 -> V_100 = V_92 << V_94 ;
V_93 = V_5 -> V_13 & V_14 ;
if ( V_5 -> V_31 & V_101 ) {
if ( V_2 -> V_97 < ( F_50 ( V_5 -> V_33 ) >>
V_2 -> V_95 ) )
V_93 = 0 ;
}
V_6 = (* V_2 -> V_102 )( V_5 -> V_33 , V_90 ,
V_89 , V_93 ) ;
V_5 -> V_30 = V_89 -> V_103 ;
if ( V_6 == 0 && F_51 ( V_89 ) )
V_6 = F_48 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_52 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_104 , struct V_88 * V_89 )
{
T_3 V_105 ;
int V_6 , V_106 ;
V_6 = F_43 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_107;
V_105 = V_104 << ( V_2 -> V_95 - 9 ) ;
V_106 = F_53 ( V_2 -> V_108 , V_109 ) ;
F_9 ( V_106 <= 0 ) ;
F_25 ( V_5 , V_2 , V_89 -> V_110 , V_105 , V_106 ) ;
V_2 -> V_67 = 0 ;
V_107:
return V_6 ;
}
static inline int F_54 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_55 ( V_2 -> V_41 , V_2 -> V_111 ,
V_2 -> V_112 , V_2 -> V_113 ) ;
if ( V_6 == V_2 -> V_112 ) {
if ( ( V_2 -> V_112 + V_2 -> V_113 ) == V_18 )
V_2 -> V_108 -- ;
F_5 ( V_2 -> V_111 ) ;
V_2 -> V_114 = V_2 -> V_115 +
( V_2 -> V_112 >> V_2 -> V_95 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_56 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_88 * V_89 )
{
int V_6 = 0 ;
if ( V_2 -> V_41 ) {
T_2 V_116 = V_2 -> V_61 ;
T_2 V_117 = V_2 -> V_60 +
V_2 -> V_41 -> V_57 . V_118 ;
if ( V_2 -> V_114 != V_2 -> V_115 ||
V_116 != V_117 )
F_27 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_41 == NULL ) {
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_115 , V_89 ) ;
if ( V_6 )
goto V_107;
}
if ( F_54 ( V_2 ) != 0 ) {
F_27 ( V_5 , V_2 ) ;
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_115 , V_89 ) ;
if ( V_6 == 0 ) {
V_6 = F_54 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_107:
return V_6 ;
}
static inline int
F_57 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned V_19 , unsigned V_119 , T_3 V_120 ,
struct V_88 * V_89 )
{
int V_6 = 0 ;
if ( V_5 -> V_13 & V_14 ) {
F_58 ( V_119 ) ;
}
if ( V_2 -> V_111 == V_15 &&
V_2 -> V_113 + V_2 -> V_112 == V_19 &&
V_2 -> V_115 +
( V_2 -> V_112 >> V_2 -> V_95 ) == V_120 ) {
V_2 -> V_112 += V_119 ;
goto V_107;
}
if ( V_2 -> V_111 ) {
V_6 = F_56 ( V_5 , V_2 , V_89 ) ;
F_31 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
if ( V_6 )
return V_6 ;
}
F_5 ( V_15 ) ;
V_2 -> V_111 = V_15 ;
V_2 -> V_113 = V_19 ;
V_2 -> V_112 = V_119 ;
V_2 -> V_115 = V_120 ;
V_2 -> V_61 = V_2 -> V_97 << V_2 -> V_95 ;
V_107:
if ( V_2 -> V_67 ) {
V_6 = F_56 ( V_5 , V_2 , V_89 ) ;
F_27 ( V_5 , V_2 ) ;
F_31 ( V_2 -> V_111 ) ;
V_2 -> V_111 = NULL ;
}
return V_6 ;
}
static void F_59 ( struct V_5 * V_5 , struct V_88 * V_89 )
{
unsigned V_74 ;
unsigned V_121 ;
V_121 = V_89 -> V_100 >> V_5 -> V_33 -> V_94 ;
for ( V_74 = 0 ; V_74 < V_121 ; V_74 ++ ) {
F_60 ( V_89 -> V_110 ,
V_89 -> V_122 + V_74 ) ;
}
}
static inline void F_61 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_123 , struct V_88 * V_89 )
{
unsigned V_124 ;
unsigned V_125 ;
unsigned V_126 ;
struct V_15 * V_15 ;
V_2 -> V_127 = 1 ;
if ( ! V_2 -> V_96 || ! F_62 ( V_89 ) )
return;
V_124 = 1 << V_2 -> V_96 ;
V_125 = V_2 -> V_97 & ( V_124 - 1 ) ;
if ( ! V_125 )
return;
if ( V_123 )
V_125 = V_124 - V_125 ;
V_126 = V_125 << V_2 -> V_95 ;
V_15 = F_4 ( 0 ) ;
if ( F_57 ( V_5 , V_2 , V_15 , 0 , V_126 ,
V_2 -> V_128 , V_89 ) )
return;
V_2 -> V_128 += V_125 ;
}
static int F_63 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_88 * V_89 )
{
const unsigned V_95 = V_2 -> V_95 ;
int V_6 = 0 ;
while ( V_2 -> V_97 < V_2 -> V_98 ) {
struct V_15 * V_15 ;
T_4 V_11 , V_17 ;
V_15 = F_7 ( V_5 , V_2 ) ;
if ( F_64 ( V_15 ) ) {
V_6 = F_65 ( V_15 ) ;
goto V_107;
}
V_11 = V_2 -> V_4 ? 0 : V_2 -> V_11 ;
V_17 = ( V_2 -> V_4 == V_2 -> V_3 - 1 ) ? V_2 -> V_17 : V_18 ;
V_2 -> V_4 ++ ;
while ( V_11 < V_17 ) {
unsigned V_126 ;
unsigned V_125 ;
unsigned V_129 ;
if ( V_2 -> V_12 == 0 ) {
unsigned long V_130 ;
unsigned long V_131 ;
V_6 = F_49 ( V_5 , V_2 , V_89 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_107;
}
if ( ! F_66 ( V_89 ) )
goto V_132;
V_2 -> V_12 =
V_89 -> V_100 >> V_2 -> V_95 ;
V_2 -> V_128 =
V_89 -> V_122 << V_2 -> V_96 ;
if ( F_62 ( V_89 ) )
F_59 ( V_5 , V_89 ) ;
if ( ! V_2 -> V_96 )
goto V_132;
V_130 = ( 1 << V_2 -> V_96 ) - 1 ;
V_131 = ( V_2 -> V_97 & V_130 ) ;
if ( ! F_62 ( V_89 ) )
V_2 -> V_128 += V_131 ;
V_2 -> V_12 -= V_131 ;
}
V_132:
if ( ! F_66 ( V_89 ) ) {
T_2 V_133 ;
if ( V_5 -> V_13 & V_14 ) {
F_31 ( V_15 ) ;
return - V_134 ;
}
V_133 = F_67 ( F_50 ( V_5 -> V_33 ) ,
1 << V_95 ) ;
if ( V_2 -> V_97 >=
V_133 >> V_95 ) {
F_31 ( V_15 ) ;
goto V_107;
}
F_68 ( V_15 , V_11 , 1 << V_95 ) ;
V_2 -> V_97 ++ ;
V_11 += 1 << V_95 ;
V_5 -> V_23 += 1 << V_95 ;
goto V_135;
}
if ( F_69 ( V_2 -> V_96 && ! V_2 -> V_127 ) )
F_61 ( V_5 , V_2 , 0 , V_89 ) ;
V_125 = V_2 -> V_12 ;
V_129 = ( V_17 - V_11 ) >> V_95 ;
if ( V_125 > V_129 )
V_125 = V_129 ;
V_129 = V_2 -> V_98 - V_2 -> V_97 ;
if ( V_125 > V_129 )
V_125 = V_129 ;
V_126 = V_125 << V_95 ;
F_9 ( V_126 == 0 ) ;
if ( V_125 == V_2 -> V_12 )
V_2 -> V_67 = F_70 ( V_89 ) ;
V_6 = F_57 ( V_5 , V_2 , V_15 ,
V_11 ,
V_126 ,
V_2 -> V_128 ,
V_89 ) ;
if ( V_6 ) {
F_31 ( V_15 ) ;
goto V_107;
}
V_2 -> V_128 += V_125 ;
V_2 -> V_97 += V_125 ;
V_11 += V_126 ;
V_5 -> V_23 += V_126 ;
V_2 -> V_12 -= V_125 ;
V_135:
F_9 ( V_2 -> V_97 > V_2 -> V_98 ) ;
if ( V_2 -> V_97 == V_2 -> V_98 )
break;
}
F_31 ( V_15 ) ;
}
V_107:
return V_6 ;
}
static inline int F_71 ( struct V_5 * V_5 )
{
int V_79 ;
unsigned long V_31 ;
F_18 ( & V_5 -> V_44 , V_31 ) ;
V_79 = -- V_5 -> V_45 ;
F_20 ( & V_5 -> V_44 , V_31 ) ;
return V_79 ;
}
static inline T_1
F_72 ( struct V_136 * V_29 , struct V_33 * V_33 ,
struct V_51 * V_52 , struct V_137 * V_7 ,
T_2 V_19 , T_5 V_102 , T_6 V_27 ,
T_7 V_64 , int V_31 )
{
unsigned V_94 = F_73 ( V_33 -> V_94 ) ;
unsigned V_95 = V_94 ;
unsigned V_138 = ( 1 << V_95 ) - 1 ;
T_1 V_139 = - V_140 ;
T_4 V_141 = F_74 ( V_7 ) ;
T_2 V_123 = V_19 + V_141 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
struct V_88 V_89 = { 0 , } ;
struct V_142 V_143 ;
unsigned long V_144 = V_19 | F_75 ( V_7 ) ;
if ( V_144 & V_138 ) {
if ( V_52 )
V_95 = F_76 ( F_77 ( V_52 ) ) ;
V_138 = ( 1 << V_95 ) - 1 ;
if ( V_144 & V_138 )
goto V_107;
}
if ( F_78 ( V_7 ) == V_24 && ! F_74 ( V_7 ) )
return 0 ;
V_5 = F_79 ( V_36 , V_55 ) ;
V_139 = - V_87 ;
if ( ! V_5 )
goto V_107;
memset ( V_5 , 0 , F_80 ( struct V_5 , V_8 ) ) ;
V_5 -> V_31 = V_31 ;
if ( V_5 -> V_31 & V_145 ) {
if ( F_78 ( V_7 ) == V_24 ) {
struct V_146 * V_147 =
V_29 -> V_34 -> V_148 ;
F_81 ( V_33 ) ;
V_139 = F_82 ( V_147 , V_19 ,
V_123 - 1 ) ;
if ( V_139 ) {
F_83 ( V_33 ) ;
F_13 ( V_36 , V_5 ) ;
goto V_107;
}
}
}
V_5 -> V_25 = F_50 ( V_33 ) ;
if ( F_78 ( V_7 ) == V_24 && V_19 >= V_5 -> V_25 ) {
if ( V_5 -> V_31 & V_145 )
F_83 ( V_33 ) ;
F_13 ( V_36 , V_5 ) ;
V_139 = 0 ;
goto V_107;
}
if ( F_84 ( V_29 ) )
V_5 -> V_20 = false ;
else if ( ! ( V_5 -> V_31 & V_149 ) &&
F_78 ( V_7 ) == V_14 && V_123 > F_50 ( V_33 ) )
V_5 -> V_20 = false ;
else
V_5 -> V_20 = true ;
V_5 -> V_33 = V_33 ;
V_5 -> V_13 = F_78 ( V_7 ) == V_14 ? V_150 : V_24 ;
if ( V_5 -> V_20 && F_78 ( V_7 ) == V_14 &&
( ( V_29 -> V_34 -> V_151 & V_152 ) ||
F_85 ( V_29 -> V_34 -> V_148 -> V_153 ) ) ) {
V_139 = F_48 ( V_5 ) ;
if ( V_139 ) {
F_13 ( V_36 , V_5 ) ;
goto V_107;
}
}
if ( ! ( V_5 -> V_31 & V_32 ) )
F_86 ( V_33 ) ;
V_139 = 0 ;
V_2 . V_95 = V_95 ;
V_2 . V_96 = V_94 - V_95 ;
V_2 . V_97 = V_19 >> V_95 ;
V_2 . V_102 = V_102 ;
V_5 -> V_27 = V_27 ;
V_2 . V_64 = V_64 ;
V_2 . V_114 = - 1 ;
V_2 . V_128 = - 1 ;
V_5 -> V_29 = V_29 ;
F_87 ( & V_5 -> V_44 ) ;
V_5 -> V_45 = 1 ;
V_5 -> V_62 = ( V_7 -> type == V_154 ) ;
V_2 . V_7 = V_7 ;
V_2 . V_98 =
( V_19 + F_74 ( V_7 ) ) >> V_95 ;
if ( F_69 ( V_2 . V_96 ) )
V_2 . V_108 = 2 ;
V_2 . V_108 += F_88 ( V_7 , V_155 ) ;
F_89 ( & V_143 ) ;
V_139 = F_63 ( V_5 , & V_2 , & V_89 ) ;
if ( V_139 )
F_30 ( V_5 , & V_2 ) ;
if ( V_139 == - V_134 ) {
V_139 = 0 ;
}
F_61 ( V_5 , & V_2 , 1 , & V_89 ) ;
if ( V_2 . V_111 ) {
T_1 V_79 ;
V_79 = F_56 ( V_5 , & V_2 , & V_89 ) ;
if ( V_139 == 0 )
V_139 = V_79 ;
F_31 ( V_2 . V_111 ) ;
V_2 . V_111 = NULL ;
}
if ( V_2 . V_41 )
F_27 ( V_5 , & V_2 ) ;
F_90 ( & V_143 ) ;
F_30 ( V_5 , & V_2 ) ;
if ( F_78 ( V_7 ) == V_24 && ( V_5 -> V_31 & V_145 ) )
F_83 ( V_5 -> V_33 ) ;
F_9 ( V_139 == - V_22 ) ;
if ( V_5 -> V_20 && V_139 == 0 && V_5 -> V_23 &&
( F_78 ( V_7 ) == V_24 || V_5 -> V_23 == V_141 ) )
V_139 = - V_22 ;
else
F_42 ( V_5 ) ;
if ( F_71 ( V_5 ) == 0 ) {
V_139 = F_10 ( V_5 , V_19 , V_139 , false ) ;
} else
F_9 ( V_139 != - V_22 ) ;
V_107:
return V_139 ;
}
T_1 F_91 ( struct V_136 * V_29 , struct V_33 * V_33 ,
struct V_51 * V_52 , struct V_137 * V_7 ,
T_2 V_19 , T_5 V_102 ,
T_6 V_27 , T_7 V_64 ,
int V_31 )
{
F_92 ( & V_52 -> V_156 -> V_157 ) ;
F_92 ( V_52 -> V_158 ) ;
F_92 ( ( char * ) V_52 -> V_158 + V_159 ) ;
return F_72 ( V_29 , V_33 , V_52 , V_7 , V_19 , V_102 ,
V_27 , V_64 , V_31 ) ;
}
static T_8 int F_93 ( void )
{
V_36 = F_94 ( V_5 , V_160 ) ;
return 0 ;
}
