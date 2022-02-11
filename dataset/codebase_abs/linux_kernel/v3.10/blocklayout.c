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
V_21 == V_23 ? L_13 : L_14 ,
V_20 -> V_24 , ( unsigned long long ) V_20 -> V_25 ) ;
F_25 ( V_21 , V_20 ) ;
}
return NULL ;
}
static struct V_20 * F_26 ( int V_26 , T_1 V_4 ,
struct V_2 * V_3 ,
void (* F_27)( struct V_20 * , int V_27 ) ,
struct V_10 * V_28 )
{
struct V_20 * V_20 ;
V_26 = F_28 ( V_26 , V_29 ) ;
V_20 = F_29 ( V_30 , V_26 ) ;
if ( ! V_20 && ( V_31 -> V_32 & V_33 ) ) {
while ( ! V_20 && ( V_26 /= 2 ) )
V_20 = F_29 ( V_30 , V_26 ) ;
}
if ( V_20 ) {
V_20 -> V_25 = V_4 - V_3 -> V_34 + V_3 -> V_35 ;
V_20 -> V_36 = V_3 -> V_37 ;
V_20 -> V_38 = F_27 ;
V_20 -> V_22 = V_28 ;
}
return V_20 ;
}
static struct V_20 * F_30 ( struct V_20 * V_20 , int V_26 , int V_21 ,
T_1 V_4 , struct V_1 * V_1 ,
struct V_2 * V_3 ,
void (* F_27)( struct V_20 * , int V_27 ) ,
struct V_10 * V_28 ,
unsigned int V_39 , int V_40 )
{
V_4 = V_4 + ( V_39 >> V_41 ) ;
F_2 ( L_15 , V_18 ,
V_26 , V_21 , ( unsigned long long ) V_4 , V_39 , V_40 ) ;
V_42:
if ( ! V_20 ) {
V_20 = F_26 ( V_26 , V_4 , V_3 , F_27 , V_28 ) ;
if ( ! V_20 )
return F_31 ( - V_43 ) ;
}
if ( F_32 ( V_20 , V_1 , V_40 , V_39 ) < V_40 ) {
V_20 = F_24 ( V_21 , V_20 ) ;
goto V_42;
}
return V_20 ;
}
static struct V_20 * F_33 ( struct V_20 * V_20 , int V_26 , int V_21 ,
T_1 V_4 , struct V_1 * V_1 ,
struct V_2 * V_3 ,
void (* F_27)( struct V_20 * , int V_27 ) ,
struct V_10 * V_28 )
{
return F_30 ( V_20 , V_26 , V_21 , V_4 , V_1 , V_3 ,
F_27 , V_28 , 0 , V_44 ) ;
}
static void F_34 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_45 = F_35 ( V_46 , & V_20 -> V_47 ) ;
struct V_48 * V_49 = V_20 -> V_50 + V_20 -> V_51 - 1 ;
do {
struct V_1 * V_1 = V_49 -> V_52 ;
if ( -- V_49 >= V_20 -> V_50 )
F_36 ( & V_49 -> V_52 -> V_32 ) ;
if ( V_45 )
F_37 ( V_1 ) ;
} while ( V_49 >= V_20 -> V_50 );
if ( ! V_45 ) {
struct V_53 * V_54 = V_28 -> V_11 ;
struct V_55 * V_56 = V_54 -> V_56 ;
if ( ! V_56 -> V_57 )
V_56 -> V_57 = - V_58 ;
F_38 ( V_56 -> V_59 ) ;
}
F_39 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_40 ( struct V_60 * V_61 )
{
struct V_62 * V_63 ;
struct V_53 * V_54 ;
F_2 ( L_11 , V_18 ) ;
V_63 = F_20 ( V_61 , struct V_62 , V_64 . V_65 ) ;
V_54 = F_20 ( V_63 , struct V_53 , V_63 ) ;
F_41 ( V_54 ) ;
}
static void
F_42 ( void * V_11 , int V_66 )
{
struct V_53 * V_54 = V_11 ;
V_54 -> V_63 . V_67 = V_54 -> V_56 -> V_57 ;
F_43 ( & V_54 -> V_63 . V_64 . V_65 , F_40 ) ;
F_44 ( & V_54 -> V_63 . V_64 . V_65 ) ;
}
static enum V_68
F_45 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_56 ;
int V_69 , V_70 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_71 = NULL ;
T_1 V_4 , V_72 = 0 ;
struct V_10 * V_28 ;
T_2 V_73 = V_54 -> args . V_39 ;
T_3 V_74 = V_54 -> args . V_75 ;
unsigned int V_76 , V_77 ;
struct V_1 * * V_78 = V_54 -> args . V_78 ;
int V_79 = V_54 -> args . V_80 >> V_81 ;
const bool V_82 = ( V_56 -> V_83 != NULL ) ;
F_2 ( L_16 , V_18 ,
V_54 -> V_78 . V_84 , V_73 , ( unsigned int ) V_54 -> args . V_75 ) ;
V_28 = F_14 ( V_54 ) ;
if ( ! V_28 )
goto V_85;
V_28 -> V_19 = F_42 ;
V_4 = ( T_1 ) ( V_73 >> V_41 ) ;
for ( V_69 = V_79 ; V_69 < V_54 -> V_78 . V_84 ; V_69 ++ ) {
if ( ! V_72 ) {
F_46 ( V_3 ) ;
F_46 ( V_71 ) ;
V_20 = F_24 ( V_23 , V_20 ) ;
V_3 = F_47 ( F_48 ( V_56 -> V_59 ) ,
V_4 , & V_71 ) ;
if ( ! V_3 ) {
V_56 -> V_57 = - V_58 ;
goto V_86;
}
V_72 = V_3 -> V_87 -
( V_4 - V_3 -> V_34 ) ;
if ( V_71 ) {
T_1 V_88 = V_71 -> V_87 -
( V_4 - V_71 -> V_34 ) ;
V_72 = F_28 ( V_72 , V_88 ) ;
}
}
if ( V_82 ) {
V_76 = V_73 & ~ V_89 ;
if ( V_76 + V_74 > V_44 )
V_77 = V_44 - V_76 ;
else
V_77 = V_74 ;
V_73 += V_77 ;
V_74 -= V_77 ;
V_4 += ( V_76 >> V_41 ) ;
} else {
V_76 = 0 ;
V_77 = V_44 ;
}
V_70 = F_11 ( V_3 , V_4 ) ;
if ( V_70 && ! V_71 ) {
V_20 = F_24 ( V_23 , V_20 ) ;
F_2 ( L_17 , V_18 ) ;
F_49 ( V_78 [ V_69 ] , V_76 , V_77 ) ;
F_1 ( V_78 [ V_69 ] ) ;
F_37 ( V_78 [ V_69 ] ) ;
} else {
struct V_2 * V_90 ;
V_90 = ( V_70 && V_71 ) ? V_71 : V_3 ;
V_20 = F_30 ( V_20 , V_54 -> V_78 . V_84 - V_69 ,
V_23 ,
V_4 , V_78 [ V_69 ] , V_90 ,
F_34 , V_28 ,
V_76 , V_77 ) ;
if ( F_50 ( V_20 ) ) {
V_56 -> V_57 = F_51 ( V_20 ) ;
V_20 = NULL ;
goto V_86;
}
}
V_4 += ( V_77 >> V_41 ) ;
V_72 -= V_91 ;
}
if ( ( V_4 << V_41 ) >= V_56 -> V_92 -> V_93 ) {
V_54 -> V_94 . V_95 = 1 ;
V_54 -> V_94 . V_75 = V_56 -> V_92 -> V_93 - V_54 -> args . V_39 ;
} else {
V_54 -> V_94 . V_75 = ( V_4 << V_41 ) - V_54 -> args . V_39 ;
}
V_86:
F_46 ( V_3 ) ;
F_46 ( V_71 ) ;
F_24 ( V_23 , V_20 ) ;
F_22 ( V_28 ) ;
return V_96 ;
V_85:
F_2 ( L_18 ) ;
return V_97 ;
}
static void F_52 ( struct V_98 * V_99 ,
T_4 V_39 , T_5 V_75 )
{
T_1 V_4 , V_100 ;
struct V_2 * V_3 ;
struct V_101 * V_102 ;
F_2 ( L_19 , V_18 , V_39 , V_75 ) ;
if ( V_75 == 0 )
return;
V_4 = ( V_39 & ( long ) ( V_89 ) ) >> V_41 ;
V_100 = ( V_39 + V_75 + V_44 - 1 ) & ( long ) ( V_89 ) ;
V_100 >>= V_41 ;
while ( V_4 < V_100 ) {
T_1 V_40 ;
V_3 = F_47 ( V_99 , V_4 , NULL ) ;
F_53 ( ! V_3 ) ;
V_40 = F_28 ( V_100 , V_3 -> V_34 + V_3 -> V_87 ) - V_4 ;
if ( V_3 -> V_5 == V_7 ) {
V_102 = F_54 ( V_3 -> V_8 ) ;
F_53 ( ! V_102 ) ;
F_55 ( V_3 , V_4 , V_40 , V_102 ) ;
}
V_4 += V_40 ;
F_46 ( V_3 ) ;
}
}
static void F_56 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_45 = F_35 ( V_46 , & V_20 -> V_47 ) ;
struct V_48 * V_49 = V_20 -> V_50 + V_20 -> V_51 - 1 ;
do {
struct V_1 * V_1 = V_49 -> V_52 ;
if ( -- V_49 >= V_20 -> V_50 )
F_36 ( & V_49 -> V_52 -> V_32 ) ;
F_57 ( V_1 ) ;
F_58 ( V_1 ) ;
} while ( V_49 >= V_20 -> V_50 );
if ( F_59 ( ! V_45 ) ) {
struct V_103 * V_11 = V_28 -> V_11 ;
struct V_55 * V_56 = V_11 -> V_56 ;
if ( ! V_56 -> V_57 )
V_56 -> V_57 = - V_58 ;
F_38 ( V_56 -> V_59 ) ;
}
F_39 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_60 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_45 = F_35 ( V_46 , & V_20 -> V_47 ) ;
struct V_103 * V_11 = V_28 -> V_11 ;
struct V_55 * V_56 = V_11 -> V_56 ;
if ( ! V_45 ) {
if ( ! V_56 -> V_57 )
V_56 -> V_57 = - V_58 ;
F_38 ( V_56 -> V_59 ) ;
}
F_39 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_61 ( struct V_60 * V_61 )
{
struct V_62 * V_63 ;
struct V_103 * V_104 ;
F_2 ( L_11 , V_18 ) ;
V_63 = F_20 ( V_61 , struct V_62 , V_64 . V_65 ) ;
V_104 = F_20 ( V_63 , struct V_103 , V_63 ) ;
if ( F_62 ( ! V_104 -> V_56 -> V_57 ) ) {
F_52 ( F_48 ( V_104 -> V_56 -> V_59 ) ,
V_104 -> args . V_39 , V_104 -> args . V_75 ) ;
}
F_63 ( V_104 ) ;
}
static void F_64 ( void * V_11 , int V_105 )
{
struct V_103 * V_104 = V_11 ;
if ( F_59 ( V_104 -> V_56 -> V_57 ) ) {
F_65 ( & F_48 ( V_104 -> V_56 -> V_59 ) -> V_106 ,
V_105 ) ;
}
V_104 -> V_63 . V_67 = V_104 -> V_56 -> V_57 ;
V_104 -> V_107 . V_108 = V_109 ;
F_43 ( & V_104 -> V_63 . V_64 . V_65 , F_61 ) ;
F_44 ( & V_104 -> V_63 . V_64 . V_65 ) ;
}
static void F_66 ( void )
{
return;
}
static void
F_67 ( struct V_110 * V_111 , T_1 V_4 , struct V_2 * V_3 )
{
F_2 ( L_20 , V_18 , V_3 ) ;
F_68 ( V_111 ) ;
V_111 -> V_112 = V_3 -> V_37 ;
V_111 -> V_113 = ( V_4 - V_3 -> V_34 + V_3 -> V_35 ) >>
( V_3 -> V_37 -> V_114 -> V_115 - V_41 ) ;
F_2 ( L_21 ,
V_18 , ( unsigned long long ) V_4 , ( long ) V_111 -> V_113 ,
V_111 -> V_116 ) ;
return;
}
static void
F_69 ( struct V_20 * V_20 , int error )
{
struct V_48 * V_49 = V_20 -> V_50 + V_20 -> V_51 - 1 ;
struct V_1 * V_1 = V_49 -> V_52 ;
F_70 ( V_1 ) ;
}
static int
F_71 ( struct V_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_39 , unsigned int V_40 )
{
struct V_20 * V_20 ;
struct V_1 * V_117 ;
T_1 V_4 ;
char * V_118 , * V_119 ;
int V_120 = 0 ;
F_2 ( L_22 , V_18 , V_39 , V_40 ) ;
V_117 = F_72 ( V_13 | V_121 ) ;
if ( V_117 == NULL )
return - V_43 ;
V_20 = F_29 ( V_30 , 1 ) ;
if ( V_20 == NULL )
return - V_43 ;
V_4 = ( V_1 -> V_122 << V_123 ) +
( V_39 / V_124 ) ;
V_20 -> V_25 = V_4 - V_3 -> V_34 + V_3 -> V_35 ;
V_20 -> V_36 = V_3 -> V_37 ;
V_20 -> V_38 = F_69 ;
F_73 ( V_117 ) ;
if ( F_32 ( V_20 , V_117 ,
V_124 , F_74 ( V_39 , V_124 ) ) == 0 ) {
F_70 ( V_117 ) ;
F_39 ( V_20 ) ;
return - V_58 ;
}
F_25 ( V_23 , V_20 ) ;
F_75 ( V_117 ) ;
if ( F_59 ( ! F_35 ( V_46 , & V_20 -> V_47 ) ) ) {
V_120 = - V_58 ;
} else {
V_118 = F_76 ( V_1 ) ;
V_119 = F_76 ( V_117 ) ;
memcpy ( V_118 + V_39 , V_119 + V_39 , V_40 ) ;
F_77 ( V_119 ) ;
F_77 ( V_118 ) ;
}
F_78 ( V_117 ) ;
F_39 ( V_20 ) ;
return V_120 ;
}
static int
F_79 ( struct V_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_125 , unsigned int V_126 ,
bool V_127 )
{
int V_120 = 0 ;
unsigned int V_128 , V_100 ;
if ( V_127 ) {
V_128 = 0 ;
V_100 = V_44 ;
} else {
V_128 = F_74 ( V_125 , V_124 ) ;
V_100 = F_80 ( V_125 + V_126 , V_124 ) ;
}
F_2 ( L_23 , V_18 , V_125 , V_126 ) ;
if ( ! V_3 ) {
F_81 ( V_1 , V_128 , V_125 ,
V_125 + V_126 , V_100 ) ;
if ( V_128 == 0 && V_100 == V_44 &&
F_82 ( V_1 ) ) {
F_37 ( V_1 ) ;
F_70 ( V_1 ) ;
}
return V_120 ;
}
if ( V_128 != V_125 )
V_120 = F_71 ( V_1 , V_3 , V_128 , V_125 - V_128 ) ;
if ( ! V_120 && ( V_125 + V_126 < V_100 ) )
V_120 = F_71 ( V_1 , V_3 , V_125 + V_126 ,
V_100 - V_125 - V_126 ) ;
return V_120 ;
}
static int
F_83 ( struct V_1 * V_1 , struct V_2 * V_71 )
{
struct V_110 * V_111 = NULL ;
int V_120 = 0 ;
T_1 V_4 ;
F_2 ( L_24 , V_18 , V_1 ) ;
F_53 ( F_4 ( V_1 ) ) ;
if ( ! V_71 ) {
F_49 ( V_1 , 0 , V_129 ) ;
F_37 ( V_1 ) ;
goto V_130;
}
V_111 = F_84 ( V_1 , V_44 , 0 ) ;
if ( ! V_111 ) {
V_120 = - V_43 ;
goto V_130;
}
V_4 = ( T_1 ) V_1 -> V_122 << V_123 ;
F_67 ( V_111 , V_4 , V_71 ) ;
if ( ! F_85 ( V_111 ) )
V_120 = F_86 ( V_111 ) ;
if ( V_120 )
goto V_130;
F_37 ( V_1 ) ;
V_130:
if ( V_111 )
F_87 ( V_111 ) ;
if ( V_120 ) {
F_66 () ;
}
return V_120 ;
}
static struct V_1 *
F_88 ( struct V_92 * V_92 , T_6 V_122 ,
struct V_2 * V_71 )
{
struct V_1 * V_1 ;
int V_131 = 0 ;
V_1 = F_89 ( V_92 -> V_132 , V_122 ) ;
if ( V_1 )
goto V_133;
V_1 = F_90 ( V_92 -> V_132 , V_122 , V_13 ) ;
if ( F_59 ( ! V_1 ) ) {
F_2 ( L_25 , V_18 ) ;
return F_31 ( - V_43 ) ;
}
V_131 = 1 ;
V_133:
if ( F_6 ( V_1 ) || F_9 ( V_1 ) ) {
F_1 ( V_1 ) ;
if ( V_131 )
F_70 ( V_1 ) ;
F_58 ( V_1 ) ;
return NULL ;
}
if ( ! V_131 ) {
F_73 ( V_1 ) ;
V_131 = 1 ;
goto V_133;
}
if ( ! F_4 ( V_1 ) ) {
F_83 ( V_1 , V_71 ) ;
}
F_91 ( V_1 ) ;
F_70 ( V_1 ) ;
return V_1 ;
}
static enum V_68
F_92 ( struct V_103 * V_104 , int V_134 )
{
struct V_55 * V_56 = V_104 -> V_56 ;
int V_69 , V_120 , V_135 , V_79 , V_136 = 0 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_71 = NULL ;
T_1 V_4 , V_137 = 0 , V_72 = 0 ;
struct V_10 * V_28 = NULL ;
T_2 V_39 = V_104 -> args . V_39 ;
T_3 V_75 = V_104 -> args . V_75 ;
unsigned int V_76 , V_77 , V_138 ;
struct V_1 * * V_78 = V_104 -> args . V_78 ;
struct V_1 * V_1 ;
T_6 V_122 ;
T_7 V_139 ;
int V_140 =
F_93 ( V_56 -> V_92 ) -> V_141 >> V_81 ;
F_2 ( L_26 , V_18 , V_75 , V_39 ) ;
if ( V_56 -> V_83 != NULL &&
( ! F_94 ( V_39 , F_93 ( V_56 -> V_92 ) -> V_141 ) ||
! F_94 ( V_75 , F_93 ( V_56 -> V_92 ) -> V_141 ) ) ) {
F_2 ( L_27 ) ;
goto V_142;
}
V_28 = F_14 ( V_104 ) ;
if ( ! V_28 )
goto V_142;
V_28 -> V_19 = F_64 ;
V_4 = ( T_1 ) ( ( V_39 & ( long ) V_89 ) >> V_41 ) ;
V_3 = F_47 ( F_48 ( V_56 -> V_59 ) , V_4 , & V_71 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
F_2 ( L_28 , V_18 ) ;
goto V_142;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_62 ( ! F_95 ( V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else
goto V_142;
V_139 = V_39 >> V_81 ;
V_135 = F_96 ( V_139 , V_140 ) ;
V_4 = ( T_1 ) ( ( ( V_39 - V_135 * V_44 ) &
( long ) V_89 ) >> V_41 ) ;
V_72 = V_3 -> V_87 - ( V_4 - V_3 -> V_34 ) ;
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
V_1 = F_88 ( V_56 -> V_92 , V_122 ,
V_71 ) ;
if ( F_59 ( F_50 ( V_1 ) ) ) {
V_56 -> V_57 = F_51 ( V_1 ) ;
goto V_86;
} else if ( V_1 == NULL )
goto V_144;
V_120 = F_97 ( V_3 -> V_8 , V_4 ,
V_91 ) ;
if ( F_59 ( V_120 ) ) {
F_2 ( L_32 ,
V_18 , V_120 ) ;
F_57 ( V_1 ) ;
F_58 ( V_1 ) ;
V_56 -> V_57 = V_120 ;
goto V_86;
}
if ( F_62 ( ! F_95 ( V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else {
F_57 ( V_1 ) ;
F_58 ( V_1 ) ;
V_56 -> V_57 = - V_43 ;
goto V_86;
}
F_52 ( F_48 ( V_56 -> V_59 ) ,
V_1 -> V_122 << V_81 ,
V_44 ) ;
V_20 = F_33 ( V_20 , V_135 , V_145 ,
V_4 , V_1 , V_3 ,
F_56 , V_28 ) ;
if ( F_50 ( V_20 ) ) {
V_56 -> V_57 = F_51 ( V_20 ) ;
V_20 = NULL ;
goto V_86;
}
V_144:
V_4 += V_91 ;
V_72 -= V_91 ;
}
if ( V_136 )
goto V_146;
}
V_20 = F_24 ( V_145 , V_20 ) ;
V_79 = V_104 -> args . V_80 >> V_81 ;
for ( V_69 = V_79 ; V_69 < V_104 -> V_78 . V_84 ; V_69 ++ ) {
if ( ! V_72 ) {
F_46 ( V_3 ) ;
F_46 ( V_71 ) ;
V_20 = F_24 ( V_145 , V_20 ) ;
V_3 = F_47 ( F_48 ( V_56 -> V_59 ) ,
V_4 , & V_71 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
V_56 -> V_57 = - V_147 ;
goto V_86;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_62 ( ! F_95 (
V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else {
V_56 -> V_57 = - V_43 ;
goto V_86;
}
}
V_72 = V_3 -> V_87 -
( V_4 - V_3 -> V_34 ) ;
}
F_2 ( L_33 , V_18 , V_39 , V_75 ) ;
V_76 = V_39 & ~ V_89 ;
if ( V_76 + V_75 > V_44 )
V_77 = V_44 - V_76 ;
else
V_77 = V_75 ;
V_138 = V_77 ;
if ( V_3 -> V_5 == V_7 &&
! F_12 ( V_3 -> V_8 , V_4 ) ) {
V_120 = F_79 ( V_78 [ V_69 ] , V_71 ,
V_76 , V_77 , true ) ;
if ( V_120 ) {
F_2 ( L_34 ,
V_18 , V_120 ) ;
V_56 -> V_57 = V_120 ;
goto V_86;
}
V_120 = F_97 ( V_3 -> V_8 , V_4 ,
V_91 ) ;
if ( F_59 ( V_120 ) ) {
F_2 ( L_32 ,
V_18 , V_120 ) ;
V_56 -> V_57 = V_120 ;
goto V_86;
}
V_76 = 0 ;
V_77 = V_44 ;
} else if ( ( V_76 & ( V_124 - 1 ) ) ||
( V_77 & ( V_124 - 1 ) ) ) {
unsigned int V_148 = V_76 ;
V_120 = F_79 ( V_78 [ V_69 ] , V_3 , V_76 ,
V_77 , false ) ;
V_76 = F_74 ( V_76 , V_124 ) ;
V_77 = F_80 ( V_148 + V_77 , V_124 )
- V_76 ;
}
V_20 = F_30 ( V_20 , V_104 -> V_78 . V_84 - V_69 , V_145 ,
V_4 , V_78 [ V_69 ] , V_3 ,
F_60 , V_28 ,
V_76 , V_77 ) ;
if ( F_50 ( V_20 ) ) {
V_56 -> V_57 = F_51 ( V_20 ) ;
V_20 = NULL ;
goto V_86;
}
V_39 += V_138 ;
V_75 -= V_138 ;
V_4 += V_91 ;
V_137 = V_4 ;
V_72 -= V_91 ;
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
V_104 -> V_94 . V_75 = V_104 -> args . V_75 ;
V_86:
F_46 ( V_3 ) ;
F_46 ( V_71 ) ;
F_24 ( V_145 , V_20 ) ;
F_22 ( V_28 ) ;
return V_96 ;
V_142:
F_46 ( V_3 ) ;
F_46 ( V_71 ) ;
F_21 ( V_28 ) ;
return V_97 ;
}
static void
F_98 ( struct V_98 * V_99 , struct V_149 * V_150 )
{
int V_69 ;
struct V_2 * V_3 ;
F_99 ( & V_99 -> V_151 ) ;
for ( V_69 = 0 ; V_69 < V_152 ; V_69 ++ ) {
while ( ! F_100 ( & V_99 -> V_153 [ V_69 ] ) ) {
V_3 = F_101 ( & V_99 -> V_153 [ V_69 ] ,
struct V_2 ,
V_154 ) ;
F_102 ( & V_3 -> V_154 ) ;
F_46 ( V_3 ) ;
}
}
F_103 ( & V_99 -> V_151 ) ;
}
static void
F_104 ( struct V_155 * V_156 )
{
struct V_157 * V_158 , * V_139 ;
struct V_101 * V_102 , * V_159 ;
F_105 (pos, temp, &marks->im_tree.mtt_stub, it_link) {
F_102 ( & V_158 -> V_160 ) ;
F_21 ( V_158 ) ;
}
F_105 (se, stemp, &marks->im_extents, bse_node) {
F_102 ( & V_102 -> V_161 ) ;
F_21 ( V_102 ) ;
}
return;
}
static void F_106 ( struct V_162 * V_163 )
{
struct V_98 * V_99 = F_107 ( V_163 ) ;
F_2 ( L_11 , V_18 ) ;
F_98 ( V_99 , NULL ) ;
F_104 ( & V_99 -> V_106 ) ;
F_21 ( V_99 ) ;
}
static struct V_162 * F_108 ( struct V_92 * V_92 ,
T_8 V_164 )
{
struct V_98 * V_99 ;
F_2 ( L_11 , V_18 ) ;
V_99 = F_109 ( sizeof( * V_99 ) , V_164 ) ;
if ( ! V_99 )
return NULL ;
F_110 ( & V_99 -> V_151 ) ;
F_111 ( & V_99 -> V_153 [ 0 ] ) ;
F_111 ( & V_99 -> V_153 [ 1 ] ) ;
F_111 ( & V_99 -> V_165 ) ;
F_111 ( & V_99 -> V_166 ) ;
V_99 -> V_167 = 0 ;
V_99 -> V_168 = F_93 ( V_92 ) -> V_141 >> V_41 ;
F_112 ( & V_99 -> V_106 , V_99 -> V_168 ) ;
return & V_99 -> V_169 ;
}
static void F_113 ( struct V_170 * V_59 )
{
F_2 ( L_11 , V_18 ) ;
F_21 ( V_59 ) ;
}
static struct V_170 * F_114 ( struct V_162 * V_163 ,
struct V_171 * V_172 ,
T_8 V_164 )
{
struct V_170 * V_59 ;
int V_173 ;
F_2 ( L_11 , V_18 ) ;
V_59 = F_109 ( sizeof( * V_59 ) , V_164 ) ;
if ( ! V_59 )
return F_31 ( - V_43 ) ;
V_173 = F_115 ( V_163 , V_172 , V_164 ) ;
if ( V_173 ) {
F_21 ( V_59 ) ;
return F_31 ( V_173 ) ;
}
return V_59 ;
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
struct V_162 * V_163 = F_119 ( V_179 -> args . V_92 ) -> V_180 ;
F_2 ( L_11 , V_18 ) ;
F_120 ( F_107 ( V_163 ) , & V_179 -> args , V_179 -> V_94 . V_173 ) ;
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
struct V_1 * * V_78 = NULL ;
int V_69 , V_196 ;
V_194 = V_188 -> V_197 -> V_198 -> V_199 . V_194 ;
V_195 = F_124 ( 0 , V_194 ) ;
F_2 ( L_35 ,
V_18 , V_194 , V_195 ) ;
V_184 = F_15 ( sizeof( * V_184 ) , V_13 ) ;
if ( ! V_184 ) {
F_2 ( L_36 , V_18 ) ;
return F_31 ( - V_43 ) ;
}
V_78 = F_109 ( V_195 * sizeof( struct V_1 * ) , V_13 ) ;
if ( V_78 == NULL ) {
F_21 ( V_184 ) ;
return F_31 ( - V_43 ) ;
}
for ( V_69 = 0 ; V_69 < V_195 ; V_69 ++ ) {
V_78 [ V_69 ] = F_72 ( V_13 ) ;
if ( ! V_78 [ V_69 ] ) {
V_12 = F_31 ( - V_43 ) ;
goto V_200;
}
}
memcpy ( & V_184 -> V_201 , V_192 , sizeof( * V_192 ) ) ;
V_184 -> V_202 = V_203 ;
V_184 -> V_78 = V_78 ;
V_184 -> V_80 = 0 ;
V_184 -> V_204 = V_129 * V_195 ;
V_184 -> V_205 = 0 ;
F_2 ( L_37 , V_18 , V_184 -> V_201 . V_11 ) ;
V_196 = F_125 ( V_188 , V_184 ) ;
F_2 ( L_38 , V_18 , V_196 ) ;
if ( V_196 ) {
V_12 = F_31 ( V_196 ) ;
goto V_200;
}
V_12 = F_126 ( V_188 , V_184 ) ;
V_200:
for ( V_69 = 0 ; V_69 < V_195 ; V_69 ++ )
F_78 ( V_78 [ V_69 ] ) ;
F_21 ( V_78 ) ;
F_21 ( V_184 ) ;
return V_12 ;
}
static int
F_127 ( struct V_187 * V_188 , const struct V_189 * V_190 )
{
struct V_181 * V_206 = NULL ;
struct V_207 * V_208 = NULL ;
struct V_183 * V_209 ;
F_128 ( V_210 ) ;
int V_173 , V_69 ;
F_2 ( L_11 , V_18 ) ;
if ( V_188 -> V_141 == 0 ) {
F_2 ( L_39 , V_18 ) ;
return - V_147 ;
}
V_206 = F_109 ( sizeof( struct V_181 ) , V_13 ) ;
if ( ! V_206 ) {
V_173 = - V_43 ;
goto V_211;
}
F_110 ( & V_206 -> V_212 ) ;
F_111 ( & V_206 -> V_213 ) ;
V_208 = F_15 ( sizeof( struct V_207 ) , V_13 ) ;
if ( ! V_208 ) {
V_173 = - V_43 ;
goto V_211;
}
V_208 -> V_95 = 0 ;
while ( ! V_208 -> V_95 ) {
V_173 = F_129 ( V_188 , V_190 , V_208 ) ;
if ( V_173 )
goto V_211;
F_2 ( L_40 ,
V_18 , V_208 -> V_214 , V_208 -> V_95 ) ;
for ( V_69 = 0 ; V_69 < V_208 -> V_214 ; V_69 ++ ) {
V_209 = F_123 ( V_188 , V_190 ,
& V_208 -> V_201 [ V_69 ] ) ;
if ( F_50 ( V_209 ) ) {
V_173 = F_51 ( V_209 ) ;
goto V_211;
}
F_99 ( & V_206 -> V_212 ) ;
F_130 ( & V_209 -> V_186 , & V_206 -> V_213 ) ;
F_103 ( & V_206 -> V_212 ) ;
}
}
F_2 ( L_41 , V_18 ) ;
V_188 -> V_215 = V_206 ;
V_216:
F_21 ( V_208 ) ;
return V_173 ;
V_211:
F_121 ( V_206 ) ;
goto V_216;
}
static int
F_131 ( struct V_187 * V_188 )
{
struct V_181 * V_206 = V_188 -> V_215 ;
F_2 ( L_11 , V_18 ) ;
F_121 ( V_206 ) ;
F_2 ( L_42 , V_18 ) ;
return 0 ;
}
static bool
F_132 ( struct V_217 * V_218 , unsigned int V_219 )
{
return F_94 ( V_218 -> V_220 , V_219 ) &&
F_94 ( V_218 -> V_221 , V_219 ) ;
}
static void
F_133 ( struct V_222 * V_223 , struct V_217 * V_218 )
{
if ( V_223 -> V_224 != NULL &&
! F_132 ( V_218 , V_124 ) )
F_134 ( V_223 ) ;
else
F_135 ( V_223 , V_218 ) ;
}
static bool
F_136 ( struct V_222 * V_223 , struct V_217 * V_225 ,
struct V_217 * V_218 )
{
if ( V_223 -> V_224 != NULL &&
! F_132 ( V_218 , V_124 ) )
return false ;
return F_137 ( V_223 , V_225 , V_218 ) ;
}
static T_7 F_138 ( struct V_92 * V_92 , T_6 V_226 )
{
struct V_227 * V_228 = V_92 -> V_132 ;
T_6 V_100 ;
V_100 = F_139 ( F_140 ( V_92 ) , V_44 ) ;
if ( V_100 != F_119 ( V_92 ) -> V_84 ) {
F_141 () ;
V_100 = F_142 ( & V_228 -> V_229 , V_226 + 1 , V_230 ) ;
F_143 () ;
}
if ( ! V_100 )
return F_140 ( V_92 ) - ( V_226 << V_81 ) ;
else
return ( V_100 - V_226 ) << V_81 ;
}
static void
F_144 ( struct V_222 * V_223 , struct V_217 * V_218 )
{
if ( V_223 -> V_224 != NULL &&
! F_132 ( V_218 , V_44 ) ) {
F_145 ( V_223 ) ;
} else {
T_7 V_231 ;
if ( V_223 -> V_224 == NULL )
V_231 = F_138 ( V_223 -> V_232 ,
V_218 -> V_233 ) ;
else
V_231 = F_146 ( V_223 -> V_224 ) ;
F_147 ( V_223 , V_218 , V_231 ) ;
}
}
static bool
F_148 ( struct V_222 * V_223 , struct V_217 * V_225 ,
struct V_217 * V_218 )
{
if ( V_223 -> V_224 != NULL &&
! F_132 ( V_218 , V_44 ) )
return false ;
return F_137 ( V_223 , V_225 , V_218 ) ;
}
static struct V_234 * F_149 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
struct V_234 * V_239 , * V_234 ;
V_239 = F_150 ( V_236 , V_240 ) ;
if ( V_239 == NULL )
return F_31 ( - V_241 ) ;
V_234 = F_151 ( V_239 , L_43 , NULL , V_238 ) ;
F_152 ( V_239 ) ;
return V_234 ;
}
static void F_153 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
if ( V_238 -> V_234 )
F_154 ( V_238 -> V_234 ) ;
}
static int F_155 ( struct V_242 * V_243 , unsigned long V_244 ,
void * V_245 )
{
struct V_235 * V_236 = V_245 ;
struct V_246 * V_246 = V_236 -> V_247 ;
struct V_248 * V_249 = F_156 ( V_246 , V_250 ) ;
struct V_234 * V_234 ;
int V_120 = 0 ;
if ( ! F_157 ( V_251 ) )
return 0 ;
if ( V_249 -> V_252 == NULL ) {
F_158 ( V_251 ) ;
return 0 ;
}
switch ( V_244 ) {
case V_253 :
V_234 = F_149 ( V_236 , V_249 -> V_252 ) ;
if ( F_50 ( V_234 ) ) {
V_120 = F_51 ( V_234 ) ;
break;
}
V_249 -> V_252 -> V_234 = V_234 ;
break;
case V_254 :
if ( V_249 -> V_252 -> V_234 )
F_153 ( V_236 , V_249 -> V_252 ) ;
break;
default:
V_120 = - V_255 ;
break;
}
F_158 ( V_251 ) ;
return V_120 ;
}
static struct V_234 * F_159 ( struct V_246 * V_246 ,
struct V_237 * V_238 )
{
struct V_235 * V_256 ;
struct V_234 * V_234 ;
V_256 = F_160 ( V_246 ) ;
if ( ! V_256 )
return NULL ;
V_234 = F_149 ( V_256 , V_238 ) ;
F_161 ( V_246 ) ;
return V_234 ;
}
static void F_162 ( struct V_246 * V_246 ,
struct V_237 * V_238 )
{
struct V_235 * V_256 ;
V_256 = F_160 ( V_246 ) ;
if ( V_256 ) {
F_153 ( V_256 , V_238 ) ;
F_161 ( V_246 ) ;
}
}
static int F_163 ( struct V_246 * V_246 )
{
struct V_248 * V_249 = F_156 ( V_246 , V_250 ) ;
struct V_234 * V_234 ;
F_164 ( & V_249 -> V_257 ) ;
V_249 -> V_252 = F_165 ( & V_258 , 0 ) ;
if ( F_50 ( V_249 -> V_252 ) )
return F_51 ( V_249 -> V_252 ) ;
V_234 = F_159 ( V_246 , V_249 -> V_252 ) ;
if ( F_50 ( V_234 ) ) {
F_166 ( V_249 -> V_252 ) ;
return F_51 ( V_234 ) ;
}
V_249 -> V_252 -> V_234 = V_234 ;
return 0 ;
}
static void F_167 ( struct V_246 * V_246 )
{
struct V_248 * V_249 = F_156 ( V_246 , V_250 ) ;
F_162 ( V_246 , V_249 -> V_252 ) ;
F_166 ( V_249 -> V_252 ) ;
V_249 -> V_252 = NULL ;
}
static int T_10 F_168 ( void )
{
int V_120 ;
F_2 ( L_44 , V_18 ) ;
V_120 = F_169 ( & V_259 ) ;
if ( V_120 )
goto V_86;
V_120 = F_170 ( & V_260 ) ;
if ( V_120 )
goto V_261;
V_120 = F_171 ( & V_262 ) ;
if ( V_120 )
goto V_263;
V_86:
return V_120 ;
V_263:
F_172 ( & V_260 ) ;
V_261:
F_173 ( & V_259 ) ;
return V_120 ;
}
static void T_11 F_174 ( void )
{
F_2 ( L_45 ,
V_18 ) ;
F_172 ( & V_260 ) ;
F_175 ( & V_262 ) ;
F_173 ( & V_259 ) ;
}
