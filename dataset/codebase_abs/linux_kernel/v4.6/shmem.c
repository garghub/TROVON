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
F_51 (slot, &mapping->page_tree, &iter, start) {
if ( V_57 . V_4 >= V_55 )
break;
V_5 = F_52 ( V_58 ) ;
if ( F_53 ( V_5 ) ) {
V_58 = F_54 ( & V_57 ) ;
continue;
}
if ( F_55 ( V_5 ) )
V_33 ++ ;
if ( F_56 () ) {
F_57 () ;
V_58 = F_58 ( & V_57 ) ;
}
}
F_31 () ;
return V_33 << V_59 ;
}
unsigned long F_59 ( struct V_60 * V_61 )
{
struct V_3 * V_3 = F_60 ( V_61 -> V_62 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
struct V_40 * V_41 = V_3 -> V_10 ;
unsigned long V_33 ;
V_33 = F_61 ( V_30 -> V_33 ) ;
if ( ! V_33 )
return 0 ;
if ( ! V_61 -> V_63 && V_61 -> V_64 - V_61 -> V_65 >= V_3 -> V_66 )
return V_33 << V_59 ;
return F_50 ( V_41 ,
F_62 ( V_61 , V_61 -> V_65 ) ,
F_62 ( V_61 , V_61 -> V_64 ) ) ;
}
void F_63 ( struct V_40 * V_41 )
{
struct V_67 V_68 ;
T_1 V_69 [ V_70 ] ;
T_1 V_4 = 0 ;
F_64 ( & V_68 , 0 ) ;
while ( ! F_65 ( V_41 ) ) {
V_68 . V_71 = F_66 ( V_41 , V_4 ,
V_70 , V_68 . V_23 , V_69 ) ;
if ( ! V_68 . V_71 )
break;
V_4 = V_69 [ V_68 . V_71 - 1 ] + 1 ;
F_67 ( & V_68 ) ;
F_68 ( V_68 . V_23 , V_68 . V_71 ) ;
F_69 ( & V_68 ) ;
F_70 () ;
}
}
static void F_71 ( struct V_3 * V_3 , T_2 V_72 , T_2 V_73 ,
bool V_74 )
{
struct V_40 * V_41 = V_3 -> V_10 ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
T_1 V_54 = ( V_72 + V_22 - 1 ) >> V_59 ;
T_1 V_55 = ( V_73 + 1 ) >> V_59 ;
unsigned int V_75 = V_72 & ( V_22 - 1 ) ;
unsigned int V_76 = ( V_73 + 1 ) & ( V_22 - 1 ) ;
struct V_67 V_68 ;
T_1 V_69 [ V_70 ] ;
long V_77 = 0 ;
T_1 V_4 ;
int V_78 ;
if ( V_73 == - 1 )
V_55 = - 1 ;
F_64 ( & V_68 , 0 ) ;
V_4 = V_54 ;
while ( V_4 < V_55 ) {
V_68 . V_71 = F_66 ( V_41 , V_4 ,
F_3 ( V_55 - V_4 , ( T_1 ) V_70 ) ,
V_68 . V_23 , V_69 ) ;
if ( ! V_68 . V_71 )
break;
for ( V_78 = 0 ; V_78 < F_72 ( & V_68 ) ; V_78 ++ ) {
struct V_5 * V_5 = V_68 . V_23 [ V_78 ] ;
V_4 = V_69 [ V_78 ] ;
if ( V_4 >= V_55 )
break;
if ( F_55 ( V_5 ) ) {
if ( V_74 )
continue;
V_77 += ! F_46 ( V_41 ,
V_4 , V_5 ) ;
continue;
}
if ( ! F_73 ( V_5 ) )
continue;
if ( ! V_74 || ! F_74 ( V_5 ) ) {
if ( V_5 -> V_41 == V_41 ) {
F_34 ( F_75 ( V_5 ) , V_5 ) ;
F_76 ( V_41 , V_5 ) ;
}
}
F_77 ( V_5 ) ;
}
F_67 ( & V_68 ) ;
F_69 ( & V_68 ) ;
F_70 () ;
V_4 ++ ;
}
if ( V_75 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_54 - 1 , & V_5 , V_79 , NULL ) ;
if ( V_5 ) {
unsigned int V_80 = V_22 ;
if ( V_54 > V_55 ) {
V_80 = V_76 ;
V_76 = 0 ;
}
F_78 ( V_5 , V_75 , V_80 ) ;
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
}
}
if ( V_76 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_55 , & V_5 , V_79 , NULL ) ;
if ( V_5 ) {
F_78 ( V_5 , 0 , V_76 ) ;
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
}
}
if ( V_54 >= V_55 )
return;
V_4 = V_54 ;
while ( V_4 < V_55 ) {
F_70 () ;
V_68 . V_71 = F_66 ( V_41 , V_4 ,
F_3 ( V_55 - V_4 , ( T_1 ) V_70 ) ,
V_68 . V_23 , V_69 ) ;
if ( ! V_68 . V_71 ) {
if ( V_4 == V_54 || V_55 != - 1 )
break;
V_4 = V_54 ;
continue;
}
for ( V_78 = 0 ; V_78 < F_72 ( & V_68 ) ; V_78 ++ ) {
struct V_5 * V_5 = V_68 . V_23 [ V_78 ] ;
V_4 = V_69 [ V_78 ] ;
if ( V_4 >= V_55 )
break;
if ( F_55 ( V_5 ) ) {
if ( V_74 )
continue;
if ( F_46 ( V_41 , V_4 , V_5 ) ) {
V_4 -- ;
break;
}
V_77 ++ ;
continue;
}
F_80 ( V_5 ) ;
if ( ! V_74 || ! F_74 ( V_5 ) ) {
if ( V_5 -> V_41 == V_41 ) {
F_34 ( F_75 ( V_5 ) , V_5 ) ;
F_76 ( V_41 , V_5 ) ;
} else {
F_77 ( V_5 ) ;
V_4 -- ;
break;
}
}
F_77 ( V_5 ) ;
}
F_67 ( & V_68 ) ;
F_69 ( & V_68 ) ;
V_4 ++ ;
}
F_17 ( & V_30 -> V_81 ) ;
V_30 -> V_33 -= V_77 ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_81 ) ;
}
void F_81 ( struct V_3 * V_3 , T_2 V_72 , T_2 V_73 )
{
F_71 ( V_3 , V_72 , V_73 , false ) ;
V_3 -> V_82 = V_3 -> V_83 = V_84 ;
}
static int F_82 ( struct V_85 * V_86 , struct V_87 * V_87 ,
struct V_88 * V_89 )
{
struct V_3 * V_3 = V_87 -> V_90 ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
if ( V_30 -> V_32 - V_30 -> V_33 != V_3 -> V_10 -> V_34 ) {
F_17 ( & V_30 -> V_81 ) ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_81 ) ;
}
F_83 ( V_3 , V_89 ) ;
return 0 ;
}
static int F_84 ( struct V_87 * V_87 , struct V_91 * V_92 )
{
struct V_3 * V_3 = V_90 ( V_87 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
int error ;
error = F_85 ( V_3 , V_92 ) ;
if ( error )
return error ;
if ( F_86 ( V_3 -> V_93 ) && ( V_92 -> V_94 & V_95 ) ) {
T_2 V_20 = V_3 -> V_66 ;
T_2 V_21 = V_92 -> V_96 ;
if ( ( V_21 < V_20 && ( V_30 -> V_97 & V_98 ) ) ||
( V_21 > V_20 && ( V_30 -> V_97 & V_99 ) ) )
return - V_100 ;
if ( V_21 != V_20 ) {
error = F_13 ( F_21 ( V_3 ) -> V_15 ,
V_20 , V_21 ) ;
if ( error )
return error ;
F_87 ( V_3 , V_21 ) ;
V_3 -> V_82 = V_3 -> V_83 = V_84 ;
}
if ( V_21 <= V_20 ) {
T_2 V_101 = F_88 ( V_21 , V_22 ) ;
if ( V_20 > V_101 )
F_89 ( V_3 -> V_10 ,
V_101 , 0 , 1 ) ;
if ( V_30 -> V_32 )
F_81 ( V_3 ,
V_21 , ( T_2 ) - 1 ) ;
if ( V_20 > V_101 )
F_89 ( V_3 -> V_10 ,
V_101 , 0 , 1 ) ;
}
}
F_90 ( V_3 , V_92 ) ;
if ( V_92 -> V_94 & V_102 )
error = F_91 ( V_3 , V_3 -> V_93 ) ;
return error ;
}
static void F_92 ( struct V_3 * V_3 )
{
struct V_29 * V_30 = F_21 ( V_3 ) ;
if ( V_3 -> V_10 -> V_103 == & V_104 ) {
F_11 ( V_30 -> V_15 , V_3 -> V_66 ) ;
V_3 -> V_66 = 0 ;
F_81 ( V_3 , 0 , ( T_2 ) - 1 ) ;
if ( ! F_93 ( & V_30 -> V_105 ) ) {
F_94 ( & V_106 ) ;
F_95 ( & V_30 -> V_105 ) ;
F_96 ( & V_106 ) ;
}
}
F_97 ( & V_30 -> V_107 ) ;
F_98 ( V_3 -> V_38 ) ;
F_19 ( V_3 -> V_35 ) ;
F_99 ( V_3 ) ;
}
static int F_100 ( struct V_29 * V_30 ,
T_3 V_49 , struct V_5 * * V_6 )
{
struct V_40 * V_41 = V_30 -> V_108 . V_10 ;
void * V_52 ;
T_1 V_4 ;
T_4 V_109 ;
int error = 0 ;
V_52 = F_32 ( V_49 ) ;
V_4 = F_101 ( & V_41 -> V_46 , V_52 ) ;
if ( V_4 == - 1 )
return - V_110 ;
if ( V_111 . V_112 != & V_30 -> V_105 )
F_102 ( & V_111 , & V_30 -> V_105 ) ;
V_109 = F_6 ( V_41 ) ;
if ( F_103 ( * V_6 , V_109 ) ) {
F_96 ( & V_106 ) ;
error = F_104 ( V_6 , V_109 , V_30 , V_4 ) ;
F_94 ( & V_106 ) ;
if ( ! F_105 ( * V_6 ) )
error = - V_47 ;
}
if ( ! error )
error = F_33 ( * V_6 , V_41 , V_4 ,
V_52 ) ;
if ( error != - V_113 ) {
F_106 ( * V_6 ) ;
F_79 ( * V_6 ) ;
if ( ! error ) {
F_17 ( & V_30 -> V_81 ) ;
V_30 -> V_33 -- ;
F_18 ( & V_30 -> V_81 ) ;
F_107 ( V_49 ) ;
}
}
return error ;
}
int F_108 ( T_3 V_49 , struct V_5 * V_5 )
{
struct V_114 * V_115 , * V_112 ;
struct V_29 * V_30 ;
struct V_116 * V_117 ;
int error = 0 ;
if ( F_109 ( ! F_110 ( V_5 ) || F_111 ( V_5 ) != V_49 . V_118 ) )
goto V_119;
error = F_112 ( V_5 , V_18 -> V_19 , V_120 , & V_117 ,
false ) ;
if ( error )
goto V_119;
error = - V_110 ;
F_94 ( & V_106 ) ;
F_113 (this, next, &shmem_swaplist) {
V_30 = F_114 ( V_115 , struct V_29 , V_105 ) ;
if ( V_30 -> V_33 )
error = F_100 ( V_30 , V_49 , & V_5 ) ;
else
F_95 ( & V_30 -> V_105 ) ;
F_70 () ;
if ( error != - V_110 )
break;
}
F_96 ( & V_106 ) ;
if ( error ) {
if ( error != - V_113 )
error = 0 ;
F_115 ( V_5 , V_117 , false ) ;
} else
F_116 ( V_5 , V_117 , true , false ) ;
V_119:
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
return error ;
}
static int F_117 ( struct V_5 * V_5 , struct V_121 * V_122 )
{
struct V_29 * V_30 ;
struct V_40 * V_41 ;
struct V_3 * V_3 ;
T_3 V_49 ;
T_1 V_4 ;
F_45 ( ! F_35 ( V_5 ) ) ;
V_41 = V_5 -> V_41 ;
V_4 = V_5 -> V_4 ;
V_3 = V_41 -> V_123 ;
V_30 = F_21 ( V_3 ) ;
if ( V_30 -> V_15 & V_124 )
goto V_125;
if ( ! V_126 )
goto V_125;
if ( ! V_122 -> V_127 ) {
F_118 ( 1 ) ;
goto V_125;
}
if ( ! F_74 ( V_5 ) ) {
if ( V_3 -> V_128 ) {
struct V_129 * V_129 ;
F_17 ( & V_3 -> V_130 ) ;
V_129 = V_3 -> V_128 ;
if ( V_129 &&
! V_129 -> V_131 &&
V_4 >= V_129 -> V_54 &&
V_4 < V_129 -> V_112 )
V_129 -> V_132 ++ ;
else
V_129 = NULL ;
F_18 ( & V_3 -> V_130 ) ;
if ( V_129 )
goto V_125;
}
F_119 ( V_5 ) ;
F_120 ( V_5 ) ;
F_121 ( V_5 ) ;
}
V_49 = F_122 () ;
if ( ! V_49 . V_118 )
goto V_125;
if ( F_123 ( V_5 , V_49 ) )
goto V_133;
F_94 ( & V_106 ) ;
if ( F_93 ( & V_30 -> V_105 ) )
F_124 ( & V_30 -> V_105 , & V_111 ) ;
if ( F_125 ( V_5 , V_49 , V_134 ) == 0 ) {
F_17 ( & V_30 -> V_81 ) ;
F_20 ( V_3 ) ;
V_30 -> V_33 ++ ;
F_18 ( & V_30 -> V_81 ) ;
F_126 ( V_49 ) ;
F_43 ( V_5 , F_32 ( V_49 ) ) ;
F_96 ( & V_106 ) ;
F_45 ( F_127 ( V_5 ) ) ;
F_128 ( V_5 , V_122 ) ;
return 0 ;
}
F_96 ( & V_106 ) ;
V_133:
F_129 ( V_49 ) ;
V_125:
F_79 ( V_5 ) ;
if ( V_122 -> V_127 )
return V_135 ;
F_77 ( V_5 ) ;
return 0 ;
}
static void F_130 ( struct V_136 * V_137 , struct V_138 * V_139 )
{
char V_140 [ 64 ] ;
if ( ! V_139 || V_139 -> V_141 == V_142 )
return;
F_131 ( V_140 , sizeof( V_140 ) , V_139 ) ;
F_132 ( V_137 , L_1 , V_140 ) ;
}
static struct V_138 * F_133 ( struct V_11 * V_24 )
{
struct V_138 * V_139 = NULL ;
if ( V_24 -> V_139 ) {
F_17 ( & V_24 -> V_26 ) ;
V_139 = V_24 -> V_139 ;
F_134 ( V_139 ) ;
F_18 ( & V_24 -> V_26 ) ;
}
return V_139 ;
}
static struct V_5 * F_135 ( T_3 V_49 , T_4 V_109 ,
struct V_29 * V_30 , T_1 V_4 )
{
struct V_60 V_143 ;
struct V_5 * V_5 ;
V_143 . V_65 = 0 ;
V_143 . V_63 = V_4 + V_30 -> V_108 . V_144 ;
V_143 . V_145 = NULL ;
V_143 . V_146 = F_136 ( & V_30 -> V_147 , V_4 ) ;
V_5 = F_137 ( V_49 , V_109 , & V_143 , 0 ) ;
F_138 ( V_143 . V_146 ) ;
return V_5 ;
}
static struct V_5 * F_139 ( T_4 V_109 ,
struct V_29 * V_30 , T_1 V_4 )
{
struct V_60 V_143 ;
struct V_5 * V_5 ;
V_143 . V_65 = 0 ;
V_143 . V_63 = V_4 + V_30 -> V_108 . V_144 ;
V_143 . V_145 = NULL ;
V_143 . V_146 = F_136 ( & V_30 -> V_147 , V_4 ) ;
V_5 = F_140 ( V_109 , & V_143 , 0 ) ;
F_138 ( V_143 . V_146 ) ;
return V_5 ;
}
static inline void F_130 ( struct V_136 * V_137 , struct V_138 * V_139 )
{
}
static inline struct V_5 * F_135 ( T_3 V_49 , T_4 V_109 ,
struct V_29 * V_30 , T_1 V_4 )
{
return F_137 ( V_49 , V_109 , NULL , 0 ) ;
}
static inline struct V_5 * F_139 ( T_4 V_109 ,
struct V_29 * V_30 , T_1 V_4 )
{
return F_141 ( V_109 ) ;
}
static inline struct V_138 * F_133 ( struct V_11 * V_24 )
{
return NULL ;
}
static bool F_103 ( struct V_5 * V_5 , T_4 V_109 )
{
return F_142 ( V_5 ) > F_143 ( V_109 ) ;
}
static int F_104 ( struct V_5 * * V_6 , T_4 V_109 ,
struct V_29 * V_30 , T_1 V_4 )
{
struct V_5 * V_148 , * V_149 ;
struct V_40 * V_150 ;
T_1 V_151 ;
int error ;
V_148 = * V_6 ;
V_151 = F_111 ( V_148 ) ;
V_150 = F_144 ( V_148 ) ;
V_109 &= ~ V_152 ;
V_149 = F_139 ( V_109 , V_30 , V_4 ) ;
if ( ! V_149 )
return - V_113 ;
F_37 ( V_149 ) ;
F_145 ( V_149 , V_148 ) ;
F_120 ( V_149 ) ;
F_146 ( V_149 ) ;
F_121 ( V_149 ) ;
F_147 ( V_149 ) ;
F_148 ( V_149 , V_151 ) ;
F_149 ( V_149 ) ;
F_38 ( & V_150 -> V_48 ) ;
error = F_23 ( V_150 , V_151 , V_148 ,
V_149 ) ;
if ( ! error ) {
F_40 ( V_149 , V_50 ) ;
F_44 ( V_148 , V_50 ) ;
}
F_41 ( & V_150 -> V_48 ) ;
if ( F_109 ( error ) ) {
V_148 = V_149 ;
} else {
F_150 ( V_148 , V_149 ) ;
F_151 ( V_149 ) ;
* V_6 = V_149 ;
}
F_152 ( V_148 ) ;
F_148 ( V_148 , 0 ) ;
F_77 ( V_148 ) ;
F_42 ( V_148 ) ;
F_42 ( V_148 ) ;
return error ;
}
static int F_5 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 , T_4 V_109 , int * V_9 )
{
struct V_40 * V_41 = V_3 -> V_10 ;
struct V_29 * V_30 ;
struct V_11 * V_24 ;
struct V_116 * V_117 ;
struct V_5 * V_5 ;
T_3 V_49 ;
int error ;
int V_153 = 0 ;
int V_32 = 0 ;
if ( V_4 > ( V_154 >> V_59 ) )
return - V_155 ;
V_156:
V_49 . V_118 = 0 ;
V_5 = F_153 ( V_41 , V_4 ) ;
if ( F_55 ( V_5 ) ) {
V_49 = F_49 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_8 != V_157 && V_8 != V_158 &&
( ( T_2 ) V_4 << V_59 ) >= F_154 ( V_3 ) ) {
error = - V_159 ;
goto V_160;
}
if ( V_5 && V_8 == V_157 )
F_155 ( V_5 ) ;
if ( V_5 && ! F_74 ( V_5 ) ) {
if ( V_8 != V_79 )
goto V_161;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 || ( V_8 == V_79 && ! V_49 . V_118 ) ) {
* V_6 = V_5 ;
return 0 ;
}
V_30 = F_21 ( V_3 ) ;
V_24 = F_7 ( V_3 -> V_35 ) ;
if ( V_49 . V_118 ) {
V_5 = F_156 ( V_49 ) ;
if ( ! V_5 ) {
if ( V_9 )
* V_9 |= V_162 ;
V_5 = F_135 ( V_49 , V_109 , V_30 , V_4 ) ;
if ( ! V_5 ) {
error = - V_113 ;
goto V_163;
}
}
F_80 ( V_5 ) ;
if ( ! F_110 ( V_5 ) || F_111 ( V_5 ) != V_49 . V_118 ||
! F_28 ( V_41 , V_4 , V_49 ) ) {
error = - V_164 ;
goto V_160;
}
if ( ! F_74 ( V_5 ) ) {
error = - V_165 ;
goto V_163;
}
F_157 ( V_5 ) ;
if ( F_103 ( V_5 , V_109 ) ) {
error = F_104 ( & V_5 , V_109 , V_30 , V_4 ) ;
if ( error )
goto V_163;
}
error = F_112 ( V_5 , V_18 -> V_19 , V_109 , & V_117 ,
false ) ;
if ( ! error ) {
error = F_33 ( V_5 , V_41 , V_4 ,
F_32 ( V_49 ) ) ;
if ( error ) {
F_115 ( V_5 , V_117 , false ) ;
F_106 ( V_5 ) ;
}
}
if ( error )
goto V_163;
F_116 ( V_5 , V_117 , true , false ) ;
F_17 ( & V_30 -> V_81 ) ;
V_30 -> V_33 -- ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_81 ) ;
if ( V_8 == V_157 )
F_155 ( V_5 ) ;
F_106 ( V_5 ) ;
F_79 ( V_5 ) ;
F_107 ( V_49 ) ;
} else {
if ( F_14 ( V_30 -> V_15 ) ) {
error = - V_28 ;
goto V_163;
}
if ( V_24 -> V_36 ) {
if ( F_158 ( & V_24 -> V_37 ,
V_24 -> V_36 ) >= 0 ) {
error = - V_28 ;
goto V_166;
}
F_159 ( & V_24 -> V_37 ) ;
}
V_5 = F_139 ( V_109 , V_30 , V_4 ) ;
if ( ! V_5 ) {
error = - V_113 ;
goto V_167;
}
F_160 ( V_5 ) ;
F_146 ( V_5 ) ;
if ( V_8 == V_157 )
F_161 ( V_5 ) ;
error = F_112 ( V_5 , V_18 -> V_19 , V_109 , & V_117 ,
false ) ;
if ( error )
goto V_167;
error = F_162 ( V_109 & V_168 ) ;
if ( ! error ) {
error = F_33 ( V_5 , V_41 , V_4 ,
NULL ) ;
F_163 () ;
}
if ( error ) {
F_115 ( V_5 , V_117 , false ) ;
goto V_167;
}
F_116 ( V_5 , V_117 , false , false ) ;
F_151 ( V_5 ) ;
F_17 ( & V_30 -> V_81 ) ;
V_30 -> V_32 ++ ;
V_3 -> V_38 += V_39 ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_81 ) ;
V_32 = true ;
if ( V_8 == V_158 )
V_8 = V_157 ;
V_161:
if ( V_8 != V_157 ) {
F_119 ( V_5 ) ;
F_120 ( V_5 ) ;
F_121 ( V_5 ) ;
}
if ( V_8 == V_169 )
F_79 ( V_5 ) ;
}
if ( V_8 != V_157 && V_8 != V_158 &&
( ( T_2 ) V_4 << V_59 ) >= F_154 ( V_3 ) ) {
if ( V_32 ) {
F_164 ( V_5 ) ;
F_165 ( V_5 ) ;
F_17 ( & V_30 -> V_81 ) ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_81 ) ;
}
error = - V_159 ;
goto V_160;
}
* V_6 = V_5 ;
return 0 ;
V_167:
if ( V_24 -> V_36 )
F_22 ( & V_24 -> V_37 , - 1 ) ;
V_166:
F_15 ( V_30 -> V_15 , 1 ) ;
V_163:
if ( V_49 . V_118 && ! F_28 ( V_41 , V_4 , V_49 ) )
error = - V_164 ;
V_160:
if ( V_5 ) {
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
}
if ( error == - V_28 && ! V_153 ++ ) {
V_30 = F_21 ( V_3 ) ;
F_17 ( & V_30 -> V_81 ) ;
F_20 ( V_3 ) ;
F_18 ( & V_30 -> V_81 ) ;
goto V_156;
}
if ( error == - V_164 )
goto V_156;
return error ;
}
static int F_166 ( struct V_60 * V_61 , struct V_170 * V_171 )
{
struct V_3 * V_3 = F_60 ( V_61 -> V_62 ) ;
int error ;
int V_172 = V_173 ;
if ( F_109 ( V_3 -> V_128 ) ) {
struct V_129 * V_129 ;
F_17 ( & V_3 -> V_130 ) ;
V_129 = V_3 -> V_128 ;
if ( V_129 &&
V_129 -> V_131 &&
V_171 -> V_174 >= V_129 -> V_54 &&
V_171 -> V_174 < V_129 -> V_112 ) {
T_5 * V_175 ;
F_167 ( V_176 ) ;
V_172 = V_177 ;
if ( ( V_171 -> V_15 & V_178 ) &&
! ( V_171 -> V_15 & V_179 ) ) {
F_168 ( & V_61 -> V_180 -> V_181 ) ;
V_172 = V_182 ;
}
V_175 = V_129 -> V_131 ;
F_169 ( V_175 , & V_176 ,
V_183 ) ;
F_18 ( & V_3 -> V_130 ) ;
F_170 () ;
F_17 ( & V_3 -> V_130 ) ;
F_171 ( V_175 , & V_176 ) ;
F_18 ( & V_3 -> V_130 ) ;
return V_172 ;
}
F_18 ( & V_3 -> V_130 ) ;
}
error = F_4 ( V_3 , V_171 -> V_174 , & V_171 -> V_5 , V_184 , & V_172 ) ;
if ( error )
return ( ( error == - V_113 ) ? V_185 : V_186 ) ;
if ( V_172 & V_162 ) {
F_172 ( V_187 ) ;
F_173 ( V_61 -> V_180 , V_187 ) ;
}
return V_172 ;
}
static int F_174 ( struct V_60 * V_61 , struct V_138 * V_139 )
{
struct V_3 * V_3 = F_60 ( V_61 -> V_62 ) ;
return F_175 ( & F_21 ( V_3 ) -> V_147 , V_61 , V_139 ) ;
}
static struct V_138 * F_176 ( struct V_60 * V_61 ,
unsigned long V_188 )
{
struct V_3 * V_3 = F_60 ( V_61 -> V_62 ) ;
T_1 V_4 ;
V_4 = ( ( V_188 - V_61 -> V_65 ) >> V_59 ) + V_61 -> V_63 ;
return F_136 ( & F_21 ( V_3 ) -> V_147 , V_4 ) ;
}
int F_177 ( struct V_189 * V_189 , int V_81 , struct V_190 * V_191 )
{
struct V_3 * V_3 = F_60 ( V_189 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
int V_192 = - V_113 ;
F_17 ( & V_30 -> V_81 ) ;
if ( V_81 && ! ( V_30 -> V_15 & V_124 ) ) {
if ( ! F_178 ( V_3 -> V_66 , V_191 ) )
goto V_193;
V_30 -> V_15 |= V_124 ;
F_179 ( V_189 -> V_194 ) ;
}
if ( ! V_81 && ( V_30 -> V_15 & V_124 ) && V_191 ) {
F_180 ( V_3 -> V_66 , V_191 ) ;
V_30 -> V_15 &= ~ V_124 ;
F_181 ( V_189 -> V_194 ) ;
}
V_192 = 0 ;
V_193:
F_18 ( & V_30 -> V_81 ) ;
return V_192 ;
}
static int F_182 ( struct V_189 * V_189 , struct V_60 * V_61 )
{
F_183 ( V_189 ) ;
V_61 -> V_145 = & V_195 ;
return 0 ;
}
static struct V_3 * F_184 ( struct V_12 * V_13 , const struct V_3 * V_196 ,
T_6 V_141 , T_7 V_197 , unsigned long V_15 )
{
struct V_3 * V_3 ;
struct V_29 * V_30 ;
struct V_11 * V_24 = F_7 ( V_13 ) ;
if ( F_16 ( V_13 ) )
return NULL ;
V_3 = F_185 ( V_13 ) ;
if ( V_3 ) {
V_3 -> V_144 = F_186 () ;
F_187 ( V_3 , V_196 , V_141 ) ;
V_3 -> V_38 = 0 ;
V_3 -> V_198 = V_3 -> V_83 = V_3 -> V_82 = V_84 ;
V_3 -> V_199 = F_188 () ;
V_30 = F_21 ( V_3 ) ;
memset ( V_30 , 0 , ( char * ) V_3 - ( char * ) V_30 ) ;
F_189 ( & V_30 -> V_81 ) ;
V_30 -> V_97 = V_200 ;
V_30 -> V_15 = V_15 & V_17 ;
F_190 ( & V_30 -> V_105 ) ;
F_191 ( & V_30 -> V_107 ) ;
F_192 ( V_3 ) ;
switch ( V_141 & V_201 ) {
default:
V_3 -> V_202 = & V_203 ;
F_193 ( V_3 , V_141 , V_197 ) ;
break;
case V_204 :
V_3 -> V_10 -> V_103 = & V_104 ;
V_3 -> V_202 = & V_205 ;
V_3 -> V_206 = & V_207 ;
F_194 ( & V_30 -> V_147 ,
F_133 ( V_24 ) ) ;
break;
case V_208 :
F_195 ( V_3 ) ;
V_3 -> V_66 = 2 * V_209 ;
V_3 -> V_202 = & V_210 ;
V_3 -> V_206 = & V_211 ;
break;
case V_212 :
F_194 ( & V_30 -> V_147 , NULL ) ;
break;
}
} else
F_19 ( V_13 ) ;
return V_3 ;
}
bool F_196 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_123 )
return false ;
return V_41 -> V_123 -> V_35 -> V_213 == & V_214 ;
}
static int
F_197 ( struct V_189 * V_189 , struct V_40 * V_41 ,
T_2 V_215 , unsigned V_216 , unsigned V_15 ,
struct V_5 * * V_6 , void * * V_217 )
{
struct V_3 * V_3 = V_41 -> V_123 ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
T_1 V_4 = V_215 >> V_59 ;
if ( F_109 ( V_30 -> V_97 ) ) {
if ( V_30 -> V_97 & V_218 )
return - V_100 ;
if ( ( V_30 -> V_97 & V_99 ) && V_215 + V_216 > V_3 -> V_66 )
return - V_100 ;
}
return F_4 ( V_3 , V_4 , V_6 , V_157 , NULL ) ;
}
static int
F_198 ( struct V_189 * V_189 , struct V_40 * V_41 ,
T_2 V_215 , unsigned V_216 , unsigned V_219 ,
struct V_5 * V_5 , void * V_217 )
{
struct V_3 * V_3 = V_41 -> V_123 ;
if ( V_215 + V_219 > V_3 -> V_66 )
F_87 ( V_3 , V_215 + V_219 ) ;
if ( ! F_74 ( V_5 ) ) {
if ( V_219 < V_22 ) {
unsigned V_220 = V_215 & ( V_22 - 1 ) ;
F_199 ( V_5 , 0 , V_220 ,
V_220 + V_219 , V_22 ) ;
}
F_121 ( V_5 ) ;
}
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
return V_219 ;
}
static T_8 F_200 ( struct V_221 * V_222 , struct V_223 * V_224 )
{
struct V_189 * V_189 = V_222 -> V_225 ;
struct V_3 * V_3 = F_60 ( V_189 ) ;
struct V_40 * V_41 = V_3 -> V_10 ;
T_1 V_4 ;
unsigned long V_226 ;
enum V_7 V_8 = V_79 ;
int error = 0 ;
T_8 V_192 = 0 ;
T_2 * V_227 = & V_222 -> V_228 ;
if ( ! F_201 ( V_224 ) )
V_8 = V_169 ;
V_4 = * V_227 >> V_59 ;
V_226 = * V_227 & ~ V_229 ;
for (; ; ) {
struct V_5 * V_5 = NULL ;
T_1 V_230 ;
unsigned long V_71 , V_172 ;
T_2 V_66 = F_154 ( V_3 ) ;
V_230 = V_66 >> V_59 ;
if ( V_4 > V_230 )
break;
if ( V_4 == V_230 ) {
V_71 = V_66 & ~ V_229 ;
if ( V_71 <= V_226 )
break;
}
error = F_4 ( V_3 , V_4 , & V_5 , V_8 , NULL ) ;
if ( error ) {
if ( error == - V_159 )
error = 0 ;
break;
}
if ( V_5 )
F_77 ( V_5 ) ;
V_71 = V_22 ;
V_66 = F_154 ( V_3 ) ;
V_230 = V_66 >> V_59 ;
if ( V_4 == V_230 ) {
V_71 = V_66 & ~ V_229 ;
if ( V_71 <= V_226 ) {
if ( V_5 )
F_42 ( V_5 ) ;
break;
}
}
V_71 -= V_226 ;
if ( V_5 ) {
if ( F_202 ( V_41 ) )
F_120 ( V_5 ) ;
if ( ! V_226 )
F_155 ( V_5 ) ;
} else {
V_5 = F_203 ( 0 ) ;
F_37 ( V_5 ) ;
}
V_172 = F_204 ( V_5 , V_226 , V_71 , V_224 ) ;
V_192 += V_172 ;
V_226 += V_172 ;
V_4 += V_226 >> V_59 ;
V_226 &= ~ V_229 ;
F_42 ( V_5 ) ;
if ( ! F_205 ( V_224 ) )
break;
if ( V_172 < V_71 ) {
error = - V_231 ;
break;
}
F_70 () ;
}
* V_227 = ( ( T_2 ) V_4 << V_59 ) + V_226 ;
F_183 ( V_189 ) ;
return V_192 ? V_192 : error ;
}
static T_8 F_206 ( struct V_189 * V_232 , T_2 * V_227 ,
struct V_233 * V_234 , T_9 V_216 ,
unsigned int V_15 )
{
struct V_40 * V_41 = V_232 -> V_194 ;
struct V_3 * V_3 = V_41 -> V_123 ;
unsigned int V_235 , V_236 , V_237 ;
struct V_5 * V_23 [ V_238 ] ;
struct V_239 V_240 [ V_238 ] ;
struct V_5 * V_5 ;
T_1 V_4 , V_230 ;
T_2 V_241 , V_242 ;
int error , V_243 ;
struct V_244 V_245 = {
. V_23 = V_23 ,
. V_240 = V_240 ,
. V_246 = V_238 ,
. V_15 = V_15 ,
. V_247 = & V_248 ,
. V_249 = V_250 ,
} ;
V_241 = F_154 ( V_3 ) ;
if ( F_109 ( * V_227 >= V_241 ) )
return 0 ;
V_242 = V_241 - * V_227 ;
if ( F_109 ( V_242 < V_216 ) )
V_216 = V_242 ;
if ( F_207 ( V_234 , & V_245 ) )
return - V_113 ;
V_4 = * V_227 >> V_59 ;
V_235 = * V_227 & ~ V_229 ;
V_237 = ( V_216 + V_235 + V_22 - 1 ) >> V_59 ;
V_236 = F_3 ( V_237 , V_245 . V_246 ) ;
V_245 . V_236 = F_208 ( V_41 , V_4 ,
V_236 , V_245 . V_23 ) ;
V_4 += V_245 . V_236 ;
error = 0 ;
while ( V_245 . V_236 < V_236 ) {
error = F_4 ( V_3 , V_4 , & V_5 , V_184 , NULL ) ;
if ( error )
break;
F_77 ( V_5 ) ;
V_245 . V_23 [ V_245 . V_236 ++ ] = V_5 ;
V_4 ++ ;
}
V_4 = * V_227 >> V_59 ;
V_236 = V_245 . V_236 ;
V_245 . V_236 = 0 ;
for ( V_243 = 0 ; V_243 < V_236 ; V_243 ++ ) {
unsigned int V_251 ;
if ( ! V_216 )
break;
V_251 = F_209 (unsigned long, len, PAGE_SIZE - loff) ;
V_5 = V_245 . V_23 [ V_243 ] ;
if ( ! F_74 ( V_5 ) || V_5 -> V_41 != V_41 ) {
error = F_4 ( V_3 , V_4 , & V_5 ,
V_184 , NULL ) ;
if ( error )
break;
F_77 ( V_5 ) ;
F_42 ( V_245 . V_23 [ V_243 ] ) ;
V_245 . V_23 [ V_243 ] = V_5 ;
}
V_241 = F_154 ( V_3 ) ;
V_230 = ( V_241 - 1 ) >> V_59 ;
if ( F_109 ( ! V_241 || V_4 > V_230 ) )
break;
if ( V_230 == V_4 ) {
unsigned int V_252 ;
V_252 = ( ( V_241 - 1 ) & ~ V_229 ) + 1 ;
if ( V_252 <= V_235 )
break;
V_251 = F_3 ( V_251 , V_252 - V_235 ) ;
V_216 = V_251 ;
}
V_245 . V_240 [ V_243 ] . V_226 = V_235 ;
V_245 . V_240 [ V_243 ] . V_216 = V_251 ;
V_216 -= V_251 ;
V_235 = 0 ;
V_245 . V_236 ++ ;
V_4 ++ ;
}
while ( V_243 < V_236 )
F_42 ( V_245 . V_23 [ V_243 ++ ] ) ;
if ( V_245 . V_236 )
error = F_210 ( V_234 , & V_245 ) ;
F_211 ( & V_245 ) ;
if ( error > 0 ) {
* V_227 += error ;
F_183 ( V_232 ) ;
}
return error ;
}
static T_1 F_212 ( struct V_40 * V_41 ,
T_1 V_4 , T_1 V_55 , int V_253 )
{
struct V_5 * V_5 ;
struct V_67 V_68 ;
T_1 V_69 [ V_70 ] ;
bool V_254 = false ;
int V_78 ;
F_64 ( & V_68 , 0 ) ;
V_68 . V_71 = 1 ;
while ( ! V_254 ) {
V_68 . V_71 = F_66 ( V_41 , V_4 ,
V_68 . V_71 , V_68 . V_23 , V_69 ) ;
if ( ! V_68 . V_71 ) {
if ( V_253 == V_255 )
V_4 = V_55 ;
break;
}
for ( V_78 = 0 ; V_78 < V_68 . V_71 ; V_78 ++ , V_4 ++ ) {
if ( V_4 < V_69 [ V_78 ] ) {
if ( V_253 == V_256 ) {
V_254 = true ;
break;
}
V_4 = V_69 [ V_78 ] ;
}
V_5 = V_68 . V_23 [ V_78 ] ;
if ( V_5 && ! F_55 ( V_5 ) ) {
if ( ! F_74 ( V_5 ) )
V_5 = NULL ;
}
if ( V_4 >= V_55 ||
( V_5 && V_253 == V_255 ) ||
( ! V_5 && V_253 == V_256 ) ) {
V_254 = true ;
break;
}
}
F_67 ( & V_68 ) ;
F_69 ( & V_68 ) ;
V_68 . V_71 = V_70 ;
F_70 () ;
}
return V_4 ;
}
static T_2 F_213 ( struct V_189 * V_189 , T_2 V_226 , int V_253 )
{
struct V_40 * V_41 = V_189 -> V_194 ;
struct V_3 * V_3 = V_41 -> V_123 ;
T_1 V_54 , V_55 ;
T_2 V_257 ;
if ( V_253 != V_255 && V_253 != V_256 )
return F_214 ( V_189 , V_226 , V_253 ,
V_154 , F_154 ( V_3 ) ) ;
F_215 ( V_3 ) ;
if ( V_226 < 0 )
V_226 = - V_159 ;
else if ( V_226 >= V_3 -> V_66 )
V_226 = - V_258 ;
else {
V_54 = V_226 >> V_59 ;
V_55 = ( V_3 -> V_66 + V_22 - 1 ) >> V_59 ;
V_257 = F_212 ( V_41 , V_54 , V_55 , V_253 ) ;
V_257 <<= V_59 ;
if ( V_257 > V_226 ) {
if ( V_257 < V_3 -> V_66 )
V_226 = V_257 ;
else if ( V_253 == V_255 )
V_226 = - V_258 ;
else
V_226 = V_3 -> V_66 ;
}
}
if ( V_226 >= 0 )
V_226 = F_216 ( V_189 , V_226 , V_154 ) ;
F_217 ( V_3 ) ;
return V_226 ;
}
static void F_218 ( struct V_40 * V_41 )
{
struct V_56 V_57 ;
void * * V_58 ;
T_1 V_54 ;
struct V_5 * V_5 ;
F_219 () ;
V_54 = 0 ;
F_29 () ;
F_51 (slot, &mapping->page_tree, &iter, start) {
V_5 = F_52 ( V_58 ) ;
if ( ! V_5 || F_220 ( V_5 ) ) {
if ( F_53 ( V_5 ) ) {
V_58 = F_54 ( & V_57 ) ;
continue;
}
} else if ( F_221 ( V_5 ) - F_222 ( V_5 ) > 1 ) {
F_38 ( & V_41 -> V_48 ) ;
F_223 ( & V_41 -> V_46 , V_57 . V_4 ,
V_259 ) ;
F_41 ( & V_41 -> V_48 ) ;
}
if ( F_56 () ) {
F_57 () ;
V_58 = F_58 ( & V_57 ) ;
}
}
F_31 () ;
}
static int F_224 ( struct V_40 * V_41 )
{
struct V_56 V_57 ;
void * * V_58 ;
T_1 V_54 ;
struct V_5 * V_5 ;
int error , V_260 ;
F_218 ( V_41 ) ;
error = 0 ;
for ( V_260 = 0 ; V_260 <= V_261 ; V_260 ++ ) {
if ( ! F_225 ( & V_41 -> V_46 , V_259 ) )
break;
if ( ! V_260 )
F_226 () ;
else if ( F_227 ( ( V_262 << V_260 ) / 200 ) )
V_260 = V_261 ;
V_54 = 0 ;
F_29 () ;
F_228 (slot, &mapping->page_tree, &iter,
start, SHMEM_TAG_PINNED) {
V_5 = F_52 ( V_58 ) ;
if ( F_220 ( V_5 ) ) {
if ( F_53 ( V_5 ) ) {
V_58 = F_54 ( & V_57 ) ;
continue;
}
V_5 = NULL ;
}
if ( V_5 &&
F_221 ( V_5 ) - F_222 ( V_5 ) != 1 ) {
if ( V_260 < V_261 )
goto V_263;
error = - V_264 ;
}
F_38 ( & V_41 -> V_48 ) ;
F_229 ( & V_41 -> V_46 ,
V_57 . V_4 , V_259 ) ;
F_41 ( & V_41 -> V_48 ) ;
V_263:
if ( F_56 () ) {
F_57 () ;
V_58 = F_58 ( & V_57 ) ;
}
}
F_31 () ;
}
return error ;
}
int F_230 ( struct V_189 * V_189 , unsigned int V_97 )
{
struct V_3 * V_3 = F_60 ( V_189 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
int error ;
if ( V_189 -> V_265 != & V_207 )
return - V_159 ;
if ( ! ( V_189 -> V_266 & V_267 ) )
return - V_100 ;
if ( V_97 & ~ ( unsigned int ) V_268 )
return - V_159 ;
F_215 ( V_3 ) ;
if ( V_30 -> V_97 & V_200 ) {
error = - V_100 ;
goto V_160;
}
if ( ( V_97 & V_218 ) && ! ( V_30 -> V_97 & V_218 ) ) {
error = F_231 ( V_189 -> V_194 ) ;
if ( error )
goto V_160;
error = F_224 ( V_189 -> V_194 ) ;
if ( error ) {
F_232 ( V_189 -> V_194 ) ;
goto V_160;
}
}
V_30 -> V_97 |= V_97 ;
error = 0 ;
V_160:
F_217 ( V_3 ) ;
return error ;
}
int F_233 ( struct V_189 * V_189 )
{
if ( V_189 -> V_265 != & V_207 )
return - V_159 ;
return F_21 ( F_60 ( V_189 ) ) -> V_97 ;
}
long F_234 ( struct V_189 * V_189 , unsigned int V_269 , unsigned long V_270 )
{
long error ;
switch ( V_269 ) {
case V_271 :
if ( V_270 > V_272 )
return - V_159 ;
error = F_230 ( V_189 , V_270 ) ;
break;
case V_273 :
error = F_233 ( V_189 ) ;
break;
default:
error = - V_159 ;
break;
}
return error ;
}
static long F_235 ( struct V_189 * V_189 , int V_141 , T_2 V_226 ,
T_2 V_216 )
{
struct V_3 * V_3 = F_60 ( V_189 ) ;
struct V_11 * V_24 = F_7 ( V_3 -> V_35 ) ;
struct V_29 * V_30 = F_21 ( V_3 ) ;
struct V_129 V_129 ;
T_1 V_54 , V_4 , V_55 ;
int error ;
if ( V_141 & ~ ( V_274 | V_275 ) )
return - V_276 ;
F_215 ( V_3 ) ;
if ( V_141 & V_275 ) {
struct V_40 * V_41 = V_189 -> V_194 ;
T_2 V_277 = F_88 ( V_226 , V_22 ) ;
T_2 V_278 = F_236 ( V_226 + V_216 , V_22 ) - 1 ;
F_237 ( V_175 ) ;
if ( V_30 -> V_97 & V_218 ) {
error = - V_100 ;
goto V_119;
}
V_129 . V_131 = & V_175 ;
V_129 . V_54 = V_277 >> V_59 ;
V_129 . V_112 = ( V_278 + 1 ) >> V_59 ;
F_17 ( & V_3 -> V_130 ) ;
V_3 -> V_128 = & V_129 ;
F_18 ( & V_3 -> V_130 ) ;
if ( ( V_279 ) V_278 > ( V_279 ) V_277 )
F_89 ( V_41 , V_277 ,
1 + V_278 - V_277 , 0 ) ;
F_81 ( V_3 , V_226 , V_226 + V_216 - 1 ) ;
F_17 ( & V_3 -> V_130 ) ;
V_3 -> V_128 = NULL ;
F_238 ( & V_175 ) ;
F_18 ( & V_3 -> V_130 ) ;
error = 0 ;
goto V_119;
}
error = F_239 ( V_3 , V_226 + V_216 ) ;
if ( error )
goto V_119;
if ( ( V_30 -> V_97 & V_99 ) && V_226 + V_216 > V_3 -> V_66 ) {
error = - V_100 ;
goto V_119;
}
V_54 = V_226 >> V_59 ;
V_55 = ( V_226 + V_216 + V_22 - 1 ) >> V_59 ;
if ( V_24 -> V_36 && V_55 - V_54 > V_24 -> V_36 ) {
error = - V_28 ;
goto V_119;
}
V_129 . V_131 = NULL ;
V_129 . V_54 = V_54 ;
V_129 . V_112 = V_54 ;
V_129 . V_280 = 0 ;
V_129 . V_132 = 0 ;
F_17 ( & V_3 -> V_130 ) ;
V_3 -> V_128 = & V_129 ;
F_18 ( & V_3 -> V_130 ) ;
for ( V_4 = V_54 ; V_4 < V_55 ; V_4 ++ ) {
struct V_5 * V_5 ;
if ( F_240 ( V_18 ) )
error = - V_281 ;
else if ( V_129 . V_132 > V_129 . V_280 )
error = - V_113 ;
else
error = F_4 ( V_3 , V_4 , & V_5 , V_158 ,
NULL ) ;
if ( error ) {
F_71 ( V_3 ,
( T_2 ) V_54 << V_59 ,
( T_2 ) V_4 << V_59 , true ) ;
goto V_282;
}
V_129 . V_112 ++ ;
if ( ! F_74 ( V_5 ) )
V_129 . V_280 ++ ;
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
F_70 () ;
}
if ( ! ( V_141 & V_274 ) && V_226 + V_216 > V_3 -> V_66 )
F_87 ( V_3 , V_226 + V_216 ) ;
V_3 -> V_82 = V_84 ;
V_282:
F_17 ( & V_3 -> V_130 ) ;
V_3 -> V_128 = NULL ;
F_18 ( & V_3 -> V_130 ) ;
V_119:
F_217 ( V_3 ) ;
return error ;
}
static int F_241 ( struct V_87 * V_87 , struct V_283 * V_284 )
{
struct V_11 * V_24 = F_7 ( V_87 -> V_285 ) ;
V_284 -> V_286 = V_287 ;
V_284 -> V_288 = V_22 ;
V_284 -> V_289 = V_290 ;
if ( V_24 -> V_36 ) {
V_284 -> V_291 = V_24 -> V_36 ;
V_284 -> V_292 =
V_284 -> V_293 = V_24 -> V_36 -
F_242 ( & V_24 -> V_37 ) ;
}
if ( V_24 -> V_25 ) {
V_284 -> V_294 = V_24 -> V_25 ;
V_284 -> V_295 = V_24 -> V_27 ;
}
return 0 ;
}
static int
F_243 ( struct V_3 * V_196 , struct V_87 * V_87 , T_6 V_141 , T_7 V_197 )
{
struct V_3 * V_3 ;
int error = - V_28 ;
V_3 = F_184 ( V_196 -> V_35 , V_196 , V_141 , V_197 , V_17 ) ;
if ( V_3 ) {
error = F_244 ( V_196 , V_3 ) ;
if ( error )
goto V_296;
error = F_245 ( V_3 , V_196 ,
& V_87 -> V_297 ,
V_298 , NULL ) ;
if ( error && error != - V_276 )
goto V_296;
error = 0 ;
V_196 -> V_66 += V_209 ;
V_196 -> V_82 = V_196 -> V_83 = V_84 ;
F_246 ( V_87 , V_3 ) ;
F_247 ( V_87 ) ;
}
return error ;
V_296:
F_248 ( V_3 ) ;
return error ;
}
static int
F_249 ( struct V_3 * V_196 , struct V_87 * V_87 , T_6 V_141 )
{
struct V_3 * V_3 ;
int error = - V_28 ;
V_3 = F_184 ( V_196 -> V_35 , V_196 , V_141 , 0 , V_17 ) ;
if ( V_3 ) {
error = F_245 ( V_3 , V_196 ,
NULL ,
V_298 , NULL ) ;
if ( error && error != - V_276 )
goto V_296;
error = F_244 ( V_196 , V_3 ) ;
if ( error )
goto V_296;
F_250 ( V_87 , V_3 ) ;
}
return error ;
V_296:
F_248 ( V_3 ) ;
return error ;
}
static int F_251 ( struct V_3 * V_196 , struct V_87 * V_87 , T_6 V_141 )
{
int error ;
if ( ( error = F_243 ( V_196 , V_87 , V_141 | V_208 , 0 ) ) )
return error ;
F_195 ( V_196 ) ;
return 0 ;
}
static int F_252 ( struct V_3 * V_196 , struct V_87 * V_87 , T_6 V_141 ,
bool V_299 )
{
return F_243 ( V_196 , V_87 , V_141 | V_204 , 0 ) ;
}
static int F_253 ( struct V_87 * V_300 , struct V_3 * V_196 , struct V_87 * V_87 )
{
struct V_3 * V_3 = V_90 ( V_300 ) ;
int V_172 ;
V_172 = F_16 ( V_3 -> V_35 ) ;
if ( V_172 )
goto V_119;
V_196 -> V_66 += V_209 ;
V_3 -> V_82 = V_196 -> V_82 = V_196 -> V_83 = V_84 ;
F_195 ( V_3 ) ;
F_254 ( V_3 ) ;
F_247 ( V_87 ) ;
F_246 ( V_87 , V_3 ) ;
V_119:
return V_172 ;
}
static int F_255 ( struct V_3 * V_196 , struct V_87 * V_87 )
{
struct V_3 * V_3 = V_90 ( V_87 ) ;
if ( V_3 -> V_301 > 1 && ! F_256 ( V_3 -> V_93 ) )
F_19 ( V_3 -> V_35 ) ;
V_196 -> V_66 -= V_209 ;
V_3 -> V_82 = V_196 -> V_82 = V_196 -> V_83 = V_84 ;
F_257 ( V_3 ) ;
F_258 ( V_87 ) ;
return 0 ;
}
static int F_259 ( struct V_3 * V_196 , struct V_87 * V_87 )
{
if ( ! F_260 ( V_87 ) )
return - V_302 ;
F_257 ( V_90 ( V_87 ) ) ;
F_257 ( V_196 ) ;
return F_255 ( V_196 , V_87 ) ;
}
static int F_261 ( struct V_3 * V_303 , struct V_87 * V_300 , struct V_3 * V_304 , struct V_87 * V_305 )
{
bool V_306 = F_262 ( V_300 ) ;
bool V_307 = F_262 ( V_305 ) ;
if ( V_303 != V_304 && V_306 != V_307 ) {
if ( V_306 ) {
F_257 ( V_303 ) ;
F_195 ( V_304 ) ;
} else {
F_257 ( V_304 ) ;
F_195 ( V_303 ) ;
}
}
V_303 -> V_82 = V_303 -> V_83 =
V_304 -> V_82 = V_304 -> V_83 =
V_90 ( V_300 ) -> V_82 =
V_90 ( V_305 ) -> V_82 = V_84 ;
return 0 ;
}
static int F_263 ( struct V_3 * V_303 , struct V_87 * V_300 )
{
struct V_87 * V_308 ;
int error ;
V_308 = F_264 ( V_300 -> V_309 , & V_300 -> V_297 ) ;
if ( ! V_308 )
return - V_113 ;
error = F_243 ( V_303 , V_308 ,
V_310 | V_311 , V_312 ) ;
F_258 ( V_308 ) ;
if ( error )
return error ;
F_265 ( V_308 ) ;
return 0 ;
}
static int F_266 ( struct V_3 * V_303 , struct V_87 * V_300 , struct V_3 * V_304 , struct V_87 * V_305 , unsigned int V_15 )
{
struct V_3 * V_3 = V_90 ( V_300 ) ;
int V_313 = F_256 ( V_3 -> V_93 ) ;
if ( V_15 & ~ ( V_314 | V_315 | V_316 ) )
return - V_159 ;
if ( V_15 & V_315 )
return F_261 ( V_303 , V_300 , V_304 , V_305 ) ;
if ( ! F_260 ( V_305 ) )
return - V_302 ;
if ( V_15 & V_316 ) {
int error ;
error = F_263 ( V_303 , V_300 ) ;
if ( error )
return error ;
}
if ( F_267 ( V_305 ) ) {
( void ) F_255 ( V_304 , V_305 ) ;
if ( V_313 ) {
F_257 ( V_90 ( V_305 ) ) ;
F_257 ( V_303 ) ;
}
} else if ( V_313 ) {
F_257 ( V_303 ) ;
F_195 ( V_304 ) ;
}
V_303 -> V_66 -= V_209 ;
V_304 -> V_66 += V_209 ;
V_303 -> V_82 = V_303 -> V_83 =
V_304 -> V_82 = V_304 -> V_83 =
V_3 -> V_82 = V_84 ;
return 0 ;
}
static int F_268 ( struct V_3 * V_196 , struct V_87 * V_87 , const char * V_317 )
{
int error ;
int V_216 ;
struct V_3 * V_3 ;
struct V_5 * V_5 ;
struct V_29 * V_30 ;
V_216 = strlen ( V_317 ) + 1 ;
if ( V_216 > V_22 )
return - V_318 ;
V_3 = F_184 ( V_196 -> V_35 , V_196 , V_212 | V_319 , 0 , V_17 ) ;
if ( ! V_3 )
return - V_28 ;
error = F_245 ( V_3 , V_196 , & V_87 -> V_297 ,
V_298 , NULL ) ;
if ( error ) {
if ( error != - V_276 ) {
F_248 ( V_3 ) ;
return error ;
}
error = 0 ;
}
V_30 = F_21 ( V_3 ) ;
V_3 -> V_66 = V_216 - 1 ;
if ( V_216 <= V_320 ) {
V_3 -> V_321 = F_269 ( V_317 , V_216 , V_120 ) ;
if ( ! V_3 -> V_321 ) {
F_248 ( V_3 ) ;
return - V_113 ;
}
V_3 -> V_202 = & V_322 ;
} else {
F_270 ( V_3 ) ;
error = F_4 ( V_3 , 0 , & V_5 , V_157 , NULL ) ;
if ( error ) {
F_248 ( V_3 ) ;
return error ;
}
V_3 -> V_10 -> V_103 = & V_104 ;
V_3 -> V_202 = & V_323 ;
memcpy ( F_271 ( V_5 ) , V_317 , V_216 ) ;
F_121 ( V_5 ) ;
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
}
V_196 -> V_66 += V_209 ;
V_196 -> V_82 = V_196 -> V_83 = V_84 ;
F_246 ( V_87 , V_3 ) ;
F_247 ( V_87 ) ;
return 0 ;
}
static void F_272 ( void * V_270 )
{
F_155 ( V_270 ) ;
F_42 ( V_270 ) ;
}
static const char * F_273 ( struct V_87 * V_87 ,
struct V_3 * V_3 ,
struct V_324 * V_254 )
{
struct V_5 * V_5 = NULL ;
int error ;
if ( ! V_87 ) {
V_5 = F_274 ( V_3 -> V_10 , 0 ) ;
if ( ! V_5 )
return F_275 ( - V_325 ) ;
if ( ! F_74 ( V_5 ) ) {
F_42 ( V_5 ) ;
return F_275 ( - V_325 ) ;
}
} else {
error = F_4 ( V_3 , 0 , & V_5 , V_79 , NULL ) ;
if ( error )
return F_275 ( error ) ;
F_77 ( V_5 ) ;
}
F_276 ( V_254 , F_272 , V_5 ) ;
return F_271 ( V_5 ) ;
}
static int V_298 ( struct V_3 * V_3 ,
const struct V_326 * V_327 ,
void * V_328 )
{
struct V_29 * V_30 = F_21 ( V_3 ) ;
const struct V_326 * V_326 ;
struct V_329 * V_330 ;
T_9 V_216 ;
for ( V_326 = V_327 ; V_326 -> V_331 != NULL ; V_326 ++ ) {
V_330 = F_277 ( V_326 -> V_332 , V_326 -> V_333 ) ;
if ( ! V_330 )
return - V_113 ;
V_216 = strlen ( V_326 -> V_331 ) + 1 ;
V_330 -> V_331 = F_278 ( V_334 + V_216 ,
V_120 ) ;
if ( ! V_330 -> V_331 ) {
F_279 ( V_330 ) ;
return - V_113 ;
}
memcpy ( V_330 -> V_331 , V_335 ,
V_334 ) ;
memcpy ( V_330 -> V_331 + V_334 ,
V_326 -> V_331 , V_216 ) ;
F_280 ( & V_30 -> V_107 , V_330 ) ;
}
return 0 ;
}
static int F_281 ( const struct V_336 * V_337 ,
struct V_87 * V_87 , const char * V_331 ,
void * V_140 , T_9 V_16 )
{
struct V_29 * V_30 = F_21 ( V_90 ( V_87 ) ) ;
V_331 = F_282 ( V_337 , V_331 ) ;
return F_283 ( & V_30 -> V_107 , V_331 , V_140 , V_16 ) ;
}
static int F_284 ( const struct V_336 * V_337 ,
struct V_87 * V_87 , const char * V_331 ,
const void * V_332 , T_9 V_16 , int V_15 )
{
struct V_29 * V_30 = F_21 ( V_90 ( V_87 ) ) ;
V_331 = F_282 ( V_337 , V_331 ) ;
return F_285 ( & V_30 -> V_107 , V_331 , V_332 , V_16 , V_15 ) ;
}
static T_8 F_286 ( struct V_87 * V_87 , char * V_140 , T_9 V_16 )
{
struct V_29 * V_30 = F_21 ( V_90 ( V_87 ) ) ;
return F_287 ( V_90 ( V_87 ) , & V_30 -> V_107 , V_140 , V_16 ) ;
}
static struct V_87 * F_288 ( struct V_87 * V_338 )
{
return F_275 ( - V_339 ) ;
}
static int F_289 ( struct V_3 * V_340 , void * V_341 )
{
T_10 * V_342 = V_341 ;
T_11 V_343 = V_342 [ 2 ] ;
V_343 = ( V_343 << 32 ) | V_342 [ 1 ] ;
return V_340 -> V_144 == V_343 && V_342 [ 0 ] == V_340 -> V_199 ;
}
static struct V_87 * F_290 ( struct V_12 * V_13 ,
struct V_344 * V_344 , int V_345 , int V_346 )
{
struct V_3 * V_3 ;
struct V_87 * V_87 = NULL ;
V_279 V_343 ;
if ( V_345 < 3 )
return NULL ;
V_343 = V_344 -> V_347 [ 2 ] ;
V_343 = ( V_343 << 32 ) | V_344 -> V_347 [ 1 ] ;
V_3 = F_291 ( V_13 , ( unsigned long ) ( V_343 + V_344 -> V_347 [ 0 ] ) ,
F_289 , V_344 -> V_347 ) ;
if ( V_3 ) {
V_87 = F_292 ( V_3 ) ;
F_248 ( V_3 ) ;
}
return V_87 ;
}
static int F_293 ( struct V_3 * V_3 , T_10 * V_342 , int * V_216 ,
struct V_3 * V_348 )
{
if ( * V_216 < 3 ) {
* V_216 = 3 ;
return V_349 ;
}
if ( F_294 ( V_3 ) ) {
static F_295 ( V_81 ) ;
F_17 ( & V_81 ) ;
if ( F_294 ( V_3 ) )
F_296 ( V_3 ,
V_3 -> V_144 + V_3 -> V_199 ) ;
F_18 ( & V_81 ) ;
}
V_342 [ 0 ] = V_3 -> V_199 ;
V_342 [ 1 ] = V_3 -> V_144 ;
V_342 [ 2 ] = ( ( T_11 ) V_3 -> V_144 ) >> 32 ;
* V_216 = 3 ;
return 1 ;
}
static int F_297 ( char * V_350 , struct V_11 * V_24 ,
bool V_351 )
{
char * V_352 , * V_332 , * V_353 ;
struct V_138 * V_139 = NULL ;
T_12 V_354 ;
T_13 V_355 ;
while ( V_350 != NULL ) {
V_352 = V_350 ;
for (; ; ) {
V_350 = strchr ( V_350 , ',' ) ;
if ( V_350 == NULL )
break;
V_350 ++ ;
if ( ! isdigit ( * V_350 ) ) {
V_350 [ - 1 ] = '\0' ;
break;
}
}
if ( ! * V_352 )
continue;
if ( ( V_332 = strchr ( V_352 , '=' ) ) != NULL ) {
* V_332 ++ = 0 ;
} else {
F_298 ( L_2 ,
V_352 ) ;
goto error;
}
if ( ! strcmp ( V_352 , L_3 ) ) {
unsigned long long V_16 ;
V_16 = F_299 ( V_332 , & V_353 ) ;
if ( * V_353 == '%' ) {
V_16 <<= V_59 ;
V_16 *= V_1 ;
F_300 ( V_16 , 100 ) ;
V_353 ++ ;
}
if ( * V_353 )
goto V_356;
V_24 -> V_36 =
F_301 ( V_16 , V_22 ) ;
} else if ( ! strcmp ( V_352 , L_4 ) ) {
V_24 -> V_36 = F_299 ( V_332 , & V_353 ) ;
if ( * V_353 )
goto V_356;
} else if ( ! strcmp ( V_352 , L_5 ) ) {
V_24 -> V_25 = F_299 ( V_332 , & V_353 ) ;
if ( * V_353 )
goto V_356;
} else if ( ! strcmp ( V_352 , L_6 ) ) {
if ( V_351 )
continue;
V_24 -> V_141 = F_302 ( V_332 , & V_353 , 8 ) & 07777 ;
if ( * V_353 )
goto V_356;
} else if ( ! strcmp ( V_352 , L_7 ) ) {
if ( V_351 )
continue;
V_354 = F_302 ( V_332 , & V_353 , 0 ) ;
if ( * V_353 )
goto V_356;
V_24 -> V_354 = F_303 ( F_304 () , V_354 ) ;
if ( ! F_305 ( V_24 -> V_354 ) )
goto V_356;
} else if ( ! strcmp ( V_352 , L_8 ) ) {
if ( V_351 )
continue;
V_355 = F_302 ( V_332 , & V_353 , 0 ) ;
if ( * V_353 )
goto V_356;
V_24 -> V_355 = F_306 ( F_304 () , V_355 ) ;
if ( ! F_307 ( V_24 -> V_355 ) )
goto V_356;
} else if ( ! strcmp ( V_352 , L_9 ) ) {
F_308 ( V_139 ) ;
V_139 = NULL ;
if ( F_309 ( V_332 , & V_139 ) )
goto V_356;
} else {
F_298 ( L_10 , V_352 ) ;
goto error;
}
}
V_24 -> V_139 = V_139 ;
return 0 ;
V_356:
F_298 ( L_11 ,
V_332 , V_352 ) ;
error:
F_308 ( V_139 ) ;
return 1 ;
}
static int F_310 ( struct V_12 * V_13 , int * V_15 , char * V_357 )
{
struct V_11 * V_24 = F_7 ( V_13 ) ;
struct V_11 V_358 = * V_24 ;
unsigned long V_359 ;
int error = - V_159 ;
V_358 . V_139 = NULL ;
if ( F_297 ( V_357 , & V_358 , true ) )
return error ;
F_17 ( & V_24 -> V_26 ) ;
V_359 = V_24 -> V_25 - V_24 -> V_27 ;
if ( F_158 ( & V_24 -> V_37 , V_358 . V_36 ) > 0 )
goto V_119;
if ( V_358 . V_25 < V_359 )
goto V_119;
if ( V_358 . V_36 && ! V_24 -> V_36 )
goto V_119;
if ( V_358 . V_25 && ! V_24 -> V_25 )
goto V_119;
error = 0 ;
V_24 -> V_36 = V_358 . V_36 ;
V_24 -> V_25 = V_358 . V_25 ;
V_24 -> V_27 = V_358 . V_25 - V_359 ;
if ( V_358 . V_139 ) {
F_308 ( V_24 -> V_139 ) ;
V_24 -> V_139 = V_358 . V_139 ;
}
V_119:
F_18 ( & V_24 -> V_26 ) ;
return error ;
}
static int F_311 ( struct V_136 * V_137 , struct V_87 * V_360 )
{
struct V_11 * V_24 = F_7 ( V_360 -> V_285 ) ;
if ( V_24 -> V_36 != F_1 () )
F_132 ( V_137 , L_12 ,
V_24 -> V_36 << ( V_59 - 10 ) ) ;
if ( V_24 -> V_25 != F_2 () )
F_132 ( V_137 , L_13 , V_24 -> V_25 ) ;
if ( V_24 -> V_141 != ( V_319 | V_361 ) )
F_132 ( V_137 , L_14 , V_24 -> V_141 ) ;
if ( ! F_312 ( V_24 -> V_354 , V_362 ) )
F_132 ( V_137 , L_15 ,
F_313 ( & V_363 , V_24 -> V_354 ) ) ;
if ( ! F_314 ( V_24 -> V_355 , V_364 ) )
F_132 ( V_137 , L_16 ,
F_315 ( & V_363 , V_24 -> V_355 ) ) ;
F_130 ( V_137 , V_24 -> V_139 ) ;
return 0 ;
}
static void F_316 ( struct V_12 * V_13 )
{
struct V_11 * V_24 = F_7 ( V_13 ) ;
F_317 ( & V_24 -> V_37 ) ;
F_308 ( V_24 -> V_139 ) ;
F_279 ( V_24 ) ;
V_13 -> V_14 = NULL ;
}
int F_318 ( struct V_12 * V_13 , void * V_357 , int V_365 )
{
struct V_3 * V_3 ;
struct V_11 * V_24 ;
int V_366 = - V_113 ;
V_24 = F_319 ( F_320 ( ( int ) sizeof( struct V_11 ) ,
V_367 ) , V_120 ) ;
if ( ! V_24 )
return - V_113 ;
V_24 -> V_141 = V_319 | V_361 ;
V_24 -> V_354 = F_321 () ;
V_24 -> V_355 = F_322 () ;
V_13 -> V_14 = V_24 ;
#ifdef F_323
if ( ! ( V_13 -> V_368 & V_369 ) ) {
V_24 -> V_36 = F_1 () ;
V_24 -> V_25 = F_2 () ;
if ( F_297 ( V_357 , V_24 , false ) ) {
V_366 = - V_159 ;
goto V_163;
}
} else {
V_13 -> V_368 |= V_370 ;
}
V_13 -> V_371 = & V_372 ;
V_13 -> V_368 |= V_373 ;
#else
V_13 -> V_368 |= V_370 ;
#endif
F_189 ( & V_24 -> V_26 ) ;
if ( F_324 ( & V_24 -> V_37 , 0 , V_120 ) )
goto V_163;
V_24 -> V_27 = V_24 -> V_25 ;
V_13 -> V_374 = V_154 ;
V_13 -> V_375 = V_22 ;
V_13 -> V_376 = V_59 ;
V_13 -> V_377 = V_287 ;
V_13 -> V_213 = & V_214 ;
V_13 -> V_378 = 1 ;
#ifdef F_325
V_13 -> V_379 = V_380 ;
#endif
#ifdef F_326
V_13 -> V_368 |= V_381 ;
#endif
V_3 = F_184 ( V_13 , NULL , V_208 | V_24 -> V_141 , 0 , V_17 ) ;
if ( ! V_3 )
goto V_163;
V_3 -> V_382 = V_24 -> V_354 ;
V_3 -> V_383 = V_24 -> V_355 ;
V_13 -> V_384 = F_327 ( V_3 ) ;
if ( ! V_13 -> V_384 )
goto V_163;
return 0 ;
V_163:
F_316 ( V_13 ) ;
return V_366 ;
}
static struct V_3 * F_328 ( struct V_12 * V_13 )
{
struct V_29 * V_30 ;
V_30 = F_329 ( V_385 , V_120 ) ;
if ( ! V_30 )
return NULL ;
return & V_30 -> V_108 ;
}
static void F_330 ( struct V_386 * V_387 )
{
struct V_3 * V_3 = F_331 ( V_387 , struct V_3 , V_388 ) ;
F_279 ( V_3 -> V_321 ) ;
F_332 ( V_385 , F_21 ( V_3 ) ) ;
}
static void F_333 ( struct V_3 * V_3 )
{
if ( F_86 ( V_3 -> V_93 ) )
F_334 ( & F_21 ( V_3 ) -> V_147 ) ;
F_335 ( & V_3 -> V_388 , F_330 ) ;
}
static void F_336 ( void * V_389 )
{
struct V_29 * V_30 = V_389 ;
F_337 ( & V_30 -> V_108 ) ;
}
static int F_338 ( void )
{
V_385 = F_339 ( L_17 ,
sizeof( struct V_29 ) ,
0 , V_390 | V_391 , F_336 ) ;
return 0 ;
}
static void F_340 ( void )
{
F_341 ( V_385 ) ;
}
static struct V_87 * F_342 ( struct V_392 * V_393 ,
int V_15 , const char * V_394 , void * V_357 )
{
return F_343 ( V_393 , V_15 , V_357 , F_318 ) ;
}
int T_14 F_344 ( void )
{
int error ;
if ( V_385 )
return 0 ;
error = F_338 () ;
if ( error )
goto V_395;
error = F_345 ( & V_396 ) ;
if ( error ) {
F_298 ( L_18 ) ;
goto V_397;
}
V_398 = F_346 ( & V_396 ) ;
if ( F_347 ( V_398 ) ) {
error = F_348 ( V_398 ) ;
F_298 ( L_19 ) ;
goto V_399;
}
return 0 ;
V_399:
F_349 ( & V_396 ) ;
V_397:
F_340 () ;
V_395:
V_398 = F_275 ( error ) ;
return error ;
}
int T_14 F_344 ( void )
{
F_45 ( F_345 ( & V_396 ) != 0 ) ;
V_398 = F_346 ( & V_396 ) ;
F_45 ( F_347 ( V_398 ) ) ;
return 0 ;
}
int F_108 ( T_3 V_49 , struct V_5 * V_5 )
{
return 0 ;
}
int F_177 ( struct V_189 * V_189 , int V_81 , struct V_190 * V_191 )
{
return 0 ;
}
void F_63 ( struct V_40 * V_41 )
{
}
void F_81 ( struct V_3 * V_3 , T_2 V_72 , T_2 V_73 )
{
F_350 ( V_3 -> V_10 , V_72 , V_73 ) ;
}
static struct V_189 * F_351 ( const char * V_331 , T_2 V_16 ,
unsigned long V_15 , unsigned int V_400 )
{
struct V_189 * V_401 ;
struct V_3 * V_3 ;
struct V_402 V_402 ;
struct V_12 * V_13 ;
struct V_403 V_115 ;
if ( F_347 ( V_398 ) )
return F_352 ( V_398 ) ;
if ( V_16 < 0 || V_16 > V_154 )
return F_275 ( - V_159 ) ;
if ( F_8 ( V_15 , V_16 ) )
return F_275 ( - V_113 ) ;
V_401 = F_275 ( - V_113 ) ;
V_115 . V_331 = V_331 ;
V_115 . V_216 = strlen ( V_331 ) ;
V_115 . V_404 = 0 ;
V_13 = V_398 -> V_405 ;
V_402 . V_86 = F_353 ( V_398 ) ;
V_402 . V_87 = F_354 ( V_13 , & V_115 ) ;
if ( ! V_402 . V_87 )
goto V_406;
F_355 ( V_402 . V_87 , & V_407 ) ;
V_401 = F_275 ( - V_28 ) ;
V_3 = F_184 ( V_13 , NULL , V_204 | V_319 , 0 , V_15 ) ;
if ( ! V_3 )
goto V_406;
V_3 -> V_400 |= V_400 ;
F_246 ( V_402 . V_87 , V_3 ) ;
V_3 -> V_66 = V_16 ;
F_356 ( V_3 ) ;
V_401 = F_275 ( F_357 ( V_3 , V_16 ) ) ;
if ( F_347 ( V_401 ) )
goto V_408;
V_401 = F_358 ( & V_402 , V_267 | V_409 ,
& V_207 ) ;
if ( F_347 ( V_401 ) )
goto V_408;
return V_401 ;
V_406:
F_11 ( V_15 , V_16 ) ;
V_408:
F_359 ( & V_402 ) ;
return V_401 ;
}
struct V_189 * F_360 ( const char * V_331 , T_2 V_16 , unsigned long V_15 )
{
return F_351 ( V_331 , V_16 , V_15 , V_410 ) ;
}
struct V_189 * F_361 ( const char * V_331 , T_2 V_16 , unsigned long V_15 )
{
return F_351 ( V_331 , V_16 , V_15 , 0 ) ;
}
int F_362 ( struct V_60 * V_61 )
{
struct V_189 * V_189 ;
T_2 V_16 = V_61 -> V_64 - V_61 -> V_65 ;
V_189 = F_351 ( L_20 , V_16 , V_61 -> V_411 , V_410 ) ;
if ( F_347 ( V_189 ) )
return F_348 ( V_189 ) ;
if ( V_61 -> V_62 )
F_363 ( V_61 -> V_62 ) ;
V_61 -> V_62 = V_189 ;
V_61 -> V_145 = & V_195 ;
return 0 ;
}
struct V_5 * F_364 ( struct V_40 * V_41 ,
T_1 V_4 , T_4 V_109 )
{
#ifdef F_365
struct V_3 * V_3 = V_41 -> V_123 ;
struct V_5 * V_5 ;
int error ;
F_45 ( V_41 -> V_103 != & V_104 ) ;
error = F_5 ( V_3 , V_4 , & V_5 , V_184 , V_109 , NULL ) ;
if ( error )
V_5 = F_275 ( error ) ;
else
F_77 ( V_5 ) ;
return V_5 ;
#else
return F_366 ( V_41 , V_4 , V_109 ) ;
#endif
}
