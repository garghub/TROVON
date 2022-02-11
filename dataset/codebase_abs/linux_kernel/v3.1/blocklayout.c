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
}
return V_12 ;
}
static inline void F_17 ( struct V_10 * V_15 )
{
F_18 ( & V_15 -> V_14 ) ;
}
static void F_19 ( struct V_16 * V_16 )
{
struct V_10 * V_15 = F_20 ( V_16 , struct V_10 , V_14 ) ;
F_2 ( L_11 , V_17 ) ;
V_15 -> V_18 ( V_15 -> V_11 ) ;
F_21 ( V_15 ) ;
}
static inline void F_22 ( struct V_10 * V_15 )
{
F_23 ( & V_15 -> V_14 , F_19 ) ;
}
static struct V_19 *
F_24 ( int V_20 , struct V_19 * V_19 )
{
if ( V_19 ) {
F_17 ( V_19 -> V_21 ) ;
F_2 ( L_12 , V_17 ,
V_20 == V_22 ? L_13 : L_14 ,
V_19 -> V_23 , ( unsigned long long ) V_19 -> V_24 ) ;
F_25 ( V_20 , V_19 ) ;
}
return NULL ;
}
static struct V_19 * F_26 ( int V_25 , T_1 V_4 ,
struct V_2 * V_3 ,
void (* F_27)( struct V_19 * , int V_26 ) ,
struct V_10 * V_27 )
{
struct V_19 * V_19 ;
V_19 = F_28 ( V_28 , V_25 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_24 = V_4 - V_3 -> V_29 + V_3 -> V_30 ;
V_19 -> V_31 = V_3 -> V_32 ;
V_19 -> V_33 = F_27 ;
V_19 -> V_21 = V_27 ;
return V_19 ;
}
static struct V_19 * F_29 ( struct V_19 * V_19 , int V_25 , int V_20 ,
T_1 V_4 , struct V_1 * V_1 ,
struct V_2 * V_3 ,
void (* F_27)( struct V_19 * , int V_26 ) ,
struct V_10 * V_27 )
{
V_34:
if ( ! V_19 ) {
V_19 = F_26 ( V_25 , V_4 , V_3 , F_27 , V_27 ) ;
if ( ! V_19 )
return F_30 ( - V_35 ) ;
}
if ( F_31 ( V_19 , V_1 , V_36 , 0 ) < V_36 ) {
V_19 = F_24 ( V_20 , V_19 ) ;
goto V_34;
}
return V_19 ;
}
static void F_32 ( struct V_37 * V_38 )
{
if ( V_38 -> V_39 . V_40 == V_41 ) {
F_2 ( L_15 , V_17 ) ;
F_33 ( F_34 ( V_41 ) , & V_38 -> V_42 -> V_43 ) ;
} else {
F_2 ( L_16 , V_17 ) ;
F_33 ( F_34 ( V_44 ) , & V_38 -> V_42 -> V_43 ) ;
}
}
static void F_35 ( struct V_19 * V_19 , int V_26 )
{
struct V_10 * V_27 = V_19 -> V_21 ;
const int V_45 = F_36 ( V_46 , & V_19 -> V_47 ) ;
struct V_48 * V_49 = V_19 -> V_50 + V_19 -> V_51 - 1 ;
struct V_52 * V_53 = (struct V_52 * ) V_27 -> V_11 ;
do {
struct V_1 * V_1 = V_49 -> V_54 ;
if ( -- V_49 >= V_19 -> V_50 )
F_37 ( & V_49 -> V_54 -> V_55 ) ;
if ( V_45 )
F_38 ( V_1 ) ;
} while ( V_49 >= V_19 -> V_50 );
if ( ! V_45 ) {
if ( ! V_53 -> V_56 )
V_53 -> V_56 = - V_57 ;
F_32 ( V_53 -> V_38 ) ;
}
F_39 ( V_19 ) ;
F_22 ( V_27 ) ;
}
static void F_40 ( struct V_58 * V_59 )
{
struct V_60 * V_61 ;
struct V_52 * V_53 ;
F_2 ( L_11 , V_17 ) ;
V_61 = F_20 ( V_59 , struct V_60 , V_62 . V_63 ) ;
V_53 = F_20 ( V_61 , struct V_52 , V_61 ) ;
F_41 ( V_53 ) ;
}
static void
F_42 ( void * V_11 )
{
struct V_52 * V_53 = V_11 ;
F_43 ( & V_53 -> V_61 . V_62 . V_63 , F_40 ) ;
F_44 ( & V_53 -> V_61 . V_62 . V_63 ) ;
}
static void F_45 ( struct V_60 * V_61 , void * V_64 )
{
return;
}
static enum V_65
F_46 ( struct V_52 * V_53 )
{
int V_66 , V_67 ;
struct V_19 * V_19 = NULL ;
struct V_2 * V_3 = NULL , * V_68 = NULL ;
T_1 V_4 , V_69 = 0 ;
struct V_10 * V_27 ;
T_2 V_70 = V_53 -> args . V_71 ;
T_3 V_72 = V_53 -> args . V_72 ;
struct V_1 * * V_73 = V_53 -> args . V_73 ;
int V_74 = V_53 -> args . V_75 >> V_76 ;
F_2 ( L_17 , V_17 ,
V_53 -> V_77 , V_70 , V_72 ) ;
V_27 = F_14 ( V_53 ) ;
if ( ! V_27 )
goto V_78;
V_27 -> V_79 = * V_53 -> V_80 ;
V_27 -> V_79 . V_81 = F_45 ;
V_27 -> V_18 = F_42 ;
V_4 = ( T_1 ) ( V_70 >> V_82 ) ;
for ( V_66 = V_74 ; V_66 < V_53 -> V_77 ; V_66 ++ ) {
if ( ! V_69 ) {
F_47 ( V_3 ) ;
F_47 ( V_68 ) ;
V_19 = F_24 ( V_22 , V_19 ) ;
V_3 = F_48 ( F_49 ( V_53 -> V_38 ) ,
V_4 , & V_68 ) ;
if ( ! V_3 ) {
V_53 -> V_56 = - V_57 ;
goto V_83;
}
V_69 = V_3 -> V_84 -
( V_4 - V_3 -> V_29 ) ;
if ( V_68 ) {
T_1 V_85 = V_68 -> V_84 -
( V_4 - V_68 -> V_29 ) ;
V_69 = F_50 ( V_69 , V_85 ) ;
}
}
V_67 = F_11 ( V_3 , V_4 ) ;
if ( V_67 && ! V_68 ) {
V_19 = F_24 ( V_22 , V_19 ) ;
F_2 ( L_18 , V_17 ) ;
F_51 ( V_73 [ V_66 ] , 0 , V_36 ) ;
F_1 ( V_73 [ V_66 ] ) ;
F_38 ( V_73 [ V_66 ] ) ;
} else {
struct V_2 * V_86 ;
V_86 = ( V_67 && V_68 ) ? V_68 : V_3 ;
V_19 = F_29 ( V_19 , V_53 -> V_77 - V_66 , V_22 ,
V_4 , V_73 [ V_66 ] , V_86 ,
F_35 , V_27 ) ;
if ( F_52 ( V_19 ) ) {
V_53 -> V_56 = F_53 ( V_19 ) ;
goto V_83;
}
}
V_4 += V_87 ;
V_69 -= V_87 ;
}
if ( ( V_4 << V_82 ) >= V_53 -> V_88 -> V_89 ) {
V_53 -> V_90 . V_91 = 1 ;
V_53 -> V_90 . V_72 = V_53 -> V_88 -> V_89 - V_70 ;
} else {
V_53 -> V_90 . V_72 = ( V_4 << V_82 ) - V_70 ;
}
V_83:
F_47 ( V_3 ) ;
F_47 ( V_68 ) ;
F_24 ( V_22 , V_19 ) ;
F_22 ( V_27 ) ;
return V_92 ;
V_78:
F_2 ( L_19 ) ;
return V_93 ;
}
static void F_54 ( struct V_94 * V_95 ,
T_4 V_71 , T_5 V_72 )
{
T_1 V_4 , V_96 ;
struct V_2 * V_3 ;
F_2 ( L_20 , V_17 , V_71 , V_72 ) ;
if ( V_72 == 0 )
return;
V_4 = ( V_71 & ( long ) ( V_97 ) ) >> V_82 ;
V_96 = ( V_71 + V_72 + V_36 - 1 ) & ( long ) ( V_97 ) ;
V_96 >>= V_82 ;
while ( V_4 < V_96 ) {
T_1 V_98 ;
V_3 = F_48 ( V_95 , V_4 , NULL ) ;
F_55 ( ! V_3 ) ;
V_98 = F_50 ( V_96 , V_3 -> V_29 + V_3 -> V_84 ) - V_4 ;
if ( V_3 -> V_5 == V_7 )
F_56 ( V_3 , V_4 , V_98 ) ;
V_4 += V_98 ;
F_47 ( V_3 ) ;
}
}
static void F_57 ( struct V_19 * V_19 , int V_26 )
{
struct V_10 * V_27 = V_19 -> V_21 ;
const int V_45 = F_36 ( V_46 , & V_19 -> V_47 ) ;
struct V_48 * V_49 = V_19 -> V_50 + V_19 -> V_51 - 1 ;
struct V_99 * V_100 = (struct V_99 * ) V_27 -> V_11 ;
do {
struct V_1 * V_1 = V_49 -> V_54 ;
if ( -- V_49 >= V_19 -> V_50 )
F_37 ( & V_49 -> V_54 -> V_55 ) ;
F_58 ( V_1 ) ;
F_59 ( V_1 ) ;
} while ( V_49 >= V_19 -> V_50 );
if ( ! V_45 ) {
if ( ! V_100 -> V_56 )
V_100 -> V_56 = - V_57 ;
F_32 ( V_100 -> V_38 ) ;
}
F_39 ( V_19 ) ;
F_22 ( V_27 ) ;
}
static void F_60 ( struct V_19 * V_19 , int V_26 )
{
struct V_10 * V_27 = V_19 -> V_21 ;
const int V_45 = F_36 ( V_46 , & V_19 -> V_47 ) ;
struct V_99 * V_100 = (struct V_99 * ) V_27 -> V_11 ;
if ( ! V_45 ) {
if ( ! V_100 -> V_56 )
V_100 -> V_56 = - V_57 ;
F_32 ( V_100 -> V_38 ) ;
}
F_39 ( V_19 ) ;
F_22 ( V_27 ) ;
}
static void F_61 ( struct V_58 * V_59 )
{
struct V_60 * V_61 ;
struct V_99 * V_100 ;
F_2 ( L_11 , V_17 ) ;
V_61 = F_20 ( V_59 , struct V_60 , V_62 . V_63 ) ;
V_100 = F_20 ( V_61 , struct V_99 , V_61 ) ;
if ( ! V_100 -> V_56 ) {
F_54 ( F_49 ( V_100 -> V_38 ) ,
V_100 -> args . V_71 , V_100 -> args . V_72 ) ;
}
F_62 ( V_100 ) ;
}
static void F_63 ( void * V_11 )
{
struct V_99 * V_100 = V_11 ;
V_100 -> V_61 . V_101 = 0 ;
V_100 -> V_102 . V_103 = V_104 ;
F_43 ( & V_100 -> V_61 . V_62 . V_63 , F_61 ) ;
F_44 ( & V_100 -> V_61 . V_62 . V_63 ) ;
}
static void F_64 ( void )
{
return;
}
static void
F_65 ( struct V_105 * V_106 , T_1 V_4 , struct V_2 * V_3 )
{
F_2 ( L_21 , V_17 , V_3 ) ;
F_66 ( V_106 ) ;
V_106 -> V_107 = V_3 -> V_32 ;
V_106 -> V_108 = ( V_4 - V_3 -> V_29 + V_3 -> V_30 ) >>
( V_3 -> V_32 -> V_109 -> V_110 - V_82 ) ;
F_2 ( L_22 ,
V_17 , ( unsigned long long ) V_4 , ( long ) V_106 -> V_108 ,
V_106 -> V_111 ) ;
return;
}
static int
F_67 ( struct V_1 * V_1 , struct V_2 * V_68 )
{
struct V_105 * V_106 = NULL ;
int V_112 = 0 ;
T_1 V_4 ;
F_2 ( L_23 , V_17 , V_1 ) ;
F_55 ( F_4 ( V_1 ) ) ;
if ( ! V_68 ) {
F_51 ( V_1 , 0 , V_113 ) ;
F_38 ( V_1 ) ;
goto V_114;
}
V_106 = F_68 ( V_1 , V_36 , 0 ) ;
if ( ! V_106 ) {
V_112 = - V_35 ;
goto V_114;
}
V_4 = ( T_1 ) V_1 -> V_115 << V_116 ;
F_65 ( V_106 , V_4 , V_68 ) ;
if ( ! F_69 ( V_106 ) )
V_112 = F_70 ( V_106 ) ;
if ( V_112 )
goto V_114;
F_38 ( V_1 ) ;
V_114:
F_47 ( V_68 ) ;
if ( V_106 )
F_71 ( V_106 ) ;
if ( V_112 ) {
F_64 () ;
}
return V_112 ;
}
static enum V_65
F_72 ( struct V_99 * V_100 , int V_117 )
{
int V_66 , V_112 , V_118 , V_74 , V_119 = 0 ;
struct V_19 * V_19 = NULL ;
struct V_2 * V_3 = NULL , * V_68 = NULL ;
T_1 V_4 , V_120 = 0 , V_69 = 0 ;
struct V_10 * V_27 ;
T_2 V_71 = V_100 -> args . V_71 ;
T_3 V_72 = V_100 -> args . V_72 ;
struct V_1 * * V_73 = V_100 -> args . V_73 ;
struct V_1 * V_1 ;
T_6 V_115 ;
T_7 V_121 ;
int V_122 =
F_73 ( V_100 -> V_88 ) -> V_123 >> V_76 ;
F_2 ( L_24 , V_17 , V_72 , V_71 ) ;
V_27 = F_14 ( V_100 ) ;
if ( ! V_27 )
return V_93 ;
V_27 -> V_79 = * V_100 -> V_80 ;
V_27 -> V_79 . V_81 = F_45 ;
V_27 -> V_18 = F_63 ;
V_4 = ( T_1 ) ( ( V_71 & ( long ) V_97 ) >> V_82 ) ;
V_3 = F_48 ( F_49 ( V_100 -> V_38 ) , V_4 , & V_68 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
F_2 ( L_25 , V_17 ) ;
V_100 -> V_56 = - V_124 ;
goto V_83;
}
if ( V_3 -> V_5 == V_7 ) {
V_121 = V_71 >> V_76 ;
V_118 = F_74 ( V_121 , V_122 ) ;
V_4 = ( T_1 ) ( ( ( V_71 - V_118 * V_36 ) &
( long ) V_97 ) >> V_82 ) ;
V_69 = V_3 -> V_84 - ( V_4 - V_3 -> V_29 ) ;
V_125:
F_2 ( L_26 , V_17 , V_118 ) ;
for (; V_118 > 0 ; V_118 -- ) {
V_115 = V_4 >> V_116 ;
F_2 ( L_27 ,
V_17 , V_118 , V_115 ,
( unsigned long long ) V_4 ) ;
V_1 =
F_75 ( V_100 -> V_88 -> V_126 , V_115 ,
V_13 ) ;
if ( ! V_1 ) {
F_2 ( L_28 , V_17 ) ;
V_100 -> V_56 = - V_35 ;
goto V_83;
}
if ( F_6 ( V_1 ) || F_9 ( V_1 ) ||
F_12 ( V_3 -> V_8 , V_4 ) ) {
F_1 ( V_1 ) ;
F_76 ( V_1 ) ;
F_59 ( V_1 ) ;
goto V_127;
}
if ( ! F_4 ( V_1 ) ) {
F_67 ( V_1 , V_68 ) ;
}
F_77 ( V_1 ) ;
F_76 ( V_1 ) ;
V_112 = F_78 ( V_3 -> V_8 , V_4 ,
V_87 ,
NULL ) ;
if ( F_79 ( V_112 ) ) {
F_2 ( L_29 ,
V_17 , V_112 ) ;
F_58 ( V_1 ) ;
F_59 ( V_1 ) ;
V_100 -> V_56 = V_112 ;
goto V_83;
}
V_19 = F_29 ( V_19 , V_118 , V_128 ,
V_4 , V_1 , V_3 ,
F_57 , V_27 ) ;
if ( F_52 ( V_19 ) ) {
V_100 -> V_56 = F_53 ( V_19 ) ;
goto V_83;
}
F_54 ( F_49 ( V_100 -> V_38 ) ,
V_1 -> V_115 << V_76 ,
V_36 ) ;
V_127:
V_4 += V_87 ;
V_69 -= V_87 ;
}
if ( V_119 )
goto V_129;
}
V_19 = F_24 ( V_128 , V_19 ) ;
V_74 = V_100 -> args . V_75 >> V_76 ;
for ( V_66 = V_74 ; V_66 < V_100 -> V_77 ; V_66 ++ ) {
if ( ! V_69 ) {
F_47 ( V_3 ) ;
V_19 = F_24 ( V_128 , V_19 ) ;
V_3 = F_48 ( F_49 ( V_100 -> V_38 ) ,
V_4 , NULL ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
V_100 -> V_56 = - V_124 ;
goto V_83;
}
V_69 = V_3 -> V_84 -
( V_4 - V_3 -> V_29 ) ;
}
if ( V_3 -> V_5 == V_7 ) {
V_112 = F_78 ( V_3 -> V_8 , V_4 ,
V_87 ,
NULL ) ;
if ( F_79 ( V_112 ) ) {
F_2 ( L_29 ,
V_17 , V_112 ) ;
V_100 -> V_56 = V_112 ;
goto V_83;
}
}
V_19 = F_29 ( V_19 , V_100 -> V_77 - V_66 , V_128 ,
V_4 , V_73 [ V_66 ] , V_3 ,
F_60 , V_27 ) ;
if ( F_52 ( V_19 ) ) {
V_100 -> V_56 = F_53 ( V_19 ) ;
goto V_83;
}
V_4 += V_87 ;
V_120 = V_4 ;
V_69 -= V_87 ;
}
if ( V_3 -> V_5 == V_7 ) {
V_19 = F_24 ( V_128 , V_19 ) ;
V_121 = V_120 >> V_116 ;
V_118 = V_122 - F_74 ( V_121 , V_122 ) ;
if ( V_118 < V_122 ) {
V_119 = 1 ;
goto V_125;
}
}
V_129:
V_100 -> V_90 . V_72 = ( V_120 << V_82 ) - ( V_71 ) ;
if ( V_72 < V_100 -> V_90 . V_72 ) {
V_100 -> V_90 . V_72 = V_72 ;
}
V_83:
F_47 ( V_3 ) ;
F_24 ( V_128 , V_19 ) ;
F_22 ( V_27 ) ;
return V_92 ;
}
static void
F_80 ( struct V_94 * V_95 , struct V_130 * V_131 )
{
int V_66 ;
struct V_2 * V_3 ;
F_81 ( & V_95 -> V_132 ) ;
for ( V_66 = 0 ; V_66 < V_133 ; V_66 ++ ) {
while ( ! F_82 ( & V_95 -> V_134 [ V_66 ] ) ) {
V_3 = F_83 ( & V_95 -> V_134 [ V_66 ] ,
struct V_2 ,
V_135 ) ;
F_84 ( & V_3 -> V_135 ) ;
F_47 ( V_3 ) ;
}
}
F_85 ( & V_95 -> V_132 ) ;
}
static void
F_86 ( struct V_136 * V_137 )
{
struct V_138 * V_139 , * V_121 ;
F_87 (pos, temp, &marks->im_tree.mtt_stub, it_link) {
F_84 ( & V_139 -> V_140 ) ;
F_21 ( V_139 ) ;
}
return;
}
static void F_88 ( struct V_141 * V_142 )
{
struct V_94 * V_95 = F_89 ( V_142 ) ;
F_2 ( L_11 , V_17 ) ;
F_80 ( V_95 , NULL ) ;
F_86 ( & V_95 -> V_143 ) ;
F_21 ( V_95 ) ;
}
static struct V_141 * F_90 ( struct V_88 * V_88 ,
T_8 V_144 )
{
struct V_94 * V_95 ;
F_2 ( L_11 , V_17 ) ;
V_95 = F_91 ( sizeof( * V_95 ) , V_144 ) ;
if ( ! V_95 )
return NULL ;
F_92 ( & V_95 -> V_132 ) ;
F_93 ( & V_95 -> V_134 [ 0 ] ) ;
F_93 ( & V_95 -> V_134 [ 1 ] ) ;
F_93 ( & V_95 -> V_145 ) ;
F_93 ( & V_95 -> V_146 ) ;
V_95 -> V_147 = 0 ;
V_95 -> V_148 = F_73 ( V_88 ) -> V_123 >> V_82 ;
F_94 ( & V_95 -> V_143 , V_95 -> V_148 ) ;
return & V_95 -> V_149 ;
}
static void F_95 ( struct V_37 * V_38 )
{
F_2 ( L_11 , V_17 ) ;
F_21 ( V_38 ) ;
}
static struct V_37 * F_96 ( struct V_141 * V_142 ,
struct V_150 * V_151 ,
T_8 V_144 )
{
struct V_37 * V_38 ;
int V_152 ;
F_2 ( L_11 , V_17 ) ;
V_38 = F_91 ( sizeof( * V_38 ) , V_144 ) ;
if ( ! V_38 )
return F_30 ( - V_35 ) ;
V_152 = F_97 ( V_142 , V_151 , V_144 ) ;
if ( V_152 ) {
F_21 ( V_38 ) ;
return F_30 ( V_152 ) ;
}
return V_38 ;
}
static void
F_98 ( struct V_141 * V_142 , struct V_153 * V_154 ,
const struct V_155 * V_156 )
{
F_2 ( L_11 , V_17 ) ;
F_99 ( F_89 ( V_142 ) , V_154 , V_156 ) ;
}
static void
F_100 ( struct V_157 * V_158 )
{
struct V_141 * V_142 = F_101 ( V_158 -> args . V_88 ) -> V_159 ;
F_2 ( L_11 , V_17 ) ;
F_102 ( F_89 ( V_142 ) , & V_158 -> args , V_158 -> V_90 . V_152 ) ;
}
static void F_103 ( struct V_160 * V_161 )
{
if ( V_161 ) {
struct V_162 * V_163 ;
F_81 ( & V_161 -> V_164 ) ;
while ( ! F_82 ( & V_161 -> V_165 ) ) {
V_163 = F_83 ( & V_161 -> V_165 ,
struct V_162 ,
V_166 ) ;
F_84 ( & V_163 -> V_166 ) ;
F_104 ( V_163 ) ;
}
F_85 ( & V_161 -> V_164 ) ;
F_21 ( V_161 ) ;
}
}
static struct V_162 *
F_105 ( struct V_167 * V_168 , const struct V_169 * V_170 ,
struct V_171 * V_172 )
{
struct V_173 * V_163 ;
struct V_162 * V_12 = NULL ;
T_9 V_174 ;
int V_175 ;
struct V_1 * * V_73 = NULL ;
int V_66 , V_176 ;
V_174 = V_168 -> V_177 -> V_178 -> V_179 . V_174 ;
V_175 = V_174 >> V_180 ;
F_2 ( L_30 ,
V_17 , V_174 , V_175 ) ;
V_163 = F_15 ( sizeof( * V_163 ) , V_13 ) ;
if ( ! V_163 ) {
F_2 ( L_31 , V_17 ) ;
return NULL ;
}
V_73 = F_91 ( V_175 * sizeof( struct V_1 * ) , V_13 ) ;
if ( V_73 == NULL ) {
F_21 ( V_163 ) ;
return NULL ;
}
for ( V_66 = 0 ; V_66 < V_175 ; V_66 ++ ) {
V_73 [ V_66 ] = F_106 ( V_13 ) ;
if ( ! V_73 [ V_66 ] )
goto V_181;
}
memcpy ( & V_163 -> V_182 , V_172 , sizeof( * V_172 ) ) ;
V_163 -> V_183 = V_184 ;
V_163 -> V_73 = V_73 ;
V_163 -> V_75 = 0 ;
V_163 -> V_185 = V_113 * V_175 ;
V_163 -> V_186 = 0 ;
F_2 ( L_32 , V_17 , V_163 -> V_182 . V_11 ) ;
V_176 = F_107 ( V_168 , V_163 ) ;
F_2 ( L_33 , V_17 , V_176 ) ;
if ( V_176 )
goto V_181;
V_12 = F_108 ( V_168 , V_163 ) ;
V_181:
for ( V_66 = 0 ; V_66 < V_175 ; V_66 ++ )
F_109 ( V_73 [ V_66 ] ) ;
F_21 ( V_73 ) ;
F_21 ( V_163 ) ;
return V_12 ;
}
static int
F_110 ( struct V_167 * V_168 , const struct V_169 * V_170 )
{
struct V_160 * V_187 = NULL ;
struct V_188 * V_189 = NULL ;
struct V_162 * V_190 ;
F_111 ( V_191 ) ;
int V_152 = 0 , V_66 ;
F_2 ( L_11 , V_17 ) ;
if ( V_168 -> V_123 == 0 ) {
F_2 ( L_34 , V_17 ) ;
return - V_124 ;
}
V_187 = F_91 ( sizeof( struct V_160 ) , V_13 ) ;
if ( ! V_187 ) {
V_152 = - V_35 ;
goto V_192;
}
F_92 ( & V_187 -> V_164 ) ;
F_93 ( & V_187 -> V_165 ) ;
V_189 = F_15 ( sizeof( struct V_188 ) , V_13 ) ;
if ( ! V_189 ) {
V_152 = - V_35 ;
goto V_192;
}
V_189 -> V_91 = 0 ;
while ( ! V_189 -> V_91 ) {
V_152 = F_112 ( V_168 , V_170 , V_189 ) ;
if ( V_152 )
goto V_192;
F_2 ( L_35 ,
V_17 , V_189 -> V_193 , V_189 -> V_91 ) ;
for ( V_66 = 0 ; V_66 < V_189 -> V_193 ; V_66 ++ ) {
V_190 = F_105 ( V_168 , V_170 ,
& V_189 -> V_182 [ V_66 ] ) ;
if ( ! V_190 ) {
V_152 = - V_194 ;
goto V_192;
}
F_81 ( & V_187 -> V_164 ) ;
F_113 ( & V_190 -> V_166 , & V_187 -> V_165 ) ;
F_85 ( & V_187 -> V_164 ) ;
}
}
F_2 ( L_36 , V_17 ) ;
V_168 -> V_195 = V_187 ;
V_196:
F_21 ( V_189 ) ;
return V_152 ;
V_192:
F_103 ( V_187 ) ;
goto V_196;
}
static int
F_114 ( struct V_167 * V_168 )
{
struct V_160 * V_187 = V_168 -> V_195 ;
F_2 ( L_11 , V_17 ) ;
F_103 ( V_187 ) ;
F_2 ( L_37 , V_17 ) ;
return 0 ;
}
static int T_10 F_115 ( void )
{
struct V_197 * V_198 ;
struct V_199 V_199 ;
int V_112 ;
F_2 ( L_38 , V_17 ) ;
V_112 = F_116 ( & V_200 ) ;
if ( V_112 )
goto V_83;
F_117 ( & V_201 ) ;
V_198 = F_118 () ;
if ( F_52 ( V_198 ) ) {
V_112 = F_53 ( V_198 ) ;
goto V_202;
}
V_112 = F_119 ( V_198 -> V_203 ,
V_198 ,
V_204 , 0 , & V_199 ) ;
if ( V_112 )
goto V_202;
V_205 = F_120 ( V_199 . V_206 , L_39 , NULL ,
& V_207 , 0 ) ;
if ( F_52 ( V_205 ) ) {
V_112 = F_53 ( V_205 ) ;
goto V_202;
}
V_83:
return V_112 ;
V_202:
F_121 ( & V_200 ) ;
return V_112 ;
}
static void T_11 F_122 ( void )
{
F_2 ( L_40 ,
V_17 ) ;
F_121 ( & V_200 ) ;
F_123 ( V_205 ) ;
}
