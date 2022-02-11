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
F_11 ( V_22 , NULL ) ;
V_22 -> V_28 = NULL ;
}
V_24 = F_1 ( V_24 ) ;
}
F_12 () ;
V_4 -> V_24 = V_24 ;
F_13 ( & V_4 -> V_25 ) ;
}
static T_1 F_14 ( T_1 V_5 , T_1 V_23 )
{
T_1 V_29 ;
if ( V_5 >= V_23 )
V_29 = ( V_23 - 0 ) + ( V_2 - V_5 ) ;
else
V_29 = V_23 - V_5 ;
return V_29 - 1 ;
}
static int F_15 ( struct V_3 * V_4 , int V_30 )
{
struct V_31 * V_32 = F_16 ( V_4 ) ;
T_1 V_29 ;
V_29 = F_14 ( V_4 -> V_5 , V_4 -> V_24 ) ;
if ( V_29 < V_30 ) {
F_6 ( V_4 ) ;
V_29 = F_14 ( V_4 -> V_5 , V_4 -> V_24 ) ;
}
if ( V_29 < V_30 ) {
F_17 ( V_32 , L_1 ) ;
F_17 ( V_32 , L_2 ,
V_33 , __LINE__ , V_30 , V_29 ) ;
return - V_34 ;
} else {
return V_29 ;
}
}
static int F_18 ( struct V_3 * V_4 , T_2 V_35 ,
T_2 V_36 , T_4 V_37 )
{
T_4 V_38 ;
T_4 V_39 = F_19 ( V_4 ) -> V_39 ;
int V_40 = V_37 / V_39 + 3 ;
int V_41 ;
if ( V_37 % V_39 )
V_40 ++ ;
V_41 = F_15 ( V_4 , V_40 ) ;
if ( V_41 < 0 )
return V_41 ;
do {
V_38 = F_20 ( V_37 , V_39 ) ;
F_4 ( & V_4 -> V_42 [ V_4 -> V_5 ] ,
V_35 , V_36 , V_38 ) ;
F_3 ( V_4 ) ;
V_37 -= V_38 ;
V_36 = V_36 + V_38 ;
V_35 = V_35 + V_38 ;
} while ( V_37 > 0 );
return 0 ;
}
static void F_21 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_42 [ V_4 -> V_5 ] , 0 ,
V_4 -> V_43 , false ) ;
F_3 ( V_4 ) ;
F_5 ( & V_4 -> V_42 [ V_4 -> V_5 ] , 0 ,
V_4 -> V_43 , true ) ;
F_3 ( V_4 ) ;
}
static int F_22 ( struct V_3 * V_4 , int V_44 , T_2 V_35 ,
T_2 V_36 , T_4 V_37 )
{
if ( V_37 && - V_34 == F_18 ( V_4 , V_35 , V_36 , V_37 ) ) {
return - V_34 ;
} else {
int V_41 = F_15 ( V_4 , 3 ) ;
if ( V_41 < 0 )
return V_41 ;
}
if ( V_44 & V_45 ) {
F_5 ( & V_4 -> V_42 [ V_4 -> V_5 ] , 0 ,
V_4 -> V_43 , false ) ;
F_3 ( V_4 ) ;
}
if ( V_44 & V_46 )
F_21 ( V_4 ) ;
return 0 ;
}
static inline void F_23 ( struct V_47 * V_4 )
{
struct V_3 * V_48 = F_24 ( V_4 ) ;
F_7 ( & V_48 -> V_49 ) ;
if ( V_48 -> V_50 == V_48 -> V_51 )
goto V_52;
V_48 -> V_50 = V_48 -> V_51 ;
F_25 () ;
F_26 ( V_48 , V_53 , V_48 -> V_50 ) ;
V_52:
F_13 ( & V_48 -> V_49 ) ;
}
static inline void F_27 ( struct V_3 * V_4 )
{
if ( F_14 ( V_4 -> V_50 , V_4 -> V_51 )
> V_54 )
F_23 ( & V_4 -> V_55 ) ;
}
static T_5 F_28 ( struct V_21 * V_22 )
{
struct V_3 * V_48 = F_24 ( V_22 -> V_56 ) ;
T_5 V_27 ;
F_29 ( V_22 ) ;
V_27 = V_22 -> V_27 ;
F_30 () ;
V_48 -> V_51 = V_48 -> V_5 ;
F_13 ( & V_48 -> V_57 ) ;
F_27 ( V_48 ) ;
return V_27 ;
}
static inline struct V_21 *
F_31 ( struct V_3 * V_4 )
{
T_1 V_58 = F_2 ( V_4 -> V_5 ) ;
struct V_21 * V_22 = & V_4 -> V_26 [ V_58 ] ;
F_32 ( V_22 , & V_4 -> V_55 ) ;
V_22 -> V_59 = F_28 ;
return V_22 ;
}
static struct V_21 *
F_33 ( struct V_47 * V_4 , T_2 V_36 , T_3 V_60 ,
unsigned long V_44 )
{
struct V_3 * V_48 = F_24 ( V_4 ) ;
int V_61 ;
F_7 ( & V_48 -> V_57 ) ;
V_61 = F_15 ( V_48 , 4 ) ;
if ( V_61 < 0 )
goto error;
F_5 ( & V_48 -> V_42 [ V_48 -> V_5 ] , V_60 , V_36 ,
false ) ;
F_3 ( V_48 ) ;
V_61 = F_22 ( V_48 , V_44 , 0 , 0 , 0 ) ;
if ( V_61 < 0 )
goto error;
return F_31 ( V_48 ) ;
error:
F_34 ( F_16 ( V_48 ) ,
L_3 , V_61 ) ;
F_13 ( & V_48 -> V_57 ) ;
return NULL ;
}
static struct V_21 *
F_35 ( struct V_47 * V_4 , T_2 V_62 ,
T_2 V_63 , T_4 V_37 , unsigned long V_44 )
{
struct V_3 * V_48 = F_24 ( V_4 ) ;
struct V_31 * V_32 = F_16 ( V_48 ) ;
int V_61 ;
if ( ! V_37 && ! V_44 )
return NULL ;
F_7 ( & V_48 -> V_57 ) ;
V_61 = F_22 ( V_48 , V_44 , V_63 , V_62 , V_37 ) ;
if ( V_61 >= 0 )
return F_31 ( V_48 ) ;
F_34 ( V_32 , L_4 , V_61 ) ;
F_13 ( & V_48 -> V_57 ) ;
return NULL ;
}
static struct V_21 *
F_36 ( struct V_47 * V_4 , unsigned long V_44 )
{
struct V_3 * V_48 = F_24 ( V_4 ) ;
int V_41 ;
F_7 ( & V_48 -> V_57 ) ;
V_41 = F_22 ( V_48 , V_44 , 0 , 0 , 0 ) ;
if ( ! V_41 )
return F_31 ( V_48 ) ;
F_13 ( & V_48 -> V_57 ) ;
return NULL ;
}
static enum V_64
F_37 ( struct V_47 * V_4 , T_5 V_27 ,
struct V_65 * V_66 )
{
struct V_3 * V_48 = F_24 ( V_4 ) ;
if ( V_67 != F_38 ( V_4 , V_27 , V_66 ) )
F_6 ( V_48 ) ;
return F_38 ( V_4 , V_27 , V_66 ) ;
}
static T_6 F_39 ( int V_68 , void * V_17 )
{
F_6 ( (struct V_3 * ) V_17 ) ;
return V_69 ;
}
static T_6 F_40 ( int V_68 , void * V_17 )
{
struct V_3 * V_4 = ( (struct V_3 * ) V_17 ) ;
F_41 ( V_4 ) ;
return V_70 ;
}
static int F_42 ( struct V_3 * V_4 )
{
T_3 V_71 = V_2 * sizeof( * V_4 -> V_42 ) ;
struct V_31 * V_32 = & F_43 ( V_4 ) -> V_32 ;
V_71 = F_44 ( V_71 , V_72 ) ;
V_4 -> V_42 = F_45 ( V_71 , V_73 ) ;
if ( ! V_4 -> V_42 )
return - V_34 ;
V_4 -> V_74 = F_46 ( V_32 , V_4 -> V_42 ,
V_71 , V_75 ) ;
if ( F_47 ( V_32 , V_4 -> V_74 ) )
goto V_76;
V_4 -> V_26 = F_48 ( V_2 * sizeof( * V_4 -> V_26 ) ) ;
if ( ! V_4 -> V_26 )
goto V_77;
return 0 ;
V_77:
F_49 ( V_32 , V_4 -> V_74 , V_71 ,
V_75 ) ;
V_76:
F_50 ( V_4 -> V_42 ) ;
return - V_34 ;
}
static void F_51 ( struct V_3 * V_4 )
{
T_3 V_71 = V_2 * sizeof( * V_4 -> V_42 ) ;
F_52 ( V_4 -> V_26 ) ;
V_71 = F_44 ( V_71 , V_72 ) ;
F_49 ( & F_43 ( V_4 ) -> V_32 , V_4 -> V_74 ,
V_71 , V_75 ) ;
F_50 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
}
static void F_53 ( struct V_3 * V_4 )
{
F_49 ( & F_43 ( V_4 ) -> V_32 , V_4 -> V_43 ,
V_78 , V_75 ) ;
F_50 ( V_4 -> V_79 ) ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = & F_43 ( V_4 ) -> V_32 ;
V_4 -> V_79 = F_45 ( V_78 , V_73 ) ;
if ( ! V_4 -> V_79 )
return - V_34 ;
V_4 -> V_43 = F_46 ( V_32 , V_4 -> V_79 ,
V_78 , V_75 ) ;
if ( F_47 ( V_32 , V_4 -> V_43 ) ) {
F_50 ( V_4 -> V_79 ) ;
V_4 -> V_79 = NULL ;
return - V_34 ;
}
return 0 ;
}
static int F_55 ( struct V_3 * V_4 )
{
if ( F_56 ( V_4 , V_80 ) ||
F_56 ( V_4 , V_81 ) & V_82 ) {
F_57 ( V_4 ) ;
F_58 ( V_4 ) ;
F_34 ( F_16 ( V_4 ) ,
L_5 ,
V_33 , __LINE__ , V_4 -> V_83 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_59 ( struct V_3 * V_4 )
{
if ( V_85 == V_4 -> V_86 )
F_60 ( V_4 ) ;
F_57 ( V_4 ) ;
F_58 ( V_4 ) ;
F_26 ( V_4 , V_87 , 0 ) ;
F_61 ( V_4 ) ;
V_4 -> V_24 = F_56 ( V_4 , V_88 ) ;
V_4 -> V_5 = V_4 -> V_24 ;
V_4 -> V_50 = 0 ;
F_62 ( V_4 ) ;
F_63 ( V_4 ) ;
return F_55 ( V_4 ) ;
}
static void F_64 ( struct V_3 * V_4 )
{
F_57 ( V_4 ) ;
F_58 ( V_4 ) ;
}
static void F_65 ( struct V_89 * V_90 )
{
F_66 ( & V_90 -> V_91 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
V_4 -> V_27 =
F_68 ( V_4 ) -> F_69 ( F_43 ( V_4 ) ,
F_40 , F_39 ,
L_6 , V_4 , V_4 -> V_83 ) ;
if ( F_70 ( V_4 -> V_27 ) )
return F_71 ( V_4 -> V_27 ) ;
return 0 ;
}
static inline void F_72 ( struct V_3 * V_4 )
{
F_68 ( V_4 ) -> F_73 ( F_43 ( V_4 ) , V_4 -> V_27 , V_4 ) ;
}
static int F_74 ( struct V_3 * V_4 )
{
int V_41 = F_42 ( V_4 ) ;
if ( V_41 )
goto V_92;
V_41 = F_54 ( V_4 ) ;
if ( V_41 )
goto V_93;
V_41 = F_59 ( V_4 ) ;
if ( V_41 )
goto V_94;
return V_41 ;
V_94:
F_53 ( V_4 ) ;
V_93:
F_51 ( V_4 ) ;
V_92:
return V_41 ;
}
static int F_75 ( struct V_3 * V_4 )
{
struct V_21 * V_22 ;
int V_95 = 0 ;
T_5 V_27 ;
V_22 = F_35 ( & V_4 -> V_55 , 0 , 0 , 0 , V_45 ) ;
if ( ! V_22 ) {
V_95 = - V_34 ;
goto error;
}
V_27 = V_22 -> V_59 ( V_22 ) ;
if ( F_76 ( V_27 ) )
V_95 = - V_34 ;
else
V_95 = F_77 ( & V_4 -> V_55 , V_27 ) ;
if ( V_95 ) {
F_34 ( F_16 ( V_4 ) , L_7 ,
V_33 , __LINE__ , V_4 -> V_83 ) ;
V_95 = - V_96 ;
}
error:
F_6 ( V_4 ) ;
return V_95 ;
}
static inline void F_78 ( struct V_3 * V_4 )
{
F_64 ( V_4 ) ;
F_6 ( V_4 ) ;
F_53 ( V_4 ) ;
F_51 ( V_4 ) ;
}
static int F_79 ( struct V_89 * V_90 ,
enum V_97 V_86 )
{
int V_98 , V_99 = V_90 -> V_100 ;
struct V_3 * V_4 ;
int V_41 ;
for ( V_98 = V_99 ; V_98 < V_99 + V_101 ; V_98 ++ ) {
unsigned long V_17 ;
V_4 = & V_90 -> V_48 [ V_98 ] ;
V_17 = ( unsigned long ) V_4 ;
V_4 -> V_83 = V_98 ;
V_4 -> V_86 = V_86 ;
F_80 ( & V_4 -> V_25 ) ;
F_80 ( & V_4 -> V_57 ) ;
F_80 ( & V_4 -> V_49 ) ;
V_41 = F_67 ( V_4 ) ;
if ( V_41 )
goto error;
}
return 0 ;
error:
for ( V_98 = V_98 - 1 ; V_98 >= V_99 ; V_98 -- )
F_72 ( V_4 ) ;
return V_41 ;
}
static void F_81 ( struct V_89 * V_90 )
{
int V_98 , V_99 = V_90 -> V_100 ;
struct V_3 * V_4 ;
for ( V_98 = V_99 ; V_98 < V_99 + V_101 ; V_98 ++ ) {
V_4 = & V_90 -> V_48 [ V_98 ] ;
F_72 ( V_4 ) ;
}
}
static int F_82 ( struct V_47 * V_4 )
{
int V_41 = F_74 ( F_24 ( V_4 ) ) ;
if ( V_41 )
return V_41 ;
return V_2 ;
}
static void F_83 ( struct V_47 * V_4 )
{
struct V_3 * V_48 = F_24 ( V_4 ) ;
F_75 ( V_48 ) ;
F_78 ( V_48 ) ;
}
static int F_84 ( struct V_89 * V_90 ,
enum V_97 V_86 )
{
int V_98 , V_99 = V_90 -> V_100 ;
F_85 ( V_90 -> V_91 . V_102 ) ;
F_86 ( V_103 , V_90 -> V_91 . V_102 ) ;
if ( V_104 == V_86 )
F_86 ( V_105 , V_90 -> V_91 . V_102 ) ;
V_90 -> V_91 . V_106 =
F_82 ;
V_90 -> V_91 . V_107 =
F_83 ;
V_90 -> V_91 . V_108 = F_37 ;
V_90 -> V_91 . V_109 = F_35 ;
V_90 -> V_91 . V_110 =
F_33 ;
V_90 -> V_91 . V_111 =
F_36 ;
V_90 -> V_91 . V_112 = F_23 ;
V_90 -> V_91 . V_113 = V_13 ;
F_87 ( & V_90 -> V_91 . V_114 ) ;
for ( V_98 = V_99 ; V_98 < V_99 + V_101 ; V_98 ++ ) {
V_90 -> V_48 [ V_98 ] . V_55 . V_31 = & V_90 -> V_91 ;
F_88 ( & V_90 -> V_48 [ V_98 ] . V_55 ) ;
F_89 ( & V_90 -> V_48 [ V_98 ] . V_55 . V_115 ,
& V_90 -> V_91 . V_114 ) ;
}
return F_90 ( & V_90 -> V_91 ) ;
}
static struct V_89 * F_91 ( struct V_116 * V_117 ,
enum V_97 V_86 )
{
struct V_89 * V_90 ;
int V_41 ;
struct V_31 * V_32 = & V_117 -> V_32 ;
V_90 = F_45 ( sizeof( * V_90 ) , V_73 ) ;
if ( ! V_90 ) {
V_41 = - V_34 ;
goto V_118;
}
V_90 -> V_117 = V_117 ;
V_90 -> V_91 . V_32 = V_32 ;
V_90 -> V_119 = V_117 -> V_120 ;
if ( V_104 == V_86 ) {
V_90 -> V_100 = 0 ;
V_90 -> V_39 = V_121 ;
} else {
V_90 -> V_100 = 4 ;
V_90 -> V_39 = V_122 ;
}
V_41 = F_79 ( V_90 , V_86 ) ;
if ( V_41 )
goto V_123;
V_41 = F_84 ( V_90 , V_86 ) ;
if ( V_41 )
goto V_124;
return V_90 ;
V_124:
F_81 ( V_90 ) ;
V_123:
F_50 ( V_90 ) ;
V_90 = NULL ;
V_118:
F_34 ( V_32 , L_8 , V_33 , __LINE__ , V_41 ) ;
return V_90 ;
}
static void F_92 ( struct V_89 * V_90 )
{
F_65 ( V_90 ) ;
F_81 ( V_90 ) ;
F_50 ( V_90 ) ;
}
static int F_93 ( struct V_125 * V_126 , void * V_127 )
{
struct V_89 * V_90 = V_126 -> V_128 ;
int V_98 , V_129 , V_99 = V_90 -> V_100 ;
struct V_3 * V_4 ;
F_94 ( V_126 , L_9 ,
F_95 ( & V_90 -> V_48 [ V_99 ] ,
V_130 + V_131 ) ) ;
F_96 ( V_126 , L_10 ) ;
F_94 ( V_126 , L_11 ,
L_12 , L_13 , L_14 , L_15 , L_16 , L_17 ) ;
F_94 ( V_126 , L_18 , L_19 , L_20 , L_21 ) ;
for ( V_98 = V_99 ; V_98 < V_99 + V_101 ; V_98 ++ ) {
V_4 = & V_90 -> V_48 [ V_98 ] ;
V_129 = V_4 -> V_83 ;
F_94 ( V_126 , L_22 ,
V_129 ,
F_56 ( V_4 , V_132 ) ,
F_56 ( V_4 , V_88 ) ,
F_56 ( V_4 , V_53 ) ,
F_56 ( V_4 , V_133 ) ) ;
F_94 ( V_126 , L_23 ,
F_56 ( V_4 , V_134 ) ,
F_56 ( V_4 , V_80 ) ,
F_56 ( V_4 , V_87 ) ,
F_56 ( V_4 , V_81 ) ) ;
}
return 0 ;
}
static int F_97 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
return F_98 ( V_136 , F_93 , V_135 -> V_137 ) ;
}
static int F_99 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
return F_100 ( V_135 , V_136 ) ;
}
static int F_101 ( struct V_116 * V_117 )
{
struct V_89 * V_90 ;
enum V_97 V_86 ;
if ( V_138 == V_117 -> V_139 . V_31 )
V_86 = V_85 ;
else
V_86 = V_104 ;
V_90 = F_91 ( V_117 , V_86 ) ;
F_102 ( & V_117 -> V_32 , V_90 ) ;
if ( V_140 ) {
V_90 -> V_141 = F_103 ( F_104 ( & V_117 -> V_32 ) ,
V_140 ) ;
if ( V_90 -> V_141 )
F_105 ( L_24 , 0444 ,
V_90 -> V_141 , V_90 ,
& V_142 ) ;
}
return 0 ;
}
static void F_106 ( struct V_116 * V_117 )
{
struct V_89 * V_90 ;
V_90 = F_107 ( & V_117 -> V_32 ) ;
F_108 ( V_90 -> V_141 ) ;
F_92 ( V_90 ) ;
}
static int T_7 F_109 ( void )
{
int V_143 = F_110 ( & V_144 ) ;
if ( V_143 )
return V_143 ;
V_140 = F_103 ( V_145 , NULL ) ;
return 0 ;
}
static void T_8 F_111 ( void )
{
F_108 ( V_140 ) ;
F_112 ( & V_144 ) ;
}
