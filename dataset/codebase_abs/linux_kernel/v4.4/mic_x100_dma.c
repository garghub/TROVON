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
if ( V_38 && - V_35 == F_17 ( V_4 , V_36 , V_37 , V_38 ) ) {
return - V_35 ;
} else {
int V_42 = F_14 ( V_4 , 3 ) ;
if ( V_42 < 0 )
return V_42 ;
}
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
F_32 ( struct V_48 * V_4 , T_2 V_37 , T_3 V_61 ,
unsigned long V_45 )
{
struct V_3 * V_49 = F_23 ( V_4 ) ;
int V_62 ;
F_7 ( & V_49 -> V_58 ) ;
V_62 = F_14 ( V_49 , 4 ) ;
if ( V_62 < 0 )
goto error;
F_5 ( & V_49 -> V_43 [ V_49 -> V_5 ] , V_61 , V_37 ,
false ) ;
F_3 ( V_49 ) ;
V_62 = F_21 ( V_49 , V_45 , 0 , 0 , 0 ) ;
if ( V_62 < 0 )
goto error;
return F_30 ( V_49 ) ;
error:
F_33 ( F_15 ( V_49 ) ,
L_3 , V_62 ) ;
F_12 ( & V_49 -> V_58 ) ;
return NULL ;
}
static struct V_21 *
F_34 ( struct V_48 * V_4 , T_2 V_63 ,
T_2 V_64 , T_4 V_38 , unsigned long V_45 )
{
struct V_3 * V_49 = F_23 ( V_4 ) ;
struct V_32 * V_33 = F_15 ( V_49 ) ;
int V_62 ;
if ( ! V_38 && ! V_45 )
return NULL ;
F_7 ( & V_49 -> V_58 ) ;
V_62 = F_21 ( V_49 , V_45 , V_64 , V_63 , V_38 ) ;
if ( V_62 >= 0 )
return F_30 ( V_49 ) ;
F_33 ( V_33 , L_4 , V_62 ) ;
F_12 ( & V_49 -> V_58 ) ;
return NULL ;
}
static struct V_21 *
F_35 ( struct V_48 * V_4 , unsigned long V_45 )
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
static enum V_65
F_36 ( struct V_48 * V_4 , T_5 V_27 ,
struct V_66 * V_67 )
{
struct V_3 * V_49 = F_23 ( V_4 ) ;
if ( V_68 != F_37 ( V_4 , V_27 , V_67 ) )
F_6 ( V_49 ) ;
return F_37 ( V_4 , V_27 , V_67 ) ;
}
static T_6 F_38 ( int V_69 , void * V_17 )
{
F_6 ( (struct V_3 * ) V_17 ) ;
return V_70 ;
}
static T_6 F_39 ( int V_69 , void * V_17 )
{
struct V_3 * V_4 = ( (struct V_3 * ) V_17 ) ;
F_40 ( V_4 ) ;
return V_71 ;
}
static int F_41 ( struct V_3 * V_4 )
{
T_3 V_72 = V_2 * sizeof( * V_4 -> V_43 ) ;
struct V_32 * V_33 = & F_42 ( V_4 ) -> V_33 ;
V_72 = F_43 ( V_72 , V_73 ) ;
V_4 -> V_43 = F_44 ( V_72 , V_74 ) ;
if ( ! V_4 -> V_43 )
return - V_35 ;
V_4 -> V_75 = F_45 ( V_33 , V_4 -> V_43 ,
V_72 , V_76 ) ;
if ( F_46 ( V_33 , V_4 -> V_75 ) )
goto V_77;
V_4 -> V_26 = F_47 ( V_2 * sizeof( * V_4 -> V_26 ) ) ;
if ( ! V_4 -> V_26 )
goto V_78;
return 0 ;
V_78:
F_48 ( V_33 , V_4 -> V_75 , V_72 ,
V_76 ) ;
V_77:
F_49 ( V_4 -> V_43 ) ;
return - V_35 ;
}
static void F_50 ( struct V_3 * V_4 )
{
T_3 V_72 = V_2 * sizeof( * V_4 -> V_43 ) ;
F_51 ( V_4 -> V_26 ) ;
V_72 = F_43 ( V_72 , V_73 ) ;
F_48 ( & F_42 ( V_4 ) -> V_33 , V_4 -> V_75 ,
V_72 , V_76 ) ;
F_49 ( V_4 -> V_43 ) ;
V_4 -> V_43 = NULL ;
}
static void F_52 ( struct V_3 * V_4 )
{
F_48 ( & F_42 ( V_4 ) -> V_33 , V_4 -> V_44 ,
V_79 , V_76 ) ;
F_49 ( V_4 -> V_80 ) ;
}
static int F_53 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = & F_42 ( V_4 ) -> V_33 ;
V_4 -> V_80 = F_44 ( V_79 , V_74 ) ;
if ( ! V_4 -> V_80 )
return - V_35 ;
V_4 -> V_44 = F_45 ( V_33 , V_4 -> V_80 ,
V_79 , V_76 ) ;
if ( F_46 ( V_33 , V_4 -> V_44 ) ) {
F_49 ( V_4 -> V_80 ) ;
V_4 -> V_80 = NULL ;
return - V_35 ;
}
return 0 ;
}
static int F_54 ( struct V_3 * V_4 )
{
if ( F_55 ( V_4 , V_81 ) ||
F_55 ( V_4 , V_82 ) & V_83 ) {
F_56 ( V_4 ) ;
F_57 ( V_4 ) ;
F_33 ( F_15 ( V_4 ) ,
L_5 ,
V_34 , __LINE__ , V_4 -> V_84 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_58 ( struct V_3 * V_4 )
{
if ( V_86 == V_4 -> V_87 )
F_59 ( V_4 ) ;
F_56 ( V_4 ) ;
F_57 ( V_4 ) ;
F_25 ( V_4 , V_88 , 0 ) ;
F_60 ( V_4 ) ;
V_4 -> V_24 = F_55 ( V_4 , V_89 ) ;
V_4 -> V_5 = V_4 -> V_24 ;
V_4 -> V_51 = 0 ;
F_61 ( V_4 ) ;
F_62 ( V_4 ) ;
return F_54 ( V_4 ) ;
}
static void F_63 ( struct V_3 * V_4 )
{
F_56 ( V_4 ) ;
F_57 ( V_4 ) ;
}
static void F_64 ( struct V_90 * V_91 )
{
F_65 ( & V_91 -> V_92 ) ;
}
static int F_66 ( struct V_3 * V_4 )
{
V_4 -> V_27 =
F_67 ( V_4 ) -> F_68 ( F_42 ( V_4 ) ,
F_39 , F_38 ,
L_6 , V_4 , V_4 -> V_84 ) ;
if ( F_69 ( V_4 -> V_27 ) )
return F_69 ( V_4 -> V_27 ) ;
return 0 ;
}
static inline void F_70 ( struct V_3 * V_4 )
{
F_67 ( V_4 ) -> F_71 ( F_42 ( V_4 ) , V_4 -> V_27 , V_4 ) ;
}
static int F_72 ( struct V_3 * V_4 )
{
int V_42 = F_41 ( V_4 ) ;
if ( V_42 )
goto V_93;
V_42 = F_53 ( V_4 ) ;
if ( V_42 )
goto V_94;
V_42 = F_58 ( V_4 ) ;
if ( V_42 )
goto V_95;
return V_42 ;
V_95:
F_52 ( V_4 ) ;
V_94:
F_50 ( V_4 ) ;
V_93:
return V_42 ;
}
static int F_73 ( struct V_3 * V_4 )
{
struct V_21 * V_22 ;
int V_96 = 0 ;
T_5 V_27 ;
V_22 = F_34 ( & V_4 -> V_56 , 0 , 0 , 0 , V_46 ) ;
if ( ! V_22 ) {
V_96 = - V_35 ;
goto error;
}
V_27 = V_22 -> V_60 ( V_22 ) ;
if ( F_74 ( V_27 ) )
V_96 = - V_35 ;
else
V_96 = F_75 ( & V_4 -> V_56 , V_27 ) ;
if ( V_96 ) {
F_33 ( F_15 ( V_4 ) , L_7 ,
V_34 , __LINE__ , V_4 -> V_84 ) ;
V_96 = - V_97 ;
}
error:
F_6 ( V_4 ) ;
return V_96 ;
}
static inline void F_76 ( struct V_3 * V_4 )
{
F_63 ( V_4 ) ;
F_6 ( V_4 ) ;
F_52 ( V_4 ) ;
F_50 ( V_4 ) ;
}
static int F_77 ( struct V_90 * V_91 ,
enum V_98 V_87 )
{
int V_99 , V_100 = V_91 -> V_101 ;
struct V_3 * V_4 ;
int V_42 ;
for ( V_99 = V_100 ; V_99 < V_100 + V_102 ; V_99 ++ ) {
unsigned long V_17 ;
V_4 = & V_91 -> V_49 [ V_99 ] ;
V_17 = ( unsigned long ) V_4 ;
V_4 -> V_84 = V_99 ;
V_4 -> V_87 = V_87 ;
F_78 ( & V_4 -> V_25 ) ;
F_78 ( & V_4 -> V_58 ) ;
F_78 ( & V_4 -> V_50 ) ;
V_42 = F_66 ( V_4 ) ;
if ( V_42 )
goto error;
}
return 0 ;
error:
for ( V_99 = V_99 - 1 ; V_99 >= V_100 ; V_99 -- )
F_70 ( V_4 ) ;
return V_42 ;
}
static void F_79 ( struct V_90 * V_91 )
{
int V_99 , V_100 = V_91 -> V_101 ;
struct V_3 * V_4 ;
for ( V_99 = V_100 ; V_99 < V_100 + V_102 ; V_99 ++ ) {
V_4 = & V_91 -> V_49 [ V_99 ] ;
F_70 ( V_4 ) ;
}
}
static int F_80 ( struct V_48 * V_4 )
{
int V_42 = F_72 ( F_23 ( V_4 ) ) ;
if ( V_42 )
return V_42 ;
return V_2 ;
}
static void F_81 ( struct V_48 * V_4 )
{
struct V_3 * V_49 = F_23 ( V_4 ) ;
F_73 ( V_49 ) ;
F_76 ( V_49 ) ;
}
static int F_82 ( struct V_90 * V_91 ,
enum V_98 V_87 )
{
int V_99 , V_100 = V_91 -> V_101 ;
F_83 ( V_91 -> V_92 . V_103 ) ;
F_84 ( V_104 , V_91 -> V_92 . V_103 ) ;
if ( V_105 == V_87 )
F_84 ( V_106 , V_91 -> V_92 . V_103 ) ;
V_91 -> V_92 . V_107 =
F_80 ;
V_91 -> V_92 . V_108 =
F_81 ;
V_91 -> V_92 . V_109 = F_36 ;
V_91 -> V_92 . V_110 = F_34 ;
V_91 -> V_92 . V_111 =
F_32 ;
V_91 -> V_92 . V_112 =
F_35 ;
V_91 -> V_92 . V_113 = F_22 ;
V_91 -> V_92 . V_114 = V_13 ;
F_85 ( & V_91 -> V_92 . V_115 ) ;
for ( V_99 = V_100 ; V_99 < V_100 + V_102 ; V_99 ++ ) {
V_91 -> V_49 [ V_99 ] . V_56 . V_32 = & V_91 -> V_92 ;
F_86 ( & V_91 -> V_49 [ V_99 ] . V_56 ) ;
F_87 ( & V_91 -> V_49 [ V_99 ] . V_56 . V_116 ,
& V_91 -> V_92 . V_115 ) ;
}
return F_88 ( & V_91 -> V_92 ) ;
}
static struct V_90 * F_89 ( struct V_117 * V_118 ,
enum V_98 V_87 )
{
struct V_90 * V_91 ;
int V_42 ;
struct V_32 * V_33 = & V_118 -> V_33 ;
V_91 = F_44 ( sizeof( * V_91 ) , V_74 ) ;
if ( ! V_91 ) {
V_42 = - V_35 ;
goto V_119;
}
V_91 -> V_118 = V_118 ;
V_91 -> V_92 . V_33 = V_33 ;
V_91 -> V_120 = V_118 -> V_121 ;
if ( V_105 == V_87 ) {
V_91 -> V_101 = 0 ;
V_91 -> V_40 = V_122 ;
} else {
V_91 -> V_101 = 4 ;
V_91 -> V_40 = V_123 ;
}
V_42 = F_77 ( V_91 , V_87 ) ;
if ( V_42 )
goto V_124;
V_42 = F_82 ( V_91 , V_87 ) ;
if ( V_42 )
goto V_125;
return V_91 ;
V_125:
F_79 ( V_91 ) ;
V_124:
F_49 ( V_91 ) ;
V_91 = NULL ;
V_119:
F_33 ( V_33 , L_8 , V_34 , __LINE__ , V_42 ) ;
return V_91 ;
}
static void F_90 ( struct V_90 * V_91 )
{
F_64 ( V_91 ) ;
F_79 ( V_91 ) ;
F_49 ( V_91 ) ;
}
static int F_91 ( struct V_126 * V_127 , void * V_128 )
{
struct V_90 * V_91 = V_127 -> V_129 ;
int V_99 , V_130 , V_100 = V_91 -> V_101 ;
struct V_3 * V_4 ;
F_92 ( V_127 , L_9 ,
F_93 ( & V_91 -> V_49 [ V_100 ] ,
V_131 + V_132 ) ) ;
F_94 ( V_127 , L_10 ) ;
F_92 ( V_127 , L_11 ,
L_12 , L_13 , L_14 , L_15 , L_16 , L_17 ) ;
F_92 ( V_127 , L_18 , L_19 , L_20 , L_21 ) ;
for ( V_99 = V_100 ; V_99 < V_100 + V_102 ; V_99 ++ ) {
V_4 = & V_91 -> V_49 [ V_99 ] ;
V_130 = V_4 -> V_84 ;
F_92 ( V_127 , L_22 ,
V_130 ,
F_55 ( V_4 , V_133 ) ,
F_55 ( V_4 , V_89 ) ,
F_55 ( V_4 , V_54 ) ,
F_55 ( V_4 , V_134 ) ) ;
F_92 ( V_127 , L_23 ,
F_55 ( V_4 , V_135 ) ,
F_55 ( V_4 , V_81 ) ,
F_55 ( V_4 , V_88 ) ,
F_55 ( V_4 , V_82 ) ) ;
}
return 0 ;
}
static int F_95 ( struct V_136 * V_136 , struct V_137 * V_137 )
{
return F_96 ( V_137 , F_91 , V_136 -> V_138 ) ;
}
static int F_97 ( struct V_136 * V_136 , struct V_137 * V_137 )
{
return F_98 ( V_136 , V_137 ) ;
}
static int F_99 ( struct V_117 * V_118 )
{
struct V_90 * V_91 ;
enum V_98 V_87 ;
if ( V_139 == V_118 -> V_140 . V_32 )
V_87 = V_86 ;
else
V_87 = V_105 ;
V_91 = F_89 ( V_118 , V_87 ) ;
F_100 ( & V_118 -> V_33 , V_91 ) ;
if ( V_141 ) {
V_91 -> V_142 = F_101 ( F_102 ( & V_118 -> V_33 ) ,
V_141 ) ;
if ( V_91 -> V_142 )
F_103 ( L_24 , 0444 ,
V_91 -> V_142 , V_91 ,
& V_143 ) ;
}
return 0 ;
}
static void F_104 ( struct V_117 * V_118 )
{
struct V_90 * V_91 ;
V_91 = F_105 ( & V_118 -> V_33 ) ;
F_106 ( V_91 -> V_142 ) ;
F_90 ( V_91 ) ;
}
static int T_7 F_107 ( void )
{
int V_144 = F_108 ( & V_145 ) ;
if ( V_144 )
return V_144 ;
V_141 = F_101 ( V_146 , NULL ) ;
return 0 ;
}
static void T_8 F_109 ( void )
{
F_106 ( V_141 ) ;
F_110 ( & V_145 ) ;
}
