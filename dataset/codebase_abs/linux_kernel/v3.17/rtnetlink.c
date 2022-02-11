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
F_38 ( V_33 ) ;
for (; ; ) {
F_39 ( & V_34 , & V_33 ,
V_35 ) ;
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
F_40 () ;
}
F_41 ( & V_34 , & V_33 ) ;
}
void F_42 ( struct V_18 * V_20 )
{
F_2 ( & V_37 ) ;
F_37 () ;
F_34 ( V_20 ) ;
F_5 () ;
F_4 ( & V_37 ) ;
}
static T_4 F_43 ( const struct V_29 * V_30 )
{
struct V_29 * V_38 ;
const struct V_18 * V_20 ;
V_38 = F_44 ( (struct V_29 * ) V_30 ) ;
if ( ! V_38 )
return 0 ;
V_20 = V_38 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_39 )
return 0 ;
return F_45 ( sizeof( struct V_40 ) ) +
V_20 -> V_39 ( V_38 , V_30 ) ;
}
static T_4 F_46 ( const struct V_29 * V_30 )
{
const struct V_18 * V_20 = V_30 -> V_18 ;
T_4 V_41 ;
if ( ! V_20 )
return 0 ;
V_41 = F_45 ( sizeof( struct V_40 ) ) +
F_45 ( strlen ( V_20 -> V_19 ) + 1 ) ;
if ( V_20 -> V_42 )
V_41 += F_45 ( sizeof( struct V_40 ) ) +
V_20 -> V_42 ( V_30 ) ;
if ( V_20 -> V_43 )
V_41 += F_45 ( V_20 -> V_43 ( V_30 ) ) ;
V_41 += F_43 ( V_30 ) ;
return V_41 ;
}
static const struct V_44 * F_47 ( const int V_45 )
{
const struct V_44 * V_20 ;
F_26 (ops, &rtnl_af_ops, list) {
if ( V_20 -> V_45 == V_45 )
return V_20 ;
}
return NULL ;
}
void F_48 ( struct V_44 * V_20 )
{
F_1 () ;
F_28 ( & V_20 -> V_25 , & V_44 ) ;
F_5 () ;
}
void F_49 ( struct V_44 * V_20 )
{
F_36 ( & V_20 -> V_25 ) ;
}
void F_50 ( struct V_44 * V_20 )
{
F_1 () ;
F_49 ( V_20 ) ;
F_5 () ;
}
static T_4 F_51 ( const struct V_29 * V_30 )
{
struct V_44 * V_46 ;
T_4 V_41 ;
V_41 = F_45 ( sizeof( struct V_40 ) ) ;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_46 -> V_47 ) {
V_41 += F_45 ( sizeof( struct V_40 ) ) +
V_46 -> V_47 ( V_30 ) ;
}
}
return V_41 ;
}
static bool F_52 ( const struct V_29 * V_30 )
{
struct V_29 * V_38 ;
V_38 = F_44 ( (struct V_29 * ) V_30 ) ;
if ( V_38 && V_38 -> V_18 )
return true ;
return false ;
}
static int F_53 ( struct V_48 * V_49 ,
const struct V_29 * V_30 )
{
struct V_29 * V_38 ;
const struct V_18 * V_20 ;
struct V_40 * V_50 ;
int V_27 ;
V_38 = F_44 ( (struct V_29 * ) V_30 ) ;
if ( ! V_38 )
return 0 ;
V_20 = V_38 -> V_18 ;
if ( ! V_20 )
return 0 ;
if ( F_54 ( V_49 , V_51 , V_20 -> V_19 ) < 0 )
return - V_52 ;
if ( V_20 -> V_53 ) {
V_50 = F_55 ( V_49 , V_54 ) ;
if ( ! V_50 )
return - V_52 ;
V_27 = V_20 -> V_53 ( V_49 , V_38 , V_30 ) ;
if ( V_27 < 0 )
goto V_55;
F_56 ( V_49 , V_50 ) ;
}
return 0 ;
V_55:
F_57 ( V_49 , V_50 ) ;
return V_27 ;
}
static int F_58 ( struct V_48 * V_49 ,
const struct V_29 * V_30 )
{
const struct V_18 * V_20 = V_30 -> V_18 ;
struct V_40 * V_56 ;
int V_27 ;
if ( ! V_20 )
return 0 ;
if ( F_54 ( V_49 , V_57 , V_20 -> V_19 ) < 0 )
return - V_52 ;
if ( V_20 -> V_58 ) {
V_27 = V_20 -> V_58 ( V_49 , V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_20 -> V_59 ) {
V_56 = F_55 ( V_49 , V_60 ) ;
if ( V_56 == NULL )
return - V_52 ;
V_27 = V_20 -> V_59 ( V_49 , V_30 ) ;
if ( V_27 < 0 )
goto V_61;
F_56 ( V_49 , V_56 ) ;
}
return 0 ;
V_61:
F_57 ( V_49 , V_56 ) ;
return V_27 ;
}
static int F_59 ( struct V_48 * V_49 , const struct V_29 * V_30 )
{
struct V_40 * V_62 ;
int V_27 = - V_52 ;
V_62 = F_55 ( V_49 , V_63 ) ;
if ( V_62 == NULL )
goto V_64;
V_27 = F_58 ( V_49 , V_30 ) ;
if ( V_27 < 0 )
goto V_65;
V_27 = F_53 ( V_49 , V_30 ) ;
if ( V_27 < 0 )
goto V_65;
F_56 ( V_49 , V_62 ) ;
return 0 ;
V_65:
F_57 ( V_49 , V_62 ) ;
V_64:
return V_27 ;
}
int F_60 ( struct V_48 * V_49 , struct V_28 * V_28 , T_5 V_66 , unsigned int V_67 , int V_68 )
{
struct V_69 * V_70 = V_28 -> V_70 ;
int V_27 = 0 ;
F_61 ( V_49 ) . V_71 = V_67 ;
if ( V_68 )
F_62 ( & V_49 -> V_72 ) ;
F_63 ( V_70 , V_49 , V_66 , V_67 , V_15 ) ;
if ( V_68 )
V_27 = F_64 ( V_70 , V_49 , V_66 , V_73 ) ;
return V_27 ;
}
int F_65 ( struct V_48 * V_49 , struct V_28 * V_28 , T_5 V_66 )
{
struct V_69 * V_70 = V_28 -> V_70 ;
return F_66 ( V_70 , V_49 , V_66 ) ;
}
void F_67 ( struct V_48 * V_49 , struct V_28 * V_28 , T_5 V_66 , T_5 V_67 ,
struct V_74 * V_75 , T_6 V_76 )
{
struct V_69 * V_70 = V_28 -> V_70 ;
int V_77 = 0 ;
if ( V_75 )
V_77 = F_68 ( V_75 ) ;
F_69 ( V_70 , V_49 , V_66 , V_67 , V_77 , V_76 ) ;
}
void F_70 ( struct V_28 * V_28 , T_5 V_67 , int error )
{
struct V_69 * V_70 = V_28 -> V_70 ;
F_71 ( V_70 , 0 , V_67 , error ) ;
}
int F_72 ( struct V_48 * V_49 , T_5 * V_78 )
{
struct V_40 * V_79 ;
int V_80 , V_81 = 0 ;
V_79 = F_55 ( V_49 , V_82 ) ;
if ( V_79 == NULL )
return - V_16 ;
for ( V_80 = 0 ; V_80 < V_83 ; V_80 ++ ) {
if ( V_78 [ V_80 ] ) {
V_81 ++ ;
if ( F_73 ( V_49 , V_80 + 1 , V_78 [ V_80 ] ) )
goto V_84;
}
}
if ( ! V_81 ) {
F_57 ( V_49 , V_79 ) ;
return 0 ;
}
return F_56 ( V_49 , V_79 ) ;
V_84:
F_57 ( V_49 , V_79 ) ;
return - V_52 ;
}
int F_74 ( struct V_48 * V_49 , struct V_85 * V_86 , T_5 V_87 ,
long V_88 , T_5 error )
{
struct V_89 V_90 = {
. V_91 = F_75 ( V_92 - V_86 -> V_93 ) ,
. V_94 = V_86 -> V_95 ,
. V_96 = F_76 ( & ( V_86 -> V_97 ) ) ,
. V_98 = error ,
. V_99 = V_87 ,
} ;
if ( V_88 ) {
unsigned long clock ;
clock = F_77 ( abs ( V_88 ) ) ;
clock = F_78 (unsigned long, clock, INT_MAX) ;
V_90 . V_100 = ( V_88 > 0 ) ? clock : - clock ;
}
return F_79 ( V_49 , V_101 , sizeof( V_90 ) , & V_90 ) ;
}
static void F_80 ( struct V_29 * V_30 , unsigned char V_102 )
{
unsigned char V_103 = V_30 -> V_103 ;
switch ( V_102 ) {
case V_104 :
if ( ( V_103 == V_105 ||
V_103 == V_106 ) &&
! F_81 ( V_30 ) )
V_103 = V_104 ;
break;
case V_105 :
if ( V_103 == V_104 ||
V_103 == V_106 )
V_103 = V_105 ;
break;
}
if ( V_30 -> V_103 != V_103 ) {
F_82 ( & V_107 ) ;
V_30 -> V_103 = V_103 ;
F_83 ( & V_107 ) ;
F_84 ( V_30 ) ;
}
}
static unsigned int F_85 ( const struct V_29 * V_30 )
{
return ( V_30 -> V_76 & ~ ( V_108 | V_109 ) ) |
( V_30 -> V_110 & ( V_108 | V_109 ) ) ;
}
static unsigned int F_86 ( const struct V_29 * V_30 ,
const struct V_111 * V_112 )
{
unsigned int V_76 = V_112 -> V_113 ;
if ( V_112 -> V_114 )
V_76 = ( V_76 & V_112 -> V_114 ) |
( F_85 ( V_30 ) & ~ V_112 -> V_114 ) ;
return V_76 ;
}
static void F_87 ( struct V_115 * V_116 ,
const struct V_117 * V_118 )
{
V_116 -> V_119 = V_118 -> V_119 ;
V_116 -> V_120 = V_118 -> V_120 ;
V_116 -> V_121 = V_118 -> V_121 ;
V_116 -> V_122 = V_118 -> V_122 ;
V_116 -> V_123 = V_118 -> V_123 ;
V_116 -> V_124 = V_118 -> V_124 ;
V_116 -> V_125 = V_118 -> V_125 ;
V_116 -> V_126 = V_118 -> V_126 ;
V_116 -> V_127 = V_118 -> V_127 ;
V_116 -> V_128 = V_118 -> V_128 ;
V_116 -> V_129 = V_118 -> V_129 ;
V_116 -> V_130 = V_118 -> V_130 ;
V_116 -> V_131 = V_118 -> V_131 ;
V_116 -> V_132 = V_118 -> V_132 ;
V_116 -> V_133 = V_118 -> V_133 ;
V_116 -> V_134 = V_118 -> V_134 ;
V_116 -> V_135 = V_118 -> V_135 ;
V_116 -> V_136 = V_118 -> V_136 ;
V_116 -> V_137 = V_118 -> V_137 ;
V_116 -> V_138 = V_118 -> V_138 ;
V_116 -> V_139 = V_118 -> V_139 ;
V_116 -> V_140 = V_118 -> V_140 ;
V_116 -> V_141 = V_118 -> V_141 ;
}
static void F_88 ( void * V_142 , const struct V_117 * V_118 )
{
memcpy ( V_142 , V_118 , sizeof( * V_118 ) ) ;
}
static inline int F_89 ( const struct V_29 * V_30 ,
T_5 V_143 )
{
if ( V_30 -> V_30 . V_144 && F_90 ( V_30 -> V_30 . V_144 ) &&
( V_143 & V_145 ) ) {
int V_146 = F_91 ( V_30 -> V_30 . V_144 ) ;
T_4 V_41 = F_45 ( sizeof( struct V_40 ) ) ;
V_41 += F_45 ( V_146 * sizeof( struct V_40 ) ) ;
V_41 += V_146 *
( F_45 ( sizeof( struct V_147 ) ) +
F_45 ( sizeof( struct V_148 ) ) +
F_45 ( sizeof( struct V_149 ) ) +
F_45 ( sizeof( struct V_150 ) ) +
F_45 ( sizeof( struct V_151 ) ) ) ;
return V_41 ;
} else
return 0 ;
}
static T_4 F_92 ( const struct V_29 * V_30 ,
T_5 V_143 )
{
T_4 V_152 = F_45 ( 4 )
+ F_45 ( V_153 )
+ F_45 ( sizeof( struct V_154 ) )
+ F_45 ( V_155 )
+ F_45 ( V_155 )
+ F_45 ( 1 )
+ F_45 ( 2 ) ;
T_4 V_156 = F_45 ( sizeof( struct V_40 ) ) ;
T_4 V_157 = F_45 ( sizeof( struct V_40 ) )
+ V_152 ;
T_4 V_158 = F_45 ( sizeof( struct V_40 ) )
+ V_152 ;
if ( ! V_30 -> V_159 -> V_160 || ! V_30 -> V_30 . V_144 ||
! ( V_143 & V_145 ) )
return 0 ;
if ( F_91 ( V_30 -> V_30 . V_144 ) )
return V_158 + V_156 +
V_157 * F_91 ( V_30 -> V_30 . V_144 ) ;
else
return V_158 ;
}
static T_7 T_4 F_93 ( const struct V_29 * V_30 ,
T_5 V_143 )
{
return F_94 ( sizeof( struct V_111 ) )
+ F_45 ( V_161 )
+ F_45 ( V_162 )
+ F_45 ( V_161 )
+ F_45 ( sizeof( struct V_163 ) )
+ F_45 ( sizeof( struct V_115 ) )
+ F_45 ( sizeof( struct V_117 ) )
+ F_45 ( V_164 )
+ F_45 ( V_164 )
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
+ F_45 ( V_143
& V_145 ? 4 : 0 )
+ F_89 ( V_30 , V_143 )
+ F_92 ( V_30 , V_143 )
+ F_46 ( V_30 )
+ F_51 ( V_30 )
+ F_45 ( V_165 ) ;
}
static int F_95 ( struct V_48 * V_49 , struct V_29 * V_30 )
{
struct V_40 * V_166 ;
struct V_40 * V_167 ;
int V_168 ;
int V_27 ;
V_166 = F_55 ( V_49 , V_169 ) ;
if ( ! V_166 )
return - V_52 ;
for ( V_168 = 0 ; V_168 < F_91 ( V_30 -> V_30 . V_144 ) ; V_168 ++ ) {
V_167 = F_55 ( V_49 , V_170 ) ;
if ( ! V_167 )
goto V_84;
if ( F_73 ( V_49 , V_171 , V_168 ) )
goto V_84;
V_27 = V_30 -> V_159 -> V_160 ( V_30 , V_168 , V_49 ) ;
if ( V_27 == - V_52 )
goto V_84;
if ( V_27 ) {
F_57 ( V_49 , V_167 ) ;
continue;
}
F_56 ( V_49 , V_167 ) ;
}
F_56 ( V_49 , V_166 ) ;
return 0 ;
V_84:
F_57 ( V_49 , V_166 ) ;
return - V_52 ;
}
static int F_96 ( struct V_48 * V_49 , struct V_29 * V_30 )
{
struct V_40 * V_172 ;
int V_27 ;
V_172 = F_55 ( V_49 , V_173 ) ;
if ( ! V_172 )
return - V_52 ;
V_27 = V_30 -> V_159 -> V_160 ( V_30 , V_174 , V_49 ) ;
if ( V_27 ) {
F_57 ( V_49 , V_172 ) ;
return ( V_27 == - V_52 ) ? V_27 : 0 ;
}
F_56 ( V_49 , V_172 ) ;
return 0 ;
}
static int F_97 ( struct V_48 * V_49 , struct V_29 * V_30 ,
T_5 V_143 )
{
int V_27 ;
if ( ! V_30 -> V_159 -> V_160 || ! V_30 -> V_30 . V_144 ||
! ( V_143 & V_145 ) )
return 0 ;
V_27 = F_96 ( V_49 , V_30 ) ;
if ( V_27 )
return V_27 ;
if ( F_91 ( V_30 -> V_30 . V_144 ) ) {
V_27 = F_95 ( V_49 , V_30 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_98 ( struct V_48 * V_49 , struct V_29 * V_30 )
{
int V_27 ;
struct V_175 V_176 ;
V_27 = F_99 ( V_30 , & V_176 ) ;
if ( V_27 ) {
if ( V_27 == - V_177 )
return 0 ;
return V_27 ;
}
if ( F_79 ( V_49 , V_178 , V_176 . V_179 , V_176 . V_87 ) )
return - V_52 ;
return 0 ;
}
static int F_100 ( struct V_48 * V_49 , struct V_29 * V_30 ,
int type , T_5 V_66 , T_5 V_180 , T_5 V_181 ,
unsigned int V_76 , T_5 V_143 )
{
struct V_111 * V_112 ;
struct V_74 * V_75 ;
struct V_117 V_182 ;
const struct V_117 * V_183 ;
struct V_40 * V_184 , * V_185 ;
struct V_44 * V_46 ;
struct V_29 * V_186 = F_44 ( V_30 ) ;
F_101 () ;
V_75 = F_102 ( V_49 , V_66 , V_180 , type , sizeof( * V_112 ) , V_76 ) ;
if ( V_75 == NULL )
return - V_52 ;
V_112 = F_103 ( V_75 ) ;
V_112 -> V_187 = V_188 ;
V_112 -> V_189 = 0 ;
V_112 -> V_190 = V_30 -> type ;
V_112 -> V_191 = V_30 -> V_192 ;
V_112 -> V_113 = F_104 ( V_30 ) ;
V_112 -> V_114 = V_181 ;
if ( F_54 ( V_49 , V_193 , V_30 -> V_194 ) ||
F_73 ( V_49 , V_195 , V_30 -> V_196 ) ||
F_105 ( V_49 , V_197 ,
F_106 ( V_30 ) ? V_30 -> V_103 : V_198 ) ||
F_105 ( V_49 , V_199 , V_30 -> V_200 ) ||
F_73 ( V_49 , V_201 , V_30 -> V_202 ) ||
F_73 ( V_49 , V_203 , V_30 -> V_67 ) ||
F_73 ( V_49 , V_204 , V_30 -> V_205 ) ||
F_73 ( V_49 , V_206 , V_30 -> V_207 ) ||
#ifdef F_107
F_73 ( V_49 , V_208 , V_30 -> V_209 ) ||
#endif
( V_30 -> V_192 != V_30 -> V_210 &&
F_73 ( V_49 , V_211 , V_30 -> V_210 ) ) ||
( V_186 &&
F_73 ( V_49 , V_212 , V_186 -> V_192 ) ) ||
F_105 ( V_49 , V_213 , F_108 ( V_30 ) ) ||
( V_30 -> V_214 &&
F_54 ( V_49 , V_215 , V_30 -> V_214 -> V_20 -> V_87 ) ) ||
( V_30 -> V_216 &&
F_54 ( V_49 , V_217 , V_30 -> V_216 ) ) ||
F_73 ( V_49 , V_218 ,
F_76 ( & V_30 -> V_219 ) ) )
goto V_84;
if ( 1 ) {
struct V_163 V_220 = {
. V_221 = V_30 -> V_221 ,
. V_222 = V_30 -> V_222 ,
. V_223 = V_30 -> V_223 ,
. V_224 = V_30 -> V_224 ,
. V_225 = V_30 -> V_225 ,
. V_226 = V_30 -> V_227 ,
} ;
if ( F_79 ( V_49 , V_228 , sizeof( V_220 ) , & V_220 ) )
goto V_84;
}
if ( V_30 -> V_229 ) {
if ( F_79 ( V_49 , V_230 , V_30 -> V_229 , V_30 -> V_231 ) ||
F_79 ( V_49 , V_232 , V_30 -> V_229 , V_30 -> V_233 ) )
goto V_84;
}
if ( F_98 ( V_49 , V_30 ) )
goto V_84;
V_184 = F_109 ( V_49 , V_234 ,
sizeof( struct V_115 ) ) ;
if ( V_184 == NULL )
goto V_84;
V_183 = F_110 ( V_30 , & V_182 ) ;
F_87 ( F_111 ( V_184 ) , V_183 ) ;
V_184 = F_109 ( V_49 , V_235 ,
sizeof( struct V_117 ) ) ;
if ( V_184 == NULL )
goto V_84;
F_88 ( F_111 ( V_184 ) , V_183 ) ;
if ( V_30 -> V_30 . V_144 && ( V_143 & V_145 ) &&
F_73 ( V_49 , V_236 , F_91 ( V_30 -> V_30 . V_144 ) ) )
goto V_84;
if ( V_30 -> V_159 -> V_237 && V_30 -> V_30 . V_144
&& ( V_143 & V_145 ) ) {
int V_80 ;
struct V_40 * V_238 , * V_168 ;
int V_146 = F_91 ( V_30 -> V_30 . V_144 ) ;
V_238 = F_55 ( V_49 , V_239 ) ;
if ( ! V_238 )
goto V_84;
for ( V_80 = 0 ; V_80 < V_146 ; V_80 ++ ) {
struct V_240 V_241 ;
struct V_147 V_242 ;
struct V_148 V_243 ;
struct V_150 V_244 ;
struct V_245 V_246 ;
struct V_149 V_247 ;
struct V_151 V_248 ;
V_241 . V_249 = - 1 ;
memset ( V_241 . V_250 , 0 , sizeof( V_241 . V_250 ) ) ;
V_241 . V_251 = 0 ;
if ( V_30 -> V_159 -> V_237 ( V_30 , V_80 , & V_241 ) )
break;
V_242 . V_168 =
V_243 . V_168 =
V_244 . V_168 =
V_246 . V_168 =
V_247 . V_168 =
V_248 . V_168 = V_241 . V_168 ;
memcpy ( V_242 . V_250 , V_241 . V_250 , sizeof( V_241 . V_250 ) ) ;
V_243 . V_252 = V_241 . V_252 ;
V_243 . V_253 = V_241 . V_253 ;
V_246 . V_254 = V_241 . V_255 ;
V_244 . V_256 = V_241 . V_256 ;
V_244 . V_255 = V_241 . V_255 ;
V_247 . V_257 = V_241 . V_249 ;
V_248 . V_258 = V_241 . V_251 ;
V_168 = F_55 ( V_49 , V_259 ) ;
if ( ! V_168 ) {
F_57 ( V_49 , V_238 ) ;
goto V_84;
}
if ( F_79 ( V_49 , V_260 , sizeof( V_242 ) , & V_242 ) ||
F_79 ( V_49 , V_261 , sizeof( V_243 ) , & V_243 ) ||
F_79 ( V_49 , V_262 , sizeof( V_244 ) ,
& V_244 ) ||
F_79 ( V_49 , V_263 , sizeof( V_246 ) ,
& V_246 ) ||
F_79 ( V_49 , V_264 , sizeof( V_247 ) ,
& V_247 ) ||
F_79 ( V_49 , V_265 , sizeof( V_248 ) ,
& V_248 ) )
goto V_84;
F_56 ( V_49 , V_168 ) ;
}
F_56 ( V_49 , V_238 ) ;
}
if ( F_97 ( V_49 , V_30 , V_143 ) )
goto V_84;
if ( V_30 -> V_18 || F_52 ( V_30 ) ) {
if ( F_59 ( V_49 , V_30 ) < 0 )
goto V_84;
}
if ( ! ( V_185 = F_55 ( V_49 , V_266 ) ) )
goto V_84;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_46 -> V_267 ) {
struct V_40 * V_268 ;
int V_27 ;
if ( ! ( V_268 = F_55 ( V_49 , V_46 -> V_45 ) ) )
goto V_84;
V_27 = V_46 -> V_267 ( V_49 , V_30 ) ;
if ( V_27 == - V_269 )
F_57 ( V_49 , V_268 ) ;
else if ( V_27 < 0 )
goto V_84;
F_56 ( V_49 , V_268 ) ;
}
}
F_56 ( V_49 , V_185 ) ;
return F_112 ( V_49 , V_75 ) ;
V_84:
F_113 ( V_49 , V_75 ) ;
return - V_52 ;
}
static int F_114 ( struct V_48 * V_49 , struct V_270 * V_271 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
int V_273 , V_274 ;
int V_275 = 0 , V_276 ;
struct V_29 * V_30 ;
struct V_277 * V_278 ;
struct V_40 * V_279 [ V_280 + 1 ] ;
T_5 V_143 = 0 ;
int V_27 ;
int V_281 ;
V_274 = V_271 -> args [ 0 ] ;
V_276 = V_271 -> args [ 1 ] ;
F_116 () ;
V_271 -> V_180 = V_28 -> V_282 ;
V_281 = F_117 ( V_271 -> V_75 ) < sizeof( struct V_111 ) ?
sizeof( struct V_283 ) : sizeof( struct V_111 ) ;
if ( F_118 ( V_271 -> V_75 , V_281 , V_279 , V_280 , V_284 ) >= 0 ) {
if ( V_279 [ V_285 ] )
V_143 = F_119 ( V_279 [ V_285 ] ) ;
}
for ( V_273 = V_274 ; V_273 < V_286 ; V_273 ++ , V_276 = 0 ) {
V_275 = 0 ;
V_278 = & V_28 -> V_287 [ V_273 ] ;
F_120 (dev, head, index_hlist) {
if ( V_275 < V_276 )
goto V_288;
V_27 = F_100 ( V_49 , V_30 , V_289 ,
F_61 ( V_271 -> V_49 ) . V_290 ,
V_271 -> V_75 -> V_291 , 0 ,
V_292 ,
V_143 ) ;
F_121 ( ( V_27 == - V_52 ) && ( V_49 -> V_293 == 0 ) ) ;
if ( V_27 <= 0 )
goto V_64;
F_122 ( V_271 , F_123 ( V_49 ) ) ;
V_288:
V_275 ++ ;
}
}
V_64:
F_124 () ;
V_271 -> args [ 1 ] = V_275 ;
V_271 -> args [ 0 ] = V_273 ;
return V_49 -> V_293 ;
}
int F_125 ( struct V_40 * * V_279 , const struct V_40 * V_278 , int V_293 )
{
return F_126 ( V_279 , V_280 , V_278 , V_293 , V_284 ) ;
}
struct V_28 * F_127 ( struct V_28 * V_294 , struct V_40 * V_279 [] )
{
struct V_28 * V_28 ;
if ( V_279 [ V_295 ] )
V_28 = F_128 ( F_119 ( V_279 [ V_295 ] ) ) ;
else if ( V_279 [ V_296 ] )
V_28 = F_129 ( F_119 ( V_279 [ V_296 ] ) ) ;
else
V_28 = F_130 ( V_294 ) ;
return V_28 ;
}
static int F_131 ( struct V_29 * V_30 , struct V_40 * V_279 [] )
{
if ( V_30 ) {
if ( V_279 [ V_230 ] &&
F_132 ( V_279 [ V_230 ] ) < V_30 -> V_229 )
return - V_297 ;
if ( V_279 [ V_232 ] &&
F_132 ( V_279 [ V_232 ] ) < V_30 -> V_229 )
return - V_297 ;
}
if ( V_279 [ V_266 ] ) {
struct V_40 * V_268 ;
int V_298 , V_27 ;
F_133 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_44 * V_46 ;
if ( ! ( V_46 = F_47 ( F_134 ( V_268 ) ) ) )
return - V_299 ;
if ( ! V_46 -> V_300 )
return - V_177 ;
if ( V_46 -> V_301 ) {
V_27 = V_46 -> V_301 ( V_30 , V_268 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_135 ( struct V_29 * V_30 , struct V_40 * V_184 )
{
int V_298 , V_27 = - V_297 ;
struct V_40 * V_168 ;
const struct V_302 * V_20 = V_30 -> V_159 ;
F_133 (vf, attr, rem) {
switch ( F_134 ( V_168 ) ) {
case V_260 : {
struct V_147 * V_303 ;
V_303 = F_111 ( V_168 ) ;
V_27 = - V_177 ;
if ( V_20 -> V_304 )
V_27 = V_20 -> V_304 ( V_30 , V_303 -> V_168 ,
V_303 -> V_250 ) ;
break;
}
case V_261 : {
struct V_148 * V_305 ;
V_305 = F_111 ( V_168 ) ;
V_27 = - V_177 ;
if ( V_20 -> V_306 )
V_27 = V_20 -> V_306 ( V_30 , V_305 -> V_168 ,
V_305 -> V_252 ,
V_305 -> V_253 ) ;
break;
}
case V_263 : {
struct V_245 * V_307 ;
struct V_240 V_308 ;
V_307 = F_111 ( V_168 ) ;
V_27 = - V_177 ;
if ( V_20 -> V_237 )
V_27 = V_20 -> V_237 ( V_30 , V_307 -> V_168 ,
& V_308 ) ;
if ( V_27 )
break;
V_27 = - V_177 ;
if ( V_20 -> V_309 )
V_27 = V_20 -> V_309 ( V_30 , V_307 -> V_168 ,
V_308 . V_256 ,
V_307 -> V_254 ) ;
break;
}
case V_262 : {
struct V_150 * V_307 ;
V_307 = F_111 ( V_168 ) ;
V_27 = - V_177 ;
if ( V_20 -> V_309 )
V_27 = V_20 -> V_309 ( V_30 , V_307 -> V_168 ,
V_307 -> V_256 ,
V_307 -> V_255 ) ;
break;
}
case V_264 : {
struct V_149 * V_310 ;
V_310 = F_111 ( V_168 ) ;
V_27 = - V_177 ;
if ( V_20 -> V_311 )
V_27 = V_20 -> V_311 ( V_30 , V_310 -> V_168 ,
V_310 -> V_257 ) ;
break;
}
case V_265 : {
struct V_151 * V_312 ;
V_312 = F_111 ( V_168 ) ;
V_27 = - V_177 ;
if ( V_20 -> V_313 )
V_27 = V_20 -> V_313 ( V_30 , V_312 -> V_168 ,
V_312 -> V_258 ) ;
break;
}
default:
V_27 = - V_297 ;
break;
}
if ( V_27 )
break;
}
return V_27 ;
}
static int F_136 ( struct V_29 * V_30 , int V_192 )
{
struct V_29 * V_186 = F_44 ( V_30 ) ;
const struct V_302 * V_20 ;
int V_27 ;
if ( V_186 ) {
if ( V_186 -> V_192 == V_192 )
return 0 ;
V_20 = V_186 -> V_159 ;
if ( V_20 -> V_314 ) {
V_27 = V_20 -> V_314 ( V_186 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_177 ;
}
}
if ( V_192 ) {
V_186 = F_137 ( F_138 ( V_30 ) , V_192 ) ;
if ( ! V_186 )
return - V_297 ;
V_20 = V_186 -> V_159 ;
if ( V_20 -> V_315 ) {
V_27 = V_20 -> V_315 ( V_186 , V_30 ) ;
if ( V_27 )
return V_27 ;
} else {
return - V_177 ;
}
}
return 0 ;
}
static int F_139 ( const struct V_48 * V_49 ,
struct V_29 * V_30 , struct V_111 * V_112 ,
struct V_40 * * V_279 , char * V_316 , int V_317 )
{
const struct V_302 * V_20 = V_30 -> V_159 ;
int V_27 ;
if ( V_279 [ V_295 ] || V_279 [ V_296 ] ) {
struct V_28 * V_28 = F_127 ( F_138 ( V_30 ) , V_279 ) ;
if ( F_140 ( V_28 ) ) {
V_27 = F_141 ( V_28 ) ;
goto V_318;
}
if ( ! F_142 ( V_49 , V_28 -> V_319 , V_320 ) ) {
V_27 = - V_321 ;
goto V_318;
}
V_27 = F_143 ( V_30 , V_28 , V_316 ) ;
F_144 ( V_28 ) ;
if ( V_27 )
goto V_318;
V_317 = 1 ;
}
if ( V_279 [ V_228 ] ) {
struct V_163 * V_322 ;
struct V_323 V_324 ;
if ( ! V_20 -> V_325 ) {
V_27 = - V_177 ;
goto V_318;
}
if ( ! F_145 ( V_30 ) ) {
V_27 = - V_326 ;
goto V_318;
}
V_322 = F_111 ( V_279 [ V_228 ] ) ;
V_324 . V_221 = ( unsigned long ) V_322 -> V_221 ;
V_324 . V_222 = ( unsigned long ) V_322 -> V_222 ;
V_324 . V_223 = ( unsigned short ) V_322 -> V_223 ;
V_324 . V_224 = ( unsigned char ) V_322 -> V_224 ;
V_324 . V_225 = ( unsigned char ) V_322 -> V_225 ;
V_324 . V_226 = ( unsigned char ) V_322 -> V_226 ;
V_27 = V_20 -> V_325 ( V_30 , & V_324 ) ;
if ( V_27 < 0 )
goto V_318;
V_317 = 1 ;
}
if ( V_279 [ V_230 ] ) {
struct V_327 * V_328 ;
int V_293 ;
V_293 = sizeof( V_329 ) + V_30 -> V_229 ;
V_328 = F_146 ( V_293 , V_15 ) ;
if ( ! V_328 ) {
V_27 = - V_330 ;
goto V_318;
}
V_328 -> V_331 = V_30 -> type ;
memcpy ( V_328 -> V_332 , F_111 ( V_279 [ V_230 ] ) ,
V_30 -> V_229 ) ;
V_27 = F_147 ( V_30 , V_328 ) ;
F_24 ( V_328 ) ;
if ( V_27 )
goto V_318;
V_317 = 1 ;
}
if ( V_279 [ V_201 ] ) {
V_27 = F_148 ( V_30 , F_119 ( V_279 [ V_201 ] ) ) ;
if ( V_27 < 0 )
goto V_318;
V_317 = 1 ;
}
if ( V_279 [ V_203 ] ) {
F_149 ( V_30 , F_119 ( V_279 [ V_203 ] ) ) ;
V_317 = 1 ;
}
if ( V_112 -> V_191 > 0 && V_316 [ 0 ] ) {
V_27 = F_150 ( V_30 , V_316 ) ;
if ( V_27 < 0 )
goto V_318;
V_317 = 1 ;
}
if ( V_279 [ V_217 ] ) {
V_27 = F_151 ( V_30 , F_111 ( V_279 [ V_217 ] ) ,
F_132 ( V_279 [ V_217 ] ) ) ;
if ( V_27 < 0 )
goto V_318;
V_317 = 1 ;
}
if ( V_279 [ V_232 ] ) {
F_152 ( V_30 -> V_233 , V_279 [ V_232 ] , V_30 -> V_229 ) ;
F_153 ( V_333 , V_30 ) ;
}
if ( V_112 -> V_113 || V_112 -> V_114 ) {
V_27 = F_154 ( V_30 , F_86 ( V_30 , V_112 ) ) ;
if ( V_27 < 0 )
goto V_318;
}
if ( V_279 [ V_212 ] ) {
V_27 = F_136 ( V_30 , F_119 ( V_279 [ V_212 ] ) ) ;
if ( V_27 )
goto V_318;
V_317 = 1 ;
}
if ( V_279 [ V_213 ] ) {
V_27 = F_155 ( V_30 , F_156 ( V_279 [ V_213 ] ) ) ;
if ( V_27 )
goto V_318;
V_317 = 1 ;
}
if ( V_279 [ V_195 ] )
V_30 -> V_196 = F_119 ( V_279 [ V_195 ] ) ;
if ( V_279 [ V_197 ] )
F_80 ( V_30 , F_156 ( V_279 [ V_197 ] ) ) ;
if ( V_279 [ V_199 ] ) {
F_82 ( & V_107 ) ;
V_30 -> V_200 = F_156 ( V_279 [ V_199 ] ) ;
F_83 ( & V_107 ) ;
}
if ( V_279 [ V_239 ] ) {
struct V_40 * V_184 ;
int V_298 ;
F_133 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_134 ( V_184 ) != V_259 ) {
V_27 = - V_297 ;
goto V_318;
}
V_27 = F_135 ( V_30 , V_184 ) ;
if ( V_27 < 0 )
goto V_318;
V_317 = 1 ;
}
}
V_27 = 0 ;
if ( V_279 [ V_169 ] ) {
struct V_40 * V_226 [ V_334 + 1 ] ;
struct V_40 * V_184 ;
int V_168 ;
int V_298 ;
V_27 = - V_177 ;
if ( ! V_20 -> V_335 )
goto V_318;
F_133 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_134 ( V_184 ) != V_170 )
continue;
V_27 = F_157 ( V_226 , V_334 ,
V_184 , V_336 ) ;
if ( V_27 < 0 )
goto V_318;
if ( ! V_226 [ V_171 ] ) {
V_27 = - V_177 ;
goto V_318;
}
V_168 = F_119 ( V_226 [ V_171 ] ) ;
V_27 = V_20 -> V_335 ( V_30 , V_168 , V_226 ) ;
if ( V_27 < 0 )
goto V_318;
V_317 = 1 ;
}
}
V_27 = 0 ;
if ( V_279 [ V_173 ] ) {
struct V_40 * V_226 [ V_334 + 1 ] ;
V_27 = F_157 ( V_226 , V_334 ,
V_279 [ V_173 ] , V_336 ) ;
if ( V_27 < 0 )
goto V_318;
V_27 = - V_177 ;
if ( V_20 -> V_335 )
V_27 = V_20 -> V_335 ( V_30 , V_174 , V_226 ) ;
if ( V_27 < 0 )
goto V_318;
V_317 = 1 ;
}
if ( V_279 [ V_266 ] ) {
struct V_40 * V_268 ;
int V_298 ;
F_133 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_44 * V_46 ;
if ( ! ( V_46 = F_47 ( F_134 ( V_268 ) ) ) )
F_158 () ;
V_27 = V_46 -> V_300 ( V_30 , V_268 ) ;
if ( V_27 < 0 )
goto V_318;
V_317 = 1 ;
}
}
V_27 = 0 ;
V_318:
if ( V_27 < 0 && V_317 )
F_159 ( L_3 ,
V_30 -> V_194 ) ;
return V_27 ;
}
static int F_160 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
struct V_111 * V_112 ;
struct V_29 * V_30 ;
int V_27 ;
struct V_40 * V_279 [ V_280 + 1 ] ;
char V_316 [ V_161 ] ;
V_27 = F_118 ( V_75 , sizeof( * V_112 ) , V_279 , V_280 , V_284 ) ;
if ( V_27 < 0 )
goto V_318;
if ( V_279 [ V_193 ] )
F_161 ( V_316 , V_279 [ V_193 ] , V_161 ) ;
else
V_316 [ 0 ] = '\0' ;
V_27 = - V_297 ;
V_112 = F_103 ( V_75 ) ;
if ( V_112 -> V_191 > 0 )
V_30 = F_137 ( V_28 , V_112 -> V_191 ) ;
else if ( V_279 [ V_193 ] )
V_30 = F_162 ( V_28 , V_316 ) ;
else
goto V_318;
if ( V_30 == NULL ) {
V_27 = - V_326 ;
goto V_318;
}
V_27 = F_131 ( V_30 , V_279 ) ;
if ( V_27 < 0 )
goto V_318;
V_27 = F_139 ( V_49 , V_30 , V_112 , V_279 , V_316 , 0 ) ;
V_318:
return V_27 ;
}
static int F_163 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
const struct V_18 * V_20 ;
struct V_29 * V_30 ;
struct V_111 * V_112 ;
char V_316 [ V_161 ] ;
struct V_40 * V_279 [ V_280 + 1 ] ;
int V_27 ;
F_31 ( V_31 ) ;
V_27 = F_118 ( V_75 , sizeof( * V_112 ) , V_279 , V_280 , V_284 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_279 [ V_193 ] )
F_161 ( V_316 , V_279 [ V_193 ] , V_161 ) ;
V_112 = F_103 ( V_75 ) ;
if ( V_112 -> V_191 > 0 )
V_30 = F_137 ( V_28 , V_112 -> V_191 ) ;
else if ( V_279 [ V_193 ] )
V_30 = F_162 ( V_28 , V_316 ) ;
else
return - V_297 ;
if ( ! V_30 )
return - V_326 ;
V_20 = V_30 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_23 )
return - V_177 ;
V_20 -> V_23 ( V_30 , & V_31 ) ;
F_33 ( & V_31 ) ;
return 0 ;
}
int F_164 ( struct V_29 * V_30 , const struct V_111 * V_112 )
{
unsigned int V_337 ;
int V_27 ;
V_337 = V_30 -> V_76 ;
if ( V_112 && ( V_112 -> V_113 || V_112 -> V_114 ) ) {
V_27 = F_165 ( V_30 , F_86 ( V_30 , V_112 ) ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_30 -> V_338 = V_339 ;
F_166 ( V_30 , V_337 , ~ 0U ) ;
return 0 ;
}
struct V_29 * F_167 ( struct V_28 * V_28 ,
char * V_316 , unsigned char V_340 ,
const struct V_18 * V_20 , struct V_40 * V_279 [] )
{
int V_27 ;
struct V_29 * V_30 ;
unsigned int V_207 = 1 ;
unsigned int V_209 = 1 ;
if ( V_279 [ V_206 ] )
V_207 = F_119 ( V_279 [ V_206 ] ) ;
else if ( V_20 -> V_341 )
V_207 = V_20 -> V_341 () ;
if ( V_279 [ V_208 ] )
V_209 = F_119 ( V_279 [ V_208 ] ) ;
else if ( V_20 -> V_342 )
V_209 = V_20 -> V_342 () ;
V_27 = - V_330 ;
V_30 = F_168 ( V_20 -> V_343 , V_316 , V_340 ,
V_20 -> V_22 , V_207 , V_209 ) ;
if ( ! V_30 )
goto V_27;
F_169 ( V_30 , V_28 ) ;
V_30 -> V_18 = V_20 ;
V_30 -> V_338 = V_344 ;
if ( V_279 [ V_201 ] )
V_30 -> V_202 = F_119 ( V_279 [ V_201 ] ) ;
if ( V_279 [ V_230 ] ) {
memcpy ( V_30 -> V_231 , F_111 ( V_279 [ V_230 ] ) ,
F_132 ( V_279 [ V_230 ] ) ) ;
V_30 -> V_345 = V_346 ;
}
if ( V_279 [ V_232 ] )
memcpy ( V_30 -> V_233 , F_111 ( V_279 [ V_232 ] ) ,
F_132 ( V_279 [ V_232 ] ) ) ;
if ( V_279 [ V_195 ] )
V_30 -> V_196 = F_119 ( V_279 [ V_195 ] ) ;
if ( V_279 [ V_197 ] )
F_80 ( V_30 , F_156 ( V_279 [ V_197 ] ) ) ;
if ( V_279 [ V_199 ] )
V_30 -> V_200 = F_156 ( V_279 [ V_199 ] ) ;
if ( V_279 [ V_203 ] )
F_149 ( V_30 , F_119 ( V_279 [ V_203 ] ) ) ;
return V_30 ;
V_27:
return F_170 ( V_27 ) ;
}
static int F_171 ( const struct V_48 * V_49 ,
struct V_28 * V_28 , int V_67 ,
struct V_111 * V_112 ,
struct V_40 * * V_279 )
{
struct V_29 * V_30 ;
int V_27 ;
F_32 (net, dev) {
if ( V_30 -> V_67 == V_67 ) {
V_27 = F_139 ( V_49 , V_30 , V_112 , V_279 , NULL , 0 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_172 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_347 = NULL ;
struct V_29 * V_30 ;
struct V_29 * V_38 = NULL ;
struct V_111 * V_112 ;
char V_19 [ V_348 ] ;
char V_316 [ V_161 ] ;
struct V_40 * V_279 [ V_280 + 1 ] ;
struct V_40 * V_62 [ V_349 + 1 ] ;
unsigned char V_340 = V_350 ;
int V_27 ;
#ifdef F_173
V_351:
#endif
V_27 = F_118 ( V_75 , sizeof( * V_112 ) , V_279 , V_280 , V_284 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_279 [ V_193 ] )
F_161 ( V_316 , V_279 [ V_193 ] , V_161 ) ;
else
V_316 [ 0 ] = '\0' ;
V_112 = F_103 ( V_75 ) ;
if ( V_112 -> V_191 > 0 )
V_30 = F_137 ( V_28 , V_112 -> V_191 ) ;
else {
if ( V_316 [ 0 ] )
V_30 = F_162 ( V_28 , V_316 ) ;
else
V_30 = NULL ;
}
if ( V_30 ) {
V_38 = F_44 ( V_30 ) ;
if ( V_38 )
V_347 = V_38 -> V_18 ;
}
V_27 = F_131 ( V_30 , V_279 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_279 [ V_63 ] ) {
V_27 = F_157 ( V_62 , V_349 ,
V_279 [ V_63 ] , V_352 ) ;
if ( V_27 < 0 )
return V_27 ;
} else
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
if ( V_62 [ V_57 ] ) {
F_161 ( V_19 , V_62 [ V_57 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_40 * V_184 [ V_20 ? V_20 -> V_353 + 1 : 0 ] ;
struct V_40 * V_354 [ V_347 ? V_347 -> V_355 + 1 : 0 ] ;
struct V_40 * * V_56 = NULL ;
struct V_40 * * V_50 = NULL ;
struct V_28 * V_356 ;
if ( V_20 ) {
if ( V_20 -> V_353 && V_62 [ V_60 ] ) {
V_27 = F_157 ( V_184 , V_20 -> V_353 ,
V_62 [ V_60 ] ,
V_20 -> V_357 ) ;
if ( V_27 < 0 )
return V_27 ;
V_56 = V_184 ;
}
if ( V_20 -> V_358 ) {
V_27 = V_20 -> V_358 ( V_279 , V_56 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_347 ) {
if ( V_347 -> V_355 &&
V_62 [ V_54 ] ) {
V_27 = F_157 ( V_354 ,
V_347 -> V_355 ,
V_62 [ V_54 ] ,
V_347 -> V_359 ) ;
if ( V_27 < 0 )
return V_27 ;
V_50 = V_354 ;
}
if ( V_347 -> V_360 ) {
V_27 = V_347 -> V_360 ( V_279 , V_50 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
if ( V_30 ) {
int V_317 = 0 ;
if ( V_75 -> V_361 & V_362 )
return - V_21 ;
if ( V_75 -> V_361 & V_363 )
return - V_177 ;
if ( V_62 [ V_60 ] ) {
if ( ! V_20 || V_20 != V_30 -> V_18 ||
! V_20 -> V_364 )
return - V_177 ;
V_27 = V_20 -> V_364 ( V_30 , V_279 , V_56 ) ;
if ( V_27 < 0 )
return V_27 ;
V_317 = 1 ;
}
if ( V_62 [ V_54 ] ) {
if ( ! V_347 || ! V_347 -> V_365 )
return - V_177 ;
V_27 = V_347 -> V_365 ( V_38 , V_30 ,
V_279 , V_50 ) ;
if ( V_27 < 0 )
return V_27 ;
V_317 = 1 ;
}
return F_139 ( V_49 , V_30 , V_112 , V_279 , V_316 , V_317 ) ;
}
if ( ! ( V_75 -> V_361 & V_366 ) ) {
if ( V_112 -> V_191 == 0 && V_279 [ V_203 ] )
return F_171 ( V_49 , V_28 ,
F_119 ( V_279 [ V_203 ] ) ,
V_112 , V_279 ) ;
return - V_326 ;
}
if ( V_279 [ V_228 ] || V_279 [ V_212 ] || V_279 [ V_367 ] )
return - V_177 ;
if ( ! V_20 ) {
#ifdef F_173
if ( V_19 [ 0 ] ) {
F_3 () ;
F_174 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_351;
}
#endif
return - V_177 ;
}
if ( ! V_20 -> V_22 )
return - V_177 ;
if ( ! V_316 [ 0 ] ) {
snprintf ( V_316 , V_161 , L_5 , V_20 -> V_19 ) ;
V_340 = V_368 ;
}
V_356 = F_127 ( V_28 , V_279 ) ;
if ( F_140 ( V_356 ) )
return F_141 ( V_356 ) ;
V_30 = F_167 ( V_356 , V_316 , V_340 , V_20 , V_279 ) ;
if ( F_140 ( V_30 ) ) {
V_27 = F_141 ( V_30 ) ;
goto V_64;
}
V_30 -> V_192 = V_112 -> V_191 ;
if ( V_20 -> V_369 ) {
V_27 = V_20 -> V_369 ( V_28 , V_30 , V_279 , V_56 ) ;
if ( V_27 < 0 ) {
if ( V_30 -> V_370 == V_371 )
F_175 ( V_30 ) ;
goto V_64;
}
} else {
V_27 = F_176 ( V_30 ) ;
if ( V_27 < 0 ) {
F_175 ( V_30 ) ;
goto V_64;
}
}
V_27 = F_164 ( V_30 , V_112 ) ;
if ( V_27 < 0 )
F_177 ( V_30 ) ;
V_64:
F_144 ( V_356 ) ;
return V_27 ;
}
}
static int F_178 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
struct V_111 * V_112 ;
char V_316 [ V_161 ] ;
struct V_40 * V_279 [ V_280 + 1 ] ;
struct V_29 * V_30 = NULL ;
struct V_48 * V_372 ;
int V_27 ;
T_5 V_143 = 0 ;
V_27 = F_118 ( V_75 , sizeof( * V_112 ) , V_279 , V_280 , V_284 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_279 [ V_193 ] )
F_161 ( V_316 , V_279 [ V_193 ] , V_161 ) ;
if ( V_279 [ V_285 ] )
V_143 = F_119 ( V_279 [ V_285 ] ) ;
V_112 = F_103 ( V_75 ) ;
if ( V_112 -> V_191 > 0 )
V_30 = F_137 ( V_28 , V_112 -> V_191 ) ;
else if ( V_279 [ V_193 ] )
V_30 = F_162 ( V_28 , V_316 ) ;
else
return - V_297 ;
if ( V_30 == NULL )
return - V_326 ;
V_372 = F_179 ( F_93 ( V_30 , V_143 ) , V_15 ) ;
if ( V_372 == NULL )
return - V_16 ;
V_27 = F_100 ( V_372 , V_30 , V_289 , F_61 ( V_49 ) . V_290 ,
V_75 -> V_291 , 0 , 0 , V_143 ) ;
if ( V_27 < 0 ) {
F_121 ( V_27 == - V_52 ) ;
F_180 ( V_372 ) ;
} else
V_27 = F_65 ( V_372 , V_28 , F_61 ( V_49 ) . V_290 ) ;
return V_27 ;
}
static T_8 F_181 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
struct V_29 * V_30 ;
struct V_40 * V_279 [ V_280 + 1 ] ;
T_5 V_143 = 0 ;
T_8 V_373 = 0 ;
int V_281 ;
V_281 = F_117 ( V_75 ) < sizeof( struct V_111 ) ?
sizeof( struct V_283 ) : sizeof( struct V_111 ) ;
if ( F_118 ( V_75 , V_281 , V_279 , V_280 , V_284 ) >= 0 ) {
if ( V_279 [ V_285 ] )
V_143 = F_119 ( V_279 [ V_285 ] ) ;
}
if ( ! V_143 )
return V_374 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_373 = F_182 ( T_8 , V_373 ,
F_93 ( V_30 ,
V_143 ) ) ;
}
return V_373 ;
}
static int F_183 ( struct V_48 * V_49 , struct V_270 * V_271 )
{
int V_275 ;
int V_276 = V_271 -> V_45 ;
if ( V_276 == 0 )
V_276 = 1 ;
for ( V_275 = 1 ; V_275 <= V_9 ; V_275 ++ ) {
int type = V_271 -> V_75 -> V_375 - V_4 ;
if ( V_275 < V_276 || V_275 == V_376 )
continue;
if ( V_10 [ V_275 ] == NULL ||
V_10 [ V_275 ] [ type ] . V_13 == NULL )
continue;
if ( V_275 > V_276 ) {
memset ( & V_271 -> args [ 0 ] , 0 , sizeof( V_271 -> args ) ) ;
V_271 -> V_377 = 0 ;
V_271 -> V_180 = 0 ;
}
if ( V_10 [ V_275 ] [ type ] . V_13 ( V_49 , V_271 ) )
break;
}
V_271 -> V_45 = V_275 ;
return V_49 -> V_293 ;
}
void F_184 ( int type , struct V_29 * V_30 , unsigned int V_181 ,
T_6 V_76 )
{
struct V_28 * V_28 = F_138 ( V_30 ) ;
struct V_48 * V_49 ;
int V_27 = - V_16 ;
T_4 V_378 ;
V_49 = F_179 ( ( V_378 = F_93 ( V_30 , 0 ) ) , V_76 ) ;
if ( V_49 == NULL )
goto V_318;
V_27 = F_100 ( V_49 , V_30 , type , 0 , 0 , V_181 , 0 , 0 ) ;
if ( V_27 < 0 ) {
F_121 ( V_27 == - V_52 ) ;
F_180 ( V_49 ) ;
goto V_318;
}
F_67 ( V_49 , V_28 , 0 , V_379 , NULL , V_76 ) ;
return;
V_318:
if ( V_27 < 0 )
F_70 ( V_28 , V_379 , V_27 ) ;
}
static int F_185 ( struct V_48 * V_49 ,
struct V_29 * V_30 ,
T_9 * V_380 , T_5 V_66 , T_5 V_180 ,
int type , unsigned int V_76 ,
int V_381 )
{
struct V_74 * V_75 ;
struct V_382 * V_383 ;
V_75 = F_102 ( V_49 , V_66 , V_180 , type , sizeof( * V_383 ) , V_381 ) ;
if ( ! V_75 )
return - V_52 ;
V_383 = F_103 ( V_75 ) ;
V_383 -> V_384 = V_385 ;
V_383 -> V_386 = 0 ;
V_383 -> V_387 = 0 ;
V_383 -> V_388 = V_76 ;
V_383 -> V_389 = 0 ;
V_383 -> V_390 = V_30 -> V_192 ;
V_383 -> V_391 = V_392 ;
if ( F_79 ( V_49 , V_393 , V_394 , V_380 ) )
goto V_84;
return F_112 ( V_49 , V_75 ) ;
V_84:
F_113 ( V_49 , V_75 ) ;
return - V_52 ;
}
static inline T_4 F_186 ( void )
{
return F_94 ( sizeof( struct V_382 ) ) + F_45 ( V_394 ) ;
}
static void F_187 ( struct V_29 * V_30 , T_9 * V_380 , int type )
{
struct V_28 * V_28 = F_138 ( V_30 ) ;
struct V_48 * V_49 ;
int V_27 = - V_16 ;
V_49 = F_179 ( F_186 () , V_395 ) ;
if ( ! V_49 )
goto V_318;
V_27 = F_185 ( V_49 , V_30 , V_380 , 0 , 0 , type , V_396 , 0 ) ;
if ( V_27 < 0 ) {
F_180 ( V_49 ) ;
goto V_318;
}
F_67 ( V_49 , V_28 , 0 , V_397 , NULL , V_395 ) ;
return;
V_318:
F_70 ( V_28 , V_397 , V_27 ) ;
}
int F_188 ( struct V_382 * V_383 ,
struct V_40 * V_279 [] ,
struct V_29 * V_30 ,
const unsigned char * V_380 ,
T_8 V_76 )
{
int V_27 = - V_297 ;
if ( V_383 -> V_391 && ! ( V_383 -> V_391 & V_392 ) ) {
F_189 ( L_6 , V_30 -> V_194 ) ;
return V_27 ;
}
if ( F_190 ( V_380 ) || F_191 ( V_380 ) )
V_27 = F_192 ( V_30 , V_380 ) ;
else if ( F_193 ( V_380 ) )
V_27 = F_194 ( V_30 , V_380 ) ;
if ( V_27 == - V_21 && ! ( V_76 & V_362 ) )
V_27 = 0 ;
return V_27 ;
}
static int F_195 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
struct V_382 * V_383 ;
struct V_40 * V_279 [ V_398 + 1 ] ;
struct V_29 * V_30 ;
T_9 * V_380 ;
int V_27 ;
V_27 = F_118 ( V_75 , sizeof( * V_383 ) , V_279 , V_398 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_383 = F_103 ( V_75 ) ;
if ( V_383 -> V_390 == 0 ) {
F_189 ( L_7 ) ;
return - V_297 ;
}
V_30 = F_137 ( V_28 , V_383 -> V_390 ) ;
if ( V_30 == NULL ) {
F_189 ( L_8 ) ;
return - V_326 ;
}
if ( ! V_279 [ V_393 ] || F_132 ( V_279 [ V_393 ] ) != V_394 ) {
F_189 ( L_9 ) ;
return - V_297 ;
}
V_380 = F_111 ( V_279 [ V_393 ] ) ;
V_27 = - V_177 ;
if ( ( ! V_383 -> V_388 || V_383 -> V_388 & V_399 ) &&
( V_30 -> V_400 & V_401 ) ) {
struct V_29 * V_402 = F_44 ( V_30 ) ;
const struct V_302 * V_20 = V_402 -> V_159 ;
V_27 = V_20 -> V_403 ( V_383 , V_279 , V_30 , V_380 , V_75 -> V_361 ) ;
if ( V_27 )
goto V_64;
else
V_383 -> V_388 &= ~ V_399 ;
}
if ( ( V_383 -> V_388 & V_396 ) ) {
if ( V_30 -> V_159 -> V_403 )
V_27 = V_30 -> V_159 -> V_403 ( V_383 , V_279 , V_30 , V_380 ,
V_75 -> V_361 ) ;
else
V_27 = F_188 ( V_383 , V_279 , V_30 , V_380 ,
V_75 -> V_361 ) ;
if ( ! V_27 ) {
F_187 ( V_30 , V_380 , V_404 ) ;
V_383 -> V_388 &= ~ V_396 ;
}
}
V_64:
return V_27 ;
}
int F_196 ( struct V_382 * V_383 ,
struct V_40 * V_279 [] ,
struct V_29 * V_30 ,
const unsigned char * V_380 )
{
int V_27 = - V_297 ;
if ( ! ( V_383 -> V_391 & V_392 ) ) {
F_189 ( L_6 , V_30 -> V_194 ) ;
return V_27 ;
}
if ( F_190 ( V_380 ) || F_191 ( V_380 ) )
V_27 = F_197 ( V_30 , V_380 ) ;
else if ( F_193 ( V_380 ) )
V_27 = F_198 ( V_30 , V_380 ) ;
return V_27 ;
}
static int F_199 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
struct V_382 * V_383 ;
struct V_40 * V_279 [ V_398 + 1 ] ;
struct V_29 * V_30 ;
int V_27 = - V_297 ;
T_10 * V_380 ;
if ( ! F_200 ( V_49 , V_320 ) )
return - V_321 ;
V_27 = F_118 ( V_75 , sizeof( * V_383 ) , V_279 , V_398 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_383 = F_103 ( V_75 ) ;
if ( V_383 -> V_390 == 0 ) {
F_189 ( L_10 ) ;
return - V_297 ;
}
V_30 = F_137 ( V_28 , V_383 -> V_390 ) ;
if ( V_30 == NULL ) {
F_189 ( L_11 ) ;
return - V_326 ;
}
if ( ! V_279 [ V_393 ] || F_132 ( V_279 [ V_393 ] ) != V_394 ) {
F_189 ( L_12 ) ;
return - V_297 ;
}
V_380 = F_111 ( V_279 [ V_393 ] ) ;
V_27 = - V_177 ;
if ( ( ! V_383 -> V_388 || V_383 -> V_388 & V_399 ) &&
( V_30 -> V_400 & V_401 ) ) {
struct V_29 * V_402 = F_44 ( V_30 ) ;
const struct V_302 * V_20 = V_402 -> V_159 ;
if ( V_20 -> V_405 )
V_27 = V_20 -> V_405 ( V_383 , V_279 , V_30 , V_380 ) ;
if ( V_27 )
goto V_64;
else
V_383 -> V_388 &= ~ V_399 ;
}
if ( V_383 -> V_388 & V_396 ) {
if ( V_30 -> V_159 -> V_405 )
V_27 = V_30 -> V_159 -> V_405 ( V_383 , V_279 , V_30 , V_380 ) ;
else
V_27 = F_196 ( V_383 , V_279 , V_30 , V_380 ) ;
if ( ! V_27 ) {
F_187 ( V_30 , V_380 , V_406 ) ;
V_383 -> V_388 &= ~ V_396 ;
}
}
V_64:
return V_27 ;
}
static int F_201 ( struct V_48 * V_49 ,
struct V_270 * V_271 ,
struct V_29 * V_30 ,
int * V_275 ,
struct V_407 * V_25 )
{
struct V_408 * V_409 ;
int V_27 ;
T_5 V_290 , V_180 ;
V_290 = F_61 ( V_271 -> V_49 ) . V_290 ;
V_180 = V_271 -> V_75 -> V_291 ;
F_26 (ha, &list->list, list) {
if ( * V_275 < V_271 -> args [ 0 ] )
goto V_410;
V_27 = F_185 ( V_49 , V_30 , V_409 -> V_380 ,
V_290 , V_180 ,
V_404 , V_396 ,
V_292 ) ;
if ( V_27 < 0 )
return V_27 ;
V_410:
* V_275 += 1 ;
}
return 0 ;
}
int F_202 ( struct V_48 * V_49 ,
struct V_270 * V_271 ,
struct V_29 * V_30 ,
struct V_29 * V_411 ,
int V_275 )
{
int V_27 ;
F_203 ( V_30 ) ;
V_27 = F_201 ( V_49 , V_271 , V_30 , & V_275 , & V_30 -> V_412 ) ;
if ( V_27 )
goto V_64;
F_201 ( V_49 , V_271 , V_30 , & V_275 , & V_30 -> V_413 ) ;
V_64:
F_204 ( V_30 ) ;
return V_275 ;
}
static int F_205 ( struct V_48 * V_49 , struct V_270 * V_271 )
{
struct V_29 * V_30 ;
struct V_40 * V_279 [ V_280 + 1 ] ;
struct V_29 * V_414 = NULL ;
struct V_29 * V_402 = NULL ;
const struct V_302 * V_20 = NULL ;
const struct V_302 * V_415 = NULL ;
struct V_111 * V_112 = F_103 ( V_271 -> V_75 ) ;
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
int V_416 = 0 ;
int V_417 = 0 ;
int V_275 = 0 ;
if ( F_118 ( V_271 -> V_75 , sizeof( struct V_111 ) , V_279 , V_280 ,
V_284 ) == 0 ) {
if ( V_279 [ V_212 ] )
V_417 = F_119 ( V_279 [ V_212 ] ) ;
}
V_416 = V_112 -> V_191 ;
if ( V_417 ) {
V_402 = F_137 ( V_28 , V_417 ) ;
if ( ! V_402 )
return - V_326 ;
V_20 = V_402 -> V_159 ;
V_414 = V_402 ;
}
F_32 (net, dev) {
if ( V_416 && ( V_30 -> V_192 != V_416 ) )
continue;
if ( ! V_417 ) {
if ( V_30 -> V_400 & V_401 ) {
V_402 = F_44 ( V_30 ) ;
V_415 = V_402 -> V_159 ;
}
V_414 = V_30 ;
} else {
if ( V_30 != V_402 &&
! ( V_30 -> V_400 & V_401 ) )
continue;
if ( V_402 != F_44 ( V_30 ) &&
! ( V_30 -> V_400 & V_418 ) )
continue;
V_414 = V_402 ;
V_415 = V_20 ;
}
if ( V_30 -> V_400 & V_401 ) {
if ( V_415 && V_415 -> V_419 )
V_275 = V_415 -> V_419 ( V_49 , V_271 , V_402 , V_30 ,
V_275 ) ;
}
V_275 = F_202 ( V_49 , V_271 , V_30 , NULL , V_275 ) ;
if ( V_30 -> V_159 -> V_419 )
V_275 = V_30 -> V_159 -> V_419 ( V_49 , V_271 , V_414 , V_30 ,
V_275 ) ;
V_415 = NULL ;
}
V_271 -> args [ 0 ] = V_275 ;
return V_49 -> V_293 ;
}
int F_206 ( struct V_48 * V_49 , T_5 V_66 , T_5 V_180 ,
struct V_29 * V_30 , T_8 V_420 )
{
struct V_74 * V_75 ;
struct V_111 * V_112 ;
struct V_40 * V_421 ;
T_9 V_103 = F_106 ( V_30 ) ? V_30 -> V_103 : V_198 ;
struct V_29 * V_402 = F_44 ( V_30 ) ;
V_75 = F_102 ( V_49 , V_66 , V_180 , V_289 , sizeof( * V_112 ) , V_292 ) ;
if ( V_75 == NULL )
return - V_52 ;
V_112 = F_103 ( V_75 ) ;
V_112 -> V_187 = V_385 ;
V_112 -> V_189 = 0 ;
V_112 -> V_190 = V_30 -> type ;
V_112 -> V_191 = V_30 -> V_192 ;
V_112 -> V_113 = F_104 ( V_30 ) ;
V_112 -> V_114 = 0 ;
if ( F_54 ( V_49 , V_193 , V_30 -> V_194 ) ||
F_73 ( V_49 , V_201 , V_30 -> V_202 ) ||
F_105 ( V_49 , V_197 , V_103 ) ||
( V_402 &&
F_73 ( V_49 , V_212 , V_402 -> V_192 ) ) ||
( V_30 -> V_229 &&
F_79 ( V_49 , V_230 , V_30 -> V_229 , V_30 -> V_231 ) ) ||
( V_30 -> V_192 != V_30 -> V_210 &&
F_73 ( V_49 , V_211 , V_30 -> V_210 ) ) )
goto V_84;
V_421 = F_55 ( V_49 , V_266 ) ;
if ( ! V_421 )
goto V_84;
if ( F_207 ( V_49 , V_422 , V_423 ) ||
F_207 ( V_49 , V_424 , V_420 ) ) {
F_57 ( V_49 , V_421 ) ;
goto V_84;
}
F_56 ( V_49 , V_421 ) ;
return F_112 ( V_49 , V_75 ) ;
V_84:
F_113 ( V_49 , V_75 ) ;
return - V_52 ;
}
static int F_208 ( struct V_48 * V_49 , struct V_270 * V_271 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
struct V_29 * V_30 ;
int V_275 = 0 ;
T_5 V_290 = F_61 ( V_271 -> V_49 ) . V_290 ;
T_5 V_180 = V_271 -> V_75 -> V_291 ;
struct V_40 * V_425 ;
T_5 V_426 = 0 ;
V_425 = F_209 ( V_271 -> V_75 , sizeof( struct V_111 ) ,
V_285 ) ;
if ( V_425 )
V_426 = F_119 ( V_425 ) ;
F_116 () ;
F_210 (net, dev) {
const struct V_302 * V_20 = V_30 -> V_159 ;
struct V_29 * V_402 = F_44 ( V_30 ) ;
if ( V_402 && V_402 -> V_159 -> V_427 ) {
if ( V_275 >= V_271 -> args [ 0 ] &&
V_402 -> V_159 -> V_427 (
V_49 , V_290 , V_180 , V_30 , V_426 ) < 0 )
break;
V_275 ++ ;
}
if ( V_20 -> V_427 ) {
if ( V_275 >= V_271 -> args [ 0 ] &&
V_20 -> V_427 ( V_49 , V_290 , V_180 , V_30 ,
V_426 ) < 0 )
break;
V_275 ++ ;
}
}
F_124 () ;
V_271 -> args [ 0 ] = V_275 ;
return V_49 -> V_293 ;
}
static inline T_4 F_211 ( void )
{
return F_94 ( sizeof( struct V_111 ) )
+ F_45 ( V_161 )
+ F_45 ( V_164 )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_5 ) )
+ F_45 ( sizeof( T_9 ) )
+ F_45 ( sizeof( struct V_40 ) )
+ F_45 ( sizeof( T_8 ) )
+ F_45 ( sizeof( T_8 ) ) ;
}
static int F_212 ( struct V_29 * V_30 , T_8 V_76 )
{
struct V_28 * V_28 = F_138 ( V_30 ) ;
struct V_29 * V_402 = F_44 ( V_30 ) ;
struct V_48 * V_49 ;
int V_27 = - V_177 ;
V_49 = F_179 ( F_211 () , V_395 ) ;
if ( ! V_49 ) {
V_27 = - V_330 ;
goto V_318;
}
if ( ( ! V_76 || ( V_76 & V_428 ) ) &&
V_402 && V_402 -> V_159 -> V_427 ) {
V_27 = V_402 -> V_159 -> V_427 ( V_49 , 0 , 0 , V_30 , 0 ) ;
if ( V_27 < 0 )
goto V_318;
}
if ( ( V_76 & V_423 ) &&
V_30 -> V_159 -> V_427 ) {
V_27 = V_30 -> V_159 -> V_427 ( V_49 , 0 , 0 , V_30 , 0 ) ;
if ( V_27 < 0 )
goto V_318;
}
F_67 ( V_49 , V_28 , 0 , V_379 , NULL , V_395 ) ;
return 0 ;
V_318:
F_121 ( V_27 == - V_52 ) ;
F_180 ( V_49 ) ;
F_70 ( V_28 , V_379 , V_27 ) ;
return V_27 ;
}
static int F_213 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
struct V_111 * V_112 ;
struct V_29 * V_30 ;
struct V_40 * V_429 , * V_184 = NULL ;
int V_298 , V_27 = - V_177 ;
T_8 V_430 , V_76 = 0 ;
bool V_431 = false ;
if ( F_117 ( V_75 ) < sizeof( * V_112 ) )
return - V_297 ;
V_112 = F_103 ( V_75 ) ;
if ( V_112 -> V_187 != V_385 )
return - V_432 ;
V_30 = F_137 ( V_28 , V_112 -> V_191 ) ;
if ( ! V_30 ) {
F_189 ( L_13 ) ;
return - V_326 ;
}
V_429 = F_209 ( V_75 , sizeof( struct V_111 ) , V_266 ) ;
if ( V_429 ) {
F_133 (attr, br_spec, rem) {
if ( F_134 ( V_184 ) == V_422 ) {
V_431 = true ;
V_76 = F_214 ( V_184 ) ;
break;
}
}
}
V_430 = V_76 ;
if ( ! V_76 || ( V_76 & V_428 ) ) {
struct V_29 * V_402 = F_44 ( V_30 ) ;
if ( ! V_402 || ! V_402 -> V_159 -> V_433 ) {
V_27 = - V_177 ;
goto V_64;
}
V_27 = V_402 -> V_159 -> V_433 ( V_30 , V_75 ) ;
if ( V_27 )
goto V_64;
V_76 &= ~ V_428 ;
}
if ( ( V_76 & V_423 ) ) {
if ( ! V_30 -> V_159 -> V_433 )
V_27 = - V_177 ;
else
V_27 = V_30 -> V_159 -> V_433 ( V_30 , V_75 ) ;
if ( ! V_27 )
V_76 &= ~ V_423 ;
}
if ( V_431 )
memcpy ( F_111 ( V_184 ) , & V_76 , sizeof( V_76 ) ) ;
if ( ! V_27 )
V_27 = F_212 ( V_30 , V_430 ) ;
V_64:
return V_27 ;
}
static int F_215 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
struct V_111 * V_112 ;
struct V_29 * V_30 ;
struct V_40 * V_429 , * V_184 = NULL ;
int V_298 , V_27 = - V_177 ;
T_8 V_430 , V_76 = 0 ;
bool V_431 = false ;
if ( F_117 ( V_75 ) < sizeof( * V_112 ) )
return - V_297 ;
V_112 = F_103 ( V_75 ) ;
if ( V_112 -> V_187 != V_385 )
return - V_432 ;
V_30 = F_137 ( V_28 , V_112 -> V_191 ) ;
if ( ! V_30 ) {
F_189 ( L_13 ) ;
return - V_326 ;
}
V_429 = F_209 ( V_75 , sizeof( struct V_111 ) , V_266 ) ;
if ( V_429 ) {
F_133 (attr, br_spec, rem) {
if ( F_134 ( V_184 ) == V_422 ) {
V_431 = true ;
V_76 = F_214 ( V_184 ) ;
break;
}
}
}
V_430 = V_76 ;
if ( ! V_76 || ( V_76 & V_428 ) ) {
struct V_29 * V_402 = F_44 ( V_30 ) ;
if ( ! V_402 || ! V_402 -> V_159 -> V_434 ) {
V_27 = - V_177 ;
goto V_64;
}
V_27 = V_402 -> V_159 -> V_434 ( V_30 , V_75 ) ;
if ( V_27 )
goto V_64;
V_76 &= ~ V_428 ;
}
if ( ( V_76 & V_423 ) ) {
if ( ! V_30 -> V_159 -> V_434 )
V_27 = - V_177 ;
else
V_27 = V_30 -> V_159 -> V_434 ( V_30 , V_75 ) ;
if ( ! V_27 )
V_76 &= ~ V_423 ;
}
if ( V_431 )
memcpy ( F_111 ( V_184 ) , & V_76 , sizeof( V_76 ) ) ;
if ( ! V_27 )
V_27 = F_212 ( V_30 , V_430 ) ;
V_64:
return V_27 ;
}
static int F_216 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
struct V_28 * V_28 = F_115 ( V_49 -> V_272 ) ;
T_1 V_11 ;
int V_435 , V_19 ;
int V_45 ;
int type ;
int V_27 ;
type = V_75 -> V_375 ;
if ( type > V_436 )
return - V_177 ;
type -= V_4 ;
if ( F_117 ( V_75 ) < sizeof( struct V_283 ) )
return 0 ;
V_45 = ( (struct V_283 * ) F_103 ( V_75 ) ) -> V_437 ;
V_435 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_217 ( V_49 , V_320 ) )
return - V_321 ;
if ( V_19 == 2 && V_75 -> V_361 & V_438 ) {
struct V_69 * V_70 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_439 = 0 ;
V_13 = F_16 ( V_45 , type ) ;
if ( V_13 == NULL )
return - V_177 ;
V_14 = F_17 ( V_45 , type ) ;
if ( V_14 )
V_439 = V_14 ( V_49 , V_75 ) ;
F_3 () ;
V_70 = V_28 -> V_70 ;
{
struct V_440 V_441 = {
. V_442 = V_13 ,
. V_439 = V_439 ,
} ;
V_27 = F_218 ( V_70 , V_49 , V_75 , & V_441 ) ;
}
F_1 () ;
return V_27 ;
}
V_11 = F_15 ( V_45 , type ) ;
if ( V_11 == NULL )
return - V_177 ;
return V_11 ( V_49 , V_75 ) ;
}
static void F_219 ( struct V_48 * V_49 )
{
F_1 () ;
F_220 ( V_49 , & F_216 ) ;
F_5 () ;
}
static int F_221 ( struct V_443 * V_444 , unsigned long V_445 , void * V_446 )
{
struct V_29 * V_30 = F_222 ( V_446 ) ;
switch ( V_445 ) {
case V_447 :
case V_448 :
case V_449 :
case V_450 :
case V_451 :
case V_452 :
case V_453 :
case V_454 :
case V_455 :
case V_456 :
case V_457 :
case V_458 :
break;
default:
F_184 ( V_289 , V_30 , 0 , V_15 ) ;
break;
}
return V_459 ;
}
static int T_11 F_223 ( struct V_28 * V_28 )
{
struct V_69 * V_272 ;
struct V_460 V_461 = {
. V_462 = V_463 ,
. V_464 = F_219 ,
. V_465 = & V_1 ,
. V_76 = V_466 ,
} ;
V_272 = F_224 ( V_28 , V_467 , & V_461 ) ;
if ( ! V_272 )
return - V_330 ;
V_28 -> V_70 = V_272 ;
return 0 ;
}
static void T_12 F_225 ( struct V_28 * V_28 )
{
F_226 ( V_28 -> V_70 ) ;
V_28 -> V_70 = NULL ;
}
void T_13 F_227 ( void )
{
if ( F_228 ( & V_468 ) )
F_21 ( L_14 ) ;
F_229 ( & V_469 ) ;
F_20 ( V_12 , V_470 , F_178 ,
F_114 , F_181 ) ;
F_20 ( V_12 , V_471 , F_160 , NULL , NULL ) ;
F_20 ( V_12 , V_289 , F_172 , NULL , NULL ) ;
F_20 ( V_12 , V_472 , F_163 , NULL , NULL ) ;
F_20 ( V_12 , V_473 , NULL , F_183 , NULL ) ;
F_20 ( V_12 , V_474 , NULL , F_183 , NULL ) ;
F_20 ( V_475 , V_404 , F_195 , NULL , NULL ) ;
F_20 ( V_475 , V_406 , F_199 , NULL , NULL ) ;
F_20 ( V_475 , V_476 , NULL , F_205 , NULL ) ;
F_20 ( V_475 , V_470 , NULL , F_208 , NULL ) ;
F_20 ( V_475 , V_472 , F_215 , NULL , NULL ) ;
F_20 ( V_475 , V_471 , F_213 , NULL , NULL ) ;
}
