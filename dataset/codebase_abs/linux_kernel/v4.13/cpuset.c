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
static struct V_19 * F_17 ( struct V_20 * V_21 ,
int V_11 , const char * V_22 , void * V_23 )
{
struct V_20 * V_24 = F_18 ( L_1 ) ;
struct V_19 * V_25 = F_19 ( - V_26 ) ;
if ( V_24 ) {
char V_27 [] =
L_2
L_3 ;
V_25 = V_24 -> V_28 ( V_24 , V_11 ,
V_22 , V_27 ) ;
F_20 ( V_24 ) ;
}
return V_25 ;
}
static void F_21 ( struct V_1 * V_7 , struct V_29 * V_30 )
{
while ( ! F_22 ( V_7 -> V_31 , V_32 ) ) {
V_7 = F_5 ( V_7 ) ;
if ( F_23 ( ! V_7 ) ) {
F_24 ( V_30 , V_32 ) ;
return;
}
}
F_25 ( V_30 , V_7 -> V_31 , V_32 ) ;
}
static void F_26 ( struct V_1 * V_7 , T_1 * V_30 )
{
while ( ! F_27 ( V_7 -> V_33 , V_34 [ V_35 ] ) )
V_7 = F_5 ( V_7 ) ;
F_28 ( * V_30 , V_7 -> V_33 , V_34 [ V_35 ] ) ;
}
static void F_29 ( struct V_1 * V_7 ,
struct V_4 * V_36 )
{
if ( F_15 ( V_7 ) )
F_30 ( V_36 ) ;
else
F_31 ( V_36 ) ;
if ( F_16 ( V_7 ) )
F_32 ( V_36 ) ;
else
F_33 ( V_36 ) ;
}
static int F_34 ( const struct V_1 * V_37 , const struct V_1 * V_38 )
{
return F_35 ( V_37 -> V_39 , V_38 -> V_39 ) &&
F_36 ( V_37 -> V_40 , V_38 -> V_40 ) &&
F_10 ( V_37 ) <= F_10 ( V_38 ) &&
F_11 ( V_37 ) <= F_11 ( V_38 ) ;
}
static struct V_1 * F_37 ( struct V_1 * V_7 )
{
struct V_1 * V_41 ;
V_41 = F_38 ( V_7 , sizeof( * V_7 ) , V_42 ) ;
if ( ! V_41 )
return NULL ;
if ( ! F_39 ( & V_41 -> V_39 , V_42 ) )
goto V_43;
if ( ! F_39 ( & V_41 -> V_31 , V_42 ) )
goto V_44;
F_24 ( V_41 -> V_39 , V_7 -> V_39 ) ;
F_24 ( V_41 -> V_31 , V_7 -> V_31 ) ;
return V_41 ;
V_44:
F_40 ( V_41 -> V_39 ) ;
V_43:
F_41 ( V_41 ) ;
return NULL ;
}
static void F_42 ( struct V_1 * V_41 )
{
F_40 ( V_41 -> V_31 ) ;
F_40 ( V_41 -> V_39 ) ;
F_41 ( V_41 ) ;
}
static int F_43 ( struct V_1 * V_45 , struct V_1 * V_41 )
{
struct V_2 * V_3 ;
struct V_1 * V_46 , * V_47 ;
int V_25 ;
F_44 () ;
V_25 = - V_48 ;
F_45 (c, css, cur)
if ( ! F_34 ( V_46 , V_41 ) )
goto V_49;
V_25 = 0 ;
if ( V_45 == & V_50 )
goto V_49;
V_47 = F_5 ( V_45 ) ;
V_25 = - V_51 ;
if ( ! F_46 ( V_52 ) &&
! F_34 ( V_41 , V_47 ) )
goto V_49;
V_25 = - V_53 ;
F_45 (c, css, par) {
if ( ( F_10 ( V_41 ) || F_10 ( V_46 ) ) &&
V_46 != V_45 &&
F_22 ( V_41 -> V_39 , V_46 -> V_39 ) )
goto V_49;
if ( ( F_11 ( V_41 ) || F_11 ( V_46 ) ) &&
V_46 != V_45 &&
F_27 ( V_41 -> V_40 , V_46 -> V_40 ) )
goto V_49;
}
V_25 = - V_54 ;
if ( ( F_47 ( V_45 -> V_3 . V_55 ) || V_45 -> V_56 ) ) {
if ( ! F_48 ( V_45 -> V_39 ) &&
F_48 ( V_41 -> V_39 ) )
goto V_49;
if ( ! F_49 ( V_45 -> V_40 ) &&
F_49 ( V_41 -> V_40 ) )
goto V_49;
}
V_25 = - V_48 ;
if ( F_10 ( V_45 ) &&
! F_50 ( V_45 -> V_39 ,
V_41 -> V_39 ) )
goto V_49;
V_25 = 0 ;
V_49:
F_51 () ;
return V_25 ;
}
static int F_52 ( struct V_1 * V_57 , struct V_1 * V_58 )
{
return F_22 ( V_57 -> V_31 , V_58 -> V_31 ) ;
}
static void
F_53 ( struct V_59 * V_60 , struct V_1 * V_46 )
{
if ( V_60 -> V_61 < V_46 -> V_61 )
V_60 -> V_61 = V_46 -> V_61 ;
return;
}
static void F_54 ( struct V_59 * V_60 ,
struct V_1 * V_62 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
F_44 () ;
F_55 (cp, pos_css, root_cs) {
if ( F_48 ( V_63 -> V_39 ) ) {
V_64 = F_56 ( V_64 ) ;
continue;
}
if ( F_13 ( V_63 ) )
F_53 ( V_60 , V_63 ) ;
}
F_51 () ;
}
static int F_57 ( T_2 * * V_65 ,
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
if ( ! F_39 ( & V_73 , V_42 ) )
goto V_76;
F_58 ( V_73 , V_77 , V_78 ) ;
if ( F_13 ( & V_50 ) ) {
V_74 = 1 ;
V_72 = F_59 ( V_74 ) ;
if ( ! V_72 )
goto V_76;
V_60 = F_60 ( sizeof( struct V_59 ) , V_42 ) ;
if ( V_60 ) {
* V_60 = V_79 ;
F_54 ( V_60 , & V_50 ) ;
}
F_25 ( V_72 [ 0 ] , V_50 . V_31 ,
V_73 ) ;
goto V_76;
}
V_67 = F_60 ( F_61 () * sizeof( V_63 ) , V_42 ) ;
if ( ! V_67 )
goto V_76;
V_68 = 0 ;
F_44 () ;
F_55 (cp, pos_css, &top_cpuset) {
if ( V_63 == & V_50 )
continue;
if ( ! F_48 ( V_63 -> V_39 ) &&
! ( F_13 ( V_63 ) &&
F_22 ( V_63 -> V_39 , V_73 ) ) )
continue;
if ( F_13 ( V_63 ) )
V_67 [ V_68 ++ ] = V_63 ;
V_64 = F_56 ( V_64 ) ;
}
F_51 () ;
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
if ( V_82 != V_83 && F_52 ( V_57 , V_58 ) ) {
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
V_72 = F_59 ( V_74 ) ;
if ( ! V_72 )
goto V_76;
V_60 = F_60 ( V_74 * sizeof( struct V_59 ) , V_42 ) ;
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
F_62 ( L_4 ,
V_75 , V_74 , V_68 , V_69 , V_82 ) ;
V_85 -- ;
}
continue;
}
F_63 ( V_84 ) ;
if ( V_60 )
* ( V_60 + V_75 ) = V_79 ;
for ( V_70 = V_69 ; V_70 < V_68 ; V_70 ++ ) {
struct V_1 * V_58 = V_67 [ V_70 ] ;
if ( V_82 == V_58 -> V_80 ) {
F_64 ( V_84 , V_84 , V_58 -> V_31 ) ;
F_25 ( V_84 , V_84 , V_73 ) ;
if ( V_60 )
F_54 ( V_60 + V_75 , V_58 ) ;
V_58 -> V_80 = - 1 ;
}
}
V_75 ++ ;
}
F_65 ( V_75 != V_74 ) ;
V_76:
F_40 ( V_73 ) ;
F_41 ( V_67 ) ;
if ( V_72 == NULL )
V_74 = 1 ;
* V_65 = V_72 ;
* V_66 = V_60 ;
return V_74 ;
}
static void F_66 ( void )
{
struct V_59 * V_86 ;
T_2 * V_72 ;
int V_74 ;
F_67 ( & V_87 ) ;
F_68 () ;
if ( ! F_69 ( V_50 . V_31 , V_88 ) )
goto V_49;
V_74 = F_57 ( & V_72 , & V_86 ) ;
F_70 ( V_74 , V_72 , V_86 ) ;
V_49:
F_71 () ;
}
static void F_66 ( void )
{
}
void F_72 ( void )
{
F_73 ( & V_87 ) ;
F_66 () ;
F_74 ( & V_87 ) ;
}
static void F_75 ( struct V_1 * V_7 )
{
struct V_89 V_90 ;
struct V_4 * V_5 ;
F_76 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_77 ( & V_90 ) ) )
F_78 ( V_5 , V_7 -> V_31 ) ;
F_79 ( & V_90 ) ;
}
static void F_80 ( struct V_1 * V_7 , struct V_29 * V_91 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
bool V_92 = false ;
F_44 () ;
F_55 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_63 ) ;
F_25 ( V_91 , V_63 -> V_39 , V_8 -> V_31 ) ;
if ( F_46 ( V_52 ) &&
F_48 ( V_91 ) )
F_24 ( V_91 , V_8 -> V_31 ) ;
if ( F_69 ( V_91 , V_63 -> V_31 ) ) {
V_64 = F_56 ( V_64 ) ;
continue;
}
if ( ! F_81 ( & V_63 -> V_3 ) )
continue;
F_51 () ;
F_82 ( & V_93 ) ;
F_24 ( V_63 -> V_31 , V_91 ) ;
F_83 ( & V_93 ) ;
F_84 ( ! F_46 ( V_52 ) &&
! F_69 ( V_63 -> V_39 , V_63 -> V_31 ) ) ;
F_75 ( V_63 ) ;
if ( ! F_48 ( V_63 -> V_39 ) &&
F_13 ( V_63 ) )
V_92 = true ;
F_44 () ;
F_85 ( & V_63 -> V_3 ) ;
}
F_51 () ;
if ( V_92 )
F_66 () ;
}
static int F_86 ( struct V_1 * V_7 , struct V_1 * V_94 ,
const char * V_95 )
{
int V_96 ;
if ( V_7 == & V_50 )
return - V_51 ;
if ( ! * V_95 ) {
F_63 ( V_94 -> V_39 ) ;
} else {
V_96 = F_87 ( V_95 , V_94 -> V_39 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! F_35 ( V_94 -> V_39 ,
V_50 . V_39 ) )
return - V_53 ;
}
if ( F_69 ( V_7 -> V_39 , V_94 -> V_39 ) )
return 0 ;
V_96 = F_43 ( V_7 , V_94 ) ;
if ( V_96 < 0 )
return V_96 ;
F_82 ( & V_93 ) ;
F_24 ( V_7 -> V_39 , V_94 -> V_39 ) ;
F_83 ( & V_93 ) ;
F_80 ( V_7 , V_94 -> V_39 ) ;
return 0 ;
}
static void F_88 ( struct V_97 * V_98 )
{
struct V_99 * V_100 =
F_2 ( V_98 , struct V_99 , V_98 ) ;
F_89 ( V_100 -> V_101 , & V_100 -> V_102 , & V_100 -> V_103 , V_104 ) ;
F_90 ( V_100 -> V_101 ) ;
F_41 ( V_100 ) ;
}
static void F_91 ( struct V_105 * V_101 , const T_1 * V_102 ,
const T_1 * V_103 )
{
struct V_99 * V_100 ;
V_100 = F_92 ( sizeof( * V_100 ) , V_42 ) ;
if ( V_100 ) {
V_100 -> V_101 = V_101 ;
V_100 -> V_102 = * V_102 ;
V_100 -> V_103 = * V_103 ;
F_93 ( & V_100 -> V_98 , F_88 ) ;
F_94 ( V_106 , & V_100 -> V_98 ) ;
} else {
F_90 ( V_101 ) ;
}
}
static void F_95 ( void )
{
F_96 ( V_106 ) ;
}
static void F_97 ( struct V_4 * V_36 ,
T_1 * V_107 )
{
F_98 ( V_36 ) ;
F_99 () ;
F_100 ( & V_36 -> V_108 ) ;
F_101 ( V_36 -> V_40 , V_36 -> V_40 , * V_107 ) ;
F_102 ( V_36 , V_107 ) ;
V_36 -> V_40 = * V_107 ;
F_103 ( & V_36 -> V_108 ) ;
F_104 () ;
F_105 ( V_36 ) ;
}
static void F_106 ( struct V_1 * V_7 )
{
static T_1 V_107 ;
struct V_89 V_90 ;
struct V_4 * V_5 ;
V_109 = V_7 ;
F_26 ( V_7 , & V_107 ) ;
F_76 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_77 ( & V_90 ) ) ) {
struct V_105 * V_101 ;
bool V_110 ;
F_97 ( V_5 , & V_107 ) ;
V_101 = F_107 ( V_5 ) ;
if ( ! V_101 )
continue;
V_110 = F_14 ( V_7 ) ;
F_108 ( V_101 , & V_7 -> V_40 ) ;
if ( V_110 )
F_91 ( V_101 , & V_7 -> V_111 , & V_107 ) ;
else
F_90 ( V_101 ) ;
}
F_79 ( & V_90 ) ;
V_7 -> V_111 = V_107 ;
V_109 = NULL ;
}
static void F_109 ( struct V_1 * V_7 , T_1 * V_112 )
{
struct V_1 * V_63 ;
struct V_2 * V_64 ;
F_44 () ;
F_55 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_63 ) ;
F_28 ( * V_112 , V_63 -> V_40 , V_8 -> V_33 ) ;
if ( F_46 ( V_52 ) &&
F_49 ( * V_112 ) )
* V_112 = V_8 -> V_33 ;
if ( F_110 ( * V_112 , V_63 -> V_33 ) ) {
V_64 = F_56 ( V_64 ) ;
continue;
}
if ( ! F_81 ( & V_63 -> V_3 ) )
continue;
F_51 () ;
F_82 ( & V_93 ) ;
V_63 -> V_33 = * V_112 ;
F_83 ( & V_93 ) ;
F_84 ( ! F_46 ( V_52 ) &&
! F_110 ( V_63 -> V_40 , V_63 -> V_33 ) ) ;
F_106 ( V_63 ) ;
F_44 () ;
F_85 ( & V_63 -> V_3 ) ;
}
F_51 () ;
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
if ( ! F_36 ( V_94 -> V_40 ,
V_50 . V_40 ) ) {
V_96 = - V_53 ;
goto V_76;
}
}
if ( F_110 ( V_7 -> V_40 , V_94 -> V_40 ) ) {
V_96 = 0 ;
goto V_76;
}
V_96 = F_43 ( V_7 , V_94 ) ;
if ( V_96 < 0 )
goto V_76;
F_82 ( & V_93 ) ;
V_7 -> V_40 = V_94 -> V_40 ;
F_83 ( & V_93 ) ;
F_109 ( V_7 , & V_94 -> V_40 ) ;
V_76:
return V_96 ;
}
int F_114 ( void )
{
int V_25 ;
F_44 () ;
V_25 = F_3 ( V_113 ) == V_109 ;
F_51 () ;
return V_25 ;
}
static int F_115 ( struct V_1 * V_7 , T_3 V_114 )
{
#ifdef F_116
if ( V_114 < - 1 || V_114 >= V_115 )
return - V_53 ;
#endif
if ( V_114 != V_7 -> V_61 ) {
V_7 -> V_61 = V_114 ;
if ( ! F_48 ( V_7 -> V_39 ) &&
F_13 ( V_7 ) )
F_66 () ;
}
return 0 ;
}
static void F_117 ( struct V_1 * V_7 )
{
struct V_89 V_90 ;
struct V_4 * V_5 ;
F_76 ( & V_7 -> V_3 , & V_90 ) ;
while ( ( V_5 = F_77 ( & V_90 ) ) )
F_29 ( V_7 , V_5 ) ;
F_79 ( & V_90 ) ;
}
static int F_118 ( T_4 V_116 , struct V_1 * V_7 ,
int V_117 )
{
struct V_1 * V_94 ;
int V_118 ;
int V_119 ;
int V_120 ;
V_94 = F_37 ( V_7 ) ;
if ( ! V_94 )
return - V_121 ;
if ( V_117 )
F_119 ( V_116 , & V_94 -> V_11 ) ;
else
F_120 ( V_116 , & V_94 -> V_11 ) ;
V_120 = F_43 ( V_7 , V_94 ) ;
if ( V_120 < 0 )
goto V_49;
V_118 = ( F_13 ( V_7 ) !=
F_13 ( V_94 ) ) ;
V_119 = ( ( F_16 ( V_7 ) != F_16 ( V_94 ) )
|| ( F_15 ( V_7 ) != F_15 ( V_94 ) ) ) ;
F_82 ( & V_93 ) ;
V_7 -> V_11 = V_94 -> V_11 ;
F_83 ( & V_93 ) ;
if ( ! F_48 ( V_94 -> V_39 ) && V_118 )
F_66 () ;
if ( V_119 )
F_117 ( V_7 ) ;
V_49:
F_42 ( V_94 ) ;
return V_120 ;
}
static void F_121 ( struct V_122 * V_123 )
{
V_123 -> V_124 = 0 ;
V_123 -> V_114 = 0 ;
V_123 -> time = 0 ;
F_122 ( & V_123 -> V_125 ) ;
}
static void F_123 ( struct V_122 * V_123 )
{
T_5 V_126 ;
T_6 V_127 ;
V_126 = F_124 () ;
V_127 = V_126 - V_123 -> time ;
if ( V_127 == 0 )
return;
V_127 = F_125 ( V_128 , V_127 ) ;
while ( V_127 -- > 0 )
V_123 -> V_114 = ( V_129 * V_123 -> V_114 ) / V_130 ;
V_123 -> time = V_126 ;
V_123 -> V_114 += ( ( V_130 - V_129 ) * V_123 -> V_124 ) / V_130 ;
V_123 -> V_124 = 0 ;
}
static void F_126 ( struct V_122 * V_123 )
{
F_127 ( & V_123 -> V_125 ) ;
F_123 ( V_123 ) ;
V_123 -> V_124 = F_125 ( V_131 , V_123 -> V_124 + V_130 ) ;
F_128 ( & V_123 -> V_125 ) ;
}
static int F_129 ( struct V_122 * V_123 )
{
int V_114 ;
F_127 ( & V_123 -> V_125 ) ;
F_123 ( V_123 ) ;
V_114 = V_123 -> V_114 ;
F_128 ( & V_123 -> V_125 ) ;
return V_114 ;
}
static int F_130 ( struct V_132 * V_133 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
int V_25 ;
V_134 = F_3 ( F_131 ( V_133 , & V_3 ) ) ;
V_7 = F_1 ( V_3 ) ;
F_73 ( & V_87 ) ;
V_25 = - V_54 ;
if ( ! F_46 ( V_52 ) &&
( F_48 ( V_7 -> V_39 ) || F_49 ( V_7 -> V_40 ) ) )
goto V_135;
F_132 (task, css, tset) {
V_25 = F_133 ( V_5 , V_7 -> V_39 ) ;
if ( V_25 )
goto V_135;
V_25 = F_134 ( V_5 ) ;
if ( V_25 )
goto V_135;
}
V_7 -> V_56 ++ ;
V_25 = 0 ;
V_135:
F_74 ( & V_87 ) ;
return V_25 ;
}
static void F_135 ( struct V_132 * V_133 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
F_131 ( V_133 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_73 ( & V_87 ) ;
F_1 ( V_3 ) -> V_56 -- ;
F_74 ( & V_87 ) ;
}
static void F_136 ( struct V_132 * V_133 )
{
static T_1 V_136 ;
struct V_4 * V_5 ;
struct V_4 * V_137 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_1 * V_138 = V_134 ;
F_131 ( V_133 , & V_3 ) ;
V_7 = F_1 ( V_3 ) ;
F_73 ( & V_87 ) ;
if ( V_7 == & V_50 )
F_24 ( V_139 , V_77 ) ;
else
F_21 ( V_7 , V_139 ) ;
F_26 ( V_7 , & V_136 ) ;
F_132 (task, css, tset) {
F_137 ( F_78 ( V_5 , V_139 ) ) ;
F_97 ( V_5 , & V_136 ) ;
F_29 ( V_7 , V_5 ) ;
}
V_136 = V_7 -> V_33 ;
F_138 (leader, css, tset) {
struct V_105 * V_101 = F_107 ( V_137 ) ;
if ( V_101 ) {
F_108 ( V_101 , & V_136 ) ;
if ( F_14 ( V_7 ) )
F_91 ( V_101 , & V_138 -> V_111 ,
& V_136 ) ;
else
F_90 ( V_101 ) ;
}
}
V_7 -> V_111 = V_136 ;
V_7 -> V_56 -- ;
if ( ! V_7 -> V_56 )
F_139 ( & V_140 ) ;
F_74 ( & V_87 ) ;
}
static int F_140 ( struct V_2 * V_3 , struct V_141 * V_142 ,
T_7 V_114 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_142 -> V_143 ;
int V_96 = 0 ;
F_73 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) ) {
V_96 = - V_26 ;
goto V_135;
}
switch ( type ) {
case V_144 :
V_96 = F_118 ( V_12 , V_7 , V_114 ) ;
break;
case V_145 :
V_96 = F_118 ( V_13 , V_7 , V_114 ) ;
break;
case V_146 :
V_96 = F_118 ( V_14 , V_7 , V_114 ) ;
break;
case V_147 :
V_96 = F_118 ( V_15 , V_7 , V_114 ) ;
break;
case V_148 :
V_96 = F_118 ( V_16 , V_7 , V_114 ) ;
break;
case V_149 :
V_150 = ! ! V_114 ;
break;
case V_151 :
V_96 = F_118 ( V_17 , V_7 , V_114 ) ;
break;
case V_152 :
V_96 = F_118 ( V_18 , V_7 , V_114 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
V_135:
F_74 ( & V_87 ) ;
return V_96 ;
}
static int F_141 ( struct V_2 * V_3 , struct V_141 * V_142 ,
T_3 V_114 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_142 -> V_143 ;
int V_96 = - V_26 ;
F_73 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) )
goto V_135;
switch ( type ) {
case V_153 :
V_96 = F_115 ( V_7 , V_114 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
V_135:
F_74 ( & V_87 ) ;
return V_96 ;
}
static T_9 F_142 ( struct V_154 * V_155 ,
char * V_95 , T_10 V_156 , T_11 V_157 )
{
struct V_1 * V_7 = F_1 ( F_143 ( V_155 ) ) ;
struct V_1 * V_94 ;
int V_96 = - V_26 ;
V_95 = F_144 ( V_95 ) ;
F_145 ( & V_7 -> V_3 ) ;
F_146 ( V_155 -> V_158 ) ;
F_147 ( & V_159 ) ;
F_73 ( & V_87 ) ;
if ( ! F_7 ( V_7 ) )
goto V_135;
V_94 = F_37 ( V_7 ) ;
if ( ! V_94 ) {
V_96 = - V_121 ;
goto V_135;
}
switch ( F_148 ( V_155 ) -> V_143 ) {
case V_160 :
V_96 = F_86 ( V_7 , V_94 , V_95 ) ;
break;
case V_161 :
V_96 = F_111 ( V_7 , V_94 , V_95 ) ;
break;
default:
V_96 = - V_53 ;
break;
}
F_42 ( V_94 ) ;
V_135:
F_74 ( & V_87 ) ;
F_149 ( V_155 -> V_158 ) ;
F_85 ( & V_7 -> V_3 ) ;
F_96 ( V_106 ) ;
return V_96 ? : V_156 ;
}
static int F_150 ( struct V_162 * V_163 , void * V_164 )
{
struct V_1 * V_7 = F_1 ( F_151 ( V_163 ) ) ;
T_8 type = F_152 ( V_163 ) -> V_143 ;
int V_25 = 0 ;
F_82 ( & V_93 ) ;
switch ( type ) {
case V_160 :
F_153 ( V_163 , L_5 , F_154 ( V_7 -> V_39 ) ) ;
break;
case V_161 :
F_153 ( V_163 , L_5 , F_155 ( & V_7 -> V_40 ) ) ;
break;
case V_165 :
F_153 ( V_163 , L_5 , F_154 ( V_7 -> V_31 ) ) ;
break;
case V_166 :
F_153 ( V_163 , L_5 , F_155 ( & V_7 -> V_33 ) ) ;
break;
default:
V_25 = - V_53 ;
}
F_83 ( & V_93 ) ;
return V_25 ;
}
static T_7 F_156 ( struct V_2 * V_3 , struct V_141 * V_142 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_142 -> V_143 ;
switch ( type ) {
case V_144 :
return F_10 ( V_7 ) ;
case V_145 :
return F_11 ( V_7 ) ;
case V_146 :
return F_12 ( V_7 ) ;
case V_147 :
return F_13 ( V_7 ) ;
case V_148 :
return F_14 ( V_7 ) ;
case V_149 :
return V_150 ;
case V_167 :
return F_129 ( & V_7 -> V_122 ) ;
case V_151 :
return F_15 ( V_7 ) ;
case V_152 :
return F_16 ( V_7 ) ;
default:
F_157 () ;
}
return 0 ;
}
static T_3 F_158 ( struct V_2 * V_3 , struct V_141 * V_142 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_8 type = V_142 -> V_143 ;
switch ( type ) {
case V_153 :
return V_7 -> V_61 ;
default:
F_157 () ;
}
return 0 ;
}
static struct V_2 *
F_159 ( struct V_2 * V_168 )
{
struct V_1 * V_7 ;
if ( ! V_168 )
return & V_50 . V_3 ;
V_7 = F_92 ( sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 )
return F_19 ( - V_121 ) ;
if ( ! F_39 ( & V_7 -> V_39 , V_42 ) )
goto V_43;
if ( ! F_39 ( & V_7 -> V_31 , V_42 ) )
goto V_44;
F_119 ( V_15 , & V_7 -> V_11 ) ;
F_63 ( V_7 -> V_39 ) ;
F_112 ( V_7 -> V_40 ) ;
F_63 ( V_7 -> V_31 ) ;
F_112 ( V_7 -> V_33 ) ;
F_121 ( & V_7 -> V_122 ) ;
V_7 -> V_61 = - 1 ;
return & V_7 -> V_3 ;
V_44:
F_40 ( V_7 -> V_39 ) ;
V_43:
F_41 ( V_7 ) ;
return F_19 ( - V_121 ) ;
}
static int F_160 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_8 = F_5 ( V_7 ) ;
struct V_1 * V_169 ;
struct V_2 * V_64 ;
if ( ! V_8 )
return 0 ;
F_73 ( & V_87 ) ;
F_119 ( V_10 , & V_7 -> V_11 ) ;
if ( F_15 ( V_8 ) )
F_119 ( V_17 , & V_7 -> V_11 ) ;
if ( F_16 ( V_8 ) )
F_119 ( V_18 , & V_7 -> V_11 ) ;
F_161 () ;
F_82 ( & V_93 ) ;
if ( F_46 ( V_52 ) ) {
F_24 ( V_7 -> V_31 , V_8 -> V_31 ) ;
V_7 -> V_33 = V_8 -> V_33 ;
}
F_83 ( & V_93 ) ;
if ( ! F_8 ( V_170 , & V_3 -> V_55 -> V_11 ) )
goto V_135;
F_44 () ;
F_45 (tmp_cs, pos_css, parent) {
if ( F_11 ( V_169 ) || F_10 ( V_169 ) ) {
F_51 () ;
goto V_135;
}
}
F_51 () ;
F_82 ( & V_93 ) ;
V_7 -> V_40 = V_8 -> V_40 ;
V_7 -> V_33 = V_8 -> V_40 ;
F_24 ( V_7 -> V_39 , V_8 -> V_39 ) ;
F_24 ( V_7 -> V_31 , V_8 -> V_39 ) ;
F_83 ( & V_93 ) ;
V_135:
F_74 ( & V_87 ) ;
return 0 ;
}
static void F_162 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_73 ( & V_87 ) ;
if ( F_13 ( V_7 ) )
F_118 ( V_15 , V_7 , 0 ) ;
F_163 () ;
F_120 ( V_10 , & V_7 -> V_11 ) ;
F_74 ( & V_87 ) ;
}
static void F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_40 ( V_7 -> V_31 ) ;
F_40 ( V_7 -> V_39 ) ;
F_41 ( V_7 ) ;
}
static void F_165 ( struct V_2 * V_171 )
{
F_73 ( & V_87 ) ;
F_82 ( & V_93 ) ;
if ( F_46 ( V_52 ) ) {
F_24 ( V_50 . V_39 , V_77 ) ;
V_50 . V_40 = V_172 ;
} else {
F_24 ( V_50 . V_39 ,
V_50 . V_31 ) ;
V_50 . V_40 = V_50 . V_33 ;
}
F_83 ( & V_93 ) ;
F_74 ( & V_87 ) ;
}
static void F_166 ( struct V_4 * V_5 )
{
if ( F_167 ( V_5 , V_6 ) )
return;
F_78 ( V_5 , & V_113 -> V_39 ) ;
V_5 -> V_40 = V_113 -> V_40 ;
}
int T_12 F_168 ( void )
{
int V_120 = 0 ;
F_65 ( ! F_39 ( & V_50 . V_39 , V_42 ) ) ;
F_65 ( ! F_39 ( & V_50 . V_31 , V_42 ) ) ;
F_169 ( V_50 . V_39 ) ;
F_170 ( V_50 . V_40 ) ;
F_169 ( V_50 . V_31 ) ;
F_170 ( V_50 . V_33 ) ;
F_121 ( & V_50 . V_122 ) ;
F_119 ( V_15 , & V_50 . V_11 ) ;
V_50 . V_61 = - 1 ;
V_120 = F_171 ( & V_173 ) ;
if ( V_120 < 0 )
return V_120 ;
F_65 ( ! F_39 ( & V_139 , V_42 ) ) ;
return 0 ;
}
static void F_172 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_5 ( V_7 ) ;
while ( F_48 ( V_8 -> V_39 ) ||
F_49 ( V_8 -> V_40 ) )
V_8 = F_5 ( V_8 ) ;
if ( F_173 ( V_8 -> V_3 . V_55 , V_7 -> V_3 . V_55 ) ) {
F_174 ( L_6 ) ;
F_175 ( V_7 -> V_3 . V_55 ) ;
F_176 ( L_7 ) ;
}
}
static void
F_177 ( struct V_1 * V_7 ,
struct V_29 * V_91 , T_1 * V_112 ,
bool V_174 , bool V_175 )
{
bool V_176 ;
F_82 ( & V_93 ) ;
F_24 ( V_7 -> V_39 , V_91 ) ;
F_24 ( V_7 -> V_31 , V_91 ) ;
V_7 -> V_40 = * V_112 ;
V_7 -> V_33 = * V_112 ;
F_83 ( & V_93 ) ;
if ( V_174 && ! F_48 ( V_7 -> V_39 ) )
F_75 ( V_7 ) ;
if ( V_175 && ! F_49 ( V_7 -> V_40 ) )
F_106 ( V_7 ) ;
V_176 = F_48 ( V_7 -> V_39 ) ||
F_49 ( V_7 -> V_40 ) ;
F_74 ( & V_87 ) ;
if ( V_176 )
F_172 ( V_7 ) ;
F_73 ( & V_87 ) ;
}
static void
F_178 ( struct V_1 * V_7 ,
struct V_29 * V_91 , T_1 * V_112 ,
bool V_174 , bool V_175 )
{
if ( F_48 ( V_91 ) )
F_24 ( V_91 , F_5 ( V_7 ) -> V_31 ) ;
if ( F_49 ( * V_112 ) )
* V_112 = F_5 ( V_7 ) -> V_33 ;
F_82 ( & V_93 ) ;
F_24 ( V_7 -> V_31 , V_91 ) ;
V_7 -> V_33 = * V_112 ;
F_83 ( & V_93 ) ;
if ( V_174 )
F_75 ( V_7 ) ;
if ( V_175 )
F_106 ( V_7 ) ;
}
static void F_179 ( struct V_1 * V_7 )
{
static T_13 V_91 ;
static T_1 V_112 ;
bool V_174 ;
bool V_175 ;
V_177:
F_180 ( V_140 , V_7 -> V_56 == 0 ) ;
F_73 ( & V_87 ) ;
if ( V_7 -> V_56 ) {
F_74 ( & V_87 ) ;
goto V_177;
}
F_25 ( & V_91 , V_7 -> V_39 , F_5 ( V_7 ) -> V_31 ) ;
F_28 ( V_112 , V_7 -> V_40 , F_5 ( V_7 ) -> V_33 ) ;
V_174 = ! F_69 ( & V_91 , V_7 -> V_31 ) ;
V_175 = ! F_110 ( V_112 , V_7 -> V_33 ) ;
if ( F_46 ( V_52 ) )
F_178 ( V_7 , & V_91 , & V_112 ,
V_174 , V_175 ) ;
else
F_177 ( V_7 , & V_91 , & V_112 ,
V_174 , V_175 ) ;
F_74 ( & V_87 ) ;
}
static void F_181 ( struct V_97 * V_98 )
{
static T_13 V_91 ;
static T_1 V_112 ;
bool V_174 , V_175 ;
bool V_178 = F_46 ( V_52 ) ;
F_73 ( & V_87 ) ;
F_24 ( & V_91 , V_88 ) ;
V_112 = V_34 [ V_35 ] ;
V_174 = ! F_69 ( V_50 . V_31 , & V_91 ) ;
V_175 = ! F_110 ( V_50 . V_33 , V_112 ) ;
if ( V_174 ) {
F_82 ( & V_93 ) ;
if ( ! V_178 )
F_24 ( V_50 . V_39 , & V_91 ) ;
F_24 ( V_50 . V_31 , & V_91 ) ;
F_83 ( & V_93 ) ;
}
if ( V_175 ) {
F_82 ( & V_93 ) ;
if ( ! V_178 )
V_50 . V_40 = V_112 ;
V_50 . V_33 = V_112 ;
F_83 ( & V_93 ) ;
F_106 ( & V_50 ) ;
}
F_74 ( & V_87 ) ;
if ( V_174 || V_175 ) {
struct V_1 * V_7 ;
struct V_2 * V_64 ;
F_44 () ;
F_55 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_50 || ! F_81 ( & V_7 -> V_3 ) )
continue;
F_51 () ;
F_179 ( V_7 ) ;
F_44 () ;
F_85 ( & V_7 -> V_3 ) ;
}
F_51 () ;
}
if ( V_174 )
F_72 () ;
}
void F_182 ( void )
{
F_70 ( 1 , NULL , NULL ) ;
F_183 ( & V_159 ) ;
}
static int F_184 ( struct V_179 * V_180 ,
unsigned long V_181 , void * V_182 )
{
F_183 ( & V_159 ) ;
return V_183 ;
}
void T_12 F_185 ( void )
{
F_24 ( V_50 . V_39 , V_88 ) ;
V_50 . V_40 = V_34 [ V_35 ] ;
V_50 . V_111 = V_50 . V_40 ;
F_24 ( V_50 . V_31 , V_88 ) ;
V_50 . V_33 = V_34 [ V_35 ] ;
F_186 ( & V_184 ) ;
V_106 = F_187 ( L_8 , 0 ) ;
F_65 ( ! V_106 ) ;
}
void F_188 ( struct V_4 * V_36 , struct V_29 * V_30 )
{
unsigned long V_11 ;
F_189 ( & V_93 , V_11 ) ;
F_44 () ;
F_21 ( F_3 ( V_36 ) , V_30 ) ;
F_51 () ;
F_190 ( & V_93 , V_11 ) ;
}
void F_191 ( struct V_4 * V_36 )
{
F_44 () ;
F_192 ( V_36 , F_3 ( V_36 ) -> V_31 ) ;
F_51 () ;
}
void T_12 F_193 ( void )
{
F_170 ( V_113 -> V_40 ) ;
}
T_1 F_194 ( struct V_4 * V_36 )
{
T_1 V_185 ;
unsigned long V_11 ;
F_189 ( & V_93 , V_11 ) ;
F_44 () ;
F_26 ( F_3 ( V_36 ) , & V_185 ) ;
F_51 () ;
F_190 ( & V_93 , V_11 ) ;
return V_185 ;
}
int F_195 ( T_1 * V_186 )
{
return F_27 ( * V_186 , V_113 -> V_40 ) ;
}
static struct V_1 * F_196 ( struct V_1 * V_7 )
{
while ( ! ( F_11 ( V_7 ) || F_12 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
bool F_197 ( int V_187 , T_14 V_188 )
{
struct V_1 * V_7 ;
int V_189 ;
unsigned long V_11 ;
if ( F_198 () )
return true ;
if ( F_199 ( V_187 , V_113 -> V_40 ) )
return true ;
if ( F_23 ( F_200 ( V_190 ) ) )
return true ;
if ( V_188 & V_191 )
return false ;
if ( V_113 -> V_11 & V_192 )
return true ;
F_189 ( & V_93 , V_11 ) ;
F_44 () ;
V_7 = F_196 ( F_3 ( V_113 ) ) ;
V_189 = F_199 ( V_187 , V_7 -> V_40 ) ;
F_51 () ;
F_190 ( & V_93 , V_11 ) ;
return V_189 ;
}
static int F_201 ( int * V_193 )
{
return * V_193 = F_202 ( * V_193 , V_113 -> V_40 ) ;
}
int F_203 ( void )
{
if ( V_113 -> V_194 == V_195 )
V_113 -> V_194 =
F_204 ( & V_113 -> V_40 ) ;
return F_201 ( & V_113 -> V_194 ) ;
}
int F_205 ( void )
{
if ( V_113 -> V_196 == V_195 )
V_113 -> V_196 =
F_204 ( & V_113 -> V_40 ) ;
return F_201 ( & V_113 -> V_196 ) ;
}
int F_206 ( const struct V_4 * V_197 ,
const struct V_4 * V_198 )
{
return F_27 ( V_197 -> V_40 , V_198 -> V_40 ) ;
}
void F_207 ( void )
{
struct V_55 * V_199 ;
F_44 () ;
V_199 = F_3 ( V_113 ) -> V_3 . V_55 ;
F_208 ( L_9 , V_113 -> V_200 ) ;
F_175 ( V_199 ) ;
F_176 ( L_10 ,
F_155 ( & V_113 -> V_40 ) ) ;
F_51 () ;
}
void F_209 ( void )
{
F_44 () ;
F_126 ( & F_3 ( V_113 ) -> V_122 ) ;
F_51 () ;
}
int F_210 ( struct V_162 * V_201 , struct V_202 * V_203 ,
struct V_204 * V_204 , struct V_4 * V_36 )
{
char * V_95 ;
struct V_2 * V_3 ;
int V_96 ;
V_96 = - V_121 ;
V_95 = F_60 ( V_205 , V_42 ) ;
if ( ! V_95 )
goto V_49;
V_3 = F_211 ( V_36 , V_6 ) ;
V_96 = F_212 ( V_3 -> V_55 , V_95 , V_205 ,
V_113 -> V_206 -> V_207 ) ;
F_85 ( V_3 ) ;
if ( V_96 >= V_205 )
V_96 = - V_208 ;
if ( V_96 < 0 )
goto V_209;
F_213 ( V_201 , V_95 ) ;
F_214 ( V_201 , '\n' ) ;
V_96 = 0 ;
V_209:
F_41 ( V_95 ) ;
V_49:
return V_96 ;
}
void F_215 ( struct V_162 * V_201 , struct V_4 * V_5 )
{
F_153 ( V_201 , L_11 ,
F_155 ( & V_5 -> V_40 ) ) ;
F_153 ( V_201 , L_12 ,
F_155 ( & V_5 -> V_40 ) ) ;
}
