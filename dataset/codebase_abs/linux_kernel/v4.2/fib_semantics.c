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
if ( V_23 -> V_29 != ( V_30 * ) V_31 )
F_5 ( V_23 -> V_29 ) ;
F_5 ( V_23 ) ;
}
void F_15 ( struct V_22 * V_23 )
{
if ( V_23 -> V_32 == 0 ) {
F_16 ( L_1 , V_23 ) ;
return;
}
V_33 -- ;
#ifdef F_17
F_12 (fi) {
if ( V_25 -> V_34 )
V_23 -> V_35 -> V_36 . V_37 -- ;
} F_14 ( V_23 ) ;
#endif
F_18 ( & V_23 -> V_24 , F_10 ) ;
}
void F_19 ( struct V_22 * V_23 )
{
F_20 ( & V_38 ) ;
if ( V_23 && -- V_23 -> V_39 == 0 ) {
F_21 ( & V_23 -> V_40 ) ;
if ( V_23 -> V_41 )
F_21 ( & V_23 -> V_42 ) ;
F_12 (fi) {
if ( ! V_25 -> V_26 )
continue;
F_21 ( & V_25 -> V_43 ) ;
} F_14 (fi)
V_23 -> V_32 = 1 ;
F_22 ( V_23 ) ;
}
F_23 ( & V_38 ) ;
}
static inline int F_24 ( const struct V_22 * V_23 , const struct V_22 * V_44 )
{
const struct V_5 * V_45 = V_44 -> V_5 ;
F_25 (fi) {
if ( V_6 -> V_46 != V_45 -> V_46 ||
V_6 -> V_47 != V_45 -> V_47 ||
V_6 -> V_48 != V_45 -> V_48 ||
#ifdef F_26
V_6 -> V_49 != V_45 -> V_49 ||
#endif
#ifdef F_17
V_6 -> V_34 != V_45 -> V_34 ||
#endif
( ( V_6 -> V_50 ^ V_45 -> V_50 ) & ~ V_51 ) )
return - 1 ;
V_45 ++ ;
} F_14 ( V_23 ) ;
return 0 ;
}
static inline unsigned int F_27 ( unsigned int V_52 )
{
unsigned int V_53 = V_54 - 1 ;
return ( V_52 ^
( V_52 >> V_55 ) ^
( V_52 >> ( V_55 * 2 ) ) ) & V_53 ;
}
static inline unsigned int F_28 ( const struct V_22 * V_23 )
{
unsigned int V_53 = ( V_56 - 1 ) ;
unsigned int V_52 = V_23 -> V_57 ;
V_52 ^= ( V_23 -> V_58 << 8 ) | V_23 -> V_59 ;
V_52 ^= ( V_60 V_30 ) V_23 -> V_41 ;
V_52 ^= V_23 -> V_61 ;
F_25 (fi) {
V_52 ^= F_27 ( V_6 -> V_46 ) ;
} F_14 (fi)
return ( V_52 ^ ( V_52 >> 7 ) ^ ( V_52 >> 12 ) ) & V_53 ;
}
static struct V_22 * F_29 ( const struct V_22 * V_62 )
{
struct V_63 * V_21 ;
struct V_22 * V_23 ;
unsigned int V_8 ;
V_8 = F_28 ( V_62 ) ;
V_21 = & V_64 [ V_8 ] ;
F_30 (fi, head, fib_hash) {
if ( ! F_31 ( V_23 -> V_35 , V_62 -> V_35 ) )
continue;
if ( V_23 -> V_57 != V_62 -> V_57 )
continue;
if ( V_62 -> V_58 == V_23 -> V_58 &&
V_62 -> V_59 == V_23 -> V_59 &&
V_62 -> V_41 == V_23 -> V_41 &&
V_62 -> V_61 == V_23 -> V_61 &&
V_62 -> V_65 == V_23 -> V_65 &&
memcmp ( V_62 -> V_29 , V_23 -> V_29 ,
sizeof( V_30 ) * V_66 ) == 0 &&
! ( ( V_62 -> V_67 ^ V_23 -> V_67 ) & ~ V_51 ) &&
( V_62 -> V_57 == 0 || F_24 ( V_23 , V_62 ) == 0 ) )
return V_23 ;
}
return NULL ;
}
int F_32 ( T_3 V_68 , struct V_69 * V_70 )
{
struct V_63 * V_21 ;
struct V_5 * V_6 ;
unsigned int V_8 ;
F_33 ( & V_38 ) ;
V_8 = F_27 ( V_70 -> V_71 ) ;
V_21 = & V_72 [ V_8 ] ;
F_30 (nh, head, nh_hash) {
if ( V_6 -> V_26 == V_70 &&
V_6 -> V_47 == V_68 &&
! ( V_6 -> V_50 & V_73 ) ) {
F_34 ( & V_38 ) ;
return 0 ;
}
}
F_34 ( & V_38 ) ;
return - 1 ;
}
static inline T_4 F_35 ( struct V_22 * V_23 )
{
T_4 V_74 = F_36 ( sizeof( struct V_75 ) )
+ F_37 ( 4 )
+ F_37 ( 4 )
+ F_37 ( 4 )
+ F_37 ( 4 )
+ F_37 ( V_76 ) ;
V_74 += F_37 ( ( V_66 * F_37 ( 4 ) ) ) ;
if ( V_23 -> V_57 ) {
T_4 V_77 = F_37 ( sizeof( struct V_78 ) ) ;
V_77 += 2 * F_37 ( 4 ) ;
V_74 += F_37 ( V_23 -> V_57 * V_77 ) ;
}
return V_74 ;
}
void F_38 ( int V_79 , T_3 V_80 , struct V_81 * V_82 ,
int V_83 , V_30 V_84 , const struct V_85 * V_86 ,
unsigned int V_87 )
{
struct V_88 * V_89 ;
V_30 V_90 = V_86 -> V_91 ? V_86 -> V_91 -> V_92 : 0 ;
int V_93 = - V_94 ;
V_89 = F_39 ( F_35 ( V_82 -> V_95 ) , V_96 ) ;
if ( ! V_89 )
goto V_97;
V_93 = F_40 ( V_89 , V_86 -> V_98 , V_90 , V_79 , V_84 ,
V_82 -> V_99 , V_80 , V_83 ,
V_82 -> V_100 , V_82 -> V_95 , V_87 ) ;
if ( V_93 < 0 ) {
F_41 ( V_93 == - V_101 ) ;
F_42 ( V_89 ) ;
goto V_97;
}
F_43 ( V_89 , V_86 -> V_102 , V_86 -> V_98 , V_103 ,
V_86 -> V_91 , V_96 ) ;
return;
V_97:
if ( V_93 < 0 )
F_44 ( V_86 -> V_102 , V_103 , V_93 ) ;
}
static int F_45 ( struct V_22 * V_23 , int V_104 ,
struct V_22 * * V_105 , int * V_106 ,
int V_107 )
{
struct V_108 * V_109 ;
int V_110 = V_111 ;
V_109 = F_46 ( & V_112 , & V_23 -> V_5 [ 0 ] . V_47 , V_23 -> V_113 ) ;
if ( V_109 ) {
V_110 = V_109 -> V_114 ;
F_47 ( V_109 ) ;
}
if ( V_110 == V_115 )
return 0 ;
if ( ( V_110 & V_116 ) && V_104 != V_107 )
return 0 ;
if ( ( V_110 & V_116 ) ||
( * V_106 < 0 && V_104 > V_107 ) ) {
* V_105 = V_23 ;
* V_106 = V_104 ;
}
return 1 ;
}
static int F_48 ( struct V_78 * V_117 , int V_118 )
{
int V_119 = 0 ;
while ( F_49 ( V_117 , V_118 ) ) {
V_119 ++ ;
V_117 = F_50 ( V_117 , & V_118 ) ;
}
return V_118 > 0 ? 0 : V_119 ;
}
static int F_51 ( struct V_22 * V_23 , struct V_78 * V_117 ,
int V_118 , struct V_120 * V_121 )
{
F_12 (fi) {
int V_122 ;
if ( ! F_49 ( V_117 , V_118 ) )
return - V_123 ;
V_25 -> V_50 =
( V_121 -> V_124 & ~ 0xFF ) | V_117 -> V_125 ;
V_25 -> V_46 = V_117 -> V_126 ;
V_25 -> V_49 = V_117 -> V_127 + 1 ;
V_122 = F_52 ( V_117 ) ;
if ( V_122 > 0 ) {
struct V_128 * V_129 , * V_130 = F_53 ( V_117 ) ;
V_129 = F_54 ( V_130 , V_122 , V_131 ) ;
V_25 -> V_47 = V_129 ? F_55 ( V_129 ) : 0 ;
#ifdef F_17
V_129 = F_54 ( V_130 , V_122 , V_132 ) ;
V_25 -> V_34 = V_129 ? F_56 ( V_129 ) : 0 ;
if ( V_25 -> V_34 )
V_23 -> V_35 -> V_36 . V_37 ++ ;
#endif
}
V_117 = F_50 ( V_117 , & V_118 ) ;
} F_14 ( V_23 ) ;
return 0 ;
}
int F_57 ( struct V_120 * V_121 , struct V_22 * V_23 )
{
#ifdef F_26
struct V_78 * V_117 ;
int V_118 ;
#endif
if ( V_121 -> V_133 && V_121 -> V_133 != V_23 -> V_61 )
return 1 ;
if ( V_121 -> V_134 || V_121 -> V_135 ) {
if ( ( ! V_121 -> V_134 || V_121 -> V_134 == V_23 -> V_5 -> V_46 ) &&
( ! V_121 -> V_135 || V_121 -> V_135 == V_23 -> V_5 -> V_47 ) )
return 0 ;
return 1 ;
}
#ifdef F_26
if ( ! V_121 -> V_136 )
return 0 ;
V_117 = V_121 -> V_136 ;
V_118 = V_121 -> V_137 ;
F_25 (fi) {
int V_122 ;
if ( ! F_49 ( V_117 , V_118 ) )
return - V_123 ;
if ( V_117 -> V_126 && V_117 -> V_126 != V_6 -> V_46 )
return 1 ;
V_122 = F_52 ( V_117 ) ;
if ( V_122 > 0 ) {
struct V_128 * V_129 , * V_130 = F_53 ( V_117 ) ;
V_129 = F_54 ( V_130 , V_122 , V_131 ) ;
if ( V_129 && F_55 ( V_129 ) != V_6 -> V_47 )
return 1 ;
#ifdef F_17
V_129 = F_54 ( V_130 , V_122 , V_132 ) ;
if ( V_129 && F_56 ( V_129 ) != V_6 -> V_34 )
return 1 ;
#endif
}
V_117 = F_50 ( V_117 , & V_118 ) ;
} F_14 ( V_23 ) ;
#endif
return 0 ;
}
static int F_58 ( struct V_120 * V_121 , struct V_22 * V_23 ,
struct V_5 * V_6 )
{
int V_93 ;
struct V_138 * V_138 ;
struct V_69 * V_70 ;
V_138 = V_121 -> V_139 . V_102 ;
if ( V_6 -> V_47 ) {
struct V_140 V_141 ;
if ( V_6 -> V_50 & V_142 ) {
if ( V_121 -> V_143 >= V_144 )
return - V_123 ;
if ( F_59 ( V_138 , V_6 -> V_47 ) != V_145 )
return - V_123 ;
V_70 = F_60 ( V_138 , V_6 -> V_46 ) ;
if ( ! V_70 )
return - V_146 ;
if ( ! ( V_70 -> V_147 & V_148 ) )
return - V_149 ;
if ( ! F_61 ( V_70 ) )
V_6 -> V_50 |= V_150 ;
V_6 -> V_26 = V_70 ;
F_62 ( V_70 ) ;
V_6 -> V_48 = V_144 ;
return 0 ;
}
F_63 () ;
{
struct V_151 V_152 = {
. V_153 = V_6 -> V_47 ,
. V_154 = V_121 -> V_143 + 1 ,
. V_155 = V_6 -> V_46 ,
. V_156 = V_157 ,
} ;
if ( V_152 . V_154 < V_144 )
V_152 . V_154 = V_144 ;
V_93 = F_64 ( V_138 , & V_152 , & V_141 ,
V_158 ) ;
if ( V_93 ) {
F_65 () ;
return V_93 ;
}
}
V_93 = - V_123 ;
if ( V_141 . type != V_145 && V_141 . type != V_159 )
goto V_160;
V_6 -> V_48 = V_141 . V_161 ;
V_6 -> V_46 = F_66 ( V_141 ) ;
V_6 -> V_26 = V_70 = F_67 ( V_141 ) ;
if ( ! V_70 )
goto V_160;
F_62 ( V_70 ) ;
if ( ! F_61 ( V_70 ) )
V_6 -> V_50 |= V_150 ;
V_93 = ( V_70 -> V_147 & V_148 ) ? 0 : - V_149 ;
} else {
struct V_162 * V_163 ;
if ( V_6 -> V_50 & ( V_164 | V_142 ) )
return - V_123 ;
F_63 () ;
V_93 = - V_146 ;
V_163 = F_68 ( V_138 , V_6 -> V_46 ) ;
if ( ! V_163 )
goto V_160;
V_93 = - V_149 ;
if ( ! ( V_163 -> V_70 -> V_147 & V_148 ) )
goto V_160;
V_6 -> V_26 = V_163 -> V_70 ;
F_62 ( V_6 -> V_26 ) ;
V_6 -> V_48 = V_165 ;
if ( ! F_61 ( V_6 -> V_26 ) )
V_6 -> V_50 |= V_150 ;
V_93 = 0 ;
}
V_160:
F_65 () ;
return V_93 ;
}
static inline unsigned int F_69 ( T_3 V_52 )
{
unsigned int V_53 = ( V_56 - 1 ) ;
return ( ( V_60 V_30 ) V_52 ^
( ( V_60 V_30 ) V_52 >> 7 ) ^
( ( V_60 V_30 ) V_52 >> 14 ) ) & V_53 ;
}
static struct V_63 * F_70 ( int V_166 )
{
if ( V_166 <= V_167 )
return F_71 ( V_166 , V_96 ) ;
else
return (struct V_63 * )
F_72 ( V_96 | V_168 ,
F_73 ( V_166 ) ) ;
}
static void F_74 ( struct V_63 * V_8 , int V_166 )
{
if ( ! V_8 )
return;
if ( V_166 <= V_167 )
F_5 ( V_8 ) ;
else
F_75 ( ( unsigned long ) V_8 , F_73 ( V_166 ) ) ;
}
static void F_76 ( struct V_63 * V_169 ,
struct V_63 * V_170 ,
unsigned int V_171 )
{
struct V_63 * V_172 , * V_173 ;
unsigned int V_174 = V_56 ;
unsigned int V_9 , V_166 ;
F_20 ( & V_38 ) ;
V_172 = V_64 ;
V_173 = V_175 ;
V_56 = V_171 ;
for ( V_9 = 0 ; V_9 < V_174 ; V_9 ++ ) {
struct V_63 * V_21 = & V_64 [ V_9 ] ;
struct V_176 * V_109 ;
struct V_22 * V_23 ;
F_77 (fi, n, head, fib_hash) {
struct V_63 * V_177 ;
unsigned int V_178 ;
V_178 = F_28 ( V_23 ) ;
V_177 = & V_169 [ V_178 ] ;
F_78 ( & V_23 -> V_40 , V_177 ) ;
}
}
V_64 = V_169 ;
for ( V_9 = 0 ; V_9 < V_174 ; V_9 ++ ) {
struct V_63 * V_179 = & V_175 [ V_9 ] ;
struct V_176 * V_109 ;
struct V_22 * V_23 ;
F_77 (fi, n, lhead, fib_lhash) {
struct V_63 * V_180 ;
unsigned int V_178 ;
V_178 = F_69 ( V_23 -> V_41 ) ;
V_180 = & V_170 [ V_178 ] ;
F_78 ( & V_23 -> V_42 , V_180 ) ;
}
}
V_175 = V_170 ;
F_23 ( & V_38 ) ;
V_166 = V_174 * sizeof( struct V_63 * ) ;
F_74 ( V_172 , V_166 ) ;
F_74 ( V_173 , V_166 ) ;
}
T_3 F_79 ( struct V_138 * V_138 , struct V_5 * V_6 )
{
V_6 -> V_181 = F_80 ( V_6 -> V_26 ,
V_6 -> V_47 ,
V_6 -> V_182 -> V_59 ) ;
V_6 -> V_183 = F_81 ( & V_138 -> V_36 . V_184 ) ;
return V_6 -> V_181 ;
}
struct V_22 * F_82 ( struct V_120 * V_121 )
{
int V_93 ;
struct V_22 * V_23 = NULL ;
struct V_22 * V_44 ;
int V_119 = 1 ;
struct V_138 * V_138 = V_121 -> V_139 . V_102 ;
if ( V_121 -> V_185 > V_186 )
goto V_187;
if ( V_188 [ V_121 -> V_185 ] . V_161 > V_121 -> V_143 )
goto V_187;
#ifdef F_26
if ( V_121 -> V_136 ) {
V_119 = F_48 ( V_121 -> V_136 , V_121 -> V_137 ) ;
if ( V_119 == 0 )
goto V_187;
}
#endif
V_93 = - V_94 ;
if ( V_33 >= V_56 ) {
unsigned int V_171 = V_56 << 1 ;
struct V_63 * V_169 ;
struct V_63 * V_170 ;
unsigned int V_166 ;
if ( ! V_171 )
V_171 = 16 ;
V_166 = V_171 * sizeof( struct V_63 * ) ;
V_169 = F_70 ( V_166 ) ;
V_170 = F_70 ( V_166 ) ;
if ( ! V_169 || ! V_170 ) {
F_74 ( V_169 , V_166 ) ;
F_74 ( V_170 , V_166 ) ;
} else
F_76 ( V_169 , V_170 , V_171 ) ;
if ( ! V_56 )
goto V_189;
}
V_23 = F_71 ( sizeof( * V_23 ) + V_119 * sizeof( struct V_5 ) , V_96 ) ;
if ( ! V_23 )
goto V_189;
V_33 ++ ;
if ( V_121 -> V_190 ) {
V_23 -> V_29 = F_71 ( sizeof( V_30 ) * V_66 , V_96 ) ;
if ( ! V_23 -> V_29 )
goto V_189;
} else
V_23 -> V_29 = ( V_30 * ) V_31 ;
V_23 -> V_35 = V_138 ;
V_23 -> V_58 = V_121 -> V_191 ;
V_23 -> V_59 = V_121 -> V_143 ;
V_23 -> V_67 = V_121 -> V_124 ;
V_23 -> V_61 = V_121 -> V_133 ;
V_23 -> V_41 = V_121 -> V_192 ;
V_23 -> V_65 = V_121 -> V_185 ;
V_23 -> V_57 = V_119 ;
F_12 (fi) {
V_25 -> V_182 = V_23 ;
V_25 -> V_27 = F_83 (struct rtable __rcu *) ;
if ( ! V_25 -> V_27 )
goto V_189;
} F_14 (fi)
if ( V_121 -> V_190 ) {
struct V_128 * V_129 ;
int V_118 ;
F_84 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_85 ( V_129 ) ;
if ( type ) {
V_30 V_52 ;
if ( type > V_66 )
goto V_187;
if ( type == V_193 ) {
char V_194 [ V_76 ] ;
F_86 ( V_194 , V_129 , sizeof( V_194 ) ) ;
V_52 = F_87 ( V_194 ) ;
if ( V_52 == V_195 )
goto V_187;
} else {
V_52 = F_56 ( V_129 ) ;
}
if ( type == V_196 && V_52 > 65535 - 40 )
V_52 = 65535 - 40 ;
if ( type == V_197 && V_52 > 65535 - 15 )
V_52 = 65535 - 15 ;
V_23 -> V_29 [ type - 1 ] = V_52 ;
}
}
}
if ( V_121 -> V_136 ) {
#ifdef F_26
V_93 = F_51 ( V_23 , V_121 -> V_136 , V_121 -> V_137 , V_121 ) ;
if ( V_93 != 0 )
goto V_189;
if ( V_121 -> V_134 && V_23 -> V_5 -> V_46 != V_121 -> V_134 )
goto V_187;
if ( V_121 -> V_135 && V_23 -> V_5 -> V_47 != V_121 -> V_135 )
goto V_187;
#ifdef F_17
if ( V_121 -> V_198 && V_23 -> V_5 -> V_34 != V_121 -> V_198 )
goto V_187;
#endif
#else
goto V_187;
#endif
} else {
struct V_5 * V_6 = V_23 -> V_5 ;
V_6 -> V_46 = V_121 -> V_134 ;
V_6 -> V_47 = V_121 -> V_135 ;
V_6 -> V_50 = V_121 -> V_124 ;
#ifdef F_17
V_6 -> V_34 = V_121 -> V_198 ;
if ( V_6 -> V_34 )
V_23 -> V_35 -> V_36 . V_37 ++ ;
#endif
#ifdef F_26
V_6 -> V_49 = 1 ;
#endif
}
if ( V_188 [ V_121 -> V_185 ] . error ) {
if ( V_121 -> V_135 || V_121 -> V_134 || V_121 -> V_136 )
goto V_187;
goto V_199;
} else {
switch ( V_121 -> V_185 ) {
case V_145 :
case V_159 :
case V_200 :
case V_201 :
case V_202 :
break;
default:
goto V_187;
}
}
if ( V_121 -> V_143 > V_165 )
goto V_187;
if ( V_121 -> V_143 == V_165 ) {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_119 != 1 || V_6 -> V_47 )
goto V_187;
V_6 -> V_48 = V_203 ;
V_6 -> V_26 = F_88 ( V_138 , V_23 -> V_5 -> V_46 ) ;
V_93 = - V_146 ;
if ( ! V_6 -> V_26 )
goto V_189;
} else {
int V_204 = 0 ;
F_12 (fi) {
V_93 = F_58 ( V_121 , V_23 , V_25 ) ;
if ( V_93 != 0 )
goto V_189;
if ( V_25 -> V_50 & V_150 )
V_204 ++ ;
} F_14 (fi)
if ( V_204 == V_23 -> V_57 )
V_23 -> V_67 |= V_150 ;
}
if ( V_23 -> V_41 ) {
if ( V_121 -> V_185 != V_159 || ! V_121 -> V_205 ||
V_23 -> V_41 != V_121 -> V_205 )
if ( F_59 ( V_138 , V_23 -> V_41 ) != V_159 )
goto V_187;
}
F_12 (fi) {
F_79 ( V_138 , V_25 ) ;
} F_14 (fi)
V_199:
V_44 = F_29 ( V_23 ) ;
if ( V_44 ) {
V_23 -> V_32 = 1 ;
F_15 ( V_23 ) ;
V_44 -> V_39 ++ ;
return V_44 ;
}
V_23 -> V_39 ++ ;
F_89 ( & V_23 -> V_206 ) ;
F_20 ( & V_38 ) ;
F_78 ( & V_23 -> V_40 ,
& V_64 [ F_28 ( V_23 ) ] ) ;
if ( V_23 -> V_41 ) {
struct V_63 * V_21 ;
V_21 = & V_175 [ F_69 ( V_23 -> V_41 ) ] ;
F_78 ( & V_23 -> V_42 , V_21 ) ;
}
F_12 (fi) {
struct V_63 * V_21 ;
unsigned int V_8 ;
if ( ! V_25 -> V_26 )
continue;
V_8 = F_27 ( V_25 -> V_26 -> V_71 ) ;
V_21 = & V_72 [ V_8 ] ;
F_78 ( & V_25 -> V_43 , V_21 ) ;
} F_14 (fi)
F_23 ( & V_38 ) ;
return V_23 ;
V_187:
V_93 = - V_123 ;
V_189:
if ( V_23 ) {
V_23 -> V_32 = 1 ;
F_15 ( V_23 ) ;
}
return F_90 ( V_93 ) ;
}
int F_40 ( struct V_88 * V_89 , V_30 V_98 , V_30 V_90 , int V_79 ,
V_30 V_84 , T_5 type , T_3 V_4 , int V_83 , T_5 V_207 ,
struct V_22 * V_23 , unsigned int V_147 )
{
struct V_208 * V_91 ;
struct V_75 * V_209 ;
V_91 = F_91 ( V_89 , V_98 , V_90 , V_79 , sizeof( * V_209 ) , V_147 ) ;
if ( ! V_91 )
return - V_101 ;
V_209 = F_92 ( V_91 ) ;
V_209 -> V_210 = V_211 ;
V_209 -> V_212 = V_83 ;
V_209 -> V_213 = 0 ;
V_209 -> V_214 = V_207 ;
if ( V_84 < 256 )
V_209 -> V_215 = V_84 ;
else
V_209 -> V_215 = V_216 ;
if ( F_93 ( V_89 , V_217 , V_84 ) )
goto V_218;
V_209 -> V_219 = type ;
V_209 -> V_220 = V_23 -> V_67 ;
V_209 -> V_221 = V_23 -> V_59 ;
V_209 -> V_222 = V_23 -> V_58 ;
if ( V_209 -> V_212 &&
F_94 ( V_89 , V_223 , V_4 ) )
goto V_218;
if ( V_23 -> V_61 &&
F_93 ( V_89 , V_224 , V_23 -> V_61 ) )
goto V_218;
if ( F_95 ( V_89 , V_23 -> V_29 ) < 0 )
goto V_218;
if ( V_23 -> V_41 &&
F_94 ( V_89 , V_225 , V_23 -> V_41 ) )
goto V_218;
if ( V_23 -> V_57 == 1 ) {
struct V_162 * V_163 ;
if ( V_23 -> V_5 -> V_47 &&
F_94 ( V_89 , V_131 , V_23 -> V_5 -> V_47 ) )
goto V_218;
if ( V_23 -> V_5 -> V_46 &&
F_93 ( V_89 , V_226 , V_23 -> V_5 -> V_46 ) )
goto V_218;
if ( V_23 -> V_5 -> V_50 & V_150 ) {
V_163 = F_96 ( V_23 -> V_5 -> V_26 ) ;
if ( V_163 &&
F_97 ( V_163 ) )
V_209 -> V_220 |= V_73 ;
}
#ifdef F_17
if ( V_23 -> V_5 [ 0 ] . V_34 &&
F_93 ( V_89 , V_132 , V_23 -> V_5 [ 0 ] . V_34 ) )
goto V_218;
#endif
}
#ifdef F_26
if ( V_23 -> V_57 > 1 ) {
struct V_78 * V_117 ;
struct V_128 * V_227 ;
V_227 = F_98 ( V_89 , V_228 ) ;
if ( ! V_227 )
goto V_218;
F_25 (fi) {
struct V_162 * V_163 ;
V_117 = F_99 ( V_89 , sizeof( * V_117 ) ) ;
if ( ! V_117 )
goto V_218;
V_117 -> V_125 = V_6 -> V_50 & 0xFF ;
if ( V_6 -> V_50 & V_150 ) {
V_163 = F_96 ( V_6 -> V_26 ) ;
if ( V_163 &&
F_97 ( V_163 ) )
V_117 -> V_125 |= V_73 ;
}
V_117 -> V_127 = V_6 -> V_49 - 1 ;
V_117 -> V_126 = V_6 -> V_46 ;
if ( V_6 -> V_47 &&
F_94 ( V_89 , V_131 , V_6 -> V_47 ) )
goto V_218;
#ifdef F_17
if ( V_6 -> V_34 &&
F_93 ( V_89 , V_132 , V_6 -> V_34 ) )
goto V_218;
#endif
V_117 -> V_229 = F_100 ( V_89 ) - ( void * ) V_117 ;
} F_14 ( V_23 ) ;
F_101 ( V_89 , V_227 ) ;
}
#endif
F_102 ( V_89 , V_91 ) ;
return 0 ;
V_218:
F_103 ( V_89 , V_91 ) ;
return - V_101 ;
}
int F_104 ( struct V_138 * V_138 , T_3 V_230 )
{
int V_231 = 0 ;
unsigned int V_8 = F_69 ( V_230 ) ;
struct V_63 * V_21 = & V_175 [ V_8 ] ;
struct V_22 * V_23 ;
if ( ! V_175 || V_230 == 0 )
return 0 ;
F_30 (fi, head, fib_lhash) {
if ( ! F_31 ( V_23 -> V_35 , V_138 ) )
continue;
if ( V_23 -> V_41 == V_230 ) {
V_23 -> V_67 |= V_73 ;
V_231 ++ ;
}
}
return V_231 ;
}
int F_105 ( struct V_69 * V_70 , unsigned long V_79 )
{
int V_231 = 0 ;
int V_161 = V_203 ;
struct V_22 * V_232 = NULL ;
unsigned int V_8 = F_27 ( V_70 -> V_71 ) ;
struct V_63 * V_21 = & V_72 [ V_8 ] ;
struct V_5 * V_6 ;
if ( V_79 == V_233 ||
V_79 == V_234 )
V_161 = - 1 ;
F_30 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_182 ;
int V_235 ;
F_106 ( ! V_23 -> V_57 ) ;
if ( V_6 -> V_26 != V_70 || V_23 == V_232 )
continue;
V_232 = V_23 ;
V_235 = 0 ;
F_12 (fi) {
if ( V_25 -> V_50 & V_73 )
V_235 ++ ;
else if ( V_25 -> V_26 == V_70 &&
V_25 -> V_48 != V_161 ) {
switch ( V_79 ) {
case V_234 :
case V_233 :
V_25 -> V_50 |= V_73 ;
case V_236 :
V_25 -> V_50 |= V_150 ;
break;
}
#ifdef F_26
F_20 ( & V_237 ) ;
V_23 -> V_238 -= V_25 -> V_239 ;
V_25 -> V_239 = 0 ;
F_23 ( & V_237 ) ;
#endif
V_235 ++ ;
}
#ifdef F_26
if ( V_79 == V_233 &&
V_25 -> V_26 == V_70 ) {
V_235 = V_23 -> V_57 ;
break;
}
#endif
} F_14 (fi)
if ( V_235 == V_23 -> V_57 ) {
switch ( V_79 ) {
case V_234 :
case V_233 :
V_23 -> V_67 |= V_73 ;
case V_236 :
V_23 -> V_67 |= V_150 ;
break;
}
V_231 ++ ;
}
}
return V_231 ;
}
void F_107 ( const struct V_151 * V_240 , struct V_140 * V_141 )
{
struct V_22 * V_23 = NULL , * V_105 = NULL ;
struct V_63 * V_241 = V_141 -> V_241 ;
struct V_242 * V_243 = V_141 -> V_244 ;
T_5 V_245 = 32 - V_141 -> V_246 ;
int V_104 = - 1 , V_106 = - 1 ;
struct V_81 * V_82 , * V_247 = NULL ;
V_30 V_248 = V_141 -> V_23 -> V_61 ;
T_5 V_249 = 0 ;
F_108 (fa, fa_head, fa_list) {
struct V_22 * V_250 = V_82 -> V_95 ;
if ( V_82 -> V_251 != V_245 )
continue;
if ( V_82 -> V_100 && V_82 -> V_100 != V_240 -> V_252 )
continue;
if ( V_82 -> V_84 != V_243 -> V_84 )
continue;
if ( V_250 -> V_61 > V_248 &&
V_82 -> V_100 == V_249 ) {
if ( V_249 )
continue;
break;
}
if ( V_250 -> V_67 & V_73 )
continue;
V_249 = V_82 -> V_100 ;
V_248 = V_250 -> V_61 ;
if ( V_250 -> V_59 != V_141 -> V_161 ||
V_82 -> V_99 != V_145 )
continue;
if ( ! V_250 -> V_5 [ 0 ] . V_47 ||
V_250 -> V_5 [ 0 ] . V_48 != V_144 )
continue;
F_109 ( V_82 ) ;
if ( ! V_23 ) {
if ( V_250 != V_141 -> V_23 )
break;
V_247 = V_82 ;
} else if ( ! F_45 ( V_23 , V_104 , & V_105 ,
& V_106 , V_247 -> V_253 ) ) {
F_110 ( V_141 , V_23 ) ;
V_247 -> V_253 = V_104 ;
goto V_160;
}
V_23 = V_250 ;
V_104 ++ ;
}
if ( V_104 <= 0 || ! V_23 ) {
if ( V_247 )
V_247 -> V_253 = - 1 ;
goto V_160;
}
if ( ! F_45 ( V_23 , V_104 , & V_105 , & V_106 ,
V_247 -> V_253 ) ) {
F_110 ( V_141 , V_23 ) ;
V_247 -> V_253 = V_104 ;
goto V_160;
}
if ( V_106 >= 0 )
F_110 ( V_141 , V_105 ) ;
V_247 -> V_253 = V_106 ;
V_160:
return;
}
int F_111 ( struct V_69 * V_70 , unsigned int V_50 )
{
struct V_22 * V_232 ;
unsigned int V_8 ;
struct V_63 * V_21 ;
struct V_5 * V_6 ;
int V_231 ;
if ( ! ( V_70 -> V_147 & V_148 ) )
return 0 ;
V_232 = NULL ;
V_8 = F_27 ( V_70 -> V_71 ) ;
V_21 = & V_72 [ V_8 ] ;
V_231 = 0 ;
F_30 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_182 ;
int V_254 ;
F_106 ( ! V_23 -> V_57 ) ;
if ( V_6 -> V_26 != V_70 || V_23 == V_232 )
continue;
V_232 = V_23 ;
V_254 = 0 ;
F_12 (fi) {
if ( ! ( V_25 -> V_50 & V_50 ) ) {
V_254 ++ ;
continue;
}
if ( ! V_25 -> V_26 ||
! ( V_25 -> V_26 -> V_147 & V_148 ) )
continue;
if ( V_25 -> V_26 != V_70 ||
! F_96 ( V_70 ) )
continue;
V_254 ++ ;
#ifdef F_26
F_20 ( & V_237 ) ;
V_25 -> V_239 = 0 ;
V_25 -> V_50 &= ~ V_50 ;
F_23 ( & V_237 ) ;
#else
V_25 -> V_50 &= ~ V_50 ;
#endif
} F_14 (fi)
if ( V_254 > 0 ) {
V_23 -> V_67 &= ~ V_50 ;
V_231 ++ ;
}
}
return V_231 ;
}
void F_112 ( struct V_140 * V_141 )
{
struct V_22 * V_23 = V_141 -> V_23 ;
struct V_162 * V_163 ;
int V_255 ;
F_20 ( & V_237 ) ;
if ( V_23 -> V_238 <= 0 ) {
int V_256 = 0 ;
F_12 (fi) {
V_163 = F_113 ( V_25 -> V_26 ) ;
if ( V_25 -> V_50 & V_73 )
continue;
if ( V_163 &&
F_97 ( V_163 ) &&
V_25 -> V_50 & V_150 )
continue;
V_256 += V_25 -> V_49 ;
V_25 -> V_239 = V_25 -> V_49 ;
} F_14 ( V_23 ) ;
V_23 -> V_238 = V_256 ;
if ( V_256 <= 0 ) {
F_23 ( & V_237 ) ;
V_141 -> V_257 = 0 ;
return;
}
}
V_255 = V_258 % V_23 -> V_238 ;
F_12 (fi) {
if ( ! ( V_25 -> V_50 & V_73 ) &&
V_25 -> V_239 ) {
V_255 -= V_25 -> V_239 ;
if ( V_255 <= 0 ) {
V_25 -> V_239 -- ;
V_23 -> V_238 -- ;
V_141 -> V_257 = V_259 ;
F_23 ( & V_237 ) ;
return;
}
}
} F_14 ( V_23 ) ;
V_141 -> V_257 = 0 ;
F_23 ( & V_237 ) ;
}
