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
static T_4 F_97 ( void )
{
T_4 V_180 = F_48 ( 0 ) +
F_48 ( 1 ) +
F_48 ( 4 ) ;
return V_180 ;
}
static T_7 T_4 F_98 ( const struct V_34 * V_35 ,
T_5 V_53 )
{
return F_99 ( sizeof( struct V_126 ) )
+ F_48 ( V_181 )
+ F_48 ( V_182 )
+ F_48 ( V_181 )
+ F_95 ( sizeof( struct V_183 ) )
+ F_48 ( sizeof( struct V_130 ) )
+ F_95 ( sizeof( struct V_132 ) )
+ F_48 ( V_184 )
+ F_48 ( V_184 )
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
+ F_48 ( 4 )
+ F_48 ( V_53
& V_159 ? 4 : 0 )
+ F_93 ( V_35 , V_53 )
+ F_96 ( V_35 , V_53 )
+ F_49 ( V_35 )
+ F_54 ( V_35 , V_53 )
+ F_48 ( V_185 )
+ F_48 ( V_185 )
+ F_48 ( V_181 )
+ F_97 ()
+ F_48 ( 4 )
+ F_48 ( 1 ) ;
}
static int F_100 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_186 ;
struct V_47 * V_187 ;
int V_188 ;
int V_32 ;
V_186 = F_58 ( V_56 , V_189 ) ;
if ( ! V_186 )
return - V_59 ;
for ( V_188 = 0 ; V_188 < F_94 ( V_35 -> V_35 . V_158 ) ; V_188 ++ ) {
V_187 = F_58 ( V_56 , V_190 ) ;
if ( ! V_187 )
goto V_95;
if ( F_78 ( V_56 , V_191 , V_188 ) )
goto V_95;
V_32 = V_35 -> V_178 -> V_179 ( V_35 , V_188 , V_56 ) ;
if ( V_32 == - V_59 )
goto V_95;
if ( V_32 ) {
F_60 ( V_56 , V_187 ) ;
continue;
}
F_59 ( V_56 , V_187 ) ;
}
F_59 ( V_56 , V_186 ) ;
return 0 ;
V_95:
F_60 ( V_56 , V_186 ) ;
return - V_59 ;
}
static int F_101 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_192 ;
int V_32 ;
V_192 = F_58 ( V_56 , V_193 ) ;
if ( ! V_192 )
return - V_59 ;
V_32 = V_35 -> V_178 -> V_179 ( V_35 , V_194 , V_56 ) ;
if ( V_32 ) {
F_60 ( V_56 , V_192 ) ;
return ( V_32 == - V_59 ) ? V_32 : 0 ;
}
F_59 ( V_56 , V_192 ) ;
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
struct V_195 V_196 ;
V_32 = F_104 ( V_35 , & V_196 ) ;
if ( V_32 ) {
if ( V_32 == - V_197 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_198 , V_196 . V_199 , V_196 . V_102 ) )
return - V_59 ;
return 0 ;
}
static int F_105 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
char V_94 [ V_181 ] ;
int V_32 ;
V_32 = F_106 ( V_35 , V_94 , sizeof( V_94 ) ) ;
if ( V_32 ) {
if ( V_32 == - V_197 )
return 0 ;
return V_32 ;
}
if ( F_57 ( V_56 , V_200 , V_94 ) )
return - V_59 ;
return 0 ;
}
static int F_107 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
int V_32 ;
struct V_201 V_202 = {
. V_203 = V_35 ,
. V_102 = V_204 ,
. V_83 = V_205 ,
} ;
V_32 = F_108 ( V_35 , & V_202 ) ;
if ( V_32 ) {
if ( V_32 == - V_197 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_206 , V_202 . V_207 . V_196 . V_199 ,
V_202 . V_207 . V_196 . V_102 ) )
return - V_59 ;
return 0 ;
}
static T_8 int F_109 ( struct V_2 * V_56 ,
struct V_34 * V_35 )
{
struct V_132 * V_208 ;
struct V_47 * V_202 ;
V_202 = F_110 ( V_56 , V_209 ,
sizeof( struct V_132 ) , V_210 ) ;
if ( ! V_202 )
return - V_59 ;
V_208 = F_111 ( V_202 ) ;
F_112 ( V_35 , V_208 ) ;
V_202 = F_113 ( V_56 , V_211 ,
sizeof( struct V_130 ) ) ;
if ( ! V_202 )
return - V_59 ;
F_92 ( F_111 ( V_202 ) , V_208 ) ;
return 0 ;
}
static T_8 int F_114 ( struct V_2 * V_56 ,
struct V_34 * V_35 ,
int V_212 ,
struct V_47 * V_213 )
{
struct V_169 V_214 ;
struct V_47 * V_188 , * V_215 , * V_216 ;
struct V_168 V_217 ;
struct V_164 V_218 ;
struct V_165 V_219 ;
struct V_166 V_220 ;
struct V_221 V_222 ;
struct V_171 V_223 ;
struct V_162 V_224 ;
struct V_167 V_225 ;
struct V_161 V_226 ;
struct V_227 V_228 ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . V_229 = - 1 ;
V_228 . V_230 = - 1 ;
V_228 . V_231 = - 1 ;
V_228 . V_232 = 0 ;
V_228 . V_233 = F_115 ( V_234 ) ;
if ( V_35 -> V_178 -> V_235 ( V_35 , V_212 , & V_228 ) )
return 0 ;
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
V_226 . V_188 =
V_224 . V_188 =
V_218 . V_188 =
V_225 . V_188 =
V_220 . V_188 =
V_219 . V_188 =
V_217 . V_188 =
V_214 . V_188 =
V_223 . V_188 = V_228 . V_188 ;
memcpy ( V_226 . V_236 , V_228 . V_236 , sizeof( V_228 . V_236 ) ) ;
V_224 . V_237 = V_228 . V_237 ;
V_224 . V_238 = V_228 . V_238 ;
V_218 . V_237 = V_228 . V_237 ;
V_218 . V_238 = V_228 . V_238 ;
V_218 . V_233 = V_228 . V_233 ;
V_220 . V_239 = V_228 . V_240 ;
V_225 . V_241 = V_228 . V_241 ;
V_225 . V_240 = V_228 . V_240 ;
V_219 . V_242 = V_228 . V_229 ;
V_217 . V_243 = V_228 . V_232 ;
V_214 . V_242 = V_228 . V_230 ;
V_223 . V_242 = V_228 . V_231 ;
V_188 = F_58 ( V_56 , V_244 ) ;
if ( ! V_188 )
goto V_245;
if ( F_84 ( V_56 , V_246 , sizeof( V_226 ) , & V_226 ) ||
F_84 ( V_56 , V_247 , sizeof( V_224 ) , & V_224 ) ||
F_84 ( V_56 , V_248 , sizeof( V_225 ) ,
& V_225 ) ||
F_84 ( V_56 , V_249 , sizeof( V_220 ) ,
& V_220 ) ||
F_84 ( V_56 , V_250 , sizeof( V_219 ) ,
& V_219 ) ||
F_84 ( V_56 , V_251 , sizeof( V_217 ) ,
& V_217 ) ||
F_84 ( V_56 , V_252 ,
sizeof( V_214 ) ,
& V_214 ) ||
F_84 ( V_56 , V_253 ,
sizeof( V_223 ) , & V_223 ) )
goto V_254;
V_216 = F_58 ( V_56 , V_255 ) ;
if ( ! V_216 )
goto V_254;
if ( F_84 ( V_56 , V_256 , sizeof( V_218 ) ,
& V_218 ) ) {
F_60 ( V_56 , V_216 ) ;
goto V_254;
}
F_59 ( V_56 , V_216 ) ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
if ( V_35 -> V_178 -> V_257 )
V_35 -> V_178 -> V_257 ( V_35 , V_212 ,
& V_222 ) ;
V_215 = F_58 ( V_56 , V_258 ) ;
if ( ! V_215 )
goto V_254;
if ( F_116 ( V_56 , V_259 ,
V_222 . V_134 , V_260 ) ||
F_116 ( V_56 , V_261 ,
V_222 . V_135 , V_260 ) ||
F_116 ( V_56 , V_262 ,
V_222 . V_136 , V_260 ) ||
F_116 ( V_56 , V_263 ,
V_222 . V_137 , V_260 ) ||
F_116 ( V_56 , V_264 ,
V_222 . V_265 , V_260 ) ||
F_116 ( V_56 , V_266 ,
V_222 . V_142 , V_260 ) ) {
F_60 ( V_56 , V_215 ) ;
goto V_254;
}
F_59 ( V_56 , V_215 ) ;
F_59 ( V_56 , V_188 ) ;
return 0 ;
V_254:
F_60 ( V_56 , V_188 ) ;
V_245:
F_60 ( V_56 , V_213 ) ;
return - V_59 ;
}
static int F_117 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_183 V_267 ;
memset ( & V_267 , 0 , sizeof( V_267 ) ) ;
V_267 . V_268 = V_35 -> V_268 ;
V_267 . V_269 = V_35 -> V_269 ;
V_267 . V_270 = V_35 -> V_270 ;
V_267 . V_271 = V_35 -> V_271 ;
V_267 . V_272 = V_35 -> V_272 ;
V_267 . V_273 = V_35 -> V_274 ;
if ( F_118 ( V_56 , V_275 , sizeof( V_267 ) , & V_267 , V_210 ) )
return - V_59 ;
return 0 ;
}
static T_9 F_119 ( struct V_34 * V_35 , T_5 * V_276 )
{
const struct V_277 * V_25 = V_35 -> V_178 ;
const struct V_278 * V_279 ;
F_120 () ;
* V_276 = 0 ;
V_279 = F_121 ( V_35 -> V_280 ) ;
if ( V_279 ) {
* V_276 = V_279 -> V_281 -> V_102 ;
return V_282 ;
}
if ( ! V_25 -> V_283 )
return V_284 ;
return F_122 ( V_35 , V_25 -> V_283 , V_276 ) ;
}
static int F_123 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_285 ;
T_5 V_276 ;
int V_32 ;
V_285 = F_58 ( V_56 , V_286 ) ;
if ( ! V_285 )
return - V_59 ;
V_32 = F_124 ( V_56 , V_287 ,
F_119 ( V_35 , & V_276 ) ) ;
if ( V_32 )
goto V_288;
if ( V_276 ) {
V_32 = F_78 ( V_56 , V_289 , V_276 ) ;
if ( V_32 )
goto V_288;
}
F_59 ( V_56 , V_285 ) ;
return 0 ;
V_288:
F_60 ( V_56 , V_285 ) ;
return V_32 ;
}
static T_5 F_125 ( unsigned long V_290 )
{
T_5 V_291 = V_292 ;
switch ( V_290 ) {
case V_293 :
V_291 = V_294 ;
break;
case V_295 :
V_291 = V_296 ;
break;
case V_297 :
V_291 = V_298 ;
break;
case V_299 :
V_291 = V_300 ;
break;
case V_301 :
V_291 = V_302 ;
break;
case V_303 :
V_291 = V_304 ;
break;
default:
break;
}
return V_291 ;
}
static int F_126 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_305 , T_5 V_306 ,
unsigned int V_83 , T_5 V_53 ,
T_5 V_290 )
{
struct V_126 * V_127 ;
struct V_81 * V_82 ;
struct V_47 * V_307 ;
struct V_51 * V_54 ;
struct V_34 * V_308 = F_47 ( V_35 ) ;
F_120 () ;
V_82 = F_127 ( V_56 , V_73 , V_305 , type , sizeof( * V_127 ) , V_83 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_128 ( V_82 ) ;
V_127 -> V_309 = V_310 ;
V_127 -> V_311 = 0 ;
V_127 -> V_312 = V_35 -> type ;
V_127 -> V_313 = V_35 -> V_314 ;
V_127 -> V_128 = F_129 ( V_35 ) ;
V_127 -> V_129 = V_306 ;
if ( F_57 ( V_56 , V_315 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_316 , V_35 -> V_317 ) ||
F_124 ( V_56 , V_318 ,
F_130 ( V_35 ) ? V_35 -> V_118 : V_319 ) ||
F_124 ( V_56 , V_320 , V_35 -> V_321 ) ||
F_78 ( V_56 , V_322 , V_35 -> V_323 ) ||
F_78 ( V_56 , V_324 , V_35 -> V_74 ) ||
F_78 ( V_56 , V_325 , V_35 -> V_326 ) ||
F_78 ( V_56 , V_327 , V_35 -> V_328 ) ||
F_78 ( V_56 , V_329 , V_35 -> V_330 ) ||
F_78 ( V_56 , V_331 , V_35 -> V_332 ) ||
#ifdef F_131
F_78 ( V_56 , V_333 , V_35 -> V_334 ) ||
#endif
( V_35 -> V_314 != F_132 ( V_35 ) &&
F_78 ( V_56 , V_335 , F_132 ( V_35 ) ) ) ||
( V_308 &&
F_78 ( V_56 , V_336 , V_308 -> V_314 ) ) ||
F_124 ( V_56 , V_337 , F_133 ( V_35 ) ) ||
( V_35 -> V_338 &&
F_57 ( V_56 , V_339 , V_35 -> V_338 -> V_25 -> V_102 ) ) ||
( V_35 -> V_340 &&
F_57 ( V_56 , V_341 , V_35 -> V_340 ) ) ||
F_78 ( V_56 , V_342 ,
F_81 ( & V_35 -> V_343 ) ) ||
F_124 ( V_56 , V_344 , V_35 -> V_345 ) )
goto V_95;
if ( V_290 != V_292 ) {
if ( F_78 ( V_56 , V_346 , V_290 ) )
goto V_95;
}
if ( F_117 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_347 ) {
if ( F_84 ( V_56 , V_348 , V_35 -> V_347 , V_35 -> V_349 ) ||
F_84 ( V_56 , V_350 , V_35 -> V_347 , V_35 -> V_265 ) )
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
F_78 ( V_56 , V_351 , F_94 ( V_35 -> V_35 . V_158 ) ) )
goto V_95;
if ( V_35 -> V_178 -> V_235 && V_35 -> V_35 . V_158 &&
V_53 & V_159 ) {
int V_87 ;
struct V_47 * V_213 ;
int V_160 = F_94 ( V_35 -> V_35 . V_158 ) ;
V_213 = F_58 ( V_56 , V_352 ) ;
if ( ! V_213 )
goto V_95;
for ( V_87 = 0 ; V_87 < V_160 ; V_87 ++ ) {
if ( F_114 ( V_56 , V_35 , V_87 , V_213 ) )
goto V_95;
}
F_59 ( V_56 , V_213 ) ;
}
if ( F_102 ( V_56 , V_35 , V_53 ) )
goto V_95;
if ( F_123 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_23 || F_55 ( V_35 ) ) {
if ( F_62 ( V_56 , V_35 ) < 0 )
goto V_95;
}
if ( V_35 -> V_23 &&
V_35 -> V_23 -> V_353 ) {
struct V_33 * V_354 = V_35 -> V_23 -> V_353 ( V_35 ) ;
if ( ! F_134 ( F_135 ( V_35 ) , V_354 ) ) {
int V_102 = F_136 ( F_135 ( V_35 ) , V_354 ) ;
if ( F_137 ( V_56 , V_355 , V_102 ) )
goto V_95;
}
}
if ( ! ( V_307 = F_58 ( V_56 , V_356 ) ) )
goto V_95;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_357 ) {
struct V_47 * V_358 ;
int V_32 ;
if ( ! ( V_358 = F_58 ( V_56 , V_54 -> V_52 ) ) )
goto V_95;
V_32 = V_54 -> V_357 ( V_56 , V_35 , V_53 ) ;
if ( V_32 == - V_359 )
F_60 ( V_56 , V_358 ) ;
else if ( V_32 < 0 )
goto V_95;
F_59 ( V_56 , V_358 ) ;
}
}
F_59 ( V_56 , V_307 ) ;
F_138 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_139 ( V_56 , V_82 ) ;
return - V_59 ;
}
static const struct V_23 * F_140 ( const struct V_47 * V_360 )
{
const struct V_23 * V_25 = NULL ;
struct V_47 * V_361 [ V_362 + 1 ] ;
if ( F_141 ( V_361 , V_362 , V_360 ,
V_363 , NULL ) < 0 )
return NULL ;
if ( V_361 [ V_64 ] ) {
char V_24 [ V_364 ] ;
F_142 ( V_24 , V_361 [ V_64 ] , sizeof( V_24 ) ) ;
V_25 = F_28 ( V_24 ) ;
}
return V_25 ;
}
static bool F_143 ( struct V_34 * V_35 , int V_365 )
{
struct V_34 * V_366 ;
if ( ! V_365 )
return false ;
V_366 = F_47 ( V_35 ) ;
if ( ! V_366 || V_366 -> V_314 != V_365 )
return true ;
return false ;
}
static bool F_144 ( const struct V_34 * V_35 ,
const struct V_23 * V_367 )
{
if ( V_367 && V_35 -> V_23 != V_367 )
return true ;
return false ;
}
static bool F_145 ( struct V_34 * V_35 ,
int V_365 ,
const struct V_23 * V_367 )
{
if ( F_143 ( V_35 , V_365 ) ||
F_144 ( V_35 , V_367 ) )
return true ;
return false ;
}
static int F_146 ( struct V_2 * V_56 , struct V_368 * V_369 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
int V_371 , V_372 ;
int V_373 = 0 , V_374 ;
struct V_34 * V_35 ;
struct V_375 * V_3 ;
struct V_47 * V_376 [ V_377 + 1 ] ;
T_5 V_53 = 0 ;
const struct V_23 * V_367 = NULL ;
unsigned int V_83 = V_378 ;
int V_365 = 0 ;
int V_32 ;
int V_379 ;
V_372 = V_369 -> args [ 0 ] ;
V_374 = V_369 -> args [ 1 ] ;
V_369 -> V_305 = V_33 -> V_380 ;
V_379 = F_148 ( V_369 -> V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_381 ) : sizeof( struct V_126 ) ;
if ( F_149 ( V_369 -> V_82 , V_379 , V_376 , V_377 ,
V_382 , NULL ) >= 0 ) {
if ( V_376 [ V_383 ] )
V_53 = F_150 ( V_376 [ V_383 ] ) ;
if ( V_376 [ V_336 ] )
V_365 = F_150 ( V_376 [ V_336 ] ) ;
if ( V_376 [ V_70 ] )
V_367 = F_140 ( V_376 [ V_70 ] ) ;
if ( V_365 || V_367 )
V_83 |= V_384 ;
}
for ( V_371 = V_372 ; V_371 < V_385 ; V_371 ++ , V_374 = 0 ) {
V_373 = 0 ;
V_3 = & V_33 -> V_386 [ V_371 ] ;
F_151 (dev, head, index_hlist) {
if ( F_145 ( V_35 , V_365 , V_367 ) )
goto V_387;
if ( V_373 < V_374 )
goto V_387;
V_32 = F_126 ( V_56 , V_35 , V_388 ,
F_64 ( V_369 -> V_56 ) . V_389 ,
V_369 -> V_82 -> V_390 , 0 ,
V_83 ,
V_53 , 0 ) ;
if ( V_32 < 0 ) {
if ( F_152 ( V_56 -> V_391 ) )
goto V_71;
goto V_392;
}
F_153 ( V_369 , F_154 ( V_56 ) ) ;
V_387:
V_373 ++ ;
}
}
V_71:
V_32 = V_56 -> V_391 ;
V_392:
V_369 -> args [ 1 ] = V_373 ;
V_369 -> args [ 0 ] = V_371 ;
return V_32 ;
}
int F_155 ( struct V_47 * * V_376 , const struct V_47 * V_3 , int V_391 ,
struct V_393 * V_394 )
{
return F_156 ( V_376 , V_377 , V_3 , V_391 , V_382 , V_394 ) ;
}
struct V_33 * F_157 ( struct V_33 * V_395 , struct V_47 * V_376 [] )
{
struct V_33 * V_33 ;
if ( V_376 [ V_396 ] )
V_33 = F_158 ( F_150 ( V_376 [ V_396 ] ) ) ;
else if ( V_376 [ V_397 ] )
V_33 = F_159 ( F_150 ( V_376 [ V_397 ] ) ) ;
else
V_33 = F_160 ( V_395 ) ;
return V_33 ;
}
static int F_161 ( struct V_34 * V_35 , struct V_47 * V_376 [] )
{
if ( V_35 ) {
if ( V_376 [ V_348 ] &&
F_162 ( V_376 [ V_348 ] ) < V_35 -> V_347 )
return - V_398 ;
if ( V_376 [ V_350 ] &&
F_162 ( V_376 [ V_350 ] ) < V_35 -> V_347 )
return - V_398 ;
}
if ( V_376 [ V_356 ] ) {
struct V_47 * V_358 ;
int V_399 , V_32 ;
F_163 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_164 ( V_358 ) ) ) )
return - V_400 ;
if ( ! V_54 -> V_401 )
return - V_197 ;
if ( V_54 -> V_402 ) {
V_32 = V_54 -> V_402 ( V_35 , V_358 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
}
return 0 ;
}
static int F_165 ( struct V_34 * V_35 , struct V_403 * V_404 ,
int V_405 )
{
const struct V_277 * V_25 = V_35 -> V_178 ;
return V_25 -> V_406 ( V_35 , V_404 -> V_188 , V_404 -> V_407 , V_405 ) ;
}
static int F_166 ( struct V_34 * V_35 , struct V_403 * V_404 , int V_405 )
{
if ( V_35 -> type != V_408 )
return - V_197 ;
return F_165 ( V_35 , V_404 , V_405 ) ;
}
static int F_167 ( struct V_34 * V_35 , struct V_47 * * V_376 )
{
const struct V_277 * V_25 = V_35 -> V_178 ;
int V_32 = - V_398 ;
if ( V_376 [ V_246 ] ) {
struct V_161 * V_409 = F_111 ( V_376 [ V_246 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_410 )
V_32 = V_25 -> V_410 ( V_35 , V_409 -> V_188 ,
V_409 -> V_236 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_376 [ V_247 ] ) {
struct V_162 * V_411 = F_111 ( V_376 [ V_247 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_412 )
V_32 = V_25 -> V_412 ( V_35 , V_411 -> V_188 , V_411 -> V_237 ,
V_411 -> V_238 ,
F_115 ( V_234 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_376 [ V_255 ] ) {
struct V_164 * V_413 [ V_163 ] ;
struct V_47 * V_202 ;
int V_399 , V_391 = 0 ;
V_32 = - V_197 ;
if ( ! V_25 -> V_412 )
return V_32 ;
F_163 (attr, tb[IFLA_VF_VLAN_LIST], rem) {
if ( F_164 ( V_202 ) != V_256 ||
F_162 ( V_202 ) < V_414 ) {
return - V_398 ;
}
if ( V_391 >= V_163 )
return - V_197 ;
V_413 [ V_391 ] = F_111 ( V_202 ) ;
V_391 ++ ;
}
if ( V_391 == 0 )
return - V_398 ;
V_32 = V_25 -> V_412 ( V_35 , V_413 [ 0 ] -> V_188 , V_413 [ 0 ] -> V_237 ,
V_413 [ 0 ] -> V_238 , V_413 [ 0 ] -> V_233 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_376 [ V_249 ] ) {
struct V_166 * V_404 = F_111 ( V_376 [ V_249 ] ) ;
struct V_227 V_415 ;
V_32 = - V_197 ;
if ( V_25 -> V_235 )
V_32 = V_25 -> V_235 ( V_35 , V_404 -> V_188 , & V_415 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = - V_197 ;
if ( V_25 -> V_416 )
V_32 = V_25 -> V_416 ( V_35 , V_404 -> V_188 ,
V_415 . V_241 ,
V_404 -> V_239 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_376 [ V_248 ] ) {
struct V_167 * V_404 = F_111 ( V_376 [ V_248 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_416 )
V_32 = V_25 -> V_416 ( V_35 , V_404 -> V_188 ,
V_404 -> V_241 ,
V_404 -> V_240 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_376 [ V_250 ] ) {
struct V_165 * V_417 = F_111 ( V_376 [ V_250 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_418 )
V_32 = V_25 -> V_418 ( V_35 , V_417 -> V_188 ,
V_417 -> V_242 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_376 [ V_251 ] ) {
struct V_168 * V_419 = F_111 ( V_376 [ V_251 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_420 )
V_32 = V_25 -> V_420 ( V_35 , V_419 -> V_188 ,
V_419 -> V_243 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_376 [ V_252 ] ) {
struct V_169 * V_421 ;
V_32 = - V_197 ;
V_421 = F_111 ( V_376 [ V_252 ] ) ;
if ( V_25 -> V_422 )
V_32 = V_25 -> V_422 ( V_35 , V_421 -> V_188 ,
V_421 -> V_242 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_376 [ V_253 ] ) {
struct V_171 * V_404 = F_111 ( V_376 [ V_253 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_423 )
V_32 = V_25 -> V_423 ( V_35 , V_404 -> V_188 , V_404 -> V_242 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_376 [ V_424 ] ) {
struct V_403 * V_404 = F_111 ( V_376 [ V_424 ] ) ;
if ( ! V_25 -> V_406 )
return - V_197 ;
return F_166 ( V_35 , V_404 , V_424 ) ;
}
if ( V_376 [ V_425 ] ) {
struct V_403 * V_404 = F_111 ( V_376 [ V_425 ] ) ;
if ( ! V_25 -> V_406 )
return - V_197 ;
return F_166 ( V_35 , V_404 , V_425 ) ;
}
return V_32 ;
}
static int F_168 ( struct V_34 * V_35 , int V_314 )
{
struct V_34 * V_308 = F_47 ( V_35 ) ;
const struct V_277 * V_25 ;
int V_32 ;
if ( V_308 ) {
if ( V_308 -> V_314 == V_314 )
return 0 ;
V_25 = V_308 -> V_178 ;
if ( V_25 -> V_426 ) {
V_32 = V_25 -> V_426 ( V_308 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_197 ;
}
}
if ( V_314 ) {
V_308 = F_169 ( F_135 ( V_35 ) , V_314 ) ;
if ( ! V_308 )
return - V_398 ;
V_25 = V_308 -> V_178 ;
if ( V_25 -> V_427 ) {
V_32 = V_25 -> V_427 ( V_308 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_197 ;
}
}
return 0 ;
}
static int F_170 ( const struct V_2 * V_56 ,
struct V_34 * V_35 , struct V_126 * V_127 ,
struct V_393 * V_428 ,
struct V_47 * * V_376 , char * V_429 , int V_430 )
{
const struct V_277 * V_25 = V_35 -> V_178 ;
int V_32 ;
if ( V_376 [ V_396 ] || V_376 [ V_397 ] ) {
struct V_33 * V_33 = F_157 ( F_135 ( V_35 ) , V_376 ) ;
if ( F_171 ( V_33 ) ) {
V_32 = F_172 ( V_33 ) ;
goto V_431;
}
if ( ! F_173 ( V_56 , V_33 -> V_432 , V_433 ) ) {
F_174 ( V_33 ) ;
V_32 = - V_434 ;
goto V_431;
}
V_32 = F_175 ( V_35 , V_33 , V_429 ) ;
F_174 ( V_33 ) ;
if ( V_32 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_275 ] ) {
struct V_183 * V_436 ;
struct V_437 V_438 ;
if ( ! V_25 -> V_439 ) {
V_32 = - V_197 ;
goto V_431;
}
if ( ! F_176 ( V_35 ) ) {
V_32 = - V_440 ;
goto V_431;
}
V_436 = F_111 ( V_376 [ V_275 ] ) ;
V_438 . V_268 = ( unsigned long ) V_436 -> V_268 ;
V_438 . V_269 = ( unsigned long ) V_436 -> V_269 ;
V_438 . V_270 = ( unsigned short ) V_436 -> V_270 ;
V_438 . V_271 = ( unsigned char ) V_436 -> V_271 ;
V_438 . V_272 = ( unsigned char ) V_436 -> V_272 ;
V_438 . V_273 = ( unsigned char ) V_436 -> V_273 ;
V_32 = V_25 -> V_439 ( V_35 , & V_438 ) ;
if ( V_32 < 0 )
goto V_431;
V_430 |= V_441 ;
}
if ( V_376 [ V_348 ] ) {
struct V_442 * V_443 ;
int V_391 ;
V_391 = sizeof( V_444 ) + F_177 ( T_4 , V_35 -> V_347 ,
sizeof( * V_443 ) ) ;
V_443 = F_178 ( V_391 , V_20 ) ;
if ( ! V_443 ) {
V_32 = - V_445 ;
goto V_431;
}
V_443 -> V_446 = V_35 -> type ;
memcpy ( V_443 -> V_447 , F_111 ( V_376 [ V_348 ] ) ,
V_35 -> V_347 ) ;
V_32 = F_179 ( V_35 , V_443 ) ;
F_27 ( V_443 ) ;
if ( V_32 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_322 ] ) {
V_32 = F_180 ( V_35 , F_150 ( V_376 [ V_322 ] ) ) ;
if ( V_32 < 0 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_324 ] ) {
F_181 ( V_35 , F_150 ( V_376 [ V_324 ] ) ) ;
V_430 |= V_441 ;
}
if ( V_127 -> V_313 > 0 && V_429 [ 0 ] ) {
V_32 = F_182 ( V_35 , V_429 ) ;
if ( V_32 < 0 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_341 ] ) {
V_32 = F_183 ( V_35 , F_111 ( V_376 [ V_341 ] ) ,
F_162 ( V_376 [ V_341 ] ) ) ;
if ( V_32 < 0 )
goto V_431;
V_430 |= V_441 ;
}
if ( V_376 [ V_350 ] ) {
F_184 ( V_35 -> V_265 , V_376 [ V_350 ] , V_35 -> V_347 ) ;
F_185 ( V_448 , V_35 ) ;
}
if ( V_127 -> V_128 || V_127 -> V_129 ) {
V_32 = F_186 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
goto V_431;
}
if ( V_376 [ V_336 ] ) {
V_32 = F_168 ( V_35 , F_150 ( V_376 [ V_336 ] ) ) ;
if ( V_32 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_337 ] ) {
V_32 = F_187 ( V_35 , F_188 ( V_376 [ V_337 ] ) ) ;
if ( V_32 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_316 ] ) {
unsigned int V_449 = F_150 ( V_376 [ V_316 ] ) ;
unsigned int V_450 = V_35 -> V_317 ;
if ( V_35 -> V_317 ^ V_449 ) {
V_35 -> V_317 = V_449 ;
V_32 = F_185 (
V_451 , V_35 ) ;
V_32 = F_189 ( V_32 ) ;
if ( V_32 ) {
V_35 -> V_317 = V_450 ;
goto V_431;
}
V_430 |= V_441 ;
}
}
if ( V_376 [ V_318 ] )
F_85 ( V_35 , F_188 ( V_376 [ V_318 ] ) ) ;
if ( V_376 [ V_320 ] ) {
unsigned char V_449 = F_188 ( V_376 [ V_320 ] ) ;
F_87 ( & V_122 ) ;
if ( V_35 -> V_321 ^ V_449 )
V_430 |= V_441 ;
V_35 -> V_321 = V_449 ;
F_88 ( & V_122 ) ;
}
if ( V_376 [ V_352 ] ) {
struct V_47 * V_213 [ V_452 + 1 ] ;
struct V_47 * V_202 ;
int V_399 ;
F_163 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_164 ( V_202 ) != V_244 ||
F_162 ( V_202 ) < V_414 ) {
V_32 = - V_398 ;
goto V_431;
}
V_32 = F_141 ( V_213 , V_452 , V_202 ,
V_453 , NULL ) ;
if ( V_32 < 0 )
goto V_431;
V_32 = F_167 ( V_35 , V_213 ) ;
if ( V_32 < 0 )
goto V_431;
V_430 |= V_441 ;
}
}
V_32 = 0 ;
if ( V_376 [ V_189 ] ) {
struct V_47 * V_273 [ V_454 + 1 ] ;
struct V_47 * V_202 ;
int V_188 ;
int V_399 ;
V_32 = - V_197 ;
if ( ! V_25 -> V_455 )
goto V_431;
F_163 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_164 ( V_202 ) != V_190 ||
F_162 ( V_202 ) < V_414 ) {
V_32 = - V_398 ;
goto V_431;
}
V_32 = F_141 ( V_273 , V_454 , V_202 ,
V_456 , NULL ) ;
if ( V_32 < 0 )
goto V_431;
if ( ! V_273 [ V_191 ] ) {
V_32 = - V_197 ;
goto V_431;
}
V_188 = F_150 ( V_273 [ V_191 ] ) ;
V_32 = V_25 -> V_455 ( V_35 , V_188 , V_273 ) ;
if ( V_32 < 0 )
goto V_431;
V_430 |= V_441 ;
}
}
V_32 = 0 ;
if ( V_376 [ V_193 ] ) {
struct V_47 * V_273 [ V_454 + 1 ] ;
V_32 = F_141 ( V_273 , V_454 ,
V_376 [ V_193 ] , V_456 ,
NULL ) ;
if ( V_32 < 0 )
goto V_431;
V_32 = - V_197 ;
if ( V_25 -> V_455 )
V_32 = V_25 -> V_455 ( V_35 , V_194 , V_273 ) ;
if ( V_32 < 0 )
goto V_431;
V_430 |= V_441 ;
}
if ( V_376 [ V_356 ] ) {
struct V_47 * V_358 ;
int V_399 ;
F_163 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_164 ( V_358 ) ) ) )
F_190 () ;
V_32 = V_54 -> V_401 ( V_35 , V_358 ) ;
if ( V_32 < 0 )
goto V_431;
V_430 |= V_441 ;
}
}
V_32 = 0 ;
if ( V_376 [ V_344 ] ) {
V_32 = F_191 ( V_35 ,
F_188 ( V_376 [ V_344 ] ) ) ;
if ( V_32 )
goto V_431;
V_430 |= V_441 ;
}
if ( V_376 [ V_286 ] ) {
struct V_47 * V_285 [ V_457 + 1 ] ;
T_5 V_458 = 0 ;
V_32 = F_141 ( V_285 , V_457 , V_376 [ V_286 ] ,
V_459 , NULL ) ;
if ( V_32 < 0 )
goto V_431;
if ( V_285 [ V_287 ] || V_285 [ V_289 ] ) {
V_32 = - V_398 ;
goto V_431;
}
if ( V_285 [ V_460 ] ) {
V_458 = F_150 ( V_285 [ V_460 ] ) ;
if ( V_458 & ~ V_461 ) {
V_32 = - V_398 ;
goto V_431;
}
if ( F_192 ( V_458 & V_462 ) > 1 ) {
V_32 = - V_398 ;
goto V_431;
}
}
if ( V_285 [ V_463 ] ) {
V_32 = F_193 ( V_35 , V_428 ,
F_194 ( V_285 [ V_463 ] ) ,
V_458 ) ;
if ( V_32 )
goto V_431;
V_430 |= V_441 ;
}
}
V_431:
if ( V_430 & V_435 ) {
if ( V_430 & V_441 )
F_89 ( V_35 ) ;
if ( V_32 < 0 )
F_195 ( L_3 ,
V_35 -> V_94 ) ;
}
return V_32 ;
}
static int F_196 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
int V_32 ;
struct V_47 * V_376 [ V_377 + 1 ] ;
char V_429 [ V_181 ] ;
V_32 = F_149 ( V_82 , sizeof( * V_127 ) , V_376 , V_377 , V_382 ,
V_428 ) ;
if ( V_32 < 0 )
goto V_431;
if ( V_376 [ V_315 ] )
F_142 ( V_429 , V_376 [ V_315 ] , V_181 ) ;
else
V_429 [ 0 ] = '\0' ;
V_32 = - V_398 ;
V_127 = F_128 ( V_82 ) ;
if ( V_127 -> V_313 > 0 )
V_35 = F_169 ( V_33 , V_127 -> V_313 ) ;
else if ( V_376 [ V_315 ] )
V_35 = F_197 ( V_33 , V_429 ) ;
else
goto V_431;
if ( V_35 == NULL ) {
V_32 = - V_440 ;
goto V_431;
}
V_32 = F_161 ( V_35 , V_376 ) ;
if ( V_32 < 0 )
goto V_431;
V_32 = F_170 ( V_56 , V_35 , V_127 , V_428 , V_376 , V_429 , 0 ) ;
V_431:
return V_32 ;
}
static int F_198 ( const struct V_33 * V_33 , int V_74 )
{
struct V_34 * V_35 , * V_281 ;
F_34 ( V_36 ) ;
bool V_464 = false ;
if ( ! V_74 )
return - V_434 ;
F_35 (net, dev) {
if ( V_35 -> V_74 == V_74 ) {
const struct V_23 * V_25 ;
V_464 = true ;
V_25 = V_35 -> V_23 ;
if ( ! V_25 || ! V_25 -> V_28 )
return - V_197 ;
}
}
if ( ! V_464 )
return - V_440 ;
F_199 (net, dev, aux) {
if ( V_35 -> V_74 == V_74 ) {
const struct V_23 * V_25 ;
V_25 = V_35 -> V_23 ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
}
}
F_36 ( & V_36 ) ;
return 0 ;
}
int F_200 ( struct V_34 * V_35 )
{
const struct V_23 * V_25 ;
F_34 ( V_36 ) ;
V_25 = V_35 -> V_23 ;
if ( ! V_25 || ! V_25 -> V_28 )
return - V_197 ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
F_36 ( & V_36 ) ;
return 0 ;
}
static int F_201 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_34 * V_35 ;
struct V_126 * V_127 ;
char V_429 [ V_181 ] ;
struct V_47 * V_376 [ V_377 + 1 ] ;
int V_32 ;
V_32 = F_149 ( V_82 , sizeof( * V_127 ) , V_376 , V_377 , V_382 , V_428 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_376 [ V_315 ] )
F_142 ( V_429 , V_376 [ V_315 ] , V_181 ) ;
V_127 = F_128 ( V_82 ) ;
if ( V_127 -> V_313 > 0 )
V_35 = F_169 ( V_33 , V_127 -> V_313 ) ;
else if ( V_376 [ V_315 ] )
V_35 = F_197 ( V_33 , V_429 ) ;
else if ( V_376 [ V_324 ] )
return F_198 ( V_33 , F_150 ( V_376 [ V_324 ] ) ) ;
else
return - V_398 ;
if ( ! V_35 )
return - V_440 ;
return F_200 ( V_35 ) ;
}
int F_202 ( struct V_34 * V_35 , const struct V_126 * V_127 )
{
unsigned int V_465 ;
int V_32 ;
V_465 = V_35 -> V_83 ;
if ( V_127 && ( V_127 -> V_128 || V_127 -> V_129 ) ) {
V_32 = F_203 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_35 -> V_466 = V_467 ;
F_204 ( V_35 , V_465 , ~ 0U ) ;
return 0 ;
}
struct V_34 * F_205 ( struct V_33 * V_33 ,
const char * V_429 , unsigned char V_468 ,
const struct V_23 * V_25 , struct V_47 * V_376 [] )
{
struct V_34 * V_35 ;
unsigned int V_328 = 1 ;
unsigned int V_334 = 1 ;
if ( V_376 [ V_327 ] )
V_328 = F_150 ( V_376 [ V_327 ] ) ;
else if ( V_25 -> V_469 )
V_328 = V_25 -> V_469 () ;
if ( V_376 [ V_333 ] )
V_334 = F_150 ( V_376 [ V_333 ] ) ;
else if ( V_25 -> V_470 )
V_334 = V_25 -> V_470 () ;
V_35 = F_206 ( V_25 -> V_471 , V_429 , V_468 ,
V_25 -> V_27 , V_328 , V_334 ) ;
if ( ! V_35 )
return F_207 ( - V_445 ) ;
F_208 ( V_35 , V_33 ) ;
V_35 -> V_23 = V_25 ;
V_35 -> V_466 = V_472 ;
if ( V_376 [ V_322 ] )
V_35 -> V_323 = F_150 ( V_376 [ V_322 ] ) ;
if ( V_376 [ V_348 ] ) {
memcpy ( V_35 -> V_349 , F_111 ( V_376 [ V_348 ] ) ,
F_162 ( V_376 [ V_348 ] ) ) ;
V_35 -> V_473 = V_474 ;
}
if ( V_376 [ V_350 ] )
memcpy ( V_35 -> V_265 , F_111 ( V_376 [ V_350 ] ) ,
F_162 ( V_376 [ V_350 ] ) ) ;
if ( V_376 [ V_316 ] )
V_35 -> V_317 = F_150 ( V_376 [ V_316 ] ) ;
if ( V_376 [ V_318 ] )
F_85 ( V_35 , F_188 ( V_376 [ V_318 ] ) ) ;
if ( V_376 [ V_320 ] )
V_35 -> V_321 = F_188 ( V_376 [ V_320 ] ) ;
if ( V_376 [ V_324 ] )
F_181 ( V_35 , F_150 ( V_376 [ V_324 ] ) ) ;
return V_35 ;
}
static int F_209 ( const struct V_2 * V_56 ,
struct V_33 * V_33 , int V_74 ,
struct V_126 * V_127 ,
struct V_393 * V_428 ,
struct V_47 * * V_376 )
{
struct V_34 * V_35 , * V_281 ;
int V_32 ;
F_199 (net, dev, aux) {
if ( V_35 -> V_74 == V_74 ) {
V_32 = F_170 ( V_56 , V_35 , V_127 , V_428 , V_376 , NULL , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
return 0 ;
}
static int F_210 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
const struct V_23 * V_25 ;
const struct V_23 * V_475 = NULL ;
struct V_34 * V_35 ;
struct V_34 * V_45 = NULL ;
struct V_126 * V_127 ;
char V_24 [ V_364 ] ;
char V_429 [ V_181 ] ;
struct V_47 * V_376 [ V_377 + 1 ] ;
struct V_47 * V_69 [ V_362 + 1 ] ;
unsigned char V_468 = V_476 ;
int V_32 ;
#ifdef F_211
V_477:
#endif
V_32 = F_149 ( V_82 , sizeof( * V_127 ) , V_376 , V_377 , V_382 , V_428 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_376 [ V_315 ] )
F_142 ( V_429 , V_376 [ V_315 ] , V_181 ) ;
else
V_429 [ 0 ] = '\0' ;
V_127 = F_128 ( V_82 ) ;
if ( V_127 -> V_313 > 0 )
V_35 = F_169 ( V_33 , V_127 -> V_313 ) ;
else {
if ( V_429 [ 0 ] )
V_35 = F_197 ( V_33 , V_429 ) ;
else
V_35 = NULL ;
}
if ( V_35 ) {
V_45 = F_47 ( V_35 ) ;
if ( V_45 )
V_475 = V_45 -> V_23 ;
}
V_32 = F_161 ( V_35 , V_376 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_376 [ V_70 ] ) {
V_32 = F_141 ( V_69 , V_362 ,
V_376 [ V_70 ] , V_363 ,
NULL ) ;
if ( V_32 < 0 )
return V_32 ;
} else
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_69 [ V_64 ] ) {
F_142 ( V_24 , V_69 [ V_64 ] , sizeof( V_24 ) ) ;
V_25 = F_28 ( V_24 ) ;
} else {
V_24 [ 0 ] = '\0' ;
V_25 = NULL ;
}
if ( 1 ) {
struct V_47 * V_202 [ V_25 ? V_25 -> V_478 + 1 : 1 ] ;
struct V_47 * V_479 [ V_475 ? V_475 -> V_480 + 1 : 1 ] ;
struct V_47 * * V_63 = NULL ;
struct V_47 * * V_57 = NULL ;
struct V_33 * V_481 , * V_354 = NULL ;
if ( V_25 ) {
if ( V_25 -> V_478 && V_69 [ V_67 ] ) {
V_32 = F_141 ( V_202 , V_25 -> V_478 ,
V_69 [ V_67 ] ,
V_25 -> V_482 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_63 = V_202 ;
}
if ( V_25 -> V_483 ) {
V_32 = V_25 -> V_483 ( V_376 , V_63 , V_428 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_475 ) {
if ( V_475 -> V_480 &&
V_69 [ V_61 ] ) {
V_32 = F_141 ( V_479 ,
V_475 -> V_480 ,
V_69 [ V_61 ] ,
V_475 -> V_484 ,
NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_57 = V_479 ;
}
if ( V_475 -> V_485 ) {
V_32 = V_475 -> V_485 ( V_376 , V_57 ,
V_428 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_35 ) {
int V_430 = 0 ;
if ( V_82 -> V_486 & V_487 )
return - V_26 ;
if ( V_82 -> V_486 & V_488 )
return - V_197 ;
if ( V_69 [ V_67 ] ) {
if ( ! V_25 || V_25 != V_35 -> V_23 ||
! V_25 -> V_489 )
return - V_197 ;
V_32 = V_25 -> V_489 ( V_35 , V_376 , V_63 , V_428 ) ;
if ( V_32 < 0 )
return V_32 ;
V_430 |= V_441 ;
}
if ( V_69 [ V_61 ] ) {
if ( ! V_475 || ! V_475 -> V_490 )
return - V_197 ;
V_32 = V_475 -> V_490 ( V_45 , V_35 ,
V_376 , V_57 ,
V_428 ) ;
if ( V_32 < 0 )
return V_32 ;
V_430 |= V_441 ;
}
return F_170 ( V_56 , V_35 , V_127 , V_428 , V_376 , V_429 ,
V_430 ) ;
}
if ( ! ( V_82 -> V_486 & V_491 ) ) {
if ( V_127 -> V_313 == 0 && V_376 [ V_324 ] )
return F_209 ( V_56 , V_33 ,
F_150 ( V_376 [ V_324 ] ) ,
V_127 , V_428 , V_376 ) ;
return - V_440 ;
}
if ( V_376 [ V_275 ] || V_376 [ V_492 ] )
return - V_197 ;
if ( ! V_25 ) {
#ifdef F_211
if ( V_24 [ 0 ] ) {
F_4 () ;
F_212 ( L_4 , V_24 ) ;
F_1 () ;
V_25 = F_28 ( V_24 ) ;
if ( V_25 )
goto V_477;
}
#endif
return - V_197 ;
}
if ( ! V_25 -> V_27 )
return - V_197 ;
if ( ! V_429 [ 0 ] ) {
snprintf ( V_429 , V_181 , L_5 , V_25 -> V_24 ) ;
V_468 = V_493 ;
}
V_481 = F_157 ( V_33 , V_376 ) ;
if ( F_171 ( V_481 ) )
return F_172 ( V_481 ) ;
V_32 = - V_434 ;
if ( ! F_173 ( V_56 , V_481 -> V_432 , V_433 ) )
goto V_71;
if ( V_376 [ V_355 ] ) {
int V_102 = F_194 ( V_376 [ V_355 ] ) ;
V_354 = F_213 ( V_481 , V_102 ) ;
if ( ! V_354 ) {
V_32 = - V_398 ;
goto V_71;
}
V_32 = - V_434 ;
if ( ! F_173 ( V_56 , V_354 -> V_432 , V_433 ) )
goto V_71;
}
V_35 = F_205 ( V_354 ? : V_481 , V_429 ,
V_468 , V_25 , V_376 ) ;
if ( F_171 ( V_35 ) ) {
V_32 = F_172 ( V_35 ) ;
goto V_71;
}
V_35 -> V_314 = V_127 -> V_313 ;
if ( V_25 -> V_494 ) {
V_32 = V_25 -> V_494 ( V_354 ? : V_33 , V_35 , V_376 , V_63 ,
V_428 ) ;
if ( V_32 < 0 ) {
if ( V_35 -> V_495 == V_496 )
F_214 ( V_35 ) ;
goto V_71;
}
} else {
V_32 = F_215 ( V_35 ) ;
if ( V_32 < 0 ) {
F_214 ( V_35 ) ;
goto V_71;
}
}
V_32 = F_202 ( V_35 , V_127 ) ;
if ( V_32 < 0 )
goto V_497;
if ( V_354 ) {
V_32 = F_175 ( V_35 , V_481 , V_429 ) ;
if ( V_32 < 0 )
goto V_497;
}
if ( V_376 [ V_336 ] ) {
V_32 = F_168 ( V_35 , F_150 ( V_376 [ V_336 ] ) ) ;
if ( V_32 )
goto V_497;
}
V_71:
if ( V_354 )
F_174 ( V_354 ) ;
F_174 ( V_481 ) ;
return V_32 ;
V_497:
if ( V_25 -> V_494 ) {
F_34 ( V_36 ) ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
F_36 ( & V_36 ) ;
} else {
F_216 ( V_35 ) ;
}
goto V_71;
}
}
static int F_217 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_126 * V_127 ;
char V_429 [ V_181 ] ;
struct V_47 * V_376 [ V_377 + 1 ] ;
struct V_34 * V_35 = NULL ;
struct V_2 * V_498 ;
int V_32 ;
T_5 V_53 = 0 ;
V_32 = F_149 ( V_82 , sizeof( * V_127 ) , V_376 , V_377 , V_382 , V_428 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_376 [ V_315 ] )
F_142 ( V_429 , V_376 [ V_315 ] , V_181 ) ;
if ( V_376 [ V_383 ] )
V_53 = F_150 ( V_376 [ V_383 ] ) ;
V_127 = F_128 ( V_82 ) ;
if ( V_127 -> V_313 > 0 )
V_35 = F_169 ( V_33 , V_127 -> V_313 ) ;
else if ( V_376 [ V_315 ] )
V_35 = F_197 ( V_33 , V_429 ) ;
else
return - V_398 ;
if ( V_35 == NULL )
return - V_440 ;
V_498 = F_218 ( F_98 ( V_35 , V_53 ) , V_20 ) ;
if ( V_498 == NULL )
return - V_21 ;
V_32 = F_126 ( V_498 , V_35 , V_388 , F_64 ( V_56 ) . V_389 ,
V_82 -> V_390 , 0 , 0 , V_53 , 0 ) ;
if ( V_32 < 0 ) {
F_219 ( V_32 == - V_59 ) ;
F_6 ( V_498 ) ;
} else
V_32 = F_68 ( V_498 , V_33 , F_64 ( V_56 ) . V_389 ) ;
return V_32 ;
}
static T_10 F_220 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_34 * V_35 ;
struct V_47 * V_376 [ V_377 + 1 ] ;
T_5 V_53 = 0 ;
T_10 V_499 = 0 ;
int V_379 ;
V_379 = F_148 ( V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_381 ) : sizeof( struct V_126 ) ;
if ( F_149 ( V_82 , V_379 , V_376 , V_377 , V_382 , NULL ) >= 0 ) {
if ( V_376 [ V_383 ] )
V_53 = F_150 ( V_376 [ V_383 ] ) ;
}
if ( ! V_53 )
return V_500 ;
F_29 (dev, &net->dev_base_head, dev_list) {
V_499 = F_177 ( T_10 , V_499 ,
F_98 ( V_35 ,
V_53 ) ) ;
}
return F_221 ( V_499 ) ;
}
static int F_222 ( struct V_2 * V_56 , struct V_368 * V_369 )
{
int V_373 ;
int V_374 = V_369 -> V_52 ;
if ( V_374 == 0 )
V_374 = 1 ;
for ( V_373 = 1 ; V_373 <= V_14 ; V_373 ++ ) {
int type = V_369 -> V_82 -> V_501 - V_9 ;
if ( V_373 < V_374 || V_373 == V_502 )
continue;
if ( V_15 [ V_373 ] == NULL ||
V_15 [ V_373 ] [ type ] . V_18 == NULL )
continue;
if ( V_373 > V_374 ) {
memset ( & V_369 -> args [ 0 ] , 0 , sizeof( V_369 -> args ) ) ;
V_369 -> V_503 = 0 ;
V_369 -> V_305 = 0 ;
}
if ( V_15 [ V_373 ] [ type ] . V_18 ( V_56 , V_369 ) )
break;
}
V_369 -> V_52 = V_373 ;
return V_56 -> V_391 ;
}
struct V_2 * F_223 ( int type , struct V_34 * V_35 ,
unsigned int V_306 ,
T_5 V_290 , T_6 V_83 )
{
struct V_33 * V_33 = F_135 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
T_4 V_504 ;
V_56 = F_218 ( ( V_504 = F_98 ( V_35 , 0 ) ) , V_83 ) ;
if ( V_56 == NULL )
goto V_431;
V_32 = F_126 ( V_56 , V_35 , type , 0 , 0 , V_306 , 0 , 0 , V_290 ) ;
if ( V_32 < 0 ) {
F_219 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
goto V_431;
}
return V_56 ;
V_431:
if ( V_32 < 0 )
F_73 ( V_33 , V_505 , V_32 ) ;
return NULL ;
}
void F_224 ( struct V_2 * V_56 , struct V_34 * V_35 , T_6 V_83 )
{
struct V_33 * V_33 = F_135 ( V_35 ) ;
F_70 ( V_56 , V_33 , 0 , V_505 , NULL , V_83 ) ;
}
static void F_225 ( int type , struct V_34 * V_35 ,
unsigned int V_306 , T_5 V_290 ,
T_6 V_83 )
{
struct V_2 * V_56 ;
if ( V_35 -> V_495 != V_506 )
return;
V_56 = F_223 ( type , V_35 , V_306 , V_290 , V_83 ) ;
if ( V_56 )
F_224 ( V_56 , V_35 , V_83 ) ;
}
void F_226 ( int type , struct V_34 * V_35 , unsigned int V_306 ,
T_6 V_83 )
{
F_225 ( type , V_35 , V_306 , F_125 ( 0 ) , V_83 ) ;
}
static int F_227 ( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_9 * V_507 , T_10 V_508 , T_5 V_73 , T_5 V_305 ,
int type , unsigned int V_83 ,
int V_509 , T_10 V_510 )
{
struct V_81 * V_82 ;
struct V_511 * V_512 ;
V_82 = F_127 ( V_56 , V_73 , V_305 , type , sizeof( * V_512 ) , V_509 ) ;
if ( ! V_82 )
return - V_59 ;
V_512 = F_128 ( V_82 ) ;
V_512 -> V_513 = V_514 ;
V_512 -> V_515 = 0 ;
V_512 -> V_516 = 0 ;
V_512 -> V_517 = V_83 ;
V_512 -> V_518 = 0 ;
V_512 -> V_519 = V_35 -> V_314 ;
V_512 -> V_510 = V_510 ;
if ( F_84 ( V_56 , V_520 , V_521 , V_507 ) )
goto V_95;
if ( V_508 )
if ( F_84 ( V_56 , V_522 , sizeof( T_10 ) , & V_508 ) )
goto V_95;
F_138 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_139 ( V_56 , V_82 ) ;
return - V_59 ;
}
static inline T_4 F_228 ( void )
{
return F_99 ( sizeof( struct V_511 ) ) +
F_48 ( V_521 ) +
F_48 ( sizeof( T_10 ) ) +
0 ;
}
static void F_229 ( struct V_34 * V_35 , T_9 * V_507 , T_10 V_508 , int type ,
T_10 V_510 )
{
struct V_33 * V_33 = F_135 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
V_56 = F_218 ( F_228 () , V_523 ) ;
if ( ! V_56 )
goto V_431;
V_32 = F_227 ( V_56 , V_35 , V_507 , V_508 ,
0 , 0 , type , V_524 , 0 , V_510 ) ;
if ( V_32 < 0 ) {
F_6 ( V_56 ) ;
goto V_431;
}
F_70 ( V_56 , V_33 , 0 , V_525 , NULL , V_523 ) ;
return;
V_431:
F_73 ( V_33 , V_525 , V_32 ) ;
}
int F_230 ( struct V_511 * V_512 ,
struct V_47 * V_376 [] ,
struct V_34 * V_35 ,
const unsigned char * V_507 , T_10 V_508 ,
T_10 V_83 )
{
int V_32 = - V_398 ;
if ( V_512 -> V_510 && ! ( V_512 -> V_510 & V_526 ) ) {
F_231 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( V_508 ) {
F_231 ( L_7 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_232 ( V_507 ) || F_233 ( V_507 ) )
V_32 = F_234 ( V_35 , V_507 ) ;
else if ( F_235 ( V_507 ) )
V_32 = F_236 ( V_35 , V_507 ) ;
if ( V_32 == - V_26 && ! ( V_83 & V_487 ) )
V_32 = 0 ;
return V_32 ;
}
static int F_237 ( struct V_47 * V_527 , T_10 * V_528 )
{
T_10 V_508 = 0 ;
if ( V_527 ) {
if ( F_162 ( V_527 ) != sizeof( T_10 ) ) {
F_231 ( L_8 ) ;
return - V_398 ;
}
V_508 = F_238 ( V_527 ) ;
if ( ! V_508 || V_508 >= V_529 ) {
F_231 ( L_9 ,
V_508 ) ;
return - V_398 ;
}
}
* V_528 = V_508 ;
return 0 ;
}
static int F_239 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_511 * V_512 ;
struct V_47 * V_376 [ V_530 + 1 ] ;
struct V_34 * V_35 ;
T_9 * V_507 ;
T_10 V_508 ;
int V_32 ;
V_32 = F_149 ( V_82 , sizeof( * V_512 ) , V_376 , V_530 , NULL , V_428 ) ;
if ( V_32 < 0 )
return V_32 ;
V_512 = F_128 ( V_82 ) ;
if ( V_512 -> V_519 == 0 ) {
F_231 ( L_10 ) ;
return - V_398 ;
}
V_35 = F_169 ( V_33 , V_512 -> V_519 ) ;
if ( V_35 == NULL ) {
F_231 ( L_11 ) ;
return - V_440 ;
}
if ( ! V_376 [ V_520 ] || F_162 ( V_376 [ V_520 ] ) != V_521 ) {
F_231 ( L_12 ) ;
return - V_398 ;
}
V_507 = F_111 ( V_376 [ V_520 ] ) ;
V_32 = F_237 ( V_376 [ V_522 ] , & V_508 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_197 ;
if ( ( ! V_512 -> V_517 || V_512 -> V_517 & V_531 ) &&
( V_35 -> V_532 & V_533 ) ) {
struct V_34 * V_534 = F_47 ( V_35 ) ;
const struct V_277 * V_25 = V_534 -> V_178 ;
V_32 = V_25 -> V_535 ( V_512 , V_376 , V_35 , V_507 , V_508 ,
V_82 -> V_486 ) ;
if ( V_32 )
goto V_71;
else
V_512 -> V_517 &= ~ V_531 ;
}
if ( ( V_512 -> V_517 & V_524 ) ) {
if ( V_35 -> V_178 -> V_535 )
V_32 = V_35 -> V_178 -> V_535 ( V_512 , V_376 , V_35 , V_507 ,
V_508 ,
V_82 -> V_486 ) ;
else
V_32 = F_230 ( V_512 , V_376 , V_35 , V_507 , V_508 ,
V_82 -> V_486 ) ;
if ( ! V_32 ) {
F_229 ( V_35 , V_507 , V_508 , V_536 ,
V_512 -> V_510 ) ;
V_512 -> V_517 &= ~ V_524 ;
}
}
V_71:
return V_32 ;
}
int F_240 ( struct V_511 * V_512 ,
struct V_47 * V_376 [] ,
struct V_34 * V_35 ,
const unsigned char * V_507 , T_10 V_508 )
{
int V_32 = - V_398 ;
if ( ! ( V_512 -> V_510 & V_526 ) ) {
F_231 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_232 ( V_507 ) || F_233 ( V_507 ) )
V_32 = F_241 ( V_35 , V_507 ) ;
else if ( F_235 ( V_507 ) )
V_32 = F_242 ( V_35 , V_507 ) ;
return V_32 ;
}
static int F_243 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_511 * V_512 ;
struct V_47 * V_376 [ V_530 + 1 ] ;
struct V_34 * V_35 ;
int V_32 = - V_398 ;
T_11 * V_507 ;
T_10 V_508 ;
if ( ! F_244 ( V_56 , V_433 ) )
return - V_434 ;
V_32 = F_149 ( V_82 , sizeof( * V_512 ) , V_376 , V_530 , NULL , V_428 ) ;
if ( V_32 < 0 )
return V_32 ;
V_512 = F_128 ( V_82 ) ;
if ( V_512 -> V_519 == 0 ) {
F_231 ( L_13 ) ;
return - V_398 ;
}
V_35 = F_169 ( V_33 , V_512 -> V_519 ) ;
if ( V_35 == NULL ) {
F_231 ( L_14 ) ;
return - V_440 ;
}
if ( ! V_376 [ V_520 ] || F_162 ( V_376 [ V_520 ] ) != V_521 ) {
F_231 ( L_15 ) ;
return - V_398 ;
}
V_507 = F_111 ( V_376 [ V_520 ] ) ;
V_32 = F_237 ( V_376 [ V_522 ] , & V_508 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_197 ;
if ( ( ! V_512 -> V_517 || V_512 -> V_517 & V_531 ) &&
( V_35 -> V_532 & V_533 ) ) {
struct V_34 * V_534 = F_47 ( V_35 ) ;
const struct V_277 * V_25 = V_534 -> V_178 ;
if ( V_25 -> V_537 )
V_32 = V_25 -> V_537 ( V_512 , V_376 , V_35 , V_507 , V_508 ) ;
if ( V_32 )
goto V_71;
else
V_512 -> V_517 &= ~ V_531 ;
}
if ( V_512 -> V_517 & V_524 ) {
if ( V_35 -> V_178 -> V_537 )
V_32 = V_35 -> V_178 -> V_537 ( V_512 , V_376 , V_35 , V_507 ,
V_508 ) ;
else
V_32 = F_240 ( V_512 , V_376 , V_35 , V_507 , V_508 ) ;
if ( ! V_32 ) {
F_229 ( V_35 , V_507 , V_508 , V_538 ,
V_512 -> V_510 ) ;
V_512 -> V_517 &= ~ V_524 ;
}
}
V_71:
return V_32 ;
}
static int F_245 ( struct V_2 * V_56 ,
struct V_368 * V_369 ,
struct V_34 * V_35 ,
int * V_373 ,
struct V_539 * V_30 )
{
struct V_540 * V_541 ;
int V_32 ;
T_5 V_389 , V_305 ;
V_389 = F_64 ( V_369 -> V_56 ) . V_389 ;
V_305 = V_369 -> V_82 -> V_390 ;
F_29 (ha, &list->list, list) {
if ( * V_373 < V_369 -> args [ 2 ] )
goto V_542;
V_32 = F_227 ( V_56 , V_35 , V_541 -> V_507 , 0 ,
V_389 , V_305 ,
V_536 , V_524 ,
V_378 , V_526 ) ;
if ( V_32 < 0 )
return V_32 ;
V_542:
* V_373 += 1 ;
}
return 0 ;
}
int F_246 ( struct V_2 * V_56 ,
struct V_368 * V_369 ,
struct V_34 * V_35 ,
struct V_34 * V_543 ,
int * V_373 )
{
int V_32 ;
F_247 ( V_35 ) ;
V_32 = F_245 ( V_56 , V_369 , V_35 , V_373 , & V_35 -> V_544 ) ;
if ( V_32 )
goto V_71;
V_32 = F_245 ( V_56 , V_369 , V_35 , V_373 , & V_35 -> V_545 ) ;
V_71:
F_248 ( V_35 ) ;
return V_32 ;
}
static int F_249 ( struct V_2 * V_56 , struct V_368 * V_369 )
{
struct V_34 * V_35 ;
struct V_47 * V_376 [ V_377 + 1 ] ;
struct V_34 * V_534 = NULL ;
const struct V_277 * V_25 = NULL ;
const struct V_277 * V_546 = NULL ;
struct V_126 * V_127 = F_128 ( V_369 -> V_82 ) ;
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_375 * V_3 ;
int V_547 = 0 ;
int V_548 = 0 ;
int V_371 , V_372 ;
int V_373 = 0 , V_374 ;
int V_32 = 0 ;
int V_549 = 0 ;
V_32 = F_149 ( V_369 -> V_82 , sizeof( struct V_126 ) , V_376 ,
V_377 , V_382 , NULL ) ;
if ( V_32 < 0 ) {
return - V_398 ;
} else if ( V_32 == 0 ) {
if ( V_376 [ V_336 ] )
V_548 = F_150 ( V_376 [ V_336 ] ) ;
}
V_547 = V_127 -> V_313 ;
if ( V_548 ) {
V_534 = F_169 ( V_33 , V_548 ) ;
if ( ! V_534 )
return - V_440 ;
V_25 = V_534 -> V_178 ;
}
V_372 = V_369 -> args [ 0 ] ;
V_374 = V_369 -> args [ 1 ] ;
for ( V_371 = V_372 ; V_371 < V_385 ; V_371 ++ , V_374 = 0 ) {
V_373 = 0 ;
V_3 = & V_33 -> V_386 [ V_371 ] ;
F_151 (dev, head, index_hlist) {
if ( V_547 && ( V_35 -> V_314 != V_547 ) )
continue;
if ( ! V_548 ) {
if ( V_35 -> V_532 & V_533 ) {
V_534 = F_47 ( V_35 ) ;
V_546 = V_534 -> V_178 ;
}
} else {
if ( V_35 != V_534 &&
! ( V_35 -> V_532 & V_533 ) )
continue;
if ( V_534 != F_47 ( V_35 ) &&
! ( V_35 -> V_532 & V_550 ) )
continue;
V_546 = V_25 ;
}
if ( V_373 < V_374 )
goto V_387;
if ( V_35 -> V_532 & V_533 ) {
if ( V_546 && V_546 -> V_551 ) {
V_32 = V_546 -> V_551 ( V_56 , V_369 ,
V_534 , V_35 ,
& V_549 ) ;
if ( V_32 == - V_59 )
goto V_71;
}
}
if ( V_35 -> V_178 -> V_551 )
V_32 = V_35 -> V_178 -> V_551 ( V_56 , V_369 ,
V_35 , NULL ,
& V_549 ) ;
else
V_32 = F_246 ( V_56 , V_369 , V_35 , NULL ,
& V_549 ) ;
if ( V_32 == - V_59 )
goto V_71;
V_546 = NULL ;
V_369 -> args [ 2 ] = 0 ;
V_549 = 0 ;
V_387:
V_373 ++ ;
}
}
V_71:
V_369 -> args [ 0 ] = V_371 ;
V_369 -> args [ 1 ] = V_373 ;
V_369 -> args [ 2 ] = V_549 ;
return V_56 -> V_391 ;
}
static int F_250 ( struct V_2 * V_56 , T_5 V_83 , T_5 V_552 ,
unsigned int V_553 , unsigned int V_554 )
{
if ( V_552 & V_554 )
return F_124 ( V_56 , V_553 , ! ! ( V_83 & V_554 ) ) ;
return 0 ;
}
int F_251 ( struct V_2 * V_56 , T_5 V_73 , T_5 V_305 ,
struct V_34 * V_35 , T_10 V_555 ,
T_5 V_83 , T_5 V_552 , int V_509 ,
T_5 V_556 ,
int (* F_252)( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_5 V_556 ) )
{
struct V_81 * V_82 ;
struct V_126 * V_127 ;
struct V_47 * V_557 ;
struct V_47 * V_558 ;
T_9 V_118 = F_130 ( V_35 ) ? V_35 -> V_118 : V_319 ;
struct V_34 * V_534 = F_47 ( V_35 ) ;
int V_32 = 0 ;
V_82 = F_127 ( V_56 , V_73 , V_305 , V_388 , sizeof( * V_127 ) , V_509 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_128 ( V_82 ) ;
V_127 -> V_309 = V_514 ;
V_127 -> V_311 = 0 ;
V_127 -> V_312 = V_35 -> type ;
V_127 -> V_313 = V_35 -> V_314 ;
V_127 -> V_128 = F_129 ( V_35 ) ;
V_127 -> V_129 = 0 ;
if ( F_57 ( V_56 , V_315 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_322 , V_35 -> V_323 ) ||
F_124 ( V_56 , V_318 , V_118 ) ||
( V_534 &&
F_78 ( V_56 , V_336 , V_534 -> V_314 ) ) ||
( V_35 -> V_347 &&
F_84 ( V_56 , V_348 , V_35 -> V_347 , V_35 -> V_349 ) ) ||
( V_35 -> V_314 != F_132 ( V_35 ) &&
F_78 ( V_56 , V_335 , F_132 ( V_35 ) ) ) )
goto V_95;
V_557 = F_58 ( V_56 , V_356 ) ;
if ( ! V_557 )
goto V_95;
if ( F_253 ( V_56 , V_559 , V_560 ) ) {
F_60 ( V_56 , V_557 ) ;
goto V_95;
}
if ( V_555 != V_561 ) {
if ( F_253 ( V_56 , V_562 , V_555 ) ) {
F_60 ( V_56 , V_557 ) ;
goto V_95;
}
}
if ( F_252 ) {
V_32 = F_252 ( V_56 , V_35 , V_556 ) ;
if ( V_32 ) {
F_60 ( V_56 , V_557 ) ;
goto V_95;
}
}
F_59 ( V_56 , V_557 ) ;
V_558 = F_58 ( V_56 , V_492 | V_563 ) ;
if ( ! V_558 )
goto V_95;
if ( F_250 ( V_56 , V_83 , V_552 ,
V_564 , V_565 ) ||
F_250 ( V_56 , V_83 , V_552 ,
V_566 , V_567 ) ||
F_250 ( V_56 , V_83 , V_552 ,
V_568 ,
V_569 ) ||
F_250 ( V_56 , V_83 , V_552 ,
V_570 , V_571 ) ||
F_250 ( V_56 , V_83 , V_552 ,
V_572 , V_573 ) ||
F_250 ( V_56 , V_83 , V_552 ,
V_574 , V_575 ) ||
F_250 ( V_56 , V_83 , V_552 ,
V_576 , V_577 ) ||
F_250 ( V_56 , V_83 , V_552 ,
V_578 , V_579 ) ) {
F_60 ( V_56 , V_558 ) ;
goto V_95;
}
F_59 ( V_56 , V_558 ) ;
F_138 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_139 ( V_56 , V_82 ) ;
return V_32 ? V_32 : - V_59 ;
}
static int F_254 ( struct V_2 * V_56 , struct V_368 * V_369 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_34 * V_35 ;
int V_373 = 0 ;
T_5 V_389 = F_64 ( V_369 -> V_56 ) . V_389 ;
T_5 V_305 = V_369 -> V_82 -> V_390 ;
T_5 V_556 = 0 ;
int V_32 ;
if ( F_148 ( V_369 -> V_82 ) > sizeof( struct V_126 ) ) {
struct V_47 * V_580 ;
V_580 = F_255 ( V_369 -> V_82 , sizeof( struct V_126 ) ,
V_383 ) ;
if ( V_580 ) {
if ( F_162 ( V_580 ) < sizeof( V_556 ) )
return - V_398 ;
V_556 = F_150 ( V_580 ) ;
}
}
F_256 () ;
F_257 (net, dev) {
const struct V_277 * V_25 = V_35 -> V_178 ;
struct V_34 * V_534 = F_47 ( V_35 ) ;
if ( V_534 && V_534 -> V_178 -> V_581 ) {
if ( V_373 >= V_369 -> args [ 0 ] ) {
V_32 = V_534 -> V_178 -> V_581 (
V_56 , V_389 , V_305 , V_35 ,
V_556 , V_378 ) ;
if ( V_32 < 0 && V_32 != - V_197 ) {
if ( F_152 ( V_56 -> V_391 ) )
break;
goto V_392;
}
}
V_373 ++ ;
}
if ( V_25 -> V_581 ) {
if ( V_373 >= V_369 -> args [ 0 ] ) {
V_32 = V_25 -> V_581 ( V_56 , V_389 ,
V_305 , V_35 ,
V_556 ,
V_378 ) ;
if ( V_32 < 0 && V_32 != - V_197 ) {
if ( F_152 ( V_56 -> V_391 ) )
break;
goto V_392;
}
}
V_373 ++ ;
}
}
V_32 = V_56 -> V_391 ;
V_392:
F_258 () ;
V_369 -> args [ 0 ] = V_373 ;
return V_32 ;
}
static inline T_4 F_259 ( void )
{
return F_99 ( sizeof( struct V_126 ) )
+ F_48 ( V_181 )
+ F_48 ( V_184 )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_9 ) )
+ F_48 ( sizeof( struct V_47 ) )
+ F_48 ( sizeof( T_10 ) )
+ F_48 ( sizeof( T_10 ) ) ;
}
static int F_260 ( struct V_34 * V_35 )
{
struct V_33 * V_33 = F_135 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_197 ;
if ( ! V_35 -> V_178 -> V_581 )
return 0 ;
V_56 = F_218 ( F_259 () , V_523 ) ;
if ( ! V_56 ) {
V_32 = - V_445 ;
goto V_431;
}
V_32 = V_35 -> V_178 -> V_581 ( V_56 , 0 , 0 , V_35 , 0 , 0 ) ;
if ( V_32 < 0 )
goto V_431;
if ( ! V_56 -> V_391 )
goto V_431;
F_70 ( V_56 , V_33 , 0 , V_505 , NULL , V_523 ) ;
return 0 ;
V_431:
F_219 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
if ( V_32 )
F_73 ( V_33 , V_505 , V_32 ) ;
return V_32 ;
}
static int F_261 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_582 , * V_202 = NULL ;
int V_399 , V_32 = - V_197 ;
T_10 V_83 = 0 ;
bool V_583 = false ;
if ( F_148 ( V_82 ) < sizeof( * V_127 ) )
return - V_398 ;
V_127 = F_128 ( V_82 ) ;
if ( V_127 -> V_309 != V_514 )
return - V_584 ;
V_35 = F_169 ( V_33 , V_127 -> V_313 ) ;
if ( ! V_35 ) {
F_231 ( L_16 ) ;
return - V_440 ;
}
V_582 = F_255 ( V_82 , sizeof( struct V_126 ) , V_356 ) ;
if ( V_582 ) {
F_163 (attr, br_spec, rem) {
if ( F_164 ( V_202 ) == V_559 ) {
if ( F_162 ( V_202 ) < sizeof( V_83 ) )
return - V_398 ;
V_583 = true ;
V_83 = F_238 ( V_202 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_585 ) ) {
struct V_34 * V_534 = F_47 ( V_35 ) ;
if ( ! V_534 || ! V_534 -> V_178 -> V_586 ) {
V_32 = - V_197 ;
goto V_71;
}
V_32 = V_534 -> V_178 -> V_586 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_585 ;
}
if ( ( V_83 & V_560 ) ) {
if ( ! V_35 -> V_178 -> V_586 )
V_32 = - V_197 ;
else
V_32 = V_35 -> V_178 -> V_586 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_560 ;
V_32 = F_260 ( V_35 ) ;
}
}
if ( V_583 )
memcpy ( F_111 ( V_202 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static int F_262 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_582 , * V_202 = NULL ;
int V_399 , V_32 = - V_197 ;
T_10 V_83 = 0 ;
bool V_583 = false ;
if ( F_148 ( V_82 ) < sizeof( * V_127 ) )
return - V_398 ;
V_127 = F_128 ( V_82 ) ;
if ( V_127 -> V_309 != V_514 )
return - V_584 ;
V_35 = F_169 ( V_33 , V_127 -> V_313 ) ;
if ( ! V_35 ) {
F_231 ( L_16 ) ;
return - V_440 ;
}
V_582 = F_255 ( V_82 , sizeof( struct V_126 ) , V_356 ) ;
if ( V_582 ) {
F_163 (attr, br_spec, rem) {
if ( F_164 ( V_202 ) == V_559 ) {
if ( F_162 ( V_202 ) < sizeof( V_83 ) )
return - V_398 ;
V_583 = true ;
V_83 = F_238 ( V_202 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_585 ) ) {
struct V_34 * V_534 = F_47 ( V_35 ) ;
if ( ! V_534 || ! V_534 -> V_178 -> V_587 ) {
V_32 = - V_197 ;
goto V_71;
}
V_32 = V_534 -> V_178 -> V_587 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_585 ;
}
if ( ( V_83 & V_560 ) ) {
if ( ! V_35 -> V_178 -> V_587 )
V_32 = - V_197 ;
else
V_32 = V_35 -> V_178 -> V_587 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_560 ;
V_32 = F_260 ( V_35 ) ;
}
}
if ( V_583 )
memcpy ( F_111 ( V_202 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static bool F_263 ( unsigned int V_552 , int V_588 , int V_589 )
{
return ( V_552 & F_264 ( V_588 ) ) &&
( ! V_589 || V_589 == V_588 ) ;
}
static int F_265 ( int V_590 )
{
switch ( V_590 ) {
case V_591 :
return sizeof( struct V_132 ) ;
}
return 0 ;
}
static int F_266 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int * V_592 )
{
struct V_47 * V_202 = NULL ;
int V_590 , V_48 ;
void * V_593 ;
int V_32 ;
if ( ! ( V_35 -> V_178 && V_35 -> V_178 -> V_594 &&
V_35 -> V_178 -> V_595 ) )
return - V_359 ;
for ( V_590 = V_596 ;
V_590 <= V_597 ; V_590 ++ ) {
if ( V_590 < * V_592 )
continue;
V_48 = F_265 ( V_590 ) ;
if ( ! V_48 )
continue;
if ( ! V_35 -> V_178 -> V_594 ( V_35 , V_590 ) )
continue;
V_202 = F_110 ( V_56 , V_590 , V_48 ,
V_598 ) ;
if ( ! V_202 )
goto V_95;
V_593 = F_111 ( V_202 ) ;
memset ( V_593 , 0 , V_48 ) ;
V_32 = V_35 -> V_178 -> V_595 ( V_590 , V_35 ,
V_593 ) ;
if ( V_32 )
goto V_599;
}
if ( ! V_202 )
return - V_359 ;
* V_592 = 0 ;
return 0 ;
V_95:
V_32 = - V_59 ;
V_599:
* V_592 = V_590 ;
return V_32 ;
}
static int F_267 ( const struct V_34 * V_35 )
{
int V_600 = 0 ;
int V_590 ;
int V_48 ;
if ( ! ( V_35 -> V_178 && V_35 -> V_178 -> V_594 &&
V_35 -> V_178 -> V_595 ) )
return 0 ;
for ( V_590 = V_596 ;
V_590 <= V_597 ; V_590 ++ ) {
if ( ! V_35 -> V_178 -> V_594 ( V_35 , V_590 ) )
continue;
V_48 = F_265 ( V_590 ) ;
V_600 += F_95 ( V_48 ) ;
}
if ( V_600 != 0 )
V_600 += F_48 ( 0 ) ;
return V_600 ;
}
static int F_268 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_305 , T_5 V_306 ,
unsigned int V_83 , unsigned int V_556 ,
int * V_589 , int * V_592 )
{
struct V_601 * V_602 ;
struct V_81 * V_82 ;
struct V_47 * V_202 ;
int V_603 = * V_592 ;
int V_32 ;
F_120 () ;
V_82 = F_127 ( V_56 , V_73 , V_305 , type , sizeof( * V_602 ) , V_83 ) ;
if ( ! V_82 )
return - V_59 ;
V_602 = F_128 ( V_82 ) ;
V_602 -> V_314 = V_35 -> V_314 ;
V_602 -> V_556 = V_556 ;
if ( F_263 ( V_556 , V_604 , * V_589 ) ) {
struct V_132 * V_208 ;
V_202 = F_110 ( V_56 , V_604 ,
sizeof( struct V_132 ) ,
V_605 ) ;
if ( ! V_202 )
goto V_95;
V_208 = F_111 ( V_202 ) ;
F_112 ( V_35 , V_208 ) ;
}
if ( F_263 ( V_556 , V_606 , * V_589 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
if ( V_25 && V_25 -> V_607 ) {
* V_589 = V_606 ;
V_202 = F_58 ( V_56 ,
V_606 ) ;
if ( ! V_202 )
goto V_95;
V_32 = V_25 -> V_607 ( V_56 , V_35 , V_592 , * V_589 ) ;
F_59 ( V_56 , V_202 ) ;
if ( V_32 )
goto V_95;
* V_589 = 0 ;
}
}
if ( F_263 ( V_556 , V_608 ,
* V_589 ) ) {
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_366 ;
V_366 = F_47 ( V_35 ) ;
if ( V_366 )
V_25 = V_366 -> V_23 ;
if ( V_25 && V_25 -> V_607 ) {
* V_589 = V_608 ;
V_202 = F_58 ( V_56 ,
V_608 ) ;
if ( ! V_202 )
goto V_95;
V_32 = V_25 -> V_607 ( V_56 , V_35 , V_592 , * V_589 ) ;
F_59 ( V_56 , V_202 ) ;
if ( V_32 )
goto V_95;
* V_589 = 0 ;
}
}
if ( F_263 ( V_556 , V_609 ,
* V_589 ) ) {
* V_589 = V_609 ;
V_202 = F_58 ( V_56 , V_609 ) ;
if ( ! V_202 )
goto V_95;
V_32 = F_266 ( V_56 , V_35 , V_592 ) ;
if ( V_32 == - V_359 )
F_60 ( V_56 , V_202 ) ;
else
F_59 ( V_56 , V_202 ) ;
if ( V_32 && V_32 != - V_359 )
goto V_95;
* V_589 = 0 ;
}
if ( F_263 ( V_556 , V_610 , * V_589 ) ) {
struct V_51 * V_54 ;
* V_589 = V_610 ;
V_202 = F_58 ( V_56 , V_610 ) ;
if ( ! V_202 )
goto V_95;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_611 ) {
struct V_47 * V_358 ;
int V_32 ;
V_358 = F_58 ( V_56 , V_54 -> V_52 ) ;
if ( ! V_358 )
goto V_95;
V_32 = V_54 -> V_611 ( V_56 , V_35 ) ;
if ( V_32 == - V_359 )
F_60 ( V_56 , V_358 ) ;
else if ( V_32 < 0 )
goto V_95;
F_59 ( V_56 , V_358 ) ;
}
}
F_59 ( V_56 , V_202 ) ;
* V_589 = 0 ;
}
F_138 ( V_56 , V_82 ) ;
return 0 ;
V_95:
if ( ! ( V_83 & V_378 ) || V_603 == * V_592 )
F_139 ( V_56 , V_82 ) ;
else
F_138 ( V_56 , V_82 ) ;
return - V_59 ;
}
static T_4 F_269 ( const struct V_34 * V_35 ,
T_5 V_556 )
{
T_4 V_48 = 0 ;
if ( F_263 ( V_556 , V_604 , 0 ) )
V_48 += F_95 ( sizeof( struct V_132 ) ) ;
if ( F_263 ( V_556 , V_606 , 0 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
int V_202 = V_606 ;
if ( V_25 && V_25 -> V_612 ) {
V_48 += F_48 ( V_25 -> V_612 ( V_35 ,
V_202 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
if ( F_263 ( V_556 , V_608 , 0 ) ) {
struct V_34 * V_613 = (struct V_34 * ) V_35 ;
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_366 ;
V_366 = F_47 ( V_613 ) ;
if ( V_366 )
V_25 = V_366 -> V_23 ;
if ( V_25 && V_25 -> V_612 ) {
int V_202 = V_608 ;
V_48 += F_48 ( V_25 -> V_612 ( V_35 ,
V_202 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
if ( F_263 ( V_556 , V_609 , 0 ) )
V_48 += F_267 ( V_35 ) ;
if ( F_263 ( V_556 , V_610 , 0 ) ) {
struct V_51 * V_54 ;
V_48 += F_48 ( 0 ) ;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_614 ) {
V_48 += F_48 (
V_54 -> V_614 ( V_35 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
}
return V_48 ;
}
static int F_270 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
struct V_34 * V_35 = NULL ;
int V_589 = 0 , V_592 = 0 ;
struct V_601 * V_602 ;
struct V_2 * V_498 ;
T_5 V_556 ;
int V_32 ;
if ( F_148 ( V_82 ) < sizeof( * V_602 ) )
return - V_398 ;
V_602 = F_128 ( V_82 ) ;
if ( V_602 -> V_314 > 0 )
V_35 = F_169 ( V_33 , V_602 -> V_314 ) ;
else
return - V_398 ;
if ( ! V_35 )
return - V_440 ;
V_556 = V_602 -> V_556 ;
if ( ! V_556 )
return - V_398 ;
V_498 = F_218 ( F_269 ( V_35 , V_556 ) , V_20 ) ;
if ( ! V_498 )
return - V_21 ;
V_32 = F_268 ( V_498 , V_35 , V_615 ,
F_64 ( V_56 ) . V_389 , V_82 -> V_390 , 0 ,
0 , V_556 , & V_589 , & V_592 ) ;
if ( V_32 < 0 ) {
F_219 ( V_32 == - V_59 ) ;
F_6 ( V_498 ) ;
} else {
V_32 = F_68 ( V_498 , V_33 , F_64 ( V_56 ) . V_389 ) ;
}
return V_32 ;
}
static int F_271 ( struct V_2 * V_56 , struct V_368 * V_369 )
{
int V_371 , V_372 , V_32 , V_374 , V_616 , V_603 ;
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
unsigned int V_83 = V_378 ;
struct V_601 * V_602 ;
struct V_375 * V_3 ;
struct V_34 * V_35 ;
T_5 V_556 = 0 ;
int V_373 = 0 ;
V_372 = V_369 -> args [ 0 ] ;
V_374 = V_369 -> args [ 1 ] ;
V_616 = V_369 -> args [ 2 ] ;
V_603 = V_369 -> args [ 3 ] ;
V_369 -> V_305 = V_33 -> V_380 ;
if ( F_148 ( V_369 -> V_82 ) < sizeof( * V_602 ) )
return - V_398 ;
V_602 = F_128 ( V_369 -> V_82 ) ;
V_556 = V_602 -> V_556 ;
if ( ! V_556 )
return - V_398 ;
for ( V_371 = V_372 ; V_371 < V_385 ; V_371 ++ , V_374 = 0 ) {
V_373 = 0 ;
V_3 = & V_33 -> V_386 [ V_371 ] ;
F_151 (dev, head, index_hlist) {
if ( V_373 < V_374 )
goto V_387;
V_32 = F_268 ( V_56 , V_35 , V_615 ,
F_64 ( V_369 -> V_56 ) . V_389 ,
V_369 -> V_82 -> V_390 , 0 ,
V_83 , V_556 ,
& V_616 , & V_603 ) ;
F_219 ( ( V_32 == - V_59 ) && ( V_56 -> V_391 == 0 ) ) ;
if ( V_32 < 0 )
goto V_71;
V_603 = 0 ;
V_616 = 0 ;
F_153 ( V_369 , F_154 ( V_56 ) ) ;
V_387:
V_373 ++ ;
}
}
V_71:
V_369 -> args [ 3 ] = V_603 ;
V_369 -> args [ 2 ] = V_616 ;
V_369 -> args [ 1 ] = V_373 ;
V_369 -> args [ 0 ] = V_371 ;
return V_56 -> V_391 ;
}
static int F_272 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_393 * V_428 )
{
struct V_33 * V_33 = F_147 ( V_56 -> V_370 ) ;
T_1 V_16 ;
int V_24 ;
int V_52 ;
int type ;
int V_32 ;
type = V_82 -> V_501 ;
if ( type > V_617 )
return - V_197 ;
type -= V_9 ;
if ( F_148 ( V_82 ) < sizeof( struct V_381 ) )
return 0 ;
V_52 = ( (struct V_381 * ) F_128 ( V_82 ) ) -> V_618 ;
V_24 = type & 3 ;
if ( V_24 != 2 && ! F_273 ( V_56 , V_433 ) )
return - V_434 ;
if ( V_24 == 2 && V_82 -> V_486 & V_619 ) {
struct V_76 * V_77 ;
T_2 V_18 ;
T_3 V_19 ;
T_10 V_620 = 0 ;
V_18 = F_19 ( V_52 , type ) ;
if ( V_18 == NULL )
return - V_197 ;
V_19 = F_20 ( V_52 , type ) ;
if ( V_19 )
V_620 = V_19 ( V_56 , V_82 ) ;
F_4 () ;
V_77 = V_33 -> V_77 ;
{
struct V_621 V_622 = {
. V_623 = V_18 ,
. V_620 = V_620 ,
} ;
V_32 = F_274 ( V_77 , V_56 , V_82 , & V_622 ) ;
}
F_1 () ;
return V_32 ;
}
V_16 = F_18 ( V_52 , type ) ;
if ( V_16 == NULL )
return - V_197 ;
return V_16 ( V_56 , V_82 , V_428 ) ;
}
static void F_275 ( struct V_2 * V_56 )
{
F_1 () ;
F_276 ( V_56 , & F_272 ) ;
F_8 () ;
}
static int F_277 ( struct V_33 * V_33 , int V_74 )
{
switch ( V_74 ) {
case V_624 :
case V_625 :
if ( ! F_278 ( V_33 -> V_432 , V_433 ) )
return - V_434 ;
break;
}
return 0 ;
}
static int F_279 ( struct V_626 * V_627 , unsigned long V_290 , void * V_628 )
{
struct V_34 * V_35 = F_280 ( V_628 ) ;
switch ( V_290 ) {
case V_293 :
case V_448 :
case V_629 :
case V_295 :
case V_297 :
case V_299 :
case V_301 :
case V_303 :
F_225 ( V_388 , V_35 , 0 , F_125 ( V_290 ) ,
V_20 ) ;
break;
default:
break;
}
return V_630 ;
}
static int T_12 F_281 ( struct V_33 * V_33 )
{
struct V_76 * V_370 ;
struct V_631 V_632 = {
. V_633 = V_634 ,
. V_635 = F_275 ,
. V_636 = & V_1 ,
. V_83 = V_637 ,
. V_638 = F_277 ,
} ;
V_370 = F_282 ( V_33 , V_639 , & V_632 ) ;
if ( ! V_370 )
return - V_445 ;
V_33 -> V_77 = V_370 ;
return 0 ;
}
static void T_13 F_283 ( struct V_33 * V_33 )
{
F_284 ( V_33 -> V_77 ) ;
V_33 -> V_77 = NULL ;
}
void T_14 F_285 ( void )
{
if ( F_286 ( & V_640 ) )
F_24 ( L_17 ) ;
F_287 ( & V_641 ) ;
F_23 ( V_17 , V_642 , F_217 ,
F_146 , F_220 ) ;
F_23 ( V_17 , V_643 , F_196 , NULL , NULL ) ;
F_23 ( V_17 , V_388 , F_210 , NULL , NULL ) ;
F_23 ( V_17 , V_644 , F_201 , NULL , NULL ) ;
F_23 ( V_17 , V_645 , NULL , F_222 , NULL ) ;
F_23 ( V_17 , V_646 , NULL , F_222 , NULL ) ;
F_23 ( V_17 , V_647 , NULL , F_222 , NULL ) ;
F_23 ( V_648 , V_536 , F_239 , NULL , NULL ) ;
F_23 ( V_648 , V_538 , F_243 , NULL , NULL ) ;
F_23 ( V_648 , V_649 , NULL , F_249 , NULL ) ;
F_23 ( V_648 , V_642 , NULL , F_254 , NULL ) ;
F_23 ( V_648 , V_644 , F_262 , NULL , NULL ) ;
F_23 ( V_648 , V_643 , F_261 , NULL , NULL ) ;
F_23 ( V_17 , V_650 , F_270 , F_271 ,
NULL ) ;
}
