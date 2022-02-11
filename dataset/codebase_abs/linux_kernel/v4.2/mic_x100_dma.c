static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 + 1 ) % V_2 ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return V_1 ? V_1 - 1 : V_2 - 1 ;
}
static inline void F_3 ( struct V_3 * V_4 )
{
V_4 -> V_5 = F_1 ( V_4 -> V_5 ) ;
}
static inline void F_4 ( struct V_6 * V_7 ,
T_2 V_8 , T_2 V_9 , T_3 V_10 )
{
T_3 V_11 , V_12 ;
V_11 = V_8 ;
V_11 |= ( V_10 >> V_13 ) << V_14 ;
V_12 = V_15 ;
V_12 <<= V_16 ;
V_12 |= V_9 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_12 = V_12 ;
}
static inline void F_5 ( struct V_6 * V_7 , T_3 V_17 ,
T_2 V_9 , bool V_18 )
{
T_3 V_11 , V_12 ;
V_11 = V_17 ;
V_12 = ( T_3 ) V_19 << V_16 | V_9 ;
if ( V_18 )
V_12 |= ( 1ULL << V_20 ) ;
V_7 -> V_11 = V_11 ;
V_7 -> V_12 = V_12 ;
}
static void F_6 ( struct V_3 * V_4 )
{
struct V_21 * V_22 ;
T_1 V_23 ;
T_1 V_24 ;
F_7 ( & V_4 -> V_25 ) ;
V_23 = F_8 ( V_4 ) ;
F_9 () ;
for ( V_24 = V_4 -> V_24 ; V_23 != V_24 ; ) {
V_22 = & V_4 -> V_26 [ V_24 ] ;
if ( V_22 -> V_27 ) {
F_10 ( V_22 ) ;
if ( V_22 -> V_28 ) {
V_22 -> V_28 ( V_22 -> V_29 ) ;
V_22 -> V_28 = NULL ;
}
}
V_24 = F_1 ( V_24 ) ;
}
F_11 () ;
V_4 -> V_24 = V_24 ;
F_12 ( & V_4 -> V_25 ) ;
}
static T_1 F_13 ( T_1 V_5 , T_1 V_23 )
{
T_1 V_30 ;
if ( V_5 >= V_23 )
V_30 = ( V_23 - 0 ) + ( V_2 - V_5 ) ;
else
V_30 = V_23 - V_5 ;
return V_30 - 1 ;
}
static int F_14 ( struct V_3 * V_4 , int V_31 )
{
struct V_32 * V_33 = F_15 ( V_4 ) ;
T_1 V_30 ;
V_30 = F_13 ( V_4 -> V_5 , V_4 -> V_24 ) ;
if ( V_30 < V_31 ) {
F_6 ( V_4 ) ;
V_30 = F_13 ( V_4 -> V_5 , V_4 -> V_24 ) ;
}
if ( V_30 < V_31 ) {
F_16 ( V_33 , L_1 ) ;
F_16 ( V_33 , L_2 ,
V_34 , __LINE__ , V_31 , V_30 ) ;
return - V_35 ;
} else {
return V_30 ;
}
}
static int F_17 ( struct V_3 * V_4 , T_2 V_36 ,
T_2 V_37 , T_4 V_38 )
{
T_4 V_39 ;
T_4 V_40 = F_18 ( V_4 ) -> V_40 ;
int V_41 = V_38 / V_40 + 3 ;
int V_42 ;
if ( V_38 % V_40 )
V_41 ++ ;
V_42 = F_14 ( V_4 , V_41 ) ;
if ( V_42 < 0 )
return V_42 ;
do {
V_39 = F_19 ( V_38 , V_40 ) ;
F_4 ( & V_4 -> V_43 [ V_4 -> V_5 ] ,
V_36 , V_37 , V_39 ) ;
F_3 ( V_4 ) ;
V_38 -= V_39 ;
V_37 = V_37 + V_39 ;
V_36 = V_36 + V_39 ;
} while ( V_38 > 0 );
return 0 ;
}
static void F_20 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_43 [ V_4 -> V_5 ] , 0 ,
V_4 -> V_44 , false ) ;
F_3 ( V_4 ) ;
F_5 ( & V_4 -> V_43 [ V_4 -> V_5 ] , 0 ,
V_4 -> V_44 , true ) ;
F_3 ( V_4 ) ;
}
static int F_21 ( struct V_3 * V_4 , int V_45 , T_2 V_36 ,
T_2 V_37 , T_4 V_38 )
{
if ( - V_35 == F_17 ( V_4 , V_36 , V_37 , V_38 ) )
return - V_35 ;
if ( V_45 & V_46 ) {
F_5 ( & V_4 -> V_43 [ V_4 -> V_5 ] , 0 ,
V_4 -> V_44 , false ) ;
F_3 ( V_4 ) ;
}
if ( V_45 & V_47 )
F_20 ( V_4 ) ;
return 0 ;
}
static inline void F_22 ( struct V_48 * V_4 )
{
struct V_3 * V_49 = F_23 ( V_4 ) ;
F_7 ( & V_49 -> V_50 ) ;
if ( V_49 -> V_51 == V_49 -> V_52 )
goto V_53;
V_49 -> V_51 = V_49 -> V_52 ;
F_24 () ;
F_25 ( V_49 , V_54 , V_49 -> V_51 ) ;
V_53:
F_12 ( & V_49 -> V_50 ) ;
}
static inline void F_26 ( struct V_3 * V_4 )
{
if ( F_13 ( V_4 -> V_51 , V_4 -> V_52 )
> V_55 )
F_22 ( & V_4 -> V_56 ) ;
}
static T_5 F_27 ( struct V_21 * V_22 )
{
struct V_3 * V_49 = F_23 ( V_22 -> V_57 ) ;
T_5 V_27 ;
F_28 ( V_22 ) ;
V_27 = V_22 -> V_27 ;
F_29 () ;
V_49 -> V_52 = V_49 -> V_5 ;
F_12 ( & V_49 -> V_58 ) ;
F_26 ( V_49 ) ;
return V_27 ;
}
static inline struct V_21 *
F_30 ( struct V_3 * V_4 )
{
T_1 V_59 = F_2 ( V_4 -> V_5 ) ;
struct V_21 * V_22 = & V_4 -> V_26 [ V_59 ] ;
F_31 ( V_22 , & V_4 -> V_56 ) ;
V_22 -> V_60 = F_27 ;
return V_22 ;
}
static struct V_21 *
F_32 ( struct V_48 * V_4 , T_2 V_61 ,
T_2 V_62 , T_4 V_38 , unsigned long V_45 )
{
struct V_3 * V_49 = F_23 ( V_4 ) ;
struct V_32 * V_33 = F_15 ( V_49 ) ;
int V_63 ;
if ( ! V_38 && ! V_45 )
return NULL ;
F_7 ( & V_49 -> V_58 ) ;
V_63 = F_21 ( V_49 , V_45 , V_62 , V_61 , V_38 ) ;
if ( V_63 >= 0 )
return F_30 ( V_49 ) ;
F_33 ( V_33 , L_3 , V_63 ) ;
F_12 ( & V_49 -> V_58 ) ;
return NULL ;
}
static struct V_21 *
F_34 ( struct V_48 * V_4 , unsigned long V_45 )
{
struct V_3 * V_49 = F_23 ( V_4 ) ;
int V_42 ;
F_7 ( & V_49 -> V_58 ) ;
V_42 = F_21 ( V_49 , V_45 , 0 , 0 , 0 ) ;
if ( ! V_42 )
return F_30 ( V_49 ) ;
F_12 ( & V_49 -> V_58 ) ;
return NULL ;
}
static enum V_64
F_35 ( struct V_48 * V_4 , T_5 V_27 ,
struct V_65 * V_66 )
{
struct V_3 * V_49 = F_23 ( V_4 ) ;
if ( V_67 != F_36 ( V_4 , V_27 , V_66 ) )
F_6 ( V_49 ) ;
return F_36 ( V_4 , V_27 , V_66 ) ;
}
static T_6 F_37 ( int V_68 , void * V_17 )
{
F_6 ( (struct V_3 * ) V_17 ) ;
return V_69 ;
}
static T_6 F_38 ( int V_68 , void * V_17 )
{
struct V_3 * V_4 = ( (struct V_3 * ) V_17 ) ;
F_39 ( V_4 ) ;
return V_70 ;
}
static int F_40 ( struct V_3 * V_4 )
{
T_3 V_71 = V_2 * sizeof( * V_4 -> V_43 ) ;
struct V_32 * V_33 = & F_41 ( V_4 ) -> V_33 ;
V_71 = F_42 ( V_71 , V_72 ) ;
V_4 -> V_43 = F_43 ( V_71 , V_73 ) ;
if ( ! V_4 -> V_43 )
return - V_35 ;
V_4 -> V_74 = F_44 ( V_33 , V_4 -> V_43 ,
V_71 , V_75 ) ;
if ( F_45 ( V_33 , V_4 -> V_74 ) )
goto V_76;
V_4 -> V_26 = F_46 ( V_2 * sizeof( * V_4 -> V_26 ) ) ;
if ( ! V_4 -> V_26 )
goto V_77;
return 0 ;
V_77:
F_47 ( V_33 , V_4 -> V_74 , V_71 ,
V_75 ) ;
V_76:
F_48 ( V_4 -> V_43 ) ;
return - V_35 ;
}
static void F_49 ( struct V_3 * V_4 )
{
T_3 V_71 = V_2 * sizeof( * V_4 -> V_43 ) ;
F_50 ( V_4 -> V_26 ) ;
V_71 = F_42 ( V_71 , V_72 ) ;
F_47 ( & F_41 ( V_4 ) -> V_33 , V_4 -> V_74 ,
V_71 , V_75 ) ;
F_48 ( V_4 -> V_43 ) ;
V_4 -> V_43 = NULL ;
}
static void F_51 ( struct V_3 * V_4 )
{
F_47 ( & F_41 ( V_4 ) -> V_33 , V_4 -> V_44 ,
V_78 , V_75 ) ;
F_48 ( V_4 -> V_79 ) ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = & F_41 ( V_4 ) -> V_33 ;
V_4 -> V_79 = F_43 ( V_78 , V_73 ) ;
if ( ! V_4 -> V_79 )
return - V_35 ;
V_4 -> V_44 = F_44 ( V_33 , V_4 -> V_79 ,
V_78 , V_75 ) ;
if ( F_45 ( V_33 , V_4 -> V_44 ) ) {
F_48 ( V_4 -> V_79 ) ;
V_4 -> V_79 = NULL ;
return - V_35 ;
}
return 0 ;
}
static int F_53 ( struct V_3 * V_4 )
{
if ( F_54 ( V_4 , V_80 ) ||
F_54 ( V_4 , V_81 ) & V_82 ) {
F_55 ( V_4 ) ;
F_56 ( V_4 ) ;
F_33 ( F_15 ( V_4 ) ,
L_4 ,
V_34 , __LINE__ , V_4 -> V_83 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_57 ( struct V_3 * V_4 )
{
if ( V_85 == V_4 -> V_86 )
F_58 ( V_4 ) ;
F_55 ( V_4 ) ;
F_56 ( V_4 ) ;
F_25 ( V_4 , V_87 , 0 ) ;
F_59 ( V_4 ) ;
V_4 -> V_24 = F_54 ( V_4 , V_88 ) ;
V_4 -> V_5 = V_4 -> V_24 ;
V_4 -> V_51 = 0 ;
F_60 ( V_4 ) ;
F_61 ( V_4 ) ;
return F_53 ( V_4 ) ;
}
static void F_62 ( struct V_3 * V_4 )
{
F_55 ( V_4 ) ;
F_56 ( V_4 ) ;
}
static void F_63 ( struct V_89 * V_90 )
{
F_64 ( & V_90 -> V_91 ) ;
}
static int F_65 ( struct V_3 * V_4 )
{
V_4 -> V_27 =
F_66 ( V_4 ) -> F_67 ( F_41 ( V_4 ) ,
F_38 , F_37 ,
L_5 , V_4 , V_4 -> V_83 ) ;
if ( F_68 ( V_4 -> V_27 ) )
return F_68 ( V_4 -> V_27 ) ;
return 0 ;
}
static inline void F_69 ( struct V_3 * V_4 )
{
F_66 ( V_4 ) -> F_70 ( F_41 ( V_4 ) , V_4 -> V_27 , V_4 ) ;
}
static int F_71 ( struct V_3 * V_4 )
{
int V_42 = F_40 ( V_4 ) ;
if ( V_42 )
goto V_92;
V_42 = F_52 ( V_4 ) ;
if ( V_42 )
goto V_93;
V_42 = F_57 ( V_4 ) ;
if ( V_42 )
goto V_94;
return V_42 ;
V_94:
F_51 ( V_4 ) ;
V_93:
F_49 ( V_4 ) ;
V_92:
return V_42 ;
}
static int F_72 ( struct V_3 * V_4 )
{
struct V_21 * V_22 ;
int V_95 = 0 ;
T_5 V_27 ;
V_22 = F_32 ( & V_4 -> V_56 , 0 , 0 , 0 , V_46 ) ;
if ( ! V_22 ) {
V_95 = - V_35 ;
goto error;
}
V_27 = V_22 -> V_60 ( V_22 ) ;
if ( F_73 ( V_27 ) )
V_95 = - V_35 ;
else
V_95 = F_74 ( & V_4 -> V_56 , V_27 ) ;
if ( V_95 ) {
F_33 ( F_15 ( V_4 ) , L_6 ,
V_34 , __LINE__ , V_4 -> V_83 ) ;
V_95 = - V_96 ;
}
error:
F_6 ( V_4 ) ;
return V_95 ;
}
static inline void F_75 ( struct V_3 * V_4 )
{
F_62 ( V_4 ) ;
F_6 ( V_4 ) ;
F_51 ( V_4 ) ;
F_49 ( V_4 ) ;
}
static int F_76 ( struct V_89 * V_90 ,
enum V_97 V_86 )
{
int V_98 , V_99 = V_90 -> V_100 ;
struct V_3 * V_4 ;
int V_42 ;
for ( V_98 = V_99 ; V_98 < V_99 + V_101 ; V_98 ++ ) {
unsigned long V_17 ;
V_4 = & V_90 -> V_49 [ V_98 ] ;
V_17 = ( unsigned long ) V_4 ;
V_4 -> V_83 = V_98 ;
V_4 -> V_86 = V_86 ;
F_77 ( & V_4 -> V_25 ) ;
F_77 ( & V_4 -> V_58 ) ;
F_77 ( & V_4 -> V_50 ) ;
V_42 = F_65 ( V_4 ) ;
if ( V_42 )
goto error;
}
return 0 ;
error:
for ( V_98 = V_98 - 1 ; V_98 >= V_99 ; V_98 -- )
F_69 ( V_4 ) ;
return V_42 ;
}
static void F_78 ( struct V_89 * V_90 )
{
int V_98 , V_99 = V_90 -> V_100 ;
struct V_3 * V_4 ;
for ( V_98 = V_99 ; V_98 < V_99 + V_101 ; V_98 ++ ) {
V_4 = & V_90 -> V_49 [ V_98 ] ;
F_69 ( V_4 ) ;
}
}
static int F_79 ( struct V_48 * V_4 )
{
int V_42 = F_71 ( F_23 ( V_4 ) ) ;
if ( V_42 )
return V_42 ;
return V_2 ;
}
static void F_80 ( struct V_48 * V_4 )
{
struct V_3 * V_49 = F_23 ( V_4 ) ;
F_72 ( V_49 ) ;
F_75 ( V_49 ) ;
}
static int F_81 ( struct V_89 * V_90 ,
enum V_97 V_86 )
{
int V_98 , V_99 = V_90 -> V_100 ;
F_82 ( V_90 -> V_91 . V_102 ) ;
F_83 ( V_103 , V_90 -> V_91 . V_102 ) ;
if ( V_104 == V_86 )
F_83 ( V_105 , V_90 -> V_91 . V_102 ) ;
V_90 -> V_91 . V_106 =
F_79 ;
V_90 -> V_91 . V_107 =
F_80 ;
V_90 -> V_91 . V_108 = F_35 ;
V_90 -> V_91 . V_109 = F_32 ;
V_90 -> V_91 . V_110 =
F_34 ;
V_90 -> V_91 . V_111 = F_22 ;
V_90 -> V_91 . V_112 = V_13 ;
F_84 ( & V_90 -> V_91 . V_113 ) ;
for ( V_98 = V_99 ; V_98 < V_99 + V_101 ; V_98 ++ ) {
V_90 -> V_49 [ V_98 ] . V_56 . V_32 = & V_90 -> V_91 ;
F_85 ( & V_90 -> V_49 [ V_98 ] . V_56 ) ;
F_86 ( & V_90 -> V_49 [ V_98 ] . V_56 . V_114 ,
& V_90 -> V_91 . V_113 ) ;
}
return F_87 ( & V_90 -> V_91 ) ;
}
static struct V_89 * F_88 ( struct V_115 * V_116 ,
enum V_97 V_86 )
{
struct V_89 * V_90 ;
int V_42 ;
struct V_32 * V_33 = & V_116 -> V_33 ;
V_90 = F_43 ( sizeof( * V_90 ) , V_73 ) ;
if ( ! V_90 ) {
V_42 = - V_35 ;
goto V_117;
}
V_90 -> V_116 = V_116 ;
V_90 -> V_91 . V_33 = V_33 ;
V_90 -> V_118 = V_116 -> V_119 ;
if ( V_104 == V_86 ) {
V_90 -> V_100 = 0 ;
V_90 -> V_40 = V_120 ;
} else {
V_90 -> V_100 = 4 ;
V_90 -> V_40 = V_121 ;
}
V_42 = F_76 ( V_90 , V_86 ) ;
if ( V_42 )
goto V_122;
V_42 = F_81 ( V_90 , V_86 ) ;
if ( V_42 )
goto V_123;
return V_90 ;
V_123:
F_78 ( V_90 ) ;
V_122:
F_48 ( V_90 ) ;
V_90 = NULL ;
V_117:
F_33 ( V_33 , L_7 , V_34 , __LINE__ , V_42 ) ;
return V_90 ;
}
static void F_89 ( struct V_89 * V_90 )
{
F_63 ( V_90 ) ;
F_78 ( V_90 ) ;
F_48 ( V_90 ) ;
}
static int F_90 ( struct V_124 * V_125 , void * V_126 )
{
struct V_89 * V_90 = V_125 -> V_127 ;
int V_98 , V_128 , V_99 = V_90 -> V_100 ;
struct V_3 * V_4 ;
F_91 ( V_125 , L_8 ,
F_92 ( & V_90 -> V_49 [ V_99 ] ,
V_129 + V_130 ) ) ;
F_93 ( V_125 , L_9 ) ;
F_91 ( V_125 , L_10 ,
L_11 , L_12 , L_13 , L_14 , L_15 , L_16 ) ;
F_91 ( V_125 , L_17 , L_18 , L_19 , L_20 ) ;
for ( V_98 = V_99 ; V_98 < V_99 + V_101 ; V_98 ++ ) {
V_4 = & V_90 -> V_49 [ V_98 ] ;
V_128 = V_4 -> V_83 ;
F_91 ( V_125 , L_21 ,
V_128 ,
F_54 ( V_4 , V_131 ) ,
F_54 ( V_4 , V_88 ) ,
F_54 ( V_4 , V_54 ) ,
F_54 ( V_4 , V_132 ) ) ;
F_91 ( V_125 , L_22 ,
F_54 ( V_4 , V_133 ) ,
F_54 ( V_4 , V_80 ) ,
F_54 ( V_4 , V_87 ) ,
F_54 ( V_4 , V_81 ) ) ;
}
return 0 ;
}
static int F_94 ( struct V_134 * V_134 , struct V_135 * V_135 )
{
return F_95 ( V_135 , F_90 , V_134 -> V_136 ) ;
}
static int F_96 ( struct V_134 * V_134 , struct V_135 * V_135 )
{
return F_97 ( V_134 , V_135 ) ;
}
static int F_98 ( struct V_115 * V_116 )
{
struct V_89 * V_90 ;
enum V_97 V_86 ;
if ( V_137 == V_116 -> V_138 . V_32 )
V_86 = V_85 ;
else
V_86 = V_104 ;
V_90 = F_88 ( V_116 , V_86 ) ;
F_99 ( & V_116 -> V_33 , V_90 ) ;
if ( V_139 ) {
V_90 -> V_140 = F_100 ( F_101 ( & V_116 -> V_33 ) ,
V_139 ) ;
if ( V_90 -> V_140 )
F_102 ( L_23 , 0444 ,
V_90 -> V_140 , V_90 ,
& V_141 ) ;
}
return 0 ;
}
static void F_103 ( struct V_115 * V_116 )
{
struct V_89 * V_90 ;
V_90 = F_104 ( & V_116 -> V_33 ) ;
F_105 ( V_90 -> V_140 ) ;
F_89 ( V_90 ) ;
}
static int T_7 F_106 ( void )
{
int V_142 = F_107 ( & V_143 ) ;
if ( V_142 )
return V_142 ;
V_139 = F_100 ( V_144 , NULL ) ;
return 0 ;
}
static void T_8 F_108 ( void )
{
F_105 ( V_139 ) ;
F_109 ( & V_143 ) ;
}
