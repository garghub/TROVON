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
if ( ! V_51 -> V_52 )
V_51 -> V_52 = - V_53 ;
F_37 ( V_51 -> V_54 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_29 ) ;
}
static void F_39 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_50 * V_59 ;
F_2 ( L_11 , V_18 ) ;
V_58 = F_20 ( V_56 , struct V_57 , V_60 . V_61 ) ;
V_59 = F_20 ( V_58 , struct V_50 , V_58 ) ;
F_40 ( V_59 ) ;
}
static void
F_41 ( void * V_11 , int V_62 )
{
struct V_50 * V_59 = V_11 ;
V_59 -> V_58 . V_63 = V_59 -> V_52 ;
F_42 ( & V_59 -> V_58 . V_60 . V_61 , F_39 ) ;
F_43 ( & V_59 -> V_58 . V_60 . V_61 ) ;
}
static enum V_64
F_44 ( struct V_50 * V_59 )
{
struct V_50 * V_51 = V_59 ;
int V_48 , V_65 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_66 = NULL ;
T_1 V_4 , V_67 = 0 ;
struct V_10 * V_29 ;
T_2 V_68 = V_59 -> args . V_40 ;
T_3 V_69 = V_59 -> args . V_70 ;
unsigned int V_71 , V_72 ;
struct V_1 * * V_73 = V_59 -> args . V_73 ;
int V_74 = V_59 -> args . V_75 >> V_76 ;
const bool V_77 = ( V_51 -> V_78 != NULL ) ;
F_2 ( L_16 , V_18 ,
V_59 -> V_79 . V_80 , V_68 ,
( unsigned int ) V_59 -> args . V_70 ) ;
V_29 = F_14 ( V_59 ) ;
if ( ! V_29 )
goto V_81;
V_29 -> V_19 = F_41 ;
V_4 = ( T_1 ) ( V_68 >> V_42 ) ;
for ( V_48 = V_74 ; V_48 < V_59 -> V_79 . V_80 ; V_48 ++ ) {
if ( ! V_67 ) {
F_45 ( V_3 ) ;
F_45 ( V_66 ) ;
V_20 = F_24 ( V_23 , V_20 ) ;
V_3 = F_46 ( F_47 ( V_51 -> V_54 ) ,
V_4 , & V_66 ) ;
if ( ! V_3 ) {
V_51 -> V_52 = - V_53 ;
goto V_82;
}
V_67 = V_3 -> V_83 -
( V_4 - V_3 -> V_35 ) ;
if ( V_66 ) {
T_1 V_84 = V_66 -> V_83 -
( V_4 - V_66 -> V_35 ) ;
V_67 = F_28 ( V_67 , V_84 ) ;
}
}
if ( V_77 ) {
V_71 = V_68 & ~ V_85 ;
if ( V_71 + V_69 > V_45 )
V_72 = V_45 - V_71 ;
else
V_72 = V_69 ;
V_68 += V_72 ;
V_69 -= V_72 ;
V_4 += ( V_71 >> V_42 ) ;
} else {
V_71 = 0 ;
V_72 = V_45 ;
}
V_65 = F_11 ( V_3 , V_4 ) ;
if ( V_65 && ! V_66 ) {
V_20 = F_24 ( V_23 , V_20 ) ;
F_2 ( L_17 , V_18 ) ;
F_48 ( V_73 [ V_48 ] , V_71 , V_72 ) ;
F_1 ( V_73 [ V_48 ] ) ;
F_36 ( V_73 [ V_48 ] ) ;
} else {
struct V_2 * V_86 ;
V_86 = ( V_65 && V_66 ) ? V_66 : V_3 ;
V_20 = F_30 ( V_20 ,
V_59 -> V_79 . V_80 - V_48 ,
V_23 ,
V_4 , V_73 [ V_48 ] , V_86 ,
F_34 , V_29 ,
V_71 , V_72 ) ;
if ( F_49 ( V_20 ) ) {
V_51 -> V_52 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_82;
}
}
V_4 += ( V_72 >> V_42 ) ;
V_67 -= V_87 ;
}
if ( ( V_4 << V_42 ) >= V_51 -> V_88 -> V_89 ) {
V_59 -> V_90 . V_91 = 1 ;
V_59 -> V_90 . V_70 = V_51 -> V_88 -> V_89 - V_59 -> args . V_40 ;
} else {
V_59 -> V_90 . V_70 = ( V_4 << V_42 ) - V_59 -> args . V_40 ;
}
V_82:
F_45 ( V_3 ) ;
F_45 ( V_66 ) ;
F_24 ( V_23 , V_20 ) ;
F_22 ( V_29 ) ;
return V_92 ;
V_81:
F_2 ( L_18 ) ;
return V_93 ;
}
static void F_51 ( struct V_94 * V_95 ,
T_4 V_40 , T_5 V_70 )
{
T_1 V_4 , V_96 ;
struct V_2 * V_3 ;
struct V_97 * V_98 ;
F_2 ( L_19 , V_18 , V_40 , V_70 ) ;
if ( V_70 == 0 )
return;
V_4 = ( V_40 & ( long ) ( V_85 ) ) >> V_42 ;
V_96 = ( V_40 + V_70 + V_45 - 1 ) & ( long ) ( V_85 ) ;
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
struct V_50 * V_51 = V_29 -> V_11 ;
if ( ! V_51 -> V_52 )
V_51 -> V_52 = - V_53 ;
F_37 ( V_51 -> V_54 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_29 ) ;
}
static void F_59 ( struct V_20 * V_20 , int V_28 )
{
struct V_10 * V_29 = V_20 -> V_22 ;
const int V_99 = F_60 ( V_100 , & V_20 -> V_101 ) ;
struct V_50 * V_51 = V_29 -> V_11 ;
if ( ! V_99 ) {
if ( ! V_51 -> V_52 )
V_51 -> V_52 = - V_53 ;
F_37 ( V_51 -> V_54 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_29 ) ;
}
static void F_61 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_50 * V_59 ;
F_2 ( L_11 , V_18 ) ;
V_58 = F_20 ( V_56 , struct V_57 , V_60 . V_61 ) ;
V_59 = F_20 ( V_58 , struct V_50 , V_58 ) ;
if ( F_62 ( ! V_59 -> V_52 ) ) {
F_51 ( F_47 ( V_59 -> V_54 ) ,
V_59 -> args . V_40 , V_59 -> args . V_70 ) ;
}
F_63 ( V_59 ) ;
}
static void F_64 ( void * V_11 , int V_102 )
{
struct V_50 * V_59 = V_11 ;
if ( F_58 ( V_59 -> V_52 ) ) {
F_65 ( & F_47 ( V_59 -> V_54 ) -> V_103 ,
V_102 ) ;
}
V_59 -> V_58 . V_63 = V_59 -> V_52 ;
V_59 -> V_104 . V_105 = V_106 ;
F_42 ( & V_59 -> V_58 . V_60 . V_61 , F_61 ) ;
F_43 ( & V_59 -> V_58 . V_60 . V_61 ) ;
}
static void F_66 ( void )
{
return;
}
static void
F_67 ( struct V_107 * V_108 , T_1 V_4 , struct V_2 * V_3 )
{
F_2 ( L_20 , V_18 , V_3 ) ;
F_68 ( V_108 ) ;
V_108 -> V_109 = V_3 -> V_38 ;
V_108 -> V_110 = ( V_4 - V_3 -> V_35 + V_3 -> V_36 ) >>
( V_3 -> V_38 -> V_111 -> V_112 - V_42 ) ;
F_2 ( L_21 ,
V_18 , ( unsigned long long ) V_4 , ( long ) V_108 -> V_110 ,
V_108 -> V_113 ) ;
return;
}
static void
F_69 ( struct V_20 * V_20 , int error )
{
struct V_46 * V_47 = V_20 -> V_114 + V_20 -> V_115 - 1 ;
struct V_1 * V_1 = V_47 -> V_49 ;
F_70 ( V_1 ) ;
}
static int
F_71 ( struct V_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_40 , unsigned int V_41 )
{
struct V_20 * V_20 ;
struct V_1 * V_116 ;
T_1 V_4 ;
char * V_117 , * V_118 ;
int V_119 = 0 ;
F_2 ( L_22 , V_18 , V_40 , V_41 ) ;
V_116 = F_72 ( V_13 | V_120 ) ;
if ( V_116 == NULL )
return - V_44 ;
V_20 = F_29 ( V_31 , 1 ) ;
if ( V_20 == NULL )
return - V_44 ;
V_4 = ( V_1 -> V_121 << V_122 ) +
( V_40 / V_123 ) ;
V_20 -> V_24 . V_26 = V_4 - V_3 -> V_35 + V_3 -> V_36 ;
V_20 -> V_37 = V_3 -> V_38 ;
V_20 -> V_39 = F_69 ;
F_73 ( V_116 ) ;
if ( F_32 ( V_20 , V_116 ,
V_123 , F_74 ( V_40 , V_123 ) ) == 0 ) {
F_70 ( V_116 ) ;
F_38 ( V_20 ) ;
return - V_53 ;
}
F_25 ( V_23 , V_20 ) ;
F_75 ( V_116 ) ;
if ( F_58 ( ! F_60 ( V_100 , & V_20 -> V_101 ) ) ) {
V_119 = - V_53 ;
} else {
V_117 = F_76 ( V_1 ) ;
V_118 = F_76 ( V_116 ) ;
memcpy ( V_117 + V_40 , V_118 + V_40 , V_41 ) ;
F_77 ( V_118 ) ;
F_77 ( V_117 ) ;
}
F_78 ( V_116 ) ;
F_38 ( V_20 ) ;
return V_119 ;
}
static int
F_79 ( struct V_1 * V_1 , struct V_2 * V_3 ,
unsigned int V_124 , unsigned int V_125 ,
bool V_126 )
{
int V_119 = 0 ;
unsigned int V_127 , V_96 ;
if ( V_126 ) {
V_127 = 0 ;
V_96 = V_45 ;
} else {
V_127 = F_74 ( V_124 , V_123 ) ;
V_96 = F_80 ( V_124 + V_125 , V_123 ) ;
}
F_2 ( L_23 , V_18 , V_124 , V_125 ) ;
if ( ! V_3 ) {
F_81 ( V_1 , V_127 , V_124 ,
V_124 + V_125 , V_96 ) ;
if ( V_127 == 0 && V_96 == V_45 &&
F_82 ( V_1 ) ) {
F_36 ( V_1 ) ;
F_70 ( V_1 ) ;
}
return V_119 ;
}
if ( V_127 != V_124 )
V_119 = F_71 ( V_1 , V_3 , V_127 , V_124 - V_127 ) ;
if ( ! V_119 && ( V_124 + V_125 < V_96 ) )
V_119 = F_71 ( V_1 , V_3 , V_124 + V_125 ,
V_96 - V_124 - V_125 ) ;
return V_119 ;
}
static int
F_83 ( struct V_1 * V_1 , struct V_2 * V_66 )
{
struct V_107 * V_108 = NULL ;
int V_119 = 0 ;
T_1 V_4 ;
F_2 ( L_24 , V_18 , V_1 ) ;
F_52 ( F_4 ( V_1 ) ) ;
if ( ! V_66 ) {
F_48 ( V_1 , 0 , V_128 ) ;
F_36 ( V_1 ) ;
goto V_129;
}
V_108 = F_84 ( V_1 , V_45 , 0 ) ;
if ( ! V_108 ) {
V_119 = - V_44 ;
goto V_129;
}
V_4 = ( T_1 ) V_1 -> V_121 << V_122 ;
F_67 ( V_108 , V_4 , V_66 ) ;
if ( ! F_85 ( V_108 ) )
V_119 = F_86 ( V_108 ) ;
if ( V_119 )
goto V_129;
F_36 ( V_1 ) ;
V_129:
if ( V_108 )
F_87 ( V_108 ) ;
if ( V_119 ) {
F_66 () ;
}
return V_119 ;
}
static struct V_1 *
F_88 ( struct V_88 * V_88 , T_6 V_121 ,
struct V_2 * V_66 )
{
struct V_1 * V_1 ;
int V_130 = 0 ;
V_1 = F_89 ( V_88 -> V_131 , V_121 ) ;
if ( V_1 )
goto V_132;
V_1 = F_90 ( V_88 -> V_131 , V_121 , V_13 ) ;
if ( F_58 ( ! V_1 ) ) {
F_2 ( L_25 , V_18 ) ;
return F_31 ( - V_44 ) ;
}
V_130 = 1 ;
V_132:
if ( F_6 ( V_1 ) || F_9 ( V_1 ) ) {
F_1 ( V_1 ) ;
if ( V_130 )
F_70 ( V_1 ) ;
F_57 ( V_1 ) ;
return NULL ;
}
if ( ! V_130 ) {
F_73 ( V_1 ) ;
V_130 = 1 ;
goto V_132;
}
if ( ! F_4 ( V_1 ) ) {
F_83 ( V_1 , V_66 ) ;
}
F_91 ( V_1 ) ;
F_70 ( V_1 ) ;
return V_1 ;
}
static enum V_64
F_92 ( struct V_50 * V_51 , int V_133 )
{
int V_48 , V_119 , V_134 , V_74 , V_135 = 0 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_66 = NULL ;
T_1 V_4 , V_136 = 0 , V_67 = 0 ;
struct V_10 * V_29 = NULL ;
T_2 V_40 = V_51 -> args . V_40 ;
T_3 V_70 = V_51 -> args . V_70 ;
unsigned int V_71 , V_72 , V_137 ;
struct V_1 * * V_73 = V_51 -> args . V_73 ;
struct V_1 * V_1 ;
T_6 V_121 ;
T_7 V_138 ;
int V_139 =
F_93 ( V_51 -> V_88 ) -> V_140 >> V_76 ;
F_2 ( L_26 , V_18 , V_70 , V_40 ) ;
if ( V_51 -> V_78 != NULL &&
( ! F_94 ( V_40 , F_93 ( V_51 -> V_88 ) -> V_140 ) ||
! F_94 ( V_70 , F_93 ( V_51 -> V_88 ) -> V_140 ) ) ) {
F_2 ( L_27 ) ;
goto V_141;
}
V_29 = F_14 ( V_51 ) ;
if ( ! V_29 )
goto V_141;
V_29 -> V_19 = F_64 ;
V_4 = ( T_1 ) ( ( V_40 & ( long ) V_85 ) >> V_42 ) ;
V_3 = F_46 ( F_47 ( V_51 -> V_54 ) , V_4 , & V_66 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
F_2 ( L_28 , V_18 ) ;
goto V_141;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_62 ( ! F_95 ( V_3 -> V_8 ) ) )
V_29 -> V_15 ++ ;
else
goto V_141;
V_138 = V_40 >> V_76 ;
V_134 = F_96 ( V_138 , V_139 ) ;
V_4 = ( T_1 ) ( ( ( V_40 - V_134 * V_45 ) &
( long ) V_85 ) >> V_42 ) ;
V_67 = V_3 -> V_83 - ( V_4 - V_3 -> V_35 ) ;
V_142:
F_2 ( L_29 , V_18 , V_134 ) ;
for (; V_134 > 0 ; V_134 -- ) {
if ( F_12 ( V_3 -> V_8 , V_4 ) ) {
F_2 ( L_30 ,
( unsigned long long ) V_4 ) ;
goto V_143;
}
V_121 = V_4 >> V_122 ;
F_2 ( L_31 ,
V_18 , V_134 , V_121 ,
( unsigned long long ) V_4 ) ;
V_1 = F_88 ( V_51 -> V_88 , V_121 ,
V_66 ) ;
if ( F_58 ( F_49 ( V_1 ) ) ) {
V_51 -> V_52 = F_50 ( V_1 ) ;
goto V_82;
} else if ( V_1 == NULL )
goto V_143;
V_119 = F_97 ( V_3 -> V_8 , V_4 ,
V_87 ) ;
if ( F_58 ( V_119 ) ) {
F_2 ( L_32 ,
V_18 , V_119 ) ;
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
V_51 -> V_52 = V_119 ;
goto V_82;
}
if ( F_62 ( ! F_95 ( V_3 -> V_8 ) ) )
V_29 -> V_15 ++ ;
else {
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
V_51 -> V_52 = - V_44 ;
goto V_82;
}
F_51 ( F_47 ( V_51 -> V_54 ) ,
V_1 -> V_121 << V_76 ,
V_45 ) ;
V_20 = F_33 ( V_20 , V_134 , V_144 ,
V_4 , V_1 , V_3 ,
F_55 , V_29 ) ;
if ( F_49 ( V_20 ) ) {
V_51 -> V_52 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_82;
}
V_143:
V_4 += V_87 ;
V_67 -= V_87 ;
}
if ( V_135 )
goto V_145;
}
V_20 = F_24 ( V_144 , V_20 ) ;
V_74 = V_51 -> args . V_75 >> V_76 ;
for ( V_48 = V_74 ; V_48 < V_51 -> V_79 . V_80 ; V_48 ++ ) {
if ( ! V_67 ) {
F_45 ( V_3 ) ;
F_45 ( V_66 ) ;
V_20 = F_24 ( V_144 , V_20 ) ;
V_3 = F_46 ( F_47 ( V_51 -> V_54 ) ,
V_4 , & V_66 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
V_51 -> V_52 = - V_146 ;
goto V_82;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_62 ( ! F_95 (
V_3 -> V_8 ) ) )
V_29 -> V_15 ++ ;
else {
V_51 -> V_52 = - V_44 ;
goto V_82;
}
}
V_67 = V_3 -> V_83 -
( V_4 - V_3 -> V_35 ) ;
}
F_2 ( L_33 , V_18 , V_40 , V_70 ) ;
V_71 = V_40 & ~ V_85 ;
if ( V_71 + V_70 > V_45 )
V_72 = V_45 - V_71 ;
else
V_72 = V_70 ;
V_137 = V_72 ;
if ( V_3 -> V_5 == V_7 &&
! F_12 ( V_3 -> V_8 , V_4 ) ) {
V_119 = F_79 ( V_73 [ V_48 ] , V_66 ,
V_71 , V_72 , true ) ;
if ( V_119 ) {
F_2 ( L_34 ,
V_18 , V_119 ) ;
V_51 -> V_52 = V_119 ;
goto V_82;
}
V_119 = F_97 ( V_3 -> V_8 , V_4 ,
V_87 ) ;
if ( F_58 ( V_119 ) ) {
F_2 ( L_32 ,
V_18 , V_119 ) ;
V_51 -> V_52 = V_119 ;
goto V_82;
}
V_71 = 0 ;
V_72 = V_45 ;
} else if ( ( V_71 & ( V_123 - 1 ) ) ||
( V_72 & ( V_123 - 1 ) ) ) {
unsigned int V_147 = V_71 ;
V_119 = F_79 ( V_73 [ V_48 ] , V_3 , V_71 ,
V_72 , false ) ;
V_71 = F_74 ( V_71 , V_123 ) ;
V_72 = F_80 ( V_147 + V_72 , V_123 )
- V_71 ;
}
V_20 = F_30 ( V_20 , V_51 -> V_79 . V_80 - V_48 ,
V_144 ,
V_4 , V_73 [ V_48 ] , V_3 ,
F_59 , V_29 ,
V_71 , V_72 ) ;
if ( F_49 ( V_20 ) ) {
V_51 -> V_52 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_82;
}
V_40 += V_137 ;
V_70 -= V_137 ;
V_4 += V_87 ;
V_136 = V_4 ;
V_67 -= V_87 ;
}
if ( V_3 -> V_5 == V_7 ) {
V_20 = F_24 ( V_144 , V_20 ) ;
V_138 = V_136 >> V_122 ;
V_134 = V_139 - F_96 ( V_138 , V_139 ) ;
if ( V_134 < V_139 ) {
V_135 = 1 ;
goto V_142;
}
}
V_145:
V_51 -> V_90 . V_70 = V_51 -> args . V_70 ;
V_82:
F_45 ( V_3 ) ;
F_45 ( V_66 ) ;
F_24 ( V_144 , V_20 ) ;
F_22 ( V_29 ) ;
return V_92 ;
V_141:
F_45 ( V_3 ) ;
F_45 ( V_66 ) ;
F_21 ( V_29 ) ;
return V_93 ;
}
static void
F_98 ( struct V_94 * V_95 , struct V_148 * V_149 )
{
int V_48 ;
struct V_2 * V_3 ;
F_99 ( & V_95 -> V_150 ) ;
for ( V_48 = 0 ; V_48 < V_151 ; V_48 ++ ) {
while ( ! F_100 ( & V_95 -> V_152 [ V_48 ] ) ) {
V_3 = F_101 ( & V_95 -> V_152 [ V_48 ] ,
struct V_2 ,
V_153 ) ;
F_102 ( & V_3 -> V_153 ) ;
F_45 ( V_3 ) ;
}
}
F_103 ( & V_95 -> V_150 ) ;
}
static void
F_104 ( struct V_154 * V_155 )
{
struct V_156 * V_157 , * V_138 ;
struct V_97 * V_98 , * V_158 ;
F_105 (pos, temp, &marks->im_tree.mtt_stub, it_link) {
F_102 ( & V_157 -> V_159 ) ;
F_21 ( V_157 ) ;
}
F_105 (se, stemp, &marks->im_extents, bse_node) {
F_102 ( & V_98 -> V_160 ) ;
F_21 ( V_98 ) ;
}
return;
}
static void F_106 ( struct V_161 * V_162 )
{
struct V_94 * V_95 = F_107 ( V_162 ) ;
F_2 ( L_11 , V_18 ) ;
F_98 ( V_95 , NULL ) ;
F_104 ( & V_95 -> V_103 ) ;
F_21 ( V_95 ) ;
}
static struct V_161 * F_108 ( struct V_88 * V_88 ,
T_8 V_163 )
{
struct V_94 * V_95 ;
F_2 ( L_11 , V_18 ) ;
V_95 = F_109 ( sizeof( * V_95 ) , V_163 ) ;
if ( ! V_95 )
return NULL ;
F_110 ( & V_95 -> V_150 ) ;
F_111 ( & V_95 -> V_152 [ 0 ] ) ;
F_111 ( & V_95 -> V_152 [ 1 ] ) ;
F_111 ( & V_95 -> V_164 ) ;
F_111 ( & V_95 -> V_165 ) ;
V_95 -> V_166 = 0 ;
V_95 -> V_167 = F_93 ( V_88 ) -> V_140 >> V_42 ;
F_112 ( & V_95 -> V_103 , V_95 -> V_167 ) ;
return & V_95 -> V_168 ;
}
static void F_113 ( struct V_169 * V_54 )
{
F_2 ( L_11 , V_18 ) ;
F_21 ( V_54 ) ;
}
static struct V_169 * F_114 ( struct V_161 * V_162 ,
struct V_170 * V_171 ,
T_8 V_163 )
{
struct V_169 * V_54 ;
int V_172 ;
F_2 ( L_11 , V_18 ) ;
V_54 = F_109 ( sizeof( * V_54 ) , V_163 ) ;
if ( ! V_54 )
return F_31 ( - V_44 ) ;
V_172 = F_115 ( V_162 , V_171 , V_163 ) ;
if ( V_172 ) {
F_21 ( V_54 ) ;
return F_31 ( V_172 ) ;
}
return V_54 ;
}
static void
F_116 ( struct V_161 * V_162 , struct V_173 * V_174 ,
const struct V_175 * V_176 )
{
F_2 ( L_11 , V_18 ) ;
F_117 ( F_107 ( V_162 ) , V_174 , V_176 ) ;
}
static void
F_118 ( struct V_177 * V_178 )
{
struct V_161 * V_162 = F_119 ( V_178 -> args . V_88 ) -> V_179 ;
F_2 ( L_11 , V_18 ) ;
F_120 ( F_107 ( V_162 ) , & V_178 -> args , V_178 -> V_90 . V_172 ) ;
}
static void F_121 ( struct V_180 * V_181 )
{
if ( V_181 ) {
struct V_182 * V_183 , * V_184 ;
F_105 (dev, tmp, &mid->bm_devlist, bm_node) {
F_102 ( & V_183 -> V_185 ) ;
F_122 ( V_183 ) ;
}
F_21 ( V_181 ) ;
}
}
static struct V_182 *
F_123 ( struct V_186 * V_187 , const struct V_188 * V_189 ,
struct V_190 * V_191 )
{
struct V_192 * V_183 ;
struct V_182 * V_12 ;
T_9 V_193 ;
int V_194 ;
struct V_1 * * V_73 = NULL ;
int V_48 , V_195 ;
V_193 = V_187 -> V_196 -> V_197 -> V_198 . V_193 ;
V_194 = F_124 ( 0 , V_193 ) ;
F_2 ( L_35 ,
V_18 , V_193 , V_194 ) ;
V_183 = F_15 ( sizeof( * V_183 ) , V_13 ) ;
if ( ! V_183 ) {
F_2 ( L_36 , V_18 ) ;
return F_31 ( - V_44 ) ;
}
V_73 = F_125 ( V_194 , sizeof( struct V_1 * ) , V_13 ) ;
if ( V_73 == NULL ) {
F_21 ( V_183 ) ;
return F_31 ( - V_44 ) ;
}
for ( V_48 = 0 ; V_48 < V_194 ; V_48 ++ ) {
V_73 [ V_48 ] = F_72 ( V_13 ) ;
if ( ! V_73 [ V_48 ] ) {
V_12 = F_31 ( - V_44 ) ;
goto V_199;
}
}
memcpy ( & V_183 -> V_200 , V_191 , sizeof( * V_191 ) ) ;
V_183 -> V_201 = V_202 ;
V_183 -> V_73 = V_73 ;
V_183 -> V_75 = 0 ;
V_183 -> V_203 = V_128 * V_194 ;
V_183 -> V_204 = 0 ;
V_183 -> V_205 = V_193 - V_206 ;
F_2 ( L_37 , V_18 , V_183 -> V_200 . V_11 ) ;
V_195 = F_126 ( V_187 , V_183 , NULL ) ;
F_2 ( L_38 , V_18 , V_195 ) ;
if ( V_195 ) {
V_12 = F_31 ( V_195 ) ;
goto V_199;
}
V_12 = F_127 ( V_187 , V_183 ) ;
V_199:
for ( V_48 = 0 ; V_48 < V_194 ; V_48 ++ )
F_78 ( V_73 [ V_48 ] ) ;
F_21 ( V_73 ) ;
F_21 ( V_183 ) ;
return V_12 ;
}
static int
F_128 ( struct V_186 * V_187 , const struct V_188 * V_189 )
{
struct V_180 * V_207 = NULL ;
struct V_208 * V_209 = NULL ;
struct V_182 * V_210 ;
F_129 ( V_211 ) ;
int V_172 , V_48 ;
F_2 ( L_11 , V_18 ) ;
if ( V_187 -> V_140 == 0 ) {
F_2 ( L_39 , V_18 ) ;
return - V_146 ;
}
V_207 = F_109 ( sizeof( struct V_180 ) , V_13 ) ;
if ( ! V_207 ) {
V_172 = - V_44 ;
goto V_212;
}
F_110 ( & V_207 -> V_213 ) ;
F_111 ( & V_207 -> V_214 ) ;
V_209 = F_15 ( sizeof( struct V_208 ) , V_13 ) ;
if ( ! V_209 ) {
V_172 = - V_44 ;
goto V_212;
}
V_209 -> V_91 = 0 ;
while ( ! V_209 -> V_91 ) {
V_172 = F_130 ( V_187 , V_189 , V_209 ) ;
if ( V_172 )
goto V_212;
F_2 ( L_40 ,
V_18 , V_209 -> V_215 , V_209 -> V_91 ) ;
for ( V_48 = 0 ; V_48 < V_209 -> V_215 ; V_48 ++ ) {
V_210 = F_123 ( V_187 , V_189 ,
& V_209 -> V_200 [ V_48 ] ) ;
if ( F_49 ( V_210 ) ) {
V_172 = F_50 ( V_210 ) ;
goto V_212;
}
F_99 ( & V_207 -> V_213 ) ;
F_131 ( & V_210 -> V_185 , & V_207 -> V_214 ) ;
F_103 ( & V_207 -> V_213 ) ;
}
}
F_2 ( L_41 , V_18 ) ;
V_187 -> V_216 = V_207 ;
V_217:
F_21 ( V_209 ) ;
return V_172 ;
V_212:
F_121 ( V_207 ) ;
goto V_217;
}
static int
F_132 ( struct V_186 * V_187 )
{
struct V_180 * V_207 = V_187 -> V_216 ;
F_2 ( L_11 , V_18 ) ;
F_121 ( V_207 ) ;
F_2 ( L_42 , V_18 ) ;
return 0 ;
}
static bool
F_133 ( struct V_218 * V_219 , unsigned int V_220 )
{
return F_94 ( V_219 -> V_221 , V_220 ) &&
F_94 ( V_219 -> V_222 , V_220 ) ;
}
static void
F_134 ( struct V_223 * V_224 , struct V_218 * V_219 )
{
if ( V_224 -> V_225 != NULL &&
! F_133 ( V_219 , V_123 ) )
F_135 ( V_224 ) ;
else
F_136 ( V_224 , V_219 ) ;
}
static T_3
F_137 ( struct V_223 * V_224 , struct V_218 * V_226 ,
struct V_218 * V_219 )
{
if ( V_224 -> V_225 != NULL &&
! F_133 ( V_219 , V_123 ) )
return 0 ;
return F_138 ( V_224 , V_226 , V_219 ) ;
}
static T_7 F_139 ( struct V_88 * V_88 , T_6 V_227 )
{
struct V_228 * V_229 = V_88 -> V_131 ;
T_6 V_96 ;
V_96 = F_140 ( F_141 ( V_88 ) , V_45 ) ;
if ( V_96 != F_119 ( V_88 ) -> V_80 ) {
F_142 () ;
V_96 = F_143 ( V_229 , V_227 + 1 , V_230 ) ;
F_144 () ;
}
if ( ! V_96 )
return F_141 ( V_88 ) - ( V_227 << V_76 ) ;
else
return ( V_96 - V_227 ) << V_76 ;
}
static void
F_145 ( struct V_223 * V_224 , struct V_218 * V_219 )
{
if ( V_224 -> V_225 != NULL &&
! F_133 ( V_219 , V_45 ) ) {
F_146 ( V_224 ) ;
} else {
T_7 V_231 ;
if ( V_224 -> V_225 == NULL )
V_231 = F_139 ( V_224 -> V_232 ,
V_219 -> V_233 ) ;
else
V_231 = F_147 ( V_224 -> V_225 ) ;
F_148 ( V_224 , V_219 , V_231 ) ;
}
}
static T_3
F_149 ( struct V_223 * V_224 , struct V_218 * V_226 ,
struct V_218 * V_219 )
{
if ( V_224 -> V_225 != NULL &&
! F_133 ( V_219 , V_45 ) )
return 0 ;
return F_138 ( V_224 , V_226 , V_219 ) ;
}
static struct V_234 * F_150 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
struct V_234 * V_239 , * V_234 ;
V_239 = F_151 ( V_236 , V_240 ) ;
if ( V_239 == NULL )
return F_31 ( - V_241 ) ;
V_234 = F_152 ( V_239 , L_43 , NULL , V_238 ) ;
F_153 ( V_239 ) ;
return V_234 ;
}
static void F_154 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
if ( V_238 -> V_234 )
F_155 ( V_238 -> V_234 ) ;
}
static int F_156 ( struct V_242 * V_243 , unsigned long V_244 ,
void * V_245 )
{
struct V_235 * V_236 = V_245 ;
struct V_246 * V_246 = V_236 -> V_247 ;
struct V_248 * V_249 = F_157 ( V_246 , V_250 ) ;
struct V_234 * V_234 ;
int V_119 = 0 ;
if ( ! F_158 ( V_251 ) )
return 0 ;
if ( V_249 -> V_252 == NULL ) {
F_159 ( V_251 ) ;
return 0 ;
}
switch ( V_244 ) {
case V_253 :
V_234 = F_150 ( V_236 , V_249 -> V_252 ) ;
if ( F_49 ( V_234 ) ) {
V_119 = F_50 ( V_234 ) ;
break;
}
V_249 -> V_252 -> V_234 = V_234 ;
break;
case V_254 :
if ( V_249 -> V_252 -> V_234 )
F_154 ( V_236 , V_249 -> V_252 ) ;
break;
default:
V_119 = - V_255 ;
break;
}
F_159 ( V_251 ) ;
return V_119 ;
}
static struct V_234 * F_160 ( struct V_246 * V_246 ,
struct V_237 * V_238 )
{
struct V_235 * V_256 ;
struct V_234 * V_234 ;
V_256 = F_161 ( V_246 ) ;
if ( ! V_256 )
return NULL ;
V_234 = F_150 ( V_256 , V_238 ) ;
F_162 ( V_246 ) ;
return V_234 ;
}
static void F_163 ( struct V_246 * V_246 ,
struct V_237 * V_238 )
{
struct V_235 * V_256 ;
V_256 = F_161 ( V_246 ) ;
if ( V_256 ) {
F_154 ( V_256 , V_238 ) ;
F_162 ( V_246 ) ;
}
}
static int F_164 ( struct V_246 * V_246 )
{
struct V_248 * V_249 = F_157 ( V_246 , V_250 ) ;
struct V_234 * V_234 ;
F_165 ( & V_249 -> V_257 ) ;
V_249 -> V_252 = F_166 ( & V_258 , 0 ) ;
if ( F_49 ( V_249 -> V_252 ) )
return F_50 ( V_249 -> V_252 ) ;
V_234 = F_160 ( V_246 , V_249 -> V_252 ) ;
if ( F_49 ( V_234 ) ) {
F_167 ( V_249 -> V_252 ) ;
return F_50 ( V_234 ) ;
}
V_249 -> V_252 -> V_234 = V_234 ;
return 0 ;
}
static void F_168 ( struct V_246 * V_246 )
{
struct V_248 * V_249 = F_157 ( V_246 , V_250 ) ;
F_163 ( V_246 , V_249 -> V_252 ) ;
F_167 ( V_249 -> V_252 ) ;
V_249 -> V_252 = NULL ;
}
static int T_10 F_169 ( void )
{
int V_119 ;
F_2 ( L_44 , V_18 ) ;
V_119 = F_170 ( & V_259 ) ;
if ( V_119 )
goto V_82;
V_119 = F_171 ( & V_260 ) ;
if ( V_119 )
goto V_261;
V_119 = F_172 ( & V_262 ) ;
if ( V_119 )
goto V_263;
V_82:
return V_119 ;
V_263:
F_173 ( & V_260 ) ;
V_261:
F_174 ( & V_259 ) ;
return V_119 ;
}
static void T_11 F_175 ( void )
{
F_2 ( L_45 ,
V_18 ) ;
F_173 ( & V_260 ) ;
F_176 ( & V_262 ) ;
F_174 ( & V_259 ) ;
}
