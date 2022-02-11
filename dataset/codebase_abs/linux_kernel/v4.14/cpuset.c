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
static inline bool F_7 ( struct V_1 * V_7 )
{
return F_8 ( V_10 , & V_7 -> V_11 ) && ! F_9 ( & V_7 -> V_3 ) ;
}
static inline int F_10 ( const struct V_1 * V_7 )
{
return F_8 ( V_12 , & V_7 -> V_11 ) ;
}
static inline int F_11 ( const struct V_1 * V_7 )
{
return F_8 ( V_13 , & V_7 -> V_11 ) ;
}
static inline int F_12 ( const struct V_1 * V_7 )
{
return F_8 ( V_14 , & V_7 -> V_11 ) ;
}
static inline int F_13 ( const struct V_1 * V_7 )
{
return F_8 ( V_15 , & V_7 -> V_11 ) ;
}
static inline int F_14 ( const struct V_1 * V_7 )
{
return F_8 ( V_16 , & V_7 -> V_11 ) ;
}
static inline int F_15 ( const struct V_1 * V_7 )
{
return F_8 ( V_17 , & V_7 -> V_11 ) ;
}
static inline int F_16 ( const struct V_1 * V_7 )
{
return F_8 ( V_18 , & V_7 -> V_11 ) ;
}
static inline bool F_17 ( void )
{
return F_18 ( V_19 ) ||
( V_19 . V_20 -> V_11 & V_21 ) ;
}
static struct V_22 * F_19 ( struct V_23 * V_24 ,
int V_11 , const char * V_25 , void * V_26 )
{
struct V_23 * V_27 = F_20 ( L_1 ) ;
struct V_22 * V_28 = F_21 ( - V_29 ) ;
if ( V_27 ) {
char V_30 [] =
L_2
L_3 ;
V_28 = V_27 -> V_31 ( V_27 , V_11 ,
V_25 , V_30 ) ;
F_22 ( V_27 ) ;
}
return V_28 ;
}
static void F_23 ( struct V_1 * V_7 , struct V_32 * V_33 )
{
while ( ! F_24 ( V_7 -> V_34 , V_35 ) ) {
V_7 = F_5 ( V_7 ) ;
if ( F_25 ( ! V_7 ) ) {
F_26 ( V_33 , V_35 ) ;
return;
}
}
F_27 ( V_33 , V_7 -> V_34 , V_35 ) ;
}
static void F_28 ( struct V_1 * V_7 , T_1 * V_33 )
{
while ( ! F_29 ( V_7 -> V_36 , V_37 [ V_38 ] ) )
V_7 = F_5 ( V_7 ) ;
F_30 ( * V_33 , V_7 -> V_36 , V_37 [ V_38 ] ) ;
}
static void F_31 ( struct V_1 * V_7 ,
struct V_4 * V_39 )
{
if ( F_15 ( V_7 ) )
F_32 ( V_39 ) ;
else
F_33 ( V_39 ) ;
if ( F_16 ( V_7 ) )
F_34 ( V_39 ) ;
else
F_35 ( V_39 ) ;
}
static int F_36 ( const struct V_1 * V_40 , const struct V_1 * V_41 )
{
return F_37 ( V_40 -> V_42 , V_41 -> V_42 ) &&
F_38 ( V_40 -> V_43 , V_41 -> V_43 ) &&
F_10 ( V_40 ) <= F_10 ( V_41 ) &&
F_11 ( V_40 ) <= F_11 ( V_41 ) ;
}
static struct V_1 * F_39 ( struct V_1 * V_7 )
{
struct V_1 * V_44 ;
V_44 = F_40 ( V_7 , sizeof( * V_7 ) , V_45 ) ;
if ( ! V_44 )
return NULL ;
if ( ! F_41 ( & V_44 -> V_42 , V_45 ) )
goto V_46;
if ( ! F_41 ( & V_44 -> V_34 , V_45 ) )
goto V_47;
F_26 ( V_44 -> V_42 , V_7 -> V_42 ) ;
F_26 ( V_44 -> V_34 , V_7 -> V_34 ) ;
return V_44 ;
V_47:
F_42 ( V_44 -> V_42 ) ;
V_46:
F_43 ( V_44 ) ;
return NULL ;
}
static void F_44 ( struct V_1 * V_44 )
{
F_42 ( V_44 -> V_34 ) ;
F_42 ( V_44 -> V_42 ) ;
F_43 ( V_44 ) ;
}
static int F_45 ( struct V_1 * V_48 , struct V_1 * V_44 )
{
struct V_2 * V_3 ;
struct V_1 * V_49 , * V_50 ;
int V_28 ;
F_46 () ;
V_28 = - V_51 ;
F_47 (c, css, cur)
if ( ! F_36 ( V_49 , V_44 ) )
goto V_52;
V_28 = 0 ;
if ( V_48 == & V_53 )
goto V_52;
V_50 = F_5 ( V_48 ) ;
V_28 = - V_54 ;
if ( ! F_17 () && ! F_36 ( V_44 , V_50 ) )
goto V_52;
V_28 = - V_55 ;
F_47 (c, css, par) {
if ( ( F_10 ( V_44 ) || F_10 ( V_49 ) ) &&
V_49 != V_48 &&
F_24 ( V_44 -> V_42 , V_49 -> V_42 ) )
goto V_52;
if ( ( F_11 ( V_44 ) || F_11 ( V_49 ) ) &&
V_49 != V_48 &&
F_29 ( V_44 -> V_43 , V_49 -> V_43 ) )
goto V_52;
}
V_28 = - V_56 ;
if ( ( F_48 ( V_48 -> V_3 . V_57 ) || V_48 -> V_58 ) ) {
if ( ! F_49 ( V_48 -> V_42 ) &&
F_49 ( V_44 -> V_42 ) )
goto V_52;
if ( ! F_50 ( V_48 -> V_43 ) &&
F_50 ( V_44 -> V_43 ) )
goto V_52;
}
V_28 = - V_51 ;
if ( F_10 ( V_48 ) &&
! F_51 ( V_48 -> V_42 ,
V_44 -> V_42 ) )
goto V_52;
V_28 = 0 ;
V_52:
F_52 () ;
return V_28 ;
}
static int F_53 ( struct V_1 * V_59 , struct V_1 * V_60 )
{
return F_24 ( V_59 -> V_34 , V_60 -> V_34 ) ;
}
static void
F_54 ( struct V_61 * V_62 , struct V_1 * V_49 )
{
if ( V_62 -> V_63 < V_49 -> V_63 )
V_62 -> V_63 = V_49 -> V_63 ;
return;
}
static void F_55 ( struct V_61 * V_62 ,
struct V_1 * V_64 )
{
struct V_1 * V_65 ;
struct V_2 * V_66 ;
F_46 () ;
F_56 (cp, pos_css, root_cs) {
if ( F_49 ( V_65 -> V_42 ) ) {
V_66 = F_57 ( V_66 ) ;
continue;
}
if ( F_13 ( V_65 ) )
F_54 ( V_62 , V_65 ) ;
}
F_52 () ;
}
static inline int F_58 ( void )
{
return F_59 ( & V_67 . V_68 ) + 1 ;
}
static int F_60 ( T_2 * * V_69 ,
struct V_61 * * V_70 )
{
struct V_1 * V_65 ;
struct V_1 * * V_71 ;
int V_72 ;
int V_73 , V_74 , V_75 ;
T_2 * V_76 ;
T_2 V_77 ;
struct V_61 * V_62 ;
int V_78 = 0 ;
int V_79 ;
struct V_2 * V_66 ;
V_76 = NULL ;
V_62 = NULL ;
V_71 = NULL ;
if ( ! F_41 ( & V_77 , V_45 ) )
goto V_80;
F_61 ( V_77 , V_81 , V_82 ) ;
if ( F_13 ( & V_53 ) ) {
V_78 = 1 ;
V_76 = F_62 ( V_78 ) ;
if ( ! V_76 )
goto V_80;
V_62 = F_63 ( sizeof( struct V_61 ) , V_45 ) ;
if ( V_62 ) {
* V_62 = V_83 ;
F_55 ( V_62 , & V_53 ) ;
}
F_27 ( V_76 [ 0 ] , V_53 . V_34 ,
V_77 ) ;
goto V_80;
}
V_71 = F_63 ( F_58 () * sizeof( V_65 ) , V_45 ) ;
if ( ! V_71 )
goto V_80;
V_72 = 0 ;
F_46 () ;
F_56 (cp, pos_css, &top_cpuset) {
if ( V_65 == & V_53 )
continue;
if ( ! F_49 ( V_65 -> V_42 ) &&
! ( F_13 ( V_65 ) &&
F_24 ( V_65 -> V_42 , V_77 ) ) )
continue;
if ( F_13 ( V_65 ) )
V_71 [ V_72 ++ ] = V_65 ;
V_66 = F_57 ( V_66 ) ;
}
F_52 () ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ )
V_71 [ V_73 ] -> V_84 = V_73 ;
V_78 = V_72 ;
V_85:
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
struct V_1 * V_59 = V_71 [ V_73 ] ;
int V_86 = V_59 -> V_84 ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
struct V_1 * V_60 = V_71 [ V_74 ] ;
int V_87 = V_60 -> V_84 ;
if ( V_86 != V_87 && F_53 ( V_59 , V_60 ) ) {
for ( V_75 = 0 ; V_75 < V_72 ; V_75 ++ ) {
struct V_1 * V_49 = V_71 [ V_75 ] ;
if ( V_49 -> V_84 == V_87 )
V_49 -> V_84 = V_86 ;
}
V_78 -- ;
goto V_85;
}
}
}
V_76 = F_62 ( V_78 ) ;
if ( ! V_76 )
goto V_80;
V_62 = F_63 ( V_78 * sizeof( struct V_61 ) , V_45 ) ;
for ( V_79 = 0 , V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
struct V_1 * V_59 = V_71 [ V_73 ] ;
struct V_32 * V_88 ;
int V_86 = V_59 -> V_84 ;
if ( V_86 < 0 ) {
continue;
}
V_88 = V_76 [ V_79 ] ;
if ( V_79 == V_78 ) {
static int V_89 = 10 ;
if ( V_89 ) {
F_64 ( L_4 ,
V_79 , V_78 , V_72 , V_73 , V_86 ) ;
V_89 -- ;
}
continue;
}
F_65 ( V_88 ) ;
if ( V_62 )
* ( V_62 + V_79 ) = V_83 ;
for ( V_74 = V_73 ; V_74 < V_72 ; V_74 ++ ) {
struct V_1 * V_60 = V_71 [ V_74 ] ;
if ( V_86 == V_60 -> V_84 ) {
F_66 ( V_88 , V_88 , V_60 -> V_34 ) ;
F_27 ( V_88 , V_88 , V_77 ) ;
if ( V_62 )
F_55 ( V_62 + V_79 , V_60 ) ;
V_60 -> V_84 = - 1 ;
}
}
V_79 ++ ;
}
F_67 ( V_79 != V_78 ) ;
V_80:
F_42 ( V_77 ) ;
F_43 ( V_71 ) ;
if ( V_76 == NULL )
V_78 = 1 ;
* V_69 = V_76 ;
* V_70 = V_62 ;
return V_78 ;
}
static void F_68 ( void )
{
struct V_61 * V_90 ;
T_2 * V_76 ;
int V_78 ;
F_69 ( & V_91 ) ;
F_70 () ;
if ( ! F_71 ( V_53 . V_34 , V_92 ) )
goto V_52;
V_78 = F_60 ( & V_76 , & V_90 ) ;
F_72 ( V_78 , V_76 , V_90 ) ;
V_52:
F_73 () ;
}
static void F_68 ( void )
{
}
void F_74 ( void )
{
F_75 ( & V_91 ) ;
F_68 () ;
F_76 ( & V_91 ) ;
}
static void F_77 ( struct V_1 * V_7 )
{
struct V_93 V_94 ;
struct V_4 * V_5 ;
F_78 ( & V_7 -> V_3 , 0 , & V_94 ) ;
while ( ( V_5 = F_79 ( & V_94 ) ) )
F_80 ( V_5 , V_7 -> V_34 ) ;
F_81 ( & V_94 ) ;
}
static void F_82 ( struct V_1 * V_7 , struct V_32 * V_95 )
{
struct V_1 * V_65 ;
struct V_2 * V_66 ;
bool V_96 = false ;
F_46 () ;
F_56 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_65 ) ;
F_27 ( V_95 , V_65 -> V_42 , V_8 -> V_34 ) ;
if ( F_17 () && F_49 ( V_95 ) )
F_26 ( V_95 , V_8 -> V_34 ) ;
if ( F_71 ( V_95 , V_65 -> V_34 ) ) {
V_66 = F_57 ( V_66 ) ;
continue;
}
if ( ! F_83 ( & V_65 -> V_3 ) )
continue;
F_52 () ;
F_84 ( & V_97 ) ;
F_26 ( V_65 -> V_34 , V_95 ) ;
F_85 ( & V_97 ) ;
F_86 ( ! F_17 () &&
! F_71 ( V_65 -> V_42 , V_65 -> V_34 ) ) ;
F_77 ( V_65 ) ;
if ( ! F_49 ( V_65 -> V_42 ) &&
F_13 ( V_65 ) )
V_96 = true ;
F_46 () ;
F_87 ( & V_65 -> V_3 ) ;
}
F_52 () ;
if ( V_96 )
F_68 () ;
}
static int F_88 ( struct V_1 * V_7 , struct V_1 * V_98 ,
const char * V_99 )
{
int V_100 ;
if ( V_7 == & V_53 )
return - V_54 ;
if ( ! * V_99 ) {
F_65 ( V_98 -> V_42 ) ;
} else {
V_100 = F_89 ( V_99 , V_98 -> V_42 ) ;
if ( V_100 < 0 )
return V_100 ;
if ( ! F_37 ( V_98 -> V_42 ,
V_53 . V_42 ) )
return - V_55 ;
}
if ( F_71 ( V_7 -> V_42 , V_98 -> V_42 ) )
return 0 ;
V_100 = F_45 ( V_7 , V_98 ) ;
if ( V_100 < 0 )
return V_100 ;
F_84 ( & V_97 ) ;
F_26 ( V_7 -> V_42 , V_98 -> V_42 ) ;
F_85 ( & V_97 ) ;
F_82 ( V_7 , V_98 -> V_42 ) ;
return 0 ;
}
static void F_90 ( struct V_101 * V_102 )
{
struct V_103 * V_104 =
F_2 ( V_102 , struct V_103 , V_102 ) ;
F_91 ( V_104 -> V_105 , & V_104 -> V_106 , & V_104 -> V_107 , V_108 ) ;
F_92 ( V_104 -> V_105 ) ;
F_43 ( V_104 ) ;
}
static void F_93 ( struct V_109 * V_105 , const T_1 * V_106 ,
const T_1 * V_107 )
{
struct V_103 * V_104 ;
V_104 = F_94 ( sizeof( * V_104 ) , V_45 ) ;
if ( V_104 ) {
V_104 -> V_105 = V_105 ;
V_104 -> V_106 = * V_106 ;
V_104 -> V_107 = * V_107 ;
F_95 ( & V_104 -> V_102 , F_90 ) ;
F_96 ( V_110 , & V_104 -> V_102 ) ;
} else {
F_92 ( V_105 ) ;
}
}
static void F_97 ( void )
{
F_98 ( V_110 ) ;
}
static void F_99 ( struct V_4 * V_39 ,
T_1 * V_111 )
{
F_100 ( V_39 ) ;
F_101 () ;
F_102 ( & V_39 -> V_112 ) ;
F_103 ( V_39 -> V_43 , V_39 -> V_43 , * V_111 ) ;
F_104 ( V_39 , V_111 ) ;
V_39 -> V_43 = * V_111 ;
F_105 ( & V_39 -> V_112 ) ;
F_106 () ;
F_107 ( V_39 ) ;
}
static void F_108 ( struct V_1 * V_7 )
{
static T_1 V_111 ;
struct V_93 V_94 ;
struct V_4 * V_5 ;
V_113 = V_7 ;
F_28 ( V_7 , & V_111 ) ;
F_78 ( & V_7 -> V_3 , 0 , & V_94 ) ;
while ( ( V_5 = F_79 ( & V_94 ) ) ) {
struct V_109 * V_105 ;
bool V_114 ;
F_99 ( V_5 , & V_111 ) ;
V_105 = F_109 ( V_5 ) ;
if ( ! V_105 )
continue;
V_114 = F_14 ( V_7 ) ;
F_110 ( V_105 , & V_7 -> V_43 ) ;
if ( V_114 )
F_93 ( V_105 , & V_7 -> V_115 , & V_111 ) ;
else
F_92 ( V_105 ) ;
}
F_81 ( & V_94 ) ;
V_7 -> V_115 = V_111 ;
V_113 = NULL ;
}
static void F_111 ( struct V_1 * V_7 , T_1 * V_116 )
{
struct V_1 * V_65 ;
struct V_2 * V_66 ;
F_46 () ;
F_56 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_65 ) ;
F_30 ( * V_116 , V_65 -> V_43 , V_8 -> V_36 ) ;
if ( F_17 () && F_50 ( * V_116 ) )
* V_116 = V_8 -> V_36 ;
if ( F_112 ( * V_116 , V_65 -> V_36 ) ) {
V_66 = F_57 ( V_66 ) ;
continue;
}
if ( ! F_83 ( & V_65 -> V_3 ) )
continue;
F_52 () ;
F_84 ( & V_97 ) ;
V_65 -> V_36 = * V_116 ;
F_85 ( & V_97 ) ;
F_86 ( ! F_17 () &&
! F_112 ( V_65 -> V_43 , V_65 -> V_36 ) ) ;
F_108 ( V_65 ) ;
F_46 () ;
F_87 ( & V_65 -> V_3 ) ;
}
F_52 () ;
}
static int F_113 ( struct V_1 * V_7 , struct V_1 * V_98 ,
const char * V_99 )
{
int V_100 ;
if ( V_7 == & V_53 ) {
V_100 = - V_54 ;
goto V_80;
}
if ( ! * V_99 ) {
F_114 ( V_98 -> V_43 ) ;
} else {
V_100 = F_115 ( V_99 , V_98 -> V_43 ) ;
if ( V_100 < 0 )
goto V_80;
if ( ! F_38 ( V_98 -> V_43 ,
V_53 . V_43 ) ) {
V_100 = - V_55 ;
goto V_80;
}
}
if ( F_112 ( V_7 -> V_43 , V_98 -> V_43 ) ) {
V_100 = 0 ;
goto V_80;
}
V_100 = F_45 ( V_7 , V_98 ) ;
if ( V_100 < 0 )
goto V_80;
F_84 ( & V_97 ) ;
V_7 -> V_43 = V_98 -> V_43 ;
F_85 ( & V_97 ) ;
F_111 ( V_7 , & V_98 -> V_43 ) ;
V_80:
return V_100 ;
}
int F_116 ( void )
{
int V_28 ;
F_46 () ;
V_28 = F_3 ( V_117 ) == V_113 ;
F_52 () ;
return V_28 ;
}
static int F_117 ( struct V_1 * V_7 , T_3 V_118 )
{
#ifdef F_118
if ( V_118 < - 1 || V_118 >= V_119 )
return - V_55 ;
#endif
if ( V_118 != V_7 -> V_63 ) {
V_7 -> V_63 = V_118 ;
if ( ! F_49 ( V_7 -> V_42 ) &&
F_13 ( V_7 ) )
F_68 () ;
}
return 0 ;
}
static void F_119 ( struct V_1 * V_7 )
{
struct V_93 V_94 ;
struct V_4 * V_5 ;
F_78 ( & V_7 -> V_3 , 0 , & V_94 ) ;
while ( ( V_5 = F_79 ( & V_94 ) ) )
F_31 ( V_7 , V_5 ) ;
F_81 ( & V_94 ) ;
}
static int F_120 ( T_4 V_120 , struct V_1 * V_7 ,
int V_121 )
{
struct V_1 * V_98 ;
int V_122 ;
int V_123 ;
int V_124 ;
V_98 = F_39 ( V_7 ) ;
if ( ! V_98 )
return - V_125 ;
if ( V_121 )
F_121 ( V_120 , & V_98 -> V_11 ) ;
else
F_122 ( V_120 , & V_98 -> V_11 ) ;
V_124 = F_45 ( V_7 , V_98 ) ;
if ( V_124 < 0 )
goto V_52;
V_122 = ( F_13 ( V_7 ) !=
F_13 ( V_98 ) ) ;
V_123 = ( ( F_16 ( V_7 ) != F_16 ( V_98 ) )
|| ( F_15 ( V_7 ) != F_15 ( V_98 ) ) ) ;
F_84 ( & V_97 ) ;
V_7 -> V_11 = V_98 -> V_11 ;
F_85 ( & V_97 ) ;
if ( ! F_49 ( V_98 -> V_42 ) && V_122 )
F_68 () ;
if ( V_123 )
F_119 ( V_7 ) ;
V_52:
F_44 ( V_98 ) ;
return V_124 ;
}
static void F_123 ( struct V_126 * V_127 )
{
V_127 -> V_128 = 0 ;
V_127 -> V_118 = 0 ;
V_127 -> time = 0 ;
F_124 ( & V_127 -> V_129 ) ;
}
static void F_125 ( struct V_126 * V_127 )
{
T_5 V_130 ;
T_6 V_131 ;
V_130 = F_126 () ;
V_131 = V_130 - V_127 -> time ;
if ( V_131 == 0 )
return;
V_131 = F_127 ( V_132 , V_131 ) ;
while ( V_131 -- > 0 )
V_127 -> V_118 = ( V_133 * V_127 -> V_118 ) / V_134 ;
V_127 -> time = V_130 ;
V_127 -> V_118 += ( ( V_134 - V_133 ) * V_127 -> V_128 ) / V_134 ;
V_127 -> V_128 = 0 ;
}
static void F_128 ( struct V_126 * V_127 )
{
F_129 ( & V_127 -> V_129 ) ;
F_125 ( V_127 ) ;
V_127 -> V_128 = F_127 ( V_135 , V_127 -> V_128 + V_134 ) ;
F_130 ( & V_127 -> V_129 ) ;
}
static int F_131 ( struct V_126 * V_127 )
{
int V_118 ;
F_129 ( & V_127 -> V_129 ) ;
F_125 ( V_127 ) ;
V_118 = V_127 -> V_118 ;
F_130 ( & V_127 -> V_129 ) ;
return V_118 ;
}
static int F_132 ( struct V_136 * V_137 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
int V_28 ;
V_138 = F_3 ( F_133 ( V_137 , & V_3 ) ) ;
V_7 = F_1 ( V_3 ) ;
F_75 ( & V_91 ) ;
V_28 = - V_56 ;
if ( ! F_17 () &&
( F_49 ( V_7 -> V_42 ) || F_50 ( V_7 -> V_43 ) ) )
goto V_139;
F_134 (task, css, tset) {
V_28 = F_135 ( V_5 , V_7 -> V_42 ) ;
if ( V_28 )
goto V_139;
V_28 = F_136 ( V_5 ) ;
if ( V_28 )
goto V_139;
}
V_7 -> V_58 ++ ;
V_28 = 0 ;
V_139:
F_76 ( & V_91 ) ;
return V_28 ;
}
static void F_137 ( struct V_136 * V_137 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
F_133 ( V_137 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_75 ( & V_91 ) ;
F_1 ( V_3 ) -> V_58 -- ;
F_76 ( & V_91 ) ;
}
static void F_138 ( struct V_136 * V_137 )
{
static T_1 V_140 ;
struct V_4 * V_5 ;
struct V_4 * V_141 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_1 * V_142 = V_138 ;
F_133 ( V_137 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_75 ( & V_91 ) ;
if ( V_7 == & V_53 )
F_26 ( V_143 , V_81 ) ;
else
F_23 ( V_7 , V_143 ) ;
F_28 ( V_7 , & V_140 ) ;
F_134 (task, css, tset) {
F_139 ( F_80 ( V_5 , V_143 ) ) ;
F_99 ( V_5 , & V_140 ) ;
F_31 ( V_7 , V_5 ) ;
}
V_140 = V_7 -> V_36 ;
F_140 (leader, css, tset) {
struct V_109 * V_105 = F_109 ( V_141 ) ;
if ( V_105 ) {
F_110 ( V_105 , & V_140 ) ;
if ( F_14 ( V_7 ) )
F_93 ( V_105 , & V_142 -> V_115 ,
& V_140 ) ;
else
F_92 ( V_105 ) ;
}
}
V_7 -> V_115 = V_140 ;
V_7 -> V_58 -- ;
if ( ! V_7 -> V_58 )
F_141 ( & V_144 ) ;
F_76 ( & V_91 ) ;
}
static int F_142 ( struct V_2 * V_3 , struct V_145 * V_146 ,
T_7 V_118 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_146 -> V_147 ;
int V_100 = 0 ;
F_75 ( & V_91 ) ;
if ( ! F_7 ( V_7 ) ) {
V_100 = - V_29 ;
goto V_139;
}
switch ( type ) {
case V_148 :
V_100 = F_120 ( V_12 , V_7 , V_118 ) ;
break;
case V_149 :
V_100 = F_120 ( V_13 , V_7 , V_118 ) ;
break;
case V_150 :
V_100 = F_120 ( V_14 , V_7 , V_118 ) ;
break;
case V_151 :
V_100 = F_120 ( V_15 , V_7 , V_118 ) ;
break;
case V_152 :
V_100 = F_120 ( V_16 , V_7 , V_118 ) ;
break;
case V_153 :
V_154 = ! ! V_118 ;
break;
case V_155 :
V_100 = F_120 ( V_17 , V_7 , V_118 ) ;
break;
case V_156 :
V_100 = F_120 ( V_18 , V_7 , V_118 ) ;
break;
default:
V_100 = - V_55 ;
break;
}
V_139:
F_76 ( & V_91 ) ;
return V_100 ;
}
static int F_143 ( struct V_2 * V_3 , struct V_145 * V_146 ,
T_3 V_118 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_146 -> V_147 ;
int V_100 = - V_29 ;
F_75 ( & V_91 ) ;
if ( ! F_7 ( V_7 ) )
goto V_139;
switch ( type ) {
case V_157 :
V_100 = F_117 ( V_7 , V_118 ) ;
break;
default:
V_100 = - V_55 ;
break;
}
V_139:
F_76 ( & V_91 ) ;
return V_100 ;
}
static T_9 F_144 ( struct V_158 * V_159 ,
char * V_99 , T_10 V_160 , T_11 V_161 )
{
struct V_1 * V_7 = F_1 ( F_145 ( V_159 ) ) ;
struct V_1 * V_98 ;
int V_100 = - V_29 ;
V_99 = F_146 ( V_99 ) ;
F_147 ( & V_7 -> V_3 ) ;
F_148 ( V_159 -> V_162 ) ;
F_149 ( & V_163 ) ;
F_75 ( & V_91 ) ;
if ( ! F_7 ( V_7 ) )
goto V_139;
V_98 = F_39 ( V_7 ) ;
if ( ! V_98 ) {
V_100 = - V_125 ;
goto V_139;
}
switch ( F_150 ( V_159 ) -> V_147 ) {
case V_164 :
V_100 = F_88 ( V_7 , V_98 , V_99 ) ;
break;
case V_165 :
V_100 = F_113 ( V_7 , V_98 , V_99 ) ;
break;
default:
V_100 = - V_55 ;
break;
}
F_44 ( V_98 ) ;
V_139:
F_76 ( & V_91 ) ;
F_151 ( V_159 -> V_162 ) ;
F_87 ( & V_7 -> V_3 ) ;
F_98 ( V_110 ) ;
return V_100 ? : V_160 ;
}
static int F_152 ( struct V_166 * V_167 , void * V_168 )
{
struct V_1 * V_7 = F_1 ( F_153 ( V_167 ) ) ;
T_8 type = F_154 ( V_167 ) -> V_147 ;
int V_28 = 0 ;
F_84 ( & V_97 ) ;
switch ( type ) {
case V_164 :
F_155 ( V_167 , L_5 , F_156 ( V_7 -> V_42 ) ) ;
break;
case V_165 :
F_155 ( V_167 , L_5 , F_157 ( & V_7 -> V_43 ) ) ;
break;
case V_169 :
F_155 ( V_167 , L_5 , F_156 ( V_7 -> V_34 ) ) ;
break;
case V_170 :
F_155 ( V_167 , L_5 , F_157 ( & V_7 -> V_36 ) ) ;
break;
default:
V_28 = - V_55 ;
}
F_85 ( & V_97 ) ;
return V_28 ;
}
static T_7 F_158 ( struct V_2 * V_3 , struct V_145 * V_146 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_146 -> V_147 ;
switch ( type ) {
case V_148 :
return F_10 ( V_7 ) ;
case V_149 :
return F_11 ( V_7 ) ;
case V_150 :
return F_12 ( V_7 ) ;
case V_151 :
return F_13 ( V_7 ) ;
case V_152 :
return F_14 ( V_7 ) ;
case V_153 :
return V_154 ;
case V_171 :
return F_131 ( & V_7 -> V_126 ) ;
case V_155 :
return F_15 ( V_7 ) ;
case V_156 :
return F_16 ( V_7 ) ;
default:
F_159 () ;
}
return 0 ;
}
static T_3 F_160 ( struct V_2 * V_3 , struct V_145 * V_146 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_146 -> V_147 ;
switch ( type ) {
case V_157 :
return V_7 -> V_63 ;
default:
F_159 () ;
}
return 0 ;
}
static struct V_2 *
F_161 ( struct V_2 * V_172 )
{
struct V_1 * V_7 ;
if ( ! V_172 )
return & V_53 . V_3 ;
V_7 = F_94 ( sizeof( * V_7 ) , V_45 ) ;
if ( ! V_7 )
return F_21 ( - V_125 ) ;
if ( ! F_41 ( & V_7 -> V_42 , V_45 ) )
goto V_46;
if ( ! F_41 ( & V_7 -> V_34 , V_45 ) )
goto V_47;
F_121 ( V_15 , & V_7 -> V_11 ) ;
F_65 ( V_7 -> V_42 ) ;
F_114 ( V_7 -> V_43 ) ;
F_65 ( V_7 -> V_34 ) ;
F_114 ( V_7 -> V_36 ) ;
F_123 ( & V_7 -> V_126 ) ;
V_7 -> V_63 = - 1 ;
return & V_7 -> V_3 ;
V_47:
F_42 ( V_7 -> V_42 ) ;
V_46:
F_43 ( V_7 ) ;
return F_21 ( - V_125 ) ;
}
static int F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_8 = F_5 ( V_7 ) ;
struct V_1 * V_173 ;
struct V_2 * V_66 ;
if ( ! V_8 )
return 0 ;
F_75 ( & V_91 ) ;
F_121 ( V_10 , & V_7 -> V_11 ) ;
if ( F_15 ( V_8 ) )
F_121 ( V_17 , & V_7 -> V_11 ) ;
if ( F_16 ( V_8 ) )
F_121 ( V_18 , & V_7 -> V_11 ) ;
F_163 () ;
F_84 ( & V_97 ) ;
if ( F_17 () ) {
F_26 ( V_7 -> V_34 , V_8 -> V_34 ) ;
V_7 -> V_36 = V_8 -> V_36 ;
}
F_85 ( & V_97 ) ;
if ( ! F_8 ( V_174 , & V_3 -> V_57 -> V_11 ) )
goto V_139;
F_46 () ;
F_47 (tmp_cs, pos_css, parent) {
if ( F_11 ( V_173 ) || F_10 ( V_173 ) ) {
F_52 () ;
goto V_139;
}
}
F_52 () ;
F_84 ( & V_97 ) ;
V_7 -> V_43 = V_8 -> V_43 ;
V_7 -> V_36 = V_8 -> V_43 ;
F_26 ( V_7 -> V_42 , V_8 -> V_42 ) ;
F_26 ( V_7 -> V_34 , V_8 -> V_42 ) ;
F_85 ( & V_97 ) ;
V_139:
F_76 ( & V_91 ) ;
return 0 ;
}
static void F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_75 ( & V_91 ) ;
if ( F_13 ( V_7 ) )
F_120 ( V_15 , V_7 , 0 ) ;
F_165 () ;
F_122 ( V_10 , & V_7 -> V_11 ) ;
F_76 ( & V_91 ) ;
}
static void F_166 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_42 ( V_7 -> V_34 ) ;
F_42 ( V_7 -> V_42 ) ;
F_43 ( V_7 ) ;
}
static void F_167 ( struct V_2 * V_175 )
{
F_75 ( & V_91 ) ;
F_84 ( & V_97 ) ;
if ( F_17 () ) {
F_26 ( V_53 . V_42 , V_81 ) ;
V_53 . V_43 = V_176 ;
} else {
F_26 ( V_53 . V_42 ,
V_53 . V_34 ) ;
V_53 . V_43 = V_53 . V_36 ;
}
F_85 ( & V_97 ) ;
F_76 ( & V_91 ) ;
}
static void F_168 ( struct V_4 * V_5 )
{
if ( F_169 ( V_5 , V_6 ) )
return;
F_80 ( V_5 , & V_117 -> V_42 ) ;
V_5 -> V_43 = V_117 -> V_43 ;
}
int T_12 F_170 ( void )
{
int V_124 = 0 ;
F_67 ( ! F_41 ( & V_53 . V_42 , V_45 ) ) ;
F_67 ( ! F_41 ( & V_53 . V_34 , V_45 ) ) ;
F_171 ( V_53 . V_42 ) ;
F_172 ( V_53 . V_43 ) ;
F_171 ( V_53 . V_34 ) ;
F_172 ( V_53 . V_36 ) ;
F_123 ( & V_53 . V_126 ) ;
F_121 ( V_15 , & V_53 . V_11 ) ;
V_53 . V_63 = - 1 ;
V_124 = F_173 ( & V_177 ) ;
if ( V_124 < 0 )
return V_124 ;
F_67 ( ! F_41 ( & V_143 , V_45 ) ) ;
return 0 ;
}
static void F_174 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_5 ( V_7 ) ;
while ( F_49 ( V_8 -> V_42 ) ||
F_50 ( V_8 -> V_43 ) )
V_8 = F_5 ( V_8 ) ;
if ( F_175 ( V_8 -> V_3 . V_57 , V_7 -> V_3 . V_57 ) ) {
F_176 ( L_6 ) ;
F_177 ( V_7 -> V_3 . V_57 ) ;
F_178 ( L_7 ) ;
}
}
static void
F_179 ( struct V_1 * V_7 ,
struct V_32 * V_95 , T_1 * V_116 ,
bool V_178 , bool V_179 )
{
bool V_180 ;
F_84 ( & V_97 ) ;
F_26 ( V_7 -> V_42 , V_95 ) ;
F_26 ( V_7 -> V_34 , V_95 ) ;
V_7 -> V_43 = * V_116 ;
V_7 -> V_36 = * V_116 ;
F_85 ( & V_97 ) ;
if ( V_178 && ! F_49 ( V_7 -> V_42 ) )
F_77 ( V_7 ) ;
if ( V_179 && ! F_50 ( V_7 -> V_43 ) )
F_108 ( V_7 ) ;
V_180 = F_49 ( V_7 -> V_42 ) ||
F_50 ( V_7 -> V_43 ) ;
F_76 ( & V_91 ) ;
if ( V_180 )
F_174 ( V_7 ) ;
F_75 ( & V_91 ) ;
}
static void
F_180 ( struct V_1 * V_7 ,
struct V_32 * V_95 , T_1 * V_116 ,
bool V_178 , bool V_179 )
{
if ( F_49 ( V_95 ) )
F_26 ( V_95 , F_5 ( V_7 ) -> V_34 ) ;
if ( F_50 ( * V_116 ) )
* V_116 = F_5 ( V_7 ) -> V_36 ;
F_84 ( & V_97 ) ;
F_26 ( V_7 -> V_34 , V_95 ) ;
V_7 -> V_36 = * V_116 ;
F_85 ( & V_97 ) ;
if ( V_178 )
F_77 ( V_7 ) ;
if ( V_179 )
F_108 ( V_7 ) ;
}
static void F_181 ( struct V_1 * V_7 )
{
static T_13 V_95 ;
static T_1 V_116 ;
bool V_178 ;
bool V_179 ;
V_181:
F_182 ( V_144 , V_7 -> V_58 == 0 ) ;
F_75 ( & V_91 ) ;
if ( V_7 -> V_58 ) {
F_76 ( & V_91 ) ;
goto V_181;
}
F_27 ( & V_95 , V_7 -> V_42 , F_5 ( V_7 ) -> V_34 ) ;
F_30 ( V_116 , V_7 -> V_43 , F_5 ( V_7 ) -> V_36 ) ;
V_178 = ! F_71 ( & V_95 , V_7 -> V_34 ) ;
V_179 = ! F_112 ( V_116 , V_7 -> V_36 ) ;
if ( F_17 () )
F_180 ( V_7 , & V_95 , & V_116 ,
V_178 , V_179 ) ;
else
F_179 ( V_7 , & V_95 , & V_116 ,
V_178 , V_179 ) ;
F_76 ( & V_91 ) ;
}
void F_183 ( void )
{
V_182 = true ;
}
static void F_184 ( struct V_101 * V_102 )
{
static T_13 V_95 ;
static T_1 V_116 ;
bool V_178 , V_179 ;
bool V_183 = F_17 () ;
F_75 ( & V_91 ) ;
F_26 ( & V_95 , V_92 ) ;
V_116 = V_37 [ V_38 ] ;
V_178 = ! F_71 ( V_53 . V_34 , & V_95 ) ;
V_179 = ! F_112 ( V_53 . V_36 , V_116 ) ;
if ( V_178 ) {
F_84 ( & V_97 ) ;
if ( ! V_183 )
F_26 ( V_53 . V_42 , & V_95 ) ;
F_26 ( V_53 . V_34 , & V_95 ) ;
F_85 ( & V_97 ) ;
}
if ( V_179 ) {
F_84 ( & V_97 ) ;
if ( ! V_183 )
V_53 . V_43 = V_116 ;
V_53 . V_36 = V_116 ;
F_85 ( & V_97 ) ;
F_108 ( & V_53 ) ;
}
F_76 ( & V_91 ) ;
if ( V_178 || V_179 ) {
struct V_1 * V_7 ;
struct V_2 * V_66 ;
F_46 () ;
F_56 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_53 || ! F_83 ( & V_7 -> V_3 ) )
continue;
F_52 () ;
F_181 ( V_7 ) ;
F_46 () ;
F_87 ( & V_7 -> V_3 ) ;
}
F_52 () ;
}
if ( V_178 || V_182 ) {
V_182 = false ;
F_74 () ;
}
}
void F_185 ( void )
{
F_186 ( & V_163 ) ;
}
void F_187 ( void )
{
F_149 ( & V_163 ) ;
}
static int F_188 ( struct V_184 * V_185 ,
unsigned long V_186 , void * V_187 )
{
F_186 ( & V_163 ) ;
return V_188 ;
}
void T_12 F_189 ( void )
{
F_26 ( V_53 . V_42 , V_92 ) ;
V_53 . V_43 = V_37 [ V_38 ] ;
V_53 . V_115 = V_53 . V_43 ;
F_26 ( V_53 . V_34 , V_92 ) ;
V_53 . V_36 = V_37 [ V_38 ] ;
F_190 ( & V_189 ) ;
V_110 = F_191 ( L_8 , 0 ) ;
F_67 ( ! V_110 ) ;
}
void F_192 ( struct V_4 * V_39 , struct V_32 * V_33 )
{
unsigned long V_11 ;
F_193 ( & V_97 , V_11 ) ;
F_46 () ;
F_23 ( F_3 ( V_39 ) , V_33 ) ;
F_52 () ;
F_194 ( & V_97 , V_11 ) ;
}
void F_195 ( struct V_4 * V_39 )
{
F_46 () ;
F_196 ( V_39 , F_3 ( V_39 ) -> V_34 ) ;
F_52 () ;
}
void T_12 F_197 ( void )
{
F_172 ( V_117 -> V_43 ) ;
}
T_1 F_198 ( struct V_4 * V_39 )
{
T_1 V_190 ;
unsigned long V_11 ;
F_193 ( & V_97 , V_11 ) ;
F_46 () ;
F_28 ( F_3 ( V_39 ) , & V_190 ) ;
F_52 () ;
F_194 ( & V_97 , V_11 ) ;
return V_190 ;
}
int F_199 ( T_1 * V_191 )
{
return F_29 ( * V_191 , V_117 -> V_43 ) ;
}
static struct V_1 * F_200 ( struct V_1 * V_7 )
{
while ( ! ( F_11 ( V_7 ) || F_12 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
bool F_201 ( int V_192 , T_14 V_193 )
{
struct V_1 * V_7 ;
int V_194 ;
unsigned long V_11 ;
if ( F_202 () )
return true ;
if ( F_203 ( V_192 , V_117 -> V_43 ) )
return true ;
if ( F_25 ( F_204 ( V_117 ) ) )
return true ;
if ( V_193 & V_195 )
return false ;
if ( V_117 -> V_11 & V_196 )
return true ;
F_193 ( & V_97 , V_11 ) ;
F_46 () ;
V_7 = F_200 ( F_3 ( V_117 ) ) ;
V_194 = F_203 ( V_192 , V_7 -> V_43 ) ;
F_52 () ;
F_194 ( & V_97 , V_11 ) ;
return V_194 ;
}
static int F_205 ( int * V_197 )
{
return * V_197 = F_206 ( * V_197 , V_117 -> V_43 ) ;
}
int F_207 ( void )
{
if ( V_117 -> V_198 == V_199 )
V_117 -> V_198 =
F_208 ( & V_117 -> V_43 ) ;
return F_205 ( & V_117 -> V_198 ) ;
}
int F_209 ( void )
{
if ( V_117 -> V_200 == V_199 )
V_117 -> V_200 =
F_208 ( & V_117 -> V_43 ) ;
return F_205 ( & V_117 -> V_200 ) ;
}
int F_210 ( const struct V_4 * V_201 ,
const struct V_4 * V_202 )
{
return F_29 ( V_201 -> V_43 , V_202 -> V_43 ) ;
}
void F_211 ( void )
{
struct V_57 * V_203 ;
F_46 () ;
V_203 = F_3 ( V_117 ) -> V_3 . V_57 ;
F_212 ( L_9 , V_117 -> V_204 ) ;
F_177 ( V_203 ) ;
F_178 ( L_10 ,
F_157 ( & V_117 -> V_43 ) ) ;
F_52 () ;
}
void F_213 ( void )
{
F_46 () ;
F_128 ( & F_3 ( V_117 ) -> V_126 ) ;
F_52 () ;
}
int F_214 ( struct V_166 * V_205 , struct V_206 * V_207 ,
struct V_208 * V_208 , struct V_4 * V_39 )
{
char * V_99 ;
struct V_2 * V_3 ;
int V_100 ;
V_100 = - V_125 ;
V_99 = F_63 ( V_209 , V_45 ) ;
if ( ! V_99 )
goto V_52;
V_3 = F_215 ( V_39 , V_6 ) ;
V_100 = F_216 ( V_3 -> V_57 , V_99 , V_209 ,
V_117 -> V_210 -> V_211 ) ;
F_87 ( V_3 ) ;
if ( V_100 >= V_209 )
V_100 = - V_212 ;
if ( V_100 < 0 )
goto V_213;
F_217 ( V_205 , V_99 ) ;
F_218 ( V_205 , '\n' ) ;
V_100 = 0 ;
V_213:
F_43 ( V_99 ) ;
V_52:
return V_100 ;
}
void F_219 ( struct V_166 * V_205 , struct V_4 * V_5 )
{
F_155 ( V_205 , L_11 ,
F_157 ( & V_5 -> V_43 ) ) ;
F_155 ( V_205 , L_12 ,
F_157 ( & V_5 -> V_43 ) ) ;
}
