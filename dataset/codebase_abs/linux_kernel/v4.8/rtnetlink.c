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
T_4 V_48 = F_48 ( sizeof( struct V_47 ) ) ;
V_48 += F_48 ( V_160 * sizeof( struct V_47 ) ) ;
V_48 += V_160 *
( F_48 ( sizeof( struct V_161 ) ) +
F_48 ( sizeof( struct V_162 ) ) +
F_48 ( sizeof( struct V_163 ) ) +
F_48 ( sizeof( struct V_164 ) ) +
F_48 ( sizeof( struct V_165 ) ) +
F_48 ( sizeof( struct V_166 ) ) +
F_96 ( sizeof( V_167 ) ) +
F_96 ( sizeof( V_167 ) ) +
F_96 ( sizeof( V_167 ) ) +
F_96 ( sizeof( V_167 ) ) +
F_96 ( sizeof( V_167 ) ) +
F_96 ( sizeof( V_167 ) ) +
F_48 ( sizeof( struct V_168 ) ) ) ;
return V_48 ;
} else
return 0 ;
}
static T_4 F_97 ( const struct V_34 * V_35 ,
T_5 V_53 )
{
T_4 V_169 = F_48 ( 4 )
+ F_48 ( V_170 )
+ F_48 ( sizeof( struct V_171 ) )
+ F_48 ( V_172 )
+ F_48 ( V_172 )
+ F_48 ( 1 )
+ F_48 ( 2 ) ;
T_4 V_173 = F_48 ( sizeof( struct V_47 ) ) ;
T_4 V_174 = F_48 ( sizeof( struct V_47 ) )
+ V_169 ;
T_4 V_175 = F_48 ( sizeof( struct V_47 ) )
+ V_169 ;
if ( ! V_35 -> V_176 -> V_177 || ! V_35 -> V_35 . V_158 ||
! ( V_53 & V_159 ) )
return 0 ;
if ( F_95 ( V_35 -> V_35 . V_158 ) )
return V_175 + V_173 +
V_174 * F_95 ( V_35 -> V_35 . V_158 ) ;
else
return V_175 ;
}
static T_4 F_98 ( const struct V_34 * V_35 )
{
T_4 V_178 = F_48 ( 1 ) ;
if ( ! V_35 -> V_176 -> V_179 )
return 0 ;
else
return V_178 ;
}
static T_7 T_4 F_99 ( const struct V_34 * V_35 ,
T_5 V_53 )
{
return F_100 ( sizeof( struct V_126 ) )
+ F_48 ( V_180 )
+ F_48 ( V_181 )
+ F_48 ( V_180 )
+ F_96 ( sizeof( struct V_182 ) )
+ F_48 ( sizeof( struct V_130 ) )
+ F_96 ( sizeof( struct V_132 ) )
+ F_48 ( V_183 )
+ F_48 ( V_183 )
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
+ F_48 ( V_184 )
+ F_48 ( V_184 )
+ F_48 ( V_180 )
+ F_98 ( V_35 )
+ F_48 ( 1 ) ;
}
static int F_101 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_185 ;
struct V_47 * V_186 ;
int V_187 ;
int V_32 ;
V_185 = F_58 ( V_56 , V_188 ) ;
if ( ! V_185 )
return - V_59 ;
for ( V_187 = 0 ; V_187 < F_95 ( V_35 -> V_35 . V_158 ) ; V_187 ++ ) {
V_186 = F_58 ( V_56 , V_189 ) ;
if ( ! V_186 )
goto V_95;
if ( F_78 ( V_56 , V_190 , V_187 ) )
goto V_95;
V_32 = V_35 -> V_176 -> V_177 ( V_35 , V_187 , V_56 ) ;
if ( V_32 == - V_59 )
goto V_95;
if ( V_32 ) {
F_60 ( V_56 , V_186 ) ;
continue;
}
F_59 ( V_56 , V_186 ) ;
}
F_59 ( V_56 , V_185 ) ;
return 0 ;
V_95:
F_60 ( V_56 , V_185 ) ;
return - V_59 ;
}
static int F_102 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_47 * V_191 ;
int V_32 ;
V_191 = F_58 ( V_56 , V_192 ) ;
if ( ! V_191 )
return - V_59 ;
V_32 = V_35 -> V_176 -> V_177 ( V_35 , V_193 , V_56 ) ;
if ( V_32 ) {
F_60 ( V_56 , V_191 ) ;
return ( V_32 == - V_59 ) ? V_32 : 0 ;
}
F_59 ( V_56 , V_191 ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_56 , struct V_34 * V_35 ,
T_5 V_53 )
{
int V_32 ;
if ( ! V_35 -> V_176 -> V_177 || ! V_35 -> V_35 . V_158 ||
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
struct V_194 V_195 ;
V_32 = F_105 ( V_35 , & V_195 ) ;
if ( V_32 ) {
if ( V_32 == - V_196 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_197 , V_195 . V_198 , V_195 . V_102 ) )
return - V_59 ;
return 0 ;
}
static int F_106 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
char V_94 [ V_180 ] ;
int V_32 ;
V_32 = F_107 ( V_35 , V_94 , sizeof( V_94 ) ) ;
if ( V_32 ) {
if ( V_32 == - V_196 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_199 , strlen ( V_94 ) , V_94 ) )
return - V_59 ;
return 0 ;
}
static int F_108 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
int V_32 ;
struct V_200 V_201 = {
. V_202 = V_35 ,
. V_102 = V_203 ,
. V_83 = V_204 ,
} ;
V_32 = F_109 ( V_35 , & V_201 ) ;
if ( V_32 ) {
if ( V_32 == - V_196 )
return 0 ;
return V_32 ;
}
if ( F_84 ( V_56 , V_205 , V_201 . V_206 . V_195 . V_198 ,
V_201 . V_206 . V_195 . V_102 ) )
return - V_59 ;
return 0 ;
}
static T_8 int F_110 ( struct V_2 * V_56 ,
struct V_34 * V_35 )
{
struct V_132 * V_207 ;
struct V_47 * V_201 ;
V_201 = F_111 ( V_56 , V_208 ,
sizeof( struct V_132 ) , V_209 ) ;
if ( ! V_201 )
return - V_59 ;
V_207 = F_112 ( V_201 ) ;
F_113 ( V_35 , V_207 ) ;
V_201 = F_114 ( V_56 , V_210 ,
sizeof( struct V_130 ) ) ;
if ( ! V_201 )
return - V_59 ;
F_92 ( F_112 ( V_201 ) , V_207 ) ;
return 0 ;
}
static T_8 int F_115 ( struct V_2 * V_56 ,
struct V_34 * V_35 ,
int V_211 ,
struct V_47 * V_212 )
{
struct V_166 V_213 ;
struct V_165 V_214 ;
struct V_163 V_215 ;
struct V_216 V_217 ;
struct V_218 V_219 ;
struct V_168 V_220 ;
struct V_162 V_221 ;
struct V_164 V_222 ;
struct V_47 * V_187 , * V_223 ;
struct V_161 V_224 ;
struct V_225 V_226 ;
V_226 . V_227 = - 1 ;
V_226 . V_228 = - 1 ;
V_226 . V_229 = - 1 ;
memset ( V_226 . V_230 , 0 , sizeof( V_226 . V_230 ) ) ;
V_226 . V_231 = 0 ;
if ( V_35 -> V_176 -> V_232 ( V_35 , V_211 , & V_226 ) )
return 0 ;
V_224 . V_187 =
V_221 . V_187 =
V_222 . V_187 =
V_217 . V_187 =
V_215 . V_187 =
V_214 . V_187 =
V_213 . V_187 =
V_220 . V_187 = V_226 . V_187 ;
memcpy ( V_224 . V_230 , V_226 . V_230 , sizeof( V_226 . V_230 ) ) ;
V_221 . V_233 = V_226 . V_233 ;
V_221 . V_234 = V_226 . V_234 ;
V_217 . V_235 = V_226 . V_236 ;
V_222 . V_237 = V_226 . V_237 ;
V_222 . V_236 = V_226 . V_236 ;
V_215 . V_238 = V_226 . V_227 ;
V_214 . V_239 = V_226 . V_231 ;
V_213 . V_238 = V_226 . V_228 ;
V_220 . V_238 = V_226 . V_229 ;
V_187 = F_58 ( V_56 , V_240 ) ;
if ( ! V_187 ) {
F_60 ( V_56 , V_212 ) ;
return - V_59 ;
}
if ( F_84 ( V_56 , V_241 , sizeof( V_224 ) , & V_224 ) ||
F_84 ( V_56 , V_242 , sizeof( V_221 ) , & V_221 ) ||
F_84 ( V_56 , V_243 , sizeof( V_222 ) ,
& V_222 ) ||
F_84 ( V_56 , V_244 , sizeof( V_217 ) ,
& V_217 ) ||
F_84 ( V_56 , V_245 , sizeof( V_215 ) ,
& V_215 ) ||
F_84 ( V_56 , V_246 , sizeof( V_214 ) ,
& V_214 ) ||
F_84 ( V_56 , V_247 ,
sizeof( V_213 ) ,
& V_213 ) ||
F_84 ( V_56 , V_248 ,
sizeof( V_220 ) , & V_220 ) )
return - V_59 ;
memset ( & V_219 , 0 , sizeof( V_219 ) ) ;
if ( V_35 -> V_176 -> V_249 )
V_35 -> V_176 -> V_249 ( V_35 , V_211 ,
& V_219 ) ;
V_223 = F_58 ( V_56 , V_250 ) ;
if ( ! V_223 ) {
F_60 ( V_56 , V_187 ) ;
F_60 ( V_56 , V_212 ) ;
return - V_59 ;
}
if ( F_116 ( V_56 , V_251 ,
V_219 . V_134 , V_252 ) ||
F_116 ( V_56 , V_253 ,
V_219 . V_135 , V_252 ) ||
F_116 ( V_56 , V_254 ,
V_219 . V_136 , V_252 ) ||
F_116 ( V_56 , V_255 ,
V_219 . V_137 , V_252 ) ||
F_116 ( V_56 , V_256 ,
V_219 . V_257 , V_252 ) ||
F_116 ( V_56 , V_258 ,
V_219 . V_142 , V_252 ) )
return - V_59 ;
F_59 ( V_56 , V_223 ) ;
F_59 ( V_56 , V_187 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_182 V_259 ;
memset ( & V_259 , 0 , sizeof( V_259 ) ) ;
V_259 . V_260 = V_35 -> V_260 ;
V_259 . V_261 = V_35 -> V_261 ;
V_259 . V_262 = V_35 -> V_262 ;
V_259 . V_263 = V_35 -> V_263 ;
V_259 . V_264 = V_35 -> V_264 ;
V_259 . V_265 = V_35 -> V_266 ;
if ( F_118 ( V_56 , V_267 , sizeof( V_259 ) , & V_259 , V_209 ) )
return - V_59 ;
return 0 ;
}
static int F_119 ( struct V_2 * V_56 , struct V_34 * V_35 )
{
struct V_268 V_269 = {} ;
struct V_47 * V_270 ;
int V_32 ;
if ( ! V_35 -> V_176 -> V_179 )
return 0 ;
V_270 = F_58 ( V_56 , V_271 ) ;
if ( ! V_270 )
return - V_59 ;
V_269 . V_272 = V_273 ;
V_32 = V_35 -> V_176 -> V_179 ( V_35 , & V_269 ) ;
if ( V_32 )
goto V_274;
V_32 = F_120 ( V_56 , V_275 , V_269 . V_276 ) ;
if ( V_32 )
goto V_274;
F_59 ( V_56 , V_270 ) ;
return 0 ;
V_274:
F_60 ( V_56 , V_270 ) ;
return V_32 ;
}
static int F_121 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_277 , T_5 V_278 ,
unsigned int V_83 , T_5 V_53 )
{
struct V_126 * V_127 ;
struct V_81 * V_82 ;
struct V_47 * V_279 ;
struct V_51 * V_54 ;
struct V_34 * V_280 = F_47 ( V_35 ) ;
F_122 () ;
V_82 = F_123 ( V_56 , V_73 , V_277 , type , sizeof( * V_127 ) , V_83 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_124 ( V_82 ) ;
V_127 -> V_281 = V_282 ;
V_127 -> V_283 = 0 ;
V_127 -> V_284 = V_35 -> type ;
V_127 -> V_285 = V_35 -> V_286 ;
V_127 -> V_128 = F_125 ( V_35 ) ;
V_127 -> V_129 = V_278 ;
if ( F_57 ( V_56 , V_287 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_288 , V_35 -> V_289 ) ||
F_120 ( V_56 , V_290 ,
F_126 ( V_35 ) ? V_35 -> V_118 : V_291 ) ||
F_120 ( V_56 , V_292 , V_35 -> V_293 ) ||
F_78 ( V_56 , V_294 , V_35 -> V_295 ) ||
F_78 ( V_56 , V_296 , V_35 -> V_74 ) ||
F_78 ( V_56 , V_297 , V_35 -> V_298 ) ||
F_78 ( V_56 , V_299 , V_35 -> V_300 ) ||
F_78 ( V_56 , V_301 , V_35 -> V_302 ) ||
F_78 ( V_56 , V_303 , V_35 -> V_304 ) ||
#ifdef F_127
F_78 ( V_56 , V_305 , V_35 -> V_306 ) ||
#endif
( V_35 -> V_286 != F_128 ( V_35 ) &&
F_78 ( V_56 , V_307 , F_128 ( V_35 ) ) ) ||
( V_280 &&
F_78 ( V_56 , V_308 , V_280 -> V_286 ) ) ||
F_120 ( V_56 , V_309 , F_129 ( V_35 ) ) ||
( V_35 -> V_310 &&
F_57 ( V_56 , V_311 , V_35 -> V_310 -> V_25 -> V_102 ) ) ||
( V_35 -> V_312 &&
F_57 ( V_56 , V_313 , V_35 -> V_312 ) ) ||
F_78 ( V_56 , V_314 ,
F_81 ( & V_35 -> V_315 ) ) ||
F_120 ( V_56 , V_316 , V_35 -> V_317 ) )
goto V_95;
if ( F_117 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_318 ) {
if ( F_84 ( V_56 , V_319 , V_35 -> V_318 , V_35 -> V_320 ) ||
F_84 ( V_56 , V_321 , V_35 -> V_318 , V_35 -> V_257 ) )
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
F_78 ( V_56 , V_322 , F_95 ( V_35 -> V_35 . V_158 ) ) )
goto V_95;
if ( V_35 -> V_176 -> V_232 && V_35 -> V_35 . V_158 &&
V_53 & V_159 ) {
int V_87 ;
struct V_47 * V_212 ;
int V_160 = F_95 ( V_35 -> V_35 . V_158 ) ;
V_212 = F_58 ( V_56 , V_323 ) ;
if ( ! V_212 )
goto V_95;
for ( V_87 = 0 ; V_87 < V_160 ; V_87 ++ ) {
if ( F_115 ( V_56 , V_35 , V_87 , V_212 ) )
goto V_95;
}
F_59 ( V_56 , V_212 ) ;
}
if ( F_103 ( V_56 , V_35 , V_53 ) )
goto V_95;
if ( F_119 ( V_56 , V_35 ) )
goto V_95;
if ( V_35 -> V_23 || F_55 ( V_35 ) ) {
if ( F_62 ( V_56 , V_35 ) < 0 )
goto V_95;
}
if ( V_35 -> V_23 &&
V_35 -> V_23 -> V_324 ) {
struct V_33 * V_325 = V_35 -> V_23 -> V_324 ( V_35 ) ;
if ( ! F_130 ( F_131 ( V_35 ) , V_325 ) ) {
int V_102 = F_132 ( F_131 ( V_35 ) , V_325 ) ;
if ( F_133 ( V_56 , V_326 , V_102 ) )
goto V_95;
}
}
if ( ! ( V_279 = F_58 ( V_56 , V_327 ) ) )
goto V_95;
F_29 (af_ops, &rtnl_af_ops, list) {
if ( V_54 -> V_328 ) {
struct V_47 * V_329 ;
int V_32 ;
if ( ! ( V_329 = F_58 ( V_56 , V_54 -> V_52 ) ) )
goto V_95;
V_32 = V_54 -> V_328 ( V_56 , V_35 , V_53 ) ;
if ( V_32 == - V_330 )
F_60 ( V_56 , V_329 ) ;
else if ( V_32 < 0 )
goto V_95;
F_59 ( V_56 , V_329 ) ;
}
}
F_59 ( V_56 , V_279 ) ;
F_134 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_135 ( V_56 , V_82 ) ;
return - V_59 ;
}
static const struct V_23 * F_136 ( const struct V_47 * V_331 )
{
const struct V_23 * V_25 = NULL ;
struct V_47 * V_332 [ V_333 + 1 ] ;
if ( F_137 ( V_332 , V_333 , V_331 , V_334 ) < 0 )
return NULL ;
if ( V_332 [ V_64 ] ) {
char V_24 [ V_335 ] ;
F_138 ( V_24 , V_332 [ V_64 ] , sizeof( V_24 ) ) ;
V_25 = F_28 ( V_24 ) ;
}
return V_25 ;
}
static bool F_139 ( struct V_34 * V_35 , int V_336 )
{
struct V_34 * V_337 ;
if ( ! V_336 )
return false ;
V_337 = F_47 ( V_35 ) ;
if ( ! V_337 || V_337 -> V_286 != V_336 )
return true ;
return false ;
}
static bool F_140 ( const struct V_34 * V_35 ,
const struct V_23 * V_338 )
{
if ( V_338 && V_35 -> V_23 != V_338 )
return true ;
return false ;
}
static bool F_141 ( struct V_34 * V_35 ,
int V_336 ,
const struct V_23 * V_338 )
{
if ( F_139 ( V_35 , V_336 ) ||
F_140 ( V_35 , V_338 ) )
return true ;
return false ;
}
static int F_142 ( struct V_2 * V_56 , struct V_339 * V_340 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
int V_342 , V_343 ;
int V_344 = 0 , V_345 ;
struct V_34 * V_35 ;
struct V_346 * V_3 ;
struct V_47 * V_347 [ V_348 + 1 ] ;
T_5 V_53 = 0 ;
const struct V_23 * V_338 = NULL ;
unsigned int V_83 = V_349 ;
int V_336 = 0 ;
int V_32 ;
int V_350 ;
V_343 = V_340 -> args [ 0 ] ;
V_345 = V_340 -> args [ 1 ] ;
V_340 -> V_277 = V_33 -> V_351 ;
V_350 = F_144 ( V_340 -> V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_352 ) : sizeof( struct V_126 ) ;
if ( F_145 ( V_340 -> V_82 , V_350 , V_347 , V_348 , V_353 ) >= 0 ) {
if ( V_347 [ V_354 ] )
V_53 = F_146 ( V_347 [ V_354 ] ) ;
if ( V_347 [ V_308 ] )
V_336 = F_146 ( V_347 [ V_308 ] ) ;
if ( V_347 [ V_70 ] )
V_338 = F_136 ( V_347 [ V_70 ] ) ;
if ( V_336 || V_338 )
V_83 |= V_355 ;
}
for ( V_342 = V_343 ; V_342 < V_356 ; V_342 ++ , V_345 = 0 ) {
V_344 = 0 ;
V_3 = & V_33 -> V_357 [ V_342 ] ;
F_147 (dev, head, index_hlist) {
if ( F_141 ( V_35 , V_336 , V_338 ) )
continue;
if ( V_344 < V_345 )
goto V_358;
V_32 = F_121 ( V_56 , V_35 , V_359 ,
F_64 ( V_340 -> V_56 ) . V_360 ,
V_340 -> V_82 -> V_361 , 0 ,
V_83 ,
V_53 ) ;
F_148 ( ( V_32 == - V_59 ) && ( V_56 -> V_362 == 0 ) ) ;
if ( V_32 < 0 )
goto V_71;
F_149 ( V_340 , F_150 ( V_56 ) ) ;
V_358:
V_344 ++ ;
}
}
V_71:
V_340 -> args [ 1 ] = V_344 ;
V_340 -> args [ 0 ] = V_342 ;
return V_56 -> V_362 ;
}
int F_151 ( struct V_47 * * V_347 , const struct V_47 * V_3 , int V_362 )
{
return F_152 ( V_347 , V_348 , V_3 , V_362 , V_353 ) ;
}
struct V_33 * F_153 ( struct V_33 * V_363 , struct V_47 * V_347 [] )
{
struct V_33 * V_33 ;
if ( V_347 [ V_364 ] )
V_33 = F_154 ( F_146 ( V_347 [ V_364 ] ) ) ;
else if ( V_347 [ V_365 ] )
V_33 = F_155 ( F_146 ( V_347 [ V_365 ] ) ) ;
else
V_33 = F_156 ( V_363 ) ;
return V_33 ;
}
static int F_157 ( struct V_34 * V_35 , struct V_47 * V_347 [] )
{
if ( V_35 ) {
if ( V_347 [ V_319 ] &&
F_158 ( V_347 [ V_319 ] ) < V_35 -> V_318 )
return - V_366 ;
if ( V_347 [ V_321 ] &&
F_158 ( V_347 [ V_321 ] ) < V_35 -> V_318 )
return - V_366 ;
}
if ( V_347 [ V_327 ] ) {
struct V_47 * V_329 ;
int V_367 , V_32 ;
F_159 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_160 ( V_329 ) ) ) )
return - V_368 ;
if ( ! V_54 -> V_369 )
return - V_196 ;
if ( V_54 -> V_370 ) {
V_32 = V_54 -> V_370 ( V_35 , V_329 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
}
return 0 ;
}
static int F_161 ( struct V_34 * V_35 , struct V_371 * V_372 ,
int V_373 )
{
const struct V_374 * V_25 = V_35 -> V_176 ;
return V_25 -> V_375 ( V_35 , V_372 -> V_187 , V_372 -> V_376 , V_373 ) ;
}
static int F_162 ( struct V_34 * V_35 , struct V_371 * V_372 , int V_373 )
{
if ( V_35 -> type != V_377 )
return - V_196 ;
return F_161 ( V_35 , V_372 , V_373 ) ;
}
static int F_163 ( struct V_34 * V_35 , struct V_47 * * V_347 )
{
const struct V_374 * V_25 = V_35 -> V_176 ;
int V_32 = - V_366 ;
if ( V_347 [ V_241 ] ) {
struct V_161 * V_378 = F_112 ( V_347 [ V_241 ] ) ;
V_32 = - V_196 ;
if ( V_25 -> V_379 )
V_32 = V_25 -> V_379 ( V_35 , V_378 -> V_187 ,
V_378 -> V_230 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_347 [ V_242 ] ) {
struct V_162 * V_380 = F_112 ( V_347 [ V_242 ] ) ;
V_32 = - V_196 ;
if ( V_25 -> V_381 )
V_32 = V_25 -> V_381 ( V_35 , V_380 -> V_187 , V_380 -> V_233 ,
V_380 -> V_234 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_347 [ V_244 ] ) {
struct V_216 * V_372 = F_112 ( V_347 [ V_244 ] ) ;
struct V_225 V_382 ;
V_32 = - V_196 ;
if ( V_25 -> V_232 )
V_32 = V_25 -> V_232 ( V_35 , V_372 -> V_187 , & V_382 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = - V_196 ;
if ( V_25 -> V_383 )
V_32 = V_25 -> V_383 ( V_35 , V_372 -> V_187 ,
V_382 . V_237 ,
V_372 -> V_235 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_347 [ V_243 ] ) {
struct V_164 * V_372 = F_112 ( V_347 [ V_243 ] ) ;
V_32 = - V_196 ;
if ( V_25 -> V_383 )
V_32 = V_25 -> V_383 ( V_35 , V_372 -> V_187 ,
V_372 -> V_237 ,
V_372 -> V_236 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_347 [ V_245 ] ) {
struct V_163 * V_384 = F_112 ( V_347 [ V_245 ] ) ;
V_32 = - V_196 ;
if ( V_25 -> V_385 )
V_32 = V_25 -> V_385 ( V_35 , V_384 -> V_187 ,
V_384 -> V_238 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_347 [ V_246 ] ) {
struct V_165 * V_386 = F_112 ( V_347 [ V_246 ] ) ;
V_32 = - V_196 ;
if ( V_25 -> V_387 )
V_32 = V_25 -> V_387 ( V_35 , V_386 -> V_187 ,
V_386 -> V_239 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_347 [ V_247 ] ) {
struct V_166 * V_388 ;
V_32 = - V_196 ;
V_388 = F_112 ( V_347 [ V_247 ] ) ;
if ( V_25 -> V_389 )
V_32 = V_25 -> V_389 ( V_35 , V_388 -> V_187 ,
V_388 -> V_238 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_347 [ V_248 ] ) {
struct V_168 * V_372 = F_112 ( V_347 [ V_248 ] ) ;
V_32 = - V_196 ;
if ( V_25 -> V_390 )
V_32 = V_25 -> V_390 ( V_35 , V_372 -> V_187 , V_372 -> V_238 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( V_347 [ V_391 ] ) {
struct V_371 * V_372 = F_112 ( V_347 [ V_391 ] ) ;
if ( ! V_25 -> V_375 )
return - V_196 ;
return F_162 ( V_35 , V_372 , V_391 ) ;
}
if ( V_347 [ V_392 ] ) {
struct V_371 * V_372 = F_112 ( V_347 [ V_392 ] ) ;
if ( ! V_25 -> V_375 )
return - V_196 ;
return F_162 ( V_35 , V_372 , V_392 ) ;
}
return V_32 ;
}
static int F_164 ( struct V_34 * V_35 , int V_286 )
{
struct V_34 * V_280 = F_47 ( V_35 ) ;
const struct V_374 * V_25 ;
int V_32 ;
if ( V_280 ) {
if ( V_280 -> V_286 == V_286 )
return 0 ;
V_25 = V_280 -> V_176 ;
if ( V_25 -> V_393 ) {
V_32 = V_25 -> V_393 ( V_280 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_196 ;
}
}
if ( V_286 ) {
V_280 = F_165 ( F_131 ( V_35 ) , V_286 ) ;
if ( ! V_280 )
return - V_366 ;
V_25 = V_280 -> V_176 ;
if ( V_25 -> V_394 ) {
V_32 = V_25 -> V_394 ( V_280 , V_35 ) ;
if ( V_32 )
return V_32 ;
} else {
return - V_196 ;
}
}
return 0 ;
}
static int F_166 ( const struct V_2 * V_56 ,
struct V_34 * V_35 , struct V_126 * V_127 ,
struct V_47 * * V_347 , char * V_395 , int V_396 )
{
const struct V_374 * V_25 = V_35 -> V_176 ;
int V_32 ;
if ( V_347 [ V_364 ] || V_347 [ V_365 ] ) {
struct V_33 * V_33 = F_153 ( F_131 ( V_35 ) , V_347 ) ;
if ( F_167 ( V_33 ) ) {
V_32 = F_168 ( V_33 ) ;
goto V_397;
}
if ( ! F_169 ( V_56 , V_33 -> V_398 , V_399 ) ) {
F_170 ( V_33 ) ;
V_32 = - V_400 ;
goto V_397;
}
V_32 = F_171 ( V_35 , V_33 , V_395 ) ;
F_170 ( V_33 ) ;
if ( V_32 )
goto V_397;
V_396 |= V_401 ;
}
if ( V_347 [ V_267 ] ) {
struct V_182 * V_402 ;
struct V_403 V_404 ;
if ( ! V_25 -> V_405 ) {
V_32 = - V_196 ;
goto V_397;
}
if ( ! F_172 ( V_35 ) ) {
V_32 = - V_406 ;
goto V_397;
}
V_402 = F_112 ( V_347 [ V_267 ] ) ;
V_404 . V_260 = ( unsigned long ) V_402 -> V_260 ;
V_404 . V_261 = ( unsigned long ) V_402 -> V_261 ;
V_404 . V_262 = ( unsigned short ) V_402 -> V_262 ;
V_404 . V_263 = ( unsigned char ) V_402 -> V_263 ;
V_404 . V_264 = ( unsigned char ) V_402 -> V_264 ;
V_404 . V_265 = ( unsigned char ) V_402 -> V_265 ;
V_32 = V_25 -> V_405 ( V_35 , & V_404 ) ;
if ( V_32 < 0 )
goto V_397;
V_396 |= V_407 ;
}
if ( V_347 [ V_319 ] ) {
struct V_408 * V_409 ;
int V_362 ;
V_362 = sizeof( V_410 ) + V_35 -> V_318 ;
V_409 = F_173 ( V_362 , V_20 ) ;
if ( ! V_409 ) {
V_32 = - V_411 ;
goto V_397;
}
V_409 -> V_412 = V_35 -> type ;
memcpy ( V_409 -> V_413 , F_112 ( V_347 [ V_319 ] ) ,
V_35 -> V_318 ) ;
V_32 = F_174 ( V_35 , V_409 ) ;
F_27 ( V_409 ) ;
if ( V_32 )
goto V_397;
V_396 |= V_401 ;
}
if ( V_347 [ V_294 ] ) {
V_32 = F_175 ( V_35 , F_146 ( V_347 [ V_294 ] ) ) ;
if ( V_32 < 0 )
goto V_397;
V_396 |= V_401 ;
}
if ( V_347 [ V_296 ] ) {
F_176 ( V_35 , F_146 ( V_347 [ V_296 ] ) ) ;
V_396 |= V_407 ;
}
if ( V_127 -> V_285 > 0 && V_395 [ 0 ] ) {
V_32 = F_177 ( V_35 , V_395 ) ;
if ( V_32 < 0 )
goto V_397;
V_396 |= V_401 ;
}
if ( V_347 [ V_313 ] ) {
V_32 = F_178 ( V_35 , F_112 ( V_347 [ V_313 ] ) ,
F_158 ( V_347 [ V_313 ] ) ) ;
if ( V_32 < 0 )
goto V_397;
V_396 |= V_407 ;
}
if ( V_347 [ V_321 ] ) {
F_179 ( V_35 -> V_257 , V_347 [ V_321 ] , V_35 -> V_318 ) ;
F_180 ( V_414 , V_35 ) ;
}
if ( V_127 -> V_128 || V_127 -> V_129 ) {
V_32 = F_181 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
goto V_397;
}
if ( V_347 [ V_308 ] ) {
V_32 = F_164 ( V_35 , F_146 ( V_347 [ V_308 ] ) ) ;
if ( V_32 )
goto V_397;
V_396 |= V_401 ;
}
if ( V_347 [ V_309 ] ) {
V_32 = F_182 ( V_35 , F_183 ( V_347 [ V_309 ] ) ) ;
if ( V_32 )
goto V_397;
V_396 |= V_401 ;
}
if ( V_347 [ V_288 ] ) {
unsigned long V_415 = F_146 ( V_347 [ V_288 ] ) ;
unsigned long V_416 = V_35 -> V_289 ;
if ( V_35 -> V_289 ^ V_415 ) {
V_35 -> V_289 = V_415 ;
V_32 = F_180 (
V_417 , V_35 ) ;
V_32 = F_184 ( V_32 ) ;
if ( V_32 ) {
V_35 -> V_289 = V_416 ;
goto V_397;
}
V_396 |= V_407 ;
}
}
if ( V_347 [ V_290 ] )
F_85 ( V_35 , F_183 ( V_347 [ V_290 ] ) ) ;
if ( V_347 [ V_292 ] ) {
unsigned char V_415 = F_183 ( V_347 [ V_292 ] ) ;
F_87 ( & V_122 ) ;
if ( V_35 -> V_293 ^ V_415 )
V_396 |= V_407 ;
V_35 -> V_293 = V_415 ;
F_88 ( & V_122 ) ;
}
if ( V_347 [ V_323 ] ) {
struct V_47 * V_212 [ V_418 + 1 ] ;
struct V_47 * V_201 ;
int V_367 ;
F_159 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_160 ( V_201 ) != V_240 ||
F_158 ( V_201 ) < V_419 ) {
V_32 = - V_366 ;
goto V_397;
}
V_32 = F_137 ( V_212 , V_418 , V_201 ,
V_420 ) ;
if ( V_32 < 0 )
goto V_397;
V_32 = F_163 ( V_35 , V_212 ) ;
if ( V_32 < 0 )
goto V_397;
V_396 |= V_407 ;
}
}
V_32 = 0 ;
if ( V_347 [ V_188 ] ) {
struct V_47 * V_265 [ V_421 + 1 ] ;
struct V_47 * V_201 ;
int V_187 ;
int V_367 ;
V_32 = - V_196 ;
if ( ! V_25 -> V_422 )
goto V_397;
F_159 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_160 ( V_201 ) != V_189 ||
F_158 ( V_201 ) < V_419 ) {
V_32 = - V_366 ;
goto V_397;
}
V_32 = F_137 ( V_265 , V_421 , V_201 ,
V_423 ) ;
if ( V_32 < 0 )
goto V_397;
if ( ! V_265 [ V_190 ] ) {
V_32 = - V_196 ;
goto V_397;
}
V_187 = F_146 ( V_265 [ V_190 ] ) ;
V_32 = V_25 -> V_422 ( V_35 , V_187 , V_265 ) ;
if ( V_32 < 0 )
goto V_397;
V_396 |= V_407 ;
}
}
V_32 = 0 ;
if ( V_347 [ V_192 ] ) {
struct V_47 * V_265 [ V_421 + 1 ] ;
V_32 = F_137 ( V_265 , V_421 ,
V_347 [ V_192 ] , V_423 ) ;
if ( V_32 < 0 )
goto V_397;
V_32 = - V_196 ;
if ( V_25 -> V_422 )
V_32 = V_25 -> V_422 ( V_35 , V_193 , V_265 ) ;
if ( V_32 < 0 )
goto V_397;
V_396 |= V_407 ;
}
if ( V_347 [ V_327 ] ) {
struct V_47 * V_329 ;
int V_367 ;
F_159 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_51 * V_54 ;
if ( ! ( V_54 = F_50 ( F_160 ( V_329 ) ) ) )
F_185 () ;
V_32 = V_54 -> V_369 ( V_35 , V_329 ) ;
if ( V_32 < 0 )
goto V_397;
V_396 |= V_407 ;
}
}
V_32 = 0 ;
if ( V_347 [ V_316 ] ) {
V_32 = F_186 ( V_35 ,
F_183 ( V_347 [ V_316 ] ) ) ;
if ( V_32 )
goto V_397;
V_396 |= V_407 ;
}
if ( V_347 [ V_271 ] ) {
struct V_47 * V_270 [ V_424 + 1 ] ;
V_32 = F_137 ( V_270 , V_424 , V_347 [ V_271 ] ,
V_425 ) ;
if ( V_32 < 0 )
goto V_397;
if ( V_270 [ V_275 ] ) {
V_32 = - V_366 ;
goto V_397;
}
if ( V_270 [ V_426 ] ) {
V_32 = F_187 ( V_35 ,
F_188 ( V_270 [ V_426 ] ) ) ;
if ( V_32 )
goto V_397;
V_396 |= V_407 ;
}
}
V_397:
if ( V_396 & V_401 ) {
if ( V_396 & V_407 )
F_89 ( V_35 ) ;
if ( V_32 < 0 )
F_189 ( L_3 ,
V_35 -> V_94 ) ;
}
return V_32 ;
}
static int F_190 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
int V_32 ;
struct V_47 * V_347 [ V_348 + 1 ] ;
char V_395 [ V_180 ] ;
V_32 = F_145 ( V_82 , sizeof( * V_127 ) , V_347 , V_348 , V_353 ) ;
if ( V_32 < 0 )
goto V_397;
if ( V_347 [ V_287 ] )
F_138 ( V_395 , V_347 [ V_287 ] , V_180 ) ;
else
V_395 [ 0 ] = '\0' ;
V_32 = - V_366 ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_285 > 0 )
V_35 = F_165 ( V_33 , V_127 -> V_285 ) ;
else if ( V_347 [ V_287 ] )
V_35 = F_191 ( V_33 , V_395 ) ;
else
goto V_397;
if ( V_35 == NULL ) {
V_32 = - V_406 ;
goto V_397;
}
V_32 = F_157 ( V_35 , V_347 ) ;
if ( V_32 < 0 )
goto V_397;
V_32 = F_166 ( V_56 , V_35 , V_127 , V_347 , V_395 , 0 ) ;
V_397:
return V_32 ;
}
static int F_192 ( const struct V_33 * V_33 , int V_74 )
{
struct V_34 * V_35 , * V_427 ;
F_34 ( V_36 ) ;
bool V_428 = false ;
if ( ! V_74 )
return - V_400 ;
F_35 (net, dev) {
if ( V_35 -> V_74 == V_74 ) {
const struct V_23 * V_25 ;
V_428 = true ;
V_25 = V_35 -> V_23 ;
if ( ! V_25 || ! V_25 -> V_28 )
return - V_196 ;
}
}
if ( ! V_428 )
return - V_406 ;
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
return - V_196 ;
V_25 -> V_28 ( V_35 , & V_36 ) ;
F_36 ( & V_36 ) ;
return 0 ;
}
static int F_195 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_34 * V_35 ;
struct V_126 * V_127 ;
char V_395 [ V_180 ] ;
struct V_47 * V_347 [ V_348 + 1 ] ;
int V_32 ;
V_32 = F_145 ( V_82 , sizeof( * V_127 ) , V_347 , V_348 , V_353 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_347 [ V_287 ] )
F_138 ( V_395 , V_347 [ V_287 ] , V_180 ) ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_285 > 0 )
V_35 = F_165 ( V_33 , V_127 -> V_285 ) ;
else if ( V_347 [ V_287 ] )
V_35 = F_191 ( V_33 , V_395 ) ;
else if ( V_347 [ V_296 ] )
return F_192 ( V_33 , F_146 ( V_347 [ V_296 ] ) ) ;
else
return - V_366 ;
if ( ! V_35 )
return - V_406 ;
return F_194 ( V_35 ) ;
}
int F_196 ( struct V_34 * V_35 , const struct V_126 * V_127 )
{
unsigned int V_429 ;
int V_32 ;
V_429 = V_35 -> V_83 ;
if ( V_127 && ( V_127 -> V_128 || V_127 -> V_129 ) ) {
V_32 = F_197 ( V_35 , F_91 ( V_35 , V_127 ) ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_35 -> V_430 = V_431 ;
F_198 ( V_35 , V_429 , ~ 0U ) ;
return 0 ;
}
struct V_34 * F_199 ( struct V_33 * V_33 ,
const char * V_395 , unsigned char V_432 ,
const struct V_23 * V_25 , struct V_47 * V_347 [] )
{
int V_32 ;
struct V_34 * V_35 ;
unsigned int V_300 = 1 ;
unsigned int V_306 = 1 ;
if ( V_347 [ V_299 ] )
V_300 = F_146 ( V_347 [ V_299 ] ) ;
else if ( V_25 -> V_433 )
V_300 = V_25 -> V_433 () ;
if ( V_347 [ V_305 ] )
V_306 = F_146 ( V_347 [ V_305 ] ) ;
else if ( V_25 -> V_434 )
V_306 = V_25 -> V_434 () ;
V_32 = - V_411 ;
V_35 = F_200 ( V_25 -> V_435 , V_395 , V_432 ,
V_25 -> V_27 , V_300 , V_306 ) ;
if ( ! V_35 )
goto V_32;
F_201 ( V_35 , V_33 ) ;
V_35 -> V_23 = V_25 ;
V_35 -> V_430 = V_436 ;
if ( V_347 [ V_294 ] )
V_35 -> V_295 = F_146 ( V_347 [ V_294 ] ) ;
if ( V_347 [ V_319 ] ) {
memcpy ( V_35 -> V_320 , F_112 ( V_347 [ V_319 ] ) ,
F_158 ( V_347 [ V_319 ] ) ) ;
V_35 -> V_437 = V_438 ;
}
if ( V_347 [ V_321 ] )
memcpy ( V_35 -> V_257 , F_112 ( V_347 [ V_321 ] ) ,
F_158 ( V_347 [ V_321 ] ) ) ;
if ( V_347 [ V_288 ] )
V_35 -> V_289 = F_146 ( V_347 [ V_288 ] ) ;
if ( V_347 [ V_290 ] )
F_85 ( V_35 , F_183 ( V_347 [ V_290 ] ) ) ;
if ( V_347 [ V_292 ] )
V_35 -> V_293 = F_183 ( V_347 [ V_292 ] ) ;
if ( V_347 [ V_296 ] )
F_176 ( V_35 , F_146 ( V_347 [ V_296 ] ) ) ;
return V_35 ;
V_32:
return F_202 ( V_32 ) ;
}
static int F_203 ( const struct V_2 * V_56 ,
struct V_33 * V_33 , int V_74 ,
struct V_126 * V_127 ,
struct V_47 * * V_347 )
{
struct V_34 * V_35 , * V_427 ;
int V_32 ;
F_193 (net, dev, aux) {
if ( V_35 -> V_74 == V_74 ) {
V_32 = F_166 ( V_56 , V_35 , V_127 , V_347 , NULL , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
return 0 ;
}
static int F_204 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
const struct V_23 * V_25 ;
const struct V_23 * V_439 = NULL ;
struct V_34 * V_35 ;
struct V_34 * V_45 = NULL ;
struct V_126 * V_127 ;
char V_24 [ V_335 ] ;
char V_395 [ V_180 ] ;
struct V_47 * V_347 [ V_348 + 1 ] ;
struct V_47 * V_69 [ V_333 + 1 ] ;
unsigned char V_432 = V_440 ;
int V_32 ;
#ifdef F_205
V_441:
#endif
V_32 = F_145 ( V_82 , sizeof( * V_127 ) , V_347 , V_348 , V_353 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_347 [ V_287 ] )
F_138 ( V_395 , V_347 [ V_287 ] , V_180 ) ;
else
V_395 [ 0 ] = '\0' ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_285 > 0 )
V_35 = F_165 ( V_33 , V_127 -> V_285 ) ;
else {
if ( V_395 [ 0 ] )
V_35 = F_191 ( V_33 , V_395 ) ;
else
V_35 = NULL ;
}
if ( V_35 ) {
V_45 = F_47 ( V_35 ) ;
if ( V_45 )
V_439 = V_45 -> V_23 ;
}
V_32 = F_157 ( V_35 , V_347 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_347 [ V_70 ] ) {
V_32 = F_137 ( V_69 , V_333 ,
V_347 [ V_70 ] , V_334 ) ;
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
struct V_47 * V_201 [ V_25 ? V_25 -> V_442 + 1 : 1 ] ;
struct V_47 * V_443 [ V_439 ? V_439 -> V_444 + 1 : 1 ] ;
struct V_47 * * V_63 = NULL ;
struct V_47 * * V_57 = NULL ;
struct V_33 * V_445 , * V_325 = NULL ;
if ( V_25 ) {
if ( V_25 -> V_442 && V_69 [ V_67 ] ) {
V_32 = F_137 ( V_201 , V_25 -> V_442 ,
V_69 [ V_67 ] ,
V_25 -> V_446 ) ;
if ( V_32 < 0 )
return V_32 ;
V_63 = V_201 ;
}
if ( V_25 -> V_447 ) {
V_32 = V_25 -> V_447 ( V_347 , V_63 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_439 ) {
if ( V_439 -> V_444 &&
V_69 [ V_61 ] ) {
V_32 = F_137 ( V_443 ,
V_439 -> V_444 ,
V_69 [ V_61 ] ,
V_439 -> V_448 ) ;
if ( V_32 < 0 )
return V_32 ;
V_57 = V_443 ;
}
if ( V_439 -> V_449 ) {
V_32 = V_439 -> V_449 ( V_347 , V_57 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
if ( V_35 ) {
int V_396 = 0 ;
if ( V_82 -> V_450 & V_451 )
return - V_26 ;
if ( V_82 -> V_450 & V_452 )
return - V_196 ;
if ( V_69 [ V_67 ] ) {
if ( ! V_25 || V_25 != V_35 -> V_23 ||
! V_25 -> V_453 )
return - V_196 ;
V_32 = V_25 -> V_453 ( V_35 , V_347 , V_63 ) ;
if ( V_32 < 0 )
return V_32 ;
V_396 |= V_407 ;
}
if ( V_69 [ V_61 ] ) {
if ( ! V_439 || ! V_439 -> V_454 )
return - V_196 ;
V_32 = V_439 -> V_454 ( V_45 , V_35 ,
V_347 , V_57 ) ;
if ( V_32 < 0 )
return V_32 ;
V_396 |= V_407 ;
}
return F_166 ( V_56 , V_35 , V_127 , V_347 , V_395 , V_396 ) ;
}
if ( ! ( V_82 -> V_450 & V_455 ) ) {
if ( V_127 -> V_285 == 0 && V_347 [ V_296 ] )
return F_203 ( V_56 , V_33 ,
F_146 ( V_347 [ V_296 ] ) ,
V_127 , V_347 ) ;
return - V_406 ;
}
if ( V_347 [ V_267 ] || V_347 [ V_308 ] || V_347 [ V_456 ] )
return - V_196 ;
if ( ! V_25 ) {
#ifdef F_205
if ( V_24 [ 0 ] ) {
F_4 () ;
F_206 ( L_4 , V_24 ) ;
F_1 () ;
V_25 = F_28 ( V_24 ) ;
if ( V_25 )
goto V_441;
}
#endif
return - V_196 ;
}
if ( ! V_25 -> V_27 )
return - V_196 ;
if ( ! V_395 [ 0 ] ) {
snprintf ( V_395 , V_180 , L_5 , V_25 -> V_24 ) ;
V_432 = V_457 ;
}
V_445 = F_153 ( V_33 , V_347 ) ;
if ( F_167 ( V_445 ) )
return F_168 ( V_445 ) ;
V_32 = - V_400 ;
if ( ! F_169 ( V_56 , V_445 -> V_398 , V_399 ) )
goto V_71;
if ( V_347 [ V_326 ] ) {
int V_102 = F_188 ( V_347 [ V_326 ] ) ;
V_325 = F_207 ( V_445 , V_102 ) ;
if ( ! V_325 ) {
V_32 = - V_366 ;
goto V_71;
}
V_32 = - V_400 ;
if ( ! F_169 ( V_56 , V_325 -> V_398 , V_399 ) )
goto V_71;
}
V_35 = F_199 ( V_325 ? : V_445 , V_395 ,
V_432 , V_25 , V_347 ) ;
if ( F_167 ( V_35 ) ) {
V_32 = F_168 ( V_35 ) ;
goto V_71;
}
V_35 -> V_286 = V_127 -> V_285 ;
if ( V_25 -> V_458 ) {
V_32 = V_25 -> V_458 ( V_325 ? : V_33 , V_35 , V_347 , V_63 ) ;
if ( V_32 < 0 ) {
if ( V_35 -> V_459 == V_460 )
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
goto V_461;
if ( V_325 ) {
V_32 = F_171 ( V_35 , V_445 , V_395 ) ;
if ( V_32 < 0 )
goto V_461;
}
V_71:
if ( V_325 )
F_170 ( V_325 ) ;
F_170 ( V_445 ) ;
return V_32 ;
V_461:
if ( V_25 -> V_458 ) {
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
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_126 * V_127 ;
char V_395 [ V_180 ] ;
struct V_47 * V_347 [ V_348 + 1 ] ;
struct V_34 * V_35 = NULL ;
struct V_2 * V_462 ;
int V_32 ;
T_5 V_53 = 0 ;
V_32 = F_145 ( V_82 , sizeof( * V_127 ) , V_347 , V_348 , V_353 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_347 [ V_287 ] )
F_138 ( V_395 , V_347 [ V_287 ] , V_180 ) ;
if ( V_347 [ V_354 ] )
V_53 = F_146 ( V_347 [ V_354 ] ) ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_285 > 0 )
V_35 = F_165 ( V_33 , V_127 -> V_285 ) ;
else if ( V_347 [ V_287 ] )
V_35 = F_191 ( V_33 , V_395 ) ;
else
return - V_366 ;
if ( V_35 == NULL )
return - V_406 ;
V_462 = F_212 ( F_99 ( V_35 , V_53 ) , V_20 ) ;
if ( V_462 == NULL )
return - V_21 ;
V_32 = F_121 ( V_462 , V_35 , V_359 , F_64 ( V_56 ) . V_360 ,
V_82 -> V_361 , 0 , 0 , V_53 ) ;
if ( V_32 < 0 ) {
F_148 ( V_32 == - V_59 ) ;
F_6 ( V_462 ) ;
} else
V_32 = F_68 ( V_462 , V_33 , F_64 ( V_56 ) . V_360 ) ;
return V_32 ;
}
static T_9 F_213 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_34 * V_35 ;
struct V_47 * V_347 [ V_348 + 1 ] ;
T_5 V_53 = 0 ;
T_9 V_463 = 0 ;
int V_350 ;
V_350 = F_144 ( V_82 ) < sizeof( struct V_126 ) ?
sizeof( struct V_352 ) : sizeof( struct V_126 ) ;
if ( F_145 ( V_82 , V_350 , V_347 , V_348 , V_353 ) >= 0 ) {
if ( V_347 [ V_354 ] )
V_53 = F_146 ( V_347 [ V_354 ] ) ;
}
if ( ! V_53 )
return V_464 ;
F_29 (dev, &net->dev_base_head, dev_list) {
V_463 = F_214 ( T_9 , V_463 ,
F_99 ( V_35 ,
V_53 ) ) ;
}
return V_463 ;
}
static int F_215 ( struct V_2 * V_56 , struct V_339 * V_340 )
{
int V_344 ;
int V_345 = V_340 -> V_52 ;
if ( V_345 == 0 )
V_345 = 1 ;
for ( V_344 = 1 ; V_344 <= V_14 ; V_344 ++ ) {
int type = V_340 -> V_82 -> V_465 - V_9 ;
if ( V_344 < V_345 || V_344 == V_466 )
continue;
if ( V_15 [ V_344 ] == NULL ||
V_15 [ V_344 ] [ type ] . V_18 == NULL )
continue;
if ( V_344 > V_345 ) {
memset ( & V_340 -> args [ 0 ] , 0 , sizeof( V_340 -> args ) ) ;
V_340 -> V_467 = 0 ;
V_340 -> V_277 = 0 ;
}
if ( V_15 [ V_344 ] [ type ] . V_18 ( V_56 , V_340 ) )
break;
}
V_340 -> V_52 = V_344 ;
return V_56 -> V_362 ;
}
struct V_2 * F_216 ( int type , struct V_34 * V_35 ,
unsigned int V_278 , T_6 V_83 )
{
struct V_33 * V_33 = F_131 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
T_4 V_468 ;
V_56 = F_212 ( ( V_468 = F_99 ( V_35 , 0 ) ) , V_83 ) ;
if ( V_56 == NULL )
goto V_397;
V_32 = F_121 ( V_56 , V_35 , type , 0 , 0 , V_278 , 0 , 0 ) ;
if ( V_32 < 0 ) {
F_148 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
goto V_397;
}
return V_56 ;
V_397:
if ( V_32 < 0 )
F_73 ( V_33 , V_469 , V_32 ) ;
return NULL ;
}
void F_217 ( struct V_2 * V_56 , struct V_34 * V_35 , T_6 V_83 )
{
struct V_33 * V_33 = F_131 ( V_35 ) ;
F_70 ( V_56 , V_33 , 0 , V_469 , NULL , V_83 ) ;
}
void F_218 ( int type , struct V_34 * V_35 , unsigned int V_278 ,
T_6 V_83 )
{
struct V_2 * V_56 ;
if ( V_35 -> V_459 != V_470 )
return;
V_56 = F_216 ( type , V_35 , V_278 , V_83 ) ;
if ( V_56 )
F_217 ( V_56 , V_35 , V_83 ) ;
}
static int F_219 ( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_10 * V_471 , T_9 V_472 , T_5 V_73 , T_5 V_277 ,
int type , unsigned int V_83 ,
int V_473 , T_9 V_474 )
{
struct V_81 * V_82 ;
struct V_475 * V_476 ;
V_82 = F_123 ( V_56 , V_73 , V_277 , type , sizeof( * V_476 ) , V_473 ) ;
if ( ! V_82 )
return - V_59 ;
V_476 = F_124 ( V_82 ) ;
V_476 -> V_477 = V_478 ;
V_476 -> V_479 = 0 ;
V_476 -> V_480 = 0 ;
V_476 -> V_481 = V_83 ;
V_476 -> V_482 = 0 ;
V_476 -> V_483 = V_35 -> V_286 ;
V_476 -> V_474 = V_474 ;
if ( F_84 ( V_56 , V_484 , V_485 , V_471 ) )
goto V_95;
if ( V_472 )
if ( F_84 ( V_56 , V_486 , sizeof( T_9 ) , & V_472 ) )
goto V_95;
F_134 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_135 ( V_56 , V_82 ) ;
return - V_59 ;
}
static inline T_4 F_220 ( void )
{
return F_100 ( sizeof( struct V_475 ) ) + F_48 ( V_485 ) ;
}
static void F_221 ( struct V_34 * V_35 , T_10 * V_471 , T_9 V_472 , int type ,
T_9 V_474 )
{
struct V_33 * V_33 = F_131 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_21 ;
V_56 = F_212 ( F_220 () , V_487 ) ;
if ( ! V_56 )
goto V_397;
V_32 = F_219 ( V_56 , V_35 , V_471 , V_472 ,
0 , 0 , type , V_488 , 0 , V_474 ) ;
if ( V_32 < 0 ) {
F_6 ( V_56 ) ;
goto V_397;
}
F_70 ( V_56 , V_33 , 0 , V_489 , NULL , V_487 ) ;
return;
V_397:
F_73 ( V_33 , V_489 , V_32 ) ;
}
int F_222 ( struct V_475 * V_476 ,
struct V_47 * V_347 [] ,
struct V_34 * V_35 ,
const unsigned char * V_471 , T_9 V_472 ,
T_9 V_83 )
{
int V_32 = - V_366 ;
if ( V_476 -> V_474 && ! ( V_476 -> V_474 & V_490 ) ) {
F_223 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( V_472 ) {
F_223 ( L_7 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_224 ( V_471 ) || F_225 ( V_471 ) )
V_32 = F_226 ( V_35 , V_471 ) ;
else if ( F_227 ( V_471 ) )
V_32 = F_228 ( V_35 , V_471 ) ;
if ( V_32 == - V_26 && ! ( V_83 & V_451 ) )
V_32 = 0 ;
return V_32 ;
}
static int F_229 ( struct V_47 * V_491 , T_9 * V_492 )
{
T_9 V_472 = 0 ;
if ( V_491 ) {
if ( F_158 ( V_491 ) != sizeof( T_9 ) ) {
F_223 ( L_8 ) ;
return - V_366 ;
}
V_472 = F_230 ( V_491 ) ;
if ( ! V_472 || V_472 >= V_493 ) {
F_223 ( L_9 ,
V_472 ) ;
return - V_366 ;
}
}
* V_492 = V_472 ;
return 0 ;
}
static int F_231 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_475 * V_476 ;
struct V_47 * V_347 [ V_494 + 1 ] ;
struct V_34 * V_35 ;
T_10 * V_471 ;
T_9 V_472 ;
int V_32 ;
V_32 = F_145 ( V_82 , sizeof( * V_476 ) , V_347 , V_494 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_476 = F_124 ( V_82 ) ;
if ( V_476 -> V_483 == 0 ) {
F_223 ( L_10 ) ;
return - V_366 ;
}
V_35 = F_165 ( V_33 , V_476 -> V_483 ) ;
if ( V_35 == NULL ) {
F_223 ( L_11 ) ;
return - V_406 ;
}
if ( ! V_347 [ V_484 ] || F_158 ( V_347 [ V_484 ] ) != V_485 ) {
F_223 ( L_12 ) ;
return - V_366 ;
}
V_471 = F_112 ( V_347 [ V_484 ] ) ;
V_32 = F_229 ( V_347 [ V_486 ] , & V_472 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_196 ;
if ( ( ! V_476 -> V_481 || V_476 -> V_481 & V_495 ) &&
( V_35 -> V_496 & V_497 ) ) {
struct V_34 * V_498 = F_47 ( V_35 ) ;
const struct V_374 * V_25 = V_498 -> V_176 ;
V_32 = V_25 -> V_499 ( V_476 , V_347 , V_35 , V_471 , V_472 ,
V_82 -> V_450 ) ;
if ( V_32 )
goto V_71;
else
V_476 -> V_481 &= ~ V_495 ;
}
if ( ( V_476 -> V_481 & V_488 ) ) {
if ( V_35 -> V_176 -> V_499 )
V_32 = V_35 -> V_176 -> V_499 ( V_476 , V_347 , V_35 , V_471 ,
V_472 ,
V_82 -> V_450 ) ;
else
V_32 = F_222 ( V_476 , V_347 , V_35 , V_471 , V_472 ,
V_82 -> V_450 ) ;
if ( ! V_32 ) {
F_221 ( V_35 , V_471 , V_472 , V_500 ,
V_476 -> V_474 ) ;
V_476 -> V_481 &= ~ V_488 ;
}
}
V_71:
return V_32 ;
}
int F_232 ( struct V_475 * V_476 ,
struct V_47 * V_347 [] ,
struct V_34 * V_35 ,
const unsigned char * V_471 , T_9 V_472 )
{
int V_32 = - V_366 ;
if ( ! ( V_476 -> V_474 & V_490 ) ) {
F_223 ( L_6 , V_35 -> V_94 ) ;
return V_32 ;
}
if ( F_224 ( V_471 ) || F_225 ( V_471 ) )
V_32 = F_233 ( V_35 , V_471 ) ;
else if ( F_227 ( V_471 ) )
V_32 = F_234 ( V_35 , V_471 ) ;
return V_32 ;
}
static int F_235 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_475 * V_476 ;
struct V_47 * V_347 [ V_494 + 1 ] ;
struct V_34 * V_35 ;
int V_32 = - V_366 ;
T_11 * V_471 ;
T_9 V_472 ;
if ( ! F_236 ( V_56 , V_399 ) )
return - V_400 ;
V_32 = F_145 ( V_82 , sizeof( * V_476 ) , V_347 , V_494 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
V_476 = F_124 ( V_82 ) ;
if ( V_476 -> V_483 == 0 ) {
F_223 ( L_13 ) ;
return - V_366 ;
}
V_35 = F_165 ( V_33 , V_476 -> V_483 ) ;
if ( V_35 == NULL ) {
F_223 ( L_14 ) ;
return - V_406 ;
}
if ( ! V_347 [ V_484 ] || F_158 ( V_347 [ V_484 ] ) != V_485 ) {
F_223 ( L_15 ) ;
return - V_366 ;
}
V_471 = F_112 ( V_347 [ V_484 ] ) ;
V_32 = F_229 ( V_347 [ V_486 ] , & V_472 ) ;
if ( V_32 )
return V_32 ;
V_32 = - V_196 ;
if ( ( ! V_476 -> V_481 || V_476 -> V_481 & V_495 ) &&
( V_35 -> V_496 & V_497 ) ) {
struct V_34 * V_498 = F_47 ( V_35 ) ;
const struct V_374 * V_25 = V_498 -> V_176 ;
if ( V_25 -> V_501 )
V_32 = V_25 -> V_501 ( V_476 , V_347 , V_35 , V_471 , V_472 ) ;
if ( V_32 )
goto V_71;
else
V_476 -> V_481 &= ~ V_495 ;
}
if ( V_476 -> V_481 & V_488 ) {
if ( V_35 -> V_176 -> V_501 )
V_32 = V_35 -> V_176 -> V_501 ( V_476 , V_347 , V_35 , V_471 ,
V_472 ) ;
else
V_32 = F_232 ( V_476 , V_347 , V_35 , V_471 , V_472 ) ;
if ( ! V_32 ) {
F_221 ( V_35 , V_471 , V_472 , V_502 ,
V_476 -> V_474 ) ;
V_476 -> V_481 &= ~ V_488 ;
}
}
V_71:
return V_32 ;
}
static int F_237 ( struct V_2 * V_56 ,
struct V_339 * V_340 ,
struct V_34 * V_35 ,
int * V_344 ,
struct V_503 * V_30 )
{
struct V_504 * V_505 ;
int V_32 ;
T_5 V_360 , V_277 ;
V_360 = F_64 ( V_340 -> V_56 ) . V_360 ;
V_277 = V_340 -> V_82 -> V_361 ;
F_29 (ha, &list->list, list) {
if ( * V_344 < V_340 -> args [ 0 ] )
goto V_506;
V_32 = F_219 ( V_56 , V_35 , V_505 -> V_471 , 0 ,
V_360 , V_277 ,
V_500 , V_488 ,
V_349 , V_490 ) ;
if ( V_32 < 0 )
return V_32 ;
V_506:
* V_344 += 1 ;
}
return 0 ;
}
int F_238 ( struct V_2 * V_56 ,
struct V_339 * V_340 ,
struct V_34 * V_35 ,
struct V_34 * V_507 ,
int V_344 )
{
int V_32 ;
F_239 ( V_35 ) ;
V_32 = F_237 ( V_56 , V_340 , V_35 , & V_344 , & V_35 -> V_508 ) ;
if ( V_32 )
goto V_71;
F_237 ( V_56 , V_340 , V_35 , & V_344 , & V_35 -> V_509 ) ;
V_71:
F_240 ( V_35 ) ;
V_340 -> args [ 1 ] = V_32 ;
return V_344 ;
}
static int F_241 ( struct V_2 * V_56 , struct V_339 * V_340 )
{
struct V_34 * V_35 ;
struct V_47 * V_347 [ V_348 + 1 ] ;
struct V_34 * V_498 = NULL ;
const struct V_374 * V_25 = NULL ;
const struct V_374 * V_510 = NULL ;
struct V_126 * V_127 = F_124 ( V_340 -> V_82 ) ;
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
int V_511 = 0 ;
int V_512 = 0 ;
int V_344 = 0 ;
if ( F_145 ( V_340 -> V_82 , sizeof( struct V_126 ) , V_347 , V_348 ,
V_353 ) == 0 ) {
if ( V_347 [ V_308 ] )
V_512 = F_146 ( V_347 [ V_308 ] ) ;
}
V_511 = V_127 -> V_285 ;
if ( V_512 ) {
V_498 = F_165 ( V_33 , V_512 ) ;
if ( ! V_498 )
return - V_406 ;
V_25 = V_498 -> V_176 ;
}
V_340 -> args [ 1 ] = 0 ;
F_35 (net, dev) {
if ( V_511 && ( V_35 -> V_286 != V_511 ) )
continue;
if ( ! V_512 ) {
if ( V_35 -> V_496 & V_497 ) {
V_498 = F_47 ( V_35 ) ;
V_510 = V_498 -> V_176 ;
}
} else {
if ( V_35 != V_498 &&
! ( V_35 -> V_496 & V_497 ) )
continue;
if ( V_498 != F_47 ( V_35 ) &&
! ( V_35 -> V_496 & V_513 ) )
continue;
V_510 = V_25 ;
}
if ( V_35 -> V_496 & V_497 ) {
if ( V_510 && V_510 -> V_514 )
V_344 = V_510 -> V_514 ( V_56 , V_340 , V_498 , V_35 ,
V_344 ) ;
}
if ( V_340 -> args [ 1 ] == - V_59 )
break;
if ( V_35 -> V_176 -> V_514 )
V_344 = V_35 -> V_176 -> V_514 ( V_56 , V_340 , V_35 , NULL ,
V_344 ) ;
else
V_344 = F_238 ( V_56 , V_340 , V_35 , NULL , V_344 ) ;
if ( V_340 -> args [ 1 ] == - V_59 )
break;
V_510 = NULL ;
}
V_340 -> args [ 0 ] = V_344 ;
return V_56 -> V_362 ;
}
static int F_242 ( struct V_2 * V_56 , T_5 V_83 , T_5 V_515 ,
unsigned int V_516 , unsigned int V_517 )
{
if ( V_515 & V_517 )
return F_120 ( V_56 , V_516 , ! ! ( V_83 & V_517 ) ) ;
return 0 ;
}
int F_243 ( struct V_2 * V_56 , T_5 V_73 , T_5 V_277 ,
struct V_34 * V_35 , T_9 V_518 ,
T_5 V_83 , T_5 V_515 , int V_473 ,
T_5 V_519 ,
int (* F_244)( struct V_2 * V_56 ,
struct V_34 * V_35 ,
T_5 V_519 ) )
{
struct V_81 * V_82 ;
struct V_126 * V_127 ;
struct V_47 * V_520 ;
struct V_47 * V_521 ;
T_10 V_118 = F_126 ( V_35 ) ? V_35 -> V_118 : V_291 ;
struct V_34 * V_498 = F_47 ( V_35 ) ;
int V_32 = 0 ;
V_82 = F_123 ( V_56 , V_73 , V_277 , V_359 , sizeof( * V_127 ) , V_473 ) ;
if ( V_82 == NULL )
return - V_59 ;
V_127 = F_124 ( V_82 ) ;
V_127 -> V_281 = V_478 ;
V_127 -> V_283 = 0 ;
V_127 -> V_284 = V_35 -> type ;
V_127 -> V_285 = V_35 -> V_286 ;
V_127 -> V_128 = F_125 ( V_35 ) ;
V_127 -> V_129 = 0 ;
if ( F_57 ( V_56 , V_287 , V_35 -> V_94 ) ||
F_78 ( V_56 , V_294 , V_35 -> V_295 ) ||
F_120 ( V_56 , V_290 , V_118 ) ||
( V_498 &&
F_78 ( V_56 , V_308 , V_498 -> V_286 ) ) ||
( V_35 -> V_318 &&
F_84 ( V_56 , V_319 , V_35 -> V_318 , V_35 -> V_320 ) ) ||
( V_35 -> V_286 != F_128 ( V_35 ) &&
F_78 ( V_56 , V_307 , F_128 ( V_35 ) ) ) )
goto V_95;
V_520 = F_58 ( V_56 , V_327 ) ;
if ( ! V_520 )
goto V_95;
if ( F_245 ( V_56 , V_522 , V_523 ) ) {
F_60 ( V_56 , V_520 ) ;
goto V_95;
}
if ( V_518 != V_524 ) {
if ( F_245 ( V_56 , V_525 , V_518 ) ) {
F_60 ( V_56 , V_520 ) ;
goto V_95;
}
}
if ( F_244 ) {
V_32 = F_244 ( V_56 , V_35 , V_519 ) ;
if ( V_32 ) {
F_60 ( V_56 , V_520 ) ;
goto V_95;
}
}
F_59 ( V_56 , V_520 ) ;
V_521 = F_58 ( V_56 , V_456 | V_526 ) ;
if ( ! V_521 )
goto V_95;
if ( F_242 ( V_56 , V_83 , V_515 ,
V_527 , V_528 ) ||
F_242 ( V_56 , V_83 , V_515 ,
V_529 , V_530 ) ||
F_242 ( V_56 , V_83 , V_515 ,
V_531 ,
V_532 ) ||
F_242 ( V_56 , V_83 , V_515 ,
V_533 , V_534 ) ||
F_242 ( V_56 , V_83 , V_515 ,
V_535 , V_536 ) ||
F_242 ( V_56 , V_83 , V_515 ,
V_537 , V_538 ) ||
F_242 ( V_56 , V_83 , V_515 ,
V_539 , V_540 ) ||
F_242 ( V_56 , V_83 , V_515 ,
V_541 , V_542 ) ) {
F_60 ( V_56 , V_521 ) ;
goto V_95;
}
F_59 ( V_56 , V_521 ) ;
F_134 ( V_56 , V_82 ) ;
return 0 ;
V_95:
F_135 ( V_56 , V_82 ) ;
return V_32 ? V_32 : - V_59 ;
}
static int F_246 ( struct V_2 * V_56 , struct V_339 * V_340 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_34 * V_35 ;
int V_344 = 0 ;
T_5 V_360 = F_64 ( V_340 -> V_56 ) . V_360 ;
T_5 V_277 = V_340 -> V_82 -> V_361 ;
T_5 V_519 = 0 ;
int V_32 ;
if ( F_144 ( V_340 -> V_82 ) > sizeof( struct V_126 ) ) {
struct V_47 * V_543 ;
V_543 = F_247 ( V_340 -> V_82 , sizeof( struct V_126 ) ,
V_354 ) ;
if ( V_543 ) {
if ( F_158 ( V_543 ) < sizeof( V_519 ) )
return - V_366 ;
V_519 = F_146 ( V_543 ) ;
}
}
F_248 () ;
F_249 (net, dev) {
const struct V_374 * V_25 = V_35 -> V_176 ;
struct V_34 * V_498 = F_47 ( V_35 ) ;
if ( V_498 && V_498 -> V_176 -> V_544 ) {
if ( V_344 >= V_340 -> args [ 0 ] ) {
V_32 = V_498 -> V_176 -> V_544 (
V_56 , V_360 , V_277 , V_35 ,
V_519 , V_349 ) ;
if ( V_32 < 0 && V_32 != - V_196 )
break;
}
V_344 ++ ;
}
if ( V_25 -> V_544 ) {
if ( V_344 >= V_340 -> args [ 0 ] ) {
V_32 = V_25 -> V_544 ( V_56 , V_360 ,
V_277 , V_35 ,
V_519 ,
V_349 ) ;
if ( V_32 < 0 && V_32 != - V_196 )
break;
}
V_344 ++ ;
}
}
F_250 () ;
V_340 -> args [ 0 ] = V_344 ;
return V_56 -> V_362 ;
}
static inline T_4 F_251 ( void )
{
return F_100 ( sizeof( struct V_126 ) )
+ F_48 ( V_180 )
+ F_48 ( V_183 )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_5 ) )
+ F_48 ( sizeof( T_10 ) )
+ F_48 ( sizeof( struct V_47 ) )
+ F_48 ( sizeof( T_9 ) )
+ F_48 ( sizeof( T_9 ) ) ;
}
static int F_252 ( struct V_34 * V_35 )
{
struct V_33 * V_33 = F_131 ( V_35 ) ;
struct V_2 * V_56 ;
int V_32 = - V_196 ;
if ( ! V_35 -> V_176 -> V_544 )
return 0 ;
V_56 = F_212 ( F_251 () , V_487 ) ;
if ( ! V_56 ) {
V_32 = - V_411 ;
goto V_397;
}
V_32 = V_35 -> V_176 -> V_544 ( V_56 , 0 , 0 , V_35 , 0 , 0 ) ;
if ( V_32 < 0 )
goto V_397;
if ( ! V_56 -> V_362 )
goto V_397;
F_70 ( V_56 , V_33 , 0 , V_469 , NULL , V_487 ) ;
return 0 ;
V_397:
F_148 ( V_32 == - V_59 ) ;
F_6 ( V_56 ) ;
if ( V_32 )
F_73 ( V_33 , V_469 , V_32 ) ;
return V_32 ;
}
static int F_253 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_545 , * V_201 = NULL ;
int V_367 , V_32 = - V_196 ;
T_9 V_83 = 0 ;
bool V_546 = false ;
if ( F_144 ( V_82 ) < sizeof( * V_127 ) )
return - V_366 ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_281 != V_478 )
return - V_547 ;
V_35 = F_165 ( V_33 , V_127 -> V_285 ) ;
if ( ! V_35 ) {
F_223 ( L_16 ) ;
return - V_406 ;
}
V_545 = F_247 ( V_82 , sizeof( struct V_126 ) , V_327 ) ;
if ( V_545 ) {
F_159 (attr, br_spec, rem) {
if ( F_160 ( V_201 ) == V_522 ) {
if ( F_158 ( V_201 ) < sizeof( V_83 ) )
return - V_366 ;
V_546 = true ;
V_83 = F_230 ( V_201 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_548 ) ) {
struct V_34 * V_498 = F_47 ( V_35 ) ;
if ( ! V_498 || ! V_498 -> V_176 -> V_549 ) {
V_32 = - V_196 ;
goto V_71;
}
V_32 = V_498 -> V_176 -> V_549 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_548 ;
}
if ( ( V_83 & V_523 ) ) {
if ( ! V_35 -> V_176 -> V_549 )
V_32 = - V_196 ;
else
V_32 = V_35 -> V_176 -> V_549 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_523 ;
V_32 = F_252 ( V_35 ) ;
}
}
if ( V_546 )
memcpy ( F_112 ( V_201 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static int F_254 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_126 * V_127 ;
struct V_34 * V_35 ;
struct V_47 * V_545 , * V_201 = NULL ;
int V_367 , V_32 = - V_196 ;
T_9 V_83 = 0 ;
bool V_546 = false ;
if ( F_144 ( V_82 ) < sizeof( * V_127 ) )
return - V_366 ;
V_127 = F_124 ( V_82 ) ;
if ( V_127 -> V_281 != V_478 )
return - V_547 ;
V_35 = F_165 ( V_33 , V_127 -> V_285 ) ;
if ( ! V_35 ) {
F_223 ( L_16 ) ;
return - V_406 ;
}
V_545 = F_247 ( V_82 , sizeof( struct V_126 ) , V_327 ) ;
if ( V_545 ) {
F_159 (attr, br_spec, rem) {
if ( F_160 ( V_201 ) == V_522 ) {
if ( F_158 ( V_201 ) < sizeof( V_83 ) )
return - V_366 ;
V_546 = true ;
V_83 = F_230 ( V_201 ) ;
break;
}
}
}
if ( ! V_83 || ( V_83 & V_548 ) ) {
struct V_34 * V_498 = F_47 ( V_35 ) ;
if ( ! V_498 || ! V_498 -> V_176 -> V_550 ) {
V_32 = - V_196 ;
goto V_71;
}
V_32 = V_498 -> V_176 -> V_550 ( V_35 , V_82 , V_83 ) ;
if ( V_32 )
goto V_71;
V_83 &= ~ V_548 ;
}
if ( ( V_83 & V_523 ) ) {
if ( ! V_35 -> V_176 -> V_550 )
V_32 = - V_196 ;
else
V_32 = V_35 -> V_176 -> V_550 ( V_35 , V_82 ,
V_83 ) ;
if ( ! V_32 ) {
V_83 &= ~ V_523 ;
V_32 = F_252 ( V_35 ) ;
}
}
if ( V_546 )
memcpy ( F_112 ( V_201 ) , & V_83 , sizeof( V_83 ) ) ;
V_71:
return V_32 ;
}
static bool F_255 ( unsigned int V_515 , int V_551 , int V_552 )
{
return ( V_515 & F_256 ( V_551 ) ) &&
( ! V_552 || V_552 == V_551 ) ;
}
static int F_257 ( struct V_2 * V_56 , struct V_34 * V_35 ,
int type , T_5 V_73 , T_5 V_277 , T_5 V_278 ,
unsigned int V_83 , unsigned int V_519 ,
int * V_552 , int * V_553 )
{
struct V_554 * V_555 ;
struct V_81 * V_82 ;
struct V_47 * V_201 ;
int V_556 = * V_553 ;
F_122 () ;
V_82 = F_123 ( V_56 , V_73 , V_277 , type , sizeof( * V_555 ) , V_83 ) ;
if ( ! V_82 )
return - V_59 ;
V_555 = F_124 ( V_82 ) ;
V_555 -> V_286 = V_35 -> V_286 ;
V_555 -> V_519 = V_519 ;
if ( F_255 ( V_519 , V_557 , * V_552 ) ) {
struct V_132 * V_207 ;
V_201 = F_111 ( V_56 , V_557 ,
sizeof( struct V_132 ) ,
V_558 ) ;
if ( ! V_201 )
goto V_95;
V_207 = F_112 ( V_201 ) ;
F_113 ( V_35 , V_207 ) ;
}
if ( F_255 ( V_519 , V_559 , * V_552 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
if ( V_25 && V_25 -> V_560 ) {
int V_32 ;
* V_552 = V_559 ;
V_201 = F_58 ( V_56 ,
V_559 ) ;
if ( ! V_201 )
goto V_95;
V_32 = V_25 -> V_560 ( V_56 , V_35 , V_553 , * V_552 ) ;
F_59 ( V_56 , V_201 ) ;
if ( V_32 )
goto V_95;
* V_552 = 0 ;
}
}
if ( F_255 ( V_519 , V_561 ,
* V_552 ) ) {
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_337 ;
V_337 = F_47 ( V_35 ) ;
if ( V_337 )
V_25 = V_337 -> V_23 ;
if ( V_25 && V_25 -> V_560 ) {
int V_32 ;
* V_552 = V_561 ;
V_201 = F_58 ( V_56 ,
V_561 ) ;
if ( ! V_201 )
goto V_95;
V_32 = V_25 -> V_560 ( V_56 , V_35 , V_553 , * V_552 ) ;
F_59 ( V_56 , V_201 ) ;
if ( V_32 )
goto V_95;
* V_552 = 0 ;
}
}
F_134 ( V_56 , V_82 ) ;
return 0 ;
V_95:
if ( ! ( V_83 & V_349 ) || V_556 == * V_553 )
F_135 ( V_56 , V_82 ) ;
else
F_134 ( V_56 , V_82 ) ;
return - V_59 ;
}
static T_4 F_258 ( const struct V_34 * V_35 ,
T_5 V_519 )
{
T_4 V_48 = 0 ;
if ( F_255 ( V_519 , V_557 , 0 ) )
V_48 += F_96 ( sizeof( struct V_132 ) ) ;
if ( F_255 ( V_519 , V_559 , 0 ) ) {
const struct V_23 * V_25 = V_35 -> V_23 ;
int V_201 = V_559 ;
if ( V_25 && V_25 -> V_562 ) {
V_48 += F_48 ( V_25 -> V_562 ( V_35 ,
V_201 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
if ( F_255 ( V_519 , V_561 , 0 ) ) {
struct V_34 * V_563 = (struct V_34 * ) V_35 ;
const struct V_23 * V_25 = NULL ;
const struct V_34 * V_337 ;
V_337 = F_47 ( V_563 ) ;
if ( V_337 )
V_25 = V_337 -> V_23 ;
if ( V_25 && V_25 -> V_562 ) {
int V_201 = V_561 ;
V_48 += F_48 ( V_25 -> V_562 ( V_35 ,
V_201 ) ) ;
V_48 += F_48 ( 0 ) ;
}
}
return V_48 ;
}
static int F_259 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
struct V_34 * V_35 = NULL ;
int V_552 = 0 , V_553 = 0 ;
struct V_554 * V_555 ;
struct V_2 * V_462 ;
T_5 V_519 ;
int V_32 ;
V_555 = F_124 ( V_82 ) ;
if ( V_555 -> V_286 > 0 )
V_35 = F_165 ( V_33 , V_555 -> V_286 ) ;
else
return - V_366 ;
if ( ! V_35 )
return - V_406 ;
V_519 = V_555 -> V_519 ;
if ( ! V_519 )
return - V_366 ;
V_462 = F_212 ( F_258 ( V_35 , V_519 ) , V_20 ) ;
if ( ! V_462 )
return - V_21 ;
V_32 = F_257 ( V_462 , V_35 , V_564 ,
F_64 ( V_56 ) . V_360 , V_82 -> V_361 , 0 ,
0 , V_519 , & V_552 , & V_553 ) ;
if ( V_32 < 0 ) {
F_148 ( V_32 == - V_59 ) ;
F_6 ( V_462 ) ;
} else {
V_32 = F_68 ( V_462 , V_33 , F_64 ( V_56 ) . V_360 ) ;
}
return V_32 ;
}
static int F_260 ( struct V_2 * V_56 , struct V_339 * V_340 )
{
int V_342 , V_343 , V_32 , V_345 , V_565 , V_556 ;
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
unsigned int V_83 = V_349 ;
struct V_554 * V_555 ;
struct V_346 * V_3 ;
struct V_34 * V_35 ;
T_5 V_519 = 0 ;
int V_344 = 0 ;
V_343 = V_340 -> args [ 0 ] ;
V_345 = V_340 -> args [ 1 ] ;
V_565 = V_340 -> args [ 2 ] ;
V_556 = V_340 -> args [ 3 ] ;
V_340 -> V_277 = V_33 -> V_351 ;
V_555 = F_124 ( V_340 -> V_82 ) ;
V_519 = V_555 -> V_519 ;
if ( ! V_519 )
return - V_366 ;
for ( V_342 = V_343 ; V_342 < V_356 ; V_342 ++ , V_345 = 0 ) {
V_344 = 0 ;
V_3 = & V_33 -> V_357 [ V_342 ] ;
F_147 (dev, head, index_hlist) {
if ( V_344 < V_345 )
goto V_358;
V_32 = F_257 ( V_56 , V_35 , V_564 ,
F_64 ( V_340 -> V_56 ) . V_360 ,
V_340 -> V_82 -> V_361 , 0 ,
V_83 , V_519 ,
& V_565 , & V_556 ) ;
F_148 ( ( V_32 == - V_59 ) && ( V_56 -> V_362 == 0 ) ) ;
if ( V_32 < 0 )
goto V_71;
V_556 = 0 ;
V_565 = 0 ;
F_149 ( V_340 , F_150 ( V_56 ) ) ;
V_358:
V_344 ++ ;
}
}
V_71:
V_340 -> args [ 3 ] = V_556 ;
V_340 -> args [ 2 ] = V_565 ;
V_340 -> args [ 1 ] = V_344 ;
V_340 -> args [ 0 ] = V_342 ;
return V_56 -> V_362 ;
}
static int F_261 ( struct V_2 * V_56 , struct V_81 * V_82 )
{
struct V_33 * V_33 = F_143 ( V_56 -> V_341 ) ;
T_1 V_16 ;
int V_24 ;
int V_52 ;
int type ;
int V_32 ;
type = V_82 -> V_465 ;
if ( type > V_566 )
return - V_196 ;
type -= V_9 ;
if ( F_144 ( V_82 ) < sizeof( struct V_352 ) )
return 0 ;
V_52 = ( (struct V_352 * ) F_124 ( V_82 ) ) -> V_567 ;
V_24 = type & 3 ;
if ( V_24 != 2 && ! F_262 ( V_56 , V_399 ) )
return - V_400 ;
if ( V_24 == 2 && V_82 -> V_450 & V_568 ) {
struct V_76 * V_77 ;
T_2 V_18 ;
T_3 V_19 ;
T_9 V_569 = 0 ;
V_18 = F_19 ( V_52 , type ) ;
if ( V_18 == NULL )
return - V_196 ;
V_19 = F_20 ( V_52 , type ) ;
if ( V_19 )
V_569 = V_19 ( V_56 , V_82 ) ;
F_4 () ;
V_77 = V_33 -> V_77 ;
{
struct V_570 V_571 = {
. V_572 = V_18 ,
. V_569 = V_569 ,
} ;
V_32 = F_263 ( V_77 , V_56 , V_82 , & V_571 ) ;
}
F_1 () ;
return V_32 ;
}
V_16 = F_18 ( V_52 , type ) ;
if ( V_16 == NULL )
return - V_196 ;
return V_16 ( V_56 , V_82 ) ;
}
static void F_264 ( struct V_2 * V_56 )
{
F_1 () ;
F_265 ( V_56 , & F_261 ) ;
F_8 () ;
}
static int F_266 ( struct V_573 * V_574 , unsigned long V_575 , void * V_576 )
{
struct V_34 * V_35 = F_267 ( V_576 ) ;
switch ( V_575 ) {
case V_577 :
case V_578 :
case V_579 :
case V_580 :
case V_581 :
case V_582 :
case V_583 :
case V_584 :
case V_585 :
case V_586 :
case V_587 :
case V_588 :
case V_589 :
break;
default:
F_218 ( V_359 , V_35 , 0 , V_20 ) ;
break;
}
return V_590 ;
}
static int T_12 F_268 ( struct V_33 * V_33 )
{
struct V_76 * V_341 ;
struct V_591 V_592 = {
. V_593 = V_594 ,
. V_595 = F_264 ,
. V_596 = & V_1 ,
. V_83 = V_597 ,
} ;
V_341 = F_269 ( V_33 , V_598 , & V_592 ) ;
if ( ! V_341 )
return - V_411 ;
V_33 -> V_77 = V_341 ;
return 0 ;
}
static void T_13 F_270 ( struct V_33 * V_33 )
{
F_271 ( V_33 -> V_77 ) ;
V_33 -> V_77 = NULL ;
}
void T_14 F_272 ( void )
{
if ( F_273 ( & V_599 ) )
F_24 ( L_17 ) ;
F_274 ( & V_600 ) ;
F_23 ( V_17 , V_601 , F_211 ,
F_142 , F_213 ) ;
F_23 ( V_17 , V_602 , F_190 , NULL , NULL ) ;
F_23 ( V_17 , V_359 , F_204 , NULL , NULL ) ;
F_23 ( V_17 , V_603 , F_195 , NULL , NULL ) ;
F_23 ( V_17 , V_604 , NULL , F_215 , NULL ) ;
F_23 ( V_17 , V_605 , NULL , F_215 , NULL ) ;
F_23 ( V_606 , V_500 , F_231 , NULL , NULL ) ;
F_23 ( V_606 , V_502 , F_235 , NULL , NULL ) ;
F_23 ( V_606 , V_607 , NULL , F_241 , NULL ) ;
F_23 ( V_606 , V_601 , NULL , F_246 , NULL ) ;
F_23 ( V_606 , V_603 , F_254 , NULL , NULL ) ;
F_23 ( V_606 , V_602 , F_253 , NULL , NULL ) ;
F_23 ( V_17 , V_608 , F_259 , F_260 ,
NULL ) ;
}
