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
if ( ! F_44 ( V_45 -> V_3 . V_52 ) && ! F_31 ( V_41 , V_47 ) )
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
if ( ( F_45 ( V_45 -> V_3 . V_52 ) || V_45 -> V_55 ) ) {
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
static int F_50 ( struct V_1 * V_56 , struct V_1 * V_57 )
{
return F_21 ( V_56 -> V_31 , V_57 -> V_31 ) ;
}
static void
F_51 ( struct V_58 * V_59 , struct V_1 * V_46 )
{
if ( V_59 -> V_60 < V_46 -> V_60 )
V_59 -> V_60 = V_46 -> V_60 ;
return;
}
static void F_52 ( struct V_58 * V_59 ,
struct V_1 * V_61 )
{
struct V_1 * V_62 ;
struct V_2 * V_63 ;
F_42 () ;
F_53 (cp, pos_css, root_cs) {
if ( F_46 ( V_62 -> V_39 ) ) {
V_63 = F_54 ( V_63 ) ;
continue;
}
if ( F_12 ( V_62 ) )
F_51 ( V_59 , V_62 ) ;
}
F_49 () ;
}
static int F_55 ( T_2 * * V_64 ,
struct V_58 * * V_65 )
{
struct V_1 * V_62 ;
struct V_1 * * V_66 ;
int V_67 ;
int V_68 , V_69 , V_70 ;
T_2 * V_71 ;
T_2 V_72 ;
struct V_58 * V_59 ;
int V_73 = 0 ;
int V_74 ;
struct V_2 * V_63 ;
V_71 = NULL ;
V_59 = NULL ;
V_66 = NULL ;
if ( ! F_36 ( & V_72 , V_42 ) )
goto V_75;
F_56 ( V_72 , V_76 , V_77 ) ;
if ( F_12 ( & V_50 ) ) {
V_73 = 1 ;
V_71 = F_57 ( V_73 ) ;
if ( ! V_71 )
goto V_75;
V_59 = F_58 ( sizeof( struct V_58 ) , V_42 ) ;
if ( V_59 ) {
* V_59 = V_78 ;
F_52 ( V_59 , & V_50 ) ;
}
F_22 ( V_71 [ 0 ] , V_50 . V_31 ,
V_72 ) ;
goto V_75;
}
V_66 = F_58 ( F_59 () * sizeof( V_62 ) , V_42 ) ;
if ( ! V_66 )
goto V_75;
V_67 = 0 ;
F_42 () ;
F_53 (cp, pos_css, &top_cpuset) {
if ( V_62 == & V_50 )
continue;
if ( ! F_46 ( V_62 -> V_39 ) &&
! ( F_12 ( V_62 ) &&
F_21 ( V_62 -> V_39 , V_72 ) ) )
continue;
if ( F_12 ( V_62 ) )
V_66 [ V_67 ++ ] = V_62 ;
V_63 = F_54 ( V_63 ) ;
}
F_49 () ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ )
V_66 [ V_68 ] -> V_79 = V_68 ;
V_73 = V_67 ;
V_80:
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
struct V_1 * V_56 = V_66 [ V_68 ] ;
int V_81 = V_56 -> V_79 ;
for ( V_69 = 0 ; V_69 < V_67 ; V_69 ++ ) {
struct V_1 * V_57 = V_66 [ V_69 ] ;
int V_82 = V_57 -> V_79 ;
if ( V_81 != V_82 && F_50 ( V_56 , V_57 ) ) {
for ( V_70 = 0 ; V_70 < V_67 ; V_70 ++ ) {
struct V_1 * V_46 = V_66 [ V_70 ] ;
if ( V_46 -> V_79 == V_82 )
V_46 -> V_79 = V_81 ;
}
V_73 -- ;
goto V_80;
}
}
}
V_71 = F_57 ( V_73 ) ;
if ( ! V_71 )
goto V_75;
V_59 = F_58 ( V_73 * sizeof( struct V_58 ) , V_42 ) ;
for ( V_74 = 0 , V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
struct V_1 * V_56 = V_66 [ V_68 ] ;
struct V_29 * V_83 ;
int V_81 = V_56 -> V_79 ;
if ( V_81 < 0 ) {
continue;
}
V_83 = V_71 [ V_74 ] ;
if ( V_74 == V_73 ) {
static int V_84 = 10 ;
if ( V_84 ) {
F_60 ( L_4 ,
V_74 , V_73 , V_67 , V_68 , V_81 ) ;
V_84 -- ;
}
continue;
}
F_61 ( V_83 ) ;
if ( V_59 )
* ( V_59 + V_74 ) = V_78 ;
for ( V_69 = V_68 ; V_69 < V_67 ; V_69 ++ ) {
struct V_1 * V_57 = V_66 [ V_69 ] ;
if ( V_81 == V_57 -> V_79 ) {
F_62 ( V_83 , V_83 , V_57 -> V_31 ) ;
F_22 ( V_83 , V_83 , V_72 ) ;
if ( V_59 )
F_52 ( V_59 + V_74 , V_57 ) ;
V_57 -> V_79 = - 1 ;
}
}
V_74 ++ ;
}
F_63 ( V_74 != V_73 ) ;
V_75:
F_38 ( V_72 ) ;
F_39 ( V_66 ) ;
if ( V_71 == NULL )
V_73 = 1 ;
* V_64 = V_71 ;
* V_65 = V_59 ;
return V_73 ;
}
static void F_64 ( void )
{
struct V_58 * V_85 ;
T_2 * V_71 ;
int V_73 ;
F_65 ( & V_86 ) ;
F_66 () ;
if ( ! F_67 ( V_50 . V_31 , V_87 ) )
goto V_49;
V_73 = F_55 ( & V_71 , & V_85 ) ;
F_68 ( V_73 , V_71 , V_85 ) ;
V_49:
F_69 () ;
}
static void F_64 ( void )
{
}
void F_70 ( void )
{
F_71 ( & V_86 ) ;
F_64 () ;
F_72 ( & V_86 ) ;
}
static void F_73 ( struct V_1 * V_7 )
{
struct V_88 V_89 ;
struct V_4 * V_5 ;
F_74 ( & V_7 -> V_3 , & V_89 ) ;
while ( ( V_5 = F_75 ( & V_89 ) ) )
F_76 ( V_5 , V_7 -> V_31 ) ;
F_77 ( & V_89 ) ;
}
static void F_78 ( struct V_1 * V_7 , struct V_29 * V_90 )
{
struct V_1 * V_62 ;
struct V_2 * V_63 ;
bool V_91 = false ;
F_42 () ;
F_53 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_62 ) ;
F_22 ( V_90 , V_62 -> V_39 , V_8 -> V_31 ) ;
if ( F_44 ( V_62 -> V_3 . V_52 ) && F_46 ( V_90 ) )
F_37 ( V_90 , V_8 -> V_31 ) ;
if ( F_67 ( V_90 , V_62 -> V_31 ) ) {
V_63 = F_54 ( V_63 ) ;
continue;
}
if ( ! F_79 ( & V_62 -> V_3 ) )
continue;
F_49 () ;
F_80 ( & V_92 ) ;
F_37 ( V_62 -> V_31 , V_90 ) ;
F_81 ( & V_92 ) ;
F_82 ( ! F_44 ( V_62 -> V_3 . V_52 ) &&
! F_67 ( V_62 -> V_39 , V_62 -> V_31 ) ) ;
F_73 ( V_62 ) ;
if ( ! F_46 ( V_62 -> V_39 ) &&
F_12 ( V_62 ) )
V_91 = true ;
F_42 () ;
F_83 ( & V_62 -> V_3 ) ;
}
F_49 () ;
if ( V_91 )
F_64 () ;
}
static int F_84 ( struct V_1 * V_7 , struct V_1 * V_93 ,
const char * V_94 )
{
int V_95 ;
if ( V_7 == & V_50 )
return - V_51 ;
if ( ! * V_94 ) {
F_61 ( V_93 -> V_39 ) ;
} else {
V_95 = F_85 ( V_94 , V_93 -> V_39 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( ! F_32 ( V_93 -> V_39 ,
V_50 . V_39 ) )
return - V_53 ;
}
if ( F_67 ( V_7 -> V_39 , V_93 -> V_39 ) )
return 0 ;
V_95 = F_41 ( V_7 , V_93 ) ;
if ( V_95 < 0 )
return V_95 ;
F_80 ( & V_92 ) ;
F_37 ( V_7 -> V_39 , V_93 -> V_39 ) ;
F_81 ( & V_92 ) ;
F_78 ( V_7 , V_93 -> V_39 ) ;
return 0 ;
}
static void F_86 ( struct V_96 * V_97 , const T_1 * V_98 ,
const T_1 * V_99 )
{
struct V_4 * V_36 = V_100 ;
V_36 -> V_40 = * V_99 ;
F_87 ( V_97 , V_98 , V_99 , V_101 ) ;
F_42 () ;
F_23 ( F_3 ( V_36 ) , & V_36 -> V_40 ) ;
F_49 () ;
}
static void F_88 ( struct V_4 * V_36 ,
T_1 * V_102 )
{
bool V_103 ;
if ( F_89 ( F_90 ( V_104 ) ) )
return;
if ( V_100 -> V_11 & V_105 )
return;
F_91 ( V_36 ) ;
V_103 = F_6 ( V_36 ) ||
! F_24 ( * V_102 , V_36 -> V_40 ) ;
if ( V_103 ) {
F_92 () ;
F_93 ( & V_36 -> V_106 ) ;
}
F_94 ( V_36 -> V_40 , V_36 -> V_40 , * V_102 ) ;
F_95 ( V_36 , V_102 , V_107 ) ;
F_95 ( V_36 , V_102 , V_108 ) ;
V_36 -> V_40 = * V_102 ;
if ( V_103 ) {
F_96 ( & V_36 -> V_106 ) ;
F_97 () ;
}
F_98 ( V_36 ) ;
}
static void F_99 ( struct V_1 * V_7 )
{
static T_1 V_102 ;
struct V_88 V_89 ;
struct V_4 * V_5 ;
V_109 = V_7 ;
F_23 ( V_7 , & V_102 ) ;
F_74 ( & V_7 -> V_3 , & V_89 ) ;
while ( ( V_5 = F_75 ( & V_89 ) ) ) {
struct V_96 * V_97 ;
bool V_110 ;
F_88 ( V_5 , & V_102 ) ;
V_97 = F_100 ( V_5 ) ;
if ( ! V_97 )
continue;
V_110 = F_13 ( V_7 ) ;
F_101 ( V_97 , & V_7 -> V_40 ) ;
if ( V_110 )
F_86 ( V_97 , & V_7 -> V_111 , & V_102 ) ;
F_102 ( V_97 ) ;
}
F_77 ( & V_89 ) ;
V_7 -> V_111 = V_102 ;
V_109 = NULL ;
}
static void F_103 ( struct V_1 * V_7 , T_1 * V_112 )
{
struct V_1 * V_62 ;
struct V_2 * V_63 ;
F_42 () ;
F_53 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_62 ) ;
F_25 ( * V_112 , V_62 -> V_40 , V_8 -> V_33 ) ;
if ( F_44 ( V_62 -> V_3 . V_52 ) && F_47 ( * V_112 ) )
* V_112 = V_8 -> V_33 ;
if ( F_104 ( * V_112 , V_62 -> V_33 ) ) {
V_63 = F_54 ( V_63 ) ;
continue;
}
if ( ! F_79 ( & V_62 -> V_3 ) )
continue;
F_49 () ;
F_80 ( & V_92 ) ;
V_62 -> V_33 = * V_112 ;
F_81 ( & V_92 ) ;
F_82 ( ! F_44 ( V_62 -> V_3 . V_52 ) &&
! F_104 ( V_62 -> V_40 , V_62 -> V_33 ) ) ;
F_99 ( V_62 ) ;
F_42 () ;
F_83 ( & V_62 -> V_3 ) ;
}
F_49 () ;
}
static int F_105 ( struct V_1 * V_7 , struct V_1 * V_93 ,
const char * V_94 )
{
int V_95 ;
if ( V_7 == & V_50 ) {
V_95 = - V_51 ;
goto V_75;
}
if ( ! * V_94 ) {
F_106 ( V_93 -> V_40 ) ;
} else {
V_95 = F_107 ( V_94 , V_93 -> V_40 ) ;
if ( V_95 < 0 )
goto V_75;
if ( ! F_33 ( V_93 -> V_40 ,
V_50 . V_40 ) ) {
V_95 = - V_53 ;
goto V_75;
}
}
if ( F_104 ( V_7 -> V_40 , V_93 -> V_40 ) ) {
V_95 = 0 ;
goto V_75;
}
V_95 = F_41 ( V_7 , V_93 ) ;
if ( V_95 < 0 )
goto V_75;
F_80 ( & V_92 ) ;
V_7 -> V_40 = V_93 -> V_40 ;
F_81 ( & V_92 ) ;
F_103 ( V_7 , & V_93 -> V_40 ) ;
V_75:
return V_95 ;
}
int F_108 ( void )
{
int V_25 ;
F_42 () ;
V_25 = F_3 ( V_100 ) == V_109 ;
F_49 () ;
return V_25 ;
}
static int F_109 ( struct V_1 * V_7 , T_3 V_113 )
{
#ifdef F_110
if ( V_113 < - 1 || V_113 >= V_114 )
return - V_53 ;
#endif
if ( V_113 != V_7 -> V_60 ) {
V_7 -> V_60 = V_113 ;
if ( ! F_46 ( V_7 -> V_39 ) &&
F_12 ( V_7 ) )
F_64 () ;
}
return 0 ;
}
static void F_111 ( struct V_1 * V_7 )
{
struct V_88 V_89 ;
struct V_4 * V_5 ;
F_74 ( & V_7 -> V_3 , & V_89 ) ;
while ( ( V_5 = F_75 ( & V_89 ) ) )
F_26 ( V_7 , V_5 ) ;
F_77 ( & V_89 ) ;
}
static int F_112 ( T_4 V_115 , struct V_1 * V_7 ,
int V_116 )
{
struct V_1 * V_93 ;
int V_117 ;
int V_118 ;
int V_119 ;
V_93 = F_34 ( V_7 ) ;
if ( ! V_93 )
return - V_120 ;
if ( V_116 )
F_113 ( V_115 , & V_93 -> V_11 ) ;
else
F_114 ( V_115 , & V_93 -> V_11 ) ;
V_119 = F_41 ( V_7 , V_93 ) ;
if ( V_119 < 0 )
goto V_49;
V_117 = ( F_12 ( V_7 ) !=
F_12 ( V_93 ) ) ;
V_118 = ( ( F_15 ( V_7 ) != F_15 ( V_93 ) )
|| ( F_14 ( V_7 ) != F_14 ( V_93 ) ) ) ;
F_80 ( & V_92 ) ;
V_7 -> V_11 = V_93 -> V_11 ;
F_81 ( & V_92 ) ;
if ( ! F_46 ( V_93 -> V_39 ) && V_117 )
F_64 () ;
if ( V_118 )
F_111 ( V_7 ) ;
V_49:
F_40 ( V_93 ) ;
return V_119 ;
}
static void F_115 ( struct V_121 * V_122 )
{
V_122 -> V_123 = 0 ;
V_122 -> V_113 = 0 ;
V_122 -> time = 0 ;
F_116 ( & V_122 -> V_124 ) ;
}
static void F_117 ( struct V_121 * V_122 )
{
T_5 V_125 = F_118 () ;
T_5 V_126 = V_125 - V_122 -> time ;
if ( V_126 == 0 )
return;
V_126 = F_119 ( V_127 , V_126 ) ;
while ( V_126 -- > 0 )
V_122 -> V_113 = ( V_128 * V_122 -> V_113 ) / V_129 ;
V_122 -> time = V_125 ;
V_122 -> V_113 += ( ( V_129 - V_128 ) * V_122 -> V_123 ) / V_129 ;
V_122 -> V_123 = 0 ;
}
static void F_120 ( struct V_121 * V_122 )
{
F_121 ( & V_122 -> V_124 ) ;
F_117 ( V_122 ) ;
V_122 -> V_123 = F_119 ( V_130 , V_122 -> V_123 + V_129 ) ;
F_122 ( & V_122 -> V_124 ) ;
}
static int F_123 ( struct V_121 * V_122 )
{
int V_113 ;
F_121 ( & V_122 -> V_124 ) ;
F_117 ( V_122 ) ;
V_113 = V_122 -> V_113 ;
F_122 ( & V_122 -> V_124 ) ;
return V_113 ;
}
static int F_124 ( struct V_2 * V_3 ,
struct V_131 * V_132 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_4 * V_5 ;
int V_25 ;
V_133 = F_3 ( F_125 ( V_132 ) ) ;
F_71 ( & V_86 ) ;
V_25 = - V_54 ;
if ( ! F_44 ( V_3 -> V_52 ) &&
( F_46 ( V_7 -> V_39 ) || F_47 ( V_7 -> V_40 ) ) )
goto V_134;
F_126 (task, tset) {
V_25 = F_127 ( V_5 , V_7 -> V_39 ) ;
if ( V_25 )
goto V_134;
V_25 = F_128 ( V_5 ) ;
if ( V_25 )
goto V_134;
}
V_7 -> V_55 ++ ;
V_25 = 0 ;
V_134:
F_72 ( & V_86 ) ;
return V_25 ;
}
static void F_129 ( struct V_2 * V_3 ,
struct V_131 * V_132 )
{
F_71 ( & V_86 ) ;
F_1 ( V_3 ) -> V_55 -- ;
F_72 ( & V_86 ) ;
}
static void F_130 ( struct V_2 * V_3 ,
struct V_131 * V_132 )
{
static T_1 V_135 ;
struct V_96 * V_97 ;
struct V_4 * V_5 ;
struct V_4 * V_136 = F_125 ( V_132 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_137 = V_133 ;
F_71 ( & V_86 ) ;
if ( V_7 == & V_50 )
F_37 ( V_138 , V_76 ) ;
else
F_20 ( V_7 , V_138 ) ;
F_23 ( V_7 , & V_135 ) ;
F_126 (task, tset) {
F_131 ( F_76 ( V_5 , V_138 ) ) ;
F_88 ( V_5 , & V_135 ) ;
F_26 ( V_7 , V_5 ) ;
}
V_135 = V_7 -> V_33 ;
V_97 = F_100 ( V_136 ) ;
if ( V_97 ) {
F_101 ( V_97 , & V_135 ) ;
if ( F_13 ( V_7 ) ) {
F_86 ( V_97 , & V_137 -> V_111 ,
& V_135 ) ;
}
F_102 ( V_97 ) ;
}
V_7 -> V_111 = V_135 ;
V_7 -> V_55 -- ;
if ( ! V_7 -> V_55 )
F_132 ( & V_139 ) ;
F_72 ( & V_86 ) ;
}
static int F_133 ( struct V_2 * V_3 , struct V_140 * V_141 ,
T_6 V_113 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_141 -> V_142 ;
int V_95 = 0 ;
F_71 ( & V_86 ) ;
if ( ! F_7 ( V_7 ) ) {
V_95 = - V_26 ;
goto V_134;
}
switch ( type ) {
case V_143 :
V_95 = F_112 ( V_12 , V_7 , V_113 ) ;
break;
case V_144 :
V_95 = F_112 ( V_13 , V_7 , V_113 ) ;
break;
case V_145 :
V_95 = F_112 ( V_14 , V_7 , V_113 ) ;
break;
case V_146 :
V_95 = F_112 ( V_15 , V_7 , V_113 ) ;
break;
case V_147 :
V_95 = F_112 ( V_16 , V_7 , V_113 ) ;
break;
case V_148 :
V_149 = ! ! V_113 ;
break;
case V_150 :
V_95 = - V_51 ;
break;
case V_151 :
V_95 = F_112 ( V_17 , V_7 , V_113 ) ;
break;
case V_152 :
V_95 = F_112 ( V_18 , V_7 , V_113 ) ;
break;
default:
V_95 = - V_53 ;
break;
}
V_134:
F_72 ( & V_86 ) ;
return V_95 ;
}
static int F_134 ( struct V_2 * V_3 , struct V_140 * V_141 ,
T_3 V_113 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_141 -> V_142 ;
int V_95 = - V_26 ;
F_71 ( & V_86 ) ;
if ( ! F_7 ( V_7 ) )
goto V_134;
switch ( type ) {
case V_153 :
V_95 = F_109 ( V_7 , V_113 ) ;
break;
default:
V_95 = - V_53 ;
break;
}
V_134:
F_72 ( & V_86 ) ;
return V_95 ;
}
static T_8 F_135 ( struct V_154 * V_155 ,
char * V_94 , T_9 V_156 , T_10 V_157 )
{
struct V_1 * V_7 = F_1 ( F_136 ( V_155 ) ) ;
struct V_1 * V_93 ;
int V_95 = - V_26 ;
V_94 = F_137 ( V_94 ) ;
F_138 ( & V_7 -> V_3 ) ;
F_139 ( V_155 -> V_158 ) ;
F_140 ( & V_159 ) ;
F_71 ( & V_86 ) ;
if ( ! F_7 ( V_7 ) )
goto V_134;
V_93 = F_34 ( V_7 ) ;
if ( ! V_93 ) {
V_95 = - V_120 ;
goto V_134;
}
switch ( F_141 ( V_155 ) -> V_142 ) {
case V_160 :
V_95 = F_84 ( V_7 , V_93 , V_94 ) ;
break;
case V_161 :
V_95 = F_105 ( V_7 , V_93 , V_94 ) ;
break;
default:
V_95 = - V_53 ;
break;
}
F_40 ( V_93 ) ;
V_134:
F_72 ( & V_86 ) ;
F_142 ( V_155 -> V_158 ) ;
F_83 ( & V_7 -> V_3 ) ;
return V_95 ? : V_156 ;
}
static int F_143 ( struct V_162 * V_163 , void * V_164 )
{
struct V_1 * V_7 = F_1 ( F_144 ( V_163 ) ) ;
T_7 type = F_145 ( V_163 ) -> V_142 ;
int V_25 = 0 ;
F_80 ( & V_92 ) ;
switch ( type ) {
case V_160 :
F_146 ( V_163 , L_5 , F_147 ( V_7 -> V_39 ) ) ;
break;
case V_161 :
F_146 ( V_163 , L_5 , F_148 ( & V_7 -> V_40 ) ) ;
break;
case V_165 :
F_146 ( V_163 , L_5 , F_147 ( V_7 -> V_31 ) ) ;
break;
case V_166 :
F_146 ( V_163 , L_5 , F_148 ( & V_7 -> V_33 ) ) ;
break;
default:
V_25 = - V_53 ;
}
F_81 ( & V_92 ) ;
return V_25 ;
}
static T_6 F_149 ( struct V_2 * V_3 , struct V_140 * V_141 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_141 -> V_142 ;
switch ( type ) {
case V_143 :
return F_9 ( V_7 ) ;
case V_144 :
return F_10 ( V_7 ) ;
case V_145 :
return F_11 ( V_7 ) ;
case V_146 :
return F_12 ( V_7 ) ;
case V_147 :
return F_13 ( V_7 ) ;
case V_148 :
return V_149 ;
case V_150 :
return F_123 ( & V_7 -> V_121 ) ;
case V_151 :
return F_14 ( V_7 ) ;
case V_152 :
return F_15 ( V_7 ) ;
default:
F_150 () ;
}
return 0 ;
}
static T_3 F_151 ( struct V_2 * V_3 , struct V_140 * V_141 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_141 -> V_142 ;
switch ( type ) {
case V_153 :
return V_7 -> V_60 ;
default:
F_150 () ;
}
return 0 ;
}
static struct V_2 *
F_152 ( struct V_2 * V_167 )
{
struct V_1 * V_7 ;
if ( ! V_167 )
return & V_50 . V_3 ;
V_7 = F_153 ( sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 )
return F_18 ( - V_120 ) ;
if ( ! F_36 ( & V_7 -> V_39 , V_42 ) )
goto V_43;
if ( ! F_36 ( & V_7 -> V_31 , V_42 ) )
goto V_44;
F_113 ( V_15 , & V_7 -> V_11 ) ;
F_61 ( V_7 -> V_39 ) ;
F_106 ( V_7 -> V_40 ) ;
F_61 ( V_7 -> V_31 ) ;
F_106 ( V_7 -> V_33 ) ;
F_115 ( & V_7 -> V_121 ) ;
V_7 -> V_60 = - 1 ;
return & V_7 -> V_3 ;
V_44:
F_38 ( V_7 -> V_39 ) ;
V_43:
F_39 ( V_7 ) ;
return F_18 ( - V_120 ) ;
}
static int F_154 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_8 = F_5 ( V_7 ) ;
struct V_1 * V_168 ;
struct V_2 * V_63 ;
if ( ! V_8 )
return 0 ;
F_71 ( & V_86 ) ;
F_113 ( V_10 , & V_7 -> V_11 ) ;
if ( F_14 ( V_8 ) )
F_113 ( V_17 , & V_7 -> V_11 ) ;
if ( F_15 ( V_8 ) )
F_113 ( V_18 , & V_7 -> V_11 ) ;
F_155 () ;
F_80 ( & V_92 ) ;
if ( F_44 ( V_7 -> V_3 . V_52 ) ) {
F_37 ( V_7 -> V_31 , V_8 -> V_31 ) ;
V_7 -> V_33 = V_8 -> V_33 ;
}
F_81 ( & V_92 ) ;
if ( ! F_8 ( V_169 , & V_3 -> V_52 -> V_11 ) )
goto V_134;
F_42 () ;
F_43 (tmp_cs, pos_css, parent) {
if ( F_10 ( V_168 ) || F_9 ( V_168 ) ) {
F_49 () ;
goto V_134;
}
}
F_49 () ;
F_80 ( & V_92 ) ;
V_7 -> V_40 = V_8 -> V_40 ;
V_7 -> V_33 = V_8 -> V_40 ;
F_37 ( V_7 -> V_39 , V_8 -> V_39 ) ;
F_37 ( V_7 -> V_31 , V_8 -> V_39 ) ;
F_81 ( & V_92 ) ;
V_134:
F_72 ( & V_86 ) ;
return 0 ;
}
static void F_156 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_71 ( & V_86 ) ;
if ( F_12 ( V_7 ) )
F_112 ( V_15 , V_7 , 0 ) ;
F_157 () ;
F_114 ( V_10 , & V_7 -> V_11 ) ;
F_72 ( & V_86 ) ;
}
static void F_158 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_38 ( V_7 -> V_31 ) ;
F_38 ( V_7 -> V_39 ) ;
F_39 ( V_7 ) ;
}
static void F_159 ( struct V_2 * V_170 )
{
F_71 ( & V_86 ) ;
F_80 ( & V_92 ) ;
if ( F_44 ( V_170 -> V_52 ) ) {
F_37 ( V_50 . V_39 , V_76 ) ;
V_50 . V_40 = V_171 ;
} else {
F_37 ( V_50 . V_39 ,
V_50 . V_31 ) ;
V_50 . V_40 = V_50 . V_33 ;
}
F_81 ( & V_92 ) ;
F_72 ( & V_86 ) ;
}
int T_11 F_160 ( void )
{
int V_119 = 0 ;
if ( ! F_36 ( & V_50 . V_39 , V_42 ) )
F_150 () ;
if ( ! F_36 ( & V_50 . V_31 , V_42 ) )
F_150 () ;
F_161 ( V_50 . V_39 ) ;
F_162 ( V_50 . V_40 ) ;
F_161 ( V_50 . V_31 ) ;
F_162 ( V_50 . V_33 ) ;
F_115 ( & V_50 . V_121 ) ;
F_113 ( V_15 , & V_50 . V_11 ) ;
V_50 . V_60 = - 1 ;
V_119 = F_163 ( & V_172 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( ! F_36 ( & V_138 , V_42 ) )
F_150 () ;
return 0 ;
}
static void F_164 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_5 ( V_7 ) ;
while ( F_46 ( V_8 -> V_39 ) ||
F_47 ( V_8 -> V_40 ) )
V_8 = F_5 ( V_8 ) ;
if ( F_165 ( V_8 -> V_3 . V_52 , V_7 -> V_3 . V_52 ) ) {
F_166 ( L_6 ) ;
F_167 ( V_7 -> V_3 . V_52 ) ;
F_168 ( L_7 ) ;
}
}
static void
F_169 ( struct V_1 * V_7 ,
struct V_29 * V_90 , T_1 * V_112 ,
bool V_173 , bool V_174 )
{
bool V_175 ;
F_80 ( & V_92 ) ;
F_37 ( V_7 -> V_39 , V_90 ) ;
F_37 ( V_7 -> V_31 , V_90 ) ;
V_7 -> V_40 = * V_112 ;
V_7 -> V_33 = * V_112 ;
F_81 ( & V_92 ) ;
if ( V_173 && ! F_46 ( V_7 -> V_39 ) )
F_73 ( V_7 ) ;
if ( V_174 && ! F_47 ( V_7 -> V_40 ) )
F_99 ( V_7 ) ;
V_175 = F_46 ( V_7 -> V_39 ) ||
F_47 ( V_7 -> V_40 ) ;
F_72 ( & V_86 ) ;
if ( V_175 )
F_164 ( V_7 ) ;
F_71 ( & V_86 ) ;
}
static void
F_170 ( struct V_1 * V_7 ,
struct V_29 * V_90 , T_1 * V_112 ,
bool V_173 , bool V_174 )
{
if ( F_46 ( V_90 ) )
F_37 ( V_90 , F_5 ( V_7 ) -> V_31 ) ;
if ( F_47 ( * V_112 ) )
* V_112 = F_5 ( V_7 ) -> V_33 ;
F_80 ( & V_92 ) ;
F_37 ( V_7 -> V_31 , V_90 ) ;
V_7 -> V_33 = * V_112 ;
F_81 ( & V_92 ) ;
if ( V_173 )
F_73 ( V_7 ) ;
if ( V_174 )
F_99 ( V_7 ) ;
}
static void F_171 ( struct V_1 * V_7 )
{
static T_12 V_90 ;
static T_1 V_112 ;
bool V_173 ;
bool V_174 ;
V_176:
F_172 ( V_139 , V_7 -> V_55 == 0 ) ;
F_71 ( & V_86 ) ;
if ( V_7 -> V_55 ) {
F_72 ( & V_86 ) ;
goto V_176;
}
F_22 ( & V_90 , V_7 -> V_39 , F_5 ( V_7 ) -> V_31 ) ;
F_25 ( V_112 , V_7 -> V_40 , F_5 ( V_7 ) -> V_33 ) ;
V_173 = ! F_67 ( & V_90 , V_7 -> V_31 ) ;
V_174 = ! F_104 ( V_112 , V_7 -> V_33 ) ;
if ( F_44 ( V_7 -> V_3 . V_52 ) )
F_170 ( V_7 , & V_90 , & V_112 ,
V_173 , V_174 ) ;
else
F_169 ( V_7 , & V_90 , & V_112 ,
V_173 , V_174 ) ;
F_72 ( & V_86 ) ;
}
static void F_173 ( struct V_177 * V_178 )
{
static T_12 V_90 ;
static T_1 V_112 ;
bool V_173 , V_174 ;
bool V_179 = F_44 ( V_50 . V_3 . V_52 ) ;
F_71 ( & V_86 ) ;
F_37 ( & V_90 , V_87 ) ;
V_112 = V_34 [ V_35 ] ;
V_173 = ! F_67 ( V_50 . V_31 , & V_90 ) ;
V_174 = ! F_104 ( V_50 . V_33 , V_112 ) ;
if ( V_173 ) {
F_80 ( & V_92 ) ;
if ( ! V_179 )
F_37 ( V_50 . V_39 , & V_90 ) ;
F_37 ( V_50 . V_31 , & V_90 ) ;
F_81 ( & V_92 ) ;
}
if ( V_174 ) {
F_80 ( & V_92 ) ;
if ( ! V_179 )
V_50 . V_40 = V_112 ;
V_50 . V_33 = V_112 ;
F_81 ( & V_92 ) ;
F_99 ( & V_50 ) ;
}
F_72 ( & V_86 ) ;
if ( V_173 || V_174 ) {
struct V_1 * V_7 ;
struct V_2 * V_63 ;
F_42 () ;
F_53 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_50 || ! F_79 ( & V_7 -> V_3 ) )
continue;
F_49 () ;
F_171 ( V_7 ) ;
F_42 () ;
F_83 ( & V_7 -> V_3 ) ;
}
F_49 () ;
}
if ( V_173 )
F_70 () ;
}
void F_174 ( bool V_180 )
{
F_68 ( 1 , NULL , NULL ) ;
F_175 ( & V_159 ) ;
}
static int F_176 ( struct V_181 * V_182 ,
unsigned long V_183 , void * V_184 )
{
F_175 ( & V_159 ) ;
return V_185 ;
}
void T_11 F_177 ( void )
{
F_37 ( V_50 . V_39 , V_87 ) ;
V_50 . V_40 = V_34 [ V_35 ] ;
V_50 . V_111 = V_50 . V_40 ;
F_37 ( V_50 . V_31 , V_87 ) ;
V_50 . V_33 = V_34 [ V_35 ] ;
F_178 ( & V_186 ) ;
}
void F_179 ( struct V_4 * V_36 , struct V_29 * V_30 )
{
unsigned long V_11 ;
F_180 ( & V_92 , V_11 ) ;
F_42 () ;
F_20 ( F_3 ( V_36 ) , V_30 ) ;
F_49 () ;
F_181 ( & V_92 , V_11 ) ;
}
void F_182 ( struct V_4 * V_36 )
{
F_42 () ;
F_183 ( V_36 , F_3 ( V_36 ) -> V_31 ) ;
F_49 () ;
}
void T_11 F_184 ( void )
{
F_162 ( V_100 -> V_40 ) ;
}
T_1 F_185 ( struct V_4 * V_36 )
{
T_1 V_187 ;
unsigned long V_11 ;
F_180 ( & V_92 , V_11 ) ;
F_42 () ;
F_23 ( F_3 ( V_36 ) , & V_187 ) ;
F_49 () ;
F_181 ( & V_92 , V_11 ) ;
return V_187 ;
}
int F_186 ( T_1 * V_188 )
{
return F_24 ( * V_188 , V_100 -> V_40 ) ;
}
static struct V_1 * F_187 ( struct V_1 * V_7 )
{
while ( ! ( F_10 ( V_7 ) || F_11 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
int F_188 ( int V_189 , T_13 V_190 )
{
struct V_1 * V_7 ;
int V_191 ;
unsigned long V_11 ;
if ( F_189 () )
return 1 ;
if ( F_190 ( V_189 , V_100 -> V_40 ) )
return 1 ;
if ( F_89 ( F_90 ( V_104 ) ) )
return 1 ;
if ( V_190 & V_192 )
return 0 ;
if ( V_100 -> V_11 & V_105 )
return 1 ;
F_180 ( & V_92 , V_11 ) ;
F_42 () ;
V_7 = F_187 ( F_3 ( V_100 ) ) ;
V_191 = F_190 ( V_189 , V_7 -> V_40 ) ;
F_49 () ;
F_181 ( & V_92 , V_11 ) ;
return V_191 ;
}
static int F_191 ( int * V_193 )
{
int V_189 ;
V_189 = F_192 ( * V_193 , V_100 -> V_40 ) ;
if ( V_189 == V_194 )
V_189 = F_193 ( V_100 -> V_40 ) ;
* V_193 = V_189 ;
return V_189 ;
}
int F_194 ( void )
{
if ( V_100 -> V_195 == V_196 )
V_100 -> V_195 =
F_195 ( & V_100 -> V_40 ) ;
return F_191 ( & V_100 -> V_195 ) ;
}
int F_196 ( void )
{
if ( V_100 -> V_197 == V_196 )
V_100 -> V_197 =
F_195 ( & V_100 -> V_40 ) ;
return F_191 ( & V_100 -> V_197 ) ;
}
int F_197 ( const struct V_4 * V_198 ,
const struct V_4 * V_199 )
{
return F_24 ( V_198 -> V_40 , V_199 -> V_40 ) ;
}
void F_198 ( struct V_4 * V_36 )
{
struct V_52 * V_200 ;
F_42 () ;
V_200 = F_3 ( V_36 ) -> V_3 . V_52 ;
F_199 ( L_8 , V_36 -> V_201 ) ;
F_167 ( V_200 ) ;
F_168 ( L_9 , F_148 ( & V_36 -> V_40 ) ) ;
F_49 () ;
}
void F_200 ( void )
{
F_42 () ;
F_120 ( & F_3 ( V_100 ) -> V_121 ) ;
F_49 () ;
}
int F_201 ( struct V_162 * V_202 , struct V_203 * V_204 ,
struct V_205 * V_205 , struct V_4 * V_36 )
{
char * V_94 , * V_37 ;
struct V_2 * V_3 ;
int V_95 ;
V_95 = - V_120 ;
V_94 = F_58 ( V_206 , V_42 ) ;
if ( ! V_94 )
goto V_49;
V_95 = - V_207 ;
F_42 () ;
V_3 = F_4 ( V_36 , V_6 ) ;
V_37 = F_202 ( V_3 -> V_52 , V_94 , V_206 ) ;
F_49 () ;
if ( ! V_37 )
goto V_208;
F_203 ( V_202 , V_37 ) ;
F_204 ( V_202 , '\n' ) ;
V_95 = 0 ;
V_208:
F_39 ( V_94 ) ;
V_49:
return V_95 ;
}
void F_205 ( struct V_162 * V_202 , struct V_4 * V_5 )
{
F_146 ( V_202 , L_10 ,
F_148 ( & V_5 -> V_40 ) ) ;
F_146 ( V_202 , L_11 ,
F_148 ( & V_5 -> V_40 ) ) ;
}
