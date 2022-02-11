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
F_9 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_7 , V_10 ) ;
F_11 () ;
if ( F_12 ( & V_2 -> V_11 , & V_9 -> V_12 ) ) {
F_13 ( & V_2 -> V_13 ) ;
F_14 ( & V_9 -> V_12 ) ;
F_15 () ;
F_16 ( & V_2 -> V_14 ) ;
#ifdef F_17
if ( V_9 -> V_15 )
F_18 ( V_2 -> V_16 ) ;
#endif
return;
}
F_15 () ;
}
static struct V_1 *
F_19 ( struct V_7 * V_7 , T_1 V_17 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 = F_10 ( V_7 , V_10 ) ;
F_20 (c, &cn->configs, list) {
if ( V_2 -> V_17 == V_17 )
return V_2 ;
}
return NULL ;
}
static inline struct V_1 *
F_21 ( struct V_7 * V_7 , T_1 V_17 , int V_18 )
{
struct V_1 * V_2 ;
F_22 () ;
V_2 = F_19 ( V_7 , V_17 ) ;
if ( V_2 ) {
#ifdef F_17
if ( ! V_2 -> V_16 )
V_2 = NULL ;
else
#endif
if ( F_23 ( ! F_24 ( & V_2 -> V_3 ) ) )
V_2 = NULL ;
else if ( V_18 )
F_2 ( & V_2 -> V_11 ) ;
}
F_25 () ;
return V_2 ;
}
static void
F_26 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_20 -> V_22 ; V_21 ++ )
F_27 ( V_20 -> V_23 [ V_21 ] - 1 , & V_2 -> V_23 ) ;
}
static int
F_28 ( struct V_24 * V_25 , unsigned long V_26 ,
void * V_27 )
{
struct V_28 * V_29 = F_29 ( V_27 ) ;
struct V_1 * V_2 ;
V_2 = F_5 ( V_25 , struct V_1 , V_14 ) ;
switch ( V_26 ) {
case V_30 :
if ( ! strcmp ( V_29 -> V_31 , V_2 -> V_32 ) ) {
V_2 -> V_33 = V_29 -> V_33 ;
F_30 ( V_29 , V_2 -> V_34 ) ;
}
break;
case V_35 :
if ( V_29 -> V_33 == V_2 -> V_33 ) {
F_31 ( V_29 , V_2 -> V_34 ) ;
V_2 -> V_33 = - 1 ;
}
break;
case V_36 :
if ( ! strcmp ( V_29 -> V_31 , V_2 -> V_32 ) ) {
V_2 -> V_33 = V_29 -> V_33 ;
F_30 ( V_29 , V_2 -> V_34 ) ;
} else if ( V_29 -> V_33 == V_2 -> V_33 ) {
F_31 ( V_29 , V_2 -> V_34 ) ;
V_2 -> V_33 = - 1 ;
}
break;
}
return V_37 ;
}
static struct V_1 *
F_32 ( struct V_7 * V_7 , const struct V_19 * V_20 ,
T_1 V_38 , const char * V_39 )
{
struct V_8 * V_9 = F_10 ( V_7 , V_10 ) ;
struct V_1 * V_2 ;
int V_40 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return F_34 ( - V_42 ) ;
strcpy ( V_2 -> V_32 , V_39 ) ;
V_2 -> V_33 = - 1 ;
V_2 -> V_17 = V_38 ;
memcpy ( & V_2 -> V_34 , & V_20 -> V_34 , V_43 ) ;
V_2 -> V_44 = V_20 -> V_44 ;
F_26 ( V_2 , V_20 ) ;
V_2 -> V_45 = V_20 -> V_45 ;
V_2 -> V_46 = V_20 -> V_46 ;
F_35 ( & V_2 -> V_3 , 1 ) ;
F_35 ( & V_2 -> V_11 , 1 ) ;
F_36 ( & V_9 -> V_12 ) ;
if ( F_19 ( V_7 , V_38 ) ) {
F_37 ( & V_9 -> V_12 ) ;
F_4 ( V_2 ) ;
return F_34 ( - V_47 ) ;
}
F_38 ( & V_2 -> V_13 , & V_9 -> V_48 ) ;
F_37 ( & V_9 -> V_12 ) ;
#ifdef F_17
{
char V_49 [ 16 ] ;
sprintf ( V_49 , L_1 , & V_38 ) ;
V_2 -> V_16 = F_39 ( V_49 , V_50 | V_51 ,
V_9 -> V_15 ,
& V_52 , V_2 ) ;
if ( ! V_2 -> V_16 ) {
V_40 = - V_42 ;
goto V_40;
}
}
#endif
V_2 -> V_14 . V_53 = F_28 ;
V_40 = F_40 ( & V_2 -> V_14 ) ;
if ( ! V_40 )
return V_2 ;
#ifdef F_17
F_18 ( V_2 -> V_16 ) ;
V_40:
#endif
F_36 ( & V_9 -> V_12 ) ;
F_13 ( & V_2 -> V_13 ) ;
F_37 ( & V_9 -> V_12 ) ;
F_4 ( V_2 ) ;
return F_34 ( V_40 ) ;
}
static int
F_41 ( struct V_1 * V_2 , T_2 V_54 )
{
if ( V_54 == 0 ||
V_54 > V_2 -> V_44 )
return 1 ;
if ( F_42 ( V_54 - 1 , & V_2 -> V_23 ) )
return 1 ;
return 0 ;
}
static bool
F_43 ( struct V_1 * V_2 , T_2 V_54 )
{
if ( V_54 == 0 ||
V_54 > V_2 -> V_44 )
return true ;
if ( F_44 ( V_54 - 1 , & V_2 -> V_23 ) )
return false ;
return true ;
}
static inline T_3
F_45 ( const struct V_55 * V_56 ,
const struct V_1 * V_57 )
{
const struct V_58 * V_59 = F_46 ( V_56 ) ;
unsigned long V_60 ;
T_2 V_61 = 0 , V_62 = 0 ;
int V_63 ;
V_63 = F_47 ( V_59 -> V_64 ) ;
if ( V_63 >= 0 ) {
const T_2 * V_65 ;
T_4 V_66 [ 2 ] ;
V_65 = F_48 ( V_56 , V_59 -> V_67 * 4 + V_63 , 4 , V_66 ) ;
if ( V_65 ) {
V_61 = V_65 [ 0 ] ;
V_62 = V_65 [ 1 ] ;
}
} else {
F_49 ( L_2 , V_59 -> V_64 ) ;
}
switch ( V_57 -> V_45 ) {
case V_68 :
V_60 = F_50 ( F_51 ( V_59 -> V_69 ) ,
V_57 -> V_46 ) ;
break;
case V_70 :
V_60 = F_52 ( F_51 ( V_59 -> V_69 ) , V_61 ,
V_57 -> V_46 ) ;
break;
case V_71 :
V_60 = F_53 ( F_51 ( V_59 -> V_69 ) , V_61 , V_62 ,
V_57 -> V_46 ) ;
break;
default:
V_60 = 0 ;
F_54 ( L_3 , V_57 -> V_45 ) ;
F_55 () ;
break;
}
return F_56 ( V_60 , V_57 -> V_44 ) + 1 ;
}
static inline int
F_57 ( const struct V_1 * V_57 , T_3 V_72 )
{
return F_58 ( V_72 - 1 , & V_57 -> V_23 ) ;
}
static unsigned int
F_59 ( struct V_55 * V_56 , const struct V_73 * V_74 )
{
const struct V_19 * V_75 = V_74 -> V_76 ;
struct V_77 * V_78 ;
enum V_79 V_80 ;
T_3 V_72 ;
V_78 = F_60 ( V_56 , & V_80 ) ;
if ( V_78 == NULL )
return V_81 ;
if ( F_46 ( V_56 ) -> V_64 == V_82 &&
( V_80 == V_83 ||
V_80 == V_84 ) )
return V_85 ;
V_72 = F_45 ( V_56 , V_75 -> V_57 ) ;
switch ( V_80 ) {
case V_86 :
V_78 -> V_87 = V_72 ;
break;
case V_83 :
case V_84 :
case V_88 :
case V_89 :
break;
default:
break;
}
#ifdef F_61
F_62 ( & V_78 -> V_90 [ V_91 ] . V_92 ) ;
#endif
F_63 ( L_4 , V_72 , V_78 -> V_87 ) ;
if ( ! F_57 ( V_75 -> V_57 , V_72 ) ) {
F_63 ( L_5 ) ;
return V_81 ;
}
F_63 ( L_6 ) ;
V_56 -> V_93 = V_94 ;
return V_85 ;
}
static int F_64 ( const struct V_95 * V_74 )
{
struct V_19 * V_75 = V_74 -> V_76 ;
const struct V_96 * V_97 = V_74 -> V_98 ;
struct V_1 * V_57 ;
int V_99 ;
if ( V_74 -> V_100 ) {
F_65 ( L_7 ) ;
return - V_101 ;
}
if ( V_75 -> V_45 != V_68 &&
V_75 -> V_45 != V_70 &&
V_75 -> V_45 != V_71 ) {
F_54 ( L_3 , V_75 -> V_45 ) ;
return - V_102 ;
}
if ( V_97 -> V_38 . V_103 . V_104 != F_66 ( 0xffffffff ) ||
V_97 -> V_38 . V_105 . V_104 == 0 ) {
F_54 ( L_8 ) ;
return - V_102 ;
}
V_57 = F_21 ( V_74 -> V_7 , V_97 -> V_38 . V_105 . V_104 , 1 ) ;
if ( ! V_57 ) {
if ( ! ( V_75 -> V_106 & V_107 ) ) {
F_54 ( L_9 ,
& V_97 -> V_38 . V_105 . V_104 ) ;
return - V_102 ;
} else {
struct V_28 * V_29 ;
if ( V_97 -> V_38 . V_39 [ 0 ] == '\0' ) {
F_54 ( L_10 ) ;
return - V_102 ;
}
V_29 = F_67 ( V_74 -> V_7 , V_97 -> V_38 . V_39 ) ;
if ( ! V_29 ) {
F_54 ( L_11 ,
V_97 -> V_38 . V_39 ) ;
return - V_108 ;
}
F_68 ( V_29 ) ;
V_57 = F_32 ( V_74 -> V_7 , V_75 ,
V_97 -> V_38 . V_105 . V_104 ,
V_97 -> V_38 . V_39 ) ;
if ( F_69 ( V_57 ) )
return F_70 ( V_57 ) ;
}
}
V_75 -> V_57 = V_57 ;
V_99 = F_71 ( V_74 -> V_7 , V_74 -> V_109 ) ;
if ( V_99 < 0 )
F_54 ( L_12 ,
V_74 -> V_109 ) ;
if ( ! V_74 -> V_7 -> V_110 . V_111 ) {
F_54 ( L_13
L_14 ) ;
V_74 -> V_7 -> V_110 . V_111 = true ;
}
return V_99 ;
}
static void F_72 ( const struct V_112 * V_74 )
{
const struct V_19 * V_75 = V_74 -> V_76 ;
F_9 ( V_74 -> V_7 , V_75 -> V_57 ) ;
F_6 ( V_75 -> V_57 ) ;
F_73 ( V_74 -> V_7 , V_74 -> V_109 ) ;
}
static void F_74 ( struct V_113 * V_114 )
{
#define F_75 30
char V_115 [ F_75 ] ;
int V_116 , V_117 ;
for ( V_117 = 0 , V_116 = 0 ; V_117 < F_75 - 3 && V_116 < V_43 ; V_116 ++ ) {
V_115 [ V_117 ++ ] = F_76 ( V_114 -> V_118 [ V_116 ] ) ;
V_115 [ V_117 ++ ] = F_77 ( V_114 -> V_118 [ V_116 ] ) ;
V_115 [ V_117 ++ ] = ':' ;
}
V_115 [ -- V_117 ] = '\0' ;
F_63 ( L_15 ,
& V_114 -> V_119 , V_115 , & V_114 -> V_120 ) ;
}
static unsigned int
F_78 ( void * V_121 ,
struct V_55 * V_56 ,
const struct V_122 * V_123 )
{
struct V_124 * V_125 = F_79 ( V_56 ) ;
struct V_113 * V_114 ;
struct V_1 * V_2 ;
struct V_7 * V_7 = V_123 -> V_7 ;
if ( V_125 -> V_126 != F_80 ( V_127 ) ||
V_125 -> V_128 != F_80 ( V_129 ) ||
V_125 -> V_130 != 4 || V_125 -> V_131 != V_43 )
return V_132 ;
if ( V_125 -> V_133 != F_80 ( V_134 ) &&
V_125 -> V_133 != F_80 ( V_135 ) )
return V_132 ;
V_114 = ( void * ) ( V_125 + 1 ) ;
V_2 = F_21 ( V_7 , V_114 -> V_119 , 0 ) ;
if ( ! V_2 )
return V_132 ;
if ( V_2 -> V_33 != V_123 -> V_136 -> V_33 ) {
F_63 ( L_16 ,
V_2 -> V_33 , V_123 -> V_136 -> V_33 ) ;
F_6 ( V_2 ) ;
return V_132 ;
}
memcpy ( V_114 -> V_118 , V_2 -> V_34 , V_125 -> V_131 ) ;
#ifdef F_61
F_63 ( L_17 ) ;
F_74 ( V_114 ) ;
#endif
F_6 ( V_2 ) ;
return V_132 ;
}
static void * F_81 ( struct V_137 * V_138 , T_5 * V_139 )
{
struct V_1 * V_2 = V_138 -> V_140 ;
unsigned int V_141 ;
T_3 V_23 ;
struct V_142 * V_143 ;
V_23 = V_2 -> V_23 ;
V_141 = F_82 ( V_23 ) ;
if ( * V_139 >= V_141 )
return NULL ;
V_143 = F_83 ( sizeof( struct V_142 ) , V_144 ) ;
if ( ! V_143 )
return F_34 ( - V_42 ) ;
V_143 -> V_139 = * V_139 ;
V_143 -> V_141 = V_141 ;
V_143 -> V_145 = F_84 ( V_23 ) ;
V_143 -> V_146 = V_23 ;
F_85 ( V_143 -> V_145 - 1 , & V_143 -> V_146 ) ;
return V_143 ;
}
static void * F_86 ( struct V_137 * V_138 , void * V_147 , T_5 * V_139 )
{
struct V_142 * V_143 = V_147 ;
* V_139 = ++ V_143 -> V_139 ;
if ( * V_139 >= V_143 -> V_141 ) {
F_4 ( V_147 ) ;
return NULL ;
}
V_143 -> V_145 = F_84 ( V_143 -> V_146 ) ;
F_85 ( V_143 -> V_145 - 1 , & V_143 -> V_146 ) ;
return V_143 ;
}
static void F_87 ( struct V_137 * V_138 , void * V_147 )
{
if ( ! F_69 ( V_147 ) )
F_4 ( V_147 ) ;
}
static int F_88 ( struct V_137 * V_138 , void * V_147 )
{
struct V_142 * V_143 = V_147 ;
if ( V_143 -> V_139 != 0 )
F_89 ( V_138 , ',' ) ;
F_90 ( V_138 , L_18 , V_143 -> V_145 ) ;
if ( V_143 -> V_139 == V_143 -> V_141 - 1 )
F_89 ( V_138 , '\n' ) ;
return 0 ;
}
static int F_91 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
int V_99 = F_92 ( V_149 , & V_150 ) ;
if ( ! V_99 ) {
struct V_137 * V_151 = V_149 -> V_152 ;
struct V_1 * V_2 = F_93 ( V_148 ) ;
V_151 -> V_140 = V_2 ;
F_1 ( V_2 ) ;
}
return V_99 ;
}
static int F_94 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_1 * V_2 = F_93 ( V_148 ) ;
int V_99 ;
V_99 = F_95 ( V_148 , V_149 ) ;
if ( ! V_99 )
F_6 ( V_2 ) ;
return V_99 ;
}
static T_6 F_96 ( struct V_149 * V_149 , const char T_7 * V_153 ,
T_8 V_154 , T_5 * V_155 )
{
struct V_1 * V_2 = F_93 ( F_97 ( V_149 ) ) ;
#define F_98 10
char V_49 [ F_98 + 1 ] ;
unsigned long V_54 ;
int V_156 ;
if ( V_154 > F_98 )
return - V_157 ;
if ( F_99 ( V_49 , V_153 , V_154 ) )
return - V_158 ;
V_49 [ V_154 ] = 0 ;
if ( * V_49 == '+' ) {
V_156 = F_100 ( V_49 + 1 , 10 , & V_54 ) ;
if ( V_156 )
return V_156 ;
if ( F_41 ( V_2 , V_54 ) )
return - V_42 ;
} else if ( * V_49 == '-' ) {
V_156 = F_100 ( V_49 + 1 , 10 , & V_54 ) ;
if ( V_156 )
return V_156 ;
if ( F_43 ( V_2 , V_54 ) )
return - V_108 ;
} else
return - V_157 ;
return V_154 ;
}
static int F_101 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = F_10 ( V_7 , V_10 ) ;
int V_99 ;
F_102 ( & V_9 -> V_48 ) ;
F_103 ( & V_9 -> V_12 ) ;
V_99 = F_104 ( V_7 , & V_159 ) ;
if ( V_99 < 0 )
return V_99 ;
#ifdef F_17
V_9 -> V_15 = F_105 ( L_19 , V_7 -> V_160 ) ;
if ( ! V_9 -> V_15 ) {
F_106 ( V_7 , & V_159 ) ;
F_65 ( L_20 ) ;
return - V_42 ;
}
#endif
return 0 ;
}
static void F_107 ( struct V_7 * V_7 )
{
#ifdef F_17
struct V_8 * V_9 = F_10 ( V_7 , V_10 ) ;
F_18 ( V_9 -> V_15 ) ;
V_9 -> V_15 = NULL ;
#endif
F_106 ( V_7 , & V_159 ) ;
}
static int T_9 F_108 ( void )
{
int V_99 ;
V_99 = F_109 ( & V_161 ) ;
if ( V_99 < 0 )
return V_99 ;
V_99 = F_110 ( & V_162 ) ;
if ( V_99 < 0 )
goto V_163;
F_54 ( L_21 ,
V_164 ) ;
return 0 ;
V_163:
F_111 ( & V_161 ) ;
return V_99 ;
}
static void T_10 F_112 ( void )
{
F_54 ( L_22 , V_164 ) ;
F_113 ( & V_162 ) ;
F_111 ( & V_161 ) ;
F_114 () ;
}
