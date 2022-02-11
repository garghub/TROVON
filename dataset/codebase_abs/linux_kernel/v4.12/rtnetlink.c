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
F_48 ( 1 ) ;
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
static T_9 F_119 ( struct V_34 * V_35 )
{
const struct V_276 * V_25 = V_35 -> V_178 ;
F_120 () ;
if ( F_121 ( V_35 -> V_277 ) )
return V_278 ;
if ( V_25 -> V_279 && F_122 ( V_35 , V_25 -> V_279 ) )
return V_280 ;
return V_281 ;
}
static int F_123 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_282 ;
int V_32 ;
V_282 = F_58 ( V_56 , V_283 ) ;
if ( ! V_282 )
return - V_59 ;
V_32 = F_124 ( V_56 , V_284 ,
F_119 ( V_35 ) ) ;
if ( V_32 )
goto V_285;
F_59 ( V_56 , V_282 ) ;
return 0 ;
V_285:
F_60 ( V_56 , V_282 ) ;
return V_32 ;
}
static int F_125 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_286 , T_5 V_287 ,
unsigned int V_83 , T_5 V_53 )
{
struct V_126 * V_127 ;
struct V_81 * V_82 ;
struct V_47 * V_288 ;
struct V_51 * V_54 ;
struct V_34 * V_289 = F_47 ( V_35 ) ;
F_120 () ;
V_82 = F_126 ( V_56 , V_73 , V_286 , type , sizeof( * V_127 ) , V_83 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_127 ( V_82 ) ;
V_127 -> V_290 = V_291 ;
V_127 -> V_292 = 0 ;
V_127 -> V_293 = V_35 -> type ;
V_127 -> V_294 = V_35 -> V_295 ;
V_127 -> V_128 = F_128 ( V_35 ) ;
V_127 -> V_129 = V_287 ;
if ( F_57 ( V_56 , V_296 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_297 , V_35 -> V_298 ) ||
F_124 ( V_56 , V_299 ,
F_129 ( V_35 ) ? V_35 -> V_118 : V_300 ) ||
F_124 ( V_56 , V_301 , V_35 -> V_302 ) ||
F_78 ( V_56 , V_303 , V_35 -> V_304 ) ||
F_78 ( V_56 , V_305 , V_35 -> V_74 ) ||
F_78 ( V_56 , V_306 , V_35 -> V_307 ) ||
F_78 ( V_56 , V_308 , V_35 -> V_309 ) ||
F_78 ( V_56 , V_310 , V_35 -> V_311 ) ||
F_78 ( V_56 , V_312 , V_35 -> V_313 ) ||
#ifdef F_130
F_78 ( V_56 , V_314 , V_35 -> V_315 ) ||
#endif
( V_35 -> V_295 != F_131 ( V_35 ) &&
F_78 ( V_56 , V_316 , F_131 ( V_35 ) ) ) ||
( V_289 &&
F_78 ( V_56 , V_317 , V_289 -> V_295 ) ) ||
F_124 ( V_56 , V_318 , F_132 ( V_35 ) ) ||
( V_35 -> V_319 &&
F_57 ( V_56 , V_320 , V_35 -> V_319 -> V_25 -> V_102 ) ) ||
( V_35 -> V_321 &&
F_57 ( V_56 , V_322 , V_35 -> V_321 ) ) ||
F_78 ( V_56 , V_323 ,
F_81 ( & V_35 -> V_324 ) ) ||
F_124 ( V_56 , V_325 , V_35 -> V_326 ) )
goto V_95;
if ( F_117 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_327 ) {
if ( F_84 ( V_56 , V_328 , V_35 -> V_327 , V_35 -> V_329 ) ||
F_84 ( V_56 , V_330 , V_35 -> V_327 , V_35 -> V_265 ) )
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
if ( V_35 -> V_178 -> V_235 && V_35 -> V_35 . V_158 &&
V_53 & V_159 ) {
int V_87 ;
struct V_47 * V_213 ;
int V_160 = F_94 ( V_35 -> V_35 . V_158 ) ;
V_213 = F_58 ( V_56 , V_332 ) ;
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
V_35 -> V_23 -> V_333 ) {
struct V_33 * V_334 = V_35 -> V_23 -> V_333 ( V_35 ) ;
if ( ! F_133 ( F_134 ( V_35 ) , V_334 ) ) {
int V_102 = F_135 ( F_134 ( V_35 ) , V_334 ) ;
if ( F_136 ( V_56 , V_335 , V_102 ) )
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
F_137 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_138 ( V_56 , V_82 ) ;
return - V_59 ;
}
static const struct V_23 * F_139 ( const struct V_47 * V_340 )
{
const struct V_23 * V_25 = NULL ;
struct V_47 * V_341 [ V_342 + 1 ] ;
if ( F_140 ( V_341 , V_342 , V_340 ,
V_343 , NULL ) < 0 )
return NULL ;
if ( V_341 [ V_64 ] ) {
char V_24 [ V_344 ] ;
F_141 ( V_24 , V_341 [ V_64 ] , sizeof( V_24 ) ) ;
V_25 = F_28 ( V_24 ) ;
}
return V_25 ;
}
static bool F_142 ( struct V_34 * V_35 , int V_345 )
{
struct V_34 * V_346 ;
if ( ! V_345 )
return false ;
V_346 = F_47 ( V_35 ) ;
if ( ! V_346 || V_346 -> V_295 != V_345 )
return true ;
return false ;
}
static bool F_143 ( const struct V_34 * V_35 ,
const struct V_23 * V_347 )
{
if ( V_347 && V_35 -> V_23 != V_347 )
return true ;
return false ;
}
static bool F_144 ( struct V_34 * V_35 ,
int V_345 ,
const struct V_23 * V_347 )
{
if ( F_142 ( V_35 , V_345 ) ||
F_143 ( V_35 , V_347 ) )
return true ;
return false ;
}
static int F_145 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
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
V_359 = F_147 ( V_349 -> V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_361 ) : sizeof( struct V_126 ) ;
if ( F_148 ( V_349 -> V_82 , V_359 , V_356 , V_357 ,
V_362 , NULL ) >= 0 ) {
if ( V_356 [ V_363 ] )
V_53 = F_149 ( V_356 [ V_363 ] ) ;
if ( V_356 [ V_317 ] )
V_345 = F_149 ( V_356 [ V_317 ] ) ;
if ( V_356 [ V_70 ] )
V_347 = F_139 ( V_356 [ V_70 ] ) ;
if ( V_345 || V_347 )
V_83 |= V_364 ;
}
for ( V_351 = V_352 ; V_351 < V_365 ; V_351 ++ , V_354 = 0 ) {
V_353 = 0 ;
V_3 = & V_33 -> V_366 [ V_351 ] ;
F_150 (dev, head, index_hlist) {
if ( F_144 ( V_35 , V_345 , V_347 ) )
goto V_367;
if ( V_353 < V_354 )
goto V_367;
V_32 = F_125 ( V_56 , V_35 , V_368 ,
F_64 ( V_349 -> V_56 ) . V_369 ,
V_349 -> V_82 -> V_370 , 0 ,
V_83 ,
V_53 ) ;
if ( V_32 < 0 ) {
if ( F_151 ( V_56 -> V_371 ) )
goto V_71;
goto V_372;
}
F_152 ( V_349 , F_153 ( V_56 ) ) ;
V_367:
V_353 ++ ;
}
}
V_71:
V_32 = V_56 -> V_371 ;
V_372:
V_349 -> args [ 1 ] = V_353 ;
V_349 -> args [ 0 ] = V_351 ;
return V_32 ;
}
int F_154 ( struct V_47 * * V_356 , const struct V_47 * V_3 , int V_371 ,
struct V_373 * V_374 )
{
return F_155 ( V_356 , V_357 , V_3 , V_371 , V_362 , V_374 ) ;
}
struct V_33 * F_156 ( struct V_33 * V_375 , struct V_47 * V_356 [] )
{
struct V_33 * V_33 ;
if ( V_356 [ V_376 ] )
V_33 = F_157 ( F_149 ( V_356 [ V_376 ] ) ) ;
else if ( V_356 [ V_377 ] )
V_33 = F_158 ( F_149 ( V_356 [ V_377 ] ) ) ;
else
V_33 = F_159 ( V_375 ) ;
return V_33 ;
}
static int F_160 ( struct V_34 * V_35 , struct V_47 * V_356 [] )
{
if ( V_35 ) {
if ( V_356 [ V_328 ] &&
F_161 ( V_356 [ V_328 ] ) < V_35 -> V_327 )
return - V_378 ;
if ( V_356 [ V_330 ] &&
F_161 ( V_356 [ V_330 ] ) < V_35 -> V_327 )
return - V_378 ;
}
if ( V_356 [ V_336 ] ) {
struct V_47 * V_338 ;
int V_379 , V_32 ;
F_162 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_163 ( V_338 ) ) ) )
return - V_380 ;
if ( ! V_54 -> V_381 )
return - V_197 ;
if ( V_54 -> V_382 ) {
V_32 = V_54 -> V_382 ( V_35 , V_338 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
}
return 0 ;
}
static int F_164 ( struct V_34 * V_35 , struct V_383 * V_384 ,
int V_385 )
{
const struct V_276 * V_25 = V_35 -> V_178 ;
return V_25 -> V_386 ( V_35 , V_384 -> V_188 , V_384 -> V_387 , V_385 ) ;
}
static int F_165 ( struct V_34 * V_35 , struct V_383 * V_384 , int V_385 )
{
if ( V_35 -> type != V_388 )
return - V_197 ;
return F_164 ( V_35 , V_384 , V_385 ) ;
}
static int F_166 ( struct V_34 * V_35 , struct V_47 * * V_356 )
{
const struct V_276 * V_25 = V_35 -> V_178 ;
int V_32 = - V_378 ;
if ( V_356 [ V_246 ] ) {
struct V_161 * V_389 = F_111 ( V_356 [ V_246 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_390 )
V_32 = V_25 -> V_390 ( V_35 , V_389 -> V_188 ,
V_389 -> V_236 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_247 ] ) {
struct V_162 * V_391 = F_111 ( V_356 [ V_247 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_392 )
V_32 = V_25 -> V_392 ( V_35 , V_391 -> V_188 , V_391 -> V_237 ,
V_391 -> V_238 ,
F_115 ( V_234 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_255 ] ) {
struct V_164 * V_393 [ V_163 ] ;
struct V_47 * V_202 ;
int V_379 , V_371 = 0 ;
V_32 = - V_197 ;
if ( ! V_25 -> V_392 )
return V_32 ;
F_162 (attr, tb[IFLA_VF_VLAN_LIST], rem) {
if ( F_163 ( V_202 ) != V_256 ||
F_161 ( V_202 ) < V_394 ) {
return - V_378 ;
}
if ( V_371 >= V_163 )
return - V_197 ;
V_393 [ V_371 ] = F_111 ( V_202 ) ;
V_371 ++ ;
}
if ( V_371 == 0 )
return - V_378 ;
V_32 = V_25 -> V_392 ( V_35 , V_393 [ 0 ] -> V_188 , V_393 [ 0 ] -> V_237 ,
V_393 [ 0 ] -> V_238 , V_393 [ 0 ] -> V_233 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_249 ] ) {
struct V_166 * V_384 = F_111 ( V_356 [ V_249 ] ) ;
struct V_227 V_395 ;
V_32 = - V_197 ;
if ( V_25 -> V_235 )
V_32 = V_25 -> V_235 ( V_35 , V_384 -> V_188 , & V_395 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = - V_197 ;
if ( V_25 -> V_396 )
V_32 = V_25 -> V_396 ( V_35 , V_384 -> V_188 ,
V_395 . V_241 ,
V_384 -> V_239 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_248 ] ) {
struct V_167 * V_384 = F_111 ( V_356 [ V_248 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_396 )
V_32 = V_25 -> V_396 ( V_35 , V_384 -> V_188 ,
V_384 -> V_241 ,
V_384 -> V_240 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_250 ] ) {
struct V_165 * V_397 = F_111 ( V_356 [ V_250 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_398 )
V_32 = V_25 -> V_398 ( V_35 , V_397 -> V_188 ,
V_397 -> V_242 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_251 ] ) {
struct V_168 * V_399 = F_111 ( V_356 [ V_251 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_400 )
V_32 = V_25 -> V_400 ( V_35 , V_399 -> V_188 ,
V_399 -> V_243 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_252 ] ) {
struct V_169 * V_401 ;
V_32 = - V_197 ;
V_401 = F_111 ( V_356 [ V_252 ] ) ;
if ( V_25 -> V_402 )
V_32 = V_25 -> V_402 ( V_35 , V_401 -> V_188 ,
V_401 -> V_242 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_253 ] ) {
struct V_171 * V_384 = F_111 ( V_356 [ V_253 ] ) ;
V_32 = - V_197 ;
if ( V_25 -> V_403 )
V_32 = V_25 -> V_403 ( V_35 , V_384 -> V_188 , V_384 -> V_242 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_356 [ V_404 ] ) {
struct V_383 * V_384 = F_111 ( V_356 [ V_404 ] ) ;
if ( ! V_25 -> V_386 )
return - V_197 ;
return F_165 ( V_35 , V_384 , V_404 ) ;
}
if ( V_356 [ V_405 ] ) {
struct V_383 * V_384 = F_111 ( V_356 [ V_405 ] ) ;
if ( ! V_25 -> V_386 )
return - V_197 ;
return F_165 ( V_35 , V_384 , V_405 ) ;
}
return V_32 ;
}
static int F_167 ( struct V_34 * V_35 , int V_295 )
{
struct V_34 * V_289 = F_47 ( V_35 ) ;
const struct V_276 * V_25 ;
int V_32 ;
if ( V_289 ) {
if ( V_289 -> V_295 == V_295 )
return 0 ;
V_25 = V_289 -> V_178 ;
if ( V_25 -> V_406 ) {
V_32 = V_25 -> V_406 ( V_289 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_197 ;
}
}
if ( V_295 ) {
V_289 = F_168 ( F_134 ( V_35 ) , V_295 ) ;
if ( ! V_289 )
return - V_378 ;
V_25 = V_289 -> V_178 ;
if ( V_25 -> V_407 ) {
V_32 = V_25 -> V_407 ( V_289 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_197 ;
}
}
return 0 ;
}
static int F_169 ( const struct V_2 * V_56 ,
struct V_34 * V_35 , struct V_126 * V_127 ,
struct V_373 * V_408 ,
struct V_47 * * V_356 , char * V_409 , int V_410 )
{
const struct V_276 * V_25 = V_35 -> V_178 ;
int V_32 ;
if ( V_356 [ V_376 ] || V_356 [ V_377 ] ) {
struct V_33 * V_33 = F_156 ( F_134 ( V_35 ) , V_356 ) ;
if ( F_170 ( V_33 ) ) {
V_32 = F_171 ( V_33 ) ;
goto V_411;
}
if ( ! F_172 ( V_56 , V_33 -> V_412 , V_413 ) ) {
F_173 ( V_33 ) ;
V_32 = - V_414 ;
goto V_411;
}
V_32 = F_174 ( V_35 , V_33 , V_409 ) ;
F_173 ( V_33 ) ;
if ( V_32 )
goto V_411;
V_410 |= V_415 ;
}
if ( V_356 [ V_275 ] ) {
struct V_183 * V_416 ;
struct V_417 V_418 ;
if ( ! V_25 -> V_419 ) {
V_32 = - V_197 ;
goto V_411;
}
if ( ! F_175 ( V_35 ) ) {
V_32 = - V_420 ;
goto V_411;
}
V_416 = F_111 ( V_356 [ V_275 ] ) ;
V_418 . V_268 = ( unsigned long ) V_416 -> V_268 ;
V_418 . V_269 = ( unsigned long ) V_416 -> V_269 ;
V_418 . V_270 = ( unsigned short ) V_416 -> V_270 ;
V_418 . V_271 = ( unsigned char ) V_416 -> V_271 ;
V_418 . V_272 = ( unsigned char ) V_416 -> V_272 ;
V_418 . V_273 = ( unsigned char ) V_416 -> V_273 ;
V_32 = V_25 -> V_419 ( V_35 , & V_418 ) ;
if ( V_32 < 0 )
goto V_411;
V_410 |= V_421 ;
}
if ( V_356 [ V_328 ] ) {
struct V_422 * V_423 ;
int V_371 ;
V_371 = sizeof( V_424 ) + V_35 -> V_327 ;
V_423 = F_176 ( V_371 , V_20 ) ;
if ( ! V_423 ) {
V_32 = - V_425 ;
goto V_411;
}
V_423 -> V_426 = V_35 -> type ;
memcpy ( V_423 -> V_427 , F_111 ( V_356 [ V_328 ] ) ,
V_35 -> V_327 ) ;
V_32 = F_177 ( V_35 , V_423 ) ;
F_27 ( V_423 ) ;
if ( V_32 )
goto V_411;
V_410 |= V_415 ;
}
if ( V_356 [ V_303 ] ) {
V_32 = F_178 ( V_35 , F_149 ( V_356 [ V_303 ] ) ) ;
if ( V_32 < 0 )
goto V_411;
V_410 |= V_415 ;
}
if ( V_356 [ V_305 ] ) {
F_179 ( V_35 , F_149 ( V_356 [ V_305 ] ) ) ;
V_410 |= V_421 ;
}
if ( V_127 -> V_294 > 0 && V_409 [ 0 ] ) {
V_32 = F_180 ( V_35 , V_409 ) ;
if ( V_32 < 0 )
goto V_411;
V_410 |= V_415 ;
}
if ( V_356 [ V_322 ] ) {
V_32 = F_181 ( V_35 , F_111 ( V_356 [ V_322 ] ) ,
F_161 ( V_356 [ V_322 ] ) ) ;
if ( V_32 < 0 )
goto V_411;
V_410 |= V_421 ;
}
if ( V_356 [ V_330 ] ) {
F_182 ( V_35 -> V_265 , V_356 [ V_330 ] , V_35 -> V_327 ) ;
F_183 ( V_428 , V_35 ) ;
}
if ( V_127 -> V_128 || V_127 -> V_129 ) {
V_32 = F_184 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
goto V_411;
}
if ( V_356 [ V_317 ] ) {
V_32 = F_167 ( V_35 , F_149 ( V_356 [ V_317 ] ) ) ;
if ( V_32 )
goto V_411;
V_410 |= V_415 ;
}
if ( V_356 [ V_318 ] ) {
V_32 = F_185 ( V_35 , F_186 ( V_356 [ V_318 ] ) ) ;
if ( V_32 )
goto V_411;
V_410 |= V_415 ;
}
if ( V_356 [ V_297 ] ) {
unsigned long V_429 = F_149 ( V_356 [ V_297 ] ) ;
unsigned long V_430 = V_35 -> V_298 ;
if ( V_35 -> V_298 ^ V_429 ) {
V_35 -> V_298 = V_429 ;
V_32 = F_183 (
V_431 , V_35 ) ;
V_32 = F_187 ( V_32 ) ;
if ( V_32 ) {
V_35 -> V_298 = V_430 ;
goto V_411;
}
V_410 |= V_421 ;
}
}
if ( V_356 [ V_299 ] )
F_85 ( V_35 , F_186 ( V_356 [ V_299 ] ) ) ;
if ( V_356 [ V_301 ] ) {
unsigned char V_429 = F_186 ( V_356 [ V_301 ] ) ;
F_87 ( & V_122 ) ;
if ( V_35 -> V_302 ^ V_429 )
V_410 |= V_421 ;
V_35 -> V_302 = V_429 ;
F_88 ( & V_122 ) ;
}
if ( V_356 [ V_332 ] ) {
struct V_47 * V_213 [ V_432 + 1 ] ;
struct V_47 * V_202 ;
int V_379 ;
F_162 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_163 ( V_202 ) != V_244 ||
F_161 ( V_202 ) < V_394 ) {
V_32 = - V_378 ;
goto V_411;
}
V_32 = F_140 ( V_213 , V_432 , V_202 ,
V_433 , NULL ) ;
if ( V_32 < 0 )
goto V_411;
V_32 = F_166 ( V_35 , V_213 ) ;
if ( V_32 < 0 )
goto V_411;
V_410 |= V_421 ;
}
}
V_32 = 0 ;
if ( V_356 [ V_189 ] ) {
struct V_47 * V_273 [ V_434 + 1 ] ;
struct V_47 * V_202 ;
int V_188 ;
int V_379 ;
V_32 = - V_197 ;
if ( ! V_25 -> V_435 )
goto V_411;
F_162 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_163 ( V_202 ) != V_190 ||
F_161 ( V_202 ) < V_394 ) {
V_32 = - V_378 ;
goto V_411;
}
V_32 = F_140 ( V_273 , V_434 , V_202 ,
V_436 , NULL ) ;
if ( V_32 < 0 )
goto V_411;
if ( ! V_273 [ V_191 ] ) {
V_32 = - V_197 ;
goto V_411;
}
V_188 = F_149 ( V_273 [ V_191 ] ) ;
V_32 = V_25 -> V_435 ( V_35 , V_188 , V_273 ) ;
if ( V_32 < 0 )
goto V_411;
V_410 |= V_421 ;
}
}
V_32 = 0 ;
if ( V_356 [ V_193 ] ) {
struct V_47 * V_273 [ V_434 + 1 ] ;
V_32 = F_140 ( V_273 , V_434 ,
V_356 [ V_193 ] , V_436 ,
NULL ) ;
if ( V_32 < 0 )
goto V_411;
V_32 = - V_197 ;
if ( V_25 -> V_435 )
V_32 = V_25 -> V_435 ( V_35 , V_194 , V_273 ) ;
if ( V_32 < 0 )
goto V_411;
V_410 |= V_421 ;
}
if ( V_356 [ V_336 ] ) {
struct V_47 * V_338 ;
int V_379 ;
F_162 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_163 ( V_338 ) ) ) )
F_188 () ;
V_32 = V_54 -> V_381 ( V_35 , V_338 ) ;
if ( V_32 < 0 )
goto V_411;
V_410 |= V_421 ;
}
}
V_32 = 0 ;
if ( V_356 [ V_325 ] ) {
V_32 = F_189 ( V_35 ,
F_186 ( V_356 [ V_325 ] ) ) ;
if ( V_32 )
goto V_411;
V_410 |= V_421 ;
}
if ( V_356 [ V_283 ] ) {
struct V_47 * V_282 [ V_437 + 1 ] ;
T_5 V_438 = 0 ;
V_32 = F_140 ( V_282 , V_437 , V_356 [ V_283 ] ,
V_439 , NULL ) ;
if ( V_32 < 0 )
goto V_411;
if ( V_282 [ V_284 ] ) {
V_32 = - V_378 ;
goto V_411;
}
if ( V_282 [ V_440 ] ) {
V_438 = F_149 ( V_282 [ V_440 ] ) ;
if ( V_438 & ~ V_441 ) {
V_32 = - V_378 ;
goto V_411;
}
if ( ( V_438 & V_442 ) &&
( V_438 & V_443 ) ) {
V_32 = - V_378 ;
goto V_411;
}
}
if ( V_282 [ V_444 ] ) {
V_32 = F_190 ( V_35 , V_408 ,
F_191 ( V_282 [ V_444 ] ) ,
V_438 ) ;
if ( V_32 )
goto V_411;
V_410 |= V_421 ;
}
}
V_411:
if ( V_410 & V_415 ) {
if ( V_410 & V_421 )
F_89 ( V_35 ) ;
if ( V_32 < 0 )
F_192 ( L_3 ,
V_35 -> V_94 ) ;
}
return V_32 ;
}
static int F_193 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
int V_32 ;
struct V_47 * V_356 [ V_357 + 1 ] ;
char V_409 [ V_181 ] ;
V_32 = F_148 ( V_82 , sizeof( * V_127 ) , V_356 , V_357 , V_362 ,
V_408 ) ;
if ( V_32 < 0 )
goto V_411;
if ( V_356 [ V_296 ] )
F_141 ( V_409 , V_356 [ V_296 ] , V_181 ) ;
else
V_409 [ 0 ] = '\0' ;
V_32 = - V_378 ;
V_127 = F_127 ( V_82 ) ;
if ( V_127 -> V_294 > 0 )
V_35 = F_168 ( V_33 , V_127 -> V_294 ) ;
else if ( V_356 [ V_296 ] )
V_35 = F_194 ( V_33 , V_409 ) ;
else
goto V_411;
if ( V_35 == NULL ) {
V_32 = - V_420 ;
goto V_411;
}
V_32 = F_160 ( V_35 , V_356 ) ;
if ( V_32 < 0 )
goto V_411;
V_32 = F_169 ( V_56 , V_35 , V_127 , V_408 , V_356 , V_409 , 0 ) ;
V_411:
return V_32 ;
}
static int F_195 ( const struct V_33 * V_33 , int V_74 )
{
struct V_34 * V_35 , * V_445 ;
F_34 ( V_36 ) ;
bool V_446 = false ;
if ( ! V_74 )
return - V_414 ;
F_35 (net, dev) {
if ( V_35 -> V_74 == V_74 ) {
const struct V_23 * V_25 ;
V_446 = true ;
V_25 = V_35 -> V_23 ;
if ( ! V_25 || ! V_25 -> V_28 )
return - V_197 ;
}
}
if ( ! V_446 )
return - V_420 ;
F_196 (net, dev, aux) {
if ( V_35 -> V_74 == V_74 ) {
const struct V_23 * V_25 ;
V_25 = V_35 -> V_23 ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
}
}
F_36 ( & V_36 ) ;
return 0 ;
}
int F_197 ( struct V_34 * V_35 )
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
static int F_198 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_34 * V_35 ;
struct V_126 * V_127 ;
char V_409 [ V_181 ] ;
struct V_47 * V_356 [ V_357 + 1 ] ;
int V_32 ;
V_32 = F_148 ( V_82 , sizeof( * V_127 ) , V_356 , V_357 , V_362 , V_408 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_356 [ V_296 ] )
F_141 ( V_409 , V_356 [ V_296 ] , V_181 ) ;
V_127 = F_127 ( V_82 ) ;
if ( V_127 -> V_294 > 0 )
V_35 = F_168 ( V_33 , V_127 -> V_294 ) ;
else if ( V_356 [ V_296 ] )
V_35 = F_194 ( V_33 , V_409 ) ;
else if ( V_356 [ V_305 ] )
return F_195 ( V_33 , F_149 ( V_356 [ V_305 ] ) ) ;
else
return - V_378 ;
if ( ! V_35 )
return - V_420 ;
return F_197 ( V_35 ) ;
}
int F_199 ( struct V_34 * V_35 , const struct V_126 * V_127 )
{
unsigned int V_447 ;
int V_32 ;
V_447 = V_35 -> V_83 ;
if ( V_127 && ( V_127 -> V_128 || V_127 -> V_129 ) ) {
V_32 = F_200 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_35 -> V_448 = V_449 ;
F_201 ( V_35 , V_447 , ~ 0U ) ;
return 0 ;
}
struct V_34 * F_202 ( struct V_33 * V_33 ,
const char * V_409 , unsigned char V_450 ,
const struct V_23 * V_25 , struct V_47 * V_356 [] )
{
struct V_34 * V_35 ;
unsigned int V_309 = 1 ;
unsigned int V_315 = 1 ;
if ( V_356 [ V_308 ] )
V_309 = F_149 ( V_356 [ V_308 ] ) ;
else if ( V_25 -> V_451 )
V_309 = V_25 -> V_451 () ;
if ( V_356 [ V_314 ] )
V_315 = F_149 ( V_356 [ V_314 ] ) ;
else if ( V_25 -> V_452 )
V_315 = V_25 -> V_452 () ;
V_35 = F_203 ( V_25 -> V_453 , V_409 , V_450 ,
V_25 -> V_27 , V_309 , V_315 ) ;
if ( ! V_35 )
return F_204 ( - V_425 ) ;
F_205 ( V_35 , V_33 ) ;
V_35 -> V_23 = V_25 ;
V_35 -> V_448 = V_454 ;
if ( V_356 [ V_303 ] )
V_35 -> V_304 = F_149 ( V_356 [ V_303 ] ) ;
if ( V_356 [ V_328 ] ) {
memcpy ( V_35 -> V_329 , F_111 ( V_356 [ V_328 ] ) ,
F_161 ( V_356 [ V_328 ] ) ) ;
V_35 -> V_455 = V_456 ;
}
if ( V_356 [ V_330 ] )
memcpy ( V_35 -> V_265 , F_111 ( V_356 [ V_330 ] ) ,
F_161 ( V_356 [ V_330 ] ) ) ;
if ( V_356 [ V_297 ] )
V_35 -> V_298 = F_149 ( V_356 [ V_297 ] ) ;
if ( V_356 [ V_299 ] )
F_85 ( V_35 , F_186 ( V_356 [ V_299 ] ) ) ;
if ( V_356 [ V_301 ] )
V_35 -> V_302 = F_186 ( V_356 [ V_301 ] ) ;
if ( V_356 [ V_305 ] )
F_179 ( V_35 , F_149 ( V_356 [ V_305 ] ) ) ;
return V_35 ;
}
static int F_206 ( const struct V_2 * V_56 ,
struct V_33 * V_33 , int V_74 ,
struct V_126 * V_127 ,
struct V_373 * V_408 ,
struct V_47 * * V_356 )
{
struct V_34 * V_35 , * V_445 ;
int V_32 ;
F_196 (net, dev, aux) {
if ( V_35 -> V_74 == V_74 ) {
V_32 = F_169 ( V_56 , V_35 , V_127 , V_408 , V_356 , NULL , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
return 0 ;
}
static int F_207 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
const struct V_23 * V_25 ;
const struct V_23 * V_457 = NULL ;
struct V_34 * V_35 ;
struct V_34 * V_45 = NULL ;
struct V_126 * V_127 ;
char V_24 [ V_344 ] ;
char V_409 [ V_181 ] ;
struct V_47 * V_356 [ V_357 + 1 ] ;
struct V_47 * V_69 [ V_342 + 1 ] ;
unsigned char V_450 = V_458 ;
int V_32 ;
#ifdef F_208
V_459:
#endif
V_32 = F_148 ( V_82 , sizeof( * V_127 ) , V_356 , V_357 , V_362 , V_408 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_356 [ V_296 ] )
F_141 ( V_409 , V_356 [ V_296 ] , V_181 ) ;
else
V_409 [ 0 ] = '\0' ;
V_127 = F_127 ( V_82 ) ;
if ( V_127 -> V_294 > 0 )
V_35 = F_168 ( V_33 , V_127 -> V_294 ) ;
else {
if ( V_409 [ 0 ] )
V_35 = F_194 ( V_33 , V_409 ) ;
else
V_35 = NULL ;
}
if ( V_35 ) {
V_45 = F_47 ( V_35 ) ;
if ( V_45 )
V_457 = V_45 -> V_23 ;
}
V_32 = F_160 ( V_35 , V_356 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_356 [ V_70 ] ) {
V_32 = F_140 ( V_69 , V_342 ,
V_356 [ V_70 ] , V_343 ,
NULL ) ;
if ( V_32 < 0 )
return V_32 ;
} else
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_69 [ V_64 ] ) {
F_141 ( V_24 , V_69 [ V_64 ] , sizeof( V_24 ) ) ;
V_25 = F_28 ( V_24 ) ;
} else {
V_24 [ 0 ] = '\0' ;
V_25 = NULL ;
}
if ( 1 ) {
struct V_47 * V_202 [ V_25 ? V_25 -> V_460 + 1 : 1 ] ;
struct V_47 * V_461 [ V_457 ? V_457 -> V_462 + 1 : 1 ] ;
struct V_47 * * V_63 = NULL ;
struct V_47 * * V_57 = NULL ;
struct V_33 * V_463 , * V_334 = NULL ;
if ( V_25 ) {
if ( V_25 -> V_460 && V_69 [ V_67 ] ) {
V_32 = F_140 ( V_202 , V_25 -> V_460 ,
V_69 [ V_67 ] ,
V_25 -> V_464 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_63 = V_202 ;
}
if ( V_25 -> V_465 ) {
V_32 = V_25 -> V_465 ( V_356 , V_63 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_457 ) {
if ( V_457 -> V_462 &&
V_69 [ V_61 ] ) {
V_32 = F_140 ( V_461 ,
V_457 -> V_462 ,
V_69 [ V_61 ] ,
V_457 -> V_466 ,
NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_57 = V_461 ;
}
if ( V_457 -> V_467 ) {
V_32 = V_457 -> V_467 ( V_356 , V_57 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_35 ) {
int V_410 = 0 ;
if ( V_82 -> V_468 & V_469 )
return - V_26 ;
if ( V_82 -> V_468 & V_470 )
return - V_197 ;
if ( V_69 [ V_67 ] ) {
if ( ! V_25 || V_25 != V_35 -> V_23 ||
! V_25 -> V_471 )
return - V_197 ;
V_32 = V_25 -> V_471 ( V_35 , V_356 , V_63 ) ;
if ( V_32 < 0 )
return V_32 ;
V_410 |= V_421 ;
}
if ( V_69 [ V_61 ] ) {
if ( ! V_457 || ! V_457 -> V_472 )
return - V_197 ;
V_32 = V_457 -> V_472 ( V_45 , V_35 ,
V_356 , V_57 ) ;
if ( V_32 < 0 )
return V_32 ;
V_410 |= V_421 ;
}
return F_169 ( V_56 , V_35 , V_127 , V_408 , V_356 , V_409 ,
V_410 ) ;
}
if ( ! ( V_82 -> V_468 & V_473 ) ) {
if ( V_127 -> V_294 == 0 && V_356 [ V_305 ] )
return F_206 ( V_56 , V_33 ,
F_149 ( V_356 [ V_305 ] ) ,
V_127 , V_408 , V_356 ) ;
return - V_420 ;
}
if ( V_356 [ V_275 ] || V_356 [ V_474 ] )
return - V_197 ;
if ( ! V_25 ) {
#ifdef F_208
if ( V_24 [ 0 ] ) {
F_4 () ;
F_209 ( L_4 , V_24 ) ;
F_1 () ;
V_25 = F_28 ( V_24 ) ;
if ( V_25 )
goto V_459;
}
#endif
return - V_197 ;
}
if ( ! V_25 -> V_27 )
return - V_197 ;
if ( ! V_409 [ 0 ] ) {
snprintf ( V_409 , V_181 , L_5 , V_25 -> V_24 ) ;
V_450 = V_475 ;
}
V_463 = F_156 ( V_33 , V_356 ) ;
if ( F_170 ( V_463 ) )
return F_171 ( V_463 ) ;
V_32 = - V_414 ;
if ( ! F_172 ( V_56 , V_463 -> V_412 , V_413 ) )
goto V_71;
if ( V_356 [ V_335 ] ) {
int V_102 = F_191 ( V_356 [ V_335 ] ) ;
V_334 = F_210 ( V_463 , V_102 ) ;
if ( ! V_334 ) {
V_32 = - V_378 ;
goto V_71;
}
V_32 = - V_414 ;
if ( ! F_172 ( V_56 , V_334 -> V_412 , V_413 ) )
goto V_71;
}
V_35 = F_202 ( V_334 ? : V_463 , V_409 ,
V_450 , V_25 , V_356 ) ;
if ( F_170 ( V_35 ) ) {
V_32 = F_171 ( V_35 ) ;
goto V_71;
}
V_35 -> V_295 = V_127 -> V_294 ;
if ( V_25 -> V_476 ) {
V_32 = V_25 -> V_476 ( V_334 ? : V_33 , V_35 , V_356 , V_63 ) ;
if ( V_32 < 0 ) {
if ( V_35 -> V_477 == V_478 )
F_211 ( V_35 ) ;
goto V_71;
}
} else {
V_32 = F_212 ( V_35 ) ;
if ( V_32 < 0 ) {
F_211 ( V_35 ) ;
goto V_71;
}
}
V_32 = F_199 ( V_35 , V_127 ) ;
if ( V_32 < 0 )
goto V_479;
if ( V_334 ) {
V_32 = F_174 ( V_35 , V_463 , V_409 ) ;
if ( V_32 < 0 )
goto V_479;
}
if ( V_356 [ V_317 ] ) {
V_32 = F_167 ( V_35 , F_149 ( V_356 [ V_317 ] ) ) ;
if ( V_32 )
goto V_479;
}
V_71:
if ( V_334 )
F_173 ( V_334 ) ;
F_173 ( V_463 ) ;
return V_32 ;
V_479:
if ( V_25 -> V_476 ) {
F_34 ( V_36 ) ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
F_36 ( & V_36 ) ;
} else {
F_213 ( V_35 ) ;
}
goto V_71;
}
}
static int F_214 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_126 * V_127 ;
char V_409 [ V_181 ] ;
struct V_47 * V_356 [ V_357 + 1 ] ;
struct V_34 * V_35 = NULL ;
struct V_2 * V_480 ;
int V_32 ;
T_5 V_53 = 0 ;
V_32 = F_148 ( V_82 , sizeof( * V_127 ) , V_356 , V_357 , V_362 , V_408 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_356 [ V_296 ] )
F_141 ( V_409 , V_356 [ V_296 ] , V_181 ) ;
if ( V_356 [ V_363 ] )
V_53 = F_149 ( V_356 [ V_363 ] ) ;
V_127 = F_127 ( V_82 ) ;
if ( V_127 -> V_294 > 0 )
V_35 = F_168 ( V_33 , V_127 -> V_294 ) ;
else if ( V_356 [ V_296 ] )
V_35 = F_194 ( V_33 , V_409 ) ;
else
return - V_378 ;
if ( V_35 == NULL )
return - V_420 ;
V_480 = F_215 ( F_98 ( V_35 , V_53 ) , V_20 ) ;
if ( V_480 == NULL )
return - V_21 ;
V_32 = F_125 ( V_480 , V_35 , V_368 , F_64 ( V_56 ) . V_369 ,
V_82 -> V_370 , 0 , 0 , V_53 ) ;
if ( V_32 < 0 ) {
F_216 ( V_32 == - V_59 ) ;
F_6 ( V_480 ) ;
} else
V_32 = F_68 ( V_480 , V_33 , F_64 ( V_56 ) . V_369 ) ;
return V_32 ;
}
static T_10 F_217 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_34 * V_35 ;
struct V_47 * V_356 [ V_357 + 1 ] ;
T_5 V_53 = 0 ;
T_10 V_481 = 0 ;
int V_359 ;
V_359 = F_147 ( V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_361 ) : sizeof( struct V_126 ) ;
if ( F_148 ( V_82 , V_359 , V_356 , V_357 , V_362 , NULL ) >= 0 ) {
if ( V_356 [ V_363 ] )
V_53 = F_149 ( V_356 [ V_363 ] ) ;
}
if ( ! V_53 )
return V_482 ;
F_29 (dev, &net->dev_base_head, dev_list) {
V_481 = F_218 ( T_10 , V_481 ,
F_98 ( V_35 ,
V_53 ) ) ;
}
return F_219 ( V_481 ) ;
}
static int F_220 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
int V_353 ;
int V_354 = V_349 -> V_52 ;
if ( V_354 == 0 )
V_354 = 1 ;
for ( V_353 = 1 ; V_353 <= V_14 ; V_353 ++ ) {
int type = V_349 -> V_82 -> V_483 - V_9 ;
if ( V_353 < V_354 || V_353 == V_484 )
continue;
if ( V_15 [ V_353 ] == NULL ||
V_15 [ V_353 ] [ type ] . V_18 == NULL )
continue;
if ( V_353 > V_354 ) {
memset ( & V_349 -> args [ 0 ] , 0 , sizeof( V_349 -> args ) ) ;
V_349 -> V_485 = 0 ;
V_349 -> V_286 = 0 ;
}
if ( V_15 [ V_353 ] [ type ] . V_18 ( V_56 , V_349 ) )
break;
}
V_349 -> V_52 = V_353 ;
return V_56 -> V_371 ;
}
struct V_2 * F_221 ( int type , struct V_34 * V_35 ,
unsigned int V_287 , T_6 V_83 )
{
struct V_33 * V_33 = F_134 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
T_4 V_486 ;
V_56 = F_215 ( ( V_486 = F_98 ( V_35 , 0 ) ) , V_83 ) ;
if ( V_56 == NULL )
goto V_411;
V_32 = F_125 ( V_56 , V_35 , type , 0 , 0 , V_287 , 0 , 0 ) ;
if ( V_32 < 0 ) {
F_216 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
goto V_411;
}
return V_56 ;
V_411:
if ( V_32 < 0 )
F_73 ( V_33 , V_487 , V_32 ) ;
return NULL ;
}
void F_222 ( struct V_2 * V_56 , struct V_34 * V_35 , T_6 V_83 )
{
struct V_33 * V_33 = F_134 ( V_35 ) ;
F_70 ( V_56 , V_33 , 0 , V_487 , NULL , V_83 ) ;
}
void F_223 ( int type , struct V_34 * V_35 , unsigned int V_287 ,
T_6 V_83 )
{
struct V_2 * V_56 ;
if ( V_35 -> V_477 != V_488 )
return;
V_56 = F_221 ( type , V_35 , V_287 , V_83 ) ;
if ( V_56 )
F_222 ( V_56 , V_35 , V_83 ) ;
}
static int F_224 ( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_9 * V_489 , T_10 V_490 , T_5 V_73 , T_5 V_286 ,
int type , unsigned int V_83 ,
int V_491 , T_10 V_492 )
{
struct V_81 * V_82 ;
struct V_493 * V_494 ;
V_82 = F_126 ( V_56 , V_73 , V_286 , type , sizeof( * V_494 ) , V_491 ) ;
if ( ! V_82 )
return - V_59 ;
V_494 = F_127 ( V_82 ) ;
V_494 -> V_495 = V_496 ;
V_494 -> V_497 = 0 ;
V_494 -> V_498 = 0 ;
V_494 -> V_499 = V_83 ;
V_494 -> V_500 = 0 ;
V_494 -> V_501 = V_35 -> V_295 ;
V_494 -> V_492 = V_492 ;
if ( F_84 ( V_56 , V_502 , V_503 , V_489 ) )
goto V_95;
if ( V_490 )
if ( F_84 ( V_56 , V_504 , sizeof( T_10 ) , & V_490 ) )
goto V_95;
F_137 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_138 ( V_56 , V_82 ) ;
return - V_59 ;
}
static inline T_4 F_225 ( void )
{
return F_99 ( sizeof( struct V_493 ) ) +
F_48 ( V_503 ) +
F_48 ( sizeof( T_10 ) ) +
0 ;
}
static void F_226 ( struct V_34 * V_35 , T_9 * V_489 , T_10 V_490 , int type ,
T_10 V_492 )
{
struct V_33 * V_33 = F_134 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
V_56 = F_215 ( F_225 () , V_505 ) ;
if ( ! V_56 )
goto V_411;
V_32 = F_224 ( V_56 , V_35 , V_489 , V_490 ,
0 , 0 , type , V_506 , 0 , V_492 ) ;
if ( V_32 < 0 ) {
F_6 ( V_56 ) ;
goto V_411;
}
F_70 ( V_56 , V_33 , 0 , V_507 , NULL , V_505 ) ;
return;
V_411:
F_73 ( V_33 , V_507 , V_32 ) ;
}
int F_227 ( struct V_493 * V_494 ,
struct V_47 * V_356 [] ,
struct V_34 * V_35 ,
const unsigned char * V_489 , T_10 V_490 ,
T_10 V_83 )
{
int V_32 = - V_378 ;
if ( V_494 -> V_492 && ! ( V_494 -> V_492 & V_508 ) ) {
F_228 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( V_490 ) {
F_228 ( L_7 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_229 ( V_489 ) || F_230 ( V_489 ) )
V_32 = F_231 ( V_35 , V_489 ) ;
else if ( F_232 ( V_489 ) )
V_32 = F_233 ( V_35 , V_489 ) ;
if ( V_32 == - V_26 && ! ( V_83 & V_469 ) )
V_32 = 0 ;
return V_32 ;
}
static int F_234 ( struct V_47 * V_509 , T_10 * V_510 )
{
T_10 V_490 = 0 ;
if ( V_509 ) {
if ( F_161 ( V_509 ) != sizeof( T_10 ) ) {
F_228 ( L_8 ) ;
return - V_378 ;
}
V_490 = F_235 ( V_509 ) ;
if ( ! V_490 || V_490 >= V_511 ) {
F_228 ( L_9 ,
V_490 ) ;
return - V_378 ;
}
}
* V_510 = V_490 ;
return 0 ;
}
static int F_236 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_493 * V_494 ;
struct V_47 * V_356 [ V_512 + 1 ] ;
struct V_34 * V_35 ;
T_9 * V_489 ;
T_10 V_490 ;
int V_32 ;
V_32 = F_148 ( V_82 , sizeof( * V_494 ) , V_356 , V_512 , NULL , V_408 ) ;
if ( V_32 < 0 )
return V_32 ;
V_494 = F_127 ( V_82 ) ;
if ( V_494 -> V_501 == 0 ) {
F_228 ( L_10 ) ;
return - V_378 ;
}
V_35 = F_168 ( V_33 , V_494 -> V_501 ) ;
if ( V_35 == NULL ) {
F_228 ( L_11 ) ;
return - V_420 ;
}
if ( ! V_356 [ V_502 ] || F_161 ( V_356 [ V_502 ] ) != V_503 ) {
F_228 ( L_12 ) ;
return - V_378 ;
}
V_489 = F_111 ( V_356 [ V_502 ] ) ;
V_32 = F_234 ( V_356 [ V_504 ] , & V_490 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_197 ;
if ( ( ! V_494 -> V_499 || V_494 -> V_499 & V_513 ) &&
( V_35 -> V_514 & V_515 ) ) {
struct V_34 * V_516 = F_47 ( V_35 ) ;
const struct V_276 * V_25 = V_516 -> V_178 ;
V_32 = V_25 -> V_517 ( V_494 , V_356 , V_35 , V_489 , V_490 ,
V_82 -> V_468 ) ;
if ( V_32 )
goto V_71;
else
V_494 -> V_499 &= ~ V_513 ;
}
if ( ( V_494 -> V_499 & V_506 ) ) {
if ( V_35 -> V_178 -> V_517 )
V_32 = V_35 -> V_178 -> V_517 ( V_494 , V_356 , V_35 , V_489 ,
V_490 ,
V_82 -> V_468 ) ;
else
V_32 = F_227 ( V_494 , V_356 , V_35 , V_489 , V_490 ,
V_82 -> V_468 ) ;
if ( ! V_32 ) {
F_226 ( V_35 , V_489 , V_490 , V_518 ,
V_494 -> V_492 ) ;
V_494 -> V_499 &= ~ V_506 ;
}
}
V_71:
return V_32 ;
}
int F_237 ( struct V_493 * V_494 ,
struct V_47 * V_356 [] ,
struct V_34 * V_35 ,
const unsigned char * V_489 , T_10 V_490 )
{
int V_32 = - V_378 ;
if ( ! ( V_494 -> V_492 & V_508 ) ) {
F_228 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_229 ( V_489 ) || F_230 ( V_489 ) )
V_32 = F_238 ( V_35 , V_489 ) ;
else if ( F_232 ( V_489 ) )
V_32 = F_239 ( V_35 , V_489 ) ;
return V_32 ;
}
static int F_240 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_493 * V_494 ;
struct V_47 * V_356 [ V_512 + 1 ] ;
struct V_34 * V_35 ;
int V_32 = - V_378 ;
T_11 * V_489 ;
T_10 V_490 ;
if ( ! F_241 ( V_56 , V_413 ) )
return - V_414 ;
V_32 = F_148 ( V_82 , sizeof( * V_494 ) , V_356 , V_512 , NULL , V_408 ) ;
if ( V_32 < 0 )
return V_32 ;
V_494 = F_127 ( V_82 ) ;
if ( V_494 -> V_501 == 0 ) {
F_228 ( L_13 ) ;
return - V_378 ;
}
V_35 = F_168 ( V_33 , V_494 -> V_501 ) ;
if ( V_35 == NULL ) {
F_228 ( L_14 ) ;
return - V_420 ;
}
if ( ! V_356 [ V_502 ] || F_161 ( V_356 [ V_502 ] ) != V_503 ) {
F_228 ( L_15 ) ;
return - V_378 ;
}
V_489 = F_111 ( V_356 [ V_502 ] ) ;
V_32 = F_234 ( V_356 [ V_504 ] , & V_490 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_197 ;
if ( ( ! V_494 -> V_499 || V_494 -> V_499 & V_513 ) &&
( V_35 -> V_514 & V_515 ) ) {
struct V_34 * V_516 = F_47 ( V_35 ) ;
const struct V_276 * V_25 = V_516 -> V_178 ;
if ( V_25 -> V_519 )
V_32 = V_25 -> V_519 ( V_494 , V_356 , V_35 , V_489 , V_490 ) ;
if ( V_32 )
goto V_71;
else
V_494 -> V_499 &= ~ V_513 ;
}
if ( V_494 -> V_499 & V_506 ) {
if ( V_35 -> V_178 -> V_519 )
V_32 = V_35 -> V_178 -> V_519 ( V_494 , V_356 , V_35 , V_489 ,
V_490 ) ;
else
V_32 = F_237 ( V_494 , V_356 , V_35 , V_489 , V_490 ) ;
if ( ! V_32 ) {
F_226 ( V_35 , V_489 , V_490 , V_520 ,
V_494 -> V_492 ) ;
V_494 -> V_499 &= ~ V_506 ;
}
}
V_71:
return V_32 ;
}
static int F_242 ( struct V_2 * V_56 ,
struct V_348 * V_349 ,
struct V_34 * V_35 ,
int * V_353 ,
struct V_521 * V_30 )
{
struct V_522 * V_523 ;
int V_32 ;
T_5 V_369 , V_286 ;
V_369 = F_64 ( V_349 -> V_56 ) . V_369 ;
V_286 = V_349 -> V_82 -> V_370 ;
F_29 (ha, &list->list, list) {
if ( * V_353 < V_349 -> args [ 2 ] )
goto V_524;
V_32 = F_224 ( V_56 , V_35 , V_523 -> V_489 , 0 ,
V_369 , V_286 ,
V_518 , V_506 ,
V_358 , V_508 ) ;
if ( V_32 < 0 )
return V_32 ;
V_524:
* V_353 += 1 ;
}
return 0 ;
}
int F_243 ( struct V_2 * V_56 ,
struct V_348 * V_349 ,
struct V_34 * V_35 ,
struct V_34 * V_525 ,
int * V_353 )
{
int V_32 ;
F_244 ( V_35 ) ;
V_32 = F_242 ( V_56 , V_349 , V_35 , V_353 , & V_35 -> V_526 ) ;
if ( V_32 )
goto V_71;
V_32 = F_242 ( V_56 , V_349 , V_35 , V_353 , & V_35 -> V_527 ) ;
V_71:
F_245 ( V_35 ) ;
return V_32 ;
}
static int F_246 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
struct V_34 * V_35 ;
struct V_47 * V_356 [ V_357 + 1 ] ;
struct V_34 * V_516 = NULL ;
const struct V_276 * V_25 = NULL ;
const struct V_276 * V_528 = NULL ;
struct V_126 * V_127 = F_127 ( V_349 -> V_82 ) ;
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_355 * V_3 ;
int V_529 = 0 ;
int V_530 = 0 ;
int V_351 , V_352 ;
int V_353 = 0 , V_354 ;
int V_32 = 0 ;
int V_531 = 0 ;
V_32 = F_148 ( V_349 -> V_82 , sizeof( struct V_126 ) , V_356 ,
V_357 , V_362 , NULL ) ;
if ( V_32 < 0 ) {
return - V_378 ;
} else if ( V_32 == 0 ) {
if ( V_356 [ V_317 ] )
V_530 = F_149 ( V_356 [ V_317 ] ) ;
}
V_529 = V_127 -> V_294 ;
if ( V_530 ) {
V_516 = F_168 ( V_33 , V_530 ) ;
if ( ! V_516 )
return - V_420 ;
V_25 = V_516 -> V_178 ;
}
V_352 = V_349 -> args [ 0 ] ;
V_354 = V_349 -> args [ 1 ] ;
for ( V_351 = V_352 ; V_351 < V_365 ; V_351 ++ , V_354 = 0 ) {
V_353 = 0 ;
V_3 = & V_33 -> V_366 [ V_351 ] ;
F_150 (dev, head, index_hlist) {
if ( V_529 && ( V_35 -> V_295 != V_529 ) )
continue;
if ( ! V_530 ) {
if ( V_35 -> V_514 & V_515 ) {
V_516 = F_47 ( V_35 ) ;
V_528 = V_516 -> V_178 ;
}
} else {
if ( V_35 != V_516 &&
! ( V_35 -> V_514 & V_515 ) )
continue;
if ( V_516 != F_47 ( V_35 ) &&
! ( V_35 -> V_514 & V_532 ) )
continue;
V_528 = V_25 ;
}
if ( V_353 < V_354 )
goto V_367;
if ( V_35 -> V_514 & V_515 ) {
if ( V_528 && V_528 -> V_533 ) {
V_32 = V_528 -> V_533 ( V_56 , V_349 ,
V_516 , V_35 ,
& V_531 ) ;
if ( V_32 == - V_59 )
goto V_71;
}
}
if ( V_35 -> V_178 -> V_533 )
V_32 = V_35 -> V_178 -> V_533 ( V_56 , V_349 ,
V_35 , NULL ,
& V_531 ) ;
else
V_32 = F_243 ( V_56 , V_349 , V_35 , NULL ,
& V_531 ) ;
if ( V_32 == - V_59 )
goto V_71;
V_528 = NULL ;
V_349 -> args [ 2 ] = 0 ;
V_531 = 0 ;
V_367:
V_353 ++ ;
}
}
V_71:
V_349 -> args [ 0 ] = V_351 ;
V_349 -> args [ 1 ] = V_353 ;
V_349 -> args [ 2 ] = V_531 ;
return V_56 -> V_371 ;
}
static int F_247 ( struct V_2 * V_56 , T_5 V_83 , T_5 V_534 ,
unsigned int V_535 , unsigned int V_536 )
{
if ( V_534 & V_536 )
return F_124 ( V_56 , V_535 , ! ! ( V_83 & V_536 ) ) ;
return 0 ;
}
int F_248 ( struct V_2 * V_56 , T_5 V_73 , T_5 V_286 ,
struct V_34 * V_35 , T_10 V_537 ,
T_5 V_83 , T_5 V_534 , int V_491 ,
T_5 V_538 ,
int (* F_249)( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_5 V_538 ) )
{
struct V_81 * V_82 ;
struct V_126 * V_127 ;
struct V_47 * V_539 ;
struct V_47 * V_540 ;
T_9 V_118 = F_129 ( V_35 ) ? V_35 -> V_118 : V_300 ;
struct V_34 * V_516 = F_47 ( V_35 ) ;
int V_32 = 0 ;
V_82 = F_126 ( V_56 , V_73 , V_286 , V_368 , sizeof( * V_127 ) , V_491 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_127 ( V_82 ) ;
V_127 -> V_290 = V_496 ;
V_127 -> V_292 = 0 ;
V_127 -> V_293 = V_35 -> type ;
V_127 -> V_294 = V_35 -> V_295 ;
V_127 -> V_128 = F_128 ( V_35 ) ;
V_127 -> V_129 = 0 ;
if ( F_57 ( V_56 , V_296 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_303 , V_35 -> V_304 ) ||
F_124 ( V_56 , V_299 , V_118 ) ||
( V_516 &&
F_78 ( V_56 , V_317 , V_516 -> V_295 ) ) ||
( V_35 -> V_327 &&
F_84 ( V_56 , V_328 , V_35 -> V_327 , V_35 -> V_329 ) ) ||
( V_35 -> V_295 != F_131 ( V_35 ) &&
F_78 ( V_56 , V_316 , F_131 ( V_35 ) ) ) )
goto V_95;
V_539 = F_58 ( V_56 , V_336 ) ;
if ( ! V_539 )
goto V_95;
if ( F_250 ( V_56 , V_541 , V_542 ) ) {
F_60 ( V_56 , V_539 ) ;
goto V_95;
}
if ( V_537 != V_543 ) {
if ( F_250 ( V_56 , V_544 , V_537 ) ) {
F_60 ( V_56 , V_539 ) ;
goto V_95;
}
}
if ( F_249 ) {
V_32 = F_249 ( V_56 , V_35 , V_538 ) ;
if ( V_32 ) {
F_60 ( V_56 , V_539 ) ;
goto V_95;
}
}
F_59 ( V_56 , V_539 ) ;
V_540 = F_58 ( V_56 , V_474 | V_545 ) ;
if ( ! V_540 )
goto V_95;
if ( F_247 ( V_56 , V_83 , V_534 ,
V_546 , V_547 ) ||
F_247 ( V_56 , V_83 , V_534 ,
V_548 , V_549 ) ||
F_247 ( V_56 , V_83 , V_534 ,
V_550 ,
V_551 ) ||
F_247 ( V_56 , V_83 , V_534 ,
V_552 , V_553 ) ||
F_247 ( V_56 , V_83 , V_534 ,
V_554 , V_555 ) ||
F_247 ( V_56 , V_83 , V_534 ,
V_556 , V_557 ) ||
F_247 ( V_56 , V_83 , V_534 ,
V_558 , V_559 ) ||
F_247 ( V_56 , V_83 , V_534 ,
V_560 , V_561 ) ) {
F_60 ( V_56 , V_540 ) ;
goto V_95;
}
F_59 ( V_56 , V_540 ) ;
F_137 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_138 ( V_56 , V_82 ) ;
return V_32 ? V_32 : - V_59 ;
}
static int F_251 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_34 * V_35 ;
int V_353 = 0 ;
T_5 V_369 = F_64 ( V_349 -> V_56 ) . V_369 ;
T_5 V_286 = V_349 -> V_82 -> V_370 ;
T_5 V_538 = 0 ;
int V_32 ;
if ( F_147 ( V_349 -> V_82 ) > sizeof( struct V_126 ) ) {
struct V_47 * V_562 ;
V_562 = F_252 ( V_349 -> V_82 , sizeof( struct V_126 ) ,
V_363 ) ;
if ( V_562 ) {
if ( F_161 ( V_562 ) < sizeof( V_538 ) )
return - V_378 ;
V_538 = F_149 ( V_562 ) ;
}
}
F_253 () ;
F_254 (net, dev) {
const struct V_276 * V_25 = V_35 -> V_178 ;
struct V_34 * V_516 = F_47 ( V_35 ) ;
if ( V_516 && V_516 -> V_178 -> V_563 ) {
if ( V_353 >= V_349 -> args [ 0 ] ) {
V_32 = V_516 -> V_178 -> V_563 (
V_56 , V_369 , V_286 , V_35 ,
V_538 , V_358 ) ;
if ( V_32 < 0 && V_32 != - V_197 ) {
if ( F_151 ( V_56 -> V_371 ) )
break;
goto V_372;
}
}
V_353 ++ ;
}
if ( V_25 -> V_563 ) {
if ( V_353 >= V_349 -> args [ 0 ] ) {
V_32 = V_25 -> V_563 ( V_56 , V_369 ,
V_286 , V_35 ,
V_538 ,
V_358 ) ;
if ( V_32 < 0 && V_32 != - V_197 ) {
if ( F_151 ( V_56 -> V_371 ) )
break;
goto V_372;
}
}
V_353 ++ ;
}
}
V_32 = V_56 -> V_371 ;
V_372:
F_255 () ;
V_349 -> args [ 0 ] = V_353 ;
return V_32 ;
}
static inline T_4 F_256 ( void )
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
static int F_257 ( struct V_34 * V_35 )
{
struct V_33 * V_33 = F_134 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_197 ;
if ( ! V_35 -> V_178 -> V_563 )
return 0 ;
V_56 = F_215 ( F_256 () , V_505 ) ;
if ( ! V_56 ) {
V_32 = - V_425 ;
goto V_411;
}
V_32 = V_35 -> V_178 -> V_563 ( V_56 , 0 , 0 , V_35 , 0 , 0 ) ;
if ( V_32 < 0 )
goto V_411;
if ( ! V_56 -> V_371 )
goto V_411;
F_70 ( V_56 , V_33 , 0 , V_487 , NULL , V_505 ) ;
return 0 ;
V_411:
F_216 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
if ( V_32 )
F_73 ( V_33 , V_487 , V_32 ) ;
return V_32 ;
}
static int F_258 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_564 , * V_202 = NULL ;
int V_379 , V_32 = - V_197 ;
T_10 V_83 = 0 ;
bool V_565 = false ;
if ( F_147 ( V_82 ) < sizeof( * V_127 ) )
return - V_378 ;
V_127 = F_127 ( V_82 ) ;
if ( V_127 -> V_290 != V_496 )
return - V_566 ;
V_35 = F_168 ( V_33 , V_127 -> V_294 ) ;
if ( ! V_35 ) {
F_228 ( L_16 ) ;
return - V_420 ;
}
V_564 = F_252 ( V_82 , sizeof( struct V_126 ) , V_336 ) ;
if ( V_564 ) {
F_162 (attr, br_spec, rem) {
if ( F_163 ( V_202 ) == V_541 ) {
if ( F_161 ( V_202 ) < sizeof( V_83 ) )
return - V_378 ;
V_565 = true ;
V_83 = F_235 ( V_202 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_567 ) ) {
struct V_34 * V_516 = F_47 ( V_35 ) ;
if ( ! V_516 || ! V_516 -> V_178 -> V_568 ) {
V_32 = - V_197 ;
goto V_71;
}
V_32 = V_516 -> V_178 -> V_568 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_567 ;
}
if ( ( V_83 & V_542 ) ) {
if ( ! V_35 -> V_178 -> V_568 )
V_32 = - V_197 ;
else
V_32 = V_35 -> V_178 -> V_568 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_542 ;
V_32 = F_257 ( V_35 ) ;
}
}
if ( V_565 )
memcpy ( F_111 ( V_202 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static int F_259 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_564 , * V_202 = NULL ;
int V_379 , V_32 = - V_197 ;
T_10 V_83 = 0 ;
bool V_565 = false ;
if ( F_147 ( V_82 ) < sizeof( * V_127 ) )
return - V_378 ;
V_127 = F_127 ( V_82 ) ;
if ( V_127 -> V_290 != V_496 )
return - V_566 ;
V_35 = F_168 ( V_33 , V_127 -> V_294 ) ;
if ( ! V_35 ) {
F_228 ( L_16 ) ;
return - V_420 ;
}
V_564 = F_252 ( V_82 , sizeof( struct V_126 ) , V_336 ) ;
if ( V_564 ) {
F_162 (attr, br_spec, rem) {
if ( F_163 ( V_202 ) == V_541 ) {
if ( F_161 ( V_202 ) < sizeof( V_83 ) )
return - V_378 ;
V_565 = true ;
V_83 = F_235 ( V_202 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_567 ) ) {
struct V_34 * V_516 = F_47 ( V_35 ) ;
if ( ! V_516 || ! V_516 -> V_178 -> V_569 ) {
V_32 = - V_197 ;
goto V_71;
}
V_32 = V_516 -> V_178 -> V_569 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_567 ;
}
if ( ( V_83 & V_542 ) ) {
if ( ! V_35 -> V_178 -> V_569 )
V_32 = - V_197 ;
else
V_32 = V_35 -> V_178 -> V_569 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_542 ;
V_32 = F_257 ( V_35 ) ;
}
}
if ( V_565 )
memcpy ( F_111 ( V_202 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static bool F_260 ( unsigned int V_534 , int V_570 , int V_571 )
{
return ( V_534 & F_261 ( V_570 ) ) &&
( ! V_571 || V_571 == V_570 ) ;
}
static int F_262 ( int V_572 )
{
switch ( V_572 ) {
case V_573 :
return sizeof( struct V_132 ) ;
}
return 0 ;
}
static int F_263 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int * V_574 )
{
struct V_47 * V_202 = NULL ;
int V_572 , V_48 ;
void * V_575 ;
int V_32 ;
if ( ! ( V_35 -> V_178 && V_35 -> V_178 -> V_576 &&
V_35 -> V_178 -> V_577 ) )
return - V_339 ;
for ( V_572 = V_578 ;
V_572 <= V_579 ; V_572 ++ ) {
if ( V_572 < * V_574 )
continue;
V_48 = F_262 ( V_572 ) ;
if ( ! V_48 )
continue;
if ( ! V_35 -> V_178 -> V_576 ( V_35 , V_572 ) )
continue;
V_202 = F_110 ( V_56 , V_572 , V_48 ,
V_580 ) ;
if ( ! V_202 )
goto V_95;
V_575 = F_111 ( V_202 ) ;
memset ( V_575 , 0 , V_48 ) ;
V_32 = V_35 -> V_178 -> V_577 ( V_572 , V_35 ,
V_575 ) ;
if ( V_32 )
goto V_581;
}
if ( ! V_202 )
return - V_339 ;
* V_574 = 0 ;
return 0 ;
V_95:
V_32 = - V_59 ;
V_581:
* V_574 = V_572 ;
return V_32 ;
}
static int F_264 ( const struct V_34 * V_35 )
{
int V_582 = 0 ;
int V_572 ;
int V_48 ;
if ( ! ( V_35 -> V_178 && V_35 -> V_178 -> V_576 &&
V_35 -> V_178 -> V_577 ) )
return 0 ;
for ( V_572 = V_578 ;
V_572 <= V_579 ; V_572 ++ ) {
if ( ! V_35 -> V_178 -> V_576 ( V_35 , V_572 ) )
continue;
V_48 = F_262 ( V_572 ) ;
V_582 += F_95 ( V_48 ) ;
}
if ( V_582 != 0 )
V_582 += F_48 ( 0 ) ;
return V_582 ;
}
static int F_265 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_286 , T_5 V_287 ,
unsigned int V_83 , unsigned int V_538 ,
int * V_571 , int * V_574 )
{
struct V_583 * V_584 ;
struct V_81 * V_82 ;
struct V_47 * V_202 ;
int V_585 = * V_574 ;
int V_32 ;
F_120 () ;
V_82 = F_126 ( V_56 , V_73 , V_286 , type , sizeof( * V_584 ) , V_83 ) ;
if ( ! V_82 )
return - V_59 ;
V_584 = F_127 ( V_82 ) ;
V_584 -> V_295 = V_35 -> V_295 ;
V_584 -> V_538 = V_538 ;
if ( F_260 ( V_538 , V_586 , * V_571 ) ) {
struct V_132 * V_208 ;
V_202 = F_110 ( V_56 , V_586 ,
sizeof( struct V_132 ) ,
V_587 ) ;
if ( ! V_202 )
goto V_95;
V_208 = F_111 ( V_202 ) ;
F_112 ( V_35 , V_208 ) ;
}
if ( F_260 ( V_538 , V_588 , * V_571 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
if ( V_25 && V_25 -> V_589 ) {
* V_571 = V_588 ;
V_202 = F_58 ( V_56 ,
V_588 ) ;
if ( ! V_202 )
goto V_95;
V_32 = V_25 -> V_589 ( V_56 , V_35 , V_574 , * V_571 ) ;
F_59 ( V_56 , V_202 ) ;
if ( V_32 )
goto V_95;
* V_571 = 0 ;
}
}
if ( F_260 ( V_538 , V_590 ,
* V_571 ) ) {
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_346 ;
V_346 = F_47 ( V_35 ) ;
if ( V_346 )
V_25 = V_346 -> V_23 ;
if ( V_25 && V_25 -> V_589 ) {
* V_571 = V_590 ;
V_202 = F_58 ( V_56 ,
V_590 ) ;
if ( ! V_202 )
goto V_95;
V_32 = V_25 -> V_589 ( V_56 , V_35 , V_574 , * V_571 ) ;
F_59 ( V_56 , V_202 ) ;
if ( V_32 )
goto V_95;
* V_571 = 0 ;
}
}
if ( F_260 ( V_538 , V_591 ,
* V_571 ) ) {
* V_571 = V_591 ;
V_202 = F_58 ( V_56 , V_591 ) ;
if ( ! V_202 )
goto V_95;
V_32 = F_263 ( V_56 , V_35 , V_574 ) ;
if ( V_32 == - V_339 )
F_60 ( V_56 , V_202 ) ;
else
F_59 ( V_56 , V_202 ) ;
if ( V_32 && V_32 != - V_339 )
goto V_95;
* V_571 = 0 ;
}
if ( F_260 ( V_538 , V_592 , * V_571 ) ) {
struct V_51 * V_54 ;
* V_571 = V_592 ;
V_202 = F_58 ( V_56 , V_592 ) ;
if ( ! V_202 )
goto V_95;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_593 ) {
struct V_47 * V_338 ;
int V_32 ;
V_338 = F_58 ( V_56 , V_54 -> V_52 ) ;
if ( ! V_338 )
goto V_95;
V_32 = V_54 -> V_593 ( V_56 , V_35 ) ;
if ( V_32 == - V_339 )
F_60 ( V_56 , V_338 ) ;
else if ( V_32 < 0 )
goto V_95;
F_59 ( V_56 , V_338 ) ;
}
}
F_59 ( V_56 , V_202 ) ;
* V_571 = 0 ;
}
F_137 ( V_56 , V_82 ) ;
return 0 ;
V_95:
if ( ! ( V_83 & V_358 ) || V_585 == * V_574 )
F_138 ( V_56 , V_82 ) ;
else
F_137 ( V_56 , V_82 ) ;
return - V_59 ;
}
static T_4 F_266 ( const struct V_34 * V_35 ,
T_5 V_538 )
{
T_4 V_48 = 0 ;
if ( F_260 ( V_538 , V_586 , 0 ) )
V_48 += F_95 ( sizeof( struct V_132 ) ) ;
if ( F_260 ( V_538 , V_588 , 0 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
int V_202 = V_588 ;
if ( V_25 && V_25 -> V_594 ) {
V_48 += F_48 ( V_25 -> V_594 ( V_35 ,
V_202 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
if ( F_260 ( V_538 , V_590 , 0 ) ) {
struct V_34 * V_595 = (struct V_34 * ) V_35 ;
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_346 ;
V_346 = F_47 ( V_595 ) ;
if ( V_346 )
V_25 = V_346 -> V_23 ;
if ( V_25 && V_25 -> V_594 ) {
int V_202 = V_590 ;
V_48 += F_48 ( V_25 -> V_594 ( V_35 ,
V_202 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
if ( F_260 ( V_538 , V_591 , 0 ) )
V_48 += F_264 ( V_35 ) ;
if ( F_260 ( V_538 , V_592 , 0 ) ) {
struct V_51 * V_54 ;
V_48 += F_48 ( 0 ) ;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_596 ) {
V_48 += F_48 (
V_54 -> V_596 ( V_35 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
}
return V_48 ;
}
static int F_267 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
struct V_34 * V_35 = NULL ;
int V_571 = 0 , V_574 = 0 ;
struct V_583 * V_584 ;
struct V_2 * V_480 ;
T_5 V_538 ;
int V_32 ;
if ( F_147 ( V_82 ) < sizeof( * V_584 ) )
return - V_378 ;
V_584 = F_127 ( V_82 ) ;
if ( V_584 -> V_295 > 0 )
V_35 = F_168 ( V_33 , V_584 -> V_295 ) ;
else
return - V_378 ;
if ( ! V_35 )
return - V_420 ;
V_538 = V_584 -> V_538 ;
if ( ! V_538 )
return - V_378 ;
V_480 = F_215 ( F_266 ( V_35 , V_538 ) , V_20 ) ;
if ( ! V_480 )
return - V_21 ;
V_32 = F_265 ( V_480 , V_35 , V_597 ,
F_64 ( V_56 ) . V_369 , V_82 -> V_370 , 0 ,
0 , V_538 , & V_571 , & V_574 ) ;
if ( V_32 < 0 ) {
F_216 ( V_32 == - V_59 ) ;
F_6 ( V_480 ) ;
} else {
V_32 = F_68 ( V_480 , V_33 , F_64 ( V_56 ) . V_369 ) ;
}
return V_32 ;
}
static int F_268 ( struct V_2 * V_56 , struct V_348 * V_349 )
{
int V_351 , V_352 , V_32 , V_354 , V_598 , V_585 ;
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
unsigned int V_83 = V_358 ;
struct V_583 * V_584 ;
struct V_355 * V_3 ;
struct V_34 * V_35 ;
T_5 V_538 = 0 ;
int V_353 = 0 ;
V_352 = V_349 -> args [ 0 ] ;
V_354 = V_349 -> args [ 1 ] ;
V_598 = V_349 -> args [ 2 ] ;
V_585 = V_349 -> args [ 3 ] ;
V_349 -> V_286 = V_33 -> V_360 ;
if ( F_147 ( V_349 -> V_82 ) < sizeof( * V_584 ) )
return - V_378 ;
V_584 = F_127 ( V_349 -> V_82 ) ;
V_538 = V_584 -> V_538 ;
if ( ! V_538 )
return - V_378 ;
for ( V_351 = V_352 ; V_351 < V_365 ; V_351 ++ , V_354 = 0 ) {
V_353 = 0 ;
V_3 = & V_33 -> V_366 [ V_351 ] ;
F_150 (dev, head, index_hlist) {
if ( V_353 < V_354 )
goto V_367;
V_32 = F_265 ( V_56 , V_35 , V_597 ,
F_64 ( V_349 -> V_56 ) . V_369 ,
V_349 -> V_82 -> V_370 , 0 ,
V_83 , V_538 ,
& V_598 , & V_585 ) ;
F_216 ( ( V_32 == - V_59 ) && ( V_56 -> V_371 == 0 ) ) ;
if ( V_32 < 0 )
goto V_71;
V_585 = 0 ;
V_598 = 0 ;
F_152 ( V_349 , F_153 ( V_56 ) ) ;
V_367:
V_353 ++ ;
}
}
V_71:
V_349 -> args [ 3 ] = V_585 ;
V_349 -> args [ 2 ] = V_598 ;
V_349 -> args [ 1 ] = V_353 ;
V_349 -> args [ 0 ] = V_351 ;
return V_56 -> V_371 ;
}
static int F_269 ( struct V_2 * V_56 , struct V_81 * V_82 ,
struct V_373 * V_408 )
{
struct V_33 * V_33 = F_146 ( V_56 -> V_350 ) ;
T_1 V_16 ;
int V_24 ;
int V_52 ;
int type ;
int V_32 ;
type = V_82 -> V_483 ;
if ( type > V_599 )
return - V_197 ;
type -= V_9 ;
if ( F_147 ( V_82 ) < sizeof( struct V_361 ) )
return 0 ;
V_52 = ( (struct V_361 * ) F_127 ( V_82 ) ) -> V_600 ;
V_24 = type & 3 ;
if ( V_24 != 2 && ! F_270 ( V_56 , V_413 ) )
return - V_414 ;
if ( V_24 == 2 && V_82 -> V_468 & V_601 ) {
struct V_76 * V_77 ;
T_2 V_18 ;
T_3 V_19 ;
T_10 V_602 = 0 ;
V_18 = F_19 ( V_52 , type ) ;
if ( V_18 == NULL )
return - V_197 ;
V_19 = F_20 ( V_52 , type ) ;
if ( V_19 )
V_602 = V_19 ( V_56 , V_82 ) ;
F_4 () ;
V_77 = V_33 -> V_77 ;
{
struct V_603 V_604 = {
. V_605 = V_18 ,
. V_602 = V_602 ,
} ;
V_32 = F_271 ( V_77 , V_56 , V_82 , & V_604 ) ;
}
F_1 () ;
return V_32 ;
}
V_16 = F_18 ( V_52 , type ) ;
if ( V_16 == NULL )
return - V_197 ;
return V_16 ( V_56 , V_82 , V_408 ) ;
}
static void F_272 ( struct V_2 * V_56 )
{
F_1 () ;
F_273 ( V_56 , & F_269 ) ;
F_8 () ;
}
static int F_274 ( struct V_606 * V_607 , unsigned long V_608 , void * V_609 )
{
struct V_34 * V_35 = F_275 ( V_609 ) ;
switch ( V_608 ) {
case V_610 :
case V_611 :
case V_612 :
case V_613 :
case V_614 :
case V_615 :
case V_616 :
F_223 ( V_368 , V_35 , 0 , V_20 ) ;
break;
default:
break;
}
return V_617 ;
}
static int T_12 F_276 ( struct V_33 * V_33 )
{
struct V_76 * V_350 ;
struct V_618 V_619 = {
. V_620 = V_621 ,
. V_622 = F_272 ,
. V_623 = & V_1 ,
. V_83 = V_624 ,
} ;
V_350 = F_277 ( V_33 , V_625 , & V_619 ) ;
if ( ! V_350 )
return - V_425 ;
V_33 -> V_77 = V_350 ;
return 0 ;
}
static void T_13 F_278 ( struct V_33 * V_33 )
{
F_279 ( V_33 -> V_77 ) ;
V_33 -> V_77 = NULL ;
}
void T_14 F_280 ( void )
{
if ( F_281 ( & V_626 ) )
F_24 ( L_17 ) ;
F_282 ( & V_627 ) ;
F_23 ( V_17 , V_628 , F_214 ,
F_145 , F_217 ) ;
F_23 ( V_17 , V_629 , F_193 , NULL , NULL ) ;
F_23 ( V_17 , V_368 , F_207 , NULL , NULL ) ;
F_23 ( V_17 , V_630 , F_198 , NULL , NULL ) ;
F_23 ( V_17 , V_631 , NULL , F_220 , NULL ) ;
F_23 ( V_17 , V_632 , NULL , F_220 , NULL ) ;
F_23 ( V_17 , V_633 , NULL , F_220 , NULL ) ;
F_23 ( V_634 , V_518 , F_236 , NULL , NULL ) ;
F_23 ( V_634 , V_520 , F_240 , NULL , NULL ) ;
F_23 ( V_634 , V_635 , NULL , F_246 , NULL ) ;
F_23 ( V_634 , V_628 , NULL , F_251 , NULL ) ;
F_23 ( V_634 , V_630 , F_259 , NULL , NULL ) ;
F_23 ( V_634 , V_629 , F_258 , NULL , NULL ) ;
F_23 ( V_17 , V_636 , F_267 , F_268 ,
NULL ) ;
}
