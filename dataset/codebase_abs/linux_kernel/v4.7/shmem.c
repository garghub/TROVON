static unsigned long F_1 ( void )
{
return V_1 / 2 ;
}
static unsigned long F_2 ( void )
{
return F_3 ( V_1 - V_2 , V_1 / 2 ) ;
}
static inline int F_4 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 )
{
return F_5 ( V_3 , V_4 , V_6 , V_8 ,
F_6 ( V_3 -> V_9 ) , NULL , NULL ) ;
}
static inline struct V_10 * F_7 ( struct V_11 * V_12 )
{
return V_12 -> V_13 ;
}
static inline int F_8 ( unsigned long V_14 , T_2 V_15 )
{
return ( V_14 & V_16 ) ?
0 : F_9 ( V_17 -> V_18 , F_10 ( V_15 ) ) ;
}
static inline void F_11 ( unsigned long V_14 , T_2 V_15 )
{
if ( ! ( V_14 & V_16 ) )
F_12 ( F_10 ( V_15 ) ) ;
}
static inline int F_13 ( unsigned long V_14 ,
T_2 V_19 , T_2 V_20 )
{
if ( ! ( V_14 & V_16 ) ) {
if ( F_10 ( V_20 ) > F_10 ( V_19 ) )
return F_9 ( V_17 -> V_18 ,
F_10 ( V_20 ) - F_10 ( V_19 ) ) ;
else if ( F_10 ( V_20 ) < F_10 ( V_19 ) )
F_12 ( F_10 ( V_19 ) - F_10 ( V_20 ) ) ;
}
return 0 ;
}
static inline int F_14 ( unsigned long V_14 )
{
return ( V_14 & V_16 ) ?
F_9 ( V_17 -> V_18 , F_10 ( V_21 ) ) : 0 ;
}
static inline void F_15 ( unsigned long V_14 , long V_22 )
{
if ( V_14 & V_16 )
F_12 ( V_22 * F_10 ( V_21 ) ) ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( V_23 -> V_24 ) {
F_17 ( & V_23 -> V_25 ) ;
if ( ! V_23 -> V_26 ) {
F_18 ( & V_23 -> V_25 ) ;
return - V_27 ;
}
V_23 -> V_26 -- ;
F_18 ( & V_23 -> V_25 ) ;
}
return 0 ;
}
static void F_19 ( struct V_11 * V_12 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( V_23 -> V_24 ) {
F_17 ( & V_23 -> V_25 ) ;
V_23 -> V_26 ++ ;
F_18 ( & V_23 -> V_25 ) ;
}
}
static void F_20 ( struct V_3 * V_3 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
long V_30 ;
V_30 = V_29 -> V_31 - V_29 -> V_32 - V_3 -> V_9 -> V_33 ;
if ( V_30 > 0 ) {
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
if ( V_23 -> V_35 )
F_22 ( & V_23 -> V_36 , - V_30 ) ;
V_29 -> V_31 -= V_30 ;
V_3 -> V_37 -= V_30 * V_38 ;
F_15 ( V_29 -> V_14 , V_30 ) ;
}
}
static int F_23 ( struct V_39 * V_40 ,
T_1 V_4 , void * V_41 , void * V_42 )
{
void * * V_43 ;
void * V_44 ;
F_24 ( ! V_41 ) ;
F_24 ( ! V_42 ) ;
V_43 = F_25 ( & V_40 -> V_45 , V_4 ) ;
if ( ! V_43 )
return - V_46 ;
V_44 = F_26 ( V_43 , & V_40 -> V_47 ) ;
if ( V_44 != V_41 )
return - V_46 ;
F_27 ( V_43 , V_42 ) ;
return 0 ;
}
static bool F_28 ( struct V_39 * V_40 ,
T_1 V_4 , T_3 V_48 )
{
void * V_44 ;
F_29 () ;
V_44 = F_30 ( & V_40 -> V_45 , V_4 ) ;
F_31 () ;
return V_44 == F_32 ( V_48 ) ;
}
static int F_33 ( struct V_5 * V_5 ,
struct V_39 * V_40 ,
T_1 V_4 , void * V_41 )
{
int error ;
F_34 ( ! F_35 ( V_5 ) , V_5 ) ;
F_34 ( ! F_36 ( V_5 ) , V_5 ) ;
F_37 ( V_5 ) ;
V_5 -> V_40 = V_40 ;
V_5 -> V_4 = V_4 ;
F_38 ( & V_40 -> V_47 ) ;
if ( ! V_41 )
error = F_39 ( & V_40 -> V_45 , V_4 , V_5 ) ;
else
error = F_23 ( V_40 , V_4 , V_41 ,
V_5 ) ;
if ( ! error ) {
V_40 -> V_33 ++ ;
F_40 ( V_5 , V_49 ) ;
F_40 ( V_5 , V_50 ) ;
F_41 ( & V_40 -> V_47 ) ;
} else {
V_5 -> V_40 = NULL ;
F_41 ( & V_40 -> V_47 ) ;
F_42 ( V_5 ) ;
}
return error ;
}
static void F_43 ( struct V_5 * V_5 , void * V_51 )
{
struct V_39 * V_40 = V_5 -> V_40 ;
int error ;
F_38 ( & V_40 -> V_47 ) ;
error = F_23 ( V_40 , V_5 -> V_4 , V_5 , V_51 ) ;
V_5 -> V_40 = NULL ;
V_40 -> V_33 -- ;
F_44 ( V_5 , V_49 ) ;
F_44 ( V_5 , V_50 ) ;
F_41 ( & V_40 -> V_47 ) ;
F_42 ( V_5 ) ;
F_45 ( error ) ;
}
static int F_46 ( struct V_39 * V_40 ,
T_1 V_4 , void * V_51 )
{
void * V_52 ;
F_38 ( & V_40 -> V_47 ) ;
V_52 = F_47 ( & V_40 -> V_45 , V_4 , V_51 ) ;
F_41 ( & V_40 -> V_47 ) ;
if ( V_52 != V_51 )
return - V_46 ;
F_48 ( F_49 ( V_51 ) ) ;
return 0 ;
}
unsigned long F_50 ( struct V_39 * V_40 ,
T_1 V_53 , T_1 V_54 )
{
struct V_55 V_56 ;
void * * V_57 ;
struct V_5 * V_5 ;
unsigned long V_32 = 0 ;
F_29 () ;
F_51 (slot, &mapping->page_tree, &iter, start) {
if ( V_56 . V_4 >= V_54 )
break;
V_5 = F_52 ( V_57 ) ;
if ( F_53 ( V_5 ) ) {
V_57 = F_54 ( & V_56 ) ;
continue;
}
if ( F_55 ( V_5 ) )
V_32 ++ ;
if ( F_56 () ) {
F_57 () ;
V_57 = F_58 ( & V_56 ) ;
}
}
F_31 () ;
return V_32 << V_58 ;
}
unsigned long F_59 ( struct V_59 * V_60 )
{
struct V_3 * V_3 = F_60 ( V_60 -> V_61 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_39 * V_40 = V_3 -> V_9 ;
unsigned long V_32 ;
V_32 = F_61 ( V_29 -> V_32 ) ;
if ( ! V_32 )
return 0 ;
if ( ! V_60 -> V_62 && V_60 -> V_63 - V_60 -> V_64 >= V_3 -> V_65 )
return V_32 << V_58 ;
return F_50 ( V_40 ,
F_62 ( V_60 , V_60 -> V_64 ) ,
F_62 ( V_60 , V_60 -> V_63 ) ) ;
}
void F_63 ( struct V_39 * V_40 )
{
struct V_66 V_67 ;
T_1 V_68 [ V_69 ] ;
T_1 V_4 = 0 ;
F_64 ( & V_67 , 0 ) ;
while ( ! F_65 ( V_40 ) ) {
V_67 . V_70 = F_66 ( V_40 , V_4 ,
V_69 , V_67 . V_22 , V_68 ) ;
if ( ! V_67 . V_70 )
break;
V_4 = V_68 [ V_67 . V_70 - 1 ] + 1 ;
F_67 ( & V_67 ) ;
F_68 ( V_67 . V_22 , V_67 . V_70 ) ;
F_69 ( & V_67 ) ;
F_70 () ;
}
}
static void F_71 ( struct V_3 * V_3 , T_2 V_71 , T_2 V_72 ,
bool V_73 )
{
struct V_39 * V_40 = V_3 -> V_9 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
T_1 V_53 = ( V_71 + V_21 - 1 ) >> V_58 ;
T_1 V_54 = ( V_72 + 1 ) >> V_58 ;
unsigned int V_74 = V_71 & ( V_21 - 1 ) ;
unsigned int V_75 = ( V_72 + 1 ) & ( V_21 - 1 ) ;
struct V_66 V_67 ;
T_1 V_68 [ V_69 ] ;
long V_76 = 0 ;
T_1 V_4 ;
int V_77 ;
if ( V_72 == - 1 )
V_54 = - 1 ;
F_64 ( & V_67 , 0 ) ;
V_4 = V_53 ;
while ( V_4 < V_54 ) {
V_67 . V_70 = F_66 ( V_40 , V_4 ,
F_3 ( V_54 - V_4 , ( T_1 ) V_69 ) ,
V_67 . V_22 , V_68 ) ;
if ( ! V_67 . V_70 )
break;
for ( V_77 = 0 ; V_77 < F_72 ( & V_67 ) ; V_77 ++ ) {
struct V_5 * V_5 = V_67 . V_22 [ V_77 ] ;
V_4 = V_68 [ V_77 ] ;
if ( V_4 >= V_54 )
break;
if ( F_55 ( V_5 ) ) {
if ( V_73 )
continue;
V_76 += ! F_46 ( V_40 ,
V_4 , V_5 ) ;
continue;
}
if ( ! F_73 ( V_5 ) )
continue;
if ( ! V_73 || ! F_74 ( V_5 ) ) {
if ( V_5 -> V_40 == V_40 ) {
F_34 ( F_75 ( V_5 ) , V_5 ) ;
F_76 ( V_40 , V_5 ) ;
}
}
F_77 ( V_5 ) ;
}
F_67 ( & V_67 ) ;
F_69 ( & V_67 ) ;
F_70 () ;
V_4 ++ ;
}
if ( V_74 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_53 - 1 , & V_5 , V_78 ) ;
if ( V_5 ) {
unsigned int V_79 = V_21 ;
if ( V_53 > V_54 ) {
V_79 = V_75 ;
V_75 = 0 ;
}
F_78 ( V_5 , V_74 , V_79 ) ;
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
}
}
if ( V_75 ) {
struct V_5 * V_5 = NULL ;
F_4 ( V_3 , V_54 , & V_5 , V_78 ) ;
if ( V_5 ) {
F_78 ( V_5 , 0 , V_75 ) ;
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
}
}
if ( V_53 >= V_54 )
return;
V_4 = V_53 ;
while ( V_4 < V_54 ) {
F_70 () ;
V_67 . V_70 = F_66 ( V_40 , V_4 ,
F_3 ( V_54 - V_4 , ( T_1 ) V_69 ) ,
V_67 . V_22 , V_68 ) ;
if ( ! V_67 . V_70 ) {
if ( V_4 == V_53 || V_54 != - 1 )
break;
V_4 = V_53 ;
continue;
}
for ( V_77 = 0 ; V_77 < F_72 ( & V_67 ) ; V_77 ++ ) {
struct V_5 * V_5 = V_67 . V_22 [ V_77 ] ;
V_4 = V_68 [ V_77 ] ;
if ( V_4 >= V_54 )
break;
if ( F_55 ( V_5 ) ) {
if ( V_73 )
continue;
if ( F_46 ( V_40 , V_4 , V_5 ) ) {
V_4 -- ;
break;
}
V_76 ++ ;
continue;
}
F_80 ( V_5 ) ;
if ( ! V_73 || ! F_74 ( V_5 ) ) {
if ( V_5 -> V_40 == V_40 ) {
F_34 ( F_75 ( V_5 ) , V_5 ) ;
F_76 ( V_40 , V_5 ) ;
} else {
F_77 ( V_5 ) ;
V_4 -- ;
break;
}
}
F_77 ( V_5 ) ;
}
F_67 ( & V_67 ) ;
F_69 ( & V_67 ) ;
V_4 ++ ;
}
F_17 ( & V_29 -> V_80 ) ;
V_29 -> V_32 -= V_76 ;
F_20 ( V_3 ) ;
F_18 ( & V_29 -> V_80 ) ;
}
void F_81 ( struct V_3 * V_3 , T_2 V_71 , T_2 V_72 )
{
F_71 ( V_3 , V_71 , V_72 , false ) ;
V_3 -> V_81 = V_3 -> V_82 = V_83 ;
}
static int F_82 ( struct V_84 * V_85 , struct V_86 * V_86 ,
struct V_87 * V_88 )
{
struct V_3 * V_3 = V_86 -> V_89 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
if ( V_29 -> V_31 - V_29 -> V_32 != V_3 -> V_9 -> V_33 ) {
F_17 ( & V_29 -> V_80 ) ;
F_20 ( V_3 ) ;
F_18 ( & V_29 -> V_80 ) ;
}
F_83 ( V_3 , V_88 ) ;
return 0 ;
}
static int F_84 ( struct V_86 * V_86 , struct V_90 * V_91 )
{
struct V_3 * V_3 = V_89 ( V_86 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
int error ;
error = F_85 ( V_3 , V_91 ) ;
if ( error )
return error ;
if ( F_86 ( V_3 -> V_92 ) && ( V_91 -> V_93 & V_94 ) ) {
T_2 V_19 = V_3 -> V_65 ;
T_2 V_20 = V_91 -> V_95 ;
if ( ( V_20 < V_19 && ( V_29 -> V_96 & V_97 ) ) ||
( V_20 > V_19 && ( V_29 -> V_96 & V_98 ) ) )
return - V_99 ;
if ( V_20 != V_19 ) {
error = F_13 ( F_21 ( V_3 ) -> V_14 ,
V_19 , V_20 ) ;
if ( error )
return error ;
F_87 ( V_3 , V_20 ) ;
V_3 -> V_81 = V_3 -> V_82 = V_83 ;
}
if ( V_20 <= V_19 ) {
T_2 V_100 = F_88 ( V_20 , V_21 ) ;
if ( V_19 > V_100 )
F_89 ( V_3 -> V_9 ,
V_100 , 0 , 1 ) ;
if ( V_29 -> V_31 )
F_81 ( V_3 ,
V_20 , ( T_2 ) - 1 ) ;
if ( V_19 > V_100 )
F_89 ( V_3 -> V_9 ,
V_100 , 0 , 1 ) ;
}
}
F_90 ( V_3 , V_91 ) ;
if ( V_91 -> V_93 & V_101 )
error = F_91 ( V_3 , V_3 -> V_92 ) ;
return error ;
}
static void F_92 ( struct V_3 * V_3 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
if ( V_3 -> V_9 -> V_102 == & V_103 ) {
F_11 ( V_29 -> V_14 , V_3 -> V_65 ) ;
V_3 -> V_65 = 0 ;
F_81 ( V_3 , 0 , ( T_2 ) - 1 ) ;
if ( ! F_93 ( & V_29 -> V_104 ) ) {
F_94 ( & V_105 ) ;
F_95 ( & V_29 -> V_104 ) ;
F_96 ( & V_105 ) ;
}
}
F_97 ( & V_29 -> V_106 ) ;
F_98 ( V_3 -> V_37 ) ;
F_19 ( V_3 -> V_34 ) ;
F_99 ( V_3 ) ;
}
static int F_100 ( struct V_28 * V_29 ,
T_3 V_48 , struct V_5 * * V_6 )
{
struct V_39 * V_40 = V_29 -> V_107 . V_9 ;
void * V_51 ;
T_1 V_4 ;
T_4 V_108 ;
int error = 0 ;
V_51 = F_32 ( V_48 ) ;
V_4 = F_101 ( & V_40 -> V_45 , V_51 ) ;
if ( V_4 == - 1 )
return - V_109 ;
if ( V_110 . V_111 != & V_29 -> V_104 )
F_102 ( & V_110 , & V_29 -> V_104 ) ;
V_108 = F_6 ( V_40 ) ;
if ( F_103 ( * V_6 , V_108 ) ) {
F_96 ( & V_105 ) ;
error = F_104 ( V_6 , V_108 , V_29 , V_4 ) ;
F_94 ( & V_105 ) ;
if ( ! F_105 ( * V_6 ) )
error = - V_46 ;
}
if ( ! error )
error = F_33 ( * V_6 , V_40 , V_4 ,
V_51 ) ;
if ( error != - V_112 ) {
F_106 ( * V_6 ) ;
F_79 ( * V_6 ) ;
if ( ! error ) {
F_17 ( & V_29 -> V_80 ) ;
V_29 -> V_32 -- ;
F_18 ( & V_29 -> V_80 ) ;
F_107 ( V_48 ) ;
}
}
return error ;
}
int F_108 ( T_3 V_48 , struct V_5 * V_5 )
{
struct V_113 * V_114 , * V_111 ;
struct V_28 * V_29 ;
struct V_115 * V_116 ;
int error = 0 ;
if ( F_109 ( ! F_110 ( V_5 ) || F_111 ( V_5 ) != V_48 . V_117 ) )
goto V_118;
error = F_112 ( V_5 , V_17 -> V_18 , V_119 , & V_116 ,
false ) ;
if ( error )
goto V_118;
error = - V_109 ;
F_94 ( & V_105 ) ;
F_113 (this, next, &shmem_swaplist) {
V_29 = F_114 ( V_114 , struct V_28 , V_104 ) ;
if ( V_29 -> V_32 )
error = F_100 ( V_29 , V_48 , & V_5 ) ;
else
F_95 ( & V_29 -> V_104 ) ;
F_70 () ;
if ( error != - V_109 )
break;
}
F_96 ( & V_105 ) ;
if ( error ) {
if ( error != - V_112 )
error = 0 ;
F_115 ( V_5 , V_116 , false ) ;
} else
F_116 ( V_5 , V_116 , true , false ) ;
V_118:
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
return error ;
}
static int F_117 ( struct V_5 * V_5 , struct V_120 * V_121 )
{
struct V_28 * V_29 ;
struct V_39 * V_40 ;
struct V_3 * V_3 ;
T_3 V_48 ;
T_1 V_4 ;
F_45 ( ! F_35 ( V_5 ) ) ;
V_40 = V_5 -> V_40 ;
V_4 = V_5 -> V_4 ;
V_3 = V_40 -> V_122 ;
V_29 = F_21 ( V_3 ) ;
if ( V_29 -> V_14 & V_123 )
goto V_124;
if ( ! V_125 )
goto V_124;
if ( ! V_121 -> V_126 ) {
F_118 ( 1 ) ;
goto V_124;
}
if ( ! F_74 ( V_5 ) ) {
if ( V_3 -> V_127 ) {
struct V_128 * V_128 ;
F_17 ( & V_3 -> V_129 ) ;
V_128 = V_3 -> V_127 ;
if ( V_128 &&
! V_128 -> V_130 &&
V_4 >= V_128 -> V_53 &&
V_4 < V_128 -> V_111 )
V_128 -> V_131 ++ ;
else
V_128 = NULL ;
F_18 ( & V_3 -> V_129 ) ;
if ( V_128 )
goto V_124;
}
F_119 ( V_5 ) ;
F_120 ( V_5 ) ;
F_121 ( V_5 ) ;
}
V_48 = F_122 () ;
if ( ! V_48 . V_117 )
goto V_124;
if ( F_123 ( V_5 , V_48 ) )
goto V_132;
F_94 ( & V_105 ) ;
if ( F_93 ( & V_29 -> V_104 ) )
F_124 ( & V_29 -> V_104 , & V_110 ) ;
if ( F_125 ( V_5 , V_48 , V_133 ) == 0 ) {
F_17 ( & V_29 -> V_80 ) ;
F_20 ( V_3 ) ;
V_29 -> V_32 ++ ;
F_18 ( & V_29 -> V_80 ) ;
F_126 ( V_48 ) ;
F_43 ( V_5 , F_32 ( V_48 ) ) ;
F_96 ( & V_105 ) ;
F_45 ( F_127 ( V_5 ) ) ;
F_128 ( V_5 , V_121 ) ;
return 0 ;
}
F_96 ( & V_105 ) ;
V_132:
F_129 ( V_48 ) ;
V_124:
F_79 ( V_5 ) ;
if ( V_121 -> V_126 )
return V_134 ;
F_77 ( V_5 ) ;
return 0 ;
}
static void F_130 ( struct V_135 * V_136 , struct V_137 * V_138 )
{
char V_139 [ 64 ] ;
if ( ! V_138 || V_138 -> V_140 == V_141 )
return;
F_131 ( V_139 , sizeof( V_139 ) , V_138 ) ;
F_132 ( V_136 , L_1 , V_139 ) ;
}
static struct V_137 * F_133 ( struct V_10 * V_23 )
{
struct V_137 * V_138 = NULL ;
if ( V_23 -> V_138 ) {
F_17 ( & V_23 -> V_25 ) ;
V_138 = V_23 -> V_138 ;
F_134 ( V_138 ) ;
F_18 ( & V_23 -> V_25 ) ;
}
return V_138 ;
}
static inline void F_130 ( struct V_135 * V_136 , struct V_137 * V_138 )
{
}
static inline struct V_137 * F_133 ( struct V_10 * V_23 )
{
return NULL ;
}
static struct V_5 * F_135 ( T_3 V_48 , T_4 V_108 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_59 V_142 ;
struct V_5 * V_5 ;
V_142 . V_64 = 0 ;
V_142 . V_62 = V_4 + V_29 -> V_107 . V_143 ;
V_142 . V_144 = NULL ;
V_142 . V_145 = F_136 ( & V_29 -> V_146 , V_4 ) ;
V_5 = F_137 ( V_48 , V_108 , & V_142 , 0 ) ;
F_138 ( V_142 . V_145 ) ;
return V_5 ;
}
static struct V_5 * F_139 ( T_4 V_108 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_59 V_142 ;
struct V_5 * V_5 ;
V_142 . V_64 = 0 ;
V_142 . V_62 = V_4 + V_29 -> V_107 . V_143 ;
V_142 . V_144 = NULL ;
V_142 . V_145 = F_136 ( & V_29 -> V_146 , V_4 ) ;
V_5 = F_140 ( V_108 , 0 , & V_142 , 0 , F_141 () , false ) ;
if ( V_5 ) {
F_142 ( V_5 ) ;
F_143 ( V_5 ) ;
}
F_138 ( V_142 . V_145 ) ;
return V_5 ;
}
static bool F_103 ( struct V_5 * V_5 , T_4 V_108 )
{
return F_144 ( V_5 ) > F_145 ( V_108 ) ;
}
static int F_104 ( struct V_5 * * V_6 , T_4 V_108 ,
struct V_28 * V_29 , T_1 V_4 )
{
struct V_5 * V_147 , * V_148 ;
struct V_39 * V_149 ;
T_1 V_150 ;
int error ;
V_147 = * V_6 ;
V_150 = F_111 ( V_147 ) ;
V_149 = F_146 ( V_147 ) ;
V_108 &= ~ V_151 ;
V_148 = F_139 ( V_108 , V_29 , V_4 ) ;
if ( ! V_148 )
return - V_112 ;
F_37 ( V_148 ) ;
F_147 ( V_148 , V_147 ) ;
F_120 ( V_148 ) ;
F_121 ( V_148 ) ;
F_148 ( V_148 , V_150 ) ;
F_149 ( V_148 ) ;
F_38 ( & V_149 -> V_47 ) ;
error = F_23 ( V_149 , V_150 , V_147 ,
V_148 ) ;
if ( ! error ) {
F_40 ( V_148 , V_49 ) ;
F_44 ( V_147 , V_49 ) ;
}
F_41 ( & V_149 -> V_47 ) ;
if ( F_109 ( error ) ) {
V_147 = V_148 ;
} else {
F_150 ( V_147 , V_148 ) ;
F_151 ( V_148 ) ;
* V_6 = V_148 ;
}
F_152 ( V_147 ) ;
F_148 ( V_147 , 0 ) ;
F_77 ( V_147 ) ;
F_42 ( V_147 ) ;
F_42 ( V_147 ) ;
return error ;
}
static int F_5 ( struct V_3 * V_3 , T_1 V_4 ,
struct V_5 * * V_6 , enum V_7 V_8 , T_4 V_108 ,
struct V_152 * V_153 , int * V_154 )
{
struct V_39 * V_40 = V_3 -> V_9 ;
struct V_28 * V_29 ;
struct V_10 * V_23 ;
struct V_152 * V_155 ;
struct V_115 * V_116 ;
struct V_5 * V_5 ;
T_3 V_48 ;
int error ;
int V_156 = 0 ;
int V_31 = 0 ;
if ( V_4 > ( V_157 >> V_58 ) )
return - V_158 ;
V_159:
V_48 . V_117 = 0 ;
V_5 = F_153 ( V_40 , V_4 ) ;
if ( F_55 ( V_5 ) ) {
V_48 = F_49 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_8 <= V_160 &&
( ( T_2 ) V_4 << V_58 ) >= F_154 ( V_3 ) ) {
error = - V_161 ;
goto V_162;
}
if ( V_5 && V_8 == V_163 )
F_155 ( V_5 ) ;
if ( V_5 && ! F_74 ( V_5 ) ) {
if ( V_8 != V_78 )
goto V_164;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 || ( V_8 == V_78 && ! V_48 . V_117 ) ) {
* V_6 = V_5 ;
return 0 ;
}
V_29 = F_21 ( V_3 ) ;
V_23 = F_7 ( V_3 -> V_34 ) ;
V_155 = V_153 ? : V_17 -> V_18 ;
if ( V_48 . V_117 ) {
V_5 = F_156 ( V_48 ) ;
if ( ! V_5 ) {
if ( V_154 ) {
* V_154 |= V_165 ;
F_157 ( V_166 ) ;
F_158 ( V_153 , V_166 ) ;
}
V_5 = F_135 ( V_48 , V_108 , V_29 , V_4 ) ;
if ( ! V_5 ) {
error = - V_112 ;
goto V_167;
}
}
F_80 ( V_5 ) ;
if ( ! F_110 ( V_5 ) || F_111 ( V_5 ) != V_48 . V_117 ||
! F_28 ( V_40 , V_4 , V_48 ) ) {
error = - V_168 ;
goto V_162;
}
if ( ! F_74 ( V_5 ) ) {
error = - V_169 ;
goto V_167;
}
F_159 ( V_5 ) ;
if ( F_103 ( V_5 , V_108 ) ) {
error = F_104 ( & V_5 , V_108 , V_29 , V_4 ) ;
if ( error )
goto V_167;
}
error = F_112 ( V_5 , V_155 , V_108 , & V_116 ,
false ) ;
if ( ! error ) {
error = F_33 ( V_5 , V_40 , V_4 ,
F_32 ( V_48 ) ) ;
if ( error ) {
F_115 ( V_5 , V_116 , false ) ;
F_106 ( V_5 ) ;
}
}
if ( error )
goto V_167;
F_116 ( V_5 , V_116 , true , false ) ;
F_17 ( & V_29 -> V_80 ) ;
V_29 -> V_32 -- ;
F_20 ( V_3 ) ;
F_18 ( & V_29 -> V_80 ) ;
if ( V_8 == V_163 )
F_155 ( V_5 ) ;
F_106 ( V_5 ) ;
F_79 ( V_5 ) ;
F_107 ( V_48 ) ;
} else {
if ( F_14 ( V_29 -> V_14 ) ) {
error = - V_27 ;
goto V_167;
}
if ( V_23 -> V_35 ) {
if ( F_160 ( & V_23 -> V_36 ,
V_23 -> V_35 ) >= 0 ) {
error = - V_27 ;
goto V_170;
}
F_161 ( & V_23 -> V_36 ) ;
}
V_5 = F_139 ( V_108 , V_29 , V_4 ) ;
if ( ! V_5 ) {
error = - V_112 ;
goto V_171;
}
if ( V_8 == V_163 )
F_162 ( V_5 ) ;
error = F_112 ( V_5 , V_155 , V_108 , & V_116 ,
false ) ;
if ( error )
goto V_171;
error = F_163 ( V_108 & V_172 ) ;
if ( ! error ) {
error = F_33 ( V_5 , V_40 , V_4 ,
NULL ) ;
F_164 () ;
}
if ( error ) {
F_115 ( V_5 , V_116 , false ) ;
goto V_171;
}
F_116 ( V_5 , V_116 , false , false ) ;
F_151 ( V_5 ) ;
F_17 ( & V_29 -> V_80 ) ;
V_29 -> V_31 ++ ;
V_3 -> V_37 += V_38 ;
F_20 ( V_3 ) ;
F_18 ( & V_29 -> V_80 ) ;
V_31 = true ;
if ( V_8 == V_173 )
V_8 = V_163 ;
V_164:
if ( V_8 != V_163 ) {
F_119 ( V_5 ) ;
F_120 ( V_5 ) ;
F_121 ( V_5 ) ;
}
}
if ( V_8 <= V_160 &&
( ( T_2 ) V_4 << V_58 ) >= F_154 ( V_3 ) ) {
if ( V_31 ) {
F_165 ( V_5 ) ;
F_166 ( V_5 ) ;
F_17 ( & V_29 -> V_80 ) ;
F_20 ( V_3 ) ;
F_18 ( & V_29 -> V_80 ) ;
}
error = - V_161 ;
goto V_162;
}
* V_6 = V_5 ;
return 0 ;
V_171:
if ( V_23 -> V_35 )
F_22 ( & V_23 -> V_36 , - 1 ) ;
V_170:
F_15 ( V_29 -> V_14 , 1 ) ;
V_167:
if ( V_48 . V_117 && ! F_28 ( V_40 , V_4 , V_48 ) )
error = - V_168 ;
V_162:
if ( V_5 ) {
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
}
if ( error == - V_27 && ! V_156 ++ ) {
V_29 = F_21 ( V_3 ) ;
F_17 ( & V_29 -> V_80 ) ;
F_20 ( V_3 ) ;
F_18 ( & V_29 -> V_80 ) ;
goto V_159;
}
if ( error == - V_168 )
goto V_159;
return error ;
}
static int F_167 ( struct V_59 * V_60 , struct V_174 * V_175 )
{
struct V_3 * V_3 = F_60 ( V_60 -> V_61 ) ;
T_4 V_108 = F_6 ( V_3 -> V_9 ) ;
int error ;
int V_176 = V_177 ;
if ( F_109 ( V_3 -> V_127 ) ) {
struct V_128 * V_128 ;
F_17 ( & V_3 -> V_129 ) ;
V_128 = V_3 -> V_127 ;
if ( V_128 &&
V_128 -> V_130 &&
V_175 -> V_178 >= V_128 -> V_53 &&
V_175 -> V_178 < V_128 -> V_111 ) {
T_5 * V_179 ;
F_168 ( V_180 ) ;
V_176 = V_181 ;
if ( ( V_175 -> V_14 & V_182 ) &&
! ( V_175 -> V_14 & V_183 ) ) {
F_169 ( & V_60 -> V_184 -> V_185 ) ;
V_176 = V_186 ;
}
V_179 = V_128 -> V_130 ;
F_170 ( V_179 , & V_180 ,
V_187 ) ;
F_18 ( & V_3 -> V_129 ) ;
F_171 () ;
F_17 ( & V_3 -> V_129 ) ;
F_172 ( V_179 , & V_180 ) ;
F_18 ( & V_3 -> V_129 ) ;
return V_176 ;
}
F_18 ( & V_3 -> V_129 ) ;
}
error = F_5 ( V_3 , V_175 -> V_178 , & V_175 -> V_5 , V_160 ,
V_108 , V_60 -> V_184 , & V_176 ) ;
if ( error )
return ( ( error == - V_112 ) ? V_188 : V_189 ) ;
return V_176 ;
}
static int F_173 ( struct V_59 * V_60 , struct V_137 * V_138 )
{
struct V_3 * V_3 = F_60 ( V_60 -> V_61 ) ;
return F_174 ( & F_21 ( V_3 ) -> V_146 , V_60 , V_138 ) ;
}
static struct V_137 * F_175 ( struct V_59 * V_60 ,
unsigned long V_190 )
{
struct V_3 * V_3 = F_60 ( V_60 -> V_61 ) ;
T_1 V_4 ;
V_4 = ( ( V_190 - V_60 -> V_64 ) >> V_58 ) + V_60 -> V_62 ;
return F_136 ( & F_21 ( V_3 ) -> V_146 , V_4 ) ;
}
int F_176 ( struct V_191 * V_191 , int V_80 , struct V_192 * V_193 )
{
struct V_3 * V_3 = F_60 ( V_191 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
int V_194 = - V_112 ;
F_17 ( & V_29 -> V_80 ) ;
if ( V_80 && ! ( V_29 -> V_14 & V_123 ) ) {
if ( ! F_177 ( V_3 -> V_65 , V_193 ) )
goto V_195;
V_29 -> V_14 |= V_123 ;
F_178 ( V_191 -> V_196 ) ;
}
if ( ! V_80 && ( V_29 -> V_14 & V_123 ) && V_193 ) {
F_179 ( V_3 -> V_65 , V_193 ) ;
V_29 -> V_14 &= ~ V_123 ;
F_180 ( V_191 -> V_196 ) ;
}
V_194 = 0 ;
V_195:
F_18 ( & V_29 -> V_80 ) ;
return V_194 ;
}
static int F_181 ( struct V_191 * V_191 , struct V_59 * V_60 )
{
F_182 ( V_191 ) ;
V_60 -> V_144 = & V_197 ;
return 0 ;
}
static struct V_3 * F_183 ( struct V_11 * V_12 , const struct V_3 * V_198 ,
T_6 V_140 , T_7 V_199 , unsigned long V_14 )
{
struct V_3 * V_3 ;
struct V_28 * V_29 ;
struct V_10 * V_23 = F_7 ( V_12 ) ;
if ( F_16 ( V_12 ) )
return NULL ;
V_3 = F_184 ( V_12 ) ;
if ( V_3 ) {
V_3 -> V_143 = F_185 () ;
F_186 ( V_3 , V_198 , V_140 ) ;
V_3 -> V_37 = 0 ;
V_3 -> V_200 = V_3 -> V_82 = V_3 -> V_81 = V_83 ;
V_3 -> V_201 = F_187 () ;
V_29 = F_21 ( V_3 ) ;
memset ( V_29 , 0 , ( char * ) V_3 - ( char * ) V_29 ) ;
F_188 ( & V_29 -> V_80 ) ;
V_29 -> V_96 = V_202 ;
V_29 -> V_14 = V_14 & V_16 ;
F_189 ( & V_29 -> V_104 ) ;
F_190 ( & V_29 -> V_106 ) ;
F_191 ( V_3 ) ;
switch ( V_140 & V_203 ) {
default:
V_3 -> V_204 = & V_205 ;
F_192 ( V_3 , V_140 , V_199 ) ;
break;
case V_206 :
V_3 -> V_9 -> V_102 = & V_103 ;
V_3 -> V_204 = & V_207 ;
V_3 -> V_208 = & V_209 ;
F_193 ( & V_29 -> V_146 ,
F_133 ( V_23 ) ) ;
break;
case V_210 :
F_194 ( V_3 ) ;
V_3 -> V_65 = 2 * V_211 ;
V_3 -> V_204 = & V_212 ;
V_3 -> V_208 = & V_213 ;
break;
case V_214 :
F_193 ( & V_29 -> V_146 , NULL ) ;
break;
}
} else
F_19 ( V_12 ) ;
return V_3 ;
}
bool F_195 ( struct V_39 * V_40 )
{
if ( ! V_40 -> V_122 )
return false ;
return V_40 -> V_122 -> V_34 -> V_215 == & V_216 ;
}
static int
F_196 ( struct V_191 * V_191 , struct V_39 * V_40 ,
T_2 V_217 , unsigned V_218 , unsigned V_14 ,
struct V_5 * * V_6 , void * * V_219 )
{
struct V_3 * V_3 = V_40 -> V_122 ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
T_1 V_4 = V_217 >> V_58 ;
if ( F_109 ( V_29 -> V_96 ) ) {
if ( V_29 -> V_96 & V_220 )
return - V_99 ;
if ( ( V_29 -> V_96 & V_98 ) && V_217 + V_218 > V_3 -> V_65 )
return - V_99 ;
}
return F_4 ( V_3 , V_4 , V_6 , V_163 ) ;
}
static int
F_197 ( struct V_191 * V_191 , struct V_39 * V_40 ,
T_2 V_217 , unsigned V_218 , unsigned V_221 ,
struct V_5 * V_5 , void * V_219 )
{
struct V_3 * V_3 = V_40 -> V_122 ;
if ( V_217 + V_221 > V_3 -> V_65 )
F_87 ( V_3 , V_217 + V_221 ) ;
if ( ! F_74 ( V_5 ) ) {
if ( V_221 < V_21 ) {
unsigned V_222 = V_217 & ( V_21 - 1 ) ;
F_198 ( V_5 , 0 , V_222 ,
V_222 + V_221 , V_21 ) ;
}
F_121 ( V_5 ) ;
}
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
return V_221 ;
}
static T_8 F_199 ( struct V_223 * V_224 , struct V_225 * V_226 )
{
struct V_191 * V_191 = V_224 -> V_227 ;
struct V_3 * V_3 = F_60 ( V_191 ) ;
struct V_39 * V_40 = V_3 -> V_9 ;
T_1 V_4 ;
unsigned long V_228 ;
enum V_7 V_8 = V_78 ;
int error = 0 ;
T_8 V_194 = 0 ;
T_2 * V_229 = & V_224 -> V_230 ;
if ( ! F_200 ( V_226 ) )
V_8 = V_160 ;
V_4 = * V_229 >> V_58 ;
V_228 = * V_229 & ~ V_231 ;
for (; ; ) {
struct V_5 * V_5 = NULL ;
T_1 V_232 ;
unsigned long V_70 , V_176 ;
T_2 V_65 = F_154 ( V_3 ) ;
V_232 = V_65 >> V_58 ;
if ( V_4 > V_232 )
break;
if ( V_4 == V_232 ) {
V_70 = V_65 & ~ V_231 ;
if ( V_70 <= V_228 )
break;
}
error = F_4 ( V_3 , V_4 , & V_5 , V_8 ) ;
if ( error ) {
if ( error == - V_161 )
error = 0 ;
break;
}
if ( V_5 ) {
if ( V_8 == V_160 )
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
}
V_70 = V_21 ;
V_65 = F_154 ( V_3 ) ;
V_232 = V_65 >> V_58 ;
if ( V_4 == V_232 ) {
V_70 = V_65 & ~ V_231 ;
if ( V_70 <= V_228 ) {
if ( V_5 )
F_42 ( V_5 ) ;
break;
}
}
V_70 -= V_228 ;
if ( V_5 ) {
if ( F_201 ( V_40 ) )
F_120 ( V_5 ) ;
if ( ! V_228 )
F_155 ( V_5 ) ;
} else {
V_5 = F_202 ( 0 ) ;
F_37 ( V_5 ) ;
}
V_176 = F_203 ( V_5 , V_228 , V_70 , V_226 ) ;
V_194 += V_176 ;
V_228 += V_176 ;
V_4 += V_228 >> V_58 ;
V_228 &= ~ V_231 ;
F_42 ( V_5 ) ;
if ( ! F_204 ( V_226 ) )
break;
if ( V_176 < V_70 ) {
error = - V_233 ;
break;
}
F_70 () ;
}
* V_229 = ( ( T_2 ) V_4 << V_58 ) + V_228 ;
F_182 ( V_191 ) ;
return V_194 ? V_194 : error ;
}
static T_8 F_205 ( struct V_191 * V_234 , T_2 * V_229 ,
struct V_235 * V_236 , T_9 V_218 ,
unsigned int V_14 )
{
struct V_39 * V_40 = V_234 -> V_196 ;
struct V_3 * V_3 = V_40 -> V_122 ;
unsigned int V_237 , V_238 , V_239 ;
struct V_5 * V_22 [ V_240 ] ;
struct V_241 V_242 [ V_240 ] ;
struct V_5 * V_5 ;
T_1 V_4 , V_232 ;
T_2 V_243 , V_244 ;
int error , V_245 ;
struct V_246 V_247 = {
. V_22 = V_22 ,
. V_242 = V_242 ,
. V_248 = V_240 ,
. V_14 = V_14 ,
. V_249 = & V_250 ,
. V_251 = V_252 ,
} ;
V_243 = F_154 ( V_3 ) ;
if ( F_109 ( * V_229 >= V_243 ) )
return 0 ;
V_244 = V_243 - * V_229 ;
if ( F_109 ( V_244 < V_218 ) )
V_218 = V_244 ;
if ( F_206 ( V_236 , & V_247 ) )
return - V_112 ;
V_4 = * V_229 >> V_58 ;
V_237 = * V_229 & ~ V_231 ;
V_239 = ( V_218 + V_237 + V_21 - 1 ) >> V_58 ;
V_238 = F_3 ( V_239 , V_247 . V_248 ) ;
V_247 . V_238 = F_207 ( V_40 , V_4 ,
V_238 , V_247 . V_22 ) ;
V_4 += V_247 . V_238 ;
error = 0 ;
while ( V_247 . V_238 < V_238 ) {
error = F_4 ( V_3 , V_4 , & V_5 , V_160 ) ;
if ( error )
break;
F_77 ( V_5 ) ;
V_247 . V_22 [ V_247 . V_238 ++ ] = V_5 ;
V_4 ++ ;
}
V_4 = * V_229 >> V_58 ;
V_238 = V_247 . V_238 ;
V_247 . V_238 = 0 ;
for ( V_245 = 0 ; V_245 < V_238 ; V_245 ++ ) {
unsigned int V_253 ;
if ( ! V_218 )
break;
V_253 = F_208 (unsigned long, len, PAGE_SIZE - loff) ;
V_5 = V_247 . V_22 [ V_245 ] ;
if ( ! F_74 ( V_5 ) || V_5 -> V_40 != V_40 ) {
error = F_4 ( V_3 , V_4 , & V_5 , V_160 ) ;
if ( error )
break;
F_77 ( V_5 ) ;
F_42 ( V_247 . V_22 [ V_245 ] ) ;
V_247 . V_22 [ V_245 ] = V_5 ;
}
V_243 = F_154 ( V_3 ) ;
V_232 = ( V_243 - 1 ) >> V_58 ;
if ( F_109 ( ! V_243 || V_4 > V_232 ) )
break;
if ( V_232 == V_4 ) {
unsigned int V_254 ;
V_254 = ( ( V_243 - 1 ) & ~ V_231 ) + 1 ;
if ( V_254 <= V_237 )
break;
V_253 = F_3 ( V_253 , V_254 - V_237 ) ;
V_218 = V_253 ;
}
V_247 . V_242 [ V_245 ] . V_228 = V_237 ;
V_247 . V_242 [ V_245 ] . V_218 = V_253 ;
V_218 -= V_253 ;
V_237 = 0 ;
V_247 . V_238 ++ ;
V_4 ++ ;
}
while ( V_245 < V_238 )
F_42 ( V_247 . V_22 [ V_245 ++ ] ) ;
if ( V_247 . V_238 )
error = F_209 ( V_236 , & V_247 ) ;
F_210 ( & V_247 ) ;
if ( error > 0 ) {
* V_229 += error ;
F_182 ( V_234 ) ;
}
return error ;
}
static T_1 F_211 ( struct V_39 * V_40 ,
T_1 V_4 , T_1 V_54 , int V_255 )
{
struct V_5 * V_5 ;
struct V_66 V_67 ;
T_1 V_68 [ V_69 ] ;
bool V_256 = false ;
int V_77 ;
F_64 ( & V_67 , 0 ) ;
V_67 . V_70 = 1 ;
while ( ! V_256 ) {
V_67 . V_70 = F_66 ( V_40 , V_4 ,
V_67 . V_70 , V_67 . V_22 , V_68 ) ;
if ( ! V_67 . V_70 ) {
if ( V_255 == V_257 )
V_4 = V_54 ;
break;
}
for ( V_77 = 0 ; V_77 < V_67 . V_70 ; V_77 ++ , V_4 ++ ) {
if ( V_4 < V_68 [ V_77 ] ) {
if ( V_255 == V_258 ) {
V_256 = true ;
break;
}
V_4 = V_68 [ V_77 ] ;
}
V_5 = V_67 . V_22 [ V_77 ] ;
if ( V_5 && ! F_55 ( V_5 ) ) {
if ( ! F_74 ( V_5 ) )
V_5 = NULL ;
}
if ( V_4 >= V_54 ||
( V_5 && V_255 == V_257 ) ||
( ! V_5 && V_255 == V_258 ) ) {
V_256 = true ;
break;
}
}
F_67 ( & V_67 ) ;
F_69 ( & V_67 ) ;
V_67 . V_70 = V_69 ;
F_70 () ;
}
return V_4 ;
}
static T_2 F_212 ( struct V_191 * V_191 , T_2 V_228 , int V_255 )
{
struct V_39 * V_40 = V_191 -> V_196 ;
struct V_3 * V_3 = V_40 -> V_122 ;
T_1 V_53 , V_54 ;
T_2 V_259 ;
if ( V_255 != V_257 && V_255 != V_258 )
return F_213 ( V_191 , V_228 , V_255 ,
V_157 , F_154 ( V_3 ) ) ;
F_214 ( V_3 ) ;
if ( V_228 < 0 )
V_228 = - V_161 ;
else if ( V_228 >= V_3 -> V_65 )
V_228 = - V_260 ;
else {
V_53 = V_228 >> V_58 ;
V_54 = ( V_3 -> V_65 + V_21 - 1 ) >> V_58 ;
V_259 = F_211 ( V_40 , V_53 , V_54 , V_255 ) ;
V_259 <<= V_58 ;
if ( V_259 > V_228 ) {
if ( V_259 < V_3 -> V_65 )
V_228 = V_259 ;
else if ( V_255 == V_257 )
V_228 = - V_260 ;
else
V_228 = V_3 -> V_65 ;
}
}
if ( V_228 >= 0 )
V_228 = F_215 ( V_191 , V_228 , V_157 ) ;
F_216 ( V_3 ) ;
return V_228 ;
}
static void F_217 ( struct V_39 * V_40 )
{
struct V_55 V_56 ;
void * * V_57 ;
T_1 V_53 ;
struct V_5 * V_5 ;
F_218 () ;
V_53 = 0 ;
F_29 () ;
F_51 (slot, &mapping->page_tree, &iter, start) {
V_5 = F_52 ( V_57 ) ;
if ( ! V_5 || F_219 ( V_5 ) ) {
if ( F_53 ( V_5 ) ) {
V_57 = F_54 ( & V_56 ) ;
continue;
}
} else if ( F_220 ( V_5 ) - F_221 ( V_5 ) > 1 ) {
F_38 ( & V_40 -> V_47 ) ;
F_222 ( & V_40 -> V_45 , V_56 . V_4 ,
V_261 ) ;
F_41 ( & V_40 -> V_47 ) ;
}
if ( F_56 () ) {
F_57 () ;
V_57 = F_58 ( & V_56 ) ;
}
}
F_31 () ;
}
static int F_223 ( struct V_39 * V_40 )
{
struct V_55 V_56 ;
void * * V_57 ;
T_1 V_53 ;
struct V_5 * V_5 ;
int error , V_262 ;
F_217 ( V_40 ) ;
error = 0 ;
for ( V_262 = 0 ; V_262 <= V_263 ; V_262 ++ ) {
if ( ! F_224 ( & V_40 -> V_45 , V_261 ) )
break;
if ( ! V_262 )
F_225 () ;
else if ( F_226 ( ( V_264 << V_262 ) / 200 ) )
V_262 = V_263 ;
V_53 = 0 ;
F_29 () ;
F_227 (slot, &mapping->page_tree, &iter,
start, SHMEM_TAG_PINNED) {
V_5 = F_52 ( V_57 ) ;
if ( F_219 ( V_5 ) ) {
if ( F_53 ( V_5 ) ) {
V_57 = F_54 ( & V_56 ) ;
continue;
}
V_5 = NULL ;
}
if ( V_5 &&
F_220 ( V_5 ) - F_221 ( V_5 ) != 1 ) {
if ( V_262 < V_263 )
goto V_265;
error = - V_266 ;
}
F_38 ( & V_40 -> V_47 ) ;
F_228 ( & V_40 -> V_45 ,
V_56 . V_4 , V_261 ) ;
F_41 ( & V_40 -> V_47 ) ;
V_265:
if ( F_56 () ) {
F_57 () ;
V_57 = F_58 ( & V_56 ) ;
}
}
F_31 () ;
}
return error ;
}
int F_229 ( struct V_191 * V_191 , unsigned int V_96 )
{
struct V_3 * V_3 = F_60 ( V_191 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
int error ;
if ( V_191 -> V_267 != & V_209 )
return - V_161 ;
if ( ! ( V_191 -> V_268 & V_269 ) )
return - V_99 ;
if ( V_96 & ~ ( unsigned int ) V_270 )
return - V_161 ;
F_214 ( V_3 ) ;
if ( V_29 -> V_96 & V_202 ) {
error = - V_99 ;
goto V_162;
}
if ( ( V_96 & V_220 ) && ! ( V_29 -> V_96 & V_220 ) ) {
error = F_230 ( V_191 -> V_196 ) ;
if ( error )
goto V_162;
error = F_223 ( V_191 -> V_196 ) ;
if ( error ) {
F_231 ( V_191 -> V_196 ) ;
goto V_162;
}
}
V_29 -> V_96 |= V_96 ;
error = 0 ;
V_162:
F_216 ( V_3 ) ;
return error ;
}
int F_232 ( struct V_191 * V_191 )
{
if ( V_191 -> V_267 != & V_209 )
return - V_161 ;
return F_21 ( F_60 ( V_191 ) ) -> V_96 ;
}
long F_233 ( struct V_191 * V_191 , unsigned int V_271 , unsigned long V_272 )
{
long error ;
switch ( V_271 ) {
case V_273 :
if ( V_272 > V_274 )
return - V_161 ;
error = F_229 ( V_191 , V_272 ) ;
break;
case V_275 :
error = F_232 ( V_191 ) ;
break;
default:
error = - V_161 ;
break;
}
return error ;
}
static long F_234 ( struct V_191 * V_191 , int V_140 , T_2 V_228 ,
T_2 V_218 )
{
struct V_3 * V_3 = F_60 ( V_191 ) ;
struct V_10 * V_23 = F_7 ( V_3 -> V_34 ) ;
struct V_28 * V_29 = F_21 ( V_3 ) ;
struct V_128 V_128 ;
T_1 V_53 , V_4 , V_54 ;
int error ;
if ( V_140 & ~ ( V_276 | V_277 ) )
return - V_278 ;
F_214 ( V_3 ) ;
if ( V_140 & V_277 ) {
struct V_39 * V_40 = V_191 -> V_196 ;
T_2 V_279 = F_88 ( V_228 , V_21 ) ;
T_2 V_280 = F_235 ( V_228 + V_218 , V_21 ) - 1 ;
F_236 ( V_179 ) ;
if ( V_29 -> V_96 & V_220 ) {
error = - V_99 ;
goto V_118;
}
V_128 . V_130 = & V_179 ;
V_128 . V_53 = V_279 >> V_58 ;
V_128 . V_111 = ( V_280 + 1 ) >> V_58 ;
F_17 ( & V_3 -> V_129 ) ;
V_3 -> V_127 = & V_128 ;
F_18 ( & V_3 -> V_129 ) ;
if ( ( V_281 ) V_280 > ( V_281 ) V_279 )
F_89 ( V_40 , V_279 ,
1 + V_280 - V_279 , 0 ) ;
F_81 ( V_3 , V_228 , V_228 + V_218 - 1 ) ;
F_17 ( & V_3 -> V_129 ) ;
V_3 -> V_127 = NULL ;
F_237 ( & V_179 ) ;
F_18 ( & V_3 -> V_129 ) ;
error = 0 ;
goto V_118;
}
error = F_238 ( V_3 , V_228 + V_218 ) ;
if ( error )
goto V_118;
if ( ( V_29 -> V_96 & V_98 ) && V_228 + V_218 > V_3 -> V_65 ) {
error = - V_99 ;
goto V_118;
}
V_53 = V_228 >> V_58 ;
V_54 = ( V_228 + V_218 + V_21 - 1 ) >> V_58 ;
if ( V_23 -> V_35 && V_54 - V_53 > V_23 -> V_35 ) {
error = - V_27 ;
goto V_118;
}
V_128 . V_130 = NULL ;
V_128 . V_53 = V_53 ;
V_128 . V_111 = V_53 ;
V_128 . V_282 = 0 ;
V_128 . V_131 = 0 ;
F_17 ( & V_3 -> V_129 ) ;
V_3 -> V_127 = & V_128 ;
F_18 ( & V_3 -> V_129 ) ;
for ( V_4 = V_53 ; V_4 < V_54 ; V_4 ++ ) {
struct V_5 * V_5 ;
if ( F_239 ( V_17 ) )
error = - V_283 ;
else if ( V_128 . V_131 > V_128 . V_282 )
error = - V_112 ;
else
error = F_4 ( V_3 , V_4 , & V_5 , V_173 ) ;
if ( error ) {
if ( V_4 > V_53 ) {
F_71 ( V_3 ,
( T_2 ) V_53 << V_58 ,
( ( T_2 ) V_4 << V_58 ) - 1 , true ) ;
}
goto V_284;
}
V_128 . V_111 ++ ;
if ( ! F_74 ( V_5 ) )
V_128 . V_282 ++ ;
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
F_70 () ;
}
if ( ! ( V_140 & V_276 ) && V_228 + V_218 > V_3 -> V_65 )
F_87 ( V_3 , V_228 + V_218 ) ;
V_3 -> V_81 = V_83 ;
V_284:
F_17 ( & V_3 -> V_129 ) ;
V_3 -> V_127 = NULL ;
F_18 ( & V_3 -> V_129 ) ;
V_118:
F_216 ( V_3 ) ;
return error ;
}
static int F_240 ( struct V_86 * V_86 , struct V_285 * V_286 )
{
struct V_10 * V_23 = F_7 ( V_86 -> V_287 ) ;
V_286 -> V_288 = V_289 ;
V_286 -> V_290 = V_21 ;
V_286 -> V_291 = V_292 ;
if ( V_23 -> V_35 ) {
V_286 -> V_293 = V_23 -> V_35 ;
V_286 -> V_294 =
V_286 -> V_295 = V_23 -> V_35 -
F_241 ( & V_23 -> V_36 ) ;
}
if ( V_23 -> V_24 ) {
V_286 -> V_296 = V_23 -> V_24 ;
V_286 -> V_297 = V_23 -> V_26 ;
}
return 0 ;
}
static int
F_242 ( struct V_3 * V_198 , struct V_86 * V_86 , T_6 V_140 , T_7 V_199 )
{
struct V_3 * V_3 ;
int error = - V_27 ;
V_3 = F_183 ( V_198 -> V_34 , V_198 , V_140 , V_199 , V_16 ) ;
if ( V_3 ) {
error = F_243 ( V_198 , V_3 ) ;
if ( error )
goto V_298;
error = F_244 ( V_3 , V_198 ,
& V_86 -> V_299 ,
V_300 , NULL ) ;
if ( error && error != - V_278 )
goto V_298;
error = 0 ;
V_198 -> V_65 += V_211 ;
V_198 -> V_81 = V_198 -> V_82 = V_83 ;
F_245 ( V_86 , V_3 ) ;
F_246 ( V_86 ) ;
}
return error ;
V_298:
F_247 ( V_3 ) ;
return error ;
}
static int
F_248 ( struct V_3 * V_198 , struct V_86 * V_86 , T_6 V_140 )
{
struct V_3 * V_3 ;
int error = - V_27 ;
V_3 = F_183 ( V_198 -> V_34 , V_198 , V_140 , 0 , V_16 ) ;
if ( V_3 ) {
error = F_244 ( V_3 , V_198 ,
NULL ,
V_300 , NULL ) ;
if ( error && error != - V_278 )
goto V_298;
error = F_243 ( V_198 , V_3 ) ;
if ( error )
goto V_298;
F_249 ( V_86 , V_3 ) ;
}
return error ;
V_298:
F_247 ( V_3 ) ;
return error ;
}
static int F_250 ( struct V_3 * V_198 , struct V_86 * V_86 , T_6 V_140 )
{
int error ;
if ( ( error = F_242 ( V_198 , V_86 , V_140 | V_210 , 0 ) ) )
return error ;
F_194 ( V_198 ) ;
return 0 ;
}
static int F_251 ( struct V_3 * V_198 , struct V_86 * V_86 , T_6 V_140 ,
bool V_301 )
{
return F_242 ( V_198 , V_86 , V_140 | V_206 , 0 ) ;
}
static int F_252 ( struct V_86 * V_302 , struct V_3 * V_198 , struct V_86 * V_86 )
{
struct V_3 * V_3 = V_89 ( V_302 ) ;
int V_176 ;
V_176 = F_16 ( V_3 -> V_34 ) ;
if ( V_176 )
goto V_118;
V_198 -> V_65 += V_211 ;
V_3 -> V_81 = V_198 -> V_81 = V_198 -> V_82 = V_83 ;
F_194 ( V_3 ) ;
F_253 ( V_3 ) ;
F_246 ( V_86 ) ;
F_245 ( V_86 , V_3 ) ;
V_118:
return V_176 ;
}
static int F_254 ( struct V_3 * V_198 , struct V_86 * V_86 )
{
struct V_3 * V_3 = V_89 ( V_86 ) ;
if ( V_3 -> V_303 > 1 && ! F_255 ( V_3 -> V_92 ) )
F_19 ( V_3 -> V_34 ) ;
V_198 -> V_65 -= V_211 ;
V_3 -> V_81 = V_198 -> V_81 = V_198 -> V_82 = V_83 ;
F_256 ( V_3 ) ;
F_257 ( V_86 ) ;
return 0 ;
}
static int F_258 ( struct V_3 * V_198 , struct V_86 * V_86 )
{
if ( ! F_259 ( V_86 ) )
return - V_304 ;
F_256 ( V_89 ( V_86 ) ) ;
F_256 ( V_198 ) ;
return F_254 ( V_198 , V_86 ) ;
}
static int F_260 ( struct V_3 * V_305 , struct V_86 * V_302 , struct V_3 * V_306 , struct V_86 * V_307 )
{
bool V_308 = F_261 ( V_302 ) ;
bool V_309 = F_261 ( V_307 ) ;
if ( V_305 != V_306 && V_308 != V_309 ) {
if ( V_308 ) {
F_256 ( V_305 ) ;
F_194 ( V_306 ) ;
} else {
F_256 ( V_306 ) ;
F_194 ( V_305 ) ;
}
}
V_305 -> V_81 = V_305 -> V_82 =
V_306 -> V_81 = V_306 -> V_82 =
V_89 ( V_302 ) -> V_81 =
V_89 ( V_307 ) -> V_81 = V_83 ;
return 0 ;
}
static int F_262 ( struct V_3 * V_305 , struct V_86 * V_302 )
{
struct V_86 * V_310 ;
int error ;
V_310 = F_263 ( V_302 -> V_311 , & V_302 -> V_299 ) ;
if ( ! V_310 )
return - V_112 ;
error = F_242 ( V_305 , V_310 ,
V_312 | V_313 , V_314 ) ;
F_257 ( V_310 ) ;
if ( error )
return error ;
F_264 ( V_310 ) ;
return 0 ;
}
static int F_265 ( struct V_3 * V_305 , struct V_86 * V_302 , struct V_3 * V_306 , struct V_86 * V_307 , unsigned int V_14 )
{
struct V_3 * V_3 = V_89 ( V_302 ) ;
int V_315 = F_255 ( V_3 -> V_92 ) ;
if ( V_14 & ~ ( V_316 | V_317 | V_318 ) )
return - V_161 ;
if ( V_14 & V_317 )
return F_260 ( V_305 , V_302 , V_306 , V_307 ) ;
if ( ! F_259 ( V_307 ) )
return - V_304 ;
if ( V_14 & V_318 ) {
int error ;
error = F_262 ( V_305 , V_302 ) ;
if ( error )
return error ;
}
if ( F_266 ( V_307 ) ) {
( void ) F_254 ( V_306 , V_307 ) ;
if ( V_315 ) {
F_256 ( V_89 ( V_307 ) ) ;
F_256 ( V_305 ) ;
}
} else if ( V_315 ) {
F_256 ( V_305 ) ;
F_194 ( V_306 ) ;
}
V_305 -> V_65 -= V_211 ;
V_306 -> V_65 += V_211 ;
V_305 -> V_81 = V_305 -> V_82 =
V_306 -> V_81 = V_306 -> V_82 =
V_3 -> V_81 = V_83 ;
return 0 ;
}
static int F_267 ( struct V_3 * V_198 , struct V_86 * V_86 , const char * V_319 )
{
int error ;
int V_218 ;
struct V_3 * V_3 ;
struct V_5 * V_5 ;
struct V_28 * V_29 ;
V_218 = strlen ( V_319 ) + 1 ;
if ( V_218 > V_21 )
return - V_320 ;
V_3 = F_183 ( V_198 -> V_34 , V_198 , V_214 | V_321 , 0 , V_16 ) ;
if ( ! V_3 )
return - V_27 ;
error = F_244 ( V_3 , V_198 , & V_86 -> V_299 ,
V_300 , NULL ) ;
if ( error ) {
if ( error != - V_278 ) {
F_247 ( V_3 ) ;
return error ;
}
error = 0 ;
}
V_29 = F_21 ( V_3 ) ;
V_3 -> V_65 = V_218 - 1 ;
if ( V_218 <= V_322 ) {
V_3 -> V_323 = F_268 ( V_319 , V_218 , V_119 ) ;
if ( ! V_3 -> V_323 ) {
F_247 ( V_3 ) ;
return - V_112 ;
}
V_3 -> V_204 = & V_324 ;
} else {
F_269 ( V_3 ) ;
error = F_4 ( V_3 , 0 , & V_5 , V_163 ) ;
if ( error ) {
F_247 ( V_3 ) ;
return error ;
}
V_3 -> V_9 -> V_102 = & V_103 ;
V_3 -> V_204 = & V_325 ;
memcpy ( F_270 ( V_5 ) , V_319 , V_218 ) ;
F_121 ( V_5 ) ;
F_79 ( V_5 ) ;
F_77 ( V_5 ) ;
F_42 ( V_5 ) ;
}
V_198 -> V_65 += V_211 ;
V_198 -> V_81 = V_198 -> V_82 = V_83 ;
F_245 ( V_86 , V_3 ) ;
F_246 ( V_86 ) ;
return 0 ;
}
static void F_271 ( void * V_272 )
{
F_155 ( V_272 ) ;
F_42 ( V_272 ) ;
}
static const char * F_272 ( struct V_86 * V_86 ,
struct V_3 * V_3 ,
struct V_326 * V_256 )
{
struct V_5 * V_5 = NULL ;
int error ;
if ( ! V_86 ) {
V_5 = F_273 ( V_3 -> V_9 , 0 ) ;
if ( ! V_5 )
return F_274 ( - V_327 ) ;
if ( ! F_74 ( V_5 ) ) {
F_42 ( V_5 ) ;
return F_274 ( - V_327 ) ;
}
} else {
error = F_4 ( V_3 , 0 , & V_5 , V_78 ) ;
if ( error )
return F_274 ( error ) ;
F_77 ( V_5 ) ;
}
F_275 ( V_256 , F_271 , V_5 ) ;
return F_270 ( V_5 ) ;
}
static int V_300 ( struct V_3 * V_3 ,
const struct V_328 * V_329 ,
void * V_330 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
const struct V_328 * V_328 ;
struct V_331 * V_332 ;
T_9 V_218 ;
for ( V_328 = V_329 ; V_328 -> V_333 != NULL ; V_328 ++ ) {
V_332 = F_276 ( V_328 -> V_334 , V_328 -> V_335 ) ;
if ( ! V_332 )
return - V_112 ;
V_218 = strlen ( V_328 -> V_333 ) + 1 ;
V_332 -> V_333 = F_277 ( V_336 + V_218 ,
V_119 ) ;
if ( ! V_332 -> V_333 ) {
F_278 ( V_332 ) ;
return - V_112 ;
}
memcpy ( V_332 -> V_333 , V_337 ,
V_336 ) ;
memcpy ( V_332 -> V_333 + V_336 ,
V_328 -> V_333 , V_218 ) ;
F_279 ( & V_29 -> V_106 , V_332 ) ;
}
return 0 ;
}
static int F_280 ( const struct V_338 * V_339 ,
struct V_86 * V_340 , struct V_3 * V_3 ,
const char * V_333 , void * V_139 , T_9 V_15 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
V_333 = F_281 ( V_339 , V_333 ) ;
return F_282 ( & V_29 -> V_106 , V_333 , V_139 , V_15 ) ;
}
static int F_283 ( const struct V_338 * V_339 ,
struct V_86 * V_340 , struct V_3 * V_3 ,
const char * V_333 , const void * V_334 ,
T_9 V_15 , int V_14 )
{
struct V_28 * V_29 = F_21 ( V_3 ) ;
V_333 = F_281 ( V_339 , V_333 ) ;
return F_284 ( & V_29 -> V_106 , V_333 , V_334 , V_15 , V_14 ) ;
}
static T_8 F_285 ( struct V_86 * V_86 , char * V_139 , T_9 V_15 )
{
struct V_28 * V_29 = F_21 ( V_89 ( V_86 ) ) ;
return F_286 ( V_89 ( V_86 ) , & V_29 -> V_106 , V_139 , V_15 ) ;
}
static struct V_86 * F_287 ( struct V_86 * V_341 )
{
return F_274 ( - V_342 ) ;
}
static int F_288 ( struct V_3 * V_343 , void * V_344 )
{
T_10 * V_345 = V_344 ;
T_11 V_346 = V_345 [ 2 ] ;
V_346 = ( V_346 << 32 ) | V_345 [ 1 ] ;
return V_343 -> V_143 == V_346 && V_345 [ 0 ] == V_343 -> V_201 ;
}
static struct V_86 * F_289 ( struct V_11 * V_12 ,
struct V_347 * V_347 , int V_348 , int V_349 )
{
struct V_3 * V_3 ;
struct V_86 * V_86 = NULL ;
V_281 V_346 ;
if ( V_348 < 3 )
return NULL ;
V_346 = V_347 -> V_350 [ 2 ] ;
V_346 = ( V_346 << 32 ) | V_347 -> V_350 [ 1 ] ;
V_3 = F_290 ( V_12 , ( unsigned long ) ( V_346 + V_347 -> V_350 [ 0 ] ) ,
F_288 , V_347 -> V_350 ) ;
if ( V_3 ) {
V_86 = F_291 ( V_3 ) ;
F_247 ( V_3 ) ;
}
return V_86 ;
}
static int F_292 ( struct V_3 * V_3 , T_10 * V_345 , int * V_218 ,
struct V_3 * V_351 )
{
if ( * V_218 < 3 ) {
* V_218 = 3 ;
return V_352 ;
}
if ( F_293 ( V_3 ) ) {
static F_294 ( V_80 ) ;
F_17 ( & V_80 ) ;
if ( F_293 ( V_3 ) )
F_295 ( V_3 ,
V_3 -> V_143 + V_3 -> V_201 ) ;
F_18 ( & V_80 ) ;
}
V_345 [ 0 ] = V_3 -> V_201 ;
V_345 [ 1 ] = V_3 -> V_143 ;
V_345 [ 2 ] = ( ( T_11 ) V_3 -> V_143 ) >> 32 ;
* V_218 = 3 ;
return 1 ;
}
static int F_296 ( char * V_353 , struct V_10 * V_23 ,
bool V_354 )
{
char * V_355 , * V_334 , * V_356 ;
struct V_137 * V_138 = NULL ;
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
if ( ( V_334 = strchr ( V_355 , '=' ) ) != NULL ) {
* V_334 ++ = 0 ;
} else {
F_297 ( L_2 ,
V_355 ) ;
goto error;
}
if ( ! strcmp ( V_355 , L_3 ) ) {
unsigned long long V_15 ;
V_15 = F_298 ( V_334 , & V_356 ) ;
if ( * V_356 == '%' ) {
V_15 <<= V_58 ;
V_15 *= V_1 ;
F_299 ( V_15 , 100 ) ;
V_356 ++ ;
}
if ( * V_356 )
goto V_359;
V_23 -> V_35 =
F_300 ( V_15 , V_21 ) ;
} else if ( ! strcmp ( V_355 , L_4 ) ) {
V_23 -> V_35 = F_298 ( V_334 , & V_356 ) ;
if ( * V_356 )
goto V_359;
} else if ( ! strcmp ( V_355 , L_5 ) ) {
V_23 -> V_24 = F_298 ( V_334 , & V_356 ) ;
if ( * V_356 )
goto V_359;
} else if ( ! strcmp ( V_355 , L_6 ) ) {
if ( V_354 )
continue;
V_23 -> V_140 = F_301 ( V_334 , & V_356 , 8 ) & 07777 ;
if ( * V_356 )
goto V_359;
} else if ( ! strcmp ( V_355 , L_7 ) ) {
if ( V_354 )
continue;
V_357 = F_301 ( V_334 , & V_356 , 0 ) ;
if ( * V_356 )
goto V_359;
V_23 -> V_357 = F_302 ( F_303 () , V_357 ) ;
if ( ! F_304 ( V_23 -> V_357 ) )
goto V_359;
} else if ( ! strcmp ( V_355 , L_8 ) ) {
if ( V_354 )
continue;
V_358 = F_301 ( V_334 , & V_356 , 0 ) ;
if ( * V_356 )
goto V_359;
V_23 -> V_358 = F_305 ( F_303 () , V_358 ) ;
if ( ! F_306 ( V_23 -> V_358 ) )
goto V_359;
} else if ( ! strcmp ( V_355 , L_9 ) ) {
F_307 ( V_138 ) ;
V_138 = NULL ;
if ( F_308 ( V_334 , & V_138 ) )
goto V_359;
} else {
F_297 ( L_10 , V_355 ) ;
goto error;
}
}
V_23 -> V_138 = V_138 ;
return 0 ;
V_359:
F_297 ( L_11 ,
V_334 , V_355 ) ;
error:
F_307 ( V_138 ) ;
return 1 ;
}
static int F_309 ( struct V_11 * V_12 , int * V_14 , char * V_360 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
struct V_10 V_361 = * V_23 ;
unsigned long V_362 ;
int error = - V_161 ;
V_361 . V_138 = NULL ;
if ( F_296 ( V_360 , & V_361 , true ) )
return error ;
F_17 ( & V_23 -> V_25 ) ;
V_362 = V_23 -> V_24 - V_23 -> V_26 ;
if ( F_160 ( & V_23 -> V_36 , V_361 . V_35 ) > 0 )
goto V_118;
if ( V_361 . V_24 < V_362 )
goto V_118;
if ( V_361 . V_35 && ! V_23 -> V_35 )
goto V_118;
if ( V_361 . V_24 && ! V_23 -> V_24 )
goto V_118;
error = 0 ;
V_23 -> V_35 = V_361 . V_35 ;
V_23 -> V_24 = V_361 . V_24 ;
V_23 -> V_26 = V_361 . V_24 - V_362 ;
if ( V_361 . V_138 ) {
F_307 ( V_23 -> V_138 ) ;
V_23 -> V_138 = V_361 . V_138 ;
}
V_118:
F_18 ( & V_23 -> V_25 ) ;
return error ;
}
static int F_310 ( struct V_135 * V_136 , struct V_86 * V_363 )
{
struct V_10 * V_23 = F_7 ( V_363 -> V_287 ) ;
if ( V_23 -> V_35 != F_1 () )
F_132 ( V_136 , L_12 ,
V_23 -> V_35 << ( V_58 - 10 ) ) ;
if ( V_23 -> V_24 != F_2 () )
F_132 ( V_136 , L_13 , V_23 -> V_24 ) ;
if ( V_23 -> V_140 != ( V_321 | V_364 ) )
F_132 ( V_136 , L_14 , V_23 -> V_140 ) ;
if ( ! F_311 ( V_23 -> V_357 , V_365 ) )
F_132 ( V_136 , L_15 ,
F_312 ( & V_366 , V_23 -> V_357 ) ) ;
if ( ! F_313 ( V_23 -> V_358 , V_367 ) )
F_132 ( V_136 , L_16 ,
F_314 ( & V_366 , V_23 -> V_358 ) ) ;
F_130 ( V_136 , V_23 -> V_138 ) ;
return 0 ;
}
static void F_315 ( struct V_11 * V_12 )
{
struct V_10 * V_23 = F_7 ( V_12 ) ;
F_316 ( & V_23 -> V_36 ) ;
F_307 ( V_23 -> V_138 ) ;
F_278 ( V_23 ) ;
V_12 -> V_13 = NULL ;
}
int F_317 ( struct V_11 * V_12 , void * V_360 , int V_368 )
{
struct V_3 * V_3 ;
struct V_10 * V_23 ;
int V_369 = - V_112 ;
V_23 = F_318 ( F_319 ( ( int ) sizeof( struct V_10 ) ,
V_370 ) , V_119 ) ;
if ( ! V_23 )
return - V_112 ;
V_23 -> V_140 = V_321 | V_364 ;
V_23 -> V_357 = F_320 () ;
V_23 -> V_358 = F_321 () ;
V_12 -> V_13 = V_23 ;
#ifdef F_322
if ( ! ( V_12 -> V_371 & V_372 ) ) {
V_23 -> V_35 = F_1 () ;
V_23 -> V_24 = F_2 () ;
if ( F_296 ( V_360 , V_23 , false ) ) {
V_369 = - V_161 ;
goto V_167;
}
} else {
V_12 -> V_371 |= V_373 ;
}
V_12 -> V_374 = & V_375 ;
V_12 -> V_371 |= V_376 ;
#else
V_12 -> V_371 |= V_373 ;
#endif
F_188 ( & V_23 -> V_25 ) ;
if ( F_323 ( & V_23 -> V_36 , 0 , V_119 ) )
goto V_167;
V_23 -> V_26 = V_23 -> V_24 ;
V_12 -> V_377 = V_157 ;
V_12 -> V_378 = V_21 ;
V_12 -> V_379 = V_58 ;
V_12 -> V_380 = V_289 ;
V_12 -> V_215 = & V_216 ;
V_12 -> V_381 = 1 ;
#ifdef F_324
V_12 -> V_382 = V_383 ;
#endif
#ifdef F_325
V_12 -> V_371 |= V_384 ;
#endif
V_3 = F_183 ( V_12 , NULL , V_210 | V_23 -> V_140 , 0 , V_16 ) ;
if ( ! V_3 )
goto V_167;
V_3 -> V_385 = V_23 -> V_357 ;
V_3 -> V_386 = V_23 -> V_358 ;
V_12 -> V_387 = F_326 ( V_3 ) ;
if ( ! V_12 -> V_387 )
goto V_167;
return 0 ;
V_167:
F_315 ( V_12 ) ;
return V_369 ;
}
static struct V_3 * F_327 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
V_29 = F_328 ( V_388 , V_119 ) ;
if ( ! V_29 )
return NULL ;
return & V_29 -> V_107 ;
}
static void F_329 ( struct V_389 * V_390 )
{
struct V_3 * V_3 = F_330 ( V_390 , struct V_3 , V_391 ) ;
if ( F_331 ( V_3 -> V_92 ) )
F_278 ( V_3 -> V_323 ) ;
F_332 ( V_388 , F_21 ( V_3 ) ) ;
}
static void F_333 ( struct V_3 * V_3 )
{
if ( F_86 ( V_3 -> V_92 ) )
F_334 ( & F_21 ( V_3 ) -> V_146 ) ;
F_335 ( & V_3 -> V_391 , F_329 ) ;
}
static void F_336 ( void * V_392 )
{
struct V_28 * V_29 = V_392 ;
F_337 ( & V_29 -> V_107 ) ;
}
static int F_338 ( void )
{
V_388 = F_339 ( L_17 ,
sizeof( struct V_28 ) ,
0 , V_393 | V_394 , F_336 ) ;
return 0 ;
}
static void F_340 ( void )
{
F_341 ( V_388 ) ;
}
static struct V_86 * F_342 ( struct V_395 * V_396 ,
int V_14 , const char * V_397 , void * V_360 )
{
return F_343 ( V_396 , V_14 , V_360 , F_317 ) ;
}
int T_14 F_344 ( void )
{
int error ;
if ( V_388 )
return 0 ;
error = F_338 () ;
if ( error )
goto V_398;
error = F_345 ( & V_399 ) ;
if ( error ) {
F_297 ( L_18 ) ;
goto V_400;
}
V_401 = F_346 ( & V_399 ) ;
if ( F_347 ( V_401 ) ) {
error = F_348 ( V_401 ) ;
F_297 ( L_19 ) ;
goto V_402;
}
return 0 ;
V_402:
F_349 ( & V_399 ) ;
V_400:
F_340 () ;
V_398:
V_401 = F_274 ( error ) ;
return error ;
}
int T_14 F_344 ( void )
{
F_45 ( F_345 ( & V_399 ) != 0 ) ;
V_401 = F_346 ( & V_399 ) ;
F_45 ( F_347 ( V_401 ) ) ;
return 0 ;
}
int F_108 ( T_3 V_48 , struct V_5 * V_5 )
{
return 0 ;
}
int F_176 ( struct V_191 * V_191 , int V_80 , struct V_192 * V_193 )
{
return 0 ;
}
void F_63 ( struct V_39 * V_40 )
{
}
void F_81 ( struct V_3 * V_3 , T_2 V_71 , T_2 V_72 )
{
F_350 ( V_3 -> V_9 , V_71 , V_72 ) ;
}
static struct V_191 * F_351 ( const char * V_333 , T_2 V_15 ,
unsigned long V_14 , unsigned int V_403 )
{
struct V_191 * V_404 ;
struct V_3 * V_3 ;
struct V_405 V_405 ;
struct V_11 * V_12 ;
struct V_406 V_114 ;
if ( F_347 ( V_401 ) )
return F_352 ( V_401 ) ;
if ( V_15 < 0 || V_15 > V_157 )
return F_274 ( - V_161 ) ;
if ( F_8 ( V_14 , V_15 ) )
return F_274 ( - V_112 ) ;
V_404 = F_274 ( - V_112 ) ;
V_114 . V_333 = V_333 ;
V_114 . V_218 = strlen ( V_333 ) ;
V_114 . V_407 = 0 ;
V_12 = V_401 -> V_408 ;
V_405 . V_85 = F_353 ( V_401 ) ;
V_405 . V_86 = F_354 ( V_12 , & V_114 ) ;
if ( ! V_405 . V_86 )
goto V_409;
F_355 ( V_405 . V_86 , & V_410 ) ;
V_404 = F_274 ( - V_27 ) ;
V_3 = F_183 ( V_12 , NULL , V_206 | V_321 , 0 , V_14 ) ;
if ( ! V_3 )
goto V_409;
V_3 -> V_403 |= V_403 ;
F_245 ( V_405 . V_86 , V_3 ) ;
V_3 -> V_65 = V_15 ;
F_356 ( V_3 ) ;
V_404 = F_274 ( F_357 ( V_3 , V_15 ) ) ;
if ( F_347 ( V_404 ) )
goto V_411;
V_404 = F_358 ( & V_405 , V_269 | V_412 ,
& V_209 ) ;
if ( F_347 ( V_404 ) )
goto V_411;
return V_404 ;
V_409:
F_11 ( V_14 , V_15 ) ;
V_411:
F_359 ( & V_405 ) ;
return V_404 ;
}
struct V_191 * F_360 ( const char * V_333 , T_2 V_15 , unsigned long V_14 )
{
return F_351 ( V_333 , V_15 , V_14 , V_413 ) ;
}
struct V_191 * F_361 ( const char * V_333 , T_2 V_15 , unsigned long V_14 )
{
return F_351 ( V_333 , V_15 , V_14 , 0 ) ;
}
int F_362 ( struct V_59 * V_60 )
{
struct V_191 * V_191 ;
T_2 V_15 = V_60 -> V_63 - V_60 -> V_64 ;
V_191 = F_351 ( L_20 , V_15 , V_60 -> V_414 , V_413 ) ;
if ( F_347 ( V_191 ) )
return F_348 ( V_191 ) ;
if ( V_60 -> V_61 )
F_363 ( V_60 -> V_61 ) ;
V_60 -> V_61 = V_191 ;
V_60 -> V_144 = & V_197 ;
return 0 ;
}
struct V_5 * F_364 ( struct V_39 * V_40 ,
T_1 V_4 , T_4 V_108 )
{
#ifdef F_365
struct V_3 * V_3 = V_40 -> V_122 ;
struct V_5 * V_5 ;
int error ;
F_45 ( V_40 -> V_102 != & V_103 ) ;
error = F_5 ( V_3 , V_4 , & V_5 , V_160 ,
V_108 , NULL , NULL ) ;
if ( error )
V_5 = F_274 ( error ) ;
else
F_77 ( V_5 ) ;
return V_5 ;
#else
return F_366 ( V_40 , V_4 , V_108 ) ;
#endif
}
