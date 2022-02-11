static void F_1 ( struct V_1 * V_1 )
{
F_2 ( L_1 , V_1 ) ;
F_2 ( L_2 , F_3 ( V_1 ) ) ;
F_2 ( L_3 , F_4 ( V_1 ) ) ;
F_2 ( L_4 , F_5 ( V_1 ) ) ;
F_2 ( L_5 , F_6 ( V_1 ) ) ;
F_2 ( L_6 , F_7 ( V_1 ) ) ;
F_2 ( L_7 , F_8 ( V_1 ) ) ;
F_2 ( L_8 , F_9 ( V_1 ) ) ;
F_2 ( L_9 , F_10 ( V_1 ) ) ;
F_2 ( L_10 ) ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_4 )
{
if ( V_3 -> V_5 == V_6 )
return 1 ;
else if ( V_3 -> V_5 != V_7 )
return 0 ;
else
return ! F_12 ( V_3 -> V_8 , V_4 ) ;
}
static int F_13 ( struct V_2 * V_3 , T_1 V_4 )
{
return ( V_3 -> V_5 == V_9 ||
V_3 -> V_5 == V_7 ) ;
}
static inline struct V_10 * F_14 ( void * V_11 )
{
struct V_10 * V_12 ;
V_12 = F_15 ( sizeof( * V_12 ) , V_13 ) ;
if ( V_12 ) {
V_12 -> V_11 = V_11 ;
F_16 ( & V_12 -> V_14 ) ;
V_12 -> V_15 = 0 ;
}
return V_12 ;
}
static inline void F_17 ( struct V_10 * V_16 )
{
F_18 ( & V_16 -> V_14 ) ;
}
static void F_19 ( struct V_17 * V_17 )
{
struct V_10 * V_16 = F_20 ( V_17 , struct V_10 , V_14 ) ;
F_2 ( L_11 , V_18 ) ;
V_16 -> V_19 ( V_16 -> V_11 , V_16 -> V_15 ) ;
F_21 ( V_16 ) ;
}
static inline void F_22 ( struct V_10 * V_16 )
{
F_23 ( & V_16 -> V_14 , F_19 ) ;
}
static struct V_20 *
F_24 ( int V_21 , struct V_20 * V_20 )
{
if ( V_20 ) {
F_17 ( V_20 -> V_22 ) ;
F_2 ( L_12 , V_18 ,
V_21 == V_23 ? L_13 : L_14 , V_20 -> V_24 . V_25 ,
( unsigned long long ) V_20 -> V_24 . V_26 ) ;
F_25 ( V_21 , V_20 ) ;
}
return NULL ;
}
static struct V_20 * F_26 ( int V_27 , T_1 V_4 ,
struct V_2 * V_3 ,
void (* F_27)( struct V_20 * , int V_28 ) ,
struct V_10 * V_29 )
{
struct V_20 * V_20 ;
V_27 = F_28 ( V_27 , V_30 ) ;
V_20 = F_29 ( V_31 , V_27 ) ;
if ( ! V_20 && ( V_32 -> V_33 & V_34 ) ) {
while ( ! V_20 && ( V_27 /= 2 ) )
V_20 = F_29 ( V_31 , V_27 ) ;
}
if ( V_20 ) {
V_20 -> V_24 . V_26 = V_4 - V_3 -> V_35 +
V_3 -> V_36 ;
V_20 -> V_37 = V_3 -> V_38 ;
V_20 -> V_39 = F_27 ;
V_20 -> V_22 = V_29 ;
}
return V_20 ;
}
static struct V_20 * F_30 ( struct V_20 * V_20 , int V_27 , int V_21 ,
T_1 V_4 , struct V_1 * V_1 ,
struct V_2 * V_3 ,
void (* F_27)( struct V_20 * , int V_28 ) ,
struct V_10 * V_29 ,
unsigned int V_40 , int V_41 )
{
V_4 = V_4 + ( V_40 >> V_42 ) ;
F_2 ( L_15 , V_18 ,
V_27 , V_21 , ( unsigned long long ) V_4 , V_40 , V_41 ) ;
V_43:
if ( ! V_20 ) {
V_20 = F_26 ( V_27 , V_4 , V_3 , F_27 , V_29 ) ;
if ( ! V_20 )
return F_31 ( - V_44 ) ;
}
if ( F_32 ( V_20 , V_1 , V_41 , V_40 ) < V_41 ) {
V_20 = F_24 ( V_21 , V_20 ) ;
goto V_43;
}
return V_20 ;
}
static struct V_20 * F_33 ( struct V_20 * V_20 , int V_27 , int V_21 ,
T_1 V_4 , struct V_1 * V_1 ,
struct V_2 * V_3 ,
void (* F_27)( struct V_20 * , int V_28 ) ,
struct V_10 * V_29 )
{
return F_30 ( V_20 , V_27 , V_21 , V_4 , V_1 , V_3 ,
F_27 , V_29 , 0 , V_45 ) ;
}
static void F_34 ( struct V_20 * V_20 , int V_28 )
{
struct V_10 * V_29 = V_20 -> V_22 ;
struct V_46 * V_47 ;
int V_48 ;
if ( ! V_28 )
F_35 (bvec, bio, i)
F_36 ( V_47 -> V_49 ) ;
if ( V_28 ) {
struct V_50 * V_51 = V_29 -> V_11 ;
struct V_52 * V_53 = V_51 -> V_53 ;
if ( ! V_53 -> V_54 )
V_53 -> V_54 = - V_55 ;
F_37 ( V_53 -> V_56 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_29 ) ;
}
static void F_39 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_50 * V_51 ;
F_2 ( L_11 , V_18 ) ;
V_60 = F_20 ( V_58 , struct V_59 , V_61 . V_62 ) ;
V_51 = F_20 ( V_60 , struct V_50 , V_60 ) ;
F_40 ( V_51 ) ;
}
static void
F_41 ( void * V_11 , int V_63 )
{
struct V_50 * V_51 = V_11 ;
V_51 -> V_60 . V_64 = V_51 -> V_53 -> V_54 ;
F_42 ( & V_51 -> V_60 . V_61 . V_62 , F_39 ) ;
F_43 ( & V_51 -> V_60 . V_61 . V_62 ) ;
}
static enum V_65
F_44 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_53 ;
int V_48 , V_66 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_67 = NULL ;
T_1 V_4 , V_68 = 0 ;
struct V_10 * V_29 ;
T_2 V_69 = V_51 -> args . V_40 ;
T_3 V_70 = V_51 -> args . V_71 ;
unsigned int V_72 , V_73 ;
struct V_1 * * V_74 = V_51 -> args . V_74 ;
int V_75 = V_51 -> args . V_76 >> V_77 ;
const bool V_78 = ( V_53 -> V_79 != NULL ) ;
F_2 ( L_16 , V_18 ,
V_51 -> V_74 . V_80 , V_69 , ( unsigned int ) V_51 -> args . V_71 ) ;
V_29 = F_14 ( V_51 ) ;
if ( ! V_29 )
goto V_81;
V_29 -> V_19 = F_41 ;
V_4 = ( T_1 ) ( V_69 >> V_42 ) ;
for ( V_48 = V_75 ; V_48 < V_51 -> V_74 . V_80 ; V_48 ++ ) {
if ( ! V_68 ) {
F_45 ( V_3 ) ;
F_45 ( V_67 ) ;
V_20 = F_24 ( V_23 , V_20 ) ;
V_3 = F_46 ( F_47 ( V_53 -> V_56 ) ,
V_4 , & V_67 ) ;
if ( ! V_3 ) {
V_53 -> V_54 = - V_55 ;
goto V_82;
}
V_68 = V_3 -> V_83 -
( V_4 - V_3 -> V_35 ) ;
if ( V_67 ) {
T_1 V_84 = V_67 -> V_83 -
( V_4 - V_67 -> V_35 ) ;
V_68 = F_28 ( V_68 , V_84 ) ;
}
}
if ( V_78 ) {
V_72 = V_69 & ~ V_85 ;
if ( V_72 + V_70 > V_45 )
V_73 = V_45 - V_72 ;
else
V_73 = V_70 ;
V_69 += V_73 ;
V_70 -= V_73 ;
V_4 += ( V_72 >> V_42 ) ;
} else {
V_72 = 0 ;
V_73 = V_45 ;
}
V_66 = F_11 ( V_3 , V_4 ) ;
if ( V_66 && ! V_67 ) {
V_20 = F_24 ( V_23 , V_20 ) ;
F_2 ( L_17 , V_18 ) ;
F_48 ( V_74 [ V_48 ] , V_72 , V_73 ) ;
F_1 ( V_74 [ V_48 ] ) ;
F_36 ( V_74 [ V_48 ] ) ;
} else {
struct V_2 * V_86 ;
V_86 = ( V_66 && V_67 ) ? V_67 : V_3 ;
V_20 = F_30 ( V_20 , V_51 -> V_74 . V_80 - V_48 ,
V_23 ,
V_4 , V_74 [ V_48 ] , V_86 ,
F_34 , V_29 ,
V_72 , V_73 ) ;
if ( F_49 ( V_20 ) ) {
V_53 -> V_54 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_82;
}
}
V_4 += ( V_73 >> V_42 ) ;
V_68 -= V_87 ;
}
if ( ( V_4 << V_42 ) >= V_53 -> V_88 -> V_89 ) {
V_51 -> V_90 . V_91 = 1 ;
V_51 -> V_90 . V_71 = V_53 -> V_88 -> V_89 - V_51 -> args . V_40 ;
} else {
V_51 -> V_90 . V_71 = ( V_4 << V_42 ) - V_51 -> args . V_40 ;
}
V_82:
F_45 ( V_3 ) ;
F_45 ( V_67 ) ;
F_24 ( V_23 , V_20 ) ;
F_22 ( V_29 ) ;
return V_92 ;
V_81:
F_2 ( L_18 ) ;
return V_93 ;
}
static void F_51 ( struct V_94 * V_95 ,
T_4 V_40 , T_5 V_71 )
{
T_1 V_4 , V_96 ;
struct V_2 * V_3 ;
struct V_97 * V_98 ;
F_2 ( L_19 , V_18 , V_40 , V_71 ) ;
if ( V_71 == 0 )
return;
V_4 = ( V_40 & ( long ) ( V_85 ) ) >> V_42 ;
V_96 = ( V_40 + V_71 + V_45 - 1 ) & ( long ) ( V_85 ) ;
V_96 >>= V_42 ;
while ( V_4 < V_96 ) {
T_1 V_41 ;
V_3 = F_46 ( V_95 , V_4 , NULL ) ;
F_52 ( ! V_3 ) ;
V_41 = F_28 ( V_96 , V_3 -> V_35 + V_3 -> V_83 ) - V_4 ;
if ( V_3 -> V_5 == V_7 ) {
V_98 = F_53 ( V_3 -> V_8 ) ;
F_52 ( ! V_98 ) ;
F_54 ( V_3 , V_4 , V_41 , V_98 ) ;
}
V_4 += V_41 ;
F_45 ( V_3 ) ;
}
}
static void F_55 ( struct V_20 * V_20 , int V_28 )
{
struct V_10 * V_29 = V_20 -> V_22 ;
struct V_46 * V_47 ;
int V_48 ;
F_35 (bvec, bio, i) {
F_56 ( V_47 -> V_49 ) ;
F_57 ( V_47 -> V_49 ) ;
}
if ( F_58 ( V_28 ) ) {
struct V_50 * V_11 = V_29 -> V_11 ;
struct V_52 * V_53 = V_11 -> V_53 ;
if ( ! V_53 -> V_54 )
V_53 -> V_54 = - V_55 ;
F_37 ( V_53 -> V_56 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_29 ) ;
}
static void F_59 ( struct V_20 * V_20 , int V_28 )
{
struct V_10 * V_29 = V_20 -> V_22 ;
const int V_99 = F_60 ( V_100 , & V_20 -> V_101 ) ;
struct V_50 * V_11 = V_29 -> V_11 ;
struct V_52 * V_53 = V_11 -> V_53 ;
if ( ! V_99 ) {
if ( ! V_53 -> V_54 )
V_53 -> V_54 = - V_55 ;
F_37 ( V_53 -> V_56 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_29 ) ;
}
static void F_61 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_50 * V_102 ;
F_2 ( L_11 , V_18 ) ;
V_60 = F_20 ( V_58 , struct V_59 , V_61 . V_62 ) ;
V_102 = F_20 ( V_60 , struct V_50 , V_60 ) ;
if ( F_62 ( ! V_102 -> V_53 -> V_54 ) ) {
F_51 ( F_47 ( V_102 -> V_53 -> V_56 ) ,
V_102 -> args . V_40 , V_102 -> args . V_71 ) ;
}
F_63 ( V_102 ) ;
}
static void F_64 ( void * V_11 , int V_103 )
{
struct V_50 * V_102 = V_11 ;
if ( F_58 ( V_102 -> V_53 -> V_54 ) ) {
F_65 ( & F_47 ( V_102 -> V_53 -> V_56 ) -> V_104 ,
V_103 ) ;
}
V_102 -> V_60 . V_64 = V_102 -> V_53 -> V_54 ;
V_102 -> V_105 . V_106 = V_107 ;
F_42 ( & V_102 -> V_60 . V_61 . V_62 , F_61 ) ;
F_43 ( & V_102 -> V_60 . V_61 . V_62 ) ;
}
static void F_66 ( void )
{
return;
}
static void
F_67 ( struct V_108 * V_109 , T_1 V_4 , struct V_2 * V_3 )
{
F_2 ( L_20 , V_18 , V_3 ) ;
F_68 ( V_109 ) ;
V_109 -> V_110 = V_3 -> V_38 ;
V_109 -> V_111 = ( V_4 - V_3 -> V_35 + V_3 -> V_36 ) >>
( V_3 -> V_38 -> V_112 -> V_113 - V_42 ) ;
F_2 ( L_21 ,
V_18 , ( unsigned long long ) V_4 , ( long ) V_109 -> V_111 ,
V_109 -> V_114 ) ;
return;
}
static void
F_69 ( struct V_20 * V_20 , int error )
{
struct V_46 * V_47 = V_20 -> V_115 + V_20 -> V_116 - 1 ;
struct V_1 * V_1 = V_47 -> V_49 ;
F_70 ( V_1 ) ;
}
static int
F_71 ( struct V_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_40 , unsigned int V_41 )
{
struct V_20 * V_20 ;
struct V_1 * V_117 ;
T_1 V_4 ;
char * V_118 , * V_119 ;
int V_120 = 0 ;
F_2 ( L_22 , V_18 , V_40 , V_41 ) ;
V_117 = F_72 ( V_13 | V_121 ) ;
if ( V_117 == NULL )
return - V_44 ;
V_20 = F_29 ( V_31 , 1 ) ;
if ( V_20 == NULL )
return - V_44 ;
V_4 = ( V_1 -> V_122 << V_123 ) +
( V_40 / V_124 ) ;
V_20 -> V_24 . V_26 = V_4 - V_3 -> V_35 + V_3 -> V_36 ;
V_20 -> V_37 = V_3 -> V_38 ;
V_20 -> V_39 = F_69 ;
F_73 ( V_117 ) ;
if ( F_32 ( V_20 , V_117 ,
V_124 , F_74 ( V_40 , V_124 ) ) == 0 ) {
F_70 ( V_117 ) ;
F_38 ( V_20 ) ;
return - V_55 ;
}
F_25 ( V_23 , V_20 ) ;
F_75 ( V_117 ) ;
if ( F_58 ( ! F_60 ( V_100 , & V_20 -> V_101 ) ) ) {
V_120 = - V_55 ;
} else {
V_118 = F_76 ( V_1 ) ;
V_119 = F_76 ( V_117 ) ;
memcpy ( V_118 + V_40 , V_119 + V_40 , V_41 ) ;
F_77 ( V_119 ) ;
F_77 ( V_118 ) ;
}
F_78 ( V_117 ) ;
F_38 ( V_20 ) ;
return V_120 ;
}
static int
F_79 ( struct V_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_125 , unsigned int V_126 ,
bool V_127 )
{
int V_120 = 0 ;
unsigned int V_128 , V_96 ;
if ( V_127 ) {
V_128 = 0 ;
V_96 = V_45 ;
} else {
V_128 = F_74 ( V_125 , V_124 ) ;
V_96 = F_80 ( V_125 + V_126 , V_124 ) ;
}
F_2 ( L_23 , V_18 , V_125 , V_126 ) ;
if ( ! V_3 ) {
F_81 ( V_1 , V_128 , V_125 ,
V_125 + V_126 , V_96 ) ;
if ( V_128 == 0 && V_96 == V_45 &&
F_82 ( V_1 ) ) {
F_36 ( V_1 ) ;
F_70 ( V_1 ) ;
}
return V_120 ;
}
if ( V_128 != V_125 )
V_120 = F_71 ( V_1 , V_3 , V_128 , V_125 - V_128 ) ;
if ( ! V_120 && ( V_125 + V_126 < V_96 ) )
V_120 = F_71 ( V_1 , V_3 , V_125 + V_126 ,
V_96 - V_125 - V_126 ) ;
return V_120 ;
}
static int
F_83 ( struct V_1 * V_1 , struct V_2 * V_67 )
{
struct V_108 * V_109 = NULL ;
int V_120 = 0 ;
T_1 V_4 ;
F_2 ( L_24 , V_18 , V_1 ) ;
F_52 ( F_4 ( V_1 ) ) ;
if ( ! V_67 ) {
F_48 ( V_1 , 0 , V_129 ) ;
F_36 ( V_1 ) ;
goto V_130;
}
V_109 = F_84 ( V_1 , V_45 , 0 ) ;
if ( ! V_109 ) {
V_120 = - V_44 ;
goto V_130;
}
V_4 = ( T_1 ) V_1 -> V_122 << V_123 ;
F_67 ( V_109 , V_4 , V_67 ) ;
if ( ! F_85 ( V_109 ) )
V_120 = F_86 ( V_109 ) ;
if ( V_120 )
goto V_130;
F_36 ( V_1 ) ;
V_130:
if ( V_109 )
F_87 ( V_109 ) ;
if ( V_120 ) {
F_66 () ;
}
return V_120 ;
}
static struct V_1 *
F_88 ( struct V_88 * V_88 , T_6 V_122 ,
struct V_2 * V_67 )
{
struct V_1 * V_1 ;
int V_131 = 0 ;
V_1 = F_89 ( V_88 -> V_132 , V_122 ) ;
if ( V_1 )
goto V_133;
V_1 = F_90 ( V_88 -> V_132 , V_122 , V_13 ) ;
if ( F_58 ( ! V_1 ) ) {
F_2 ( L_25 , V_18 ) ;
return F_31 ( - V_44 ) ;
}
V_131 = 1 ;
V_133:
if ( F_6 ( V_1 ) || F_9 ( V_1 ) ) {
F_1 ( V_1 ) ;
if ( V_131 )
F_70 ( V_1 ) ;
F_57 ( V_1 ) ;
return NULL ;
}
if ( ! V_131 ) {
F_73 ( V_1 ) ;
V_131 = 1 ;
goto V_133;
}
if ( ! F_4 ( V_1 ) ) {
F_83 ( V_1 , V_67 ) ;
}
F_91 ( V_1 ) ;
F_70 ( V_1 ) ;
return V_1 ;
}
static enum V_65
F_92 ( struct V_50 * V_102 , int V_134 )
{
struct V_52 * V_53 = V_102 -> V_53 ;
int V_48 , V_120 , V_135 , V_75 , V_136 = 0 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_67 = NULL ;
T_1 V_4 , V_137 = 0 , V_68 = 0 ;
struct V_10 * V_29 = NULL ;
T_2 V_40 = V_102 -> args . V_40 ;
T_3 V_71 = V_102 -> args . V_71 ;
unsigned int V_72 , V_73 , V_138 ;
struct V_1 * * V_74 = V_102 -> args . V_74 ;
struct V_1 * V_1 ;
T_6 V_122 ;
T_7 V_139 ;
int V_140 =
F_93 ( V_53 -> V_88 ) -> V_141 >> V_77 ;
F_2 ( L_26 , V_18 , V_71 , V_40 ) ;
if ( V_53 -> V_79 != NULL &&
( ! F_94 ( V_40 , F_93 ( V_53 -> V_88 ) -> V_141 ) ||
! F_94 ( V_71 , F_93 ( V_53 -> V_88 ) -> V_141 ) ) ) {
F_2 ( L_27 ) ;
goto V_142;
}
V_29 = F_14 ( V_102 ) ;
if ( ! V_29 )
goto V_142;
V_29 -> V_19 = F_64 ;
V_4 = ( T_1 ) ( ( V_40 & ( long ) V_85 ) >> V_42 ) ;
V_3 = F_46 ( F_47 ( V_53 -> V_56 ) , V_4 , & V_67 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
F_2 ( L_28 , V_18 ) ;
goto V_142;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_62 ( ! F_95 ( V_3 -> V_8 ) ) )
V_29 -> V_15 ++ ;
else
goto V_142;
V_139 = V_40 >> V_77 ;
V_135 = F_96 ( V_139 , V_140 ) ;
V_4 = ( T_1 ) ( ( ( V_40 - V_135 * V_45 ) &
( long ) V_85 ) >> V_42 ) ;
V_68 = V_3 -> V_83 - ( V_4 - V_3 -> V_35 ) ;
V_143:
F_2 ( L_29 , V_18 , V_135 ) ;
for (; V_135 > 0 ; V_135 -- ) {
if ( F_12 ( V_3 -> V_8 , V_4 ) ) {
F_2 ( L_30 ,
( unsigned long long ) V_4 ) ;
goto V_144;
}
V_122 = V_4 >> V_123 ;
F_2 ( L_31 ,
V_18 , V_135 , V_122 ,
( unsigned long long ) V_4 ) ;
V_1 = F_88 ( V_53 -> V_88 , V_122 ,
V_67 ) ;
if ( F_58 ( F_49 ( V_1 ) ) ) {
V_53 -> V_54 = F_50 ( V_1 ) ;
goto V_82;
} else if ( V_1 == NULL )
goto V_144;
V_120 = F_97 ( V_3 -> V_8 , V_4 ,
V_87 ) ;
if ( F_58 ( V_120 ) ) {
F_2 ( L_32 ,
V_18 , V_120 ) ;
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
V_53 -> V_54 = V_120 ;
goto V_82;
}
if ( F_62 ( ! F_95 ( V_3 -> V_8 ) ) )
V_29 -> V_15 ++ ;
else {
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
V_53 -> V_54 = - V_44 ;
goto V_82;
}
F_51 ( F_47 ( V_53 -> V_56 ) ,
V_1 -> V_122 << V_77 ,
V_45 ) ;
V_20 = F_33 ( V_20 , V_135 , V_145 ,
V_4 , V_1 , V_3 ,
F_55 , V_29 ) ;
if ( F_49 ( V_20 ) ) {
V_53 -> V_54 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_82;
}
V_144:
V_4 += V_87 ;
V_68 -= V_87 ;
}
if ( V_136 )
goto V_146;
}
V_20 = F_24 ( V_145 , V_20 ) ;
V_75 = V_102 -> args . V_76 >> V_77 ;
for ( V_48 = V_75 ; V_48 < V_102 -> V_74 . V_80 ; V_48 ++ ) {
if ( ! V_68 ) {
F_45 ( V_3 ) ;
F_45 ( V_67 ) ;
V_20 = F_24 ( V_145 , V_20 ) ;
V_3 = F_46 ( F_47 ( V_53 -> V_56 ) ,
V_4 , & V_67 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
V_53 -> V_54 = - V_147 ;
goto V_82;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_62 ( ! F_95 (
V_3 -> V_8 ) ) )
V_29 -> V_15 ++ ;
else {
V_53 -> V_54 = - V_44 ;
goto V_82;
}
}
V_68 = V_3 -> V_83 -
( V_4 - V_3 -> V_35 ) ;
}
F_2 ( L_33 , V_18 , V_40 , V_71 ) ;
V_72 = V_40 & ~ V_85 ;
if ( V_72 + V_71 > V_45 )
V_73 = V_45 - V_72 ;
else
V_73 = V_71 ;
V_138 = V_73 ;
if ( V_3 -> V_5 == V_7 &&
! F_12 ( V_3 -> V_8 , V_4 ) ) {
V_120 = F_79 ( V_74 [ V_48 ] , V_67 ,
V_72 , V_73 , true ) ;
if ( V_120 ) {
F_2 ( L_34 ,
V_18 , V_120 ) ;
V_53 -> V_54 = V_120 ;
goto V_82;
}
V_120 = F_97 ( V_3 -> V_8 , V_4 ,
V_87 ) ;
if ( F_58 ( V_120 ) ) {
F_2 ( L_32 ,
V_18 , V_120 ) ;
V_53 -> V_54 = V_120 ;
goto V_82;
}
V_72 = 0 ;
V_73 = V_45 ;
} else if ( ( V_72 & ( V_124 - 1 ) ) ||
( V_73 & ( V_124 - 1 ) ) ) {
unsigned int V_148 = V_72 ;
V_120 = F_79 ( V_74 [ V_48 ] , V_3 , V_72 ,
V_73 , false ) ;
V_72 = F_74 ( V_72 , V_124 ) ;
V_73 = F_80 ( V_148 + V_73 , V_124 )
- V_72 ;
}
V_20 = F_30 ( V_20 , V_102 -> V_74 . V_80 - V_48 , V_145 ,
V_4 , V_74 [ V_48 ] , V_3 ,
F_59 , V_29 ,
V_72 , V_73 ) ;
if ( F_49 ( V_20 ) ) {
V_53 -> V_54 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_82;
}
V_40 += V_138 ;
V_71 -= V_138 ;
V_4 += V_87 ;
V_137 = V_4 ;
V_68 -= V_87 ;
}
if ( V_3 -> V_5 == V_7 ) {
V_20 = F_24 ( V_145 , V_20 ) ;
V_139 = V_137 >> V_123 ;
V_135 = V_140 - F_96 ( V_139 , V_140 ) ;
if ( V_135 < V_140 ) {
V_136 = 1 ;
goto V_143;
}
}
V_146:
V_102 -> V_90 . V_71 = V_102 -> args . V_71 ;
V_82:
F_45 ( V_3 ) ;
F_45 ( V_67 ) ;
F_24 ( V_145 , V_20 ) ;
F_22 ( V_29 ) ;
return V_92 ;
V_142:
F_45 ( V_3 ) ;
F_45 ( V_67 ) ;
F_21 ( V_29 ) ;
return V_93 ;
}
static void
F_98 ( struct V_94 * V_95 , struct V_149 * V_150 )
{
int V_48 ;
struct V_2 * V_3 ;
F_99 ( & V_95 -> V_151 ) ;
for ( V_48 = 0 ; V_48 < V_152 ; V_48 ++ ) {
while ( ! F_100 ( & V_95 -> V_153 [ V_48 ] ) ) {
V_3 = F_101 ( & V_95 -> V_153 [ V_48 ] ,
struct V_2 ,
V_154 ) ;
F_102 ( & V_3 -> V_154 ) ;
F_45 ( V_3 ) ;
}
}
F_103 ( & V_95 -> V_151 ) ;
}
static void
F_104 ( struct V_155 * V_156 )
{
struct V_157 * V_158 , * V_139 ;
struct V_97 * V_98 , * V_159 ;
F_105 (pos, temp, &marks->im_tree.mtt_stub, it_link) {
F_102 ( & V_158 -> V_160 ) ;
F_21 ( V_158 ) ;
}
F_105 (se, stemp, &marks->im_extents, bse_node) {
F_102 ( & V_98 -> V_161 ) ;
F_21 ( V_98 ) ;
}
return;
}
static void F_106 ( struct V_162 * V_163 )
{
struct V_94 * V_95 = F_107 ( V_163 ) ;
F_2 ( L_11 , V_18 ) ;
F_98 ( V_95 , NULL ) ;
F_104 ( & V_95 -> V_104 ) ;
F_21 ( V_95 ) ;
}
static struct V_162 * F_108 ( struct V_88 * V_88 ,
T_8 V_164 )
{
struct V_94 * V_95 ;
F_2 ( L_11 , V_18 ) ;
V_95 = F_109 ( sizeof( * V_95 ) , V_164 ) ;
if ( ! V_95 )
return NULL ;
F_110 ( & V_95 -> V_151 ) ;
F_111 ( & V_95 -> V_153 [ 0 ] ) ;
F_111 ( & V_95 -> V_153 [ 1 ] ) ;
F_111 ( & V_95 -> V_165 ) ;
F_111 ( & V_95 -> V_166 ) ;
V_95 -> V_167 = 0 ;
V_95 -> V_168 = F_93 ( V_88 ) -> V_141 >> V_42 ;
F_112 ( & V_95 -> V_104 , V_95 -> V_168 ) ;
return & V_95 -> V_169 ;
}
static void F_113 ( struct V_170 * V_56 )
{
F_2 ( L_11 , V_18 ) ;
F_21 ( V_56 ) ;
}
static struct V_170 * F_114 ( struct V_162 * V_163 ,
struct V_171 * V_172 ,
T_8 V_164 )
{
struct V_170 * V_56 ;
int V_173 ;
F_2 ( L_11 , V_18 ) ;
V_56 = F_109 ( sizeof( * V_56 ) , V_164 ) ;
if ( ! V_56 )
return F_31 ( - V_44 ) ;
V_173 = F_115 ( V_163 , V_172 , V_164 ) ;
if ( V_173 ) {
F_21 ( V_56 ) ;
return F_31 ( V_173 ) ;
}
return V_56 ;
}
static void
F_116 ( struct V_162 * V_163 , struct V_174 * V_175 ,
const struct V_176 * V_177 )
{
F_2 ( L_11 , V_18 ) ;
F_117 ( F_107 ( V_163 ) , V_175 , V_177 ) ;
}
static void
F_118 ( struct V_178 * V_179 )
{
struct V_162 * V_163 = F_119 ( V_179 -> args . V_88 ) -> V_180 ;
F_2 ( L_11 , V_18 ) ;
F_120 ( F_107 ( V_163 ) , & V_179 -> args , V_179 -> V_90 . V_173 ) ;
}
static void F_121 ( struct V_181 * V_182 )
{
if ( V_182 ) {
struct V_183 * V_184 , * V_185 ;
F_105 (dev, tmp, &mid->bm_devlist, bm_node) {
F_102 ( & V_184 -> V_186 ) ;
F_122 ( V_184 ) ;
}
F_21 ( V_182 ) ;
}
}
static struct V_183 *
F_123 ( struct V_187 * V_188 , const struct V_189 * V_190 ,
struct V_191 * V_192 )
{
struct V_193 * V_184 ;
struct V_183 * V_12 ;
T_9 V_194 ;
int V_195 ;
struct V_1 * * V_74 = NULL ;
int V_48 , V_196 ;
V_194 = V_188 -> V_197 -> V_198 -> V_199 . V_194 ;
V_195 = F_124 ( 0 , V_194 ) ;
F_2 ( L_35 ,
V_18 , V_194 , V_195 ) ;
V_184 = F_15 ( sizeof( * V_184 ) , V_13 ) ;
if ( ! V_184 ) {
F_2 ( L_36 , V_18 ) ;
return F_31 ( - V_44 ) ;
}
V_74 = F_109 ( V_195 * sizeof( struct V_1 * ) , V_13 ) ;
if ( V_74 == NULL ) {
F_21 ( V_184 ) ;
return F_31 ( - V_44 ) ;
}
for ( V_48 = 0 ; V_48 < V_195 ; V_48 ++ ) {
V_74 [ V_48 ] = F_72 ( V_13 ) ;
if ( ! V_74 [ V_48 ] ) {
V_12 = F_31 ( - V_44 ) ;
goto V_200;
}
}
memcpy ( & V_184 -> V_201 , V_192 , sizeof( * V_192 ) ) ;
V_184 -> V_202 = V_203 ;
V_184 -> V_74 = V_74 ;
V_184 -> V_76 = 0 ;
V_184 -> V_204 = V_129 * V_195 ;
V_184 -> V_205 = 0 ;
V_184 -> V_206 = V_194 - V_207 ;
F_2 ( L_37 , V_18 , V_184 -> V_201 . V_11 ) ;
V_196 = F_125 ( V_188 , V_184 , NULL ) ;
F_2 ( L_38 , V_18 , V_196 ) ;
if ( V_196 ) {
V_12 = F_31 ( V_196 ) ;
goto V_200;
}
V_12 = F_126 ( V_188 , V_184 ) ;
V_200:
for ( V_48 = 0 ; V_48 < V_195 ; V_48 ++ )
F_78 ( V_74 [ V_48 ] ) ;
F_21 ( V_74 ) ;
F_21 ( V_184 ) ;
return V_12 ;
}
static int
F_127 ( struct V_187 * V_188 , const struct V_189 * V_190 )
{
struct V_181 * V_208 = NULL ;
struct V_209 * V_210 = NULL ;
struct V_183 * V_211 ;
F_128 ( V_212 ) ;
int V_173 , V_48 ;
F_2 ( L_11 , V_18 ) ;
if ( V_188 -> V_141 == 0 ) {
F_2 ( L_39 , V_18 ) ;
return - V_147 ;
}
V_208 = F_109 ( sizeof( struct V_181 ) , V_13 ) ;
if ( ! V_208 ) {
V_173 = - V_44 ;
goto V_213;
}
F_110 ( & V_208 -> V_214 ) ;
F_111 ( & V_208 -> V_215 ) ;
V_210 = F_15 ( sizeof( struct V_209 ) , V_13 ) ;
if ( ! V_210 ) {
V_173 = - V_44 ;
goto V_213;
}
V_210 -> V_91 = 0 ;
while ( ! V_210 -> V_91 ) {
V_173 = F_129 ( V_188 , V_190 , V_210 ) ;
if ( V_173 )
goto V_213;
F_2 ( L_40 ,
V_18 , V_210 -> V_216 , V_210 -> V_91 ) ;
for ( V_48 = 0 ; V_48 < V_210 -> V_216 ; V_48 ++ ) {
V_211 = F_123 ( V_188 , V_190 ,
& V_210 -> V_201 [ V_48 ] ) ;
if ( F_49 ( V_211 ) ) {
V_173 = F_50 ( V_211 ) ;
goto V_213;
}
F_99 ( & V_208 -> V_214 ) ;
F_130 ( & V_211 -> V_186 , & V_208 -> V_215 ) ;
F_103 ( & V_208 -> V_214 ) ;
}
}
F_2 ( L_41 , V_18 ) ;
V_188 -> V_217 = V_208 ;
V_218:
F_21 ( V_210 ) ;
return V_173 ;
V_213:
F_121 ( V_208 ) ;
goto V_218;
}
static int
F_131 ( struct V_187 * V_188 )
{
struct V_181 * V_208 = V_188 -> V_217 ;
F_2 ( L_11 , V_18 ) ;
F_121 ( V_208 ) ;
F_2 ( L_42 , V_18 ) ;
return 0 ;
}
static bool
F_132 ( struct V_219 * V_220 , unsigned int V_221 )
{
return F_94 ( V_220 -> V_222 , V_221 ) &&
F_94 ( V_220 -> V_223 , V_221 ) ;
}
static void
F_133 ( struct V_224 * V_225 , struct V_219 * V_220 )
{
if ( V_225 -> V_226 != NULL &&
! F_132 ( V_220 , V_124 ) )
F_134 ( V_225 ) ;
else
F_135 ( V_225 , V_220 ) ;
}
static T_3
F_136 ( struct V_224 * V_225 , struct V_219 * V_227 ,
struct V_219 * V_220 )
{
if ( V_225 -> V_226 != NULL &&
! F_132 ( V_220 , V_124 ) )
return 0 ;
return F_137 ( V_225 , V_227 , V_220 ) ;
}
static T_7 F_138 ( struct V_88 * V_88 , T_6 V_228 )
{
struct V_229 * V_230 = V_88 -> V_132 ;
T_6 V_96 ;
V_96 = F_139 ( F_140 ( V_88 ) , V_45 ) ;
if ( V_96 != F_119 ( V_88 ) -> V_80 ) {
F_141 () ;
V_96 = F_142 ( V_230 , V_228 + 1 , V_231 ) ;
F_143 () ;
}
if ( ! V_96 )
return F_140 ( V_88 ) - ( V_228 << V_77 ) ;
else
return ( V_96 - V_228 ) << V_77 ;
}
static void
F_144 ( struct V_224 * V_225 , struct V_219 * V_220 )
{
if ( V_225 -> V_226 != NULL &&
! F_132 ( V_220 , V_45 ) ) {
F_145 ( V_225 ) ;
} else {
T_7 V_232 ;
if ( V_225 -> V_226 == NULL )
V_232 = F_138 ( V_225 -> V_233 ,
V_220 -> V_234 ) ;
else
V_232 = F_146 ( V_225 -> V_226 ) ;
F_147 ( V_225 , V_220 , V_232 ) ;
}
}
static T_3
F_148 ( struct V_224 * V_225 , struct V_219 * V_227 ,
struct V_219 * V_220 )
{
if ( V_225 -> V_226 != NULL &&
! F_132 ( V_220 , V_45 ) )
return 0 ;
return F_137 ( V_225 , V_227 , V_220 ) ;
}
static struct V_235 * F_149 ( struct V_236 * V_237 ,
struct V_238 * V_239 )
{
struct V_235 * V_240 , * V_235 ;
V_240 = F_150 ( V_237 , V_241 ) ;
if ( V_240 == NULL )
return F_31 ( - V_242 ) ;
V_235 = F_151 ( V_240 , L_43 , NULL , V_239 ) ;
F_152 ( V_240 ) ;
return V_235 ;
}
static void F_153 ( struct V_236 * V_237 ,
struct V_238 * V_239 )
{
if ( V_239 -> V_235 )
F_154 ( V_239 -> V_235 ) ;
}
static int F_155 ( struct V_243 * V_244 , unsigned long V_245 ,
void * V_246 )
{
struct V_236 * V_237 = V_246 ;
struct V_247 * V_247 = V_237 -> V_248 ;
struct V_249 * V_250 = F_156 ( V_247 , V_251 ) ;
struct V_235 * V_235 ;
int V_120 = 0 ;
if ( ! F_157 ( V_252 ) )
return 0 ;
if ( V_250 -> V_253 == NULL ) {
F_158 ( V_252 ) ;
return 0 ;
}
switch ( V_245 ) {
case V_254 :
V_235 = F_149 ( V_237 , V_250 -> V_253 ) ;
if ( F_49 ( V_235 ) ) {
V_120 = F_50 ( V_235 ) ;
break;
}
V_250 -> V_253 -> V_235 = V_235 ;
break;
case V_255 :
if ( V_250 -> V_253 -> V_235 )
F_153 ( V_237 , V_250 -> V_253 ) ;
break;
default:
V_120 = - V_256 ;
break;
}
F_158 ( V_252 ) ;
return V_120 ;
}
static struct V_235 * F_159 ( struct V_247 * V_247 ,
struct V_238 * V_239 )
{
struct V_236 * V_257 ;
struct V_235 * V_235 ;
V_257 = F_160 ( V_247 ) ;
if ( ! V_257 )
return NULL ;
V_235 = F_149 ( V_257 , V_239 ) ;
F_161 ( V_247 ) ;
return V_235 ;
}
static void F_162 ( struct V_247 * V_247 ,
struct V_238 * V_239 )
{
struct V_236 * V_257 ;
V_257 = F_160 ( V_247 ) ;
if ( V_257 ) {
F_153 ( V_257 , V_239 ) ;
F_161 ( V_247 ) ;
}
}
static int F_163 ( struct V_247 * V_247 )
{
struct V_249 * V_250 = F_156 ( V_247 , V_251 ) ;
struct V_235 * V_235 ;
F_164 ( & V_250 -> V_258 ) ;
V_250 -> V_253 = F_165 ( & V_259 , 0 ) ;
if ( F_49 ( V_250 -> V_253 ) )
return F_50 ( V_250 -> V_253 ) ;
V_235 = F_159 ( V_247 , V_250 -> V_253 ) ;
if ( F_49 ( V_235 ) ) {
F_166 ( V_250 -> V_253 ) ;
return F_50 ( V_235 ) ;
}
V_250 -> V_253 -> V_235 = V_235 ;
return 0 ;
}
static void F_167 ( struct V_247 * V_247 )
{
struct V_249 * V_250 = F_156 ( V_247 , V_251 ) ;
F_162 ( V_247 , V_250 -> V_253 ) ;
F_166 ( V_250 -> V_253 ) ;
V_250 -> V_253 = NULL ;
}
static int T_10 F_168 ( void )
{
int V_120 ;
F_2 ( L_44 , V_18 ) ;
V_120 = F_169 ( & V_260 ) ;
if ( V_120 )
goto V_82;
V_120 = F_170 ( & V_261 ) ;
if ( V_120 )
goto V_262;
V_120 = F_171 ( & V_263 ) ;
if ( V_120 )
goto V_264;
V_82:
return V_120 ;
V_264:
F_172 ( & V_261 ) ;
V_262:
F_173 ( & V_260 ) ;
return V_120 ;
}
static void T_11 F_174 ( void )
{
F_2 ( L_45 ,
V_18 ) ;
F_172 ( & V_261 ) ;
F_175 ( & V_263 ) ;
F_173 ( & V_260 ) ;
}
