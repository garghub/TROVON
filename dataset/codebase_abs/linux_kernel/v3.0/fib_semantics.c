void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0 ) {
F_2 ( L_1 , V_2 ) ;
return;
}
F_3 (fi) {
if ( V_4 -> V_5 )
F_4 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
} F_5 ( V_2 ) ;
V_6 -- ;
F_6 ( V_2 -> V_7 ) ;
F_7 ( V_2 , V_8 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_9 ) ;
if ( V_2 && -- V_2 -> V_10 == 0 ) {
F_10 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_12 )
F_10 ( & V_2 -> V_13 ) ;
F_3 (fi) {
if ( ! V_4 -> V_5 )
continue;
F_10 ( & V_4 -> V_14 ) ;
} F_5 (fi)
V_2 -> V_3 = 1 ;
F_11 ( V_2 ) ;
}
F_12 ( & V_9 ) ;
}
static inline int F_13 ( const struct V_1 * V_2 , const struct V_1 * V_15 )
{
const struct V_16 * V_17 = V_15 -> V_16 ;
F_14 (fi) {
if ( V_18 -> V_19 != V_17 -> V_19 ||
V_18 -> V_20 != V_17 -> V_20 ||
V_18 -> V_21 != V_17 -> V_21 ||
#ifdef F_15
V_18 -> V_22 != V_17 -> V_22 ||
#endif
#ifdef F_16
V_18 -> V_23 != V_17 -> V_23 ||
#endif
( ( V_18 -> V_24 ^ V_17 -> V_24 ) & ~ V_25 ) )
return - 1 ;
V_17 ++ ;
} F_5 ( V_2 ) ;
return 0 ;
}
static inline unsigned int F_17 ( unsigned int V_26 )
{
unsigned int V_27 = V_28 - 1 ;
return ( V_26 ^
( V_26 >> V_29 ) ^
( V_26 >> ( V_29 * 2 ) ) ) & V_27 ;
}
static inline unsigned int F_18 ( const struct V_1 * V_2 )
{
unsigned int V_27 = ( V_30 - 1 ) ;
unsigned int V_26 = V_2 -> V_31 ;
V_26 ^= ( V_2 -> V_32 << 8 ) | V_2 -> V_33 ;
V_26 ^= ( V_34 V_35 ) V_2 -> V_12 ;
V_26 ^= V_2 -> V_36 ;
F_14 (fi) {
V_26 ^= F_17 ( V_18 -> V_19 ) ;
} F_5 (fi)
return ( V_26 ^ ( V_26 >> 7 ) ^ ( V_26 >> 12 ) ) & V_27 ;
}
static struct V_1 * F_19 ( const struct V_1 * V_37 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
unsigned int V_42 ;
V_42 = F_18 ( V_37 ) ;
V_39 = & V_43 [ V_42 ] ;
F_20 (fi, node, head, fib_hash) {
if ( ! F_21 ( V_2 -> V_7 , V_37 -> V_7 ) )
continue;
if ( V_2 -> V_31 != V_37 -> V_31 )
continue;
if ( V_37 -> V_32 == V_2 -> V_32 &&
V_37 -> V_33 == V_2 -> V_33 &&
V_37 -> V_12 == V_2 -> V_12 &&
V_37 -> V_36 == V_2 -> V_36 &&
memcmp ( V_37 -> V_44 , V_2 -> V_44 ,
sizeof( V_35 ) * V_45 ) == 0 &&
( ( V_37 -> V_46 ^ V_2 -> V_46 ) & ~ V_25 ) == 0 &&
( V_37 -> V_31 == 0 || F_13 ( V_2 , V_37 ) == 0 ) )
return V_2 ;
}
return NULL ;
}
int F_22 ( T_1 V_47 , struct V_48 * V_49 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_16 * V_18 ;
unsigned int V_42 ;
F_23 ( & V_9 ) ;
V_42 = F_17 ( V_49 -> V_50 ) ;
V_39 = & V_51 [ V_42 ] ;
F_20 (nh, node, head, nh_hash) {
if ( V_18 -> V_5 == V_49 &&
V_18 -> V_20 == V_47 &&
! ( V_18 -> V_24 & V_25 ) ) {
F_24 ( & V_9 ) ;
return 0 ;
}
}
F_24 ( & V_9 ) ;
return - 1 ;
}
static inline T_2 F_25 ( struct V_1 * V_2 )
{
T_2 V_52 = F_26 ( sizeof( struct V_53 ) )
+ F_27 ( 4 )
+ F_27 ( 4 )
+ F_27 ( 4 )
+ F_27 ( 4 ) ;
V_52 += F_27 ( ( V_45 * F_27 ( 4 ) ) ) ;
if ( V_2 -> V_31 ) {
T_2 V_54 = F_27 ( sizeof( struct V_55 ) ) ;
V_54 += 2 * F_27 ( 4 ) ;
V_52 += F_27 ( V_2 -> V_31 * V_54 ) ;
}
return V_52 ;
}
void F_28 ( int V_56 , T_1 V_57 , struct V_58 * V_59 ,
int V_60 , V_35 V_61 , struct V_62 * V_63 ,
unsigned int V_64 )
{
struct V_65 * V_66 ;
V_35 V_67 = V_63 -> V_68 ? V_63 -> V_68 -> V_69 : 0 ;
int V_70 = - V_71 ;
V_66 = F_29 ( F_25 ( V_59 -> V_72 ) , V_73 ) ;
if ( V_66 == NULL )
goto V_74;
V_70 = F_30 ( V_66 , V_63 -> V_75 , V_67 , V_56 , V_61 ,
V_59 -> V_76 , V_57 , V_60 ,
V_59 -> V_77 , V_59 -> V_72 , V_64 ) ;
if ( V_70 < 0 ) {
F_31 ( V_70 == - V_78 ) ;
F_32 ( V_66 ) ;
goto V_74;
}
F_33 ( V_66 , V_63 -> V_79 , V_63 -> V_75 , V_80 ,
V_63 -> V_68 , V_73 ) ;
return;
V_74:
if ( V_70 < 0 )
F_34 ( V_63 -> V_79 , V_80 , V_70 ) ;
}
struct V_58 * F_35 ( struct V_81 * V_82 , T_3 V_83 , V_35 V_84 )
{
if ( V_82 ) {
struct V_58 * V_59 ;
F_36 (fa, fah, fa_list) {
if ( V_59 -> V_77 > V_83 )
continue;
if ( V_59 -> V_72 -> V_36 >= V_84 ||
V_59 -> V_77 < V_83 )
return V_59 ;
}
}
return NULL ;
}
int F_37 ( struct V_1 * V_2 , int V_85 ,
struct V_1 * * V_86 , int * V_87 , int V_88 )
{
struct V_89 * V_90 ;
int V_91 = V_92 ;
V_90 = F_38 ( & V_93 , & V_2 -> V_16 [ 0 ] . V_20 , V_2 -> V_94 ) ;
if ( V_90 ) {
V_91 = V_90 -> V_95 ;
F_39 ( V_90 ) ;
}
if ( V_91 == V_96 )
return 0 ;
if ( ( V_91 & V_97 ) && V_85 != V_88 )
return 0 ;
if ( ( V_91 & V_97 ) ||
( * V_87 < 0 && V_85 > V_88 ) ) {
* V_86 = V_2 ;
* V_87 = V_85 ;
}
return 1 ;
}
static int F_40 ( struct V_55 * V_98 , int V_99 )
{
int V_100 = 0 ;
while ( F_41 ( V_98 , V_99 ) ) {
V_100 ++ ;
V_98 = F_42 ( V_98 , & V_99 ) ;
}
return V_99 > 0 ? 0 : V_100 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_55 * V_98 ,
int V_99 , struct V_101 * V_102 )
{
F_3 (fi) {
int V_103 ;
if ( ! F_41 ( V_98 , V_99 ) )
return - V_104 ;
V_4 -> V_24 =
( V_102 -> V_105 & ~ 0xFF ) | V_98 -> V_106 ;
V_4 -> V_19 = V_98 -> V_107 ;
V_4 -> V_22 = V_98 -> V_108 + 1 ;
V_103 = F_44 ( V_98 ) ;
if ( V_103 > 0 ) {
struct V_109 * V_110 , * V_111 = F_45 ( V_98 ) ;
V_110 = F_46 ( V_111 , V_103 , V_112 ) ;
V_4 -> V_20 = V_110 ? F_47 ( V_110 ) : 0 ;
#ifdef F_16
V_110 = F_46 ( V_111 , V_103 , V_113 ) ;
V_4 -> V_23 = V_110 ? F_48 ( V_110 ) : 0 ;
#endif
}
V_98 = F_42 ( V_98 , & V_99 ) ;
} F_5 ( V_2 ) ;
return 0 ;
}
int F_49 ( struct V_101 * V_102 , struct V_1 * V_2 )
{
#ifdef F_15
struct V_55 * V_98 ;
int V_99 ;
#endif
if ( V_102 -> V_114 && V_102 -> V_114 != V_2 -> V_36 )
return 1 ;
if ( V_102 -> V_115 || V_102 -> V_116 ) {
if ( ( ! V_102 -> V_115 || V_102 -> V_115 == V_2 -> V_16 -> V_19 ) &&
( ! V_102 -> V_116 || V_102 -> V_116 == V_2 -> V_16 -> V_20 ) )
return 0 ;
return 1 ;
}
#ifdef F_15
if ( V_102 -> V_117 == NULL )
return 0 ;
V_98 = V_102 -> V_117 ;
V_99 = V_102 -> V_118 ;
F_14 (fi) {
int V_103 ;
if ( ! F_41 ( V_98 , V_99 ) )
return - V_104 ;
if ( V_98 -> V_107 && V_98 -> V_107 != V_18 -> V_19 )
return 1 ;
V_103 = F_44 ( V_98 ) ;
if ( V_103 < 0 ) {
struct V_109 * V_110 , * V_111 = F_45 ( V_98 ) ;
V_110 = F_46 ( V_111 , V_103 , V_112 ) ;
if ( V_110 && F_47 ( V_110 ) != V_18 -> V_20 )
return 1 ;
#ifdef F_16
V_110 = F_46 ( V_111 , V_103 , V_113 ) ;
if ( V_110 && F_48 ( V_110 ) != V_18 -> V_23 )
return 1 ;
#endif
}
V_98 = F_42 ( V_98 , & V_99 ) ;
} F_5 ( V_2 ) ;
#endif
return 0 ;
}
static int F_50 ( struct V_101 * V_102 , struct V_1 * V_2 ,
struct V_16 * V_18 )
{
int V_70 ;
struct V_119 * V_119 ;
struct V_48 * V_49 ;
V_119 = V_102 -> V_120 . V_79 ;
if ( V_18 -> V_20 ) {
struct V_121 V_122 ;
if ( V_18 -> V_24 & V_123 ) {
if ( V_102 -> V_124 >= V_125 )
return - V_104 ;
if ( F_51 ( V_119 , V_18 -> V_20 ) != V_126 )
return - V_104 ;
V_49 = F_52 ( V_119 , V_18 -> V_19 ) ;
if ( ! V_49 )
return - V_127 ;
if ( ! ( V_49 -> V_128 & V_129 ) )
return - V_130 ;
V_18 -> V_5 = V_49 ;
F_53 ( V_49 ) ;
V_18 -> V_21 = V_125 ;
return 0 ;
}
F_54 () ;
{
struct V_131 V_132 = {
. V_133 = V_18 -> V_20 ,
. V_134 = V_102 -> V_124 + 1 ,
. V_135 = V_18 -> V_19 ,
} ;
if ( V_132 . V_134 < V_125 )
V_132 . V_134 = V_125 ;
V_70 = F_55 ( V_119 , & V_132 , & V_122 ) ;
if ( V_70 ) {
F_56 () ;
return V_70 ;
}
}
V_70 = - V_104 ;
if ( V_122 . type != V_126 && V_122 . type != V_136 )
goto V_137;
V_18 -> V_21 = V_122 . V_138 ;
V_18 -> V_19 = F_57 ( V_122 ) ;
V_18 -> V_5 = V_49 = F_58 ( V_122 ) ;
if ( ! V_49 )
goto V_137;
F_53 ( V_49 ) ;
V_70 = ( V_49 -> V_128 & V_129 ) ? 0 : - V_130 ;
} else {
struct V_139 * V_140 ;
if ( V_18 -> V_24 & ( V_141 | V_123 ) )
return - V_104 ;
F_54 () ;
V_70 = - V_127 ;
V_140 = F_59 ( V_119 , V_18 -> V_19 ) ;
if ( V_140 == NULL )
goto V_137;
V_70 = - V_130 ;
if ( ! ( V_140 -> V_49 -> V_128 & V_129 ) )
goto V_137;
V_18 -> V_5 = V_140 -> V_49 ;
F_53 ( V_18 -> V_5 ) ;
V_18 -> V_21 = V_142 ;
V_70 = 0 ;
}
V_137:
F_56 () ;
return V_70 ;
}
static inline unsigned int F_60 ( T_1 V_26 )
{
unsigned int V_27 = ( V_30 - 1 ) ;
return ( ( V_34 V_35 ) V_26 ^
( ( V_34 V_35 ) V_26 >> 7 ) ^
( ( V_34 V_35 ) V_26 >> 14 ) ) & V_27 ;
}
static struct V_38 * F_61 ( int V_143 )
{
if ( V_143 <= V_144 )
return F_62 ( V_143 , V_73 ) ;
else
return (struct V_38 * )
F_63 ( V_73 | V_145 ,
F_64 ( V_143 ) ) ;
}
static void F_65 ( struct V_38 * V_42 , int V_143 )
{
if ( ! V_42 )
return;
if ( V_143 <= V_144 )
F_66 ( V_42 ) ;
else
F_67 ( ( unsigned long ) V_42 , F_64 ( V_143 ) ) ;
}
static void F_68 ( struct V_38 * V_146 ,
struct V_38 * V_147 ,
unsigned int V_148 )
{
struct V_38 * V_149 , * V_150 ;
unsigned int V_151 = V_30 ;
unsigned int V_152 , V_143 ;
F_9 ( & V_9 ) ;
V_149 = V_43 ;
V_150 = V_153 ;
V_30 = V_148 ;
for ( V_152 = 0 ; V_152 < V_151 ; V_152 ++ ) {
struct V_38 * V_39 = & V_43 [ V_152 ] ;
struct V_40 * V_41 , * V_90 ;
struct V_1 * V_2 ;
F_69 (fi, node, n, head, fib_hash) {
struct V_38 * V_154 ;
unsigned int V_155 ;
F_10 ( & V_2 -> V_11 ) ;
V_155 = F_18 ( V_2 ) ;
V_154 = & V_146 [ V_155 ] ;
F_70 ( & V_2 -> V_11 , V_154 ) ;
}
}
V_43 = V_146 ;
for ( V_152 = 0 ; V_152 < V_151 ; V_152 ++ ) {
struct V_38 * V_156 = & V_153 [ V_152 ] ;
struct V_40 * V_41 , * V_90 ;
struct V_1 * V_2 ;
F_69 (fi, node, n, lhead, fib_lhash) {
struct V_38 * V_157 ;
unsigned int V_155 ;
F_10 ( & V_2 -> V_13 ) ;
V_155 = F_60 ( V_2 -> V_12 ) ;
V_157 = & V_147 [ V_155 ] ;
F_70 ( & V_2 -> V_13 , V_157 ) ;
}
}
V_153 = V_147 ;
F_12 ( & V_9 ) ;
V_143 = V_151 * sizeof( struct V_38 * ) ;
F_65 ( V_149 , V_143 ) ;
F_65 ( V_150 , V_143 ) ;
}
T_1 F_71 ( struct V_119 * V_119 , struct V_16 * V_18 )
{
V_18 -> V_158 = F_72 ( V_18 -> V_5 ,
V_18 -> V_20 ,
V_18 -> V_159 -> V_33 ) ;
V_18 -> V_160 = F_73 ( & V_119 -> V_161 . V_162 ) ;
return V_18 -> V_158 ;
}
struct V_1 * F_74 ( struct V_101 * V_102 )
{
int V_70 ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_15 ;
int V_100 = 1 ;
struct V_119 * V_119 = V_102 -> V_120 . V_79 ;
if ( V_102 -> V_163 > V_164 )
goto V_165;
if ( V_166 [ V_102 -> V_163 ] . V_138 > V_102 -> V_124 )
goto V_165;
#ifdef F_15
if ( V_102 -> V_117 ) {
V_100 = F_40 ( V_102 -> V_117 , V_102 -> V_118 ) ;
if ( V_100 == 0 )
goto V_165;
}
#endif
V_70 = - V_71 ;
if ( V_6 >= V_30 ) {
unsigned int V_148 = V_30 << 1 ;
struct V_38 * V_146 ;
struct V_38 * V_147 ;
unsigned int V_143 ;
if ( ! V_148 )
V_148 = 1 ;
V_143 = V_148 * sizeof( struct V_38 * ) ;
V_146 = F_61 ( V_143 ) ;
V_147 = F_61 ( V_143 ) ;
if ( ! V_146 || ! V_147 ) {
F_65 ( V_146 , V_143 ) ;
F_65 ( V_147 , V_143 ) ;
} else
F_68 ( V_146 , V_147 , V_148 ) ;
if ( ! V_30 )
goto V_167;
}
V_2 = F_62 ( sizeof( * V_2 ) + V_100 * sizeof( struct V_16 ) , V_73 ) ;
if ( V_2 == NULL )
goto V_167;
if ( V_102 -> V_168 ) {
V_2 -> V_44 = F_62 ( sizeof( V_35 ) * V_45 , V_73 ) ;
if ( ! V_2 -> V_44 )
goto V_167;
} else
V_2 -> V_44 = ( V_35 * ) V_169 ;
V_6 ++ ;
V_2 -> V_7 = F_75 ( V_119 ) ;
V_2 -> V_32 = V_102 -> V_170 ;
V_2 -> V_33 = V_102 -> V_124 ;
V_2 -> V_46 = V_102 -> V_105 ;
V_2 -> V_36 = V_102 -> V_114 ;
V_2 -> V_12 = V_102 -> V_171 ;
V_2 -> V_31 = V_100 ;
F_3 (fi) {
V_4 -> V_159 = V_2 ;
} F_5 (fi)
if ( V_102 -> V_168 ) {
struct V_109 * V_110 ;
int V_99 ;
F_76 (nla, cfg->fc_mx, cfg->fc_mx_len, remaining) {
int type = F_77 ( V_110 ) ;
if ( type ) {
if ( type > V_45 )
goto V_165;
V_2 -> V_44 [ type - 1 ] = F_48 ( V_110 ) ;
}
}
}
if ( V_102 -> V_117 ) {
#ifdef F_15
V_70 = F_43 ( V_2 , V_102 -> V_117 , V_102 -> V_118 , V_102 ) ;
if ( V_70 != 0 )
goto V_167;
if ( V_102 -> V_115 && V_2 -> V_16 -> V_19 != V_102 -> V_115 )
goto V_165;
if ( V_102 -> V_116 && V_2 -> V_16 -> V_20 != V_102 -> V_116 )
goto V_165;
#ifdef F_16
if ( V_102 -> V_172 && V_2 -> V_16 -> V_23 != V_102 -> V_172 )
goto V_165;
#endif
#else
goto V_165;
#endif
} else {
struct V_16 * V_18 = V_2 -> V_16 ;
V_18 -> V_19 = V_102 -> V_115 ;
V_18 -> V_20 = V_102 -> V_116 ;
V_18 -> V_24 = V_102 -> V_105 ;
#ifdef F_16
V_18 -> V_23 = V_102 -> V_172 ;
#endif
#ifdef F_15
V_18 -> V_22 = 1 ;
#endif
}
if ( V_166 [ V_102 -> V_163 ] . error ) {
if ( V_102 -> V_116 || V_102 -> V_115 || V_102 -> V_117 )
goto V_165;
goto V_173;
} else {
switch ( V_102 -> V_163 ) {
case V_126 :
case V_136 :
case V_174 :
case V_175 :
case V_176 :
break;
default:
goto V_165;
}
}
if ( V_102 -> V_124 > V_142 )
goto V_165;
if ( V_102 -> V_124 == V_142 ) {
struct V_16 * V_18 = V_2 -> V_16 ;
if ( V_100 != 1 || V_18 -> V_20 )
goto V_165;
V_18 -> V_21 = V_177 ;
V_18 -> V_5 = F_78 ( V_119 , V_2 -> V_16 -> V_19 ) ;
V_70 = - V_127 ;
if ( V_18 -> V_5 == NULL )
goto V_167;
} else {
F_3 (fi) {
V_70 = F_50 ( V_102 , V_2 , V_4 ) ;
if ( V_70 != 0 )
goto V_167;
} F_5 (fi)
}
if ( V_2 -> V_12 ) {
if ( V_102 -> V_163 != V_136 || ! V_102 -> V_178 ||
V_2 -> V_12 != V_102 -> V_178 )
if ( F_51 ( V_119 , V_2 -> V_12 ) != V_136 )
goto V_165;
}
F_3 (fi) {
F_71 ( V_119 , V_4 ) ;
} F_5 (fi)
V_173:
V_15 = F_19 ( V_2 ) ;
if ( V_15 ) {
V_2 -> V_3 = 1 ;
F_1 ( V_2 ) ;
V_15 -> V_10 ++ ;
return V_15 ;
}
V_2 -> V_10 ++ ;
F_79 ( & V_2 -> V_179 ) ;
F_9 ( & V_9 ) ;
F_70 ( & V_2 -> V_11 ,
& V_43 [ F_18 ( V_2 ) ] ) ;
if ( V_2 -> V_12 ) {
struct V_38 * V_39 ;
V_39 = & V_153 [ F_60 ( V_2 -> V_12 ) ] ;
F_70 ( & V_2 -> V_13 , V_39 ) ;
}
F_3 (fi) {
struct V_38 * V_39 ;
unsigned int V_42 ;
if ( ! V_4 -> V_5 )
continue;
V_42 = F_17 ( V_4 -> V_5 -> V_50 ) ;
V_39 = & V_51 [ V_42 ] ;
F_70 ( & V_4 -> V_14 , V_39 ) ;
} F_5 (fi)
F_12 ( & V_9 ) ;
return V_2 ;
V_165:
V_70 = - V_104 ;
V_167:
if ( V_2 ) {
V_2 -> V_3 = 1 ;
F_1 ( V_2 ) ;
}
return F_80 ( V_70 ) ;
}
int F_30 ( struct V_65 * V_66 , V_35 V_75 , V_35 V_67 , int V_56 ,
V_35 V_61 , T_3 type , T_1 V_180 , int V_60 , T_3 V_83 ,
struct V_1 * V_2 , unsigned int V_128 )
{
struct V_181 * V_68 ;
struct V_53 * V_182 ;
V_68 = F_81 ( V_66 , V_75 , V_67 , V_56 , sizeof( * V_182 ) , V_128 ) ;
if ( V_68 == NULL )
return - V_78 ;
V_182 = F_82 ( V_68 ) ;
V_182 -> V_183 = V_184 ;
V_182 -> V_185 = V_60 ;
V_182 -> V_186 = 0 ;
V_182 -> V_187 = V_83 ;
if ( V_61 < 256 )
V_182 -> V_188 = V_61 ;
else
V_182 -> V_188 = V_189 ;
F_83 ( V_66 , V_190 , V_61 ) ;
V_182 -> V_191 = type ;
V_182 -> V_192 = V_2 -> V_46 ;
V_182 -> V_193 = V_2 -> V_33 ;
V_182 -> V_194 = V_2 -> V_32 ;
if ( V_182 -> V_185 )
F_84 ( V_66 , V_195 , V_180 ) ;
if ( V_2 -> V_36 )
F_83 ( V_66 , V_196 , V_2 -> V_36 ) ;
if ( F_85 ( V_66 , V_2 -> V_44 ) < 0 )
goto V_197;
if ( V_2 -> V_12 )
F_84 ( V_66 , V_198 , V_2 -> V_12 ) ;
if ( V_2 -> V_31 == 1 ) {
if ( V_2 -> V_16 -> V_20 )
F_84 ( V_66 , V_112 , V_2 -> V_16 -> V_20 ) ;
if ( V_2 -> V_16 -> V_19 )
F_83 ( V_66 , V_199 , V_2 -> V_16 -> V_19 ) ;
#ifdef F_16
if ( V_2 -> V_16 [ 0 ] . V_23 )
F_83 ( V_66 , V_113 , V_2 -> V_16 [ 0 ] . V_23 ) ;
#endif
}
#ifdef F_15
if ( V_2 -> V_31 > 1 ) {
struct V_55 * V_98 ;
struct V_109 * V_200 ;
V_200 = F_86 ( V_66 , V_201 ) ;
if ( V_200 == NULL )
goto V_197;
F_14 (fi) {
V_98 = F_87 ( V_66 , sizeof( * V_98 ) ) ;
if ( V_98 == NULL )
goto V_197;
V_98 -> V_106 = V_18 -> V_24 & 0xFF ;
V_98 -> V_108 = V_18 -> V_22 - 1 ;
V_98 -> V_107 = V_18 -> V_19 ;
if ( V_18 -> V_20 )
F_84 ( V_66 , V_112 , V_18 -> V_20 ) ;
#ifdef F_16
if ( V_18 -> V_23 )
F_83 ( V_66 , V_113 , V_18 -> V_23 ) ;
#endif
V_98 -> V_202 = F_88 ( V_66 ) - ( void * ) V_98 ;
} F_5 ( V_2 ) ;
F_89 ( V_66 , V_200 ) ;
}
#endif
return F_90 ( V_66 , V_68 ) ;
V_197:
F_91 ( V_66 , V_68 ) ;
return - V_78 ;
}
int F_92 ( struct V_119 * V_119 , T_1 V_203 )
{
int V_204 = 0 ;
unsigned int V_42 = F_60 ( V_203 ) ;
struct V_38 * V_39 = & V_153 [ V_42 ] ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
if ( V_153 == NULL || V_203 == 0 )
return 0 ;
F_20 (fi, node, head, fib_lhash) {
if ( ! F_21 ( V_2 -> V_7 , V_119 ) )
continue;
if ( V_2 -> V_12 == V_203 ) {
V_2 -> V_46 |= V_25 ;
V_204 ++ ;
}
}
return V_204 ;
}
int F_93 ( struct V_48 * V_49 , int V_205 )
{
int V_204 = 0 ;
int V_138 = V_177 ;
struct V_1 * V_206 = NULL ;
unsigned int V_42 = F_17 ( V_49 -> V_50 ) ;
struct V_38 * V_39 = & V_51 [ V_42 ] ;
struct V_40 * V_41 ;
struct V_16 * V_18 ;
if ( V_205 )
V_138 = - 1 ;
F_20 (nh, node, head, nh_hash) {
struct V_1 * V_2 = V_18 -> V_159 ;
int V_207 ;
F_94 ( ! V_2 -> V_31 ) ;
if ( V_18 -> V_5 != V_49 || V_2 == V_206 )
continue;
V_206 = V_2 ;
V_207 = 0 ;
F_3 (fi) {
if ( V_4 -> V_24 & V_25 )
V_207 ++ ;
else if ( V_4 -> V_5 == V_49 &&
V_4 -> V_21 != V_138 ) {
V_4 -> V_24 |= V_25 ;
#ifdef F_15
F_9 ( & V_208 ) ;
V_2 -> V_209 -= V_4 -> V_210 ;
V_4 -> V_210 = 0 ;
F_12 ( & V_208 ) ;
#endif
V_207 ++ ;
}
#ifdef F_15
if ( V_205 > 1 && V_4 -> V_5 == V_49 ) {
V_207 = V_2 -> V_31 ;
break;
}
#endif
} F_5 (fi)
if ( V_207 == V_2 -> V_31 ) {
V_2 -> V_46 |= V_25 ;
V_204 ++ ;
}
}
return V_204 ;
}
void F_95 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = NULL , * V_86 = NULL ;
struct V_81 * V_211 = V_122 -> V_211 ;
struct V_212 * V_213 = V_122 -> V_214 ;
int V_85 = - 1 , V_87 = - 1 ;
struct V_58 * V_59 ;
F_96 (fa, fa_head, fa_list) {
struct V_1 * V_215 = V_59 -> V_72 ;
if ( V_215 -> V_33 != V_122 -> V_138 ||
V_59 -> V_76 != V_126 )
continue;
if ( V_215 -> V_36 > V_122 -> V_2 -> V_36 )
break;
if ( ! V_215 -> V_16 [ 0 ] . V_20 ||
V_215 -> V_16 [ 0 ] . V_21 != V_125 )
continue;
F_97 ( V_59 ) ;
if ( V_2 == NULL ) {
if ( V_215 != V_122 -> V_2 )
break;
} else if ( ! F_37 ( V_2 , V_85 , & V_86 ,
& V_87 , V_213 -> V_216 ) ) {
F_98 ( V_122 , V_2 ) ;
V_213 -> V_216 = V_85 ;
goto V_137;
}
V_2 = V_215 ;
V_85 ++ ;
}
if ( V_85 <= 0 || V_2 == NULL ) {
V_213 -> V_216 = - 1 ;
goto V_137;
}
if ( ! F_37 ( V_2 , V_85 , & V_86 , & V_87 ,
V_213 -> V_216 ) ) {
F_98 ( V_122 , V_2 ) ;
V_213 -> V_216 = V_85 ;
goto V_137;
}
if ( V_87 >= 0 )
F_98 ( V_122 , V_86 ) ;
V_213 -> V_216 = V_87 ;
V_137:
return;
}
int F_99 ( struct V_48 * V_49 )
{
struct V_1 * V_206 ;
unsigned int V_42 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_16 * V_18 ;
int V_204 ;
if ( ! ( V_49 -> V_128 & V_129 ) )
return 0 ;
V_206 = NULL ;
V_42 = F_17 ( V_49 -> V_50 ) ;
V_39 = & V_51 [ V_42 ] ;
V_204 = 0 ;
F_20 (nh, node, head, nh_hash) {
struct V_1 * V_2 = V_18 -> V_159 ;
int V_217 ;
F_94 ( ! V_2 -> V_31 ) ;
if ( V_18 -> V_5 != V_49 || V_2 == V_206 )
continue;
V_206 = V_2 ;
V_217 = 0 ;
F_3 (fi) {
if ( ! ( V_4 -> V_24 & V_25 ) ) {
V_217 ++ ;
continue;
}
if ( V_4 -> V_5 == NULL ||
! ( V_4 -> V_5 -> V_128 & V_129 ) )
continue;
if ( V_4 -> V_5 != V_49 ||
! F_100 ( V_49 ) )
continue;
V_217 ++ ;
F_9 ( & V_208 ) ;
V_4 -> V_210 = 0 ;
V_4 -> V_24 &= ~ V_25 ;
F_12 ( & V_208 ) ;
} F_5 (fi)
if ( V_217 > 0 ) {
V_2 -> V_46 &= ~ V_25 ;
V_204 ++ ;
}
}
return V_204 ;
}
void F_101 ( struct V_121 * V_122 )
{
struct V_1 * V_2 = V_122 -> V_2 ;
int V_218 ;
F_9 ( & V_208 ) ;
if ( V_2 -> V_209 <= 0 ) {
int V_219 = 0 ;
F_3 (fi) {
if ( ! ( V_4 -> V_24 & V_25 ) ) {
V_219 += V_4 -> V_22 ;
V_4 -> V_210 = V_4 -> V_22 ;
}
} F_5 ( V_2 ) ;
V_2 -> V_209 = V_219 ;
if ( V_219 <= 0 ) {
F_12 ( & V_208 ) ;
V_122 -> V_220 = 0 ;
return;
}
}
V_218 = V_221 % V_2 -> V_209 ;
F_3 (fi) {
if ( ! ( V_4 -> V_24 & V_25 ) &&
V_4 -> V_210 ) {
V_218 -= V_4 -> V_210 ;
if ( V_218 <= 0 ) {
V_4 -> V_210 -- ;
V_2 -> V_209 -- ;
V_122 -> V_220 = V_222 ;
F_12 ( & V_208 ) ;
return;
}
}
} F_5 ( V_2 ) ;
V_122 -> V_220 = 0 ;
F_12 ( & V_208 ) ;
}
