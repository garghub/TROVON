static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static inline struct V_1 * F_4 ( struct V_6 * V_7 )
{
return F_2 ( F_5 ( V_7 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static inline struct V_1 * F_6 ( const struct V_1 * V_8 )
{
struct V_2 * V_9 = V_8 -> V_5 . V_2 -> V_10 ;
if ( V_9 )
return F_1 ( V_9 ) ;
return NULL ;
}
static inline bool F_7 ( struct V_6 * V_7 )
{
return V_7 -> V_11 ;
}
static inline bool F_7 ( struct V_6 * V_7 )
{
return false ;
}
static inline bool F_8 ( const struct V_1 * V_8 )
{
return F_9 ( V_12 , & V_8 -> V_13 ) ;
}
static inline int F_10 ( const struct V_1 * V_8 )
{
return F_9 ( V_14 , & V_8 -> V_13 ) ;
}
static inline int F_11 ( const struct V_1 * V_8 )
{
return F_9 ( V_15 , & V_8 -> V_13 ) ;
}
static inline int F_12 ( const struct V_1 * V_8 )
{
return F_9 ( V_16 , & V_8 -> V_13 ) ;
}
static inline int F_13 ( const struct V_1 * V_8 )
{
return F_9 ( V_17 , & V_8 -> V_13 ) ;
}
static inline int F_14 ( const struct V_1 * V_8 )
{
return F_9 ( V_18 , & V_8 -> V_13 ) ;
}
static inline int F_15 ( const struct V_1 * V_8 )
{
return F_9 ( V_19 , & V_8 -> V_13 ) ;
}
static inline int F_16 ( const struct V_1 * V_8 )
{
return F_9 ( V_20 , & V_8 -> V_13 ) ;
}
static struct V_21 * F_17 ( struct V_22 * V_23 ,
int V_13 , const char * V_24 , void * V_25 )
{
struct V_22 * V_26 = F_18 ( L_1 ) ;
struct V_21 * V_27 = F_19 ( - V_28 ) ;
if ( V_26 ) {
char V_29 [] =
L_2
L_3 ;
V_27 = V_26 -> V_30 ( V_26 , V_13 ,
V_24 , V_29 ) ;
F_20 ( V_26 ) ;
}
return V_27 ;
}
static void F_21 ( const struct V_1 * V_8 ,
struct V_31 * V_32 )
{
while ( V_8 && ! F_22 ( V_8 -> V_33 , V_34 ) )
V_8 = F_6 ( V_8 ) ;
if ( V_8 )
F_23 ( V_32 , V_8 -> V_33 , V_34 ) ;
else
F_24 ( V_32 , V_34 ) ;
F_25 ( ! F_22 ( V_32 , V_34 ) ) ;
}
static void F_26 ( const struct V_1 * V_8 , T_1 * V_32 )
{
while ( V_8 && ! F_27 ( V_8 -> V_35 ,
V_36 [ V_37 ] ) )
V_8 = F_6 ( V_8 ) ;
if ( V_8 )
F_28 ( * V_32 , V_8 -> V_35 ,
V_36 [ V_37 ] ) ;
else
* V_32 = V_36 [ V_37 ] ;
F_25 ( ! F_27 ( * V_32 , V_36 [ V_37 ] ) ) ;
}
static void F_29 ( struct V_1 * V_8 ,
struct V_6 * V_38 )
{
if ( F_15 ( V_8 ) )
V_38 -> V_13 |= V_39 ;
else
V_38 -> V_13 &= ~ V_39 ;
if ( F_16 ( V_8 ) )
V_38 -> V_13 |= V_40 ;
else
V_38 -> V_13 &= ~ V_40 ;
}
static int F_30 ( const struct V_1 * V_41 , const struct V_1 * V_42 )
{
return F_31 ( V_41 -> V_33 , V_42 -> V_33 ) &&
F_32 ( V_41 -> V_35 , V_42 -> V_35 ) &&
F_10 ( V_41 ) <= F_10 ( V_42 ) &&
F_11 ( V_41 ) <= F_11 ( V_42 ) ;
}
static struct V_1 * F_33 ( const struct V_1 * V_8 )
{
struct V_1 * V_43 ;
V_43 = F_34 ( V_8 , sizeof( * V_8 ) , V_44 ) ;
if ( ! V_43 )
return NULL ;
if ( ! F_35 ( & V_43 -> V_33 , V_44 ) ) {
F_36 ( V_43 ) ;
return NULL ;
}
F_24 ( V_43 -> V_33 , V_8 -> V_33 ) ;
return V_43 ;
}
static void F_37 ( struct V_1 * V_43 )
{
F_38 ( V_43 -> V_33 ) ;
F_36 ( V_43 ) ;
}
static int F_39 ( const struct V_1 * V_45 , const struct V_1 * V_43 )
{
struct V_2 * V_3 ;
struct V_1 * V_46 , * V_47 ;
int V_27 ;
F_40 () ;
V_27 = - V_48 ;
F_41 (c, cont, cur)
if ( ! F_30 ( V_46 , V_43 ) )
goto V_49;
V_27 = 0 ;
if ( V_45 == & V_50 )
goto V_49;
V_47 = F_6 ( V_45 ) ;
V_27 = - V_51 ;
if ( ! F_30 ( V_43 , V_47 ) )
goto V_49;
V_27 = - V_52 ;
F_41 (c, cont, par) {
if ( ( F_10 ( V_43 ) || F_10 ( V_46 ) ) &&
V_46 != V_45 &&
F_22 ( V_43 -> V_33 , V_46 -> V_33 ) )
goto V_49;
if ( ( F_11 ( V_43 ) || F_11 ( V_46 ) ) &&
V_46 != V_45 &&
F_27 ( V_43 -> V_35 , V_46 -> V_35 ) )
goto V_49;
}
V_27 = - V_53 ;
if ( ( F_42 ( V_45 -> V_5 . V_2 ) || V_45 -> V_54 ) &&
( F_43 ( V_43 -> V_33 ) ||
F_44 ( V_43 -> V_35 ) ) )
goto V_49;
V_27 = 0 ;
V_49:
F_45 () ;
return V_27 ;
}
static int F_46 ( struct V_1 * V_55 , struct V_1 * V_56 )
{
return F_22 ( V_55 -> V_33 , V_56 -> V_33 ) ;
}
static void
F_47 ( struct V_57 * V_58 , struct V_1 * V_46 )
{
if ( V_58 -> V_59 < V_46 -> V_59 )
V_58 -> V_59 = V_46 -> V_59 ;
return;
}
static void F_48 ( struct V_57 * V_58 ,
struct V_1 * V_60 )
{
struct V_1 * V_61 ;
struct V_2 * V_62 ;
F_40 () ;
F_49 (cp, pos_cgrp, root_cs) {
if ( F_43 ( V_61 -> V_33 ) ) {
V_62 = F_50 ( V_62 ) ;
continue;
}
if ( F_13 ( V_61 ) )
F_47 ( V_58 , V_61 ) ;
}
F_45 () ;
}
static int F_51 ( T_2 * * V_63 ,
struct V_57 * * V_64 )
{
struct V_1 * V_61 ;
struct V_1 * * V_65 ;
int V_66 ;
int V_67 , V_68 , V_69 ;
T_2 * V_70 ;
struct V_57 * V_58 ;
int V_71 = 0 ;
int V_72 ;
struct V_2 * V_62 ;
V_70 = NULL ;
V_58 = NULL ;
V_65 = NULL ;
if ( F_13 ( & V_50 ) ) {
V_71 = 1 ;
V_70 = F_52 ( V_71 ) ;
if ( ! V_70 )
goto V_73;
V_58 = F_53 ( sizeof( struct V_57 ) , V_44 ) ;
if ( V_58 ) {
* V_58 = V_74 ;
F_48 ( V_58 , & V_50 ) ;
}
F_24 ( V_70 [ 0 ] , V_50 . V_33 ) ;
goto V_73;
}
V_65 = F_53 ( V_75 * sizeof( V_61 ) , V_44 ) ;
if ( ! V_65 )
goto V_73;
V_66 = 0 ;
F_40 () ;
F_49 (cp, pos_cgrp, &top_cpuset) {
if ( ! F_43 ( V_61 -> V_33 ) &&
! F_13 ( V_61 ) )
continue;
if ( F_13 ( V_61 ) )
V_65 [ V_66 ++ ] = V_61 ;
V_62 = F_50 ( V_62 ) ;
}
F_45 () ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ )
V_65 [ V_67 ] -> V_76 = V_67 ;
V_71 = V_66 ;
V_77:
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
struct V_1 * V_55 = V_65 [ V_67 ] ;
int V_78 = V_55 -> V_76 ;
for ( V_68 = 0 ; V_68 < V_66 ; V_68 ++ ) {
struct V_1 * V_56 = V_65 [ V_68 ] ;
int V_79 = V_56 -> V_76 ;
if ( V_78 != V_79 && F_46 ( V_55 , V_56 ) ) {
for ( V_69 = 0 ; V_69 < V_66 ; V_69 ++ ) {
struct V_1 * V_46 = V_65 [ V_69 ] ;
if ( V_46 -> V_76 == V_79 )
V_46 -> V_76 = V_78 ;
}
V_71 -- ;
goto V_77;
}
}
}
V_70 = F_52 ( V_71 ) ;
if ( ! V_70 )
goto V_73;
V_58 = F_53 ( V_71 * sizeof( struct V_57 ) , V_44 ) ;
for ( V_72 = 0 , V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
struct V_1 * V_55 = V_65 [ V_67 ] ;
struct V_31 * V_80 ;
int V_78 = V_55 -> V_76 ;
if ( V_78 < 0 ) {
continue;
}
V_80 = V_70 [ V_72 ] ;
if ( V_72 == V_71 ) {
static int V_81 = 10 ;
if ( V_81 ) {
F_54 ( V_82
L_4
L_5
L_6 ,
V_72 , V_71 , V_66 , V_67 , V_78 ) ;
V_81 -- ;
}
continue;
}
F_55 ( V_80 ) ;
if ( V_58 )
* ( V_58 + V_72 ) = V_74 ;
for ( V_68 = V_67 ; V_68 < V_66 ; V_68 ++ ) {
struct V_1 * V_56 = V_65 [ V_68 ] ;
if ( V_78 == V_56 -> V_76 ) {
F_56 ( V_80 , V_80 , V_56 -> V_33 ) ;
if ( V_58 )
F_48 ( V_58 + V_72 , V_56 ) ;
V_56 -> V_76 = - 1 ;
}
}
V_72 ++ ;
}
F_25 ( V_72 != V_71 ) ;
V_73:
F_36 ( V_65 ) ;
if ( V_70 == NULL )
V_71 = 1 ;
* V_63 = V_70 ;
* V_64 = V_58 ;
return V_71 ;
}
static void F_57 ( void )
{
struct V_57 * V_83 ;
T_2 * V_70 ;
int V_71 ;
F_58 ( & V_84 ) ;
F_59 () ;
V_71 = F_51 ( & V_70 , & V_83 ) ;
F_60 ( V_71 , V_70 , V_83 ) ;
F_61 () ;
}
static void F_57 ( void )
{
}
static int F_51 ( T_2 * * V_63 ,
struct V_57 * * V_64 )
{
* V_63 = NULL ;
return 1 ;
}
void F_62 ( void )
{
F_63 ( & V_84 ) ;
F_57 () ;
F_64 ( & V_84 ) ;
}
static int F_65 ( struct V_6 * V_38 ,
struct V_85 * V_86 )
{
return ! F_66 ( & V_38 -> V_33 ,
( F_1 ( V_86 -> V_87 ) ) -> V_33 ) ;
}
static void F_67 ( struct V_6 * V_38 ,
struct V_85 * V_86 )
{
F_68 ( V_38 , ( ( F_1 ( V_86 -> V_87 ) ) -> V_33 ) ) ;
}
static void F_69 ( struct V_1 * V_8 , struct V_88 * V_89 )
{
struct V_85 V_86 ;
V_86 . V_87 = V_8 -> V_5 . V_2 ;
V_86 . V_90 = F_65 ;
V_86 . V_91 = F_67 ;
V_86 . V_89 = V_89 ;
F_70 ( & V_86 ) ;
}
static int F_71 ( struct V_1 * V_8 , struct V_1 * V_92 ,
const char * V_93 )
{
struct V_88 V_89 ;
int V_94 ;
int V_95 ;
if ( V_8 == & V_50 )
return - V_51 ;
if ( ! * V_93 ) {
F_55 ( V_92 -> V_33 ) ;
} else {
V_94 = F_72 ( V_93 , V_92 -> V_33 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( ! F_31 ( V_92 -> V_33 , V_96 ) )
return - V_52 ;
}
V_94 = F_39 ( V_8 , V_92 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( F_66 ( V_8 -> V_33 , V_92 -> V_33 ) )
return 0 ;
V_94 = F_73 ( & V_89 , V_97 , V_44 , NULL ) ;
if ( V_94 )
return V_94 ;
V_95 = F_13 ( V_92 ) ;
F_63 ( & V_98 ) ;
F_24 ( V_8 -> V_33 , V_92 -> V_33 ) ;
F_64 ( & V_98 ) ;
F_69 ( V_8 , & V_89 ) ;
F_74 ( & V_89 ) ;
if ( V_95 )
F_57 () ;
return 0 ;
}
static void F_75 ( struct V_99 * V_100 , const T_1 * V_101 ,
const T_1 * V_102 )
{
struct V_6 * V_38 = V_103 ;
V_38 -> V_35 = * V_102 ;
F_76 ( V_100 , V_101 , V_102 , V_104 ) ;
F_26 ( F_4 ( V_38 ) , & V_38 -> V_35 ) ;
}
static void F_77 ( struct V_6 * V_38 ,
T_1 * V_105 )
{
bool V_106 ;
if ( F_78 ( F_79 ( V_107 ) ) )
return;
if ( V_103 -> V_13 & V_108 )
return;
F_80 ( V_38 ) ;
V_106 = F_7 ( V_38 ) ||
! F_27 ( * V_105 , V_38 -> V_35 ) ;
if ( V_106 )
F_81 ( & V_38 -> V_109 ) ;
F_82 ( V_38 -> V_35 , V_38 -> V_35 , * V_105 ) ;
F_83 ( V_38 , V_105 , V_110 ) ;
F_83 ( V_38 , V_105 , V_111 ) ;
V_38 -> V_35 = * V_105 ;
if ( V_106 )
F_84 ( & V_38 -> V_109 ) ;
F_85 ( V_38 ) ;
}
static void F_86 ( struct V_6 * V_41 ,
struct V_85 * V_86 )
{
struct V_99 * V_100 ;
struct V_1 * V_8 ;
int V_112 ;
const T_1 * V_113 = V_86 -> V_25 ;
static T_1 V_105 ;
V_8 = F_1 ( V_86 -> V_87 ) ;
F_26 ( V_8 , & V_105 ) ;
F_77 ( V_41 , & V_105 ) ;
V_100 = F_87 ( V_41 ) ;
if ( ! V_100 )
return;
V_112 = F_14 ( V_8 ) ;
F_88 ( V_100 , & V_8 -> V_35 ) ;
if ( V_112 )
F_75 ( V_100 , V_113 , & V_8 -> V_35 ) ;
F_89 ( V_100 ) ;
}
static void F_90 ( struct V_1 * V_8 , const T_1 * V_113 ,
struct V_88 * V_89 )
{
struct V_85 V_86 ;
V_114 = V_8 ;
V_86 . V_87 = V_8 -> V_5 . V_2 ;
V_86 . V_90 = NULL ;
V_86 . V_91 = F_86 ;
V_86 . V_89 = V_89 ;
V_86 . V_25 = ( T_1 * ) V_113 ;
F_70 ( & V_86 ) ;
V_114 = NULL ;
}
static int F_91 ( struct V_1 * V_8 , struct V_1 * V_92 ,
const char * V_93 )
{
F_92 ( T_1 , V_113 , V_44 ) ;
int V_94 ;
struct V_88 V_89 ;
if ( ! V_113 )
return - V_115 ;
if ( V_8 == & V_50 ) {
V_94 = - V_51 ;
goto V_73;
}
if ( ! * V_93 ) {
F_93 ( V_92 -> V_35 ) ;
} else {
V_94 = F_94 ( V_93 , V_92 -> V_35 ) ;
if ( V_94 < 0 )
goto V_73;
if ( ! F_32 ( V_92 -> V_35 ,
V_36 [ V_37 ] ) ) {
V_94 = - V_52 ;
goto V_73;
}
}
* V_113 = V_8 -> V_35 ;
if ( F_95 ( * V_113 , V_92 -> V_35 ) ) {
V_94 = 0 ;
goto V_73;
}
V_94 = F_39 ( V_8 , V_92 ) ;
if ( V_94 < 0 )
goto V_73;
V_94 = F_73 ( & V_89 , V_97 , V_44 , NULL ) ;
if ( V_94 < 0 )
goto V_73;
F_63 ( & V_98 ) ;
V_8 -> V_35 = V_92 -> V_35 ;
F_64 ( & V_98 ) ;
F_90 ( V_8 , V_113 , & V_89 ) ;
F_74 ( & V_89 ) ;
V_73:
F_96 ( V_113 ) ;
return V_94 ;
}
int F_97 ( void )
{
return F_4 ( V_103 ) == V_114 ;
}
static int F_98 ( struct V_1 * V_8 , T_3 V_116 )
{
#ifdef F_99
if ( V_116 < - 1 || V_116 >= V_117 )
return - V_52 ;
#endif
if ( V_116 != V_8 -> V_59 ) {
V_8 -> V_59 = V_116 ;
if ( ! F_43 ( V_8 -> V_33 ) &&
F_13 ( V_8 ) )
F_57 () ;
}
return 0 ;
}
static void F_100 ( struct V_6 * V_38 ,
struct V_85 * V_86 )
{
F_29 ( F_1 ( V_86 -> V_87 ) , V_38 ) ;
}
static void F_101 ( struct V_1 * V_8 , struct V_88 * V_89 )
{
struct V_85 V_86 ;
V_86 . V_87 = V_8 -> V_5 . V_2 ;
V_86 . V_90 = NULL ;
V_86 . V_91 = F_100 ;
V_86 . V_89 = V_89 ;
F_70 ( & V_86 ) ;
}
static int F_102 ( T_4 V_118 , struct V_1 * V_8 ,
int V_119 )
{
struct V_1 * V_92 ;
int V_120 ;
int V_121 ;
struct V_88 V_89 ;
int V_122 ;
V_92 = F_33 ( V_8 ) ;
if ( ! V_92 )
return - V_115 ;
if ( V_119 )
F_103 ( V_118 , & V_92 -> V_13 ) ;
else
F_104 ( V_118 , & V_92 -> V_13 ) ;
V_122 = F_39 ( V_8 , V_92 ) ;
if ( V_122 < 0 )
goto V_49;
V_122 = F_73 ( & V_89 , V_97 , V_44 , NULL ) ;
if ( V_122 < 0 )
goto V_49;
V_120 = ( F_13 ( V_8 ) !=
F_13 ( V_92 ) ) ;
V_121 = ( ( F_16 ( V_8 ) != F_16 ( V_92 ) )
|| ( F_15 ( V_8 ) != F_15 ( V_92 ) ) ) ;
F_63 ( & V_98 ) ;
V_8 -> V_13 = V_92 -> V_13 ;
F_64 ( & V_98 ) ;
if ( ! F_43 ( V_92 -> V_33 ) && V_120 )
F_57 () ;
if ( V_121 )
F_101 ( V_8 , & V_89 ) ;
F_74 ( & V_89 ) ;
V_49:
F_37 ( V_92 ) ;
return V_122 ;
}
static void F_105 ( struct V_123 * V_124 )
{
V_124 -> V_125 = 0 ;
V_124 -> V_116 = 0 ;
V_124 -> time = 0 ;
F_106 ( & V_124 -> V_126 ) ;
}
static void F_107 ( struct V_123 * V_124 )
{
T_5 V_127 = F_108 () ;
T_5 V_128 = V_127 - V_124 -> time ;
if ( V_128 == 0 )
return;
V_128 = F_109 ( V_129 , V_128 ) ;
while ( V_128 -- > 0 )
V_124 -> V_116 = ( V_130 * V_124 -> V_116 ) / V_131 ;
V_124 -> time = V_127 ;
V_124 -> V_116 += ( ( V_131 - V_130 ) * V_124 -> V_125 ) / V_131 ;
V_124 -> V_125 = 0 ;
}
static void F_110 ( struct V_123 * V_124 )
{
F_111 ( & V_124 -> V_126 ) ;
F_107 ( V_124 ) ;
V_124 -> V_125 = F_109 ( V_132 , V_124 -> V_125 + V_131 ) ;
F_112 ( & V_124 -> V_126 ) ;
}
static int F_113 ( struct V_123 * V_124 )
{
int V_116 ;
F_111 ( & V_124 -> V_126 ) ;
F_107 ( V_124 ) ;
V_116 = V_124 -> V_116 ;
F_112 ( & V_124 -> V_126 ) ;
return V_116 ;
}
static int F_114 ( struct V_2 * V_133 , struct V_134 * V_135 )
{
struct V_1 * V_8 = F_1 ( V_133 ) ;
struct V_6 * V_7 ;
int V_27 ;
F_63 ( & V_84 ) ;
V_27 = - V_53 ;
if ( F_43 ( V_8 -> V_33 ) || F_44 ( V_8 -> V_35 ) )
goto V_136;
F_115 (task, cgrp, tset) {
V_27 = - V_52 ;
if ( V_7 -> V_13 & V_137 )
goto V_136;
V_27 = F_116 ( V_7 ) ;
if ( V_27 )
goto V_136;
}
V_8 -> V_54 ++ ;
V_27 = 0 ;
V_136:
F_64 ( & V_84 ) ;
return V_27 ;
}
static void F_117 ( struct V_2 * V_133 ,
struct V_134 * V_135 )
{
F_63 ( & V_84 ) ;
F_1 ( V_133 ) -> V_54 -- ;
F_64 ( & V_84 ) ;
}
static void F_118 ( struct V_2 * V_133 , struct V_134 * V_135 )
{
static T_1 V_138 ;
static T_1 V_139 ;
struct V_99 * V_100 ;
struct V_6 * V_7 ;
struct V_6 * V_140 = F_119 ( V_135 ) ;
struct V_2 * V_141 = F_120 ( V_135 ) ;
struct V_1 * V_8 = F_1 ( V_133 ) ;
struct V_1 * V_142 = F_1 ( V_141 ) ;
F_63 ( & V_84 ) ;
if ( V_8 == & V_50 )
F_24 ( V_143 , V_144 ) ;
else
F_21 ( V_8 , V_143 ) ;
F_26 ( V_8 , & V_139 ) ;
F_115 (task, cgrp, tset) {
F_121 ( F_68 ( V_7 , V_143 ) ) ;
F_77 ( V_7 , & V_139 ) ;
F_29 ( V_8 , V_7 ) ;
}
V_138 = V_142 -> V_35 ;
V_139 = V_8 -> V_35 ;
V_100 = F_87 ( V_140 ) ;
if ( V_100 ) {
F_88 ( V_100 , & V_139 ) ;
if ( F_14 ( V_8 ) )
F_75 ( V_100 , & V_138 ,
& V_139 ) ;
F_89 ( V_100 ) ;
}
V_8 -> V_54 -- ;
if ( F_43 ( V_8 -> V_33 ) || F_44 ( V_8 -> V_35 ) )
F_122 ( V_8 ) ;
F_64 ( & V_84 ) ;
}
static int F_123 ( struct V_2 * V_133 , struct V_145 * V_146 , T_6 V_116 )
{
struct V_1 * V_8 = F_1 ( V_133 ) ;
T_7 type = V_146 -> V_147 ;
int V_94 = - V_28 ;
F_63 ( & V_84 ) ;
if ( ! F_8 ( V_8 ) )
goto V_136;
switch ( type ) {
case V_148 :
V_94 = F_102 ( V_14 , V_8 , V_116 ) ;
break;
case V_149 :
V_94 = F_102 ( V_15 , V_8 , V_116 ) ;
break;
case V_150 :
V_94 = F_102 ( V_16 , V_8 , V_116 ) ;
break;
case V_151 :
V_94 = F_102 ( V_17 , V_8 , V_116 ) ;
break;
case V_152 :
V_94 = F_102 ( V_18 , V_8 , V_116 ) ;
break;
case V_153 :
V_154 = ! ! V_116 ;
break;
case V_155 :
V_94 = - V_51 ;
break;
case V_156 :
V_94 = F_102 ( V_19 , V_8 , V_116 ) ;
break;
case V_157 :
V_94 = F_102 ( V_20 , V_8 , V_116 ) ;
break;
default:
V_94 = - V_52 ;
break;
}
V_136:
F_64 ( & V_84 ) ;
return V_94 ;
}
static int F_124 ( struct V_2 * V_133 , struct V_145 * V_146 , T_3 V_116 )
{
struct V_1 * V_8 = F_1 ( V_133 ) ;
T_7 type = V_146 -> V_147 ;
int V_94 = - V_28 ;
F_63 ( & V_84 ) ;
if ( ! F_8 ( V_8 ) )
goto V_136;
switch ( type ) {
case V_158 :
V_94 = F_98 ( V_8 , V_116 ) ;
break;
default:
V_94 = - V_52 ;
break;
}
V_136:
F_64 ( & V_84 ) ;
return V_94 ;
}
static int F_125 ( struct V_2 * V_133 , struct V_145 * V_146 ,
const char * V_93 )
{
struct V_1 * V_8 = F_1 ( V_133 ) ;
struct V_1 * V_92 ;
int V_94 = - V_28 ;
F_126 ( & V_159 ) ;
F_127 ( V_160 ) ;
F_63 ( & V_84 ) ;
if ( ! F_8 ( V_8 ) )
goto V_136;
V_92 = F_33 ( V_8 ) ;
if ( ! V_92 ) {
V_94 = - V_115 ;
goto V_136;
}
switch ( V_146 -> V_147 ) {
case V_161 :
V_94 = F_71 ( V_8 , V_92 , V_93 ) ;
break;
case V_162 :
V_94 = F_91 ( V_8 , V_92 , V_93 ) ;
break;
default:
V_94 = - V_52 ;
break;
}
F_37 ( V_92 ) ;
V_136:
F_64 ( & V_84 ) ;
return V_94 ;
}
static T_8 F_128 ( char * V_163 , struct V_1 * V_8 )
{
T_8 V_164 ;
F_63 ( & V_98 ) ;
V_164 = F_129 ( V_163 , V_97 , V_8 -> V_33 ) ;
F_64 ( & V_98 ) ;
return V_164 ;
}
static T_8 F_130 ( char * V_163 , struct V_1 * V_8 )
{
T_8 V_164 ;
F_63 ( & V_98 ) ;
V_164 = F_131 ( V_163 , V_97 , V_8 -> V_35 ) ;
F_64 ( & V_98 ) ;
return V_164 ;
}
static T_9 F_132 ( struct V_2 * V_3 ,
struct V_145 * V_146 ,
struct V_165 * V_165 ,
char T_10 * V_93 ,
T_8 V_166 , T_11 * V_167 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_146 -> V_147 ;
char * V_163 ;
T_9 V_94 = 0 ;
char * V_168 ;
if ( ! ( V_163 = ( char * ) F_133 ( V_169 ) ) )
return - V_115 ;
V_168 = V_163 ;
switch ( type ) {
case V_161 :
V_168 += F_128 ( V_168 , V_8 ) ;
break;
case V_162 :
V_168 += F_130 ( V_168 , V_8 ) ;
break;
default:
V_94 = - V_52 ;
goto V_49;
}
* V_168 ++ = '\n' ;
V_94 = F_134 ( V_93 , V_166 , V_167 , V_163 , V_168 - V_163 ) ;
V_49:
F_135 ( ( unsigned long ) V_163 ) ;
return V_94 ;
}
static T_6 F_136 ( struct V_2 * V_3 , struct V_145 * V_146 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_146 -> V_147 ;
switch ( type ) {
case V_148 :
return F_10 ( V_8 ) ;
case V_149 :
return F_11 ( V_8 ) ;
case V_150 :
return F_12 ( V_8 ) ;
case V_151 :
return F_13 ( V_8 ) ;
case V_152 :
return F_14 ( V_8 ) ;
case V_153 :
return V_154 ;
case V_155 :
return F_113 ( & V_8 -> V_123 ) ;
case V_156 :
return F_15 ( V_8 ) ;
case V_157 :
return F_16 ( V_8 ) ;
default:
F_137 () ;
}
return 0 ;
}
static T_3 F_138 ( struct V_2 * V_3 , struct V_145 * V_146 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_146 -> V_147 ;
switch ( type ) {
case V_158 :
return V_8 -> V_59 ;
default:
F_137 () ;
}
return 0 ;
}
static struct F_3 * F_139 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
if ( ! V_3 -> V_10 )
return & V_50 . V_5 ;
V_8 = F_140 ( sizeof( * V_8 ) , V_44 ) ;
if ( ! V_8 )
return F_19 ( - V_115 ) ;
if ( ! F_35 ( & V_8 -> V_33 , V_44 ) ) {
F_36 ( V_8 ) ;
return F_19 ( - V_115 ) ;
}
F_103 ( V_17 , & V_8 -> V_13 ) ;
F_55 ( V_8 -> V_33 ) ;
F_93 ( V_8 -> V_35 ) ;
F_105 ( & V_8 -> V_123 ) ;
F_141 ( & V_8 -> V_170 , V_171 ) ;
V_8 -> V_59 = - 1 ;
return & V_8 -> V_5 ;
}
static int F_142 ( struct V_2 * V_133 )
{
struct V_1 * V_8 = F_1 ( V_133 ) ;
struct V_1 * V_10 = F_6 ( V_8 ) ;
struct V_1 * V_172 ;
struct V_2 * V_173 ;
if ( ! V_10 )
return 0 ;
F_63 ( & V_84 ) ;
F_103 ( V_12 , & V_8 -> V_13 ) ;
if ( F_15 ( V_10 ) )
F_103 ( V_19 , & V_8 -> V_13 ) ;
if ( F_16 ( V_10 ) )
F_103 ( V_20 , & V_8 -> V_13 ) ;
V_75 ++ ;
if ( ! F_9 ( V_174 , & V_133 -> V_13 ) )
goto V_136;
F_40 () ;
F_41 (tmp_cs, pos_cg, parent) {
if ( F_11 ( V_172 ) || F_10 ( V_172 ) ) {
F_45 () ;
goto V_136;
}
}
F_45 () ;
F_63 ( & V_98 ) ;
V_8 -> V_35 = V_10 -> V_35 ;
F_24 ( V_8 -> V_33 , V_10 -> V_33 ) ;
F_64 ( & V_98 ) ;
V_136:
F_64 ( & V_84 ) ;
return 0 ;
}
static void F_143 ( struct V_2 * V_133 )
{
struct V_1 * V_8 = F_1 ( V_133 ) ;
F_63 ( & V_84 ) ;
if ( F_13 ( V_8 ) )
F_102 ( V_17 , V_8 , 0 ) ;
V_75 -- ;
F_104 ( V_12 , & V_8 -> V_13 ) ;
F_64 ( & V_84 ) ;
}
static void F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_38 ( V_8 -> V_33 ) ;
F_36 ( V_8 ) ;
}
int T_12 F_145 ( void )
{
int V_122 = 0 ;
if ( ! F_35 ( & V_50 . V_33 , V_44 ) )
F_137 () ;
F_146 ( V_50 . V_33 ) ;
F_147 ( V_50 . V_35 ) ;
F_105 ( & V_50 . V_123 ) ;
F_103 ( V_17 , & V_50 . V_13 ) ;
V_50 . V_59 = - 1 ;
V_122 = F_148 ( & V_175 ) ;
if ( V_122 < 0 )
return V_122 ;
if ( ! F_35 ( & V_143 , V_44 ) )
F_137 () ;
V_75 = 1 ;
return 0 ;
}
static void F_149 ( struct V_6 * V_38 ,
struct V_85 * V_86 )
{
struct V_2 * V_176 = V_86 -> V_25 ;
F_150 () ;
F_151 ( V_176 , V_38 ) ;
F_152 () ;
}
static void F_153 ( struct V_1 * V_101 , struct V_1 * V_102 )
{
struct V_85 V_86 ;
V_86 . V_87 = V_101 -> V_5 . V_2 ;
V_86 . V_90 = NULL ;
V_86 . V_91 = F_149 ;
V_86 . V_89 = NULL ;
V_86 . V_25 = V_102 -> V_5 . V_2 ;
if ( F_70 ( & V_86 ) )
F_54 ( V_177 L_7
L_8 ) ;
}
static void F_154 ( struct V_1 * V_8 )
{
struct V_1 * V_10 ;
V_10 = F_6 ( V_8 ) ;
while ( F_43 ( V_10 -> V_33 ) ||
F_44 ( V_10 -> V_35 ) )
V_10 = F_6 ( V_10 ) ;
F_153 ( V_8 , V_10 ) ;
}
static void V_171 ( struct V_178 * V_179 )
{
static T_13 V_180 ;
static T_1 V_181 , V_182 ;
struct V_1 * V_8 = F_2 ( V_179 , struct V_1 , V_170 ) ;
bool V_183 ;
F_63 ( & V_84 ) ;
F_155 ( & V_180 , V_8 -> V_33 , V_50 . V_33 ) ;
F_156 ( V_181 , V_8 -> V_35 , V_50 . V_35 ) ;
if ( ! F_43 ( & V_180 ) ) {
F_63 ( & V_98 ) ;
F_155 ( V_8 -> V_33 , V_8 -> V_33 , & V_180 ) ;
F_64 ( & V_98 ) ;
F_69 ( V_8 , NULL ) ;
}
if ( ! F_44 ( V_181 ) ) {
V_182 = V_8 -> V_35 ;
F_63 ( & V_98 ) ;
F_156 ( V_8 -> V_35 , V_8 -> V_35 , V_181 ) ;
F_64 ( & V_98 ) ;
F_90 ( V_8 , & V_182 , NULL ) ;
}
V_183 = F_43 ( V_8 -> V_33 ) ||
F_44 ( V_8 -> V_35 ) ;
F_64 ( & V_84 ) ;
if ( V_183 )
F_154 ( V_8 ) ;
F_157 ( & V_8 -> V_5 ) ;
}
static void F_122 ( struct V_1 * V_8 )
{
if ( ! F_158 ( & V_8 -> V_5 ) )
return;
if ( ! F_159 ( V_160 , & V_8 -> V_170 ) )
F_157 ( & V_8 -> V_5 ) ;
}
static void F_160 ( struct V_178 * V_179 )
{
static T_13 V_184 , V_185 ;
static T_1 V_186 , V_182 ;
bool V_187 , V_188 ;
bool V_189 , V_190 ;
F_63 ( & V_84 ) ;
F_24 ( & V_184 , V_96 ) ;
V_186 = V_36 [ V_37 ] ;
V_187 = ! F_66 ( V_50 . V_33 , & V_184 ) ;
V_189 = F_155 ( & V_185 , V_50 . V_33 ,
& V_184 ) ;
V_188 = ! F_95 ( V_50 . V_35 , V_186 ) ;
F_156 ( V_182 , V_50 . V_35 , V_186 ) ;
V_190 = ! F_44 ( V_182 ) ;
if ( V_187 ) {
F_63 ( & V_98 ) ;
F_24 ( V_50 . V_33 , & V_184 ) ;
F_64 ( & V_98 ) ;
}
if ( V_188 ) {
V_182 = V_50 . V_35 ;
F_63 ( & V_98 ) ;
V_50 . V_35 = V_186 ;
F_64 ( & V_98 ) ;
F_90 ( & V_50 , & V_182 , NULL ) ;
}
if ( V_189 || V_190 ) {
struct V_1 * V_8 ;
struct V_2 * V_62 ;
F_40 () ;
F_49 (cs, pos_cgrp, &top_cpuset)
F_122 ( V_8 ) ;
F_45 () ;
}
F_64 ( & V_84 ) ;
F_127 ( V_160 ) ;
if ( V_187 ) {
struct V_57 * V_83 ;
T_2 * V_70 ;
int V_71 ;
F_63 ( & V_84 ) ;
V_71 = F_51 ( & V_70 , & V_83 ) ;
F_64 ( & V_84 ) ;
F_60 ( V_71 , V_70 , V_83 ) ;
}
}
void F_161 ( bool V_191 )
{
F_60 ( 1 , NULL , NULL ) ;
F_162 ( & V_159 ) ;
}
static int F_163 ( struct V_192 * V_193 ,
unsigned long V_194 , void * V_195 )
{
F_162 ( & V_159 ) ;
return V_196 ;
}
void T_12 F_164 ( void )
{
F_24 ( V_50 . V_33 , V_96 ) ;
V_50 . V_35 = V_36 [ V_37 ] ;
F_165 ( F_163 , 10 ) ;
V_160 =
F_166 ( L_9 , 0 ) ;
F_25 ( ! V_160 ) ;
}
void F_167 ( struct V_6 * V_38 , struct V_31 * V_32 )
{
F_63 ( & V_98 ) ;
F_80 ( V_38 ) ;
F_21 ( F_4 ( V_38 ) , V_32 ) ;
F_85 ( V_38 ) ;
F_64 ( & V_98 ) ;
}
void F_168 ( struct V_6 * V_38 )
{
const struct V_1 * V_8 ;
F_40 () ;
V_8 = F_4 ( V_38 ) ;
if ( V_8 )
F_169 ( V_38 , V_8 -> V_33 ) ;
F_45 () ;
}
void F_170 ( void )
{
F_147 ( V_103 -> V_35 ) ;
}
T_1 F_171 ( struct V_6 * V_38 )
{
T_1 V_197 ;
F_63 ( & V_98 ) ;
F_80 ( V_38 ) ;
F_26 ( F_4 ( V_38 ) , & V_197 ) ;
F_85 ( V_38 ) ;
F_64 ( & V_98 ) ;
return V_197 ;
}
int F_172 ( T_1 * V_198 )
{
return F_27 ( * V_198 , V_103 -> V_35 ) ;
}
static const struct V_1 * F_173 ( const struct V_1 * V_8 )
{
while ( ! ( F_11 ( V_8 ) || F_12 ( V_8 ) ) && F_6 ( V_8 ) )
V_8 = F_6 ( V_8 ) ;
return V_8 ;
}
int F_174 ( int V_199 , T_14 V_200 )
{
const struct V_1 * V_8 ;
int V_201 ;
if ( F_175 () || ( V_200 & V_202 ) )
return 1 ;
F_176 ( ! ( V_200 & V_203 ) ) ;
if ( F_177 ( V_199 , V_103 -> V_35 ) )
return 1 ;
if ( F_78 ( F_79 ( V_107 ) ) )
return 1 ;
if ( V_200 & V_203 )
return 0 ;
if ( V_103 -> V_13 & V_108 )
return 1 ;
F_63 ( & V_98 ) ;
F_80 ( V_103 ) ;
V_8 = F_173 ( F_4 ( V_103 ) ) ;
F_85 ( V_103 ) ;
V_201 = F_177 ( V_199 , V_8 -> V_35 ) ;
F_64 ( & V_98 ) ;
return V_201 ;
}
int F_178 ( int V_199 , T_14 V_200 )
{
if ( F_175 () || ( V_200 & V_202 ) )
return 1 ;
if ( F_177 ( V_199 , V_103 -> V_35 ) )
return 1 ;
if ( F_78 ( F_79 ( V_107 ) ) )
return 1 ;
return 0 ;
}
static int F_179 ( int * V_204 )
{
int V_199 ;
V_199 = F_180 ( * V_204 , V_103 -> V_35 ) ;
if ( V_199 == V_205 )
V_199 = F_181 ( V_103 -> V_35 ) ;
* V_204 = V_199 ;
return V_199 ;
}
int F_182 ( void )
{
if ( V_103 -> V_206 == V_207 )
V_103 -> V_206 =
F_183 ( & V_103 -> V_35 ) ;
return F_179 ( & V_103 -> V_206 ) ;
}
int F_184 ( void )
{
if ( V_103 -> V_208 == V_207 )
V_103 -> V_208 =
F_183 ( & V_103 -> V_35 ) ;
return F_179 ( & V_103 -> V_208 ) ;
}
int F_185 ( const struct V_6 * V_209 ,
const struct V_6 * V_210 )
{
return F_27 ( V_209 -> V_35 , V_210 -> V_35 ) ;
}
void F_186 ( struct V_6 * V_38 )
{
struct V_21 * V_21 ;
V_21 = F_4 ( V_38 ) -> V_5 . V_2 -> V_21 ;
F_111 ( & V_211 ) ;
if ( ! V_21 ) {
strcpy ( V_212 , L_10 ) ;
} else {
F_111 ( & V_21 -> V_213 ) ;
F_187 ( V_212 , ( const char * ) V_21 -> V_214 . V_215 ,
V_216 ) ;
F_112 ( & V_21 -> V_213 ) ;
}
F_131 ( V_217 , V_218 ,
V_38 -> V_35 ) ;
F_54 ( V_219 L_11 ,
V_38 -> V_220 , V_212 , V_217 ) ;
F_112 ( & V_211 ) ;
}
void F_188 ( void )
{
F_80 ( V_103 ) ;
F_110 ( & F_4 ( V_103 ) -> V_123 ) ;
F_85 ( V_103 ) ;
}
static int F_189 ( struct V_221 * V_222 , void * V_223 )
{
struct V_224 * V_224 ;
struct V_6 * V_38 ;
char * V_93 ;
struct F_3 * V_5 ;
int V_94 ;
V_94 = - V_115 ;
V_93 = F_53 ( V_97 , V_44 ) ;
if ( ! V_93 )
goto V_49;
V_94 = - V_225 ;
V_224 = V_222 -> V_147 ;
V_38 = F_190 ( V_224 , V_226 ) ;
if ( ! V_38 )
goto V_227;
F_40 () ;
V_5 = F_5 ( V_38 , V_4 ) ;
V_94 = F_191 ( V_5 -> V_2 , V_93 , V_97 ) ;
F_45 () ;
if ( V_94 < 0 )
goto V_228;
F_192 ( V_222 , V_93 ) ;
F_193 ( V_222 , '\n' ) ;
V_228:
F_194 ( V_38 ) ;
V_227:
F_36 ( V_93 ) ;
V_49:
return V_94 ;
}
static int F_195 ( struct V_229 * V_229 , struct V_165 * V_165 )
{
struct V_224 * V_224 = F_196 ( V_229 ) -> V_224 ;
return F_197 ( V_165 , F_189 , V_224 ) ;
}
void F_198 ( struct V_221 * V_222 , struct V_6 * V_7 )
{
F_199 ( V_222 , L_12 ) ;
F_200 ( V_222 , & V_7 -> V_35 ) ;
F_199 ( V_222 , L_13 ) ;
F_199 ( V_222 , L_14 ) ;
F_201 ( V_222 , & V_7 -> V_35 ) ;
F_199 ( V_222 , L_13 ) ;
}
