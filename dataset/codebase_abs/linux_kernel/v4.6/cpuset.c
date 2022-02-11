static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 , V_6 ) ) ;
}
static inline struct V_1 * F_5 ( struct V_1 * V_7 )
{
return F_1 ( V_7 -> V_3 . V_8 ) ;
}
static inline bool F_6 ( struct V_4 * V_5 )
{
return V_5 -> V_9 ;
}
static inline bool F_6 ( struct V_4 * V_5 )
{
return false ;
}
static inline bool F_7 ( const struct V_1 * V_7 )
{
return F_8 ( V_10 , & V_7 -> V_11 ) ;
}
static inline int F_9 ( const struct V_1 * V_7 )
{
return F_8 ( V_12 , & V_7 -> V_11 ) ;
}
static inline int F_10 ( const struct V_1 * V_7 )
{
return F_8 ( V_13 , & V_7 -> V_11 ) ;
}
static inline int F_11 ( const struct V_1 * V_7 )
{
return F_8 ( V_14 , & V_7 -> V_11 ) ;
}
static inline int F_12 ( const struct V_1 * V_7 )
{
return F_8 ( V_15 , & V_7 -> V_11 ) ;
}
static inline int F_13 ( const struct V_1 * V_7 )
{
return F_8 ( V_16 , & V_7 -> V_11 ) ;
}
static inline int F_14 ( const struct V_1 * V_7 )
{
return F_8 ( V_17 , & V_7 -> V_11 ) ;
}
static inline int F_15 ( const struct V_1 * V_7 )
{
return F_8 ( V_18 , & V_7 -> V_11 ) ;
}
static struct V_19 * F_16 ( struct V_20 * V_21 ,
int V_11 , const char * V_22 , void * V_23 )
{
struct V_20 * V_24 = F_17 ( L_1 ) ;
struct V_19 * V_25 = F_18 ( - V_26 ) ;
if ( V_24 ) {
char V_27 [] =
L_2
L_3 ;
V_25 = V_24 -> V_28 ( V_24 , V_11 ,
V_22 , V_27 ) ;
F_19 ( V_24 ) ;
}
return V_25 ;
}
static void F_20 ( struct V_1 * V_7 , struct V_29 * V_30 )
{
while ( ! F_21 ( V_7 -> V_31 , V_32 ) )
V_7 = F_5 ( V_7 ) ;
F_22 ( V_30 , V_7 -> V_31 , V_32 ) ;
}
static void F_23 ( struct V_1 * V_7 , T_1 * V_30 )
{
while ( ! F_24 ( V_7 -> V_33 , V_34 [ V_35 ] ) )
V_7 = F_5 ( V_7 ) ;
F_25 ( * V_30 , V_7 -> V_33 , V_34 [ V_35 ] ) ;
}
static void F_26 ( struct V_1 * V_7 ,
struct V_4 * V_36 )
{
if ( F_14 ( V_7 ) )
F_27 ( V_36 ) ;
else
F_28 ( V_36 ) ;
if ( F_15 ( V_7 ) )
F_29 ( V_36 ) ;
else
F_30 ( V_36 ) ;
}
static int F_31 ( const struct V_1 * V_37 , const struct V_1 * V_38 )
{
return F_32 ( V_37 -> V_39 , V_38 -> V_39 ) &&
F_33 ( V_37 -> V_40 , V_38 -> V_40 ) &&
F_9 ( V_37 ) <= F_9 ( V_38 ) &&
F_10 ( V_37 ) <= F_10 ( V_38 ) ;
}
static struct V_1 * F_34 ( struct V_1 * V_7 )
{
struct V_1 * V_41 ;
V_41 = F_35 ( V_7 , sizeof( * V_7 ) , V_42 ) ;
if ( ! V_41 )
return NULL ;
if ( ! F_36 ( & V_41 -> V_39 , V_42 ) )
goto V_43;
if ( ! F_36 ( & V_41 -> V_31 , V_42 ) )
goto V_44;
F_37 ( V_41 -> V_39 , V_7 -> V_39 ) ;
F_37 ( V_41 -> V_31 , V_7 -> V_31 ) ;
return V_41 ;
V_44:
F_38 ( V_41 -> V_39 ) ;
V_43:
F_39 ( V_41 ) ;
return NULL ;
}
static void F_40 ( struct V_1 * V_41 )
{
F_38 ( V_41 -> V_31 ) ;
F_38 ( V_41 -> V_39 ) ;
F_39 ( V_41 ) ;
}
static int F_41 ( struct V_1 * V_45 , struct V_1 * V_41 )
{
struct V_2 * V_3 ;
struct V_1 * V_46 , * V_47 ;
int V_25 ;
F_42 () ;
V_25 = - V_48 ;
F_43 (c, css, cur)
if ( ! F_31 ( V_46 , V_41 ) )
goto V_49;
V_25 = 0 ;
if ( V_45 == & V_50 )
goto V_49;
V_47 = F_5 ( V_45 ) ;
V_25 = - V_51 ;
if ( ! F_44 ( V_52 ) &&
! F_31 ( V_41 , V_47 ) )
goto V_49;
V_25 = - V_53 ;
F_43 (c, css, par) {
if ( ( F_9 ( V_41 ) || F_9 ( V_46 ) ) &&
V_46 != V_45 &&
F_21 ( V_41 -> V_39 , V_46 -> V_39 ) )
goto V_49;
if ( ( F_10 ( V_41 ) || F_10 ( V_46 ) ) &&
V_46 != V_45 &&
F_24 ( V_41 -> V_40 , V_46 -> V_40 ) )
goto V_49;
}
V_25 = - V_54 ;
if ( ( F_45 ( V_45 -> V_3 . V_55 ) || V_45 -> V_56 ) ) {
if ( ! F_46 ( V_45 -> V_39 ) &&
F_46 ( V_41 -> V_39 ) )
goto V_49;
if ( ! F_47 ( V_45 -> V_40 ) &&
F_47 ( V_41 -> V_40 ) )
goto V_49;
}
V_25 = - V_48 ;
if ( F_9 ( V_45 ) &&
! F_48 ( V_45 -> V_39 ,
V_41 -> V_39 ) )
goto V_49;
V_25 = 0 ;
V_49:
F_49 () ;
return V_25 ;
}
static int F_50 ( struct V_1 * V_57 , struct V_1 * V_58 )
{
return F_21 ( V_57 -> V_31 , V_58 -> V_31 ) ;
}
static void
F_51 ( struct V_59 * V_60 , struct V_1 * V_46 )
{
if ( V_60 -> V_61 < V_46 -> V_61 )
V_60 -> V_61 = V_46 -> V_61 ;
return;
}
static void F_52 ( struct V_59 * V_60 ,
struct V_1 * V_62 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
F_42 () ;
F_53 (cp, pos_css, root_cs) {
if ( F_46 ( V_63 -> V_39 ) ) {
V_64 = F_54 ( V_64 ) ;
continue;
}
if ( F_12 ( V_63 ) )
F_51 ( V_60 , V_63 ) ;
}
F_49 () ;
}
static int F_55 ( T_2 * * V_65 ,
struct V_59 * * V_66 )
{
struct V_1 * V_63 ;
struct V_1 * * V_67 ;
int V_68 ;
int V_69 , V_70 , V_71 ;
T_2 * V_72 ;
T_2 V_73 ;
struct V_59 * V_60 ;
int V_74 = 0 ;
int V_75 ;
struct V_2 * V_64 ;
V_72 = NULL ;
V_60 = NULL ;
V_67 = NULL ;
if ( ! F_36 ( & V_73 , V_42 ) )
goto V_76;
F_56 ( V_73 , V_77 , V_78 ) ;
if ( F_12 ( & V_50 ) ) {
V_74 = 1 ;
V_72 = F_57 ( V_74 ) ;
if ( ! V_72 )
goto V_76;
V_60 = F_58 ( sizeof( struct V_59 ) , V_42 ) ;
if ( V_60 ) {
* V_60 = V_79 ;
F_52 ( V_60 , & V_50 ) ;
}
F_22 ( V_72 [ 0 ] , V_50 . V_31 ,
V_73 ) ;
goto V_76;
}
V_67 = F_58 ( F_59 () * sizeof( V_63 ) , V_42 ) ;
if ( ! V_67 )
goto V_76;
V_68 = 0 ;
F_42 () ;
F_53 (cp, pos_css, &top_cpuset) {
if ( V_63 == & V_50 )
continue;
if ( ! F_46 ( V_63 -> V_39 ) &&
! ( F_12 ( V_63 ) &&
F_21 ( V_63 -> V_39 , V_73 ) ) )
continue;
if ( F_12 ( V_63 ) )
V_67 [ V_68 ++ ] = V_63 ;
V_64 = F_54 ( V_64 ) ;
}
F_49 () ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ )
V_67 [ V_69 ] -> V_80 = V_69 ;
V_74 = V_68 ;
V_81:
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
struct V_1 * V_57 = V_67 [ V_69 ] ;
int V_82 = V_57 -> V_80 ;
for ( V_70 = 0 ; V_70 < V_68 ; V_70 ++ ) {
struct V_1 * V_58 = V_67 [ V_70 ] ;
int V_83 = V_58 -> V_80 ;
if ( V_82 != V_83 && F_50 ( V_57 , V_58 ) ) {
for ( V_71 = 0 ; V_71 < V_68 ; V_71 ++ ) {
struct V_1 * V_46 = V_67 [ V_71 ] ;
if ( V_46 -> V_80 == V_83 )
V_46 -> V_80 = V_82 ;
}
V_74 -- ;
goto V_81;
}
}
}
V_72 = F_57 ( V_74 ) ;
if ( ! V_72 )
goto V_76;
V_60 = F_58 ( V_74 * sizeof( struct V_59 ) , V_42 ) ;
for ( V_75 = 0 , V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
struct V_1 * V_57 = V_67 [ V_69 ] ;
struct V_29 * V_84 ;
int V_82 = V_57 -> V_80 ;
if ( V_82 < 0 ) {
continue;
}
V_84 = V_72 [ V_75 ] ;
if ( V_75 == V_74 ) {
static int V_85 = 10 ;
if ( V_85 ) {
F_60 ( L_4 ,
V_75 , V_74 , V_68 , V_69 , V_82 ) ;
V_85 -- ;
}
continue;
}
F_61 ( V_84 ) ;
if ( V_60 )
* ( V_60 + V_75 ) = V_79 ;
for ( V_70 = V_69 ; V_70 < V_68 ; V_70 ++ ) {
struct V_1 * V_58 = V_67 [ V_70 ] ;
if ( V_82 == V_58 -> V_80 ) {
F_62 ( V_84 , V_84 , V_58 -> V_31 ) ;
F_22 ( V_84 , V_84 , V_73 ) ;
if ( V_60 )
F_52 ( V_60 + V_75 , V_58 ) ;
V_58 -> V_80 = - 1 ;
}
}
V_75 ++ ;
}
F_63 ( V_75 != V_74 ) ;
V_76:
F_38 ( V_73 ) ;
F_39 ( V_67 ) ;
if ( V_72 == NULL )
V_74 = 1 ;
* V_65 = V_72 ;
* V_66 = V_60 ;
return V_74 ;
}
static void F_64 ( void )
{
struct V_59 * V_86 ;
T_2 * V_72 ;
int V_74 ;
F_65 ( & V_87 ) ;
F_66 () ;
if ( ! F_67 ( V_50 . V_31 , V_88 ) )
goto V_49;
V_74 = F_55 ( & V_72 , & V_86 ) ;
F_68 ( V_74 , V_72 , V_86 ) ;
V_49:
F_69 () ;
}
static void F_64 ( void )
{
}
void F_70 ( void )
{
F_71 ( & V_87 ) ;
F_64 () ;
F_72 ( & V_87 ) ;
}
static void F_73 ( struct V_1 * V_7 )
{
struct V_89 V_90 ;
struct V_4 * V_5 ;
F_74 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_75 ( & V_90 ) ) )
F_76 ( V_5 , V_7 -> V_31 ) ;
F_77 ( & V_90 ) ;
}
static void F_78 ( struct V_1 * V_7 , struct V_29 * V_91 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
bool V_92 = false ;
F_42 () ;
F_53 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_63 ) ;
F_22 ( V_91 , V_63 -> V_39 , V_8 -> V_31 ) ;
if ( F_44 ( V_52 ) &&
F_46 ( V_91 ) )
F_37 ( V_91 , V_8 -> V_31 ) ;
if ( F_67 ( V_91 , V_63 -> V_31 ) ) {
V_64 = F_54 ( V_64 ) ;
continue;
}
if ( ! F_79 ( & V_63 -> V_3 ) )
continue;
F_49 () ;
F_80 ( & V_93 ) ;
F_37 ( V_63 -> V_31 , V_91 ) ;
F_81 ( & V_93 ) ;
F_82 ( ! F_44 ( V_52 ) &&
! F_67 ( V_63 -> V_39 , V_63 -> V_31 ) ) ;
F_73 ( V_63 ) ;
if ( ! F_46 ( V_63 -> V_39 ) &&
F_12 ( V_63 ) )
V_92 = true ;
F_42 () ;
F_83 ( & V_63 -> V_3 ) ;
}
F_49 () ;
if ( V_92 )
F_64 () ;
}
static int F_84 ( struct V_1 * V_7 , struct V_1 * V_94 ,
const char * V_95 )
{
int V_96 ;
if ( V_7 == & V_50 )
return - V_51 ;
if ( ! * V_95 ) {
F_61 ( V_94 -> V_39 ) ;
} else {
V_96 = F_85 ( V_95 , V_94 -> V_39 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! F_32 ( V_94 -> V_39 ,
V_50 . V_39 ) )
return - V_53 ;
}
if ( F_67 ( V_7 -> V_39 , V_94 -> V_39 ) )
return 0 ;
V_96 = F_41 ( V_7 , V_94 ) ;
if ( V_96 < 0 )
return V_96 ;
F_80 ( & V_93 ) ;
F_37 ( V_7 -> V_39 , V_94 -> V_39 ) ;
F_81 ( & V_93 ) ;
F_78 ( V_7 , V_94 -> V_39 ) ;
return 0 ;
}
static void F_86 ( struct V_97 * V_98 )
{
struct V_99 * V_100 =
F_2 ( V_98 , struct V_99 , V_98 ) ;
F_87 ( V_100 -> V_101 , & V_100 -> V_102 , & V_100 -> V_103 , V_104 ) ;
F_88 ( V_100 -> V_101 ) ;
F_39 ( V_100 ) ;
}
static void F_89 ( struct V_105 * V_101 , const T_1 * V_102 ,
const T_1 * V_103 )
{
struct V_99 * V_100 ;
V_100 = F_90 ( sizeof( * V_100 ) , V_42 ) ;
if ( V_100 ) {
V_100 -> V_101 = V_101 ;
V_100 -> V_102 = * V_102 ;
V_100 -> V_103 = * V_103 ;
F_91 ( & V_100 -> V_98 , F_86 ) ;
F_92 ( V_106 , & V_100 -> V_98 ) ;
} else {
F_88 ( V_101 ) ;
}
}
static void F_93 ( void )
{
F_94 ( V_106 ) ;
}
static void F_95 ( struct V_4 * V_36 ,
T_1 * V_107 )
{
bool V_108 ;
if ( F_96 ( F_97 ( V_109 ) ) )
return;
if ( V_110 -> V_11 & V_111 )
return;
F_98 ( V_36 ) ;
V_108 = F_6 ( V_36 ) ||
! F_24 ( * V_107 , V_36 -> V_40 ) ;
if ( V_108 ) {
F_99 () ;
F_100 ( & V_36 -> V_112 ) ;
}
F_101 ( V_36 -> V_40 , V_36 -> V_40 , * V_107 ) ;
F_102 ( V_36 , V_107 , V_113 ) ;
F_102 ( V_36 , V_107 , V_114 ) ;
V_36 -> V_40 = * V_107 ;
if ( V_108 ) {
F_103 ( & V_36 -> V_112 ) ;
F_104 () ;
}
F_105 ( V_36 ) ;
}
static void F_106 ( struct V_1 * V_7 )
{
static T_1 V_107 ;
struct V_89 V_90 ;
struct V_4 * V_5 ;
V_115 = V_7 ;
F_23 ( V_7 , & V_107 ) ;
F_74 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_75 ( & V_90 ) ) ) {
struct V_105 * V_101 ;
bool V_116 ;
F_95 ( V_5 , & V_107 ) ;
V_101 = F_107 ( V_5 ) ;
if ( ! V_101 )
continue;
V_116 = F_13 ( V_7 ) ;
F_108 ( V_101 , & V_7 -> V_40 ) ;
if ( V_116 )
F_89 ( V_101 , & V_7 -> V_117 , & V_107 ) ;
else
F_88 ( V_101 ) ;
}
F_77 ( & V_90 ) ;
V_7 -> V_117 = V_107 ;
V_115 = NULL ;
}
static void F_109 ( struct V_1 * V_7 , T_1 * V_118 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
F_42 () ;
F_53 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_63 ) ;
F_25 ( * V_118 , V_63 -> V_40 , V_8 -> V_33 ) ;
if ( F_44 ( V_52 ) &&
F_47 ( * V_118 ) )
* V_118 = V_8 -> V_33 ;
if ( F_110 ( * V_118 , V_63 -> V_33 ) ) {
V_64 = F_54 ( V_64 ) ;
continue;
}
if ( ! F_79 ( & V_63 -> V_3 ) )
continue;
F_49 () ;
F_80 ( & V_93 ) ;
V_63 -> V_33 = * V_118 ;
F_81 ( & V_93 ) ;
F_82 ( ! F_44 ( V_52 ) &&
! F_110 ( V_63 -> V_40 , V_63 -> V_33 ) ) ;
F_106 ( V_63 ) ;
F_42 () ;
F_83 ( & V_63 -> V_3 ) ;
}
F_49 () ;
}
static int F_111 ( struct V_1 * V_7 , struct V_1 * V_94 ,
const char * V_95 )
{
int V_96 ;
if ( V_7 == & V_50 ) {
V_96 = - V_51 ;
goto V_76;
}
if ( ! * V_95 ) {
F_112 ( V_94 -> V_40 ) ;
} else {
V_96 = F_113 ( V_95 , V_94 -> V_40 ) ;
if ( V_96 < 0 )
goto V_76;
if ( ! F_33 ( V_94 -> V_40 ,
V_50 . V_40 ) ) {
V_96 = - V_53 ;
goto V_76;
}
}
if ( F_110 ( V_7 -> V_40 , V_94 -> V_40 ) ) {
V_96 = 0 ;
goto V_76;
}
V_96 = F_41 ( V_7 , V_94 ) ;
if ( V_96 < 0 )
goto V_76;
F_80 ( & V_93 ) ;
V_7 -> V_40 = V_94 -> V_40 ;
F_81 ( & V_93 ) ;
F_109 ( V_7 , & V_94 -> V_40 ) ;
V_76:
return V_96 ;
}
int F_114 ( void )
{
int V_25 ;
F_42 () ;
V_25 = F_3 ( V_110 ) == V_115 ;
F_49 () ;
return V_25 ;
}
static int F_115 ( struct V_1 * V_7 , T_3 V_119 )
{
#ifdef F_116
if ( V_119 < - 1 || V_119 >= V_120 )
return - V_53 ;
#endif
if ( V_119 != V_7 -> V_61 ) {
V_7 -> V_61 = V_119 ;
if ( ! F_46 ( V_7 -> V_39 ) &&
F_12 ( V_7 ) )
F_64 () ;
}
return 0 ;
}
static void F_117 ( struct V_1 * V_7 )
{
struct V_89 V_90 ;
struct V_4 * V_5 ;
F_74 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_75 ( & V_90 ) ) )
F_26 ( V_7 , V_5 ) ;
F_77 ( & V_90 ) ;
}
static int F_118 ( T_4 V_121 , struct V_1 * V_7 ,
int V_122 )
{
struct V_1 * V_94 ;
int V_123 ;
int V_124 ;
int V_125 ;
V_94 = F_34 ( V_7 ) ;
if ( ! V_94 )
return - V_126 ;
if ( V_122 )
F_119 ( V_121 , & V_94 -> V_11 ) ;
else
F_120 ( V_121 , & V_94 -> V_11 ) ;
V_125 = F_41 ( V_7 , V_94 ) ;
if ( V_125 < 0 )
goto V_49;
V_123 = ( F_12 ( V_7 ) !=
F_12 ( V_94 ) ) ;
V_124 = ( ( F_15 ( V_7 ) != F_15 ( V_94 ) )
|| ( F_14 ( V_7 ) != F_14 ( V_94 ) ) ) ;
F_80 ( & V_93 ) ;
V_7 -> V_11 = V_94 -> V_11 ;
F_81 ( & V_93 ) ;
if ( ! F_46 ( V_94 -> V_39 ) && V_123 )
F_64 () ;
if ( V_124 )
F_117 ( V_7 ) ;
V_49:
F_40 ( V_94 ) ;
return V_125 ;
}
static void F_121 ( struct V_127 * V_128 )
{
V_128 -> V_129 = 0 ;
V_128 -> V_119 = 0 ;
V_128 -> time = 0 ;
F_122 ( & V_128 -> V_130 ) ;
}
static void F_123 ( struct V_127 * V_128 )
{
T_5 V_131 ;
T_6 V_132 ;
V_131 = F_124 () ;
V_132 = V_131 - V_128 -> time ;
if ( V_132 == 0 )
return;
V_132 = F_125 ( V_133 , V_132 ) ;
while ( V_132 -- > 0 )
V_128 -> V_119 = ( V_134 * V_128 -> V_119 ) / V_135 ;
V_128 -> time = V_131 ;
V_128 -> V_119 += ( ( V_135 - V_134 ) * V_128 -> V_129 ) / V_135 ;
V_128 -> V_129 = 0 ;
}
static void F_126 ( struct V_127 * V_128 )
{
F_127 ( & V_128 -> V_130 ) ;
F_123 ( V_128 ) ;
V_128 -> V_129 = F_125 ( V_136 , V_128 -> V_129 + V_135 ) ;
F_128 ( & V_128 -> V_130 ) ;
}
static int F_129 ( struct V_127 * V_128 )
{
int V_119 ;
F_127 ( & V_128 -> V_130 ) ;
F_123 ( V_128 ) ;
V_119 = V_128 -> V_119 ;
F_128 ( & V_128 -> V_130 ) ;
return V_119 ;
}
static int F_130 ( struct V_137 * V_138 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
int V_25 ;
V_139 = F_3 ( F_131 ( V_138 , & V_3 ) ) ;
V_7 = F_1 ( V_3 ) ;
F_71 ( & V_87 ) ;
V_25 = - V_54 ;
if ( ! F_44 ( V_52 ) &&
( F_46 ( V_7 -> V_39 ) || F_47 ( V_7 -> V_40 ) ) )
goto V_140;
F_132 (task, css, tset) {
V_25 = F_133 ( V_5 , V_7 -> V_39 ) ;
if ( V_25 )
goto V_140;
V_25 = F_134 ( V_5 ) ;
if ( V_25 )
goto V_140;
}
V_7 -> V_56 ++ ;
V_25 = 0 ;
V_140:
F_72 ( & V_87 ) ;
return V_25 ;
}
static void F_135 ( struct V_137 * V_138 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
F_131 ( V_138 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_71 ( & V_87 ) ;
F_1 ( V_3 ) -> V_56 -- ;
F_72 ( & V_87 ) ;
}
static void F_136 ( struct V_137 * V_138 )
{
static T_1 V_141 ;
struct V_4 * V_5 ;
struct V_4 * V_142 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_1 * V_143 = V_139 ;
F_131 ( V_138 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_71 ( & V_87 ) ;
if ( V_7 == & V_50 )
F_37 ( V_144 , V_77 ) ;
else
F_20 ( V_7 , V_144 ) ;
F_23 ( V_7 , & V_141 ) ;
F_132 (task, css, tset) {
F_137 ( F_76 ( V_5 , V_144 ) ) ;
F_95 ( V_5 , & V_141 ) ;
F_26 ( V_7 , V_5 ) ;
}
V_141 = V_7 -> V_33 ;
F_138 (leader, css, tset) {
struct V_105 * V_101 = F_107 ( V_142 ) ;
if ( V_101 ) {
F_108 ( V_101 , & V_141 ) ;
if ( F_13 ( V_7 ) )
F_89 ( V_101 , & V_143 -> V_117 ,
& V_141 ) ;
else
F_88 ( V_101 ) ;
}
}
V_7 -> V_117 = V_141 ;
V_7 -> V_56 -- ;
if ( ! V_7 -> V_56 )
F_139 ( & V_145 ) ;
F_72 ( & V_87 ) ;
}
static int F_140 ( struct V_2 * V_3 , struct V_146 * V_147 ,
T_7 V_119 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_147 -> V_148 ;
int V_96 = 0 ;
F_71 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) ) {
V_96 = - V_26 ;
goto V_140;
}
switch ( type ) {
case V_149 :
V_96 = F_118 ( V_12 , V_7 , V_119 ) ;
break;
case V_150 :
V_96 = F_118 ( V_13 , V_7 , V_119 ) ;
break;
case V_151 :
V_96 = F_118 ( V_14 , V_7 , V_119 ) ;
break;
case V_152 :
V_96 = F_118 ( V_15 , V_7 , V_119 ) ;
break;
case V_153 :
V_96 = F_118 ( V_16 , V_7 , V_119 ) ;
break;
case V_154 :
V_155 = ! ! V_119 ;
break;
case V_156 :
V_96 = F_118 ( V_17 , V_7 , V_119 ) ;
break;
case V_157 :
V_96 = F_118 ( V_18 , V_7 , V_119 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
V_140:
F_72 ( & V_87 ) ;
return V_96 ;
}
static int F_141 ( struct V_2 * V_3 , struct V_146 * V_147 ,
T_3 V_119 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_147 -> V_148 ;
int V_96 = - V_26 ;
F_71 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) )
goto V_140;
switch ( type ) {
case V_158 :
V_96 = F_115 ( V_7 , V_119 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
V_140:
F_72 ( & V_87 ) ;
return V_96 ;
}
static T_9 F_142 ( struct V_159 * V_160 ,
char * V_95 , T_10 V_161 , T_11 V_162 )
{
struct V_1 * V_7 = F_1 ( F_143 ( V_160 ) ) ;
struct V_1 * V_94 ;
int V_96 = - V_26 ;
V_95 = F_144 ( V_95 ) ;
F_145 ( & V_7 -> V_3 ) ;
F_146 ( V_160 -> V_163 ) ;
F_147 ( & V_164 ) ;
F_71 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) )
goto V_140;
V_94 = F_34 ( V_7 ) ;
if ( ! V_94 ) {
V_96 = - V_126 ;
goto V_140;
}
switch ( F_148 ( V_160 ) -> V_148 ) {
case V_165 :
V_96 = F_84 ( V_7 , V_94 , V_95 ) ;
break;
case V_166 :
V_96 = F_111 ( V_7 , V_94 , V_95 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
F_40 ( V_94 ) ;
V_140:
F_72 ( & V_87 ) ;
F_149 ( V_160 -> V_163 ) ;
F_83 ( & V_7 -> V_3 ) ;
F_94 ( V_106 ) ;
return V_96 ? : V_161 ;
}
static int F_150 ( struct V_167 * V_168 , void * V_169 )
{
struct V_1 * V_7 = F_1 ( F_151 ( V_168 ) ) ;
T_8 type = F_152 ( V_168 ) -> V_148 ;
int V_25 = 0 ;
F_80 ( & V_93 ) ;
switch ( type ) {
case V_165 :
F_153 ( V_168 , L_5 , F_154 ( V_7 -> V_39 ) ) ;
break;
case V_166 :
F_153 ( V_168 , L_5 , F_155 ( & V_7 -> V_40 ) ) ;
break;
case V_170 :
F_153 ( V_168 , L_5 , F_154 ( V_7 -> V_31 ) ) ;
break;
case V_171 :
F_153 ( V_168 , L_5 , F_155 ( & V_7 -> V_33 ) ) ;
break;
default:
V_25 = - V_53 ;
}
F_81 ( & V_93 ) ;
return V_25 ;
}
static T_7 F_156 ( struct V_2 * V_3 , struct V_146 * V_147 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_147 -> V_148 ;
switch ( type ) {
case V_149 :
return F_9 ( V_7 ) ;
case V_150 :
return F_10 ( V_7 ) ;
case V_151 :
return F_11 ( V_7 ) ;
case V_152 :
return F_12 ( V_7 ) ;
case V_153 :
return F_13 ( V_7 ) ;
case V_154 :
return V_155 ;
case V_172 :
return F_129 ( & V_7 -> V_127 ) ;
case V_156 :
return F_14 ( V_7 ) ;
case V_157 :
return F_15 ( V_7 ) ;
default:
F_157 () ;
}
return 0 ;
}
static T_3 F_158 ( struct V_2 * V_3 , struct V_146 * V_147 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_147 -> V_148 ;
switch ( type ) {
case V_158 :
return V_7 -> V_61 ;
default:
F_157 () ;
}
return 0 ;
}
static struct V_2 *
F_159 ( struct V_2 * V_173 )
{
struct V_1 * V_7 ;
if ( ! V_173 )
return & V_50 . V_3 ;
V_7 = F_90 ( sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 )
return F_18 ( - V_126 ) ;
if ( ! F_36 ( & V_7 -> V_39 , V_42 ) )
goto V_43;
if ( ! F_36 ( & V_7 -> V_31 , V_42 ) )
goto V_44;
F_119 ( V_15 , & V_7 -> V_11 ) ;
F_61 ( V_7 -> V_39 ) ;
F_112 ( V_7 -> V_40 ) ;
F_61 ( V_7 -> V_31 ) ;
F_112 ( V_7 -> V_33 ) ;
F_121 ( & V_7 -> V_127 ) ;
V_7 -> V_61 = - 1 ;
return & V_7 -> V_3 ;
V_44:
F_38 ( V_7 -> V_39 ) ;
V_43:
F_39 ( V_7 ) ;
return F_18 ( - V_126 ) ;
}
static int F_160 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_8 = F_5 ( V_7 ) ;
struct V_1 * V_174 ;
struct V_2 * V_64 ;
if ( ! V_8 )
return 0 ;
F_71 ( & V_87 ) ;
F_119 ( V_10 , & V_7 -> V_11 ) ;
if ( F_14 ( V_8 ) )
F_119 ( V_17 , & V_7 -> V_11 ) ;
if ( F_15 ( V_8 ) )
F_119 ( V_18 , & V_7 -> V_11 ) ;
F_161 () ;
F_80 ( & V_93 ) ;
if ( F_44 ( V_52 ) ) {
F_37 ( V_7 -> V_31 , V_8 -> V_31 ) ;
V_7 -> V_33 = V_8 -> V_33 ;
}
F_81 ( & V_93 ) ;
if ( ! F_8 ( V_175 , & V_3 -> V_55 -> V_11 ) )
goto V_140;
F_42 () ;
F_43 (tmp_cs, pos_css, parent) {
if ( F_10 ( V_174 ) || F_9 ( V_174 ) ) {
F_49 () ;
goto V_140;
}
}
F_49 () ;
F_80 ( & V_93 ) ;
V_7 -> V_40 = V_8 -> V_40 ;
V_7 -> V_33 = V_8 -> V_40 ;
F_37 ( V_7 -> V_39 , V_8 -> V_39 ) ;
F_37 ( V_7 -> V_31 , V_8 -> V_39 ) ;
F_81 ( & V_93 ) ;
V_140:
F_72 ( & V_87 ) ;
return 0 ;
}
static void F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_71 ( & V_87 ) ;
if ( F_12 ( V_7 ) )
F_118 ( V_15 , V_7 , 0 ) ;
F_163 () ;
F_120 ( V_10 , & V_7 -> V_11 ) ;
F_72 ( & V_87 ) ;
}
static void F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_38 ( V_7 -> V_31 ) ;
F_38 ( V_7 -> V_39 ) ;
F_39 ( V_7 ) ;
}
static void F_165 ( struct V_2 * V_176 )
{
F_71 ( & V_87 ) ;
F_80 ( & V_93 ) ;
if ( F_44 ( V_52 ) ) {
F_37 ( V_50 . V_39 , V_77 ) ;
V_50 . V_40 = V_177 ;
} else {
F_37 ( V_50 . V_39 ,
V_50 . V_31 ) ;
V_50 . V_40 = V_50 . V_33 ;
}
F_81 ( & V_93 ) ;
F_72 ( & V_87 ) ;
}
int T_12 F_166 ( void )
{
int V_125 = 0 ;
if ( ! F_36 ( & V_50 . V_39 , V_42 ) )
F_157 () ;
if ( ! F_36 ( & V_50 . V_31 , V_42 ) )
F_157 () ;
F_167 ( V_50 . V_39 ) ;
F_168 ( V_50 . V_40 ) ;
F_167 ( V_50 . V_31 ) ;
F_168 ( V_50 . V_33 ) ;
F_121 ( & V_50 . V_127 ) ;
F_119 ( V_15 , & V_50 . V_11 ) ;
V_50 . V_61 = - 1 ;
V_125 = F_169 ( & V_178 ) ;
if ( V_125 < 0 )
return V_125 ;
if ( ! F_36 ( & V_144 , V_42 ) )
F_157 () ;
return 0 ;
}
static void F_170 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_5 ( V_7 ) ;
while ( F_46 ( V_8 -> V_39 ) ||
F_47 ( V_8 -> V_40 ) )
V_8 = F_5 ( V_8 ) ;
if ( F_171 ( V_8 -> V_3 . V_55 , V_7 -> V_3 . V_55 ) ) {
F_172 ( L_6 ) ;
F_173 ( V_7 -> V_3 . V_55 ) ;
F_174 ( L_7 ) ;
}
}
static void
F_175 ( struct V_1 * V_7 ,
struct V_29 * V_91 , T_1 * V_118 ,
bool V_179 , bool V_180 )
{
bool V_181 ;
F_80 ( & V_93 ) ;
F_37 ( V_7 -> V_39 , V_91 ) ;
F_37 ( V_7 -> V_31 , V_91 ) ;
V_7 -> V_40 = * V_118 ;
V_7 -> V_33 = * V_118 ;
F_81 ( & V_93 ) ;
if ( V_179 && ! F_46 ( V_7 -> V_39 ) )
F_73 ( V_7 ) ;
if ( V_180 && ! F_47 ( V_7 -> V_40 ) )
F_106 ( V_7 ) ;
V_181 = F_46 ( V_7 -> V_39 ) ||
F_47 ( V_7 -> V_40 ) ;
F_72 ( & V_87 ) ;
if ( V_181 )
F_170 ( V_7 ) ;
F_71 ( & V_87 ) ;
}
static void
F_176 ( struct V_1 * V_7 ,
struct V_29 * V_91 , T_1 * V_118 ,
bool V_179 , bool V_180 )
{
if ( F_46 ( V_91 ) )
F_37 ( V_91 , F_5 ( V_7 ) -> V_31 ) ;
if ( F_47 ( * V_118 ) )
* V_118 = F_5 ( V_7 ) -> V_33 ;
F_80 ( & V_93 ) ;
F_37 ( V_7 -> V_31 , V_91 ) ;
V_7 -> V_33 = * V_118 ;
F_81 ( & V_93 ) ;
if ( V_179 )
F_73 ( V_7 ) ;
if ( V_180 )
F_106 ( V_7 ) ;
}
static void F_177 ( struct V_1 * V_7 )
{
static T_13 V_91 ;
static T_1 V_118 ;
bool V_179 ;
bool V_180 ;
V_182:
F_178 ( V_145 , V_7 -> V_56 == 0 ) ;
F_71 ( & V_87 ) ;
if ( V_7 -> V_56 ) {
F_72 ( & V_87 ) ;
goto V_182;
}
F_22 ( & V_91 , V_7 -> V_39 , F_5 ( V_7 ) -> V_31 ) ;
F_25 ( V_118 , V_7 -> V_40 , F_5 ( V_7 ) -> V_33 ) ;
V_179 = ! F_67 ( & V_91 , V_7 -> V_31 ) ;
V_180 = ! F_110 ( V_118 , V_7 -> V_33 ) ;
if ( F_44 ( V_52 ) )
F_176 ( V_7 , & V_91 , & V_118 ,
V_179 , V_180 ) ;
else
F_175 ( V_7 , & V_91 , & V_118 ,
V_179 , V_180 ) ;
F_72 ( & V_87 ) ;
}
static void F_179 ( struct V_97 * V_98 )
{
static T_13 V_91 ;
static T_1 V_118 ;
bool V_179 , V_180 ;
bool V_183 = F_44 ( V_52 ) ;
F_71 ( & V_87 ) ;
F_37 ( & V_91 , V_88 ) ;
V_118 = V_34 [ V_35 ] ;
V_179 = ! F_67 ( V_50 . V_31 , & V_91 ) ;
V_180 = ! F_110 ( V_50 . V_33 , V_118 ) ;
if ( V_179 ) {
F_80 ( & V_93 ) ;
if ( ! V_183 )
F_37 ( V_50 . V_39 , & V_91 ) ;
F_37 ( V_50 . V_31 , & V_91 ) ;
F_81 ( & V_93 ) ;
}
if ( V_180 ) {
F_80 ( & V_93 ) ;
if ( ! V_183 )
V_50 . V_40 = V_118 ;
V_50 . V_33 = V_118 ;
F_81 ( & V_93 ) ;
F_106 ( & V_50 ) ;
}
F_72 ( & V_87 ) ;
if ( V_179 || V_180 ) {
struct V_1 * V_7 ;
struct V_2 * V_64 ;
F_42 () ;
F_53 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_50 || ! F_79 ( & V_7 -> V_3 ) )
continue;
F_49 () ;
F_177 ( V_7 ) ;
F_42 () ;
F_83 ( & V_7 -> V_3 ) ;
}
F_49 () ;
}
if ( V_179 )
F_70 () ;
}
void F_180 ( bool V_184 )
{
F_68 ( 1 , NULL , NULL ) ;
F_181 ( & V_164 ) ;
}
static int F_182 ( struct V_185 * V_186 ,
unsigned long V_187 , void * V_188 )
{
F_181 ( & V_164 ) ;
return V_189 ;
}
void T_12 F_183 ( void )
{
F_37 ( V_50 . V_39 , V_88 ) ;
V_50 . V_40 = V_34 [ V_35 ] ;
V_50 . V_117 = V_50 . V_40 ;
F_37 ( V_50 . V_31 , V_88 ) ;
V_50 . V_33 = V_34 [ V_35 ] ;
F_184 ( & V_190 ) ;
V_106 = F_185 ( L_8 , 0 ) ;
F_63 ( ! V_106 ) ;
}
void F_186 ( struct V_4 * V_36 , struct V_29 * V_30 )
{
unsigned long V_11 ;
F_187 ( & V_93 , V_11 ) ;
F_42 () ;
F_20 ( F_3 ( V_36 ) , V_30 ) ;
F_49 () ;
F_188 ( & V_93 , V_11 ) ;
}
void F_189 ( struct V_4 * V_36 )
{
F_42 () ;
F_190 ( V_36 , F_3 ( V_36 ) -> V_31 ) ;
F_49 () ;
}
void T_12 F_191 ( void )
{
F_168 ( V_110 -> V_40 ) ;
}
T_1 F_192 ( struct V_4 * V_36 )
{
T_1 V_191 ;
unsigned long V_11 ;
F_187 ( & V_93 , V_11 ) ;
F_42 () ;
F_23 ( F_3 ( V_36 ) , & V_191 ) ;
F_49 () ;
F_188 ( & V_93 , V_11 ) ;
return V_191 ;
}
int F_193 ( T_1 * V_192 )
{
return F_24 ( * V_192 , V_110 -> V_40 ) ;
}
static struct V_1 * F_194 ( struct V_1 * V_7 )
{
while ( ! ( F_10 ( V_7 ) || F_11 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
int F_195 ( int V_193 , T_14 V_194 )
{
struct V_1 * V_7 ;
int V_195 ;
unsigned long V_11 ;
if ( F_196 () )
return 1 ;
if ( F_197 ( V_193 , V_110 -> V_40 ) )
return 1 ;
if ( F_96 ( F_97 ( V_109 ) ) )
return 1 ;
if ( V_194 & V_196 )
return 0 ;
if ( V_110 -> V_11 & V_111 )
return 1 ;
F_187 ( & V_93 , V_11 ) ;
F_42 () ;
V_7 = F_194 ( F_3 ( V_110 ) ) ;
V_195 = F_197 ( V_193 , V_7 -> V_40 ) ;
F_49 () ;
F_188 ( & V_93 , V_11 ) ;
return V_195 ;
}
static int F_198 ( int * V_197 )
{
int V_193 ;
V_193 = F_199 ( * V_197 , V_110 -> V_40 ) ;
if ( V_193 == V_198 )
V_193 = F_200 ( V_110 -> V_40 ) ;
* V_197 = V_193 ;
return V_193 ;
}
int F_201 ( void )
{
if ( V_110 -> V_199 == V_200 )
V_110 -> V_199 =
F_202 ( & V_110 -> V_40 ) ;
return F_198 ( & V_110 -> V_199 ) ;
}
int F_203 ( void )
{
if ( V_110 -> V_201 == V_200 )
V_110 -> V_201 =
F_202 ( & V_110 -> V_40 ) ;
return F_198 ( & V_110 -> V_201 ) ;
}
int F_204 ( const struct V_4 * V_202 ,
const struct V_4 * V_203 )
{
return F_24 ( V_202 -> V_40 , V_203 -> V_40 ) ;
}
void F_205 ( void )
{
struct V_55 * V_204 ;
F_42 () ;
V_204 = F_3 ( V_110 ) -> V_3 . V_55 ;
F_206 ( L_9 , V_110 -> V_205 ) ;
F_173 ( V_204 ) ;
F_174 ( L_10 ,
F_155 ( & V_110 -> V_40 ) ) ;
F_49 () ;
}
void F_207 ( void )
{
F_42 () ;
F_126 ( & F_3 ( V_110 ) -> V_127 ) ;
F_49 () ;
}
int F_208 ( struct V_167 * V_206 , struct V_207 * V_208 ,
struct V_209 * V_209 , struct V_4 * V_36 )
{
char * V_95 , * V_37 ;
struct V_2 * V_3 ;
int V_96 ;
V_96 = - V_126 ;
V_95 = F_58 ( V_210 , V_42 ) ;
if ( ! V_95 )
goto V_49;
V_96 = - V_211 ;
V_3 = F_209 ( V_36 , V_6 ) ;
V_37 = F_210 ( V_3 -> V_55 , V_95 , V_210 ,
V_110 -> V_212 -> V_213 ) ;
F_83 ( V_3 ) ;
if ( ! V_37 )
goto V_214;
F_211 ( V_206 , V_37 ) ;
F_212 ( V_206 , '\n' ) ;
V_96 = 0 ;
V_214:
F_39 ( V_95 ) ;
V_49:
return V_96 ;
}
void F_213 ( struct V_167 * V_206 , struct V_4 * V_5 )
{
F_153 ( V_206 , L_11 ,
F_155 ( & V_5 -> V_40 ) ) ;
F_153 ( V_206 , L_12 ,
F_155 ( & V_5 -> V_40 ) ) ;
}
