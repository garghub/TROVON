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
do {
struct V_1 * V_1 = V_46 -> V_49 ;
if ( -- V_46 >= V_20 -> V_47 )
F_35 ( & V_46 -> V_49 -> V_32 ) ;
if ( V_42 )
F_36 ( V_1 ) ;
} while ( V_46 >= V_20 -> V_47 );
if ( ! V_42 ) {
struct V_50 * V_51 = V_28 -> V_11 ;
struct V_52 * V_53 = V_51 -> V_53 ;
if ( ! V_53 -> V_54 )
V_53 -> V_54 = - V_55 ;
F_37 ( V_53 -> V_56 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_28 ) ;
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
static bool
F_44 ( T_2 V_65 , T_3 V_66 , unsigned long V_67 )
{
if ( ( V_65 & V_67 ) || ( V_66 & V_67 ) )
return false ;
return true ;
}
static enum V_68
F_45 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_53 ;
int V_69 , V_70 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_71 = NULL ;
T_1 V_4 , V_72 = 0 ;
struct V_10 * V_28 ;
T_4 V_73 = V_51 -> args . V_65 ;
struct V_1 * * V_74 = V_51 -> args . V_74 ;
int V_75 = V_51 -> args . V_76 >> V_77 ;
F_2 ( L_15 , V_18 ,
V_51 -> V_74 . V_78 , V_73 , ( unsigned int ) V_51 -> args . V_79 ) ;
if ( ! F_44 ( V_73 , V_51 -> args . V_79 , V_80 ) )
goto V_81;
V_28 = F_14 ( V_51 ) ;
if ( ! V_28 )
goto V_81;
V_28 -> V_19 = F_41 ;
V_4 = ( T_1 ) ( V_73 >> V_82 ) ;
for ( V_69 = V_75 ; V_69 < V_51 -> V_74 . V_78 ; V_69 ++ ) {
if ( ! V_72 ) {
F_46 ( V_3 ) ;
F_46 ( V_71 ) ;
V_20 = F_24 ( V_23 , V_20 ) ;
V_3 = F_47 ( F_48 ( V_53 -> V_56 ) ,
V_4 , & V_71 ) ;
if ( ! V_3 ) {
V_53 -> V_54 = - V_55 ;
goto V_83;
}
V_72 = V_3 -> V_84 -
( V_4 - V_3 -> V_34 ) ;
if ( V_71 ) {
T_1 V_85 = V_71 -> V_84 -
( V_4 - V_71 -> V_34 ) ;
V_72 = F_28 ( V_72 , V_85 ) ;
}
}
V_70 = F_11 ( V_3 , V_4 ) ;
if ( V_70 && ! V_71 ) {
V_20 = F_24 ( V_23 , V_20 ) ;
F_2 ( L_16 , V_18 ) ;
F_49 ( V_74 [ V_69 ] , 0 , V_41 ) ;
F_1 ( V_74 [ V_69 ] ) ;
F_36 ( V_74 [ V_69 ] ) ;
} else {
struct V_2 * V_86 ;
V_86 = ( V_70 && V_71 ) ? V_71 : V_3 ;
V_20 = F_30 ( V_20 , V_51 -> V_74 . V_78 - V_69 ,
V_23 ,
V_4 , V_74 [ V_69 ] , V_86 ,
F_33 , V_28 ) ;
if ( F_50 ( V_20 ) ) {
V_53 -> V_54 = F_51 ( V_20 ) ;
V_20 = NULL ;
goto V_83;
}
}
V_4 += V_87 ;
V_72 -= V_87 ;
}
if ( ( V_4 << V_82 ) >= V_53 -> V_88 -> V_89 ) {
V_51 -> V_90 . V_91 = 1 ;
V_51 -> V_90 . V_79 = V_53 -> V_88 -> V_89 - V_73 ;
} else {
V_51 -> V_90 . V_79 = ( V_4 << V_82 ) - V_73 ;
}
V_83:
F_46 ( V_3 ) ;
F_46 ( V_71 ) ;
F_24 ( V_23 , V_20 ) ;
F_22 ( V_28 ) ;
return V_92 ;
V_81:
F_2 ( L_17 ) ;
return V_93 ;
}
static void F_52 ( struct V_94 * V_95 ,
T_5 V_65 , T_6 V_79 )
{
T_1 V_4 , V_96 ;
struct V_2 * V_3 ;
struct V_97 * V_98 ;
F_2 ( L_18 , V_18 , V_65 , V_79 ) ;
if ( V_79 == 0 )
return;
V_4 = ( V_65 & ( long ) ( V_80 ) ) >> V_82 ;
V_96 = ( V_65 + V_79 + V_41 - 1 ) & ( long ) ( V_80 ) ;
V_96 >>= V_82 ;
while ( V_4 < V_96 ) {
T_1 V_66 ;
V_3 = F_47 ( V_95 , V_4 , NULL ) ;
F_53 ( ! V_3 ) ;
V_66 = F_28 ( V_96 , V_3 -> V_34 + V_3 -> V_84 ) - V_4 ;
if ( V_3 -> V_5 == V_7 ) {
V_98 = F_54 ( V_3 -> V_8 ) ;
F_53 ( ! V_98 ) ;
F_55 ( V_3 , V_4 , V_66 , V_98 ) ;
}
V_4 += V_66 ;
F_46 ( V_3 ) ;
}
}
static void F_56 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_42 = F_34 ( V_43 , & V_20 -> V_44 ) ;
struct V_45 * V_46 = V_20 -> V_47 + V_20 -> V_48 - 1 ;
do {
struct V_1 * V_1 = V_46 -> V_49 ;
if ( -- V_46 >= V_20 -> V_47 )
F_35 ( & V_46 -> V_49 -> V_32 ) ;
F_57 ( V_1 ) ;
F_58 ( V_1 ) ;
} while ( V_46 >= V_20 -> V_47 );
if ( F_59 ( ! V_42 ) ) {
struct V_99 * V_11 = V_28 -> V_11 ;
struct V_52 * V_53 = V_11 -> V_53 ;
if ( ! V_53 -> V_54 )
V_53 -> V_54 = - V_55 ;
F_37 ( V_53 -> V_56 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_60 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_42 = F_34 ( V_43 , & V_20 -> V_44 ) ;
struct V_99 * V_11 = V_28 -> V_11 ;
struct V_52 * V_53 = V_11 -> V_53 ;
if ( ! V_42 ) {
if ( ! V_53 -> V_54 )
V_53 -> V_54 = - V_55 ;
F_37 ( V_53 -> V_56 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_61 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_99 * V_100 ;
F_2 ( L_11 , V_18 ) ;
V_60 = F_20 ( V_58 , struct V_59 , V_61 . V_62 ) ;
V_100 = F_20 ( V_60 , struct V_99 , V_60 ) ;
if ( F_62 ( ! V_100 -> V_53 -> V_54 ) ) {
F_52 ( F_48 ( V_100 -> V_53 -> V_56 ) ,
V_100 -> args . V_65 , V_100 -> args . V_79 ) ;
}
F_63 ( V_100 ) ;
}
static void F_64 ( void * V_11 , int V_101 )
{
struct V_99 * V_100 = V_11 ;
if ( F_59 ( V_100 -> V_53 -> V_54 ) ) {
F_65 ( & F_48 ( V_100 -> V_53 -> V_56 ) -> V_102 ,
V_101 ) ;
}
V_100 -> V_60 . V_64 = V_100 -> V_53 -> V_54 ;
V_100 -> V_103 . V_104 = V_105 ;
F_42 ( & V_100 -> V_60 . V_61 . V_62 , F_61 ) ;
F_43 ( & V_100 -> V_60 . V_61 . V_62 ) ;
}
static void F_66 ( void )
{
return;
}
static void
F_67 ( struct V_106 * V_107 , T_1 V_4 , struct V_2 * V_3 )
{
F_2 ( L_19 , V_18 , V_3 ) ;
F_68 ( V_107 ) ;
V_107 -> V_108 = V_3 -> V_37 ;
V_107 -> V_109 = ( V_4 - V_3 -> V_34 + V_3 -> V_35 ) >>
( V_3 -> V_37 -> V_110 -> V_111 - V_82 ) ;
F_2 ( L_20 ,
V_18 , ( unsigned long long ) V_4 , ( long ) V_107 -> V_109 ,
V_107 -> V_112 ) ;
return;
}
static int
F_69 ( struct V_1 * V_1 , struct V_2 * V_71 )
{
struct V_106 * V_107 = NULL ;
int V_113 = 0 ;
T_1 V_4 ;
F_2 ( L_21 , V_18 , V_1 ) ;
F_53 ( F_4 ( V_1 ) ) ;
if ( ! V_71 ) {
F_49 ( V_1 , 0 , V_114 ) ;
F_36 ( V_1 ) ;
goto V_115;
}
V_107 = F_70 ( V_1 , V_41 , 0 ) ;
if ( ! V_107 ) {
V_113 = - V_40 ;
goto V_115;
}
V_4 = ( T_1 ) V_1 -> V_116 << V_117 ;
F_67 ( V_107 , V_4 , V_71 ) ;
if ( ! F_71 ( V_107 ) )
V_113 = F_72 ( V_107 ) ;
if ( V_113 )
goto V_115;
F_36 ( V_1 ) ;
V_115:
F_46 ( V_71 ) ;
if ( V_107 )
F_73 ( V_107 ) ;
if ( V_113 ) {
F_66 () ;
}
return V_113 ;
}
static struct V_1 *
F_74 ( struct V_88 * V_88 , T_7 V_116 ,
struct V_2 * V_71 )
{
struct V_1 * V_1 ;
int V_118 = 0 ;
V_1 = F_75 ( V_88 -> V_119 , V_116 ) ;
if ( V_1 )
goto V_120;
V_1 = F_76 ( V_88 -> V_119 , V_116 , V_13 ) ;
if ( F_59 ( ! V_1 ) ) {
F_2 ( L_22 , V_18 ) ;
return F_31 ( - V_40 ) ;
}
V_118 = 1 ;
V_120:
if ( F_6 ( V_1 ) || F_9 ( V_1 ) ) {
F_1 ( V_1 ) ;
if ( V_118 )
F_77 ( V_1 ) ;
F_58 ( V_1 ) ;
return NULL ;
}
if ( ! V_118 ) {
F_78 ( V_1 ) ;
V_118 = 1 ;
goto V_120;
}
if ( ! F_4 ( V_1 ) ) {
F_69 ( V_1 , V_71 ) ;
}
F_79 ( V_1 ) ;
F_77 ( V_1 ) ;
return V_1 ;
}
static enum V_68
F_80 ( struct V_99 * V_100 , int V_121 )
{
struct V_52 * V_53 = V_100 -> V_53 ;
int V_69 , V_113 , V_122 , V_75 , V_123 = 0 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_71 = NULL ;
T_1 V_4 , V_124 = 0 , V_72 = 0 ;
struct V_10 * V_28 = NULL ;
T_4 V_65 = V_100 -> args . V_65 ;
T_8 V_79 = V_100 -> args . V_79 ;
struct V_1 * * V_74 = V_100 -> args . V_74 ;
struct V_1 * V_1 ;
T_7 V_116 ;
T_2 V_125 ;
int V_126 =
F_81 ( V_53 -> V_88 ) -> V_127 >> V_77 ;
F_2 ( L_23 , V_18 , V_79 , V_65 ) ;
if ( ! F_44 ( V_65 , V_79 , V_80 ) )
goto V_128;
V_28 = F_14 ( V_100 ) ;
if ( ! V_28 )
goto V_128;
V_28 -> V_19 = F_64 ;
V_4 = ( T_1 ) ( ( V_65 & ( long ) V_80 ) >> V_82 ) ;
V_3 = F_47 ( F_48 ( V_53 -> V_56 ) , V_4 , & V_71 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
F_2 ( L_24 , V_18 ) ;
goto V_128;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_62 ( ! F_82 ( V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else
goto V_128;
V_125 = V_65 >> V_77 ;
V_122 = F_83 ( V_125 , V_126 ) ;
V_4 = ( T_1 ) ( ( ( V_65 - V_122 * V_41 ) &
( long ) V_80 ) >> V_82 ) ;
V_72 = V_3 -> V_84 - ( V_4 - V_3 -> V_34 ) ;
V_129:
F_2 ( L_25 , V_18 , V_122 ) ;
for (; V_122 > 0 ; V_122 -- ) {
if ( F_12 ( V_3 -> V_8 , V_4 ) ) {
F_2 ( L_26 ,
( unsigned long long ) V_4 ) ;
goto V_130;
}
V_116 = V_4 >> V_117 ;
F_2 ( L_27 ,
V_18 , V_122 , V_116 ,
( unsigned long long ) V_4 ) ;
V_1 = F_74 ( V_53 -> V_88 , V_116 ,
V_71 ) ;
if ( F_59 ( F_50 ( V_1 ) ) ) {
V_53 -> V_54 = F_51 ( V_1 ) ;
goto V_83;
} else if ( V_1 == NULL )
goto V_130;
V_113 = F_84 ( V_3 -> V_8 , V_4 ,
V_87 ) ;
if ( F_59 ( V_113 ) ) {
F_2 ( L_28 ,
V_18 , V_113 ) ;
F_57 ( V_1 ) ;
F_58 ( V_1 ) ;
V_53 -> V_54 = V_113 ;
goto V_83;
}
if ( F_62 ( ! F_82 ( V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else {
F_57 ( V_1 ) ;
F_58 ( V_1 ) ;
V_53 -> V_54 = - V_40 ;
goto V_83;
}
F_52 ( F_48 ( V_53 -> V_56 ) ,
V_1 -> V_116 << V_77 ,
V_41 ) ;
V_20 = F_30 ( V_20 , V_122 , V_131 ,
V_4 , V_1 , V_3 ,
F_56 , V_28 ) ;
if ( F_50 ( V_20 ) ) {
V_53 -> V_54 = F_51 ( V_20 ) ;
V_20 = NULL ;
goto V_83;
}
V_130:
V_4 += V_87 ;
V_72 -= V_87 ;
}
if ( V_123 )
goto V_132;
}
V_20 = F_24 ( V_131 , V_20 ) ;
V_75 = V_100 -> args . V_76 >> V_77 ;
for ( V_69 = V_75 ; V_69 < V_100 -> V_74 . V_78 ; V_69 ++ ) {
if ( ! V_72 ) {
F_46 ( V_3 ) ;
V_20 = F_24 ( V_131 , V_20 ) ;
V_3 = F_47 ( F_48 ( V_53 -> V_56 ) ,
V_4 , NULL ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
V_53 -> V_54 = - V_133 ;
goto V_83;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_62 ( ! F_82 (
V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else {
V_53 -> V_54 = - V_40 ;
goto V_83;
}
}
V_72 = V_3 -> V_84 -
( V_4 - V_3 -> V_34 ) ;
}
if ( V_3 -> V_5 == V_7 ) {
V_113 = F_84 ( V_3 -> V_8 , V_4 ,
V_87 ) ;
if ( F_59 ( V_113 ) ) {
F_2 ( L_28 ,
V_18 , V_113 ) ;
V_53 -> V_54 = V_113 ;
goto V_83;
}
}
V_20 = F_30 ( V_20 , V_100 -> V_74 . V_78 - V_69 , V_131 ,
V_4 , V_74 [ V_69 ] , V_3 ,
F_60 , V_28 ) ;
if ( F_50 ( V_20 ) ) {
V_53 -> V_54 = F_51 ( V_20 ) ;
V_20 = NULL ;
goto V_83;
}
V_4 += V_87 ;
V_124 = V_4 ;
V_72 -= V_87 ;
}
if ( V_3 -> V_5 == V_7 ) {
V_20 = F_24 ( V_131 , V_20 ) ;
V_125 = V_124 >> V_117 ;
V_122 = V_126 - F_83 ( V_125 , V_126 ) ;
if ( V_122 < V_126 ) {
V_123 = 1 ;
goto V_129;
}
}
V_132:
V_100 -> V_90 . V_79 = ( V_124 << V_82 ) - ( V_65 ) ;
if ( V_79 < V_100 -> V_90 . V_79 ) {
V_100 -> V_90 . V_79 = V_79 ;
}
V_83:
F_46 ( V_3 ) ;
F_24 ( V_131 , V_20 ) ;
F_22 ( V_28 ) ;
return V_92 ;
V_128:
F_46 ( V_3 ) ;
F_21 ( V_28 ) ;
return V_93 ;
}
static void
F_85 ( struct V_94 * V_95 , struct V_134 * V_135 )
{
int V_69 ;
struct V_2 * V_3 ;
F_86 ( & V_95 -> V_136 ) ;
for ( V_69 = 0 ; V_69 < V_137 ; V_69 ++ ) {
while ( ! F_87 ( & V_95 -> V_138 [ V_69 ] ) ) {
V_3 = F_88 ( & V_95 -> V_138 [ V_69 ] ,
struct V_2 ,
V_139 ) ;
F_89 ( & V_3 -> V_139 ) ;
F_46 ( V_3 ) ;
}
}
F_90 ( & V_95 -> V_136 ) ;
}
static void
F_91 ( struct V_140 * V_141 )
{
struct V_142 * V_143 , * V_125 ;
struct V_97 * V_98 , * V_144 ;
F_92 (pos, temp, &marks->im_tree.mtt_stub, it_link) {
F_89 ( & V_143 -> V_145 ) ;
F_21 ( V_143 ) ;
}
F_92 (se, stemp, &marks->im_extents, bse_node) {
F_89 ( & V_98 -> V_146 ) ;
F_21 ( V_98 ) ;
}
return;
}
static void F_93 ( struct V_147 * V_148 )
{
struct V_94 * V_95 = F_94 ( V_148 ) ;
F_2 ( L_11 , V_18 ) ;
F_85 ( V_95 , NULL ) ;
F_91 ( & V_95 -> V_102 ) ;
F_21 ( V_95 ) ;
}
static struct V_147 * F_95 ( struct V_88 * V_88 ,
T_9 V_149 )
{
struct V_94 * V_95 ;
F_2 ( L_11 , V_18 ) ;
V_95 = F_96 ( sizeof( * V_95 ) , V_149 ) ;
if ( ! V_95 )
return NULL ;
F_97 ( & V_95 -> V_136 ) ;
F_98 ( & V_95 -> V_138 [ 0 ] ) ;
F_98 ( & V_95 -> V_138 [ 1 ] ) ;
F_98 ( & V_95 -> V_150 ) ;
F_98 ( & V_95 -> V_151 ) ;
V_95 -> V_152 = 0 ;
V_95 -> V_153 = F_81 ( V_88 ) -> V_127 >> V_82 ;
F_99 ( & V_95 -> V_102 , V_95 -> V_153 ) ;
return & V_95 -> V_154 ;
}
static void F_100 ( struct V_155 * V_56 )
{
F_2 ( L_11 , V_18 ) ;
F_21 ( V_56 ) ;
}
static struct V_155 * F_101 ( struct V_147 * V_148 ,
struct V_156 * V_157 ,
T_9 V_149 )
{
struct V_155 * V_56 ;
int V_158 ;
F_2 ( L_11 , V_18 ) ;
V_56 = F_96 ( sizeof( * V_56 ) , V_149 ) ;
if ( ! V_56 )
return F_31 ( - V_40 ) ;
V_158 = F_102 ( V_148 , V_157 , V_149 ) ;
if ( V_158 ) {
F_21 ( V_56 ) ;
return F_31 ( V_158 ) ;
}
return V_56 ;
}
static void
F_103 ( struct V_147 * V_148 , struct V_159 * V_160 ,
const struct V_161 * V_162 )
{
F_2 ( L_11 , V_18 ) ;
F_104 ( F_94 ( V_148 ) , V_160 , V_162 ) ;
}
static void
F_105 ( struct V_163 * V_164 )
{
struct V_147 * V_148 = F_106 ( V_164 -> args . V_88 ) -> V_165 ;
F_2 ( L_11 , V_18 ) ;
F_107 ( F_94 ( V_148 ) , & V_164 -> args , V_164 -> V_90 . V_158 ) ;
}
static void F_108 ( struct V_166 * V_167 )
{
if ( V_167 ) {
struct V_168 * V_169 , * V_170 ;
F_92 (dev, tmp, &mid->bm_devlist, bm_node) {
F_89 ( & V_169 -> V_171 ) ;
F_109 ( V_169 ) ;
}
F_21 ( V_167 ) ;
}
}
static struct V_168 *
F_110 ( struct V_172 * V_173 , const struct V_174 * V_175 ,
struct V_176 * V_177 )
{
struct V_178 * V_169 ;
struct V_168 * V_12 ;
T_3 V_179 ;
int V_180 ;
struct V_1 * * V_74 = NULL ;
int V_69 , V_181 ;
V_179 = V_173 -> V_182 -> V_183 -> V_184 . V_179 ;
V_180 = F_111 ( 0 , V_179 ) ;
F_2 ( L_29 ,
V_18 , V_179 , V_180 ) ;
V_169 = F_15 ( sizeof( * V_169 ) , V_13 ) ;
if ( ! V_169 ) {
F_2 ( L_30 , V_18 ) ;
return F_31 ( - V_40 ) ;
}
V_74 = F_96 ( V_180 * sizeof( struct V_1 * ) , V_13 ) ;
if ( V_74 == NULL ) {
F_21 ( V_169 ) ;
return F_31 ( - V_40 ) ;
}
for ( V_69 = 0 ; V_69 < V_180 ; V_69 ++ ) {
V_74 [ V_69 ] = F_112 ( V_13 ) ;
if ( ! V_74 [ V_69 ] ) {
V_12 = F_31 ( - V_40 ) ;
goto V_185;
}
}
memcpy ( & V_169 -> V_186 , V_177 , sizeof( * V_177 ) ) ;
V_169 -> V_187 = V_188 ;
V_169 -> V_74 = V_74 ;
V_169 -> V_76 = 0 ;
V_169 -> V_189 = V_114 * V_180 ;
V_169 -> V_190 = 0 ;
F_2 ( L_31 , V_18 , V_169 -> V_186 . V_11 ) ;
V_181 = F_113 ( V_173 , V_169 ) ;
F_2 ( L_32 , V_18 , V_181 ) ;
if ( V_181 ) {
V_12 = F_31 ( V_181 ) ;
goto V_185;
}
V_12 = F_114 ( V_173 , V_169 ) ;
V_185:
for ( V_69 = 0 ; V_69 < V_180 ; V_69 ++ )
F_115 ( V_74 [ V_69 ] ) ;
F_21 ( V_74 ) ;
F_21 ( V_169 ) ;
return V_12 ;
}
static int
F_116 ( struct V_172 * V_173 , const struct V_174 * V_175 )
{
struct V_166 * V_191 = NULL ;
struct V_192 * V_193 = NULL ;
struct V_168 * V_194 ;
F_117 ( V_195 ) ;
int V_158 , V_69 ;
F_2 ( L_11 , V_18 ) ;
if ( V_173 -> V_127 == 0 ) {
F_2 ( L_33 , V_18 ) ;
return - V_133 ;
}
V_191 = F_96 ( sizeof( struct V_166 ) , V_13 ) ;
if ( ! V_191 ) {
V_158 = - V_40 ;
goto V_196;
}
F_97 ( & V_191 -> V_197 ) ;
F_98 ( & V_191 -> V_198 ) ;
V_193 = F_15 ( sizeof( struct V_192 ) , V_13 ) ;
if ( ! V_193 ) {
V_158 = - V_40 ;
goto V_196;
}
V_193 -> V_91 = 0 ;
while ( ! V_193 -> V_91 ) {
V_158 = F_118 ( V_173 , V_175 , V_193 ) ;
if ( V_158 )
goto V_196;
F_2 ( L_34 ,
V_18 , V_193 -> V_199 , V_193 -> V_91 ) ;
for ( V_69 = 0 ; V_69 < V_193 -> V_199 ; V_69 ++ ) {
V_194 = F_110 ( V_173 , V_175 ,
& V_193 -> V_186 [ V_69 ] ) ;
if ( F_50 ( V_194 ) ) {
V_158 = F_51 ( V_194 ) ;
goto V_196;
}
F_86 ( & V_191 -> V_197 ) ;
F_119 ( & V_194 -> V_171 , & V_191 -> V_198 ) ;
F_90 ( & V_191 -> V_197 ) ;
}
}
F_2 ( L_35 , V_18 ) ;
V_173 -> V_200 = V_191 ;
V_201:
F_21 ( V_193 ) ;
return V_158 ;
V_196:
F_108 ( V_191 ) ;
goto V_201;
}
static int
F_120 ( struct V_172 * V_173 )
{
struct V_166 * V_191 = V_173 -> V_200 ;
F_2 ( L_11 , V_18 ) ;
F_108 ( V_191 ) ;
F_2 ( L_36 , V_18 ) ;
return 0 ;
}
static void
F_121 ( struct V_202 * V_203 , struct V_204 * V_205 )
{
if ( ! F_44 ( V_205 -> V_206 , V_205 -> V_207 , V_80 ) )
F_122 ( V_203 ) ;
else
F_123 ( V_203 , V_205 ) ;
}
static void
F_124 ( struct V_202 * V_203 , struct V_204 * V_205 )
{
if ( ! F_44 ( V_205 -> V_206 , V_205 -> V_207 , V_80 ) )
F_125 ( V_203 ) ;
else
F_126 ( V_203 , V_205 ) ;
}
static struct V_208 * F_127 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
struct V_208 * V_213 , * V_208 ;
V_213 = F_128 ( V_210 , V_214 ) ;
if ( V_213 == NULL )
return F_31 ( - V_215 ) ;
V_208 = F_129 ( V_213 , L_37 , NULL , V_212 ) ;
F_130 ( V_213 ) ;
return V_208 ;
}
static void F_131 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
if ( V_212 -> V_208 )
F_132 ( V_212 -> V_208 ) ;
}
static int F_133 ( struct V_216 * V_217 , unsigned long V_218 ,
void * V_219 )
{
struct V_209 * V_210 = V_219 ;
struct V_220 * V_220 = V_210 -> V_221 ;
struct V_222 * V_223 = F_134 ( V_220 , V_224 ) ;
struct V_208 * V_208 ;
int V_113 = 0 ;
if ( ! F_135 ( V_225 ) )
return 0 ;
if ( V_223 -> V_226 == NULL ) {
F_136 ( V_225 ) ;
return 0 ;
}
switch ( V_218 ) {
case V_227 :
V_208 = F_127 ( V_210 , V_223 -> V_226 ) ;
if ( F_50 ( V_208 ) ) {
V_113 = F_51 ( V_208 ) ;
break;
}
V_223 -> V_226 -> V_208 = V_208 ;
break;
case V_228 :
if ( V_223 -> V_226 -> V_208 )
F_131 ( V_210 , V_223 -> V_226 ) ;
break;
default:
V_113 = - V_229 ;
break;
}
F_136 ( V_225 ) ;
return V_113 ;
}
static struct V_208 * F_137 ( struct V_220 * V_220 ,
struct V_211 * V_212 )
{
struct V_209 * V_230 ;
struct V_208 * V_208 ;
V_230 = F_138 ( V_220 ) ;
if ( ! V_230 )
return NULL ;
V_208 = F_127 ( V_230 , V_212 ) ;
F_139 ( V_220 ) ;
return V_208 ;
}
static void F_140 ( struct V_220 * V_220 ,
struct V_211 * V_212 )
{
struct V_209 * V_230 ;
V_230 = F_138 ( V_220 ) ;
if ( V_230 ) {
F_131 ( V_230 , V_212 ) ;
F_139 ( V_220 ) ;
}
}
static int F_141 ( struct V_220 * V_220 )
{
struct V_222 * V_223 = F_134 ( V_220 , V_224 ) ;
struct V_208 * V_208 ;
F_142 ( & V_223 -> V_231 ) ;
V_223 -> V_226 = F_143 ( & V_232 , 0 ) ;
if ( F_50 ( V_223 -> V_226 ) )
return F_51 ( V_223 -> V_226 ) ;
V_208 = F_137 ( V_220 , V_223 -> V_226 ) ;
if ( F_50 ( V_208 ) ) {
F_144 ( V_223 -> V_226 ) ;
return F_51 ( V_208 ) ;
}
V_223 -> V_226 -> V_208 = V_208 ;
return 0 ;
}
static void F_145 ( struct V_220 * V_220 )
{
struct V_222 * V_223 = F_134 ( V_220 , V_224 ) ;
F_140 ( V_220 , V_223 -> V_226 ) ;
F_144 ( V_223 -> V_226 ) ;
V_223 -> V_226 = NULL ;
}
static int T_10 F_146 ( void )
{
int V_113 ;
F_2 ( L_38 , V_18 ) ;
V_113 = F_147 ( & V_233 ) ;
if ( V_113 )
goto V_83;
V_113 = F_148 ( & V_234 ) ;
if ( V_113 )
goto V_235;
V_113 = F_149 ( & V_236 ) ;
if ( V_113 )
goto V_237;
V_83:
return V_113 ;
V_237:
F_150 ( & V_234 ) ;
V_235:
F_151 ( & V_233 ) ;
return V_113 ;
}
static void T_11 F_152 ( void )
{
F_2 ( L_39 ,
V_18 ) ;
F_150 ( & V_234 ) ;
F_153 ( & V_236 ) ;
F_151 ( & V_233 ) ;
}
