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
} else if ( V_82 == V_91 - 1 ) {
T_5 V_92 = V_80 [ V_82 ] & V_93 ;
F_74 ( V_93 & V_94 ) ;
if ( F_75 ( V_51 , V_82 + 1 , V_92 ) )
goto V_90;
} else {
if ( F_75 ( V_51 , V_82 + 1 , V_80 [ V_82 ] ) )
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
int F_76 ( struct V_50 * V_51 , struct V_95 * V_96 , T_5 V_97 ,
long V_98 , T_5 error )
{
struct V_99 V_100 = {
. V_101 = F_77 ( V_102 - V_96 -> V_103 ) ,
. V_104 = V_96 -> V_105 ,
. V_106 = F_78 ( & ( V_96 -> V_107 ) ) ,
. V_108 = error ,
. V_109 = V_97 ,
} ;
if ( V_98 ) {
unsigned long clock ;
clock = F_79 ( abs ( V_98 ) ) ;
clock = F_80 (unsigned long, clock, INT_MAX) ;
V_100 . V_110 = ( V_98 > 0 ) ? clock : - clock ;
}
return F_81 ( V_51 , V_111 , sizeof( V_100 ) , & V_100 ) ;
}
static void F_82 ( struct V_29 * V_30 , unsigned char V_112 )
{
unsigned char V_113 = V_30 -> V_113 ;
switch ( V_112 ) {
case V_114 :
if ( ( V_113 == V_115 ||
V_113 == V_116 ) &&
! F_83 ( V_30 ) )
V_113 = V_114 ;
break;
case V_115 :
if ( V_113 == V_114 ||
V_113 == V_116 )
V_113 = V_115 ;
break;
}
if ( V_30 -> V_113 != V_113 ) {
F_84 ( & V_117 ) ;
V_30 -> V_113 = V_113 ;
F_85 ( & V_117 ) ;
F_86 ( V_30 ) ;
}
}
static unsigned int F_87 ( const struct V_29 * V_30 )
{
return ( V_30 -> V_78 & ~ ( V_118 | V_119 ) ) |
( V_30 -> V_120 & ( V_118 | V_119 ) ) ;
}
static unsigned int F_88 ( const struct V_29 * V_30 ,
const struct V_121 * V_122 )
{
unsigned int V_78 = V_122 -> V_123 ;
if ( V_122 -> V_124 )
V_78 = ( V_78 & V_122 -> V_124 ) |
( F_87 ( V_30 ) & ~ V_122 -> V_124 ) ;
return V_78 ;
}
static void F_89 ( struct V_125 * V_126 ,
const struct V_127 * V_128 )
{
V_126 -> V_129 = V_128 -> V_129 ;
V_126 -> V_130 = V_128 -> V_130 ;
V_126 -> V_131 = V_128 -> V_131 ;
V_126 -> V_132 = V_128 -> V_132 ;
V_126 -> V_133 = V_128 -> V_133 ;
V_126 -> V_134 = V_128 -> V_134 ;
V_126 -> V_135 = V_128 -> V_135 ;
V_126 -> V_136 = V_128 -> V_136 ;
V_126 -> V_137 = V_128 -> V_137 ;
V_126 -> V_138 = V_128 -> V_138 ;
V_126 -> V_139 = V_128 -> V_139 ;
V_126 -> V_140 = V_128 -> V_140 ;
V_126 -> V_141 = V_128 -> V_141 ;
V_126 -> V_142 = V_128 -> V_142 ;
V_126 -> V_143 = V_128 -> V_143 ;
V_126 -> V_144 = V_128 -> V_144 ;
V_126 -> V_145 = V_128 -> V_145 ;
V_126 -> V_146 = V_128 -> V_146 ;
V_126 -> V_147 = V_128 -> V_147 ;
V_126 -> V_148 = V_128 -> V_148 ;
V_126 -> V_149 = V_128 -> V_149 ;
V_126 -> V_150 = V_128 -> V_150 ;
V_126 -> V_151 = V_128 -> V_151 ;
}
static void F_90 ( void * V_152 , const struct V_127 * V_128 )
{
memcpy ( V_152 , V_128 , sizeof( * V_128 ) ) ;
}
static inline int F_91 ( const struct V_29 * V_30 ,
T_5 V_153 )
{
if ( V_30 -> V_30 . V_154 && F_92 ( V_30 -> V_30 . V_154 ) &&
( V_153 & V_155 ) ) {
int V_156 = F_93 ( V_30 -> V_30 . V_154 ) ;
T_4 V_43 = F_45 ( sizeof( struct V_42 ) ) ;
V_43 += F_45 ( V_156 * sizeof( struct V_42 ) ) ;
V_43 += V_156 *
( F_45 ( sizeof( struct V_157 ) ) +
F_45 ( sizeof( struct V_158 ) ) +
F_45 ( sizeof( struct V_159 ) ) +
F_45 ( sizeof( struct V_160 ) ) +
F_45 ( sizeof( struct V_161 ) ) +
F_45 ( sizeof( struct V_162 ) ) +
F_45 ( sizeof( V_163 ) ) +
F_45 ( sizeof( V_163 ) ) +
F_45 ( sizeof( V_163 ) ) +
F_45 ( sizeof( V_163 ) ) +
F_45 ( sizeof( V_163 ) ) +
F_45 ( sizeof( V_163 ) ) ) ;
return V_43 ;
} else
return 0 ;
}
static T_4 F_94 ( const struct V_29 * V_30 ,
T_5 V_153 )
{
T_4 V_164 = F_45 ( 4 )
+ F_45 ( V_165 )
+ F_45 ( sizeof( struct V_166 ) )
+ F_45 ( V_167 )
+ F_45 ( V_167 )
+ F_45 ( 1 )
+ F_45 ( 2 ) ;
T_4 V_168 = F_45 ( sizeof( struct V_42 ) ) ;
T_4 V_169 = F_45 ( sizeof( struct V_42 ) )
+ V_164 ;
T_4 V_170 = F_45 ( sizeof( struct V_42 ) )
+ V_164 ;
if ( ! V_30 -> V_171 -> V_172 || ! V_30 -> V_30 . V_154 ||
! ( V_153 & V_155 ) )
return 0 ;
if ( F_93 ( V_30 -> V_30 . V_154 ) )
return V_170 + V_168 +
V_169 * F_93 ( V_30 -> V_30 . V_154 ) ;
else
return V_170 ;
}
static T_7 T_4 F_95 ( const struct V_29 * V_30 ,
T_5 V_153 )
{
return F_96 ( sizeof( struct V_121 ) )
+ F_45 ( V_173 )
+ F_45 ( V_174 )
+ F_45 ( V_173 )
+ F_45 ( sizeof( struct V_175 ) )
+ F_45 ( sizeof( struct V_125 ) )
+ F_45 ( sizeof( struct V_127 ) )
+ F_45 ( V_176 )
+ F_45 ( V_176 )
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
+ F_45 ( V_153
& V_155 ? 4 : 0 )
+ F_91 ( V_30 , V_153 )
+ F_94 ( V_30 , V_153 )
+ F_46 ( V_30 )
+ F_51 ( V_30 )
+ F_45 ( V_177 )
+ F_45 ( V_177 )
+ F_45 ( 1 ) ;
}
static int F_97 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_178 ;
struct V_42 * V_179 ;
int V_180 ;
int V_27 ;
V_178 = F_55 ( V_51 , V_181 ) ;
if ( ! V_178 )
return - V_54 ;
for ( V_180 = 0 ; V_180 < F_93 ( V_30 -> V_30 . V_154 ) ; V_180 ++ ) {
V_179 = F_55 ( V_51 , V_182 ) ;
if ( ! V_179 )
goto V_90;
if ( F_75 ( V_51 , V_183 , V_180 ) )
goto V_90;
V_27 = V_30 -> V_171 -> V_172 ( V_30 , V_180 , V_51 ) ;
if ( V_27 == - V_54 )
goto V_90;
if ( V_27 ) {
F_57 ( V_51 , V_179 ) ;
continue;
}
F_56 ( V_51 , V_179 ) ;
}
F_56 ( V_51 , V_178 ) ;
return 0 ;
V_90:
F_57 ( V_51 , V_178 ) ;
return - V_54 ;
}
static int F_98 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_184 ;
int V_27 ;
V_184 = F_55 ( V_51 , V_185 ) ;
if ( ! V_184 )
return - V_54 ;
V_27 = V_30 -> V_171 -> V_172 ( V_30 , V_186 , V_51 ) ;
if ( V_27 ) {
F_57 ( V_51 , V_184 ) ;
return ( V_27 == - V_54 ) ? V_27 : 0 ;
}
F_56 ( V_51 , V_184 ) ;
return 0 ;
}
static int F_99 ( struct V_50 * V_51 , struct V_29 * V_30 ,
T_5 V_153 )
{
int V_27 ;
if ( ! V_30 -> V_171 -> V_172 || ! V_30 -> V_30 . V_154 ||
! ( V_153 & V_155 ) )
return 0 ;
V_27 = F_98 ( V_51 , V_30 ) ;
if ( V_27 )
return V_27 ;
if ( F_93 ( V_30 -> V_30 . V_154 ) ) {
V_27 = F_97 ( V_51 , V_30 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_100 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
int V_27 ;
struct V_187 V_188 ;
V_27 = F_101 ( V_30 , & V_188 ) ;
if ( V_27 ) {
if ( V_27 == - V_189 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_51 , V_190 , V_188 . V_191 , V_188 . V_97 ) )
return - V_54 ;
return 0 ;
}
static int F_102 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
char V_89 [ V_173 ] ;
int V_27 ;
V_27 = F_103 ( V_30 , V_89 , sizeof( V_89 ) ) ;
if ( V_27 ) {
if ( V_27 == - V_189 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_51 , V_192 , strlen ( V_89 ) , V_89 ) )
return - V_54 ;
return 0 ;
}
static int F_104 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
int V_27 ;
struct V_193 V_194 = {
. V_97 = V_195 ,
. V_78 = V_196 ,
} ;
V_27 = F_105 ( V_30 , & V_194 ) ;
if ( V_27 ) {
if ( V_27 == - V_189 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_51 , V_197 , V_194 . V_198 . V_188 . V_191 ,
V_194 . V_198 . V_188 . V_97 ) )
return - V_54 ;
return 0 ;
}
static int F_106 ( struct V_50 * V_51 , struct V_29 * V_30 ,
int type , T_5 V_68 , T_5 V_199 , T_5 V_200 ,
unsigned int V_78 , T_5 V_153 )
{
struct V_121 * V_122 ;
struct V_76 * V_77 ;
struct V_127 V_201 ;
const struct V_127 * V_202 ;
struct V_42 * V_194 , * V_203 ;
struct V_46 * V_48 ;
struct V_29 * V_204 = F_44 ( V_30 ) ;
F_107 () ;
V_77 = F_108 ( V_51 , V_68 , V_199 , type , sizeof( * V_122 ) , V_78 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_122 = F_109 ( V_77 ) ;
V_122 -> V_205 = V_206 ;
V_122 -> V_207 = 0 ;
V_122 -> V_208 = V_30 -> type ;
V_122 -> V_209 = V_30 -> V_210 ;
V_122 -> V_123 = F_110 ( V_30 ) ;
V_122 -> V_124 = V_200 ;
if ( F_54 ( V_51 , V_211 , V_30 -> V_89 ) ||
F_75 ( V_51 , V_212 , V_30 -> V_213 ) ||
F_111 ( V_51 , V_214 ,
F_112 ( V_30 ) ? V_30 -> V_113 : V_215 ) ||
F_111 ( V_51 , V_216 , V_30 -> V_217 ) ||
F_75 ( V_51 , V_218 , V_30 -> V_219 ) ||
F_75 ( V_51 , V_220 , V_30 -> V_69 ) ||
F_75 ( V_51 , V_221 , V_30 -> V_222 ) ||
F_75 ( V_51 , V_223 , V_30 -> V_224 ) ||
#ifdef F_113
F_75 ( V_51 , V_225 , V_30 -> V_226 ) ||
#endif
( V_30 -> V_210 != F_114 ( V_30 ) &&
F_75 ( V_51 , V_227 , F_114 ( V_30 ) ) ) ||
( V_204 &&
F_75 ( V_51 , V_228 , V_204 -> V_210 ) ) ||
F_111 ( V_51 , V_229 , F_115 ( V_30 ) ) ||
( V_30 -> V_230 &&
F_54 ( V_51 , V_231 , V_30 -> V_230 -> V_20 -> V_97 ) ) ||
( V_30 -> V_232 &&
F_54 ( V_51 , V_233 , V_30 -> V_232 ) ) ||
F_75 ( V_51 , V_234 ,
F_78 ( & V_30 -> V_235 ) ) ||
F_111 ( V_51 , V_236 , V_30 -> V_237 ) )
goto V_90;
if ( 1 ) {
struct V_175 V_238 = {
. V_239 = V_30 -> V_239 ,
. V_240 = V_30 -> V_240 ,
. V_241 = V_30 -> V_241 ,
. V_242 = V_30 -> V_242 ,
. V_243 = V_30 -> V_243 ,
. V_244 = V_30 -> V_245 ,
} ;
if ( F_81 ( V_51 , V_246 , sizeof( V_238 ) , & V_238 ) )
goto V_90;
}
if ( V_30 -> V_247 ) {
if ( F_81 ( V_51 , V_248 , V_30 -> V_247 , V_30 -> V_249 ) ||
F_81 ( V_51 , V_250 , V_30 -> V_247 , V_30 -> V_251 ) )
goto V_90;
}
if ( F_100 ( V_51 , V_30 ) )
goto V_90;
if ( F_102 ( V_51 , V_30 ) )
goto V_90;
if ( F_104 ( V_51 , V_30 ) )
goto V_90;
V_194 = F_116 ( V_51 , V_252 ,
sizeof( struct V_125 ) ) ;
if ( V_194 == NULL )
goto V_90;
V_202 = F_117 ( V_30 , & V_201 ) ;
F_89 ( F_118 ( V_194 ) , V_202 ) ;
V_194 = F_116 ( V_51 , V_253 ,
sizeof( struct V_127 ) ) ;
if ( V_194 == NULL )
goto V_90;
F_90 ( F_118 ( V_194 ) , V_202 ) ;
if ( V_30 -> V_30 . V_154 && ( V_153 & V_155 ) &&
F_75 ( V_51 , V_254 , F_93 ( V_30 -> V_30 . V_154 ) ) )
goto V_90;
if ( V_30 -> V_171 -> V_255 && V_30 -> V_30 . V_154
&& ( V_153 & V_155 ) ) {
int V_82 ;
struct V_42 * V_256 , * V_180 , * V_257 ;
int V_156 = F_93 ( V_30 -> V_30 . V_154 ) ;
V_256 = F_55 ( V_51 , V_258 ) ;
if ( ! V_256 )
goto V_90;
for ( V_82 = 0 ; V_82 < V_156 ; V_82 ++ ) {
struct V_259 V_260 ;
struct V_157 V_261 ;
struct V_158 V_262 ;
struct V_160 V_263 ;
struct V_264 V_265 ;
struct V_159 V_266 ;
struct V_161 V_267 ;
struct V_162 V_268 ;
struct V_269 V_270 ;
V_260 . V_271 = - 1 ;
V_260 . V_272 = - 1 ;
memset ( V_260 . V_273 , 0 , sizeof( V_260 . V_273 ) ) ;
V_260 . V_274 = 0 ;
if ( V_30 -> V_171 -> V_255 ( V_30 , V_82 , & V_260 ) )
break;
V_261 . V_180 =
V_262 . V_180 =
V_263 . V_180 =
V_265 . V_180 =
V_266 . V_180 =
V_267 . V_180 =
V_268 . V_180 = V_260 . V_180 ;
memcpy ( V_261 . V_273 , V_260 . V_273 , sizeof( V_260 . V_273 ) ) ;
V_262 . V_275 = V_260 . V_275 ;
V_262 . V_276 = V_260 . V_276 ;
V_265 . V_277 = V_260 . V_278 ;
V_263 . V_279 = V_260 . V_279 ;
V_263 . V_278 = V_260 . V_278 ;
V_266 . V_280 = V_260 . V_271 ;
V_267 . V_281 = V_260 . V_274 ;
V_268 . V_280 = V_260 . V_272 ;
V_180 = F_55 ( V_51 , V_282 ) ;
if ( ! V_180 ) {
F_57 ( V_51 , V_256 ) ;
goto V_90;
}
if ( F_81 ( V_51 , V_283 , sizeof( V_261 ) , & V_261 ) ||
F_81 ( V_51 , V_284 , sizeof( V_262 ) , & V_262 ) ||
F_81 ( V_51 , V_285 , sizeof( V_263 ) ,
& V_263 ) ||
F_81 ( V_51 , V_286 , sizeof( V_265 ) ,
& V_265 ) ||
F_81 ( V_51 , V_287 , sizeof( V_266 ) ,
& V_266 ) ||
F_81 ( V_51 , V_288 , sizeof( V_267 ) ,
& V_267 ) ||
F_81 ( V_51 , V_289 ,
sizeof( V_268 ) ,
& V_268 ) )
goto V_90;
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
if ( V_30 -> V_171 -> V_290 )
V_30 -> V_171 -> V_290 ( V_30 , V_82 ,
& V_270 ) ;
V_257 = F_55 ( V_51 , V_291 ) ;
if ( ! V_257 ) {
F_57 ( V_51 , V_180 ) ;
F_57 ( V_51 , V_256 ) ;
goto V_90;
}
if ( F_119 ( V_51 , V_292 ,
V_270 . V_129 ) ||
F_119 ( V_51 , V_293 ,
V_270 . V_130 ) ||
F_119 ( V_51 , V_294 ,
V_270 . V_131 ) ||
F_119 ( V_51 , V_295 ,
V_270 . V_132 ) ||
F_119 ( V_51 , V_296 ,
V_270 . V_251 ) ||
F_119 ( V_51 , V_297 ,
V_270 . V_137 ) )
goto V_90;
F_56 ( V_51 , V_257 ) ;
F_56 ( V_51 , V_180 ) ;
}
F_56 ( V_51 , V_256 ) ;
}
if ( F_99 ( V_51 , V_30 , V_153 ) )
goto V_90;
if ( V_30 -> V_18 || F_52 ( V_30 ) ) {
if ( F_59 ( V_51 , V_30 ) < 0 )
goto V_90;
}
if ( V_30 -> V_18 &&
V_30 -> V_18 -> V_298 ) {
struct V_28 * V_299 = V_30 -> V_18 -> V_298 ( V_30 ) ;
if ( ! F_120 ( F_121 ( V_30 ) , V_299 ) ) {
int V_97 = F_122 ( F_121 ( V_30 ) , V_299 ) ;
if ( F_123 ( V_51 , V_300 , V_97 ) )
goto V_90;
}
}
if ( ! ( V_203 = F_55 ( V_51 , V_301 ) ) )
goto V_90;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_48 -> V_302 ) {
struct V_42 * V_303 ;
int V_27 ;
if ( ! ( V_303 = F_55 ( V_51 , V_48 -> V_47 ) ) )
goto V_90;
V_27 = V_48 -> V_302 ( V_51 , V_30 ) ;
if ( V_27 == - V_304 )
F_57 ( V_51 , V_303 ) ;
else if ( V_27 < 0 )
goto V_90;
F_56 ( V_51 , V_303 ) ;
}
}
F_56 ( V_51 , V_203 ) ;
F_124 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_125 ( V_51 , V_77 ) ;
return - V_54 ;
}
static int F_126 ( struct V_50 * V_51 , struct V_305 * V_306 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
int V_308 , V_309 ;
int V_310 = 0 , V_311 ;
struct V_29 * V_30 ;
struct V_312 * V_313 ;
struct V_42 * V_314 [ V_315 + 1 ] ;
T_5 V_153 = 0 ;
int V_27 ;
int V_316 ;
V_309 = V_306 -> args [ 0 ] ;
V_311 = V_306 -> args [ 1 ] ;
V_306 -> V_199 = V_28 -> V_317 ;
V_316 = F_128 ( V_306 -> V_77 ) < sizeof( struct V_121 ) ?
sizeof( struct V_318 ) : sizeof( struct V_121 ) ;
if ( F_129 ( V_306 -> V_77 , V_316 , V_314 , V_315 , V_319 ) >= 0 ) {
if ( V_314 [ V_320 ] )
V_153 = F_130 ( V_314 [ V_320 ] ) ;
}
for ( V_308 = V_309 ; V_308 < V_321 ; V_308 ++ , V_311 = 0 ) {
V_310 = 0 ;
V_313 = & V_28 -> V_322 [ V_308 ] ;
F_131 (dev, head, index_hlist) {
if ( V_310 < V_311 )
goto V_323;
V_27 = F_106 ( V_51 , V_30 , V_324 ,
F_61 ( V_306 -> V_51 ) . V_325 ,
V_306 -> V_77 -> V_326 , 0 ,
V_327 ,
V_153 ) ;
F_132 ( ( V_27 == - V_54 ) && ( V_51 -> V_328 == 0 ) ) ;
if ( V_27 < 0 )
goto V_66;
F_133 ( V_306 , F_134 ( V_51 ) ) ;
V_323:
V_310 ++ ;
}
}
V_66:
V_306 -> args [ 1 ] = V_310 ;
V_306 -> args [ 0 ] = V_308 ;
return V_51 -> V_328 ;
}
int F_135 ( struct V_42 * * V_314 , const struct V_42 * V_313 , int V_328 )
{
return F_136 ( V_314 , V_315 , V_313 , V_328 , V_319 ) ;
}
struct V_28 * F_137 ( struct V_28 * V_329 , struct V_42 * V_314 [] )
{
struct V_28 * V_28 ;
if ( V_314 [ V_330 ] )
V_28 = F_138 ( F_130 ( V_314 [ V_330 ] ) ) ;
else if ( V_314 [ V_331 ] )
V_28 = F_139 ( F_130 ( V_314 [ V_331 ] ) ) ;
else
V_28 = F_140 ( V_329 ) ;
return V_28 ;
}
static int F_141 ( struct V_29 * V_30 , struct V_42 * V_314 [] )
{
if ( V_30 ) {
if ( V_314 [ V_248 ] &&
F_142 ( V_314 [ V_248 ] ) < V_30 -> V_247 )
return - V_332 ;
if ( V_314 [ V_250 ] &&
F_142 ( V_314 [ V_250 ] ) < V_30 -> V_247 )
return - V_332 ;
}
if ( V_314 [ V_301 ] ) {
struct V_42 * V_303 ;
int V_333 , V_27 ;
F_143 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_144 ( V_303 ) ) ) )
return - V_334 ;
if ( ! V_48 -> V_335 )
return - V_189 ;
if ( V_48 -> V_336 ) {
V_27 = V_48 -> V_336 ( V_30 , V_303 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_145 ( struct V_29 * V_30 , struct V_42 * * V_314 )
{
const struct V_337 * V_20 = V_30 -> V_171 ;
int V_27 = - V_332 ;
if ( V_314 [ V_283 ] ) {
struct V_157 * V_338 = F_118 ( V_314 [ V_283 ] ) ;
V_27 = - V_189 ;
if ( V_20 -> V_339 )
V_27 = V_20 -> V_339 ( V_30 , V_338 -> V_180 ,
V_338 -> V_273 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_314 [ V_284 ] ) {
struct V_158 * V_340 = F_118 ( V_314 [ V_284 ] ) ;
V_27 = - V_189 ;
if ( V_20 -> V_341 )
V_27 = V_20 -> V_341 ( V_30 , V_340 -> V_180 , V_340 -> V_275 ,
V_340 -> V_276 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_314 [ V_286 ] ) {
struct V_264 * V_342 = F_118 ( V_314 [ V_286 ] ) ;
struct V_259 V_343 ;
V_27 = - V_189 ;
if ( V_20 -> V_255 )
V_27 = V_20 -> V_255 ( V_30 , V_342 -> V_180 , & V_343 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = - V_189 ;
if ( V_20 -> V_344 )
V_27 = V_20 -> V_344 ( V_30 , V_342 -> V_180 ,
V_343 . V_279 ,
V_342 -> V_277 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_314 [ V_285 ] ) {
struct V_160 * V_342 = F_118 ( V_314 [ V_285 ] ) ;
V_27 = - V_189 ;
if ( V_20 -> V_344 )
V_27 = V_20 -> V_344 ( V_30 , V_342 -> V_180 ,
V_342 -> V_279 ,
V_342 -> V_278 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_314 [ V_287 ] ) {
struct V_159 * V_345 = F_118 ( V_314 [ V_287 ] ) ;
V_27 = - V_189 ;
if ( V_20 -> V_346 )
V_27 = V_20 -> V_346 ( V_30 , V_345 -> V_180 ,
V_345 -> V_280 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_314 [ V_288 ] ) {
struct V_161 * V_347 = F_118 ( V_314 [ V_288 ] ) ;
V_27 = - V_189 ;
if ( V_20 -> V_348 )
V_27 = V_20 -> V_348 ( V_30 , V_347 -> V_180 ,
V_347 -> V_281 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_314 [ V_289 ] ) {
struct V_162 * V_349 ;
V_27 = - V_189 ;
V_349 = F_118 ( V_314 [ V_289 ] ) ;
if ( V_20 -> V_350 )
V_27 = V_20 -> V_350 ( V_30 , V_349 -> V_180 ,
V_349 -> V_280 ) ;
if ( V_27 < 0 )
return V_27 ;
}
return V_27 ;
}
static int F_146 ( struct V_29 * V_30 , int V_210 )
{
struct V_29 * V_204 = F_44 ( V_30 ) ;
const struct V_337 * V_20 ;
int V_27 ;
if ( V_204 ) {
if ( V_204 -> V_210 == V_210 )
return 0 ;
V_20 = V_204 -> V_171 ;
if ( V_20 -> V_351 ) {
V_27 = V_20 -> V_351 ( V_204 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_189 ;
}
}
if ( V_210 ) {
V_204 = F_147 ( F_121 ( V_30 ) , V_210 ) ;
if ( ! V_204 )
return - V_332 ;
V_20 = V_204 -> V_171 ;
if ( V_20 -> V_352 ) {
V_27 = V_20 -> V_352 ( V_204 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_189 ;
}
}
return 0 ;
}
static int F_148 ( const struct V_50 * V_51 ,
struct V_29 * V_30 , struct V_121 * V_122 ,
struct V_42 * * V_314 , char * V_353 , int V_354 )
{
const struct V_337 * V_20 = V_30 -> V_171 ;
int V_27 ;
if ( V_314 [ V_330 ] || V_314 [ V_331 ] ) {
struct V_28 * V_28 = F_137 ( F_121 ( V_30 ) , V_314 ) ;
if ( F_149 ( V_28 ) ) {
V_27 = F_150 ( V_28 ) ;
goto V_355;
}
if ( ! F_151 ( V_51 , V_28 -> V_356 , V_357 ) ) {
F_152 ( V_28 ) ;
V_27 = - V_358 ;
goto V_355;
}
V_27 = F_153 ( V_30 , V_28 , V_353 ) ;
F_152 ( V_28 ) ;
if ( V_27 )
goto V_355;
V_354 |= V_359 ;
}
if ( V_314 [ V_246 ] ) {
struct V_175 * V_360 ;
struct V_361 V_362 ;
if ( ! V_20 -> V_363 ) {
V_27 = - V_189 ;
goto V_355;
}
if ( ! F_154 ( V_30 ) ) {
V_27 = - V_364 ;
goto V_355;
}
V_360 = F_118 ( V_314 [ V_246 ] ) ;
V_362 . V_239 = ( unsigned long ) V_360 -> V_239 ;
V_362 . V_240 = ( unsigned long ) V_360 -> V_240 ;
V_362 . V_241 = ( unsigned short ) V_360 -> V_241 ;
V_362 . V_242 = ( unsigned char ) V_360 -> V_242 ;
V_362 . V_243 = ( unsigned char ) V_360 -> V_243 ;
V_362 . V_244 = ( unsigned char ) V_360 -> V_244 ;
V_27 = V_20 -> V_363 ( V_30 , & V_362 ) ;
if ( V_27 < 0 )
goto V_355;
V_354 |= V_365 ;
}
if ( V_314 [ V_248 ] ) {
struct V_366 * V_367 ;
int V_328 ;
V_328 = sizeof( V_368 ) + V_30 -> V_247 ;
V_367 = F_155 ( V_328 , V_15 ) ;
if ( ! V_367 ) {
V_27 = - V_369 ;
goto V_355;
}
V_367 -> V_370 = V_30 -> type ;
memcpy ( V_367 -> V_371 , F_118 ( V_314 [ V_248 ] ) ,
V_30 -> V_247 ) ;
V_27 = F_156 ( V_30 , V_367 ) ;
F_24 ( V_367 ) ;
if ( V_27 )
goto V_355;
V_354 |= V_359 ;
}
if ( V_314 [ V_218 ] ) {
V_27 = F_157 ( V_30 , F_130 ( V_314 [ V_218 ] ) ) ;
if ( V_27 < 0 )
goto V_355;
V_354 |= V_359 ;
}
if ( V_314 [ V_220 ] ) {
F_158 ( V_30 , F_130 ( V_314 [ V_220 ] ) ) ;
V_354 |= V_365 ;
}
if ( V_122 -> V_209 > 0 && V_353 [ 0 ] ) {
V_27 = F_159 ( V_30 , V_353 ) ;
if ( V_27 < 0 )
goto V_355;
V_354 |= V_359 ;
}
if ( V_314 [ V_233 ] ) {
V_27 = F_160 ( V_30 , F_118 ( V_314 [ V_233 ] ) ,
F_142 ( V_314 [ V_233 ] ) ) ;
if ( V_27 < 0 )
goto V_355;
V_354 |= V_365 ;
}
if ( V_314 [ V_250 ] ) {
F_161 ( V_30 -> V_251 , V_314 [ V_250 ] , V_30 -> V_247 ) ;
F_162 ( V_372 , V_30 ) ;
}
if ( V_122 -> V_123 || V_122 -> V_124 ) {
V_27 = F_163 ( V_30 , F_88 ( V_30 , V_122 ) ) ;
if ( V_27 < 0 )
goto V_355;
}
if ( V_314 [ V_228 ] ) {
V_27 = F_146 ( V_30 , F_130 ( V_314 [ V_228 ] ) ) ;
if ( V_27 )
goto V_355;
V_354 |= V_359 ;
}
if ( V_314 [ V_229 ] ) {
V_27 = F_164 ( V_30 , F_165 ( V_314 [ V_229 ] ) ) ;
if ( V_27 )
goto V_355;
V_354 |= V_359 ;
}
if ( V_314 [ V_212 ] ) {
unsigned long V_373 = F_130 ( V_314 [ V_212 ] ) ;
if ( V_30 -> V_213 ^ V_373 )
V_354 |= V_365 ;
V_30 -> V_213 = V_373 ;
}
if ( V_314 [ V_214 ] )
F_82 ( V_30 , F_165 ( V_314 [ V_214 ] ) ) ;
if ( V_314 [ V_216 ] ) {
unsigned char V_373 = F_165 ( V_314 [ V_216 ] ) ;
F_84 ( & V_117 ) ;
if ( V_30 -> V_217 ^ V_373 )
V_354 |= V_365 ;
V_30 -> V_217 = V_373 ;
F_85 ( & V_117 ) ;
}
if ( V_314 [ V_258 ] ) {
struct V_42 * V_256 [ V_374 + 1 ] ;
struct V_42 * V_194 ;
int V_333 ;
F_143 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_144 ( V_194 ) != V_282 ||
F_142 ( V_194 ) < V_375 ) {
V_27 = - V_332 ;
goto V_355;
}
V_27 = F_166 ( V_256 , V_374 , V_194 ,
V_376 ) ;
if ( V_27 < 0 )
goto V_355;
V_27 = F_145 ( V_30 , V_256 ) ;
if ( V_27 < 0 )
goto V_355;
V_354 |= V_365 ;
}
}
V_27 = 0 ;
if ( V_314 [ V_181 ] ) {
struct V_42 * V_244 [ V_377 + 1 ] ;
struct V_42 * V_194 ;
int V_180 ;
int V_333 ;
V_27 = - V_189 ;
if ( ! V_20 -> V_378 )
goto V_355;
F_143 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_144 ( V_194 ) != V_182 ||
F_142 ( V_194 ) < V_375 ) {
V_27 = - V_332 ;
goto V_355;
}
V_27 = F_166 ( V_244 , V_377 , V_194 ,
V_379 ) ;
if ( V_27 < 0 )
goto V_355;
if ( ! V_244 [ V_183 ] ) {
V_27 = - V_189 ;
goto V_355;
}
V_180 = F_130 ( V_244 [ V_183 ] ) ;
V_27 = V_20 -> V_378 ( V_30 , V_180 , V_244 ) ;
if ( V_27 < 0 )
goto V_355;
V_354 |= V_365 ;
}
}
V_27 = 0 ;
if ( V_314 [ V_185 ] ) {
struct V_42 * V_244 [ V_377 + 1 ] ;
V_27 = F_166 ( V_244 , V_377 ,
V_314 [ V_185 ] , V_379 ) ;
if ( V_27 < 0 )
goto V_355;
V_27 = - V_189 ;
if ( V_20 -> V_378 )
V_27 = V_20 -> V_378 ( V_30 , V_186 , V_244 ) ;
if ( V_27 < 0 )
goto V_355;
V_354 |= V_365 ;
}
if ( V_314 [ V_301 ] ) {
struct V_42 * V_303 ;
int V_333 ;
F_143 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_144 ( V_303 ) ) ) )
F_167 () ;
V_27 = V_48 -> V_335 ( V_30 , V_303 ) ;
if ( V_27 < 0 )
goto V_355;
V_354 |= V_365 ;
}
}
V_27 = 0 ;
if ( V_314 [ V_236 ] ) {
V_27 = F_168 ( V_30 ,
F_165 ( V_314 [ V_236 ] ) ) ;
if ( V_27 )
goto V_355;
V_354 |= V_365 ;
}
V_355:
if ( V_354 & V_359 ) {
if ( V_354 & V_365 )
F_86 ( V_30 ) ;
if ( V_27 < 0 )
F_169 ( L_3 ,
V_30 -> V_89 ) ;
}
return V_27 ;
}
static int F_170 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
struct V_121 * V_122 ;
struct V_29 * V_30 ;
int V_27 ;
struct V_42 * V_314 [ V_315 + 1 ] ;
char V_353 [ V_173 ] ;
V_27 = F_129 ( V_77 , sizeof( * V_122 ) , V_314 , V_315 , V_319 ) ;
if ( V_27 < 0 )
goto V_355;
if ( V_314 [ V_211 ] )
F_171 ( V_353 , V_314 [ V_211 ] , V_173 ) ;
else
V_353 [ 0 ] = '\0' ;
V_27 = - V_332 ;
V_122 = F_109 ( V_77 ) ;
if ( V_122 -> V_209 > 0 )
V_30 = F_147 ( V_28 , V_122 -> V_209 ) ;
else if ( V_314 [ V_211 ] )
V_30 = F_172 ( V_28 , V_353 ) ;
else
goto V_355;
if ( V_30 == NULL ) {
V_27 = - V_364 ;
goto V_355;
}
V_27 = F_141 ( V_30 , V_314 ) ;
if ( V_27 < 0 )
goto V_355;
V_27 = F_148 ( V_51 , V_30 , V_122 , V_314 , V_353 , 0 ) ;
V_355:
return V_27 ;
}
static int F_173 ( const struct V_28 * V_28 , int V_69 )
{
struct V_29 * V_30 , * V_380 ;
F_31 ( V_31 ) ;
bool V_381 = false ;
if ( ! V_69 )
return - V_358 ;
F_32 (net, dev) {
if ( V_30 -> V_69 == V_69 ) {
const struct V_18 * V_20 ;
V_381 = true ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_189 ;
}
}
if ( ! V_381 )
return - V_364 ;
F_174 (net, dev, aux) {
if ( V_30 -> V_69 == V_69 ) {
const struct V_18 * V_20 ;
V_20 = V_30 -> V_18 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
}
}
F_33 ( & V_31 ) ;
return 0 ;
}
int F_175 ( struct V_29 * V_30 )
{
const struct V_18 * V_20 ;
F_31 ( V_31 ) ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_189 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
return 0 ;
}
static int F_176 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
struct V_29 * V_30 ;
struct V_121 * V_122 ;
char V_353 [ V_173 ] ;
struct V_42 * V_314 [ V_315 + 1 ] ;
int V_27 ;
V_27 = F_129 ( V_77 , sizeof( * V_122 ) , V_314 , V_315 , V_319 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_314 [ V_211 ] )
F_171 ( V_353 , V_314 [ V_211 ] , V_173 ) ;
V_122 = F_109 ( V_77 ) ;
if ( V_122 -> V_209 > 0 )
V_30 = F_147 ( V_28 , V_122 -> V_209 ) ;
else if ( V_314 [ V_211 ] )
V_30 = F_172 ( V_28 , V_353 ) ;
else if ( V_314 [ V_220 ] )
return F_173 ( V_28 , F_130 ( V_314 [ V_220 ] ) ) ;
else
return - V_332 ;
if ( ! V_30 )
return - V_364 ;
return F_175 ( V_30 ) ;
}
int F_177 ( struct V_29 * V_30 , const struct V_121 * V_122 )
{
unsigned int V_382 ;
int V_27 ;
V_382 = V_30 -> V_78 ;
if ( V_122 && ( V_122 -> V_123 || V_122 -> V_124 ) ) {
V_27 = F_178 ( V_30 , F_88 ( V_30 , V_122 ) ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_30 -> V_383 = V_384 ;
F_179 ( V_30 , V_382 , ~ 0U ) ;
return 0 ;
}
struct V_29 * F_180 ( struct V_28 * V_28 ,
const char * V_353 , unsigned char V_385 ,
const struct V_18 * V_20 , struct V_42 * V_314 [] )
{
int V_27 ;
struct V_29 * V_30 ;
unsigned int V_224 = 1 ;
unsigned int V_226 = 1 ;
if ( V_314 [ V_223 ] )
V_224 = F_130 ( V_314 [ V_223 ] ) ;
else if ( V_20 -> V_386 )
V_224 = V_20 -> V_386 () ;
if ( V_314 [ V_225 ] )
V_226 = F_130 ( V_314 [ V_225 ] ) ;
else if ( V_20 -> V_387 )
V_226 = V_20 -> V_387 () ;
V_27 = - V_369 ;
V_30 = F_181 ( V_20 -> V_388 , V_353 , V_385 ,
V_20 -> V_22 , V_224 , V_226 ) ;
if ( ! V_30 )
goto V_27;
F_182 ( V_30 , V_28 ) ;
V_30 -> V_18 = V_20 ;
V_30 -> V_383 = V_389 ;
if ( V_314 [ V_218 ] )
V_30 -> V_219 = F_130 ( V_314 [ V_218 ] ) ;
if ( V_314 [ V_248 ] ) {
memcpy ( V_30 -> V_249 , F_118 ( V_314 [ V_248 ] ) ,
F_142 ( V_314 [ V_248 ] ) ) ;
V_30 -> V_390 = V_391 ;
}
if ( V_314 [ V_250 ] )
memcpy ( V_30 -> V_251 , F_118 ( V_314 [ V_250 ] ) ,
F_142 ( V_314 [ V_250 ] ) ) ;
if ( V_314 [ V_212 ] )
V_30 -> V_213 = F_130 ( V_314 [ V_212 ] ) ;
if ( V_314 [ V_214 ] )
F_82 ( V_30 , F_165 ( V_314 [ V_214 ] ) ) ;
if ( V_314 [ V_216 ] )
V_30 -> V_217 = F_165 ( V_314 [ V_216 ] ) ;
if ( V_314 [ V_220 ] )
F_158 ( V_30 , F_130 ( V_314 [ V_220 ] ) ) ;
return V_30 ;
V_27:
return F_183 ( V_27 ) ;
}
static int F_184 ( const struct V_50 * V_51 ,
struct V_28 * V_28 , int V_69 ,
struct V_121 * V_122 ,
struct V_42 * * V_314 )
{
struct V_29 * V_30 , * V_380 ;
int V_27 ;
F_174 (net, dev, aux) {
if ( V_30 -> V_69 == V_69 ) {
V_27 = F_148 ( V_51 , V_30 , V_122 , V_314 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_185 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_392 = NULL ;
struct V_29 * V_30 ;
struct V_29 * V_40 = NULL ;
struct V_121 * V_122 ;
char V_19 [ V_393 ] ;
char V_353 [ V_173 ] ;
struct V_42 * V_314 [ V_315 + 1 ] ;
struct V_42 * V_64 [ V_394 + 1 ] ;
unsigned char V_385 = V_395 ;
int V_27 ;
#ifdef F_186
V_396:
#endif
V_27 = F_129 ( V_77 , sizeof( * V_122 ) , V_314 , V_315 , V_319 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_314 [ V_211 ] )
F_171 ( V_353 , V_314 [ V_211 ] , V_173 ) ;
else
V_353 [ 0 ] = '\0' ;
V_122 = F_109 ( V_77 ) ;
if ( V_122 -> V_209 > 0 )
V_30 = F_147 ( V_28 , V_122 -> V_209 ) ;
else {
if ( V_353 [ 0 ] )
V_30 = F_172 ( V_28 , V_353 ) ;
else
V_30 = NULL ;
}
if ( V_30 ) {
V_40 = F_44 ( V_30 ) ;
if ( V_40 )
V_392 = V_40 -> V_18 ;
}
V_27 = F_141 ( V_30 , V_314 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_314 [ V_65 ] ) {
V_27 = F_166 ( V_64 , V_394 ,
V_314 [ V_65 ] , V_397 ) ;
if ( V_27 < 0 )
return V_27 ;
} else
memset ( V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_64 [ V_59 ] ) {
F_171 ( V_19 , V_64 [ V_59 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_42 * V_194 [ V_20 ? V_20 -> V_398 + 1 : 1 ] ;
struct V_42 * V_399 [ V_392 ? V_392 -> V_400 + 1 : 1 ] ;
struct V_42 * * V_58 = NULL ;
struct V_42 * * V_52 = NULL ;
struct V_28 * V_401 , * V_299 = NULL ;
if ( V_20 ) {
if ( V_20 -> V_398 && V_64 [ V_62 ] ) {
V_27 = F_166 ( V_194 , V_20 -> V_398 ,
V_64 [ V_62 ] ,
V_20 -> V_402 ) ;
if ( V_27 < 0 )
return V_27 ;
V_58 = V_194 ;
}
if ( V_20 -> V_403 ) {
V_27 = V_20 -> V_403 ( V_314 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_392 ) {
if ( V_392 -> V_400 &&
V_64 [ V_56 ] ) {
V_27 = F_166 ( V_399 ,
V_392 -> V_400 ,
V_64 [ V_56 ] ,
V_392 -> V_404 ) ;
if ( V_27 < 0 )
return V_27 ;
V_52 = V_399 ;
}
if ( V_392 -> V_405 ) {
V_27 = V_392 -> V_405 ( V_314 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_30 ) {
int V_354 = 0 ;
if ( V_77 -> V_406 & V_407 )
return - V_21 ;
if ( V_77 -> V_406 & V_408 )
return - V_189 ;
if ( V_64 [ V_62 ] ) {
if ( ! V_20 || V_20 != V_30 -> V_18 ||
! V_20 -> V_409 )
return - V_189 ;
V_27 = V_20 -> V_409 ( V_30 , V_314 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
V_354 |= V_365 ;
}
if ( V_64 [ V_56 ] ) {
if ( ! V_392 || ! V_392 -> V_410 )
return - V_189 ;
V_27 = V_392 -> V_410 ( V_40 , V_30 ,
V_314 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
V_354 |= V_365 ;
}
return F_148 ( V_51 , V_30 , V_122 , V_314 , V_353 , V_354 ) ;
}
if ( ! ( V_77 -> V_406 & V_411 ) ) {
if ( V_122 -> V_209 == 0 && V_314 [ V_220 ] )
return F_184 ( V_51 , V_28 ,
F_130 ( V_314 [ V_220 ] ) ,
V_122 , V_314 ) ;
return - V_364 ;
}
if ( V_314 [ V_246 ] || V_314 [ V_228 ] || V_314 [ V_412 ] )
return - V_189 ;
if ( ! V_20 ) {
#ifdef F_186
if ( V_19 [ 0 ] ) {
F_3 () ;
F_187 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_396;
}
#endif
return - V_189 ;
}
if ( ! V_20 -> V_22 )
return - V_189 ;
if ( ! V_353 [ 0 ] ) {
snprintf ( V_353 , V_173 , L_5 , V_20 -> V_19 ) ;
V_385 = V_413 ;
}
V_401 = F_137 ( V_28 , V_314 ) ;
if ( F_149 ( V_401 ) )
return F_150 ( V_401 ) ;
V_27 = - V_358 ;
if ( ! F_151 ( V_51 , V_401 -> V_356 , V_357 ) )
goto V_66;
if ( V_314 [ V_300 ] ) {
int V_97 = F_188 ( V_314 [ V_300 ] ) ;
V_299 = F_189 ( V_401 , V_97 ) ;
if ( ! V_299 ) {
V_27 = - V_332 ;
goto V_66;
}
V_27 = - V_358 ;
if ( ! F_151 ( V_51 , V_299 -> V_356 , V_357 ) )
goto V_66;
}
V_30 = F_180 ( V_299 ? : V_401 , V_353 ,
V_385 , V_20 , V_314 ) ;
if ( F_149 ( V_30 ) ) {
V_27 = F_150 ( V_30 ) ;
goto V_66;
}
V_30 -> V_210 = V_122 -> V_209 ;
if ( V_20 -> V_414 ) {
V_27 = V_20 -> V_414 ( V_299 ? : V_28 , V_30 , V_314 , V_58 ) ;
if ( V_27 < 0 ) {
if ( V_30 -> V_415 == V_416 )
F_190 ( V_30 ) ;
goto V_66;
}
} else {
V_27 = F_191 ( V_30 ) ;
if ( V_27 < 0 ) {
F_190 ( V_30 ) ;
goto V_66;
}
}
V_27 = F_177 ( V_30 , V_122 ) ;
if ( V_27 < 0 )
goto V_417;
if ( V_299 ) {
V_27 = F_153 ( V_30 , V_401 , V_353 ) ;
if ( V_27 < 0 )
goto V_417;
}
V_66:
if ( V_299 )
F_152 ( V_299 ) ;
F_152 ( V_401 ) ;
return V_27 ;
V_417:
if ( V_20 -> V_414 ) {
F_31 ( V_31 ) ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
} else {
F_192 ( V_30 ) ;
}
goto V_66;
}
}
static int F_193 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
struct V_121 * V_122 ;
char V_353 [ V_173 ] ;
struct V_42 * V_314 [ V_315 + 1 ] ;
struct V_29 * V_30 = NULL ;
struct V_50 * V_418 ;
int V_27 ;
T_5 V_153 = 0 ;
V_27 = F_129 ( V_77 , sizeof( * V_122 ) , V_314 , V_315 , V_319 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_314 [ V_211 ] )
F_171 ( V_353 , V_314 [ V_211 ] , V_173 ) ;
if ( V_314 [ V_320 ] )
V_153 = F_130 ( V_314 [ V_320 ] ) ;
V_122 = F_109 ( V_77 ) ;
if ( V_122 -> V_209 > 0 )
V_30 = F_147 ( V_28 , V_122 -> V_209 ) ;
else if ( V_314 [ V_211 ] )
V_30 = F_172 ( V_28 , V_353 ) ;
else
return - V_332 ;
if ( V_30 == NULL )
return - V_364 ;
V_418 = F_194 ( F_95 ( V_30 , V_153 ) , V_15 ) ;
if ( V_418 == NULL )
return - V_16 ;
V_27 = F_106 ( V_418 , V_30 , V_324 , F_61 ( V_51 ) . V_325 ,
V_77 -> V_326 , 0 , 0 , V_153 ) ;
if ( V_27 < 0 ) {
F_132 ( V_27 == - V_54 ) ;
F_195 ( V_418 ) ;
} else
V_27 = F_65 ( V_418 , V_28 , F_61 ( V_51 ) . V_325 ) ;
return V_27 ;
}
static T_8 F_196 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
struct V_29 * V_30 ;
struct V_42 * V_314 [ V_315 + 1 ] ;
T_5 V_153 = 0 ;
T_8 V_419 = 0 ;
int V_316 ;
V_316 = F_128 ( V_77 ) < sizeof( struct V_121 ) ?
sizeof( struct V_318 ) : sizeof( struct V_121 ) ;
if ( F_129 ( V_77 , V_316 , V_314 , V_315 , V_319 ) >= 0 ) {
if ( V_314 [ V_320 ] )
V_153 = F_130 ( V_314 [ V_320 ] ) ;
}
if ( ! V_153 )
return V_420 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_419 = F_197 ( T_8 , V_419 ,
F_95 ( V_30 ,
V_153 ) ) ;
}
return V_419 ;
}
static int F_198 ( struct V_50 * V_51 , struct V_305 * V_306 )
{
int V_310 ;
int V_311 = V_306 -> V_47 ;
if ( V_311 == 0 )
V_311 = 1 ;
for ( V_310 = 1 ; V_310 <= V_9 ; V_310 ++ ) {
int type = V_306 -> V_77 -> V_421 - V_4 ;
if ( V_310 < V_311 || V_310 == V_422 )
continue;
if ( V_10 [ V_310 ] == NULL ||
V_10 [ V_310 ] [ type ] . V_13 == NULL )
continue;
if ( V_310 > V_311 ) {
memset ( & V_306 -> args [ 0 ] , 0 , sizeof( V_306 -> args ) ) ;
V_306 -> V_423 = 0 ;
V_306 -> V_199 = 0 ;
}
if ( V_10 [ V_310 ] [ type ] . V_13 ( V_51 , V_306 ) )
break;
}
V_306 -> V_47 = V_310 ;
return V_51 -> V_328 ;
}
struct V_50 * F_199 ( int type , struct V_29 * V_30 ,
unsigned int V_200 , T_6 V_78 )
{
struct V_28 * V_28 = F_121 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
T_4 V_424 ;
V_51 = F_194 ( ( V_424 = F_95 ( V_30 , 0 ) ) , V_78 ) ;
if ( V_51 == NULL )
goto V_355;
V_27 = F_106 ( V_51 , V_30 , type , 0 , 0 , V_200 , 0 , 0 ) ;
if ( V_27 < 0 ) {
F_132 ( V_27 == - V_54 ) ;
F_195 ( V_51 ) ;
goto V_355;
}
return V_51 ;
V_355:
if ( V_27 < 0 )
F_70 ( V_28 , V_425 , V_27 ) ;
return NULL ;
}
void F_200 ( struct V_50 * V_51 , struct V_29 * V_30 , T_6 V_78 )
{
struct V_28 * V_28 = F_121 ( V_30 ) ;
F_67 ( V_51 , V_28 , 0 , V_425 , NULL , V_78 ) ;
}
void F_201 ( int type , struct V_29 * V_30 , unsigned int V_200 ,
T_6 V_78 )
{
struct V_50 * V_51 ;
if ( V_30 -> V_415 != V_426 )
return;
V_51 = F_199 ( type , V_30 , V_200 , V_78 ) ;
if ( V_51 )
F_200 ( V_51 , V_30 , V_78 ) ;
}
static int F_202 ( struct V_50 * V_51 ,
struct V_29 * V_30 ,
T_9 * V_427 , T_8 V_428 , T_5 V_68 , T_5 V_199 ,
int type , unsigned int V_78 ,
int V_429 )
{
struct V_76 * V_77 ;
struct V_430 * V_431 ;
V_77 = F_108 ( V_51 , V_68 , V_199 , type , sizeof( * V_431 ) , V_429 ) ;
if ( ! V_77 )
return - V_54 ;
V_431 = F_109 ( V_77 ) ;
V_431 -> V_432 = V_433 ;
V_431 -> V_434 = 0 ;
V_431 -> V_435 = 0 ;
V_431 -> V_436 = V_78 ;
V_431 -> V_437 = 0 ;
V_431 -> V_438 = V_30 -> V_210 ;
V_431 -> V_439 = V_440 ;
if ( F_81 ( V_51 , V_441 , V_442 , V_427 ) )
goto V_90;
if ( V_428 )
if ( F_81 ( V_51 , V_443 , sizeof( T_8 ) , & V_428 ) )
goto V_90;
F_124 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_125 ( V_51 , V_77 ) ;
return - V_54 ;
}
static inline T_4 F_203 ( void )
{
return F_96 ( sizeof( struct V_430 ) ) + F_45 ( V_442 ) ;
}
static void F_204 ( struct V_29 * V_30 , T_9 * V_427 , T_8 V_428 , int type )
{
struct V_28 * V_28 = F_121 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
V_51 = F_194 ( F_203 () , V_444 ) ;
if ( ! V_51 )
goto V_355;
V_27 = F_202 ( V_51 , V_30 , V_427 , V_428 ,
0 , 0 , type , V_445 , 0 ) ;
if ( V_27 < 0 ) {
F_195 ( V_51 ) ;
goto V_355;
}
F_67 ( V_51 , V_28 , 0 , V_446 , NULL , V_444 ) ;
return;
V_355:
F_70 ( V_28 , V_446 , V_27 ) ;
}
int F_205 ( struct V_430 * V_431 ,
struct V_42 * V_314 [] ,
struct V_29 * V_30 ,
const unsigned char * V_427 , T_8 V_428 ,
T_8 V_78 )
{
int V_27 = - V_332 ;
if ( V_431 -> V_439 && ! ( V_431 -> V_439 & V_440 ) ) {
F_206 ( L_6 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( V_428 ) {
F_206 ( L_7 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( F_207 ( V_427 ) || F_208 ( V_427 ) )
V_27 = F_209 ( V_30 , V_427 ) ;
else if ( F_210 ( V_427 ) )
V_27 = F_211 ( V_30 , V_427 ) ;
if ( V_27 == - V_21 && ! ( V_78 & V_407 ) )
V_27 = 0 ;
return V_27 ;
}
static int F_212 ( struct V_42 * V_447 , T_8 * V_448 )
{
T_8 V_428 = 0 ;
if ( V_447 ) {
if ( F_142 ( V_447 ) != sizeof( T_8 ) ) {
F_206 ( L_8 ) ;
return - V_332 ;
}
V_428 = F_213 ( V_447 ) ;
if ( ! V_428 || V_428 >= V_449 ) {
F_206 ( L_9 ,
V_428 ) ;
return - V_332 ;
}
}
* V_448 = V_428 ;
return 0 ;
}
static int F_214 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
struct V_430 * V_431 ;
struct V_42 * V_314 [ V_450 + 1 ] ;
struct V_29 * V_30 ;
T_9 * V_427 ;
T_8 V_428 ;
int V_27 ;
V_27 = F_129 ( V_77 , sizeof( * V_431 ) , V_314 , V_450 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_431 = F_109 ( V_77 ) ;
if ( V_431 -> V_438 == 0 ) {
F_206 ( L_10 ) ;
return - V_332 ;
}
V_30 = F_147 ( V_28 , V_431 -> V_438 ) ;
if ( V_30 == NULL ) {
F_206 ( L_11 ) ;
return - V_364 ;
}
if ( ! V_314 [ V_441 ] || F_142 ( V_314 [ V_441 ] ) != V_442 ) {
F_206 ( L_12 ) ;
return - V_332 ;
}
V_427 = F_118 ( V_314 [ V_441 ] ) ;
V_27 = F_212 ( V_314 [ V_443 ] , & V_428 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_189 ;
if ( ( ! V_431 -> V_436 || V_431 -> V_436 & V_451 ) &&
( V_30 -> V_452 & V_453 ) ) {
struct V_29 * V_454 = F_44 ( V_30 ) ;
const struct V_337 * V_20 = V_454 -> V_171 ;
V_27 = V_20 -> V_455 ( V_431 , V_314 , V_30 , V_427 , V_428 ,
V_77 -> V_406 ) ;
if ( V_27 )
goto V_66;
else
V_431 -> V_436 &= ~ V_451 ;
}
if ( ( V_431 -> V_436 & V_445 ) ) {
if ( V_30 -> V_171 -> V_455 )
V_27 = V_30 -> V_171 -> V_455 ( V_431 , V_314 , V_30 , V_427 ,
V_428 ,
V_77 -> V_406 ) ;
else
V_27 = F_205 ( V_431 , V_314 , V_30 , V_427 , V_428 ,
V_77 -> V_406 ) ;
if ( ! V_27 ) {
F_204 ( V_30 , V_427 , V_428 , V_456 ) ;
V_431 -> V_436 &= ~ V_445 ;
}
}
V_66:
return V_27 ;
}
int F_215 ( struct V_430 * V_431 ,
struct V_42 * V_314 [] ,
struct V_29 * V_30 ,
const unsigned char * V_427 , T_8 V_428 )
{
int V_27 = - V_332 ;
if ( ! ( V_431 -> V_439 & V_440 ) ) {
F_206 ( L_6 , V_30 -> V_89 ) ;
return V_27 ;
}
if ( F_207 ( V_427 ) || F_208 ( V_427 ) )
V_27 = F_216 ( V_30 , V_427 ) ;
else if ( F_210 ( V_427 ) )
V_27 = F_217 ( V_30 , V_427 ) ;
return V_27 ;
}
static int F_218 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
struct V_430 * V_431 ;
struct V_42 * V_314 [ V_450 + 1 ] ;
struct V_29 * V_30 ;
int V_27 = - V_332 ;
T_10 * V_427 ;
T_8 V_428 ;
if ( ! F_219 ( V_51 , V_357 ) )
return - V_358 ;
V_27 = F_129 ( V_77 , sizeof( * V_431 ) , V_314 , V_450 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_431 = F_109 ( V_77 ) ;
if ( V_431 -> V_438 == 0 ) {
F_206 ( L_13 ) ;
return - V_332 ;
}
V_30 = F_147 ( V_28 , V_431 -> V_438 ) ;
if ( V_30 == NULL ) {
F_206 ( L_14 ) ;
return - V_364 ;
}
if ( ! V_314 [ V_441 ] || F_142 ( V_314 [ V_441 ] ) != V_442 ) {
F_206 ( L_15 ) ;
return - V_332 ;
}
V_427 = F_118 ( V_314 [ V_441 ] ) ;
V_27 = F_212 ( V_314 [ V_443 ] , & V_428 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_189 ;
if ( ( ! V_431 -> V_436 || V_431 -> V_436 & V_451 ) &&
( V_30 -> V_452 & V_453 ) ) {
struct V_29 * V_454 = F_44 ( V_30 ) ;
const struct V_337 * V_20 = V_454 -> V_171 ;
if ( V_20 -> V_457 )
V_27 = V_20 -> V_457 ( V_431 , V_314 , V_30 , V_427 , V_428 ) ;
if ( V_27 )
goto V_66;
else
V_431 -> V_436 &= ~ V_451 ;
}
if ( V_431 -> V_436 & V_445 ) {
if ( V_30 -> V_171 -> V_457 )
V_27 = V_30 -> V_171 -> V_457 ( V_431 , V_314 , V_30 , V_427 ,
V_428 ) ;
else
V_27 = F_215 ( V_431 , V_314 , V_30 , V_427 , V_428 ) ;
if ( ! V_27 ) {
F_204 ( V_30 , V_427 , V_428 , V_458 ) ;
V_431 -> V_436 &= ~ V_445 ;
}
}
V_66:
return V_27 ;
}
static int F_220 ( struct V_50 * V_51 ,
struct V_305 * V_306 ,
struct V_29 * V_30 ,
int * V_310 ,
struct V_459 * V_25 )
{
struct V_460 * V_461 ;
int V_27 ;
T_5 V_325 , V_199 ;
V_325 = F_61 ( V_306 -> V_51 ) . V_325 ;
V_199 = V_306 -> V_77 -> V_326 ;
F_26 (ha, &list->list, list) {
if ( * V_310 < V_306 -> args [ 0 ] )
goto V_462;
V_27 = F_202 ( V_51 , V_30 , V_461 -> V_427 , 0 ,
V_325 , V_199 ,
V_456 , V_445 ,
V_327 ) ;
if ( V_27 < 0 )
return V_27 ;
V_462:
* V_310 += 1 ;
}
return 0 ;
}
int F_221 ( struct V_50 * V_51 ,
struct V_305 * V_306 ,
struct V_29 * V_30 ,
struct V_29 * V_463 ,
int V_310 )
{
int V_27 ;
F_222 ( V_30 ) ;
V_27 = F_220 ( V_51 , V_306 , V_30 , & V_310 , & V_30 -> V_464 ) ;
if ( V_27 )
goto V_66;
F_220 ( V_51 , V_306 , V_30 , & V_310 , & V_30 -> V_465 ) ;
V_66:
F_223 ( V_30 ) ;
return V_310 ;
}
static int F_224 ( struct V_50 * V_51 , struct V_305 * V_306 )
{
struct V_29 * V_30 ;
struct V_42 * V_314 [ V_315 + 1 ] ;
struct V_29 * V_454 = NULL ;
const struct V_337 * V_20 = NULL ;
const struct V_337 * V_466 = NULL ;
struct V_121 * V_122 = F_109 ( V_306 -> V_77 ) ;
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
int V_467 = 0 ;
int V_468 = 0 ;
int V_310 = 0 ;
if ( F_129 ( V_306 -> V_77 , sizeof( struct V_121 ) , V_314 , V_315 ,
V_319 ) == 0 ) {
if ( V_314 [ V_228 ] )
V_468 = F_130 ( V_314 [ V_228 ] ) ;
}
V_467 = V_122 -> V_209 ;
if ( V_468 ) {
V_454 = F_147 ( V_28 , V_468 ) ;
if ( ! V_454 )
return - V_364 ;
V_20 = V_454 -> V_171 ;
}
F_32 (net, dev) {
if ( V_467 && ( V_30 -> V_210 != V_467 ) )
continue;
if ( ! V_468 ) {
if ( V_30 -> V_452 & V_453 ) {
V_454 = F_44 ( V_30 ) ;
V_466 = V_454 -> V_171 ;
}
} else {
if ( V_30 != V_454 &&
! ( V_30 -> V_452 & V_453 ) )
continue;
if ( V_454 != F_44 ( V_30 ) &&
! ( V_30 -> V_452 & V_469 ) )
continue;
V_466 = V_20 ;
}
if ( V_30 -> V_452 & V_453 ) {
if ( V_466 && V_466 -> V_470 )
V_310 = V_466 -> V_470 ( V_51 , V_306 , V_454 , V_30 ,
V_310 ) ;
}
if ( V_30 -> V_171 -> V_470 )
V_310 = V_30 -> V_171 -> V_470 ( V_51 , V_306 , V_30 , NULL ,
V_310 ) ;
else
V_310 = F_221 ( V_51 , V_306 , V_30 , NULL , V_310 ) ;
V_466 = NULL ;
}
V_306 -> args [ 0 ] = V_310 ;
return V_51 -> V_328 ;
}
static int F_225 ( struct V_50 * V_51 , T_5 V_78 , T_5 V_471 ,
unsigned int V_472 , unsigned int V_473 )
{
if ( V_471 & V_473 )
return F_111 ( V_51 , V_472 , ! ! ( V_78 & V_473 ) ) ;
return 0 ;
}
int F_226 ( struct V_50 * V_51 , T_5 V_68 , T_5 V_199 ,
struct V_29 * V_30 , T_8 V_474 ,
T_5 V_78 , T_5 V_471 , int V_429 ,
T_5 V_475 ,
int (* F_227)( struct V_50 * V_51 ,
struct V_29 * V_30 ,
T_5 V_475 ) )
{
struct V_76 * V_77 ;
struct V_121 * V_122 ;
struct V_42 * V_476 ;
struct V_42 * V_477 ;
T_9 V_113 = F_112 ( V_30 ) ? V_30 -> V_113 : V_215 ;
struct V_29 * V_454 = F_44 ( V_30 ) ;
int V_27 = 0 ;
V_77 = F_108 ( V_51 , V_68 , V_199 , V_324 , sizeof( * V_122 ) , V_429 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_122 = F_109 ( V_77 ) ;
V_122 -> V_205 = V_433 ;
V_122 -> V_207 = 0 ;
V_122 -> V_208 = V_30 -> type ;
V_122 -> V_209 = V_30 -> V_210 ;
V_122 -> V_123 = F_110 ( V_30 ) ;
V_122 -> V_124 = 0 ;
if ( F_54 ( V_51 , V_211 , V_30 -> V_89 ) ||
F_75 ( V_51 , V_218 , V_30 -> V_219 ) ||
F_111 ( V_51 , V_214 , V_113 ) ||
( V_454 &&
F_75 ( V_51 , V_228 , V_454 -> V_210 ) ) ||
( V_30 -> V_247 &&
F_81 ( V_51 , V_248 , V_30 -> V_247 , V_30 -> V_249 ) ) ||
( V_30 -> V_210 != F_114 ( V_30 ) &&
F_75 ( V_51 , V_227 , F_114 ( V_30 ) ) ) )
goto V_90;
V_476 = F_55 ( V_51 , V_301 ) ;
if ( ! V_476 )
goto V_90;
if ( F_228 ( V_51 , V_478 , V_479 ) ) {
F_57 ( V_51 , V_476 ) ;
goto V_90;
}
if ( V_474 != V_480 ) {
if ( F_228 ( V_51 , V_481 , V_474 ) ) {
F_57 ( V_51 , V_476 ) ;
goto V_90;
}
}
if ( F_227 ) {
V_27 = F_227 ( V_51 , V_30 , V_475 ) ;
if ( V_27 ) {
F_57 ( V_51 , V_476 ) ;
goto V_90;
}
}
F_56 ( V_51 , V_476 ) ;
V_477 = F_55 ( V_51 , V_412 | V_482 ) ;
if ( ! V_477 )
goto V_90;
if ( F_225 ( V_51 , V_78 , V_471 ,
V_483 , V_484 ) ||
F_225 ( V_51 , V_78 , V_471 ,
V_485 , V_486 ) ||
F_225 ( V_51 , V_78 , V_471 ,
V_487 ,
V_488 ) ||
F_225 ( V_51 , V_78 , V_471 ,
V_489 , V_490 ) ||
F_225 ( V_51 , V_78 , V_471 ,
V_491 , V_492 ) ||
F_225 ( V_51 , V_78 , V_471 ,
V_493 , V_494 ) ||
F_225 ( V_51 , V_78 , V_471 ,
V_495 , V_496 ) ||
F_225 ( V_51 , V_78 , V_471 ,
V_497 , V_498 ) ) {
F_57 ( V_51 , V_477 ) ;
goto V_90;
}
F_56 ( V_51 , V_477 ) ;
F_124 ( V_51 , V_77 ) ;
return 0 ;
V_90:
F_125 ( V_51 , V_77 ) ;
return V_27 ? V_27 : - V_54 ;
}
static int F_229 ( struct V_50 * V_51 , struct V_305 * V_306 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
struct V_29 * V_30 ;
int V_310 = 0 ;
T_5 V_325 = F_61 ( V_306 -> V_51 ) . V_325 ;
T_5 V_199 = V_306 -> V_77 -> V_326 ;
T_5 V_475 = 0 ;
int V_27 ;
if ( F_128 ( V_306 -> V_77 ) > sizeof( struct V_121 ) ) {
struct V_42 * V_499 ;
V_499 = F_230 ( V_306 -> V_77 , sizeof( struct V_121 ) ,
V_320 ) ;
if ( V_499 ) {
if ( F_142 ( V_499 ) < sizeof( V_475 ) )
return - V_332 ;
V_475 = F_130 ( V_499 ) ;
}
}
F_231 () ;
F_232 (net, dev) {
const struct V_337 * V_20 = V_30 -> V_171 ;
struct V_29 * V_454 = F_44 ( V_30 ) ;
if ( V_454 && V_454 -> V_171 -> V_500 ) {
if ( V_310 >= V_306 -> args [ 0 ] ) {
V_27 = V_454 -> V_171 -> V_500 (
V_51 , V_325 , V_199 , V_30 ,
V_475 , V_327 ) ;
if ( V_27 < 0 && V_27 != - V_189 )
break;
}
V_310 ++ ;
}
if ( V_20 -> V_500 ) {
if ( V_310 >= V_306 -> args [ 0 ] ) {
V_27 = V_20 -> V_500 ( V_51 , V_325 ,
V_199 , V_30 ,
V_475 ,
V_327 ) ;
if ( V_27 < 0 && V_27 != - V_189 )
break;
}
V_310 ++ ;
}
}
F_233 () ;
V_306 -> args [ 0 ] = V_310 ;
return V_51 -> V_328 ;
}
static inline T_4 F_234 ( void )
{
return F_96 ( sizeof( struct V_121 ) )
+ F_45 ( V_173 )
+ F_45 ( V_176 )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_9 ) )
+ F_45 ( sizeof( struct V_42 ) )
+ F_45 ( sizeof( T_8 ) )
+ F_45 ( sizeof( T_8 ) ) ;
}
static int F_235 ( struct V_29 * V_30 )
{
struct V_28 * V_28 = F_121 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_189 ;
if ( ! V_30 -> V_171 -> V_500 )
return 0 ;
V_51 = F_194 ( F_234 () , V_444 ) ;
if ( ! V_51 ) {
V_27 = - V_369 ;
goto V_355;
}
V_27 = V_30 -> V_171 -> V_500 ( V_51 , 0 , 0 , V_30 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_355;
if ( ! V_51 -> V_328 )
goto V_355;
F_67 ( V_51 , V_28 , 0 , V_425 , NULL , V_444 ) ;
return 0 ;
V_355:
F_132 ( V_27 == - V_54 ) ;
F_195 ( V_51 ) ;
if ( V_27 )
F_70 ( V_28 , V_425 , V_27 ) ;
return V_27 ;
}
static int F_236 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
struct V_121 * V_122 ;
struct V_29 * V_30 ;
struct V_42 * V_501 , * V_194 = NULL ;
int V_333 , V_27 = - V_189 ;
T_8 V_78 = 0 ;
bool V_502 = false ;
if ( F_128 ( V_77 ) < sizeof( * V_122 ) )
return - V_332 ;
V_122 = F_109 ( V_77 ) ;
if ( V_122 -> V_205 != V_433 )
return - V_503 ;
V_30 = F_147 ( V_28 , V_122 -> V_209 ) ;
if ( ! V_30 ) {
F_206 ( L_16 ) ;
return - V_364 ;
}
V_501 = F_230 ( V_77 , sizeof( struct V_121 ) , V_301 ) ;
if ( V_501 ) {
F_143 (attr, br_spec, rem) {
if ( F_144 ( V_194 ) == V_478 ) {
if ( F_142 ( V_194 ) < sizeof( V_78 ) )
return - V_332 ;
V_502 = true ;
V_78 = F_213 ( V_194 ) ;
break;
}
}
}
if ( ! V_78 || ( V_78 & V_504 ) ) {
struct V_29 * V_454 = F_44 ( V_30 ) ;
if ( ! V_454 || ! V_454 -> V_171 -> V_505 ) {
V_27 = - V_189 ;
goto V_66;
}
V_27 = V_454 -> V_171 -> V_505 ( V_30 , V_77 , V_78 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_504 ;
}
if ( ( V_78 & V_479 ) ) {
if ( ! V_30 -> V_171 -> V_505 )
V_27 = - V_189 ;
else
V_27 = V_30 -> V_171 -> V_505 ( V_30 , V_77 ,
V_78 ) ;
if ( ! V_27 ) {
V_78 &= ~ V_479 ;
V_27 = F_235 ( V_30 ) ;
}
}
if ( V_502 )
memcpy ( F_118 ( V_194 ) , & V_78 , sizeof( V_78 ) ) ;
V_66:
return V_27 ;
}
static int F_237 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
struct V_121 * V_122 ;
struct V_29 * V_30 ;
struct V_42 * V_501 , * V_194 = NULL ;
int V_333 , V_27 = - V_189 ;
T_8 V_78 = 0 ;
bool V_502 = false ;
if ( F_128 ( V_77 ) < sizeof( * V_122 ) )
return - V_332 ;
V_122 = F_109 ( V_77 ) ;
if ( V_122 -> V_205 != V_433 )
return - V_503 ;
V_30 = F_147 ( V_28 , V_122 -> V_209 ) ;
if ( ! V_30 ) {
F_206 ( L_16 ) ;
return - V_364 ;
}
V_501 = F_230 ( V_77 , sizeof( struct V_121 ) , V_301 ) ;
if ( V_501 ) {
F_143 (attr, br_spec, rem) {
if ( F_144 ( V_194 ) == V_478 ) {
if ( F_142 ( V_194 ) < sizeof( V_78 ) )
return - V_332 ;
V_502 = true ;
V_78 = F_213 ( V_194 ) ;
break;
}
}
}
if ( ! V_78 || ( V_78 & V_504 ) ) {
struct V_29 * V_454 = F_44 ( V_30 ) ;
if ( ! V_454 || ! V_454 -> V_171 -> V_506 ) {
V_27 = - V_189 ;
goto V_66;
}
V_27 = V_454 -> V_171 -> V_506 ( V_30 , V_77 , V_78 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_504 ;
}
if ( ( V_78 & V_479 ) ) {
if ( ! V_30 -> V_171 -> V_506 )
V_27 = - V_189 ;
else
V_27 = V_30 -> V_171 -> V_506 ( V_30 , V_77 ,
V_78 ) ;
if ( ! V_27 ) {
V_78 &= ~ V_479 ;
V_27 = F_235 ( V_30 ) ;
}
}
if ( V_502 )
memcpy ( F_118 ( V_194 ) , & V_78 , sizeof( V_78 ) ) ;
V_66:
return V_27 ;
}
static int F_238 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_127 ( V_51 -> V_307 ) ;
T_1 V_11 ;
int V_507 , V_19 ;
int V_47 ;
int type ;
int V_27 ;
type = V_77 -> V_421 ;
if ( type > V_508 )
return - V_189 ;
type -= V_4 ;
if ( F_128 ( V_77 ) < sizeof( struct V_318 ) )
return 0 ;
V_47 = ( (struct V_318 * ) F_109 ( V_77 ) ) -> V_509 ;
V_507 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_239 ( V_51 , V_357 ) )
return - V_358 ;
if ( V_19 == 2 && V_77 -> V_406 & V_510 ) {
struct V_71 * V_72 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_511 = 0 ;
V_13 = F_16 ( V_47 , type ) ;
if ( V_13 == NULL )
return - V_189 ;
V_14 = F_17 ( V_47 , type ) ;
if ( V_14 )
V_511 = V_14 ( V_51 , V_77 ) ;
F_3 () ;
V_72 = V_28 -> V_72 ;
{
struct V_512 V_513 = {
. V_514 = V_13 ,
. V_511 = V_511 ,
} ;
V_27 = F_240 ( V_72 , V_51 , V_77 , & V_513 ) ;
}
F_1 () ;
return V_27 ;
}
V_11 = F_15 ( V_47 , type ) ;
if ( V_11 == NULL )
return - V_189 ;
return V_11 ( V_51 , V_77 ) ;
}
static void F_241 ( struct V_50 * V_51 )
{
F_1 () ;
F_242 ( V_51 , & F_238 ) ;
F_5 () ;
}
static int F_243 ( struct V_515 * V_516 , unsigned long V_517 , void * V_518 )
{
struct V_29 * V_30 = F_244 ( V_518 ) ;
switch ( V_517 ) {
case V_519 :
case V_520 :
case V_521 :
case V_522 :
case V_523 :
case V_524 :
case V_525 :
case V_526 :
case V_527 :
case V_528 :
case V_529 :
case V_530 :
case V_531 :
break;
default:
F_201 ( V_324 , V_30 , 0 , V_15 ) ;
break;
}
return V_532 ;
}
static int T_11 F_245 ( struct V_28 * V_28 )
{
struct V_71 * V_307 ;
struct V_533 V_534 = {
. V_535 = V_536 ,
. V_537 = F_241 ,
. V_538 = & V_1 ,
. V_78 = V_539 ,
} ;
V_307 = F_246 ( V_28 , V_540 , & V_534 ) ;
if ( ! V_307 )
return - V_369 ;
V_28 -> V_72 = V_307 ;
return 0 ;
}
static void T_12 F_247 ( struct V_28 * V_28 )
{
F_248 ( V_28 -> V_72 ) ;
V_28 -> V_72 = NULL ;
}
void T_13 F_249 ( void )
{
if ( F_250 ( & V_541 ) )
F_21 ( L_17 ) ;
F_251 ( & V_542 ) ;
F_20 ( V_12 , V_543 , F_193 ,
F_126 , F_196 ) ;
F_20 ( V_12 , V_544 , F_170 , NULL , NULL ) ;
F_20 ( V_12 , V_324 , F_185 , NULL , NULL ) ;
F_20 ( V_12 , V_545 , F_176 , NULL , NULL ) ;
F_20 ( V_12 , V_546 , NULL , F_198 , NULL ) ;
F_20 ( V_12 , V_547 , NULL , F_198 , NULL ) ;
F_20 ( V_548 , V_456 , F_214 , NULL , NULL ) ;
F_20 ( V_548 , V_458 , F_218 , NULL , NULL ) ;
F_20 ( V_548 , V_549 , NULL , F_224 , NULL ) ;
F_20 ( V_548 , V_543 , NULL , F_229 , NULL ) ;
F_20 ( V_548 , V_545 , F_237 , NULL , NULL ) ;
F_20 ( V_548 , V_544 , F_236 , NULL , NULL ) ;
}
