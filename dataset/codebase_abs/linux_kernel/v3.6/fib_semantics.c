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
F_5 ( V_13 ) ;
V_13 = V_15 ;
}
}
F_5 ( V_8 ) ;
}
static void F_6 ( struct V_1 T_1 * T_2 * V_2 )
{
int V_18 ;
if ( ! V_2 )
return;
F_7 (cpu) {
struct V_1 * V_3 ;
V_3 = F_2 ( * F_8 ( V_2 , V_18 ) , 1 ) ;
if ( V_3 )
F_3 ( & V_3 -> V_4 ) ;
}
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_11 ( V_20 , struct V_21 , V_23 ) ;
F_12 (fi) {
if ( V_24 -> V_25 )
F_13 ( V_24 -> V_25 ) ;
if ( V_24 -> V_9 )
F_4 ( V_24 ) ;
F_6 ( V_24 -> V_26 ) ;
F_1 ( & V_24 -> V_27 ) ;
} F_14 ( V_22 ) ;
F_15 ( V_22 -> V_28 ) ;
if ( V_22 -> V_29 != ( V_30 * ) V_31 )
F_5 ( V_22 -> V_29 ) ;
F_5 ( V_22 ) ;
}
void F_16 ( struct V_21 * V_22 )
{
if ( V_22 -> V_32 == 0 ) {
F_17 ( L_1 , V_22 ) ;
return;
}
V_33 -- ;
#ifdef F_18
F_12 (fi) {
if ( V_24 -> V_34 )
V_22 -> V_28 -> V_35 . V_36 -- ;
} F_14 ( V_22 ) ;
#endif
F_19 ( & V_22 -> V_23 , F_10 ) ;
}
void F_20 ( struct V_21 * V_22 )
{
F_21 ( & V_37 ) ;
if ( V_22 && -- V_22 -> V_38 == 0 ) {
F_22 ( & V_22 -> V_39 ) ;
if ( V_22 -> V_40 )
F_22 ( & V_22 -> V_41 ) ;
F_12 (fi) {
if ( ! V_24 -> V_25 )
continue;
F_22 ( & V_24 -> V_42 ) ;
} F_14 (fi)
V_22 -> V_32 = 1 ;
F_23 ( V_22 ) ;
}
F_24 ( & V_37 ) ;
}
static inline int F_25 ( const struct V_21 * V_22 , const struct V_21 * V_43 )
{
const struct V_5 * V_44 = V_43 -> V_5 ;
F_26 (fi) {
if ( V_6 -> V_45 != V_44 -> V_45 ||
V_6 -> V_46 != V_44 -> V_46 ||
V_6 -> V_47 != V_44 -> V_47 ||
#ifdef F_27
V_6 -> V_48 != V_44 -> V_48 ||
#endif
#ifdef F_18
V_6 -> V_34 != V_44 -> V_34 ||
#endif
( ( V_6 -> V_49 ^ V_44 -> V_49 ) & ~ V_50 ) )
return - 1 ;
V_44 ++ ;
} F_14 ( V_22 ) ;
return 0 ;
}
static inline unsigned int F_28 ( unsigned int V_51 )
{
unsigned int V_52 = V_53 - 1 ;
return ( V_51 ^
( V_51 >> V_54 ) ^
( V_51 >> ( V_54 * 2 ) ) ) & V_52 ;
}
static inline unsigned int F_29 ( const struct V_21 * V_22 )
{
unsigned int V_52 = ( V_55 - 1 ) ;
unsigned int V_51 = V_22 -> V_56 ;
V_51 ^= ( V_22 -> V_57 << 8 ) | V_22 -> V_58 ;
V_51 ^= ( V_59 V_30 ) V_22 -> V_40 ;
V_51 ^= V_22 -> V_60 ;
F_26 (fi) {
V_51 ^= F_28 ( V_6 -> V_45 ) ;
} F_14 (fi)
return ( V_51 ^ ( V_51 >> 7 ) ^ ( V_51 >> 12 ) ) & V_52 ;
}
static struct V_21 * F_30 ( const struct V_21 * V_61 )
{
struct V_62 * V_20 ;
struct V_63 * V_64 ;
struct V_21 * V_22 ;
unsigned int V_8 ;
V_8 = F_29 ( V_61 ) ;
V_20 = & V_65 [ V_8 ] ;
F_31 (fi, node, head, fib_hash) {
if ( ! F_32 ( V_22 -> V_28 , V_61 -> V_28 ) )
continue;
if ( V_22 -> V_56 != V_61 -> V_56 )
continue;
if ( V_61 -> V_57 == V_22 -> V_57 &&
V_61 -> V_58 == V_22 -> V_58 &&
V_61 -> V_40 == V_22 -> V_40 &&
V_61 -> V_60 == V_22 -> V_60 &&
memcmp ( V_61 -> V_29 , V_22 -> V_29 ,
sizeof( V_30 ) * V_66 ) == 0 &&
( ( V_61 -> V_67 ^ V_22 -> V_67 ) & ~ V_50 ) == 0 &&
( V_61 -> V_56 == 0 || F_25 ( V_22 , V_61 ) == 0 ) )
return V_22 ;
}
return NULL ;
}
int F_33 ( T_3 V_68 , struct V_69 * V_70 )
{
struct V_62 * V_20 ;
struct V_63 * V_64 ;
struct V_5 * V_6 ;
unsigned int V_8 ;
F_34 ( & V_37 ) ;
V_8 = F_28 ( V_70 -> V_71 ) ;
V_20 = & V_72 [ V_8 ] ;
F_31 (nh, node, head, nh_hash) {
if ( V_6 -> V_25 == V_70 &&
V_6 -> V_46 == V_68 &&
! ( V_6 -> V_49 & V_50 ) ) {
F_35 ( & V_37 ) ;
return 0 ;
}
}
F_35 ( & V_37 ) ;
return - 1 ;
}
static inline T_4 F_36 ( struct V_21 * V_22 )
{
T_4 V_73 = F_37 ( sizeof( struct V_74 ) )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 ) ;
V_73 += F_38 ( ( V_66 * F_38 ( 4 ) ) ) ;
if ( V_22 -> V_56 ) {
T_4 V_75 = F_38 ( sizeof( struct V_76 ) ) ;
V_75 += 2 * F_38 ( 4 ) ;
V_73 += F_38 ( V_22 -> V_56 * V_75 ) ;
}
return V_73 ;
}
void F_39 ( int V_77 , T_3 V_78 , struct V_79 * V_80 ,
int V_81 , V_30 V_82 , struct V_83 * V_84 ,
unsigned int V_85 )
{
struct V_86 * V_87 ;
V_30 V_88 = V_84 -> V_89 ? V_84 -> V_89 -> V_90 : 0 ;
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
struct V_79 * F_46 ( struct V_102 * V_103 , T_5 V_104 , V_30 V_105 )
{
if ( V_103 ) {
struct V_79 * V_80 ;
F_47 (fa, fah, fa_list) {
if ( V_80 -> V_98 > V_104 )
continue;
if ( V_80 -> V_93 -> V_60 >= V_105 ||
V_80 -> V_98 < V_104 )
return V_80 ;
}
}
return NULL ;
}
int F_48 ( struct V_21 * V_22 , int V_106 ,
struct V_21 * * V_107 , int * V_108 , int V_109 )
{
struct V_110 * V_111 ;
int V_112 = V_113 ;
V_111 = F_49 ( & V_114 , & V_22 -> V_5 [ 0 ] . V_46 , V_22 -> V_115 ) ;
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
* V_107 = V_22 ;
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
static int F_54 ( struct V_21 * V_22 , struct V_76 * V_119 ,
int V_120 , struct V_122 * V_123 )
{
F_12 (fi) {
int V_124 ;
if ( ! F_52 ( V_119 , V_120 ) )
return - V_125 ;
V_24 -> V_49 =
( V_123 -> V_126 & ~ 0xFF ) | V_119 -> V_127 ;
V_24 -> V_45 = V_119 -> V_128 ;
V_24 -> V_48 = V_119 -> V_129 + 1 ;
V_124 = F_55 ( V_119 ) ;
if ( V_124 > 0 ) {
struct V_130 * V_131 , * V_132 = F_56 ( V_119 ) ;
V_131 = F_57 ( V_132 , V_124 , V_133 ) ;
V_24 -> V_46 = V_131 ? F_58 ( V_131 ) : 0 ;
#ifdef F_18
V_131 = F_57 ( V_132 , V_124 , V_134 ) ;
V_24 -> V_34 = V_131 ? F_59 ( V_131 ) : 0 ;
if ( V_24 -> V_34 )
V_22 -> V_28 -> V_35 . V_36 ++ ;
#endif
}
V_119 = F_53 ( V_119 , & V_120 ) ;
} F_14 ( V_22 ) ;
return 0 ;
}
int F_60 ( struct V_122 * V_123 , struct V_21 * V_22 )
{
#ifdef F_27
struct V_76 * V_119 ;
int V_120 ;
#endif
if ( V_123 -> V_135 && V_123 -> V_135 != V_22 -> V_60 )
return 1 ;
if ( V_123 -> V_136 || V_123 -> V_137 ) {
if ( ( ! V_123 -> V_136 || V_123 -> V_136 == V_22 -> V_5 -> V_45 ) &&
( ! V_123 -> V_137 || V_123 -> V_137 == V_22 -> V_5 -> V_46 ) )
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
if ( V_119 -> V_128 && V_119 -> V_128 != V_6 -> V_45 )
return 1 ;
V_124 = F_55 ( V_119 ) ;
if ( V_124 < 0 ) {
struct V_130 * V_131 , * V_132 = F_56 ( V_119 ) ;
V_131 = F_57 ( V_132 , V_124 , V_133 ) ;
if ( V_131 && F_58 ( V_131 ) != V_6 -> V_46 )
return 1 ;
#ifdef F_18
V_131 = F_57 ( V_132 , V_124 , V_134 ) ;
if ( V_131 && F_59 ( V_131 ) != V_6 -> V_34 )
return 1 ;
#endif
}
V_119 = F_53 ( V_119 , & V_120 ) ;
} F_14 ( V_22 ) ;
#endif
return 0 ;
}
static int F_61 ( struct V_122 * V_123 , struct V_21 * V_22 ,
struct V_5 * V_6 )
{
int V_91 ;
struct V_140 * V_140 ;
struct V_69 * V_70 ;
V_140 = V_123 -> V_141 . V_100 ;
if ( V_6 -> V_46 ) {
struct V_142 V_143 ;
if ( V_6 -> V_49 & V_144 ) {
if ( V_123 -> V_145 >= V_146 )
return - V_125 ;
if ( F_62 ( V_140 , V_6 -> V_46 ) != V_147 )
return - V_125 ;
V_70 = F_63 ( V_140 , V_6 -> V_45 ) ;
if ( ! V_70 )
return - V_148 ;
if ( ! ( V_70 -> V_149 & V_150 ) )
return - V_151 ;
V_6 -> V_25 = V_70 ;
F_64 ( V_70 ) ;
V_6 -> V_47 = V_146 ;
return 0 ;
}
F_65 () ;
{
struct V_152 V_153 = {
. V_154 = V_6 -> V_46 ,
. V_155 = V_123 -> V_145 + 1 ,
. V_156 = V_6 -> V_45 ,
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
V_6 -> V_47 = V_143 . V_159 ;
V_6 -> V_45 = F_68 ( V_143 ) ;
V_6 -> V_25 = V_70 = F_69 ( V_143 ) ;
if ( ! V_70 )
goto V_158;
F_64 ( V_70 ) ;
V_91 = ( V_70 -> V_149 & V_150 ) ? 0 : - V_151 ;
} else {
struct V_160 * V_161 ;
if ( V_6 -> V_49 & ( V_162 | V_144 ) )
return - V_125 ;
F_65 () ;
V_91 = - V_148 ;
V_161 = F_70 ( V_140 , V_6 -> V_45 ) ;
if ( V_161 == NULL )
goto V_158;
V_91 = - V_151 ;
if ( ! ( V_161 -> V_70 -> V_149 & V_150 ) )
goto V_158;
V_6 -> V_25 = V_161 -> V_70 ;
F_64 ( V_6 -> V_25 ) ;
V_6 -> V_47 = V_163 ;
V_91 = 0 ;
}
V_158:
F_67 () ;
return V_91 ;
}
static inline unsigned int F_71 ( T_3 V_51 )
{
unsigned int V_52 = ( V_55 - 1 ) ;
return ( ( V_59 V_30 ) V_51 ^
( ( V_59 V_30 ) V_51 >> 7 ) ^
( ( V_59 V_30 ) V_51 >> 14 ) ) & V_52 ;
}
static struct V_62 * F_72 ( int V_164 )
{
if ( V_164 <= V_165 )
return F_73 ( V_164 , V_94 ) ;
else
return (struct V_62 * )
F_74 ( V_94 | V_166 ,
F_75 ( V_164 ) ) ;
}
static void F_76 ( struct V_62 * V_8 , int V_164 )
{
if ( ! V_8 )
return;
if ( V_164 <= V_165 )
F_5 ( V_8 ) ;
else
F_77 ( ( unsigned long ) V_8 , F_75 ( V_164 ) ) ;
}
static void F_78 ( struct V_62 * V_167 ,
struct V_62 * V_168 ,
unsigned int V_169 )
{
struct V_62 * V_170 , * V_171 ;
unsigned int V_172 = V_55 ;
unsigned int V_10 , V_164 ;
F_21 ( & V_37 ) ;
V_170 = V_65 ;
V_171 = V_173 ;
V_55 = V_169 ;
for ( V_10 = 0 ; V_10 < V_172 ; V_10 ++ ) {
struct V_62 * V_20 = & V_65 [ V_10 ] ;
struct V_63 * V_64 , * V_111 ;
struct V_21 * V_22 ;
F_79 (fi, node, n, head, fib_hash) {
struct V_62 * V_174 ;
unsigned int V_175 ;
F_22 ( & V_22 -> V_39 ) ;
V_175 = F_29 ( V_22 ) ;
V_174 = & V_167 [ V_175 ] ;
F_80 ( & V_22 -> V_39 , V_174 ) ;
}
}
V_65 = V_167 ;
for ( V_10 = 0 ; V_10 < V_172 ; V_10 ++ ) {
struct V_62 * V_176 = & V_173 [ V_10 ] ;
struct V_63 * V_64 , * V_111 ;
struct V_21 * V_22 ;
F_79 (fi, node, n, lhead, fib_lhash) {
struct V_62 * V_177 ;
unsigned int V_175 ;
F_22 ( & V_22 -> V_41 ) ;
V_175 = F_71 ( V_22 -> V_40 ) ;
V_177 = & V_168 [ V_175 ] ;
F_80 ( & V_22 -> V_41 , V_177 ) ;
}
}
V_173 = V_168 ;
F_24 ( & V_37 ) ;
V_164 = V_172 * sizeof( struct V_62 * ) ;
F_76 ( V_170 , V_164 ) ;
F_76 ( V_171 , V_164 ) ;
}
T_3 F_81 ( struct V_140 * V_140 , struct V_5 * V_6 )
{
V_6 -> V_178 = F_82 ( V_6 -> V_25 ,
V_6 -> V_46 ,
V_6 -> V_179 -> V_58 ) ;
V_6 -> V_180 = F_83 ( & V_140 -> V_35 . V_181 ) ;
return V_6 -> V_178 ;
}
struct V_21 * F_84 ( struct V_122 * V_123 )
{
int V_91 ;
struct V_21 * V_22 = NULL ;
struct V_21 * V_43 ;
int V_121 = 1 ;
struct V_140 * V_140 = V_123 -> V_141 . V_100 ;
if ( V_123 -> V_182 > V_183 )
goto V_184;
if ( V_185 [ V_123 -> V_182 ] . V_159 > V_123 -> V_145 )
goto V_184;
#ifdef F_27
if ( V_123 -> V_138 ) {
V_121 = F_51 ( V_123 -> V_138 , V_123 -> V_139 ) ;
if ( V_121 == 0 )
goto V_184;
}
#endif
V_91 = - V_92 ;
if ( V_33 >= V_55 ) {
unsigned int V_169 = V_55 << 1 ;
struct V_62 * V_167 ;
struct V_62 * V_168 ;
unsigned int V_164 ;
if ( ! V_169 )
V_169 = 1 ;
V_164 = V_169 * sizeof( struct V_62 * ) ;
V_167 = F_72 ( V_164 ) ;
V_168 = F_72 ( V_164 ) ;
if ( ! V_167 || ! V_168 ) {
F_76 ( V_167 , V_164 ) ;
F_76 ( V_168 , V_164 ) ;
} else
F_78 ( V_167 , V_168 , V_169 ) ;
if ( ! V_55 )
goto V_186;
}
V_22 = F_73 ( sizeof( * V_22 ) + V_121 * sizeof( struct V_5 ) , V_94 ) ;
if ( V_22 == NULL )
goto V_186;
if ( V_123 -> V_187 ) {
V_22 -> V_29 = F_73 ( sizeof( V_30 ) * V_66 , V_94 ) ;
if ( ! V_22 -> V_29 )
goto V_186;
} else
V_22 -> V_29 = ( V_30 * ) V_31 ;
V_33 ++ ;
V_22 -> V_28 = F_85 ( V_140 ) ;
V_22 -> V_57 = V_123 -> V_188 ;
V_22 -> V_58 = V_123 -> V_145 ;
V_22 -> V_67 = V_123 -> V_126 ;
V_22 -> V_60 = V_123 -> V_135 ;
V_22 -> V_40 = V_123 -> V_189 ;
V_22 -> V_56 = V_121 ;
F_12 (fi) {
V_24 -> V_179 = V_22 ;
V_24 -> V_26 = F_86 (struct rtable __rcu *) ;
} F_14 (fi)
if ( V_123 -> V_187 ) {
struct V_130 * V_131 ;
int V_120 ;
F_87 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_88 ( V_131 ) ;
if ( type ) {
V_30 V_51 ;
if ( type > V_66 )
goto V_184;
V_51 = F_59 ( V_131 ) ;
if ( type == V_190 && V_51 > 65535 - 40 )
V_51 = 65535 - 40 ;
if ( type == V_191 && V_51 > 65535 - 15 )
V_51 = 65535 - 15 ;
V_22 -> V_29 [ type - 1 ] = V_51 ;
}
}
}
if ( V_123 -> V_138 ) {
#ifdef F_27
V_91 = F_54 ( V_22 , V_123 -> V_138 , V_123 -> V_139 , V_123 ) ;
if ( V_91 != 0 )
goto V_186;
if ( V_123 -> V_136 && V_22 -> V_5 -> V_45 != V_123 -> V_136 )
goto V_184;
if ( V_123 -> V_137 && V_22 -> V_5 -> V_46 != V_123 -> V_137 )
goto V_184;
#ifdef F_18
if ( V_123 -> V_192 && V_22 -> V_5 -> V_34 != V_123 -> V_192 )
goto V_184;
#endif
#else
goto V_184;
#endif
} else {
struct V_5 * V_6 = V_22 -> V_5 ;
V_6 -> V_45 = V_123 -> V_136 ;
V_6 -> V_46 = V_123 -> V_137 ;
V_6 -> V_49 = V_123 -> V_126 ;
#ifdef F_18
V_6 -> V_34 = V_123 -> V_192 ;
if ( V_6 -> V_34 )
V_22 -> V_28 -> V_35 . V_36 ++ ;
#endif
#ifdef F_27
V_6 -> V_48 = 1 ;
#endif
}
if ( V_185 [ V_123 -> V_182 ] . error ) {
if ( V_123 -> V_137 || V_123 -> V_136 || V_123 -> V_138 )
goto V_184;
goto V_193;
} else {
switch ( V_123 -> V_182 ) {
case V_147 :
case V_157 :
case V_194 :
case V_195 :
case V_196 :
break;
default:
goto V_184;
}
}
if ( V_123 -> V_145 > V_163 )
goto V_184;
if ( V_123 -> V_145 == V_163 ) {
struct V_5 * V_6 = V_22 -> V_5 ;
if ( V_121 != 1 || V_6 -> V_46 )
goto V_184;
V_6 -> V_47 = V_197 ;
V_6 -> V_25 = F_89 ( V_140 , V_22 -> V_5 -> V_45 ) ;
V_91 = - V_148 ;
if ( V_6 -> V_25 == NULL )
goto V_186;
} else {
F_12 (fi) {
V_91 = F_61 ( V_123 , V_22 , V_24 ) ;
if ( V_91 != 0 )
goto V_186;
} F_14 (fi)
}
if ( V_22 -> V_40 ) {
if ( V_123 -> V_182 != V_157 || ! V_123 -> V_198 ||
V_22 -> V_40 != V_123 -> V_198 )
if ( F_62 ( V_140 , V_22 -> V_40 ) != V_157 )
goto V_184;
}
F_12 (fi) {
F_81 ( V_140 , V_24 ) ;
} F_14 (fi)
V_193:
V_43 = F_30 ( V_22 ) ;
if ( V_43 ) {
V_22 -> V_32 = 1 ;
F_16 ( V_22 ) ;
V_43 -> V_38 ++ ;
return V_43 ;
}
V_22 -> V_38 ++ ;
F_90 ( & V_22 -> V_199 ) ;
F_21 ( & V_37 ) ;
F_80 ( & V_22 -> V_39 ,
& V_65 [ F_29 ( V_22 ) ] ) ;
if ( V_22 -> V_40 ) {
struct V_62 * V_20 ;
V_20 = & V_173 [ F_71 ( V_22 -> V_40 ) ] ;
F_80 ( & V_22 -> V_41 , V_20 ) ;
}
F_12 (fi) {
struct V_62 * V_20 ;
unsigned int V_8 ;
if ( ! V_24 -> V_25 )
continue;
V_8 = F_28 ( V_24 -> V_25 -> V_71 ) ;
V_20 = & V_72 [ V_8 ] ;
F_80 ( & V_24 -> V_42 , V_20 ) ;
} F_14 (fi)
F_24 ( & V_37 ) ;
return V_22 ;
V_184:
V_91 = - V_125 ;
V_186:
if ( V_22 ) {
V_22 -> V_32 = 1 ;
F_16 ( V_22 ) ;
}
return F_91 ( V_91 ) ;
}
int F_41 ( struct V_86 * V_87 , V_30 V_96 , V_30 V_88 , int V_77 ,
V_30 V_82 , T_5 type , T_3 V_4 , int V_81 , T_5 V_104 ,
struct V_21 * V_22 , unsigned int V_149 )
{
struct V_200 * V_89 ;
struct V_74 * V_201 ;
V_89 = F_92 ( V_87 , V_96 , V_88 , V_77 , sizeof( * V_201 ) , V_149 ) ;
if ( V_89 == NULL )
return - V_99 ;
V_201 = F_93 ( V_89 ) ;
V_201 -> V_202 = V_203 ;
V_201 -> V_204 = V_81 ;
V_201 -> V_205 = 0 ;
V_201 -> V_206 = V_104 ;
if ( V_82 < 256 )
V_201 -> V_207 = V_82 ;
else
V_201 -> V_207 = V_208 ;
if ( F_94 ( V_87 , V_209 , V_82 ) )
goto V_210;
V_201 -> V_211 = type ;
V_201 -> V_212 = V_22 -> V_67 ;
V_201 -> V_213 = V_22 -> V_58 ;
V_201 -> V_214 = V_22 -> V_57 ;
if ( V_201 -> V_204 &&
F_95 ( V_87 , V_215 , V_4 ) )
goto V_210;
if ( V_22 -> V_60 &&
F_94 ( V_87 , V_216 , V_22 -> V_60 ) )
goto V_210;
if ( F_96 ( V_87 , V_22 -> V_29 ) < 0 )
goto V_210;
if ( V_22 -> V_40 &&
F_95 ( V_87 , V_217 , V_22 -> V_40 ) )
goto V_210;
if ( V_22 -> V_56 == 1 ) {
if ( V_22 -> V_5 -> V_46 &&
F_95 ( V_87 , V_133 , V_22 -> V_5 -> V_46 ) )
goto V_210;
if ( V_22 -> V_5 -> V_45 &&
F_94 ( V_87 , V_218 , V_22 -> V_5 -> V_45 ) )
goto V_210;
#ifdef F_18
if ( V_22 -> V_5 [ 0 ] . V_34 &&
F_94 ( V_87 , V_134 , V_22 -> V_5 [ 0 ] . V_34 ) )
goto V_210;
#endif
}
#ifdef F_27
if ( V_22 -> V_56 > 1 ) {
struct V_76 * V_119 ;
struct V_130 * V_219 ;
V_219 = F_97 ( V_87 , V_220 ) ;
if ( V_219 == NULL )
goto V_210;
F_26 (fi) {
V_119 = F_98 ( V_87 , sizeof( * V_119 ) ) ;
if ( V_119 == NULL )
goto V_210;
V_119 -> V_127 = V_6 -> V_49 & 0xFF ;
V_119 -> V_129 = V_6 -> V_48 - 1 ;
V_119 -> V_128 = V_6 -> V_45 ;
if ( V_6 -> V_46 &&
F_95 ( V_87 , V_133 , V_6 -> V_46 ) )
goto V_210;
#ifdef F_18
if ( V_6 -> V_34 &&
F_94 ( V_87 , V_134 , V_6 -> V_34 ) )
goto V_210;
#endif
V_119 -> V_221 = F_99 ( V_87 ) - ( void * ) V_119 ;
} F_14 ( V_22 ) ;
F_100 ( V_87 , V_219 ) ;
}
#endif
return F_101 ( V_87 , V_89 ) ;
V_210:
F_102 ( V_87 , V_89 ) ;
return - V_99 ;
}
int F_103 ( struct V_140 * V_140 , T_3 V_222 )
{
int V_223 = 0 ;
unsigned int V_8 = F_71 ( V_222 ) ;
struct V_62 * V_20 = & V_173 [ V_8 ] ;
struct V_63 * V_64 ;
struct V_21 * V_22 ;
if ( V_173 == NULL || V_222 == 0 )
return 0 ;
F_31 (fi, node, head, fib_lhash) {
if ( ! F_32 ( V_22 -> V_28 , V_140 ) )
continue;
if ( V_22 -> V_40 == V_222 ) {
V_22 -> V_67 |= V_50 ;
V_223 ++ ;
}
}
return V_223 ;
}
int F_104 ( struct V_69 * V_70 , int V_224 )
{
int V_223 = 0 ;
int V_159 = V_197 ;
struct V_21 * V_225 = NULL ;
unsigned int V_8 = F_28 ( V_70 -> V_71 ) ;
struct V_62 * V_20 = & V_72 [ V_8 ] ;
struct V_63 * V_64 ;
struct V_5 * V_6 ;
if ( V_224 )
V_159 = - 1 ;
F_31 (nh, node, head, nh_hash) {
struct V_21 * V_22 = V_6 -> V_179 ;
int V_226 ;
F_105 ( ! V_22 -> V_56 ) ;
if ( V_6 -> V_25 != V_70 || V_22 == V_225 )
continue;
V_225 = V_22 ;
V_226 = 0 ;
F_12 (fi) {
if ( V_24 -> V_49 & V_50 )
V_226 ++ ;
else if ( V_24 -> V_25 == V_70 &&
V_24 -> V_47 != V_159 ) {
V_24 -> V_49 |= V_50 ;
#ifdef F_27
F_21 ( & V_227 ) ;
V_22 -> V_228 -= V_24 -> V_229 ;
V_24 -> V_229 = 0 ;
F_24 ( & V_227 ) ;
#endif
V_226 ++ ;
}
#ifdef F_27
if ( V_224 > 1 && V_24 -> V_25 == V_70 ) {
V_226 = V_22 -> V_56 ;
break;
}
#endif
} F_14 (fi)
if ( V_226 == V_22 -> V_56 ) {
V_22 -> V_67 |= V_50 ;
V_223 ++ ;
}
}
return V_223 ;
}
void F_106 ( struct V_142 * V_143 )
{
struct V_21 * V_22 = NULL , * V_107 = NULL ;
struct V_102 * V_230 = V_143 -> V_230 ;
struct V_231 * V_232 = V_143 -> V_233 ;
int V_106 = - 1 , V_108 = - 1 ;
struct V_79 * V_80 ;
F_107 (fa, fa_head, fa_list) {
struct V_21 * V_234 = V_80 -> V_93 ;
if ( V_234 -> V_58 != V_143 -> V_159 ||
V_80 -> V_97 != V_147 )
continue;
if ( V_234 -> V_60 > V_143 -> V_22 -> V_60 )
break;
if ( ! V_234 -> V_5 [ 0 ] . V_46 ||
V_234 -> V_5 [ 0 ] . V_47 != V_146 )
continue;
F_108 ( V_80 ) ;
if ( V_22 == NULL ) {
if ( V_234 != V_143 -> V_22 )
break;
} else if ( ! F_48 ( V_22 , V_106 , & V_107 ,
& V_108 , V_232 -> V_235 ) ) {
F_109 ( V_143 , V_22 ) ;
V_232 -> V_235 = V_106 ;
goto V_158;
}
V_22 = V_234 ;
V_106 ++ ;
}
if ( V_106 <= 0 || V_22 == NULL ) {
V_232 -> V_235 = - 1 ;
goto V_158;
}
if ( ! F_48 ( V_22 , V_106 , & V_107 , & V_108 ,
V_232 -> V_235 ) ) {
F_109 ( V_143 , V_22 ) ;
V_232 -> V_235 = V_106 ;
goto V_158;
}
if ( V_108 >= 0 )
F_109 ( V_143 , V_107 ) ;
V_232 -> V_235 = V_108 ;
V_158:
return;
}
int F_110 ( struct V_69 * V_70 )
{
struct V_21 * V_225 ;
unsigned int V_8 ;
struct V_62 * V_20 ;
struct V_63 * V_64 ;
struct V_5 * V_6 ;
int V_223 ;
if ( ! ( V_70 -> V_149 & V_150 ) )
return 0 ;
V_225 = NULL ;
V_8 = F_28 ( V_70 -> V_71 ) ;
V_20 = & V_72 [ V_8 ] ;
V_223 = 0 ;
F_31 (nh, node, head, nh_hash) {
struct V_21 * V_22 = V_6 -> V_179 ;
int V_236 ;
F_105 ( ! V_22 -> V_56 ) ;
if ( V_6 -> V_25 != V_70 || V_22 == V_225 )
continue;
V_225 = V_22 ;
V_236 = 0 ;
F_12 (fi) {
if ( ! ( V_24 -> V_49 & V_50 ) ) {
V_236 ++ ;
continue;
}
if ( V_24 -> V_25 == NULL ||
! ( V_24 -> V_25 -> V_149 & V_150 ) )
continue;
if ( V_24 -> V_25 != V_70 ||
! F_111 ( V_70 ) )
continue;
V_236 ++ ;
F_21 ( & V_227 ) ;
V_24 -> V_229 = 0 ;
V_24 -> V_49 &= ~ V_50 ;
F_24 ( & V_227 ) ;
} F_14 (fi)
if ( V_236 > 0 ) {
V_22 -> V_67 &= ~ V_50 ;
V_223 ++ ;
}
}
return V_223 ;
}
void F_112 ( struct V_142 * V_143 )
{
struct V_21 * V_22 = V_143 -> V_22 ;
int V_237 ;
F_21 ( & V_227 ) ;
if ( V_22 -> V_228 <= 0 ) {
int V_238 = 0 ;
F_12 (fi) {
if ( ! ( V_24 -> V_49 & V_50 ) ) {
V_238 += V_24 -> V_48 ;
V_24 -> V_229 = V_24 -> V_48 ;
}
} F_14 ( V_22 ) ;
V_22 -> V_228 = V_238 ;
if ( V_238 <= 0 ) {
F_24 ( & V_227 ) ;
V_143 -> V_239 = 0 ;
return;
}
}
V_237 = V_240 % V_22 -> V_228 ;
F_12 (fi) {
if ( ! ( V_24 -> V_49 & V_50 ) &&
V_24 -> V_229 ) {
V_237 -= V_24 -> V_229 ;
if ( V_237 <= 0 ) {
V_24 -> V_229 -- ;
V_22 -> V_228 -- ;
V_143 -> V_239 = V_241 ;
F_24 ( & V_227 ) ;
return;
}
}
} F_14 ( V_22 ) ;
V_143 -> V_239 = 0 ;
F_24 ( & V_227 ) ;
}
