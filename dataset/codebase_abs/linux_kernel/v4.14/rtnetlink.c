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
int F_18 ( int V_11 , int V_7 ,
T_1 V_12 , T_2 V_13 ,
unsigned int V_14 )
{
struct V_15 * V_16 ;
int V_8 ;
F_17 ( V_11 < 0 || V_11 > V_17 ) ;
V_8 = F_16 ( V_7 ) ;
V_16 = F_19 ( V_18 [ V_11 ] ) ;
if ( V_16 == NULL ) {
V_16 = F_20 ( V_10 , sizeof( * V_16 ) , V_19 ) ;
if ( V_16 == NULL )
return - V_20 ;
F_21 ( V_18 [ V_11 ] , V_16 ) ;
}
if ( V_12 )
V_16 [ V_8 ] . V_12 = V_12 ;
if ( V_13 )
V_16 [ V_8 ] . V_13 = V_13 ;
V_16 [ V_8 ] . V_14 |= V_14 ;
return 0 ;
}
void F_22 ( int V_11 , int V_7 ,
T_1 V_12 , T_2 V_13 ,
unsigned int V_14 )
{
if ( F_18 ( V_11 , V_7 , V_12 , V_13 , V_14 ) < 0 )
F_23 ( L_1
L_2 ,
V_11 , V_7 ) ;
}
int F_24 ( int V_11 , int V_7 )
{
struct V_15 * V_21 ;
int V_8 ;
F_17 ( V_11 < 0 || V_11 > V_17 ) ;
V_8 = F_16 ( V_7 ) ;
F_1 () ;
V_21 = F_25 ( V_18 [ V_11 ] ) ;
if ( ! V_21 ) {
F_8 () ;
return - V_22 ;
}
V_21 [ V_8 ] . V_12 = NULL ;
V_21 [ V_8 ] . V_13 = NULL ;
V_21 [ V_8 ] . V_14 = 0 ;
F_8 () ;
return 0 ;
}
void F_26 ( int V_11 )
{
struct V_15 * V_21 ;
F_17 ( V_11 < 0 || V_11 > V_17 ) ;
F_1 () ;
V_21 = F_25 ( V_18 [ V_11 ] ) ;
F_27 ( V_18 [ V_11 ] , NULL ) ;
F_8 () ;
F_28 () ;
while ( F_29 ( & V_23 [ V_11 ] ) > 1 )
F_30 () ;
F_31 ( V_21 ) ;
}
static const struct V_24 * F_32 ( const char * V_25 )
{
const struct V_24 * V_26 ;
F_33 (ops, &link_ops, list) {
if ( ! strcmp ( V_26 -> V_25 , V_25 ) )
return V_26 ;
}
return NULL ;
}
int F_34 ( struct V_24 * V_26 )
{
if ( F_32 ( V_26 -> V_25 ) )
return - V_27 ;
if ( V_26 -> V_28 && ! V_26 -> V_29 )
V_26 -> V_29 = V_30 ;
F_35 ( & V_26 -> V_31 , & V_32 ) ;
return 0 ;
}
int F_36 ( struct V_24 * V_26 )
{
int V_33 ;
F_1 () ;
V_33 = F_34 ( V_26 ) ;
F_8 () ;
return V_33 ;
}
static void F_37 ( struct V_34 * V_34 , struct V_24 * V_26 )
{
struct V_35 * V_36 ;
F_38 ( V_37 ) ;
F_39 (net, dev) {
if ( V_36 -> V_24 == V_26 )
V_26 -> V_29 ( V_36 , & V_37 ) ;
}
F_40 ( & V_37 ) ;
}
void F_41 ( struct V_24 * V_26 )
{
struct V_34 * V_34 ;
F_42 (net) {
F_37 ( V_34 , V_26 ) ;
}
F_43 ( & V_26 -> V_31 ) ;
}
static void F_44 ( void )
{
struct V_34 * V_34 ;
bool V_38 ;
F_45 ( V_39 , V_40 ) ;
F_46 ( & V_41 , & V_39 ) ;
for (; ; ) {
V_38 = false ;
F_1 () ;
F_42 (net) {
if ( V_34 -> V_42 > 0 ) {
V_38 = true ;
break;
}
}
if ( ! V_38 )
break;
F_4 () ;
F_47 ( & V_39 , V_43 , V_44 ) ;
}
F_48 ( & V_41 , & V_39 ) ;
}
void F_49 ( struct V_24 * V_26 )
{
F_2 ( & V_45 ) ;
F_44 () ;
F_41 ( V_26 ) ;
F_8 () ;
F_5 ( & V_45 ) ;
}
static T_3 F_50 ( const struct V_35 * V_36 )
{
struct V_35 * V_46 ;
const struct V_24 * V_26 ;
T_3 V_47 = 0 ;
F_51 () ;
V_46 = F_52 ( (struct V_35 * ) V_36 ) ;
if ( ! V_46 )
goto V_48;
V_26 = V_46 -> V_24 ;
if ( ! V_26 || ! V_26 -> V_49 )
goto V_48;
V_47 = F_53 ( sizeof( struct V_50 ) ) +
V_26 -> V_49 ( V_46 , V_36 ) ;
V_48:
F_54 () ;
return V_47 ;
}
static T_3 F_55 ( const struct V_35 * V_36 )
{
const struct V_24 * V_26 = V_36 -> V_24 ;
T_3 V_47 ;
if ( ! V_26 )
return 0 ;
V_47 = F_53 ( sizeof( struct V_50 ) ) +
F_53 ( strlen ( V_26 -> V_25 ) + 1 ) ;
if ( V_26 -> V_51 )
V_47 += F_53 ( sizeof( struct V_50 ) ) +
V_26 -> V_51 ( V_36 ) ;
if ( V_26 -> V_52 )
V_47 += F_53 ( V_26 -> V_52 ( V_36 ) ) ;
V_47 += F_50 ( V_36 ) ;
return V_47 ;
}
static const struct V_53 * F_56 ( const int V_54 )
{
const struct V_53 * V_26 ;
F_33 (ops, &rtnl_af_ops, list) {
if ( V_26 -> V_54 == V_54 )
return V_26 ;
}
return NULL ;
}
void F_57 ( struct V_53 * V_26 )
{
F_1 () ;
F_35 ( & V_26 -> V_31 , & V_53 ) ;
F_8 () ;
}
void F_58 ( struct V_53 * V_26 )
{
F_43 ( & V_26 -> V_31 ) ;
}
void F_59 ( struct V_53 * V_26 )
{
F_1 () ;
F_58 ( V_26 ) ;
F_8 () ;
}
static T_3 F_60 ( const struct V_35 * V_36 ,
T_4 V_55 )
{
struct V_53 * V_56 ;
T_3 V_47 ;
V_47 = F_53 ( sizeof( struct V_50 ) ) ;
F_33 (af_ops, &rtnl_af_ops, list) {
if ( V_56 -> V_57 ) {
V_47 += F_53 ( sizeof( struct V_50 ) ) +
V_56 -> V_57 ( V_36 , V_55 ) ;
}
}
return V_47 ;
}
static bool F_61 ( const struct V_35 * V_36 )
{
struct V_35 * V_46 ;
V_46 = F_62 ( (struct V_35 * ) V_36 ) ;
if ( V_46 && V_46 -> V_24 )
return true ;
return false ;
}
static int F_63 ( struct V_2 * V_58 ,
const struct V_35 * V_36 )
{
struct V_35 * V_46 ;
const struct V_24 * V_26 ;
struct V_50 * V_59 ;
int V_33 ;
V_46 = F_62 ( (struct V_35 * ) V_36 ) ;
if ( ! V_46 )
return 0 ;
V_26 = V_46 -> V_24 ;
if ( ! V_26 )
return 0 ;
if ( F_64 ( V_58 , V_60 , V_26 -> V_25 ) < 0 )
return - V_61 ;
if ( V_26 -> V_62 ) {
V_59 = F_65 ( V_58 , V_63 ) ;
if ( ! V_59 )
return - V_61 ;
V_33 = V_26 -> V_62 ( V_58 , V_46 , V_36 ) ;
if ( V_33 < 0 )
goto V_64;
F_66 ( V_58 , V_59 ) ;
}
return 0 ;
V_64:
F_67 ( V_58 , V_59 ) ;
return V_33 ;
}
static int F_68 ( struct V_2 * V_58 ,
const struct V_35 * V_36 )
{
const struct V_24 * V_26 = V_36 -> V_24 ;
struct V_50 * V_65 ;
int V_33 ;
if ( ! V_26 )
return 0 ;
if ( F_64 ( V_58 , V_66 , V_26 -> V_25 ) < 0 )
return - V_61 ;
if ( V_26 -> V_67 ) {
V_33 = V_26 -> V_67 ( V_58 , V_36 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_26 -> V_68 ) {
V_65 = F_65 ( V_58 , V_69 ) ;
if ( V_65 == NULL )
return - V_61 ;
V_33 = V_26 -> V_68 ( V_58 , V_36 ) ;
if ( V_33 < 0 )
goto V_70;
F_66 ( V_58 , V_65 ) ;
}
return 0 ;
V_70:
F_67 ( V_58 , V_65 ) ;
return V_33 ;
}
static int F_69 ( struct V_2 * V_58 , const struct V_35 * V_36 )
{
struct V_50 * V_71 ;
int V_33 = - V_61 ;
V_71 = F_65 ( V_58 , V_72 ) ;
if ( V_71 == NULL )
goto V_48;
V_33 = F_68 ( V_58 , V_36 ) ;
if ( V_33 < 0 )
goto V_73;
V_33 = F_63 ( V_58 , V_36 ) ;
if ( V_33 < 0 )
goto V_73;
F_66 ( V_58 , V_71 ) ;
return 0 ;
V_73:
F_67 ( V_58 , V_71 ) ;
V_48:
return V_33 ;
}
int F_70 ( struct V_2 * V_58 , struct V_34 * V_34 , T_4 V_74 , unsigned int V_75 , int V_76 )
{
struct V_77 * V_78 = V_34 -> V_78 ;
int V_33 = 0 ;
F_71 ( V_58 ) . V_79 = V_75 ;
if ( V_76 )
F_72 ( & V_58 -> V_80 ) ;
F_73 ( V_78 , V_58 , V_74 , V_75 , V_19 ) ;
if ( V_76 )
V_33 = F_74 ( V_78 , V_58 , V_74 , V_81 ) ;
return V_33 ;
}
int F_75 ( struct V_2 * V_58 , struct V_34 * V_34 , T_4 V_74 )
{
struct V_77 * V_78 = V_34 -> V_78 ;
return F_76 ( V_78 , V_58 , V_74 ) ;
}
void F_77 ( struct V_2 * V_58 , struct V_34 * V_34 , T_4 V_74 , T_4 V_75 ,
struct V_82 * V_83 , T_5 V_14 )
{
struct V_77 * V_78 = V_34 -> V_78 ;
int V_84 = 0 ;
if ( V_83 )
V_84 = F_78 ( V_83 ) ;
F_79 ( V_78 , V_58 , V_74 , V_75 , V_84 , V_14 ) ;
}
void F_80 ( struct V_34 * V_34 , T_4 V_75 , int error )
{
struct V_77 * V_78 = V_34 -> V_78 ;
F_81 ( V_78 , 0 , V_75 , error ) ;
}
int F_82 ( struct V_2 * V_58 , T_4 * V_85 )
{
struct V_50 * V_86 ;
int V_87 , V_88 = 0 ;
V_86 = F_65 ( V_58 , V_89 ) ;
if ( V_86 == NULL )
return - V_20 ;
for ( V_87 = 0 ; V_87 < V_90 ; V_87 ++ ) {
if ( V_85 [ V_87 ] ) {
if ( V_87 == V_91 - 1 ) {
char V_92 [ V_93 ] , * V_94 ;
V_94 = F_83 ( V_85 [ V_87 ] , V_92 ) ;
if ( ! V_94 )
continue;
if ( F_64 ( V_58 , V_87 + 1 , V_94 ) )
goto V_95;
} else if ( V_87 == V_96 - 1 ) {
T_4 V_97 = V_85 [ V_87 ] & V_98 ;
if ( ! V_97 )
continue;
F_84 ( V_98 & V_99 ) ;
if ( F_85 ( V_58 , V_87 + 1 , V_97 ) )
goto V_95;
} else {
if ( F_85 ( V_58 , V_87 + 1 , V_85 [ V_87 ] ) )
goto V_95;
}
V_88 ++ ;
}
}
if ( ! V_88 ) {
F_67 ( V_58 , V_86 ) ;
return 0 ;
}
return F_66 ( V_58 , V_86 ) ;
V_95:
F_67 ( V_58 , V_86 ) ;
return - V_61 ;
}
int F_86 ( struct V_2 * V_58 , struct V_100 * V_101 , T_4 V_102 ,
long V_103 , T_4 error )
{
struct V_104 V_105 = {
. V_106 = F_87 ( V_107 - V_101 -> V_108 ) ,
. V_109 = V_101 -> V_110 ,
. V_111 = F_88 ( & ( V_101 -> V_112 ) ) ,
. V_113 = error ,
. V_114 = V_102 ,
} ;
if ( V_103 ) {
unsigned long clock ;
clock = F_89 ( abs ( V_103 ) ) ;
clock = F_90 (unsigned long, clock, INT_MAX) ;
V_105 . V_115 = ( V_103 > 0 ) ? clock : - clock ;
}
return F_91 ( V_58 , V_116 , sizeof( V_105 ) , & V_105 ) ;
}
static void F_92 ( struct V_35 * V_36 , unsigned char V_117 )
{
unsigned char V_118 = V_36 -> V_118 ;
switch ( V_117 ) {
case V_119 :
if ( ( V_118 == V_120 ||
V_118 == V_121 ) &&
! F_93 ( V_36 ) )
V_118 = V_119 ;
break;
case V_120 :
if ( V_118 == V_119 ||
V_118 == V_121 )
V_118 = V_120 ;
break;
}
if ( V_36 -> V_118 != V_118 ) {
F_94 ( & V_122 ) ;
V_36 -> V_118 = V_118 ;
F_95 ( & V_122 ) ;
F_96 ( V_36 ) ;
}
}
static unsigned int F_97 ( const struct V_35 * V_36 )
{
return ( V_36 -> V_14 & ~ ( V_123 | V_124 ) ) |
( V_36 -> V_125 & ( V_123 | V_124 ) ) ;
}
static unsigned int F_98 ( const struct V_35 * V_36 ,
const struct V_126 * V_127 )
{
unsigned int V_14 = V_127 -> V_128 ;
if ( V_127 -> V_129 )
V_14 = ( V_14 & V_127 -> V_129 ) |
( F_97 ( V_36 ) & ~ V_127 -> V_129 ) ;
return V_14 ;
}
static void F_99 ( struct V_130 * V_131 ,
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
static inline int F_100 ( const struct V_35 * V_36 ,
T_4 V_55 )
{
if ( V_36 -> V_36 . V_158 && ( V_55 & V_159 ) ) {
int V_160 = F_101 ( V_36 -> V_36 . V_158 ) ;
T_3 V_47 = F_53 ( 0 ) ;
V_47 += V_160 *
( F_53 ( 0 ) +
F_53 ( sizeof( struct V_161 ) ) +
F_53 ( sizeof( struct V_162 ) ) +
F_53 ( 0 ) +
F_53 ( V_163 *
sizeof( struct V_164 ) ) +
F_53 ( sizeof( struct V_165 ) ) +
F_53 ( sizeof( struct V_166 ) ) +
F_53 ( sizeof( struct V_167 ) ) +
F_53 ( sizeof( struct V_168 ) ) +
F_53 ( sizeof( struct V_169 ) ) +
F_53 ( 0 ) +
F_102 ( sizeof( V_170 ) ) +
F_102 ( sizeof( V_170 ) ) +
F_102 ( sizeof( V_170 ) ) +
F_102 ( sizeof( V_170 ) ) +
F_102 ( sizeof( V_170 ) ) +
F_102 ( sizeof( V_170 ) ) +
F_53 ( sizeof( struct V_171 ) ) ) ;
return V_47 ;
} else
return 0 ;
}
static T_3 F_103 ( const struct V_35 * V_36 ,
T_4 V_55 )
{
T_3 V_172 = F_53 ( 4 )
+ F_53 ( V_173 )
+ F_53 ( V_174 )
+ F_53 ( V_174 )
+ F_53 ( 1 )
+ F_53 ( 2 ) ;
T_3 V_175 = F_53 ( sizeof( struct V_50 ) ) ;
T_3 V_176 = F_53 ( sizeof( struct V_50 ) )
+ V_172 ;
T_3 V_177 = F_53 ( sizeof( struct V_50 ) )
+ V_172 ;
if ( ! V_36 -> V_178 -> V_179 || ! V_36 -> V_36 . V_158 ||
! ( V_55 & V_159 ) )
return 0 ;
if ( F_101 ( V_36 -> V_36 . V_158 ) )
return V_177 + V_175 +
V_176 * F_101 ( V_36 -> V_36 . V_158 ) ;
else
return V_177 ;
}
static T_3 F_104 ( void )
{
T_3 V_180 = F_53 ( 0 ) +
F_53 ( 1 ) +
F_53 ( 4 ) ;
return V_180 ;
}
static T_6 T_3 F_105 ( const struct V_35 * V_36 ,
T_4 V_55 )
{
return F_106 ( sizeof( struct V_126 ) )
+ F_53 ( V_181 )
+ F_53 ( V_182 )
+ F_53 ( V_181 )
+ F_102 ( sizeof( struct V_183 ) )
+ F_53 ( sizeof( struct V_130 ) )
+ F_102 ( sizeof( struct V_132 ) )
+ F_53 ( V_184 )
+ F_53 ( V_184 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 1 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 1 )
+ F_53 ( 1 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( V_55
& V_159 ? 4 : 0 )
+ F_100 ( V_36 , V_55 )
+ F_103 ( V_36 , V_55 )
+ F_55 ( V_36 )
+ F_60 ( V_36 , V_55 )
+ F_53 ( V_185 )
+ F_53 ( V_185 )
+ F_53 ( V_181 )
+ F_104 ()
+ F_53 ( 4 )
+ F_53 ( 1 ) ;
}
static int F_107 ( struct V_2 * V_58 , struct V_35 * V_36 )
{
struct V_50 * V_186 ;
struct V_50 * V_187 ;
int V_188 ;
int V_33 ;
V_186 = F_65 ( V_58 , V_189 ) ;
if ( ! V_186 )
return - V_61 ;
for ( V_188 = 0 ; V_188 < F_101 ( V_36 -> V_36 . V_158 ) ; V_188 ++ ) {
V_187 = F_65 ( V_58 , V_190 ) ;
if ( ! V_187 )
goto V_95;
if ( F_85 ( V_58 , V_191 , V_188 ) )
goto V_95;
V_33 = V_36 -> V_178 -> V_179 ( V_36 , V_188 , V_58 ) ;
if ( V_33 == - V_61 )
goto V_95;
if ( V_33 ) {
F_67 ( V_58 , V_187 ) ;
continue;
}
F_66 ( V_58 , V_187 ) ;
}
F_66 ( V_58 , V_186 ) ;
return 0 ;
V_95:
F_67 ( V_58 , V_186 ) ;
return - V_61 ;
}
static int F_108 ( struct V_2 * V_58 , struct V_35 * V_36 )
{
struct V_50 * V_192 ;
int V_33 ;
V_192 = F_65 ( V_58 , V_193 ) ;
if ( ! V_192 )
return - V_61 ;
V_33 = V_36 -> V_178 -> V_179 ( V_36 , V_194 , V_58 ) ;
if ( V_33 ) {
F_67 ( V_58 , V_192 ) ;
return ( V_33 == - V_61 ) ? V_33 : 0 ;
}
F_66 ( V_58 , V_192 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_58 , struct V_35 * V_36 ,
T_4 V_55 )
{
int V_33 ;
if ( ! V_36 -> V_178 -> V_179 || ! V_36 -> V_36 . V_158 ||
! ( V_55 & V_159 ) )
return 0 ;
V_33 = F_108 ( V_58 , V_36 ) ;
if ( V_33 )
return V_33 ;
if ( F_101 ( V_36 -> V_36 . V_158 ) ) {
V_33 = F_107 ( V_58 , V_36 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_110 ( struct V_2 * V_58 , struct V_35 * V_36 )
{
int V_33 ;
struct V_195 V_196 ;
V_33 = F_111 ( V_36 , & V_196 ) ;
if ( V_33 ) {
if ( V_33 == - V_197 )
return 0 ;
return V_33 ;
}
if ( F_91 ( V_58 , V_198 , V_196 . V_199 , V_196 . V_102 ) )
return - V_61 ;
return 0 ;
}
static int F_112 ( struct V_2 * V_58 , struct V_35 * V_36 )
{
char V_94 [ V_181 ] ;
int V_33 ;
V_33 = F_113 ( V_36 , V_94 , sizeof( V_94 ) ) ;
if ( V_33 ) {
if ( V_33 == - V_197 )
return 0 ;
return V_33 ;
}
if ( F_64 ( V_58 , V_200 , V_94 ) )
return - V_61 ;
return 0 ;
}
static int F_114 ( struct V_2 * V_58 , struct V_35 * V_36 )
{
int V_33 ;
struct V_201 V_202 = {
. V_203 = V_36 ,
. V_102 = V_204 ,
. V_14 = V_205 ,
} ;
V_33 = F_115 ( V_36 , & V_202 ) ;
if ( V_33 ) {
if ( V_33 == - V_197 )
return 0 ;
return V_33 ;
}
if ( F_91 ( V_58 , V_206 , V_202 . V_207 . V_196 . V_199 ,
V_202 . V_207 . V_196 . V_102 ) )
return - V_61 ;
return 0 ;
}
static T_7 int F_116 ( struct V_2 * V_58 ,
struct V_35 * V_36 )
{
struct V_132 * V_208 ;
struct V_50 * V_202 ;
V_202 = F_117 ( V_58 , V_209 ,
sizeof( struct V_132 ) , V_210 ) ;
if ( ! V_202 )
return - V_61 ;
V_208 = F_118 ( V_202 ) ;
F_119 ( V_36 , V_208 ) ;
V_202 = F_120 ( V_58 , V_211 ,
sizeof( struct V_130 ) ) ;
if ( ! V_202 )
return - V_61 ;
F_99 ( F_118 ( V_202 ) , V_208 ) ;
return 0 ;
}
static T_7 int F_121 ( struct V_2 * V_58 ,
struct V_35 * V_36 ,
int V_212 ,
struct V_50 * V_213 )
{
struct V_169 V_214 ;
struct V_50 * V_188 , * V_215 , * V_216 ;
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
V_228 . V_233 = F_122 ( V_234 ) ;
if ( V_36 -> V_178 -> V_235 ( V_36 , V_212 , & V_228 ) )
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
V_188 = F_65 ( V_58 , V_244 ) ;
if ( ! V_188 )
goto V_245;
if ( F_91 ( V_58 , V_246 , sizeof( V_226 ) , & V_226 ) ||
F_91 ( V_58 , V_247 , sizeof( V_224 ) , & V_224 ) ||
F_91 ( V_58 , V_248 , sizeof( V_225 ) ,
& V_225 ) ||
F_91 ( V_58 , V_249 , sizeof( V_220 ) ,
& V_220 ) ||
F_91 ( V_58 , V_250 , sizeof( V_219 ) ,
& V_219 ) ||
F_91 ( V_58 , V_251 , sizeof( V_217 ) ,
& V_217 ) ||
F_91 ( V_58 , V_252 ,
sizeof( V_214 ) ,
& V_214 ) ||
F_91 ( V_58 , V_253 ,
sizeof( V_223 ) , & V_223 ) )
goto V_254;
V_216 = F_65 ( V_58 , V_255 ) ;
if ( ! V_216 )
goto V_254;
if ( F_91 ( V_58 , V_256 , sizeof( V_218 ) ,
& V_218 ) ) {
F_67 ( V_58 , V_216 ) ;
goto V_254;
}
F_66 ( V_58 , V_216 ) ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
if ( V_36 -> V_178 -> V_257 )
V_36 -> V_178 -> V_257 ( V_36 , V_212 ,
& V_222 ) ;
V_215 = F_65 ( V_58 , V_258 ) ;
if ( ! V_215 )
goto V_254;
if ( F_123 ( V_58 , V_259 ,
V_222 . V_134 , V_260 ) ||
F_123 ( V_58 , V_261 ,
V_222 . V_135 , V_260 ) ||
F_123 ( V_58 , V_262 ,
V_222 . V_136 , V_260 ) ||
F_123 ( V_58 , V_263 ,
V_222 . V_137 , V_260 ) ||
F_123 ( V_58 , V_264 ,
V_222 . V_265 , V_260 ) ||
F_123 ( V_58 , V_266 ,
V_222 . V_142 , V_260 ) ) {
F_67 ( V_58 , V_215 ) ;
goto V_254;
}
F_66 ( V_58 , V_215 ) ;
F_66 ( V_58 , V_188 ) ;
return 0 ;
V_254:
F_67 ( V_58 , V_188 ) ;
V_245:
F_67 ( V_58 , V_213 ) ;
return - V_61 ;
}
static int F_124 ( struct V_2 * V_58 , struct V_35 * V_36 )
{
struct V_183 V_267 ;
memset ( & V_267 , 0 , sizeof( V_267 ) ) ;
V_267 . V_268 = V_36 -> V_268 ;
V_267 . V_269 = V_36 -> V_269 ;
V_267 . V_270 = V_36 -> V_270 ;
V_267 . V_271 = V_36 -> V_271 ;
V_267 . V_272 = V_36 -> V_272 ;
V_267 . V_273 = V_36 -> V_274 ;
if ( F_125 ( V_58 , V_275 , sizeof( V_267 ) , & V_267 , V_210 ) )
return - V_61 ;
return 0 ;
}
static T_8 F_126 ( struct V_35 * V_36 , T_4 * V_276 )
{
const struct V_277 * V_26 = V_36 -> V_178 ;
const struct V_278 * V_279 ;
F_127 () ;
* V_276 = 0 ;
V_279 = F_25 ( V_36 -> V_280 ) ;
if ( V_279 ) {
* V_276 = V_279 -> V_281 -> V_102 ;
return V_282 ;
}
if ( ! V_26 -> V_283 )
return V_284 ;
return F_128 ( V_36 , V_26 -> V_283 , V_276 ) ;
}
static int F_129 ( struct V_2 * V_58 , struct V_35 * V_36 )
{
struct V_50 * V_285 ;
T_4 V_276 ;
int V_33 ;
V_285 = F_65 ( V_58 , V_286 ) ;
if ( ! V_285 )
return - V_61 ;
V_33 = F_130 ( V_58 , V_287 ,
F_126 ( V_36 , & V_276 ) ) ;
if ( V_33 )
goto V_288;
if ( V_276 ) {
V_33 = F_85 ( V_58 , V_289 , V_276 ) ;
if ( V_33 )
goto V_288;
}
F_66 ( V_58 , V_285 ) ;
return 0 ;
V_288:
F_67 ( V_58 , V_285 ) ;
return V_33 ;
}
static T_4 F_131 ( unsigned long V_290 )
{
T_4 V_291 = V_292 ;
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
static int F_132 ( struct V_2 * V_58 , struct V_35 * V_36 ,
int type , T_4 V_74 , T_4 V_305 , T_4 V_306 ,
unsigned int V_14 , T_4 V_55 ,
T_4 V_290 )
{
struct V_126 * V_127 ;
struct V_82 * V_83 ;
struct V_50 * V_307 ;
struct V_53 * V_56 ;
struct V_35 * V_308 = F_62 ( V_36 ) ;
F_127 () ;
V_83 = F_133 ( V_58 , V_74 , V_305 , type , sizeof( * V_127 ) , V_14 ) ;
if ( V_83 == NULL )
return - V_61 ;
V_127 = F_134 ( V_83 ) ;
V_127 -> V_309 = V_310 ;
V_127 -> V_311 = 0 ;
V_127 -> V_312 = V_36 -> type ;
V_127 -> V_313 = V_36 -> V_314 ;
V_127 -> V_128 = F_135 ( V_36 ) ;
V_127 -> V_129 = V_306 ;
if ( F_64 ( V_58 , V_315 , V_36 -> V_94 ) ||
F_85 ( V_58 , V_316 , V_36 -> V_317 ) ||
F_130 ( V_58 , V_318 ,
F_136 ( V_36 ) ? V_36 -> V_118 : V_319 ) ||
F_130 ( V_58 , V_320 , V_36 -> V_321 ) ||
F_85 ( V_58 , V_322 , V_36 -> V_323 ) ||
F_85 ( V_58 , V_324 , V_36 -> V_75 ) ||
F_85 ( V_58 , V_325 , V_36 -> V_326 ) ||
F_85 ( V_58 , V_327 , V_36 -> V_328 ) ||
F_85 ( V_58 , V_329 , V_36 -> V_330 ) ||
F_85 ( V_58 , V_331 , V_36 -> V_332 ) ||
#ifdef F_137
F_85 ( V_58 , V_333 , V_36 -> V_334 ) ||
#endif
( V_36 -> V_314 != F_138 ( V_36 ) &&
F_85 ( V_58 , V_335 , F_138 ( V_36 ) ) ) ||
( V_308 &&
F_85 ( V_58 , V_336 , V_308 -> V_314 ) ) ||
F_130 ( V_58 , V_337 , F_139 ( V_36 ) ) ||
( V_36 -> V_338 &&
F_64 ( V_58 , V_339 , V_36 -> V_338 -> V_26 -> V_102 ) ) ||
( V_36 -> V_340 &&
F_64 ( V_58 , V_341 , V_36 -> V_340 ) ) ||
F_85 ( V_58 , V_342 ,
F_88 ( & V_36 -> V_343 ) ) ||
F_130 ( V_58 , V_344 , V_36 -> V_345 ) )
goto V_95;
if ( V_290 != V_292 ) {
if ( F_85 ( V_58 , V_346 , V_290 ) )
goto V_95;
}
if ( F_124 ( V_58 , V_36 ) )
goto V_95;
if ( V_36 -> V_347 ) {
if ( F_91 ( V_58 , V_348 , V_36 -> V_347 , V_36 -> V_349 ) ||
F_91 ( V_58 , V_350 , V_36 -> V_347 , V_36 -> V_265 ) )
goto V_95;
}
if ( F_110 ( V_58 , V_36 ) )
goto V_95;
if ( F_112 ( V_58 , V_36 ) )
goto V_95;
if ( F_114 ( V_58 , V_36 ) )
goto V_95;
if ( F_116 ( V_58 , V_36 ) )
goto V_95;
if ( V_36 -> V_36 . V_158 && ( V_55 & V_159 ) &&
F_85 ( V_58 , V_351 , F_101 ( V_36 -> V_36 . V_158 ) ) )
goto V_95;
if ( V_36 -> V_178 -> V_235 && V_36 -> V_36 . V_158 &&
V_55 & V_159 ) {
int V_87 ;
struct V_50 * V_213 ;
int V_160 = F_101 ( V_36 -> V_36 . V_158 ) ;
V_213 = F_65 ( V_58 , V_352 ) ;
if ( ! V_213 )
goto V_95;
for ( V_87 = 0 ; V_87 < V_160 ; V_87 ++ ) {
if ( F_121 ( V_58 , V_36 , V_87 , V_213 ) )
goto V_95;
}
F_66 ( V_58 , V_213 ) ;
}
if ( F_109 ( V_58 , V_36 , V_55 ) )
goto V_95;
if ( F_129 ( V_58 , V_36 ) )
goto V_95;
if ( V_36 -> V_24 || F_61 ( V_36 ) ) {
if ( F_69 ( V_58 , V_36 ) < 0 )
goto V_95;
}
if ( V_36 -> V_24 &&
V_36 -> V_24 -> V_353 ) {
struct V_34 * V_354 = V_36 -> V_24 -> V_353 ( V_36 ) ;
if ( ! F_140 ( F_141 ( V_36 ) , V_354 ) ) {
int V_102 = F_142 ( F_141 ( V_36 ) , V_354 ) ;
if ( F_143 ( V_58 , V_355 , V_102 ) )
goto V_95;
}
}
if ( ! ( V_307 = F_65 ( V_58 , V_356 ) ) )
goto V_95;
F_33 (af_ops, &rtnl_af_ops, list) {
if ( V_56 -> V_357 ) {
struct V_50 * V_358 ;
int V_33 ;
if ( ! ( V_358 = F_65 ( V_58 , V_56 -> V_54 ) ) )
goto V_95;
V_33 = V_56 -> V_357 ( V_58 , V_36 , V_55 ) ;
if ( V_33 == - V_359 )
F_67 ( V_58 , V_358 ) ;
else if ( V_33 < 0 )
goto V_95;
F_66 ( V_58 , V_358 ) ;
}
}
F_66 ( V_58 , V_307 ) ;
F_144 ( V_58 , V_83 ) ;
return 0 ;
V_95:
F_145 ( V_58 , V_83 ) ;
return - V_61 ;
}
static const struct V_24 * F_146 ( const struct V_50 * V_360 )
{
const struct V_24 * V_26 = NULL ;
struct V_50 * V_361 [ V_362 + 1 ] ;
if ( F_147 ( V_361 , V_362 , V_360 ,
V_363 , NULL ) < 0 )
return NULL ;
if ( V_361 [ V_66 ] ) {
char V_25 [ V_364 ] ;
F_148 ( V_25 , V_361 [ V_66 ] , sizeof( V_25 ) ) ;
V_26 = F_32 ( V_25 ) ;
}
return V_26 ;
}
static bool F_149 ( struct V_35 * V_36 , int V_365 )
{
struct V_35 * V_366 ;
if ( ! V_365 )
return false ;
V_366 = F_62 ( V_36 ) ;
if ( ! V_366 || V_366 -> V_314 != V_365 )
return true ;
return false ;
}
static bool F_150 ( const struct V_35 * V_36 ,
const struct V_24 * V_367 )
{
if ( V_367 && V_36 -> V_24 != V_367 )
return true ;
return false ;
}
static bool F_151 ( struct V_35 * V_36 ,
int V_365 ,
const struct V_24 * V_367 )
{
if ( F_149 ( V_36 , V_365 ) ||
F_150 ( V_36 , V_367 ) )
return true ;
return false ;
}
static int F_152 ( struct V_2 * V_58 , struct V_368 * V_369 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
int V_371 , V_372 ;
int V_373 = 0 , V_374 ;
struct V_35 * V_36 ;
struct V_375 * V_3 ;
struct V_50 * V_376 [ V_377 + 1 ] ;
T_4 V_55 = 0 ;
const struct V_24 * V_367 = NULL ;
unsigned int V_14 = V_378 ;
int V_365 = 0 ;
int V_33 ;
int V_379 ;
V_372 = V_369 -> args [ 0 ] ;
V_374 = V_369 -> args [ 1 ] ;
V_379 = F_154 ( V_369 -> V_83 ) < sizeof( struct V_126 ) ?
sizeof( struct V_380 ) : sizeof( struct V_126 ) ;
if ( F_155 ( V_369 -> V_83 , V_379 , V_376 , V_377 ,
V_381 , NULL ) >= 0 ) {
if ( V_376 [ V_382 ] )
V_55 = F_156 ( V_376 [ V_382 ] ) ;
if ( V_376 [ V_336 ] )
V_365 = F_156 ( V_376 [ V_336 ] ) ;
if ( V_376 [ V_72 ] )
V_367 = F_146 ( V_376 [ V_72 ] ) ;
if ( V_365 || V_367 )
V_14 |= V_383 ;
}
for ( V_371 = V_372 ; V_371 < V_384 ; V_371 ++ , V_374 = 0 ) {
V_373 = 0 ;
V_3 = & V_34 -> V_385 [ V_371 ] ;
F_157 (dev, head, index_hlist) {
if ( F_151 ( V_36 , V_365 , V_367 ) )
goto V_386;
if ( V_373 < V_374 )
goto V_386;
V_33 = F_132 ( V_58 , V_36 , V_387 ,
F_71 ( V_369 -> V_58 ) . V_388 ,
V_369 -> V_83 -> V_389 , 0 ,
V_14 ,
V_55 , 0 ) ;
if ( V_33 < 0 ) {
if ( F_158 ( V_58 -> V_390 ) )
goto V_48;
goto V_391;
}
V_386:
V_373 ++ ;
}
}
V_48:
V_33 = V_58 -> V_390 ;
V_391:
V_369 -> args [ 1 ] = V_373 ;
V_369 -> args [ 0 ] = V_371 ;
V_369 -> V_305 = V_34 -> V_392 ;
F_159 ( V_369 , F_160 ( V_58 ) ) ;
return V_33 ;
}
int F_161 ( struct V_50 * * V_376 , const struct V_50 * V_3 , int V_390 ,
struct V_393 * V_394 )
{
return F_162 ( V_376 , V_377 , V_3 , V_390 , V_381 , V_394 ) ;
}
struct V_34 * F_163 ( struct V_34 * V_395 , struct V_50 * V_376 [] )
{
struct V_34 * V_34 ;
if ( V_376 [ V_396 ] )
V_34 = F_164 ( F_156 ( V_376 [ V_396 ] ) ) ;
else if ( V_376 [ V_397 ] )
V_34 = F_165 ( F_156 ( V_376 [ V_397 ] ) ) ;
else
V_34 = F_166 ( V_395 ) ;
return V_34 ;
}
static int F_167 ( struct V_35 * V_36 , struct V_50 * V_376 [] )
{
if ( V_36 ) {
if ( V_376 [ V_348 ] &&
F_168 ( V_376 [ V_348 ] ) < V_36 -> V_347 )
return - V_398 ;
if ( V_376 [ V_350 ] &&
F_168 ( V_376 [ V_350 ] ) < V_36 -> V_347 )
return - V_398 ;
}
if ( V_376 [ V_356 ] ) {
struct V_50 * V_358 ;
int V_399 , V_33 ;
F_169 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_53 * V_56 ;
if ( ! ( V_56 = F_56 ( F_170 ( V_358 ) ) ) )
return - V_400 ;
if ( ! V_56 -> V_401 )
return - V_197 ;
if ( V_56 -> V_402 ) {
V_33 = V_56 -> V_402 ( V_36 , V_358 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
}
return 0 ;
}
static int F_171 ( struct V_35 * V_36 , struct V_403 * V_404 ,
int V_405 )
{
const struct V_277 * V_26 = V_36 -> V_178 ;
return V_26 -> V_406 ( V_36 , V_404 -> V_188 , V_404 -> V_407 , V_405 ) ;
}
static int F_172 ( struct V_35 * V_36 , struct V_403 * V_404 , int V_405 )
{
if ( V_36 -> type != V_408 )
return - V_197 ;
return F_171 ( V_36 , V_404 , V_405 ) ;
}
static int F_173 ( struct V_35 * V_36 , struct V_50 * * V_376 )
{
const struct V_277 * V_26 = V_36 -> V_178 ;
int V_33 = - V_398 ;
if ( V_376 [ V_246 ] ) {
struct V_161 * V_409 = F_118 ( V_376 [ V_246 ] ) ;
V_33 = - V_197 ;
if ( V_26 -> V_410 )
V_33 = V_26 -> V_410 ( V_36 , V_409 -> V_188 ,
V_409 -> V_236 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_376 [ V_247 ] ) {
struct V_162 * V_411 = F_118 ( V_376 [ V_247 ] ) ;
V_33 = - V_197 ;
if ( V_26 -> V_412 )
V_33 = V_26 -> V_412 ( V_36 , V_411 -> V_188 , V_411 -> V_237 ,
V_411 -> V_238 ,
F_122 ( V_234 ) ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_376 [ V_255 ] ) {
struct V_164 * V_413 [ V_163 ] ;
struct V_50 * V_202 ;
int V_399 , V_390 = 0 ;
V_33 = - V_197 ;
if ( ! V_26 -> V_412 )
return V_33 ;
F_169 (attr, tb[IFLA_VF_VLAN_LIST], rem) {
if ( F_170 ( V_202 ) != V_256 ||
F_168 ( V_202 ) < V_414 ) {
return - V_398 ;
}
if ( V_390 >= V_163 )
return - V_197 ;
V_413 [ V_390 ] = F_118 ( V_202 ) ;
V_390 ++ ;
}
if ( V_390 == 0 )
return - V_398 ;
V_33 = V_26 -> V_412 ( V_36 , V_413 [ 0 ] -> V_188 , V_413 [ 0 ] -> V_237 ,
V_413 [ 0 ] -> V_238 , V_413 [ 0 ] -> V_233 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_376 [ V_249 ] ) {
struct V_166 * V_404 = F_118 ( V_376 [ V_249 ] ) ;
struct V_227 V_415 ;
V_33 = - V_197 ;
if ( V_26 -> V_235 )
V_33 = V_26 -> V_235 ( V_36 , V_404 -> V_188 , & V_415 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = - V_197 ;
if ( V_26 -> V_416 )
V_33 = V_26 -> V_416 ( V_36 , V_404 -> V_188 ,
V_415 . V_241 ,
V_404 -> V_239 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_376 [ V_248 ] ) {
struct V_167 * V_404 = F_118 ( V_376 [ V_248 ] ) ;
V_33 = - V_197 ;
if ( V_26 -> V_416 )
V_33 = V_26 -> V_416 ( V_36 , V_404 -> V_188 ,
V_404 -> V_241 ,
V_404 -> V_240 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_376 [ V_250 ] ) {
struct V_165 * V_417 = F_118 ( V_376 [ V_250 ] ) ;
V_33 = - V_197 ;
if ( V_26 -> V_418 )
V_33 = V_26 -> V_418 ( V_36 , V_417 -> V_188 ,
V_417 -> V_242 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_376 [ V_251 ] ) {
struct V_168 * V_419 = F_118 ( V_376 [ V_251 ] ) ;
V_33 = - V_197 ;
if ( V_26 -> V_420 )
V_33 = V_26 -> V_420 ( V_36 , V_419 -> V_188 ,
V_419 -> V_243 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_376 [ V_252 ] ) {
struct V_169 * V_421 ;
V_33 = - V_197 ;
V_421 = F_118 ( V_376 [ V_252 ] ) ;
if ( V_26 -> V_422 )
V_33 = V_26 -> V_422 ( V_36 , V_421 -> V_188 ,
V_421 -> V_242 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_376 [ V_253 ] ) {
struct V_171 * V_404 = F_118 ( V_376 [ V_253 ] ) ;
V_33 = - V_197 ;
if ( V_26 -> V_423 )
V_33 = V_26 -> V_423 ( V_36 , V_404 -> V_188 , V_404 -> V_242 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_376 [ V_424 ] ) {
struct V_403 * V_404 = F_118 ( V_376 [ V_424 ] ) ;
if ( ! V_26 -> V_406 )
return - V_197 ;
return F_172 ( V_36 , V_404 , V_424 ) ;
}
if ( V_376 [ V_425 ] ) {
struct V_403 * V_404 = F_118 ( V_376 [ V_425 ] ) ;
if ( ! V_26 -> V_406 )
return - V_197 ;
return F_172 ( V_36 , V_404 , V_425 ) ;
}
return V_33 ;
}
static int F_174 ( struct V_35 * V_36 , int V_314 )
{
struct V_35 * V_308 = F_62 ( V_36 ) ;
const struct V_277 * V_26 ;
int V_33 ;
if ( V_308 ) {
if ( V_308 -> V_314 == V_314 )
return 0 ;
V_26 = V_308 -> V_178 ;
if ( V_26 -> V_426 ) {
V_33 = V_26 -> V_426 ( V_308 , V_36 ) ;
if ( V_33 )
return V_33 ;
} else {
return - V_197 ;
}
}
if ( V_314 ) {
V_308 = F_175 ( F_141 ( V_36 ) , V_314 ) ;
if ( ! V_308 )
return - V_398 ;
V_26 = V_308 -> V_178 ;
if ( V_26 -> V_427 ) {
V_33 = V_26 -> V_427 ( V_308 , V_36 ) ;
if ( V_33 )
return V_33 ;
} else {
return - V_197 ;
}
}
return 0 ;
}
static int F_176 ( const struct V_2 * V_58 ,
struct V_35 * V_36 , struct V_126 * V_127 ,
struct V_393 * V_428 ,
struct V_50 * * V_376 , char * V_429 , int V_430 )
{
const struct V_277 * V_26 = V_36 -> V_178 ;
int V_33 ;
if ( V_376 [ V_396 ] || V_376 [ V_397 ] ) {
struct V_34 * V_34 = F_163 ( F_141 ( V_36 ) , V_376 ) ;
if ( F_177 ( V_34 ) ) {
V_33 = F_178 ( V_34 ) ;
goto V_431;
}
if ( ! F_179 ( V_58 , V_34 -> V_432 , V_433 ) ) {
F_180 ( V_34 ) ;
V_33 = - V_434 ;
goto V_431;
}
V_33 = F_181 ( V_36 , V_34 , V_429 ) ;
F_180 ( V_34 ) ;
if ( V_33 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_275 ] ) {
struct V_183 * V_436 ;
struct V_437 V_438 ;
if ( ! V_26 -> V_439 ) {
V_33 = - V_197 ;
goto V_431;
}
if ( ! F_182 ( V_36 ) ) {
V_33 = - V_440 ;
goto V_431;
}
V_436 = F_118 ( V_376 [ V_275 ] ) ;
V_438 . V_268 = ( unsigned long ) V_436 -> V_268 ;
V_438 . V_269 = ( unsigned long ) V_436 -> V_269 ;
V_438 . V_270 = ( unsigned short ) V_436 -> V_270 ;
V_438 . V_271 = ( unsigned char ) V_436 -> V_271 ;
V_438 . V_272 = ( unsigned char ) V_436 -> V_272 ;
V_438 . V_273 = ( unsigned char ) V_436 -> V_273 ;
V_33 = V_26 -> V_439 ( V_36 , & V_438 ) ;
if ( V_33 < 0 )
goto V_431;
V_430 |= V_441 ;
}
if ( V_376 [ V_348 ] ) {
struct V_442 * V_443 ;
int V_390 ;
V_390 = sizeof( V_444 ) + F_183 ( T_3 , V_36 -> V_347 ,
sizeof( * V_443 ) ) ;
V_443 = F_184 ( V_390 , V_19 ) ;
if ( ! V_443 ) {
V_33 = - V_445 ;
goto V_431;
}
V_443 -> V_446 = V_36 -> type ;
memcpy ( V_443 -> V_447 , F_118 ( V_376 [ V_348 ] ) ,
V_36 -> V_347 ) ;
V_33 = F_185 ( V_36 , V_443 ) ;
F_31 ( V_443 ) ;
if ( V_33 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_322 ] ) {
V_33 = F_186 ( V_36 , F_156 ( V_376 [ V_322 ] ) ) ;
if ( V_33 < 0 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_324 ] ) {
F_187 ( V_36 , F_156 ( V_376 [ V_324 ] ) ) ;
V_430 |= V_441 ;
}
if ( V_127 -> V_313 > 0 && V_429 [ 0 ] ) {
V_33 = F_188 ( V_36 , V_429 ) ;
if ( V_33 < 0 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_341 ] ) {
V_33 = F_189 ( V_36 , F_118 ( V_376 [ V_341 ] ) ,
F_168 ( V_376 [ V_341 ] ) ) ;
if ( V_33 < 0 )
goto V_431;
V_430 |= V_441 ;
}
if ( V_376 [ V_350 ] ) {
F_190 ( V_36 -> V_265 , V_376 [ V_350 ] , V_36 -> V_347 ) ;
F_191 ( V_448 , V_36 ) ;
}
if ( V_127 -> V_128 || V_127 -> V_129 ) {
V_33 = F_192 ( V_36 , F_98 ( V_36 , V_127 ) ) ;
if ( V_33 < 0 )
goto V_431;
}
if ( V_376 [ V_336 ] ) {
V_33 = F_174 ( V_36 , F_156 ( V_376 [ V_336 ] ) ) ;
if ( V_33 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_337 ] ) {
V_33 = F_193 ( V_36 , F_194 ( V_376 [ V_337 ] ) ) ;
if ( V_33 )
goto V_431;
V_430 |= V_435 ;
}
if ( V_376 [ V_316 ] ) {
unsigned int V_449 = F_156 ( V_376 [ V_316 ] ) ;
unsigned int V_450 = V_36 -> V_317 ;
if ( V_36 -> V_317 ^ V_449 ) {
V_36 -> V_317 = V_449 ;
V_33 = F_191 (
V_451 , V_36 ) ;
V_33 = F_195 ( V_33 ) ;
if ( V_33 ) {
V_36 -> V_317 = V_450 ;
goto V_431;
}
V_430 |= V_435 ;
}
}
if ( V_376 [ V_318 ] )
F_92 ( V_36 , F_194 ( V_376 [ V_318 ] ) ) ;
if ( V_376 [ V_320 ] ) {
unsigned char V_449 = F_194 ( V_376 [ V_320 ] ) ;
F_94 ( & V_122 ) ;
if ( V_36 -> V_321 ^ V_449 )
V_430 |= V_441 ;
V_36 -> V_321 = V_449 ;
F_95 ( & V_122 ) ;
}
if ( V_376 [ V_352 ] ) {
struct V_50 * V_213 [ V_452 + 1 ] ;
struct V_50 * V_202 ;
int V_399 ;
F_169 (attr, tb[IFLA_VFINFO_LIST], rem) {
if ( F_170 ( V_202 ) != V_244 ||
F_168 ( V_202 ) < V_414 ) {
V_33 = - V_398 ;
goto V_431;
}
V_33 = F_147 ( V_213 , V_452 , V_202 ,
V_453 , NULL ) ;
if ( V_33 < 0 )
goto V_431;
V_33 = F_173 ( V_36 , V_213 ) ;
if ( V_33 < 0 )
goto V_431;
V_430 |= V_441 ;
}
}
V_33 = 0 ;
if ( V_376 [ V_189 ] ) {
struct V_50 * V_273 [ V_454 + 1 ] ;
struct V_50 * V_202 ;
int V_188 ;
int V_399 ;
V_33 = - V_197 ;
if ( ! V_26 -> V_455 )
goto V_431;
F_169 (attr, tb[IFLA_VF_PORTS], rem) {
if ( F_170 ( V_202 ) != V_190 ||
F_168 ( V_202 ) < V_414 ) {
V_33 = - V_398 ;
goto V_431;
}
V_33 = F_147 ( V_273 , V_454 , V_202 ,
V_456 , NULL ) ;
if ( V_33 < 0 )
goto V_431;
if ( ! V_273 [ V_191 ] ) {
V_33 = - V_197 ;
goto V_431;
}
V_188 = F_156 ( V_273 [ V_191 ] ) ;
V_33 = V_26 -> V_455 ( V_36 , V_188 , V_273 ) ;
if ( V_33 < 0 )
goto V_431;
V_430 |= V_441 ;
}
}
V_33 = 0 ;
if ( V_376 [ V_193 ] ) {
struct V_50 * V_273 [ V_454 + 1 ] ;
V_33 = F_147 ( V_273 , V_454 ,
V_376 [ V_193 ] , V_456 ,
NULL ) ;
if ( V_33 < 0 )
goto V_431;
V_33 = - V_197 ;
if ( V_26 -> V_455 )
V_33 = V_26 -> V_455 ( V_36 , V_194 , V_273 ) ;
if ( V_33 < 0 )
goto V_431;
V_430 |= V_441 ;
}
if ( V_376 [ V_356 ] ) {
struct V_50 * V_358 ;
int V_399 ;
F_169 (af, tb[IFLA_AF_SPEC], rem) {
const struct V_53 * V_56 ;
if ( ! ( V_56 = F_56 ( F_170 ( V_358 ) ) ) )
F_196 () ;
V_33 = V_56 -> V_401 ( V_36 , V_358 ) ;
if ( V_33 < 0 )
goto V_431;
V_430 |= V_441 ;
}
}
V_33 = 0 ;
if ( V_376 [ V_344 ] ) {
V_33 = F_197 ( V_36 ,
F_194 ( V_376 [ V_344 ] ) ) ;
if ( V_33 )
goto V_431;
V_430 |= V_441 ;
}
if ( V_376 [ V_286 ] ) {
struct V_50 * V_285 [ V_457 + 1 ] ;
T_4 V_458 = 0 ;
V_33 = F_147 ( V_285 , V_457 , V_376 [ V_286 ] ,
V_459 , NULL ) ;
if ( V_33 < 0 )
goto V_431;
if ( V_285 [ V_287 ] || V_285 [ V_289 ] ) {
V_33 = - V_398 ;
goto V_431;
}
if ( V_285 [ V_460 ] ) {
V_458 = F_156 ( V_285 [ V_460 ] ) ;
if ( V_458 & ~ V_461 ) {
V_33 = - V_398 ;
goto V_431;
}
if ( F_198 ( V_458 & V_462 ) > 1 ) {
V_33 = - V_398 ;
goto V_431;
}
}
if ( V_285 [ V_463 ] ) {
V_33 = F_199 ( V_36 , V_428 ,
F_200 ( V_285 [ V_463 ] ) ,
V_458 ) ;
if ( V_33 )
goto V_431;
V_430 |= V_441 ;
}
}
V_431:
if ( V_430 & V_435 ) {
if ( ( V_430 & V_441 ) == V_441 )
F_96 ( V_36 ) ;
if ( V_33 < 0 )
F_201 ( L_3 ,
V_36 -> V_94 ) ;
}
return V_33 ;
}
static int F_202 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_126 * V_127 ;
struct V_35 * V_36 ;
int V_33 ;
struct V_50 * V_376 [ V_377 + 1 ] ;
char V_429 [ V_181 ] ;
V_33 = F_155 ( V_83 , sizeof( * V_127 ) , V_376 , V_377 , V_381 ,
V_428 ) ;
if ( V_33 < 0 )
goto V_431;
if ( V_376 [ V_315 ] )
F_148 ( V_429 , V_376 [ V_315 ] , V_181 ) ;
else
V_429 [ 0 ] = '\0' ;
V_33 = - V_398 ;
V_127 = F_134 ( V_83 ) ;
if ( V_127 -> V_313 > 0 )
V_36 = F_175 ( V_34 , V_127 -> V_313 ) ;
else if ( V_376 [ V_315 ] )
V_36 = F_203 ( V_34 , V_429 ) ;
else
goto V_431;
if ( V_36 == NULL ) {
V_33 = - V_440 ;
goto V_431;
}
V_33 = F_167 ( V_36 , V_376 ) ;
if ( V_33 < 0 )
goto V_431;
V_33 = F_176 ( V_58 , V_36 , V_127 , V_428 , V_376 , V_429 , 0 ) ;
V_431:
return V_33 ;
}
static int F_204 ( const struct V_34 * V_34 , int V_75 )
{
struct V_35 * V_36 , * V_281 ;
F_38 ( V_37 ) ;
bool V_464 = false ;
if ( ! V_75 )
return - V_434 ;
F_39 (net, dev) {
if ( V_36 -> V_75 == V_75 ) {
const struct V_24 * V_26 ;
V_464 = true ;
V_26 = V_36 -> V_24 ;
if ( ! V_26 || ! V_26 -> V_29 )
return - V_197 ;
}
}
if ( ! V_464 )
return - V_440 ;
F_205 (net, dev, aux) {
if ( V_36 -> V_75 == V_75 ) {
const struct V_24 * V_26 ;
V_26 = V_36 -> V_24 ;
V_26 -> V_29 ( V_36 , & V_37 ) ;
}
}
F_40 ( & V_37 ) ;
return 0 ;
}
int F_206 ( struct V_35 * V_36 )
{
const struct V_24 * V_26 ;
F_38 ( V_37 ) ;
V_26 = V_36 -> V_24 ;
if ( ! V_26 || ! V_26 -> V_29 )
return - V_197 ;
V_26 -> V_29 ( V_36 , & V_37 ) ;
F_40 ( & V_37 ) ;
return 0 ;
}
static int F_207 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_35 * V_36 ;
struct V_126 * V_127 ;
char V_429 [ V_181 ] ;
struct V_50 * V_376 [ V_377 + 1 ] ;
int V_33 ;
V_33 = F_155 ( V_83 , sizeof( * V_127 ) , V_376 , V_377 , V_381 , V_428 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_376 [ V_315 ] )
F_148 ( V_429 , V_376 [ V_315 ] , V_181 ) ;
V_127 = F_134 ( V_83 ) ;
if ( V_127 -> V_313 > 0 )
V_36 = F_175 ( V_34 , V_127 -> V_313 ) ;
else if ( V_376 [ V_315 ] )
V_36 = F_203 ( V_34 , V_429 ) ;
else if ( V_376 [ V_324 ] )
return F_204 ( V_34 , F_156 ( V_376 [ V_324 ] ) ) ;
else
return - V_398 ;
if ( ! V_36 )
return - V_440 ;
return F_206 ( V_36 ) ;
}
int F_208 ( struct V_35 * V_36 , const struct V_126 * V_127 )
{
unsigned int V_465 ;
int V_33 ;
V_465 = V_36 -> V_14 ;
if ( V_127 && ( V_127 -> V_128 || V_127 -> V_129 ) ) {
V_33 = F_209 ( V_36 , F_98 ( V_36 , V_127 ) ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_36 -> V_466 = V_467 ;
F_210 ( V_36 , V_465 , ~ 0U ) ;
return 0 ;
}
struct V_35 * F_211 ( struct V_34 * V_34 ,
const char * V_429 , unsigned char V_468 ,
const struct V_24 * V_26 , struct V_50 * V_376 [] )
{
struct V_35 * V_36 ;
unsigned int V_328 = 1 ;
unsigned int V_334 = 1 ;
if ( V_376 [ V_327 ] )
V_328 = F_156 ( V_376 [ V_327 ] ) ;
else if ( V_26 -> V_469 )
V_328 = V_26 -> V_469 () ;
if ( V_376 [ V_333 ] )
V_334 = F_156 ( V_376 [ V_333 ] ) ;
else if ( V_26 -> V_470 )
V_334 = V_26 -> V_470 () ;
V_36 = F_212 ( V_26 -> V_471 , V_429 , V_468 ,
V_26 -> V_28 , V_328 , V_334 ) ;
if ( ! V_36 )
return F_213 ( - V_445 ) ;
F_214 ( V_36 , V_34 ) ;
V_36 -> V_24 = V_26 ;
V_36 -> V_466 = V_472 ;
if ( V_376 [ V_322 ] )
V_36 -> V_323 = F_156 ( V_376 [ V_322 ] ) ;
if ( V_376 [ V_348 ] ) {
memcpy ( V_36 -> V_349 , F_118 ( V_376 [ V_348 ] ) ,
F_168 ( V_376 [ V_348 ] ) ) ;
V_36 -> V_473 = V_474 ;
}
if ( V_376 [ V_350 ] )
memcpy ( V_36 -> V_265 , F_118 ( V_376 [ V_350 ] ) ,
F_168 ( V_376 [ V_350 ] ) ) ;
if ( V_376 [ V_316 ] )
V_36 -> V_317 = F_156 ( V_376 [ V_316 ] ) ;
if ( V_376 [ V_318 ] )
F_92 ( V_36 , F_194 ( V_376 [ V_318 ] ) ) ;
if ( V_376 [ V_320 ] )
V_36 -> V_321 = F_194 ( V_376 [ V_320 ] ) ;
if ( V_376 [ V_324 ] )
F_187 ( V_36 , F_156 ( V_376 [ V_324 ] ) ) ;
return V_36 ;
}
static int F_215 ( const struct V_2 * V_58 ,
struct V_34 * V_34 , int V_75 ,
struct V_126 * V_127 ,
struct V_393 * V_428 ,
struct V_50 * * V_376 )
{
struct V_35 * V_36 , * V_281 ;
int V_33 ;
F_205 (net, dev, aux) {
if ( V_36 -> V_75 == V_75 ) {
V_33 = F_176 ( V_58 , V_36 , V_127 , V_428 , V_376 , NULL , 0 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
return 0 ;
}
static int F_216 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
const struct V_24 * V_26 ;
const struct V_24 * V_475 = NULL ;
struct V_35 * V_36 ;
struct V_35 * V_46 = NULL ;
struct V_126 * V_127 ;
char V_25 [ V_364 ] ;
char V_429 [ V_181 ] ;
struct V_50 * V_376 [ V_377 + 1 ] ;
struct V_50 * V_71 [ V_362 + 1 ] ;
unsigned char V_468 = V_476 ;
int V_33 ;
#ifdef F_217
V_477:
#endif
V_33 = F_155 ( V_83 , sizeof( * V_127 ) , V_376 , V_377 , V_381 , V_428 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_376 [ V_315 ] )
F_148 ( V_429 , V_376 [ V_315 ] , V_181 ) ;
else
V_429 [ 0 ] = '\0' ;
V_127 = F_134 ( V_83 ) ;
if ( V_127 -> V_313 > 0 )
V_36 = F_175 ( V_34 , V_127 -> V_313 ) ;
else {
if ( V_429 [ 0 ] )
V_36 = F_203 ( V_34 , V_429 ) ;
else
V_36 = NULL ;
}
if ( V_36 ) {
V_46 = F_62 ( V_36 ) ;
if ( V_46 )
V_475 = V_46 -> V_24 ;
}
V_33 = F_167 ( V_36 , V_376 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_376 [ V_72 ] ) {
V_33 = F_147 ( V_71 , V_362 ,
V_376 [ V_72 ] , V_363 ,
NULL ) ;
if ( V_33 < 0 )
return V_33 ;
} else
memset ( V_71 , 0 , sizeof( V_71 ) ) ;
if ( V_71 [ V_66 ] ) {
F_148 ( V_25 , V_71 [ V_66 ] , sizeof( V_25 ) ) ;
V_26 = F_32 ( V_25 ) ;
} else {
V_25 [ 0 ] = '\0' ;
V_26 = NULL ;
}
if ( 1 ) {
struct V_50 * V_202 [ V_26 ? V_26 -> V_478 + 1 : 1 ] ;
struct V_50 * V_479 [ V_475 ? V_475 -> V_480 + 1 : 1 ] ;
struct V_50 * * V_65 = NULL ;
struct V_50 * * V_59 = NULL ;
struct V_34 * V_481 , * V_354 = NULL ;
if ( V_26 ) {
if ( V_26 -> V_478 && V_71 [ V_69 ] ) {
V_33 = F_147 ( V_202 , V_26 -> V_478 ,
V_71 [ V_69 ] ,
V_26 -> V_482 , NULL ) ;
if ( V_33 < 0 )
return V_33 ;
V_65 = V_202 ;
}
if ( V_26 -> V_483 ) {
V_33 = V_26 -> V_483 ( V_376 , V_65 , V_428 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
if ( V_475 ) {
if ( V_475 -> V_480 &&
V_71 [ V_63 ] ) {
V_33 = F_147 ( V_479 ,
V_475 -> V_480 ,
V_71 [ V_63 ] ,
V_475 -> V_484 ,
NULL ) ;
if ( V_33 < 0 )
return V_33 ;
V_59 = V_479 ;
}
if ( V_475 -> V_485 ) {
V_33 = V_475 -> V_485 ( V_376 , V_59 ,
V_428 ) ;
if ( V_33 < 0 )
return V_33 ;
}
}
if ( V_36 ) {
int V_430 = 0 ;
if ( V_83 -> V_486 & V_487 )
return - V_27 ;
if ( V_83 -> V_486 & V_488 )
return - V_197 ;
if ( V_71 [ V_69 ] ) {
if ( ! V_26 || V_26 != V_36 -> V_24 ||
! V_26 -> V_489 )
return - V_197 ;
V_33 = V_26 -> V_489 ( V_36 , V_376 , V_65 , V_428 ) ;
if ( V_33 < 0 )
return V_33 ;
V_430 |= V_441 ;
}
if ( V_71 [ V_63 ] ) {
if ( ! V_475 || ! V_475 -> V_490 )
return - V_197 ;
V_33 = V_475 -> V_490 ( V_46 , V_36 ,
V_376 , V_59 ,
V_428 ) ;
if ( V_33 < 0 )
return V_33 ;
V_430 |= V_441 ;
}
return F_176 ( V_58 , V_36 , V_127 , V_428 , V_376 , V_429 ,
V_430 ) ;
}
if ( ! ( V_83 -> V_486 & V_491 ) ) {
if ( V_127 -> V_313 == 0 && V_376 [ V_324 ] )
return F_215 ( V_58 , V_34 ,
F_156 ( V_376 [ V_324 ] ) ,
V_127 , V_428 , V_376 ) ;
return - V_440 ;
}
if ( V_376 [ V_275 ] || V_376 [ V_492 ] )
return - V_197 ;
if ( ! V_26 ) {
#ifdef F_217
if ( V_25 [ 0 ] ) {
F_4 () ;
F_218 ( L_4 , V_25 ) ;
F_1 () ;
V_26 = F_32 ( V_25 ) ;
if ( V_26 )
goto V_477;
}
#endif
return - V_197 ;
}
if ( ! V_26 -> V_28 )
return - V_197 ;
if ( ! V_429 [ 0 ] ) {
snprintf ( V_429 , V_181 , L_5 , V_26 -> V_25 ) ;
V_468 = V_493 ;
}
V_481 = F_163 ( V_34 , V_376 ) ;
if ( F_177 ( V_481 ) )
return F_178 ( V_481 ) ;
V_33 = - V_434 ;
if ( ! F_179 ( V_58 , V_481 -> V_432 , V_433 ) )
goto V_48;
if ( V_376 [ V_355 ] ) {
int V_102 = F_200 ( V_376 [ V_355 ] ) ;
V_354 = F_219 ( V_481 , V_102 ) ;
if ( ! V_354 ) {
V_33 = - V_398 ;
goto V_48;
}
V_33 = - V_434 ;
if ( ! F_179 ( V_58 , V_354 -> V_432 , V_433 ) )
goto V_48;
}
V_36 = F_211 ( V_354 ? : V_481 , V_429 ,
V_468 , V_26 , V_376 ) ;
if ( F_177 ( V_36 ) ) {
V_33 = F_178 ( V_36 ) ;
goto V_48;
}
V_36 -> V_314 = V_127 -> V_313 ;
if ( V_26 -> V_494 ) {
V_33 = V_26 -> V_494 ( V_354 ? : V_34 , V_36 , V_376 , V_65 ,
V_428 ) ;
if ( V_33 < 0 ) {
if ( V_36 -> V_495 == V_496 )
F_220 ( V_36 ) ;
goto V_48;
}
} else {
V_33 = F_221 ( V_36 ) ;
if ( V_33 < 0 ) {
F_220 ( V_36 ) ;
goto V_48;
}
}
V_33 = F_208 ( V_36 , V_127 ) ;
if ( V_33 < 0 )
goto V_497;
if ( V_354 ) {
V_33 = F_181 ( V_36 , V_481 , V_429 ) ;
if ( V_33 < 0 )
goto V_497;
}
if ( V_376 [ V_336 ] ) {
V_33 = F_174 ( V_36 , F_156 ( V_376 [ V_336 ] ) ) ;
if ( V_33 )
goto V_497;
}
V_48:
if ( V_354 )
F_180 ( V_354 ) ;
F_180 ( V_481 ) ;
return V_33 ;
V_497:
if ( V_26 -> V_494 ) {
F_38 ( V_37 ) ;
V_26 -> V_29 ( V_36 , & V_37 ) ;
F_40 ( & V_37 ) ;
} else {
F_222 ( V_36 ) ;
}
goto V_48;
}
}
static int F_223 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_126 * V_127 ;
char V_429 [ V_181 ] ;
struct V_50 * V_376 [ V_377 + 1 ] ;
struct V_35 * V_36 = NULL ;
struct V_2 * V_498 ;
int V_33 ;
T_4 V_55 = 0 ;
V_33 = F_155 ( V_83 , sizeof( * V_127 ) , V_376 , V_377 , V_381 , V_428 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_376 [ V_315 ] )
F_148 ( V_429 , V_376 [ V_315 ] , V_181 ) ;
if ( V_376 [ V_382 ] )
V_55 = F_156 ( V_376 [ V_382 ] ) ;
V_127 = F_134 ( V_83 ) ;
if ( V_127 -> V_313 > 0 )
V_36 = F_175 ( V_34 , V_127 -> V_313 ) ;
else if ( V_376 [ V_315 ] )
V_36 = F_203 ( V_34 , V_429 ) ;
else
return - V_398 ;
if ( V_36 == NULL )
return - V_440 ;
V_498 = F_224 ( F_105 ( V_36 , V_55 ) , V_19 ) ;
if ( V_498 == NULL )
return - V_20 ;
V_33 = F_132 ( V_498 , V_36 , V_387 , F_71 ( V_58 ) . V_388 ,
V_83 -> V_389 , 0 , 0 , V_55 , 0 ) ;
if ( V_33 < 0 ) {
F_225 ( V_33 == - V_61 ) ;
F_6 ( V_498 ) ;
} else
V_33 = F_75 ( V_498 , V_34 , F_71 ( V_58 ) . V_388 ) ;
return V_33 ;
}
static T_9 F_226 ( struct V_2 * V_58 , struct V_82 * V_83 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_35 * V_36 ;
struct V_50 * V_376 [ V_377 + 1 ] ;
T_4 V_55 = 0 ;
T_9 V_499 = 0 ;
int V_379 ;
V_379 = F_154 ( V_83 ) < sizeof( struct V_126 ) ?
sizeof( struct V_380 ) : sizeof( struct V_126 ) ;
if ( F_155 ( V_83 , V_379 , V_376 , V_377 , V_381 , NULL ) >= 0 ) {
if ( V_376 [ V_382 ] )
V_55 = F_156 ( V_376 [ V_382 ] ) ;
}
if ( ! V_55 )
return V_500 ;
F_51 () ;
F_227 (net, dev) {
V_499 = F_183 ( T_9 , V_499 ,
F_105 ( V_36 ,
V_55 ) ) ;
}
F_54 () ;
return F_228 ( V_499 ) ;
}
static int F_229 ( struct V_2 * V_58 , struct V_368 * V_369 )
{
int V_373 ;
int V_374 = V_369 -> V_54 ;
if ( V_374 == 0 )
V_374 = 1 ;
for ( V_373 = 1 ; V_373 <= V_17 ; V_373 ++ ) {
int type = V_369 -> V_83 -> V_501 - V_9 ;
struct V_15 * V_21 ;
T_2 V_13 ;
if ( V_373 < V_374 || V_373 == V_502 )
continue;
V_21 = F_25 ( V_18 [ V_373 ] ) ;
if ( ! V_21 )
continue;
V_13 = F_230 ( V_21 [ type ] . V_13 ) ;
if ( ! V_13 )
continue;
if ( V_373 > V_374 ) {
memset ( & V_369 -> args [ 0 ] , 0 , sizeof( V_369 -> args ) ) ;
V_369 -> V_503 = 0 ;
V_369 -> V_305 = 0 ;
}
if ( V_13 ( V_58 , V_369 ) )
break;
}
V_369 -> V_54 = V_373 ;
return V_58 -> V_390 ;
}
struct V_2 * F_231 ( int type , struct V_35 * V_36 ,
unsigned int V_306 ,
T_4 V_290 , T_5 V_14 )
{
struct V_34 * V_34 = F_141 ( V_36 ) ;
struct V_2 * V_58 ;
int V_33 = - V_20 ;
T_3 V_504 ;
V_58 = F_224 ( ( V_504 = F_105 ( V_36 , 0 ) ) , V_14 ) ;
if ( V_58 == NULL )
goto V_431;
V_33 = F_132 ( V_58 , V_36 , type , 0 , 0 , V_306 , 0 , 0 , V_290 ) ;
if ( V_33 < 0 ) {
F_225 ( V_33 == - V_61 ) ;
F_6 ( V_58 ) ;
goto V_431;
}
return V_58 ;
V_431:
if ( V_33 < 0 )
F_80 ( V_34 , V_505 , V_33 ) ;
return NULL ;
}
void F_232 ( struct V_2 * V_58 , struct V_35 * V_36 , T_5 V_14 )
{
struct V_34 * V_34 = F_141 ( V_36 ) ;
F_77 ( V_58 , V_34 , 0 , V_505 , NULL , V_14 ) ;
}
static void F_233 ( int type , struct V_35 * V_36 ,
unsigned int V_306 , T_4 V_290 ,
T_5 V_14 )
{
struct V_2 * V_58 ;
if ( V_36 -> V_495 != V_506 )
return;
V_58 = F_231 ( type , V_36 , V_306 , V_290 , V_14 ) ;
if ( V_58 )
F_232 ( V_58 , V_36 , V_14 ) ;
}
void F_234 ( int type , struct V_35 * V_36 , unsigned int V_306 ,
T_5 V_14 )
{
F_233 ( type , V_36 , V_306 , F_131 ( 0 ) , V_14 ) ;
}
static int F_235 ( struct V_2 * V_58 ,
struct V_35 * V_36 ,
T_8 * V_507 , T_9 V_508 , T_4 V_74 , T_4 V_305 ,
int type , unsigned int V_14 ,
int V_509 , T_9 V_510 )
{
struct V_82 * V_83 ;
struct V_511 * V_512 ;
V_83 = F_133 ( V_58 , V_74 , V_305 , type , sizeof( * V_512 ) , V_509 ) ;
if ( ! V_83 )
return - V_61 ;
V_512 = F_134 ( V_83 ) ;
V_512 -> V_513 = V_514 ;
V_512 -> V_515 = 0 ;
V_512 -> V_516 = 0 ;
V_512 -> V_517 = V_14 ;
V_512 -> V_518 = 0 ;
V_512 -> V_519 = V_36 -> V_314 ;
V_512 -> V_510 = V_510 ;
if ( F_91 ( V_58 , V_520 , V_521 , V_507 ) )
goto V_95;
if ( V_508 )
if ( F_91 ( V_58 , V_522 , sizeof( T_9 ) , & V_508 ) )
goto V_95;
F_144 ( V_58 , V_83 ) ;
return 0 ;
V_95:
F_145 ( V_58 , V_83 ) ;
return - V_61 ;
}
static inline T_3 F_236 ( void )
{
return F_106 ( sizeof( struct V_511 ) ) +
F_53 ( V_521 ) +
F_53 ( sizeof( T_9 ) ) +
0 ;
}
static void F_237 ( struct V_35 * V_36 , T_8 * V_507 , T_9 V_508 , int type ,
T_9 V_510 )
{
struct V_34 * V_34 = F_141 ( V_36 ) ;
struct V_2 * V_58 ;
int V_33 = - V_20 ;
V_58 = F_224 ( F_236 () , V_523 ) ;
if ( ! V_58 )
goto V_431;
V_33 = F_235 ( V_58 , V_36 , V_507 , V_508 ,
0 , 0 , type , V_524 , 0 , V_510 ) ;
if ( V_33 < 0 ) {
F_6 ( V_58 ) ;
goto V_431;
}
F_77 ( V_58 , V_34 , 0 , V_525 , NULL , V_523 ) ;
return;
V_431:
F_80 ( V_34 , V_525 , V_33 ) ;
}
int F_238 ( struct V_511 * V_512 ,
struct V_50 * V_376 [] ,
struct V_35 * V_36 ,
const unsigned char * V_507 , T_9 V_508 ,
T_9 V_14 )
{
int V_33 = - V_398 ;
if ( V_512 -> V_510 && ! ( V_512 -> V_510 & V_526 ) ) {
F_239 ( L_6 , V_36 -> V_94 ) ;
return V_33 ;
}
if ( V_508 ) {
F_239 ( L_7 , V_36 -> V_94 ) ;
return V_33 ;
}
if ( F_240 ( V_507 ) || F_241 ( V_507 ) )
V_33 = F_242 ( V_36 , V_507 ) ;
else if ( F_243 ( V_507 ) )
V_33 = F_244 ( V_36 , V_507 ) ;
if ( V_33 == - V_27 && ! ( V_14 & V_487 ) )
V_33 = 0 ;
return V_33 ;
}
static int F_245 ( struct V_50 * V_527 , T_9 * V_528 )
{
T_9 V_508 = 0 ;
if ( V_527 ) {
if ( F_168 ( V_527 ) != sizeof( T_9 ) ) {
F_239 ( L_8 ) ;
return - V_398 ;
}
V_508 = F_246 ( V_527 ) ;
if ( ! V_508 || V_508 >= V_529 ) {
F_239 ( L_9 ,
V_508 ) ;
return - V_398 ;
}
}
* V_528 = V_508 ;
return 0 ;
}
static int F_247 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_511 * V_512 ;
struct V_50 * V_376 [ V_530 + 1 ] ;
struct V_35 * V_36 ;
T_8 * V_507 ;
T_9 V_508 ;
int V_33 ;
V_33 = F_155 ( V_83 , sizeof( * V_512 ) , V_376 , V_530 , NULL , V_428 ) ;
if ( V_33 < 0 )
return V_33 ;
V_512 = F_134 ( V_83 ) ;
if ( V_512 -> V_519 == 0 ) {
F_239 ( L_10 ) ;
return - V_398 ;
}
V_36 = F_175 ( V_34 , V_512 -> V_519 ) ;
if ( V_36 == NULL ) {
F_239 ( L_11 ) ;
return - V_440 ;
}
if ( ! V_376 [ V_520 ] || F_168 ( V_376 [ V_520 ] ) != V_521 ) {
F_239 ( L_12 ) ;
return - V_398 ;
}
V_507 = F_118 ( V_376 [ V_520 ] ) ;
V_33 = F_245 ( V_376 [ V_522 ] , & V_508 ) ;
if ( V_33 )
return V_33 ;
V_33 = - V_197 ;
if ( ( ! V_512 -> V_517 || V_512 -> V_517 & V_531 ) &&
( V_36 -> V_532 & V_533 ) ) {
struct V_35 * V_534 = F_62 ( V_36 ) ;
const struct V_277 * V_26 = V_534 -> V_178 ;
V_33 = V_26 -> V_535 ( V_512 , V_376 , V_36 , V_507 , V_508 ,
V_83 -> V_486 ) ;
if ( V_33 )
goto V_48;
else
V_512 -> V_517 &= ~ V_531 ;
}
if ( ( V_512 -> V_517 & V_524 ) ) {
if ( V_36 -> V_178 -> V_535 )
V_33 = V_36 -> V_178 -> V_535 ( V_512 , V_376 , V_36 , V_507 ,
V_508 ,
V_83 -> V_486 ) ;
else
V_33 = F_238 ( V_512 , V_376 , V_36 , V_507 , V_508 ,
V_83 -> V_486 ) ;
if ( ! V_33 ) {
F_237 ( V_36 , V_507 , V_508 , V_536 ,
V_512 -> V_510 ) ;
V_512 -> V_517 &= ~ V_524 ;
}
}
V_48:
return V_33 ;
}
int F_248 ( struct V_511 * V_512 ,
struct V_50 * V_376 [] ,
struct V_35 * V_36 ,
const unsigned char * V_507 , T_9 V_508 )
{
int V_33 = - V_398 ;
if ( ! ( V_512 -> V_510 & V_526 ) ) {
F_239 ( L_6 , V_36 -> V_94 ) ;
return V_33 ;
}
if ( F_240 ( V_507 ) || F_241 ( V_507 ) )
V_33 = F_249 ( V_36 , V_507 ) ;
else if ( F_243 ( V_507 ) )
V_33 = F_250 ( V_36 , V_507 ) ;
return V_33 ;
}
static int F_251 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_511 * V_512 ;
struct V_50 * V_376 [ V_530 + 1 ] ;
struct V_35 * V_36 ;
int V_33 = - V_398 ;
T_10 * V_507 ;
T_9 V_508 ;
if ( ! F_252 ( V_58 , V_433 ) )
return - V_434 ;
V_33 = F_155 ( V_83 , sizeof( * V_512 ) , V_376 , V_530 , NULL , V_428 ) ;
if ( V_33 < 0 )
return V_33 ;
V_512 = F_134 ( V_83 ) ;
if ( V_512 -> V_519 == 0 ) {
F_239 ( L_13 ) ;
return - V_398 ;
}
V_36 = F_175 ( V_34 , V_512 -> V_519 ) ;
if ( V_36 == NULL ) {
F_239 ( L_14 ) ;
return - V_440 ;
}
if ( ! V_376 [ V_520 ] || F_168 ( V_376 [ V_520 ] ) != V_521 ) {
F_239 ( L_15 ) ;
return - V_398 ;
}
V_507 = F_118 ( V_376 [ V_520 ] ) ;
V_33 = F_245 ( V_376 [ V_522 ] , & V_508 ) ;
if ( V_33 )
return V_33 ;
V_33 = - V_197 ;
if ( ( ! V_512 -> V_517 || V_512 -> V_517 & V_531 ) &&
( V_36 -> V_532 & V_533 ) ) {
struct V_35 * V_534 = F_62 ( V_36 ) ;
const struct V_277 * V_26 = V_534 -> V_178 ;
if ( V_26 -> V_537 )
V_33 = V_26 -> V_537 ( V_512 , V_376 , V_36 , V_507 , V_508 ) ;
if ( V_33 )
goto V_48;
else
V_512 -> V_517 &= ~ V_531 ;
}
if ( V_512 -> V_517 & V_524 ) {
if ( V_36 -> V_178 -> V_537 )
V_33 = V_36 -> V_178 -> V_537 ( V_512 , V_376 , V_36 , V_507 ,
V_508 ) ;
else
V_33 = F_248 ( V_512 , V_376 , V_36 , V_507 , V_508 ) ;
if ( ! V_33 ) {
F_237 ( V_36 , V_507 , V_508 , V_538 ,
V_512 -> V_510 ) ;
V_512 -> V_517 &= ~ V_524 ;
}
}
V_48:
return V_33 ;
}
static int F_253 ( struct V_2 * V_58 ,
struct V_368 * V_369 ,
struct V_35 * V_36 ,
int * V_373 ,
struct V_539 * V_31 )
{
struct V_540 * V_541 ;
int V_33 ;
T_4 V_388 , V_305 ;
V_388 = F_71 ( V_369 -> V_58 ) . V_388 ;
V_305 = V_369 -> V_83 -> V_389 ;
F_33 (ha, &list->list, list) {
if ( * V_373 < V_369 -> args [ 2 ] )
goto V_542;
V_33 = F_235 ( V_58 , V_36 , V_541 -> V_507 , 0 ,
V_388 , V_305 ,
V_536 , V_524 ,
V_378 , V_526 ) ;
if ( V_33 < 0 )
return V_33 ;
V_542:
* V_373 += 1 ;
}
return 0 ;
}
int F_254 ( struct V_2 * V_58 ,
struct V_368 * V_369 ,
struct V_35 * V_36 ,
struct V_35 * V_543 ,
int * V_373 )
{
int V_33 ;
F_255 ( V_36 ) ;
V_33 = F_253 ( V_58 , V_369 , V_36 , V_373 , & V_36 -> V_544 ) ;
if ( V_33 )
goto V_48;
V_33 = F_253 ( V_58 , V_369 , V_36 , V_373 , & V_36 -> V_545 ) ;
V_48:
F_256 ( V_36 ) ;
return V_33 ;
}
static int F_257 ( struct V_2 * V_58 , struct V_368 * V_369 )
{
struct V_35 * V_36 ;
struct V_50 * V_376 [ V_377 + 1 ] ;
struct V_35 * V_534 = NULL ;
const struct V_277 * V_26 = NULL ;
const struct V_277 * V_546 = NULL ;
struct V_126 * V_127 = F_134 ( V_369 -> V_83 ) ;
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_375 * V_3 ;
int V_547 = 0 ;
int V_548 = 0 ;
int V_371 , V_372 ;
int V_373 = 0 , V_374 ;
int V_33 = 0 ;
int V_549 = 0 ;
V_33 = F_155 ( V_369 -> V_83 , sizeof( struct V_126 ) , V_376 ,
V_377 , V_381 , NULL ) ;
if ( V_33 < 0 ) {
return - V_398 ;
} else if ( V_33 == 0 ) {
if ( V_376 [ V_336 ] )
V_548 = F_156 ( V_376 [ V_336 ] ) ;
}
V_547 = V_127 -> V_313 ;
if ( V_548 ) {
V_534 = F_175 ( V_34 , V_548 ) ;
if ( ! V_534 )
return - V_440 ;
V_26 = V_534 -> V_178 ;
}
V_372 = V_369 -> args [ 0 ] ;
V_374 = V_369 -> args [ 1 ] ;
for ( V_371 = V_372 ; V_371 < V_384 ; V_371 ++ , V_374 = 0 ) {
V_373 = 0 ;
V_3 = & V_34 -> V_385 [ V_371 ] ;
F_157 (dev, head, index_hlist) {
if ( V_547 && ( V_36 -> V_314 != V_547 ) )
continue;
if ( ! V_548 ) {
if ( V_36 -> V_532 & V_533 ) {
V_534 = F_62 ( V_36 ) ;
V_546 = V_534 -> V_178 ;
}
} else {
if ( V_36 != V_534 &&
! ( V_36 -> V_532 & V_533 ) )
continue;
if ( V_534 != F_62 ( V_36 ) &&
! ( V_36 -> V_532 & V_550 ) )
continue;
V_546 = V_26 ;
}
if ( V_373 < V_374 )
goto V_386;
if ( V_36 -> V_532 & V_533 ) {
if ( V_546 && V_546 -> V_551 ) {
V_33 = V_546 -> V_551 ( V_58 , V_369 ,
V_534 , V_36 ,
& V_549 ) ;
if ( V_33 == - V_61 )
goto V_48;
}
}
if ( V_36 -> V_178 -> V_551 )
V_33 = V_36 -> V_178 -> V_551 ( V_58 , V_369 ,
V_36 , NULL ,
& V_549 ) ;
else
V_33 = F_254 ( V_58 , V_369 , V_36 , NULL ,
& V_549 ) ;
if ( V_33 == - V_61 )
goto V_48;
V_546 = NULL ;
V_369 -> args [ 2 ] = 0 ;
V_549 = 0 ;
V_386:
V_373 ++ ;
}
}
V_48:
V_369 -> args [ 0 ] = V_371 ;
V_369 -> args [ 1 ] = V_373 ;
V_369 -> args [ 2 ] = V_549 ;
return V_58 -> V_390 ;
}
static int F_258 ( struct V_2 * V_58 , T_4 V_14 , T_4 V_552 ,
unsigned int V_553 , unsigned int V_554 )
{
if ( V_552 & V_554 )
return F_130 ( V_58 , V_553 , ! ! ( V_14 & V_554 ) ) ;
return 0 ;
}
int F_259 ( struct V_2 * V_58 , T_4 V_74 , T_4 V_305 ,
struct V_35 * V_36 , T_9 V_555 ,
T_4 V_14 , T_4 V_552 , int V_509 ,
T_4 V_556 ,
int (* F_260)( struct V_2 * V_58 ,
struct V_35 * V_36 ,
T_4 V_556 ) )
{
struct V_82 * V_83 ;
struct V_126 * V_127 ;
struct V_50 * V_557 ;
struct V_50 * V_558 ;
T_8 V_118 = F_136 ( V_36 ) ? V_36 -> V_118 : V_319 ;
struct V_35 * V_534 = F_62 ( V_36 ) ;
int V_33 = 0 ;
V_83 = F_133 ( V_58 , V_74 , V_305 , V_387 , sizeof( * V_127 ) , V_509 ) ;
if ( V_83 == NULL )
return - V_61 ;
V_127 = F_134 ( V_83 ) ;
V_127 -> V_309 = V_514 ;
V_127 -> V_311 = 0 ;
V_127 -> V_312 = V_36 -> type ;
V_127 -> V_313 = V_36 -> V_314 ;
V_127 -> V_128 = F_135 ( V_36 ) ;
V_127 -> V_129 = 0 ;
if ( F_64 ( V_58 , V_315 , V_36 -> V_94 ) ||
F_85 ( V_58 , V_322 , V_36 -> V_323 ) ||
F_130 ( V_58 , V_318 , V_118 ) ||
( V_534 &&
F_85 ( V_58 , V_336 , V_534 -> V_314 ) ) ||
( V_36 -> V_347 &&
F_91 ( V_58 , V_348 , V_36 -> V_347 , V_36 -> V_349 ) ) ||
( V_36 -> V_314 != F_138 ( V_36 ) &&
F_85 ( V_58 , V_335 , F_138 ( V_36 ) ) ) )
goto V_95;
V_557 = F_65 ( V_58 , V_356 ) ;
if ( ! V_557 )
goto V_95;
if ( F_261 ( V_58 , V_559 , V_560 ) ) {
F_67 ( V_58 , V_557 ) ;
goto V_95;
}
if ( V_555 != V_561 ) {
if ( F_261 ( V_58 , V_562 , V_555 ) ) {
F_67 ( V_58 , V_557 ) ;
goto V_95;
}
}
if ( F_260 ) {
V_33 = F_260 ( V_58 , V_36 , V_556 ) ;
if ( V_33 ) {
F_67 ( V_58 , V_557 ) ;
goto V_95;
}
}
F_66 ( V_58 , V_557 ) ;
V_558 = F_65 ( V_58 , V_492 | V_563 ) ;
if ( ! V_558 )
goto V_95;
if ( F_258 ( V_58 , V_14 , V_552 ,
V_564 , V_565 ) ||
F_258 ( V_58 , V_14 , V_552 ,
V_566 , V_567 ) ||
F_258 ( V_58 , V_14 , V_552 ,
V_568 ,
V_569 ) ||
F_258 ( V_58 , V_14 , V_552 ,
V_570 , V_571 ) ||
F_258 ( V_58 , V_14 , V_552 ,
V_572 , V_573 ) ||
F_258 ( V_58 , V_14 , V_552 ,
V_574 , V_575 ) ||
F_258 ( V_58 , V_14 , V_552 ,
V_576 , V_577 ) ||
F_258 ( V_58 , V_14 , V_552 ,
V_578 , V_579 ) ) {
F_67 ( V_58 , V_558 ) ;
goto V_95;
}
F_66 ( V_58 , V_558 ) ;
F_144 ( V_58 , V_83 ) ;
return 0 ;
V_95:
F_145 ( V_58 , V_83 ) ;
return V_33 ? V_33 : - V_61 ;
}
static int F_262 ( struct V_2 * V_58 , struct V_368 * V_369 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_35 * V_36 ;
int V_373 = 0 ;
T_4 V_388 = F_71 ( V_369 -> V_58 ) . V_388 ;
T_4 V_305 = V_369 -> V_83 -> V_389 ;
T_4 V_556 = 0 ;
int V_33 ;
if ( F_154 ( V_369 -> V_83 ) > sizeof( struct V_126 ) ) {
struct V_50 * V_580 ;
V_580 = F_263 ( V_369 -> V_83 , sizeof( struct V_126 ) ,
V_382 ) ;
if ( V_580 ) {
if ( F_168 ( V_580 ) < sizeof( V_556 ) )
return - V_398 ;
V_556 = F_156 ( V_580 ) ;
}
}
F_51 () ;
F_227 (net, dev) {
const struct V_277 * V_26 = V_36 -> V_178 ;
struct V_35 * V_534 = F_62 ( V_36 ) ;
if ( V_534 && V_534 -> V_178 -> V_581 ) {
if ( V_373 >= V_369 -> args [ 0 ] ) {
V_33 = V_534 -> V_178 -> V_581 (
V_58 , V_388 , V_305 , V_36 ,
V_556 , V_378 ) ;
if ( V_33 < 0 && V_33 != - V_197 ) {
if ( F_158 ( V_58 -> V_390 ) )
break;
goto V_391;
}
}
V_373 ++ ;
}
if ( V_26 -> V_581 ) {
if ( V_373 >= V_369 -> args [ 0 ] ) {
V_33 = V_26 -> V_581 ( V_58 , V_388 ,
V_305 , V_36 ,
V_556 ,
V_378 ) ;
if ( V_33 < 0 && V_33 != - V_197 ) {
if ( F_158 ( V_58 -> V_390 ) )
break;
goto V_391;
}
}
V_373 ++ ;
}
}
V_33 = V_58 -> V_390 ;
V_391:
F_54 () ;
V_369 -> args [ 0 ] = V_373 ;
return V_33 ;
}
static inline T_3 F_264 ( void )
{
return F_106 ( sizeof( struct V_126 ) )
+ F_53 ( V_181 )
+ F_53 ( V_184 )
+ F_53 ( sizeof( T_4 ) )
+ F_53 ( sizeof( T_4 ) )
+ F_53 ( sizeof( T_4 ) )
+ F_53 ( sizeof( T_4 ) )
+ F_53 ( sizeof( T_8 ) )
+ F_53 ( sizeof( struct V_50 ) )
+ F_53 ( sizeof( T_9 ) )
+ F_53 ( sizeof( T_9 ) ) ;
}
static int F_265 ( struct V_35 * V_36 )
{
struct V_34 * V_34 = F_141 ( V_36 ) ;
struct V_2 * V_58 ;
int V_33 = - V_197 ;
if ( ! V_36 -> V_178 -> V_581 )
return 0 ;
V_58 = F_224 ( F_264 () , V_523 ) ;
if ( ! V_58 ) {
V_33 = - V_445 ;
goto V_431;
}
V_33 = V_36 -> V_178 -> V_581 ( V_58 , 0 , 0 , V_36 , 0 , 0 ) ;
if ( V_33 < 0 )
goto V_431;
if ( ! V_58 -> V_390 )
goto V_431;
F_77 ( V_58 , V_34 , 0 , V_505 , NULL , V_523 ) ;
return 0 ;
V_431:
F_225 ( V_33 == - V_61 ) ;
F_6 ( V_58 ) ;
if ( V_33 )
F_80 ( V_34 , V_505 , V_33 ) ;
return V_33 ;
}
static int F_266 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_126 * V_127 ;
struct V_35 * V_36 ;
struct V_50 * V_582 , * V_202 = NULL ;
int V_399 , V_33 = - V_197 ;
T_9 V_14 = 0 ;
bool V_583 = false ;
if ( F_154 ( V_83 ) < sizeof( * V_127 ) )
return - V_398 ;
V_127 = F_134 ( V_83 ) ;
if ( V_127 -> V_309 != V_514 )
return - V_584 ;
V_36 = F_175 ( V_34 , V_127 -> V_313 ) ;
if ( ! V_36 ) {
F_239 ( L_16 ) ;
return - V_440 ;
}
V_582 = F_263 ( V_83 , sizeof( struct V_126 ) , V_356 ) ;
if ( V_582 ) {
F_169 (attr, br_spec, rem) {
if ( F_170 ( V_202 ) == V_559 ) {
if ( F_168 ( V_202 ) < sizeof( V_14 ) )
return - V_398 ;
V_583 = true ;
V_14 = F_246 ( V_202 ) ;
break;
}
}
}
if ( ! V_14 || ( V_14 & V_585 ) ) {
struct V_35 * V_534 = F_62 ( V_36 ) ;
if ( ! V_534 || ! V_534 -> V_178 -> V_586 ) {
V_33 = - V_197 ;
goto V_48;
}
V_33 = V_534 -> V_178 -> V_586 ( V_36 , V_83 , V_14 ) ;
if ( V_33 )
goto V_48;
V_14 &= ~ V_585 ;
}
if ( ( V_14 & V_560 ) ) {
if ( ! V_36 -> V_178 -> V_586 )
V_33 = - V_197 ;
else
V_33 = V_36 -> V_178 -> V_586 ( V_36 , V_83 ,
V_14 ) ;
if ( ! V_33 ) {
V_14 &= ~ V_560 ;
V_33 = F_265 ( V_36 ) ;
}
}
if ( V_583 )
memcpy ( F_118 ( V_202 ) , & V_14 , sizeof( V_14 ) ) ;
V_48:
return V_33 ;
}
static int F_267 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_126 * V_127 ;
struct V_35 * V_36 ;
struct V_50 * V_582 , * V_202 = NULL ;
int V_399 , V_33 = - V_197 ;
T_9 V_14 = 0 ;
bool V_583 = false ;
if ( F_154 ( V_83 ) < sizeof( * V_127 ) )
return - V_398 ;
V_127 = F_134 ( V_83 ) ;
if ( V_127 -> V_309 != V_514 )
return - V_584 ;
V_36 = F_175 ( V_34 , V_127 -> V_313 ) ;
if ( ! V_36 ) {
F_239 ( L_16 ) ;
return - V_440 ;
}
V_582 = F_263 ( V_83 , sizeof( struct V_126 ) , V_356 ) ;
if ( V_582 ) {
F_169 (attr, br_spec, rem) {
if ( F_170 ( V_202 ) == V_559 ) {
if ( F_168 ( V_202 ) < sizeof( V_14 ) )
return - V_398 ;
V_583 = true ;
V_14 = F_246 ( V_202 ) ;
break;
}
}
}
if ( ! V_14 || ( V_14 & V_585 ) ) {
struct V_35 * V_534 = F_62 ( V_36 ) ;
if ( ! V_534 || ! V_534 -> V_178 -> V_587 ) {
V_33 = - V_197 ;
goto V_48;
}
V_33 = V_534 -> V_178 -> V_587 ( V_36 , V_83 , V_14 ) ;
if ( V_33 )
goto V_48;
V_14 &= ~ V_585 ;
}
if ( ( V_14 & V_560 ) ) {
if ( ! V_36 -> V_178 -> V_587 )
V_33 = - V_197 ;
else
V_33 = V_36 -> V_178 -> V_587 ( V_36 , V_83 ,
V_14 ) ;
if ( ! V_33 ) {
V_14 &= ~ V_560 ;
V_33 = F_265 ( V_36 ) ;
}
}
if ( V_583 )
memcpy ( F_118 ( V_202 ) , & V_14 , sizeof( V_14 ) ) ;
V_48:
return V_33 ;
}
static bool F_268 ( unsigned int V_552 , int V_588 , int V_589 )
{
return ( V_552 & F_269 ( V_588 ) ) &&
( ! V_589 || V_589 == V_588 ) ;
}
static int F_270 ( int V_590 )
{
switch ( V_590 ) {
case V_591 :
return sizeof( struct V_132 ) ;
}
return 0 ;
}
static int F_271 ( struct V_2 * V_58 , struct V_35 * V_36 ,
int * V_592 )
{
struct V_50 * V_202 = NULL ;
int V_590 , V_47 ;
void * V_593 ;
int V_33 ;
if ( ! ( V_36 -> V_178 && V_36 -> V_178 -> V_594 &&
V_36 -> V_178 -> V_595 ) )
return - V_359 ;
for ( V_590 = V_596 ;
V_590 <= V_597 ; V_590 ++ ) {
if ( V_590 < * V_592 )
continue;
V_47 = F_270 ( V_590 ) ;
if ( ! V_47 )
continue;
if ( ! V_36 -> V_178 -> V_594 ( V_36 , V_590 ) )
continue;
V_202 = F_117 ( V_58 , V_590 , V_47 ,
V_598 ) ;
if ( ! V_202 )
goto V_95;
V_593 = F_118 ( V_202 ) ;
memset ( V_593 , 0 , V_47 ) ;
V_33 = V_36 -> V_178 -> V_595 ( V_590 , V_36 ,
V_593 ) ;
if ( V_33 )
goto V_599;
}
if ( ! V_202 )
return - V_359 ;
* V_592 = 0 ;
return 0 ;
V_95:
V_33 = - V_61 ;
V_599:
* V_592 = V_590 ;
return V_33 ;
}
static int F_272 ( const struct V_35 * V_36 )
{
int V_600 = 0 ;
int V_590 ;
int V_47 ;
if ( ! ( V_36 -> V_178 && V_36 -> V_178 -> V_594 &&
V_36 -> V_178 -> V_595 ) )
return 0 ;
for ( V_590 = V_596 ;
V_590 <= V_597 ; V_590 ++ ) {
if ( ! V_36 -> V_178 -> V_594 ( V_36 , V_590 ) )
continue;
V_47 = F_270 ( V_590 ) ;
V_600 += F_102 ( V_47 ) ;
}
if ( V_600 != 0 )
V_600 += F_53 ( 0 ) ;
return V_600 ;
}
static int F_273 ( struct V_2 * V_58 , struct V_35 * V_36 ,
int type , T_4 V_74 , T_4 V_305 , T_4 V_306 ,
unsigned int V_14 , unsigned int V_556 ,
int * V_589 , int * V_592 )
{
struct V_601 * V_602 ;
struct V_82 * V_83 ;
struct V_50 * V_202 ;
int V_603 = * V_592 ;
int V_33 ;
F_127 () ;
V_83 = F_133 ( V_58 , V_74 , V_305 , type , sizeof( * V_602 ) , V_14 ) ;
if ( ! V_83 )
return - V_61 ;
V_602 = F_134 ( V_83 ) ;
V_602 -> V_54 = V_604 ;
V_602 -> V_605 = 0 ;
V_602 -> V_606 = 0 ;
V_602 -> V_314 = V_36 -> V_314 ;
V_602 -> V_556 = V_556 ;
if ( F_268 ( V_556 , V_607 , * V_589 ) ) {
struct V_132 * V_208 ;
V_202 = F_117 ( V_58 , V_607 ,
sizeof( struct V_132 ) ,
V_608 ) ;
if ( ! V_202 )
goto V_95;
V_208 = F_118 ( V_202 ) ;
F_119 ( V_36 , V_208 ) ;
}
if ( F_268 ( V_556 , V_609 , * V_589 ) ) {
const struct V_24 * V_26 = V_36 -> V_24 ;
if ( V_26 && V_26 -> V_610 ) {
* V_589 = V_609 ;
V_202 = F_65 ( V_58 ,
V_609 ) ;
if ( ! V_202 )
goto V_95;
V_33 = V_26 -> V_610 ( V_58 , V_36 , V_592 , * V_589 ) ;
F_66 ( V_58 , V_202 ) ;
if ( V_33 )
goto V_95;
* V_589 = 0 ;
}
}
if ( F_268 ( V_556 , V_611 ,
* V_589 ) ) {
const struct V_24 * V_26 = NULL ;
const struct V_35 * V_366 ;
V_366 = F_62 ( V_36 ) ;
if ( V_366 )
V_26 = V_366 -> V_24 ;
if ( V_26 && V_26 -> V_610 ) {
* V_589 = V_611 ;
V_202 = F_65 ( V_58 ,
V_611 ) ;
if ( ! V_202 )
goto V_95;
V_33 = V_26 -> V_610 ( V_58 , V_36 , V_592 , * V_589 ) ;
F_66 ( V_58 , V_202 ) ;
if ( V_33 )
goto V_95;
* V_589 = 0 ;
}
}
if ( F_268 ( V_556 , V_612 ,
* V_589 ) ) {
* V_589 = V_612 ;
V_202 = F_65 ( V_58 , V_612 ) ;
if ( ! V_202 )
goto V_95;
V_33 = F_271 ( V_58 , V_36 , V_592 ) ;
if ( V_33 == - V_359 )
F_67 ( V_58 , V_202 ) ;
else
F_66 ( V_58 , V_202 ) ;
if ( V_33 && V_33 != - V_359 )
goto V_95;
* V_589 = 0 ;
}
if ( F_268 ( V_556 , V_613 , * V_589 ) ) {
struct V_53 * V_56 ;
* V_589 = V_613 ;
V_202 = F_65 ( V_58 , V_613 ) ;
if ( ! V_202 )
goto V_95;
F_33 (af_ops, &rtnl_af_ops, list) {
if ( V_56 -> V_614 ) {
struct V_50 * V_358 ;
int V_33 ;
V_358 = F_65 ( V_58 , V_56 -> V_54 ) ;
if ( ! V_358 )
goto V_95;
V_33 = V_56 -> V_614 ( V_58 , V_36 ) ;
if ( V_33 == - V_359 )
F_67 ( V_58 , V_358 ) ;
else if ( V_33 < 0 )
goto V_95;
F_66 ( V_58 , V_358 ) ;
}
}
F_66 ( V_58 , V_202 ) ;
* V_589 = 0 ;
}
F_144 ( V_58 , V_83 ) ;
return 0 ;
V_95:
if ( ! ( V_14 & V_378 ) || V_603 == * V_592 )
F_145 ( V_58 , V_83 ) ;
else
F_144 ( V_58 , V_83 ) ;
return - V_61 ;
}
static T_3 F_274 ( const struct V_35 * V_36 ,
T_4 V_556 )
{
T_3 V_47 = 0 ;
if ( F_268 ( V_556 , V_607 , 0 ) )
V_47 += F_102 ( sizeof( struct V_132 ) ) ;
if ( F_268 ( V_556 , V_609 , 0 ) ) {
const struct V_24 * V_26 = V_36 -> V_24 ;
int V_202 = V_609 ;
if ( V_26 && V_26 -> V_615 ) {
V_47 += F_53 ( V_26 -> V_615 ( V_36 ,
V_202 ) ) ;
V_47 += F_53 ( 0 ) ;
}
}
if ( F_268 ( V_556 , V_611 , 0 ) ) {
struct V_35 * V_616 = (struct V_35 * ) V_36 ;
const struct V_24 * V_26 = NULL ;
const struct V_35 * V_366 ;
V_366 = F_62 ( V_616 ) ;
if ( V_366 )
V_26 = V_366 -> V_24 ;
if ( V_26 && V_26 -> V_615 ) {
int V_202 = V_611 ;
V_47 += F_53 ( V_26 -> V_615 ( V_36 ,
V_202 ) ) ;
V_47 += F_53 ( 0 ) ;
}
}
if ( F_268 ( V_556 , V_612 , 0 ) )
V_47 += F_272 ( V_36 ) ;
if ( F_268 ( V_556 , V_613 , 0 ) ) {
struct V_53 * V_56 ;
V_47 += F_53 ( 0 ) ;
F_33 (af_ops, &rtnl_af_ops, list) {
if ( V_56 -> V_617 ) {
V_47 += F_53 (
V_56 -> V_617 ( V_36 ) ) ;
V_47 += F_53 ( 0 ) ;
}
}
}
return V_47 ;
}
static int F_275 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_35 * V_36 = NULL ;
int V_589 = 0 , V_592 = 0 ;
struct V_601 * V_602 ;
struct V_2 * V_498 ;
T_4 V_556 ;
int V_33 ;
if ( F_154 ( V_83 ) < sizeof( * V_602 ) )
return - V_398 ;
V_602 = F_134 ( V_83 ) ;
if ( V_602 -> V_314 > 0 )
V_36 = F_175 ( V_34 , V_602 -> V_314 ) ;
else
return - V_398 ;
if ( ! V_36 )
return - V_440 ;
V_556 = V_602 -> V_556 ;
if ( ! V_556 )
return - V_398 ;
V_498 = F_224 ( F_274 ( V_36 , V_556 ) , V_19 ) ;
if ( ! V_498 )
return - V_20 ;
V_33 = F_273 ( V_498 , V_36 , V_618 ,
F_71 ( V_58 ) . V_388 , V_83 -> V_389 , 0 ,
0 , V_556 , & V_589 , & V_592 ) ;
if ( V_33 < 0 ) {
F_225 ( V_33 == - V_61 ) ;
F_6 ( V_498 ) ;
} else {
V_33 = F_75 ( V_498 , V_34 , F_71 ( V_58 ) . V_388 ) ;
}
return V_33 ;
}
static int F_276 ( struct V_2 * V_58 , struct V_368 * V_369 )
{
int V_371 , V_372 , V_33 , V_374 , V_619 , V_603 ;
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
unsigned int V_14 = V_378 ;
struct V_601 * V_602 ;
struct V_375 * V_3 ;
struct V_35 * V_36 ;
T_4 V_556 = 0 ;
int V_373 = 0 ;
V_372 = V_369 -> args [ 0 ] ;
V_374 = V_369 -> args [ 1 ] ;
V_619 = V_369 -> args [ 2 ] ;
V_603 = V_369 -> args [ 3 ] ;
V_369 -> V_305 = V_34 -> V_392 ;
if ( F_154 ( V_369 -> V_83 ) < sizeof( * V_602 ) )
return - V_398 ;
V_602 = F_134 ( V_369 -> V_83 ) ;
V_556 = V_602 -> V_556 ;
if ( ! V_556 )
return - V_398 ;
for ( V_371 = V_372 ; V_371 < V_384 ; V_371 ++ , V_374 = 0 ) {
V_373 = 0 ;
V_3 = & V_34 -> V_385 [ V_371 ] ;
F_157 (dev, head, index_hlist) {
if ( V_373 < V_374 )
goto V_386;
V_33 = F_273 ( V_58 , V_36 , V_618 ,
F_71 ( V_369 -> V_58 ) . V_388 ,
V_369 -> V_83 -> V_389 , 0 ,
V_14 , V_556 ,
& V_619 , & V_603 ) ;
F_225 ( ( V_33 == - V_61 ) && ( V_58 -> V_390 == 0 ) ) ;
if ( V_33 < 0 )
goto V_48;
V_603 = 0 ;
V_619 = 0 ;
F_159 ( V_369 , F_160 ( V_58 ) ) ;
V_386:
V_373 ++ ;
}
}
V_48:
V_369 -> args [ 3 ] = V_603 ;
V_369 -> args [ 2 ] = V_619 ;
V_369 -> args [ 1 ] = V_373 ;
V_369 -> args [ 0 ] = V_371 ;
return V_58 -> V_390 ;
}
static int F_277 ( struct V_2 * V_58 , struct V_82 * V_83 ,
struct V_393 * V_428 )
{
struct V_34 * V_34 = F_153 ( V_58 -> V_370 ) ;
struct V_15 * V_21 ;
int V_33 = - V_197 ;
T_1 V_12 ;
unsigned int V_14 ;
int V_25 ;
int V_54 ;
int type ;
type = V_83 -> V_501 ;
if ( type > V_620 )
return - V_197 ;
type -= V_9 ;
if ( F_154 ( V_83 ) < sizeof( struct V_380 ) )
return 0 ;
V_54 = ( (struct V_380 * ) F_134 ( V_83 ) ) -> V_621 ;
V_25 = type & 3 ;
if ( V_25 != 2 && ! F_278 ( V_58 , V_433 ) )
return - V_434 ;
if ( V_54 >= F_279 ( V_18 ) )
V_54 = V_604 ;
F_51 () ;
V_21 = F_280 ( V_18 [ V_54 ] ) ;
if ( ! V_21 ) {
V_54 = V_604 ;
V_21 = F_280 ( V_18 [ V_54 ] ) ;
}
if ( V_25 == 2 && V_83 -> V_486 & V_622 ) {
struct V_77 * V_78 ;
T_2 V_13 ;
T_9 V_623 = 0 ;
V_13 = F_230 ( V_21 [ type ] . V_13 ) ;
if ( ! V_13 ) {
V_54 = V_604 ;
V_21 = F_280 ( V_18 [ V_604 ] ) ;
if ( ! V_21 )
goto V_624;
V_13 = F_230 ( V_21 [ type ] . V_13 ) ;
if ( ! V_13 )
goto V_624;
}
F_72 ( & V_23 [ V_54 ] ) ;
if ( type == V_625 - V_9 )
V_623 = F_226 ( V_58 , V_83 ) ;
F_54 () ;
V_78 = V_34 -> V_78 ;
{
struct V_626 V_627 = {
. V_628 = V_13 ,
. V_623 = V_623 ,
} ;
V_33 = F_281 ( V_78 , V_58 , V_83 , & V_627 ) ;
}
F_282 ( & V_23 [ V_54 ] ) ;
return V_33 ;
}
V_12 = F_230 ( V_21 [ type ] . V_12 ) ;
if ( ! V_12 ) {
V_54 = V_604 ;
V_21 = F_280 ( V_18 [ V_54 ] ) ;
}
V_14 = F_230 ( V_21 [ type ] . V_14 ) ;
if ( V_14 & V_629 ) {
F_72 ( & V_23 [ V_54 ] ) ;
V_12 = F_230 ( V_21 [ type ] . V_12 ) ;
F_54 () ;
if ( V_12 )
V_33 = V_12 ( V_58 , V_83 , V_428 ) ;
F_282 ( & V_23 [ V_54 ] ) ;
return V_33 ;
}
F_54 () ;
F_1 () ;
V_21 = F_25 ( V_18 [ V_54 ] ) ;
if ( V_21 ) {
V_12 = F_230 ( V_21 [ type ] . V_12 ) ;
if ( V_12 )
V_33 = V_12 ( V_58 , V_83 , V_428 ) ;
}
F_8 () ;
return V_33 ;
V_624:
F_54 () ;
return - V_197 ;
}
static void F_283 ( struct V_2 * V_58 )
{
F_284 ( V_58 , & F_277 ) ;
}
static int F_285 ( struct V_34 * V_34 , int V_75 )
{
switch ( V_75 ) {
case V_630 :
case V_631 :
if ( ! F_286 ( V_34 -> V_432 , V_433 ) )
return - V_434 ;
break;
}
return 0 ;
}
static int F_287 ( struct V_632 * V_633 , unsigned long V_290 , void * V_634 )
{
struct V_35 * V_36 = F_288 ( V_634 ) ;
switch ( V_290 ) {
case V_293 :
case V_635 :
case V_448 :
case V_636 :
case V_295 :
case V_297 :
case V_637 :
case V_299 :
case V_638 :
case V_301 :
case V_303 :
case V_451 :
F_233 ( V_387 , V_36 , 0 , F_131 ( V_290 ) ,
V_19 ) ;
break;
default:
break;
}
return V_639 ;
}
static int T_11 F_289 ( struct V_34 * V_34 )
{
struct V_77 * V_370 ;
struct V_640 V_641 = {
. V_642 = V_643 ,
. V_644 = F_283 ,
. V_645 = & V_1 ,
. V_14 = V_646 ,
. V_647 = F_285 ,
} ;
V_370 = F_290 ( V_34 , V_648 , & V_641 ) ;
if ( ! V_370 )
return - V_445 ;
V_34 -> V_78 = V_370 ;
return 0 ;
}
static void T_12 F_291 ( struct V_34 * V_34 )
{
F_292 ( V_34 -> V_78 ) ;
V_34 -> V_78 = NULL ;
}
void T_13 F_293 ( void )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < F_279 ( V_23 ) ; V_87 ++ )
F_294 ( & V_23 [ V_87 ] , 1 ) ;
if ( F_295 ( & V_649 ) )
F_23 ( L_17 ) ;
F_296 ( & V_650 ) ;
F_22 ( V_604 , V_625 , F_223 ,
F_152 , 0 ) ;
F_22 ( V_604 , V_651 , F_202 , NULL , 0 ) ;
F_22 ( V_604 , V_387 , F_216 , NULL , 0 ) ;
F_22 ( V_604 , V_652 , F_207 , NULL , 0 ) ;
F_22 ( V_604 , V_653 , NULL , F_229 , 0 ) ;
F_22 ( V_604 , V_654 , NULL , F_229 , 0 ) ;
F_22 ( V_604 , V_655 , NULL , F_229 , 0 ) ;
F_22 ( V_656 , V_536 , F_247 , NULL , 0 ) ;
F_22 ( V_656 , V_538 , F_251 , NULL , 0 ) ;
F_22 ( V_656 , V_657 , NULL , F_257 , 0 ) ;
F_22 ( V_656 , V_625 , NULL , F_262 , 0 ) ;
F_22 ( V_656 , V_652 , F_267 , NULL , 0 ) ;
F_22 ( V_656 , V_651 , F_266 , NULL , 0 ) ;
F_22 ( V_604 , V_658 , F_275 , F_276 ,
0 ) ;
}
