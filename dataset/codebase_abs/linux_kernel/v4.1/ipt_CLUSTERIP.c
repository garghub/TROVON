static inline void
F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_4 ( F_5 ( V_5 , struct V_1 , V_6 ) ) ;
}
static inline void
F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( & V_2 -> V_3 ) )
F_8 ( & V_2 -> V_6 , F_3 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_10 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
F_12 () ;
if ( F_13 ( & V_2 -> V_12 , & V_10 -> V_13 ) ) {
F_14 ( & V_2 -> V_14 ) ;
F_15 ( & V_10 -> V_13 ) ;
F_16 () ;
F_17 ( V_2 -> V_8 , V_2 -> V_15 ) ;
F_18 ( V_2 -> V_8 ) ;
#ifdef F_19
F_20 ( V_2 -> V_16 ) ;
#endif
return;
}
F_16 () ;
}
static struct V_1 *
F_21 ( struct V_7 * V_7 , T_1 V_17 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
F_22 (c, &cn->configs, list) {
if ( V_2 -> V_17 == V_17 )
return V_2 ;
}
return NULL ;
}
static inline struct V_1 *
F_23 ( struct V_7 * V_7 , T_1 V_17 , int V_18 )
{
struct V_1 * V_2 ;
F_24 () ;
V_2 = F_21 ( V_7 , V_17 ) ;
if ( V_2 ) {
if ( F_25 ( ! F_26 ( & V_2 -> V_3 ) ) )
V_2 = NULL ;
else if ( V_18 )
F_2 ( & V_2 -> V_12 ) ;
}
F_27 () ;
return V_2 ;
}
static void
F_28 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_20 -> V_22 ; V_21 ++ )
F_29 ( V_20 -> V_23 [ V_21 ] - 1 , & V_2 -> V_23 ) ;
}
static struct V_1 *
F_30 ( const struct V_19 * V_20 , T_1 V_24 ,
struct V_25 * V_8 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 = F_11 ( F_10 ( V_8 ) , V_11 ) ;
V_2 = F_31 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = V_24 ;
memcpy ( & V_2 -> V_15 , & V_20 -> V_15 , V_27 ) ;
V_2 -> V_28 = V_20 -> V_28 ;
F_28 ( V_2 , V_20 ) ;
V_2 -> V_29 = V_20 -> V_29 ;
V_2 -> V_30 = V_20 -> V_30 ;
F_32 ( & V_2 -> V_3 , 1 ) ;
F_32 ( & V_2 -> V_12 , 1 ) ;
#ifdef F_19
{
char V_31 [ 16 ] ;
sprintf ( V_31 , L_1 , & V_24 ) ;
V_2 -> V_16 = F_33 ( V_31 , V_32 | V_33 ,
V_10 -> V_34 ,
& V_35 , V_2 ) ;
if ( ! V_2 -> V_16 ) {
F_4 ( V_2 ) ;
return NULL ;
}
}
#endif
F_34 ( & V_10 -> V_13 ) ;
F_35 ( & V_2 -> V_14 , & V_10 -> V_36 ) ;
F_36 ( & V_10 -> V_13 ) ;
return V_2 ;
}
static int
F_37 ( struct V_1 * V_2 , T_2 V_37 )
{
if ( V_37 == 0 ||
V_37 > V_2 -> V_28 )
return 1 ;
if ( F_38 ( V_37 - 1 , & V_2 -> V_23 ) )
return 1 ;
return 0 ;
}
static bool
F_39 ( struct V_1 * V_2 , T_2 V_37 )
{
if ( V_37 == 0 ||
V_37 > V_2 -> V_28 )
return true ;
if ( F_40 ( V_37 - 1 , & V_2 -> V_23 ) )
return false ;
return true ;
}
static inline T_3
F_41 ( const struct V_38 * V_39 ,
const struct V_1 * V_40 )
{
const struct V_41 * V_42 = F_42 ( V_39 ) ;
unsigned long V_43 ;
T_2 V_44 = 0 , V_45 = 0 ;
int V_46 ;
V_46 = F_43 ( V_42 -> V_47 ) ;
if ( V_46 >= 0 ) {
const T_2 * V_48 ;
T_4 V_49 [ 2 ] ;
V_48 = F_44 ( V_39 , V_42 -> V_50 * 4 + V_46 , 4 , V_49 ) ;
if ( V_48 ) {
V_44 = V_48 [ 0 ] ;
V_45 = V_48 [ 1 ] ;
}
} else {
F_45 ( L_2 , V_42 -> V_47 ) ;
}
switch ( V_40 -> V_29 ) {
case V_51 :
V_43 = F_46 ( F_47 ( V_42 -> V_52 ) ,
V_40 -> V_30 ) ;
break;
case V_53 :
V_43 = F_48 ( F_47 ( V_42 -> V_52 ) , V_44 ,
V_40 -> V_30 ) ;
break;
case V_54 :
V_43 = F_49 ( F_47 ( V_42 -> V_52 ) , V_44 , V_45 ,
V_40 -> V_30 ) ;
break;
default:
V_43 = 0 ;
F_50 ( L_3 , V_40 -> V_29 ) ;
F_51 () ;
break;
}
return F_52 ( V_43 , V_40 -> V_28 ) + 1 ;
}
static inline int
F_53 ( const struct V_1 * V_40 , T_3 V_55 )
{
return F_54 ( V_55 - 1 , & V_40 -> V_23 ) ;
}
static unsigned int
F_55 ( struct V_38 * V_39 , const struct V_56 * V_57 )
{
const struct V_19 * V_58 = V_57 -> V_59 ;
struct V_60 * V_61 ;
enum V_62 V_63 ;
T_3 V_55 ;
V_61 = F_56 ( V_39 , & V_63 ) ;
if ( V_61 == NULL )
return V_64 ;
if ( F_42 ( V_39 ) -> V_47 == V_65 &&
( V_63 == V_66 ||
V_63 == V_67 ) )
return V_68 ;
V_55 = F_41 ( V_39 , V_58 -> V_40 ) ;
switch ( V_63 ) {
case V_69 :
V_61 -> V_70 = V_55 ;
break;
case V_66 :
case V_67 :
case V_71 :
case V_72 :
break;
default:
break;
}
#ifdef F_57
F_58 ( & V_61 -> V_73 [ V_74 ] . V_75 ) ;
#endif
F_59 ( L_4 , V_55 , V_61 -> V_70 ) ;
if ( ! F_53 ( V_58 -> V_40 , V_55 ) ) {
F_59 ( L_5 ) ;
return V_64 ;
}
F_59 ( L_6 ) ;
V_39 -> V_76 = V_77 ;
return V_68 ;
}
static int F_60 ( const struct V_78 * V_57 )
{
struct V_19 * V_58 = V_57 -> V_59 ;
const struct V_79 * V_80 = V_57 -> V_81 ;
struct V_1 * V_40 ;
int V_82 ;
if ( V_58 -> V_29 != V_51 &&
V_58 -> V_29 != V_53 &&
V_58 -> V_29 != V_54 ) {
F_50 ( L_3 , V_58 -> V_29 ) ;
return - V_83 ;
}
if ( V_80 -> V_24 . V_84 . V_85 != F_61 ( 0xffffffff ) ||
V_80 -> V_24 . V_86 . V_85 == 0 ) {
F_50 ( L_7 ) ;
return - V_83 ;
}
V_40 = F_23 ( V_57 -> V_7 , V_80 -> V_24 . V_86 . V_85 , 1 ) ;
if ( ! V_40 ) {
if ( ! ( V_58 -> V_87 & V_88 ) ) {
F_50 ( L_8 ,
& V_80 -> V_24 . V_86 . V_85 ) ;
return - V_83 ;
} else {
struct V_25 * V_8 ;
if ( V_80 -> V_24 . V_89 [ 0 ] == '\0' ) {
F_50 ( L_9 ) ;
return - V_83 ;
}
V_8 = F_62 ( V_57 -> V_7 , V_80 -> V_24 . V_89 ) ;
if ( ! V_8 ) {
F_50 ( L_10 ,
V_80 -> V_24 . V_89 ) ;
return - V_90 ;
}
V_40 = F_30 ( V_58 ,
V_80 -> V_24 . V_86 . V_85 , V_8 ) ;
if ( ! V_40 ) {
F_18 ( V_8 ) ;
return - V_91 ;
}
F_63 ( V_40 -> V_8 , V_40 -> V_15 ) ;
}
}
V_58 -> V_40 = V_40 ;
V_82 = F_64 ( V_57 -> V_92 ) ;
if ( V_82 < 0 )
F_50 ( L_11 ,
V_57 -> V_92 ) ;
if ( ! V_57 -> V_7 -> V_93 . V_94 ) {
F_50 ( L_12
L_13 ) ;
V_57 -> V_7 -> V_93 . V_94 = true ;
}
return V_82 ;
}
static void F_65 ( const struct V_95 * V_57 )
{
const struct V_19 * V_58 = V_57 -> V_59 ;
F_9 ( V_58 -> V_40 ) ;
F_6 ( V_58 -> V_40 ) ;
F_66 ( V_57 -> V_92 ) ;
}
static void F_67 ( struct V_96 * V_97 )
{
#define F_68 30
char V_98 [ F_68 ] ;
int V_99 , V_100 ;
for ( V_100 = 0 , V_99 = 0 ; V_100 < F_68 - 3 && V_99 < V_27 ; V_99 ++ ) {
V_98 [ V_100 ++ ] = F_69 ( V_97 -> V_101 [ V_99 ] ) ;
V_98 [ V_100 ++ ] = F_70 ( V_97 -> V_101 [ V_99 ] ) ;
V_98 [ V_100 ++ ] = ':' ;
}
V_98 [ -- V_100 ] = '\0' ;
F_59 ( L_14 ,
& V_97 -> V_102 , V_98 , & V_97 -> V_103 ) ;
}
static unsigned int
F_71 ( const struct V_104 * V_105 ,
struct V_38 * V_39 ,
const struct V_106 * V_107 )
{
struct V_108 * V_109 = F_72 ( V_39 ) ;
struct V_96 * V_97 ;
struct V_1 * V_2 ;
struct V_7 * V_7 = F_10 ( V_107 -> V_110 ? V_107 -> V_110 : V_107 -> V_111 ) ;
if ( V_109 -> V_112 != F_73 ( V_113 ) ||
V_109 -> V_114 != F_73 ( V_115 ) ||
V_109 -> V_116 != 4 || V_109 -> V_117 != V_27 )
return V_118 ;
if ( V_109 -> V_119 != F_73 ( V_120 ) &&
V_109 -> V_119 != F_73 ( V_121 ) )
return V_118 ;
V_97 = ( void * ) ( V_109 + 1 ) ;
V_2 = F_23 ( V_7 , V_97 -> V_102 , 0 ) ;
if ( ! V_2 )
return V_118 ;
if ( V_2 -> V_8 != V_107 -> V_111 ) {
F_59 ( L_15
L_16 ,
V_2 -> V_8 -> V_122 , V_107 -> V_111 -> V_122 ) ;
F_6 ( V_2 ) ;
return V_118 ;
}
memcpy ( V_97 -> V_101 , V_2 -> V_15 , V_109 -> V_117 ) ;
#ifdef F_57
F_59 ( L_17 ) ;
F_67 ( V_97 ) ;
#endif
F_6 ( V_2 ) ;
return V_118 ;
}
static void * F_74 ( struct V_123 * V_124 , T_5 * V_125 )
{
struct V_1 * V_2 = V_124 -> V_126 ;
unsigned int V_127 ;
T_3 V_23 ;
struct V_128 * V_129 ;
V_23 = V_2 -> V_23 ;
V_127 = F_75 ( V_23 ) ;
if ( * V_125 >= V_127 )
return NULL ;
V_129 = F_76 ( sizeof( struct V_128 ) , V_130 ) ;
if ( ! V_129 )
return F_77 ( - V_91 ) ;
V_129 -> V_125 = * V_125 ;
V_129 -> V_127 = V_127 ;
V_129 -> V_131 = F_78 ( V_23 ) ;
V_129 -> V_132 = V_23 ;
F_79 ( V_129 -> V_131 - 1 , & V_129 -> V_132 ) ;
return V_129 ;
}
static void * F_80 ( struct V_123 * V_124 , void * V_133 , T_5 * V_125 )
{
struct V_128 * V_129 = V_133 ;
* V_125 = ++ V_129 -> V_125 ;
if ( * V_125 >= V_129 -> V_127 ) {
F_4 ( V_133 ) ;
return NULL ;
}
V_129 -> V_131 = F_78 ( V_129 -> V_132 ) ;
F_79 ( V_129 -> V_131 - 1 , & V_129 -> V_132 ) ;
return V_129 ;
}
static void F_81 ( struct V_123 * V_124 , void * V_133 )
{
if ( ! F_82 ( V_133 ) )
F_4 ( V_133 ) ;
}
static int F_83 ( struct V_123 * V_124 , void * V_133 )
{
struct V_128 * V_129 = V_133 ;
if ( V_129 -> V_125 != 0 )
F_84 ( V_124 , ',' ) ;
F_85 ( V_124 , L_18 , V_129 -> V_131 ) ;
if ( V_129 -> V_125 == V_129 -> V_127 - 1 )
F_84 ( V_124 , '\n' ) ;
return 0 ;
}
static int F_86 ( struct V_134 * V_134 , struct V_135 * V_135 )
{
int V_82 = F_87 ( V_135 , & V_136 ) ;
if ( ! V_82 ) {
struct V_123 * V_137 = V_135 -> V_138 ;
struct V_1 * V_2 = F_88 ( V_134 ) ;
V_137 -> V_126 = V_2 ;
F_1 ( V_2 ) ;
}
return V_82 ;
}
static int F_89 ( struct V_134 * V_134 , struct V_135 * V_135 )
{
struct V_1 * V_2 = F_88 ( V_134 ) ;
int V_82 ;
V_82 = F_90 ( V_134 , V_135 ) ;
if ( ! V_82 )
F_6 ( V_2 ) ;
return V_82 ;
}
static T_6 F_91 ( struct V_135 * V_135 , const char T_7 * V_139 ,
T_8 V_140 , T_5 * V_141 )
{
struct V_1 * V_2 = F_88 ( F_92 ( V_135 ) ) ;
#define F_93 10
char V_31 [ F_93 + 1 ] ;
unsigned long V_37 ;
int V_142 ;
if ( V_140 > F_93 )
return - V_143 ;
if ( F_94 ( V_31 , V_139 , V_140 ) )
return - V_144 ;
V_31 [ V_140 ] = 0 ;
if ( * V_31 == '+' ) {
V_142 = F_95 ( V_31 + 1 , 10 , & V_37 ) ;
if ( V_142 )
return V_142 ;
if ( F_37 ( V_2 , V_37 ) )
return - V_91 ;
} else if ( * V_31 == '-' ) {
V_142 = F_95 ( V_31 + 1 , 10 , & V_37 ) ;
if ( V_142 )
return V_142 ;
if ( F_39 ( V_2 , V_37 ) )
return - V_90 ;
} else
return - V_143 ;
return V_140 ;
}
static int F_96 ( struct V_7 * V_7 )
{
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
F_97 ( & V_10 -> V_36 ) ;
F_98 ( & V_10 -> V_13 ) ;
#ifdef F_19
V_10 -> V_34 = F_99 ( L_19 , V_7 -> V_145 ) ;
if ( ! V_10 -> V_34 ) {
F_100 ( L_20 ) ;
return - V_91 ;
}
#endif
return 0 ;
}
static void F_101 ( struct V_7 * V_7 )
{
#ifdef F_19
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
F_20 ( V_10 -> V_34 ) ;
#endif
}
static int T_9 F_102 ( void )
{
int V_82 ;
V_82 = F_103 ( & V_146 ) ;
if ( V_82 < 0 )
return V_82 ;
V_82 = F_104 ( & V_147 ) ;
if ( V_82 < 0 )
goto V_148;
V_82 = F_105 ( & V_149 ) ;
if ( V_82 < 0 )
goto V_150;
F_50 ( L_21 ,
V_151 ) ;
return 0 ;
V_150:
F_106 ( & V_147 ) ;
V_148:
F_107 ( & V_146 ) ;
return V_82 ;
}
static void T_10 F_108 ( void )
{
F_50 ( L_22 , V_151 ) ;
F_109 ( & V_149 ) ;
F_106 ( & V_147 ) ;
F_107 ( & V_146 ) ;
F_110 () ;
}
