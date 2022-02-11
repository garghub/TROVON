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
static T_4 F_51 ( const struct V_29 * V_30 )
{
struct V_46 * V_48 ;
T_4 V_43 ;
V_43 = F_45 ( sizeof( struct V_42 ) ) ;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_48 -> V_49 ) {
V_43 += F_45 ( sizeof( struct V_42 ) ) +
V_48 -> V_49 ( V_30 ) ;
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
static int F_53 ( struct V_50 * V_51 ,
const struct V_29 * V_30 )
{
struct V_29 * V_40 ;
const struct V_18 * V_20 ;
struct V_42 * V_52 ;
int V_27 ;
V_40 = F_44 ( (struct V_29 * ) V_30 ) ;
if ( ! V_40 )
return 0 ;
V_20 = V_40 -> V_18 ;
if ( ! V_20 )
return 0 ;
if ( F_54 ( V_51 , V_53 , V_20 -> V_19 ) < 0 )
return - V_54 ;
if ( V_20 -> V_55 ) {
V_52 = F_55 ( V_51 , V_56 ) ;
if ( ! V_52 )
return - V_54 ;
V_27 = V_20 -> V_55 ( V_51 , V_40 , V_30 ) ;
if ( V_27 < 0 )
goto V_57;
F_56 ( V_51 , V_52 ) ;
}
return 0 ;
V_57:
F_57 ( V_51 , V_52 ) ;
return V_27 ;
}
static int F_58 ( struct V_50 * V_51 ,
const struct V_29 * V_30 )
{
const struct V_18 * V_20 = V_30 -> V_18 ;
struct V_42 * V_58 ;
int V_27 ;
if ( ! V_20 )
return 0 ;
if ( F_54 ( V_51 , V_59 , V_20 -> V_19 ) < 0 )
return - V_54 ;
if ( V_20 -> V_60 ) {
V_27 = V_20 -> V_60 ( V_51 , V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_20 -> V_61 ) {
V_58 = F_55 ( V_51 , V_62 ) ;
if ( V_58 == NULL )
return - V_54 ;
V_27 = V_20 -> V_61 ( V_51 , V_30 ) ;
if ( V_27 < 0 )
goto V_63;
F_56 ( V_51 , V_58 ) ;
}
return 0 ;
V_63:
F_57 ( V_51 , V_58 ) ;
return V_27 ;
}
static int F_59 ( struct V_50 * V_51 , const struct V_29 * V_30 )
{
struct V_42 * V_64 ;
int V_27 = - V_54 ;
V_64 = F_55 ( V_51 , V_65 ) ;
if ( V_64 == NULL )
goto V_66;
V_27 = F_58 ( V_51 , V_30 ) ;
if ( V_27 < 0 )
goto V_67;
V_27 = F_53 ( V_51 , V_30 ) ;
if ( V_27 < 0 )
goto V_67;
F_56 ( V_51 , V_64 ) ;
return 0 ;
V_67:
F_57 ( V_51 , V_64 ) ;
V_66:
return V_27 ;
}
int F_60 ( struct V_50 * V_51 , struct V_28 * V_28 , T_5 V_68 , unsigned int V_69 , int V_70 )
{
struct V_71 * V_72 = V_28 -> V_72 ;
int V_27 = 0 ;
F_61 ( V_51 ) . V_73 = V_69 ;
if ( V_70 )
F_62 ( & V_51 -> V_74 ) ;
F_63 ( V_72 , V_51 , V_68 , V_69 , V_15 ) ;
if ( V_70 )
V_27 = F_64 ( V_72 , V_51 , V_68 , V_75 ) ;
return V_27 ;
}
int F_65 ( struct V_50 * V_51 , struct V_28 * V_28 , T_5 V_68 )
{
struct V_71 * V_72 = V_28 -> V_72 ;
return F_66 ( V_72 , V_51 , V_68 ) ;
}
void F_67 ( struct V_50 * V_51 , struct V_28 * V_28 , T_5 V_68 , T_5 V_69 ,
struct V_76 * V_77 , T_6 V_78 )
{
struct V_71 * V_72 = V_28 -> V_72 ;
int V_79 = 0 ;
if ( V_77 )
V_79 = F_68 ( V_77 ) ;
F_69 ( V_72 , V_51 , V_68 , V_69 , V_79 , V_78 ) ;
}
void F_70 ( struct V_28 * V_28 , T_5 V_69 , int error )
{
struct V_71 * V_72 = V_28 -> V_72 ;
F_71 ( V_72 , 0 , V_69 , error ) ;
}
int F_72 ( struct V_50 * V_51 , T_5 * V_80 )
{
struct V_42 * V_81 ;
int V_82 , V_83 = 0 ;
V_81 = F_55 ( V_51 , V_84 ) ;
if ( V_81 == NULL )
return - V_16 ;
for ( V_82 = 0 ; V_82 < V_85 ; V_82 ++ ) {
if ( V_80 [ V_82 ] ) {
if ( V_82 == V_86 - 1 ) {
char V_87 [ V_88 ] , * V_89 ;
V_89 = F_73 ( V_80 [ V_82 ] , V_87 ) ;
if ( ! V_89 )
continue;
if ( F_54 ( V_51 , V_82 + 1 , V_89 ) )
goto V_90;
} else {
if ( F_74 ( V_51 , V_82 + 1 , V_80 [ V_82 ] ) )
goto V_90;
}
V_83 ++ ;
}
}
if ( ! V_83 ) {
F_57 ( V_51 , V_81 ) ;
return 0 ;
}
return F_56 ( V_51 , V_81 ) ;
V_90:
F_57 ( V_51 , V_81 ) ;
return - V_54 ;
}
int F_75 ( struct V_50 * V_51 , struct V_91 * V_92 , T_5 V_93 ,
long V_94 , T_5 error )
{
struct V_95 V_96 = {
. V_97 = F_76 ( V_98 - V_92 -> V_99 ) ,
. V_100 = V_92 -> V_101 ,
. V_102 = F_77 ( & ( V_92 -> V_103 ) ) ,
. V_104 = error ,
. V_105 = V_93 ,
} ;
if ( V_94 ) {
unsigned long clock ;
clock = F_78 ( abs ( V_94 ) ) ;
clock = F_79 (unsigned long, clock, INT_MAX) ;
V_96 . V_106 = ( V_94 > 0 ) ? clock : - clock ;
}
return F_80 ( V_51 , V_107 , sizeof( V_96 ) , & V_96 ) ;
}
static void F_81 ( struct V_29 * V_30 , unsigned char V_108 )
{
unsigned char V_109 = V_30 -> V_109 ;
switch ( V_108 ) {
case V_110 :
if ( ( V_109 == V_111 ||
V_109 == V_112 ) &&
! F_82 ( V_30 ) )
V_109 = V_110 ;
break;
case V_111 :
if ( V_109 == V_110 ||
V_109 == V_112 )
V_109 = V_111 ;
break;
}
if ( V_30 -> V_109 != V_109 ) {
F_83 ( & V_113 ) ;
V_30 -> V_109 = V_109 ;
F_84 ( & V_113 ) ;
F_85 ( V_30 ) ;
}
}
static unsigned int F_86 ( const struct V_29 * V_30 )
{
return ( V_30 -> V_78 & ~ ( V_114 | V_115 ) ) |
( V_30 -> V_116 & ( V_114 | V_115 ) ) ;
}
static unsigned int F_87 ( const struct V_29 * V_30 ,
const struct V_117 * V_118 )
{
unsigned int V_78 = V_118 -> V_119 ;
if ( V_118 -> V_120 )
V_78 = ( V_78 & V_118 -> V_120 ) |
( F_86 ( V_30 ) & ~ V_118 -> V_120 ) ;
return V_78 ;
}
static void F_88 ( struct V_121 * V_122 ,
const struct V_123 * V_124 )
{
V_122 -> V_125 = V_124 -> V_125 ;
V_122 -> V_126 = V_124 -> V_126 ;
V_122 -> V_127 = V_124 -> V_127 ;
V_122 -> V_128 = V_124 -> V_128 ;
V_122 -> V_129 = V_124 -> V_129 ;
V_122 -> V_130 = V_124 -> V_130 ;
V_122 -> V_131 = V_124 -> V_131 ;
V_122 -> V_132 = V_124 -> V_132 ;
V_122 -> V_133 = V_124 -> V_133 ;
V_122 -> V_134 = V_124 -> V_134 ;
V_122 -> V_135 = V_124 -> V_135 ;
V_122 -> V_136 = V_124 -> V_136 ;
V_122 -> V_137 = V_124 -> V_137 ;
V_122 -> V_138 = V_124 -> V_138 ;
V_122 -> V_139 = V_124 -> V_139 ;
V_122 -> V_140 = V_124 -> V_140 ;
V_122 -> V_141 = V_124 -> V_141 ;
V_122 -> V_142 = V_124 -> V_142 ;
V_122 -> V_143 = V_124 -> V_143 ;
V_122 -> V_144 = V_124 -> V_144 ;
V_122 -> V_145 = V_124 -> V_145 ;
V_122 -> V_146 = V_124 -> V_146 ;
V_122 -> V_147 = V_124 -> V_147 ;
}
static void F_89 ( void * V_148 , const struct V_123 * V_124 )
{
memcpy ( V_148 , V_124 , sizeof( * V_124 ) ) ;
}
static inline int F_90 ( const struct V_29 * V_30 ,
T_5 V_149 )
{
if ( V_30 -> V_30 . V_150 && F_91 ( V_30 -> V_30 . V_150 ) &&
( V_149 & V_151 ) ) {
int V_152 = F_92 ( V_30 -> V_30 . V_150 ) ;
T_4 V_43 = F_45 ( sizeof( struct V_42 ) ) ;
V_43 += F_45 ( V_152 * sizeof( struct V_42 ) ) ;
V_43 += V_152 *
( F_45 ( sizeof( struct V_153 ) ) +
F_45 ( sizeof( struct V_154 ) ) +
F_45 ( sizeof( struct V_155 ) ) +
F_45 ( sizeof( struct V_156 ) ) +
F_45 ( sizeof( struct V_157 ) ) +
F_45 ( sizeof( struct V_158 ) ) +
F_45 ( sizeof( V_159 ) ) +
F_45 ( sizeof( V_159 ) ) +
F_45 ( sizeof( V_159 ) ) +
F_45 ( sizeof( V_159 ) ) +
F_45 ( sizeof( V_159 ) ) +
F_45 ( sizeof( V_159 ) ) ) ;
return V_43 ;
} else
return 0 ;
}
static T_4 F_93 ( const struct V_29 * V_30 ,
T_5 V_149 )
{
T_4 V_160 = F_45 ( 4 )
+ F_45 ( V_161 )
+ F_45 ( sizeof( struct V_162 ) )
+ F_45 ( V_163 )
+ F_45 ( V_163 )
+ F_45 ( 1 )
+ F_45 ( 2 ) ;
T_4 V_164 = F_45 ( sizeof( struct V_42 ) ) ;
T_4 V_165 = F_45 ( sizeof( struct V_42 ) )
+ V_160 ;
T_4 V_166 = F_45 ( sizeof( struct V_42 ) )
+ V_160 ;
if ( ! V_30 -> V_167 -> V_168 || ! V_30 -> V_30 . V_150 ||
! ( V_149 & V_151 ) )
return 0 ;
if ( F_92 ( V_30 -> V_30 . V_150 ) )
return V_166 + V_164 +
V_165 * F_92 ( V_30 -> V_30 . V_150 ) ;
else
return V_166 ;
}
static T_7 T_4 F_94 ( const struct V_29 * V_30 ,
T_5 V_149 )
{
return F_95 ( sizeof( struct V_117 ) )
+ F_45 ( V_169 )
+ F_45 ( V_170 )
+ F_45 ( V_169 )
+ F_45 ( sizeof( struct V_171 ) )
+ F_45 ( sizeof( struct V_121 ) )
+ F_45 ( sizeof( struct V_123 ) )
+ F_45 ( V_172 )
+ F_45 ( V_172 )
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
+ F_45 ( 4 )
+ F_45 ( V_149
& V_151 ? 4 : 0 )
+ F_90 ( V_30 , V_149 )
+ F_93 ( V_30 , V_149 )
+ F_46 ( V_30 )
+ F_51 ( V_30 )
+ F_45 ( V_173 )
+ F_45 ( V_173 ) ;
}
static int F_96 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_174 ;
struct V_42 * V_175 ;
int V_176 ;
int V_27 ;
V_174 = F_55 ( V_51 , V_177 ) ;
if ( ! V_174 )
return - V_54 ;
for ( V_176 = 0 ; V_176 < F_92 ( V_30 -> V_30 . V_150 ) ; V_176 ++ ) {
V_175 = F_55 ( V_51 , V_178 ) ;
if ( ! V_175 )
goto V_90;
if ( F_74 ( V_51 , V_179 , V_176 ) )
goto V_90;
V_27 = V_30 -> V_167 -> V_168 ( V_30 , V_176 , V_51 ) ;
if ( V_27 == - V_54 )
goto V_90;
if ( V_27 ) {
F_57 ( V_51 , V_175 ) ;
continue;
}
F_56 ( V_51 , V_175 ) ;
}
F_56 ( V_51 , V_174 ) ;
return 0 ;
V_90:
F_57 ( V_51 , V_174 ) ;
return - V_54 ;
}
static int F_97 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_180 ;
int V_27 ;
V_180 = F_55 ( V_51 , V_181 ) ;
if ( ! V_180 )
return - V_54 ;
V_27 = V_30 -> V_167 -> V_168 ( V_30 , V_182 , V_51 ) ;
if ( V_27 ) {
F_57 ( V_51 , V_180 ) ;
return ( V_27 == - V_54 ) ? V_27 : 0 ;
}
F_56 ( V_51 , V_180 ) ;
return 0 ;
}
static int F_98 ( struct V_50 * V_51 , struct V_29 * V_30 ,
T_5 V_149 )
{
int V_27 ;
if ( ! V_30 -> V_167 -> V_168 || ! V_30 -> V_30 . V_150 ||
! ( V_149 & V_151 ) )
return 0 ;
V_27 = F_97 ( V_51 , V_30 ) ;
if ( V_27 )
return V_27 ;
if ( F_92 ( V_30 -> V_30 . V_150 ) ) {
V_27 = F_96 ( V_51 , V_30 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_99 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
int V_27 ;
struct V_183 V_184 ;
V_27 = F_100 ( V_30 , & V_184 ) ;
if ( V_27 ) {
if ( V_27 == - V_185 )
return 0 ;
return V_27 ;
}
if ( F_80 ( V_51 , V_186 , V_184 . V_187 , V_184 . V_93 ) )
return - V_54 ;
return 0 ;
}
static int F_101 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
char V_89 [ V_169 ] ;
int V_27 ;
V_27 = F_102 ( V_30 , V_89 , sizeof( V_89 ) ) ;
if ( V_27 ) {
if ( V_27 == - V_185 )
return 0 ;
return V_27 ;
}
if ( F_80 ( V_51 , V_188 , strlen ( V_89 ) , V_89 ) )
return - V_54 ;
return 0 ;
}
static int F_103 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
int V_27 ;
struct V_189 V_190 = {
. V_93 = V_191 ,
. V_78 = V_192 ,
} ;
V_27 = F_104 ( V_30 , & V_190 ) ;
if ( V_27 ) {
if ( V_27 == - V_185 )
return 0 ;
return V_27 ;
}
if ( F_80 ( V_51 , V_193 , V_190 . V_194 . V_184 . V_187 ,
V_190 . V_194 . V_184 . V_93 ) )
return - V_54 ;
return 0 ;
}
static int F_105 ( struct V_50 * V_51 , struct V_29 * V_30 ,
int type , T_5 V_68 , T_5 V_195 , T_5 V_196 ,
unsigned int V_78 , T_5 V_149 )
{
struct V_117 * V_118 ;
struct V_76 * V_77 ;
struct V_123 V_197 ;
const struct V_123 * V_198 ;
struct V_42 * V_190 , * V_199 ;
struct V_46 * V_48 ;
struct V_29 * V_200 = F_44 ( V_30 ) ;
F_106 () ;
V_77 = F_107 ( V_51 , V_68 , V_195 , type , sizeof( * V_118 ) , V_78 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_118 = F_108 ( V_77 ) ;
V_118 -> V_201 = V_202 ;
V_118 -> V_203 = 0 ;
V_118 -> V_204 = V_30 -> type ;
V_118 -> V_205 = V_30 -> V_206 ;
V_118 -> V_119 = F_109 ( V_30 ) ;
V_118 -> V_120 = V_196 ;
if ( F_54 ( V_51 , V_207 , V_30 -> V_89 ) ||
F_74 ( V_51 , V_208 , V_30 -> V_209 ) ||
F_110 ( V_51 , V_210 ,
F_111 ( V_30 ) ? V_30 -> V_109 : V_211 ) ||
F_110 ( V_51 , V_212 , V_30 -> V_213 ) ||
F_74 ( V_51 , V_214 , V_30 -> V_215 ) ||
F_74 ( V_51 , V_216 , V_30 -> V_69 ) ||
F_74 ( V_51 , V_217 , V_30 -> V_218 ) ||
F_74 ( V_51 , V_219 , V_30 -> V_220 ) ||
#ifdef F_112
F_74 ( V_51 , V_221 , V_30 -> V_222 ) ||
#endif
( V_30 -> V_206 != F_113 ( V_30 ) &&
F_74 ( V_51 , V_223 , F_113 ( V_30 ) ) ) ||
( V_200 &&
F_74 ( V_51 , V_224 , V_200 -> V_206 ) ) ||
F_110 ( V_51 , V_225 , F_114 ( V_30 ) ) ||
( V_30 -> V_226 &&
F_54 ( V_51 , V_227 , V_30 -> V_226 -> V_20 -> V_93 ) ) ||
( V_30 -> V_228 &&
F_54 ( V_51 , V_229 , V_30 -> V_228 ) ) ||
F_74 ( V_51 , V_230 ,
F_77 ( & V_30 -> V_231 ) ) )
goto V_90;
if ( 1 ) {
struct V_171 V_232 = {
. V_233 = V_30 -> V_233 ,
. V_234 = V_30 -> V_234 ,
. V_235 = V_30 -> V_235 ,
. V_236 = V_30 -> V_236 ,
. V_237 = V_30 -> V_237 ,
. V_238 = V_30 -> V_239 ,
} ;
if ( F_80 ( V_51 , V_240 , sizeof( V_232 ) , & V_232 ) )
goto V_90;
}
if ( V_30 -> V_241 ) {
if ( F_80 ( V_51 , V_242 , V_30 -> V_241 , V_30 -> V_243 ) ||
F_80 ( V_51 , V_244 , V_30 -> V_241 , V_30 -> V_245 ) )
goto V_90;
}
if ( F_99 ( V_51 , V_30 ) )
goto V_90;
if ( F_101 ( V_51 , V_30 ) )
goto V_90;
if ( F_103 ( V_51 , V_30 ) )
goto V_90;
V_190 = F_115 ( V_51 , V_246 ,
sizeof( struct V_121 ) ) ;
if ( V_190 == NULL )
goto V_90;
V_198 = F_116 ( V_30 , & V_197 ) ;
F_88 ( F_117 ( V_190 ) , V_198 ) ;
V_190 = F_115 ( V_51 , V_247 ,
sizeof( struct V_123 ) ) ;
if ( V_190 == NULL )
goto V_90;
F_89 ( F_117 ( V_190 ) , V_198 ) ;
if ( V_30 -> V_30 . V_150 && ( V_149 & V_151 ) &&
F_74 ( V_51 , V_248 , F_92 ( V_30 -> V_30 . V_150 ) ) )
goto V_90;
if ( V_30 -> V_167 -> V_249 && V_30 -> V_30 . V_150
&& ( V_149 & V_151 ) ) {
int V_82 ;
struct V_42 * V_250 , * V_176 , * V_251 ;
int V_152 = F_92 ( V_30 -> V_30 . V_150 ) ;
V_250 = F_55 ( V_51 , V_252 ) ;
if ( ! V_250 )
goto V_90;
for ( V_82 = 0 ; V_82 < V_152 ; V_82 ++ ) {
struct V_253 V_254 ;
struct V_153 V_255 ;
struct V_154 V_256 ;
struct V_156 V_257 ;
struct V_258 V_259 ;
struct V_155 V_260 ;
struct V_157 V_261 ;
struct V_158 V_262 ;
struct V_263 V_264 ;
V_254 . V_265 = - 1 ;
V_254 . V_266 = - 1 ;
memset ( V_254 . V_267 , 0 , sizeof( V_254 . V_267 ) ) ;
V_254 . V_268 = 0 ;
if ( V_30 -> V_167 -> V_249 ( V_30 , V_82 , & V_254 ) )
break;
V_255 . V_176 =
V_256 . V_176 =
V_257 . V_176 =
V_259 . V_176 =
V_260 . V_176 =
V_261 . V_176 =
V_262 . V_176 = V_254 . V_176 ;
memcpy ( V_255 . V_267 , V_254 . V_267 , sizeof( V_254 . V_267 ) ) ;
V_256 . V_269 = V_254 . V_269 ;
V_256 . V_270 = V_254 . V_270 ;
V_259 . V_271 = V_254 . V_272 ;
V_257 . V_273 = V_254 . V_273 ;
V_257 . V_272 = V_254 . V_272 ;
V_260 . V_274 = V_254 . V_265 ;
V_261 . V_275 = V_254 . V_268 ;
V_262 . V_274 = V_254 . V_266 ;
V_176 = F_55 ( V_51 , V_276 ) ;
if ( ! V_176 ) {
F_57 ( V_51 , V_250 ) ;
goto V_90;
}
if ( F_80 ( V_51 , V_277 , sizeof( V_255 ) , & V_255 ) ||
F_80 ( V_51 , V_278 , sizeof( V_256 ) , & V_256 ) ||
F_80 ( V_51 , V_279 , sizeof( V_257 ) ,
& V_257 ) ||
F_80 ( V_51 , V_280 , sizeof( V_259 ) ,
& V_259 ) ||
F_80 ( V_51 , V_281 , sizeof( V_260 ) ,
& V_260 ) ||
F_80 ( V_51 , V_282 , sizeof( V_261 ) ,
& V_261 ) ||
F_80 ( V_51 , V_283 ,
sizeof( V_262 ) ,
& V_262 ) )
goto V_90;
memset ( & V_264 , 0 , sizeof( V_264 ) ) ;
if ( V_30 -> V_167 -> V_284 )
V_30 -> V_167 -> V_284 ( V_30 , V_82 ,
& V_264 ) ;
V_251 = F_55 ( V_51 , V_285 ) ;
if ( ! V_251 ) {
F_57 ( V_51 , V_176 ) ;
F_57 ( V_51 , V_250 ) ;
goto V_90;
}
if ( F_118 ( V_51 , V_286 ,
V_264 . V_125 ) ||
F_118 ( V_51 , V_287 ,
V_264 . V_126 ) ||
F_118 ( V_51 , V_288 ,
V_264 . V_127 ) ||
F_118 ( V_51 , V_289 ,
V_264 . V_128 ) ||
F_118 ( V_51 , V_290 ,
V_264 . V_245 ) ||
F_118 ( V_51 , V_291 ,
V_264 . V_133 ) )
goto V_90;
F_56 ( V_51 , V_251 ) ;
F_56 ( V_51 , V_176 ) ;
}
F_56 ( V_51 , V_250 ) ;
}
if ( F_98 ( V_51 , V_30 , V_149 ) )
goto V_90;
if ( V_30 -> V_18 || F_52 ( V_30 ) ) {
if ( F_59 ( V_51 , V_30 ) < 0 )
goto V_90;
}
if ( V_30 -> V_18 &&
V_30 -> V_18 -> V_292 ) {
struct V_28 * V_293 = V_30 -> V_18 -> V_292 ( V_30 ) ;
if ( ! F_119 ( F_120 ( V_30 ) , V_293 ) ) {
int V_93 = F_121 ( F_120 ( V_30 ) , V_293 ) ;
if ( F_122 ( V_51 , V_294 , V_93 ) )
goto V_90;
}
}
if ( ! ( V_199 = F_55 ( V_51 , V_295 ) ) )
goto V_90;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_48 -> V_296 ) {
struct V_42 * V_297 ;
int V_27 ;
if ( ! ( V_297 = F_55 ( V_51 , V_48 -> V_47 ) ) )
goto V_90;
V_27 = V_48 -> V_296 ( V_51 , V_30 ) ;
if ( V_27 == - V_298 )
F_57 ( V_51 , V_297 ) ;
else if ( V_27 < 0 )
goto V_90;
F_56 ( V_51 , V_297 ) ;
}
}
F_56 ( V_51 , V_199 ) ;
F_123 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_124 ( V_51 , V_77 ) ;
return - V_54 ;
}
static int F_125 ( struct V_50 * V_51 , struct V_299 * V_300 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
int V_302 , V_303 ;
int V_304 = 0 , V_305 ;
struct V_29 * V_30 ;
struct V_306 * V_307 ;
struct V_42 * V_308 [ V_309 + 1 ] ;
T_5 V_149 = 0 ;
int V_27 ;
int V_310 ;
V_303 = V_300 -> args [ 0 ] ;
V_305 = V_300 -> args [ 1 ] ;
V_300 -> V_195 = V_28 -> V_311 ;
V_310 = F_127 ( V_300 -> V_77 ) < sizeof( struct V_117 ) ?
sizeof( struct V_312 ) : sizeof( struct V_117 ) ;
if ( F_128 ( V_300 -> V_77 , V_310 , V_308 , V_309 , V_313 ) >= 0 ) {
if ( V_308 [ V_314 ] )
V_149 = F_129 ( V_308 [ V_314 ] ) ;
}
for ( V_302 = V_303 ; V_302 < V_315 ; V_302 ++ , V_305 = 0 ) {
V_304 = 0 ;
V_307 = & V_28 -> V_316 [ V_302 ] ;
F_130 (dev, head, index_hlist) {
if ( V_304 < V_305 )
goto V_317;
V_27 = F_105 ( V_51 , V_30 , V_318 ,
F_61 ( V_300 -> V_51 ) . V_319 ,
V_300 -> V_77 -> V_320 , 0 ,
V_321 ,
V_149 ) ;
F_131 ( ( V_27 == - V_54 ) && ( V_51 -> V_322 == 0 ) ) ;
if ( V_27 < 0 )
goto V_66;
F_132 ( V_300 , F_133 ( V_51 ) ) ;
V_317:
V_304 ++ ;
}
}
V_66:
V_300 -> args [ 1 ] = V_304 ;
V_300 -> args [ 0 ] = V_302 ;
return V_51 -> V_322 ;
}
int F_134 ( struct V_42 * * V_308 , const struct V_42 * V_307 , int V_322 )
{
return F_135 ( V_308 , V_309 , V_307 , V_322 , V_313 ) ;
}
struct V_28 * F_136 ( struct V_28 * V_323 , struct V_42 * V_308 [] )
{
struct V_28 * V_28 ;
if ( V_308 [ V_324 ] )
V_28 = F_137 ( F_129 ( V_308 [ V_324 ] ) ) ;
else if ( V_308 [ V_325 ] )
V_28 = F_138 ( F_129 ( V_308 [ V_325 ] ) ) ;
else
V_28 = F_139 ( V_323 ) ;
return V_28 ;
}
static int F_140 ( struct V_29 * V_30 , struct V_42 * V_308 [] )
{
if ( V_30 ) {
if ( V_308 [ V_242 ] &&
F_141 ( V_308 [ V_242 ] ) < V_30 -> V_241 )
return - V_326 ;
if ( V_308 [ V_244 ] &&
F_141 ( V_308 [ V_244 ] ) < V_30 -> V_241 )
return - V_326 ;
}
if ( V_308 [ V_295 ] ) {
struct V_42 * V_297 ;
int V_327 , V_27 ;
F_142 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_143 ( V_297 ) ) ) )
return - V_328 ;
if ( ! V_48 -> V_329 )
return - V_185 ;
if ( V_48 -> V_330 ) {
V_27 = V_48 -> V_330 ( V_30 , V_297 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_144 ( struct V_29 * V_30 , struct V_42 * * V_308 )
{
const struct V_331 * V_20 = V_30 -> V_167 ;
int V_27 = - V_326 ;
if ( V_308 [ V_277 ] ) {
struct V_153 * V_332 = F_117 ( V_308 [ V_277 ] ) ;
V_27 = - V_185 ;
if ( V_20 -> V_333 )
V_27 = V_20 -> V_333 ( V_30 , V_332 -> V_176 ,
V_332 -> V_267 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_308 [ V_278 ] ) {
struct V_154 * V_334 = F_117 ( V_308 [ V_278 ] ) ;
V_27 = - V_185 ;
if ( V_20 -> V_335 )
V_27 = V_20 -> V_335 ( V_30 , V_334 -> V_176 , V_334 -> V_269 ,
V_334 -> V_270 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_308 [ V_280 ] ) {
struct V_258 * V_336 = F_117 ( V_308 [ V_280 ] ) ;
struct V_253 V_337 ;
V_27 = - V_185 ;
if ( V_20 -> V_249 )
V_27 = V_20 -> V_249 ( V_30 , V_336 -> V_176 , & V_337 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = - V_185 ;
if ( V_20 -> V_338 )
V_27 = V_20 -> V_338 ( V_30 , V_336 -> V_176 ,
V_337 . V_273 ,
V_336 -> V_271 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_308 [ V_279 ] ) {
struct V_156 * V_336 = F_117 ( V_308 [ V_279 ] ) ;
V_27 = - V_185 ;
if ( V_20 -> V_338 )
V_27 = V_20 -> V_338 ( V_30 , V_336 -> V_176 ,
V_336 -> V_273 ,
V_336 -> V_272 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_308 [ V_281 ] ) {
struct V_155 * V_339 = F_117 ( V_308 [ V_281 ] ) ;
V_27 = - V_185 ;
if ( V_20 -> V_340 )
V_27 = V_20 -> V_340 ( V_30 , V_339 -> V_176 ,
V_339 -> V_274 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_308 [ V_282 ] ) {
struct V_157 * V_341 = F_117 ( V_308 [ V_282 ] ) ;
V_27 = - V_185 ;
if ( V_20 -> V_342 )
V_27 = V_20 -> V_342 ( V_30 , V_341 -> V_176 ,
V_341 -> V_275 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_308 [ V_283 ] ) {
struct V_158 * V_343 ;
V_27 = - V_185 ;
V_343 = F_117 ( V_308 [ V_283 ] ) ;
if ( V_20 -> V_344 )
V_27 = V_20 -> V_344 ( V_30 , V_343 -> V_176 ,
V_343 -> V_274 ) ;
if ( V_27 < 0 )
return V_27 ;
}
return V_27 ;
}
static int F_145 ( struct V_29 * V_30 , int V_206 )
{
struct V_29 * V_200 = F_44 ( V_30 ) ;
const struct V_331 * V_20 ;
int V_27 ;
if ( V_200 ) {
if ( V_200 -> V_206 == V_206 )
return 0 ;
V_20 = V_200 -> V_167 ;
if ( V_20 -> V_345 ) {
V_27 = V_20 -> V_345 ( V_200 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_185 ;
}
}
if ( V_206 ) {
V_200 = F_146 ( F_120 ( V_30 ) , V_206 ) ;
if ( ! V_200 )
return - V_326 ;
V_20 = V_200 -> V_167 ;
if ( V_20 -> V_346 ) {
V_27 = V_20 -> V_346 ( V_200 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_185 ;
}
}
return 0 ;
}
static int F_147 ( const struct V_50 * V_51 ,
struct V_29 * V_30 , struct V_117 * V_118 ,
struct V_42 * * V_308 , char * V_347 , int V_348 )
{
const struct V_331 * V_20 = V_30 -> V_167 ;
int V_27 ;
if ( V_308 [ V_324 ] || V_308 [ V_325 ] ) {
struct V_28 * V_28 = F_136 ( F_120 ( V_30 ) , V_308 ) ;
if ( F_148 ( V_28 ) ) {
V_27 = F_149 ( V_28 ) ;
goto V_349;
}
if ( ! F_150 ( V_51 , V_28 -> V_350 , V_351 ) ) {
F_151 ( V_28 ) ;
V_27 = - V_352 ;
goto V_349;
}
V_27 = F_152 ( V_30 , V_28 , V_347 ) ;
F_151 ( V_28 ) ;
if ( V_27 )
goto V_349;
V_348 |= V_353 ;
}
if ( V_308 [ V_240 ] ) {
struct V_171 * V_354 ;
struct V_355 V_356 ;
if ( ! V_20 -> V_357 ) {
V_27 = - V_185 ;
goto V_349;
}
if ( ! F_153 ( V_30 ) ) {
V_27 = - V_358 ;
goto V_349;
}
V_354 = F_117 ( V_308 [ V_240 ] ) ;
V_356 . V_233 = ( unsigned long ) V_354 -> V_233 ;
V_356 . V_234 = ( unsigned long ) V_354 -> V_234 ;
V_356 . V_235 = ( unsigned short ) V_354 -> V_235 ;
V_356 . V_236 = ( unsigned char ) V_354 -> V_236 ;
V_356 . V_237 = ( unsigned char ) V_354 -> V_237 ;
V_356 . V_238 = ( unsigned char ) V_354 -> V_238 ;
V_27 = V_20 -> V_357 ( V_30 , & V_356 ) ;
if ( V_27 < 0 )
goto V_349;
V_348 |= V_359 ;
}
if ( V_308 [ V_242 ] ) {
struct V_360 * V_361 ;
int V_322 ;
V_322 = sizeof( V_362 ) + V_30 -> V_241 ;
V_361 = F_154 ( V_322 , V_15 ) ;
if ( ! V_361 ) {
V_27 = - V_363 ;
goto V_349;
}
V_361 -> V_364 = V_30 -> type ;
memcpy ( V_361 -> V_365 , F_117 ( V_308 [ V_242 ] ) ,
V_30 -> V_241 ) ;
V_27 = F_155 ( V_30 , V_361 ) ;
F_24 ( V_361 ) ;
if ( V_27 )
goto V_349;
V_348 |= V_353 ;
}
if ( V_308 [ V_214 ] ) {
V_27 = F_156 ( V_30 , F_129 ( V_308 [ V_214 ] ) ) ;
if ( V_27 < 0 )
goto V_349;
V_348 |= V_353 ;
}
if ( V_308 [ V_216 ] ) {
F_157 ( V_30 , F_129 ( V_308 [ V_216 ] ) ) ;
V_348 |= V_359 ;
}
if ( V_118 -> V_205 > 0 && V_347 [ 0 ] ) {
V_27 = F_158 ( V_30 , V_347 ) ;
if ( V_27 < 0 )
goto V_349;
V_348 |= V_353 ;
}
if ( V_308 [ V_229 ] ) {
V_27 = F_159 ( V_30 , F_117 ( V_308 [ V_229 ] ) ,
F_141 ( V_308 [ V_229 ] ) ) ;
if ( V_27 < 0 )
goto V_349;
V_348 |= V_359 ;
}
if ( V_308 [ V_244 ] ) {
F_160 ( V_30 -> V_245 , V_308 [ V_244 ] , V_30 -> V_241 ) ;
F_161 ( V_366 , V_30 ) ;
}
if ( V_118 -> V_119 || V_118 -> V_120 ) {
V_27 = F_162 ( V_30 , F_87 ( V_30 , V_118 ) ) ;
if ( V_27 < 0 )
goto V_349;
}
if ( V_308 [ V_224 ] ) {
V_27 = F_145 ( V_30 , F_129 ( V_308 [ V_224 ] ) ) ;
if ( V_27 )
goto V_349;
V_348 |= V_353 ;
}
if ( V_308 [ V_225 ] ) {
V_27 = F_163 ( V_30 , F_164 ( V_308 [ V_225 ] ) ) ;
if ( V_27 )
goto V_349;
V_348 |= V_353 ;
}
if ( V_308 [ V_208 ] ) {
unsigned long V_367 = F_129 ( V_308 [ V_208 ] ) ;
if ( V_30 -> V_209 ^ V_367 )
V_348 |= V_359 ;
V_30 -> V_209 = V_367 ;
}
if ( V_308 [ V_210 ] )
F_81 ( V_30 , F_164 ( V_308 [ V_210 ] ) ) ;
if ( V_308 [ V_212 ] ) {
unsigned char V_367 = F_164 ( V_308 [ V_212 ] ) ;
F_83 ( & V_113 ) ;
if ( V_30 -> V_213 ^ V_367 )
V_348 |= V_359 ;
V_30 -> V_213 = V_367 ;
F_84 ( & V_113 ) ;
}
if ( V_308 [ V_252 ] ) {
struct V_42 * V_250 [ V_368 + 1 ] ;
struct V_42 * V_190 ;
int V_327 ;
F_142 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_143 ( V_190 ) != V_276 ||
F_141 ( V_190 ) < V_369 ) {
V_27 = - V_326 ;
goto V_349;
}
V_27 = F_165 ( V_250 , V_368 , V_190 ,
V_370 ) ;
if ( V_27 < 0 )
goto V_349;
V_27 = F_144 ( V_30 , V_250 ) ;
if ( V_27 < 0 )
goto V_349;
V_348 |= V_359 ;
}
}
V_27 = 0 ;
if ( V_308 [ V_177 ] ) {
struct V_42 * V_238 [ V_371 + 1 ] ;
struct V_42 * V_190 ;
int V_176 ;
int V_327 ;
V_27 = - V_185 ;
if ( ! V_20 -> V_372 )
goto V_349;
F_142 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_143 ( V_190 ) != V_178 ||
F_141 ( V_190 ) < V_369 ) {
V_27 = - V_326 ;
goto V_349;
}
V_27 = F_165 ( V_238 , V_371 , V_190 ,
V_373 ) ;
if ( V_27 < 0 )
goto V_349;
if ( ! V_238 [ V_179 ] ) {
V_27 = - V_185 ;
goto V_349;
}
V_176 = F_129 ( V_238 [ V_179 ] ) ;
V_27 = V_20 -> V_372 ( V_30 , V_176 , V_238 ) ;
if ( V_27 < 0 )
goto V_349;
V_348 |= V_359 ;
}
}
V_27 = 0 ;
if ( V_308 [ V_181 ] ) {
struct V_42 * V_238 [ V_371 + 1 ] ;
V_27 = F_165 ( V_238 , V_371 ,
V_308 [ V_181 ] , V_373 ) ;
if ( V_27 < 0 )
goto V_349;
V_27 = - V_185 ;
if ( V_20 -> V_372 )
V_27 = V_20 -> V_372 ( V_30 , V_182 , V_238 ) ;
if ( V_27 < 0 )
goto V_349;
V_348 |= V_359 ;
}
if ( V_308 [ V_295 ] ) {
struct V_42 * V_297 ;
int V_327 ;
F_142 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_143 ( V_297 ) ) ) )
F_166 () ;
V_27 = V_48 -> V_329 ( V_30 , V_297 ) ;
if ( V_27 < 0 )
goto V_349;
V_348 |= V_359 ;
}
}
V_27 = 0 ;
V_349:
if ( V_348 & V_353 ) {
if ( V_348 & V_359 )
F_85 ( V_30 ) ;
if ( V_27 < 0 )
F_167 ( L_3 ,
V_30 -> V_89 ) ;
}
return V_27 ;
}
static int F_168 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
struct V_117 * V_118 ;
struct V_29 * V_30 ;
int V_27 ;
struct V_42 * V_308 [ V_309 + 1 ] ;
char V_347 [ V_169 ] ;
V_27 = F_128 ( V_77 , sizeof( * V_118 ) , V_308 , V_309 , V_313 ) ;
if ( V_27 < 0 )
goto V_349;
if ( V_308 [ V_207 ] )
F_169 ( V_347 , V_308 [ V_207 ] , V_169 ) ;
else
V_347 [ 0 ] = '\0' ;
V_27 = - V_326 ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_205 > 0 )
V_30 = F_146 ( V_28 , V_118 -> V_205 ) ;
else if ( V_308 [ V_207 ] )
V_30 = F_170 ( V_28 , V_347 ) ;
else
goto V_349;
if ( V_30 == NULL ) {
V_27 = - V_358 ;
goto V_349;
}
V_27 = F_140 ( V_30 , V_308 ) ;
if ( V_27 < 0 )
goto V_349;
V_27 = F_147 ( V_51 , V_30 , V_118 , V_308 , V_347 , 0 ) ;
V_349:
return V_27 ;
}
static int F_171 ( const struct V_28 * V_28 , int V_69 )
{
struct V_29 * V_30 , * V_374 ;
F_31 ( V_31 ) ;
bool V_375 = false ;
if ( ! V_69 )
return - V_352 ;
F_32 (net, dev) {
if ( V_30 -> V_69 == V_69 ) {
const struct V_18 * V_20 ;
V_375 = true ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_185 ;
}
}
if ( ! V_375 )
return - V_358 ;
F_172 (net, dev, aux) {
if ( V_30 -> V_69 == V_69 ) {
const struct V_18 * V_20 ;
V_20 = V_30 -> V_18 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
}
}
F_33 ( & V_31 ) ;
return 0 ;
}
static int F_173 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
const struct V_18 * V_20 ;
struct V_29 * V_30 ;
struct V_117 * V_118 ;
char V_347 [ V_169 ] ;
struct V_42 * V_308 [ V_309 + 1 ] ;
int V_27 ;
F_31 ( V_31 ) ;
V_27 = F_128 ( V_77 , sizeof( * V_118 ) , V_308 , V_309 , V_313 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_308 [ V_207 ] )
F_169 ( V_347 , V_308 [ V_207 ] , V_169 ) ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_205 > 0 )
V_30 = F_146 ( V_28 , V_118 -> V_205 ) ;
else if ( V_308 [ V_207 ] )
V_30 = F_170 ( V_28 , V_347 ) ;
else if ( V_308 [ V_216 ] )
return F_171 ( V_28 , F_129 ( V_308 [ V_216 ] ) ) ;
else
return - V_326 ;
if ( ! V_30 )
return - V_358 ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_185 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
return 0 ;
}
int F_174 ( struct V_29 * V_30 , const struct V_117 * V_118 )
{
unsigned int V_376 ;
int V_27 ;
V_376 = V_30 -> V_78 ;
if ( V_118 && ( V_118 -> V_119 || V_118 -> V_120 ) ) {
V_27 = F_175 ( V_30 , F_87 ( V_30 , V_118 ) ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_30 -> V_377 = V_378 ;
F_176 ( V_30 , V_376 , ~ 0U ) ;
return 0 ;
}
struct V_29 * F_177 ( struct V_28 * V_28 ,
const char * V_347 , unsigned char V_379 ,
const struct V_18 * V_20 , struct V_42 * V_308 [] )
{
int V_27 ;
struct V_29 * V_30 ;
unsigned int V_220 = 1 ;
unsigned int V_222 = 1 ;
if ( V_308 [ V_219 ] )
V_220 = F_129 ( V_308 [ V_219 ] ) ;
else if ( V_20 -> V_380 )
V_220 = V_20 -> V_380 () ;
if ( V_308 [ V_221 ] )
V_222 = F_129 ( V_308 [ V_221 ] ) ;
else if ( V_20 -> V_381 )
V_222 = V_20 -> V_381 () ;
V_27 = - V_363 ;
V_30 = F_178 ( V_20 -> V_382 , V_347 , V_379 ,
V_20 -> V_22 , V_220 , V_222 ) ;
if ( ! V_30 )
goto V_27;
F_179 ( V_30 , V_28 ) ;
V_30 -> V_18 = V_20 ;
V_30 -> V_377 = V_383 ;
if ( V_308 [ V_214 ] )
V_30 -> V_215 = F_129 ( V_308 [ V_214 ] ) ;
if ( V_308 [ V_242 ] ) {
memcpy ( V_30 -> V_243 , F_117 ( V_308 [ V_242 ] ) ,
F_141 ( V_308 [ V_242 ] ) ) ;
V_30 -> V_384 = V_385 ;
}
if ( V_308 [ V_244 ] )
memcpy ( V_30 -> V_245 , F_117 ( V_308 [ V_244 ] ) ,
F_141 ( V_308 [ V_244 ] ) ) ;
if ( V_308 [ V_208 ] )
V_30 -> V_209 = F_129 ( V_308 [ V_208 ] ) ;
if ( V_308 [ V_210 ] )
F_81 ( V_30 , F_164 ( V_308 [ V_210 ] ) ) ;
if ( V_308 [ V_212 ] )
V_30 -> V_213 = F_164 ( V_308 [ V_212 ] ) ;
if ( V_308 [ V_216 ] )
F_157 ( V_30 , F_129 ( V_308 [ V_216 ] ) ) ;
return V_30 ;
V_27:
return F_180 ( V_27 ) ;
}
static int F_181 ( const struct V_50 * V_51 ,
struct V_28 * V_28 , int V_69 ,
struct V_117 * V_118 ,
struct V_42 * * V_308 )
{
struct V_29 * V_30 , * V_374 ;
int V_27 ;
F_172 (net, dev, aux) {
if ( V_30 -> V_69 == V_69 ) {
V_27 = F_147 ( V_51 , V_30 , V_118 , V_308 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_182 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_386 = NULL ;
struct V_29 * V_30 ;
struct V_29 * V_40 = NULL ;
struct V_117 * V_118 ;
char V_19 [ V_387 ] ;
char V_347 [ V_169 ] ;
struct V_42 * V_308 [ V_309 + 1 ] ;
struct V_42 * V_64 [ V_388 + 1 ] ;
unsigned char V_379 = V_389 ;
int V_27 ;
#ifdef F_183
V_390:
#endif
V_27 = F_128 ( V_77 , sizeof( * V_118 ) , V_308 , V_309 , V_313 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_308 [ V_207 ] )
F_169 ( V_347 , V_308 [ V_207 ] , V_169 ) ;
else
V_347 [ 0 ] = '\0' ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_205 > 0 )
V_30 = F_146 ( V_28 , V_118 -> V_205 ) ;
else {
if ( V_347 [ 0 ] )
V_30 = F_170 ( V_28 , V_347 ) ;
else
V_30 = NULL ;
}
if ( V_30 ) {
V_40 = F_44 ( V_30 ) ;
if ( V_40 )
V_386 = V_40 -> V_18 ;
}
V_27 = F_140 ( V_30 , V_308 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_308 [ V_65 ] ) {
V_27 = F_165 ( V_64 , V_388 ,
V_308 [ V_65 ] , V_391 ) ;
if ( V_27 < 0 )
return V_27 ;
} else
memset ( V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_64 [ V_59 ] ) {
F_169 ( V_19 , V_64 [ V_59 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_42 * V_190 [ V_20 ? V_20 -> V_392 + 1 : 1 ] ;
struct V_42 * V_393 [ V_386 ? V_386 -> V_394 + 1 : 1 ] ;
struct V_42 * * V_58 = NULL ;
struct V_42 * * V_52 = NULL ;
struct V_28 * V_395 , * V_293 = NULL ;
if ( V_20 ) {
if ( V_20 -> V_392 && V_64 [ V_62 ] ) {
V_27 = F_165 ( V_190 , V_20 -> V_392 ,
V_64 [ V_62 ] ,
V_20 -> V_396 ) ;
if ( V_27 < 0 )
return V_27 ;
V_58 = V_190 ;
}
if ( V_20 -> V_397 ) {
V_27 = V_20 -> V_397 ( V_308 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_386 ) {
if ( V_386 -> V_394 &&
V_64 [ V_56 ] ) {
V_27 = F_165 ( V_393 ,
V_386 -> V_394 ,
V_64 [ V_56 ] ,
V_386 -> V_398 ) ;
if ( V_27 < 0 )
return V_27 ;
V_52 = V_393 ;
}
if ( V_386 -> V_399 ) {
V_27 = V_386 -> V_399 ( V_308 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_30 ) {
int V_348 = 0 ;
if ( V_77 -> V_400 & V_401 )
return - V_21 ;
if ( V_77 -> V_400 & V_402 )
return - V_185 ;
if ( V_64 [ V_62 ] ) {
if ( ! V_20 || V_20 != V_30 -> V_18 ||
! V_20 -> V_403 )
return - V_185 ;
V_27 = V_20 -> V_403 ( V_30 , V_308 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
V_348 |= V_359 ;
}
if ( V_64 [ V_56 ] ) {
if ( ! V_386 || ! V_386 -> V_404 )
return - V_185 ;
V_27 = V_386 -> V_404 ( V_40 , V_30 ,
V_308 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
V_348 |= V_359 ;
}
return F_147 ( V_51 , V_30 , V_118 , V_308 , V_347 , V_348 ) ;
}
if ( ! ( V_77 -> V_400 & V_405 ) ) {
if ( V_118 -> V_205 == 0 && V_308 [ V_216 ] )
return F_181 ( V_51 , V_28 ,
F_129 ( V_308 [ V_216 ] ) ,
V_118 , V_308 ) ;
return - V_358 ;
}
if ( V_308 [ V_240 ] || V_308 [ V_224 ] || V_308 [ V_406 ] )
return - V_185 ;
if ( ! V_20 ) {
#ifdef F_183
if ( V_19 [ 0 ] ) {
F_3 () ;
F_184 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_390;
}
#endif
return - V_185 ;
}
if ( ! V_20 -> V_22 )
return - V_185 ;
if ( ! V_347 [ 0 ] ) {
snprintf ( V_347 , V_169 , L_5 , V_20 -> V_19 ) ;
V_379 = V_407 ;
}
V_395 = F_136 ( V_28 , V_308 ) ;
if ( F_148 ( V_395 ) )
return F_149 ( V_395 ) ;
V_27 = - V_352 ;
if ( ! F_150 ( V_51 , V_395 -> V_350 , V_351 ) )
goto V_66;
if ( V_308 [ V_294 ] ) {
int V_93 = F_185 ( V_308 [ V_294 ] ) ;
V_293 = F_186 ( V_395 , V_93 ) ;
if ( ! V_293 ) {
V_27 = - V_326 ;
goto V_66;
}
V_27 = - V_352 ;
if ( ! F_150 ( V_51 , V_293 -> V_350 , V_351 ) )
goto V_66;
}
V_30 = F_177 ( V_293 ? : V_395 , V_347 ,
V_379 , V_20 , V_308 ) ;
if ( F_148 ( V_30 ) ) {
V_27 = F_149 ( V_30 ) ;
goto V_66;
}
V_30 -> V_206 = V_118 -> V_205 ;
if ( V_20 -> V_408 ) {
V_27 = V_20 -> V_408 ( V_293 ? : V_28 , V_30 , V_308 , V_58 ) ;
if ( V_27 < 0 ) {
if ( V_30 -> V_409 == V_410 )
F_187 ( V_30 ) ;
goto V_66;
}
} else {
V_27 = F_188 ( V_30 ) ;
if ( V_27 < 0 ) {
F_187 ( V_30 ) ;
goto V_66;
}
}
V_27 = F_174 ( V_30 , V_118 ) ;
if ( V_27 < 0 )
goto V_411;
if ( V_293 ) {
V_27 = F_152 ( V_30 , V_395 , V_347 ) ;
if ( V_27 < 0 )
goto V_411;
}
V_66:
if ( V_293 )
F_151 ( V_293 ) ;
F_151 ( V_395 ) ;
return V_27 ;
V_411:
if ( V_20 -> V_408 ) {
F_31 ( V_31 ) ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
} else {
F_189 ( V_30 ) ;
}
goto V_66;
}
}
static int F_190 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
struct V_117 * V_118 ;
char V_347 [ V_169 ] ;
struct V_42 * V_308 [ V_309 + 1 ] ;
struct V_29 * V_30 = NULL ;
struct V_50 * V_412 ;
int V_27 ;
T_5 V_149 = 0 ;
V_27 = F_128 ( V_77 , sizeof( * V_118 ) , V_308 , V_309 , V_313 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_308 [ V_207 ] )
F_169 ( V_347 , V_308 [ V_207 ] , V_169 ) ;
if ( V_308 [ V_314 ] )
V_149 = F_129 ( V_308 [ V_314 ] ) ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_205 > 0 )
V_30 = F_146 ( V_28 , V_118 -> V_205 ) ;
else if ( V_308 [ V_207 ] )
V_30 = F_170 ( V_28 , V_347 ) ;
else
return - V_326 ;
if ( V_30 == NULL )
return - V_358 ;
V_412 = F_191 ( F_94 ( V_30 , V_149 ) , V_15 ) ;
if ( V_412 == NULL )
return - V_16 ;
V_27 = F_105 ( V_412 , V_30 , V_318 , F_61 ( V_51 ) . V_319 ,
V_77 -> V_320 , 0 , 0 , V_149 ) ;
if ( V_27 < 0 ) {
F_131 ( V_27 == - V_54 ) ;
F_192 ( V_412 ) ;
} else
V_27 = F_65 ( V_412 , V_28 , F_61 ( V_51 ) . V_319 ) ;
return V_27 ;
}
static T_8 F_193 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
struct V_29 * V_30 ;
struct V_42 * V_308 [ V_309 + 1 ] ;
T_5 V_149 = 0 ;
T_8 V_413 = 0 ;
int V_310 ;
V_310 = F_127 ( V_77 ) < sizeof( struct V_117 ) ?
sizeof( struct V_312 ) : sizeof( struct V_117 ) ;
if ( F_128 ( V_77 , V_310 , V_308 , V_309 , V_313 ) >= 0 ) {
if ( V_308 [ V_314 ] )
V_149 = F_129 ( V_308 [ V_314 ] ) ;
}
if ( ! V_149 )
return V_414 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_413 = F_194 ( T_8 , V_413 ,
F_94 ( V_30 ,
V_149 ) ) ;
}
return V_413 ;
}
static int F_195 ( struct V_50 * V_51 , struct V_299 * V_300 )
{
int V_304 ;
int V_305 = V_300 -> V_47 ;
if ( V_305 == 0 )
V_305 = 1 ;
for ( V_304 = 1 ; V_304 <= V_9 ; V_304 ++ ) {
int type = V_300 -> V_77 -> V_415 - V_4 ;
if ( V_304 < V_305 || V_304 == V_416 )
continue;
if ( V_10 [ V_304 ] == NULL ||
V_10 [ V_304 ] [ type ] . V_13 == NULL )
continue;
if ( V_304 > V_305 ) {
memset ( & V_300 -> args [ 0 ] , 0 , sizeof( V_300 -> args ) ) ;
V_300 -> V_417 = 0 ;
V_300 -> V_195 = 0 ;
}
if ( V_10 [ V_304 ] [ type ] . V_13 ( V_51 , V_300 ) )
break;
}
V_300 -> V_47 = V_304 ;
return V_51 -> V_322 ;
}
struct V_50 * F_196 ( int type , struct V_29 * V_30 ,
unsigned int V_196 , T_6 V_78 )
{
struct V_28 * V_28 = F_120 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
T_4 V_418 ;
V_51 = F_191 ( ( V_418 = F_94 ( V_30 , 0 ) ) , V_78 ) ;
if ( V_51 == NULL )
goto V_349;
V_27 = F_105 ( V_51 , V_30 , type , 0 , 0 , V_196 , 0 , 0 ) ;
if ( V_27 < 0 ) {
F_131 ( V_27 == - V_54 ) ;
F_192 ( V_51 ) ;
goto V_349;
}
return V_51 ;
V_349:
if ( V_27 < 0 )
F_70 ( V_28 , V_419 , V_27 ) ;
return NULL ;
}
void F_197 ( struct V_50 * V_51 , struct V_29 * V_30 , T_6 V_78 )
{
struct V_28 * V_28 = F_120 ( V_30 ) ;
F_67 ( V_51 , V_28 , 0 , V_419 , NULL , V_78 ) ;
}
void F_198 ( int type , struct V_29 * V_30 , unsigned int V_196 ,
T_6 V_78 )
{
struct V_50 * V_51 ;
if ( V_30 -> V_409 != V_420 )
return;
V_51 = F_196 ( type , V_30 , V_196 , V_78 ) ;
if ( V_51 )
F_197 ( V_51 , V_30 , V_78 ) ;
}
static int F_199 ( struct V_50 * V_51 ,
struct V_29 * V_30 ,
T_9 * V_421 , T_8 V_422 , T_5 V_68 , T_5 V_195 ,
int type , unsigned int V_78 ,
int V_423 )
{
struct V_76 * V_77 ;
struct V_424 * V_425 ;
V_77 = F_107 ( V_51 , V_68 , V_195 , type , sizeof( * V_425 ) , V_423 ) ;
if ( ! V_77 )
return - V_54 ;
V_425 = F_108 ( V_77 ) ;
V_425 -> V_426 = V_427 ;
V_425 -> V_428 = 0 ;
V_425 -> V_429 = 0 ;
V_425 -> V_430 = V_78 ;
V_425 -> V_431 = 0 ;
V_425 -> V_432 = V_30 -> V_206 ;
V_425 -> V_433 = V_434 ;
if ( F_80 ( V_51 , V_435 , V_436 , V_421 ) )
goto V_90;
if ( V_422 )
if ( F_80 ( V_51 , V_437 , sizeof( T_8 ) , & V_422 ) )
goto V_90;
F_123 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_124 ( V_51 , V_77 ) ;
return - V_54 ;
}
static inline T_4 F_200 ( void )
{
return F_95 ( sizeof( struct V_424 ) ) + F_45 ( V_436 ) ;
}
static void F_201 ( struct V_29 * V_30 , T_9 * V_421 , T_8 V_422 , int type )
{
struct V_28 * V_28 = F_120 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
V_51 = F_191 ( F_200 () , V_438 ) ;
if ( ! V_51 )
goto V_349;
V_27 = F_199 ( V_51 , V_30 , V_421 , V_422 ,
0 , 0 , type , V_439 , 0 ) ;
if ( V_27 < 0 ) {
F_192 ( V_51 ) ;
goto V_349;
}
F_67 ( V_51 , V_28 , 0 , V_440 , NULL , V_438 ) ;
return;
V_349:
F_70 ( V_28 , V_440 , V_27 ) ;
}
int F_202 ( struct V_424 * V_425 ,
struct V_42 * V_308 [] ,
struct V_29 * V_30 ,
const unsigned char * V_421 , T_8 V_422 ,
T_8 V_78 )
{
int V_27 = - V_326 ;
if ( V_425 -> V_433 && ! ( V_425 -> V_433 & V_434 ) ) {
F_203 ( L_6 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( V_422 ) {
F_203 ( L_7 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( F_204 ( V_421 ) || F_205 ( V_421 ) )
V_27 = F_206 ( V_30 , V_421 ) ;
else if ( F_207 ( V_421 ) )
V_27 = F_208 ( V_30 , V_421 ) ;
if ( V_27 == - V_21 && ! ( V_78 & V_401 ) )
V_27 = 0 ;
return V_27 ;
}
static int F_209 ( struct V_42 * V_441 , T_8 * V_442 )
{
T_8 V_422 = 0 ;
if ( V_441 ) {
if ( F_141 ( V_441 ) != sizeof( T_8 ) ) {
F_203 ( L_8 ) ;
return - V_326 ;
}
V_422 = F_210 ( V_441 ) ;
if ( ! V_422 || V_422 >= V_443 ) {
F_203 ( L_9 ,
V_422 ) ;
return - V_326 ;
}
}
* V_442 = V_422 ;
return 0 ;
}
static int F_211 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
struct V_424 * V_425 ;
struct V_42 * V_308 [ V_444 + 1 ] ;
struct V_29 * V_30 ;
T_9 * V_421 ;
T_8 V_422 ;
int V_27 ;
V_27 = F_128 ( V_77 , sizeof( * V_425 ) , V_308 , V_444 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_425 = F_108 ( V_77 ) ;
if ( V_425 -> V_432 == 0 ) {
F_203 ( L_10 ) ;
return - V_326 ;
}
V_30 = F_146 ( V_28 , V_425 -> V_432 ) ;
if ( V_30 == NULL ) {
F_203 ( L_11 ) ;
return - V_358 ;
}
if ( ! V_308 [ V_435 ] || F_141 ( V_308 [ V_435 ] ) != V_436 ) {
F_203 ( L_12 ) ;
return - V_326 ;
}
V_421 = F_117 ( V_308 [ V_435 ] ) ;
V_27 = F_209 ( V_308 [ V_437 ] , & V_422 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_185 ;
if ( ( ! V_425 -> V_430 || V_425 -> V_430 & V_445 ) &&
( V_30 -> V_446 & V_447 ) ) {
struct V_29 * V_448 = F_44 ( V_30 ) ;
const struct V_331 * V_20 = V_448 -> V_167 ;
V_27 = V_20 -> V_449 ( V_425 , V_308 , V_30 , V_421 , V_422 ,
V_77 -> V_400 ) ;
if ( V_27 )
goto V_66;
else
V_425 -> V_430 &= ~ V_445 ;
}
if ( ( V_425 -> V_430 & V_439 ) ) {
if ( V_30 -> V_167 -> V_449 )
V_27 = V_30 -> V_167 -> V_449 ( V_425 , V_308 , V_30 , V_421 ,
V_422 ,
V_77 -> V_400 ) ;
else
V_27 = F_202 ( V_425 , V_308 , V_30 , V_421 , V_422 ,
V_77 -> V_400 ) ;
if ( ! V_27 ) {
F_201 ( V_30 , V_421 , V_422 , V_450 ) ;
V_425 -> V_430 &= ~ V_439 ;
}
}
V_66:
return V_27 ;
}
int F_212 ( struct V_424 * V_425 ,
struct V_42 * V_308 [] ,
struct V_29 * V_30 ,
const unsigned char * V_421 , T_8 V_422 )
{
int V_27 = - V_326 ;
if ( ! ( V_425 -> V_433 & V_434 ) ) {
F_203 ( L_6 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( F_204 ( V_421 ) || F_205 ( V_421 ) )
V_27 = F_213 ( V_30 , V_421 ) ;
else if ( F_207 ( V_421 ) )
V_27 = F_214 ( V_30 , V_421 ) ;
return V_27 ;
}
static int F_215 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
struct V_424 * V_425 ;
struct V_42 * V_308 [ V_444 + 1 ] ;
struct V_29 * V_30 ;
int V_27 = - V_326 ;
T_10 * V_421 ;
T_8 V_422 ;
if ( ! F_216 ( V_51 , V_351 ) )
return - V_352 ;
V_27 = F_128 ( V_77 , sizeof( * V_425 ) , V_308 , V_444 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_425 = F_108 ( V_77 ) ;
if ( V_425 -> V_432 == 0 ) {
F_203 ( L_13 ) ;
return - V_326 ;
}
V_30 = F_146 ( V_28 , V_425 -> V_432 ) ;
if ( V_30 == NULL ) {
F_203 ( L_14 ) ;
return - V_358 ;
}
if ( ! V_308 [ V_435 ] || F_141 ( V_308 [ V_435 ] ) != V_436 ) {
F_203 ( L_15 ) ;
return - V_326 ;
}
V_421 = F_117 ( V_308 [ V_435 ] ) ;
V_27 = F_209 ( V_308 [ V_437 ] , & V_422 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_185 ;
if ( ( ! V_425 -> V_430 || V_425 -> V_430 & V_445 ) &&
( V_30 -> V_446 & V_447 ) ) {
struct V_29 * V_448 = F_44 ( V_30 ) ;
const struct V_331 * V_20 = V_448 -> V_167 ;
if ( V_20 -> V_451 )
V_27 = V_20 -> V_451 ( V_425 , V_308 , V_30 , V_421 , V_422 ) ;
if ( V_27 )
goto V_66;
else
V_425 -> V_430 &= ~ V_445 ;
}
if ( V_425 -> V_430 & V_439 ) {
if ( V_30 -> V_167 -> V_451 )
V_27 = V_30 -> V_167 -> V_451 ( V_425 , V_308 , V_30 , V_421 ,
V_422 ) ;
else
V_27 = F_212 ( V_425 , V_308 , V_30 , V_421 , V_422 ) ;
if ( ! V_27 ) {
F_201 ( V_30 , V_421 , V_422 , V_452 ) ;
V_425 -> V_430 &= ~ V_439 ;
}
}
V_66:
return V_27 ;
}
static int F_217 ( struct V_50 * V_51 ,
struct V_299 * V_300 ,
struct V_29 * V_30 ,
int * V_304 ,
struct V_453 * V_25 )
{
struct V_454 * V_455 ;
int V_27 ;
T_5 V_319 , V_195 ;
V_319 = F_61 ( V_300 -> V_51 ) . V_319 ;
V_195 = V_300 -> V_77 -> V_320 ;
F_26 (ha, &list->list, list) {
if ( * V_304 < V_300 -> args [ 0 ] )
goto V_456;
V_27 = F_199 ( V_51 , V_30 , V_455 -> V_421 , 0 ,
V_319 , V_195 ,
V_450 , V_439 ,
V_321 ) ;
if ( V_27 < 0 )
return V_27 ;
V_456:
* V_304 += 1 ;
}
return 0 ;
}
int F_218 ( struct V_50 * V_51 ,
struct V_299 * V_300 ,
struct V_29 * V_30 ,
struct V_29 * V_457 ,
int V_304 )
{
int V_27 ;
F_219 ( V_30 ) ;
V_27 = F_217 ( V_51 , V_300 , V_30 , & V_304 , & V_30 -> V_458 ) ;
if ( V_27 )
goto V_66;
F_217 ( V_51 , V_300 , V_30 , & V_304 , & V_30 -> V_459 ) ;
V_66:
F_220 ( V_30 ) ;
return V_304 ;
}
static int F_221 ( struct V_50 * V_51 , struct V_299 * V_300 )
{
struct V_29 * V_30 ;
struct V_42 * V_308 [ V_309 + 1 ] ;
struct V_29 * V_448 = NULL ;
const struct V_331 * V_20 = NULL ;
const struct V_331 * V_460 = NULL ;
struct V_117 * V_118 = F_108 ( V_300 -> V_77 ) ;
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
int V_461 = 0 ;
int V_462 = 0 ;
int V_304 = 0 ;
if ( F_128 ( V_300 -> V_77 , sizeof( struct V_117 ) , V_308 , V_309 ,
V_313 ) == 0 ) {
if ( V_308 [ V_224 ] )
V_462 = F_129 ( V_308 [ V_224 ] ) ;
}
V_461 = V_118 -> V_205 ;
if ( V_462 ) {
V_448 = F_146 ( V_28 , V_462 ) ;
if ( ! V_448 )
return - V_358 ;
V_20 = V_448 -> V_167 ;
}
F_32 (net, dev) {
if ( V_461 && ( V_30 -> V_206 != V_461 ) )
continue;
if ( ! V_462 ) {
if ( V_30 -> V_446 & V_447 ) {
V_448 = F_44 ( V_30 ) ;
V_460 = V_448 -> V_167 ;
}
} else {
if ( V_30 != V_448 &&
! ( V_30 -> V_446 & V_447 ) )
continue;
if ( V_448 != F_44 ( V_30 ) &&
! ( V_30 -> V_446 & V_463 ) )
continue;
V_460 = V_20 ;
}
if ( V_30 -> V_446 & V_447 ) {
if ( V_460 && V_460 -> V_464 )
V_304 = V_460 -> V_464 ( V_51 , V_300 , V_448 , V_30 ,
V_304 ) ;
}
if ( V_30 -> V_167 -> V_464 )
V_304 = V_30 -> V_167 -> V_464 ( V_51 , V_300 , V_30 , NULL ,
V_304 ) ;
else
V_304 = F_218 ( V_51 , V_300 , V_30 , NULL , V_304 ) ;
V_460 = NULL ;
}
V_300 -> args [ 0 ] = V_304 ;
return V_51 -> V_322 ;
}
static int F_222 ( struct V_50 * V_51 , T_5 V_78 , T_5 V_465 ,
unsigned int V_466 , unsigned int V_467 )
{
if ( V_465 & V_467 )
return F_110 ( V_51 , V_466 , ! ! ( V_78 & V_467 ) ) ;
return 0 ;
}
int F_223 ( struct V_50 * V_51 , T_5 V_68 , T_5 V_195 ,
struct V_29 * V_30 , T_8 V_468 ,
T_5 V_78 , T_5 V_465 , int V_423 ,
T_5 V_469 ,
int (* F_224)( struct V_50 * V_51 ,
struct V_29 * V_30 ,
T_5 V_469 ) )
{
struct V_76 * V_77 ;
struct V_117 * V_118 ;
struct V_42 * V_470 ;
struct V_42 * V_471 ;
T_9 V_109 = F_111 ( V_30 ) ? V_30 -> V_109 : V_211 ;
struct V_29 * V_448 = F_44 ( V_30 ) ;
int V_27 = 0 ;
V_77 = F_107 ( V_51 , V_68 , V_195 , V_318 , sizeof( * V_118 ) , V_423 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_118 = F_108 ( V_77 ) ;
V_118 -> V_201 = V_427 ;
V_118 -> V_203 = 0 ;
V_118 -> V_204 = V_30 -> type ;
V_118 -> V_205 = V_30 -> V_206 ;
V_118 -> V_119 = F_109 ( V_30 ) ;
V_118 -> V_120 = 0 ;
if ( F_54 ( V_51 , V_207 , V_30 -> V_89 ) ||
F_74 ( V_51 , V_214 , V_30 -> V_215 ) ||
F_110 ( V_51 , V_210 , V_109 ) ||
( V_448 &&
F_74 ( V_51 , V_224 , V_448 -> V_206 ) ) ||
( V_30 -> V_241 &&
F_80 ( V_51 , V_242 , V_30 -> V_241 , V_30 -> V_243 ) ) ||
( V_30 -> V_206 != F_113 ( V_30 ) &&
F_74 ( V_51 , V_223 , F_113 ( V_30 ) ) ) )
goto V_90;
V_470 = F_55 ( V_51 , V_295 ) ;
if ( ! V_470 )
goto V_90;
if ( F_225 ( V_51 , V_472 , V_473 ) ) {
F_57 ( V_51 , V_470 ) ;
goto V_90;
}
if ( V_468 != V_474 ) {
if ( F_225 ( V_51 , V_475 , V_468 ) ) {
F_57 ( V_51 , V_470 ) ;
goto V_90;
}
}
if ( F_224 ) {
V_27 = F_224 ( V_51 , V_30 , V_469 ) ;
if ( V_27 ) {
F_57 ( V_51 , V_470 ) ;
goto V_90;
}
}
F_56 ( V_51 , V_470 ) ;
V_471 = F_55 ( V_51 , V_406 | V_476 ) ;
if ( ! V_471 )
goto V_90;
if ( F_222 ( V_51 , V_78 , V_465 ,
V_477 , V_478 ) ||
F_222 ( V_51 , V_78 , V_465 ,
V_479 , V_480 ) ||
F_222 ( V_51 , V_78 , V_465 ,
V_481 ,
V_482 ) ||
F_222 ( V_51 , V_78 , V_465 ,
V_483 , V_484 ) ||
F_222 ( V_51 , V_78 , V_465 ,
V_485 , V_486 ) ||
F_222 ( V_51 , V_78 , V_465 ,
V_487 , V_488 ) ||
F_222 ( V_51 , V_78 , V_465 ,
V_489 , V_490 ) ||
F_222 ( V_51 , V_78 , V_465 ,
V_491 , V_492 ) ) {
F_57 ( V_51 , V_471 ) ;
goto V_90;
}
F_56 ( V_51 , V_471 ) ;
F_123 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_124 ( V_51 , V_77 ) ;
return V_27 ? V_27 : - V_54 ;
}
static int F_226 ( struct V_50 * V_51 , struct V_299 * V_300 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
struct V_29 * V_30 ;
int V_304 = 0 ;
T_5 V_319 = F_61 ( V_300 -> V_51 ) . V_319 ;
T_5 V_195 = V_300 -> V_77 -> V_320 ;
T_5 V_469 = 0 ;
if ( F_127 ( V_300 -> V_77 ) > sizeof( struct V_117 ) ) {
struct V_42 * V_493 ;
V_493 = F_227 ( V_300 -> V_77 , sizeof( struct V_117 ) ,
V_314 ) ;
if ( V_493 ) {
if ( F_141 ( V_493 ) < sizeof( V_469 ) )
return - V_326 ;
V_469 = F_129 ( V_493 ) ;
}
}
F_228 () ;
F_229 (net, dev) {
const struct V_331 * V_20 = V_30 -> V_167 ;
struct V_29 * V_448 = F_44 ( V_30 ) ;
if ( V_448 && V_448 -> V_167 -> V_494 ) {
if ( V_304 >= V_300 -> args [ 0 ] &&
V_448 -> V_167 -> V_494 (
V_51 , V_319 , V_195 , V_30 , V_469 ,
V_321 ) < 0 )
break;
V_304 ++ ;
}
if ( V_20 -> V_494 ) {
if ( V_304 >= V_300 -> args [ 0 ] &&
V_20 -> V_494 ( V_51 , V_319 , V_195 , V_30 ,
V_469 ,
V_321 ) < 0 )
break;
V_304 ++ ;
}
}
F_230 () ;
V_300 -> args [ 0 ] = V_304 ;
return V_51 -> V_322 ;
}
static inline T_4 F_231 ( void )
{
return F_95 ( sizeof( struct V_117 ) )
+ F_45 ( V_169 )
+ F_45 ( V_172 )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_9 ) )
+ F_45 ( sizeof( struct V_42 ) )
+ F_45 ( sizeof( T_8 ) )
+ F_45 ( sizeof( T_8 ) ) ;
}
static int F_232 ( struct V_29 * V_30 )
{
struct V_28 * V_28 = F_120 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_185 ;
if ( ! V_30 -> V_167 -> V_494 )
return 0 ;
V_51 = F_191 ( F_231 () , V_438 ) ;
if ( ! V_51 ) {
V_27 = - V_363 ;
goto V_349;
}
V_27 = V_30 -> V_167 -> V_494 ( V_51 , 0 , 0 , V_30 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_349;
if ( ! V_51 -> V_322 )
goto V_349;
F_67 ( V_51 , V_28 , 0 , V_419 , NULL , V_438 ) ;
return 0 ;
V_349:
F_131 ( V_27 == - V_54 ) ;
F_192 ( V_51 ) ;
if ( V_27 )
F_70 ( V_28 , V_419 , V_27 ) ;
return V_27 ;
}
static int F_233 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
struct V_117 * V_118 ;
struct V_29 * V_30 ;
struct V_42 * V_495 , * V_190 = NULL ;
int V_327 , V_27 = - V_185 ;
T_8 V_78 = 0 ;
bool V_496 = false ;
if ( F_127 ( V_77 ) < sizeof( * V_118 ) )
return - V_326 ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_201 != V_427 )
return - V_497 ;
V_30 = F_146 ( V_28 , V_118 -> V_205 ) ;
if ( ! V_30 ) {
F_203 ( L_16 ) ;
return - V_358 ;
}
V_495 = F_227 ( V_77 , sizeof( struct V_117 ) , V_295 ) ;
if ( V_495 ) {
F_142 (attr, br_spec, rem) {
if ( F_143 ( V_190 ) == V_472 ) {
if ( F_141 ( V_190 ) < sizeof( V_78 ) )
return - V_326 ;
V_496 = true ;
V_78 = F_210 ( V_190 ) ;
break;
}
}
}
if ( ! V_78 || ( V_78 & V_498 ) ) {
struct V_29 * V_448 = F_44 ( V_30 ) ;
if ( ! V_448 || ! V_448 -> V_167 -> V_499 ) {
V_27 = - V_185 ;
goto V_66;
}
V_27 = V_448 -> V_167 -> V_499 ( V_30 , V_77 , V_78 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_498 ;
}
if ( ( V_78 & V_473 ) ) {
if ( ! V_30 -> V_167 -> V_499 )
V_27 = - V_185 ;
else
V_27 = V_30 -> V_167 -> V_499 ( V_30 , V_77 ,
V_78 ) ;
if ( ! V_27 ) {
V_78 &= ~ V_473 ;
V_27 = F_232 ( V_30 ) ;
}
}
if ( V_496 )
memcpy ( F_117 ( V_190 ) , & V_78 , sizeof( V_78 ) ) ;
V_66:
return V_27 ;
}
static int F_234 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
struct V_117 * V_118 ;
struct V_29 * V_30 ;
struct V_42 * V_495 , * V_190 = NULL ;
int V_327 , V_27 = - V_185 ;
T_8 V_78 = 0 ;
bool V_496 = false ;
if ( F_127 ( V_77 ) < sizeof( * V_118 ) )
return - V_326 ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_201 != V_427 )
return - V_497 ;
V_30 = F_146 ( V_28 , V_118 -> V_205 ) ;
if ( ! V_30 ) {
F_203 ( L_16 ) ;
return - V_358 ;
}
V_495 = F_227 ( V_77 , sizeof( struct V_117 ) , V_295 ) ;
if ( V_495 ) {
F_142 (attr, br_spec, rem) {
if ( F_143 ( V_190 ) == V_472 ) {
if ( F_141 ( V_190 ) < sizeof( V_78 ) )
return - V_326 ;
V_496 = true ;
V_78 = F_210 ( V_190 ) ;
break;
}
}
}
if ( ! V_78 || ( V_78 & V_498 ) ) {
struct V_29 * V_448 = F_44 ( V_30 ) ;
if ( ! V_448 || ! V_448 -> V_167 -> V_500 ) {
V_27 = - V_185 ;
goto V_66;
}
V_27 = V_448 -> V_167 -> V_500 ( V_30 , V_77 , V_78 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_498 ;
}
if ( ( V_78 & V_473 ) ) {
if ( ! V_30 -> V_167 -> V_500 )
V_27 = - V_185 ;
else
V_27 = V_30 -> V_167 -> V_500 ( V_30 , V_77 ,
V_78 ) ;
if ( ! V_27 ) {
V_78 &= ~ V_473 ;
V_27 = F_232 ( V_30 ) ;
}
}
if ( V_496 )
memcpy ( F_117 ( V_190 ) , & V_78 , sizeof( V_78 ) ) ;
V_66:
return V_27 ;
}
static int F_235 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_126 ( V_51 -> V_301 ) ;
T_1 V_11 ;
int V_501 , V_19 ;
int V_47 ;
int type ;
int V_27 ;
type = V_77 -> V_415 ;
if ( type > V_502 )
return - V_185 ;
type -= V_4 ;
if ( F_127 ( V_77 ) < sizeof( struct V_312 ) )
return 0 ;
V_47 = ( (struct V_312 * ) F_108 ( V_77 ) ) -> V_503 ;
V_501 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_236 ( V_51 , V_351 ) )
return - V_352 ;
if ( V_19 == 2 && V_77 -> V_400 & V_504 ) {
struct V_71 * V_72 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_505 = 0 ;
V_13 = F_16 ( V_47 , type ) ;
if ( V_13 == NULL )
return - V_185 ;
V_14 = F_17 ( V_47 , type ) ;
if ( V_14 )
V_505 = V_14 ( V_51 , V_77 ) ;
F_3 () ;
V_72 = V_28 -> V_72 ;
{
struct V_506 V_507 = {
. V_508 = V_13 ,
. V_505 = V_505 ,
} ;
V_27 = F_237 ( V_72 , V_51 , V_77 , & V_507 ) ;
}
F_1 () ;
return V_27 ;
}
V_11 = F_15 ( V_47 , type ) ;
if ( V_11 == NULL )
return - V_185 ;
return V_11 ( V_51 , V_77 ) ;
}
static void F_238 ( struct V_50 * V_51 )
{
F_1 () ;
F_239 ( V_51 , & F_235 ) ;
F_5 () ;
}
static int F_240 ( struct V_509 * V_510 , unsigned long V_511 , void * V_512 )
{
struct V_29 * V_30 = F_241 ( V_512 ) ;
switch ( V_511 ) {
case V_513 :
case V_514 :
case V_515 :
case V_516 :
case V_517 :
case V_518 :
case V_519 :
case V_520 :
case V_521 :
case V_522 :
case V_523 :
case V_524 :
case V_525 :
break;
default:
F_198 ( V_318 , V_30 , 0 , V_15 ) ;
break;
}
return V_526 ;
}
static int T_11 F_242 ( struct V_28 * V_28 )
{
struct V_71 * V_301 ;
struct V_527 V_528 = {
. V_529 = V_530 ,
. V_531 = F_238 ,
. V_532 = & V_1 ,
. V_78 = V_533 ,
} ;
V_301 = F_243 ( V_28 , V_534 , & V_528 ) ;
if ( ! V_301 )
return - V_363 ;
V_28 -> V_72 = V_301 ;
return 0 ;
}
static void T_12 F_244 ( struct V_28 * V_28 )
{
F_245 ( V_28 -> V_72 ) ;
V_28 -> V_72 = NULL ;
}
void T_13 F_246 ( void )
{
if ( F_247 ( & V_535 ) )
F_21 ( L_17 ) ;
F_248 ( & V_536 ) ;
F_20 ( V_12 , V_537 , F_190 ,
F_125 , F_193 ) ;
F_20 ( V_12 , V_538 , F_168 , NULL , NULL ) ;
F_20 ( V_12 , V_318 , F_182 , NULL , NULL ) ;
F_20 ( V_12 , V_539 , F_173 , NULL , NULL ) ;
F_20 ( V_12 , V_540 , NULL , F_195 , NULL ) ;
F_20 ( V_12 , V_541 , NULL , F_195 , NULL ) ;
F_20 ( V_542 , V_450 , F_211 , NULL , NULL ) ;
F_20 ( V_542 , V_452 , F_215 , NULL , NULL ) ;
F_20 ( V_542 , V_543 , NULL , F_221 , NULL ) ;
F_20 ( V_542 , V_537 , NULL , F_226 , NULL ) ;
F_20 ( V_542 , V_539 , F_234 , NULL , NULL ) ;
F_20 ( V_542 , V_538 , F_233 , NULL , NULL ) ;
}
