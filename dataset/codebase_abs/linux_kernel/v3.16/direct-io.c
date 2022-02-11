static inline unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 ;
}
static inline int F_2 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_3 ( V_2 -> V_7 , V_5 -> V_8 , V_9 * V_10 ,
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
V_2 -> V_17 = V_10 ;
return 0 ;
}
if ( V_6 >= 0 ) {
F_6 ( V_2 -> V_7 , V_6 ) ;
V_6 += V_2 -> V_11 ;
V_2 -> V_4 = 0 ;
V_2 -> V_3 = ( V_6 + V_10 - 1 ) / V_10 ;
V_2 -> V_17 = ( ( V_6 - 1 ) & ( V_10 - 1 ) ) + 1 ;
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
static T_1 F_10 ( struct V_5 * V_5 , T_2 V_18 , T_1 V_6 ,
bool V_19 )
{
T_1 V_20 = 0 ;
if ( V_6 == - V_21 )
V_6 = 0 ;
if ( V_5 -> V_22 ) {
V_20 = V_5 -> V_22 ;
if ( ( V_5 -> V_13 == V_23 ) && ( ( V_18 + V_20 ) > V_5 -> V_24 ) )
V_20 = V_5 -> V_24 - V_18 ;
}
if ( V_6 == 0 )
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 )
V_6 = V_5 -> V_25 ;
if ( V_6 == 0 )
V_6 = V_20 ;
if ( V_5 -> V_26 && V_5 -> V_22 )
V_5 -> V_26 ( V_5 -> V_27 , V_18 , V_20 , V_5 -> V_28 ) ;
F_11 ( V_5 -> V_29 ) ;
if ( V_19 ) {
if ( V_5 -> V_13 & V_14 ) {
int V_30 ;
V_30 = F_12 ( V_5 -> V_27 -> V_31 , V_18 ,
V_20 ) ;
if ( V_30 < 0 && V_6 > 0 )
V_6 = V_30 ;
}
F_13 ( V_5 -> V_27 , V_6 , 0 ) ;
}
F_14 ( V_32 , V_5 ) ;
return V_6 ;
}
static void F_15 ( struct V_33 * V_34 )
{
struct V_5 * V_5 = F_16 ( V_34 , struct V_5 , V_35 ) ;
F_10 ( V_5 , V_5 -> V_27 -> V_36 , 0 , true ) ;
}
static void F_17 ( struct V_37 * V_37 , int error )
{
struct V_5 * V_5 = V_37 -> V_38 ;
unsigned long V_39 ;
unsigned long V_40 ;
F_18 ( V_5 , V_37 ) ;
F_19 ( & V_5 -> V_41 , V_40 ) ;
V_39 = -- V_5 -> V_42 ;
if ( V_39 == 1 && V_5 -> V_43 )
F_20 ( V_5 -> V_43 ) ;
F_21 ( & V_5 -> V_41 , V_40 ) ;
if ( V_39 == 0 ) {
if ( V_5 -> V_22 && V_5 -> V_44 ) {
F_22 ( & V_5 -> V_35 , F_15 ) ;
F_23 ( V_5 -> V_29 -> V_45 -> V_46 ,
& V_5 -> V_35 ) ;
} else {
F_10 ( V_5 , V_5 -> V_27 -> V_36 , 0 , true ) ;
}
}
}
static void F_24 ( struct V_37 * V_37 , int error )
{
struct V_5 * V_5 = V_37 -> V_38 ;
unsigned long V_40 ;
F_19 ( & V_5 -> V_41 , V_40 ) ;
V_37 -> V_38 = V_5 -> V_47 ;
V_5 -> V_47 = V_37 ;
if ( -- V_5 -> V_42 == 1 && V_5 -> V_43 )
F_20 ( V_5 -> V_43 ) ;
F_21 ( & V_5 -> V_41 , V_40 ) ;
}
void F_25 ( struct V_37 * V_37 , int error )
{
struct V_5 * V_5 = V_37 -> V_38 ;
if ( V_5 -> V_19 )
F_17 ( V_37 , error ) ;
else
F_24 ( V_37 , error ) ;
}
static inline void
F_26 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_48 * V_49 ,
T_3 V_50 , int V_51 )
{
struct V_37 * V_37 ;
V_37 = F_27 ( V_52 , V_51 ) ;
V_37 -> V_53 = V_49 ;
V_37 -> V_54 . V_55 = V_50 ;
if ( V_5 -> V_19 )
V_37 -> V_56 = F_17 ;
else
V_37 -> V_56 = F_24 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_57 = V_2 -> V_58 ;
}
static inline void F_28 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
struct V_37 * V_37 = V_2 -> V_37 ;
unsigned long V_40 ;
V_37 -> V_38 = V_5 ;
F_19 ( & V_5 -> V_41 , V_40 ) ;
V_5 -> V_42 ++ ;
F_21 ( & V_5 -> V_41 , V_40 ) ;
if ( V_5 -> V_19 && V_5 -> V_13 == V_23 )
F_29 ( V_37 ) ;
if ( V_2 -> V_59 )
V_2 -> V_59 ( V_5 -> V_13 , V_37 , V_5 -> V_29 ,
V_2 -> V_57 ) ;
else
F_30 ( V_5 -> V_13 , V_37 ) ;
V_2 -> V_37 = NULL ;
V_2 -> V_60 = 0 ;
V_2 -> V_57 = 0 ;
}
static inline void F_31 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
while ( V_2 -> V_4 < V_2 -> V_3 )
F_32 ( V_5 -> V_8 [ V_2 -> V_4 ++ ] ) ;
}
static struct V_37 * F_33 ( struct V_5 * V_5 )
{
unsigned long V_40 ;
struct V_37 * V_37 = NULL ;
F_19 ( & V_5 -> V_41 , V_40 ) ;
while ( V_5 -> V_42 > 1 && V_5 -> V_47 == NULL ) {
F_34 ( V_61 ) ;
V_5 -> V_43 = V_62 ;
F_21 ( & V_5 -> V_41 , V_40 ) ;
F_35 () ;
F_19 ( & V_5 -> V_41 , V_40 ) ;
V_5 -> V_43 = NULL ;
}
if ( V_5 -> V_47 ) {
V_37 = V_5 -> V_47 ;
V_5 -> V_47 = V_37 -> V_38 ;
}
F_21 ( & V_5 -> V_41 , V_40 ) ;
return V_37 ;
}
static int F_18 ( struct V_5 * V_5 , struct V_37 * V_37 )
{
const int V_63 = F_36 ( V_64 , & V_37 -> V_65 ) ;
struct V_66 * V_67 ;
unsigned V_68 ;
if ( ! V_63 )
V_5 -> V_25 = - V_69 ;
if ( V_5 -> V_19 && V_5 -> V_13 == V_23 ) {
F_37 ( V_37 ) ;
} else {
F_38 (bvec, bio, i) {
struct V_15 * V_15 = V_67 -> V_70 ;
if ( V_5 -> V_13 == V_23 && ! F_39 ( V_15 ) )
F_40 ( V_15 ) ;
F_32 ( V_15 ) ;
}
F_41 ( V_37 ) ;
}
return V_63 ? 0 : - V_69 ;
}
static void F_42 ( struct V_5 * V_5 )
{
struct V_37 * V_37 ;
do {
V_37 = F_33 ( V_5 ) ;
if ( V_37 )
F_18 ( V_5 , V_37 ) ;
} while ( V_37 );
}
static inline int F_43 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_71 ++ >= 64 ) {
while ( V_5 -> V_47 ) {
unsigned long V_40 ;
struct V_37 * V_37 ;
int V_72 ;
F_19 ( & V_5 -> V_41 , V_40 ) ;
V_37 = V_5 -> V_47 ;
V_5 -> V_47 = V_37 -> V_38 ;
F_21 ( & V_5 -> V_41 , V_40 ) ;
V_72 = F_18 ( V_5 , V_37 ) ;
if ( V_6 == 0 )
V_6 = V_72 ;
}
V_2 -> V_71 = 0 ;
}
return V_6 ;
}
static int F_44 ( struct V_73 * V_74 )
{
struct V_75 * V_76 ;
struct V_75 * V_77 = F_45 ( L_1 ,
V_78 , 0 ,
V_74 -> V_79 ) ;
if ( ! V_77 )
return - V_80 ;
V_76 = F_46 ( & V_74 -> V_46 , NULL , V_77 ) ;
if ( V_76 )
F_47 ( V_77 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_5 )
{
struct V_73 * V_74 = V_5 -> V_29 -> V_45 ;
if ( V_5 -> V_44 )
return 0 ;
V_5 -> V_44 = true ;
if ( ! V_74 -> V_46 )
return F_44 ( V_74 ) ;
return 0 ;
}
static int F_49 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_81 * V_82 )
{
int V_6 ;
T_3 V_83 ;
T_3 V_84 ;
unsigned long V_85 ;
int V_86 ;
unsigned int V_87 = V_2 -> V_88 + V_2 -> V_89 ;
V_6 = V_5 -> V_16 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_90 >= V_2 -> V_91 ) ;
V_83 = V_2 -> V_90 >> V_2 -> V_89 ;
V_84 = ( V_2 -> V_91 - 1 ) >>
V_2 -> V_89 ;
V_85 = V_84 - V_83 + 1 ;
V_82 -> V_92 = 0 ;
V_82 -> V_93 = V_85 << V_87 ;
V_86 = V_5 -> V_13 & V_14 ;
if ( V_5 -> V_40 & V_94 ) {
if ( V_2 -> V_90 < ( F_50 ( V_5 -> V_29 ) >>
V_2 -> V_88 ) )
V_86 = 0 ;
}
V_6 = (* V_2 -> V_95 )( V_5 -> V_29 , V_83 ,
V_82 , V_86 ) ;
V_5 -> V_28 = V_82 -> V_96 ;
if ( V_6 == 0 && F_51 ( V_82 ) )
V_6 = F_48 ( V_5 ) ;
}
return V_6 ;
}
static inline int F_52 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_97 , struct V_81 * V_82 )
{
T_3 V_98 ;
int V_6 , V_99 ;
V_6 = F_43 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_100;
V_98 = V_97 << ( V_2 -> V_88 - 9 ) ;
V_99 = F_53 ( V_2 -> V_101 , F_54 ( V_82 -> V_102 ) ) ;
F_9 ( V_99 <= 0 ) ;
F_26 ( V_5 , V_2 , V_82 -> V_102 , V_98 , V_99 ) ;
V_2 -> V_60 = 0 ;
V_100:
return V_6 ;
}
static inline int F_55 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_56 ( V_2 -> V_37 , V_2 -> V_103 ,
V_2 -> V_104 , V_2 -> V_105 ) ;
if ( V_6 == V_2 -> V_104 ) {
if ( ( V_2 -> V_104 + V_2 -> V_105 ) == V_10 )
V_2 -> V_101 -- ;
F_5 ( V_2 -> V_103 ) ;
V_2 -> V_106 = V_2 -> V_107 +
( V_2 -> V_104 >> V_2 -> V_88 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_57 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_81 * V_82 )
{
int V_6 = 0 ;
if ( V_2 -> V_37 ) {
T_2 V_108 = V_2 -> V_58 ;
T_2 V_109 = V_2 -> V_57 +
V_2 -> V_37 -> V_54 . V_110 ;
if ( V_2 -> V_106 != V_2 -> V_107 ||
V_108 != V_109 )
F_28 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_37 == NULL ) {
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_107 , V_82 ) ;
if ( V_6 )
goto V_100;
}
if ( F_55 ( V_2 ) != 0 ) {
F_28 ( V_5 , V_2 ) ;
V_6 = F_52 ( V_5 , V_2 , V_2 -> V_107 , V_82 ) ;
if ( V_6 == 0 ) {
V_6 = F_55 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_100:
return V_6 ;
}
static inline int
F_58 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned V_18 , unsigned V_111 , T_3 V_112 ,
struct V_81 * V_82 )
{
int V_6 = 0 ;
if ( V_5 -> V_13 & V_14 ) {
F_59 ( V_111 ) ;
}
if ( V_2 -> V_103 == V_15 &&
V_2 -> V_105 + V_2 -> V_104 == V_18 &&
V_2 -> V_107 +
( V_2 -> V_104 >> V_2 -> V_88 ) == V_112 ) {
V_2 -> V_104 += V_111 ;
goto V_100;
}
if ( V_2 -> V_103 ) {
V_6 = F_57 ( V_5 , V_2 , V_82 ) ;
F_32 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
if ( V_6 )
return V_6 ;
}
F_5 ( V_15 ) ;
V_2 -> V_103 = V_15 ;
V_2 -> V_105 = V_18 ;
V_2 -> V_104 = V_111 ;
V_2 -> V_107 = V_112 ;
V_2 -> V_58 = V_2 -> V_90 << V_2 -> V_88 ;
V_100:
if ( V_2 -> V_60 ) {
V_6 = F_57 ( V_5 , V_2 , V_82 ) ;
F_28 ( V_5 , V_2 ) ;
F_32 ( V_2 -> V_103 ) ;
V_2 -> V_103 = NULL ;
}
return V_6 ;
}
static void F_60 ( struct V_5 * V_5 , struct V_81 * V_82 )
{
unsigned V_68 ;
unsigned V_113 ;
V_113 = V_82 -> V_93 >> V_5 -> V_29 -> V_87 ;
for ( V_68 = 0 ; V_68 < V_113 ; V_68 ++ ) {
F_61 ( V_82 -> V_102 ,
V_82 -> V_114 + V_68 ) ;
}
}
static inline void F_62 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_115 , struct V_81 * V_82 )
{
unsigned V_116 ;
unsigned V_117 ;
unsigned V_118 ;
struct V_15 * V_15 ;
V_2 -> V_119 = 1 ;
if ( ! V_2 -> V_89 || ! F_63 ( V_82 ) )
return;
V_116 = 1 << V_2 -> V_89 ;
V_117 = V_2 -> V_90 & ( V_116 - 1 ) ;
if ( ! V_117 )
return;
if ( V_115 )
V_117 = V_116 - V_117 ;
V_118 = V_117 << V_2 -> V_88 ;
V_15 = F_4 ( 0 ) ;
if ( F_58 ( V_5 , V_2 , V_15 , 0 , V_118 ,
V_2 -> V_120 , V_82 ) )
return;
V_2 -> V_120 += V_117 ;
}
static int F_64 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_81 * V_82 )
{
const unsigned V_88 = V_2 -> V_88 ;
int V_6 = 0 ;
while ( V_2 -> V_90 < V_2 -> V_91 ) {
struct V_15 * V_15 ;
T_4 V_11 , V_17 ;
V_15 = F_7 ( V_5 , V_2 ) ;
if ( F_65 ( V_15 ) ) {
V_6 = F_66 ( V_15 ) ;
goto V_100;
}
V_11 = V_2 -> V_4 ? 0 : V_2 -> V_11 ;
V_17 = ( V_2 -> V_4 == V_2 -> V_3 - 1 ) ? V_2 -> V_17 : V_10 ;
V_2 -> V_4 ++ ;
while ( V_11 < V_17 ) {
unsigned V_118 ;
unsigned V_117 ;
unsigned V_121 ;
if ( V_2 -> V_12 == 0 ) {
unsigned long V_122 ;
unsigned long V_123 ;
V_6 = F_49 ( V_5 , V_2 , V_82 ) ;
if ( V_6 ) {
F_32 ( V_15 ) ;
goto V_100;
}
if ( ! F_67 ( V_82 ) )
goto V_124;
V_2 -> V_12 =
V_82 -> V_93 >> V_2 -> V_88 ;
V_2 -> V_120 =
V_82 -> V_114 << V_2 -> V_89 ;
if ( F_63 ( V_82 ) )
F_60 ( V_5 , V_82 ) ;
if ( ! V_2 -> V_89 )
goto V_124;
V_122 = ( 1 << V_2 -> V_89 ) - 1 ;
V_123 = ( V_2 -> V_90 & V_122 ) ;
if ( ! F_63 ( V_82 ) )
V_2 -> V_120 += V_123 ;
V_2 -> V_12 -= V_123 ;
}
V_124:
if ( ! F_67 ( V_82 ) ) {
T_2 V_125 ;
if ( V_5 -> V_13 & V_14 ) {
F_32 ( V_15 ) ;
return - V_126 ;
}
V_125 = F_68 ( F_50 ( V_5 -> V_29 ) ,
1 << V_88 ) ;
if ( V_2 -> V_90 >=
V_125 >> V_88 ) {
F_32 ( V_15 ) ;
goto V_100;
}
F_69 ( V_15 , V_11 , 1 << V_88 ) ;
V_2 -> V_90 ++ ;
V_11 += 1 << V_88 ;
V_5 -> V_22 += 1 << V_88 ;
goto V_127;
}
if ( F_70 ( V_2 -> V_89 && ! V_2 -> V_119 ) )
F_62 ( V_5 , V_2 , 0 , V_82 ) ;
V_117 = V_2 -> V_12 ;
V_121 = ( V_17 - V_11 ) >> V_88 ;
if ( V_117 > V_121 )
V_117 = V_121 ;
V_121 = V_2 -> V_91 - V_2 -> V_90 ;
if ( V_117 > V_121 )
V_117 = V_121 ;
V_118 = V_117 << V_88 ;
F_9 ( V_118 == 0 ) ;
if ( V_117 == V_2 -> V_12 )
V_2 -> V_60 = F_71 ( V_82 ) ;
V_6 = F_58 ( V_5 , V_2 , V_15 ,
V_11 ,
V_118 ,
V_2 -> V_120 ,
V_82 ) ;
if ( V_6 ) {
F_32 ( V_15 ) ;
goto V_100;
}
V_2 -> V_120 += V_117 ;
V_2 -> V_90 += V_117 ;
V_11 += V_118 ;
V_5 -> V_22 += V_118 ;
V_2 -> V_12 -= V_117 ;
V_127:
F_9 ( V_2 -> V_90 > V_2 -> V_91 ) ;
if ( V_2 -> V_90 == V_2 -> V_91 )
break;
}
F_32 ( V_15 ) ;
}
V_100:
return V_6 ;
}
static inline int F_72 ( struct V_5 * V_5 )
{
int V_72 ;
unsigned long V_40 ;
F_19 ( & V_5 -> V_41 , V_40 ) ;
V_72 = -- V_5 -> V_42 ;
F_21 ( & V_5 -> V_41 , V_40 ) ;
return V_72 ;
}
static inline T_1
F_73 ( int V_13 , struct V_128 * V_27 , struct V_29 * V_29 ,
struct V_48 * V_49 , struct V_129 * V_7 , T_2 V_18 ,
T_5 V_95 , T_6 V_26 ,
T_7 V_59 , int V_40 )
{
unsigned V_87 = F_74 ( V_29 -> V_87 ) ;
unsigned V_88 = V_87 ;
unsigned V_130 = ( 1 << V_88 ) - 1 ;
T_1 V_131 = - V_132 ;
T_4 V_133 = F_75 ( V_7 ) ;
T_2 V_115 = V_18 + V_133 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
struct V_81 V_82 = { 0 , } ;
struct V_134 V_135 ;
unsigned long V_136 = V_18 | F_76 ( V_7 ) ;
if ( V_13 & V_14 )
V_13 = V_137 ;
if ( V_136 & V_130 ) {
if ( V_49 )
V_88 = F_77 ( F_78 ( V_49 ) ) ;
V_130 = ( 1 << V_88 ) - 1 ;
if ( V_136 & V_130 )
goto V_100;
}
if ( V_13 == V_23 && ! F_75 ( V_7 ) )
return 0 ;
V_5 = F_79 ( V_32 , V_52 ) ;
V_131 = - V_80 ;
if ( ! V_5 )
goto V_100;
memset ( V_5 , 0 , F_80 ( struct V_5 , V_8 ) ) ;
V_5 -> V_40 = V_40 ;
if ( V_5 -> V_40 & V_138 ) {
if ( V_13 == V_23 ) {
struct V_139 * V_140 =
V_27 -> V_31 -> V_141 ;
F_81 ( & V_29 -> V_142 ) ;
V_131 = F_82 ( V_140 , V_18 ,
V_115 - 1 ) ;
if ( V_131 ) {
F_83 ( & V_29 -> V_142 ) ;
F_14 ( V_32 , V_5 ) ;
goto V_100;
}
}
}
if ( F_84 ( V_27 ) )
V_5 -> V_19 = false ;
else if ( ! ( V_5 -> V_40 & V_143 ) &&
( V_13 & V_14 ) && V_115 > F_50 ( V_29 ) )
V_5 -> V_19 = false ;
else
V_5 -> V_19 = true ;
V_5 -> V_29 = V_29 ;
V_5 -> V_13 = V_13 ;
if ( V_5 -> V_19 && ( V_13 & V_14 ) &&
( ( V_27 -> V_31 -> V_144 & V_145 ) ||
F_85 ( V_27 -> V_31 -> V_141 -> V_146 ) ) ) {
V_131 = F_48 ( V_5 ) ;
if ( V_131 ) {
F_14 ( V_32 , V_5 ) ;
goto V_100;
}
}
F_86 ( & V_29 -> V_147 ) ;
V_131 = 0 ;
V_2 . V_88 = V_88 ;
V_2 . V_89 = V_87 - V_88 ;
V_2 . V_90 = V_18 >> V_88 ;
V_2 . V_95 = V_95 ;
V_5 -> V_26 = V_26 ;
V_2 . V_59 = V_59 ;
V_2 . V_106 = - 1 ;
V_2 . V_120 = - 1 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_24 = F_50 ( V_29 ) ;
F_87 ( & V_5 -> V_41 ) ;
V_5 -> V_42 = 1 ;
V_2 . V_7 = V_7 ;
V_2 . V_91 =
( V_18 + F_75 ( V_7 ) ) >> V_88 ;
if ( F_70 ( V_2 . V_89 ) )
V_2 . V_101 = 2 ;
V_2 . V_101 += F_88 ( V_7 , V_148 ) ;
F_89 ( & V_135 ) ;
V_131 = F_64 ( V_5 , & V_2 , & V_82 ) ;
if ( V_131 )
F_31 ( V_5 , & V_2 ) ;
if ( V_131 == - V_126 ) {
V_131 = 0 ;
}
F_62 ( V_5 , & V_2 , 1 , & V_82 ) ;
if ( V_2 . V_103 ) {
T_1 V_72 ;
V_72 = F_57 ( V_5 , & V_2 , & V_82 ) ;
if ( V_131 == 0 )
V_131 = V_72 ;
F_32 ( V_2 . V_103 ) ;
V_2 . V_103 = NULL ;
}
if ( V_2 . V_37 )
F_28 ( V_5 , & V_2 ) ;
F_90 ( & V_135 ) ;
F_31 ( V_5 , & V_2 ) ;
if ( V_13 == V_23 && ( V_5 -> V_40 & V_138 ) )
F_83 ( & V_5 -> V_29 -> V_142 ) ;
F_9 ( V_131 == - V_21 ) ;
if ( V_5 -> V_19 && V_131 == 0 && V_5 -> V_22 &&
( V_13 == V_23 || V_5 -> V_22 == V_133 ) )
V_131 = - V_21 ;
else
F_42 ( V_5 ) ;
if ( F_72 ( V_5 ) == 0 ) {
V_131 = F_10 ( V_5 , V_18 , V_131 , false ) ;
} else
F_9 ( V_131 != - V_21 ) ;
V_100:
return V_131 ;
}
T_1
F_91 ( int V_13 , struct V_128 * V_27 , struct V_29 * V_29 ,
struct V_48 * V_49 , struct V_129 * V_7 , T_2 V_18 ,
T_5 V_95 , T_6 V_26 ,
T_7 V_59 , int V_40 )
{
F_92 ( & V_49 -> V_149 -> V_150 ) ;
F_92 ( V_49 -> V_151 ) ;
F_92 ( ( char * ) V_49 -> V_151 + V_152 ) ;
return F_73 ( V_13 , V_27 , V_29 , V_49 , V_7 , V_18 ,
V_95 , V_26 , V_59 , V_40 ) ;
}
static T_8 int F_93 ( void )
{
V_32 = F_94 ( V_5 , V_153 ) ;
return 0 ;
}
