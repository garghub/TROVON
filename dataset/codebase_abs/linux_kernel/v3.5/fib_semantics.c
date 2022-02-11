static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 (fi) {
if ( V_6 -> V_7 )
F_4 ( V_6 -> V_7 ) ;
} F_5 ( V_4 ) ;
F_6 ( V_4 -> V_8 ) ;
if ( V_4 -> V_9 != ( V_10 * ) V_11 )
F_7 ( V_4 -> V_9 ) ;
F_7 ( V_4 ) ;
}
void F_8 ( struct V_3 * V_4 )
{
if ( V_4 -> V_12 == 0 ) {
F_9 ( L_1 , V_4 ) ;
return;
}
V_13 -- ;
F_10 ( & V_4 -> V_5 , F_1 ) ;
}
void F_11 ( struct V_3 * V_4 )
{
F_12 ( & V_14 ) ;
if ( V_4 && -- V_4 -> V_15 == 0 ) {
F_13 ( & V_4 -> V_16 ) ;
if ( V_4 -> V_17 )
F_13 ( & V_4 -> V_18 ) ;
F_3 (fi) {
if ( ! V_6 -> V_7 )
continue;
F_13 ( & V_6 -> V_19 ) ;
} F_5 (fi)
V_4 -> V_12 = 1 ;
F_14 ( V_4 ) ;
}
F_15 ( & V_14 ) ;
}
static inline int F_16 ( const struct V_3 * V_4 , const struct V_3 * V_20 )
{
const struct V_21 * V_22 = V_20 -> V_21 ;
F_17 (fi) {
if ( V_23 -> V_24 != V_22 -> V_24 ||
V_23 -> V_25 != V_22 -> V_25 ||
V_23 -> V_26 != V_22 -> V_26 ||
#ifdef F_18
V_23 -> V_27 != V_22 -> V_27 ||
#endif
#ifdef F_19
V_23 -> V_28 != V_22 -> V_28 ||
#endif
( ( V_23 -> V_29 ^ V_22 -> V_29 ) & ~ V_30 ) )
return - 1 ;
V_22 ++ ;
} F_5 ( V_4 ) ;
return 0 ;
}
static inline unsigned int F_20 ( unsigned int V_31 )
{
unsigned int V_32 = V_33 - 1 ;
return ( V_31 ^
( V_31 >> V_34 ) ^
( V_31 >> ( V_34 * 2 ) ) ) & V_32 ;
}
static inline unsigned int F_21 ( const struct V_3 * V_4 )
{
unsigned int V_32 = ( V_35 - 1 ) ;
unsigned int V_31 = V_4 -> V_36 ;
V_31 ^= ( V_4 -> V_37 << 8 ) | V_4 -> V_38 ;
V_31 ^= ( V_39 V_10 ) V_4 -> V_17 ;
V_31 ^= V_4 -> V_40 ;
F_17 (fi) {
V_31 ^= F_20 ( V_23 -> V_24 ) ;
} F_5 (fi)
return ( V_31 ^ ( V_31 >> 7 ) ^ ( V_31 >> 12 ) ) & V_32 ;
}
static struct V_3 * F_22 ( const struct V_3 * V_41 )
{
struct V_42 * V_2 ;
struct V_43 * V_44 ;
struct V_3 * V_4 ;
unsigned int V_45 ;
V_45 = F_21 ( V_41 ) ;
V_2 = & V_46 [ V_45 ] ;
F_23 (fi, node, head, fib_hash) {
if ( ! F_24 ( V_4 -> V_8 , V_41 -> V_8 ) )
continue;
if ( V_4 -> V_36 != V_41 -> V_36 )
continue;
if ( V_41 -> V_37 == V_4 -> V_37 &&
V_41 -> V_38 == V_4 -> V_38 &&
V_41 -> V_17 == V_4 -> V_17 &&
V_41 -> V_40 == V_4 -> V_40 &&
memcmp ( V_41 -> V_9 , V_4 -> V_9 ,
sizeof( V_10 ) * V_47 ) == 0 &&
( ( V_41 -> V_48 ^ V_4 -> V_48 ) & ~ V_30 ) == 0 &&
( V_41 -> V_36 == 0 || F_16 ( V_4 , V_41 ) == 0 ) )
return V_4 ;
}
return NULL ;
}
int F_25 ( T_1 V_49 , struct V_50 * V_51 )
{
struct V_42 * V_2 ;
struct V_43 * V_44 ;
struct V_21 * V_23 ;
unsigned int V_45 ;
F_26 ( & V_14 ) ;
V_45 = F_20 ( V_51 -> V_52 ) ;
V_2 = & V_53 [ V_45 ] ;
F_23 (nh, node, head, nh_hash) {
if ( V_23 -> V_7 == V_51 &&
V_23 -> V_25 == V_49 &&
! ( V_23 -> V_29 & V_30 ) ) {
F_27 ( & V_14 ) ;
return 0 ;
}
}
F_27 ( & V_14 ) ;
return - 1 ;
}
static inline T_2 F_28 ( struct V_3 * V_4 )
{
T_2 V_54 = F_29 ( sizeof( struct V_55 ) )
+ F_30 ( 4 )
+ F_30 ( 4 )
+ F_30 ( 4 )
+ F_30 ( 4 ) ;
V_54 += F_30 ( ( V_47 * F_30 ( 4 ) ) ) ;
if ( V_4 -> V_36 ) {
T_2 V_56 = F_30 ( sizeof( struct V_57 ) ) ;
V_56 += 2 * F_30 ( 4 ) ;
V_54 += F_30 ( V_4 -> V_36 * V_56 ) ;
}
return V_54 ;
}
void F_31 ( int V_58 , T_1 V_59 , struct V_60 * V_61 ,
int V_62 , V_10 V_63 , struct V_64 * V_65 ,
unsigned int V_66 )
{
struct V_67 * V_68 ;
V_10 V_69 = V_65 -> V_70 ? V_65 -> V_70 -> V_71 : 0 ;
int V_72 = - V_73 ;
V_68 = F_32 ( F_28 ( V_61 -> V_74 ) , V_75 ) ;
if ( V_68 == NULL )
goto V_76;
V_72 = F_33 ( V_68 , V_65 -> V_77 , V_69 , V_58 , V_63 ,
V_61 -> V_78 , V_59 , V_62 ,
V_61 -> V_79 , V_61 -> V_74 , V_66 ) ;
if ( V_72 < 0 ) {
F_34 ( V_72 == - V_80 ) ;
F_35 ( V_68 ) ;
goto V_76;
}
F_36 ( V_68 , V_65 -> V_81 , V_65 -> V_77 , V_82 ,
V_65 -> V_70 , V_75 ) ;
return;
V_76:
if ( V_72 < 0 )
F_37 ( V_65 -> V_81 , V_82 , V_72 ) ;
}
struct V_60 * F_38 ( struct V_83 * V_84 , T_3 V_85 , V_10 V_86 )
{
if ( V_84 ) {
struct V_60 * V_61 ;
F_39 (fa, fah, fa_list) {
if ( V_61 -> V_79 > V_85 )
continue;
if ( V_61 -> V_74 -> V_40 >= V_86 ||
V_61 -> V_79 < V_85 )
return V_61 ;
}
}
return NULL ;
}
int F_40 ( struct V_3 * V_4 , int V_87 ,
struct V_3 * * V_88 , int * V_89 , int V_90 )
{
struct V_91 * V_92 ;
int V_93 = V_94 ;
V_92 = F_41 ( & V_95 , & V_4 -> V_21 [ 0 ] . V_25 , V_4 -> V_96 ) ;
if ( V_92 ) {
V_93 = V_92 -> V_97 ;
F_42 ( V_92 ) ;
}
if ( V_93 == V_98 )
return 0 ;
if ( ( V_93 & V_99 ) && V_87 != V_90 )
return 0 ;
if ( ( V_93 & V_99 ) ||
( * V_89 < 0 && V_87 > V_90 ) ) {
* V_88 = V_4 ;
* V_89 = V_87 ;
}
return 1 ;
}
static int F_43 ( struct V_57 * V_100 , int V_101 )
{
int V_102 = 0 ;
while ( F_44 ( V_100 , V_101 ) ) {
V_102 ++ ;
V_100 = F_45 ( V_100 , & V_101 ) ;
}
return V_101 > 0 ? 0 : V_102 ;
}
static int F_46 ( struct V_3 * V_4 , struct V_57 * V_100 ,
int V_101 , struct V_103 * V_104 )
{
F_3 (fi) {
int V_105 ;
if ( ! F_44 ( V_100 , V_101 ) )
return - V_106 ;
V_6 -> V_29 =
( V_104 -> V_107 & ~ 0xFF ) | V_100 -> V_108 ;
V_6 -> V_24 = V_100 -> V_109 ;
V_6 -> V_27 = V_100 -> V_110 + 1 ;
V_105 = F_47 ( V_100 ) ;
if ( V_105 > 0 ) {
struct V_111 * V_112 , * V_113 = F_48 ( V_100 ) ;
V_112 = F_49 ( V_113 , V_105 , V_114 ) ;
V_6 -> V_25 = V_112 ? F_50 ( V_112 ) : 0 ;
#ifdef F_19
V_112 = F_49 ( V_113 , V_105 , V_115 ) ;
V_6 -> V_28 = V_112 ? F_51 ( V_112 ) : 0 ;
#endif
}
V_100 = F_45 ( V_100 , & V_101 ) ;
} F_5 ( V_4 ) ;
return 0 ;
}
int F_52 ( struct V_103 * V_104 , struct V_3 * V_4 )
{
#ifdef F_18
struct V_57 * V_100 ;
int V_101 ;
#endif
if ( V_104 -> V_116 && V_104 -> V_116 != V_4 -> V_40 )
return 1 ;
if ( V_104 -> V_117 || V_104 -> V_118 ) {
if ( ( ! V_104 -> V_117 || V_104 -> V_117 == V_4 -> V_21 -> V_24 ) &&
( ! V_104 -> V_118 || V_104 -> V_118 == V_4 -> V_21 -> V_25 ) )
return 0 ;
return 1 ;
}
#ifdef F_18
if ( V_104 -> V_119 == NULL )
return 0 ;
V_100 = V_104 -> V_119 ;
V_101 = V_104 -> V_120 ;
F_17 (fi) {
int V_105 ;
if ( ! F_44 ( V_100 , V_101 ) )
return - V_106 ;
if ( V_100 -> V_109 && V_100 -> V_109 != V_23 -> V_24 )
return 1 ;
V_105 = F_47 ( V_100 ) ;
if ( V_105 < 0 ) {
struct V_111 * V_112 , * V_113 = F_48 ( V_100 ) ;
V_112 = F_49 ( V_113 , V_105 , V_114 ) ;
if ( V_112 && F_50 ( V_112 ) != V_23 -> V_25 )
return 1 ;
#ifdef F_19
V_112 = F_49 ( V_113 , V_105 , V_115 ) ;
if ( V_112 && F_51 ( V_112 ) != V_23 -> V_28 )
return 1 ;
#endif
}
V_100 = F_45 ( V_100 , & V_101 ) ;
} F_5 ( V_4 ) ;
#endif
return 0 ;
}
static int F_53 ( struct V_103 * V_104 , struct V_3 * V_4 ,
struct V_21 * V_23 )
{
int V_72 ;
struct V_121 * V_121 ;
struct V_50 * V_51 ;
V_121 = V_104 -> V_122 . V_81 ;
if ( V_23 -> V_25 ) {
struct V_123 V_124 ;
if ( V_23 -> V_29 & V_125 ) {
if ( V_104 -> V_126 >= V_127 )
return - V_106 ;
if ( F_54 ( V_121 , V_23 -> V_25 ) != V_128 )
return - V_106 ;
V_51 = F_55 ( V_121 , V_23 -> V_24 ) ;
if ( ! V_51 )
return - V_129 ;
if ( ! ( V_51 -> V_130 & V_131 ) )
return - V_132 ;
V_23 -> V_7 = V_51 ;
F_56 ( V_51 ) ;
V_23 -> V_26 = V_127 ;
return 0 ;
}
F_57 () ;
{
struct V_133 V_134 = {
. V_135 = V_23 -> V_25 ,
. V_136 = V_104 -> V_126 + 1 ,
. V_137 = V_23 -> V_24 ,
} ;
if ( V_134 . V_136 < V_127 )
V_134 . V_136 = V_127 ;
V_72 = F_58 ( V_121 , & V_134 , & V_124 ) ;
if ( V_72 ) {
F_59 () ;
return V_72 ;
}
}
V_72 = - V_106 ;
if ( V_124 . type != V_128 && V_124 . type != V_138 )
goto V_139;
V_23 -> V_26 = V_124 . V_140 ;
V_23 -> V_24 = F_60 ( V_124 ) ;
V_23 -> V_7 = V_51 = F_61 ( V_124 ) ;
if ( ! V_51 )
goto V_139;
F_56 ( V_51 ) ;
V_72 = ( V_51 -> V_130 & V_131 ) ? 0 : - V_132 ;
} else {
struct V_141 * V_142 ;
if ( V_23 -> V_29 & ( V_143 | V_125 ) )
return - V_106 ;
F_57 () ;
V_72 = - V_129 ;
V_142 = F_62 ( V_121 , V_23 -> V_24 ) ;
if ( V_142 == NULL )
goto V_139;
V_72 = - V_132 ;
if ( ! ( V_142 -> V_51 -> V_130 & V_131 ) )
goto V_139;
V_23 -> V_7 = V_142 -> V_51 ;
F_56 ( V_23 -> V_7 ) ;
V_23 -> V_26 = V_144 ;
V_72 = 0 ;
}
V_139:
F_59 () ;
return V_72 ;
}
static inline unsigned int F_63 ( T_1 V_31 )
{
unsigned int V_32 = ( V_35 - 1 ) ;
return ( ( V_39 V_10 ) V_31 ^
( ( V_39 V_10 ) V_31 >> 7 ) ^
( ( V_39 V_10 ) V_31 >> 14 ) ) & V_32 ;
}
static struct V_42 * F_64 ( int V_145 )
{
if ( V_145 <= V_146 )
return F_65 ( V_145 , V_75 ) ;
else
return (struct V_42 * )
F_66 ( V_75 | V_147 ,
F_67 ( V_145 ) ) ;
}
static void F_68 ( struct V_42 * V_45 , int V_145 )
{
if ( ! V_45 )
return;
if ( V_145 <= V_146 )
F_7 ( V_45 ) ;
else
F_69 ( ( unsigned long ) V_45 , F_67 ( V_145 ) ) ;
}
static void F_70 ( struct V_42 * V_148 ,
struct V_42 * V_149 ,
unsigned int V_150 )
{
struct V_42 * V_151 , * V_152 ;
unsigned int V_153 = V_35 ;
unsigned int V_154 , V_145 ;
F_12 ( & V_14 ) ;
V_151 = V_46 ;
V_152 = V_155 ;
V_35 = V_150 ;
for ( V_154 = 0 ; V_154 < V_153 ; V_154 ++ ) {
struct V_42 * V_2 = & V_46 [ V_154 ] ;
struct V_43 * V_44 , * V_92 ;
struct V_3 * V_4 ;
F_71 (fi, node, n, head, fib_hash) {
struct V_42 * V_156 ;
unsigned int V_157 ;
F_13 ( & V_4 -> V_16 ) ;
V_157 = F_21 ( V_4 ) ;
V_156 = & V_148 [ V_157 ] ;
F_72 ( & V_4 -> V_16 , V_156 ) ;
}
}
V_46 = V_148 ;
for ( V_154 = 0 ; V_154 < V_153 ; V_154 ++ ) {
struct V_42 * V_158 = & V_155 [ V_154 ] ;
struct V_43 * V_44 , * V_92 ;
struct V_3 * V_4 ;
F_71 (fi, node, n, lhead, fib_lhash) {
struct V_42 * V_159 ;
unsigned int V_157 ;
F_13 ( & V_4 -> V_18 ) ;
V_157 = F_63 ( V_4 -> V_17 ) ;
V_159 = & V_149 [ V_157 ] ;
F_72 ( & V_4 -> V_18 , V_159 ) ;
}
}
V_155 = V_149 ;
F_15 ( & V_14 ) ;
V_145 = V_153 * sizeof( struct V_42 * ) ;
F_68 ( V_151 , V_145 ) ;
F_68 ( V_152 , V_145 ) ;
}
T_1 F_73 ( struct V_121 * V_121 , struct V_21 * V_23 )
{
V_23 -> V_160 = F_74 ( V_23 -> V_7 ,
V_23 -> V_25 ,
V_23 -> V_161 -> V_38 ) ;
V_23 -> V_162 = F_75 ( & V_121 -> V_163 . V_164 ) ;
return V_23 -> V_160 ;
}
struct V_3 * F_76 ( struct V_103 * V_104 )
{
int V_72 ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_20 ;
int V_102 = 1 ;
struct V_121 * V_121 = V_104 -> V_122 . V_81 ;
if ( V_104 -> V_165 > V_166 )
goto V_167;
if ( V_168 [ V_104 -> V_165 ] . V_140 > V_104 -> V_126 )
goto V_167;
#ifdef F_18
if ( V_104 -> V_119 ) {
V_102 = F_43 ( V_104 -> V_119 , V_104 -> V_120 ) ;
if ( V_102 == 0 )
goto V_167;
}
#endif
V_72 = - V_73 ;
if ( V_13 >= V_35 ) {
unsigned int V_150 = V_35 << 1 ;
struct V_42 * V_148 ;
struct V_42 * V_149 ;
unsigned int V_145 ;
if ( ! V_150 )
V_150 = 1 ;
V_145 = V_150 * sizeof( struct V_42 * ) ;
V_148 = F_64 ( V_145 ) ;
V_149 = F_64 ( V_145 ) ;
if ( ! V_148 || ! V_149 ) {
F_68 ( V_148 , V_145 ) ;
F_68 ( V_149 , V_145 ) ;
} else
F_70 ( V_148 , V_149 , V_150 ) ;
if ( ! V_35 )
goto V_169;
}
V_4 = F_65 ( sizeof( * V_4 ) + V_102 * sizeof( struct V_21 ) , V_75 ) ;
if ( V_4 == NULL )
goto V_169;
if ( V_104 -> V_170 ) {
V_4 -> V_9 = F_65 ( sizeof( V_10 ) * V_47 , V_75 ) ;
if ( ! V_4 -> V_9 )
goto V_169;
} else
V_4 -> V_9 = ( V_10 * ) V_11 ;
V_13 ++ ;
V_4 -> V_8 = F_77 ( V_121 ) ;
V_4 -> V_37 = V_104 -> V_171 ;
V_4 -> V_38 = V_104 -> V_126 ;
V_4 -> V_48 = V_104 -> V_107 ;
V_4 -> V_40 = V_104 -> V_116 ;
V_4 -> V_17 = V_104 -> V_172 ;
V_4 -> V_36 = V_102 ;
F_3 (fi) {
V_6 -> V_161 = V_4 ;
} F_5 (fi)
if ( V_104 -> V_170 ) {
struct V_111 * V_112 ;
int V_101 ;
F_78 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_79 ( V_112 ) ;
if ( type ) {
if ( type > V_47 )
goto V_167;
V_4 -> V_9 [ type - 1 ] = F_51 ( V_112 ) ;
}
}
}
if ( V_104 -> V_119 ) {
#ifdef F_18
V_72 = F_46 ( V_4 , V_104 -> V_119 , V_104 -> V_120 , V_104 ) ;
if ( V_72 != 0 )
goto V_169;
if ( V_104 -> V_117 && V_4 -> V_21 -> V_24 != V_104 -> V_117 )
goto V_167;
if ( V_104 -> V_118 && V_4 -> V_21 -> V_25 != V_104 -> V_118 )
goto V_167;
#ifdef F_19
if ( V_104 -> V_173 && V_4 -> V_21 -> V_28 != V_104 -> V_173 )
goto V_167;
#endif
#else
goto V_167;
#endif
} else {
struct V_21 * V_23 = V_4 -> V_21 ;
V_23 -> V_24 = V_104 -> V_117 ;
V_23 -> V_25 = V_104 -> V_118 ;
V_23 -> V_29 = V_104 -> V_107 ;
#ifdef F_19
V_23 -> V_28 = V_104 -> V_173 ;
#endif
#ifdef F_18
V_23 -> V_27 = 1 ;
#endif
}
if ( V_168 [ V_104 -> V_165 ] . error ) {
if ( V_104 -> V_118 || V_104 -> V_117 || V_104 -> V_119 )
goto V_167;
goto V_174;
} else {
switch ( V_104 -> V_165 ) {
case V_128 :
case V_138 :
case V_175 :
case V_176 :
case V_177 :
break;
default:
goto V_167;
}
}
if ( V_104 -> V_126 > V_144 )
goto V_167;
if ( V_104 -> V_126 == V_144 ) {
struct V_21 * V_23 = V_4 -> V_21 ;
if ( V_102 != 1 || V_23 -> V_25 )
goto V_167;
V_23 -> V_26 = V_178 ;
V_23 -> V_7 = F_80 ( V_121 , V_4 -> V_21 -> V_24 ) ;
V_72 = - V_129 ;
if ( V_23 -> V_7 == NULL )
goto V_169;
} else {
F_3 (fi) {
V_72 = F_53 ( V_104 , V_4 , V_6 ) ;
if ( V_72 != 0 )
goto V_169;
} F_5 (fi)
}
if ( V_4 -> V_17 ) {
if ( V_104 -> V_165 != V_138 || ! V_104 -> V_179 ||
V_4 -> V_17 != V_104 -> V_179 )
if ( F_54 ( V_121 , V_4 -> V_17 ) != V_138 )
goto V_167;
}
F_3 (fi) {
F_73 ( V_121 , V_6 ) ;
} F_5 (fi)
V_174:
V_20 = F_22 ( V_4 ) ;
if ( V_20 ) {
V_4 -> V_12 = 1 ;
F_8 ( V_4 ) ;
V_20 -> V_15 ++ ;
return V_20 ;
}
V_4 -> V_15 ++ ;
F_81 ( & V_4 -> V_180 ) ;
F_12 ( & V_14 ) ;
F_72 ( & V_4 -> V_16 ,
& V_46 [ F_21 ( V_4 ) ] ) ;
if ( V_4 -> V_17 ) {
struct V_42 * V_2 ;
V_2 = & V_155 [ F_63 ( V_4 -> V_17 ) ] ;
F_72 ( & V_4 -> V_18 , V_2 ) ;
}
F_3 (fi) {
struct V_42 * V_2 ;
unsigned int V_45 ;
if ( ! V_6 -> V_7 )
continue;
V_45 = F_20 ( V_6 -> V_7 -> V_52 ) ;
V_2 = & V_53 [ V_45 ] ;
F_72 ( & V_6 -> V_19 , V_2 ) ;
} F_5 (fi)
F_15 ( & V_14 ) ;
return V_4 ;
V_167:
V_72 = - V_106 ;
V_169:
if ( V_4 ) {
V_4 -> V_12 = 1 ;
F_8 ( V_4 ) ;
}
return F_82 ( V_72 ) ;
}
int F_33 ( struct V_67 * V_68 , V_10 V_77 , V_10 V_69 , int V_58 ,
V_10 V_63 , T_3 type , T_1 V_181 , int V_62 , T_3 V_85 ,
struct V_3 * V_4 , unsigned int V_130 )
{
struct V_182 * V_70 ;
struct V_55 * V_183 ;
V_70 = F_83 ( V_68 , V_77 , V_69 , V_58 , sizeof( * V_183 ) , V_130 ) ;
if ( V_70 == NULL )
return - V_80 ;
V_183 = F_84 ( V_70 ) ;
V_183 -> V_184 = V_185 ;
V_183 -> V_186 = V_62 ;
V_183 -> V_187 = 0 ;
V_183 -> V_188 = V_85 ;
if ( V_63 < 256 )
V_183 -> V_189 = V_63 ;
else
V_183 -> V_189 = V_190 ;
if ( F_85 ( V_68 , V_191 , V_63 ) )
goto V_192;
V_183 -> V_193 = type ;
V_183 -> V_194 = V_4 -> V_48 ;
V_183 -> V_195 = V_4 -> V_38 ;
V_183 -> V_196 = V_4 -> V_37 ;
if ( V_183 -> V_186 &&
F_86 ( V_68 , V_197 , V_181 ) )
goto V_192;
if ( V_4 -> V_40 &&
F_85 ( V_68 , V_198 , V_4 -> V_40 ) )
goto V_192;
if ( F_87 ( V_68 , V_4 -> V_9 ) < 0 )
goto V_192;
if ( V_4 -> V_17 &&
F_86 ( V_68 , V_199 , V_4 -> V_17 ) )
goto V_192;
if ( V_4 -> V_36 == 1 ) {
if ( V_4 -> V_21 -> V_25 &&
F_86 ( V_68 , V_114 , V_4 -> V_21 -> V_25 ) )
goto V_192;
if ( V_4 -> V_21 -> V_24 &&
F_85 ( V_68 , V_200 , V_4 -> V_21 -> V_24 ) )
goto V_192;
#ifdef F_19
if ( V_4 -> V_21 [ 0 ] . V_28 &&
F_85 ( V_68 , V_115 , V_4 -> V_21 [ 0 ] . V_28 ) )
goto V_192;
#endif
}
#ifdef F_18
if ( V_4 -> V_36 > 1 ) {
struct V_57 * V_100 ;
struct V_111 * V_201 ;
V_201 = F_88 ( V_68 , V_202 ) ;
if ( V_201 == NULL )
goto V_192;
F_17 (fi) {
V_100 = F_89 ( V_68 , sizeof( * V_100 ) ) ;
if ( V_100 == NULL )
goto V_192;
V_100 -> V_108 = V_23 -> V_29 & 0xFF ;
V_100 -> V_110 = V_23 -> V_27 - 1 ;
V_100 -> V_109 = V_23 -> V_24 ;
if ( V_23 -> V_25 &&
F_86 ( V_68 , V_114 , V_23 -> V_25 ) )
goto V_192;
#ifdef F_19
if ( V_23 -> V_28 &&
F_85 ( V_68 , V_115 , V_23 -> V_28 ) )
goto V_192;
#endif
V_100 -> V_203 = F_90 ( V_68 ) - ( void * ) V_100 ;
} F_5 ( V_4 ) ;
F_91 ( V_68 , V_201 ) ;
}
#endif
return F_92 ( V_68 , V_70 ) ;
V_192:
F_93 ( V_68 , V_70 ) ;
return - V_80 ;
}
int F_94 ( struct V_121 * V_121 , T_1 V_204 )
{
int V_205 = 0 ;
unsigned int V_45 = F_63 ( V_204 ) ;
struct V_42 * V_2 = & V_155 [ V_45 ] ;
struct V_43 * V_44 ;
struct V_3 * V_4 ;
if ( V_155 == NULL || V_204 == 0 )
return 0 ;
F_23 (fi, node, head, fib_lhash) {
if ( ! F_24 ( V_4 -> V_8 , V_121 ) )
continue;
if ( V_4 -> V_17 == V_204 ) {
V_4 -> V_48 |= V_30 ;
V_205 ++ ;
}
}
return V_205 ;
}
int F_95 ( struct V_50 * V_51 , int V_206 )
{
int V_205 = 0 ;
int V_140 = V_178 ;
struct V_3 * V_207 = NULL ;
unsigned int V_45 = F_20 ( V_51 -> V_52 ) ;
struct V_42 * V_2 = & V_53 [ V_45 ] ;
struct V_43 * V_44 ;
struct V_21 * V_23 ;
if ( V_206 )
V_140 = - 1 ;
F_23 (nh, node, head, nh_hash) {
struct V_3 * V_4 = V_23 -> V_161 ;
int V_208 ;
F_96 ( ! V_4 -> V_36 ) ;
if ( V_23 -> V_7 != V_51 || V_4 == V_207 )
continue;
V_207 = V_4 ;
V_208 = 0 ;
F_3 (fi) {
if ( V_6 -> V_29 & V_30 )
V_208 ++ ;
else if ( V_6 -> V_7 == V_51 &&
V_6 -> V_26 != V_140 ) {
V_6 -> V_29 |= V_30 ;
#ifdef F_18
F_12 ( & V_209 ) ;
V_4 -> V_210 -= V_6 -> V_211 ;
V_6 -> V_211 = 0 ;
F_15 ( & V_209 ) ;
#endif
V_208 ++ ;
}
#ifdef F_18
if ( V_206 > 1 && V_6 -> V_7 == V_51 ) {
V_208 = V_4 -> V_36 ;
break;
}
#endif
} F_5 (fi)
if ( V_208 == V_4 -> V_36 ) {
V_4 -> V_48 |= V_30 ;
V_205 ++ ;
}
}
return V_205 ;
}
void F_97 ( struct V_123 * V_124 )
{
struct V_3 * V_4 = NULL , * V_88 = NULL ;
struct V_83 * V_212 = V_124 -> V_212 ;
struct V_213 * V_214 = V_124 -> V_215 ;
int V_87 = - 1 , V_89 = - 1 ;
struct V_60 * V_61 ;
F_98 (fa, fa_head, fa_list) {
struct V_3 * V_216 = V_61 -> V_74 ;
if ( V_216 -> V_38 != V_124 -> V_140 ||
V_61 -> V_78 != V_128 )
continue;
if ( V_216 -> V_40 > V_124 -> V_4 -> V_40 )
break;
if ( ! V_216 -> V_21 [ 0 ] . V_25 ||
V_216 -> V_21 [ 0 ] . V_26 != V_127 )
continue;
F_99 ( V_61 ) ;
if ( V_4 == NULL ) {
if ( V_216 != V_124 -> V_4 )
break;
} else if ( ! F_40 ( V_4 , V_87 , & V_88 ,
& V_89 , V_214 -> V_217 ) ) {
F_100 ( V_124 , V_4 ) ;
V_214 -> V_217 = V_87 ;
goto V_139;
}
V_4 = V_216 ;
V_87 ++ ;
}
if ( V_87 <= 0 || V_4 == NULL ) {
V_214 -> V_217 = - 1 ;
goto V_139;
}
if ( ! F_40 ( V_4 , V_87 , & V_88 , & V_89 ,
V_214 -> V_217 ) ) {
F_100 ( V_124 , V_4 ) ;
V_214 -> V_217 = V_87 ;
goto V_139;
}
if ( V_89 >= 0 )
F_100 ( V_124 , V_88 ) ;
V_214 -> V_217 = V_89 ;
V_139:
return;
}
int F_101 ( struct V_50 * V_51 )
{
struct V_3 * V_207 ;
unsigned int V_45 ;
struct V_42 * V_2 ;
struct V_43 * V_44 ;
struct V_21 * V_23 ;
int V_205 ;
if ( ! ( V_51 -> V_130 & V_131 ) )
return 0 ;
V_207 = NULL ;
V_45 = F_20 ( V_51 -> V_52 ) ;
V_2 = & V_53 [ V_45 ] ;
V_205 = 0 ;
F_23 (nh, node, head, nh_hash) {
struct V_3 * V_4 = V_23 -> V_161 ;
int V_218 ;
F_96 ( ! V_4 -> V_36 ) ;
if ( V_23 -> V_7 != V_51 || V_4 == V_207 )
continue;
V_207 = V_4 ;
V_218 = 0 ;
F_3 (fi) {
if ( ! ( V_6 -> V_29 & V_30 ) ) {
V_218 ++ ;
continue;
}
if ( V_6 -> V_7 == NULL ||
! ( V_6 -> V_7 -> V_130 & V_131 ) )
continue;
if ( V_6 -> V_7 != V_51 ||
! F_102 ( V_51 ) )
continue;
V_218 ++ ;
F_12 ( & V_209 ) ;
V_6 -> V_211 = 0 ;
V_6 -> V_29 &= ~ V_30 ;
F_15 ( & V_209 ) ;
} F_5 (fi)
if ( V_218 > 0 ) {
V_4 -> V_48 &= ~ V_30 ;
V_205 ++ ;
}
}
return V_205 ;
}
void F_103 ( struct V_123 * V_124 )
{
struct V_3 * V_4 = V_124 -> V_4 ;
int V_219 ;
F_12 ( & V_209 ) ;
if ( V_4 -> V_210 <= 0 ) {
int V_220 = 0 ;
F_3 (fi) {
if ( ! ( V_6 -> V_29 & V_30 ) ) {
V_220 += V_6 -> V_27 ;
V_6 -> V_211 = V_6 -> V_27 ;
}
} F_5 ( V_4 ) ;
V_4 -> V_210 = V_220 ;
if ( V_220 <= 0 ) {
F_15 ( & V_209 ) ;
V_124 -> V_221 = 0 ;
return;
}
}
V_219 = V_222 % V_4 -> V_210 ;
F_3 (fi) {
if ( ! ( V_6 -> V_29 & V_30 ) &&
V_6 -> V_211 ) {
V_219 -= V_6 -> V_211 ;
if ( V_219 <= 0 ) {
V_6 -> V_211 -- ;
V_4 -> V_210 -- ;
V_124 -> V_221 = V_223 ;
F_15 ( & V_209 ) ;
return;
}
}
} F_5 ( V_4 ) ;
V_124 -> V_221 = 0 ;
F_15 ( & V_209 ) ;
}
