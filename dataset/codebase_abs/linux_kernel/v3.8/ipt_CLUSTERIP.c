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
F_10 () ;
if ( F_11 ( & V_2 -> V_7 , & V_8 ) ) {
F_12 ( & V_2 -> V_9 ) ;
F_13 ( & V_8 ) ;
F_14 () ;
F_15 ( V_2 -> V_10 , V_2 -> V_11 ) ;
F_16 ( V_2 -> V_10 ) ;
#ifdef F_17
F_18 ( V_2 -> V_12 -> V_13 , V_2 -> V_12 -> V_14 ) ;
#endif
return;
}
F_14 () ;
}
static struct V_1 *
F_19 ( T_1 V_15 )
{
struct V_1 * V_2 ;
F_20 (c, &clusterip_configs, list) {
if ( V_2 -> V_15 == V_15 )
return V_2 ;
}
return NULL ;
}
static inline struct V_1 *
F_21 ( T_1 V_15 , int V_16 )
{
struct V_1 * V_2 ;
F_22 () ;
V_2 = F_19 ( V_15 ) ;
if ( V_2 ) {
if ( F_23 ( ! F_24 ( & V_2 -> V_3 ) ) )
V_2 = NULL ;
else if ( V_16 )
F_2 ( & V_2 -> V_7 ) ;
}
F_25 () ;
return V_2 ;
}
static void
F_26 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_20 ; V_19 ++ )
F_27 ( V_18 -> V_21 [ V_19 ] - 1 , & V_2 -> V_21 ) ;
}
static struct V_1 *
F_28 ( const struct V_17 * V_18 , T_1 V_22 ,
struct V_23 * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_10 = V_10 ;
V_2 -> V_15 = V_22 ;
memcpy ( & V_2 -> V_11 , & V_18 -> V_11 , V_25 ) ;
V_2 -> V_26 = V_18 -> V_26 ;
F_26 ( V_2 , V_18 ) ;
V_2 -> V_27 = V_18 -> V_27 ;
V_2 -> V_28 = V_18 -> V_28 ;
F_30 ( & V_2 -> V_3 , 1 ) ;
F_30 ( & V_2 -> V_7 , 1 ) ;
#ifdef F_17
{
char V_29 [ 16 ] ;
sprintf ( V_29 , L_1 , & V_22 ) ;
V_2 -> V_12 = F_31 ( V_29 , V_30 | V_31 ,
V_32 ,
& V_33 , V_2 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 ) ;
return NULL ;
}
}
#endif
F_32 ( & V_8 ) ;
F_33 ( & V_2 -> V_9 , & V_34 ) ;
F_34 ( & V_8 ) ;
return V_2 ;
}
static int
F_35 ( struct V_1 * V_2 , T_2 V_35 )
{
if ( V_35 == 0 ||
V_35 > V_2 -> V_26 )
return 1 ;
if ( F_36 ( V_35 - 1 , & V_2 -> V_21 ) )
return 1 ;
return 0 ;
}
static bool
F_37 ( struct V_1 * V_2 , T_2 V_35 )
{
if ( V_35 == 0 ||
V_35 > V_2 -> V_26 )
return true ;
if ( F_38 ( V_35 - 1 , & V_2 -> V_21 ) )
return false ;
return true ;
}
static inline T_3
F_39 ( const struct V_36 * V_37 ,
const struct V_1 * V_38 )
{
const struct V_39 * V_40 = F_40 ( V_37 ) ;
unsigned long V_41 ;
T_2 V_42 = 0 , V_43 = 0 ;
int V_44 ;
V_44 = F_41 ( V_40 -> V_45 ) ;
if ( V_44 >= 0 ) {
const T_2 * V_46 ;
T_4 V_47 [ 2 ] ;
V_46 = F_42 ( V_37 , V_40 -> V_48 * 4 + V_44 , 4 , V_47 ) ;
if ( V_46 ) {
V_42 = V_46 [ 0 ] ;
V_43 = V_46 [ 1 ] ;
}
} else {
F_43 ( L_2 , V_40 -> V_45 ) ;
}
switch ( V_38 -> V_27 ) {
case V_49 :
V_41 = F_44 ( F_45 ( V_40 -> V_50 ) ,
V_38 -> V_28 ) ;
break;
case V_51 :
V_41 = F_46 ( F_45 ( V_40 -> V_50 ) , V_42 ,
V_38 -> V_28 ) ;
break;
case V_52 :
V_41 = F_47 ( F_45 ( V_40 -> V_50 ) , V_42 , V_43 ,
V_38 -> V_28 ) ;
break;
default:
V_41 = 0 ;
F_48 ( L_3 , V_38 -> V_27 ) ;
F_49 () ;
break;
}
return ( ( ( V_53 ) V_41 * V_38 -> V_26 ) >> 32 ) + 1 ;
}
static inline int
F_50 ( const struct V_1 * V_38 , T_3 V_54 )
{
return F_51 ( V_54 - 1 , & V_38 -> V_21 ) ;
}
static unsigned int
F_52 ( struct V_36 * V_37 , const struct V_55 * V_56 )
{
const struct V_17 * V_57 = V_56 -> V_58 ;
struct V_59 * V_60 ;
enum V_61 V_62 ;
T_3 V_54 ;
V_60 = F_53 ( V_37 , & V_62 ) ;
if ( V_60 == NULL )
return V_63 ;
if ( F_40 ( V_37 ) -> V_45 == V_64 &&
( V_62 == V_65 ||
V_62 == V_66 ) )
return V_67 ;
V_54 = F_39 ( V_37 , V_57 -> V_38 ) ;
switch ( V_62 ) {
case V_68 :
V_60 -> V_69 = V_54 ;
break;
case V_65 :
case V_66 :
case V_70 :
case V_71 :
break;
default:
break;
}
#ifdef F_54
F_55 ( & V_60 -> V_72 [ V_73 ] . V_74 ) ;
#endif
F_56 ( L_4 , V_54 , V_60 -> V_69 ) ;
if ( ! F_50 ( V_57 -> V_38 , V_54 ) ) {
F_56 ( L_5 ) ;
return V_63 ;
}
F_56 ( L_6 ) ;
V_37 -> V_75 = V_76 ;
return V_67 ;
}
static int F_57 ( const struct V_77 * V_56 )
{
struct V_17 * V_57 = V_56 -> V_58 ;
const struct V_78 * V_79 = V_56 -> V_80 ;
struct V_1 * V_38 ;
int V_81 ;
if ( V_57 -> V_27 != V_49 &&
V_57 -> V_27 != V_51 &&
V_57 -> V_27 != V_52 ) {
F_48 ( L_3 , V_57 -> V_27 ) ;
return - V_82 ;
}
if ( V_79 -> V_22 . V_83 . V_84 != F_58 ( 0xffffffff ) ||
V_79 -> V_22 . V_85 . V_84 == 0 ) {
F_48 ( L_7 ) ;
return - V_82 ;
}
V_38 = F_21 ( V_79 -> V_22 . V_85 . V_84 , 1 ) ;
if ( ! V_38 ) {
if ( ! ( V_57 -> V_86 & V_87 ) ) {
F_48 ( L_8 ,
& V_79 -> V_22 . V_85 . V_84 ) ;
return - V_82 ;
} else {
struct V_23 * V_10 ;
if ( V_79 -> V_22 . V_88 [ 0 ] == '\0' ) {
F_48 ( L_9 ) ;
return - V_82 ;
}
V_10 = F_59 ( & V_89 , V_79 -> V_22 . V_88 ) ;
if ( ! V_10 ) {
F_48 ( L_10 ,
V_79 -> V_22 . V_88 ) ;
return - V_90 ;
}
V_38 = F_28 ( V_57 ,
V_79 -> V_22 . V_85 . V_84 , V_10 ) ;
if ( ! V_38 ) {
F_16 ( V_10 ) ;
return - V_91 ;
}
F_60 ( V_38 -> V_10 , V_38 -> V_11 ) ;
}
}
V_57 -> V_38 = V_38 ;
V_81 = F_61 ( V_56 -> V_92 ) ;
if ( V_81 < 0 )
F_48 ( L_11 ,
V_56 -> V_92 ) ;
return V_81 ;
}
static void F_62 ( const struct V_93 * V_56 )
{
const struct V_17 * V_57 = V_56 -> V_58 ;
F_9 ( V_57 -> V_38 ) ;
F_6 ( V_57 -> V_38 ) ;
F_63 ( V_56 -> V_92 ) ;
}
static void F_64 ( struct V_94 * V_95 )
{
#define F_65 30
char V_96 [ F_65 ] ;
int V_97 , V_98 ;
for ( V_98 = 0 , V_97 = 0 ; V_98 < F_65 - 3 && V_97 < V_25 ; V_97 ++ ) {
V_96 [ V_98 ++ ] = F_66 ( V_95 -> V_99 [ V_97 ] ) ;
V_96 [ V_98 ++ ] = F_67 ( V_95 -> V_99 [ V_97 ] ) ;
V_96 [ V_98 ++ ] = ':' ;
}
V_96 [ -- V_98 ] = '\0' ;
F_56 ( L_12 ,
& V_95 -> V_100 , V_96 , & V_95 -> V_101 ) ;
}
static unsigned int
F_68 ( unsigned int V_102 ,
struct V_36 * V_37 ,
const struct V_23 * V_103 ,
const struct V_23 * V_104 ,
int (* F_69)( struct V_36 * ) )
{
struct V_105 * V_106 = F_70 ( V_37 ) ;
struct V_94 * V_95 ;
struct V_1 * V_2 ;
if ( V_106 -> V_107 != F_71 ( V_108 ) ||
V_106 -> V_109 != F_71 ( V_110 ) ||
V_106 -> V_111 != 4 || V_106 -> V_112 != V_25 )
return V_113 ;
if ( V_106 -> V_114 != F_71 ( V_115 ) &&
V_106 -> V_114 != F_71 ( V_116 ) )
return V_113 ;
V_95 = ( void * ) ( V_106 + 1 ) ;
V_2 = F_21 ( V_95 -> V_100 , 0 ) ;
if ( ! V_2 )
return V_113 ;
if ( V_2 -> V_10 != V_104 ) {
F_56 ( L_13
L_14 ,
V_2 -> V_10 -> V_13 , V_104 -> V_13 ) ;
F_6 ( V_2 ) ;
return V_113 ;
}
memcpy ( V_95 -> V_99 , V_2 -> V_11 , V_106 -> V_112 ) ;
#ifdef F_54
F_56 ( L_15 ) ;
F_64 ( V_95 ) ;
#endif
F_6 ( V_2 ) ;
return V_113 ;
}
static void * F_72 ( struct V_117 * V_118 , T_5 * V_119 )
{
struct V_1 * V_2 = V_118 -> V_120 ;
unsigned int V_121 ;
T_3 V_21 ;
struct V_122 * V_123 ;
V_21 = V_2 -> V_21 ;
V_121 = F_73 ( V_21 ) ;
if ( * V_119 >= V_121 )
return NULL ;
V_123 = F_74 ( sizeof( struct V_122 ) , V_124 ) ;
if ( ! V_123 )
return F_75 ( - V_91 ) ;
V_123 -> V_119 = * V_119 ;
V_123 -> V_121 = V_121 ;
V_123 -> V_125 = F_76 ( V_21 ) ;
V_123 -> V_126 = V_21 ;
F_77 ( V_123 -> V_125 - 1 , & V_123 -> V_126 ) ;
return V_123 ;
}
static void * F_78 ( struct V_117 * V_118 , void * V_127 , T_5 * V_119 )
{
struct V_122 * V_123 = V_127 ;
* V_119 = ++ V_123 -> V_119 ;
if ( * V_119 >= V_123 -> V_121 ) {
F_4 ( V_127 ) ;
return NULL ;
}
V_123 -> V_125 = F_76 ( V_123 -> V_126 ) ;
F_77 ( V_123 -> V_125 - 1 , & V_123 -> V_126 ) ;
return V_123 ;
}
static void F_79 ( struct V_117 * V_118 , void * V_127 )
{
if ( ! F_80 ( V_127 ) )
F_4 ( V_127 ) ;
}
static int F_81 ( struct V_117 * V_118 , void * V_127 )
{
struct V_122 * V_123 = V_127 ;
if ( V_123 -> V_119 != 0 )
F_82 ( V_118 , ',' ) ;
F_83 ( V_118 , L_16 , V_123 -> V_125 ) ;
if ( V_123 -> V_119 == V_123 -> V_121 - 1 )
F_82 ( V_118 , '\n' ) ;
return 0 ;
}
static int F_84 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
int V_81 = F_85 ( V_129 , & V_130 ) ;
if ( ! V_81 ) {
struct V_117 * V_131 = V_129 -> V_132 ;
struct V_1 * V_2 = F_86 ( V_128 ) -> V_133 ;
V_131 -> V_120 = V_2 ;
F_1 ( V_2 ) ;
}
return V_81 ;
}
static int F_87 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
struct V_1 * V_2 = F_86 ( V_128 ) -> V_133 ;
int V_81 ;
V_81 = F_88 ( V_128 , V_129 ) ;
if ( ! V_81 )
F_6 ( V_2 ) ;
return V_81 ;
}
static T_6 F_89 ( struct V_129 * V_129 , const char T_7 * V_134 ,
T_8 V_135 , T_5 * V_136 )
{
struct V_1 * V_2 = F_86 ( V_129 -> V_137 . V_138 -> V_139 ) -> V_133 ;
#define F_90 10
char V_29 [ F_90 + 1 ] ;
unsigned long V_35 ;
int V_140 ;
if ( V_135 > F_90 )
return - V_141 ;
if ( F_91 ( V_29 , V_134 , V_135 ) )
return - V_142 ;
V_29 [ V_135 ] = 0 ;
if ( * V_29 == '+' ) {
V_140 = F_92 ( V_29 + 1 , 10 , & V_35 ) ;
if ( V_140 )
return V_140 ;
if ( F_35 ( V_2 , V_35 ) )
return - V_91 ;
} else if ( * V_29 == '-' ) {
V_140 = F_92 ( V_29 + 1 , 10 , & V_35 ) ;
if ( V_140 )
return V_140 ;
if ( F_37 ( V_2 , V_35 ) )
return - V_90 ;
} else
return - V_141 ;
return V_135 ;
}
static int T_9 F_93 ( void )
{
int V_81 ;
V_81 = F_94 ( & V_143 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_95 ( & V_144 ) ;
if ( V_81 < 0 )
goto V_145;
#ifdef F_17
V_32 = F_96 ( L_17 , V_89 . V_146 ) ;
if ( ! V_32 ) {
F_97 ( L_18 ) ;
V_81 = - V_91 ;
goto V_147;
}
#endif
F_48 ( L_19 ,
V_148 ) ;
return 0 ;
#ifdef F_17
V_147:
F_98 ( & V_144 ) ;
#endif
V_145:
F_99 ( & V_143 ) ;
return V_81 ;
}
static void T_10 F_100 ( void )
{
F_48 ( L_20 , V_148 ) ;
#ifdef F_17
F_18 ( V_32 -> V_13 , V_32 -> V_14 ) ;
#endif
F_98 ( & V_144 ) ;
F_99 ( & V_143 ) ;
F_101 () ;
}
