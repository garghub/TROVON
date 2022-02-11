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
while ( ! F_21 ( V_7 -> V_31 , V_32 ) ) {
V_7 = F_5 ( V_7 ) ;
if ( F_22 ( ! V_7 ) ) {
F_23 ( V_30 , V_32 ) ;
return;
}
}
F_24 ( V_30 , V_7 -> V_31 , V_32 ) ;
}
static void F_25 ( struct V_1 * V_7 , T_1 * V_30 )
{
while ( ! F_26 ( V_7 -> V_33 , V_34 [ V_35 ] ) )
V_7 = F_5 ( V_7 ) ;
F_27 ( * V_30 , V_7 -> V_33 , V_34 [ V_35 ] ) ;
}
static void F_28 ( struct V_1 * V_7 ,
struct V_4 * V_36 )
{
if ( F_14 ( V_7 ) )
F_29 ( V_36 ) ;
else
F_30 ( V_36 ) ;
if ( F_15 ( V_7 ) )
F_31 ( V_36 ) ;
else
F_32 ( V_36 ) ;
}
static int F_33 ( const struct V_1 * V_37 , const struct V_1 * V_38 )
{
return F_34 ( V_37 -> V_39 , V_38 -> V_39 ) &&
F_35 ( V_37 -> V_40 , V_38 -> V_40 ) &&
F_9 ( V_37 ) <= F_9 ( V_38 ) &&
F_10 ( V_37 ) <= F_10 ( V_38 ) ;
}
static struct V_1 * F_36 ( struct V_1 * V_7 )
{
struct V_1 * V_41 ;
V_41 = F_37 ( V_7 , sizeof( * V_7 ) , V_42 ) ;
if ( ! V_41 )
return NULL ;
if ( ! F_38 ( & V_41 -> V_39 , V_42 ) )
goto V_43;
if ( ! F_38 ( & V_41 -> V_31 , V_42 ) )
goto V_44;
F_23 ( V_41 -> V_39 , V_7 -> V_39 ) ;
F_23 ( V_41 -> V_31 , V_7 -> V_31 ) ;
return V_41 ;
V_44:
F_39 ( V_41 -> V_39 ) ;
V_43:
F_40 ( V_41 ) ;
return NULL ;
}
static void F_41 ( struct V_1 * V_41 )
{
F_39 ( V_41 -> V_31 ) ;
F_39 ( V_41 -> V_39 ) ;
F_40 ( V_41 ) ;
}
static int F_42 ( struct V_1 * V_45 , struct V_1 * V_41 )
{
struct V_2 * V_3 ;
struct V_1 * V_46 , * V_47 ;
int V_25 ;
F_43 () ;
V_25 = - V_48 ;
F_44 (c, css, cur)
if ( ! F_33 ( V_46 , V_41 ) )
goto V_49;
V_25 = 0 ;
if ( V_45 == & V_50 )
goto V_49;
V_47 = F_5 ( V_45 ) ;
V_25 = - V_51 ;
if ( ! F_45 ( V_52 ) &&
! F_33 ( V_41 , V_47 ) )
goto V_49;
V_25 = - V_53 ;
F_44 (c, css, par) {
if ( ( F_9 ( V_41 ) || F_9 ( V_46 ) ) &&
V_46 != V_45 &&
F_21 ( V_41 -> V_39 , V_46 -> V_39 ) )
goto V_49;
if ( ( F_10 ( V_41 ) || F_10 ( V_46 ) ) &&
V_46 != V_45 &&
F_26 ( V_41 -> V_40 , V_46 -> V_40 ) )
goto V_49;
}
V_25 = - V_54 ;
if ( ( F_46 ( V_45 -> V_3 . V_55 ) || V_45 -> V_56 ) ) {
if ( ! F_47 ( V_45 -> V_39 ) &&
F_47 ( V_41 -> V_39 ) )
goto V_49;
if ( ! F_48 ( V_45 -> V_40 ) &&
F_48 ( V_41 -> V_40 ) )
goto V_49;
}
V_25 = - V_48 ;
if ( F_9 ( V_45 ) &&
! F_49 ( V_45 -> V_39 ,
V_41 -> V_39 ) )
goto V_49;
V_25 = 0 ;
V_49:
F_50 () ;
return V_25 ;
}
static int F_51 ( struct V_1 * V_57 , struct V_1 * V_58 )
{
return F_21 ( V_57 -> V_31 , V_58 -> V_31 ) ;
}
static void
F_52 ( struct V_59 * V_60 , struct V_1 * V_46 )
{
if ( V_60 -> V_61 < V_46 -> V_61 )
V_60 -> V_61 = V_46 -> V_61 ;
return;
}
static void F_53 ( struct V_59 * V_60 ,
struct V_1 * V_62 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
F_43 () ;
F_54 (cp, pos_css, root_cs) {
if ( F_47 ( V_63 -> V_39 ) ) {
V_64 = F_55 ( V_64 ) ;
continue;
}
if ( F_12 ( V_63 ) )
F_52 ( V_60 , V_63 ) ;
}
F_50 () ;
}
static int F_56 ( T_2 * * V_65 ,
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
if ( ! F_38 ( & V_73 , V_42 ) )
goto V_76;
F_57 ( V_73 , V_77 , V_78 ) ;
if ( F_12 ( & V_50 ) ) {
V_74 = 1 ;
V_72 = F_58 ( V_74 ) ;
if ( ! V_72 )
goto V_76;
V_60 = F_59 ( sizeof( struct V_59 ) , V_42 ) ;
if ( V_60 ) {
* V_60 = V_79 ;
F_53 ( V_60 , & V_50 ) ;
}
F_24 ( V_72 [ 0 ] , V_50 . V_31 ,
V_73 ) ;
goto V_76;
}
V_67 = F_59 ( F_60 () * sizeof( V_63 ) , V_42 ) ;
if ( ! V_67 )
goto V_76;
V_68 = 0 ;
F_43 () ;
F_54 (cp, pos_css, &top_cpuset) {
if ( V_63 == & V_50 )
continue;
if ( ! F_47 ( V_63 -> V_39 ) &&
! ( F_12 ( V_63 ) &&
F_21 ( V_63 -> V_39 , V_73 ) ) )
continue;
if ( F_12 ( V_63 ) )
V_67 [ V_68 ++ ] = V_63 ;
V_64 = F_55 ( V_64 ) ;
}
F_50 () ;
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
if ( V_82 != V_83 && F_51 ( V_57 , V_58 ) ) {
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
V_72 = F_58 ( V_74 ) ;
if ( ! V_72 )
goto V_76;
V_60 = F_59 ( V_74 * sizeof( struct V_59 ) , V_42 ) ;
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
F_61 ( L_4 ,
V_75 , V_74 , V_68 , V_69 , V_82 ) ;
V_85 -- ;
}
continue;
}
F_62 ( V_84 ) ;
if ( V_60 )
* ( V_60 + V_75 ) = V_79 ;
for ( V_70 = V_69 ; V_70 < V_68 ; V_70 ++ ) {
struct V_1 * V_58 = V_67 [ V_70 ] ;
if ( V_82 == V_58 -> V_80 ) {
F_63 ( V_84 , V_84 , V_58 -> V_31 ) ;
F_24 ( V_84 , V_84 , V_73 ) ;
if ( V_60 )
F_53 ( V_60 + V_75 , V_58 ) ;
V_58 -> V_80 = - 1 ;
}
}
V_75 ++ ;
}
F_64 ( V_75 != V_74 ) ;
V_76:
F_39 ( V_73 ) ;
F_40 ( V_67 ) ;
if ( V_72 == NULL )
V_74 = 1 ;
* V_65 = V_72 ;
* V_66 = V_60 ;
return V_74 ;
}
static void F_65 ( void )
{
struct V_59 * V_86 ;
T_2 * V_72 ;
int V_74 ;
F_66 ( & V_87 ) ;
F_67 () ;
if ( ! F_68 ( V_50 . V_31 , V_88 ) )
goto V_49;
V_74 = F_56 ( & V_72 , & V_86 ) ;
F_69 ( V_74 , V_72 , V_86 ) ;
V_49:
F_70 () ;
}
static void F_65 ( void )
{
}
void F_71 ( void )
{
F_72 ( & V_87 ) ;
F_65 () ;
F_73 ( & V_87 ) ;
}
static void F_74 ( struct V_1 * V_7 )
{
struct V_89 V_90 ;
struct V_4 * V_5 ;
F_75 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_76 ( & V_90 ) ) )
F_77 ( V_5 , V_7 -> V_31 ) ;
F_78 ( & V_90 ) ;
}
static void F_79 ( struct V_1 * V_7 , struct V_29 * V_91 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
bool V_92 = false ;
F_43 () ;
F_54 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_63 ) ;
F_24 ( V_91 , V_63 -> V_39 , V_8 -> V_31 ) ;
if ( F_45 ( V_52 ) &&
F_47 ( V_91 ) )
F_23 ( V_91 , V_8 -> V_31 ) ;
if ( F_68 ( V_91 , V_63 -> V_31 ) ) {
V_64 = F_55 ( V_64 ) ;
continue;
}
if ( ! F_80 ( & V_63 -> V_3 ) )
continue;
F_50 () ;
F_81 ( & V_93 ) ;
F_23 ( V_63 -> V_31 , V_91 ) ;
F_82 ( & V_93 ) ;
F_83 ( ! F_45 ( V_52 ) &&
! F_68 ( V_63 -> V_39 , V_63 -> V_31 ) ) ;
F_74 ( V_63 ) ;
if ( ! F_47 ( V_63 -> V_39 ) &&
F_12 ( V_63 ) )
V_92 = true ;
F_43 () ;
F_84 ( & V_63 -> V_3 ) ;
}
F_50 () ;
if ( V_92 )
F_65 () ;
}
static int F_85 ( struct V_1 * V_7 , struct V_1 * V_94 ,
const char * V_95 )
{
int V_96 ;
if ( V_7 == & V_50 )
return - V_51 ;
if ( ! * V_95 ) {
F_62 ( V_94 -> V_39 ) ;
} else {
V_96 = F_86 ( V_95 , V_94 -> V_39 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! F_34 ( V_94 -> V_39 ,
V_50 . V_39 ) )
return - V_53 ;
}
if ( F_68 ( V_7 -> V_39 , V_94 -> V_39 ) )
return 0 ;
V_96 = F_42 ( V_7 , V_94 ) ;
if ( V_96 < 0 )
return V_96 ;
F_81 ( & V_93 ) ;
F_23 ( V_7 -> V_39 , V_94 -> V_39 ) ;
F_82 ( & V_93 ) ;
F_79 ( V_7 , V_94 -> V_39 ) ;
return 0 ;
}
static void F_87 ( struct V_97 * V_98 )
{
struct V_99 * V_100 =
F_2 ( V_98 , struct V_99 , V_98 ) ;
F_88 ( V_100 -> V_101 , & V_100 -> V_102 , & V_100 -> V_103 , V_104 ) ;
F_89 ( V_100 -> V_101 ) ;
F_40 ( V_100 ) ;
}
static void F_90 ( struct V_105 * V_101 , const T_1 * V_102 ,
const T_1 * V_103 )
{
struct V_99 * V_100 ;
V_100 = F_91 ( sizeof( * V_100 ) , V_42 ) ;
if ( V_100 ) {
V_100 -> V_101 = V_101 ;
V_100 -> V_102 = * V_102 ;
V_100 -> V_103 = * V_103 ;
F_92 ( & V_100 -> V_98 , F_87 ) ;
F_93 ( V_106 , & V_100 -> V_98 ) ;
} else {
F_89 ( V_101 ) ;
}
}
static void F_94 ( void )
{
F_95 ( V_106 ) ;
}
static void F_96 ( struct V_4 * V_36 ,
T_1 * V_107 )
{
bool V_108 ;
F_97 ( V_36 ) ;
V_108 = F_6 ( V_36 ) ||
! F_26 ( * V_107 , V_36 -> V_40 ) ;
if ( V_108 ) {
F_98 () ;
F_99 ( & V_36 -> V_109 ) ;
}
F_100 ( V_36 -> V_40 , V_36 -> V_40 , * V_107 ) ;
F_101 ( V_36 , V_107 , V_110 ) ;
F_101 ( V_36 , V_107 , V_111 ) ;
V_36 -> V_40 = * V_107 ;
if ( V_108 ) {
F_102 ( & V_36 -> V_109 ) ;
F_103 () ;
}
F_104 ( V_36 ) ;
}
static void F_105 ( struct V_1 * V_7 )
{
static T_1 V_107 ;
struct V_89 V_90 ;
struct V_4 * V_5 ;
V_112 = V_7 ;
F_25 ( V_7 , & V_107 ) ;
F_75 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_76 ( & V_90 ) ) ) {
struct V_105 * V_101 ;
bool V_113 ;
F_96 ( V_5 , & V_107 ) ;
V_101 = F_106 ( V_5 ) ;
if ( ! V_101 )
continue;
V_113 = F_13 ( V_7 ) ;
F_107 ( V_101 , & V_7 -> V_40 ) ;
if ( V_113 )
F_90 ( V_101 , & V_7 -> V_114 , & V_107 ) ;
else
F_89 ( V_101 ) ;
}
F_78 ( & V_90 ) ;
V_7 -> V_114 = V_107 ;
V_112 = NULL ;
}
static void F_108 ( struct V_1 * V_7 , T_1 * V_115 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
F_43 () ;
F_54 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_63 ) ;
F_27 ( * V_115 , V_63 -> V_40 , V_8 -> V_33 ) ;
if ( F_45 ( V_52 ) &&
F_48 ( * V_115 ) )
* V_115 = V_8 -> V_33 ;
if ( F_109 ( * V_115 , V_63 -> V_33 ) ) {
V_64 = F_55 ( V_64 ) ;
continue;
}
if ( ! F_80 ( & V_63 -> V_3 ) )
continue;
F_50 () ;
F_81 ( & V_93 ) ;
V_63 -> V_33 = * V_115 ;
F_82 ( & V_93 ) ;
F_83 ( ! F_45 ( V_52 ) &&
! F_109 ( V_63 -> V_40 , V_63 -> V_33 ) ) ;
F_105 ( V_63 ) ;
F_43 () ;
F_84 ( & V_63 -> V_3 ) ;
}
F_50 () ;
}
static int F_110 ( struct V_1 * V_7 , struct V_1 * V_94 ,
const char * V_95 )
{
int V_96 ;
if ( V_7 == & V_50 ) {
V_96 = - V_51 ;
goto V_76;
}
if ( ! * V_95 ) {
F_111 ( V_94 -> V_40 ) ;
} else {
V_96 = F_112 ( V_95 , V_94 -> V_40 ) ;
if ( V_96 < 0 )
goto V_76;
if ( ! F_35 ( V_94 -> V_40 ,
V_50 . V_40 ) ) {
V_96 = - V_53 ;
goto V_76;
}
}
if ( F_109 ( V_7 -> V_40 , V_94 -> V_40 ) ) {
V_96 = 0 ;
goto V_76;
}
V_96 = F_42 ( V_7 , V_94 ) ;
if ( V_96 < 0 )
goto V_76;
F_81 ( & V_93 ) ;
V_7 -> V_40 = V_94 -> V_40 ;
F_82 ( & V_93 ) ;
F_108 ( V_7 , & V_94 -> V_40 ) ;
V_76:
return V_96 ;
}
int F_113 ( void )
{
int V_25 ;
F_43 () ;
V_25 = F_3 ( V_116 ) == V_112 ;
F_50 () ;
return V_25 ;
}
static int F_114 ( struct V_1 * V_7 , T_3 V_117 )
{
#ifdef F_115
if ( V_117 < - 1 || V_117 >= V_118 )
return - V_53 ;
#endif
if ( V_117 != V_7 -> V_61 ) {
V_7 -> V_61 = V_117 ;
if ( ! F_47 ( V_7 -> V_39 ) &&
F_12 ( V_7 ) )
F_65 () ;
}
return 0 ;
}
static void F_116 ( struct V_1 * V_7 )
{
struct V_89 V_90 ;
struct V_4 * V_5 ;
F_75 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_76 ( & V_90 ) ) )
F_28 ( V_7 , V_5 ) ;
F_78 ( & V_90 ) ;
}
static int F_117 ( T_4 V_119 , struct V_1 * V_7 ,
int V_120 )
{
struct V_1 * V_94 ;
int V_121 ;
int V_122 ;
int V_123 ;
V_94 = F_36 ( V_7 ) ;
if ( ! V_94 )
return - V_124 ;
if ( V_120 )
F_118 ( V_119 , & V_94 -> V_11 ) ;
else
F_119 ( V_119 , & V_94 -> V_11 ) ;
V_123 = F_42 ( V_7 , V_94 ) ;
if ( V_123 < 0 )
goto V_49;
V_121 = ( F_12 ( V_7 ) !=
F_12 ( V_94 ) ) ;
V_122 = ( ( F_15 ( V_7 ) != F_15 ( V_94 ) )
|| ( F_14 ( V_7 ) != F_14 ( V_94 ) ) ) ;
F_81 ( & V_93 ) ;
V_7 -> V_11 = V_94 -> V_11 ;
F_82 ( & V_93 ) ;
if ( ! F_47 ( V_94 -> V_39 ) && V_121 )
F_65 () ;
if ( V_122 )
F_116 ( V_7 ) ;
V_49:
F_41 ( V_94 ) ;
return V_123 ;
}
static void F_120 ( struct V_125 * V_126 )
{
V_126 -> V_127 = 0 ;
V_126 -> V_117 = 0 ;
V_126 -> time = 0 ;
F_121 ( & V_126 -> V_128 ) ;
}
static void F_122 ( struct V_125 * V_126 )
{
T_5 V_129 ;
T_6 V_130 ;
V_129 = F_123 () ;
V_130 = V_129 - V_126 -> time ;
if ( V_130 == 0 )
return;
V_130 = F_124 ( V_131 , V_130 ) ;
while ( V_130 -- > 0 )
V_126 -> V_117 = ( V_132 * V_126 -> V_117 ) / V_133 ;
V_126 -> time = V_129 ;
V_126 -> V_117 += ( ( V_133 - V_132 ) * V_126 -> V_127 ) / V_133 ;
V_126 -> V_127 = 0 ;
}
static void F_125 ( struct V_125 * V_126 )
{
F_126 ( & V_126 -> V_128 ) ;
F_122 ( V_126 ) ;
V_126 -> V_127 = F_124 ( V_134 , V_126 -> V_127 + V_133 ) ;
F_127 ( & V_126 -> V_128 ) ;
}
static int F_128 ( struct V_125 * V_126 )
{
int V_117 ;
F_126 ( & V_126 -> V_128 ) ;
F_122 ( V_126 ) ;
V_117 = V_126 -> V_117 ;
F_127 ( & V_126 -> V_128 ) ;
return V_117 ;
}
static int F_129 ( struct V_135 * V_136 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
int V_25 ;
V_137 = F_3 ( F_130 ( V_136 , & V_3 ) ) ;
V_7 = F_1 ( V_3 ) ;
F_72 ( & V_87 ) ;
V_25 = - V_54 ;
if ( ! F_45 ( V_52 ) &&
( F_47 ( V_7 -> V_39 ) || F_48 ( V_7 -> V_40 ) ) )
goto V_138;
F_131 (task, css, tset) {
V_25 = F_132 ( V_5 , V_7 -> V_39 ) ;
if ( V_25 )
goto V_138;
V_25 = F_133 ( V_5 ) ;
if ( V_25 )
goto V_138;
}
V_7 -> V_56 ++ ;
V_25 = 0 ;
V_138:
F_73 ( & V_87 ) ;
return V_25 ;
}
static void F_134 ( struct V_135 * V_136 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
F_130 ( V_136 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_72 ( & V_87 ) ;
F_1 ( V_3 ) -> V_56 -- ;
F_73 ( & V_87 ) ;
}
static void F_135 ( struct V_135 * V_136 )
{
static T_1 V_139 ;
struct V_4 * V_5 ;
struct V_4 * V_140 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_1 * V_141 = V_137 ;
F_130 ( V_136 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_72 ( & V_87 ) ;
if ( V_7 == & V_50 )
F_23 ( V_142 , V_77 ) ;
else
F_20 ( V_7 , V_142 ) ;
F_25 ( V_7 , & V_139 ) ;
F_131 (task, css, tset) {
F_136 ( F_77 ( V_5 , V_142 ) ) ;
F_96 ( V_5 , & V_139 ) ;
F_28 ( V_7 , V_5 ) ;
}
V_139 = V_7 -> V_33 ;
F_137 (leader, css, tset) {
struct V_105 * V_101 = F_106 ( V_140 ) ;
if ( V_101 ) {
F_107 ( V_101 , & V_139 ) ;
if ( F_13 ( V_7 ) )
F_90 ( V_101 , & V_141 -> V_114 ,
& V_139 ) ;
else
F_89 ( V_101 ) ;
}
}
V_7 -> V_114 = V_139 ;
V_7 -> V_56 -- ;
if ( ! V_7 -> V_56 )
F_138 ( & V_143 ) ;
F_73 ( & V_87 ) ;
}
static int F_139 ( struct V_2 * V_3 , struct V_144 * V_145 ,
T_7 V_117 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_145 -> V_146 ;
int V_96 = 0 ;
F_72 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) ) {
V_96 = - V_26 ;
goto V_138;
}
switch ( type ) {
case V_147 :
V_96 = F_117 ( V_12 , V_7 , V_117 ) ;
break;
case V_148 :
V_96 = F_117 ( V_13 , V_7 , V_117 ) ;
break;
case V_149 :
V_96 = F_117 ( V_14 , V_7 , V_117 ) ;
break;
case V_150 :
V_96 = F_117 ( V_15 , V_7 , V_117 ) ;
break;
case V_151 :
V_96 = F_117 ( V_16 , V_7 , V_117 ) ;
break;
case V_152 :
V_153 = ! ! V_117 ;
break;
case V_154 :
V_96 = F_117 ( V_17 , V_7 , V_117 ) ;
break;
case V_155 :
V_96 = F_117 ( V_18 , V_7 , V_117 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
V_138:
F_73 ( & V_87 ) ;
return V_96 ;
}
static int F_140 ( struct V_2 * V_3 , struct V_144 * V_145 ,
T_3 V_117 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_145 -> V_146 ;
int V_96 = - V_26 ;
F_72 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) )
goto V_138;
switch ( type ) {
case V_156 :
V_96 = F_114 ( V_7 , V_117 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
V_138:
F_73 ( & V_87 ) ;
return V_96 ;
}
static T_9 F_141 ( struct V_157 * V_158 ,
char * V_95 , T_10 V_159 , T_11 V_160 )
{
struct V_1 * V_7 = F_1 ( F_142 ( V_158 ) ) ;
struct V_1 * V_94 ;
int V_96 = - V_26 ;
V_95 = F_143 ( V_95 ) ;
F_144 ( & V_7 -> V_3 ) ;
F_145 ( V_158 -> V_161 ) ;
F_146 ( & V_162 ) ;
F_72 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) )
goto V_138;
V_94 = F_36 ( V_7 ) ;
if ( ! V_94 ) {
V_96 = - V_124 ;
goto V_138;
}
switch ( F_147 ( V_158 ) -> V_146 ) {
case V_163 :
V_96 = F_85 ( V_7 , V_94 , V_95 ) ;
break;
case V_164 :
V_96 = F_110 ( V_7 , V_94 , V_95 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
F_41 ( V_94 ) ;
V_138:
F_73 ( & V_87 ) ;
F_148 ( V_158 -> V_161 ) ;
F_84 ( & V_7 -> V_3 ) ;
F_95 ( V_106 ) ;
return V_96 ? : V_159 ;
}
static int F_149 ( struct V_165 * V_166 , void * V_167 )
{
struct V_1 * V_7 = F_1 ( F_150 ( V_166 ) ) ;
T_8 type = F_151 ( V_166 ) -> V_146 ;
int V_25 = 0 ;
F_81 ( & V_93 ) ;
switch ( type ) {
case V_163 :
F_152 ( V_166 , L_5 , F_153 ( V_7 -> V_39 ) ) ;
break;
case V_164 :
F_152 ( V_166 , L_5 , F_154 ( & V_7 -> V_40 ) ) ;
break;
case V_168 :
F_152 ( V_166 , L_5 , F_153 ( V_7 -> V_31 ) ) ;
break;
case V_169 :
F_152 ( V_166 , L_5 , F_154 ( & V_7 -> V_33 ) ) ;
break;
default:
V_25 = - V_53 ;
}
F_82 ( & V_93 ) ;
return V_25 ;
}
static T_7 F_155 ( struct V_2 * V_3 , struct V_144 * V_145 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_145 -> V_146 ;
switch ( type ) {
case V_147 :
return F_9 ( V_7 ) ;
case V_148 :
return F_10 ( V_7 ) ;
case V_149 :
return F_11 ( V_7 ) ;
case V_150 :
return F_12 ( V_7 ) ;
case V_151 :
return F_13 ( V_7 ) ;
case V_152 :
return V_153 ;
case V_170 :
return F_128 ( & V_7 -> V_125 ) ;
case V_154 :
return F_14 ( V_7 ) ;
case V_155 :
return F_15 ( V_7 ) ;
default:
F_156 () ;
}
return 0 ;
}
static T_3 F_157 ( struct V_2 * V_3 , struct V_144 * V_145 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_145 -> V_146 ;
switch ( type ) {
case V_156 :
return V_7 -> V_61 ;
default:
F_156 () ;
}
return 0 ;
}
static struct V_2 *
F_158 ( struct V_2 * V_171 )
{
struct V_1 * V_7 ;
if ( ! V_171 )
return & V_50 . V_3 ;
V_7 = F_91 ( sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 )
return F_18 ( - V_124 ) ;
if ( ! F_38 ( & V_7 -> V_39 , V_42 ) )
goto V_43;
if ( ! F_38 ( & V_7 -> V_31 , V_42 ) )
goto V_44;
F_118 ( V_15 , & V_7 -> V_11 ) ;
F_62 ( V_7 -> V_39 ) ;
F_111 ( V_7 -> V_40 ) ;
F_62 ( V_7 -> V_31 ) ;
F_111 ( V_7 -> V_33 ) ;
F_120 ( & V_7 -> V_125 ) ;
V_7 -> V_61 = - 1 ;
return & V_7 -> V_3 ;
V_44:
F_39 ( V_7 -> V_39 ) ;
V_43:
F_40 ( V_7 ) ;
return F_18 ( - V_124 ) ;
}
static int F_159 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_8 = F_5 ( V_7 ) ;
struct V_1 * V_172 ;
struct V_2 * V_64 ;
if ( ! V_8 )
return 0 ;
F_72 ( & V_87 ) ;
F_118 ( V_10 , & V_7 -> V_11 ) ;
if ( F_14 ( V_8 ) )
F_118 ( V_17 , & V_7 -> V_11 ) ;
if ( F_15 ( V_8 ) )
F_118 ( V_18 , & V_7 -> V_11 ) ;
F_160 () ;
F_81 ( & V_93 ) ;
if ( F_45 ( V_52 ) ) {
F_23 ( V_7 -> V_31 , V_8 -> V_31 ) ;
V_7 -> V_33 = V_8 -> V_33 ;
}
F_82 ( & V_93 ) ;
if ( ! F_8 ( V_173 , & V_3 -> V_55 -> V_11 ) )
goto V_138;
F_43 () ;
F_44 (tmp_cs, pos_css, parent) {
if ( F_10 ( V_172 ) || F_9 ( V_172 ) ) {
F_50 () ;
goto V_138;
}
}
F_50 () ;
F_81 ( & V_93 ) ;
V_7 -> V_40 = V_8 -> V_40 ;
V_7 -> V_33 = V_8 -> V_40 ;
F_23 ( V_7 -> V_39 , V_8 -> V_39 ) ;
F_23 ( V_7 -> V_31 , V_8 -> V_39 ) ;
F_82 ( & V_93 ) ;
V_138:
F_73 ( & V_87 ) ;
return 0 ;
}
static void F_161 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_72 ( & V_87 ) ;
if ( F_12 ( V_7 ) )
F_117 ( V_15 , V_7 , 0 ) ;
F_162 () ;
F_119 ( V_10 , & V_7 -> V_11 ) ;
F_73 ( & V_87 ) ;
}
static void F_163 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_39 ( V_7 -> V_31 ) ;
F_39 ( V_7 -> V_39 ) ;
F_40 ( V_7 ) ;
}
static void F_164 ( struct V_2 * V_174 )
{
F_72 ( & V_87 ) ;
F_81 ( & V_93 ) ;
if ( F_45 ( V_52 ) ) {
F_23 ( V_50 . V_39 , V_77 ) ;
V_50 . V_40 = V_175 ;
} else {
F_23 ( V_50 . V_39 ,
V_50 . V_31 ) ;
V_50 . V_40 = V_50 . V_33 ;
}
F_82 ( & V_93 ) ;
F_73 ( & V_87 ) ;
}
static void F_165 ( struct V_4 * V_5 )
{
if ( F_166 ( V_5 , V_6 ) )
return;
F_77 ( V_5 , & V_116 -> V_39 ) ;
V_5 -> V_40 = V_116 -> V_40 ;
}
int T_12 F_167 ( void )
{
int V_123 = 0 ;
if ( ! F_38 ( & V_50 . V_39 , V_42 ) )
F_156 () ;
if ( ! F_38 ( & V_50 . V_31 , V_42 ) )
F_156 () ;
F_168 ( V_50 . V_39 ) ;
F_169 ( V_50 . V_40 ) ;
F_168 ( V_50 . V_31 ) ;
F_169 ( V_50 . V_33 ) ;
F_120 ( & V_50 . V_125 ) ;
F_118 ( V_15 , & V_50 . V_11 ) ;
V_50 . V_61 = - 1 ;
V_123 = F_170 ( & V_176 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( ! F_38 ( & V_142 , V_42 ) )
F_156 () ;
return 0 ;
}
static void F_171 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_5 ( V_7 ) ;
while ( F_47 ( V_8 -> V_39 ) ||
F_48 ( V_8 -> V_40 ) )
V_8 = F_5 ( V_8 ) ;
if ( F_172 ( V_8 -> V_3 . V_55 , V_7 -> V_3 . V_55 ) ) {
F_173 ( L_6 ) ;
F_174 ( V_7 -> V_3 . V_55 ) ;
F_175 ( L_7 ) ;
}
}
static void
F_176 ( struct V_1 * V_7 ,
struct V_29 * V_91 , T_1 * V_115 ,
bool V_177 , bool V_178 )
{
bool V_179 ;
F_81 ( & V_93 ) ;
F_23 ( V_7 -> V_39 , V_91 ) ;
F_23 ( V_7 -> V_31 , V_91 ) ;
V_7 -> V_40 = * V_115 ;
V_7 -> V_33 = * V_115 ;
F_82 ( & V_93 ) ;
if ( V_177 && ! F_47 ( V_7 -> V_39 ) )
F_74 ( V_7 ) ;
if ( V_178 && ! F_48 ( V_7 -> V_40 ) )
F_105 ( V_7 ) ;
V_179 = F_47 ( V_7 -> V_39 ) ||
F_48 ( V_7 -> V_40 ) ;
F_73 ( & V_87 ) ;
if ( V_179 )
F_171 ( V_7 ) ;
F_72 ( & V_87 ) ;
}
static void
F_177 ( struct V_1 * V_7 ,
struct V_29 * V_91 , T_1 * V_115 ,
bool V_177 , bool V_178 )
{
if ( F_47 ( V_91 ) )
F_23 ( V_91 , F_5 ( V_7 ) -> V_31 ) ;
if ( F_48 ( * V_115 ) )
* V_115 = F_5 ( V_7 ) -> V_33 ;
F_81 ( & V_93 ) ;
F_23 ( V_7 -> V_31 , V_91 ) ;
V_7 -> V_33 = * V_115 ;
F_82 ( & V_93 ) ;
if ( V_177 )
F_74 ( V_7 ) ;
if ( V_178 )
F_105 ( V_7 ) ;
}
static void F_178 ( struct V_1 * V_7 )
{
static T_13 V_91 ;
static T_1 V_115 ;
bool V_177 ;
bool V_178 ;
V_180:
F_179 ( V_143 , V_7 -> V_56 == 0 ) ;
F_72 ( & V_87 ) ;
if ( V_7 -> V_56 ) {
F_73 ( & V_87 ) ;
goto V_180;
}
F_24 ( & V_91 , V_7 -> V_39 , F_5 ( V_7 ) -> V_31 ) ;
F_27 ( V_115 , V_7 -> V_40 , F_5 ( V_7 ) -> V_33 ) ;
V_177 = ! F_68 ( & V_91 , V_7 -> V_31 ) ;
V_178 = ! F_109 ( V_115 , V_7 -> V_33 ) ;
if ( F_45 ( V_52 ) )
F_177 ( V_7 , & V_91 , & V_115 ,
V_177 , V_178 ) ;
else
F_176 ( V_7 , & V_91 , & V_115 ,
V_177 , V_178 ) ;
F_73 ( & V_87 ) ;
}
static void F_180 ( struct V_97 * V_98 )
{
static T_13 V_91 ;
static T_1 V_115 ;
bool V_177 , V_178 ;
bool V_181 = F_45 ( V_52 ) ;
F_72 ( & V_87 ) ;
F_23 ( & V_91 , V_88 ) ;
V_115 = V_34 [ V_35 ] ;
V_177 = ! F_68 ( V_50 . V_31 , & V_91 ) ;
V_178 = ! F_109 ( V_50 . V_33 , V_115 ) ;
if ( V_177 ) {
F_81 ( & V_93 ) ;
if ( ! V_181 )
F_23 ( V_50 . V_39 , & V_91 ) ;
F_23 ( V_50 . V_31 , & V_91 ) ;
F_82 ( & V_93 ) ;
}
if ( V_178 ) {
F_81 ( & V_93 ) ;
if ( ! V_181 )
V_50 . V_40 = V_115 ;
V_50 . V_33 = V_115 ;
F_82 ( & V_93 ) ;
F_105 ( & V_50 ) ;
}
F_73 ( & V_87 ) ;
if ( V_177 || V_178 ) {
struct V_1 * V_7 ;
struct V_2 * V_64 ;
F_43 () ;
F_54 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_50 || ! F_80 ( & V_7 -> V_3 ) )
continue;
F_50 () ;
F_178 ( V_7 ) ;
F_43 () ;
F_84 ( & V_7 -> V_3 ) ;
}
F_50 () ;
}
if ( V_177 )
F_71 () ;
}
void F_181 ( bool V_182 )
{
F_69 ( 1 , NULL , NULL ) ;
F_182 ( & V_162 ) ;
}
static int F_183 ( struct V_183 * V_184 ,
unsigned long V_185 , void * V_186 )
{
F_182 ( & V_162 ) ;
return V_187 ;
}
void T_12 F_184 ( void )
{
F_23 ( V_50 . V_39 , V_88 ) ;
V_50 . V_40 = V_34 [ V_35 ] ;
V_50 . V_114 = V_50 . V_40 ;
F_23 ( V_50 . V_31 , V_88 ) ;
V_50 . V_33 = V_34 [ V_35 ] ;
F_185 ( & V_188 ) ;
V_106 = F_186 ( L_8 , 0 ) ;
F_64 ( ! V_106 ) ;
}
void F_187 ( struct V_4 * V_36 , struct V_29 * V_30 )
{
unsigned long V_11 ;
F_188 ( & V_93 , V_11 ) ;
F_43 () ;
F_20 ( F_3 ( V_36 ) , V_30 ) ;
F_50 () ;
F_189 ( & V_93 , V_11 ) ;
}
void F_190 ( struct V_4 * V_36 )
{
F_43 () ;
F_191 ( V_36 , F_3 ( V_36 ) -> V_31 ) ;
F_50 () ;
}
void T_12 F_192 ( void )
{
F_169 ( V_116 -> V_40 ) ;
}
T_1 F_193 ( struct V_4 * V_36 )
{
T_1 V_189 ;
unsigned long V_11 ;
F_188 ( & V_93 , V_11 ) ;
F_43 () ;
F_25 ( F_3 ( V_36 ) , & V_189 ) ;
F_50 () ;
F_189 ( & V_93 , V_11 ) ;
return V_189 ;
}
int F_194 ( T_1 * V_190 )
{
return F_26 ( * V_190 , V_116 -> V_40 ) ;
}
static struct V_1 * F_195 ( struct V_1 * V_7 )
{
while ( ! ( F_10 ( V_7 ) || F_11 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
bool F_196 ( int V_191 , T_14 V_192 )
{
struct V_1 * V_7 ;
int V_193 ;
unsigned long V_11 ;
if ( F_197 () )
return true ;
if ( F_198 ( V_191 , V_116 -> V_40 ) )
return true ;
if ( F_22 ( F_199 ( V_194 ) ) )
return true ;
if ( V_192 & V_195 )
return false ;
if ( V_116 -> V_11 & V_196 )
return true ;
F_188 ( & V_93 , V_11 ) ;
F_43 () ;
V_7 = F_195 ( F_3 ( V_116 ) ) ;
V_193 = F_198 ( V_191 , V_7 -> V_40 ) ;
F_50 () ;
F_189 ( & V_93 , V_11 ) ;
return V_193 ;
}
static int F_200 ( int * V_197 )
{
return * V_197 = F_201 ( * V_197 , V_116 -> V_40 ) ;
}
int F_202 ( void )
{
if ( V_116 -> V_198 == V_199 )
V_116 -> V_198 =
F_203 ( & V_116 -> V_40 ) ;
return F_200 ( & V_116 -> V_198 ) ;
}
int F_204 ( void )
{
if ( V_116 -> V_200 == V_199 )
V_116 -> V_200 =
F_203 ( & V_116 -> V_40 ) ;
return F_200 ( & V_116 -> V_200 ) ;
}
int F_205 ( const struct V_4 * V_201 ,
const struct V_4 * V_202 )
{
return F_26 ( V_201 -> V_40 , V_202 -> V_40 ) ;
}
void F_206 ( void )
{
struct V_55 * V_203 ;
F_43 () ;
V_203 = F_3 ( V_116 ) -> V_3 . V_55 ;
F_207 ( L_9 , V_116 -> V_204 ) ;
F_174 ( V_203 ) ;
F_175 ( L_10 ,
F_154 ( & V_116 -> V_40 ) ) ;
F_50 () ;
}
void F_208 ( void )
{
F_43 () ;
F_125 ( & F_3 ( V_116 ) -> V_125 ) ;
F_50 () ;
}
int F_209 ( struct V_165 * V_205 , struct V_206 * V_207 ,
struct V_208 * V_208 , struct V_4 * V_36 )
{
char * V_95 ;
struct V_2 * V_3 ;
int V_96 ;
V_96 = - V_124 ;
V_95 = F_59 ( V_209 , V_42 ) ;
if ( ! V_95 )
goto V_49;
V_3 = F_210 ( V_36 , V_6 ) ;
V_96 = F_211 ( V_3 -> V_55 , V_95 , V_209 ,
V_116 -> V_210 -> V_211 ) ;
F_84 ( V_3 ) ;
if ( V_96 >= V_209 )
V_96 = - V_212 ;
if ( V_96 < 0 )
goto V_213;
F_212 ( V_205 , V_95 ) ;
F_213 ( V_205 , '\n' ) ;
V_96 = 0 ;
V_213:
F_40 ( V_95 ) ;
V_49:
return V_96 ;
}
void F_214 ( struct V_165 * V_205 , struct V_4 * V_5 )
{
F_152 ( V_205 , L_11 ,
F_154 ( & V_5 -> V_40 ) ) ;
F_152 ( V_205 , L_12 ,
F_154 ( & V_5 -> V_40 ) ) ;
}
