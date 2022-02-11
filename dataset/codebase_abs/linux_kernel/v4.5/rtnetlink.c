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
. V_196 = V_30 ,
. V_98 = V_197 ,
. V_79 = V_198 ,
} ;
V_27 = F_105 ( V_30 , & V_195 ) ;
if ( V_27 ) {
if ( V_27 == - V_190 )
return 0 ;
return V_27 ;
}
if ( F_81 ( V_52 , V_199 , V_195 . V_200 . V_189 . V_192 ,
V_195 . V_200 . V_189 . V_98 ) )
return - V_55 ;
return 0 ;
}
static T_8 int F_106 ( struct V_51 * V_52 ,
struct V_29 * V_30 )
{
const struct V_128 * V_201 ;
struct V_128 V_202 ;
struct V_42 * V_195 ;
V_201 = F_107 ( V_30 , & V_202 ) ;
V_195 = F_108 ( V_52 , V_203 ,
sizeof( struct V_126 ) ) ;
if ( ! V_195 )
return - V_55 ;
F_89 ( F_109 ( V_195 ) , V_201 ) ;
V_195 = F_108 ( V_52 , V_204 ,
sizeof( struct V_128 ) ) ;
if ( ! V_195 )
return - V_55 ;
F_90 ( F_109 ( V_195 ) , V_201 ) ;
return 0 ;
}
static T_8 int F_110 ( struct V_51 * V_52 ,
struct V_29 * V_30 ,
int V_205 ,
struct V_42 * V_206 )
{
struct V_162 V_207 ;
struct V_161 V_208 ;
struct V_159 V_209 ;
struct V_210 V_211 ;
struct V_212 V_213 ;
struct V_164 V_214 ;
struct V_158 V_215 ;
struct V_160 V_216 ;
struct V_42 * V_181 , * V_217 ;
struct V_157 V_218 ;
struct V_219 V_220 ;
V_220 . V_221 = - 1 ;
V_220 . V_222 = - 1 ;
V_220 . V_223 = - 1 ;
memset ( V_220 . V_224 , 0 , sizeof( V_220 . V_224 ) ) ;
V_220 . V_225 = 0 ;
if ( V_30 -> V_172 -> V_226 ( V_30 , V_205 , & V_220 ) )
return 0 ;
V_218 . V_181 =
V_215 . V_181 =
V_216 . V_181 =
V_211 . V_181 =
V_209 . V_181 =
V_208 . V_181 =
V_207 . V_181 =
V_214 . V_181 = V_220 . V_181 ;
memcpy ( V_218 . V_224 , V_220 . V_224 , sizeof( V_220 . V_224 ) ) ;
V_215 . V_227 = V_220 . V_227 ;
V_215 . V_228 = V_220 . V_228 ;
V_211 . V_229 = V_220 . V_230 ;
V_216 . V_231 = V_220 . V_231 ;
V_216 . V_230 = V_220 . V_230 ;
V_209 . V_232 = V_220 . V_221 ;
V_208 . V_233 = V_220 . V_225 ;
V_207 . V_232 = V_220 . V_222 ;
V_214 . V_232 = V_220 . V_223 ;
V_181 = F_55 ( V_52 , V_234 ) ;
if ( ! V_181 ) {
F_57 ( V_52 , V_206 ) ;
return - V_55 ;
}
if ( F_81 ( V_52 , V_235 , sizeof( V_218 ) , & V_218 ) ||
F_81 ( V_52 , V_236 , sizeof( V_215 ) , & V_215 ) ||
F_81 ( V_52 , V_237 , sizeof( V_216 ) ,
& V_216 ) ||
F_81 ( V_52 , V_238 , sizeof( V_211 ) ,
& V_211 ) ||
F_81 ( V_52 , V_239 , sizeof( V_209 ) ,
& V_209 ) ||
F_81 ( V_52 , V_240 , sizeof( V_208 ) ,
& V_208 ) ||
F_81 ( V_52 , V_241 ,
sizeof( V_207 ) ,
& V_207 ) ||
F_81 ( V_52 , V_242 ,
sizeof( V_214 ) , & V_214 ) )
return - V_55 ;
memset ( & V_213 , 0 , sizeof( V_213 ) ) ;
if ( V_30 -> V_172 -> V_243 )
V_30 -> V_172 -> V_243 ( V_30 , V_205 ,
& V_213 ) ;
V_217 = F_55 ( V_52 , V_244 ) ;
if ( ! V_217 ) {
F_57 ( V_52 , V_181 ) ;
F_57 ( V_52 , V_206 ) ;
return - V_55 ;
}
if ( F_111 ( V_52 , V_245 ,
V_213 . V_130 ) ||
F_111 ( V_52 , V_246 ,
V_213 . V_131 ) ||
F_111 ( V_52 , V_247 ,
V_213 . V_132 ) ||
F_111 ( V_52 , V_248 ,
V_213 . V_133 ) ||
F_111 ( V_52 , V_249 ,
V_213 . V_250 ) ||
F_111 ( V_52 , V_251 ,
V_213 . V_138 ) )
return - V_55 ;
F_56 ( V_52 , V_217 ) ;
F_56 ( V_52 , V_181 ) ;
return 0 ;
}
static int F_112 ( struct V_51 * V_52 , struct V_29 * V_30 )
{
struct V_176 V_252 = {
. V_253 = V_30 -> V_253 ,
. V_254 = V_30 -> V_254 ,
. V_255 = V_30 -> V_255 ,
. V_256 = V_30 -> V_256 ,
. V_257 = V_30 -> V_257 ,
. V_258 = V_30 -> V_259 ,
} ;
if ( F_81 ( V_52 , V_260 , sizeof( V_252 ) , & V_252 ) )
return - V_55 ;
return 0 ;
}
static int F_113 ( struct V_51 * V_52 , struct V_29 * V_30 ,
int type , T_5 V_69 , T_5 V_261 , T_5 V_262 ,
unsigned int V_79 , T_5 V_48 )
{
struct V_122 * V_123 ;
struct V_77 * V_78 ;
struct V_42 * V_263 ;
struct V_46 * V_49 ;
struct V_29 * V_264 = F_44 ( V_30 ) ;
F_114 () ;
V_78 = F_115 ( V_52 , V_69 , V_261 , type , sizeof( * V_123 ) , V_79 ) ;
if ( V_78 == NULL )
return - V_55 ;
V_123 = F_116 ( V_78 ) ;
V_123 -> V_265 = V_266 ;
V_123 -> V_267 = 0 ;
V_123 -> V_268 = V_30 -> type ;
V_123 -> V_269 = V_30 -> V_270 ;
V_123 -> V_124 = F_117 ( V_30 ) ;
V_123 -> V_125 = V_262 ;
if ( F_54 ( V_52 , V_271 , V_30 -> V_90 ) ||
F_75 ( V_52 , V_272 , V_30 -> V_273 ) ||
F_118 ( V_52 , V_274 ,
F_119 ( V_30 ) ? V_30 -> V_114 : V_275 ) ||
F_118 ( V_52 , V_276 , V_30 -> V_277 ) ||
F_75 ( V_52 , V_278 , V_30 -> V_279 ) ||
F_75 ( V_52 , V_280 , V_30 -> V_70 ) ||
F_75 ( V_52 , V_281 , V_30 -> V_282 ) ||
F_75 ( V_52 , V_283 , V_30 -> V_284 ) ||
#ifdef F_120
F_75 ( V_52 , V_285 , V_30 -> V_286 ) ||
#endif
( V_30 -> V_270 != F_121 ( V_30 ) &&
F_75 ( V_52 , V_287 , F_121 ( V_30 ) ) ) ||
( V_264 &&
F_75 ( V_52 , V_288 , V_264 -> V_270 ) ) ||
F_118 ( V_52 , V_289 , F_122 ( V_30 ) ) ||
( V_30 -> V_290 &&
F_54 ( V_52 , V_291 , V_30 -> V_290 -> V_20 -> V_98 ) ) ||
( V_30 -> V_292 &&
F_54 ( V_52 , V_293 , V_30 -> V_292 ) ) ||
F_75 ( V_52 , V_294 ,
F_78 ( & V_30 -> V_295 ) ) ||
F_118 ( V_52 , V_296 , V_30 -> V_297 ) )
goto V_91;
if ( F_112 ( V_52 , V_30 ) )
goto V_91;
if ( V_30 -> V_298 ) {
if ( F_81 ( V_52 , V_299 , V_30 -> V_298 , V_30 -> V_300 ) ||
F_81 ( V_52 , V_301 , V_30 -> V_298 , V_30 -> V_250 ) )
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
F_75 ( V_52 , V_302 , F_93 ( V_30 -> V_30 . V_154 ) ) )
goto V_91;
if ( V_30 -> V_172 -> V_226 && V_30 -> V_30 . V_154 &&
V_48 & V_155 ) {
int V_83 ;
struct V_42 * V_206 ;
int V_156 = F_93 ( V_30 -> V_30 . V_154 ) ;
V_206 = F_55 ( V_52 , V_303 ) ;
if ( ! V_206 )
goto V_91;
for ( V_83 = 0 ; V_83 < V_156 ; V_83 ++ ) {
if ( F_110 ( V_52 , V_30 , V_83 , V_206 ) )
goto V_91;
}
F_56 ( V_52 , V_206 ) ;
}
if ( F_99 ( V_52 , V_30 , V_48 ) )
goto V_91;
if ( V_30 -> V_18 || F_52 ( V_30 ) ) {
if ( F_59 ( V_52 , V_30 ) < 0 )
goto V_91;
}
if ( V_30 -> V_18 &&
V_30 -> V_18 -> V_304 ) {
struct V_28 * V_305 = V_30 -> V_18 -> V_304 ( V_30 ) ;
if ( ! F_123 ( F_124 ( V_30 ) , V_305 ) ) {
int V_98 = F_125 ( F_124 ( V_30 ) , V_305 ) ;
if ( F_126 ( V_52 , V_306 , V_98 ) )
goto V_91;
}
}
if ( ! ( V_263 = F_55 ( V_52 , V_307 ) ) )
goto V_91;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_49 -> V_308 ) {
struct V_42 * V_309 ;
int V_27 ;
if ( ! ( V_309 = F_55 ( V_52 , V_49 -> V_47 ) ) )
goto V_91;
V_27 = V_49 -> V_308 ( V_52 , V_30 , V_48 ) ;
if ( V_27 == - V_310 )
F_57 ( V_52 , V_309 ) ;
else if ( V_27 < 0 )
goto V_91;
F_56 ( V_52 , V_309 ) ;
}
}
F_56 ( V_52 , V_263 ) ;
F_127 ( V_52 , V_78 ) ;
return 0 ;
V_91:
F_128 ( V_52 , V_78 ) ;
return - V_55 ;
}
static int F_129 ( struct V_51 * V_52 , struct V_311 * V_312 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
int V_314 , V_315 ;
int V_316 = 0 , V_317 ;
struct V_29 * V_30 ;
struct V_318 * V_319 ;
struct V_42 * V_320 [ V_321 + 1 ] ;
T_5 V_48 = 0 ;
int V_27 ;
int V_322 ;
V_315 = V_312 -> args [ 0 ] ;
V_317 = V_312 -> args [ 1 ] ;
V_312 -> V_261 = V_28 -> V_323 ;
V_322 = F_131 ( V_312 -> V_78 ) < sizeof( struct V_122 ) ?
sizeof( struct V_324 ) : sizeof( struct V_122 ) ;
if ( F_132 ( V_312 -> V_78 , V_322 , V_320 , V_321 , V_325 ) >= 0 ) {
if ( V_320 [ V_326 ] )
V_48 = F_133 ( V_320 [ V_326 ] ) ;
}
for ( V_314 = V_315 ; V_314 < V_327 ; V_314 ++ , V_317 = 0 ) {
V_316 = 0 ;
V_319 = & V_28 -> V_328 [ V_314 ] ;
F_134 (dev, head, index_hlist) {
if ( V_316 < V_317 )
goto V_329;
V_27 = F_113 ( V_52 , V_30 , V_330 ,
F_61 ( V_312 -> V_52 ) . V_331 ,
V_312 -> V_78 -> V_332 , 0 ,
V_333 ,
V_48 ) ;
F_135 ( ( V_27 == - V_55 ) && ( V_52 -> V_334 == 0 ) ) ;
if ( V_27 < 0 )
goto V_67;
F_136 ( V_312 , F_137 ( V_52 ) ) ;
V_329:
V_316 ++ ;
}
}
V_67:
V_312 -> args [ 1 ] = V_316 ;
V_312 -> args [ 0 ] = V_314 ;
return V_52 -> V_334 ;
}
int F_138 ( struct V_42 * * V_320 , const struct V_42 * V_319 , int V_334 )
{
return F_139 ( V_320 , V_321 , V_319 , V_334 , V_325 ) ;
}
struct V_28 * F_140 ( struct V_28 * V_335 , struct V_42 * V_320 [] )
{
struct V_28 * V_28 ;
if ( V_320 [ V_336 ] )
V_28 = F_141 ( F_133 ( V_320 [ V_336 ] ) ) ;
else if ( V_320 [ V_337 ] )
V_28 = F_142 ( F_133 ( V_320 [ V_337 ] ) ) ;
else
V_28 = F_143 ( V_335 ) ;
return V_28 ;
}
static int F_144 ( struct V_29 * V_30 , struct V_42 * V_320 [] )
{
if ( V_30 ) {
if ( V_320 [ V_299 ] &&
F_145 ( V_320 [ V_299 ] ) < V_30 -> V_298 )
return - V_338 ;
if ( V_320 [ V_301 ] &&
F_145 ( V_320 [ V_301 ] ) < V_30 -> V_298 )
return - V_338 ;
}
if ( V_320 [ V_307 ] ) {
struct V_42 * V_309 ;
int V_339 , V_27 ;
F_146 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_49 ;
if ( ! ( V_49 = F_47 ( F_147 ( V_309 ) ) ) )
return - V_340 ;
if ( ! V_49 -> V_341 )
return - V_190 ;
if ( V_49 -> V_342 ) {
V_27 = V_49 -> V_342 ( V_30 , V_309 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_148 ( struct V_29 * V_30 , struct V_42 * * V_320 )
{
const struct V_343 * V_20 = V_30 -> V_172 ;
int V_27 = - V_338 ;
if ( V_320 [ V_235 ] ) {
struct V_157 * V_344 = F_109 ( V_320 [ V_235 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_345 )
V_27 = V_20 -> V_345 ( V_30 , V_344 -> V_181 ,
V_344 -> V_224 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_320 [ V_236 ] ) {
struct V_158 * V_346 = F_109 ( V_320 [ V_236 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_347 )
V_27 = V_20 -> V_347 ( V_30 , V_346 -> V_181 , V_346 -> V_227 ,
V_346 -> V_228 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_320 [ V_238 ] ) {
struct V_210 * V_348 = F_109 ( V_320 [ V_238 ] ) ;
struct V_219 V_349 ;
V_27 = - V_190 ;
if ( V_20 -> V_226 )
V_27 = V_20 -> V_226 ( V_30 , V_348 -> V_181 , & V_349 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = - V_190 ;
if ( V_20 -> V_350 )
V_27 = V_20 -> V_350 ( V_30 , V_348 -> V_181 ,
V_349 . V_231 ,
V_348 -> V_229 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_320 [ V_237 ] ) {
struct V_160 * V_348 = F_109 ( V_320 [ V_237 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_350 )
V_27 = V_20 -> V_350 ( V_30 , V_348 -> V_181 ,
V_348 -> V_231 ,
V_348 -> V_230 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_320 [ V_239 ] ) {
struct V_159 * V_351 = F_109 ( V_320 [ V_239 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_352 )
V_27 = V_20 -> V_352 ( V_30 , V_351 -> V_181 ,
V_351 -> V_232 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_320 [ V_240 ] ) {
struct V_161 * V_353 = F_109 ( V_320 [ V_240 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_354 )
V_27 = V_20 -> V_354 ( V_30 , V_353 -> V_181 ,
V_353 -> V_233 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_320 [ V_241 ] ) {
struct V_162 * V_355 ;
V_27 = - V_190 ;
V_355 = F_109 ( V_320 [ V_241 ] ) ;
if ( V_20 -> V_356 )
V_27 = V_20 -> V_356 ( V_30 , V_355 -> V_181 ,
V_355 -> V_232 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_320 [ V_242 ] ) {
struct V_164 * V_348 = F_109 ( V_320 [ V_242 ] ) ;
V_27 = - V_190 ;
if ( V_20 -> V_357 )
V_27 = V_20 -> V_357 ( V_30 , V_348 -> V_181 , V_348 -> V_232 ) ;
if ( V_27 < 0 )
return V_27 ;
}
return V_27 ;
}
static int F_149 ( struct V_29 * V_30 , int V_270 )
{
struct V_29 * V_264 = F_44 ( V_30 ) ;
const struct V_343 * V_20 ;
int V_27 ;
if ( V_264 ) {
if ( V_264 -> V_270 == V_270 )
return 0 ;
V_20 = V_264 -> V_172 ;
if ( V_20 -> V_358 ) {
V_27 = V_20 -> V_358 ( V_264 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_190 ;
}
}
if ( V_270 ) {
V_264 = F_150 ( F_124 ( V_30 ) , V_270 ) ;
if ( ! V_264 )
return - V_338 ;
V_20 = V_264 -> V_172 ;
if ( V_20 -> V_359 ) {
V_27 = V_20 -> V_359 ( V_264 , V_30 ) ;
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
struct V_42 * * V_320 , char * V_360 , int V_361 )
{
const struct V_343 * V_20 = V_30 -> V_172 ;
int V_27 ;
if ( V_320 [ V_336 ] || V_320 [ V_337 ] ) {
struct V_28 * V_28 = F_140 ( F_124 ( V_30 ) , V_320 ) ;
if ( F_152 ( V_28 ) ) {
V_27 = F_153 ( V_28 ) ;
goto V_362;
}
if ( ! F_154 ( V_52 , V_28 -> V_363 , V_364 ) ) {
F_155 ( V_28 ) ;
V_27 = - V_365 ;
goto V_362;
}
V_27 = F_156 ( V_30 , V_28 , V_360 ) ;
F_155 ( V_28 ) ;
if ( V_27 )
goto V_362;
V_361 |= V_366 ;
}
if ( V_320 [ V_260 ] ) {
struct V_176 * V_367 ;
struct V_368 V_369 ;
if ( ! V_20 -> V_370 ) {
V_27 = - V_190 ;
goto V_362;
}
if ( ! F_157 ( V_30 ) ) {
V_27 = - V_371 ;
goto V_362;
}
V_367 = F_109 ( V_320 [ V_260 ] ) ;
V_369 . V_253 = ( unsigned long ) V_367 -> V_253 ;
V_369 . V_254 = ( unsigned long ) V_367 -> V_254 ;
V_369 . V_255 = ( unsigned short ) V_367 -> V_255 ;
V_369 . V_256 = ( unsigned char ) V_367 -> V_256 ;
V_369 . V_257 = ( unsigned char ) V_367 -> V_257 ;
V_369 . V_258 = ( unsigned char ) V_367 -> V_258 ;
V_27 = V_20 -> V_370 ( V_30 , & V_369 ) ;
if ( V_27 < 0 )
goto V_362;
V_361 |= V_372 ;
}
if ( V_320 [ V_299 ] ) {
struct V_373 * V_374 ;
int V_334 ;
V_334 = sizeof( V_375 ) + V_30 -> V_298 ;
V_374 = F_158 ( V_334 , V_15 ) ;
if ( ! V_374 ) {
V_27 = - V_376 ;
goto V_362;
}
V_374 -> V_377 = V_30 -> type ;
memcpy ( V_374 -> V_378 , F_109 ( V_320 [ V_299 ] ) ,
V_30 -> V_298 ) ;
V_27 = F_159 ( V_30 , V_374 ) ;
F_24 ( V_374 ) ;
if ( V_27 )
goto V_362;
V_361 |= V_366 ;
}
if ( V_320 [ V_278 ] ) {
V_27 = F_160 ( V_30 , F_133 ( V_320 [ V_278 ] ) ) ;
if ( V_27 < 0 )
goto V_362;
V_361 |= V_366 ;
}
if ( V_320 [ V_280 ] ) {
F_161 ( V_30 , F_133 ( V_320 [ V_280 ] ) ) ;
V_361 |= V_372 ;
}
if ( V_123 -> V_269 > 0 && V_360 [ 0 ] ) {
V_27 = F_162 ( V_30 , V_360 ) ;
if ( V_27 < 0 )
goto V_362;
V_361 |= V_366 ;
}
if ( V_320 [ V_293 ] ) {
V_27 = F_163 ( V_30 , F_109 ( V_320 [ V_293 ] ) ,
F_145 ( V_320 [ V_293 ] ) ) ;
if ( V_27 < 0 )
goto V_362;
V_361 |= V_372 ;
}
if ( V_320 [ V_301 ] ) {
F_164 ( V_30 -> V_250 , V_320 [ V_301 ] , V_30 -> V_298 ) ;
F_165 ( V_379 , V_30 ) ;
}
if ( V_123 -> V_124 || V_123 -> V_125 ) {
V_27 = F_166 ( V_30 , F_88 ( V_30 , V_123 ) ) ;
if ( V_27 < 0 )
goto V_362;
}
if ( V_320 [ V_288 ] ) {
V_27 = F_149 ( V_30 , F_133 ( V_320 [ V_288 ] ) ) ;
if ( V_27 )
goto V_362;
V_361 |= V_366 ;
}
if ( V_320 [ V_289 ] ) {
V_27 = F_167 ( V_30 , F_168 ( V_320 [ V_289 ] ) ) ;
if ( V_27 )
goto V_362;
V_361 |= V_366 ;
}
if ( V_320 [ V_272 ] ) {
unsigned long V_380 = F_133 ( V_320 [ V_272 ] ) ;
if ( V_30 -> V_273 ^ V_380 )
V_361 |= V_372 ;
V_30 -> V_273 = V_380 ;
}
if ( V_320 [ V_274 ] )
F_82 ( V_30 , F_168 ( V_320 [ V_274 ] ) ) ;
if ( V_320 [ V_276 ] ) {
unsigned char V_380 = F_168 ( V_320 [ V_276 ] ) ;
F_84 ( & V_118 ) ;
if ( V_30 -> V_277 ^ V_380 )
V_361 |= V_372 ;
V_30 -> V_277 = V_380 ;
F_85 ( & V_118 ) ;
}
if ( V_320 [ V_303 ] ) {
struct V_42 * V_206 [ V_381 + 1 ] ;
struct V_42 * V_195 ;
int V_339 ;
F_146 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_147 ( V_195 ) != V_234 ||
F_145 ( V_195 ) < V_382 ) {
V_27 = - V_338 ;
goto V_362;
}
V_27 = F_169 ( V_206 , V_381 , V_195 ,
V_383 ) ;
if ( V_27 < 0 )
goto V_362;
V_27 = F_148 ( V_30 , V_206 ) ;
if ( V_27 < 0 )
goto V_362;
V_361 |= V_372 ;
}
}
V_27 = 0 ;
if ( V_320 [ V_182 ] ) {
struct V_42 * V_258 [ V_384 + 1 ] ;
struct V_42 * V_195 ;
int V_181 ;
int V_339 ;
V_27 = - V_190 ;
if ( ! V_20 -> V_385 )
goto V_362;
F_146 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_147 ( V_195 ) != V_183 ||
F_145 ( V_195 ) < V_382 ) {
V_27 = - V_338 ;
goto V_362;
}
V_27 = F_169 ( V_258 , V_384 , V_195 ,
V_386 ) ;
if ( V_27 < 0 )
goto V_362;
if ( ! V_258 [ V_184 ] ) {
V_27 = - V_190 ;
goto V_362;
}
V_181 = F_133 ( V_258 [ V_184 ] ) ;
V_27 = V_20 -> V_385 ( V_30 , V_181 , V_258 ) ;
if ( V_27 < 0 )
goto V_362;
V_361 |= V_372 ;
}
}
V_27 = 0 ;
if ( V_320 [ V_186 ] ) {
struct V_42 * V_258 [ V_384 + 1 ] ;
V_27 = F_169 ( V_258 , V_384 ,
V_320 [ V_186 ] , V_386 ) ;
if ( V_27 < 0 )
goto V_362;
V_27 = - V_190 ;
if ( V_20 -> V_385 )
V_27 = V_20 -> V_385 ( V_30 , V_187 , V_258 ) ;
if ( V_27 < 0 )
goto V_362;
V_361 |= V_372 ;
}
if ( V_320 [ V_307 ] ) {
struct V_42 * V_309 ;
int V_339 ;
F_146 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_46 * V_49 ;
if ( ! ( V_49 = F_47 ( F_147 ( V_309 ) ) ) )
F_170 () ;
V_27 = V_49 -> V_341 ( V_30 , V_309 ) ;
if ( V_27 < 0 )
goto V_362;
V_361 |= V_372 ;
}
}
V_27 = 0 ;
if ( V_320 [ V_296 ] ) {
V_27 = F_171 ( V_30 ,
F_168 ( V_320 [ V_296 ] ) ) ;
if ( V_27 )
goto V_362;
V_361 |= V_372 ;
}
V_362:
if ( V_361 & V_366 ) {
if ( V_361 & V_372 )
F_86 ( V_30 ) ;
if ( V_27 < 0 )
F_172 ( L_3 ,
V_30 -> V_90 ) ;
}
return V_27 ;
}
static int F_173 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
struct V_122 * V_123 ;
struct V_29 * V_30 ;
int V_27 ;
struct V_42 * V_320 [ V_321 + 1 ] ;
char V_360 [ V_174 ] ;
V_27 = F_132 ( V_78 , sizeof( * V_123 ) , V_320 , V_321 , V_325 ) ;
if ( V_27 < 0 )
goto V_362;
if ( V_320 [ V_271 ] )
F_174 ( V_360 , V_320 [ V_271 ] , V_174 ) ;
else
V_360 [ 0 ] = '\0' ;
V_27 = - V_338 ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_269 > 0 )
V_30 = F_150 ( V_28 , V_123 -> V_269 ) ;
else if ( V_320 [ V_271 ] )
V_30 = F_175 ( V_28 , V_360 ) ;
else
goto V_362;
if ( V_30 == NULL ) {
V_27 = - V_371 ;
goto V_362;
}
V_27 = F_144 ( V_30 , V_320 ) ;
if ( V_27 < 0 )
goto V_362;
V_27 = F_151 ( V_52 , V_30 , V_123 , V_320 , V_360 , 0 ) ;
V_362:
return V_27 ;
}
static int F_176 ( const struct V_28 * V_28 , int V_70 )
{
struct V_29 * V_30 , * V_387 ;
F_31 ( V_31 ) ;
bool V_388 = false ;
if ( ! V_70 )
return - V_365 ;
F_32 (net, dev) {
if ( V_30 -> V_70 == V_70 ) {
const struct V_18 * V_20 ;
V_388 = true ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_190 ;
}
}
if ( ! V_388 )
return - V_371 ;
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
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
struct V_29 * V_30 ;
struct V_122 * V_123 ;
char V_360 [ V_174 ] ;
struct V_42 * V_320 [ V_321 + 1 ] ;
int V_27 ;
V_27 = F_132 ( V_78 , sizeof( * V_123 ) , V_320 , V_321 , V_325 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_320 [ V_271 ] )
F_174 ( V_360 , V_320 [ V_271 ] , V_174 ) ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_269 > 0 )
V_30 = F_150 ( V_28 , V_123 -> V_269 ) ;
else if ( V_320 [ V_271 ] )
V_30 = F_175 ( V_28 , V_360 ) ;
else if ( V_320 [ V_280 ] )
return F_176 ( V_28 , F_133 ( V_320 [ V_280 ] ) ) ;
else
return - V_338 ;
if ( ! V_30 )
return - V_371 ;
return F_178 ( V_30 ) ;
}
int F_180 ( struct V_29 * V_30 , const struct V_122 * V_123 )
{
unsigned int V_389 ;
int V_27 ;
V_389 = V_30 -> V_79 ;
if ( V_123 && ( V_123 -> V_124 || V_123 -> V_125 ) ) {
V_27 = F_181 ( V_30 , F_88 ( V_30 , V_123 ) ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_30 -> V_390 = V_391 ;
F_182 ( V_30 , V_389 , ~ 0U ) ;
return 0 ;
}
struct V_29 * F_183 ( struct V_28 * V_28 ,
const char * V_360 , unsigned char V_392 ,
const struct V_18 * V_20 , struct V_42 * V_320 [] )
{
int V_27 ;
struct V_29 * V_30 ;
unsigned int V_284 = 1 ;
unsigned int V_286 = 1 ;
if ( V_320 [ V_283 ] )
V_284 = F_133 ( V_320 [ V_283 ] ) ;
else if ( V_20 -> V_393 )
V_284 = V_20 -> V_393 () ;
if ( V_320 [ V_285 ] )
V_286 = F_133 ( V_320 [ V_285 ] ) ;
else if ( V_20 -> V_394 )
V_286 = V_20 -> V_394 () ;
V_27 = - V_376 ;
V_30 = F_184 ( V_20 -> V_395 , V_360 , V_392 ,
V_20 -> V_22 , V_284 , V_286 ) ;
if ( ! V_30 )
goto V_27;
F_185 ( V_30 , V_28 ) ;
V_30 -> V_18 = V_20 ;
V_30 -> V_390 = V_396 ;
if ( V_320 [ V_278 ] )
V_30 -> V_279 = F_133 ( V_320 [ V_278 ] ) ;
if ( V_320 [ V_299 ] ) {
memcpy ( V_30 -> V_300 , F_109 ( V_320 [ V_299 ] ) ,
F_145 ( V_320 [ V_299 ] ) ) ;
V_30 -> V_397 = V_398 ;
}
if ( V_320 [ V_301 ] )
memcpy ( V_30 -> V_250 , F_109 ( V_320 [ V_301 ] ) ,
F_145 ( V_320 [ V_301 ] ) ) ;
if ( V_320 [ V_272 ] )
V_30 -> V_273 = F_133 ( V_320 [ V_272 ] ) ;
if ( V_320 [ V_274 ] )
F_82 ( V_30 , F_168 ( V_320 [ V_274 ] ) ) ;
if ( V_320 [ V_276 ] )
V_30 -> V_277 = F_168 ( V_320 [ V_276 ] ) ;
if ( V_320 [ V_280 ] )
F_161 ( V_30 , F_133 ( V_320 [ V_280 ] ) ) ;
return V_30 ;
V_27:
return F_186 ( V_27 ) ;
}
static int F_187 ( const struct V_51 * V_52 ,
struct V_28 * V_28 , int V_70 ,
struct V_122 * V_123 ,
struct V_42 * * V_320 )
{
struct V_29 * V_30 , * V_387 ;
int V_27 ;
F_177 (net, dev, aux) {
if ( V_30 -> V_70 == V_70 ) {
V_27 = F_151 ( V_52 , V_30 , V_123 , V_320 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_188 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_399 = NULL ;
struct V_29 * V_30 ;
struct V_29 * V_40 = NULL ;
struct V_122 * V_123 ;
char V_19 [ V_400 ] ;
char V_360 [ V_174 ] ;
struct V_42 * V_320 [ V_321 + 1 ] ;
struct V_42 * V_65 [ V_401 + 1 ] ;
unsigned char V_392 = V_402 ;
int V_27 ;
#ifdef F_189
V_403:
#endif
V_27 = F_132 ( V_78 , sizeof( * V_123 ) , V_320 , V_321 , V_325 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_320 [ V_271 ] )
F_174 ( V_360 , V_320 [ V_271 ] , V_174 ) ;
else
V_360 [ 0 ] = '\0' ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_269 > 0 )
V_30 = F_150 ( V_28 , V_123 -> V_269 ) ;
else {
if ( V_360 [ 0 ] )
V_30 = F_175 ( V_28 , V_360 ) ;
else
V_30 = NULL ;
}
if ( V_30 ) {
V_40 = F_44 ( V_30 ) ;
if ( V_40 )
V_399 = V_40 -> V_18 ;
}
V_27 = F_144 ( V_30 , V_320 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_320 [ V_66 ] ) {
V_27 = F_169 ( V_65 , V_401 ,
V_320 [ V_66 ] , V_404 ) ;
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
struct V_42 * V_195 [ V_20 ? V_20 -> V_405 + 1 : 1 ] ;
struct V_42 * V_406 [ V_399 ? V_399 -> V_407 + 1 : 1 ] ;
struct V_42 * * V_59 = NULL ;
struct V_42 * * V_53 = NULL ;
struct V_28 * V_408 , * V_305 = NULL ;
if ( V_20 ) {
if ( V_20 -> V_405 && V_65 [ V_63 ] ) {
V_27 = F_169 ( V_195 , V_20 -> V_405 ,
V_65 [ V_63 ] ,
V_20 -> V_409 ) ;
if ( V_27 < 0 )
return V_27 ;
V_59 = V_195 ;
}
if ( V_20 -> V_410 ) {
V_27 = V_20 -> V_410 ( V_320 , V_59 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_399 ) {
if ( V_399 -> V_407 &&
V_65 [ V_57 ] ) {
V_27 = F_169 ( V_406 ,
V_399 -> V_407 ,
V_65 [ V_57 ] ,
V_399 -> V_411 ) ;
if ( V_27 < 0 )
return V_27 ;
V_53 = V_406 ;
}
if ( V_399 -> V_412 ) {
V_27 = V_399 -> V_412 ( V_320 , V_53 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_30 ) {
int V_361 = 0 ;
if ( V_78 -> V_413 & V_414 )
return - V_21 ;
if ( V_78 -> V_413 & V_415 )
return - V_190 ;
if ( V_65 [ V_63 ] ) {
if ( ! V_20 || V_20 != V_30 -> V_18 ||
! V_20 -> V_416 )
return - V_190 ;
V_27 = V_20 -> V_416 ( V_30 , V_320 , V_59 ) ;
if ( V_27 < 0 )
return V_27 ;
V_361 |= V_372 ;
}
if ( V_65 [ V_57 ] ) {
if ( ! V_399 || ! V_399 -> V_417 )
return - V_190 ;
V_27 = V_399 -> V_417 ( V_40 , V_30 ,
V_320 , V_53 ) ;
if ( V_27 < 0 )
return V_27 ;
V_361 |= V_372 ;
}
return F_151 ( V_52 , V_30 , V_123 , V_320 , V_360 , V_361 ) ;
}
if ( ! ( V_78 -> V_413 & V_418 ) ) {
if ( V_123 -> V_269 == 0 && V_320 [ V_280 ] )
return F_187 ( V_52 , V_28 ,
F_133 ( V_320 [ V_280 ] ) ,
V_123 , V_320 ) ;
return - V_371 ;
}
if ( V_320 [ V_260 ] || V_320 [ V_288 ] || V_320 [ V_419 ] )
return - V_190 ;
if ( ! V_20 ) {
#ifdef F_189
if ( V_19 [ 0 ] ) {
F_3 () ;
F_190 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_403;
}
#endif
return - V_190 ;
}
if ( ! V_20 -> V_22 )
return - V_190 ;
if ( ! V_360 [ 0 ] ) {
snprintf ( V_360 , V_174 , L_5 , V_20 -> V_19 ) ;
V_392 = V_420 ;
}
V_408 = F_140 ( V_28 , V_320 ) ;
if ( F_152 ( V_408 ) )
return F_153 ( V_408 ) ;
V_27 = - V_365 ;
if ( ! F_154 ( V_52 , V_408 -> V_363 , V_364 ) )
goto V_67;
if ( V_320 [ V_306 ] ) {
int V_98 = F_191 ( V_320 [ V_306 ] ) ;
V_305 = F_192 ( V_408 , V_98 ) ;
if ( ! V_305 ) {
V_27 = - V_338 ;
goto V_67;
}
V_27 = - V_365 ;
if ( ! F_154 ( V_52 , V_305 -> V_363 , V_364 ) )
goto V_67;
}
V_30 = F_183 ( V_305 ? : V_408 , V_360 ,
V_392 , V_20 , V_320 ) ;
if ( F_152 ( V_30 ) ) {
V_27 = F_153 ( V_30 ) ;
goto V_67;
}
V_30 -> V_270 = V_123 -> V_269 ;
if ( V_20 -> V_421 ) {
V_27 = V_20 -> V_421 ( V_305 ? : V_28 , V_30 , V_320 , V_59 ) ;
if ( V_27 < 0 ) {
if ( V_30 -> V_422 == V_423 )
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
goto V_424;
if ( V_305 ) {
V_27 = F_156 ( V_30 , V_408 , V_360 ) ;
if ( V_27 < 0 )
goto V_424;
}
V_67:
if ( V_305 )
F_155 ( V_305 ) ;
F_155 ( V_408 ) ;
return V_27 ;
V_424:
if ( V_20 -> V_421 ) {
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
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
struct V_122 * V_123 ;
char V_360 [ V_174 ] ;
struct V_42 * V_320 [ V_321 + 1 ] ;
struct V_29 * V_30 = NULL ;
struct V_51 * V_425 ;
int V_27 ;
T_5 V_48 = 0 ;
V_27 = F_132 ( V_78 , sizeof( * V_123 ) , V_320 , V_321 , V_325 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_320 [ V_271 ] )
F_174 ( V_360 , V_320 [ V_271 ] , V_174 ) ;
if ( V_320 [ V_326 ] )
V_48 = F_133 ( V_320 [ V_326 ] ) ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_269 > 0 )
V_30 = F_150 ( V_28 , V_123 -> V_269 ) ;
else if ( V_320 [ V_271 ] )
V_30 = F_175 ( V_28 , V_360 ) ;
else
return - V_338 ;
if ( V_30 == NULL )
return - V_371 ;
V_425 = F_197 ( F_95 ( V_30 , V_48 ) , V_15 ) ;
if ( V_425 == NULL )
return - V_16 ;
V_27 = F_113 ( V_425 , V_30 , V_330 , F_61 ( V_52 ) . V_331 ,
V_78 -> V_332 , 0 , 0 , V_48 ) ;
if ( V_27 < 0 ) {
F_135 ( V_27 == - V_55 ) ;
F_198 ( V_425 ) ;
} else
V_27 = F_65 ( V_425 , V_28 , F_61 ( V_52 ) . V_331 ) ;
return V_27 ;
}
static T_9 F_199 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
struct V_29 * V_30 ;
struct V_42 * V_320 [ V_321 + 1 ] ;
T_5 V_48 = 0 ;
T_9 V_426 = 0 ;
int V_322 ;
V_322 = F_131 ( V_78 ) < sizeof( struct V_122 ) ?
sizeof( struct V_324 ) : sizeof( struct V_122 ) ;
if ( F_132 ( V_78 , V_322 , V_320 , V_321 , V_325 ) >= 0 ) {
if ( V_320 [ V_326 ] )
V_48 = F_133 ( V_320 [ V_326 ] ) ;
}
if ( ! V_48 )
return V_427 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_426 = F_200 ( T_9 , V_426 ,
F_95 ( V_30 ,
V_48 ) ) ;
}
return V_426 ;
}
static int F_201 ( struct V_51 * V_52 , struct V_311 * V_312 )
{
int V_316 ;
int V_317 = V_312 -> V_47 ;
if ( V_317 == 0 )
V_317 = 1 ;
for ( V_316 = 1 ; V_316 <= V_9 ; V_316 ++ ) {
int type = V_312 -> V_78 -> V_428 - V_4 ;
if ( V_316 < V_317 || V_316 == V_429 )
continue;
if ( V_10 [ V_316 ] == NULL ||
V_10 [ V_316 ] [ type ] . V_13 == NULL )
continue;
if ( V_316 > V_317 ) {
memset ( & V_312 -> args [ 0 ] , 0 , sizeof( V_312 -> args ) ) ;
V_312 -> V_430 = 0 ;
V_312 -> V_261 = 0 ;
}
if ( V_10 [ V_316 ] [ type ] . V_13 ( V_52 , V_312 ) )
break;
}
V_312 -> V_47 = V_316 ;
return V_52 -> V_334 ;
}
struct V_51 * F_202 ( int type , struct V_29 * V_30 ,
unsigned int V_262 , T_6 V_79 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
struct V_51 * V_52 ;
int V_27 = - V_16 ;
T_4 V_431 ;
V_52 = F_197 ( ( V_431 = F_95 ( V_30 , 0 ) ) , V_79 ) ;
if ( V_52 == NULL )
goto V_362;
V_27 = F_113 ( V_52 , V_30 , type , 0 , 0 , V_262 , 0 , 0 ) ;
if ( V_27 < 0 ) {
F_135 ( V_27 == - V_55 ) ;
F_198 ( V_52 ) ;
goto V_362;
}
return V_52 ;
V_362:
if ( V_27 < 0 )
F_70 ( V_28 , V_432 , V_27 ) ;
return NULL ;
}
void F_203 ( struct V_51 * V_52 , struct V_29 * V_30 , T_6 V_79 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
F_67 ( V_52 , V_28 , 0 , V_432 , NULL , V_79 ) ;
}
void F_204 ( int type , struct V_29 * V_30 , unsigned int V_262 ,
T_6 V_79 )
{
struct V_51 * V_52 ;
if ( V_30 -> V_422 != V_433 )
return;
V_52 = F_202 ( type , V_30 , V_262 , V_79 ) ;
if ( V_52 )
F_203 ( V_52 , V_30 , V_79 ) ;
}
static int F_205 ( struct V_51 * V_52 ,
struct V_29 * V_30 ,
T_10 * V_434 , T_9 V_435 , T_5 V_69 , T_5 V_261 ,
int type , unsigned int V_79 ,
int V_436 , T_9 V_437 )
{
struct V_77 * V_78 ;
struct V_438 * V_439 ;
V_78 = F_115 ( V_52 , V_69 , V_261 , type , sizeof( * V_439 ) , V_436 ) ;
if ( ! V_78 )
return - V_55 ;
V_439 = F_116 ( V_78 ) ;
V_439 -> V_440 = V_441 ;
V_439 -> V_442 = 0 ;
V_439 -> V_443 = 0 ;
V_439 -> V_444 = V_79 ;
V_439 -> V_445 = 0 ;
V_439 -> V_446 = V_30 -> V_270 ;
V_439 -> V_437 = V_437 ;
if ( F_81 ( V_52 , V_447 , V_448 , V_434 ) )
goto V_91;
if ( V_435 )
if ( F_81 ( V_52 , V_449 , sizeof( T_9 ) , & V_435 ) )
goto V_91;
F_127 ( V_52 , V_78 ) ;
return 0 ;
V_91:
F_128 ( V_52 , V_78 ) ;
return - V_55 ;
}
static inline T_4 F_206 ( void )
{
return F_96 ( sizeof( struct V_438 ) ) + F_45 ( V_448 ) ;
}
static void F_207 ( struct V_29 * V_30 , T_10 * V_434 , T_9 V_435 , int type ,
T_9 V_437 )
{
struct V_28 * V_28 = F_124 ( V_30 ) ;
struct V_51 * V_52 ;
int V_27 = - V_16 ;
V_52 = F_197 ( F_206 () , V_450 ) ;
if ( ! V_52 )
goto V_362;
V_27 = F_205 ( V_52 , V_30 , V_434 , V_435 ,
0 , 0 , type , V_451 , 0 , V_437 ) ;
if ( V_27 < 0 ) {
F_198 ( V_52 ) ;
goto V_362;
}
F_67 ( V_52 , V_28 , 0 , V_452 , NULL , V_450 ) ;
return;
V_362:
F_70 ( V_28 , V_452 , V_27 ) ;
}
int F_208 ( struct V_438 * V_439 ,
struct V_42 * V_320 [] ,
struct V_29 * V_30 ,
const unsigned char * V_434 , T_9 V_435 ,
T_9 V_79 )
{
int V_27 = - V_338 ;
if ( V_439 -> V_437 && ! ( V_439 -> V_437 & V_453 ) ) {
F_209 ( L_6 , V_30 -> V_90 ) ;
return V_27 ;
}
if ( V_435 ) {
F_209 ( L_7 , V_30 -> V_90 ) ;
return V_27 ;
}
if ( F_210 ( V_434 ) || F_211 ( V_434 ) )
V_27 = F_212 ( V_30 , V_434 ) ;
else if ( F_213 ( V_434 ) )
V_27 = F_214 ( V_30 , V_434 ) ;
if ( V_27 == - V_21 && ! ( V_79 & V_414 ) )
V_27 = 0 ;
return V_27 ;
}
static int F_215 ( struct V_42 * V_454 , T_9 * V_455 )
{
T_9 V_435 = 0 ;
if ( V_454 ) {
if ( F_145 ( V_454 ) != sizeof( T_9 ) ) {
F_209 ( L_8 ) ;
return - V_338 ;
}
V_435 = F_216 ( V_454 ) ;
if ( ! V_435 || V_435 >= V_456 ) {
F_209 ( L_9 ,
V_435 ) ;
return - V_338 ;
}
}
* V_455 = V_435 ;
return 0 ;
}
static int F_217 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
struct V_438 * V_439 ;
struct V_42 * V_320 [ V_457 + 1 ] ;
struct V_29 * V_30 ;
T_10 * V_434 ;
T_9 V_435 ;
int V_27 ;
V_27 = F_132 ( V_78 , sizeof( * V_439 ) , V_320 , V_457 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_439 = F_116 ( V_78 ) ;
if ( V_439 -> V_446 == 0 ) {
F_209 ( L_10 ) ;
return - V_338 ;
}
V_30 = F_150 ( V_28 , V_439 -> V_446 ) ;
if ( V_30 == NULL ) {
F_209 ( L_11 ) ;
return - V_371 ;
}
if ( ! V_320 [ V_447 ] || F_145 ( V_320 [ V_447 ] ) != V_448 ) {
F_209 ( L_12 ) ;
return - V_338 ;
}
V_434 = F_109 ( V_320 [ V_447 ] ) ;
V_27 = F_215 ( V_320 [ V_449 ] , & V_435 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_190 ;
if ( ( ! V_439 -> V_444 || V_439 -> V_444 & V_458 ) &&
( V_30 -> V_459 & V_460 ) ) {
struct V_29 * V_461 = F_44 ( V_30 ) ;
const struct V_343 * V_20 = V_461 -> V_172 ;
V_27 = V_20 -> V_462 ( V_439 , V_320 , V_30 , V_434 , V_435 ,
V_78 -> V_413 ) ;
if ( V_27 )
goto V_67;
else
V_439 -> V_444 &= ~ V_458 ;
}
if ( ( V_439 -> V_444 & V_451 ) ) {
if ( V_30 -> V_172 -> V_462 )
V_27 = V_30 -> V_172 -> V_462 ( V_439 , V_320 , V_30 , V_434 ,
V_435 ,
V_78 -> V_413 ) ;
else
V_27 = F_208 ( V_439 , V_320 , V_30 , V_434 , V_435 ,
V_78 -> V_413 ) ;
if ( ! V_27 ) {
F_207 ( V_30 , V_434 , V_435 , V_463 ,
V_439 -> V_437 ) ;
V_439 -> V_444 &= ~ V_451 ;
}
}
V_67:
return V_27 ;
}
int F_218 ( struct V_438 * V_439 ,
struct V_42 * V_320 [] ,
struct V_29 * V_30 ,
const unsigned char * V_434 , T_9 V_435 )
{
int V_27 = - V_338 ;
if ( ! ( V_439 -> V_437 & V_453 ) ) {
F_209 ( L_6 , V_30 -> V_90 ) ;
return V_27 ;
}
if ( F_210 ( V_434 ) || F_211 ( V_434 ) )
V_27 = F_219 ( V_30 , V_434 ) ;
else if ( F_213 ( V_434 ) )
V_27 = F_220 ( V_30 , V_434 ) ;
return V_27 ;
}
static int F_221 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
struct V_438 * V_439 ;
struct V_42 * V_320 [ V_457 + 1 ] ;
struct V_29 * V_30 ;
int V_27 = - V_338 ;
T_11 * V_434 ;
T_9 V_435 ;
if ( ! F_222 ( V_52 , V_364 ) )
return - V_365 ;
V_27 = F_132 ( V_78 , sizeof( * V_439 ) , V_320 , V_457 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_439 = F_116 ( V_78 ) ;
if ( V_439 -> V_446 == 0 ) {
F_209 ( L_13 ) ;
return - V_338 ;
}
V_30 = F_150 ( V_28 , V_439 -> V_446 ) ;
if ( V_30 == NULL ) {
F_209 ( L_14 ) ;
return - V_371 ;
}
if ( ! V_320 [ V_447 ] || F_145 ( V_320 [ V_447 ] ) != V_448 ) {
F_209 ( L_15 ) ;
return - V_338 ;
}
V_434 = F_109 ( V_320 [ V_447 ] ) ;
V_27 = F_215 ( V_320 [ V_449 ] , & V_435 ) ;
if ( V_27 )
return V_27 ;
V_27 = - V_190 ;
if ( ( ! V_439 -> V_444 || V_439 -> V_444 & V_458 ) &&
( V_30 -> V_459 & V_460 ) ) {
struct V_29 * V_461 = F_44 ( V_30 ) ;
const struct V_343 * V_20 = V_461 -> V_172 ;
if ( V_20 -> V_464 )
V_27 = V_20 -> V_464 ( V_439 , V_320 , V_30 , V_434 , V_435 ) ;
if ( V_27 )
goto V_67;
else
V_439 -> V_444 &= ~ V_458 ;
}
if ( V_439 -> V_444 & V_451 ) {
if ( V_30 -> V_172 -> V_464 )
V_27 = V_30 -> V_172 -> V_464 ( V_439 , V_320 , V_30 , V_434 ,
V_435 ) ;
else
V_27 = F_218 ( V_439 , V_320 , V_30 , V_434 , V_435 ) ;
if ( ! V_27 ) {
F_207 ( V_30 , V_434 , V_435 , V_465 ,
V_439 -> V_437 ) ;
V_439 -> V_444 &= ~ V_451 ;
}
}
V_67:
return V_27 ;
}
static int F_223 ( struct V_51 * V_52 ,
struct V_311 * V_312 ,
struct V_29 * V_30 ,
int * V_316 ,
struct V_466 * V_25 )
{
struct V_467 * V_468 ;
int V_27 ;
T_5 V_331 , V_261 ;
V_331 = F_61 ( V_312 -> V_52 ) . V_331 ;
V_261 = V_312 -> V_78 -> V_332 ;
F_26 (ha, &list->list, list) {
if ( * V_316 < V_312 -> args [ 0 ] )
goto V_469;
V_27 = F_205 ( V_52 , V_30 , V_468 -> V_434 , 0 ,
V_331 , V_261 ,
V_463 , V_451 ,
V_333 , V_453 ) ;
if ( V_27 < 0 )
return V_27 ;
V_469:
* V_316 += 1 ;
}
return 0 ;
}
int F_224 ( struct V_51 * V_52 ,
struct V_311 * V_312 ,
struct V_29 * V_30 ,
struct V_29 * V_470 ,
int V_316 )
{
int V_27 ;
F_225 ( V_30 ) ;
V_27 = F_223 ( V_52 , V_312 , V_30 , & V_316 , & V_30 -> V_471 ) ;
if ( V_27 )
goto V_67;
F_223 ( V_52 , V_312 , V_30 , & V_316 , & V_30 -> V_472 ) ;
V_67:
F_226 ( V_30 ) ;
V_312 -> args [ 1 ] = V_27 ;
return V_316 ;
}
static int F_227 ( struct V_51 * V_52 , struct V_311 * V_312 )
{
struct V_29 * V_30 ;
struct V_42 * V_320 [ V_321 + 1 ] ;
struct V_29 * V_461 = NULL ;
const struct V_343 * V_20 = NULL ;
const struct V_343 * V_473 = NULL ;
struct V_122 * V_123 = F_116 ( V_312 -> V_78 ) ;
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
int V_474 = 0 ;
int V_475 = 0 ;
int V_316 = 0 ;
if ( F_132 ( V_312 -> V_78 , sizeof( struct V_122 ) , V_320 , V_321 ,
V_325 ) == 0 ) {
if ( V_320 [ V_288 ] )
V_475 = F_133 ( V_320 [ V_288 ] ) ;
}
V_474 = V_123 -> V_269 ;
if ( V_475 ) {
V_461 = F_150 ( V_28 , V_475 ) ;
if ( ! V_461 )
return - V_371 ;
V_20 = V_461 -> V_172 ;
}
V_312 -> args [ 1 ] = 0 ;
F_32 (net, dev) {
if ( V_474 && ( V_30 -> V_270 != V_474 ) )
continue;
if ( ! V_475 ) {
if ( V_30 -> V_459 & V_460 ) {
V_461 = F_44 ( V_30 ) ;
V_473 = V_461 -> V_172 ;
}
} else {
if ( V_30 != V_461 &&
! ( V_30 -> V_459 & V_460 ) )
continue;
if ( V_461 != F_44 ( V_30 ) &&
! ( V_30 -> V_459 & V_476 ) )
continue;
V_473 = V_20 ;
}
if ( V_30 -> V_459 & V_460 ) {
if ( V_473 && V_473 -> V_477 )
V_316 = V_473 -> V_477 ( V_52 , V_312 , V_461 , V_30 ,
V_316 ) ;
}
if ( V_312 -> args [ 1 ] == - V_55 )
break;
if ( V_30 -> V_172 -> V_477 )
V_316 = V_30 -> V_172 -> V_477 ( V_52 , V_312 , V_30 , NULL ,
V_316 ) ;
else
V_316 = F_224 ( V_52 , V_312 , V_30 , NULL , V_316 ) ;
if ( V_312 -> args [ 1 ] == - V_55 )
break;
V_473 = NULL ;
}
V_312 -> args [ 0 ] = V_316 ;
return V_52 -> V_334 ;
}
static int F_228 ( struct V_51 * V_52 , T_5 V_79 , T_5 V_478 ,
unsigned int V_479 , unsigned int V_480 )
{
if ( V_478 & V_480 )
return F_118 ( V_52 , V_479 , ! ! ( V_79 & V_480 ) ) ;
return 0 ;
}
int F_229 ( struct V_51 * V_52 , T_5 V_69 , T_5 V_261 ,
struct V_29 * V_30 , T_9 V_481 ,
T_5 V_79 , T_5 V_478 , int V_436 ,
T_5 V_482 ,
int (* F_230)( struct V_51 * V_52 ,
struct V_29 * V_30 ,
T_5 V_482 ) )
{
struct V_77 * V_78 ;
struct V_122 * V_123 ;
struct V_42 * V_483 ;
struct V_42 * V_484 ;
T_10 V_114 = F_119 ( V_30 ) ? V_30 -> V_114 : V_275 ;
struct V_29 * V_461 = F_44 ( V_30 ) ;
int V_27 = 0 ;
V_78 = F_115 ( V_52 , V_69 , V_261 , V_330 , sizeof( * V_123 ) , V_436 ) ;
if ( V_78 == NULL )
return - V_55 ;
V_123 = F_116 ( V_78 ) ;
V_123 -> V_265 = V_441 ;
V_123 -> V_267 = 0 ;
V_123 -> V_268 = V_30 -> type ;
V_123 -> V_269 = V_30 -> V_270 ;
V_123 -> V_124 = F_117 ( V_30 ) ;
V_123 -> V_125 = 0 ;
if ( F_54 ( V_52 , V_271 , V_30 -> V_90 ) ||
F_75 ( V_52 , V_278 , V_30 -> V_279 ) ||
F_118 ( V_52 , V_274 , V_114 ) ||
( V_461 &&
F_75 ( V_52 , V_288 , V_461 -> V_270 ) ) ||
( V_30 -> V_298 &&
F_81 ( V_52 , V_299 , V_30 -> V_298 , V_30 -> V_300 ) ) ||
( V_30 -> V_270 != F_121 ( V_30 ) &&
F_75 ( V_52 , V_287 , F_121 ( V_30 ) ) ) )
goto V_91;
V_483 = F_55 ( V_52 , V_307 ) ;
if ( ! V_483 )
goto V_91;
if ( F_231 ( V_52 , V_485 , V_486 ) ) {
F_57 ( V_52 , V_483 ) ;
goto V_91;
}
if ( V_481 != V_487 ) {
if ( F_231 ( V_52 , V_488 , V_481 ) ) {
F_57 ( V_52 , V_483 ) ;
goto V_91;
}
}
if ( F_230 ) {
V_27 = F_230 ( V_52 , V_30 , V_482 ) ;
if ( V_27 ) {
F_57 ( V_52 , V_483 ) ;
goto V_91;
}
}
F_56 ( V_52 , V_483 ) ;
V_484 = F_55 ( V_52 , V_419 | V_489 ) ;
if ( ! V_484 )
goto V_91;
if ( F_228 ( V_52 , V_79 , V_478 ,
V_490 , V_491 ) ||
F_228 ( V_52 , V_79 , V_478 ,
V_492 , V_493 ) ||
F_228 ( V_52 , V_79 , V_478 ,
V_494 ,
V_495 ) ||
F_228 ( V_52 , V_79 , V_478 ,
V_496 , V_497 ) ||
F_228 ( V_52 , V_79 , V_478 ,
V_498 , V_499 ) ||
F_228 ( V_52 , V_79 , V_478 ,
V_500 , V_501 ) ||
F_228 ( V_52 , V_79 , V_478 ,
V_502 , V_503 ) ||
F_228 ( V_52 , V_79 , V_478 ,
V_504 , V_505 ) ) {
F_57 ( V_52 , V_484 ) ;
goto V_91;
}
F_56 ( V_52 , V_484 ) ;
F_127 ( V_52 , V_78 ) ;
return 0 ;
V_91:
F_128 ( V_52 , V_78 ) ;
return V_27 ? V_27 : - V_55 ;
}
static int F_232 ( struct V_51 * V_52 , struct V_311 * V_312 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
struct V_29 * V_30 ;
int V_316 = 0 ;
T_5 V_331 = F_61 ( V_312 -> V_52 ) . V_331 ;
T_5 V_261 = V_312 -> V_78 -> V_332 ;
T_5 V_482 = 0 ;
int V_27 ;
if ( F_131 ( V_312 -> V_78 ) > sizeof( struct V_122 ) ) {
struct V_42 * V_506 ;
V_506 = F_233 ( V_312 -> V_78 , sizeof( struct V_122 ) ,
V_326 ) ;
if ( V_506 ) {
if ( F_145 ( V_506 ) < sizeof( V_482 ) )
return - V_338 ;
V_482 = F_133 ( V_506 ) ;
}
}
F_234 () ;
F_235 (net, dev) {
const struct V_343 * V_20 = V_30 -> V_172 ;
struct V_29 * V_461 = F_44 ( V_30 ) ;
if ( V_461 && V_461 -> V_172 -> V_507 ) {
if ( V_316 >= V_312 -> args [ 0 ] ) {
V_27 = V_461 -> V_172 -> V_507 (
V_52 , V_331 , V_261 , V_30 ,
V_482 , V_333 ) ;
if ( V_27 < 0 && V_27 != - V_190 )
break;
}
V_316 ++ ;
}
if ( V_20 -> V_507 ) {
if ( V_316 >= V_312 -> args [ 0 ] ) {
V_27 = V_20 -> V_507 ( V_52 , V_331 ,
V_261 , V_30 ,
V_482 ,
V_333 ) ;
if ( V_27 < 0 && V_27 != - V_190 )
break;
}
V_316 ++ ;
}
}
F_236 () ;
V_312 -> args [ 0 ] = V_316 ;
return V_52 -> V_334 ;
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
if ( ! V_30 -> V_172 -> V_507 )
return 0 ;
V_52 = F_197 ( F_237 () , V_450 ) ;
if ( ! V_52 ) {
V_27 = - V_376 ;
goto V_362;
}
V_27 = V_30 -> V_172 -> V_507 ( V_52 , 0 , 0 , V_30 , 0 , 0 ) ;
if ( V_27 < 0 )
goto V_362;
if ( ! V_52 -> V_334 )
goto V_362;
F_67 ( V_52 , V_28 , 0 , V_432 , NULL , V_450 ) ;
return 0 ;
V_362:
F_135 ( V_27 == - V_55 ) ;
F_198 ( V_52 ) ;
if ( V_27 )
F_70 ( V_28 , V_432 , V_27 ) ;
return V_27 ;
}
static int F_239 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
struct V_122 * V_123 ;
struct V_29 * V_30 ;
struct V_42 * V_508 , * V_195 = NULL ;
int V_339 , V_27 = - V_190 ;
T_9 V_79 = 0 ;
bool V_509 = false ;
if ( F_131 ( V_78 ) < sizeof( * V_123 ) )
return - V_338 ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_265 != V_441 )
return - V_510 ;
V_30 = F_150 ( V_28 , V_123 -> V_269 ) ;
if ( ! V_30 ) {
F_209 ( L_16 ) ;
return - V_371 ;
}
V_508 = F_233 ( V_78 , sizeof( struct V_122 ) , V_307 ) ;
if ( V_508 ) {
F_146 (attr, br_spec, rem) {
if ( F_147 ( V_195 ) == V_485 ) {
if ( F_145 ( V_195 ) < sizeof( V_79 ) )
return - V_338 ;
V_509 = true ;
V_79 = F_216 ( V_195 ) ;
break;
}
}
}
if ( ! V_79 || ( V_79 & V_511 ) ) {
struct V_29 * V_461 = F_44 ( V_30 ) ;
if ( ! V_461 || ! V_461 -> V_172 -> V_512 ) {
V_27 = - V_190 ;
goto V_67;
}
V_27 = V_461 -> V_172 -> V_512 ( V_30 , V_78 , V_79 ) ;
if ( V_27 )
goto V_67;
V_79 &= ~ V_511 ;
}
if ( ( V_79 & V_486 ) ) {
if ( ! V_30 -> V_172 -> V_512 )
V_27 = - V_190 ;
else
V_27 = V_30 -> V_172 -> V_512 ( V_30 , V_78 ,
V_79 ) ;
if ( ! V_27 ) {
V_79 &= ~ V_486 ;
V_27 = F_238 ( V_30 ) ;
}
}
if ( V_509 )
memcpy ( F_109 ( V_195 ) , & V_79 , sizeof( V_79 ) ) ;
V_67:
return V_27 ;
}
static int F_240 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
struct V_122 * V_123 ;
struct V_29 * V_30 ;
struct V_42 * V_508 , * V_195 = NULL ;
int V_339 , V_27 = - V_190 ;
T_9 V_79 = 0 ;
bool V_509 = false ;
if ( F_131 ( V_78 ) < sizeof( * V_123 ) )
return - V_338 ;
V_123 = F_116 ( V_78 ) ;
if ( V_123 -> V_265 != V_441 )
return - V_510 ;
V_30 = F_150 ( V_28 , V_123 -> V_269 ) ;
if ( ! V_30 ) {
F_209 ( L_16 ) ;
return - V_371 ;
}
V_508 = F_233 ( V_78 , sizeof( struct V_122 ) , V_307 ) ;
if ( V_508 ) {
F_146 (attr, br_spec, rem) {
if ( F_147 ( V_195 ) == V_485 ) {
if ( F_145 ( V_195 ) < sizeof( V_79 ) )
return - V_338 ;
V_509 = true ;
V_79 = F_216 ( V_195 ) ;
break;
}
}
}
if ( ! V_79 || ( V_79 & V_511 ) ) {
struct V_29 * V_461 = F_44 ( V_30 ) ;
if ( ! V_461 || ! V_461 -> V_172 -> V_513 ) {
V_27 = - V_190 ;
goto V_67;
}
V_27 = V_461 -> V_172 -> V_513 ( V_30 , V_78 , V_79 ) ;
if ( V_27 )
goto V_67;
V_79 &= ~ V_511 ;
}
if ( ( V_79 & V_486 ) ) {
if ( ! V_30 -> V_172 -> V_513 )
V_27 = - V_190 ;
else
V_27 = V_30 -> V_172 -> V_513 ( V_30 , V_78 ,
V_79 ) ;
if ( ! V_27 ) {
V_79 &= ~ V_486 ;
V_27 = F_238 ( V_30 ) ;
}
}
if ( V_509 )
memcpy ( F_109 ( V_195 ) , & V_79 , sizeof( V_79 ) ) ;
V_67:
return V_27 ;
}
static int F_241 ( struct V_51 * V_52 , struct V_77 * V_78 )
{
struct V_28 * V_28 = F_130 ( V_52 -> V_313 ) ;
T_1 V_11 ;
int V_19 ;
int V_47 ;
int type ;
int V_27 ;
type = V_78 -> V_428 ;
if ( type > V_514 )
return - V_190 ;
type -= V_4 ;
if ( F_131 ( V_78 ) < sizeof( struct V_324 ) )
return 0 ;
V_47 = ( (struct V_324 * ) F_116 ( V_78 ) ) -> V_515 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_242 ( V_52 , V_364 ) )
return - V_365 ;
if ( V_19 == 2 && V_78 -> V_413 & V_516 ) {
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
F_204 ( V_330 , V_30 , 0 , V_15 ) ;
break;
}
return V_538 ;
}
static int T_12 F_248 ( struct V_28 * V_28 )
{
struct V_72 * V_313 ;
struct V_539 V_540 = {
. V_541 = V_542 ,
. V_543 = F_244 ,
. V_544 = & V_1 ,
. V_79 = V_545 ,
} ;
V_313 = F_249 ( V_28 , V_546 , & V_540 ) ;
if ( ! V_313 )
return - V_376 ;
V_28 -> V_73 = V_313 ;
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
F_20 ( V_12 , V_330 , F_188 , NULL , NULL ) ;
F_20 ( V_12 , V_551 , F_179 , NULL , NULL ) ;
F_20 ( V_12 , V_552 , NULL , F_201 , NULL ) ;
F_20 ( V_12 , V_553 , NULL , F_201 , NULL ) ;
F_20 ( V_554 , V_463 , F_217 , NULL , NULL ) ;
F_20 ( V_554 , V_465 , F_221 , NULL , NULL ) ;
F_20 ( V_554 , V_555 , NULL , F_227 , NULL ) ;
F_20 ( V_554 , V_549 , NULL , F_232 , NULL ) ;
F_20 ( V_554 , V_551 , F_240 , NULL , NULL ) ;
F_20 ( V_554 , V_550 , F_239 , NULL , NULL ) ;
}
