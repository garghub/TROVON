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
static enum V_65
F_44 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_53 ;
int V_66 , V_67 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_68 = NULL ;
T_1 V_4 , V_69 = 0 ;
struct V_10 * V_28 ;
T_2 V_70 = V_51 -> args . V_71 ;
struct V_1 * * V_72 = V_51 -> args . V_72 ;
int V_73 = V_51 -> args . V_74 >> V_75 ;
F_2 ( L_15 , V_18 ,
V_51 -> V_72 . V_76 , V_70 , ( unsigned int ) V_51 -> args . V_77 ) ;
V_28 = F_14 ( V_51 ) ;
if ( ! V_28 )
goto V_78;
V_28 -> V_19 = F_41 ;
V_4 = ( T_1 ) ( V_70 >> V_79 ) ;
for ( V_66 = V_73 ; V_66 < V_51 -> V_72 . V_76 ; V_66 ++ ) {
if ( ! V_69 ) {
F_45 ( V_3 ) ;
F_45 ( V_68 ) ;
V_20 = F_24 ( V_23 , V_20 ) ;
V_3 = F_46 ( F_47 ( V_53 -> V_56 ) ,
V_4 , & V_68 ) ;
if ( ! V_3 ) {
V_53 -> V_54 = - V_55 ;
goto V_80;
}
V_69 = V_3 -> V_81 -
( V_4 - V_3 -> V_34 ) ;
if ( V_68 ) {
T_1 V_82 = V_68 -> V_81 -
( V_4 - V_68 -> V_34 ) ;
V_69 = F_28 ( V_69 , V_82 ) ;
}
}
V_67 = F_11 ( V_3 , V_4 ) ;
if ( V_67 && ! V_68 ) {
V_20 = F_24 ( V_23 , V_20 ) ;
F_2 ( L_16 , V_18 ) ;
F_48 ( V_72 [ V_66 ] , 0 , V_41 ) ;
F_1 ( V_72 [ V_66 ] ) ;
F_36 ( V_72 [ V_66 ] ) ;
} else {
struct V_2 * V_83 ;
V_83 = ( V_67 && V_68 ) ? V_68 : V_3 ;
V_20 = F_30 ( V_20 , V_51 -> V_72 . V_76 - V_66 ,
V_23 ,
V_4 , V_72 [ V_66 ] , V_83 ,
F_33 , V_28 ) ;
if ( F_49 ( V_20 ) ) {
V_53 -> V_54 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_80;
}
}
V_4 += V_84 ;
V_69 -= V_84 ;
}
if ( ( V_4 << V_79 ) >= V_53 -> V_85 -> V_86 ) {
V_51 -> V_87 . V_88 = 1 ;
V_51 -> V_87 . V_77 = V_53 -> V_85 -> V_86 - V_70 ;
} else {
V_51 -> V_87 . V_77 = ( V_4 << V_79 ) - V_70 ;
}
V_80:
F_45 ( V_3 ) ;
F_45 ( V_68 ) ;
F_24 ( V_23 , V_20 ) ;
F_22 ( V_28 ) ;
return V_89 ;
V_78:
F_2 ( L_17 ) ;
return V_90 ;
}
static void F_51 ( struct V_91 * V_92 ,
T_3 V_71 , T_4 V_77 )
{
T_1 V_4 , V_93 ;
struct V_2 * V_3 ;
struct V_94 * V_95 ;
F_2 ( L_18 , V_18 , V_71 , V_77 ) ;
if ( V_77 == 0 )
return;
V_4 = ( V_71 & ( long ) ( V_96 ) ) >> V_79 ;
V_93 = ( V_71 + V_77 + V_41 - 1 ) & ( long ) ( V_96 ) ;
V_93 >>= V_79 ;
while ( V_4 < V_93 ) {
T_1 V_97 ;
V_3 = F_46 ( V_92 , V_4 , NULL ) ;
F_52 ( ! V_3 ) ;
V_97 = F_28 ( V_93 , V_3 -> V_34 + V_3 -> V_81 ) - V_4 ;
if ( V_3 -> V_5 == V_7 ) {
V_95 = F_53 ( V_3 -> V_8 ) ;
F_52 ( ! V_95 ) ;
F_54 ( V_3 , V_4 , V_97 , V_95 ) ;
}
V_4 += V_97 ;
F_45 ( V_3 ) ;
}
}
static void F_55 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_42 = F_34 ( V_43 , & V_20 -> V_44 ) ;
struct V_45 * V_46 = V_20 -> V_47 + V_20 -> V_48 - 1 ;
do {
struct V_1 * V_1 = V_46 -> V_49 ;
if ( -- V_46 >= V_20 -> V_47 )
F_35 ( & V_46 -> V_49 -> V_32 ) ;
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
} while ( V_46 >= V_20 -> V_47 );
if ( F_58 ( ! V_42 ) ) {
struct V_98 * V_11 = V_28 -> V_11 ;
struct V_52 * V_53 = V_11 -> V_53 ;
if ( ! V_53 -> V_54 )
V_53 -> V_54 = - V_55 ;
F_37 ( V_53 -> V_56 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_59 ( struct V_20 * V_20 , int V_27 )
{
struct V_10 * V_28 = V_20 -> V_22 ;
const int V_42 = F_34 ( V_43 , & V_20 -> V_44 ) ;
struct V_98 * V_11 = V_28 -> V_11 ;
struct V_52 * V_53 = V_11 -> V_53 ;
if ( ! V_42 ) {
if ( ! V_53 -> V_54 )
V_53 -> V_54 = - V_55 ;
F_37 ( V_53 -> V_56 ) ;
}
F_38 ( V_20 ) ;
F_22 ( V_28 ) ;
}
static void F_60 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_98 * V_99 ;
F_2 ( L_11 , V_18 ) ;
V_60 = F_20 ( V_58 , struct V_59 , V_61 . V_62 ) ;
V_99 = F_20 ( V_60 , struct V_98 , V_60 ) ;
if ( F_61 ( ! V_99 -> V_53 -> V_54 ) ) {
F_51 ( F_47 ( V_99 -> V_53 -> V_56 ) ,
V_99 -> args . V_71 , V_99 -> args . V_77 ) ;
}
F_62 ( V_99 ) ;
}
static void F_63 ( void * V_11 , int V_100 )
{
struct V_98 * V_99 = V_11 ;
if ( F_58 ( V_99 -> V_53 -> V_54 ) ) {
F_64 ( & F_47 ( V_99 -> V_53 -> V_56 ) -> V_101 ,
V_100 ) ;
}
V_99 -> V_60 . V_64 = V_99 -> V_53 -> V_54 ;
V_99 -> V_102 . V_103 = V_104 ;
F_42 ( & V_99 -> V_60 . V_61 . V_62 , F_60 ) ;
F_43 ( & V_99 -> V_60 . V_61 . V_62 ) ;
}
static void F_65 ( void )
{
return;
}
static void
F_66 ( struct V_105 * V_106 , T_1 V_4 , struct V_2 * V_3 )
{
F_2 ( L_19 , V_18 , V_3 ) ;
F_67 ( V_106 ) ;
V_106 -> V_107 = V_3 -> V_37 ;
V_106 -> V_108 = ( V_4 - V_3 -> V_34 + V_3 -> V_35 ) >>
( V_3 -> V_37 -> V_109 -> V_110 - V_79 ) ;
F_2 ( L_20 ,
V_18 , ( unsigned long long ) V_4 , ( long ) V_106 -> V_108 ,
V_106 -> V_111 ) ;
return;
}
static int
F_68 ( struct V_1 * V_1 , struct V_2 * V_68 )
{
struct V_105 * V_106 = NULL ;
int V_112 = 0 ;
T_1 V_4 ;
F_2 ( L_21 , V_18 , V_1 ) ;
F_52 ( F_4 ( V_1 ) ) ;
if ( ! V_68 ) {
F_48 ( V_1 , 0 , V_113 ) ;
F_36 ( V_1 ) ;
goto V_114;
}
V_106 = F_69 ( V_1 , V_41 , 0 ) ;
if ( ! V_106 ) {
V_112 = - V_40 ;
goto V_114;
}
V_4 = ( T_1 ) V_1 -> V_115 << V_116 ;
F_66 ( V_106 , V_4 , V_68 ) ;
if ( ! F_70 ( V_106 ) )
V_112 = F_71 ( V_106 ) ;
if ( V_112 )
goto V_114;
F_36 ( V_1 ) ;
V_114:
F_45 ( V_68 ) ;
if ( V_106 )
F_72 ( V_106 ) ;
if ( V_112 ) {
F_65 () ;
}
return V_112 ;
}
static struct V_1 *
F_73 ( struct V_85 * V_85 , T_5 V_115 ,
struct V_2 * V_68 )
{
struct V_1 * V_1 ;
int V_117 = 0 ;
V_1 = F_74 ( V_85 -> V_118 , V_115 ) ;
if ( V_1 )
goto V_119;
V_1 = F_75 ( V_85 -> V_118 , V_115 , V_13 ) ;
if ( F_58 ( ! V_1 ) ) {
F_2 ( L_22 , V_18 ) ;
return F_31 ( - V_40 ) ;
}
V_117 = 1 ;
V_119:
if ( F_6 ( V_1 ) || F_9 ( V_1 ) ) {
F_1 ( V_1 ) ;
if ( V_117 )
F_76 ( V_1 ) ;
F_57 ( V_1 ) ;
return NULL ;
}
if ( ! V_117 ) {
F_77 ( V_1 ) ;
V_117 = 1 ;
goto V_119;
}
if ( ! F_4 ( V_1 ) ) {
F_68 ( V_1 , V_68 ) ;
}
F_78 ( V_1 ) ;
F_76 ( V_1 ) ;
return V_1 ;
}
static enum V_65
F_79 ( struct V_98 * V_99 , int V_120 )
{
struct V_52 * V_53 = V_99 -> V_53 ;
int V_66 , V_112 , V_121 , V_73 , V_122 = 0 ;
struct V_20 * V_20 = NULL ;
struct V_2 * V_3 = NULL , * V_68 = NULL ;
T_1 V_4 , V_123 = 0 , V_69 = 0 ;
struct V_10 * V_28 ;
T_2 V_71 = V_99 -> args . V_71 ;
T_6 V_77 = V_99 -> args . V_77 ;
struct V_1 * * V_72 = V_99 -> args . V_72 ;
struct V_1 * V_1 ;
T_5 V_115 ;
T_7 V_124 ;
int V_125 =
F_80 ( V_53 -> V_85 ) -> V_126 >> V_75 ;
F_2 ( L_23 , V_18 , V_77 , V_71 ) ;
V_28 = F_14 ( V_99 ) ;
if ( ! V_28 )
goto V_127;
V_28 -> V_19 = F_63 ;
V_4 = ( T_1 ) ( ( V_71 & ( long ) V_96 ) >> V_79 ) ;
V_3 = F_46 ( F_47 ( V_53 -> V_56 ) , V_4 , & V_68 ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
F_2 ( L_24 , V_18 ) ;
goto V_127;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_61 ( ! F_81 ( V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else
goto V_127;
V_124 = V_71 >> V_75 ;
V_121 = F_82 ( V_124 , V_125 ) ;
V_4 = ( T_1 ) ( ( ( V_71 - V_121 * V_41 ) &
( long ) V_96 ) >> V_79 ) ;
V_69 = V_3 -> V_81 - ( V_4 - V_3 -> V_34 ) ;
V_128:
F_2 ( L_25 , V_18 , V_121 ) ;
for (; V_121 > 0 ; V_121 -- ) {
if ( F_12 ( V_3 -> V_8 , V_4 ) ) {
F_2 ( L_26 ,
( unsigned long long ) V_4 ) ;
goto V_129;
}
V_115 = V_4 >> V_116 ;
F_2 ( L_27 ,
V_18 , V_121 , V_115 ,
( unsigned long long ) V_4 ) ;
V_1 = F_73 ( V_53 -> V_85 , V_115 ,
V_68 ) ;
if ( F_58 ( F_49 ( V_1 ) ) ) {
V_53 -> V_54 = F_50 ( V_1 ) ;
goto V_80;
} else if ( V_1 == NULL )
goto V_129;
V_112 = F_83 ( V_3 -> V_8 , V_4 ,
V_84 ) ;
if ( F_58 ( V_112 ) ) {
F_2 ( L_28 ,
V_18 , V_112 ) ;
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
V_53 -> V_54 = V_112 ;
goto V_80;
}
if ( F_61 ( ! F_81 ( V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else {
F_56 ( V_1 ) ;
F_57 ( V_1 ) ;
V_53 -> V_54 = - V_40 ;
goto V_80;
}
F_51 ( F_47 ( V_53 -> V_56 ) ,
V_1 -> V_115 << V_75 ,
V_41 ) ;
V_20 = F_30 ( V_20 , V_121 , V_130 ,
V_4 , V_1 , V_3 ,
F_55 , V_28 ) ;
if ( F_49 ( V_20 ) ) {
V_53 -> V_54 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_80;
}
V_129:
V_4 += V_84 ;
V_69 -= V_84 ;
}
if ( V_122 )
goto V_131;
}
V_20 = F_24 ( V_130 , V_20 ) ;
V_73 = V_99 -> args . V_74 >> V_75 ;
for ( V_66 = V_73 ; V_66 < V_99 -> V_72 . V_76 ; V_66 ++ ) {
if ( ! V_69 ) {
F_45 ( V_3 ) ;
V_20 = F_24 ( V_130 , V_20 ) ;
V_3 = F_46 ( F_47 ( V_53 -> V_56 ) ,
V_4 , NULL ) ;
if ( ! V_3 || ! F_13 ( V_3 , V_4 ) ) {
V_53 -> V_54 = - V_132 ;
goto V_80;
}
if ( V_3 -> V_5 == V_7 ) {
if ( F_61 ( ! F_81 (
V_3 -> V_8 ) ) )
V_28 -> V_15 ++ ;
else {
V_53 -> V_54 = - V_40 ;
goto V_80;
}
}
V_69 = V_3 -> V_81 -
( V_4 - V_3 -> V_34 ) ;
}
if ( V_3 -> V_5 == V_7 ) {
V_112 = F_83 ( V_3 -> V_8 , V_4 ,
V_84 ) ;
if ( F_58 ( V_112 ) ) {
F_2 ( L_28 ,
V_18 , V_112 ) ;
V_53 -> V_54 = V_112 ;
goto V_80;
}
}
V_20 = F_30 ( V_20 , V_99 -> V_72 . V_76 - V_66 , V_130 ,
V_4 , V_72 [ V_66 ] , V_3 ,
F_59 , V_28 ) ;
if ( F_49 ( V_20 ) ) {
V_53 -> V_54 = F_50 ( V_20 ) ;
V_20 = NULL ;
goto V_80;
}
V_4 += V_84 ;
V_123 = V_4 ;
V_69 -= V_84 ;
}
if ( V_3 -> V_5 == V_7 ) {
V_20 = F_24 ( V_130 , V_20 ) ;
V_124 = V_123 >> V_116 ;
V_121 = V_125 - F_82 ( V_124 , V_125 ) ;
if ( V_121 < V_125 ) {
V_122 = 1 ;
goto V_128;
}
}
V_131:
V_99 -> V_87 . V_77 = ( V_123 << V_79 ) - ( V_71 ) ;
if ( V_77 < V_99 -> V_87 . V_77 ) {
V_99 -> V_87 . V_77 = V_77 ;
}
V_80:
F_45 ( V_3 ) ;
F_24 ( V_130 , V_20 ) ;
F_22 ( V_28 ) ;
return V_89 ;
V_127:
F_45 ( V_3 ) ;
F_21 ( V_28 ) ;
return V_90 ;
}
static void
F_84 ( struct V_91 * V_92 , struct V_133 * V_134 )
{
int V_66 ;
struct V_2 * V_3 ;
F_85 ( & V_92 -> V_135 ) ;
for ( V_66 = 0 ; V_66 < V_136 ; V_66 ++ ) {
while ( ! F_86 ( & V_92 -> V_137 [ V_66 ] ) ) {
V_3 = F_87 ( & V_92 -> V_137 [ V_66 ] ,
struct V_2 ,
V_138 ) ;
F_88 ( & V_3 -> V_138 ) ;
F_45 ( V_3 ) ;
}
}
F_89 ( & V_92 -> V_135 ) ;
}
static void
F_90 ( struct V_139 * V_140 )
{
struct V_141 * V_142 , * V_124 ;
struct V_94 * V_95 , * V_143 ;
F_91 (pos, temp, &marks->im_tree.mtt_stub, it_link) {
F_88 ( & V_142 -> V_144 ) ;
F_21 ( V_142 ) ;
}
F_91 (se, stemp, &marks->im_extents, bse_node) {
F_88 ( & V_95 -> V_145 ) ;
F_21 ( V_95 ) ;
}
return;
}
static void F_92 ( struct V_146 * V_147 )
{
struct V_91 * V_92 = F_93 ( V_147 ) ;
F_2 ( L_11 , V_18 ) ;
F_84 ( V_92 , NULL ) ;
F_90 ( & V_92 -> V_101 ) ;
F_21 ( V_92 ) ;
}
static struct V_146 * F_94 ( struct V_85 * V_85 ,
T_8 V_148 )
{
struct V_91 * V_92 ;
F_2 ( L_11 , V_18 ) ;
V_92 = F_95 ( sizeof( * V_92 ) , V_148 ) ;
if ( ! V_92 )
return NULL ;
F_96 ( & V_92 -> V_135 ) ;
F_97 ( & V_92 -> V_137 [ 0 ] ) ;
F_97 ( & V_92 -> V_137 [ 1 ] ) ;
F_97 ( & V_92 -> V_149 ) ;
F_97 ( & V_92 -> V_150 ) ;
V_92 -> V_151 = 0 ;
V_92 -> V_152 = F_80 ( V_85 ) -> V_126 >> V_79 ;
F_98 ( & V_92 -> V_101 , V_92 -> V_152 ) ;
return & V_92 -> V_153 ;
}
static void F_99 ( struct V_154 * V_56 )
{
F_2 ( L_11 , V_18 ) ;
F_21 ( V_56 ) ;
}
static struct V_154 * F_100 ( struct V_146 * V_147 ,
struct V_155 * V_156 ,
T_8 V_148 )
{
struct V_154 * V_56 ;
int V_157 ;
F_2 ( L_11 , V_18 ) ;
V_56 = F_95 ( sizeof( * V_56 ) , V_148 ) ;
if ( ! V_56 )
return F_31 ( - V_40 ) ;
V_157 = F_101 ( V_147 , V_156 , V_148 ) ;
if ( V_157 ) {
F_21 ( V_56 ) ;
return F_31 ( V_157 ) ;
}
return V_56 ;
}
static void
F_102 ( struct V_146 * V_147 , struct V_158 * V_159 ,
const struct V_160 * V_161 )
{
F_2 ( L_11 , V_18 ) ;
F_103 ( F_93 ( V_147 ) , V_159 , V_161 ) ;
}
static void
F_104 ( struct V_162 * V_163 )
{
struct V_146 * V_147 = F_105 ( V_163 -> args . V_85 ) -> V_164 ;
F_2 ( L_11 , V_18 ) ;
F_106 ( F_93 ( V_147 ) , & V_163 -> args , V_163 -> V_87 . V_157 ) ;
}
static void F_107 ( struct V_165 * V_166 )
{
if ( V_166 ) {
struct V_167 * V_168 , * V_169 ;
F_91 (dev, tmp, &mid->bm_devlist, bm_node) {
F_88 ( & V_168 -> V_170 ) ;
F_108 ( V_168 ) ;
}
F_21 ( V_166 ) ;
}
}
static struct V_167 *
F_109 ( struct V_171 * V_172 , const struct V_173 * V_174 ,
struct V_175 * V_176 )
{
struct V_177 * V_168 ;
struct V_167 * V_12 ;
T_9 V_178 ;
int V_179 ;
struct V_1 * * V_72 = NULL ;
int V_66 , V_180 ;
V_178 = V_172 -> V_181 -> V_182 -> V_183 . V_178 ;
V_179 = F_110 ( 0 , V_178 ) ;
F_2 ( L_29 ,
V_18 , V_178 , V_179 ) ;
V_168 = F_15 ( sizeof( * V_168 ) , V_13 ) ;
if ( ! V_168 ) {
F_2 ( L_30 , V_18 ) ;
return F_31 ( - V_40 ) ;
}
V_72 = F_95 ( V_179 * sizeof( struct V_1 * ) , V_13 ) ;
if ( V_72 == NULL ) {
F_21 ( V_168 ) ;
return F_31 ( - V_40 ) ;
}
for ( V_66 = 0 ; V_66 < V_179 ; V_66 ++ ) {
V_72 [ V_66 ] = F_111 ( V_13 ) ;
if ( ! V_72 [ V_66 ] ) {
V_12 = F_31 ( - V_40 ) ;
goto V_184;
}
}
memcpy ( & V_168 -> V_185 , V_176 , sizeof( * V_176 ) ) ;
V_168 -> V_186 = V_187 ;
V_168 -> V_72 = V_72 ;
V_168 -> V_74 = 0 ;
V_168 -> V_188 = V_113 * V_179 ;
V_168 -> V_189 = 0 ;
F_2 ( L_31 , V_18 , V_168 -> V_185 . V_11 ) ;
V_180 = F_112 ( V_172 , V_168 ) ;
F_2 ( L_32 , V_18 , V_180 ) ;
if ( V_180 ) {
V_12 = F_31 ( V_180 ) ;
goto V_184;
}
V_12 = F_113 ( V_172 , V_168 ) ;
V_184:
for ( V_66 = 0 ; V_66 < V_179 ; V_66 ++ )
F_114 ( V_72 [ V_66 ] ) ;
F_21 ( V_72 ) ;
F_21 ( V_168 ) ;
return V_12 ;
}
static int
F_115 ( struct V_171 * V_172 , const struct V_173 * V_174 )
{
struct V_165 * V_190 = NULL ;
struct V_191 * V_192 = NULL ;
struct V_167 * V_193 ;
F_116 ( V_194 ) ;
int V_157 , V_66 ;
F_2 ( L_11 , V_18 ) ;
if ( V_172 -> V_126 == 0 ) {
F_2 ( L_33 , V_18 ) ;
return - V_132 ;
}
V_190 = F_95 ( sizeof( struct V_165 ) , V_13 ) ;
if ( ! V_190 ) {
V_157 = - V_40 ;
goto V_195;
}
F_96 ( & V_190 -> V_196 ) ;
F_97 ( & V_190 -> V_197 ) ;
V_192 = F_15 ( sizeof( struct V_191 ) , V_13 ) ;
if ( ! V_192 ) {
V_157 = - V_40 ;
goto V_195;
}
V_192 -> V_88 = 0 ;
while ( ! V_192 -> V_88 ) {
V_157 = F_117 ( V_172 , V_174 , V_192 ) ;
if ( V_157 )
goto V_195;
F_2 ( L_34 ,
V_18 , V_192 -> V_198 , V_192 -> V_88 ) ;
for ( V_66 = 0 ; V_66 < V_192 -> V_198 ; V_66 ++ ) {
V_193 = F_109 ( V_172 , V_174 ,
& V_192 -> V_185 [ V_66 ] ) ;
if ( F_49 ( V_193 ) ) {
V_157 = F_50 ( V_193 ) ;
goto V_195;
}
F_85 ( & V_190 -> V_196 ) ;
F_118 ( & V_193 -> V_170 , & V_190 -> V_197 ) ;
F_89 ( & V_190 -> V_196 ) ;
}
}
F_2 ( L_35 , V_18 ) ;
V_172 -> V_199 = V_190 ;
V_200:
F_21 ( V_192 ) ;
return V_157 ;
V_195:
F_107 ( V_190 ) ;
goto V_200;
}
static int
F_119 ( struct V_171 * V_172 )
{
struct V_165 * V_190 = V_172 -> V_199 ;
F_2 ( L_11 , V_18 ) ;
F_107 ( V_190 ) ;
F_2 ( L_36 , V_18 ) ;
return 0 ;
}
static struct V_201 * F_120 ( struct V_202 * V_203 ,
struct V_204 * V_205 )
{
struct V_201 * V_206 , * V_201 ;
V_206 = F_121 ( V_203 , V_207 ) ;
if ( V_206 == NULL )
return F_31 ( - V_208 ) ;
V_201 = F_122 ( V_206 , L_37 , NULL , V_205 ) ;
F_123 ( V_206 ) ;
return V_201 ;
}
static void F_124 ( struct V_202 * V_203 ,
struct V_204 * V_205 )
{
if ( V_205 -> V_201 )
F_125 ( V_205 -> V_201 ) ;
}
static int F_126 ( struct V_209 * V_210 , unsigned long V_211 ,
void * V_212 )
{
struct V_202 * V_203 = V_212 ;
struct V_213 * V_213 = V_203 -> V_214 ;
struct V_215 * V_216 = F_127 ( V_213 , V_217 ) ;
struct V_201 * V_201 ;
int V_112 = 0 ;
if ( ! F_128 ( V_218 ) )
return 0 ;
if ( V_216 -> V_219 == NULL ) {
F_129 ( V_218 ) ;
return 0 ;
}
switch ( V_211 ) {
case V_220 :
V_201 = F_120 ( V_203 , V_216 -> V_219 ) ;
if ( F_49 ( V_201 ) ) {
V_112 = F_50 ( V_201 ) ;
break;
}
V_216 -> V_219 -> V_201 = V_201 ;
break;
case V_221 :
if ( V_216 -> V_219 -> V_201 )
F_124 ( V_203 , V_216 -> V_219 ) ;
break;
default:
V_112 = - V_222 ;
break;
}
F_129 ( V_218 ) ;
return V_112 ;
}
static struct V_201 * F_130 ( struct V_213 * V_213 ,
struct V_204 * V_205 )
{
struct V_202 * V_223 ;
struct V_201 * V_201 ;
V_223 = F_131 ( V_213 ) ;
if ( ! V_223 )
return NULL ;
V_201 = F_120 ( V_223 , V_205 ) ;
F_132 ( V_213 ) ;
return V_201 ;
}
static void F_133 ( struct V_213 * V_213 ,
struct V_204 * V_205 )
{
struct V_202 * V_223 ;
V_223 = F_131 ( V_213 ) ;
if ( V_223 ) {
F_124 ( V_223 , V_205 ) ;
F_132 ( V_213 ) ;
}
}
static int F_134 ( struct V_213 * V_213 )
{
struct V_215 * V_216 = F_127 ( V_213 , V_217 ) ;
struct V_201 * V_201 ;
F_135 ( & V_216 -> V_224 ) ;
V_216 -> V_219 = F_136 ( & V_225 , 0 ) ;
if ( F_49 ( V_216 -> V_219 ) )
return F_50 ( V_216 -> V_219 ) ;
V_201 = F_130 ( V_213 , V_216 -> V_219 ) ;
if ( F_49 ( V_201 ) ) {
F_137 ( V_216 -> V_219 ) ;
return F_50 ( V_201 ) ;
}
V_216 -> V_219 -> V_201 = V_201 ;
return 0 ;
}
static void F_138 ( struct V_213 * V_213 )
{
struct V_215 * V_216 = F_127 ( V_213 , V_217 ) ;
F_133 ( V_213 , V_216 -> V_219 ) ;
F_137 ( V_216 -> V_219 ) ;
V_216 -> V_219 = NULL ;
}
static int T_10 F_139 ( void )
{
int V_112 ;
F_2 ( L_38 , V_18 ) ;
V_112 = F_140 ( & V_226 ) ;
if ( V_112 )
goto V_80;
V_112 = F_141 ( & V_227 ) ;
if ( V_112 )
goto V_228;
V_112 = F_142 ( & V_229 ) ;
if ( V_112 )
goto V_230;
V_80:
return V_112 ;
V_230:
F_143 ( & V_227 ) ;
V_228:
F_144 ( & V_226 ) ;
return V_112 ;
}
static void T_11 F_145 ( void )
{
F_2 ( L_39 ,
V_18 ) ;
F_143 ( & V_227 ) ;
F_146 ( & V_229 ) ;
F_144 ( & V_226 ) ;
}
