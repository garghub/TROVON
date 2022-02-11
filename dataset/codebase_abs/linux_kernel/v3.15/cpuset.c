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
static void F_68 ( struct V_1 * V_7 )
{
struct V_1 * V_84 = F_66 ( V_7 ) ;
struct V_85 V_86 ;
struct V_4 * V_5 ;
F_69 ( & V_7 -> V_3 , & V_86 ) ;
while ( ( V_5 = F_70 ( & V_86 ) ) )
F_71 ( V_5 , V_84 -> V_30 ) ;
F_72 ( & V_86 ) ;
}
static void F_73 ( struct V_1 * V_58 , bool V_87 )
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
if ( ! F_74 ( & V_59 -> V_3 ) )
continue;
F_44 () ;
F_68 ( V_59 ) ;
F_39 () ;
F_75 ( & V_59 -> V_3 ) ;
}
F_44 () ;
}
static int F_76 ( struct V_1 * V_7 , struct V_1 * V_88 ,
const char * V_89 )
{
int V_90 ;
int V_91 ;
if ( V_7 == & V_47 )
return - V_48 ;
if ( ! * V_89 ) {
F_54 ( V_88 -> V_30 ) ;
} else {
V_90 = F_77 ( V_89 , V_88 -> V_30 ) ;
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
V_91 = F_13 ( V_88 ) ;
F_64 ( & V_92 ) ;
F_35 ( V_7 -> V_30 , V_88 -> V_30 ) ;
F_65 ( & V_92 ) ;
F_73 ( V_7 , true ) ;
if ( V_91 )
F_57 () ;
return 0 ;
}
static void F_78 ( struct V_93 * V_94 , const T_1 * V_95 ,
const T_1 * V_96 )
{
struct V_4 * V_35 = V_97 ;
struct V_1 * V_98 ;
V_35 -> V_32 = * V_96 ;
F_79 ( V_94 , V_95 , V_96 , V_99 ) ;
F_39 () ;
V_98 = F_67 ( F_3 ( V_35 ) ) ;
F_24 ( V_98 , & V_35 -> V_32 ) ;
F_44 () ;
}
static void F_80 ( struct V_4 * V_35 ,
T_1 * V_100 )
{
bool V_101 ;
if ( F_81 ( F_82 ( V_102 ) ) )
return;
if ( V_97 -> V_10 & V_103 )
return;
F_83 ( V_35 ) ;
V_101 = F_7 ( V_35 ) ||
! F_25 ( * V_100 , V_35 -> V_32 ) ;
if ( V_101 ) {
F_84 () ;
F_85 ( & V_35 -> V_104 ) ;
}
F_86 ( V_35 -> V_32 , V_35 -> V_32 , * V_100 ) ;
F_87 ( V_35 , V_100 , V_105 ) ;
F_87 ( V_35 , V_100 , V_106 ) ;
V_35 -> V_32 = * V_100 ;
if ( V_101 ) {
F_88 ( & V_35 -> V_104 ) ;
F_89 () ;
}
F_90 ( V_35 ) ;
}
static void F_91 ( struct V_1 * V_7 )
{
static T_1 V_100 ;
struct V_1 * V_98 = F_67 ( V_7 ) ;
struct V_85 V_86 ;
struct V_4 * V_5 ;
V_107 = V_7 ;
F_24 ( V_98 , & V_100 ) ;
F_69 ( & V_7 -> V_3 , & V_86 ) ;
while ( ( V_5 = F_70 ( & V_86 ) ) ) {
struct V_93 * V_94 ;
bool V_108 ;
F_80 ( V_5 , & V_100 ) ;
V_94 = F_92 ( V_5 ) ;
if ( ! V_94 )
continue;
V_108 = F_14 ( V_7 ) ;
F_93 ( V_94 , & V_7 -> V_32 ) ;
if ( V_108 )
F_78 ( V_94 , & V_7 -> V_109 , & V_100 ) ;
F_94 ( V_94 ) ;
}
F_72 ( & V_86 ) ;
V_7 -> V_109 = V_100 ;
V_107 = NULL ;
}
static void F_95 ( struct V_1 * V_58 , bool V_87 )
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
if ( ! F_74 ( & V_59 -> V_3 ) )
continue;
F_44 () ;
F_91 ( V_59 ) ;
F_39 () ;
F_75 ( & V_59 -> V_3 ) ;
}
F_44 () ;
}
static int F_96 ( struct V_1 * V_7 , struct V_1 * V_88 ,
const char * V_89 )
{
int V_90 ;
if ( V_7 == & V_47 ) {
V_90 = - V_48 ;
goto V_71;
}
if ( ! * V_89 ) {
F_97 ( V_88 -> V_32 ) ;
} else {
V_90 = F_98 ( V_89 , V_88 -> V_32 ) ;
if ( V_90 < 0 )
goto V_71;
if ( ! F_30 ( V_88 -> V_32 ,
V_33 [ V_34 ] ) ) {
V_90 = - V_49 ;
goto V_71;
}
}
if ( F_99 ( V_7 -> V_32 , V_88 -> V_32 ) ) {
V_90 = 0 ;
goto V_71;
}
V_90 = F_38 ( V_7 , V_88 ) ;
if ( V_90 < 0 )
goto V_71;
F_64 ( & V_92 ) ;
V_7 -> V_32 = V_88 -> V_32 ;
F_65 ( & V_92 ) ;
F_95 ( V_7 , true ) ;
V_71:
return V_90 ;
}
int F_100 ( void )
{
return F_3 ( V_97 ) == V_107 ;
}
static int F_101 ( struct V_1 * V_7 , T_3 V_110 )
{
#ifdef F_102
if ( V_110 < - 1 || V_110 >= V_111 )
return - V_49 ;
#endif
if ( V_110 != V_7 -> V_57 ) {
V_7 -> V_57 = V_110 ;
if ( ! F_42 ( V_7 -> V_30 ) &&
F_13 ( V_7 ) )
F_57 () ;
}
return 0 ;
}
static void F_103 ( struct V_1 * V_7 )
{
struct V_85 V_86 ;
struct V_4 * V_5 ;
F_69 ( & V_7 -> V_3 , & V_86 ) ;
while ( ( V_5 = F_70 ( & V_86 ) ) )
F_27 ( V_7 , V_5 ) ;
F_72 ( & V_86 ) ;
}
static int F_104 ( T_4 V_112 , struct V_1 * V_7 ,
int V_113 )
{
struct V_1 * V_88 ;
int V_114 ;
int V_115 ;
int V_116 ;
V_88 = F_31 ( V_7 ) ;
if ( ! V_88 )
return - V_117 ;
if ( V_113 )
F_105 ( V_112 , & V_88 -> V_10 ) ;
else
F_106 ( V_112 , & V_88 -> V_10 ) ;
V_116 = F_38 ( V_7 , V_88 ) ;
if ( V_116 < 0 )
goto V_46;
V_114 = ( F_13 ( V_7 ) !=
F_13 ( V_88 ) ) ;
V_115 = ( ( F_16 ( V_7 ) != F_16 ( V_88 ) )
|| ( F_15 ( V_7 ) != F_15 ( V_88 ) ) ) ;
F_64 ( & V_92 ) ;
V_7 -> V_10 = V_88 -> V_10 ;
F_65 ( & V_92 ) ;
if ( ! F_42 ( V_88 -> V_30 ) && V_114 )
F_57 () ;
if ( V_115 )
F_103 ( V_7 ) ;
V_46:
F_36 ( V_88 ) ;
return V_116 ;
}
static void F_107 ( struct V_118 * V_119 )
{
V_119 -> V_120 = 0 ;
V_119 -> V_110 = 0 ;
V_119 -> time = 0 ;
F_108 ( & V_119 -> V_121 ) ;
}
static void F_109 ( struct V_118 * V_119 )
{
T_5 V_122 = F_110 () ;
T_5 V_123 = V_122 - V_119 -> time ;
if ( V_123 == 0 )
return;
V_123 = F_111 ( V_124 , V_123 ) ;
while ( V_123 -- > 0 )
V_119 -> V_110 = ( V_125 * V_119 -> V_110 ) / V_126 ;
V_119 -> time = V_122 ;
V_119 -> V_110 += ( ( V_126 - V_125 ) * V_119 -> V_120 ) / V_126 ;
V_119 -> V_120 = 0 ;
}
static void F_112 ( struct V_118 * V_119 )
{
F_113 ( & V_119 -> V_121 ) ;
F_109 ( V_119 ) ;
V_119 -> V_120 = F_111 ( V_127 , V_119 -> V_120 + V_126 ) ;
F_114 ( & V_119 -> V_121 ) ;
}
static int F_115 ( struct V_118 * V_119 )
{
int V_110 ;
F_113 ( & V_119 -> V_121 ) ;
F_109 ( V_119 ) ;
V_110 = V_119 -> V_110 ;
F_114 ( & V_119 -> V_121 ) ;
return V_110 ;
}
static int F_116 ( struct V_2 * V_3 ,
struct V_128 * V_129 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_4 * V_5 ;
int V_24 ;
V_130 = F_3 ( F_117 ( V_129 ) ) ;
F_64 ( & V_82 ) ;
V_24 = - V_50 ;
if ( ! F_118 ( V_3 -> V_51 ) &&
( F_42 ( V_7 -> V_30 ) || F_43 ( V_7 -> V_32 ) ) )
goto V_131;
F_119 (task, tset) {
V_24 = - V_49 ;
if ( V_5 -> V_10 & V_132 )
goto V_131;
V_24 = F_120 ( V_5 ) ;
if ( V_24 )
goto V_131;
}
V_7 -> V_52 ++ ;
V_24 = 0 ;
V_131:
F_65 ( & V_82 ) ;
return V_24 ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_128 * V_129 )
{
F_64 ( & V_82 ) ;
F_1 ( V_3 ) -> V_52 -- ;
F_65 ( & V_82 ) ;
}
static void F_122 ( struct V_2 * V_3 ,
struct V_128 * V_129 )
{
static T_1 V_133 ;
struct V_93 * V_94 ;
struct V_4 * V_5 ;
struct V_4 * V_134 = F_117 ( V_129 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_135 = V_130 ;
struct V_1 * V_84 = F_66 ( V_7 ) ;
struct V_1 * V_98 = F_67 ( V_7 ) ;
F_64 ( & V_82 ) ;
if ( V_7 == & V_47 )
F_35 ( V_136 , V_137 ) ;
else
F_21 ( V_84 , V_136 ) ;
F_24 ( V_98 , & V_133 ) ;
F_119 (task, tset) {
F_123 ( F_71 ( V_5 , V_136 ) ) ;
F_80 ( V_5 , & V_133 ) ;
F_27 ( V_7 , V_5 ) ;
}
V_133 = V_7 -> V_32 ;
V_94 = F_92 ( V_134 ) ;
if ( V_94 ) {
struct V_1 * V_138 = F_67 ( V_135 ) ;
F_93 ( V_94 , & V_133 ) ;
if ( F_14 ( V_7 ) ) {
F_78 ( V_94 , & V_138 -> V_109 ,
& V_133 ) ;
}
F_94 ( V_94 ) ;
}
V_7 -> V_109 = V_133 ;
V_7 -> V_52 -- ;
if ( ! V_7 -> V_52 )
F_124 ( & V_139 ) ;
F_65 ( & V_82 ) ;
}
static int F_125 ( struct V_2 * V_3 , struct V_140 * V_141 ,
T_6 V_110 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_141 -> V_142 ;
int V_90 = 0 ;
F_64 ( & V_82 ) ;
if ( ! F_8 ( V_7 ) ) {
V_90 = - V_25 ;
goto V_131;
}
switch ( type ) {
case V_143 :
V_90 = F_104 ( V_11 , V_7 , V_110 ) ;
break;
case V_144 :
V_90 = F_104 ( V_12 , V_7 , V_110 ) ;
break;
case V_145 :
V_90 = F_104 ( V_13 , V_7 , V_110 ) ;
break;
case V_146 :
V_90 = F_104 ( V_14 , V_7 , V_110 ) ;
break;
case V_147 :
V_90 = F_104 ( V_15 , V_7 , V_110 ) ;
break;
case V_148 :
V_149 = ! ! V_110 ;
break;
case V_150 :
V_90 = - V_48 ;
break;
case V_151 :
V_90 = F_104 ( V_16 , V_7 , V_110 ) ;
break;
case V_152 :
V_90 = F_104 ( V_17 , V_7 , V_110 ) ;
break;
default:
V_90 = - V_49 ;
break;
}
V_131:
F_65 ( & V_82 ) ;
return V_90 ;
}
static int F_126 ( struct V_2 * V_3 , struct V_140 * V_141 ,
T_3 V_110 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_141 -> V_142 ;
int V_90 = - V_25 ;
F_64 ( & V_82 ) ;
if ( ! F_8 ( V_7 ) )
goto V_131;
switch ( type ) {
case V_153 :
V_90 = F_101 ( V_7 , V_110 ) ;
break;
default:
V_90 = - V_49 ;
break;
}
V_131:
F_65 ( & V_82 ) ;
return V_90 ;
}
static int F_127 ( struct V_2 * V_3 ,
struct V_140 * V_141 , char * V_89 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_88 ;
int V_90 = - V_25 ;
F_128 ( & V_154 ) ;
F_64 ( & V_82 ) ;
if ( ! F_8 ( V_7 ) )
goto V_131;
V_88 = F_31 ( V_7 ) ;
if ( ! V_88 ) {
V_90 = - V_117 ;
goto V_131;
}
switch ( V_141 -> V_142 ) {
case V_155 :
V_90 = F_76 ( V_7 , V_88 , V_89 ) ;
break;
case V_156 :
V_90 = F_96 ( V_7 , V_88 , V_89 ) ;
break;
default:
V_90 = - V_49 ;
break;
}
F_36 ( V_88 ) ;
V_131:
F_65 ( & V_82 ) ;
return V_90 ;
}
static int F_129 ( struct V_157 * V_158 , void * V_159 )
{
struct V_1 * V_7 = F_1 ( F_130 ( V_158 ) ) ;
T_7 type = F_131 ( V_158 ) -> V_142 ;
T_8 V_160 ;
char * V_89 , * V_161 ;
int V_24 = 0 ;
V_160 = F_132 ( V_158 , & V_89 ) ;
V_161 = V_89 ;
F_64 ( & V_92 ) ;
switch ( type ) {
case V_155 :
V_161 += F_133 ( V_161 , V_160 , V_7 -> V_30 ) ;
break;
case V_156 :
V_161 += F_134 ( V_161 , V_160 , V_7 -> V_32 ) ;
break;
default:
V_24 = - V_49 ;
goto V_131;
}
if ( V_161 < V_89 + V_160 - 1 ) {
* V_161 ++ = '\n' ;
F_135 ( V_158 , V_161 - V_89 ) ;
} else {
F_135 ( V_158 , - 1 ) ;
}
V_131:
F_65 ( & V_92 ) ;
return V_24 ;
}
static T_6 F_136 ( struct V_2 * V_3 , struct V_140 * V_141 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_141 -> V_142 ;
switch ( type ) {
case V_143 :
return F_10 ( V_7 ) ;
case V_144 :
return F_11 ( V_7 ) ;
case V_145 :
return F_12 ( V_7 ) ;
case V_146 :
return F_13 ( V_7 ) ;
case V_147 :
return F_14 ( V_7 ) ;
case V_148 :
return V_149 ;
case V_150 :
return F_115 ( & V_7 -> V_118 ) ;
case V_151 :
return F_15 ( V_7 ) ;
case V_152 :
return F_16 ( V_7 ) ;
default:
F_137 () ;
}
return 0 ;
}
static T_3 F_138 ( struct V_2 * V_3 , struct V_140 * V_141 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_141 -> V_142 ;
switch ( type ) {
case V_153 :
return V_7 -> V_57 ;
default:
F_137 () ;
}
return 0 ;
}
static struct V_2 *
F_139 ( struct V_2 * V_162 )
{
struct V_1 * V_7 ;
if ( ! V_162 )
return & V_47 . V_3 ;
V_7 = F_140 ( sizeof( * V_7 ) , V_41 ) ;
if ( ! V_7 )
return F_19 ( - V_117 ) ;
if ( ! F_33 ( & V_7 -> V_30 , V_41 ) ) {
F_34 ( V_7 ) ;
return F_19 ( - V_117 ) ;
}
F_105 ( V_14 , & V_7 -> V_10 ) ;
F_54 ( V_7 -> V_30 ) ;
F_97 ( V_7 -> V_32 ) ;
F_107 ( & V_7 -> V_118 ) ;
V_7 -> V_57 = - 1 ;
return & V_7 -> V_3 ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_163 = F_5 ( V_7 ) ;
struct V_1 * V_164 ;
struct V_2 * V_60 ;
if ( ! V_163 )
return 0 ;
F_64 ( & V_82 ) ;
F_105 ( V_9 , & V_7 -> V_10 ) ;
if ( F_15 ( V_163 ) )
F_105 ( V_16 , & V_7 -> V_10 ) ;
if ( F_16 ( V_163 ) )
F_105 ( V_17 , & V_7 -> V_10 ) ;
V_73 ++ ;
if ( ! F_9 ( V_165 , & V_3 -> V_51 -> V_10 ) )
goto V_131;
F_39 () ;
F_40 (tmp_cs, pos_css, parent) {
if ( F_11 ( V_164 ) || F_10 ( V_164 ) ) {
F_44 () ;
goto V_131;
}
}
F_44 () ;
F_64 ( & V_92 ) ;
V_7 -> V_32 = V_163 -> V_32 ;
F_35 ( V_7 -> V_30 , V_163 -> V_30 ) ;
F_65 ( & V_92 ) ;
V_131:
F_65 ( & V_82 ) ;
return 0 ;
}
static void F_142 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_64 ( & V_82 ) ;
if ( F_13 ( V_7 ) )
F_104 ( V_14 , V_7 , 0 ) ;
V_73 -- ;
F_106 ( V_9 , & V_7 -> V_10 ) ;
F_65 ( & V_82 ) ;
}
static void F_143 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_37 ( V_7 -> V_30 ) ;
F_34 ( V_7 ) ;
}
int T_9 F_144 ( void )
{
int V_116 = 0 ;
if ( ! F_33 ( & V_47 . V_30 , V_41 ) )
F_137 () ;
F_145 ( V_47 . V_30 ) ;
F_146 ( V_47 . V_32 ) ;
F_107 ( & V_47 . V_118 ) ;
F_105 ( V_14 , & V_47 . V_10 ) ;
V_47 . V_57 = - 1 ;
V_116 = F_147 ( & V_166 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( ! F_33 ( & V_136 , V_41 ) )
F_137 () ;
V_73 = 1 ;
return 0 ;
}
static void F_148 ( struct V_1 * V_7 )
{
struct V_1 * V_163 ;
V_163 = F_5 ( V_7 ) ;
while ( F_42 ( V_163 -> V_30 ) ||
F_43 ( V_163 -> V_32 ) )
V_163 = F_5 ( V_163 ) ;
if ( F_149 ( V_163 -> V_3 . V_51 , V_7 -> V_3 . V_51 ) ) {
F_53 ( V_167 L_7 ) ;
F_150 ( V_7 -> V_3 . V_51 ) ;
F_151 ( L_8 ) ;
}
}
static void F_152 ( struct V_1 * V_7 )
{
static T_10 V_168 ;
static T_1 V_169 ;
bool V_170 ;
bool V_171 = F_118 ( V_7 -> V_3 . V_51 ) ;
V_172:
F_153 ( V_139 , V_7 -> V_52 == 0 ) ;
F_64 ( & V_82 ) ;
if ( V_7 -> V_52 ) {
F_65 ( & V_82 ) ;
goto V_172;
}
F_154 ( & V_168 , V_7 -> V_30 , V_47 . V_30 ) ;
F_155 ( V_169 , V_7 -> V_32 , V_47 . V_32 ) ;
F_64 ( & V_92 ) ;
F_154 ( V_7 -> V_30 , V_7 -> V_30 , & V_168 ) ;
F_65 ( & V_92 ) ;
if ( ( V_171 && F_42 ( V_7 -> V_30 ) ) ||
( ! F_42 ( & V_168 ) && ! F_42 ( V_7 -> V_30 ) ) )
F_68 ( V_7 ) ;
F_64 ( & V_92 ) ;
F_155 ( V_7 -> V_32 , V_7 -> V_32 , V_169 ) ;
F_65 ( & V_92 ) ;
if ( ( V_171 && F_43 ( V_7 -> V_32 ) ) ||
( ! F_43 ( V_169 ) && ! F_43 ( V_7 -> V_32 ) ) )
F_91 ( V_7 ) ;
V_170 = F_42 ( V_7 -> V_30 ) ||
F_43 ( V_7 -> V_32 ) ;
F_65 ( & V_82 ) ;
if ( ! V_171 && V_170 )
F_148 ( V_7 ) ;
}
static void F_156 ( struct V_173 * V_174 )
{
static T_10 V_175 ;
static T_1 V_176 ;
bool V_177 , V_178 ;
F_64 ( & V_82 ) ;
F_35 ( & V_175 , V_83 ) ;
V_176 = V_33 [ V_34 ] ;
V_177 = ! F_60 ( V_47 . V_30 , & V_175 ) ;
V_178 = ! F_99 ( V_47 . V_32 , V_176 ) ;
if ( V_177 ) {
F_64 ( & V_92 ) ;
F_35 ( V_47 . V_30 , & V_175 ) ;
F_65 ( & V_92 ) ;
}
if ( V_178 ) {
F_64 ( & V_92 ) ;
V_47 . V_32 = V_176 ;
F_65 ( & V_92 ) ;
F_91 ( & V_47 ) ;
}
F_65 ( & V_82 ) ;
if ( V_177 || V_178 ) {
struct V_1 * V_7 ;
struct V_2 * V_60 ;
F_39 () ;
F_48 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_47 || ! F_74 ( & V_7 -> V_3 ) )
continue;
F_44 () ;
F_152 ( V_7 ) ;
F_39 () ;
F_75 ( & V_7 -> V_3 ) ;
}
F_44 () ;
}
if ( V_177 )
F_63 () ;
}
void F_157 ( bool V_179 )
{
F_61 ( 1 , NULL , NULL ) ;
F_158 ( & V_154 ) ;
}
static int F_159 ( struct V_180 * V_181 ,
unsigned long V_182 , void * V_183 )
{
F_158 ( & V_154 ) ;
return V_184 ;
}
void T_9 F_160 ( void )
{
F_35 ( V_47 . V_30 , V_83 ) ;
V_47 . V_32 = V_33 [ V_34 ] ;
V_47 . V_109 = V_47 . V_32 ;
F_161 ( & V_185 ) ;
}
void F_162 ( struct V_4 * V_35 , struct V_28 * V_29 )
{
struct V_1 * V_84 ;
F_64 ( & V_92 ) ;
F_39 () ;
V_84 = F_66 ( F_3 ( V_35 ) ) ;
F_21 ( V_84 , V_29 ) ;
F_44 () ;
F_65 ( & V_92 ) ;
}
void F_163 ( struct V_4 * V_35 )
{
struct V_1 * V_84 ;
F_39 () ;
V_84 = F_66 ( F_3 ( V_35 ) ) ;
F_164 ( V_35 , V_84 -> V_30 ) ;
F_44 () ;
}
void F_165 ( void )
{
F_146 ( V_97 -> V_32 ) ;
}
T_1 F_166 ( struct V_4 * V_35 )
{
struct V_1 * V_98 ;
T_1 V_186 ;
F_64 ( & V_92 ) ;
F_39 () ;
V_98 = F_67 ( F_3 ( V_35 ) ) ;
F_24 ( V_98 , & V_186 ) ;
F_44 () ;
F_65 ( & V_92 ) ;
return V_186 ;
}
int F_167 ( T_1 * V_187 )
{
return F_25 ( * V_187 , V_97 -> V_32 ) ;
}
static struct V_1 * F_168 ( struct V_1 * V_7 )
{
while ( ! ( F_11 ( V_7 ) || F_12 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
int F_169 ( int V_188 , T_11 V_189 )
{
struct V_1 * V_7 ;
int V_190 ;
if ( F_170 () || ( V_189 & V_191 ) )
return 1 ;
F_171 ( ! ( V_189 & V_192 ) ) ;
if ( F_172 ( V_188 , V_97 -> V_32 ) )
return 1 ;
if ( F_81 ( F_82 ( V_102 ) ) )
return 1 ;
if ( V_189 & V_192 )
return 0 ;
if ( V_97 -> V_10 & V_103 )
return 1 ;
F_64 ( & V_92 ) ;
F_39 () ;
V_7 = F_168 ( F_3 ( V_97 ) ) ;
V_190 = F_172 ( V_188 , V_7 -> V_32 ) ;
F_44 () ;
F_65 ( & V_92 ) ;
return V_190 ;
}
int F_173 ( int V_188 , T_11 V_189 )
{
if ( F_170 () || ( V_189 & V_191 ) )
return 1 ;
if ( F_172 ( V_188 , V_97 -> V_32 ) )
return 1 ;
if ( F_81 ( F_82 ( V_102 ) ) )
return 1 ;
return 0 ;
}
static int F_174 ( int * V_193 )
{
int V_188 ;
V_188 = F_175 ( * V_193 , V_97 -> V_32 ) ;
if ( V_188 == V_194 )
V_188 = F_176 ( V_97 -> V_32 ) ;
* V_193 = V_188 ;
return V_188 ;
}
int F_177 ( void )
{
if ( V_97 -> V_195 == V_196 )
V_97 -> V_195 =
F_178 ( & V_97 -> V_32 ) ;
return F_174 ( & V_97 -> V_195 ) ;
}
int F_179 ( void )
{
if ( V_97 -> V_197 == V_196 )
V_97 -> V_197 =
F_178 ( & V_97 -> V_32 ) ;
return F_174 ( & V_97 -> V_197 ) ;
}
int F_180 ( const struct V_4 * V_198 ,
const struct V_4 * V_199 )
{
return F_25 ( V_198 -> V_32 , V_199 -> V_32 ) ;
}
void F_181 ( struct V_4 * V_35 )
{
static char V_200 [ V_201 ] ;
static F_182 ( V_202 ) ;
struct V_51 * V_203 ;
F_113 ( & V_202 ) ;
F_39 () ;
V_203 = F_3 ( V_35 ) -> V_3 . V_51 ;
F_134 ( V_200 , V_201 ,
V_35 -> V_32 ) ;
F_53 ( V_204 L_9 , V_35 -> V_205 ) ;
F_150 ( V_203 ) ;
F_151 ( L_10 , V_200 ) ;
F_44 () ;
F_114 ( & V_202 ) ;
}
void F_183 ( void )
{
F_39 () ;
F_112 ( & F_3 ( V_97 ) -> V_118 ) ;
F_44 () ;
}
int F_184 ( struct V_157 * V_206 , void * V_207 )
{
struct V_208 * V_208 ;
struct V_4 * V_35 ;
char * V_89 , * V_38 ;
struct V_2 * V_3 ;
int V_90 ;
V_90 = - V_117 ;
V_89 = F_52 ( V_209 , V_41 ) ;
if ( ! V_89 )
goto V_46;
V_90 = - V_210 ;
V_208 = V_206 -> V_142 ;
V_35 = F_185 ( V_208 , V_211 ) ;
if ( ! V_35 )
goto V_212;
V_90 = - V_213 ;
F_39 () ;
V_3 = F_4 ( V_35 , V_6 ) ;
V_38 = F_186 ( V_3 -> V_51 , V_89 , V_209 ) ;
F_44 () ;
if ( ! V_38 )
goto V_214;
F_187 ( V_206 , V_38 ) ;
F_188 ( V_206 , '\n' ) ;
V_90 = 0 ;
V_214:
F_189 ( V_35 ) ;
V_212:
F_34 ( V_89 ) ;
V_46:
return V_90 ;
}
void F_190 ( struct V_157 * V_206 , struct V_4 * V_5 )
{
F_191 ( V_206 , L_11 ) ;
F_192 ( V_206 , & V_5 -> V_32 ) ;
F_191 ( V_206 , L_8 ) ;
F_191 ( V_206 , L_12 ) ;
F_193 ( V_206 , & V_5 -> V_32 ) ;
F_191 ( V_206 , L_8 ) ;
}
