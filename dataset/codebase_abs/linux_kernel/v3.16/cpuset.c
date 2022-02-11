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
V_36 -> V_11 |= V_37 ;
else
V_36 -> V_11 &= ~ V_37 ;
if ( F_15 ( V_7 ) )
V_36 -> V_11 |= V_38 ;
else
V_36 -> V_11 &= ~ V_38 ;
}
static int F_27 ( const struct V_1 * V_39 , const struct V_1 * V_40 )
{
return F_28 ( V_39 -> V_31 , V_40 -> V_31 ) &&
F_29 ( V_39 -> V_33 , V_40 -> V_33 ) &&
F_9 ( V_39 ) <= F_9 ( V_40 ) &&
F_10 ( V_39 ) <= F_10 ( V_40 ) ;
}
static struct V_1 * F_30 ( struct V_1 * V_7 )
{
struct V_1 * V_41 ;
V_41 = F_31 ( V_7 , sizeof( * V_7 ) , V_42 ) ;
if ( ! V_41 )
return NULL ;
if ( ! F_32 ( & V_41 -> V_31 , V_42 ) ) {
F_33 ( V_41 ) ;
return NULL ;
}
F_34 ( V_41 -> V_31 , V_7 -> V_31 ) ;
return V_41 ;
}
static void F_35 ( struct V_1 * V_41 )
{
F_36 ( V_41 -> V_31 ) ;
F_33 ( V_41 ) ;
}
static int F_37 ( struct V_1 * V_43 , struct V_1 * V_41 )
{
struct V_2 * V_3 ;
struct V_1 * V_44 , * V_45 ;
int V_25 ;
F_38 () ;
V_25 = - V_46 ;
F_39 (c, css, cur)
if ( ! F_27 ( V_44 , V_41 ) )
goto V_47;
V_25 = 0 ;
if ( V_43 == & V_48 )
goto V_47;
V_45 = F_5 ( V_43 ) ;
V_25 = - V_49 ;
if ( ! F_27 ( V_41 , V_45 ) )
goto V_47;
V_25 = - V_50 ;
F_39 (c, css, par) {
if ( ( F_9 ( V_41 ) || F_9 ( V_44 ) ) &&
V_44 != V_43 &&
F_21 ( V_41 -> V_31 , V_44 -> V_31 ) )
goto V_47;
if ( ( F_10 ( V_41 ) || F_10 ( V_44 ) ) &&
V_44 != V_43 &&
F_24 ( V_41 -> V_33 , V_44 -> V_33 ) )
goto V_47;
}
V_25 = - V_51 ;
if ( ( F_40 ( V_43 -> V_3 . V_52 ) || V_43 -> V_53 ) ) {
if ( ! F_41 ( V_43 -> V_31 ) &&
F_41 ( V_41 -> V_31 ) )
goto V_47;
if ( ! F_42 ( V_43 -> V_33 ) &&
F_42 ( V_41 -> V_33 ) )
goto V_47;
}
V_25 = 0 ;
V_47:
F_43 () ;
return V_25 ;
}
static int F_44 ( struct V_1 * V_54 , struct V_1 * V_55 )
{
return F_21 ( V_54 -> V_31 , V_55 -> V_31 ) ;
}
static void
F_45 ( struct V_56 * V_57 , struct V_1 * V_44 )
{
if ( V_57 -> V_58 < V_44 -> V_58 )
V_57 -> V_58 = V_44 -> V_58 ;
return;
}
static void F_46 ( struct V_56 * V_57 ,
struct V_1 * V_59 )
{
struct V_1 * V_60 ;
struct V_2 * V_61 ;
F_38 () ;
F_47 (cp, pos_css, root_cs) {
if ( V_60 == V_59 )
continue;
if ( F_41 ( V_60 -> V_31 ) ) {
V_61 = F_48 ( V_61 ) ;
continue;
}
if ( F_12 ( V_60 ) )
F_45 ( V_57 , V_60 ) ;
}
F_43 () ;
}
static int F_49 ( T_2 * * V_62 ,
struct V_56 * * V_63 )
{
struct V_1 * V_60 ;
struct V_1 * * V_64 ;
int V_65 ;
int V_66 , V_67 , V_68 ;
T_2 * V_69 ;
struct V_56 * V_57 ;
int V_70 = 0 ;
int V_71 ;
struct V_2 * V_61 ;
V_69 = NULL ;
V_57 = NULL ;
V_64 = NULL ;
if ( F_12 ( & V_48 ) ) {
V_70 = 1 ;
V_69 = F_50 ( V_70 ) ;
if ( ! V_69 )
goto V_72;
V_57 = F_51 ( sizeof( struct V_56 ) , V_42 ) ;
if ( V_57 ) {
* V_57 = V_73 ;
F_46 ( V_57 , & V_48 ) ;
}
F_34 ( V_69 [ 0 ] , V_48 . V_31 ) ;
goto V_72;
}
V_64 = F_51 ( F_52 () * sizeof( V_60 ) , V_42 ) ;
if ( ! V_64 )
goto V_72;
V_65 = 0 ;
F_38 () ;
F_47 (cp, pos_css, &top_cpuset) {
if ( V_60 == & V_48 )
continue;
if ( ! F_41 ( V_60 -> V_31 ) &&
! F_12 ( V_60 ) )
continue;
if ( F_12 ( V_60 ) )
V_64 [ V_65 ++ ] = V_60 ;
V_61 = F_48 ( V_61 ) ;
}
F_43 () ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ )
V_64 [ V_66 ] -> V_74 = V_66 ;
V_70 = V_65 ;
V_75:
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
struct V_1 * V_54 = V_64 [ V_66 ] ;
int V_76 = V_54 -> V_74 ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ ) {
struct V_1 * V_55 = V_64 [ V_67 ] ;
int V_77 = V_55 -> V_74 ;
if ( V_76 != V_77 && F_44 ( V_54 , V_55 ) ) {
for ( V_68 = 0 ; V_68 < V_65 ; V_68 ++ ) {
struct V_1 * V_44 = V_64 [ V_68 ] ;
if ( V_44 -> V_74 == V_77 )
V_44 -> V_74 = V_76 ;
}
V_70 -- ;
goto V_75;
}
}
}
V_69 = F_50 ( V_70 ) ;
if ( ! V_69 )
goto V_72;
V_57 = F_51 ( V_70 * sizeof( struct V_56 ) , V_42 ) ;
for ( V_71 = 0 , V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
struct V_1 * V_54 = V_64 [ V_66 ] ;
struct V_29 * V_78 ;
int V_76 = V_54 -> V_74 ;
if ( V_76 < 0 ) {
continue;
}
V_78 = V_69 [ V_71 ] ;
if ( V_71 == V_70 ) {
static int V_79 = 10 ;
if ( V_79 ) {
F_53 ( L_4 ,
V_71 , V_70 , V_65 , V_66 , V_76 ) ;
V_79 -- ;
}
continue;
}
F_54 ( V_78 ) ;
if ( V_57 )
* ( V_57 + V_71 ) = V_73 ;
for ( V_67 = V_66 ; V_67 < V_65 ; V_67 ++ ) {
struct V_1 * V_55 = V_64 [ V_67 ] ;
if ( V_76 == V_55 -> V_74 ) {
F_55 ( V_78 , V_78 , V_55 -> V_31 ) ;
if ( V_57 )
F_46 ( V_57 + V_71 , V_55 ) ;
V_55 -> V_74 = - 1 ;
}
}
V_71 ++ ;
}
F_56 ( V_71 != V_70 ) ;
V_72:
F_33 ( V_64 ) ;
if ( V_69 == NULL )
V_70 = 1 ;
* V_62 = V_69 ;
* V_63 = V_57 ;
return V_70 ;
}
static void F_57 ( void )
{
struct V_56 * V_80 ;
T_2 * V_69 ;
int V_70 ;
F_58 ( & V_81 ) ;
F_59 () ;
if ( ! F_60 ( V_48 . V_31 , V_82 ) )
goto V_47;
V_70 = F_49 ( & V_69 , & V_80 ) ;
F_61 ( V_70 , V_69 , V_80 ) ;
V_47:
F_62 () ;
}
static void F_57 ( void )
{
}
void F_63 ( void )
{
F_64 ( & V_81 ) ;
F_57 () ;
F_65 ( & V_81 ) ;
}
static struct V_1 * F_66 ( struct V_1 * V_7 )
{
while ( F_41 ( V_7 -> V_31 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
static struct V_1 * F_67 ( struct V_1 * V_7 )
{
while ( F_42 ( V_7 -> V_33 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
static void F_68 ( struct V_1 * V_7 )
{
struct V_1 * V_83 = F_66 ( V_7 ) ;
struct V_84 V_85 ;
struct V_4 * V_5 ;
F_69 ( & V_7 -> V_3 , & V_85 ) ;
while ( ( V_5 = F_70 ( & V_85 ) ) )
F_71 ( V_5 , V_83 -> V_31 ) ;
F_72 ( & V_85 ) ;
}
static void F_73 ( struct V_1 * V_59 , bool V_86 )
{
struct V_1 * V_60 ;
struct V_2 * V_61 ;
F_38 () ;
F_47 (cp, pos_css, root_cs) {
if ( V_60 == V_59 ) {
if ( ! V_86 )
continue;
} else {
if ( ! F_41 ( V_60 -> V_31 ) ) {
V_61 = F_48 ( V_61 ) ;
continue;
}
}
if ( ! F_74 ( & V_60 -> V_3 ) )
continue;
F_43 () ;
F_68 ( V_60 ) ;
F_38 () ;
F_75 ( & V_60 -> V_3 ) ;
}
F_43 () ;
}
static int F_76 ( struct V_1 * V_7 , struct V_1 * V_87 ,
const char * V_88 )
{
int V_89 ;
int V_90 ;
if ( V_7 == & V_48 )
return - V_49 ;
if ( ! * V_88 ) {
F_54 ( V_87 -> V_31 ) ;
} else {
V_89 = F_77 ( V_88 , V_87 -> V_31 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( ! F_28 ( V_87 -> V_31 , V_82 ) )
return - V_50 ;
}
if ( F_60 ( V_7 -> V_31 , V_87 -> V_31 ) )
return 0 ;
V_89 = F_37 ( V_7 , V_87 ) ;
if ( V_89 < 0 )
return V_89 ;
V_90 = F_12 ( V_87 ) ;
F_64 ( & V_91 ) ;
F_34 ( V_7 -> V_31 , V_87 -> V_31 ) ;
F_65 ( & V_91 ) ;
F_73 ( V_7 , true ) ;
if ( V_90 )
F_57 () ;
return 0 ;
}
static void F_78 ( struct V_92 * V_93 , const T_1 * V_94 ,
const T_1 * V_95 )
{
struct V_4 * V_36 = V_96 ;
struct V_1 * V_97 ;
V_36 -> V_33 = * V_95 ;
F_79 ( V_93 , V_94 , V_95 , V_98 ) ;
F_38 () ;
V_97 = F_67 ( F_3 ( V_36 ) ) ;
F_23 ( V_97 , & V_36 -> V_33 ) ;
F_43 () ;
}
static void F_80 ( struct V_4 * V_36 ,
T_1 * V_99 )
{
bool V_100 ;
if ( F_81 ( F_82 ( V_101 ) ) )
return;
if ( V_96 -> V_11 & V_102 )
return;
F_83 ( V_36 ) ;
V_100 = F_6 ( V_36 ) ||
! F_24 ( * V_99 , V_36 -> V_33 ) ;
if ( V_100 ) {
F_84 () ;
F_85 ( & V_36 -> V_103 ) ;
}
F_86 ( V_36 -> V_33 , V_36 -> V_33 , * V_99 ) ;
F_87 ( V_36 , V_99 , V_104 ) ;
F_87 ( V_36 , V_99 , V_105 ) ;
V_36 -> V_33 = * V_99 ;
if ( V_100 ) {
F_88 ( & V_36 -> V_103 ) ;
F_89 () ;
}
F_90 ( V_36 ) ;
}
static void F_91 ( struct V_1 * V_7 )
{
static T_1 V_99 ;
struct V_1 * V_97 = F_67 ( V_7 ) ;
struct V_84 V_85 ;
struct V_4 * V_5 ;
V_106 = V_7 ;
F_23 ( V_97 , & V_99 ) ;
F_69 ( & V_7 -> V_3 , & V_85 ) ;
while ( ( V_5 = F_70 ( & V_85 ) ) ) {
struct V_92 * V_93 ;
bool V_107 ;
F_80 ( V_5 , & V_99 ) ;
V_93 = F_92 ( V_5 ) ;
if ( ! V_93 )
continue;
V_107 = F_13 ( V_7 ) ;
F_93 ( V_93 , & V_7 -> V_33 ) ;
if ( V_107 )
F_78 ( V_93 , & V_7 -> V_108 , & V_99 ) ;
F_94 ( V_93 ) ;
}
F_72 ( & V_85 ) ;
V_7 -> V_108 = V_99 ;
V_106 = NULL ;
}
static void F_95 ( struct V_1 * V_59 , bool V_86 )
{
struct V_1 * V_60 ;
struct V_2 * V_61 ;
F_38 () ;
F_47 (cp, pos_css, root_cs) {
if ( V_60 == V_59 ) {
if ( ! V_86 )
continue;
} else {
if ( ! F_42 ( V_60 -> V_33 ) ) {
V_61 = F_48 ( V_61 ) ;
continue;
}
}
if ( ! F_74 ( & V_60 -> V_3 ) )
continue;
F_43 () ;
F_91 ( V_60 ) ;
F_38 () ;
F_75 ( & V_60 -> V_3 ) ;
}
F_43 () ;
}
static int F_96 ( struct V_1 * V_7 , struct V_1 * V_87 ,
const char * V_88 )
{
int V_89 ;
if ( V_7 == & V_48 ) {
V_89 = - V_49 ;
goto V_72;
}
if ( ! * V_88 ) {
F_97 ( V_87 -> V_33 ) ;
} else {
V_89 = F_98 ( V_88 , V_87 -> V_33 ) ;
if ( V_89 < 0 )
goto V_72;
if ( ! F_29 ( V_87 -> V_33 ,
V_34 [ V_35 ] ) ) {
V_89 = - V_50 ;
goto V_72;
}
}
if ( F_99 ( V_7 -> V_33 , V_87 -> V_33 ) ) {
V_89 = 0 ;
goto V_72;
}
V_89 = F_37 ( V_7 , V_87 ) ;
if ( V_89 < 0 )
goto V_72;
F_64 ( & V_91 ) ;
V_7 -> V_33 = V_87 -> V_33 ;
F_65 ( & V_91 ) ;
F_95 ( V_7 , true ) ;
V_72:
return V_89 ;
}
int F_100 ( void )
{
int V_25 ;
F_38 () ;
V_25 = F_3 ( V_96 ) == V_106 ;
F_43 () ;
return V_25 ;
}
static int F_101 ( struct V_1 * V_7 , T_3 V_109 )
{
#ifdef F_102
if ( V_109 < - 1 || V_109 >= V_110 )
return - V_50 ;
#endif
if ( V_109 != V_7 -> V_58 ) {
V_7 -> V_58 = V_109 ;
if ( ! F_41 ( V_7 -> V_31 ) &&
F_12 ( V_7 ) )
F_57 () ;
}
return 0 ;
}
static void F_103 ( struct V_1 * V_7 )
{
struct V_84 V_85 ;
struct V_4 * V_5 ;
F_69 ( & V_7 -> V_3 , & V_85 ) ;
while ( ( V_5 = F_70 ( & V_85 ) ) )
F_26 ( V_7 , V_5 ) ;
F_72 ( & V_85 ) ;
}
static int F_104 ( T_4 V_111 , struct V_1 * V_7 ,
int V_112 )
{
struct V_1 * V_87 ;
int V_113 ;
int V_114 ;
int V_115 ;
V_87 = F_30 ( V_7 ) ;
if ( ! V_87 )
return - V_116 ;
if ( V_112 )
F_105 ( V_111 , & V_87 -> V_11 ) ;
else
F_106 ( V_111 , & V_87 -> V_11 ) ;
V_115 = F_37 ( V_7 , V_87 ) ;
if ( V_115 < 0 )
goto V_47;
V_113 = ( F_12 ( V_7 ) !=
F_12 ( V_87 ) ) ;
V_114 = ( ( F_15 ( V_7 ) != F_15 ( V_87 ) )
|| ( F_14 ( V_7 ) != F_14 ( V_87 ) ) ) ;
F_64 ( & V_91 ) ;
V_7 -> V_11 = V_87 -> V_11 ;
F_65 ( & V_91 ) ;
if ( ! F_41 ( V_87 -> V_31 ) && V_113 )
F_57 () ;
if ( V_114 )
F_103 ( V_7 ) ;
V_47:
F_35 ( V_87 ) ;
return V_115 ;
}
static void F_107 ( struct V_117 * V_118 )
{
V_118 -> V_119 = 0 ;
V_118 -> V_109 = 0 ;
V_118 -> time = 0 ;
F_108 ( & V_118 -> V_120 ) ;
}
static void F_109 ( struct V_117 * V_118 )
{
T_5 V_121 = F_110 () ;
T_5 V_122 = V_121 - V_118 -> time ;
if ( V_122 == 0 )
return;
V_122 = F_111 ( V_123 , V_122 ) ;
while ( V_122 -- > 0 )
V_118 -> V_109 = ( V_124 * V_118 -> V_109 ) / V_125 ;
V_118 -> time = V_121 ;
V_118 -> V_109 += ( ( V_125 - V_124 ) * V_118 -> V_119 ) / V_125 ;
V_118 -> V_119 = 0 ;
}
static void F_112 ( struct V_117 * V_118 )
{
F_113 ( & V_118 -> V_120 ) ;
F_109 ( V_118 ) ;
V_118 -> V_119 = F_111 ( V_126 , V_118 -> V_119 + V_125 ) ;
F_114 ( & V_118 -> V_120 ) ;
}
static int F_115 ( struct V_117 * V_118 )
{
int V_109 ;
F_113 ( & V_118 -> V_120 ) ;
F_109 ( V_118 ) ;
V_109 = V_118 -> V_109 ;
F_114 ( & V_118 -> V_120 ) ;
return V_109 ;
}
static int F_116 ( struct V_2 * V_3 ,
struct V_127 * V_128 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_4 * V_5 ;
int V_25 ;
V_129 = F_3 ( F_117 ( V_128 ) ) ;
F_64 ( & V_81 ) ;
V_25 = - V_51 ;
if ( ! F_118 ( V_3 -> V_52 ) &&
( F_41 ( V_7 -> V_31 ) || F_42 ( V_7 -> V_33 ) ) )
goto V_130;
F_119 (task, tset) {
V_25 = - V_50 ;
if ( V_5 -> V_11 & V_131 )
goto V_130;
V_25 = F_120 ( V_5 ) ;
if ( V_25 )
goto V_130;
}
V_7 -> V_53 ++ ;
V_25 = 0 ;
V_130:
F_65 ( & V_81 ) ;
return V_25 ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_127 * V_128 )
{
F_64 ( & V_81 ) ;
F_1 ( V_3 ) -> V_53 -- ;
F_65 ( & V_81 ) ;
}
static void F_122 ( struct V_2 * V_3 ,
struct V_127 * V_128 )
{
static T_1 V_132 ;
struct V_92 * V_93 ;
struct V_4 * V_5 ;
struct V_4 * V_133 = F_117 ( V_128 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_134 = V_129 ;
struct V_1 * V_83 = F_66 ( V_7 ) ;
struct V_1 * V_97 = F_67 ( V_7 ) ;
F_64 ( & V_81 ) ;
if ( V_7 == & V_48 )
F_34 ( V_135 , V_136 ) ;
else
F_20 ( V_83 , V_135 ) ;
F_23 ( V_97 , & V_132 ) ;
F_119 (task, tset) {
F_123 ( F_71 ( V_5 , V_135 ) ) ;
F_80 ( V_5 , & V_132 ) ;
F_26 ( V_7 , V_5 ) ;
}
V_132 = V_7 -> V_33 ;
V_93 = F_92 ( V_133 ) ;
if ( V_93 ) {
struct V_1 * V_137 = F_67 ( V_134 ) ;
F_93 ( V_93 , & V_132 ) ;
if ( F_13 ( V_7 ) ) {
F_78 ( V_93 , & V_137 -> V_108 ,
& V_132 ) ;
}
F_94 ( V_93 ) ;
}
V_7 -> V_108 = V_132 ;
V_7 -> V_53 -- ;
if ( ! V_7 -> V_53 )
F_124 ( & V_138 ) ;
F_65 ( & V_81 ) ;
}
static int F_125 ( struct V_2 * V_3 , struct V_139 * V_140 ,
T_6 V_109 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_140 -> V_141 ;
int V_89 = 0 ;
F_64 ( & V_81 ) ;
if ( ! F_7 ( V_7 ) ) {
V_89 = - V_26 ;
goto V_130;
}
switch ( type ) {
case V_142 :
V_89 = F_104 ( V_12 , V_7 , V_109 ) ;
break;
case V_143 :
V_89 = F_104 ( V_13 , V_7 , V_109 ) ;
break;
case V_144 :
V_89 = F_104 ( V_14 , V_7 , V_109 ) ;
break;
case V_145 :
V_89 = F_104 ( V_15 , V_7 , V_109 ) ;
break;
case V_146 :
V_89 = F_104 ( V_16 , V_7 , V_109 ) ;
break;
case V_147 :
V_148 = ! ! V_109 ;
break;
case V_149 :
V_89 = - V_49 ;
break;
case V_150 :
V_89 = F_104 ( V_17 , V_7 , V_109 ) ;
break;
case V_151 :
V_89 = F_104 ( V_18 , V_7 , V_109 ) ;
break;
default:
V_89 = - V_50 ;
break;
}
V_130:
F_65 ( & V_81 ) ;
return V_89 ;
}
static int F_126 ( struct V_2 * V_3 , struct V_139 * V_140 ,
T_3 V_109 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_140 -> V_141 ;
int V_89 = - V_26 ;
F_64 ( & V_81 ) ;
if ( ! F_7 ( V_7 ) )
goto V_130;
switch ( type ) {
case V_152 :
V_89 = F_101 ( V_7 , V_109 ) ;
break;
default:
V_89 = - V_50 ;
break;
}
V_130:
F_65 ( & V_81 ) ;
return V_89 ;
}
static T_8 F_127 ( struct V_153 * V_154 ,
char * V_88 , T_9 V_155 , T_10 V_156 )
{
struct V_1 * V_7 = F_1 ( F_128 ( V_154 ) ) ;
struct V_1 * V_87 ;
int V_89 = - V_26 ;
V_88 = F_129 ( V_88 ) ;
F_130 ( & V_7 -> V_3 ) ;
F_131 ( V_154 -> V_157 ) ;
F_132 ( & V_158 ) ;
F_64 ( & V_81 ) ;
if ( ! F_7 ( V_7 ) )
goto V_130;
V_87 = F_30 ( V_7 ) ;
if ( ! V_87 ) {
V_89 = - V_116 ;
goto V_130;
}
switch ( F_133 ( V_154 ) -> V_141 ) {
case V_159 :
V_89 = F_76 ( V_7 , V_87 , V_88 ) ;
break;
case V_160 :
V_89 = F_96 ( V_7 , V_87 , V_88 ) ;
break;
default:
V_89 = - V_50 ;
break;
}
F_35 ( V_87 ) ;
V_130:
F_65 ( & V_81 ) ;
F_134 ( V_154 -> V_157 ) ;
F_75 ( & V_7 -> V_3 ) ;
return V_89 ? : V_155 ;
}
static int F_135 ( struct V_161 * V_162 , void * V_163 )
{
struct V_1 * V_7 = F_1 ( F_136 ( V_162 ) ) ;
T_7 type = F_137 ( V_162 ) -> V_141 ;
T_8 V_164 ;
char * V_88 , * V_165 ;
int V_25 = 0 ;
V_164 = F_138 ( V_162 , & V_88 ) ;
V_165 = V_88 ;
F_64 ( & V_91 ) ;
switch ( type ) {
case V_159 :
V_165 += F_139 ( V_165 , V_164 , V_7 -> V_31 ) ;
break;
case V_160 :
V_165 += F_140 ( V_165 , V_164 , V_7 -> V_33 ) ;
break;
default:
V_25 = - V_50 ;
goto V_130;
}
if ( V_165 < V_88 + V_164 - 1 ) {
* V_165 ++ = '\n' ;
F_141 ( V_162 , V_165 - V_88 ) ;
} else {
F_141 ( V_162 , - 1 ) ;
}
V_130:
F_65 ( & V_91 ) ;
return V_25 ;
}
static T_6 F_142 ( struct V_2 * V_3 , struct V_139 * V_140 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_140 -> V_141 ;
switch ( type ) {
case V_142 :
return F_9 ( V_7 ) ;
case V_143 :
return F_10 ( V_7 ) ;
case V_144 :
return F_11 ( V_7 ) ;
case V_145 :
return F_12 ( V_7 ) ;
case V_146 :
return F_13 ( V_7 ) ;
case V_147 :
return V_148 ;
case V_149 :
return F_115 ( & V_7 -> V_117 ) ;
case V_150 :
return F_14 ( V_7 ) ;
case V_151 :
return F_15 ( V_7 ) ;
default:
F_143 () ;
}
return 0 ;
}
static T_3 F_144 ( struct V_2 * V_3 , struct V_139 * V_140 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_140 -> V_141 ;
switch ( type ) {
case V_152 :
return V_7 -> V_58 ;
default:
F_143 () ;
}
return 0 ;
}
static struct V_2 *
F_145 ( struct V_2 * V_166 )
{
struct V_1 * V_7 ;
if ( ! V_166 )
return & V_48 . V_3 ;
V_7 = F_146 ( sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 )
return F_18 ( - V_116 ) ;
if ( ! F_32 ( & V_7 -> V_31 , V_42 ) ) {
F_33 ( V_7 ) ;
return F_18 ( - V_116 ) ;
}
F_105 ( V_15 , & V_7 -> V_11 ) ;
F_54 ( V_7 -> V_31 ) ;
F_97 ( V_7 -> V_33 ) ;
F_107 ( & V_7 -> V_117 ) ;
V_7 -> V_58 = - 1 ;
return & V_7 -> V_3 ;
}
static int F_147 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_8 = F_5 ( V_7 ) ;
struct V_1 * V_167 ;
struct V_2 * V_61 ;
if ( ! V_8 )
return 0 ;
F_64 ( & V_81 ) ;
F_105 ( V_10 , & V_7 -> V_11 ) ;
if ( F_14 ( V_8 ) )
F_105 ( V_17 , & V_7 -> V_11 ) ;
if ( F_15 ( V_8 ) )
F_105 ( V_18 , & V_7 -> V_11 ) ;
F_148 () ;
if ( ! F_8 ( V_168 , & V_3 -> V_52 -> V_11 ) )
goto V_130;
F_38 () ;
F_39 (tmp_cs, pos_css, parent) {
if ( F_10 ( V_167 ) || F_9 ( V_167 ) ) {
F_43 () ;
goto V_130;
}
}
F_43 () ;
F_64 ( & V_91 ) ;
V_7 -> V_33 = V_8 -> V_33 ;
F_34 ( V_7 -> V_31 , V_8 -> V_31 ) ;
F_65 ( & V_91 ) ;
V_130:
F_65 ( & V_81 ) ;
return 0 ;
}
static void F_149 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_64 ( & V_81 ) ;
if ( F_12 ( V_7 ) )
F_104 ( V_15 , V_7 , 0 ) ;
F_150 () ;
F_106 ( V_10 , & V_7 -> V_11 ) ;
F_65 ( & V_81 ) ;
}
static void F_151 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_36 ( V_7 -> V_31 ) ;
F_33 ( V_7 ) ;
}
int T_11 F_152 ( void )
{
int V_115 = 0 ;
if ( ! F_32 ( & V_48 . V_31 , V_42 ) )
F_143 () ;
F_153 ( V_48 . V_31 ) ;
F_154 ( V_48 . V_33 ) ;
F_107 ( & V_48 . V_117 ) ;
F_105 ( V_15 , & V_48 . V_11 ) ;
V_48 . V_58 = - 1 ;
V_115 = F_155 ( & V_169 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( ! F_32 ( & V_135 , V_42 ) )
F_143 () ;
return 0 ;
}
static void F_156 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_5 ( V_7 ) ;
while ( F_41 ( V_8 -> V_31 ) ||
F_42 ( V_8 -> V_33 ) )
V_8 = F_5 ( V_8 ) ;
if ( F_157 ( V_8 -> V_3 . V_52 , V_7 -> V_3 . V_52 ) ) {
F_158 ( L_5 ) ;
F_159 ( V_7 -> V_3 . V_52 ) ;
F_160 ( L_6 ) ;
}
}
static void F_161 ( struct V_1 * V_7 )
{
static T_12 V_170 ;
static T_1 V_171 ;
bool V_172 ;
bool V_173 = F_118 ( V_7 -> V_3 . V_52 ) ;
V_174:
F_162 ( V_138 , V_7 -> V_53 == 0 ) ;
F_64 ( & V_81 ) ;
if ( V_7 -> V_53 ) {
F_65 ( & V_81 ) ;
goto V_174;
}
F_163 ( & V_170 , V_7 -> V_31 , V_48 . V_31 ) ;
F_164 ( V_171 , V_7 -> V_33 , V_48 . V_33 ) ;
F_64 ( & V_91 ) ;
F_163 ( V_7 -> V_31 , V_7 -> V_31 , & V_170 ) ;
F_65 ( & V_91 ) ;
if ( ( V_173 && F_41 ( V_7 -> V_31 ) ) ||
( ! F_41 ( & V_170 ) && ! F_41 ( V_7 -> V_31 ) ) )
F_68 ( V_7 ) ;
F_64 ( & V_91 ) ;
F_164 ( V_7 -> V_33 , V_7 -> V_33 , V_171 ) ;
F_65 ( & V_91 ) ;
if ( ( V_173 && F_42 ( V_7 -> V_33 ) ) ||
( ! F_42 ( V_171 ) && ! F_42 ( V_7 -> V_33 ) ) )
F_91 ( V_7 ) ;
V_172 = F_41 ( V_7 -> V_31 ) ||
F_42 ( V_7 -> V_33 ) ;
F_65 ( & V_81 ) ;
if ( ! V_173 && V_172 )
F_156 ( V_7 ) ;
}
static void F_165 ( struct V_175 * V_176 )
{
static T_12 V_177 ;
static T_1 V_178 ;
bool V_179 , V_180 ;
F_64 ( & V_81 ) ;
F_34 ( & V_177 , V_82 ) ;
V_178 = V_34 [ V_35 ] ;
V_179 = ! F_60 ( V_48 . V_31 , & V_177 ) ;
V_180 = ! F_99 ( V_48 . V_33 , V_178 ) ;
if ( V_179 ) {
F_64 ( & V_91 ) ;
F_34 ( V_48 . V_31 , & V_177 ) ;
F_65 ( & V_91 ) ;
}
if ( V_180 ) {
F_64 ( & V_91 ) ;
V_48 . V_33 = V_178 ;
F_65 ( & V_91 ) ;
F_91 ( & V_48 ) ;
}
F_65 ( & V_81 ) ;
if ( V_179 || V_180 ) {
struct V_1 * V_7 ;
struct V_2 * V_61 ;
F_38 () ;
F_47 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_48 || ! F_74 ( & V_7 -> V_3 ) )
continue;
F_43 () ;
F_161 ( V_7 ) ;
F_38 () ;
F_75 ( & V_7 -> V_3 ) ;
}
F_43 () ;
}
if ( V_179 )
F_63 () ;
}
void F_166 ( bool V_181 )
{
F_61 ( 1 , NULL , NULL ) ;
F_167 ( & V_158 ) ;
}
static int F_168 ( struct V_182 * V_183 ,
unsigned long V_184 , void * V_185 )
{
F_167 ( & V_158 ) ;
return V_186 ;
}
void T_11 F_169 ( void )
{
F_34 ( V_48 . V_31 , V_82 ) ;
V_48 . V_33 = V_34 [ V_35 ] ;
V_48 . V_108 = V_48 . V_33 ;
F_170 ( & V_187 ) ;
}
void F_171 ( struct V_4 * V_36 , struct V_29 * V_30 )
{
struct V_1 * V_83 ;
F_64 ( & V_91 ) ;
F_38 () ;
V_83 = F_66 ( F_3 ( V_36 ) ) ;
F_20 ( V_83 , V_30 ) ;
F_43 () ;
F_65 ( & V_91 ) ;
}
void F_172 ( struct V_4 * V_36 )
{
struct V_1 * V_83 ;
F_38 () ;
V_83 = F_66 ( F_3 ( V_36 ) ) ;
F_173 ( V_36 , V_83 -> V_31 ) ;
F_43 () ;
}
void F_174 ( void )
{
F_154 ( V_96 -> V_33 ) ;
}
T_1 F_175 ( struct V_4 * V_36 )
{
struct V_1 * V_97 ;
T_1 V_188 ;
F_64 ( & V_91 ) ;
F_38 () ;
V_97 = F_67 ( F_3 ( V_36 ) ) ;
F_23 ( V_97 , & V_188 ) ;
F_43 () ;
F_65 ( & V_91 ) ;
return V_188 ;
}
int F_176 ( T_1 * V_189 )
{
return F_24 ( * V_189 , V_96 -> V_33 ) ;
}
static struct V_1 * F_177 ( struct V_1 * V_7 )
{
while ( ! ( F_10 ( V_7 ) || F_11 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
int F_178 ( int V_190 , T_13 V_191 )
{
struct V_1 * V_7 ;
int V_192 ;
if ( F_179 () || ( V_191 & V_193 ) )
return 1 ;
F_180 ( ! ( V_191 & V_194 ) ) ;
if ( F_181 ( V_190 , V_96 -> V_33 ) )
return 1 ;
if ( F_81 ( F_82 ( V_101 ) ) )
return 1 ;
if ( V_191 & V_194 )
return 0 ;
if ( V_96 -> V_11 & V_102 )
return 1 ;
F_64 ( & V_91 ) ;
F_38 () ;
V_7 = F_177 ( F_3 ( V_96 ) ) ;
V_192 = F_181 ( V_190 , V_7 -> V_33 ) ;
F_43 () ;
F_65 ( & V_91 ) ;
return V_192 ;
}
int F_182 ( int V_190 , T_13 V_191 )
{
if ( F_179 () || ( V_191 & V_193 ) )
return 1 ;
if ( F_181 ( V_190 , V_96 -> V_33 ) )
return 1 ;
if ( F_81 ( F_82 ( V_101 ) ) )
return 1 ;
return 0 ;
}
static int F_183 ( int * V_195 )
{
int V_190 ;
V_190 = F_184 ( * V_195 , V_96 -> V_33 ) ;
if ( V_190 == V_196 )
V_190 = F_185 ( V_96 -> V_33 ) ;
* V_195 = V_190 ;
return V_190 ;
}
int F_186 ( void )
{
if ( V_96 -> V_197 == V_198 )
V_96 -> V_197 =
F_187 ( & V_96 -> V_33 ) ;
return F_183 ( & V_96 -> V_197 ) ;
}
int F_188 ( void )
{
if ( V_96 -> V_199 == V_198 )
V_96 -> V_199 =
F_187 ( & V_96 -> V_33 ) ;
return F_183 ( & V_96 -> V_199 ) ;
}
int F_189 ( const struct V_4 * V_200 ,
const struct V_4 * V_201 )
{
return F_24 ( V_200 -> V_33 , V_201 -> V_33 ) ;
}
void F_190 ( struct V_4 * V_36 )
{
static char V_202 [ V_203 ] ;
static F_191 ( V_204 ) ;
struct V_52 * V_205 ;
F_113 ( & V_204 ) ;
F_38 () ;
V_205 = F_3 ( V_36 ) -> V_3 . V_52 ;
F_140 ( V_202 , V_203 ,
V_36 -> V_33 ) ;
F_192 ( L_7 , V_36 -> V_206 ) ;
F_159 ( V_205 ) ;
F_160 ( L_8 , V_202 ) ;
F_43 () ;
F_114 ( & V_204 ) ;
}
void F_193 ( void )
{
F_38 () ;
F_112 ( & F_3 ( V_96 ) -> V_117 ) ;
F_43 () ;
}
int F_194 ( struct V_161 * V_207 , void * V_208 )
{
struct V_209 * V_209 ;
struct V_4 * V_36 ;
char * V_88 , * V_39 ;
struct V_2 * V_3 ;
int V_89 ;
V_89 = - V_116 ;
V_88 = F_51 ( V_210 , V_42 ) ;
if ( ! V_88 )
goto V_47;
V_89 = - V_211 ;
V_209 = V_207 -> V_141 ;
V_36 = F_195 ( V_209 , V_212 ) ;
if ( ! V_36 )
goto V_213;
V_89 = - V_214 ;
F_38 () ;
V_3 = F_4 ( V_36 , V_6 ) ;
V_39 = F_196 ( V_3 -> V_52 , V_88 , V_210 ) ;
F_43 () ;
if ( ! V_39 )
goto V_215;
F_197 ( V_207 , V_39 ) ;
F_198 ( V_207 , '\n' ) ;
V_89 = 0 ;
V_215:
F_199 ( V_36 ) ;
V_213:
F_33 ( V_88 ) ;
V_47:
return V_89 ;
}
void F_200 ( struct V_161 * V_207 , struct V_4 * V_5 )
{
F_197 ( V_207 , L_9 ) ;
F_201 ( V_207 , & V_5 -> V_33 ) ;
F_197 ( V_207 , L_6 ) ;
F_197 ( V_207 , L_10 ) ;
F_202 ( V_207 , & V_5 -> V_33 ) ;
F_197 ( V_207 , L_6 ) ;
}
