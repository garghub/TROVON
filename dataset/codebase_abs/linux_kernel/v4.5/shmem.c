static unsigned long F_1 ( void )
{
return V_1 / 2 ;
}
static unsigned long F_2 ( void )
{
return F_3 ( V_1 - V_2 , V_1 / 2 ) ;
}
static inline int F_4 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 , int * V_9 )
{
return F_5 ( V_3 , V_4 , V_6 , V_8 ,
F_6 ( V_3 -> V_10 ) , V_9 ) ;
}
static inline struct V_11 * F_7 ( struct V_12 * V_13 )
{
return V_13 -> V_14 ;
}
static inline int F_8 ( unsigned long V_15 , T_2 V_16 )
{
return ( V_15 & V_17 ) ?
0 : F_9 ( V_18 -> V_19 , F_10 ( V_16 ) ) ;
}
static inline void F_11 ( unsigned long V_15 , T_2 V_16 )
{
if ( ! ( V_15 & V_17 ) )
F_12 ( F_10 ( V_16 ) ) ;
}
static inline int F_13 ( unsigned long V_15 ,
T_2 V_20 , T_2 V_21 )
{
if ( ! ( V_15 & V_17 ) ) {
if ( F_10 ( V_21 ) > F_10 ( V_20 ) )
return F_9 ( V_18 -> V_19 ,
F_10 ( V_21 ) - F_10 ( V_20 ) ) ;
else if ( F_10 ( V_21 ) < F_10 ( V_20 ) )
F_12 ( F_10 ( V_20 ) - F_10 ( V_21 ) ) ;
}
return 0 ;
}
static inline int F_14 ( unsigned long V_15 )
{
return ( V_15 & V_17 ) ?
F_9 ( V_18 -> V_19 , F_10 ( V_22 ) ) : 0 ;
}
static inline void F_15 ( unsigned long V_15 , long V_23 )
{
if ( V_15 & V_17 )
F_12 ( V_23 * F_10 ( V_22 ) ) ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_11 * V_24 = F_7 ( V_13 ) ;
if ( V_24 -> V_25 ) {
F_17 ( & V_24 -> V_26 ) ;
if ( ! V_24 -> V_27 ) {
F_18 ( & V_24 -> V_26 ) ;
return - V_28 ;
}
V_24 -> V_27 -- ;
F_18 ( & V_24 -> V_26 ) ;
}
return 0 ;
}
static void F_19 ( struct V_12 * V_13 )
{
struct V_11 * V_24 = F_7 ( V_13 ) ;
if ( V_24 -> V_25 ) {
F_17 ( & V_24 -> V_26 ) ;
V_24 -> V_27 ++ ;
F_18 ( & V_24 -> V_26 ) ;
}
}
static void F_20 ( struct V_3 * V_3 )
{
struct V_29 * V_30 = F_21 ( V_3 ) ;
long V_31 ;
V_31 = V_30 -> V_32 - V_30 -> V_33 - V_3 -> V_10 -> V_34 ;
if ( V_31 > 0 ) {
struct V_11 * V_24 = F_7 ( V_3 -> V_35 ) ;
if ( V_24 -> V_36 )
F_22 ( & V_24 -> V_37 , - V_31 ) ;
V_30 -> V_32 -= V_31 ;
V_3 -> V_38 -= V_31 * V_39 ;
F_15 ( V_30 -> V_15 , V_31 ) ;
}
}
static int F_23 ( struct V_40 * V_41 ,
T_1 V_4 , void * V_42 , void * V_43 )
{
void * * V_44 ;
void * V_45 ;
F_24 ( ! V_42 ) ;
F_24 ( ! V_43 ) ;
V_44 = F_25 ( & V_41 -> V_46 , V_4 ) ;
if ( ! V_44 )
return - V_47 ;
V_45 = F_26 ( V_44 , & V_41 -> V_48 ) ;
if ( V_45 != V_42 )
return - V_47 ;
F_27 ( V_44 , V_43 ) ;
return 0 ;
}
static bool F_28 ( struct V_40 * V_41 ,
T_1 V_4 , T_3 V_49 )
{
void * V_45 ;
F_29 () ;
V_45 = F_30 ( & V_41 -> V_46 , V_4 ) ;
F_31 () ;
return V_45 == F_32 ( V_49 ) ;
}
static int F_33 ( struct V_5 * V_5 ,
struct V_40 * V_41 ,
T_1 V_4 , void * V_42 )
{
int error ;
F_34 ( ! F_35 ( V_5 ) , V_5 ) ;
F_34 ( ! F_36 ( V_5 ) , V_5 ) ;
F_37 ( V_5 ) ;
V_5 -> V_41 = V_41 ;
V_5 -> V_4 = V_4 ;
F_38 ( & V_41 -> V_48 ) ;
if ( ! V_42 )
error = F_39 ( & V_41 -> V_46 , V_4 , V_5 ) ;
else
error = F_23 ( V_41 , V_4 , V_42 ,
V_5 ) ;
if ( ! error ) {
V_41 -> V_34 ++ ;
F_40 ( V_5 , V_50 ) ;
F_40 ( V_5 , V_51 ) ;
F_41 ( & V_41 -> V_48 ) ;
} else {
V_5 -> V_41 = NULL ;
F_41 ( & V_41 -> V_48 ) ;
F_42 ( V_5 ) ;
}
return error ;
}
static void F_43 ( struct V_5 * V_5 , void * V_52 )
{
struct V_40 * V_41 = V_5 -> V_41 ;
int error ;
F_38 ( & V_41 -> V_48 ) ;
error = F_23 ( V_41 , V_5 -> V_4 , V_5 , V_52 ) ;
V_5 -> V_41 = NULL ;
V_41 -> V_34 -- ;
F_44 ( V_5 , V_50 ) ;
F_44 ( V_5 , V_51 ) ;
F_41 ( & V_41 -> V_48 ) ;
F_42 ( V_5 ) ;
F_45 ( error ) ;
}
static int F_46 ( struct V_40 * V_41 ,
T_1 V_4 , void * V_52 )
{
void * V_53 ;
F_38 ( & V_41 -> V_48 ) ;
V_53 = F_47 ( & V_41 -> V_46 , V_4 , V_52 ) ;
F_41 ( & V_41 -> V_48 ) ;
if ( V_53 != V_52 )
return - V_47 ;
F_48 ( F_49 ( V_52 ) ) ;
return 0 ;
}
unsigned long F_50 ( struct V_40 * V_41 ,
T_1 V_54 , T_1 V_55 )
{
struct V_56 V_57 ;
void * * V_58 ;
struct V_5 * V_5 ;
unsigned long V_33 = 0 ;
F_29 () ;
V_59:
F_51 (slot, &mapping->page_tree, &iter, start) {
if ( V_57 . V_4 >= V_55 )
break;
V_5 = F_52 ( V_58 ) ;
if ( F_53 ( V_5 ) )
goto V_59;
if ( F_54 ( V_5 ) )
V_33 ++ ;
if ( F_55 () ) {
F_56 () ;
V_54 = V_57 . V_4 + 1 ;
goto V_59;
}
}
F_31 () ;
return V_33 << V_60 ;
}
unsigned long F_57 ( struct V_61 * V_62 )
{
struct V_3 * V_3 = F_58 ( V_62 -> V_63 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
struct V_40 * V_41 = V_3 -> V_10 ;
unsigned long V_33 ;
V_33 = F_59 ( V_30 -> V_33 ) ;
if ( ! V_33 )
return 0 ;
if ( ! V_62 -> V_64 && V_62 -> V_65 - V_62 -> V_66 >= V_3 -> V_67 )
return V_33 << V_60 ;
return F_50 ( V_41 ,
F_60 ( V_62 , V_62 -> V_66 ) ,
F_60 ( V_62 , V_62 -> V_65 ) ) ;
}
void F_61 ( struct V_40 * V_41 )
{
struct V_68 V_69 ;
T_1 V_70 [ V_71 ] ;
T_1 V_4 = 0 ;
F_62 ( & V_69 , 0 ) ;
while ( ! F_63 ( V_41 ) ) {
V_69 . V_72 = F_64 ( V_41 , V_4 ,
V_71 , V_69 . V_23 , V_70 ) ;
if ( ! V_69 . V_72 )
break;
V_4 = V_70 [ V_69 . V_72 - 1 ] + 1 ;
F_65 ( & V_69 ) ;
F_66 ( V_69 . V_23 , V_69 . V_72 ) ;
F_67 ( & V_69 ) ;
F_68 () ;
}
}
static void F_69 ( struct V_3 * V_3 , T_2 V_73 , T_2 V_74 ,
bool V_75 )
{
struct V_40 * V_41 = V_3 -> V_10 ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
T_1 V_54 = ( V_73 + V_22 - 1 ) >> V_76 ;
T_1 V_55 = ( V_74 + 1 ) >> V_76 ;
unsigned int V_77 = V_73 & ( V_22 - 1 ) ;
unsigned int V_78 = ( V_74 + 1 ) & ( V_22 - 1 ) ;
struct V_68 V_69 ;
T_1 V_70 [ V_71 ] ;
long V_79 = 0 ;
T_1 V_4 ;
int V_80 ;
if ( V_74 == - 1 )
V_55 = - 1 ;
F_62 ( & V_69 , 0 ) ;
V_4 = V_54 ;
while ( V_4 < V_55 ) {
V_69 . V_72 = F_64 ( V_41 , V_4 ,
F_3 ( V_55 - V_4 , ( T_1 ) V_71 ) ,
V_69 . V_23 , V_70 ) ;
if ( ! V_69 . V_72 )
break;
for ( V_80 = 0 ; V_80 < F_70 ( & V_69 ) ; V_80 ++ ) {
struct V_5 * V_5 = V_69 . V_23 [ V_80 ] ;
V_4 = V_70 [ V_80 ] ;
if ( V_4 >= V_55 )
break;
if ( F_54 ( V_5 ) ) {
if ( V_75 )
continue;
V_79 += ! F_46 ( V_41 ,
V_4 , V_5 ) ;
continue;
}
if ( ! F_71 ( V_5 ) )
continue;
if ( ! V_75 || ! F_72 ( V_5 ) ) {
if ( V_5 -> V_41 == V_41 ) {
F_34 ( F_73 ( V_5 ) , V_5 ) ;
F_74 ( V_41 , V_5 ) ;
}
}
F_75 ( V_5 ) ;
}
F_65 ( & V_69 ) ;
F_67 ( & V_69 ) ;
F_68 () ;
V_4 ++ ;
}
if ( V_77 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_54 - 1 , & V_5 , V_81 , NULL ) ;
if ( V_5 ) {
unsigned int V_82 = V_22 ;
if ( V_54 > V_55 ) {
V_82 = V_78 ;
V_78 = 0 ;
}
F_76 ( V_5 , V_77 , V_82 ) ;
F_77 ( V_5 ) ;
F_75 ( V_5 ) ;
F_42 ( V_5 ) ;
}
}
if ( V_78 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_55 , & V_5 , V_81 , NULL ) ;
if ( V_5 ) {
F_76 ( V_5 , 0 , V_78 ) ;
F_77 ( V_5 ) ;
F_75 ( V_5 ) ;
F_42 ( V_5 ) ;
}
}
if ( V_54 >= V_55 )
return;
V_4 = V_54 ;
while ( V_4 < V_55 ) {
F_68 () ;
V_69 . V_72 = F_64 ( V_41 , V_4 ,
F_3 ( V_55 - V_4 , ( T_1 ) V_71 ) ,
V_69 . V_23 , V_70 ) ;
if ( ! V_69 . V_72 ) {
if ( V_4 == V_54 || V_55 != - 1 )
break;
V_4 = V_54 ;
continue;
}
for ( V_80 = 0 ; V_80 < F_70 ( & V_69 ) ; V_80 ++ ) {
struct V_5 * V_5 = V_69 . V_23 [ V_80 ] ;
V_4 = V_70 [ V_80 ] ;
if ( V_4 >= V_55 )
break;
if ( F_54 ( V_5 ) ) {
if ( V_75 )
continue;
if ( F_46 ( V_41 , V_4 , V_5 ) ) {
V_4 -- ;
break;
}
V_79 ++ ;
continue;
}
F_78 ( V_5 ) ;
if ( ! V_75 || ! F_72 ( V_5 ) ) {
if ( V_5 -> V_41 == V_41 ) {
F_34 ( F_73 ( V_5 ) , V_5 ) ;
F_74 ( V_41 , V_5 ) ;
} else {
F_75 ( V_5 ) ;
V_4 -- ;
break;
}
}
F_75 ( V_5 ) ;
}
F_65 ( & V_69 ) ;
F_67 ( & V_69 ) ;
V_4 ++ ;
}
F_17 ( & V_30 -> V_83 ) ;
V_30 -> V_33 -= V_79 ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_83 ) ;
}
void F_79 ( struct V_3 * V_3 , T_2 V_73 , T_2 V_74 )
{
F_69 ( V_3 , V_73 , V_74 , false ) ;
V_3 -> V_84 = V_3 -> V_85 = V_86 ;
}
static int F_80 ( struct V_87 * V_88 , struct V_89 * V_89 ,
struct V_90 * V_91 )
{
struct V_3 * V_3 = V_89 -> V_92 ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
if ( V_30 -> V_32 - V_30 -> V_33 != V_3 -> V_10 -> V_34 ) {
F_17 ( & V_30 -> V_83 ) ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_83 ) ;
}
F_81 ( V_3 , V_91 ) ;
return 0 ;
}
static int F_82 ( struct V_89 * V_89 , struct V_93 * V_94 )
{
struct V_3 * V_3 = V_92 ( V_89 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
int error ;
error = F_83 ( V_3 , V_94 ) ;
if ( error )
return error ;
if ( F_84 ( V_3 -> V_95 ) && ( V_94 -> V_96 & V_97 ) ) {
T_2 V_20 = V_3 -> V_67 ;
T_2 V_21 = V_94 -> V_98 ;
if ( ( V_21 < V_20 && ( V_30 -> V_99 & V_100 ) ) ||
( V_21 > V_20 && ( V_30 -> V_99 & V_101 ) ) )
return - V_102 ;
if ( V_21 != V_20 ) {
error = F_13 ( F_21 ( V_3 ) -> V_15 ,
V_20 , V_21 ) ;
if ( error )
return error ;
F_85 ( V_3 , V_21 ) ;
V_3 -> V_84 = V_3 -> V_85 = V_86 ;
}
if ( V_21 <= V_20 ) {
T_2 V_103 = F_86 ( V_21 , V_104 ) ;
if ( V_20 > V_103 )
F_87 ( V_3 -> V_10 ,
V_103 , 0 , 1 ) ;
if ( V_30 -> V_32 )
F_79 ( V_3 ,
V_21 , ( T_2 ) - 1 ) ;
if ( V_20 > V_103 )
F_87 ( V_3 -> V_10 ,
V_103 , 0 , 1 ) ;
}
}
F_88 ( V_3 , V_94 ) ;
if ( V_94 -> V_96 & V_105 )
error = F_89 ( V_3 , V_3 -> V_95 ) ;
return error ;
}
static void F_90 ( struct V_3 * V_3 )
{
struct V_29 * V_30 = F_21 ( V_3 ) ;
if ( V_3 -> V_10 -> V_106 == & V_107 ) {
F_11 ( V_30 -> V_15 , V_3 -> V_67 ) ;
V_3 -> V_67 = 0 ;
F_79 ( V_3 , 0 , ( T_2 ) - 1 ) ;
if ( ! F_91 ( & V_30 -> V_108 ) ) {
F_92 ( & V_109 ) ;
F_93 ( & V_30 -> V_108 ) ;
F_94 ( & V_109 ) ;
}
}
F_95 ( & V_30 -> V_110 ) ;
F_96 ( V_3 -> V_38 ) ;
F_19 ( V_3 -> V_35 ) ;
F_97 ( V_3 ) ;
}
static int F_98 ( struct V_29 * V_30 ,
T_3 V_49 , struct V_5 * * V_6 )
{
struct V_40 * V_41 = V_30 -> V_111 . V_10 ;
void * V_52 ;
T_1 V_4 ;
T_4 V_112 ;
int error = 0 ;
V_52 = F_32 ( V_49 ) ;
V_4 = F_99 ( & V_41 -> V_46 , V_52 ) ;
if ( V_4 == - 1 )
return - V_113 ;
if ( V_114 . V_115 != & V_30 -> V_108 )
F_100 ( & V_114 , & V_30 -> V_108 ) ;
V_112 = F_6 ( V_41 ) ;
if ( F_101 ( * V_6 , V_112 ) ) {
F_94 ( & V_109 ) ;
error = F_102 ( V_6 , V_112 , V_30 , V_4 ) ;
F_92 ( & V_109 ) ;
if ( ! F_103 ( * V_6 ) )
error = - V_47 ;
}
if ( ! error )
error = F_33 ( * V_6 , V_41 , V_4 ,
V_52 ) ;
if ( error != - V_116 ) {
F_104 ( * V_6 ) ;
F_77 ( * V_6 ) ;
if ( ! error ) {
F_17 ( & V_30 -> V_83 ) ;
V_30 -> V_33 -- ;
F_18 ( & V_30 -> V_83 ) ;
F_105 ( V_49 ) ;
}
}
return error ;
}
int F_106 ( T_3 V_49 , struct V_5 * V_5 )
{
struct V_117 * V_118 , * V_115 ;
struct V_29 * V_30 ;
struct V_119 * V_120 ;
int error = 0 ;
if ( F_107 ( ! F_108 ( V_5 ) || F_109 ( V_5 ) != V_49 . V_121 ) )
goto V_122;
error = F_110 ( V_5 , V_18 -> V_19 , V_123 , & V_120 ,
false ) ;
if ( error )
goto V_122;
error = - V_113 ;
F_92 ( & V_109 ) ;
F_111 (this, next, &shmem_swaplist) {
V_30 = F_112 ( V_118 , struct V_29 , V_108 ) ;
if ( V_30 -> V_33 )
error = F_98 ( V_30 , V_49 , & V_5 ) ;
else
F_93 ( & V_30 -> V_108 ) ;
F_68 () ;
if ( error != - V_113 )
break;
}
F_94 ( & V_109 ) ;
if ( error ) {
if ( error != - V_116 )
error = 0 ;
F_113 ( V_5 , V_120 , false ) ;
} else
F_114 ( V_5 , V_120 , true , false ) ;
V_122:
F_75 ( V_5 ) ;
F_42 ( V_5 ) ;
return error ;
}
static int F_115 ( struct V_5 * V_5 , struct V_124 * V_125 )
{
struct V_29 * V_30 ;
struct V_40 * V_41 ;
struct V_3 * V_3 ;
T_3 V_49 ;
T_1 V_4 ;
F_45 ( ! F_35 ( V_5 ) ) ;
V_41 = V_5 -> V_41 ;
V_4 = V_5 -> V_4 ;
V_3 = V_41 -> V_126 ;
V_30 = F_21 ( V_3 ) ;
if ( V_30 -> V_15 & V_127 )
goto V_128;
if ( ! V_129 )
goto V_128;
if ( ! V_125 -> V_130 ) {
F_116 ( 1 ) ;
goto V_128;
}
if ( ! F_72 ( V_5 ) ) {
if ( V_3 -> V_131 ) {
struct V_132 * V_132 ;
F_17 ( & V_3 -> V_133 ) ;
V_132 = V_3 -> V_131 ;
if ( V_132 &&
! V_132 -> V_134 &&
V_4 >= V_132 -> V_54 &&
V_4 < V_132 -> V_115 )
V_132 -> V_135 ++ ;
else
V_132 = NULL ;
F_18 ( & V_3 -> V_133 ) ;
if ( V_132 )
goto V_128;
}
F_117 ( V_5 ) ;
F_118 ( V_5 ) ;
F_119 ( V_5 ) ;
}
V_49 = F_120 () ;
if ( ! V_49 . V_121 )
goto V_128;
if ( F_121 ( V_5 , V_49 ) )
goto V_136;
F_92 ( & V_109 ) ;
if ( F_91 ( & V_30 -> V_108 ) )
F_122 ( & V_30 -> V_108 , & V_114 ) ;
if ( F_123 ( V_5 , V_49 , V_137 ) == 0 ) {
F_17 ( & V_30 -> V_83 ) ;
F_20 ( V_3 ) ;
V_30 -> V_33 ++ ;
F_18 ( & V_30 -> V_83 ) ;
F_124 ( V_49 ) ;
F_43 ( V_5 , F_32 ( V_49 ) ) ;
F_94 ( & V_109 ) ;
F_45 ( F_125 ( V_5 ) ) ;
F_126 ( V_5 , V_125 ) ;
return 0 ;
}
F_94 ( & V_109 ) ;
V_136:
F_127 ( V_49 ) ;
V_128:
F_77 ( V_5 ) ;
if ( V_125 -> V_130 )
return V_138 ;
F_75 ( V_5 ) ;
return 0 ;
}
static void F_128 ( struct V_139 * V_140 , struct V_141 * V_142 )
{
char V_143 [ 64 ] ;
if ( ! V_142 || V_142 -> V_144 == V_145 )
return;
F_129 ( V_143 , sizeof( V_143 ) , V_142 ) ;
F_130 ( V_140 , L_1 , V_143 ) ;
}
static struct V_141 * F_131 ( struct V_11 * V_24 )
{
struct V_141 * V_142 = NULL ;
if ( V_24 -> V_142 ) {
F_17 ( & V_24 -> V_26 ) ;
V_142 = V_24 -> V_142 ;
F_132 ( V_142 ) ;
F_18 ( & V_24 -> V_26 ) ;
}
return V_142 ;
}
static struct V_5 * F_133 ( T_3 V_49 , T_4 V_112 ,
struct V_29 * V_30 , T_1 V_4 )
{
struct V_61 V_146 ;
struct V_5 * V_5 ;
V_146 . V_66 = 0 ;
V_146 . V_64 = V_4 + V_30 -> V_111 . V_147 ;
V_146 . V_148 = NULL ;
V_146 . V_149 = F_134 ( & V_30 -> V_150 , V_4 ) ;
V_5 = F_135 ( V_49 , V_112 , & V_146 , 0 ) ;
F_136 ( V_146 . V_149 ) ;
return V_5 ;
}
static struct V_5 * F_137 ( T_4 V_112 ,
struct V_29 * V_30 , T_1 V_4 )
{
struct V_61 V_146 ;
struct V_5 * V_5 ;
V_146 . V_66 = 0 ;
V_146 . V_64 = V_4 + V_30 -> V_111 . V_147 ;
V_146 . V_148 = NULL ;
V_146 . V_149 = F_134 ( & V_30 -> V_150 , V_4 ) ;
V_5 = F_138 ( V_112 , & V_146 , 0 ) ;
F_136 ( V_146 . V_149 ) ;
return V_5 ;
}
static inline void F_128 ( struct V_139 * V_140 , struct V_141 * V_142 )
{
}
static inline struct V_5 * F_133 ( T_3 V_49 , T_4 V_112 ,
struct V_29 * V_30 , T_1 V_4 )
{
return F_135 ( V_49 , V_112 , NULL , 0 ) ;
}
static inline struct V_5 * F_137 ( T_4 V_112 ,
struct V_29 * V_30 , T_1 V_4 )
{
return F_139 ( V_112 ) ;
}
static inline struct V_141 * F_131 ( struct V_11 * V_24 )
{
return NULL ;
}
static bool F_101 ( struct V_5 * V_5 , T_4 V_112 )
{
return F_140 ( V_5 ) > F_141 ( V_112 ) ;
}
static int F_102 ( struct V_5 * * V_6 , T_4 V_112 ,
struct V_29 * V_30 , T_1 V_4 )
{
struct V_5 * V_151 , * V_152 ;
struct V_40 * V_153 ;
T_1 V_154 ;
int error ;
V_151 = * V_6 ;
V_154 = F_109 ( V_151 ) ;
V_153 = F_142 ( V_151 ) ;
V_112 &= ~ V_155 ;
V_152 = F_137 ( V_112 , V_30 , V_4 ) ;
if ( ! V_152 )
return - V_116 ;
F_37 ( V_152 ) ;
F_143 ( V_152 , V_151 ) ;
F_118 ( V_152 ) ;
F_144 ( V_152 ) ;
F_119 ( V_152 ) ;
F_145 ( V_152 ) ;
F_146 ( V_152 , V_154 ) ;
F_147 ( V_152 ) ;
F_38 ( & V_153 -> V_48 ) ;
error = F_23 ( V_153 , V_154 , V_151 ,
V_152 ) ;
if ( ! error ) {
F_40 ( V_152 , V_50 ) ;
F_44 ( V_151 , V_50 ) ;
}
F_41 ( & V_153 -> V_48 ) ;
if ( F_107 ( error ) ) {
V_151 = V_152 ;
} else {
F_148 ( V_151 , V_152 ) ;
F_149 ( V_152 ) ;
* V_6 = V_152 ;
}
F_150 ( V_151 ) ;
F_146 ( V_151 , 0 ) ;
F_75 ( V_151 ) ;
F_42 ( V_151 ) ;
F_42 ( V_151 ) ;
return error ;
}
static int F_5 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 , T_4 V_112 , int * V_9 )
{
struct V_40 * V_41 = V_3 -> V_10 ;
struct V_29 * V_30 ;
struct V_11 * V_24 ;
struct V_119 * V_120 ;
struct V_5 * V_5 ;
T_3 V_49 ;
int error ;
int V_156 = 0 ;
int V_32 = 0 ;
if ( V_4 > ( V_157 >> V_76 ) )
return - V_158 ;
V_159:
V_49 . V_121 = 0 ;
V_5 = F_151 ( V_41 , V_4 ) ;
if ( F_54 ( V_5 ) ) {
V_49 = F_49 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_8 != V_160 && V_8 != V_161 &&
( ( T_2 ) V_4 << V_76 ) >= F_152 ( V_3 ) ) {
error = - V_162 ;
goto V_163;
}
if ( V_5 && V_8 == V_160 )
F_153 ( V_5 ) ;
if ( V_5 && ! F_72 ( V_5 ) ) {
if ( V_8 != V_81 )
goto V_164;
F_75 ( V_5 ) ;
F_42 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 || ( V_8 == V_81 && ! V_49 . V_121 ) ) {
* V_6 = V_5 ;
return 0 ;
}
V_30 = F_21 ( V_3 ) ;
V_24 = F_7 ( V_3 -> V_35 ) ;
if ( V_49 . V_121 ) {
V_5 = F_154 ( V_49 ) ;
if ( ! V_5 ) {
if ( V_9 )
* V_9 |= V_165 ;
V_5 = F_133 ( V_49 , V_112 , V_30 , V_4 ) ;
if ( ! V_5 ) {
error = - V_116 ;
goto V_166;
}
}
F_78 ( V_5 ) ;
if ( ! F_108 ( V_5 ) || F_109 ( V_5 ) != V_49 . V_121 ||
! F_28 ( V_41 , V_4 , V_49 ) ) {
error = - V_167 ;
goto V_163;
}
if ( ! F_72 ( V_5 ) ) {
error = - V_168 ;
goto V_166;
}
F_155 ( V_5 ) ;
if ( F_101 ( V_5 , V_112 ) ) {
error = F_102 ( & V_5 , V_112 , V_30 , V_4 ) ;
if ( error )
goto V_166;
}
error = F_110 ( V_5 , V_18 -> V_19 , V_112 , & V_120 ,
false ) ;
if ( ! error ) {
error = F_33 ( V_5 , V_41 , V_4 ,
F_32 ( V_49 ) ) ;
if ( error ) {
F_113 ( V_5 , V_120 , false ) ;
F_104 ( V_5 ) ;
}
}
if ( error )
goto V_166;
F_114 ( V_5 , V_120 , true , false ) ;
F_17 ( & V_30 -> V_83 ) ;
V_30 -> V_33 -- ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_83 ) ;
if ( V_8 == V_160 )
F_153 ( V_5 ) ;
F_104 ( V_5 ) ;
F_77 ( V_5 ) ;
F_105 ( V_49 ) ;
} else {
if ( F_14 ( V_30 -> V_15 ) ) {
error = - V_28 ;
goto V_166;
}
if ( V_24 -> V_36 ) {
if ( F_156 ( & V_24 -> V_37 ,
V_24 -> V_36 ) >= 0 ) {
error = - V_28 ;
goto V_169;
}
F_157 ( & V_24 -> V_37 ) ;
}
V_5 = F_137 ( V_112 , V_30 , V_4 ) ;
if ( ! V_5 ) {
error = - V_116 ;
goto V_170;
}
F_158 ( V_5 ) ;
F_144 ( V_5 ) ;
if ( V_8 == V_160 )
F_159 ( V_5 ) ;
error = F_110 ( V_5 , V_18 -> V_19 , V_112 , & V_120 ,
false ) ;
if ( error )
goto V_170;
error = F_160 ( V_112 & V_171 ) ;
if ( ! error ) {
error = F_33 ( V_5 , V_41 , V_4 ,
NULL ) ;
F_161 () ;
}
if ( error ) {
F_113 ( V_5 , V_120 , false ) ;
goto V_170;
}
F_114 ( V_5 , V_120 , false , false ) ;
F_149 ( V_5 ) ;
F_17 ( & V_30 -> V_83 ) ;
V_30 -> V_32 ++ ;
V_3 -> V_38 += V_39 ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_83 ) ;
V_32 = true ;
if ( V_8 == V_161 )
V_8 = V_160 ;
V_164:
if ( V_8 != V_160 ) {
F_117 ( V_5 ) ;
F_118 ( V_5 ) ;
F_119 ( V_5 ) ;
}
if ( V_8 == V_172 )
F_77 ( V_5 ) ;
}
if ( V_8 != V_160 && V_8 != V_161 &&
( ( T_2 ) V_4 << V_76 ) >= F_152 ( V_3 ) ) {
if ( V_32 ) {
F_162 ( V_5 ) ;
F_163 ( V_5 ) ;
F_17 ( & V_30 -> V_83 ) ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_83 ) ;
}
error = - V_162 ;
goto V_163;
}
* V_6 = V_5 ;
return 0 ;
V_170:
if ( V_24 -> V_36 )
F_22 ( & V_24 -> V_37 , - 1 ) ;
V_169:
F_15 ( V_30 -> V_15 , 1 ) ;
V_166:
if ( V_49 . V_121 && ! F_28 ( V_41 , V_4 , V_49 ) )
error = - V_167 ;
V_163:
if ( V_5 ) {
F_75 ( V_5 ) ;
F_42 ( V_5 ) ;
}
if ( error == - V_28 && ! V_156 ++ ) {
V_30 = F_21 ( V_3 ) ;
F_17 ( & V_30 -> V_83 ) ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_83 ) ;
goto V_159;
}
if ( error == - V_167 )
goto V_159;
return error ;
}
static int F_164 ( struct V_61 * V_62 , struct V_173 * V_174 )
{
struct V_3 * V_3 = F_58 ( V_62 -> V_63 ) ;
int error ;
int V_175 = V_176 ;
if ( F_107 ( V_3 -> V_131 ) ) {
struct V_132 * V_132 ;
F_17 ( & V_3 -> V_133 ) ;
V_132 = V_3 -> V_131 ;
if ( V_132 &&
V_132 -> V_134 &&
V_174 -> V_177 >= V_132 -> V_54 &&
V_174 -> V_177 < V_132 -> V_115 ) {
T_5 * V_178 ;
F_165 ( V_179 ) ;
V_175 = V_180 ;
if ( ( V_174 -> V_15 & V_181 ) &&
! ( V_174 -> V_15 & V_182 ) ) {
F_166 ( & V_62 -> V_183 -> V_184 ) ;
V_175 = V_185 ;
}
V_178 = V_132 -> V_134 ;
F_167 ( V_178 , & V_179 ,
V_186 ) ;
F_18 ( & V_3 -> V_133 ) ;
F_168 () ;
F_17 ( & V_3 -> V_133 ) ;
F_169 ( V_178 , & V_179 ) ;
F_18 ( & V_3 -> V_133 ) ;
return V_175 ;
}
F_18 ( & V_3 -> V_133 ) ;
}
error = F_4 ( V_3 , V_174 -> V_177 , & V_174 -> V_5 , V_187 , & V_175 ) ;
if ( error )
return ( ( error == - V_116 ) ? V_188 : V_189 ) ;
if ( V_175 & V_165 ) {
F_170 ( V_190 ) ;
F_171 ( V_62 -> V_183 , V_190 ) ;
}
return V_175 ;
}
static int F_172 ( struct V_61 * V_62 , struct V_141 * V_142 )
{
struct V_3 * V_3 = F_58 ( V_62 -> V_63 ) ;
return F_173 ( & F_21 ( V_3 ) -> V_150 , V_62 , V_142 ) ;
}
static struct V_141 * F_174 ( struct V_61 * V_62 ,
unsigned long V_191 )
{
struct V_3 * V_3 = F_58 ( V_62 -> V_63 ) ;
T_1 V_4 ;
V_4 = ( ( V_191 - V_62 -> V_66 ) >> V_60 ) + V_62 -> V_64 ;
return F_134 ( & F_21 ( V_3 ) -> V_150 , V_4 ) ;
}
int F_175 ( struct V_192 * V_192 , int V_83 , struct V_193 * V_194 )
{
struct V_3 * V_3 = F_58 ( V_192 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
int V_195 = - V_116 ;
F_17 ( & V_30 -> V_83 ) ;
if ( V_83 && ! ( V_30 -> V_15 & V_127 ) ) {
if ( ! F_176 ( V_3 -> V_67 , V_194 ) )
goto V_196;
V_30 -> V_15 |= V_127 ;
F_177 ( V_192 -> V_197 ) ;
}
if ( ! V_83 && ( V_30 -> V_15 & V_127 ) && V_194 ) {
F_178 ( V_3 -> V_67 , V_194 ) ;
V_30 -> V_15 &= ~ V_127 ;
F_179 ( V_192 -> V_197 ) ;
}
V_195 = 0 ;
V_196:
F_18 ( & V_30 -> V_83 ) ;
return V_195 ;
}
static int F_180 ( struct V_192 * V_192 , struct V_61 * V_62 )
{
F_181 ( V_192 ) ;
V_62 -> V_148 = & V_198 ;
return 0 ;
}
static struct V_3 * F_182 ( struct V_12 * V_13 , const struct V_3 * V_199 ,
T_6 V_144 , T_7 V_200 , unsigned long V_15 )
{
struct V_3 * V_3 ;
struct V_29 * V_30 ;
struct V_11 * V_24 = F_7 ( V_13 ) ;
if ( F_16 ( V_13 ) )
return NULL ;
V_3 = F_183 ( V_13 ) ;
if ( V_3 ) {
V_3 -> V_147 = F_184 () ;
F_185 ( V_3 , V_199 , V_144 ) ;
V_3 -> V_38 = 0 ;
V_3 -> V_201 = V_3 -> V_85 = V_3 -> V_84 = V_86 ;
V_3 -> V_202 = F_186 () ;
V_30 = F_21 ( V_3 ) ;
memset ( V_30 , 0 , ( char * ) V_3 - ( char * ) V_30 ) ;
F_187 ( & V_30 -> V_83 ) ;
V_30 -> V_99 = V_203 ;
V_30 -> V_15 = V_15 & V_17 ;
F_188 ( & V_30 -> V_108 ) ;
F_189 ( & V_30 -> V_110 ) ;
F_190 ( V_3 ) ;
switch ( V_144 & V_204 ) {
default:
V_3 -> V_205 = & V_206 ;
F_191 ( V_3 , V_144 , V_200 ) ;
break;
case V_207 :
V_3 -> V_10 -> V_106 = & V_107 ;
V_3 -> V_205 = & V_208 ;
V_3 -> V_209 = & V_210 ;
F_192 ( & V_30 -> V_150 ,
F_131 ( V_24 ) ) ;
break;
case V_211 :
F_193 ( V_3 ) ;
V_3 -> V_67 = 2 * V_212 ;
V_3 -> V_205 = & V_213 ;
V_3 -> V_209 = & V_214 ;
break;
case V_215 :
F_192 ( & V_30 -> V_150 , NULL ) ;
break;
}
} else
F_19 ( V_13 ) ;
return V_3 ;
}
bool F_194 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_126 )
return false ;
return V_41 -> V_126 -> V_35 -> V_216 == & V_217 ;
}
static int
F_195 ( struct V_192 * V_192 , struct V_40 * V_41 ,
T_2 V_218 , unsigned V_219 , unsigned V_15 ,
struct V_5 * * V_6 , void * * V_220 )
{
struct V_3 * V_3 = V_41 -> V_126 ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
T_1 V_4 = V_218 >> V_76 ;
if ( F_107 ( V_30 -> V_99 ) ) {
if ( V_30 -> V_99 & V_221 )
return - V_102 ;
if ( ( V_30 -> V_99 & V_101 ) && V_218 + V_219 > V_3 -> V_67 )
return - V_102 ;
}
return F_4 ( V_3 , V_4 , V_6 , V_160 , NULL ) ;
}
static int
F_196 ( struct V_192 * V_192 , struct V_40 * V_41 ,
T_2 V_218 , unsigned V_219 , unsigned V_222 ,
struct V_5 * V_5 , void * V_220 )
{
struct V_3 * V_3 = V_41 -> V_126 ;
if ( V_218 + V_222 > V_3 -> V_67 )
F_85 ( V_3 , V_218 + V_222 ) ;
if ( ! F_72 ( V_5 ) ) {
if ( V_222 < V_22 ) {
unsigned V_223 = V_218 & ( V_22 - 1 ) ;
F_197 ( V_5 , 0 , V_223 ,
V_223 + V_222 , V_22 ) ;
}
F_119 ( V_5 ) ;
}
F_77 ( V_5 ) ;
F_75 ( V_5 ) ;
F_42 ( V_5 ) ;
return V_222 ;
}
static T_8 F_198 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
struct V_192 * V_192 = V_225 -> V_228 ;
struct V_3 * V_3 = F_58 ( V_192 ) ;
struct V_40 * V_41 = V_3 -> V_10 ;
T_1 V_4 ;
unsigned long V_229 ;
enum V_7 V_8 = V_81 ;
int error = 0 ;
T_8 V_195 = 0 ;
T_2 * V_230 = & V_225 -> V_231 ;
if ( ! F_199 ( V_227 ) )
V_8 = V_172 ;
V_4 = * V_230 >> V_76 ;
V_229 = * V_230 & ~ V_232 ;
for (; ; ) {
struct V_5 * V_5 = NULL ;
T_1 V_233 ;
unsigned long V_72 , V_175 ;
T_2 V_67 = F_152 ( V_3 ) ;
V_233 = V_67 >> V_76 ;
if ( V_4 > V_233 )
break;
if ( V_4 == V_233 ) {
V_72 = V_67 & ~ V_232 ;
if ( V_72 <= V_229 )
break;
}
error = F_4 ( V_3 , V_4 , & V_5 , V_8 , NULL ) ;
if ( error ) {
if ( error == - V_162 )
error = 0 ;
break;
}
if ( V_5 )
F_75 ( V_5 ) ;
V_72 = V_22 ;
V_67 = F_152 ( V_3 ) ;
V_233 = V_67 >> V_76 ;
if ( V_4 == V_233 ) {
V_72 = V_67 & ~ V_232 ;
if ( V_72 <= V_229 ) {
if ( V_5 )
F_42 ( V_5 ) ;
break;
}
}
V_72 -= V_229 ;
if ( V_5 ) {
if ( F_200 ( V_41 ) )
F_118 ( V_5 ) ;
if ( ! V_229 )
F_153 ( V_5 ) ;
} else {
V_5 = F_201 ( 0 ) ;
F_37 ( V_5 ) ;
}
V_175 = F_202 ( V_5 , V_229 , V_72 , V_227 ) ;
V_195 += V_175 ;
V_229 += V_175 ;
V_4 += V_229 >> V_76 ;
V_229 &= ~ V_232 ;
F_42 ( V_5 ) ;
if ( ! F_203 ( V_227 ) )
break;
if ( V_175 < V_72 ) {
error = - V_234 ;
break;
}
F_68 () ;
}
* V_230 = ( ( T_2 ) V_4 << V_76 ) + V_229 ;
F_181 ( V_192 ) ;
return V_195 ? V_195 : error ;
}
static T_8 F_204 ( struct V_192 * V_235 , T_2 * V_230 ,
struct V_236 * V_237 , T_9 V_219 ,
unsigned int V_15 )
{
struct V_40 * V_41 = V_235 -> V_197 ;
struct V_3 * V_3 = V_41 -> V_126 ;
unsigned int V_238 , V_239 , V_240 ;
struct V_5 * V_23 [ V_241 ] ;
struct V_242 V_243 [ V_241 ] ;
struct V_5 * V_5 ;
T_1 V_4 , V_233 ;
T_2 V_244 , V_245 ;
int error , V_246 ;
struct V_247 V_248 = {
. V_23 = V_23 ,
. V_243 = V_243 ,
. V_249 = V_241 ,
. V_15 = V_15 ,
. V_250 = & V_251 ,
. V_252 = V_253 ,
} ;
V_244 = F_152 ( V_3 ) ;
if ( F_107 ( * V_230 >= V_244 ) )
return 0 ;
V_245 = V_244 - * V_230 ;
if ( F_107 ( V_245 < V_219 ) )
V_219 = V_245 ;
if ( F_205 ( V_237 , & V_248 ) )
return - V_116 ;
V_4 = * V_230 >> V_76 ;
V_238 = * V_230 & ~ V_232 ;
V_240 = ( V_219 + V_238 + V_22 - 1 ) >> V_76 ;
V_239 = F_3 ( V_240 , V_248 . V_249 ) ;
V_248 . V_239 = F_206 ( V_41 , V_4 ,
V_239 , V_248 . V_23 ) ;
V_4 += V_248 . V_239 ;
error = 0 ;
while ( V_248 . V_239 < V_239 ) {
error = F_4 ( V_3 , V_4 , & V_5 , V_187 , NULL ) ;
if ( error )
break;
F_75 ( V_5 ) ;
V_248 . V_23 [ V_248 . V_239 ++ ] = V_5 ;
V_4 ++ ;
}
V_4 = * V_230 >> V_76 ;
V_239 = V_248 . V_239 ;
V_248 . V_239 = 0 ;
for ( V_246 = 0 ; V_246 < V_239 ; V_246 ++ ) {
unsigned int V_254 ;
if ( ! V_219 )
break;
V_254 = F_207 (unsigned long, len, PAGE_CACHE_SIZE - loff) ;
V_5 = V_248 . V_23 [ V_246 ] ;
if ( ! F_72 ( V_5 ) || V_5 -> V_41 != V_41 ) {
error = F_4 ( V_3 , V_4 , & V_5 ,
V_187 , NULL ) ;
if ( error )
break;
F_75 ( V_5 ) ;
F_42 ( V_248 . V_23 [ V_246 ] ) ;
V_248 . V_23 [ V_246 ] = V_5 ;
}
V_244 = F_152 ( V_3 ) ;
V_233 = ( V_244 - 1 ) >> V_76 ;
if ( F_107 ( ! V_244 || V_4 > V_233 ) )
break;
if ( V_233 == V_4 ) {
unsigned int V_255 ;
V_255 = ( ( V_244 - 1 ) & ~ V_232 ) + 1 ;
if ( V_255 <= V_238 )
break;
V_254 = F_3 ( V_254 , V_255 - V_238 ) ;
V_219 = V_254 ;
}
V_248 . V_243 [ V_246 ] . V_229 = V_238 ;
V_248 . V_243 [ V_246 ] . V_219 = V_254 ;
V_219 -= V_254 ;
V_238 = 0 ;
V_248 . V_239 ++ ;
V_4 ++ ;
}
while ( V_246 < V_239 )
F_42 ( V_248 . V_23 [ V_246 ++ ] ) ;
if ( V_248 . V_239 )
error = F_208 ( V_237 , & V_248 ) ;
F_209 ( & V_248 ) ;
if ( error > 0 ) {
* V_230 += error ;
F_181 ( V_235 ) ;
}
return error ;
}
static T_1 F_210 ( struct V_40 * V_41 ,
T_1 V_4 , T_1 V_55 , int V_256 )
{
struct V_5 * V_5 ;
struct V_68 V_69 ;
T_1 V_70 [ V_71 ] ;
bool V_257 = false ;
int V_80 ;
F_62 ( & V_69 , 0 ) ;
V_69 . V_72 = 1 ;
while ( ! V_257 ) {
V_69 . V_72 = F_64 ( V_41 , V_4 ,
V_69 . V_72 , V_69 . V_23 , V_70 ) ;
if ( ! V_69 . V_72 ) {
if ( V_256 == V_258 )
V_4 = V_55 ;
break;
}
for ( V_80 = 0 ; V_80 < V_69 . V_72 ; V_80 ++ , V_4 ++ ) {
if ( V_4 < V_70 [ V_80 ] ) {
if ( V_256 == V_259 ) {
V_257 = true ;
break;
}
V_4 = V_70 [ V_80 ] ;
}
V_5 = V_69 . V_23 [ V_80 ] ;
if ( V_5 && ! F_54 ( V_5 ) ) {
if ( ! F_72 ( V_5 ) )
V_5 = NULL ;
}
if ( V_4 >= V_55 ||
( V_5 && V_256 == V_258 ) ||
( ! V_5 && V_256 == V_259 ) ) {
V_257 = true ;
break;
}
}
F_65 ( & V_69 ) ;
F_67 ( & V_69 ) ;
V_69 . V_72 = V_71 ;
F_68 () ;
}
return V_4 ;
}
static T_2 F_211 ( struct V_192 * V_192 , T_2 V_229 , int V_256 )
{
struct V_40 * V_41 = V_192 -> V_197 ;
struct V_3 * V_3 = V_41 -> V_126 ;
T_1 V_54 , V_55 ;
T_2 V_260 ;
if ( V_256 != V_258 && V_256 != V_259 )
return F_212 ( V_192 , V_229 , V_256 ,
V_157 , F_152 ( V_3 ) ) ;
F_213 ( V_3 ) ;
if ( V_229 < 0 )
V_229 = - V_162 ;
else if ( V_229 >= V_3 -> V_67 )
V_229 = - V_261 ;
else {
V_54 = V_229 >> V_76 ;
V_55 = ( V_3 -> V_67 + V_22 - 1 ) >> V_76 ;
V_260 = F_210 ( V_41 , V_54 , V_55 , V_256 ) ;
V_260 <<= V_76 ;
if ( V_260 > V_229 ) {
if ( V_260 < V_3 -> V_67 )
V_229 = V_260 ;
else if ( V_256 == V_258 )
V_229 = - V_261 ;
else
V_229 = V_3 -> V_67 ;
}
}
if ( V_229 >= 0 )
V_229 = F_214 ( V_192 , V_229 , V_157 ) ;
F_215 ( V_3 ) ;
return V_229 ;
}
static void F_216 ( struct V_40 * V_41 )
{
struct V_56 V_57 ;
void * * V_58 ;
T_1 V_54 ;
struct V_5 * V_5 ;
F_217 () ;
V_54 = 0 ;
F_29 () ;
V_59:
F_51 (slot, &mapping->page_tree, &iter, start) {
V_5 = F_52 ( V_58 ) ;
if ( ! V_5 || F_218 ( V_5 ) ) {
if ( F_53 ( V_5 ) )
goto V_59;
} else if ( F_219 ( V_5 ) - F_220 ( V_5 ) > 1 ) {
F_38 ( & V_41 -> V_48 ) ;
F_221 ( & V_41 -> V_46 , V_57 . V_4 ,
V_262 ) ;
F_41 ( & V_41 -> V_48 ) ;
}
if ( F_55 () ) {
F_56 () ;
V_54 = V_57 . V_4 + 1 ;
goto V_59;
}
}
F_31 () ;
}
static int F_222 ( struct V_40 * V_41 )
{
struct V_56 V_57 ;
void * * V_58 ;
T_1 V_54 ;
struct V_5 * V_5 ;
int error , V_263 ;
F_216 ( V_41 ) ;
error = 0 ;
for ( V_263 = 0 ; V_263 <= V_264 ; V_263 ++ ) {
if ( ! F_223 ( & V_41 -> V_46 , V_262 ) )
break;
if ( ! V_263 )
F_224 () ;
else if ( F_225 ( ( V_265 << V_263 ) / 200 ) )
V_263 = V_264 ;
V_54 = 0 ;
F_29 () ;
V_59:
F_226 (slot, &mapping->page_tree, &iter,
start, SHMEM_TAG_PINNED) {
V_5 = F_52 ( V_58 ) ;
if ( F_218 ( V_5 ) ) {
if ( F_53 ( V_5 ) )
goto V_59;
V_5 = NULL ;
}
if ( V_5 &&
F_219 ( V_5 ) - F_220 ( V_5 ) != 1 ) {
if ( V_263 < V_264 )
goto V_266;
error = - V_267 ;
}
F_38 ( & V_41 -> V_48 ) ;
F_227 ( & V_41 -> V_46 ,
V_57 . V_4 , V_262 ) ;
F_41 ( & V_41 -> V_48 ) ;
V_266:
if ( F_55 () ) {
F_56 () ;
V_54 = V_57 . V_4 + 1 ;
goto V_59;
}
}
F_31 () ;
}
return error ;
}
int F_228 ( struct V_192 * V_192 , unsigned int V_99 )
{
struct V_3 * V_3 = F_58 ( V_192 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
int error ;
if ( V_192 -> V_268 != & V_210 )
return - V_162 ;
if ( ! ( V_192 -> V_269 & V_270 ) )
return - V_102 ;
if ( V_99 & ~ ( unsigned int ) V_271 )
return - V_162 ;
F_213 ( V_3 ) ;
if ( V_30 -> V_99 & V_203 ) {
error = - V_102 ;
goto V_163;
}
if ( ( V_99 & V_221 ) && ! ( V_30 -> V_99 & V_221 ) ) {
error = F_229 ( V_192 -> V_197 ) ;
if ( error )
goto V_163;
error = F_222 ( V_192 -> V_197 ) ;
if ( error ) {
F_230 ( V_192 -> V_197 ) ;
goto V_163;
}
}
V_30 -> V_99 |= V_99 ;
error = 0 ;
V_163:
F_215 ( V_3 ) ;
return error ;
}
int F_231 ( struct V_192 * V_192 )
{
if ( V_192 -> V_268 != & V_210 )
return - V_162 ;
return F_21 ( F_58 ( V_192 ) ) -> V_99 ;
}
long F_232 ( struct V_192 * V_192 , unsigned int V_272 , unsigned long V_273 )
{
long error ;
switch ( V_272 ) {
case V_274 :
if ( V_273 > V_275 )
return - V_162 ;
error = F_228 ( V_192 , V_273 ) ;
break;
case V_276 :
error = F_231 ( V_192 ) ;
break;
default:
error = - V_162 ;
break;
}
return error ;
}
static long F_233 ( struct V_192 * V_192 , int V_144 , T_2 V_229 ,
T_2 V_219 )
{
struct V_3 * V_3 = F_58 ( V_192 ) ;
struct V_11 * V_24 = F_7 ( V_3 -> V_35 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
struct V_132 V_132 ;
T_1 V_54 , V_4 , V_55 ;
int error ;
if ( V_144 & ~ ( V_277 | V_278 ) )
return - V_279 ;
F_213 ( V_3 ) ;
if ( V_144 & V_278 ) {
struct V_40 * V_41 = V_192 -> V_197 ;
T_2 V_280 = F_86 ( V_229 , V_104 ) ;
T_2 V_281 = F_234 ( V_229 + V_219 , V_104 ) - 1 ;
F_235 ( V_178 ) ;
if ( V_30 -> V_99 & V_221 ) {
error = - V_102 ;
goto V_122;
}
V_132 . V_134 = & V_178 ;
V_132 . V_54 = V_280 >> V_60 ;
V_132 . V_115 = ( V_281 + 1 ) >> V_60 ;
F_17 ( & V_3 -> V_133 ) ;
V_3 -> V_131 = & V_132 ;
F_18 ( & V_3 -> V_133 ) ;
if ( ( V_282 ) V_281 > ( V_282 ) V_280 )
F_87 ( V_41 , V_280 ,
1 + V_281 - V_280 , 0 ) ;
F_79 ( V_3 , V_229 , V_229 + V_219 - 1 ) ;
F_17 ( & V_3 -> V_133 ) ;
V_3 -> V_131 = NULL ;
F_236 ( & V_178 ) ;
F_18 ( & V_3 -> V_133 ) ;
error = 0 ;
goto V_122;
}
error = F_237 ( V_3 , V_229 + V_219 ) ;
if ( error )
goto V_122;
if ( ( V_30 -> V_99 & V_101 ) && V_229 + V_219 > V_3 -> V_67 ) {
error = - V_102 ;
goto V_122;
}
V_54 = V_229 >> V_76 ;
V_55 = ( V_229 + V_219 + V_22 - 1 ) >> V_76 ;
if ( V_24 -> V_36 && V_55 - V_54 > V_24 -> V_36 ) {
error = - V_28 ;
goto V_122;
}
V_132 . V_134 = NULL ;
V_132 . V_54 = V_54 ;
V_132 . V_115 = V_54 ;
V_132 . V_283 = 0 ;
V_132 . V_135 = 0 ;
F_17 ( & V_3 -> V_133 ) ;
V_3 -> V_131 = & V_132 ;
F_18 ( & V_3 -> V_133 ) ;
for ( V_4 = V_54 ; V_4 < V_55 ; V_4 ++ ) {
struct V_5 * V_5 ;
if ( F_238 ( V_18 ) )
error = - V_284 ;
else if ( V_132 . V_135 > V_132 . V_283 )
error = - V_116 ;
else
error = F_4 ( V_3 , V_4 , & V_5 , V_161 ,
NULL ) ;
if ( error ) {
F_69 ( V_3 ,
( T_2 ) V_54 << V_76 ,
( T_2 ) V_4 << V_76 , true ) ;
goto V_285;
}
V_132 . V_115 ++ ;
if ( ! F_72 ( V_5 ) )
V_132 . V_283 ++ ;
F_77 ( V_5 ) ;
F_75 ( V_5 ) ;
F_42 ( V_5 ) ;
F_68 () ;
}
if ( ! ( V_144 & V_277 ) && V_229 + V_219 > V_3 -> V_67 )
F_85 ( V_3 , V_229 + V_219 ) ;
V_3 -> V_84 = V_86 ;
V_285:
F_17 ( & V_3 -> V_133 ) ;
V_3 -> V_131 = NULL ;
F_18 ( & V_3 -> V_133 ) ;
V_122:
F_215 ( V_3 ) ;
return error ;
}
static int F_239 ( struct V_89 * V_89 , struct V_286 * V_287 )
{
struct V_11 * V_24 = F_7 ( V_89 -> V_288 ) ;
V_287 -> V_289 = V_290 ;
V_287 -> V_291 = V_22 ;
V_287 -> V_292 = V_293 ;
if ( V_24 -> V_36 ) {
V_287 -> V_294 = V_24 -> V_36 ;
V_287 -> V_295 =
V_287 -> V_296 = V_24 -> V_36 -
F_240 ( & V_24 -> V_37 ) ;
}
if ( V_24 -> V_25 ) {
V_287 -> V_297 = V_24 -> V_25 ;
V_287 -> V_298 = V_24 -> V_27 ;
}
return 0 ;
}
static int
F_241 ( struct V_3 * V_199 , struct V_89 * V_89 , T_6 V_144 , T_7 V_200 )
{
struct V_3 * V_3 ;
int error = - V_28 ;
V_3 = F_182 ( V_199 -> V_35 , V_199 , V_144 , V_200 , V_17 ) ;
if ( V_3 ) {
error = F_242 ( V_199 , V_3 ) ;
if ( error )
goto V_299;
error = F_243 ( V_3 , V_199 ,
& V_89 -> V_300 ,
V_301 , NULL ) ;
if ( error && error != - V_279 )
goto V_299;
error = 0 ;
V_199 -> V_67 += V_212 ;
V_199 -> V_84 = V_199 -> V_85 = V_86 ;
F_244 ( V_89 , V_3 ) ;
F_245 ( V_89 ) ;
}
return error ;
V_299:
F_246 ( V_3 ) ;
return error ;
}
static int
F_247 ( struct V_3 * V_199 , struct V_89 * V_89 , T_6 V_144 )
{
struct V_3 * V_3 ;
int error = - V_28 ;
V_3 = F_182 ( V_199 -> V_35 , V_199 , V_144 , 0 , V_17 ) ;
if ( V_3 ) {
error = F_243 ( V_3 , V_199 ,
NULL ,
V_301 , NULL ) ;
if ( error && error != - V_279 )
goto V_299;
error = F_242 ( V_199 , V_3 ) ;
if ( error )
goto V_299;
F_248 ( V_89 , V_3 ) ;
}
return error ;
V_299:
F_246 ( V_3 ) ;
return error ;
}
static int F_249 ( struct V_3 * V_199 , struct V_89 * V_89 , T_6 V_144 )
{
int error ;
if ( ( error = F_241 ( V_199 , V_89 , V_144 | V_211 , 0 ) ) )
return error ;
F_193 ( V_199 ) ;
return 0 ;
}
static int F_250 ( struct V_3 * V_199 , struct V_89 * V_89 , T_6 V_144 ,
bool V_302 )
{
return F_241 ( V_199 , V_89 , V_144 | V_207 , 0 ) ;
}
static int F_251 ( struct V_89 * V_303 , struct V_3 * V_199 , struct V_89 * V_89 )
{
struct V_3 * V_3 = V_92 ( V_303 ) ;
int V_175 ;
V_175 = F_16 ( V_3 -> V_35 ) ;
if ( V_175 )
goto V_122;
V_199 -> V_67 += V_212 ;
V_3 -> V_84 = V_199 -> V_84 = V_199 -> V_85 = V_86 ;
F_193 ( V_3 ) ;
F_252 ( V_3 ) ;
F_245 ( V_89 ) ;
F_244 ( V_89 , V_3 ) ;
V_122:
return V_175 ;
}
static int F_253 ( struct V_3 * V_199 , struct V_89 * V_89 )
{
struct V_3 * V_3 = V_92 ( V_89 ) ;
if ( V_3 -> V_304 > 1 && ! F_254 ( V_3 -> V_95 ) )
F_19 ( V_3 -> V_35 ) ;
V_199 -> V_67 -= V_212 ;
V_3 -> V_84 = V_199 -> V_84 = V_199 -> V_85 = V_86 ;
F_255 ( V_3 ) ;
F_256 ( V_89 ) ;
return 0 ;
}
static int F_257 ( struct V_3 * V_199 , struct V_89 * V_89 )
{
if ( ! F_258 ( V_89 ) )
return - V_305 ;
F_255 ( V_92 ( V_89 ) ) ;
F_255 ( V_199 ) ;
return F_253 ( V_199 , V_89 ) ;
}
static int F_259 ( struct V_3 * V_306 , struct V_89 * V_303 , struct V_3 * V_307 , struct V_89 * V_308 )
{
bool V_309 = F_260 ( V_303 ) ;
bool V_310 = F_260 ( V_308 ) ;
if ( V_306 != V_307 && V_309 != V_310 ) {
if ( V_309 ) {
F_255 ( V_306 ) ;
F_193 ( V_307 ) ;
} else {
F_255 ( V_307 ) ;
F_193 ( V_306 ) ;
}
}
V_306 -> V_84 = V_306 -> V_85 =
V_307 -> V_84 = V_307 -> V_85 =
V_92 ( V_303 ) -> V_84 =
V_92 ( V_308 ) -> V_84 = V_86 ;
return 0 ;
}
static int F_261 ( struct V_3 * V_306 , struct V_89 * V_303 )
{
struct V_89 * V_311 ;
int error ;
V_311 = F_262 ( V_303 -> V_312 , & V_303 -> V_300 ) ;
if ( ! V_311 )
return - V_116 ;
error = F_241 ( V_306 , V_311 ,
V_313 | V_314 , V_315 ) ;
F_256 ( V_311 ) ;
if ( error )
return error ;
F_263 ( V_311 ) ;
return 0 ;
}
static int F_264 ( struct V_3 * V_306 , struct V_89 * V_303 , struct V_3 * V_307 , struct V_89 * V_308 , unsigned int V_15 )
{
struct V_3 * V_3 = V_92 ( V_303 ) ;
int V_316 = F_254 ( V_3 -> V_95 ) ;
if ( V_15 & ~ ( V_317 | V_318 | V_319 ) )
return - V_162 ;
if ( V_15 & V_318 )
return F_259 ( V_306 , V_303 , V_307 , V_308 ) ;
if ( ! F_258 ( V_308 ) )
return - V_305 ;
if ( V_15 & V_319 ) {
int error ;
error = F_261 ( V_306 , V_303 ) ;
if ( error )
return error ;
}
if ( F_265 ( V_308 ) ) {
( void ) F_253 ( V_307 , V_308 ) ;
if ( V_316 ) {
F_255 ( V_92 ( V_308 ) ) ;
F_255 ( V_306 ) ;
}
} else if ( V_316 ) {
F_255 ( V_306 ) ;
F_193 ( V_307 ) ;
}
V_306 -> V_67 -= V_212 ;
V_307 -> V_67 += V_212 ;
V_306 -> V_84 = V_306 -> V_85 =
V_307 -> V_84 = V_307 -> V_85 =
V_3 -> V_84 = V_86 ;
return 0 ;
}
static int F_266 ( struct V_3 * V_199 , struct V_89 * V_89 , const char * V_320 )
{
int error ;
int V_219 ;
struct V_3 * V_3 ;
struct V_5 * V_5 ;
struct V_29 * V_30 ;
V_219 = strlen ( V_320 ) + 1 ;
if ( V_219 > V_22 )
return - V_321 ;
V_3 = F_182 ( V_199 -> V_35 , V_199 , V_215 | V_322 , 0 , V_17 ) ;
if ( ! V_3 )
return - V_28 ;
error = F_243 ( V_3 , V_199 , & V_89 -> V_300 ,
V_301 , NULL ) ;
if ( error ) {
if ( error != - V_279 ) {
F_246 ( V_3 ) ;
return error ;
}
error = 0 ;
}
V_30 = F_21 ( V_3 ) ;
V_3 -> V_67 = V_219 - 1 ;
if ( V_219 <= V_323 ) {
V_3 -> V_324 = F_267 ( V_320 , V_219 , V_123 ) ;
if ( ! V_3 -> V_324 ) {
F_246 ( V_3 ) ;
return - V_116 ;
}
V_3 -> V_205 = & V_325 ;
} else {
F_268 ( V_3 ) ;
error = F_4 ( V_3 , 0 , & V_5 , V_160 , NULL ) ;
if ( error ) {
F_246 ( V_3 ) ;
return error ;
}
V_3 -> V_10 -> V_106 = & V_107 ;
V_3 -> V_205 = & V_326 ;
memcpy ( F_269 ( V_5 ) , V_320 , V_219 ) ;
F_119 ( V_5 ) ;
F_77 ( V_5 ) ;
F_75 ( V_5 ) ;
F_42 ( V_5 ) ;
}
V_199 -> V_67 += V_212 ;
V_199 -> V_84 = V_199 -> V_85 = V_86 ;
F_244 ( V_89 , V_3 ) ;
F_245 ( V_89 ) ;
return 0 ;
}
static void F_270 ( void * V_273 )
{
F_153 ( V_273 ) ;
F_271 ( V_273 ) ;
}
static const char * F_272 ( struct V_89 * V_89 ,
struct V_3 * V_3 ,
struct V_327 * V_257 )
{
struct V_5 * V_5 = NULL ;
int error ;
if ( ! V_89 ) {
V_5 = F_273 ( V_3 -> V_10 , 0 ) ;
if ( ! V_5 )
return F_274 ( - V_328 ) ;
if ( ! F_72 ( V_5 ) ) {
F_271 ( V_5 ) ;
return F_274 ( - V_328 ) ;
}
} else {
error = F_4 ( V_3 , 0 , & V_5 , V_81 , NULL ) ;
if ( error )
return F_274 ( error ) ;
F_75 ( V_5 ) ;
}
F_275 ( V_257 , F_270 , V_5 ) ;
return F_269 ( V_5 ) ;
}
static int V_301 ( struct V_3 * V_3 ,
const struct V_329 * V_330 ,
void * V_331 )
{
struct V_29 * V_30 = F_21 ( V_3 ) ;
const struct V_329 * V_329 ;
struct V_332 * V_333 ;
T_9 V_219 ;
for ( V_329 = V_330 ; V_329 -> V_334 != NULL ; V_329 ++ ) {
V_333 = F_276 ( V_329 -> V_335 , V_329 -> V_336 ) ;
if ( ! V_333 )
return - V_116 ;
V_219 = strlen ( V_329 -> V_334 ) + 1 ;
V_333 -> V_334 = F_277 ( V_337 + V_219 ,
V_123 ) ;
if ( ! V_333 -> V_334 ) {
F_278 ( V_333 ) ;
return - V_116 ;
}
memcpy ( V_333 -> V_334 , V_338 ,
V_337 ) ;
memcpy ( V_333 -> V_334 + V_337 ,
V_329 -> V_334 , V_219 ) ;
F_279 ( & V_30 -> V_110 , V_333 ) ;
}
return 0 ;
}
static int F_280 ( const struct V_339 * V_340 ,
struct V_89 * V_89 , const char * V_334 ,
void * V_143 , T_9 V_16 )
{
struct V_29 * V_30 = F_21 ( V_92 ( V_89 ) ) ;
V_334 = F_281 ( V_340 , V_334 ) ;
return F_282 ( & V_30 -> V_110 , V_334 , V_143 , V_16 ) ;
}
static int F_283 ( const struct V_339 * V_340 ,
struct V_89 * V_89 , const char * V_334 ,
const void * V_335 , T_9 V_16 , int V_15 )
{
struct V_29 * V_30 = F_21 ( V_92 ( V_89 ) ) ;
V_334 = F_281 ( V_340 , V_334 ) ;
return F_284 ( & V_30 -> V_110 , V_334 , V_335 , V_16 , V_15 ) ;
}
static T_8 F_285 ( struct V_89 * V_89 , char * V_143 , T_9 V_16 )
{
struct V_29 * V_30 = F_21 ( V_92 ( V_89 ) ) ;
return F_286 ( V_92 ( V_89 ) , & V_30 -> V_110 , V_143 , V_16 ) ;
}
static struct V_89 * F_287 ( struct V_89 * V_341 )
{
return F_274 ( - V_342 ) ;
}
static int F_288 ( struct V_3 * V_343 , void * V_344 )
{
T_10 * V_345 = V_344 ;
T_11 V_346 = V_345 [ 2 ] ;
V_346 = ( V_346 << 32 ) | V_345 [ 1 ] ;
return V_343 -> V_147 == V_346 && V_345 [ 0 ] == V_343 -> V_202 ;
}
static struct V_89 * F_289 ( struct V_12 * V_13 ,
struct V_347 * V_347 , int V_348 , int V_349 )
{
struct V_3 * V_3 ;
struct V_89 * V_89 = NULL ;
V_282 V_346 ;
if ( V_348 < 3 )
return NULL ;
V_346 = V_347 -> V_350 [ 2 ] ;
V_346 = ( V_346 << 32 ) | V_347 -> V_350 [ 1 ] ;
V_3 = F_290 ( V_13 , ( unsigned long ) ( V_346 + V_347 -> V_350 [ 0 ] ) ,
F_288 , V_347 -> V_350 ) ;
if ( V_3 ) {
V_89 = F_291 ( V_3 ) ;
F_246 ( V_3 ) ;
}
return V_89 ;
}
static int F_292 ( struct V_3 * V_3 , T_10 * V_345 , int * V_219 ,
struct V_3 * V_351 )
{
if ( * V_219 < 3 ) {
* V_219 = 3 ;
return V_352 ;
}
if ( F_293 ( V_3 ) ) {
static F_294 ( V_83 ) ;
F_17 ( & V_83 ) ;
if ( F_293 ( V_3 ) )
F_295 ( V_3 ,
V_3 -> V_147 + V_3 -> V_202 ) ;
F_18 ( & V_83 ) ;
}
V_345 [ 0 ] = V_3 -> V_202 ;
V_345 [ 1 ] = V_3 -> V_147 ;
V_345 [ 2 ] = ( ( T_11 ) V_3 -> V_147 ) >> 32 ;
* V_219 = 3 ;
return 1 ;
}
static int F_296 ( char * V_353 , struct V_11 * V_24 ,
bool V_354 )
{
char * V_355 , * V_335 , * V_356 ;
struct V_141 * V_142 = NULL ;
T_12 V_357 ;
T_13 V_358 ;
while ( V_353 != NULL ) {
V_355 = V_353 ;
for (; ; ) {
V_353 = strchr ( V_353 , ',' ) ;
if ( V_353 == NULL )
break;
V_353 ++ ;
if ( ! isdigit ( * V_353 ) ) {
V_353 [ - 1 ] = '\0' ;
break;
}
}
if ( ! * V_355 )
continue;
if ( ( V_335 = strchr ( V_355 , '=' ) ) != NULL ) {
* V_335 ++ = 0 ;
} else {
F_297 ( V_359
L_2 ,
V_355 ) ;
goto error;
}
if ( ! strcmp ( V_355 , L_3 ) ) {
unsigned long long V_16 ;
V_16 = F_298 ( V_335 , & V_356 ) ;
if ( * V_356 == '%' ) {
V_16 <<= V_60 ;
V_16 *= V_1 ;
F_299 ( V_16 , 100 ) ;
V_356 ++ ;
}
if ( * V_356 )
goto V_360;
V_24 -> V_36 =
F_300 ( V_16 , V_22 ) ;
} else if ( ! strcmp ( V_355 , L_4 ) ) {
V_24 -> V_36 = F_298 ( V_335 , & V_356 ) ;
if ( * V_356 )
goto V_360;
} else if ( ! strcmp ( V_355 , L_5 ) ) {
V_24 -> V_25 = F_298 ( V_335 , & V_356 ) ;
if ( * V_356 )
goto V_360;
} else if ( ! strcmp ( V_355 , L_6 ) ) {
if ( V_354 )
continue;
V_24 -> V_144 = F_301 ( V_335 , & V_356 , 8 ) & 07777 ;
if ( * V_356 )
goto V_360;
} else if ( ! strcmp ( V_355 , L_7 ) ) {
if ( V_354 )
continue;
V_357 = F_301 ( V_335 , & V_356 , 0 ) ;
if ( * V_356 )
goto V_360;
V_24 -> V_357 = F_302 ( F_303 () , V_357 ) ;
if ( ! F_304 ( V_24 -> V_357 ) )
goto V_360;
} else if ( ! strcmp ( V_355 , L_8 ) ) {
if ( V_354 )
continue;
V_358 = F_301 ( V_335 , & V_356 , 0 ) ;
if ( * V_356 )
goto V_360;
V_24 -> V_358 = F_305 ( F_303 () , V_358 ) ;
if ( ! F_306 ( V_24 -> V_358 ) )
goto V_360;
} else if ( ! strcmp ( V_355 , L_9 ) ) {
F_307 ( V_142 ) ;
V_142 = NULL ;
if ( F_308 ( V_335 , & V_142 ) )
goto V_360;
} else {
F_297 ( V_359 L_10 ,
V_355 ) ;
goto error;
}
}
V_24 -> V_142 = V_142 ;
return 0 ;
V_360:
F_297 ( V_359 L_11 ,
V_335 , V_355 ) ;
error:
F_307 ( V_142 ) ;
return 1 ;
}
static int F_309 ( struct V_12 * V_13 , int * V_15 , char * V_361 )
{
struct V_11 * V_24 = F_7 ( V_13 ) ;
struct V_11 V_362 = * V_24 ;
unsigned long V_363 ;
int error = - V_162 ;
V_362 . V_142 = NULL ;
if ( F_296 ( V_361 , & V_362 , true ) )
return error ;
F_17 ( & V_24 -> V_26 ) ;
V_363 = V_24 -> V_25 - V_24 -> V_27 ;
if ( F_156 ( & V_24 -> V_37 , V_362 . V_36 ) > 0 )
goto V_122;
if ( V_362 . V_25 < V_363 )
goto V_122;
if ( V_362 . V_36 && ! V_24 -> V_36 )
goto V_122;
if ( V_362 . V_25 && ! V_24 -> V_25 )
goto V_122;
error = 0 ;
V_24 -> V_36 = V_362 . V_36 ;
V_24 -> V_25 = V_362 . V_25 ;
V_24 -> V_27 = V_362 . V_25 - V_363 ;
if ( V_362 . V_142 ) {
F_307 ( V_24 -> V_142 ) ;
V_24 -> V_142 = V_362 . V_142 ;
}
V_122:
F_18 ( & V_24 -> V_26 ) ;
return error ;
}
static int F_310 ( struct V_139 * V_140 , struct V_89 * V_364 )
{
struct V_11 * V_24 = F_7 ( V_364 -> V_288 ) ;
if ( V_24 -> V_36 != F_1 () )
F_130 ( V_140 , L_12 ,
V_24 -> V_36 << ( V_76 - 10 ) ) ;
if ( V_24 -> V_25 != F_2 () )
F_130 ( V_140 , L_13 , V_24 -> V_25 ) ;
if ( V_24 -> V_144 != ( V_322 | V_365 ) )
F_130 ( V_140 , L_14 , V_24 -> V_144 ) ;
if ( ! F_311 ( V_24 -> V_357 , V_366 ) )
F_130 ( V_140 , L_15 ,
F_312 ( & V_367 , V_24 -> V_357 ) ) ;
if ( ! F_313 ( V_24 -> V_358 , V_368 ) )
F_130 ( V_140 , L_16 ,
F_314 ( & V_367 , V_24 -> V_358 ) ) ;
F_128 ( V_140 , V_24 -> V_142 ) ;
return 0 ;
}
static void F_315 ( struct V_12 * V_13 )
{
struct V_11 * V_24 = F_7 ( V_13 ) ;
F_316 ( & V_24 -> V_37 ) ;
F_307 ( V_24 -> V_142 ) ;
F_278 ( V_24 ) ;
V_13 -> V_14 = NULL ;
}
int F_317 ( struct V_12 * V_13 , void * V_361 , int V_369 )
{
struct V_3 * V_3 ;
struct V_11 * V_24 ;
int V_370 = - V_116 ;
V_24 = F_318 ( F_319 ( ( int ) sizeof( struct V_11 ) ,
V_371 ) , V_123 ) ;
if ( ! V_24 )
return - V_116 ;
V_24 -> V_144 = V_322 | V_365 ;
V_24 -> V_357 = F_320 () ;
V_24 -> V_358 = F_321 () ;
V_13 -> V_14 = V_24 ;
#ifdef F_322
if ( ! ( V_13 -> V_372 & V_373 ) ) {
V_24 -> V_36 = F_1 () ;
V_24 -> V_25 = F_2 () ;
if ( F_296 ( V_361 , V_24 , false ) ) {
V_370 = - V_162 ;
goto V_166;
}
} else {
V_13 -> V_372 |= V_374 ;
}
V_13 -> V_375 = & V_376 ;
V_13 -> V_372 |= V_377 ;
#else
V_13 -> V_372 |= V_374 ;
#endif
F_187 ( & V_24 -> V_26 ) ;
if ( F_323 ( & V_24 -> V_37 , 0 , V_123 ) )
goto V_166;
V_24 -> V_27 = V_24 -> V_25 ;
V_13 -> V_378 = V_157 ;
V_13 -> V_379 = V_22 ;
V_13 -> V_380 = V_76 ;
V_13 -> V_381 = V_290 ;
V_13 -> V_216 = & V_217 ;
V_13 -> V_382 = 1 ;
#ifdef F_324
V_13 -> V_383 = V_384 ;
#endif
#ifdef F_325
V_13 -> V_372 |= V_385 ;
#endif
V_3 = F_182 ( V_13 , NULL , V_211 | V_24 -> V_144 , 0 , V_17 ) ;
if ( ! V_3 )
goto V_166;
V_3 -> V_386 = V_24 -> V_357 ;
V_3 -> V_387 = V_24 -> V_358 ;
V_13 -> V_388 = F_326 ( V_3 ) ;
if ( ! V_13 -> V_388 )
goto V_166;
return 0 ;
V_166:
F_315 ( V_13 ) ;
return V_370 ;
}
static struct V_3 * F_327 ( struct V_12 * V_13 )
{
struct V_29 * V_30 ;
V_30 = F_328 ( V_389 , V_123 ) ;
if ( ! V_30 )
return NULL ;
return & V_30 -> V_111 ;
}
static void F_329 ( struct V_390 * V_391 )
{
struct V_3 * V_3 = F_330 ( V_391 , struct V_3 , V_392 ) ;
F_278 ( V_3 -> V_324 ) ;
F_331 ( V_389 , F_21 ( V_3 ) ) ;
}
static void F_332 ( struct V_3 * V_3 )
{
if ( F_84 ( V_3 -> V_95 ) )
F_333 ( & F_21 ( V_3 ) -> V_150 ) ;
F_334 ( & V_3 -> V_392 , F_329 ) ;
}
static void F_335 ( void * V_393 )
{
struct V_29 * V_30 = V_393 ;
F_336 ( & V_30 -> V_111 ) ;
}
static int F_337 ( void )
{
V_389 = F_338 ( L_17 ,
sizeof( struct V_29 ) ,
0 , V_394 | V_395 , F_335 ) ;
return 0 ;
}
static void F_339 ( void )
{
F_340 ( V_389 ) ;
}
static struct V_89 * F_341 ( struct V_396 * V_397 ,
int V_15 , const char * V_398 , void * V_361 )
{
return F_342 ( V_397 , V_15 , V_361 , F_317 ) ;
}
int T_14 F_343 ( void )
{
int error ;
if ( V_389 )
return 0 ;
error = F_337 () ;
if ( error )
goto V_399;
error = F_344 ( & V_400 ) ;
if ( error ) {
F_297 ( V_359 L_18 ) ;
goto V_401;
}
V_402 = F_345 ( & V_400 ) ;
if ( F_346 ( V_402 ) ) {
error = F_347 ( V_402 ) ;
F_297 ( V_359 L_19 ) ;
goto V_403;
}
return 0 ;
V_403:
F_348 ( & V_400 ) ;
V_401:
F_339 () ;
V_399:
V_402 = F_274 ( error ) ;
return error ;
}
int T_14 F_343 ( void )
{
F_45 ( F_344 ( & V_400 ) != 0 ) ;
V_402 = F_345 ( & V_400 ) ;
F_45 ( F_346 ( V_402 ) ) ;
return 0 ;
}
int F_106 ( T_3 V_49 , struct V_5 * V_5 )
{
return 0 ;
}
int F_175 ( struct V_192 * V_192 , int V_83 , struct V_193 * V_194 )
{
return 0 ;
}
void F_61 ( struct V_40 * V_41 )
{
}
void F_79 ( struct V_3 * V_3 , T_2 V_73 , T_2 V_74 )
{
F_349 ( V_3 -> V_10 , V_73 , V_74 ) ;
}
static struct V_192 * F_350 ( const char * V_334 , T_2 V_16 ,
unsigned long V_15 , unsigned int V_404 )
{
struct V_192 * V_405 ;
struct V_3 * V_3 ;
struct V_406 V_406 ;
struct V_12 * V_13 ;
struct V_407 V_118 ;
if ( F_346 ( V_402 ) )
return F_351 ( V_402 ) ;
if ( V_16 < 0 || V_16 > V_157 )
return F_274 ( - V_162 ) ;
if ( F_8 ( V_15 , V_16 ) )
return F_274 ( - V_116 ) ;
V_405 = F_274 ( - V_116 ) ;
V_118 . V_334 = V_334 ;
V_118 . V_219 = strlen ( V_334 ) ;
V_118 . V_408 = 0 ;
V_13 = V_402 -> V_409 ;
V_406 . V_88 = F_352 ( V_402 ) ;
V_406 . V_89 = F_353 ( V_13 , & V_118 ) ;
if ( ! V_406 . V_89 )
goto V_410;
F_354 ( V_406 . V_89 , & V_411 ) ;
V_405 = F_274 ( - V_28 ) ;
V_3 = F_182 ( V_13 , NULL , V_207 | V_322 , 0 , V_15 ) ;
if ( ! V_3 )
goto V_410;
V_3 -> V_404 |= V_404 ;
F_244 ( V_406 . V_89 , V_3 ) ;
V_3 -> V_67 = V_16 ;
F_355 ( V_3 ) ;
V_405 = F_274 ( F_356 ( V_3 , V_16 ) ) ;
if ( F_346 ( V_405 ) )
goto V_412;
V_405 = F_357 ( & V_406 , V_270 | V_413 ,
& V_210 ) ;
if ( F_346 ( V_405 ) )
goto V_412;
return V_405 ;
V_410:
F_11 ( V_15 , V_16 ) ;
V_412:
F_358 ( & V_406 ) ;
return V_405 ;
}
struct V_192 * F_359 ( const char * V_334 , T_2 V_16 , unsigned long V_15 )
{
return F_350 ( V_334 , V_16 , V_15 , V_414 ) ;
}
struct V_192 * F_360 ( const char * V_334 , T_2 V_16 , unsigned long V_15 )
{
return F_350 ( V_334 , V_16 , V_15 , 0 ) ;
}
int F_361 ( struct V_61 * V_62 )
{
struct V_192 * V_192 ;
T_2 V_16 = V_62 -> V_65 - V_62 -> V_66 ;
V_192 = F_350 ( L_20 , V_16 , V_62 -> V_415 , V_414 ) ;
if ( F_346 ( V_192 ) )
return F_347 ( V_192 ) ;
if ( V_62 -> V_63 )
F_362 ( V_62 -> V_63 ) ;
V_62 -> V_63 = V_192 ;
V_62 -> V_148 = & V_198 ;
return 0 ;
}
struct V_5 * F_363 ( struct V_40 * V_41 ,
T_1 V_4 , T_4 V_112 )
{
#ifdef F_364
struct V_3 * V_3 = V_41 -> V_126 ;
struct V_5 * V_5 ;
int error ;
F_45 ( V_41 -> V_106 != & V_107 ) ;
error = F_5 ( V_3 , V_4 , & V_5 , V_187 , V_112 , NULL ) ;
if ( error )
V_5 = F_274 ( error ) ;
else
F_75 ( V_5 ) ;
return V_5 ;
#else
return F_365 ( V_41 , V_4 , V_112 ) ;
#endif
}
