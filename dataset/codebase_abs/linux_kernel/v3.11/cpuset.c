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
static inline struct V_1 * F_6 ( const struct V_1 * V_8 )
{
struct V_2 * V_9 = V_8 -> V_5 . V_2 -> V_10 ;
if ( V_9 )
return F_1 ( V_9 ) ;
return NULL ;
}
static inline bool F_7 ( struct V_6 * V_7 )
{
return V_7 -> V_11 ;
}
static inline bool F_7 ( struct V_6 * V_7 )
{
return false ;
}
static inline bool F_8 ( const struct V_1 * V_8 )
{
return F_9 ( V_12 , & V_8 -> V_13 ) ;
}
static inline int F_10 ( const struct V_1 * V_8 )
{
return F_9 ( V_14 , & V_8 -> V_13 ) ;
}
static inline int F_11 ( const struct V_1 * V_8 )
{
return F_9 ( V_15 , & V_8 -> V_13 ) ;
}
static inline int F_12 ( const struct V_1 * V_8 )
{
return F_9 ( V_16 , & V_8 -> V_13 ) ;
}
static inline int F_13 ( const struct V_1 * V_8 )
{
return F_9 ( V_17 , & V_8 -> V_13 ) ;
}
static inline int F_14 ( const struct V_1 * V_8 )
{
return F_9 ( V_18 , & V_8 -> V_13 ) ;
}
static inline int F_15 ( const struct V_1 * V_8 )
{
return F_9 ( V_19 , & V_8 -> V_13 ) ;
}
static inline int F_16 ( const struct V_1 * V_8 )
{
return F_9 ( V_20 , & V_8 -> V_13 ) ;
}
static struct V_21 * F_17 ( struct V_22 * V_23 ,
int V_13 , const char * V_24 , void * V_25 )
{
struct V_22 * V_26 = F_18 ( L_1 ) ;
struct V_21 * V_27 = F_19 ( - V_28 ) ;
if ( V_26 ) {
char V_29 [] =
L_2
L_3 ;
V_27 = V_26 -> V_30 ( V_26 , V_13 ,
V_24 , V_29 ) ;
F_20 ( V_26 ) ;
}
return V_27 ;
}
static void F_21 ( const struct V_1 * V_8 ,
struct V_31 * V_32 )
{
while ( ! F_22 ( V_8 -> V_33 , V_34 ) )
V_8 = F_6 ( V_8 ) ;
F_23 ( V_32 , V_8 -> V_33 , V_34 ) ;
}
static void F_24 ( const struct V_1 * V_8 , T_1 * V_32 )
{
while ( ! F_25 ( V_8 -> V_35 , V_36 [ V_37 ] ) )
V_8 = F_6 ( V_8 ) ;
F_26 ( * V_32 , V_8 -> V_35 , V_36 [ V_37 ] ) ;
}
static void F_27 ( struct V_1 * V_8 ,
struct V_6 * V_38 )
{
if ( F_15 ( V_8 ) )
V_38 -> V_13 |= V_39 ;
else
V_38 -> V_13 &= ~ V_39 ;
if ( F_16 ( V_8 ) )
V_38 -> V_13 |= V_40 ;
else
V_38 -> V_13 &= ~ V_40 ;
}
static int F_28 ( const struct V_1 * V_41 , const struct V_1 * V_42 )
{
return F_29 ( V_41 -> V_33 , V_42 -> V_33 ) &&
F_30 ( V_41 -> V_35 , V_42 -> V_35 ) &&
F_10 ( V_41 ) <= F_10 ( V_42 ) &&
F_11 ( V_41 ) <= F_11 ( V_42 ) ;
}
static struct V_1 * F_31 ( const struct V_1 * V_8 )
{
struct V_1 * V_43 ;
V_43 = F_32 ( V_8 , sizeof( * V_8 ) , V_44 ) ;
if ( ! V_43 )
return NULL ;
if ( ! F_33 ( & V_43 -> V_33 , V_44 ) ) {
F_34 ( V_43 ) ;
return NULL ;
}
F_35 ( V_43 -> V_33 , V_8 -> V_33 ) ;
return V_43 ;
}
static void F_36 ( struct V_1 * V_43 )
{
F_37 ( V_43 -> V_33 ) ;
F_34 ( V_43 ) ;
}
static int F_38 ( const struct V_1 * V_45 , const struct V_1 * V_43 )
{
struct V_2 * V_3 ;
struct V_1 * V_46 , * V_47 ;
int V_27 ;
F_39 () ;
V_27 = - V_48 ;
F_40 (c, cgrp, cur)
if ( ! F_28 ( V_46 , V_43 ) )
goto V_49;
V_27 = 0 ;
if ( V_45 == & V_50 )
goto V_49;
V_47 = F_6 ( V_45 ) ;
V_27 = - V_51 ;
if ( ! F_28 ( V_43 , V_47 ) )
goto V_49;
V_27 = - V_52 ;
F_40 (c, cgrp, par) {
if ( ( F_10 ( V_43 ) || F_10 ( V_46 ) ) &&
V_46 != V_45 &&
F_22 ( V_43 -> V_33 , V_46 -> V_33 ) )
goto V_49;
if ( ( F_11 ( V_43 ) || F_11 ( V_46 ) ) &&
V_46 != V_45 &&
F_25 ( V_43 -> V_35 , V_46 -> V_35 ) )
goto V_49;
}
V_27 = - V_53 ;
if ( ( F_41 ( V_45 -> V_5 . V_2 ) || V_45 -> V_54 ) ) {
if ( ! F_42 ( V_45 -> V_33 ) &&
F_42 ( V_43 -> V_33 ) )
goto V_49;
if ( ! F_43 ( V_45 -> V_35 ) &&
F_43 ( V_43 -> V_35 ) )
goto V_49;
}
V_27 = 0 ;
V_49:
F_44 () ;
return V_27 ;
}
static int F_45 ( struct V_1 * V_55 , struct V_1 * V_56 )
{
return F_22 ( V_55 -> V_33 , V_56 -> V_33 ) ;
}
static void
F_46 ( struct V_57 * V_58 , struct V_1 * V_46 )
{
if ( V_58 -> V_59 < V_46 -> V_59 )
V_58 -> V_59 = V_46 -> V_59 ;
return;
}
static void F_47 ( struct V_57 * V_58 ,
struct V_1 * V_60 )
{
struct V_1 * V_61 ;
struct V_2 * V_62 ;
F_39 () ;
F_48 (cp, pos_cgrp, root_cs) {
if ( F_42 ( V_61 -> V_33 ) ) {
V_62 = F_49 ( V_62 ) ;
continue;
}
if ( F_13 ( V_61 ) )
F_46 ( V_58 , V_61 ) ;
}
F_44 () ;
}
static int F_50 ( T_2 * * V_63 ,
struct V_57 * * V_64 )
{
struct V_1 * V_61 ;
struct V_1 * * V_65 ;
int V_66 ;
int V_67 , V_68 , V_69 ;
T_2 * V_70 ;
struct V_57 * V_58 ;
int V_71 = 0 ;
int V_72 ;
struct V_2 * V_62 ;
V_70 = NULL ;
V_58 = NULL ;
V_65 = NULL ;
if ( F_13 ( & V_50 ) ) {
V_71 = 1 ;
V_70 = F_51 ( V_71 ) ;
if ( ! V_70 )
goto V_73;
V_58 = F_52 ( sizeof( struct V_57 ) , V_44 ) ;
if ( V_58 ) {
* V_58 = V_74 ;
F_47 ( V_58 , & V_50 ) ;
}
F_35 ( V_70 [ 0 ] , V_50 . V_33 ) ;
goto V_73;
}
V_65 = F_52 ( V_75 * sizeof( V_61 ) , V_44 ) ;
if ( ! V_65 )
goto V_73;
V_66 = 0 ;
F_39 () ;
F_48 (cp, pos_cgrp, &top_cpuset) {
if ( ! F_42 ( V_61 -> V_33 ) &&
! F_13 ( V_61 ) )
continue;
if ( F_13 ( V_61 ) )
V_65 [ V_66 ++ ] = V_61 ;
V_62 = F_49 ( V_62 ) ;
}
F_44 () ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ )
V_65 [ V_67 ] -> V_76 = V_67 ;
V_71 = V_66 ;
V_77:
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
struct V_1 * V_55 = V_65 [ V_67 ] ;
int V_78 = V_55 -> V_76 ;
for ( V_68 = 0 ; V_68 < V_66 ; V_68 ++ ) {
struct V_1 * V_56 = V_65 [ V_68 ] ;
int V_79 = V_56 -> V_76 ;
if ( V_78 != V_79 && F_45 ( V_55 , V_56 ) ) {
for ( V_69 = 0 ; V_69 < V_66 ; V_69 ++ ) {
struct V_1 * V_46 = V_65 [ V_69 ] ;
if ( V_46 -> V_76 == V_79 )
V_46 -> V_76 = V_78 ;
}
V_71 -- ;
goto V_77;
}
}
}
V_70 = F_51 ( V_71 ) ;
if ( ! V_70 )
goto V_73;
V_58 = F_52 ( V_71 * sizeof( struct V_57 ) , V_44 ) ;
for ( V_72 = 0 , V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
struct V_1 * V_55 = V_65 [ V_67 ] ;
struct V_31 * V_80 ;
int V_78 = V_55 -> V_76 ;
if ( V_78 < 0 ) {
continue;
}
V_80 = V_70 [ V_72 ] ;
if ( V_72 == V_71 ) {
static int V_81 = 10 ;
if ( V_81 ) {
F_53 ( V_82
L_4
L_5
L_6 ,
V_72 , V_71 , V_66 , V_67 , V_78 ) ;
V_81 -- ;
}
continue;
}
F_54 ( V_80 ) ;
if ( V_58 )
* ( V_58 + V_72 ) = V_74 ;
for ( V_68 = V_67 ; V_68 < V_66 ; V_68 ++ ) {
struct V_1 * V_56 = V_65 [ V_68 ] ;
if ( V_78 == V_56 -> V_76 ) {
F_55 ( V_80 , V_80 , V_56 -> V_33 ) ;
if ( V_58 )
F_47 ( V_58 + V_72 , V_56 ) ;
V_56 -> V_76 = - 1 ;
}
}
V_72 ++ ;
}
F_56 ( V_72 != V_71 ) ;
V_73:
F_34 ( V_65 ) ;
if ( V_70 == NULL )
V_71 = 1 ;
* V_63 = V_70 ;
* V_64 = V_58 ;
return V_71 ;
}
static void F_57 ( void )
{
struct V_57 * V_83 ;
T_2 * V_70 ;
int V_71 ;
F_58 ( & V_84 ) ;
F_59 () ;
if ( ! F_60 ( V_50 . V_33 , V_85 ) )
goto V_49;
V_71 = F_50 ( & V_70 , & V_83 ) ;
F_61 ( V_71 , V_70 , V_83 ) ;
V_49:
F_62 () ;
}
static void F_57 ( void )
{
}
void F_63 ( void )
{
F_64 ( & V_84 ) ;
F_57 () ;
F_65 ( & V_84 ) ;
}
static struct V_1 * F_66 ( struct V_1 * V_8 )
{
while ( F_42 ( V_8 -> V_33 ) )
V_8 = F_6 ( V_8 ) ;
return V_8 ;
}
static struct V_1 * F_67 ( struct V_1 * V_8 )
{
while ( F_43 ( V_8 -> V_35 ) )
V_8 = F_6 ( V_8 ) ;
return V_8 ;
}
static void F_68 ( struct V_6 * V_38 ,
struct V_86 * V_87 )
{
struct V_1 * V_88 ;
V_88 = F_66 ( F_1 ( V_87 -> V_89 ) ) ;
F_69 ( V_38 , V_88 -> V_33 ) ;
}
static void F_70 ( struct V_1 * V_8 , struct V_90 * V_91 )
{
struct V_86 V_87 ;
V_87 . V_89 = V_8 -> V_5 . V_2 ;
V_87 . V_92 = NULL ;
V_87 . V_93 = F_68 ;
V_87 . V_91 = V_91 ;
F_71 ( & V_87 ) ;
}
static void F_72 ( struct V_1 * V_60 ,
bool V_94 , struct V_90 * V_91 )
{
struct V_1 * V_61 ;
struct V_2 * V_62 ;
if ( V_94 )
F_70 ( V_60 , V_91 ) ;
F_39 () ;
F_48 (cp, pos_cgrp, root_cs) {
if ( ! F_42 ( V_61 -> V_33 ) ) {
V_62 = F_49 ( V_62 ) ;
continue;
}
if ( ! F_73 ( & V_61 -> V_5 ) )
continue;
F_44 () ;
F_70 ( V_61 , V_91 ) ;
F_39 () ;
F_74 ( & V_61 -> V_5 ) ;
}
F_44 () ;
}
static int F_75 ( struct V_1 * V_8 , struct V_1 * V_95 ,
const char * V_96 )
{
struct V_90 V_91 ;
int V_97 ;
int V_98 ;
if ( V_8 == & V_50 )
return - V_51 ;
if ( ! * V_96 ) {
F_54 ( V_95 -> V_33 ) ;
} else {
V_97 = F_76 ( V_96 , V_95 -> V_33 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( ! F_29 ( V_95 -> V_33 , V_85 ) )
return - V_52 ;
}
if ( F_60 ( V_8 -> V_33 , V_95 -> V_33 ) )
return 0 ;
V_97 = F_38 ( V_8 , V_95 ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_77 ( & V_91 , V_99 , V_44 , NULL ) ;
if ( V_97 )
return V_97 ;
V_98 = F_13 ( V_95 ) ;
F_64 ( & V_100 ) ;
F_35 ( V_8 -> V_33 , V_95 -> V_33 ) ;
F_65 ( & V_100 ) ;
F_72 ( V_8 , true , & V_91 ) ;
F_78 ( & V_91 ) ;
if ( V_98 )
F_57 () ;
return 0 ;
}
static void F_79 ( struct V_101 * V_102 , const T_1 * V_103 ,
const T_1 * V_104 )
{
struct V_6 * V_38 = V_105 ;
struct V_1 * V_106 ;
V_38 -> V_35 = * V_104 ;
F_80 ( V_102 , V_103 , V_104 , V_107 ) ;
V_106 = F_67 ( F_4 ( V_38 ) ) ;
F_24 ( V_106 , & V_38 -> V_35 ) ;
}
static void F_81 ( struct V_6 * V_38 ,
T_1 * V_108 )
{
bool V_109 ;
if ( F_82 ( F_83 ( V_110 ) ) )
return;
if ( V_105 -> V_13 & V_111 )
return;
F_84 ( V_38 ) ;
V_109 = F_7 ( V_38 ) ||
! F_25 ( * V_108 , V_38 -> V_35 ) ;
if ( V_109 )
F_85 ( & V_38 -> V_112 ) ;
F_86 ( V_38 -> V_35 , V_38 -> V_35 , * V_108 ) ;
F_87 ( V_38 , V_108 , V_113 ) ;
F_87 ( V_38 , V_108 , V_114 ) ;
V_38 -> V_35 = * V_108 ;
if ( V_109 )
F_88 ( & V_38 -> V_112 ) ;
F_89 ( V_38 ) ;
}
static void F_90 ( struct V_6 * V_41 ,
struct V_86 * V_87 )
{
struct V_1 * V_8 = F_1 ( V_87 -> V_89 ) ;
struct V_101 * V_102 ;
int V_115 ;
T_1 * V_108 = V_87 -> V_25 ;
F_81 ( V_41 , V_108 ) ;
V_102 = F_91 ( V_41 ) ;
if ( ! V_102 )
return;
V_115 = F_14 ( V_8 ) ;
F_92 ( V_102 , & V_8 -> V_35 ) ;
if ( V_115 )
F_79 ( V_102 , & V_8 -> V_116 , V_108 ) ;
F_93 ( V_102 ) ;
}
static void F_94 ( struct V_1 * V_8 , struct V_90 * V_91 )
{
static T_1 V_108 ;
struct V_86 V_87 ;
struct V_1 * V_106 = F_67 ( V_8 ) ;
V_117 = V_8 ;
F_24 ( V_106 , & V_108 ) ;
V_87 . V_89 = V_8 -> V_5 . V_2 ;
V_87 . V_92 = NULL ;
V_87 . V_93 = F_90 ;
V_87 . V_91 = V_91 ;
V_87 . V_25 = & V_108 ;
F_71 ( & V_87 ) ;
V_8 -> V_116 = V_108 ;
V_117 = NULL ;
}
static void F_95 ( struct V_1 * V_60 ,
bool V_94 , struct V_90 * V_91 )
{
struct V_1 * V_61 ;
struct V_2 * V_62 ;
if ( V_94 )
F_94 ( V_60 , V_91 ) ;
F_39 () ;
F_48 (cp, pos_cgrp, root_cs) {
if ( ! F_43 ( V_61 -> V_35 ) ) {
V_62 = F_49 ( V_62 ) ;
continue;
}
if ( ! F_73 ( & V_61 -> V_5 ) )
continue;
F_44 () ;
F_94 ( V_61 , V_91 ) ;
F_39 () ;
F_74 ( & V_61 -> V_5 ) ;
}
F_44 () ;
}
static int F_96 ( struct V_1 * V_8 , struct V_1 * V_95 ,
const char * V_96 )
{
int V_97 ;
struct V_90 V_91 ;
if ( V_8 == & V_50 ) {
V_97 = - V_51 ;
goto V_73;
}
if ( ! * V_96 ) {
F_97 ( V_95 -> V_35 ) ;
} else {
V_97 = F_98 ( V_96 , V_95 -> V_35 ) ;
if ( V_97 < 0 )
goto V_73;
if ( ! F_30 ( V_95 -> V_35 ,
V_36 [ V_37 ] ) ) {
V_97 = - V_52 ;
goto V_73;
}
}
if ( F_99 ( V_8 -> V_35 , V_95 -> V_35 ) ) {
V_97 = 0 ;
goto V_73;
}
V_97 = F_38 ( V_8 , V_95 ) ;
if ( V_97 < 0 )
goto V_73;
V_97 = F_77 ( & V_91 , V_99 , V_44 , NULL ) ;
if ( V_97 < 0 )
goto V_73;
F_64 ( & V_100 ) ;
V_8 -> V_35 = V_95 -> V_35 ;
F_65 ( & V_100 ) ;
F_95 ( V_8 , true , & V_91 ) ;
F_78 ( & V_91 ) ;
V_73:
return V_97 ;
}
int F_100 ( void )
{
return F_4 ( V_105 ) == V_117 ;
}
static int F_101 ( struct V_1 * V_8 , T_3 V_118 )
{
#ifdef F_102
if ( V_118 < - 1 || V_118 >= V_119 )
return - V_52 ;
#endif
if ( V_118 != V_8 -> V_59 ) {
V_8 -> V_59 = V_118 ;
if ( ! F_42 ( V_8 -> V_33 ) &&
F_13 ( V_8 ) )
F_57 () ;
}
return 0 ;
}
static void F_103 ( struct V_6 * V_38 ,
struct V_86 * V_87 )
{
F_27 ( F_1 ( V_87 -> V_89 ) , V_38 ) ;
}
static void F_104 ( struct V_1 * V_8 , struct V_90 * V_91 )
{
struct V_86 V_87 ;
V_87 . V_89 = V_8 -> V_5 . V_2 ;
V_87 . V_92 = NULL ;
V_87 . V_93 = F_103 ;
V_87 . V_91 = V_91 ;
F_71 ( & V_87 ) ;
}
static int F_105 ( T_4 V_120 , struct V_1 * V_8 ,
int V_121 )
{
struct V_1 * V_95 ;
int V_122 ;
int V_123 ;
struct V_90 V_91 ;
int V_124 ;
V_95 = F_31 ( V_8 ) ;
if ( ! V_95 )
return - V_125 ;
if ( V_121 )
F_106 ( V_120 , & V_95 -> V_13 ) ;
else
F_107 ( V_120 , & V_95 -> V_13 ) ;
V_124 = F_38 ( V_8 , V_95 ) ;
if ( V_124 < 0 )
goto V_49;
V_124 = F_77 ( & V_91 , V_99 , V_44 , NULL ) ;
if ( V_124 < 0 )
goto V_49;
V_122 = ( F_13 ( V_8 ) !=
F_13 ( V_95 ) ) ;
V_123 = ( ( F_16 ( V_8 ) != F_16 ( V_95 ) )
|| ( F_15 ( V_8 ) != F_15 ( V_95 ) ) ) ;
F_64 ( & V_100 ) ;
V_8 -> V_13 = V_95 -> V_13 ;
F_65 ( & V_100 ) ;
if ( ! F_42 ( V_95 -> V_33 ) && V_122 )
F_57 () ;
if ( V_123 )
F_104 ( V_8 , & V_91 ) ;
F_78 ( & V_91 ) ;
V_49:
F_36 ( V_95 ) ;
return V_124 ;
}
static void F_108 ( struct V_126 * V_127 )
{
V_127 -> V_128 = 0 ;
V_127 -> V_118 = 0 ;
V_127 -> time = 0 ;
F_109 ( & V_127 -> V_129 ) ;
}
static void F_110 ( struct V_126 * V_127 )
{
T_5 V_130 = F_111 () ;
T_5 V_131 = V_130 - V_127 -> time ;
if ( V_131 == 0 )
return;
V_131 = F_112 ( V_132 , V_131 ) ;
while ( V_131 -- > 0 )
V_127 -> V_118 = ( V_133 * V_127 -> V_118 ) / V_134 ;
V_127 -> time = V_130 ;
V_127 -> V_118 += ( ( V_134 - V_133 ) * V_127 -> V_128 ) / V_134 ;
V_127 -> V_128 = 0 ;
}
static void F_113 ( struct V_126 * V_127 )
{
F_114 ( & V_127 -> V_129 ) ;
F_110 ( V_127 ) ;
V_127 -> V_128 = F_112 ( V_135 , V_127 -> V_128 + V_134 ) ;
F_115 ( & V_127 -> V_129 ) ;
}
static int F_116 ( struct V_126 * V_127 )
{
int V_118 ;
F_114 ( & V_127 -> V_129 ) ;
F_110 ( V_127 ) ;
V_118 = V_127 -> V_118 ;
F_115 ( & V_127 -> V_129 ) ;
return V_118 ;
}
static int F_117 ( struct V_2 * V_3 , struct V_136 * V_137 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
int V_27 ;
F_64 ( & V_84 ) ;
V_27 = - V_53 ;
if ( ! F_118 ( V_3 ) &&
( F_42 ( V_8 -> V_33 ) || F_43 ( V_8 -> V_35 ) ) )
goto V_138;
F_119 (task, cgrp, tset) {
V_27 = - V_52 ;
if ( V_7 -> V_13 & V_139 )
goto V_138;
V_27 = F_120 ( V_7 ) ;
if ( V_27 )
goto V_138;
}
V_8 -> V_54 ++ ;
V_27 = 0 ;
V_138:
F_65 ( & V_84 ) ;
return V_27 ;
}
static void F_121 ( struct V_2 * V_3 ,
struct V_136 * V_137 )
{
F_64 ( & V_84 ) ;
F_1 ( V_3 ) -> V_54 -- ;
F_65 ( & V_84 ) ;
}
static void F_122 ( struct V_2 * V_3 , struct V_136 * V_137 )
{
static T_1 V_140 ;
struct V_101 * V_102 ;
struct V_6 * V_7 ;
struct V_6 * V_141 = F_123 ( V_137 ) ;
struct V_2 * V_142 = F_124 ( V_137 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_1 * V_143 = F_1 ( V_142 ) ;
struct V_1 * V_88 = F_66 ( V_8 ) ;
struct V_1 * V_106 = F_67 ( V_8 ) ;
F_64 ( & V_84 ) ;
if ( V_8 == & V_50 )
F_35 ( V_144 , V_145 ) ;
else
F_21 ( V_88 , V_144 ) ;
F_24 ( V_106 , & V_140 ) ;
F_119 (task, cgrp, tset) {
F_125 ( F_69 ( V_7 , V_144 ) ) ;
F_81 ( V_7 , & V_140 ) ;
F_27 ( V_8 , V_7 ) ;
}
V_140 = V_8 -> V_35 ;
V_102 = F_91 ( V_141 ) ;
if ( V_102 ) {
struct V_1 * V_146 = F_67 ( V_143 ) ;
F_92 ( V_102 , & V_140 ) ;
if ( F_14 ( V_8 ) ) {
F_79 ( V_102 , & V_146 -> V_116 ,
& V_140 ) ;
}
F_93 ( V_102 ) ;
}
V_8 -> V_116 = V_140 ;
V_8 -> V_54 -- ;
if ( ! V_8 -> V_54 )
F_126 ( & V_147 ) ;
F_65 ( & V_84 ) ;
}
static int F_127 ( struct V_2 * V_3 , struct V_148 * V_149 , T_6 V_118 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_149 -> V_150 ;
int V_97 = 0 ;
F_64 ( & V_84 ) ;
if ( ! F_8 ( V_8 ) ) {
V_97 = - V_28 ;
goto V_138;
}
switch ( type ) {
case V_151 :
V_97 = F_105 ( V_14 , V_8 , V_118 ) ;
break;
case V_152 :
V_97 = F_105 ( V_15 , V_8 , V_118 ) ;
break;
case V_153 :
V_97 = F_105 ( V_16 , V_8 , V_118 ) ;
break;
case V_154 :
V_97 = F_105 ( V_17 , V_8 , V_118 ) ;
break;
case V_155 :
V_97 = F_105 ( V_18 , V_8 , V_118 ) ;
break;
case V_156 :
V_157 = ! ! V_118 ;
break;
case V_158 :
V_97 = - V_51 ;
break;
case V_159 :
V_97 = F_105 ( V_19 , V_8 , V_118 ) ;
break;
case V_160 :
V_97 = F_105 ( V_20 , V_8 , V_118 ) ;
break;
default:
V_97 = - V_52 ;
break;
}
V_138:
F_65 ( & V_84 ) ;
return V_97 ;
}
static int F_128 ( struct V_2 * V_3 , struct V_148 * V_149 , T_3 V_118 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_149 -> V_150 ;
int V_97 = - V_28 ;
F_64 ( & V_84 ) ;
if ( ! F_8 ( V_8 ) )
goto V_138;
switch ( type ) {
case V_161 :
V_97 = F_101 ( V_8 , V_118 ) ;
break;
default:
V_97 = - V_52 ;
break;
}
V_138:
F_65 ( & V_84 ) ;
return V_97 ;
}
static int F_129 ( struct V_2 * V_3 , struct V_148 * V_149 ,
const char * V_96 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_1 * V_95 ;
int V_97 = - V_28 ;
F_130 ( & V_162 ) ;
F_64 ( & V_84 ) ;
if ( ! F_8 ( V_8 ) )
goto V_138;
V_95 = F_31 ( V_8 ) ;
if ( ! V_95 ) {
V_97 = - V_125 ;
goto V_138;
}
switch ( V_149 -> V_150 ) {
case V_163 :
V_97 = F_75 ( V_8 , V_95 , V_96 ) ;
break;
case V_164 :
V_97 = F_96 ( V_8 , V_95 , V_96 ) ;
break;
default:
V_97 = - V_52 ;
break;
}
F_36 ( V_95 ) ;
V_138:
F_65 ( & V_84 ) ;
return V_97 ;
}
static T_8 F_131 ( char * V_165 , struct V_1 * V_8 )
{
T_8 V_166 ;
F_64 ( & V_100 ) ;
V_166 = F_132 ( V_165 , V_99 , V_8 -> V_33 ) ;
F_65 ( & V_100 ) ;
return V_166 ;
}
static T_8 F_133 ( char * V_165 , struct V_1 * V_8 )
{
T_8 V_166 ;
F_64 ( & V_100 ) ;
V_166 = F_134 ( V_165 , V_99 , V_8 -> V_35 ) ;
F_65 ( & V_100 ) ;
return V_166 ;
}
static T_9 F_135 ( struct V_2 * V_3 ,
struct V_148 * V_149 ,
struct V_167 * V_167 ,
char T_10 * V_96 ,
T_8 V_168 , T_11 * V_169 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_149 -> V_150 ;
char * V_165 ;
T_9 V_97 = 0 ;
char * V_170 ;
if ( ! ( V_165 = ( char * ) F_136 ( V_171 ) ) )
return - V_125 ;
V_170 = V_165 ;
switch ( type ) {
case V_163 :
V_170 += F_131 ( V_170 , V_8 ) ;
break;
case V_164 :
V_170 += F_133 ( V_170 , V_8 ) ;
break;
default:
V_97 = - V_52 ;
goto V_49;
}
* V_170 ++ = '\n' ;
V_97 = F_137 ( V_96 , V_168 , V_169 , V_165 , V_170 - V_165 ) ;
V_49:
F_138 ( ( unsigned long ) V_165 ) ;
return V_97 ;
}
static T_6 F_139 ( struct V_2 * V_3 , struct V_148 * V_149 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_149 -> V_150 ;
switch ( type ) {
case V_151 :
return F_10 ( V_8 ) ;
case V_152 :
return F_11 ( V_8 ) ;
case V_153 :
return F_12 ( V_8 ) ;
case V_154 :
return F_13 ( V_8 ) ;
case V_155 :
return F_14 ( V_8 ) ;
case V_156 :
return V_157 ;
case V_158 :
return F_116 ( & V_8 -> V_126 ) ;
case V_159 :
return F_15 ( V_8 ) ;
case V_160 :
return F_16 ( V_8 ) ;
default:
F_140 () ;
}
return 0 ;
}
static T_3 F_141 ( struct V_2 * V_3 , struct V_148 * V_149 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_7 type = V_149 -> V_150 ;
switch ( type ) {
case V_161 :
return V_8 -> V_59 ;
default:
F_140 () ;
}
return 0 ;
}
static struct F_3 * F_142 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
if ( ! V_3 -> V_10 )
return & V_50 . V_5 ;
V_8 = F_143 ( sizeof( * V_8 ) , V_44 ) ;
if ( ! V_8 )
return F_19 ( - V_125 ) ;
if ( ! F_33 ( & V_8 -> V_33 , V_44 ) ) {
F_34 ( V_8 ) ;
return F_19 ( - V_125 ) ;
}
F_106 ( V_17 , & V_8 -> V_13 ) ;
F_54 ( V_8 -> V_33 ) ;
F_97 ( V_8 -> V_35 ) ;
F_108 ( & V_8 -> V_126 ) ;
V_8 -> V_59 = - 1 ;
return & V_8 -> V_5 ;
}
static int F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
struct V_1 * V_10 = F_6 ( V_8 ) ;
struct V_1 * V_172 ;
struct V_2 * V_173 ;
if ( ! V_10 )
return 0 ;
F_64 ( & V_84 ) ;
F_106 ( V_12 , & V_8 -> V_13 ) ;
if ( F_15 ( V_10 ) )
F_106 ( V_19 , & V_8 -> V_13 ) ;
if ( F_16 ( V_10 ) )
F_106 ( V_20 , & V_8 -> V_13 ) ;
V_75 ++ ;
if ( ! F_9 ( V_174 , & V_3 -> V_13 ) )
goto V_138;
F_39 () ;
F_40 (tmp_cs, pos_cg, parent) {
if ( F_11 ( V_172 ) || F_10 ( V_172 ) ) {
F_44 () ;
goto V_138;
}
}
F_44 () ;
F_64 ( & V_100 ) ;
V_8 -> V_35 = V_10 -> V_35 ;
F_35 ( V_8 -> V_33 , V_10 -> V_33 ) ;
F_65 ( & V_100 ) ;
V_138:
F_65 ( & V_84 ) ;
return 0 ;
}
static void F_145 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_64 ( & V_84 ) ;
if ( F_13 ( V_8 ) )
F_105 ( V_17 , V_8 , 0 ) ;
V_75 -- ;
F_107 ( V_12 , & V_8 -> V_13 ) ;
F_65 ( & V_84 ) ;
}
static void F_146 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_37 ( V_8 -> V_33 ) ;
F_34 ( V_8 ) ;
}
int T_12 F_147 ( void )
{
int V_124 = 0 ;
if ( ! F_33 ( & V_50 . V_33 , V_44 ) )
F_140 () ;
F_148 ( V_50 . V_33 ) ;
F_149 ( V_50 . V_35 ) ;
F_108 ( & V_50 . V_126 ) ;
F_106 ( V_17 , & V_50 . V_13 ) ;
V_50 . V_59 = - 1 ;
V_124 = F_150 ( & V_175 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( ! F_33 ( & V_144 , V_44 ) )
F_140 () ;
V_75 = 1 ;
return 0 ;
}
static void F_151 ( struct V_1 * V_8 )
{
struct V_1 * V_10 ;
V_10 = F_6 ( V_8 ) ;
while ( F_42 ( V_10 -> V_33 ) ||
F_43 ( V_10 -> V_35 ) )
V_10 = F_6 ( V_10 ) ;
if ( F_152 ( V_10 -> V_5 . V_2 , V_8 -> V_5 . V_2 ) ) {
F_39 () ;
F_53 ( V_176 L_7 ,
F_153 ( V_8 -> V_5 . V_2 ) ) ;
F_44 () ;
}
}
static void F_154 ( struct V_1 * V_8 )
{
static T_13 V_177 ;
static T_1 V_178 ;
bool V_179 ;
bool V_180 = F_118 ( V_8 -> V_5 . V_2 ) ;
V_181:
F_155 ( V_147 , V_8 -> V_54 == 0 ) ;
F_64 ( & V_84 ) ;
if ( V_8 -> V_54 ) {
F_65 ( & V_84 ) ;
goto V_181;
}
F_156 ( & V_177 , V_8 -> V_33 , V_50 . V_33 ) ;
F_157 ( V_178 , V_8 -> V_35 , V_50 . V_35 ) ;
F_64 ( & V_100 ) ;
F_156 ( V_8 -> V_33 , V_8 -> V_33 , & V_177 ) ;
F_65 ( & V_100 ) ;
if ( ( V_180 && F_42 ( V_8 -> V_33 ) ) ||
( ! F_42 ( & V_177 ) && ! F_42 ( V_8 -> V_33 ) ) )
F_70 ( V_8 , NULL ) ;
F_64 ( & V_100 ) ;
F_157 ( V_8 -> V_35 , V_8 -> V_35 , V_178 ) ;
F_65 ( & V_100 ) ;
if ( ( V_180 && F_43 ( V_8 -> V_35 ) ) ||
( ! F_43 ( V_178 ) && ! F_43 ( V_8 -> V_35 ) ) )
F_94 ( V_8 , NULL ) ;
V_179 = F_42 ( V_8 -> V_33 ) ||
F_43 ( V_8 -> V_35 ) ;
F_65 ( & V_84 ) ;
if ( ! V_180 && V_179 )
F_151 ( V_8 ) ;
}
static void F_158 ( struct V_182 * V_183 )
{
static T_13 V_184 ;
static T_1 V_185 ;
bool V_186 , V_187 ;
F_64 ( & V_84 ) ;
F_35 ( & V_184 , V_85 ) ;
V_185 = V_36 [ V_37 ] ;
V_186 = ! F_60 ( V_50 . V_33 , & V_184 ) ;
V_187 = ! F_99 ( V_50 . V_35 , V_185 ) ;
if ( V_186 ) {
F_64 ( & V_100 ) ;
F_35 ( V_50 . V_33 , & V_184 ) ;
F_65 ( & V_100 ) ;
}
if ( V_187 ) {
F_64 ( & V_100 ) ;
V_50 . V_35 = V_185 ;
F_65 ( & V_100 ) ;
F_94 ( & V_50 , NULL ) ;
}
F_65 ( & V_84 ) ;
if ( V_186 || V_187 ) {
struct V_1 * V_8 ;
struct V_2 * V_62 ;
F_39 () ;
F_48 (cs, pos_cgrp, &top_cpuset) {
if ( ! F_73 ( & V_8 -> V_5 ) )
continue;
F_44 () ;
F_154 ( V_8 ) ;
F_39 () ;
F_74 ( & V_8 -> V_5 ) ;
}
F_44 () ;
}
if ( V_186 )
F_63 () ;
}
void F_159 ( bool V_188 )
{
F_61 ( 1 , NULL , NULL ) ;
F_160 ( & V_162 ) ;
}
static int F_161 ( struct V_189 * V_190 ,
unsigned long V_191 , void * V_192 )
{
F_160 ( & V_162 ) ;
return V_193 ;
}
void T_12 F_162 ( void )
{
F_35 ( V_50 . V_33 , V_85 ) ;
V_50 . V_35 = V_36 [ V_37 ] ;
V_50 . V_116 = V_50 . V_35 ;
F_163 ( & V_194 ) ;
}
void F_164 ( struct V_6 * V_38 , struct V_31 * V_32 )
{
struct V_1 * V_88 ;
F_64 ( & V_100 ) ;
F_84 ( V_38 ) ;
V_88 = F_66 ( F_4 ( V_38 ) ) ;
F_21 ( V_88 , V_32 ) ;
F_89 ( V_38 ) ;
F_65 ( & V_100 ) ;
}
void F_165 ( struct V_6 * V_38 )
{
const struct V_1 * V_88 ;
F_39 () ;
V_88 = F_66 ( F_4 ( V_38 ) ) ;
F_166 ( V_38 , V_88 -> V_33 ) ;
F_44 () ;
}
void F_167 ( void )
{
F_149 ( V_105 -> V_35 ) ;
}
T_1 F_168 ( struct V_6 * V_38 )
{
struct V_1 * V_106 ;
T_1 V_195 ;
F_64 ( & V_100 ) ;
F_84 ( V_38 ) ;
V_106 = F_67 ( F_4 ( V_38 ) ) ;
F_24 ( V_106 , & V_195 ) ;
F_89 ( V_38 ) ;
F_65 ( & V_100 ) ;
return V_195 ;
}
int F_169 ( T_1 * V_196 )
{
return F_25 ( * V_196 , V_105 -> V_35 ) ;
}
static const struct V_1 * F_170 ( const struct V_1 * V_8 )
{
while ( ! ( F_11 ( V_8 ) || F_12 ( V_8 ) ) && F_6 ( V_8 ) )
V_8 = F_6 ( V_8 ) ;
return V_8 ;
}
int F_171 ( int V_197 , T_14 V_198 )
{
const struct V_1 * V_8 ;
int V_199 ;
if ( F_172 () || ( V_198 & V_200 ) )
return 1 ;
F_173 ( ! ( V_198 & V_201 ) ) ;
if ( F_174 ( V_197 , V_105 -> V_35 ) )
return 1 ;
if ( F_82 ( F_83 ( V_110 ) ) )
return 1 ;
if ( V_198 & V_201 )
return 0 ;
if ( V_105 -> V_13 & V_111 )
return 1 ;
F_64 ( & V_100 ) ;
F_84 ( V_105 ) ;
V_8 = F_170 ( F_4 ( V_105 ) ) ;
F_89 ( V_105 ) ;
V_199 = F_174 ( V_197 , V_8 -> V_35 ) ;
F_65 ( & V_100 ) ;
return V_199 ;
}
int F_175 ( int V_197 , T_14 V_198 )
{
if ( F_172 () || ( V_198 & V_200 ) )
return 1 ;
if ( F_174 ( V_197 , V_105 -> V_35 ) )
return 1 ;
if ( F_82 ( F_83 ( V_110 ) ) )
return 1 ;
return 0 ;
}
static int F_176 ( int * V_202 )
{
int V_197 ;
V_197 = F_177 ( * V_202 , V_105 -> V_35 ) ;
if ( V_197 == V_203 )
V_197 = F_178 ( V_105 -> V_35 ) ;
* V_202 = V_197 ;
return V_197 ;
}
int F_179 ( void )
{
if ( V_105 -> V_204 == V_205 )
V_105 -> V_204 =
F_180 ( & V_105 -> V_35 ) ;
return F_176 ( & V_105 -> V_204 ) ;
}
int F_181 ( void )
{
if ( V_105 -> V_206 == V_205 )
V_105 -> V_206 =
F_180 ( & V_105 -> V_35 ) ;
return F_176 ( & V_105 -> V_206 ) ;
}
int F_182 ( const struct V_6 * V_207 ,
const struct V_6 * V_208 )
{
return F_25 ( V_207 -> V_35 , V_208 -> V_35 ) ;
}
void F_183 ( struct V_6 * V_38 )
{
static char V_209 [ V_210 ] ;
static F_184 ( V_211 ) ;
struct V_2 * V_3 = F_4 ( V_38 ) -> V_5 . V_2 ;
F_39 () ;
F_114 ( & V_211 ) ;
F_134 ( V_209 , V_210 ,
V_38 -> V_35 ) ;
F_53 ( V_212 L_8 ,
V_38 -> V_213 , F_153 ( V_3 ) , V_209 ) ;
F_115 ( & V_211 ) ;
F_44 () ;
}
void F_185 ( void )
{
F_84 ( V_105 ) ;
F_113 ( & F_4 ( V_105 ) -> V_126 ) ;
F_89 ( V_105 ) ;
}
int F_186 ( struct V_214 * V_215 , void * V_216 )
{
struct V_217 * V_217 ;
struct V_6 * V_38 ;
char * V_96 ;
struct F_3 * V_5 ;
int V_97 ;
V_97 = - V_125 ;
V_96 = F_52 ( V_99 , V_44 ) ;
if ( ! V_96 )
goto V_49;
V_97 = - V_218 ;
V_217 = V_215 -> V_150 ;
V_38 = F_187 ( V_217 , V_219 ) ;
if ( ! V_38 )
goto V_220;
F_39 () ;
V_5 = F_5 ( V_38 , V_4 ) ;
V_97 = F_188 ( V_5 -> V_2 , V_96 , V_99 ) ;
F_44 () ;
if ( V_97 < 0 )
goto V_221;
F_189 ( V_215 , V_96 ) ;
F_190 ( V_215 , '\n' ) ;
V_221:
F_191 ( V_38 ) ;
V_220:
F_34 ( V_96 ) ;
V_49:
return V_97 ;
}
void F_192 ( struct V_214 * V_215 , struct V_6 * V_7 )
{
F_193 ( V_215 , L_9 ) ;
F_194 ( V_215 , & V_7 -> V_35 ) ;
F_193 ( V_215 , L_10 ) ;
F_193 ( V_215 , L_11 ) ;
F_195 ( V_215 , & V_7 -> V_35 ) ;
F_193 ( V_215 , L_10 ) ;
}
