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
struct V_149 V_242 ;
struct V_243 V_244 ;
struct V_148 V_245 ;
struct V_246 V_247 ;
V_239 . V_248 = - 1 ;
memset ( V_239 . V_249 , 0 , sizeof( V_239 . V_249 ) ) ;
V_239 . V_250 = 0 ;
if ( V_29 -> V_157 -> V_235 ( V_29 , V_79 , & V_239 ) )
break;
V_240 . V_166 =
V_241 . V_166 =
V_242 . V_166 =
V_244 . V_166 =
V_245 . V_166 =
V_247 . V_166 = V_239 . V_166 ;
memcpy ( V_240 . V_249 , V_239 . V_249 , sizeof( V_239 . V_249 ) ) ;
V_241 . V_251 = V_239 . V_251 ;
V_241 . V_252 = V_239 . V_252 ;
V_244 . V_253 = V_239 . V_254 ;
V_242 . V_255 = V_239 . V_255 ;
V_242 . V_254 = V_239 . V_254 ;
V_245 . V_256 = V_239 . V_248 ;
V_247 . V_257 = V_239 . V_250 ;
V_166 = F_55 ( V_48 , V_258 ) ;
if ( ! V_166 ) {
F_57 ( V_48 , V_236 ) ;
goto V_83;
}
if ( F_79 ( V_48 , V_259 , sizeof( V_240 ) , & V_240 ) ||
F_79 ( V_48 , V_260 , sizeof( V_241 ) , & V_241 ) ||
F_79 ( V_48 , V_261 , sizeof( V_242 ) ,
& V_242 ) ||
F_79 ( V_48 , V_262 , sizeof( V_244 ) ,
& V_244 ) ||
F_79 ( V_48 , V_263 , sizeof( V_245 ) ,
& V_245 ) ||
F_79 ( V_48 , V_264 , sizeof( V_247 ) ,
& V_247 ) )
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
if ( ! ( V_183 = F_55 ( V_48 , V_265 ) ) )
goto V_83;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_45 -> V_266 ) {
struct V_39 * V_267 ;
int V_26 ;
if ( ! ( V_267 = F_55 ( V_48 , V_45 -> V_44 ) ) )
goto V_83;
V_26 = V_45 -> V_266 ( V_48 , V_29 ) ;
if ( V_26 == - V_268 )
F_57 ( V_48 , V_267 ) ;
else if ( V_26 < 0 )
goto V_83;
F_56 ( V_48 , V_267 ) ;
}
}
F_56 ( V_48 , V_183 ) ;
return F_112 ( V_48 , V_74 ) ;
V_83:
F_113 ( V_48 , V_74 ) ;
return - V_51 ;
}
static int F_114 ( struct V_47 * V_48 , struct V_269 * V_270 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
int V_272 , V_273 ;
int V_274 = 0 , V_275 ;
struct V_28 * V_29 ;
struct V_276 * V_277 ;
struct V_39 * V_278 [ V_279 + 1 ] ;
T_5 V_142 = 0 ;
int V_26 ;
int V_280 ;
V_273 = V_270 -> args [ 0 ] ;
V_275 = V_270 -> args [ 1 ] ;
F_116 () ;
V_270 -> V_178 = V_27 -> V_281 ;
V_280 = F_117 ( V_270 -> V_74 ) < sizeof( struct V_110 ) ?
sizeof( struct V_282 ) : sizeof( struct V_110 ) ;
if ( F_118 ( V_270 -> V_74 , V_280 , V_278 , V_279 , V_283 ) >= 0 ) {
if ( V_278 [ V_284 ] )
V_142 = F_119 ( V_278 [ V_284 ] ) ;
}
for ( V_272 = V_273 ; V_272 < V_285 ; V_272 ++ , V_275 = 0 ) {
V_274 = 0 ;
V_277 = & V_27 -> V_286 [ V_272 ] ;
F_120 (dev, head, index_hlist) {
if ( V_274 < V_275 )
goto V_287;
V_26 = F_100 ( V_48 , V_29 , V_288 ,
F_61 ( V_270 -> V_48 ) . V_289 ,
V_270 -> V_74 -> V_290 , 0 ,
V_291 ,
V_142 ) ;
F_121 ( ( V_26 == - V_51 ) && ( V_48 -> V_292 == 0 ) ) ;
if ( V_26 <= 0 )
goto V_63;
F_122 ( V_270 , F_123 ( V_48 ) ) ;
V_287:
V_274 ++ ;
}
}
V_63:
F_124 () ;
V_270 -> args [ 1 ] = V_274 ;
V_270 -> args [ 0 ] = V_272 ;
return V_48 -> V_292 ;
}
int F_125 ( struct V_39 * * V_278 , const struct V_39 * V_277 , int V_292 )
{
return F_126 ( V_278 , V_279 , V_277 , V_292 , V_283 ) ;
}
struct V_27 * F_127 ( struct V_27 * V_293 , struct V_39 * V_278 [] )
{
struct V_27 * V_27 ;
if ( V_278 [ V_294 ] )
V_27 = F_128 ( F_119 ( V_278 [ V_294 ] ) ) ;
else if ( V_278 [ V_295 ] )
V_27 = F_129 ( F_119 ( V_278 [ V_295 ] ) ) ;
else
V_27 = F_130 ( V_293 ) ;
return V_27 ;
}
static int F_131 ( struct V_28 * V_29 , struct V_39 * V_278 [] )
{
if ( V_29 ) {
if ( V_278 [ V_228 ] &&
F_132 ( V_278 [ V_228 ] ) < V_29 -> V_227 )
return - V_296 ;
if ( V_278 [ V_230 ] &&
F_132 ( V_278 [ V_230 ] ) < V_29 -> V_227 )
return - V_296 ;
}
if ( V_278 [ V_265 ] ) {
struct V_39 * V_267 ;
int V_297 , V_26 ;
F_133 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_43 * V_45 ;
if ( ! ( V_45 = F_47 ( F_134 ( V_267 ) ) ) )
return - V_298 ;
if ( ! V_45 -> V_299 )
return - V_175 ;
if ( V_45 -> V_300 ) {
V_26 = V_45 -> V_300 ( V_29 , V_267 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
}
return 0 ;
}
static int F_135 ( struct V_28 * V_29 , struct V_39 * V_182 )
{
int V_297 , V_26 = - V_296 ;
struct V_39 * V_166 ;
const struct V_301 * V_20 = V_29 -> V_157 ;
F_133 (vf, attr, rem) {
switch ( F_134 ( V_166 ) ) {
case V_259 : {
struct V_146 * V_302 ;
V_302 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_303 )
V_26 = V_20 -> V_303 ( V_29 , V_302 -> V_166 ,
V_302 -> V_249 ) ;
break;
}
case V_260 : {
struct V_147 * V_304 ;
V_304 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_305 )
V_26 = V_20 -> V_305 ( V_29 , V_304 -> V_166 ,
V_304 -> V_251 ,
V_304 -> V_252 ) ;
break;
}
case V_262 : {
struct V_243 * V_306 ;
struct V_238 V_307 ;
V_306 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_235 )
V_26 = V_20 -> V_235 ( V_29 , V_306 -> V_166 ,
& V_307 ) ;
if ( V_26 )
break;
V_26 = - V_175 ;
if ( V_20 -> V_308 )
V_26 = V_20 -> V_308 ( V_29 , V_306 -> V_166 ,
V_307 . V_255 ,
V_306 -> V_253 ) ;
break;
}
case V_261 : {
struct V_149 * V_306 ;
V_306 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_308 )
V_26 = V_20 -> V_308 ( V_29 , V_306 -> V_166 ,
V_306 -> V_255 ,
V_306 -> V_254 ) ;
break;
}
case V_263 : {
struct V_148 * V_309 ;
V_309 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_310 )
V_26 = V_20 -> V_310 ( V_29 , V_309 -> V_166 ,
V_309 -> V_256 ) ;
break;
}
case V_264 : {
struct V_246 * V_311 ;
V_311 = F_111 ( V_166 ) ;
V_26 = - V_175 ;
if ( V_20 -> V_312 )
V_26 = V_20 -> V_312 ( V_29 , V_311 -> V_166 ,
V_311 -> V_257 ) ;
break;
}
default:
V_26 = - V_296 ;
break;
}
if ( V_26 )
break;
}
return V_26 ;
}
static int F_136 ( struct V_28 * V_29 , int V_190 )
{
struct V_28 * V_184 = F_44 ( V_29 ) ;
const struct V_301 * V_20 ;
int V_26 ;
if ( V_184 ) {
if ( V_184 -> V_190 == V_190 )
return 0 ;
V_20 = V_184 -> V_157 ;
if ( V_20 -> V_313 ) {
V_26 = V_20 -> V_313 ( V_184 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_175 ;
}
}
if ( V_190 ) {
V_184 = F_137 ( F_138 ( V_29 ) , V_190 ) ;
if ( ! V_184 )
return - V_296 ;
V_20 = V_184 -> V_157 ;
if ( V_20 -> V_314 ) {
V_26 = V_20 -> V_314 ( V_184 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_175 ;
}
}
return 0 ;
}
static int F_139 ( const struct V_47 * V_48 ,
struct V_28 * V_29 , struct V_110 * V_111 ,
struct V_39 * * V_278 , char * V_315 , int V_316 )
{
const struct V_301 * V_20 = V_29 -> V_157 ;
int V_26 ;
if ( V_278 [ V_294 ] || V_278 [ V_295 ] ) {
struct V_27 * V_27 = F_127 ( F_138 ( V_29 ) , V_278 ) ;
if ( F_140 ( V_27 ) ) {
V_26 = F_141 ( V_27 ) ;
goto V_317;
}
if ( ! F_142 ( V_48 , V_27 -> V_318 , V_319 ) ) {
V_26 = - V_320 ;
goto V_317;
}
V_26 = F_143 ( V_29 , V_27 , V_315 ) ;
F_144 ( V_27 ) ;
if ( V_26 )
goto V_317;
V_316 = 1 ;
}
if ( V_278 [ V_226 ] ) {
struct V_161 * V_321 ;
struct V_322 V_323 ;
if ( ! V_20 -> V_324 ) {
V_26 = - V_175 ;
goto V_317;
}
if ( ! F_145 ( V_29 ) ) {
V_26 = - V_325 ;
goto V_317;
}
V_321 = F_111 ( V_278 [ V_226 ] ) ;
V_323 . V_219 = ( unsigned long ) V_321 -> V_219 ;
V_323 . V_220 = ( unsigned long ) V_321 -> V_220 ;
V_323 . V_221 = ( unsigned short ) V_321 -> V_221 ;
V_323 . V_222 = ( unsigned char ) V_321 -> V_222 ;
V_323 . V_223 = ( unsigned char ) V_321 -> V_223 ;
V_323 . V_224 = ( unsigned char ) V_321 -> V_224 ;
V_26 = V_20 -> V_324 ( V_29 , & V_323 ) ;
if ( V_26 < 0 )
goto V_317;
V_316 = 1 ;
}
if ( V_278 [ V_228 ] ) {
struct V_326 * V_327 ;
int V_292 ;
V_292 = sizeof( V_328 ) + V_29 -> V_227 ;
V_327 = F_146 ( V_292 , V_15 ) ;
if ( ! V_327 ) {
V_26 = - V_329 ;
goto V_317;
}
V_327 -> V_330 = V_29 -> type ;
memcpy ( V_327 -> V_331 , F_111 ( V_278 [ V_228 ] ) ,
V_29 -> V_227 ) ;
V_26 = F_147 ( V_29 , V_327 ) ;
F_24 ( V_327 ) ;
if ( V_26 )
goto V_317;
V_316 = 1 ;
}
if ( V_278 [ V_199 ] ) {
V_26 = F_148 ( V_29 , F_119 ( V_278 [ V_199 ] ) ) ;
if ( V_26 < 0 )
goto V_317;
V_316 = 1 ;
}
if ( V_278 [ V_201 ] ) {
F_149 ( V_29 , F_119 ( V_278 [ V_201 ] ) ) ;
V_316 = 1 ;
}
if ( V_111 -> V_189 > 0 && V_315 [ 0 ] ) {
V_26 = F_150 ( V_29 , V_315 ) ;
if ( V_26 < 0 )
goto V_317;
V_316 = 1 ;
}
if ( V_278 [ V_215 ] ) {
V_26 = F_151 ( V_29 , F_111 ( V_278 [ V_215 ] ) ,
F_132 ( V_278 [ V_215 ] ) ) ;
if ( V_26 < 0 )
goto V_317;
V_316 = 1 ;
}
if ( V_278 [ V_230 ] ) {
F_152 ( V_29 -> V_231 , V_278 [ V_230 ] , V_29 -> V_227 ) ;
F_153 ( V_332 , V_29 ) ;
}
if ( V_111 -> V_112 || V_111 -> V_113 ) {
V_26 = F_154 ( V_29 , F_86 ( V_29 , V_111 ) ) ;
if ( V_26 < 0 )
goto V_317;
}
if ( V_278 [ V_210 ] ) {
V_26 = F_136 ( V_29 , F_119 ( V_278 [ V_210 ] ) ) ;
if ( V_26 )
goto V_317;
V_316 = 1 ;
}
if ( V_278 [ V_211 ] ) {
V_26 = F_155 ( V_29 , F_156 ( V_278 [ V_211 ] ) ) ;
if ( V_26 )
goto V_317;
V_316 = 1 ;
}
if ( V_278 [ V_193 ] )
V_29 -> V_194 = F_119 ( V_278 [ V_193 ] ) ;
if ( V_278 [ V_195 ] )
F_80 ( V_29 , F_156 ( V_278 [ V_195 ] ) ) ;
if ( V_278 [ V_197 ] ) {
F_82 ( & V_106 ) ;
V_29 -> V_198 = F_156 ( V_278 [ V_197 ] ) ;
F_83 ( & V_106 ) ;
}
if ( V_278 [ V_237 ] ) {
struct V_39 * V_182 ;
int V_297 ;
F_133 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_134 ( V_182 ) != V_258 ) {
V_26 = - V_296 ;
goto V_317;
}
V_26 = F_135 ( V_29 , V_182 ) ;
if ( V_26 < 0 )
goto V_317;
V_316 = 1 ;
}
}
V_26 = 0 ;
if ( V_278 [ V_167 ] ) {
struct V_39 * V_224 [ V_333 + 1 ] ;
struct V_39 * V_182 ;
int V_166 ;
int V_297 ;
V_26 = - V_175 ;
if ( ! V_20 -> V_334 )
goto V_317;
F_133 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_134 ( V_182 ) != V_168 )
continue;
V_26 = F_157 ( V_224 , V_333 ,
V_182 , V_335 ) ;
if ( V_26 < 0 )
goto V_317;
if ( ! V_224 [ V_169 ] ) {
V_26 = - V_175 ;
goto V_317;
}
V_166 = F_119 ( V_224 [ V_169 ] ) ;
V_26 = V_20 -> V_334 ( V_29 , V_166 , V_224 ) ;
if ( V_26 < 0 )
goto V_317;
V_316 = 1 ;
}
}
V_26 = 0 ;
if ( V_278 [ V_171 ] ) {
struct V_39 * V_224 [ V_333 + 1 ] ;
V_26 = F_157 ( V_224 , V_333 ,
V_278 [ V_171 ] , V_335 ) ;
if ( V_26 < 0 )
goto V_317;
V_26 = - V_175 ;
if ( V_20 -> V_334 )
V_26 = V_20 -> V_334 ( V_29 , V_172 , V_224 ) ;
if ( V_26 < 0 )
goto V_317;
V_316 = 1 ;
}
if ( V_278 [ V_265 ] ) {
struct V_39 * V_267 ;
int V_297 ;
F_133 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_43 * V_45 ;
if ( ! ( V_45 = F_47 ( F_134 ( V_267 ) ) ) )
F_158 () ;
V_26 = V_45 -> V_299 ( V_29 , V_267 ) ;
if ( V_26 < 0 )
goto V_317;
V_316 = 1 ;
}
}
V_26 = 0 ;
V_317:
if ( V_26 < 0 && V_316 )
F_159 ( L_3 ,
V_29 -> V_192 ) ;
return V_26 ;
}
static int F_160 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
struct V_110 * V_111 ;
struct V_28 * V_29 ;
int V_26 ;
struct V_39 * V_278 [ V_279 + 1 ] ;
char V_315 [ V_159 ] ;
V_26 = F_118 ( V_74 , sizeof( * V_111 ) , V_278 , V_279 , V_283 ) ;
if ( V_26 < 0 )
goto V_317;
if ( V_278 [ V_191 ] )
F_161 ( V_315 , V_278 [ V_191 ] , V_159 ) ;
else
V_315 [ 0 ] = '\0' ;
V_26 = - V_296 ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_189 > 0 )
V_29 = F_137 ( V_27 , V_111 -> V_189 ) ;
else if ( V_278 [ V_191 ] )
V_29 = F_162 ( V_27 , V_315 ) ;
else
goto V_317;
if ( V_29 == NULL ) {
V_26 = - V_325 ;
goto V_317;
}
V_26 = F_131 ( V_29 , V_278 ) ;
if ( V_26 < 0 )
goto V_317;
V_26 = F_139 ( V_48 , V_29 , V_111 , V_278 , V_315 , 0 ) ;
V_317:
return V_26 ;
}
static int F_163 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_110 * V_111 ;
char V_315 [ V_159 ] ;
struct V_39 * V_278 [ V_279 + 1 ] ;
int V_26 ;
F_31 ( V_30 ) ;
V_26 = F_118 ( V_74 , sizeof( * V_111 ) , V_278 , V_279 , V_283 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_278 [ V_191 ] )
F_161 ( V_315 , V_278 [ V_191 ] , V_159 ) ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_189 > 0 )
V_29 = F_137 ( V_27 , V_111 -> V_189 ) ;
else if ( V_278 [ V_191 ] )
V_29 = F_162 ( V_27 , V_315 ) ;
else
return - V_296 ;
if ( ! V_29 )
return - V_325 ;
V_20 = V_29 -> V_18 ;
if ( ! V_20 )
return - V_175 ;
V_20 -> V_22 ( V_29 , & V_30 ) ;
F_33 ( & V_30 ) ;
return 0 ;
}
int F_164 ( struct V_28 * V_29 , const struct V_110 * V_111 )
{
unsigned int V_336 ;
int V_26 ;
V_336 = V_29 -> V_75 ;
if ( V_111 && ( V_111 -> V_112 || V_111 -> V_113 ) ) {
V_26 = F_165 ( V_29 , F_86 ( V_29 , V_111 ) ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_29 -> V_337 = V_338 ;
F_166 ( V_29 , V_336 , ~ 0U ) ;
return 0 ;
}
struct V_28 * F_167 ( struct V_27 * V_27 ,
char * V_315 , const struct V_18 * V_20 , struct V_39 * V_278 [] )
{
int V_26 ;
struct V_28 * V_29 ;
unsigned int V_205 = 1 ;
unsigned int V_207 = 1 ;
if ( V_278 [ V_204 ] )
V_205 = F_119 ( V_278 [ V_204 ] ) ;
else if ( V_20 -> V_339 )
V_205 = V_20 -> V_339 () ;
if ( V_278 [ V_206 ] )
V_207 = F_119 ( V_278 [ V_206 ] ) ;
else if ( V_20 -> V_340 )
V_207 = V_20 -> V_340 () ;
V_26 = - V_329 ;
V_29 = F_168 ( V_20 -> V_341 , V_315 , V_20 -> V_342 ,
V_205 , V_207 ) ;
if ( ! V_29 )
goto V_26;
F_169 ( V_29 , V_27 ) ;
V_29 -> V_18 = V_20 ;
V_29 -> V_337 = V_343 ;
if ( V_278 [ V_199 ] )
V_29 -> V_200 = F_119 ( V_278 [ V_199 ] ) ;
if ( V_278 [ V_228 ] ) {
memcpy ( V_29 -> V_229 , F_111 ( V_278 [ V_228 ] ) ,
F_132 ( V_278 [ V_228 ] ) ) ;
V_29 -> V_344 = V_345 ;
}
if ( V_278 [ V_230 ] )
memcpy ( V_29 -> V_231 , F_111 ( V_278 [ V_230 ] ) ,
F_132 ( V_278 [ V_230 ] ) ) ;
if ( V_278 [ V_193 ] )
V_29 -> V_194 = F_119 ( V_278 [ V_193 ] ) ;
if ( V_278 [ V_195 ] )
F_80 ( V_29 , F_156 ( V_278 [ V_195 ] ) ) ;
if ( V_278 [ V_197 ] )
V_29 -> V_198 = F_156 ( V_278 [ V_197 ] ) ;
if ( V_278 [ V_201 ] )
F_149 ( V_29 , F_119 ( V_278 [ V_201 ] ) ) ;
return V_29 ;
V_26:
return F_170 ( V_26 ) ;
}
static int F_171 ( const struct V_47 * V_48 ,
struct V_27 * V_27 , int V_66 ,
struct V_110 * V_111 ,
struct V_39 * * V_278 )
{
struct V_28 * V_29 ;
int V_26 ;
F_32 (net, dev) {
if ( V_29 -> V_66 == V_66 ) {
V_26 = F_139 ( V_48 , V_29 , V_111 , V_278 , NULL , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
return 0 ;
}
static int F_172 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_346 = NULL ;
struct V_28 * V_29 ;
struct V_28 * V_37 = NULL ;
struct V_110 * V_111 ;
char V_19 [ V_347 ] ;
char V_315 [ V_159 ] ;
struct V_39 * V_278 [ V_279 + 1 ] ;
struct V_39 * V_61 [ V_348 + 1 ] ;
int V_26 ;
#ifdef F_173
V_349:
#endif
V_26 = F_118 ( V_74 , sizeof( * V_111 ) , V_278 , V_279 , V_283 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_278 [ V_191 ] )
F_161 ( V_315 , V_278 [ V_191 ] , V_159 ) ;
else
V_315 [ 0 ] = '\0' ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_189 > 0 )
V_29 = F_137 ( V_27 , V_111 -> V_189 ) ;
else {
if ( V_315 [ 0 ] )
V_29 = F_162 ( V_27 , V_315 ) ;
else
V_29 = NULL ;
}
if ( V_29 ) {
V_37 = F_44 ( V_29 ) ;
if ( V_37 )
V_346 = V_37 -> V_18 ;
}
V_26 = F_131 ( V_29 , V_278 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_278 [ V_62 ] ) {
V_26 = F_157 ( V_61 , V_348 ,
V_278 [ V_62 ] , V_350 ) ;
if ( V_26 < 0 )
return V_26 ;
} else
memset ( V_61 , 0 , sizeof( V_61 ) ) ;
if ( V_61 [ V_56 ] ) {
F_161 ( V_19 , V_61 [ V_56 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_39 * V_182 [ V_20 ? V_20 -> V_351 + 1 : 0 ] ;
struct V_39 * V_352 [ V_346 ? V_346 -> V_353 + 1 : 0 ] ;
struct V_39 * * V_55 = NULL ;
struct V_39 * * V_49 = NULL ;
struct V_27 * V_354 ;
if ( V_20 ) {
if ( V_20 -> V_351 && V_61 [ V_59 ] ) {
V_26 = F_157 ( V_182 , V_20 -> V_351 ,
V_61 [ V_59 ] ,
V_20 -> V_355 ) ;
if ( V_26 < 0 )
return V_26 ;
V_55 = V_182 ;
}
if ( V_20 -> V_356 ) {
V_26 = V_20 -> V_356 ( V_278 , V_55 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_346 ) {
if ( V_346 -> V_353 &&
V_61 [ V_53 ] ) {
V_26 = F_157 ( V_352 ,
V_346 -> V_353 ,
V_61 [ V_53 ] ,
V_346 -> V_357 ) ;
if ( V_26 < 0 )
return V_26 ;
V_49 = V_352 ;
}
if ( V_346 -> V_358 ) {
V_26 = V_346 -> V_358 ( V_278 , V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_29 ) {
int V_316 = 0 ;
if ( V_74 -> V_359 & V_360 )
return - V_21 ;
if ( V_74 -> V_359 & V_361 )
return - V_175 ;
if ( V_61 [ V_59 ] ) {
if ( ! V_20 || V_20 != V_29 -> V_18 ||
! V_20 -> V_362 )
return - V_175 ;
V_26 = V_20 -> V_362 ( V_29 , V_278 , V_55 ) ;
if ( V_26 < 0 )
return V_26 ;
V_316 = 1 ;
}
if ( V_61 [ V_53 ] ) {
if ( ! V_346 || ! V_346 -> V_363 )
return - V_175 ;
V_26 = V_346 -> V_363 ( V_37 , V_29 ,
V_278 , V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
V_316 = 1 ;
}
return F_139 ( V_48 , V_29 , V_111 , V_278 , V_315 , V_316 ) ;
}
if ( ! ( V_74 -> V_359 & V_364 ) ) {
if ( V_111 -> V_189 == 0 && V_278 [ V_201 ] )
return F_171 ( V_48 , V_27 ,
F_119 ( V_278 [ V_201 ] ) ,
V_111 , V_278 ) ;
return - V_325 ;
}
if ( V_278 [ V_226 ] || V_278 [ V_210 ] || V_278 [ V_365 ] )
return - V_175 ;
if ( ! V_20 ) {
#ifdef F_173
if ( V_19 [ 0 ] ) {
F_3 () ;
F_174 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_349;
}
#endif
return - V_175 ;
}
if ( ! V_315 [ 0 ] )
snprintf ( V_315 , V_159 , L_5 , V_20 -> V_19 ) ;
V_354 = F_127 ( V_27 , V_278 ) ;
if ( F_140 ( V_354 ) )
return F_141 ( V_354 ) ;
V_29 = F_167 ( V_354 , V_315 , V_20 , V_278 ) ;
if ( F_140 ( V_29 ) ) {
V_26 = F_141 ( V_29 ) ;
goto V_63;
}
V_29 -> V_190 = V_111 -> V_189 ;
if ( V_20 -> V_366 ) {
V_26 = V_20 -> V_366 ( V_27 , V_29 , V_278 , V_55 ) ;
if ( V_26 < 0 ) {
if ( V_29 -> V_367 == V_368 )
F_175 ( V_29 ) ;
goto V_63;
}
} else {
V_26 = F_176 ( V_29 ) ;
if ( V_26 < 0 ) {
F_175 ( V_29 ) ;
goto V_63;
}
}
V_26 = F_164 ( V_29 , V_111 ) ;
if ( V_26 < 0 )
F_177 ( V_29 ) ;
V_63:
F_144 ( V_354 ) ;
return V_26 ;
}
}
static int F_178 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
struct V_110 * V_111 ;
char V_315 [ V_159 ] ;
struct V_39 * V_278 [ V_279 + 1 ] ;
struct V_28 * V_29 = NULL ;
struct V_47 * V_369 ;
int V_26 ;
T_5 V_142 = 0 ;
V_26 = F_118 ( V_74 , sizeof( * V_111 ) , V_278 , V_279 , V_283 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_278 [ V_191 ] )
F_161 ( V_315 , V_278 [ V_191 ] , V_159 ) ;
if ( V_278 [ V_284 ] )
V_142 = F_119 ( V_278 [ V_284 ] ) ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_189 > 0 )
V_29 = F_137 ( V_27 , V_111 -> V_189 ) ;
else if ( V_278 [ V_191 ] )
V_29 = F_162 ( V_27 , V_315 ) ;
else
return - V_296 ;
if ( V_29 == NULL )
return - V_325 ;
V_369 = F_179 ( F_93 ( V_29 , V_142 ) , V_15 ) ;
if ( V_369 == NULL )
return - V_16 ;
V_26 = F_100 ( V_369 , V_29 , V_288 , F_61 ( V_48 ) . V_289 ,
V_74 -> V_290 , 0 , 0 , V_142 ) ;
if ( V_26 < 0 ) {
F_121 ( V_26 == - V_51 ) ;
F_180 ( V_369 ) ;
} else
V_26 = F_65 ( V_369 , V_27 , F_61 ( V_48 ) . V_289 ) ;
return V_26 ;
}
static T_8 F_181 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
struct V_28 * V_29 ;
struct V_39 * V_278 [ V_279 + 1 ] ;
T_5 V_142 = 0 ;
T_8 V_370 = 0 ;
int V_280 ;
V_280 = F_117 ( V_74 ) < sizeof( struct V_110 ) ?
sizeof( struct V_282 ) : sizeof( struct V_110 ) ;
if ( F_118 ( V_74 , V_280 , V_278 , V_279 , V_283 ) >= 0 ) {
if ( V_278 [ V_284 ] )
V_142 = F_119 ( V_278 [ V_284 ] ) ;
}
if ( ! V_142 )
return V_371 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_370 = F_182 ( T_8 , V_370 ,
F_93 ( V_29 ,
V_142 ) ) ;
}
return V_370 ;
}
static int F_183 ( struct V_47 * V_48 , struct V_269 * V_270 )
{
int V_274 ;
int V_275 = V_270 -> V_44 ;
if ( V_275 == 0 )
V_275 = 1 ;
for ( V_274 = 1 ; V_274 <= V_9 ; V_274 ++ ) {
int type = V_270 -> V_74 -> V_372 - V_4 ;
if ( V_274 < V_275 || V_274 == V_373 )
continue;
if ( V_10 [ V_274 ] == NULL ||
V_10 [ V_274 ] [ type ] . V_13 == NULL )
continue;
if ( V_274 > V_275 ) {
memset ( & V_270 -> args [ 0 ] , 0 , sizeof( V_270 -> args ) ) ;
V_270 -> V_374 = 0 ;
V_270 -> V_178 = 0 ;
}
if ( V_10 [ V_274 ] [ type ] . V_13 ( V_48 , V_270 ) )
break;
}
V_270 -> V_44 = V_274 ;
return V_48 -> V_292 ;
}
void F_184 ( int type , struct V_28 * V_29 , unsigned int V_179 ,
T_6 V_75 )
{
struct V_27 * V_27 = F_138 ( V_29 ) ;
struct V_47 * V_48 ;
int V_26 = - V_16 ;
T_4 V_375 ;
V_48 = F_179 ( ( V_375 = F_93 ( V_29 , 0 ) ) , V_75 ) ;
if ( V_48 == NULL )
goto V_317;
V_26 = F_100 ( V_48 , V_29 , type , 0 , 0 , V_179 , 0 , 0 ) ;
if ( V_26 < 0 ) {
F_121 ( V_26 == - V_51 ) ;
F_180 ( V_48 ) ;
goto V_317;
}
F_67 ( V_48 , V_27 , 0 , V_376 , NULL , V_75 ) ;
return;
V_317:
if ( V_26 < 0 )
F_70 ( V_27 , V_376 , V_26 ) ;
}
static int F_185 ( struct V_47 * V_48 ,
struct V_28 * V_29 ,
T_9 * V_377 , T_5 V_65 , T_5 V_178 ,
int type , unsigned int V_75 ,
int V_378 )
{
struct V_73 * V_74 ;
struct V_379 * V_380 ;
V_74 = F_102 ( V_48 , V_65 , V_178 , type , sizeof( * V_380 ) , V_378 ) ;
if ( ! V_74 )
return - V_51 ;
V_380 = F_103 ( V_74 ) ;
V_380 -> V_381 = V_382 ;
V_380 -> V_383 = 0 ;
V_380 -> V_384 = 0 ;
V_380 -> V_385 = V_75 ;
V_380 -> V_386 = 0 ;
V_380 -> V_387 = V_29 -> V_190 ;
V_380 -> V_388 = V_389 ;
if ( F_79 ( V_48 , V_390 , V_391 , V_377 ) )
goto V_83;
return F_112 ( V_48 , V_74 ) ;
V_83:
F_113 ( V_48 , V_74 ) ;
return - V_51 ;
}
static inline T_4 F_186 ( void )
{
return F_94 ( sizeof( struct V_379 ) ) + F_45 ( V_391 ) ;
}
static void F_187 ( struct V_28 * V_29 , T_9 * V_377 , int type )
{
struct V_27 * V_27 = F_138 ( V_29 ) ;
struct V_47 * V_48 ;
int V_26 = - V_16 ;
V_48 = F_179 ( F_186 () , V_392 ) ;
if ( ! V_48 )
goto V_317;
V_26 = F_185 ( V_48 , V_29 , V_377 , 0 , 0 , type , V_393 , 0 ) ;
if ( V_26 < 0 ) {
F_180 ( V_48 ) ;
goto V_317;
}
F_67 ( V_48 , V_27 , 0 , V_394 , NULL , V_392 ) ;
return;
V_317:
F_70 ( V_27 , V_394 , V_26 ) ;
}
int F_188 ( struct V_379 * V_380 ,
struct V_39 * V_278 [] ,
struct V_28 * V_29 ,
const unsigned char * V_377 ,
T_8 V_75 )
{
int V_26 = - V_296 ;
if ( V_380 -> V_388 && ! ( V_380 -> V_388 & V_389 ) ) {
F_189 ( L_6 , V_29 -> V_192 ) ;
return V_26 ;
}
if ( F_190 ( V_377 ) || F_191 ( V_377 ) )
V_26 = F_192 ( V_29 , V_377 ) ;
else if ( F_193 ( V_377 ) )
V_26 = F_194 ( V_29 , V_377 ) ;
if ( V_26 == - V_21 && ! ( V_75 & V_360 ) )
V_26 = 0 ;
return V_26 ;
}
static int F_195 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
struct V_379 * V_380 ;
struct V_39 * V_278 [ V_395 + 1 ] ;
struct V_28 * V_29 ;
T_9 * V_377 ;
int V_26 ;
V_26 = F_118 ( V_74 , sizeof( * V_380 ) , V_278 , V_395 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_380 = F_103 ( V_74 ) ;
if ( V_380 -> V_387 == 0 ) {
F_189 ( L_7 ) ;
return - V_296 ;
}
V_29 = F_137 ( V_27 , V_380 -> V_387 ) ;
if ( V_29 == NULL ) {
F_189 ( L_8 ) ;
return - V_325 ;
}
if ( ! V_278 [ V_390 ] || F_132 ( V_278 [ V_390 ] ) != V_391 ) {
F_189 ( L_9 ) ;
return - V_296 ;
}
V_377 = F_111 ( V_278 [ V_390 ] ) ;
V_26 = - V_175 ;
if ( ( ! V_380 -> V_385 || V_380 -> V_385 & V_396 ) &&
( V_29 -> V_397 & V_398 ) ) {
struct V_28 * V_399 = F_44 ( V_29 ) ;
const struct V_301 * V_20 = V_399 -> V_157 ;
V_26 = V_20 -> V_400 ( V_380 , V_278 , V_29 , V_377 , V_74 -> V_359 ) ;
if ( V_26 )
goto V_63;
else
V_380 -> V_385 &= ~ V_396 ;
}
if ( ( V_380 -> V_385 & V_393 ) ) {
if ( V_29 -> V_157 -> V_400 )
V_26 = V_29 -> V_157 -> V_400 ( V_380 , V_278 , V_29 , V_377 ,
V_74 -> V_359 ) ;
else
V_26 = F_188 ( V_380 , V_278 , V_29 , V_377 ,
V_74 -> V_359 ) ;
if ( ! V_26 ) {
F_187 ( V_29 , V_377 , V_401 ) ;
V_380 -> V_385 &= ~ V_393 ;
}
}
V_63:
return V_26 ;
}
int F_196 ( struct V_379 * V_380 ,
struct V_39 * V_278 [] ,
struct V_28 * V_29 ,
const unsigned char * V_377 )
{
int V_26 = - V_175 ;
if ( ! ( V_380 -> V_388 & V_389 ) ) {
F_189 ( L_6 , V_29 -> V_192 ) ;
return - V_296 ;
}
if ( F_190 ( V_377 ) || F_191 ( V_377 ) )
V_26 = F_197 ( V_29 , V_377 ) ;
else if ( F_193 ( V_377 ) )
V_26 = F_198 ( V_29 , V_377 ) ;
else
V_26 = - V_296 ;
return V_26 ;
}
static int F_199 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
struct V_379 * V_380 ;
struct V_39 * V_278 [ V_395 + 1 ] ;
struct V_28 * V_29 ;
int V_26 = - V_296 ;
T_10 * V_377 ;
if ( ! F_200 ( V_48 , V_319 ) )
return - V_320 ;
V_26 = F_118 ( V_74 , sizeof( * V_380 ) , V_278 , V_395 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_380 = F_103 ( V_74 ) ;
if ( V_380 -> V_387 == 0 ) {
F_189 ( L_10 ) ;
return - V_296 ;
}
V_29 = F_137 ( V_27 , V_380 -> V_387 ) ;
if ( V_29 == NULL ) {
F_189 ( L_11 ) ;
return - V_325 ;
}
if ( ! V_278 [ V_390 ] || F_132 ( V_278 [ V_390 ] ) != V_391 ) {
F_189 ( L_12 ) ;
return - V_296 ;
}
V_377 = F_111 ( V_278 [ V_390 ] ) ;
V_26 = - V_175 ;
if ( ( ! V_380 -> V_385 || V_380 -> V_385 & V_396 ) &&
( V_29 -> V_397 & V_398 ) ) {
struct V_28 * V_399 = F_44 ( V_29 ) ;
const struct V_301 * V_20 = V_399 -> V_157 ;
if ( V_20 -> V_402 )
V_26 = V_20 -> V_402 ( V_380 , V_278 , V_29 , V_377 ) ;
if ( V_26 )
goto V_63;
else
V_380 -> V_385 &= ~ V_396 ;
}
if ( V_380 -> V_385 & V_393 ) {
if ( V_29 -> V_157 -> V_402 )
V_26 = V_29 -> V_157 -> V_402 ( V_380 , V_278 , V_29 , V_377 ) ;
else
V_26 = F_196 ( V_380 , V_278 , V_29 , V_377 ) ;
if ( ! V_26 ) {
F_187 ( V_29 , V_377 , V_403 ) ;
V_380 -> V_385 &= ~ V_393 ;
}
}
V_63:
return V_26 ;
}
static int F_201 ( struct V_47 * V_48 ,
struct V_269 * V_270 ,
struct V_28 * V_29 ,
int * V_274 ,
struct V_404 * V_24 )
{
struct V_405 * V_406 ;
int V_26 ;
T_5 V_289 , V_178 ;
V_289 = F_61 ( V_270 -> V_48 ) . V_289 ;
V_178 = V_270 -> V_74 -> V_290 ;
F_26 (ha, &list->list, list) {
if ( * V_274 < V_270 -> args [ 0 ] )
goto V_407;
V_26 = F_185 ( V_48 , V_29 , V_406 -> V_377 ,
V_289 , V_178 ,
V_401 , V_393 ,
V_291 ) ;
if ( V_26 < 0 )
return V_26 ;
V_407:
* V_274 += 1 ;
}
return 0 ;
}
int F_202 ( struct V_47 * V_48 ,
struct V_269 * V_270 ,
struct V_28 * V_29 ,
int V_274 )
{
int V_26 ;
F_203 ( V_29 ) ;
V_26 = F_201 ( V_48 , V_270 , V_29 , & V_274 , & V_29 -> V_408 ) ;
if ( V_26 )
goto V_63;
F_201 ( V_48 , V_270 , V_29 , & V_274 , & V_29 -> V_409 ) ;
V_63:
F_204 ( V_29 ) ;
return V_274 ;
}
static int F_205 ( struct V_47 * V_48 , struct V_269 * V_270 )
{
int V_274 = 0 ;
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
struct V_28 * V_29 ;
F_116 () ;
F_206 (net, dev) {
if ( V_29 -> V_397 & V_398 ) {
struct V_28 * V_399 ;
const struct V_301 * V_20 ;
V_399 = F_44 ( V_29 ) ;
V_20 = V_399 -> V_157 ;
if ( V_20 -> V_410 )
V_274 = V_20 -> V_410 ( V_48 , V_270 , V_29 , V_274 ) ;
}
if ( V_29 -> V_157 -> V_410 )
V_274 = V_29 -> V_157 -> V_410 ( V_48 , V_270 , V_29 , V_274 ) ;
else
V_274 = F_202 ( V_48 , V_270 , V_29 , V_274 ) ;
}
F_124 () ;
V_270 -> args [ 0 ] = V_274 ;
return V_48 -> V_292 ;
}
int F_207 ( struct V_47 * V_48 , T_5 V_65 , T_5 V_178 ,
struct V_28 * V_29 , T_8 V_411 )
{
struct V_73 * V_74 ;
struct V_110 * V_111 ;
struct V_39 * V_412 ;
T_9 V_102 = F_106 ( V_29 ) ? V_29 -> V_102 : V_196 ;
struct V_28 * V_399 = F_44 ( V_29 ) ;
V_74 = F_102 ( V_48 , V_65 , V_178 , V_288 , sizeof( * V_111 ) , V_291 ) ;
if ( V_74 == NULL )
return - V_51 ;
V_111 = F_103 ( V_74 ) ;
V_111 -> V_185 = V_382 ;
V_111 -> V_187 = 0 ;
V_111 -> V_188 = V_29 -> type ;
V_111 -> V_189 = V_29 -> V_190 ;
V_111 -> V_112 = F_104 ( V_29 ) ;
V_111 -> V_113 = 0 ;
if ( F_54 ( V_48 , V_191 , V_29 -> V_192 ) ||
F_73 ( V_48 , V_199 , V_29 -> V_200 ) ||
F_105 ( V_48 , V_195 , V_102 ) ||
( V_399 &&
F_73 ( V_48 , V_210 , V_399 -> V_190 ) ) ||
( V_29 -> V_227 &&
F_79 ( V_48 , V_228 , V_29 -> V_227 , V_29 -> V_229 ) ) ||
( V_29 -> V_190 != V_29 -> V_208 &&
F_73 ( V_48 , V_209 , V_29 -> V_208 ) ) )
goto V_83;
V_412 = F_55 ( V_48 , V_265 ) ;
if ( ! V_412 )
goto V_83;
if ( F_208 ( V_48 , V_413 , V_414 ) ||
F_208 ( V_48 , V_415 , V_411 ) ) {
F_57 ( V_48 , V_412 ) ;
goto V_83;
}
F_56 ( V_48 , V_412 ) ;
return F_112 ( V_48 , V_74 ) ;
V_83:
F_113 ( V_48 , V_74 ) ;
return - V_51 ;
}
static int F_209 ( struct V_47 * V_48 , struct V_269 * V_270 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
struct V_28 * V_29 ;
int V_274 = 0 ;
T_5 V_289 = F_61 ( V_270 -> V_48 ) . V_289 ;
T_5 V_178 = V_270 -> V_74 -> V_290 ;
struct V_39 * V_416 ;
T_5 V_417 = 0 ;
V_416 = F_210 ( V_270 -> V_74 , sizeof( struct V_110 ) ,
V_284 ) ;
if ( V_416 )
V_417 = F_119 ( V_416 ) ;
F_116 () ;
F_206 (net, dev) {
const struct V_301 * V_20 = V_29 -> V_157 ;
struct V_28 * V_399 = F_44 ( V_29 ) ;
if ( V_399 && V_399 -> V_157 -> V_418 ) {
if ( V_274 >= V_270 -> args [ 0 ] &&
V_399 -> V_157 -> V_418 (
V_48 , V_289 , V_178 , V_29 , V_417 ) < 0 )
break;
V_274 ++ ;
}
if ( V_20 -> V_418 ) {
if ( V_274 >= V_270 -> args [ 0 ] &&
V_20 -> V_418 ( V_48 , V_289 , V_178 , V_29 ,
V_417 ) < 0 )
break;
V_274 ++ ;
}
}
F_124 () ;
V_270 -> args [ 0 ] = V_274 ;
return V_48 -> V_292 ;
}
static inline T_4 F_211 ( void )
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
static int F_212 ( struct V_28 * V_29 , T_8 V_75 )
{
struct V_27 * V_27 = F_138 ( V_29 ) ;
struct V_28 * V_399 = F_44 ( V_29 ) ;
struct V_47 * V_48 ;
int V_26 = - V_175 ;
V_48 = F_179 ( F_211 () , V_392 ) ;
if ( ! V_48 ) {
V_26 = - V_329 ;
goto V_317;
}
if ( ( ! V_75 || ( V_75 & V_419 ) ) &&
V_399 && V_399 -> V_157 -> V_418 ) {
V_26 = V_399 -> V_157 -> V_418 ( V_48 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_317;
}
if ( ( V_75 & V_414 ) &&
V_29 -> V_157 -> V_418 ) {
V_26 = V_29 -> V_157 -> V_418 ( V_48 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_317;
}
F_67 ( V_48 , V_27 , 0 , V_376 , NULL , V_392 ) ;
return 0 ;
V_317:
F_121 ( V_26 == - V_51 ) ;
F_180 ( V_48 ) ;
F_70 ( V_27 , V_376 , V_26 ) ;
return V_26 ;
}
static int F_213 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
struct V_110 * V_111 ;
struct V_28 * V_29 ;
struct V_39 * V_420 , * V_182 = NULL ;
int V_297 , V_26 = - V_175 ;
T_8 V_421 , V_75 = 0 ;
bool V_422 = false ;
if ( F_117 ( V_74 ) < sizeof( * V_111 ) )
return - V_296 ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_185 != V_382 )
return - V_423 ;
V_29 = F_137 ( V_27 , V_111 -> V_189 ) ;
if ( ! V_29 ) {
F_189 ( L_13 ) ;
return - V_325 ;
}
V_420 = F_210 ( V_74 , sizeof( struct V_110 ) , V_265 ) ;
if ( V_420 ) {
F_133 (attr, br_spec, rem) {
if ( F_134 ( V_182 ) == V_413 ) {
V_422 = true ;
V_75 = F_214 ( V_182 ) ;
break;
}
}
}
V_421 = V_75 ;
if ( ! V_75 || ( V_75 & V_419 ) ) {
struct V_28 * V_399 = F_44 ( V_29 ) ;
if ( ! V_399 || ! V_399 -> V_157 -> V_424 ) {
V_26 = - V_175 ;
goto V_63;
}
V_26 = V_399 -> V_157 -> V_424 ( V_29 , V_74 ) ;
if ( V_26 )
goto V_63;
V_75 &= ~ V_419 ;
}
if ( ( V_75 & V_414 ) ) {
if ( ! V_29 -> V_157 -> V_424 )
V_26 = - V_175 ;
else
V_26 = V_29 -> V_157 -> V_424 ( V_29 , V_74 ) ;
if ( ! V_26 )
V_75 &= ~ V_414 ;
}
if ( V_422 )
memcpy ( F_111 ( V_182 ) , & V_75 , sizeof( V_75 ) ) ;
if ( ! V_26 )
V_26 = F_212 ( V_29 , V_421 ) ;
V_63:
return V_26 ;
}
static int F_215 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
struct V_110 * V_111 ;
struct V_28 * V_29 ;
struct V_39 * V_420 , * V_182 = NULL ;
int V_297 , V_26 = - V_175 ;
T_8 V_421 , V_75 = 0 ;
bool V_422 = false ;
if ( F_117 ( V_74 ) < sizeof( * V_111 ) )
return - V_296 ;
V_111 = F_103 ( V_74 ) ;
if ( V_111 -> V_185 != V_382 )
return - V_423 ;
V_29 = F_137 ( V_27 , V_111 -> V_189 ) ;
if ( ! V_29 ) {
F_189 ( L_13 ) ;
return - V_325 ;
}
V_420 = F_210 ( V_74 , sizeof( struct V_110 ) , V_265 ) ;
if ( V_420 ) {
F_133 (attr, br_spec, rem) {
if ( F_134 ( V_182 ) == V_413 ) {
V_422 = true ;
V_75 = F_214 ( V_182 ) ;
break;
}
}
}
V_421 = V_75 ;
if ( ! V_75 || ( V_75 & V_419 ) ) {
struct V_28 * V_399 = F_44 ( V_29 ) ;
if ( ! V_399 || ! V_399 -> V_157 -> V_425 ) {
V_26 = - V_175 ;
goto V_63;
}
V_26 = V_399 -> V_157 -> V_425 ( V_29 , V_74 ) ;
if ( V_26 )
goto V_63;
V_75 &= ~ V_419 ;
}
if ( ( V_75 & V_414 ) ) {
if ( ! V_29 -> V_157 -> V_425 )
V_26 = - V_175 ;
else
V_26 = V_29 -> V_157 -> V_425 ( V_29 , V_74 ) ;
if ( ! V_26 )
V_75 &= ~ V_414 ;
}
if ( V_422 )
memcpy ( F_111 ( V_182 ) , & V_75 , sizeof( V_75 ) ) ;
if ( ! V_26 )
V_26 = F_212 ( V_29 , V_421 ) ;
V_63:
return V_26 ;
}
static int F_216 ( struct V_47 * V_48 , struct V_73 * V_74 )
{
struct V_27 * V_27 = F_115 ( V_48 -> V_271 ) ;
T_1 V_11 ;
int V_426 , V_19 ;
int V_44 ;
int type ;
int V_26 ;
type = V_74 -> V_372 ;
if ( type > V_427 )
return - V_175 ;
type -= V_4 ;
if ( F_117 ( V_74 ) < sizeof( struct V_282 ) )
return 0 ;
V_44 = ( (struct V_282 * ) F_103 ( V_74 ) ) -> V_428 ;
V_426 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_217 ( V_48 , V_319 ) )
return - V_320 ;
if ( V_19 == 2 && V_74 -> V_359 & V_429 ) {
struct V_68 * V_69 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_430 = 0 ;
V_13 = F_16 ( V_44 , type ) ;
if ( V_13 == NULL )
return - V_175 ;
V_14 = F_17 ( V_44 , type ) ;
if ( V_14 )
V_430 = V_14 ( V_48 , V_74 ) ;
F_3 () ;
V_69 = V_27 -> V_69 ;
{
struct V_431 V_432 = {
. V_433 = V_13 ,
. V_430 = V_430 ,
} ;
V_26 = F_218 ( V_69 , V_48 , V_74 , & V_432 ) ;
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
static int F_221 ( struct V_434 * V_435 , unsigned long V_436 , void * V_437 )
{
struct V_28 * V_29 = F_222 ( V_437 ) ;
switch ( V_436 ) {
case V_438 :
case V_439 :
case V_440 :
case V_441 :
case V_442 :
case V_443 :
case V_444 :
case V_445 :
case V_446 :
case V_447 :
case V_448 :
case V_449 :
break;
default:
F_184 ( V_288 , V_29 , 0 , V_15 ) ;
break;
}
return V_450 ;
}
static int T_11 F_223 ( struct V_27 * V_27 )
{
struct V_68 * V_271 ;
struct V_451 V_452 = {
. V_453 = V_454 ,
. V_455 = F_219 ,
. V_456 = & V_1 ,
. V_75 = V_457 ,
} ;
V_271 = F_224 ( V_27 , V_458 , & V_452 ) ;
if ( ! V_271 )
return - V_329 ;
V_27 -> V_69 = V_271 ;
return 0 ;
}
static void T_12 F_225 ( struct V_27 * V_27 )
{
F_226 ( V_27 -> V_69 ) ;
V_27 -> V_69 = NULL ;
}
void T_13 F_227 ( void )
{
if ( F_228 ( & V_459 ) )
F_21 ( L_14 ) ;
F_229 ( & V_460 ) ;
F_20 ( V_12 , V_461 , F_178 ,
F_114 , F_181 ) ;
F_20 ( V_12 , V_462 , F_160 , NULL , NULL ) ;
F_20 ( V_12 , V_288 , F_172 , NULL , NULL ) ;
F_20 ( V_12 , V_463 , F_163 , NULL , NULL ) ;
F_20 ( V_12 , V_464 , NULL , F_183 , NULL ) ;
F_20 ( V_12 , V_465 , NULL , F_183 , NULL ) ;
F_20 ( V_466 , V_401 , F_195 , NULL , NULL ) ;
F_20 ( V_466 , V_403 , F_199 , NULL , NULL ) ;
F_20 ( V_466 , V_467 , NULL , F_205 , NULL ) ;
F_20 ( V_466 , V_461 , NULL , F_209 , NULL ) ;
F_20 ( V_466 , V_463 , F_215 , NULL , NULL ) ;
F_20 ( V_466 , V_462 , F_213 , NULL , NULL ) ;
}
