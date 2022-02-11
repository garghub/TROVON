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
return F_1 ( F_6 ( & V_7 -> V_3 ) ) ;
}
static inline bool F_7 ( struct V_4 * V_5 )
{
return V_5 -> V_8 ;
}
static inline bool F_7 ( struct V_4 * V_5 )
{
return false ;
}
static inline bool F_8 ( const struct V_1 * V_7 )
{
return F_9 ( V_9 , & V_7 -> V_10 ) ;
}
static inline int F_10 ( const struct V_1 * V_7 )
{
return F_9 ( V_11 , & V_7 -> V_10 ) ;
}
static inline int F_11 ( const struct V_1 * V_7 )
{
return F_9 ( V_12 , & V_7 -> V_10 ) ;
}
static inline int F_12 ( const struct V_1 * V_7 )
{
return F_9 ( V_13 , & V_7 -> V_10 ) ;
}
static inline int F_13 ( const struct V_1 * V_7 )
{
return F_9 ( V_14 , & V_7 -> V_10 ) ;
}
static inline int F_14 ( const struct V_1 * V_7 )
{
return F_9 ( V_15 , & V_7 -> V_10 ) ;
}
static inline int F_15 ( const struct V_1 * V_7 )
{
return F_9 ( V_16 , & V_7 -> V_10 ) ;
}
static inline int F_16 ( const struct V_1 * V_7 )
{
return F_9 ( V_17 , & V_7 -> V_10 ) ;
}
static struct V_18 * F_17 ( struct V_19 * V_20 ,
int V_10 , const char * V_21 , void * V_22 )
{
struct V_19 * V_23 = F_18 ( L_1 ) ;
struct V_18 * V_24 = F_19 ( - V_25 ) ;
if ( V_23 ) {
char V_26 [] =
L_2
L_3 ;
V_24 = V_23 -> V_27 ( V_23 , V_10 ,
V_21 , V_26 ) ;
F_20 ( V_23 ) ;
}
return V_24 ;
}
static void F_21 ( struct V_1 * V_7 , struct V_28 * V_29 )
{
while ( ! F_22 ( V_7 -> V_30 , V_31 ) )
V_7 = F_5 ( V_7 ) ;
F_23 ( V_29 , V_7 -> V_30 , V_31 ) ;
}
static void F_24 ( struct V_1 * V_7 , T_1 * V_29 )
{
while ( ! F_25 ( V_7 -> V_32 , V_33 [ V_34 ] ) )
V_7 = F_5 ( V_7 ) ;
F_26 ( * V_29 , V_7 -> V_32 , V_33 [ V_34 ] ) ;
}
static void F_27 ( struct V_1 * V_7 ,
struct V_4 * V_35 )
{
if ( F_15 ( V_7 ) )
V_35 -> V_10 |= V_36 ;
else
V_35 -> V_10 &= ~ V_36 ;
if ( F_16 ( V_7 ) )
V_35 -> V_10 |= V_37 ;
else
V_35 -> V_10 &= ~ V_37 ;
}
static int F_28 ( const struct V_1 * V_38 , const struct V_1 * V_39 )
{
return F_29 ( V_38 -> V_30 , V_39 -> V_30 ) &&
F_30 ( V_38 -> V_32 , V_39 -> V_32 ) &&
F_10 ( V_38 ) <= F_10 ( V_39 ) &&
F_11 ( V_38 ) <= F_11 ( V_39 ) ;
}
static struct V_1 * F_31 ( struct V_1 * V_7 )
{
struct V_1 * V_40 ;
V_40 = F_32 ( V_7 , sizeof( * V_7 ) , V_41 ) ;
if ( ! V_40 )
return NULL ;
if ( ! F_33 ( & V_40 -> V_30 , V_41 ) ) {
F_34 ( V_40 ) ;
return NULL ;
}
F_35 ( V_40 -> V_30 , V_7 -> V_30 ) ;
return V_40 ;
}
static void F_36 ( struct V_1 * V_40 )
{
F_37 ( V_40 -> V_30 ) ;
F_34 ( V_40 ) ;
}
static int F_38 ( struct V_1 * V_42 , struct V_1 * V_40 )
{
struct V_2 * V_3 ;
struct V_1 * V_43 , * V_44 ;
int V_24 ;
F_39 () ;
V_24 = - V_45 ;
F_40 (c, css, cur)
if ( ! F_28 ( V_43 , V_40 ) )
goto V_46;
V_24 = 0 ;
if ( V_42 == & V_47 )
goto V_46;
V_44 = F_5 ( V_42 ) ;
V_24 = - V_48 ;
if ( ! F_28 ( V_40 , V_44 ) )
goto V_46;
V_24 = - V_49 ;
F_40 (c, css, par) {
if ( ( F_10 ( V_40 ) || F_10 ( V_43 ) ) &&
V_43 != V_42 &&
F_22 ( V_40 -> V_30 , V_43 -> V_30 ) )
goto V_46;
if ( ( F_11 ( V_40 ) || F_11 ( V_43 ) ) &&
V_43 != V_42 &&
F_25 ( V_40 -> V_32 , V_43 -> V_32 ) )
goto V_46;
}
V_24 = - V_50 ;
if ( ( F_41 ( V_42 -> V_3 . V_51 ) || V_42 -> V_52 ) ) {
if ( ! F_42 ( V_42 -> V_30 ) &&
F_42 ( V_40 -> V_30 ) )
goto V_46;
if ( ! F_43 ( V_42 -> V_32 ) &&
F_43 ( V_40 -> V_32 ) )
goto V_46;
}
V_24 = 0 ;
V_46:
F_44 () ;
return V_24 ;
}
static int F_45 ( struct V_1 * V_53 , struct V_1 * V_54 )
{
return F_22 ( V_53 -> V_30 , V_54 -> V_30 ) ;
}
static void
F_46 ( struct V_55 * V_56 , struct V_1 * V_43 )
{
if ( V_56 -> V_57 < V_43 -> V_57 )
V_56 -> V_57 = V_43 -> V_57 ;
return;
}
static void F_47 ( struct V_55 * V_56 ,
struct V_1 * V_58 )
{
struct V_1 * V_59 ;
struct V_2 * V_60 ;
F_39 () ;
F_48 (cp, pos_css, root_cs) {
if ( V_59 == V_58 )
continue;
if ( F_42 ( V_59 -> V_30 ) ) {
V_60 = F_49 ( V_60 ) ;
continue;
}
if ( F_13 ( V_59 ) )
F_46 ( V_56 , V_59 ) ;
}
F_44 () ;
}
static int F_50 ( T_2 * * V_61 ,
struct V_55 * * V_62 )
{
struct V_1 * V_59 ;
struct V_1 * * V_63 ;
int V_64 ;
int V_65 , V_66 , V_67 ;
T_2 * V_68 ;
struct V_55 * V_56 ;
int V_69 = 0 ;
int V_70 ;
struct V_2 * V_60 ;
V_68 = NULL ;
V_56 = NULL ;
V_63 = NULL ;
if ( F_13 ( & V_47 ) ) {
V_69 = 1 ;
V_68 = F_51 ( V_69 ) ;
if ( ! V_68 )
goto V_71;
V_56 = F_52 ( sizeof( struct V_55 ) , V_41 ) ;
if ( V_56 ) {
* V_56 = V_72 ;
F_47 ( V_56 , & V_47 ) ;
}
F_35 ( V_68 [ 0 ] , V_47 . V_30 ) ;
goto V_71;
}
V_63 = F_52 ( V_73 * sizeof( V_59 ) , V_41 ) ;
if ( ! V_63 )
goto V_71;
V_64 = 0 ;
F_39 () ;
F_48 (cp, pos_css, &top_cpuset) {
if ( V_59 == & V_47 )
continue;
if ( ! F_42 ( V_59 -> V_30 ) &&
! F_13 ( V_59 ) )
continue;
if ( F_13 ( V_59 ) )
V_63 [ V_64 ++ ] = V_59 ;
V_60 = F_49 ( V_60 ) ;
}
F_44 () ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ )
V_63 [ V_65 ] -> V_74 = V_65 ;
V_69 = V_64 ;
V_75:
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
struct V_1 * V_53 = V_63 [ V_65 ] ;
int V_76 = V_53 -> V_74 ;
for ( V_66 = 0 ; V_66 < V_64 ; V_66 ++ ) {
struct V_1 * V_54 = V_63 [ V_66 ] ;
int V_77 = V_54 -> V_74 ;
if ( V_76 != V_77 && F_45 ( V_53 , V_54 ) ) {
for ( V_67 = 0 ; V_67 < V_64 ; V_67 ++ ) {
struct V_1 * V_43 = V_63 [ V_67 ] ;
if ( V_43 -> V_74 == V_77 )
V_43 -> V_74 = V_76 ;
}
V_69 -- ;
goto V_75;
}
}
}
V_68 = F_51 ( V_69 ) ;
if ( ! V_68 )
goto V_71;
V_56 = F_52 ( V_69 * sizeof( struct V_55 ) , V_41 ) ;
for ( V_70 = 0 , V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
struct V_1 * V_53 = V_63 [ V_65 ] ;
struct V_28 * V_78 ;
int V_76 = V_53 -> V_74 ;
if ( V_76 < 0 ) {
continue;
}
V_78 = V_68 [ V_70 ] ;
if ( V_70 == V_69 ) {
static int V_79 = 10 ;
if ( V_79 ) {
F_53 ( V_80
L_4
L_5
L_6 ,
V_70 , V_69 , V_64 , V_65 , V_76 ) ;
V_79 -- ;
}
continue;
}
F_54 ( V_78 ) ;
if ( V_56 )
* ( V_56 + V_70 ) = V_72 ;
for ( V_66 = V_65 ; V_66 < V_64 ; V_66 ++ ) {
struct V_1 * V_54 = V_63 [ V_66 ] ;
if ( V_76 == V_54 -> V_74 ) {
F_55 ( V_78 , V_78 , V_54 -> V_30 ) ;
if ( V_56 )
F_47 ( V_56 + V_70 , V_54 ) ;
V_54 -> V_74 = - 1 ;
}
}
V_70 ++ ;
}
F_56 ( V_70 != V_69 ) ;
V_71:
F_34 ( V_63 ) ;
if ( V_68 == NULL )
V_69 = 1 ;
* V_61 = V_68 ;
* V_62 = V_56 ;
return V_69 ;
}
static void F_57 ( void )
{
struct V_55 * V_81 ;
T_2 * V_68 ;
int V_69 ;
F_58 ( & V_82 ) ;
F_59 () ;
if ( ! F_60 ( V_47 . V_30 , V_83 ) )
goto V_46;
V_69 = F_50 ( & V_68 , & V_81 ) ;
F_61 ( V_69 , V_68 , V_81 ) ;
V_46:
F_62 () ;
}
static void F_57 ( void )
{
}
void F_63 ( void )
{
F_64 ( & V_82 ) ;
F_57 () ;
F_65 ( & V_82 ) ;
}
static struct V_1 * F_66 ( struct V_1 * V_7 )
{
while ( F_42 ( V_7 -> V_30 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
static struct V_1 * F_67 ( struct V_1 * V_7 )
{
while ( F_43 ( V_7 -> V_32 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
static void F_68 ( struct V_4 * V_35 , void * V_22 )
{
struct V_1 * V_7 = V_22 ;
struct V_1 * V_84 = F_66 ( V_7 ) ;
F_69 ( V_35 , V_84 -> V_30 ) ;
}
static void F_70 ( struct V_1 * V_7 , struct V_85 * V_86 )
{
F_71 ( & V_7 -> V_3 , NULL , F_68 , V_7 , V_86 ) ;
}
static void F_72 ( struct V_1 * V_58 ,
bool V_87 , struct V_85 * V_86 )
{
struct V_1 * V_59 ;
struct V_2 * V_60 ;
F_39 () ;
F_48 (cp, pos_css, root_cs) {
if ( V_59 == V_58 ) {
if ( ! V_87 )
continue;
} else {
if ( ! F_42 ( V_59 -> V_30 ) ) {
V_60 = F_49 ( V_60 ) ;
continue;
}
}
if ( ! F_73 ( & V_59 -> V_3 ) )
continue;
F_44 () ;
F_70 ( V_59 , V_86 ) ;
F_39 () ;
F_74 ( & V_59 -> V_3 ) ;
}
F_44 () ;
}
static int F_75 ( struct V_1 * V_7 , struct V_1 * V_88 ,
const char * V_89 )
{
struct V_85 V_86 ;
int V_90 ;
int V_91 ;
if ( V_7 == & V_47 )
return - V_48 ;
if ( ! * V_89 ) {
F_54 ( V_88 -> V_30 ) ;
} else {
V_90 = F_76 ( V_89 , V_88 -> V_30 ) ;
if ( V_90 < 0 )
return V_90 ;
if ( ! F_29 ( V_88 -> V_30 , V_83 ) )
return - V_49 ;
}
if ( F_60 ( V_7 -> V_30 , V_88 -> V_30 ) )
return 0 ;
V_90 = F_38 ( V_7 , V_88 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_77 ( & V_86 , V_92 , V_41 , NULL ) ;
if ( V_90 )
return V_90 ;
V_91 = F_13 ( V_88 ) ;
F_64 ( & V_93 ) ;
F_35 ( V_7 -> V_30 , V_88 -> V_30 ) ;
F_65 ( & V_93 ) ;
F_72 ( V_7 , true , & V_86 ) ;
F_78 ( & V_86 ) ;
if ( V_91 )
F_57 () ;
return 0 ;
}
static void F_79 ( struct V_94 * V_95 , const T_1 * V_96 ,
const T_1 * V_97 )
{
struct V_4 * V_35 = V_98 ;
struct V_1 * V_99 ;
V_35 -> V_32 = * V_97 ;
F_80 ( V_95 , V_96 , V_97 , V_100 ) ;
V_99 = F_67 ( F_3 ( V_35 ) ) ;
F_24 ( V_99 , & V_35 -> V_32 ) ;
}
static void F_81 ( struct V_4 * V_35 ,
T_1 * V_101 )
{
bool V_102 ;
if ( F_82 ( F_83 ( V_103 ) ) )
return;
if ( V_98 -> V_10 & V_104 )
return;
F_84 ( V_35 ) ;
V_102 = F_7 ( V_35 ) ||
! F_25 ( * V_101 , V_35 -> V_32 ) ;
if ( V_102 ) {
F_85 () ;
F_86 ( & V_35 -> V_105 ) ;
}
F_87 ( V_35 -> V_32 , V_35 -> V_32 , * V_101 ) ;
F_88 ( V_35 , V_101 , V_106 ) ;
F_88 ( V_35 , V_101 , V_107 ) ;
V_35 -> V_32 = * V_101 ;
if ( V_102 ) {
F_89 ( & V_35 -> V_105 ) ;
F_90 () ;
}
F_91 ( V_35 ) ;
}
static void F_92 ( struct V_4 * V_38 , void * V_22 )
{
struct V_108 * V_109 = V_22 ;
struct V_1 * V_7 = V_109 -> V_7 ;
struct V_94 * V_95 ;
int V_110 ;
F_81 ( V_38 , V_109 -> V_101 ) ;
V_95 = F_93 ( V_38 ) ;
if ( ! V_95 )
return;
V_110 = F_14 ( V_7 ) ;
F_94 ( V_95 , & V_7 -> V_32 ) ;
if ( V_110 )
F_79 ( V_95 , & V_7 -> V_111 , V_109 -> V_101 ) ;
F_95 ( V_95 ) ;
}
static void F_96 ( struct V_1 * V_7 , struct V_85 * V_86 )
{
static T_1 V_101 ;
struct V_1 * V_99 = F_67 ( V_7 ) ;
struct V_108 V_109 = { . V_7 = V_7 ,
. V_101 = & V_101 } ;
V_112 = V_7 ;
F_24 ( V_99 , & V_101 ) ;
F_71 ( & V_7 -> V_3 , NULL , F_92 , & V_109 , V_86 ) ;
V_7 -> V_111 = V_101 ;
V_112 = NULL ;
}
static void F_97 ( struct V_1 * V_58 ,
bool V_87 , struct V_85 * V_86 )
{
struct V_1 * V_59 ;
struct V_2 * V_60 ;
F_39 () ;
F_48 (cp, pos_css, root_cs) {
if ( V_59 == V_58 ) {
if ( ! V_87 )
continue;
} else {
if ( ! F_43 ( V_59 -> V_32 ) ) {
V_60 = F_49 ( V_60 ) ;
continue;
}
}
if ( ! F_73 ( & V_59 -> V_3 ) )
continue;
F_44 () ;
F_96 ( V_59 , V_86 ) ;
F_39 () ;
F_74 ( & V_59 -> V_3 ) ;
}
F_44 () ;
}
static int F_98 ( struct V_1 * V_7 , struct V_1 * V_88 ,
const char * V_89 )
{
int V_90 ;
struct V_85 V_86 ;
if ( V_7 == & V_47 ) {
V_90 = - V_48 ;
goto V_71;
}
if ( ! * V_89 ) {
F_99 ( V_88 -> V_32 ) ;
} else {
V_90 = F_100 ( V_89 , V_88 -> V_32 ) ;
if ( V_90 < 0 )
goto V_71;
if ( ! F_30 ( V_88 -> V_32 ,
V_33 [ V_34 ] ) ) {
V_90 = - V_49 ;
goto V_71;
}
}
if ( F_101 ( V_7 -> V_32 , V_88 -> V_32 ) ) {
V_90 = 0 ;
goto V_71;
}
V_90 = F_38 ( V_7 , V_88 ) ;
if ( V_90 < 0 )
goto V_71;
V_90 = F_77 ( & V_86 , V_92 , V_41 , NULL ) ;
if ( V_90 < 0 )
goto V_71;
F_64 ( & V_93 ) ;
V_7 -> V_32 = V_88 -> V_32 ;
F_65 ( & V_93 ) ;
F_97 ( V_7 , true , & V_86 ) ;
F_78 ( & V_86 ) ;
V_71:
return V_90 ;
}
int F_102 ( void )
{
return F_3 ( V_98 ) == V_112 ;
}
static int F_103 ( struct V_1 * V_7 , T_3 V_113 )
{
#ifdef F_104
if ( V_113 < - 1 || V_113 >= V_114 )
return - V_49 ;
#endif
if ( V_113 != V_7 -> V_57 ) {
V_7 -> V_57 = V_113 ;
if ( ! F_42 ( V_7 -> V_30 ) &&
F_13 ( V_7 ) )
F_57 () ;
}
return 0 ;
}
static void F_105 ( struct V_4 * V_35 , void * V_22 )
{
struct V_1 * V_7 = V_22 ;
F_27 ( V_7 , V_35 ) ;
}
static void F_106 ( struct V_1 * V_7 , struct V_85 * V_86 )
{
F_71 ( & V_7 -> V_3 , NULL , F_105 , V_7 , V_86 ) ;
}
static int F_107 ( T_4 V_115 , struct V_1 * V_7 ,
int V_116 )
{
struct V_1 * V_88 ;
int V_117 ;
int V_118 ;
struct V_85 V_86 ;
int V_119 ;
V_88 = F_31 ( V_7 ) ;
if ( ! V_88 )
return - V_120 ;
if ( V_116 )
F_108 ( V_115 , & V_88 -> V_10 ) ;
else
F_109 ( V_115 , & V_88 -> V_10 ) ;
V_119 = F_38 ( V_7 , V_88 ) ;
if ( V_119 < 0 )
goto V_46;
V_119 = F_77 ( & V_86 , V_92 , V_41 , NULL ) ;
if ( V_119 < 0 )
goto V_46;
V_117 = ( F_13 ( V_7 ) !=
F_13 ( V_88 ) ) ;
V_118 = ( ( F_16 ( V_7 ) != F_16 ( V_88 ) )
|| ( F_15 ( V_7 ) != F_15 ( V_88 ) ) ) ;
F_64 ( & V_93 ) ;
V_7 -> V_10 = V_88 -> V_10 ;
F_65 ( & V_93 ) ;
if ( ! F_42 ( V_88 -> V_30 ) && V_117 )
F_57 () ;
if ( V_118 )
F_106 ( V_7 , & V_86 ) ;
F_78 ( & V_86 ) ;
V_46:
F_36 ( V_88 ) ;
return V_119 ;
}
static void F_110 ( struct V_121 * V_122 )
{
V_122 -> V_123 = 0 ;
V_122 -> V_113 = 0 ;
V_122 -> time = 0 ;
F_111 ( & V_122 -> V_124 ) ;
}
static void F_112 ( struct V_121 * V_122 )
{
T_5 V_125 = F_113 () ;
T_5 V_126 = V_125 - V_122 -> time ;
if ( V_126 == 0 )
return;
V_126 = F_114 ( V_127 , V_126 ) ;
while ( V_126 -- > 0 )
V_122 -> V_113 = ( V_128 * V_122 -> V_113 ) / V_129 ;
V_122 -> time = V_125 ;
V_122 -> V_113 += ( ( V_129 - V_128 ) * V_122 -> V_123 ) / V_129 ;
V_122 -> V_123 = 0 ;
}
static void F_115 ( struct V_121 * V_122 )
{
F_116 ( & V_122 -> V_124 ) ;
F_112 ( V_122 ) ;
V_122 -> V_123 = F_114 ( V_130 , V_122 -> V_123 + V_129 ) ;
F_117 ( & V_122 -> V_124 ) ;
}
static int F_118 ( struct V_121 * V_122 )
{
int V_113 ;
F_116 ( & V_122 -> V_124 ) ;
F_112 ( V_122 ) ;
V_113 = V_122 -> V_113 ;
F_117 ( & V_122 -> V_124 ) ;
return V_113 ;
}
static int F_119 ( struct V_2 * V_3 ,
struct V_131 * V_132 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_4 * V_5 ;
int V_24 ;
F_64 ( & V_82 ) ;
V_24 = - V_50 ;
if ( ! F_120 ( V_3 -> V_51 ) &&
( F_42 ( V_7 -> V_30 ) || F_43 ( V_7 -> V_32 ) ) )
goto V_133;
F_121 (task, css, tset) {
V_24 = - V_49 ;
if ( V_5 -> V_10 & V_134 )
goto V_133;
V_24 = F_122 ( V_5 ) ;
if ( V_24 )
goto V_133;
}
V_7 -> V_52 ++ ;
V_24 = 0 ;
V_133:
F_65 ( & V_82 ) ;
return V_24 ;
}
static void F_123 ( struct V_2 * V_3 ,
struct V_131 * V_132 )
{
F_64 ( & V_82 ) ;
F_1 ( V_3 ) -> V_52 -- ;
F_65 ( & V_82 ) ;
}
static void F_124 ( struct V_2 * V_3 ,
struct V_131 * V_132 )
{
static T_1 V_135 ;
struct V_94 * V_95 ;
struct V_4 * V_5 ;
struct V_4 * V_136 = F_125 ( V_132 ) ;
struct V_2 * V_137 = F_126 ( V_132 ,
V_6 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_138 = F_1 ( V_137 ) ;
struct V_1 * V_84 = F_66 ( V_7 ) ;
struct V_1 * V_99 = F_67 ( V_7 ) ;
F_64 ( & V_82 ) ;
if ( V_7 == & V_47 )
F_35 ( V_139 , V_140 ) ;
else
F_21 ( V_84 , V_139 ) ;
F_24 ( V_99 , & V_135 ) ;
F_121 (task, css, tset) {
F_127 ( F_69 ( V_5 , V_139 ) ) ;
F_81 ( V_5 , & V_135 ) ;
F_27 ( V_7 , V_5 ) ;
}
V_135 = V_7 -> V_32 ;
V_95 = F_93 ( V_136 ) ;
if ( V_95 ) {
struct V_1 * V_141 = F_67 ( V_138 ) ;
F_94 ( V_95 , & V_135 ) ;
if ( F_14 ( V_7 ) ) {
F_79 ( V_95 , & V_141 -> V_111 ,
& V_135 ) ;
}
F_95 ( V_95 ) ;
}
V_7 -> V_111 = V_135 ;
V_7 -> V_52 -- ;
if ( ! V_7 -> V_52 )
F_128 ( & V_142 ) ;
F_65 ( & V_82 ) ;
}
static int F_129 ( struct V_2 * V_3 , struct V_143 * V_144 ,
T_6 V_113 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_144 -> V_145 ;
int V_90 = 0 ;
F_64 ( & V_82 ) ;
if ( ! F_8 ( V_7 ) ) {
V_90 = - V_25 ;
goto V_133;
}
switch ( type ) {
case V_146 :
V_90 = F_107 ( V_11 , V_7 , V_113 ) ;
break;
case V_147 :
V_90 = F_107 ( V_12 , V_7 , V_113 ) ;
break;
case V_148 :
V_90 = F_107 ( V_13 , V_7 , V_113 ) ;
break;
case V_149 :
V_90 = F_107 ( V_14 , V_7 , V_113 ) ;
break;
case V_150 :
V_90 = F_107 ( V_15 , V_7 , V_113 ) ;
break;
case V_151 :
V_152 = ! ! V_113 ;
break;
case V_153 :
V_90 = - V_48 ;
break;
case V_154 :
V_90 = F_107 ( V_16 , V_7 , V_113 ) ;
break;
case V_155 :
V_90 = F_107 ( V_17 , V_7 , V_113 ) ;
break;
default:
V_90 = - V_49 ;
break;
}
V_133:
F_65 ( & V_82 ) ;
return V_90 ;
}
static int F_130 ( struct V_2 * V_3 , struct V_143 * V_144 ,
T_3 V_113 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_144 -> V_145 ;
int V_90 = - V_25 ;
F_64 ( & V_82 ) ;
if ( ! F_8 ( V_7 ) )
goto V_133;
switch ( type ) {
case V_156 :
V_90 = F_103 ( V_7 , V_113 ) ;
break;
default:
V_90 = - V_49 ;
break;
}
V_133:
F_65 ( & V_82 ) ;
return V_90 ;
}
static int F_131 ( struct V_2 * V_3 ,
struct V_143 * V_144 , const char * V_89 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_88 ;
int V_90 = - V_25 ;
F_132 ( & V_157 ) ;
F_64 ( & V_82 ) ;
if ( ! F_8 ( V_7 ) )
goto V_133;
V_88 = F_31 ( V_7 ) ;
if ( ! V_88 ) {
V_90 = - V_120 ;
goto V_133;
}
switch ( V_144 -> V_145 ) {
case V_158 :
V_90 = F_75 ( V_7 , V_88 , V_89 ) ;
break;
case V_159 :
V_90 = F_98 ( V_7 , V_88 , V_89 ) ;
break;
default:
V_90 = - V_49 ;
break;
}
F_36 ( V_88 ) ;
V_133:
F_65 ( & V_82 ) ;
return V_90 ;
}
static T_8 F_133 ( char * V_160 , struct V_1 * V_7 )
{
T_8 V_161 ;
F_64 ( & V_93 ) ;
V_161 = F_134 ( V_160 , V_92 , V_7 -> V_30 ) ;
F_65 ( & V_93 ) ;
return V_161 ;
}
static T_8 F_135 ( char * V_160 , struct V_1 * V_7 )
{
T_8 V_161 ;
F_64 ( & V_93 ) ;
V_161 = F_136 ( V_160 , V_92 , V_7 -> V_32 ) ;
F_65 ( & V_93 ) ;
return V_161 ;
}
static T_9 F_137 ( struct V_2 * V_3 ,
struct V_143 * V_144 , struct V_162 * V_162 ,
char T_10 * V_89 , T_8 V_163 ,
T_11 * V_164 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_144 -> V_145 ;
char * V_160 ;
T_9 V_90 = 0 ;
char * V_165 ;
if ( ! ( V_160 = ( char * ) F_138 ( V_166 ) ) )
return - V_120 ;
V_165 = V_160 ;
switch ( type ) {
case V_158 :
V_165 += F_133 ( V_165 , V_7 ) ;
break;
case V_159 :
V_165 += F_135 ( V_165 , V_7 ) ;
break;
default:
V_90 = - V_49 ;
goto V_46;
}
* V_165 ++ = '\n' ;
V_90 = F_139 ( V_89 , V_163 , V_164 , V_160 , V_165 - V_160 ) ;
V_46:
F_140 ( ( unsigned long ) V_160 ) ;
return V_90 ;
}
static T_6 F_141 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_144 -> V_145 ;
switch ( type ) {
case V_146 :
return F_10 ( V_7 ) ;
case V_147 :
return F_11 ( V_7 ) ;
case V_148 :
return F_12 ( V_7 ) ;
case V_149 :
return F_13 ( V_7 ) ;
case V_150 :
return F_14 ( V_7 ) ;
case V_151 :
return V_152 ;
case V_153 :
return F_118 ( & V_7 -> V_121 ) ;
case V_154 :
return F_15 ( V_7 ) ;
case V_155 :
return F_16 ( V_7 ) ;
default:
F_142 () ;
}
return 0 ;
}
static T_3 F_143 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_144 -> V_145 ;
switch ( type ) {
case V_156 :
return V_7 -> V_57 ;
default:
F_142 () ;
}
return 0 ;
}
static struct V_2 *
F_144 ( struct V_2 * V_167 )
{
struct V_1 * V_7 ;
if ( ! V_167 )
return & V_47 . V_3 ;
V_7 = F_145 ( sizeof( * V_7 ) , V_41 ) ;
if ( ! V_7 )
return F_19 ( - V_120 ) ;
if ( ! F_33 ( & V_7 -> V_30 , V_41 ) ) {
F_34 ( V_7 ) ;
return F_19 ( - V_120 ) ;
}
F_108 ( V_14 , & V_7 -> V_10 ) ;
F_54 ( V_7 -> V_30 ) ;
F_99 ( V_7 -> V_32 ) ;
F_110 ( & V_7 -> V_121 ) ;
V_7 -> V_57 = - 1 ;
return & V_7 -> V_3 ;
}
static int F_146 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_168 = F_5 ( V_7 ) ;
struct V_1 * V_169 ;
struct V_2 * V_60 ;
if ( ! V_168 )
return 0 ;
F_64 ( & V_82 ) ;
F_108 ( V_9 , & V_7 -> V_10 ) ;
if ( F_15 ( V_168 ) )
F_108 ( V_16 , & V_7 -> V_10 ) ;
if ( F_16 ( V_168 ) )
F_108 ( V_17 , & V_7 -> V_10 ) ;
V_73 ++ ;
if ( ! F_9 ( V_170 , & V_3 -> V_51 -> V_10 ) )
goto V_133;
F_39 () ;
F_40 (tmp_cs, pos_css, parent) {
if ( F_11 ( V_169 ) || F_10 ( V_169 ) ) {
F_44 () ;
goto V_133;
}
}
F_44 () ;
F_64 ( & V_93 ) ;
V_7 -> V_32 = V_168 -> V_32 ;
F_35 ( V_7 -> V_30 , V_168 -> V_30 ) ;
F_65 ( & V_93 ) ;
V_133:
F_65 ( & V_82 ) ;
return 0 ;
}
static void F_147 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_64 ( & V_82 ) ;
if ( F_13 ( V_7 ) )
F_107 ( V_14 , V_7 , 0 ) ;
V_73 -- ;
F_109 ( V_9 , & V_7 -> V_10 ) ;
F_65 ( & V_82 ) ;
}
static void F_148 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_37 ( V_7 -> V_30 ) ;
F_34 ( V_7 ) ;
}
int T_12 F_149 ( void )
{
int V_119 = 0 ;
if ( ! F_33 ( & V_47 . V_30 , V_41 ) )
F_142 () ;
F_150 ( V_47 . V_30 ) ;
F_151 ( V_47 . V_32 ) ;
F_110 ( & V_47 . V_121 ) ;
F_108 ( V_14 , & V_47 . V_10 ) ;
V_47 . V_57 = - 1 ;
V_119 = F_152 ( & V_171 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( ! F_33 ( & V_139 , V_41 ) )
F_142 () ;
V_73 = 1 ;
return 0 ;
}
static void F_153 ( struct V_1 * V_7 )
{
struct V_1 * V_168 ;
V_168 = F_5 ( V_7 ) ;
while ( F_42 ( V_168 -> V_30 ) ||
F_43 ( V_168 -> V_32 ) )
V_168 = F_5 ( V_168 ) ;
if ( F_154 ( V_168 -> V_3 . V_51 , V_7 -> V_3 . V_51 ) ) {
F_39 () ;
F_53 ( V_172 L_7 ,
F_155 ( V_7 -> V_3 . V_51 ) ) ;
F_44 () ;
}
}
static void F_156 ( struct V_1 * V_7 )
{
static T_13 V_173 ;
static T_1 V_174 ;
bool V_175 ;
bool V_176 = F_120 ( V_7 -> V_3 . V_51 ) ;
V_177:
F_157 ( V_142 , V_7 -> V_52 == 0 ) ;
F_64 ( & V_82 ) ;
if ( V_7 -> V_52 ) {
F_65 ( & V_82 ) ;
goto V_177;
}
F_158 ( & V_173 , V_7 -> V_30 , V_47 . V_30 ) ;
F_159 ( V_174 , V_7 -> V_32 , V_47 . V_32 ) ;
F_64 ( & V_93 ) ;
F_158 ( V_7 -> V_30 , V_7 -> V_30 , & V_173 ) ;
F_65 ( & V_93 ) ;
if ( ( V_176 && F_42 ( V_7 -> V_30 ) ) ||
( ! F_42 ( & V_173 ) && ! F_42 ( V_7 -> V_30 ) ) )
F_70 ( V_7 , NULL ) ;
F_64 ( & V_93 ) ;
F_159 ( V_7 -> V_32 , V_7 -> V_32 , V_174 ) ;
F_65 ( & V_93 ) ;
if ( ( V_176 && F_43 ( V_7 -> V_32 ) ) ||
( ! F_43 ( V_174 ) && ! F_43 ( V_7 -> V_32 ) ) )
F_96 ( V_7 , NULL ) ;
V_175 = F_42 ( V_7 -> V_30 ) ||
F_43 ( V_7 -> V_32 ) ;
F_65 ( & V_82 ) ;
if ( ! V_176 && V_175 )
F_153 ( V_7 ) ;
}
static void F_160 ( struct V_178 * V_179 )
{
static T_13 V_180 ;
static T_1 V_181 ;
bool V_182 , V_183 ;
F_64 ( & V_82 ) ;
F_35 ( & V_180 , V_83 ) ;
V_181 = V_33 [ V_34 ] ;
V_182 = ! F_60 ( V_47 . V_30 , & V_180 ) ;
V_183 = ! F_101 ( V_47 . V_32 , V_181 ) ;
if ( V_182 ) {
F_64 ( & V_93 ) ;
F_35 ( V_47 . V_30 , & V_180 ) ;
F_65 ( & V_93 ) ;
}
if ( V_183 ) {
F_64 ( & V_93 ) ;
V_47 . V_32 = V_181 ;
F_65 ( & V_93 ) ;
F_96 ( & V_47 , NULL ) ;
}
F_65 ( & V_82 ) ;
if ( V_182 || V_183 ) {
struct V_1 * V_7 ;
struct V_2 * V_60 ;
F_39 () ;
F_48 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_47 || ! F_73 ( & V_7 -> V_3 ) )
continue;
F_44 () ;
F_156 ( V_7 ) ;
F_39 () ;
F_74 ( & V_7 -> V_3 ) ;
}
F_44 () ;
}
if ( V_182 )
F_63 () ;
}
void F_161 ( bool V_184 )
{
F_61 ( 1 , NULL , NULL ) ;
F_162 ( & V_157 ) ;
}
static int F_163 ( struct V_185 * V_186 ,
unsigned long V_187 , void * V_109 )
{
F_162 ( & V_157 ) ;
return V_188 ;
}
void T_12 F_164 ( void )
{
F_35 ( V_47 . V_30 , V_83 ) ;
V_47 . V_32 = V_33 [ V_34 ] ;
V_47 . V_111 = V_47 . V_32 ;
F_165 ( & V_189 ) ;
}
void F_166 ( struct V_4 * V_35 , struct V_28 * V_29 )
{
struct V_1 * V_84 ;
F_64 ( & V_93 ) ;
F_84 ( V_35 ) ;
V_84 = F_66 ( F_3 ( V_35 ) ) ;
F_21 ( V_84 , V_29 ) ;
F_91 ( V_35 ) ;
F_65 ( & V_93 ) ;
}
void F_167 ( struct V_4 * V_35 )
{
struct V_1 * V_84 ;
F_39 () ;
V_84 = F_66 ( F_3 ( V_35 ) ) ;
F_168 ( V_35 , V_84 -> V_30 ) ;
F_44 () ;
}
void F_169 ( void )
{
F_151 ( V_98 -> V_32 ) ;
}
T_1 F_170 ( struct V_4 * V_35 )
{
struct V_1 * V_99 ;
T_1 V_190 ;
F_64 ( & V_93 ) ;
F_84 ( V_35 ) ;
V_99 = F_67 ( F_3 ( V_35 ) ) ;
F_24 ( V_99 , & V_190 ) ;
F_91 ( V_35 ) ;
F_65 ( & V_93 ) ;
return V_190 ;
}
int F_171 ( T_1 * V_191 )
{
return F_25 ( * V_191 , V_98 -> V_32 ) ;
}
static struct V_1 * F_172 ( struct V_1 * V_7 )
{
while ( ! ( F_11 ( V_7 ) || F_12 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
int F_173 ( int V_192 , T_14 V_193 )
{
struct V_1 * V_7 ;
int V_194 ;
if ( F_174 () || ( V_193 & V_195 ) )
return 1 ;
F_175 ( ! ( V_193 & V_196 ) ) ;
if ( F_176 ( V_192 , V_98 -> V_32 ) )
return 1 ;
if ( F_82 ( F_83 ( V_103 ) ) )
return 1 ;
if ( V_193 & V_196 )
return 0 ;
if ( V_98 -> V_10 & V_104 )
return 1 ;
F_64 ( & V_93 ) ;
F_84 ( V_98 ) ;
V_7 = F_172 ( F_3 ( V_98 ) ) ;
F_91 ( V_98 ) ;
V_194 = F_176 ( V_192 , V_7 -> V_32 ) ;
F_65 ( & V_93 ) ;
return V_194 ;
}
int F_177 ( int V_192 , T_14 V_193 )
{
if ( F_174 () || ( V_193 & V_195 ) )
return 1 ;
if ( F_176 ( V_192 , V_98 -> V_32 ) )
return 1 ;
if ( F_82 ( F_83 ( V_103 ) ) )
return 1 ;
return 0 ;
}
static int F_178 ( int * V_197 )
{
int V_192 ;
V_192 = F_179 ( * V_197 , V_98 -> V_32 ) ;
if ( V_192 == V_198 )
V_192 = F_180 ( V_98 -> V_32 ) ;
* V_197 = V_192 ;
return V_192 ;
}
int F_181 ( void )
{
if ( V_98 -> V_199 == V_200 )
V_98 -> V_199 =
F_182 ( & V_98 -> V_32 ) ;
return F_178 ( & V_98 -> V_199 ) ;
}
int F_183 ( void )
{
if ( V_98 -> V_201 == V_200 )
V_98 -> V_201 =
F_182 ( & V_98 -> V_32 ) ;
return F_178 ( & V_98 -> V_201 ) ;
}
int F_184 ( const struct V_4 * V_202 ,
const struct V_4 * V_203 )
{
return F_25 ( V_202 -> V_32 , V_203 -> V_32 ) ;
}
void F_185 ( struct V_4 * V_35 )
{
static char V_204 [ V_205 ] ;
static F_186 ( V_206 ) ;
struct V_51 * V_207 = F_3 ( V_35 ) -> V_3 . V_51 ;
F_39 () ;
F_116 ( & V_206 ) ;
F_136 ( V_204 , V_205 ,
V_35 -> V_32 ) ;
F_53 ( V_208 L_8 ,
V_35 -> V_209 , F_155 ( V_207 ) , V_204 ) ;
F_117 ( & V_206 ) ;
F_44 () ;
}
void F_187 ( void )
{
F_84 ( V_98 ) ;
F_115 ( & F_3 ( V_98 ) -> V_121 ) ;
F_91 ( V_98 ) ;
}
int F_188 ( struct V_210 * V_211 , void * V_212 )
{
struct V_213 * V_213 ;
struct V_4 * V_35 ;
char * V_89 ;
struct V_2 * V_3 ;
int V_90 ;
V_90 = - V_120 ;
V_89 = F_52 ( V_92 , V_41 ) ;
if ( ! V_89 )
goto V_46;
V_90 = - V_214 ;
V_213 = V_211 -> V_145 ;
V_35 = F_189 ( V_213 , V_215 ) ;
if ( ! V_35 )
goto V_216;
F_39 () ;
V_3 = F_4 ( V_35 , V_6 ) ;
V_90 = F_190 ( V_3 -> V_51 , V_89 , V_92 ) ;
F_44 () ;
if ( V_90 < 0 )
goto V_217;
F_191 ( V_211 , V_89 ) ;
F_192 ( V_211 , '\n' ) ;
V_217:
F_193 ( V_35 ) ;
V_216:
F_34 ( V_89 ) ;
V_46:
return V_90 ;
}
void F_194 ( struct V_210 * V_211 , struct V_4 * V_5 )
{
F_195 ( V_211 , L_9 ) ;
F_196 ( V_211 , & V_5 -> V_32 ) ;
F_195 ( V_211 , L_10 ) ;
F_195 ( V_211 , L_11 ) ;
F_197 ( V_211 , & V_5 -> V_32 ) ;
F_195 ( V_211 , L_10 ) ;
}
