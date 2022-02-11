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
V_83 ++ ;
if ( F_73 ( V_51 , V_82 + 1 , V_80 [ V_82 ] ) )
goto V_86;
}
}
if ( ! V_83 ) {
F_57 ( V_51 , V_81 ) ;
return 0 ;
}
return F_56 ( V_51 , V_81 ) ;
V_86:
F_57 ( V_51 , V_81 ) ;
return - V_54 ;
}
int F_74 ( struct V_50 * V_51 , struct V_87 * V_88 , T_5 V_89 ,
long V_90 , T_5 error )
{
struct V_91 V_92 = {
. V_93 = F_75 ( V_94 - V_88 -> V_95 ) ,
. V_96 = V_88 -> V_97 ,
. V_98 = F_76 ( & ( V_88 -> V_99 ) ) ,
. V_100 = error ,
. V_101 = V_89 ,
} ;
if ( V_90 ) {
unsigned long clock ;
clock = F_77 ( abs ( V_90 ) ) ;
clock = F_78 (unsigned long, clock, INT_MAX) ;
V_92 . V_102 = ( V_90 > 0 ) ? clock : - clock ;
}
return F_79 ( V_51 , V_103 , sizeof( V_92 ) , & V_92 ) ;
}
static void F_80 ( struct V_29 * V_30 , unsigned char V_104 )
{
unsigned char V_105 = V_30 -> V_105 ;
switch ( V_104 ) {
case V_106 :
if ( ( V_105 == V_107 ||
V_105 == V_108 ) &&
! F_81 ( V_30 ) )
V_105 = V_106 ;
break;
case V_107 :
if ( V_105 == V_106 ||
V_105 == V_108 )
V_105 = V_107 ;
break;
}
if ( V_30 -> V_105 != V_105 ) {
F_82 ( & V_109 ) ;
V_30 -> V_105 = V_105 ;
F_83 ( & V_109 ) ;
F_84 ( V_30 ) ;
}
}
static unsigned int F_85 ( const struct V_29 * V_30 )
{
return ( V_30 -> V_78 & ~ ( V_110 | V_111 ) ) |
( V_30 -> V_112 & ( V_110 | V_111 ) ) ;
}
static unsigned int F_86 ( const struct V_29 * V_30 ,
const struct V_113 * V_114 )
{
unsigned int V_78 = V_114 -> V_115 ;
if ( V_114 -> V_116 )
V_78 = ( V_78 & V_114 -> V_116 ) |
( F_85 ( V_30 ) & ~ V_114 -> V_116 ) ;
return V_78 ;
}
static void F_87 ( struct V_117 * V_118 ,
const struct V_119 * V_120 )
{
V_118 -> V_121 = V_120 -> V_121 ;
V_118 -> V_122 = V_120 -> V_122 ;
V_118 -> V_123 = V_120 -> V_123 ;
V_118 -> V_124 = V_120 -> V_124 ;
V_118 -> V_125 = V_120 -> V_125 ;
V_118 -> V_126 = V_120 -> V_126 ;
V_118 -> V_127 = V_120 -> V_127 ;
V_118 -> V_128 = V_120 -> V_128 ;
V_118 -> V_129 = V_120 -> V_129 ;
V_118 -> V_130 = V_120 -> V_130 ;
V_118 -> V_131 = V_120 -> V_131 ;
V_118 -> V_132 = V_120 -> V_132 ;
V_118 -> V_133 = V_120 -> V_133 ;
V_118 -> V_134 = V_120 -> V_134 ;
V_118 -> V_135 = V_120 -> V_135 ;
V_118 -> V_136 = V_120 -> V_136 ;
V_118 -> V_137 = V_120 -> V_137 ;
V_118 -> V_138 = V_120 -> V_138 ;
V_118 -> V_139 = V_120 -> V_139 ;
V_118 -> V_140 = V_120 -> V_140 ;
V_118 -> V_141 = V_120 -> V_141 ;
V_118 -> V_142 = V_120 -> V_142 ;
V_118 -> V_143 = V_120 -> V_143 ;
}
static void F_88 ( void * V_144 , const struct V_119 * V_120 )
{
memcpy ( V_144 , V_120 , sizeof( * V_120 ) ) ;
}
static inline int F_89 ( const struct V_29 * V_30 ,
T_5 V_145 )
{
if ( V_30 -> V_30 . V_146 && F_90 ( V_30 -> V_30 . V_146 ) &&
( V_145 & V_147 ) ) {
int V_148 = F_91 ( V_30 -> V_30 . V_146 ) ;
T_4 V_43 = F_45 ( sizeof( struct V_42 ) ) ;
V_43 += F_45 ( V_148 * sizeof( struct V_42 ) ) ;
V_43 += V_148 *
( F_45 ( sizeof( struct V_149 ) ) +
F_45 ( sizeof( struct V_150 ) ) +
F_45 ( sizeof( struct V_151 ) ) +
F_45 ( sizeof( struct V_152 ) ) +
F_45 ( sizeof( struct V_153 ) ) ) ;
return V_43 ;
} else
return 0 ;
}
static T_4 F_92 ( const struct V_29 * V_30 ,
T_5 V_145 )
{
T_4 V_154 = F_45 ( 4 )
+ F_45 ( V_155 )
+ F_45 ( sizeof( struct V_156 ) )
+ F_45 ( V_157 )
+ F_45 ( V_157 )
+ F_45 ( 1 )
+ F_45 ( 2 ) ;
T_4 V_158 = F_45 ( sizeof( struct V_42 ) ) ;
T_4 V_159 = F_45 ( sizeof( struct V_42 ) )
+ V_154 ;
T_4 V_160 = F_45 ( sizeof( struct V_42 ) )
+ V_154 ;
if ( ! V_30 -> V_161 -> V_162 || ! V_30 -> V_30 . V_146 ||
! ( V_145 & V_147 ) )
return 0 ;
if ( F_91 ( V_30 -> V_30 . V_146 ) )
return V_160 + V_158 +
V_159 * F_91 ( V_30 -> V_30 . V_146 ) ;
else
return V_160 ;
}
static T_7 T_4 F_93 ( const struct V_29 * V_30 ,
T_5 V_145 )
{
return F_94 ( sizeof( struct V_113 ) )
+ F_45 ( V_163 )
+ F_45 ( V_164 )
+ F_45 ( V_163 )
+ F_45 ( sizeof( struct V_165 ) )
+ F_45 ( sizeof( struct V_117 ) )
+ F_45 ( sizeof( struct V_119 ) )
+ F_45 ( V_166 )
+ F_45 ( V_166 )
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
+ F_45 ( V_145
& V_147 ? 4 : 0 )
+ F_89 ( V_30 , V_145 )
+ F_92 ( V_30 , V_145 )
+ F_46 ( V_30 )
+ F_51 ( V_30 )
+ F_45 ( V_167 )
+ F_45 ( V_167 ) ;
}
static int F_95 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_168 ;
struct V_42 * V_169 ;
int V_170 ;
int V_27 ;
V_168 = F_55 ( V_51 , V_171 ) ;
if ( ! V_168 )
return - V_54 ;
for ( V_170 = 0 ; V_170 < F_91 ( V_30 -> V_30 . V_146 ) ; V_170 ++ ) {
V_169 = F_55 ( V_51 , V_172 ) ;
if ( ! V_169 )
goto V_86;
if ( F_73 ( V_51 , V_173 , V_170 ) )
goto V_86;
V_27 = V_30 -> V_161 -> V_162 ( V_30 , V_170 , V_51 ) ;
if ( V_27 == - V_54 )
goto V_86;
if ( V_27 ) {
F_57 ( V_51 , V_169 ) ;
continue;
}
F_56 ( V_51 , V_169 ) ;
}
F_56 ( V_51 , V_168 ) ;
return 0 ;
V_86:
F_57 ( V_51 , V_168 ) ;
return - V_54 ;
}
static int F_96 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
struct V_42 * V_174 ;
int V_27 ;
V_174 = F_55 ( V_51 , V_175 ) ;
if ( ! V_174 )
return - V_54 ;
V_27 = V_30 -> V_161 -> V_162 ( V_30 , V_176 , V_51 ) ;
if ( V_27 ) {
F_57 ( V_51 , V_174 ) ;
return ( V_27 == - V_54 ) ? V_27 : 0 ;
}
F_56 ( V_51 , V_174 ) ;
return 0 ;
}
static int F_97 ( struct V_50 * V_51 , struct V_29 * V_30 ,
T_5 V_145 )
{
int V_27 ;
if ( ! V_30 -> V_161 -> V_162 || ! V_30 -> V_30 . V_146 ||
! ( V_145 & V_147 ) )
return 0 ;
V_27 = F_96 ( V_51 , V_30 ) ;
if ( V_27 )
return V_27 ;
if ( F_91 ( V_30 -> V_30 . V_146 ) ) {
V_27 = F_95 ( V_51 , V_30 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_98 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
int V_27 ;
struct V_177 V_178 ;
V_27 = F_99 ( V_30 , & V_178 ) ;
if ( V_27 ) {
if ( V_27 == - V_179 )
return 0 ;
return V_27 ;
}
if ( F_79 ( V_51 , V_180 , V_178 . V_181 , V_178 . V_89 ) )
return - V_54 ;
return 0 ;
}
static int F_100 ( struct V_50 * V_51 , struct V_29 * V_30 )
{
int V_27 ;
struct V_177 V_182 ;
V_27 = F_101 ( V_30 , & V_182 ) ;
if ( V_27 ) {
if ( V_27 == - V_179 )
return 0 ;
return V_27 ;
}
if ( F_79 ( V_51 , V_183 , V_182 . V_181 , V_182 . V_89 ) )
return - V_54 ;
return 0 ;
}
static int F_102 ( struct V_50 * V_51 , struct V_29 * V_30 ,
int type , T_5 V_68 , T_5 V_184 , T_5 V_185 ,
unsigned int V_78 , T_5 V_145 )
{
struct V_113 * V_114 ;
struct V_76 * V_77 ;
struct V_119 V_186 ;
const struct V_119 * V_187 ;
struct V_42 * V_188 , * V_189 ;
struct V_46 * V_48 ;
struct V_29 * V_190 = F_44 ( V_30 ) ;
F_103 () ;
V_77 = F_104 ( V_51 , V_68 , V_184 , type , sizeof( * V_114 ) , V_78 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_114 = F_105 ( V_77 ) ;
V_114 -> V_191 = V_192 ;
V_114 -> V_193 = 0 ;
V_114 -> V_194 = V_30 -> type ;
V_114 -> V_195 = V_30 -> V_196 ;
V_114 -> V_115 = F_106 ( V_30 ) ;
V_114 -> V_116 = V_185 ;
if ( F_54 ( V_51 , V_197 , V_30 -> V_198 ) ||
F_73 ( V_51 , V_199 , V_30 -> V_200 ) ||
F_107 ( V_51 , V_201 ,
F_108 ( V_30 ) ? V_30 -> V_105 : V_202 ) ||
F_107 ( V_51 , V_203 , V_30 -> V_204 ) ||
F_73 ( V_51 , V_205 , V_30 -> V_206 ) ||
F_73 ( V_51 , V_207 , V_30 -> V_69 ) ||
F_73 ( V_51 , V_208 , V_30 -> V_209 ) ||
F_73 ( V_51 , V_210 , V_30 -> V_211 ) ||
#ifdef F_109
F_73 ( V_51 , V_212 , V_30 -> V_213 ) ||
#endif
( V_30 -> V_196 != V_30 -> V_214 &&
F_73 ( V_51 , V_215 , V_30 -> V_214 ) ) ||
( V_190 &&
F_73 ( V_51 , V_216 , V_190 -> V_196 ) ) ||
F_107 ( V_51 , V_217 , F_110 ( V_30 ) ) ||
( V_30 -> V_218 &&
F_54 ( V_51 , V_219 , V_30 -> V_218 -> V_20 -> V_89 ) ) ||
( V_30 -> V_220 &&
F_54 ( V_51 , V_221 , V_30 -> V_220 ) ) ||
F_73 ( V_51 , V_222 ,
F_76 ( & V_30 -> V_223 ) ) )
goto V_86;
if ( 1 ) {
struct V_165 V_224 = {
. V_225 = V_30 -> V_225 ,
. V_226 = V_30 -> V_226 ,
. V_227 = V_30 -> V_227 ,
. V_228 = V_30 -> V_228 ,
. V_229 = V_30 -> V_229 ,
. V_230 = V_30 -> V_231 ,
} ;
if ( F_79 ( V_51 , V_232 , sizeof( V_224 ) , & V_224 ) )
goto V_86;
}
if ( V_30 -> V_233 ) {
if ( F_79 ( V_51 , V_234 , V_30 -> V_233 , V_30 -> V_235 ) ||
F_79 ( V_51 , V_236 , V_30 -> V_233 , V_30 -> V_237 ) )
goto V_86;
}
if ( F_98 ( V_51 , V_30 ) )
goto V_86;
if ( F_100 ( V_51 , V_30 ) )
goto V_86;
V_188 = F_111 ( V_51 , V_238 ,
sizeof( struct V_117 ) ) ;
if ( V_188 == NULL )
goto V_86;
V_187 = F_112 ( V_30 , & V_186 ) ;
F_87 ( F_113 ( V_188 ) , V_187 ) ;
V_188 = F_111 ( V_51 , V_239 ,
sizeof( struct V_119 ) ) ;
if ( V_188 == NULL )
goto V_86;
F_88 ( F_113 ( V_188 ) , V_187 ) ;
if ( V_30 -> V_30 . V_146 && ( V_145 & V_147 ) &&
F_73 ( V_51 , V_240 , F_91 ( V_30 -> V_30 . V_146 ) ) )
goto V_86;
if ( V_30 -> V_161 -> V_241 && V_30 -> V_30 . V_146
&& ( V_145 & V_147 ) ) {
int V_82 ;
struct V_42 * V_242 , * V_170 ;
int V_148 = F_91 ( V_30 -> V_30 . V_146 ) ;
V_242 = F_55 ( V_51 , V_243 ) ;
if ( ! V_242 )
goto V_86;
for ( V_82 = 0 ; V_82 < V_148 ; V_82 ++ ) {
struct V_244 V_245 ;
struct V_149 V_246 ;
struct V_150 V_247 ;
struct V_152 V_248 ;
struct V_249 V_250 ;
struct V_151 V_251 ;
struct V_153 V_252 ;
V_245 . V_253 = - 1 ;
memset ( V_245 . V_254 , 0 , sizeof( V_245 . V_254 ) ) ;
V_245 . V_255 = 0 ;
if ( V_30 -> V_161 -> V_241 ( V_30 , V_82 , & V_245 ) )
break;
V_246 . V_170 =
V_247 . V_170 =
V_248 . V_170 =
V_250 . V_170 =
V_251 . V_170 =
V_252 . V_170 = V_245 . V_170 ;
memcpy ( V_246 . V_254 , V_245 . V_254 , sizeof( V_245 . V_254 ) ) ;
V_247 . V_256 = V_245 . V_256 ;
V_247 . V_257 = V_245 . V_257 ;
V_250 . V_258 = V_245 . V_259 ;
V_248 . V_260 = V_245 . V_260 ;
V_248 . V_259 = V_245 . V_259 ;
V_251 . V_261 = V_245 . V_253 ;
V_252 . V_262 = V_245 . V_255 ;
V_170 = F_55 ( V_51 , V_263 ) ;
if ( ! V_170 ) {
F_57 ( V_51 , V_242 ) ;
goto V_86;
}
if ( F_79 ( V_51 , V_264 , sizeof( V_246 ) , & V_246 ) ||
F_79 ( V_51 , V_265 , sizeof( V_247 ) , & V_247 ) ||
F_79 ( V_51 , V_266 , sizeof( V_248 ) ,
& V_248 ) ||
F_79 ( V_51 , V_267 , sizeof( V_250 ) ,
& V_250 ) ||
F_79 ( V_51 , V_268 , sizeof( V_251 ) ,
& V_251 ) ||
F_79 ( V_51 , V_269 , sizeof( V_252 ) ,
& V_252 ) )
goto V_86;
F_56 ( V_51 , V_170 ) ;
}
F_56 ( V_51 , V_242 ) ;
}
if ( F_97 ( V_51 , V_30 , V_145 ) )
goto V_86;
if ( V_30 -> V_18 || F_52 ( V_30 ) ) {
if ( F_59 ( V_51 , V_30 ) < 0 )
goto V_86;
}
if ( ! ( V_189 = F_55 ( V_51 , V_270 ) ) )
goto V_86;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_48 -> V_271 ) {
struct V_42 * V_272 ;
int V_27 ;
if ( ! ( V_272 = F_55 ( V_51 , V_48 -> V_47 ) ) )
goto V_86;
V_27 = V_48 -> V_271 ( V_51 , V_30 ) ;
if ( V_27 == - V_273 )
F_57 ( V_51 , V_272 ) ;
else if ( V_27 < 0 )
goto V_86;
F_56 ( V_51 , V_272 ) ;
}
}
F_56 ( V_51 , V_189 ) ;
return F_114 ( V_51 , V_77 ) ;
V_86:
F_115 ( V_51 , V_77 ) ;
return - V_54 ;
}
static int F_116 ( struct V_50 * V_51 , struct V_274 * V_275 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
int V_277 , V_278 ;
int V_279 = 0 , V_280 ;
struct V_29 * V_30 ;
struct V_281 * V_282 ;
struct V_42 * V_283 [ V_284 + 1 ] ;
T_5 V_145 = 0 ;
int V_27 ;
int V_285 ;
V_278 = V_275 -> args [ 0 ] ;
V_280 = V_275 -> args [ 1 ] ;
F_118 () ;
V_275 -> V_184 = V_28 -> V_286 ;
V_285 = F_119 ( V_275 -> V_77 ) < sizeof( struct V_113 ) ?
sizeof( struct V_287 ) : sizeof( struct V_113 ) ;
if ( F_120 ( V_275 -> V_77 , V_285 , V_283 , V_284 , V_288 ) >= 0 ) {
if ( V_283 [ V_289 ] )
V_145 = F_121 ( V_283 [ V_289 ] ) ;
}
for ( V_277 = V_278 ; V_277 < V_290 ; V_277 ++ , V_280 = 0 ) {
V_279 = 0 ;
V_282 = & V_28 -> V_291 [ V_277 ] ;
F_122 (dev, head, index_hlist) {
if ( V_279 < V_280 )
goto V_292;
V_27 = F_102 ( V_51 , V_30 , V_293 ,
F_61 ( V_275 -> V_51 ) . V_294 ,
V_275 -> V_77 -> V_295 , 0 ,
V_296 ,
V_145 ) ;
F_123 ( ( V_27 == - V_54 ) && ( V_51 -> V_297 == 0 ) ) ;
if ( V_27 <= 0 )
goto V_66;
F_124 ( V_275 , F_125 ( V_51 ) ) ;
V_292:
V_279 ++ ;
}
}
V_66:
F_126 () ;
V_275 -> args [ 1 ] = V_279 ;
V_275 -> args [ 0 ] = V_277 ;
return V_51 -> V_297 ;
}
int F_127 ( struct V_42 * * V_283 , const struct V_42 * V_282 , int V_297 )
{
return F_128 ( V_283 , V_284 , V_282 , V_297 , V_288 ) ;
}
struct V_28 * F_129 ( struct V_28 * V_298 , struct V_42 * V_283 [] )
{
struct V_28 * V_28 ;
if ( V_283 [ V_299 ] )
V_28 = F_130 ( F_121 ( V_283 [ V_299 ] ) ) ;
else if ( V_283 [ V_300 ] )
V_28 = F_131 ( F_121 ( V_283 [ V_300 ] ) ) ;
else
V_28 = F_132 ( V_298 ) ;
return V_28 ;
}
static int F_133 ( struct V_29 * V_30 , struct V_42 * V_283 [] )
{
if ( V_30 ) {
if ( V_283 [ V_234 ] &&
F_134 ( V_283 [ V_234 ] ) < V_30 -> V_233 )
return - V_301 ;
if ( V_283 [ V_236 ] &&
F_134 ( V_283 [ V_236 ] ) < V_30 -> V_233 )
return - V_301 ;
}
if ( V_283 [ V_270 ] ) {
struct V_42 * V_272 ;
int V_302 , V_27 ;
F_135 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_136 ( V_272 ) ) ) )
return - V_303 ;
if ( ! V_48 -> V_304 )
return - V_179 ;
if ( V_48 -> V_305 ) {
V_27 = V_48 -> V_305 ( V_30 , V_272 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_137 ( struct V_29 * V_30 , struct V_42 * V_188 )
{
int V_302 , V_27 = - V_301 ;
struct V_42 * V_170 ;
const struct V_306 * V_20 = V_30 -> V_161 ;
F_135 (vf, attr, rem) {
switch ( F_136 ( V_170 ) ) {
case V_264 : {
struct V_149 * V_307 ;
V_307 = F_113 ( V_170 ) ;
V_27 = - V_179 ;
if ( V_20 -> V_308 )
V_27 = V_20 -> V_308 ( V_30 , V_307 -> V_170 ,
V_307 -> V_254 ) ;
break;
}
case V_265 : {
struct V_150 * V_309 ;
V_309 = F_113 ( V_170 ) ;
V_27 = - V_179 ;
if ( V_20 -> V_310 )
V_27 = V_20 -> V_310 ( V_30 , V_309 -> V_170 ,
V_309 -> V_256 ,
V_309 -> V_257 ) ;
break;
}
case V_267 : {
struct V_249 * V_311 ;
struct V_244 V_312 ;
V_311 = F_113 ( V_170 ) ;
V_27 = - V_179 ;
if ( V_20 -> V_241 )
V_27 = V_20 -> V_241 ( V_30 , V_311 -> V_170 ,
& V_312 ) ;
if ( V_27 )
break;
V_27 = - V_179 ;
if ( V_20 -> V_313 )
V_27 = V_20 -> V_313 ( V_30 , V_311 -> V_170 ,
V_312 . V_260 ,
V_311 -> V_258 ) ;
break;
}
case V_266 : {
struct V_152 * V_311 ;
V_311 = F_113 ( V_170 ) ;
V_27 = - V_179 ;
if ( V_20 -> V_313 )
V_27 = V_20 -> V_313 ( V_30 , V_311 -> V_170 ,
V_311 -> V_260 ,
V_311 -> V_259 ) ;
break;
}
case V_268 : {
struct V_151 * V_314 ;
V_314 = F_113 ( V_170 ) ;
V_27 = - V_179 ;
if ( V_20 -> V_315 )
V_27 = V_20 -> V_315 ( V_30 , V_314 -> V_170 ,
V_314 -> V_261 ) ;
break;
}
case V_269 : {
struct V_153 * V_316 ;
V_316 = F_113 ( V_170 ) ;
V_27 = - V_179 ;
if ( V_20 -> V_317 )
V_27 = V_20 -> V_317 ( V_30 , V_316 -> V_170 ,
V_316 -> V_262 ) ;
break;
}
default:
V_27 = - V_301 ;
break;
}
if ( V_27 )
break;
}
return V_27 ;
}
static int F_138 ( struct V_29 * V_30 , int V_196 )
{
struct V_29 * V_190 = F_44 ( V_30 ) ;
const struct V_306 * V_20 ;
int V_27 ;
if ( V_190 ) {
if ( V_190 -> V_196 == V_196 )
return 0 ;
V_20 = V_190 -> V_161 ;
if ( V_20 -> V_318 ) {
V_27 = V_20 -> V_318 ( V_190 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_179 ;
}
}
if ( V_196 ) {
V_190 = F_139 ( F_140 ( V_30 ) , V_196 ) ;
if ( ! V_190 )
return - V_301 ;
V_20 = V_190 -> V_161 ;
if ( V_20 -> V_319 ) {
V_27 = V_20 -> V_319 ( V_190 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_179 ;
}
}
return 0 ;
}
static int F_141 ( const struct V_50 * V_51 ,
struct V_29 * V_30 , struct V_113 * V_114 ,
struct V_42 * * V_283 , char * V_320 , int V_321 )
{
const struct V_306 * V_20 = V_30 -> V_161 ;
int V_27 ;
if ( V_283 [ V_299 ] || V_283 [ V_300 ] ) {
struct V_28 * V_28 = F_129 ( F_140 ( V_30 ) , V_283 ) ;
if ( F_142 ( V_28 ) ) {
V_27 = F_143 ( V_28 ) ;
goto V_322;
}
if ( ! F_144 ( V_51 , V_28 -> V_323 , V_324 ) ) {
F_145 ( V_28 ) ;
V_27 = - V_325 ;
goto V_322;
}
V_27 = F_146 ( V_30 , V_28 , V_320 ) ;
F_145 ( V_28 ) ;
if ( V_27 )
goto V_322;
V_321 |= V_326 ;
}
if ( V_283 [ V_232 ] ) {
struct V_165 * V_327 ;
struct V_328 V_329 ;
if ( ! V_20 -> V_330 ) {
V_27 = - V_179 ;
goto V_322;
}
if ( ! F_147 ( V_30 ) ) {
V_27 = - V_331 ;
goto V_322;
}
V_327 = F_113 ( V_283 [ V_232 ] ) ;
V_329 . V_225 = ( unsigned long ) V_327 -> V_225 ;
V_329 . V_226 = ( unsigned long ) V_327 -> V_226 ;
V_329 . V_227 = ( unsigned short ) V_327 -> V_227 ;
V_329 . V_228 = ( unsigned char ) V_327 -> V_228 ;
V_329 . V_229 = ( unsigned char ) V_327 -> V_229 ;
V_329 . V_230 = ( unsigned char ) V_327 -> V_230 ;
V_27 = V_20 -> V_330 ( V_30 , & V_329 ) ;
if ( V_27 < 0 )
goto V_322;
V_321 |= V_332 ;
}
if ( V_283 [ V_234 ] ) {
struct V_333 * V_334 ;
int V_297 ;
V_297 = sizeof( V_335 ) + V_30 -> V_233 ;
V_334 = F_148 ( V_297 , V_15 ) ;
if ( ! V_334 ) {
V_27 = - V_336 ;
goto V_322;
}
V_334 -> V_337 = V_30 -> type ;
memcpy ( V_334 -> V_338 , F_113 ( V_283 [ V_234 ] ) ,
V_30 -> V_233 ) ;
V_27 = F_149 ( V_30 , V_334 ) ;
F_24 ( V_334 ) ;
if ( V_27 )
goto V_322;
V_321 |= V_326 ;
}
if ( V_283 [ V_205 ] ) {
V_27 = F_150 ( V_30 , F_121 ( V_283 [ V_205 ] ) ) ;
if ( V_27 < 0 )
goto V_322;
V_321 |= V_326 ;
}
if ( V_283 [ V_207 ] ) {
F_151 ( V_30 , F_121 ( V_283 [ V_207 ] ) ) ;
V_321 |= V_332 ;
}
if ( V_114 -> V_195 > 0 && V_320 [ 0 ] ) {
V_27 = F_152 ( V_30 , V_320 ) ;
if ( V_27 < 0 )
goto V_322;
V_321 |= V_326 ;
}
if ( V_283 [ V_221 ] ) {
V_27 = F_153 ( V_30 , F_113 ( V_283 [ V_221 ] ) ,
F_134 ( V_283 [ V_221 ] ) ) ;
if ( V_27 < 0 )
goto V_322;
V_321 |= V_332 ;
}
if ( V_283 [ V_236 ] ) {
F_154 ( V_30 -> V_237 , V_283 [ V_236 ] , V_30 -> V_233 ) ;
F_155 ( V_339 , V_30 ) ;
}
if ( V_114 -> V_115 || V_114 -> V_116 ) {
V_27 = F_156 ( V_30 , F_86 ( V_30 , V_114 ) ) ;
if ( V_27 < 0 )
goto V_322;
}
if ( V_283 [ V_216 ] ) {
V_27 = F_138 ( V_30 , F_121 ( V_283 [ V_216 ] ) ) ;
if ( V_27 )
goto V_322;
V_321 |= V_326 ;
}
if ( V_283 [ V_217 ] ) {
V_27 = F_157 ( V_30 , F_158 ( V_283 [ V_217 ] ) ) ;
if ( V_27 )
goto V_322;
V_321 |= V_326 ;
}
if ( V_283 [ V_199 ] ) {
unsigned long V_340 = F_121 ( V_283 [ V_199 ] ) ;
if ( V_30 -> V_200 ^ V_340 )
V_321 |= V_332 ;
V_30 -> V_200 = V_340 ;
}
if ( V_283 [ V_201 ] )
F_80 ( V_30 , F_158 ( V_283 [ V_201 ] ) ) ;
if ( V_283 [ V_203 ] ) {
unsigned char V_340 = F_158 ( V_283 [ V_203 ] ) ;
F_82 ( & V_109 ) ;
if ( V_30 -> V_204 ^ V_340 )
V_321 |= V_332 ;
V_30 -> V_204 = V_340 ;
F_83 ( & V_109 ) ;
}
if ( V_283 [ V_243 ] ) {
struct V_42 * V_188 ;
int V_302 ;
F_135 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_136 ( V_188 ) != V_263 ) {
V_27 = - V_301 ;
goto V_322;
}
V_27 = F_137 ( V_30 , V_188 ) ;
if ( V_27 < 0 )
goto V_322;
V_321 |= V_332 ;
}
}
V_27 = 0 ;
if ( V_283 [ V_171 ] ) {
struct V_42 * V_230 [ V_341 + 1 ] ;
struct V_42 * V_188 ;
int V_170 ;
int V_302 ;
V_27 = - V_179 ;
if ( ! V_20 -> V_342 )
goto V_322;
F_135 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_136 ( V_188 ) != V_172 )
continue;
V_27 = F_159 ( V_230 , V_341 ,
V_188 , V_343 ) ;
if ( V_27 < 0 )
goto V_322;
if ( ! V_230 [ V_173 ] ) {
V_27 = - V_179 ;
goto V_322;
}
V_170 = F_121 ( V_230 [ V_173 ] ) ;
V_27 = V_20 -> V_342 ( V_30 , V_170 , V_230 ) ;
if ( V_27 < 0 )
goto V_322;
V_321 |= V_332 ;
}
}
V_27 = 0 ;
if ( V_283 [ V_175 ] ) {
struct V_42 * V_230 [ V_341 + 1 ] ;
V_27 = F_159 ( V_230 , V_341 ,
V_283 [ V_175 ] , V_343 ) ;
if ( V_27 < 0 )
goto V_322;
V_27 = - V_179 ;
if ( V_20 -> V_342 )
V_27 = V_20 -> V_342 ( V_30 , V_176 , V_230 ) ;
if ( V_27 < 0 )
goto V_322;
V_321 |= V_332 ;
}
if ( V_283 [ V_270 ] ) {
struct V_42 * V_272 ;
int V_302 ;
F_135 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_48 ;
if ( ! ( V_48 = F_47 ( F_136 ( V_272 ) ) ) )
F_160 () ;
V_27 = V_48 -> V_304 ( V_30 , V_272 ) ;
if ( V_27 < 0 )
goto V_322;
V_321 |= V_332 ;
}
}
V_27 = 0 ;
V_322:
if ( V_321 & V_326 ) {
if ( V_321 & V_332 )
F_84 ( V_30 ) ;
if ( V_27 < 0 )
F_161 ( L_3 ,
V_30 -> V_198 ) ;
}
return V_27 ;
}
static int F_162 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
struct V_113 * V_114 ;
struct V_29 * V_30 ;
int V_27 ;
struct V_42 * V_283 [ V_284 + 1 ] ;
char V_320 [ V_163 ] ;
V_27 = F_120 ( V_77 , sizeof( * V_114 ) , V_283 , V_284 , V_288 ) ;
if ( V_27 < 0 )
goto V_322;
if ( V_283 [ V_197 ] )
F_163 ( V_320 , V_283 [ V_197 ] , V_163 ) ;
else
V_320 [ 0 ] = '\0' ;
V_27 = - V_301 ;
V_114 = F_105 ( V_77 ) ;
if ( V_114 -> V_195 > 0 )
V_30 = F_139 ( V_28 , V_114 -> V_195 ) ;
else if ( V_283 [ V_197 ] )
V_30 = F_164 ( V_28 , V_320 ) ;
else
goto V_322;
if ( V_30 == NULL ) {
V_27 = - V_331 ;
goto V_322;
}
V_27 = F_133 ( V_30 , V_283 ) ;
if ( V_27 < 0 )
goto V_322;
V_27 = F_141 ( V_51 , V_30 , V_114 , V_283 , V_320 , 0 ) ;
V_322:
return V_27 ;
}
static int F_165 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
const struct V_18 * V_20 ;
struct V_29 * V_30 ;
struct V_113 * V_114 ;
char V_320 [ V_163 ] ;
struct V_42 * V_283 [ V_284 + 1 ] ;
int V_27 ;
F_31 ( V_31 ) ;
V_27 = F_120 ( V_77 , sizeof( * V_114 ) , V_283 , V_284 , V_288 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_283 [ V_197 ] )
F_163 ( V_320 , V_283 [ V_197 ] , V_163 ) ;
V_114 = F_105 ( V_77 ) ;
if ( V_114 -> V_195 > 0 )
V_30 = F_139 ( V_28 , V_114 -> V_195 ) ;
else if ( V_283 [ V_197 ] )
V_30 = F_164 ( V_28 , V_320 ) ;
else
return - V_301 ;
if ( ! V_30 )
return - V_331 ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_179 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
return 0 ;
}
int F_166 ( struct V_29 * V_30 , const struct V_113 * V_114 )
{
unsigned int V_344 ;
int V_27 ;
V_344 = V_30 -> V_78 ;
if ( V_114 && ( V_114 -> V_115 || V_114 -> V_116 ) ) {
V_27 = F_167 ( V_30 , F_86 ( V_30 , V_114 ) ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_30 -> V_345 = V_346 ;
F_168 ( V_30 , V_344 , ~ 0U ) ;
return 0 ;
}
struct V_29 * F_169 ( struct V_28 * V_28 ,
char * V_320 , unsigned char V_347 ,
const struct V_18 * V_20 , struct V_42 * V_283 [] )
{
int V_27 ;
struct V_29 * V_30 ;
unsigned int V_211 = 1 ;
unsigned int V_213 = 1 ;
if ( V_283 [ V_210 ] )
V_211 = F_121 ( V_283 [ V_210 ] ) ;
else if ( V_20 -> V_348 )
V_211 = V_20 -> V_348 () ;
if ( V_283 [ V_212 ] )
V_213 = F_121 ( V_283 [ V_212 ] ) ;
else if ( V_20 -> V_349 )
V_213 = V_20 -> V_349 () ;
V_27 = - V_336 ;
V_30 = F_170 ( V_20 -> V_350 , V_320 , V_347 ,
V_20 -> V_22 , V_211 , V_213 ) ;
if ( ! V_30 )
goto V_27;
F_171 ( V_30 , V_28 ) ;
V_30 -> V_18 = V_20 ;
V_30 -> V_345 = V_351 ;
if ( V_283 [ V_205 ] )
V_30 -> V_206 = F_121 ( V_283 [ V_205 ] ) ;
if ( V_283 [ V_234 ] ) {
memcpy ( V_30 -> V_235 , F_113 ( V_283 [ V_234 ] ) ,
F_134 ( V_283 [ V_234 ] ) ) ;
V_30 -> V_352 = V_353 ;
}
if ( V_283 [ V_236 ] )
memcpy ( V_30 -> V_237 , F_113 ( V_283 [ V_236 ] ) ,
F_134 ( V_283 [ V_236 ] ) ) ;
if ( V_283 [ V_199 ] )
V_30 -> V_200 = F_121 ( V_283 [ V_199 ] ) ;
if ( V_283 [ V_201 ] )
F_80 ( V_30 , F_158 ( V_283 [ V_201 ] ) ) ;
if ( V_283 [ V_203 ] )
V_30 -> V_204 = F_158 ( V_283 [ V_203 ] ) ;
if ( V_283 [ V_207 ] )
F_151 ( V_30 , F_121 ( V_283 [ V_207 ] ) ) ;
return V_30 ;
V_27:
return F_172 ( V_27 ) ;
}
static int F_173 ( const struct V_50 * V_51 ,
struct V_28 * V_28 , int V_69 ,
struct V_113 * V_114 ,
struct V_42 * * V_283 )
{
struct V_29 * V_30 ;
int V_27 ;
F_32 (net, dev) {
if ( V_30 -> V_69 == V_69 ) {
V_27 = F_141 ( V_51 , V_30 , V_114 , V_283 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_174 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_354 = NULL ;
struct V_29 * V_30 ;
struct V_29 * V_40 = NULL ;
struct V_113 * V_114 ;
char V_19 [ V_355 ] ;
char V_320 [ V_163 ] ;
struct V_42 * V_283 [ V_284 + 1 ] ;
struct V_42 * V_64 [ V_356 + 1 ] ;
unsigned char V_347 = V_357 ;
int V_27 ;
#ifdef F_175
V_358:
#endif
V_27 = F_120 ( V_77 , sizeof( * V_114 ) , V_283 , V_284 , V_288 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_283 [ V_197 ] )
F_163 ( V_320 , V_283 [ V_197 ] , V_163 ) ;
else
V_320 [ 0 ] = '\0' ;
V_114 = F_105 ( V_77 ) ;
if ( V_114 -> V_195 > 0 )
V_30 = F_139 ( V_28 , V_114 -> V_195 ) ;
else {
if ( V_320 [ 0 ] )
V_30 = F_164 ( V_28 , V_320 ) ;
else
V_30 = NULL ;
}
if ( V_30 ) {
V_40 = F_44 ( V_30 ) ;
if ( V_40 )
V_354 = V_40 -> V_18 ;
}
V_27 = F_133 ( V_30 , V_283 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_283 [ V_65 ] ) {
V_27 = F_159 ( V_64 , V_356 ,
V_283 [ V_65 ] , V_359 ) ;
if ( V_27 < 0 )
return V_27 ;
} else
memset ( V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_64 [ V_59 ] ) {
F_163 ( V_19 , V_64 [ V_59 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_42 * V_188 [ V_20 ? V_20 -> V_360 + 1 : 0 ] ;
struct V_42 * V_361 [ V_354 ? V_354 -> V_362 + 1 : 0 ] ;
struct V_42 * * V_58 = NULL ;
struct V_42 * * V_52 = NULL ;
struct V_28 * V_363 ;
if ( V_20 ) {
if ( V_20 -> V_360 && V_64 [ V_62 ] ) {
V_27 = F_159 ( V_188 , V_20 -> V_360 ,
V_64 [ V_62 ] ,
V_20 -> V_364 ) ;
if ( V_27 < 0 )
return V_27 ;
V_58 = V_188 ;
}
if ( V_20 -> V_365 ) {
V_27 = V_20 -> V_365 ( V_283 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_354 ) {
if ( V_354 -> V_362 &&
V_64 [ V_56 ] ) {
V_27 = F_159 ( V_361 ,
V_354 -> V_362 ,
V_64 [ V_56 ] ,
V_354 -> V_366 ) ;
if ( V_27 < 0 )
return V_27 ;
V_52 = V_361 ;
}
if ( V_354 -> V_367 ) {
V_27 = V_354 -> V_367 ( V_283 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_30 ) {
int V_321 = 0 ;
if ( V_77 -> V_368 & V_369 )
return - V_21 ;
if ( V_77 -> V_368 & V_370 )
return - V_179 ;
if ( V_64 [ V_62 ] ) {
if ( ! V_20 || V_20 != V_30 -> V_18 ||
! V_20 -> V_371 )
return - V_179 ;
V_27 = V_20 -> V_371 ( V_30 , V_283 , V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
V_321 |= V_332 ;
}
if ( V_64 [ V_56 ] ) {
if ( ! V_354 || ! V_354 -> V_372 )
return - V_179 ;
V_27 = V_354 -> V_372 ( V_40 , V_30 ,
V_283 , V_52 ) ;
if ( V_27 < 0 )
return V_27 ;
V_321 |= V_332 ;
}
return F_141 ( V_51 , V_30 , V_114 , V_283 , V_320 , V_321 ) ;
}
if ( ! ( V_77 -> V_368 & V_373 ) ) {
if ( V_114 -> V_195 == 0 && V_283 [ V_207 ] )
return F_173 ( V_51 , V_28 ,
F_121 ( V_283 [ V_207 ] ) ,
V_114 , V_283 ) ;
return - V_331 ;
}
if ( V_283 [ V_232 ] || V_283 [ V_216 ] || V_283 [ V_374 ] )
return - V_179 ;
if ( ! V_20 ) {
#ifdef F_175
if ( V_19 [ 0 ] ) {
F_3 () ;
F_176 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_358;
}
#endif
return - V_179 ;
}
if ( ! V_20 -> V_22 )
return - V_179 ;
if ( ! V_320 [ 0 ] ) {
snprintf ( V_320 , V_163 , L_5 , V_20 -> V_19 ) ;
V_347 = V_375 ;
}
V_363 = F_129 ( V_28 , V_283 ) ;
if ( F_142 ( V_363 ) )
return F_143 ( V_363 ) ;
V_30 = F_169 ( V_363 , V_320 , V_347 , V_20 , V_283 ) ;
if ( F_142 ( V_30 ) ) {
V_27 = F_143 ( V_30 ) ;
goto V_66;
}
V_30 -> V_196 = V_114 -> V_195 ;
if ( V_20 -> V_376 ) {
V_27 = V_20 -> V_376 ( V_28 , V_30 , V_283 , V_58 ) ;
if ( V_27 < 0 ) {
if ( V_30 -> V_377 == V_378 )
F_177 ( V_30 ) ;
goto V_66;
}
} else {
V_27 = F_178 ( V_30 ) ;
if ( V_27 < 0 ) {
F_177 ( V_30 ) ;
goto V_66;
}
}
V_27 = F_166 ( V_30 , V_114 ) ;
if ( V_27 < 0 )
F_179 ( V_30 ) ;
V_66:
F_145 ( V_363 ) ;
return V_27 ;
}
}
static int F_180 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
struct V_113 * V_114 ;
char V_320 [ V_163 ] ;
struct V_42 * V_283 [ V_284 + 1 ] ;
struct V_29 * V_30 = NULL ;
struct V_50 * V_379 ;
int V_27 ;
T_5 V_145 = 0 ;
V_27 = F_120 ( V_77 , sizeof( * V_114 ) , V_283 , V_284 , V_288 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_283 [ V_197 ] )
F_163 ( V_320 , V_283 [ V_197 ] , V_163 ) ;
if ( V_283 [ V_289 ] )
V_145 = F_121 ( V_283 [ V_289 ] ) ;
V_114 = F_105 ( V_77 ) ;
if ( V_114 -> V_195 > 0 )
V_30 = F_139 ( V_28 , V_114 -> V_195 ) ;
else if ( V_283 [ V_197 ] )
V_30 = F_164 ( V_28 , V_320 ) ;
else
return - V_301 ;
if ( V_30 == NULL )
return - V_331 ;
V_379 = F_181 ( F_93 ( V_30 , V_145 ) , V_15 ) ;
if ( V_379 == NULL )
return - V_16 ;
V_27 = F_102 ( V_379 , V_30 , V_293 , F_61 ( V_51 ) . V_294 ,
V_77 -> V_295 , 0 , 0 , V_145 ) ;
if ( V_27 < 0 ) {
F_123 ( V_27 == - V_54 ) ;
F_182 ( V_379 ) ;
} else
V_27 = F_65 ( V_379 , V_28 , F_61 ( V_51 ) . V_294 ) ;
return V_27 ;
}
static T_8 F_183 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
struct V_29 * V_30 ;
struct V_42 * V_283 [ V_284 + 1 ] ;
T_5 V_145 = 0 ;
T_8 V_380 = 0 ;
int V_285 ;
V_285 = F_119 ( V_77 ) < sizeof( struct V_113 ) ?
sizeof( struct V_287 ) : sizeof( struct V_113 ) ;
if ( F_120 ( V_77 , V_285 , V_283 , V_284 , V_288 ) >= 0 ) {
if ( V_283 [ V_289 ] )
V_145 = F_121 ( V_283 [ V_289 ] ) ;
}
if ( ! V_145 )
return V_381 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_380 = F_184 ( T_8 , V_380 ,
F_93 ( V_30 ,
V_145 ) ) ;
}
return V_380 ;
}
static int F_185 ( struct V_50 * V_51 , struct V_274 * V_275 )
{
int V_279 ;
int V_280 = V_275 -> V_47 ;
if ( V_280 == 0 )
V_280 = 1 ;
for ( V_279 = 1 ; V_279 <= V_9 ; V_279 ++ ) {
int type = V_275 -> V_77 -> V_382 - V_4 ;
if ( V_279 < V_280 || V_279 == V_383 )
continue;
if ( V_10 [ V_279 ] == NULL ||
V_10 [ V_279 ] [ type ] . V_13 == NULL )
continue;
if ( V_279 > V_280 ) {
memset ( & V_275 -> args [ 0 ] , 0 , sizeof( V_275 -> args ) ) ;
V_275 -> V_384 = 0 ;
V_275 -> V_184 = 0 ;
}
if ( V_10 [ V_279 ] [ type ] . V_13 ( V_51 , V_275 ) )
break;
}
V_275 -> V_47 = V_279 ;
return V_51 -> V_297 ;
}
struct V_50 * F_186 ( int type , struct V_29 * V_30 ,
unsigned int V_185 , T_6 V_78 )
{
struct V_28 * V_28 = F_140 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
T_4 V_385 ;
V_51 = F_181 ( ( V_385 = F_93 ( V_30 , 0 ) ) , V_78 ) ;
if ( V_51 == NULL )
goto V_322;
V_27 = F_102 ( V_51 , V_30 , type , 0 , 0 , V_185 , 0 , 0 ) ;
if ( V_27 < 0 ) {
F_123 ( V_27 == - V_54 ) ;
F_182 ( V_51 ) ;
goto V_322;
}
return V_51 ;
V_322:
if ( V_27 < 0 )
F_70 ( V_28 , V_386 , V_27 ) ;
return NULL ;
}
void F_187 ( struct V_50 * V_51 , struct V_29 * V_30 , T_6 V_78 )
{
struct V_28 * V_28 = F_140 ( V_30 ) ;
F_67 ( V_51 , V_28 , 0 , V_386 , NULL , V_78 ) ;
}
void F_188 ( int type , struct V_29 * V_30 , unsigned int V_185 ,
T_6 V_78 )
{
struct V_50 * V_51 ;
V_51 = F_186 ( type , V_30 , V_185 , V_78 ) ;
if ( V_51 )
F_187 ( V_51 , V_30 , V_78 ) ;
}
static int F_189 ( struct V_50 * V_51 ,
struct V_29 * V_30 ,
T_9 * V_387 , T_5 V_68 , T_5 V_184 ,
int type , unsigned int V_78 ,
int V_388 )
{
struct V_76 * V_77 ;
struct V_389 * V_390 ;
V_77 = F_104 ( V_51 , V_68 , V_184 , type , sizeof( * V_390 ) , V_388 ) ;
if ( ! V_77 )
return - V_54 ;
V_390 = F_105 ( V_77 ) ;
V_390 -> V_391 = V_392 ;
V_390 -> V_393 = 0 ;
V_390 -> V_394 = 0 ;
V_390 -> V_395 = V_78 ;
V_390 -> V_396 = 0 ;
V_390 -> V_397 = V_30 -> V_196 ;
V_390 -> V_398 = V_399 ;
if ( F_79 ( V_51 , V_400 , V_401 , V_387 ) )
goto V_86;
return F_114 ( V_51 , V_77 ) ;
V_86:
F_115 ( V_51 , V_77 ) ;
return - V_54 ;
}
static inline T_4 F_190 ( void )
{
return F_94 ( sizeof( struct V_389 ) ) + F_45 ( V_401 ) ;
}
static void F_191 ( struct V_29 * V_30 , T_9 * V_387 , int type )
{
struct V_28 * V_28 = F_140 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_16 ;
V_51 = F_181 ( F_190 () , V_402 ) ;
if ( ! V_51 )
goto V_322;
V_27 = F_189 ( V_51 , V_30 , V_387 , 0 , 0 , type , V_403 , 0 ) ;
if ( V_27 < 0 ) {
F_182 ( V_51 ) ;
goto V_322;
}
F_67 ( V_51 , V_28 , 0 , V_404 , NULL , V_402 ) ;
return;
V_322:
F_70 ( V_28 , V_404 , V_27 ) ;
}
int F_192 ( struct V_389 * V_390 ,
struct V_42 * V_283 [] ,
struct V_29 * V_30 ,
const unsigned char * V_387 , T_8 V_405 ,
T_8 V_78 )
{
int V_27 = - V_301 ;
if ( V_390 -> V_398 && ! ( V_390 -> V_398 & V_399 ) ) {
F_193 ( L_6 , V_30 -> V_198 ) ;
return V_27 ;
}
if ( V_405 ) {
F_193 ( L_7 , V_30 -> V_198 ) ;
return V_27 ;
}
if ( F_194 ( V_387 ) || F_195 ( V_387 ) )
V_27 = F_196 ( V_30 , V_387 ) ;
else if ( F_197 ( V_387 ) )
V_27 = F_198 ( V_30 , V_387 ) ;
if ( V_27 == - V_21 && ! ( V_78 & V_369 ) )
V_27 = 0 ;
return V_27 ;
}
static int F_199 ( struct V_42 * V_406 , T_8 * V_407 )
{
T_8 V_405 = 0 ;
if ( V_406 ) {
if ( F_134 ( V_406 ) != sizeof( T_8 ) ) {
F_193 ( L_8 ) ;
return - V_301 ;
}
V_405 = F_200 ( V_406 ) ;
if ( ! V_405 || V_405 >= V_408 ) {
F_193 ( L_9 ,
V_405 ) ;
return - V_301 ;
}
}
* V_407 = V_405 ;
return 0 ;
}
static int F_201 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
struct V_389 * V_390 ;
struct V_42 * V_283 [ V_409 + 1 ] ;
struct V_29 * V_30 ;
T_9 * V_387 ;
T_8 V_405 ;
int V_27 ;
V_27 = F_120 ( V_77 , sizeof( * V_390 ) , V_283 , V_409 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_390 = F_105 ( V_77 ) ;
if ( V_390 -> V_397 == 0 ) {
F_193 ( L_10 ) ;
return - V_301 ;
}
V_30 = F_139 ( V_28 , V_390 -> V_397 ) ;
if ( V_30 == NULL ) {
F_193 ( L_11 ) ;
return - V_331 ;
}
if ( ! V_283 [ V_400 ] || F_134 ( V_283 [ V_400 ] ) != V_401 ) {
F_193 ( L_12 ) ;
return - V_301 ;
}
V_387 = F_113 ( V_283 [ V_400 ] ) ;
V_27 = F_199 ( V_283 [ V_410 ] , & V_405 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_179 ;
if ( ( ! V_390 -> V_395 || V_390 -> V_395 & V_411 ) &&
( V_30 -> V_412 & V_413 ) ) {
struct V_29 * V_414 = F_44 ( V_30 ) ;
const struct V_306 * V_20 = V_414 -> V_161 ;
V_27 = V_20 -> V_415 ( V_390 , V_283 , V_30 , V_387 , V_405 ,
V_77 -> V_368 ) ;
if ( V_27 )
goto V_66;
else
V_390 -> V_395 &= ~ V_411 ;
}
if ( ( V_390 -> V_395 & V_403 ) ) {
if ( V_30 -> V_161 -> V_415 )
V_27 = V_30 -> V_161 -> V_415 ( V_390 , V_283 , V_30 , V_387 ,
V_405 ,
V_77 -> V_368 ) ;
else
V_27 = F_192 ( V_390 , V_283 , V_30 , V_387 , V_405 ,
V_77 -> V_368 ) ;
if ( ! V_27 ) {
F_191 ( V_30 , V_387 , V_416 ) ;
V_390 -> V_395 &= ~ V_403 ;
}
}
V_66:
return V_27 ;
}
int F_202 ( struct V_389 * V_390 ,
struct V_42 * V_283 [] ,
struct V_29 * V_30 ,
const unsigned char * V_387 , T_8 V_405 )
{
int V_27 = - V_301 ;
if ( ! ( V_390 -> V_398 & V_399 ) ) {
F_193 ( L_6 , V_30 -> V_198 ) ;
return V_27 ;
}
if ( F_194 ( V_387 ) || F_195 ( V_387 ) )
V_27 = F_203 ( V_30 , V_387 ) ;
else if ( F_197 ( V_387 ) )
V_27 = F_204 ( V_30 , V_387 ) ;
return V_27 ;
}
static int F_205 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
struct V_389 * V_390 ;
struct V_42 * V_283 [ V_409 + 1 ] ;
struct V_29 * V_30 ;
int V_27 = - V_301 ;
T_10 * V_387 ;
T_8 V_405 ;
if ( ! F_206 ( V_51 , V_324 ) )
return - V_325 ;
V_27 = F_120 ( V_77 , sizeof( * V_390 ) , V_283 , V_409 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_390 = F_105 ( V_77 ) ;
if ( V_390 -> V_397 == 0 ) {
F_193 ( L_13 ) ;
return - V_301 ;
}
V_30 = F_139 ( V_28 , V_390 -> V_397 ) ;
if ( V_30 == NULL ) {
F_193 ( L_14 ) ;
return - V_331 ;
}
if ( ! V_283 [ V_400 ] || F_134 ( V_283 [ V_400 ] ) != V_401 ) {
F_193 ( L_15 ) ;
return - V_301 ;
}
V_387 = F_113 ( V_283 [ V_400 ] ) ;
V_27 = F_199 ( V_283 [ V_410 ] , & V_405 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_179 ;
if ( ( ! V_390 -> V_395 || V_390 -> V_395 & V_411 ) &&
( V_30 -> V_412 & V_413 ) ) {
struct V_29 * V_414 = F_44 ( V_30 ) ;
const struct V_306 * V_20 = V_414 -> V_161 ;
if ( V_20 -> V_417 )
V_27 = V_20 -> V_417 ( V_390 , V_283 , V_30 , V_387 , V_405 ) ;
if ( V_27 )
goto V_66;
else
V_390 -> V_395 &= ~ V_411 ;
}
if ( V_390 -> V_395 & V_403 ) {
if ( V_30 -> V_161 -> V_417 )
V_27 = V_30 -> V_161 -> V_417 ( V_390 , V_283 , V_30 , V_387 ,
V_405 ) ;
else
V_27 = F_202 ( V_390 , V_283 , V_30 , V_387 , V_405 ) ;
if ( ! V_27 ) {
F_191 ( V_30 , V_387 , V_418 ) ;
V_390 -> V_395 &= ~ V_403 ;
}
}
V_66:
return V_27 ;
}
static int F_207 ( struct V_50 * V_51 ,
struct V_274 * V_275 ,
struct V_29 * V_30 ,
int * V_279 ,
struct V_419 * V_25 )
{
struct V_420 * V_421 ;
int V_27 ;
T_5 V_294 , V_184 ;
V_294 = F_61 ( V_275 -> V_51 ) . V_294 ;
V_184 = V_275 -> V_77 -> V_295 ;
F_26 (ha, &list->list, list) {
if ( * V_279 < V_275 -> args [ 0 ] )
goto V_422;
V_27 = F_189 ( V_51 , V_30 , V_421 -> V_387 ,
V_294 , V_184 ,
V_416 , V_403 ,
V_296 ) ;
if ( V_27 < 0 )
return V_27 ;
V_422:
* V_279 += 1 ;
}
return 0 ;
}
int F_208 ( struct V_50 * V_51 ,
struct V_274 * V_275 ,
struct V_29 * V_30 ,
struct V_29 * V_423 ,
int V_279 )
{
int V_27 ;
F_209 ( V_30 ) ;
V_27 = F_207 ( V_51 , V_275 , V_30 , & V_279 , & V_30 -> V_424 ) ;
if ( V_27 )
goto V_66;
F_207 ( V_51 , V_275 , V_30 , & V_279 , & V_30 -> V_425 ) ;
V_66:
F_210 ( V_30 ) ;
return V_279 ;
}
static int F_211 ( struct V_50 * V_51 , struct V_274 * V_275 )
{
struct V_29 * V_30 ;
struct V_42 * V_283 [ V_284 + 1 ] ;
struct V_29 * V_426 = NULL ;
struct V_29 * V_414 = NULL ;
const struct V_306 * V_20 = NULL ;
const struct V_306 * V_427 = NULL ;
struct V_113 * V_114 = F_105 ( V_275 -> V_77 ) ;
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
int V_428 = 0 ;
int V_429 = 0 ;
int V_279 = 0 ;
if ( F_120 ( V_275 -> V_77 , sizeof( struct V_113 ) , V_283 , V_284 ,
V_288 ) == 0 ) {
if ( V_283 [ V_216 ] )
V_429 = F_121 ( V_283 [ V_216 ] ) ;
}
V_428 = V_114 -> V_195 ;
if ( V_429 ) {
V_414 = F_139 ( V_28 , V_429 ) ;
if ( ! V_414 )
return - V_331 ;
V_20 = V_414 -> V_161 ;
V_426 = V_414 ;
}
F_32 (net, dev) {
if ( V_428 && ( V_30 -> V_196 != V_428 ) )
continue;
if ( ! V_429 ) {
if ( V_30 -> V_412 & V_413 ) {
V_414 = F_44 ( V_30 ) ;
V_427 = V_414 -> V_161 ;
}
V_426 = V_30 ;
} else {
if ( V_30 != V_414 &&
! ( V_30 -> V_412 & V_413 ) )
continue;
if ( V_414 != F_44 ( V_30 ) &&
! ( V_30 -> V_412 & V_430 ) )
continue;
V_426 = V_414 ;
V_427 = V_20 ;
}
if ( V_30 -> V_412 & V_413 ) {
if ( V_427 && V_427 -> V_431 )
V_279 = V_427 -> V_431 ( V_51 , V_275 , V_414 , V_30 ,
V_279 ) ;
}
V_279 = F_208 ( V_51 , V_275 , V_30 , NULL , V_279 ) ;
if ( V_30 -> V_161 -> V_431 )
V_279 = V_30 -> V_161 -> V_431 ( V_51 , V_275 , V_426 , V_30 ,
V_279 ) ;
V_427 = NULL ;
}
V_275 -> args [ 0 ] = V_279 ;
return V_51 -> V_297 ;
}
static int F_212 ( struct V_50 * V_51 , T_5 V_78 , T_5 V_432 ,
unsigned int V_433 , unsigned int V_434 )
{
if ( V_432 & V_434 )
return F_107 ( V_51 , V_433 , ! ! ( V_78 & V_434 ) ) ;
return 0 ;
}
int F_213 ( struct V_50 * V_51 , T_5 V_68 , T_5 V_184 ,
struct V_29 * V_30 , T_8 V_435 ,
T_5 V_78 , T_5 V_432 )
{
struct V_76 * V_77 ;
struct V_113 * V_114 ;
struct V_42 * V_436 ;
struct V_42 * V_437 ;
T_9 V_105 = F_108 ( V_30 ) ? V_30 -> V_105 : V_202 ;
struct V_29 * V_414 = F_44 ( V_30 ) ;
V_77 = F_104 ( V_51 , V_68 , V_184 , V_293 , sizeof( * V_114 ) , V_296 ) ;
if ( V_77 == NULL )
return - V_54 ;
V_114 = F_105 ( V_77 ) ;
V_114 -> V_191 = V_392 ;
V_114 -> V_193 = 0 ;
V_114 -> V_194 = V_30 -> type ;
V_114 -> V_195 = V_30 -> V_196 ;
V_114 -> V_115 = F_106 ( V_30 ) ;
V_114 -> V_116 = 0 ;
if ( F_54 ( V_51 , V_197 , V_30 -> V_198 ) ||
F_73 ( V_51 , V_205 , V_30 -> V_206 ) ||
F_107 ( V_51 , V_201 , V_105 ) ||
( V_414 &&
F_73 ( V_51 , V_216 , V_414 -> V_196 ) ) ||
( V_30 -> V_233 &&
F_79 ( V_51 , V_234 , V_30 -> V_233 , V_30 -> V_235 ) ) ||
( V_30 -> V_196 != V_30 -> V_214 &&
F_73 ( V_51 , V_215 , V_30 -> V_214 ) ) )
goto V_86;
V_436 = F_55 ( V_51 , V_270 ) ;
if ( ! V_436 )
goto V_86;
if ( F_214 ( V_51 , V_438 , V_439 ) ) {
F_57 ( V_51 , V_436 ) ;
goto V_86;
}
if ( V_435 != V_440 ) {
if ( F_214 ( V_51 , V_441 , V_435 ) ) {
F_57 ( V_51 , V_436 ) ;
goto V_86;
}
}
F_56 ( V_51 , V_436 ) ;
V_437 = F_55 ( V_51 , V_374 | V_442 ) ;
if ( ! V_437 )
goto V_86;
if ( F_212 ( V_51 , V_78 , V_432 ,
V_443 , V_444 ) ||
F_212 ( V_51 , V_78 , V_432 ,
V_445 , V_446 ) ||
F_212 ( V_51 , V_78 , V_432 ,
V_447 ,
V_448 ) ||
F_212 ( V_51 , V_78 , V_432 ,
V_449 , V_450 ) ||
F_212 ( V_51 , V_78 , V_432 ,
V_451 , V_452 ) ||
F_212 ( V_51 , V_78 , V_432 ,
V_453 , V_454 ) ||
F_212 ( V_51 , V_78 , V_432 ,
V_455 , V_456 ) ||
F_212 ( V_51 , V_78 , V_432 ,
V_457 , V_458 ) ) {
F_57 ( V_51 , V_437 ) ;
goto V_86;
}
F_56 ( V_51 , V_437 ) ;
return F_114 ( V_51 , V_77 ) ;
V_86:
F_115 ( V_51 , V_77 ) ;
return - V_54 ;
}
static int F_215 ( struct V_50 * V_51 , struct V_274 * V_275 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
struct V_29 * V_30 ;
int V_279 = 0 ;
T_5 V_294 = F_61 ( V_275 -> V_51 ) . V_294 ;
T_5 V_184 = V_275 -> V_77 -> V_295 ;
T_5 V_459 = 0 ;
if ( F_119 ( V_275 -> V_77 ) > sizeof( struct V_113 ) ) {
struct V_42 * V_460 ;
V_460 = F_216 ( V_275 -> V_77 , sizeof( struct V_113 ) ,
V_289 ) ;
if ( V_460 ) {
if ( F_134 ( V_460 ) < sizeof( V_459 ) )
return - V_301 ;
V_459 = F_121 ( V_460 ) ;
}
}
F_118 () ;
F_217 (net, dev) {
const struct V_306 * V_20 = V_30 -> V_161 ;
struct V_29 * V_414 = F_44 ( V_30 ) ;
if ( V_414 && V_414 -> V_161 -> V_461 ) {
if ( V_279 >= V_275 -> args [ 0 ] &&
V_414 -> V_161 -> V_461 (
V_51 , V_294 , V_184 , V_30 , V_459 ) < 0 )
break;
V_279 ++ ;
}
if ( V_20 -> V_461 ) {
if ( V_279 >= V_275 -> args [ 0 ] &&
V_20 -> V_461 ( V_51 , V_294 , V_184 , V_30 ,
V_459 ) < 0 )
break;
V_279 ++ ;
}
}
F_126 () ;
V_275 -> args [ 0 ] = V_279 ;
return V_51 -> V_297 ;
}
static inline T_4 F_218 ( void )
{
return F_94 ( sizeof( struct V_113 ) )
+ F_45 ( V_163 )
+ F_45 ( V_166 )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_9 ) )
+ F_45 ( sizeof( struct V_42 ) )
+ F_45 ( sizeof( T_8 ) )
+ F_45 ( sizeof( T_8 ) ) ;
}
static int F_219 ( struct V_29 * V_30 , T_8 V_78 )
{
struct V_28 * V_28 = F_140 ( V_30 ) ;
struct V_29 * V_414 = F_44 ( V_30 ) ;
struct V_50 * V_51 ;
int V_27 = - V_179 ;
V_51 = F_181 ( F_218 () , V_402 ) ;
if ( ! V_51 ) {
V_27 = - V_336 ;
goto V_322;
}
if ( ( ! V_78 || ( V_78 & V_462 ) ) &&
V_414 && V_414 -> V_161 -> V_461 ) {
V_27 = V_414 -> V_161 -> V_461 ( V_51 , 0 , 0 , V_30 , 0 ) ;
if ( V_27 < 0 )
goto V_322;
}
if ( ( V_78 & V_439 ) &&
V_30 -> V_161 -> V_461 ) {
V_27 = V_30 -> V_161 -> V_461 ( V_51 , 0 , 0 , V_30 , 0 ) ;
if ( V_27 < 0 )
goto V_322;
}
if ( ! V_51 -> V_297 )
goto V_322;
F_67 ( V_51 , V_28 , 0 , V_386 , NULL , V_402 ) ;
return 0 ;
V_322:
F_123 ( V_27 == - V_54 ) ;
F_182 ( V_51 ) ;
if ( V_27 )
F_70 ( V_28 , V_386 , V_27 ) ;
return V_27 ;
}
static int F_220 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
struct V_113 * V_114 ;
struct V_29 * V_30 ;
struct V_42 * V_463 , * V_188 = NULL ;
int V_302 , V_27 = - V_179 ;
T_8 V_464 , V_78 = 0 ;
bool V_465 = false ;
if ( F_119 ( V_77 ) < sizeof( * V_114 ) )
return - V_301 ;
V_114 = F_105 ( V_77 ) ;
if ( V_114 -> V_191 != V_392 )
return - V_466 ;
V_30 = F_139 ( V_28 , V_114 -> V_195 ) ;
if ( ! V_30 ) {
F_193 ( L_16 ) ;
return - V_331 ;
}
V_463 = F_216 ( V_77 , sizeof( struct V_113 ) , V_270 ) ;
if ( V_463 ) {
F_135 (attr, br_spec, rem) {
if ( F_136 ( V_188 ) == V_438 ) {
if ( F_134 ( V_188 ) < sizeof( V_78 ) )
return - V_301 ;
V_465 = true ;
V_78 = F_200 ( V_188 ) ;
break;
}
}
}
V_464 = V_78 ;
if ( ! V_78 || ( V_78 & V_462 ) ) {
struct V_29 * V_414 = F_44 ( V_30 ) ;
if ( ! V_414 || ! V_414 -> V_161 -> V_467 ) {
V_27 = - V_179 ;
goto V_66;
}
V_27 = V_414 -> V_161 -> V_467 ( V_30 , V_77 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_462 ;
}
if ( ( V_78 & V_439 ) ) {
if ( ! V_30 -> V_161 -> V_467 )
V_27 = - V_179 ;
else
V_27 = V_30 -> V_161 -> V_467 ( V_30 , V_77 ) ;
if ( ! V_27 )
V_78 &= ~ V_439 ;
}
if ( V_465 )
memcpy ( F_113 ( V_188 ) , & V_78 , sizeof( V_78 ) ) ;
if ( ! V_27 )
V_27 = F_219 ( V_30 , V_464 ) ;
V_66:
return V_27 ;
}
static int F_221 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
struct V_113 * V_114 ;
struct V_29 * V_30 ;
struct V_42 * V_463 , * V_188 = NULL ;
int V_302 , V_27 = - V_179 ;
T_8 V_464 , V_78 = 0 ;
bool V_465 = false ;
if ( F_119 ( V_77 ) < sizeof( * V_114 ) )
return - V_301 ;
V_114 = F_105 ( V_77 ) ;
if ( V_114 -> V_191 != V_392 )
return - V_466 ;
V_30 = F_139 ( V_28 , V_114 -> V_195 ) ;
if ( ! V_30 ) {
F_193 ( L_16 ) ;
return - V_331 ;
}
V_463 = F_216 ( V_77 , sizeof( struct V_113 ) , V_270 ) ;
if ( V_463 ) {
F_135 (attr, br_spec, rem) {
if ( F_136 ( V_188 ) == V_438 ) {
if ( F_134 ( V_188 ) < sizeof( V_78 ) )
return - V_301 ;
V_465 = true ;
V_78 = F_200 ( V_188 ) ;
break;
}
}
}
V_464 = V_78 ;
if ( ! V_78 || ( V_78 & V_462 ) ) {
struct V_29 * V_414 = F_44 ( V_30 ) ;
if ( ! V_414 || ! V_414 -> V_161 -> V_468 ) {
V_27 = - V_179 ;
goto V_66;
}
V_27 = V_414 -> V_161 -> V_468 ( V_30 , V_77 ) ;
if ( V_27 )
goto V_66;
V_78 &= ~ V_462 ;
}
if ( ( V_78 & V_439 ) ) {
if ( ! V_30 -> V_161 -> V_468 )
V_27 = - V_179 ;
else
V_27 = V_30 -> V_161 -> V_468 ( V_30 , V_77 ) ;
if ( ! V_27 )
V_78 &= ~ V_439 ;
}
if ( V_465 )
memcpy ( F_113 ( V_188 ) , & V_78 , sizeof( V_78 ) ) ;
if ( ! V_27 )
V_27 = F_219 ( V_30 , V_464 ) ;
V_66:
return V_27 ;
}
static int F_222 ( struct V_50 * V_51 , struct V_76 * V_77 )
{
struct V_28 * V_28 = F_117 ( V_51 -> V_276 ) ;
T_1 V_11 ;
int V_469 , V_19 ;
int V_47 ;
int type ;
int V_27 ;
type = V_77 -> V_382 ;
if ( type > V_470 )
return - V_179 ;
type -= V_4 ;
if ( F_119 ( V_77 ) < sizeof( struct V_287 ) )
return 0 ;
V_47 = ( (struct V_287 * ) F_105 ( V_77 ) ) -> V_471 ;
V_469 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_223 ( V_51 , V_324 ) )
return - V_325 ;
if ( V_19 == 2 && V_77 -> V_368 & V_472 ) {
struct V_71 * V_72 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_473 = 0 ;
V_13 = F_16 ( V_47 , type ) ;
if ( V_13 == NULL )
return - V_179 ;
V_14 = F_17 ( V_47 , type ) ;
if ( V_14 )
V_473 = V_14 ( V_51 , V_77 ) ;
F_3 () ;
V_72 = V_28 -> V_72 ;
{
struct V_474 V_475 = {
. V_476 = V_13 ,
. V_473 = V_473 ,
} ;
V_27 = F_224 ( V_72 , V_51 , V_77 , & V_475 ) ;
}
F_1 () ;
return V_27 ;
}
V_11 = F_15 ( V_47 , type ) ;
if ( V_11 == NULL )
return - V_179 ;
return V_11 ( V_51 , V_77 ) ;
}
static void F_225 ( struct V_50 * V_51 )
{
F_1 () ;
F_226 ( V_51 , & F_222 ) ;
F_5 () ;
}
static int F_227 ( struct V_477 * V_478 , unsigned long V_479 , void * V_480 )
{
struct V_29 * V_30 = F_228 ( V_480 ) ;
switch ( V_479 ) {
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_488 :
case V_489 :
case V_490 :
case V_491 :
case V_492 :
break;
default:
F_188 ( V_293 , V_30 , 0 , V_15 ) ;
break;
}
return V_493 ;
}
static int T_11 F_229 ( struct V_28 * V_28 )
{
struct V_71 * V_276 ;
struct V_494 V_495 = {
. V_496 = V_497 ,
. V_498 = F_225 ,
. V_499 = & V_1 ,
. V_78 = V_500 ,
} ;
V_276 = F_230 ( V_28 , V_501 , & V_495 ) ;
if ( ! V_276 )
return - V_336 ;
V_28 -> V_72 = V_276 ;
return 0 ;
}
static void T_12 F_231 ( struct V_28 * V_28 )
{
F_232 ( V_28 -> V_72 ) ;
V_28 -> V_72 = NULL ;
}
void T_13 F_233 ( void )
{
if ( F_234 ( & V_502 ) )
F_21 ( L_17 ) ;
F_235 ( & V_503 ) ;
F_20 ( V_12 , V_504 , F_180 ,
F_116 , F_183 ) ;
F_20 ( V_12 , V_505 , F_162 , NULL , NULL ) ;
F_20 ( V_12 , V_293 , F_174 , NULL , NULL ) ;
F_20 ( V_12 , V_506 , F_165 , NULL , NULL ) ;
F_20 ( V_12 , V_507 , NULL , F_185 , NULL ) ;
F_20 ( V_12 , V_508 , NULL , F_185 , NULL ) ;
F_20 ( V_509 , V_416 , F_201 , NULL , NULL ) ;
F_20 ( V_509 , V_418 , F_205 , NULL , NULL ) ;
F_20 ( V_509 , V_510 , NULL , F_211 , NULL ) ;
F_20 ( V_509 , V_504 , NULL , F_215 , NULL ) ;
F_20 ( V_509 , V_506 , F_221 , NULL , NULL ) ;
F_20 ( V_509 , V_505 , F_220 , NULL , NULL ) ;
}
