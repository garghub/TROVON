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
F_45 ( sizeof( struct V_157 ) ) ) ;
return V_43 ;
} else
return 0 ;
}
static T_4 F_93 ( const struct V_29 * V_30 ,
T_5 V_149 )
{
T_4 V_158 = F_45 ( 4 )
+ F_45 ( V_159 )
+ F_45 ( sizeof( struct V_160 ) )
+ F_45 ( V_161 )
+ F_45 ( V_161 )
+ F_45 ( 1 )
+ F_45 ( 2 ) ;
T_4 V_162 = F_45 ( sizeof( struct V_42 ) ) ;
T_4 V_163 = F_45 ( sizeof( struct V_42 ) )
+ V_158 ;
T_4 V_164 = F_45 ( sizeof( struct V_42 ) )
+ V_158 ;
if ( ! V_30 -> V_165 -> V_166 || ! V_30 -> V_30 . V_150 ||
! ( V_149 & V_151 ) )
return 0 ;
if ( F_92 ( V_30 -> V_30 . V_150 ) )
return V_164 + V_162 +
V_163 * F_92 ( V_30 -> V_30 . V_150 ) ;
else
return V_164 ;
}
static T_7 T_4 F_94 ( const struct V_29 * V_30 ,
T_5 V_149 )
{
return F_95 ( sizeof( struct V_117 ) )
+ F_45 ( V_167 )
+ F_45 ( V_168 )
+ F_45 ( V_167 )
+ F_45 ( sizeof( struct V_169 ) )
+ F_45 ( sizeof( struct V_121 ) )
+ F_45 ( sizeof( struct V_123 ) )
+ F_45 ( V_170 )
+ F_45 ( V_170 )
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
+ F_45 ( V_171 )
+ F_45 ( V_171 ) ;
}
static int F_96 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_172 ;
struct V_42 * V_173 ;
int V_174 ;
int V_27 ;
V_172 = F_55 ( V_51 , V_175 ) ;
if ( ! V_172 )
return - V_54 ;
for ( V_174 = 0 ; V_174 < F_92 ( V_30 -> V_30 . V_150 ) ; V_174 ++ ) {
V_173 = F_55 ( V_51 , V_176 ) ;
if ( ! V_173 )
goto V_90;
if ( F_74 ( V_51 , V_177 , V_174 ) )
goto V_90;
V_27 = V_30 -> V_165 -> V_166 ( V_30 , V_174 , V_51 ) ;
if ( V_27 == - V_54 )
goto V_90;
if ( V_27 ) {
F_57 ( V_51 , V_173 ) ;
continue;
}
F_56 ( V_51 , V_173 ) ;
}
F_56 ( V_51 , V_172 ) ;
return 0 ;
V_90:
F_57 ( V_51 , V_172 ) ;
return - V_54 ;
}
static int F_97 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_178 ;
int V_27 ;
V_178 = F_55 ( V_51 , V_179 ) ;
if ( ! V_178 )
return - V_54 ;
V_27 = V_30 -> V_165 -> V_166 ( V_30 , V_180 , V_51 ) ;
if ( V_27 ) {
F_57 ( V_51 , V_178 ) ;
return ( V_27 == - V_54 ) ? V_27 : 0 ;
}
F_56 ( V_51 , V_178 ) ;
return 0 ;
}
static int F_98 ( struct V_50 * V_51 , struct V_29 * V_30 ,
T_5 V_149 )
{
int V_27 ;
if ( ! V_30 -> V_165 -> V_166 || ! V_30 -> V_30 . V_150 ||
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
struct V_181 V_182 ;
V_27 = F_100 ( V_30 , & V_182 ) ;
if ( V_27 ) {
if ( V_27 == - V_183 )
return 0 ;
return V_27 ;
}
if ( F_80 ( V_51 , V_184 , V_182 . V_185 , V_182 . V_93 ) )
return - V_54 ;
return 0 ;
}
static int F_101 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
int V_27 ;
struct V_181 V_186 ;
V_27 = F_102 ( V_30 , & V_186 ) ;
if ( V_27 ) {
if ( V_27 == - V_183 )
return 0 ;
return V_27 ;
}
if ( F_80 ( V_51 , V_187 , V_186 . V_185 , V_186 . V_93 ) )
return - V_54 ;
return 0 ;
}
static int F_103 ( struct V_50 * V_51 , struct V_29 * V_30 ,
int type , T_5 V_68 , T_5 V_188 , T_5 V_189 ,
unsigned int V_78 , T_5 V_149 )
{
struct V_117 * V_118 ;
struct V_76 * V_77 ;
struct V_123 V_190 ;
const struct V_123 * V_191 ;
struct V_42 * V_192 , * V_193 ;
struct V_46 * V_48 ;
struct V_29 * V_194 = F_44 ( V_30 ) ;
F_104 () ;
V_77 = F_105 ( V_51 , V_68 , V_188 , type , sizeof( * V_118 ) , V_78 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_118 = F_106 ( V_77 ) ;
V_118 -> V_195 = V_196 ;
V_118 -> V_197 = 0 ;
V_118 -> V_198 = V_30 -> type ;
V_118 -> V_199 = V_30 -> V_200 ;
V_118 -> V_119 = F_107 ( V_30 ) ;
V_118 -> V_120 = V_189 ;
if ( F_54 ( V_51 , V_201 , V_30 -> V_89 ) ||
F_74 ( V_51 , V_202 , V_30 -> V_203 ) ||
F_108 ( V_51 , V_204 ,
F_109 ( V_30 ) ? V_30 -> V_109 : V_205 ) ||
F_108 ( V_51 , V_206 , V_30 -> V_207 ) ||
F_74 ( V_51 , V_208 , V_30 -> V_209 ) ||
F_74 ( V_51 , V_210 , V_30 -> V_69 ) ||
F_74 ( V_51 , V_211 , V_30 -> V_212 ) ||
F_74 ( V_51 , V_213 , V_30 -> V_214 ) ||
#ifdef F_110
F_74 ( V_51 , V_215 , V_30 -> V_216 ) ||
#endif
( V_30 -> V_200 != V_30 -> V_217 &&
F_74 ( V_51 , V_218 , V_30 -> V_217 ) ) ||
( V_194 &&
F_74 ( V_51 , V_219 , V_194 -> V_200 ) ) ||
F_108 ( V_51 , V_220 , F_111 ( V_30 ) ) ||
( V_30 -> V_221 &&
F_54 ( V_51 , V_222 , V_30 -> V_221 -> V_20 -> V_93 ) ) ||
( V_30 -> V_223 &&
F_54 ( V_51 , V_224 , V_30 -> V_223 ) ) ||
F_74 ( V_51 , V_225 ,
F_77 ( & V_30 -> V_226 ) ) )
goto V_90;
if ( 1 ) {
struct V_169 V_227 = {
. V_228 = V_30 -> V_228 ,
. V_229 = V_30 -> V_229 ,
. V_230 = V_30 -> V_230 ,
. V_231 = V_30 -> V_231 ,
. V_232 = V_30 -> V_232 ,
. V_233 = V_30 -> V_234 ,
} ;
if ( F_80 ( V_51 , V_235 , sizeof( V_227 ) , & V_227 ) )
goto V_90;
}
if ( V_30 -> V_236 ) {
if ( F_80 ( V_51 , V_237 , V_30 -> V_236 , V_30 -> V_238 ) ||
F_80 ( V_51 , V_239 , V_30 -> V_236 , V_30 -> V_240 ) )
goto V_90;
}
if ( F_99 ( V_51 , V_30 ) )
goto V_90;
if ( F_101 ( V_51 , V_30 ) )
goto V_90;
V_192 = F_112 ( V_51 , V_241 ,
sizeof( struct V_121 ) ) ;
if ( V_192 == NULL )
goto V_90;
V_191 = F_113 ( V_30 , & V_190 ) ;
F_88 ( F_114 ( V_192 ) , V_191 ) ;
V_192 = F_112 ( V_51 , V_242 ,
sizeof( struct V_123 ) ) ;
if ( V_192 == NULL )
goto V_90;
F_89 ( F_114 ( V_192 ) , V_191 ) ;
if ( V_30 -> V_30 . V_150 && ( V_149 & V_151 ) &&
F_74 ( V_51 , V_243 , F_92 ( V_30 -> V_30 . V_150 ) ) )
goto V_90;
if ( V_30 -> V_165 -> V_244 && V_30 -> V_30 . V_150
&& ( V_149 & V_151 ) ) {
int V_82 ;
struct V_42 * V_245 , * V_174 ;
int V_152 = F_92 ( V_30 -> V_30 . V_150 ) ;
V_245 = F_55 ( V_51 , V_246 ) ;
if ( ! V_245 )
goto V_90;
for ( V_82 = 0 ; V_82 < V_152 ; V_82 ++ ) {
struct V_247 V_248 ;
struct V_153 V_249 ;
struct V_154 V_250 ;
struct V_156 V_251 ;
struct V_252 V_253 ;
struct V_155 V_254 ;
struct V_157 V_255 ;
V_248 . V_256 = - 1 ;
memset ( V_248 . V_257 , 0 , sizeof( V_248 . V_257 ) ) ;
V_248 . V_258 = 0 ;
if ( V_30 -> V_165 -> V_244 ( V_30 , V_82 , & V_248 ) )
break;
V_249 . V_174 =
V_250 . V_174 =
V_251 . V_174 =
V_253 . V_174 =
V_254 . V_174 =
V_255 . V_174 = V_248 . V_174 ;
memcpy ( V_249 . V_257 , V_248 . V_257 , sizeof( V_248 . V_257 ) ) ;
V_250 . V_259 = V_248 . V_259 ;
V_250 . V_260 = V_248 . V_260 ;
V_253 . V_261 = V_248 . V_262 ;
V_251 . V_263 = V_248 . V_263 ;
V_251 . V_262 = V_248 . V_262 ;
V_254 . V_264 = V_248 . V_256 ;
V_255 . V_265 = V_248 . V_258 ;
V_174 = F_55 ( V_51 , V_266 ) ;
if ( ! V_174 ) {
F_57 ( V_51 , V_245 ) ;
goto V_90;
}
if ( F_80 ( V_51 , V_267 , sizeof( V_249 ) , & V_249 ) ||
F_80 ( V_51 , V_268 , sizeof( V_250 ) , & V_250 ) ||
F_80 ( V_51 , V_269 , sizeof( V_251 ) ,
& V_251 ) ||
F_80 ( V_51 , V_270 , sizeof( V_253 ) ,
& V_253 ) ||
F_80 ( V_51 , V_271 , sizeof( V_254 ) ,
& V_254 ) ||
F_80 ( V_51 , V_272 , sizeof( V_255 ) ,
& V_255 ) )
goto V_90;
F_56 ( V_51 , V_174 ) ;
}
F_56 ( V_51 , V_245 ) ;
}
if ( F_98 ( V_51 , V_30 , V_149 ) )
goto V_90;
if ( V_30 -> V_18 || F_52 ( V_30 ) ) {
if ( F_59 ( V_51 , V_30 ) < 0 )
goto V_90;
}
if ( V_30 -> V_18 &&
V_30 -> V_18 -> V_273 ) {
struct V_28 * V_274 = V_30 -> V_18 -> V_273 ( V_30 ) ;
if ( ! F_115 ( F_116 ( V_30 ) , V_274 ) ) {
int V_93 = F_117 ( F_116 ( V_30 ) , V_274 ) ;
if ( F_118 ( V_51 , V_275 , V_93 ) )
goto V_90;
}
}
if ( ! ( V_193 = F_55 ( V_51 , V_276 ) ) )
goto V_90;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_48 -> V_277 ) {
struct V_42 * V_278 ;
int V_27 ;
if ( ! ( V_278 = F_55 ( V_51 , V_48 -> V_47 ) ) )
goto V_90;
V_27 = V_48 -> V_277 ( V_51 , V_30 ) ;
if ( V_27 == - V_279 )
F_57 ( V_51 , V_278 ) ;
else if ( V_27 < 0 )
goto V_90;
F_56 ( V_51 , V_278 ) ;
}
}
F_56 ( V_51 , V_193 ) ;
F_119 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_120 ( V_51 , V_77 ) ;
return - V_54 ;
}
static int F_121 ( struct V_50 * V_51 , struct V_280 * V_281 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
int V_283 , V_284 ;
int V_285 = 0 , V_286 ;
struct V_29 * V_30 ;
struct V_287 * V_288 ;
struct V_42 * V_289 [ V_290 + 1 ] ;
T_5 V_149 = 0 ;
int V_27 ;
int V_291 ;
V_284 = V_281 -> args [ 0 ] ;
V_286 = V_281 -> args [ 1 ] ;
V_281 -> V_188 = V_28 -> V_292 ;
V_291 = F_123 ( V_281 -> V_77 ) < sizeof( struct V_117 ) ?
sizeof( struct V_293 ) : sizeof( struct V_117 ) ;
if ( F_124 ( V_281 -> V_77 , V_291 , V_289 , V_290 , V_294 ) >= 0 ) {
if ( V_289 [ V_295 ] )
V_149 = F_125 ( V_289 [ V_295 ] ) ;
}
for ( V_283 = V_284 ; V_283 < V_296 ; V_283 ++ , V_286 = 0 ) {
V_285 = 0 ;
V_288 = & V_28 -> V_297 [ V_283 ] ;
F_126 (dev, head, index_hlist) {
if ( V_285 < V_286 )
goto V_298;
V_27 = F_103 ( V_51 , V_30 , V_299 ,
F_61 ( V_281 -> V_51 ) . V_300 ,
V_281 -> V_77 -> V_301 , 0 ,
V_302 ,
V_149 ) ;
F_127 ( ( V_27 == - V_54 ) && ( V_51 -> V_303 == 0 ) ) ;
if ( V_27 < 0 )
goto V_66;
F_128 ( V_281 , F_129 ( V_51 ) ) ;
V_298:
V_285 ++ ;
}
}
V_66:
V_281 -> args [ 1 ] = V_285 ;
V_281 -> args [ 0 ] = V_283 ;
return V_51 -> V_303 ;
}
int F_130 ( struct V_42 * * V_289 , const struct V_42 * V_288 , int V_303 )
{
return F_131 ( V_289 , V_290 , V_288 , V_303 , V_294 ) ;
}
struct V_28 * F_132 ( struct V_28 * V_304 , struct V_42 * V_289 [] )
{
struct V_28 * V_28 ;
if ( V_289 [ V_305 ] )
V_28 = F_133 ( F_125 ( V_289 [ V_305 ] ) ) ;
else if ( V_289 [ V_306 ] )
V_28 = F_134 ( F_125 ( V_289 [ V_306 ] ) ) ;
else
V_28 = F_135 ( V_304 ) ;
return V_28 ;
}
static int F_136 ( struct V_29 * V_30 , struct V_42 * V_289 [] )
{
if ( V_30 ) {
if ( V_289 [ V_237 ] &&
F_137 ( V_289 [ V_237 ] ) < V_30 -> V_236 )
return - V_307 ;
if ( V_289 [ V_239 ] &&
F_137 ( V_289 [ V_239 ] ) < V_30 -> V_236 )
return - V_307 ;
}
if ( V_289 [ V_276 ] ) {
struct V_42 * V_278 ;
int V_308 , V_27 ;
F_138 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_139 ( V_278 ) ) ) )
return - V_309 ;
if ( ! V_48 -> V_310 )
return - V_183 ;
if ( V_48 -> V_311 ) {
V_27 = V_48 -> V_311 ( V_30 , V_278 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_140 ( struct V_29 * V_30 , struct V_42 * V_192 )
{
int V_308 , V_27 = - V_307 ;
struct V_42 * V_174 ;
const struct V_312 * V_20 = V_30 -> V_165 ;
F_138 (vf, attr, rem) {
switch ( F_139 ( V_174 ) ) {
case V_267 : {
struct V_153 * V_313 ;
V_313 = F_114 ( V_174 ) ;
V_27 = - V_183 ;
if ( V_20 -> V_314 )
V_27 = V_20 -> V_314 ( V_30 , V_313 -> V_174 ,
V_313 -> V_257 ) ;
break;
}
case V_268 : {
struct V_154 * V_315 ;
V_315 = F_114 ( V_174 ) ;
V_27 = - V_183 ;
if ( V_20 -> V_316 )
V_27 = V_20 -> V_316 ( V_30 , V_315 -> V_174 ,
V_315 -> V_259 ,
V_315 -> V_260 ) ;
break;
}
case V_270 : {
struct V_252 * V_317 ;
struct V_247 V_318 ;
V_317 = F_114 ( V_174 ) ;
V_27 = - V_183 ;
if ( V_20 -> V_244 )
V_27 = V_20 -> V_244 ( V_30 , V_317 -> V_174 ,
& V_318 ) ;
if ( V_27 )
break;
V_27 = - V_183 ;
if ( V_20 -> V_319 )
V_27 = V_20 -> V_319 ( V_30 , V_317 -> V_174 ,
V_318 . V_263 ,
V_317 -> V_261 ) ;
break;
}
case V_269 : {
struct V_156 * V_317 ;
V_317 = F_114 ( V_174 ) ;
V_27 = - V_183 ;
if ( V_20 -> V_319 )
V_27 = V_20 -> V_319 ( V_30 , V_317 -> V_174 ,
V_317 -> V_263 ,
V_317 -> V_262 ) ;
break;
}
case V_271 : {
struct V_155 * V_320 ;
V_320 = F_114 ( V_174 ) ;
V_27 = - V_183 ;
if ( V_20 -> V_321 )
V_27 = V_20 -> V_321 ( V_30 , V_320 -> V_174 ,
V_320 -> V_264 ) ;
break;
}
case V_272 : {
struct V_157 * V_322 ;
V_322 = F_114 ( V_174 ) ;
V_27 = - V_183 ;
if ( V_20 -> V_323 )
V_27 = V_20 -> V_323 ( V_30 , V_322 -> V_174 ,
V_322 -> V_265 ) ;
break;
}
default:
V_27 = - V_307 ;
break;
}
if ( V_27 )
break;
}
return V_27 ;
}
static int F_141 ( struct V_29 * V_30 , int V_200 )
{
struct V_29 * V_194 = F_44 ( V_30 ) ;
const struct V_312 * V_20 ;
int V_27 ;
if ( V_194 ) {
if ( V_194 -> V_200 == V_200 )
return 0 ;
V_20 = V_194 -> V_165 ;
if ( V_20 -> V_324 ) {
V_27 = V_20 -> V_324 ( V_194 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_183 ;
}
}
if ( V_200 ) {
V_194 = F_142 ( F_116 ( V_30 ) , V_200 ) ;
if ( ! V_194 )
return - V_307 ;
V_20 = V_194 -> V_165 ;
if ( V_20 -> V_325 ) {
V_27 = V_20 -> V_325 ( V_194 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_183 ;
}
}
return 0 ;
}
static int F_143 ( const struct V_50 * V_51 ,
struct V_29 * V_30 , struct V_117 * V_118 ,
struct V_42 * * V_289 , char * V_326 , int V_327 )
{
const struct V_312 * V_20 = V_30 -> V_165 ;
int V_27 ;
if ( V_289 [ V_305 ] || V_289 [ V_306 ] ) {
struct V_28 * V_28 = F_132 ( F_116 ( V_30 ) , V_289 ) ;
if ( F_144 ( V_28 ) ) {
V_27 = F_145 ( V_28 ) ;
goto V_328;
}
if ( ! F_146 ( V_51 , V_28 -> V_329 , V_330 ) ) {
F_147 ( V_28 ) ;
V_27 = - V_331 ;
goto V_328;
}
V_27 = F_148 ( V_30 , V_28 , V_326 ) ;
F_147 ( V_28 ) ;
if ( V_27 )
goto V_328;
V_327 |= V_332 ;
}
if ( V_289 [ V_235 ] ) {
struct V_169 * V_333 ;
struct V_334 V_335 ;
if ( ! V_20 -> V_336 ) {
V_27 = - V_183 ;
goto V_328;
}
if ( ! F_149 ( V_30 ) ) {
V_27 = - V_337 ;
goto V_328;
}
V_333 = F_114 ( V_289 [ V_235 ] ) ;
V_335 . V_228 = ( unsigned long ) V_333 -> V_228 ;
V_335 . V_229 = ( unsigned long ) V_333 -> V_229 ;
V_335 . V_230 = ( unsigned short ) V_333 -> V_230 ;
V_335 . V_231 = ( unsigned char ) V_333 -> V_231 ;
V_335 . V_232 = ( unsigned char ) V_333 -> V_232 ;
V_335 . V_233 = ( unsigned char ) V_333 -> V_233 ;
V_27 = V_20 -> V_336 ( V_30 , & V_335 ) ;
if ( V_27 < 0 )
goto V_328;
V_327 |= V_338 ;
}
if ( V_289 [ V_237 ] ) {
struct V_339 * V_340 ;
int V_303 ;
V_303 = sizeof( V_341 ) + V_30 -> V_236 ;
V_340 = F_150 ( V_303 , V_15 ) ;
if ( ! V_340 ) {
V_27 = - V_342 ;
goto V_328;
}
V_340 -> V_343 = V_30 -> type ;
memcpy ( V_340 -> V_344 , F_114 ( V_289 [ V_237 ] ) ,
V_30 -> V_236 ) ;
V_27 = F_151 ( V_30 , V_340 ) ;
F_24 ( V_340 ) ;
if ( V_27 )
goto V_328;
V_327 |= V_332 ;
}
if ( V_289 [ V_208 ] ) {
V_27 = F_152 ( V_30 , F_125 ( V_289 [ V_208 ] ) ) ;
if ( V_27 < 0 )
goto V_328;
V_327 |= V_332 ;
}
if ( V_289 [ V_210 ] ) {
F_153 ( V_30 , F_125 ( V_289 [ V_210 ] ) ) ;
V_327 |= V_338 ;
}
if ( V_118 -> V_199 > 0 && V_326 [ 0 ] ) {
V_27 = F_154 ( V_30 , V_326 ) ;
if ( V_27 < 0 )
goto V_328;
V_327 |= V_332 ;
}
if ( V_289 [ V_224 ] ) {
V_27 = F_155 ( V_30 , F_114 ( V_289 [ V_224 ] ) ,
F_137 ( V_289 [ V_224 ] ) ) ;
if ( V_27 < 0 )
goto V_328;
V_327 |= V_338 ;
}
if ( V_289 [ V_239 ] ) {
F_156 ( V_30 -> V_240 , V_289 [ V_239 ] , V_30 -> V_236 ) ;
F_157 ( V_345 , V_30 ) ;
}
if ( V_118 -> V_119 || V_118 -> V_120 ) {
V_27 = F_158 ( V_30 , F_87 ( V_30 , V_118 ) ) ;
if ( V_27 < 0 )
goto V_328;
}
if ( V_289 [ V_219 ] ) {
V_27 = F_141 ( V_30 , F_125 ( V_289 [ V_219 ] ) ) ;
if ( V_27 )
goto V_328;
V_327 |= V_332 ;
}
if ( V_289 [ V_220 ] ) {
V_27 = F_159 ( V_30 , F_160 ( V_289 [ V_220 ] ) ) ;
if ( V_27 )
goto V_328;
V_327 |= V_332 ;
}
if ( V_289 [ V_202 ] ) {
unsigned long V_346 = F_125 ( V_289 [ V_202 ] ) ;
if ( V_30 -> V_203 ^ V_346 )
V_327 |= V_338 ;
V_30 -> V_203 = V_346 ;
}
if ( V_289 [ V_204 ] )
F_81 ( V_30 , F_160 ( V_289 [ V_204 ] ) ) ;
if ( V_289 [ V_206 ] ) {
unsigned char V_346 = F_160 ( V_289 [ V_206 ] ) ;
F_83 ( & V_113 ) ;
if ( V_30 -> V_207 ^ V_346 )
V_327 |= V_338 ;
V_30 -> V_207 = V_346 ;
F_84 ( & V_113 ) ;
}
if ( V_289 [ V_246 ] ) {
struct V_42 * V_192 ;
int V_308 ;
F_138 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_139 ( V_192 ) != V_266 ) {
V_27 = - V_307 ;
goto V_328;
}
V_27 = F_140 ( V_30 , V_192 ) ;
if ( V_27 < 0 )
goto V_328;
V_327 |= V_338 ;
}
}
V_27 = 0 ;
if ( V_289 [ V_175 ] ) {
struct V_42 * V_233 [ V_347 + 1 ] ;
struct V_42 * V_192 ;
int V_174 ;
int V_308 ;
V_27 = - V_183 ;
if ( ! V_20 -> V_348 )
goto V_328;
F_138 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_139 ( V_192 ) != V_176 )
continue;
V_27 = F_161 ( V_233 , V_347 ,
V_192 , V_349 ) ;
if ( V_27 < 0 )
goto V_328;
if ( ! V_233 [ V_177 ] ) {
V_27 = - V_183 ;
goto V_328;
}
V_174 = F_125 ( V_233 [ V_177 ] ) ;
V_27 = V_20 -> V_348 ( V_30 , V_174 , V_233 ) ;
if ( V_27 < 0 )
goto V_328;
V_327 |= V_338 ;
}
}
V_27 = 0 ;
if ( V_289 [ V_179 ] ) {
struct V_42 * V_233 [ V_347 + 1 ] ;
V_27 = F_161 ( V_233 , V_347 ,
V_289 [ V_179 ] , V_349 ) ;
if ( V_27 < 0 )
goto V_328;
V_27 = - V_183 ;
if ( V_20 -> V_348 )
V_27 = V_20 -> V_348 ( V_30 , V_180 , V_233 ) ;
if ( V_27 < 0 )
goto V_328;
V_327 |= V_338 ;
}
if ( V_289 [ V_276 ] ) {
struct V_42 * V_278 ;
int V_308 ;
F_138 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_139 ( V_278 ) ) ) )
F_162 () ;
V_27 = V_48 -> V_310 ( V_30 , V_278 ) ;
if ( V_27 < 0 )
goto V_328;
V_327 |= V_338 ;
}
}
V_27 = 0 ;
V_328:
if ( V_327 & V_332 ) {
if ( V_327 & V_338 )
F_85 ( V_30 ) ;
if ( V_27 < 0 )
F_163 ( L_3 ,
V_30 -> V_89 ) ;
}
return V_27 ;
}
static int F_164 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
struct V_117 * V_118 ;
struct V_29 * V_30 ;
int V_27 ;
struct V_42 * V_289 [ V_290 + 1 ] ;
char V_326 [ V_167 ] ;
V_27 = F_124 ( V_77 , sizeof( * V_118 ) , V_289 , V_290 , V_294 ) ;
if ( V_27 < 0 )
goto V_328;
if ( V_289 [ V_201 ] )
F_165 ( V_326 , V_289 [ V_201 ] , V_167 ) ;
else
V_326 [ 0 ] = '\0' ;
V_27 = - V_307 ;
V_118 = F_106 ( V_77 ) ;
if ( V_118 -> V_199 > 0 )
V_30 = F_142 ( V_28 , V_118 -> V_199 ) ;
else if ( V_289 [ V_201 ] )
V_30 = F_166 ( V_28 , V_326 ) ;
else
goto V_328;
if ( V_30 == NULL ) {
V_27 = - V_337 ;
goto V_328;
}
V_27 = F_136 ( V_30 , V_289 ) ;
if ( V_27 < 0 )
goto V_328;
V_27 = F_143 ( V_51 , V_30 , V_118 , V_289 , V_326 , 0 ) ;
V_328:
return V_27 ;
}
static int F_167 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
const struct V_18 * V_20 ;
struct V_29 * V_30 ;
struct V_117 * V_118 ;
char V_326 [ V_167 ] ;
struct V_42 * V_289 [ V_290 + 1 ] ;
int V_27 ;
F_31 ( V_31 ) ;
V_27 = F_124 ( V_77 , sizeof( * V_118 ) , V_289 , V_290 , V_294 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_289 [ V_201 ] )
F_165 ( V_326 , V_289 [ V_201 ] , V_167 ) ;
V_118 = F_106 ( V_77 ) ;
if ( V_118 -> V_199 > 0 )
V_30 = F_142 ( V_28 , V_118 -> V_199 ) ;
else if ( V_289 [ V_201 ] )
V_30 = F_166 ( V_28 , V_326 ) ;
else
return - V_307 ;
if ( ! V_30 )
return - V_337 ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_183 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
return 0 ;
}
int F_168 ( struct V_29 * V_30 , const struct V_117 * V_118 )
{
unsigned int V_350 ;
int V_27 ;
V_350 = V_30 -> V_78 ;
if ( V_118 && ( V_118 -> V_119 || V_118 -> V_120 ) ) {
V_27 = F_169 ( V_30 , F_87 ( V_30 , V_118 ) ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_30 -> V_351 = V_352 ;
F_170 ( V_30 , V_350 , ~ 0U ) ;
return 0 ;
}
struct V_29 * F_171 ( struct V_28 * V_28 ,
char * V_326 , unsigned char V_353 ,
const struct V_18 * V_20 , struct V_42 * V_289 [] )
{
int V_27 ;
struct V_29 * V_30 ;
unsigned int V_214 = 1 ;
unsigned int V_216 = 1 ;
if ( V_289 [ V_213 ] )
V_214 = F_125 ( V_289 [ V_213 ] ) ;
else if ( V_20 -> V_354 )
V_214 = V_20 -> V_354 () ;
if ( V_289 [ V_215 ] )
V_216 = F_125 ( V_289 [ V_215 ] ) ;
else if ( V_20 -> V_355 )
V_216 = V_20 -> V_355 () ;
V_27 = - V_342 ;
V_30 = F_172 ( V_20 -> V_356 , V_326 , V_353 ,
V_20 -> V_22 , V_214 , V_216 ) ;
if ( ! V_30 )
goto V_27;
F_173 ( V_30 , V_28 ) ;
V_30 -> V_18 = V_20 ;
V_30 -> V_351 = V_357 ;
if ( V_289 [ V_208 ] )
V_30 -> V_209 = F_125 ( V_289 [ V_208 ] ) ;
if ( V_289 [ V_237 ] ) {
memcpy ( V_30 -> V_238 , F_114 ( V_289 [ V_237 ] ) ,
F_137 ( V_289 [ V_237 ] ) ) ;
V_30 -> V_358 = V_359 ;
}
if ( V_289 [ V_239 ] )
memcpy ( V_30 -> V_240 , F_114 ( V_289 [ V_239 ] ) ,
F_137 ( V_289 [ V_239 ] ) ) ;
if ( V_289 [ V_202 ] )
V_30 -> V_203 = F_125 ( V_289 [ V_202 ] ) ;
if ( V_289 [ V_204 ] )
F_81 ( V_30 , F_160 ( V_289 [ V_204 ] ) ) ;
if ( V_289 [ V_206 ] )
V_30 -> V_207 = F_160 ( V_289 [ V_206 ] ) ;
if ( V_289 [ V_210 ] )
F_153 ( V_30 , F_125 ( V_289 [ V_210 ] ) ) ;
return V_30 ;
V_27:
return F_174 ( V_27 ) ;
}
static int F_175 ( const struct V_50 * V_51 ,
struct V_28 * V_28 , int V_69 ,
struct V_117 * V_118 ,
struct V_42 * * V_289 )
{
struct V_29 * V_30 , * V_360 ;
int V_27 ;
F_176 (net, dev, aux) {
if ( V_30 -> V_69 == V_69 ) {
V_27 = F_143 ( V_51 , V_30 , V_118 , V_289 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_177 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_361 = NULL ;
struct V_29 * V_30 ;
struct V_29 * V_40 = NULL ;
struct V_117 * V_118 ;
char V_19 [ V_362 ] ;
char V_326 [ V_167 ] ;
struct V_42 * V_289 [ V_290 + 1 ] ;
struct V_42 * V_64 [ V_363 + 1 ] ;
unsigned char V_353 = V_364 ;
int V_27 ;
#ifdef F_178
V_365:
#endif
V_27 = F_124 ( V_77 , sizeof( * V_118 ) , V_289 , V_290 , V_294 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_289 [ V_201 ] )
F_165 ( V_326 , V_289 [ V_201 ] , V_167 ) ;
else
V_326 [ 0 ] = '\0' ;
V_118 = F_106 ( V_77 ) ;
if ( V_118 -> V_199 > 0 )
V_30 = F_142 ( V_28 , V_118 -> V_199 ) ;
else {
if ( V_326 [ 0 ] )
V_30 = F_166 ( V_28 , V_326 ) ;
else
V_30 = NULL ;
}
if ( V_30 ) {
V_40 = F_44 ( V_30 ) ;
if ( V_40 )
V_361 = V_40 -> V_18 ;
}
V_27 = F_136 ( V_30 , V_289 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_289 [ V_65 ] ) {
V_27 = F_161 ( V_64 , V_363 ,
V_289 [ V_65 ] , V_366 ) ;
if ( V_27 < 0 )
return V_27 ;
} else
memset ( V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_64 [ V_59 ] ) {
F_165 ( V_19 , V_64 [ V_59 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_42 * V_192 [ V_20 ? V_20 -> V_367 + 1 : 1 ] ;
struct V_42 * V_368 [ V_361 ? V_361 -> V_369 + 1 : 1 ] ;
struct V_42 * * V_58 = NULL ;
struct V_42 * * V_52 = NULL ;
struct V_28 * V_370 , * V_274 = NULL ;
if ( V_20 ) {
if ( V_20 -> V_367 && V_64 [ V_62 ] ) {
V_27 = F_161 ( V_192 , V_20 -> V_367 ,
V_64 [ V_62 ] ,
V_20 -> V_371 ) ;
if ( V_27 < 0 )
return V_27 ;
V_58 = V_192 ;
}
if ( V_20 -> V_372 ) {
V_27 = V_20 -> V_372 ( V_289 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_361 ) {
if ( V_361 -> V_369 &&
V_64 [ V_56 ] ) {
V_27 = F_161 ( V_368 ,
V_361 -> V_369 ,
V_64 [ V_56 ] ,
V_361 -> V_373 ) ;
if ( V_27 < 0 )
return V_27 ;
V_52 = V_368 ;
}
if ( V_361 -> V_374 ) {
V_27 = V_361 -> V_374 ( V_289 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_30 ) {
int V_327 = 0 ;
if ( V_77 -> V_375 & V_376 )
return - V_21 ;
if ( V_77 -> V_375 & V_377 )
return - V_183 ;
if ( V_64 [ V_62 ] ) {
if ( ! V_20 || V_20 != V_30 -> V_18 ||
! V_20 -> V_378 )
return - V_183 ;
V_27 = V_20 -> V_378 ( V_30 , V_289 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
V_327 |= V_338 ;
}
if ( V_64 [ V_56 ] ) {
if ( ! V_361 || ! V_361 -> V_379 )
return - V_183 ;
V_27 = V_361 -> V_379 ( V_40 , V_30 ,
V_289 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
V_327 |= V_338 ;
}
return F_143 ( V_51 , V_30 , V_118 , V_289 , V_326 , V_327 ) ;
}
if ( ! ( V_77 -> V_375 & V_380 ) ) {
if ( V_118 -> V_199 == 0 && V_289 [ V_210 ] )
return F_175 ( V_51 , V_28 ,
F_125 ( V_289 [ V_210 ] ) ,
V_118 , V_289 ) ;
return - V_337 ;
}
if ( V_289 [ V_235 ] || V_289 [ V_219 ] || V_289 [ V_381 ] )
return - V_183 ;
if ( ! V_20 ) {
#ifdef F_178
if ( V_19 [ 0 ] ) {
F_3 () ;
F_179 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_365;
}
#endif
return - V_183 ;
}
if ( ! V_20 -> V_22 )
return - V_183 ;
if ( ! V_326 [ 0 ] ) {
snprintf ( V_326 , V_167 , L_5 , V_20 -> V_19 ) ;
V_353 = V_382 ;
}
V_370 = F_132 ( V_28 , V_289 ) ;
if ( F_144 ( V_370 ) )
return F_145 ( V_370 ) ;
V_27 = - V_331 ;
if ( ! F_146 ( V_51 , V_370 -> V_329 , V_330 ) )
goto V_66;
if ( V_289 [ V_275 ] ) {
int V_93 = F_180 ( V_289 [ V_275 ] ) ;
V_274 = F_181 ( V_370 , V_93 ) ;
if ( ! V_274 ) {
V_27 = - V_307 ;
goto V_66;
}
V_27 = - V_331 ;
if ( ! F_146 ( V_51 , V_274 -> V_329 , V_330 ) )
goto V_66;
}
V_30 = F_171 ( V_274 ? : V_370 , V_326 ,
V_353 , V_20 , V_289 ) ;
if ( F_144 ( V_30 ) ) {
V_27 = F_145 ( V_30 ) ;
goto V_66;
}
V_30 -> V_200 = V_118 -> V_199 ;
if ( V_20 -> V_383 ) {
V_27 = V_20 -> V_383 ( V_274 ? : V_28 , V_30 , V_289 , V_58 ) ;
if ( V_27 < 0 ) {
if ( V_30 -> V_384 == V_385 )
F_182 ( V_30 ) ;
goto V_66;
}
} else {
V_27 = F_183 ( V_30 ) ;
if ( V_27 < 0 ) {
F_182 ( V_30 ) ;
goto V_66;
}
}
V_27 = F_168 ( V_30 , V_118 ) ;
if ( V_27 < 0 )
goto V_386;
if ( V_274 ) {
V_27 = F_148 ( V_30 , V_370 , V_326 ) ;
if ( V_27 < 0 )
goto V_386;
}
V_66:
if ( V_274 )
F_147 ( V_274 ) ;
F_147 ( V_370 ) ;
return V_27 ;
V_386:
if ( V_20 -> V_383 ) {
F_31 ( V_31 ) ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
} else {
F_184 ( V_30 ) ;
}
goto V_66;
}
}
static int F_185 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
struct V_117 * V_118 ;
char V_326 [ V_167 ] ;
struct V_42 * V_289 [ V_290 + 1 ] ;
struct V_29 * V_30 = NULL ;
struct V_50 * V_387 ;
int V_27 ;
T_5 V_149 = 0 ;
V_27 = F_124 ( V_77 , sizeof( * V_118 ) , V_289 , V_290 , V_294 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_289 [ V_201 ] )
F_165 ( V_326 , V_289 [ V_201 ] , V_167 ) ;
if ( V_289 [ V_295 ] )
V_149 = F_125 ( V_289 [ V_295 ] ) ;
V_118 = F_106 ( V_77 ) ;
if ( V_118 -> V_199 > 0 )
V_30 = F_142 ( V_28 , V_118 -> V_199 ) ;
else if ( V_289 [ V_201 ] )
V_30 = F_166 ( V_28 , V_326 ) ;
else
return - V_307 ;
if ( V_30 == NULL )
return - V_337 ;
V_387 = F_186 ( F_94 ( V_30 , V_149 ) , V_15 ) ;
if ( V_387 == NULL )
return - V_16 ;
V_27 = F_103 ( V_387 , V_30 , V_299 , F_61 ( V_51 ) . V_300 ,
V_77 -> V_301 , 0 , 0 , V_149 ) ;
if ( V_27 < 0 ) {
F_127 ( V_27 == - V_54 ) ;
F_187 ( V_387 ) ;
} else
V_27 = F_65 ( V_387 , V_28 , F_61 ( V_51 ) . V_300 ) ;
return V_27 ;
}
static T_8 F_188 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
struct V_29 * V_30 ;
struct V_42 * V_289 [ V_290 + 1 ] ;
T_5 V_149 = 0 ;
T_8 V_388 = 0 ;
int V_291 ;
V_291 = F_123 ( V_77 ) < sizeof( struct V_117 ) ?
sizeof( struct V_293 ) : sizeof( struct V_117 ) ;
if ( F_124 ( V_77 , V_291 , V_289 , V_290 , V_294 ) >= 0 ) {
if ( V_289 [ V_295 ] )
V_149 = F_125 ( V_289 [ V_295 ] ) ;
}
if ( ! V_149 )
return V_389 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_388 = F_189 ( T_8 , V_388 ,
F_94 ( V_30 ,
V_149 ) ) ;
}
return V_388 ;
}
static int F_190 ( struct V_50 * V_51 , struct V_280 * V_281 )
{
int V_285 ;
int V_286 = V_281 -> V_47 ;
if ( V_286 == 0 )
V_286 = 1 ;
for ( V_285 = 1 ; V_285 <= V_9 ; V_285 ++ ) {
int type = V_281 -> V_77 -> V_390 - V_4 ;
if ( V_285 < V_286 || V_285 == V_391 )
continue;
if ( V_10 [ V_285 ] == NULL ||
V_10 [ V_285 ] [ type ] . V_13 == NULL )
continue;
if ( V_285 > V_286 ) {
memset ( & V_281 -> args [ 0 ] , 0 , sizeof( V_281 -> args ) ) ;
V_281 -> V_392 = 0 ;
V_281 -> V_188 = 0 ;
}
if ( V_10 [ V_285 ] [ type ] . V_13 ( V_51 , V_281 ) )
break;
}
V_281 -> V_47 = V_285 ;
return V_51 -> V_303 ;
}
struct V_50 * F_191 ( int type , struct V_29 * V_30 ,
unsigned int V_189 , T_6 V_78 )
{
struct V_28 * V_28 = F_116 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
T_4 V_393 ;
V_51 = F_186 ( ( V_393 = F_94 ( V_30 , 0 ) ) , V_78 ) ;
if ( V_51 == NULL )
goto V_328;
V_27 = F_103 ( V_51 , V_30 , type , 0 , 0 , V_189 , 0 , 0 ) ;
if ( V_27 < 0 ) {
F_127 ( V_27 == - V_54 ) ;
F_187 ( V_51 ) ;
goto V_328;
}
return V_51 ;
V_328:
if ( V_27 < 0 )
F_70 ( V_28 , V_394 , V_27 ) ;
return NULL ;
}
void F_192 ( struct V_50 * V_51 , struct V_29 * V_30 , T_6 V_78 )
{
struct V_28 * V_28 = F_116 ( V_30 ) ;
F_67 ( V_51 , V_28 , 0 , V_394 , NULL , V_78 ) ;
}
void F_193 ( int type , struct V_29 * V_30 , unsigned int V_189 ,
T_6 V_78 )
{
struct V_50 * V_51 ;
V_51 = F_191 ( type , V_30 , V_189 , V_78 ) ;
if ( V_51 )
F_192 ( V_51 , V_30 , V_78 ) ;
}
static int F_194 ( struct V_50 * V_51 ,
struct V_29 * V_30 ,
T_9 * V_395 , T_5 V_68 , T_5 V_188 ,
int type , unsigned int V_78 ,
int V_396 )
{
struct V_76 * V_77 ;
struct V_397 * V_398 ;
V_77 = F_105 ( V_51 , V_68 , V_188 , type , sizeof( * V_398 ) , V_396 ) ;
if ( ! V_77 )
return - V_54 ;
V_398 = F_106 ( V_77 ) ;
V_398 -> V_399 = V_400 ;
V_398 -> V_401 = 0 ;
V_398 -> V_402 = 0 ;
V_398 -> V_403 = V_78 ;
V_398 -> V_404 = 0 ;
V_398 -> V_405 = V_30 -> V_200 ;
V_398 -> V_406 = V_407 ;
if ( F_80 ( V_51 , V_408 , V_409 , V_395 ) )
goto V_90;
F_119 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_120 ( V_51 , V_77 ) ;
return - V_54 ;
}
static inline T_4 F_195 ( void )
{
return F_95 ( sizeof( struct V_397 ) ) + F_45 ( V_409 ) ;
}
static void F_196 ( struct V_29 * V_30 , T_9 * V_395 , int type )
{
struct V_28 * V_28 = F_116 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
V_51 = F_186 ( F_195 () , V_410 ) ;
if ( ! V_51 )
goto V_328;
V_27 = F_194 ( V_51 , V_30 , V_395 , 0 , 0 , type , V_411 , 0 ) ;
if ( V_27 < 0 ) {
F_187 ( V_51 ) ;
goto V_328;
}
F_67 ( V_51 , V_28 , 0 , V_412 , NULL , V_410 ) ;
return;
V_328:
F_70 ( V_28 , V_412 , V_27 ) ;
}
int F_197 ( struct V_397 * V_398 ,
struct V_42 * V_289 [] ,
struct V_29 * V_30 ,
const unsigned char * V_395 , T_8 V_413 ,
T_8 V_78 )
{
int V_27 = - V_307 ;
if ( V_398 -> V_406 && ! ( V_398 -> V_406 & V_407 ) ) {
F_198 ( L_6 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( V_413 ) {
F_198 ( L_7 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( F_199 ( V_395 ) || F_200 ( V_395 ) )
V_27 = F_201 ( V_30 , V_395 ) ;
else if ( F_202 ( V_395 ) )
V_27 = F_203 ( V_30 , V_395 ) ;
if ( V_27 == - V_21 && ! ( V_78 & V_376 ) )
V_27 = 0 ;
return V_27 ;
}
static int F_204 ( struct V_42 * V_414 , T_8 * V_415 )
{
T_8 V_413 = 0 ;
if ( V_414 ) {
if ( F_137 ( V_414 ) != sizeof( T_8 ) ) {
F_198 ( L_8 ) ;
return - V_307 ;
}
V_413 = F_205 ( V_414 ) ;
if ( ! V_413 || V_413 >= V_416 ) {
F_198 ( L_9 ,
V_413 ) ;
return - V_307 ;
}
}
* V_415 = V_413 ;
return 0 ;
}
static int F_206 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
struct V_397 * V_398 ;
struct V_42 * V_289 [ V_417 + 1 ] ;
struct V_29 * V_30 ;
T_9 * V_395 ;
T_8 V_413 ;
int V_27 ;
V_27 = F_124 ( V_77 , sizeof( * V_398 ) , V_289 , V_417 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_398 = F_106 ( V_77 ) ;
if ( V_398 -> V_405 == 0 ) {
F_198 ( L_10 ) ;
return - V_307 ;
}
V_30 = F_142 ( V_28 , V_398 -> V_405 ) ;
if ( V_30 == NULL ) {
F_198 ( L_11 ) ;
return - V_337 ;
}
if ( ! V_289 [ V_408 ] || F_137 ( V_289 [ V_408 ] ) != V_409 ) {
F_198 ( L_12 ) ;
return - V_307 ;
}
V_395 = F_114 ( V_289 [ V_408 ] ) ;
V_27 = F_204 ( V_289 [ V_418 ] , & V_413 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_183 ;
if ( ( ! V_398 -> V_403 || V_398 -> V_403 & V_419 ) &&
( V_30 -> V_420 & V_421 ) ) {
struct V_29 * V_422 = F_44 ( V_30 ) ;
const struct V_312 * V_20 = V_422 -> V_165 ;
V_27 = V_20 -> V_423 ( V_398 , V_289 , V_30 , V_395 , V_413 ,
V_77 -> V_375 ) ;
if ( V_27 )
goto V_66;
else
V_398 -> V_403 &= ~ V_419 ;
}
if ( ( V_398 -> V_403 & V_411 ) ) {
if ( V_30 -> V_165 -> V_423 )
V_27 = V_30 -> V_165 -> V_423 ( V_398 , V_289 , V_30 , V_395 ,
V_413 ,
V_77 -> V_375 ) ;
else
V_27 = F_197 ( V_398 , V_289 , V_30 , V_395 , V_413 ,
V_77 -> V_375 ) ;
if ( ! V_27 ) {
F_196 ( V_30 , V_395 , V_424 ) ;
V_398 -> V_403 &= ~ V_411 ;
}
}
V_66:
return V_27 ;
}
int F_207 ( struct V_397 * V_398 ,
struct V_42 * V_289 [] ,
struct V_29 * V_30 ,
const unsigned char * V_395 , T_8 V_413 )
{
int V_27 = - V_307 ;
if ( ! ( V_398 -> V_406 & V_407 ) ) {
F_198 ( L_6 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( F_199 ( V_395 ) || F_200 ( V_395 ) )
V_27 = F_208 ( V_30 , V_395 ) ;
else if ( F_202 ( V_395 ) )
V_27 = F_209 ( V_30 , V_395 ) ;
return V_27 ;
}
static int F_210 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
struct V_397 * V_398 ;
struct V_42 * V_289 [ V_417 + 1 ] ;
struct V_29 * V_30 ;
int V_27 = - V_307 ;
T_10 * V_395 ;
T_8 V_413 ;
if ( ! F_211 ( V_51 , V_330 ) )
return - V_331 ;
V_27 = F_124 ( V_77 , sizeof( * V_398 ) , V_289 , V_417 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_398 = F_106 ( V_77 ) ;
if ( V_398 -> V_405 == 0 ) {
F_198 ( L_13 ) ;
return - V_307 ;
}
V_30 = F_142 ( V_28 , V_398 -> V_405 ) ;
if ( V_30 == NULL ) {
F_198 ( L_14 ) ;
return - V_337 ;
}
if ( ! V_289 [ V_408 ] || F_137 ( V_289 [ V_408 ] ) != V_409 ) {
F_198 ( L_15 ) ;
return - V_307 ;
}
V_395 = F_114 ( V_289 [ V_408 ] ) ;
V_27 = F_204 ( V_289 [ V_418 ] , & V_413 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_183 ;
if ( ( ! V_398 -> V_403 || V_398 -> V_403 & V_419 ) &&
( V_30 -> V_420 & V_421 ) ) {
struct V_29 * V_422 = F_44 ( V_30 ) ;
const struct V_312 * V_20 = V_422 -> V_165 ;
if ( V_20 -> V_425 )
V_27 = V_20 -> V_425 ( V_398 , V_289 , V_30 , V_395 , V_413 ) ;
if ( V_27 )
goto V_66;
else
V_398 -> V_403 &= ~ V_419 ;
}
if ( V_398 -> V_403 & V_411 ) {
if ( V_30 -> V_165 -> V_425 )
V_27 = V_30 -> V_165 -> V_425 ( V_398 , V_289 , V_30 , V_395 ,
V_413 ) ;
else
V_27 = F_207 ( V_398 , V_289 , V_30 , V_395 , V_413 ) ;
if ( ! V_27 ) {
F_196 ( V_30 , V_395 , V_426 ) ;
V_398 -> V_403 &= ~ V_411 ;
}
}
V_66:
return V_27 ;
}
static int F_212 ( struct V_50 * V_51 ,
struct V_280 * V_281 ,
struct V_29 * V_30 ,
int * V_285 ,
struct V_427 * V_25 )
{
struct V_428 * V_429 ;
int V_27 ;
T_5 V_300 , V_188 ;
V_300 = F_61 ( V_281 -> V_51 ) . V_300 ;
V_188 = V_281 -> V_77 -> V_301 ;
F_26 (ha, &list->list, list) {
if ( * V_285 < V_281 -> args [ 0 ] )
goto V_430;
V_27 = F_194 ( V_51 , V_30 , V_429 -> V_395 ,
V_300 , V_188 ,
V_424 , V_411 ,
V_302 ) ;
if ( V_27 < 0 )
return V_27 ;
V_430:
* V_285 += 1 ;
}
return 0 ;
}
int F_213 ( struct V_50 * V_51 ,
struct V_280 * V_281 ,
struct V_29 * V_30 ,
struct V_29 * V_431 ,
int V_285 )
{
int V_27 ;
F_214 ( V_30 ) ;
V_27 = F_212 ( V_51 , V_281 , V_30 , & V_285 , & V_30 -> V_432 ) ;
if ( V_27 )
goto V_66;
F_212 ( V_51 , V_281 , V_30 , & V_285 , & V_30 -> V_433 ) ;
V_66:
F_215 ( V_30 ) ;
return V_285 ;
}
static int F_216 ( struct V_50 * V_51 , struct V_280 * V_281 )
{
struct V_29 * V_30 ;
struct V_42 * V_289 [ V_290 + 1 ] ;
struct V_29 * V_434 = NULL ;
struct V_29 * V_422 = NULL ;
const struct V_312 * V_20 = NULL ;
const struct V_312 * V_435 = NULL ;
struct V_117 * V_118 = F_106 ( V_281 -> V_77 ) ;
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
int V_436 = 0 ;
int V_437 = 0 ;
int V_285 = 0 ;
if ( F_124 ( V_281 -> V_77 , sizeof( struct V_117 ) , V_289 , V_290 ,
V_294 ) == 0 ) {
if ( V_289 [ V_219 ] )
V_437 = F_125 ( V_289 [ V_219 ] ) ;
}
V_436 = V_118 -> V_199 ;
if ( V_437 ) {
V_422 = F_142 ( V_28 , V_437 ) ;
if ( ! V_422 )
return - V_337 ;
V_20 = V_422 -> V_165 ;
V_434 = V_422 ;
}
F_32 (net, dev) {
if ( V_436 && ( V_30 -> V_200 != V_436 ) )
continue;
if ( ! V_437 ) {
if ( V_30 -> V_420 & V_421 ) {
V_422 = F_44 ( V_30 ) ;
V_435 = V_422 -> V_165 ;
}
V_434 = V_30 ;
} else {
if ( V_30 != V_422 &&
! ( V_30 -> V_420 & V_421 ) )
continue;
if ( V_422 != F_44 ( V_30 ) &&
! ( V_30 -> V_420 & V_438 ) )
continue;
V_434 = V_422 ;
V_435 = V_20 ;
}
if ( V_30 -> V_420 & V_421 ) {
if ( V_435 && V_435 -> V_439 )
V_285 = V_435 -> V_439 ( V_51 , V_281 , V_422 , V_30 ,
V_285 ) ;
}
if ( V_30 -> V_165 -> V_439 )
V_285 = V_30 -> V_165 -> V_439 ( V_51 , V_281 , V_30 , NULL ,
V_285 ) ;
else
V_285 = F_213 ( V_51 , V_281 , V_30 , NULL , V_285 ) ;
V_435 = NULL ;
}
V_281 -> args [ 0 ] = V_285 ;
return V_51 -> V_303 ;
}
static int F_217 ( struct V_50 * V_51 , T_5 V_78 , T_5 V_440 ,
unsigned int V_441 , unsigned int V_442 )
{
if ( V_440 & V_442 )
return F_108 ( V_51 , V_441 , ! ! ( V_78 & V_442 ) ) ;
return 0 ;
}
int F_218 ( struct V_50 * V_51 , T_5 V_68 , T_5 V_188 ,
struct V_29 * V_30 , T_8 V_443 ,
T_5 V_78 , T_5 V_440 )
{
struct V_76 * V_77 ;
struct V_117 * V_118 ;
struct V_42 * V_444 ;
struct V_42 * V_445 ;
T_9 V_109 = F_109 ( V_30 ) ? V_30 -> V_109 : V_205 ;
struct V_29 * V_422 = F_44 ( V_30 ) ;
V_77 = F_105 ( V_51 , V_68 , V_188 , V_299 , sizeof( * V_118 ) , V_302 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_118 = F_106 ( V_77 ) ;
V_118 -> V_195 = V_400 ;
V_118 -> V_197 = 0 ;
V_118 -> V_198 = V_30 -> type ;
V_118 -> V_199 = V_30 -> V_200 ;
V_118 -> V_119 = F_107 ( V_30 ) ;
V_118 -> V_120 = 0 ;
if ( F_54 ( V_51 , V_201 , V_30 -> V_89 ) ||
F_74 ( V_51 , V_208 , V_30 -> V_209 ) ||
F_108 ( V_51 , V_204 , V_109 ) ||
( V_422 &&
F_74 ( V_51 , V_219 , V_422 -> V_200 ) ) ||
( V_30 -> V_236 &&
F_80 ( V_51 , V_237 , V_30 -> V_236 , V_30 -> V_238 ) ) ||
( V_30 -> V_200 != V_30 -> V_217 &&
F_74 ( V_51 , V_218 , V_30 -> V_217 ) ) )
goto V_90;
V_444 = F_55 ( V_51 , V_276 ) ;
if ( ! V_444 )
goto V_90;
if ( F_219 ( V_51 , V_446 , V_447 ) ) {
F_57 ( V_51 , V_444 ) ;
goto V_90;
}
if ( V_443 != V_448 ) {
if ( F_219 ( V_51 , V_449 , V_443 ) ) {
F_57 ( V_51 , V_444 ) ;
goto V_90;
}
}
F_56 ( V_51 , V_444 ) ;
V_445 = F_55 ( V_51 , V_381 | V_450 ) ;
if ( ! V_445 )
goto V_90;
if ( F_217 ( V_51 , V_78 , V_440 ,
V_451 , V_452 ) ||
F_217 ( V_51 , V_78 , V_440 ,
V_453 , V_454 ) ||
F_217 ( V_51 , V_78 , V_440 ,
V_455 ,
V_456 ) ||
F_217 ( V_51 , V_78 , V_440 ,
V_457 , V_458 ) ||
F_217 ( V_51 , V_78 , V_440 ,
V_459 , V_460 ) ||
F_217 ( V_51 , V_78 , V_440 ,
V_461 , V_462 ) ||
F_217 ( V_51 , V_78 , V_440 ,
V_463 , V_464 ) ||
F_217 ( V_51 , V_78 , V_440 ,
V_465 , V_466 ) ) {
F_57 ( V_51 , V_445 ) ;
goto V_90;
}
F_56 ( V_51 , V_445 ) ;
F_119 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_120 ( V_51 , V_77 ) ;
return - V_54 ;
}
static int F_220 ( struct V_50 * V_51 , struct V_280 * V_281 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
struct V_29 * V_30 ;
int V_285 = 0 ;
T_5 V_300 = F_61 ( V_281 -> V_51 ) . V_300 ;
T_5 V_188 = V_281 -> V_77 -> V_301 ;
T_5 V_467 = 0 ;
if ( F_123 ( V_281 -> V_77 ) > sizeof( struct V_117 ) ) {
struct V_42 * V_468 ;
V_468 = F_221 ( V_281 -> V_77 , sizeof( struct V_117 ) ,
V_295 ) ;
if ( V_468 ) {
if ( F_137 ( V_468 ) < sizeof( V_467 ) )
return - V_307 ;
V_467 = F_125 ( V_468 ) ;
}
}
F_222 () ;
F_223 (net, dev) {
const struct V_312 * V_20 = V_30 -> V_165 ;
struct V_29 * V_422 = F_44 ( V_30 ) ;
if ( V_422 && V_422 -> V_165 -> V_469 ) {
if ( V_285 >= V_281 -> args [ 0 ] &&
V_422 -> V_165 -> V_469 (
V_51 , V_300 , V_188 , V_30 , V_467 ) < 0 )
break;
V_285 ++ ;
}
if ( V_20 -> V_469 ) {
if ( V_285 >= V_281 -> args [ 0 ] &&
V_20 -> V_469 ( V_51 , V_300 , V_188 , V_30 ,
V_467 ) < 0 )
break;
V_285 ++ ;
}
}
F_224 () ;
V_281 -> args [ 0 ] = V_285 ;
return V_51 -> V_303 ;
}
static inline T_4 F_225 ( void )
{
return F_95 ( sizeof( struct V_117 ) )
+ F_45 ( V_167 )
+ F_45 ( V_170 )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_9 ) )
+ F_45 ( sizeof( struct V_42 ) )
+ F_45 ( sizeof( T_8 ) )
+ F_45 ( sizeof( T_8 ) ) ;
}
static int F_226 ( struct V_29 * V_30 )
{
struct V_28 * V_28 = F_116 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_183 ;
if ( ! V_30 -> V_165 -> V_469 )
return 0 ;
V_51 = F_186 ( F_225 () , V_410 ) ;
if ( ! V_51 ) {
V_27 = - V_342 ;
goto V_328;
}
V_27 = V_30 -> V_165 -> V_469 ( V_51 , 0 , 0 , V_30 , 0 ) ;
if ( V_27 < 0 )
goto V_328;
if ( ! V_51 -> V_303 )
goto V_328;
F_67 ( V_51 , V_28 , 0 , V_394 , NULL , V_410 ) ;
return 0 ;
V_328:
F_127 ( V_27 == - V_54 ) ;
F_187 ( V_51 ) ;
if ( V_27 )
F_70 ( V_28 , V_394 , V_27 ) ;
return V_27 ;
}
static int F_227 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
struct V_117 * V_118 ;
struct V_29 * V_30 ;
struct V_42 * V_470 , * V_192 = NULL ;
int V_308 , V_27 = - V_183 ;
T_8 V_78 = 0 ;
bool V_471 = false ;
if ( F_123 ( V_77 ) < sizeof( * V_118 ) )
return - V_307 ;
V_118 = F_106 ( V_77 ) ;
if ( V_118 -> V_195 != V_400 )
return - V_472 ;
V_30 = F_142 ( V_28 , V_118 -> V_199 ) ;
if ( ! V_30 ) {
F_198 ( L_16 ) ;
return - V_337 ;
}
V_470 = F_221 ( V_77 , sizeof( struct V_117 ) , V_276 ) ;
if ( V_470 ) {
F_138 (attr, br_spec, rem) {
if ( F_139 ( V_192 ) == V_446 ) {
if ( F_137 ( V_192 ) < sizeof( V_78 ) )
return - V_307 ;
V_471 = true ;
V_78 = F_205 ( V_192 ) ;
break;
}
}
}
if ( ! V_78 || ( V_78 & V_473 ) ) {
struct V_29 * V_422 = F_44 ( V_30 ) ;
if ( ! V_422 || ! V_422 -> V_165 -> V_474 ) {
V_27 = - V_183 ;
goto V_66;
}
V_27 = V_422 -> V_165 -> V_474 ( V_30 , V_77 , V_78 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_473 ;
}
if ( ( V_78 & V_447 ) ) {
if ( ! V_30 -> V_165 -> V_474 )
V_27 = - V_183 ;
else
V_27 = V_30 -> V_165 -> V_474 ( V_30 , V_77 ,
V_78 ) ;
if ( ! V_27 ) {
V_78 &= ~ V_447 ;
V_27 = F_226 ( V_30 ) ;
}
}
if ( V_471 )
memcpy ( F_114 ( V_192 ) , & V_78 , sizeof( V_78 ) ) ;
V_66:
return V_27 ;
}
static int F_228 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
struct V_117 * V_118 ;
struct V_29 * V_30 ;
struct V_42 * V_470 , * V_192 = NULL ;
int V_308 , V_27 = - V_183 ;
T_8 V_78 = 0 ;
bool V_471 = false ;
if ( F_123 ( V_77 ) < sizeof( * V_118 ) )
return - V_307 ;
V_118 = F_106 ( V_77 ) ;
if ( V_118 -> V_195 != V_400 )
return - V_472 ;
V_30 = F_142 ( V_28 , V_118 -> V_199 ) ;
if ( ! V_30 ) {
F_198 ( L_16 ) ;
return - V_337 ;
}
V_470 = F_221 ( V_77 , sizeof( struct V_117 ) , V_276 ) ;
if ( V_470 ) {
F_138 (attr, br_spec, rem) {
if ( F_139 ( V_192 ) == V_446 ) {
if ( F_137 ( V_192 ) < sizeof( V_78 ) )
return - V_307 ;
V_471 = true ;
V_78 = F_205 ( V_192 ) ;
break;
}
}
}
if ( ! V_78 || ( V_78 & V_473 ) ) {
struct V_29 * V_422 = F_44 ( V_30 ) ;
if ( ! V_422 || ! V_422 -> V_165 -> V_475 ) {
V_27 = - V_183 ;
goto V_66;
}
V_27 = V_422 -> V_165 -> V_475 ( V_30 , V_77 , V_78 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_473 ;
}
if ( ( V_78 & V_447 ) ) {
if ( ! V_30 -> V_165 -> V_475 )
V_27 = - V_183 ;
else
V_27 = V_30 -> V_165 -> V_475 ( V_30 , V_77 ,
V_78 ) ;
if ( ! V_27 ) {
V_78 &= ~ V_447 ;
V_27 = F_226 ( V_30 ) ;
}
}
if ( V_471 )
memcpy ( F_114 ( V_192 ) , & V_78 , sizeof( V_78 ) ) ;
V_66:
return V_27 ;
}
static int F_229 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_122 ( V_51 -> V_282 ) ;
T_1 V_11 ;
int V_476 , V_19 ;
int V_47 ;
int type ;
int V_27 ;
type = V_77 -> V_390 ;
if ( type > V_477 )
return - V_183 ;
type -= V_4 ;
if ( F_123 ( V_77 ) < sizeof( struct V_293 ) )
return 0 ;
V_47 = ( (struct V_293 * ) F_106 ( V_77 ) ) -> V_478 ;
V_476 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_230 ( V_51 , V_330 ) )
return - V_331 ;
if ( V_19 == 2 && V_77 -> V_375 & V_479 ) {
struct V_71 * V_72 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_480 = 0 ;
V_13 = F_16 ( V_47 , type ) ;
if ( V_13 == NULL )
return - V_183 ;
V_14 = F_17 ( V_47 , type ) ;
if ( V_14 )
V_480 = V_14 ( V_51 , V_77 ) ;
F_3 () ;
V_72 = V_28 -> V_72 ;
{
struct V_481 V_482 = {
. V_483 = V_13 ,
. V_480 = V_480 ,
} ;
V_27 = F_231 ( V_72 , V_51 , V_77 , & V_482 ) ;
}
F_1 () ;
return V_27 ;
}
V_11 = F_15 ( V_47 , type ) ;
if ( V_11 == NULL )
return - V_183 ;
return V_11 ( V_51 , V_77 ) ;
}
static void F_232 ( struct V_50 * V_51 )
{
F_1 () ;
F_233 ( V_51 , & F_229 ) ;
F_5 () ;
}
static int F_234 ( struct V_484 * V_485 , unsigned long V_486 , void * V_487 )
{
struct V_29 * V_30 = F_235 ( V_487 ) ;
switch ( V_486 ) {
case V_488 :
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
case V_494 :
case V_495 :
case V_496 :
case V_497 :
case V_498 :
case V_499 :
case V_500 :
break;
default:
F_193 ( V_299 , V_30 , 0 , V_15 ) ;
break;
}
return V_501 ;
}
static int T_11 F_236 ( struct V_28 * V_28 )
{
struct V_71 * V_282 ;
struct V_502 V_503 = {
. V_504 = V_505 ,
. V_506 = F_232 ,
. V_507 = & V_1 ,
. V_78 = V_508 ,
} ;
V_282 = F_237 ( V_28 , V_509 , & V_503 ) ;
if ( ! V_282 )
return - V_342 ;
V_28 -> V_72 = V_282 ;
return 0 ;
}
static void T_12 F_238 ( struct V_28 * V_28 )
{
F_239 ( V_28 -> V_72 ) ;
V_28 -> V_72 = NULL ;
}
void T_13 F_240 ( void )
{
if ( F_241 ( & V_510 ) )
F_21 ( L_17 ) ;
F_242 ( & V_511 ) ;
F_20 ( V_12 , V_512 , F_185 ,
F_121 , F_188 ) ;
F_20 ( V_12 , V_513 , F_164 , NULL , NULL ) ;
F_20 ( V_12 , V_299 , F_177 , NULL , NULL ) ;
F_20 ( V_12 , V_514 , F_167 , NULL , NULL ) ;
F_20 ( V_12 , V_515 , NULL , F_190 , NULL ) ;
F_20 ( V_12 , V_516 , NULL , F_190 , NULL ) ;
F_20 ( V_517 , V_424 , F_206 , NULL , NULL ) ;
F_20 ( V_517 , V_426 , F_210 , NULL , NULL ) ;
F_20 ( V_517 , V_518 , NULL , F_216 , NULL ) ;
F_20 ( V_517 , V_512 , NULL , F_220 , NULL ) ;
F_20 ( V_517 , V_514 , F_228 , NULL , NULL ) ;
F_20 ( V_517 , V_513 , F_227 , NULL , NULL ) ;
}
