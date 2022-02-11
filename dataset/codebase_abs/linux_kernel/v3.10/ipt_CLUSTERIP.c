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
F_18 ( V_2 -> V_12 ) ;
#endif
return;
}
F_14 () ;
}
static struct V_1 *
F_19 ( T_1 V_13 )
{
struct V_1 * V_2 ;
F_20 (c, &clusterip_configs, list) {
if ( V_2 -> V_13 == V_13 )
return V_2 ;
}
return NULL ;
}
static inline struct V_1 *
F_21 ( T_1 V_13 , int V_14 )
{
struct V_1 * V_2 ;
F_22 () ;
V_2 = F_19 ( V_13 ) ;
if ( V_2 ) {
if ( F_23 ( ! F_24 ( & V_2 -> V_3 ) ) )
V_2 = NULL ;
else if ( V_14 )
F_2 ( & V_2 -> V_7 ) ;
}
F_25 () ;
return V_2 ;
}
static void
F_26 ( struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_18 ; V_17 ++ )
F_27 ( V_16 -> V_19 [ V_17 ] - 1 , & V_2 -> V_19 ) ;
}
static struct V_1 *
F_28 ( const struct V_15 * V_16 , T_1 V_20 ,
struct V_21 * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_10 = V_10 ;
V_2 -> V_13 = V_20 ;
memcpy ( & V_2 -> V_11 , & V_16 -> V_11 , V_23 ) ;
V_2 -> V_24 = V_16 -> V_24 ;
F_26 ( V_2 , V_16 ) ;
V_2 -> V_25 = V_16 -> V_25 ;
V_2 -> V_26 = V_16 -> V_26 ;
F_30 ( & V_2 -> V_3 , 1 ) ;
F_30 ( & V_2 -> V_7 , 1 ) ;
#ifdef F_17
{
char V_27 [ 16 ] ;
sprintf ( V_27 , L_1 , & V_20 ) ;
V_2 -> V_12 = F_31 ( V_27 , V_28 | V_29 ,
V_30 ,
& V_31 , V_2 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 ) ;
return NULL ;
}
}
#endif
F_32 ( & V_8 ) ;
F_33 ( & V_2 -> V_9 , & V_32 ) ;
F_34 ( & V_8 ) ;
return V_2 ;
}
static int
F_35 ( struct V_1 * V_2 , T_2 V_33 )
{
if ( V_33 == 0 ||
V_33 > V_2 -> V_24 )
return 1 ;
if ( F_36 ( V_33 - 1 , & V_2 -> V_19 ) )
return 1 ;
return 0 ;
}
static bool
F_37 ( struct V_1 * V_2 , T_2 V_33 )
{
if ( V_33 == 0 ||
V_33 > V_2 -> V_24 )
return true ;
if ( F_38 ( V_33 - 1 , & V_2 -> V_19 ) )
return false ;
return true ;
}
static inline T_3
F_39 ( const struct V_34 * V_35 ,
const struct V_1 * V_36 )
{
const struct V_37 * V_38 = F_40 ( V_35 ) ;
unsigned long V_39 ;
T_2 V_40 = 0 , V_41 = 0 ;
int V_42 ;
V_42 = F_41 ( V_38 -> V_43 ) ;
if ( V_42 >= 0 ) {
const T_2 * V_44 ;
T_4 V_45 [ 2 ] ;
V_44 = F_42 ( V_35 , V_38 -> V_46 * 4 + V_42 , 4 , V_45 ) ;
if ( V_44 ) {
V_40 = V_44 [ 0 ] ;
V_41 = V_44 [ 1 ] ;
}
} else {
F_43 ( L_2 , V_38 -> V_43 ) ;
}
switch ( V_36 -> V_25 ) {
case V_47 :
V_39 = F_44 ( F_45 ( V_38 -> V_48 ) ,
V_36 -> V_26 ) ;
break;
case V_49 :
V_39 = F_46 ( F_45 ( V_38 -> V_48 ) , V_40 ,
V_36 -> V_26 ) ;
break;
case V_50 :
V_39 = F_47 ( F_45 ( V_38 -> V_48 ) , V_40 , V_41 ,
V_36 -> V_26 ) ;
break;
default:
V_39 = 0 ;
F_48 ( L_3 , V_36 -> V_25 ) ;
F_49 () ;
break;
}
return ( ( ( V_51 ) V_39 * V_36 -> V_24 ) >> 32 ) + 1 ;
}
static inline int
F_50 ( const struct V_1 * V_36 , T_3 V_52 )
{
return F_51 ( V_52 - 1 , & V_36 -> V_19 ) ;
}
static unsigned int
F_52 ( struct V_34 * V_35 , const struct V_53 * V_54 )
{
const struct V_15 * V_55 = V_54 -> V_56 ;
struct V_57 * V_58 ;
enum V_59 V_60 ;
T_3 V_52 ;
V_58 = F_53 ( V_35 , & V_60 ) ;
if ( V_58 == NULL )
return V_61 ;
if ( F_40 ( V_35 ) -> V_43 == V_62 &&
( V_60 == V_63 ||
V_60 == V_64 ) )
return V_65 ;
V_52 = F_39 ( V_35 , V_55 -> V_36 ) ;
switch ( V_60 ) {
case V_66 :
V_58 -> V_67 = V_52 ;
break;
case V_63 :
case V_64 :
case V_68 :
case V_69 :
break;
default:
break;
}
#ifdef F_54
F_55 ( & V_58 -> V_70 [ V_71 ] . V_72 ) ;
#endif
F_56 ( L_4 , V_52 , V_58 -> V_67 ) ;
if ( ! F_50 ( V_55 -> V_36 , V_52 ) ) {
F_56 ( L_5 ) ;
return V_61 ;
}
F_56 ( L_6 ) ;
V_35 -> V_73 = V_74 ;
return V_65 ;
}
static int F_57 ( const struct V_75 * V_54 )
{
struct V_15 * V_55 = V_54 -> V_56 ;
const struct V_76 * V_77 = V_54 -> V_78 ;
struct V_1 * V_36 ;
int V_79 ;
if ( V_55 -> V_25 != V_47 &&
V_55 -> V_25 != V_49 &&
V_55 -> V_25 != V_50 ) {
F_48 ( L_3 , V_55 -> V_25 ) ;
return - V_80 ;
}
if ( V_77 -> V_20 . V_81 . V_82 != F_58 ( 0xffffffff ) ||
V_77 -> V_20 . V_83 . V_82 == 0 ) {
F_48 ( L_7 ) ;
return - V_80 ;
}
V_36 = F_21 ( V_77 -> V_20 . V_83 . V_82 , 1 ) ;
if ( ! V_36 ) {
if ( ! ( V_55 -> V_84 & V_85 ) ) {
F_48 ( L_8 ,
& V_77 -> V_20 . V_83 . V_82 ) ;
return - V_80 ;
} else {
struct V_21 * V_10 ;
if ( V_77 -> V_20 . V_86 [ 0 ] == '\0' ) {
F_48 ( L_9 ) ;
return - V_80 ;
}
V_10 = F_59 ( & V_87 , V_77 -> V_20 . V_86 ) ;
if ( ! V_10 ) {
F_48 ( L_10 ,
V_77 -> V_20 . V_86 ) ;
return - V_88 ;
}
V_36 = F_28 ( V_55 ,
V_77 -> V_20 . V_83 . V_82 , V_10 ) ;
if ( ! V_36 ) {
F_16 ( V_10 ) ;
return - V_89 ;
}
F_60 ( V_36 -> V_10 , V_36 -> V_11 ) ;
}
}
V_55 -> V_36 = V_36 ;
V_79 = F_61 ( V_54 -> V_90 ) ;
if ( V_79 < 0 )
F_48 ( L_11 ,
V_54 -> V_90 ) ;
return V_79 ;
}
static void F_62 ( const struct V_91 * V_54 )
{
const struct V_15 * V_55 = V_54 -> V_56 ;
F_9 ( V_55 -> V_36 ) ;
F_6 ( V_55 -> V_36 ) ;
F_63 ( V_54 -> V_90 ) ;
}
static void F_64 ( struct V_92 * V_93 )
{
#define F_65 30
char V_94 [ F_65 ] ;
int V_95 , V_96 ;
for ( V_96 = 0 , V_95 = 0 ; V_96 < F_65 - 3 && V_95 < V_23 ; V_95 ++ ) {
V_94 [ V_96 ++ ] = F_66 ( V_93 -> V_97 [ V_95 ] ) ;
V_94 [ V_96 ++ ] = F_67 ( V_93 -> V_97 [ V_95 ] ) ;
V_94 [ V_96 ++ ] = ':' ;
}
V_94 [ -- V_96 ] = '\0' ;
F_56 ( L_12 ,
& V_93 -> V_98 , V_94 , & V_93 -> V_99 ) ;
}
static unsigned int
F_68 ( unsigned int V_100 ,
struct V_34 * V_35 ,
const struct V_21 * V_101 ,
const struct V_21 * V_102 ,
int (* F_69)( struct V_34 * ) )
{
struct V_103 * V_104 = F_70 ( V_35 ) ;
struct V_92 * V_93 ;
struct V_1 * V_2 ;
if ( V_104 -> V_105 != F_71 ( V_106 ) ||
V_104 -> V_107 != F_71 ( V_108 ) ||
V_104 -> V_109 != 4 || V_104 -> V_110 != V_23 )
return V_111 ;
if ( V_104 -> V_112 != F_71 ( V_113 ) &&
V_104 -> V_112 != F_71 ( V_114 ) )
return V_111 ;
V_93 = ( void * ) ( V_104 + 1 ) ;
V_2 = F_21 ( V_93 -> V_98 , 0 ) ;
if ( ! V_2 )
return V_111 ;
if ( V_2 -> V_10 != V_102 ) {
F_56 ( L_13
L_14 ,
V_2 -> V_10 -> V_115 , V_102 -> V_115 ) ;
F_6 ( V_2 ) ;
return V_111 ;
}
memcpy ( V_93 -> V_97 , V_2 -> V_11 , V_104 -> V_110 ) ;
#ifdef F_54
F_56 ( L_15 ) ;
F_64 ( V_93 ) ;
#endif
F_6 ( V_2 ) ;
return V_111 ;
}
static void * F_72 ( struct V_116 * V_117 , T_5 * V_118 )
{
struct V_1 * V_2 = V_117 -> V_119 ;
unsigned int V_120 ;
T_3 V_19 ;
struct V_121 * V_122 ;
V_19 = V_2 -> V_19 ;
V_120 = F_73 ( V_19 ) ;
if ( * V_118 >= V_120 )
return NULL ;
V_122 = F_74 ( sizeof( struct V_121 ) , V_123 ) ;
if ( ! V_122 )
return F_75 ( - V_89 ) ;
V_122 -> V_118 = * V_118 ;
V_122 -> V_120 = V_120 ;
V_122 -> V_124 = F_76 ( V_19 ) ;
V_122 -> V_125 = V_19 ;
F_77 ( V_122 -> V_124 - 1 , & V_122 -> V_125 ) ;
return V_122 ;
}
static void * F_78 ( struct V_116 * V_117 , void * V_126 , T_5 * V_118 )
{
struct V_121 * V_122 = V_126 ;
* V_118 = ++ V_122 -> V_118 ;
if ( * V_118 >= V_122 -> V_120 ) {
F_4 ( V_126 ) ;
return NULL ;
}
V_122 -> V_124 = F_76 ( V_122 -> V_125 ) ;
F_77 ( V_122 -> V_124 - 1 , & V_122 -> V_125 ) ;
return V_122 ;
}
static void F_79 ( struct V_116 * V_117 , void * V_126 )
{
if ( ! F_80 ( V_126 ) )
F_4 ( V_126 ) ;
}
static int F_81 ( struct V_116 * V_117 , void * V_126 )
{
struct V_121 * V_122 = V_126 ;
if ( V_122 -> V_118 != 0 )
F_82 ( V_117 , ',' ) ;
F_83 ( V_117 , L_16 , V_122 -> V_124 ) ;
if ( V_122 -> V_118 == V_122 -> V_120 - 1 )
F_82 ( V_117 , '\n' ) ;
return 0 ;
}
static int F_84 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
int V_79 = F_85 ( V_128 , & V_129 ) ;
if ( ! V_79 ) {
struct V_116 * V_130 = V_128 -> V_131 ;
struct V_1 * V_2 = F_86 ( V_127 ) ;
V_130 -> V_119 = V_2 ;
F_1 ( V_2 ) ;
}
return V_79 ;
}
static int F_87 ( struct V_127 * V_127 , struct V_128 * V_128 )
{
struct V_1 * V_2 = F_86 ( V_127 ) ;
int V_79 ;
V_79 = F_88 ( V_127 , V_128 ) ;
if ( ! V_79 )
F_6 ( V_2 ) ;
return V_79 ;
}
static T_6 F_89 ( struct V_128 * V_128 , const char T_7 * V_132 ,
T_8 V_133 , T_5 * V_134 )
{
struct V_1 * V_2 = F_86 ( F_90 ( V_128 ) ) ;
#define F_91 10
char V_27 [ F_91 + 1 ] ;
unsigned long V_33 ;
int V_135 ;
if ( V_133 > F_91 )
return - V_136 ;
if ( F_92 ( V_27 , V_132 , V_133 ) )
return - V_137 ;
V_27 [ V_133 ] = 0 ;
if ( * V_27 == '+' ) {
V_135 = F_93 ( V_27 + 1 , 10 , & V_33 ) ;
if ( V_135 )
return V_135 ;
if ( F_35 ( V_2 , V_33 ) )
return - V_89 ;
} else if ( * V_27 == '-' ) {
V_135 = F_93 ( V_27 + 1 , 10 , & V_33 ) ;
if ( V_135 )
return V_135 ;
if ( F_37 ( V_2 , V_33 ) )
return - V_88 ;
} else
return - V_136 ;
return V_133 ;
}
static int T_9 F_94 ( void )
{
int V_79 ;
V_79 = F_95 ( & V_138 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_96 ( & V_139 ) ;
if ( V_79 < 0 )
goto V_140;
#ifdef F_17
V_30 = F_97 ( L_17 , V_87 . V_141 ) ;
if ( ! V_30 ) {
F_98 ( L_18 ) ;
V_79 = - V_89 ;
goto V_142;
}
#endif
F_48 ( L_19 ,
V_143 ) ;
return 0 ;
#ifdef F_17
V_142:
F_99 ( & V_139 ) ;
#endif
V_140:
F_100 ( & V_138 ) ;
return V_79 ;
}
static void T_10 F_101 ( void )
{
F_48 ( L_20 , V_143 ) ;
#ifdef F_17
F_18 ( V_30 ) ;
#endif
F_99 ( & V_139 ) ;
F_100 ( & V_138 ) ;
F_102 () ;
}
