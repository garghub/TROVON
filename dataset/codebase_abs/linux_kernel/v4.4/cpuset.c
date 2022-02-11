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
static void F_86 ( struct V_97 * V_98 , const T_1 * V_99 ,
const T_1 * V_100 )
{
struct V_4 * V_36 = V_101 ;
V_36 -> V_40 = * V_100 ;
F_87 ( V_98 , V_99 , V_100 , V_102 ) ;
F_42 () ;
F_23 ( F_3 ( V_36 ) , & V_36 -> V_40 ) ;
F_49 () ;
}
static void F_88 ( struct V_4 * V_36 ,
T_1 * V_103 )
{
bool V_104 ;
if ( F_89 ( F_90 ( V_105 ) ) )
return;
if ( V_101 -> V_11 & V_106 )
return;
F_91 ( V_36 ) ;
V_104 = F_6 ( V_36 ) ||
! F_24 ( * V_103 , V_36 -> V_40 ) ;
if ( V_104 ) {
F_92 () ;
F_93 ( & V_36 -> V_107 ) ;
}
F_94 ( V_36 -> V_40 , V_36 -> V_40 , * V_103 ) ;
F_95 ( V_36 , V_103 , V_108 ) ;
F_95 ( V_36 , V_103 , V_109 ) ;
V_36 -> V_40 = * V_103 ;
if ( V_104 ) {
F_96 ( & V_36 -> V_107 ) ;
F_97 () ;
}
F_98 ( V_36 ) ;
}
static void F_99 ( struct V_1 * V_7 )
{
static T_1 V_103 ;
struct V_89 V_90 ;
struct V_4 * V_5 ;
V_110 = V_7 ;
F_23 ( V_7 , & V_103 ) ;
F_74 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_75 ( & V_90 ) ) ) {
struct V_97 * V_98 ;
bool V_111 ;
F_88 ( V_5 , & V_103 ) ;
V_98 = F_100 ( V_5 ) ;
if ( ! V_98 )
continue;
V_111 = F_13 ( V_7 ) ;
F_101 ( V_98 , & V_7 -> V_40 ) ;
if ( V_111 )
F_86 ( V_98 , & V_7 -> V_112 , & V_103 ) ;
F_102 ( V_98 ) ;
}
F_77 ( & V_90 ) ;
V_7 -> V_112 = V_103 ;
V_110 = NULL ;
}
static void F_103 ( struct V_1 * V_7 , T_1 * V_113 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
F_42 () ;
F_53 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_63 ) ;
F_25 ( * V_113 , V_63 -> V_40 , V_8 -> V_33 ) ;
if ( F_44 ( V_52 ) &&
F_47 ( * V_113 ) )
* V_113 = V_8 -> V_33 ;
if ( F_104 ( * V_113 , V_63 -> V_33 ) ) {
V_64 = F_54 ( V_64 ) ;
continue;
}
if ( ! F_79 ( & V_63 -> V_3 ) )
continue;
F_49 () ;
F_80 ( & V_93 ) ;
V_63 -> V_33 = * V_113 ;
F_81 ( & V_93 ) ;
F_82 ( ! F_44 ( V_52 ) &&
! F_104 ( V_63 -> V_40 , V_63 -> V_33 ) ) ;
F_99 ( V_63 ) ;
F_42 () ;
F_83 ( & V_63 -> V_3 ) ;
}
F_49 () ;
}
static int F_105 ( struct V_1 * V_7 , struct V_1 * V_94 ,
const char * V_95 )
{
int V_96 ;
if ( V_7 == & V_50 ) {
V_96 = - V_51 ;
goto V_76;
}
if ( ! * V_95 ) {
F_106 ( V_94 -> V_40 ) ;
} else {
V_96 = F_107 ( V_95 , V_94 -> V_40 ) ;
if ( V_96 < 0 )
goto V_76;
if ( ! F_33 ( V_94 -> V_40 ,
V_50 . V_40 ) ) {
V_96 = - V_53 ;
goto V_76;
}
}
if ( F_104 ( V_7 -> V_40 , V_94 -> V_40 ) ) {
V_96 = 0 ;
goto V_76;
}
V_96 = F_41 ( V_7 , V_94 ) ;
if ( V_96 < 0 )
goto V_76;
F_80 ( & V_93 ) ;
V_7 -> V_40 = V_94 -> V_40 ;
F_81 ( & V_93 ) ;
F_103 ( V_7 , & V_94 -> V_40 ) ;
V_76:
return V_96 ;
}
int F_108 ( void )
{
int V_25 ;
F_42 () ;
V_25 = F_3 ( V_101 ) == V_110 ;
F_49 () ;
return V_25 ;
}
static int F_109 ( struct V_1 * V_7 , T_3 V_114 )
{
#ifdef F_110
if ( V_114 < - 1 || V_114 >= V_115 )
return - V_53 ;
#endif
if ( V_114 != V_7 -> V_61 ) {
V_7 -> V_61 = V_114 ;
if ( ! F_46 ( V_7 -> V_39 ) &&
F_12 ( V_7 ) )
F_64 () ;
}
return 0 ;
}
static void F_111 ( struct V_1 * V_7 )
{
struct V_89 V_90 ;
struct V_4 * V_5 ;
F_74 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_75 ( & V_90 ) ) )
F_26 ( V_7 , V_5 ) ;
F_77 ( & V_90 ) ;
}
static int F_112 ( T_4 V_116 , struct V_1 * V_7 ,
int V_117 )
{
struct V_1 * V_94 ;
int V_118 ;
int V_119 ;
int V_120 ;
V_94 = F_34 ( V_7 ) ;
if ( ! V_94 )
return - V_121 ;
if ( V_117 )
F_113 ( V_116 , & V_94 -> V_11 ) ;
else
F_114 ( V_116 , & V_94 -> V_11 ) ;
V_120 = F_41 ( V_7 , V_94 ) ;
if ( V_120 < 0 )
goto V_49;
V_118 = ( F_12 ( V_7 ) !=
F_12 ( V_94 ) ) ;
V_119 = ( ( F_15 ( V_7 ) != F_15 ( V_94 ) )
|| ( F_14 ( V_7 ) != F_14 ( V_94 ) ) ) ;
F_80 ( & V_93 ) ;
V_7 -> V_11 = V_94 -> V_11 ;
F_81 ( & V_93 ) ;
if ( ! F_46 ( V_94 -> V_39 ) && V_118 )
F_64 () ;
if ( V_119 )
F_111 ( V_7 ) ;
V_49:
F_40 ( V_94 ) ;
return V_120 ;
}
static void F_115 ( struct V_122 * V_123 )
{
V_123 -> V_124 = 0 ;
V_123 -> V_114 = 0 ;
V_123 -> time = 0 ;
F_116 ( & V_123 -> V_125 ) ;
}
static void F_117 ( struct V_122 * V_123 )
{
T_5 V_126 = F_118 () ;
T_5 V_127 = V_126 - V_123 -> time ;
if ( V_127 == 0 )
return;
V_127 = F_119 ( V_128 , V_127 ) ;
while ( V_127 -- > 0 )
V_123 -> V_114 = ( V_129 * V_123 -> V_114 ) / V_130 ;
V_123 -> time = V_126 ;
V_123 -> V_114 += ( ( V_130 - V_129 ) * V_123 -> V_124 ) / V_130 ;
V_123 -> V_124 = 0 ;
}
static void F_120 ( struct V_122 * V_123 )
{
F_121 ( & V_123 -> V_125 ) ;
F_117 ( V_123 ) ;
V_123 -> V_124 = F_119 ( V_131 , V_123 -> V_124 + V_130 ) ;
F_122 ( & V_123 -> V_125 ) ;
}
static int F_123 ( struct V_122 * V_123 )
{
int V_114 ;
F_121 ( & V_123 -> V_125 ) ;
F_117 ( V_123 ) ;
V_114 = V_123 -> V_114 ;
F_122 ( & V_123 -> V_125 ) ;
return V_114 ;
}
static int F_124 ( struct V_132 * V_133 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
int V_25 ;
V_134 = F_3 ( F_125 ( V_133 , & V_3 ) ) ;
V_7 = F_1 ( V_3 ) ;
F_71 ( & V_87 ) ;
V_25 = - V_54 ;
if ( ! F_44 ( V_52 ) &&
( F_46 ( V_7 -> V_39 ) || F_47 ( V_7 -> V_40 ) ) )
goto V_135;
F_126 (task, css, tset) {
V_25 = F_127 ( V_5 , V_7 -> V_39 ) ;
if ( V_25 )
goto V_135;
V_25 = F_128 ( V_5 ) ;
if ( V_25 )
goto V_135;
}
V_7 -> V_56 ++ ;
V_25 = 0 ;
V_135:
F_72 ( & V_87 ) ;
return V_25 ;
}
static void F_129 ( struct V_132 * V_133 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
F_125 ( V_133 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_71 ( & V_87 ) ;
F_1 ( V_3 ) -> V_56 -- ;
F_72 ( & V_87 ) ;
}
static void F_130 ( struct V_132 * V_133 )
{
static T_1 V_136 ;
struct V_4 * V_5 ;
struct V_4 * V_137 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_1 * V_138 = V_134 ;
F_125 ( V_133 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_71 ( & V_87 ) ;
if ( V_7 == & V_50 )
F_37 ( V_139 , V_77 ) ;
else
F_20 ( V_7 , V_139 ) ;
F_23 ( V_7 , & V_136 ) ;
F_126 (task, css, tset) {
F_131 ( F_76 ( V_5 , V_139 ) ) ;
F_88 ( V_5 , & V_136 ) ;
F_26 ( V_7 , V_5 ) ;
}
V_136 = V_7 -> V_33 ;
F_132 (leader, css, tset) {
struct V_97 * V_98 = F_100 ( V_137 ) ;
if ( V_98 ) {
F_101 ( V_98 , & V_136 ) ;
if ( F_13 ( V_7 ) ) {
F_86 ( V_98 , & V_138 -> V_112 ,
& V_136 ) ;
}
F_102 ( V_98 ) ;
}
}
V_7 -> V_112 = V_136 ;
V_7 -> V_56 -- ;
if ( ! V_7 -> V_56 )
F_133 ( & V_140 ) ;
F_72 ( & V_87 ) ;
}
static int F_134 ( struct V_2 * V_3 , struct V_141 * V_142 ,
T_6 V_114 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_142 -> V_143 ;
int V_96 = 0 ;
F_71 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) ) {
V_96 = - V_26 ;
goto V_135;
}
switch ( type ) {
case V_144 :
V_96 = F_112 ( V_12 , V_7 , V_114 ) ;
break;
case V_145 :
V_96 = F_112 ( V_13 , V_7 , V_114 ) ;
break;
case V_146 :
V_96 = F_112 ( V_14 , V_7 , V_114 ) ;
break;
case V_147 :
V_96 = F_112 ( V_15 , V_7 , V_114 ) ;
break;
case V_148 :
V_96 = F_112 ( V_16 , V_7 , V_114 ) ;
break;
case V_149 :
V_150 = ! ! V_114 ;
break;
case V_151 :
V_96 = F_112 ( V_17 , V_7 , V_114 ) ;
break;
case V_152 :
V_96 = F_112 ( V_18 , V_7 , V_114 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
V_135:
F_72 ( & V_87 ) ;
return V_96 ;
}
static int F_135 ( struct V_2 * V_3 , struct V_141 * V_142 ,
T_3 V_114 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_142 -> V_143 ;
int V_96 = - V_26 ;
F_71 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) )
goto V_135;
switch ( type ) {
case V_153 :
V_96 = F_109 ( V_7 , V_114 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
V_135:
F_72 ( & V_87 ) ;
return V_96 ;
}
static T_8 F_136 ( struct V_154 * V_155 ,
char * V_95 , T_9 V_156 , T_10 V_157 )
{
struct V_1 * V_7 = F_1 ( F_137 ( V_155 ) ) ;
struct V_1 * V_94 ;
int V_96 = - V_26 ;
V_95 = F_138 ( V_95 ) ;
F_139 ( & V_7 -> V_3 ) ;
F_140 ( V_155 -> V_158 ) ;
F_141 ( & V_159 ) ;
F_71 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) )
goto V_135;
V_94 = F_34 ( V_7 ) ;
if ( ! V_94 ) {
V_96 = - V_121 ;
goto V_135;
}
switch ( F_142 ( V_155 ) -> V_143 ) {
case V_160 :
V_96 = F_84 ( V_7 , V_94 , V_95 ) ;
break;
case V_161 :
V_96 = F_105 ( V_7 , V_94 , V_95 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
F_40 ( V_94 ) ;
V_135:
F_72 ( & V_87 ) ;
F_143 ( V_155 -> V_158 ) ;
F_83 ( & V_7 -> V_3 ) ;
return V_96 ? : V_156 ;
}
static int F_144 ( struct V_162 * V_163 , void * V_164 )
{
struct V_1 * V_7 = F_1 ( F_145 ( V_163 ) ) ;
T_7 type = F_146 ( V_163 ) -> V_143 ;
int V_25 = 0 ;
F_80 ( & V_93 ) ;
switch ( type ) {
case V_160 :
F_147 ( V_163 , L_5 , F_148 ( V_7 -> V_39 ) ) ;
break;
case V_161 :
F_147 ( V_163 , L_5 , F_149 ( & V_7 -> V_40 ) ) ;
break;
case V_165 :
F_147 ( V_163 , L_5 , F_148 ( V_7 -> V_31 ) ) ;
break;
case V_166 :
F_147 ( V_163 , L_5 , F_149 ( & V_7 -> V_33 ) ) ;
break;
default:
V_25 = - V_53 ;
}
F_81 ( & V_93 ) ;
return V_25 ;
}
static T_6 F_150 ( struct V_2 * V_3 , struct V_141 * V_142 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_142 -> V_143 ;
switch ( type ) {
case V_144 :
return F_9 ( V_7 ) ;
case V_145 :
return F_10 ( V_7 ) ;
case V_146 :
return F_11 ( V_7 ) ;
case V_147 :
return F_12 ( V_7 ) ;
case V_148 :
return F_13 ( V_7 ) ;
case V_149 :
return V_150 ;
case V_167 :
return F_123 ( & V_7 -> V_122 ) ;
case V_151 :
return F_14 ( V_7 ) ;
case V_152 :
return F_15 ( V_7 ) ;
default:
F_151 () ;
}
return 0 ;
}
static T_3 F_152 ( struct V_2 * V_3 , struct V_141 * V_142 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_142 -> V_143 ;
switch ( type ) {
case V_153 :
return V_7 -> V_61 ;
default:
F_151 () ;
}
return 0 ;
}
static struct V_2 *
F_153 ( struct V_2 * V_168 )
{
struct V_1 * V_7 ;
if ( ! V_168 )
return & V_50 . V_3 ;
V_7 = F_154 ( sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 )
return F_18 ( - V_121 ) ;
if ( ! F_36 ( & V_7 -> V_39 , V_42 ) )
goto V_43;
if ( ! F_36 ( & V_7 -> V_31 , V_42 ) )
goto V_44;
F_113 ( V_15 , & V_7 -> V_11 ) ;
F_61 ( V_7 -> V_39 ) ;
F_106 ( V_7 -> V_40 ) ;
F_61 ( V_7 -> V_31 ) ;
F_106 ( V_7 -> V_33 ) ;
F_115 ( & V_7 -> V_122 ) ;
V_7 -> V_61 = - 1 ;
return & V_7 -> V_3 ;
V_44:
F_38 ( V_7 -> V_39 ) ;
V_43:
F_39 ( V_7 ) ;
return F_18 ( - V_121 ) ;
}
static int F_155 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_8 = F_5 ( V_7 ) ;
struct V_1 * V_169 ;
struct V_2 * V_64 ;
if ( ! V_8 )
return 0 ;
F_71 ( & V_87 ) ;
F_113 ( V_10 , & V_7 -> V_11 ) ;
if ( F_14 ( V_8 ) )
F_113 ( V_17 , & V_7 -> V_11 ) ;
if ( F_15 ( V_8 ) )
F_113 ( V_18 , & V_7 -> V_11 ) ;
F_156 () ;
F_80 ( & V_93 ) ;
if ( F_44 ( V_52 ) ) {
F_37 ( V_7 -> V_31 , V_8 -> V_31 ) ;
V_7 -> V_33 = V_8 -> V_33 ;
}
F_81 ( & V_93 ) ;
if ( ! F_8 ( V_170 , & V_3 -> V_55 -> V_11 ) )
goto V_135;
F_42 () ;
F_43 (tmp_cs, pos_css, parent) {
if ( F_10 ( V_169 ) || F_9 ( V_169 ) ) {
F_49 () ;
goto V_135;
}
}
F_49 () ;
F_80 ( & V_93 ) ;
V_7 -> V_40 = V_8 -> V_40 ;
V_7 -> V_33 = V_8 -> V_40 ;
F_37 ( V_7 -> V_39 , V_8 -> V_39 ) ;
F_37 ( V_7 -> V_31 , V_8 -> V_39 ) ;
F_81 ( & V_93 ) ;
V_135:
F_72 ( & V_87 ) ;
return 0 ;
}
static void F_157 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_71 ( & V_87 ) ;
if ( F_12 ( V_7 ) )
F_112 ( V_15 , V_7 , 0 ) ;
F_158 () ;
F_114 ( V_10 , & V_7 -> V_11 ) ;
F_72 ( & V_87 ) ;
}
static void F_159 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_38 ( V_7 -> V_31 ) ;
F_38 ( V_7 -> V_39 ) ;
F_39 ( V_7 ) ;
}
static void F_160 ( struct V_2 * V_171 )
{
F_71 ( & V_87 ) ;
F_80 ( & V_93 ) ;
if ( F_44 ( V_52 ) ) {
F_37 ( V_50 . V_39 , V_77 ) ;
V_50 . V_40 = V_172 ;
} else {
F_37 ( V_50 . V_39 ,
V_50 . V_31 ) ;
V_50 . V_40 = V_50 . V_33 ;
}
F_81 ( & V_93 ) ;
F_72 ( & V_87 ) ;
}
int T_11 F_161 ( void )
{
int V_120 = 0 ;
if ( ! F_36 ( & V_50 . V_39 , V_42 ) )
F_151 () ;
if ( ! F_36 ( & V_50 . V_31 , V_42 ) )
F_151 () ;
F_162 ( V_50 . V_39 ) ;
F_163 ( V_50 . V_40 ) ;
F_162 ( V_50 . V_31 ) ;
F_163 ( V_50 . V_33 ) ;
F_115 ( & V_50 . V_122 ) ;
F_113 ( V_15 , & V_50 . V_11 ) ;
V_50 . V_61 = - 1 ;
V_120 = F_164 ( & V_173 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( ! F_36 ( & V_139 , V_42 ) )
F_151 () ;
return 0 ;
}
static void F_165 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_5 ( V_7 ) ;
while ( F_46 ( V_8 -> V_39 ) ||
F_47 ( V_8 -> V_40 ) )
V_8 = F_5 ( V_8 ) ;
if ( F_166 ( V_8 -> V_3 . V_55 , V_7 -> V_3 . V_55 ) ) {
F_167 ( L_6 ) ;
F_168 ( V_7 -> V_3 . V_55 ) ;
F_169 ( L_7 ) ;
}
}
static void
F_170 ( struct V_1 * V_7 ,
struct V_29 * V_91 , T_1 * V_113 ,
bool V_174 , bool V_175 )
{
bool V_176 ;
F_80 ( & V_93 ) ;
F_37 ( V_7 -> V_39 , V_91 ) ;
F_37 ( V_7 -> V_31 , V_91 ) ;
V_7 -> V_40 = * V_113 ;
V_7 -> V_33 = * V_113 ;
F_81 ( & V_93 ) ;
if ( V_174 && ! F_46 ( V_7 -> V_39 ) )
F_73 ( V_7 ) ;
if ( V_175 && ! F_47 ( V_7 -> V_40 ) )
F_99 ( V_7 ) ;
V_176 = F_46 ( V_7 -> V_39 ) ||
F_47 ( V_7 -> V_40 ) ;
F_72 ( & V_87 ) ;
if ( V_176 )
F_165 ( V_7 ) ;
F_71 ( & V_87 ) ;
}
static void
F_171 ( struct V_1 * V_7 ,
struct V_29 * V_91 , T_1 * V_113 ,
bool V_174 , bool V_175 )
{
if ( F_46 ( V_91 ) )
F_37 ( V_91 , F_5 ( V_7 ) -> V_31 ) ;
if ( F_47 ( * V_113 ) )
* V_113 = F_5 ( V_7 ) -> V_33 ;
F_80 ( & V_93 ) ;
F_37 ( V_7 -> V_31 , V_91 ) ;
V_7 -> V_33 = * V_113 ;
F_81 ( & V_93 ) ;
if ( V_174 )
F_73 ( V_7 ) ;
if ( V_175 )
F_99 ( V_7 ) ;
}
static void F_172 ( struct V_1 * V_7 )
{
static T_12 V_91 ;
static T_1 V_113 ;
bool V_174 ;
bool V_175 ;
V_177:
F_173 ( V_140 , V_7 -> V_56 == 0 ) ;
F_71 ( & V_87 ) ;
if ( V_7 -> V_56 ) {
F_72 ( & V_87 ) ;
goto V_177;
}
F_22 ( & V_91 , V_7 -> V_39 , F_5 ( V_7 ) -> V_31 ) ;
F_25 ( V_113 , V_7 -> V_40 , F_5 ( V_7 ) -> V_33 ) ;
V_174 = ! F_67 ( & V_91 , V_7 -> V_31 ) ;
V_175 = ! F_104 ( V_113 , V_7 -> V_33 ) ;
if ( F_44 ( V_52 ) )
F_171 ( V_7 , & V_91 , & V_113 ,
V_174 , V_175 ) ;
else
F_170 ( V_7 , & V_91 , & V_113 ,
V_174 , V_175 ) ;
F_72 ( & V_87 ) ;
}
static void F_174 ( struct V_178 * V_179 )
{
static T_12 V_91 ;
static T_1 V_113 ;
bool V_174 , V_175 ;
bool V_180 = F_44 ( V_52 ) ;
F_71 ( & V_87 ) ;
F_37 ( & V_91 , V_88 ) ;
V_113 = V_34 [ V_35 ] ;
V_174 = ! F_67 ( V_50 . V_31 , & V_91 ) ;
V_175 = ! F_104 ( V_50 . V_33 , V_113 ) ;
if ( V_174 ) {
F_80 ( & V_93 ) ;
if ( ! V_180 )
F_37 ( V_50 . V_39 , & V_91 ) ;
F_37 ( V_50 . V_31 , & V_91 ) ;
F_81 ( & V_93 ) ;
}
if ( V_175 ) {
F_80 ( & V_93 ) ;
if ( ! V_180 )
V_50 . V_40 = V_113 ;
V_50 . V_33 = V_113 ;
F_81 ( & V_93 ) ;
F_99 ( & V_50 ) ;
}
F_72 ( & V_87 ) ;
if ( V_174 || V_175 ) {
struct V_1 * V_7 ;
struct V_2 * V_64 ;
F_42 () ;
F_53 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_50 || ! F_79 ( & V_7 -> V_3 ) )
continue;
F_49 () ;
F_172 ( V_7 ) ;
F_42 () ;
F_83 ( & V_7 -> V_3 ) ;
}
F_49 () ;
}
if ( V_174 )
F_70 () ;
}
void F_175 ( bool V_181 )
{
F_68 ( 1 , NULL , NULL ) ;
F_176 ( & V_159 ) ;
}
static int F_177 ( struct V_182 * V_183 ,
unsigned long V_184 , void * V_185 )
{
F_176 ( & V_159 ) ;
return V_186 ;
}
void T_11 F_178 ( void )
{
F_37 ( V_50 . V_39 , V_88 ) ;
V_50 . V_40 = V_34 [ V_35 ] ;
V_50 . V_112 = V_50 . V_40 ;
F_37 ( V_50 . V_31 , V_88 ) ;
V_50 . V_33 = V_34 [ V_35 ] ;
F_179 ( & V_187 ) ;
}
void F_180 ( struct V_4 * V_36 , struct V_29 * V_30 )
{
unsigned long V_11 ;
F_181 ( & V_93 , V_11 ) ;
F_42 () ;
F_20 ( F_3 ( V_36 ) , V_30 ) ;
F_49 () ;
F_182 ( & V_93 , V_11 ) ;
}
void F_183 ( struct V_4 * V_36 )
{
F_42 () ;
F_184 ( V_36 , F_3 ( V_36 ) -> V_31 ) ;
F_49 () ;
}
void T_11 F_185 ( void )
{
F_163 ( V_101 -> V_40 ) ;
}
T_1 F_186 ( struct V_4 * V_36 )
{
T_1 V_188 ;
unsigned long V_11 ;
F_181 ( & V_93 , V_11 ) ;
F_42 () ;
F_23 ( F_3 ( V_36 ) , & V_188 ) ;
F_49 () ;
F_182 ( & V_93 , V_11 ) ;
return V_188 ;
}
int F_187 ( T_1 * V_189 )
{
return F_24 ( * V_189 , V_101 -> V_40 ) ;
}
static struct V_1 * F_188 ( struct V_1 * V_7 )
{
while ( ! ( F_10 ( V_7 ) || F_11 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
int F_189 ( int V_190 , T_13 V_191 )
{
struct V_1 * V_7 ;
int V_192 ;
unsigned long V_11 ;
if ( F_190 () )
return 1 ;
if ( F_191 ( V_190 , V_101 -> V_40 ) )
return 1 ;
if ( F_89 ( F_90 ( V_105 ) ) )
return 1 ;
if ( V_191 & V_193 )
return 0 ;
if ( V_101 -> V_11 & V_106 )
return 1 ;
F_181 ( & V_93 , V_11 ) ;
F_42 () ;
V_7 = F_188 ( F_3 ( V_101 ) ) ;
V_192 = F_191 ( V_190 , V_7 -> V_40 ) ;
F_49 () ;
F_182 ( & V_93 , V_11 ) ;
return V_192 ;
}
static int F_192 ( int * V_194 )
{
int V_190 ;
V_190 = F_193 ( * V_194 , V_101 -> V_40 ) ;
if ( V_190 == V_195 )
V_190 = F_194 ( V_101 -> V_40 ) ;
* V_194 = V_190 ;
return V_190 ;
}
int F_195 ( void )
{
if ( V_101 -> V_196 == V_197 )
V_101 -> V_196 =
F_196 ( & V_101 -> V_40 ) ;
return F_192 ( & V_101 -> V_196 ) ;
}
int F_197 ( void )
{
if ( V_101 -> V_198 == V_197 )
V_101 -> V_198 =
F_196 ( & V_101 -> V_40 ) ;
return F_192 ( & V_101 -> V_198 ) ;
}
int F_198 ( const struct V_4 * V_199 ,
const struct V_4 * V_200 )
{
return F_24 ( V_199 -> V_40 , V_200 -> V_40 ) ;
}
void F_199 ( void )
{
struct V_55 * V_201 ;
F_42 () ;
V_201 = F_3 ( V_101 ) -> V_3 . V_55 ;
F_200 ( L_8 , V_101 -> V_202 ) ;
F_168 ( V_201 ) ;
F_169 ( L_9 ,
F_149 ( & V_101 -> V_40 ) ) ;
F_49 () ;
}
void F_201 ( void )
{
F_42 () ;
F_120 ( & F_3 ( V_101 ) -> V_122 ) ;
F_49 () ;
}
int F_202 ( struct V_162 * V_203 , struct V_204 * V_205 ,
struct V_206 * V_206 , struct V_4 * V_36 )
{
char * V_95 , * V_37 ;
struct V_2 * V_3 ;
int V_96 ;
V_96 = - V_121 ;
V_95 = F_58 ( V_207 , V_42 ) ;
if ( ! V_95 )
goto V_49;
V_96 = - V_208 ;
F_42 () ;
V_3 = F_4 ( V_36 , V_6 ) ;
V_37 = F_203 ( V_3 -> V_55 , V_95 , V_207 ) ;
F_49 () ;
if ( ! V_37 )
goto V_209;
F_204 ( V_203 , V_37 ) ;
F_205 ( V_203 , '\n' ) ;
V_96 = 0 ;
V_209:
F_39 ( V_95 ) ;
V_49:
return V_96 ;
}
void F_206 ( struct V_162 * V_203 , struct V_4 * V_5 )
{
F_147 ( V_203 , L_10 ,
F_149 ( & V_5 -> V_40 ) ) ;
F_147 ( V_203 , L_11 ,
F_149 ( & V_5 -> V_40 ) ) ;
}
