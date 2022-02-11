static inline unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 ;
}
static inline int F_2 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_3 ( V_2 -> V_7 , V_5 -> V_8 , V_9 , V_10 ,
& V_2 -> V_11 ) ;
if ( V_6 < 0 && V_2 -> V_12 && ( V_5 -> V_13 == V_14 ) ) {
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
if ( ( V_5 -> V_13 == V_26 ) &&
( ( V_20 + V_23 ) > V_5 -> V_27 ) )
V_23 = V_5 -> V_27 - V_20 ;
if ( F_11 ( V_6 == - V_28 ) && V_23 )
V_6 = 0 ;
}
if ( V_6 == 0 )
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 )
V_6 = V_5 -> V_29 ;
if ( V_6 == 0 )
V_6 = V_23 ;
if ( V_5 -> V_30 ) {
int V_31 ;
V_31 = V_5 -> V_30 ( V_5 -> V_21 , V_20 , V_6 , V_5 -> V_32 ) ;
if ( V_31 )
V_6 = V_31 ;
}
if ( ! ( V_5 -> V_33 & V_34 ) )
F_12 ( V_5 -> V_35 ) ;
if ( V_19 ) {
V_5 -> V_21 -> V_22 += V_23 ;
if ( V_5 -> V_13 == V_14 )
V_6 = F_13 ( V_5 -> V_21 , V_23 ) ;
V_5 -> V_21 -> V_36 ( V_5 -> V_21 , V_6 , 0 ) ;
}
F_14 ( V_37 , V_5 ) ;
return V_6 ;
}
static void F_15 ( struct V_38 * V_39 )
{
struct V_5 * V_5 = F_16 ( V_39 , struct V_5 , V_40 ) ;
F_10 ( V_5 , 0 , true ) ;
}
static void F_17 ( struct V_41 * V_41 )
{
struct V_5 * V_5 = V_41 -> V_42 ;
unsigned long V_43 ;
unsigned long V_33 ;
F_18 ( V_5 , V_41 ) ;
F_19 ( & V_5 -> V_44 , V_33 ) ;
V_43 = -- V_5 -> V_45 ;
if ( V_43 == 1 && V_5 -> V_46 )
F_20 ( V_5 -> V_46 ) ;
F_21 ( & V_5 -> V_44 , V_33 ) ;
if ( V_43 == 0 ) {
if ( V_5 -> V_25 && V_5 -> V_47 ) {
F_22 ( & V_5 -> V_40 , F_15 ) ;
F_23 ( V_5 -> V_35 -> V_48 -> V_49 ,
& V_5 -> V_40 ) ;
} else {
F_10 ( V_5 , 0 , true ) ;
}
}
}
static void F_24 ( struct V_41 * V_41 )
{
struct V_5 * V_5 = V_41 -> V_42 ;
unsigned long V_33 ;
F_19 ( & V_5 -> V_44 , V_33 ) ;
V_41 -> V_42 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 ;
if ( -- V_5 -> V_45 == 1 && V_5 -> V_46 )
F_20 ( V_5 -> V_46 ) ;
F_21 ( & V_5 -> V_44 , V_33 ) ;
}
void F_25 ( struct V_41 * V_41 , int error )
{
struct V_5 * V_5 = V_41 -> V_42 ;
if ( V_5 -> V_19 )
F_17 ( V_41 ) ;
else
F_24 ( V_41 ) ;
}
static inline void
F_26 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_51 * V_52 ,
T_3 V_53 , int V_54 )
{
struct V_41 * V_41 ;
V_41 = F_27 ( V_55 , V_54 ) ;
V_41 -> V_56 = V_52 ;
V_41 -> V_57 . V_58 = V_53 ;
F_28 ( V_41 , V_5 -> V_13 , V_5 -> V_59 ) ;
if ( V_5 -> V_19 )
V_41 -> V_60 = F_17 ;
else
V_41 -> V_60 = F_24 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_61 = V_2 -> V_62 ;
}
static inline void F_29 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
struct V_41 * V_41 = V_2 -> V_41 ;
unsigned long V_33 ;
V_41 -> V_42 = V_5 ;
F_19 ( & V_5 -> V_44 , V_33 ) ;
V_5 -> V_45 ++ ;
F_21 ( & V_5 -> V_44 , V_33 ) ;
if ( V_5 -> V_19 && V_5 -> V_13 == V_26 && V_5 -> V_63 )
F_30 ( V_41 ) ;
V_5 -> V_64 = V_41 -> V_56 ;
if ( V_2 -> V_65 ) {
V_2 -> V_65 ( V_41 , V_5 -> V_35 , V_2 -> V_61 ) ;
V_5 -> V_66 = V_67 ;
} else
V_5 -> V_66 = F_31 ( V_41 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_68 = 0 ;
V_2 -> V_61 = 0 ;
}
static inline void F_32 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
while ( V_2 -> V_4 < V_2 -> V_3 )
F_33 ( V_5 -> V_8 [ V_2 -> V_4 ++ ] ) ;
}
static struct V_41 * F_34 ( struct V_5 * V_5 )
{
unsigned long V_33 ;
struct V_41 * V_41 = NULL ;
F_19 ( & V_5 -> V_44 , V_33 ) ;
while ( V_5 -> V_45 > 1 && V_5 -> V_50 == NULL ) {
F_35 ( V_69 ) ;
V_5 -> V_46 = V_70 ;
F_21 ( & V_5 -> V_44 , V_33 ) ;
if ( ! ( V_5 -> V_21 -> V_71 & V_72 ) ||
! F_36 ( F_37 ( V_5 -> V_64 ) , V_5 -> V_66 ) )
F_38 () ;
F_19 ( & V_5 -> V_44 , V_33 ) ;
V_5 -> V_46 = NULL ;
}
if ( V_5 -> V_50 ) {
V_41 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 -> V_42 ;
}
F_21 ( & V_5 -> V_44 , V_33 ) ;
return V_41 ;
}
static int F_18 ( struct V_5 * V_5 , struct V_41 * V_41 )
{
struct V_73 * V_74 ;
unsigned V_75 ;
int V_31 ;
if ( V_41 -> V_76 )
V_5 -> V_29 = - V_77 ;
if ( V_5 -> V_19 && V_5 -> V_13 == V_26 && V_5 -> V_63 ) {
V_31 = V_41 -> V_76 ;
F_39 ( V_41 ) ;
} else {
F_40 (bvec, bio, i) {
struct V_15 * V_15 = V_74 -> V_78 ;
if ( V_5 -> V_13 == V_26 && ! F_41 ( V_15 ) &&
V_5 -> V_63 )
F_42 ( V_15 ) ;
F_33 ( V_15 ) ;
}
V_31 = V_41 -> V_76 ;
F_43 ( V_41 ) ;
}
return V_31 ;
}
static void F_44 ( struct V_5 * V_5 )
{
struct V_41 * V_41 ;
do {
V_41 = F_34 ( V_5 ) ;
if ( V_41 )
F_18 ( V_5 , V_41 ) ;
} while ( V_41 );
}
static inline int F_45 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_79 ++ >= 64 ) {
while ( V_5 -> V_50 ) {
unsigned long V_33 ;
struct V_41 * V_41 ;
int V_80 ;
F_19 ( & V_5 -> V_44 , V_33 ) ;
V_41 = V_5 -> V_50 ;
V_5 -> V_50 = V_41 -> V_42 ;
F_21 ( & V_5 -> V_44 , V_33 ) ;
V_80 = F_18 ( V_5 , V_41 ) ;
if ( V_6 == 0 )
V_6 = V_80 ;
}
V_2 -> V_79 = 0 ;
}
return V_6 ;
}
static int F_46 ( struct V_81 * V_82 )
{
struct V_83 * V_84 ;
struct V_83 * V_85 = F_47 ( L_1 ,
V_86 , 0 ,
V_82 -> V_87 ) ;
if ( ! V_85 )
return - V_88 ;
V_84 = F_48 ( & V_82 -> V_49 , NULL , V_85 ) ;
if ( V_84 )
F_49 ( V_85 ) ;
return 0 ;
}
static int F_50 ( struct V_5 * V_5 )
{
struct V_81 * V_82 = V_5 -> V_35 -> V_48 ;
if ( V_5 -> V_47 )
return 0 ;
V_5 -> V_47 = true ;
if ( ! V_82 -> V_49 )
return F_46 ( V_82 ) ;
return 0 ;
}
static int F_51 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_89 * V_90 )
{
int V_6 ;
T_3 V_91 ;
T_3 V_92 ;
unsigned long V_93 ;
int V_94 ;
unsigned int V_95 = V_2 -> V_96 + V_2 -> V_97 ;
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_98 >= V_2 -> V_99 ) ;
V_91 = V_2 -> V_98 >> V_2 -> V_97 ;
V_92 = ( V_2 -> V_99 - 1 ) >>
V_2 -> V_97 ;
V_93 = V_92 - V_91 + 1 ;
V_90 -> V_100 = 0 ;
V_90 -> V_101 = V_93 << V_95 ;
V_94 = V_5 -> V_13 == V_14 ;
if ( V_5 -> V_33 & V_102 ) {
if ( V_91 <= ( ( F_52 ( V_5 -> V_35 ) - 1 ) >>
V_95 ) )
V_94 = 0 ;
}
V_6 = (* V_2 -> V_103 )( V_5 -> V_35 , V_91 ,
V_90 , V_94 ) ;
V_5 -> V_32 = V_90 -> V_104 ;
if ( V_6 == 0 && F_53 ( V_90 ) )
V_6 = F_50 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_54 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_105 , struct V_89 * V_90 )
{
T_3 V_106 ;
int V_6 , V_107 ;
V_6 = F_45 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_108;
V_106 = V_105 << ( V_2 -> V_96 - 9 ) ;
V_107 = F_55 ( V_2 -> V_109 , V_110 ) ;
F_9 ( V_107 <= 0 ) ;
F_26 ( V_5 , V_2 , V_90 -> V_111 , V_106 , V_107 ) ;
V_2 -> V_68 = 0 ;
V_108:
return V_6 ;
}
static inline int F_56 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_57 ( V_2 -> V_41 , V_2 -> V_112 ,
V_2 -> V_113 , V_2 -> V_114 ) ;
if ( V_6 == V_2 -> V_113 ) {
if ( ( V_2 -> V_113 + V_2 -> V_114 ) == V_18 )
V_2 -> V_109 -- ;
F_5 ( V_2 -> V_112 ) ;
V_2 -> V_115 = V_2 -> V_116 +
( V_2 -> V_113 >> V_2 -> V_96 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_58 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_89 * V_90 )
{
int V_6 = 0 ;
if ( V_2 -> V_41 ) {
T_2 V_117 = V_2 -> V_62 ;
T_2 V_118 = V_2 -> V_61 +
V_2 -> V_41 -> V_57 . V_119 ;
if ( V_2 -> V_115 != V_2 -> V_116 ||
V_117 != V_118 )
F_29 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_41 == NULL ) {
V_6 = F_54 ( V_5 , V_2 , V_2 -> V_116 , V_90 ) ;
if ( V_6 )
goto V_108;
}
if ( F_56 ( V_2 ) != 0 ) {
F_29 ( V_5 , V_2 ) ;
V_6 = F_54 ( V_5 , V_2 , V_2 -> V_116 , V_90 ) ;
if ( V_6 == 0 ) {
V_6 = F_56 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_108:
return V_6 ;
}
static inline int
F_59 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned V_20 , unsigned V_120 , T_3 V_121 ,
struct V_89 * V_90 )
{
int V_6 = 0 ;
if ( V_5 -> V_13 == V_14 ) {
F_60 ( V_120 ) ;
}
if ( V_2 -> V_112 == V_15 &&
V_2 -> V_114 + V_2 -> V_113 == V_20 &&
V_2 -> V_116 +
( V_2 -> V_113 >> V_2 -> V_96 ) == V_121 ) {
V_2 -> V_113 += V_120 ;
goto V_108;
}
if ( V_2 -> V_112 ) {
V_6 = F_58 ( V_5 , V_2 , V_90 ) ;
F_33 ( V_2 -> V_112 ) ;
V_2 -> V_112 = NULL ;
if ( V_6 )
return V_6 ;
}
F_5 ( V_15 ) ;
V_2 -> V_112 = V_15 ;
V_2 -> V_114 = V_20 ;
V_2 -> V_113 = V_120 ;
V_2 -> V_116 = V_121 ;
V_2 -> V_62 = V_2 -> V_98 << V_2 -> V_96 ;
V_108:
if ( V_2 -> V_68 ) {
V_6 = F_58 ( V_5 , V_2 , V_90 ) ;
F_29 ( V_5 , V_2 ) ;
F_33 ( V_2 -> V_112 ) ;
V_2 -> V_112 = NULL ;
}
return V_6 ;
}
static void F_61 ( struct V_5 * V_5 , struct V_89 * V_90 )
{
unsigned V_75 ;
unsigned V_122 ;
V_122 = V_90 -> V_101 >> V_5 -> V_35 -> V_95 ;
for ( V_75 = 0 ; V_75 < V_122 ; V_75 ++ ) {
F_62 ( V_90 -> V_111 ,
V_90 -> V_123 + V_75 ) ;
}
}
static inline void F_63 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_124 , struct V_89 * V_90 )
{
unsigned V_125 ;
unsigned V_126 ;
unsigned V_127 ;
struct V_15 * V_15 ;
V_2 -> V_128 = 1 ;
if ( ! V_2 -> V_97 || ! F_64 ( V_90 ) )
return;
V_125 = 1 << V_2 -> V_97 ;
V_126 = V_2 -> V_98 & ( V_125 - 1 ) ;
if ( ! V_126 )
return;
if ( V_124 )
V_126 = V_125 - V_126 ;
V_127 = V_126 << V_2 -> V_96 ;
V_15 = F_4 ( 0 ) ;
if ( F_59 ( V_5 , V_2 , V_15 , 0 , V_127 ,
V_2 -> V_129 , V_90 ) )
return;
V_2 -> V_129 += V_126 ;
}
static int F_65 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_89 * V_90 )
{
const unsigned V_96 = V_2 -> V_96 ;
int V_6 = 0 ;
while ( V_2 -> V_98 < V_2 -> V_99 ) {
struct V_15 * V_15 ;
T_4 V_11 , V_17 ;
V_15 = F_7 ( V_5 , V_2 ) ;
if ( F_66 ( V_15 ) ) {
V_6 = F_67 ( V_15 ) ;
goto V_108;
}
V_11 = V_2 -> V_4 ? 0 : V_2 -> V_11 ;
V_17 = ( V_2 -> V_4 == V_2 -> V_3 - 1 ) ? V_2 -> V_17 : V_18 ;
V_2 -> V_4 ++ ;
while ( V_11 < V_17 ) {
unsigned V_127 ;
unsigned V_126 ;
unsigned V_130 ;
if ( V_2 -> V_12 == 0 ) {
unsigned long V_131 ;
unsigned long V_132 ;
V_6 = F_51 ( V_5 , V_2 , V_90 ) ;
if ( V_6 ) {
F_33 ( V_15 ) ;
goto V_108;
}
if ( ! F_68 ( V_90 ) )
goto V_133;
V_2 -> V_12 =
V_90 -> V_101 >> V_2 -> V_96 ;
V_2 -> V_129 =
V_90 -> V_123 << V_2 -> V_97 ;
if ( F_64 ( V_90 ) )
F_61 ( V_5 , V_90 ) ;
if ( ! V_2 -> V_97 )
goto V_133;
V_131 = ( 1 << V_2 -> V_97 ) - 1 ;
V_132 = ( V_2 -> V_98 & V_131 ) ;
if ( ! F_64 ( V_90 ) )
V_2 -> V_129 += V_132 ;
V_2 -> V_12 -= V_132 ;
}
V_133:
if ( ! F_68 ( V_90 ) ) {
T_2 V_134 ;
if ( V_5 -> V_13 == V_14 ) {
F_33 ( V_15 ) ;
return - V_135 ;
}
V_134 = F_69 ( F_52 ( V_5 -> V_35 ) ,
1 << V_96 ) ;
if ( V_2 -> V_98 >=
V_134 >> V_96 ) {
F_33 ( V_15 ) ;
goto V_108;
}
F_70 ( V_15 , V_11 , 1 << V_96 ) ;
V_2 -> V_98 ++ ;
V_11 += 1 << V_96 ;
V_5 -> V_25 += 1 << V_96 ;
goto V_136;
}
if ( F_11 ( V_2 -> V_97 && ! V_2 -> V_128 ) )
F_63 ( V_5 , V_2 , 0 , V_90 ) ;
V_126 = V_2 -> V_12 ;
V_130 = ( V_17 - V_11 ) >> V_96 ;
if ( V_126 > V_130 )
V_126 = V_130 ;
V_130 = V_2 -> V_99 - V_2 -> V_98 ;
if ( V_126 > V_130 )
V_126 = V_130 ;
V_127 = V_126 << V_96 ;
F_9 ( V_127 == 0 ) ;
if ( V_126 == V_2 -> V_12 )
V_2 -> V_68 = F_71 ( V_90 ) ;
V_6 = F_59 ( V_5 , V_2 , V_15 ,
V_11 ,
V_127 ,
V_2 -> V_129 ,
V_90 ) ;
if ( V_6 ) {
F_33 ( V_15 ) ;
goto V_108;
}
V_2 -> V_129 += V_126 ;
V_2 -> V_98 += V_126 ;
V_11 += V_127 ;
V_5 -> V_25 += V_127 ;
V_2 -> V_12 -= V_126 ;
V_136:
F_9 ( V_2 -> V_98 > V_2 -> V_99 ) ;
if ( V_2 -> V_98 == V_2 -> V_99 )
break;
}
F_33 ( V_15 ) ;
}
V_108:
return V_6 ;
}
static inline int F_72 ( struct V_5 * V_5 )
{
int V_80 ;
unsigned long V_33 ;
F_19 ( & V_5 -> V_44 , V_33 ) ;
V_80 = -- V_5 -> V_45 ;
F_21 ( & V_5 -> V_44 , V_33 ) ;
return V_80 ;
}
static inline T_1
F_73 ( struct V_137 * V_21 , struct V_35 * V_35 ,
struct V_51 * V_52 , struct V_138 * V_7 ,
T_5 V_103 , T_6 V_30 ,
T_7 V_65 , int V_33 )
{
unsigned V_95 = F_74 ( V_35 -> V_95 ) ;
unsigned V_96 = V_95 ;
unsigned V_139 = ( 1 << V_96 ) - 1 ;
T_1 V_140 = - V_141 ;
T_4 V_142 = F_75 ( V_7 ) ;
T_2 V_20 = V_21 -> V_22 ;
T_2 V_124 = V_20 + V_142 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
struct V_89 V_90 = { 0 , } ;
struct V_143 V_144 ;
unsigned long V_145 = V_20 | F_76 ( V_7 ) ;
if ( V_145 & V_139 ) {
if ( V_52 )
V_96 = F_77 ( F_78 ( V_52 ) ) ;
V_139 = ( 1 << V_96 ) - 1 ;
if ( V_145 & V_139 )
goto V_108;
}
if ( F_79 ( V_7 ) == V_146 && ! F_75 ( V_7 ) )
return 0 ;
V_5 = F_80 ( V_37 , V_55 ) ;
V_140 = - V_88 ;
if ( ! V_5 )
goto V_108;
memset ( V_5 , 0 , F_81 ( struct V_5 , V_8 ) ) ;
V_5 -> V_33 = V_33 ;
if ( V_5 -> V_33 & V_147 ) {
if ( F_79 ( V_7 ) == V_146 ) {
struct V_148 * V_149 =
V_21 -> V_150 -> V_151 ;
F_82 ( V_35 ) ;
V_140 = F_83 ( V_149 , V_20 ,
V_124 - 1 ) ;
if ( V_140 ) {
F_84 ( V_35 ) ;
F_14 ( V_37 , V_5 ) ;
goto V_108;
}
}
}
V_5 -> V_27 = F_52 ( V_35 ) ;
if ( F_79 ( V_7 ) == V_146 && V_20 >= V_5 -> V_27 ) {
if ( V_5 -> V_33 & V_147 )
F_84 ( V_35 ) ;
F_14 ( V_37 , V_5 ) ;
V_140 = 0 ;
goto V_108;
}
if ( F_85 ( V_21 ) )
V_5 -> V_19 = false ;
else if ( ! ( V_5 -> V_33 & V_152 ) &&
F_79 ( V_7 ) == V_153 && V_124 > F_52 ( V_35 ) )
V_5 -> V_19 = false ;
else
V_5 -> V_19 = true ;
V_5 -> V_35 = V_35 ;
if ( F_79 ( V_7 ) == V_153 ) {
V_5 -> V_13 = V_14 ;
V_5 -> V_59 = V_154 ;
} else {
V_5 -> V_13 = V_26 ;
}
if ( V_5 -> V_19 && F_79 ( V_7 ) == V_153 &&
( ( V_21 -> V_150 -> V_155 & V_156 ) ||
F_86 ( V_21 -> V_150 -> V_151 -> V_157 ) ) ) {
V_140 = F_50 ( V_5 ) ;
if ( V_140 ) {
F_14 ( V_37 , V_5 ) ;
goto V_108;
}
}
if ( ! ( V_5 -> V_33 & V_34 ) )
F_87 ( V_35 ) ;
V_140 = 0 ;
V_2 . V_96 = V_96 ;
V_2 . V_97 = V_95 - V_96 ;
V_2 . V_98 = V_20 >> V_96 ;
V_2 . V_103 = V_103 ;
V_5 -> V_30 = V_30 ;
V_2 . V_65 = V_65 ;
V_2 . V_115 = - 1 ;
V_2 . V_129 = - 1 ;
V_5 -> V_21 = V_21 ;
F_88 ( & V_5 -> V_44 ) ;
V_5 -> V_45 = 1 ;
V_5 -> V_63 = ( V_7 -> type == V_158 ) ;
V_2 . V_7 = V_7 ;
V_2 . V_99 =
( V_20 + F_75 ( V_7 ) ) >> V_96 ;
if ( F_11 ( V_2 . V_97 ) )
V_2 . V_109 = 2 ;
V_2 . V_109 += F_89 ( V_7 , V_159 ) ;
F_90 ( & V_144 ) ;
V_140 = F_65 ( V_5 , & V_2 , & V_90 ) ;
if ( V_140 )
F_32 ( V_5 , & V_2 ) ;
if ( V_140 == - V_135 ) {
V_140 = 0 ;
}
F_63 ( V_5 , & V_2 , 1 , & V_90 ) ;
if ( V_2 . V_112 ) {
T_1 V_80 ;
V_80 = F_58 ( V_5 , & V_2 , & V_90 ) ;
if ( V_140 == 0 )
V_140 = V_80 ;
F_33 ( V_2 . V_112 ) ;
V_2 . V_112 = NULL ;
}
if ( V_2 . V_41 )
F_29 ( V_5 , & V_2 ) ;
F_91 ( & V_144 ) ;
F_32 ( V_5 , & V_2 ) ;
if ( F_79 ( V_7 ) == V_146 && ( V_5 -> V_33 & V_147 ) )
F_84 ( V_5 -> V_35 ) ;
F_9 ( V_140 == - V_24 ) ;
if ( V_5 -> V_19 && V_140 == 0 && V_5 -> V_25 &&
( F_79 ( V_7 ) == V_146 || V_5 -> V_25 == V_142 ) )
V_140 = - V_24 ;
else
F_44 ( V_5 ) ;
if ( F_72 ( V_5 ) == 0 ) {
V_140 = F_10 ( V_5 , V_140 , false ) ;
} else
F_9 ( V_140 != - V_24 ) ;
V_108:
return V_140 ;
}
T_1 F_92 ( struct V_137 * V_21 , struct V_35 * V_35 ,
struct V_51 * V_52 , struct V_138 * V_7 ,
T_5 V_103 ,
T_6 V_30 , T_7 V_65 ,
int V_33 )
{
F_93 ( & V_52 -> V_160 -> V_161 ) ;
F_93 ( V_52 -> V_162 ) ;
F_93 ( ( char * ) V_52 -> V_162 + V_163 ) ;
return F_73 ( V_21 , V_35 , V_52 , V_7 , V_103 ,
V_30 , V_65 , V_33 ) ;
}
static T_8 int F_94 ( void )
{
V_37 = F_95 ( V_5 , V_164 ) ;
return 0 ;
}
