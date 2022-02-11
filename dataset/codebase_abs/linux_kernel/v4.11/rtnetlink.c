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
if ( V_35 -> V_35 . V_158 && ( V_53 & V_159 ) ) {
int V_160 = F_94 ( V_35 -> V_35 . V_158 ) ;
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
F_95 ( sizeof( V_170 ) ) +
F_95 ( sizeof( V_170 ) ) +
F_95 ( sizeof( V_170 ) ) +
F_95 ( sizeof( V_170 ) ) +
F_95 ( sizeof( V_170 ) ) +
F_95 ( sizeof( V_170 ) ) +
F_48 ( sizeof( struct V_171 ) ) ) ;
return V_48 ;
} else
return 0 ;
}
static T_4 F_96 ( const struct V_34 * V_35 ,
T_5 V_53 )
{
T_4 V_172 = F_48 ( 4 )
+ F_48 ( V_173 )
+ F_48 ( V_174 )
+ F_48 ( V_174 )
+ F_48 ( 1 )
+ F_48 ( 2 ) ;
T_4 V_175 = F_48 ( sizeof( struct V_47 ) ) ;
T_4 V_176 = F_48 ( sizeof( struct V_47 ) )
+ V_172 ;
T_4 V_177 = F_48 ( sizeof( struct V_47 ) )
+ V_172 ;
if ( ! V_35 -> V_178 -> V_179 || ! V_35 -> V_35 . V_158 ||
! ( V_53 & V_159 ) )
return 0 ;
if ( F_94 ( V_35 -> V_35 . V_158 ) )
return V_177 + V_175 +
V_176 * F_94 ( V_35 -> V_35 . V_158 ) ;
else
return V_177 ;
}
static T_4 F_97 ( const struct V_34 * V_35 )
{
T_4 V_180 = F_48 ( 0 ) +
F_48 ( 1 ) ;
if ( ! V_35 -> V_178 -> V_181 )
return 0 ;
else
return V_180 ;
}
static T_7 T_4 F_98 ( const struct V_34 * V_35 ,
T_5 V_53 )
{
return F_99 ( sizeof( struct V_126 ) )
+ F_48 ( V_182 )
+ F_48 ( V_183 )
+ F_48 ( V_182 )
+ F_95 ( sizeof( struct V_184 ) )
+ F_48 ( sizeof( struct V_130 ) )
+ F_95 ( sizeof( struct V_132 ) )
+ F_48 ( V_185 )
+ F_48 ( V_185 )
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
+ F_96 ( V_35 , V_53 )
+ F_49 ( V_35 )
+ F_54 ( V_35 , V_53 )
+ F_48 ( V_186 )
+ F_48 ( V_186 )
+ F_48 ( V_182 )
+ F_97 ( V_35 )
+ F_48 ( 1 ) ;
}
static int F_100 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_187 ;
struct V_47 * V_188 ;
int V_189 ;
int V_32 ;
V_187 = F_58 ( V_56 , V_190 ) ;
if ( ! V_187 )
return - V_59 ;
for ( V_189 = 0 ; V_189 < F_94 ( V_35 -> V_35 . V_158 ) ; V_189 ++ ) {
V_188 = F_58 ( V_56 , V_191 ) ;
if ( ! V_188 )
goto V_95;
if ( F_78 ( V_56 , V_192 , V_189 ) )
goto V_95;
V_32 = V_35 -> V_178 -> V_179 ( V_35 , V_189 , V_56 ) ;
if ( V_32 == - V_59 )
goto V_95;
if ( V_32 ) {
F_60 ( V_56 , V_188 ) ;
continue;
}
F_59 ( V_56 , V_188 ) ;
}
F_59 ( V_56 , V_187 ) ;
return 0 ;
V_95:
F_60 ( V_56 , V_187 ) ;
return - V_59 ;
}
static int F_101 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_193 ;
int V_32 ;
V_193 = F_58 ( V_56 , V_194 ) ;
if ( ! V_193 )
return - V_59 ;
V_32 = V_35 -> V_178 -> V_179 ( V_35 , V_195 , V_56 ) ;
if ( V_32 ) {
F_60 ( V_56 , V_193 ) ;
return ( V_32 == - V_59 ) ? V_32 : 0 ;
}
F_59 ( V_56 , V_193 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_56 , struct V_34 * V_35 ,
T_5 V_53 )
{
int V_32 ;
if ( ! V_35 -> V_178 -> V_179 || ! V_35 -> V_35 . V_158 ||
! ( V_53 & V_159 ) )
return 0 ;
V_32 = F_101 ( V_56 , V_35 ) ;
if ( V_32 )
return V_32 ;
if ( F_94 ( V_35 -> V_35 . V_158 ) ) {
V_32 = F_100 ( V_56 , V_35 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_103 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
int V_32 ;
struct V_196 V_197 ;
V_32 = F_104 ( V_35 , & V_197 ) ;
if ( V_32 ) {
if ( V_32 == - V_198 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_199 , V_197 . V_200 , V_197 . V_102 ) )
return - V_59 ;
return 0 ;
}
static int F_105 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
char V_94 [ V_182 ] ;
int V_32 ;
V_32 = F_106 ( V_35 , V_94 , sizeof( V_94 ) ) ;
if ( V_32 ) {
if ( V_32 == - V_198 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_201 , strlen ( V_94 ) , V_94 ) )
return - V_59 ;
return 0 ;
}
static int F_107 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
int V_32 ;
struct V_202 V_203 = {
. V_204 = V_35 ,
. V_102 = V_205 ,
. V_83 = V_206 ,
} ;
V_32 = F_108 ( V_35 , & V_203 ) ;
if ( V_32 ) {
if ( V_32 == - V_198 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_207 , V_203 . V_208 . V_197 . V_200 ,
V_203 . V_208 . V_197 . V_102 ) )
return - V_59 ;
return 0 ;
}
static T_8 int F_109 ( struct V_2 * V_56 ,
struct V_34 * V_35 )
{
struct V_132 * V_209 ;
struct V_47 * V_203 ;
V_203 = F_110 ( V_56 , V_210 ,
sizeof( struct V_132 ) , V_211 ) ;
if ( ! V_203 )
return - V_59 ;
V_209 = F_111 ( V_203 ) ;
F_112 ( V_35 , V_209 ) ;
V_203 = F_113 ( V_56 , V_212 ,
sizeof( struct V_130 ) ) ;
if ( ! V_203 )
return - V_59 ;
F_92 ( F_111 ( V_203 ) , V_209 ) ;
return 0 ;
}
static T_8 int F_114 ( struct V_2 * V_56 ,
struct V_34 * V_35 ,
int V_213 ,
struct V_47 * V_214 )
{
struct V_169 V_215 ;
struct V_47 * V_189 , * V_216 , * V_217 ;
struct V_168 V_218 ;
struct V_164 V_219 ;
struct V_165 V_220 ;
struct V_166 V_221 ;
struct V_222 V_223 ;
struct V_171 V_224 ;
struct V_162 V_225 ;
struct V_167 V_226 ;
struct V_161 V_227 ;
struct V_228 V_229 ;
V_229 . V_230 = - 1 ;
V_229 . V_231 = - 1 ;
V_229 . V_232 = - 1 ;
memset ( V_229 . V_233 , 0 , sizeof( V_229 . V_233 ) ) ;
V_229 . V_234 = 0 ;
V_229 . V_235 = F_115 ( V_236 ) ;
if ( V_35 -> V_178 -> V_237 ( V_35 , V_213 , & V_229 ) )
return 0 ;
memset ( & V_219 , 0 , sizeof( V_219 ) ) ;
V_227 . V_189 =
V_225 . V_189 =
V_219 . V_189 =
V_226 . V_189 =
V_221 . V_189 =
V_220 . V_189 =
V_218 . V_189 =
V_215 . V_189 =
V_224 . V_189 = V_229 . V_189 ;
memcpy ( V_227 . V_233 , V_229 . V_233 , sizeof( V_229 . V_233 ) ) ;
V_225 . V_238 = V_229 . V_238 ;
V_225 . V_239 = V_229 . V_239 ;
V_219 . V_238 = V_229 . V_238 ;
V_219 . V_239 = V_229 . V_239 ;
V_219 . V_235 = V_229 . V_235 ;
V_221 . V_240 = V_229 . V_241 ;
V_226 . V_242 = V_229 . V_242 ;
V_226 . V_241 = V_229 . V_241 ;
V_220 . V_243 = V_229 . V_230 ;
V_218 . V_244 = V_229 . V_234 ;
V_215 . V_243 = V_229 . V_231 ;
V_224 . V_243 = V_229 . V_232 ;
V_189 = F_58 ( V_56 , V_245 ) ;
if ( ! V_189 )
goto V_246;
if ( F_84 ( V_56 , V_247 , sizeof( V_227 ) , & V_227 ) ||
F_84 ( V_56 , V_248 , sizeof( V_225 ) , & V_225 ) ||
F_84 ( V_56 , V_249 , sizeof( V_226 ) ,
& V_226 ) ||
F_84 ( V_56 , V_250 , sizeof( V_221 ) ,
& V_221 ) ||
F_84 ( V_56 , V_251 , sizeof( V_220 ) ,
& V_220 ) ||
F_84 ( V_56 , V_252 , sizeof( V_218 ) ,
& V_218 ) ||
F_84 ( V_56 , V_253 ,
sizeof( V_215 ) ,
& V_215 ) ||
F_84 ( V_56 , V_254 ,
sizeof( V_224 ) , & V_224 ) )
goto V_255;
V_217 = F_58 ( V_56 , V_256 ) ;
if ( ! V_217 )
goto V_255;
if ( F_84 ( V_56 , V_257 , sizeof( V_219 ) ,
& V_219 ) ) {
F_60 ( V_56 , V_217 ) ;
goto V_255;
}
F_59 ( V_56 , V_217 ) ;
memset ( & V_223 , 0 , sizeof( V_223 ) ) ;
if ( V_35 -> V_178 -> V_258 )
V_35 -> V_178 -> V_258 ( V_35 , V_213 ,
& V_223 ) ;
V_216 = F_58 ( V_56 , V_259 ) ;
if ( ! V_216 )
goto V_255;
if ( F_116 ( V_56 , V_260 ,
V_223 . V_134 , V_261 ) ||
F_116 ( V_56 , V_262 ,
V_223 . V_135 , V_261 ) ||
F_116 ( V_56 , V_263 ,
V_223 . V_136 , V_261 ) ||
F_116 ( V_56 , V_264 ,
V_223 . V_137 , V_261 ) ||
F_116 ( V_56 , V_265 ,
V_223 . V_266 , V_261 ) ||
F_116 ( V_56 , V_267 ,
V_223 . V_142 , V_261 ) ) {
F_60 ( V_56 , V_216 ) ;
goto V_255;
}
F_59 ( V_56 , V_216 ) ;
F_59 ( V_56 , V_189 ) ;
return 0 ;
V_255:
F_60 ( V_56 , V_189 ) ;
V_246:
F_60 ( V_56 , V_214 ) ;
return - V_59 ;
}
static int F_117 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_184 V_268 ;
memset ( & V_268 , 0 , sizeof( V_268 ) ) ;
V_268 . V_269 = V_35 -> V_269 ;
V_268 . V_270 = V_35 -> V_270 ;
V_268 . V_271 = V_35 -> V_271 ;
V_268 . V_272 = V_35 -> V_272 ;
V_268 . V_273 = V_35 -> V_273 ;
V_268 . V_274 = V_35 -> V_275 ;
if ( F_118 ( V_56 , V_276 , sizeof( V_268 ) , & V_268 , V_211 ) )
return - V_59 ;
return 0 ;
}
static int F_119 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_277 V_278 = {} ;
struct V_47 * V_279 ;
int V_32 ;
if ( ! V_35 -> V_178 -> V_181 )
return 0 ;
V_279 = F_58 ( V_56 , V_280 ) ;
if ( ! V_279 )
return - V_59 ;
V_278 . V_281 = V_282 ;
V_32 = V_35 -> V_178 -> V_181 ( V_35 , & V_278 ) ;
if ( V_32 )
goto V_283;
V_32 = F_120 ( V_56 , V_284 , V_278 . V_285 ) ;
if ( V_32 )
goto V_283;
F_59 ( V_56 , V_279 ) ;
return 0 ;
V_283:
F_60 ( V_56 , V_279 ) ;
return V_32 ;
}
static int F_121 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_286 , T_5 V_287 ,
unsigned int V_83 , T_5 V_53 )
{
struct V_126 * V_127 ;
struct V_81 * V_82 ;
struct V_47 * V_288 ;
struct V_51 * V_54 ;
struct V_34 * V_289 = F_47 ( V_35 ) ;
F_122 () ;
V_82 = F_123 ( V_56 , V_73 , V_286 , type , sizeof( * V_127 ) , V_83 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_124 ( V_82 ) ;
V_127 -> V_290 = V_291 ;
V_127 -> V_292 = 0 ;
V_127 -> V_293 = V_35 -> type ;
V_127 -> V_294 = V_35 -> V_295 ;
V_127 -> V_128 = F_125 ( V_35 ) ;
V_127 -> V_129 = V_287 ;
if ( F_57 ( V_56 , V_296 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_297 , V_35 -> V_298 ) ||
F_120 ( V_56 , V_299 ,
F_126 ( V_35 ) ? V_35 -> V_118 : V_300 ) ||
F_120 ( V_56 , V_301 , V_35 -> V_302 ) ||
F_78 ( V_56 , V_303 , V_35 -> V_304 ) ||
F_78 ( V_56 , V_305 , V_35 -> V_74 ) ||
F_78 ( V_56 , V_306 , V_35 -> V_307 ) ||
F_78 ( V_56 , V_308 , V_35 -> V_309 ) ||
F_78 ( V_56 , V_310 , V_35 -> V_311 ) ||
F_78 ( V_56 , V_312 , V_35 -> V_313 ) ||
#ifdef F_127
F_78 ( V_56 , V_314 , V_35 -> V_315 ) ||
#endif
( V_35 -> V_295 != F_128 ( V_35 ) &&
F_78 ( V_56 , V_316 , F_128 ( V_35 ) ) ) ||
( V_289 &&
F_78 ( V_56 , V_317 , V_289 -> V_295 ) ) ||
F_120 ( V_56 , V_318 , F_129 ( V_35 ) ) ||
( V_35 -> V_319 &&
F_57 ( V_56 , V_320 , V_35 -> V_319 -> V_25 -> V_102 ) ) ||
( V_35 -> V_321 &&
F_57 ( V_56 , V_322 , V_35 -> V_321 ) ) ||
F_78 ( V_56 , V_323 ,
F_81 ( & V_35 -> V_324 ) ) ||
F_120 ( V_56 , V_325 , V_35 -> V_326 ) )
goto V_95;
if ( F_117 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_327 ) {
if ( F_84 ( V_56 , V_328 , V_35 -> V_327 , V_35 -> V_329 ) ||
F_84 ( V_56 , V_330 , V_35 -> V_327 , V_35 -> V_266 ) )
goto V_95;
}
if ( F_103 ( V_56 , V_35 ) )
goto V_95;
if ( F_105 ( V_56 , V_35 ) )
goto V_95;
if ( F_107 ( V_56 , V_35 ) )
goto V_95;
if ( F_109 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_35 . V_158 && ( V_53 & V_159 ) &&
F_78 ( V_56 , V_331 , F_94 ( V_35 -> V_35 . V_158 ) ) )
goto V_95;
if ( V_35 -> V_178 -> V_237 && V_35 -> V_35 . V_158 &&
V_53 & V_159 ) {
int V_87 ;
struct V_47 * V_214 ;
int V_160 = F_94 ( V_35 -> V_35 . V_158 ) ;
V_214 = F_58 ( V_56 , V_332 ) ;
if ( ! V_214 )
goto V_95;
for ( V_87 = 0 ; V_87 < V_160 ; V_87 ++ ) {
if ( F_114 ( V_56 , V_35 , V_87 , V_214 ) )
goto V_95;
}
F_59 ( V_56 , V_214 ) ;
}
if ( F_102 ( V_56 , V_35 , V_53 ) )
goto V_95;
if ( F_119 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_23 || F_55 ( V_35 ) ) {
if ( F_62 ( V_56 , V_35 ) < 0 )
goto V_95;
}
if ( V_35 -> V_23 &&
V_35 -> V_23 -> V_333 ) {
struct V_33 * V_334 = V_35 -> V_23 -> V_333 ( V_35 ) ;
if ( ! F_130 ( F_131 ( V_35 ) , V_334 ) ) {
int V_102 = F_132 ( F_131 ( V_35 ) , V_334 ) ;
if ( F_133 ( V_56 , V_335 , V_102 ) )
goto V_95;
}
}
if ( ! ( V_288 = F_58 ( V_56 , V_336 ) ) )
goto V_95;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_337 ) {
struct V_47 * V_338 ;
int V_32 ;
if ( ! ( V_338 = F_58 ( V_56 , V_54 -> V_52 ) ) )
goto V_95;
V_32 = V_54 -> V_337 ( V_56 , V_35 , V_53 ) ;
if ( V_32 == - V_339 )
F_60 ( V_56 , V_338 ) ;
else if ( V_32 < 0 )
goto V_95;
F_59 ( V_56 , V_338 ) ;
}
}
F_59 ( V_56 , V_288 ) ;
F_134 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_135 ( V_56 , V_82 ) ;
return - V_59 ;
}
static const struct V_23 * F_136 ( const struct V_47 * V_340 )
{
const struct V_23 * V_25 = NULL ;
struct V_47 * V_341 [ V_342 + 1 ] ;
if ( F_137 ( V_341 , V_342 , V_340 , V_343 ) < 0 )
return NULL ;
if ( V_341 [ V_64 ] ) {
char V_24 [ V_344 ] ;
F_138 ( V_24 , V_341 [ V_64 ] , sizeof( V_24 ) ) ;
V_25 = F_28 ( V_24 ) ;
}
return V_25 ;
}
static bool F_139 ( struct V_34 * V_35 , int V_345 )
{
struct V_34 * V_346 ;
if ( ! V_345 )
return false ;
V_346 = F_47 ( V_35 ) ;
if ( ! V_346 || V_346 -> V_295 != V_345 )
return true ;
return false ;
}
static bool F_140 ( const struct V_34 * V_35 ,
const struct V_23 * V_347 )
{
if ( V_347 && V_35 -> V_23 != V_347 )
return true ;
return false ;
}
static bool F_141 ( struct V_34 * V_35 ,
int V_345 ,
const struct V_23 * V_347 )
{
if ( F_139 ( V_35 , V_345 ) ||
F_140 ( V_35 , V_347 ) )
return true ;
return false ;
}
static int F_142 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
int V_351 , V_352 ;
int V_353 = 0 , V_354 ;
struct V_34 * V_35 ;
struct V_355 * V_3 ;
struct V_47 * V_356 [ V_357 + 1 ] ;
T_5 V_53 = 0 ;
const struct V_23 * V_347 = NULL ;
unsigned int V_83 = V_358 ;
int V_345 = 0 ;
int V_32 ;
int V_359 ;
V_352 = V_349 -> args [ 0 ] ;
V_354 = V_349 -> args [ 1 ] ;
V_349 -> V_286 = V_33 -> V_360 ;
V_359 = F_144 ( V_349 -> V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_361 ) : sizeof( struct V_126 ) ;
if ( F_145 ( V_349 -> V_82 , V_359 , V_356 , V_357 , V_362 ) >= 0 ) {
if ( V_356 [ V_363 ] )
V_53 = F_146 ( V_356 [ V_363 ] ) ;
if ( V_356 [ V_317 ] )
V_345 = F_146 ( V_356 [ V_317 ] ) ;
if ( V_356 [ V_70 ] )
V_347 = F_136 ( V_356 [ V_70 ] ) ;
if ( V_345 || V_347 )
V_83 |= V_364 ;
}
for ( V_351 = V_352 ; V_351 < V_365 ; V_351 ++ , V_354 = 0 ) {
V_353 = 0 ;
V_3 = & V_33 -> V_366 [ V_351 ] ;
F_147 (dev, head, index_hlist) {
if ( F_141 ( V_35 , V_345 , V_347 ) )
goto V_367;
if ( V_353 < V_354 )
goto V_367;
V_32 = F_121 ( V_56 , V_35 , V_368 ,
F_64 ( V_349 -> V_56 ) . V_369 ,
V_349 -> V_82 -> V_370 , 0 ,
V_83 ,
V_53 ) ;
F_148 ( ( V_32 == - V_59 ) && ( V_56 -> V_371 == 0 ) ) ;
if ( V_32 < 0 )
goto V_71;
F_149 ( V_349 , F_150 ( V_56 ) ) ;
V_367:
V_353 ++ ;
}
}
V_71:
V_349 -> args [ 1 ] = V_353 ;
V_349 -> args [ 0 ] = V_351 ;
return V_56 -> V_371 ;
}
int F_151 ( struct V_47 * * V_356 , const struct V_47 * V_3 , int V_371 )
{
return F_152 ( V_356 , V_357 , V_3 , V_371 , V_362 ) ;
}
struct V_33 * F_153 ( struct V_33 * V_372 , struct V_47 * V_356 [] )
{
struct V_33 * V_33 ;
if ( V_356 [ V_373 ] )
V_33 = F_154 ( F_146 ( V_356 [ V_373 ] ) ) ;
else if ( V_356 [ V_374 ] )
V_33 = F_155 ( F_146 ( V_356 [ V_374 ] ) ) ;
else
V_33 = F_156 ( V_372 ) ;
return V_33 ;
}
static int F_157 ( struct V_34 * V_35 , struct V_47 * V_356 [] )
{
if ( V_35 ) {
if ( V_356 [ V_328 ] &&
F_158 ( V_356 [ V_328 ] ) < V_35 -> V_327 )
return - V_375 ;
if ( V_356 [ V_330 ] &&
F_158 ( V_356 [ V_330 ] ) < V_35 -> V_327 )
return - V_375 ;
}
if ( V_356 [ V_336 ] ) {
struct V_47 * V_338 ;
int V_376 , V_32 ;
F_159 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_160 ( V_338 ) ) ) )
return - V_377 ;
if ( ! V_54 -> V_378 )
return - V_198 ;
if ( V_54 -> V_379 ) {
V_32 = V_54 -> V_379 ( V_35 , V_338 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
}
return 0 ;
}
static int F_161 ( struct V_34 * V_35 , struct V_380 * V_381 ,
int V_382 )
{
const struct V_383 * V_25 = V_35 -> V_178 ;
return V_25 -> V_384 ( V_35 , V_381 -> V_189 , V_381 -> V_385 , V_382 ) ;
}
static int F_162 ( struct V_34 * V_35 , struct V_380 * V_381 , int V_382 )
{
if ( V_35 -> type != V_386 )
return - V_198 ;
return F_161 ( V_35 , V_381 , V_382 ) ;
}
static int F_163 ( struct V_34 * V_35 , struct V_47 * * V_356 )
{
const struct V_383 * V_25 = V_35 -> V_178 ;
int V_32 = - V_375 ;
if ( V_356 [ V_247 ] ) {
struct V_161 * V_387 = F_111 ( V_356 [ V_247 ] ) ;
V_32 = - V_198 ;
if ( V_25 -> V_388 )
V_32 = V_25 -> V_388 ( V_35 , V_387 -> V_189 ,
V_387 -> V_233 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_248 ] ) {
struct V_162 * V_389 = F_111 ( V_356 [ V_248 ] ) ;
V_32 = - V_198 ;
if ( V_25 -> V_390 )
V_32 = V_25 -> V_390 ( V_35 , V_389 -> V_189 , V_389 -> V_238 ,
V_389 -> V_239 ,
F_115 ( V_236 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_256 ] ) {
struct V_164 * V_391 [ V_163 ] ;
struct V_47 * V_203 ;
int V_376 , V_371 = 0 ;
V_32 = - V_198 ;
if ( ! V_25 -> V_390 )
return V_32 ;
F_159 (attr, tb[IFLA_VF_VLAN_LIST], rem) {
if ( F_160 ( V_203 ) != V_257 ||
F_158 ( V_203 ) < V_392 ) {
return - V_375 ;
}
if ( V_371 >= V_163 )
return - V_198 ;
V_391 [ V_371 ] = F_111 ( V_203 ) ;
V_371 ++ ;
}
if ( V_371 == 0 )
return - V_375 ;
V_32 = V_25 -> V_390 ( V_35 , V_391 [ 0 ] -> V_189 , V_391 [ 0 ] -> V_238 ,
V_391 [ 0 ] -> V_239 , V_391 [ 0 ] -> V_235 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_250 ] ) {
struct V_166 * V_381 = F_111 ( V_356 [ V_250 ] ) ;
struct V_228 V_393 ;
V_32 = - V_198 ;
if ( V_25 -> V_237 )
V_32 = V_25 -> V_237 ( V_35 , V_381 -> V_189 , & V_393 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = - V_198 ;
if ( V_25 -> V_394 )
V_32 = V_25 -> V_394 ( V_35 , V_381 -> V_189 ,
V_393 . V_242 ,
V_381 -> V_240 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_249 ] ) {
struct V_167 * V_381 = F_111 ( V_356 [ V_249 ] ) ;
V_32 = - V_198 ;
if ( V_25 -> V_394 )
V_32 = V_25 -> V_394 ( V_35 , V_381 -> V_189 ,
V_381 -> V_242 ,
V_381 -> V_241 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_251 ] ) {
struct V_165 * V_395 = F_111 ( V_356 [ V_251 ] ) ;
V_32 = - V_198 ;
if ( V_25 -> V_396 )
V_32 = V_25 -> V_396 ( V_35 , V_395 -> V_189 ,
V_395 -> V_243 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_252 ] ) {
struct V_168 * V_397 = F_111 ( V_356 [ V_252 ] ) ;
V_32 = - V_198 ;
if ( V_25 -> V_398 )
V_32 = V_25 -> V_398 ( V_35 , V_397 -> V_189 ,
V_397 -> V_244 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_253 ] ) {
struct V_169 * V_399 ;
V_32 = - V_198 ;
V_399 = F_111 ( V_356 [ V_253 ] ) ;
if ( V_25 -> V_400 )
V_32 = V_25 -> V_400 ( V_35 , V_399 -> V_189 ,
V_399 -> V_243 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_254 ] ) {
struct V_171 * V_381 = F_111 ( V_356 [ V_254 ] ) ;
V_32 = - V_198 ;
if ( V_25 -> V_401 )
V_32 = V_25 -> V_401 ( V_35 , V_381 -> V_189 , V_381 -> V_243 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_402 ] ) {
struct V_380 * V_381 = F_111 ( V_356 [ V_402 ] ) ;
if ( ! V_25 -> V_384 )
return - V_198 ;
return F_162 ( V_35 , V_381 , V_402 ) ;
}
if ( V_356 [ V_403 ] ) {
struct V_380 * V_381 = F_111 ( V_356 [ V_403 ] ) ;
if ( ! V_25 -> V_384 )
return - V_198 ;
return F_162 ( V_35 , V_381 , V_403 ) ;
}
return V_32 ;
}
static int F_164 ( struct V_34 * V_35 , int V_295 )
{
struct V_34 * V_289 = F_47 ( V_35 ) ;
const struct V_383 * V_25 ;
int V_32 ;
if ( V_289 ) {
if ( V_289 -> V_295 == V_295 )
return 0 ;
V_25 = V_289 -> V_178 ;
if ( V_25 -> V_404 ) {
V_32 = V_25 -> V_404 ( V_289 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_198 ;
}
}
if ( V_295 ) {
V_289 = F_165 ( F_131 ( V_35 ) , V_295 ) ;
if ( ! V_289 )
return - V_375 ;
V_25 = V_289 -> V_178 ;
if ( V_25 -> V_405 ) {
V_32 = V_25 -> V_405 ( V_289 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_198 ;
}
}
return 0 ;
}
static int F_166 ( const struct V_2 * V_56 ,
struct V_34 * V_35 , struct V_126 * V_127 ,
struct V_47 * * V_356 , char * V_406 , int V_407 )
{
const struct V_383 * V_25 = V_35 -> V_178 ;
int V_32 ;
if ( V_356 [ V_373 ] || V_356 [ V_374 ] ) {
struct V_33 * V_33 = F_153 ( F_131 ( V_35 ) , V_356 ) ;
if ( F_167 ( V_33 ) ) {
V_32 = F_168 ( V_33 ) ;
goto V_408;
}
if ( ! F_169 ( V_56 , V_33 -> V_409 , V_410 ) ) {
F_170 ( V_33 ) ;
V_32 = - V_411 ;
goto V_408;
}
V_32 = F_171 ( V_35 , V_33 , V_406 ) ;
F_170 ( V_33 ) ;
if ( V_32 )
goto V_408;
V_407 |= V_412 ;
}
if ( V_356 [ V_276 ] ) {
struct V_184 * V_413 ;
struct V_414 V_415 ;
if ( ! V_25 -> V_416 ) {
V_32 = - V_198 ;
goto V_408;
}
if ( ! F_172 ( V_35 ) ) {
V_32 = - V_417 ;
goto V_408;
}
V_413 = F_111 ( V_356 [ V_276 ] ) ;
V_415 . V_269 = ( unsigned long ) V_413 -> V_269 ;
V_415 . V_270 = ( unsigned long ) V_413 -> V_270 ;
V_415 . V_271 = ( unsigned short ) V_413 -> V_271 ;
V_415 . V_272 = ( unsigned char ) V_413 -> V_272 ;
V_415 . V_273 = ( unsigned char ) V_413 -> V_273 ;
V_415 . V_274 = ( unsigned char ) V_413 -> V_274 ;
V_32 = V_25 -> V_416 ( V_35 , & V_415 ) ;
if ( V_32 < 0 )
goto V_408;
V_407 |= V_418 ;
}
if ( V_356 [ V_328 ] ) {
struct V_419 * V_420 ;
int V_371 ;
V_371 = sizeof( V_421 ) + V_35 -> V_327 ;
V_420 = F_173 ( V_371 , V_20 ) ;
if ( ! V_420 ) {
V_32 = - V_422 ;
goto V_408;
}
V_420 -> V_423 = V_35 -> type ;
memcpy ( V_420 -> V_424 , F_111 ( V_356 [ V_328 ] ) ,
V_35 -> V_327 ) ;
V_32 = F_174 ( V_35 , V_420 ) ;
F_27 ( V_420 ) ;
if ( V_32 )
goto V_408;
V_407 |= V_412 ;
}
if ( V_356 [ V_303 ] ) {
V_32 = F_175 ( V_35 , F_146 ( V_356 [ V_303 ] ) ) ;
if ( V_32 < 0 )
goto V_408;
V_407 |= V_412 ;
}
if ( V_356 [ V_305 ] ) {
F_176 ( V_35 , F_146 ( V_356 [ V_305 ] ) ) ;
V_407 |= V_418 ;
}
if ( V_127 -> V_294 > 0 && V_406 [ 0 ] ) {
V_32 = F_177 ( V_35 , V_406 ) ;
if ( V_32 < 0 )
goto V_408;
V_407 |= V_412 ;
}
if ( V_356 [ V_322 ] ) {
V_32 = F_178 ( V_35 , F_111 ( V_356 [ V_322 ] ) ,
F_158 ( V_356 [ V_322 ] ) ) ;
if ( V_32 < 0 )
goto V_408;
V_407 |= V_418 ;
}
if ( V_356 [ V_330 ] ) {
F_179 ( V_35 -> V_266 , V_356 [ V_330 ] , V_35 -> V_327 ) ;
F_180 ( V_425 , V_35 ) ;
}
if ( V_127 -> V_128 || V_127 -> V_129 ) {
V_32 = F_181 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
goto V_408;
}
if ( V_356 [ V_317 ] ) {
V_32 = F_164 ( V_35 , F_146 ( V_356 [ V_317 ] ) ) ;
if ( V_32 )
goto V_408;
V_407 |= V_412 ;
}
if ( V_356 [ V_318 ] ) {
V_32 = F_182 ( V_35 , F_183 ( V_356 [ V_318 ] ) ) ;
if ( V_32 )
goto V_408;
V_407 |= V_412 ;
}
if ( V_356 [ V_297 ] ) {
unsigned long V_426 = F_146 ( V_356 [ V_297 ] ) ;
unsigned long V_427 = V_35 -> V_298 ;
if ( V_35 -> V_298 ^ V_426 ) {
V_35 -> V_298 = V_426 ;
V_32 = F_180 (
V_428 , V_35 ) ;
V_32 = F_184 ( V_32 ) ;
if ( V_32 ) {
V_35 -> V_298 = V_427 ;
goto V_408;
}
V_407 |= V_418 ;
}
}
if ( V_356 [ V_299 ] )
F_85 ( V_35 , F_183 ( V_356 [ V_299 ] ) ) ;
if ( V_356 [ V_301 ] ) {
unsigned char V_426 = F_183 ( V_356 [ V_301 ] ) ;
F_87 ( & V_122 ) ;
if ( V_35 -> V_302 ^ V_426 )
V_407 |= V_418 ;
V_35 -> V_302 = V_426 ;
F_88 ( & V_122 ) ;
}
if ( V_356 [ V_332 ] ) {
struct V_47 * V_214 [ V_429 + 1 ] ;
struct V_47 * V_203 ;
int V_376 ;
F_159 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_160 ( V_203 ) != V_245 ||
F_158 ( V_203 ) < V_392 ) {
V_32 = - V_375 ;
goto V_408;
}
V_32 = F_137 ( V_214 , V_429 , V_203 ,
V_430 ) ;
if ( V_32 < 0 )
goto V_408;
V_32 = F_163 ( V_35 , V_214 ) ;
if ( V_32 < 0 )
goto V_408;
V_407 |= V_418 ;
}
}
V_32 = 0 ;
if ( V_356 [ V_190 ] ) {
struct V_47 * V_274 [ V_431 + 1 ] ;
struct V_47 * V_203 ;
int V_189 ;
int V_376 ;
V_32 = - V_198 ;
if ( ! V_25 -> V_432 )
goto V_408;
F_159 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_160 ( V_203 ) != V_191 ||
F_158 ( V_203 ) < V_392 ) {
V_32 = - V_375 ;
goto V_408;
}
V_32 = F_137 ( V_274 , V_431 , V_203 ,
V_433 ) ;
if ( V_32 < 0 )
goto V_408;
if ( ! V_274 [ V_192 ] ) {
V_32 = - V_198 ;
goto V_408;
}
V_189 = F_146 ( V_274 [ V_192 ] ) ;
V_32 = V_25 -> V_432 ( V_35 , V_189 , V_274 ) ;
if ( V_32 < 0 )
goto V_408;
V_407 |= V_418 ;
}
}
V_32 = 0 ;
if ( V_356 [ V_194 ] ) {
struct V_47 * V_274 [ V_431 + 1 ] ;
V_32 = F_137 ( V_274 , V_431 ,
V_356 [ V_194 ] , V_433 ) ;
if ( V_32 < 0 )
goto V_408;
V_32 = - V_198 ;
if ( V_25 -> V_432 )
V_32 = V_25 -> V_432 ( V_35 , V_195 , V_274 ) ;
if ( V_32 < 0 )
goto V_408;
V_407 |= V_418 ;
}
if ( V_356 [ V_336 ] ) {
struct V_47 * V_338 ;
int V_376 ;
F_159 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_160 ( V_338 ) ) ) )
F_185 () ;
V_32 = V_54 -> V_378 ( V_35 , V_338 ) ;
if ( V_32 < 0 )
goto V_408;
V_407 |= V_418 ;
}
}
V_32 = 0 ;
if ( V_356 [ V_325 ] ) {
V_32 = F_186 ( V_35 ,
F_183 ( V_356 [ V_325 ] ) ) ;
if ( V_32 )
goto V_408;
V_407 |= V_418 ;
}
if ( V_356 [ V_280 ] ) {
struct V_47 * V_279 [ V_434 + 1 ] ;
T_5 V_435 = 0 ;
V_32 = F_137 ( V_279 , V_434 , V_356 [ V_280 ] ,
V_436 ) ;
if ( V_32 < 0 )
goto V_408;
if ( V_279 [ V_284 ] ) {
V_32 = - V_375 ;
goto V_408;
}
if ( V_279 [ V_437 ] ) {
V_435 = F_146 ( V_279 [ V_437 ] ) ;
if ( V_435 & ~ V_438 ) {
V_32 = - V_375 ;
goto V_408;
}
}
if ( V_279 [ V_439 ] ) {
V_32 = F_187 ( V_35 ,
F_188 ( V_279 [ V_439 ] ) ,
V_435 ) ;
if ( V_32 )
goto V_408;
V_407 |= V_418 ;
}
}
V_408:
if ( V_407 & V_412 ) {
if ( V_407 & V_418 )
F_89 ( V_35 ) ;
if ( V_32 < 0 )
F_189 ( L_3 ,
V_35 -> V_94 ) ;
}
return V_32 ;
}
static int F_190 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
int V_32 ;
struct V_47 * V_356 [ V_357 + 1 ] ;
char V_406 [ V_182 ] ;
V_32 = F_145 ( V_82 , sizeof( * V_127 ) , V_356 , V_357 , V_362 ) ;
if ( V_32 < 0 )
goto V_408;
if ( V_356 [ V_296 ] )
F_138 ( V_406 , V_356 [ V_296 ] , V_182 ) ;
else
V_406 [ 0 ] = '\0' ;
V_32 = - V_375 ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_294 > 0 )
V_35 = F_165 ( V_33 , V_127 -> V_294 ) ;
else if ( V_356 [ V_296 ] )
V_35 = F_191 ( V_33 , V_406 ) ;
else
goto V_408;
if ( V_35 == NULL ) {
V_32 = - V_417 ;
goto V_408;
}
V_32 = F_157 ( V_35 , V_356 ) ;
if ( V_32 < 0 )
goto V_408;
V_32 = F_166 ( V_56 , V_35 , V_127 , V_356 , V_406 , 0 ) ;
V_408:
return V_32 ;
}
static int F_192 ( const struct V_33 * V_33 , int V_74 )
{
struct V_34 * V_35 , * V_440 ;
F_34 ( V_36 ) ;
bool V_441 = false ;
if ( ! V_74 )
return - V_411 ;
F_35 (net, dev) {
if ( V_35 -> V_74 == V_74 ) {
const struct V_23 * V_25 ;
V_441 = true ;
V_25 = V_35 -> V_23 ;
if ( ! V_25 || ! V_25 -> V_28 )
return - V_198 ;
}
}
if ( ! V_441 )
return - V_417 ;
F_193 (net, dev, aux) {
if ( V_35 -> V_74 == V_74 ) {
const struct V_23 * V_25 ;
V_25 = V_35 -> V_23 ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
}
}
F_36 ( & V_36 ) ;
return 0 ;
}
int F_194 ( struct V_34 * V_35 )
{
const struct V_23 * V_25 ;
F_34 ( V_36 ) ;
V_25 = V_35 -> V_23 ;
if ( ! V_25 || ! V_25 -> V_28 )
return - V_198 ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
F_36 ( & V_36 ) ;
return 0 ;
}
static int F_195 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_34 * V_35 ;
struct V_126 * V_127 ;
char V_406 [ V_182 ] ;
struct V_47 * V_356 [ V_357 + 1 ] ;
int V_32 ;
V_32 = F_145 ( V_82 , sizeof( * V_127 ) , V_356 , V_357 , V_362 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_356 [ V_296 ] )
F_138 ( V_406 , V_356 [ V_296 ] , V_182 ) ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_294 > 0 )
V_35 = F_165 ( V_33 , V_127 -> V_294 ) ;
else if ( V_356 [ V_296 ] )
V_35 = F_191 ( V_33 , V_406 ) ;
else if ( V_356 [ V_305 ] )
return F_192 ( V_33 , F_146 ( V_356 [ V_305 ] ) ) ;
else
return - V_375 ;
if ( ! V_35 )
return - V_417 ;
return F_194 ( V_35 ) ;
}
int F_196 ( struct V_34 * V_35 , const struct V_126 * V_127 )
{
unsigned int V_442 ;
int V_32 ;
V_442 = V_35 -> V_83 ;
if ( V_127 && ( V_127 -> V_128 || V_127 -> V_129 ) ) {
V_32 = F_197 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_35 -> V_443 = V_444 ;
F_198 ( V_35 , V_442 , ~ 0U ) ;
return 0 ;
}
struct V_34 * F_199 ( struct V_33 * V_33 ,
const char * V_406 , unsigned char V_445 ,
const struct V_23 * V_25 , struct V_47 * V_356 [] )
{
struct V_34 * V_35 ;
unsigned int V_309 = 1 ;
unsigned int V_315 = 1 ;
if ( V_356 [ V_308 ] )
V_309 = F_146 ( V_356 [ V_308 ] ) ;
else if ( V_25 -> V_446 )
V_309 = V_25 -> V_446 () ;
if ( V_356 [ V_314 ] )
V_315 = F_146 ( V_356 [ V_314 ] ) ;
else if ( V_25 -> V_447 )
V_315 = V_25 -> V_447 () ;
V_35 = F_200 ( V_25 -> V_448 , V_406 , V_445 ,
V_25 -> V_27 , V_309 , V_315 ) ;
if ( ! V_35 )
return F_201 ( - V_422 ) ;
F_202 ( V_35 , V_33 ) ;
V_35 -> V_23 = V_25 ;
V_35 -> V_443 = V_449 ;
if ( V_356 [ V_303 ] )
V_35 -> V_304 = F_146 ( V_356 [ V_303 ] ) ;
if ( V_356 [ V_328 ] ) {
memcpy ( V_35 -> V_329 , F_111 ( V_356 [ V_328 ] ) ,
F_158 ( V_356 [ V_328 ] ) ) ;
V_35 -> V_450 = V_451 ;
}
if ( V_356 [ V_330 ] )
memcpy ( V_35 -> V_266 , F_111 ( V_356 [ V_330 ] ) ,
F_158 ( V_356 [ V_330 ] ) ) ;
if ( V_356 [ V_297 ] )
V_35 -> V_298 = F_146 ( V_356 [ V_297 ] ) ;
if ( V_356 [ V_299 ] )
F_85 ( V_35 , F_183 ( V_356 [ V_299 ] ) ) ;
if ( V_356 [ V_301 ] )
V_35 -> V_302 = F_183 ( V_356 [ V_301 ] ) ;
if ( V_356 [ V_305 ] )
F_176 ( V_35 , F_146 ( V_356 [ V_305 ] ) ) ;
return V_35 ;
}
static int F_203 ( const struct V_2 * V_56 ,
struct V_33 * V_33 , int V_74 ,
struct V_126 * V_127 ,
struct V_47 * * V_356 )
{
struct V_34 * V_35 , * V_440 ;
int V_32 ;
F_193 (net, dev, aux) {
if ( V_35 -> V_74 == V_74 ) {
V_32 = F_166 ( V_56 , V_35 , V_127 , V_356 , NULL , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
return 0 ;
}
static int F_204 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
const struct V_23 * V_25 ;
const struct V_23 * V_452 = NULL ;
struct V_34 * V_35 ;
struct V_34 * V_45 = NULL ;
struct V_126 * V_127 ;
char V_24 [ V_344 ] ;
char V_406 [ V_182 ] ;
struct V_47 * V_356 [ V_357 + 1 ] ;
struct V_47 * V_69 [ V_342 + 1 ] ;
unsigned char V_445 = V_453 ;
int V_32 ;
#ifdef F_205
V_454:
#endif
V_32 = F_145 ( V_82 , sizeof( * V_127 ) , V_356 , V_357 , V_362 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_356 [ V_296 ] )
F_138 ( V_406 , V_356 [ V_296 ] , V_182 ) ;
else
V_406 [ 0 ] = '\0' ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_294 > 0 )
V_35 = F_165 ( V_33 , V_127 -> V_294 ) ;
else {
if ( V_406 [ 0 ] )
V_35 = F_191 ( V_33 , V_406 ) ;
else
V_35 = NULL ;
}
if ( V_35 ) {
V_45 = F_47 ( V_35 ) ;
if ( V_45 )
V_452 = V_45 -> V_23 ;
}
V_32 = F_157 ( V_35 , V_356 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_356 [ V_70 ] ) {
V_32 = F_137 ( V_69 , V_342 ,
V_356 [ V_70 ] , V_343 ) ;
if ( V_32 < 0 )
return V_32 ;
} else
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_69 [ V_64 ] ) {
F_138 ( V_24 , V_69 [ V_64 ] , sizeof( V_24 ) ) ;
V_25 = F_28 ( V_24 ) ;
} else {
V_24 [ 0 ] = '\0' ;
V_25 = NULL ;
}
if ( 1 ) {
struct V_47 * V_203 [ V_25 ? V_25 -> V_455 + 1 : 1 ] ;
struct V_47 * V_456 [ V_452 ? V_452 -> V_457 + 1 : 1 ] ;
struct V_47 * * V_63 = NULL ;
struct V_47 * * V_57 = NULL ;
struct V_33 * V_458 , * V_334 = NULL ;
if ( V_25 ) {
if ( V_25 -> V_455 && V_69 [ V_67 ] ) {
V_32 = F_137 ( V_203 , V_25 -> V_455 ,
V_69 [ V_67 ] ,
V_25 -> V_459 ) ;
if ( V_32 < 0 )
return V_32 ;
V_63 = V_203 ;
}
if ( V_25 -> V_460 ) {
V_32 = V_25 -> V_460 ( V_356 , V_63 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_452 ) {
if ( V_452 -> V_457 &&
V_69 [ V_61 ] ) {
V_32 = F_137 ( V_456 ,
V_452 -> V_457 ,
V_69 [ V_61 ] ,
V_452 -> V_461 ) ;
if ( V_32 < 0 )
return V_32 ;
V_57 = V_456 ;
}
if ( V_452 -> V_462 ) {
V_32 = V_452 -> V_462 ( V_356 , V_57 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_35 ) {
int V_407 = 0 ;
if ( V_82 -> V_463 & V_464 )
return - V_26 ;
if ( V_82 -> V_463 & V_465 )
return - V_198 ;
if ( V_69 [ V_67 ] ) {
if ( ! V_25 || V_25 != V_35 -> V_23 ||
! V_25 -> V_466 )
return - V_198 ;
V_32 = V_25 -> V_466 ( V_35 , V_356 , V_63 ) ;
if ( V_32 < 0 )
return V_32 ;
V_407 |= V_418 ;
}
if ( V_69 [ V_61 ] ) {
if ( ! V_452 || ! V_452 -> V_467 )
return - V_198 ;
V_32 = V_452 -> V_467 ( V_45 , V_35 ,
V_356 , V_57 ) ;
if ( V_32 < 0 )
return V_32 ;
V_407 |= V_418 ;
}
return F_166 ( V_56 , V_35 , V_127 , V_356 , V_406 , V_407 ) ;
}
if ( ! ( V_82 -> V_463 & V_468 ) ) {
if ( V_127 -> V_294 == 0 && V_356 [ V_305 ] )
return F_203 ( V_56 , V_33 ,
F_146 ( V_356 [ V_305 ] ) ,
V_127 , V_356 ) ;
return - V_417 ;
}
if ( V_356 [ V_276 ] || V_356 [ V_469 ] )
return - V_198 ;
if ( ! V_25 ) {
#ifdef F_205
if ( V_24 [ 0 ] ) {
F_4 () ;
F_206 ( L_4 , V_24 ) ;
F_1 () ;
V_25 = F_28 ( V_24 ) ;
if ( V_25 )
goto V_454;
}
#endif
return - V_198 ;
}
if ( ! V_25 -> V_27 )
return - V_198 ;
if ( ! V_406 [ 0 ] ) {
snprintf ( V_406 , V_182 , L_5 , V_25 -> V_24 ) ;
V_445 = V_470 ;
}
V_458 = F_153 ( V_33 , V_356 ) ;
if ( F_167 ( V_458 ) )
return F_168 ( V_458 ) ;
V_32 = - V_411 ;
if ( ! F_169 ( V_56 , V_458 -> V_409 , V_410 ) )
goto V_71;
if ( V_356 [ V_335 ] ) {
int V_102 = F_188 ( V_356 [ V_335 ] ) ;
V_334 = F_207 ( V_458 , V_102 ) ;
if ( ! V_334 ) {
V_32 = - V_375 ;
goto V_71;
}
V_32 = - V_411 ;
if ( ! F_169 ( V_56 , V_334 -> V_409 , V_410 ) )
goto V_71;
}
V_35 = F_199 ( V_334 ? : V_458 , V_406 ,
V_445 , V_25 , V_356 ) ;
if ( F_167 ( V_35 ) ) {
V_32 = F_168 ( V_35 ) ;
goto V_71;
}
V_35 -> V_295 = V_127 -> V_294 ;
if ( V_25 -> V_471 ) {
V_32 = V_25 -> V_471 ( V_334 ? : V_33 , V_35 , V_356 , V_63 ) ;
if ( V_32 < 0 ) {
if ( V_35 -> V_472 == V_473 )
F_208 ( V_35 ) ;
goto V_71;
}
} else {
V_32 = F_209 ( V_35 ) ;
if ( V_32 < 0 ) {
F_208 ( V_35 ) ;
goto V_71;
}
}
V_32 = F_196 ( V_35 , V_127 ) ;
if ( V_32 < 0 )
goto V_474;
if ( V_334 ) {
V_32 = F_171 ( V_35 , V_458 , V_406 ) ;
if ( V_32 < 0 )
goto V_474;
}
if ( V_356 [ V_317 ] ) {
V_32 = F_164 ( V_35 , F_146 ( V_356 [ V_317 ] ) ) ;
if ( V_32 )
goto V_474;
}
V_71:
if ( V_334 )
F_170 ( V_334 ) ;
F_170 ( V_458 ) ;
return V_32 ;
V_474:
if ( V_25 -> V_471 ) {
F_34 ( V_36 ) ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
F_36 ( & V_36 ) ;
} else {
F_210 ( V_35 ) ;
}
goto V_71;
}
}
static int F_211 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_126 * V_127 ;
char V_406 [ V_182 ] ;
struct V_47 * V_356 [ V_357 + 1 ] ;
struct V_34 * V_35 = NULL ;
struct V_2 * V_475 ;
int V_32 ;
T_5 V_53 = 0 ;
V_32 = F_145 ( V_82 , sizeof( * V_127 ) , V_356 , V_357 , V_362 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_356 [ V_296 ] )
F_138 ( V_406 , V_356 [ V_296 ] , V_182 ) ;
if ( V_356 [ V_363 ] )
V_53 = F_146 ( V_356 [ V_363 ] ) ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_294 > 0 )
V_35 = F_165 ( V_33 , V_127 -> V_294 ) ;
else if ( V_356 [ V_296 ] )
V_35 = F_191 ( V_33 , V_406 ) ;
else
return - V_375 ;
if ( V_35 == NULL )
return - V_417 ;
V_475 = F_212 ( F_98 ( V_35 , V_53 ) , V_20 ) ;
if ( V_475 == NULL )
return - V_21 ;
V_32 = F_121 ( V_475 , V_35 , V_368 , F_64 ( V_56 ) . V_369 ,
V_82 -> V_370 , 0 , 0 , V_53 ) ;
if ( V_32 < 0 ) {
F_148 ( V_32 == - V_59 ) ;
F_6 ( V_475 ) ;
} else
V_32 = F_68 ( V_475 , V_33 , F_64 ( V_56 ) . V_369 ) ;
return V_32 ;
}
static T_9 F_213 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_34 * V_35 ;
struct V_47 * V_356 [ V_357 + 1 ] ;
T_5 V_53 = 0 ;
T_9 V_476 = 0 ;
int V_359 ;
V_359 = F_144 ( V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_361 ) : sizeof( struct V_126 ) ;
if ( F_145 ( V_82 , V_359 , V_356 , V_357 , V_362 ) >= 0 ) {
if ( V_356 [ V_363 ] )
V_53 = F_146 ( V_356 [ V_363 ] ) ;
}
if ( ! V_53 )
return V_477 ;
F_29 (dev, &net->dev_base_head, dev_list) {
V_476 = F_214 ( T_9 , V_476 ,
F_98 ( V_35 ,
V_53 ) ) ;
}
return F_215 ( V_476 ) ;
}
static int F_216 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
int V_353 ;
int V_354 = V_349 -> V_52 ;
if ( V_354 == 0 )
V_354 = 1 ;
for ( V_353 = 1 ; V_353 <= V_14 ; V_353 ++ ) {
int type = V_349 -> V_82 -> V_478 - V_9 ;
if ( V_353 < V_354 || V_353 == V_479 )
continue;
if ( V_15 [ V_353 ] == NULL ||
V_15 [ V_353 ] [ type ] . V_18 == NULL )
continue;
if ( V_353 > V_354 ) {
memset ( & V_349 -> args [ 0 ] , 0 , sizeof( V_349 -> args ) ) ;
V_349 -> V_480 = 0 ;
V_349 -> V_286 = 0 ;
}
if ( V_15 [ V_353 ] [ type ] . V_18 ( V_56 , V_349 ) )
break;
}
V_349 -> V_52 = V_353 ;
return V_56 -> V_371 ;
}
struct V_2 * F_217 ( int type , struct V_34 * V_35 ,
unsigned int V_287 , T_6 V_83 )
{
struct V_33 * V_33 = F_131 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
T_4 V_481 ;
V_56 = F_212 ( ( V_481 = F_98 ( V_35 , 0 ) ) , V_83 ) ;
if ( V_56 == NULL )
goto V_408;
V_32 = F_121 ( V_56 , V_35 , type , 0 , 0 , V_287 , 0 , 0 ) ;
if ( V_32 < 0 ) {
F_148 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
goto V_408;
}
return V_56 ;
V_408:
if ( V_32 < 0 )
F_73 ( V_33 , V_482 , V_32 ) ;
return NULL ;
}
void F_218 ( struct V_2 * V_56 , struct V_34 * V_35 , T_6 V_83 )
{
struct V_33 * V_33 = F_131 ( V_35 ) ;
F_70 ( V_56 , V_33 , 0 , V_482 , NULL , V_83 ) ;
}
void F_219 ( int type , struct V_34 * V_35 , unsigned int V_287 ,
T_6 V_83 )
{
struct V_2 * V_56 ;
if ( V_35 -> V_472 != V_483 )
return;
V_56 = F_217 ( type , V_35 , V_287 , V_83 ) ;
if ( V_56 )
F_218 ( V_56 , V_35 , V_83 ) ;
}
static int F_220 ( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_10 * V_484 , T_9 V_485 , T_5 V_73 , T_5 V_286 ,
int type , unsigned int V_83 ,
int V_486 , T_9 V_487 )
{
struct V_81 * V_82 ;
struct V_488 * V_489 ;
V_82 = F_123 ( V_56 , V_73 , V_286 , type , sizeof( * V_489 ) , V_486 ) ;
if ( ! V_82 )
return - V_59 ;
V_489 = F_124 ( V_82 ) ;
V_489 -> V_490 = V_491 ;
V_489 -> V_492 = 0 ;
V_489 -> V_493 = 0 ;
V_489 -> V_494 = V_83 ;
V_489 -> V_495 = 0 ;
V_489 -> V_496 = V_35 -> V_295 ;
V_489 -> V_487 = V_487 ;
if ( F_84 ( V_56 , V_497 , V_498 , V_484 ) )
goto V_95;
if ( V_485 )
if ( F_84 ( V_56 , V_499 , sizeof( T_9 ) , & V_485 ) )
goto V_95;
F_134 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_135 ( V_56 , V_82 ) ;
return - V_59 ;
}
static inline T_4 F_221 ( void )
{
return F_99 ( sizeof( struct V_488 ) ) +
F_48 ( V_498 ) +
F_48 ( sizeof( T_9 ) ) +
0 ;
}
static void F_222 ( struct V_34 * V_35 , T_10 * V_484 , T_9 V_485 , int type ,
T_9 V_487 )
{
struct V_33 * V_33 = F_131 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
V_56 = F_212 ( F_221 () , V_500 ) ;
if ( ! V_56 )
goto V_408;
V_32 = F_220 ( V_56 , V_35 , V_484 , V_485 ,
0 , 0 , type , V_501 , 0 , V_487 ) ;
if ( V_32 < 0 ) {
F_6 ( V_56 ) ;
goto V_408;
}
F_70 ( V_56 , V_33 , 0 , V_502 , NULL , V_500 ) ;
return;
V_408:
F_73 ( V_33 , V_502 , V_32 ) ;
}
int F_223 ( struct V_488 * V_489 ,
struct V_47 * V_356 [] ,
struct V_34 * V_35 ,
const unsigned char * V_484 , T_9 V_485 ,
T_9 V_83 )
{
int V_32 = - V_375 ;
if ( V_489 -> V_487 && ! ( V_489 -> V_487 & V_503 ) ) {
F_224 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( V_485 ) {
F_224 ( L_7 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_225 ( V_484 ) || F_226 ( V_484 ) )
V_32 = F_227 ( V_35 , V_484 ) ;
else if ( F_228 ( V_484 ) )
V_32 = F_229 ( V_35 , V_484 ) ;
if ( V_32 == - V_26 && ! ( V_83 & V_464 ) )
V_32 = 0 ;
return V_32 ;
}
static int F_230 ( struct V_47 * V_504 , T_9 * V_505 )
{
T_9 V_485 = 0 ;
if ( V_504 ) {
if ( F_158 ( V_504 ) != sizeof( T_9 ) ) {
F_224 ( L_8 ) ;
return - V_375 ;
}
V_485 = F_231 ( V_504 ) ;
if ( ! V_485 || V_485 >= V_506 ) {
F_224 ( L_9 ,
V_485 ) ;
return - V_375 ;
}
}
* V_505 = V_485 ;
return 0 ;
}
static int F_232 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_488 * V_489 ;
struct V_47 * V_356 [ V_507 + 1 ] ;
struct V_34 * V_35 ;
T_10 * V_484 ;
T_9 V_485 ;
int V_32 ;
V_32 = F_145 ( V_82 , sizeof( * V_489 ) , V_356 , V_507 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_489 = F_124 ( V_82 ) ;
if ( V_489 -> V_496 == 0 ) {
F_224 ( L_10 ) ;
return - V_375 ;
}
V_35 = F_165 ( V_33 , V_489 -> V_496 ) ;
if ( V_35 == NULL ) {
F_224 ( L_11 ) ;
return - V_417 ;
}
if ( ! V_356 [ V_497 ] || F_158 ( V_356 [ V_497 ] ) != V_498 ) {
F_224 ( L_12 ) ;
return - V_375 ;
}
V_484 = F_111 ( V_356 [ V_497 ] ) ;
V_32 = F_230 ( V_356 [ V_499 ] , & V_485 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_198 ;
if ( ( ! V_489 -> V_494 || V_489 -> V_494 & V_508 ) &&
( V_35 -> V_509 & V_510 ) ) {
struct V_34 * V_511 = F_47 ( V_35 ) ;
const struct V_383 * V_25 = V_511 -> V_178 ;
V_32 = V_25 -> V_512 ( V_489 , V_356 , V_35 , V_484 , V_485 ,
V_82 -> V_463 ) ;
if ( V_32 )
goto V_71;
else
V_489 -> V_494 &= ~ V_508 ;
}
if ( ( V_489 -> V_494 & V_501 ) ) {
if ( V_35 -> V_178 -> V_512 )
V_32 = V_35 -> V_178 -> V_512 ( V_489 , V_356 , V_35 , V_484 ,
V_485 ,
V_82 -> V_463 ) ;
else
V_32 = F_223 ( V_489 , V_356 , V_35 , V_484 , V_485 ,
V_82 -> V_463 ) ;
if ( ! V_32 ) {
F_222 ( V_35 , V_484 , V_485 , V_513 ,
V_489 -> V_487 ) ;
V_489 -> V_494 &= ~ V_501 ;
}
}
V_71:
return V_32 ;
}
int F_233 ( struct V_488 * V_489 ,
struct V_47 * V_356 [] ,
struct V_34 * V_35 ,
const unsigned char * V_484 , T_9 V_485 )
{
int V_32 = - V_375 ;
if ( ! ( V_489 -> V_487 & V_503 ) ) {
F_224 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_225 ( V_484 ) || F_226 ( V_484 ) )
V_32 = F_234 ( V_35 , V_484 ) ;
else if ( F_228 ( V_484 ) )
V_32 = F_235 ( V_35 , V_484 ) ;
return V_32 ;
}
static int F_236 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_488 * V_489 ;
struct V_47 * V_356 [ V_507 + 1 ] ;
struct V_34 * V_35 ;
int V_32 = - V_375 ;
T_11 * V_484 ;
T_9 V_485 ;
if ( ! F_237 ( V_56 , V_410 ) )
return - V_411 ;
V_32 = F_145 ( V_82 , sizeof( * V_489 ) , V_356 , V_507 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_489 = F_124 ( V_82 ) ;
if ( V_489 -> V_496 == 0 ) {
F_224 ( L_13 ) ;
return - V_375 ;
}
V_35 = F_165 ( V_33 , V_489 -> V_496 ) ;
if ( V_35 == NULL ) {
F_224 ( L_14 ) ;
return - V_417 ;
}
if ( ! V_356 [ V_497 ] || F_158 ( V_356 [ V_497 ] ) != V_498 ) {
F_224 ( L_15 ) ;
return - V_375 ;
}
V_484 = F_111 ( V_356 [ V_497 ] ) ;
V_32 = F_230 ( V_356 [ V_499 ] , & V_485 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_198 ;
if ( ( ! V_489 -> V_494 || V_489 -> V_494 & V_508 ) &&
( V_35 -> V_509 & V_510 ) ) {
struct V_34 * V_511 = F_47 ( V_35 ) ;
const struct V_383 * V_25 = V_511 -> V_178 ;
if ( V_25 -> V_514 )
V_32 = V_25 -> V_514 ( V_489 , V_356 , V_35 , V_484 , V_485 ) ;
if ( V_32 )
goto V_71;
else
V_489 -> V_494 &= ~ V_508 ;
}
if ( V_489 -> V_494 & V_501 ) {
if ( V_35 -> V_178 -> V_514 )
V_32 = V_35 -> V_178 -> V_514 ( V_489 , V_356 , V_35 , V_484 ,
V_485 ) ;
else
V_32 = F_233 ( V_489 , V_356 , V_35 , V_484 , V_485 ) ;
if ( ! V_32 ) {
F_222 ( V_35 , V_484 , V_485 , V_515 ,
V_489 -> V_487 ) ;
V_489 -> V_494 &= ~ V_501 ;
}
}
V_71:
return V_32 ;
}
static int F_238 ( struct V_2 * V_56 ,
struct V_348 * V_349 ,
struct V_34 * V_35 ,
int * V_353 ,
struct V_516 * V_30 )
{
struct V_517 * V_518 ;
int V_32 ;
T_5 V_369 , V_286 ;
V_369 = F_64 ( V_349 -> V_56 ) . V_369 ;
V_286 = V_349 -> V_82 -> V_370 ;
F_29 (ha, &list->list, list) {
if ( * V_353 < V_349 -> args [ 2 ] )
goto V_519;
V_32 = F_220 ( V_56 , V_35 , V_518 -> V_484 , 0 ,
V_369 , V_286 ,
V_513 , V_501 ,
V_358 , V_503 ) ;
if ( V_32 < 0 )
return V_32 ;
V_519:
* V_353 += 1 ;
}
return 0 ;
}
int F_239 ( struct V_2 * V_56 ,
struct V_348 * V_349 ,
struct V_34 * V_35 ,
struct V_34 * V_520 ,
int * V_353 )
{
int V_32 ;
F_240 ( V_35 ) ;
V_32 = F_238 ( V_56 , V_349 , V_35 , V_353 , & V_35 -> V_521 ) ;
if ( V_32 )
goto V_71;
V_32 = F_238 ( V_56 , V_349 , V_35 , V_353 , & V_35 -> V_522 ) ;
V_71:
F_241 ( V_35 ) ;
return V_32 ;
}
static int F_242 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
struct V_34 * V_35 ;
struct V_47 * V_356 [ V_357 + 1 ] ;
struct V_34 * V_511 = NULL ;
const struct V_383 * V_25 = NULL ;
const struct V_383 * V_523 = NULL ;
struct V_126 * V_127 = F_124 ( V_349 -> V_82 ) ;
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_355 * V_3 ;
int V_524 = 0 ;
int V_525 = 0 ;
int V_351 , V_352 ;
int V_353 = 0 , V_354 ;
int V_32 = 0 ;
int V_526 = 0 ;
if ( F_145 ( V_349 -> V_82 , sizeof( struct V_126 ) , V_356 , V_357 ,
V_362 ) == 0 ) {
if ( V_356 [ V_317 ] )
V_525 = F_146 ( V_356 [ V_317 ] ) ;
}
V_524 = V_127 -> V_294 ;
if ( V_525 ) {
V_511 = F_165 ( V_33 , V_525 ) ;
if ( ! V_511 )
return - V_417 ;
V_25 = V_511 -> V_178 ;
}
V_352 = V_349 -> args [ 0 ] ;
V_354 = V_349 -> args [ 1 ] ;
for ( V_351 = V_352 ; V_351 < V_365 ; V_351 ++ , V_354 = 0 ) {
V_353 = 0 ;
V_3 = & V_33 -> V_366 [ V_351 ] ;
F_147 (dev, head, index_hlist) {
if ( V_524 && ( V_35 -> V_295 != V_524 ) )
continue;
if ( ! V_525 ) {
if ( V_35 -> V_509 & V_510 ) {
V_511 = F_47 ( V_35 ) ;
V_523 = V_511 -> V_178 ;
}
} else {
if ( V_35 != V_511 &&
! ( V_35 -> V_509 & V_510 ) )
continue;
if ( V_511 != F_47 ( V_35 ) &&
! ( V_35 -> V_509 & V_527 ) )
continue;
V_523 = V_25 ;
}
if ( V_353 < V_354 )
goto V_367;
if ( V_35 -> V_509 & V_510 ) {
if ( V_523 && V_523 -> V_528 ) {
V_32 = V_523 -> V_528 ( V_56 , V_349 ,
V_511 , V_35 ,
& V_526 ) ;
if ( V_32 == - V_59 )
goto V_71;
}
}
if ( V_35 -> V_178 -> V_528 )
V_32 = V_35 -> V_178 -> V_528 ( V_56 , V_349 ,
V_35 , NULL ,
& V_526 ) ;
else
V_32 = F_239 ( V_56 , V_349 , V_35 , NULL ,
& V_526 ) ;
if ( V_32 == - V_59 )
goto V_71;
V_523 = NULL ;
V_349 -> args [ 2 ] = 0 ;
V_526 = 0 ;
V_367:
V_353 ++ ;
}
}
V_71:
V_349 -> args [ 0 ] = V_351 ;
V_349 -> args [ 1 ] = V_353 ;
V_349 -> args [ 2 ] = V_526 ;
return V_56 -> V_371 ;
}
static int F_243 ( struct V_2 * V_56 , T_5 V_83 , T_5 V_529 ,
unsigned int V_530 , unsigned int V_531 )
{
if ( V_529 & V_531 )
return F_120 ( V_56 , V_530 , ! ! ( V_83 & V_531 ) ) ;
return 0 ;
}
int F_244 ( struct V_2 * V_56 , T_5 V_73 , T_5 V_286 ,
struct V_34 * V_35 , T_9 V_532 ,
T_5 V_83 , T_5 V_529 , int V_486 ,
T_5 V_533 ,
int (* F_245)( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_5 V_533 ) )
{
struct V_81 * V_82 ;
struct V_126 * V_127 ;
struct V_47 * V_534 ;
struct V_47 * V_535 ;
T_10 V_118 = F_126 ( V_35 ) ? V_35 -> V_118 : V_300 ;
struct V_34 * V_511 = F_47 ( V_35 ) ;
int V_32 = 0 ;
V_82 = F_123 ( V_56 , V_73 , V_286 , V_368 , sizeof( * V_127 ) , V_486 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_124 ( V_82 ) ;
V_127 -> V_290 = V_491 ;
V_127 -> V_292 = 0 ;
V_127 -> V_293 = V_35 -> type ;
V_127 -> V_294 = V_35 -> V_295 ;
V_127 -> V_128 = F_125 ( V_35 ) ;
V_127 -> V_129 = 0 ;
if ( F_57 ( V_56 , V_296 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_303 , V_35 -> V_304 ) ||
F_120 ( V_56 , V_299 , V_118 ) ||
( V_511 &&
F_78 ( V_56 , V_317 , V_511 -> V_295 ) ) ||
( V_35 -> V_327 &&
F_84 ( V_56 , V_328 , V_35 -> V_327 , V_35 -> V_329 ) ) ||
( V_35 -> V_295 != F_128 ( V_35 ) &&
F_78 ( V_56 , V_316 , F_128 ( V_35 ) ) ) )
goto V_95;
V_534 = F_58 ( V_56 , V_336 ) ;
if ( ! V_534 )
goto V_95;
if ( F_246 ( V_56 , V_536 , V_537 ) ) {
F_60 ( V_56 , V_534 ) ;
goto V_95;
}
if ( V_532 != V_538 ) {
if ( F_246 ( V_56 , V_539 , V_532 ) ) {
F_60 ( V_56 , V_534 ) ;
goto V_95;
}
}
if ( F_245 ) {
V_32 = F_245 ( V_56 , V_35 , V_533 ) ;
if ( V_32 ) {
F_60 ( V_56 , V_534 ) ;
goto V_95;
}
}
F_59 ( V_56 , V_534 ) ;
V_535 = F_58 ( V_56 , V_469 | V_540 ) ;
if ( ! V_535 )
goto V_95;
if ( F_243 ( V_56 , V_83 , V_529 ,
V_541 , V_542 ) ||
F_243 ( V_56 , V_83 , V_529 ,
V_543 , V_544 ) ||
F_243 ( V_56 , V_83 , V_529 ,
V_545 ,
V_546 ) ||
F_243 ( V_56 , V_83 , V_529 ,
V_547 , V_548 ) ||
F_243 ( V_56 , V_83 , V_529 ,
V_549 , V_550 ) ||
F_243 ( V_56 , V_83 , V_529 ,
V_551 , V_552 ) ||
F_243 ( V_56 , V_83 , V_529 ,
V_553 , V_554 ) ||
F_243 ( V_56 , V_83 , V_529 ,
V_555 , V_556 ) ) {
F_60 ( V_56 , V_535 ) ;
goto V_95;
}
F_59 ( V_56 , V_535 ) ;
F_134 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_135 ( V_56 , V_82 ) ;
return V_32 ? V_32 : - V_59 ;
}
static int F_247 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_34 * V_35 ;
int V_353 = 0 ;
T_5 V_369 = F_64 ( V_349 -> V_56 ) . V_369 ;
T_5 V_286 = V_349 -> V_82 -> V_370 ;
T_5 V_533 = 0 ;
int V_32 ;
if ( F_144 ( V_349 -> V_82 ) > sizeof( struct V_126 ) ) {
struct V_47 * V_557 ;
V_557 = F_248 ( V_349 -> V_82 , sizeof( struct V_126 ) ,
V_363 ) ;
if ( V_557 ) {
if ( F_158 ( V_557 ) < sizeof( V_533 ) )
return - V_375 ;
V_533 = F_146 ( V_557 ) ;
}
}
F_249 () ;
F_250 (net, dev) {
const struct V_383 * V_25 = V_35 -> V_178 ;
struct V_34 * V_511 = F_47 ( V_35 ) ;
if ( V_511 && V_511 -> V_178 -> V_558 ) {
if ( V_353 >= V_349 -> args [ 0 ] ) {
V_32 = V_511 -> V_178 -> V_558 (
V_56 , V_369 , V_286 , V_35 ,
V_533 , V_358 ) ;
if ( V_32 < 0 && V_32 != - V_198 )
break;
}
V_353 ++ ;
}
if ( V_25 -> V_558 ) {
if ( V_353 >= V_349 -> args [ 0 ] ) {
V_32 = V_25 -> V_558 ( V_56 , V_369 ,
V_286 , V_35 ,
V_533 ,
V_358 ) ;
if ( V_32 < 0 && V_32 != - V_198 )
break;
}
V_353 ++ ;
}
}
F_251 () ;
V_349 -> args [ 0 ] = V_353 ;
return V_56 -> V_371 ;
}
static inline T_4 F_252 ( void )
{
return F_99 ( sizeof( struct V_126 ) )
+ F_48 ( V_182 )
+ F_48 ( V_185 )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_10 ) )
+ F_48 ( sizeof( struct V_47 ) )
+ F_48 ( sizeof( T_9 ) )
+ F_48 ( sizeof( T_9 ) ) ;
}
static int F_253 ( struct V_34 * V_35 )
{
struct V_33 * V_33 = F_131 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_198 ;
if ( ! V_35 -> V_178 -> V_558 )
return 0 ;
V_56 = F_212 ( F_252 () , V_500 ) ;
if ( ! V_56 ) {
V_32 = - V_422 ;
goto V_408;
}
V_32 = V_35 -> V_178 -> V_558 ( V_56 , 0 , 0 , V_35 , 0 , 0 ) ;
if ( V_32 < 0 )
goto V_408;
if ( ! V_56 -> V_371 )
goto V_408;
F_70 ( V_56 , V_33 , 0 , V_482 , NULL , V_500 ) ;
return 0 ;
V_408:
F_148 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
if ( V_32 )
F_73 ( V_33 , V_482 , V_32 ) ;
return V_32 ;
}
static int F_254 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_559 , * V_203 = NULL ;
int V_376 , V_32 = - V_198 ;
T_9 V_83 = 0 ;
bool V_560 = false ;
if ( F_144 ( V_82 ) < sizeof( * V_127 ) )
return - V_375 ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_290 != V_491 )
return - V_561 ;
V_35 = F_165 ( V_33 , V_127 -> V_294 ) ;
if ( ! V_35 ) {
F_224 ( L_16 ) ;
return - V_417 ;
}
V_559 = F_248 ( V_82 , sizeof( struct V_126 ) , V_336 ) ;
if ( V_559 ) {
F_159 (attr, br_spec, rem) {
if ( F_160 ( V_203 ) == V_536 ) {
if ( F_158 ( V_203 ) < sizeof( V_83 ) )
return - V_375 ;
V_560 = true ;
V_83 = F_231 ( V_203 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_562 ) ) {
struct V_34 * V_511 = F_47 ( V_35 ) ;
if ( ! V_511 || ! V_511 -> V_178 -> V_563 ) {
V_32 = - V_198 ;
goto V_71;
}
V_32 = V_511 -> V_178 -> V_563 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_562 ;
}
if ( ( V_83 & V_537 ) ) {
if ( ! V_35 -> V_178 -> V_563 )
V_32 = - V_198 ;
else
V_32 = V_35 -> V_178 -> V_563 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_537 ;
V_32 = F_253 ( V_35 ) ;
}
}
if ( V_560 )
memcpy ( F_111 ( V_203 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static int F_255 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_559 , * V_203 = NULL ;
int V_376 , V_32 = - V_198 ;
T_9 V_83 = 0 ;
bool V_560 = false ;
if ( F_144 ( V_82 ) < sizeof( * V_127 ) )
return - V_375 ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_290 != V_491 )
return - V_561 ;
V_35 = F_165 ( V_33 , V_127 -> V_294 ) ;
if ( ! V_35 ) {
F_224 ( L_16 ) ;
return - V_417 ;
}
V_559 = F_248 ( V_82 , sizeof( struct V_126 ) , V_336 ) ;
if ( V_559 ) {
F_159 (attr, br_spec, rem) {
if ( F_160 ( V_203 ) == V_536 ) {
if ( F_158 ( V_203 ) < sizeof( V_83 ) )
return - V_375 ;
V_560 = true ;
V_83 = F_231 ( V_203 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_562 ) ) {
struct V_34 * V_511 = F_47 ( V_35 ) ;
if ( ! V_511 || ! V_511 -> V_178 -> V_564 ) {
V_32 = - V_198 ;
goto V_71;
}
V_32 = V_511 -> V_178 -> V_564 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_562 ;
}
if ( ( V_83 & V_537 ) ) {
if ( ! V_35 -> V_178 -> V_564 )
V_32 = - V_198 ;
else
V_32 = V_35 -> V_178 -> V_564 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_537 ;
V_32 = F_253 ( V_35 ) ;
}
}
if ( V_560 )
memcpy ( F_111 ( V_203 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static bool F_256 ( unsigned int V_529 , int V_565 , int V_566 )
{
return ( V_529 & F_257 ( V_565 ) ) &&
( ! V_566 || V_566 == V_565 ) ;
}
static int F_258 ( int V_567 )
{
switch ( V_567 ) {
case V_568 :
return sizeof( struct V_132 ) ;
}
return 0 ;
}
static int F_259 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int * V_569 )
{
struct V_47 * V_203 = NULL ;
int V_567 , V_48 ;
void * V_570 ;
int V_32 ;
if ( ! ( V_35 -> V_178 && V_35 -> V_178 -> V_571 &&
V_35 -> V_178 -> V_572 ) )
return - V_339 ;
for ( V_567 = V_573 ;
V_567 <= V_574 ; V_567 ++ ) {
if ( V_567 < * V_569 )
continue;
V_48 = F_258 ( V_567 ) ;
if ( ! V_48 )
continue;
if ( ! V_35 -> V_178 -> V_571 ( V_35 , V_567 ) )
continue;
V_203 = F_110 ( V_56 , V_567 , V_48 ,
V_575 ) ;
if ( ! V_203 )
goto V_95;
V_570 = F_111 ( V_203 ) ;
memset ( V_570 , 0 , V_48 ) ;
V_32 = V_35 -> V_178 -> V_572 ( V_567 , V_35 ,
V_570 ) ;
if ( V_32 )
goto V_576;
}
if ( ! V_203 )
return - V_339 ;
* V_569 = 0 ;
return 0 ;
V_95:
V_32 = - V_59 ;
V_576:
* V_569 = V_567 ;
return V_32 ;
}
static int F_260 ( const struct V_34 * V_35 )
{
int V_577 = 0 ;
int V_567 ;
int V_48 ;
if ( ! ( V_35 -> V_178 && V_35 -> V_178 -> V_571 &&
V_35 -> V_178 -> V_572 ) )
return 0 ;
for ( V_567 = V_573 ;
V_567 <= V_574 ; V_567 ++ ) {
if ( ! V_35 -> V_178 -> V_571 ( V_35 , V_567 ) )
continue;
V_48 = F_258 ( V_567 ) ;
V_577 += F_95 ( V_48 ) ;
}
if ( V_577 != 0 )
V_577 += F_48 ( 0 ) ;
return V_577 ;
}
static int F_261 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_286 , T_5 V_287 ,
unsigned int V_83 , unsigned int V_533 ,
int * V_566 , int * V_569 )
{
struct V_578 * V_579 ;
struct V_81 * V_82 ;
struct V_47 * V_203 ;
int V_580 = * V_569 ;
int V_32 ;
F_122 () ;
V_82 = F_123 ( V_56 , V_73 , V_286 , type , sizeof( * V_579 ) , V_83 ) ;
if ( ! V_82 )
return - V_59 ;
V_579 = F_124 ( V_82 ) ;
V_579 -> V_295 = V_35 -> V_295 ;
V_579 -> V_533 = V_533 ;
if ( F_256 ( V_533 , V_581 , * V_566 ) ) {
struct V_132 * V_209 ;
V_203 = F_110 ( V_56 , V_581 ,
sizeof( struct V_132 ) ,
V_582 ) ;
if ( ! V_203 )
goto V_95;
V_209 = F_111 ( V_203 ) ;
F_112 ( V_35 , V_209 ) ;
}
if ( F_256 ( V_533 , V_583 , * V_566 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
if ( V_25 && V_25 -> V_584 ) {
* V_566 = V_583 ;
V_203 = F_58 ( V_56 ,
V_583 ) ;
if ( ! V_203 )
goto V_95;
V_32 = V_25 -> V_584 ( V_56 , V_35 , V_569 , * V_566 ) ;
F_59 ( V_56 , V_203 ) ;
if ( V_32 )
goto V_95;
* V_566 = 0 ;
}
}
if ( F_256 ( V_533 , V_585 ,
* V_566 ) ) {
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_346 ;
V_346 = F_47 ( V_35 ) ;
if ( V_346 )
V_25 = V_346 -> V_23 ;
if ( V_25 && V_25 -> V_584 ) {
* V_566 = V_585 ;
V_203 = F_58 ( V_56 ,
V_585 ) ;
if ( ! V_203 )
goto V_95;
V_32 = V_25 -> V_584 ( V_56 , V_35 , V_569 , * V_566 ) ;
F_59 ( V_56 , V_203 ) ;
if ( V_32 )
goto V_95;
* V_566 = 0 ;
}
}
if ( F_256 ( V_533 , V_586 ,
* V_566 ) ) {
* V_566 = V_586 ;
V_203 = F_58 ( V_56 , V_586 ) ;
if ( ! V_203 )
goto V_95;
V_32 = F_259 ( V_56 , V_35 , V_569 ) ;
if ( V_32 == - V_339 )
F_60 ( V_56 , V_203 ) ;
else
F_59 ( V_56 , V_203 ) ;
if ( V_32 && V_32 != - V_339 )
goto V_95;
* V_566 = 0 ;
}
if ( F_256 ( V_533 , V_587 , * V_566 ) ) {
struct V_51 * V_54 ;
* V_566 = V_587 ;
V_203 = F_58 ( V_56 , V_587 ) ;
if ( ! V_203 )
goto V_95;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_588 ) {
struct V_47 * V_338 ;
int V_32 ;
V_338 = F_58 ( V_56 , V_54 -> V_52 ) ;
if ( ! V_338 )
goto V_95;
V_32 = V_54 -> V_588 ( V_56 , V_35 ) ;
if ( V_32 == - V_339 )
F_60 ( V_56 , V_338 ) ;
else if ( V_32 < 0 )
goto V_95;
F_59 ( V_56 , V_338 ) ;
}
}
F_59 ( V_56 , V_203 ) ;
* V_566 = 0 ;
}
F_134 ( V_56 , V_82 ) ;
return 0 ;
V_95:
if ( ! ( V_83 & V_358 ) || V_580 == * V_569 )
F_135 ( V_56 , V_82 ) ;
else
F_134 ( V_56 , V_82 ) ;
return - V_59 ;
}
static T_4 F_262 ( const struct V_34 * V_35 ,
T_5 V_533 )
{
T_4 V_48 = 0 ;
if ( F_256 ( V_533 , V_581 , 0 ) )
V_48 += F_95 ( sizeof( struct V_132 ) ) ;
if ( F_256 ( V_533 , V_583 , 0 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
int V_203 = V_583 ;
if ( V_25 && V_25 -> V_589 ) {
V_48 += F_48 ( V_25 -> V_589 ( V_35 ,
V_203 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
if ( F_256 ( V_533 , V_585 , 0 ) ) {
struct V_34 * V_590 = (struct V_34 * ) V_35 ;
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_346 ;
V_346 = F_47 ( V_590 ) ;
if ( V_346 )
V_25 = V_346 -> V_23 ;
if ( V_25 && V_25 -> V_589 ) {
int V_203 = V_585 ;
V_48 += F_48 ( V_25 -> V_589 ( V_35 ,
V_203 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
if ( F_256 ( V_533 , V_586 , 0 ) )
V_48 += F_260 ( V_35 ) ;
if ( F_256 ( V_533 , V_587 , 0 ) ) {
struct V_51 * V_54 ;
V_48 += F_48 ( 0 ) ;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_591 ) {
V_48 += F_48 (
V_54 -> V_591 ( V_35 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
}
return V_48 ;
}
static int F_263 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
struct V_34 * V_35 = NULL ;
int V_566 = 0 , V_569 = 0 ;
struct V_578 * V_579 ;
struct V_2 * V_475 ;
T_5 V_533 ;
int V_32 ;
if ( F_144 ( V_82 ) < sizeof( * V_579 ) )
return - V_375 ;
V_579 = F_124 ( V_82 ) ;
if ( V_579 -> V_295 > 0 )
V_35 = F_165 ( V_33 , V_579 -> V_295 ) ;
else
return - V_375 ;
if ( ! V_35 )
return - V_417 ;
V_533 = V_579 -> V_533 ;
if ( ! V_533 )
return - V_375 ;
V_475 = F_212 ( F_262 ( V_35 , V_533 ) , V_20 ) ;
if ( ! V_475 )
return - V_21 ;
V_32 = F_261 ( V_475 , V_35 , V_592 ,
F_64 ( V_56 ) . V_369 , V_82 -> V_370 , 0 ,
0 , V_533 , & V_566 , & V_569 ) ;
if ( V_32 < 0 ) {
F_148 ( V_32 == - V_59 ) ;
F_6 ( V_475 ) ;
} else {
V_32 = F_68 ( V_475 , V_33 , F_64 ( V_56 ) . V_369 ) ;
}
return V_32 ;
}
static int F_264 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
int V_351 , V_352 , V_32 , V_354 , V_593 , V_580 ;
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
unsigned int V_83 = V_358 ;
struct V_578 * V_579 ;
struct V_355 * V_3 ;
struct V_34 * V_35 ;
T_5 V_533 = 0 ;
int V_353 = 0 ;
V_352 = V_349 -> args [ 0 ] ;
V_354 = V_349 -> args [ 1 ] ;
V_593 = V_349 -> args [ 2 ] ;
V_580 = V_349 -> args [ 3 ] ;
V_349 -> V_286 = V_33 -> V_360 ;
if ( F_144 ( V_349 -> V_82 ) < sizeof( * V_579 ) )
return - V_375 ;
V_579 = F_124 ( V_349 -> V_82 ) ;
V_533 = V_579 -> V_533 ;
if ( ! V_533 )
return - V_375 ;
for ( V_351 = V_352 ; V_351 < V_365 ; V_351 ++ , V_354 = 0 ) {
V_353 = 0 ;
V_3 = & V_33 -> V_366 [ V_351 ] ;
F_147 (dev, head, index_hlist) {
if ( V_353 < V_354 )
goto V_367;
V_32 = F_261 ( V_56 , V_35 , V_592 ,
F_64 ( V_349 -> V_56 ) . V_369 ,
V_349 -> V_82 -> V_370 , 0 ,
V_83 , V_533 ,
& V_593 , & V_580 ) ;
F_148 ( ( V_32 == - V_59 ) && ( V_56 -> V_371 == 0 ) ) ;
if ( V_32 < 0 )
goto V_71;
V_580 = 0 ;
V_593 = 0 ;
F_149 ( V_349 , F_150 ( V_56 ) ) ;
V_367:
V_353 ++ ;
}
}
V_71:
V_349 -> args [ 3 ] = V_580 ;
V_349 -> args [ 2 ] = V_593 ;
V_349 -> args [ 1 ] = V_353 ;
V_349 -> args [ 0 ] = V_351 ;
return V_56 -> V_371 ;
}
static int F_265 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_350 ) ;
T_1 V_16 ;
int V_24 ;
int V_52 ;
int type ;
int V_32 ;
type = V_82 -> V_478 ;
if ( type > V_594 )
return - V_198 ;
type -= V_9 ;
if ( F_144 ( V_82 ) < sizeof( struct V_361 ) )
return 0 ;
V_52 = ( (struct V_361 * ) F_124 ( V_82 ) ) -> V_595 ;
V_24 = type & 3 ;
if ( V_24 != 2 && ! F_266 ( V_56 , V_410 ) )
return - V_411 ;
if ( V_24 == 2 && V_82 -> V_463 & V_596 ) {
struct V_76 * V_77 ;
T_2 V_18 ;
T_3 V_19 ;
T_9 V_597 = 0 ;
V_18 = F_19 ( V_52 , type ) ;
if ( V_18 == NULL )
return - V_198 ;
V_19 = F_20 ( V_52 , type ) ;
if ( V_19 )
V_597 = V_19 ( V_56 , V_82 ) ;
F_4 () ;
V_77 = V_33 -> V_77 ;
{
struct V_598 V_599 = {
. V_600 = V_18 ,
. V_597 = V_597 ,
} ;
V_32 = F_267 ( V_77 , V_56 , V_82 , & V_599 ) ;
}
F_1 () ;
return V_32 ;
}
V_16 = F_18 ( V_52 , type ) ;
if ( V_16 == NULL )
return - V_198 ;
return V_16 ( V_56 , V_82 ) ;
}
static void F_268 ( struct V_2 * V_56 )
{
F_1 () ;
F_269 ( V_56 , & F_265 ) ;
F_8 () ;
}
static int F_270 ( struct V_601 * V_602 , unsigned long V_603 , void * V_604 )
{
struct V_34 * V_35 = F_271 ( V_604 ) ;
switch ( V_603 ) {
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
case V_616 :
case V_617 :
break;
default:
F_219 ( V_368 , V_35 , 0 , V_20 ) ;
break;
}
return V_618 ;
}
static int T_12 F_272 ( struct V_33 * V_33 )
{
struct V_76 * V_350 ;
struct V_619 V_620 = {
. V_621 = V_622 ,
. V_623 = F_268 ,
. V_624 = & V_1 ,
. V_83 = V_625 ,
} ;
V_350 = F_273 ( V_33 , V_626 , & V_620 ) ;
if ( ! V_350 )
return - V_422 ;
V_33 -> V_77 = V_350 ;
return 0 ;
}
static void T_13 F_274 ( struct V_33 * V_33 )
{
F_275 ( V_33 -> V_77 ) ;
V_33 -> V_77 = NULL ;
}
void T_14 F_276 ( void )
{
if ( F_277 ( & V_627 ) )
F_24 ( L_17 ) ;
F_278 ( & V_628 ) ;
F_23 ( V_17 , V_629 , F_211 ,
F_142 , F_213 ) ;
F_23 ( V_17 , V_630 , F_190 , NULL , NULL ) ;
F_23 ( V_17 , V_368 , F_204 , NULL , NULL ) ;
F_23 ( V_17 , V_631 , F_195 , NULL , NULL ) ;
F_23 ( V_17 , V_632 , NULL , F_216 , NULL ) ;
F_23 ( V_17 , V_633 , NULL , F_216 , NULL ) ;
F_23 ( V_634 , V_513 , F_232 , NULL , NULL ) ;
F_23 ( V_634 , V_515 , F_236 , NULL , NULL ) ;
F_23 ( V_634 , V_635 , NULL , F_242 , NULL ) ;
F_23 ( V_634 , V_629 , NULL , F_247 , NULL ) ;
F_23 ( V_634 , V_631 , F_255 , NULL , NULL ) ;
F_23 ( V_634 , V_630 , F_254 , NULL , NULL ) ;
F_23 ( V_17 , V_636 , F_263 , F_264 ,
NULL ) ;
}
