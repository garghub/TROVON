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
struct V_99 * V_11 = V_29 -> V_11 ;
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
const int V_100 = F_60 ( V_101 , & V_20 -> V_102 ) ;
struct V_99 * V_11 = V_29 -> V_11 ;
struct V_52 * V_53 = V_11 -> V_53 ;
if ( ! V_100 ) {
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
struct V_99 * V_103 ;
F_2 ( L_11 , V_18 ) ;
V_60 = F_20 ( V_58 , struct V_59 , V_61 . V_62 ) ;
V_103 = F_20 ( V_60 , struct V_99 , V_60 ) ;
if ( F_62 ( ! V_103 -> V_53 -> V_54 ) ) {
F_51 ( F_47 ( V_103 -> V_53 -> V_56 ) ,
V_103 -> args . V_40 , V_103 -> args . V_71 ) ;
}
F_63 ( V_103 ) ;
}
static void F_64 ( void * V_11 , int V_104 )
{
struct V_99 * V_103 = V_11 ;
if ( F_58 ( V_103 -> V_53 -> V_54 ) ) {
F_65 ( & F_47 ( V_103 -> V_53 -> V_56 ) -> V_105 ,
V_104 ) ;
}
V_103 -> V_60 . V_64 = V_103 -> V_53 -> V_54 ;
V_103 -> V_106 . V_107 = V_108 ;
F_42 ( & V_103 -> V_60 . V_61 . V_62 , F_61 ) ;
F_43 ( & V_103 -> V_60 . V_61 . V_62 ) ;
}
static void F_66 ( void )
{
return;
}
static void
F_67 ( struct V_109 * V_110 , T_1 V_4 , struct V_2 * V_3 )
{
F_2 ( L_20 , V_18 , V_3 ) ;
F_68 ( V_110 ) ;
V_110 -> V_111 = V_3 -> V_38 ;
V_110 -> V_112 = ( V_4 - V_3 -> V_35 + V_3 -> V_36 ) >>
( V_3 -> V_38 -> V_113 -> V_114 - V_42 ) ;
F_2 ( L_21 ,
V_18 , ( unsigned long long ) V_4 , ( long ) V_110 -> V_112 ,
V_110 -> V_115 ) ;
return;
}
static void
F_69 ( struct V_20 * V_20 , int error )
{
struct V_46 * V_47 = V_20 -> V_116 + V_20 -> V_117 - 1 ;
struct V_1 * V_1 = V_47 -> V_49 ;
F_70 ( V_1 ) ;
}
static int
F_71 ( struct V_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_40 , unsigned int V_41 )
{
struct V_20 * V_20 ;
struct V_1 * V_118 ;
T_1 V_4 ;
char * V_119 , * V_120 ;
int V_121 = 0 ;
F_2 ( L_22 , V_18 , V_40 , V_41 ) ;
V_118 = F_72 ( V_13 | V_122 ) ;
if ( V_118 == NULL )
return - V_44 ;
V_20 = F_29 ( V_31 , 1 ) ;
if ( V_20 == NULL )
return - V_44 ;
V_4 = ( V_1 -> V_123 << V_124 ) +
( V_40 / V_125 ) ;
V_20 -> V_24 . V_26 = V_4 - V_3 -> V_35 + V_3 -> V_36 ;
V_20 -> V_37 = V_3 -> V_38 ;
V_20 -> V_39 = F_69 ;
F_73 ( V_118 ) ;
if ( F_32 ( V_20 , V_118 ,
V_125 , F_74 ( V_40 , V_125 ) ) == 0 ) {
F_70 ( V_118 ) ;
F_38 ( V_20 ) ;
return - V_55 ;
}
F_25 ( V_23 , V_20 ) ;
F_75 ( V_118 ) ;
if ( F_58 ( ! F_60 ( V_101 , & V_20 -> V_102 ) ) ) {
V_121 = - V_55 ;
} else {
V_119 = F_76 ( V_1 ) ;
V_120 = F_76 ( V_118 ) ;
memcpy ( V_119 + V_40 , V_120 + V_40 , V_41 ) ;
F_77 ( V_120 ) ;
F_77 ( V_119 ) ;
}
F_78 ( V_118 ) ;
F_38 ( V_20 ) ;
return V_121 ;
}
static int
F_79 ( struct V_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_126 , unsigned int V_127 ,
bool V_128 )
{
int V_121 = 0 ;
unsigned int V_129 , V_96 ;
if ( V_128 ) {
V_129 = 0 ;
V_96 = V_45 ;
} else {
V_129 = F_74 ( V_126 , V_125 ) ;
V_96 = F_80 ( V_126 + V_127 , V_125 ) ;
}
F_2 ( L_23 , V_18 , V_126 , V_127 ) ;
if ( ! V_3 ) {
F_81 ( V_1 , V_129 , V_126 ,
V_126 + V_127 , V_96 ) ;
if ( V_129 == 0 && V_96 == V_45 &&
F_82 ( V_1 ) ) {
F_36 ( V_1 ) ;
F_70 ( V_1 ) ;
}
return V_121 ;
}
if ( V_129 != V_126 )
V_121 = F_71 ( V_1 , V_3 , V_129 , V_126 - V_129 ) ;
if ( ! V_121 && ( V_126 + V_127 < V_96 ) )
V_121 = F_71 ( V_1 , V_3 , V_126 + V_127 ,
V_96 - V_126 - V_127 ) ;
return V_121 ;
}
static int
F_83 ( struct V_1 * V_1 , struct V_2 * V_67 )
{
struct V_109 * V_110 = NULL ;
int V_121 = 0 ;
T_1 V_4 ;
F_2 ( L_24 , V_18 , V_1 ) ;
F_52 ( F_4 ( V_1 ) ) ;
if ( ! V_67 ) {
F_48 ( V_1 , 0 , V_130 ) ;
F_36 ( V_1 ) ;
goto V_131;
}
V_110 = F_84 ( V_1 , V_45 , 0 ) ;
if ( ! V_110 ) {
V_121 = - V_44 ;
goto V_131;
}
V_4 = ( T_1 ) V_1 -> V_123 << V_124 ;
F_67 ( V_110 , V_4 , V_67 ) ;
if ( ! F_85 ( V_110 ) )
V_121 = F_86 ( V_110 ) ;
if ( V_121 )
goto V_131;
F_36 ( V_1 ) ;
V_131:
if ( V_110 )
F_87 ( V_110 ) ;
if ( V_121 ) {
F_66 () ;
}
return V_121 ;
}
static struct V_1 *
F_88 ( struct V_88 * V_88 , T_6 V_123 ,
struct V_2 * V_67 )
{
struct V_1 * V_1 ;
int V_132 = 0 ;
V_1 = F_89 ( V_88 -> V_133 , V_123 ) ;
if ( V_1 )
goto V_134;
V_1 = F_90 ( V_88 -> V_133 , V_123 , V_13 ) ;
if ( F_58 ( ! V_1 ) ) {
F_2 ( L_25 , V_18 ) ;
return F_31 ( - V_44 ) ;
}
V_132 = 1 ;
V_134:
if ( F_6 ( V_1 ) || F_9 ( V_1 ) ) {
F_1 ( V_1 ) ;
if ( V_132 )
F_70 ( V_1 ) ;
F_57 ( V_1 ) ;
return NULL ;
}
if ( ! V_132 ) {
F_73 ( V_1 ) ;
V_132 = 1 ;
goto V_134;
}
if ( ! F_4 ( V_1 ) ) {
F_83 ( V_1 , V_67 ) ;
}
F_91 ( V_1 ) ;
F_70 ( V_1 ) ;
return V_1 ;
}
static enum V_65
F_92 ( struct V_99 * V_103 , int V_135 )
{
struct V_52 * V_53 = V_103 -> V_53 ;
int V_48 , V_121 , V_136 , V_75 , V_137 = 0 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_67 = NULL ;
T_1 V_4 , V_138 = 0 , V_68 = 0 ;
struct V_10 * V_29 = NULL ;
T_2 V_40 = V_103 -> args . V_40 ;
T_3 V_71 = V_103 -> args . V_71 ;
unsigned int V_72 , V_73 , V_139 ;
struct V_1 * * V_74 = V_103 -> args . V_74 ;
struct V_1 * V_1 ;
T_6 V_123 ;
T_7 V_140 ;
int V_141 =
F_93 ( V_53 -> V_88 ) -> V_142 >> V_77 ;
F_2 ( L_26 , V_18 , V_71 , V_40 ) ;
if ( V_53 -> V_79 != NULL &&
( ! F_94 ( V_40 , F_93 ( V_53 -> V_88 ) -> V_142 ) ||
! F_94 ( V_71 , F_93 ( V_53 -> V_88 ) -> V_142 ) ) ) {
F_2 ( L_27 ) ;
goto V_143;
}
V_29 = F_14 ( V_103 ) ;
if ( ! V_29 )
goto V_143;
V_29 -> V_19 = F_64 ;
V_4 = ( T_1 ) ( ( V_40 & ( long ) V_85 ) >> V_42 ) ;
V_3 = F_46 ( F_47 ( V_53 -> V_56 ) , V_4 , & V_67 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
F_2 ( L_28 , V_18 ) ;
goto V_143;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_62 ( ! F_95 ( V_3 -> V_8 ) ) )
V_29 -> V_15 ++ ;
else
goto V_143;
V_140 = V_40 >> V_77 ;
V_136 = F_96 ( V_140 , V_141 ) ;
V_4 = ( T_1 ) ( ( ( V_40 - V_136 * V_45 ) &
( long ) V_85 ) >> V_42 ) ;
V_68 = V_3 -> V_83 - ( V_4 - V_3 -> V_35 ) ;
V_144:
F_2 ( L_29 , V_18 , V_136 ) ;
for (; V_136 > 0 ; V_136 -- ) {
if ( F_12 ( V_3 -> V_8 , V_4 ) ) {
F_2 ( L_30 ,
( unsigned long long ) V_4 ) ;
goto V_145;
}
V_123 = V_4 >> V_124 ;
F_2 ( L_31 ,
V_18 , V_136 , V_123 ,
( unsigned long long ) V_4 ) ;
V_1 = F_88 ( V_53 -> V_88 , V_123 ,
V_67 ) ;
if ( F_58 ( F_49 ( V_1 ) ) ) {
V_53 -> V_54 = F_50 ( V_1 ) ;
goto V_82;
} else if ( V_1 == NULL )
goto V_145;
V_121 = F_97 ( V_3 -> V_8 , V_4 ,
V_87 ) ;
if ( F_58 ( V_121 ) ) {
F_2 ( L_32 ,
V_18 , V_121 ) ;
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
V_53 -> V_54 = V_121 ;
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
V_1 -> V_123 << V_77 ,
V_45 ) ;
V_20 = F_33 ( V_20 , V_136 , V_146 ,
V_4 , V_1 , V_3 ,
F_55 , V_29 ) ;
if ( F_49 ( V_20 ) ) {
V_53 -> V_54 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_82;
}
V_145:
V_4 += V_87 ;
V_68 -= V_87 ;
}
if ( V_137 )
goto V_147;
}
V_20 = F_24 ( V_146 , V_20 ) ;
V_75 = V_103 -> args . V_76 >> V_77 ;
for ( V_48 = V_75 ; V_48 < V_103 -> V_74 . V_80 ; V_48 ++ ) {
if ( ! V_68 ) {
F_45 ( V_3 ) ;
F_45 ( V_67 ) ;
V_20 = F_24 ( V_146 , V_20 ) ;
V_3 = F_46 ( F_47 ( V_53 -> V_56 ) ,
V_4 , & V_67 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
V_53 -> V_54 = - V_148 ;
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
V_139 = V_73 ;
if ( V_3 -> V_5 == V_7 &&
! F_12 ( V_3 -> V_8 , V_4 ) ) {
V_121 = F_79 ( V_74 [ V_48 ] , V_67 ,
V_72 , V_73 , true ) ;
if ( V_121 ) {
F_2 ( L_34 ,
V_18 , V_121 ) ;
V_53 -> V_54 = V_121 ;
goto V_82;
}
V_121 = F_97 ( V_3 -> V_8 , V_4 ,
V_87 ) ;
if ( F_58 ( V_121 ) ) {
F_2 ( L_32 ,
V_18 , V_121 ) ;
V_53 -> V_54 = V_121 ;
goto V_82;
}
V_72 = 0 ;
V_73 = V_45 ;
} else if ( ( V_72 & ( V_125 - 1 ) ) ||
( V_73 & ( V_125 - 1 ) ) ) {
unsigned int V_149 = V_72 ;
V_121 = F_79 ( V_74 [ V_48 ] , V_3 , V_72 ,
V_73 , false ) ;
V_72 = F_74 ( V_72 , V_125 ) ;
V_73 = F_80 ( V_149 + V_73 , V_125 )
- V_72 ;
}
V_20 = F_30 ( V_20 , V_103 -> V_74 . V_80 - V_48 , V_146 ,
V_4 , V_74 [ V_48 ] , V_3 ,
F_59 , V_29 ,
V_72 , V_73 ) ;
if ( F_49 ( V_20 ) ) {
V_53 -> V_54 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_82;
}
V_40 += V_139 ;
V_71 -= V_139 ;
V_4 += V_87 ;
V_138 = V_4 ;
V_68 -= V_87 ;
}
if ( V_3 -> V_5 == V_7 ) {
V_20 = F_24 ( V_146 , V_20 ) ;
V_140 = V_138 >> V_124 ;
V_136 = V_141 - F_96 ( V_140 , V_141 ) ;
if ( V_136 < V_141 ) {
V_137 = 1 ;
goto V_144;
}
}
V_147:
V_103 -> V_90 . V_71 = V_103 -> args . V_71 ;
V_82:
F_45 ( V_3 ) ;
F_45 ( V_67 ) ;
F_24 ( V_146 , V_20 ) ;
F_22 ( V_29 ) ;
return V_92 ;
V_143:
F_45 ( V_3 ) ;
F_45 ( V_67 ) ;
F_21 ( V_29 ) ;
return V_93 ;
}
static void
F_98 ( struct V_94 * V_95 , struct V_150 * V_151 )
{
int V_48 ;
struct V_2 * V_3 ;
F_99 ( & V_95 -> V_152 ) ;
for ( V_48 = 0 ; V_48 < V_153 ; V_48 ++ ) {
while ( ! F_100 ( & V_95 -> V_154 [ V_48 ] ) ) {
V_3 = F_101 ( & V_95 -> V_154 [ V_48 ] ,
struct V_2 ,
V_155 ) ;
F_102 ( & V_3 -> V_155 ) ;
F_45 ( V_3 ) ;
}
}
F_103 ( & V_95 -> V_152 ) ;
}
static void
F_104 ( struct V_156 * V_157 )
{
struct V_158 * V_159 , * V_140 ;
struct V_97 * V_98 , * V_160 ;
F_105 (pos, temp, &marks->im_tree.mtt_stub, it_link) {
F_102 ( & V_159 -> V_161 ) ;
F_21 ( V_159 ) ;
}
F_105 (se, stemp, &marks->im_extents, bse_node) {
F_102 ( & V_98 -> V_162 ) ;
F_21 ( V_98 ) ;
}
return;
}
static void F_106 ( struct V_163 * V_164 )
{
struct V_94 * V_95 = F_107 ( V_164 ) ;
F_2 ( L_11 , V_18 ) ;
F_98 ( V_95 , NULL ) ;
F_104 ( & V_95 -> V_105 ) ;
F_21 ( V_95 ) ;
}
static struct V_163 * F_108 ( struct V_88 * V_88 ,
T_8 V_165 )
{
struct V_94 * V_95 ;
F_2 ( L_11 , V_18 ) ;
V_95 = F_109 ( sizeof( * V_95 ) , V_165 ) ;
if ( ! V_95 )
return NULL ;
F_110 ( & V_95 -> V_152 ) ;
F_111 ( & V_95 -> V_154 [ 0 ] ) ;
F_111 ( & V_95 -> V_154 [ 1 ] ) ;
F_111 ( & V_95 -> V_166 ) ;
F_111 ( & V_95 -> V_167 ) ;
V_95 -> V_168 = 0 ;
V_95 -> V_169 = F_93 ( V_88 ) -> V_142 >> V_42 ;
F_112 ( & V_95 -> V_105 , V_95 -> V_169 ) ;
return & V_95 -> V_170 ;
}
static void F_113 ( struct V_171 * V_56 )
{
F_2 ( L_11 , V_18 ) ;
F_21 ( V_56 ) ;
}
static struct V_171 * F_114 ( struct V_163 * V_164 ,
struct V_172 * V_173 ,
T_8 V_165 )
{
struct V_171 * V_56 ;
int V_174 ;
F_2 ( L_11 , V_18 ) ;
V_56 = F_109 ( sizeof( * V_56 ) , V_165 ) ;
if ( ! V_56 )
return F_31 ( - V_44 ) ;
V_174 = F_115 ( V_164 , V_173 , V_165 ) ;
if ( V_174 ) {
F_21 ( V_56 ) ;
return F_31 ( V_174 ) ;
}
return V_56 ;
}
static void
F_116 ( struct V_163 * V_164 , struct V_175 * V_176 ,
const struct V_177 * V_178 )
{
F_2 ( L_11 , V_18 ) ;
F_117 ( F_107 ( V_164 ) , V_176 , V_178 ) ;
}
static void
F_118 ( struct V_179 * V_180 )
{
struct V_163 * V_164 = F_119 ( V_180 -> args . V_88 ) -> V_181 ;
F_2 ( L_11 , V_18 ) ;
F_120 ( F_107 ( V_164 ) , & V_180 -> args , V_180 -> V_90 . V_174 ) ;
}
static void F_121 ( struct V_182 * V_183 )
{
if ( V_183 ) {
struct V_184 * V_185 , * V_186 ;
F_105 (dev, tmp, &mid->bm_devlist, bm_node) {
F_102 ( & V_185 -> V_187 ) ;
F_122 ( V_185 ) ;
}
F_21 ( V_183 ) ;
}
}
static struct V_184 *
F_123 ( struct V_188 * V_189 , const struct V_190 * V_191 ,
struct V_192 * V_193 )
{
struct V_194 * V_185 ;
struct V_184 * V_12 ;
T_9 V_195 ;
int V_196 ;
struct V_1 * * V_74 = NULL ;
int V_48 , V_197 ;
V_195 = V_189 -> V_198 -> V_199 -> V_200 . V_195 ;
V_196 = F_124 ( 0 , V_195 ) ;
F_2 ( L_35 ,
V_18 , V_195 , V_196 ) ;
V_185 = F_15 ( sizeof( * V_185 ) , V_13 ) ;
if ( ! V_185 ) {
F_2 ( L_36 , V_18 ) ;
return F_31 ( - V_44 ) ;
}
V_74 = F_109 ( V_196 * sizeof( struct V_1 * ) , V_13 ) ;
if ( V_74 == NULL ) {
F_21 ( V_185 ) ;
return F_31 ( - V_44 ) ;
}
for ( V_48 = 0 ; V_48 < V_196 ; V_48 ++ ) {
V_74 [ V_48 ] = F_72 ( V_13 ) ;
if ( ! V_74 [ V_48 ] ) {
V_12 = F_31 ( - V_44 ) ;
goto V_201;
}
}
memcpy ( & V_185 -> V_202 , V_193 , sizeof( * V_193 ) ) ;
V_185 -> V_203 = V_204 ;
V_185 -> V_74 = V_74 ;
V_185 -> V_76 = 0 ;
V_185 -> V_205 = V_130 * V_196 ;
V_185 -> V_206 = 0 ;
V_185 -> V_207 = V_195 - V_208 ;
F_2 ( L_37 , V_18 , V_185 -> V_202 . V_11 ) ;
V_197 = F_125 ( V_189 , V_185 , NULL ) ;
F_2 ( L_38 , V_18 , V_197 ) ;
if ( V_197 ) {
V_12 = F_31 ( V_197 ) ;
goto V_201;
}
V_12 = F_126 ( V_189 , V_185 ) ;
V_201:
for ( V_48 = 0 ; V_48 < V_196 ; V_48 ++ )
F_78 ( V_74 [ V_48 ] ) ;
F_21 ( V_74 ) ;
F_21 ( V_185 ) ;
return V_12 ;
}
static int
F_127 ( struct V_188 * V_189 , const struct V_190 * V_191 )
{
struct V_182 * V_209 = NULL ;
struct V_210 * V_211 = NULL ;
struct V_184 * V_212 ;
F_128 ( V_213 ) ;
int V_174 , V_48 ;
F_2 ( L_11 , V_18 ) ;
if ( V_189 -> V_142 == 0 ) {
F_2 ( L_39 , V_18 ) ;
return - V_148 ;
}
V_209 = F_109 ( sizeof( struct V_182 ) , V_13 ) ;
if ( ! V_209 ) {
V_174 = - V_44 ;
goto V_214;
}
F_110 ( & V_209 -> V_215 ) ;
F_111 ( & V_209 -> V_216 ) ;
V_211 = F_15 ( sizeof( struct V_210 ) , V_13 ) ;
if ( ! V_211 ) {
V_174 = - V_44 ;
goto V_214;
}
V_211 -> V_91 = 0 ;
while ( ! V_211 -> V_91 ) {
V_174 = F_129 ( V_189 , V_191 , V_211 ) ;
if ( V_174 )
goto V_214;
F_2 ( L_40 ,
V_18 , V_211 -> V_217 , V_211 -> V_91 ) ;
for ( V_48 = 0 ; V_48 < V_211 -> V_217 ; V_48 ++ ) {
V_212 = F_123 ( V_189 , V_191 ,
& V_211 -> V_202 [ V_48 ] ) ;
if ( F_49 ( V_212 ) ) {
V_174 = F_50 ( V_212 ) ;
goto V_214;
}
F_99 ( & V_209 -> V_215 ) ;
F_130 ( & V_212 -> V_187 , & V_209 -> V_216 ) ;
F_103 ( & V_209 -> V_215 ) ;
}
}
F_2 ( L_41 , V_18 ) ;
V_189 -> V_218 = V_209 ;
V_219:
F_21 ( V_211 ) ;
return V_174 ;
V_214:
F_121 ( V_209 ) ;
goto V_219;
}
static int
F_131 ( struct V_188 * V_189 )
{
struct V_182 * V_209 = V_189 -> V_218 ;
F_2 ( L_11 , V_18 ) ;
F_121 ( V_209 ) ;
F_2 ( L_42 , V_18 ) ;
return 0 ;
}
static bool
F_132 ( struct V_220 * V_221 , unsigned int V_222 )
{
return F_94 ( V_221 -> V_223 , V_222 ) &&
F_94 ( V_221 -> V_224 , V_222 ) ;
}
static void
F_133 ( struct V_225 * V_226 , struct V_220 * V_221 )
{
if ( V_226 -> V_227 != NULL &&
! F_132 ( V_221 , V_125 ) )
F_134 ( V_226 ) ;
else
F_135 ( V_226 , V_221 ) ;
}
static bool
F_136 ( struct V_225 * V_226 , struct V_220 * V_228 ,
struct V_220 * V_221 )
{
if ( V_226 -> V_227 != NULL &&
! F_132 ( V_221 , V_125 ) )
return false ;
return F_137 ( V_226 , V_228 , V_221 ) ;
}
static T_7 F_138 ( struct V_88 * V_88 , T_6 V_229 )
{
struct V_230 * V_231 = V_88 -> V_133 ;
T_6 V_96 ;
V_96 = F_139 ( F_140 ( V_88 ) , V_45 ) ;
if ( V_96 != F_119 ( V_88 ) -> V_80 ) {
F_141 () ;
V_96 = F_142 ( & V_231 -> V_232 , V_229 + 1 , V_233 ) ;
F_143 () ;
}
if ( ! V_96 )
return F_140 ( V_88 ) - ( V_229 << V_77 ) ;
else
return ( V_96 - V_229 ) << V_77 ;
}
static void
F_144 ( struct V_225 * V_226 , struct V_220 * V_221 )
{
if ( V_226 -> V_227 != NULL &&
! F_132 ( V_221 , V_45 ) ) {
F_145 ( V_226 ) ;
} else {
T_7 V_234 ;
if ( V_226 -> V_227 == NULL )
V_234 = F_138 ( V_226 -> V_235 ,
V_221 -> V_236 ) ;
else
V_234 = F_146 ( V_226 -> V_227 ) ;
F_147 ( V_226 , V_221 , V_234 ) ;
}
}
static bool
F_148 ( struct V_225 * V_226 , struct V_220 * V_228 ,
struct V_220 * V_221 )
{
if ( V_226 -> V_227 != NULL &&
! F_132 ( V_221 , V_45 ) )
return false ;
return F_137 ( V_226 , V_228 , V_221 ) ;
}
static struct V_237 * F_149 ( struct V_238 * V_239 ,
struct V_240 * V_241 )
{
struct V_237 * V_242 , * V_237 ;
V_242 = F_150 ( V_239 , V_243 ) ;
if ( V_242 == NULL )
return F_31 ( - V_244 ) ;
V_237 = F_151 ( V_242 , L_43 , NULL , V_241 ) ;
F_152 ( V_242 ) ;
return V_237 ;
}
static void F_153 ( struct V_238 * V_239 ,
struct V_240 * V_241 )
{
if ( V_241 -> V_237 )
F_154 ( V_241 -> V_237 ) ;
}
static int F_155 ( struct V_245 * V_246 , unsigned long V_247 ,
void * V_248 )
{
struct V_238 * V_239 = V_248 ;
struct V_249 * V_249 = V_239 -> V_250 ;
struct V_251 * V_252 = F_156 ( V_249 , V_253 ) ;
struct V_237 * V_237 ;
int V_121 = 0 ;
if ( ! F_157 ( V_254 ) )
return 0 ;
if ( V_252 -> V_255 == NULL ) {
F_158 ( V_254 ) ;
return 0 ;
}
switch ( V_247 ) {
case V_256 :
V_237 = F_149 ( V_239 , V_252 -> V_255 ) ;
if ( F_49 ( V_237 ) ) {
V_121 = F_50 ( V_237 ) ;
break;
}
V_252 -> V_255 -> V_237 = V_237 ;
break;
case V_257 :
if ( V_252 -> V_255 -> V_237 )
F_153 ( V_239 , V_252 -> V_255 ) ;
break;
default:
V_121 = - V_258 ;
break;
}
F_158 ( V_254 ) ;
return V_121 ;
}
static struct V_237 * F_159 ( struct V_249 * V_249 ,
struct V_240 * V_241 )
{
struct V_238 * V_259 ;
struct V_237 * V_237 ;
V_259 = F_160 ( V_249 ) ;
if ( ! V_259 )
return NULL ;
V_237 = F_149 ( V_259 , V_241 ) ;
F_161 ( V_249 ) ;
return V_237 ;
}
static void F_162 ( struct V_249 * V_249 ,
struct V_240 * V_241 )
{
struct V_238 * V_259 ;
V_259 = F_160 ( V_249 ) ;
if ( V_259 ) {
F_153 ( V_259 , V_241 ) ;
F_161 ( V_249 ) ;
}
}
static int F_163 ( struct V_249 * V_249 )
{
struct V_251 * V_252 = F_156 ( V_249 , V_253 ) ;
struct V_237 * V_237 ;
F_164 ( & V_252 -> V_260 ) ;
V_252 -> V_255 = F_165 ( & V_261 , 0 ) ;
if ( F_49 ( V_252 -> V_255 ) )
return F_50 ( V_252 -> V_255 ) ;
V_237 = F_159 ( V_249 , V_252 -> V_255 ) ;
if ( F_49 ( V_237 ) ) {
F_166 ( V_252 -> V_255 ) ;
return F_50 ( V_237 ) ;
}
V_252 -> V_255 -> V_237 = V_237 ;
return 0 ;
}
static void F_167 ( struct V_249 * V_249 )
{
struct V_251 * V_252 = F_156 ( V_249 , V_253 ) ;
F_162 ( V_249 , V_252 -> V_255 ) ;
F_166 ( V_252 -> V_255 ) ;
V_252 -> V_255 = NULL ;
}
static int T_10 F_168 ( void )
{
int V_121 ;
F_2 ( L_44 , V_18 ) ;
V_121 = F_169 ( & V_262 ) ;
if ( V_121 )
goto V_82;
V_121 = F_170 ( & V_263 ) ;
if ( V_121 )
goto V_264;
V_121 = F_171 ( & V_265 ) ;
if ( V_121 )
goto V_266;
V_82:
return V_121 ;
V_266:
F_172 ( & V_263 ) ;
V_264:
F_173 ( & V_262 ) ;
return V_121 ;
}
static void T_11 F_174 ( void )
{
F_2 ( L_45 ,
V_18 ) ;
F_172 ( & V_263 ) ;
F_175 ( & V_265 ) ;
F_173 ( & V_262 ) ;
}
