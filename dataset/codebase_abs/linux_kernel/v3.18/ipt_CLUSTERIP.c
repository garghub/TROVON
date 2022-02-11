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
return V_82 ;
}
static void F_65 ( const struct V_93 * V_57 )
{
const struct V_19 * V_58 = V_57 -> V_59 ;
F_9 ( V_58 -> V_40 ) ;
F_6 ( V_58 -> V_40 ) ;
F_66 ( V_57 -> V_92 ) ;
}
static void F_67 ( struct V_94 * V_95 )
{
#define F_68 30
char V_96 [ F_68 ] ;
int V_97 , V_98 ;
for ( V_98 = 0 , V_97 = 0 ; V_98 < F_68 - 3 && V_97 < V_27 ; V_97 ++ ) {
V_96 [ V_98 ++ ] = F_69 ( V_95 -> V_99 [ V_97 ] ) ;
V_96 [ V_98 ++ ] = F_70 ( V_95 -> V_99 [ V_97 ] ) ;
V_96 [ V_98 ++ ] = ':' ;
}
V_96 [ -- V_98 ] = '\0' ;
F_59 ( L_12 ,
& V_95 -> V_100 , V_96 , & V_95 -> V_101 ) ;
}
static unsigned int
F_71 ( const struct V_102 * V_103 ,
struct V_38 * V_39 ,
const struct V_25 * V_104 ,
const struct V_25 * V_105 ,
int (* F_72)( struct V_38 * ) )
{
struct V_106 * V_107 = F_73 ( V_39 ) ;
struct V_94 * V_95 ;
struct V_1 * V_2 ;
struct V_7 * V_7 = F_10 ( V_104 ? V_104 : V_105 ) ;
if ( V_107 -> V_108 != F_74 ( V_109 ) ||
V_107 -> V_110 != F_74 ( V_111 ) ||
V_107 -> V_112 != 4 || V_107 -> V_113 != V_27 )
return V_114 ;
if ( V_107 -> V_115 != F_74 ( V_116 ) &&
V_107 -> V_115 != F_74 ( V_117 ) )
return V_114 ;
V_95 = ( void * ) ( V_107 + 1 ) ;
V_2 = F_23 ( V_7 , V_95 -> V_100 , 0 ) ;
if ( ! V_2 )
return V_114 ;
if ( V_2 -> V_8 != V_105 ) {
F_59 ( L_13
L_14 ,
V_2 -> V_8 -> V_118 , V_105 -> V_118 ) ;
F_6 ( V_2 ) ;
return V_114 ;
}
memcpy ( V_95 -> V_99 , V_2 -> V_15 , V_107 -> V_113 ) ;
#ifdef F_57
F_59 ( L_15 ) ;
F_67 ( V_95 ) ;
#endif
F_6 ( V_2 ) ;
return V_114 ;
}
static void * F_75 ( struct V_119 * V_120 , T_5 * V_121 )
{
struct V_1 * V_2 = V_120 -> V_122 ;
unsigned int V_123 ;
T_3 V_23 ;
struct V_124 * V_125 ;
V_23 = V_2 -> V_23 ;
V_123 = F_76 ( V_23 ) ;
if ( * V_121 >= V_123 )
return NULL ;
V_125 = F_77 ( sizeof( struct V_124 ) , V_126 ) ;
if ( ! V_125 )
return F_78 ( - V_91 ) ;
V_125 -> V_121 = * V_121 ;
V_125 -> V_123 = V_123 ;
V_125 -> V_127 = F_79 ( V_23 ) ;
V_125 -> V_128 = V_23 ;
F_80 ( V_125 -> V_127 - 1 , & V_125 -> V_128 ) ;
return V_125 ;
}
static void * F_81 ( struct V_119 * V_120 , void * V_129 , T_5 * V_121 )
{
struct V_124 * V_125 = V_129 ;
* V_121 = ++ V_125 -> V_121 ;
if ( * V_121 >= V_125 -> V_123 ) {
F_4 ( V_129 ) ;
return NULL ;
}
V_125 -> V_127 = F_79 ( V_125 -> V_128 ) ;
F_80 ( V_125 -> V_127 - 1 , & V_125 -> V_128 ) ;
return V_125 ;
}
static void F_82 ( struct V_119 * V_120 , void * V_129 )
{
if ( ! F_83 ( V_129 ) )
F_4 ( V_129 ) ;
}
static int F_84 ( struct V_119 * V_120 , void * V_129 )
{
struct V_124 * V_125 = V_129 ;
if ( V_125 -> V_121 != 0 )
F_85 ( V_120 , ',' ) ;
F_86 ( V_120 , L_16 , V_125 -> V_127 ) ;
if ( V_125 -> V_121 == V_125 -> V_123 - 1 )
F_85 ( V_120 , '\n' ) ;
return 0 ;
}
static int F_87 ( struct V_130 * V_130 , struct V_131 * V_131 )
{
int V_82 = F_88 ( V_131 , & V_132 ) ;
if ( ! V_82 ) {
struct V_119 * V_133 = V_131 -> V_134 ;
struct V_1 * V_2 = F_89 ( V_130 ) ;
V_133 -> V_122 = V_2 ;
F_1 ( V_2 ) ;
}
return V_82 ;
}
static int F_90 ( struct V_130 * V_130 , struct V_131 * V_131 )
{
struct V_1 * V_2 = F_89 ( V_130 ) ;
int V_82 ;
V_82 = F_91 ( V_130 , V_131 ) ;
if ( ! V_82 )
F_6 ( V_2 ) ;
return V_82 ;
}
static T_6 F_92 ( struct V_131 * V_131 , const char T_7 * V_135 ,
T_8 V_136 , T_5 * V_137 )
{
struct V_1 * V_2 = F_89 ( F_93 ( V_131 ) ) ;
#define F_94 10
char V_31 [ F_94 + 1 ] ;
unsigned long V_37 ;
int V_138 ;
if ( V_136 > F_94 )
return - V_139 ;
if ( F_95 ( V_31 , V_135 , V_136 ) )
return - V_140 ;
V_31 [ V_136 ] = 0 ;
if ( * V_31 == '+' ) {
V_138 = F_96 ( V_31 + 1 , 10 , & V_37 ) ;
if ( V_138 )
return V_138 ;
if ( F_37 ( V_2 , V_37 ) )
return - V_91 ;
} else if ( * V_31 == '-' ) {
V_138 = F_96 ( V_31 + 1 , 10 , & V_37 ) ;
if ( V_138 )
return V_138 ;
if ( F_39 ( V_2 , V_37 ) )
return - V_90 ;
} else
return - V_139 ;
return V_136 ;
}
static int F_97 ( struct V_7 * V_7 )
{
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
F_98 ( & V_10 -> V_36 ) ;
F_99 ( & V_10 -> V_13 ) ;
#ifdef F_19
V_10 -> V_34 = F_100 ( L_17 , V_7 -> V_141 ) ;
if ( ! V_10 -> V_34 ) {
F_101 ( L_18 ) ;
return - V_91 ;
}
#endif
return 0 ;
}
static void F_102 ( struct V_7 * V_7 )
{
#ifdef F_19
struct V_9 * V_10 = F_11 ( V_7 , V_11 ) ;
F_20 ( V_10 -> V_34 ) ;
#endif
}
static int T_9 F_103 ( void )
{
int V_82 ;
V_82 = F_104 ( & V_142 ) ;
if ( V_82 < 0 )
return V_82 ;
V_82 = F_105 ( & V_143 ) ;
if ( V_82 < 0 )
goto V_144;
V_82 = F_106 ( & V_145 ) ;
if ( V_82 < 0 )
goto V_146;
F_50 ( L_19 ,
V_147 ) ;
return 0 ;
V_146:
F_107 ( & V_143 ) ;
V_144:
F_108 ( & V_142 ) ;
return V_82 ;
}
static void T_10 F_109 ( void )
{
F_50 ( L_20 , V_147 ) ;
F_110 ( & V_145 ) ;
F_107 ( & V_143 ) ;
F_108 ( & V_142 ) ;
F_111 () ;
}
