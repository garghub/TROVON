void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( struct V_2 * V_3 , struct V_2 * V_4 )
{
if ( V_3 && V_4 ) {
V_4 -> V_5 = V_6 ;
V_6 = V_3 ;
}
}
void F_4 ( void )
{
struct V_2 * V_3 = V_6 ;
V_6 = NULL ;
F_5 ( & V_1 ) ;
while ( V_3 ) {
struct V_2 * V_5 = V_3 -> V_5 ;
F_6 ( V_3 ) ;
F_7 () ;
V_3 = V_5 ;
}
}
void F_8 ( void )
{
F_9 () ;
}
int F_10 ( void )
{
return F_11 ( & V_1 ) ;
}
int F_12 ( void )
{
return F_13 ( & V_1 ) ;
}
bool F_14 ( void )
{
return F_15 ( & V_1 ) ;
}
static inline int F_16 ( int V_7 )
{
int V_8 = V_7 - V_9 ;
F_17 ( V_8 < 0 || V_8 >= V_10 ) ;
return V_8 ;
}
static T_1 F_18 ( int V_11 , int V_8 )
{
struct V_12 * V_13 ;
if ( V_11 <= V_14 )
V_13 = V_15 [ V_11 ] ;
else
V_13 = NULL ;
if ( V_13 == NULL || V_13 [ V_8 ] . V_16 == NULL )
V_13 = V_15 [ V_17 ] ;
return V_13 [ V_8 ] . V_16 ;
}
static T_2 F_19 ( int V_11 , int V_8 )
{
struct V_12 * V_13 ;
if ( V_11 <= V_14 )
V_13 = V_15 [ V_11 ] ;
else
V_13 = NULL ;
if ( V_13 == NULL || V_13 [ V_8 ] . V_18 == NULL )
V_13 = V_15 [ V_17 ] ;
return V_13 [ V_8 ] . V_18 ;
}
static T_3 F_20 ( int V_11 , int V_8 )
{
struct V_12 * V_13 ;
if ( V_11 <= V_14 )
V_13 = V_15 [ V_11 ] ;
else
V_13 = NULL ;
if ( V_13 == NULL || V_13 [ V_8 ] . V_19 == NULL )
V_13 = V_15 [ V_17 ] ;
return V_13 [ V_8 ] . V_19 ;
}
int F_21 ( int V_11 , int V_7 ,
T_1 V_16 , T_2 V_18 ,
T_3 V_19 )
{
struct V_12 * V_13 ;
int V_8 ;
F_17 ( V_11 < 0 || V_11 > V_14 ) ;
V_8 = F_16 ( V_7 ) ;
V_13 = V_15 [ V_11 ] ;
if ( V_13 == NULL ) {
V_13 = F_22 ( V_10 , sizeof( * V_13 ) , V_20 ) ;
if ( V_13 == NULL )
return - V_21 ;
V_15 [ V_11 ] = V_13 ;
}
if ( V_16 )
V_13 [ V_8 ] . V_16 = V_16 ;
if ( V_18 )
V_13 [ V_8 ] . V_18 = V_18 ;
if ( V_19 )
V_13 [ V_8 ] . V_19 = V_19 ;
return 0 ;
}
void F_23 ( int V_11 , int V_7 ,
T_1 V_16 , T_2 V_18 ,
T_3 V_19 )
{
if ( F_21 ( V_11 , V_7 , V_16 , V_18 , V_19 ) < 0 )
F_24 ( L_1
L_2 ,
V_11 , V_7 ) ;
}
int F_25 ( int V_11 , int V_7 )
{
int V_8 ;
F_17 ( V_11 < 0 || V_11 > V_14 ) ;
V_8 = F_16 ( V_7 ) ;
if ( V_15 [ V_11 ] == NULL )
return - V_22 ;
V_15 [ V_11 ] [ V_8 ] . V_16 = NULL ;
V_15 [ V_11 ] [ V_8 ] . V_18 = NULL ;
V_15 [ V_11 ] [ V_8 ] . V_19 = NULL ;
return 0 ;
}
void F_26 ( int V_11 )
{
F_17 ( V_11 < 0 || V_11 > V_14 ) ;
F_27 ( V_15 [ V_11 ] ) ;
V_15 [ V_11 ] = NULL ;
}
static const struct V_23 * F_28 ( const char * V_24 )
{
const struct V_23 * V_25 ;
F_29 (ops, &link_ops, list) {
if ( ! strcmp ( V_25 -> V_24 , V_24 ) )
return V_25 ;
}
return NULL ;
}
int F_30 ( struct V_23 * V_25 )
{
if ( F_28 ( V_25 -> V_24 ) )
return - V_26 ;
if ( V_25 -> V_27 && ! V_25 -> V_28 )
V_25 -> V_28 = V_29 ;
F_31 ( & V_25 -> V_30 , & V_31 ) ;
return 0 ;
}
int F_32 ( struct V_23 * V_25 )
{
int V_32 ;
F_1 () ;
V_32 = F_30 ( V_25 ) ;
F_8 () ;
return V_32 ;
}
static void F_33 ( struct V_33 * V_33 , struct V_23 * V_25 )
{
struct V_34 * V_35 ;
F_34 ( V_36 ) ;
F_35 (net, dev) {
if ( V_35 -> V_23 == V_25 )
V_25 -> V_28 ( V_35 , & V_36 ) ;
}
F_36 ( & V_36 ) ;
}
void F_37 ( struct V_23 * V_25 )
{
struct V_33 * V_33 ;
F_38 (net) {
F_33 ( V_33 , V_25 ) ;
}
F_39 ( & V_25 -> V_30 ) ;
}
static void F_40 ( void )
{
struct V_33 * V_33 ;
bool V_37 ;
F_41 ( V_38 , V_39 ) ;
F_42 ( & V_40 , & V_38 ) ;
for (; ; ) {
V_37 = false ;
F_1 () ;
F_38 (net) {
if ( V_33 -> V_41 > 0 ) {
V_37 = true ;
break;
}
}
if ( ! V_37 )
break;
F_4 () ;
F_43 ( & V_38 , V_42 , V_43 ) ;
}
F_44 ( & V_40 , & V_38 ) ;
}
void F_45 ( struct V_23 * V_25 )
{
F_2 ( & V_44 ) ;
F_40 () ;
F_37 ( V_25 ) ;
F_8 () ;
F_5 ( & V_44 ) ;
}
static T_4 F_46 ( const struct V_34 * V_35 )
{
struct V_34 * V_45 ;
const struct V_23 * V_25 ;
V_45 = F_47 ( (struct V_34 * ) V_35 ) ;
if ( ! V_45 )
return 0 ;
V_25 = V_45 -> V_23 ;
if ( ! V_25 || ! V_25 -> V_46 )
return 0 ;
return F_48 ( sizeof( struct V_47 ) ) +
V_25 -> V_46 ( V_45 , V_35 ) ;
}
static T_4 F_49 ( const struct V_34 * V_35 )
{
const struct V_23 * V_25 = V_35 -> V_23 ;
T_4 V_48 ;
if ( ! V_25 )
return 0 ;
V_48 = F_48 ( sizeof( struct V_47 ) ) +
F_48 ( strlen ( V_25 -> V_24 ) + 1 ) ;
if ( V_25 -> V_49 )
V_48 += F_48 ( sizeof( struct V_47 ) ) +
V_25 -> V_49 ( V_35 ) ;
if ( V_25 -> V_50 )
V_48 += F_48 ( V_25 -> V_50 ( V_35 ) ) ;
V_48 += F_46 ( V_35 ) ;
return V_48 ;
}
static const struct V_51 * F_50 ( const int V_52 )
{
const struct V_51 * V_25 ;
F_29 (ops, &rtnl_af_ops, list) {
if ( V_25 -> V_52 == V_52 )
return V_25 ;
}
return NULL ;
}
void F_51 ( struct V_51 * V_25 )
{
F_1 () ;
F_31 ( & V_25 -> V_30 , & V_51 ) ;
F_8 () ;
}
void F_52 ( struct V_51 * V_25 )
{
F_39 ( & V_25 -> V_30 ) ;
}
void F_53 ( struct V_51 * V_25 )
{
F_1 () ;
F_52 ( V_25 ) ;
F_8 () ;
}
static T_4 F_54 ( const struct V_34 * V_35 ,
T_5 V_53 )
{
struct V_51 * V_54 ;
T_4 V_48 ;
V_48 = F_48 ( sizeof( struct V_47 ) ) ;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_55 ) {
V_48 += F_48 ( sizeof( struct V_47 ) ) +
V_54 -> V_55 ( V_35 , V_53 ) ;
}
}
return V_48 ;
}
static bool F_55 ( const struct V_34 * V_35 )
{
struct V_34 * V_45 ;
V_45 = F_47 ( (struct V_34 * ) V_35 ) ;
if ( V_45 && V_45 -> V_23 )
return true ;
return false ;
}
static int F_56 ( struct V_2 * V_56 ,
const struct V_34 * V_35 )
{
struct V_34 * V_45 ;
const struct V_23 * V_25 ;
struct V_47 * V_57 ;
int V_32 ;
V_45 = F_47 ( (struct V_34 * ) V_35 ) ;
if ( ! V_45 )
return 0 ;
V_25 = V_45 -> V_23 ;
if ( ! V_25 )
return 0 ;
if ( F_57 ( V_56 , V_58 , V_25 -> V_24 ) < 0 )
return - V_59 ;
if ( V_25 -> V_60 ) {
V_57 = F_58 ( V_56 , V_61 ) ;
if ( ! V_57 )
return - V_59 ;
V_32 = V_25 -> V_60 ( V_56 , V_45 , V_35 ) ;
if ( V_32 < 0 )
goto V_62;
F_59 ( V_56 , V_57 ) ;
}
return 0 ;
V_62:
F_60 ( V_56 , V_57 ) ;
return V_32 ;
}
static int F_61 ( struct V_2 * V_56 ,
const struct V_34 * V_35 )
{
const struct V_23 * V_25 = V_35 -> V_23 ;
struct V_47 * V_63 ;
int V_32 ;
if ( ! V_25 )
return 0 ;
if ( F_57 ( V_56 , V_64 , V_25 -> V_24 ) < 0 )
return - V_59 ;
if ( V_25 -> V_65 ) {
V_32 = V_25 -> V_65 ( V_56 , V_35 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_25 -> V_66 ) {
V_63 = F_58 ( V_56 , V_67 ) ;
if ( V_63 == NULL )
return - V_59 ;
V_32 = V_25 -> V_66 ( V_56 , V_35 ) ;
if ( V_32 < 0 )
goto V_68;
F_59 ( V_56 , V_63 ) ;
}
return 0 ;
V_68:
F_60 ( V_56 , V_63 ) ;
return V_32 ;
}
static int F_62 ( struct V_2 * V_56 , const struct V_34 * V_35 )
{
struct V_47 * V_69 ;
int V_32 = - V_59 ;
V_69 = F_58 ( V_56 , V_70 ) ;
if ( V_69 == NULL )
goto V_71;
V_32 = F_61 ( V_56 , V_35 ) ;
if ( V_32 < 0 )
goto V_72;
V_32 = F_56 ( V_56 , V_35 ) ;
if ( V_32 < 0 )
goto V_72;
F_59 ( V_56 , V_69 ) ;
return 0 ;
V_72:
F_60 ( V_56 , V_69 ) ;
V_71:
return V_32 ;
}
int F_63 ( struct V_2 * V_56 , struct V_33 * V_33 , T_5 V_73 , unsigned int V_74 , int V_75 )
{
struct V_76 * V_77 = V_33 -> V_77 ;
int V_32 = 0 ;
F_64 ( V_56 ) . V_78 = V_74 ;
if ( V_75 )
F_65 ( & V_56 -> V_79 ) ;
F_66 ( V_77 , V_56 , V_73 , V_74 , V_20 ) ;
if ( V_75 )
V_32 = F_67 ( V_77 , V_56 , V_73 , V_80 ) ;
return V_32 ;
}
int F_68 ( struct V_2 * V_56 , struct V_33 * V_33 , T_5 V_73 )
{
struct V_76 * V_77 = V_33 -> V_77 ;
return F_69 ( V_77 , V_56 , V_73 ) ;
}
void F_70 ( struct V_2 * V_56 , struct V_33 * V_33 , T_5 V_73 , T_5 V_74 ,
struct V_81 * V_82 , T_6 V_83 )
{
struct V_76 * V_77 = V_33 -> V_77 ;
int V_84 = 0 ;
if ( V_82 )
V_84 = F_71 ( V_82 ) ;
F_72 ( V_77 , V_56 , V_73 , V_74 , V_84 , V_83 ) ;
}
void F_73 ( struct V_33 * V_33 , T_5 V_74 , int error )
{
struct V_76 * V_77 = V_33 -> V_77 ;
F_74 ( V_77 , 0 , V_74 , error ) ;
}
int F_75 ( struct V_2 * V_56 , T_5 * V_85 )
{
struct V_47 * V_86 ;
int V_87 , V_88 = 0 ;
V_86 = F_58 ( V_56 , V_89 ) ;
if ( V_86 == NULL )
return - V_21 ;
for ( V_87 = 0 ; V_87 < V_90 ; V_87 ++ ) {
if ( V_85 [ V_87 ] ) {
if ( V_87 == V_91 - 1 ) {
char V_92 [ V_93 ] , * V_94 ;
V_94 = F_76 ( V_85 [ V_87 ] , V_92 ) ;
if ( ! V_94 )
continue;
if ( F_57 ( V_56 , V_87 + 1 , V_94 ) )
goto V_95;
} else if ( V_87 == V_96 - 1 ) {
T_5 V_97 = V_85 [ V_87 ] & V_98 ;
if ( ! V_97 )
continue;
F_77 ( V_98 & V_99 ) ;
if ( F_78 ( V_56 , V_87 + 1 , V_97 ) )
goto V_95;
} else {
if ( F_78 ( V_56 , V_87 + 1 , V_85 [ V_87 ] ) )
goto V_95;
}
V_88 ++ ;
}
}
if ( ! V_88 ) {
F_60 ( V_56 , V_86 ) ;
return 0 ;
}
return F_59 ( V_56 , V_86 ) ;
V_95:
F_60 ( V_56 , V_86 ) ;
return - V_59 ;
}
int F_79 ( struct V_2 * V_56 , struct V_100 * V_101 , T_5 V_102 ,
long V_103 , T_5 error )
{
struct V_104 V_105 = {
. V_106 = F_80 ( V_107 - V_101 -> V_108 ) ,
. V_109 = V_101 -> V_110 ,
. V_111 = F_81 ( & ( V_101 -> V_112 ) ) ,
. V_113 = error ,
. V_114 = V_102 ,
} ;
if ( V_103 ) {
unsigned long clock ;
clock = F_82 ( abs ( V_103 ) ) ;
clock = F_83 (unsigned long, clock, INT_MAX) ;
V_105 . V_115 = ( V_103 > 0 ) ? clock : - clock ;
}
return F_84 ( V_56 , V_116 , sizeof( V_105 ) , & V_105 ) ;
}
static void F_85 ( struct V_34 * V_35 , unsigned char V_117 )
{
unsigned char V_118 = V_35 -> V_118 ;
switch ( V_117 ) {
case V_119 :
if ( ( V_118 == V_120 ||
V_118 == V_121 ) &&
! F_86 ( V_35 ) )
V_118 = V_119 ;
break;
case V_120 :
if ( V_118 == V_119 ||
V_118 == V_121 )
V_118 = V_120 ;
break;
}
if ( V_35 -> V_118 != V_118 ) {
F_87 ( & V_122 ) ;
V_35 -> V_118 = V_118 ;
F_88 ( & V_122 ) ;
F_89 ( V_35 ) ;
}
}
static unsigned int F_90 ( const struct V_34 * V_35 )
{
return ( V_35 -> V_83 & ~ ( V_123 | V_124 ) ) |
( V_35 -> V_125 & ( V_123 | V_124 ) ) ;
}
static unsigned int F_91 ( const struct V_34 * V_35 ,
const struct V_126 * V_127 )
{
unsigned int V_83 = V_127 -> V_128 ;
if ( V_127 -> V_129 )
V_83 = ( V_83 & V_127 -> V_129 ) |
( F_90 ( V_35 ) & ~ V_127 -> V_129 ) ;
return V_83 ;
}
static void F_92 ( struct V_130 * V_131 ,
const struct V_132 * V_133 )
{
V_131 -> V_134 = V_133 -> V_134 ;
V_131 -> V_135 = V_133 -> V_135 ;
V_131 -> V_136 = V_133 -> V_136 ;
V_131 -> V_137 = V_133 -> V_137 ;
V_131 -> V_138 = V_133 -> V_138 ;
V_131 -> V_139 = V_133 -> V_139 ;
V_131 -> V_140 = V_133 -> V_140 ;
V_131 -> V_141 = V_133 -> V_141 ;
V_131 -> V_142 = V_133 -> V_142 ;
V_131 -> V_143 = V_133 -> V_143 ;
V_131 -> V_144 = V_133 -> V_144 ;
V_131 -> V_145 = V_133 -> V_145 ;
V_131 -> V_146 = V_133 -> V_146 ;
V_131 -> V_147 = V_133 -> V_147 ;
V_131 -> V_148 = V_133 -> V_148 ;
V_131 -> V_149 = V_133 -> V_149 ;
V_131 -> V_150 = V_133 -> V_150 ;
V_131 -> V_151 = V_133 -> V_151 ;
V_131 -> V_152 = V_133 -> V_152 ;
V_131 -> V_153 = V_133 -> V_153 ;
V_131 -> V_154 = V_133 -> V_154 ;
V_131 -> V_155 = V_133 -> V_155 ;
V_131 -> V_156 = V_133 -> V_156 ;
V_131 -> V_157 = V_133 -> V_157 ;
}
static inline int F_93 ( const struct V_34 * V_35 ,
T_5 V_53 )
{
if ( V_35 -> V_35 . V_158 && F_94 ( V_35 -> V_35 . V_158 ) &&
( V_53 & V_159 ) ) {
int V_160 = F_95 ( V_35 -> V_35 . V_158 ) ;
T_4 V_48 = F_48 ( 0 ) ;
V_48 += V_160 *
( F_48 ( 0 ) +
F_48 ( sizeof( struct V_161 ) ) +
F_48 ( sizeof( struct V_162 ) ) +
F_48 ( 0 ) +
F_48 ( V_163 *
sizeof( struct V_164 ) ) +
F_48 ( sizeof( struct V_165 ) ) +
F_48 ( sizeof( struct V_166 ) ) +
F_48 ( sizeof( struct V_167 ) ) +
F_48 ( sizeof( struct V_168 ) ) +
F_48 ( sizeof( struct V_169 ) ) +
F_48 ( 0 ) +
F_96 ( sizeof( V_170 ) ) +
F_96 ( sizeof( V_170 ) ) +
F_96 ( sizeof( V_170 ) ) +
F_96 ( sizeof( V_170 ) ) +
F_96 ( sizeof( V_170 ) ) +
F_96 ( sizeof( V_170 ) ) +
F_48 ( sizeof( struct V_171 ) ) ) ;
return V_48 ;
} else
return 0 ;
}
static T_4 F_97 ( const struct V_34 * V_35 ,
T_5 V_53 )
{
T_4 V_172 = F_48 ( 4 )
+ F_48 ( V_173 )
+ F_48 ( sizeof( struct V_174 ) )
+ F_48 ( V_175 )
+ F_48 ( V_175 )
+ F_48 ( 1 )
+ F_48 ( 2 ) ;
T_4 V_176 = F_48 ( sizeof( struct V_47 ) ) ;
T_4 V_177 = F_48 ( sizeof( struct V_47 ) )
+ V_172 ;
T_4 V_178 = F_48 ( sizeof( struct V_47 ) )
+ V_172 ;
if ( ! V_35 -> V_179 -> V_180 || ! V_35 -> V_35 . V_158 ||
! ( V_53 & V_159 ) )
return 0 ;
if ( F_95 ( V_35 -> V_35 . V_158 ) )
return V_178 + V_176 +
V_177 * F_95 ( V_35 -> V_35 . V_158 ) ;
else
return V_178 ;
}
static T_4 F_98 ( const struct V_34 * V_35 )
{
T_4 V_181 = F_48 ( 0 ) +
F_48 ( 1 ) ;
if ( ! V_35 -> V_179 -> V_182 )
return 0 ;
else
return V_181 ;
}
static T_7 T_4 F_99 ( const struct V_34 * V_35 ,
T_5 V_53 )
{
return F_100 ( sizeof( struct V_126 ) )
+ F_48 ( V_183 )
+ F_48 ( V_184 )
+ F_48 ( V_183 )
+ F_96 ( sizeof( struct V_185 ) )
+ F_48 ( sizeof( struct V_130 ) )
+ F_96 ( sizeof( struct V_132 ) )
+ F_48 ( V_186 )
+ F_48 ( V_186 )
+ F_48 ( 4 )
+ F_48 ( 4 )
+ F_48 ( 4 )
+ F_48 ( 4 )
+ F_48 ( 4 )
+ F_48 ( 1 )
+ F_48 ( 4 )
+ F_48 ( 4 )
+ F_48 ( 4 )
+ F_48 ( 4 )
+ F_48 ( 4 )
+ F_48 ( 1 )
+ F_48 ( 1 )
+ F_48 ( 4 )
+ F_48 ( 4 )
+ F_48 ( V_53
& V_159 ? 4 : 0 )
+ F_93 ( V_35 , V_53 )
+ F_97 ( V_35 , V_53 )
+ F_49 ( V_35 )
+ F_54 ( V_35 , V_53 )
+ F_48 ( V_187 )
+ F_48 ( V_187 )
+ F_48 ( V_183 )
+ F_98 ( V_35 )
+ F_48 ( 1 ) ;
}
static int F_101 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_188 ;
struct V_47 * V_189 ;
int V_190 ;
int V_32 ;
V_188 = F_58 ( V_56 , V_191 ) ;
if ( ! V_188 )
return - V_59 ;
for ( V_190 = 0 ; V_190 < F_95 ( V_35 -> V_35 . V_158 ) ; V_190 ++ ) {
V_189 = F_58 ( V_56 , V_192 ) ;
if ( ! V_189 )
goto V_95;
if ( F_78 ( V_56 , V_193 , V_190 ) )
goto V_95;
V_32 = V_35 -> V_179 -> V_180 ( V_35 , V_190 , V_56 ) ;
if ( V_32 == - V_59 )
goto V_95;
if ( V_32 ) {
F_60 ( V_56 , V_189 ) ;
continue;
}
F_59 ( V_56 , V_189 ) ;
}
F_59 ( V_56 , V_188 ) ;
return 0 ;
V_95:
F_60 ( V_56 , V_188 ) ;
return - V_59 ;
}
static int F_102 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_194 ;
int V_32 ;
V_194 = F_58 ( V_56 , V_195 ) ;
if ( ! V_194 )
return - V_59 ;
V_32 = V_35 -> V_179 -> V_180 ( V_35 , V_196 , V_56 ) ;
if ( V_32 ) {
F_60 ( V_56 , V_194 ) ;
return ( V_32 == - V_59 ) ? V_32 : 0 ;
}
F_59 ( V_56 , V_194 ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_56 , struct V_34 * V_35 ,
T_5 V_53 )
{
int V_32 ;
if ( ! V_35 -> V_179 -> V_180 || ! V_35 -> V_35 . V_158 ||
! ( V_53 & V_159 ) )
return 0 ;
V_32 = F_102 ( V_56 , V_35 ) ;
if ( V_32 )
return V_32 ;
if ( F_95 ( V_35 -> V_35 . V_158 ) ) {
V_32 = F_101 ( V_56 , V_35 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_104 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
int V_32 ;
struct V_197 V_198 ;
V_32 = F_105 ( V_35 , & V_198 ) ;
if ( V_32 ) {
if ( V_32 == - V_199 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_200 , V_198 . V_201 , V_198 . V_102 ) )
return - V_59 ;
return 0 ;
}
static int F_106 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
char V_94 [ V_183 ] ;
int V_32 ;
V_32 = F_107 ( V_35 , V_94 , sizeof( V_94 ) ) ;
if ( V_32 ) {
if ( V_32 == - V_199 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_202 , strlen ( V_94 ) , V_94 ) )
return - V_59 ;
return 0 ;
}
static int F_108 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
int V_32 ;
struct V_203 V_204 = {
. V_205 = V_35 ,
. V_102 = V_206 ,
. V_83 = V_207 ,
} ;
V_32 = F_109 ( V_35 , & V_204 ) ;
if ( V_32 ) {
if ( V_32 == - V_199 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_208 , V_204 . V_209 . V_198 . V_201 ,
V_204 . V_209 . V_198 . V_102 ) )
return - V_59 ;
return 0 ;
}
static T_8 int F_110 ( struct V_2 * V_56 ,
struct V_34 * V_35 )
{
struct V_132 * V_210 ;
struct V_47 * V_204 ;
V_204 = F_111 ( V_56 , V_211 ,
sizeof( struct V_132 ) , V_212 ) ;
if ( ! V_204 )
return - V_59 ;
V_210 = F_112 ( V_204 ) ;
F_113 ( V_35 , V_210 ) ;
V_204 = F_114 ( V_56 , V_213 ,
sizeof( struct V_130 ) ) ;
if ( ! V_204 )
return - V_59 ;
F_92 ( F_112 ( V_204 ) , V_210 ) ;
return 0 ;
}
static T_8 int F_115 ( struct V_2 * V_56 ,
struct V_34 * V_35 ,
int V_214 ,
struct V_47 * V_215 )
{
struct V_169 V_216 ;
struct V_47 * V_190 , * V_217 , * V_218 ;
struct V_168 V_219 ;
struct V_164 V_220 ;
struct V_165 V_221 ;
struct V_166 V_222 ;
struct V_223 V_224 ;
struct V_171 V_225 ;
struct V_162 V_226 ;
struct V_167 V_227 ;
struct V_161 V_228 ;
struct V_229 V_230 ;
V_230 . V_231 = - 1 ;
V_230 . V_232 = - 1 ;
V_230 . V_233 = - 1 ;
memset ( V_230 . V_234 , 0 , sizeof( V_230 . V_234 ) ) ;
V_230 . V_235 = 0 ;
V_230 . V_236 = F_116 ( V_237 ) ;
if ( V_35 -> V_179 -> V_238 ( V_35 , V_214 , & V_230 ) )
return 0 ;
memset ( & V_220 , 0 , sizeof( V_220 ) ) ;
V_228 . V_190 =
V_226 . V_190 =
V_220 . V_190 =
V_227 . V_190 =
V_222 . V_190 =
V_221 . V_190 =
V_219 . V_190 =
V_216 . V_190 =
V_225 . V_190 = V_230 . V_190 ;
memcpy ( V_228 . V_234 , V_230 . V_234 , sizeof( V_230 . V_234 ) ) ;
V_226 . V_239 = V_230 . V_239 ;
V_226 . V_240 = V_230 . V_240 ;
V_220 . V_239 = V_230 . V_239 ;
V_220 . V_240 = V_230 . V_240 ;
V_220 . V_236 = V_230 . V_236 ;
V_222 . V_241 = V_230 . V_242 ;
V_227 . V_243 = V_230 . V_243 ;
V_227 . V_242 = V_230 . V_242 ;
V_221 . V_244 = V_230 . V_231 ;
V_219 . V_245 = V_230 . V_235 ;
V_216 . V_244 = V_230 . V_232 ;
V_225 . V_244 = V_230 . V_233 ;
V_190 = F_58 ( V_56 , V_246 ) ;
if ( ! V_190 )
goto V_247;
if ( F_84 ( V_56 , V_248 , sizeof( V_228 ) , & V_228 ) ||
F_84 ( V_56 , V_249 , sizeof( V_226 ) , & V_226 ) ||
F_84 ( V_56 , V_250 , sizeof( V_227 ) ,
& V_227 ) ||
F_84 ( V_56 , V_251 , sizeof( V_222 ) ,
& V_222 ) ||
F_84 ( V_56 , V_252 , sizeof( V_221 ) ,
& V_221 ) ||
F_84 ( V_56 , V_253 , sizeof( V_219 ) ,
& V_219 ) ||
F_84 ( V_56 , V_254 ,
sizeof( V_216 ) ,
& V_216 ) ||
F_84 ( V_56 , V_255 ,
sizeof( V_225 ) , & V_225 ) )
goto V_256;
V_218 = F_58 ( V_56 , V_257 ) ;
if ( ! V_218 )
goto V_256;
if ( F_84 ( V_56 , V_258 , sizeof( V_220 ) ,
& V_220 ) ) {
F_60 ( V_56 , V_218 ) ;
goto V_256;
}
F_59 ( V_56 , V_218 ) ;
memset ( & V_224 , 0 , sizeof( V_224 ) ) ;
if ( V_35 -> V_179 -> V_259 )
V_35 -> V_179 -> V_259 ( V_35 , V_214 ,
& V_224 ) ;
V_217 = F_58 ( V_56 , V_260 ) ;
if ( ! V_217 )
goto V_256;
if ( F_117 ( V_56 , V_261 ,
V_224 . V_134 , V_262 ) ||
F_117 ( V_56 , V_263 ,
V_224 . V_135 , V_262 ) ||
F_117 ( V_56 , V_264 ,
V_224 . V_136 , V_262 ) ||
F_117 ( V_56 , V_265 ,
V_224 . V_137 , V_262 ) ||
F_117 ( V_56 , V_266 ,
V_224 . V_267 , V_262 ) ||
F_117 ( V_56 , V_268 ,
V_224 . V_142 , V_262 ) ) {
F_60 ( V_56 , V_217 ) ;
goto V_256;
}
F_59 ( V_56 , V_217 ) ;
F_59 ( V_56 , V_190 ) ;
return 0 ;
V_256:
F_60 ( V_56 , V_190 ) ;
V_247:
F_60 ( V_56 , V_215 ) ;
return - V_59 ;
}
static int F_118 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_185 V_269 ;
memset ( & V_269 , 0 , sizeof( V_269 ) ) ;
V_269 . V_270 = V_35 -> V_270 ;
V_269 . V_271 = V_35 -> V_271 ;
V_269 . V_272 = V_35 -> V_272 ;
V_269 . V_273 = V_35 -> V_273 ;
V_269 . V_274 = V_35 -> V_274 ;
V_269 . V_275 = V_35 -> V_276 ;
if ( F_119 ( V_56 , V_277 , sizeof( V_269 ) , & V_269 , V_212 ) )
return - V_59 ;
return 0 ;
}
static int F_120 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_278 V_279 = {} ;
struct V_47 * V_280 ;
int V_32 ;
if ( ! V_35 -> V_179 -> V_182 )
return 0 ;
V_280 = F_58 ( V_56 , V_281 ) ;
if ( ! V_280 )
return - V_59 ;
V_279 . V_282 = V_283 ;
V_32 = V_35 -> V_179 -> V_182 ( V_35 , & V_279 ) ;
if ( V_32 )
goto V_284;
V_32 = F_121 ( V_56 , V_285 , V_279 . V_286 ) ;
if ( V_32 )
goto V_284;
F_59 ( V_56 , V_280 ) ;
return 0 ;
V_284:
F_60 ( V_56 , V_280 ) ;
return V_32 ;
}
static int F_122 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_287 , T_5 V_288 ,
unsigned int V_83 , T_5 V_53 )
{
struct V_126 * V_127 ;
struct V_81 * V_82 ;
struct V_47 * V_289 ;
struct V_51 * V_54 ;
struct V_34 * V_290 = F_47 ( V_35 ) ;
F_123 () ;
V_82 = F_124 ( V_56 , V_73 , V_287 , type , sizeof( * V_127 ) , V_83 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_125 ( V_82 ) ;
V_127 -> V_291 = V_292 ;
V_127 -> V_293 = 0 ;
V_127 -> V_294 = V_35 -> type ;
V_127 -> V_295 = V_35 -> V_296 ;
V_127 -> V_128 = F_126 ( V_35 ) ;
V_127 -> V_129 = V_288 ;
if ( F_57 ( V_56 , V_297 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_298 , V_35 -> V_299 ) ||
F_121 ( V_56 , V_300 ,
F_127 ( V_35 ) ? V_35 -> V_118 : V_301 ) ||
F_121 ( V_56 , V_302 , V_35 -> V_303 ) ||
F_78 ( V_56 , V_304 , V_35 -> V_305 ) ||
F_78 ( V_56 , V_306 , V_35 -> V_74 ) ||
F_78 ( V_56 , V_307 , V_35 -> V_308 ) ||
F_78 ( V_56 , V_309 , V_35 -> V_310 ) ||
F_78 ( V_56 , V_311 , V_35 -> V_312 ) ||
F_78 ( V_56 , V_313 , V_35 -> V_314 ) ||
#ifdef F_128
F_78 ( V_56 , V_315 , V_35 -> V_316 ) ||
#endif
( V_35 -> V_296 != F_129 ( V_35 ) &&
F_78 ( V_56 , V_317 , F_129 ( V_35 ) ) ) ||
( V_290 &&
F_78 ( V_56 , V_318 , V_290 -> V_296 ) ) ||
F_121 ( V_56 , V_319 , F_130 ( V_35 ) ) ||
( V_35 -> V_320 &&
F_57 ( V_56 , V_321 , V_35 -> V_320 -> V_25 -> V_102 ) ) ||
( V_35 -> V_322 &&
F_57 ( V_56 , V_323 , V_35 -> V_322 ) ) ||
F_78 ( V_56 , V_324 ,
F_81 ( & V_35 -> V_325 ) ) ||
F_121 ( V_56 , V_326 , V_35 -> V_327 ) )
goto V_95;
if ( F_118 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_328 ) {
if ( F_84 ( V_56 , V_329 , V_35 -> V_328 , V_35 -> V_330 ) ||
F_84 ( V_56 , V_331 , V_35 -> V_328 , V_35 -> V_267 ) )
goto V_95;
}
if ( F_104 ( V_56 , V_35 ) )
goto V_95;
if ( F_106 ( V_56 , V_35 ) )
goto V_95;
if ( F_108 ( V_56 , V_35 ) )
goto V_95;
if ( F_110 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_35 . V_158 && ( V_53 & V_159 ) &&
F_78 ( V_56 , V_332 , F_95 ( V_35 -> V_35 . V_158 ) ) )
goto V_95;
if ( V_35 -> V_179 -> V_238 && V_35 -> V_35 . V_158 &&
V_53 & V_159 ) {
int V_87 ;
struct V_47 * V_215 ;
int V_160 = F_95 ( V_35 -> V_35 . V_158 ) ;
V_215 = F_58 ( V_56 , V_333 ) ;
if ( ! V_215 )
goto V_95;
for ( V_87 = 0 ; V_87 < V_160 ; V_87 ++ ) {
if ( F_115 ( V_56 , V_35 , V_87 , V_215 ) )
goto V_95;
}
F_59 ( V_56 , V_215 ) ;
}
if ( F_103 ( V_56 , V_35 , V_53 ) )
goto V_95;
if ( F_120 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_23 || F_55 ( V_35 ) ) {
if ( F_62 ( V_56 , V_35 ) < 0 )
goto V_95;
}
if ( V_35 -> V_23 &&
V_35 -> V_23 -> V_334 ) {
struct V_33 * V_335 = V_35 -> V_23 -> V_334 ( V_35 ) ;
if ( ! F_131 ( F_132 ( V_35 ) , V_335 ) ) {
int V_102 = F_133 ( F_132 ( V_35 ) , V_335 ) ;
if ( F_134 ( V_56 , V_336 , V_102 ) )
goto V_95;
}
}
if ( ! ( V_289 = F_58 ( V_56 , V_337 ) ) )
goto V_95;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_338 ) {
struct V_47 * V_339 ;
int V_32 ;
if ( ! ( V_339 = F_58 ( V_56 , V_54 -> V_52 ) ) )
goto V_95;
V_32 = V_54 -> V_338 ( V_56 , V_35 , V_53 ) ;
if ( V_32 == - V_340 )
F_60 ( V_56 , V_339 ) ;
else if ( V_32 < 0 )
goto V_95;
F_59 ( V_56 , V_339 ) ;
}
}
F_59 ( V_56 , V_289 ) ;
F_135 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_136 ( V_56 , V_82 ) ;
return - V_59 ;
}
static const struct V_23 * F_137 ( const struct V_47 * V_341 )
{
const struct V_23 * V_25 = NULL ;
struct V_47 * V_342 [ V_343 + 1 ] ;
if ( F_138 ( V_342 , V_343 , V_341 , V_344 ) < 0 )
return NULL ;
if ( V_342 [ V_64 ] ) {
char V_24 [ V_345 ] ;
F_139 ( V_24 , V_342 [ V_64 ] , sizeof( V_24 ) ) ;
V_25 = F_28 ( V_24 ) ;
}
return V_25 ;
}
static bool F_140 ( struct V_34 * V_35 , int V_346 )
{
struct V_34 * V_347 ;
if ( ! V_346 )
return false ;
V_347 = F_47 ( V_35 ) ;
if ( ! V_347 || V_347 -> V_296 != V_346 )
return true ;
return false ;
}
static bool F_141 ( const struct V_34 * V_35 ,
const struct V_23 * V_348 )
{
if ( V_348 && V_35 -> V_23 != V_348 )
return true ;
return false ;
}
static bool F_142 ( struct V_34 * V_35 ,
int V_346 ,
const struct V_23 * V_348 )
{
if ( F_140 ( V_35 , V_346 ) ||
F_141 ( V_35 , V_348 ) )
return true ;
return false ;
}
static int F_143 ( struct V_2 * V_56 , struct V_349 * V_350 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
int V_352 , V_353 ;
int V_354 = 0 , V_355 ;
struct V_34 * V_35 ;
struct V_356 * V_3 ;
struct V_47 * V_357 [ V_358 + 1 ] ;
T_5 V_53 = 0 ;
const struct V_23 * V_348 = NULL ;
unsigned int V_83 = V_359 ;
int V_346 = 0 ;
int V_32 ;
int V_360 ;
V_353 = V_350 -> args [ 0 ] ;
V_355 = V_350 -> args [ 1 ] ;
V_350 -> V_287 = V_33 -> V_361 ;
V_360 = F_145 ( V_350 -> V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_362 ) : sizeof( struct V_126 ) ;
if ( F_146 ( V_350 -> V_82 , V_360 , V_357 , V_358 , V_363 ) >= 0 ) {
if ( V_357 [ V_364 ] )
V_53 = F_147 ( V_357 [ V_364 ] ) ;
if ( V_357 [ V_318 ] )
V_346 = F_147 ( V_357 [ V_318 ] ) ;
if ( V_357 [ V_70 ] )
V_348 = F_137 ( V_357 [ V_70 ] ) ;
if ( V_346 || V_348 )
V_83 |= V_365 ;
}
for ( V_352 = V_353 ; V_352 < V_366 ; V_352 ++ , V_355 = 0 ) {
V_354 = 0 ;
V_3 = & V_33 -> V_367 [ V_352 ] ;
F_148 (dev, head, index_hlist) {
if ( F_142 ( V_35 , V_346 , V_348 ) )
goto V_368;
if ( V_354 < V_355 )
goto V_368;
V_32 = F_122 ( V_56 , V_35 , V_369 ,
F_64 ( V_350 -> V_56 ) . V_370 ,
V_350 -> V_82 -> V_371 , 0 ,
V_83 ,
V_53 ) ;
F_149 ( ( V_32 == - V_59 ) && ( V_56 -> V_372 == 0 ) ) ;
if ( V_32 < 0 )
goto V_71;
F_150 ( V_350 , F_151 ( V_56 ) ) ;
V_368:
V_354 ++ ;
}
}
V_71:
V_350 -> args [ 1 ] = V_354 ;
V_350 -> args [ 0 ] = V_352 ;
return V_56 -> V_372 ;
}
int F_152 ( struct V_47 * * V_357 , const struct V_47 * V_3 , int V_372 )
{
return F_153 ( V_357 , V_358 , V_3 , V_372 , V_363 ) ;
}
struct V_33 * F_154 ( struct V_33 * V_373 , struct V_47 * V_357 [] )
{
struct V_33 * V_33 ;
if ( V_357 [ V_374 ] )
V_33 = F_155 ( F_147 ( V_357 [ V_374 ] ) ) ;
else if ( V_357 [ V_375 ] )
V_33 = F_156 ( F_147 ( V_357 [ V_375 ] ) ) ;
else
V_33 = F_157 ( V_373 ) ;
return V_33 ;
}
static int F_158 ( struct V_34 * V_35 , struct V_47 * V_357 [] )
{
if ( V_35 ) {
if ( V_357 [ V_329 ] &&
F_159 ( V_357 [ V_329 ] ) < V_35 -> V_328 )
return - V_376 ;
if ( V_357 [ V_331 ] &&
F_159 ( V_357 [ V_331 ] ) < V_35 -> V_328 )
return - V_376 ;
}
if ( V_357 [ V_337 ] ) {
struct V_47 * V_339 ;
int V_377 , V_32 ;
F_160 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_161 ( V_339 ) ) ) )
return - V_378 ;
if ( ! V_54 -> V_379 )
return - V_199 ;
if ( V_54 -> V_380 ) {
V_32 = V_54 -> V_380 ( V_35 , V_339 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
}
return 0 ;
}
static int F_162 ( struct V_34 * V_35 , struct V_381 * V_382 ,
int V_383 )
{
const struct V_384 * V_25 = V_35 -> V_179 ;
return V_25 -> V_385 ( V_35 , V_382 -> V_190 , V_382 -> V_386 , V_383 ) ;
}
static int F_163 ( struct V_34 * V_35 , struct V_381 * V_382 , int V_383 )
{
if ( V_35 -> type != V_387 )
return - V_199 ;
return F_162 ( V_35 , V_382 , V_383 ) ;
}
static int F_164 ( struct V_34 * V_35 , struct V_47 * * V_357 )
{
const struct V_384 * V_25 = V_35 -> V_179 ;
int V_32 = - V_376 ;
if ( V_357 [ V_248 ] ) {
struct V_161 * V_388 = F_112 ( V_357 [ V_248 ] ) ;
V_32 = - V_199 ;
if ( V_25 -> V_389 )
V_32 = V_25 -> V_389 ( V_35 , V_388 -> V_190 ,
V_388 -> V_234 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_357 [ V_249 ] ) {
struct V_162 * V_390 = F_112 ( V_357 [ V_249 ] ) ;
V_32 = - V_199 ;
if ( V_25 -> V_391 )
V_32 = V_25 -> V_391 ( V_35 , V_390 -> V_190 , V_390 -> V_239 ,
V_390 -> V_240 ,
F_116 ( V_237 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_357 [ V_257 ] ) {
struct V_164 * V_392 [ V_163 ] ;
struct V_47 * V_204 ;
int V_377 , V_372 = 0 ;
V_32 = - V_199 ;
if ( ! V_25 -> V_391 )
return V_32 ;
F_160 (attr, tb[IFLA_VF_VLAN_LIST], rem) {
if ( F_161 ( V_204 ) != V_258 ||
F_159 ( V_204 ) < V_393 ) {
return - V_376 ;
}
if ( V_372 >= V_163 )
return - V_199 ;
V_392 [ V_372 ] = F_112 ( V_204 ) ;
V_372 ++ ;
}
if ( V_372 == 0 )
return - V_376 ;
V_32 = V_25 -> V_391 ( V_35 , V_392 [ 0 ] -> V_190 , V_392 [ 0 ] -> V_239 ,
V_392 [ 0 ] -> V_240 , V_392 [ 0 ] -> V_236 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_357 [ V_251 ] ) {
struct V_166 * V_382 = F_112 ( V_357 [ V_251 ] ) ;
struct V_229 V_394 ;
V_32 = - V_199 ;
if ( V_25 -> V_238 )
V_32 = V_25 -> V_238 ( V_35 , V_382 -> V_190 , & V_394 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = - V_199 ;
if ( V_25 -> V_395 )
V_32 = V_25 -> V_395 ( V_35 , V_382 -> V_190 ,
V_394 . V_243 ,
V_382 -> V_241 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_357 [ V_250 ] ) {
struct V_167 * V_382 = F_112 ( V_357 [ V_250 ] ) ;
V_32 = - V_199 ;
if ( V_25 -> V_395 )
V_32 = V_25 -> V_395 ( V_35 , V_382 -> V_190 ,
V_382 -> V_243 ,
V_382 -> V_242 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_357 [ V_252 ] ) {
struct V_165 * V_396 = F_112 ( V_357 [ V_252 ] ) ;
V_32 = - V_199 ;
if ( V_25 -> V_397 )
V_32 = V_25 -> V_397 ( V_35 , V_396 -> V_190 ,
V_396 -> V_244 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_357 [ V_253 ] ) {
struct V_168 * V_398 = F_112 ( V_357 [ V_253 ] ) ;
V_32 = - V_199 ;
if ( V_25 -> V_399 )
V_32 = V_25 -> V_399 ( V_35 , V_398 -> V_190 ,
V_398 -> V_245 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_357 [ V_254 ] ) {
struct V_169 * V_400 ;
V_32 = - V_199 ;
V_400 = F_112 ( V_357 [ V_254 ] ) ;
if ( V_25 -> V_401 )
V_32 = V_25 -> V_401 ( V_35 , V_400 -> V_190 ,
V_400 -> V_244 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_357 [ V_255 ] ) {
struct V_171 * V_382 = F_112 ( V_357 [ V_255 ] ) ;
V_32 = - V_199 ;
if ( V_25 -> V_402 )
V_32 = V_25 -> V_402 ( V_35 , V_382 -> V_190 , V_382 -> V_244 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_357 [ V_403 ] ) {
struct V_381 * V_382 = F_112 ( V_357 [ V_403 ] ) ;
if ( ! V_25 -> V_385 )
return - V_199 ;
return F_163 ( V_35 , V_382 , V_403 ) ;
}
if ( V_357 [ V_404 ] ) {
struct V_381 * V_382 = F_112 ( V_357 [ V_404 ] ) ;
if ( ! V_25 -> V_385 )
return - V_199 ;
return F_163 ( V_35 , V_382 , V_404 ) ;
}
return V_32 ;
}
static int F_165 ( struct V_34 * V_35 , int V_296 )
{
struct V_34 * V_290 = F_47 ( V_35 ) ;
const struct V_384 * V_25 ;
int V_32 ;
if ( V_290 ) {
if ( V_290 -> V_296 == V_296 )
return 0 ;
V_25 = V_290 -> V_179 ;
if ( V_25 -> V_405 ) {
V_32 = V_25 -> V_405 ( V_290 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_199 ;
}
}
if ( V_296 ) {
V_290 = F_166 ( F_132 ( V_35 ) , V_296 ) ;
if ( ! V_290 )
return - V_376 ;
V_25 = V_290 -> V_179 ;
if ( V_25 -> V_406 ) {
V_32 = V_25 -> V_406 ( V_290 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_199 ;
}
}
return 0 ;
}
static int F_167 ( const struct V_2 * V_56 ,
struct V_34 * V_35 , struct V_126 * V_127 ,
struct V_47 * * V_357 , char * V_407 , int V_408 )
{
const struct V_384 * V_25 = V_35 -> V_179 ;
int V_32 ;
if ( V_357 [ V_374 ] || V_357 [ V_375 ] ) {
struct V_33 * V_33 = F_154 ( F_132 ( V_35 ) , V_357 ) ;
if ( F_168 ( V_33 ) ) {
V_32 = F_169 ( V_33 ) ;
goto V_409;
}
if ( ! F_170 ( V_56 , V_33 -> V_410 , V_411 ) ) {
F_171 ( V_33 ) ;
V_32 = - V_412 ;
goto V_409;
}
V_32 = F_172 ( V_35 , V_33 , V_407 ) ;
F_171 ( V_33 ) ;
if ( V_32 )
goto V_409;
V_408 |= V_413 ;
}
if ( V_357 [ V_277 ] ) {
struct V_185 * V_414 ;
struct V_415 V_416 ;
if ( ! V_25 -> V_417 ) {
V_32 = - V_199 ;
goto V_409;
}
if ( ! F_173 ( V_35 ) ) {
V_32 = - V_418 ;
goto V_409;
}
V_414 = F_112 ( V_357 [ V_277 ] ) ;
V_416 . V_270 = ( unsigned long ) V_414 -> V_270 ;
V_416 . V_271 = ( unsigned long ) V_414 -> V_271 ;
V_416 . V_272 = ( unsigned short ) V_414 -> V_272 ;
V_416 . V_273 = ( unsigned char ) V_414 -> V_273 ;
V_416 . V_274 = ( unsigned char ) V_414 -> V_274 ;
V_416 . V_275 = ( unsigned char ) V_414 -> V_275 ;
V_32 = V_25 -> V_417 ( V_35 , & V_416 ) ;
if ( V_32 < 0 )
goto V_409;
V_408 |= V_419 ;
}
if ( V_357 [ V_329 ] ) {
struct V_420 * V_421 ;
int V_372 ;
V_372 = sizeof( V_422 ) + V_35 -> V_328 ;
V_421 = F_174 ( V_372 , V_20 ) ;
if ( ! V_421 ) {
V_32 = - V_423 ;
goto V_409;
}
V_421 -> V_424 = V_35 -> type ;
memcpy ( V_421 -> V_425 , F_112 ( V_357 [ V_329 ] ) ,
V_35 -> V_328 ) ;
V_32 = F_175 ( V_35 , V_421 ) ;
F_27 ( V_421 ) ;
if ( V_32 )
goto V_409;
V_408 |= V_413 ;
}
if ( V_357 [ V_304 ] ) {
V_32 = F_176 ( V_35 , F_147 ( V_357 [ V_304 ] ) ) ;
if ( V_32 < 0 )
goto V_409;
V_408 |= V_413 ;
}
if ( V_357 [ V_306 ] ) {
F_177 ( V_35 , F_147 ( V_357 [ V_306 ] ) ) ;
V_408 |= V_419 ;
}
if ( V_127 -> V_295 > 0 && V_407 [ 0 ] ) {
V_32 = F_178 ( V_35 , V_407 ) ;
if ( V_32 < 0 )
goto V_409;
V_408 |= V_413 ;
}
if ( V_357 [ V_323 ] ) {
V_32 = F_179 ( V_35 , F_112 ( V_357 [ V_323 ] ) ,
F_159 ( V_357 [ V_323 ] ) ) ;
if ( V_32 < 0 )
goto V_409;
V_408 |= V_419 ;
}
if ( V_357 [ V_331 ] ) {
F_180 ( V_35 -> V_267 , V_357 [ V_331 ] , V_35 -> V_328 ) ;
F_181 ( V_426 , V_35 ) ;
}
if ( V_127 -> V_128 || V_127 -> V_129 ) {
V_32 = F_182 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
goto V_409;
}
if ( V_357 [ V_318 ] ) {
V_32 = F_165 ( V_35 , F_147 ( V_357 [ V_318 ] ) ) ;
if ( V_32 )
goto V_409;
V_408 |= V_413 ;
}
if ( V_357 [ V_319 ] ) {
V_32 = F_183 ( V_35 , F_184 ( V_357 [ V_319 ] ) ) ;
if ( V_32 )
goto V_409;
V_408 |= V_413 ;
}
if ( V_357 [ V_298 ] ) {
unsigned long V_427 = F_147 ( V_357 [ V_298 ] ) ;
unsigned long V_428 = V_35 -> V_299 ;
if ( V_35 -> V_299 ^ V_427 ) {
V_35 -> V_299 = V_427 ;
V_32 = F_181 (
V_429 , V_35 ) ;
V_32 = F_185 ( V_32 ) ;
if ( V_32 ) {
V_35 -> V_299 = V_428 ;
goto V_409;
}
V_408 |= V_419 ;
}
}
if ( V_357 [ V_300 ] )
F_85 ( V_35 , F_184 ( V_357 [ V_300 ] ) ) ;
if ( V_357 [ V_302 ] ) {
unsigned char V_427 = F_184 ( V_357 [ V_302 ] ) ;
F_87 ( & V_122 ) ;
if ( V_35 -> V_303 ^ V_427 )
V_408 |= V_419 ;
V_35 -> V_303 = V_427 ;
F_88 ( & V_122 ) ;
}
if ( V_357 [ V_333 ] ) {
struct V_47 * V_215 [ V_430 + 1 ] ;
struct V_47 * V_204 ;
int V_377 ;
F_160 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_161 ( V_204 ) != V_246 ||
F_159 ( V_204 ) < V_393 ) {
V_32 = - V_376 ;
goto V_409;
}
V_32 = F_138 ( V_215 , V_430 , V_204 ,
V_431 ) ;
if ( V_32 < 0 )
goto V_409;
V_32 = F_164 ( V_35 , V_215 ) ;
if ( V_32 < 0 )
goto V_409;
V_408 |= V_419 ;
}
}
V_32 = 0 ;
if ( V_357 [ V_191 ] ) {
struct V_47 * V_275 [ V_432 + 1 ] ;
struct V_47 * V_204 ;
int V_190 ;
int V_377 ;
V_32 = - V_199 ;
if ( ! V_25 -> V_433 )
goto V_409;
F_160 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_161 ( V_204 ) != V_192 ||
F_159 ( V_204 ) < V_393 ) {
V_32 = - V_376 ;
goto V_409;
}
V_32 = F_138 ( V_275 , V_432 , V_204 ,
V_434 ) ;
if ( V_32 < 0 )
goto V_409;
if ( ! V_275 [ V_193 ] ) {
V_32 = - V_199 ;
goto V_409;
}
V_190 = F_147 ( V_275 [ V_193 ] ) ;
V_32 = V_25 -> V_433 ( V_35 , V_190 , V_275 ) ;
if ( V_32 < 0 )
goto V_409;
V_408 |= V_419 ;
}
}
V_32 = 0 ;
if ( V_357 [ V_195 ] ) {
struct V_47 * V_275 [ V_432 + 1 ] ;
V_32 = F_138 ( V_275 , V_432 ,
V_357 [ V_195 ] , V_434 ) ;
if ( V_32 < 0 )
goto V_409;
V_32 = - V_199 ;
if ( V_25 -> V_433 )
V_32 = V_25 -> V_433 ( V_35 , V_196 , V_275 ) ;
if ( V_32 < 0 )
goto V_409;
V_408 |= V_419 ;
}
if ( V_357 [ V_337 ] ) {
struct V_47 * V_339 ;
int V_377 ;
F_160 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_161 ( V_339 ) ) ) )
F_186 () ;
V_32 = V_54 -> V_379 ( V_35 , V_339 ) ;
if ( V_32 < 0 )
goto V_409;
V_408 |= V_419 ;
}
}
V_32 = 0 ;
if ( V_357 [ V_326 ] ) {
V_32 = F_187 ( V_35 ,
F_184 ( V_357 [ V_326 ] ) ) ;
if ( V_32 )
goto V_409;
V_408 |= V_419 ;
}
if ( V_357 [ V_281 ] ) {
struct V_47 * V_280 [ V_435 + 1 ] ;
T_5 V_436 = 0 ;
V_32 = F_138 ( V_280 , V_435 , V_357 [ V_281 ] ,
V_437 ) ;
if ( V_32 < 0 )
goto V_409;
if ( V_280 [ V_285 ] ) {
V_32 = - V_376 ;
goto V_409;
}
if ( V_280 [ V_438 ] ) {
V_436 = F_147 ( V_280 [ V_438 ] ) ;
if ( V_436 & ~ V_439 ) {
V_32 = - V_376 ;
goto V_409;
}
}
if ( V_280 [ V_440 ] ) {
V_32 = F_188 ( V_35 ,
F_189 ( V_280 [ V_440 ] ) ,
V_436 ) ;
if ( V_32 )
goto V_409;
V_408 |= V_419 ;
}
}
V_409:
if ( V_408 & V_413 ) {
if ( V_408 & V_419 )
F_89 ( V_35 ) ;
if ( V_32 < 0 )
F_190 ( L_3 ,
V_35 -> V_94 ) ;
}
return V_32 ;
}
static int F_191 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
int V_32 ;
struct V_47 * V_357 [ V_358 + 1 ] ;
char V_407 [ V_183 ] ;
V_32 = F_146 ( V_82 , sizeof( * V_127 ) , V_357 , V_358 , V_363 ) ;
if ( V_32 < 0 )
goto V_409;
if ( V_357 [ V_297 ] )
F_139 ( V_407 , V_357 [ V_297 ] , V_183 ) ;
else
V_407 [ 0 ] = '\0' ;
V_32 = - V_376 ;
V_127 = F_125 ( V_82 ) ;
if ( V_127 -> V_295 > 0 )
V_35 = F_166 ( V_33 , V_127 -> V_295 ) ;
else if ( V_357 [ V_297 ] )
V_35 = F_192 ( V_33 , V_407 ) ;
else
goto V_409;
if ( V_35 == NULL ) {
V_32 = - V_418 ;
goto V_409;
}
V_32 = F_158 ( V_35 , V_357 ) ;
if ( V_32 < 0 )
goto V_409;
V_32 = F_167 ( V_56 , V_35 , V_127 , V_357 , V_407 , 0 ) ;
V_409:
return V_32 ;
}
static int F_193 ( const struct V_33 * V_33 , int V_74 )
{
struct V_34 * V_35 , * V_441 ;
F_34 ( V_36 ) ;
bool V_442 = false ;
if ( ! V_74 )
return - V_412 ;
F_35 (net, dev) {
if ( V_35 -> V_74 == V_74 ) {
const struct V_23 * V_25 ;
V_442 = true ;
V_25 = V_35 -> V_23 ;
if ( ! V_25 || ! V_25 -> V_28 )
return - V_199 ;
}
}
if ( ! V_442 )
return - V_418 ;
F_194 (net, dev, aux) {
if ( V_35 -> V_74 == V_74 ) {
const struct V_23 * V_25 ;
V_25 = V_35 -> V_23 ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
}
}
F_36 ( & V_36 ) ;
return 0 ;
}
int F_195 ( struct V_34 * V_35 )
{
const struct V_23 * V_25 ;
F_34 ( V_36 ) ;
V_25 = V_35 -> V_23 ;
if ( ! V_25 || ! V_25 -> V_28 )
return - V_199 ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
F_36 ( & V_36 ) ;
return 0 ;
}
static int F_196 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_34 * V_35 ;
struct V_126 * V_127 ;
char V_407 [ V_183 ] ;
struct V_47 * V_357 [ V_358 + 1 ] ;
int V_32 ;
V_32 = F_146 ( V_82 , sizeof( * V_127 ) , V_357 , V_358 , V_363 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_357 [ V_297 ] )
F_139 ( V_407 , V_357 [ V_297 ] , V_183 ) ;
V_127 = F_125 ( V_82 ) ;
if ( V_127 -> V_295 > 0 )
V_35 = F_166 ( V_33 , V_127 -> V_295 ) ;
else if ( V_357 [ V_297 ] )
V_35 = F_192 ( V_33 , V_407 ) ;
else if ( V_357 [ V_306 ] )
return F_193 ( V_33 , F_147 ( V_357 [ V_306 ] ) ) ;
else
return - V_376 ;
if ( ! V_35 )
return - V_418 ;
return F_195 ( V_35 ) ;
}
int F_197 ( struct V_34 * V_35 , const struct V_126 * V_127 )
{
unsigned int V_443 ;
int V_32 ;
V_443 = V_35 -> V_83 ;
if ( V_127 && ( V_127 -> V_128 || V_127 -> V_129 ) ) {
V_32 = F_198 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_35 -> V_444 = V_445 ;
F_199 ( V_35 , V_443 , ~ 0U ) ;
return 0 ;
}
struct V_34 * F_200 ( struct V_33 * V_33 ,
const char * V_407 , unsigned char V_446 ,
const struct V_23 * V_25 , struct V_47 * V_357 [] )
{
int V_32 ;
struct V_34 * V_35 ;
unsigned int V_310 = 1 ;
unsigned int V_316 = 1 ;
if ( V_357 [ V_309 ] )
V_310 = F_147 ( V_357 [ V_309 ] ) ;
else if ( V_25 -> V_447 )
V_310 = V_25 -> V_447 () ;
if ( V_357 [ V_315 ] )
V_316 = F_147 ( V_357 [ V_315 ] ) ;
else if ( V_25 -> V_448 )
V_316 = V_25 -> V_448 () ;
V_32 = - V_423 ;
V_35 = F_201 ( V_25 -> V_449 , V_407 , V_446 ,
V_25 -> V_27 , V_310 , V_316 ) ;
if ( ! V_35 )
goto V_32;
F_202 ( V_35 , V_33 ) ;
V_35 -> V_23 = V_25 ;
V_35 -> V_444 = V_450 ;
if ( V_357 [ V_304 ] )
V_35 -> V_305 = F_147 ( V_357 [ V_304 ] ) ;
if ( V_357 [ V_329 ] ) {
memcpy ( V_35 -> V_330 , F_112 ( V_357 [ V_329 ] ) ,
F_159 ( V_357 [ V_329 ] ) ) ;
V_35 -> V_451 = V_452 ;
}
if ( V_357 [ V_331 ] )
memcpy ( V_35 -> V_267 , F_112 ( V_357 [ V_331 ] ) ,
F_159 ( V_357 [ V_331 ] ) ) ;
if ( V_357 [ V_298 ] )
V_35 -> V_299 = F_147 ( V_357 [ V_298 ] ) ;
if ( V_357 [ V_300 ] )
F_85 ( V_35 , F_184 ( V_357 [ V_300 ] ) ) ;
if ( V_357 [ V_302 ] )
V_35 -> V_303 = F_184 ( V_357 [ V_302 ] ) ;
if ( V_357 [ V_306 ] )
F_177 ( V_35 , F_147 ( V_357 [ V_306 ] ) ) ;
return V_35 ;
V_32:
return F_203 ( V_32 ) ;
}
static int F_204 ( const struct V_2 * V_56 ,
struct V_33 * V_33 , int V_74 ,
struct V_126 * V_127 ,
struct V_47 * * V_357 )
{
struct V_34 * V_35 , * V_441 ;
int V_32 ;
F_194 (net, dev, aux) {
if ( V_35 -> V_74 == V_74 ) {
V_32 = F_167 ( V_56 , V_35 , V_127 , V_357 , NULL , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
return 0 ;
}
static int F_205 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
const struct V_23 * V_25 ;
const struct V_23 * V_453 = NULL ;
struct V_34 * V_35 ;
struct V_34 * V_45 = NULL ;
struct V_126 * V_127 ;
char V_24 [ V_345 ] ;
char V_407 [ V_183 ] ;
struct V_47 * V_357 [ V_358 + 1 ] ;
struct V_47 * V_69 [ V_343 + 1 ] ;
unsigned char V_446 = V_454 ;
int V_32 ;
#ifdef F_206
V_455:
#endif
V_32 = F_146 ( V_82 , sizeof( * V_127 ) , V_357 , V_358 , V_363 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_357 [ V_297 ] )
F_139 ( V_407 , V_357 [ V_297 ] , V_183 ) ;
else
V_407 [ 0 ] = '\0' ;
V_127 = F_125 ( V_82 ) ;
if ( V_127 -> V_295 > 0 )
V_35 = F_166 ( V_33 , V_127 -> V_295 ) ;
else {
if ( V_407 [ 0 ] )
V_35 = F_192 ( V_33 , V_407 ) ;
else
V_35 = NULL ;
}
if ( V_35 ) {
V_45 = F_47 ( V_35 ) ;
if ( V_45 )
V_453 = V_45 -> V_23 ;
}
V_32 = F_158 ( V_35 , V_357 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_357 [ V_70 ] ) {
V_32 = F_138 ( V_69 , V_343 ,
V_357 [ V_70 ] , V_344 ) ;
if ( V_32 < 0 )
return V_32 ;
} else
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_69 [ V_64 ] ) {
F_139 ( V_24 , V_69 [ V_64 ] , sizeof( V_24 ) ) ;
V_25 = F_28 ( V_24 ) ;
} else {
V_24 [ 0 ] = '\0' ;
V_25 = NULL ;
}
if ( 1 ) {
struct V_47 * V_204 [ V_25 ? V_25 -> V_456 + 1 : 1 ] ;
struct V_47 * V_457 [ V_453 ? V_453 -> V_458 + 1 : 1 ] ;
struct V_47 * * V_63 = NULL ;
struct V_47 * * V_57 = NULL ;
struct V_33 * V_459 , * V_335 = NULL ;
if ( V_25 ) {
if ( V_25 -> V_456 && V_69 [ V_67 ] ) {
V_32 = F_138 ( V_204 , V_25 -> V_456 ,
V_69 [ V_67 ] ,
V_25 -> V_460 ) ;
if ( V_32 < 0 )
return V_32 ;
V_63 = V_204 ;
}
if ( V_25 -> V_461 ) {
V_32 = V_25 -> V_461 ( V_357 , V_63 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_453 ) {
if ( V_453 -> V_458 &&
V_69 [ V_61 ] ) {
V_32 = F_138 ( V_457 ,
V_453 -> V_458 ,
V_69 [ V_61 ] ,
V_453 -> V_462 ) ;
if ( V_32 < 0 )
return V_32 ;
V_57 = V_457 ;
}
if ( V_453 -> V_463 ) {
V_32 = V_453 -> V_463 ( V_357 , V_57 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_35 ) {
int V_408 = 0 ;
if ( V_82 -> V_464 & V_465 )
return - V_26 ;
if ( V_82 -> V_464 & V_466 )
return - V_199 ;
if ( V_69 [ V_67 ] ) {
if ( ! V_25 || V_25 != V_35 -> V_23 ||
! V_25 -> V_467 )
return - V_199 ;
V_32 = V_25 -> V_467 ( V_35 , V_357 , V_63 ) ;
if ( V_32 < 0 )
return V_32 ;
V_408 |= V_419 ;
}
if ( V_69 [ V_61 ] ) {
if ( ! V_453 || ! V_453 -> V_468 )
return - V_199 ;
V_32 = V_453 -> V_468 ( V_45 , V_35 ,
V_357 , V_57 ) ;
if ( V_32 < 0 )
return V_32 ;
V_408 |= V_419 ;
}
return F_167 ( V_56 , V_35 , V_127 , V_357 , V_407 , V_408 ) ;
}
if ( ! ( V_82 -> V_464 & V_469 ) ) {
if ( V_127 -> V_295 == 0 && V_357 [ V_306 ] )
return F_204 ( V_56 , V_33 ,
F_147 ( V_357 [ V_306 ] ) ,
V_127 , V_357 ) ;
return - V_418 ;
}
if ( V_357 [ V_277 ] || V_357 [ V_318 ] || V_357 [ V_470 ] )
return - V_199 ;
if ( ! V_25 ) {
#ifdef F_206
if ( V_24 [ 0 ] ) {
F_4 () ;
F_207 ( L_4 , V_24 ) ;
F_1 () ;
V_25 = F_28 ( V_24 ) ;
if ( V_25 )
goto V_455;
}
#endif
return - V_199 ;
}
if ( ! V_25 -> V_27 )
return - V_199 ;
if ( ! V_407 [ 0 ] ) {
snprintf ( V_407 , V_183 , L_5 , V_25 -> V_24 ) ;
V_446 = V_471 ;
}
V_459 = F_154 ( V_33 , V_357 ) ;
if ( F_168 ( V_459 ) )
return F_169 ( V_459 ) ;
V_32 = - V_412 ;
if ( ! F_170 ( V_56 , V_459 -> V_410 , V_411 ) )
goto V_71;
if ( V_357 [ V_336 ] ) {
int V_102 = F_189 ( V_357 [ V_336 ] ) ;
V_335 = F_208 ( V_459 , V_102 ) ;
if ( ! V_335 ) {
V_32 = - V_376 ;
goto V_71;
}
V_32 = - V_412 ;
if ( ! F_170 ( V_56 , V_335 -> V_410 , V_411 ) )
goto V_71;
}
V_35 = F_200 ( V_335 ? : V_459 , V_407 ,
V_446 , V_25 , V_357 ) ;
if ( F_168 ( V_35 ) ) {
V_32 = F_169 ( V_35 ) ;
goto V_71;
}
V_35 -> V_296 = V_127 -> V_295 ;
if ( V_25 -> V_472 ) {
V_32 = V_25 -> V_472 ( V_335 ? : V_33 , V_35 , V_357 , V_63 ) ;
if ( V_32 < 0 ) {
if ( V_35 -> V_473 == V_474 )
F_209 ( V_35 ) ;
goto V_71;
}
} else {
V_32 = F_210 ( V_35 ) ;
if ( V_32 < 0 ) {
F_209 ( V_35 ) ;
goto V_71;
}
}
V_32 = F_197 ( V_35 , V_127 ) ;
if ( V_32 < 0 )
goto V_475;
if ( V_335 ) {
V_32 = F_172 ( V_35 , V_459 , V_407 ) ;
if ( V_32 < 0 )
goto V_475;
}
V_71:
if ( V_335 )
F_171 ( V_335 ) ;
F_171 ( V_459 ) ;
return V_32 ;
V_475:
if ( V_25 -> V_472 ) {
F_34 ( V_36 ) ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
F_36 ( & V_36 ) ;
} else {
F_211 ( V_35 ) ;
}
goto V_71;
}
}
static int F_212 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_126 * V_127 ;
char V_407 [ V_183 ] ;
struct V_47 * V_357 [ V_358 + 1 ] ;
struct V_34 * V_35 = NULL ;
struct V_2 * V_476 ;
int V_32 ;
T_5 V_53 = 0 ;
V_32 = F_146 ( V_82 , sizeof( * V_127 ) , V_357 , V_358 , V_363 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_357 [ V_297 ] )
F_139 ( V_407 , V_357 [ V_297 ] , V_183 ) ;
if ( V_357 [ V_364 ] )
V_53 = F_147 ( V_357 [ V_364 ] ) ;
V_127 = F_125 ( V_82 ) ;
if ( V_127 -> V_295 > 0 )
V_35 = F_166 ( V_33 , V_127 -> V_295 ) ;
else if ( V_357 [ V_297 ] )
V_35 = F_192 ( V_33 , V_407 ) ;
else
return - V_376 ;
if ( V_35 == NULL )
return - V_418 ;
V_476 = F_213 ( F_99 ( V_35 , V_53 ) , V_20 ) ;
if ( V_476 == NULL )
return - V_21 ;
V_32 = F_122 ( V_476 , V_35 , V_369 , F_64 ( V_56 ) . V_370 ,
V_82 -> V_371 , 0 , 0 , V_53 ) ;
if ( V_32 < 0 ) {
F_149 ( V_32 == - V_59 ) ;
F_6 ( V_476 ) ;
} else
V_32 = F_68 ( V_476 , V_33 , F_64 ( V_56 ) . V_370 ) ;
return V_32 ;
}
static T_9 F_214 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_34 * V_35 ;
struct V_47 * V_357 [ V_358 + 1 ] ;
T_5 V_53 = 0 ;
T_9 V_477 = 0 ;
int V_360 ;
V_360 = F_145 ( V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_362 ) : sizeof( struct V_126 ) ;
if ( F_146 ( V_82 , V_360 , V_357 , V_358 , V_363 ) >= 0 ) {
if ( V_357 [ V_364 ] )
V_53 = F_147 ( V_357 [ V_364 ] ) ;
}
if ( ! V_53 )
return V_478 ;
F_29 (dev, &net->dev_base_head, dev_list) {
V_477 = F_215 ( T_9 , V_477 ,
F_99 ( V_35 ,
V_53 ) ) ;
}
return F_216 ( V_477 ) ;
}
static int F_217 ( struct V_2 * V_56 , struct V_349 * V_350 )
{
int V_354 ;
int V_355 = V_350 -> V_52 ;
if ( V_355 == 0 )
V_355 = 1 ;
for ( V_354 = 1 ; V_354 <= V_14 ; V_354 ++ ) {
int type = V_350 -> V_82 -> V_479 - V_9 ;
if ( V_354 < V_355 || V_354 == V_480 )
continue;
if ( V_15 [ V_354 ] == NULL ||
V_15 [ V_354 ] [ type ] . V_18 == NULL )
continue;
if ( V_354 > V_355 ) {
memset ( & V_350 -> args [ 0 ] , 0 , sizeof( V_350 -> args ) ) ;
V_350 -> V_481 = 0 ;
V_350 -> V_287 = 0 ;
}
if ( V_15 [ V_354 ] [ type ] . V_18 ( V_56 , V_350 ) )
break;
}
V_350 -> V_52 = V_354 ;
return V_56 -> V_372 ;
}
struct V_2 * F_218 ( int type , struct V_34 * V_35 ,
unsigned int V_288 , T_6 V_83 )
{
struct V_33 * V_33 = F_132 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
T_4 V_482 ;
V_56 = F_213 ( ( V_482 = F_99 ( V_35 , 0 ) ) , V_83 ) ;
if ( V_56 == NULL )
goto V_409;
V_32 = F_122 ( V_56 , V_35 , type , 0 , 0 , V_288 , 0 , 0 ) ;
if ( V_32 < 0 ) {
F_149 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
goto V_409;
}
return V_56 ;
V_409:
if ( V_32 < 0 )
F_73 ( V_33 , V_483 , V_32 ) ;
return NULL ;
}
void F_219 ( struct V_2 * V_56 , struct V_34 * V_35 , T_6 V_83 )
{
struct V_33 * V_33 = F_132 ( V_35 ) ;
F_70 ( V_56 , V_33 , 0 , V_483 , NULL , V_83 ) ;
}
void F_220 ( int type , struct V_34 * V_35 , unsigned int V_288 ,
T_6 V_83 )
{
struct V_2 * V_56 ;
if ( V_35 -> V_473 != V_484 )
return;
V_56 = F_218 ( type , V_35 , V_288 , V_83 ) ;
if ( V_56 )
F_219 ( V_56 , V_35 , V_83 ) ;
}
static int F_221 ( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_10 * V_485 , T_9 V_486 , T_5 V_73 , T_5 V_287 ,
int type , unsigned int V_83 ,
int V_487 , T_9 V_488 )
{
struct V_81 * V_82 ;
struct V_489 * V_490 ;
V_82 = F_124 ( V_56 , V_73 , V_287 , type , sizeof( * V_490 ) , V_487 ) ;
if ( ! V_82 )
return - V_59 ;
V_490 = F_125 ( V_82 ) ;
V_490 -> V_491 = V_492 ;
V_490 -> V_493 = 0 ;
V_490 -> V_494 = 0 ;
V_490 -> V_495 = V_83 ;
V_490 -> V_496 = 0 ;
V_490 -> V_497 = V_35 -> V_296 ;
V_490 -> V_488 = V_488 ;
if ( F_84 ( V_56 , V_498 , V_499 , V_485 ) )
goto V_95;
if ( V_486 )
if ( F_84 ( V_56 , V_500 , sizeof( T_9 ) , & V_486 ) )
goto V_95;
F_135 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_136 ( V_56 , V_82 ) ;
return - V_59 ;
}
static inline T_4 F_222 ( void )
{
return F_100 ( sizeof( struct V_489 ) ) +
F_48 ( V_499 ) +
F_48 ( sizeof( T_9 ) ) +
0 ;
}
static void F_223 ( struct V_34 * V_35 , T_10 * V_485 , T_9 V_486 , int type ,
T_9 V_488 )
{
struct V_33 * V_33 = F_132 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
V_56 = F_213 ( F_222 () , V_501 ) ;
if ( ! V_56 )
goto V_409;
V_32 = F_221 ( V_56 , V_35 , V_485 , V_486 ,
0 , 0 , type , V_502 , 0 , V_488 ) ;
if ( V_32 < 0 ) {
F_6 ( V_56 ) ;
goto V_409;
}
F_70 ( V_56 , V_33 , 0 , V_503 , NULL , V_501 ) ;
return;
V_409:
F_73 ( V_33 , V_503 , V_32 ) ;
}
int F_224 ( struct V_489 * V_490 ,
struct V_47 * V_357 [] ,
struct V_34 * V_35 ,
const unsigned char * V_485 , T_9 V_486 ,
T_9 V_83 )
{
int V_32 = - V_376 ;
if ( V_490 -> V_488 && ! ( V_490 -> V_488 & V_504 ) ) {
F_225 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( V_486 ) {
F_225 ( L_7 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_226 ( V_485 ) || F_227 ( V_485 ) )
V_32 = F_228 ( V_35 , V_485 ) ;
else if ( F_229 ( V_485 ) )
V_32 = F_230 ( V_35 , V_485 ) ;
if ( V_32 == - V_26 && ! ( V_83 & V_465 ) )
V_32 = 0 ;
return V_32 ;
}
static int F_231 ( struct V_47 * V_505 , T_9 * V_506 )
{
T_9 V_486 = 0 ;
if ( V_505 ) {
if ( F_159 ( V_505 ) != sizeof( T_9 ) ) {
F_225 ( L_8 ) ;
return - V_376 ;
}
V_486 = F_232 ( V_505 ) ;
if ( ! V_486 || V_486 >= V_507 ) {
F_225 ( L_9 ,
V_486 ) ;
return - V_376 ;
}
}
* V_506 = V_486 ;
return 0 ;
}
static int F_233 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_489 * V_490 ;
struct V_47 * V_357 [ V_508 + 1 ] ;
struct V_34 * V_35 ;
T_10 * V_485 ;
T_9 V_486 ;
int V_32 ;
V_32 = F_146 ( V_82 , sizeof( * V_490 ) , V_357 , V_508 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_490 = F_125 ( V_82 ) ;
if ( V_490 -> V_497 == 0 ) {
F_225 ( L_10 ) ;
return - V_376 ;
}
V_35 = F_166 ( V_33 , V_490 -> V_497 ) ;
if ( V_35 == NULL ) {
F_225 ( L_11 ) ;
return - V_418 ;
}
if ( ! V_357 [ V_498 ] || F_159 ( V_357 [ V_498 ] ) != V_499 ) {
F_225 ( L_12 ) ;
return - V_376 ;
}
V_485 = F_112 ( V_357 [ V_498 ] ) ;
V_32 = F_231 ( V_357 [ V_500 ] , & V_486 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_199 ;
if ( ( ! V_490 -> V_495 || V_490 -> V_495 & V_509 ) &&
( V_35 -> V_510 & V_511 ) ) {
struct V_34 * V_512 = F_47 ( V_35 ) ;
const struct V_384 * V_25 = V_512 -> V_179 ;
V_32 = V_25 -> V_513 ( V_490 , V_357 , V_35 , V_485 , V_486 ,
V_82 -> V_464 ) ;
if ( V_32 )
goto V_71;
else
V_490 -> V_495 &= ~ V_509 ;
}
if ( ( V_490 -> V_495 & V_502 ) ) {
if ( V_35 -> V_179 -> V_513 )
V_32 = V_35 -> V_179 -> V_513 ( V_490 , V_357 , V_35 , V_485 ,
V_486 ,
V_82 -> V_464 ) ;
else
V_32 = F_224 ( V_490 , V_357 , V_35 , V_485 , V_486 ,
V_82 -> V_464 ) ;
if ( ! V_32 ) {
F_223 ( V_35 , V_485 , V_486 , V_514 ,
V_490 -> V_488 ) ;
V_490 -> V_495 &= ~ V_502 ;
}
}
V_71:
return V_32 ;
}
int F_234 ( struct V_489 * V_490 ,
struct V_47 * V_357 [] ,
struct V_34 * V_35 ,
const unsigned char * V_485 , T_9 V_486 )
{
int V_32 = - V_376 ;
if ( ! ( V_490 -> V_488 & V_504 ) ) {
F_225 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_226 ( V_485 ) || F_227 ( V_485 ) )
V_32 = F_235 ( V_35 , V_485 ) ;
else if ( F_229 ( V_485 ) )
V_32 = F_236 ( V_35 , V_485 ) ;
return V_32 ;
}
static int F_237 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_489 * V_490 ;
struct V_47 * V_357 [ V_508 + 1 ] ;
struct V_34 * V_35 ;
int V_32 = - V_376 ;
T_11 * V_485 ;
T_9 V_486 ;
if ( ! F_238 ( V_56 , V_411 ) )
return - V_412 ;
V_32 = F_146 ( V_82 , sizeof( * V_490 ) , V_357 , V_508 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_490 = F_125 ( V_82 ) ;
if ( V_490 -> V_497 == 0 ) {
F_225 ( L_13 ) ;
return - V_376 ;
}
V_35 = F_166 ( V_33 , V_490 -> V_497 ) ;
if ( V_35 == NULL ) {
F_225 ( L_14 ) ;
return - V_418 ;
}
if ( ! V_357 [ V_498 ] || F_159 ( V_357 [ V_498 ] ) != V_499 ) {
F_225 ( L_15 ) ;
return - V_376 ;
}
V_485 = F_112 ( V_357 [ V_498 ] ) ;
V_32 = F_231 ( V_357 [ V_500 ] , & V_486 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_199 ;
if ( ( ! V_490 -> V_495 || V_490 -> V_495 & V_509 ) &&
( V_35 -> V_510 & V_511 ) ) {
struct V_34 * V_512 = F_47 ( V_35 ) ;
const struct V_384 * V_25 = V_512 -> V_179 ;
if ( V_25 -> V_515 )
V_32 = V_25 -> V_515 ( V_490 , V_357 , V_35 , V_485 , V_486 ) ;
if ( V_32 )
goto V_71;
else
V_490 -> V_495 &= ~ V_509 ;
}
if ( V_490 -> V_495 & V_502 ) {
if ( V_35 -> V_179 -> V_515 )
V_32 = V_35 -> V_179 -> V_515 ( V_490 , V_357 , V_35 , V_485 ,
V_486 ) ;
else
V_32 = F_234 ( V_490 , V_357 , V_35 , V_485 , V_486 ) ;
if ( ! V_32 ) {
F_223 ( V_35 , V_485 , V_486 , V_516 ,
V_490 -> V_488 ) ;
V_490 -> V_495 &= ~ V_502 ;
}
}
V_71:
return V_32 ;
}
static int F_239 ( struct V_2 * V_56 ,
struct V_349 * V_350 ,
struct V_34 * V_35 ,
int * V_354 ,
struct V_517 * V_30 )
{
struct V_518 * V_519 ;
int V_32 ;
T_5 V_370 , V_287 ;
V_370 = F_64 ( V_350 -> V_56 ) . V_370 ;
V_287 = V_350 -> V_82 -> V_371 ;
F_29 (ha, &list->list, list) {
if ( * V_354 < V_350 -> args [ 2 ] )
goto V_520;
V_32 = F_221 ( V_56 , V_35 , V_519 -> V_485 , 0 ,
V_370 , V_287 ,
V_514 , V_502 ,
V_359 , V_504 ) ;
if ( V_32 < 0 )
return V_32 ;
V_520:
* V_354 += 1 ;
}
return 0 ;
}
int F_240 ( struct V_2 * V_56 ,
struct V_349 * V_350 ,
struct V_34 * V_35 ,
struct V_34 * V_521 ,
int * V_354 )
{
int V_32 ;
F_241 ( V_35 ) ;
V_32 = F_239 ( V_56 , V_350 , V_35 , V_354 , & V_35 -> V_522 ) ;
if ( V_32 )
goto V_71;
V_32 = F_239 ( V_56 , V_350 , V_35 , V_354 , & V_35 -> V_523 ) ;
V_71:
F_242 ( V_35 ) ;
return V_32 ;
}
static int F_243 ( struct V_2 * V_56 , struct V_349 * V_350 )
{
struct V_34 * V_35 ;
struct V_47 * V_357 [ V_358 + 1 ] ;
struct V_34 * V_512 = NULL ;
const struct V_384 * V_25 = NULL ;
const struct V_384 * V_524 = NULL ;
struct V_126 * V_127 = F_125 ( V_350 -> V_82 ) ;
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_356 * V_3 ;
int V_525 = 0 ;
int V_526 = 0 ;
int V_352 , V_353 ;
int V_354 = 0 , V_355 ;
int V_32 = 0 ;
int V_527 = 0 ;
if ( F_146 ( V_350 -> V_82 , sizeof( struct V_126 ) , V_357 , V_358 ,
V_363 ) == 0 ) {
if ( V_357 [ V_318 ] )
V_526 = F_147 ( V_357 [ V_318 ] ) ;
}
V_525 = V_127 -> V_295 ;
if ( V_526 ) {
V_512 = F_166 ( V_33 , V_526 ) ;
if ( ! V_512 )
return - V_418 ;
V_25 = V_512 -> V_179 ;
}
V_353 = V_350 -> args [ 0 ] ;
V_355 = V_350 -> args [ 1 ] ;
for ( V_352 = V_353 ; V_352 < V_366 ; V_352 ++ , V_355 = 0 ) {
V_354 = 0 ;
V_3 = & V_33 -> V_367 [ V_352 ] ;
F_148 (dev, head, index_hlist) {
if ( V_525 && ( V_35 -> V_296 != V_525 ) )
continue;
if ( ! V_526 ) {
if ( V_35 -> V_510 & V_511 ) {
V_512 = F_47 ( V_35 ) ;
V_524 = V_512 -> V_179 ;
}
} else {
if ( V_35 != V_512 &&
! ( V_35 -> V_510 & V_511 ) )
continue;
if ( V_512 != F_47 ( V_35 ) &&
! ( V_35 -> V_510 & V_528 ) )
continue;
V_524 = V_25 ;
}
if ( V_354 < V_355 )
goto V_368;
if ( V_35 -> V_510 & V_511 ) {
if ( V_524 && V_524 -> V_529 ) {
V_32 = V_524 -> V_529 ( V_56 , V_350 ,
V_512 , V_35 ,
& V_527 ) ;
if ( V_32 == - V_59 )
goto V_71;
}
}
if ( V_35 -> V_179 -> V_529 )
V_32 = V_35 -> V_179 -> V_529 ( V_56 , V_350 ,
V_35 , NULL ,
& V_527 ) ;
else
V_32 = F_240 ( V_56 , V_350 , V_35 , NULL ,
& V_527 ) ;
if ( V_32 == - V_59 )
goto V_71;
V_524 = NULL ;
V_350 -> args [ 2 ] = 0 ;
V_527 = 0 ;
V_368:
V_354 ++ ;
}
}
V_71:
V_350 -> args [ 0 ] = V_352 ;
V_350 -> args [ 1 ] = V_354 ;
V_350 -> args [ 2 ] = V_527 ;
return V_56 -> V_372 ;
}
static int F_244 ( struct V_2 * V_56 , T_5 V_83 , T_5 V_530 ,
unsigned int V_531 , unsigned int V_532 )
{
if ( V_530 & V_532 )
return F_121 ( V_56 , V_531 , ! ! ( V_83 & V_532 ) ) ;
return 0 ;
}
int F_245 ( struct V_2 * V_56 , T_5 V_73 , T_5 V_287 ,
struct V_34 * V_35 , T_9 V_533 ,
T_5 V_83 , T_5 V_530 , int V_487 ,
T_5 V_534 ,
int (* F_246)( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_5 V_534 ) )
{
struct V_81 * V_82 ;
struct V_126 * V_127 ;
struct V_47 * V_535 ;
struct V_47 * V_536 ;
T_10 V_118 = F_127 ( V_35 ) ? V_35 -> V_118 : V_301 ;
struct V_34 * V_512 = F_47 ( V_35 ) ;
int V_32 = 0 ;
V_82 = F_124 ( V_56 , V_73 , V_287 , V_369 , sizeof( * V_127 ) , V_487 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_125 ( V_82 ) ;
V_127 -> V_291 = V_492 ;
V_127 -> V_293 = 0 ;
V_127 -> V_294 = V_35 -> type ;
V_127 -> V_295 = V_35 -> V_296 ;
V_127 -> V_128 = F_126 ( V_35 ) ;
V_127 -> V_129 = 0 ;
if ( F_57 ( V_56 , V_297 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_304 , V_35 -> V_305 ) ||
F_121 ( V_56 , V_300 , V_118 ) ||
( V_512 &&
F_78 ( V_56 , V_318 , V_512 -> V_296 ) ) ||
( V_35 -> V_328 &&
F_84 ( V_56 , V_329 , V_35 -> V_328 , V_35 -> V_330 ) ) ||
( V_35 -> V_296 != F_129 ( V_35 ) &&
F_78 ( V_56 , V_317 , F_129 ( V_35 ) ) ) )
goto V_95;
V_535 = F_58 ( V_56 , V_337 ) ;
if ( ! V_535 )
goto V_95;
if ( F_247 ( V_56 , V_537 , V_538 ) ) {
F_60 ( V_56 , V_535 ) ;
goto V_95;
}
if ( V_533 != V_539 ) {
if ( F_247 ( V_56 , V_540 , V_533 ) ) {
F_60 ( V_56 , V_535 ) ;
goto V_95;
}
}
if ( F_246 ) {
V_32 = F_246 ( V_56 , V_35 , V_534 ) ;
if ( V_32 ) {
F_60 ( V_56 , V_535 ) ;
goto V_95;
}
}
F_59 ( V_56 , V_535 ) ;
V_536 = F_58 ( V_56 , V_470 | V_541 ) ;
if ( ! V_536 )
goto V_95;
if ( F_244 ( V_56 , V_83 , V_530 ,
V_542 , V_543 ) ||
F_244 ( V_56 , V_83 , V_530 ,
V_544 , V_545 ) ||
F_244 ( V_56 , V_83 , V_530 ,
V_546 ,
V_547 ) ||
F_244 ( V_56 , V_83 , V_530 ,
V_548 , V_549 ) ||
F_244 ( V_56 , V_83 , V_530 ,
V_550 , V_551 ) ||
F_244 ( V_56 , V_83 , V_530 ,
V_552 , V_553 ) ||
F_244 ( V_56 , V_83 , V_530 ,
V_554 , V_555 ) ||
F_244 ( V_56 , V_83 , V_530 ,
V_556 , V_557 ) ) {
F_60 ( V_56 , V_536 ) ;
goto V_95;
}
F_59 ( V_56 , V_536 ) ;
F_135 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_136 ( V_56 , V_82 ) ;
return V_32 ? V_32 : - V_59 ;
}
static int F_248 ( struct V_2 * V_56 , struct V_349 * V_350 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_34 * V_35 ;
int V_354 = 0 ;
T_5 V_370 = F_64 ( V_350 -> V_56 ) . V_370 ;
T_5 V_287 = V_350 -> V_82 -> V_371 ;
T_5 V_534 = 0 ;
int V_32 ;
if ( F_145 ( V_350 -> V_82 ) > sizeof( struct V_126 ) ) {
struct V_47 * V_558 ;
V_558 = F_249 ( V_350 -> V_82 , sizeof( struct V_126 ) ,
V_364 ) ;
if ( V_558 ) {
if ( F_159 ( V_558 ) < sizeof( V_534 ) )
return - V_376 ;
V_534 = F_147 ( V_558 ) ;
}
}
F_250 () ;
F_251 (net, dev) {
const struct V_384 * V_25 = V_35 -> V_179 ;
struct V_34 * V_512 = F_47 ( V_35 ) ;
if ( V_512 && V_512 -> V_179 -> V_559 ) {
if ( V_354 >= V_350 -> args [ 0 ] ) {
V_32 = V_512 -> V_179 -> V_559 (
V_56 , V_370 , V_287 , V_35 ,
V_534 , V_359 ) ;
if ( V_32 < 0 && V_32 != - V_199 )
break;
}
V_354 ++ ;
}
if ( V_25 -> V_559 ) {
if ( V_354 >= V_350 -> args [ 0 ] ) {
V_32 = V_25 -> V_559 ( V_56 , V_370 ,
V_287 , V_35 ,
V_534 ,
V_359 ) ;
if ( V_32 < 0 && V_32 != - V_199 )
break;
}
V_354 ++ ;
}
}
F_252 () ;
V_350 -> args [ 0 ] = V_354 ;
return V_56 -> V_372 ;
}
static inline T_4 F_253 ( void )
{
return F_100 ( sizeof( struct V_126 ) )
+ F_48 ( V_183 )
+ F_48 ( V_186 )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_10 ) )
+ F_48 ( sizeof( struct V_47 ) )
+ F_48 ( sizeof( T_9 ) )
+ F_48 ( sizeof( T_9 ) ) ;
}
static int F_254 ( struct V_34 * V_35 )
{
struct V_33 * V_33 = F_132 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_199 ;
if ( ! V_35 -> V_179 -> V_559 )
return 0 ;
V_56 = F_213 ( F_253 () , V_501 ) ;
if ( ! V_56 ) {
V_32 = - V_423 ;
goto V_409;
}
V_32 = V_35 -> V_179 -> V_559 ( V_56 , 0 , 0 , V_35 , 0 , 0 ) ;
if ( V_32 < 0 )
goto V_409;
if ( ! V_56 -> V_372 )
goto V_409;
F_70 ( V_56 , V_33 , 0 , V_483 , NULL , V_501 ) ;
return 0 ;
V_409:
F_149 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
if ( V_32 )
F_73 ( V_33 , V_483 , V_32 ) ;
return V_32 ;
}
static int F_255 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_560 , * V_204 = NULL ;
int V_377 , V_32 = - V_199 ;
T_9 V_83 = 0 ;
bool V_561 = false ;
if ( F_145 ( V_82 ) < sizeof( * V_127 ) )
return - V_376 ;
V_127 = F_125 ( V_82 ) ;
if ( V_127 -> V_291 != V_492 )
return - V_562 ;
V_35 = F_166 ( V_33 , V_127 -> V_295 ) ;
if ( ! V_35 ) {
F_225 ( L_16 ) ;
return - V_418 ;
}
V_560 = F_249 ( V_82 , sizeof( struct V_126 ) , V_337 ) ;
if ( V_560 ) {
F_160 (attr, br_spec, rem) {
if ( F_161 ( V_204 ) == V_537 ) {
if ( F_159 ( V_204 ) < sizeof( V_83 ) )
return - V_376 ;
V_561 = true ;
V_83 = F_232 ( V_204 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_563 ) ) {
struct V_34 * V_512 = F_47 ( V_35 ) ;
if ( ! V_512 || ! V_512 -> V_179 -> V_564 ) {
V_32 = - V_199 ;
goto V_71;
}
V_32 = V_512 -> V_179 -> V_564 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_563 ;
}
if ( ( V_83 & V_538 ) ) {
if ( ! V_35 -> V_179 -> V_564 )
V_32 = - V_199 ;
else
V_32 = V_35 -> V_179 -> V_564 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_538 ;
V_32 = F_254 ( V_35 ) ;
}
}
if ( V_561 )
memcpy ( F_112 ( V_204 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static int F_256 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_560 , * V_204 = NULL ;
int V_377 , V_32 = - V_199 ;
T_9 V_83 = 0 ;
bool V_561 = false ;
if ( F_145 ( V_82 ) < sizeof( * V_127 ) )
return - V_376 ;
V_127 = F_125 ( V_82 ) ;
if ( V_127 -> V_291 != V_492 )
return - V_562 ;
V_35 = F_166 ( V_33 , V_127 -> V_295 ) ;
if ( ! V_35 ) {
F_225 ( L_16 ) ;
return - V_418 ;
}
V_560 = F_249 ( V_82 , sizeof( struct V_126 ) , V_337 ) ;
if ( V_560 ) {
F_160 (attr, br_spec, rem) {
if ( F_161 ( V_204 ) == V_537 ) {
if ( F_159 ( V_204 ) < sizeof( V_83 ) )
return - V_376 ;
V_561 = true ;
V_83 = F_232 ( V_204 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_563 ) ) {
struct V_34 * V_512 = F_47 ( V_35 ) ;
if ( ! V_512 || ! V_512 -> V_179 -> V_565 ) {
V_32 = - V_199 ;
goto V_71;
}
V_32 = V_512 -> V_179 -> V_565 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_563 ;
}
if ( ( V_83 & V_538 ) ) {
if ( ! V_35 -> V_179 -> V_565 )
V_32 = - V_199 ;
else
V_32 = V_35 -> V_179 -> V_565 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_538 ;
V_32 = F_254 ( V_35 ) ;
}
}
if ( V_561 )
memcpy ( F_112 ( V_204 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static bool F_257 ( unsigned int V_530 , int V_566 , int V_567 )
{
return ( V_530 & F_258 ( V_566 ) ) &&
( ! V_567 || V_567 == V_566 ) ;
}
static int F_259 ( int V_568 )
{
switch ( V_568 ) {
case V_569 :
return sizeof( struct V_132 ) ;
}
return 0 ;
}
static int F_260 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int * V_570 )
{
struct V_47 * V_204 = NULL ;
int V_568 , V_48 ;
void * V_571 ;
int V_32 ;
if ( ! ( V_35 -> V_179 && V_35 -> V_179 -> V_572 &&
V_35 -> V_179 -> V_573 ) )
return - V_340 ;
for ( V_568 = V_574 ;
V_568 <= V_575 ; V_568 ++ ) {
if ( V_568 < * V_570 )
continue;
V_48 = F_259 ( V_568 ) ;
if ( ! V_48 )
continue;
if ( ! V_35 -> V_179 -> V_572 ( V_35 , V_568 ) )
continue;
V_204 = F_111 ( V_56 , V_568 , V_48 ,
V_576 ) ;
if ( ! V_204 )
goto V_95;
V_571 = F_112 ( V_204 ) ;
memset ( V_571 , 0 , V_48 ) ;
V_32 = V_35 -> V_179 -> V_573 ( V_568 , V_35 ,
V_571 ) ;
if ( V_32 )
goto V_577;
}
if ( ! V_204 )
return - V_340 ;
* V_570 = 0 ;
return 0 ;
V_95:
V_32 = - V_59 ;
V_577:
* V_570 = V_568 ;
return V_32 ;
}
static int F_261 ( const struct V_34 * V_35 )
{
int V_578 = 0 ;
int V_568 ;
int V_48 ;
if ( ! ( V_35 -> V_179 && V_35 -> V_179 -> V_572 &&
V_35 -> V_179 -> V_573 ) )
return 0 ;
for ( V_568 = V_574 ;
V_568 <= V_575 ; V_568 ++ ) {
if ( ! V_35 -> V_179 -> V_572 ( V_35 , V_568 ) )
continue;
V_48 = F_259 ( V_568 ) ;
V_578 += F_96 ( V_48 ) ;
}
if ( V_578 != 0 )
V_578 += F_48 ( 0 ) ;
return V_578 ;
}
static int F_262 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_287 , T_5 V_288 ,
unsigned int V_83 , unsigned int V_534 ,
int * V_567 , int * V_570 )
{
struct V_579 * V_580 ;
struct V_81 * V_82 ;
struct V_47 * V_204 ;
int V_581 = * V_570 ;
int V_32 ;
F_123 () ;
V_82 = F_124 ( V_56 , V_73 , V_287 , type , sizeof( * V_580 ) , V_83 ) ;
if ( ! V_82 )
return - V_59 ;
V_580 = F_125 ( V_82 ) ;
V_580 -> V_296 = V_35 -> V_296 ;
V_580 -> V_534 = V_534 ;
if ( F_257 ( V_534 , V_582 , * V_567 ) ) {
struct V_132 * V_210 ;
V_204 = F_111 ( V_56 , V_582 ,
sizeof( struct V_132 ) ,
V_583 ) ;
if ( ! V_204 )
goto V_95;
V_210 = F_112 ( V_204 ) ;
F_113 ( V_35 , V_210 ) ;
}
if ( F_257 ( V_534 , V_584 , * V_567 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
if ( V_25 && V_25 -> V_585 ) {
* V_567 = V_584 ;
V_204 = F_58 ( V_56 ,
V_584 ) ;
if ( ! V_204 )
goto V_95;
V_32 = V_25 -> V_585 ( V_56 , V_35 , V_570 , * V_567 ) ;
F_59 ( V_56 , V_204 ) ;
if ( V_32 )
goto V_95;
* V_567 = 0 ;
}
}
if ( F_257 ( V_534 , V_586 ,
* V_567 ) ) {
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_347 ;
V_347 = F_47 ( V_35 ) ;
if ( V_347 )
V_25 = V_347 -> V_23 ;
if ( V_25 && V_25 -> V_585 ) {
* V_567 = V_586 ;
V_204 = F_58 ( V_56 ,
V_586 ) ;
if ( ! V_204 )
goto V_95;
V_32 = V_25 -> V_585 ( V_56 , V_35 , V_570 , * V_567 ) ;
F_59 ( V_56 , V_204 ) ;
if ( V_32 )
goto V_95;
* V_567 = 0 ;
}
}
if ( F_257 ( V_534 , V_587 ,
* V_567 ) ) {
* V_567 = V_587 ;
V_204 = F_58 ( V_56 , V_587 ) ;
if ( ! V_204 )
goto V_95;
V_32 = F_260 ( V_56 , V_35 , V_570 ) ;
if ( V_32 == - V_340 )
F_60 ( V_56 , V_204 ) ;
else
F_59 ( V_56 , V_204 ) ;
if ( V_32 && V_32 != - V_340 )
goto V_95;
* V_567 = 0 ;
}
F_135 ( V_56 , V_82 ) ;
return 0 ;
V_95:
if ( ! ( V_83 & V_359 ) || V_581 == * V_570 )
F_136 ( V_56 , V_82 ) ;
else
F_135 ( V_56 , V_82 ) ;
return - V_59 ;
}
static T_4 F_263 ( const struct V_34 * V_35 ,
T_5 V_534 )
{
T_4 V_48 = 0 ;
if ( F_257 ( V_534 , V_582 , 0 ) )
V_48 += F_96 ( sizeof( struct V_132 ) ) ;
if ( F_257 ( V_534 , V_584 , 0 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
int V_204 = V_584 ;
if ( V_25 && V_25 -> V_588 ) {
V_48 += F_48 ( V_25 -> V_588 ( V_35 ,
V_204 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
if ( F_257 ( V_534 , V_586 , 0 ) ) {
struct V_34 * V_589 = (struct V_34 * ) V_35 ;
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_347 ;
V_347 = F_47 ( V_589 ) ;
if ( V_347 )
V_25 = V_347 -> V_23 ;
if ( V_25 && V_25 -> V_588 ) {
int V_204 = V_586 ;
V_48 += F_48 ( V_25 -> V_588 ( V_35 ,
V_204 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
if ( F_257 ( V_534 , V_587 , 0 ) )
V_48 += F_261 ( V_35 ) ;
return V_48 ;
}
static int F_264 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
struct V_34 * V_35 = NULL ;
int V_567 = 0 , V_570 = 0 ;
struct V_579 * V_580 ;
struct V_2 * V_476 ;
T_5 V_534 ;
int V_32 ;
if ( F_145 ( V_82 ) < sizeof( * V_580 ) )
return - V_376 ;
V_580 = F_125 ( V_82 ) ;
if ( V_580 -> V_296 > 0 )
V_35 = F_166 ( V_33 , V_580 -> V_296 ) ;
else
return - V_376 ;
if ( ! V_35 )
return - V_418 ;
V_534 = V_580 -> V_534 ;
if ( ! V_534 )
return - V_376 ;
V_476 = F_213 ( F_263 ( V_35 , V_534 ) , V_20 ) ;
if ( ! V_476 )
return - V_21 ;
V_32 = F_262 ( V_476 , V_35 , V_590 ,
F_64 ( V_56 ) . V_370 , V_82 -> V_371 , 0 ,
0 , V_534 , & V_567 , & V_570 ) ;
if ( V_32 < 0 ) {
F_149 ( V_32 == - V_59 ) ;
F_6 ( V_476 ) ;
} else {
V_32 = F_68 ( V_476 , V_33 , F_64 ( V_56 ) . V_370 ) ;
}
return V_32 ;
}
static int F_265 ( struct V_2 * V_56 , struct V_349 * V_350 )
{
int V_352 , V_353 , V_32 , V_355 , V_591 , V_581 ;
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
unsigned int V_83 = V_359 ;
struct V_579 * V_580 ;
struct V_356 * V_3 ;
struct V_34 * V_35 ;
T_5 V_534 = 0 ;
int V_354 = 0 ;
V_353 = V_350 -> args [ 0 ] ;
V_355 = V_350 -> args [ 1 ] ;
V_591 = V_350 -> args [ 2 ] ;
V_581 = V_350 -> args [ 3 ] ;
V_350 -> V_287 = V_33 -> V_361 ;
if ( F_145 ( V_350 -> V_82 ) < sizeof( * V_580 ) )
return - V_376 ;
V_580 = F_125 ( V_350 -> V_82 ) ;
V_534 = V_580 -> V_534 ;
if ( ! V_534 )
return - V_376 ;
for ( V_352 = V_353 ; V_352 < V_366 ; V_352 ++ , V_355 = 0 ) {
V_354 = 0 ;
V_3 = & V_33 -> V_367 [ V_352 ] ;
F_148 (dev, head, index_hlist) {
if ( V_354 < V_355 )
goto V_368;
V_32 = F_262 ( V_56 , V_35 , V_590 ,
F_64 ( V_350 -> V_56 ) . V_370 ,
V_350 -> V_82 -> V_371 , 0 ,
V_83 , V_534 ,
& V_591 , & V_581 ) ;
F_149 ( ( V_32 == - V_59 ) && ( V_56 -> V_372 == 0 ) ) ;
if ( V_32 < 0 )
goto V_71;
V_581 = 0 ;
V_591 = 0 ;
F_150 ( V_350 , F_151 ( V_56 ) ) ;
V_368:
V_354 ++ ;
}
}
V_71:
V_350 -> args [ 3 ] = V_581 ;
V_350 -> args [ 2 ] = V_591 ;
V_350 -> args [ 1 ] = V_354 ;
V_350 -> args [ 0 ] = V_352 ;
return V_56 -> V_372 ;
}
static int F_266 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_144 ( V_56 -> V_351 ) ;
T_1 V_16 ;
int V_24 ;
int V_52 ;
int type ;
int V_32 ;
type = V_82 -> V_479 ;
if ( type > V_592 )
return - V_199 ;
type -= V_9 ;
if ( F_145 ( V_82 ) < sizeof( struct V_362 ) )
return 0 ;
V_52 = ( (struct V_362 * ) F_125 ( V_82 ) ) -> V_593 ;
V_24 = type & 3 ;
if ( V_24 != 2 && ! F_267 ( V_56 , V_411 ) )
return - V_412 ;
if ( V_24 == 2 && V_82 -> V_464 & V_594 ) {
struct V_76 * V_77 ;
T_2 V_18 ;
T_3 V_19 ;
T_9 V_595 = 0 ;
V_18 = F_19 ( V_52 , type ) ;
if ( V_18 == NULL )
return - V_199 ;
V_19 = F_20 ( V_52 , type ) ;
if ( V_19 )
V_595 = V_19 ( V_56 , V_82 ) ;
F_4 () ;
V_77 = V_33 -> V_77 ;
{
struct V_596 V_597 = {
. V_598 = V_18 ,
. V_595 = V_595 ,
} ;
V_32 = F_268 ( V_77 , V_56 , V_82 , & V_597 ) ;
}
F_1 () ;
return V_32 ;
}
V_16 = F_18 ( V_52 , type ) ;
if ( V_16 == NULL )
return - V_199 ;
return V_16 ( V_56 , V_82 ) ;
}
static void F_269 ( struct V_2 * V_56 )
{
F_1 () ;
F_270 ( V_56 , & F_266 ) ;
F_8 () ;
}
static int F_271 ( struct V_599 * V_600 , unsigned long V_601 , void * V_602 )
{
struct V_34 * V_35 = F_272 ( V_602 ) ;
switch ( V_601 ) {
case V_603 :
case V_604 :
case V_605 :
case V_606 :
case V_607 :
case V_608 :
case V_609 :
case V_610 :
case V_611 :
case V_612 :
case V_613 :
case V_614 :
case V_615 :
break;
default:
F_220 ( V_369 , V_35 , 0 , V_20 ) ;
break;
}
return V_616 ;
}
static int T_12 F_273 ( struct V_33 * V_33 )
{
struct V_76 * V_351 ;
struct V_617 V_618 = {
. V_619 = V_620 ,
. V_621 = F_269 ,
. V_622 = & V_1 ,
. V_83 = V_623 ,
} ;
V_351 = F_274 ( V_33 , V_624 , & V_618 ) ;
if ( ! V_351 )
return - V_423 ;
V_33 -> V_77 = V_351 ;
return 0 ;
}
static void T_13 F_275 ( struct V_33 * V_33 )
{
F_276 ( V_33 -> V_77 ) ;
V_33 -> V_77 = NULL ;
}
void T_14 F_277 ( void )
{
if ( F_278 ( & V_625 ) )
F_24 ( L_17 ) ;
F_279 ( & V_626 ) ;
F_23 ( V_17 , V_627 , F_212 ,
F_143 , F_214 ) ;
F_23 ( V_17 , V_628 , F_191 , NULL , NULL ) ;
F_23 ( V_17 , V_369 , F_205 , NULL , NULL ) ;
F_23 ( V_17 , V_629 , F_196 , NULL , NULL ) ;
F_23 ( V_17 , V_630 , NULL , F_217 , NULL ) ;
F_23 ( V_17 , V_631 , NULL , F_217 , NULL ) ;
F_23 ( V_632 , V_514 , F_233 , NULL , NULL ) ;
F_23 ( V_632 , V_516 , F_237 , NULL , NULL ) ;
F_23 ( V_632 , V_633 , NULL , F_243 , NULL ) ;
F_23 ( V_632 , V_627 , NULL , F_248 , NULL ) ;
F_23 ( V_632 , V_629 , F_256 , NULL , NULL ) ;
F_23 ( V_632 , V_628 , F_255 , NULL , NULL ) ;
F_23 ( V_17 , V_634 , F_264 , F_265 ,
NULL ) ;
}
