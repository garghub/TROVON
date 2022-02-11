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
F_45 ( sizeof( struct V_158 ) ) ) ;
return V_43 ;
} else
return 0 ;
}
static T_4 F_93 ( const struct V_29 * V_30 ,
T_5 V_149 )
{
T_4 V_159 = F_45 ( 4 )
+ F_45 ( V_160 )
+ F_45 ( sizeof( struct V_161 ) )
+ F_45 ( V_162 )
+ F_45 ( V_162 )
+ F_45 ( 1 )
+ F_45 ( 2 ) ;
T_4 V_163 = F_45 ( sizeof( struct V_42 ) ) ;
T_4 V_164 = F_45 ( sizeof( struct V_42 ) )
+ V_159 ;
T_4 V_165 = F_45 ( sizeof( struct V_42 ) )
+ V_159 ;
if ( ! V_30 -> V_166 -> V_167 || ! V_30 -> V_30 . V_150 ||
! ( V_149 & V_151 ) )
return 0 ;
if ( F_92 ( V_30 -> V_30 . V_150 ) )
return V_165 + V_163 +
V_164 * F_92 ( V_30 -> V_30 . V_150 ) ;
else
return V_165 ;
}
static T_7 T_4 F_94 ( const struct V_29 * V_30 ,
T_5 V_149 )
{
return F_95 ( sizeof( struct V_117 ) )
+ F_45 ( V_168 )
+ F_45 ( V_169 )
+ F_45 ( V_168 )
+ F_45 ( sizeof( struct V_170 ) )
+ F_45 ( sizeof( struct V_121 ) )
+ F_45 ( sizeof( struct V_123 ) )
+ F_45 ( V_171 )
+ F_45 ( V_171 )
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
+ F_45 ( V_172 )
+ F_45 ( V_172 ) ;
}
static int F_96 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_173 ;
struct V_42 * V_174 ;
int V_175 ;
int V_27 ;
V_173 = F_55 ( V_51 , V_176 ) ;
if ( ! V_173 )
return - V_54 ;
for ( V_175 = 0 ; V_175 < F_92 ( V_30 -> V_30 . V_150 ) ; V_175 ++ ) {
V_174 = F_55 ( V_51 , V_177 ) ;
if ( ! V_174 )
goto V_90;
if ( F_74 ( V_51 , V_178 , V_175 ) )
goto V_90;
V_27 = V_30 -> V_166 -> V_167 ( V_30 , V_175 , V_51 ) ;
if ( V_27 == - V_54 )
goto V_90;
if ( V_27 ) {
F_57 ( V_51 , V_174 ) ;
continue;
}
F_56 ( V_51 , V_174 ) ;
}
F_56 ( V_51 , V_173 ) ;
return 0 ;
V_90:
F_57 ( V_51 , V_173 ) ;
return - V_54 ;
}
static int F_97 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_179 ;
int V_27 ;
V_179 = F_55 ( V_51 , V_180 ) ;
if ( ! V_179 )
return - V_54 ;
V_27 = V_30 -> V_166 -> V_167 ( V_30 , V_181 , V_51 ) ;
if ( V_27 ) {
F_57 ( V_51 , V_179 ) ;
return ( V_27 == - V_54 ) ? V_27 : 0 ;
}
F_56 ( V_51 , V_179 ) ;
return 0 ;
}
static int F_98 ( struct V_50 * V_51 , struct V_29 * V_30 ,
T_5 V_149 )
{
int V_27 ;
if ( ! V_30 -> V_166 -> V_167 || ! V_30 -> V_30 . V_150 ||
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
struct V_182 V_183 ;
V_27 = F_100 ( V_30 , & V_183 ) ;
if ( V_27 ) {
if ( V_27 == - V_184 )
return 0 ;
return V_27 ;
}
if ( F_80 ( V_51 , V_185 , V_183 . V_186 , V_183 . V_93 ) )
return - V_54 ;
return 0 ;
}
static int F_101 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
char V_89 [ V_168 ] ;
int V_27 ;
V_27 = F_102 ( V_30 , V_89 , sizeof( V_89 ) ) ;
if ( V_27 ) {
if ( V_27 == - V_184 )
return 0 ;
return V_27 ;
}
if ( F_80 ( V_51 , V_187 , strlen ( V_89 ) , V_89 ) )
return - V_54 ;
return 0 ;
}
static int F_103 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
int V_27 ;
struct V_182 V_188 ;
V_27 = F_104 ( V_30 , & V_188 ) ;
if ( V_27 ) {
if ( V_27 == - V_184 )
return 0 ;
return V_27 ;
}
if ( F_80 ( V_51 , V_189 , V_188 . V_186 , V_188 . V_93 ) )
return - V_54 ;
return 0 ;
}
static int F_105 ( struct V_50 * V_51 , struct V_29 * V_30 ,
int type , T_5 V_68 , T_5 V_190 , T_5 V_191 ,
unsigned int V_78 , T_5 V_149 )
{
struct V_117 * V_118 ;
struct V_76 * V_77 ;
struct V_123 V_192 ;
const struct V_123 * V_193 ;
struct V_42 * V_194 , * V_195 ;
struct V_46 * V_48 ;
struct V_29 * V_196 = F_44 ( V_30 ) ;
F_106 () ;
V_77 = F_107 ( V_51 , V_68 , V_190 , type , sizeof( * V_118 ) , V_78 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_118 = F_108 ( V_77 ) ;
V_118 -> V_197 = V_198 ;
V_118 -> V_199 = 0 ;
V_118 -> V_200 = V_30 -> type ;
V_118 -> V_201 = V_30 -> V_202 ;
V_118 -> V_119 = F_109 ( V_30 ) ;
V_118 -> V_120 = V_191 ;
if ( F_54 ( V_51 , V_203 , V_30 -> V_89 ) ||
F_74 ( V_51 , V_204 , V_30 -> V_205 ) ||
F_110 ( V_51 , V_206 ,
F_111 ( V_30 ) ? V_30 -> V_109 : V_207 ) ||
F_110 ( V_51 , V_208 , V_30 -> V_209 ) ||
F_74 ( V_51 , V_210 , V_30 -> V_211 ) ||
F_74 ( V_51 , V_212 , V_30 -> V_69 ) ||
F_74 ( V_51 , V_213 , V_30 -> V_214 ) ||
F_74 ( V_51 , V_215 , V_30 -> V_216 ) ||
#ifdef F_112
F_74 ( V_51 , V_217 , V_30 -> V_218 ) ||
#endif
( V_30 -> V_202 != F_113 ( V_30 ) &&
F_74 ( V_51 , V_219 , F_113 ( V_30 ) ) ) ||
( V_196 &&
F_74 ( V_51 , V_220 , V_196 -> V_202 ) ) ||
F_110 ( V_51 , V_221 , F_114 ( V_30 ) ) ||
( V_30 -> V_222 &&
F_54 ( V_51 , V_223 , V_30 -> V_222 -> V_20 -> V_93 ) ) ||
( V_30 -> V_224 &&
F_54 ( V_51 , V_225 , V_30 -> V_224 ) ) ||
F_74 ( V_51 , V_226 ,
F_77 ( & V_30 -> V_227 ) ) )
goto V_90;
if ( 1 ) {
struct V_170 V_228 = {
. V_229 = V_30 -> V_229 ,
. V_230 = V_30 -> V_230 ,
. V_231 = V_30 -> V_231 ,
. V_232 = V_30 -> V_232 ,
. V_233 = V_30 -> V_233 ,
. V_234 = V_30 -> V_235 ,
} ;
if ( F_80 ( V_51 , V_236 , sizeof( V_228 ) , & V_228 ) )
goto V_90;
}
if ( V_30 -> V_237 ) {
if ( F_80 ( V_51 , V_238 , V_30 -> V_237 , V_30 -> V_239 ) ||
F_80 ( V_51 , V_240 , V_30 -> V_237 , V_30 -> V_241 ) )
goto V_90;
}
if ( F_99 ( V_51 , V_30 ) )
goto V_90;
if ( F_101 ( V_51 , V_30 ) )
goto V_90;
if ( F_103 ( V_51 , V_30 ) )
goto V_90;
V_194 = F_115 ( V_51 , V_242 ,
sizeof( struct V_121 ) ) ;
if ( V_194 == NULL )
goto V_90;
V_193 = F_116 ( V_30 , & V_192 ) ;
F_88 ( F_117 ( V_194 ) , V_193 ) ;
V_194 = F_115 ( V_51 , V_243 ,
sizeof( struct V_123 ) ) ;
if ( V_194 == NULL )
goto V_90;
F_89 ( F_117 ( V_194 ) , V_193 ) ;
if ( V_30 -> V_30 . V_150 && ( V_149 & V_151 ) &&
F_74 ( V_51 , V_244 , F_92 ( V_30 -> V_30 . V_150 ) ) )
goto V_90;
if ( V_30 -> V_166 -> V_245 && V_30 -> V_30 . V_150
&& ( V_149 & V_151 ) ) {
int V_82 ;
struct V_42 * V_246 , * V_175 ;
int V_152 = F_92 ( V_30 -> V_30 . V_150 ) ;
V_246 = F_55 ( V_51 , V_247 ) ;
if ( ! V_246 )
goto V_90;
for ( V_82 = 0 ; V_82 < V_152 ; V_82 ++ ) {
struct V_248 V_249 ;
struct V_153 V_250 ;
struct V_154 V_251 ;
struct V_156 V_252 ;
struct V_253 V_254 ;
struct V_155 V_255 ;
struct V_157 V_256 ;
struct V_158 V_257 ;
V_249 . V_258 = - 1 ;
V_249 . V_259 = - 1 ;
memset ( V_249 . V_260 , 0 , sizeof( V_249 . V_260 ) ) ;
V_249 . V_261 = 0 ;
if ( V_30 -> V_166 -> V_245 ( V_30 , V_82 , & V_249 ) )
break;
V_250 . V_175 =
V_251 . V_175 =
V_252 . V_175 =
V_254 . V_175 =
V_255 . V_175 =
V_256 . V_175 =
V_257 . V_175 = V_249 . V_175 ;
memcpy ( V_250 . V_260 , V_249 . V_260 , sizeof( V_249 . V_260 ) ) ;
V_251 . V_262 = V_249 . V_262 ;
V_251 . V_263 = V_249 . V_263 ;
V_254 . V_264 = V_249 . V_265 ;
V_252 . V_266 = V_249 . V_266 ;
V_252 . V_265 = V_249 . V_265 ;
V_255 . V_267 = V_249 . V_258 ;
V_256 . V_268 = V_249 . V_261 ;
V_257 . V_267 = V_249 . V_259 ;
V_175 = F_55 ( V_51 , V_269 ) ;
if ( ! V_175 ) {
F_57 ( V_51 , V_246 ) ;
goto V_90;
}
if ( F_80 ( V_51 , V_270 , sizeof( V_250 ) , & V_250 ) ||
F_80 ( V_51 , V_271 , sizeof( V_251 ) , & V_251 ) ||
F_80 ( V_51 , V_272 , sizeof( V_252 ) ,
& V_252 ) ||
F_80 ( V_51 , V_273 , sizeof( V_254 ) ,
& V_254 ) ||
F_80 ( V_51 , V_274 , sizeof( V_255 ) ,
& V_255 ) ||
F_80 ( V_51 , V_275 , sizeof( V_256 ) ,
& V_256 ) ||
F_80 ( V_51 , V_276 ,
sizeof( V_257 ) ,
& V_257 ) )
goto V_90;
F_56 ( V_51 , V_175 ) ;
}
F_56 ( V_51 , V_246 ) ;
}
if ( F_98 ( V_51 , V_30 , V_149 ) )
goto V_90;
if ( V_30 -> V_18 || F_52 ( V_30 ) ) {
if ( F_59 ( V_51 , V_30 ) < 0 )
goto V_90;
}
if ( V_30 -> V_18 &&
V_30 -> V_18 -> V_277 ) {
struct V_28 * V_278 = V_30 -> V_18 -> V_277 ( V_30 ) ;
if ( ! F_118 ( F_119 ( V_30 ) , V_278 ) ) {
int V_93 = F_120 ( F_119 ( V_30 ) , V_278 ) ;
if ( F_121 ( V_51 , V_279 , V_93 ) )
goto V_90;
}
}
if ( ! ( V_195 = F_55 ( V_51 , V_280 ) ) )
goto V_90;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_48 -> V_281 ) {
struct V_42 * V_282 ;
int V_27 ;
if ( ! ( V_282 = F_55 ( V_51 , V_48 -> V_47 ) ) )
goto V_90;
V_27 = V_48 -> V_281 ( V_51 , V_30 ) ;
if ( V_27 == - V_283 )
F_57 ( V_51 , V_282 ) ;
else if ( V_27 < 0 )
goto V_90;
F_56 ( V_51 , V_282 ) ;
}
}
F_56 ( V_51 , V_195 ) ;
F_122 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_123 ( V_51 , V_77 ) ;
return - V_54 ;
}
static int F_124 ( struct V_50 * V_51 , struct V_284 * V_285 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
int V_287 , V_288 ;
int V_289 = 0 , V_290 ;
struct V_29 * V_30 ;
struct V_291 * V_292 ;
struct V_42 * V_293 [ V_294 + 1 ] ;
T_5 V_149 = 0 ;
int V_27 ;
int V_295 ;
V_288 = V_285 -> args [ 0 ] ;
V_290 = V_285 -> args [ 1 ] ;
V_285 -> V_190 = V_28 -> V_296 ;
V_295 = F_126 ( V_285 -> V_77 ) < sizeof( struct V_117 ) ?
sizeof( struct V_297 ) : sizeof( struct V_117 ) ;
if ( F_127 ( V_285 -> V_77 , V_295 , V_293 , V_294 , V_298 ) >= 0 ) {
if ( V_293 [ V_299 ] )
V_149 = F_128 ( V_293 [ V_299 ] ) ;
}
for ( V_287 = V_288 ; V_287 < V_300 ; V_287 ++ , V_290 = 0 ) {
V_289 = 0 ;
V_292 = & V_28 -> V_301 [ V_287 ] ;
F_129 (dev, head, index_hlist) {
if ( V_289 < V_290 )
goto V_302;
V_27 = F_105 ( V_51 , V_30 , V_303 ,
F_61 ( V_285 -> V_51 ) . V_304 ,
V_285 -> V_77 -> V_305 , 0 ,
V_306 ,
V_149 ) ;
F_130 ( ( V_27 == - V_54 ) && ( V_51 -> V_307 == 0 ) ) ;
if ( V_27 < 0 )
goto V_66;
F_131 ( V_285 , F_132 ( V_51 ) ) ;
V_302:
V_289 ++ ;
}
}
V_66:
V_285 -> args [ 1 ] = V_289 ;
V_285 -> args [ 0 ] = V_287 ;
return V_51 -> V_307 ;
}
int F_133 ( struct V_42 * * V_293 , const struct V_42 * V_292 , int V_307 )
{
return F_134 ( V_293 , V_294 , V_292 , V_307 , V_298 ) ;
}
struct V_28 * F_135 ( struct V_28 * V_308 , struct V_42 * V_293 [] )
{
struct V_28 * V_28 ;
if ( V_293 [ V_309 ] )
V_28 = F_136 ( F_128 ( V_293 [ V_309 ] ) ) ;
else if ( V_293 [ V_310 ] )
V_28 = F_137 ( F_128 ( V_293 [ V_310 ] ) ) ;
else
V_28 = F_138 ( V_308 ) ;
return V_28 ;
}
static int F_139 ( struct V_29 * V_30 , struct V_42 * V_293 [] )
{
if ( V_30 ) {
if ( V_293 [ V_238 ] &&
F_140 ( V_293 [ V_238 ] ) < V_30 -> V_237 )
return - V_311 ;
if ( V_293 [ V_240 ] &&
F_140 ( V_293 [ V_240 ] ) < V_30 -> V_237 )
return - V_311 ;
}
if ( V_293 [ V_280 ] ) {
struct V_42 * V_282 ;
int V_312 , V_27 ;
F_141 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_142 ( V_282 ) ) ) )
return - V_313 ;
if ( ! V_48 -> V_314 )
return - V_184 ;
if ( V_48 -> V_315 ) {
V_27 = V_48 -> V_315 ( V_30 , V_282 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_143 ( struct V_29 * V_30 , struct V_42 * V_194 )
{
int V_312 , V_27 = - V_311 ;
struct V_42 * V_175 ;
const struct V_316 * V_20 = V_30 -> V_166 ;
F_141 (vf, attr, rem) {
switch ( F_142 ( V_175 ) ) {
case V_270 : {
struct V_153 * V_317 ;
V_317 = F_117 ( V_175 ) ;
V_27 = - V_184 ;
if ( V_20 -> V_318 )
V_27 = V_20 -> V_318 ( V_30 , V_317 -> V_175 ,
V_317 -> V_260 ) ;
break;
}
case V_271 : {
struct V_154 * V_319 ;
V_319 = F_117 ( V_175 ) ;
V_27 = - V_184 ;
if ( V_20 -> V_320 )
V_27 = V_20 -> V_320 ( V_30 , V_319 -> V_175 ,
V_319 -> V_262 ,
V_319 -> V_263 ) ;
break;
}
case V_273 : {
struct V_253 * V_321 ;
struct V_248 V_322 ;
V_321 = F_117 ( V_175 ) ;
V_27 = - V_184 ;
if ( V_20 -> V_245 )
V_27 = V_20 -> V_245 ( V_30 , V_321 -> V_175 ,
& V_322 ) ;
if ( V_27 )
break;
V_27 = - V_184 ;
if ( V_20 -> V_323 )
V_27 = V_20 -> V_323 ( V_30 , V_321 -> V_175 ,
V_322 . V_266 ,
V_321 -> V_264 ) ;
break;
}
case V_272 : {
struct V_156 * V_321 ;
V_321 = F_117 ( V_175 ) ;
V_27 = - V_184 ;
if ( V_20 -> V_323 )
V_27 = V_20 -> V_323 ( V_30 , V_321 -> V_175 ,
V_321 -> V_266 ,
V_321 -> V_265 ) ;
break;
}
case V_274 : {
struct V_155 * V_324 ;
V_324 = F_117 ( V_175 ) ;
V_27 = - V_184 ;
if ( V_20 -> V_325 )
V_27 = V_20 -> V_325 ( V_30 , V_324 -> V_175 ,
V_324 -> V_267 ) ;
break;
}
case V_275 : {
struct V_157 * V_326 ;
V_326 = F_117 ( V_175 ) ;
V_27 = - V_184 ;
if ( V_20 -> V_327 )
V_27 = V_20 -> V_327 ( V_30 , V_326 -> V_175 ,
V_326 -> V_268 ) ;
break;
}
case V_276 : {
struct V_158 * V_328 ;
V_328 = F_117 ( V_175 ) ;
V_27 = - V_184 ;
if ( V_20 -> V_329 )
V_27 = V_20 -> V_329 ( V_30 ,
V_328 -> V_175 ,
V_328 -> V_267 ) ;
break;
}
default:
V_27 = - V_311 ;
break;
}
if ( V_27 )
break;
}
return V_27 ;
}
static int F_144 ( struct V_29 * V_30 , int V_202 )
{
struct V_29 * V_196 = F_44 ( V_30 ) ;
const struct V_316 * V_20 ;
int V_27 ;
if ( V_196 ) {
if ( V_196 -> V_202 == V_202 )
return 0 ;
V_20 = V_196 -> V_166 ;
if ( V_20 -> V_330 ) {
V_27 = V_20 -> V_330 ( V_196 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_184 ;
}
}
if ( V_202 ) {
V_196 = F_145 ( F_119 ( V_30 ) , V_202 ) ;
if ( ! V_196 )
return - V_311 ;
V_20 = V_196 -> V_166 ;
if ( V_20 -> V_331 ) {
V_27 = V_20 -> V_331 ( V_196 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_184 ;
}
}
return 0 ;
}
static int F_146 ( const struct V_50 * V_51 ,
struct V_29 * V_30 , struct V_117 * V_118 ,
struct V_42 * * V_293 , char * V_332 , int V_333 )
{
const struct V_316 * V_20 = V_30 -> V_166 ;
int V_27 ;
if ( V_293 [ V_309 ] || V_293 [ V_310 ] ) {
struct V_28 * V_28 = F_135 ( F_119 ( V_30 ) , V_293 ) ;
if ( F_147 ( V_28 ) ) {
V_27 = F_148 ( V_28 ) ;
goto V_334;
}
if ( ! F_149 ( V_51 , V_28 -> V_335 , V_336 ) ) {
F_150 ( V_28 ) ;
V_27 = - V_337 ;
goto V_334;
}
V_27 = F_151 ( V_30 , V_28 , V_332 ) ;
F_150 ( V_28 ) ;
if ( V_27 )
goto V_334;
V_333 |= V_338 ;
}
if ( V_293 [ V_236 ] ) {
struct V_170 * V_339 ;
struct V_340 V_341 ;
if ( ! V_20 -> V_342 ) {
V_27 = - V_184 ;
goto V_334;
}
if ( ! F_152 ( V_30 ) ) {
V_27 = - V_343 ;
goto V_334;
}
V_339 = F_117 ( V_293 [ V_236 ] ) ;
V_341 . V_229 = ( unsigned long ) V_339 -> V_229 ;
V_341 . V_230 = ( unsigned long ) V_339 -> V_230 ;
V_341 . V_231 = ( unsigned short ) V_339 -> V_231 ;
V_341 . V_232 = ( unsigned char ) V_339 -> V_232 ;
V_341 . V_233 = ( unsigned char ) V_339 -> V_233 ;
V_341 . V_234 = ( unsigned char ) V_339 -> V_234 ;
V_27 = V_20 -> V_342 ( V_30 , & V_341 ) ;
if ( V_27 < 0 )
goto V_334;
V_333 |= V_344 ;
}
if ( V_293 [ V_238 ] ) {
struct V_345 * V_346 ;
int V_307 ;
V_307 = sizeof( V_347 ) + V_30 -> V_237 ;
V_346 = F_153 ( V_307 , V_15 ) ;
if ( ! V_346 ) {
V_27 = - V_348 ;
goto V_334;
}
V_346 -> V_349 = V_30 -> type ;
memcpy ( V_346 -> V_350 , F_117 ( V_293 [ V_238 ] ) ,
V_30 -> V_237 ) ;
V_27 = F_154 ( V_30 , V_346 ) ;
F_24 ( V_346 ) ;
if ( V_27 )
goto V_334;
V_333 |= V_338 ;
}
if ( V_293 [ V_210 ] ) {
V_27 = F_155 ( V_30 , F_128 ( V_293 [ V_210 ] ) ) ;
if ( V_27 < 0 )
goto V_334;
V_333 |= V_338 ;
}
if ( V_293 [ V_212 ] ) {
F_156 ( V_30 , F_128 ( V_293 [ V_212 ] ) ) ;
V_333 |= V_344 ;
}
if ( V_118 -> V_201 > 0 && V_332 [ 0 ] ) {
V_27 = F_157 ( V_30 , V_332 ) ;
if ( V_27 < 0 )
goto V_334;
V_333 |= V_338 ;
}
if ( V_293 [ V_225 ] ) {
V_27 = F_158 ( V_30 , F_117 ( V_293 [ V_225 ] ) ,
F_140 ( V_293 [ V_225 ] ) ) ;
if ( V_27 < 0 )
goto V_334;
V_333 |= V_344 ;
}
if ( V_293 [ V_240 ] ) {
F_159 ( V_30 -> V_241 , V_293 [ V_240 ] , V_30 -> V_237 ) ;
F_160 ( V_351 , V_30 ) ;
}
if ( V_118 -> V_119 || V_118 -> V_120 ) {
V_27 = F_161 ( V_30 , F_87 ( V_30 , V_118 ) ) ;
if ( V_27 < 0 )
goto V_334;
}
if ( V_293 [ V_220 ] ) {
V_27 = F_144 ( V_30 , F_128 ( V_293 [ V_220 ] ) ) ;
if ( V_27 )
goto V_334;
V_333 |= V_338 ;
}
if ( V_293 [ V_221 ] ) {
V_27 = F_162 ( V_30 , F_163 ( V_293 [ V_221 ] ) ) ;
if ( V_27 )
goto V_334;
V_333 |= V_338 ;
}
if ( V_293 [ V_204 ] ) {
unsigned long V_352 = F_128 ( V_293 [ V_204 ] ) ;
if ( V_30 -> V_205 ^ V_352 )
V_333 |= V_344 ;
V_30 -> V_205 = V_352 ;
}
if ( V_293 [ V_206 ] )
F_81 ( V_30 , F_163 ( V_293 [ V_206 ] ) ) ;
if ( V_293 [ V_208 ] ) {
unsigned char V_352 = F_163 ( V_293 [ V_208 ] ) ;
F_83 ( & V_113 ) ;
if ( V_30 -> V_209 ^ V_352 )
V_333 |= V_344 ;
V_30 -> V_209 = V_352 ;
F_84 ( & V_113 ) ;
}
if ( V_293 [ V_247 ] ) {
struct V_42 * V_194 ;
int V_312 ;
F_141 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_142 ( V_194 ) != V_269 ) {
V_27 = - V_311 ;
goto V_334;
}
V_27 = F_143 ( V_30 , V_194 ) ;
if ( V_27 < 0 )
goto V_334;
V_333 |= V_344 ;
}
}
V_27 = 0 ;
if ( V_293 [ V_176 ] ) {
struct V_42 * V_234 [ V_353 + 1 ] ;
struct V_42 * V_194 ;
int V_175 ;
int V_312 ;
V_27 = - V_184 ;
if ( ! V_20 -> V_354 )
goto V_334;
F_141 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_142 ( V_194 ) != V_177 )
continue;
V_27 = F_164 ( V_234 , V_353 ,
V_194 , V_355 ) ;
if ( V_27 < 0 )
goto V_334;
if ( ! V_234 [ V_178 ] ) {
V_27 = - V_184 ;
goto V_334;
}
V_175 = F_128 ( V_234 [ V_178 ] ) ;
V_27 = V_20 -> V_354 ( V_30 , V_175 , V_234 ) ;
if ( V_27 < 0 )
goto V_334;
V_333 |= V_344 ;
}
}
V_27 = 0 ;
if ( V_293 [ V_180 ] ) {
struct V_42 * V_234 [ V_353 + 1 ] ;
V_27 = F_164 ( V_234 , V_353 ,
V_293 [ V_180 ] , V_355 ) ;
if ( V_27 < 0 )
goto V_334;
V_27 = - V_184 ;
if ( V_20 -> V_354 )
V_27 = V_20 -> V_354 ( V_30 , V_181 , V_234 ) ;
if ( V_27 < 0 )
goto V_334;
V_333 |= V_344 ;
}
if ( V_293 [ V_280 ] ) {
struct V_42 * V_282 ;
int V_312 ;
F_141 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_142 ( V_282 ) ) ) )
F_165 () ;
V_27 = V_48 -> V_314 ( V_30 , V_282 ) ;
if ( V_27 < 0 )
goto V_334;
V_333 |= V_344 ;
}
}
V_27 = 0 ;
V_334:
if ( V_333 & V_338 ) {
if ( V_333 & V_344 )
F_85 ( V_30 ) ;
if ( V_27 < 0 )
F_166 ( L_3 ,
V_30 -> V_89 ) ;
}
return V_27 ;
}
static int F_167 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
struct V_117 * V_118 ;
struct V_29 * V_30 ;
int V_27 ;
struct V_42 * V_293 [ V_294 + 1 ] ;
char V_332 [ V_168 ] ;
V_27 = F_127 ( V_77 , sizeof( * V_118 ) , V_293 , V_294 , V_298 ) ;
if ( V_27 < 0 )
goto V_334;
if ( V_293 [ V_203 ] )
F_168 ( V_332 , V_293 [ V_203 ] , V_168 ) ;
else
V_332 [ 0 ] = '\0' ;
V_27 = - V_311 ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_201 > 0 )
V_30 = F_145 ( V_28 , V_118 -> V_201 ) ;
else if ( V_293 [ V_203 ] )
V_30 = F_169 ( V_28 , V_332 ) ;
else
goto V_334;
if ( V_30 == NULL ) {
V_27 = - V_343 ;
goto V_334;
}
V_27 = F_139 ( V_30 , V_293 ) ;
if ( V_27 < 0 )
goto V_334;
V_27 = F_146 ( V_51 , V_30 , V_118 , V_293 , V_332 , 0 ) ;
V_334:
return V_27 ;
}
static int F_170 ( const struct V_28 * V_28 , int V_69 )
{
struct V_29 * V_30 , * V_356 ;
F_31 ( V_31 ) ;
bool V_357 = false ;
if ( ! V_69 )
return - V_337 ;
F_32 (net, dev) {
if ( V_30 -> V_69 == V_69 ) {
const struct V_18 * V_20 ;
V_357 = true ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_184 ;
}
}
if ( ! V_357 )
return - V_343 ;
F_171 (net, dev, aux) {
if ( V_30 -> V_69 == V_69 ) {
const struct V_18 * V_20 ;
V_20 = V_30 -> V_18 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
}
}
F_33 ( & V_31 ) ;
return 0 ;
}
static int F_172 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
const struct V_18 * V_20 ;
struct V_29 * V_30 ;
struct V_117 * V_118 ;
char V_332 [ V_168 ] ;
struct V_42 * V_293 [ V_294 + 1 ] ;
int V_27 ;
F_31 ( V_31 ) ;
V_27 = F_127 ( V_77 , sizeof( * V_118 ) , V_293 , V_294 , V_298 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_293 [ V_203 ] )
F_168 ( V_332 , V_293 [ V_203 ] , V_168 ) ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_201 > 0 )
V_30 = F_145 ( V_28 , V_118 -> V_201 ) ;
else if ( V_293 [ V_203 ] )
V_30 = F_169 ( V_28 , V_332 ) ;
else if ( V_293 [ V_212 ] )
return F_170 ( V_28 , F_128 ( V_293 [ V_212 ] ) ) ;
else
return - V_311 ;
if ( ! V_30 )
return - V_343 ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_184 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
return 0 ;
}
int F_173 ( struct V_29 * V_30 , const struct V_117 * V_118 )
{
unsigned int V_358 ;
int V_27 ;
V_358 = V_30 -> V_78 ;
if ( V_118 && ( V_118 -> V_119 || V_118 -> V_120 ) ) {
V_27 = F_174 ( V_30 , F_87 ( V_30 , V_118 ) ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_30 -> V_359 = V_360 ;
F_175 ( V_30 , V_358 , ~ 0U ) ;
return 0 ;
}
struct V_29 * F_176 ( struct V_28 * V_28 ,
const char * V_332 , unsigned char V_361 ,
const struct V_18 * V_20 , struct V_42 * V_293 [] )
{
int V_27 ;
struct V_29 * V_30 ;
unsigned int V_216 = 1 ;
unsigned int V_218 = 1 ;
if ( V_293 [ V_215 ] )
V_216 = F_128 ( V_293 [ V_215 ] ) ;
else if ( V_20 -> V_362 )
V_216 = V_20 -> V_362 () ;
if ( V_293 [ V_217 ] )
V_218 = F_128 ( V_293 [ V_217 ] ) ;
else if ( V_20 -> V_363 )
V_218 = V_20 -> V_363 () ;
V_27 = - V_348 ;
V_30 = F_177 ( V_20 -> V_364 , V_332 , V_361 ,
V_20 -> V_22 , V_216 , V_218 ) ;
if ( ! V_30 )
goto V_27;
F_178 ( V_30 , V_28 ) ;
V_30 -> V_18 = V_20 ;
V_30 -> V_359 = V_365 ;
if ( V_293 [ V_210 ] )
V_30 -> V_211 = F_128 ( V_293 [ V_210 ] ) ;
if ( V_293 [ V_238 ] ) {
memcpy ( V_30 -> V_239 , F_117 ( V_293 [ V_238 ] ) ,
F_140 ( V_293 [ V_238 ] ) ) ;
V_30 -> V_366 = V_367 ;
}
if ( V_293 [ V_240 ] )
memcpy ( V_30 -> V_241 , F_117 ( V_293 [ V_240 ] ) ,
F_140 ( V_293 [ V_240 ] ) ) ;
if ( V_293 [ V_204 ] )
V_30 -> V_205 = F_128 ( V_293 [ V_204 ] ) ;
if ( V_293 [ V_206 ] )
F_81 ( V_30 , F_163 ( V_293 [ V_206 ] ) ) ;
if ( V_293 [ V_208 ] )
V_30 -> V_209 = F_163 ( V_293 [ V_208 ] ) ;
if ( V_293 [ V_212 ] )
F_156 ( V_30 , F_128 ( V_293 [ V_212 ] ) ) ;
return V_30 ;
V_27:
return F_179 ( V_27 ) ;
}
static int F_180 ( const struct V_50 * V_51 ,
struct V_28 * V_28 , int V_69 ,
struct V_117 * V_118 ,
struct V_42 * * V_293 )
{
struct V_29 * V_30 , * V_356 ;
int V_27 ;
F_171 (net, dev, aux) {
if ( V_30 -> V_69 == V_69 ) {
V_27 = F_146 ( V_51 , V_30 , V_118 , V_293 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_181 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_368 = NULL ;
struct V_29 * V_30 ;
struct V_29 * V_40 = NULL ;
struct V_117 * V_118 ;
char V_19 [ V_369 ] ;
char V_332 [ V_168 ] ;
struct V_42 * V_293 [ V_294 + 1 ] ;
struct V_42 * V_64 [ V_370 + 1 ] ;
unsigned char V_361 = V_371 ;
int V_27 ;
#ifdef F_182
V_372:
#endif
V_27 = F_127 ( V_77 , sizeof( * V_118 ) , V_293 , V_294 , V_298 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_293 [ V_203 ] )
F_168 ( V_332 , V_293 [ V_203 ] , V_168 ) ;
else
V_332 [ 0 ] = '\0' ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_201 > 0 )
V_30 = F_145 ( V_28 , V_118 -> V_201 ) ;
else {
if ( V_332 [ 0 ] )
V_30 = F_169 ( V_28 , V_332 ) ;
else
V_30 = NULL ;
}
if ( V_30 ) {
V_40 = F_44 ( V_30 ) ;
if ( V_40 )
V_368 = V_40 -> V_18 ;
}
V_27 = F_139 ( V_30 , V_293 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_293 [ V_65 ] ) {
V_27 = F_164 ( V_64 , V_370 ,
V_293 [ V_65 ] , V_373 ) ;
if ( V_27 < 0 )
return V_27 ;
} else
memset ( V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_64 [ V_59 ] ) {
F_168 ( V_19 , V_64 [ V_59 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_42 * V_194 [ V_20 ? V_20 -> V_374 + 1 : 1 ] ;
struct V_42 * V_375 [ V_368 ? V_368 -> V_376 + 1 : 1 ] ;
struct V_42 * * V_58 = NULL ;
struct V_42 * * V_52 = NULL ;
struct V_28 * V_377 , * V_278 = NULL ;
if ( V_20 ) {
if ( V_20 -> V_374 && V_64 [ V_62 ] ) {
V_27 = F_164 ( V_194 , V_20 -> V_374 ,
V_64 [ V_62 ] ,
V_20 -> V_378 ) ;
if ( V_27 < 0 )
return V_27 ;
V_58 = V_194 ;
}
if ( V_20 -> V_379 ) {
V_27 = V_20 -> V_379 ( V_293 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_368 ) {
if ( V_368 -> V_376 &&
V_64 [ V_56 ] ) {
V_27 = F_164 ( V_375 ,
V_368 -> V_376 ,
V_64 [ V_56 ] ,
V_368 -> V_380 ) ;
if ( V_27 < 0 )
return V_27 ;
V_52 = V_375 ;
}
if ( V_368 -> V_381 ) {
V_27 = V_368 -> V_381 ( V_293 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_30 ) {
int V_333 = 0 ;
if ( V_77 -> V_382 & V_383 )
return - V_21 ;
if ( V_77 -> V_382 & V_384 )
return - V_184 ;
if ( V_64 [ V_62 ] ) {
if ( ! V_20 || V_20 != V_30 -> V_18 ||
! V_20 -> V_385 )
return - V_184 ;
V_27 = V_20 -> V_385 ( V_30 , V_293 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
V_333 |= V_344 ;
}
if ( V_64 [ V_56 ] ) {
if ( ! V_368 || ! V_368 -> V_386 )
return - V_184 ;
V_27 = V_368 -> V_386 ( V_40 , V_30 ,
V_293 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
V_333 |= V_344 ;
}
return F_146 ( V_51 , V_30 , V_118 , V_293 , V_332 , V_333 ) ;
}
if ( ! ( V_77 -> V_382 & V_387 ) ) {
if ( V_118 -> V_201 == 0 && V_293 [ V_212 ] )
return F_180 ( V_51 , V_28 ,
F_128 ( V_293 [ V_212 ] ) ,
V_118 , V_293 ) ;
return - V_343 ;
}
if ( V_293 [ V_236 ] || V_293 [ V_220 ] || V_293 [ V_388 ] )
return - V_184 ;
if ( ! V_20 ) {
#ifdef F_182
if ( V_19 [ 0 ] ) {
F_3 () ;
F_183 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_372;
}
#endif
return - V_184 ;
}
if ( ! V_20 -> V_22 )
return - V_184 ;
if ( ! V_332 [ 0 ] ) {
snprintf ( V_332 , V_168 , L_5 , V_20 -> V_19 ) ;
V_361 = V_389 ;
}
V_377 = F_135 ( V_28 , V_293 ) ;
if ( F_147 ( V_377 ) )
return F_148 ( V_377 ) ;
V_27 = - V_337 ;
if ( ! F_149 ( V_51 , V_377 -> V_335 , V_336 ) )
goto V_66;
if ( V_293 [ V_279 ] ) {
int V_93 = F_184 ( V_293 [ V_279 ] ) ;
V_278 = F_185 ( V_377 , V_93 ) ;
if ( ! V_278 ) {
V_27 = - V_311 ;
goto V_66;
}
V_27 = - V_337 ;
if ( ! F_149 ( V_51 , V_278 -> V_335 , V_336 ) )
goto V_66;
}
V_30 = F_176 ( V_278 ? : V_377 , V_332 ,
V_361 , V_20 , V_293 ) ;
if ( F_147 ( V_30 ) ) {
V_27 = F_148 ( V_30 ) ;
goto V_66;
}
V_30 -> V_202 = V_118 -> V_201 ;
if ( V_20 -> V_390 ) {
V_27 = V_20 -> V_390 ( V_278 ? : V_28 , V_30 , V_293 , V_58 ) ;
if ( V_27 < 0 ) {
if ( V_30 -> V_391 == V_392 )
F_186 ( V_30 ) ;
goto V_66;
}
} else {
V_27 = F_187 ( V_30 ) ;
if ( V_27 < 0 ) {
F_186 ( V_30 ) ;
goto V_66;
}
}
V_27 = F_173 ( V_30 , V_118 ) ;
if ( V_27 < 0 )
goto V_393;
if ( V_278 ) {
V_27 = F_151 ( V_30 , V_377 , V_332 ) ;
if ( V_27 < 0 )
goto V_393;
}
V_66:
if ( V_278 )
F_150 ( V_278 ) ;
F_150 ( V_377 ) ;
return V_27 ;
V_393:
if ( V_20 -> V_390 ) {
F_31 ( V_31 ) ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
} else {
F_188 ( V_30 ) ;
}
goto V_66;
}
}
static int F_189 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
struct V_117 * V_118 ;
char V_332 [ V_168 ] ;
struct V_42 * V_293 [ V_294 + 1 ] ;
struct V_29 * V_30 = NULL ;
struct V_50 * V_394 ;
int V_27 ;
T_5 V_149 = 0 ;
V_27 = F_127 ( V_77 , sizeof( * V_118 ) , V_293 , V_294 , V_298 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_293 [ V_203 ] )
F_168 ( V_332 , V_293 [ V_203 ] , V_168 ) ;
if ( V_293 [ V_299 ] )
V_149 = F_128 ( V_293 [ V_299 ] ) ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_201 > 0 )
V_30 = F_145 ( V_28 , V_118 -> V_201 ) ;
else if ( V_293 [ V_203 ] )
V_30 = F_169 ( V_28 , V_332 ) ;
else
return - V_311 ;
if ( V_30 == NULL )
return - V_343 ;
V_394 = F_190 ( F_94 ( V_30 , V_149 ) , V_15 ) ;
if ( V_394 == NULL )
return - V_16 ;
V_27 = F_105 ( V_394 , V_30 , V_303 , F_61 ( V_51 ) . V_304 ,
V_77 -> V_305 , 0 , 0 , V_149 ) ;
if ( V_27 < 0 ) {
F_130 ( V_27 == - V_54 ) ;
F_191 ( V_394 ) ;
} else
V_27 = F_65 ( V_394 , V_28 , F_61 ( V_51 ) . V_304 ) ;
return V_27 ;
}
static T_8 F_192 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
struct V_29 * V_30 ;
struct V_42 * V_293 [ V_294 + 1 ] ;
T_5 V_149 = 0 ;
T_8 V_395 = 0 ;
int V_295 ;
V_295 = F_126 ( V_77 ) < sizeof( struct V_117 ) ?
sizeof( struct V_297 ) : sizeof( struct V_117 ) ;
if ( F_127 ( V_77 , V_295 , V_293 , V_294 , V_298 ) >= 0 ) {
if ( V_293 [ V_299 ] )
V_149 = F_128 ( V_293 [ V_299 ] ) ;
}
if ( ! V_149 )
return V_396 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_395 = F_193 ( T_8 , V_395 ,
F_94 ( V_30 ,
V_149 ) ) ;
}
return V_395 ;
}
static int F_194 ( struct V_50 * V_51 , struct V_284 * V_285 )
{
int V_289 ;
int V_290 = V_285 -> V_47 ;
if ( V_290 == 0 )
V_290 = 1 ;
for ( V_289 = 1 ; V_289 <= V_9 ; V_289 ++ ) {
int type = V_285 -> V_77 -> V_397 - V_4 ;
if ( V_289 < V_290 || V_289 == V_398 )
continue;
if ( V_10 [ V_289 ] == NULL ||
V_10 [ V_289 ] [ type ] . V_13 == NULL )
continue;
if ( V_289 > V_290 ) {
memset ( & V_285 -> args [ 0 ] , 0 , sizeof( V_285 -> args ) ) ;
V_285 -> V_399 = 0 ;
V_285 -> V_190 = 0 ;
}
if ( V_10 [ V_289 ] [ type ] . V_13 ( V_51 , V_285 ) )
break;
}
V_285 -> V_47 = V_289 ;
return V_51 -> V_307 ;
}
struct V_50 * F_195 ( int type , struct V_29 * V_30 ,
unsigned int V_191 , T_6 V_78 )
{
struct V_28 * V_28 = F_119 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
T_4 V_400 ;
V_51 = F_190 ( ( V_400 = F_94 ( V_30 , 0 ) ) , V_78 ) ;
if ( V_51 == NULL )
goto V_334;
V_27 = F_105 ( V_51 , V_30 , type , 0 , 0 , V_191 , 0 , 0 ) ;
if ( V_27 < 0 ) {
F_130 ( V_27 == - V_54 ) ;
F_191 ( V_51 ) ;
goto V_334;
}
return V_51 ;
V_334:
if ( V_27 < 0 )
F_70 ( V_28 , V_401 , V_27 ) ;
return NULL ;
}
void F_196 ( struct V_50 * V_51 , struct V_29 * V_30 , T_6 V_78 )
{
struct V_28 * V_28 = F_119 ( V_30 ) ;
F_67 ( V_51 , V_28 , 0 , V_401 , NULL , V_78 ) ;
}
void F_197 ( int type , struct V_29 * V_30 , unsigned int V_191 ,
T_6 V_78 )
{
struct V_50 * V_51 ;
if ( V_30 -> V_391 != V_402 )
return;
V_51 = F_195 ( type , V_30 , V_191 , V_78 ) ;
if ( V_51 )
F_196 ( V_51 , V_30 , V_78 ) ;
}
static int F_198 ( struct V_50 * V_51 ,
struct V_29 * V_30 ,
T_9 * V_403 , T_8 V_404 , T_5 V_68 , T_5 V_190 ,
int type , unsigned int V_78 ,
int V_405 )
{
struct V_76 * V_77 ;
struct V_406 * V_407 ;
V_77 = F_107 ( V_51 , V_68 , V_190 , type , sizeof( * V_407 ) , V_405 ) ;
if ( ! V_77 )
return - V_54 ;
V_407 = F_108 ( V_77 ) ;
V_407 -> V_408 = V_409 ;
V_407 -> V_410 = 0 ;
V_407 -> V_411 = 0 ;
V_407 -> V_412 = V_78 ;
V_407 -> V_413 = 0 ;
V_407 -> V_414 = V_30 -> V_202 ;
V_407 -> V_415 = V_416 ;
if ( F_80 ( V_51 , V_417 , V_418 , V_403 ) )
goto V_90;
if ( V_404 )
if ( F_80 ( V_51 , V_419 , sizeof( T_8 ) , & V_404 ) )
goto V_90;
F_122 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_123 ( V_51 , V_77 ) ;
return - V_54 ;
}
static inline T_4 F_199 ( void )
{
return F_95 ( sizeof( struct V_406 ) ) + F_45 ( V_418 ) ;
}
static void F_200 ( struct V_29 * V_30 , T_9 * V_403 , T_8 V_404 , int type )
{
struct V_28 * V_28 = F_119 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
V_51 = F_190 ( F_199 () , V_420 ) ;
if ( ! V_51 )
goto V_334;
V_27 = F_198 ( V_51 , V_30 , V_403 , V_404 ,
0 , 0 , type , V_421 , 0 ) ;
if ( V_27 < 0 ) {
F_191 ( V_51 ) ;
goto V_334;
}
F_67 ( V_51 , V_28 , 0 , V_422 , NULL , V_420 ) ;
return;
V_334:
F_70 ( V_28 , V_422 , V_27 ) ;
}
int F_201 ( struct V_406 * V_407 ,
struct V_42 * V_293 [] ,
struct V_29 * V_30 ,
const unsigned char * V_403 , T_8 V_404 ,
T_8 V_78 )
{
int V_27 = - V_311 ;
if ( V_407 -> V_415 && ! ( V_407 -> V_415 & V_416 ) ) {
F_202 ( L_6 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( V_404 ) {
F_202 ( L_7 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( F_203 ( V_403 ) || F_204 ( V_403 ) )
V_27 = F_205 ( V_30 , V_403 ) ;
else if ( F_206 ( V_403 ) )
V_27 = F_207 ( V_30 , V_403 ) ;
if ( V_27 == - V_21 && ! ( V_78 & V_383 ) )
V_27 = 0 ;
return V_27 ;
}
static int F_208 ( struct V_42 * V_423 , T_8 * V_424 )
{
T_8 V_404 = 0 ;
if ( V_423 ) {
if ( F_140 ( V_423 ) != sizeof( T_8 ) ) {
F_202 ( L_8 ) ;
return - V_311 ;
}
V_404 = F_209 ( V_423 ) ;
if ( ! V_404 || V_404 >= V_425 ) {
F_202 ( L_9 ,
V_404 ) ;
return - V_311 ;
}
}
* V_424 = V_404 ;
return 0 ;
}
static int F_210 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
struct V_406 * V_407 ;
struct V_42 * V_293 [ V_426 + 1 ] ;
struct V_29 * V_30 ;
T_9 * V_403 ;
T_8 V_404 ;
int V_27 ;
V_27 = F_127 ( V_77 , sizeof( * V_407 ) , V_293 , V_426 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_407 = F_108 ( V_77 ) ;
if ( V_407 -> V_414 == 0 ) {
F_202 ( L_10 ) ;
return - V_311 ;
}
V_30 = F_145 ( V_28 , V_407 -> V_414 ) ;
if ( V_30 == NULL ) {
F_202 ( L_11 ) ;
return - V_343 ;
}
if ( ! V_293 [ V_417 ] || F_140 ( V_293 [ V_417 ] ) != V_418 ) {
F_202 ( L_12 ) ;
return - V_311 ;
}
V_403 = F_117 ( V_293 [ V_417 ] ) ;
V_27 = F_208 ( V_293 [ V_419 ] , & V_404 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_184 ;
if ( ( ! V_407 -> V_412 || V_407 -> V_412 & V_427 ) &&
( V_30 -> V_428 & V_429 ) ) {
struct V_29 * V_430 = F_44 ( V_30 ) ;
const struct V_316 * V_20 = V_430 -> V_166 ;
V_27 = V_20 -> V_431 ( V_407 , V_293 , V_30 , V_403 , V_404 ,
V_77 -> V_382 ) ;
if ( V_27 )
goto V_66;
else
V_407 -> V_412 &= ~ V_427 ;
}
if ( ( V_407 -> V_412 & V_421 ) ) {
if ( V_30 -> V_166 -> V_431 )
V_27 = V_30 -> V_166 -> V_431 ( V_407 , V_293 , V_30 , V_403 ,
V_404 ,
V_77 -> V_382 ) ;
else
V_27 = F_201 ( V_407 , V_293 , V_30 , V_403 , V_404 ,
V_77 -> V_382 ) ;
if ( ! V_27 ) {
F_200 ( V_30 , V_403 , V_404 , V_432 ) ;
V_407 -> V_412 &= ~ V_421 ;
}
}
V_66:
return V_27 ;
}
int F_211 ( struct V_406 * V_407 ,
struct V_42 * V_293 [] ,
struct V_29 * V_30 ,
const unsigned char * V_403 , T_8 V_404 )
{
int V_27 = - V_311 ;
if ( ! ( V_407 -> V_415 & V_416 ) ) {
F_202 ( L_6 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( F_203 ( V_403 ) || F_204 ( V_403 ) )
V_27 = F_212 ( V_30 , V_403 ) ;
else if ( F_206 ( V_403 ) )
V_27 = F_213 ( V_30 , V_403 ) ;
return V_27 ;
}
static int F_214 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
struct V_406 * V_407 ;
struct V_42 * V_293 [ V_426 + 1 ] ;
struct V_29 * V_30 ;
int V_27 = - V_311 ;
T_10 * V_403 ;
T_8 V_404 ;
if ( ! F_215 ( V_51 , V_336 ) )
return - V_337 ;
V_27 = F_127 ( V_77 , sizeof( * V_407 ) , V_293 , V_426 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_407 = F_108 ( V_77 ) ;
if ( V_407 -> V_414 == 0 ) {
F_202 ( L_13 ) ;
return - V_311 ;
}
V_30 = F_145 ( V_28 , V_407 -> V_414 ) ;
if ( V_30 == NULL ) {
F_202 ( L_14 ) ;
return - V_343 ;
}
if ( ! V_293 [ V_417 ] || F_140 ( V_293 [ V_417 ] ) != V_418 ) {
F_202 ( L_15 ) ;
return - V_311 ;
}
V_403 = F_117 ( V_293 [ V_417 ] ) ;
V_27 = F_208 ( V_293 [ V_419 ] , & V_404 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_184 ;
if ( ( ! V_407 -> V_412 || V_407 -> V_412 & V_427 ) &&
( V_30 -> V_428 & V_429 ) ) {
struct V_29 * V_430 = F_44 ( V_30 ) ;
const struct V_316 * V_20 = V_430 -> V_166 ;
if ( V_20 -> V_433 )
V_27 = V_20 -> V_433 ( V_407 , V_293 , V_30 , V_403 , V_404 ) ;
if ( V_27 )
goto V_66;
else
V_407 -> V_412 &= ~ V_427 ;
}
if ( V_407 -> V_412 & V_421 ) {
if ( V_30 -> V_166 -> V_433 )
V_27 = V_30 -> V_166 -> V_433 ( V_407 , V_293 , V_30 , V_403 ,
V_404 ) ;
else
V_27 = F_211 ( V_407 , V_293 , V_30 , V_403 , V_404 ) ;
if ( ! V_27 ) {
F_200 ( V_30 , V_403 , V_404 , V_434 ) ;
V_407 -> V_412 &= ~ V_421 ;
}
}
V_66:
return V_27 ;
}
static int F_216 ( struct V_50 * V_51 ,
struct V_284 * V_285 ,
struct V_29 * V_30 ,
int * V_289 ,
struct V_435 * V_25 )
{
struct V_436 * V_437 ;
int V_27 ;
T_5 V_304 , V_190 ;
V_304 = F_61 ( V_285 -> V_51 ) . V_304 ;
V_190 = V_285 -> V_77 -> V_305 ;
F_26 (ha, &list->list, list) {
if ( * V_289 < V_285 -> args [ 0 ] )
goto V_438;
V_27 = F_198 ( V_51 , V_30 , V_437 -> V_403 , 0 ,
V_304 , V_190 ,
V_432 , V_421 ,
V_306 ) ;
if ( V_27 < 0 )
return V_27 ;
V_438:
* V_289 += 1 ;
}
return 0 ;
}
int F_217 ( struct V_50 * V_51 ,
struct V_284 * V_285 ,
struct V_29 * V_30 ,
struct V_29 * V_439 ,
int V_289 )
{
int V_27 ;
F_218 ( V_30 ) ;
V_27 = F_216 ( V_51 , V_285 , V_30 , & V_289 , & V_30 -> V_440 ) ;
if ( V_27 )
goto V_66;
F_216 ( V_51 , V_285 , V_30 , & V_289 , & V_30 -> V_441 ) ;
V_66:
F_219 ( V_30 ) ;
return V_289 ;
}
static int F_220 ( struct V_50 * V_51 , struct V_284 * V_285 )
{
struct V_29 * V_30 ;
struct V_42 * V_293 [ V_294 + 1 ] ;
struct V_29 * V_430 = NULL ;
const struct V_316 * V_20 = NULL ;
const struct V_316 * V_442 = NULL ;
struct V_117 * V_118 = F_108 ( V_285 -> V_77 ) ;
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
int V_443 = 0 ;
int V_444 = 0 ;
int V_289 = 0 ;
if ( F_127 ( V_285 -> V_77 , sizeof( struct V_117 ) , V_293 , V_294 ,
V_298 ) == 0 ) {
if ( V_293 [ V_220 ] )
V_444 = F_128 ( V_293 [ V_220 ] ) ;
}
V_443 = V_118 -> V_201 ;
if ( V_444 ) {
V_430 = F_145 ( V_28 , V_444 ) ;
if ( ! V_430 )
return - V_343 ;
V_20 = V_430 -> V_166 ;
}
F_32 (net, dev) {
if ( V_443 && ( V_30 -> V_202 != V_443 ) )
continue;
if ( ! V_444 ) {
if ( V_30 -> V_428 & V_429 ) {
V_430 = F_44 ( V_30 ) ;
V_442 = V_430 -> V_166 ;
}
} else {
if ( V_30 != V_430 &&
! ( V_30 -> V_428 & V_429 ) )
continue;
if ( V_430 != F_44 ( V_30 ) &&
! ( V_30 -> V_428 & V_445 ) )
continue;
V_442 = V_20 ;
}
if ( V_30 -> V_428 & V_429 ) {
if ( V_442 && V_442 -> V_446 )
V_289 = V_442 -> V_446 ( V_51 , V_285 , V_430 , V_30 ,
V_289 ) ;
}
if ( V_30 -> V_166 -> V_446 )
V_289 = V_30 -> V_166 -> V_446 ( V_51 , V_285 , V_30 , NULL ,
V_289 ) ;
else
V_289 = F_217 ( V_51 , V_285 , V_30 , NULL , V_289 ) ;
V_442 = NULL ;
}
V_285 -> args [ 0 ] = V_289 ;
return V_51 -> V_307 ;
}
static int F_221 ( struct V_50 * V_51 , T_5 V_78 , T_5 V_447 ,
unsigned int V_448 , unsigned int V_449 )
{
if ( V_447 & V_449 )
return F_110 ( V_51 , V_448 , ! ! ( V_78 & V_449 ) ) ;
return 0 ;
}
int F_222 ( struct V_50 * V_51 , T_5 V_68 , T_5 V_190 ,
struct V_29 * V_30 , T_8 V_450 ,
T_5 V_78 , T_5 V_447 , int V_405 )
{
struct V_76 * V_77 ;
struct V_117 * V_118 ;
struct V_42 * V_451 ;
struct V_42 * V_452 ;
T_9 V_109 = F_111 ( V_30 ) ? V_30 -> V_109 : V_207 ;
struct V_29 * V_430 = F_44 ( V_30 ) ;
V_77 = F_107 ( V_51 , V_68 , V_190 , V_303 , sizeof( * V_118 ) , V_405 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_118 = F_108 ( V_77 ) ;
V_118 -> V_197 = V_409 ;
V_118 -> V_199 = 0 ;
V_118 -> V_200 = V_30 -> type ;
V_118 -> V_201 = V_30 -> V_202 ;
V_118 -> V_119 = F_109 ( V_30 ) ;
V_118 -> V_120 = 0 ;
if ( F_54 ( V_51 , V_203 , V_30 -> V_89 ) ||
F_74 ( V_51 , V_210 , V_30 -> V_211 ) ||
F_110 ( V_51 , V_206 , V_109 ) ||
( V_430 &&
F_74 ( V_51 , V_220 , V_430 -> V_202 ) ) ||
( V_30 -> V_237 &&
F_80 ( V_51 , V_238 , V_30 -> V_237 , V_30 -> V_239 ) ) ||
( V_30 -> V_202 != F_113 ( V_30 ) &&
F_74 ( V_51 , V_219 , F_113 ( V_30 ) ) ) )
goto V_90;
V_451 = F_55 ( V_51 , V_280 ) ;
if ( ! V_451 )
goto V_90;
if ( F_223 ( V_51 , V_453 , V_454 ) ) {
F_57 ( V_51 , V_451 ) ;
goto V_90;
}
if ( V_450 != V_455 ) {
if ( F_223 ( V_51 , V_456 , V_450 ) ) {
F_57 ( V_51 , V_451 ) ;
goto V_90;
}
}
F_56 ( V_51 , V_451 ) ;
V_452 = F_55 ( V_51 , V_388 | V_457 ) ;
if ( ! V_452 )
goto V_90;
if ( F_221 ( V_51 , V_78 , V_447 ,
V_458 , V_459 ) ||
F_221 ( V_51 , V_78 , V_447 ,
V_460 , V_461 ) ||
F_221 ( V_51 , V_78 , V_447 ,
V_462 ,
V_463 ) ||
F_221 ( V_51 , V_78 , V_447 ,
V_464 , V_465 ) ||
F_221 ( V_51 , V_78 , V_447 ,
V_466 , V_467 ) ||
F_221 ( V_51 , V_78 , V_447 ,
V_468 , V_469 ) ||
F_221 ( V_51 , V_78 , V_447 ,
V_470 , V_471 ) ||
F_221 ( V_51 , V_78 , V_447 ,
V_472 , V_473 ) ) {
F_57 ( V_51 , V_452 ) ;
goto V_90;
}
F_56 ( V_51 , V_452 ) ;
F_122 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_123 ( V_51 , V_77 ) ;
return - V_54 ;
}
static int F_224 ( struct V_50 * V_51 , struct V_284 * V_285 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
struct V_29 * V_30 ;
int V_289 = 0 ;
T_5 V_304 = F_61 ( V_285 -> V_51 ) . V_304 ;
T_5 V_190 = V_285 -> V_77 -> V_305 ;
T_5 V_474 = 0 ;
if ( F_126 ( V_285 -> V_77 ) > sizeof( struct V_117 ) ) {
struct V_42 * V_475 ;
V_475 = F_225 ( V_285 -> V_77 , sizeof( struct V_117 ) ,
V_299 ) ;
if ( V_475 ) {
if ( F_140 ( V_475 ) < sizeof( V_474 ) )
return - V_311 ;
V_474 = F_128 ( V_475 ) ;
}
}
F_226 () ;
F_227 (net, dev) {
const struct V_316 * V_20 = V_30 -> V_166 ;
struct V_29 * V_430 = F_44 ( V_30 ) ;
if ( V_430 && V_430 -> V_166 -> V_476 ) {
if ( V_289 >= V_285 -> args [ 0 ] &&
V_430 -> V_166 -> V_476 (
V_51 , V_304 , V_190 , V_30 , V_474 ,
V_306 ) < 0 )
break;
V_289 ++ ;
}
if ( V_20 -> V_476 ) {
if ( V_289 >= V_285 -> args [ 0 ] &&
V_20 -> V_476 ( V_51 , V_304 , V_190 , V_30 ,
V_474 ,
V_306 ) < 0 )
break;
V_289 ++ ;
}
}
F_228 () ;
V_285 -> args [ 0 ] = V_289 ;
return V_51 -> V_307 ;
}
static inline T_4 F_229 ( void )
{
return F_95 ( sizeof( struct V_117 ) )
+ F_45 ( V_168 )
+ F_45 ( V_171 )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_9 ) )
+ F_45 ( sizeof( struct V_42 ) )
+ F_45 ( sizeof( T_8 ) )
+ F_45 ( sizeof( T_8 ) ) ;
}
static int F_230 ( struct V_29 * V_30 )
{
struct V_28 * V_28 = F_119 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_184 ;
if ( ! V_30 -> V_166 -> V_476 )
return 0 ;
V_51 = F_190 ( F_229 () , V_420 ) ;
if ( ! V_51 ) {
V_27 = - V_348 ;
goto V_334;
}
V_27 = V_30 -> V_166 -> V_476 ( V_51 , 0 , 0 , V_30 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_334;
if ( ! V_51 -> V_307 )
goto V_334;
F_67 ( V_51 , V_28 , 0 , V_401 , NULL , V_420 ) ;
return 0 ;
V_334:
F_130 ( V_27 == - V_54 ) ;
F_191 ( V_51 ) ;
if ( V_27 )
F_70 ( V_28 , V_401 , V_27 ) ;
return V_27 ;
}
static int F_231 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
struct V_117 * V_118 ;
struct V_29 * V_30 ;
struct V_42 * V_477 , * V_194 = NULL ;
int V_312 , V_27 = - V_184 ;
T_8 V_78 = 0 ;
bool V_478 = false ;
if ( F_126 ( V_77 ) < sizeof( * V_118 ) )
return - V_311 ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_197 != V_409 )
return - V_479 ;
V_30 = F_145 ( V_28 , V_118 -> V_201 ) ;
if ( ! V_30 ) {
F_202 ( L_16 ) ;
return - V_343 ;
}
V_477 = F_225 ( V_77 , sizeof( struct V_117 ) , V_280 ) ;
if ( V_477 ) {
F_141 (attr, br_spec, rem) {
if ( F_142 ( V_194 ) == V_453 ) {
if ( F_140 ( V_194 ) < sizeof( V_78 ) )
return - V_311 ;
V_478 = true ;
V_78 = F_209 ( V_194 ) ;
break;
}
}
}
if ( ! V_78 || ( V_78 & V_480 ) ) {
struct V_29 * V_430 = F_44 ( V_30 ) ;
if ( ! V_430 || ! V_430 -> V_166 -> V_481 ) {
V_27 = - V_184 ;
goto V_66;
}
V_27 = V_430 -> V_166 -> V_481 ( V_30 , V_77 , V_78 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_480 ;
}
if ( ( V_78 & V_454 ) ) {
if ( ! V_30 -> V_166 -> V_481 )
V_27 = - V_184 ;
else
V_27 = V_30 -> V_166 -> V_481 ( V_30 , V_77 ,
V_78 ) ;
if ( ! V_27 ) {
V_78 &= ~ V_454 ;
V_27 = F_230 ( V_30 ) ;
}
}
if ( V_478 )
memcpy ( F_117 ( V_194 ) , & V_78 , sizeof( V_78 ) ) ;
V_66:
return V_27 ;
}
static int F_232 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
struct V_117 * V_118 ;
struct V_29 * V_30 ;
struct V_42 * V_477 , * V_194 = NULL ;
int V_312 , V_27 = - V_184 ;
T_8 V_78 = 0 ;
bool V_478 = false ;
if ( F_126 ( V_77 ) < sizeof( * V_118 ) )
return - V_311 ;
V_118 = F_108 ( V_77 ) ;
if ( V_118 -> V_197 != V_409 )
return - V_479 ;
V_30 = F_145 ( V_28 , V_118 -> V_201 ) ;
if ( ! V_30 ) {
F_202 ( L_16 ) ;
return - V_343 ;
}
V_477 = F_225 ( V_77 , sizeof( struct V_117 ) , V_280 ) ;
if ( V_477 ) {
F_141 (attr, br_spec, rem) {
if ( F_142 ( V_194 ) == V_453 ) {
if ( F_140 ( V_194 ) < sizeof( V_78 ) )
return - V_311 ;
V_478 = true ;
V_78 = F_209 ( V_194 ) ;
break;
}
}
}
if ( ! V_78 || ( V_78 & V_480 ) ) {
struct V_29 * V_430 = F_44 ( V_30 ) ;
if ( ! V_430 || ! V_430 -> V_166 -> V_482 ) {
V_27 = - V_184 ;
goto V_66;
}
V_27 = V_430 -> V_166 -> V_482 ( V_30 , V_77 , V_78 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_480 ;
}
if ( ( V_78 & V_454 ) ) {
if ( ! V_30 -> V_166 -> V_482 )
V_27 = - V_184 ;
else
V_27 = V_30 -> V_166 -> V_482 ( V_30 , V_77 ,
V_78 ) ;
if ( ! V_27 ) {
V_78 &= ~ V_454 ;
V_27 = F_230 ( V_30 ) ;
}
}
if ( V_478 )
memcpy ( F_117 ( V_194 ) , & V_78 , sizeof( V_78 ) ) ;
V_66:
return V_27 ;
}
static int F_233 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_125 ( V_51 -> V_286 ) ;
T_1 V_11 ;
int V_483 , V_19 ;
int V_47 ;
int type ;
int V_27 ;
type = V_77 -> V_397 ;
if ( type > V_484 )
return - V_184 ;
type -= V_4 ;
if ( F_126 ( V_77 ) < sizeof( struct V_297 ) )
return 0 ;
V_47 = ( (struct V_297 * ) F_108 ( V_77 ) ) -> V_485 ;
V_483 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_234 ( V_51 , V_336 ) )
return - V_337 ;
if ( V_19 == 2 && V_77 -> V_382 & V_486 ) {
struct V_71 * V_72 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_487 = 0 ;
V_13 = F_16 ( V_47 , type ) ;
if ( V_13 == NULL )
return - V_184 ;
V_14 = F_17 ( V_47 , type ) ;
if ( V_14 )
V_487 = V_14 ( V_51 , V_77 ) ;
F_3 () ;
V_72 = V_28 -> V_72 ;
{
struct V_488 V_489 = {
. V_490 = V_13 ,
. V_487 = V_487 ,
} ;
V_27 = F_235 ( V_72 , V_51 , V_77 , & V_489 ) ;
}
F_1 () ;
return V_27 ;
}
V_11 = F_15 ( V_47 , type ) ;
if ( V_11 == NULL )
return - V_184 ;
return V_11 ( V_51 , V_77 ) ;
}
static void F_236 ( struct V_50 * V_51 )
{
F_1 () ;
F_237 ( V_51 , & F_233 ) ;
F_5 () ;
}
static int F_238 ( struct V_491 * V_492 , unsigned long V_493 , void * V_494 )
{
struct V_29 * V_30 = F_239 ( V_494 ) ;
switch ( V_493 ) {
case V_495 :
case V_496 :
case V_497 :
case V_498 :
case V_499 :
case V_500 :
case V_501 :
case V_502 :
case V_503 :
case V_504 :
case V_505 :
case V_506 :
case V_507 :
break;
default:
F_197 ( V_303 , V_30 , 0 , V_15 ) ;
break;
}
return V_508 ;
}
static int T_11 F_240 ( struct V_28 * V_28 )
{
struct V_71 * V_286 ;
struct V_509 V_510 = {
. V_511 = V_512 ,
. V_513 = F_236 ,
. V_514 = & V_1 ,
. V_78 = V_515 ,
} ;
V_286 = F_241 ( V_28 , V_516 , & V_510 ) ;
if ( ! V_286 )
return - V_348 ;
V_28 -> V_72 = V_286 ;
return 0 ;
}
static void T_12 F_242 ( struct V_28 * V_28 )
{
F_243 ( V_28 -> V_72 ) ;
V_28 -> V_72 = NULL ;
}
void T_13 F_244 ( void )
{
if ( F_245 ( & V_517 ) )
F_21 ( L_17 ) ;
F_246 ( & V_518 ) ;
F_20 ( V_12 , V_519 , F_189 ,
F_124 , F_192 ) ;
F_20 ( V_12 , V_520 , F_167 , NULL , NULL ) ;
F_20 ( V_12 , V_303 , F_181 , NULL , NULL ) ;
F_20 ( V_12 , V_521 , F_172 , NULL , NULL ) ;
F_20 ( V_12 , V_522 , NULL , F_194 , NULL ) ;
F_20 ( V_12 , V_523 , NULL , F_194 , NULL ) ;
F_20 ( V_524 , V_432 , F_210 , NULL , NULL ) ;
F_20 ( V_524 , V_434 , F_214 , NULL , NULL ) ;
F_20 ( V_524 , V_525 , NULL , F_220 , NULL ) ;
F_20 ( V_524 , V_519 , NULL , F_224 , NULL ) ;
F_20 ( V_524 , V_521 , F_232 , NULL , NULL ) ;
F_20 ( V_524 , V_520 , F_231 , NULL , NULL ) ;
}
