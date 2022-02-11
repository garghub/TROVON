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
V_107:
if ( F_81 ( F_82 ( V_108 ) ) )
return;
if ( V_103 -> V_11 & V_109 )
return;
F_83 ( V_36 ) ;
V_106 = F_6 ( V_36 ) ||
! F_25 ( * V_105 , V_36 -> V_33 ) ;
F_84 ( V_36 -> V_33 , V_36 -> V_33 , * V_105 ) ;
F_85 ( V_36 , V_105 , V_110 ) ;
F_86 () ;
while ( V_106 && F_87 ( V_36 -> V_111 ) ) {
F_88 ( V_36 ) ;
if ( ! F_89 ( V_36 ) )
F_90 () ;
goto V_107;
}
F_86 () ;
F_85 ( V_36 , V_105 , V_112 ) ;
V_36 -> V_33 = * V_105 ;
F_88 ( V_36 ) ;
}
static void F_91 ( struct V_6 * V_39 ,
struct V_85 * V_86 )
{
struct V_99 * V_100 ;
struct V_1 * V_9 ;
int V_113 ;
const T_1 * V_114 = V_86 -> V_22 ;
static T_1 V_105 ;
V_9 = F_1 ( V_86 -> V_87 ) ;
F_24 ( V_9 , & V_105 ) ;
F_80 ( V_39 , & V_105 ) ;
V_100 = F_92 ( V_39 ) ;
if ( ! V_100 )
return;
V_113 = F_12 ( V_9 ) ;
F_93 ( V_100 , & V_9 -> V_33 ) ;
if ( V_113 )
F_78 ( V_100 , V_114 , & V_9 -> V_33 ) ;
F_94 ( V_100 ) ;
}
static void F_95 ( struct V_1 * V_9 , const T_1 * V_114 ,
struct V_88 * V_89 )
{
struct V_85 V_86 ;
V_115 = V_9 ;
V_86 . V_87 = V_9 -> V_5 . V_2 ;
V_86 . V_90 = NULL ;
V_86 . V_91 = F_91 ;
V_86 . V_89 = V_89 ;
V_86 . V_22 = ( T_1 * ) V_114 ;
F_71 ( & V_86 ) ;
V_115 = NULL ;
}
static int F_96 ( struct V_1 * V_9 , struct V_1 * V_92 ,
const char * V_93 )
{
F_97 ( T_1 , V_114 , V_42 ) ;
int V_94 ;
struct V_88 V_89 ;
if ( ! V_114 )
return - V_116 ;
if ( V_9 == & V_47 ) {
V_94 = - V_48 ;
goto V_70;
}
if ( ! * V_93 ) {
F_98 ( V_92 -> V_33 ) ;
} else {
V_94 = F_99 ( V_93 , V_92 -> V_33 ) ;
if ( V_94 < 0 )
goto V_70;
if ( ! F_30 ( V_92 -> V_33 ,
V_34 [ V_35 ] ) ) {
V_94 = - V_49 ;
goto V_70;
}
}
* V_114 = V_9 -> V_33 ;
if ( F_100 ( * V_114 , V_92 -> V_33 ) ) {
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
F_95 ( V_9 , V_114 , & V_89 ) ;
F_77 ( & V_89 ) ;
V_70:
F_101 ( V_114 ) ;
return V_94 ;
}
int F_102 ( void )
{
return F_4 ( V_103 ) == V_115 ;
}
static int F_103 ( struct V_1 * V_9 , T_3 V_117 )
{
#ifdef F_104
if ( V_117 < - 1 || V_117 >= V_118 )
return - V_49 ;
#endif
if ( V_117 != V_9 -> V_55 ) {
V_9 -> V_55 = V_117 ;
if ( ! F_40 ( V_9 -> V_30 ) &&
F_11 ( V_9 ) )
F_63 () ;
}
return 0 ;
}
static void F_105 ( struct V_6 * V_36 ,
struct V_85 * V_86 )
{
F_27 ( F_1 ( V_86 -> V_87 ) , V_36 ) ;
}
static void F_106 ( struct V_1 * V_9 , struct V_88 * V_89 )
{
struct V_85 V_86 ;
V_86 . V_87 = V_9 -> V_5 . V_2 ;
V_86 . V_90 = NULL ;
V_86 . V_91 = F_105 ;
V_86 . V_89 = V_89 ;
F_71 ( & V_86 ) ;
}
static int F_107 ( T_4 V_119 , struct V_1 * V_9 ,
int V_120 )
{
struct V_1 * V_92 ;
int V_121 ;
int V_122 ;
struct V_88 V_89 ;
int V_123 ;
V_92 = F_31 ( V_9 ) ;
if ( ! V_92 )
return - V_116 ;
if ( V_120 )
F_108 ( V_119 , & V_92 -> V_11 ) ;
else
F_109 ( V_119 , & V_92 -> V_11 ) ;
V_123 = F_37 ( V_9 , V_92 ) ;
if ( V_123 < 0 )
goto V_124;
V_123 = F_74 ( & V_89 , V_97 , V_42 , NULL ) ;
if ( V_123 < 0 )
goto V_124;
V_121 = ( F_11 ( V_9 ) !=
F_11 ( V_92 ) ) ;
V_122 = ( ( F_14 ( V_9 ) != F_14 ( V_92 ) )
|| ( F_13 ( V_9 ) != F_13 ( V_92 ) ) ) ;
F_75 ( & V_98 ) ;
V_9 -> V_11 = V_92 -> V_11 ;
F_76 ( & V_98 ) ;
if ( ! F_40 ( V_92 -> V_30 ) && V_121 )
F_63 () ;
if ( V_122 )
F_106 ( V_9 , & V_89 ) ;
F_77 ( & V_89 ) ;
V_124:
F_35 ( V_92 ) ;
return V_123 ;
}
static void F_110 ( struct V_125 * V_126 )
{
V_126 -> V_127 = 0 ;
V_126 -> V_117 = 0 ;
V_126 -> time = 0 ;
F_111 ( & V_126 -> V_128 ) ;
}
static void F_112 ( struct V_125 * V_126 )
{
T_5 V_129 = F_113 () ;
T_5 V_130 = V_129 - V_126 -> time ;
if ( V_130 == 0 )
return;
V_130 = F_114 ( V_131 , V_130 ) ;
while ( V_130 -- > 0 )
V_126 -> V_117 = ( V_132 * V_126 -> V_117 ) / V_133 ;
V_126 -> time = V_129 ;
V_126 -> V_117 += ( ( V_133 - V_132 ) * V_126 -> V_127 ) / V_133 ;
V_126 -> V_127 = 0 ;
}
static void F_115 ( struct V_125 * V_126 )
{
F_116 ( & V_126 -> V_128 ) ;
F_112 ( V_126 ) ;
V_126 -> V_127 = F_114 ( V_134 , V_126 -> V_127 + V_133 ) ;
F_117 ( & V_126 -> V_128 ) ;
}
static int F_118 ( struct V_125 * V_126 )
{
int V_117 ;
F_116 ( & V_126 -> V_128 ) ;
F_112 ( V_126 ) ;
V_117 = V_126 -> V_117 ;
F_117 ( & V_126 -> V_128 ) ;
return V_117 ;
}
static int F_119 ( struct V_135 * V_136 , struct V_2 * V_137 ,
struct V_138 * V_139 )
{
struct V_1 * V_9 = F_1 ( V_137 ) ;
struct V_6 * V_7 ;
int V_24 ;
if ( F_40 ( V_9 -> V_30 ) || F_41 ( V_9 -> V_33 ) )
return - V_50 ;
F_120 (task, cgrp, tset) {
if ( V_7 -> V_11 & V_140 )
return - V_49 ;
if ( ( V_24 = F_121 ( V_7 ) ) )
return V_24 ;
}
if ( V_9 == & V_47 )
F_22 ( V_141 , V_142 ) ;
else
F_19 ( V_9 , V_141 ) ;
F_24 ( V_9 , & V_143 ) ;
return 0 ;
}
static void F_122 ( struct V_135 * V_136 , struct V_2 * V_137 ,
struct V_138 * V_139 )
{
struct V_99 * V_100 ;
struct V_6 * V_7 ;
struct V_6 * V_144 = F_123 ( V_139 ) ;
struct V_2 * V_145 = F_124 ( V_139 ) ;
struct V_1 * V_9 = F_1 ( V_137 ) ;
struct V_1 * V_146 = F_1 ( V_145 ) ;
F_120 (task, cgrp, tset) {
F_125 ( F_69 ( V_7 , V_141 ) ) ;
F_80 ( V_7 , & V_143 ) ;
F_27 ( V_9 , V_7 ) ;
}
V_147 = V_146 -> V_33 ;
V_143 = V_9 -> V_33 ;
V_100 = F_92 ( V_144 ) ;
if ( V_100 ) {
F_93 ( V_100 , & V_143 ) ;
if ( F_12 ( V_9 ) )
F_78 ( V_100 , & V_147 ,
& V_143 ) ;
F_94 ( V_100 ) ;
}
}
static int F_126 ( struct V_2 * V_137 , struct V_148 * V_149 , T_6 V_117 )
{
int V_94 = 0 ;
struct V_1 * V_9 = F_1 ( V_137 ) ;
T_7 type = V_149 -> V_150 ;
if ( ! F_127 ( V_137 ) )
return - V_25 ;
switch ( type ) {
case V_151 :
V_94 = F_107 ( V_10 , V_9 , V_117 ) ;
break;
case V_152 :
V_94 = F_107 ( V_12 , V_9 , V_117 ) ;
break;
case V_153 :
V_94 = F_107 ( V_13 , V_9 , V_117 ) ;
break;
case V_154 :
V_94 = F_107 ( V_14 , V_9 , V_117 ) ;
break;
case V_155 :
V_94 = F_107 ( V_15 , V_9 , V_117 ) ;
break;
case V_156 :
V_157 = ! ! V_117 ;
break;
case V_158 :
V_94 = - V_48 ;
break;
case V_159 :
V_94 = F_107 ( V_16 , V_9 , V_117 ) ;
break;
case V_160 :
V_94 = F_107 ( V_17 , V_9 , V_117 ) ;
break;
default:
V_94 = - V_49 ;
break;
}
F_60 () ;
return V_94 ;
}
static int F_128 ( struct V_2 * V_137 , struct V_148 * V_149 , T_3 V_117 )
{
int V_94 = 0 ;
struct V_1 * V_9 = F_1 ( V_137 ) ;
T_7 type = V_149 -> V_150 ;
if ( ! F_127 ( V_137 ) )
return - V_25 ;
switch ( type ) {
case V_161 :
V_94 = F_103 ( V_9 , V_117 ) ;
break;
default:
V_94 = - V_49 ;
break;
}
F_60 () ;
return V_94 ;
}
static int F_129 ( struct V_2 * V_137 , struct V_148 * V_149 ,
const char * V_93 )
{
int V_94 = 0 ;
struct V_1 * V_9 = F_1 ( V_137 ) ;
struct V_1 * V_92 ;
if ( ! F_127 ( V_137 ) )
return - V_25 ;
V_92 = F_31 ( V_9 ) ;
if ( ! V_92 ) {
V_94 = - V_116 ;
goto V_124;
}
switch ( V_149 -> V_150 ) {
case V_162 :
V_94 = F_72 ( V_9 , V_92 , V_93 ) ;
break;
case V_163 :
V_94 = F_96 ( V_9 , V_92 , V_93 ) ;
break;
default:
V_94 = - V_49 ;
break;
}
F_35 ( V_92 ) ;
V_124:
F_60 () ;
return V_94 ;
}
static T_8 F_130 ( char * V_164 , struct V_1 * V_9 )
{
T_8 V_165 ;
F_75 ( & V_98 ) ;
V_165 = F_131 ( V_164 , V_97 , V_9 -> V_30 ) ;
F_76 ( & V_98 ) ;
return V_165 ;
}
static T_8 F_132 ( char * V_164 , struct V_1 * V_9 )
{
T_8 V_165 ;
F_75 ( & V_98 ) ;
V_165 = F_133 ( V_164 , V_97 , V_9 -> V_33 ) ;
F_76 ( & V_98 ) ;
return V_165 ;
}
static T_9 F_134 ( struct V_2 * V_3 ,
struct V_148 * V_149 ,
struct V_166 * V_166 ,
char T_10 * V_93 ,
T_8 V_167 , T_11 * V_168 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_7 type = V_149 -> V_150 ;
char * V_164 ;
T_9 V_94 = 0 ;
char * V_169 ;
if ( ! ( V_164 = ( char * ) F_135 ( V_170 ) ) )
return - V_116 ;
V_169 = V_164 ;
switch ( type ) {
case V_162 :
V_169 += F_130 ( V_169 , V_9 ) ;
break;
case V_163 :
V_169 += F_132 ( V_169 , V_9 ) ;
break;
default:
V_94 = - V_49 ;
goto V_124;
}
* V_169 ++ = '\n' ;
V_94 = F_136 ( V_93 , V_167 , V_168 , V_164 , V_169 - V_164 ) ;
V_124:
F_137 ( ( unsigned long ) V_164 ) ;
return V_94 ;
}
static T_6 F_138 ( struct V_2 * V_3 , struct V_148 * V_149 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_7 type = V_149 -> V_150 ;
switch ( type ) {
case V_151 :
return F_7 ( V_9 ) ;
case V_152 :
return F_9 ( V_9 ) ;
case V_153 :
return F_10 ( V_9 ) ;
case V_154 :
return F_11 ( V_9 ) ;
case V_155 :
return F_12 ( V_9 ) ;
case V_156 :
return V_157 ;
case V_158 :
return F_118 ( & V_9 -> V_125 ) ;
case V_159 :
return F_13 ( V_9 ) ;
case V_160 :
return F_14 ( V_9 ) ;
default:
F_139 () ;
}
return 0 ;
}
static T_3 F_140 ( struct V_2 * V_3 , struct V_148 * V_149 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_7 type = V_149 -> V_150 ;
switch ( type ) {
case V_161 :
return V_9 -> V_55 ;
default:
F_139 () ;
}
return 0 ;
}
static int F_141 ( struct V_135 * V_136 , struct V_2 * V_3 )
{
int V_123 ;
V_123 = F_142 ( V_3 , V_136 , V_171 , F_143 ( V_171 ) ) ;
if ( V_123 )
return V_123 ;
if ( ! V_3 -> V_32 )
V_123 = F_144 ( V_3 , V_136 ,
& V_172 ) ;
return V_123 ;
}
static void F_145 ( struct V_135 * V_136 ,
struct V_2 * V_2 )
{
struct V_2 * V_32 , * V_58 ;
struct V_1 * V_9 , * V_173 ;
V_32 = V_2 -> V_32 ;
F_38 (child, &parent->children, sibling) {
V_9 = F_1 ( V_58 ) ;
if ( F_9 ( V_9 ) || F_7 ( V_9 ) )
return;
}
V_9 = F_1 ( V_2 ) ;
V_173 = F_1 ( V_32 ) ;
F_75 ( & V_98 ) ;
V_9 -> V_33 = V_173 -> V_33 ;
F_22 ( V_9 -> V_30 , V_173 -> V_30 ) ;
F_76 ( & V_98 ) ;
return;
}
static struct F_3 * F_146 (
struct V_135 * V_136 ,
struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_1 * V_32 ;
if ( ! V_3 -> V_32 ) {
return & V_47 . V_5 ;
}
V_32 = F_1 ( V_3 -> V_32 ) ;
V_9 = F_53 ( sizeof( * V_9 ) , V_42 ) ;
if ( ! V_9 )
return F_17 ( - V_116 ) ;
if ( ! F_33 ( & V_9 -> V_30 , V_42 ) ) {
F_34 ( V_9 ) ;
return F_17 ( - V_116 ) ;
}
V_9 -> V_11 = 0 ;
if ( F_13 ( V_32 ) )
F_108 ( V_16 , & V_9 -> V_11 ) ;
if ( F_14 ( V_32 ) )
F_108 ( V_17 , & V_9 -> V_11 ) ;
F_108 ( V_14 , & V_9 -> V_11 ) ;
F_55 ( V_9 -> V_30 ) ;
F_98 ( V_9 -> V_33 ) ;
F_110 ( & V_9 -> V_125 ) ;
V_9 -> V_55 = - 1 ;
V_9 -> V_32 = V_32 ;
V_72 ++ ;
return & V_9 -> V_5 ;
}
static void F_147 ( struct V_135 * V_136 , struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( F_11 ( V_9 ) )
F_107 ( V_14 , V_9 , 0 ) ;
V_72 -- ;
F_36 ( V_9 -> V_30 ) ;
F_34 ( V_9 ) ;
}
int T_12 F_148 ( void )
{
int V_123 = 0 ;
if ( ! F_33 ( & V_47 . V_30 , V_42 ) )
F_139 () ;
F_149 ( V_47 . V_30 ) ;
F_150 ( V_47 . V_33 ) ;
F_110 ( & V_47 . V_125 ) ;
F_108 ( V_14 , & V_47 . V_11 ) ;
V_47 . V_55 = - 1 ;
V_123 = F_151 ( & V_174 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( ! F_33 ( & V_141 , V_42 ) )
F_139 () ;
V_72 = 1 ;
return 0 ;
}
static void F_152 ( struct V_6 * V_36 ,
struct V_85 * V_86 )
{
struct V_2 * V_175 = V_86 -> V_22 ;
F_153 ( V_175 , V_36 ) ;
}
static void F_154 ( struct V_1 * V_101 , struct V_1 * V_102 )
{
struct V_85 V_86 ;
V_86 . V_87 = V_101 -> V_5 . V_2 ;
V_86 . V_90 = NULL ;
V_86 . V_91 = F_152 ;
V_86 . V_89 = NULL ;
V_86 . V_22 = V_102 -> V_5 . V_2 ;
if ( F_71 ( & V_86 ) )
F_54 ( V_176 L_7
L_8 ) ;
}
static void F_155 ( struct V_1 * V_9 )
{
struct V_1 * V_32 ;
if ( F_47 ( & V_9 -> V_5 . V_2 -> V_177 ) )
return;
V_32 = V_9 -> V_32 ;
while ( F_40 ( V_32 -> V_30 ) ||
F_41 ( V_32 -> V_33 ) )
V_32 = V_32 -> V_32 ;
F_154 ( V_9 , V_32 ) ;
}
static void F_156 ( struct V_1 * V_178 )
{
F_45 ( V_179 ) ;
struct V_1 * V_57 ;
struct V_1 * V_58 ;
struct V_2 * V_3 ;
static T_1 V_180 ;
F_50 ( (struct V_181 * ) & V_178 -> V_56 , & V_179 ) ;
while ( ! F_47 ( & V_179 ) ) {
V_57 = F_48 ( & V_179 , struct V_1 , V_56 ) ;
F_49 ( V_179 . V_59 ) ;
F_38 (cont, &cp->css.cgroup->children, sibling) {
V_58 = F_1 ( V_3 ) ;
F_50 ( & V_58 -> V_56 , & V_179 ) ;
}
if ( F_29 ( V_57 -> V_30 , V_96 ) &&
F_30 ( V_57 -> V_33 , V_34 [ V_35 ] ) )
continue;
V_180 = V_57 -> V_33 ;
F_75 ( & V_98 ) ;
F_21 ( V_57 -> V_30 , V_57 -> V_30 ,
V_96 ) ;
F_26 ( V_57 -> V_33 , V_57 -> V_33 ,
V_34 [ V_35 ] ) ;
F_76 ( & V_98 ) ;
if ( F_40 ( V_57 -> V_30 ) ||
F_41 ( V_57 -> V_33 ) )
F_155 ( V_57 ) ;
else {
F_70 ( V_57 , NULL ) ;
F_95 ( V_57 , & V_180 , NULL ) ;
}
}
}
void F_157 ( void )
{
struct V_53 * V_82 ;
T_2 * V_67 ;
int V_68 ;
F_59 () ;
F_75 ( & V_98 ) ;
F_22 ( V_47 . V_30 , V_96 ) ;
F_76 ( & V_98 ) ;
F_156 ( & V_47 ) ;
V_68 = F_51 ( & V_67 , & V_82 ) ;
F_60 () ;
F_61 ( V_68 , V_67 , V_82 ) ;
}
static int F_158 ( struct V_182 * V_183 ,
unsigned long V_184 , void * V_185 )
{
static T_1 V_180 ;
F_59 () ;
switch ( V_184 ) {
case V_186 :
V_180 = V_47 . V_33 ;
F_75 ( & V_98 ) ;
V_47 . V_33 = V_34 [ V_35 ] ;
F_76 ( & V_98 ) ;
F_95 ( & V_47 , & V_180 , NULL ) ;
break;
case V_187 :
F_156 ( & V_47 ) ;
break;
default:
break;
}
F_60 () ;
return V_188 ;
}
void T_12 F_159 ( void )
{
F_22 ( V_47 . V_30 , V_96 ) ;
V_47 . V_33 = V_34 [ V_35 ] ;
F_160 ( F_158 , 10 ) ;
V_83 = F_161 ( L_9 ) ;
F_23 ( ! V_83 ) ;
}
void F_162 ( struct V_6 * V_36 , struct V_28 * V_29 )
{
F_75 ( & V_98 ) ;
F_83 ( V_36 ) ;
F_19 ( F_4 ( V_36 ) , V_29 ) ;
F_88 ( V_36 ) ;
F_76 ( & V_98 ) ;
}
int F_163 ( struct V_6 * V_36 )
{
const struct V_1 * V_9 ;
int V_189 ;
F_164 () ;
V_9 = F_4 ( V_36 ) ;
if ( V_9 )
F_165 ( V_36 , V_9 -> V_30 ) ;
F_166 () ;
V_189 = F_167 ( & V_36 -> V_30 , V_96 ) ;
if ( V_189 >= V_190 ) {
F_165 ( V_36 , V_142 ) ;
V_189 = F_168 ( V_96 ) ;
}
return V_189 ;
}
void F_169 ( void )
{
F_150 ( V_103 -> V_33 ) ;
}
T_1 F_170 ( struct V_6 * V_36 )
{
T_1 V_191 ;
F_75 ( & V_98 ) ;
F_83 ( V_36 ) ;
F_24 ( F_4 ( V_36 ) , & V_191 ) ;
F_88 ( V_36 ) ;
F_76 ( & V_98 ) ;
return V_191 ;
}
int F_171 ( T_1 * V_192 )
{
return F_25 ( * V_192 , V_103 -> V_33 ) ;
}
static const struct V_1 * F_172 ( const struct V_1 * V_9 )
{
while ( ! ( F_9 ( V_9 ) || F_10 ( V_9 ) ) && V_9 -> V_32 )
V_9 = V_9 -> V_32 ;
return V_9 ;
}
int F_173 ( int V_193 , T_13 V_194 )
{
const struct V_1 * V_9 ;
int V_195 ;
if ( F_174 () || ( V_194 & V_196 ) )
return 1 ;
F_175 ( ! ( V_194 & V_197 ) ) ;
if ( F_176 ( V_193 , V_103 -> V_33 ) )
return 1 ;
if ( F_81 ( F_82 ( V_108 ) ) )
return 1 ;
if ( V_194 & V_197 )
return 0 ;
if ( V_103 -> V_11 & V_109 )
return 1 ;
F_75 ( & V_98 ) ;
F_83 ( V_103 ) ;
V_9 = F_172 ( F_4 ( V_103 ) ) ;
F_88 ( V_103 ) ;
V_195 = F_176 ( V_193 , V_9 -> V_33 ) ;
F_76 ( & V_98 ) ;
return V_195 ;
}
int F_177 ( int V_193 , T_13 V_194 )
{
if ( F_174 () || ( V_194 & V_196 ) )
return 1 ;
if ( F_176 ( V_193 , V_103 -> V_33 ) )
return 1 ;
if ( F_81 ( F_82 ( V_108 ) ) )
return 1 ;
return 0 ;
}
void F_178 ( void )
{
F_76 ( & V_98 ) ;
}
static int F_179 ( int * V_198 )
{
int V_193 ;
V_193 = F_180 ( * V_198 , V_103 -> V_33 ) ;
if ( V_193 == V_199 )
V_193 = F_181 ( V_103 -> V_33 ) ;
* V_198 = V_193 ;
return V_193 ;
}
int F_182 ( void )
{
if ( V_103 -> V_200 == V_201 )
V_103 -> V_200 =
F_183 ( & V_103 -> V_33 ) ;
return F_179 ( & V_103 -> V_200 ) ;
}
int F_184 ( void )
{
if ( V_103 -> V_202 == V_201 )
V_103 -> V_202 =
F_183 ( & V_103 -> V_33 ) ;
return F_179 ( & V_103 -> V_202 ) ;
}
int F_185 ( const struct V_6 * V_203 ,
const struct V_6 * V_204 )
{
return F_25 ( V_203 -> V_33 , V_204 -> V_33 ) ;
}
void F_186 ( struct V_6 * V_36 )
{
struct V_18 * V_18 ;
V_18 = F_4 ( V_36 ) -> V_5 . V_2 -> V_18 ;
F_116 ( & V_205 ) ;
snprintf ( V_206 , V_207 ,
V_18 ? ( const char * ) V_18 -> V_208 . V_209 : L_10 ) ;
F_133 ( V_210 , V_211 ,
V_36 -> V_33 ) ;
F_54 ( V_212 L_11 ,
V_36 -> V_213 , V_206 , V_210 ) ;
F_117 ( & V_205 ) ;
}
void F_187 ( void )
{
F_83 ( V_103 ) ;
F_115 ( & F_4 ( V_103 ) -> V_125 ) ;
F_88 ( V_103 ) ;
}
static int F_188 ( struct V_214 * V_215 , void * V_216 )
{
struct V_217 * V_217 ;
struct V_6 * V_36 ;
char * V_93 ;
struct F_3 * V_5 ;
int V_94 ;
V_94 = - V_116 ;
V_93 = F_53 ( V_97 , V_42 ) ;
if ( ! V_93 )
goto V_124;
V_94 = - V_218 ;
V_217 = V_215 -> V_150 ;
V_36 = F_189 ( V_217 , V_219 ) ;
if ( ! V_36 )
goto V_220;
V_94 = - V_49 ;
F_59 () ;
V_5 = F_5 ( V_36 , V_4 ) ;
V_94 = F_190 ( V_5 -> V_2 , V_93 , V_97 ) ;
if ( V_94 < 0 )
goto V_221;
F_191 ( V_215 , V_93 ) ;
F_192 ( V_215 , '\n' ) ;
V_221:
F_60 () ;
F_193 ( V_36 ) ;
V_220:
F_34 ( V_93 ) ;
V_124:
return V_94 ;
}
static int F_194 ( struct V_222 * V_222 , struct V_166 * V_166 )
{
struct V_217 * V_217 = F_195 ( V_222 ) -> V_217 ;
return F_196 ( V_166 , F_188 , V_217 ) ;
}
void F_197 ( struct V_214 * V_215 , struct V_6 * V_7 )
{
F_198 ( V_215 , L_12 ) ;
F_199 ( V_215 , & V_7 -> V_33 ) ;
F_198 ( V_215 , L_13 ) ;
F_198 ( V_215 , L_14 ) ;
F_200 ( V_215 , & V_7 -> V_33 ) ;
F_198 ( V_215 , L_13 ) ;
}
