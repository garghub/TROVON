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
#ifdef F_19
if ( ! V_2 -> V_16 )
V_2 = NULL ;
else
#endif
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
struct V_7 * V_7 = F_10 ( V_8 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
V_2 = F_31 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return F_32 ( - V_27 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = V_24 ;
memcpy ( & V_2 -> V_15 , & V_20 -> V_15 , V_28 ) ;
V_2 -> V_29 = V_20 -> V_29 ;
F_28 ( V_2 , V_20 ) ;
V_2 -> V_30 = V_20 -> V_30 ;
V_2 -> V_31 = V_20 -> V_31 ;
F_33 ( & V_2 -> V_3 , 1 ) ;
F_33 ( & V_2 -> V_12 , 1 ) ;
F_34 ( & V_10 -> V_13 ) ;
if ( F_21 ( V_7 , V_24 ) ) {
F_35 ( & V_10 -> V_13 ) ;
F_4 ( V_2 ) ;
return F_32 ( - V_32 ) ;
}
F_36 ( & V_2 -> V_14 , & V_10 -> V_33 ) ;
F_35 ( & V_10 -> V_13 ) ;
#ifdef F_19
{
char V_34 [ 16 ] ;
sprintf ( V_34 , L_1 , & V_24 ) ;
V_2 -> V_16 = F_37 ( V_34 , V_35 | V_36 ,
V_10 -> V_37 ,
& V_38 , V_2 ) ;
if ( ! V_2 -> V_16 ) {
F_34 ( & V_10 -> V_13 ) ;
F_14 ( & V_2 -> V_14 ) ;
F_35 ( & V_10 -> V_13 ) ;
F_4 ( V_2 ) ;
return F_32 ( - V_27 ) ;
}
}
#endif
return V_2 ;
}
static int
F_38 ( struct V_1 * V_2 , T_2 V_39 )
{
if ( V_39 == 0 ||
V_39 > V_2 -> V_29 )
return 1 ;
if ( F_39 ( V_39 - 1 , & V_2 -> V_23 ) )
return 1 ;
return 0 ;
}
static bool
F_40 ( struct V_1 * V_2 , T_2 V_39 )
{
if ( V_39 == 0 ||
V_39 > V_2 -> V_29 )
return true ;
if ( F_41 ( V_39 - 1 , & V_2 -> V_23 ) )
return false ;
return true ;
}
static inline T_3
F_42 ( const struct V_40 * V_41 ,
const struct V_1 * V_42 )
{
const struct V_43 * V_44 = F_43 ( V_41 ) ;
unsigned long V_45 ;
T_2 V_46 = 0 , V_47 = 0 ;
int V_48 ;
V_48 = F_44 ( V_44 -> V_49 ) ;
if ( V_48 >= 0 ) {
const T_2 * V_50 ;
T_4 V_51 [ 2 ] ;
V_50 = F_45 ( V_41 , V_44 -> V_52 * 4 + V_48 , 4 , V_51 ) ;
if ( V_50 ) {
V_46 = V_50 [ 0 ] ;
V_47 = V_50 [ 1 ] ;
}
} else {
F_46 ( L_2 , V_44 -> V_49 ) ;
}
switch ( V_42 -> V_30 ) {
case V_53 :
V_45 = F_47 ( F_48 ( V_44 -> V_54 ) ,
V_42 -> V_31 ) ;
break;
case V_55 :
V_45 = F_49 ( F_48 ( V_44 -> V_54 ) , V_46 ,
V_42 -> V_31 ) ;
break;
case V_56 :
V_45 = F_50 ( F_48 ( V_44 -> V_54 ) , V_46 , V_47 ,
V_42 -> V_31 ) ;
break;
default:
V_45 = 0 ;
F_51 ( L_3 , V_42 -> V_30 ) ;
F_52 () ;
break;
}
return F_53 ( V_45 , V_42 -> V_29 ) + 1 ;
}
static inline int
F_54 ( const struct V_1 * V_42 , T_3 V_57 )
{
return F_55 ( V_57 - 1 , & V_42 -> V_23 ) ;
}
static unsigned int
F_56 ( struct V_40 * V_41 , const struct V_58 * V_59 )
{
const struct V_19 * V_60 = V_59 -> V_61 ;
struct V_62 * V_63 ;
enum V_64 V_65 ;
T_3 V_57 ;
V_63 = F_57 ( V_41 , & V_65 ) ;
if ( V_63 == NULL )
return V_66 ;
if ( F_43 ( V_41 ) -> V_49 == V_67 &&
( V_65 == V_68 ||
V_65 == V_69 ) )
return V_70 ;
V_57 = F_42 ( V_41 , V_60 -> V_42 ) ;
switch ( V_65 ) {
case V_71 :
V_63 -> V_72 = V_57 ;
break;
case V_68 :
case V_69 :
case V_73 :
case V_74 :
break;
default:
break;
}
#ifdef F_58
F_59 ( & V_63 -> V_75 [ V_76 ] . V_77 ) ;
#endif
F_60 ( L_4 , V_57 , V_63 -> V_72 ) ;
if ( ! F_54 ( V_60 -> V_42 , V_57 ) ) {
F_60 ( L_5 ) ;
return V_66 ;
}
F_60 ( L_6 ) ;
V_41 -> V_78 = V_79 ;
return V_70 ;
}
static int F_61 ( const struct V_80 * V_59 )
{
struct V_19 * V_60 = V_59 -> V_61 ;
const struct V_81 * V_82 = V_59 -> V_83 ;
struct V_1 * V_42 ;
int V_84 ;
if ( V_59 -> V_85 ) {
F_62 ( L_7 ) ;
return - V_86 ;
}
if ( V_60 -> V_30 != V_53 &&
V_60 -> V_30 != V_55 &&
V_60 -> V_30 != V_56 ) {
F_51 ( L_3 , V_60 -> V_30 ) ;
return - V_87 ;
}
if ( V_82 -> V_24 . V_88 . V_89 != F_63 ( 0xffffffff ) ||
V_82 -> V_24 . V_90 . V_89 == 0 ) {
F_51 ( L_8 ) ;
return - V_87 ;
}
V_42 = F_23 ( V_59 -> V_7 , V_82 -> V_24 . V_90 . V_89 , 1 ) ;
if ( ! V_42 ) {
if ( ! ( V_60 -> V_91 & V_92 ) ) {
F_51 ( L_9 ,
& V_82 -> V_24 . V_90 . V_89 ) ;
return - V_87 ;
} else {
struct V_25 * V_8 ;
if ( V_82 -> V_24 . V_93 [ 0 ] == '\0' ) {
F_51 ( L_10 ) ;
return - V_87 ;
}
V_8 = F_64 ( V_59 -> V_7 , V_82 -> V_24 . V_93 ) ;
if ( ! V_8 ) {
F_51 ( L_11 ,
V_82 -> V_24 . V_93 ) ;
return - V_94 ;
}
V_42 = F_30 ( V_60 ,
V_82 -> V_24 . V_90 . V_89 , V_8 ) ;
if ( F_65 ( V_42 ) ) {
F_18 ( V_8 ) ;
return F_66 ( V_42 ) ;
}
F_67 ( V_42 -> V_8 , V_42 -> V_15 ) ;
}
}
V_60 -> V_42 = V_42 ;
V_84 = F_68 ( V_59 -> V_7 , V_59 -> V_95 ) ;
if ( V_84 < 0 )
F_51 ( L_12 ,
V_59 -> V_95 ) ;
if ( ! V_59 -> V_7 -> V_96 . V_97 ) {
F_51 ( L_13
L_14 ) ;
V_59 -> V_7 -> V_96 . V_97 = true ;
}
return V_84 ;
}
static void F_69 ( const struct V_98 * V_59 )
{
const struct V_19 * V_60 = V_59 -> V_61 ;
F_9 ( V_60 -> V_42 ) ;
F_6 ( V_60 -> V_42 ) ;
F_68 ( V_59 -> V_7 , V_59 -> V_95 ) ;
}
static void F_70 ( struct V_99 * V_100 )
{
#define F_71 30
char V_101 [ F_71 ] ;
int V_102 , V_103 ;
for ( V_103 = 0 , V_102 = 0 ; V_103 < F_71 - 3 && V_102 < V_28 ; V_102 ++ ) {
V_101 [ V_103 ++ ] = F_72 ( V_100 -> V_104 [ V_102 ] ) ;
V_101 [ V_103 ++ ] = F_73 ( V_100 -> V_104 [ V_102 ] ) ;
V_101 [ V_103 ++ ] = ':' ;
}
V_101 [ -- V_103 ] = '\0' ;
F_60 ( L_15 ,
& V_100 -> V_105 , V_101 , & V_100 -> V_106 ) ;
}
static unsigned int
F_74 ( void * V_107 ,
struct V_40 * V_41 ,
const struct V_108 * V_109 )
{
struct V_110 * V_111 = F_75 ( V_41 ) ;
struct V_99 * V_100 ;
struct V_1 * V_2 ;
struct V_7 * V_7 = V_109 -> V_7 ;
if ( V_111 -> V_112 != F_76 ( V_113 ) ||
V_111 -> V_114 != F_76 ( V_115 ) ||
V_111 -> V_116 != 4 || V_111 -> V_117 != V_28 )
return V_118 ;
if ( V_111 -> V_119 != F_76 ( V_120 ) &&
V_111 -> V_119 != F_76 ( V_121 ) )
return V_118 ;
V_100 = ( void * ) ( V_111 + 1 ) ;
V_2 = F_23 ( V_7 , V_100 -> V_105 , 0 ) ;
if ( ! V_2 )
return V_118 ;
if ( V_2 -> V_8 != V_109 -> V_122 ) {
F_60 ( L_16
L_17 ,
V_2 -> V_8 -> V_123 , V_109 -> V_122 -> V_123 ) ;
F_6 ( V_2 ) ;
return V_118 ;
}
memcpy ( V_100 -> V_104 , V_2 -> V_15 , V_111 -> V_117 ) ;
#ifdef F_58
F_60 ( L_18 ) ;
F_70 ( V_100 ) ;
#endif
F_6 ( V_2 ) ;
return V_118 ;
}
static void * F_77 ( struct V_124 * V_125 , T_5 * V_126 )
{
struct V_1 * V_2 = V_125 -> V_127 ;
unsigned int V_128 ;
T_3 V_23 ;
struct V_129 * V_130 ;
V_23 = V_2 -> V_23 ;
V_128 = F_78 ( V_23 ) ;
if ( * V_126 >= V_128 )
return NULL ;
V_130 = F_79 ( sizeof( struct V_129 ) , V_131 ) ;
if ( ! V_130 )
return F_32 ( - V_27 ) ;
V_130 -> V_126 = * V_126 ;
V_130 -> V_128 = V_128 ;
V_130 -> V_132 = F_80 ( V_23 ) ;
V_130 -> V_133 = V_23 ;
F_81 ( V_130 -> V_132 - 1 , & V_130 -> V_133 ) ;
return V_130 ;
}
static void * F_82 ( struct V_124 * V_125 , void * V_134 , T_5 * V_126 )
{
struct V_129 * V_130 = V_134 ;
* V_126 = ++ V_130 -> V_126 ;
if ( * V_126 >= V_130 -> V_128 ) {
F_4 ( V_134 ) ;
return NULL ;
}
V_130 -> V_132 = F_80 ( V_130 -> V_133 ) ;
F_81 ( V_130 -> V_132 - 1 , & V_130 -> V_133 ) ;
return V_130 ;
}
static void F_83 ( struct V_124 * V_125 , void * V_134 )
{
if ( ! F_65 ( V_134 ) )
F_4 ( V_134 ) ;
}
static int F_84 ( struct V_124 * V_125 , void * V_134 )
{
struct V_129 * V_130 = V_134 ;
if ( V_130 -> V_126 != 0 )
F_85 ( V_125 , ',' ) ;
F_86 ( V_125 , L_19 , V_130 -> V_132 ) ;
if ( V_130 -> V_126 == V_130 -> V_128 - 1 )
F_85 ( V_125 , '\n' ) ;
return 0 ;
}
static int F_87 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
int V_84 = F_88 ( V_136 , & V_137 ) ;
if ( ! V_84 ) {
struct V_124 * V_138 = V_136 -> V_139 ;
struct V_1 * V_2 = F_89 ( V_135 ) ;
V_138 -> V_127 = V_2 ;
F_1 ( V_2 ) ;
}
return V_84 ;
}
static int F_90 ( struct V_135 * V_135 , struct V_136 * V_136 )
{
struct V_1 * V_2 = F_89 ( V_135 ) ;
int V_84 ;
V_84 = F_91 ( V_135 , V_136 ) ;
if ( ! V_84 )
F_6 ( V_2 ) ;
return V_84 ;
}
static T_6 F_92 ( struct V_136 * V_136 , const char T_7 * V_140 ,
T_8 V_141 , T_5 * V_142 )
{
struct V_1 * V_2 = F_89 ( F_93 ( V_136 ) ) ;
#define F_94 10
char V_34 [ F_94 + 1 ] ;
unsigned long V_39 ;
int V_143 ;
if ( V_141 > F_94 )
return - V_144 ;
if ( F_95 ( V_34 , V_140 , V_141 ) )
return - V_145 ;
V_34 [ V_141 ] = 0 ;
if ( * V_34 == '+' ) {
V_143 = F_96 ( V_34 + 1 , 10 , & V_39 ) ;
if ( V_143 )
return V_143 ;
if ( F_38 ( V_2 , V_39 ) )
return - V_27 ;
} else if ( * V_34 == '-' ) {
V_143 = F_96 ( V_34 + 1 , 10 , & V_39 ) ;
if ( V_143 )
return V_143 ;
if ( F_40 ( V_2 , V_39 ) )
return - V_94 ;
} else
return - V_144 ;
return V_141 ;
}
static int F_97 ( struct V_7 * V_7 )
{
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
F_98 ( & V_10 -> V_33 ) ;
F_99 ( & V_10 -> V_13 ) ;
#ifdef F_19
V_10 -> V_37 = F_100 ( L_20 , V_7 -> V_146 ) ;
if ( ! V_10 -> V_37 ) {
F_62 ( L_21 ) ;
return - V_27 ;
}
#endif
return 0 ;
}
static void F_101 ( struct V_7 * V_7 )
{
#ifdef F_19
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
F_20 ( V_10 -> V_37 ) ;
#endif
}
static int T_9 F_102 ( void )
{
int V_84 ;
V_84 = F_103 ( & V_147 ) ;
if ( V_84 < 0 )
return V_84 ;
V_84 = F_104 ( & V_148 ) ;
if ( V_84 < 0 )
goto V_149;
V_84 = F_105 ( & V_150 ) ;
if ( V_84 < 0 )
goto V_151;
F_51 ( L_22 ,
V_152 ) ;
return 0 ;
V_151:
F_106 ( & V_148 ) ;
V_149:
F_107 ( & V_147 ) ;
return V_84 ;
}
static void T_10 F_108 ( void )
{
F_51 ( L_23 , V_152 ) ;
F_109 ( & V_150 ) ;
F_106 ( & V_148 ) ;
F_107 ( & V_147 ) ;
F_110 () ;
}
