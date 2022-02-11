static void F_1 ( struct V_1 T_1 * * V_2 )
{
struct V_1 * V_3 = F_2 ( * V_2 , 1 ) ;
if ( ! V_3 )
return;
F_3 ( & V_3 -> V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_2 ( V_6 -> V_10 , 1 ) ;
if ( ! V_8 )
return;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
struct V_12 * V_13 ;
V_13 = F_2 ( V_8 [ V_9 ] . V_14 , 1 ) ;
while ( V_13 ) {
struct V_12 * V_15 ;
V_15 = F_2 ( V_13 -> V_16 , 1 ) ;
F_1 ( & V_13 -> V_17 ) ;
F_1 ( & V_13 -> V_18 ) ;
F_5 ( V_13 ) ;
V_13 = V_15 ;
}
}
F_5 ( V_8 ) ;
}
static void F_6 ( struct V_1 T_1 * T_2 * V_2 )
{
int V_19 ;
if ( ! V_2 )
return;
F_7 (cpu) {
struct V_1 * V_3 ;
V_3 = F_2 ( * F_8 ( V_2 , V_19 ) , 1 ) ;
if ( V_3 )
F_3 ( & V_3 -> V_4 ) ;
}
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( V_21 , struct V_22 , V_24 ) ;
F_12 (fi) {
if ( V_25 -> V_26 )
F_13 ( V_25 -> V_26 ) ;
F_4 ( V_25 ) ;
F_6 ( V_25 -> V_27 ) ;
F_1 ( & V_25 -> V_28 ) ;
} F_14 ( V_23 ) ;
F_15 ( V_23 -> V_29 ) ;
if ( V_23 -> V_30 != ( V_31 * ) V_32 )
F_5 ( V_23 -> V_30 ) ;
F_5 ( V_23 ) ;
}
void F_16 ( struct V_22 * V_23 )
{
if ( V_23 -> V_33 == 0 ) {
F_17 ( L_1 , V_23 ) ;
return;
}
V_34 -- ;
#ifdef F_18
F_12 (fi) {
if ( V_25 -> V_35 )
V_23 -> V_29 -> V_36 . V_37 -- ;
} F_14 ( V_23 ) ;
#endif
F_19 ( & V_23 -> V_24 , F_10 ) ;
}
void F_20 ( struct V_22 * V_23 )
{
F_21 ( & V_38 ) ;
if ( V_23 && -- V_23 -> V_39 == 0 ) {
F_22 ( & V_23 -> V_40 ) ;
if ( V_23 -> V_41 )
F_22 ( & V_23 -> V_42 ) ;
F_12 (fi) {
if ( ! V_25 -> V_26 )
continue;
F_22 ( & V_25 -> V_43 ) ;
} F_14 (fi)
V_23 -> V_33 = 1 ;
F_23 ( V_23 ) ;
}
F_24 ( & V_38 ) ;
}
static inline int F_25 ( const struct V_22 * V_23 , const struct V_22 * V_44 )
{
const struct V_5 * V_45 = V_44 -> V_5 ;
F_26 (fi) {
if ( V_6 -> V_46 != V_45 -> V_46 ||
V_6 -> V_47 != V_45 -> V_47 ||
V_6 -> V_48 != V_45 -> V_48 ||
#ifdef F_27
V_6 -> V_49 != V_45 -> V_49 ||
#endif
#ifdef F_18
V_6 -> V_35 != V_45 -> V_35 ||
#endif
( ( V_6 -> V_50 ^ V_45 -> V_50 ) & ~ V_51 ) )
return - 1 ;
V_45 ++ ;
} F_14 ( V_23 ) ;
return 0 ;
}
static inline unsigned int F_28 ( unsigned int V_52 )
{
unsigned int V_53 = V_54 - 1 ;
return ( V_52 ^
( V_52 >> V_55 ) ^
( V_52 >> ( V_55 * 2 ) ) ) & V_53 ;
}
static inline unsigned int F_29 ( const struct V_22 * V_23 )
{
unsigned int V_53 = ( V_56 - 1 ) ;
unsigned int V_52 = V_23 -> V_57 ;
V_52 ^= ( V_23 -> V_58 << 8 ) | V_23 -> V_59 ;
V_52 ^= ( V_60 V_31 ) V_23 -> V_41 ;
V_52 ^= V_23 -> V_61 ;
F_26 (fi) {
V_52 ^= F_28 ( V_6 -> V_46 ) ;
} F_14 (fi)
return ( V_52 ^ ( V_52 >> 7 ) ^ ( V_52 >> 12 ) ) & V_53 ;
}
static struct V_22 * F_30 ( const struct V_22 * V_62 )
{
struct V_63 * V_21 ;
struct V_22 * V_23 ;
unsigned int V_8 ;
V_8 = F_29 ( V_62 ) ;
V_21 = & V_64 [ V_8 ] ;
F_31 (fi, head, fib_hash) {
if ( ! F_32 ( V_23 -> V_29 , V_62 -> V_29 ) )
continue;
if ( V_23 -> V_57 != V_62 -> V_57 )
continue;
if ( V_62 -> V_58 == V_23 -> V_58 &&
V_62 -> V_59 == V_23 -> V_59 &&
V_62 -> V_41 == V_23 -> V_41 &&
V_62 -> V_61 == V_23 -> V_61 &&
V_62 -> V_65 == V_23 -> V_65 &&
memcmp ( V_62 -> V_30 , V_23 -> V_30 ,
sizeof( V_31 ) * V_66 ) == 0 &&
( ( V_62 -> V_67 ^ V_23 -> V_67 ) & ~ V_51 ) == 0 &&
( V_62 -> V_57 == 0 || F_25 ( V_23 , V_62 ) == 0 ) )
return V_23 ;
}
return NULL ;
}
int F_33 ( T_3 V_68 , struct V_69 * V_70 )
{
struct V_63 * V_21 ;
struct V_5 * V_6 ;
unsigned int V_8 ;
F_34 ( & V_38 ) ;
V_8 = F_28 ( V_70 -> V_71 ) ;
V_21 = & V_72 [ V_8 ] ;
F_31 (nh, head, nh_hash) {
if ( V_6 -> V_26 == V_70 &&
V_6 -> V_47 == V_68 &&
! ( V_6 -> V_50 & V_51 ) ) {
F_35 ( & V_38 ) ;
return 0 ;
}
}
F_35 ( & V_38 ) ;
return - 1 ;
}
static inline T_4 F_36 ( struct V_22 * V_23 )
{
T_4 V_73 = F_37 ( sizeof( struct V_74 ) )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( V_75 ) ;
V_73 += F_38 ( ( V_66 * F_38 ( 4 ) ) ) ;
if ( V_23 -> V_57 ) {
T_4 V_76 = F_38 ( sizeof( struct V_77 ) ) ;
V_76 += 2 * F_38 ( 4 ) ;
V_73 += F_38 ( V_23 -> V_57 * V_76 ) ;
}
return V_73 ;
}
void F_39 ( int V_78 , T_3 V_79 , struct V_80 * V_81 ,
int V_82 , V_31 V_83 , const struct V_84 * V_85 ,
unsigned int V_86 )
{
struct V_87 * V_88 ;
V_31 V_89 = V_85 -> V_90 ? V_85 -> V_90 -> V_91 : 0 ;
int V_92 = - V_93 ;
V_88 = F_40 ( F_36 ( V_81 -> V_94 ) , V_95 ) ;
if ( V_88 == NULL )
goto V_96;
V_92 = F_41 ( V_88 , V_85 -> V_97 , V_89 , V_78 , V_83 ,
V_81 -> V_98 , V_79 , V_82 ,
V_81 -> V_99 , V_81 -> V_94 , V_86 ) ;
if ( V_92 < 0 ) {
F_42 ( V_92 == - V_100 ) ;
F_43 ( V_88 ) ;
goto V_96;
}
F_44 ( V_88 , V_85 -> V_101 , V_85 -> V_97 , V_102 ,
V_85 -> V_90 , V_95 ) ;
return;
V_96:
if ( V_92 < 0 )
F_45 ( V_85 -> V_101 , V_102 , V_92 ) ;
}
static int F_46 ( struct V_22 * V_23 , int V_103 ,
struct V_22 * * V_104 , int * V_105 ,
int V_106 )
{
struct V_107 * V_108 ;
int V_109 = V_110 ;
V_108 = F_47 ( & V_111 , & V_23 -> V_5 [ 0 ] . V_47 , V_23 -> V_112 ) ;
if ( V_108 ) {
V_109 = V_108 -> V_113 ;
F_48 ( V_108 ) ;
}
if ( V_109 == V_114 )
return 0 ;
if ( ( V_109 & V_115 ) && V_103 != V_106 )
return 0 ;
if ( ( V_109 & V_115 ) ||
( * V_105 < 0 && V_103 > V_106 ) ) {
* V_104 = V_23 ;
* V_105 = V_103 ;
}
return 1 ;
}
static int F_49 ( struct V_77 * V_116 , int V_117 )
{
int V_118 = 0 ;
while ( F_50 ( V_116 , V_117 ) ) {
V_118 ++ ;
V_116 = F_51 ( V_116 , & V_117 ) ;
}
return V_117 > 0 ? 0 : V_118 ;
}
static int F_52 ( struct V_22 * V_23 , struct V_77 * V_116 ,
int V_117 , struct V_119 * V_120 )
{
F_12 (fi) {
int V_121 ;
if ( ! F_50 ( V_116 , V_117 ) )
return - V_122 ;
V_25 -> V_50 =
( V_120 -> V_123 & ~ 0xFF ) | V_116 -> V_124 ;
V_25 -> V_46 = V_116 -> V_125 ;
V_25 -> V_49 = V_116 -> V_126 + 1 ;
V_121 = F_53 ( V_116 ) ;
if ( V_121 > 0 ) {
struct V_127 * V_128 , * V_129 = F_54 ( V_116 ) ;
V_128 = F_55 ( V_129 , V_121 , V_130 ) ;
V_25 -> V_47 = V_128 ? F_56 ( V_128 ) : 0 ;
#ifdef F_18
V_128 = F_55 ( V_129 , V_121 , V_131 ) ;
V_25 -> V_35 = V_128 ? F_57 ( V_128 ) : 0 ;
if ( V_25 -> V_35 )
V_23 -> V_29 -> V_36 . V_37 ++ ;
#endif
}
V_116 = F_51 ( V_116 , & V_117 ) ;
} F_14 ( V_23 ) ;
return 0 ;
}
int F_58 ( struct V_119 * V_120 , struct V_22 * V_23 )
{
#ifdef F_27
struct V_77 * V_116 ;
int V_117 ;
#endif
if ( V_120 -> V_132 && V_120 -> V_132 != V_23 -> V_61 )
return 1 ;
if ( V_120 -> V_133 || V_120 -> V_134 ) {
if ( ( ! V_120 -> V_133 || V_120 -> V_133 == V_23 -> V_5 -> V_46 ) &&
( ! V_120 -> V_134 || V_120 -> V_134 == V_23 -> V_5 -> V_47 ) )
return 0 ;
return 1 ;
}
#ifdef F_27
if ( V_120 -> V_135 == NULL )
return 0 ;
V_116 = V_120 -> V_135 ;
V_117 = V_120 -> V_136 ;
F_26 (fi) {
int V_121 ;
if ( ! F_50 ( V_116 , V_117 ) )
return - V_122 ;
if ( V_116 -> V_125 && V_116 -> V_125 != V_6 -> V_46 )
return 1 ;
V_121 = F_53 ( V_116 ) ;
if ( V_121 > 0 ) {
struct V_127 * V_128 , * V_129 = F_54 ( V_116 ) ;
V_128 = F_55 ( V_129 , V_121 , V_130 ) ;
if ( V_128 && F_56 ( V_128 ) != V_6 -> V_47 )
return 1 ;
#ifdef F_18
V_128 = F_55 ( V_129 , V_121 , V_131 ) ;
if ( V_128 && F_57 ( V_128 ) != V_6 -> V_35 )
return 1 ;
#endif
}
V_116 = F_51 ( V_116 , & V_117 ) ;
} F_14 ( V_23 ) ;
#endif
return 0 ;
}
static int F_59 ( struct V_119 * V_120 , struct V_22 * V_23 ,
struct V_5 * V_6 )
{
int V_92 ;
struct V_137 * V_137 ;
struct V_69 * V_70 ;
V_137 = V_120 -> V_138 . V_101 ;
if ( V_6 -> V_47 ) {
struct V_139 V_140 ;
if ( V_6 -> V_50 & V_141 ) {
if ( V_120 -> V_142 >= V_143 )
return - V_122 ;
if ( F_60 ( V_137 , V_6 -> V_47 ) != V_144 )
return - V_122 ;
V_70 = F_61 ( V_137 , V_6 -> V_46 ) ;
if ( ! V_70 )
return - V_145 ;
if ( ! ( V_70 -> V_146 & V_147 ) )
return - V_148 ;
V_6 -> V_26 = V_70 ;
F_62 ( V_70 ) ;
V_6 -> V_48 = V_143 ;
return 0 ;
}
F_63 () ;
{
struct V_149 V_150 = {
. V_151 = V_6 -> V_47 ,
. V_152 = V_120 -> V_142 + 1 ,
. V_153 = V_6 -> V_46 ,
. V_154 = V_155 ,
} ;
if ( V_150 . V_152 < V_143 )
V_150 . V_152 = V_143 ;
V_92 = F_64 ( V_137 , & V_150 , & V_140 ) ;
if ( V_92 ) {
F_65 () ;
return V_92 ;
}
}
V_92 = - V_122 ;
if ( V_140 . type != V_144 && V_140 . type != V_156 )
goto V_157;
V_6 -> V_48 = V_140 . V_158 ;
V_6 -> V_46 = F_66 ( V_140 ) ;
V_6 -> V_26 = V_70 = F_67 ( V_140 ) ;
if ( ! V_70 )
goto V_157;
F_62 ( V_70 ) ;
V_92 = ( V_70 -> V_146 & V_147 ) ? 0 : - V_148 ;
} else {
struct V_159 * V_160 ;
if ( V_6 -> V_50 & ( V_161 | V_141 ) )
return - V_122 ;
F_63 () ;
V_92 = - V_145 ;
V_160 = F_68 ( V_137 , V_6 -> V_46 ) ;
if ( V_160 == NULL )
goto V_157;
V_92 = - V_148 ;
if ( ! ( V_160 -> V_70 -> V_146 & V_147 ) )
goto V_157;
V_6 -> V_26 = V_160 -> V_70 ;
F_62 ( V_6 -> V_26 ) ;
V_6 -> V_48 = V_162 ;
V_92 = 0 ;
}
V_157:
F_65 () ;
return V_92 ;
}
static inline unsigned int F_69 ( T_3 V_52 )
{
unsigned int V_53 = ( V_56 - 1 ) ;
return ( ( V_60 V_31 ) V_52 ^
( ( V_60 V_31 ) V_52 >> 7 ) ^
( ( V_60 V_31 ) V_52 >> 14 ) ) & V_53 ;
}
static struct V_63 * F_70 ( int V_163 )
{
if ( V_163 <= V_164 )
return F_71 ( V_163 , V_95 ) ;
else
return (struct V_63 * )
F_72 ( V_95 | V_165 ,
F_73 ( V_163 ) ) ;
}
static void F_74 ( struct V_63 * V_8 , int V_163 )
{
if ( ! V_8 )
return;
if ( V_163 <= V_164 )
F_5 ( V_8 ) ;
else
F_75 ( ( unsigned long ) V_8 , F_73 ( V_163 ) ) ;
}
static void F_76 ( struct V_63 * V_166 ,
struct V_63 * V_167 ,
unsigned int V_168 )
{
struct V_63 * V_169 , * V_170 ;
unsigned int V_171 = V_56 ;
unsigned int V_9 , V_163 ;
F_21 ( & V_38 ) ;
V_169 = V_64 ;
V_170 = V_172 ;
V_56 = V_168 ;
for ( V_9 = 0 ; V_9 < V_171 ; V_9 ++ ) {
struct V_63 * V_21 = & V_64 [ V_9 ] ;
struct V_173 * V_108 ;
struct V_22 * V_23 ;
F_77 (fi, n, head, fib_hash) {
struct V_63 * V_174 ;
unsigned int V_175 ;
F_22 ( & V_23 -> V_40 ) ;
V_175 = F_29 ( V_23 ) ;
V_174 = & V_166 [ V_175 ] ;
F_78 ( & V_23 -> V_40 , V_174 ) ;
}
}
V_64 = V_166 ;
for ( V_9 = 0 ; V_9 < V_171 ; V_9 ++ ) {
struct V_63 * V_176 = & V_172 [ V_9 ] ;
struct V_173 * V_108 ;
struct V_22 * V_23 ;
F_77 (fi, n, lhead, fib_lhash) {
struct V_63 * V_177 ;
unsigned int V_175 ;
F_22 ( & V_23 -> V_42 ) ;
V_175 = F_69 ( V_23 -> V_41 ) ;
V_177 = & V_167 [ V_175 ] ;
F_78 ( & V_23 -> V_42 , V_177 ) ;
}
}
V_172 = V_167 ;
F_24 ( & V_38 ) ;
V_163 = V_171 * sizeof( struct V_63 * ) ;
F_74 ( V_169 , V_163 ) ;
F_74 ( V_170 , V_163 ) ;
}
T_3 F_79 ( struct V_137 * V_137 , struct V_5 * V_6 )
{
V_6 -> V_178 = F_80 ( V_6 -> V_26 ,
V_6 -> V_47 ,
V_6 -> V_179 -> V_59 ) ;
V_6 -> V_180 = F_81 ( & V_137 -> V_36 . V_181 ) ;
return V_6 -> V_178 ;
}
struct V_22 * F_82 ( struct V_119 * V_120 )
{
int V_92 ;
struct V_22 * V_23 = NULL ;
struct V_22 * V_44 ;
int V_118 = 1 ;
struct V_137 * V_137 = V_120 -> V_138 . V_101 ;
if ( V_120 -> V_182 > V_183 )
goto V_184;
if ( V_185 [ V_120 -> V_182 ] . V_158 > V_120 -> V_142 )
goto V_184;
#ifdef F_27
if ( V_120 -> V_135 ) {
V_118 = F_49 ( V_120 -> V_135 , V_120 -> V_136 ) ;
if ( V_118 == 0 )
goto V_184;
}
#endif
V_92 = - V_93 ;
if ( V_34 >= V_56 ) {
unsigned int V_168 = V_56 << 1 ;
struct V_63 * V_166 ;
struct V_63 * V_167 ;
unsigned int V_163 ;
if ( ! V_168 )
V_168 = 16 ;
V_163 = V_168 * sizeof( struct V_63 * ) ;
V_166 = F_70 ( V_163 ) ;
V_167 = F_70 ( V_163 ) ;
if ( ! V_166 || ! V_167 ) {
F_74 ( V_166 , V_163 ) ;
F_74 ( V_167 , V_163 ) ;
} else
F_76 ( V_166 , V_167 , V_168 ) ;
if ( ! V_56 )
goto V_186;
}
V_23 = F_71 ( sizeof( * V_23 ) + V_118 * sizeof( struct V_5 ) , V_95 ) ;
if ( V_23 == NULL )
goto V_186;
V_34 ++ ;
if ( V_120 -> V_187 ) {
V_23 -> V_30 = F_71 ( sizeof( V_31 ) * V_66 , V_95 ) ;
if ( ! V_23 -> V_30 )
goto V_186;
} else
V_23 -> V_30 = ( V_31 * ) V_32 ;
V_23 -> V_29 = F_83 ( V_137 ) ;
V_23 -> V_58 = V_120 -> V_188 ;
V_23 -> V_59 = V_120 -> V_142 ;
V_23 -> V_67 = V_120 -> V_123 ;
V_23 -> V_61 = V_120 -> V_132 ;
V_23 -> V_41 = V_120 -> V_189 ;
V_23 -> V_65 = V_120 -> V_182 ;
V_23 -> V_57 = V_118 ;
F_12 (fi) {
V_25 -> V_179 = V_23 ;
V_25 -> V_27 = F_84 (struct rtable __rcu *) ;
if ( ! V_25 -> V_27 )
goto V_186;
} F_14 (fi)
if ( V_120 -> V_187 ) {
struct V_127 * V_128 ;
int V_117 ;
F_85 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_86 ( V_128 ) ;
if ( type ) {
V_31 V_52 ;
if ( type > V_66 )
goto V_184;
if ( type == V_190 ) {
char V_191 [ V_75 ] ;
F_87 ( V_191 , V_128 , sizeof( V_191 ) ) ;
V_52 = F_88 ( V_191 ) ;
if ( V_52 == V_192 )
goto V_184;
} else {
V_52 = F_57 ( V_128 ) ;
}
if ( type == V_193 && V_52 > 65535 - 40 )
V_52 = 65535 - 40 ;
if ( type == V_194 && V_52 > 65535 - 15 )
V_52 = 65535 - 15 ;
V_23 -> V_30 [ type - 1 ] = V_52 ;
}
}
}
if ( V_120 -> V_135 ) {
#ifdef F_27
V_92 = F_52 ( V_23 , V_120 -> V_135 , V_120 -> V_136 , V_120 ) ;
if ( V_92 != 0 )
goto V_186;
if ( V_120 -> V_133 && V_23 -> V_5 -> V_46 != V_120 -> V_133 )
goto V_184;
if ( V_120 -> V_134 && V_23 -> V_5 -> V_47 != V_120 -> V_134 )
goto V_184;
#ifdef F_18
if ( V_120 -> V_195 && V_23 -> V_5 -> V_35 != V_120 -> V_195 )
goto V_184;
#endif
#else
goto V_184;
#endif
} else {
struct V_5 * V_6 = V_23 -> V_5 ;
V_6 -> V_46 = V_120 -> V_133 ;
V_6 -> V_47 = V_120 -> V_134 ;
V_6 -> V_50 = V_120 -> V_123 ;
#ifdef F_18
V_6 -> V_35 = V_120 -> V_195 ;
if ( V_6 -> V_35 )
V_23 -> V_29 -> V_36 . V_37 ++ ;
#endif
#ifdef F_27
V_6 -> V_49 = 1 ;
#endif
}
if ( V_185 [ V_120 -> V_182 ] . error ) {
if ( V_120 -> V_134 || V_120 -> V_133 || V_120 -> V_135 )
goto V_184;
goto V_196;
} else {
switch ( V_120 -> V_182 ) {
case V_144 :
case V_156 :
case V_197 :
case V_198 :
case V_199 :
break;
default:
goto V_184;
}
}
if ( V_120 -> V_142 > V_162 )
goto V_184;
if ( V_120 -> V_142 == V_162 ) {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_118 != 1 || V_6 -> V_47 )
goto V_184;
V_6 -> V_48 = V_200 ;
V_6 -> V_26 = F_89 ( V_137 , V_23 -> V_5 -> V_46 ) ;
V_92 = - V_145 ;
if ( V_6 -> V_26 == NULL )
goto V_186;
} else {
F_12 (fi) {
V_92 = F_59 ( V_120 , V_23 , V_25 ) ;
if ( V_92 != 0 )
goto V_186;
} F_14 (fi)
}
if ( V_23 -> V_41 ) {
if ( V_120 -> V_182 != V_156 || ! V_120 -> V_201 ||
V_23 -> V_41 != V_120 -> V_201 )
if ( F_60 ( V_137 , V_23 -> V_41 ) != V_156 )
goto V_184;
}
F_12 (fi) {
F_79 ( V_137 , V_25 ) ;
} F_14 (fi)
V_196:
V_44 = F_30 ( V_23 ) ;
if ( V_44 ) {
V_23 -> V_33 = 1 ;
F_16 ( V_23 ) ;
V_44 -> V_39 ++ ;
return V_44 ;
}
V_23 -> V_39 ++ ;
F_90 ( & V_23 -> V_202 ) ;
F_21 ( & V_38 ) ;
F_78 ( & V_23 -> V_40 ,
& V_64 [ F_29 ( V_23 ) ] ) ;
if ( V_23 -> V_41 ) {
struct V_63 * V_21 ;
V_21 = & V_172 [ F_69 ( V_23 -> V_41 ) ] ;
F_78 ( & V_23 -> V_42 , V_21 ) ;
}
F_12 (fi) {
struct V_63 * V_21 ;
unsigned int V_8 ;
if ( ! V_25 -> V_26 )
continue;
V_8 = F_28 ( V_25 -> V_26 -> V_71 ) ;
V_21 = & V_72 [ V_8 ] ;
F_78 ( & V_25 -> V_43 , V_21 ) ;
} F_14 (fi)
F_24 ( & V_38 ) ;
return V_23 ;
V_184:
V_92 = - V_122 ;
V_186:
if ( V_23 ) {
V_23 -> V_33 = 1 ;
F_16 ( V_23 ) ;
}
return F_91 ( V_92 ) ;
}
int F_41 ( struct V_87 * V_88 , V_31 V_97 , V_31 V_89 , int V_78 ,
V_31 V_83 , T_5 type , T_3 V_4 , int V_82 , T_5 V_203 ,
struct V_22 * V_23 , unsigned int V_146 )
{
struct V_204 * V_90 ;
struct V_74 * V_205 ;
V_90 = F_92 ( V_88 , V_97 , V_89 , V_78 , sizeof( * V_205 ) , V_146 ) ;
if ( V_90 == NULL )
return - V_100 ;
V_205 = F_93 ( V_90 ) ;
V_205 -> V_206 = V_207 ;
V_205 -> V_208 = V_82 ;
V_205 -> V_209 = 0 ;
V_205 -> V_210 = V_203 ;
if ( V_83 < 256 )
V_205 -> V_211 = V_83 ;
else
V_205 -> V_211 = V_212 ;
if ( F_94 ( V_88 , V_213 , V_83 ) )
goto V_214;
V_205 -> V_215 = type ;
V_205 -> V_216 = V_23 -> V_67 ;
V_205 -> V_217 = V_23 -> V_59 ;
V_205 -> V_218 = V_23 -> V_58 ;
if ( V_205 -> V_208 &&
F_95 ( V_88 , V_219 , V_4 ) )
goto V_214;
if ( V_23 -> V_61 &&
F_94 ( V_88 , V_220 , V_23 -> V_61 ) )
goto V_214;
if ( F_96 ( V_88 , V_23 -> V_30 ) < 0 )
goto V_214;
if ( V_23 -> V_41 &&
F_95 ( V_88 , V_221 , V_23 -> V_41 ) )
goto V_214;
if ( V_23 -> V_57 == 1 ) {
if ( V_23 -> V_5 -> V_47 &&
F_95 ( V_88 , V_130 , V_23 -> V_5 -> V_47 ) )
goto V_214;
if ( V_23 -> V_5 -> V_46 &&
F_94 ( V_88 , V_222 , V_23 -> V_5 -> V_46 ) )
goto V_214;
#ifdef F_18
if ( V_23 -> V_5 [ 0 ] . V_35 &&
F_94 ( V_88 , V_131 , V_23 -> V_5 [ 0 ] . V_35 ) )
goto V_214;
#endif
}
#ifdef F_27
if ( V_23 -> V_57 > 1 ) {
struct V_77 * V_116 ;
struct V_127 * V_223 ;
V_223 = F_97 ( V_88 , V_224 ) ;
if ( V_223 == NULL )
goto V_214;
F_26 (fi) {
V_116 = F_98 ( V_88 , sizeof( * V_116 ) ) ;
if ( V_116 == NULL )
goto V_214;
V_116 -> V_124 = V_6 -> V_50 & 0xFF ;
V_116 -> V_126 = V_6 -> V_49 - 1 ;
V_116 -> V_125 = V_6 -> V_46 ;
if ( V_6 -> V_47 &&
F_95 ( V_88 , V_130 , V_6 -> V_47 ) )
goto V_214;
#ifdef F_18
if ( V_6 -> V_35 &&
F_94 ( V_88 , V_131 , V_6 -> V_35 ) )
goto V_214;
#endif
V_116 -> V_225 = F_99 ( V_88 ) - ( void * ) V_116 ;
} F_14 ( V_23 ) ;
F_100 ( V_88 , V_223 ) ;
}
#endif
F_101 ( V_88 , V_90 ) ;
return 0 ;
V_214:
F_102 ( V_88 , V_90 ) ;
return - V_100 ;
}
int F_103 ( struct V_137 * V_137 , T_3 V_226 )
{
int V_227 = 0 ;
unsigned int V_8 = F_69 ( V_226 ) ;
struct V_63 * V_21 = & V_172 [ V_8 ] ;
struct V_22 * V_23 ;
if ( V_172 == NULL || V_226 == 0 )
return 0 ;
F_31 (fi, head, fib_lhash) {
if ( ! F_32 ( V_23 -> V_29 , V_137 ) )
continue;
if ( V_23 -> V_41 == V_226 ) {
V_23 -> V_67 |= V_51 ;
V_227 ++ ;
}
}
return V_227 ;
}
int F_104 ( struct V_69 * V_70 , int V_228 )
{
int V_227 = 0 ;
int V_158 = V_200 ;
struct V_22 * V_229 = NULL ;
unsigned int V_8 = F_28 ( V_70 -> V_71 ) ;
struct V_63 * V_21 = & V_72 [ V_8 ] ;
struct V_5 * V_6 ;
if ( V_228 )
V_158 = - 1 ;
F_31 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_179 ;
int V_230 ;
F_105 ( ! V_23 -> V_57 ) ;
if ( V_6 -> V_26 != V_70 || V_23 == V_229 )
continue;
V_229 = V_23 ;
V_230 = 0 ;
F_12 (fi) {
if ( V_25 -> V_50 & V_51 )
V_230 ++ ;
else if ( V_25 -> V_26 == V_70 &&
V_25 -> V_48 != V_158 ) {
V_25 -> V_50 |= V_51 ;
#ifdef F_27
F_21 ( & V_231 ) ;
V_23 -> V_232 -= V_25 -> V_233 ;
V_25 -> V_233 = 0 ;
F_24 ( & V_231 ) ;
#endif
V_230 ++ ;
}
#ifdef F_27
if ( V_228 > 1 && V_25 -> V_26 == V_70 ) {
V_230 = V_23 -> V_57 ;
break;
}
#endif
} F_14 (fi)
if ( V_230 == V_23 -> V_57 ) {
V_23 -> V_67 |= V_51 ;
V_227 ++ ;
}
}
return V_227 ;
}
void F_106 ( struct V_139 * V_140 )
{
struct V_22 * V_23 = NULL , * V_104 = NULL ;
struct V_234 * V_235 = V_140 -> V_235 ;
struct V_236 * V_237 = V_140 -> V_238 ;
int V_103 = - 1 , V_105 = - 1 ;
struct V_80 * V_81 ;
F_107 (fa, fa_head, fa_list) {
struct V_22 * V_239 = V_81 -> V_94 ;
if ( V_239 -> V_59 != V_140 -> V_158 ||
V_81 -> V_98 != V_144 )
continue;
if ( V_239 -> V_61 > V_140 -> V_23 -> V_61 )
break;
if ( ! V_239 -> V_5 [ 0 ] . V_47 ||
V_239 -> V_5 [ 0 ] . V_48 != V_143 )
continue;
F_108 ( V_81 ) ;
if ( V_23 == NULL ) {
if ( V_239 != V_140 -> V_23 )
break;
} else if ( ! F_46 ( V_23 , V_103 , & V_104 ,
& V_105 , V_237 -> V_240 ) ) {
F_109 ( V_140 , V_23 ) ;
V_237 -> V_240 = V_103 ;
goto V_157;
}
V_23 = V_239 ;
V_103 ++ ;
}
if ( V_103 <= 0 || V_23 == NULL ) {
V_237 -> V_240 = - 1 ;
goto V_157;
}
if ( ! F_46 ( V_23 , V_103 , & V_104 , & V_105 ,
V_237 -> V_240 ) ) {
F_109 ( V_140 , V_23 ) ;
V_237 -> V_240 = V_103 ;
goto V_157;
}
if ( V_105 >= 0 )
F_109 ( V_140 , V_104 ) ;
V_237 -> V_240 = V_105 ;
V_157:
return;
}
int F_110 ( struct V_69 * V_70 )
{
struct V_22 * V_229 ;
unsigned int V_8 ;
struct V_63 * V_21 ;
struct V_5 * V_6 ;
int V_227 ;
if ( ! ( V_70 -> V_146 & V_147 ) )
return 0 ;
V_229 = NULL ;
V_8 = F_28 ( V_70 -> V_71 ) ;
V_21 = & V_72 [ V_8 ] ;
V_227 = 0 ;
F_31 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_179 ;
int V_241 ;
F_105 ( ! V_23 -> V_57 ) ;
if ( V_6 -> V_26 != V_70 || V_23 == V_229 )
continue;
V_229 = V_23 ;
V_241 = 0 ;
F_12 (fi) {
if ( ! ( V_25 -> V_50 & V_51 ) ) {
V_241 ++ ;
continue;
}
if ( V_25 -> V_26 == NULL ||
! ( V_25 -> V_26 -> V_146 & V_147 ) )
continue;
if ( V_25 -> V_26 != V_70 ||
! F_111 ( V_70 ) )
continue;
V_241 ++ ;
F_21 ( & V_231 ) ;
V_25 -> V_233 = 0 ;
V_25 -> V_50 &= ~ V_51 ;
F_24 ( & V_231 ) ;
} F_14 (fi)
if ( V_241 > 0 ) {
V_23 -> V_67 &= ~ V_51 ;
V_227 ++ ;
}
}
return V_227 ;
}
void F_112 ( struct V_139 * V_140 )
{
struct V_22 * V_23 = V_140 -> V_23 ;
int V_242 ;
F_21 ( & V_231 ) ;
if ( V_23 -> V_232 <= 0 ) {
int V_243 = 0 ;
F_12 (fi) {
if ( ! ( V_25 -> V_50 & V_51 ) ) {
V_243 += V_25 -> V_49 ;
V_25 -> V_233 = V_25 -> V_49 ;
}
} F_14 ( V_23 ) ;
V_23 -> V_232 = V_243 ;
if ( V_243 <= 0 ) {
F_24 ( & V_231 ) ;
V_140 -> V_244 = 0 ;
return;
}
}
V_242 = V_245 % V_23 -> V_232 ;
F_12 (fi) {
if ( ! ( V_25 -> V_50 & V_51 ) &&
V_25 -> V_233 ) {
V_242 -= V_25 -> V_233 ;
if ( V_242 <= 0 ) {
V_25 -> V_233 -- ;
V_23 -> V_232 -- ;
V_140 -> V_244 = V_246 ;
F_24 ( & V_231 ) ;
return;
}
}
} F_14 ( V_23 ) ;
V_140 -> V_244 = 0 ;
F_24 ( & V_231 ) ;
}
