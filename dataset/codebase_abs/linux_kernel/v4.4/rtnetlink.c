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
}
static void F_90 ( void * V_153 , const struct V_128 * V_129 )
{
memcpy ( V_153 , V_129 , sizeof( * V_129 ) ) ;
}
static inline int F_91 ( const struct V_29 * V_30 ,
T_5 V_48 )
{
if ( V_30 -> V_30 . V_154 && F_92 ( V_30 -> V_30 . V_154 ) &&
( V_48 & V_155 ) ) {
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
F_45 ( sizeof( V_163 ) ) +
F_45 ( sizeof( struct V_164 ) ) ) ;
return V_43 ;
} else
return 0 ;
}
static T_4 F_94 ( const struct V_29 * V_30 ,
T_5 V_48 )
{
T_4 V_165 = F_45 ( 4 )
+ F_45 ( V_166 )
+ F_45 ( sizeof( struct V_167 ) )
+ F_45 ( V_168 )
+ F_45 ( V_168 )
+ F_45 ( 1 )
+ F_45 ( 2 ) ;
T_4 V_169 = F_45 ( sizeof( struct V_42 ) ) ;
T_4 V_170 = F_45 ( sizeof( struct V_42 ) )
+ V_165 ;
T_4 V_171 = F_45 ( sizeof( struct V_42 ) )
+ V_165 ;
if ( ! V_30 -> V_172 -> V_173 || ! V_30 -> V_30 . V_154 ||
! ( V_48 & V_155 ) )
return 0 ;
if ( F_93 ( V_30 -> V_30 . V_154 ) )
return V_171 + V_169 +
V_170 * F_93 ( V_30 -> V_30 . V_154 ) ;
else
return V_171 ;
}
static T_7 T_4 F_95 ( const struct V_29 * V_30 ,
T_5 V_48 )
{
return F_96 ( sizeof( struct V_122 ) )
+ F_45 ( V_174 )
+ F_45 ( V_175 )
+ F_45 ( V_174 )
+ F_45 ( sizeof( struct V_176 ) )
+ F_45 ( sizeof( struct V_126 ) )
+ F_45 ( sizeof( struct V_128 ) )
+ F_45 ( V_177 )
+ F_45 ( V_177 )
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
+ F_45 ( V_48
& V_155 ? 4 : 0 )
+ F_91 ( V_30 , V_48 )
+ F_94 ( V_30 , V_48 )
+ F_46 ( V_30 )
+ F_51 ( V_30 , V_48 )
+ F_45 ( V_178 )
+ F_45 ( V_178 )
+ F_45 ( 1 ) ;
}
static int F_97 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
struct V_42 * V_179 ;
struct V_42 * V_180 ;
int V_181 ;
int V_27 ;
V_179 = F_55 ( V_52 , V_182 ) ;
if ( ! V_179 )
return - V_55 ;
for ( V_181 = 0 ; V_181 < F_93 ( V_30 -> V_30 . V_154 ) ; V_181 ++ ) {
V_180 = F_55 ( V_52 , V_183 ) ;
if ( ! V_180 )
goto V_91;
if ( F_75 ( V_52 , V_184 , V_181 ) )
goto V_91;
V_27 = V_30 -> V_172 -> V_173 ( V_30 , V_181 , V_52 ) ;
if ( V_27 == - V_55 )
goto V_91;
if ( V_27 ) {
F_57 ( V_52 , V_180 ) ;
continue;
}
F_56 ( V_52 , V_180 ) ;
}
F_56 ( V_52 , V_179 ) ;
return 0 ;
V_91:
F_57 ( V_52 , V_179 ) ;
return - V_55 ;
}
static int F_98 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
struct V_42 * V_185 ;
int V_27 ;
V_185 = F_55 ( V_52 , V_186 ) ;
if ( ! V_185 )
return - V_55 ;
V_27 = V_30 -> V_172 -> V_173 ( V_30 , V_187 , V_52 ) ;
if ( V_27 ) {
F_57 ( V_52 , V_185 ) ;
return ( V_27 == - V_55 ) ? V_27 : 0 ;
}
F_56 ( V_52 , V_185 ) ;
return 0 ;
}
static int F_99 ( struct V_51 * V_52 , struct V_29 * V_30 ,
T_5 V_48 )
{
int V_27 ;
if ( ! V_30 -> V_172 -> V_173 || ! V_30 -> V_30 . V_154 ||
! ( V_48 & V_155 ) )
return 0 ;
V_27 = F_98 ( V_52 , V_30 ) ;
if ( V_27 )
return V_27 ;
if ( F_93 ( V_30 -> V_30 . V_154 ) ) {
V_27 = F_97 ( V_52 , V_30 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_100 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
int V_27 ;
struct V_188 V_189 ;
V_27 = F_101 ( V_30 , & V_189 ) ;
if ( V_27 ) {
if ( V_27 == - V_190 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_52 , V_191 , V_189 . V_192 , V_189 . V_98 ) )
return - V_55 ;
return 0 ;
}
static int F_102 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
char V_90 [ V_174 ] ;
int V_27 ;
V_27 = F_103 ( V_30 , V_90 , sizeof( V_90 ) ) ;
if ( V_27 ) {
if ( V_27 == - V_190 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_52 , V_193 , strlen ( V_90 ) , V_90 ) )
return - V_55 ;
return 0 ;
}
static int F_104 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
int V_27 ;
struct V_194 V_195 = {
. V_98 = V_196 ,
. V_79 = V_197 ,
} ;
V_27 = F_105 ( V_30 , & V_195 ) ;
if ( V_27 ) {
if ( V_27 == - V_190 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_52 , V_198 , V_195 . V_199 . V_189 . V_192 ,
V_195 . V_199 . V_189 . V_98 ) )
return - V_55 ;
return 0 ;
}
static T_8 int F_106 ( struct V_51 * V_52 ,
struct V_29 * V_30 )
{
const struct V_128 * V_200 ;
struct V_128 V_201 ;
struct V_42 * V_195 ;
V_200 = F_107 ( V_30 , & V_201 ) ;
V_195 = F_108 ( V_52 , V_202 ,
sizeof( struct V_126 ) ) ;
if ( ! V_195 )
return - V_55 ;
F_89 ( F_109 ( V_195 ) , V_200 ) ;
V_195 = F_108 ( V_52 , V_203 ,
sizeof( struct V_128 ) ) ;
if ( ! V_195 )
return - V_55 ;
F_90 ( F_109 ( V_195 ) , V_200 ) ;
return 0 ;
}
static T_8 int F_110 ( struct V_51 * V_52 ,
struct V_29 * V_30 ,
int V_204 ,
struct V_42 * V_205 )
{
struct V_162 V_206 ;
struct V_161 V_207 ;
struct V_159 V_208 ;
struct V_209 V_210 ;
struct V_211 V_212 ;
struct V_164 V_213 ;
struct V_158 V_214 ;
struct V_160 V_215 ;
struct V_42 * V_181 , * V_216 ;
struct V_157 V_217 ;
struct V_218 V_219 ;
V_219 . V_220 = - 1 ;
V_219 . V_221 = - 1 ;
V_219 . V_222 = - 1 ;
memset ( V_219 . V_223 , 0 , sizeof( V_219 . V_223 ) ) ;
V_219 . V_224 = 0 ;
if ( V_30 -> V_172 -> V_225 ( V_30 , V_204 , & V_219 ) )
return 0 ;
V_217 . V_181 =
V_214 . V_181 =
V_215 . V_181 =
V_210 . V_181 =
V_208 . V_181 =
V_207 . V_181 =
V_206 . V_181 =
V_213 . V_181 = V_219 . V_181 ;
memcpy ( V_217 . V_223 , V_219 . V_223 , sizeof( V_219 . V_223 ) ) ;
V_214 . V_226 = V_219 . V_226 ;
V_214 . V_227 = V_219 . V_227 ;
V_210 . V_228 = V_219 . V_229 ;
V_215 . V_230 = V_219 . V_230 ;
V_215 . V_229 = V_219 . V_229 ;
V_208 . V_231 = V_219 . V_220 ;
V_207 . V_232 = V_219 . V_224 ;
V_206 . V_231 = V_219 . V_221 ;
V_213 . V_231 = V_219 . V_222 ;
V_181 = F_55 ( V_52 , V_233 ) ;
if ( ! V_181 ) {
F_57 ( V_52 , V_205 ) ;
return - V_55 ;
}
if ( F_81 ( V_52 , V_234 , sizeof( V_217 ) , & V_217 ) ||
F_81 ( V_52 , V_235 , sizeof( V_214 ) , & V_214 ) ||
F_81 ( V_52 , V_236 , sizeof( V_215 ) ,
& V_215 ) ||
F_81 ( V_52 , V_237 , sizeof( V_210 ) ,
& V_210 ) ||
F_81 ( V_52 , V_238 , sizeof( V_208 ) ,
& V_208 ) ||
F_81 ( V_52 , V_239 , sizeof( V_207 ) ,
& V_207 ) ||
F_81 ( V_52 , V_240 ,
sizeof( V_206 ) ,
& V_206 ) ||
F_81 ( V_52 , V_241 ,
sizeof( V_213 ) , & V_213 ) )
return - V_55 ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
if ( V_30 -> V_172 -> V_242 )
V_30 -> V_172 -> V_242 ( V_30 , V_204 ,
& V_212 ) ;
V_216 = F_55 ( V_52 , V_243 ) ;
if ( ! V_216 ) {
F_57 ( V_52 , V_181 ) ;
F_57 ( V_52 , V_205 ) ;
return - V_55 ;
}
if ( F_111 ( V_52 , V_244 ,
V_212 . V_130 ) ||
F_111 ( V_52 , V_245 ,
V_212 . V_131 ) ||
F_111 ( V_52 , V_246 ,
V_212 . V_132 ) ||
F_111 ( V_52 , V_247 ,
V_212 . V_133 ) ||
F_111 ( V_52 , V_248 ,
V_212 . V_249 ) ||
F_111 ( V_52 , V_250 ,
V_212 . V_138 ) )
return - V_55 ;
F_56 ( V_52 , V_216 ) ;
F_56 ( V_52 , V_181 ) ;
return 0 ;
}
static int F_112 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
struct V_176 V_251 = {
. V_252 = V_30 -> V_252 ,
. V_253 = V_30 -> V_253 ,
. V_254 = V_30 -> V_254 ,
. V_255 = V_30 -> V_255 ,
. V_256 = V_30 -> V_256 ,
. V_257 = V_30 -> V_258 ,
} ;
if ( F_81 ( V_52 , V_259 , sizeof( V_251 ) , & V_251 ) )
return - V_55 ;
return 0 ;
}
static int F_113 ( struct V_51 * V_52 , struct V_29 * V_30 ,
int type , T_5 V_69 , T_5 V_260 , T_5 V_261 ,
unsigned int V_79 , T_5 V_48 )
{
struct V_122 * V_123 ;
struct V_77 * V_78 ;
struct V_42 * V_262 ;
struct V_46 * V_49 ;
struct V_29 * V_263 = F_44 ( V_30 ) ;
F_114 () ;
V_78 = F_115 ( V_52 , V_69 , V_260 , type , sizeof( * V_123 ) , V_79 ) ;
if ( V_78 == NULL )
return - V_55 ;
V_123 = F_116 ( V_78 ) ;
V_123 -> V_264 = V_265 ;
V_123 -> V_266 = 0 ;
V_123 -> V_267 = V_30 -> type ;
V_123 -> V_268 = V_30 -> V_269 ;
V_123 -> V_124 = F_117 ( V_30 ) ;
V_123 -> V_125 = V_261 ;
if ( F_54 ( V_52 , V_270 , V_30 -> V_90 ) ||
F_75 ( V_52 , V_271 , V_30 -> V_272 ) ||
F_118 ( V_52 , V_273 ,
F_119 ( V_30 ) ? V_30 -> V_114 : V_274 ) ||
F_118 ( V_52 , V_275 , V_30 -> V_276 ) ||
F_75 ( V_52 , V_277 , V_30 -> V_278 ) ||
F_75 ( V_52 , V_279 , V_30 -> V_70 ) ||
F_75 ( V_52 , V_280 , V_30 -> V_281 ) ||
F_75 ( V_52 , V_282 , V_30 -> V_283 ) ||
#ifdef F_120
F_75 ( V_52 , V_284 , V_30 -> V_285 ) ||
#endif
( V_30 -> V_269 != F_121 ( V_30 ) &&
F_75 ( V_52 , V_286 , F_121 ( V_30 ) ) ) ||
( V_263 &&
F_75 ( V_52 , V_287 , V_263 -> V_269 ) ) ||
F_118 ( V_52 , V_288 , F_122 ( V_30 ) ) ||
( V_30 -> V_289 &&
F_54 ( V_52 , V_290 , V_30 -> V_289 -> V_20 -> V_98 ) ) ||
( V_30 -> V_291 &&
F_54 ( V_52 , V_292 , V_30 -> V_291 ) ) ||
F_75 ( V_52 , V_293 ,
F_78 ( & V_30 -> V_294 ) ) ||
F_118 ( V_52 , V_295 , V_30 -> V_296 ) )
goto V_91;
if ( F_112 ( V_52 , V_30 ) )
goto V_91;
if ( V_30 -> V_297 ) {
if ( F_81 ( V_52 , V_298 , V_30 -> V_297 , V_30 -> V_299 ) ||
F_81 ( V_52 , V_300 , V_30 -> V_297 , V_30 -> V_249 ) )
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
if ( V_30 -> V_30 . V_154 && ( V_48 & V_155 ) &&
F_75 ( V_52 , V_301 , F_93 ( V_30 -> V_30 . V_154 ) ) )
goto V_91;
if ( V_30 -> V_172 -> V_225 && V_30 -> V_30 . V_154 &&
V_48 & V_155 ) {
int V_83 ;
struct V_42 * V_205 ;
int V_156 = F_93 ( V_30 -> V_30 . V_154 ) ;
V_205 = F_55 ( V_52 , V_302 ) ;
if ( ! V_205 )
goto V_91;
for ( V_83 = 0 ; V_83 < V_156 ; V_83 ++ ) {
if ( F_110 ( V_52 , V_30 , V_83 , V_205 ) )
goto V_91;
}
F_56 ( V_52 , V_205 ) ;
}
if ( F_99 ( V_52 , V_30 , V_48 ) )
goto V_91;
if ( V_30 -> V_18 || F_52 ( V_30 ) ) {
if ( F_59 ( V_52 , V_30 ) < 0 )
goto V_91;
}
if ( V_30 -> V_18 &&
V_30 -> V_18 -> V_303 ) {
struct V_28 * V_304 = V_30 -> V_18 -> V_303 ( V_30 ) ;
if ( ! F_123 ( F_124 ( V_30 ) , V_304 ) ) {
int V_98 = F_125 ( F_124 ( V_30 ) , V_304 ) ;
if ( F_126 ( V_52 , V_305 , V_98 ) )
goto V_91;
}
}
if ( ! ( V_262 = F_55 ( V_52 , V_306 ) ) )
goto V_91;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_49 -> V_307 ) {
struct V_42 * V_308 ;
int V_27 ;
if ( ! ( V_308 = F_55 ( V_52 , V_49 -> V_47 ) ) )
goto V_91;
V_27 = V_49 -> V_307 ( V_52 , V_30 , V_48 ) ;
if ( V_27 == - V_309 )
F_57 ( V_52 , V_308 ) ;
else if ( V_27 < 0 )
goto V_91;
F_56 ( V_52 , V_308 ) ;
}
}
F_56 ( V_52 , V_262 ) ;
F_127 ( V_52 , V_78 ) ;
return 0 ;
V_91:
F_128 ( V_52 , V_78 ) ;
return - V_55 ;
}
static int F_129 ( struct V_51 * V_52 , struct V_310 * V_311 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
int V_313 , V_314 ;
int V_315 = 0 , V_316 ;
struct V_29 * V_30 ;
struct V_317 * V_318 ;
struct V_42 * V_319 [ V_320 + 1 ] ;
T_5 V_48 = 0 ;
int V_27 ;
int V_321 ;
V_314 = V_311 -> args [ 0 ] ;
V_316 = V_311 -> args [ 1 ] ;
V_311 -> V_260 = V_28 -> V_322 ;
V_321 = F_131 ( V_311 -> V_78 ) < sizeof( struct V_122 ) ?
sizeof( struct V_323 ) : sizeof( struct V_122 ) ;
if ( F_132 ( V_311 -> V_78 , V_321 , V_319 , V_320 , V_324 ) >= 0 ) {
if ( V_319 [ V_325 ] )
V_48 = F_133 ( V_319 [ V_325 ] ) ;
}
for ( V_313 = V_314 ; V_313 < V_326 ; V_313 ++ , V_316 = 0 ) {
V_315 = 0 ;
V_318 = & V_28 -> V_327 [ V_313 ] ;
F_134 (dev, head, index_hlist) {
if ( V_315 < V_316 )
goto V_328;
V_27 = F_113 ( V_52 , V_30 , V_329 ,
F_61 ( V_311 -> V_52 ) . V_330 ,
V_311 -> V_78 -> V_331 , 0 ,
V_332 ,
V_48 ) ;
F_135 ( ( V_27 == - V_55 ) && ( V_52 -> V_333 == 0 ) ) ;
if ( V_27 < 0 )
goto V_67;
F_136 ( V_311 , F_137 ( V_52 ) ) ;
V_328:
V_315 ++ ;
}
}
V_67:
V_311 -> args [ 1 ] = V_315 ;
V_311 -> args [ 0 ] = V_313 ;
return V_52 -> V_333 ;
}
int F_138 ( struct V_42 * * V_319 , const struct V_42 * V_318 , int V_333 )
{
return F_139 ( V_319 , V_320 , V_318 , V_333 , V_324 ) ;
}
struct V_28 * F_140 ( struct V_28 * V_334 , struct V_42 * V_319 [] )
{
struct V_28 * V_28 ;
if ( V_319 [ V_335 ] )
V_28 = F_141 ( F_133 ( V_319 [ V_335 ] ) ) ;
else if ( V_319 [ V_336 ] )
V_28 = F_142 ( F_133 ( V_319 [ V_336 ] ) ) ;
else
V_28 = F_143 ( V_334 ) ;
return V_28 ;
}
static int F_144 ( struct V_29 * V_30 , struct V_42 * V_319 [] )
{
if ( V_30 ) {
if ( V_319 [ V_298 ] &&
F_145 ( V_319 [ V_298 ] ) < V_30 -> V_297 )
return - V_337 ;
if ( V_319 [ V_300 ] &&
F_145 ( V_319 [ V_300 ] ) < V_30 -> V_297 )
return - V_337 ;
}
if ( V_319 [ V_306 ] ) {
struct V_42 * V_308 ;
int V_338 , V_27 ;
F_146 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_49 ;
if ( ! ( V_49 = F_47 ( F_147 ( V_308 ) ) ) )
return - V_339 ;
if ( ! V_49 -> V_340 )
return - V_190 ;
if ( V_49 -> V_341 ) {
V_27 = V_49 -> V_341 ( V_30 , V_308 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_148 ( struct V_29 * V_30 , struct V_42 * * V_319 )
{
const struct V_342 * V_20 = V_30 -> V_172 ;
int V_27 = - V_337 ;
if ( V_319 [ V_234 ] ) {
struct V_157 * V_343 = F_109 ( V_319 [ V_234 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_344 )
V_27 = V_20 -> V_344 ( V_30 , V_343 -> V_181 ,
V_343 -> V_223 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_319 [ V_235 ] ) {
struct V_158 * V_345 = F_109 ( V_319 [ V_235 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_346 )
V_27 = V_20 -> V_346 ( V_30 , V_345 -> V_181 , V_345 -> V_226 ,
V_345 -> V_227 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_319 [ V_237 ] ) {
struct V_209 * V_347 = F_109 ( V_319 [ V_237 ] ) ;
struct V_218 V_348 ;
V_27 = - V_190 ;
if ( V_20 -> V_225 )
V_27 = V_20 -> V_225 ( V_30 , V_347 -> V_181 , & V_348 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = - V_190 ;
if ( V_20 -> V_349 )
V_27 = V_20 -> V_349 ( V_30 , V_347 -> V_181 ,
V_348 . V_230 ,
V_347 -> V_228 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_319 [ V_236 ] ) {
struct V_160 * V_347 = F_109 ( V_319 [ V_236 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_349 )
V_27 = V_20 -> V_349 ( V_30 , V_347 -> V_181 ,
V_347 -> V_230 ,
V_347 -> V_229 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_319 [ V_238 ] ) {
struct V_159 * V_350 = F_109 ( V_319 [ V_238 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_351 )
V_27 = V_20 -> V_351 ( V_30 , V_350 -> V_181 ,
V_350 -> V_231 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_319 [ V_239 ] ) {
struct V_161 * V_352 = F_109 ( V_319 [ V_239 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_353 )
V_27 = V_20 -> V_353 ( V_30 , V_352 -> V_181 ,
V_352 -> V_232 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_319 [ V_240 ] ) {
struct V_162 * V_354 ;
V_27 = - V_190 ;
V_354 = F_109 ( V_319 [ V_240 ] ) ;
if ( V_20 -> V_355 )
V_27 = V_20 -> V_355 ( V_30 , V_354 -> V_181 ,
V_354 -> V_231 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_319 [ V_241 ] ) {
struct V_164 * V_347 = F_109 ( V_319 [ V_241 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_356 )
V_27 = V_20 -> V_356 ( V_30 , V_347 -> V_181 , V_347 -> V_231 ) ;
if ( V_27 < 0 )
return V_27 ;
}
return V_27 ;
}
static int F_149 ( struct V_29 * V_30 , int V_269 )
{
struct V_29 * V_263 = F_44 ( V_30 ) ;
const struct V_342 * V_20 ;
int V_27 ;
if ( V_263 ) {
if ( V_263 -> V_269 == V_269 )
return 0 ;
V_20 = V_263 -> V_172 ;
if ( V_20 -> V_357 ) {
V_27 = V_20 -> V_357 ( V_263 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_190 ;
}
}
if ( V_269 ) {
V_263 = F_150 ( F_124 ( V_30 ) , V_269 ) ;
if ( ! V_263 )
return - V_337 ;
V_20 = V_263 -> V_172 ;
if ( V_20 -> V_358 ) {
V_27 = V_20 -> V_358 ( V_263 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_190 ;
}
}
return 0 ;
}
static int F_151 ( const struct V_51 * V_52 ,
struct V_29 * V_30 , struct V_122 * V_123 ,
struct V_42 * * V_319 , char * V_359 , int V_360 )
{
const struct V_342 * V_20 = V_30 -> V_172 ;
int V_27 ;
if ( V_319 [ V_335 ] || V_319 [ V_336 ] ) {
struct V_28 * V_28 = F_140 ( F_124 ( V_30 ) , V_319 ) ;
if ( F_152 ( V_28 ) ) {
V_27 = F_153 ( V_28 ) ;
goto V_361;
}
if ( ! F_154 ( V_52 , V_28 -> V_362 , V_363 ) ) {
F_155 ( V_28 ) ;
V_27 = - V_364 ;
goto V_361;
}
V_27 = F_156 ( V_30 , V_28 , V_359 ) ;
F_155 ( V_28 ) ;
if ( V_27 )
goto V_361;
V_360 |= V_365 ;
}
if ( V_319 [ V_259 ] ) {
struct V_176 * V_366 ;
struct V_367 V_368 ;
if ( ! V_20 -> V_369 ) {
V_27 = - V_190 ;
goto V_361;
}
if ( ! F_157 ( V_30 ) ) {
V_27 = - V_370 ;
goto V_361;
}
V_366 = F_109 ( V_319 [ V_259 ] ) ;
V_368 . V_252 = ( unsigned long ) V_366 -> V_252 ;
V_368 . V_253 = ( unsigned long ) V_366 -> V_253 ;
V_368 . V_254 = ( unsigned short ) V_366 -> V_254 ;
V_368 . V_255 = ( unsigned char ) V_366 -> V_255 ;
V_368 . V_256 = ( unsigned char ) V_366 -> V_256 ;
V_368 . V_257 = ( unsigned char ) V_366 -> V_257 ;
V_27 = V_20 -> V_369 ( V_30 , & V_368 ) ;
if ( V_27 < 0 )
goto V_361;
V_360 |= V_371 ;
}
if ( V_319 [ V_298 ] ) {
struct V_372 * V_373 ;
int V_333 ;
V_333 = sizeof( V_374 ) + V_30 -> V_297 ;
V_373 = F_158 ( V_333 , V_15 ) ;
if ( ! V_373 ) {
V_27 = - V_375 ;
goto V_361;
}
V_373 -> V_376 = V_30 -> type ;
memcpy ( V_373 -> V_377 , F_109 ( V_319 [ V_298 ] ) ,
V_30 -> V_297 ) ;
V_27 = F_159 ( V_30 , V_373 ) ;
F_24 ( V_373 ) ;
if ( V_27 )
goto V_361;
V_360 |= V_365 ;
}
if ( V_319 [ V_277 ] ) {
V_27 = F_160 ( V_30 , F_133 ( V_319 [ V_277 ] ) ) ;
if ( V_27 < 0 )
goto V_361;
V_360 |= V_365 ;
}
if ( V_319 [ V_279 ] ) {
F_161 ( V_30 , F_133 ( V_319 [ V_279 ] ) ) ;
V_360 |= V_371 ;
}
if ( V_123 -> V_268 > 0 && V_359 [ 0 ] ) {
V_27 = F_162 ( V_30 , V_359 ) ;
if ( V_27 < 0 )
goto V_361;
V_360 |= V_365 ;
}
if ( V_319 [ V_292 ] ) {
V_27 = F_163 ( V_30 , F_109 ( V_319 [ V_292 ] ) ,
F_145 ( V_319 [ V_292 ] ) ) ;
if ( V_27 < 0 )
goto V_361;
V_360 |= V_371 ;
}
if ( V_319 [ V_300 ] ) {
F_164 ( V_30 -> V_249 , V_319 [ V_300 ] , V_30 -> V_297 ) ;
F_165 ( V_378 , V_30 ) ;
}
if ( V_123 -> V_124 || V_123 -> V_125 ) {
V_27 = F_166 ( V_30 , F_88 ( V_30 , V_123 ) ) ;
if ( V_27 < 0 )
goto V_361;
}
if ( V_319 [ V_287 ] ) {
V_27 = F_149 ( V_30 , F_133 ( V_319 [ V_287 ] ) ) ;
if ( V_27 )
goto V_361;
V_360 |= V_365 ;
}
if ( V_319 [ V_288 ] ) {
V_27 = F_167 ( V_30 , F_168 ( V_319 [ V_288 ] ) ) ;
if ( V_27 )
goto V_361;
V_360 |= V_365 ;
}
if ( V_319 [ V_271 ] ) {
unsigned long V_379 = F_133 ( V_319 [ V_271 ] ) ;
if ( V_30 -> V_272 ^ V_379 )
V_360 |= V_371 ;
V_30 -> V_272 = V_379 ;
}
if ( V_319 [ V_273 ] )
F_82 ( V_30 , F_168 ( V_319 [ V_273 ] ) ) ;
if ( V_319 [ V_275 ] ) {
unsigned char V_379 = F_168 ( V_319 [ V_275 ] ) ;
F_84 ( & V_118 ) ;
if ( V_30 -> V_276 ^ V_379 )
V_360 |= V_371 ;
V_30 -> V_276 = V_379 ;
F_85 ( & V_118 ) ;
}
if ( V_319 [ V_302 ] ) {
struct V_42 * V_205 [ V_380 + 1 ] ;
struct V_42 * V_195 ;
int V_338 ;
F_146 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_147 ( V_195 ) != V_233 ||
F_145 ( V_195 ) < V_381 ) {
V_27 = - V_337 ;
goto V_361;
}
V_27 = F_169 ( V_205 , V_380 , V_195 ,
V_382 ) ;
if ( V_27 < 0 )
goto V_361;
V_27 = F_148 ( V_30 , V_205 ) ;
if ( V_27 < 0 )
goto V_361;
V_360 |= V_371 ;
}
}
V_27 = 0 ;
if ( V_319 [ V_182 ] ) {
struct V_42 * V_257 [ V_383 + 1 ] ;
struct V_42 * V_195 ;
int V_181 ;
int V_338 ;
V_27 = - V_190 ;
if ( ! V_20 -> V_384 )
goto V_361;
F_146 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_147 ( V_195 ) != V_183 ||
F_145 ( V_195 ) < V_381 ) {
V_27 = - V_337 ;
goto V_361;
}
V_27 = F_169 ( V_257 , V_383 , V_195 ,
V_385 ) ;
if ( V_27 < 0 )
goto V_361;
if ( ! V_257 [ V_184 ] ) {
V_27 = - V_190 ;
goto V_361;
}
V_181 = F_133 ( V_257 [ V_184 ] ) ;
V_27 = V_20 -> V_384 ( V_30 , V_181 , V_257 ) ;
if ( V_27 < 0 )
goto V_361;
V_360 |= V_371 ;
}
}
V_27 = 0 ;
if ( V_319 [ V_186 ] ) {
struct V_42 * V_257 [ V_383 + 1 ] ;
V_27 = F_169 ( V_257 , V_383 ,
V_319 [ V_186 ] , V_385 ) ;
if ( V_27 < 0 )
goto V_361;
V_27 = - V_190 ;
if ( V_20 -> V_384 )
V_27 = V_20 -> V_384 ( V_30 , V_187 , V_257 ) ;
if ( V_27 < 0 )
goto V_361;
V_360 |= V_371 ;
}
if ( V_319 [ V_306 ] ) {
struct V_42 * V_308 ;
int V_338 ;
F_146 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_49 ;
if ( ! ( V_49 = F_47 ( F_147 ( V_308 ) ) ) )
F_170 () ;
V_27 = V_49 -> V_340 ( V_30 , V_308 ) ;
if ( V_27 < 0 )
goto V_361;
V_360 |= V_371 ;
}
}
V_27 = 0 ;
if ( V_319 [ V_295 ] ) {
V_27 = F_171 ( V_30 ,
F_168 ( V_319 [ V_295 ] ) ) ;
if ( V_27 )
goto V_361;
V_360 |= V_371 ;
}
V_361:
if ( V_360 & V_365 ) {
if ( V_360 & V_371 )
F_86 ( V_30 ) ;
if ( V_27 < 0 )
F_172 ( L_3 ,
V_30 -> V_90 ) ;
}
return V_27 ;
}
static int F_173 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
struct V_122 * V_123 ;
struct V_29 * V_30 ;
int V_27 ;
struct V_42 * V_319 [ V_320 + 1 ] ;
char V_359 [ V_174 ] ;
V_27 = F_132 ( V_78 , sizeof( * V_123 ) , V_319 , V_320 , V_324 ) ;
if ( V_27 < 0 )
goto V_361;
if ( V_319 [ V_270 ] )
F_174 ( V_359 , V_319 [ V_270 ] , V_174 ) ;
else
V_359 [ 0 ] = '\0' ;
V_27 = - V_337 ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_268 > 0 )
V_30 = F_150 ( V_28 , V_123 -> V_268 ) ;
else if ( V_319 [ V_270 ] )
V_30 = F_175 ( V_28 , V_359 ) ;
else
goto V_361;
if ( V_30 == NULL ) {
V_27 = - V_370 ;
goto V_361;
}
V_27 = F_144 ( V_30 , V_319 ) ;
if ( V_27 < 0 )
goto V_361;
V_27 = F_151 ( V_52 , V_30 , V_123 , V_319 , V_359 , 0 ) ;
V_361:
return V_27 ;
}
static int F_176 ( const struct V_28 * V_28 , int V_70 )
{
struct V_29 * V_30 , * V_386 ;
F_31 ( V_31 ) ;
bool V_387 = false ;
if ( ! V_70 )
return - V_364 ;
F_32 (net, dev) {
if ( V_30 -> V_70 == V_70 ) {
const struct V_18 * V_20 ;
V_387 = true ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_190 ;
}
}
if ( ! V_387 )
return - V_370 ;
F_177 (net, dev, aux) {
if ( V_30 -> V_70 == V_70 ) {
const struct V_18 * V_20 ;
V_20 = V_30 -> V_18 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
}
}
F_33 ( & V_31 ) ;
return 0 ;
}
int F_178 ( struct V_29 * V_30 )
{
const struct V_18 * V_20 ;
F_31 ( V_31 ) ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_190 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
return 0 ;
}
static int F_179 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
struct V_29 * V_30 ;
struct V_122 * V_123 ;
char V_359 [ V_174 ] ;
struct V_42 * V_319 [ V_320 + 1 ] ;
int V_27 ;
V_27 = F_132 ( V_78 , sizeof( * V_123 ) , V_319 , V_320 , V_324 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_319 [ V_270 ] )
F_174 ( V_359 , V_319 [ V_270 ] , V_174 ) ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_268 > 0 )
V_30 = F_150 ( V_28 , V_123 -> V_268 ) ;
else if ( V_319 [ V_270 ] )
V_30 = F_175 ( V_28 , V_359 ) ;
else if ( V_319 [ V_279 ] )
return F_176 ( V_28 , F_133 ( V_319 [ V_279 ] ) ) ;
else
return - V_337 ;
if ( ! V_30 )
return - V_370 ;
return F_178 ( V_30 ) ;
}
int F_180 ( struct V_29 * V_30 , const struct V_122 * V_123 )
{
unsigned int V_388 ;
int V_27 ;
V_388 = V_30 -> V_79 ;
if ( V_123 && ( V_123 -> V_124 || V_123 -> V_125 ) ) {
V_27 = F_181 ( V_30 , F_88 ( V_30 , V_123 ) ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_30 -> V_389 = V_390 ;
F_182 ( V_30 , V_388 , ~ 0U ) ;
return 0 ;
}
struct V_29 * F_183 ( struct V_28 * V_28 ,
const char * V_359 , unsigned char V_391 ,
const struct V_18 * V_20 , struct V_42 * V_319 [] )
{
int V_27 ;
struct V_29 * V_30 ;
unsigned int V_283 = 1 ;
unsigned int V_285 = 1 ;
if ( V_319 [ V_282 ] )
V_283 = F_133 ( V_319 [ V_282 ] ) ;
else if ( V_20 -> V_392 )
V_283 = V_20 -> V_392 () ;
if ( V_319 [ V_284 ] )
V_285 = F_133 ( V_319 [ V_284 ] ) ;
else if ( V_20 -> V_393 )
V_285 = V_20 -> V_393 () ;
V_27 = - V_375 ;
V_30 = F_184 ( V_20 -> V_394 , V_359 , V_391 ,
V_20 -> V_22 , V_283 , V_285 ) ;
if ( ! V_30 )
goto V_27;
F_185 ( V_30 , V_28 ) ;
V_30 -> V_18 = V_20 ;
V_30 -> V_389 = V_395 ;
if ( V_319 [ V_277 ] )
V_30 -> V_278 = F_133 ( V_319 [ V_277 ] ) ;
if ( V_319 [ V_298 ] ) {
memcpy ( V_30 -> V_299 , F_109 ( V_319 [ V_298 ] ) ,
F_145 ( V_319 [ V_298 ] ) ) ;
V_30 -> V_396 = V_397 ;
}
if ( V_319 [ V_300 ] )
memcpy ( V_30 -> V_249 , F_109 ( V_319 [ V_300 ] ) ,
F_145 ( V_319 [ V_300 ] ) ) ;
if ( V_319 [ V_271 ] )
V_30 -> V_272 = F_133 ( V_319 [ V_271 ] ) ;
if ( V_319 [ V_273 ] )
F_82 ( V_30 , F_168 ( V_319 [ V_273 ] ) ) ;
if ( V_319 [ V_275 ] )
V_30 -> V_276 = F_168 ( V_319 [ V_275 ] ) ;
if ( V_319 [ V_279 ] )
F_161 ( V_30 , F_133 ( V_319 [ V_279 ] ) ) ;
return V_30 ;
V_27:
return F_186 ( V_27 ) ;
}
static int F_187 ( const struct V_51 * V_52 ,
struct V_28 * V_28 , int V_70 ,
struct V_122 * V_123 ,
struct V_42 * * V_319 )
{
struct V_29 * V_30 , * V_386 ;
int V_27 ;
F_177 (net, dev, aux) {
if ( V_30 -> V_70 == V_70 ) {
V_27 = F_151 ( V_52 , V_30 , V_123 , V_319 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_188 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_398 = NULL ;
struct V_29 * V_30 ;
struct V_29 * V_40 = NULL ;
struct V_122 * V_123 ;
char V_19 [ V_399 ] ;
char V_359 [ V_174 ] ;
struct V_42 * V_319 [ V_320 + 1 ] ;
struct V_42 * V_65 [ V_400 + 1 ] ;
unsigned char V_391 = V_401 ;
int V_27 ;
#ifdef F_189
V_402:
#endif
V_27 = F_132 ( V_78 , sizeof( * V_123 ) , V_319 , V_320 , V_324 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_319 [ V_270 ] )
F_174 ( V_359 , V_319 [ V_270 ] , V_174 ) ;
else
V_359 [ 0 ] = '\0' ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_268 > 0 )
V_30 = F_150 ( V_28 , V_123 -> V_268 ) ;
else {
if ( V_359 [ 0 ] )
V_30 = F_175 ( V_28 , V_359 ) ;
else
V_30 = NULL ;
}
if ( V_30 ) {
V_40 = F_44 ( V_30 ) ;
if ( V_40 )
V_398 = V_40 -> V_18 ;
}
V_27 = F_144 ( V_30 , V_319 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_319 [ V_66 ] ) {
V_27 = F_169 ( V_65 , V_400 ,
V_319 [ V_66 ] , V_403 ) ;
if ( V_27 < 0 )
return V_27 ;
} else
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
if ( V_65 [ V_60 ] ) {
F_174 ( V_19 , V_65 [ V_60 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_42 * V_195 [ V_20 ? V_20 -> V_404 + 1 : 1 ] ;
struct V_42 * V_405 [ V_398 ? V_398 -> V_406 + 1 : 1 ] ;
struct V_42 * * V_59 = NULL ;
struct V_42 * * V_53 = NULL ;
struct V_28 * V_407 , * V_304 = NULL ;
if ( V_20 ) {
if ( V_20 -> V_404 && V_65 [ V_63 ] ) {
V_27 = F_169 ( V_195 , V_20 -> V_404 ,
V_65 [ V_63 ] ,
V_20 -> V_408 ) ;
if ( V_27 < 0 )
return V_27 ;
V_59 = V_195 ;
}
if ( V_20 -> V_409 ) {
V_27 = V_20 -> V_409 ( V_319 , V_59 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_398 ) {
if ( V_398 -> V_406 &&
V_65 [ V_57 ] ) {
V_27 = F_169 ( V_405 ,
V_398 -> V_406 ,
V_65 [ V_57 ] ,
V_398 -> V_410 ) ;
if ( V_27 < 0 )
return V_27 ;
V_53 = V_405 ;
}
if ( V_398 -> V_411 ) {
V_27 = V_398 -> V_411 ( V_319 , V_53 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_30 ) {
int V_360 = 0 ;
if ( V_78 -> V_412 & V_413 )
return - V_21 ;
if ( V_78 -> V_412 & V_414 )
return - V_190 ;
if ( V_65 [ V_63 ] ) {
if ( ! V_20 || V_20 != V_30 -> V_18 ||
! V_20 -> V_415 )
return - V_190 ;
V_27 = V_20 -> V_415 ( V_30 , V_319 , V_59 ) ;
if ( V_27 < 0 )
return V_27 ;
V_360 |= V_371 ;
}
if ( V_65 [ V_57 ] ) {
if ( ! V_398 || ! V_398 -> V_416 )
return - V_190 ;
V_27 = V_398 -> V_416 ( V_40 , V_30 ,
V_319 , V_53 ) ;
if ( V_27 < 0 )
return V_27 ;
V_360 |= V_371 ;
}
return F_151 ( V_52 , V_30 , V_123 , V_319 , V_359 , V_360 ) ;
}
if ( ! ( V_78 -> V_412 & V_417 ) ) {
if ( V_123 -> V_268 == 0 && V_319 [ V_279 ] )
return F_187 ( V_52 , V_28 ,
F_133 ( V_319 [ V_279 ] ) ,
V_123 , V_319 ) ;
return - V_370 ;
}
if ( V_319 [ V_259 ] || V_319 [ V_287 ] || V_319 [ V_418 ] )
return - V_190 ;
if ( ! V_20 ) {
#ifdef F_189
if ( V_19 [ 0 ] ) {
F_3 () ;
F_190 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_402;
}
#endif
return - V_190 ;
}
if ( ! V_20 -> V_22 )
return - V_190 ;
if ( ! V_359 [ 0 ] ) {
snprintf ( V_359 , V_174 , L_5 , V_20 -> V_19 ) ;
V_391 = V_419 ;
}
V_407 = F_140 ( V_28 , V_319 ) ;
if ( F_152 ( V_407 ) )
return F_153 ( V_407 ) ;
V_27 = - V_364 ;
if ( ! F_154 ( V_52 , V_407 -> V_362 , V_363 ) )
goto V_67;
if ( V_319 [ V_305 ] ) {
int V_98 = F_191 ( V_319 [ V_305 ] ) ;
V_304 = F_192 ( V_407 , V_98 ) ;
if ( ! V_304 ) {
V_27 = - V_337 ;
goto V_67;
}
V_27 = - V_364 ;
if ( ! F_154 ( V_52 , V_304 -> V_362 , V_363 ) )
goto V_67;
}
V_30 = F_183 ( V_304 ? : V_407 , V_359 ,
V_391 , V_20 , V_319 ) ;
if ( F_152 ( V_30 ) ) {
V_27 = F_153 ( V_30 ) ;
goto V_67;
}
V_30 -> V_269 = V_123 -> V_268 ;
if ( V_20 -> V_420 ) {
V_27 = V_20 -> V_420 ( V_304 ? : V_28 , V_30 , V_319 , V_59 ) ;
if ( V_27 < 0 ) {
if ( V_30 -> V_421 == V_422 )
F_193 ( V_30 ) ;
goto V_67;
}
} else {
V_27 = F_194 ( V_30 ) ;
if ( V_27 < 0 ) {
F_193 ( V_30 ) ;
goto V_67;
}
}
V_27 = F_180 ( V_30 , V_123 ) ;
if ( V_27 < 0 )
goto V_423;
if ( V_304 ) {
V_27 = F_156 ( V_30 , V_407 , V_359 ) ;
if ( V_27 < 0 )
goto V_423;
}
V_67:
if ( V_304 )
F_155 ( V_304 ) ;
F_155 ( V_407 ) ;
return V_27 ;
V_423:
if ( V_20 -> V_420 ) {
F_31 ( V_31 ) ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
} else {
F_195 ( V_30 ) ;
}
goto V_67;
}
}
static int F_196 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
struct V_122 * V_123 ;
char V_359 [ V_174 ] ;
struct V_42 * V_319 [ V_320 + 1 ] ;
struct V_29 * V_30 = NULL ;
struct V_51 * V_424 ;
int V_27 ;
T_5 V_48 = 0 ;
V_27 = F_132 ( V_78 , sizeof( * V_123 ) , V_319 , V_320 , V_324 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_319 [ V_270 ] )
F_174 ( V_359 , V_319 [ V_270 ] , V_174 ) ;
if ( V_319 [ V_325 ] )
V_48 = F_133 ( V_319 [ V_325 ] ) ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_268 > 0 )
V_30 = F_150 ( V_28 , V_123 -> V_268 ) ;
else if ( V_319 [ V_270 ] )
V_30 = F_175 ( V_28 , V_359 ) ;
else
return - V_337 ;
if ( V_30 == NULL )
return - V_370 ;
V_424 = F_197 ( F_95 ( V_30 , V_48 ) , V_15 ) ;
if ( V_424 == NULL )
return - V_16 ;
V_27 = F_113 ( V_424 , V_30 , V_329 , F_61 ( V_52 ) . V_330 ,
V_78 -> V_331 , 0 , 0 , V_48 ) ;
if ( V_27 < 0 ) {
F_135 ( V_27 == - V_55 ) ;
F_198 ( V_424 ) ;
} else
V_27 = F_65 ( V_424 , V_28 , F_61 ( V_52 ) . V_330 ) ;
return V_27 ;
}
static T_9 F_199 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
struct V_29 * V_30 ;
struct V_42 * V_319 [ V_320 + 1 ] ;
T_5 V_48 = 0 ;
T_9 V_425 = 0 ;
int V_321 ;
V_321 = F_131 ( V_78 ) < sizeof( struct V_122 ) ?
sizeof( struct V_323 ) : sizeof( struct V_122 ) ;
if ( F_132 ( V_78 , V_321 , V_319 , V_320 , V_324 ) >= 0 ) {
if ( V_319 [ V_325 ] )
V_48 = F_133 ( V_319 [ V_325 ] ) ;
}
if ( ! V_48 )
return V_426 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_425 = F_200 ( T_9 , V_425 ,
F_95 ( V_30 ,
V_48 ) ) ;
}
return V_425 ;
}
static int F_201 ( struct V_51 * V_52 , struct V_310 * V_311 )
{
int V_315 ;
int V_316 = V_311 -> V_47 ;
if ( V_316 == 0 )
V_316 = 1 ;
for ( V_315 = 1 ; V_315 <= V_9 ; V_315 ++ ) {
int type = V_311 -> V_78 -> V_427 - V_4 ;
if ( V_315 < V_316 || V_315 == V_428 )
continue;
if ( V_10 [ V_315 ] == NULL ||
V_10 [ V_315 ] [ type ] . V_13 == NULL )
continue;
if ( V_315 > V_316 ) {
memset ( & V_311 -> args [ 0 ] , 0 , sizeof( V_311 -> args ) ) ;
V_311 -> V_429 = 0 ;
V_311 -> V_260 = 0 ;
}
if ( V_10 [ V_315 ] [ type ] . V_13 ( V_52 , V_311 ) )
break;
}
V_311 -> V_47 = V_315 ;
return V_52 -> V_333 ;
}
struct V_51 * F_202 ( int type , struct V_29 * V_30 ,
unsigned int V_261 , T_6 V_79 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
struct V_51 * V_52 ;
int V_27 = - V_16 ;
T_4 V_430 ;
V_52 = F_197 ( ( V_430 = F_95 ( V_30 , 0 ) ) , V_79 ) ;
if ( V_52 == NULL )
goto V_361;
V_27 = F_113 ( V_52 , V_30 , type , 0 , 0 , V_261 , 0 , 0 ) ;
if ( V_27 < 0 ) {
F_135 ( V_27 == - V_55 ) ;
F_198 ( V_52 ) ;
goto V_361;
}
return V_52 ;
V_361:
if ( V_27 < 0 )
F_70 ( V_28 , V_431 , V_27 ) ;
return NULL ;
}
void F_203 ( struct V_51 * V_52 , struct V_29 * V_30 , T_6 V_79 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
F_67 ( V_52 , V_28 , 0 , V_431 , NULL , V_79 ) ;
}
void F_204 ( int type , struct V_29 * V_30 , unsigned int V_261 ,
T_6 V_79 )
{
struct V_51 * V_52 ;
if ( V_30 -> V_421 != V_432 )
return;
V_52 = F_202 ( type , V_30 , V_261 , V_79 ) ;
if ( V_52 )
F_203 ( V_52 , V_30 , V_79 ) ;
}
static int F_205 ( struct V_51 * V_52 ,
struct V_29 * V_30 ,
T_10 * V_433 , T_9 V_434 , T_5 V_69 , T_5 V_260 ,
int type , unsigned int V_79 ,
int V_435 )
{
struct V_77 * V_78 ;
struct V_436 * V_437 ;
V_78 = F_115 ( V_52 , V_69 , V_260 , type , sizeof( * V_437 ) , V_435 ) ;
if ( ! V_78 )
return - V_55 ;
V_437 = F_116 ( V_78 ) ;
V_437 -> V_438 = V_439 ;
V_437 -> V_440 = 0 ;
V_437 -> V_441 = 0 ;
V_437 -> V_442 = V_79 ;
V_437 -> V_443 = 0 ;
V_437 -> V_444 = V_30 -> V_269 ;
V_437 -> V_445 = V_446 ;
if ( F_81 ( V_52 , V_447 , V_448 , V_433 ) )
goto V_91;
if ( V_434 )
if ( F_81 ( V_52 , V_449 , sizeof( T_9 ) , & V_434 ) )
goto V_91;
F_127 ( V_52 , V_78 ) ;
return 0 ;
V_91:
F_128 ( V_52 , V_78 ) ;
return - V_55 ;
}
static inline T_4 F_206 ( void )
{
return F_96 ( sizeof( struct V_436 ) ) + F_45 ( V_448 ) ;
}
static void F_207 ( struct V_29 * V_30 , T_10 * V_433 , T_9 V_434 , int type )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
struct V_51 * V_52 ;
int V_27 = - V_16 ;
V_52 = F_197 ( F_206 () , V_450 ) ;
if ( ! V_52 )
goto V_361;
V_27 = F_205 ( V_52 , V_30 , V_433 , V_434 ,
0 , 0 , type , V_451 , 0 ) ;
if ( V_27 < 0 ) {
F_198 ( V_52 ) ;
goto V_361;
}
F_67 ( V_52 , V_28 , 0 , V_452 , NULL , V_450 ) ;
return;
V_361:
F_70 ( V_28 , V_452 , V_27 ) ;
}
int F_208 ( struct V_436 * V_437 ,
struct V_42 * V_319 [] ,
struct V_29 * V_30 ,
const unsigned char * V_433 , T_9 V_434 ,
T_9 V_79 )
{
int V_27 = - V_337 ;
if ( V_437 -> V_445 && ! ( V_437 -> V_445 & V_446 ) ) {
F_209 ( L_6 , V_30 -> V_90 ) ;
return V_27 ;
}
if ( V_434 ) {
F_209 ( L_7 , V_30 -> V_90 ) ;
return V_27 ;
}
if ( F_210 ( V_433 ) || F_211 ( V_433 ) )
V_27 = F_212 ( V_30 , V_433 ) ;
else if ( F_213 ( V_433 ) )
V_27 = F_214 ( V_30 , V_433 ) ;
if ( V_27 == - V_21 && ! ( V_79 & V_413 ) )
V_27 = 0 ;
return V_27 ;
}
static int F_215 ( struct V_42 * V_453 , T_9 * V_454 )
{
T_9 V_434 = 0 ;
if ( V_453 ) {
if ( F_145 ( V_453 ) != sizeof( T_9 ) ) {
F_209 ( L_8 ) ;
return - V_337 ;
}
V_434 = F_216 ( V_453 ) ;
if ( ! V_434 || V_434 >= V_455 ) {
F_209 ( L_9 ,
V_434 ) ;
return - V_337 ;
}
}
* V_454 = V_434 ;
return 0 ;
}
static int F_217 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
struct V_436 * V_437 ;
struct V_42 * V_319 [ V_456 + 1 ] ;
struct V_29 * V_30 ;
T_10 * V_433 ;
T_9 V_434 ;
int V_27 ;
V_27 = F_132 ( V_78 , sizeof( * V_437 ) , V_319 , V_456 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_437 = F_116 ( V_78 ) ;
if ( V_437 -> V_444 == 0 ) {
F_209 ( L_10 ) ;
return - V_337 ;
}
V_30 = F_150 ( V_28 , V_437 -> V_444 ) ;
if ( V_30 == NULL ) {
F_209 ( L_11 ) ;
return - V_370 ;
}
if ( ! V_319 [ V_447 ] || F_145 ( V_319 [ V_447 ] ) != V_448 ) {
F_209 ( L_12 ) ;
return - V_337 ;
}
V_433 = F_109 ( V_319 [ V_447 ] ) ;
V_27 = F_215 ( V_319 [ V_449 ] , & V_434 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_190 ;
if ( ( ! V_437 -> V_442 || V_437 -> V_442 & V_457 ) &&
( V_30 -> V_458 & V_459 ) ) {
struct V_29 * V_460 = F_44 ( V_30 ) ;
const struct V_342 * V_20 = V_460 -> V_172 ;
V_27 = V_20 -> V_461 ( V_437 , V_319 , V_30 , V_433 , V_434 ,
V_78 -> V_412 ) ;
if ( V_27 )
goto V_67;
else
V_437 -> V_442 &= ~ V_457 ;
}
if ( ( V_437 -> V_442 & V_451 ) ) {
if ( V_30 -> V_172 -> V_461 )
V_27 = V_30 -> V_172 -> V_461 ( V_437 , V_319 , V_30 , V_433 ,
V_434 ,
V_78 -> V_412 ) ;
else
V_27 = F_208 ( V_437 , V_319 , V_30 , V_433 , V_434 ,
V_78 -> V_412 ) ;
if ( ! V_27 ) {
F_207 ( V_30 , V_433 , V_434 , V_462 ) ;
V_437 -> V_442 &= ~ V_451 ;
}
}
V_67:
return V_27 ;
}
int F_218 ( struct V_436 * V_437 ,
struct V_42 * V_319 [] ,
struct V_29 * V_30 ,
const unsigned char * V_433 , T_9 V_434 )
{
int V_27 = - V_337 ;
if ( ! ( V_437 -> V_445 & V_446 ) ) {
F_209 ( L_6 , V_30 -> V_90 ) ;
return V_27 ;
}
if ( F_210 ( V_433 ) || F_211 ( V_433 ) )
V_27 = F_219 ( V_30 , V_433 ) ;
else if ( F_213 ( V_433 ) )
V_27 = F_220 ( V_30 , V_433 ) ;
return V_27 ;
}
static int F_221 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
struct V_436 * V_437 ;
struct V_42 * V_319 [ V_456 + 1 ] ;
struct V_29 * V_30 ;
int V_27 = - V_337 ;
T_11 * V_433 ;
T_9 V_434 ;
if ( ! F_222 ( V_52 , V_363 ) )
return - V_364 ;
V_27 = F_132 ( V_78 , sizeof( * V_437 ) , V_319 , V_456 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_437 = F_116 ( V_78 ) ;
if ( V_437 -> V_444 == 0 ) {
F_209 ( L_13 ) ;
return - V_337 ;
}
V_30 = F_150 ( V_28 , V_437 -> V_444 ) ;
if ( V_30 == NULL ) {
F_209 ( L_14 ) ;
return - V_370 ;
}
if ( ! V_319 [ V_447 ] || F_145 ( V_319 [ V_447 ] ) != V_448 ) {
F_209 ( L_15 ) ;
return - V_337 ;
}
V_433 = F_109 ( V_319 [ V_447 ] ) ;
V_27 = F_215 ( V_319 [ V_449 ] , & V_434 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_190 ;
if ( ( ! V_437 -> V_442 || V_437 -> V_442 & V_457 ) &&
( V_30 -> V_458 & V_459 ) ) {
struct V_29 * V_460 = F_44 ( V_30 ) ;
const struct V_342 * V_20 = V_460 -> V_172 ;
if ( V_20 -> V_463 )
V_27 = V_20 -> V_463 ( V_437 , V_319 , V_30 , V_433 , V_434 ) ;
if ( V_27 )
goto V_67;
else
V_437 -> V_442 &= ~ V_457 ;
}
if ( V_437 -> V_442 & V_451 ) {
if ( V_30 -> V_172 -> V_463 )
V_27 = V_30 -> V_172 -> V_463 ( V_437 , V_319 , V_30 , V_433 ,
V_434 ) ;
else
V_27 = F_218 ( V_437 , V_319 , V_30 , V_433 , V_434 ) ;
if ( ! V_27 ) {
F_207 ( V_30 , V_433 , V_434 , V_464 ) ;
V_437 -> V_442 &= ~ V_451 ;
}
}
V_67:
return V_27 ;
}
static int F_223 ( struct V_51 * V_52 ,
struct V_310 * V_311 ,
struct V_29 * V_30 ,
int * V_315 ,
struct V_465 * V_25 )
{
struct V_466 * V_467 ;
int V_27 ;
T_5 V_330 , V_260 ;
V_330 = F_61 ( V_311 -> V_52 ) . V_330 ;
V_260 = V_311 -> V_78 -> V_331 ;
F_26 (ha, &list->list, list) {
if ( * V_315 < V_311 -> args [ 0 ] )
goto V_468;
V_27 = F_205 ( V_52 , V_30 , V_467 -> V_433 , 0 ,
V_330 , V_260 ,
V_462 , V_451 ,
V_332 ) ;
if ( V_27 < 0 )
return V_27 ;
V_468:
* V_315 += 1 ;
}
return 0 ;
}
int F_224 ( struct V_51 * V_52 ,
struct V_310 * V_311 ,
struct V_29 * V_30 ,
struct V_29 * V_469 ,
int V_315 )
{
int V_27 ;
F_225 ( V_30 ) ;
V_27 = F_223 ( V_52 , V_311 , V_30 , & V_315 , & V_30 -> V_470 ) ;
if ( V_27 )
goto V_67;
F_223 ( V_52 , V_311 , V_30 , & V_315 , & V_30 -> V_471 ) ;
V_67:
F_226 ( V_30 ) ;
return V_315 ;
}
static int F_227 ( struct V_51 * V_52 , struct V_310 * V_311 )
{
struct V_29 * V_30 ;
struct V_42 * V_319 [ V_320 + 1 ] ;
struct V_29 * V_460 = NULL ;
const struct V_342 * V_20 = NULL ;
const struct V_342 * V_472 = NULL ;
struct V_122 * V_123 = F_116 ( V_311 -> V_78 ) ;
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
int V_473 = 0 ;
int V_474 = 0 ;
int V_315 = 0 ;
if ( F_132 ( V_311 -> V_78 , sizeof( struct V_122 ) , V_319 , V_320 ,
V_324 ) == 0 ) {
if ( V_319 [ V_287 ] )
V_474 = F_133 ( V_319 [ V_287 ] ) ;
}
V_473 = V_123 -> V_268 ;
if ( V_474 ) {
V_460 = F_150 ( V_28 , V_474 ) ;
if ( ! V_460 )
return - V_370 ;
V_20 = V_460 -> V_172 ;
}
F_32 (net, dev) {
if ( V_473 && ( V_30 -> V_269 != V_473 ) )
continue;
if ( ! V_474 ) {
if ( V_30 -> V_458 & V_459 ) {
V_460 = F_44 ( V_30 ) ;
V_472 = V_460 -> V_172 ;
}
} else {
if ( V_30 != V_460 &&
! ( V_30 -> V_458 & V_459 ) )
continue;
if ( V_460 != F_44 ( V_30 ) &&
! ( V_30 -> V_458 & V_475 ) )
continue;
V_472 = V_20 ;
}
if ( V_30 -> V_458 & V_459 ) {
if ( V_472 && V_472 -> V_476 )
V_315 = V_472 -> V_476 ( V_52 , V_311 , V_460 , V_30 ,
V_315 ) ;
}
if ( V_30 -> V_172 -> V_476 )
V_315 = V_30 -> V_172 -> V_476 ( V_52 , V_311 , V_30 , NULL ,
V_315 ) ;
else
V_315 = F_224 ( V_52 , V_311 , V_30 , NULL , V_315 ) ;
V_472 = NULL ;
}
V_311 -> args [ 0 ] = V_315 ;
return V_52 -> V_333 ;
}
static int F_228 ( struct V_51 * V_52 , T_5 V_79 , T_5 V_477 ,
unsigned int V_478 , unsigned int V_479 )
{
if ( V_477 & V_479 )
return F_118 ( V_52 , V_478 , ! ! ( V_79 & V_479 ) ) ;
return 0 ;
}
int F_229 ( struct V_51 * V_52 , T_5 V_69 , T_5 V_260 ,
struct V_29 * V_30 , T_9 V_480 ,
T_5 V_79 , T_5 V_477 , int V_435 ,
T_5 V_481 ,
int (* F_230)( struct V_51 * V_52 ,
struct V_29 * V_30 ,
T_5 V_481 ) )
{
struct V_77 * V_78 ;
struct V_122 * V_123 ;
struct V_42 * V_482 ;
struct V_42 * V_483 ;
T_10 V_114 = F_119 ( V_30 ) ? V_30 -> V_114 : V_274 ;
struct V_29 * V_460 = F_44 ( V_30 ) ;
int V_27 = 0 ;
V_78 = F_115 ( V_52 , V_69 , V_260 , V_329 , sizeof( * V_123 ) , V_435 ) ;
if ( V_78 == NULL )
return - V_55 ;
V_123 = F_116 ( V_78 ) ;
V_123 -> V_264 = V_439 ;
V_123 -> V_266 = 0 ;
V_123 -> V_267 = V_30 -> type ;
V_123 -> V_268 = V_30 -> V_269 ;
V_123 -> V_124 = F_117 ( V_30 ) ;
V_123 -> V_125 = 0 ;
if ( F_54 ( V_52 , V_270 , V_30 -> V_90 ) ||
F_75 ( V_52 , V_277 , V_30 -> V_278 ) ||
F_118 ( V_52 , V_273 , V_114 ) ||
( V_460 &&
F_75 ( V_52 , V_287 , V_460 -> V_269 ) ) ||
( V_30 -> V_297 &&
F_81 ( V_52 , V_298 , V_30 -> V_297 , V_30 -> V_299 ) ) ||
( V_30 -> V_269 != F_121 ( V_30 ) &&
F_75 ( V_52 , V_286 , F_121 ( V_30 ) ) ) )
goto V_91;
V_482 = F_55 ( V_52 , V_306 ) ;
if ( ! V_482 )
goto V_91;
if ( F_231 ( V_52 , V_484 , V_485 ) ) {
F_57 ( V_52 , V_482 ) ;
goto V_91;
}
if ( V_480 != V_486 ) {
if ( F_231 ( V_52 , V_487 , V_480 ) ) {
F_57 ( V_52 , V_482 ) ;
goto V_91;
}
}
if ( F_230 ) {
V_27 = F_230 ( V_52 , V_30 , V_481 ) ;
if ( V_27 ) {
F_57 ( V_52 , V_482 ) ;
goto V_91;
}
}
F_56 ( V_52 , V_482 ) ;
V_483 = F_55 ( V_52 , V_418 | V_488 ) ;
if ( ! V_483 )
goto V_91;
if ( F_228 ( V_52 , V_79 , V_477 ,
V_489 , V_490 ) ||
F_228 ( V_52 , V_79 , V_477 ,
V_491 , V_492 ) ||
F_228 ( V_52 , V_79 , V_477 ,
V_493 ,
V_494 ) ||
F_228 ( V_52 , V_79 , V_477 ,
V_495 , V_496 ) ||
F_228 ( V_52 , V_79 , V_477 ,
V_497 , V_498 ) ||
F_228 ( V_52 , V_79 , V_477 ,
V_499 , V_500 ) ||
F_228 ( V_52 , V_79 , V_477 ,
V_501 , V_502 ) ||
F_228 ( V_52 , V_79 , V_477 ,
V_503 , V_504 ) ) {
F_57 ( V_52 , V_483 ) ;
goto V_91;
}
F_56 ( V_52 , V_483 ) ;
F_127 ( V_52 , V_78 ) ;
return 0 ;
V_91:
F_128 ( V_52 , V_78 ) ;
return V_27 ? V_27 : - V_55 ;
}
static int F_232 ( struct V_51 * V_52 , struct V_310 * V_311 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
struct V_29 * V_30 ;
int V_315 = 0 ;
T_5 V_330 = F_61 ( V_311 -> V_52 ) . V_330 ;
T_5 V_260 = V_311 -> V_78 -> V_331 ;
T_5 V_481 = 0 ;
int V_27 ;
if ( F_131 ( V_311 -> V_78 ) > sizeof( struct V_122 ) ) {
struct V_42 * V_505 ;
V_505 = F_233 ( V_311 -> V_78 , sizeof( struct V_122 ) ,
V_325 ) ;
if ( V_505 ) {
if ( F_145 ( V_505 ) < sizeof( V_481 ) )
return - V_337 ;
V_481 = F_133 ( V_505 ) ;
}
}
F_234 () ;
F_235 (net, dev) {
const struct V_342 * V_20 = V_30 -> V_172 ;
struct V_29 * V_460 = F_44 ( V_30 ) ;
if ( V_460 && V_460 -> V_172 -> V_506 ) {
if ( V_315 >= V_311 -> args [ 0 ] ) {
V_27 = V_460 -> V_172 -> V_506 (
V_52 , V_330 , V_260 , V_30 ,
V_481 , V_332 ) ;
if ( V_27 < 0 && V_27 != - V_190 )
break;
}
V_315 ++ ;
}
if ( V_20 -> V_506 ) {
if ( V_315 >= V_311 -> args [ 0 ] ) {
V_27 = V_20 -> V_506 ( V_52 , V_330 ,
V_260 , V_30 ,
V_481 ,
V_332 ) ;
if ( V_27 < 0 && V_27 != - V_190 )
break;
}
V_315 ++ ;
}
}
F_236 () ;
V_311 -> args [ 0 ] = V_315 ;
return V_52 -> V_333 ;
}
static inline T_4 F_237 ( void )
{
return F_96 ( sizeof( struct V_122 ) )
+ F_45 ( V_174 )
+ F_45 ( V_177 )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_10 ) )
+ F_45 ( sizeof( struct V_42 ) )
+ F_45 ( sizeof( T_9 ) )
+ F_45 ( sizeof( T_9 ) ) ;
}
static int F_238 ( struct V_29 * V_30 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
struct V_51 * V_52 ;
int V_27 = - V_190 ;
if ( ! V_30 -> V_172 -> V_506 )
return 0 ;
V_52 = F_197 ( F_237 () , V_450 ) ;
if ( ! V_52 ) {
V_27 = - V_375 ;
goto V_361;
}
V_27 = V_30 -> V_172 -> V_506 ( V_52 , 0 , 0 , V_30 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_361;
if ( ! V_52 -> V_333 )
goto V_361;
F_67 ( V_52 , V_28 , 0 , V_431 , NULL , V_450 ) ;
return 0 ;
V_361:
F_135 ( V_27 == - V_55 ) ;
F_198 ( V_52 ) ;
if ( V_27 )
F_70 ( V_28 , V_431 , V_27 ) ;
return V_27 ;
}
static int F_239 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
struct V_122 * V_123 ;
struct V_29 * V_30 ;
struct V_42 * V_507 , * V_195 = NULL ;
int V_338 , V_27 = - V_190 ;
T_9 V_79 = 0 ;
bool V_508 = false ;
if ( F_131 ( V_78 ) < sizeof( * V_123 ) )
return - V_337 ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_264 != V_439 )
return - V_509 ;
V_30 = F_150 ( V_28 , V_123 -> V_268 ) ;
if ( ! V_30 ) {
F_209 ( L_16 ) ;
return - V_370 ;
}
V_507 = F_233 ( V_78 , sizeof( struct V_122 ) , V_306 ) ;
if ( V_507 ) {
F_146 (attr, br_spec, rem) {
if ( F_147 ( V_195 ) == V_484 ) {
if ( F_145 ( V_195 ) < sizeof( V_79 ) )
return - V_337 ;
V_508 = true ;
V_79 = F_216 ( V_195 ) ;
break;
}
}
}
if ( ! V_79 || ( V_79 & V_510 ) ) {
struct V_29 * V_460 = F_44 ( V_30 ) ;
if ( ! V_460 || ! V_460 -> V_172 -> V_511 ) {
V_27 = - V_190 ;
goto V_67;
}
V_27 = V_460 -> V_172 -> V_511 ( V_30 , V_78 , V_79 ) ;
if ( V_27 )
goto V_67;
V_79 &= ~ V_510 ;
}
if ( ( V_79 & V_485 ) ) {
if ( ! V_30 -> V_172 -> V_511 )
V_27 = - V_190 ;
else
V_27 = V_30 -> V_172 -> V_511 ( V_30 , V_78 ,
V_79 ) ;
if ( ! V_27 ) {
V_79 &= ~ V_485 ;
V_27 = F_238 ( V_30 ) ;
}
}
if ( V_508 )
memcpy ( F_109 ( V_195 ) , & V_79 , sizeof( V_79 ) ) ;
V_67:
return V_27 ;
}
static int F_240 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
struct V_122 * V_123 ;
struct V_29 * V_30 ;
struct V_42 * V_507 , * V_195 = NULL ;
int V_338 , V_27 = - V_190 ;
T_9 V_79 = 0 ;
bool V_508 = false ;
if ( F_131 ( V_78 ) < sizeof( * V_123 ) )
return - V_337 ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_264 != V_439 )
return - V_509 ;
V_30 = F_150 ( V_28 , V_123 -> V_268 ) ;
if ( ! V_30 ) {
F_209 ( L_16 ) ;
return - V_370 ;
}
V_507 = F_233 ( V_78 , sizeof( struct V_122 ) , V_306 ) ;
if ( V_507 ) {
F_146 (attr, br_spec, rem) {
if ( F_147 ( V_195 ) == V_484 ) {
if ( F_145 ( V_195 ) < sizeof( V_79 ) )
return - V_337 ;
V_508 = true ;
V_79 = F_216 ( V_195 ) ;
break;
}
}
}
if ( ! V_79 || ( V_79 & V_510 ) ) {
struct V_29 * V_460 = F_44 ( V_30 ) ;
if ( ! V_460 || ! V_460 -> V_172 -> V_512 ) {
V_27 = - V_190 ;
goto V_67;
}
V_27 = V_460 -> V_172 -> V_512 ( V_30 , V_78 , V_79 ) ;
if ( V_27 )
goto V_67;
V_79 &= ~ V_510 ;
}
if ( ( V_79 & V_485 ) ) {
if ( ! V_30 -> V_172 -> V_512 )
V_27 = - V_190 ;
else
V_27 = V_30 -> V_172 -> V_512 ( V_30 , V_78 ,
V_79 ) ;
if ( ! V_27 ) {
V_79 &= ~ V_485 ;
V_27 = F_238 ( V_30 ) ;
}
}
if ( V_508 )
memcpy ( F_109 ( V_195 ) , & V_79 , sizeof( V_79 ) ) ;
V_67:
return V_27 ;
}
static int F_241 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_312 ) ;
T_1 V_11 ;
int V_513 , V_19 ;
int V_47 ;
int type ;
int V_27 ;
type = V_78 -> V_427 ;
if ( type > V_514 )
return - V_190 ;
type -= V_4 ;
if ( F_131 ( V_78 ) < sizeof( struct V_323 ) )
return 0 ;
V_47 = ( (struct V_323 * ) F_116 ( V_78 ) ) -> V_515 ;
V_513 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_242 ( V_52 , V_363 ) )
return - V_364 ;
if ( V_19 == 2 && V_78 -> V_412 & V_516 ) {
struct V_72 * V_73 ;
T_2 V_13 ;
T_3 V_14 ;
T_9 V_517 = 0 ;
V_13 = F_16 ( V_47 , type ) ;
if ( V_13 == NULL )
return - V_190 ;
V_14 = F_17 ( V_47 , type ) ;
if ( V_14 )
V_517 = V_14 ( V_52 , V_78 ) ;
F_3 () ;
V_73 = V_28 -> V_73 ;
{
struct V_518 V_519 = {
. V_520 = V_13 ,
. V_517 = V_517 ,
} ;
V_27 = F_243 ( V_73 , V_52 , V_78 , & V_519 ) ;
}
F_1 () ;
return V_27 ;
}
V_11 = F_15 ( V_47 , type ) ;
if ( V_11 == NULL )
return - V_190 ;
return V_11 ( V_52 , V_78 ) ;
}
static void F_244 ( struct V_51 * V_52 )
{
F_1 () ;
F_245 ( V_52 , & F_241 ) ;
F_5 () ;
}
static int F_246 ( struct V_521 * V_522 , unsigned long V_523 , void * V_524 )
{
struct V_29 * V_30 = F_247 ( V_524 ) ;
switch ( V_523 ) {
case V_525 :
case V_526 :
case V_527 :
case V_528 :
case V_529 :
case V_530 :
case V_531 :
case V_532 :
case V_533 :
case V_534 :
case V_535 :
case V_536 :
case V_537 :
break;
default:
F_204 ( V_329 , V_30 , 0 , V_15 ) ;
break;
}
return V_538 ;
}
static int T_12 F_248 ( struct V_28 * V_28 )
{
struct V_72 * V_312 ;
struct V_539 V_540 = {
. V_541 = V_542 ,
. V_543 = F_244 ,
. V_544 = & V_1 ,
. V_79 = V_545 ,
} ;
V_312 = F_249 ( V_28 , V_546 , & V_540 ) ;
if ( ! V_312 )
return - V_375 ;
V_28 -> V_73 = V_312 ;
return 0 ;
}
static void T_13 F_250 ( struct V_28 * V_28 )
{
F_251 ( V_28 -> V_73 ) ;
V_28 -> V_73 = NULL ;
}
void T_14 F_252 ( void )
{
if ( F_253 ( & V_547 ) )
F_21 ( L_17 ) ;
F_254 ( & V_548 ) ;
F_20 ( V_12 , V_549 , F_196 ,
F_129 , F_199 ) ;
F_20 ( V_12 , V_550 , F_173 , NULL , NULL ) ;
F_20 ( V_12 , V_329 , F_188 , NULL , NULL ) ;
F_20 ( V_12 , V_551 , F_179 , NULL , NULL ) ;
F_20 ( V_12 , V_552 , NULL , F_201 , NULL ) ;
F_20 ( V_12 , V_553 , NULL , F_201 , NULL ) ;
F_20 ( V_554 , V_462 , F_217 , NULL , NULL ) ;
F_20 ( V_554 , V_464 , F_221 , NULL , NULL ) ;
F_20 ( V_554 , V_555 , NULL , F_227 , NULL ) ;
F_20 ( V_554 , V_549 , NULL , F_232 , NULL ) ;
F_20 ( V_554 , V_551 , F_240 , NULL , NULL ) ;
F_20 ( V_554 , V_550 , F_239 , NULL , NULL ) ;
}
