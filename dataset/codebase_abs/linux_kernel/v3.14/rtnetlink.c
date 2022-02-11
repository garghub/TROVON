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
void F_37 ( struct V_18 * V_20 )
{
F_1 () ;
F_34 ( V_20 ) ;
F_5 () ;
}
static T_4 F_38 ( const struct V_28 * V_29 )
{
struct V_28 * V_31 ;
const struct V_18 * V_20 ;
V_31 = F_39 ( (struct V_28 * ) V_29 ) ;
if ( ! V_31 )
return 0 ;
V_20 = V_31 -> V_18 ;
if ( ! V_20 || ! V_20 -> V_32 )
return 0 ;
return F_40 ( sizeof( struct V_33 ) ) +
V_20 -> V_32 ( V_31 , V_29 ) ;
}
static T_4 F_41 ( const struct V_28 * V_29 )
{
const struct V_18 * V_20 = V_29 -> V_18 ;
T_4 V_34 ;
if ( ! V_20 )
return 0 ;
V_34 = F_40 ( sizeof( struct V_33 ) ) +
F_40 ( strlen ( V_20 -> V_19 ) + 1 ) ;
if ( V_20 -> V_35 )
V_34 += F_40 ( sizeof( struct V_33 ) ) +
V_20 -> V_35 ( V_29 ) ;
if ( V_20 -> V_36 )
V_34 += F_40 ( V_20 -> V_36 ( V_29 ) ) ;
V_34 += F_38 ( V_29 ) ;
return V_34 ;
}
static const struct V_37 * F_42 ( const int V_38 )
{
const struct V_37 * V_20 ;
F_26 (ops, &rtnl_af_ops, list) {
if ( V_20 -> V_38 == V_38 )
return V_20 ;
}
return NULL ;
}
void F_43 ( struct V_37 * V_20 )
{
F_1 () ;
F_28 ( & V_20 -> V_24 , & V_37 ) ;
F_5 () ;
}
void F_44 ( struct V_37 * V_20 )
{
F_36 ( & V_20 -> V_24 ) ;
}
void F_45 ( struct V_37 * V_20 )
{
F_1 () ;
F_44 ( V_20 ) ;
F_5 () ;
}
static T_4 F_46 ( const struct V_28 * V_29 )
{
struct V_37 * V_39 ;
T_4 V_34 ;
V_34 = F_40 ( sizeof( struct V_33 ) ) ;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_39 -> V_40 ) {
V_34 += F_40 ( sizeof( struct V_33 ) ) +
V_39 -> V_40 ( V_29 ) ;
}
}
return V_34 ;
}
static bool F_47 ( const struct V_28 * V_29 )
{
struct V_28 * V_31 ;
V_31 = F_39 ( (struct V_28 * ) V_29 ) ;
if ( V_31 && V_31 -> V_18 )
return true ;
return false ;
}
static int F_48 ( struct V_41 * V_42 ,
const struct V_28 * V_29 )
{
struct V_28 * V_31 ;
const struct V_18 * V_20 ;
struct V_33 * V_43 ;
int V_26 ;
V_31 = F_39 ( (struct V_28 * ) V_29 ) ;
if ( ! V_31 )
return 0 ;
V_20 = V_31 -> V_18 ;
if ( ! V_20 )
return 0 ;
if ( F_49 ( V_42 , V_44 , V_20 -> V_19 ) < 0 )
return - V_45 ;
if ( V_20 -> V_46 ) {
V_43 = F_50 ( V_42 , V_47 ) ;
if ( ! V_43 )
return - V_45 ;
V_26 = V_20 -> V_46 ( V_42 , V_31 , V_29 ) ;
if ( V_26 < 0 )
goto V_48;
F_51 ( V_42 , V_43 ) ;
}
return 0 ;
V_48:
F_52 ( V_42 , V_43 ) ;
return V_26 ;
}
static int F_53 ( struct V_41 * V_42 ,
const struct V_28 * V_29 )
{
const struct V_18 * V_20 = V_29 -> V_18 ;
struct V_33 * V_49 ;
int V_26 ;
if ( ! V_20 )
return 0 ;
if ( F_49 ( V_42 , V_50 , V_20 -> V_19 ) < 0 )
return - V_45 ;
if ( V_20 -> V_51 ) {
V_26 = V_20 -> V_51 ( V_42 , V_29 ) ;
if ( V_26 < 0 )
return V_26 ;
}
if ( V_20 -> V_52 ) {
V_49 = F_50 ( V_42 , V_53 ) ;
if ( V_49 == NULL )
return - V_45 ;
V_26 = V_20 -> V_52 ( V_42 , V_29 ) ;
if ( V_26 < 0 )
goto V_54;
F_51 ( V_42 , V_49 ) ;
}
return 0 ;
V_54:
F_52 ( V_42 , V_49 ) ;
return V_26 ;
}
static int F_54 ( struct V_41 * V_42 , const struct V_28 * V_29 )
{
struct V_33 * V_55 ;
int V_26 = - V_45 ;
V_55 = F_50 ( V_42 , V_56 ) ;
if ( V_55 == NULL )
goto V_57;
V_26 = F_53 ( V_42 , V_29 ) ;
if ( V_26 < 0 )
goto V_58;
V_26 = F_48 ( V_42 , V_29 ) ;
if ( V_26 < 0 )
goto V_58;
F_51 ( V_42 , V_55 ) ;
return 0 ;
V_58:
F_52 ( V_42 , V_55 ) ;
V_57:
return V_26 ;
}
int F_55 ( struct V_41 * V_42 , struct V_27 * V_27 , T_5 V_59 , unsigned int V_60 , int V_61 )
{
struct V_62 * V_63 = V_27 -> V_63 ;
int V_26 = 0 ;
F_56 ( V_42 ) . V_64 = V_60 ;
if ( V_61 )
F_57 ( & V_42 -> V_65 ) ;
F_58 ( V_63 , V_42 , V_59 , V_60 , V_15 ) ;
if ( V_61 )
V_26 = F_59 ( V_63 , V_42 , V_59 , V_66 ) ;
return V_26 ;
}
int F_60 ( struct V_41 * V_42 , struct V_27 * V_27 , T_5 V_59 )
{
struct V_62 * V_63 = V_27 -> V_63 ;
return F_61 ( V_63 , V_42 , V_59 ) ;
}
void F_62 ( struct V_41 * V_42 , struct V_27 * V_27 , T_5 V_59 , T_5 V_60 ,
struct V_67 * V_68 , T_6 V_69 )
{
struct V_62 * V_63 = V_27 -> V_63 ;
int V_70 = 0 ;
if ( V_68 )
V_70 = F_63 ( V_68 ) ;
F_64 ( V_63 , V_42 , V_59 , V_60 , V_70 , V_69 ) ;
}
void F_65 ( struct V_27 * V_27 , T_5 V_60 , int error )
{
struct V_62 * V_63 = V_27 -> V_63 ;
F_66 ( V_63 , 0 , V_60 , error ) ;
}
int F_67 ( struct V_41 * V_42 , T_5 * V_71 )
{
struct V_33 * V_72 ;
int V_73 , V_74 = 0 ;
V_72 = F_50 ( V_42 , V_75 ) ;
if ( V_72 == NULL )
return - V_16 ;
for ( V_73 = 0 ; V_73 < V_76 ; V_73 ++ ) {
if ( V_71 [ V_73 ] ) {
V_74 ++ ;
if ( F_68 ( V_42 , V_73 + 1 , V_71 [ V_73 ] ) )
goto V_77;
}
}
if ( ! V_74 ) {
F_52 ( V_42 , V_72 ) ;
return 0 ;
}
return F_51 ( V_42 , V_72 ) ;
V_77:
F_52 ( V_42 , V_72 ) ;
return - V_45 ;
}
int F_69 ( struct V_41 * V_42 , struct V_78 * V_79 , T_5 V_80 ,
long V_81 , T_5 error )
{
struct V_82 V_83 = {
. V_84 = F_70 ( V_85 - V_79 -> V_86 ) ,
. V_87 = V_79 -> V_88 ,
. V_89 = F_71 ( & ( V_79 -> V_90 ) ) ,
. V_91 = error ,
. V_92 = V_80 ,
} ;
if ( V_81 ) {
unsigned long clock ;
clock = F_72 ( abs ( V_81 ) ) ;
clock = F_73 (unsigned long, clock, INT_MAX) ;
V_83 . V_93 = ( V_81 > 0 ) ? clock : - clock ;
}
return F_74 ( V_42 , V_94 , sizeof( V_83 ) , & V_83 ) ;
}
static void F_75 ( struct V_28 * V_29 , unsigned char V_95 )
{
unsigned char V_96 = V_29 -> V_96 ;
switch ( V_95 ) {
case V_97 :
if ( ( V_96 == V_98 ||
V_96 == V_99 ) &&
! F_76 ( V_29 ) )
V_96 = V_97 ;
break;
case V_98 :
if ( V_96 == V_97 ||
V_96 == V_99 )
V_96 = V_98 ;
break;
}
if ( V_29 -> V_96 != V_96 ) {
F_77 ( & V_100 ) ;
V_29 -> V_96 = V_96 ;
F_78 ( & V_100 ) ;
F_79 ( V_29 ) ;
}
}
static unsigned int F_80 ( const struct V_28 * V_29 )
{
return ( V_29 -> V_69 & ~ ( V_101 | V_102 ) ) |
( V_29 -> V_103 & ( V_101 | V_102 ) ) ;
}
static unsigned int F_81 ( const struct V_28 * V_29 ,
const struct V_104 * V_105 )
{
unsigned int V_69 = V_105 -> V_106 ;
if ( V_105 -> V_107 )
V_69 = ( V_69 & V_105 -> V_107 ) |
( F_80 ( V_29 ) & ~ V_105 -> V_107 ) ;
return V_69 ;
}
static void F_82 ( struct V_108 * V_109 ,
const struct V_110 * V_111 )
{
V_109 -> V_112 = V_111 -> V_112 ;
V_109 -> V_113 = V_111 -> V_113 ;
V_109 -> V_114 = V_111 -> V_114 ;
V_109 -> V_115 = V_111 -> V_115 ;
V_109 -> V_116 = V_111 -> V_116 ;
V_109 -> V_117 = V_111 -> V_117 ;
V_109 -> V_118 = V_111 -> V_118 ;
V_109 -> V_119 = V_111 -> V_119 ;
V_109 -> V_120 = V_111 -> V_120 ;
V_109 -> V_121 = V_111 -> V_121 ;
V_109 -> V_122 = V_111 -> V_122 ;
V_109 -> V_123 = V_111 -> V_123 ;
V_109 -> V_124 = V_111 -> V_124 ;
V_109 -> V_125 = V_111 -> V_125 ;
V_109 -> V_126 = V_111 -> V_126 ;
V_109 -> V_127 = V_111 -> V_127 ;
V_109 -> V_128 = V_111 -> V_128 ;
V_109 -> V_129 = V_111 -> V_129 ;
V_109 -> V_130 = V_111 -> V_130 ;
V_109 -> V_131 = V_111 -> V_131 ;
V_109 -> V_132 = V_111 -> V_132 ;
V_109 -> V_133 = V_111 -> V_133 ;
V_109 -> V_134 = V_111 -> V_134 ;
}
static void F_83 ( void * V_135 , const struct V_110 * V_111 )
{
memcpy ( V_135 , V_111 , sizeof( * V_111 ) ) ;
}
static inline int F_84 ( const struct V_28 * V_29 ,
T_5 V_136 )
{
if ( V_29 -> V_29 . V_137 && F_85 ( V_29 -> V_29 . V_137 ) &&
( V_136 & V_138 ) ) {
int V_139 = F_86 ( V_29 -> V_29 . V_137 ) ;
T_4 V_34 = F_40 ( sizeof( struct V_33 ) ) ;
V_34 += F_40 ( V_139 * sizeof( struct V_33 ) ) ;
V_34 += V_139 *
( F_40 ( sizeof( struct V_140 ) ) +
F_40 ( sizeof( struct V_141 ) ) +
F_40 ( sizeof( struct V_142 ) ) +
F_40 ( sizeof( struct V_143 ) ) ) ;
return V_34 ;
} else
return 0 ;
}
static T_4 F_87 ( const struct V_28 * V_29 )
{
T_4 V_144 = F_40 ( 4 )
+ F_40 ( V_145 )
+ F_40 ( sizeof( struct V_146 ) )
+ F_40 ( V_147 )
+ F_40 ( V_147 )
+ F_40 ( 1 )
+ F_40 ( 2 ) ;
T_4 V_148 = F_40 ( sizeof( struct V_33 ) ) ;
T_4 V_149 = F_40 ( sizeof( struct V_33 ) )
+ V_144 ;
T_4 V_150 = F_40 ( sizeof( struct V_33 ) )
+ V_144 ;
if ( ! V_29 -> V_151 -> V_152 || ! V_29 -> V_29 . V_137 )
return 0 ;
if ( F_86 ( V_29 -> V_29 . V_137 ) )
return V_150 + V_148 +
V_149 * F_86 ( V_29 -> V_29 . V_137 ) ;
else
return V_150 ;
}
static T_7 T_4 F_88 ( const struct V_28 * V_29 ,
T_5 V_136 )
{
return F_89 ( sizeof( struct V_104 ) )
+ F_40 ( V_153 )
+ F_40 ( V_154 )
+ F_40 ( V_153 )
+ F_40 ( sizeof( struct V_155 ) )
+ F_40 ( sizeof( struct V_108 ) )
+ F_40 ( sizeof( struct V_110 ) )
+ F_40 ( V_156 )
+ F_40 ( V_156 )
+ F_40 ( 4 )
+ F_40 ( 4 )
+ F_40 ( 4 )
+ F_40 ( 4 )
+ F_40 ( 4 )
+ F_40 ( 1 )
+ F_40 ( 4 )
+ F_40 ( 4 )
+ F_40 ( 4 )
+ F_40 ( 1 )
+ F_40 ( 1 )
+ F_40 ( V_136
& V_138 ? 4 : 0 )
+ F_84 ( V_29 , V_136 )
+ F_87 ( V_29 )
+ F_41 ( V_29 )
+ F_46 ( V_29 )
+ F_40 ( V_157 ) ;
}
static int F_90 ( struct V_41 * V_42 , struct V_28 * V_29 )
{
struct V_33 * V_158 ;
struct V_33 * V_159 ;
int V_160 ;
int V_26 ;
V_158 = F_50 ( V_42 , V_161 ) ;
if ( ! V_158 )
return - V_45 ;
for ( V_160 = 0 ; V_160 < F_86 ( V_29 -> V_29 . V_137 ) ; V_160 ++ ) {
V_159 = F_50 ( V_42 , V_162 ) ;
if ( ! V_159 )
goto V_77;
if ( F_68 ( V_42 , V_163 , V_160 ) )
goto V_77;
V_26 = V_29 -> V_151 -> V_152 ( V_29 , V_160 , V_42 ) ;
if ( V_26 == - V_45 )
goto V_77;
if ( V_26 ) {
F_52 ( V_42 , V_159 ) ;
continue;
}
F_51 ( V_42 , V_159 ) ;
}
F_51 ( V_42 , V_158 ) ;
return 0 ;
V_77:
F_52 ( V_42 , V_158 ) ;
return - V_45 ;
}
static int F_91 ( struct V_41 * V_42 , struct V_28 * V_29 )
{
struct V_33 * V_164 ;
int V_26 ;
V_164 = F_50 ( V_42 , V_165 ) ;
if ( ! V_164 )
return - V_45 ;
V_26 = V_29 -> V_151 -> V_152 ( V_29 , V_166 , V_42 ) ;
if ( V_26 ) {
F_52 ( V_42 , V_164 ) ;
return ( V_26 == - V_45 ) ? V_26 : 0 ;
}
F_51 ( V_42 , V_164 ) ;
return 0 ;
}
static int F_92 ( struct V_41 * V_42 , struct V_28 * V_29 )
{
int V_26 ;
if ( ! V_29 -> V_151 -> V_152 || ! V_29 -> V_29 . V_137 )
return 0 ;
V_26 = F_91 ( V_42 , V_29 ) ;
if ( V_26 )
return V_26 ;
if ( F_86 ( V_29 -> V_29 . V_137 ) ) {
V_26 = F_90 ( V_42 , V_29 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_93 ( struct V_41 * V_42 , struct V_28 * V_29 )
{
int V_26 ;
struct V_167 V_168 ;
V_26 = F_94 ( V_29 , & V_168 ) ;
if ( V_26 ) {
if ( V_26 == - V_169 )
return 0 ;
return V_26 ;
}
if ( F_74 ( V_42 , V_170 , V_168 . V_171 , V_168 . V_80 ) )
return - V_45 ;
return 0 ;
}
static int F_95 ( struct V_41 * V_42 , struct V_28 * V_29 ,
int type , T_5 V_59 , T_5 V_172 , T_5 V_173 ,
unsigned int V_69 , T_5 V_136 )
{
struct V_104 * V_105 ;
struct V_67 * V_68 ;
struct V_110 V_174 ;
const struct V_110 * V_175 ;
struct V_33 * V_176 , * V_177 ;
struct V_37 * V_39 ;
struct V_28 * V_178 = F_39 ( V_29 ) ;
F_96 () ;
V_68 = F_97 ( V_42 , V_59 , V_172 , type , sizeof( * V_105 ) , V_69 ) ;
if ( V_68 == NULL )
return - V_45 ;
V_105 = F_98 ( V_68 ) ;
V_105 -> V_179 = V_180 ;
V_105 -> V_181 = 0 ;
V_105 -> V_182 = V_29 -> type ;
V_105 -> V_183 = V_29 -> V_184 ;
V_105 -> V_106 = F_99 ( V_29 ) ;
V_105 -> V_107 = V_173 ;
if ( F_49 ( V_42 , V_185 , V_29 -> V_186 ) ||
F_68 ( V_42 , V_187 , V_29 -> V_188 ) ||
F_100 ( V_42 , V_189 ,
F_101 ( V_29 ) ? V_29 -> V_96 : V_190 ) ||
F_100 ( V_42 , V_191 , V_29 -> V_192 ) ||
F_68 ( V_42 , V_193 , V_29 -> V_194 ) ||
F_68 ( V_42 , V_195 , V_29 -> V_60 ) ||
F_68 ( V_42 , V_196 , V_29 -> V_197 ) ||
F_68 ( V_42 , V_198 , V_29 -> V_199 ) ||
#ifdef F_102
F_68 ( V_42 , V_200 , V_29 -> V_201 ) ||
#endif
( V_29 -> V_184 != V_29 -> V_202 &&
F_68 ( V_42 , V_203 , V_29 -> V_202 ) ) ||
( V_178 &&
F_68 ( V_42 , V_204 , V_178 -> V_184 ) ) ||
F_100 ( V_42 , V_205 , F_103 ( V_29 ) ) ||
( V_29 -> V_206 &&
F_49 ( V_42 , V_207 , V_29 -> V_206 -> V_20 -> V_80 ) ) ||
( V_29 -> V_208 &&
F_49 ( V_42 , V_209 , V_29 -> V_208 ) ) )
goto V_77;
if ( 1 ) {
struct V_155 V_210 = {
. V_211 = V_29 -> V_211 ,
. V_212 = V_29 -> V_212 ,
. V_213 = V_29 -> V_213 ,
. V_214 = V_29 -> V_214 ,
. V_215 = V_29 -> V_215 ,
. V_216 = V_29 -> V_217 ,
} ;
if ( F_74 ( V_42 , V_218 , sizeof( V_210 ) , & V_210 ) )
goto V_77;
}
if ( V_29 -> V_219 ) {
if ( F_74 ( V_42 , V_220 , V_29 -> V_219 , V_29 -> V_221 ) ||
F_74 ( V_42 , V_222 , V_29 -> V_219 , V_29 -> V_223 ) )
goto V_77;
}
if ( F_93 ( V_42 , V_29 ) )
goto V_77;
V_176 = F_104 ( V_42 , V_224 ,
sizeof( struct V_108 ) ) ;
if ( V_176 == NULL )
goto V_77;
V_175 = F_105 ( V_29 , & V_174 ) ;
F_82 ( F_106 ( V_176 ) , V_175 ) ;
V_176 = F_104 ( V_42 , V_225 ,
sizeof( struct V_110 ) ) ;
if ( V_176 == NULL )
goto V_77;
F_83 ( F_106 ( V_176 ) , V_175 ) ;
if ( V_29 -> V_29 . V_137 && ( V_136 & V_138 ) &&
F_68 ( V_42 , V_226 , F_86 ( V_29 -> V_29 . V_137 ) ) )
goto V_77;
if ( V_29 -> V_151 -> V_227 && V_29 -> V_29 . V_137
&& ( V_136 & V_138 ) ) {
int V_73 ;
struct V_33 * V_228 , * V_160 ;
int V_139 = F_86 ( V_29 -> V_29 . V_137 ) ;
V_228 = F_50 ( V_42 , V_229 ) ;
if ( ! V_228 )
goto V_77;
for ( V_73 = 0 ; V_73 < V_139 ; V_73 ++ ) {
struct V_230 V_231 ;
struct V_140 V_232 ;
struct V_141 V_233 ;
struct V_142 V_234 ;
struct V_143 V_235 ;
struct V_236 V_237 ;
V_231 . V_238 = - 1 ;
memset ( V_231 . V_239 , 0 , sizeof( V_231 . V_239 ) ) ;
V_231 . V_240 = 0 ;
if ( V_29 -> V_151 -> V_227 ( V_29 , V_73 , & V_231 ) )
break;
V_232 . V_160 =
V_233 . V_160 =
V_234 . V_160 =
V_235 . V_160 =
V_237 . V_160 = V_231 . V_160 ;
memcpy ( V_232 . V_239 , V_231 . V_239 , sizeof( V_231 . V_239 ) ) ;
V_233 . V_241 = V_231 . V_241 ;
V_233 . V_242 = V_231 . V_242 ;
V_234 . V_243 = V_231 . V_244 ;
V_235 . V_245 = V_231 . V_238 ;
V_237 . V_246 = V_231 . V_240 ;
V_160 = F_50 ( V_42 , V_247 ) ;
if ( ! V_160 ) {
F_52 ( V_42 , V_228 ) ;
goto V_77;
}
if ( F_74 ( V_42 , V_248 , sizeof( V_232 ) , & V_232 ) ||
F_74 ( V_42 , V_249 , sizeof( V_233 ) , & V_233 ) ||
F_74 ( V_42 , V_250 , sizeof( V_234 ) ,
& V_234 ) ||
F_74 ( V_42 , V_251 , sizeof( V_235 ) ,
& V_235 ) ||
F_74 ( V_42 , V_252 , sizeof( V_237 ) ,
& V_237 ) )
goto V_77;
F_51 ( V_42 , V_160 ) ;
}
F_51 ( V_42 , V_228 ) ;
}
if ( F_92 ( V_42 , V_29 ) )
goto V_77;
if ( V_29 -> V_18 || F_47 ( V_29 ) ) {
if ( F_54 ( V_42 , V_29 ) < 0 )
goto V_77;
}
if ( ! ( V_177 = F_50 ( V_42 , V_253 ) ) )
goto V_77;
F_26 (af_ops, &rtnl_af_ops, list) {
if ( V_39 -> V_254 ) {
struct V_33 * V_255 ;
int V_26 ;
if ( ! ( V_255 = F_50 ( V_42 , V_39 -> V_38 ) ) )
goto V_77;
V_26 = V_39 -> V_254 ( V_42 , V_29 ) ;
if ( V_26 == - V_256 )
F_52 ( V_42 , V_255 ) ;
else if ( V_26 < 0 )
goto V_77;
F_51 ( V_42 , V_255 ) ;
}
}
F_51 ( V_42 , V_177 ) ;
return F_107 ( V_42 , V_68 ) ;
V_77:
F_108 ( V_42 , V_68 ) ;
return - V_45 ;
}
static int F_109 ( struct V_41 * V_42 , struct V_257 * V_258 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
int V_260 , V_261 ;
int V_262 = 0 , V_263 ;
struct V_28 * V_29 ;
struct V_264 * V_265 ;
struct V_33 * V_266 [ V_267 + 1 ] ;
T_5 V_136 = 0 ;
V_261 = V_258 -> args [ 0 ] ;
V_263 = V_258 -> args [ 1 ] ;
F_111 () ;
V_258 -> V_172 = V_27 -> V_268 ;
if ( F_112 ( V_258 -> V_68 , sizeof( struct V_104 ) , V_266 , V_267 ,
V_269 ) >= 0 ) {
if ( V_266 [ V_270 ] )
V_136 = F_113 ( V_266 [ V_270 ] ) ;
}
for ( V_260 = V_261 ; V_260 < V_271 ; V_260 ++ , V_263 = 0 ) {
V_262 = 0 ;
V_265 = & V_27 -> V_272 [ V_260 ] ;
F_114 (dev, head, index_hlist) {
if ( V_262 < V_263 )
goto V_273;
if ( F_95 ( V_42 , V_29 , V_274 ,
F_56 ( V_258 -> V_42 ) . V_275 ,
V_258 -> V_68 -> V_276 , 0 ,
V_277 ,
V_136 ) <= 0 )
goto V_57;
F_115 ( V_258 , F_116 ( V_42 ) ) ;
V_273:
V_262 ++ ;
}
}
V_57:
F_117 () ;
V_258 -> args [ 1 ] = V_262 ;
V_258 -> args [ 0 ] = V_260 ;
return V_42 -> V_278 ;
}
struct V_27 * F_118 ( struct V_27 * V_279 , struct V_33 * V_266 [] )
{
struct V_27 * V_27 ;
if ( V_266 [ V_280 ] )
V_27 = F_119 ( F_113 ( V_266 [ V_280 ] ) ) ;
else if ( V_266 [ V_281 ] )
V_27 = F_120 ( F_113 ( V_266 [ V_281 ] ) ) ;
else
V_27 = F_121 ( V_279 ) ;
return V_27 ;
}
static int F_122 ( struct V_28 * V_29 , struct V_33 * V_266 [] )
{
if ( V_29 ) {
if ( V_266 [ V_220 ] &&
F_123 ( V_266 [ V_220 ] ) < V_29 -> V_219 )
return - V_282 ;
if ( V_266 [ V_222 ] &&
F_123 ( V_266 [ V_222 ] ) < V_29 -> V_219 )
return - V_282 ;
}
if ( V_266 [ V_253 ] ) {
struct V_33 * V_255 ;
int V_283 , V_26 ;
F_124 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_37 * V_39 ;
if ( ! ( V_39 = F_42 ( F_125 ( V_255 ) ) ) )
return - V_284 ;
if ( ! V_39 -> V_285 )
return - V_169 ;
if ( V_39 -> V_286 ) {
V_26 = V_39 -> V_286 ( V_29 , V_255 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
}
return 0 ;
}
static int F_126 ( struct V_28 * V_29 , struct V_33 * V_176 )
{
int V_283 , V_26 = - V_282 ;
struct V_33 * V_160 ;
const struct V_287 * V_20 = V_29 -> V_151 ;
F_124 (vf, attr, rem) {
switch ( F_125 ( V_160 ) ) {
case V_248 : {
struct V_140 * V_288 ;
V_288 = F_106 ( V_160 ) ;
V_26 = - V_169 ;
if ( V_20 -> V_289 )
V_26 = V_20 -> V_289 ( V_29 , V_288 -> V_160 ,
V_288 -> V_239 ) ;
break;
}
case V_249 : {
struct V_141 * V_290 ;
V_290 = F_106 ( V_160 ) ;
V_26 = - V_169 ;
if ( V_20 -> V_291 )
V_26 = V_20 -> V_291 ( V_29 , V_290 -> V_160 ,
V_290 -> V_241 ,
V_290 -> V_242 ) ;
break;
}
case V_250 : {
struct V_142 * V_292 ;
V_292 = F_106 ( V_160 ) ;
V_26 = - V_169 ;
if ( V_20 -> V_293 )
V_26 = V_20 -> V_293 ( V_29 , V_292 -> V_160 ,
V_292 -> V_243 ) ;
break;
}
case V_251 : {
struct V_143 * V_294 ;
V_294 = F_106 ( V_160 ) ;
V_26 = - V_169 ;
if ( V_20 -> V_295 )
V_26 = V_20 -> V_295 ( V_29 , V_294 -> V_160 ,
V_294 -> V_245 ) ;
break;
}
case V_252 : {
struct V_236 * V_296 ;
V_296 = F_106 ( V_160 ) ;
V_26 = - V_169 ;
if ( V_20 -> V_297 )
V_26 = V_20 -> V_297 ( V_29 , V_296 -> V_160 ,
V_296 -> V_246 ) ;
break;
}
default:
V_26 = - V_282 ;
break;
}
if ( V_26 )
break;
}
return V_26 ;
}
static int F_127 ( struct V_28 * V_29 , int V_184 )
{
struct V_28 * V_178 = F_39 ( V_29 ) ;
const struct V_287 * V_20 ;
int V_26 ;
if ( V_178 ) {
if ( V_178 -> V_184 == V_184 )
return 0 ;
V_20 = V_178 -> V_151 ;
if ( V_20 -> V_298 ) {
V_26 = V_20 -> V_298 ( V_178 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_169 ;
}
}
if ( V_184 ) {
V_178 = F_128 ( F_129 ( V_29 ) , V_184 ) ;
if ( ! V_178 )
return - V_282 ;
V_20 = V_178 -> V_151 ;
if ( V_20 -> V_299 ) {
V_26 = V_20 -> V_299 ( V_178 , V_29 ) ;
if ( V_26 )
return V_26 ;
} else {
return - V_169 ;
}
}
return 0 ;
}
static int F_130 ( struct V_28 * V_29 , struct V_104 * V_105 ,
struct V_33 * * V_266 , char * V_300 , int V_301 )
{
const struct V_287 * V_20 = V_29 -> V_151 ;
int V_26 ;
if ( V_266 [ V_280 ] || V_266 [ V_281 ] ) {
struct V_27 * V_27 = F_118 ( F_129 ( V_29 ) , V_266 ) ;
if ( F_131 ( V_27 ) ) {
V_26 = F_132 ( V_27 ) ;
goto V_302;
}
if ( ! F_133 ( V_27 -> V_303 , V_304 ) ) {
V_26 = - V_305 ;
goto V_302;
}
V_26 = F_134 ( V_29 , V_27 , V_300 ) ;
F_135 ( V_27 ) ;
if ( V_26 )
goto V_302;
V_301 = 1 ;
}
if ( V_266 [ V_218 ] ) {
struct V_155 * V_306 ;
struct V_307 V_308 ;
if ( ! V_20 -> V_309 ) {
V_26 = - V_169 ;
goto V_302;
}
if ( ! F_136 ( V_29 ) ) {
V_26 = - V_310 ;
goto V_302;
}
V_306 = F_106 ( V_266 [ V_218 ] ) ;
V_308 . V_211 = ( unsigned long ) V_306 -> V_211 ;
V_308 . V_212 = ( unsigned long ) V_306 -> V_212 ;
V_308 . V_213 = ( unsigned short ) V_306 -> V_213 ;
V_308 . V_214 = ( unsigned char ) V_306 -> V_214 ;
V_308 . V_215 = ( unsigned char ) V_306 -> V_215 ;
V_308 . V_216 = ( unsigned char ) V_306 -> V_216 ;
V_26 = V_20 -> V_309 ( V_29 , & V_308 ) ;
if ( V_26 < 0 )
goto V_302;
V_301 = 1 ;
}
if ( V_266 [ V_220 ] ) {
struct V_311 * V_312 ;
int V_278 ;
V_278 = sizeof( V_313 ) + V_29 -> V_219 ;
V_312 = F_137 ( V_278 , V_15 ) ;
if ( ! V_312 ) {
V_26 = - V_314 ;
goto V_302;
}
V_312 -> V_315 = V_29 -> type ;
memcpy ( V_312 -> V_316 , F_106 ( V_266 [ V_220 ] ) ,
V_29 -> V_219 ) ;
V_26 = F_138 ( V_29 , V_312 ) ;
F_24 ( V_312 ) ;
if ( V_26 )
goto V_302;
V_301 = 1 ;
}
if ( V_266 [ V_193 ] ) {
V_26 = F_139 ( V_29 , F_113 ( V_266 [ V_193 ] ) ) ;
if ( V_26 < 0 )
goto V_302;
V_301 = 1 ;
}
if ( V_266 [ V_195 ] ) {
F_140 ( V_29 , F_113 ( V_266 [ V_195 ] ) ) ;
V_301 = 1 ;
}
if ( V_105 -> V_183 > 0 && V_300 [ 0 ] ) {
V_26 = F_141 ( V_29 , V_300 ) ;
if ( V_26 < 0 )
goto V_302;
V_301 = 1 ;
}
if ( V_266 [ V_209 ] ) {
V_26 = F_142 ( V_29 , F_106 ( V_266 [ V_209 ] ) ,
F_123 ( V_266 [ V_209 ] ) ) ;
if ( V_26 < 0 )
goto V_302;
V_301 = 1 ;
}
if ( V_266 [ V_222 ] ) {
F_143 ( V_29 -> V_223 , V_266 [ V_222 ] , V_29 -> V_219 ) ;
F_144 ( V_317 , V_29 ) ;
}
if ( V_105 -> V_106 || V_105 -> V_107 ) {
V_26 = F_145 ( V_29 , F_81 ( V_29 , V_105 ) ) ;
if ( V_26 < 0 )
goto V_302;
}
if ( V_266 [ V_204 ] ) {
V_26 = F_127 ( V_29 , F_113 ( V_266 [ V_204 ] ) ) ;
if ( V_26 )
goto V_302;
V_301 = 1 ;
}
if ( V_266 [ V_205 ] ) {
V_26 = F_146 ( V_29 , F_147 ( V_266 [ V_205 ] ) ) ;
if ( V_26 )
goto V_302;
V_301 = 1 ;
}
if ( V_266 [ V_187 ] )
V_29 -> V_188 = F_113 ( V_266 [ V_187 ] ) ;
if ( V_266 [ V_189 ] )
F_75 ( V_29 , F_147 ( V_266 [ V_189 ] ) ) ;
if ( V_266 [ V_191 ] ) {
F_77 ( & V_100 ) ;
V_29 -> V_192 = F_147 ( V_266 [ V_191 ] ) ;
F_78 ( & V_100 ) ;
}
if ( V_266 [ V_229 ] ) {
struct V_33 * V_176 ;
int V_283 ;
F_124 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_125 ( V_176 ) != V_247 ) {
V_26 = - V_282 ;
goto V_302;
}
V_26 = F_126 ( V_29 , V_176 ) ;
if ( V_26 < 0 )
goto V_302;
V_301 = 1 ;
}
}
V_26 = 0 ;
if ( V_266 [ V_161 ] ) {
struct V_33 * V_216 [ V_318 + 1 ] ;
struct V_33 * V_176 ;
int V_160 ;
int V_283 ;
V_26 = - V_169 ;
if ( ! V_20 -> V_319 )
goto V_302;
F_124 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_125 ( V_176 ) != V_162 )
continue;
V_26 = F_148 ( V_216 , V_318 ,
V_176 , V_320 ) ;
if ( V_26 < 0 )
goto V_302;
if ( ! V_216 [ V_163 ] ) {
V_26 = - V_169 ;
goto V_302;
}
V_160 = F_113 ( V_216 [ V_163 ] ) ;
V_26 = V_20 -> V_319 ( V_29 , V_160 , V_216 ) ;
if ( V_26 < 0 )
goto V_302;
V_301 = 1 ;
}
}
V_26 = 0 ;
if ( V_266 [ V_165 ] ) {
struct V_33 * V_216 [ V_318 + 1 ] ;
V_26 = F_148 ( V_216 , V_318 ,
V_266 [ V_165 ] , V_320 ) ;
if ( V_26 < 0 )
goto V_302;
V_26 = - V_169 ;
if ( V_20 -> V_319 )
V_26 = V_20 -> V_319 ( V_29 , V_166 , V_216 ) ;
if ( V_26 < 0 )
goto V_302;
V_301 = 1 ;
}
if ( V_266 [ V_253 ] ) {
struct V_33 * V_255 ;
int V_283 ;
F_124 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_37 * V_39 ;
if ( ! ( V_39 = F_42 ( F_125 ( V_255 ) ) ) )
F_149 () ;
V_26 = V_39 -> V_285 ( V_29 , V_255 ) ;
if ( V_26 < 0 )
goto V_302;
V_301 = 1 ;
}
}
V_26 = 0 ;
V_302:
if ( V_26 < 0 && V_301 )
F_150 ( L_3 ,
V_29 -> V_186 ) ;
return V_26 ;
}
static int F_151 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
struct V_104 * V_105 ;
struct V_28 * V_29 ;
int V_26 ;
struct V_33 * V_266 [ V_267 + 1 ] ;
char V_300 [ V_153 ] ;
V_26 = F_112 ( V_68 , sizeof( * V_105 ) , V_266 , V_267 , V_269 ) ;
if ( V_26 < 0 )
goto V_302;
if ( V_266 [ V_185 ] )
F_152 ( V_300 , V_266 [ V_185 ] , V_153 ) ;
else
V_300 [ 0 ] = '\0' ;
V_26 = - V_282 ;
V_105 = F_98 ( V_68 ) ;
if ( V_105 -> V_183 > 0 )
V_29 = F_128 ( V_27 , V_105 -> V_183 ) ;
else if ( V_266 [ V_185 ] )
V_29 = F_153 ( V_27 , V_300 ) ;
else
goto V_302;
if ( V_29 == NULL ) {
V_26 = - V_310 ;
goto V_302;
}
V_26 = F_122 ( V_29 , V_266 ) ;
if ( V_26 < 0 )
goto V_302;
V_26 = F_130 ( V_29 , V_105 , V_266 , V_300 , 0 ) ;
V_302:
return V_26 ;
}
static int F_154 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
const struct V_18 * V_20 ;
struct V_28 * V_29 ;
struct V_104 * V_105 ;
char V_300 [ V_153 ] ;
struct V_33 * V_266 [ V_267 + 1 ] ;
int V_26 ;
F_31 ( V_30 ) ;
V_26 = F_112 ( V_68 , sizeof( * V_105 ) , V_266 , V_267 , V_269 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_266 [ V_185 ] )
F_152 ( V_300 , V_266 [ V_185 ] , V_153 ) ;
V_105 = F_98 ( V_68 ) ;
if ( V_105 -> V_183 > 0 )
V_29 = F_128 ( V_27 , V_105 -> V_183 ) ;
else if ( V_266 [ V_185 ] )
V_29 = F_153 ( V_27 , V_300 ) ;
else
return - V_282 ;
if ( ! V_29 )
return - V_310 ;
V_20 = V_29 -> V_18 ;
if ( ! V_20 )
return - V_169 ;
V_20 -> V_22 ( V_29 , & V_30 ) ;
F_33 ( & V_30 ) ;
F_36 ( & V_30 ) ;
return 0 ;
}
int F_155 ( struct V_28 * V_29 , const struct V_104 * V_105 )
{
unsigned int V_321 ;
int V_26 ;
V_321 = V_29 -> V_69 ;
if ( V_105 && ( V_105 -> V_106 || V_105 -> V_107 ) ) {
V_26 = F_156 ( V_29 , F_81 ( V_29 , V_105 ) ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_29 -> V_322 = V_323 ;
F_157 ( V_29 , V_321 , ~ 0U ) ;
return 0 ;
}
struct V_28 * F_158 ( struct V_27 * V_27 ,
char * V_300 , const struct V_18 * V_20 , struct V_33 * V_266 [] )
{
int V_26 ;
struct V_28 * V_29 ;
unsigned int V_199 = 1 ;
unsigned int V_201 = 1 ;
if ( V_266 [ V_198 ] )
V_199 = F_113 ( V_266 [ V_198 ] ) ;
else if ( V_20 -> V_324 )
V_199 = V_20 -> V_324 () ;
if ( V_266 [ V_200 ] )
V_201 = F_113 ( V_266 [ V_200 ] ) ;
else if ( V_20 -> V_325 )
V_201 = V_20 -> V_325 () ;
V_26 = - V_314 ;
V_29 = F_159 ( V_20 -> V_326 , V_300 , V_20 -> V_327 ,
V_199 , V_201 ) ;
if ( ! V_29 )
goto V_26;
F_160 ( V_29 , V_27 ) ;
V_29 -> V_18 = V_20 ;
V_29 -> V_322 = V_328 ;
if ( V_266 [ V_193 ] )
V_29 -> V_194 = F_113 ( V_266 [ V_193 ] ) ;
if ( V_266 [ V_220 ] ) {
memcpy ( V_29 -> V_221 , F_106 ( V_266 [ V_220 ] ) ,
F_123 ( V_266 [ V_220 ] ) ) ;
V_29 -> V_329 = V_330 ;
}
if ( V_266 [ V_222 ] )
memcpy ( V_29 -> V_223 , F_106 ( V_266 [ V_222 ] ) ,
F_123 ( V_266 [ V_222 ] ) ) ;
if ( V_266 [ V_187 ] )
V_29 -> V_188 = F_113 ( V_266 [ V_187 ] ) ;
if ( V_266 [ V_189 ] )
F_75 ( V_29 , F_147 ( V_266 [ V_189 ] ) ) ;
if ( V_266 [ V_191 ] )
V_29 -> V_192 = F_147 ( V_266 [ V_191 ] ) ;
if ( V_266 [ V_195 ] )
F_140 ( V_29 , F_113 ( V_266 [ V_195 ] ) ) ;
return V_29 ;
V_26:
return F_161 ( V_26 ) ;
}
static int F_162 ( struct V_27 * V_27 , int V_60 ,
struct V_104 * V_105 ,
struct V_33 * * V_266 )
{
struct V_28 * V_29 ;
int V_26 ;
F_32 (net, dev) {
if ( V_29 -> V_60 == V_60 ) {
V_26 = F_130 ( V_29 , V_105 , V_266 , NULL , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
return 0 ;
}
static int F_163 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
const struct V_18 * V_20 ;
const struct V_18 * V_331 = NULL ;
struct V_28 * V_29 ;
struct V_28 * V_31 = NULL ;
struct V_104 * V_105 ;
char V_19 [ V_332 ] ;
char V_300 [ V_153 ] ;
struct V_33 * V_266 [ V_267 + 1 ] ;
struct V_33 * V_55 [ V_333 + 1 ] ;
int V_26 ;
#ifdef F_164
V_334:
#endif
V_26 = F_112 ( V_68 , sizeof( * V_105 ) , V_266 , V_267 , V_269 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_266 [ V_185 ] )
F_152 ( V_300 , V_266 [ V_185 ] , V_153 ) ;
else
V_300 [ 0 ] = '\0' ;
V_105 = F_98 ( V_68 ) ;
if ( V_105 -> V_183 > 0 )
V_29 = F_128 ( V_27 , V_105 -> V_183 ) ;
else {
if ( V_300 [ 0 ] )
V_29 = F_153 ( V_27 , V_300 ) ;
else
V_29 = NULL ;
}
if ( V_29 ) {
V_31 = F_39 ( V_29 ) ;
if ( V_31 )
V_331 = V_31 -> V_18 ;
}
V_26 = F_122 ( V_29 , V_266 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_266 [ V_56 ] ) {
V_26 = F_148 ( V_55 , V_333 ,
V_266 [ V_56 ] , V_335 ) ;
if ( V_26 < 0 )
return V_26 ;
} else
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
if ( V_55 [ V_50 ] ) {
F_152 ( V_19 , V_55 [ V_50 ] , sizeof( V_19 ) ) ;
V_20 = F_25 ( V_19 ) ;
} else {
V_19 [ 0 ] = '\0' ;
V_20 = NULL ;
}
if ( 1 ) {
struct V_33 * V_176 [ V_20 ? V_20 -> V_336 + 1 : 0 ] ;
struct V_33 * V_337 [ V_331 ? V_331 -> V_338 + 1 : 0 ] ;
struct V_33 * * V_49 = NULL ;
struct V_33 * * V_43 = NULL ;
struct V_27 * V_339 ;
if ( V_20 ) {
if ( V_20 -> V_336 && V_55 [ V_53 ] ) {
V_26 = F_148 ( V_176 , V_20 -> V_336 ,
V_55 [ V_53 ] ,
V_20 -> V_340 ) ;
if ( V_26 < 0 )
return V_26 ;
V_49 = V_176 ;
}
if ( V_20 -> V_341 ) {
V_26 = V_20 -> V_341 ( V_266 , V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_331 ) {
if ( V_331 -> V_338 &&
V_55 [ V_47 ] ) {
V_26 = F_148 ( V_337 ,
V_331 -> V_338 ,
V_55 [ V_47 ] ,
V_331 -> V_342 ) ;
if ( V_26 < 0 )
return V_26 ;
V_43 = V_337 ;
}
if ( V_331 -> V_343 ) {
V_26 = V_331 -> V_343 ( V_266 , V_43 ) ;
if ( V_26 < 0 )
return V_26 ;
}
}
if ( V_29 ) {
int V_301 = 0 ;
if ( V_68 -> V_344 & V_345 )
return - V_21 ;
if ( V_68 -> V_344 & V_346 )
return - V_169 ;
if ( V_55 [ V_53 ] ) {
if ( ! V_20 || V_20 != V_29 -> V_18 ||
! V_20 -> V_347 )
return - V_169 ;
V_26 = V_20 -> V_347 ( V_29 , V_266 , V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
V_301 = 1 ;
}
if ( V_55 [ V_47 ] ) {
if ( ! V_331 || ! V_331 -> V_348 )
return - V_169 ;
V_26 = V_331 -> V_348 ( V_31 , V_29 ,
V_266 , V_43 ) ;
if ( V_26 < 0 )
return V_26 ;
V_301 = 1 ;
}
return F_130 ( V_29 , V_105 , V_266 , V_300 , V_301 ) ;
}
if ( ! ( V_68 -> V_344 & V_349 ) ) {
if ( V_105 -> V_183 == 0 && V_266 [ V_195 ] )
return F_162 ( V_27 ,
F_113 ( V_266 [ V_195 ] ) ,
V_105 , V_266 ) ;
return - V_310 ;
}
if ( V_266 [ V_218 ] || V_266 [ V_204 ] || V_266 [ V_350 ] )
return - V_169 ;
if ( ! V_20 ) {
#ifdef F_164
if ( V_19 [ 0 ] ) {
F_3 () ;
F_165 ( L_4 , V_19 ) ;
F_1 () ;
V_20 = F_25 ( V_19 ) ;
if ( V_20 )
goto V_334;
}
#endif
return - V_169 ;
}
if ( ! V_300 [ 0 ] )
snprintf ( V_300 , V_153 , L_5 , V_20 -> V_19 ) ;
V_339 = F_118 ( V_27 , V_266 ) ;
if ( F_131 ( V_339 ) )
return F_132 ( V_339 ) ;
V_29 = F_158 ( V_339 , V_300 , V_20 , V_266 ) ;
if ( F_131 ( V_29 ) ) {
V_26 = F_132 ( V_29 ) ;
goto V_57;
}
V_29 -> V_184 = V_105 -> V_183 ;
if ( V_20 -> V_351 ) {
V_26 = V_20 -> V_351 ( V_27 , V_29 , V_266 , V_49 ) ;
if ( V_26 < 0 )
goto V_57;
} else {
V_26 = F_166 ( V_29 ) ;
if ( V_26 < 0 ) {
F_167 ( V_29 ) ;
goto V_57;
}
}
V_26 = F_155 ( V_29 , V_105 ) ;
if ( V_26 < 0 )
F_168 ( V_29 ) ;
V_57:
F_135 ( V_339 ) ;
return V_26 ;
}
}
static int F_169 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
struct V_104 * V_105 ;
char V_300 [ V_153 ] ;
struct V_33 * V_266 [ V_267 + 1 ] ;
struct V_28 * V_29 = NULL ;
struct V_41 * V_352 ;
int V_26 ;
T_5 V_136 = 0 ;
V_26 = F_112 ( V_68 , sizeof( * V_105 ) , V_266 , V_267 , V_269 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_266 [ V_185 ] )
F_152 ( V_300 , V_266 [ V_185 ] , V_153 ) ;
if ( V_266 [ V_270 ] )
V_136 = F_113 ( V_266 [ V_270 ] ) ;
V_105 = F_98 ( V_68 ) ;
if ( V_105 -> V_183 > 0 )
V_29 = F_128 ( V_27 , V_105 -> V_183 ) ;
else if ( V_266 [ V_185 ] )
V_29 = F_153 ( V_27 , V_300 ) ;
else
return - V_282 ;
if ( V_29 == NULL )
return - V_310 ;
V_352 = F_170 ( F_88 ( V_29 , V_136 ) , V_15 ) ;
if ( V_352 == NULL )
return - V_16 ;
V_26 = F_95 ( V_352 , V_29 , V_274 , F_56 ( V_42 ) . V_275 ,
V_68 -> V_276 , 0 , 0 , V_136 ) ;
if ( V_26 < 0 ) {
F_171 ( V_26 == - V_45 ) ;
F_172 ( V_352 ) ;
} else
V_26 = F_60 ( V_352 , V_27 , F_56 ( V_42 ) . V_275 ) ;
return V_26 ;
}
static T_8 F_173 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
struct V_28 * V_29 ;
struct V_33 * V_266 [ V_267 + 1 ] ;
T_5 V_136 = 0 ;
T_8 V_353 = 0 ;
if ( F_112 ( V_68 , sizeof( struct V_104 ) , V_266 , V_267 ,
V_269 ) >= 0 ) {
if ( V_266 [ V_270 ] )
V_136 = F_113 ( V_266 [ V_270 ] ) ;
}
if ( ! V_136 )
return V_354 ;
F_26 (dev, &net->dev_base_head, dev_list) {
V_353 = F_174 ( T_8 , V_353 ,
F_88 ( V_29 ,
V_136 ) ) ;
}
return V_353 ;
}
static int F_175 ( struct V_41 * V_42 , struct V_257 * V_258 )
{
int V_262 ;
int V_263 = V_258 -> V_38 ;
if ( V_263 == 0 )
V_263 = 1 ;
for ( V_262 = 1 ; V_262 <= V_9 ; V_262 ++ ) {
int type = V_258 -> V_68 -> V_355 - V_4 ;
if ( V_262 < V_263 || V_262 == V_356 )
continue;
if ( V_10 [ V_262 ] == NULL ||
V_10 [ V_262 ] [ type ] . V_13 == NULL )
continue;
if ( V_262 > V_263 ) {
memset ( & V_258 -> args [ 0 ] , 0 , sizeof( V_258 -> args ) ) ;
V_258 -> V_357 = 0 ;
V_258 -> V_172 = 0 ;
}
if ( V_10 [ V_262 ] [ type ] . V_13 ( V_42 , V_258 ) )
break;
}
V_258 -> V_38 = V_262 ;
return V_42 -> V_278 ;
}
void F_176 ( int type , struct V_28 * V_29 , unsigned int V_173 ,
T_6 V_69 )
{
struct V_27 * V_27 = F_129 ( V_29 ) ;
struct V_41 * V_42 ;
int V_26 = - V_16 ;
T_4 V_358 ;
V_42 = F_170 ( ( V_358 = F_88 ( V_29 , 0 ) ) , V_69 ) ;
if ( V_42 == NULL )
goto V_302;
V_26 = F_95 ( V_42 , V_29 , type , 0 , 0 , V_173 , 0 , 0 ) ;
if ( V_26 < 0 ) {
F_171 ( V_26 == - V_45 ) ;
F_172 ( V_42 ) ;
goto V_302;
}
F_62 ( V_42 , V_27 , 0 , V_359 , NULL , V_69 ) ;
return;
V_302:
if ( V_26 < 0 )
F_65 ( V_27 , V_359 , V_26 ) ;
}
static int F_177 ( struct V_41 * V_42 ,
struct V_28 * V_29 ,
T_9 * V_360 , T_5 V_59 , T_5 V_172 ,
int type , unsigned int V_69 ,
int V_361 )
{
struct V_67 * V_68 ;
struct V_362 * V_363 ;
V_68 = F_97 ( V_42 , V_59 , V_172 , type , sizeof( * V_363 ) , V_361 ) ;
if ( ! V_68 )
return - V_45 ;
V_363 = F_98 ( V_68 ) ;
V_363 -> V_364 = V_365 ;
V_363 -> V_366 = 0 ;
V_363 -> V_367 = 0 ;
V_363 -> V_368 = V_69 ;
V_363 -> V_369 = 0 ;
V_363 -> V_370 = V_29 -> V_184 ;
V_363 -> V_371 = V_372 ;
if ( F_74 ( V_42 , V_373 , V_374 , V_360 ) )
goto V_77;
return F_107 ( V_42 , V_68 ) ;
V_77:
F_108 ( V_42 , V_68 ) ;
return - V_45 ;
}
static inline T_4 F_178 ( void )
{
return F_89 ( sizeof( struct V_362 ) ) + F_40 ( V_374 ) ;
}
static void F_179 ( struct V_28 * V_29 , T_9 * V_360 , int type )
{
struct V_27 * V_27 = F_129 ( V_29 ) ;
struct V_41 * V_42 ;
int V_26 = - V_16 ;
V_42 = F_170 ( F_178 () , V_375 ) ;
if ( ! V_42 )
goto V_302;
V_26 = F_177 ( V_42 , V_29 , V_360 , 0 , 0 , type , V_376 , 0 ) ;
if ( V_26 < 0 ) {
F_172 ( V_42 ) ;
goto V_302;
}
F_62 ( V_42 , V_27 , 0 , V_377 , NULL , V_375 ) ;
return;
V_302:
F_65 ( V_27 , V_377 , V_26 ) ;
}
int F_180 ( struct V_362 * V_363 ,
struct V_33 * V_266 [] ,
struct V_28 * V_29 ,
const unsigned char * V_360 ,
T_8 V_69 )
{
int V_26 = - V_282 ;
if ( V_363 -> V_371 && ! ( V_363 -> V_371 & V_372 ) ) {
F_181 ( L_6 , V_29 -> V_186 ) ;
return V_26 ;
}
if ( F_182 ( V_360 ) || F_183 ( V_360 ) )
V_26 = F_184 ( V_29 , V_360 ) ;
else if ( F_185 ( V_360 ) )
V_26 = F_186 ( V_29 , V_360 ) ;
if ( V_26 == - V_21 && ! ( V_69 & V_345 ) )
V_26 = 0 ;
return V_26 ;
}
static int F_187 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
struct V_362 * V_363 ;
struct V_33 * V_266 [ V_378 + 1 ] ;
struct V_28 * V_29 ;
T_9 * V_360 ;
int V_26 ;
V_26 = F_112 ( V_68 , sizeof( * V_363 ) , V_266 , V_378 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_363 = F_98 ( V_68 ) ;
if ( V_363 -> V_370 == 0 ) {
F_181 ( L_7 ) ;
return - V_282 ;
}
V_29 = F_128 ( V_27 , V_363 -> V_370 ) ;
if ( V_29 == NULL ) {
F_181 ( L_8 ) ;
return - V_310 ;
}
if ( ! V_266 [ V_373 ] || F_123 ( V_266 [ V_373 ] ) != V_374 ) {
F_181 ( L_9 ) ;
return - V_282 ;
}
V_360 = F_106 ( V_266 [ V_373 ] ) ;
V_26 = - V_169 ;
if ( ( ! V_363 -> V_368 || V_363 -> V_368 & V_379 ) &&
( V_29 -> V_380 & V_381 ) ) {
struct V_28 * V_382 = F_39 ( V_29 ) ;
const struct V_287 * V_20 = V_382 -> V_151 ;
V_26 = V_20 -> V_383 ( V_363 , V_266 , V_29 , V_360 , V_68 -> V_344 ) ;
if ( V_26 )
goto V_57;
else
V_363 -> V_368 &= ~ V_379 ;
}
if ( ( V_363 -> V_368 & V_376 ) ) {
if ( V_29 -> V_151 -> V_383 )
V_26 = V_29 -> V_151 -> V_383 ( V_363 , V_266 , V_29 , V_360 ,
V_68 -> V_344 ) ;
else
V_26 = F_180 ( V_363 , V_266 , V_29 , V_360 ,
V_68 -> V_344 ) ;
if ( ! V_26 ) {
F_179 ( V_29 , V_360 , V_384 ) ;
V_363 -> V_368 &= ~ V_376 ;
}
}
V_57:
return V_26 ;
}
int F_188 ( struct V_362 * V_363 ,
struct V_33 * V_266 [] ,
struct V_28 * V_29 ,
const unsigned char * V_360 )
{
int V_26 = - V_169 ;
if ( ! ( V_363 -> V_371 & V_372 ) ) {
F_181 ( L_6 , V_29 -> V_186 ) ;
return - V_282 ;
}
if ( F_182 ( V_360 ) || F_183 ( V_360 ) )
V_26 = F_189 ( V_29 , V_360 ) ;
else if ( F_185 ( V_360 ) )
V_26 = F_190 ( V_29 , V_360 ) ;
else
V_26 = - V_282 ;
return V_26 ;
}
static int F_191 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
struct V_362 * V_363 ;
struct V_33 * V_266 [ V_378 + 1 ] ;
struct V_28 * V_29 ;
int V_26 = - V_282 ;
T_10 * V_360 ;
if ( ! F_192 ( V_304 ) )
return - V_305 ;
V_26 = F_112 ( V_68 , sizeof( * V_363 ) , V_266 , V_378 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
V_363 = F_98 ( V_68 ) ;
if ( V_363 -> V_370 == 0 ) {
F_181 ( L_10 ) ;
return - V_282 ;
}
V_29 = F_128 ( V_27 , V_363 -> V_370 ) ;
if ( V_29 == NULL ) {
F_181 ( L_11 ) ;
return - V_310 ;
}
if ( ! V_266 [ V_373 ] || F_123 ( V_266 [ V_373 ] ) != V_374 ) {
F_181 ( L_12 ) ;
return - V_282 ;
}
V_360 = F_106 ( V_266 [ V_373 ] ) ;
V_26 = - V_169 ;
if ( ( ! V_363 -> V_368 || V_363 -> V_368 & V_379 ) &&
( V_29 -> V_380 & V_381 ) ) {
struct V_28 * V_382 = F_39 ( V_29 ) ;
const struct V_287 * V_20 = V_382 -> V_151 ;
if ( V_20 -> V_385 )
V_26 = V_20 -> V_385 ( V_363 , V_266 , V_29 , V_360 ) ;
if ( V_26 )
goto V_57;
else
V_363 -> V_368 &= ~ V_379 ;
}
if ( V_363 -> V_368 & V_376 ) {
if ( V_29 -> V_151 -> V_385 )
V_26 = V_29 -> V_151 -> V_385 ( V_363 , V_266 , V_29 , V_360 ) ;
else
V_26 = F_188 ( V_363 , V_266 , V_29 , V_360 ) ;
if ( ! V_26 ) {
F_179 ( V_29 , V_360 , V_386 ) ;
V_363 -> V_368 &= ~ V_376 ;
}
}
V_57:
return V_26 ;
}
static int F_193 ( struct V_41 * V_42 ,
struct V_257 * V_258 ,
struct V_28 * V_29 ,
int * V_262 ,
struct V_387 * V_24 )
{
struct V_388 * V_389 ;
int V_26 ;
T_5 V_275 , V_172 ;
V_275 = F_56 ( V_258 -> V_42 ) . V_275 ;
V_172 = V_258 -> V_68 -> V_276 ;
F_26 (ha, &list->list, list) {
if ( * V_262 < V_258 -> args [ 0 ] )
goto V_390;
V_26 = F_177 ( V_42 , V_29 , V_389 -> V_360 ,
V_275 , V_172 ,
V_384 , V_376 ,
V_277 ) ;
if ( V_26 < 0 )
return V_26 ;
V_390:
* V_262 += 1 ;
}
return 0 ;
}
int F_194 ( struct V_41 * V_42 ,
struct V_257 * V_258 ,
struct V_28 * V_29 ,
int V_262 )
{
int V_26 ;
F_195 ( V_29 ) ;
V_26 = F_193 ( V_42 , V_258 , V_29 , & V_262 , & V_29 -> V_391 ) ;
if ( V_26 )
goto V_57;
F_193 ( V_42 , V_258 , V_29 , & V_262 , & V_29 -> V_392 ) ;
V_57:
F_196 ( V_29 ) ;
return V_262 ;
}
static int F_197 ( struct V_41 * V_42 , struct V_257 * V_258 )
{
int V_262 = 0 ;
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
struct V_28 * V_29 ;
F_111 () ;
F_198 (net, dev) {
if ( V_29 -> V_380 & V_381 ) {
struct V_28 * V_382 ;
const struct V_287 * V_20 ;
V_382 = F_39 ( V_29 ) ;
V_20 = V_382 -> V_151 ;
if ( V_20 -> V_393 )
V_262 = V_20 -> V_393 ( V_42 , V_258 , V_29 , V_262 ) ;
}
if ( V_29 -> V_151 -> V_393 )
V_262 = V_29 -> V_151 -> V_393 ( V_42 , V_258 , V_29 , V_262 ) ;
else
V_262 = F_194 ( V_42 , V_258 , V_29 , V_262 ) ;
}
F_117 () ;
V_258 -> args [ 0 ] = V_262 ;
return V_42 -> V_278 ;
}
int F_199 ( struct V_41 * V_42 , T_5 V_59 , T_5 V_172 ,
struct V_28 * V_29 , T_8 V_394 )
{
struct V_67 * V_68 ;
struct V_104 * V_105 ;
struct V_33 * V_395 ;
T_9 V_96 = F_101 ( V_29 ) ? V_29 -> V_96 : V_190 ;
struct V_28 * V_382 = F_39 ( V_29 ) ;
V_68 = F_97 ( V_42 , V_59 , V_172 , V_274 , sizeof( * V_105 ) , V_277 ) ;
if ( V_68 == NULL )
return - V_45 ;
V_105 = F_98 ( V_68 ) ;
V_105 -> V_179 = V_365 ;
V_105 -> V_181 = 0 ;
V_105 -> V_182 = V_29 -> type ;
V_105 -> V_183 = V_29 -> V_184 ;
V_105 -> V_106 = F_99 ( V_29 ) ;
V_105 -> V_107 = 0 ;
if ( F_49 ( V_42 , V_185 , V_29 -> V_186 ) ||
F_68 ( V_42 , V_193 , V_29 -> V_194 ) ||
F_100 ( V_42 , V_189 , V_96 ) ||
( V_382 &&
F_68 ( V_42 , V_204 , V_382 -> V_184 ) ) ||
( V_29 -> V_219 &&
F_74 ( V_42 , V_220 , V_29 -> V_219 , V_29 -> V_221 ) ) ||
( V_29 -> V_184 != V_29 -> V_202 &&
F_68 ( V_42 , V_203 , V_29 -> V_202 ) ) )
goto V_77;
V_395 = F_50 ( V_42 , V_253 ) ;
if ( ! V_395 )
goto V_77;
if ( F_200 ( V_42 , V_396 , V_397 ) ||
F_200 ( V_42 , V_398 , V_394 ) ) {
F_52 ( V_42 , V_395 ) ;
goto V_77;
}
F_51 ( V_42 , V_395 ) ;
return F_107 ( V_42 , V_68 ) ;
V_77:
F_108 ( V_42 , V_68 ) ;
return - V_45 ;
}
static int F_201 ( struct V_41 * V_42 , struct V_257 * V_258 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
struct V_28 * V_29 ;
int V_262 = 0 ;
T_5 V_275 = F_56 ( V_258 -> V_42 ) . V_275 ;
T_5 V_172 = V_258 -> V_68 -> V_276 ;
struct V_33 * V_399 ;
T_5 V_400 = 0 ;
V_399 = F_202 ( V_258 -> V_68 , sizeof( struct V_104 ) ,
V_270 ) ;
if ( V_399 )
V_400 = F_113 ( V_399 ) ;
F_111 () ;
F_198 (net, dev) {
const struct V_287 * V_20 = V_29 -> V_151 ;
struct V_28 * V_382 = F_39 ( V_29 ) ;
if ( V_382 && V_382 -> V_151 -> V_401 ) {
if ( V_262 >= V_258 -> args [ 0 ] &&
V_382 -> V_151 -> V_401 (
V_42 , V_275 , V_172 , V_29 , V_400 ) < 0 )
break;
V_262 ++ ;
}
if ( V_20 -> V_401 ) {
if ( V_262 >= V_258 -> args [ 0 ] &&
V_20 -> V_401 ( V_42 , V_275 , V_172 , V_29 ,
V_400 ) < 0 )
break;
V_262 ++ ;
}
}
F_117 () ;
V_258 -> args [ 0 ] = V_262 ;
return V_42 -> V_278 ;
}
static inline T_4 F_203 ( void )
{
return F_89 ( sizeof( struct V_104 ) )
+ F_40 ( V_153 )
+ F_40 ( V_156 )
+ F_40 ( sizeof( T_5 ) )
+ F_40 ( sizeof( T_5 ) )
+ F_40 ( sizeof( T_5 ) )
+ F_40 ( sizeof( T_5 ) )
+ F_40 ( sizeof( T_9 ) )
+ F_40 ( sizeof( struct V_33 ) )
+ F_40 ( sizeof( T_8 ) )
+ F_40 ( sizeof( T_8 ) ) ;
}
static int F_204 ( struct V_28 * V_29 , T_8 V_69 )
{
struct V_27 * V_27 = F_129 ( V_29 ) ;
struct V_28 * V_382 = F_39 ( V_29 ) ;
struct V_41 * V_42 ;
int V_26 = - V_169 ;
V_42 = F_170 ( F_203 () , V_375 ) ;
if ( ! V_42 ) {
V_26 = - V_314 ;
goto V_302;
}
if ( ( ! V_69 || ( V_69 & V_402 ) ) &&
V_382 && V_382 -> V_151 -> V_401 ) {
V_26 = V_382 -> V_151 -> V_401 ( V_42 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_302;
}
if ( ( V_69 & V_397 ) &&
V_29 -> V_151 -> V_401 ) {
V_26 = V_29 -> V_151 -> V_401 ( V_42 , 0 , 0 , V_29 , 0 ) ;
if ( V_26 < 0 )
goto V_302;
}
F_62 ( V_42 , V_27 , 0 , V_359 , NULL , V_375 ) ;
return 0 ;
V_302:
F_171 ( V_26 == - V_45 ) ;
F_172 ( V_42 ) ;
F_65 ( V_27 , V_359 , V_26 ) ;
return V_26 ;
}
static int F_205 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
struct V_104 * V_105 ;
struct V_28 * V_29 ;
struct V_33 * V_403 , * V_176 = NULL ;
int V_283 , V_26 = - V_169 ;
T_8 V_404 , V_69 = 0 ;
bool V_405 = false ;
if ( F_206 ( V_68 ) < sizeof( * V_105 ) )
return - V_282 ;
V_105 = F_98 ( V_68 ) ;
if ( V_105 -> V_179 != V_365 )
return - V_406 ;
V_29 = F_128 ( V_27 , V_105 -> V_183 ) ;
if ( ! V_29 ) {
F_181 ( L_13 ) ;
return - V_310 ;
}
V_403 = F_202 ( V_68 , sizeof( struct V_104 ) , V_253 ) ;
if ( V_403 ) {
F_124 (attr, br_spec, rem) {
if ( F_125 ( V_176 ) == V_396 ) {
V_405 = true ;
V_69 = F_207 ( V_176 ) ;
break;
}
}
}
V_404 = V_69 ;
if ( ! V_69 || ( V_69 & V_402 ) ) {
struct V_28 * V_382 = F_39 ( V_29 ) ;
if ( ! V_382 || ! V_382 -> V_151 -> V_407 ) {
V_26 = - V_169 ;
goto V_57;
}
V_26 = V_382 -> V_151 -> V_407 ( V_29 , V_68 ) ;
if ( V_26 )
goto V_57;
V_69 &= ~ V_402 ;
}
if ( ( V_69 & V_397 ) ) {
if ( ! V_29 -> V_151 -> V_407 )
V_26 = - V_169 ;
else
V_26 = V_29 -> V_151 -> V_407 ( V_29 , V_68 ) ;
if ( ! V_26 )
V_69 &= ~ V_397 ;
}
if ( V_405 )
memcpy ( F_106 ( V_176 ) , & V_69 , sizeof( V_69 ) ) ;
if ( ! V_26 )
V_26 = F_204 ( V_29 , V_404 ) ;
V_57:
return V_26 ;
}
static int F_208 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
struct V_104 * V_105 ;
struct V_28 * V_29 ;
struct V_33 * V_403 , * V_176 = NULL ;
int V_283 , V_26 = - V_169 ;
T_8 V_404 , V_69 = 0 ;
bool V_405 = false ;
if ( F_206 ( V_68 ) < sizeof( * V_105 ) )
return - V_282 ;
V_105 = F_98 ( V_68 ) ;
if ( V_105 -> V_179 != V_365 )
return - V_406 ;
V_29 = F_128 ( V_27 , V_105 -> V_183 ) ;
if ( ! V_29 ) {
F_181 ( L_13 ) ;
return - V_310 ;
}
V_403 = F_202 ( V_68 , sizeof( struct V_104 ) , V_253 ) ;
if ( V_403 ) {
F_124 (attr, br_spec, rem) {
if ( F_125 ( V_176 ) == V_396 ) {
V_405 = true ;
V_69 = F_207 ( V_176 ) ;
break;
}
}
}
V_404 = V_69 ;
if ( ! V_69 || ( V_69 & V_402 ) ) {
struct V_28 * V_382 = F_39 ( V_29 ) ;
if ( ! V_382 || ! V_382 -> V_151 -> V_408 ) {
V_26 = - V_169 ;
goto V_57;
}
V_26 = V_382 -> V_151 -> V_408 ( V_29 , V_68 ) ;
if ( V_26 )
goto V_57;
V_69 &= ~ V_402 ;
}
if ( ( V_69 & V_397 ) ) {
if ( ! V_29 -> V_151 -> V_408 )
V_26 = - V_169 ;
else
V_26 = V_29 -> V_151 -> V_408 ( V_29 , V_68 ) ;
if ( ! V_26 )
V_69 &= ~ V_397 ;
}
if ( V_405 )
memcpy ( F_106 ( V_176 ) , & V_69 , sizeof( V_69 ) ) ;
if ( ! V_26 )
V_26 = F_204 ( V_29 , V_404 ) ;
V_57:
return V_26 ;
}
static int F_209 ( struct V_41 * V_42 , struct V_67 * V_68 )
{
struct V_27 * V_27 = F_110 ( V_42 -> V_259 ) ;
T_1 V_11 ;
int V_409 , V_19 ;
int V_38 ;
int type ;
int V_26 ;
type = V_68 -> V_355 ;
if ( type > V_410 )
return - V_169 ;
type -= V_4 ;
if ( F_206 ( V_68 ) < sizeof( struct V_411 ) )
return 0 ;
V_38 = ( (struct V_411 * ) F_98 ( V_68 ) ) -> V_412 ;
V_409 = type >> 2 ;
V_19 = type & 3 ;
if ( V_19 != 2 && ! F_133 ( V_27 -> V_303 , V_304 ) )
return - V_305 ;
if ( V_19 == 2 && V_68 -> V_344 & V_413 ) {
struct V_62 * V_63 ;
T_2 V_13 ;
T_3 V_14 ;
T_8 V_414 = 0 ;
V_13 = F_16 ( V_38 , type ) ;
if ( V_13 == NULL )
return - V_169 ;
V_14 = F_17 ( V_38 , type ) ;
if ( V_14 )
V_414 = V_14 ( V_42 , V_68 ) ;
F_3 () ;
V_63 = V_27 -> V_63 ;
{
struct V_415 V_416 = {
. V_417 = V_13 ,
. V_414 = V_414 ,
} ;
V_26 = F_210 ( V_63 , V_42 , V_68 , & V_416 ) ;
}
F_1 () ;
return V_26 ;
}
V_11 = F_15 ( V_38 , type ) ;
if ( V_11 == NULL )
return - V_169 ;
return V_11 ( V_42 , V_68 ) ;
}
static void F_211 ( struct V_41 * V_42 )
{
F_1 () ;
F_212 ( V_42 , & F_209 ) ;
F_5 () ;
}
static int F_213 ( struct V_418 * V_419 , unsigned long V_420 , void * V_421 )
{
struct V_28 * V_29 = F_214 ( V_421 ) ;
switch ( V_420 ) {
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
break;
default:
F_176 ( V_274 , V_29 , 0 , V_15 ) ;
break;
}
return V_434 ;
}
static int T_11 F_215 ( struct V_27 * V_27 )
{
struct V_62 * V_259 ;
struct V_435 V_436 = {
. V_437 = V_438 ,
. V_439 = F_211 ,
. V_440 = & V_1 ,
. V_69 = V_441 ,
} ;
V_259 = F_216 ( V_27 , V_442 , & V_436 ) ;
if ( ! V_259 )
return - V_314 ;
V_27 -> V_63 = V_259 ;
return 0 ;
}
static void T_12 F_217 ( struct V_27 * V_27 )
{
F_218 ( V_27 -> V_63 ) ;
V_27 -> V_63 = NULL ;
}
void T_13 F_219 ( void )
{
if ( F_220 ( & V_443 ) )
F_21 ( L_14 ) ;
F_221 ( & V_444 ) ;
F_20 ( V_12 , V_445 , F_169 ,
F_109 , F_173 ) ;
F_20 ( V_12 , V_446 , F_151 , NULL , NULL ) ;
F_20 ( V_12 , V_274 , F_163 , NULL , NULL ) ;
F_20 ( V_12 , V_447 , F_154 , NULL , NULL ) ;
F_20 ( V_12 , V_448 , NULL , F_175 , NULL ) ;
F_20 ( V_12 , V_449 , NULL , F_175 , NULL ) ;
F_20 ( V_450 , V_384 , F_187 , NULL , NULL ) ;
F_20 ( V_450 , V_386 , F_191 , NULL , NULL ) ;
F_20 ( V_450 , V_451 , NULL , F_197 , NULL ) ;
F_20 ( V_450 , V_445 , NULL , F_201 , NULL ) ;
F_20 ( V_450 , V_447 , F_208 , NULL , NULL ) ;
F_20 ( V_450 , V_446 , F_205 , NULL , NULL ) ;
}
