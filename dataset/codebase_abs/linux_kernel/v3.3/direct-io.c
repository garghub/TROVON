static void F_1 ( struct V_1 * V_1 )
{
T_1 * V_2 = F_2 ( & V_1 -> V_3 , V_4 ) ;
F_3 ( V_5 , & V_1 -> V_3 , V_4 ) ;
do {
F_4 ( V_2 , & V_5 . V_6 , V_7 ) ;
if ( F_5 ( & V_1 -> V_8 ) )
F_6 () ;
} while ( F_5 ( & V_1 -> V_8 ) );
F_7 ( V_2 , & V_5 . V_6 ) ;
}
void F_8 ( struct V_1 * V_1 )
{
if ( F_5 ( & V_1 -> V_8 ) )
F_1 ( V_1 ) ;
}
void F_9 ( struct V_1 * V_1 )
{
if ( F_10 ( & V_1 -> V_8 ) )
F_11 ( & V_1 -> V_3 , V_4 ) ;
}
static inline unsigned F_12 ( struct V_9 * V_10 )
{
return V_10 -> V_11 - V_10 -> V_12 ;
}
static inline int F_13 ( struct V_13 * V_13 , struct V_9 * V_10 )
{
int V_14 ;
int V_15 ;
V_15 = F_14 ( V_10 -> V_16 - V_10 -> V_17 , V_18 ) ;
V_14 = F_15 (
V_10 -> V_19 ,
V_15 ,
V_13 -> V_20 == V_21 ,
& V_13 -> V_22 [ 0 ] ) ;
if ( V_14 < 0 && V_10 -> V_23 && ( V_13 -> V_20 & V_24 ) ) {
struct V_25 * V_25 = F_16 ( 0 ) ;
if ( V_13 -> V_26 == 0 )
V_13 -> V_26 = V_14 ;
F_17 ( V_25 ) ;
V_13 -> V_22 [ 0 ] = V_25 ;
V_10 -> V_12 = 0 ;
V_10 -> V_11 = 1 ;
V_14 = 0 ;
goto V_27;
}
if ( V_14 >= 0 ) {
V_10 -> V_19 += V_14 * V_28 ;
V_10 -> V_17 += V_14 ;
V_10 -> V_12 = 0 ;
V_10 -> V_11 = V_14 ;
V_14 = 0 ;
}
V_27:
return V_14 ;
}
static inline struct V_25 * F_18 ( struct V_13 * V_13 ,
struct V_9 * V_10 )
{
if ( F_12 ( V_10 ) == 0 ) {
int V_14 ;
V_14 = F_13 ( V_13 , V_10 ) ;
if ( V_14 )
return F_19 ( V_14 ) ;
F_20 ( F_12 ( V_10 ) == 0 ) ;
}
return V_13 -> V_22 [ V_10 -> V_12 ++ ] ;
}
static T_2 F_21 ( struct V_13 * V_13 , T_3 V_29 , T_2 V_14 , bool V_30 )
{
T_2 V_31 = 0 ;
if ( V_14 == - V_32 )
V_14 = 0 ;
if ( V_13 -> V_33 ) {
V_31 = V_13 -> V_33 ;
if ( ( V_13 -> V_20 == V_21 ) && ( ( V_29 + V_31 ) > V_13 -> V_34 ) )
V_31 = V_13 -> V_34 - V_29 ;
}
if ( V_14 == 0 )
V_14 = V_13 -> V_26 ;
if ( V_14 == 0 )
V_14 = V_13 -> V_35 ;
if ( V_14 == 0 )
V_14 = V_31 ;
if ( V_13 -> V_36 && V_13 -> V_33 ) {
V_13 -> V_36 ( V_13 -> V_37 , V_29 , V_31 ,
V_13 -> V_38 , V_14 , V_30 ) ;
} else {
if ( V_30 )
F_22 ( V_13 -> V_37 , V_14 , 0 ) ;
F_9 ( V_13 -> V_1 ) ;
}
return V_14 ;
}
static void F_23 ( struct V_39 * V_39 , int error )
{
struct V_13 * V_13 = V_39 -> V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
F_24 ( V_13 , V_39 ) ;
F_25 ( & V_13 -> V_43 , V_42 ) ;
V_41 = -- V_13 -> V_44 ;
if ( V_41 == 1 && V_13 -> V_45 )
F_26 ( V_13 -> V_45 ) ;
F_27 ( & V_13 -> V_43 , V_42 ) ;
if ( V_41 == 0 ) {
F_21 ( V_13 , V_13 -> V_37 -> V_46 , 0 , true ) ;
F_28 ( V_47 , V_13 ) ;
}
}
static void F_29 ( struct V_39 * V_39 , int error )
{
struct V_13 * V_13 = V_39 -> V_40 ;
unsigned long V_42 ;
F_25 ( & V_13 -> V_43 , V_42 ) ;
V_39 -> V_40 = V_13 -> V_48 ;
V_13 -> V_48 = V_39 ;
if ( -- V_13 -> V_44 == 1 && V_13 -> V_45 )
F_26 ( V_13 -> V_45 ) ;
F_27 ( & V_13 -> V_43 , V_42 ) ;
}
void F_30 ( struct V_39 * V_39 , int error )
{
struct V_13 * V_13 = V_39 -> V_40 ;
if ( V_13 -> V_30 )
F_23 ( V_39 , error ) ;
else
F_29 ( V_39 , error ) ;
}
static inline void
F_31 ( struct V_13 * V_13 , struct V_9 * V_10 ,
struct V_49 * V_50 ,
T_4 V_51 , int V_52 )
{
struct V_39 * V_39 ;
V_39 = F_32 ( V_53 , V_52 ) ;
V_39 -> V_54 = V_50 ;
V_39 -> V_55 = V_51 ;
if ( V_13 -> V_30 )
V_39 -> V_56 = F_23 ;
else
V_39 -> V_56 = F_29 ;
V_10 -> V_39 = V_39 ;
V_10 -> V_57 = V_10 -> V_58 ;
}
static inline void F_33 ( struct V_13 * V_13 , struct V_9 * V_10 )
{
struct V_39 * V_39 = V_10 -> V_39 ;
unsigned long V_42 ;
V_39 -> V_40 = V_13 ;
F_25 ( & V_13 -> V_43 , V_42 ) ;
V_13 -> V_44 ++ ;
F_27 ( & V_13 -> V_43 , V_42 ) ;
if ( V_13 -> V_30 && V_13 -> V_20 == V_21 )
F_34 ( V_39 ) ;
if ( V_10 -> V_59 )
V_10 -> V_59 ( V_13 -> V_20 , V_39 , V_13 -> V_1 ,
V_10 -> V_57 ) ;
else
F_35 ( V_13 -> V_20 , V_39 ) ;
V_10 -> V_39 = NULL ;
V_10 -> V_60 = 0 ;
V_10 -> V_57 = 0 ;
}
static inline void F_36 ( struct V_13 * V_13 , struct V_9 * V_10 )
{
while ( F_12 ( V_10 ) )
F_37 ( F_18 ( V_13 , V_10 ) ) ;
}
static struct V_39 * F_38 ( struct V_13 * V_13 )
{
unsigned long V_42 ;
struct V_39 * V_39 = NULL ;
F_25 ( & V_13 -> V_43 , V_42 ) ;
while ( V_13 -> V_44 > 1 && V_13 -> V_48 == NULL ) {
F_39 ( V_7 ) ;
V_13 -> V_45 = V_61 ;
F_27 ( & V_13 -> V_43 , V_42 ) ;
F_40 () ;
F_25 ( & V_13 -> V_43 , V_42 ) ;
V_13 -> V_45 = NULL ;
}
if ( V_13 -> V_48 ) {
V_39 = V_13 -> V_48 ;
V_13 -> V_48 = V_39 -> V_40 ;
}
F_27 ( & V_13 -> V_43 , V_42 ) ;
return V_39 ;
}
static int F_24 ( struct V_13 * V_13 , struct V_39 * V_39 )
{
const int V_62 = F_41 ( V_63 , & V_39 -> V_64 ) ;
struct V_65 * V_66 = V_39 -> V_67 ;
int V_68 ;
if ( ! V_62 )
V_13 -> V_35 = - V_69 ;
if ( V_13 -> V_30 && V_13 -> V_20 == V_21 ) {
F_42 ( V_39 ) ;
} else {
for ( V_68 = 0 ; V_68 < V_39 -> V_70 ; V_68 ++ ) {
struct V_25 * V_25 = V_66 [ V_68 ] . V_71 ;
if ( V_13 -> V_20 == V_21 && ! F_43 ( V_25 ) )
F_44 ( V_25 ) ;
F_37 ( V_25 ) ;
}
F_45 ( V_39 ) ;
}
return V_62 ? 0 : - V_69 ;
}
static void F_46 ( struct V_13 * V_13 )
{
struct V_39 * V_39 ;
do {
V_39 = F_38 ( V_13 ) ;
if ( V_39 )
F_24 ( V_13 , V_39 ) ;
} while ( V_39 );
}
static inline int F_47 ( struct V_13 * V_13 , struct V_9 * V_10 )
{
int V_14 = 0 ;
if ( V_10 -> V_72 ++ >= 64 ) {
while ( V_13 -> V_48 ) {
unsigned long V_42 ;
struct V_39 * V_39 ;
int V_73 ;
F_25 ( & V_13 -> V_43 , V_42 ) ;
V_39 = V_13 -> V_48 ;
V_13 -> V_48 = V_39 -> V_40 ;
F_27 ( & V_13 -> V_43 , V_42 ) ;
V_73 = F_24 ( V_13 , V_39 ) ;
if ( V_14 == 0 )
V_14 = V_73 ;
}
V_10 -> V_72 = 0 ;
}
return V_14 ;
}
static int F_48 ( struct V_13 * V_13 , struct V_9 * V_10 ,
struct V_74 * V_75 )
{
int V_14 ;
T_4 V_76 ;
T_4 V_77 ;
unsigned long V_78 ;
int V_79 ;
V_14 = V_13 -> V_26 ;
if ( V_14 == 0 ) {
F_20 ( V_10 -> V_80 >= V_10 -> V_81 ) ;
V_76 = V_10 -> V_80 >> V_10 -> V_82 ;
V_77 = ( V_10 -> V_81 - 1 ) >>
V_10 -> V_82 ;
V_78 = V_77 - V_76 + 1 ;
V_75 -> V_83 = 0 ;
V_75 -> V_84 = V_78 << V_13 -> V_1 -> V_85 ;
V_79 = V_13 -> V_20 & V_24 ;
if ( V_13 -> V_42 & V_86 ) {
if ( V_10 -> V_80 < ( F_49 ( V_13 -> V_1 ) >>
V_10 -> V_87 ) )
V_79 = 0 ;
}
V_14 = (* V_10 -> V_88 )( V_13 -> V_1 , V_76 ,
V_75 , V_79 ) ;
V_13 -> V_38 = V_75 -> V_89 ;
}
return V_14 ;
}
static inline int F_50 ( struct V_13 * V_13 , struct V_9 * V_10 ,
T_4 V_90 , struct V_74 * V_75 )
{
T_4 V_91 ;
int V_14 , V_15 ;
V_14 = F_47 ( V_13 , V_10 ) ;
if ( V_14 )
goto V_27;
V_91 = V_90 << ( V_10 -> V_87 - 9 ) ;
V_15 = F_14 ( V_10 -> V_92 , F_51 ( V_75 -> V_93 ) ) ;
V_15 = F_14 ( V_15 , V_94 ) ;
F_20 ( V_15 <= 0 ) ;
F_31 ( V_13 , V_10 , V_75 -> V_93 , V_91 , V_15 ) ;
V_10 -> V_60 = 0 ;
V_27:
return V_14 ;
}
static inline int F_52 ( struct V_9 * V_10 )
{
int V_14 ;
V_14 = F_53 ( V_10 -> V_39 , V_10 -> V_95 ,
V_10 -> V_96 , V_10 -> V_97 ) ;
if ( V_14 == V_10 -> V_96 ) {
if ( ( V_10 -> V_96 + V_10 -> V_97 ) == V_28 )
V_10 -> V_92 -- ;
F_17 ( V_10 -> V_95 ) ;
V_10 -> V_98 = V_10 -> V_99 +
( V_10 -> V_96 >> V_10 -> V_87 ) ;
V_14 = 0 ;
} else {
V_14 = 1 ;
}
return V_14 ;
}
static inline int F_54 ( struct V_13 * V_13 , struct V_9 * V_10 ,
struct V_74 * V_75 )
{
int V_14 = 0 ;
if ( V_10 -> V_39 ) {
T_3 V_100 = V_10 -> V_58 ;
T_3 V_101 = V_10 -> V_57 +
V_10 -> V_39 -> V_102 ;
if ( V_10 -> V_98 != V_10 -> V_99 ||
V_100 != V_101 )
F_33 ( V_13 , V_10 ) ;
else if ( V_10 -> V_60 )
F_33 ( V_13 , V_10 ) ;
}
if ( V_10 -> V_39 == NULL ) {
V_14 = F_50 ( V_13 , V_10 , V_10 -> V_99 , V_75 ) ;
if ( V_14 )
goto V_27;
}
if ( F_52 ( V_10 ) != 0 ) {
F_33 ( V_13 , V_10 ) ;
V_14 = F_50 ( V_13 , V_10 , V_10 -> V_99 , V_75 ) ;
if ( V_14 == 0 ) {
V_14 = F_52 ( V_10 ) ;
F_20 ( V_14 != 0 ) ;
}
}
V_27:
return V_14 ;
}
static inline int
F_55 ( struct V_13 * V_13 , struct V_9 * V_10 , struct V_25 * V_25 ,
unsigned V_29 , unsigned V_103 , T_4 V_104 ,
struct V_74 * V_75 )
{
int V_14 = 0 ;
if ( V_13 -> V_20 & V_24 ) {
F_56 ( V_103 ) ;
}
if ( V_10 -> V_95 == V_25 &&
V_10 -> V_97 + V_10 -> V_96 == V_29 &&
V_10 -> V_99 +
( V_10 -> V_96 >> V_10 -> V_87 ) == V_104 ) {
V_10 -> V_96 += V_103 ;
if ( V_10 -> V_60 ) {
V_14 = F_54 ( V_13 , V_10 , V_75 ) ;
F_37 ( V_10 -> V_95 ) ;
V_10 -> V_95 = NULL ;
}
goto V_27;
}
if ( V_10 -> V_95 ) {
V_14 = F_54 ( V_13 , V_10 , V_75 ) ;
F_37 ( V_10 -> V_95 ) ;
V_10 -> V_95 = NULL ;
if ( V_14 )
goto V_27;
}
F_17 ( V_25 ) ;
V_10 -> V_95 = V_25 ;
V_10 -> V_97 = V_29 ;
V_10 -> V_96 = V_103 ;
V_10 -> V_99 = V_104 ;
V_10 -> V_58 = V_10 -> V_80 << V_10 -> V_87 ;
V_27:
return V_14 ;
}
static void F_57 ( struct V_13 * V_13 , struct V_74 * V_75 )
{
unsigned V_105 ;
unsigned V_106 ;
V_106 = V_75 -> V_84 >> V_13 -> V_1 -> V_85 ;
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ ) {
F_58 ( V_75 -> V_93 ,
V_75 -> V_107 + V_105 ) ;
}
}
static inline void F_59 ( struct V_13 * V_13 , struct V_9 * V_10 ,
int V_108 , struct V_74 * V_75 )
{
unsigned V_109 ;
unsigned V_110 ;
unsigned V_111 ;
struct V_25 * V_25 ;
V_10 -> V_112 = 1 ;
if ( ! V_10 -> V_82 || ! F_60 ( V_75 ) )
return;
V_109 = 1 << V_10 -> V_82 ;
V_110 = V_10 -> V_80 & ( V_109 - 1 ) ;
if ( ! V_110 )
return;
if ( V_108 )
V_110 = V_109 - V_110 ;
V_111 = V_110 << V_10 -> V_87 ;
V_25 = F_16 ( 0 ) ;
if ( F_55 ( V_13 , V_10 , V_25 , 0 , V_111 ,
V_10 -> V_113 , V_75 ) )
return;
V_10 -> V_113 += V_110 ;
}
static int F_61 ( struct V_13 * V_13 , struct V_9 * V_10 ,
struct V_74 * V_75 )
{
const unsigned V_87 = V_10 -> V_87 ;
const unsigned V_114 = V_28 >> V_87 ;
struct V_25 * V_25 ;
unsigned V_115 ;
int V_14 = 0 ;
V_115 = V_10 -> V_116 ;
while ( V_10 -> V_80 < V_10 -> V_81 ) {
V_25 = F_18 ( V_13 , V_10 ) ;
if ( F_62 ( V_25 ) ) {
V_14 = F_63 ( V_25 ) ;
goto V_27;
}
while ( V_115 < V_114 ) {
unsigned V_117 = V_115 << V_87 ;
unsigned V_111 ;
unsigned V_110 ;
unsigned V_118 ;
if ( V_10 -> V_23 == 0 ) {
unsigned long V_119 ;
unsigned long V_120 ;
V_14 = F_48 ( V_13 , V_10 , V_75 ) ;
if ( V_14 ) {
F_37 ( V_25 ) ;
goto V_27;
}
if ( ! F_64 ( V_75 ) )
goto V_121;
V_10 -> V_23 =
V_75 -> V_84 >> V_10 -> V_87 ;
V_10 -> V_113 =
V_75 -> V_107 << V_10 -> V_82 ;
if ( F_60 ( V_75 ) )
F_57 ( V_13 , V_75 ) ;
if ( ! V_10 -> V_82 )
goto V_121;
V_119 = ( 1 << V_10 -> V_82 ) - 1 ;
V_120 = ( V_10 -> V_80 & V_119 ) ;
if ( ! F_60 ( V_75 ) )
V_10 -> V_113 += V_120 ;
V_10 -> V_23 -= V_120 ;
}
V_121:
if ( ! F_64 ( V_75 ) ) {
T_3 V_122 ;
if ( V_13 -> V_20 & V_24 ) {
F_37 ( V_25 ) ;
return - V_123 ;
}
V_122 = F_65 ( F_49 ( V_13 -> V_1 ) ,
1 << V_87 ) ;
if ( V_10 -> V_80 >=
V_122 >> V_87 ) {
F_37 ( V_25 ) ;
goto V_27;
}
F_66 ( V_25 , V_115 << V_87 ,
1 << V_87 ) ;
V_10 -> V_80 ++ ;
V_115 ++ ;
goto V_124;
}
if ( F_67 ( V_10 -> V_82 && ! V_10 -> V_112 ) )
F_59 ( V_13 , V_10 , 0 , V_75 ) ;
V_110 = V_10 -> V_23 ;
V_118 = ( V_28 - V_117 ) >> V_87 ;
if ( V_110 > V_118 )
V_110 = V_118 ;
V_118 = V_10 -> V_81 - V_10 -> V_80 ;
if ( V_110 > V_118 )
V_110 = V_118 ;
V_111 = V_110 << V_87 ;
F_20 ( V_111 == 0 ) ;
V_10 -> V_60 = F_68 ( V_75 ) ;
V_14 = F_55 ( V_13 , V_10 , V_25 ,
V_117 ,
V_111 ,
V_10 -> V_113 ,
V_75 ) ;
if ( V_14 ) {
F_37 ( V_25 ) ;
goto V_27;
}
V_10 -> V_113 += V_110 ;
V_10 -> V_80 += V_110 ;
V_115 += V_110 ;
V_10 -> V_23 -= V_110 ;
V_124:
F_20 ( V_10 -> V_80 > V_10 -> V_81 ) ;
if ( V_10 -> V_80 == V_10 -> V_81 )
break;
}
F_37 ( V_25 ) ;
V_115 = 0 ;
}
V_27:
return V_14 ;
}
static inline int F_69 ( struct V_13 * V_13 )
{
int V_73 ;
unsigned long V_42 ;
F_25 ( & V_13 -> V_43 , V_42 ) ;
V_73 = -- V_13 -> V_44 ;
F_27 ( & V_13 -> V_43 , V_42 ) ;
return V_73 ;
}
static inline T_2
F_70 ( int V_20 , struct V_125 * V_37 , struct V_1 * V_1 ,
struct V_49 * V_50 , const struct V_126 * V_127 , T_3 V_29 ,
unsigned long V_128 , T_5 V_88 , T_6 V_36 ,
T_7 V_59 , int V_42 )
{
int V_129 ;
T_8 V_130 ;
unsigned long V_131 ;
unsigned V_87 = V_1 -> V_85 ;
unsigned V_132 = ( 1 << V_87 ) - 1 ;
T_2 V_133 = - V_134 ;
T_3 V_108 = V_29 ;
struct V_13 * V_13 ;
struct V_9 V_10 = { 0 , } ;
unsigned long V_135 ;
T_8 V_136 ;
struct V_74 V_75 = { 0 , } ;
if ( V_20 & V_24 )
V_20 = V_137 ;
if ( V_29 & V_132 ) {
if ( V_50 )
V_87 = F_71 ( F_72 ( V_50 ) ) ;
V_132 = ( 1 << V_87 ) - 1 ;
if ( V_29 & V_132 )
goto V_27;
}
for ( V_129 = 0 ; V_129 < V_128 ; V_129 ++ ) {
V_131 = ( unsigned long ) V_127 [ V_129 ] . V_138 ;
V_130 = V_127 [ V_129 ] . V_139 ;
V_108 += V_130 ;
if ( F_67 ( ( V_131 & V_132 ) ||
( V_130 & V_132 ) ) ) {
if ( V_50 )
V_87 = F_71 (
F_72 ( V_50 ) ) ;
V_132 = ( 1 << V_87 ) - 1 ;
if ( ( V_131 & V_132 ) || ( V_130 & V_132 ) )
goto V_27;
}
}
if ( V_20 == V_21 && V_108 == V_29 )
return 0 ;
V_13 = F_73 ( V_47 , V_53 ) ;
V_133 = - V_140 ;
if ( ! V_13 )
goto V_27;
memset ( V_13 , 0 , F_74 ( struct V_13 , V_22 ) ) ;
V_13 -> V_42 = V_42 ;
if ( V_13 -> V_42 & V_141 ) {
if ( V_20 == V_21 ) {
struct V_142 * V_143 =
V_37 -> V_144 -> V_145 ;
F_75 ( & V_1 -> V_146 ) ;
V_133 = F_76 ( V_143 , V_29 ,
V_108 - 1 ) ;
if ( V_133 ) {
F_77 ( & V_1 -> V_146 ) ;
F_28 ( V_47 , V_13 ) ;
goto V_27;
}
}
}
F_78 ( & V_1 -> V_8 ) ;
V_13 -> V_30 = ! F_79 ( V_37 ) && ! ( ( V_20 & V_24 ) &&
( V_108 > F_49 ( V_1 ) ) ) ;
V_133 = 0 ;
V_13 -> V_1 = V_1 ;
V_13 -> V_20 = V_20 ;
V_10 . V_87 = V_87 ;
V_10 . V_82 = V_1 -> V_85 - V_87 ;
V_10 . V_80 = V_29 >> V_87 ;
V_10 . V_88 = V_88 ;
V_13 -> V_36 = V_36 ;
V_10 . V_59 = V_59 ;
V_10 . V_98 = - 1 ;
V_10 . V_113 = - 1 ;
V_13 -> V_37 = V_37 ;
V_13 -> V_34 = F_49 ( V_1 ) ;
F_80 ( & V_13 -> V_43 ) ;
V_13 -> V_44 = 1 ;
if ( F_67 ( V_10 . V_82 ) )
V_10 . V_92 = 2 ;
for ( V_129 = 0 ; V_129 < V_128 ; V_129 ++ ) {
V_135 = ( unsigned long ) V_127 [ V_129 ] . V_138 ;
V_10 . V_92 +=
( ( V_135 + V_127 [ V_129 ] . V_139 + V_28 - 1 ) /
V_28 - V_135 / V_28 ) ;
}
for ( V_129 = 0 ; V_129 < V_128 ; V_129 ++ ) {
V_135 = ( unsigned long ) V_127 [ V_129 ] . V_138 ;
V_10 . V_130 += V_136 = V_127 [ V_129 ] . V_139 ;
V_10 . V_116 = ( V_135 & ~ V_147 ) >> V_87 ;
V_10 . V_81 = V_10 . V_80 +
( V_136 >> V_87 ) ;
V_10 . V_12 = 0 ;
V_10 . V_11 = 0 ;
V_10 . V_17 = 0 ;
V_10 . V_16 = 0 ;
if ( V_135 & ( V_28 - 1 ) ) {
V_10 . V_16 ++ ;
V_136 -= V_28 - ( V_135 & ( V_28 - 1 ) ) ;
}
V_10 . V_16 += ( V_136 + V_28 - 1 ) / V_28 ;
V_10 . V_19 = V_135 ;
V_133 = F_61 ( V_13 , & V_10 , & V_75 ) ;
V_13 -> V_33 += V_127 [ V_129 ] . V_139 -
( ( V_10 . V_81 - V_10 . V_80 ) <<
V_87 ) ;
if ( V_133 ) {
F_36 ( V_13 , & V_10 ) ;
break;
}
}
if ( V_133 == - V_123 ) {
V_133 = 0 ;
}
F_59 ( V_13 , & V_10 , 1 , & V_75 ) ;
if ( V_10 . V_95 ) {
T_2 V_73 ;
V_73 = F_54 ( V_13 , & V_10 , & V_75 ) ;
if ( V_133 == 0 )
V_133 = V_73 ;
F_37 ( V_10 . V_95 ) ;
V_10 . V_95 = NULL ;
}
if ( V_10 . V_39 )
F_33 ( V_13 , & V_10 ) ;
F_36 ( V_13 , & V_10 ) ;
if ( V_20 == V_21 && ( V_13 -> V_42 & V_141 ) )
F_77 ( & V_13 -> V_1 -> V_146 ) ;
F_20 ( V_133 == - V_32 ) ;
if ( V_13 -> V_30 && V_133 == 0 && V_13 -> V_33 &&
( ( V_20 & V_21 ) || ( V_13 -> V_33 == V_10 . V_130 ) ) )
V_133 = - V_32 ;
if ( V_133 != - V_32 )
F_46 ( V_13 ) ;
if ( F_69 ( V_13 ) == 0 ) {
V_133 = F_21 ( V_13 , V_29 , V_133 , false ) ;
F_28 ( V_47 , V_13 ) ;
} else
F_20 ( V_133 != - V_32 ) ;
V_27:
return V_133 ;
}
T_2
F_81 ( int V_20 , struct V_125 * V_37 , struct V_1 * V_1 ,
struct V_49 * V_50 , const struct V_126 * V_127 , T_3 V_29 ,
unsigned long V_128 , T_5 V_88 , T_6 V_36 ,
T_7 V_59 , int V_42 )
{
F_82 ( & V_50 -> V_148 -> V_149 ) ;
F_82 ( V_50 -> V_150 ) ;
F_82 ( ( char * ) V_50 -> V_150 + V_151 ) ;
return F_70 ( V_20 , V_37 , V_1 , V_50 , V_127 , V_29 ,
V_128 , V_88 , V_36 ,
V_59 , V_42 ) ;
}
static T_9 int F_83 ( void )
{
V_47 = F_84 ( V_13 , V_152 ) ;
return 0 ;
}
