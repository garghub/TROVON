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
struct V_10 * V_28 )
{
V_39:
if ( ! V_20 ) {
V_20 = F_26 ( V_26 , V_4 , V_3 , F_27 , V_28 ) ;
if ( ! V_20 )
return F_31 ( - V_40 ) ;
}
if ( F_32 ( V_20 , V_1 , V_41 , 0 ) < V_41 ) {
V_20 = F_24 ( V_21 , V_20 ) ;
goto V_39;
}
return V_20 ;
}
static void F_33 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_42 = F_34 ( V_43 , & V_20 -> V_44 ) ;
struct V_45 * V_46 = V_20 -> V_47 + V_20 -> V_48 - 1 ;
struct V_49 * V_50 = (struct V_49 * ) V_28 -> V_11 ;
do {
struct V_1 * V_1 = V_46 -> V_51 ;
if ( -- V_46 >= V_20 -> V_47 )
F_35 ( & V_46 -> V_51 -> V_32 ) ;
if ( V_42 )
F_36 ( V_1 ) ;
} while ( V_46 >= V_20 -> V_47 );
if ( ! V_42 ) {
if ( ! V_50 -> V_52 )
V_50 -> V_52 = - V_53 ;
F_37 ( V_50 -> V_54 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_39 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_49 * V_50 ;
F_2 ( L_11 , V_18 ) ;
V_58 = F_20 ( V_56 , struct V_57 , V_59 . V_60 ) ;
V_50 = F_20 ( V_58 , struct V_49 , V_58 ) ;
F_40 ( V_50 ) ;
}
static void
F_41 ( void * V_11 , int V_61 )
{
struct V_49 * V_50 = V_11 ;
V_50 -> V_58 . V_62 = V_50 -> V_52 ;
F_42 ( & V_50 -> V_58 . V_59 . V_60 , F_39 ) ;
F_43 ( & V_50 -> V_58 . V_59 . V_60 ) ;
}
static enum V_63
F_44 ( struct V_49 * V_50 )
{
int V_64 , V_65 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_66 = NULL ;
T_1 V_4 , V_67 = 0 ;
struct V_10 * V_28 ;
T_2 V_68 = V_50 -> args . V_69 ;
T_3 V_70 = V_50 -> args . V_70 ;
struct V_1 * * V_71 = V_50 -> args . V_71 ;
int V_72 = V_50 -> args . V_73 >> V_74 ;
F_2 ( L_15 , V_18 ,
V_50 -> V_75 , V_68 , V_70 ) ;
V_28 = F_14 ( V_50 ) ;
if ( ! V_28 )
goto V_76;
V_28 -> V_19 = F_41 ;
V_4 = ( T_1 ) ( V_68 >> V_77 ) ;
for ( V_64 = V_72 ; V_64 < V_50 -> V_75 ; V_64 ++ ) {
if ( ! V_67 ) {
F_45 ( V_3 ) ;
F_45 ( V_66 ) ;
V_20 = F_24 ( V_23 , V_20 ) ;
V_3 = F_46 ( F_47 ( V_50 -> V_54 ) ,
V_4 , & V_66 ) ;
if ( ! V_3 ) {
V_50 -> V_52 = - V_53 ;
goto V_78;
}
V_67 = V_3 -> V_79 -
( V_4 - V_3 -> V_34 ) ;
if ( V_66 ) {
T_1 V_80 = V_66 -> V_79 -
( V_4 - V_66 -> V_34 ) ;
V_67 = F_28 ( V_67 , V_80 ) ;
}
}
V_65 = F_11 ( V_3 , V_4 ) ;
if ( V_65 && ! V_66 ) {
V_20 = F_24 ( V_23 , V_20 ) ;
F_2 ( L_16 , V_18 ) ;
F_48 ( V_71 [ V_64 ] , 0 , V_41 ) ;
F_1 ( V_71 [ V_64 ] ) ;
F_36 ( V_71 [ V_64 ] ) ;
} else {
struct V_2 * V_81 ;
V_81 = ( V_65 && V_66 ) ? V_66 : V_3 ;
V_20 = F_30 ( V_20 , V_50 -> V_75 - V_64 , V_23 ,
V_4 , V_71 [ V_64 ] , V_81 ,
F_33 , V_28 ) ;
if ( F_49 ( V_20 ) ) {
V_50 -> V_52 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_78;
}
}
V_4 += V_82 ;
V_67 -= V_82 ;
}
if ( ( V_4 << V_77 ) >= V_50 -> V_83 -> V_84 ) {
V_50 -> V_85 . V_86 = 1 ;
V_50 -> V_85 . V_70 = V_50 -> V_83 -> V_84 - V_68 ;
} else {
V_50 -> V_85 . V_70 = ( V_4 << V_77 ) - V_68 ;
}
V_78:
F_45 ( V_3 ) ;
F_45 ( V_66 ) ;
F_24 ( V_23 , V_20 ) ;
F_22 ( V_28 ) ;
return V_87 ;
V_76:
F_2 ( L_17 ) ;
return V_88 ;
}
static void F_51 ( struct V_89 * V_90 ,
T_4 V_69 , T_5 V_70 )
{
T_1 V_4 , V_91 ;
struct V_2 * V_3 ;
struct V_92 * V_93 ;
F_2 ( L_18 , V_18 , V_69 , V_70 ) ;
if ( V_70 == 0 )
return;
V_4 = ( V_69 & ( long ) ( V_94 ) ) >> V_77 ;
V_91 = ( V_69 + V_70 + V_41 - 1 ) & ( long ) ( V_94 ) ;
V_91 >>= V_77 ;
while ( V_4 < V_91 ) {
T_1 V_95 ;
V_3 = F_46 ( V_90 , V_4 , NULL ) ;
F_52 ( ! V_3 ) ;
V_95 = F_28 ( V_91 , V_3 -> V_34 + V_3 -> V_79 ) - V_4 ;
if ( V_3 -> V_5 == V_7 ) {
V_93 = F_53 ( V_3 -> V_8 ) ;
F_52 ( ! V_93 ) ;
F_54 ( V_3 , V_4 , V_95 , V_93 ) ;
}
V_4 += V_95 ;
F_45 ( V_3 ) ;
}
}
static void F_55 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_42 = F_34 ( V_43 , & V_20 -> V_44 ) ;
struct V_45 * V_46 = V_20 -> V_47 + V_20 -> V_48 - 1 ;
struct V_96 * V_97 = (struct V_96 * ) V_28 -> V_11 ;
do {
struct V_1 * V_1 = V_46 -> V_51 ;
if ( -- V_46 >= V_20 -> V_47 )
F_35 ( & V_46 -> V_51 -> V_32 ) ;
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
} while ( V_46 >= V_20 -> V_47 );
if ( F_58 ( ! V_42 ) ) {
if ( ! V_97 -> V_52 )
V_97 -> V_52 = - V_53 ;
F_37 ( V_97 -> V_54 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_59 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_42 = F_34 ( V_43 , & V_20 -> V_44 ) ;
struct V_96 * V_97 = (struct V_96 * ) V_28 -> V_11 ;
if ( ! V_42 ) {
if ( ! V_97 -> V_52 )
V_97 -> V_52 = - V_53 ;
F_37 ( V_97 -> V_54 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_60 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_96 * V_97 ;
F_2 ( L_11 , V_18 ) ;
V_58 = F_20 ( V_56 , struct V_57 , V_59 . V_60 ) ;
V_97 = F_20 ( V_58 , struct V_96 , V_58 ) ;
if ( F_61 ( ! V_97 -> V_52 ) ) {
F_51 ( F_47 ( V_97 -> V_54 ) ,
V_97 -> args . V_69 , V_97 -> args . V_70 ) ;
}
F_62 ( V_97 ) ;
}
static void F_63 ( void * V_11 , int V_98 )
{
struct V_96 * V_97 = V_11 ;
if ( F_58 ( V_97 -> V_52 ) ) {
F_64 ( & F_47 ( V_97 -> V_54 ) -> V_99 ,
V_98 ) ;
}
V_97 -> V_58 . V_62 = V_97 -> V_52 ;
V_97 -> V_100 . V_101 = V_102 ;
F_42 ( & V_97 -> V_58 . V_59 . V_60 , F_60 ) ;
F_43 ( & V_97 -> V_58 . V_59 . V_60 ) ;
}
static void F_65 ( void )
{
return;
}
static void
F_66 ( struct V_103 * V_104 , T_1 V_4 , struct V_2 * V_3 )
{
F_2 ( L_19 , V_18 , V_3 ) ;
F_67 ( V_104 ) ;
V_104 -> V_105 = V_3 -> V_37 ;
V_104 -> V_106 = ( V_4 - V_3 -> V_34 + V_3 -> V_35 ) >>
( V_3 -> V_37 -> V_107 -> V_108 - V_77 ) ;
F_2 ( L_20 ,
V_18 , ( unsigned long long ) V_4 , ( long ) V_104 -> V_106 ,
V_104 -> V_109 ) ;
return;
}
static int
F_68 ( struct V_1 * V_1 , struct V_2 * V_66 )
{
struct V_103 * V_104 = NULL ;
int V_110 = 0 ;
T_1 V_4 ;
F_2 ( L_21 , V_18 , V_1 ) ;
F_52 ( F_4 ( V_1 ) ) ;
if ( ! V_66 ) {
F_48 ( V_1 , 0 , V_111 ) ;
F_36 ( V_1 ) ;
goto V_112;
}
V_104 = F_69 ( V_1 , V_41 , 0 ) ;
if ( ! V_104 ) {
V_110 = - V_40 ;
goto V_112;
}
V_4 = ( T_1 ) V_1 -> V_113 << V_114 ;
F_66 ( V_104 , V_4 , V_66 ) ;
if ( ! F_70 ( V_104 ) )
V_110 = F_71 ( V_104 ) ;
if ( V_110 )
goto V_112;
F_36 ( V_1 ) ;
V_112:
F_45 ( V_66 ) ;
if ( V_104 )
F_72 ( V_104 ) ;
if ( V_110 ) {
F_65 () ;
}
return V_110 ;
}
static struct V_1 *
F_73 ( struct V_83 * V_83 , T_6 V_113 ,
struct V_2 * V_66 )
{
struct V_1 * V_1 ;
int V_115 = 0 ;
V_1 = F_74 ( V_83 -> V_116 , V_113 ) ;
if ( V_1 )
goto V_117;
V_1 = F_75 ( V_83 -> V_116 , V_113 , V_13 ) ;
if ( F_58 ( ! V_1 ) ) {
F_2 ( L_22 , V_18 ) ;
return F_31 ( - V_40 ) ;
}
V_115 = 1 ;
V_117:
if ( F_6 ( V_1 ) || F_9 ( V_1 ) ) {
F_1 ( V_1 ) ;
if ( V_115 )
F_76 ( V_1 ) ;
F_57 ( V_1 ) ;
return NULL ;
}
if ( ! V_115 ) {
F_77 ( V_1 ) ;
V_115 = 1 ;
goto V_117;
}
if ( ! F_4 ( V_1 ) ) {
F_68 ( V_1 , V_66 ) ;
}
F_78 ( V_1 ) ;
F_76 ( V_1 ) ;
return V_1 ;
}
static enum V_63
F_79 ( struct V_96 * V_97 , int V_118 )
{
int V_64 , V_110 , V_119 , V_72 , V_120 = 0 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_66 = NULL ;
T_1 V_4 , V_121 = 0 , V_67 = 0 ;
struct V_10 * V_28 ;
T_2 V_69 = V_97 -> args . V_69 ;
T_3 V_70 = V_97 -> args . V_70 ;
struct V_1 * * V_71 = V_97 -> args . V_71 ;
struct V_1 * V_1 ;
T_6 V_113 ;
T_7 V_122 ;
int V_123 =
F_80 ( V_97 -> V_83 ) -> V_124 >> V_74 ;
F_2 ( L_23 , V_18 , V_70 , V_69 ) ;
V_28 = F_14 ( V_97 ) ;
if ( ! V_28 )
goto V_125;
V_28 -> V_19 = F_63 ;
V_4 = ( T_1 ) ( ( V_69 & ( long ) V_94 ) >> V_77 ) ;
V_3 = F_46 ( F_47 ( V_97 -> V_54 ) , V_4 , & V_66 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
F_2 ( L_24 , V_18 ) ;
goto V_125;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_61 ( ! F_81 ( V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else
goto V_125;
V_122 = V_69 >> V_74 ;
V_119 = F_82 ( V_122 , V_123 ) ;
V_4 = ( T_1 ) ( ( ( V_69 - V_119 * V_41 ) &
( long ) V_94 ) >> V_77 ) ;
V_67 = V_3 -> V_79 - ( V_4 - V_3 -> V_34 ) ;
V_126:
F_2 ( L_25 , V_18 , V_119 ) ;
for (; V_119 > 0 ; V_119 -- ) {
if ( F_12 ( V_3 -> V_8 , V_4 ) ) {
F_2 ( L_26 ,
( unsigned long long ) V_4 ) ;
goto V_127;
}
V_113 = V_4 >> V_114 ;
F_2 ( L_27 ,
V_18 , V_119 , V_113 ,
( unsigned long long ) V_4 ) ;
V_1 = F_73 ( V_97 -> V_83 , V_113 ,
V_66 ) ;
if ( F_58 ( F_49 ( V_1 ) ) ) {
V_97 -> V_52 = F_50 ( V_1 ) ;
goto V_78;
} else if ( V_1 == NULL )
goto V_127;
V_110 = F_83 ( V_3 -> V_8 , V_4 ,
V_82 ) ;
if ( F_58 ( V_110 ) ) {
F_2 ( L_28 ,
V_18 , V_110 ) ;
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
V_97 -> V_52 = V_110 ;
goto V_78;
}
if ( F_61 ( ! F_81 ( V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else {
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
V_97 -> V_52 = - V_40 ;
goto V_78;
}
F_51 ( F_47 ( V_97 -> V_54 ) ,
V_1 -> V_113 << V_74 ,
V_41 ) ;
V_20 = F_30 ( V_20 , V_119 , V_128 ,
V_4 , V_1 , V_3 ,
F_55 , V_28 ) ;
if ( F_49 ( V_20 ) ) {
V_97 -> V_52 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_78;
}
V_127:
V_4 += V_82 ;
V_67 -= V_82 ;
}
if ( V_120 )
goto V_129;
}
V_20 = F_24 ( V_128 , V_20 ) ;
V_72 = V_97 -> args . V_73 >> V_74 ;
for ( V_64 = V_72 ; V_64 < V_97 -> V_75 ; V_64 ++ ) {
if ( ! V_67 ) {
F_45 ( V_3 ) ;
V_20 = F_24 ( V_128 , V_20 ) ;
V_3 = F_46 ( F_47 ( V_97 -> V_54 ) ,
V_4 , NULL ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
V_97 -> V_52 = - V_130 ;
goto V_78;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_61 ( ! F_81 (
V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else {
V_97 -> V_52 = - V_40 ;
goto V_78;
}
}
V_67 = V_3 -> V_79 -
( V_4 - V_3 -> V_34 ) ;
}
if ( V_3 -> V_5 == V_7 ) {
V_110 = F_83 ( V_3 -> V_8 , V_4 ,
V_82 ) ;
if ( F_58 ( V_110 ) ) {
F_2 ( L_28 ,
V_18 , V_110 ) ;
V_97 -> V_52 = V_110 ;
goto V_78;
}
}
V_20 = F_30 ( V_20 , V_97 -> V_75 - V_64 , V_128 ,
V_4 , V_71 [ V_64 ] , V_3 ,
F_59 , V_28 ) ;
if ( F_49 ( V_20 ) ) {
V_97 -> V_52 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_78;
}
V_4 += V_82 ;
V_121 = V_4 ;
V_67 -= V_82 ;
}
if ( V_3 -> V_5 == V_7 ) {
V_20 = F_24 ( V_128 , V_20 ) ;
V_122 = V_121 >> V_114 ;
V_119 = V_123 - F_82 ( V_122 , V_123 ) ;
if ( V_119 < V_123 ) {
V_120 = 1 ;
goto V_126;
}
}
V_129:
V_97 -> V_85 . V_70 = ( V_121 << V_77 ) - ( V_69 ) ;
if ( V_70 < V_97 -> V_85 . V_70 ) {
V_97 -> V_85 . V_70 = V_70 ;
}
V_78:
F_45 ( V_3 ) ;
F_24 ( V_128 , V_20 ) ;
F_22 ( V_28 ) ;
return V_87 ;
V_125:
F_45 ( V_3 ) ;
F_21 ( V_28 ) ;
return V_88 ;
}
static void
F_84 ( struct V_89 * V_90 , struct V_131 * V_132 )
{
int V_64 ;
struct V_2 * V_3 ;
F_85 ( & V_90 -> V_133 ) ;
for ( V_64 = 0 ; V_64 < V_134 ; V_64 ++ ) {
while ( ! F_86 ( & V_90 -> V_135 [ V_64 ] ) ) {
V_3 = F_87 ( & V_90 -> V_135 [ V_64 ] ,
struct V_2 ,
V_136 ) ;
F_88 ( & V_3 -> V_136 ) ;
F_45 ( V_3 ) ;
}
}
F_89 ( & V_90 -> V_133 ) ;
}
static void
F_90 ( struct V_137 * V_138 )
{
struct V_139 * V_140 , * V_122 ;
struct V_92 * V_93 , * V_141 ;
F_91 (pos, temp, &marks->im_tree.mtt_stub, it_link) {
F_88 ( & V_140 -> V_142 ) ;
F_21 ( V_140 ) ;
}
F_91 (se, stemp, &marks->im_extents, bse_node) {
F_88 ( & V_93 -> V_143 ) ;
F_21 ( V_93 ) ;
}
return;
}
static void F_92 ( struct V_144 * V_145 )
{
struct V_89 * V_90 = F_93 ( V_145 ) ;
F_2 ( L_11 , V_18 ) ;
F_84 ( V_90 , NULL ) ;
F_90 ( & V_90 -> V_99 ) ;
F_21 ( V_90 ) ;
}
static struct V_144 * F_94 ( struct V_83 * V_83 ,
T_8 V_146 )
{
struct V_89 * V_90 ;
F_2 ( L_11 , V_18 ) ;
V_90 = F_95 ( sizeof( * V_90 ) , V_146 ) ;
if ( ! V_90 )
return NULL ;
F_96 ( & V_90 -> V_133 ) ;
F_97 ( & V_90 -> V_135 [ 0 ] ) ;
F_97 ( & V_90 -> V_135 [ 1 ] ) ;
F_97 ( & V_90 -> V_147 ) ;
F_97 ( & V_90 -> V_148 ) ;
V_90 -> V_149 = 0 ;
V_90 -> V_150 = F_80 ( V_83 ) -> V_124 >> V_77 ;
F_98 ( & V_90 -> V_99 , V_90 -> V_150 ) ;
return & V_90 -> V_151 ;
}
static void F_99 ( struct V_152 * V_54 )
{
F_2 ( L_11 , V_18 ) ;
F_21 ( V_54 ) ;
}
static struct V_152 * F_100 ( struct V_144 * V_145 ,
struct V_153 * V_154 ,
T_8 V_146 )
{
struct V_152 * V_54 ;
int V_155 ;
F_2 ( L_11 , V_18 ) ;
V_54 = F_95 ( sizeof( * V_54 ) , V_146 ) ;
if ( ! V_54 )
return F_31 ( - V_40 ) ;
V_155 = F_101 ( V_145 , V_154 , V_146 ) ;
if ( V_155 ) {
F_21 ( V_54 ) ;
return F_31 ( V_155 ) ;
}
return V_54 ;
}
static void
F_102 ( struct V_144 * V_145 , struct V_156 * V_157 ,
const struct V_158 * V_159 )
{
F_2 ( L_11 , V_18 ) ;
F_103 ( F_93 ( V_145 ) , V_157 , V_159 ) ;
}
static void
F_104 ( struct V_160 * V_161 )
{
struct V_144 * V_145 = F_105 ( V_161 -> args . V_83 ) -> V_162 ;
F_2 ( L_11 , V_18 ) ;
F_106 ( F_93 ( V_145 ) , & V_161 -> args , V_161 -> V_85 . V_155 ) ;
}
static void F_107 ( struct V_163 * V_164 )
{
if ( V_164 ) {
struct V_165 * V_166 , * V_167 ;
F_91 (dev, tmp, &mid->bm_devlist, bm_node) {
F_88 ( & V_166 -> V_168 ) ;
F_108 ( V_166 ) ;
}
F_21 ( V_164 ) ;
}
}
static struct V_165 *
F_109 ( struct V_169 * V_170 , const struct V_171 * V_172 ,
struct V_173 * V_174 )
{
struct V_175 * V_166 ;
struct V_165 * V_12 ;
T_9 V_176 ;
int V_177 ;
struct V_1 * * V_71 = NULL ;
int V_64 , V_178 ;
V_176 = V_170 -> V_179 -> V_180 -> V_181 . V_176 ;
V_177 = V_176 >> V_182 ;
F_2 ( L_29 ,
V_18 , V_176 , V_177 ) ;
V_166 = F_15 ( sizeof( * V_166 ) , V_13 ) ;
if ( ! V_166 ) {
F_2 ( L_30 , V_18 ) ;
return F_31 ( - V_40 ) ;
}
V_71 = F_95 ( V_177 * sizeof( struct V_1 * ) , V_13 ) ;
if ( V_71 == NULL ) {
F_21 ( V_166 ) ;
return F_31 ( - V_40 ) ;
}
for ( V_64 = 0 ; V_64 < V_177 ; V_64 ++ ) {
V_71 [ V_64 ] = F_110 ( V_13 ) ;
if ( ! V_71 [ V_64 ] ) {
V_12 = F_31 ( - V_40 ) ;
goto V_183;
}
}
memcpy ( & V_166 -> V_184 , V_174 , sizeof( * V_174 ) ) ;
V_166 -> V_185 = V_186 ;
V_166 -> V_71 = V_71 ;
V_166 -> V_73 = 0 ;
V_166 -> V_187 = V_111 * V_177 ;
V_166 -> V_188 = 0 ;
F_2 ( L_31 , V_18 , V_166 -> V_184 . V_11 ) ;
V_178 = F_111 ( V_170 , V_166 ) ;
F_2 ( L_32 , V_18 , V_178 ) ;
if ( V_178 ) {
V_12 = F_31 ( V_178 ) ;
goto V_183;
}
V_12 = F_112 ( V_170 , V_166 ) ;
V_183:
for ( V_64 = 0 ; V_64 < V_177 ; V_64 ++ )
F_113 ( V_71 [ V_64 ] ) ;
F_21 ( V_71 ) ;
F_21 ( V_166 ) ;
return V_12 ;
}
static int
F_114 ( struct V_169 * V_170 , const struct V_171 * V_172 )
{
struct V_163 * V_189 = NULL ;
struct V_190 * V_191 = NULL ;
struct V_165 * V_192 ;
F_115 ( V_193 ) ;
int V_155 , V_64 ;
F_2 ( L_11 , V_18 ) ;
if ( V_170 -> V_124 == 0 ) {
F_2 ( L_33 , V_18 ) ;
return - V_130 ;
}
V_189 = F_95 ( sizeof( struct V_163 ) , V_13 ) ;
if ( ! V_189 ) {
V_155 = - V_40 ;
goto V_194;
}
F_96 ( & V_189 -> V_195 ) ;
F_97 ( & V_189 -> V_196 ) ;
V_191 = F_15 ( sizeof( struct V_190 ) , V_13 ) ;
if ( ! V_191 ) {
V_155 = - V_40 ;
goto V_194;
}
V_191 -> V_86 = 0 ;
while ( ! V_191 -> V_86 ) {
V_155 = F_116 ( V_170 , V_172 , V_191 ) ;
if ( V_155 )
goto V_194;
F_2 ( L_34 ,
V_18 , V_191 -> V_197 , V_191 -> V_86 ) ;
for ( V_64 = 0 ; V_64 < V_191 -> V_197 ; V_64 ++ ) {
V_192 = F_109 ( V_170 , V_172 ,
& V_191 -> V_184 [ V_64 ] ) ;
if ( F_49 ( V_192 ) ) {
V_155 = F_50 ( V_192 ) ;
goto V_194;
}
F_85 ( & V_189 -> V_195 ) ;
F_117 ( & V_192 -> V_168 , & V_189 -> V_196 ) ;
F_89 ( & V_189 -> V_195 ) ;
}
}
F_2 ( L_35 , V_18 ) ;
V_170 -> V_198 = V_189 ;
V_199:
F_21 ( V_191 ) ;
return V_155 ;
V_194:
F_107 ( V_189 ) ;
goto V_199;
}
static int
F_118 ( struct V_169 * V_170 )
{
struct V_163 * V_189 = V_170 -> V_198 ;
F_2 ( L_11 , V_18 ) ;
F_107 ( V_189 ) ;
F_2 ( L_36 , V_18 ) ;
return 0 ;
}
static int T_10 F_119 ( void )
{
struct V_200 * V_201 ;
struct V_202 V_202 ;
int V_110 ;
F_2 ( L_37 , V_18 ) ;
V_110 = F_120 ( & V_203 ) ;
if ( V_110 )
goto V_78;
F_121 ( & V_204 ) ;
V_201 = F_122 () ;
if ( F_49 ( V_201 ) ) {
V_110 = F_50 ( V_201 ) ;
goto V_205;
}
V_110 = F_123 ( V_201 -> V_206 ,
V_201 ,
V_207 , 0 , & V_202 ) ;
if ( V_110 )
goto V_208;
V_209 = F_124 ( V_202 . V_210 , L_38 , NULL ,
& V_211 , 0 ) ;
F_125 ( & V_202 ) ;
if ( F_49 ( V_209 ) ) {
V_110 = F_50 ( V_209 ) ;
goto V_208;
}
V_78:
return V_110 ;
V_208:
F_126 () ;
V_205:
F_127 ( & V_203 ) ;
return V_110 ;
}
static void T_11 F_128 ( void )
{
F_2 ( L_39 ,
V_18 ) ;
F_127 ( & V_203 ) ;
F_129 ( V_209 ) ;
F_126 () ;
}
