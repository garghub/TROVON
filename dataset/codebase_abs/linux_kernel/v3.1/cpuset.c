static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static inline struct V_1 * F_4 ( struct V_6 * V_7 )
{
return F_2 ( F_5 ( V_7 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static inline int F_6 ( const struct V_1 * V_8 )
{
return F_7 ( V_9 , & V_8 -> V_10 ) ;
}
static inline int F_8 ( const struct V_1 * V_8 )
{
return F_7 ( V_11 , & V_8 -> V_10 ) ;
}
static inline int F_9 ( const struct V_1 * V_8 )
{
return F_7 ( V_12 , & V_8 -> V_10 ) ;
}
static inline int F_10 ( const struct V_1 * V_8 )
{
return F_7 ( V_13 , & V_8 -> V_10 ) ;
}
static inline int F_11 ( const struct V_1 * V_8 )
{
return F_7 ( V_14 , & V_8 -> V_10 ) ;
}
static inline int F_12 ( const struct V_1 * V_8 )
{
return F_7 ( V_15 , & V_8 -> V_10 ) ;
}
static inline int F_13 ( const struct V_1 * V_8 )
{
return F_7 ( V_16 , & V_8 -> V_10 ) ;
}
static struct V_17 * F_14 ( struct V_18 * V_19 ,
int V_10 , const char * V_20 , void * V_21 )
{
struct V_18 * V_22 = F_15 ( L_1 ) ;
struct V_17 * V_23 = F_16 ( - V_24 ) ;
if ( V_22 ) {
char V_25 [] =
L_2
L_3 ;
V_23 = V_22 -> V_26 ( V_22 , V_10 ,
V_20 , V_25 ) ;
F_17 ( V_22 ) ;
}
return V_23 ;
}
static void F_18 ( const struct V_1 * V_8 ,
struct V_27 * V_28 )
{
while ( V_8 && ! F_19 ( V_8 -> V_29 , V_30 ) )
V_8 = V_8 -> V_31 ;
if ( V_8 )
F_20 ( V_28 , V_8 -> V_29 , V_30 ) ;
else
F_21 ( V_28 , V_30 ) ;
F_22 ( ! F_19 ( V_28 , V_30 ) ) ;
}
static void F_23 ( const struct V_1 * V_8 , T_1 * V_28 )
{
while ( V_8 && ! F_24 ( V_8 -> V_32 ,
V_33 [ V_34 ] ) )
V_8 = V_8 -> V_31 ;
if ( V_8 )
F_25 ( * V_28 , V_8 -> V_32 ,
V_33 [ V_34 ] ) ;
else
* V_28 = V_33 [ V_34 ] ;
F_22 ( ! F_24 ( * V_28 , V_33 [ V_34 ] ) ) ;
}
static void F_26 ( struct V_1 * V_8 ,
struct V_6 * V_35 )
{
if ( F_12 ( V_8 ) )
V_35 -> V_10 |= V_36 ;
else
V_35 -> V_10 &= ~ V_36 ;
if ( F_13 ( V_8 ) )
V_35 -> V_10 |= V_37 ;
else
V_35 -> V_10 &= ~ V_37 ;
}
static int F_27 ( const struct V_1 * V_38 , const struct V_1 * V_39 )
{
return F_28 ( V_38 -> V_29 , V_39 -> V_29 ) &&
F_29 ( V_38 -> V_32 , V_39 -> V_32 ) &&
F_6 ( V_38 ) <= F_6 ( V_39 ) &&
F_8 ( V_38 ) <= F_8 ( V_39 ) ;
}
static struct V_1 * F_30 ( const struct V_1 * V_8 )
{
struct V_1 * V_40 ;
V_40 = F_31 ( V_8 , sizeof( * V_8 ) , V_41 ) ;
if ( ! V_40 )
return NULL ;
if ( ! F_32 ( & V_40 -> V_29 , V_41 ) ) {
F_33 ( V_40 ) ;
return NULL ;
}
F_21 ( V_40 -> V_29 , V_8 -> V_29 ) ;
return V_40 ;
}
static void F_34 ( struct V_1 * V_40 )
{
F_35 ( V_40 -> V_29 ) ;
F_33 ( V_40 ) ;
}
static int F_36 ( const struct V_1 * V_42 , const struct V_1 * V_40 )
{
struct V_2 * V_3 ;
struct V_1 * V_43 , * V_44 ;
F_37 (cont, &cur->css.cgroup->children, sibling) {
if ( ! F_27 ( F_1 ( V_3 ) , V_40 ) )
return - V_45 ;
}
if ( V_42 == & V_46 )
return 0 ;
V_44 = V_42 -> V_31 ;
if ( ! F_27 ( V_40 , V_44 ) )
return - V_47 ;
F_37 (cont, &par->css.cgroup->children, sibling) {
V_43 = F_1 ( V_3 ) ;
if ( ( F_6 ( V_40 ) || F_6 ( V_43 ) ) &&
V_43 != V_42 &&
F_19 ( V_40 -> V_29 , V_43 -> V_29 ) )
return - V_48 ;
if ( ( F_8 ( V_40 ) || F_8 ( V_43 ) ) &&
V_43 != V_42 &&
F_24 ( V_40 -> V_32 , V_43 -> V_32 ) )
return - V_48 ;
}
if ( F_38 ( V_42 -> V_5 . V_2 ) ) {
if ( F_39 ( V_40 -> V_29 ) ||
F_40 ( V_40 -> V_32 ) ) {
return - V_49 ;
}
}
return 0 ;
}
static int F_41 ( struct V_1 * V_50 , struct V_1 * V_51 )
{
return F_19 ( V_50 -> V_29 , V_51 -> V_29 ) ;
}
static void
F_42 ( struct V_52 * V_53 , struct V_1 * V_43 )
{
if ( V_53 -> V_54 < V_43 -> V_54 )
V_53 -> V_54 = V_43 -> V_54 ;
return;
}
static void
F_43 ( struct V_52 * V_53 , struct V_1 * V_43 )
{
F_44 ( V_39 ) ;
F_45 ( & V_43 -> V_55 , & V_39 ) ;
while ( ! F_46 ( & V_39 ) ) {
struct V_1 * V_56 ;
struct V_2 * V_3 ;
struct V_1 * V_57 ;
V_56 = F_47 ( & V_39 , struct V_1 , V_55 ) ;
F_48 ( V_39 . V_58 ) ;
if ( F_39 ( V_56 -> V_29 ) )
continue;
if ( F_10 ( V_56 ) )
F_42 ( V_53 , V_56 ) ;
F_37 (cont, &cp->css.cgroup->children, sibling) {
V_57 = F_1 ( V_3 ) ;
F_49 ( & V_57 -> V_55 , & V_39 ) ;
}
}
}
static int F_50 ( T_2 * * V_59 ,
struct V_52 * * V_60 )
{
F_44 ( V_39 ) ;
struct V_1 * V_56 ;
struct V_1 * * V_61 ;
int V_62 ;
int V_63 , V_64 , V_65 ;
T_2 * V_66 ;
struct V_52 * V_53 ;
int V_67 = 0 ;
int V_68 ;
V_66 = NULL ;
V_53 = NULL ;
V_61 = NULL ;
if ( F_10 ( & V_46 ) ) {
V_67 = 1 ;
V_66 = F_51 ( V_67 ) ;
if ( ! V_66 )
goto V_69;
V_53 = F_52 ( sizeof( struct V_52 ) , V_41 ) ;
if ( V_53 ) {
* V_53 = V_70 ;
F_43 ( V_53 , & V_46 ) ;
}
F_21 ( V_66 [ 0 ] , V_46 . V_29 ) ;
goto V_69;
}
V_61 = F_52 ( V_71 * sizeof( V_56 ) , V_41 ) ;
if ( ! V_61 )
goto V_69;
V_62 = 0 ;
F_45 ( & V_46 . V_55 , & V_39 ) ;
while ( ! F_46 ( & V_39 ) ) {
struct V_2 * V_3 ;
struct V_1 * V_57 ;
V_56 = F_47 ( & V_39 , struct V_1 , V_55 ) ;
F_48 ( V_39 . V_58 ) ;
if ( F_39 ( V_56 -> V_29 ) )
continue;
if ( F_10 ( V_56 ) ) {
V_61 [ V_62 ++ ] = V_56 ;
continue;
}
F_37 (cont, &cp->css.cgroup->children, sibling) {
V_57 = F_1 ( V_3 ) ;
F_49 ( & V_57 -> V_55 , & V_39 ) ;
}
}
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ )
V_61 [ V_63 ] -> V_72 = V_63 ;
V_67 = V_62 ;
V_73:
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
struct V_1 * V_50 = V_61 [ V_63 ] ;
int V_74 = V_50 -> V_72 ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
struct V_1 * V_51 = V_61 [ V_64 ] ;
int V_75 = V_51 -> V_72 ;
if ( V_74 != V_75 && F_41 ( V_50 , V_51 ) ) {
for ( V_65 = 0 ; V_65 < V_62 ; V_65 ++ ) {
struct V_1 * V_43 = V_61 [ V_65 ] ;
if ( V_43 -> V_72 == V_75 )
V_43 -> V_72 = V_74 ;
}
V_67 -- ;
goto V_73;
}
}
}
V_66 = F_51 ( V_67 ) ;
if ( ! V_66 )
goto V_69;
V_53 = F_52 ( V_67 * sizeof( struct V_52 ) , V_41 ) ;
for ( V_68 = 0 , V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
struct V_1 * V_50 = V_61 [ V_63 ] ;
struct V_27 * V_76 ;
int V_74 = V_50 -> V_72 ;
if ( V_74 < 0 ) {
continue;
}
V_76 = V_66 [ V_68 ] ;
if ( V_68 == V_67 ) {
static int V_77 = 10 ;
if ( V_77 ) {
F_53 ( V_78
L_4
L_5
L_6 ,
V_68 , V_67 , V_62 , V_63 , V_74 ) ;
V_77 -- ;
}
continue;
}
F_54 ( V_76 ) ;
if ( V_53 )
* ( V_53 + V_68 ) = V_70 ;
for ( V_64 = V_63 ; V_64 < V_62 ; V_64 ++ ) {
struct V_1 * V_51 = V_61 [ V_64 ] ;
if ( V_74 == V_51 -> V_72 ) {
F_55 ( V_76 , V_76 , V_51 -> V_29 ) ;
if ( V_53 )
F_43 ( V_53 + V_68 , V_51 ) ;
V_51 -> V_72 = - 1 ;
}
}
V_68 ++ ;
}
F_22 ( V_68 != V_67 ) ;
V_69:
F_33 ( V_61 ) ;
if ( V_66 == NULL )
V_67 = 1 ;
* V_59 = V_66 ;
* V_60 = V_53 ;
return V_67 ;
}
static void F_56 ( struct V_79 * V_80 )
{
struct V_52 * V_81 ;
T_2 * V_66 ;
int V_67 ;
F_57 () ;
F_58 () ;
V_67 = F_50 ( & V_66 , & V_81 ) ;
F_59 () ;
F_60 ( V_67 , V_66 , V_81 ) ;
F_61 () ;
}
static void F_56 ( struct V_79 * V_80 )
{
}
static int F_50 ( T_2 * * V_59 ,
struct V_52 * * V_60 )
{
* V_59 = NULL ;
return 1 ;
}
static void F_62 ( void )
{
F_63 ( V_82 , & V_83 ) ;
}
void F_64 ( void )
{
F_56 ( NULL ) ;
}
static int F_65 ( struct V_6 * V_35 ,
struct V_84 * V_85 )
{
return ! F_66 ( & V_35 -> V_29 ,
( F_1 ( V_85 -> V_86 ) ) -> V_29 ) ;
}
static void F_67 ( struct V_6 * V_35 ,
struct V_84 * V_85 )
{
F_68 ( V_35 , ( ( F_1 ( V_85 -> V_86 ) ) -> V_29 ) ) ;
}
static void F_69 ( struct V_1 * V_8 , struct V_87 * V_88 )
{
struct V_84 V_85 ;
V_85 . V_86 = V_8 -> V_5 . V_2 ;
V_85 . V_89 = F_65 ;
V_85 . V_90 = F_67 ;
V_85 . V_88 = V_88 ;
F_70 ( & V_85 ) ;
}
static int F_71 ( struct V_1 * V_8 , struct V_1 * V_91 ,
const char * V_92 )
{
struct V_87 V_88 ;
int V_93 ;
int V_94 ;
if ( V_8 == & V_46 )
return - V_47 ;
if ( ! * V_92 ) {
F_54 ( V_91 -> V_29 ) ;
} else {
V_93 = F_72 ( V_92 , V_91 -> V_29 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( ! F_28 ( V_91 -> V_29 , V_95 ) )
return - V_48 ;
}
V_93 = F_36 ( V_8 , V_91 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( F_66 ( V_8 -> V_29 , V_91 -> V_29 ) )
return 0 ;
V_93 = F_73 ( & V_88 , V_96 , V_41 , NULL ) ;
if ( V_93 )
return V_93 ;
V_94 = F_10 ( V_91 ) ;
F_74 ( & V_97 ) ;
F_21 ( V_8 -> V_29 , V_91 -> V_29 ) ;
F_75 ( & V_97 ) ;
F_69 ( V_8 , & V_88 ) ;
F_76 ( & V_88 ) ;
if ( V_94 )
F_62 () ;
return 0 ;
}
static void F_77 ( struct V_98 * V_99 , const T_1 * V_100 ,
const T_1 * V_101 )
{
struct V_6 * V_35 = V_102 ;
V_35 -> V_32 = * V_101 ;
F_78 ( V_99 , V_100 , V_101 , V_103 ) ;
F_23 ( F_4 ( V_35 ) , & V_35 -> V_32 ) ;
}
static void F_79 ( struct V_6 * V_35 ,
T_1 * V_104 )
{
V_105:
if ( F_80 ( F_81 ( V_106 ) ) )
return;
if ( V_102 -> V_10 & V_107 )
return;
F_82 ( V_35 ) ;
F_83 ( V_35 -> V_32 , V_35 -> V_32 , * V_104 ) ;
F_84 ( V_35 , V_104 , V_108 ) ;
F_85 () ;
while ( F_86 ( V_35 -> V_109 ) ) {
F_87 ( V_35 ) ;
if ( ! F_88 ( V_35 ) )
F_89 () ;
goto V_105;
}
F_85 () ;
F_84 ( V_35 , V_104 , V_110 ) ;
V_35 -> V_32 = * V_104 ;
F_87 ( V_35 ) ;
}
static void F_90 ( struct V_6 * V_38 ,
struct V_84 * V_85 )
{
struct V_98 * V_99 ;
struct V_1 * V_8 ;
int V_111 ;
const T_1 * V_112 = V_85 -> V_21 ;
static T_1 V_104 ;
V_8 = F_1 ( V_85 -> V_86 ) ;
F_23 ( V_8 , & V_104 ) ;
F_79 ( V_38 , & V_104 ) ;
V_99 = F_91 ( V_38 ) ;
if ( ! V_99 )
return;
V_111 = F_11 ( V_8 ) ;
F_92 ( V_99 , & V_8 -> V_32 ) ;
if ( V_111 )
F_77 ( V_99 , V_112 , & V_8 -> V_32 ) ;
F_93 ( V_99 ) ;
}
static void F_94 ( struct V_1 * V_8 , const T_1 * V_112 ,
struct V_87 * V_88 )
{
struct V_84 V_85 ;
V_113 = V_8 ;
V_85 . V_86 = V_8 -> V_5 . V_2 ;
V_85 . V_89 = NULL ;
V_85 . V_90 = F_90 ;
V_85 . V_88 = V_88 ;
V_85 . V_21 = ( T_1 * ) V_112 ;
F_70 ( & V_85 ) ;
V_113 = NULL ;
}
static int F_95 ( struct V_1 * V_8 , struct V_1 * V_91 ,
const char * V_92 )
{
F_96 ( T_1 , V_112 , V_41 ) ;
int V_93 ;
struct V_87 V_88 ;
if ( ! V_112 )
return - V_114 ;
if ( V_8 == & V_46 ) {
V_93 = - V_47 ;
goto V_69;
}
if ( ! * V_92 ) {
F_97 ( V_91 -> V_32 ) ;
} else {
V_93 = F_98 ( V_92 , V_91 -> V_32 ) ;
if ( V_93 < 0 )
goto V_69;
if ( ! F_29 ( V_91 -> V_32 ,
V_33 [ V_34 ] ) ) {
V_93 = - V_48 ;
goto V_69;
}
}
* V_112 = V_8 -> V_32 ;
if ( F_99 ( * V_112 , V_91 -> V_32 ) ) {
V_93 = 0 ;
goto V_69;
}
V_93 = F_36 ( V_8 , V_91 ) ;
if ( V_93 < 0 )
goto V_69;
V_93 = F_73 ( & V_88 , V_96 , V_41 , NULL ) ;
if ( V_93 < 0 )
goto V_69;
F_74 ( & V_97 ) ;
V_8 -> V_32 = V_91 -> V_32 ;
F_75 ( & V_97 ) ;
F_94 ( V_8 , V_112 , & V_88 ) ;
F_76 ( & V_88 ) ;
V_69:
F_100 ( V_112 ) ;
return V_93 ;
}
int F_101 ( void )
{
return F_4 ( V_102 ) == V_113 ;
}
static int F_102 ( struct V_1 * V_8 , T_3 V_115 )
{
#ifdef F_103
if ( V_115 < - 1 || V_115 >= V_116 )
return - V_48 ;
#endif
if ( V_115 != V_8 -> V_54 ) {
V_8 -> V_54 = V_115 ;
if ( ! F_39 ( V_8 -> V_29 ) &&
F_10 ( V_8 ) )
F_62 () ;
}
return 0 ;
}
static void F_104 ( struct V_6 * V_35 ,
struct V_84 * V_85 )
{
F_26 ( F_1 ( V_85 -> V_86 ) , V_35 ) ;
}
static void F_105 ( struct V_1 * V_8 , struct V_87 * V_88 )
{
struct V_84 V_85 ;
V_85 . V_86 = V_8 -> V_5 . V_2 ;
V_85 . V_89 = NULL ;
V_85 . V_90 = F_104 ;
V_85 . V_88 = V_88 ;
F_70 ( & V_85 ) ;
}
static int F_106 ( T_4 V_117 , struct V_1 * V_8 ,
int V_118 )
{
struct V_1 * V_91 ;
int V_119 ;
int V_120 ;
struct V_87 V_88 ;
int V_121 ;
V_91 = F_30 ( V_8 ) ;
if ( ! V_91 )
return - V_114 ;
if ( V_118 )
F_107 ( V_117 , & V_91 -> V_10 ) ;
else
F_108 ( V_117 , & V_91 -> V_10 ) ;
V_121 = F_36 ( V_8 , V_91 ) ;
if ( V_121 < 0 )
goto V_122;
V_121 = F_73 ( & V_88 , V_96 , V_41 , NULL ) ;
if ( V_121 < 0 )
goto V_122;
V_119 = ( F_10 ( V_8 ) !=
F_10 ( V_91 ) ) ;
V_120 = ( ( F_13 ( V_8 ) != F_13 ( V_91 ) )
|| ( F_12 ( V_8 ) != F_12 ( V_91 ) ) ) ;
F_74 ( & V_97 ) ;
V_8 -> V_10 = V_91 -> V_10 ;
F_75 ( & V_97 ) ;
if ( ! F_39 ( V_91 -> V_29 ) && V_119 )
F_62 () ;
if ( V_120 )
F_105 ( V_8 , & V_88 ) ;
F_76 ( & V_88 ) ;
V_122:
F_34 ( V_91 ) ;
return V_121 ;
}
static void F_109 ( struct V_123 * V_124 )
{
V_124 -> V_125 = 0 ;
V_124 -> V_115 = 0 ;
V_124 -> time = 0 ;
F_110 ( & V_124 -> V_126 ) ;
}
static void F_111 ( struct V_123 * V_124 )
{
T_5 V_127 = F_112 () ;
T_5 V_128 = V_127 - V_124 -> time ;
if ( V_128 == 0 )
return;
V_128 = F_113 ( V_129 , V_128 ) ;
while ( V_128 -- > 0 )
V_124 -> V_115 = ( V_130 * V_124 -> V_115 ) / V_131 ;
V_124 -> time = V_127 ;
V_124 -> V_115 += ( ( V_131 - V_130 ) * V_124 -> V_125 ) / V_131 ;
V_124 -> V_125 = 0 ;
}
static void F_114 ( struct V_123 * V_124 )
{
F_115 ( & V_124 -> V_126 ) ;
F_111 ( V_124 ) ;
V_124 -> V_125 = F_113 ( V_132 , V_124 -> V_125 + V_131 ) ;
F_116 ( & V_124 -> V_126 ) ;
}
static int F_117 ( struct V_123 * V_124 )
{
int V_115 ;
F_115 ( & V_124 -> V_126 ) ;
F_111 ( V_124 ) ;
V_115 = V_124 -> V_115 ;
F_116 ( & V_124 -> V_126 ) ;
return V_115 ;
}
static int F_118 ( struct V_133 * V_134 , struct V_2 * V_3 ,
struct V_6 * V_35 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( F_39 ( V_8 -> V_29 ) || F_40 ( V_8 -> V_32 ) )
return - V_49 ;
if ( V_35 -> V_10 & V_135 )
return - V_48 ;
return 0 ;
}
static int F_119 ( struct V_2 * V_136 , struct V_6 * V_7 )
{
return F_120 ( V_7 ) ;
}
static void F_121 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_8 == & V_46 )
F_21 ( V_137 , V_138 ) ;
else
F_18 ( V_8 , V_137 ) ;
F_23 ( V_8 , & V_139 ) ;
}
static void F_122 ( struct V_2 * V_3 , struct V_6 * V_35 )
{
int V_121 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_121 = F_68 ( V_35 , V_137 ) ;
F_123 ( V_121 ) ;
F_79 ( V_35 , & V_139 ) ;
F_26 ( V_8 , V_35 ) ;
}
static void F_124 ( struct V_133 * V_134 , struct V_2 * V_3 ,
struct V_2 * V_140 , struct V_6 * V_35 )
{
struct V_98 * V_99 ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_1 * V_141 = F_1 ( V_140 ) ;
V_142 = V_141 -> V_32 ;
V_139 = V_8 -> V_32 ;
V_99 = F_91 ( V_35 ) ;
if ( V_99 ) {
F_92 ( V_99 , & V_139 ) ;
if ( F_11 ( V_8 ) )
F_77 ( V_99 , & V_142 ,
& V_139 ) ;
F_93 ( V_99 ) ;
}
}
static int F_125 ( struct V_2 * V_136 , struct V_143 * V_144 , T_6 V_115 )
{
int V_93 = 0 ;
struct V_1 * V_8 = F_1 ( V_136 ) ;
T_7 type = V_144 -> V_145 ;
if ( ! F_126 ( V_136 ) )
return - V_24 ;
switch ( type ) {
case V_146 :
V_93 = F_106 ( V_9 , V_8 , V_115 ) ;
break;
case V_147 :
V_93 = F_106 ( V_11 , V_8 , V_115 ) ;
break;
case V_148 :
V_93 = F_106 ( V_12 , V_8 , V_115 ) ;
break;
case V_149 :
V_93 = F_106 ( V_13 , V_8 , V_115 ) ;
break;
case V_150 :
V_93 = F_106 ( V_14 , V_8 , V_115 ) ;
break;
case V_151 :
V_152 = ! ! V_115 ;
break;
case V_153 :
V_93 = - V_47 ;
break;
case V_154 :
V_93 = F_106 ( V_15 , V_8 , V_115 ) ;
break;
case V_155 :
V_93 = F_106 ( V_16 , V_8 , V_115 ) ;
break;
default:
V_93 = - V_48 ;
break;
}
F_59 () ;
return V_93 ;
}
static int F_127 ( struct V_2 * V_136 , struct V_143 * V_144 , T_3 V_115 )
{
int V_93 = 0 ;
struct V_1 * V_8 = F_1 ( V_136 ) ;
T_7 type = V_144 -> V_145 ;
if ( ! F_126 ( V_136 ) )
return - V_24 ;
switch ( type ) {
case V_156 :
V_93 = F_102 ( V_8 , V_115 ) ;
break;
default:
V_93 = - V_48 ;
break;
}
F_59 () ;
return V_93 ;
}
static int F_128 ( struct V_2 * V_136 , struct V_143 * V_144 ,
const char * V_92 )
{
int V_93 = 0 ;
struct V_1 * V_8 = F_1 ( V_136 ) ;
struct V_1 * V_91 ;
if ( ! F_126 ( V_136 ) )
return - V_24 ;
V_91 = F_30 ( V_8 ) ;
if ( ! V_91 ) {
V_93 = - V_114 ;
goto V_122;
}
switch ( V_144 -> V_145 ) {
case V_157 :
V_93 = F_71 ( V_8 , V_91 , V_92 ) ;
break;
case V_158 :
V_93 = F_95 ( V_8 , V_91 , V_92 ) ;
break;
default:
V_93 = - V_48 ;
break;
}
F_34 ( V_91 ) ;
V_122:
F_59 () ;
return V_93 ;
}
static T_8 F_129 ( char * V_159 , struct V_1 * V_8 )
{
T_8 V_160 ;
F_74 ( & V_97 ) ;
V_160 = F_130 ( V_159 , V_96 , V_8 -> V_29 ) ;
F_75 ( & V_97 ) ;
return V_160 ;
}
static T_8 F_131 ( char * V_159 , struct V_1 * V_8 )
{
T_8 V_160 ;
F_74 ( & V_97 ) ;
V_160 = F_132 ( V_159 , V_96 , V_8 -> V_32 ) ;
F_75 ( & V_97 ) ;
return V_160 ;
}
static T_9 F_133 ( struct V_2 * V_3 ,
struct V_143 * V_144 ,
struct V_161 * V_161 ,
char T_10 * V_92 ,
T_8 V_162 , T_11 * V_163 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_144 -> V_145 ;
char * V_159 ;
T_9 V_93 = 0 ;
char * V_164 ;
if ( ! ( V_159 = ( char * ) F_134 ( V_165 ) ) )
return - V_114 ;
V_164 = V_159 ;
switch ( type ) {
case V_157 :
V_164 += F_129 ( V_164 , V_8 ) ;
break;
case V_158 :
V_164 += F_131 ( V_164 , V_8 ) ;
break;
default:
V_93 = - V_48 ;
goto V_122;
}
* V_164 ++ = '\n' ;
V_93 = F_135 ( V_92 , V_162 , V_163 , V_159 , V_164 - V_159 ) ;
V_122:
F_136 ( ( unsigned long ) V_159 ) ;
return V_93 ;
}
static T_6 F_137 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_144 -> V_145 ;
switch ( type ) {
case V_146 :
return F_6 ( V_8 ) ;
case V_147 :
return F_8 ( V_8 ) ;
case V_148 :
return F_9 ( V_8 ) ;
case V_149 :
return F_10 ( V_8 ) ;
case V_150 :
return F_11 ( V_8 ) ;
case V_151 :
return V_152 ;
case V_153 :
return F_117 ( & V_8 -> V_123 ) ;
case V_154 :
return F_12 ( V_8 ) ;
case V_155 :
return F_13 ( V_8 ) ;
default:
F_138 () ;
}
return 0 ;
}
static T_3 F_139 ( struct V_2 * V_3 , struct V_143 * V_144 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_144 -> V_145 ;
switch ( type ) {
case V_156 :
return V_8 -> V_54 ;
default:
F_138 () ;
}
return 0 ;
}
static int F_140 ( struct V_133 * V_134 , struct V_2 * V_3 )
{
int V_121 ;
V_121 = F_141 ( V_3 , V_134 , V_166 , F_142 ( V_166 ) ) ;
if ( V_121 )
return V_121 ;
if ( ! V_3 -> V_31 )
V_121 = F_143 ( V_3 , V_134 ,
& V_167 ) ;
return V_121 ;
}
static void F_144 ( struct V_133 * V_134 ,
struct V_2 * V_2 )
{
struct V_2 * V_31 , * V_57 ;
struct V_1 * V_8 , * V_168 ;
V_31 = V_2 -> V_31 ;
F_37 (child, &parent->children, sibling) {
V_8 = F_1 ( V_57 ) ;
if ( F_8 ( V_8 ) || F_6 ( V_8 ) )
return;
}
V_8 = F_1 ( V_2 ) ;
V_168 = F_1 ( V_31 ) ;
F_74 ( & V_97 ) ;
V_8 -> V_32 = V_168 -> V_32 ;
F_21 ( V_8 -> V_29 , V_168 -> V_29 ) ;
F_75 ( & V_97 ) ;
return;
}
static struct F_3 * F_145 (
struct V_133 * V_134 ,
struct V_2 * V_3 )
{
struct V_1 * V_8 ;
struct V_1 * V_31 ;
if ( ! V_3 -> V_31 ) {
return & V_46 . V_5 ;
}
V_31 = F_1 ( V_3 -> V_31 ) ;
V_8 = F_52 ( sizeof( * V_8 ) , V_41 ) ;
if ( ! V_8 )
return F_16 ( - V_114 ) ;
if ( ! F_32 ( & V_8 -> V_29 , V_41 ) ) {
F_33 ( V_8 ) ;
return F_16 ( - V_114 ) ;
}
V_8 -> V_10 = 0 ;
if ( F_12 ( V_31 ) )
F_107 ( V_15 , & V_8 -> V_10 ) ;
if ( F_13 ( V_31 ) )
F_107 ( V_16 , & V_8 -> V_10 ) ;
F_107 ( V_13 , & V_8 -> V_10 ) ;
F_54 ( V_8 -> V_29 ) ;
F_97 ( V_8 -> V_32 ) ;
F_109 ( & V_8 -> V_123 ) ;
V_8 -> V_54 = - 1 ;
V_8 -> V_31 = V_31 ;
V_71 ++ ;
return & V_8 -> V_5 ;
}
static void F_146 ( struct V_133 * V_134 , struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( F_10 ( V_8 ) )
F_106 ( V_13 , V_8 , 0 ) ;
V_71 -- ;
F_35 ( V_8 -> V_29 ) ;
F_33 ( V_8 ) ;
}
int T_12 F_147 ( void )
{
int V_121 = 0 ;
if ( ! F_32 ( & V_46 . V_29 , V_41 ) )
F_138 () ;
F_148 ( V_46 . V_29 ) ;
F_149 ( V_46 . V_32 ) ;
F_109 ( & V_46 . V_123 ) ;
F_107 ( V_13 , & V_46 . V_10 ) ;
V_46 . V_54 = - 1 ;
V_121 = F_150 ( & V_169 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( ! F_32 ( & V_137 , V_41 ) )
F_138 () ;
V_71 = 1 ;
return 0 ;
}
static void F_151 ( struct V_6 * V_35 ,
struct V_84 * V_85 )
{
struct V_2 * V_170 = V_85 -> V_21 ;
F_152 ( V_170 , V_35 ) ;
}
static void F_153 ( struct V_1 * V_100 , struct V_1 * V_101 )
{
struct V_84 V_85 ;
V_85 . V_86 = V_100 -> V_5 . V_2 ;
V_85 . V_89 = NULL ;
V_85 . V_90 = F_151 ;
V_85 . V_88 = NULL ;
V_85 . V_21 = V_101 -> V_5 . V_2 ;
if ( F_70 ( & V_85 ) )
F_53 ( V_171 L_7
L_8 ) ;
}
static void F_154 ( struct V_1 * V_8 )
{
struct V_1 * V_31 ;
if ( F_46 ( & V_8 -> V_5 . V_2 -> V_172 ) )
return;
V_31 = V_8 -> V_31 ;
while ( F_39 ( V_31 -> V_29 ) ||
F_40 ( V_31 -> V_32 ) )
V_31 = V_31 -> V_31 ;
F_153 ( V_8 , V_31 ) ;
}
static void F_155 ( struct V_1 * V_173 )
{
F_44 ( V_174 ) ;
struct V_1 * V_56 ;
struct V_1 * V_57 ;
struct V_2 * V_3 ;
static T_1 V_175 ;
F_49 ( (struct V_176 * ) & V_173 -> V_55 , & V_174 ) ;
while ( ! F_46 ( & V_174 ) ) {
V_56 = F_47 ( & V_174 , struct V_1 , V_55 ) ;
F_48 ( V_174 . V_58 ) ;
F_37 (cont, &cp->css.cgroup->children, sibling) {
V_57 = F_1 ( V_3 ) ;
F_49 ( & V_57 -> V_55 , & V_174 ) ;
}
if ( F_28 ( V_56 -> V_29 , V_95 ) &&
F_29 ( V_56 -> V_32 , V_33 [ V_34 ] ) )
continue;
V_175 = V_56 -> V_32 ;
F_74 ( & V_97 ) ;
F_20 ( V_56 -> V_29 , V_56 -> V_29 ,
V_95 ) ;
F_25 ( V_56 -> V_32 , V_56 -> V_32 ,
V_33 [ V_34 ] ) ;
F_75 ( & V_97 ) ;
if ( F_39 ( V_56 -> V_29 ) ||
F_40 ( V_56 -> V_32 ) )
F_154 ( V_56 ) ;
else {
F_69 ( V_56 , NULL ) ;
F_94 ( V_56 , & V_175 , NULL ) ;
}
}
}
void F_156 ( void )
{
struct V_52 * V_81 ;
T_2 * V_66 ;
int V_67 ;
F_58 () ;
F_74 ( & V_97 ) ;
F_21 ( V_46 . V_29 , V_95 ) ;
F_75 ( & V_97 ) ;
F_155 ( & V_46 ) ;
V_67 = F_50 ( & V_66 , & V_81 ) ;
F_59 () ;
F_60 ( V_67 , V_66 , V_81 ) ;
}
static int F_157 ( struct V_177 * V_178 ,
unsigned long V_179 , void * V_180 )
{
static T_1 V_175 ;
F_58 () ;
switch ( V_179 ) {
case V_181 :
V_175 = V_46 . V_32 ;
F_74 ( & V_97 ) ;
V_46 . V_32 = V_33 [ V_34 ] ;
F_75 ( & V_97 ) ;
F_94 ( & V_46 , & V_175 , NULL ) ;
break;
case V_182 :
F_155 ( & V_46 ) ;
break;
default:
break;
}
F_59 () ;
return V_183 ;
}
void T_12 F_158 ( void )
{
F_21 ( V_46 . V_29 , V_95 ) ;
V_46 . V_32 = V_33 [ V_34 ] ;
F_159 ( F_157 , 10 ) ;
V_82 = F_160 ( L_9 ) ;
F_22 ( ! V_82 ) ;
}
void F_161 ( struct V_6 * V_35 , struct V_27 * V_28 )
{
F_74 ( & V_97 ) ;
F_82 ( V_35 ) ;
F_18 ( F_4 ( V_35 ) , V_28 ) ;
F_87 ( V_35 ) ;
F_75 ( & V_97 ) ;
}
int F_162 ( struct V_6 * V_35 )
{
const struct V_1 * V_8 ;
int V_184 ;
F_163 () ;
V_8 = F_4 ( V_35 ) ;
if ( V_8 )
F_164 ( V_35 , V_8 -> V_29 ) ;
F_165 () ;
V_184 = F_166 ( & V_35 -> V_29 , V_95 ) ;
if ( V_184 >= V_185 ) {
F_164 ( V_35 , V_138 ) ;
V_184 = F_167 ( V_95 ) ;
}
return V_184 ;
}
void F_168 ( void )
{
F_149 ( V_102 -> V_32 ) ;
}
T_1 F_169 ( struct V_6 * V_35 )
{
T_1 V_186 ;
F_74 ( & V_97 ) ;
F_82 ( V_35 ) ;
F_23 ( F_4 ( V_35 ) , & V_186 ) ;
F_87 ( V_35 ) ;
F_75 ( & V_97 ) ;
return V_186 ;
}
int F_170 ( T_1 * V_187 )
{
return F_24 ( * V_187 , V_102 -> V_32 ) ;
}
static const struct V_1 * F_171 ( const struct V_1 * V_8 )
{
while ( ! ( F_8 ( V_8 ) || F_9 ( V_8 ) ) && V_8 -> V_31 )
V_8 = V_8 -> V_31 ;
return V_8 ;
}
int F_172 ( int V_188 , T_13 V_189 )
{
const struct V_1 * V_8 ;
int V_190 ;
if ( F_173 () || ( V_189 & V_191 ) )
return 1 ;
F_174 ( ! ( V_189 & V_192 ) ) ;
if ( F_175 ( V_188 , V_102 -> V_32 ) )
return 1 ;
if ( F_80 ( F_81 ( V_106 ) ) )
return 1 ;
if ( V_189 & V_192 )
return 0 ;
if ( V_102 -> V_10 & V_107 )
return 1 ;
F_74 ( & V_97 ) ;
F_82 ( V_102 ) ;
V_8 = F_171 ( F_4 ( V_102 ) ) ;
F_87 ( V_102 ) ;
V_190 = F_175 ( V_188 , V_8 -> V_32 ) ;
F_75 ( & V_97 ) ;
return V_190 ;
}
int F_176 ( int V_188 , T_13 V_189 )
{
if ( F_173 () || ( V_189 & V_191 ) )
return 1 ;
if ( F_175 ( V_188 , V_102 -> V_32 ) )
return 1 ;
if ( F_80 ( F_81 ( V_106 ) ) )
return 1 ;
return 0 ;
}
void F_177 ( void )
{
F_75 ( & V_97 ) ;
}
static int F_178 ( int * V_193 )
{
int V_188 ;
V_188 = F_179 ( * V_193 , V_102 -> V_32 ) ;
if ( V_188 == V_194 )
V_188 = F_180 ( V_102 -> V_32 ) ;
* V_193 = V_188 ;
return V_188 ;
}
int F_181 ( void )
{
if ( V_102 -> V_195 == V_196 )
V_102 -> V_195 =
F_182 ( & V_102 -> V_32 ) ;
return F_178 ( & V_102 -> V_195 ) ;
}
int F_183 ( void )
{
if ( V_102 -> V_197 == V_196 )
V_102 -> V_197 =
F_182 ( & V_102 -> V_32 ) ;
return F_178 ( & V_102 -> V_197 ) ;
}
int F_184 ( const struct V_6 * V_198 ,
const struct V_6 * V_199 )
{
return F_24 ( V_198 -> V_32 , V_199 -> V_32 ) ;
}
void F_185 ( struct V_6 * V_35 )
{
struct V_17 * V_17 ;
V_17 = F_4 ( V_35 ) -> V_5 . V_2 -> V_17 ;
F_115 ( & V_200 ) ;
snprintf ( V_201 , V_202 ,
V_17 ? ( const char * ) V_17 -> V_203 . V_204 : L_10 ) ;
F_132 ( V_205 , V_206 ,
V_35 -> V_32 ) ;
F_53 ( V_207 L_11 ,
V_35 -> V_208 , V_201 , V_205 ) ;
F_116 ( & V_200 ) ;
}
void F_186 ( void )
{
F_82 ( V_102 ) ;
F_114 ( & F_4 ( V_102 ) -> V_123 ) ;
F_87 ( V_102 ) ;
}
static int F_187 ( struct V_209 * V_210 , void * V_211 )
{
struct V_212 * V_212 ;
struct V_6 * V_35 ;
char * V_92 ;
struct F_3 * V_5 ;
int V_93 ;
V_93 = - V_114 ;
V_92 = F_52 ( V_96 , V_41 ) ;
if ( ! V_92 )
goto V_122;
V_93 = - V_213 ;
V_212 = V_210 -> V_145 ;
V_35 = F_188 ( V_212 , V_214 ) ;
if ( ! V_35 )
goto V_215;
V_93 = - V_48 ;
F_58 () ;
V_5 = F_5 ( V_35 , V_4 ) ;
V_93 = F_189 ( V_5 -> V_2 , V_92 , V_96 ) ;
if ( V_93 < 0 )
goto V_216;
F_190 ( V_210 , V_92 ) ;
F_191 ( V_210 , '\n' ) ;
V_216:
F_59 () ;
F_192 ( V_35 ) ;
V_215:
F_33 ( V_92 ) ;
V_122:
return V_93 ;
}
static int F_193 ( struct V_217 * V_217 , struct V_161 * V_161 )
{
struct V_212 * V_212 = F_194 ( V_217 ) -> V_212 ;
return F_195 ( V_161 , F_187 , V_212 ) ;
}
void F_196 ( struct V_209 * V_210 , struct V_6 * V_7 )
{
F_197 ( V_210 , L_12 ) ;
F_198 ( V_210 , & V_7 -> V_32 ) ;
F_197 ( V_210 , L_13 ) ;
F_197 ( V_210 , L_14 ) ;
F_199 ( V_210 , & V_7 -> V_32 ) ;
F_197 ( V_210 , L_13 ) ;
}
