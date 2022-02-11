static void F_1 ( struct V_1 T_1 * * V_2 )
{
struct V_1 * V_3 = F_2 ( * V_2 , 1 ) ;
if ( ! V_3 )
return;
F_3 ( & V_3 -> V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_12 * V_13 ;
V_13 = F_2 ( V_8 [ V_10 ] . V_14 , 1 ) ;
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
if ( V_25 -> V_9 )
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
+ F_38 ( 4 ) ;
V_73 += F_38 ( ( V_66 * F_38 ( 4 ) ) ) ;
if ( V_23 -> V_57 ) {
T_4 V_75 = F_38 ( sizeof( struct V_76 ) ) ;
V_75 += 2 * F_38 ( 4 ) ;
V_73 += F_38 ( V_23 -> V_57 * V_75 ) ;
}
return V_73 ;
}
void F_39 ( int V_77 , T_3 V_78 , struct V_79 * V_80 ,
int V_81 , V_31 V_82 , struct V_83 * V_84 ,
unsigned int V_85 )
{
struct V_86 * V_87 ;
V_31 V_88 = V_84 -> V_89 ? V_84 -> V_89 -> V_90 : 0 ;
int V_91 = - V_92 ;
V_87 = F_40 ( F_36 ( V_80 -> V_93 ) , V_94 ) ;
if ( V_87 == NULL )
goto V_95;
V_91 = F_41 ( V_87 , V_84 -> V_96 , V_88 , V_77 , V_82 ,
V_80 -> V_97 , V_78 , V_81 ,
V_80 -> V_98 , V_80 -> V_93 , V_85 ) ;
if ( V_91 < 0 ) {
F_42 ( V_91 == - V_99 ) ;
F_43 ( V_87 ) ;
goto V_95;
}
F_44 ( V_87 , V_84 -> V_100 , V_84 -> V_96 , V_101 ,
V_84 -> V_89 , V_94 ) ;
return;
V_95:
if ( V_91 < 0 )
F_45 ( V_84 -> V_100 , V_101 , V_91 ) ;
}
struct V_79 * F_46 ( struct V_102 * V_103 , T_5 V_104 , V_31 V_105 )
{
if ( V_103 ) {
struct V_79 * V_80 ;
F_47 (fa, fah, fa_list) {
if ( V_80 -> V_98 > V_104 )
continue;
if ( V_80 -> V_93 -> V_61 >= V_105 ||
V_80 -> V_98 < V_104 )
return V_80 ;
}
}
return NULL ;
}
int F_48 ( struct V_22 * V_23 , int V_106 ,
struct V_22 * * V_107 , int * V_108 , int V_109 )
{
struct V_110 * V_111 ;
int V_112 = V_113 ;
V_111 = F_49 ( & V_114 , & V_23 -> V_5 [ 0 ] . V_47 , V_23 -> V_115 ) ;
if ( V_111 ) {
V_112 = V_111 -> V_116 ;
F_50 ( V_111 ) ;
}
if ( V_112 == V_117 )
return 0 ;
if ( ( V_112 & V_118 ) && V_106 != V_109 )
return 0 ;
if ( ( V_112 & V_118 ) ||
( * V_108 < 0 && V_106 > V_109 ) ) {
* V_107 = V_23 ;
* V_108 = V_106 ;
}
return 1 ;
}
static int F_51 ( struct V_76 * V_119 , int V_120 )
{
int V_121 = 0 ;
while ( F_52 ( V_119 , V_120 ) ) {
V_121 ++ ;
V_119 = F_53 ( V_119 , & V_120 ) ;
}
return V_120 > 0 ? 0 : V_121 ;
}
static int F_54 ( struct V_22 * V_23 , struct V_76 * V_119 ,
int V_120 , struct V_122 * V_123 )
{
F_12 (fi) {
int V_124 ;
if ( ! F_52 ( V_119 , V_120 ) )
return - V_125 ;
V_25 -> V_50 =
( V_123 -> V_126 & ~ 0xFF ) | V_119 -> V_127 ;
V_25 -> V_46 = V_119 -> V_128 ;
V_25 -> V_49 = V_119 -> V_129 + 1 ;
V_124 = F_55 ( V_119 ) ;
if ( V_124 > 0 ) {
struct V_130 * V_131 , * V_132 = F_56 ( V_119 ) ;
V_131 = F_57 ( V_132 , V_124 , V_133 ) ;
V_25 -> V_47 = V_131 ? F_58 ( V_131 ) : 0 ;
#ifdef F_18
V_131 = F_57 ( V_132 , V_124 , V_134 ) ;
V_25 -> V_35 = V_131 ? F_59 ( V_131 ) : 0 ;
if ( V_25 -> V_35 )
V_23 -> V_29 -> V_36 . V_37 ++ ;
#endif
}
V_119 = F_53 ( V_119 , & V_120 ) ;
} F_14 ( V_23 ) ;
return 0 ;
}
int F_60 ( struct V_122 * V_123 , struct V_22 * V_23 )
{
#ifdef F_27
struct V_76 * V_119 ;
int V_120 ;
#endif
if ( V_123 -> V_135 && V_123 -> V_135 != V_23 -> V_61 )
return 1 ;
if ( V_123 -> V_136 || V_123 -> V_137 ) {
if ( ( ! V_123 -> V_136 || V_123 -> V_136 == V_23 -> V_5 -> V_46 ) &&
( ! V_123 -> V_137 || V_123 -> V_137 == V_23 -> V_5 -> V_47 ) )
return 0 ;
return 1 ;
}
#ifdef F_27
if ( V_123 -> V_138 == NULL )
return 0 ;
V_119 = V_123 -> V_138 ;
V_120 = V_123 -> V_139 ;
F_26 (fi) {
int V_124 ;
if ( ! F_52 ( V_119 , V_120 ) )
return - V_125 ;
if ( V_119 -> V_128 && V_119 -> V_128 != V_6 -> V_46 )
return 1 ;
V_124 = F_55 ( V_119 ) ;
if ( V_124 < 0 ) {
struct V_130 * V_131 , * V_132 = F_56 ( V_119 ) ;
V_131 = F_57 ( V_132 , V_124 , V_133 ) ;
if ( V_131 && F_58 ( V_131 ) != V_6 -> V_47 )
return 1 ;
#ifdef F_18
V_131 = F_57 ( V_132 , V_124 , V_134 ) ;
if ( V_131 && F_59 ( V_131 ) != V_6 -> V_35 )
return 1 ;
#endif
}
V_119 = F_53 ( V_119 , & V_120 ) ;
} F_14 ( V_23 ) ;
#endif
return 0 ;
}
static int F_61 ( struct V_122 * V_123 , struct V_22 * V_23 ,
struct V_5 * V_6 )
{
int V_91 ;
struct V_140 * V_140 ;
struct V_69 * V_70 ;
V_140 = V_123 -> V_141 . V_100 ;
if ( V_6 -> V_47 ) {
struct V_142 V_143 ;
if ( V_6 -> V_50 & V_144 ) {
if ( V_123 -> V_145 >= V_146 )
return - V_125 ;
if ( F_62 ( V_140 , V_6 -> V_47 ) != V_147 )
return - V_125 ;
V_70 = F_63 ( V_140 , V_6 -> V_46 ) ;
if ( ! V_70 )
return - V_148 ;
if ( ! ( V_70 -> V_149 & V_150 ) )
return - V_151 ;
V_6 -> V_26 = V_70 ;
F_64 ( V_70 ) ;
V_6 -> V_48 = V_146 ;
return 0 ;
}
F_65 () ;
{
struct V_152 V_153 = {
. V_154 = V_6 -> V_47 ,
. V_155 = V_123 -> V_145 + 1 ,
. V_156 = V_6 -> V_46 ,
} ;
if ( V_153 . V_155 < V_146 )
V_153 . V_155 = V_146 ;
V_91 = F_66 ( V_140 , & V_153 , & V_143 ) ;
if ( V_91 ) {
F_67 () ;
return V_91 ;
}
}
V_91 = - V_125 ;
if ( V_143 . type != V_147 && V_143 . type != V_157 )
goto V_158;
V_6 -> V_48 = V_143 . V_159 ;
V_6 -> V_46 = F_68 ( V_143 ) ;
V_6 -> V_26 = V_70 = F_69 ( V_143 ) ;
if ( ! V_70 )
goto V_158;
F_64 ( V_70 ) ;
V_91 = ( V_70 -> V_149 & V_150 ) ? 0 : - V_151 ;
} else {
struct V_160 * V_161 ;
if ( V_6 -> V_50 & ( V_162 | V_144 ) )
return - V_125 ;
F_65 () ;
V_91 = - V_148 ;
V_161 = F_70 ( V_140 , V_6 -> V_46 ) ;
if ( V_161 == NULL )
goto V_158;
V_91 = - V_151 ;
if ( ! ( V_161 -> V_70 -> V_149 & V_150 ) )
goto V_158;
V_6 -> V_26 = V_161 -> V_70 ;
F_64 ( V_6 -> V_26 ) ;
V_6 -> V_48 = V_163 ;
V_91 = 0 ;
}
V_158:
F_67 () ;
return V_91 ;
}
static inline unsigned int F_71 ( T_3 V_52 )
{
unsigned int V_53 = ( V_56 - 1 ) ;
return ( ( V_60 V_31 ) V_52 ^
( ( V_60 V_31 ) V_52 >> 7 ) ^
( ( V_60 V_31 ) V_52 >> 14 ) ) & V_53 ;
}
static struct V_63 * F_72 ( int V_164 )
{
if ( V_164 <= V_165 )
return F_73 ( V_164 , V_94 ) ;
else
return (struct V_63 * )
F_74 ( V_94 | V_166 ,
F_75 ( V_164 ) ) ;
}
static void F_76 ( struct V_63 * V_8 , int V_164 )
{
if ( ! V_8 )
return;
if ( V_164 <= V_165 )
F_5 ( V_8 ) ;
else
F_77 ( ( unsigned long ) V_8 , F_75 ( V_164 ) ) ;
}
static void F_78 ( struct V_63 * V_167 ,
struct V_63 * V_168 ,
unsigned int V_169 )
{
struct V_63 * V_170 , * V_171 ;
unsigned int V_172 = V_56 ;
unsigned int V_10 , V_164 ;
F_21 ( & V_38 ) ;
V_170 = V_64 ;
V_171 = V_173 ;
V_56 = V_169 ;
for ( V_10 = 0 ; V_10 < V_172 ; V_10 ++ ) {
struct V_63 * V_21 = & V_64 [ V_10 ] ;
struct V_174 * V_111 ;
struct V_22 * V_23 ;
F_79 (fi, n, head, fib_hash) {
struct V_63 * V_175 ;
unsigned int V_176 ;
F_22 ( & V_23 -> V_40 ) ;
V_176 = F_29 ( V_23 ) ;
V_175 = & V_167 [ V_176 ] ;
F_80 ( & V_23 -> V_40 , V_175 ) ;
}
}
V_64 = V_167 ;
for ( V_10 = 0 ; V_10 < V_172 ; V_10 ++ ) {
struct V_63 * V_177 = & V_173 [ V_10 ] ;
struct V_174 * V_111 ;
struct V_22 * V_23 ;
F_79 (fi, n, lhead, fib_lhash) {
struct V_63 * V_178 ;
unsigned int V_176 ;
F_22 ( & V_23 -> V_42 ) ;
V_176 = F_71 ( V_23 -> V_41 ) ;
V_178 = & V_168 [ V_176 ] ;
F_80 ( & V_23 -> V_42 , V_178 ) ;
}
}
V_173 = V_168 ;
F_24 ( & V_38 ) ;
V_164 = V_172 * sizeof( struct V_63 * ) ;
F_76 ( V_170 , V_164 ) ;
F_76 ( V_171 , V_164 ) ;
}
T_3 F_81 ( struct V_140 * V_140 , struct V_5 * V_6 )
{
V_6 -> V_179 = F_82 ( V_6 -> V_26 ,
V_6 -> V_47 ,
V_6 -> V_180 -> V_59 ) ;
V_6 -> V_181 = F_83 ( & V_140 -> V_36 . V_182 ) ;
return V_6 -> V_179 ;
}
struct V_22 * F_84 ( struct V_122 * V_123 )
{
int V_91 ;
struct V_22 * V_23 = NULL ;
struct V_22 * V_44 ;
int V_121 = 1 ;
struct V_140 * V_140 = V_123 -> V_141 . V_100 ;
if ( V_123 -> V_183 > V_184 )
goto V_185;
if ( V_186 [ V_123 -> V_183 ] . V_159 > V_123 -> V_145 )
goto V_185;
#ifdef F_27
if ( V_123 -> V_138 ) {
V_121 = F_51 ( V_123 -> V_138 , V_123 -> V_139 ) ;
if ( V_121 == 0 )
goto V_185;
}
#endif
V_91 = - V_92 ;
if ( V_34 >= V_56 ) {
unsigned int V_169 = V_56 << 1 ;
struct V_63 * V_167 ;
struct V_63 * V_168 ;
unsigned int V_164 ;
if ( ! V_169 )
V_169 = 16 ;
V_164 = V_169 * sizeof( struct V_63 * ) ;
V_167 = F_72 ( V_164 ) ;
V_168 = F_72 ( V_164 ) ;
if ( ! V_167 || ! V_168 ) {
F_76 ( V_167 , V_164 ) ;
F_76 ( V_168 , V_164 ) ;
} else
F_78 ( V_167 , V_168 , V_169 ) ;
if ( ! V_56 )
goto V_187;
}
V_23 = F_73 ( sizeof( * V_23 ) + V_121 * sizeof( struct V_5 ) , V_94 ) ;
if ( V_23 == NULL )
goto V_187;
if ( V_123 -> V_188 ) {
V_23 -> V_30 = F_73 ( sizeof( V_31 ) * V_66 , V_94 ) ;
if ( ! V_23 -> V_30 )
goto V_187;
} else
V_23 -> V_30 = ( V_31 * ) V_32 ;
V_34 ++ ;
V_23 -> V_29 = F_85 ( V_140 ) ;
V_23 -> V_58 = V_123 -> V_189 ;
V_23 -> V_59 = V_123 -> V_145 ;
V_23 -> V_67 = V_123 -> V_126 ;
V_23 -> V_61 = V_123 -> V_135 ;
V_23 -> V_41 = V_123 -> V_190 ;
V_23 -> V_65 = V_123 -> V_183 ;
V_23 -> V_57 = V_121 ;
F_12 (fi) {
V_25 -> V_180 = V_23 ;
V_25 -> V_27 = F_86 (struct rtable __rcu *) ;
if ( ! V_25 -> V_27 )
goto V_187;
} F_14 (fi)
if ( V_123 -> V_188 ) {
struct V_130 * V_131 ;
int V_120 ;
F_87 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_88 ( V_131 ) ;
if ( type ) {
V_31 V_52 ;
if ( type > V_66 )
goto V_185;
V_52 = F_59 ( V_131 ) ;
if ( type == V_191 && V_52 > 65535 - 40 )
V_52 = 65535 - 40 ;
if ( type == V_192 && V_52 > 65535 - 15 )
V_52 = 65535 - 15 ;
V_23 -> V_30 [ type - 1 ] = V_52 ;
}
}
}
if ( V_123 -> V_138 ) {
#ifdef F_27
V_91 = F_54 ( V_23 , V_123 -> V_138 , V_123 -> V_139 , V_123 ) ;
if ( V_91 != 0 )
goto V_187;
if ( V_123 -> V_136 && V_23 -> V_5 -> V_46 != V_123 -> V_136 )
goto V_185;
if ( V_123 -> V_137 && V_23 -> V_5 -> V_47 != V_123 -> V_137 )
goto V_185;
#ifdef F_18
if ( V_123 -> V_193 && V_23 -> V_5 -> V_35 != V_123 -> V_193 )
goto V_185;
#endif
#else
goto V_185;
#endif
} else {
struct V_5 * V_6 = V_23 -> V_5 ;
V_6 -> V_46 = V_123 -> V_136 ;
V_6 -> V_47 = V_123 -> V_137 ;
V_6 -> V_50 = V_123 -> V_126 ;
#ifdef F_18
V_6 -> V_35 = V_123 -> V_193 ;
if ( V_6 -> V_35 )
V_23 -> V_29 -> V_36 . V_37 ++ ;
#endif
#ifdef F_27
V_6 -> V_49 = 1 ;
#endif
}
if ( V_186 [ V_123 -> V_183 ] . error ) {
if ( V_123 -> V_137 || V_123 -> V_136 || V_123 -> V_138 )
goto V_185;
goto V_194;
} else {
switch ( V_123 -> V_183 ) {
case V_147 :
case V_157 :
case V_195 :
case V_196 :
case V_197 :
break;
default:
goto V_185;
}
}
if ( V_123 -> V_145 > V_163 )
goto V_185;
if ( V_123 -> V_145 == V_163 ) {
struct V_5 * V_6 = V_23 -> V_5 ;
if ( V_121 != 1 || V_6 -> V_47 )
goto V_185;
V_6 -> V_48 = V_198 ;
V_6 -> V_26 = F_89 ( V_140 , V_23 -> V_5 -> V_46 ) ;
V_91 = - V_148 ;
if ( V_6 -> V_26 == NULL )
goto V_187;
} else {
F_12 (fi) {
V_91 = F_61 ( V_123 , V_23 , V_25 ) ;
if ( V_91 != 0 )
goto V_187;
} F_14 (fi)
}
if ( V_23 -> V_41 ) {
if ( V_123 -> V_183 != V_157 || ! V_123 -> V_199 ||
V_23 -> V_41 != V_123 -> V_199 )
if ( F_62 ( V_140 , V_23 -> V_41 ) != V_157 )
goto V_185;
}
F_12 (fi) {
F_81 ( V_140 , V_25 ) ;
} F_14 (fi)
V_194:
V_44 = F_30 ( V_23 ) ;
if ( V_44 ) {
V_23 -> V_33 = 1 ;
F_16 ( V_23 ) ;
V_44 -> V_39 ++ ;
return V_44 ;
}
V_23 -> V_39 ++ ;
F_90 ( & V_23 -> V_200 ) ;
F_21 ( & V_38 ) ;
F_80 ( & V_23 -> V_40 ,
& V_64 [ F_29 ( V_23 ) ] ) ;
if ( V_23 -> V_41 ) {
struct V_63 * V_21 ;
V_21 = & V_173 [ F_71 ( V_23 -> V_41 ) ] ;
F_80 ( & V_23 -> V_42 , V_21 ) ;
}
F_12 (fi) {
struct V_63 * V_21 ;
unsigned int V_8 ;
if ( ! V_25 -> V_26 )
continue;
V_8 = F_28 ( V_25 -> V_26 -> V_71 ) ;
V_21 = & V_72 [ V_8 ] ;
F_80 ( & V_25 -> V_43 , V_21 ) ;
} F_14 (fi)
F_24 ( & V_38 ) ;
return V_23 ;
V_185:
V_91 = - V_125 ;
V_187:
if ( V_23 ) {
V_23 -> V_33 = 1 ;
F_16 ( V_23 ) ;
}
return F_91 ( V_91 ) ;
}
int F_41 ( struct V_86 * V_87 , V_31 V_96 , V_31 V_88 , int V_77 ,
V_31 V_82 , T_5 type , T_3 V_4 , int V_81 , T_5 V_104 ,
struct V_22 * V_23 , unsigned int V_149 )
{
struct V_201 * V_89 ;
struct V_74 * V_202 ;
V_89 = F_92 ( V_87 , V_96 , V_88 , V_77 , sizeof( * V_202 ) , V_149 ) ;
if ( V_89 == NULL )
return - V_99 ;
V_202 = F_93 ( V_89 ) ;
V_202 -> V_203 = V_204 ;
V_202 -> V_205 = V_81 ;
V_202 -> V_206 = 0 ;
V_202 -> V_207 = V_104 ;
if ( V_82 < 256 )
V_202 -> V_208 = V_82 ;
else
V_202 -> V_208 = V_209 ;
if ( F_94 ( V_87 , V_210 , V_82 ) )
goto V_211;
V_202 -> V_212 = type ;
V_202 -> V_213 = V_23 -> V_67 ;
V_202 -> V_214 = V_23 -> V_59 ;
V_202 -> V_215 = V_23 -> V_58 ;
if ( V_202 -> V_205 &&
F_95 ( V_87 , V_216 , V_4 ) )
goto V_211;
if ( V_23 -> V_61 &&
F_94 ( V_87 , V_217 , V_23 -> V_61 ) )
goto V_211;
if ( F_96 ( V_87 , V_23 -> V_30 ) < 0 )
goto V_211;
if ( V_23 -> V_41 &&
F_95 ( V_87 , V_218 , V_23 -> V_41 ) )
goto V_211;
if ( V_23 -> V_57 == 1 ) {
if ( V_23 -> V_5 -> V_47 &&
F_95 ( V_87 , V_133 , V_23 -> V_5 -> V_47 ) )
goto V_211;
if ( V_23 -> V_5 -> V_46 &&
F_94 ( V_87 , V_219 , V_23 -> V_5 -> V_46 ) )
goto V_211;
#ifdef F_18
if ( V_23 -> V_5 [ 0 ] . V_35 &&
F_94 ( V_87 , V_134 , V_23 -> V_5 [ 0 ] . V_35 ) )
goto V_211;
#endif
}
#ifdef F_27
if ( V_23 -> V_57 > 1 ) {
struct V_76 * V_119 ;
struct V_130 * V_220 ;
V_220 = F_97 ( V_87 , V_221 ) ;
if ( V_220 == NULL )
goto V_211;
F_26 (fi) {
V_119 = F_98 ( V_87 , sizeof( * V_119 ) ) ;
if ( V_119 == NULL )
goto V_211;
V_119 -> V_127 = V_6 -> V_50 & 0xFF ;
V_119 -> V_129 = V_6 -> V_49 - 1 ;
V_119 -> V_128 = V_6 -> V_46 ;
if ( V_6 -> V_47 &&
F_95 ( V_87 , V_133 , V_6 -> V_47 ) )
goto V_211;
#ifdef F_18
if ( V_6 -> V_35 &&
F_94 ( V_87 , V_134 , V_6 -> V_35 ) )
goto V_211;
#endif
V_119 -> V_222 = F_99 ( V_87 ) - ( void * ) V_119 ;
} F_14 ( V_23 ) ;
F_100 ( V_87 , V_220 ) ;
}
#endif
return F_101 ( V_87 , V_89 ) ;
V_211:
F_102 ( V_87 , V_89 ) ;
return - V_99 ;
}
int F_103 ( struct V_140 * V_140 , T_3 V_223 )
{
int V_224 = 0 ;
unsigned int V_8 = F_71 ( V_223 ) ;
struct V_63 * V_21 = & V_173 [ V_8 ] ;
struct V_22 * V_23 ;
if ( V_173 == NULL || V_223 == 0 )
return 0 ;
F_31 (fi, head, fib_lhash) {
if ( ! F_32 ( V_23 -> V_29 , V_140 ) )
continue;
if ( V_23 -> V_41 == V_223 ) {
V_23 -> V_67 |= V_51 ;
V_224 ++ ;
}
}
return V_224 ;
}
int F_104 ( struct V_69 * V_70 , int V_225 )
{
int V_224 = 0 ;
int V_159 = V_198 ;
struct V_22 * V_226 = NULL ;
unsigned int V_8 = F_28 ( V_70 -> V_71 ) ;
struct V_63 * V_21 = & V_72 [ V_8 ] ;
struct V_5 * V_6 ;
if ( V_225 )
V_159 = - 1 ;
F_31 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_180 ;
int V_227 ;
F_105 ( ! V_23 -> V_57 ) ;
if ( V_6 -> V_26 != V_70 || V_23 == V_226 )
continue;
V_226 = V_23 ;
V_227 = 0 ;
F_12 (fi) {
if ( V_25 -> V_50 & V_51 )
V_227 ++ ;
else if ( V_25 -> V_26 == V_70 &&
V_25 -> V_48 != V_159 ) {
V_25 -> V_50 |= V_51 ;
#ifdef F_27
F_21 ( & V_228 ) ;
V_23 -> V_229 -= V_25 -> V_230 ;
V_25 -> V_230 = 0 ;
F_24 ( & V_228 ) ;
#endif
V_227 ++ ;
}
#ifdef F_27
if ( V_225 > 1 && V_25 -> V_26 == V_70 ) {
V_227 = V_23 -> V_57 ;
break;
}
#endif
} F_14 (fi)
if ( V_227 == V_23 -> V_57 ) {
V_23 -> V_67 |= V_51 ;
V_224 ++ ;
}
}
return V_224 ;
}
void F_106 ( struct V_142 * V_143 )
{
struct V_22 * V_23 = NULL , * V_107 = NULL ;
struct V_102 * V_231 = V_143 -> V_231 ;
struct V_232 * V_233 = V_143 -> V_234 ;
int V_106 = - 1 , V_108 = - 1 ;
struct V_79 * V_80 ;
F_107 (fa, fa_head, fa_list) {
struct V_22 * V_235 = V_80 -> V_93 ;
if ( V_235 -> V_59 != V_143 -> V_159 ||
V_80 -> V_97 != V_147 )
continue;
if ( V_235 -> V_61 > V_143 -> V_23 -> V_61 )
break;
if ( ! V_235 -> V_5 [ 0 ] . V_47 ||
V_235 -> V_5 [ 0 ] . V_48 != V_146 )
continue;
F_108 ( V_80 ) ;
if ( V_23 == NULL ) {
if ( V_235 != V_143 -> V_23 )
break;
} else if ( ! F_48 ( V_23 , V_106 , & V_107 ,
& V_108 , V_233 -> V_236 ) ) {
F_109 ( V_143 , V_23 ) ;
V_233 -> V_236 = V_106 ;
goto V_158;
}
V_23 = V_235 ;
V_106 ++ ;
}
if ( V_106 <= 0 || V_23 == NULL ) {
V_233 -> V_236 = - 1 ;
goto V_158;
}
if ( ! F_48 ( V_23 , V_106 , & V_107 , & V_108 ,
V_233 -> V_236 ) ) {
F_109 ( V_143 , V_23 ) ;
V_233 -> V_236 = V_106 ;
goto V_158;
}
if ( V_108 >= 0 )
F_109 ( V_143 , V_107 ) ;
V_233 -> V_236 = V_108 ;
V_158:
return;
}
int F_110 ( struct V_69 * V_70 )
{
struct V_22 * V_226 ;
unsigned int V_8 ;
struct V_63 * V_21 ;
struct V_5 * V_6 ;
int V_224 ;
if ( ! ( V_70 -> V_149 & V_150 ) )
return 0 ;
V_226 = NULL ;
V_8 = F_28 ( V_70 -> V_71 ) ;
V_21 = & V_72 [ V_8 ] ;
V_224 = 0 ;
F_31 (nh, head, nh_hash) {
struct V_22 * V_23 = V_6 -> V_180 ;
int V_237 ;
F_105 ( ! V_23 -> V_57 ) ;
if ( V_6 -> V_26 != V_70 || V_23 == V_226 )
continue;
V_226 = V_23 ;
V_237 = 0 ;
F_12 (fi) {
if ( ! ( V_25 -> V_50 & V_51 ) ) {
V_237 ++ ;
continue;
}
if ( V_25 -> V_26 == NULL ||
! ( V_25 -> V_26 -> V_149 & V_150 ) )
continue;
if ( V_25 -> V_26 != V_70 ||
! F_111 ( V_70 ) )
continue;
V_237 ++ ;
F_21 ( & V_228 ) ;
V_25 -> V_230 = 0 ;
V_25 -> V_50 &= ~ V_51 ;
F_24 ( & V_228 ) ;
} F_14 (fi)
if ( V_237 > 0 ) {
V_23 -> V_67 &= ~ V_51 ;
V_224 ++ ;
}
}
return V_224 ;
}
void F_112 ( struct V_142 * V_143 )
{
struct V_22 * V_23 = V_143 -> V_23 ;
int V_238 ;
F_21 ( & V_228 ) ;
if ( V_23 -> V_229 <= 0 ) {
int V_239 = 0 ;
F_12 (fi) {
if ( ! ( V_25 -> V_50 & V_51 ) ) {
V_239 += V_25 -> V_49 ;
V_25 -> V_230 = V_25 -> V_49 ;
}
} F_14 ( V_23 ) ;
V_23 -> V_229 = V_239 ;
if ( V_239 <= 0 ) {
F_24 ( & V_228 ) ;
V_143 -> V_240 = 0 ;
return;
}
}
V_238 = V_241 % V_23 -> V_229 ;
F_12 (fi) {
if ( ! ( V_25 -> V_50 & V_51 ) &&
V_25 -> V_230 ) {
V_238 -= V_25 -> V_230 ;
if ( V_238 <= 0 ) {
V_25 -> V_230 -- ;
V_23 -> V_229 -- ;
V_143 -> V_240 = V_242 ;
F_24 ( & V_228 ) ;
return;
}
}
} F_14 ( V_23 ) ;
V_143 -> V_240 = 0 ;
F_24 ( & V_228 ) ;
}
