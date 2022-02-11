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
int F_11 ( void )
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
if ( ! V_20 -> V_22 )
V_20 -> V_22 = V_23 ;
F_28 ( & V_20 -> V_24 , & V_25 ) ;
return 0 ;
}
int F_29 ( struct V_18 * V_20 )
{
int V_26 ;
F_1 () ;
V_26 = F_27 ( V_20 ) ;
F_5 () ;
return V_26 ;
}
static void F_30 ( struct V_27 * V_27 , struct V_18 * V_20 )
{
struct V_28 * V_29 ;
F_31 ( V_30 ) ;
F_32 (net, dev) {
if ( V_29 -> V_18 == V_20 )
V_20 -> V_22 ( V_29 , & V_30 ) ;
}
F_33 ( & V_30 ) ;
}
void F_34 ( struct V_18 * V_20 )
{
struct V_27 * V_27 ;
F_35 (net) {
F_30 ( V_27 , V_20 ) ;
}
F_36 ( & V_20 -> V_24 ) ;
}
static void F_37 ( void )
{
struct V_27 * V_27 ;
bool V_31 ;
F_38 ( V_32 ) ;
for (; ; ) {
F_39 ( & V_33 , & V_32 ,
V_34 ) ;
V_31 = false ;
F_1 () ;
F_35 (net) {
if ( V_27 -> V_35 > 0 ) {
V_31 = true ;
break;
}
}
if ( ! V_31 )
break;
F_3 () ;
F_40 () ;
}
F_41 ( & V_33 , & V_32 ) ;
}
void F_42 ( struct V_18 * V_20 )
{
F_2 ( & V_36 ) ;
F_37 () ;
F_34 ( V_20 ) ;
F_5 () ;
F_4 ( & V_36 ) ;
}
static T_4 F_43 ( const struct V_28 * V_29 )
{
struct V_28 * V_37 ;
const struct V_18 * V_20 ;
V_37 = F_44 ( (struct V_28 * ) V_29 ) ;
if ( ! V_37 )
return 0 ;
V_20 = V_37 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_38 )
return 0 ;
return F_45 ( sizeof( struct V_39 ) ) +
V_20 -> V_38 ( V_37 , V_29 ) ;
}
static T_4 F_46 ( const struct V_28 * V_29 )
{
const struct V_18 * V_20 = V_29 -> V_18 ;
T_4 V_40 ;
if ( ! V_20 )
return 0 ;
V_40 = F_45 ( sizeof( struct V_39 ) ) +
F_45 ( strlen ( V_20 -> V_19 ) + 1 ) ;
if ( V_20 -> V_41 )
V_40 += F_45 ( sizeof( struct V_39 ) ) +
V_20 -> V_41 ( V_29 ) ;
if ( V_20 -> V_42 )
V_40 += F_45 ( V_20 -> V_42 ( V_29 ) ) ;
V_40 += F_43 ( V_29 ) ;
return V_40 ;
}
static const struct V_43 * F_47 ( const int V_44 )
{
const struct V_43 * V_20 ;
F_26 (ops, &rtnl_af_ops, list) {
if ( V_20 -> V_44 == V_44 )
return V_20 ;
}
return NULL ;
}
void F_48 ( struct V_43 * V_20 )
{
F_1 () ;
F_28 ( & V_20 -> V_24 , & V_43 ) ;
F_5 () ;
}
void F_49 ( struct V_43 * V_20 )
{
F_36 ( & V_20 -> V_24 ) ;
}
void F_50 ( struct V_43 * V_20 )
{
F_1 () ;
F_49 ( V_20 ) ;
F_5 () ;
}
static T_4 F_51 ( const struct V_28 * V_29 )
{
struct V_43 * V_45 ;
T_4 V_40 ;
V_40 = F_45 ( sizeof( struct V_39 ) ) ;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_45 -> V_46 ) {
V_40 += F_45 ( sizeof( struct V_39 ) ) +
V_45 -> V_46 ( V_29 ) ;
}
}
return V_40 ;
}
static bool F_52 ( const struct V_28 * V_29 )
{
struct V_28 * V_37 ;
V_37 = F_44 ( (struct V_28 * ) V_29 ) ;
if ( V_37 && V_37 -> V_18 )
return true ;
return false ;
}
static int F_53 ( struct V_47 * V_48 ,
const struct V_28 * V_29 )
{
struct V_28 * V_37 ;
const struct V_18 * V_20 ;
struct V_39 * V_49 ;
int V_26 ;
V_37 = F_44 ( (struct V_28 * ) V_29 ) ;
if ( ! V_37 )
return 0 ;
V_20 = V_37 -> V_18 ;
if ( ! V_20 )
return 0 ;
if ( F_54 ( V_48 , V_50 , V_20 -> V_19 ) < 0 )
return - V_51 ;
if ( V_20 -> V_52 ) {
V_49 = F_55 ( V_48 , V_53 ) ;
if ( ! V_49 )
return - V_51 ;
V_26 = V_20 -> V_52 ( V_48 , V_37 , V_29 ) ;
if ( V_26 < 0 )
goto V_54;
F_56 ( V_48 , V_49 ) ;
}
return 0 ;
V_54:
F_57 ( V_48 , V_49 ) ;
return V_26 ;
}
static int F_58 ( struct V_47 * V_48 ,
const struct V_28 * V_29 )
{
const struct V_18 * V_20 = V_29 -> V_18 ;
struct V_39 * V_55 ;
int V_26 ;
if ( ! V_20 )
return 0 ;
if ( F_54 ( V_48 , V_56 , V_20 -> V_19 ) < 0 )
return - V_51 ;
if ( V_20 -> V_57 ) {
V_26 = V_20 -> V_57 ( V_48 , V_29 ) ;
if ( V_26 < 0 )
return V_26 ;
}
if ( V_20 -> V_58 ) {
V_55 = F_55 ( V_48 , V_59 ) ;
if ( V_55 == NULL )
return - V_51 ;
V_26 = V_20 -> V_58 ( V_48 , V_29 ) ;
if ( V_26 < 0 )
goto V_60;
F_56 ( V_48 , V_55 ) ;
}
return 0 ;
V_60:
F_57 ( V_48 , V_55 ) ;
return V_26 ;
}
static int F_59 ( struct V_47 * V_48 , const struct V_28 * V_29 )
{
struct V_39 * V_61 ;
int V_26 = - V_51 ;
V_61 = F_55 ( V_48 , V_62 ) ;
if ( V_61 == NULL )
goto V_63;
V_26 = F_58 ( V_48 , V_29 ) ;
if ( V_26 < 0 )
goto V_64;
V_26 = F_53 ( V_48 , V_29 ) ;
if ( V_26 < 0 )
goto V_64;
F_56 ( V_48 , V_61 ) ;
return 0 ;
V_64:
F_57 ( V_48 , V_61 ) ;
V_63:
return V_26 ;
}
int F_60 ( struct V_47 * V_48 , struct V_27 * V_27 , T_5 V_65 , unsigned int V_66 , int V_67 )
{
struct V_68 * V_69 = V_27 -> V_69 ;
int V_26 = 0 ;
F_61 ( V_48 ) . V_70 = V_66 ;
if ( V_67 )
F_62 ( & V_48 -> V_71 ) ;
F_63 ( V_69 , V_48 , V_65 , V_66 , V_15 ) ;
if ( V_67 )
V_26 = F_64 ( V_69 , V_48 , V_65 , V_72 ) ;
return V_26 ;
}
int F_65 ( struct V_47 * V_48 , struct V_27 * V_27 , T_5 V_65 )
{
struct V_68 * V_69 = V_27 -> V_69 ;
return F_66 ( V_69 , V_48 , V_65 ) ;
}
void F_67 ( struct V_47 * V_48 , struct V_27 * V_27 , T_5 V_65 , T_5 V_66 ,
struct V_73 * V_74 , T_6 V_75 )
{
struct V_68 * V_69 = V_27 -> V_69 ;
int V_76 = 0 ;
if ( V_74 )
V_76 = F_68 ( V_74 ) ;
F_69 ( V_69 , V_48 , V_65 , V_66 , V_76 , V_75 ) ;
}
void F_70 ( struct V_27 * V_27 , T_5 V_66 , int error )
{
struct V_68 * V_69 = V_27 -> V_69 ;
F_71 ( V_69 , 0 , V_66 , error ) ;
}
int F_72 ( struct V_47 * V_48 , T_5 * V_77 )
{
struct V_39 * V_78 ;
int V_79 , V_80 = 0 ;
V_78 = F_55 ( V_48 , V_81 ) ;
if ( V_78 == NULL )
return - V_16 ;
for ( V_79 = 0 ; V_79 < V_82 ; V_79 ++ ) {
if ( V_77 [ V_79 ] ) {
V_80 ++ ;
if ( F_73 ( V_48 , V_79 + 1 , V_77 [ V_79 ] ) )
goto V_83;
}
}
if ( ! V_80 ) {
F_57 ( V_48 , V_78 ) ;
return 0 ;
}
return F_56 ( V_48 , V_78 ) ;
V_83:
F_57 ( V_48 , V_78 ) ;
return - V_51 ;
}
int F_74 ( struct V_47 * V_48 , struct V_84 * V_85 , T_5 V_86 ,
long V_87 , T_5 error )
{
struct V_88 V_89 = {
. V_90 = F_75 ( V_91 - V_85 -> V_92 ) ,
. V_93 = V_85 -> V_94 ,
. V_95 = F_76 ( & ( V_85 -> V_96 ) ) ,
. V_97 = error ,
. V_98 = V_86 ,
} ;
if ( V_87 ) {
unsigned long clock ;
clock = F_77 ( abs ( V_87 ) ) ;
clock = F_78 (unsigned long, clock, INT_MAX) ;
V_89 . V_99 = ( V_87 > 0 ) ? clock : - clock ;
}
return F_79 ( V_48 , V_100 , sizeof( V_89 ) , & V_89 ) ;
}
static void F_80 ( struct V_28 * V_29 , unsigned char V_101 )
{
unsigned char V_102 = V_29 -> V_102 ;
switch ( V_101 ) {
case V_103 :
if ( ( V_102 == V_104 ||
V_102 == V_105 ) &&
! F_81 ( V_29 ) )
V_102 = V_103 ;
break;
case V_104 :
if ( V_102 == V_103 ||
V_102 == V_105 )
V_102 = V_104 ;
break;
}
if ( V_29 -> V_102 != V_102 ) {
F_82 ( & V_106 ) ;
V_29 -> V_102 = V_102 ;
F_83 ( & V_106 ) ;
F_84 ( V_29 ) ;
}
}
static unsigned int F_85 ( const struct V_28 * V_29 )
{
return ( V_29 -> V_75 & ~ ( V_107 | V_108 ) ) |
( V_29 -> V_109 & ( V_107 | V_108 ) ) ;
}
static unsigned int F_86 ( const struct V_28 * V_29 ,
const struct V_110 * V_111 )
{
unsigned int V_75 = V_111 -> V_112 ;
if ( V_111 -> V_113 )
V_75 = ( V_75 & V_111 -> V_113 ) |
( F_85 ( V_29 ) & ~ V_111 -> V_113 ) ;
return V_75 ;
}
static void F_87 ( struct V_114 * V_115 ,
const struct V_116 * V_117 )
{
V_115 -> V_118 = V_117 -> V_118 ;
V_115 -> V_119 = V_117 -> V_119 ;
V_115 -> V_120 = V_117 -> V_120 ;
V_115 -> V_121 = V_117 -> V_121 ;
V_115 -> V_122 = V_117 -> V_122 ;
V_115 -> V_123 = V_117 -> V_123 ;
V_115 -> V_124 = V_117 -> V_124 ;
V_115 -> V_125 = V_117 -> V_125 ;
V_115 -> V_126 = V_117 -> V_126 ;
V_115 -> V_127 = V_117 -> V_127 ;
V_115 -> V_128 = V_117 -> V_128 ;
V_115 -> V_129 = V_117 -> V_129 ;
V_115 -> V_130 = V_117 -> V_130 ;
V_115 -> V_131 = V_117 -> V_131 ;
V_115 -> V_132 = V_117 -> V_132 ;
V_115 -> V_133 = V_117 -> V_133 ;
V_115 -> V_134 = V_117 -> V_134 ;
V_115 -> V_135 = V_117 -> V_135 ;
V_115 -> V_136 = V_117 -> V_136 ;
V_115 -> V_137 = V_117 -> V_137 ;
V_115 -> V_138 = V_117 -> V_138 ;
V_115 -> V_139 = V_117 -> V_139 ;
V_115 -> V_140 = V_117 -> V_140 ;
}
static void F_88 ( void * V_141 , const struct V_116 * V_117 )
{
memcpy ( V_141 , V_117 , sizeof( * V_117 ) ) ;
}
static inline int F_89 ( const struct V_28 * V_29 ,
T_5 V_142 )
{
if ( V_29 -> V_29 . V_143 && F_90 ( V_29 -> V_29 . V_143 ) &&
( V_142 & V_144 ) ) {
int V_145 = F_91 ( V_29 -> V_29 . V_143 ) ;
T_4 V_40 = F_45 ( sizeof( struct V_39 ) ) ;
V_40 += F_45 ( V_145 * sizeof( struct V_39 ) ) ;
V_40 += V_145 *
( F_45 ( sizeof( struct V_146 ) ) +
F_45 ( sizeof( struct V_147 ) ) +
F_45 ( sizeof( struct V_148 ) ) +
F_45 ( sizeof( struct V_149 ) ) ) ;
return V_40 ;
} else
return 0 ;
}
static T_4 F_92 ( const struct V_28 * V_29 ,
T_5 V_142 )
{
T_4 V_150 = F_45 ( 4 )
+ F_45 ( V_151 )
+ F_45 ( sizeof( struct V_152 ) )
+ F_45 ( V_153 )
+ F_45 ( V_153 )
+ F_45 ( 1 )
+ F_45 ( 2 ) ;
T_4 V_154 = F_45 ( sizeof( struct V_39 ) ) ;
T_4 V_155 = F_45 ( sizeof( struct V_39 ) )
+ V_150 ;
T_4 V_156 = F_45 ( sizeof( struct V_39 ) )
+ V_150 ;
if ( ! V_29 -> V_157 -> V_158 || ! V_29 -> V_29 . V_143 ||
! ( V_142 & V_144 ) )
return 0 ;
if ( F_91 ( V_29 -> V_29 . V_143 ) )
return V_156 + V_154 +
V_155 * F_91 ( V_29 -> V_29 . V_143 ) ;
else
return V_156 ;
}
static T_7 T_4 F_93 ( const struct V_28 * V_29 ,
T_5 V_142 )
{
return F_94 ( sizeof( struct V_110 ) )
+ F_45 ( V_159 )
+ F_45 ( V_160 )
+ F_45 ( V_159 )
+ F_45 ( sizeof( struct V_161 ) )
+ F_45 ( sizeof( struct V_114 ) )
+ F_45 ( sizeof( struct V_116 ) )
+ F_45 ( V_162 )
+ F_45 ( V_162 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 1 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 4 )
+ F_45 ( 1 )
+ F_45 ( 1 )
+ F_45 ( 4 )
+ F_45 ( V_142
& V_144 ? 4 : 0 )
+ F_89 ( V_29 , V_142 )
+ F_92 ( V_29 , V_142 )
+ F_46 ( V_29 )
+ F_51 ( V_29 )
+ F_45 ( V_163 ) ;
}
static int F_95 ( struct V_47 * V_48 , struct V_28 * V_29 )
{
struct V_39 * V_164 ;
struct V_39 * V_165 ;
int V_166 ;
int V_26 ;
V_164 = F_55 ( V_48 , V_167 ) ;
if ( ! V_164 )
return - V_51 ;
for ( V_166 = 0 ; V_166 < F_91 ( V_29 -> V_29 . V_143 ) ; V_166 ++ ) {
V_165 = F_55 ( V_48 , V_168 ) ;
if ( ! V_165 )
goto V_83;
if ( F_73 ( V_48 , V_169 , V_166 ) )
goto V_83;
V_26 = V_29 -> V_157 -> V_158 ( V_29 , V_166 , V_48 ) ;
if ( V_26 == - V_51 )
goto V_83;
if ( V_26 ) {
F_57 ( V_48 , V_165 ) ;
continue;
}
F_56 ( V_48 , V_165 ) ;
}
F_56 ( V_48 , V_164 ) ;
return 0 ;
V_83:
F_57 ( V_48 , V_164 ) ;
return - V_51 ;
}
static int F_96 ( struct V_47 * V_48 , struct V_28 * V_29 )
{
struct V_39 * V_170 ;
int V_26 ;
V_170 = F_55 ( V_48 , V_171 ) ;
if ( ! V_170 )
return - V_51 ;
V_26 = V_29 -> V_157 -> V_158 ( V_29 , V_172 , V_48 ) ;
if ( V_26 ) {
F_57 ( V_48 , V_170 ) ;
return ( V_26 == - V_51 ) ? V_26 : 0 ;
}
F_56 ( V_48 , V_170 ) ;
return 0 ;
}
static int F_97 ( struct V_47 * V_48 , struct V_28 * V_29 ,
T_5 V_142 )
{
int V_26 ;
if ( ! V_29 -> V_157 -> V_158 || ! V_29 -> V_29 . V_143 ||
! ( V_142 & V_144 ) )
return 0 ;
V_26 = F_96 ( V_48 , V_29 ) ;
if ( V_26 )
return V_26 ;
if ( F_91 ( V_29 -> V_29 . V_143 ) ) {
V_26 = F_95 ( V_48 , V_29 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_98 ( struct V_47 * V_48 , struct V_28 * V_29 )
{
int V_26 ;
struct V_173 V_174 ;
V_26 = F_99 ( V_29 , & V_174 ) ;
if ( V_26 ) {
if ( V_26 == - V_175 )
return 0 ;
return V_26 ;
}
if ( F_79 ( V_48 , V_176 , V_174 . V_177 , V_174 . V_86 ) )
return - V_51 ;
return 0 ;
}
static int F_100 ( struct V_47 * V_48 , struct V_28 * V_29 ,
int type , T_5 V_65 , T_5 V_178 , T_5 V_179 ,
unsigned int V_75 , T_5 V_142 )
{
struct V_110 * V_111 ;
struct V_73 * V_74 ;
struct V_116 V_180 ;
const struct V_116 * V_181 ;
struct V_39 * V_182 , * V_183 ;
struct V_43 * V_45 ;
struct V_28 * V_184 = F_44 ( V_29 ) ;
F_101 () ;
V_74 = F_102 ( V_48 , V_65 , V_178 , type , sizeof( * V_111 ) , V_75 ) ;
if ( V_74 == NULL )
return - V_51 ;
V_111 = F_103 ( V_74 ) ;
V_111 -> V_185 = V_186 ;
V_111 -> V_187 = 0 ;
V_111 -> V_188 = V_29 -> type ;
V_111 -> V_189 = V_29 -> V_190 ;
V_111 -> V_112 = F_104 ( V_29 ) ;
V_111 -> V_113 = V_179 ;
if ( F_54 ( V_48 , V_191 , V_29 -> V_192 ) ||
F_73 ( V_48 , V_193 , V_29 -> V_194 ) ||
F_105 ( V_48 , V_195 ,
F_106 ( V_29 ) ? V_29 -> V_102 : V_196 ) ||
F_105 ( V_48 , V_197 , V_29 -> V_198 ) ||
F_73 ( V_48 , V_199 , V_29 -> V_200 ) ||
F_73 ( V_48 , V_201 , V_29 -> V_66 ) ||
F_73 ( V_48 , V_202 , V_29 -> V_203 ) ||
F_73 ( V_48 , V_204 , V_29 -> V_205 ) ||
#ifdef F_107
F_73 ( V_48 , V_206 , V_29 -> V_207 ) ||
#endif
( V_29 -> V_190 != V_29 -> V_208 &&
F_73 ( V_48 , V_209 , V_29 -> V_208 ) ) ||
( V_184 &&
F_73 ( V_48 , V_210 , V_184 -> V_190 ) ) ||
F_105 ( V_48 , V_211 , F_108 ( V_29 ) ) ||
( V_29 -> V_212 &&
F_54 ( V_48 , V_213 , V_29 -> V_212 -> V_20 -> V_86 ) ) ||
( V_29 -> V_214 &&
F_54 ( V_48 , V_215 , V_29 -> V_214 ) ) ||
F_73 ( V_48 , V_216 ,
F_76 ( & V_29 -> V_217 ) ) )
goto V_83;
if ( 1 ) {
struct V_161 V_218 = {
. V_219 = V_29 -> V_219 ,
. V_220 = V_29 -> V_220 ,
. V_221 = V_29 -> V_221 ,
. V_222 = V_29 -> V_222 ,
. V_223 = V_29 -> V_223 ,
. V_224 = V_29 -> V_225 ,
} ;
if ( F_79 ( V_48 , V_226 , sizeof( V_218 ) , & V_218 ) )
goto V_83;
}
if ( V_29 -> V_227 ) {
if ( F_79 ( V_48 , V_228 , V_29 -> V_227 , V_29 -> V_229 ) ||
F_79 ( V_48 , V_230 , V_29 -> V_227 , V_29 -> V_231 ) )
goto V_83;
}
if ( F_98 ( V_48 , V_29 ) )
goto V_83;
V_182 = F_109 ( V_48 , V_232 ,
sizeof( struct V_114 ) ) ;
if ( V_182 == NULL )
goto V_83;
V_181 = F_110 ( V_29 , & V_180 ) ;
F_87 ( F_111 ( V_182 ) , V_181 ) ;
V_182 = F_109 ( V_48 , V_233 ,
sizeof( struct V_116 ) ) ;
if ( V_182 == NULL )
goto V_83;
F_88 ( F_111 ( V_182 ) , V_181 ) ;
if ( V_29 -> V_29 . V_143 && ( V_142 & V_144 ) &&
F_73 ( V_48 , V_234 , F_91 ( V_29 -> V_29 . V_143 ) ) )
goto V_83;
if ( V_29 -> V_157 -> V_235 && V_29 -> V_29 . V_143
&& ( V_142 & V_144 ) ) {
int V_79 ;
struct V_39 * V_236 , * V_166 ;
int V_145 = F_91 ( V_29 -> V_29 . V_143 ) ;
V_236 = F_55 ( V_48 , V_237 ) ;
if ( ! V_236 )
goto V_83;
for ( V_79 = 0 ; V_79 < V_145 ; V_79 ++ ) {
struct V_238 V_239 ;
struct V_146 V_240 ;
struct V_147 V_241 ;
struct V_148 V_242 ;
struct V_149 V_243 ;
struct V_244 V_245 ;
V_239 . V_246 = - 1 ;
memset ( V_239 . V_247 , 0 , sizeof( V_239 . V_247 ) ) ;
V_239 . V_248 = 0 ;
if ( V_29 -> V_157 -> V_235 ( V_29 , V_79 , & V_239 ) )
break;
V_240 . V_166 =
V_241 . V_166 =
V_242 . V_166 =
V_243 . V_166 =
V_245 . V_166 = V_239 . V_166 ;
memcpy ( V_240 . V_247 , V_239 . V_247 , sizeof( V_239 . V_247 ) ) ;
V_241 . V_249 = V_239 . V_249 ;
V_241 . V_250 = V_239 . V_250 ;
V_242 . V_251 = V_239 . V_252 ;
V_243 . V_253 = V_239 . V_246 ;
V_245 . V_254 = V_239 . V_248 ;
V_166 = F_55 ( V_48 , V_255 ) ;
if ( ! V_166 ) {
F_57 ( V_48 , V_236 ) ;
goto V_83;
}
if ( F_79 ( V_48 , V_256 , sizeof( V_240 ) , & V_240 ) ||
F_79 ( V_48 , V_257 , sizeof( V_241 ) , & V_241 ) ||
F_79 ( V_48 , V_258 , sizeof( V_242 ) ,
& V_242 ) ||
F_79 ( V_48 , V_259 , sizeof( V_243 ) ,
& V_243 ) ||
F_79 ( V_48 , V_260 , sizeof( V_245 ) ,
& V_245 ) )
goto V_83;
F_56 ( V_48 , V_166 ) ;
}
F_56 ( V_48 , V_236 ) ;
}
if ( F_97 ( V_48 , V_29 , V_142 ) )
goto V_83;
if ( V_29 -> V_18 || F_52 ( V_29 ) ) {
if ( F_59 ( V_48 , V_29 ) < 0 )
goto V_83;
}
if ( ! ( V_183 = F_55 ( V_48 , V_261 ) ) )
goto V_83;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_45 -> V_262 ) {
struct V_39 * V_263 ;
int V_26 ;
if ( ! ( V_263 = F_55 ( V_48 , V_45 -> V_44 ) ) )
goto V_83;
V_26 = V_45 -> V_262 ( V_48 , V_29 ) ;
if ( V_26 == - V_264 )
F_57 ( V_48 , V_263 ) ;
else if ( V_26 < 0 )
goto V_83;
F_56 ( V_48 , V_263 ) ;
}
}
F_56 ( V_48 , V_183 ) ;
return F_112 ( V_48 , V_74 ) ;
V_83:
F_113 ( V_48 , V_74 ) ;
return - V_51 ;
}
static int F_114 ( struct V_47 * V_48 , struct V_265 * V_266 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
int V_268 , V_269 ;
int V_270 = 0 , V_271 ;
struct V_28 * V_29 ;
struct V_272 * V_273 ;
struct V_39 * V_274 [ V_275 + 1 ] ;
T_5 V_142 = 0 ;
int V_26 ;
V_269 = V_266 -> args [ 0 ] ;
V_271 = V_266 -> args [ 1 ] ;
F_116 () ;
V_266 -> V_178 = V_27 -> V_276 ;
if ( F_117 ( V_266 -> V_74 , sizeof( struct V_110 ) , V_274 , V_275 ,
V_277 ) >= 0 ) {
if ( V_274 [ V_278 ] )
V_142 = F_118 ( V_274 [ V_278 ] ) ;
}
for ( V_268 = V_269 ; V_268 < V_279 ; V_268 ++ , V_271 = 0 ) {
V_270 = 0 ;
V_273 = & V_27 -> V_280 [ V_268 ] ;
F_119 (dev, head, index_hlist) {
if ( V_270 < V_271 )
goto V_281;
V_26 = F_100 ( V_48 , V_29 , V_282 ,
F_61 ( V_266 -> V_48 ) . V_283 ,
V_266 -> V_74 -> V_284 , 0 ,
V_285 ,
V_142 ) ;
F_120 ( ( V_26 == - V_51 ) && ( V_48 -> V_286 == 0 ) ) ;
if ( V_26 <= 0 )
goto V_63;
F_121 ( V_266 , F_122 ( V_48 ) ) ;
V_281:
V_270 ++ ;
}
}
V_63:
F_123 () ;
V_266 -> args [ 1 ] = V_270 ;
V_266 -> args [ 0 ] = V_268 ;
return V_48 -> V_286 ;
}
int F_124 ( struct V_39 * * V_274 , const struct V_39 * V_273 , int V_286 )
{
return F_125 ( V_274 , V_275 , V_273 , V_286 , V_277 ) ;
}
struct V_27 * F_126 ( struct V_27 * V_287 , struct V_39 * V_274 [] )
{
struct V_27 * V_27 ;
if ( V_274 [ V_288 ] )
V_27 = F_127 ( F_118 ( V_274 [ V_288 ] ) ) ;
else if ( V_274 [ V_289 ] )
V_27 = F_128 ( F_118 ( V_274 [ V_289 ] ) ) ;
else
V_27 = F_129 ( V_287 ) ;
return V_27 ;
}
static int F_130 ( struct V_28 * V_29 , struct V_39 * V_274 [] )
{
if ( V_29 ) {
if ( V_274 [ V_228 ] &&
F_131 ( V_274 [ V_228 ] ) < V_29 -> V_227 )
return - V_290 ;
if ( V_274 [ V_230 ] &&
F_131 ( V_274 [ V_230 ] ) < V_29 -> V_227 )
return - V_290 ;
}
if ( V_274 [ V_261 ] ) {
struct V_39 * V_263 ;
int V_291 , V_26 ;
F_132 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_43 * V_45 ;
if ( ! ( V_45 = F_47 ( F_133 ( V_263 ) ) ) )
return - V_292 ;
if ( ! V_45 -> V_293 )
return - V_175 ;
if ( V_45 -> V_294 ) {
V_26 = V_45 -> V_294 ( V_29 , V_263 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
}
return 0 ;
}
static int F_134 ( struct V_28 * V_29 , struct V_39 * V_182 )
{
int V_291 , V_26 = - V_290 ;
struct V_39 * V_166 ;
const struct V_295 * V_20 = V_29 -> V_157 ;
F_132 (vf, attr, rem) {
switch ( F_133 ( V_166 ) ) {
case V_256 : {
struct V_146 * V_296 ;
V_296 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_297 )
V_26 = V_20 -> V_297 ( V_29 , V_296 -> V_166 ,
V_296 -> V_247 ) ;
break;
}
case V_257 : {
struct V_147 * V_298 ;
V_298 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_299 )
V_26 = V_20 -> V_299 ( V_29 , V_298 -> V_166 ,
V_298 -> V_249 ,
V_298 -> V_250 ) ;
break;
}
case V_258 : {
struct V_148 * V_300 ;
V_300 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_301 )
V_26 = V_20 -> V_301 ( V_29 , V_300 -> V_166 ,
V_300 -> V_251 ) ;
break;
}
case V_259 : {
struct V_149 * V_302 ;
V_302 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_303 )
V_26 = V_20 -> V_303 ( V_29 , V_302 -> V_166 ,
V_302 -> V_253 ) ;
break;
}
case V_260 : {
struct V_244 * V_304 ;
V_304 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_305 )
V_26 = V_20 -> V_305 ( V_29 , V_304 -> V_166 ,
V_304 -> V_254 ) ;
break;
}
default:
V_26 = - V_290 ;
break;
}
if ( V_26 )
break;
}
return V_26 ;
}
static int F_135 ( struct V_28 * V_29 , int V_190 )
{
struct V_28 * V_184 = F_44 ( V_29 ) ;
const struct V_295 * V_20 ;
int V_26 ;
if ( V_184 ) {
if ( V_184 -> V_190 == V_190 )
return 0 ;
V_20 = V_184 -> V_157 ;
if ( V_20 -> V_306 ) {
V_26 = V_20 -> V_306 ( V_184 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_175 ;
}
}
if ( V_190 ) {
V_184 = F_136 ( F_137 ( V_29 ) , V_190 ) ;
if ( ! V_184 )
return - V_290 ;
V_20 = V_184 -> V_157 ;
if ( V_20 -> V_307 ) {
V_26 = V_20 -> V_307 ( V_184 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_175 ;
}
}
return 0 ;
}
static int F_138 ( const struct V_47 * V_48 ,
struct V_28 * V_29 , struct V_110 * V_111 ,
struct V_39 * * V_274 , char * V_308 , int V_309 )
{
const struct V_295 * V_20 = V_29 -> V_157 ;
int V_26 ;
if ( V_274 [ V_288 ] || V_274 [ V_289 ] ) {
struct V_27 * V_27 = F_126 ( F_137 ( V_29 ) , V_274 ) ;
if ( F_139 ( V_27 ) ) {
V_26 = F_140 ( V_27 ) ;
goto V_310;
}
if ( ! F_141 ( V_48 , V_27 -> V_311 , V_312 ) ) {
V_26 = - V_313 ;
goto V_310;
}
V_26 = F_142 ( V_29 , V_27 , V_308 ) ;
F_143 ( V_27 ) ;
if ( V_26 )
goto V_310;
V_309 = 1 ;
}
if ( V_274 [ V_226 ] ) {
struct V_161 * V_314 ;
struct V_315 V_316 ;
if ( ! V_20 -> V_317 ) {
V_26 = - V_175 ;
goto V_310;
}
if ( ! F_144 ( V_29 ) ) {
V_26 = - V_318 ;
goto V_310;
}
V_314 = F_111 ( V_274 [ V_226 ] ) ;
V_316 . V_219 = ( unsigned long ) V_314 -> V_219 ;
V_316 . V_220 = ( unsigned long ) V_314 -> V_220 ;
V_316 . V_221 = ( unsigned short ) V_314 -> V_221 ;
V_316 . V_222 = ( unsigned char ) V_314 -> V_222 ;
V_316 . V_223 = ( unsigned char ) V_314 -> V_223 ;
V_316 . V_224 = ( unsigned char ) V_314 -> V_224 ;
V_26 = V_20 -> V_317 ( V_29 , & V_316 ) ;
if ( V_26 < 0 )
goto V_310;
V_309 = 1 ;
}
if ( V_274 [ V_228 ] ) {
struct V_319 * V_320 ;
int V_286 ;
V_286 = sizeof( V_321 ) + V_29 -> V_227 ;
V_320 = F_145 ( V_286 , V_15 ) ;
if ( ! V_320 ) {
V_26 = - V_322 ;
goto V_310;
}
V_320 -> V_323 = V_29 -> type ;
memcpy ( V_320 -> V_324 , F_111 ( V_274 [ V_228 ] ) ,
V_29 -> V_227 ) ;
V_26 = F_146 ( V_29 , V_320 ) ;
F_24 ( V_320 ) ;
if ( V_26 )
goto V_310;
V_309 = 1 ;
}
if ( V_274 [ V_199 ] ) {
V_26 = F_147 ( V_29 , F_118 ( V_274 [ V_199 ] ) ) ;
if ( V_26 < 0 )
goto V_310;
V_309 = 1 ;
}
if ( V_274 [ V_201 ] ) {
F_148 ( V_29 , F_118 ( V_274 [ V_201 ] ) ) ;
V_309 = 1 ;
}
if ( V_111 -> V_189 > 0 && V_308 [ 0 ] ) {
V_26 = F_149 ( V_29 , V_308 ) ;
if ( V_26 < 0 )
goto V_310;
V_309 = 1 ;
}
if ( V_274 [ V_215 ] ) {
V_26 = F_150 ( V_29 , F_111 ( V_274 [ V_215 ] ) ,
F_131 ( V_274 [ V_215 ] ) ) ;
if ( V_26 < 0 )
goto V_310;
V_309 = 1 ;
}
if ( V_274 [ V_230 ] ) {
F_151 ( V_29 -> V_231 , V_274 [ V_230 ] , V_29 -> V_227 ) ;
F_152 ( V_325 , V_29 ) ;
}
if ( V_111 -> V_112 || V_111 -> V_113 ) {
V_26 = F_153 ( V_29 , F_86 ( V_29 , V_111 ) ) ;
if ( V_26 < 0 )
goto V_310;
}
if ( V_274 [ V_210 ] ) {
V_26 = F_135 ( V_29 , F_118 ( V_274 [ V_210 ] ) ) ;
if ( V_26 )
goto V_310;
V_309 = 1 ;
}
if ( V_274 [ V_211 ] ) {
V_26 = F_154 ( V_29 , F_155 ( V_274 [ V_211 ] ) ) ;
if ( V_26 )
goto V_310;
V_309 = 1 ;
}
if ( V_274 [ V_193 ] )
V_29 -> V_194 = F_118 ( V_274 [ V_193 ] ) ;
if ( V_274 [ V_195 ] )
F_80 ( V_29 , F_155 ( V_274 [ V_195 ] ) ) ;
if ( V_274 [ V_197 ] ) {
F_82 ( & V_106 ) ;
V_29 -> V_198 = F_155 ( V_274 [ V_197 ] ) ;
F_83 ( & V_106 ) ;
}
if ( V_274 [ V_237 ] ) {
struct V_39 * V_182 ;
int V_291 ;
F_132 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_133 ( V_182 ) != V_255 ) {
V_26 = - V_290 ;
goto V_310;
}
V_26 = F_134 ( V_29 , V_182 ) ;
if ( V_26 < 0 )
goto V_310;
V_309 = 1 ;
}
}
V_26 = 0 ;
if ( V_274 [ V_167 ] ) {
struct V_39 * V_224 [ V_326 + 1 ] ;
struct V_39 * V_182 ;
int V_166 ;
int V_291 ;
V_26 = - V_175 ;
if ( ! V_20 -> V_327 )
goto V_310;
F_132 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_133 ( V_182 ) != V_168 )
continue;
V_26 = F_156 ( V_224 , V_326 ,
V_182 , V_328 ) ;
if ( V_26 < 0 )
goto V_310;
if ( ! V_224 [ V_169 ] ) {
V_26 = - V_175 ;
goto V_310;
}
V_166 = F_118 ( V_224 [ V_169 ] ) ;
V_26 = V_20 -> V_327 ( V_29 , V_166 , V_224 ) ;
if ( V_26 < 0 )
goto V_310;
V_309 = 1 ;
}
}
V_26 = 0 ;
if ( V_274 [ V_171 ] ) {
struct V_39 * V_224 [ V_326 + 1 ] ;
V_26 = F_156 ( V_224 , V_326 ,
V_274 [ V_171 ] , V_328 ) ;
if ( V_26 < 0 )
goto V_310;
V_26 = - V_175 ;
if ( V_20 -> V_327 )
V_26 = V_20 -> V_327 ( V_29 , V_172 , V_224 ) ;
if ( V_26 < 0 )
goto V_310;
V_309 = 1 ;
}
if ( V_274 [ V_261 ] ) {
struct V_39 * V_263 ;
int V_291 ;
F_132 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_43 * V_45 ;
if ( ! ( V_45 = F_47 ( F_133 ( V_263 ) ) ) )
F_157 () ;
V_26 = V_45 -> V_293 ( V_29 , V_263 ) ;
if ( V_26 < 0 )
goto V_310;
V_309 = 1 ;
}
}
V_26 = 0 ;
V_310:
if ( V_26 < 0 && V_309 )
F_158 ( L_3 ,
V_29 -> V_192 ) ;
return V_26 ;
}
static int F_159 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
struct V_110 * V_111 ;
struct V_28 * V_29 ;
int V_26 ;
struct V_39 * V_274 [ V_275 + 1 ] ;
char V_308 [ V_159 ] ;
V_26 = F_117 ( V_74 , sizeof( * V_111 ) , V_274 , V_275 , V_277 ) ;
if ( V_26 < 0 )
goto V_310;
if ( V_274 [ V_191 ] )
F_160 ( V_308 , V_274 [ V_191 ] , V_159 ) ;
else
V_308 [ 0 ] = '\0' ;
V_26 = - V_290 ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_189 > 0 )
V_29 = F_136 ( V_27 , V_111 -> V_189 ) ;
else if ( V_274 [ V_191 ] )
V_29 = F_161 ( V_27 , V_308 ) ;
else
goto V_310;
if ( V_29 == NULL ) {
V_26 = - V_318 ;
goto V_310;
}
V_26 = F_130 ( V_29 , V_274 ) ;
if ( V_26 < 0 )
goto V_310;
V_26 = F_138 ( V_48 , V_29 , V_111 , V_274 , V_308 , 0 ) ;
V_310:
return V_26 ;
}
static int F_162 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_110 * V_111 ;
char V_308 [ V_159 ] ;
struct V_39 * V_274 [ V_275 + 1 ] ;
int V_26 ;
F_31 ( V_30 ) ;
V_26 = F_117 ( V_74 , sizeof( * V_111 ) , V_274 , V_275 , V_277 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_274 [ V_191 ] )
F_160 ( V_308 , V_274 [ V_191 ] , V_159 ) ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_189 > 0 )
V_29 = F_136 ( V_27 , V_111 -> V_189 ) ;
else if ( V_274 [ V_191 ] )
V_29 = F_161 ( V_27 , V_308 ) ;
else
return - V_290 ;
if ( ! V_29 )
return - V_318 ;
V_20 = V_29 -> V_18 ;
if ( ! V_20 )
return - V_175 ;
V_20 -> V_22 ( V_29 , & V_30 ) ;
F_33 ( & V_30 ) ;
F_36 ( & V_30 ) ;
return 0 ;
}
int F_163 ( struct V_28 * V_29 , const struct V_110 * V_111 )
{
unsigned int V_329 ;
int V_26 ;
V_329 = V_29 -> V_75 ;
if ( V_111 && ( V_111 -> V_112 || V_111 -> V_113 ) ) {
V_26 = F_164 ( V_29 , F_86 ( V_29 , V_111 ) ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_29 -> V_330 = V_331 ;
F_165 ( V_29 , V_329 , ~ 0U ) ;
return 0 ;
}
struct V_28 * F_166 ( struct V_27 * V_27 ,
char * V_308 , const struct V_18 * V_20 , struct V_39 * V_274 [] )
{
int V_26 ;
struct V_28 * V_29 ;
unsigned int V_205 = 1 ;
unsigned int V_207 = 1 ;
if ( V_274 [ V_204 ] )
V_205 = F_118 ( V_274 [ V_204 ] ) ;
else if ( V_20 -> V_332 )
V_205 = V_20 -> V_332 () ;
if ( V_274 [ V_206 ] )
V_207 = F_118 ( V_274 [ V_206 ] ) ;
else if ( V_20 -> V_333 )
V_207 = V_20 -> V_333 () ;
V_26 = - V_322 ;
V_29 = F_167 ( V_20 -> V_334 , V_308 , V_20 -> V_335 ,
V_205 , V_207 ) ;
if ( ! V_29 )
goto V_26;
F_168 ( V_29 , V_27 ) ;
V_29 -> V_18 = V_20 ;
V_29 -> V_330 = V_336 ;
if ( V_274 [ V_199 ] )
V_29 -> V_200 = F_118 ( V_274 [ V_199 ] ) ;
if ( V_274 [ V_228 ] ) {
memcpy ( V_29 -> V_229 , F_111 ( V_274 [ V_228 ] ) ,
F_131 ( V_274 [ V_228 ] ) ) ;
V_29 -> V_337 = V_338 ;
}
if ( V_274 [ V_230 ] )
memcpy ( V_29 -> V_231 , F_111 ( V_274 [ V_230 ] ) ,
F_131 ( V_274 [ V_230 ] ) ) ;
if ( V_274 [ V_193 ] )
V_29 -> V_194 = F_118 ( V_274 [ V_193 ] ) ;
if ( V_274 [ V_195 ] )
F_80 ( V_29 , F_155 ( V_274 [ V_195 ] ) ) ;
if ( V_274 [ V_197 ] )
V_29 -> V_198 = F_155 ( V_274 [ V_197 ] ) ;
if ( V_274 [ V_201 ] )
F_148 ( V_29 , F_118 ( V_274 [ V_201 ] ) ) ;
return V_29 ;
V_26:
return F_169 ( V_26 ) ;
}
static int F_170 ( const struct V_47 * V_48 ,
struct V_27 * V_27 , int V_66 ,
struct V_110 * V_111 ,
struct V_39 * * V_274 )
{
struct V_28 * V_29 ;
int V_26 ;
F_32 (net, dev) {
if ( V_29 -> V_66 == V_66 ) {
V_26 = F_138 ( V_48 , V_29 , V_111 , V_274 , NULL , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
return 0 ;
}
static int F_171 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_339 = NULL ;
struct V_28 * V_29 ;
struct V_28 * V_37 = NULL ;
struct V_110 * V_111 ;
char V_19 [ V_340 ] ;
char V_308 [ V_159 ] ;
struct V_39 * V_274 [ V_275 + 1 ] ;
struct V_39 * V_61 [ V_341 + 1 ] ;
int V_26 ;
#ifdef F_172
V_342:
#endif
V_26 = F_117 ( V_74 , sizeof( * V_111 ) , V_274 , V_275 , V_277 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_274 [ V_191 ] )
F_160 ( V_308 , V_274 [ V_191 ] , V_159 ) ;
else
V_308 [ 0 ] = '\0' ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_189 > 0 )
V_29 = F_136 ( V_27 , V_111 -> V_189 ) ;
else {
if ( V_308 [ 0 ] )
V_29 = F_161 ( V_27 , V_308 ) ;
else
V_29 = NULL ;
}
if ( V_29 ) {
V_37 = F_44 ( V_29 ) ;
if ( V_37 )
V_339 = V_37 -> V_18 ;
}
V_26 = F_130 ( V_29 , V_274 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_274 [ V_62 ] ) {
V_26 = F_156 ( V_61 , V_341 ,
V_274 [ V_62 ] , V_343 ) ;
if ( V_26 < 0 )
return V_26 ;
} else
memset ( V_61 , 0 , sizeof( V_61 ) ) ;
if ( V_61 [ V_56 ] ) {
F_160 ( V_19 , V_61 [ V_56 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_39 * V_182 [ V_20 ? V_20 -> V_344 + 1 : 0 ] ;
struct V_39 * V_345 [ V_339 ? V_339 -> V_346 + 1 : 0 ] ;
struct V_39 * * V_55 = NULL ;
struct V_39 * * V_49 = NULL ;
struct V_27 * V_347 ;
if ( V_20 ) {
if ( V_20 -> V_344 && V_61 [ V_59 ] ) {
V_26 = F_156 ( V_182 , V_20 -> V_344 ,
V_61 [ V_59 ] ,
V_20 -> V_348 ) ;
if ( V_26 < 0 )
return V_26 ;
V_55 = V_182 ;
}
if ( V_20 -> V_349 ) {
V_26 = V_20 -> V_349 ( V_274 , V_55 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_339 ) {
if ( V_339 -> V_346 &&
V_61 [ V_53 ] ) {
V_26 = F_156 ( V_345 ,
V_339 -> V_346 ,
V_61 [ V_53 ] ,
V_339 -> V_350 ) ;
if ( V_26 < 0 )
return V_26 ;
V_49 = V_345 ;
}
if ( V_339 -> V_351 ) {
V_26 = V_339 -> V_351 ( V_274 , V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_29 ) {
int V_309 = 0 ;
if ( V_74 -> V_352 & V_353 )
return - V_21 ;
if ( V_74 -> V_352 & V_354 )
return - V_175 ;
if ( V_61 [ V_59 ] ) {
if ( ! V_20 || V_20 != V_29 -> V_18 ||
! V_20 -> V_355 )
return - V_175 ;
V_26 = V_20 -> V_355 ( V_29 , V_274 , V_55 ) ;
if ( V_26 < 0 )
return V_26 ;
V_309 = 1 ;
}
if ( V_61 [ V_53 ] ) {
if ( ! V_339 || ! V_339 -> V_356 )
return - V_175 ;
V_26 = V_339 -> V_356 ( V_37 , V_29 ,
V_274 , V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
V_309 = 1 ;
}
return F_138 ( V_48 , V_29 , V_111 , V_274 , V_308 , V_309 ) ;
}
if ( ! ( V_74 -> V_352 & V_357 ) ) {
if ( V_111 -> V_189 == 0 && V_274 [ V_201 ] )
return F_170 ( V_48 , V_27 ,
F_118 ( V_274 [ V_201 ] ) ,
V_111 , V_274 ) ;
return - V_318 ;
}
if ( V_274 [ V_226 ] || V_274 [ V_210 ] || V_274 [ V_358 ] )
return - V_175 ;
if ( ! V_20 ) {
#ifdef F_172
if ( V_19 [ 0 ] ) {
F_3 () ;
F_173 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_342;
}
#endif
return - V_175 ;
}
if ( ! V_308 [ 0 ] )
snprintf ( V_308 , V_159 , L_5 , V_20 -> V_19 ) ;
V_347 = F_126 ( V_27 , V_274 ) ;
if ( F_139 ( V_347 ) )
return F_140 ( V_347 ) ;
V_29 = F_166 ( V_347 , V_308 , V_20 , V_274 ) ;
if ( F_139 ( V_29 ) ) {
V_26 = F_140 ( V_29 ) ;
goto V_63;
}
V_29 -> V_190 = V_111 -> V_189 ;
if ( V_20 -> V_359 ) {
V_26 = V_20 -> V_359 ( V_27 , V_29 , V_274 , V_55 ) ;
if ( V_26 < 0 )
goto V_63;
} else {
V_26 = F_174 ( V_29 ) ;
if ( V_26 < 0 ) {
F_175 ( V_29 ) ;
goto V_63;
}
}
V_26 = F_163 ( V_29 , V_111 ) ;
if ( V_26 < 0 )
F_176 ( V_29 ) ;
V_63:
F_143 ( V_347 ) ;
return V_26 ;
}
}
static int F_177 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
struct V_110 * V_111 ;
char V_308 [ V_159 ] ;
struct V_39 * V_274 [ V_275 + 1 ] ;
struct V_28 * V_29 = NULL ;
struct V_47 * V_360 ;
int V_26 ;
T_5 V_142 = 0 ;
V_26 = F_117 ( V_74 , sizeof( * V_111 ) , V_274 , V_275 , V_277 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_274 [ V_191 ] )
F_160 ( V_308 , V_274 [ V_191 ] , V_159 ) ;
if ( V_274 [ V_278 ] )
V_142 = F_118 ( V_274 [ V_278 ] ) ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_189 > 0 )
V_29 = F_136 ( V_27 , V_111 -> V_189 ) ;
else if ( V_274 [ V_191 ] )
V_29 = F_161 ( V_27 , V_308 ) ;
else
return - V_290 ;
if ( V_29 == NULL )
return - V_318 ;
V_360 = F_178 ( F_93 ( V_29 , V_142 ) , V_15 ) ;
if ( V_360 == NULL )
return - V_16 ;
V_26 = F_100 ( V_360 , V_29 , V_282 , F_61 ( V_48 ) . V_283 ,
V_74 -> V_284 , 0 , 0 , V_142 ) ;
if ( V_26 < 0 ) {
F_120 ( V_26 == - V_51 ) ;
F_179 ( V_360 ) ;
} else
V_26 = F_65 ( V_360 , V_27 , F_61 ( V_48 ) . V_283 ) ;
return V_26 ;
}
static T_8 F_180 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
struct V_28 * V_29 ;
struct V_39 * V_274 [ V_275 + 1 ] ;
T_5 V_142 = 0 ;
T_8 V_361 = 0 ;
if ( F_117 ( V_74 , sizeof( struct V_110 ) , V_274 , V_275 ,
V_277 ) >= 0 ) {
if ( V_274 [ V_278 ] )
V_142 = F_118 ( V_274 [ V_278 ] ) ;
}
if ( ! V_142 )
return V_362 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_361 = F_181 ( T_8 , V_361 ,
F_93 ( V_29 ,
V_142 ) ) ;
}
return V_361 ;
}
static int F_182 ( struct V_47 * V_48 , struct V_265 * V_266 )
{
int V_270 ;
int V_271 = V_266 -> V_44 ;
if ( V_271 == 0 )
V_271 = 1 ;
for ( V_270 = 1 ; V_270 <= V_9 ; V_270 ++ ) {
int type = V_266 -> V_74 -> V_363 - V_4 ;
if ( V_270 < V_271 || V_270 == V_364 )
continue;
if ( V_10 [ V_270 ] == NULL ||
V_10 [ V_270 ] [ type ] . V_13 == NULL )
continue;
if ( V_270 > V_271 ) {
memset ( & V_266 -> args [ 0 ] , 0 , sizeof( V_266 -> args ) ) ;
V_266 -> V_365 = 0 ;
V_266 -> V_178 = 0 ;
}
if ( V_10 [ V_270 ] [ type ] . V_13 ( V_48 , V_266 ) )
break;
}
V_266 -> V_44 = V_270 ;
return V_48 -> V_286 ;
}
void F_183 ( int type , struct V_28 * V_29 , unsigned int V_179 ,
T_6 V_75 )
{
struct V_27 * V_27 = F_137 ( V_29 ) ;
struct V_47 * V_48 ;
int V_26 = - V_16 ;
T_4 V_366 ;
V_48 = F_178 ( ( V_366 = F_93 ( V_29 , 0 ) ) , V_75 ) ;
if ( V_48 == NULL )
goto V_310;
V_26 = F_100 ( V_48 , V_29 , type , 0 , 0 , V_179 , 0 , 0 ) ;
if ( V_26 < 0 ) {
F_120 ( V_26 == - V_51 ) ;
F_179 ( V_48 ) ;
goto V_310;
}
F_67 ( V_48 , V_27 , 0 , V_367 , NULL , V_75 ) ;
return;
V_310:
if ( V_26 < 0 )
F_70 ( V_27 , V_367 , V_26 ) ;
}
static int F_184 ( struct V_47 * V_48 ,
struct V_28 * V_29 ,
T_9 * V_368 , T_5 V_65 , T_5 V_178 ,
int type , unsigned int V_75 ,
int V_369 )
{
struct V_73 * V_74 ;
struct V_370 * V_371 ;
V_74 = F_102 ( V_48 , V_65 , V_178 , type , sizeof( * V_371 ) , V_369 ) ;
if ( ! V_74 )
return - V_51 ;
V_371 = F_103 ( V_74 ) ;
V_371 -> V_372 = V_373 ;
V_371 -> V_374 = 0 ;
V_371 -> V_375 = 0 ;
V_371 -> V_376 = V_75 ;
V_371 -> V_377 = 0 ;
V_371 -> V_378 = V_29 -> V_190 ;
V_371 -> V_379 = V_380 ;
if ( F_79 ( V_48 , V_381 , V_382 , V_368 ) )
goto V_83;
return F_112 ( V_48 , V_74 ) ;
V_83:
F_113 ( V_48 , V_74 ) ;
return - V_51 ;
}
static inline T_4 F_185 ( void )
{
return F_94 ( sizeof( struct V_370 ) ) + F_45 ( V_382 ) ;
}
static void F_186 ( struct V_28 * V_29 , T_9 * V_368 , int type )
{
struct V_27 * V_27 = F_137 ( V_29 ) ;
struct V_47 * V_48 ;
int V_26 = - V_16 ;
V_48 = F_178 ( F_185 () , V_383 ) ;
if ( ! V_48 )
goto V_310;
V_26 = F_184 ( V_48 , V_29 , V_368 , 0 , 0 , type , V_384 , 0 ) ;
if ( V_26 < 0 ) {
F_179 ( V_48 ) ;
goto V_310;
}
F_67 ( V_48 , V_27 , 0 , V_385 , NULL , V_383 ) ;
return;
V_310:
F_70 ( V_27 , V_385 , V_26 ) ;
}
int F_187 ( struct V_370 * V_371 ,
struct V_39 * V_274 [] ,
struct V_28 * V_29 ,
const unsigned char * V_368 ,
T_8 V_75 )
{
int V_26 = - V_290 ;
if ( V_371 -> V_379 && ! ( V_371 -> V_379 & V_380 ) ) {
F_188 ( L_6 , V_29 -> V_192 ) ;
return V_26 ;
}
if ( F_189 ( V_368 ) || F_190 ( V_368 ) )
V_26 = F_191 ( V_29 , V_368 ) ;
else if ( F_192 ( V_368 ) )
V_26 = F_193 ( V_29 , V_368 ) ;
if ( V_26 == - V_21 && ! ( V_75 & V_353 ) )
V_26 = 0 ;
return V_26 ;
}
static int F_194 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
struct V_370 * V_371 ;
struct V_39 * V_274 [ V_386 + 1 ] ;
struct V_28 * V_29 ;
T_9 * V_368 ;
int V_26 ;
V_26 = F_117 ( V_74 , sizeof( * V_371 ) , V_274 , V_386 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_371 = F_103 ( V_74 ) ;
if ( V_371 -> V_378 == 0 ) {
F_188 ( L_7 ) ;
return - V_290 ;
}
V_29 = F_136 ( V_27 , V_371 -> V_378 ) ;
if ( V_29 == NULL ) {
F_188 ( L_8 ) ;
return - V_318 ;
}
if ( ! V_274 [ V_381 ] || F_131 ( V_274 [ V_381 ] ) != V_382 ) {
F_188 ( L_9 ) ;
return - V_290 ;
}
V_368 = F_111 ( V_274 [ V_381 ] ) ;
V_26 = - V_175 ;
if ( ( ! V_371 -> V_376 || V_371 -> V_376 & V_387 ) &&
( V_29 -> V_388 & V_389 ) ) {
struct V_28 * V_390 = F_44 ( V_29 ) ;
const struct V_295 * V_20 = V_390 -> V_157 ;
V_26 = V_20 -> V_391 ( V_371 , V_274 , V_29 , V_368 , V_74 -> V_352 ) ;
if ( V_26 )
goto V_63;
else
V_371 -> V_376 &= ~ V_387 ;
}
if ( ( V_371 -> V_376 & V_384 ) ) {
if ( V_29 -> V_157 -> V_391 )
V_26 = V_29 -> V_157 -> V_391 ( V_371 , V_274 , V_29 , V_368 ,
V_74 -> V_352 ) ;
else
V_26 = F_187 ( V_371 , V_274 , V_29 , V_368 ,
V_74 -> V_352 ) ;
if ( ! V_26 ) {
F_186 ( V_29 , V_368 , V_392 ) ;
V_371 -> V_376 &= ~ V_384 ;
}
}
V_63:
return V_26 ;
}
int F_195 ( struct V_370 * V_371 ,
struct V_39 * V_274 [] ,
struct V_28 * V_29 ,
const unsigned char * V_368 )
{
int V_26 = - V_175 ;
if ( ! ( V_371 -> V_379 & V_380 ) ) {
F_188 ( L_6 , V_29 -> V_192 ) ;
return - V_290 ;
}
if ( F_189 ( V_368 ) || F_190 ( V_368 ) )
V_26 = F_196 ( V_29 , V_368 ) ;
else if ( F_192 ( V_368 ) )
V_26 = F_197 ( V_29 , V_368 ) ;
else
V_26 = - V_290 ;
return V_26 ;
}
static int F_198 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
struct V_370 * V_371 ;
struct V_39 * V_274 [ V_386 + 1 ] ;
struct V_28 * V_29 ;
int V_26 = - V_290 ;
T_10 * V_368 ;
if ( ! F_199 ( V_48 , V_312 ) )
return - V_313 ;
V_26 = F_117 ( V_74 , sizeof( * V_371 ) , V_274 , V_386 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_371 = F_103 ( V_74 ) ;
if ( V_371 -> V_378 == 0 ) {
F_188 ( L_10 ) ;
return - V_290 ;
}
V_29 = F_136 ( V_27 , V_371 -> V_378 ) ;
if ( V_29 == NULL ) {
F_188 ( L_11 ) ;
return - V_318 ;
}
if ( ! V_274 [ V_381 ] || F_131 ( V_274 [ V_381 ] ) != V_382 ) {
F_188 ( L_12 ) ;
return - V_290 ;
}
V_368 = F_111 ( V_274 [ V_381 ] ) ;
V_26 = - V_175 ;
if ( ( ! V_371 -> V_376 || V_371 -> V_376 & V_387 ) &&
( V_29 -> V_388 & V_389 ) ) {
struct V_28 * V_390 = F_44 ( V_29 ) ;
const struct V_295 * V_20 = V_390 -> V_157 ;
if ( V_20 -> V_393 )
V_26 = V_20 -> V_393 ( V_371 , V_274 , V_29 , V_368 ) ;
if ( V_26 )
goto V_63;
else
V_371 -> V_376 &= ~ V_387 ;
}
if ( V_371 -> V_376 & V_384 ) {
if ( V_29 -> V_157 -> V_393 )
V_26 = V_29 -> V_157 -> V_393 ( V_371 , V_274 , V_29 , V_368 ) ;
else
V_26 = F_195 ( V_371 , V_274 , V_29 , V_368 ) ;
if ( ! V_26 ) {
F_186 ( V_29 , V_368 , V_394 ) ;
V_371 -> V_376 &= ~ V_384 ;
}
}
V_63:
return V_26 ;
}
static int F_200 ( struct V_47 * V_48 ,
struct V_265 * V_266 ,
struct V_28 * V_29 ,
int * V_270 ,
struct V_395 * V_24 )
{
struct V_396 * V_397 ;
int V_26 ;
T_5 V_283 , V_178 ;
V_283 = F_61 ( V_266 -> V_48 ) . V_283 ;
V_178 = V_266 -> V_74 -> V_284 ;
F_26 (ha, &list->list, list) {
if ( * V_270 < V_266 -> args [ 0 ] )
goto V_398;
V_26 = F_184 ( V_48 , V_29 , V_397 -> V_368 ,
V_283 , V_178 ,
V_392 , V_384 ,
V_285 ) ;
if ( V_26 < 0 )
return V_26 ;
V_398:
* V_270 += 1 ;
}
return 0 ;
}
int F_201 ( struct V_47 * V_48 ,
struct V_265 * V_266 ,
struct V_28 * V_29 ,
int V_270 )
{
int V_26 ;
F_202 ( V_29 ) ;
V_26 = F_200 ( V_48 , V_266 , V_29 , & V_270 , & V_29 -> V_399 ) ;
if ( V_26 )
goto V_63;
F_200 ( V_48 , V_266 , V_29 , & V_270 , & V_29 -> V_400 ) ;
V_63:
F_203 ( V_29 ) ;
return V_270 ;
}
static int F_204 ( struct V_47 * V_48 , struct V_265 * V_266 )
{
int V_270 = 0 ;
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
struct V_28 * V_29 ;
F_116 () ;
F_205 (net, dev) {
if ( V_29 -> V_388 & V_389 ) {
struct V_28 * V_390 ;
const struct V_295 * V_20 ;
V_390 = F_44 ( V_29 ) ;
V_20 = V_390 -> V_157 ;
if ( V_20 -> V_401 )
V_270 = V_20 -> V_401 ( V_48 , V_266 , V_29 , V_270 ) ;
}
if ( V_29 -> V_157 -> V_401 )
V_270 = V_29 -> V_157 -> V_401 ( V_48 , V_266 , V_29 , V_270 ) ;
else
V_270 = F_201 ( V_48 , V_266 , V_29 , V_270 ) ;
}
F_123 () ;
V_266 -> args [ 0 ] = V_270 ;
return V_48 -> V_286 ;
}
int F_206 ( struct V_47 * V_48 , T_5 V_65 , T_5 V_178 ,
struct V_28 * V_29 , T_8 V_402 )
{
struct V_73 * V_74 ;
struct V_110 * V_111 ;
struct V_39 * V_403 ;
T_9 V_102 = F_106 ( V_29 ) ? V_29 -> V_102 : V_196 ;
struct V_28 * V_390 = F_44 ( V_29 ) ;
V_74 = F_102 ( V_48 , V_65 , V_178 , V_282 , sizeof( * V_111 ) , V_285 ) ;
if ( V_74 == NULL )
return - V_51 ;
V_111 = F_103 ( V_74 ) ;
V_111 -> V_185 = V_373 ;
V_111 -> V_187 = 0 ;
V_111 -> V_188 = V_29 -> type ;
V_111 -> V_189 = V_29 -> V_190 ;
V_111 -> V_112 = F_104 ( V_29 ) ;
V_111 -> V_113 = 0 ;
if ( F_54 ( V_48 , V_191 , V_29 -> V_192 ) ||
F_73 ( V_48 , V_199 , V_29 -> V_200 ) ||
F_105 ( V_48 , V_195 , V_102 ) ||
( V_390 &&
F_73 ( V_48 , V_210 , V_390 -> V_190 ) ) ||
( V_29 -> V_227 &&
F_79 ( V_48 , V_228 , V_29 -> V_227 , V_29 -> V_229 ) ) ||
( V_29 -> V_190 != V_29 -> V_208 &&
F_73 ( V_48 , V_209 , V_29 -> V_208 ) ) )
goto V_83;
V_403 = F_55 ( V_48 , V_261 ) ;
if ( ! V_403 )
goto V_83;
if ( F_207 ( V_48 , V_404 , V_405 ) ||
F_207 ( V_48 , V_406 , V_402 ) ) {
F_57 ( V_48 , V_403 ) ;
goto V_83;
}
F_56 ( V_48 , V_403 ) ;
return F_112 ( V_48 , V_74 ) ;
V_83:
F_113 ( V_48 , V_74 ) ;
return - V_51 ;
}
static int F_208 ( struct V_47 * V_48 , struct V_265 * V_266 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
struct V_28 * V_29 ;
int V_270 = 0 ;
T_5 V_283 = F_61 ( V_266 -> V_48 ) . V_283 ;
T_5 V_178 = V_266 -> V_74 -> V_284 ;
struct V_39 * V_407 ;
T_5 V_408 = 0 ;
V_407 = F_209 ( V_266 -> V_74 , sizeof( struct V_110 ) ,
V_278 ) ;
if ( V_407 )
V_408 = F_118 ( V_407 ) ;
F_116 () ;
F_205 (net, dev) {
const struct V_295 * V_20 = V_29 -> V_157 ;
struct V_28 * V_390 = F_44 ( V_29 ) ;
if ( V_390 && V_390 -> V_157 -> V_409 ) {
if ( V_270 >= V_266 -> args [ 0 ] &&
V_390 -> V_157 -> V_409 (
V_48 , V_283 , V_178 , V_29 , V_408 ) < 0 )
break;
V_270 ++ ;
}
if ( V_20 -> V_409 ) {
if ( V_270 >= V_266 -> args [ 0 ] &&
V_20 -> V_409 ( V_48 , V_283 , V_178 , V_29 ,
V_408 ) < 0 )
break;
V_270 ++ ;
}
}
F_123 () ;
V_266 -> args [ 0 ] = V_270 ;
return V_48 -> V_286 ;
}
static inline T_4 F_210 ( void )
{
return F_94 ( sizeof( struct V_110 ) )
+ F_45 ( V_159 )
+ F_45 ( V_162 )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_9 ) )
+ F_45 ( sizeof( struct V_39 ) )
+ F_45 ( sizeof( T_8 ) )
+ F_45 ( sizeof( T_8 ) ) ;
}
static int F_211 ( struct V_28 * V_29 , T_8 V_75 )
{
struct V_27 * V_27 = F_137 ( V_29 ) ;
struct V_28 * V_390 = F_44 ( V_29 ) ;
struct V_47 * V_48 ;
int V_26 = - V_175 ;
V_48 = F_178 ( F_210 () , V_383 ) ;
if ( ! V_48 ) {
V_26 = - V_322 ;
goto V_310;
}
if ( ( ! V_75 || ( V_75 & V_410 ) ) &&
V_390 && V_390 -> V_157 -> V_409 ) {
V_26 = V_390 -> V_157 -> V_409 ( V_48 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_310;
}
if ( ( V_75 & V_405 ) &&
V_29 -> V_157 -> V_409 ) {
V_26 = V_29 -> V_157 -> V_409 ( V_48 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_310;
}
F_67 ( V_48 , V_27 , 0 , V_367 , NULL , V_383 ) ;
return 0 ;
V_310:
F_120 ( V_26 == - V_51 ) ;
F_179 ( V_48 ) ;
F_70 ( V_27 , V_367 , V_26 ) ;
return V_26 ;
}
static int F_212 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
struct V_110 * V_111 ;
struct V_28 * V_29 ;
struct V_39 * V_411 , * V_182 = NULL ;
int V_291 , V_26 = - V_175 ;
T_8 V_412 , V_75 = 0 ;
bool V_413 = false ;
if ( F_213 ( V_74 ) < sizeof( * V_111 ) )
return - V_290 ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_185 != V_373 )
return - V_414 ;
V_29 = F_136 ( V_27 , V_111 -> V_189 ) ;
if ( ! V_29 ) {
F_188 ( L_13 ) ;
return - V_318 ;
}
V_411 = F_209 ( V_74 , sizeof( struct V_110 ) , V_261 ) ;
if ( V_411 ) {
F_132 (attr, br_spec, rem) {
if ( F_133 ( V_182 ) == V_404 ) {
V_413 = true ;
V_75 = F_214 ( V_182 ) ;
break;
}
}
}
V_412 = V_75 ;
if ( ! V_75 || ( V_75 & V_410 ) ) {
struct V_28 * V_390 = F_44 ( V_29 ) ;
if ( ! V_390 || ! V_390 -> V_157 -> V_415 ) {
V_26 = - V_175 ;
goto V_63;
}
V_26 = V_390 -> V_157 -> V_415 ( V_29 , V_74 ) ;
if ( V_26 )
goto V_63;
V_75 &= ~ V_410 ;
}
if ( ( V_75 & V_405 ) ) {
if ( ! V_29 -> V_157 -> V_415 )
V_26 = - V_175 ;
else
V_26 = V_29 -> V_157 -> V_415 ( V_29 , V_74 ) ;
if ( ! V_26 )
V_75 &= ~ V_405 ;
}
if ( V_413 )
memcpy ( F_111 ( V_182 ) , & V_75 , sizeof( V_75 ) ) ;
if ( ! V_26 )
V_26 = F_211 ( V_29 , V_412 ) ;
V_63:
return V_26 ;
}
static int F_215 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
struct V_110 * V_111 ;
struct V_28 * V_29 ;
struct V_39 * V_411 , * V_182 = NULL ;
int V_291 , V_26 = - V_175 ;
T_8 V_412 , V_75 = 0 ;
bool V_413 = false ;
if ( F_213 ( V_74 ) < sizeof( * V_111 ) )
return - V_290 ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_185 != V_373 )
return - V_414 ;
V_29 = F_136 ( V_27 , V_111 -> V_189 ) ;
if ( ! V_29 ) {
F_188 ( L_13 ) ;
return - V_318 ;
}
V_411 = F_209 ( V_74 , sizeof( struct V_110 ) , V_261 ) ;
if ( V_411 ) {
F_132 (attr, br_spec, rem) {
if ( F_133 ( V_182 ) == V_404 ) {
V_413 = true ;
V_75 = F_214 ( V_182 ) ;
break;
}
}
}
V_412 = V_75 ;
if ( ! V_75 || ( V_75 & V_410 ) ) {
struct V_28 * V_390 = F_44 ( V_29 ) ;
if ( ! V_390 || ! V_390 -> V_157 -> V_416 ) {
V_26 = - V_175 ;
goto V_63;
}
V_26 = V_390 -> V_157 -> V_416 ( V_29 , V_74 ) ;
if ( V_26 )
goto V_63;
V_75 &= ~ V_410 ;
}
if ( ( V_75 & V_405 ) ) {
if ( ! V_29 -> V_157 -> V_416 )
V_26 = - V_175 ;
else
V_26 = V_29 -> V_157 -> V_416 ( V_29 , V_74 ) ;
if ( ! V_26 )
V_75 &= ~ V_405 ;
}
if ( V_413 )
memcpy ( F_111 ( V_182 ) , & V_75 , sizeof( V_75 ) ) ;
if ( ! V_26 )
V_26 = F_211 ( V_29 , V_412 ) ;
V_63:
return V_26 ;
}
static int F_216 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_267 ) ;
T_1 V_11 ;
int V_417 , V_19 ;
int V_44 ;
int type ;
int V_26 ;
type = V_74 -> V_363 ;
if ( type > V_418 )
return - V_175 ;
type -= V_4 ;
if ( F_213 ( V_74 ) < sizeof( struct V_419 ) )
return 0 ;
V_44 = ( (struct V_419 * ) F_103 ( V_74 ) ) -> V_420 ;
V_417 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_217 ( V_48 , V_312 ) )
return - V_313 ;
if ( V_19 == 2 && V_74 -> V_352 & V_421 ) {
struct V_68 * V_69 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_422 = 0 ;
V_13 = F_16 ( V_44 , type ) ;
if ( V_13 == NULL )
return - V_175 ;
V_14 = F_17 ( V_44 , type ) ;
if ( V_14 )
V_422 = V_14 ( V_48 , V_74 ) ;
F_3 () ;
V_69 = V_27 -> V_69 ;
{
struct V_423 V_424 = {
. V_425 = V_13 ,
. V_422 = V_422 ,
} ;
V_26 = F_218 ( V_69 , V_48 , V_74 , & V_424 ) ;
}
F_1 () ;
return V_26 ;
}
V_11 = F_15 ( V_44 , type ) ;
if ( V_11 == NULL )
return - V_175 ;
return V_11 ( V_48 , V_74 ) ;
}
static void F_219 ( struct V_47 * V_48 )
{
F_1 () ;
F_220 ( V_48 , & F_216 ) ;
F_5 () ;
}
static int F_221 ( struct V_426 * V_427 , unsigned long V_428 , void * V_429 )
{
struct V_28 * V_29 = F_222 ( V_429 ) ;
switch ( V_428 ) {
case V_430 :
case V_431 :
case V_432 :
case V_433 :
case V_434 :
case V_435 :
case V_436 :
case V_437 :
case V_438 :
case V_439 :
case V_440 :
case V_441 :
break;
default:
F_183 ( V_282 , V_29 , 0 , V_15 ) ;
break;
}
return V_442 ;
}
static int T_11 F_223 ( struct V_27 * V_27 )
{
struct V_68 * V_267 ;
struct V_443 V_444 = {
. V_445 = V_446 ,
. V_447 = F_219 ,
. V_448 = & V_1 ,
. V_75 = V_449 ,
} ;
V_267 = F_224 ( V_27 , V_450 , & V_444 ) ;
if ( ! V_267 )
return - V_322 ;
V_27 -> V_69 = V_267 ;
return 0 ;
}
static void T_12 F_225 ( struct V_27 * V_27 )
{
F_226 ( V_27 -> V_69 ) ;
V_27 -> V_69 = NULL ;
}
void T_13 F_227 ( void )
{
if ( F_228 ( & V_451 ) )
F_21 ( L_14 ) ;
F_229 ( & V_452 ) ;
F_20 ( V_12 , V_453 , F_177 ,
F_114 , F_180 ) ;
F_20 ( V_12 , V_454 , F_159 , NULL , NULL ) ;
F_20 ( V_12 , V_282 , F_171 , NULL , NULL ) ;
F_20 ( V_12 , V_455 , F_162 , NULL , NULL ) ;
F_20 ( V_12 , V_456 , NULL , F_182 , NULL ) ;
F_20 ( V_12 , V_457 , NULL , F_182 , NULL ) ;
F_20 ( V_458 , V_392 , F_194 , NULL , NULL ) ;
F_20 ( V_458 , V_394 , F_198 , NULL , NULL ) ;
F_20 ( V_458 , V_459 , NULL , F_204 , NULL ) ;
F_20 ( V_458 , V_453 , NULL , F_208 , NULL ) ;
F_20 ( V_458 , V_455 , F_215 , NULL , NULL ) ;
F_20 ( V_458 , V_454 , F_212 , NULL , NULL ) ;
}
