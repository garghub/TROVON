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
static T_1 F_10 ( struct V_5 * V_5 , T_2 V_21 , T_1 V_6 , bool V_22 )
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
if ( V_5 -> V_28 && V_5 -> V_25 ) {
V_5 -> V_28 ( V_5 -> V_29 , V_21 , V_23 ,
V_5 -> V_30 , V_6 , V_22 ) ;
} else {
F_11 ( V_5 -> V_31 ) ;
if ( V_22 )
F_12 ( V_5 -> V_29 , V_6 , 0 ) ;
}
return V_6 ;
}
static void F_13 ( struct V_32 * V_32 , int error )
{
struct V_5 * V_5 = V_32 -> V_33 ;
unsigned long V_34 ;
unsigned long V_35 ;
F_14 ( V_5 , V_32 ) ;
F_15 ( & V_5 -> V_36 , V_35 ) ;
V_34 = -- V_5 -> V_37 ;
if ( V_34 == 1 && V_5 -> V_38 )
F_16 ( V_5 -> V_38 ) ;
F_17 ( & V_5 -> V_36 , V_35 ) ;
if ( V_34 == 0 ) {
F_10 ( V_5 , V_5 -> V_29 -> V_39 , 0 , true ) ;
F_18 ( V_40 , V_5 ) ;
}
}
static void F_19 ( struct V_32 * V_32 , int error )
{
struct V_5 * V_5 = V_32 -> V_33 ;
unsigned long V_35 ;
F_15 ( & V_5 -> V_36 , V_35 ) ;
V_32 -> V_33 = V_5 -> V_41 ;
V_5 -> V_41 = V_32 ;
if ( -- V_5 -> V_37 == 1 && V_5 -> V_38 )
F_16 ( V_5 -> V_38 ) ;
F_17 ( & V_5 -> V_36 , V_35 ) ;
}
void F_20 ( struct V_32 * V_32 , int error )
{
struct V_5 * V_5 = V_32 -> V_33 ;
if ( V_5 -> V_22 )
F_13 ( V_32 , error ) ;
else
F_19 ( V_32 , error ) ;
}
static inline void
F_21 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_42 * V_43 ,
T_3 V_44 , int V_45 )
{
struct V_32 * V_32 ;
V_32 = F_22 ( V_46 , V_45 ) ;
V_32 -> V_47 = V_43 ;
V_32 -> V_48 = V_44 ;
if ( V_5 -> V_22 )
V_32 -> V_49 = F_13 ;
else
V_32 -> V_49 = F_19 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_50 = V_2 -> V_51 ;
}
static inline void F_23 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
struct V_32 * V_32 = V_2 -> V_32 ;
unsigned long V_35 ;
V_32 -> V_33 = V_5 ;
F_15 ( & V_5 -> V_36 , V_35 ) ;
V_5 -> V_37 ++ ;
F_17 ( & V_5 -> V_36 , V_35 ) ;
if ( V_5 -> V_22 && V_5 -> V_12 == V_13 )
F_24 ( V_32 ) ;
if ( V_2 -> V_52 )
V_2 -> V_52 ( V_5 -> V_12 , V_32 , V_5 -> V_31 ,
V_2 -> V_50 ) ;
else
F_25 ( V_5 -> V_12 , V_32 ) ;
V_2 -> V_32 = NULL ;
V_2 -> V_53 = 0 ;
V_2 -> V_50 = 0 ;
}
static inline void F_26 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
while ( F_1 ( V_2 ) )
F_27 ( F_7 ( V_5 , V_2 ) ) ;
}
static struct V_32 * F_28 ( struct V_5 * V_5 )
{
unsigned long V_35 ;
struct V_32 * V_32 = NULL ;
F_15 ( & V_5 -> V_36 , V_35 ) ;
while ( V_5 -> V_37 > 1 && V_5 -> V_41 == NULL ) {
F_29 ( V_54 ) ;
V_5 -> V_38 = V_55 ;
F_17 ( & V_5 -> V_36 , V_35 ) ;
F_30 () ;
F_15 ( & V_5 -> V_36 , V_35 ) ;
V_5 -> V_38 = NULL ;
}
if ( V_5 -> V_41 ) {
V_32 = V_5 -> V_41 ;
V_5 -> V_41 = V_32 -> V_33 ;
}
F_17 ( & V_5 -> V_36 , V_35 ) ;
return V_32 ;
}
static int F_14 ( struct V_5 * V_5 , struct V_32 * V_32 )
{
const int V_56 = F_31 ( V_57 , & V_32 -> V_58 ) ;
struct V_59 * V_60 ;
unsigned V_61 ;
if ( ! V_56 )
V_5 -> V_27 = - V_62 ;
if ( V_5 -> V_22 && V_5 -> V_12 == V_13 ) {
F_32 ( V_32 ) ;
} else {
F_33 (bvec, bio, i) {
struct V_17 * V_17 = V_60 -> V_63 ;
if ( V_5 -> V_12 == V_13 && ! F_34 ( V_17 ) )
F_35 ( V_17 ) ;
F_27 ( V_17 ) ;
}
F_36 ( V_32 ) ;
}
return V_56 ? 0 : - V_62 ;
}
static void F_37 ( struct V_5 * V_5 )
{
struct V_32 * V_32 ;
do {
V_32 = F_28 ( V_5 ) ;
if ( V_32 )
F_14 ( V_5 , V_32 ) ;
} while ( V_32 );
}
static inline int F_38 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_64 ++ >= 64 ) {
while ( V_5 -> V_41 ) {
unsigned long V_35 ;
struct V_32 * V_32 ;
int V_65 ;
F_15 ( & V_5 -> V_36 , V_35 ) ;
V_32 = V_5 -> V_41 ;
V_5 -> V_41 = V_32 -> V_33 ;
F_17 ( & V_5 -> V_36 , V_35 ) ;
V_65 = F_14 ( V_5 , V_32 ) ;
if ( V_6 == 0 )
V_6 = V_65 ;
}
V_2 -> V_64 = 0 ;
}
return V_6 ;
}
static int F_39 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_66 * V_67 )
{
int V_6 ;
T_3 V_68 ;
T_3 V_69 ;
unsigned long V_70 ;
int V_71 ;
unsigned int V_72 = V_2 -> V_73 + V_2 -> V_74 ;
V_6 = V_5 -> V_18 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_75 >= V_2 -> V_76 ) ;
V_68 = V_2 -> V_75 >> V_2 -> V_74 ;
V_69 = ( V_2 -> V_76 - 1 ) >>
V_2 -> V_74 ;
V_70 = V_69 - V_68 + 1 ;
V_67 -> V_77 = 0 ;
V_67 -> V_78 = V_70 << V_72 ;
V_71 = V_5 -> V_12 & V_16 ;
if ( V_5 -> V_35 & V_79 ) {
if ( V_2 -> V_75 < ( F_40 ( V_5 -> V_31 ) >>
V_2 -> V_73 ) )
V_71 = 0 ;
}
V_6 = (* V_2 -> V_80 )( V_5 -> V_31 , V_68 ,
V_67 , V_71 ) ;
V_5 -> V_30 = V_67 -> V_81 ;
}
return V_6 ;
}
static inline int F_41 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_82 , struct V_66 * V_67 )
{
T_3 V_83 ;
int V_6 , V_7 ;
V_6 = F_38 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_19;
V_83 = V_82 << ( V_2 -> V_73 - 9 ) ;
V_7 = F_3 ( V_2 -> V_84 , F_42 ( V_67 -> V_85 ) ) ;
V_7 = F_3 ( V_7 , V_86 ) ;
F_9 ( V_7 <= 0 ) ;
F_21 ( V_5 , V_2 , V_67 -> V_85 , V_83 , V_7 ) ;
V_2 -> V_53 = 0 ;
V_19:
return V_6 ;
}
static inline int F_43 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_44 ( V_2 -> V_32 , V_2 -> V_87 ,
V_2 -> V_88 , V_2 -> V_89 ) ;
if ( V_6 == V_2 -> V_88 ) {
if ( ( V_2 -> V_88 + V_2 -> V_89 ) == V_20 )
V_2 -> V_84 -- ;
F_6 ( V_2 -> V_87 ) ;
V_2 -> V_90 = V_2 -> V_91 +
( V_2 -> V_88 >> V_2 -> V_73 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_45 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_66 * V_67 )
{
int V_6 = 0 ;
if ( V_2 -> V_32 ) {
T_2 V_92 = V_2 -> V_51 ;
T_2 V_93 = V_2 -> V_50 +
V_2 -> V_32 -> V_94 ;
if ( V_2 -> V_90 != V_2 -> V_91 ||
V_92 != V_93 )
F_23 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_32 == NULL ) {
V_6 = F_41 ( V_5 , V_2 , V_2 -> V_91 , V_67 ) ;
if ( V_6 )
goto V_19;
}
if ( F_43 ( V_2 ) != 0 ) {
F_23 ( V_5 , V_2 ) ;
V_6 = F_41 ( V_5 , V_2 , V_2 -> V_91 , V_67 ) ;
if ( V_6 == 0 ) {
V_6 = F_43 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_19:
return V_6 ;
}
static inline int
F_46 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_17 * V_17 ,
unsigned V_21 , unsigned V_95 , T_3 V_96 ,
struct V_66 * V_67 )
{
int V_6 = 0 ;
if ( V_5 -> V_12 & V_16 ) {
F_47 ( V_95 ) ;
}
if ( V_2 -> V_87 == V_17 &&
V_2 -> V_89 + V_2 -> V_88 == V_21 &&
V_2 -> V_91 +
( V_2 -> V_88 >> V_2 -> V_73 ) == V_96 ) {
V_2 -> V_88 += V_95 ;
goto V_19;
}
if ( V_2 -> V_87 ) {
V_6 = F_45 ( V_5 , V_2 , V_67 ) ;
F_27 ( V_2 -> V_87 ) ;
V_2 -> V_87 = NULL ;
if ( V_6 )
return V_6 ;
}
F_6 ( V_17 ) ;
V_2 -> V_87 = V_17 ;
V_2 -> V_89 = V_21 ;
V_2 -> V_88 = V_95 ;
V_2 -> V_91 = V_96 ;
V_2 -> V_51 = V_2 -> V_75 << V_2 -> V_73 ;
V_19:
if ( V_2 -> V_53 ) {
V_6 = F_45 ( V_5 , V_2 , V_67 ) ;
F_23 ( V_5 , V_2 ) ;
F_27 ( V_2 -> V_87 ) ;
V_2 -> V_87 = NULL ;
}
return V_6 ;
}
static void F_48 ( struct V_5 * V_5 , struct V_66 * V_67 )
{
unsigned V_61 ;
unsigned V_97 ;
V_97 = V_67 -> V_78 >> V_5 -> V_31 -> V_72 ;
for ( V_61 = 0 ; V_61 < V_97 ; V_61 ++ ) {
F_49 ( V_67 -> V_85 ,
V_67 -> V_98 + V_61 ) ;
}
}
static inline void F_50 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_99 , struct V_66 * V_67 )
{
unsigned V_100 ;
unsigned V_101 ;
unsigned V_102 ;
struct V_17 * V_17 ;
V_2 -> V_103 = 1 ;
if ( ! V_2 -> V_74 || ! F_51 ( V_67 ) )
return;
V_100 = 1 << V_2 -> V_74 ;
V_101 = V_2 -> V_75 & ( V_100 - 1 ) ;
if ( ! V_101 )
return;
if ( V_99 )
V_101 = V_100 - V_101 ;
V_102 = V_101 << V_2 -> V_73 ;
V_17 = F_5 ( 0 ) ;
if ( F_46 ( V_5 , V_2 , V_17 , 0 , V_102 ,
V_2 -> V_104 , V_67 ) )
return;
V_2 -> V_104 += V_101 ;
}
static int F_52 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_66 * V_67 )
{
const unsigned V_73 = V_2 -> V_73 ;
const unsigned V_105 = V_20 >> V_73 ;
struct V_17 * V_17 ;
unsigned V_106 ;
int V_6 = 0 ;
V_106 = V_2 -> V_107 ;
while ( V_2 -> V_75 < V_2 -> V_76 ) {
V_17 = F_7 ( V_5 , V_2 ) ;
if ( F_53 ( V_17 ) ) {
V_6 = F_54 ( V_17 ) ;
goto V_19;
}
while ( V_106 < V_105 ) {
unsigned V_108 = V_106 << V_73 ;
unsigned V_102 ;
unsigned V_101 ;
unsigned V_109 ;
if ( V_2 -> V_15 == 0 ) {
unsigned long V_110 ;
unsigned long V_111 ;
V_6 = F_39 ( V_5 , V_2 , V_67 ) ;
if ( V_6 ) {
F_27 ( V_17 ) ;
goto V_19;
}
if ( ! F_55 ( V_67 ) )
goto V_112;
V_2 -> V_15 =
V_67 -> V_78 >> V_2 -> V_73 ;
V_2 -> V_104 =
V_67 -> V_98 << V_2 -> V_74 ;
if ( F_51 ( V_67 ) )
F_48 ( V_5 , V_67 ) ;
if ( ! V_2 -> V_74 )
goto V_112;
V_110 = ( 1 << V_2 -> V_74 ) - 1 ;
V_111 = ( V_2 -> V_75 & V_110 ) ;
if ( ! F_51 ( V_67 ) )
V_2 -> V_104 += V_111 ;
V_2 -> V_15 -= V_111 ;
}
V_112:
if ( ! F_55 ( V_67 ) ) {
T_2 V_113 ;
if ( V_5 -> V_12 & V_16 ) {
F_27 ( V_17 ) ;
return - V_114 ;
}
V_113 = F_56 ( F_40 ( V_5 -> V_31 ) ,
1 << V_73 ) ;
if ( V_2 -> V_75 >=
V_113 >> V_73 ) {
F_27 ( V_17 ) ;
goto V_19;
}
F_57 ( V_17 , V_106 << V_73 ,
1 << V_73 ) ;
V_2 -> V_75 ++ ;
V_106 ++ ;
goto V_115;
}
if ( F_58 ( V_2 -> V_74 && ! V_2 -> V_103 ) )
F_50 ( V_5 , V_2 , 0 , V_67 ) ;
V_101 = V_2 -> V_15 ;
V_109 = ( V_20 - V_108 ) >> V_73 ;
if ( V_101 > V_109 )
V_101 = V_109 ;
V_109 = V_2 -> V_76 - V_2 -> V_75 ;
if ( V_101 > V_109 )
V_101 = V_109 ;
V_102 = V_101 << V_73 ;
F_9 ( V_102 == 0 ) ;
if ( V_101 == V_2 -> V_15 )
V_2 -> V_53 = F_59 ( V_67 ) ;
V_6 = F_46 ( V_5 , V_2 , V_17 ,
V_108 ,
V_102 ,
V_2 -> V_104 ,
V_67 ) ;
if ( V_6 ) {
F_27 ( V_17 ) ;
goto V_19;
}
V_2 -> V_104 += V_101 ;
V_2 -> V_75 += V_101 ;
V_106 += V_101 ;
V_2 -> V_15 -= V_101 ;
V_115:
F_9 ( V_2 -> V_75 > V_2 -> V_76 ) ;
if ( V_2 -> V_75 == V_2 -> V_76 )
break;
}
F_27 ( V_17 ) ;
V_106 = 0 ;
}
V_19:
return V_6 ;
}
static inline int F_60 ( struct V_5 * V_5 )
{
int V_65 ;
unsigned long V_35 ;
F_15 ( & V_5 -> V_36 , V_35 ) ;
V_65 = -- V_5 -> V_37 ;
F_17 ( & V_5 -> V_36 , V_35 ) ;
return V_65 ;
}
static inline T_1
F_61 ( int V_12 , struct V_116 * V_29 , struct V_31 * V_31 ,
struct V_42 * V_43 , const struct V_117 * V_118 , T_2 V_21 ,
unsigned long V_119 , T_4 V_80 , T_5 V_28 ,
T_6 V_52 , int V_35 )
{
int V_120 ;
T_7 V_121 ;
unsigned long V_122 ;
unsigned V_72 = F_62 ( V_31 -> V_72 ) ;
unsigned V_73 = V_72 ;
unsigned V_123 = ( 1 << V_73 ) - 1 ;
T_1 V_124 = - V_125 ;
T_2 V_99 = V_21 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
unsigned long V_126 ;
T_7 V_127 ;
struct V_66 V_67 = { 0 , } ;
struct V_128 V_129 ;
if ( V_12 & V_16 )
V_12 = V_130 ;
if ( V_21 & V_123 ) {
if ( V_43 )
V_73 = F_63 ( F_64 ( V_43 ) ) ;
V_123 = ( 1 << V_73 ) - 1 ;
if ( V_21 & V_123 )
goto V_19;
}
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
V_122 = ( unsigned long ) V_118 [ V_120 ] . V_131 ;
V_121 = V_118 [ V_120 ] . V_132 ;
V_99 += V_121 ;
if ( F_58 ( ( V_122 & V_123 ) ||
( V_121 & V_123 ) ) ) {
if ( V_43 )
V_73 = F_63 (
F_64 ( V_43 ) ) ;
V_123 = ( 1 << V_73 ) - 1 ;
if ( ( V_122 & V_123 ) || ( V_121 & V_123 ) )
goto V_19;
}
}
if ( V_12 == V_13 && V_99 == V_21 )
return 0 ;
V_5 = F_65 ( V_40 , V_46 ) ;
V_124 = - V_133 ;
if ( ! V_5 )
goto V_19;
memset ( V_5 , 0 , F_66 ( struct V_5 , V_14 ) ) ;
V_5 -> V_35 = V_35 ;
if ( V_5 -> V_35 & V_134 ) {
if ( V_12 == V_13 ) {
struct V_135 * V_136 =
V_29 -> V_137 -> V_138 ;
F_67 ( & V_31 -> V_139 ) ;
V_124 = F_68 ( V_136 , V_21 ,
V_99 - 1 ) ;
if ( V_124 ) {
F_69 ( & V_31 -> V_139 ) ;
F_18 ( V_40 , V_5 ) ;
goto V_19;
}
}
}
F_70 ( & V_31 -> V_140 ) ;
V_5 -> V_22 = ! F_71 ( V_29 ) && ! ( ( V_12 & V_16 ) &&
( V_99 > F_40 ( V_31 ) ) ) ;
V_124 = 0 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_12 = V_12 ;
V_2 . V_73 = V_73 ;
V_2 . V_74 = V_72 - V_73 ;
V_2 . V_75 = V_21 >> V_73 ;
V_2 . V_80 = V_80 ;
V_5 -> V_28 = V_28 ;
V_2 . V_52 = V_52 ;
V_2 . V_90 = - 1 ;
V_2 . V_104 = - 1 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_26 = F_40 ( V_31 ) ;
F_72 ( & V_5 -> V_36 ) ;
V_5 -> V_37 = 1 ;
if ( F_58 ( V_2 . V_74 ) )
V_2 . V_84 = 2 ;
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
V_126 = ( unsigned long ) V_118 [ V_120 ] . V_131 ;
V_2 . V_84 +=
( ( V_126 + V_118 [ V_120 ] . V_132 + V_20 - 1 ) /
V_20 - V_126 / V_20 ) ;
}
F_73 ( & V_129 ) ;
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
V_126 = ( unsigned long ) V_118 [ V_120 ] . V_131 ;
V_2 . V_121 += V_127 = V_118 [ V_120 ] . V_132 ;
V_2 . V_107 = ( V_126 & ~ V_141 ) >> V_73 ;
V_2 . V_76 = V_2 . V_75 +
( V_127 >> V_73 ) ;
V_2 . V_4 = 0 ;
V_2 . V_3 = 0 ;
V_2 . V_9 = 0 ;
V_2 . V_8 = 0 ;
if ( V_126 & ( V_20 - 1 ) ) {
V_2 . V_8 ++ ;
V_127 -= V_20 - ( V_126 & ( V_20 - 1 ) ) ;
}
V_2 . V_8 += ( V_127 + V_20 - 1 ) / V_20 ;
V_2 . V_11 = V_126 ;
V_124 = F_52 ( V_5 , & V_2 , & V_67 ) ;
V_5 -> V_25 += V_118 [ V_120 ] . V_132 -
( ( V_2 . V_76 - V_2 . V_75 ) <<
V_73 ) ;
if ( V_124 ) {
F_26 ( V_5 , & V_2 ) ;
break;
}
}
if ( V_124 == - V_114 ) {
V_124 = 0 ;
}
F_50 ( V_5 , & V_2 , 1 , & V_67 ) ;
if ( V_2 . V_87 ) {
T_1 V_65 ;
V_65 = F_45 ( V_5 , & V_2 , & V_67 ) ;
if ( V_124 == 0 )
V_124 = V_65 ;
F_27 ( V_2 . V_87 ) ;
V_2 . V_87 = NULL ;
}
if ( V_2 . V_32 )
F_23 ( V_5 , & V_2 ) ;
F_74 ( & V_129 ) ;
F_26 ( V_5 , & V_2 ) ;
if ( V_12 == V_13 && ( V_5 -> V_35 & V_134 ) )
F_69 ( & V_5 -> V_31 -> V_139 ) ;
F_9 ( V_124 == - V_24 ) ;
if ( V_5 -> V_22 && V_124 == 0 && V_5 -> V_25 &&
( ( V_12 == V_13 ) || ( V_5 -> V_25 == V_2 . V_121 ) ) )
V_124 = - V_24 ;
if ( V_124 != - V_24 )
F_37 ( V_5 ) ;
if ( F_60 ( V_5 ) == 0 ) {
V_124 = F_10 ( V_5 , V_21 , V_124 , false ) ;
F_18 ( V_40 , V_5 ) ;
} else
F_9 ( V_124 != - V_24 ) ;
V_19:
return V_124 ;
}
T_1
F_75 ( int V_12 , struct V_116 * V_29 , struct V_31 * V_31 ,
struct V_42 * V_43 , const struct V_117 * V_118 , T_2 V_21 ,
unsigned long V_119 , T_4 V_80 , T_5 V_28 ,
T_6 V_52 , int V_35 )
{
F_76 ( & V_43 -> V_142 -> V_143 ) ;
F_76 ( V_43 -> V_144 ) ;
F_76 ( ( char * ) V_43 -> V_144 + V_145 ) ;
return F_61 ( V_12 , V_29 , V_31 , V_43 , V_118 , V_21 ,
V_119 , V_80 , V_28 ,
V_52 , V_35 ) ;
}
static T_8 int F_77 ( void )
{
V_40 = F_78 ( V_5 , V_146 ) ;
return 0 ;
}
