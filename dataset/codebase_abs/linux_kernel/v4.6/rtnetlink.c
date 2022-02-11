void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
void F_5 ( void )
{
F_6 () ;
}
int F_7 ( void )
{
return F_8 ( & V_1 ) ;
}
int F_9 ( void )
{
return F_10 ( & V_1 ) ;
}
bool F_11 ( void )
{
return F_12 ( & V_1 ) ;
}
static inline int F_13 ( int V_2 )
{
int V_3 = V_2 - V_4 ;
F_14 ( V_3 < 0 || V_3 >= V_5 ) ;
return V_3 ;
}
static T_1 F_15 ( int V_6 , int V_3 )
{
struct V_7 * V_8 ;
if ( V_6 <= V_9 )
V_8 = V_10 [ V_6 ] ;
else
V_8 = NULL ;
if ( V_8 == NULL || V_8 [ V_3 ] . V_11 == NULL )
V_8 = V_10 [ V_12 ] ;
return V_8 [ V_3 ] . V_11 ;
}
static T_2 F_16 ( int V_6 , int V_3 )
{
struct V_7 * V_8 ;
if ( V_6 <= V_9 )
V_8 = V_10 [ V_6 ] ;
else
V_8 = NULL ;
if ( V_8 == NULL || V_8 [ V_3 ] . V_13 == NULL )
V_8 = V_10 [ V_12 ] ;
return V_8 [ V_3 ] . V_13 ;
}
static T_3 F_17 ( int V_6 , int V_3 )
{
struct V_7 * V_8 ;
if ( V_6 <= V_9 )
V_8 = V_10 [ V_6 ] ;
else
V_8 = NULL ;
if ( V_8 == NULL || V_8 [ V_3 ] . V_14 == NULL )
V_8 = V_10 [ V_12 ] ;
return V_8 [ V_3 ] . V_14 ;
}
int F_18 ( int V_6 , int V_2 ,
T_1 V_11 , T_2 V_13 ,
T_3 V_14 )
{
struct V_7 * V_8 ;
int V_3 ;
F_14 ( V_6 < 0 || V_6 > V_9 ) ;
V_3 = F_13 ( V_2 ) ;
V_8 = V_10 [ V_6 ] ;
if ( V_8 == NULL ) {
V_8 = F_19 ( V_5 , sizeof( * V_8 ) , V_15 ) ;
if ( V_8 == NULL )
return - V_16 ;
V_10 [ V_6 ] = V_8 ;
}
if ( V_11 )
V_8 [ V_3 ] . V_11 = V_11 ;
if ( V_13 )
V_8 [ V_3 ] . V_13 = V_13 ;
if ( V_14 )
V_8 [ V_3 ] . V_14 = V_14 ;
return 0 ;
}
void F_20 ( int V_6 , int V_2 ,
T_1 V_11 , T_2 V_13 ,
T_3 V_14 )
{
if ( F_18 ( V_6 , V_2 , V_11 , V_13 , V_14 ) < 0 )
F_21 ( L_1
L_2 ,
V_6 , V_2 ) ;
}
int F_22 ( int V_6 , int V_2 )
{
int V_3 ;
F_14 ( V_6 < 0 || V_6 > V_9 ) ;
V_3 = F_13 ( V_2 ) ;
if ( V_10 [ V_6 ] == NULL )
return - V_17 ;
V_10 [ V_6 ] [ V_3 ] . V_11 = NULL ;
V_10 [ V_6 ] [ V_3 ] . V_13 = NULL ;
return 0 ;
}
void F_23 ( int V_6 )
{
F_14 ( V_6 < 0 || V_6 > V_9 ) ;
F_24 ( V_10 [ V_6 ] ) ;
V_10 [ V_6 ] = NULL ;
}
static const struct V_18 * F_25 ( const char * V_19 )
{
const struct V_18 * V_20 ;
F_26 (ops, &link_ops, list) {
if ( ! strcmp ( V_20 -> V_19 , V_19 ) )
return V_20 ;
}
return NULL ;
}
int F_27 ( struct V_18 * V_20 )
{
if ( F_25 ( V_20 -> V_19 ) )
return - V_21 ;
if ( V_20 -> V_22 && ! V_20 -> V_23 )
V_20 -> V_23 = V_24 ;
F_28 ( & V_20 -> V_25 , & V_26 ) ;
return 0 ;
}
int F_29 ( struct V_18 * V_20 )
{
int V_27 ;
F_1 () ;
V_27 = F_27 ( V_20 ) ;
F_5 () ;
return V_27 ;
}
static void F_30 ( struct V_28 * V_28 , struct V_18 * V_20 )
{
struct V_29 * V_30 ;
F_31 ( V_31 ) ;
F_32 (net, dev) {
if ( V_30 -> V_18 == V_20 )
V_20 -> V_23 ( V_30 , & V_31 ) ;
}
F_33 ( & V_31 ) ;
}
void F_34 ( struct V_18 * V_20 )
{
struct V_28 * V_28 ;
F_35 (net) {
F_30 ( V_28 , V_20 ) ;
}
F_36 ( & V_20 -> V_25 ) ;
}
static void F_37 ( void )
{
struct V_28 * V_28 ;
bool V_32 ;
F_38 ( V_33 , V_34 ) ;
F_39 ( & V_35 , & V_33 ) ;
for (; ; ) {
V_32 = false ;
F_1 () ;
F_35 (net) {
if ( V_28 -> V_36 > 0 ) {
V_32 = true ;
break;
}
}
if ( ! V_32 )
break;
F_3 () ;
F_40 ( & V_33 , V_37 , V_38 ) ;
}
F_41 ( & V_35 , & V_33 ) ;
}
void F_42 ( struct V_18 * V_20 )
{
F_2 ( & V_39 ) ;
F_37 () ;
F_34 ( V_20 ) ;
F_5 () ;
F_4 ( & V_39 ) ;
}
static T_4 F_43 ( const struct V_29 * V_30 )
{
struct V_29 * V_40 ;
const struct V_18 * V_20 ;
V_40 = F_44 ( (struct V_29 * ) V_30 ) ;
if ( ! V_40 )
return 0 ;
V_20 = V_40 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_41 )
return 0 ;
return F_45 ( sizeof( struct V_42 ) ) +
V_20 -> V_41 ( V_40 , V_30 ) ;
}
static T_4 F_46 ( const struct V_29 * V_30 )
{
const struct V_18 * V_20 = V_30 -> V_18 ;
T_4 V_43 ;
if ( ! V_20 )
return 0 ;
V_43 = F_45 ( sizeof( struct V_42 ) ) +
F_45 ( strlen ( V_20 -> V_19 ) + 1 ) ;
if ( V_20 -> V_44 )
V_43 += F_45 ( sizeof( struct V_42 ) ) +
V_20 -> V_44 ( V_30 ) ;
if ( V_20 -> V_45 )
V_43 += F_45 ( V_20 -> V_45 ( V_30 ) ) ;
V_43 += F_43 ( V_30 ) ;
return V_43 ;
}
static const struct V_46 * F_47 ( const int V_47 )
{
const struct V_46 * V_20 ;
F_26 (ops, &rtnl_af_ops, list) {
if ( V_20 -> V_47 == V_47 )
return V_20 ;
}
return NULL ;
}
void F_48 ( struct V_46 * V_20 )
{
F_1 () ;
F_28 ( & V_20 -> V_25 , & V_46 ) ;
F_5 () ;
}
void F_49 ( struct V_46 * V_20 )
{
F_36 ( & V_20 -> V_25 ) ;
}
void F_50 ( struct V_46 * V_20 )
{
F_1 () ;
F_49 ( V_20 ) ;
F_5 () ;
}
static T_4 F_51 ( const struct V_29 * V_30 ,
T_5 V_48 )
{
struct V_46 * V_49 ;
T_4 V_43 ;
V_43 = F_45 ( sizeof( struct V_42 ) ) ;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_49 -> V_50 ) {
V_43 += F_45 ( sizeof( struct V_42 ) ) +
V_49 -> V_50 ( V_30 , V_48 ) ;
}
}
return V_43 ;
}
static bool F_52 ( const struct V_29 * V_30 )
{
struct V_29 * V_40 ;
V_40 = F_44 ( (struct V_29 * ) V_30 ) ;
if ( V_40 && V_40 -> V_18 )
return true ;
return false ;
}
static int F_53 ( struct V_51 * V_52 ,
const struct V_29 * V_30 )
{
struct V_29 * V_40 ;
const struct V_18 * V_20 ;
struct V_42 * V_53 ;
int V_27 ;
V_40 = F_44 ( (struct V_29 * ) V_30 ) ;
if ( ! V_40 )
return 0 ;
V_20 = V_40 -> V_18 ;
if ( ! V_20 )
return 0 ;
if ( F_54 ( V_52 , V_54 , V_20 -> V_19 ) < 0 )
return - V_55 ;
if ( V_20 -> V_56 ) {
V_53 = F_55 ( V_52 , V_57 ) ;
if ( ! V_53 )
return - V_55 ;
V_27 = V_20 -> V_56 ( V_52 , V_40 , V_30 ) ;
if ( V_27 < 0 )
goto V_58;
F_56 ( V_52 , V_53 ) ;
}
return 0 ;
V_58:
F_57 ( V_52 , V_53 ) ;
return V_27 ;
}
static int F_58 ( struct V_51 * V_52 ,
const struct V_29 * V_30 )
{
const struct V_18 * V_20 = V_30 -> V_18 ;
struct V_42 * V_59 ;
int V_27 ;
if ( ! V_20 )
return 0 ;
if ( F_54 ( V_52 , V_60 , V_20 -> V_19 ) < 0 )
return - V_55 ;
if ( V_20 -> V_61 ) {
V_27 = V_20 -> V_61 ( V_52 , V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_20 -> V_62 ) {
V_59 = F_55 ( V_52 , V_63 ) ;
if ( V_59 == NULL )
return - V_55 ;
V_27 = V_20 -> V_62 ( V_52 , V_30 ) ;
if ( V_27 < 0 )
goto V_64;
F_56 ( V_52 , V_59 ) ;
}
return 0 ;
V_64:
F_57 ( V_52 , V_59 ) ;
return V_27 ;
}
static int F_59 ( struct V_51 * V_52 , const struct V_29 * V_30 )
{
struct V_42 * V_65 ;
int V_27 = - V_55 ;
V_65 = F_55 ( V_52 , V_66 ) ;
if ( V_65 == NULL )
goto V_67;
V_27 = F_58 ( V_52 , V_30 ) ;
if ( V_27 < 0 )
goto V_68;
V_27 = F_53 ( V_52 , V_30 ) ;
if ( V_27 < 0 )
goto V_68;
F_56 ( V_52 , V_65 ) ;
return 0 ;
V_68:
F_57 ( V_52 , V_65 ) ;
V_67:
return V_27 ;
}
int F_60 ( struct V_51 * V_52 , struct V_28 * V_28 , T_5 V_69 , unsigned int V_70 , int V_71 )
{
struct V_72 * V_73 = V_28 -> V_73 ;
int V_27 = 0 ;
F_61 ( V_52 ) . V_74 = V_70 ;
if ( V_71 )
F_62 ( & V_52 -> V_75 ) ;
F_63 ( V_73 , V_52 , V_69 , V_70 , V_15 ) ;
if ( V_71 )
V_27 = F_64 ( V_73 , V_52 , V_69 , V_76 ) ;
return V_27 ;
}
int F_65 ( struct V_51 * V_52 , struct V_28 * V_28 , T_5 V_69 )
{
struct V_72 * V_73 = V_28 -> V_73 ;
return F_66 ( V_73 , V_52 , V_69 ) ;
}
void F_67 ( struct V_51 * V_52 , struct V_28 * V_28 , T_5 V_69 , T_5 V_70 ,
struct V_77 * V_78 , T_6 V_79 )
{
struct V_72 * V_73 = V_28 -> V_73 ;
int V_80 = 0 ;
if ( V_78 )
V_80 = F_68 ( V_78 ) ;
F_69 ( V_73 , V_52 , V_69 , V_70 , V_80 , V_79 ) ;
}
void F_70 ( struct V_28 * V_28 , T_5 V_70 , int error )
{
struct V_72 * V_73 = V_28 -> V_73 ;
F_71 ( V_73 , 0 , V_70 , error ) ;
}
int F_72 ( struct V_51 * V_52 , T_5 * V_81 )
{
struct V_42 * V_82 ;
int V_83 , V_84 = 0 ;
V_82 = F_55 ( V_52 , V_85 ) ;
if ( V_82 == NULL )
return - V_16 ;
for ( V_83 = 0 ; V_83 < V_86 ; V_83 ++ ) {
if ( V_81 [ V_83 ] ) {
if ( V_83 == V_87 - 1 ) {
char V_88 [ V_89 ] , * V_90 ;
V_90 = F_73 ( V_81 [ V_83 ] , V_88 ) ;
if ( ! V_90 )
continue;
if ( F_54 ( V_52 , V_83 + 1 , V_90 ) )
goto V_91;
} else if ( V_83 == V_92 - 1 ) {
T_5 V_93 = V_81 [ V_83 ] & V_94 ;
F_74 ( V_94 & V_95 ) ;
if ( F_75 ( V_52 , V_83 + 1 , V_93 ) )
goto V_91;
} else {
if ( F_75 ( V_52 , V_83 + 1 , V_81 [ V_83 ] ) )
goto V_91;
}
V_84 ++ ;
}
}
if ( ! V_84 ) {
F_57 ( V_52 , V_82 ) ;
return 0 ;
}
return F_56 ( V_52 , V_82 ) ;
V_91:
F_57 ( V_52 , V_82 ) ;
return - V_55 ;
}
int F_76 ( struct V_51 * V_52 , struct V_96 * V_97 , T_5 V_98 ,
long V_99 , T_5 error )
{
struct V_100 V_101 = {
. V_102 = F_77 ( V_103 - V_97 -> V_104 ) ,
. V_105 = V_97 -> V_106 ,
. V_107 = F_78 ( & ( V_97 -> V_108 ) ) ,
. V_109 = error ,
. V_110 = V_98 ,
} ;
if ( V_99 ) {
unsigned long clock ;
clock = F_79 ( abs ( V_99 ) ) ;
clock = F_80 (unsigned long, clock, INT_MAX) ;
V_101 . V_111 = ( V_99 > 0 ) ? clock : - clock ;
}
return F_81 ( V_52 , V_112 , sizeof( V_101 ) , & V_101 ) ;
}
static void F_82 ( struct V_29 * V_30 , unsigned char V_113 )
{
unsigned char V_114 = V_30 -> V_114 ;
switch ( V_113 ) {
case V_115 :
if ( ( V_114 == V_116 ||
V_114 == V_117 ) &&
! F_83 ( V_30 ) )
V_114 = V_115 ;
break;
case V_116 :
if ( V_114 == V_115 ||
V_114 == V_117 )
V_114 = V_116 ;
break;
}
if ( V_30 -> V_114 != V_114 ) {
F_84 ( & V_118 ) ;
V_30 -> V_114 = V_114 ;
F_85 ( & V_118 ) ;
F_86 ( V_30 ) ;
}
}
static unsigned int F_87 ( const struct V_29 * V_30 )
{
return ( V_30 -> V_79 & ~ ( V_119 | V_120 ) ) |
( V_30 -> V_121 & ( V_119 | V_120 ) ) ;
}
static unsigned int F_88 ( const struct V_29 * V_30 ,
const struct V_122 * V_123 )
{
unsigned int V_79 = V_123 -> V_124 ;
if ( V_123 -> V_125 )
V_79 = ( V_79 & V_123 -> V_125 ) |
( F_87 ( V_30 ) & ~ V_123 -> V_125 ) ;
return V_79 ;
}
static void F_89 ( struct V_126 * V_127 ,
const struct V_128 * V_129 )
{
V_127 -> V_130 = V_129 -> V_130 ;
V_127 -> V_131 = V_129 -> V_131 ;
V_127 -> V_132 = V_129 -> V_132 ;
V_127 -> V_133 = V_129 -> V_133 ;
V_127 -> V_134 = V_129 -> V_134 ;
V_127 -> V_135 = V_129 -> V_135 ;
V_127 -> V_136 = V_129 -> V_136 ;
V_127 -> V_137 = V_129 -> V_137 ;
V_127 -> V_138 = V_129 -> V_138 ;
V_127 -> V_139 = V_129 -> V_139 ;
V_127 -> V_140 = V_129 -> V_140 ;
V_127 -> V_141 = V_129 -> V_141 ;
V_127 -> V_142 = V_129 -> V_142 ;
V_127 -> V_143 = V_129 -> V_143 ;
V_127 -> V_144 = V_129 -> V_144 ;
V_127 -> V_145 = V_129 -> V_145 ;
V_127 -> V_146 = V_129 -> V_146 ;
V_127 -> V_147 = V_129 -> V_147 ;
V_127 -> V_148 = V_129 -> V_148 ;
V_127 -> V_149 = V_129 -> V_149 ;
V_127 -> V_150 = V_129 -> V_150 ;
V_127 -> V_151 = V_129 -> V_151 ;
V_127 -> V_152 = V_129 -> V_152 ;
V_127 -> V_153 = V_129 -> V_153 ;
}
static void F_90 ( void * V_154 , const struct V_128 * V_129 )
{
memcpy ( V_154 , V_129 , sizeof( * V_129 ) ) ;
}
static inline int F_91 ( const struct V_29 * V_30 ,
T_5 V_48 )
{
if ( V_30 -> V_30 . V_155 && F_92 ( V_30 -> V_30 . V_155 ) &&
( V_48 & V_156 ) ) {
int V_157 = F_93 ( V_30 -> V_30 . V_155 ) ;
T_4 V_43 = F_45 ( sizeof( struct V_42 ) ) ;
V_43 += F_45 ( V_157 * sizeof( struct V_42 ) ) ;
V_43 += V_157 *
( F_45 ( sizeof( struct V_158 ) ) +
F_45 ( sizeof( struct V_159 ) ) +
F_45 ( sizeof( struct V_160 ) ) +
F_45 ( sizeof( struct V_161 ) ) +
F_45 ( sizeof( struct V_162 ) ) +
F_45 ( sizeof( struct V_163 ) ) +
F_45 ( sizeof( V_164 ) ) +
F_45 ( sizeof( V_164 ) ) +
F_45 ( sizeof( V_164 ) ) +
F_45 ( sizeof( V_164 ) ) +
F_45 ( sizeof( V_164 ) ) +
F_45 ( sizeof( V_164 ) ) +
F_45 ( sizeof( struct V_165 ) ) ) ;
return V_43 ;
} else
return 0 ;
}
static T_4 F_94 ( const struct V_29 * V_30 ,
T_5 V_48 )
{
T_4 V_166 = F_45 ( 4 )
+ F_45 ( V_167 )
+ F_45 ( sizeof( struct V_168 ) )
+ F_45 ( V_169 )
+ F_45 ( V_169 )
+ F_45 ( 1 )
+ F_45 ( 2 ) ;
T_4 V_170 = F_45 ( sizeof( struct V_42 ) ) ;
T_4 V_171 = F_45 ( sizeof( struct V_42 ) )
+ V_166 ;
T_4 V_172 = F_45 ( sizeof( struct V_42 ) )
+ V_166 ;
if ( ! V_30 -> V_173 -> V_174 || ! V_30 -> V_30 . V_155 ||
! ( V_48 & V_156 ) )
return 0 ;
if ( F_93 ( V_30 -> V_30 . V_155 ) )
return V_172 + V_170 +
V_171 * F_93 ( V_30 -> V_30 . V_155 ) ;
else
return V_172 ;
}
static T_7 T_4 F_95 ( const struct V_29 * V_30 ,
T_5 V_48 )
{
return F_96 ( sizeof( struct V_122 ) )
+ F_45 ( V_175 )
+ F_45 ( V_176 )
+ F_45 ( V_175 )
+ F_45 ( sizeof( struct V_177 ) )
+ F_45 ( sizeof( struct V_126 ) )
+ F_45 ( sizeof( struct V_128 ) )
+ F_45 ( V_178 )
+ F_45 ( V_178 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 1 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 1 )
+ F_45 ( 1 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( V_48
& V_156 ? 4 : 0 )
+ F_91 ( V_30 , V_48 )
+ F_94 ( V_30 , V_48 )
+ F_46 ( V_30 )
+ F_51 ( V_30 , V_48 )
+ F_45 ( V_179 )
+ F_45 ( V_179 )
+ F_45 ( V_175 )
+ F_45 ( 1 ) ;
}
static int F_97 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
struct V_42 * V_180 ;
struct V_42 * V_181 ;
int V_182 ;
int V_27 ;
V_180 = F_55 ( V_52 , V_183 ) ;
if ( ! V_180 )
return - V_55 ;
for ( V_182 = 0 ; V_182 < F_93 ( V_30 -> V_30 . V_155 ) ; V_182 ++ ) {
V_181 = F_55 ( V_52 , V_184 ) ;
if ( ! V_181 )
goto V_91;
if ( F_75 ( V_52 , V_185 , V_182 ) )
goto V_91;
V_27 = V_30 -> V_173 -> V_174 ( V_30 , V_182 , V_52 ) ;
if ( V_27 == - V_55 )
goto V_91;
if ( V_27 ) {
F_57 ( V_52 , V_181 ) ;
continue;
}
F_56 ( V_52 , V_181 ) ;
}
F_56 ( V_52 , V_180 ) ;
return 0 ;
V_91:
F_57 ( V_52 , V_180 ) ;
return - V_55 ;
}
static int F_98 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
struct V_42 * V_186 ;
int V_27 ;
V_186 = F_55 ( V_52 , V_187 ) ;
if ( ! V_186 )
return - V_55 ;
V_27 = V_30 -> V_173 -> V_174 ( V_30 , V_188 , V_52 ) ;
if ( V_27 ) {
F_57 ( V_52 , V_186 ) ;
return ( V_27 == - V_55 ) ? V_27 : 0 ;
}
F_56 ( V_52 , V_186 ) ;
return 0 ;
}
static int F_99 ( struct V_51 * V_52 , struct V_29 * V_30 ,
T_5 V_48 )
{
int V_27 ;
if ( ! V_30 -> V_173 -> V_174 || ! V_30 -> V_30 . V_155 ||
! ( V_48 & V_156 ) )
return 0 ;
V_27 = F_98 ( V_52 , V_30 ) ;
if ( V_27 )
return V_27 ;
if ( F_93 ( V_30 -> V_30 . V_155 ) ) {
V_27 = F_97 ( V_52 , V_30 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_100 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
int V_27 ;
struct V_189 V_190 ;
V_27 = F_101 ( V_30 , & V_190 ) ;
if ( V_27 ) {
if ( V_27 == - V_191 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_52 , V_192 , V_190 . V_193 , V_190 . V_98 ) )
return - V_55 ;
return 0 ;
}
static int F_102 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
char V_90 [ V_175 ] ;
int V_27 ;
V_27 = F_103 ( V_30 , V_90 , sizeof( V_90 ) ) ;
if ( V_27 ) {
if ( V_27 == - V_191 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_52 , V_194 , strlen ( V_90 ) , V_90 ) )
return - V_55 ;
return 0 ;
}
static int F_104 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
int V_27 ;
struct V_195 V_196 = {
. V_197 = V_30 ,
. V_98 = V_198 ,
. V_79 = V_199 ,
} ;
V_27 = F_105 ( V_30 , & V_196 ) ;
if ( V_27 ) {
if ( V_27 == - V_191 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_52 , V_200 , V_196 . V_201 . V_190 . V_193 ,
V_196 . V_201 . V_190 . V_98 ) )
return - V_55 ;
return 0 ;
}
static T_8 int F_106 ( struct V_51 * V_52 ,
struct V_29 * V_30 )
{
const struct V_128 * V_202 ;
struct V_128 V_203 ;
struct V_42 * V_196 ;
V_202 = F_107 ( V_30 , & V_203 ) ;
V_196 = F_108 ( V_52 , V_204 ,
sizeof( struct V_126 ) ) ;
if ( ! V_196 )
return - V_55 ;
F_89 ( F_109 ( V_196 ) , V_202 ) ;
V_196 = F_108 ( V_52 , V_205 ,
sizeof( struct V_128 ) ) ;
if ( ! V_196 )
return - V_55 ;
F_90 ( F_109 ( V_196 ) , V_202 ) ;
return 0 ;
}
static T_8 int F_110 ( struct V_51 * V_52 ,
struct V_29 * V_30 ,
int V_206 ,
struct V_42 * V_207 )
{
struct V_163 V_208 ;
struct V_162 V_209 ;
struct V_160 V_210 ;
struct V_211 V_212 ;
struct V_213 V_214 ;
struct V_165 V_215 ;
struct V_159 V_216 ;
struct V_161 V_217 ;
struct V_42 * V_182 , * V_218 ;
struct V_158 V_219 ;
struct V_220 V_221 ;
V_221 . V_222 = - 1 ;
V_221 . V_223 = - 1 ;
V_221 . V_224 = - 1 ;
memset ( V_221 . V_225 , 0 , sizeof( V_221 . V_225 ) ) ;
V_221 . V_226 = 0 ;
if ( V_30 -> V_173 -> V_227 ( V_30 , V_206 , & V_221 ) )
return 0 ;
V_219 . V_182 =
V_216 . V_182 =
V_217 . V_182 =
V_212 . V_182 =
V_210 . V_182 =
V_209 . V_182 =
V_208 . V_182 =
V_215 . V_182 = V_221 . V_182 ;
memcpy ( V_219 . V_225 , V_221 . V_225 , sizeof( V_221 . V_225 ) ) ;
V_216 . V_228 = V_221 . V_228 ;
V_216 . V_229 = V_221 . V_229 ;
V_212 . V_230 = V_221 . V_231 ;
V_217 . V_232 = V_221 . V_232 ;
V_217 . V_231 = V_221 . V_231 ;
V_210 . V_233 = V_221 . V_222 ;
V_209 . V_234 = V_221 . V_226 ;
V_208 . V_233 = V_221 . V_223 ;
V_215 . V_233 = V_221 . V_224 ;
V_182 = F_55 ( V_52 , V_235 ) ;
if ( ! V_182 ) {
F_57 ( V_52 , V_207 ) ;
return - V_55 ;
}
if ( F_81 ( V_52 , V_236 , sizeof( V_219 ) , & V_219 ) ||
F_81 ( V_52 , V_237 , sizeof( V_216 ) , & V_216 ) ||
F_81 ( V_52 , V_238 , sizeof( V_217 ) ,
& V_217 ) ||
F_81 ( V_52 , V_239 , sizeof( V_212 ) ,
& V_212 ) ||
F_81 ( V_52 , V_240 , sizeof( V_210 ) ,
& V_210 ) ||
F_81 ( V_52 , V_241 , sizeof( V_209 ) ,
& V_209 ) ||
F_81 ( V_52 , V_242 ,
sizeof( V_208 ) ,
& V_208 ) ||
F_81 ( V_52 , V_243 ,
sizeof( V_215 ) , & V_215 ) )
return - V_55 ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
if ( V_30 -> V_173 -> V_244 )
V_30 -> V_173 -> V_244 ( V_30 , V_206 ,
& V_214 ) ;
V_218 = F_55 ( V_52 , V_245 ) ;
if ( ! V_218 ) {
F_57 ( V_52 , V_182 ) ;
F_57 ( V_52 , V_207 ) ;
return - V_55 ;
}
if ( F_111 ( V_52 , V_246 ,
V_214 . V_130 ) ||
F_111 ( V_52 , V_247 ,
V_214 . V_131 ) ||
F_111 ( V_52 , V_248 ,
V_214 . V_132 ) ||
F_111 ( V_52 , V_249 ,
V_214 . V_133 ) ||
F_111 ( V_52 , V_250 ,
V_214 . V_251 ) ||
F_111 ( V_52 , V_252 ,
V_214 . V_138 ) )
return - V_55 ;
F_56 ( V_52 , V_218 ) ;
F_56 ( V_52 , V_182 ) ;
return 0 ;
}
static int F_112 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
struct V_177 V_253 ;
memset ( & V_253 , 0 , sizeof( V_253 ) ) ;
V_253 . V_254 = V_30 -> V_254 ;
V_253 . V_255 = V_30 -> V_255 ;
V_253 . V_256 = V_30 -> V_256 ;
V_253 . V_257 = V_30 -> V_257 ;
V_253 . V_258 = V_30 -> V_258 ;
V_253 . V_259 = V_30 -> V_260 ;
if ( F_81 ( V_52 , V_261 , sizeof( V_253 ) , & V_253 ) )
return - V_55 ;
return 0 ;
}
static int F_113 ( struct V_51 * V_52 , struct V_29 * V_30 ,
int type , T_5 V_69 , T_5 V_262 , T_5 V_263 ,
unsigned int V_79 , T_5 V_48 )
{
struct V_122 * V_123 ;
struct V_77 * V_78 ;
struct V_42 * V_264 ;
struct V_46 * V_49 ;
struct V_29 * V_265 = F_44 ( V_30 ) ;
F_114 () ;
V_78 = F_115 ( V_52 , V_69 , V_262 , type , sizeof( * V_123 ) , V_79 ) ;
if ( V_78 == NULL )
return - V_55 ;
V_123 = F_116 ( V_78 ) ;
V_123 -> V_266 = V_267 ;
V_123 -> V_268 = 0 ;
V_123 -> V_269 = V_30 -> type ;
V_123 -> V_270 = V_30 -> V_271 ;
V_123 -> V_124 = F_117 ( V_30 ) ;
V_123 -> V_125 = V_263 ;
if ( F_54 ( V_52 , V_272 , V_30 -> V_90 ) ||
F_75 ( V_52 , V_273 , V_30 -> V_274 ) ||
F_118 ( V_52 , V_275 ,
F_119 ( V_30 ) ? V_30 -> V_114 : V_276 ) ||
F_118 ( V_52 , V_277 , V_30 -> V_278 ) ||
F_75 ( V_52 , V_279 , V_30 -> V_280 ) ||
F_75 ( V_52 , V_281 , V_30 -> V_70 ) ||
F_75 ( V_52 , V_282 , V_30 -> V_283 ) ||
F_75 ( V_52 , V_284 , V_30 -> V_285 ) ||
F_75 ( V_52 , V_286 , V_30 -> V_287 ) ||
F_75 ( V_52 , V_288 , V_30 -> V_289 ) ||
#ifdef F_120
F_75 ( V_52 , V_290 , V_30 -> V_291 ) ||
#endif
( V_30 -> V_271 != F_121 ( V_30 ) &&
F_75 ( V_52 , V_292 , F_121 ( V_30 ) ) ) ||
( V_265 &&
F_75 ( V_52 , V_293 , V_265 -> V_271 ) ) ||
F_118 ( V_52 , V_294 , F_122 ( V_30 ) ) ||
( V_30 -> V_295 &&
F_54 ( V_52 , V_296 , V_30 -> V_295 -> V_20 -> V_98 ) ) ||
( V_30 -> V_297 &&
F_54 ( V_52 , V_298 , V_30 -> V_297 ) ) ||
F_75 ( V_52 , V_299 ,
F_78 ( & V_30 -> V_300 ) ) ||
F_118 ( V_52 , V_301 , V_30 -> V_302 ) )
goto V_91;
if ( F_112 ( V_52 , V_30 ) )
goto V_91;
if ( V_30 -> V_303 ) {
if ( F_81 ( V_52 , V_304 , V_30 -> V_303 , V_30 -> V_305 ) ||
F_81 ( V_52 , V_306 , V_30 -> V_303 , V_30 -> V_251 ) )
goto V_91;
}
if ( F_100 ( V_52 , V_30 ) )
goto V_91;
if ( F_102 ( V_52 , V_30 ) )
goto V_91;
if ( F_104 ( V_52 , V_30 ) )
goto V_91;
if ( F_106 ( V_52 , V_30 ) )
goto V_91;
if ( V_30 -> V_30 . V_155 && ( V_48 & V_156 ) &&
F_75 ( V_52 , V_307 , F_93 ( V_30 -> V_30 . V_155 ) ) )
goto V_91;
if ( V_30 -> V_173 -> V_227 && V_30 -> V_30 . V_155 &&
V_48 & V_156 ) {
int V_83 ;
struct V_42 * V_207 ;
int V_157 = F_93 ( V_30 -> V_30 . V_155 ) ;
V_207 = F_55 ( V_52 , V_308 ) ;
if ( ! V_207 )
goto V_91;
for ( V_83 = 0 ; V_83 < V_157 ; V_83 ++ ) {
if ( F_110 ( V_52 , V_30 , V_83 , V_207 ) )
goto V_91;
}
F_56 ( V_52 , V_207 ) ;
}
if ( F_99 ( V_52 , V_30 , V_48 ) )
goto V_91;
if ( V_30 -> V_18 || F_52 ( V_30 ) ) {
if ( F_59 ( V_52 , V_30 ) < 0 )
goto V_91;
}
if ( V_30 -> V_18 &&
V_30 -> V_18 -> V_309 ) {
struct V_28 * V_310 = V_30 -> V_18 -> V_309 ( V_30 ) ;
if ( ! F_123 ( F_124 ( V_30 ) , V_310 ) ) {
int V_98 = F_125 ( F_124 ( V_30 ) , V_310 ) ;
if ( F_126 ( V_52 , V_311 , V_98 ) )
goto V_91;
}
}
if ( ! ( V_264 = F_55 ( V_52 , V_312 ) ) )
goto V_91;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_49 -> V_313 ) {
struct V_42 * V_314 ;
int V_27 ;
if ( ! ( V_314 = F_55 ( V_52 , V_49 -> V_47 ) ) )
goto V_91;
V_27 = V_49 -> V_313 ( V_52 , V_30 , V_48 ) ;
if ( V_27 == - V_315 )
F_57 ( V_52 , V_314 ) ;
else if ( V_27 < 0 )
goto V_91;
F_56 ( V_52 , V_314 ) ;
}
}
F_56 ( V_52 , V_264 ) ;
F_127 ( V_52 , V_78 ) ;
return 0 ;
V_91:
F_128 ( V_52 , V_78 ) ;
return - V_55 ;
}
static const struct V_18 * F_129 ( const struct V_42 * V_316 )
{
const struct V_18 * V_20 = NULL ;
struct V_42 * V_317 [ V_318 + 1 ] ;
if ( F_130 ( V_317 , V_318 , V_316 , V_319 ) < 0 )
return NULL ;
if ( V_317 [ V_60 ] ) {
char V_19 [ V_320 ] ;
F_131 ( V_19 , V_317 [ V_60 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
}
return V_20 ;
}
static bool F_132 ( struct V_29 * V_30 , int V_321 )
{
struct V_29 * V_322 ;
if ( ! V_321 )
return false ;
V_322 = F_44 ( V_30 ) ;
if ( ! V_322 || V_322 -> V_271 != V_321 )
return true ;
return false ;
}
static bool F_133 ( const struct V_29 * V_30 ,
const struct V_18 * V_323 )
{
if ( V_323 && V_30 -> V_18 != V_323 )
return true ;
return false ;
}
static bool F_134 ( struct V_29 * V_30 ,
int V_321 ,
const struct V_18 * V_323 )
{
if ( F_132 ( V_30 , V_321 ) ||
F_133 ( V_30 , V_323 ) )
return true ;
return false ;
}
static int F_135 ( struct V_51 * V_52 , struct V_324 * V_325 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
int V_327 , V_328 ;
int V_329 = 0 , V_330 ;
struct V_29 * V_30 ;
struct V_331 * V_332 ;
struct V_42 * V_333 [ V_334 + 1 ] ;
T_5 V_48 = 0 ;
const struct V_18 * V_323 = NULL ;
unsigned int V_79 = V_335 ;
int V_321 = 0 ;
int V_27 ;
int V_336 ;
V_328 = V_325 -> args [ 0 ] ;
V_330 = V_325 -> args [ 1 ] ;
V_325 -> V_262 = V_28 -> V_337 ;
V_336 = F_137 ( V_325 -> V_78 ) < sizeof( struct V_122 ) ?
sizeof( struct V_338 ) : sizeof( struct V_122 ) ;
if ( F_138 ( V_325 -> V_78 , V_336 , V_333 , V_334 , V_339 ) >= 0 ) {
if ( V_333 [ V_340 ] )
V_48 = F_139 ( V_333 [ V_340 ] ) ;
if ( V_333 [ V_293 ] )
V_321 = F_139 ( V_333 [ V_293 ] ) ;
if ( V_333 [ V_66 ] )
V_323 = F_129 ( V_333 [ V_66 ] ) ;
if ( V_321 || V_323 )
V_79 |= V_341 ;
}
for ( V_327 = V_328 ; V_327 < V_342 ; V_327 ++ , V_330 = 0 ) {
V_329 = 0 ;
V_332 = & V_28 -> V_343 [ V_327 ] ;
F_140 (dev, head, index_hlist) {
if ( F_134 ( V_30 , V_321 , V_323 ) )
continue;
if ( V_329 < V_330 )
goto V_344;
V_27 = F_113 ( V_52 , V_30 , V_345 ,
F_61 ( V_325 -> V_52 ) . V_346 ,
V_325 -> V_78 -> V_347 , 0 ,
V_79 ,
V_48 ) ;
F_141 ( ( V_27 == - V_55 ) && ( V_52 -> V_348 == 0 ) ) ;
if ( V_27 < 0 )
goto V_67;
F_142 ( V_325 , F_143 ( V_52 ) ) ;
V_344:
V_329 ++ ;
}
}
V_67:
V_325 -> args [ 1 ] = V_329 ;
V_325 -> args [ 0 ] = V_327 ;
return V_52 -> V_348 ;
}
int F_144 ( struct V_42 * * V_333 , const struct V_42 * V_332 , int V_348 )
{
return F_145 ( V_333 , V_334 , V_332 , V_348 , V_339 ) ;
}
struct V_28 * F_146 ( struct V_28 * V_349 , struct V_42 * V_333 [] )
{
struct V_28 * V_28 ;
if ( V_333 [ V_350 ] )
V_28 = F_147 ( F_139 ( V_333 [ V_350 ] ) ) ;
else if ( V_333 [ V_351 ] )
V_28 = F_148 ( F_139 ( V_333 [ V_351 ] ) ) ;
else
V_28 = F_149 ( V_349 ) ;
return V_28 ;
}
static int F_150 ( struct V_29 * V_30 , struct V_42 * V_333 [] )
{
if ( V_30 ) {
if ( V_333 [ V_304 ] &&
F_151 ( V_333 [ V_304 ] ) < V_30 -> V_303 )
return - V_352 ;
if ( V_333 [ V_306 ] &&
F_151 ( V_333 [ V_306 ] ) < V_30 -> V_303 )
return - V_352 ;
}
if ( V_333 [ V_312 ] ) {
struct V_42 * V_314 ;
int V_353 , V_27 ;
F_152 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_49 ;
if ( ! ( V_49 = F_47 ( F_153 ( V_314 ) ) ) )
return - V_354 ;
if ( ! V_49 -> V_355 )
return - V_191 ;
if ( V_49 -> V_356 ) {
V_27 = V_49 -> V_356 ( V_30 , V_314 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_154 ( struct V_29 * V_30 , struct V_357 * V_358 ,
int V_359 )
{
const struct V_360 * V_20 = V_30 -> V_173 ;
return V_20 -> V_361 ( V_30 , V_358 -> V_182 , V_358 -> V_362 , V_359 ) ;
}
static int F_155 ( struct V_29 * V_30 , struct V_357 * V_358 , int V_359 )
{
if ( V_30 -> type != V_363 )
return - V_191 ;
return F_154 ( V_30 , V_358 , V_359 ) ;
}
static int F_156 ( struct V_29 * V_30 , struct V_42 * * V_333 )
{
const struct V_360 * V_20 = V_30 -> V_173 ;
int V_27 = - V_352 ;
if ( V_333 [ V_236 ] ) {
struct V_158 * V_364 = F_109 ( V_333 [ V_236 ] ) ;
V_27 = - V_191 ;
if ( V_20 -> V_365 )
V_27 = V_20 -> V_365 ( V_30 , V_364 -> V_182 ,
V_364 -> V_225 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_333 [ V_237 ] ) {
struct V_159 * V_366 = F_109 ( V_333 [ V_237 ] ) ;
V_27 = - V_191 ;
if ( V_20 -> V_367 )
V_27 = V_20 -> V_367 ( V_30 , V_366 -> V_182 , V_366 -> V_228 ,
V_366 -> V_229 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_333 [ V_239 ] ) {
struct V_211 * V_358 = F_109 ( V_333 [ V_239 ] ) ;
struct V_220 V_368 ;
V_27 = - V_191 ;
if ( V_20 -> V_227 )
V_27 = V_20 -> V_227 ( V_30 , V_358 -> V_182 , & V_368 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = - V_191 ;
if ( V_20 -> V_369 )
V_27 = V_20 -> V_369 ( V_30 , V_358 -> V_182 ,
V_368 . V_232 ,
V_358 -> V_230 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_333 [ V_238 ] ) {
struct V_161 * V_358 = F_109 ( V_333 [ V_238 ] ) ;
V_27 = - V_191 ;
if ( V_20 -> V_369 )
V_27 = V_20 -> V_369 ( V_30 , V_358 -> V_182 ,
V_358 -> V_232 ,
V_358 -> V_231 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_333 [ V_240 ] ) {
struct V_160 * V_370 = F_109 ( V_333 [ V_240 ] ) ;
V_27 = - V_191 ;
if ( V_20 -> V_371 )
V_27 = V_20 -> V_371 ( V_30 , V_370 -> V_182 ,
V_370 -> V_233 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_333 [ V_241 ] ) {
struct V_162 * V_372 = F_109 ( V_333 [ V_241 ] ) ;
V_27 = - V_191 ;
if ( V_20 -> V_373 )
V_27 = V_20 -> V_373 ( V_30 , V_372 -> V_182 ,
V_372 -> V_234 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_333 [ V_242 ] ) {
struct V_163 * V_374 ;
V_27 = - V_191 ;
V_374 = F_109 ( V_333 [ V_242 ] ) ;
if ( V_20 -> V_375 )
V_27 = V_20 -> V_375 ( V_30 , V_374 -> V_182 ,
V_374 -> V_233 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_333 [ V_243 ] ) {
struct V_165 * V_358 = F_109 ( V_333 [ V_243 ] ) ;
V_27 = - V_191 ;
if ( V_20 -> V_376 )
V_27 = V_20 -> V_376 ( V_30 , V_358 -> V_182 , V_358 -> V_233 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_333 [ V_377 ] ) {
struct V_357 * V_358 = F_109 ( V_333 [ V_377 ] ) ;
if ( ! V_20 -> V_361 )
return - V_191 ;
return F_155 ( V_30 , V_358 , V_377 ) ;
}
if ( V_333 [ V_378 ] ) {
struct V_357 * V_358 = F_109 ( V_333 [ V_378 ] ) ;
if ( ! V_20 -> V_361 )
return - V_191 ;
return F_155 ( V_30 , V_358 , V_378 ) ;
}
return V_27 ;
}
static int F_157 ( struct V_29 * V_30 , int V_271 )
{
struct V_29 * V_265 = F_44 ( V_30 ) ;
const struct V_360 * V_20 ;
int V_27 ;
if ( V_265 ) {
if ( V_265 -> V_271 == V_271 )
return 0 ;
V_20 = V_265 -> V_173 ;
if ( V_20 -> V_379 ) {
V_27 = V_20 -> V_379 ( V_265 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_191 ;
}
}
if ( V_271 ) {
V_265 = F_158 ( F_124 ( V_30 ) , V_271 ) ;
if ( ! V_265 )
return - V_352 ;
V_20 = V_265 -> V_173 ;
if ( V_20 -> V_380 ) {
V_27 = V_20 -> V_380 ( V_265 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_191 ;
}
}
return 0 ;
}
static int F_159 ( const struct V_51 * V_52 ,
struct V_29 * V_30 , struct V_122 * V_123 ,
struct V_42 * * V_333 , char * V_381 , int V_382 )
{
const struct V_360 * V_20 = V_30 -> V_173 ;
int V_27 ;
if ( V_333 [ V_350 ] || V_333 [ V_351 ] ) {
struct V_28 * V_28 = F_146 ( F_124 ( V_30 ) , V_333 ) ;
if ( F_160 ( V_28 ) ) {
V_27 = F_161 ( V_28 ) ;
goto V_383;
}
if ( ! F_162 ( V_52 , V_28 -> V_384 , V_385 ) ) {
F_163 ( V_28 ) ;
V_27 = - V_386 ;
goto V_383;
}
V_27 = F_164 ( V_30 , V_28 , V_381 ) ;
F_163 ( V_28 ) ;
if ( V_27 )
goto V_383;
V_382 |= V_387 ;
}
if ( V_333 [ V_261 ] ) {
struct V_177 * V_388 ;
struct V_389 V_390 ;
if ( ! V_20 -> V_391 ) {
V_27 = - V_191 ;
goto V_383;
}
if ( ! F_165 ( V_30 ) ) {
V_27 = - V_392 ;
goto V_383;
}
V_388 = F_109 ( V_333 [ V_261 ] ) ;
V_390 . V_254 = ( unsigned long ) V_388 -> V_254 ;
V_390 . V_255 = ( unsigned long ) V_388 -> V_255 ;
V_390 . V_256 = ( unsigned short ) V_388 -> V_256 ;
V_390 . V_257 = ( unsigned char ) V_388 -> V_257 ;
V_390 . V_258 = ( unsigned char ) V_388 -> V_258 ;
V_390 . V_259 = ( unsigned char ) V_388 -> V_259 ;
V_27 = V_20 -> V_391 ( V_30 , & V_390 ) ;
if ( V_27 < 0 )
goto V_383;
V_382 |= V_393 ;
}
if ( V_333 [ V_304 ] ) {
struct V_394 * V_395 ;
int V_348 ;
V_348 = sizeof( V_396 ) + V_30 -> V_303 ;
V_395 = F_166 ( V_348 , V_15 ) ;
if ( ! V_395 ) {
V_27 = - V_397 ;
goto V_383;
}
V_395 -> V_398 = V_30 -> type ;
memcpy ( V_395 -> V_399 , F_109 ( V_333 [ V_304 ] ) ,
V_30 -> V_303 ) ;
V_27 = F_167 ( V_30 , V_395 ) ;
F_24 ( V_395 ) ;
if ( V_27 )
goto V_383;
V_382 |= V_387 ;
}
if ( V_333 [ V_279 ] ) {
V_27 = F_168 ( V_30 , F_139 ( V_333 [ V_279 ] ) ) ;
if ( V_27 < 0 )
goto V_383;
V_382 |= V_387 ;
}
if ( V_333 [ V_281 ] ) {
F_169 ( V_30 , F_139 ( V_333 [ V_281 ] ) ) ;
V_382 |= V_393 ;
}
if ( V_123 -> V_270 > 0 && V_381 [ 0 ] ) {
V_27 = F_170 ( V_30 , V_381 ) ;
if ( V_27 < 0 )
goto V_383;
V_382 |= V_387 ;
}
if ( V_333 [ V_298 ] ) {
V_27 = F_171 ( V_30 , F_109 ( V_333 [ V_298 ] ) ,
F_151 ( V_333 [ V_298 ] ) ) ;
if ( V_27 < 0 )
goto V_383;
V_382 |= V_393 ;
}
if ( V_333 [ V_306 ] ) {
F_172 ( V_30 -> V_251 , V_333 [ V_306 ] , V_30 -> V_303 ) ;
F_173 ( V_400 , V_30 ) ;
}
if ( V_123 -> V_124 || V_123 -> V_125 ) {
V_27 = F_174 ( V_30 , F_88 ( V_30 , V_123 ) ) ;
if ( V_27 < 0 )
goto V_383;
}
if ( V_333 [ V_293 ] ) {
V_27 = F_157 ( V_30 , F_139 ( V_333 [ V_293 ] ) ) ;
if ( V_27 )
goto V_383;
V_382 |= V_387 ;
}
if ( V_333 [ V_294 ] ) {
V_27 = F_175 ( V_30 , F_176 ( V_333 [ V_294 ] ) ) ;
if ( V_27 )
goto V_383;
V_382 |= V_387 ;
}
if ( V_333 [ V_273 ] ) {
unsigned long V_401 = F_139 ( V_333 [ V_273 ] ) ;
if ( V_30 -> V_274 ^ V_401 )
V_382 |= V_393 ;
V_30 -> V_274 = V_401 ;
}
if ( V_333 [ V_275 ] )
F_82 ( V_30 , F_176 ( V_333 [ V_275 ] ) ) ;
if ( V_333 [ V_277 ] ) {
unsigned char V_401 = F_176 ( V_333 [ V_277 ] ) ;
F_84 ( & V_118 ) ;
if ( V_30 -> V_278 ^ V_401 )
V_382 |= V_393 ;
V_30 -> V_278 = V_401 ;
F_85 ( & V_118 ) ;
}
if ( V_333 [ V_308 ] ) {
struct V_42 * V_207 [ V_402 + 1 ] ;
struct V_42 * V_196 ;
int V_353 ;
F_152 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_153 ( V_196 ) != V_235 ||
F_151 ( V_196 ) < V_403 ) {
V_27 = - V_352 ;
goto V_383;
}
V_27 = F_130 ( V_207 , V_402 , V_196 ,
V_404 ) ;
if ( V_27 < 0 )
goto V_383;
V_27 = F_156 ( V_30 , V_207 ) ;
if ( V_27 < 0 )
goto V_383;
V_382 |= V_393 ;
}
}
V_27 = 0 ;
if ( V_333 [ V_183 ] ) {
struct V_42 * V_259 [ V_405 + 1 ] ;
struct V_42 * V_196 ;
int V_182 ;
int V_353 ;
V_27 = - V_191 ;
if ( ! V_20 -> V_406 )
goto V_383;
F_152 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_153 ( V_196 ) != V_184 ||
F_151 ( V_196 ) < V_403 ) {
V_27 = - V_352 ;
goto V_383;
}
V_27 = F_130 ( V_259 , V_405 , V_196 ,
V_407 ) ;
if ( V_27 < 0 )
goto V_383;
if ( ! V_259 [ V_185 ] ) {
V_27 = - V_191 ;
goto V_383;
}
V_182 = F_139 ( V_259 [ V_185 ] ) ;
V_27 = V_20 -> V_406 ( V_30 , V_182 , V_259 ) ;
if ( V_27 < 0 )
goto V_383;
V_382 |= V_393 ;
}
}
V_27 = 0 ;
if ( V_333 [ V_187 ] ) {
struct V_42 * V_259 [ V_405 + 1 ] ;
V_27 = F_130 ( V_259 , V_405 ,
V_333 [ V_187 ] , V_407 ) ;
if ( V_27 < 0 )
goto V_383;
V_27 = - V_191 ;
if ( V_20 -> V_406 )
V_27 = V_20 -> V_406 ( V_30 , V_188 , V_259 ) ;
if ( V_27 < 0 )
goto V_383;
V_382 |= V_393 ;
}
if ( V_333 [ V_312 ] ) {
struct V_42 * V_314 ;
int V_353 ;
F_152 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_49 ;
if ( ! ( V_49 = F_47 ( F_153 ( V_314 ) ) ) )
F_177 () ;
V_27 = V_49 -> V_355 ( V_30 , V_314 ) ;
if ( V_27 < 0 )
goto V_383;
V_382 |= V_393 ;
}
}
V_27 = 0 ;
if ( V_333 [ V_301 ] ) {
V_27 = F_178 ( V_30 ,
F_176 ( V_333 [ V_301 ] ) ) ;
if ( V_27 )
goto V_383;
V_382 |= V_393 ;
}
V_383:
if ( V_382 & V_387 ) {
if ( V_382 & V_393 )
F_86 ( V_30 ) ;
if ( V_27 < 0 )
F_179 ( L_3 ,
V_30 -> V_90 ) ;
}
return V_27 ;
}
static int F_180 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
struct V_122 * V_123 ;
struct V_29 * V_30 ;
int V_27 ;
struct V_42 * V_333 [ V_334 + 1 ] ;
char V_381 [ V_175 ] ;
V_27 = F_138 ( V_78 , sizeof( * V_123 ) , V_333 , V_334 , V_339 ) ;
if ( V_27 < 0 )
goto V_383;
if ( V_333 [ V_272 ] )
F_131 ( V_381 , V_333 [ V_272 ] , V_175 ) ;
else
V_381 [ 0 ] = '\0' ;
V_27 = - V_352 ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_270 > 0 )
V_30 = F_158 ( V_28 , V_123 -> V_270 ) ;
else if ( V_333 [ V_272 ] )
V_30 = F_181 ( V_28 , V_381 ) ;
else
goto V_383;
if ( V_30 == NULL ) {
V_27 = - V_392 ;
goto V_383;
}
V_27 = F_150 ( V_30 , V_333 ) ;
if ( V_27 < 0 )
goto V_383;
V_27 = F_159 ( V_52 , V_30 , V_123 , V_333 , V_381 , 0 ) ;
V_383:
return V_27 ;
}
static int F_182 ( const struct V_28 * V_28 , int V_70 )
{
struct V_29 * V_30 , * V_408 ;
F_31 ( V_31 ) ;
bool V_409 = false ;
if ( ! V_70 )
return - V_386 ;
F_32 (net, dev) {
if ( V_30 -> V_70 == V_70 ) {
const struct V_18 * V_20 ;
V_409 = true ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_191 ;
}
}
if ( ! V_409 )
return - V_392 ;
F_183 (net, dev, aux) {
if ( V_30 -> V_70 == V_70 ) {
const struct V_18 * V_20 ;
V_20 = V_30 -> V_18 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
}
}
F_33 ( & V_31 ) ;
return 0 ;
}
int F_184 ( struct V_29 * V_30 )
{
const struct V_18 * V_20 ;
F_31 ( V_31 ) ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_191 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
return 0 ;
}
static int F_185 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
struct V_29 * V_30 ;
struct V_122 * V_123 ;
char V_381 [ V_175 ] ;
struct V_42 * V_333 [ V_334 + 1 ] ;
int V_27 ;
V_27 = F_138 ( V_78 , sizeof( * V_123 ) , V_333 , V_334 , V_339 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_333 [ V_272 ] )
F_131 ( V_381 , V_333 [ V_272 ] , V_175 ) ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_270 > 0 )
V_30 = F_158 ( V_28 , V_123 -> V_270 ) ;
else if ( V_333 [ V_272 ] )
V_30 = F_181 ( V_28 , V_381 ) ;
else if ( V_333 [ V_281 ] )
return F_182 ( V_28 , F_139 ( V_333 [ V_281 ] ) ) ;
else
return - V_352 ;
if ( ! V_30 )
return - V_392 ;
return F_184 ( V_30 ) ;
}
int F_186 ( struct V_29 * V_30 , const struct V_122 * V_123 )
{
unsigned int V_410 ;
int V_27 ;
V_410 = V_30 -> V_79 ;
if ( V_123 && ( V_123 -> V_124 || V_123 -> V_125 ) ) {
V_27 = F_187 ( V_30 , F_88 ( V_30 , V_123 ) ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_30 -> V_411 = V_412 ;
F_188 ( V_30 , V_410 , ~ 0U ) ;
return 0 ;
}
struct V_29 * F_189 ( struct V_28 * V_28 ,
const char * V_381 , unsigned char V_413 ,
const struct V_18 * V_20 , struct V_42 * V_333 [] )
{
int V_27 ;
struct V_29 * V_30 ;
unsigned int V_285 = 1 ;
unsigned int V_291 = 1 ;
if ( V_333 [ V_284 ] )
V_285 = F_139 ( V_333 [ V_284 ] ) ;
else if ( V_20 -> V_414 )
V_285 = V_20 -> V_414 () ;
if ( V_333 [ V_290 ] )
V_291 = F_139 ( V_333 [ V_290 ] ) ;
else if ( V_20 -> V_415 )
V_291 = V_20 -> V_415 () ;
V_27 = - V_397 ;
V_30 = F_190 ( V_20 -> V_416 , V_381 , V_413 ,
V_20 -> V_22 , V_285 , V_291 ) ;
if ( ! V_30 )
goto V_27;
F_191 ( V_30 , V_28 ) ;
V_30 -> V_18 = V_20 ;
V_30 -> V_411 = V_417 ;
if ( V_333 [ V_279 ] )
V_30 -> V_280 = F_139 ( V_333 [ V_279 ] ) ;
if ( V_333 [ V_304 ] ) {
memcpy ( V_30 -> V_305 , F_109 ( V_333 [ V_304 ] ) ,
F_151 ( V_333 [ V_304 ] ) ) ;
V_30 -> V_418 = V_419 ;
}
if ( V_333 [ V_306 ] )
memcpy ( V_30 -> V_251 , F_109 ( V_333 [ V_306 ] ) ,
F_151 ( V_333 [ V_306 ] ) ) ;
if ( V_333 [ V_273 ] )
V_30 -> V_274 = F_139 ( V_333 [ V_273 ] ) ;
if ( V_333 [ V_275 ] )
F_82 ( V_30 , F_176 ( V_333 [ V_275 ] ) ) ;
if ( V_333 [ V_277 ] )
V_30 -> V_278 = F_176 ( V_333 [ V_277 ] ) ;
if ( V_333 [ V_281 ] )
F_169 ( V_30 , F_139 ( V_333 [ V_281 ] ) ) ;
return V_30 ;
V_27:
return F_192 ( V_27 ) ;
}
static int F_193 ( const struct V_51 * V_52 ,
struct V_28 * V_28 , int V_70 ,
struct V_122 * V_123 ,
struct V_42 * * V_333 )
{
struct V_29 * V_30 , * V_408 ;
int V_27 ;
F_183 (net, dev, aux) {
if ( V_30 -> V_70 == V_70 ) {
V_27 = F_159 ( V_52 , V_30 , V_123 , V_333 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_194 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_420 = NULL ;
struct V_29 * V_30 ;
struct V_29 * V_40 = NULL ;
struct V_122 * V_123 ;
char V_19 [ V_320 ] ;
char V_381 [ V_175 ] ;
struct V_42 * V_333 [ V_334 + 1 ] ;
struct V_42 * V_65 [ V_318 + 1 ] ;
unsigned char V_413 = V_421 ;
int V_27 ;
#ifdef F_195
V_422:
#endif
V_27 = F_138 ( V_78 , sizeof( * V_123 ) , V_333 , V_334 , V_339 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_333 [ V_272 ] )
F_131 ( V_381 , V_333 [ V_272 ] , V_175 ) ;
else
V_381 [ 0 ] = '\0' ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_270 > 0 )
V_30 = F_158 ( V_28 , V_123 -> V_270 ) ;
else {
if ( V_381 [ 0 ] )
V_30 = F_181 ( V_28 , V_381 ) ;
else
V_30 = NULL ;
}
if ( V_30 ) {
V_40 = F_44 ( V_30 ) ;
if ( V_40 )
V_420 = V_40 -> V_18 ;
}
V_27 = F_150 ( V_30 , V_333 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_333 [ V_66 ] ) {
V_27 = F_130 ( V_65 , V_318 ,
V_333 [ V_66 ] , V_319 ) ;
if ( V_27 < 0 )
return V_27 ;
} else
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
if ( V_65 [ V_60 ] ) {
F_131 ( V_19 , V_65 [ V_60 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_42 * V_196 [ V_20 ? V_20 -> V_423 + 1 : 1 ] ;
struct V_42 * V_424 [ V_420 ? V_420 -> V_425 + 1 : 1 ] ;
struct V_42 * * V_59 = NULL ;
struct V_42 * * V_53 = NULL ;
struct V_28 * V_426 , * V_310 = NULL ;
if ( V_20 ) {
if ( V_20 -> V_423 && V_65 [ V_63 ] ) {
V_27 = F_130 ( V_196 , V_20 -> V_423 ,
V_65 [ V_63 ] ,
V_20 -> V_427 ) ;
if ( V_27 < 0 )
return V_27 ;
V_59 = V_196 ;
}
if ( V_20 -> V_428 ) {
V_27 = V_20 -> V_428 ( V_333 , V_59 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_420 ) {
if ( V_420 -> V_425 &&
V_65 [ V_57 ] ) {
V_27 = F_130 ( V_424 ,
V_420 -> V_425 ,
V_65 [ V_57 ] ,
V_420 -> V_429 ) ;
if ( V_27 < 0 )
return V_27 ;
V_53 = V_424 ;
}
if ( V_420 -> V_430 ) {
V_27 = V_420 -> V_430 ( V_333 , V_53 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_30 ) {
int V_382 = 0 ;
if ( V_78 -> V_431 & V_432 )
return - V_21 ;
if ( V_78 -> V_431 & V_433 )
return - V_191 ;
if ( V_65 [ V_63 ] ) {
if ( ! V_20 || V_20 != V_30 -> V_18 ||
! V_20 -> V_434 )
return - V_191 ;
V_27 = V_20 -> V_434 ( V_30 , V_333 , V_59 ) ;
if ( V_27 < 0 )
return V_27 ;
V_382 |= V_393 ;
}
if ( V_65 [ V_57 ] ) {
if ( ! V_420 || ! V_420 -> V_435 )
return - V_191 ;
V_27 = V_420 -> V_435 ( V_40 , V_30 ,
V_333 , V_53 ) ;
if ( V_27 < 0 )
return V_27 ;
V_382 |= V_393 ;
}
return F_159 ( V_52 , V_30 , V_123 , V_333 , V_381 , V_382 ) ;
}
if ( ! ( V_78 -> V_431 & V_436 ) ) {
if ( V_123 -> V_270 == 0 && V_333 [ V_281 ] )
return F_193 ( V_52 , V_28 ,
F_139 ( V_333 [ V_281 ] ) ,
V_123 , V_333 ) ;
return - V_392 ;
}
if ( V_333 [ V_261 ] || V_333 [ V_293 ] || V_333 [ V_437 ] )
return - V_191 ;
if ( ! V_20 ) {
#ifdef F_195
if ( V_19 [ 0 ] ) {
F_3 () ;
F_196 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_422;
}
#endif
return - V_191 ;
}
if ( ! V_20 -> V_22 )
return - V_191 ;
if ( ! V_381 [ 0 ] ) {
snprintf ( V_381 , V_175 , L_5 , V_20 -> V_19 ) ;
V_413 = V_438 ;
}
V_426 = F_146 ( V_28 , V_333 ) ;
if ( F_160 ( V_426 ) )
return F_161 ( V_426 ) ;
V_27 = - V_386 ;
if ( ! F_162 ( V_52 , V_426 -> V_384 , V_385 ) )
goto V_67;
if ( V_333 [ V_311 ] ) {
int V_98 = F_197 ( V_333 [ V_311 ] ) ;
V_310 = F_198 ( V_426 , V_98 ) ;
if ( ! V_310 ) {
V_27 = - V_352 ;
goto V_67;
}
V_27 = - V_386 ;
if ( ! F_162 ( V_52 , V_310 -> V_384 , V_385 ) )
goto V_67;
}
V_30 = F_189 ( V_310 ? : V_426 , V_381 ,
V_413 , V_20 , V_333 ) ;
if ( F_160 ( V_30 ) ) {
V_27 = F_161 ( V_30 ) ;
goto V_67;
}
V_30 -> V_271 = V_123 -> V_270 ;
if ( V_20 -> V_439 ) {
V_27 = V_20 -> V_439 ( V_310 ? : V_28 , V_30 , V_333 , V_59 ) ;
if ( V_27 < 0 ) {
if ( V_30 -> V_440 == V_441 )
F_199 ( V_30 ) ;
goto V_67;
}
} else {
V_27 = F_200 ( V_30 ) ;
if ( V_27 < 0 ) {
F_199 ( V_30 ) ;
goto V_67;
}
}
V_27 = F_186 ( V_30 , V_123 ) ;
if ( V_27 < 0 )
goto V_442;
if ( V_310 ) {
V_27 = F_164 ( V_30 , V_426 , V_381 ) ;
if ( V_27 < 0 )
goto V_442;
}
V_67:
if ( V_310 )
F_163 ( V_310 ) ;
F_163 ( V_426 ) ;
return V_27 ;
V_442:
if ( V_20 -> V_439 ) {
F_31 ( V_31 ) ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
} else {
F_201 ( V_30 ) ;
}
goto V_67;
}
}
static int F_202 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
struct V_122 * V_123 ;
char V_381 [ V_175 ] ;
struct V_42 * V_333 [ V_334 + 1 ] ;
struct V_29 * V_30 = NULL ;
struct V_51 * V_443 ;
int V_27 ;
T_5 V_48 = 0 ;
V_27 = F_138 ( V_78 , sizeof( * V_123 ) , V_333 , V_334 , V_339 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_333 [ V_272 ] )
F_131 ( V_381 , V_333 [ V_272 ] , V_175 ) ;
if ( V_333 [ V_340 ] )
V_48 = F_139 ( V_333 [ V_340 ] ) ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_270 > 0 )
V_30 = F_158 ( V_28 , V_123 -> V_270 ) ;
else if ( V_333 [ V_272 ] )
V_30 = F_181 ( V_28 , V_381 ) ;
else
return - V_352 ;
if ( V_30 == NULL )
return - V_392 ;
V_443 = F_203 ( F_95 ( V_30 , V_48 ) , V_15 ) ;
if ( V_443 == NULL )
return - V_16 ;
V_27 = F_113 ( V_443 , V_30 , V_345 , F_61 ( V_52 ) . V_346 ,
V_78 -> V_347 , 0 , 0 , V_48 ) ;
if ( V_27 < 0 ) {
F_141 ( V_27 == - V_55 ) ;
F_204 ( V_443 ) ;
} else
V_27 = F_65 ( V_443 , V_28 , F_61 ( V_52 ) . V_346 ) ;
return V_27 ;
}
static T_9 F_205 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
struct V_29 * V_30 ;
struct V_42 * V_333 [ V_334 + 1 ] ;
T_5 V_48 = 0 ;
T_9 V_444 = 0 ;
int V_336 ;
V_336 = F_137 ( V_78 ) < sizeof( struct V_122 ) ?
sizeof( struct V_338 ) : sizeof( struct V_122 ) ;
if ( F_138 ( V_78 , V_336 , V_333 , V_334 , V_339 ) >= 0 ) {
if ( V_333 [ V_340 ] )
V_48 = F_139 ( V_333 [ V_340 ] ) ;
}
if ( ! V_48 )
return V_445 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_444 = F_206 ( T_9 , V_444 ,
F_95 ( V_30 ,
V_48 ) ) ;
}
return V_444 ;
}
static int F_207 ( struct V_51 * V_52 , struct V_324 * V_325 )
{
int V_329 ;
int V_330 = V_325 -> V_47 ;
if ( V_330 == 0 )
V_330 = 1 ;
for ( V_329 = 1 ; V_329 <= V_9 ; V_329 ++ ) {
int type = V_325 -> V_78 -> V_446 - V_4 ;
if ( V_329 < V_330 || V_329 == V_447 )
continue;
if ( V_10 [ V_329 ] == NULL ||
V_10 [ V_329 ] [ type ] . V_13 == NULL )
continue;
if ( V_329 > V_330 ) {
memset ( & V_325 -> args [ 0 ] , 0 , sizeof( V_325 -> args ) ) ;
V_325 -> V_448 = 0 ;
V_325 -> V_262 = 0 ;
}
if ( V_10 [ V_329 ] [ type ] . V_13 ( V_52 , V_325 ) )
break;
}
V_325 -> V_47 = V_329 ;
return V_52 -> V_348 ;
}
struct V_51 * F_208 ( int type , struct V_29 * V_30 ,
unsigned int V_263 , T_6 V_79 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
struct V_51 * V_52 ;
int V_27 = - V_16 ;
T_4 V_449 ;
V_52 = F_203 ( ( V_449 = F_95 ( V_30 , 0 ) ) , V_79 ) ;
if ( V_52 == NULL )
goto V_383;
V_27 = F_113 ( V_52 , V_30 , type , 0 , 0 , V_263 , 0 , 0 ) ;
if ( V_27 < 0 ) {
F_141 ( V_27 == - V_55 ) ;
F_204 ( V_52 ) ;
goto V_383;
}
return V_52 ;
V_383:
if ( V_27 < 0 )
F_70 ( V_28 , V_450 , V_27 ) ;
return NULL ;
}
void F_209 ( struct V_51 * V_52 , struct V_29 * V_30 , T_6 V_79 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
F_67 ( V_52 , V_28 , 0 , V_450 , NULL , V_79 ) ;
}
void F_210 ( int type , struct V_29 * V_30 , unsigned int V_263 ,
T_6 V_79 )
{
struct V_51 * V_52 ;
if ( V_30 -> V_440 != V_451 )
return;
V_52 = F_208 ( type , V_30 , V_263 , V_79 ) ;
if ( V_52 )
F_209 ( V_52 , V_30 , V_79 ) ;
}
static int F_211 ( struct V_51 * V_52 ,
struct V_29 * V_30 ,
T_10 * V_452 , T_9 V_453 , T_5 V_69 , T_5 V_262 ,
int type , unsigned int V_79 ,
int V_454 , T_9 V_455 )
{
struct V_77 * V_78 ;
struct V_456 * V_457 ;
V_78 = F_115 ( V_52 , V_69 , V_262 , type , sizeof( * V_457 ) , V_454 ) ;
if ( ! V_78 )
return - V_55 ;
V_457 = F_116 ( V_78 ) ;
V_457 -> V_458 = V_459 ;
V_457 -> V_460 = 0 ;
V_457 -> V_461 = 0 ;
V_457 -> V_462 = V_79 ;
V_457 -> V_463 = 0 ;
V_457 -> V_464 = V_30 -> V_271 ;
V_457 -> V_455 = V_455 ;
if ( F_81 ( V_52 , V_465 , V_466 , V_452 ) )
goto V_91;
if ( V_453 )
if ( F_81 ( V_52 , V_467 , sizeof( T_9 ) , & V_453 ) )
goto V_91;
F_127 ( V_52 , V_78 ) ;
return 0 ;
V_91:
F_128 ( V_52 , V_78 ) ;
return - V_55 ;
}
static inline T_4 F_212 ( void )
{
return F_96 ( sizeof( struct V_456 ) ) + F_45 ( V_466 ) ;
}
static void F_213 ( struct V_29 * V_30 , T_10 * V_452 , T_9 V_453 , int type ,
T_9 V_455 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
struct V_51 * V_52 ;
int V_27 = - V_16 ;
V_52 = F_203 ( F_212 () , V_468 ) ;
if ( ! V_52 )
goto V_383;
V_27 = F_211 ( V_52 , V_30 , V_452 , V_453 ,
0 , 0 , type , V_469 , 0 , V_455 ) ;
if ( V_27 < 0 ) {
F_204 ( V_52 ) ;
goto V_383;
}
F_67 ( V_52 , V_28 , 0 , V_470 , NULL , V_468 ) ;
return;
V_383:
F_70 ( V_28 , V_470 , V_27 ) ;
}
int F_214 ( struct V_456 * V_457 ,
struct V_42 * V_333 [] ,
struct V_29 * V_30 ,
const unsigned char * V_452 , T_9 V_453 ,
T_9 V_79 )
{
int V_27 = - V_352 ;
if ( V_457 -> V_455 && ! ( V_457 -> V_455 & V_471 ) ) {
F_215 ( L_6 , V_30 -> V_90 ) ;
return V_27 ;
}
if ( V_453 ) {
F_215 ( L_7 , V_30 -> V_90 ) ;
return V_27 ;
}
if ( F_216 ( V_452 ) || F_217 ( V_452 ) )
V_27 = F_218 ( V_30 , V_452 ) ;
else if ( F_219 ( V_452 ) )
V_27 = F_220 ( V_30 , V_452 ) ;
if ( V_27 == - V_21 && ! ( V_79 & V_432 ) )
V_27 = 0 ;
return V_27 ;
}
static int F_221 ( struct V_42 * V_472 , T_9 * V_473 )
{
T_9 V_453 = 0 ;
if ( V_472 ) {
if ( F_151 ( V_472 ) != sizeof( T_9 ) ) {
F_215 ( L_8 ) ;
return - V_352 ;
}
V_453 = F_222 ( V_472 ) ;
if ( ! V_453 || V_453 >= V_474 ) {
F_215 ( L_9 ,
V_453 ) ;
return - V_352 ;
}
}
* V_473 = V_453 ;
return 0 ;
}
static int F_223 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
struct V_456 * V_457 ;
struct V_42 * V_333 [ V_475 + 1 ] ;
struct V_29 * V_30 ;
T_10 * V_452 ;
T_9 V_453 ;
int V_27 ;
V_27 = F_138 ( V_78 , sizeof( * V_457 ) , V_333 , V_475 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_457 = F_116 ( V_78 ) ;
if ( V_457 -> V_464 == 0 ) {
F_215 ( L_10 ) ;
return - V_352 ;
}
V_30 = F_158 ( V_28 , V_457 -> V_464 ) ;
if ( V_30 == NULL ) {
F_215 ( L_11 ) ;
return - V_392 ;
}
if ( ! V_333 [ V_465 ] || F_151 ( V_333 [ V_465 ] ) != V_466 ) {
F_215 ( L_12 ) ;
return - V_352 ;
}
V_452 = F_109 ( V_333 [ V_465 ] ) ;
V_27 = F_221 ( V_333 [ V_467 ] , & V_453 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_191 ;
if ( ( ! V_457 -> V_462 || V_457 -> V_462 & V_476 ) &&
( V_30 -> V_477 & V_478 ) ) {
struct V_29 * V_479 = F_44 ( V_30 ) ;
const struct V_360 * V_20 = V_479 -> V_173 ;
V_27 = V_20 -> V_480 ( V_457 , V_333 , V_30 , V_452 , V_453 ,
V_78 -> V_431 ) ;
if ( V_27 )
goto V_67;
else
V_457 -> V_462 &= ~ V_476 ;
}
if ( ( V_457 -> V_462 & V_469 ) ) {
if ( V_30 -> V_173 -> V_480 )
V_27 = V_30 -> V_173 -> V_480 ( V_457 , V_333 , V_30 , V_452 ,
V_453 ,
V_78 -> V_431 ) ;
else
V_27 = F_214 ( V_457 , V_333 , V_30 , V_452 , V_453 ,
V_78 -> V_431 ) ;
if ( ! V_27 ) {
F_213 ( V_30 , V_452 , V_453 , V_481 ,
V_457 -> V_455 ) ;
V_457 -> V_462 &= ~ V_469 ;
}
}
V_67:
return V_27 ;
}
int F_224 ( struct V_456 * V_457 ,
struct V_42 * V_333 [] ,
struct V_29 * V_30 ,
const unsigned char * V_452 , T_9 V_453 )
{
int V_27 = - V_352 ;
if ( ! ( V_457 -> V_455 & V_471 ) ) {
F_215 ( L_6 , V_30 -> V_90 ) ;
return V_27 ;
}
if ( F_216 ( V_452 ) || F_217 ( V_452 ) )
V_27 = F_225 ( V_30 , V_452 ) ;
else if ( F_219 ( V_452 ) )
V_27 = F_226 ( V_30 , V_452 ) ;
return V_27 ;
}
static int F_227 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
struct V_456 * V_457 ;
struct V_42 * V_333 [ V_475 + 1 ] ;
struct V_29 * V_30 ;
int V_27 = - V_352 ;
T_11 * V_452 ;
T_9 V_453 ;
if ( ! F_228 ( V_52 , V_385 ) )
return - V_386 ;
V_27 = F_138 ( V_78 , sizeof( * V_457 ) , V_333 , V_475 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_457 = F_116 ( V_78 ) ;
if ( V_457 -> V_464 == 0 ) {
F_215 ( L_13 ) ;
return - V_352 ;
}
V_30 = F_158 ( V_28 , V_457 -> V_464 ) ;
if ( V_30 == NULL ) {
F_215 ( L_14 ) ;
return - V_392 ;
}
if ( ! V_333 [ V_465 ] || F_151 ( V_333 [ V_465 ] ) != V_466 ) {
F_215 ( L_15 ) ;
return - V_352 ;
}
V_452 = F_109 ( V_333 [ V_465 ] ) ;
V_27 = F_221 ( V_333 [ V_467 ] , & V_453 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_191 ;
if ( ( ! V_457 -> V_462 || V_457 -> V_462 & V_476 ) &&
( V_30 -> V_477 & V_478 ) ) {
struct V_29 * V_479 = F_44 ( V_30 ) ;
const struct V_360 * V_20 = V_479 -> V_173 ;
if ( V_20 -> V_482 )
V_27 = V_20 -> V_482 ( V_457 , V_333 , V_30 , V_452 , V_453 ) ;
if ( V_27 )
goto V_67;
else
V_457 -> V_462 &= ~ V_476 ;
}
if ( V_457 -> V_462 & V_469 ) {
if ( V_30 -> V_173 -> V_482 )
V_27 = V_30 -> V_173 -> V_482 ( V_457 , V_333 , V_30 , V_452 ,
V_453 ) ;
else
V_27 = F_224 ( V_457 , V_333 , V_30 , V_452 , V_453 ) ;
if ( ! V_27 ) {
F_213 ( V_30 , V_452 , V_453 , V_483 ,
V_457 -> V_455 ) ;
V_457 -> V_462 &= ~ V_469 ;
}
}
V_67:
return V_27 ;
}
static int F_229 ( struct V_51 * V_52 ,
struct V_324 * V_325 ,
struct V_29 * V_30 ,
int * V_329 ,
struct V_484 * V_25 )
{
struct V_485 * V_486 ;
int V_27 ;
T_5 V_346 , V_262 ;
V_346 = F_61 ( V_325 -> V_52 ) . V_346 ;
V_262 = V_325 -> V_78 -> V_347 ;
F_26 (ha, &list->list, list) {
if ( * V_329 < V_325 -> args [ 0 ] )
goto V_487;
V_27 = F_211 ( V_52 , V_30 , V_486 -> V_452 , 0 ,
V_346 , V_262 ,
V_481 , V_469 ,
V_335 , V_471 ) ;
if ( V_27 < 0 )
return V_27 ;
V_487:
* V_329 += 1 ;
}
return 0 ;
}
int F_230 ( struct V_51 * V_52 ,
struct V_324 * V_325 ,
struct V_29 * V_30 ,
struct V_29 * V_488 ,
int V_329 )
{
int V_27 ;
F_231 ( V_30 ) ;
V_27 = F_229 ( V_52 , V_325 , V_30 , & V_329 , & V_30 -> V_489 ) ;
if ( V_27 )
goto V_67;
F_229 ( V_52 , V_325 , V_30 , & V_329 , & V_30 -> V_490 ) ;
V_67:
F_232 ( V_30 ) ;
V_325 -> args [ 1 ] = V_27 ;
return V_329 ;
}
static int F_233 ( struct V_51 * V_52 , struct V_324 * V_325 )
{
struct V_29 * V_30 ;
struct V_42 * V_333 [ V_334 + 1 ] ;
struct V_29 * V_479 = NULL ;
const struct V_360 * V_20 = NULL ;
const struct V_360 * V_491 = NULL ;
struct V_122 * V_123 = F_116 ( V_325 -> V_78 ) ;
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
int V_492 = 0 ;
int V_493 = 0 ;
int V_329 = 0 ;
if ( F_138 ( V_325 -> V_78 , sizeof( struct V_122 ) , V_333 , V_334 ,
V_339 ) == 0 ) {
if ( V_333 [ V_293 ] )
V_493 = F_139 ( V_333 [ V_293 ] ) ;
}
V_492 = V_123 -> V_270 ;
if ( V_493 ) {
V_479 = F_158 ( V_28 , V_493 ) ;
if ( ! V_479 )
return - V_392 ;
V_20 = V_479 -> V_173 ;
}
V_325 -> args [ 1 ] = 0 ;
F_32 (net, dev) {
if ( V_492 && ( V_30 -> V_271 != V_492 ) )
continue;
if ( ! V_493 ) {
if ( V_30 -> V_477 & V_478 ) {
V_479 = F_44 ( V_30 ) ;
V_491 = V_479 -> V_173 ;
}
} else {
if ( V_30 != V_479 &&
! ( V_30 -> V_477 & V_478 ) )
continue;
if ( V_479 != F_44 ( V_30 ) &&
! ( V_30 -> V_477 & V_494 ) )
continue;
V_491 = V_20 ;
}
if ( V_30 -> V_477 & V_478 ) {
if ( V_491 && V_491 -> V_495 )
V_329 = V_491 -> V_495 ( V_52 , V_325 , V_479 , V_30 ,
V_329 ) ;
}
if ( V_325 -> args [ 1 ] == - V_55 )
break;
if ( V_30 -> V_173 -> V_495 )
V_329 = V_30 -> V_173 -> V_495 ( V_52 , V_325 , V_30 , NULL ,
V_329 ) ;
else
V_329 = F_230 ( V_52 , V_325 , V_30 , NULL , V_329 ) ;
if ( V_325 -> args [ 1 ] == - V_55 )
break;
V_491 = NULL ;
}
V_325 -> args [ 0 ] = V_329 ;
return V_52 -> V_348 ;
}
static int F_234 ( struct V_51 * V_52 , T_5 V_79 , T_5 V_496 ,
unsigned int V_497 , unsigned int V_498 )
{
if ( V_496 & V_498 )
return F_118 ( V_52 , V_497 , ! ! ( V_79 & V_498 ) ) ;
return 0 ;
}
int F_235 ( struct V_51 * V_52 , T_5 V_69 , T_5 V_262 ,
struct V_29 * V_30 , T_9 V_499 ,
T_5 V_79 , T_5 V_496 , int V_454 ,
T_5 V_500 ,
int (* F_236)( struct V_51 * V_52 ,
struct V_29 * V_30 ,
T_5 V_500 ) )
{
struct V_77 * V_78 ;
struct V_122 * V_123 ;
struct V_42 * V_501 ;
struct V_42 * V_502 ;
T_10 V_114 = F_119 ( V_30 ) ? V_30 -> V_114 : V_276 ;
struct V_29 * V_479 = F_44 ( V_30 ) ;
int V_27 = 0 ;
V_78 = F_115 ( V_52 , V_69 , V_262 , V_345 , sizeof( * V_123 ) , V_454 ) ;
if ( V_78 == NULL )
return - V_55 ;
V_123 = F_116 ( V_78 ) ;
V_123 -> V_266 = V_459 ;
V_123 -> V_268 = 0 ;
V_123 -> V_269 = V_30 -> type ;
V_123 -> V_270 = V_30 -> V_271 ;
V_123 -> V_124 = F_117 ( V_30 ) ;
V_123 -> V_125 = 0 ;
if ( F_54 ( V_52 , V_272 , V_30 -> V_90 ) ||
F_75 ( V_52 , V_279 , V_30 -> V_280 ) ||
F_118 ( V_52 , V_275 , V_114 ) ||
( V_479 &&
F_75 ( V_52 , V_293 , V_479 -> V_271 ) ) ||
( V_30 -> V_303 &&
F_81 ( V_52 , V_304 , V_30 -> V_303 , V_30 -> V_305 ) ) ||
( V_30 -> V_271 != F_121 ( V_30 ) &&
F_75 ( V_52 , V_292 , F_121 ( V_30 ) ) ) )
goto V_91;
V_501 = F_55 ( V_52 , V_312 ) ;
if ( ! V_501 )
goto V_91;
if ( F_237 ( V_52 , V_503 , V_504 ) ) {
F_57 ( V_52 , V_501 ) ;
goto V_91;
}
if ( V_499 != V_505 ) {
if ( F_237 ( V_52 , V_506 , V_499 ) ) {
F_57 ( V_52 , V_501 ) ;
goto V_91;
}
}
if ( F_236 ) {
V_27 = F_236 ( V_52 , V_30 , V_500 ) ;
if ( V_27 ) {
F_57 ( V_52 , V_501 ) ;
goto V_91;
}
}
F_56 ( V_52 , V_501 ) ;
V_502 = F_55 ( V_52 , V_437 | V_507 ) ;
if ( ! V_502 )
goto V_91;
if ( F_234 ( V_52 , V_79 , V_496 ,
V_508 , V_509 ) ||
F_234 ( V_52 , V_79 , V_496 ,
V_510 , V_511 ) ||
F_234 ( V_52 , V_79 , V_496 ,
V_512 ,
V_513 ) ||
F_234 ( V_52 , V_79 , V_496 ,
V_514 , V_515 ) ||
F_234 ( V_52 , V_79 , V_496 ,
V_516 , V_517 ) ||
F_234 ( V_52 , V_79 , V_496 ,
V_518 , V_519 ) ||
F_234 ( V_52 , V_79 , V_496 ,
V_520 , V_521 ) ||
F_234 ( V_52 , V_79 , V_496 ,
V_522 , V_523 ) ) {
F_57 ( V_52 , V_502 ) ;
goto V_91;
}
F_56 ( V_52 , V_502 ) ;
F_127 ( V_52 , V_78 ) ;
return 0 ;
V_91:
F_128 ( V_52 , V_78 ) ;
return V_27 ? V_27 : - V_55 ;
}
static int F_238 ( struct V_51 * V_52 , struct V_324 * V_325 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
struct V_29 * V_30 ;
int V_329 = 0 ;
T_5 V_346 = F_61 ( V_325 -> V_52 ) . V_346 ;
T_5 V_262 = V_325 -> V_78 -> V_347 ;
T_5 V_500 = 0 ;
int V_27 ;
if ( F_137 ( V_325 -> V_78 ) > sizeof( struct V_122 ) ) {
struct V_42 * V_524 ;
V_524 = F_239 ( V_325 -> V_78 , sizeof( struct V_122 ) ,
V_340 ) ;
if ( V_524 ) {
if ( F_151 ( V_524 ) < sizeof( V_500 ) )
return - V_352 ;
V_500 = F_139 ( V_524 ) ;
}
}
F_240 () ;
F_241 (net, dev) {
const struct V_360 * V_20 = V_30 -> V_173 ;
struct V_29 * V_479 = F_44 ( V_30 ) ;
if ( V_479 && V_479 -> V_173 -> V_525 ) {
if ( V_329 >= V_325 -> args [ 0 ] ) {
V_27 = V_479 -> V_173 -> V_525 (
V_52 , V_346 , V_262 , V_30 ,
V_500 , V_335 ) ;
if ( V_27 < 0 && V_27 != - V_191 )
break;
}
V_329 ++ ;
}
if ( V_20 -> V_525 ) {
if ( V_329 >= V_325 -> args [ 0 ] ) {
V_27 = V_20 -> V_525 ( V_52 , V_346 ,
V_262 , V_30 ,
V_500 ,
V_335 ) ;
if ( V_27 < 0 && V_27 != - V_191 )
break;
}
V_329 ++ ;
}
}
F_242 () ;
V_325 -> args [ 0 ] = V_329 ;
return V_52 -> V_348 ;
}
static inline T_4 F_243 ( void )
{
return F_96 ( sizeof( struct V_122 ) )
+ F_45 ( V_175 )
+ F_45 ( V_178 )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_10 ) )
+ F_45 ( sizeof( struct V_42 ) )
+ F_45 ( sizeof( T_9 ) )
+ F_45 ( sizeof( T_9 ) ) ;
}
static int F_244 ( struct V_29 * V_30 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
struct V_51 * V_52 ;
int V_27 = - V_191 ;
if ( ! V_30 -> V_173 -> V_525 )
return 0 ;
V_52 = F_203 ( F_243 () , V_468 ) ;
if ( ! V_52 ) {
V_27 = - V_397 ;
goto V_383;
}
V_27 = V_30 -> V_173 -> V_525 ( V_52 , 0 , 0 , V_30 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_383;
if ( ! V_52 -> V_348 )
goto V_383;
F_67 ( V_52 , V_28 , 0 , V_450 , NULL , V_468 ) ;
return 0 ;
V_383:
F_141 ( V_27 == - V_55 ) ;
F_204 ( V_52 ) ;
if ( V_27 )
F_70 ( V_28 , V_450 , V_27 ) ;
return V_27 ;
}
static int F_245 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
struct V_122 * V_123 ;
struct V_29 * V_30 ;
struct V_42 * V_526 , * V_196 = NULL ;
int V_353 , V_27 = - V_191 ;
T_9 V_79 = 0 ;
bool V_527 = false ;
if ( F_137 ( V_78 ) < sizeof( * V_123 ) )
return - V_352 ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_266 != V_459 )
return - V_528 ;
V_30 = F_158 ( V_28 , V_123 -> V_270 ) ;
if ( ! V_30 ) {
F_215 ( L_16 ) ;
return - V_392 ;
}
V_526 = F_239 ( V_78 , sizeof( struct V_122 ) , V_312 ) ;
if ( V_526 ) {
F_152 (attr, br_spec, rem) {
if ( F_153 ( V_196 ) == V_503 ) {
if ( F_151 ( V_196 ) < sizeof( V_79 ) )
return - V_352 ;
V_527 = true ;
V_79 = F_222 ( V_196 ) ;
break;
}
}
}
if ( ! V_79 || ( V_79 & V_529 ) ) {
struct V_29 * V_479 = F_44 ( V_30 ) ;
if ( ! V_479 || ! V_479 -> V_173 -> V_530 ) {
V_27 = - V_191 ;
goto V_67;
}
V_27 = V_479 -> V_173 -> V_530 ( V_30 , V_78 , V_79 ) ;
if ( V_27 )
goto V_67;
V_79 &= ~ V_529 ;
}
if ( ( V_79 & V_504 ) ) {
if ( ! V_30 -> V_173 -> V_530 )
V_27 = - V_191 ;
else
V_27 = V_30 -> V_173 -> V_530 ( V_30 , V_78 ,
V_79 ) ;
if ( ! V_27 ) {
V_79 &= ~ V_504 ;
V_27 = F_244 ( V_30 ) ;
}
}
if ( V_527 )
memcpy ( F_109 ( V_196 ) , & V_79 , sizeof( V_79 ) ) ;
V_67:
return V_27 ;
}
static int F_246 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
struct V_122 * V_123 ;
struct V_29 * V_30 ;
struct V_42 * V_526 , * V_196 = NULL ;
int V_353 , V_27 = - V_191 ;
T_9 V_79 = 0 ;
bool V_527 = false ;
if ( F_137 ( V_78 ) < sizeof( * V_123 ) )
return - V_352 ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_266 != V_459 )
return - V_528 ;
V_30 = F_158 ( V_28 , V_123 -> V_270 ) ;
if ( ! V_30 ) {
F_215 ( L_16 ) ;
return - V_392 ;
}
V_526 = F_239 ( V_78 , sizeof( struct V_122 ) , V_312 ) ;
if ( V_526 ) {
F_152 (attr, br_spec, rem) {
if ( F_153 ( V_196 ) == V_503 ) {
if ( F_151 ( V_196 ) < sizeof( V_79 ) )
return - V_352 ;
V_527 = true ;
V_79 = F_222 ( V_196 ) ;
break;
}
}
}
if ( ! V_79 || ( V_79 & V_529 ) ) {
struct V_29 * V_479 = F_44 ( V_30 ) ;
if ( ! V_479 || ! V_479 -> V_173 -> V_531 ) {
V_27 = - V_191 ;
goto V_67;
}
V_27 = V_479 -> V_173 -> V_531 ( V_30 , V_78 , V_79 ) ;
if ( V_27 )
goto V_67;
V_79 &= ~ V_529 ;
}
if ( ( V_79 & V_504 ) ) {
if ( ! V_30 -> V_173 -> V_531 )
V_27 = - V_191 ;
else
V_27 = V_30 -> V_173 -> V_531 ( V_30 , V_78 ,
V_79 ) ;
if ( ! V_27 ) {
V_79 &= ~ V_504 ;
V_27 = F_244 ( V_30 ) ;
}
}
if ( V_527 )
memcpy ( F_109 ( V_196 ) , & V_79 , sizeof( V_79 ) ) ;
V_67:
return V_27 ;
}
static int F_247 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_136 ( V_52 -> V_326 ) ;
T_1 V_11 ;
int V_19 ;
int V_47 ;
int type ;
int V_27 ;
type = V_78 -> V_446 ;
if ( type > V_532 )
return - V_191 ;
type -= V_4 ;
if ( F_137 ( V_78 ) < sizeof( struct V_338 ) )
return 0 ;
V_47 = ( (struct V_338 * ) F_116 ( V_78 ) ) -> V_533 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_248 ( V_52 , V_385 ) )
return - V_386 ;
if ( V_19 == 2 && V_78 -> V_431 & V_534 ) {
struct V_72 * V_73 ;
T_2 V_13 ;
T_3 V_14 ;
T_9 V_535 = 0 ;
V_13 = F_16 ( V_47 , type ) ;
if ( V_13 == NULL )
return - V_191 ;
V_14 = F_17 ( V_47 , type ) ;
if ( V_14 )
V_535 = V_14 ( V_52 , V_78 ) ;
F_3 () ;
V_73 = V_28 -> V_73 ;
{
struct V_536 V_537 = {
. V_538 = V_13 ,
. V_535 = V_535 ,
} ;
V_27 = F_249 ( V_73 , V_52 , V_78 , & V_537 ) ;
}
F_1 () ;
return V_27 ;
}
V_11 = F_15 ( V_47 , type ) ;
if ( V_11 == NULL )
return - V_191 ;
return V_11 ( V_52 , V_78 ) ;
}
static void F_250 ( struct V_51 * V_52 )
{
F_1 () ;
F_251 ( V_52 , & F_247 ) ;
F_5 () ;
}
static int F_252 ( struct V_539 * V_540 , unsigned long V_541 , void * V_542 )
{
struct V_29 * V_30 = F_253 ( V_542 ) ;
switch ( V_541 ) {
case V_543 :
case V_544 :
case V_545 :
case V_546 :
case V_547 :
case V_548 :
case V_549 :
case V_550 :
case V_551 :
case V_552 :
case V_553 :
case V_554 :
case V_555 :
break;
default:
F_210 ( V_345 , V_30 , 0 , V_15 ) ;
break;
}
return V_556 ;
}
static int T_12 F_254 ( struct V_28 * V_28 )
{
struct V_72 * V_326 ;
struct V_557 V_558 = {
. V_559 = V_560 ,
. V_561 = F_250 ,
. V_562 = & V_1 ,
. V_79 = V_563 ,
} ;
V_326 = F_255 ( V_28 , V_564 , & V_558 ) ;
if ( ! V_326 )
return - V_397 ;
V_28 -> V_73 = V_326 ;
return 0 ;
}
static void T_13 F_256 ( struct V_28 * V_28 )
{
F_257 ( V_28 -> V_73 ) ;
V_28 -> V_73 = NULL ;
}
void T_14 F_258 ( void )
{
if ( F_259 ( & V_565 ) )
F_21 ( L_17 ) ;
F_260 ( & V_566 ) ;
F_20 ( V_12 , V_567 , F_202 ,
F_135 , F_205 ) ;
F_20 ( V_12 , V_568 , F_180 , NULL , NULL ) ;
F_20 ( V_12 , V_345 , F_194 , NULL , NULL ) ;
F_20 ( V_12 , V_569 , F_185 , NULL , NULL ) ;
F_20 ( V_12 , V_570 , NULL , F_207 , NULL ) ;
F_20 ( V_12 , V_571 , NULL , F_207 , NULL ) ;
F_20 ( V_572 , V_481 , F_223 , NULL , NULL ) ;
F_20 ( V_572 , V_483 , F_227 , NULL , NULL ) ;
F_20 ( V_572 , V_573 , NULL , F_233 , NULL ) ;
F_20 ( V_572 , V_567 , NULL , F_238 , NULL ) ;
F_20 ( V_572 , V_569 , F_246 , NULL , NULL ) ;
F_20 ( V_572 , V_568 , F_245 , NULL , NULL ) ;
}
