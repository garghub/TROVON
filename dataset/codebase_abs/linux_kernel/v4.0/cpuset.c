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
struct V_58 * V_59 ;
int V_72 = 0 ;
int V_73 ;
struct V_2 * V_63 ;
V_71 = NULL ;
V_59 = NULL ;
V_66 = NULL ;
if ( F_12 ( & V_50 ) ) {
V_72 = 1 ;
V_71 = F_56 ( V_72 ) ;
if ( ! V_71 )
goto V_74;
V_59 = F_57 ( sizeof( struct V_58 ) , V_42 ) ;
if ( V_59 ) {
* V_59 = V_75 ;
F_52 ( V_59 , & V_50 ) ;
}
F_37 ( V_71 [ 0 ] , V_50 . V_31 ) ;
goto V_74;
}
V_66 = F_57 ( F_58 () * sizeof( V_62 ) , V_42 ) ;
if ( ! V_66 )
goto V_74;
V_67 = 0 ;
F_42 () ;
F_53 (cp, pos_css, &top_cpuset) {
if ( V_62 == & V_50 )
continue;
if ( ! F_46 ( V_62 -> V_39 ) &&
! F_12 ( V_62 ) )
continue;
if ( F_12 ( V_62 ) )
V_66 [ V_67 ++ ] = V_62 ;
V_63 = F_54 ( V_63 ) ;
}
F_49 () ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ )
V_66 [ V_68 ] -> V_76 = V_68 ;
V_72 = V_67 ;
V_77:
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
struct V_1 * V_56 = V_66 [ V_68 ] ;
int V_78 = V_56 -> V_76 ;
for ( V_69 = 0 ; V_69 < V_67 ; V_69 ++ ) {
struct V_1 * V_57 = V_66 [ V_69 ] ;
int V_79 = V_57 -> V_76 ;
if ( V_78 != V_79 && F_50 ( V_56 , V_57 ) ) {
for ( V_70 = 0 ; V_70 < V_67 ; V_70 ++ ) {
struct V_1 * V_46 = V_66 [ V_70 ] ;
if ( V_46 -> V_76 == V_79 )
V_46 -> V_76 = V_78 ;
}
V_72 -- ;
goto V_77;
}
}
}
V_71 = F_56 ( V_72 ) ;
if ( ! V_71 )
goto V_74;
V_59 = F_57 ( V_72 * sizeof( struct V_58 ) , V_42 ) ;
for ( V_73 = 0 , V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
struct V_1 * V_56 = V_66 [ V_68 ] ;
struct V_29 * V_80 ;
int V_78 = V_56 -> V_76 ;
if ( V_78 < 0 ) {
continue;
}
V_80 = V_71 [ V_73 ] ;
if ( V_73 == V_72 ) {
static int V_81 = 10 ;
if ( V_81 ) {
F_59 ( L_4 ,
V_73 , V_72 , V_67 , V_68 , V_78 ) ;
V_81 -- ;
}
continue;
}
F_60 ( V_80 ) ;
if ( V_59 )
* ( V_59 + V_73 ) = V_75 ;
for ( V_69 = V_68 ; V_69 < V_67 ; V_69 ++ ) {
struct V_1 * V_57 = V_66 [ V_69 ] ;
if ( V_78 == V_57 -> V_76 ) {
F_61 ( V_80 , V_80 , V_57 -> V_31 ) ;
if ( V_59 )
F_52 ( V_59 + V_73 , V_57 ) ;
V_57 -> V_76 = - 1 ;
}
}
V_73 ++ ;
}
F_62 ( V_73 != V_72 ) ;
V_74:
F_39 ( V_66 ) ;
if ( V_71 == NULL )
V_72 = 1 ;
* V_64 = V_71 ;
* V_65 = V_59 ;
return V_72 ;
}
static void F_63 ( void )
{
struct V_58 * V_82 ;
T_2 * V_71 ;
int V_72 ;
F_64 ( & V_83 ) ;
F_65 () ;
if ( ! F_66 ( V_50 . V_31 , V_84 ) )
goto V_49;
V_72 = F_55 ( & V_71 , & V_82 ) ;
F_67 ( V_72 , V_71 , V_82 ) ;
V_49:
F_68 () ;
}
static void F_63 ( void )
{
}
void F_69 ( void )
{
F_70 ( & V_83 ) ;
F_63 () ;
F_71 ( & V_83 ) ;
}
static void F_72 ( struct V_1 * V_7 )
{
struct V_85 V_86 ;
struct V_4 * V_5 ;
F_73 ( & V_7 -> V_3 , & V_86 ) ;
while ( ( V_5 = F_74 ( & V_86 ) ) )
F_75 ( V_5 , V_7 -> V_31 ) ;
F_76 ( & V_86 ) ;
}
static void F_77 ( struct V_1 * V_7 , struct V_29 * V_87 )
{
struct V_1 * V_62 ;
struct V_2 * V_63 ;
bool V_88 = false ;
F_42 () ;
F_53 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_62 ) ;
F_22 ( V_87 , V_62 -> V_39 , V_8 -> V_31 ) ;
if ( F_44 ( V_62 -> V_3 . V_52 ) && F_46 ( V_87 ) )
F_37 ( V_87 , V_8 -> V_31 ) ;
if ( F_66 ( V_87 , V_62 -> V_31 ) ) {
V_63 = F_54 ( V_63 ) ;
continue;
}
if ( ! F_78 ( & V_62 -> V_3 ) )
continue;
F_49 () ;
F_79 ( & V_89 ) ;
F_37 ( V_62 -> V_31 , V_87 ) ;
F_80 ( & V_89 ) ;
F_81 ( ! F_44 ( V_62 -> V_3 . V_52 ) &&
! F_66 ( V_62 -> V_39 , V_62 -> V_31 ) ) ;
F_72 ( V_62 ) ;
if ( ! F_46 ( V_62 -> V_39 ) &&
F_12 ( V_62 ) )
V_88 = true ;
F_42 () ;
F_82 ( & V_62 -> V_3 ) ;
}
F_49 () ;
if ( V_88 )
F_63 () ;
}
static int F_83 ( struct V_1 * V_7 , struct V_1 * V_90 ,
const char * V_91 )
{
int V_92 ;
if ( V_7 == & V_50 )
return - V_51 ;
if ( ! * V_91 ) {
F_60 ( V_90 -> V_39 ) ;
} else {
V_92 = F_84 ( V_91 , V_90 -> V_39 ) ;
if ( V_92 < 0 )
return V_92 ;
if ( ! F_32 ( V_90 -> V_39 ,
V_50 . V_39 ) )
return - V_53 ;
}
if ( F_66 ( V_7 -> V_39 , V_90 -> V_39 ) )
return 0 ;
V_92 = F_41 ( V_7 , V_90 ) ;
if ( V_92 < 0 )
return V_92 ;
F_79 ( & V_89 ) ;
F_37 ( V_7 -> V_39 , V_90 -> V_39 ) ;
F_80 ( & V_89 ) ;
F_77 ( V_7 , V_90 -> V_39 ) ;
return 0 ;
}
static void F_85 ( struct V_93 * V_94 , const T_1 * V_95 ,
const T_1 * V_96 )
{
struct V_4 * V_36 = V_97 ;
V_36 -> V_40 = * V_96 ;
F_86 ( V_94 , V_95 , V_96 , V_98 ) ;
F_42 () ;
F_23 ( F_3 ( V_36 ) , & V_36 -> V_40 ) ;
F_49 () ;
}
static void F_87 ( struct V_4 * V_36 ,
T_1 * V_99 )
{
bool V_100 ;
if ( F_88 ( F_89 ( V_101 ) ) )
return;
if ( V_97 -> V_11 & V_102 )
return;
F_90 ( V_36 ) ;
V_100 = F_6 ( V_36 ) ||
! F_24 ( * V_99 , V_36 -> V_40 ) ;
if ( V_100 ) {
F_91 () ;
F_92 ( & V_36 -> V_103 ) ;
}
F_93 ( V_36 -> V_40 , V_36 -> V_40 , * V_99 ) ;
F_94 ( V_36 , V_99 , V_104 ) ;
F_94 ( V_36 , V_99 , V_105 ) ;
V_36 -> V_40 = * V_99 ;
if ( V_100 ) {
F_95 ( & V_36 -> V_103 ) ;
F_96 () ;
}
F_97 ( V_36 ) ;
}
static void F_98 ( struct V_1 * V_7 )
{
static T_1 V_99 ;
struct V_85 V_86 ;
struct V_4 * V_5 ;
V_106 = V_7 ;
F_23 ( V_7 , & V_99 ) ;
F_73 ( & V_7 -> V_3 , & V_86 ) ;
while ( ( V_5 = F_74 ( & V_86 ) ) ) {
struct V_93 * V_94 ;
bool V_107 ;
F_87 ( V_5 , & V_99 ) ;
V_94 = F_99 ( V_5 ) ;
if ( ! V_94 )
continue;
V_107 = F_13 ( V_7 ) ;
F_100 ( V_94 , & V_7 -> V_40 ) ;
if ( V_107 )
F_85 ( V_94 , & V_7 -> V_108 , & V_99 ) ;
F_101 ( V_94 ) ;
}
F_76 ( & V_86 ) ;
V_7 -> V_108 = V_99 ;
V_106 = NULL ;
}
static void F_102 ( struct V_1 * V_7 , T_1 * V_109 )
{
struct V_1 * V_62 ;
struct V_2 * V_63 ;
F_42 () ;
F_53 (cp, pos_css, cs) {
struct V_1 * V_8 = F_5 ( V_62 ) ;
F_25 ( * V_109 , V_62 -> V_40 , V_8 -> V_33 ) ;
if ( F_44 ( V_62 -> V_3 . V_52 ) && F_47 ( * V_109 ) )
* V_109 = V_8 -> V_33 ;
if ( F_103 ( * V_109 , V_62 -> V_33 ) ) {
V_63 = F_54 ( V_63 ) ;
continue;
}
if ( ! F_78 ( & V_62 -> V_3 ) )
continue;
F_49 () ;
F_79 ( & V_89 ) ;
V_62 -> V_33 = * V_109 ;
F_80 ( & V_89 ) ;
F_81 ( ! F_44 ( V_62 -> V_3 . V_52 ) &&
! F_103 ( V_62 -> V_40 , V_62 -> V_33 ) ) ;
F_98 ( V_62 ) ;
F_42 () ;
F_82 ( & V_62 -> V_3 ) ;
}
F_49 () ;
}
static int F_104 ( struct V_1 * V_7 , struct V_1 * V_90 ,
const char * V_91 )
{
int V_92 ;
if ( V_7 == & V_50 ) {
V_92 = - V_51 ;
goto V_74;
}
if ( ! * V_91 ) {
F_105 ( V_90 -> V_40 ) ;
} else {
V_92 = F_106 ( V_91 , V_90 -> V_40 ) ;
if ( V_92 < 0 )
goto V_74;
if ( ! F_33 ( V_90 -> V_40 ,
V_50 . V_40 ) ) {
V_92 = - V_53 ;
goto V_74;
}
}
if ( F_103 ( V_7 -> V_40 , V_90 -> V_40 ) ) {
V_92 = 0 ;
goto V_74;
}
V_92 = F_41 ( V_7 , V_90 ) ;
if ( V_92 < 0 )
goto V_74;
F_79 ( & V_89 ) ;
V_7 -> V_40 = V_90 -> V_40 ;
F_80 ( & V_89 ) ;
F_102 ( V_7 , & V_7 -> V_40 ) ;
V_74:
return V_92 ;
}
int F_107 ( void )
{
int V_25 ;
F_42 () ;
V_25 = F_3 ( V_97 ) == V_106 ;
F_49 () ;
return V_25 ;
}
static int F_108 ( struct V_1 * V_7 , T_3 V_110 )
{
#ifdef F_109
if ( V_110 < - 1 || V_110 >= V_111 )
return - V_53 ;
#endif
if ( V_110 != V_7 -> V_60 ) {
V_7 -> V_60 = V_110 ;
if ( ! F_46 ( V_7 -> V_39 ) &&
F_12 ( V_7 ) )
F_63 () ;
}
return 0 ;
}
static void F_110 ( struct V_1 * V_7 )
{
struct V_85 V_86 ;
struct V_4 * V_5 ;
F_73 ( & V_7 -> V_3 , & V_86 ) ;
while ( ( V_5 = F_74 ( & V_86 ) ) )
F_26 ( V_7 , V_5 ) ;
F_76 ( & V_86 ) ;
}
static int F_111 ( T_4 V_112 , struct V_1 * V_7 ,
int V_113 )
{
struct V_1 * V_90 ;
int V_114 ;
int V_115 ;
int V_116 ;
V_90 = F_34 ( V_7 ) ;
if ( ! V_90 )
return - V_117 ;
if ( V_113 )
F_112 ( V_112 , & V_90 -> V_11 ) ;
else
F_113 ( V_112 , & V_90 -> V_11 ) ;
V_116 = F_41 ( V_7 , V_90 ) ;
if ( V_116 < 0 )
goto V_49;
V_114 = ( F_12 ( V_7 ) !=
F_12 ( V_90 ) ) ;
V_115 = ( ( F_15 ( V_7 ) != F_15 ( V_90 ) )
|| ( F_14 ( V_7 ) != F_14 ( V_90 ) ) ) ;
F_79 ( & V_89 ) ;
V_7 -> V_11 = V_90 -> V_11 ;
F_80 ( & V_89 ) ;
if ( ! F_46 ( V_90 -> V_39 ) && V_114 )
F_63 () ;
if ( V_115 )
F_110 ( V_7 ) ;
V_49:
F_40 ( V_90 ) ;
return V_116 ;
}
static void F_114 ( struct V_118 * V_119 )
{
V_119 -> V_120 = 0 ;
V_119 -> V_110 = 0 ;
V_119 -> time = 0 ;
F_115 ( & V_119 -> V_121 ) ;
}
static void F_116 ( struct V_118 * V_119 )
{
T_5 V_122 = F_117 () ;
T_5 V_123 = V_122 - V_119 -> time ;
if ( V_123 == 0 )
return;
V_123 = F_118 ( V_124 , V_123 ) ;
while ( V_123 -- > 0 )
V_119 -> V_110 = ( V_125 * V_119 -> V_110 ) / V_126 ;
V_119 -> time = V_122 ;
V_119 -> V_110 += ( ( V_126 - V_125 ) * V_119 -> V_120 ) / V_126 ;
V_119 -> V_120 = 0 ;
}
static void F_119 ( struct V_118 * V_119 )
{
F_120 ( & V_119 -> V_121 ) ;
F_116 ( V_119 ) ;
V_119 -> V_120 = F_118 ( V_127 , V_119 -> V_120 + V_126 ) ;
F_121 ( & V_119 -> V_121 ) ;
}
static int F_122 ( struct V_118 * V_119 )
{
int V_110 ;
F_120 ( & V_119 -> V_121 ) ;
F_116 ( V_119 ) ;
V_110 = V_119 -> V_110 ;
F_121 ( & V_119 -> V_121 ) ;
return V_110 ;
}
static int F_123 ( struct V_2 * V_3 ,
struct V_128 * V_129 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_4 * V_5 ;
int V_25 ;
V_130 = F_3 ( F_124 ( V_129 ) ) ;
F_70 ( & V_83 ) ;
V_25 = - V_54 ;
if ( ! F_44 ( V_3 -> V_52 ) &&
( F_46 ( V_7 -> V_39 ) || F_47 ( V_7 -> V_40 ) ) )
goto V_131;
F_125 (task, tset) {
V_25 = F_126 ( V_5 , V_7 -> V_39 ) ;
if ( V_25 )
goto V_131;
V_25 = F_127 ( V_5 ) ;
if ( V_25 )
goto V_131;
}
V_7 -> V_55 ++ ;
V_25 = 0 ;
V_131:
F_71 ( & V_83 ) ;
return V_25 ;
}
static void F_128 ( struct V_2 * V_3 ,
struct V_128 * V_129 )
{
F_70 ( & V_83 ) ;
F_1 ( V_3 ) -> V_55 -- ;
F_71 ( & V_83 ) ;
}
static void F_129 ( struct V_2 * V_3 ,
struct V_128 * V_129 )
{
static T_1 V_132 ;
struct V_93 * V_94 ;
struct V_4 * V_5 ;
struct V_4 * V_133 = F_124 ( V_129 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_134 = V_130 ;
F_70 ( & V_83 ) ;
if ( V_7 == & V_50 )
F_37 ( V_135 , V_136 ) ;
else
F_20 ( V_7 , V_135 ) ;
F_23 ( V_7 , & V_132 ) ;
F_125 (task, tset) {
F_130 ( F_75 ( V_5 , V_135 ) ) ;
F_87 ( V_5 , & V_132 ) ;
F_26 ( V_7 , V_5 ) ;
}
V_132 = V_7 -> V_33 ;
V_94 = F_99 ( V_133 ) ;
if ( V_94 ) {
F_100 ( V_94 , & V_132 ) ;
if ( F_13 ( V_7 ) ) {
F_85 ( V_94 , & V_134 -> V_108 ,
& V_132 ) ;
}
F_101 ( V_94 ) ;
}
V_7 -> V_108 = V_132 ;
V_7 -> V_55 -- ;
if ( ! V_7 -> V_55 )
F_131 ( & V_137 ) ;
F_71 ( & V_83 ) ;
}
static int F_132 ( struct V_2 * V_3 , struct V_138 * V_139 ,
T_6 V_110 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_139 -> V_140 ;
int V_92 = 0 ;
F_70 ( & V_83 ) ;
if ( ! F_7 ( V_7 ) ) {
V_92 = - V_26 ;
goto V_131;
}
switch ( type ) {
case V_141 :
V_92 = F_111 ( V_12 , V_7 , V_110 ) ;
break;
case V_142 :
V_92 = F_111 ( V_13 , V_7 , V_110 ) ;
break;
case V_143 :
V_92 = F_111 ( V_14 , V_7 , V_110 ) ;
break;
case V_144 :
V_92 = F_111 ( V_15 , V_7 , V_110 ) ;
break;
case V_145 :
V_92 = F_111 ( V_16 , V_7 , V_110 ) ;
break;
case V_146 :
V_147 = ! ! V_110 ;
break;
case V_148 :
V_92 = - V_51 ;
break;
case V_149 :
V_92 = F_111 ( V_17 , V_7 , V_110 ) ;
break;
case V_150 :
V_92 = F_111 ( V_18 , V_7 , V_110 ) ;
break;
default:
V_92 = - V_53 ;
break;
}
V_131:
F_71 ( & V_83 ) ;
return V_92 ;
}
static int F_133 ( struct V_2 * V_3 , struct V_138 * V_139 ,
T_3 V_110 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_139 -> V_140 ;
int V_92 = - V_26 ;
F_70 ( & V_83 ) ;
if ( ! F_7 ( V_7 ) )
goto V_131;
switch ( type ) {
case V_151 :
V_92 = F_108 ( V_7 , V_110 ) ;
break;
default:
V_92 = - V_53 ;
break;
}
V_131:
F_71 ( & V_83 ) ;
return V_92 ;
}
static T_8 F_134 ( struct V_152 * V_153 ,
char * V_91 , T_9 V_154 , T_10 V_155 )
{
struct V_1 * V_7 = F_1 ( F_135 ( V_153 ) ) ;
struct V_1 * V_90 ;
int V_92 = - V_26 ;
V_91 = F_136 ( V_91 ) ;
F_137 ( & V_7 -> V_3 ) ;
F_138 ( V_153 -> V_156 ) ;
F_139 ( & V_157 ) ;
F_70 ( & V_83 ) ;
if ( ! F_7 ( V_7 ) )
goto V_131;
V_90 = F_34 ( V_7 ) ;
if ( ! V_90 ) {
V_92 = - V_117 ;
goto V_131;
}
switch ( F_140 ( V_153 ) -> V_140 ) {
case V_158 :
V_92 = F_83 ( V_7 , V_90 , V_91 ) ;
break;
case V_159 :
V_92 = F_104 ( V_7 , V_90 , V_91 ) ;
break;
default:
V_92 = - V_53 ;
break;
}
F_40 ( V_90 ) ;
V_131:
F_71 ( & V_83 ) ;
F_141 ( V_153 -> V_156 ) ;
F_82 ( & V_7 -> V_3 ) ;
return V_92 ? : V_154 ;
}
static int F_142 ( struct V_160 * V_161 , void * V_162 )
{
struct V_1 * V_7 = F_1 ( F_143 ( V_161 ) ) ;
T_7 type = F_144 ( V_161 ) -> V_140 ;
int V_25 = 0 ;
F_79 ( & V_89 ) ;
switch ( type ) {
case V_158 :
F_145 ( V_161 , L_5 , F_146 ( V_7 -> V_39 ) ) ;
break;
case V_159 :
F_145 ( V_161 , L_5 , F_147 ( & V_7 -> V_40 ) ) ;
break;
case V_163 :
F_145 ( V_161 , L_5 , F_146 ( V_7 -> V_31 ) ) ;
break;
case V_164 :
F_145 ( V_161 , L_5 , F_147 ( & V_7 -> V_33 ) ) ;
break;
default:
V_25 = - V_53 ;
}
F_80 ( & V_89 ) ;
return V_25 ;
}
static T_6 F_148 ( struct V_2 * V_3 , struct V_138 * V_139 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_139 -> V_140 ;
switch ( type ) {
case V_141 :
return F_9 ( V_7 ) ;
case V_142 :
return F_10 ( V_7 ) ;
case V_143 :
return F_11 ( V_7 ) ;
case V_144 :
return F_12 ( V_7 ) ;
case V_145 :
return F_13 ( V_7 ) ;
case V_146 :
return V_147 ;
case V_148 :
return F_122 ( & V_7 -> V_118 ) ;
case V_149 :
return F_14 ( V_7 ) ;
case V_150 :
return F_15 ( V_7 ) ;
default:
F_149 () ;
}
return 0 ;
}
static T_3 F_150 ( struct V_2 * V_3 , struct V_138 * V_139 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_7 type = V_139 -> V_140 ;
switch ( type ) {
case V_151 :
return V_7 -> V_60 ;
default:
F_149 () ;
}
return 0 ;
}
static struct V_2 *
F_151 ( struct V_2 * V_165 )
{
struct V_1 * V_7 ;
if ( ! V_165 )
return & V_50 . V_3 ;
V_7 = F_152 ( sizeof( * V_7 ) , V_42 ) ;
if ( ! V_7 )
return F_18 ( - V_117 ) ;
if ( ! F_36 ( & V_7 -> V_39 , V_42 ) )
goto V_43;
if ( ! F_36 ( & V_7 -> V_31 , V_42 ) )
goto V_44;
F_112 ( V_15 , & V_7 -> V_11 ) ;
F_60 ( V_7 -> V_39 ) ;
F_105 ( V_7 -> V_40 ) ;
F_60 ( V_7 -> V_31 ) ;
F_105 ( V_7 -> V_33 ) ;
F_114 ( & V_7 -> V_118 ) ;
V_7 -> V_60 = - 1 ;
return & V_7 -> V_3 ;
V_44:
F_38 ( V_7 -> V_39 ) ;
V_43:
F_39 ( V_7 ) ;
return F_18 ( - V_117 ) ;
}
static int F_153 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_1 * V_8 = F_5 ( V_7 ) ;
struct V_1 * V_166 ;
struct V_2 * V_63 ;
if ( ! V_8 )
return 0 ;
F_70 ( & V_83 ) ;
F_112 ( V_10 , & V_7 -> V_11 ) ;
if ( F_14 ( V_8 ) )
F_112 ( V_17 , & V_7 -> V_11 ) ;
if ( F_15 ( V_8 ) )
F_112 ( V_18 , & V_7 -> V_11 ) ;
F_154 () ;
F_79 ( & V_89 ) ;
if ( F_44 ( V_7 -> V_3 . V_52 ) ) {
F_37 ( V_7 -> V_31 , V_8 -> V_31 ) ;
V_7 -> V_33 = V_8 -> V_33 ;
}
F_80 ( & V_89 ) ;
if ( ! F_8 ( V_167 , & V_3 -> V_52 -> V_11 ) )
goto V_131;
F_42 () ;
F_43 (tmp_cs, pos_css, parent) {
if ( F_10 ( V_166 ) || F_9 ( V_166 ) ) {
F_49 () ;
goto V_131;
}
}
F_49 () ;
F_79 ( & V_89 ) ;
V_7 -> V_40 = V_8 -> V_40 ;
V_7 -> V_33 = V_8 -> V_40 ;
F_37 ( V_7 -> V_39 , V_8 -> V_39 ) ;
F_37 ( V_7 -> V_31 , V_8 -> V_39 ) ;
F_80 ( & V_89 ) ;
V_131:
F_71 ( & V_83 ) ;
return 0 ;
}
static void F_155 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_70 ( & V_83 ) ;
if ( F_12 ( V_7 ) )
F_111 ( V_15 , V_7 , 0 ) ;
F_156 () ;
F_113 ( V_10 , & V_7 -> V_11 ) ;
F_71 ( & V_83 ) ;
}
static void F_157 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_38 ( V_7 -> V_31 ) ;
F_38 ( V_7 -> V_39 ) ;
F_39 ( V_7 ) ;
}
static void F_158 ( struct V_2 * V_168 )
{
F_70 ( & V_83 ) ;
F_79 ( & V_89 ) ;
if ( F_44 ( V_168 -> V_52 ) ) {
F_37 ( V_50 . V_39 , V_136 ) ;
V_50 . V_40 = V_169 ;
} else {
F_37 ( V_50 . V_39 ,
V_50 . V_31 ) ;
V_50 . V_40 = V_50 . V_33 ;
}
F_80 ( & V_89 ) ;
F_71 ( & V_83 ) ;
}
int T_11 F_159 ( void )
{
int V_116 = 0 ;
if ( ! F_36 ( & V_50 . V_39 , V_42 ) )
F_149 () ;
if ( ! F_36 ( & V_50 . V_31 , V_42 ) )
F_149 () ;
F_160 ( V_50 . V_39 ) ;
F_161 ( V_50 . V_40 ) ;
F_160 ( V_50 . V_31 ) ;
F_161 ( V_50 . V_33 ) ;
F_114 ( & V_50 . V_118 ) ;
F_112 ( V_15 , & V_50 . V_11 ) ;
V_50 . V_60 = - 1 ;
V_116 = F_162 ( & V_170 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( ! F_36 ( & V_135 , V_42 ) )
F_149 () ;
return 0 ;
}
static void F_163 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_5 ( V_7 ) ;
while ( F_46 ( V_8 -> V_39 ) ||
F_47 ( V_8 -> V_40 ) )
V_8 = F_5 ( V_8 ) ;
if ( F_164 ( V_8 -> V_3 . V_52 , V_7 -> V_3 . V_52 ) ) {
F_165 ( L_6 ) ;
F_166 ( V_7 -> V_3 . V_52 ) ;
F_167 ( L_7 ) ;
}
}
static void
F_168 ( struct V_1 * V_7 ,
struct V_29 * V_87 , T_1 * V_109 ,
bool V_171 , bool V_172 )
{
bool V_173 ;
F_79 ( & V_89 ) ;
F_37 ( V_7 -> V_39 , V_87 ) ;
F_37 ( V_7 -> V_31 , V_87 ) ;
V_7 -> V_40 = * V_109 ;
V_7 -> V_33 = * V_109 ;
F_80 ( & V_89 ) ;
if ( V_171 && ! F_46 ( V_7 -> V_39 ) )
F_72 ( V_7 ) ;
if ( V_172 && ! F_47 ( V_7 -> V_40 ) )
F_98 ( V_7 ) ;
V_173 = F_46 ( V_7 -> V_39 ) ||
F_47 ( V_7 -> V_40 ) ;
F_71 ( & V_83 ) ;
if ( V_173 )
F_163 ( V_7 ) ;
F_70 ( & V_83 ) ;
}
static void
F_169 ( struct V_1 * V_7 ,
struct V_29 * V_87 , T_1 * V_109 ,
bool V_171 , bool V_172 )
{
if ( F_46 ( V_87 ) )
F_37 ( V_87 , F_5 ( V_7 ) -> V_31 ) ;
if ( F_47 ( * V_109 ) )
* V_109 = F_5 ( V_7 ) -> V_33 ;
F_79 ( & V_89 ) ;
F_37 ( V_7 -> V_31 , V_87 ) ;
V_7 -> V_33 = * V_109 ;
F_80 ( & V_89 ) ;
if ( V_171 )
F_72 ( V_7 ) ;
if ( V_172 )
F_98 ( V_7 ) ;
}
static void F_170 ( struct V_1 * V_7 )
{
static T_12 V_87 ;
static T_1 V_109 ;
bool V_171 ;
bool V_172 ;
V_174:
F_171 ( V_137 , V_7 -> V_55 == 0 ) ;
F_70 ( & V_83 ) ;
if ( V_7 -> V_55 ) {
F_71 ( & V_83 ) ;
goto V_174;
}
F_22 ( & V_87 , V_7 -> V_39 , F_5 ( V_7 ) -> V_31 ) ;
F_25 ( V_109 , V_7 -> V_40 , F_5 ( V_7 ) -> V_33 ) ;
V_171 = ! F_66 ( & V_87 , V_7 -> V_31 ) ;
V_172 = ! F_103 ( V_109 , V_7 -> V_33 ) ;
if ( F_44 ( V_7 -> V_3 . V_52 ) )
F_169 ( V_7 , & V_87 , & V_109 ,
V_171 , V_172 ) ;
else
F_168 ( V_7 , & V_87 , & V_109 ,
V_171 , V_172 ) ;
F_71 ( & V_83 ) ;
}
static void F_172 ( struct V_175 * V_176 )
{
static T_12 V_87 ;
static T_1 V_109 ;
bool V_171 , V_172 ;
bool V_177 = F_44 ( V_50 . V_3 . V_52 ) ;
F_70 ( & V_83 ) ;
F_37 ( & V_87 , V_84 ) ;
V_109 = V_34 [ V_35 ] ;
V_171 = ! F_66 ( V_50 . V_31 , & V_87 ) ;
V_172 = ! F_103 ( V_50 . V_33 , V_109 ) ;
if ( V_171 ) {
F_79 ( & V_89 ) ;
if ( ! V_177 )
F_37 ( V_50 . V_39 , & V_87 ) ;
F_37 ( V_50 . V_31 , & V_87 ) ;
F_80 ( & V_89 ) ;
}
if ( V_172 ) {
F_79 ( & V_89 ) ;
if ( ! V_177 )
V_50 . V_40 = V_109 ;
V_50 . V_33 = V_109 ;
F_80 ( & V_89 ) ;
F_98 ( & V_50 ) ;
}
F_71 ( & V_83 ) ;
if ( V_171 || V_172 ) {
struct V_1 * V_7 ;
struct V_2 * V_63 ;
F_42 () ;
F_53 (cs, pos_css, &top_cpuset) {
if ( V_7 == & V_50 || ! F_78 ( & V_7 -> V_3 ) )
continue;
F_49 () ;
F_170 ( V_7 ) ;
F_42 () ;
F_82 ( & V_7 -> V_3 ) ;
}
F_49 () ;
}
if ( V_171 )
F_69 () ;
}
void F_173 ( bool V_178 )
{
F_67 ( 1 , NULL , NULL ) ;
F_174 ( & V_157 ) ;
}
static int F_175 ( struct V_179 * V_180 ,
unsigned long V_181 , void * V_182 )
{
F_174 ( & V_157 ) ;
return V_183 ;
}
void T_11 F_176 ( void )
{
F_37 ( V_50 . V_39 , V_84 ) ;
V_50 . V_40 = V_34 [ V_35 ] ;
V_50 . V_108 = V_50 . V_40 ;
F_37 ( V_50 . V_31 , V_84 ) ;
V_50 . V_33 = V_34 [ V_35 ] ;
F_177 ( & V_184 ) ;
}
void F_178 ( struct V_4 * V_36 , struct V_29 * V_30 )
{
unsigned long V_11 ;
F_179 ( & V_89 , V_11 ) ;
F_42 () ;
F_20 ( F_3 ( V_36 ) , V_30 ) ;
F_49 () ;
F_180 ( & V_89 , V_11 ) ;
}
void F_181 ( struct V_4 * V_36 )
{
F_42 () ;
F_182 ( V_36 , F_3 ( V_36 ) -> V_31 ) ;
F_49 () ;
}
void T_11 F_183 ( void )
{
F_161 ( V_97 -> V_40 ) ;
}
T_1 F_184 ( struct V_4 * V_36 )
{
T_1 V_185 ;
unsigned long V_11 ;
F_179 ( & V_89 , V_11 ) ;
F_42 () ;
F_23 ( F_3 ( V_36 ) , & V_185 ) ;
F_49 () ;
F_180 ( & V_89 , V_11 ) ;
return V_185 ;
}
int F_185 ( T_1 * V_186 )
{
return F_24 ( * V_186 , V_97 -> V_40 ) ;
}
static struct V_1 * F_186 ( struct V_1 * V_7 )
{
while ( ! ( F_10 ( V_7 ) || F_11 ( V_7 ) ) && F_5 ( V_7 ) )
V_7 = F_5 ( V_7 ) ;
return V_7 ;
}
int F_187 ( int V_187 , T_13 V_188 )
{
struct V_1 * V_7 ;
int V_189 ;
unsigned long V_11 ;
if ( F_188 () || ( V_188 & V_190 ) )
return 1 ;
if ( F_189 ( V_187 , V_97 -> V_40 ) )
return 1 ;
if ( F_88 ( F_89 ( V_101 ) ) )
return 1 ;
if ( V_188 & V_191 )
return 0 ;
if ( V_97 -> V_11 & V_102 )
return 1 ;
F_179 ( & V_89 , V_11 ) ;
F_42 () ;
V_7 = F_186 ( F_3 ( V_97 ) ) ;
V_189 = F_189 ( V_187 , V_7 -> V_40 ) ;
F_49 () ;
F_180 ( & V_89 , V_11 ) ;
return V_189 ;
}
static int F_190 ( int * V_192 )
{
int V_187 ;
V_187 = F_191 ( * V_192 , V_97 -> V_40 ) ;
if ( V_187 == V_193 )
V_187 = F_192 ( V_97 -> V_40 ) ;
* V_192 = V_187 ;
return V_187 ;
}
int F_193 ( void )
{
if ( V_97 -> V_194 == V_195 )
V_97 -> V_194 =
F_194 ( & V_97 -> V_40 ) ;
return F_190 ( & V_97 -> V_194 ) ;
}
int F_195 ( void )
{
if ( V_97 -> V_196 == V_195 )
V_97 -> V_196 =
F_194 ( & V_97 -> V_40 ) ;
return F_190 ( & V_97 -> V_196 ) ;
}
int F_196 ( const struct V_4 * V_197 ,
const struct V_4 * V_198 )
{
return F_24 ( V_197 -> V_40 , V_198 -> V_40 ) ;
}
void F_197 ( struct V_4 * V_36 )
{
struct V_52 * V_199 ;
F_42 () ;
V_199 = F_3 ( V_36 ) -> V_3 . V_52 ;
F_198 ( L_8 , V_36 -> V_200 ) ;
F_166 ( V_199 ) ;
F_167 ( L_9 , F_147 ( & V_36 -> V_40 ) ) ;
F_49 () ;
}
void F_199 ( void )
{
F_42 () ;
F_119 ( & F_3 ( V_97 ) -> V_118 ) ;
F_49 () ;
}
int F_200 ( struct V_160 * V_201 , struct V_202 * V_203 ,
struct V_204 * V_204 , struct V_4 * V_36 )
{
char * V_91 , * V_37 ;
struct V_2 * V_3 ;
int V_92 ;
V_92 = - V_117 ;
V_91 = F_57 ( V_205 , V_42 ) ;
if ( ! V_91 )
goto V_49;
V_92 = - V_206 ;
F_42 () ;
V_3 = F_4 ( V_36 , V_6 ) ;
V_37 = F_201 ( V_3 -> V_52 , V_91 , V_205 ) ;
F_49 () ;
if ( ! V_37 )
goto V_207;
F_202 ( V_201 , V_37 ) ;
F_203 ( V_201 , '\n' ) ;
V_92 = 0 ;
V_207:
F_39 ( V_91 ) ;
V_49:
return V_92 ;
}
void F_204 ( struct V_160 * V_201 , struct V_4 * V_5 )
{
F_145 ( V_201 , L_10 ,
F_147 ( & V_5 -> V_40 ) ) ;
F_145 ( V_201 , L_11 ,
F_147 ( & V_5 -> V_40 ) ) ;
}
