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
struct V_21 * V_22 ;
unsigned int V_8 ;
V_8 = F_29 ( V_61 ) ;
V_20 = & V_63 [ V_8 ] ;
F_31 (fi, head, fib_hash) {
if ( ! F_32 ( V_22 -> V_28 , V_61 -> V_28 ) )
continue;
if ( V_22 -> V_56 != V_61 -> V_56 )
continue;
if ( V_61 -> V_57 == V_22 -> V_57 &&
V_61 -> V_58 == V_22 -> V_58 &&
V_61 -> V_40 == V_22 -> V_40 &&
V_61 -> V_60 == V_22 -> V_60 &&
V_61 -> V_64 == V_22 -> V_64 &&
memcmp ( V_61 -> V_29 , V_22 -> V_29 ,
sizeof( V_30 ) * V_65 ) == 0 &&
( ( V_61 -> V_66 ^ V_22 -> V_66 ) & ~ V_50 ) == 0 &&
( V_61 -> V_56 == 0 || F_25 ( V_22 , V_61 ) == 0 ) )
return V_22 ;
}
return NULL ;
}
int F_33 ( T_3 V_67 , struct V_68 * V_69 )
{
struct V_62 * V_20 ;
struct V_5 * V_6 ;
unsigned int V_8 ;
F_34 ( & V_37 ) ;
V_8 = F_28 ( V_69 -> V_70 ) ;
V_20 = & V_71 [ V_8 ] ;
F_31 (nh, head, nh_hash) {
if ( V_6 -> V_25 == V_69 &&
V_6 -> V_46 == V_67 &&
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
T_4 V_72 = F_37 ( sizeof( struct V_73 ) )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 )
+ F_38 ( 4 ) ;
V_72 += F_38 ( ( V_65 * F_38 ( 4 ) ) ) ;
if ( V_22 -> V_56 ) {
T_4 V_74 = F_38 ( sizeof( struct V_75 ) ) ;
V_74 += 2 * F_38 ( 4 ) ;
V_72 += F_38 ( V_22 -> V_56 * V_74 ) ;
}
return V_72 ;
}
void F_39 ( int V_76 , T_3 V_77 , struct V_78 * V_79 ,
int V_80 , V_30 V_81 , struct V_82 * V_83 ,
unsigned int V_84 )
{
struct V_85 * V_86 ;
V_30 V_87 = V_83 -> V_88 ? V_83 -> V_88 -> V_89 : 0 ;
int V_90 = - V_91 ;
V_86 = F_40 ( F_36 ( V_79 -> V_92 ) , V_93 ) ;
if ( V_86 == NULL )
goto V_94;
V_90 = F_41 ( V_86 , V_83 -> V_95 , V_87 , V_76 , V_81 ,
V_79 -> V_96 , V_77 , V_80 ,
V_79 -> V_97 , V_79 -> V_92 , V_84 ) ;
if ( V_90 < 0 ) {
F_42 ( V_90 == - V_98 ) ;
F_43 ( V_86 ) ;
goto V_94;
}
F_44 ( V_86 , V_83 -> V_99 , V_83 -> V_95 , V_100 ,
V_83 -> V_88 , V_93 ) ;
return;
V_94:
if ( V_90 < 0 )
F_45 ( V_83 -> V_99 , V_100 , V_90 ) ;
}
struct V_78 * F_46 ( struct V_101 * V_102 , T_5 V_103 , V_30 V_104 )
{
if ( V_102 ) {
struct V_78 * V_79 ;
F_47 (fa, fah, fa_list) {
if ( V_79 -> V_97 > V_103 )
continue;
if ( V_79 -> V_92 -> V_60 >= V_104 ||
V_79 -> V_97 < V_103 )
return V_79 ;
}
}
return NULL ;
}
int F_48 ( struct V_21 * V_22 , int V_105 ,
struct V_21 * * V_106 , int * V_107 , int V_108 )
{
struct V_109 * V_110 ;
int V_111 = V_112 ;
V_110 = F_49 ( & V_113 , & V_22 -> V_5 [ 0 ] . V_46 , V_22 -> V_114 ) ;
if ( V_110 ) {
V_111 = V_110 -> V_115 ;
F_50 ( V_110 ) ;
}
if ( V_111 == V_116 )
return 0 ;
if ( ( V_111 & V_117 ) && V_105 != V_108 )
return 0 ;
if ( ( V_111 & V_117 ) ||
( * V_107 < 0 && V_105 > V_108 ) ) {
* V_106 = V_22 ;
* V_107 = V_105 ;
}
return 1 ;
}
static int F_51 ( struct V_75 * V_118 , int V_119 )
{
int V_120 = 0 ;
while ( F_52 ( V_118 , V_119 ) ) {
V_120 ++ ;
V_118 = F_53 ( V_118 , & V_119 ) ;
}
return V_119 > 0 ? 0 : V_120 ;
}
static int F_54 ( struct V_21 * V_22 , struct V_75 * V_118 ,
int V_119 , struct V_121 * V_122 )
{
F_12 (fi) {
int V_123 ;
if ( ! F_52 ( V_118 , V_119 ) )
return - V_124 ;
V_24 -> V_49 =
( V_122 -> V_125 & ~ 0xFF ) | V_118 -> V_126 ;
V_24 -> V_45 = V_118 -> V_127 ;
V_24 -> V_48 = V_118 -> V_128 + 1 ;
V_123 = F_55 ( V_118 ) ;
if ( V_123 > 0 ) {
struct V_129 * V_130 , * V_131 = F_56 ( V_118 ) ;
V_130 = F_57 ( V_131 , V_123 , V_132 ) ;
V_24 -> V_46 = V_130 ? F_58 ( V_130 ) : 0 ;
#ifdef F_18
V_130 = F_57 ( V_131 , V_123 , V_133 ) ;
V_24 -> V_34 = V_130 ? F_59 ( V_130 ) : 0 ;
if ( V_24 -> V_34 )
V_22 -> V_28 -> V_35 . V_36 ++ ;
#endif
}
V_118 = F_53 ( V_118 , & V_119 ) ;
} F_14 ( V_22 ) ;
return 0 ;
}
int F_60 ( struct V_121 * V_122 , struct V_21 * V_22 )
{
#ifdef F_27
struct V_75 * V_118 ;
int V_119 ;
#endif
if ( V_122 -> V_134 && V_122 -> V_134 != V_22 -> V_60 )
return 1 ;
if ( V_122 -> V_135 || V_122 -> V_136 ) {
if ( ( ! V_122 -> V_135 || V_122 -> V_135 == V_22 -> V_5 -> V_45 ) &&
( ! V_122 -> V_136 || V_122 -> V_136 == V_22 -> V_5 -> V_46 ) )
return 0 ;
return 1 ;
}
#ifdef F_27
if ( V_122 -> V_137 == NULL )
return 0 ;
V_118 = V_122 -> V_137 ;
V_119 = V_122 -> V_138 ;
F_26 (fi) {
int V_123 ;
if ( ! F_52 ( V_118 , V_119 ) )
return - V_124 ;
if ( V_118 -> V_127 && V_118 -> V_127 != V_6 -> V_45 )
return 1 ;
V_123 = F_55 ( V_118 ) ;
if ( V_123 < 0 ) {
struct V_129 * V_130 , * V_131 = F_56 ( V_118 ) ;
V_130 = F_57 ( V_131 , V_123 , V_132 ) ;
if ( V_130 && F_58 ( V_130 ) != V_6 -> V_46 )
return 1 ;
#ifdef F_18
V_130 = F_57 ( V_131 , V_123 , V_133 ) ;
if ( V_130 && F_59 ( V_130 ) != V_6 -> V_34 )
return 1 ;
#endif
}
V_118 = F_53 ( V_118 , & V_119 ) ;
} F_14 ( V_22 ) ;
#endif
return 0 ;
}
static int F_61 ( struct V_121 * V_122 , struct V_21 * V_22 ,
struct V_5 * V_6 )
{
int V_90 ;
struct V_139 * V_139 ;
struct V_68 * V_69 ;
V_139 = V_122 -> V_140 . V_99 ;
if ( V_6 -> V_46 ) {
struct V_141 V_142 ;
if ( V_6 -> V_49 & V_143 ) {
if ( V_122 -> V_144 >= V_145 )
return - V_124 ;
if ( F_62 ( V_139 , V_6 -> V_46 ) != V_146 )
return - V_124 ;
V_69 = F_63 ( V_139 , V_6 -> V_45 ) ;
if ( ! V_69 )
return - V_147 ;
if ( ! ( V_69 -> V_148 & V_149 ) )
return - V_150 ;
V_6 -> V_25 = V_69 ;
F_64 ( V_69 ) ;
V_6 -> V_47 = V_145 ;
return 0 ;
}
F_65 () ;
{
struct V_151 V_152 = {
. V_153 = V_6 -> V_46 ,
. V_154 = V_122 -> V_144 + 1 ,
. V_155 = V_6 -> V_45 ,
} ;
if ( V_152 . V_154 < V_145 )
V_152 . V_154 = V_145 ;
V_90 = F_66 ( V_139 , & V_152 , & V_142 ) ;
if ( V_90 ) {
F_67 () ;
return V_90 ;
}
}
V_90 = - V_124 ;
if ( V_142 . type != V_146 && V_142 . type != V_156 )
goto V_157;
V_6 -> V_47 = V_142 . V_158 ;
V_6 -> V_45 = F_68 ( V_142 ) ;
V_6 -> V_25 = V_69 = F_69 ( V_142 ) ;
if ( ! V_69 )
goto V_157;
F_64 ( V_69 ) ;
V_90 = ( V_69 -> V_148 & V_149 ) ? 0 : - V_150 ;
} else {
struct V_159 * V_160 ;
if ( V_6 -> V_49 & ( V_161 | V_143 ) )
return - V_124 ;
F_65 () ;
V_90 = - V_147 ;
V_160 = F_70 ( V_139 , V_6 -> V_45 ) ;
if ( V_160 == NULL )
goto V_157;
V_90 = - V_150 ;
if ( ! ( V_160 -> V_69 -> V_148 & V_149 ) )
goto V_157;
V_6 -> V_25 = V_160 -> V_69 ;
F_64 ( V_6 -> V_25 ) ;
V_6 -> V_47 = V_162 ;
V_90 = 0 ;
}
V_157:
F_67 () ;
return V_90 ;
}
static inline unsigned int F_71 ( T_3 V_51 )
{
unsigned int V_52 = ( V_55 - 1 ) ;
return ( ( V_59 V_30 ) V_51 ^
( ( V_59 V_30 ) V_51 >> 7 ) ^
( ( V_59 V_30 ) V_51 >> 14 ) ) & V_52 ;
}
static struct V_62 * F_72 ( int V_163 )
{
if ( V_163 <= V_164 )
return F_73 ( V_163 , V_93 ) ;
else
return (struct V_62 * )
F_74 ( V_93 | V_165 ,
F_75 ( V_163 ) ) ;
}
static void F_76 ( struct V_62 * V_8 , int V_163 )
{
if ( ! V_8 )
return;
if ( V_163 <= V_164 )
F_5 ( V_8 ) ;
else
F_77 ( ( unsigned long ) V_8 , F_75 ( V_163 ) ) ;
}
static void F_78 ( struct V_62 * V_166 ,
struct V_62 * V_167 ,
unsigned int V_168 )
{
struct V_62 * V_169 , * V_170 ;
unsigned int V_171 = V_55 ;
unsigned int V_10 , V_163 ;
F_21 ( & V_37 ) ;
V_169 = V_63 ;
V_170 = V_172 ;
V_55 = V_168 ;
for ( V_10 = 0 ; V_10 < V_171 ; V_10 ++ ) {
struct V_62 * V_20 = & V_63 [ V_10 ] ;
struct V_173 * V_110 ;
struct V_21 * V_22 ;
F_79 (fi, n, head, fib_hash) {
struct V_62 * V_174 ;
unsigned int V_175 ;
F_22 ( & V_22 -> V_39 ) ;
V_175 = F_29 ( V_22 ) ;
V_174 = & V_166 [ V_175 ] ;
F_80 ( & V_22 -> V_39 , V_174 ) ;
}
}
V_63 = V_166 ;
for ( V_10 = 0 ; V_10 < V_171 ; V_10 ++ ) {
struct V_62 * V_176 = & V_172 [ V_10 ] ;
struct V_173 * V_110 ;
struct V_21 * V_22 ;
F_79 (fi, n, lhead, fib_lhash) {
struct V_62 * V_177 ;
unsigned int V_175 ;
F_22 ( & V_22 -> V_41 ) ;
V_175 = F_71 ( V_22 -> V_40 ) ;
V_177 = & V_167 [ V_175 ] ;
F_80 ( & V_22 -> V_41 , V_177 ) ;
}
}
V_172 = V_167 ;
F_24 ( & V_37 ) ;
V_163 = V_171 * sizeof( struct V_62 * ) ;
F_76 ( V_169 , V_163 ) ;
F_76 ( V_170 , V_163 ) ;
}
T_3 F_81 ( struct V_139 * V_139 , struct V_5 * V_6 )
{
V_6 -> V_178 = F_82 ( V_6 -> V_25 ,
V_6 -> V_46 ,
V_6 -> V_179 -> V_58 ) ;
V_6 -> V_180 = F_83 ( & V_139 -> V_35 . V_181 ) ;
return V_6 -> V_178 ;
}
struct V_21 * F_84 ( struct V_121 * V_122 )
{
int V_90 ;
struct V_21 * V_22 = NULL ;
struct V_21 * V_43 ;
int V_120 = 1 ;
struct V_139 * V_139 = V_122 -> V_140 . V_99 ;
if ( V_122 -> V_182 > V_183 )
goto V_184;
if ( V_185 [ V_122 -> V_182 ] . V_158 > V_122 -> V_144 )
goto V_184;
#ifdef F_27
if ( V_122 -> V_137 ) {
V_120 = F_51 ( V_122 -> V_137 , V_122 -> V_138 ) ;
if ( V_120 == 0 )
goto V_184;
}
#endif
V_90 = - V_91 ;
if ( V_33 >= V_55 ) {
unsigned int V_168 = V_55 << 1 ;
struct V_62 * V_166 ;
struct V_62 * V_167 ;
unsigned int V_163 ;
if ( ! V_168 )
V_168 = 16 ;
V_163 = V_168 * sizeof( struct V_62 * ) ;
V_166 = F_72 ( V_163 ) ;
V_167 = F_72 ( V_163 ) ;
if ( ! V_166 || ! V_167 ) {
F_76 ( V_166 , V_163 ) ;
F_76 ( V_167 , V_163 ) ;
} else
F_78 ( V_166 , V_167 , V_168 ) ;
if ( ! V_55 )
goto V_186;
}
V_22 = F_73 ( sizeof( * V_22 ) + V_120 * sizeof( struct V_5 ) , V_93 ) ;
if ( V_22 == NULL )
goto V_186;
if ( V_122 -> V_187 ) {
V_22 -> V_29 = F_73 ( sizeof( V_30 ) * V_65 , V_93 ) ;
if ( ! V_22 -> V_29 )
goto V_186;
} else
V_22 -> V_29 = ( V_30 * ) V_31 ;
V_33 ++ ;
V_22 -> V_28 = F_85 ( V_139 ) ;
V_22 -> V_57 = V_122 -> V_188 ;
V_22 -> V_58 = V_122 -> V_144 ;
V_22 -> V_66 = V_122 -> V_125 ;
V_22 -> V_60 = V_122 -> V_134 ;
V_22 -> V_40 = V_122 -> V_189 ;
V_22 -> V_64 = V_122 -> V_182 ;
V_22 -> V_56 = V_120 ;
F_12 (fi) {
V_24 -> V_179 = V_22 ;
V_24 -> V_26 = F_86 (struct rtable __rcu *) ;
if ( ! V_24 -> V_26 )
goto V_186;
} F_14 (fi)
if ( V_122 -> V_187 ) {
struct V_129 * V_130 ;
int V_119 ;
F_87 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_88 ( V_130 ) ;
if ( type ) {
V_30 V_51 ;
if ( type > V_65 )
goto V_184;
V_51 = F_59 ( V_130 ) ;
if ( type == V_190 && V_51 > 65535 - 40 )
V_51 = 65535 - 40 ;
if ( type == V_191 && V_51 > 65535 - 15 )
V_51 = 65535 - 15 ;
V_22 -> V_29 [ type - 1 ] = V_51 ;
}
}
}
if ( V_122 -> V_137 ) {
#ifdef F_27
V_90 = F_54 ( V_22 , V_122 -> V_137 , V_122 -> V_138 , V_122 ) ;
if ( V_90 != 0 )
goto V_186;
if ( V_122 -> V_135 && V_22 -> V_5 -> V_45 != V_122 -> V_135 )
goto V_184;
if ( V_122 -> V_136 && V_22 -> V_5 -> V_46 != V_122 -> V_136 )
goto V_184;
#ifdef F_18
if ( V_122 -> V_192 && V_22 -> V_5 -> V_34 != V_122 -> V_192 )
goto V_184;
#endif
#else
goto V_184;
#endif
} else {
struct V_5 * V_6 = V_22 -> V_5 ;
V_6 -> V_45 = V_122 -> V_135 ;
V_6 -> V_46 = V_122 -> V_136 ;
V_6 -> V_49 = V_122 -> V_125 ;
#ifdef F_18
V_6 -> V_34 = V_122 -> V_192 ;
if ( V_6 -> V_34 )
V_22 -> V_28 -> V_35 . V_36 ++ ;
#endif
#ifdef F_27
V_6 -> V_48 = 1 ;
#endif
}
if ( V_185 [ V_122 -> V_182 ] . error ) {
if ( V_122 -> V_136 || V_122 -> V_135 || V_122 -> V_137 )
goto V_184;
goto V_193;
} else {
switch ( V_122 -> V_182 ) {
case V_146 :
case V_156 :
case V_194 :
case V_195 :
case V_196 :
break;
default:
goto V_184;
}
}
if ( V_122 -> V_144 > V_162 )
goto V_184;
if ( V_122 -> V_144 == V_162 ) {
struct V_5 * V_6 = V_22 -> V_5 ;
if ( V_120 != 1 || V_6 -> V_46 )
goto V_184;
V_6 -> V_47 = V_197 ;
V_6 -> V_25 = F_89 ( V_139 , V_22 -> V_5 -> V_45 ) ;
V_90 = - V_147 ;
if ( V_6 -> V_25 == NULL )
goto V_186;
} else {
F_12 (fi) {
V_90 = F_61 ( V_122 , V_22 , V_24 ) ;
if ( V_90 != 0 )
goto V_186;
} F_14 (fi)
}
if ( V_22 -> V_40 ) {
if ( V_122 -> V_182 != V_156 || ! V_122 -> V_198 ||
V_22 -> V_40 != V_122 -> V_198 )
if ( F_62 ( V_139 , V_22 -> V_40 ) != V_156 )
goto V_184;
}
F_12 (fi) {
F_81 ( V_139 , V_24 ) ;
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
& V_63 [ F_29 ( V_22 ) ] ) ;
if ( V_22 -> V_40 ) {
struct V_62 * V_20 ;
V_20 = & V_172 [ F_71 ( V_22 -> V_40 ) ] ;
F_80 ( & V_22 -> V_41 , V_20 ) ;
}
F_12 (fi) {
struct V_62 * V_20 ;
unsigned int V_8 ;
if ( ! V_24 -> V_25 )
continue;
V_8 = F_28 ( V_24 -> V_25 -> V_70 ) ;
V_20 = & V_71 [ V_8 ] ;
F_80 ( & V_24 -> V_42 , V_20 ) ;
} F_14 (fi)
F_24 ( & V_37 ) ;
return V_22 ;
V_184:
V_90 = - V_124 ;
V_186:
if ( V_22 ) {
V_22 -> V_32 = 1 ;
F_16 ( V_22 ) ;
}
return F_91 ( V_90 ) ;
}
int F_41 ( struct V_85 * V_86 , V_30 V_95 , V_30 V_87 , int V_76 ,
V_30 V_81 , T_5 type , T_3 V_4 , int V_80 , T_5 V_103 ,
struct V_21 * V_22 , unsigned int V_148 )
{
struct V_200 * V_88 ;
struct V_73 * V_201 ;
V_88 = F_92 ( V_86 , V_95 , V_87 , V_76 , sizeof( * V_201 ) , V_148 ) ;
if ( V_88 == NULL )
return - V_98 ;
V_201 = F_93 ( V_88 ) ;
V_201 -> V_202 = V_203 ;
V_201 -> V_204 = V_80 ;
V_201 -> V_205 = 0 ;
V_201 -> V_206 = V_103 ;
if ( V_81 < 256 )
V_201 -> V_207 = V_81 ;
else
V_201 -> V_207 = V_208 ;
if ( F_94 ( V_86 , V_209 , V_81 ) )
goto V_210;
V_201 -> V_211 = type ;
V_201 -> V_212 = V_22 -> V_66 ;
V_201 -> V_213 = V_22 -> V_58 ;
V_201 -> V_214 = V_22 -> V_57 ;
if ( V_201 -> V_204 &&
F_95 ( V_86 , V_215 , V_4 ) )
goto V_210;
if ( V_22 -> V_60 &&
F_94 ( V_86 , V_216 , V_22 -> V_60 ) )
goto V_210;
if ( F_96 ( V_86 , V_22 -> V_29 ) < 0 )
goto V_210;
if ( V_22 -> V_40 &&
F_95 ( V_86 , V_217 , V_22 -> V_40 ) )
goto V_210;
if ( V_22 -> V_56 == 1 ) {
if ( V_22 -> V_5 -> V_46 &&
F_95 ( V_86 , V_132 , V_22 -> V_5 -> V_46 ) )
goto V_210;
if ( V_22 -> V_5 -> V_45 &&
F_94 ( V_86 , V_218 , V_22 -> V_5 -> V_45 ) )
goto V_210;
#ifdef F_18
if ( V_22 -> V_5 [ 0 ] . V_34 &&
F_94 ( V_86 , V_133 , V_22 -> V_5 [ 0 ] . V_34 ) )
goto V_210;
#endif
}
#ifdef F_27
if ( V_22 -> V_56 > 1 ) {
struct V_75 * V_118 ;
struct V_129 * V_219 ;
V_219 = F_97 ( V_86 , V_220 ) ;
if ( V_219 == NULL )
goto V_210;
F_26 (fi) {
V_118 = F_98 ( V_86 , sizeof( * V_118 ) ) ;
if ( V_118 == NULL )
goto V_210;
V_118 -> V_126 = V_6 -> V_49 & 0xFF ;
V_118 -> V_128 = V_6 -> V_48 - 1 ;
V_118 -> V_127 = V_6 -> V_45 ;
if ( V_6 -> V_46 &&
F_95 ( V_86 , V_132 , V_6 -> V_46 ) )
goto V_210;
#ifdef F_18
if ( V_6 -> V_34 &&
F_94 ( V_86 , V_133 , V_6 -> V_34 ) )
goto V_210;
#endif
V_118 -> V_221 = F_99 ( V_86 ) - ( void * ) V_118 ;
} F_14 ( V_22 ) ;
F_100 ( V_86 , V_219 ) ;
}
#endif
return F_101 ( V_86 , V_88 ) ;
V_210:
F_102 ( V_86 , V_88 ) ;
return - V_98 ;
}
int F_103 ( struct V_139 * V_139 , T_3 V_222 )
{
int V_223 = 0 ;
unsigned int V_8 = F_71 ( V_222 ) ;
struct V_62 * V_20 = & V_172 [ V_8 ] ;
struct V_21 * V_22 ;
if ( V_172 == NULL || V_222 == 0 )
return 0 ;
F_31 (fi, head, fib_lhash) {
if ( ! F_32 ( V_22 -> V_28 , V_139 ) )
continue;
if ( V_22 -> V_40 == V_222 ) {
V_22 -> V_66 |= V_50 ;
V_223 ++ ;
}
}
return V_223 ;
}
int F_104 ( struct V_68 * V_69 , int V_224 )
{
int V_223 = 0 ;
int V_158 = V_197 ;
struct V_21 * V_225 = NULL ;
unsigned int V_8 = F_28 ( V_69 -> V_70 ) ;
struct V_62 * V_20 = & V_71 [ V_8 ] ;
struct V_5 * V_6 ;
if ( V_224 )
V_158 = - 1 ;
F_31 (nh, head, nh_hash) {
struct V_21 * V_22 = V_6 -> V_179 ;
int V_226 ;
F_105 ( ! V_22 -> V_56 ) ;
if ( V_6 -> V_25 != V_69 || V_22 == V_225 )
continue;
V_225 = V_22 ;
V_226 = 0 ;
F_12 (fi) {
if ( V_24 -> V_49 & V_50 )
V_226 ++ ;
else if ( V_24 -> V_25 == V_69 &&
V_24 -> V_47 != V_158 ) {
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
if ( V_224 > 1 && V_24 -> V_25 == V_69 ) {
V_226 = V_22 -> V_56 ;
break;
}
#endif
} F_14 (fi)
if ( V_226 == V_22 -> V_56 ) {
V_22 -> V_66 |= V_50 ;
V_223 ++ ;
}
}
return V_223 ;
}
void F_106 ( struct V_141 * V_142 )
{
struct V_21 * V_22 = NULL , * V_106 = NULL ;
struct V_101 * V_230 = V_142 -> V_230 ;
struct V_231 * V_232 = V_142 -> V_233 ;
int V_105 = - 1 , V_107 = - 1 ;
struct V_78 * V_79 ;
F_107 (fa, fa_head, fa_list) {
struct V_21 * V_234 = V_79 -> V_92 ;
if ( V_234 -> V_58 != V_142 -> V_158 ||
V_79 -> V_96 != V_146 )
continue;
if ( V_234 -> V_60 > V_142 -> V_22 -> V_60 )
break;
if ( ! V_234 -> V_5 [ 0 ] . V_46 ||
V_234 -> V_5 [ 0 ] . V_47 != V_145 )
continue;
F_108 ( V_79 ) ;
if ( V_22 == NULL ) {
if ( V_234 != V_142 -> V_22 )
break;
} else if ( ! F_48 ( V_22 , V_105 , & V_106 ,
& V_107 , V_232 -> V_235 ) ) {
F_109 ( V_142 , V_22 ) ;
V_232 -> V_235 = V_105 ;
goto V_157;
}
V_22 = V_234 ;
V_105 ++ ;
}
if ( V_105 <= 0 || V_22 == NULL ) {
V_232 -> V_235 = - 1 ;
goto V_157;
}
if ( ! F_48 ( V_22 , V_105 , & V_106 , & V_107 ,
V_232 -> V_235 ) ) {
F_109 ( V_142 , V_22 ) ;
V_232 -> V_235 = V_105 ;
goto V_157;
}
if ( V_107 >= 0 )
F_109 ( V_142 , V_106 ) ;
V_232 -> V_235 = V_107 ;
V_157:
return;
}
int F_110 ( struct V_68 * V_69 )
{
struct V_21 * V_225 ;
unsigned int V_8 ;
struct V_62 * V_20 ;
struct V_5 * V_6 ;
int V_223 ;
if ( ! ( V_69 -> V_148 & V_149 ) )
return 0 ;
V_225 = NULL ;
V_8 = F_28 ( V_69 -> V_70 ) ;
V_20 = & V_71 [ V_8 ] ;
V_223 = 0 ;
F_31 (nh, head, nh_hash) {
struct V_21 * V_22 = V_6 -> V_179 ;
int V_236 ;
F_105 ( ! V_22 -> V_56 ) ;
if ( V_6 -> V_25 != V_69 || V_22 == V_225 )
continue;
V_225 = V_22 ;
V_236 = 0 ;
F_12 (fi) {
if ( ! ( V_24 -> V_49 & V_50 ) ) {
V_236 ++ ;
continue;
}
if ( V_24 -> V_25 == NULL ||
! ( V_24 -> V_25 -> V_148 & V_149 ) )
continue;
if ( V_24 -> V_25 != V_69 ||
! F_111 ( V_69 ) )
continue;
V_236 ++ ;
F_21 ( & V_227 ) ;
V_24 -> V_229 = 0 ;
V_24 -> V_49 &= ~ V_50 ;
F_24 ( & V_227 ) ;
} F_14 (fi)
if ( V_236 > 0 ) {
V_22 -> V_66 &= ~ V_50 ;
V_223 ++ ;
}
}
return V_223 ;
}
void F_112 ( struct V_141 * V_142 )
{
struct V_21 * V_22 = V_142 -> V_22 ;
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
V_142 -> V_239 = 0 ;
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
V_142 -> V_239 = V_241 ;
F_24 ( & V_227 ) ;
return;
}
}
} F_14 ( V_22 ) ;
V_142 -> V_239 = 0 ;
F_24 ( & V_227 ) ;
}
