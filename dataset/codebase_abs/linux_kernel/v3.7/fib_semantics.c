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
V_61 -> V_66 == V_22 -> V_66 &&
memcmp ( V_61 -> V_29 , V_22 -> V_29 ,
sizeof( V_30 ) * V_67 ) == 0 &&
( ( V_61 -> V_68 ^ V_22 -> V_68 ) & ~ V_50 ) == 0 &&
( V_61 -> V_56 == 0 || F_25 ( V_22 , V_61 ) == 0 ) )
return V_22 ;
}
return NULL ;
}
int F_33 ( T_3 V_69 , struct V_70 * V_71 )
{
struct V_62 * V_20 ;
struct V_63 * V_64 ;
struct V_5 * V_6 ;
unsigned int V_8 ;
F_34 ( & V_37 ) ;
V_8 = F_28 ( V_71 -> V_72 ) ;
V_20 = & V_73 [ V_8 ] ;
F_31 (nh, node, head, nh_hash) {
if ( V_6 -> V_25 == V_71 &&
V_6 -> V_46 == V_69 &&
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
T_4 V_74 = F_37 ( sizeof( struct V_75 ) )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 ) ;
V_74 += F_38 ( ( V_67 * F_38 ( 4 ) ) ) ;
if ( V_22 -> V_56 ) {
T_4 V_76 = F_38 ( sizeof( struct V_77 ) ) ;
V_76 += 2 * F_38 ( 4 ) ;
V_74 += F_38 ( V_22 -> V_56 * V_76 ) ;
}
return V_74 ;
}
void F_39 ( int V_78 , T_3 V_79 , struct V_80 * V_81 ,
int V_82 , V_30 V_83 , struct V_84 * V_85 ,
unsigned int V_86 )
{
struct V_87 * V_88 ;
V_30 V_89 = V_85 -> V_90 ? V_85 -> V_90 -> V_91 : 0 ;
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
struct V_80 * F_46 ( struct V_103 * V_104 , T_5 V_105 , V_30 V_106 )
{
if ( V_104 ) {
struct V_80 * V_81 ;
F_47 (fa, fah, fa_list) {
if ( V_81 -> V_99 > V_105 )
continue;
if ( V_81 -> V_94 -> V_60 >= V_106 ||
V_81 -> V_99 < V_105 )
return V_81 ;
}
}
return NULL ;
}
int F_48 ( struct V_21 * V_22 , int V_107 ,
struct V_21 * * V_108 , int * V_109 , int V_110 )
{
struct V_111 * V_112 ;
int V_113 = V_114 ;
V_112 = F_49 ( & V_115 , & V_22 -> V_5 [ 0 ] . V_46 , V_22 -> V_116 ) ;
if ( V_112 ) {
V_113 = V_112 -> V_117 ;
F_50 ( V_112 ) ;
}
if ( V_113 == V_118 )
return 0 ;
if ( ( V_113 & V_119 ) && V_107 != V_110 )
return 0 ;
if ( ( V_113 & V_119 ) ||
( * V_109 < 0 && V_107 > V_110 ) ) {
* V_108 = V_22 ;
* V_109 = V_107 ;
}
return 1 ;
}
static int F_51 ( struct V_77 * V_120 , int V_121 )
{
int V_122 = 0 ;
while ( F_52 ( V_120 , V_121 ) ) {
V_122 ++ ;
V_120 = F_53 ( V_120 , & V_121 ) ;
}
return V_121 > 0 ? 0 : V_122 ;
}
static int F_54 ( struct V_21 * V_22 , struct V_77 * V_120 ,
int V_121 , struct V_123 * V_124 )
{
F_12 (fi) {
int V_125 ;
if ( ! F_52 ( V_120 , V_121 ) )
return - V_126 ;
V_24 -> V_49 =
( V_124 -> V_127 & ~ 0xFF ) | V_120 -> V_128 ;
V_24 -> V_45 = V_120 -> V_129 ;
V_24 -> V_48 = V_120 -> V_130 + 1 ;
V_125 = F_55 ( V_120 ) ;
if ( V_125 > 0 ) {
struct V_131 * V_132 , * V_133 = F_56 ( V_120 ) ;
V_132 = F_57 ( V_133 , V_125 , V_134 ) ;
V_24 -> V_46 = V_132 ? F_58 ( V_132 ) : 0 ;
#ifdef F_18
V_132 = F_57 ( V_133 , V_125 , V_135 ) ;
V_24 -> V_34 = V_132 ? F_59 ( V_132 ) : 0 ;
if ( V_24 -> V_34 )
V_22 -> V_28 -> V_35 . V_36 ++ ;
#endif
}
V_120 = F_53 ( V_120 , & V_121 ) ;
} F_14 ( V_22 ) ;
return 0 ;
}
int F_60 ( struct V_123 * V_124 , struct V_21 * V_22 )
{
#ifdef F_27
struct V_77 * V_120 ;
int V_121 ;
#endif
if ( V_124 -> V_136 && V_124 -> V_136 != V_22 -> V_60 )
return 1 ;
if ( V_124 -> V_137 || V_124 -> V_138 ) {
if ( ( ! V_124 -> V_137 || V_124 -> V_137 == V_22 -> V_5 -> V_45 ) &&
( ! V_124 -> V_138 || V_124 -> V_138 == V_22 -> V_5 -> V_46 ) )
return 0 ;
return 1 ;
}
#ifdef F_27
if ( V_124 -> V_139 == NULL )
return 0 ;
V_120 = V_124 -> V_139 ;
V_121 = V_124 -> V_140 ;
F_26 (fi) {
int V_125 ;
if ( ! F_52 ( V_120 , V_121 ) )
return - V_126 ;
if ( V_120 -> V_129 && V_120 -> V_129 != V_6 -> V_45 )
return 1 ;
V_125 = F_55 ( V_120 ) ;
if ( V_125 < 0 ) {
struct V_131 * V_132 , * V_133 = F_56 ( V_120 ) ;
V_132 = F_57 ( V_133 , V_125 , V_134 ) ;
if ( V_132 && F_58 ( V_132 ) != V_6 -> V_46 )
return 1 ;
#ifdef F_18
V_132 = F_57 ( V_133 , V_125 , V_135 ) ;
if ( V_132 && F_59 ( V_132 ) != V_6 -> V_34 )
return 1 ;
#endif
}
V_120 = F_53 ( V_120 , & V_121 ) ;
} F_14 ( V_22 ) ;
#endif
return 0 ;
}
static int F_61 ( struct V_123 * V_124 , struct V_21 * V_22 ,
struct V_5 * V_6 )
{
int V_92 ;
struct V_141 * V_141 ;
struct V_70 * V_71 ;
V_141 = V_124 -> V_142 . V_101 ;
if ( V_6 -> V_46 ) {
struct V_143 V_144 ;
if ( V_6 -> V_49 & V_145 ) {
if ( V_124 -> V_146 >= V_147 )
return - V_126 ;
if ( F_62 ( V_141 , V_6 -> V_46 ) != V_148 )
return - V_126 ;
V_71 = F_63 ( V_141 , V_6 -> V_45 ) ;
if ( ! V_71 )
return - V_149 ;
if ( ! ( V_71 -> V_150 & V_151 ) )
return - V_152 ;
V_6 -> V_25 = V_71 ;
F_64 ( V_71 ) ;
V_6 -> V_47 = V_147 ;
return 0 ;
}
F_65 () ;
{
struct V_153 V_154 = {
. V_155 = V_6 -> V_46 ,
. V_156 = V_124 -> V_146 + 1 ,
. V_157 = V_6 -> V_45 ,
} ;
if ( V_154 . V_156 < V_147 )
V_154 . V_156 = V_147 ;
V_92 = F_66 ( V_141 , & V_154 , & V_144 ) ;
if ( V_92 ) {
F_67 () ;
return V_92 ;
}
}
V_92 = - V_126 ;
if ( V_144 . type != V_148 && V_144 . type != V_158 )
goto V_159;
V_6 -> V_47 = V_144 . V_160 ;
V_6 -> V_45 = F_68 ( V_144 ) ;
V_6 -> V_25 = V_71 = F_69 ( V_144 ) ;
if ( ! V_71 )
goto V_159;
F_64 ( V_71 ) ;
V_92 = ( V_71 -> V_150 & V_151 ) ? 0 : - V_152 ;
} else {
struct V_161 * V_162 ;
if ( V_6 -> V_49 & ( V_163 | V_145 ) )
return - V_126 ;
F_65 () ;
V_92 = - V_149 ;
V_162 = F_70 ( V_141 , V_6 -> V_45 ) ;
if ( V_162 == NULL )
goto V_159;
V_92 = - V_152 ;
if ( ! ( V_162 -> V_71 -> V_150 & V_151 ) )
goto V_159;
V_6 -> V_25 = V_162 -> V_71 ;
F_64 ( V_6 -> V_25 ) ;
V_6 -> V_47 = V_164 ;
V_92 = 0 ;
}
V_159:
F_67 () ;
return V_92 ;
}
static inline unsigned int F_71 ( T_3 V_51 )
{
unsigned int V_52 = ( V_55 - 1 ) ;
return ( ( V_59 V_30 ) V_51 ^
( ( V_59 V_30 ) V_51 >> 7 ) ^
( ( V_59 V_30 ) V_51 >> 14 ) ) & V_52 ;
}
static struct V_62 * F_72 ( int V_165 )
{
if ( V_165 <= V_166 )
return F_73 ( V_165 , V_95 ) ;
else
return (struct V_62 * )
F_74 ( V_95 | V_167 ,
F_75 ( V_165 ) ) ;
}
static void F_76 ( struct V_62 * V_8 , int V_165 )
{
if ( ! V_8 )
return;
if ( V_165 <= V_166 )
F_5 ( V_8 ) ;
else
F_77 ( ( unsigned long ) V_8 , F_75 ( V_165 ) ) ;
}
static void F_78 ( struct V_62 * V_168 ,
struct V_62 * V_169 ,
unsigned int V_170 )
{
struct V_62 * V_171 , * V_172 ;
unsigned int V_173 = V_55 ;
unsigned int V_10 , V_165 ;
F_21 ( & V_37 ) ;
V_171 = V_65 ;
V_172 = V_174 ;
V_55 = V_170 ;
for ( V_10 = 0 ; V_10 < V_173 ; V_10 ++ ) {
struct V_62 * V_20 = & V_65 [ V_10 ] ;
struct V_63 * V_64 , * V_112 ;
struct V_21 * V_22 ;
F_79 (fi, node, n, head, fib_hash) {
struct V_62 * V_175 ;
unsigned int V_176 ;
F_22 ( & V_22 -> V_39 ) ;
V_176 = F_29 ( V_22 ) ;
V_175 = & V_168 [ V_176 ] ;
F_80 ( & V_22 -> V_39 , V_175 ) ;
}
}
V_65 = V_168 ;
for ( V_10 = 0 ; V_10 < V_173 ; V_10 ++ ) {
struct V_62 * V_177 = & V_174 [ V_10 ] ;
struct V_63 * V_64 , * V_112 ;
struct V_21 * V_22 ;
F_79 (fi, node, n, lhead, fib_lhash) {
struct V_62 * V_178 ;
unsigned int V_176 ;
F_22 ( & V_22 -> V_41 ) ;
V_176 = F_71 ( V_22 -> V_40 ) ;
V_178 = & V_169 [ V_176 ] ;
F_80 ( & V_22 -> V_41 , V_178 ) ;
}
}
V_174 = V_169 ;
F_24 ( & V_37 ) ;
V_165 = V_173 * sizeof( struct V_62 * ) ;
F_76 ( V_171 , V_165 ) ;
F_76 ( V_172 , V_165 ) ;
}
T_3 F_81 ( struct V_141 * V_141 , struct V_5 * V_6 )
{
V_6 -> V_179 = F_82 ( V_6 -> V_25 ,
V_6 -> V_46 ,
V_6 -> V_180 -> V_58 ) ;
V_6 -> V_181 = F_83 ( & V_141 -> V_35 . V_182 ) ;
return V_6 -> V_179 ;
}
struct V_21 * F_84 ( struct V_123 * V_124 )
{
int V_92 ;
struct V_21 * V_22 = NULL ;
struct V_21 * V_43 ;
int V_122 = 1 ;
struct V_141 * V_141 = V_124 -> V_142 . V_101 ;
if ( V_124 -> V_183 > V_184 )
goto V_185;
if ( V_186 [ V_124 -> V_183 ] . V_160 > V_124 -> V_146 )
goto V_185;
#ifdef F_27
if ( V_124 -> V_139 ) {
V_122 = F_51 ( V_124 -> V_139 , V_124 -> V_140 ) ;
if ( V_122 == 0 )
goto V_185;
}
#endif
V_92 = - V_93 ;
if ( V_33 >= V_55 ) {
unsigned int V_170 = V_55 << 1 ;
struct V_62 * V_168 ;
struct V_62 * V_169 ;
unsigned int V_165 ;
if ( ! V_170 )
V_170 = 1 ;
V_165 = V_170 * sizeof( struct V_62 * ) ;
V_168 = F_72 ( V_165 ) ;
V_169 = F_72 ( V_165 ) ;
if ( ! V_168 || ! V_169 ) {
F_76 ( V_168 , V_165 ) ;
F_76 ( V_169 , V_165 ) ;
} else
F_78 ( V_168 , V_169 , V_170 ) ;
if ( ! V_55 )
goto V_187;
}
V_22 = F_73 ( sizeof( * V_22 ) + V_122 * sizeof( struct V_5 ) , V_95 ) ;
if ( V_22 == NULL )
goto V_187;
if ( V_124 -> V_188 ) {
V_22 -> V_29 = F_73 ( sizeof( V_30 ) * V_67 , V_95 ) ;
if ( ! V_22 -> V_29 )
goto V_187;
} else
V_22 -> V_29 = ( V_30 * ) V_31 ;
V_33 ++ ;
V_22 -> V_28 = F_85 ( V_141 ) ;
V_22 -> V_57 = V_124 -> V_189 ;
V_22 -> V_58 = V_124 -> V_146 ;
V_22 -> V_68 = V_124 -> V_127 ;
V_22 -> V_60 = V_124 -> V_136 ;
V_22 -> V_40 = V_124 -> V_190 ;
V_22 -> V_66 = V_124 -> V_183 ;
V_22 -> V_56 = V_122 ;
F_12 (fi) {
V_24 -> V_180 = V_22 ;
V_24 -> V_26 = F_86 (struct rtable __rcu *) ;
if ( ! V_24 -> V_26 )
goto V_187;
} F_14 (fi)
if ( V_124 -> V_188 ) {
struct V_131 * V_132 ;
int V_121 ;
F_87 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_88 ( V_132 ) ;
if ( type ) {
V_30 V_51 ;
if ( type > V_67 )
goto V_185;
V_51 = F_59 ( V_132 ) ;
if ( type == V_191 && V_51 > 65535 - 40 )
V_51 = 65535 - 40 ;
if ( type == V_192 && V_51 > 65535 - 15 )
V_51 = 65535 - 15 ;
V_22 -> V_29 [ type - 1 ] = V_51 ;
}
}
}
if ( V_124 -> V_139 ) {
#ifdef F_27
V_92 = F_54 ( V_22 , V_124 -> V_139 , V_124 -> V_140 , V_124 ) ;
if ( V_92 != 0 )
goto V_187;
if ( V_124 -> V_137 && V_22 -> V_5 -> V_45 != V_124 -> V_137 )
goto V_185;
if ( V_124 -> V_138 && V_22 -> V_5 -> V_46 != V_124 -> V_138 )
goto V_185;
#ifdef F_18
if ( V_124 -> V_193 && V_22 -> V_5 -> V_34 != V_124 -> V_193 )
goto V_185;
#endif
#else
goto V_185;
#endif
} else {
struct V_5 * V_6 = V_22 -> V_5 ;
V_6 -> V_45 = V_124 -> V_137 ;
V_6 -> V_46 = V_124 -> V_138 ;
V_6 -> V_49 = V_124 -> V_127 ;
#ifdef F_18
V_6 -> V_34 = V_124 -> V_193 ;
if ( V_6 -> V_34 )
V_22 -> V_28 -> V_35 . V_36 ++ ;
#endif
#ifdef F_27
V_6 -> V_48 = 1 ;
#endif
}
if ( V_186 [ V_124 -> V_183 ] . error ) {
if ( V_124 -> V_138 || V_124 -> V_137 || V_124 -> V_139 )
goto V_185;
goto V_194;
} else {
switch ( V_124 -> V_183 ) {
case V_148 :
case V_158 :
case V_195 :
case V_196 :
case V_197 :
break;
default:
goto V_185;
}
}
if ( V_124 -> V_146 > V_164 )
goto V_185;
if ( V_124 -> V_146 == V_164 ) {
struct V_5 * V_6 = V_22 -> V_5 ;
if ( V_122 != 1 || V_6 -> V_46 )
goto V_185;
V_6 -> V_47 = V_198 ;
V_6 -> V_25 = F_89 ( V_141 , V_22 -> V_5 -> V_45 ) ;
V_92 = - V_149 ;
if ( V_6 -> V_25 == NULL )
goto V_187;
} else {
F_12 (fi) {
V_92 = F_61 ( V_124 , V_22 , V_24 ) ;
if ( V_92 != 0 )
goto V_187;
} F_14 (fi)
}
if ( V_22 -> V_40 ) {
if ( V_124 -> V_183 != V_158 || ! V_124 -> V_199 ||
V_22 -> V_40 != V_124 -> V_199 )
if ( F_62 ( V_141 , V_22 -> V_40 ) != V_158 )
goto V_185;
}
F_12 (fi) {
F_81 ( V_141 , V_24 ) ;
} F_14 (fi)
V_194:
V_43 = F_30 ( V_22 ) ;
if ( V_43 ) {
V_22 -> V_32 = 1 ;
F_16 ( V_22 ) ;
V_43 -> V_38 ++ ;
return V_43 ;
}
V_22 -> V_38 ++ ;
F_90 ( & V_22 -> V_200 ) ;
F_21 ( & V_37 ) ;
F_80 ( & V_22 -> V_39 ,
& V_65 [ F_29 ( V_22 ) ] ) ;
if ( V_22 -> V_40 ) {
struct V_62 * V_20 ;
V_20 = & V_174 [ F_71 ( V_22 -> V_40 ) ] ;
F_80 ( & V_22 -> V_41 , V_20 ) ;
}
F_12 (fi) {
struct V_62 * V_20 ;
unsigned int V_8 ;
if ( ! V_24 -> V_25 )
continue;
V_8 = F_28 ( V_24 -> V_25 -> V_72 ) ;
V_20 = & V_73 [ V_8 ] ;
F_80 ( & V_24 -> V_42 , V_20 ) ;
} F_14 (fi)
F_24 ( & V_37 ) ;
return V_22 ;
V_185:
V_92 = - V_126 ;
V_187:
if ( V_22 ) {
V_22 -> V_32 = 1 ;
F_16 ( V_22 ) ;
}
return F_91 ( V_92 ) ;
}
int F_41 ( struct V_87 * V_88 , V_30 V_97 , V_30 V_89 , int V_78 ,
V_30 V_83 , T_5 type , T_3 V_4 , int V_82 , T_5 V_105 ,
struct V_21 * V_22 , unsigned int V_150 )
{
struct V_201 * V_90 ;
struct V_75 * V_202 ;
V_90 = F_92 ( V_88 , V_97 , V_89 , V_78 , sizeof( * V_202 ) , V_150 ) ;
if ( V_90 == NULL )
return - V_100 ;
V_202 = F_93 ( V_90 ) ;
V_202 -> V_203 = V_204 ;
V_202 -> V_205 = V_82 ;
V_202 -> V_206 = 0 ;
V_202 -> V_207 = V_105 ;
if ( V_83 < 256 )
V_202 -> V_208 = V_83 ;
else
V_202 -> V_208 = V_209 ;
if ( F_94 ( V_88 , V_210 , V_83 ) )
goto V_211;
V_202 -> V_212 = type ;
V_202 -> V_213 = V_22 -> V_68 ;
V_202 -> V_214 = V_22 -> V_58 ;
V_202 -> V_215 = V_22 -> V_57 ;
if ( V_202 -> V_205 &&
F_95 ( V_88 , V_216 , V_4 ) )
goto V_211;
if ( V_22 -> V_60 &&
F_94 ( V_88 , V_217 , V_22 -> V_60 ) )
goto V_211;
if ( F_96 ( V_88 , V_22 -> V_29 ) < 0 )
goto V_211;
if ( V_22 -> V_40 &&
F_95 ( V_88 , V_218 , V_22 -> V_40 ) )
goto V_211;
if ( V_22 -> V_56 == 1 ) {
if ( V_22 -> V_5 -> V_46 &&
F_95 ( V_88 , V_134 , V_22 -> V_5 -> V_46 ) )
goto V_211;
if ( V_22 -> V_5 -> V_45 &&
F_94 ( V_88 , V_219 , V_22 -> V_5 -> V_45 ) )
goto V_211;
#ifdef F_18
if ( V_22 -> V_5 [ 0 ] . V_34 &&
F_94 ( V_88 , V_135 , V_22 -> V_5 [ 0 ] . V_34 ) )
goto V_211;
#endif
}
#ifdef F_27
if ( V_22 -> V_56 > 1 ) {
struct V_77 * V_120 ;
struct V_131 * V_220 ;
V_220 = F_97 ( V_88 , V_221 ) ;
if ( V_220 == NULL )
goto V_211;
F_26 (fi) {
V_120 = F_98 ( V_88 , sizeof( * V_120 ) ) ;
if ( V_120 == NULL )
goto V_211;
V_120 -> V_128 = V_6 -> V_49 & 0xFF ;
V_120 -> V_130 = V_6 -> V_48 - 1 ;
V_120 -> V_129 = V_6 -> V_45 ;
if ( V_6 -> V_46 &&
F_95 ( V_88 , V_134 , V_6 -> V_46 ) )
goto V_211;
#ifdef F_18
if ( V_6 -> V_34 &&
F_94 ( V_88 , V_135 , V_6 -> V_34 ) )
goto V_211;
#endif
V_120 -> V_222 = F_99 ( V_88 ) - ( void * ) V_120 ;
} F_14 ( V_22 ) ;
F_100 ( V_88 , V_220 ) ;
}
#endif
return F_101 ( V_88 , V_90 ) ;
V_211:
F_102 ( V_88 , V_90 ) ;
return - V_100 ;
}
int F_103 ( struct V_141 * V_141 , T_3 V_223 )
{
int V_224 = 0 ;
unsigned int V_8 = F_71 ( V_223 ) ;
struct V_62 * V_20 = & V_174 [ V_8 ] ;
struct V_63 * V_64 ;
struct V_21 * V_22 ;
if ( V_174 == NULL || V_223 == 0 )
return 0 ;
F_31 (fi, node, head, fib_lhash) {
if ( ! F_32 ( V_22 -> V_28 , V_141 ) )
continue;
if ( V_22 -> V_40 == V_223 ) {
V_22 -> V_68 |= V_50 ;
V_224 ++ ;
}
}
return V_224 ;
}
int F_104 ( struct V_70 * V_71 , int V_225 )
{
int V_224 = 0 ;
int V_160 = V_198 ;
struct V_21 * V_226 = NULL ;
unsigned int V_8 = F_28 ( V_71 -> V_72 ) ;
struct V_62 * V_20 = & V_73 [ V_8 ] ;
struct V_63 * V_64 ;
struct V_5 * V_6 ;
if ( V_225 )
V_160 = - 1 ;
F_31 (nh, node, head, nh_hash) {
struct V_21 * V_22 = V_6 -> V_180 ;
int V_227 ;
F_105 ( ! V_22 -> V_56 ) ;
if ( V_6 -> V_25 != V_71 || V_22 == V_226 )
continue;
V_226 = V_22 ;
V_227 = 0 ;
F_12 (fi) {
if ( V_24 -> V_49 & V_50 )
V_227 ++ ;
else if ( V_24 -> V_25 == V_71 &&
V_24 -> V_47 != V_160 ) {
V_24 -> V_49 |= V_50 ;
#ifdef F_27
F_21 ( & V_228 ) ;
V_22 -> V_229 -= V_24 -> V_230 ;
V_24 -> V_230 = 0 ;
F_24 ( & V_228 ) ;
#endif
V_227 ++ ;
}
#ifdef F_27
if ( V_225 > 1 && V_24 -> V_25 == V_71 ) {
V_227 = V_22 -> V_56 ;
break;
}
#endif
} F_14 (fi)
if ( V_227 == V_22 -> V_56 ) {
V_22 -> V_68 |= V_50 ;
V_224 ++ ;
}
}
return V_224 ;
}
void F_106 ( struct V_143 * V_144 )
{
struct V_21 * V_22 = NULL , * V_108 = NULL ;
struct V_103 * V_231 = V_144 -> V_231 ;
struct V_232 * V_233 = V_144 -> V_234 ;
int V_107 = - 1 , V_109 = - 1 ;
struct V_80 * V_81 ;
F_107 (fa, fa_head, fa_list) {
struct V_21 * V_235 = V_81 -> V_94 ;
if ( V_235 -> V_58 != V_144 -> V_160 ||
V_81 -> V_98 != V_148 )
continue;
if ( V_235 -> V_60 > V_144 -> V_22 -> V_60 )
break;
if ( ! V_235 -> V_5 [ 0 ] . V_46 ||
V_235 -> V_5 [ 0 ] . V_47 != V_147 )
continue;
F_108 ( V_81 ) ;
if ( V_22 == NULL ) {
if ( V_235 != V_144 -> V_22 )
break;
} else if ( ! F_48 ( V_22 , V_107 , & V_108 ,
& V_109 , V_233 -> V_236 ) ) {
F_109 ( V_144 , V_22 ) ;
V_233 -> V_236 = V_107 ;
goto V_159;
}
V_22 = V_235 ;
V_107 ++ ;
}
if ( V_107 <= 0 || V_22 == NULL ) {
V_233 -> V_236 = - 1 ;
goto V_159;
}
if ( ! F_48 ( V_22 , V_107 , & V_108 , & V_109 ,
V_233 -> V_236 ) ) {
F_109 ( V_144 , V_22 ) ;
V_233 -> V_236 = V_107 ;
goto V_159;
}
if ( V_109 >= 0 )
F_109 ( V_144 , V_108 ) ;
V_233 -> V_236 = V_109 ;
V_159:
return;
}
int F_110 ( struct V_70 * V_71 )
{
struct V_21 * V_226 ;
unsigned int V_8 ;
struct V_62 * V_20 ;
struct V_63 * V_64 ;
struct V_5 * V_6 ;
int V_224 ;
if ( ! ( V_71 -> V_150 & V_151 ) )
return 0 ;
V_226 = NULL ;
V_8 = F_28 ( V_71 -> V_72 ) ;
V_20 = & V_73 [ V_8 ] ;
V_224 = 0 ;
F_31 (nh, node, head, nh_hash) {
struct V_21 * V_22 = V_6 -> V_180 ;
int V_237 ;
F_105 ( ! V_22 -> V_56 ) ;
if ( V_6 -> V_25 != V_71 || V_22 == V_226 )
continue;
V_226 = V_22 ;
V_237 = 0 ;
F_12 (fi) {
if ( ! ( V_24 -> V_49 & V_50 ) ) {
V_237 ++ ;
continue;
}
if ( V_24 -> V_25 == NULL ||
! ( V_24 -> V_25 -> V_150 & V_151 ) )
continue;
if ( V_24 -> V_25 != V_71 ||
! F_111 ( V_71 ) )
continue;
V_237 ++ ;
F_21 ( & V_228 ) ;
V_24 -> V_230 = 0 ;
V_24 -> V_49 &= ~ V_50 ;
F_24 ( & V_228 ) ;
} F_14 (fi)
if ( V_237 > 0 ) {
V_22 -> V_68 &= ~ V_50 ;
V_224 ++ ;
}
}
return V_224 ;
}
void F_112 ( struct V_143 * V_144 )
{
struct V_21 * V_22 = V_144 -> V_22 ;
int V_238 ;
F_21 ( & V_228 ) ;
if ( V_22 -> V_229 <= 0 ) {
int V_239 = 0 ;
F_12 (fi) {
if ( ! ( V_24 -> V_49 & V_50 ) ) {
V_239 += V_24 -> V_48 ;
V_24 -> V_230 = V_24 -> V_48 ;
}
} F_14 ( V_22 ) ;
V_22 -> V_229 = V_239 ;
if ( V_239 <= 0 ) {
F_24 ( & V_228 ) ;
V_144 -> V_240 = 0 ;
return;
}
}
V_238 = V_241 % V_22 -> V_229 ;
F_12 (fi) {
if ( ! ( V_24 -> V_49 & V_50 ) &&
V_24 -> V_230 ) {
V_238 -= V_24 -> V_230 ;
if ( V_238 <= 0 ) {
V_24 -> V_230 -- ;
V_22 -> V_229 -- ;
V_144 -> V_240 = V_242 ;
F_24 ( & V_228 ) ;
return;
}
}
} F_14 ( V_22 ) ;
V_144 -> V_240 = 0 ;
F_24 ( & V_228 ) ;
}
