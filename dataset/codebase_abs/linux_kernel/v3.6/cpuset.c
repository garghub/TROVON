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
static inline bool F_6 ( struct V_6 * V_7 )
{
return V_7 -> V_8 ;
}
static inline bool F_6 ( struct V_6 * V_7 )
{
return false ;
}
static inline int F_7 ( const struct V_1 * V_9 )
{
return F_8 ( V_10 , & V_9 -> V_11 ) ;
}
static inline int F_9 ( const struct V_1 * V_9 )
{
return F_8 ( V_12 , & V_9 -> V_11 ) ;
}
static inline int F_10 ( const struct V_1 * V_9 )
{
return F_8 ( V_13 , & V_9 -> V_11 ) ;
}
static inline int F_11 ( const struct V_1 * V_9 )
{
return F_8 ( V_14 , & V_9 -> V_11 ) ;
}
static inline int F_12 ( const struct V_1 * V_9 )
{
return F_8 ( V_15 , & V_9 -> V_11 ) ;
}
static inline int F_13 ( const struct V_1 * V_9 )
{
return F_8 ( V_16 , & V_9 -> V_11 ) ;
}
static inline int F_14 ( const struct V_1 * V_9 )
{
return F_8 ( V_17 , & V_9 -> V_11 ) ;
}
static struct V_18 * F_15 ( struct V_19 * V_20 ,
int V_11 , const char * V_21 , void * V_22 )
{
struct V_19 * V_23 = F_16 ( L_1 ) ;
struct V_18 * V_24 = F_17 ( - V_25 ) ;
if ( V_23 ) {
char V_26 [] =
L_2
L_3 ;
V_24 = V_23 -> V_27 ( V_23 , V_11 ,
V_21 , V_26 ) ;
F_18 ( V_23 ) ;
}
return V_24 ;
}
static void F_19 ( const struct V_1 * V_9 ,
struct V_28 * V_29 )
{
while ( V_9 && ! F_20 ( V_9 -> V_30 , V_31 ) )
V_9 = V_9 -> V_32 ;
if ( V_9 )
F_21 ( V_29 , V_9 -> V_30 , V_31 ) ;
else
F_22 ( V_29 , V_31 ) ;
F_23 ( ! F_20 ( V_29 , V_31 ) ) ;
}
static void F_24 ( const struct V_1 * V_9 , T_1 * V_29 )
{
while ( V_9 && ! F_25 ( V_9 -> V_33 ,
V_34 [ V_35 ] ) )
V_9 = V_9 -> V_32 ;
if ( V_9 )
F_26 ( * V_29 , V_9 -> V_33 ,
V_34 [ V_35 ] ) ;
else
* V_29 = V_34 [ V_35 ] ;
F_23 ( ! F_25 ( * V_29 , V_34 [ V_35 ] ) ) ;
}
static void F_27 ( struct V_1 * V_9 ,
struct V_6 * V_36 )
{
if ( F_13 ( V_9 ) )
V_36 -> V_11 |= V_37 ;
else
V_36 -> V_11 &= ~ V_37 ;
if ( F_14 ( V_9 ) )
V_36 -> V_11 |= V_38 ;
else
V_36 -> V_11 &= ~ V_38 ;
}
static int F_28 ( const struct V_1 * V_39 , const struct V_1 * V_40 )
{
return F_29 ( V_39 -> V_30 , V_40 -> V_30 ) &&
F_30 ( V_39 -> V_33 , V_40 -> V_33 ) &&
F_7 ( V_39 ) <= F_7 ( V_40 ) &&
F_9 ( V_39 ) <= F_9 ( V_40 ) ;
}
static struct V_1 * F_31 ( const struct V_1 * V_9 )
{
struct V_1 * V_41 ;
V_41 = F_32 ( V_9 , sizeof( * V_9 ) , V_42 ) ;
if ( ! V_41 )
return NULL ;
if ( ! F_33 ( & V_41 -> V_30 , V_42 ) ) {
F_34 ( V_41 ) ;
return NULL ;
}
F_22 ( V_41 -> V_30 , V_9 -> V_30 ) ;
return V_41 ;
}
static void F_35 ( struct V_1 * V_41 )
{
F_36 ( V_41 -> V_30 ) ;
F_34 ( V_41 ) ;
}
static int F_37 ( const struct V_1 * V_43 , const struct V_1 * V_41 )
{
struct V_2 * V_3 ;
struct V_1 * V_44 , * V_45 ;
F_38 (cont, &cur->css.cgroup->children, sibling) {
if ( ! F_28 ( F_1 ( V_3 ) , V_41 ) )
return - V_46 ;
}
if ( V_43 == & V_47 )
return 0 ;
V_45 = V_43 -> V_32 ;
if ( ! F_28 ( V_41 , V_45 ) )
return - V_48 ;
F_38 (cont, &par->css.cgroup->children, sibling) {
V_44 = F_1 ( V_3 ) ;
if ( ( F_7 ( V_41 ) || F_7 ( V_44 ) ) &&
V_44 != V_43 &&
F_20 ( V_41 -> V_30 , V_44 -> V_30 ) )
return - V_49 ;
if ( ( F_9 ( V_41 ) || F_9 ( V_44 ) ) &&
V_44 != V_43 &&
F_25 ( V_41 -> V_33 , V_44 -> V_33 ) )
return - V_49 ;
}
if ( F_39 ( V_43 -> V_5 . V_2 ) ) {
if ( F_40 ( V_41 -> V_30 ) ||
F_41 ( V_41 -> V_33 ) ) {
return - V_50 ;
}
}
return 0 ;
}
static int F_42 ( struct V_1 * V_51 , struct V_1 * V_52 )
{
return F_20 ( V_51 -> V_30 , V_52 -> V_30 ) ;
}
static void
F_43 ( struct V_53 * V_54 , struct V_1 * V_44 )
{
if ( V_54 -> V_55 < V_44 -> V_55 )
V_54 -> V_55 = V_44 -> V_55 ;
return;
}
static void
F_44 ( struct V_53 * V_54 , struct V_1 * V_44 )
{
F_45 ( V_40 ) ;
F_46 ( & V_44 -> V_56 , & V_40 ) ;
while ( ! F_47 ( & V_40 ) ) {
struct V_1 * V_57 ;
struct V_2 * V_3 ;
struct V_1 * V_58 ;
V_57 = F_48 ( & V_40 , struct V_1 , V_56 ) ;
F_49 ( V_40 . V_59 ) ;
if ( F_40 ( V_57 -> V_30 ) )
continue;
if ( F_11 ( V_57 ) )
F_43 ( V_54 , V_57 ) ;
F_38 (cont, &cp->css.cgroup->children, sibling) {
V_58 = F_1 ( V_3 ) ;
F_50 ( & V_58 -> V_56 , & V_40 ) ;
}
}
}
static int F_51 ( T_2 * * V_60 ,
struct V_53 * * V_61 )
{
F_45 ( V_40 ) ;
struct V_1 * V_57 ;
struct V_1 * * V_62 ;
int V_63 ;
int V_64 , V_65 , V_66 ;
T_2 * V_67 ;
struct V_53 * V_54 ;
int V_68 = 0 ;
int V_69 ;
V_67 = NULL ;
V_54 = NULL ;
V_62 = NULL ;
if ( F_11 ( & V_47 ) ) {
V_68 = 1 ;
V_67 = F_52 ( V_68 ) ;
if ( ! V_67 )
goto V_70;
V_54 = F_53 ( sizeof( struct V_53 ) , V_42 ) ;
if ( V_54 ) {
* V_54 = V_71 ;
F_44 ( V_54 , & V_47 ) ;
}
F_22 ( V_67 [ 0 ] , V_47 . V_30 ) ;
goto V_70;
}
V_62 = F_53 ( V_72 * sizeof( V_57 ) , V_42 ) ;
if ( ! V_62 )
goto V_70;
V_63 = 0 ;
F_46 ( & V_47 . V_56 , & V_40 ) ;
while ( ! F_47 ( & V_40 ) ) {
struct V_2 * V_3 ;
struct V_1 * V_58 ;
V_57 = F_48 ( & V_40 , struct V_1 , V_56 ) ;
F_49 ( V_40 . V_59 ) ;
if ( F_40 ( V_57 -> V_30 ) )
continue;
if ( F_11 ( V_57 ) ) {
V_62 [ V_63 ++ ] = V_57 ;
continue;
}
F_38 (cont, &cp->css.cgroup->children, sibling) {
V_58 = F_1 ( V_3 ) ;
F_50 ( & V_58 -> V_56 , & V_40 ) ;
}
}
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ )
V_62 [ V_64 ] -> V_73 = V_64 ;
V_68 = V_63 ;
V_74:
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
struct V_1 * V_51 = V_62 [ V_64 ] ;
int V_75 = V_51 -> V_73 ;
for ( V_65 = 0 ; V_65 < V_63 ; V_65 ++ ) {
struct V_1 * V_52 = V_62 [ V_65 ] ;
int V_76 = V_52 -> V_73 ;
if ( V_75 != V_76 && F_42 ( V_51 , V_52 ) ) {
for ( V_66 = 0 ; V_66 < V_63 ; V_66 ++ ) {
struct V_1 * V_44 = V_62 [ V_66 ] ;
if ( V_44 -> V_73 == V_76 )
V_44 -> V_73 = V_75 ;
}
V_68 -- ;
goto V_74;
}
}
}
V_67 = F_52 ( V_68 ) ;
if ( ! V_67 )
goto V_70;
V_54 = F_53 ( V_68 * sizeof( struct V_53 ) , V_42 ) ;
for ( V_69 = 0 , V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
struct V_1 * V_51 = V_62 [ V_64 ] ;
struct V_28 * V_77 ;
int V_75 = V_51 -> V_73 ;
if ( V_75 < 0 ) {
continue;
}
V_77 = V_67 [ V_69 ] ;
if ( V_69 == V_68 ) {
static int V_78 = 10 ;
if ( V_78 ) {
F_54 ( V_79
L_4
L_5
L_6 ,
V_69 , V_68 , V_63 , V_64 , V_75 ) ;
V_78 -- ;
}
continue;
}
F_55 ( V_77 ) ;
if ( V_54 )
* ( V_54 + V_69 ) = V_71 ;
for ( V_65 = V_64 ; V_65 < V_63 ; V_65 ++ ) {
struct V_1 * V_52 = V_62 [ V_65 ] ;
if ( V_75 == V_52 -> V_73 ) {
F_56 ( V_77 , V_77 , V_52 -> V_30 ) ;
if ( V_54 )
F_44 ( V_54 + V_69 , V_52 ) ;
V_52 -> V_73 = - 1 ;
}
}
V_69 ++ ;
}
F_23 ( V_69 != V_68 ) ;
V_70:
F_34 ( V_62 ) ;
if ( V_67 == NULL )
V_68 = 1 ;
* V_60 = V_67 ;
* V_61 = V_54 ;
return V_68 ;
}
static void F_57 ( struct V_80 * V_81 )
{
struct V_53 * V_82 ;
T_2 * V_67 ;
int V_68 ;
F_58 () ;
F_59 () ;
V_68 = F_51 ( & V_67 , & V_82 ) ;
F_60 () ;
F_61 ( V_68 , V_67 , V_82 ) ;
F_62 () ;
}
static void F_57 ( struct V_80 * V_81 )
{
}
static int F_51 ( T_2 * * V_60 ,
struct V_53 * * V_61 )
{
* V_60 = NULL ;
return 1 ;
}
static void F_63 ( void )
{
F_64 ( V_83 , & V_84 ) ;
}
void F_65 ( void )
{
F_57 ( NULL ) ;
}
static int F_66 ( struct V_6 * V_36 ,
struct V_85 * V_86 )
{
return ! F_67 ( & V_36 -> V_30 ,
( F_1 ( V_86 -> V_87 ) ) -> V_30 ) ;
}
static void F_68 ( struct V_6 * V_36 ,
struct V_85 * V_86 )
{
F_69 ( V_36 , ( ( F_1 ( V_86 -> V_87 ) ) -> V_30 ) ) ;
}
static void F_70 ( struct V_1 * V_9 , struct V_88 * V_89 )
{
struct V_85 V_86 ;
V_86 . V_87 = V_9 -> V_5 . V_2 ;
V_86 . V_90 = F_66 ;
V_86 . V_91 = F_68 ;
V_86 . V_89 = V_89 ;
F_71 ( & V_86 ) ;
}
static int F_72 ( struct V_1 * V_9 , struct V_1 * V_92 ,
const char * V_93 )
{
struct V_88 V_89 ;
int V_94 ;
int V_95 ;
if ( V_9 == & V_47 )
return - V_48 ;
if ( ! * V_93 ) {
F_55 ( V_92 -> V_30 ) ;
} else {
V_94 = F_73 ( V_93 , V_92 -> V_30 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( ! F_29 ( V_92 -> V_30 , V_96 ) )
return - V_49 ;
}
V_94 = F_37 ( V_9 , V_92 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( F_67 ( V_9 -> V_30 , V_92 -> V_30 ) )
return 0 ;
V_94 = F_74 ( & V_89 , V_97 , V_42 , NULL ) ;
if ( V_94 )
return V_94 ;
V_95 = F_11 ( V_92 ) ;
F_75 ( & V_98 ) ;
F_22 ( V_9 -> V_30 , V_92 -> V_30 ) ;
F_76 ( & V_98 ) ;
F_70 ( V_9 , & V_89 ) ;
F_77 ( & V_89 ) ;
if ( V_95 )
F_63 () ;
return 0 ;
}
static void F_78 ( struct V_99 * V_100 , const T_1 * V_101 ,
const T_1 * V_102 )
{
struct V_6 * V_36 = V_103 ;
V_36 -> V_33 = * V_102 ;
F_79 ( V_100 , V_101 , V_102 , V_104 ) ;
F_24 ( F_4 ( V_36 ) , & V_36 -> V_33 ) ;
}
static void F_80 ( struct V_6 * V_36 ,
T_1 * V_105 )
{
bool V_106 ;
if ( F_81 ( F_82 ( V_107 ) ) )
return;
if ( V_103 -> V_11 & V_108 )
return;
F_83 ( V_36 ) ;
V_106 = F_6 ( V_36 ) ||
! F_25 ( * V_105 , V_36 -> V_33 ) ;
if ( V_106 )
F_84 ( & V_36 -> V_109 ) ;
F_85 ( V_36 -> V_33 , V_36 -> V_33 , * V_105 ) ;
F_86 ( V_36 , V_105 , V_110 ) ;
F_86 ( V_36 , V_105 , V_111 ) ;
V_36 -> V_33 = * V_105 ;
if ( V_106 )
F_87 ( & V_36 -> V_109 ) ;
F_88 ( V_36 ) ;
}
static void F_89 ( struct V_6 * V_39 ,
struct V_85 * V_86 )
{
struct V_99 * V_100 ;
struct V_1 * V_9 ;
int V_112 ;
const T_1 * V_113 = V_86 -> V_22 ;
static T_1 V_105 ;
V_9 = F_1 ( V_86 -> V_87 ) ;
F_24 ( V_9 , & V_105 ) ;
F_80 ( V_39 , & V_105 ) ;
V_100 = F_90 ( V_39 ) ;
if ( ! V_100 )
return;
V_112 = F_12 ( V_9 ) ;
F_91 ( V_100 , & V_9 -> V_33 ) ;
if ( V_112 )
F_78 ( V_100 , V_113 , & V_9 -> V_33 ) ;
F_92 ( V_100 ) ;
}
static void F_93 ( struct V_1 * V_9 , const T_1 * V_113 ,
struct V_88 * V_89 )
{
struct V_85 V_86 ;
V_114 = V_9 ;
V_86 . V_87 = V_9 -> V_5 . V_2 ;
V_86 . V_90 = NULL ;
V_86 . V_91 = F_89 ;
V_86 . V_89 = V_89 ;
V_86 . V_22 = ( T_1 * ) V_113 ;
F_71 ( & V_86 ) ;
V_114 = NULL ;
}
static int F_94 ( struct V_1 * V_9 , struct V_1 * V_92 ,
const char * V_93 )
{
F_95 ( T_1 , V_113 , V_42 ) ;
int V_94 ;
struct V_88 V_89 ;
if ( ! V_113 )
return - V_115 ;
if ( V_9 == & V_47 ) {
V_94 = - V_48 ;
goto V_70;
}
if ( ! * V_93 ) {
F_96 ( V_92 -> V_33 ) ;
} else {
V_94 = F_97 ( V_93 , V_92 -> V_33 ) ;
if ( V_94 < 0 )
goto V_70;
if ( ! F_30 ( V_92 -> V_33 ,
V_34 [ V_35 ] ) ) {
V_94 = - V_49 ;
goto V_70;
}
}
* V_113 = V_9 -> V_33 ;
if ( F_98 ( * V_113 , V_92 -> V_33 ) ) {
V_94 = 0 ;
goto V_70;
}
V_94 = F_37 ( V_9 , V_92 ) ;
if ( V_94 < 0 )
goto V_70;
V_94 = F_74 ( & V_89 , V_97 , V_42 , NULL ) ;
if ( V_94 < 0 )
goto V_70;
F_75 ( & V_98 ) ;
V_9 -> V_33 = V_92 -> V_33 ;
F_76 ( & V_98 ) ;
F_93 ( V_9 , V_113 , & V_89 ) ;
F_77 ( & V_89 ) ;
V_70:
F_99 ( V_113 ) ;
return V_94 ;
}
int F_100 ( void )
{
return F_4 ( V_103 ) == V_114 ;
}
static int F_101 ( struct V_1 * V_9 , T_3 V_116 )
{
#ifdef F_102
if ( V_116 < - 1 || V_116 >= V_117 )
return - V_49 ;
#endif
if ( V_116 != V_9 -> V_55 ) {
V_9 -> V_55 = V_116 ;
if ( ! F_40 ( V_9 -> V_30 ) &&
F_11 ( V_9 ) )
F_63 () ;
}
return 0 ;
}
static void F_103 ( struct V_6 * V_36 ,
struct V_85 * V_86 )
{
F_27 ( F_1 ( V_86 -> V_87 ) , V_36 ) ;
}
static void F_104 ( struct V_1 * V_9 , struct V_88 * V_89 )
{
struct V_85 V_86 ;
V_86 . V_87 = V_9 -> V_5 . V_2 ;
V_86 . V_90 = NULL ;
V_86 . V_91 = F_103 ;
V_86 . V_89 = V_89 ;
F_71 ( & V_86 ) ;
}
static int F_105 ( T_4 V_118 , struct V_1 * V_9 ,
int V_119 )
{
struct V_1 * V_92 ;
int V_120 ;
int V_121 ;
struct V_88 V_89 ;
int V_122 ;
V_92 = F_31 ( V_9 ) ;
if ( ! V_92 )
return - V_115 ;
if ( V_119 )
F_106 ( V_118 , & V_92 -> V_11 ) ;
else
F_107 ( V_118 , & V_92 -> V_11 ) ;
V_122 = F_37 ( V_9 , V_92 ) ;
if ( V_122 < 0 )
goto V_123;
V_122 = F_74 ( & V_89 , V_97 , V_42 , NULL ) ;
if ( V_122 < 0 )
goto V_123;
V_120 = ( F_11 ( V_9 ) !=
F_11 ( V_92 ) ) ;
V_121 = ( ( F_14 ( V_9 ) != F_14 ( V_92 ) )
|| ( F_13 ( V_9 ) != F_13 ( V_92 ) ) ) ;
F_75 ( & V_98 ) ;
V_9 -> V_11 = V_92 -> V_11 ;
F_76 ( & V_98 ) ;
if ( ! F_40 ( V_92 -> V_30 ) && V_120 )
F_63 () ;
if ( V_121 )
F_104 ( V_9 , & V_89 ) ;
F_77 ( & V_89 ) ;
V_123:
F_35 ( V_92 ) ;
return V_122 ;
}
static void F_108 ( struct V_124 * V_125 )
{
V_125 -> V_126 = 0 ;
V_125 -> V_116 = 0 ;
V_125 -> time = 0 ;
F_109 ( & V_125 -> V_127 ) ;
}
static void F_110 ( struct V_124 * V_125 )
{
T_5 V_128 = F_111 () ;
T_5 V_129 = V_128 - V_125 -> time ;
if ( V_129 == 0 )
return;
V_129 = F_112 ( V_130 , V_129 ) ;
while ( V_129 -- > 0 )
V_125 -> V_116 = ( V_131 * V_125 -> V_116 ) / V_132 ;
V_125 -> time = V_128 ;
V_125 -> V_116 += ( ( V_132 - V_131 ) * V_125 -> V_126 ) / V_132 ;
V_125 -> V_126 = 0 ;
}
static void F_113 ( struct V_124 * V_125 )
{
F_114 ( & V_125 -> V_127 ) ;
F_110 ( V_125 ) ;
V_125 -> V_126 = F_112 ( V_133 , V_125 -> V_126 + V_132 ) ;
F_115 ( & V_125 -> V_127 ) ;
}
static int F_116 ( struct V_124 * V_125 )
{
int V_116 ;
F_114 ( & V_125 -> V_127 ) ;
F_110 ( V_125 ) ;
V_116 = V_125 -> V_116 ;
F_115 ( & V_125 -> V_127 ) ;
return V_116 ;
}
static int F_117 ( struct V_2 * V_134 , struct V_135 * V_136 )
{
struct V_1 * V_9 = F_1 ( V_134 ) ;
struct V_6 * V_7 ;
int V_24 ;
if ( F_40 ( V_9 -> V_30 ) || F_41 ( V_9 -> V_33 ) )
return - V_50 ;
F_118 (task, cgrp, tset) {
if ( V_7 -> V_11 & V_137 )
return - V_49 ;
if ( ( V_24 = F_119 ( V_7 ) ) )
return V_24 ;
}
if ( V_9 == & V_47 )
F_22 ( V_138 , V_139 ) ;
else
F_19 ( V_9 , V_138 ) ;
F_24 ( V_9 , & V_140 ) ;
return 0 ;
}
static void F_120 ( struct V_2 * V_134 , struct V_135 * V_136 )
{
struct V_99 * V_100 ;
struct V_6 * V_7 ;
struct V_6 * V_141 = F_121 ( V_136 ) ;
struct V_2 * V_142 = F_122 ( V_136 ) ;
struct V_1 * V_9 = F_1 ( V_134 ) ;
struct V_1 * V_143 = F_1 ( V_142 ) ;
F_118 (task, cgrp, tset) {
F_123 ( F_69 ( V_7 , V_138 ) ) ;
F_80 ( V_7 , & V_140 ) ;
F_27 ( V_9 , V_7 ) ;
}
V_144 = V_143 -> V_33 ;
V_140 = V_9 -> V_33 ;
V_100 = F_90 ( V_141 ) ;
if ( V_100 ) {
F_91 ( V_100 , & V_140 ) ;
if ( F_12 ( V_9 ) )
F_78 ( V_100 , & V_144 ,
& V_140 ) ;
F_92 ( V_100 ) ;
}
}
static int F_124 ( struct V_2 * V_134 , struct V_145 * V_146 , T_6 V_116 )
{
int V_94 = 0 ;
struct V_1 * V_9 = F_1 ( V_134 ) ;
T_7 type = V_146 -> V_147 ;
if ( ! F_125 ( V_134 ) )
return - V_25 ;
switch ( type ) {
case V_148 :
V_94 = F_105 ( V_10 , V_9 , V_116 ) ;
break;
case V_149 :
V_94 = F_105 ( V_12 , V_9 , V_116 ) ;
break;
case V_150 :
V_94 = F_105 ( V_13 , V_9 , V_116 ) ;
break;
case V_151 :
V_94 = F_105 ( V_14 , V_9 , V_116 ) ;
break;
case V_152 :
V_94 = F_105 ( V_15 , V_9 , V_116 ) ;
break;
case V_153 :
V_154 = ! ! V_116 ;
break;
case V_155 :
V_94 = - V_48 ;
break;
case V_156 :
V_94 = F_105 ( V_16 , V_9 , V_116 ) ;
break;
case V_157 :
V_94 = F_105 ( V_17 , V_9 , V_116 ) ;
break;
default:
V_94 = - V_49 ;
break;
}
F_60 () ;
return V_94 ;
}
static int F_126 ( struct V_2 * V_134 , struct V_145 * V_146 , T_3 V_116 )
{
int V_94 = 0 ;
struct V_1 * V_9 = F_1 ( V_134 ) ;
T_7 type = V_146 -> V_147 ;
if ( ! F_125 ( V_134 ) )
return - V_25 ;
switch ( type ) {
case V_158 :
V_94 = F_101 ( V_9 , V_116 ) ;
break;
default:
V_94 = - V_49 ;
break;
}
F_60 () ;
return V_94 ;
}
static int F_127 ( struct V_2 * V_134 , struct V_145 * V_146 ,
const char * V_93 )
{
int V_94 = 0 ;
struct V_1 * V_9 = F_1 ( V_134 ) ;
struct V_1 * V_92 ;
if ( ! F_125 ( V_134 ) )
return - V_25 ;
V_92 = F_31 ( V_9 ) ;
if ( ! V_92 ) {
V_94 = - V_115 ;
goto V_123;
}
switch ( V_146 -> V_147 ) {
case V_159 :
V_94 = F_72 ( V_9 , V_92 , V_93 ) ;
break;
case V_160 :
V_94 = F_94 ( V_9 , V_92 , V_93 ) ;
break;
default:
V_94 = - V_49 ;
break;
}
F_35 ( V_92 ) ;
V_123:
F_60 () ;
return V_94 ;
}
static T_8 F_128 ( char * V_161 , struct V_1 * V_9 )
{
T_8 V_162 ;
F_75 ( & V_98 ) ;
V_162 = F_129 ( V_161 , V_97 , V_9 -> V_30 ) ;
F_76 ( & V_98 ) ;
return V_162 ;
}
static T_8 F_130 ( char * V_161 , struct V_1 * V_9 )
{
T_8 V_162 ;
F_75 ( & V_98 ) ;
V_162 = F_131 ( V_161 , V_97 , V_9 -> V_33 ) ;
F_76 ( & V_98 ) ;
return V_162 ;
}
static T_9 F_132 ( struct V_2 * V_3 ,
struct V_145 * V_146 ,
struct V_163 * V_163 ,
char T_10 * V_93 ,
T_8 V_164 , T_11 * V_165 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_7 type = V_146 -> V_147 ;
char * V_161 ;
T_9 V_94 = 0 ;
char * V_166 ;
if ( ! ( V_161 = ( char * ) F_133 ( V_167 ) ) )
return - V_115 ;
V_166 = V_161 ;
switch ( type ) {
case V_159 :
V_166 += F_128 ( V_166 , V_9 ) ;
break;
case V_160 :
V_166 += F_130 ( V_166 , V_9 ) ;
break;
default:
V_94 = - V_49 ;
goto V_123;
}
* V_166 ++ = '\n' ;
V_94 = F_134 ( V_93 , V_164 , V_165 , V_161 , V_166 - V_161 ) ;
V_123:
F_135 ( ( unsigned long ) V_161 ) ;
return V_94 ;
}
static T_6 F_136 ( struct V_2 * V_3 , struct V_145 * V_146 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_7 type = V_146 -> V_147 ;
switch ( type ) {
case V_148 :
return F_7 ( V_9 ) ;
case V_149 :
return F_9 ( V_9 ) ;
case V_150 :
return F_10 ( V_9 ) ;
case V_151 :
return F_11 ( V_9 ) ;
case V_152 :
return F_12 ( V_9 ) ;
case V_153 :
return V_154 ;
case V_155 :
return F_116 ( & V_9 -> V_124 ) ;
case V_156 :
return F_13 ( V_9 ) ;
case V_157 :
return F_14 ( V_9 ) ;
default:
F_137 () ;
}
return 0 ;
}
static T_3 F_138 ( struct V_2 * V_3 , struct V_145 * V_146 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_7 type = V_146 -> V_147 ;
switch ( type ) {
case V_158 :
return V_9 -> V_55 ;
default:
F_137 () ;
}
return 0 ;
}
static void F_139 ( struct V_2 * V_2 )
{
struct V_2 * V_32 , * V_58 ;
struct V_1 * V_9 , * V_168 ;
V_32 = V_2 -> V_32 ;
F_38 (child, &parent->children, sibling) {
V_9 = F_1 ( V_58 ) ;
if ( F_9 ( V_9 ) || F_7 ( V_9 ) )
return;
}
V_9 = F_1 ( V_2 ) ;
V_168 = F_1 ( V_32 ) ;
F_75 ( & V_98 ) ;
V_9 -> V_33 = V_168 -> V_33 ;
F_22 ( V_9 -> V_30 , V_168 -> V_30 ) ;
F_76 ( & V_98 ) ;
return;
}
static struct F_3 * F_140 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_1 * V_32 ;
if ( ! V_3 -> V_32 ) {
return & V_47 . V_5 ;
}
V_32 = F_1 ( V_3 -> V_32 ) ;
V_9 = F_53 ( sizeof( * V_9 ) , V_42 ) ;
if ( ! V_9 )
return F_17 ( - V_115 ) ;
if ( ! F_33 ( & V_9 -> V_30 , V_42 ) ) {
F_34 ( V_9 ) ;
return F_17 ( - V_115 ) ;
}
V_9 -> V_11 = 0 ;
if ( F_13 ( V_32 ) )
F_106 ( V_16 , & V_9 -> V_11 ) ;
if ( F_14 ( V_32 ) )
F_106 ( V_17 , & V_9 -> V_11 ) ;
F_106 ( V_14 , & V_9 -> V_11 ) ;
F_55 ( V_9 -> V_30 ) ;
F_96 ( V_9 -> V_33 ) ;
F_108 ( & V_9 -> V_124 ) ;
V_9 -> V_55 = - 1 ;
V_9 -> V_32 = V_32 ;
V_72 ++ ;
return & V_9 -> V_5 ;
}
static void F_141 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( F_11 ( V_9 ) )
F_105 ( V_14 , V_9 , 0 ) ;
V_72 -- ;
F_36 ( V_9 -> V_30 ) ;
F_34 ( V_9 ) ;
}
int T_12 F_142 ( void )
{
int V_122 = 0 ;
if ( ! F_33 ( & V_47 . V_30 , V_42 ) )
F_137 () ;
F_143 ( V_47 . V_30 ) ;
F_144 ( V_47 . V_33 ) ;
F_108 ( & V_47 . V_124 ) ;
F_106 ( V_14 , & V_47 . V_11 ) ;
V_47 . V_55 = - 1 ;
V_122 = F_145 ( & V_169 ) ;
if ( V_122 < 0 )
return V_122 ;
if ( ! F_33 ( & V_138 , V_42 ) )
F_137 () ;
V_72 = 1 ;
return 0 ;
}
static void F_146 ( struct V_6 * V_36 ,
struct V_85 * V_86 )
{
struct V_2 * V_170 = V_86 -> V_22 ;
F_147 ( V_170 , V_36 ) ;
}
static void F_148 ( struct V_1 * V_101 , struct V_1 * V_102 )
{
struct V_85 V_86 ;
V_86 . V_87 = V_101 -> V_5 . V_2 ;
V_86 . V_90 = NULL ;
V_86 . V_91 = F_146 ;
V_86 . V_89 = NULL ;
V_86 . V_22 = V_102 -> V_5 . V_2 ;
if ( F_71 ( & V_86 ) )
F_54 ( V_171 L_7
L_8 ) ;
}
static void F_149 ( struct V_1 * V_9 )
{
struct V_1 * V_32 ;
if ( F_47 ( & V_9 -> V_5 . V_2 -> V_172 ) )
return;
V_32 = V_9 -> V_32 ;
while ( F_40 ( V_32 -> V_30 ) ||
F_41 ( V_32 -> V_33 ) )
V_32 = V_32 -> V_32 ;
F_148 ( V_9 , V_32 ) ;
}
static struct V_1 * F_150 ( struct V_173 * V_174 )
{
struct V_1 * V_57 ;
struct V_1 * V_58 ;
struct V_2 * V_3 ;
if ( F_47 ( V_174 ) )
return NULL ;
V_57 = F_48 ( V_174 , struct V_1 , V_56 ) ;
F_49 ( V_174 -> V_59 ) ;
F_38 (cont, &cp->css.cgroup->children, sibling) {
V_58 = F_1 ( V_3 ) ;
F_50 ( & V_58 -> V_56 , V_174 ) ;
}
return V_57 ;
}
static void
F_151 ( struct V_1 * V_175 , enum V_176 V_177 )
{
F_45 ( V_174 ) ;
struct V_1 * V_57 ;
static T_1 V_178 ;
F_50 ( (struct V_173 * ) & V_175 -> V_56 , & V_174 ) ;
switch ( V_177 ) {
case V_179 :
while ( ( V_57 = F_150 ( & V_174 ) ) != NULL ) {
if ( F_29 ( V_57 -> V_30 , V_96 ) )
continue;
F_75 ( & V_98 ) ;
F_21 ( V_57 -> V_30 , V_57 -> V_30 ,
V_96 ) ;
F_76 ( & V_98 ) ;
if ( F_40 ( V_57 -> V_30 ) )
F_149 ( V_57 ) ;
else
F_70 ( V_57 , NULL ) ;
}
break;
case V_180 :
while ( ( V_57 = F_150 ( & V_174 ) ) != NULL ) {
if ( F_30 ( V_57 -> V_33 ,
V_34 [ V_35 ] ) )
continue;
V_178 = V_57 -> V_33 ;
F_75 ( & V_98 ) ;
F_26 ( V_57 -> V_33 , V_57 -> V_33 ,
V_34 [ V_35 ] ) ;
F_76 ( & V_98 ) ;
if ( F_41 ( V_57 -> V_33 ) )
F_149 ( V_57 ) ;
else
F_93 ( V_57 , & V_178 , NULL ) ;
}
}
}
void F_152 ( bool V_181 )
{
struct V_53 * V_82 ;
T_2 * V_67 ;
int V_68 ;
F_59 () ;
F_75 ( & V_98 ) ;
F_22 ( V_47 . V_30 , V_96 ) ;
F_76 ( & V_98 ) ;
if ( ! V_181 )
F_151 ( & V_47 , V_179 ) ;
V_68 = F_51 ( & V_67 , & V_82 ) ;
F_60 () ;
F_61 ( V_68 , V_67 , V_82 ) ;
}
static int F_153 ( struct V_182 * V_183 ,
unsigned long V_184 , void * V_185 )
{
static T_1 V_178 ;
F_59 () ;
switch ( V_184 ) {
case V_186 :
V_178 = V_47 . V_33 ;
F_75 ( & V_98 ) ;
V_47 . V_33 = V_34 [ V_35 ] ;
F_76 ( & V_98 ) ;
F_93 ( & V_47 , & V_178 , NULL ) ;
break;
case V_187 :
F_151 ( & V_47 , V_180 ) ;
break;
default:
break;
}
F_60 () ;
return V_188 ;
}
void T_12 F_154 ( void )
{
F_22 ( V_47 . V_30 , V_96 ) ;
V_47 . V_33 = V_34 [ V_35 ] ;
F_155 ( F_153 , 10 ) ;
V_83 = F_156 ( L_9 ) ;
F_23 ( ! V_83 ) ;
}
void F_157 ( struct V_6 * V_36 , struct V_28 * V_29 )
{
F_75 ( & V_98 ) ;
F_83 ( V_36 ) ;
F_19 ( F_4 ( V_36 ) , V_29 ) ;
F_88 ( V_36 ) ;
F_76 ( & V_98 ) ;
}
void F_158 ( struct V_6 * V_36 )
{
const struct V_1 * V_9 ;
F_159 () ;
V_9 = F_4 ( V_36 ) ;
if ( V_9 )
F_160 ( V_36 , V_9 -> V_30 ) ;
F_161 () ;
}
void F_162 ( void )
{
F_144 ( V_103 -> V_33 ) ;
}
T_1 F_163 ( struct V_6 * V_36 )
{
T_1 V_189 ;
F_75 ( & V_98 ) ;
F_83 ( V_36 ) ;
F_24 ( F_4 ( V_36 ) , & V_189 ) ;
F_88 ( V_36 ) ;
F_76 ( & V_98 ) ;
return V_189 ;
}
int F_164 ( T_1 * V_190 )
{
return F_25 ( * V_190 , V_103 -> V_33 ) ;
}
static const struct V_1 * F_165 ( const struct V_1 * V_9 )
{
while ( ! ( F_9 ( V_9 ) || F_10 ( V_9 ) ) && V_9 -> V_32 )
V_9 = V_9 -> V_32 ;
return V_9 ;
}
int F_166 ( int V_191 , T_13 V_192 )
{
const struct V_1 * V_9 ;
int V_193 ;
if ( F_167 () || ( V_192 & V_194 ) )
return 1 ;
F_168 ( ! ( V_192 & V_195 ) ) ;
if ( F_169 ( V_191 , V_103 -> V_33 ) )
return 1 ;
if ( F_81 ( F_82 ( V_107 ) ) )
return 1 ;
if ( V_192 & V_195 )
return 0 ;
if ( V_103 -> V_11 & V_108 )
return 1 ;
F_75 ( & V_98 ) ;
F_83 ( V_103 ) ;
V_9 = F_165 ( F_4 ( V_103 ) ) ;
F_88 ( V_103 ) ;
V_193 = F_169 ( V_191 , V_9 -> V_33 ) ;
F_76 ( & V_98 ) ;
return V_193 ;
}
int F_170 ( int V_191 , T_13 V_192 )
{
if ( F_167 () || ( V_192 & V_194 ) )
return 1 ;
if ( F_169 ( V_191 , V_103 -> V_33 ) )
return 1 ;
if ( F_81 ( F_82 ( V_107 ) ) )
return 1 ;
return 0 ;
}
void F_171 ( void )
{
F_76 ( & V_98 ) ;
}
static int F_172 ( int * V_196 )
{
int V_191 ;
V_191 = F_173 ( * V_196 , V_103 -> V_33 ) ;
if ( V_191 == V_197 )
V_191 = F_174 ( V_103 -> V_33 ) ;
* V_196 = V_191 ;
return V_191 ;
}
int F_175 ( void )
{
if ( V_103 -> V_198 == V_199 )
V_103 -> V_198 =
F_176 ( & V_103 -> V_33 ) ;
return F_172 ( & V_103 -> V_198 ) ;
}
int F_177 ( void )
{
if ( V_103 -> V_200 == V_199 )
V_103 -> V_200 =
F_176 ( & V_103 -> V_33 ) ;
return F_172 ( & V_103 -> V_200 ) ;
}
int F_178 ( const struct V_6 * V_201 ,
const struct V_6 * V_202 )
{
return F_25 ( V_201 -> V_33 , V_202 -> V_33 ) ;
}
void F_179 ( struct V_6 * V_36 )
{
struct V_18 * V_18 ;
V_18 = F_4 ( V_36 ) -> V_5 . V_2 -> V_18 ;
F_114 ( & V_203 ) ;
snprintf ( V_204 , V_205 ,
V_18 ? ( const char * ) V_18 -> V_206 . V_207 : L_10 ) ;
F_131 ( V_208 , V_209 ,
V_36 -> V_33 ) ;
F_54 ( V_210 L_11 ,
V_36 -> V_211 , V_204 , V_208 ) ;
F_115 ( & V_203 ) ;
}
void F_180 ( void )
{
F_83 ( V_103 ) ;
F_113 ( & F_4 ( V_103 ) -> V_124 ) ;
F_88 ( V_103 ) ;
}
static int F_181 ( struct V_212 * V_213 , void * V_214 )
{
struct V_215 * V_215 ;
struct V_6 * V_36 ;
char * V_93 ;
struct F_3 * V_5 ;
int V_94 ;
V_94 = - V_115 ;
V_93 = F_53 ( V_97 , V_42 ) ;
if ( ! V_93 )
goto V_123;
V_94 = - V_216 ;
V_215 = V_213 -> V_147 ;
V_36 = F_182 ( V_215 , V_217 ) ;
if ( ! V_36 )
goto V_218;
V_94 = - V_49 ;
F_59 () ;
V_5 = F_5 ( V_36 , V_4 ) ;
V_94 = F_183 ( V_5 -> V_2 , V_93 , V_97 ) ;
if ( V_94 < 0 )
goto V_219;
F_184 ( V_213 , V_93 ) ;
F_185 ( V_213 , '\n' ) ;
V_219:
F_60 () ;
F_186 ( V_36 ) ;
V_218:
F_34 ( V_93 ) ;
V_123:
return V_94 ;
}
static int F_187 ( struct V_220 * V_220 , struct V_163 * V_163 )
{
struct V_215 * V_215 = F_188 ( V_220 ) -> V_215 ;
return F_189 ( V_163 , F_181 , V_215 ) ;
}
void F_190 ( struct V_212 * V_213 , struct V_6 * V_7 )
{
F_191 ( V_213 , L_12 ) ;
F_192 ( V_213 , & V_7 -> V_33 ) ;
F_191 ( V_213 , L_13 ) ;
F_191 ( V_213 , L_14 ) ;
F_193 ( V_213 , & V_7 -> V_33 ) ;
F_191 ( V_213 , L_13 ) ;
}
