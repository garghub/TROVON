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
struct V_59 * V_60 = V_32 -> V_61 ;
int V_62 ;
if ( ! V_56 )
V_5 -> V_27 = - V_63 ;
if ( V_5 -> V_22 && V_5 -> V_12 == V_13 ) {
F_32 ( V_32 ) ;
} else {
for ( V_62 = 0 ; V_62 < V_32 -> V_64 ; V_62 ++ ) {
struct V_17 * V_17 = V_60 [ V_62 ] . V_65 ;
if ( V_5 -> V_12 == V_13 && ! F_33 ( V_17 ) )
F_34 ( V_17 ) ;
F_27 ( V_17 ) ;
}
F_35 ( V_32 ) ;
}
return V_56 ? 0 : - V_63 ;
}
static void F_36 ( struct V_5 * V_5 )
{
struct V_32 * V_32 ;
do {
V_32 = F_28 ( V_5 ) ;
if ( V_32 )
F_14 ( V_5 , V_32 ) ;
} while ( V_32 );
}
static inline int F_37 ( struct V_5 * V_5 , struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( V_2 -> V_66 ++ >= 64 ) {
while ( V_5 -> V_41 ) {
unsigned long V_35 ;
struct V_32 * V_32 ;
int V_67 ;
F_15 ( & V_5 -> V_36 , V_35 ) ;
V_32 = V_5 -> V_41 ;
V_5 -> V_41 = V_32 -> V_33 ;
F_17 ( & V_5 -> V_36 , V_35 ) ;
V_67 = F_14 ( V_5 , V_32 ) ;
if ( V_6 == 0 )
V_6 = V_67 ;
}
V_2 -> V_66 = 0 ;
}
return V_6 ;
}
static int F_38 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_68 * V_69 )
{
int V_6 ;
T_3 V_70 ;
T_3 V_71 ;
unsigned long V_72 ;
int V_73 ;
unsigned int V_74 = V_2 -> V_75 + V_2 -> V_76 ;
V_6 = V_5 -> V_18 ;
if ( V_6 == 0 ) {
F_9 ( V_2 -> V_77 >= V_2 -> V_78 ) ;
V_70 = V_2 -> V_77 >> V_2 -> V_76 ;
V_71 = ( V_2 -> V_78 - 1 ) >>
V_2 -> V_76 ;
V_72 = V_71 - V_70 + 1 ;
V_69 -> V_79 = 0 ;
V_69 -> V_80 = V_72 << V_74 ;
V_73 = V_5 -> V_12 & V_16 ;
if ( V_5 -> V_35 & V_81 ) {
if ( V_2 -> V_77 < ( F_39 ( V_5 -> V_31 ) >>
V_2 -> V_75 ) )
V_73 = 0 ;
}
V_6 = (* V_2 -> V_82 )( V_5 -> V_31 , V_70 ,
V_69 , V_73 ) ;
V_5 -> V_30 = V_69 -> V_83 ;
}
return V_6 ;
}
static inline int F_40 ( struct V_5 * V_5 , struct V_1 * V_2 ,
T_3 V_84 , struct V_68 * V_69 )
{
T_3 V_85 ;
int V_6 , V_7 ;
V_6 = F_37 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_19;
V_85 = V_84 << ( V_2 -> V_75 - 9 ) ;
V_7 = F_3 ( V_2 -> V_86 , F_41 ( V_69 -> V_87 ) ) ;
V_7 = F_3 ( V_7 , V_88 ) ;
F_9 ( V_7 <= 0 ) ;
F_21 ( V_5 , V_2 , V_69 -> V_87 , V_85 , V_7 ) ;
V_2 -> V_53 = 0 ;
V_19:
return V_6 ;
}
static inline int F_42 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_43 ( V_2 -> V_32 , V_2 -> V_89 ,
V_2 -> V_90 , V_2 -> V_91 ) ;
if ( V_6 == V_2 -> V_90 ) {
if ( ( V_2 -> V_90 + V_2 -> V_91 ) == V_20 )
V_2 -> V_86 -- ;
F_6 ( V_2 -> V_89 ) ;
V_2 -> V_92 = V_2 -> V_93 +
( V_2 -> V_90 >> V_2 -> V_75 ) ;
V_6 = 0 ;
} else {
V_6 = 1 ;
}
return V_6 ;
}
static inline int F_44 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_68 * V_69 )
{
int V_6 = 0 ;
if ( V_2 -> V_32 ) {
T_2 V_94 = V_2 -> V_51 ;
T_2 V_95 = V_2 -> V_50 +
V_2 -> V_32 -> V_96 ;
if ( V_2 -> V_92 != V_2 -> V_93 ||
V_94 != V_95 )
F_23 ( V_5 , V_2 ) ;
else if ( V_2 -> V_53 )
F_23 ( V_5 , V_2 ) ;
}
if ( V_2 -> V_32 == NULL ) {
V_6 = F_40 ( V_5 , V_2 , V_2 -> V_93 , V_69 ) ;
if ( V_6 )
goto V_19;
}
if ( F_42 ( V_2 ) != 0 ) {
F_23 ( V_5 , V_2 ) ;
V_6 = F_40 ( V_5 , V_2 , V_2 -> V_93 , V_69 ) ;
if ( V_6 == 0 ) {
V_6 = F_42 ( V_2 ) ;
F_9 ( V_6 != 0 ) ;
}
}
V_19:
return V_6 ;
}
static inline int
F_45 ( struct V_5 * V_5 , struct V_1 * V_2 , struct V_17 * V_17 ,
unsigned V_21 , unsigned V_97 , T_3 V_98 ,
struct V_68 * V_69 )
{
int V_6 = 0 ;
if ( V_5 -> V_12 & V_16 ) {
F_46 ( V_97 ) ;
}
if ( V_2 -> V_89 == V_17 &&
V_2 -> V_91 + V_2 -> V_90 == V_21 &&
V_2 -> V_93 +
( V_2 -> V_90 >> V_2 -> V_75 ) == V_98 ) {
V_2 -> V_90 += V_97 ;
if ( V_2 -> V_53 ) {
V_6 = F_44 ( V_5 , V_2 , V_69 ) ;
F_27 ( V_2 -> V_89 ) ;
V_2 -> V_89 = NULL ;
}
goto V_19;
}
if ( V_2 -> V_89 ) {
V_6 = F_44 ( V_5 , V_2 , V_69 ) ;
F_27 ( V_2 -> V_89 ) ;
V_2 -> V_89 = NULL ;
if ( V_6 )
goto V_19;
}
F_6 ( V_17 ) ;
V_2 -> V_89 = V_17 ;
V_2 -> V_91 = V_21 ;
V_2 -> V_90 = V_97 ;
V_2 -> V_93 = V_98 ;
V_2 -> V_51 = V_2 -> V_77 << V_2 -> V_75 ;
V_19:
return V_6 ;
}
static void F_47 ( struct V_5 * V_5 , struct V_68 * V_69 )
{
unsigned V_99 ;
unsigned V_100 ;
V_100 = V_69 -> V_80 >> V_5 -> V_31 -> V_74 ;
for ( V_99 = 0 ; V_99 < V_100 ; V_99 ++ ) {
F_48 ( V_69 -> V_87 ,
V_69 -> V_101 + V_99 ) ;
}
}
static inline void F_49 ( struct V_5 * V_5 , struct V_1 * V_2 ,
int V_102 , struct V_68 * V_69 )
{
unsigned V_103 ;
unsigned V_104 ;
unsigned V_105 ;
struct V_17 * V_17 ;
V_2 -> V_106 = 1 ;
if ( ! V_2 -> V_76 || ! F_50 ( V_69 ) )
return;
V_103 = 1 << V_2 -> V_76 ;
V_104 = V_2 -> V_77 & ( V_103 - 1 ) ;
if ( ! V_104 )
return;
if ( V_102 )
V_104 = V_103 - V_104 ;
V_105 = V_104 << V_2 -> V_75 ;
V_17 = F_5 ( 0 ) ;
if ( F_45 ( V_5 , V_2 , V_17 , 0 , V_105 ,
V_2 -> V_107 , V_69 ) )
return;
V_2 -> V_107 += V_104 ;
}
static int F_51 ( struct V_5 * V_5 , struct V_1 * V_2 ,
struct V_68 * V_69 )
{
const unsigned V_75 = V_2 -> V_75 ;
const unsigned V_108 = V_20 >> V_75 ;
struct V_17 * V_17 ;
unsigned V_109 ;
int V_6 = 0 ;
V_109 = V_2 -> V_110 ;
while ( V_2 -> V_77 < V_2 -> V_78 ) {
V_17 = F_7 ( V_5 , V_2 ) ;
if ( F_52 ( V_17 ) ) {
V_6 = F_53 ( V_17 ) ;
goto V_19;
}
while ( V_109 < V_108 ) {
unsigned V_111 = V_109 << V_75 ;
unsigned V_105 ;
unsigned V_104 ;
unsigned V_112 ;
if ( V_2 -> V_15 == 0 ) {
unsigned long V_113 ;
unsigned long V_114 ;
V_6 = F_38 ( V_5 , V_2 , V_69 ) ;
if ( V_6 ) {
F_27 ( V_17 ) ;
goto V_19;
}
if ( ! F_54 ( V_69 ) )
goto V_115;
V_2 -> V_15 =
V_69 -> V_80 >> V_2 -> V_75 ;
V_2 -> V_107 =
V_69 -> V_101 << V_2 -> V_76 ;
if ( F_50 ( V_69 ) )
F_47 ( V_5 , V_69 ) ;
if ( ! V_2 -> V_76 )
goto V_115;
V_113 = ( 1 << V_2 -> V_76 ) - 1 ;
V_114 = ( V_2 -> V_77 & V_113 ) ;
if ( ! F_50 ( V_69 ) )
V_2 -> V_107 += V_114 ;
V_2 -> V_15 -= V_114 ;
}
V_115:
if ( ! F_54 ( V_69 ) ) {
T_2 V_116 ;
if ( V_5 -> V_12 & V_16 ) {
F_27 ( V_17 ) ;
return - V_117 ;
}
V_116 = F_55 ( F_39 ( V_5 -> V_31 ) ,
1 << V_75 ) ;
if ( V_2 -> V_77 >=
V_116 >> V_75 ) {
F_27 ( V_17 ) ;
goto V_19;
}
F_56 ( V_17 , V_109 << V_75 ,
1 << V_75 ) ;
V_2 -> V_77 ++ ;
V_109 ++ ;
goto V_118;
}
if ( F_57 ( V_2 -> V_76 && ! V_2 -> V_106 ) )
F_49 ( V_5 , V_2 , 0 , V_69 ) ;
V_104 = V_2 -> V_15 ;
V_112 = ( V_20 - V_111 ) >> V_75 ;
if ( V_104 > V_112 )
V_104 = V_112 ;
V_112 = V_2 -> V_78 - V_2 -> V_77 ;
if ( V_104 > V_112 )
V_104 = V_112 ;
V_105 = V_104 << V_75 ;
F_9 ( V_105 == 0 ) ;
V_2 -> V_53 = F_58 ( V_69 ) ;
V_6 = F_45 ( V_5 , V_2 , V_17 ,
V_111 ,
V_105 ,
V_2 -> V_107 ,
V_69 ) ;
if ( V_6 ) {
F_27 ( V_17 ) ;
goto V_19;
}
V_2 -> V_107 += V_104 ;
V_2 -> V_77 += V_104 ;
V_109 += V_104 ;
V_2 -> V_15 -= V_104 ;
V_118:
F_9 ( V_2 -> V_77 > V_2 -> V_78 ) ;
if ( V_2 -> V_77 == V_2 -> V_78 )
break;
}
F_27 ( V_17 ) ;
V_109 = 0 ;
}
V_19:
return V_6 ;
}
static inline int F_59 ( struct V_5 * V_5 )
{
int V_67 ;
unsigned long V_35 ;
F_15 ( & V_5 -> V_36 , V_35 ) ;
V_67 = -- V_5 -> V_37 ;
F_17 ( & V_5 -> V_36 , V_35 ) ;
return V_67 ;
}
static inline T_1
F_60 ( int V_12 , struct V_119 * V_29 , struct V_31 * V_31 ,
struct V_42 * V_43 , const struct V_120 * V_121 , T_2 V_21 ,
unsigned long V_122 , T_4 V_82 , T_5 V_28 ,
T_6 V_52 , int V_35 )
{
int V_123 ;
T_7 V_124 ;
unsigned long V_125 ;
unsigned V_74 = F_61 ( V_31 -> V_74 ) ;
unsigned V_75 = V_74 ;
unsigned V_126 = ( 1 << V_75 ) - 1 ;
T_1 V_127 = - V_128 ;
T_2 V_102 = V_21 ;
struct V_5 * V_5 ;
struct V_1 V_2 = { 0 , } ;
unsigned long V_129 ;
T_7 V_130 ;
struct V_68 V_69 = { 0 , } ;
struct V_131 V_132 ;
if ( V_12 & V_16 )
V_12 = V_133 ;
if ( V_21 & V_126 ) {
if ( V_43 )
V_75 = F_62 ( F_63 ( V_43 ) ) ;
V_126 = ( 1 << V_75 ) - 1 ;
if ( V_21 & V_126 )
goto V_19;
}
for ( V_123 = 0 ; V_123 < V_122 ; V_123 ++ ) {
V_125 = ( unsigned long ) V_121 [ V_123 ] . V_134 ;
V_124 = V_121 [ V_123 ] . V_135 ;
V_102 += V_124 ;
if ( F_57 ( ( V_125 & V_126 ) ||
( V_124 & V_126 ) ) ) {
if ( V_43 )
V_75 = F_62 (
F_63 ( V_43 ) ) ;
V_126 = ( 1 << V_75 ) - 1 ;
if ( ( V_125 & V_126 ) || ( V_124 & V_126 ) )
goto V_19;
}
}
if ( V_12 == V_13 && V_102 == V_21 )
return 0 ;
V_5 = F_64 ( V_40 , V_46 ) ;
V_127 = - V_136 ;
if ( ! V_5 )
goto V_19;
memset ( V_5 , 0 , F_65 ( struct V_5 , V_14 ) ) ;
V_5 -> V_35 = V_35 ;
if ( V_5 -> V_35 & V_137 ) {
if ( V_12 == V_13 ) {
struct V_138 * V_139 =
V_29 -> V_140 -> V_141 ;
F_66 ( & V_31 -> V_142 ) ;
V_127 = F_67 ( V_139 , V_21 ,
V_102 - 1 ) ;
if ( V_127 ) {
F_68 ( & V_31 -> V_142 ) ;
F_18 ( V_40 , V_5 ) ;
goto V_19;
}
}
}
F_69 ( & V_31 -> V_143 ) ;
V_5 -> V_22 = ! F_70 ( V_29 ) && ! ( ( V_12 & V_16 ) &&
( V_102 > F_39 ( V_31 ) ) ) ;
V_127 = 0 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_12 = V_12 ;
V_2 . V_75 = V_75 ;
V_2 . V_76 = V_74 - V_75 ;
V_2 . V_77 = V_21 >> V_75 ;
V_2 . V_82 = V_82 ;
V_5 -> V_28 = V_28 ;
V_2 . V_52 = V_52 ;
V_2 . V_92 = - 1 ;
V_2 . V_107 = - 1 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_26 = F_39 ( V_31 ) ;
F_71 ( & V_5 -> V_36 ) ;
V_5 -> V_37 = 1 ;
if ( F_57 ( V_2 . V_76 ) )
V_2 . V_86 = 2 ;
for ( V_123 = 0 ; V_123 < V_122 ; V_123 ++ ) {
V_129 = ( unsigned long ) V_121 [ V_123 ] . V_134 ;
V_2 . V_86 +=
( ( V_129 + V_121 [ V_123 ] . V_135 + V_20 - 1 ) /
V_20 - V_129 / V_20 ) ;
}
F_72 ( & V_132 ) ;
for ( V_123 = 0 ; V_123 < V_122 ; V_123 ++ ) {
V_129 = ( unsigned long ) V_121 [ V_123 ] . V_134 ;
V_2 . V_124 += V_130 = V_121 [ V_123 ] . V_135 ;
V_2 . V_110 = ( V_129 & ~ V_144 ) >> V_75 ;
V_2 . V_78 = V_2 . V_77 +
( V_130 >> V_75 ) ;
V_2 . V_4 = 0 ;
V_2 . V_3 = 0 ;
V_2 . V_9 = 0 ;
V_2 . V_8 = 0 ;
if ( V_129 & ( V_20 - 1 ) ) {
V_2 . V_8 ++ ;
V_130 -= V_20 - ( V_129 & ( V_20 - 1 ) ) ;
}
V_2 . V_8 += ( V_130 + V_20 - 1 ) / V_20 ;
V_2 . V_11 = V_129 ;
V_127 = F_51 ( V_5 , & V_2 , & V_69 ) ;
V_5 -> V_25 += V_121 [ V_123 ] . V_135 -
( ( V_2 . V_78 - V_2 . V_77 ) <<
V_75 ) ;
if ( V_127 ) {
F_26 ( V_5 , & V_2 ) ;
break;
}
}
if ( V_127 == - V_117 ) {
V_127 = 0 ;
}
F_49 ( V_5 , & V_2 , 1 , & V_69 ) ;
if ( V_2 . V_89 ) {
T_1 V_67 ;
V_67 = F_44 ( V_5 , & V_2 , & V_69 ) ;
if ( V_127 == 0 )
V_127 = V_67 ;
F_27 ( V_2 . V_89 ) ;
V_2 . V_89 = NULL ;
}
if ( V_2 . V_32 )
F_23 ( V_5 , & V_2 ) ;
F_73 ( & V_132 ) ;
F_26 ( V_5 , & V_2 ) ;
if ( V_12 == V_13 && ( V_5 -> V_35 & V_137 ) )
F_68 ( & V_5 -> V_31 -> V_142 ) ;
F_9 ( V_127 == - V_24 ) ;
if ( V_5 -> V_22 && V_127 == 0 && V_5 -> V_25 &&
( ( V_12 == V_13 ) || ( V_5 -> V_25 == V_2 . V_124 ) ) )
V_127 = - V_24 ;
if ( V_127 != - V_24 )
F_36 ( V_5 ) ;
if ( F_59 ( V_5 ) == 0 ) {
V_127 = F_10 ( V_5 , V_21 , V_127 , false ) ;
F_18 ( V_40 , V_5 ) ;
} else
F_9 ( V_127 != - V_24 ) ;
V_19:
return V_127 ;
}
T_1
F_74 ( int V_12 , struct V_119 * V_29 , struct V_31 * V_31 ,
struct V_42 * V_43 , const struct V_120 * V_121 , T_2 V_21 ,
unsigned long V_122 , T_4 V_82 , T_5 V_28 ,
T_6 V_52 , int V_35 )
{
F_75 ( & V_43 -> V_145 -> V_146 ) ;
F_75 ( V_43 -> V_147 ) ;
F_75 ( ( char * ) V_43 -> V_147 + V_148 ) ;
return F_60 ( V_12 , V_29 , V_31 , V_43 , V_121 , V_21 ,
V_122 , V_82 , V_28 ,
V_52 , V_35 ) ;
}
static T_8 int F_76 ( void )
{
V_40 = F_77 ( V_5 , V_149 ) ;
return 0 ;
}
