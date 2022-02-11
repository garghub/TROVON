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
return ( ( ( V_55 ) V_43 * V_40 -> V_28 ) >> 32 ) + 1 ;
}
static inline int
F_52 ( const struct V_1 * V_40 , T_3 V_56 )
{
return F_53 ( V_56 - 1 , & V_40 -> V_23 ) ;
}
static unsigned int
F_54 ( struct V_38 * V_39 , const struct V_57 * V_58 )
{
const struct V_19 * V_59 = V_58 -> V_60 ;
struct V_61 * V_62 ;
enum V_63 V_64 ;
T_3 V_56 ;
V_62 = F_55 ( V_39 , & V_64 ) ;
if ( V_62 == NULL )
return V_65 ;
if ( F_42 ( V_39 ) -> V_47 == V_66 &&
( V_64 == V_67 ||
V_64 == V_68 ) )
return V_69 ;
V_56 = F_41 ( V_39 , V_59 -> V_40 ) ;
switch ( V_64 ) {
case V_70 :
V_62 -> V_71 = V_56 ;
break;
case V_67 :
case V_68 :
case V_72 :
case V_73 :
break;
default:
break;
}
#ifdef F_56
F_57 ( & V_62 -> V_74 [ V_75 ] . V_76 ) ;
#endif
F_58 ( L_4 , V_56 , V_62 -> V_71 ) ;
if ( ! F_52 ( V_59 -> V_40 , V_56 ) ) {
F_58 ( L_5 ) ;
return V_65 ;
}
F_58 ( L_6 ) ;
V_39 -> V_77 = V_78 ;
return V_69 ;
}
static int F_59 ( const struct V_79 * V_58 )
{
struct V_19 * V_59 = V_58 -> V_60 ;
const struct V_80 * V_81 = V_58 -> V_82 ;
struct V_1 * V_40 ;
int V_83 ;
if ( V_59 -> V_29 != V_51 &&
V_59 -> V_29 != V_53 &&
V_59 -> V_29 != V_54 ) {
F_50 ( L_3 , V_59 -> V_29 ) ;
return - V_84 ;
}
if ( V_81 -> V_24 . V_85 . V_86 != F_60 ( 0xffffffff ) ||
V_81 -> V_24 . V_87 . V_86 == 0 ) {
F_50 ( L_7 ) ;
return - V_84 ;
}
V_40 = F_23 ( V_58 -> V_7 , V_81 -> V_24 . V_87 . V_86 , 1 ) ;
if ( ! V_40 ) {
if ( ! ( V_59 -> V_88 & V_89 ) ) {
F_50 ( L_8 ,
& V_81 -> V_24 . V_87 . V_86 ) ;
return - V_84 ;
} else {
struct V_25 * V_8 ;
if ( V_81 -> V_24 . V_90 [ 0 ] == '\0' ) {
F_50 ( L_9 ) ;
return - V_84 ;
}
V_8 = F_61 ( V_58 -> V_7 , V_81 -> V_24 . V_90 ) ;
if ( ! V_8 ) {
F_50 ( L_10 ,
V_81 -> V_24 . V_90 ) ;
return - V_91 ;
}
V_40 = F_30 ( V_59 ,
V_81 -> V_24 . V_87 . V_86 , V_8 ) ;
if ( ! V_40 ) {
F_18 ( V_8 ) ;
return - V_92 ;
}
F_62 ( V_40 -> V_8 , V_40 -> V_15 ) ;
}
}
V_59 -> V_40 = V_40 ;
V_83 = F_63 ( V_58 -> V_93 ) ;
if ( V_83 < 0 )
F_50 ( L_11 ,
V_58 -> V_93 ) ;
return V_83 ;
}
static void F_64 ( const struct V_94 * V_58 )
{
const struct V_19 * V_59 = V_58 -> V_60 ;
F_9 ( V_59 -> V_40 ) ;
F_6 ( V_59 -> V_40 ) ;
F_65 ( V_58 -> V_93 ) ;
}
static void F_66 ( struct V_95 * V_96 )
{
#define F_67 30
char V_97 [ F_67 ] ;
int V_98 , V_99 ;
for ( V_99 = 0 , V_98 = 0 ; V_99 < F_67 - 3 && V_98 < V_27 ; V_98 ++ ) {
V_97 [ V_99 ++ ] = F_68 ( V_96 -> V_100 [ V_98 ] ) ;
V_97 [ V_99 ++ ] = F_69 ( V_96 -> V_100 [ V_98 ] ) ;
V_97 [ V_99 ++ ] = ':' ;
}
V_97 [ -- V_99 ] = '\0' ;
F_58 ( L_12 ,
& V_96 -> V_101 , V_97 , & V_96 -> V_102 ) ;
}
static unsigned int
F_70 ( const struct V_103 * V_104 ,
struct V_38 * V_39 ,
const struct V_25 * V_105 ,
const struct V_25 * V_106 ,
int (* F_71)( struct V_38 * ) )
{
struct V_107 * V_108 = F_72 ( V_39 ) ;
struct V_95 * V_96 ;
struct V_1 * V_2 ;
struct V_7 * V_7 = F_10 ( V_105 ? V_105 : V_106 ) ;
if ( V_108 -> V_109 != F_73 ( V_110 ) ||
V_108 -> V_111 != F_73 ( V_112 ) ||
V_108 -> V_113 != 4 || V_108 -> V_114 != V_27 )
return V_115 ;
if ( V_108 -> V_116 != F_73 ( V_117 ) &&
V_108 -> V_116 != F_73 ( V_118 ) )
return V_115 ;
V_96 = ( void * ) ( V_108 + 1 ) ;
V_2 = F_23 ( V_7 , V_96 -> V_101 , 0 ) ;
if ( ! V_2 )
return V_115 ;
if ( V_2 -> V_8 != V_106 ) {
F_58 ( L_13
L_14 ,
V_2 -> V_8 -> V_119 , V_106 -> V_119 ) ;
F_6 ( V_2 ) ;
return V_115 ;
}
memcpy ( V_96 -> V_100 , V_2 -> V_15 , V_108 -> V_114 ) ;
#ifdef F_56
F_58 ( L_15 ) ;
F_66 ( V_96 ) ;
#endif
F_6 ( V_2 ) ;
return V_115 ;
}
static void * F_74 ( struct V_120 * V_121 , T_5 * V_122 )
{
struct V_1 * V_2 = V_121 -> V_123 ;
unsigned int V_124 ;
T_3 V_23 ;
struct V_125 * V_126 ;
V_23 = V_2 -> V_23 ;
V_124 = F_75 ( V_23 ) ;
if ( * V_122 >= V_124 )
return NULL ;
V_126 = F_76 ( sizeof( struct V_125 ) , V_127 ) ;
if ( ! V_126 )
return F_77 ( - V_92 ) ;
V_126 -> V_122 = * V_122 ;
V_126 -> V_124 = V_124 ;
V_126 -> V_128 = F_78 ( V_23 ) ;
V_126 -> V_129 = V_23 ;
F_79 ( V_126 -> V_128 - 1 , & V_126 -> V_129 ) ;
return V_126 ;
}
static void * F_80 ( struct V_120 * V_121 , void * V_130 , T_5 * V_122 )
{
struct V_125 * V_126 = V_130 ;
* V_122 = ++ V_126 -> V_122 ;
if ( * V_122 >= V_126 -> V_124 ) {
F_4 ( V_130 ) ;
return NULL ;
}
V_126 -> V_128 = F_78 ( V_126 -> V_129 ) ;
F_79 ( V_126 -> V_128 - 1 , & V_126 -> V_129 ) ;
return V_126 ;
}
static void F_81 ( struct V_120 * V_121 , void * V_130 )
{
if ( ! F_82 ( V_130 ) )
F_4 ( V_130 ) ;
}
static int F_83 ( struct V_120 * V_121 , void * V_130 )
{
struct V_125 * V_126 = V_130 ;
if ( V_126 -> V_122 != 0 )
F_84 ( V_121 , ',' ) ;
F_85 ( V_121 , L_16 , V_126 -> V_128 ) ;
if ( V_126 -> V_122 == V_126 -> V_124 - 1 )
F_84 ( V_121 , '\n' ) ;
return 0 ;
}
static int F_86 ( struct V_131 * V_131 , struct V_132 * V_132 )
{
int V_83 = F_87 ( V_132 , & V_133 ) ;
if ( ! V_83 ) {
struct V_120 * V_134 = V_132 -> V_135 ;
struct V_1 * V_2 = F_88 ( V_131 ) ;
V_134 -> V_123 = V_2 ;
F_1 ( V_2 ) ;
}
return V_83 ;
}
static int F_89 ( struct V_131 * V_131 , struct V_132 * V_132 )
{
struct V_1 * V_2 = F_88 ( V_131 ) ;
int V_83 ;
V_83 = F_90 ( V_131 , V_132 ) ;
if ( ! V_83 )
F_6 ( V_2 ) ;
return V_83 ;
}
static T_6 F_91 ( struct V_132 * V_132 , const char T_7 * V_136 ,
T_8 V_137 , T_5 * V_138 )
{
struct V_1 * V_2 = F_88 ( F_92 ( V_132 ) ) ;
#define F_93 10
char V_31 [ F_93 + 1 ] ;
unsigned long V_37 ;
int V_139 ;
if ( V_137 > F_93 )
return - V_140 ;
if ( F_94 ( V_31 , V_136 , V_137 ) )
return - V_141 ;
V_31 [ V_137 ] = 0 ;
if ( * V_31 == '+' ) {
V_139 = F_95 ( V_31 + 1 , 10 , & V_37 ) ;
if ( V_139 )
return V_139 ;
if ( F_37 ( V_2 , V_37 ) )
return - V_92 ;
} else if ( * V_31 == '-' ) {
V_139 = F_95 ( V_31 + 1 , 10 , & V_37 ) ;
if ( V_139 )
return V_139 ;
if ( F_39 ( V_2 , V_37 ) )
return - V_91 ;
} else
return - V_140 ;
return V_137 ;
}
static int F_96 ( struct V_7 * V_7 )
{
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
F_97 ( & V_10 -> V_36 ) ;
F_98 ( & V_10 -> V_13 ) ;
#ifdef F_19
V_10 -> V_34 = F_99 ( L_17 , V_7 -> V_142 ) ;
if ( ! V_10 -> V_34 ) {
F_100 ( L_18 ) ;
return - V_92 ;
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
int V_83 ;
V_83 = F_103 ( & V_143 ) ;
if ( V_83 < 0 )
return V_83 ;
V_83 = F_104 ( & V_144 ) ;
if ( V_83 < 0 )
goto V_145;
V_83 = F_105 ( & V_146 ) ;
if ( V_83 < 0 )
goto V_147;
F_50 ( L_19 ,
V_148 ) ;
return 0 ;
V_147:
F_106 ( & V_144 ) ;
V_145:
F_107 ( & V_143 ) ;
return V_83 ;
}
static void T_10 F_108 ( void )
{
F_50 ( L_20 , V_148 ) ;
F_109 ( & V_146 ) ;
F_106 ( & V_144 ) ;
F_107 ( & V_143 ) ;
F_110 () ;
}
