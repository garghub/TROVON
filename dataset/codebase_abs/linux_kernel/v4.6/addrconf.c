static inline T_1 F_1 ( unsigned long V_1 )
{
return ( V_1 - V_2 ) * 100UL / V_3 ;
}
static inline int F_2 ( struct V_4 * V_5 )
{
return 0 ;
}
static inline void F_3 ( struct V_4 * V_5 )
{
}
static inline bool F_4 ( const struct V_6 * V_7 )
{
return ! F_5 ( V_7 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
if ( F_7 ( & V_5 -> V_8 ) )
F_8 ( V_5 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
if ( F_10 ( & V_10 -> V_11 ) )
F_11 ( V_10 ) ;
}
static void F_12 ( struct V_4 * V_5 ,
unsigned long V_12 )
{
if ( ! F_13 ( & V_5 -> V_8 ) )
F_14 ( V_5 ) ;
F_15 ( & V_5 -> V_8 , V_13 + V_12 ) ;
}
static void F_16 ( struct V_9 * V_10 ,
unsigned long V_14 )
{
if ( ! F_17 ( & V_10 -> V_11 ) )
F_18 ( V_10 ) ;
F_19 ( V_15 , & V_10 -> V_11 , V_14 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
int V_16 ;
V_5 -> V_17 . V_18 = F_21 ( struct V_19 ) ;
if ( ! V_5 -> V_17 . V_18 )
goto V_20;
F_22 (i) {
struct V_19 * V_21 ;
V_21 = F_23 ( V_5 -> V_17 . V_18 , V_16 ) ;
F_24 ( & V_21 -> V_22 ) ;
}
V_5 -> V_17 . V_23 = F_25 ( sizeof( struct V_24 ) ,
V_25 ) ;
if ( ! V_5 -> V_17 . V_23 )
goto V_26;
V_5 -> V_17 . V_27 = F_25 ( sizeof( struct V_28 ) ,
V_25 ) ;
if ( ! V_5 -> V_17 . V_27 )
goto V_29;
return 0 ;
V_29:
F_26 ( V_5 -> V_17 . V_23 ) ;
V_26:
F_27 ( V_5 -> V_17 . V_18 ) ;
V_20:
return - V_30 ;
}
static struct V_4 * F_28 ( struct V_6 * V_7 )
{
struct V_4 * V_31 ;
int V_32 = - V_30 ;
F_29 () ;
if ( V_7 -> V_33 < V_34 )
return F_30 ( - V_35 ) ;
V_31 = F_25 ( sizeof( struct V_4 ) , V_25 ) ;
if ( ! V_31 )
return F_30 ( V_32 ) ;
F_31 ( & V_31 -> V_36 ) ;
V_31 -> V_7 = V_7 ;
F_32 ( & V_31 -> V_37 ) ;
F_33 ( & V_31 -> V_8 , V_38 ,
( unsigned long ) V_31 ) ;
memcpy ( & V_31 -> V_39 , F_34 ( V_7 ) -> V_18 . V_40 , sizeof( V_31 -> V_39 ) ) ;
if ( V_31 -> V_39 . V_41 . V_42 )
V_31 -> V_43 = V_44 ;
else
V_31 -> V_43 = V_45 ;
V_31 -> V_39 . V_46 = V_7 -> V_33 ;
V_31 -> V_39 . V_47 = NULL ;
V_31 -> V_48 = F_35 ( V_7 , & V_49 ) ;
if ( ! V_31 -> V_48 ) {
F_26 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
if ( V_31 -> V_39 . V_50 )
F_36 ( V_7 ) ;
F_37 ( V_7 ) ;
if ( F_20 ( V_31 ) < 0 ) {
F_38 ( V_51
L_1 ,
V_52 , V_7 -> V_53 ) ;
F_39 ( & V_49 , V_31 -> V_48 ) ;
F_40 ( V_7 ) ;
F_26 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
if ( F_41 ( V_31 ) < 0 ) {
F_38 ( V_51
L_2 ,
V_52 , V_7 -> V_53 ) ;
goto V_54;
}
F_14 ( V_31 ) ;
if ( V_7 -> V_55 & ( V_56 | V_57 ) )
V_31 -> V_39 . V_58 = - 1 ;
#if F_42 ( V_59 )
if ( V_7 -> type == V_60 && ( V_7 -> V_61 & V_62 ) ) {
F_43 ( L_3 , V_7 -> V_53 ) ;
V_31 -> V_39 . V_63 = 0 ;
}
#endif
F_32 ( & V_31 -> V_64 ) ;
F_33 ( & V_31 -> V_65 , V_66 , ( unsigned long ) V_31 ) ;
if ( ( V_7 -> V_55 & V_57 ) ||
V_7 -> type == V_67 ||
V_7 -> type == V_68 ||
V_7 -> type == V_60 ||
V_7 -> type == V_69 ) {
V_31 -> V_39 . V_70 = - 1 ;
} else {
F_14 ( V_31 ) ;
V_66 ( ( unsigned long ) V_31 ) ;
}
V_31 -> V_71 = V_72 ;
if ( F_44 ( V_7 ) && F_4 ( V_7 ) )
V_31 -> V_73 |= V_74 ;
F_45 ( V_31 ) ;
V_31 -> V_75 = V_13 ;
V_32 = F_2 ( V_31 ) ;
if ( V_32 ) {
F_46 ( V_31 ) ;
F_7 ( & V_31 -> V_65 ) ;
F_47 ( V_31 ) ;
goto V_54;
}
F_48 ( V_7 -> V_76 , V_31 ) ;
F_49 ( V_7 , & V_77 ) ;
F_49 ( V_7 , & V_78 ) ;
if ( V_31 -> V_39 . V_50 && ( V_7 -> V_55 & V_79 ) )
F_49 ( V_7 , & V_80 ) ;
return V_31 ;
V_54:
F_39 ( & V_49 , V_31 -> V_48 ) ;
V_31 -> V_81 = 1 ;
F_50 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
static struct V_4 * F_51 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return NULL ;
}
if ( V_7 -> V_55 & V_82 )
F_54 ( V_5 ) ;
return V_5 ;
}
static int F_55 ( int type )
{
int V_83 = F_56 ( sizeof( struct V_84 ) )
+ F_57 ( 4 ) ;
bool V_85 = false ;
if ( type == V_86 )
V_85 = true ;
if ( V_85 || type == V_87 )
V_83 += F_57 ( 4 ) ;
#ifdef F_58
if ( V_85 || type == V_88 )
V_83 += F_57 ( 4 ) ;
#endif
if ( V_85 || type == V_89 )
V_83 += F_57 ( 4 ) ;
if ( V_85 || type == V_90 )
V_83 += F_57 ( 4 ) ;
return V_83 ;
}
static int F_59 ( struct V_91 * V_92 , int V_93 ,
struct V_94 * V_95 , T_1 V_96 ,
T_1 V_97 , int V_98 , unsigned int V_55 ,
int type )
{
struct V_99 * V_100 ;
struct V_84 * V_101 ;
bool V_85 = false ;
V_100 = F_60 ( V_92 , V_96 , V_97 , V_98 , sizeof( struct V_84 ) ,
V_55 ) ;
if ( ! V_100 )
return - V_102 ;
if ( type == V_86 )
V_85 = true ;
V_101 = F_61 ( V_100 ) ;
V_101 -> V_103 = V_104 ;
if ( F_62 ( V_92 , V_105 , V_93 ) < 0 )
goto V_106;
if ( ( V_85 || type == V_87 ) &&
F_62 ( V_92 , V_87 , V_95 -> V_50 ) < 0 )
goto V_106;
#ifdef F_58
if ( ( V_85 || type == V_88 ) &&
F_62 ( V_92 , V_88 ,
V_95 -> V_107 ) < 0 )
goto V_106;
#endif
if ( ( V_85 || type == V_89 ) &&
F_62 ( V_92 , V_89 , V_95 -> V_108 ) < 0 )
goto V_106;
if ( ( V_85 || type == V_90 ) &&
F_62 ( V_92 , V_90 ,
V_95 -> V_109 ) < 0 )
goto V_106;
F_63 ( V_92 , V_100 ) ;
return 0 ;
V_106:
F_64 ( V_92 , V_100 ) ;
return - V_102 ;
}
void F_65 ( struct V_110 * V_110 , int type , int V_93 ,
struct V_94 * V_95 )
{
struct V_91 * V_92 ;
int V_32 = - V_111 ;
V_92 = F_66 ( F_55 ( type ) , V_112 ) ;
if ( ! V_92 )
goto V_113;
V_32 = F_59 ( V_92 , V_93 , V_95 , 0 , 0 ,
V_114 , 0 , type ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_102 ) ;
F_68 ( V_92 ) ;
goto V_113;
}
F_69 ( V_92 , V_110 , 0 , V_115 , NULL , V_112 ) ;
return;
V_113:
F_70 ( V_110 , V_115 , V_32 ) ;
}
static int F_71 ( struct V_91 * V_116 ,
struct V_99 * V_100 )
{
struct V_110 * V_110 = F_72 ( V_116 -> V_117 ) ;
struct V_118 * V_119 [ V_120 + 1 ] ;
struct V_84 * V_101 ;
struct V_91 * V_92 ;
struct V_94 * V_95 ;
struct V_4 * V_121 ;
struct V_6 * V_7 ;
int V_93 ;
int V_32 ;
V_32 = F_73 ( V_100 , sizeof( * V_101 ) , V_119 , V_120 ,
V_122 ) ;
if ( V_32 < 0 )
goto V_113;
V_32 = - V_35 ;
if ( ! V_119 [ V_105 ] )
goto V_113;
V_93 = F_74 ( V_119 [ V_105 ] ) ;
switch ( V_93 ) {
case V_123 :
V_95 = V_110 -> V_18 . V_124 ;
break;
case V_125 :
V_95 = V_110 -> V_18 . V_40 ;
break;
default:
V_7 = F_75 ( V_110 , V_93 ) ;
if ( ! V_7 )
goto V_113;
V_121 = F_52 ( V_7 ) ;
if ( ! V_121 )
goto V_113;
V_95 = & V_121 -> V_39 ;
break;
}
V_32 = - V_111 ;
V_92 = F_66 ( F_55 ( V_86 ) , V_112 ) ;
if ( ! V_92 )
goto V_113;
V_32 = F_59 ( V_92 , V_93 , V_95 ,
F_76 ( V_116 ) . V_96 ,
V_100 -> V_126 , V_114 , 0 ,
V_86 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_102 ) ;
F_68 ( V_92 ) ;
goto V_113;
}
V_32 = F_77 ( V_92 , V_110 , F_76 ( V_116 ) . V_96 ) ;
V_113:
return V_32 ;
}
static int F_78 ( struct V_91 * V_92 ,
struct V_127 * V_128 )
{
struct V_110 * V_110 = F_72 ( V_92 -> V_117 ) ;
int V_129 , V_130 ;
int V_131 , V_132 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_133 * V_134 ;
V_130 = V_128 -> args [ 0 ] ;
V_132 = V_131 = V_128 -> args [ 1 ] ;
for ( V_129 = V_130 ; V_129 < V_135 ; V_129 ++ , V_132 = 0 ) {
V_131 = 0 ;
V_134 = & V_110 -> V_136 [ V_129 ] ;
F_79 () ;
V_128 -> V_97 = F_80 ( & V_110 -> V_18 . V_137 ) ^
V_110 -> V_138 ;
F_81 (dev, head, index_hlist) {
if ( V_131 < V_132 )
goto V_139;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_139;
if ( F_59 ( V_92 , V_7 -> V_93 ,
& V_5 -> V_39 ,
F_76 ( V_128 -> V_92 ) . V_96 ,
V_128 -> V_100 -> V_126 ,
V_114 ,
V_140 ,
V_86 ) < 0 ) {
F_82 () ;
goto V_141;
}
F_83 ( V_128 , F_84 ( V_92 ) ) ;
V_139:
V_131 ++ ;
}
F_82 () ;
}
if ( V_129 == V_135 ) {
if ( F_59 ( V_92 , V_123 ,
V_110 -> V_18 . V_124 ,
F_76 ( V_128 -> V_92 ) . V_96 ,
V_128 -> V_100 -> V_126 ,
V_114 , V_140 ,
V_86 ) < 0 )
goto V_141;
else
V_129 ++ ;
}
if ( V_129 == V_135 + 1 ) {
if ( F_59 ( V_92 , V_125 ,
V_110 -> V_18 . V_40 ,
F_76 ( V_128 -> V_92 ) . V_96 ,
V_128 -> V_100 -> V_126 ,
V_114 , V_140 ,
V_86 ) < 0 )
goto V_141;
else
V_129 ++ ;
}
V_141:
V_128 -> args [ 0 ] = V_129 ;
V_128 -> args [ 1 ] = V_131 ;
return V_92 -> V_142 ;
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_143 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_39 . V_50 )
F_36 ( V_7 ) ;
if ( V_7 -> V_55 & V_79 ) {
if ( V_5 -> V_39 . V_50 ) {
F_49 ( V_7 , & V_80 ) ;
F_49 ( V_7 , & V_144 ) ;
F_49 ( V_7 , & V_145 ) ;
} else {
F_86 ( V_7 , & V_80 ) ;
F_86 ( V_7 , & V_144 ) ;
F_86 ( V_7 , & V_145 ) ;
}
}
F_87 (ifa, &idev->addr_list, if_list) {
if ( V_143 -> V_55 & V_146 )
continue;
if ( V_5 -> V_39 . V_50 )
F_88 ( V_143 ) ;
else
F_89 ( V_143 ) ;
}
F_65 ( F_34 ( V_7 ) , V_87 ,
V_7 -> V_93 , & V_5 -> V_39 ) ;
}
static void F_90 ( struct V_110 * V_110 , T_2 V_147 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_91 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_148 = ( ! V_5 -> V_39 . V_50 ) ^ ( ! V_147 ) ;
V_5 -> V_39 . V_50 = V_147 ;
if ( V_148 )
F_85 ( V_5 ) ;
}
}
}
static int F_92 ( struct V_149 * V_150 , int * V_151 , int V_147 )
{
struct V_110 * V_110 ;
int V_152 ;
if ( ! F_93 () )
return F_94 () ;
V_110 = (struct V_110 * ) V_150 -> V_153 ;
V_152 = * V_151 ;
* V_151 = V_147 ;
if ( V_151 == & V_110 -> V_18 . V_40 -> V_50 ) {
if ( ( ! V_147 ) ^ ( ! V_152 ) )
F_65 ( V_110 , V_87 ,
V_125 ,
V_110 -> V_18 . V_40 ) ;
F_95 () ;
return 0 ;
}
if ( V_151 == & V_110 -> V_18 . V_124 -> V_50 ) {
V_110 -> V_18 . V_40 -> V_50 = V_147 ;
F_90 ( V_110 , V_147 ) ;
if ( ( ! V_147 ) ^ ( ! V_152 ) )
F_65 ( V_110 , V_87 ,
V_123 ,
V_110 -> V_18 . V_124 ) ;
} else if ( ( ! V_147 ) ^ ( ! V_152 ) )
F_85 ( (struct V_4 * ) V_150 -> V_154 ) ;
F_95 () ;
if ( V_147 )
F_96 ( V_110 ) ;
return 1 ;
}
static void F_97 ( struct V_110 * V_110 , T_2 V_147 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_91 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_148 = ( ! V_5 -> V_39 . V_109 ) ^ ( ! V_147 ) ;
V_5 -> V_39 . V_109 = V_147 ;
if ( V_148 )
F_65 ( F_34 ( V_7 ) ,
V_90 ,
V_7 -> V_93 ,
& V_5 -> V_39 ) ;
}
}
}
static int F_98 ( struct V_149 * V_150 , int * V_151 , int V_147 )
{
struct V_110 * V_110 ;
int V_152 ;
if ( ! F_93 () )
return F_94 () ;
V_110 = (struct V_110 * ) V_150 -> V_153 ;
V_152 = * V_151 ;
* V_151 = V_147 ;
if ( V_151 == & V_110 -> V_18 . V_40 -> V_109 ) {
if ( ( ! V_147 ) ^ ( ! V_152 ) )
F_65 ( V_110 ,
V_90 ,
V_125 ,
V_110 -> V_18 . V_40 ) ;
F_95 () ;
return 0 ;
}
if ( V_151 == & V_110 -> V_18 . V_124 -> V_109 ) {
V_110 -> V_18 . V_40 -> V_109 = V_147 ;
F_97 ( V_110 , V_147 ) ;
if ( ( ! V_147 ) ^ ( ! V_152 ) )
F_65 ( V_110 ,
V_90 ,
V_123 ,
V_110 -> V_18 . V_124 ) ;
}
F_95 () ;
return 1 ;
}
void F_99 ( struct V_9 * V_10 )
{
F_67 ( ! F_100 ( & V_10 -> V_155 ) ) ;
#ifdef F_101
F_102 ( L_4 , V_52 ) ;
#endif
F_103 ( V_10 -> V_5 ) ;
if ( F_10 ( & V_10 -> V_11 ) )
F_104 ( L_5 ,
V_10 ) ;
if ( V_10 -> V_156 != V_157 ) {
F_105 ( L_6 , V_10 ) ;
return;
}
F_106 ( V_10 -> V_158 ) ;
F_107 ( V_10 , V_159 ) ;
}
static void
F_108 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_160 * V_151 ;
int V_161 = F_109 ( & V_10 -> V_162 ) ;
F_110 (p, &idev->addr_list) {
struct V_9 * V_143
= F_111 ( V_151 , struct V_9 , V_163 ) ;
if ( V_161 >= F_109 ( & V_143 -> V_162 ) )
break;
}
F_112 ( & V_10 -> V_163 , V_151 ) ;
}
static T_1 F_113 ( const struct V_164 * V_162 )
{
return F_114 ( F_115 ( V_162 ) , V_165 ) ;
}
static struct V_9 *
F_116 ( struct V_4 * V_5 , const struct V_164 * V_162 ,
const struct V_164 * V_166 , int V_167 ,
int V_168 , T_1 V_55 , T_1 V_169 , T_1 V_170 )
{
struct V_9 * V_143 = NULL ;
struct V_171 * V_158 ;
unsigned int V_172 ;
int V_32 = 0 ;
int V_173 = F_117 ( V_162 ) ;
if ( V_173 == V_174 ||
V_173 & V_175 ||
( ! ( V_5 -> V_7 -> V_55 & V_57 ) &&
V_173 & V_176 ) )
return F_30 ( - V_177 ) ;
F_118 () ;
if ( V_5 -> V_81 ) {
V_32 = - V_178 ;
goto V_179;
}
if ( V_5 -> V_39 . V_180 ) {
V_32 = - V_181 ;
goto V_179;
}
F_119 ( & V_182 ) ;
if ( F_120 ( F_34 ( V_5 -> V_7 ) , V_162 , V_5 -> V_7 ) ) {
F_38 ( L_7 ) ;
V_32 = - V_183 ;
goto V_184;
}
V_143 = F_25 ( sizeof( struct V_9 ) , V_112 ) ;
if ( ! V_143 ) {
F_38 ( L_8 ) ;
V_32 = - V_111 ;
goto V_184;
}
V_158 = F_121 ( V_5 , V_162 , false ) ;
if ( F_53 ( V_158 ) ) {
V_32 = F_122 ( V_158 ) ;
goto V_184;
}
F_123 ( V_5 -> V_48 ) ;
V_143 -> V_162 = * V_162 ;
if ( V_166 )
V_143 -> V_166 = * V_166 ;
F_124 ( & V_143 -> V_36 ) ;
F_125 ( & V_143 -> V_11 , V_185 ) ;
F_126 ( & V_143 -> V_155 ) ;
V_143 -> V_168 = V_168 ;
V_143 -> V_186 = V_167 ;
V_143 -> V_55 = V_55 | V_146 ;
V_143 -> V_169 = V_169 ;
V_143 -> V_170 = V_170 ;
V_143 -> V_1 = V_143 -> V_75 = V_13 ;
V_143 -> V_187 = false ;
V_143 -> V_158 = V_158 ;
V_143 -> V_5 = V_5 ;
F_14 ( V_5 ) ;
F_18 ( V_143 ) ;
V_172 = F_113 ( V_162 ) ;
F_127 ( & V_143 -> V_155 , & V_188 [ V_172 ] ) ;
F_128 ( & V_182 ) ;
F_129 ( & V_5 -> V_36 ) ;
F_108 ( V_5 , V_143 ) ;
if ( V_143 -> V_55 & V_189 ) {
F_130 ( & V_143 -> V_190 , & V_5 -> V_64 ) ;
F_18 ( V_143 ) ;
}
F_18 ( V_143 ) ;
F_131 ( & V_5 -> V_36 ) ;
V_179:
F_132 () ;
if ( F_133 ( V_32 == 0 ) )
F_134 ( V_191 , V_143 ) ;
else {
F_26 ( V_143 ) ;
V_143 = F_30 ( V_32 ) ;
}
return V_143 ;
V_184:
F_128 ( & V_182 ) ;
goto V_179;
}
static enum V_192
F_135 ( struct V_9 * V_10 , unsigned long * V_193 )
{
struct V_9 * V_143 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_194 ;
enum V_192 V_195 = V_196 ;
* V_193 = V_13 ;
F_87 (ifa, &idev->addr_list, if_list) {
if ( V_143 == V_10 )
continue;
if ( ! F_136 ( & V_143 -> V_162 , & V_10 -> V_162 ,
V_10 -> V_186 ) )
continue;
if ( V_143 -> V_55 & ( V_197 | V_198 ) )
return V_199 ;
V_195 = V_200 ;
F_119 ( & V_143 -> V_36 ) ;
V_194 = F_137 ( V_143 -> V_169 , V_3 ) ;
if ( F_138 ( * V_193 , V_143 -> V_75 + V_194 * V_3 ) )
* V_193 = V_143 -> V_75 + V_194 * V_3 ;
F_128 ( & V_143 -> V_36 ) ;
}
return V_195 ;
}
static void
F_139 ( struct V_9 * V_10 , unsigned long V_193 , bool V_201 )
{
struct V_171 * V_158 ;
V_158 = F_140 ( & V_10 -> V_162 ,
V_10 -> V_186 ,
V_10 -> V_5 -> V_7 ,
0 , V_202 | V_203 ) ;
if ( V_158 ) {
if ( V_201 )
F_141 ( V_158 ) ;
else {
if ( ! ( V_158 -> V_204 & V_205 ) )
F_142 ( V_158 , V_193 ) ;
F_106 ( V_158 ) ;
}
}
}
static void F_143 ( struct V_9 * V_10 )
{
int V_156 ;
enum V_192 V_195 = V_199 ;
unsigned long V_193 ;
F_29 () ;
F_144 ( & V_10 -> V_36 ) ;
V_156 = V_10 -> V_156 ;
V_10 -> V_156 = V_157 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_156 == V_157 )
goto V_184;
F_144 ( & V_182 ) ;
F_146 ( & V_10 -> V_155 ) ;
F_145 ( & V_182 ) ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_10 -> V_55 & V_189 ) {
F_148 ( & V_10 -> V_190 ) ;
if ( V_10 -> V_206 ) {
F_149 ( V_10 -> V_206 ) ;
V_10 -> V_206 = NULL ;
}
F_11 ( V_10 ) ;
}
if ( V_10 -> V_55 & V_197 && ! ( V_10 -> V_55 & V_198 ) )
V_195 = F_135 ( V_10 , & V_193 ) ;
F_150 ( & V_10 -> V_163 ) ;
F_11 ( V_10 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
F_9 ( V_10 ) ;
F_152 ( V_207 , V_10 ) ;
F_134 ( V_208 , V_10 ) ;
if ( V_195 != V_199 ) {
F_139 ( V_10 , V_193 ,
V_195 == V_196 ) ;
}
F_153 ( V_10 ) ;
V_184:
F_149 ( V_10 ) ;
}
static int F_154 ( struct V_9 * V_10 , struct V_9 * V_209 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_164 V_162 , * V_210 ;
unsigned long V_211 , V_212 , V_213 , V_214 ;
unsigned long V_215 ;
int V_216 ;
int V_217 = 0 ;
T_1 V_218 ;
unsigned long V_219 = V_13 ;
F_147 ( & V_5 -> V_36 ) ;
if ( V_209 ) {
F_144 ( & V_209 -> V_36 ) ;
memcpy ( & V_162 . V_220 [ 8 ] , & V_209 -> V_162 . V_220 [ 8 ] , 8 ) ;
F_145 ( & V_209 -> V_36 ) ;
V_210 = & V_162 ;
} else {
V_210 = NULL ;
}
V_221:
F_14 ( V_5 ) ;
if ( V_5 -> V_39 . V_70 <= 0 ) {
F_151 ( & V_5 -> V_36 ) ;
F_43 ( L_9 , V_52 ) ;
F_103 ( V_5 ) ;
V_217 = - 1 ;
goto V_184;
}
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_222 ++ >= V_5 -> V_39 . V_223 ) {
V_5 -> V_39 . V_70 = - 1 ;
F_145 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_105 ( L_10 ,
V_52 ) ;
F_103 ( V_5 ) ;
V_217 = - 1 ;
goto V_184;
}
F_18 ( V_10 ) ;
memcpy ( V_162 . V_220 , V_10 -> V_162 . V_220 , 8 ) ;
F_155 ( V_5 , V_210 ) ;
memcpy ( & V_162 . V_220 [ 8 ] , V_5 -> V_224 , 8 ) ;
V_214 = ( V_219 - V_10 -> V_75 ) / V_3 ;
V_212 = F_156 ( V_225 ,
V_10 -> V_169 ,
V_5 -> V_39 . V_226 + V_214 ) ;
V_211 = F_156 ( V_225 ,
V_10 -> V_170 ,
V_5 -> V_39 . V_227 + V_214 -
V_5 -> V_39 . V_228 ) ;
V_216 = V_10 -> V_186 ;
V_213 = V_10 -> V_75 ;
F_145 ( & V_10 -> V_36 ) ;
V_215 = V_5 -> V_39 . V_223 *
V_5 -> V_39 . V_229 *
F_157 ( V_5 -> V_48 , V_230 ) / V_3 ;
F_151 ( & V_5 -> V_36 ) ;
V_214 = ( V_219 - V_213 + V_231 ) / V_3 ;
if ( V_211 <= V_215 + V_214 ) {
F_149 ( V_10 ) ;
F_103 ( V_5 ) ;
V_217 = - 1 ;
goto V_184;
}
V_218 = V_189 ;
if ( V_10 -> V_55 & V_232 )
V_218 |= V_232 ;
V_209 = F_116 ( V_5 , & V_162 , NULL , V_216 ,
F_158 ( & V_162 ) , V_218 ,
V_212 , V_211 ) ;
if ( F_53 ( V_209 ) ) {
F_149 ( V_10 ) ;
F_103 ( V_5 ) ;
F_43 ( L_11 , V_52 ) ;
V_210 = & V_162 ;
F_147 ( & V_5 -> V_36 ) ;
goto V_221;
}
F_144 ( & V_209 -> V_36 ) ;
V_209 -> V_206 = V_10 ;
V_209 -> V_1 = V_219 ;
V_209 -> V_75 = V_213 ;
F_145 ( & V_209 -> V_36 ) ;
F_159 ( V_209 ) ;
F_149 ( V_209 ) ;
F_103 ( V_5 ) ;
V_184:
return V_217 ;
}
static inline int F_160 ( int type )
{
if ( type & ( V_233 | V_234 | V_176 ) )
return 1 ;
return 0 ;
}
static inline bool F_161 ( struct V_4 * V_5 )
{
#ifdef F_162
return V_5 && V_5 -> V_39 . V_235 && V_5 -> V_39 . V_236 ;
#else
return false ;
#endif
}
static int F_163 ( struct V_110 * V_110 ,
struct V_237 * V_238 ,
struct V_239 * V_240 ,
int V_16 )
{
int V_217 ;
if ( V_16 <= V_238 -> V_241 ) {
switch ( V_16 ) {
case V_242 :
V_217 = V_238 -> V_243 ;
break;
case V_244 :
V_217 = V_238 -> V_245 ;
break;
default:
V_217 = ! ! F_164 ( V_16 , V_238 -> V_246 ) ;
}
goto V_184;
}
switch ( V_16 ) {
case V_247 :
V_217 = ! ! V_238 -> V_143 ;
break;
case V_248 :
V_217 = F_165 ( & V_238 -> V_143 -> V_162 , V_240 -> V_162 ) ;
break;
case V_242 :
V_217 = F_166 ( V_238 -> V_173 ) ;
if ( V_217 >= V_240 -> V_168 )
V_217 = - V_217 ;
else
V_217 -= 128 ;
V_238 -> V_243 = V_217 ;
break;
case V_249 :
{
T_3 V_250 = V_251 ;
if ( ! F_161 ( V_238 -> V_143 -> V_5 ) )
V_250 |= V_232 ;
V_217 = F_160 ( V_238 -> V_173 ) ||
! ( V_238 -> V_143 -> V_55 & V_250 ) ;
break;
}
#ifdef F_167
case V_252 :
{
int V_253 = ! ( V_240 -> V_254 & V_255 ) ;
V_217 = ! ( V_238 -> V_143 -> V_55 & V_256 ) ^ V_253 ;
break;
}
#endif
case V_257 :
V_217 = ( ! V_240 -> V_93 ||
V_240 -> V_93 == V_238 -> V_143 -> V_5 -> V_7 -> V_93 ) ;
break;
case V_258 :
V_217 = F_168 ( V_110 ,
& V_238 -> V_143 -> V_162 , V_238 -> V_173 ,
V_238 -> V_143 -> V_5 -> V_7 -> V_93 ) == V_240 -> V_259 ;
break;
case V_260 :
{
int V_261 = V_240 -> V_254 & ( V_262 | V_263 ) ?
! ! ( V_240 -> V_254 & V_263 ) :
V_238 -> V_143 -> V_5 -> V_39 . V_70 >= 2 ;
V_217 = ( ! ( V_238 -> V_143 -> V_55 & V_189 ) ) ^ V_261 ;
break;
}
case V_264 :
V_217 = ! ( F_169 ( & V_238 -> V_143 -> V_162 ) ^
F_169 ( V_240 -> V_162 ) ) ;
break;
case V_244 :
V_217 = F_170 ( & V_238 -> V_143 -> V_162 , V_240 -> V_162 ) ;
if ( V_217 > V_238 -> V_143 -> V_186 )
V_217 = V_238 -> V_143 -> V_186 ;
V_238 -> V_245 = V_217 ;
break;
#ifdef F_162
case V_265 :
V_217 = ! ( V_238 -> V_143 -> V_55 & V_232 ) ;
break;
#endif
default:
V_217 = 0 ;
}
if ( V_217 )
F_171 ( V_16 , V_238 -> V_246 ) ;
V_238 -> V_241 = V_16 ;
V_184:
return V_217 ;
}
static int F_172 ( struct V_110 * V_110 ,
struct V_239 * V_240 ,
struct V_4 * V_5 ,
struct V_237 * V_266 ,
int V_267 )
{
struct V_237 * V_238 = & V_266 [ 1 - V_267 ] , * V_268 = & V_266 [ V_267 ] ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_238 -> V_143 -> V_55 & V_146 ) &&
( ! ( V_238 -> V_143 -> V_55 & V_232 ) ) )
continue;
V_238 -> V_173 = F_174 ( & V_238 -> V_143 -> V_162 ) ;
if ( F_175 ( V_238 -> V_173 == V_174 ||
V_238 -> V_173 & V_175 ) ) {
F_176 ( L_12 ,
V_5 -> V_7 -> V_53 ) ;
continue;
}
V_238 -> V_241 = - 1 ;
F_177 ( V_238 -> V_246 , V_269 ) ;
for ( V_16 = 0 ; V_16 < V_269 ; V_16 ++ ) {
int V_270 , V_271 ;
V_270 = F_163 ( V_110 , V_268 , V_240 , V_16 ) ;
V_271 = F_163 ( V_110 , V_238 , V_240 , V_16 ) ;
if ( V_270 > V_271 ) {
if ( V_16 == V_242 &&
V_238 -> V_243 > 0 ) {
goto V_184;
}
break;
} else if ( V_270 < V_271 ) {
if ( V_268 -> V_143 )
F_149 ( V_268 -> V_143 ) ;
F_18 ( V_238 -> V_143 ) ;
F_178 ( V_268 , V_238 ) ;
V_267 = 1 - V_267 ;
V_238 -> V_143 = V_268 -> V_143 ;
break;
}
}
}
V_184:
F_179 ( & V_5 -> V_36 ) ;
return V_267 ;
}
int F_180 ( struct V_110 * V_110 , const struct V_6 * V_272 ,
const struct V_164 * V_273 , unsigned int V_254 ,
struct V_164 * V_274 )
{
struct V_237 V_266 [ 2 ] , * V_268 ;
struct V_239 V_240 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_275 ;
bool V_276 = false ;
int V_267 = 0 ;
V_275 = F_174 ( V_273 ) ;
V_240 . V_162 = V_273 ;
V_240 . V_93 = V_272 ? V_272 -> V_93 : 0 ;
V_240 . V_168 = F_166 ( V_275 ) ;
V_240 . V_259 = F_168 ( V_110 , V_273 , V_275 , V_240 . V_93 ) ;
V_240 . V_254 = V_254 ;
V_266 [ V_267 ] . V_241 = - 1 ;
V_266 [ V_267 ] . V_143 = NULL ;
F_79 () ;
if ( V_272 ) {
V_5 = F_52 ( V_272 ) ;
if ( ( V_275 & V_175 ) ||
V_240 . V_168 <= V_277 ||
( V_5 && V_5 -> V_39 . V_278 ) ) {
V_276 = true ;
}
}
if ( V_276 ) {
if ( V_5 )
V_267 = F_172 ( V_110 , & V_240 , V_5 , V_266 , V_267 ) ;
} else {
F_181 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
continue;
V_267 = F_172 ( V_110 , & V_240 , V_5 , V_266 , V_267 ) ;
}
}
F_82 () ;
V_268 = & V_266 [ V_267 ] ;
if ( ! V_268 -> V_143 )
return - V_177 ;
* V_274 = V_268 -> V_143 -> V_162 ;
F_149 ( V_268 -> V_143 ) ;
return 0 ;
}
int F_182 ( struct V_4 * V_5 , struct V_164 * V_162 ,
T_1 V_279 )
{
struct V_9 * V_10 ;
int V_32 = - V_177 ;
F_183 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_168 > V_280 )
break;
if ( V_10 -> V_168 == V_280 &&
! ( V_10 -> V_55 & V_279 ) ) {
* V_162 = V_10 -> V_162 ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
int F_184 ( struct V_6 * V_7 , struct V_164 * V_162 ,
T_1 V_279 )
{
struct V_4 * V_5 ;
int V_32 = - V_177 ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
V_32 = F_182 ( V_5 , V_162 , V_279 ) ;
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_32 ;
}
static int F_185 ( struct V_4 * V_5 )
{
int V_281 = 0 ;
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list)
V_281 ++ ;
F_179 ( & V_5 -> V_36 ) ;
return V_281 ;
}
int F_186 ( struct V_110 * V_110 , const struct V_164 * V_162 ,
const struct V_6 * V_7 , int V_282 )
{
return F_187 ( V_110 , V_162 , V_7 , V_282 , V_146 ) ;
}
int F_187 ( struct V_110 * V_110 , const struct V_164 * V_162 ,
const struct V_6 * V_7 , int V_282 ,
T_1 V_279 )
{
struct V_9 * V_10 ;
unsigned int V_172 = F_113 ( V_162 ) ;
T_1 V_283 ;
F_118 () ;
F_81 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_110 ) )
continue;
V_283 = ( V_10 -> V_55 & V_232 )
? ( V_10 -> V_55 & ~ V_146 )
: V_10 -> V_55 ;
if ( F_165 ( & V_10 -> V_162 , V_162 ) &&
! ( V_283 & V_279 ) &&
( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_168 & ( V_280 | V_284 ) || V_282 ) ) ) {
F_132 () ;
return 1 ;
}
}
F_132 () ;
return 0 ;
}
static bool F_120 ( struct V_110 * V_110 , const struct V_164 * V_162 ,
struct V_6 * V_7 )
{
unsigned int V_172 = F_113 ( V_162 ) ;
struct V_9 * V_10 ;
F_189 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_110 ) )
continue;
if ( F_165 ( & V_10 -> V_162 , V_162 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_190 ( const struct V_164 * V_162 ,
const unsigned int V_186 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_143 ;
bool V_217 = false ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifa, &idev->addr_list, if_list) {
V_217 = F_136 ( V_162 , & V_143 -> V_162 , V_186 ) ;
if ( V_217 )
break;
}
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_217 ;
}
int F_191 ( const struct V_164 * V_162 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_143 ;
int V_285 ;
V_285 = 0 ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifa, &idev->addr_list, if_list) {
V_285 = F_136 ( V_162 , & V_143 -> V_162 ,
V_143 -> V_186 ) ;
if ( V_285 )
break;
}
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_285 ;
}
struct V_9 * F_192 ( struct V_110 * V_110 , const struct V_164 * V_162 ,
struct V_6 * V_7 , int V_282 )
{
struct V_9 * V_10 , * V_286 = NULL ;
unsigned int V_172 = F_113 ( V_162 ) ;
F_118 () ;
F_193 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_110 ) )
continue;
if ( F_165 ( & V_10 -> V_162 , V_162 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_168 & ( V_280 | V_284 ) || V_282 ) ) {
V_286 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_132 () ;
return V_286 ;
}
static void F_194 ( struct V_9 * V_10 , int V_287 )
{
if ( V_287 )
V_10 -> V_55 |= V_288 ;
if ( V_10 -> V_55 & V_197 ) {
F_144 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_55 |= V_146 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_287 )
F_152 ( 0 , V_10 ) ;
F_149 ( V_10 ) ;
} else if ( V_10 -> V_55 & V_189 ) {
struct V_9 * V_206 ;
F_144 ( & V_10 -> V_36 ) ;
V_206 = V_10 -> V_206 ;
if ( V_206 ) {
F_18 ( V_206 ) ;
F_145 ( & V_10 -> V_36 ) ;
F_154 ( V_206 , V_10 ) ;
F_149 ( V_206 ) ;
} else {
F_145 ( & V_10 -> V_36 ) ;
}
F_143 ( V_10 ) ;
} else {
F_143 ( V_10 ) ;
}
}
static int F_195 ( struct V_9 * V_10 )
{
int V_32 = - V_289 ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 == V_290 ) {
V_10 -> V_156 = V_291 ;
V_32 = 0 ;
}
F_145 ( & V_10 -> V_36 ) ;
return V_32 ;
}
void F_196 ( struct V_9 * V_10 )
{
struct V_164 V_162 ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_110 * V_110 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( F_195 ( V_10 ) ) {
F_149 ( V_10 ) ;
return;
}
F_197 ( L_13 ,
V_10 -> V_5 -> V_7 -> V_53 , & V_10 -> V_162 ) ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_55 & V_292 ) {
int V_168 = V_10 -> V_168 ;
T_1 V_55 = V_10 -> V_55 ;
struct V_164 V_293 ;
struct V_9 * V_294 ;
T_1 V_169 , V_295 ;
int V_167 = V_10 -> V_186 ;
int V_296 = V_10 -> V_297 + 1 ;
if ( V_296 > V_110 -> V_18 . V_47 . V_298 ) {
F_197 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_53 ) ;
goto V_299;
}
V_293 = V_10 -> V_162 ;
if ( F_198 ( & V_293 , V_296 ,
V_5 ) )
goto V_299;
V_169 = V_10 -> V_169 ;
V_295 = V_10 -> V_170 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_5 -> V_39 . V_300 &&
F_185 ( V_5 ) >=
V_5 -> V_39 . V_300 )
goto V_301;
F_197 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_53 ) ;
V_294 = F_116 ( V_5 , & V_293 , NULL , V_167 ,
V_168 , V_55 , V_169 ,
V_295 ) ;
if ( F_53 ( V_294 ) )
goto V_301;
F_144 ( & V_294 -> V_36 ) ;
V_294 -> V_297 = V_296 ;
V_294 -> V_156 = V_302 ;
F_145 ( & V_294 -> V_36 ) ;
F_16 ( V_294 , V_110 -> V_18 . V_47 . V_303 ) ;
F_149 ( V_294 ) ;
V_301:
F_144 ( & V_10 -> V_36 ) ;
} else if ( V_5 -> V_39 . V_58 > 1 && ! V_5 -> V_39 . V_180 ) {
V_162 . V_304 [ 0 ] = F_199 ( 0xfe800000 ) ;
V_162 . V_304 [ 1 ] = 0 ;
if ( ! F_200 ( V_162 . V_220 + 8 , V_5 -> V_7 ) &&
F_165 ( & V_10 -> V_162 , & V_162 ) ) {
V_5 -> V_39 . V_180 = 1 ;
F_43 ( L_16 ,
V_10 -> V_5 -> V_7 -> V_53 ) ;
}
}
V_299:
V_10 -> V_156 = V_305 ;
F_145 ( & V_10 -> V_36 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_201 ( struct V_6 * V_7 , const struct V_164 * V_162 )
{
struct V_164 V_306 ;
if ( V_7 -> V_55 & ( V_57 | V_56 ) )
return;
F_202 ( V_162 , & V_306 ) ;
F_49 ( V_7 , & V_306 ) ;
}
void F_203 ( struct V_4 * V_5 , const struct V_164 * V_162 )
{
struct V_164 V_306 ;
if ( V_5 -> V_7 -> V_55 & ( V_57 | V_56 ) )
return;
F_202 ( V_162 , & V_306 ) ;
F_204 ( V_5 , & V_306 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_164 V_162 ;
if ( V_10 -> V_186 >= 127 )
return;
F_205 ( & V_162 , & V_10 -> V_162 , V_10 -> V_186 ) ;
if ( F_206 ( & V_162 ) )
return;
F_207 ( V_10 -> V_5 , & V_162 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
struct V_164 V_162 ;
if ( V_10 -> V_186 >= 127 )
return;
F_205 ( & V_162 , & V_10 -> V_162 , V_10 -> V_186 ) ;
if ( F_206 ( & V_162 ) )
return;
F_208 ( V_10 -> V_5 , & V_162 ) ;
}
static int F_209 ( T_3 * V_307 , struct V_6 * V_7 )
{
if ( V_7 -> V_308 != V_309 )
return - 1 ;
memcpy ( V_307 , V_7 -> V_310 , V_309 ) ;
V_307 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_210 ( T_3 * V_307 , struct V_6 * V_7 )
{
union V_311 * V_312 ;
if ( V_7 -> V_308 != V_313 )
return - 1 ;
V_312 = (union V_311 * ) V_7 -> V_310 ;
memcpy ( V_307 , & V_312 -> V_314 . V_315 , sizeof( V_312 -> V_314 . V_315 ) ) ;
V_307 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_211 ( T_3 * V_307 , struct V_6 * V_7 )
{
if ( V_7 -> V_308 != V_316 )
return - 1 ;
memset ( V_307 , 0 , 7 ) ;
V_307 [ 7 ] = * ( T_3 * ) V_7 -> V_310 ;
return 0 ;
}
static int F_212 ( T_3 * V_307 , struct V_6 * V_7 )
{
if ( V_7 -> V_308 != V_317 )
return - 1 ;
memcpy ( V_307 , V_7 -> V_310 + 12 , 8 ) ;
V_307 [ 0 ] |= 2 ;
return 0 ;
}
static int F_213 ( T_3 * V_307 , T_4 V_162 )
{
if ( V_162 == 0 )
return - 1 ;
V_307 [ 0 ] = ( F_214 ( V_162 ) || F_215 ( V_162 ) ||
F_216 ( V_162 ) || F_217 ( V_162 ) ||
F_218 ( V_162 ) || F_219 ( V_162 ) ||
F_220 ( V_162 ) || F_221 ( V_162 ) ||
F_222 ( V_162 ) || F_223 ( V_162 ) ||
F_224 ( V_162 ) ) ? 0x00 : 0x02 ;
V_307 [ 1 ] = 0 ;
V_307 [ 2 ] = 0x5E ;
V_307 [ 3 ] = 0xFE ;
memcpy ( V_307 + 4 , & V_162 , 4 ) ;
return 0 ;
}
static int F_225 ( T_3 * V_307 , struct V_6 * V_7 )
{
if ( V_7 -> V_61 & V_62 )
return F_213 ( V_307 , * ( T_4 * ) V_7 -> V_310 ) ;
return - 1 ;
}
static int F_226 ( T_3 * V_307 , struct V_6 * V_7 )
{
return F_213 ( V_307 , * ( T_4 * ) V_7 -> V_310 ) ;
}
static int F_227 ( T_3 * V_307 , struct V_6 * V_7 )
{
memcpy ( V_307 , V_7 -> V_318 , 3 ) ;
memcpy ( V_307 + 5 , V_7 -> V_318 + 3 , 3 ) ;
V_307 [ 3 ] = 0xFF ;
V_307 [ 4 ] = 0xFE ;
V_307 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_200 ( T_3 * V_307 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_319 :
case V_320 :
return F_228 ( V_307 , V_7 ) ;
case V_321 :
return F_211 ( V_307 , V_7 ) ;
case V_322 :
return F_212 ( V_307 , V_7 ) ;
case V_60 :
return F_225 ( V_307 , V_7 ) ;
case V_323 :
return F_226 ( V_307 , V_7 ) ;
case V_324 :
return F_209 ( V_307 , V_7 ) ;
case V_325 :
return F_210 ( V_307 , V_7 ) ;
case V_68 :
return F_227 ( V_307 , V_7 ) ;
}
return - 1 ;
}
static int F_229 ( T_3 * V_307 , struct V_4 * V_5 )
{
int V_32 = - 1 ;
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_183 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_168 > V_280 )
break;
if ( V_10 -> V_168 == V_280 && ! ( V_10 -> V_55 & V_146 ) ) {
memcpy ( V_307 , V_10 -> V_162 . V_220 + 8 , 8 ) ;
V_32 = 0 ;
break;
}
}
F_179 ( & V_5 -> V_36 ) ;
return V_32 ;
}
static void F_230 ( struct V_4 * V_5 )
{
V_326:
F_231 ( V_5 -> V_224 , sizeof( V_5 -> V_224 ) ) ;
V_5 -> V_224 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_224 [ 0 ] == 0xfd &&
( V_5 -> V_224 [ 1 ] & V_5 -> V_224 [ 2 ] & V_5 -> V_224 [ 3 ] & V_5 -> V_224 [ 4 ] & V_5 -> V_224 [ 5 ] & V_5 -> V_224 [ 6 ] ) == 0xff &&
( V_5 -> V_224 [ 7 ] & 0x80 ) )
goto V_326;
if ( ( V_5 -> V_224 [ 0 ] | V_5 -> V_224 [ 1 ] ) == 0 ) {
if ( V_5 -> V_224 [ 2 ] == 0x5e && V_5 -> V_224 [ 3 ] == 0xfe )
goto V_326;
if ( ( V_5 -> V_224 [ 2 ] | V_5 -> V_224 [ 3 ] | V_5 -> V_224 [ 4 ] | V_5 -> V_224 [ 5 ] | V_5 -> V_224 [ 6 ] | V_5 -> V_224 [ 7 ] ) == 0x00 )
goto V_326;
}
}
static void V_66 ( unsigned long V_327 )
{
struct V_4 * V_5 = (struct V_4 * ) V_327 ;
unsigned long V_193 ;
F_118 () ;
F_147 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_81 )
goto V_184;
F_230 ( V_5 ) ;
V_193 = V_13 +
V_5 -> V_39 . V_227 * V_3 -
V_5 -> V_39 . V_223 * V_5 -> V_39 . V_229 *
F_157 ( V_5 -> V_48 , V_230 ) -
V_5 -> V_39 . V_228 * V_3 ;
if ( F_138 ( V_193 , V_13 ) ) {
F_105 ( L_17 ,
V_52 , V_5 -> V_7 -> V_53 ) ;
goto V_184;
}
if ( ! F_15 ( & V_5 -> V_65 , V_193 ) )
F_14 ( V_5 ) ;
V_184:
F_151 ( & V_5 -> V_36 ) ;
F_132 () ;
F_103 ( V_5 ) ;
}
static void F_155 ( struct V_4 * V_5 , struct V_164 * V_210 )
{
if ( V_210 && memcmp ( V_5 -> V_224 , & V_210 -> V_220 [ 8 ] , 8 ) == 0 )
F_230 ( V_5 ) ;
}
static void
F_232 ( struct V_164 * V_328 , int V_329 , struct V_6 * V_7 ,
unsigned long V_193 , T_1 V_55 )
{
struct V_330 V_331 = {
. V_332 = F_233 ( V_7 ) ? : V_333 ,
. V_334 = V_335 ,
. V_336 = V_7 -> V_93 ,
. V_337 = V_193 ,
. V_338 = V_329 ,
. V_339 = V_340 | V_55 ,
. V_341 . V_342 = F_34 ( V_7 ) ,
. V_343 = V_344 ,
} ;
V_331 . V_345 = * V_328 ;
#if F_42 ( V_59 )
if ( V_7 -> type == V_60 && ( V_7 -> V_55 & V_346 ) )
V_331 . V_339 |= V_347 ;
#endif
F_234 ( & V_331 ) ;
}
static struct V_171 * F_140 ( const struct V_164 * V_328 ,
int V_329 ,
const struct V_6 * V_7 ,
T_1 V_55 , T_1 V_348 )
{
struct V_349 * V_350 ;
struct V_171 * V_158 = NULL ;
struct V_351 * V_150 ;
T_1 V_352 = F_233 ( V_7 ) ? : V_333 ;
V_150 = F_235 ( F_34 ( V_7 ) , V_352 ) ;
if ( ! V_150 )
return NULL ;
F_173 ( & V_150 -> V_353 ) ;
V_350 = F_236 ( & V_150 -> V_354 , V_328 , V_329 , NULL , 0 ) ;
if ( ! V_350 )
goto V_184;
V_348 |= V_355 ;
for ( V_158 = V_350 -> V_356 ; V_158 ; V_158 = V_158 -> V_240 . V_357 ) {
if ( V_158 -> V_240 . V_7 -> V_93 != V_7 -> V_93 )
continue;
if ( ( V_158 -> V_204 & V_55 ) != V_55 )
continue;
if ( ( V_158 -> V_204 & V_348 ) != 0 )
continue;
F_237 ( & V_158 -> V_240 ) ;
break;
}
V_184:
F_179 ( & V_150 -> V_353 ) ;
return V_158 ;
}
static void F_238 ( struct V_6 * V_7 )
{
struct V_330 V_331 = {
. V_332 = F_233 ( V_7 ) ? : V_358 ,
. V_334 = V_335 ,
. V_336 = V_7 -> V_93 ,
. V_338 = 8 ,
. V_339 = V_340 ,
. V_341 . V_342 = F_34 ( V_7 ) ,
} ;
F_239 ( & V_331 . V_345 , F_199 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_234 ( & V_331 ) ;
}
static struct V_4 * F_240 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return F_30 ( - V_111 ) ;
if ( V_5 -> V_39 . V_180 )
return F_30 ( - V_181 ) ;
if ( ! ( V_7 -> V_55 & V_57 ) )
F_238 ( V_7 ) ;
return V_5 ;
}
static void F_241 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_225 V_169 , V_225 V_170 ,
bool V_359 , unsigned long V_219 )
{
T_1 V_55 ;
struct V_9 * V_209 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ift, &idev->tempaddr_list, tmp_list) {
int V_214 , V_360 , V_361 ;
if ( V_10 != V_209 -> V_206 )
continue;
V_214 = ( V_219 - V_209 -> V_1 ) / V_3 ;
V_360 = V_5 -> V_39 . V_226 - V_214 ;
if ( V_360 < 0 )
V_360 = 0 ;
V_361 = V_5 -> V_39 . V_227 -
V_5 -> V_39 . V_228 - V_214 ;
if ( V_361 < 0 )
V_361 = 0 ;
if ( V_169 > V_360 )
V_169 = V_360 ;
if ( V_170 > V_361 )
V_170 = V_361 ;
F_119 ( & V_209 -> V_36 ) ;
V_55 = V_209 -> V_55 ;
V_209 -> V_169 = V_169 ;
V_209 -> V_170 = V_170 ;
V_209 -> V_75 = V_219 ;
if ( V_170 > 0 )
V_209 -> V_55 &= ~ V_251 ;
F_128 ( & V_209 -> V_36 ) ;
if ( ! ( V_55 & V_146 ) )
F_152 ( 0 , V_209 ) ;
}
if ( ( V_359 || F_242 ( & V_5 -> V_64 ) ) &&
V_5 -> V_39 . V_70 > 0 ) {
F_179 ( & V_5 -> V_36 ) ;
F_154 ( V_10 , NULL ) ;
} else {
F_179 ( & V_5 -> V_36 ) ;
}
}
static bool F_243 ( struct V_4 * V_5 )
{
return V_5 -> V_43 == V_44 ||
V_5 -> V_43 == V_362 ;
}
void F_244 ( struct V_6 * V_7 , T_3 * V_363 , int V_142 , bool V_364 )
{
struct V_365 * V_366 ;
V_225 V_169 ;
V_225 V_170 ;
int V_173 ;
T_1 V_218 = 0 ;
struct V_4 * V_121 ;
struct V_110 * V_110 = F_34 ( V_7 ) ;
V_366 = (struct V_365 * ) V_363 ;
if ( V_142 < sizeof( struct V_365 ) ) {
F_38 ( L_18 ) ;
return;
}
V_173 = F_117 ( & V_366 -> V_367 ) ;
if ( V_173 & ( V_175 | V_368 ) )
return;
V_169 = F_245 ( V_366 -> V_369 ) ;
V_170 = F_245 ( V_366 -> V_370 ) ;
if ( V_170 > V_169 ) {
F_246 ( L_19 ) ;
return;
}
V_121 = F_247 ( V_7 ) ;
if ( ! V_121 ) {
F_176 ( L_20 ,
V_7 -> V_53 ) ;
return;
}
if ( V_366 -> V_285 ) {
struct V_171 * V_158 ;
unsigned long V_371 ;
if ( V_3 > V_372 )
V_371 = F_137 ( V_169 , V_3 ) ;
else
V_371 = F_137 ( V_169 , V_372 ) ;
if ( F_248 ( V_371 ) )
V_371 *= V_3 ;
V_158 = F_140 ( & V_366 -> V_367 ,
V_366 -> V_186 ,
V_7 ,
V_373 | V_374 ,
V_202 | V_203 ) ;
if ( V_158 ) {
if ( V_169 == 0 ) {
F_141 ( V_158 ) ;
V_158 = NULL ;
} else if ( F_248 ( V_371 ) ) {
F_142 ( V_158 , V_13 + V_371 ) ;
} else {
F_249 ( V_158 ) ;
}
} else if ( V_169 ) {
T_5 V_193 = 0 ;
int V_55 = V_373 | V_374 ;
if ( F_248 ( V_371 ) ) {
V_55 |= V_205 ;
V_193 = F_250 ( V_371 ) ;
}
F_232 ( & V_366 -> V_367 , V_366 -> V_186 ,
V_7 , V_193 , V_55 ) ;
}
F_106 ( V_158 ) ;
}
if ( V_366 -> V_375 && V_121 -> V_39 . V_375 ) {
struct V_9 * V_10 ;
struct V_164 V_162 ;
int V_359 = 0 , V_376 = 0 ;
bool V_187 = false ;
if ( V_366 -> V_186 == 64 ) {
memcpy ( & V_162 , & V_366 -> V_367 , 8 ) ;
if ( ! F_206 ( & V_121 -> V_71 ) ) {
F_173 ( & V_121 -> V_36 ) ;
memcpy ( V_162 . V_220 + 8 ,
V_121 -> V_71 . V_220 + 8 , 8 ) ;
F_179 ( & V_121 -> V_36 ) ;
V_187 = true ;
} else if ( F_243 ( V_121 ) &&
! F_198 ( & V_162 , 0 ,
V_121 ) ) {
V_218 |= V_292 ;
goto V_377;
} else if ( F_200 ( V_162 . V_220 + 8 , V_7 ) &&
F_229 ( V_162 . V_220 + 8 , V_121 ) ) {
F_103 ( V_121 ) ;
return;
}
goto V_377;
}
F_176 ( L_21 ,
V_366 -> V_186 ) ;
F_103 ( V_121 ) ;
return;
V_377:
V_10 = F_192 ( V_110 , & V_162 , V_7 , 1 ) ;
if ( ! V_10 && V_169 ) {
int V_300 = V_121 -> V_39 . V_300 ;
#ifdef F_162
if ( V_121 -> V_39 . V_235 &&
! V_110 -> V_18 . V_124 -> V_50 && V_364 )
V_218 |= V_232 ;
#endif
if ( ! V_300 ||
F_185 ( V_121 ) < V_300 )
V_10 = F_116 ( V_121 , & V_162 , NULL ,
V_366 -> V_186 ,
V_173 & V_378 ,
V_218 , V_169 ,
V_170 ) ;
if ( F_251 ( V_10 ) ) {
F_103 ( V_121 ) ;
return;
}
V_376 = 0 ;
V_359 = 1 ;
F_144 ( & V_10 -> V_36 ) ;
V_10 -> V_55 |= V_379 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_187 = V_187 ;
F_145 ( & V_10 -> V_36 ) ;
F_159 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_55 ;
unsigned long V_219 ;
T_1 V_380 ;
F_144 ( & V_10 -> V_36 ) ;
V_219 = V_13 ;
if ( V_10 -> V_169 > ( V_219 - V_10 -> V_75 ) / V_3 )
V_380 = V_10 -> V_169 - ( V_219 - V_10 -> V_75 ) / V_3 ;
else
V_380 = 0 ;
if ( ! V_376 && ! V_359 && V_380 ) {
const T_1 V_381 = F_156 ( T_1 ,
V_380 , V_382 ) ;
V_169 = F_252 ( V_169 , V_381 ) ;
V_376 = 1 ;
}
if ( V_376 ) {
V_10 -> V_169 = V_169 ;
V_10 -> V_170 = V_170 ;
V_10 -> V_75 = V_219 ;
V_55 = V_10 -> V_55 ;
V_10 -> V_55 &= ~ V_251 ;
F_145 ( & V_10 -> V_36 ) ;
if ( ! ( V_55 & V_146 ) )
F_152 ( 0 , V_10 ) ;
} else
F_145 ( & V_10 -> V_36 ) ;
F_241 ( V_121 , V_10 , V_169 , V_170 ,
V_359 , V_219 ) ;
F_149 ( V_10 ) ;
F_253 () ;
}
}
F_254 ( V_383 , V_121 , V_366 ) ;
F_103 ( V_121 ) ;
}
int F_255 ( struct V_110 * V_110 , void T_6 * V_384 )
{
struct V_385 V_386 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_256 () ;
V_32 = - V_387 ;
if ( F_257 ( & V_386 , V_384 , sizeof( struct V_385 ) ) )
goto V_388;
V_7 = F_75 ( V_110 , V_386 . V_389 ) ;
V_32 = - V_178 ;
if ( ! V_7 )
goto V_388;
#if F_42 ( V_59 )
if ( V_7 -> type == V_60 ) {
const struct V_390 * V_391 = V_7 -> V_392 ;
struct V_393 V_394 ;
struct V_395 V_151 ;
V_32 = - V_177 ;
if ( ! ( F_117 ( & V_386 . V_396 ) & V_234 ) )
goto V_388;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_397 . V_273 = V_386 . V_396 . V_304 [ 3 ] ;
V_151 . V_397 . V_274 = 0 ;
V_151 . V_397 . V_398 = 4 ;
V_151 . V_397 . V_399 = 5 ;
V_151 . V_397 . V_400 = V_401 ;
V_151 . V_397 . V_402 = 64 ;
V_394 . V_403 . V_404 = ( V_405 void T_6 * ) & V_151 ;
if ( V_391 -> V_406 ) {
T_7 V_407 = F_258 () ;
F_259 ( V_408 ) ;
V_32 = V_391 -> V_406 ( V_7 , & V_394 , V_409 ) ;
F_259 ( V_407 ) ;
} else
V_32 = - V_410 ;
if ( V_32 == 0 ) {
V_32 = - V_111 ;
V_7 = F_260 ( V_110 , V_151 . V_53 ) ;
if ( ! V_7 )
goto V_388;
V_32 = F_261 ( V_7 ) ;
}
}
#endif
V_388:
F_95 () ;
return V_32 ;
}
static int F_262 ( struct V_411 * V_117 , bool V_412 ,
const struct V_164 * V_162 , int V_93 )
{
int V_217 ;
F_29 () ;
F_263 ( V_117 ) ;
if ( V_412 )
V_217 = F_264 ( V_117 , V_93 , V_162 ) ;
else
V_217 = F_265 ( V_117 , V_93 , V_162 ) ;
F_266 ( V_117 ) ;
return V_217 ;
}
static int F_267 ( struct V_110 * V_110 , int V_93 ,
const struct V_164 * V_328 ,
const struct V_164 * V_413 ,
unsigned int V_329 , V_225 V_414 ,
V_225 V_170 , V_225 V_169 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_415 ;
T_5 V_193 ;
int V_168 ;
T_1 V_55 ;
F_29 () ;
if ( V_329 > 128 )
return - V_35 ;
if ( ! V_169 || V_170 > V_169 )
return - V_35 ;
if ( V_414 & V_379 && V_329 != 64 )
return - V_35 ;
V_7 = F_75 ( V_110 , V_93 ) ;
if ( ! V_7 )
return - V_178 ;
V_5 = F_240 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return F_122 ( V_5 ) ;
if ( V_414 & V_416 ) {
int V_217 = F_262 ( V_110 -> V_18 . V_417 ,
true , V_328 , V_93 ) ;
if ( V_217 < 0 )
return V_217 ;
}
V_168 = F_158 ( V_328 ) ;
V_415 = F_137 ( V_169 , V_3 ) ;
if ( F_248 ( V_415 ) ) {
V_193 = F_250 ( V_415 * V_3 ) ;
V_169 = V_415 ;
V_55 = V_205 ;
} else {
V_193 = 0 ;
V_55 = 0 ;
V_414 |= V_197 ;
}
V_415 = F_137 ( V_170 , V_3 ) ;
if ( F_248 ( V_415 ) ) {
if ( V_415 == 0 )
V_414 |= V_251 ;
V_170 = V_415 ;
}
V_10 = F_116 ( V_5 , V_328 , V_413 , V_329 , V_168 , V_414 ,
V_169 , V_170 ) ;
if ( ! F_53 ( V_10 ) ) {
if ( ! ( V_414 & V_198 ) ) {
F_232 ( & V_10 -> V_162 , V_10 -> V_186 , V_7 ,
V_193 , V_55 ) ;
}
F_159 ( V_10 ) ;
if ( V_414 & V_379 )
F_241 ( V_5 , V_10 , V_169 , V_170 ,
true , V_13 ) ;
F_149 ( V_10 ) ;
F_268 () ;
return 0 ;
} else if ( V_414 & V_416 ) {
F_262 ( V_110 -> V_18 . V_417 ,
false , V_328 , V_93 ) ;
}
return F_122 ( V_10 ) ;
}
static int F_269 ( struct V_110 * V_110 , int V_93 , T_1 V_414 ,
const struct V_164 * V_328 , unsigned int V_329 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_329 > 128 )
return - V_35 ;
V_7 = F_75 ( V_110 , V_93 ) ;
if ( ! V_7 )
return - V_178 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_418 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_186 == V_329 &&
F_165 ( V_328 , & V_10 -> V_162 ) ) {
F_18 ( V_10 ) ;
F_179 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_55 & V_189 ) &&
( V_414 & V_379 ) )
F_241 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_143 ( V_10 ) ;
F_268 () ;
if ( F_270 ( V_328 ) ) {
F_262 ( V_110 -> V_18 . V_417 ,
false , V_328 , V_7 -> V_93 ) ;
}
return 0 ;
}
}
F_179 ( & V_5 -> V_36 ) ;
return - V_177 ;
}
int F_271 ( struct V_110 * V_110 , void T_6 * V_384 )
{
struct V_385 V_386 ;
int V_32 ;
if ( ! F_272 ( V_110 -> V_419 , V_420 ) )
return - V_421 ;
if ( F_257 ( & V_386 , V_384 , sizeof( struct V_385 ) ) )
return - V_387 ;
F_256 () ;
V_32 = F_267 ( V_110 , V_386 . V_389 , & V_386 . V_396 , NULL ,
V_386 . V_422 , V_197 ,
V_423 , V_423 ) ;
F_95 () ;
return V_32 ;
}
int F_273 ( struct V_110 * V_110 , void T_6 * V_384 )
{
struct V_385 V_386 ;
int V_32 ;
if ( ! F_272 ( V_110 -> V_419 , V_420 ) )
return - V_421 ;
if ( F_257 ( & V_386 , V_384 , sizeof( struct V_385 ) ) )
return - V_387 ;
F_256 () ;
V_32 = F_269 ( V_110 , V_386 . V_389 , 0 , & V_386 . V_396 ,
V_386 . V_422 ) ;
F_95 () ;
return V_32 ;
}
static void F_274 ( struct V_4 * V_5 , const struct V_164 * V_162 ,
int V_329 , int V_168 )
{
struct V_9 * V_10 ;
V_10 = F_116 ( V_5 , V_162 , NULL , V_329 ,
V_168 , V_197 ,
V_423 , V_423 ) ;
if ( ! F_53 ( V_10 ) ) {
F_144 ( & V_10 -> V_36 ) ;
V_10 -> V_55 &= ~ V_146 ;
F_145 ( & V_10 -> V_36 ) ;
F_152 ( V_424 , V_10 ) ;
F_149 ( V_10 ) ;
}
}
static void F_275 ( struct V_4 * V_5 )
{
struct V_164 V_162 ;
struct V_6 * V_7 ;
struct V_110 * V_110 = F_34 ( V_5 -> V_7 ) ;
int V_168 , V_329 ;
T_1 V_425 = 0 ;
F_29 () ;
memset ( & V_162 , 0 , sizeof( struct V_164 ) ) ;
memcpy ( & V_162 . V_304 [ 3 ] , V_5 -> V_7 -> V_310 , 4 ) ;
if ( V_5 -> V_7 -> V_55 & V_346 ) {
V_162 . V_304 [ 0 ] = F_199 ( 0xfe800000 ) ;
V_168 = V_280 ;
V_329 = 64 ;
} else {
V_168 = V_234 ;
V_329 = 96 ;
V_425 |= V_347 ;
}
if ( V_162 . V_304 [ 3 ] ) {
F_274 ( V_5 , & V_162 , V_329 , V_168 ) ;
F_232 ( & V_162 , V_329 , V_5 -> V_7 , 0 , V_425 ) ;
return;
}
F_91 (net, dev) {
struct V_426 * V_427 = F_276 ( V_7 ) ;
if ( V_427 && ( V_7 -> V_55 & V_82 ) ) {
struct V_428 * V_143 ;
int V_429 = V_168 ;
for ( V_143 = V_427 -> V_430 ; V_143 ; V_143 = V_143 -> V_431 ) {
V_162 . V_304 [ 3 ] = V_143 -> V_432 ;
if ( V_143 -> V_433 == V_434 )
continue;
if ( V_143 -> V_433 >= V_435 ) {
if ( V_5 -> V_7 -> V_55 & V_346 )
continue;
V_429 |= V_284 ;
}
F_274 ( V_5 , & V_162 , V_329 , V_429 ) ;
F_232 ( & V_162 , V_329 , V_5 -> V_7 , 0 ,
V_425 ) ;
}
}
}
}
static void F_277 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_436 ;
struct V_9 * V_437 ;
struct V_171 * V_438 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_22 , V_52 ) ;
return;
}
F_274 ( V_5 , & V_439 , 128 , V_284 ) ;
F_91 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_436 -> V_53 , V_7 -> V_53 ) )
continue;
V_5 = F_52 ( V_436 ) ;
if ( ! V_5 )
continue;
F_173 ( & V_5 -> V_36 ) ;
F_87 (sp_ifa, &idev->addr_list, if_list) {
if ( V_437 -> V_55 & ( V_288 | V_146 ) )
continue;
if ( V_437 -> V_158 ) {
if ( V_437 -> V_158 -> V_240 . V_440 > 0 ) {
F_106 ( V_437 -> V_158 ) ;
V_437 -> V_158 = NULL ;
} else {
continue;
}
}
V_438 = F_121 ( V_5 , & V_437 -> V_162 , false ) ;
if ( ! F_53 ( V_438 ) ) {
V_437 -> V_158 = V_438 ;
F_278 ( V_438 ) ;
}
}
F_179 ( & V_5 -> V_36 ) ;
}
}
static void F_279 ( struct V_4 * V_5 ,
const struct V_164 * V_162 , T_1 V_55 )
{
struct V_9 * V_10 ;
T_1 V_218 = V_55 | V_197 ;
#ifdef F_162
if ( V_5 -> V_39 . V_235 &&
! F_34 ( V_5 -> V_7 ) -> V_18 . V_124 -> V_50 )
V_218 |= V_232 ;
#endif
V_10 = F_116 ( V_5 , V_162 , NULL , 64 , V_280 , V_218 ,
V_423 , V_423 ) ;
if ( ! F_53 ( V_10 ) ) {
F_232 ( & V_10 -> V_162 , V_10 -> V_186 , V_5 -> V_7 , 0 , 0 ) ;
F_159 ( V_10 ) ;
F_149 ( V_10 ) ;
}
}
static bool F_280 ( struct V_164 V_441 )
{
if ( ( V_441 . V_304 [ 2 ] | V_441 . V_304 [ 3 ] ) == 0 )
return true ;
if ( V_441 . V_304 [ 2 ] == F_199 ( 0x02005eff ) &&
( ( V_441 . V_304 [ 3 ] & F_199 ( 0xfe000000 ) ) == F_199 ( 0xfe000000 ) ) )
return true ;
if ( V_441 . V_304 [ 2 ] == F_199 ( 0xfdffffff ) &&
( ( V_441 . V_304 [ 3 ] & F_199 ( 0xffffff80 ) ) == F_199 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_198 ( struct V_164 * V_441 ,
T_3 V_442 ,
const struct V_4 * V_5 )
{
static F_281 ( V_36 ) ;
static V_225 V_443 [ V_444 ] ;
static V_225 V_445 [ V_446 ] ;
static union {
char V_447 [ V_448 ] ;
struct {
struct V_164 V_449 ;
T_4 V_367 [ 2 ] ;
unsigned char V_450 [ V_451 ] ;
T_3 V_442 ;
} V_452 ;
} V_327 ;
struct V_164 V_449 ;
struct V_164 V_453 ;
struct V_110 * V_110 = F_34 ( V_5 -> V_7 ) ;
F_282 ( sizeof( V_327 . V_447 ) != sizeof( V_327 ) ) ;
if ( V_5 -> V_39 . V_41 . V_42 )
V_449 = V_5 -> V_39 . V_41 . V_449 ;
else if ( V_110 -> V_18 . V_40 -> V_41 . V_42 )
V_449 = V_110 -> V_18 . V_40 -> V_41 . V_449 ;
else
return - 1 ;
V_221:
F_144 ( & V_36 ) ;
F_283 ( V_443 ) ;
memset ( & V_327 , 0 , sizeof( V_327 ) ) ;
memset ( V_445 , 0 , sizeof( V_445 ) ) ;
memcpy ( V_327 . V_450 , V_5 -> V_7 -> V_318 , V_5 -> V_7 -> V_308 ) ;
V_327 . V_367 [ 0 ] = V_441 -> V_304 [ 0 ] ;
V_327 . V_367 [ 1 ] = V_441 -> V_304 [ 1 ] ;
V_327 . V_449 = V_449 ;
V_327 . V_442 = V_442 ;
F_284 ( V_443 , V_327 . V_447 , V_445 ) ;
V_453 = * V_441 ;
V_453 . V_304 [ 2 ] = ( V_405 T_4 ) V_443 [ 0 ] ;
V_453 . V_304 [ 3 ] = ( V_405 T_4 ) V_443 [ 1 ] ;
F_145 ( & V_36 ) ;
if ( F_280 ( V_453 ) ) {
V_442 ++ ;
if ( V_442 > F_34 ( V_5 -> V_7 ) -> V_18 . V_47 . V_298 )
return - 1 ;
goto V_221;
}
* V_441 = V_453 ;
return 0 ;
}
static void F_285 ( struct V_4 * V_5 )
{
struct V_454 * V_455 = & V_5 -> V_39 . V_41 ;
if ( V_455 -> V_42 )
return;
V_455 = & V_5 -> V_39 . V_41 ;
F_231 ( & V_455 -> V_449 , sizeof( V_455 -> V_449 ) ) ;
V_455 -> V_42 = true ;
}
static void F_286 ( struct V_4 * V_5 , bool V_456 )
{
struct V_164 V_162 ;
if ( F_287 ( V_5 -> V_7 ) )
return;
F_239 ( & V_162 , F_199 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
switch ( V_5 -> V_43 ) {
case V_362 :
F_285 ( V_5 ) ;
case V_44 :
if ( ! F_198 ( & V_162 , 0 , V_5 ) )
F_279 ( V_5 , & V_162 ,
V_292 ) ;
else if ( V_456 )
F_232 ( & V_162 , 64 , V_5 -> V_7 , 0 , 0 ) ;
break;
case V_45 :
if ( F_200 ( V_162 . V_220 + 8 , V_5 -> V_7 ) == 0 )
F_279 ( V_5 , & V_162 , 0 ) ;
else if ( V_456 )
F_232 ( & V_162 , 64 , V_5 -> V_7 , 0 , 0 ) ;
break;
case V_457 :
default:
break;
}
}
static void F_288 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_319 ) &&
( V_7 -> type != V_320 ) &&
( V_7 -> type != V_321 ) &&
( V_7 -> type != V_322 ) &&
( V_7 -> type != V_325 ) &&
( V_7 -> type != V_68 ) &&
( V_7 -> type != V_324 ) &&
( V_7 -> type != V_69 ) ) {
return;
}
V_5 = F_240 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return;
if ( V_7 -> type == V_69 &&
V_5 -> V_43 == V_45 )
V_5 -> V_43 = V_362 ;
F_286 ( V_5 , false ) ;
}
static void F_289 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_22 , V_52 ) ;
return;
}
if ( V_7 -> V_61 & V_62 ) {
F_286 ( V_5 , false ) ;
return;
}
F_275 ( V_5 ) ;
if ( V_7 -> V_55 & V_346 )
F_238 ( V_7 ) ;
}
static void F_290 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_22 , V_52 ) ;
return;
}
F_286 ( V_5 , true ) ;
if ( V_7 -> V_55 & V_346 )
F_238 ( V_7 ) ;
}
static int F_291 ( struct V_4 * V_5 ,
struct V_9 * V_10 )
{
if ( ! V_10 -> V_158 ) {
struct V_171 * V_158 ;
V_158 = F_121 ( V_5 , & V_10 -> V_162 , false ) ;
if ( F_175 ( F_53 ( V_158 ) ) )
return F_122 ( V_158 ) ;
V_10 -> V_158 = V_158 ;
}
if ( ! ( V_10 -> V_55 & V_198 ) ) {
F_232 ( & V_10 -> V_162 , V_10 -> V_186 ,
V_5 -> V_7 , 0 , 0 ) ;
}
F_159 ( V_10 ) ;
return 0 ;
}
static void F_292 ( struct V_6 * V_7 )
{
struct V_9 * V_10 , * V_458 ;
struct V_4 * V_5 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return;
F_147 ( & V_5 -> V_36 ) ;
F_293 (ifp, tmp, &idev->addr_list, if_list) {
if ( ( V_10 -> V_55 & V_197 ) &&
F_291 ( V_5 , V_10 ) < 0 ) {
F_151 ( & V_5 -> V_36 ) ;
F_143 ( V_10 ) ;
F_147 ( & V_5 -> V_36 ) ;
F_197 ( L_23 ,
V_5 -> V_7 -> V_53 , & V_10 -> V_162 ) ;
}
}
F_151 ( & V_5 -> V_36 ) ;
}
static int F_294 ( struct V_459 * V_460 , unsigned long V_98 ,
void * V_461 )
{
struct V_6 * V_7 = F_295 ( V_461 ) ;
struct V_462 * V_463 ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
int V_464 = 0 ;
int V_32 ;
switch ( V_98 ) {
case V_465 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return F_296 ( F_122 ( V_5 ) ) ;
}
break;
case V_466 :
if ( V_7 -> V_33 < V_34 ) {
F_297 ( V_7 , 1 ) ;
break;
}
if ( V_5 ) {
F_298 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_46 = V_7 -> V_33 ;
break;
}
V_5 = F_28 ( V_7 ) ;
if ( F_53 ( V_5 ) )
break;
if ( ! ( V_5 -> V_73 & V_74 ) )
break;
V_464 = 1 ;
case V_191 :
case V_467 :
if ( V_7 -> V_55 & V_468 )
break;
if ( V_5 && V_5 -> V_39 . V_180 )
break;
if ( V_98 == V_191 ) {
F_292 ( V_7 ) ;
if ( ! F_4 ( V_7 ) ) {
F_43 ( L_24 ,
V_7 -> V_53 ) ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 )
V_5 = F_28 ( V_7 ) ;
if ( ! F_251 ( V_5 ) ) {
V_5 -> V_73 |= V_74 ;
V_464 = 1 ;
}
} else if ( V_98 == V_467 ) {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_73 & V_74 )
break;
V_5 -> V_73 |= V_74 ;
}
F_43 ( L_25 ,
V_7 -> V_53 ) ;
V_464 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_59 )
case V_60 :
F_289 ( V_7 ) ;
break;
#endif
#if F_42 ( V_469 )
case V_323 :
F_290 ( V_7 ) ;
break;
#endif
case V_470 :
F_277 ( V_7 ) ;
break;
default:
F_288 ( V_7 ) ;
break;
}
if ( ! F_251 ( V_5 ) ) {
if ( V_464 )
F_299 ( V_5 ) ;
if ( V_5 -> V_39 . V_46 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_298 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_46 = V_7 -> V_33 ;
}
V_5 -> V_75 = V_13 ;
F_300 ( V_471 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_297 ( V_7 , 1 ) ;
}
break;
case V_208 :
case V_472 :
F_297 ( V_7 , V_98 != V_208 ) ;
break;
case V_473 :
if ( V_5 ) {
F_47 ( V_5 ) ;
F_3 ( V_5 ) ;
V_32 = F_2 ( V_5 ) ;
if ( V_32 )
return F_296 ( V_32 ) ;
V_32 = F_41 ( V_5 ) ;
if ( V_32 ) {
F_3 ( V_5 ) ;
return F_296 ( V_32 ) ;
}
}
break;
case V_474 :
case V_475 :
if ( V_5 )
F_301 ( V_7 , V_98 ) ;
break;
case V_476 :
V_463 = V_461 ;
if ( V_463 -> V_477 && F_287 ( V_463 -> V_477 ) )
F_297 ( V_7 , 0 ) ;
}
return V_478 ;
}
static void F_301 ( struct V_6 * V_7 , unsigned long V_98 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_98 == V_475 )
F_302 ( V_5 ) ;
else if ( V_98 == V_474 )
F_303 ( V_5 ) ;
}
static bool F_304 ( const struct V_164 * V_162 )
{
return F_117 ( V_162 ) &
( V_368 | V_176 ) ;
}
static int F_297 ( struct V_6 * V_7 , int V_479 )
{
struct V_110 * V_110 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_143 , * V_458 ;
struct V_160 V_480 ;
int V_481 ;
bool V_482 ;
int V_156 , V_16 ;
F_29 () ;
F_305 ( V_110 , V_7 ) ;
F_306 ( & V_49 , V_7 ) ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_178 ;
if ( V_479 ) {
V_5 -> V_81 = 1 ;
F_307 ( V_7 -> V_76 , NULL ) ;
F_47 ( V_5 ) ;
}
V_481 = V_110 -> V_18 . V_124 -> V_483 ;
if ( ! V_481 )
V_481 = V_5 -> V_39 . V_483 ;
V_482 = ! ( V_479 || V_481 <= 0 ) ;
for ( V_16 = 0 ; V_16 < V_484 ; V_16 ++ ) {
struct V_133 * V_129 = & V_188 [ V_16 ] ;
F_144 ( & V_182 ) ;
V_485:
F_81 (ifa, h, addr_lst) {
if ( V_143 -> V_5 == V_5 ) {
F_9 ( V_143 ) ;
if ( ! V_482 ||
! ( V_143 -> V_55 & V_197 ) ||
F_304 ( & V_143 -> V_162 ) ) {
F_146 ( & V_143 -> V_155 ) ;
goto V_485;
}
}
}
F_145 ( & V_182 ) ;
}
F_147 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_479 )
V_5 -> V_73 &= ~ ( V_486 | V_487 | V_74 ) ;
if ( V_479 && F_7 ( & V_5 -> V_65 ) )
F_103 ( V_5 ) ;
while ( ! F_242 ( & V_5 -> V_64 ) ) {
V_143 = F_308 ( & V_5 -> V_64 ,
struct V_9 , V_190 ) ;
F_148 ( & V_143 -> V_190 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_144 ( & V_143 -> V_36 ) ;
if ( V_143 -> V_206 ) {
F_149 ( V_143 -> V_206 ) ;
V_143 -> V_206 = NULL ;
}
F_145 ( & V_143 -> V_36 ) ;
F_149 ( V_143 ) ;
F_147 ( & V_5 -> V_36 ) ;
}
V_482 = ( ! V_479 && V_481 > 0 ) ;
F_32 ( & V_480 ) ;
F_293 (ifa, tmp, &idev->addr_list, if_list) {
struct V_171 * V_158 = NULL ;
F_9 ( V_143 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_144 ( & V_143 -> V_36 ) ;
if ( V_482 && ( V_143 -> V_55 & V_197 ) &&
! F_304 ( & V_143 -> V_162 ) ) {
V_156 = V_157 ;
V_143 -> V_156 = 0 ;
if ( ! ( V_143 -> V_55 & V_488 ) )
V_143 -> V_55 |= V_146 ;
V_158 = V_143 -> V_158 ;
V_143 -> V_158 = NULL ;
} else {
V_156 = V_143 -> V_156 ;
V_143 -> V_156 = V_157 ;
F_148 ( & V_143 -> V_163 ) ;
F_130 ( & V_143 -> V_163 , & V_480 ) ;
}
F_145 ( & V_143 -> V_36 ) ;
if ( V_158 )
F_141 ( V_158 ) ;
if ( V_156 != V_157 ) {
F_309 ( V_207 , V_143 ) ;
F_134 ( V_208 , V_143 ) ;
}
F_147 ( & V_5 -> V_36 ) ;
}
F_151 ( & V_5 -> V_36 ) ;
while ( ! F_242 ( & V_480 ) ) {
V_143 = F_308 ( & V_480 ,
struct V_9 , V_163 ) ;
F_148 ( & V_143 -> V_163 ) ;
F_149 ( V_143 ) ;
}
if ( V_479 ) {
F_310 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_311 ( V_5 ) ;
}
V_5 -> V_75 = V_13 ;
if ( V_479 ) {
F_3 ( V_5 ) ;
F_39 ( & V_49 , V_5 -> V_48 ) ;
F_306 ( & V_49 , V_7 ) ;
F_103 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_327 )
{
struct V_4 * V_5 = (struct V_4 * ) V_327 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_164 V_489 ;
F_129 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_81 || ! ( V_5 -> V_73 & V_74 ) )
goto V_184;
if ( ! F_312 ( V_5 ) )
goto V_184;
if ( V_5 -> V_73 & V_487 )
goto V_184;
if ( V_5 -> V_490 ++ < V_5 -> V_39 . V_63 ) {
F_131 ( & V_5 -> V_36 ) ;
if ( ! F_184 ( V_7 , & V_489 , V_146 ) )
F_313 ( V_7 , & V_489 ,
& V_80 ) ;
else
goto V_491;
F_129 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_490 ==
V_5 -> V_39 . V_63 ) ?
V_5 -> V_39 . V_492 :
V_5 -> V_39 . V_493 ) ;
} else {
F_102 ( L_26 , V_5 -> V_7 -> V_53 ) ;
}
V_184:
F_131 ( & V_5 -> V_36 ) ;
V_491:
F_103 ( V_5 ) ;
}
static void F_314 ( struct V_9 * V_10 )
{
unsigned long V_494 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_55 & V_232 )
V_494 = 0 ;
else
V_494 = F_315 () % ( V_5 -> V_39 . V_492 ? : 1 ) ;
V_10 -> V_495 = V_5 -> V_39 . V_229 ;
F_16 ( V_10 , V_494 ) ;
}
static void F_316 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_496 = false ;
F_201 ( V_7 , & V_10 -> V_162 ) ;
F_317 ( ( V_405 T_1 ) V_10 -> V_162 . V_304 [ 3 ] ) ;
F_173 ( & V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 == V_157 )
goto V_184;
if ( V_7 -> V_55 & ( V_56 | V_57 ) ||
V_5 -> V_39 . V_58 < 1 ||
! ( V_10 -> V_55 & V_146 ) ||
V_10 -> V_55 & V_488 ) {
V_10 -> V_55 &= ~ ( V_146 | V_232 | V_288 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
F_318 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_73 & V_74 ) ) {
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
F_18 ( V_10 ) ;
F_194 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_55 & V_232 ) {
F_278 ( V_10 -> V_158 ) ;
if ( F_161 ( V_5 ) ) {
V_496 = true ;
}
}
F_314 ( V_10 ) ;
V_184:
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
if ( V_496 )
F_152 ( V_424 , V_10 ) ;
}
static void F_159 ( struct V_9 * V_10 )
{
bool V_497 = false ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 != V_157 ) {
V_10 -> V_156 = V_302 ;
V_497 = true ;
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_497 )
F_16 ( V_10 , 0 ) ;
}
static void V_185 ( struct V_498 * V_499 )
{
struct V_9 * V_10 = F_319 ( F_320 ( V_499 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_164 V_500 ;
enum {
V_501 ,
V_502 ,
V_503 ,
} V_195 = V_501 ;
F_256 () ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 == V_302 ) {
V_195 = V_502 ;
V_10 -> V_156 = V_290 ;
} else if ( V_10 -> V_156 == V_305 ) {
V_195 = V_503 ;
V_10 -> V_156 = V_291 ;
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_195 == V_502 ) {
F_316 ( V_10 ) ;
goto V_184;
} else if ( V_195 == V_503 ) {
F_194 ( V_10 , 1 ) ;
goto V_184;
}
if ( ! V_10 -> V_495 && F_195 ( V_10 ) )
goto V_184;
F_147 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_81 || ! ( V_5 -> V_73 & V_74 ) ) {
F_151 ( & V_5 -> V_36 ) ;
goto V_184;
}
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 == V_157 ) {
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
goto V_184;
}
if ( V_10 -> V_495 == 0 ) {
V_10 -> V_55 &= ~ ( V_146 | V_232 | V_288 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_318 ( V_10 ) ;
goto V_184;
}
V_10 -> V_495 -- ;
F_16 ( V_10 ,
F_157 ( V_10 -> V_5 -> V_48 , V_230 ) ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_202 ( & V_10 -> V_162 , & V_500 ) ;
F_321 ( V_10 -> V_5 -> V_7 , & V_10 -> V_162 , & V_500 , & V_72 ) ;
V_184:
F_149 ( V_10 ) ;
F_95 () ;
}
static bool F_322 ( struct V_9 * V_10 )
{
struct V_9 * V_504 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_183 (ifpiter, &idev->addr_list, if_list) {
if ( V_504 -> V_168 > V_280 )
break;
if ( V_10 != V_504 && V_504 -> V_168 == V_280 &&
( V_504 -> V_55 & ( V_197 | V_146 |
V_232 | V_288 ) ) ==
V_197 )
return false ;
}
return true ;
}
static void F_318 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_164 V_489 ;
bool V_505 , V_506 ;
F_9 ( V_10 ) ;
F_152 ( V_424 , V_10 ) ;
F_173 ( & V_10 -> V_5 -> V_36 ) ;
V_506 = V_10 -> V_168 == V_280 && F_322 ( V_10 ) ;
V_505 = V_506 &&
F_312 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_63 > 0 &&
( V_7 -> V_55 & V_57 ) == 0 ;
F_179 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_506 )
F_323 ( V_10 -> V_5 ) ;
if ( V_505 ) {
if ( F_184 ( V_7 , & V_489 , V_146 ) )
return;
F_313 ( V_7 , & V_489 , & V_80 ) ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_490 = 1 ;
V_10 -> V_5 -> V_73 |= V_486 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_493 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_299 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list) {
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_55 & V_146 &&
V_10 -> V_156 == V_290 )
F_314 ( V_10 ) ;
F_128 ( & V_10 -> V_36 ) ;
}
F_179 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_324 ( struct V_507 * V_97 , T_8 V_508 )
{
struct V_9 * V_143 = NULL ;
struct V_509 * V_156 = V_97 -> V_510 ;
struct V_110 * V_110 = F_325 ( V_97 ) ;
int V_151 = 0 ;
if ( V_508 == 0 ) {
V_156 -> V_511 = 0 ;
V_156 -> V_512 = 0 ;
}
for (; V_156 -> V_511 < V_484 ; ++ V_156 -> V_511 ) {
F_193 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_188 ( F_34 ( V_143 -> V_5 -> V_7 ) , V_110 ) )
continue;
if ( V_151 < V_156 -> V_512 ) {
V_151 ++ ;
continue;
}
V_156 -> V_512 ++ ;
return V_143 ;
}
V_156 -> V_512 = 0 ;
V_151 = 0 ;
}
return NULL ;
}
static struct V_9 * F_326 ( struct V_507 * V_97 ,
struct V_9 * V_143 )
{
struct V_509 * V_156 = V_97 -> V_510 ;
struct V_110 * V_110 = F_325 ( V_97 ) ;
F_327 (ifa, addr_lst) {
if ( ! F_188 ( F_34 ( V_143 -> V_5 -> V_7 ) , V_110 ) )
continue;
V_156 -> V_512 ++ ;
return V_143 ;
}
while ( ++ V_156 -> V_511 < V_484 ) {
V_156 -> V_512 = 0 ;
F_193 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_188 ( F_34 ( V_143 -> V_5 -> V_7 ) , V_110 ) )
continue;
V_156 -> V_512 ++ ;
return V_143 ;
}
}
return NULL ;
}
static void * F_328 ( struct V_507 * V_97 , T_8 * V_508 )
__acquires( T_9 )
{
F_118 () ;
return F_324 ( V_97 , * V_508 ) ;
}
static void * F_329 ( struct V_507 * V_97 , void * V_513 , T_8 * V_508 )
{
struct V_9 * V_143 ;
V_143 = F_326 ( V_97 , V_513 ) ;
++ * V_508 ;
return V_143 ;
}
static void F_330 ( struct V_507 * V_97 , void * V_513 )
__releases( T_9 )
{
F_132 () ;
}
static int F_331 ( struct V_507 * V_97 , void * V_513 )
{
struct V_9 * V_10 = (struct V_9 * ) V_513 ;
F_332 ( V_97 , L_27 ,
& V_10 -> V_162 ,
V_10 -> V_5 -> V_7 -> V_93 ,
V_10 -> V_186 ,
V_10 -> V_168 ,
( T_3 ) V_10 -> V_55 ,
V_10 -> V_5 -> V_7 -> V_53 ) ;
return 0 ;
}
static int F_333 ( struct V_514 * V_514 , struct V_515 * V_515 )
{
return F_334 ( V_514 , V_515 , & V_516 ,
sizeof( struct V_509 ) ) ;
}
static int T_10 F_335 ( struct V_110 * V_110 )
{
if ( ! F_336 ( L_28 , V_517 , V_110 -> V_518 , & V_519 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_337 ( struct V_110 * V_110 )
{
F_338 ( L_28 , V_110 -> V_518 ) ;
}
int T_12 F_339 ( void )
{
return F_340 ( & V_520 ) ;
}
void F_341 ( void )
{
F_342 ( & V_520 ) ;
}
int F_343 ( struct V_110 * V_110 , const struct V_164 * V_162 )
{
int V_217 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_172 = F_113 ( V_162 ) ;
F_118 () ;
F_193 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_110 ) )
continue;
if ( F_165 ( & V_10 -> V_162 , V_162 ) &&
( V_10 -> V_55 & V_256 ) ) {
V_217 = 1 ;
break;
}
}
F_132 () ;
return V_217 ;
}
static void F_268 ( void )
{
unsigned long V_219 , V_521 , V_522 , V_523 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_118 () ;
V_219 = V_13 ;
V_521 = F_344 ( V_219 + V_524 ) ;
F_10 ( & V_525 ) ;
for ( V_16 = 0 ; V_16 < V_484 ; V_16 ++ ) {
V_485:
F_193 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_214 ;
if ( ( V_10 -> V_55 & V_197 ) &&
( V_10 -> V_170 == V_423 ) )
continue;
F_119 ( & V_10 -> V_36 ) ;
V_214 = ( V_219 - V_10 -> V_75 + V_231 ) / V_3 ;
if ( V_10 -> V_169 != V_423 &&
V_214 >= V_10 -> V_169 ) {
F_128 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_143 ( V_10 ) ;
goto V_485;
} else if ( V_10 -> V_170 == V_423 ) {
F_128 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_214 >= V_10 -> V_170 ) {
int V_526 = 0 ;
if ( ! ( V_10 -> V_55 & V_251 ) ) {
V_526 = 1 ;
V_10 -> V_55 |= V_251 ;
}
if ( ( V_10 -> V_169 != V_423 ) &&
( F_138 ( V_10 -> V_75 + V_10 -> V_169 * V_3 , V_521 ) ) )
V_521 = V_10 -> V_75 + V_10 -> V_169 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
if ( V_526 ) {
F_18 ( V_10 ) ;
F_152 ( 0 , V_10 ) ;
F_149 ( V_10 ) ;
goto V_485;
}
} else if ( ( V_10 -> V_55 & V_189 ) &&
! ( V_10 -> V_55 & V_146 ) ) {
unsigned long V_215 = V_10 -> V_5 -> V_39 . V_223 *
V_10 -> V_5 -> V_39 . V_229 *
F_157 ( V_10 -> V_5 -> V_48 , V_230 ) / V_3 ;
if ( V_214 >= V_10 -> V_170 - V_215 ) {
struct V_9 * V_206 = V_10 -> V_206 ;
if ( F_138 ( V_10 -> V_75 + V_10 -> V_170 * V_3 , V_521 ) )
V_521 = V_10 -> V_75 + V_10 -> V_170 * V_3 ;
if ( ! V_10 -> V_222 && V_206 ) {
V_10 -> V_222 ++ ;
F_18 ( V_10 ) ;
F_18 ( V_206 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_119 ( & V_206 -> V_36 ) ;
V_206 -> V_222 = 0 ;
F_128 ( & V_206 -> V_36 ) ;
F_154 ( V_206 , V_10 ) ;
F_149 ( V_206 ) ;
F_149 ( V_10 ) ;
goto V_485;
}
} else if ( F_138 ( V_10 -> V_75 + V_10 -> V_170 * V_3 - V_215 * V_3 , V_521 ) )
V_521 = V_10 -> V_75 + V_10 -> V_170 * V_3 - V_215 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
} else {
if ( F_138 ( V_10 -> V_75 + V_10 -> V_170 * V_3 , V_521 ) )
V_521 = V_10 -> V_75 + V_10 -> V_170 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
}
}
}
V_522 = F_344 ( V_521 ) ;
V_523 = V_521 ;
if ( F_138 ( V_522 , V_521 + V_527 ) )
V_523 = V_522 ;
if ( F_138 ( V_523 , V_13 + V_528 ) )
V_523 = V_13 + V_528 ;
F_38 ( V_529 L_29 ,
V_219 , V_521 , V_522 , V_523 ) ;
F_19 ( V_15 , & V_525 , V_523 - V_219 ) ;
F_132 () ;
}
static void F_345 ( struct V_498 * V_499 )
{
F_256 () ;
F_268 () ;
F_95 () ;
}
static void F_253 ( void )
{
F_19 ( V_15 , & V_525 , 0 ) ;
}
static struct V_164 * F_346 ( struct V_118 * V_162 , struct V_118 * V_530 ,
struct V_164 * * V_413 )
{
struct V_164 * V_328 = NULL ;
* V_413 = NULL ;
if ( V_162 )
V_328 = F_347 ( V_162 ) ;
if ( V_530 ) {
if ( V_328 && F_348 ( V_530 , V_328 , sizeof( * V_328 ) ) )
* V_413 = V_328 ;
V_328 = F_347 ( V_530 ) ;
}
return V_328 ;
}
static int
F_349 ( struct V_91 * V_92 , struct V_99 * V_100 )
{
struct V_110 * V_110 = F_72 ( V_92 -> V_117 ) ;
struct V_531 * V_532 ;
struct V_118 * V_119 [ V_533 + 1 ] ;
struct V_164 * V_328 , * V_413 ;
T_1 V_414 ;
int V_32 ;
V_32 = F_73 ( V_100 , sizeof( * V_532 ) , V_119 , V_533 , V_534 ) ;
if ( V_32 < 0 )
return V_32 ;
V_532 = F_61 ( V_100 ) ;
V_328 = F_346 ( V_119 [ V_535 ] , V_119 [ V_536 ] , & V_413 ) ;
if ( ! V_328 )
return - V_35 ;
V_414 = V_119 [ V_537 ] ? F_350 ( V_119 [ V_537 ] ) : V_532 -> V_414 ;
V_414 &= V_379 ;
return F_269 ( V_110 , V_532 -> V_538 , V_414 , V_328 ,
V_532 -> V_539 ) ;
}
static int F_351 ( struct V_9 * V_10 , T_1 V_414 ,
T_1 V_170 , T_1 V_169 )
{
T_1 V_55 ;
T_5 V_193 ;
unsigned long V_415 ;
bool V_540 ;
bool V_541 ;
F_29 () ;
if ( ! V_169 || ( V_170 > V_169 ) )
return - V_35 ;
if ( V_414 & V_379 &&
( V_10 -> V_55 & V_189 || V_10 -> V_186 != 64 ) )
return - V_35 ;
V_415 = F_137 ( V_169 , V_3 ) ;
if ( F_248 ( V_415 ) ) {
V_193 = F_250 ( V_415 * V_3 ) ;
V_169 = V_415 ;
V_55 = V_205 ;
} else {
V_193 = 0 ;
V_55 = 0 ;
V_414 |= V_197 ;
}
V_415 = F_137 ( V_170 , V_3 ) ;
if ( F_248 ( V_415 ) ) {
if ( V_415 == 0 )
V_414 |= V_251 ;
V_170 = V_415 ;
}
F_144 ( & V_10 -> V_36 ) ;
V_540 = V_10 -> V_55 & V_379 ;
V_541 = V_10 -> V_55 & V_197 &&
! ( V_10 -> V_55 & V_198 ) ;
V_10 -> V_55 &= ~ ( V_251 | V_197 | V_488 |
V_256 | V_379 |
V_198 ) ;
V_10 -> V_55 |= V_414 ;
V_10 -> V_75 = V_13 ;
V_10 -> V_169 = V_169 ;
V_10 -> V_170 = V_170 ;
F_145 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_55 & V_146 ) )
F_152 ( 0 , V_10 ) ;
if ( ! ( V_414 & V_198 ) ) {
F_232 ( & V_10 -> V_162 , V_10 -> V_186 , V_10 -> V_5 -> V_7 ,
V_193 , V_55 ) ;
} else if ( V_541 ) {
enum V_192 V_195 ;
unsigned long V_371 ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
V_195 = F_135 ( V_10 , & V_371 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_195 != V_199 ) {
F_139 ( V_10 , V_371 ,
V_195 == V_196 ) ;
}
}
if ( V_540 || V_10 -> V_55 & V_379 ) {
if ( V_540 && ! ( V_10 -> V_55 & V_379 ) )
V_169 = V_170 = 0 ;
F_241 ( V_10 -> V_5 , V_10 , V_169 , V_170 ,
! V_540 , V_13 ) ;
}
F_268 () ;
return 0 ;
}
static int
F_352 ( struct V_91 * V_92 , struct V_99 * V_100 )
{
struct V_110 * V_110 = F_72 ( V_92 -> V_117 ) ;
struct V_531 * V_532 ;
struct V_118 * V_119 [ V_533 + 1 ] ;
struct V_164 * V_328 , * V_413 ;
struct V_9 * V_143 ;
struct V_6 * V_7 ;
T_1 V_169 = V_423 , V_295 = V_423 ;
T_1 V_414 ;
int V_32 ;
V_32 = F_73 ( V_100 , sizeof( * V_532 ) , V_119 , V_533 , V_534 ) ;
if ( V_32 < 0 )
return V_32 ;
V_532 = F_61 ( V_100 ) ;
V_328 = F_346 ( V_119 [ V_535 ] , V_119 [ V_536 ] , & V_413 ) ;
if ( ! V_328 )
return - V_35 ;
if ( V_119 [ V_542 ] ) {
struct V_543 * V_544 ;
V_544 = F_347 ( V_119 [ V_542 ] ) ;
V_169 = V_544 -> V_545 ;
V_295 = V_544 -> V_546 ;
} else {
V_295 = V_423 ;
V_169 = V_423 ;
}
V_7 = F_75 ( V_110 , V_532 -> V_538 ) ;
if ( ! V_7 )
return - V_178 ;
V_414 = V_119 [ V_537 ] ? F_350 ( V_119 [ V_537 ] ) : V_532 -> V_414 ;
V_414 &= V_488 | V_256 | V_379 |
V_198 | V_416 ;
V_143 = F_192 ( V_110 , V_328 , V_7 , 1 ) ;
if ( ! V_143 ) {
return F_267 ( V_110 , V_532 -> V_538 , V_328 , V_413 ,
V_532 -> V_539 , V_414 ,
V_295 , V_169 ) ;
}
if ( V_100 -> V_547 & V_548 ||
! ( V_100 -> V_547 & V_549 ) )
V_32 = - V_183 ;
else
V_32 = F_351 ( V_143 , V_414 , V_295 , V_169 ) ;
F_149 ( V_143 ) ;
return V_32 ;
}
static void F_353 ( struct V_99 * V_100 , T_3 V_550 , T_1 V_55 ,
T_3 V_168 , int V_93 )
{
struct V_531 * V_532 ;
V_532 = F_61 ( V_100 ) ;
V_532 -> V_551 = V_104 ;
V_532 -> V_539 = V_550 ;
V_532 -> V_414 = V_55 ;
V_532 -> V_433 = V_168 ;
V_532 -> V_538 = V_93 ;
}
static int F_354 ( struct V_91 * V_92 , unsigned long V_1 ,
unsigned long V_75 , T_1 V_552 , T_1 V_369 )
{
struct V_543 V_544 ;
V_544 . V_1 = F_1 ( V_1 ) ;
V_544 . V_75 = F_1 ( V_75 ) ;
V_544 . V_546 = V_552 ;
V_544 . V_545 = V_369 ;
return F_355 ( V_92 , V_542 , sizeof( V_544 ) , & V_544 ) ;
}
static inline int F_356 ( int V_433 )
{
if ( V_433 & V_284 )
return V_435 ;
else if ( V_433 & V_280 )
return V_434 ;
else if ( V_433 & V_553 )
return V_554 ;
else
return V_555 ;
}
static inline int F_357 ( void )
{
return F_56 ( sizeof( struct V_531 ) )
+ F_57 ( 16 )
+ F_57 ( 16 )
+ F_57 ( sizeof( struct V_543 ) )
+ F_57 ( 4 ) ;
}
static int F_358 ( struct V_91 * V_92 , struct V_9 * V_143 ,
T_1 V_96 , T_1 V_97 , int V_98 , unsigned int V_55 )
{
struct V_99 * V_100 ;
T_1 V_552 , V_369 ;
V_100 = F_60 ( V_92 , V_96 , V_97 , V_98 , sizeof( struct V_531 ) , V_55 ) ;
if ( ! V_100 )
return - V_102 ;
F_353 ( V_100 , V_143 -> V_186 , V_143 -> V_55 , F_356 ( V_143 -> V_168 ) ,
V_143 -> V_5 -> V_7 -> V_93 ) ;
if ( ! ( ( V_143 -> V_55 & V_197 ) &&
( V_143 -> V_170 == V_423 ) ) ) {
V_552 = V_143 -> V_170 ;
V_369 = V_143 -> V_169 ;
if ( V_552 != V_423 ) {
long V_556 = ( V_13 - V_143 -> V_75 ) / V_3 ;
if ( V_552 > V_556 )
V_552 -= V_556 ;
else
V_552 = 0 ;
if ( V_369 != V_423 ) {
if ( V_369 > V_556 )
V_369 -= V_556 ;
else
V_369 = 0 ;
}
}
} else {
V_552 = V_423 ;
V_369 = V_423 ;
}
if ( ! F_206 ( & V_143 -> V_166 ) ) {
if ( F_359 ( V_92 , V_536 , & V_143 -> V_162 ) < 0 ||
F_359 ( V_92 , V_535 , & V_143 -> V_166 ) < 0 )
goto error;
} else
if ( F_359 ( V_92 , V_535 , & V_143 -> V_162 ) < 0 )
goto error;
if ( F_354 ( V_92 , V_143 -> V_1 , V_143 -> V_75 , V_552 , V_369 ) < 0 )
goto error;
if ( F_360 ( V_92 , V_537 , V_143 -> V_55 ) < 0 )
goto error;
F_63 ( V_92 , V_100 ) ;
return 0 ;
error:
F_64 ( V_92 , V_100 ) ;
return - V_102 ;
}
static int F_361 ( struct V_91 * V_92 , struct V_557 * V_558 ,
T_1 V_96 , T_1 V_97 , int V_98 , T_13 V_55 )
{
struct V_99 * V_100 ;
T_3 V_168 = V_555 ;
int V_93 = V_558 -> V_5 -> V_7 -> V_93 ;
if ( F_158 ( & V_558 -> V_559 ) & V_553 )
V_168 = V_554 ;
V_100 = F_60 ( V_92 , V_96 , V_97 , V_98 , sizeof( struct V_531 ) , V_55 ) ;
if ( ! V_100 )
return - V_102 ;
F_353 ( V_100 , 128 , V_197 , V_168 , V_93 ) ;
if ( F_359 ( V_92 , V_560 , & V_558 -> V_559 ) < 0 ||
F_354 ( V_92 , V_558 -> V_561 , V_558 -> V_562 ,
V_423 , V_423 ) < 0 ) {
F_64 ( V_92 , V_100 ) ;
return - V_102 ;
}
F_63 ( V_92 , V_100 ) ;
return 0 ;
}
static int F_362 ( struct V_91 * V_92 , struct V_563 * V_564 ,
T_1 V_96 , T_1 V_97 , int V_98 , unsigned int V_55 )
{
struct V_99 * V_100 ;
T_3 V_168 = V_555 ;
int V_93 = V_564 -> V_565 -> V_7 -> V_93 ;
if ( F_158 ( & V_564 -> V_566 ) & V_553 )
V_168 = V_554 ;
V_100 = F_60 ( V_92 , V_96 , V_97 , V_98 , sizeof( struct V_531 ) , V_55 ) ;
if ( ! V_100 )
return - V_102 ;
F_353 ( V_100 , 128 , V_197 , V_168 , V_93 ) ;
if ( F_359 ( V_92 , V_567 , & V_564 -> V_566 ) < 0 ||
F_354 ( V_92 , V_564 -> V_568 , V_564 -> V_569 ,
V_423 , V_423 ) < 0 ) {
F_64 ( V_92 , V_100 ) ;
return - V_102 ;
}
F_63 ( V_92 , V_100 ) ;
return 0 ;
}
static int F_363 ( struct V_4 * V_5 , struct V_91 * V_92 ,
struct V_127 * V_128 , enum V_570 type ,
int V_571 , int * V_572 )
{
struct V_557 * V_558 ;
struct V_563 * V_564 ;
int V_32 = 1 ;
int V_573 = * V_572 ;
F_173 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_574 : {
struct V_9 * V_143 ;
F_87 (ifa, &idev->addr_list, if_list) {
if ( ++ V_573 < V_571 )
continue;
V_32 = F_358 ( V_92 , V_143 ,
F_76 ( V_128 -> V_92 ) . V_96 ,
V_128 -> V_100 -> V_126 ,
V_424 ,
V_140 ) ;
if ( V_32 < 0 )
break;
F_83 ( V_128 , F_84 ( V_92 ) ) ;
}
break;
}
case V_575 :
for ( V_558 = V_5 -> V_576 ; V_558 ;
V_558 = V_558 -> V_521 , V_573 ++ ) {
if ( V_573 < V_571 )
continue;
V_32 = F_361 ( V_92 , V_558 ,
F_76 ( V_128 -> V_92 ) . V_96 ,
V_128 -> V_100 -> V_126 ,
V_577 ,
V_140 ) ;
if ( V_32 < 0 )
break;
}
break;
case V_578 :
for ( V_564 = V_5 -> V_579 ; V_564 ;
V_564 = V_564 -> V_580 , V_573 ++ ) {
if ( V_573 < V_571 )
continue;
V_32 = F_362 ( V_92 , V_564 ,
F_76 ( V_128 -> V_92 ) . V_96 ,
V_128 -> V_100 -> V_126 ,
V_581 ,
V_140 ) ;
if ( V_32 < 0 )
break;
}
break;
default:
break;
}
F_179 ( & V_5 -> V_36 ) ;
* V_572 = V_573 ;
return V_32 ;
}
static int F_364 ( struct V_91 * V_92 , struct V_127 * V_128 ,
enum V_570 type )
{
struct V_110 * V_110 = F_72 ( V_92 -> V_117 ) ;
int V_129 , V_130 ;
int V_131 , V_573 ;
int V_132 , V_571 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_133 * V_134 ;
V_130 = V_128 -> args [ 0 ] ;
V_132 = V_131 = V_128 -> args [ 1 ] ;
V_571 = V_573 = V_128 -> args [ 2 ] ;
F_79 () ;
V_128 -> V_97 = F_80 ( & V_110 -> V_18 . V_137 ) ^ V_110 -> V_138 ;
for ( V_129 = V_130 ; V_129 < V_135 ; V_129 ++ , V_132 = 0 ) {
V_131 = 0 ;
V_134 = & V_110 -> V_136 [ V_129 ] ;
F_81 (dev, head, index_hlist) {
if ( V_131 < V_132 )
goto V_139;
if ( V_129 > V_130 || V_131 > V_132 )
V_571 = 0 ;
V_573 = 0 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_139;
if ( F_363 ( V_5 , V_92 , V_128 , type ,
V_571 , & V_573 ) < 0 )
goto V_141;
V_139:
V_131 ++ ;
}
}
V_141:
F_82 () ;
V_128 -> args [ 0 ] = V_129 ;
V_128 -> args [ 1 ] = V_131 ;
V_128 -> args [ 2 ] = V_573 ;
return V_92 -> V_142 ;
}
static int F_365 ( struct V_91 * V_92 , struct V_127 * V_128 )
{
enum V_570 type = V_574 ;
return F_364 ( V_92 , V_128 , type ) ;
}
static int F_366 ( struct V_91 * V_92 , struct V_127 * V_128 )
{
enum V_570 type = V_575 ;
return F_364 ( V_92 , V_128 , type ) ;
}
static int F_367 ( struct V_91 * V_92 , struct V_127 * V_128 )
{
enum V_570 type = V_578 ;
return F_364 ( V_92 , V_128 , type ) ;
}
static int F_368 ( struct V_91 * V_116 , struct V_99 * V_100 )
{
struct V_110 * V_110 = F_72 ( V_116 -> V_117 ) ;
struct V_531 * V_532 ;
struct V_118 * V_119 [ V_533 + 1 ] ;
struct V_164 * V_162 = NULL , * V_582 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_143 ;
struct V_91 * V_92 ;
int V_32 ;
V_32 = F_73 ( V_100 , sizeof( * V_532 ) , V_119 , V_533 , V_534 ) ;
if ( V_32 < 0 )
goto V_113;
V_162 = F_346 ( V_119 [ V_535 ] , V_119 [ V_536 ] , & V_582 ) ;
if ( ! V_162 ) {
V_32 = - V_35 ;
goto V_113;
}
V_532 = F_61 ( V_100 ) ;
if ( V_532 -> V_538 )
V_7 = F_75 ( V_110 , V_532 -> V_538 ) ;
V_143 = F_192 ( V_110 , V_162 , V_7 , 1 ) ;
if ( ! V_143 ) {
V_32 = - V_177 ;
goto V_113;
}
V_92 = F_66 ( F_357 () , V_25 ) ;
if ( ! V_92 ) {
V_32 = - V_111 ;
goto V_583;
}
V_32 = F_358 ( V_92 , V_143 , F_76 ( V_116 ) . V_96 ,
V_100 -> V_126 , V_424 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_102 ) ;
F_68 ( V_92 ) ;
goto V_583;
}
V_32 = F_77 ( V_92 , V_110 , F_76 ( V_116 ) . V_96 ) ;
V_583:
F_149 ( V_143 ) ;
V_113:
return V_32 ;
}
static void F_369 ( int V_98 , struct V_9 * V_143 )
{
struct V_91 * V_92 ;
struct V_110 * V_110 = F_34 ( V_143 -> V_5 -> V_7 ) ;
int V_32 = - V_111 ;
V_92 = F_66 ( F_357 () , V_112 ) ;
if ( ! V_92 )
goto V_113;
V_32 = F_358 ( V_92 , V_143 , 0 , 0 , V_98 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_102 ) ;
F_68 ( V_92 ) ;
goto V_113;
}
F_69 ( V_92 , V_110 , 0 , V_584 , NULL , V_112 ) ;
return;
V_113:
if ( V_32 < 0 )
F_70 ( V_110 , V_584 , V_32 ) ;
}
static inline void F_370 ( struct V_94 * V_39 ,
T_2 * V_585 , int V_586 )
{
F_371 ( V_586 < ( V_587 * 4 ) ) ;
memset ( V_585 , 0 , V_586 ) ;
V_585 [ V_588 ] = V_39 -> V_50 ;
V_585 [ V_589 ] = V_39 -> V_590 ;
V_585 [ V_591 ] = V_39 -> V_46 ;
V_585 [ V_592 ] = V_39 -> V_593 ;
V_585 [ V_594 ] = V_39 -> V_595 ;
V_585 [ V_596 ] = V_39 -> V_375 ;
V_585 [ V_597 ] = V_39 -> V_229 ;
V_585 [ V_598 ] = V_39 -> V_63 ;
V_585 [ V_599 ] =
F_372 ( V_39 -> V_493 ) ;
V_585 [ V_600 ] =
F_372 ( V_39 -> V_492 ) ;
V_585 [ V_601 ] = V_39 -> V_602 ;
V_585 [ V_603 ] =
F_372 ( V_39 -> V_604 ) ;
V_585 [ V_605 ] =
F_372 ( V_39 -> V_606 ) ;
V_585 [ V_607 ] = V_39 -> V_70 ;
V_585 [ V_608 ] = V_39 -> V_226 ;
V_585 [ V_609 ] = V_39 -> V_227 ;
V_585 [ V_610 ] = V_39 -> V_223 ;
V_585 [ V_611 ] = V_39 -> V_228 ;
V_585 [ V_612 ] = V_39 -> V_300 ;
V_585 [ V_613 ] = V_39 -> V_614 ;
V_585 [ V_615 ] = V_39 -> V_616 ;
V_585 [ V_617 ] = V_39 -> V_618 ;
#ifdef F_373
V_585 [ V_619 ] = V_39 -> V_620 ;
V_585 [ V_621 ] =
F_372 ( V_39 -> V_622 ) ;
#ifdef F_374
V_585 [ V_623 ] = V_39 -> V_624 ;
#endif
#endif
V_585 [ V_625 ] = V_39 -> V_108 ;
V_585 [ V_626 ] = V_39 -> V_627 ;
#ifdef F_162
V_585 [ V_628 ] = V_39 -> V_235 ;
V_585 [ V_629 ] = V_39 -> V_236 ;
#endif
#ifdef F_58
V_585 [ V_630 ] = V_39 -> V_107 ;
#endif
V_585 [ V_631 ] = V_39 -> V_180 ;
V_585 [ V_632 ] = V_39 -> V_58 ;
V_585 [ V_633 ] = V_39 -> V_634 ;
V_585 [ V_635 ] = V_39 -> V_636 ;
V_585 [ V_637 ] = V_39 -> V_638 ;
V_585 [ V_639 ] = V_39 -> V_640 ;
V_585 [ V_641 ] = V_39 -> V_642 ;
V_585 [ V_643 ] = V_39 -> V_109 ;
V_585 [ V_644 ] = V_39 -> V_278 ;
V_585 [ V_645 ] = V_39 -> V_646 ;
V_585 [ V_647 ] = V_39 -> V_648 ;
V_585 [ V_649 ] = V_39 -> V_483 ;
}
static inline T_14 F_375 ( void )
{
return F_57 ( 4 )
+ F_57 ( sizeof( struct V_650 ) )
+ F_57 ( V_587 * 4 )
+ F_57 ( V_651 * 8 )
+ F_57 ( V_652 * 8 )
+ F_57 ( sizeof( struct V_164 ) ) ;
}
static inline T_14 F_376 ( void )
{
return F_56 ( sizeof( struct V_653 ) )
+ F_57 ( V_654 )
+ F_57 ( V_451 )
+ F_57 ( 4 )
+ F_57 ( 4 )
+ F_57 ( 1 )
+ F_57 ( F_375 () ) ;
}
static inline void F_377 ( T_15 * V_17 , T_16 * V_655 ,
int V_656 , int V_586 )
{
int V_16 ;
int V_657 = V_586 - sizeof( T_15 ) * V_656 ;
F_371 ( V_657 < 0 ) ;
F_378 ( V_656 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_656 ; V_16 ++ )
F_378 ( F_379 ( & V_655 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_656 ] , 0 , V_657 ) ;
}
static inline void F_380 ( T_15 * V_17 , void T_17 * V_655 ,
int V_586 , T_14 V_658 )
{
int V_16 , V_659 ;
T_15 V_660 [ V_651 ] ;
int V_657 = V_586 - sizeof( T_15 ) * V_651 ;
F_371 ( V_657 < 0 ) ;
memset ( V_660 , 0 , sizeof( V_660 ) ) ;
V_660 [ 0 ] = V_651 ;
F_22 (c) {
for ( V_16 = 1 ; V_16 < V_651 ; V_16 ++ )
V_660 [ V_16 ] += F_381 ( V_655 , V_659 , V_16 , V_658 ) ;
}
memcpy ( V_17 , V_660 , V_651 * sizeof( T_15 ) ) ;
memset ( & V_17 [ V_651 ] , 0 , V_657 ) ;
}
static void F_382 ( T_15 * V_17 , struct V_4 * V_5 , int V_661 ,
int V_586 )
{
switch ( V_661 ) {
case V_662 :
F_380 ( V_17 , V_5 -> V_17 . V_18 , V_586 ,
F_383 ( struct V_19 , V_22 ) ) ;
break;
case V_663 :
F_377 ( V_17 , V_5 -> V_17 . V_23 -> V_664 , V_652 , V_586 ) ;
break;
}
}
static int F_384 ( struct V_91 * V_92 , struct V_4 * V_5 ,
T_1 V_665 )
{
struct V_118 * V_666 ;
struct V_650 V_544 ;
if ( F_360 ( V_92 , V_667 , V_5 -> V_73 ) )
goto V_106;
V_544 . V_668 = V_669 ;
V_544 . V_75 = F_1 ( V_5 -> V_75 ) ;
V_544 . V_670 = F_372 ( V_5 -> V_48 -> V_670 ) ;
V_544 . V_671 = F_372 ( F_157 ( V_5 -> V_48 , V_230 ) ) ;
if ( F_355 ( V_92 , V_672 , sizeof( V_544 ) , & V_544 ) )
goto V_106;
V_666 = F_385 ( V_92 , V_673 , V_587 * sizeof( V_674 ) ) ;
if ( ! V_666 )
goto V_106;
F_370 ( & V_5 -> V_39 , F_347 ( V_666 ) , F_386 ( V_666 ) ) ;
if ( V_665 & V_675 )
return 0 ;
V_666 = F_385 ( V_92 , V_662 , V_651 * sizeof( T_15 ) ) ;
if ( ! V_666 )
goto V_106;
F_382 ( F_347 ( V_666 ) , V_5 , V_662 , F_386 ( V_666 ) ) ;
V_666 = F_385 ( V_92 , V_663 , V_652 * sizeof( T_15 ) ) ;
if ( ! V_666 )
goto V_106;
F_382 ( F_347 ( V_666 ) , V_5 , V_663 , F_386 ( V_666 ) ) ;
V_666 = F_385 ( V_92 , V_676 , sizeof( struct V_164 ) ) ;
if ( ! V_666 )
goto V_106;
if ( F_387 ( V_92 , V_677 , V_5 -> V_43 ) )
goto V_106;
F_173 ( & V_5 -> V_36 ) ;
memcpy ( F_347 ( V_666 ) , V_5 -> V_71 . V_220 , F_386 ( V_666 ) ) ;
F_179 ( & V_5 -> V_36 ) ;
return 0 ;
V_106:
return - V_102 ;
}
static T_14 F_388 ( const struct V_6 * V_7 ,
T_1 V_665 )
{
if ( ! F_52 ( V_7 ) )
return 0 ;
return F_375 () ;
}
static int F_389 ( struct V_91 * V_92 , const struct V_6 * V_7 ,
T_1 V_665 )
{
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_678 ;
if ( F_384 ( V_92 , V_5 , V_665 ) < 0 )
return - V_102 ;
return 0 ;
}
static int F_390 ( struct V_4 * V_5 , struct V_164 * V_71 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_679 = false ;
struct V_164 V_680 ;
F_29 () ;
if ( ! V_71 )
return - V_35 ;
if ( F_206 ( V_71 ) )
return - V_35 ;
if ( V_7 -> V_55 & ( V_57 | V_56 ) )
return - V_35 ;
if ( ! F_312 ( V_5 ) )
return - V_35 ;
if ( V_5 -> V_39 . V_63 <= 0 )
return - V_35 ;
F_147 ( & V_5 -> V_36 ) ;
F_282 ( sizeof( V_71 -> V_220 ) != 16 ) ;
memcpy ( V_5 -> V_71 . V_220 + 8 , V_71 -> V_220 + 8 , 8 ) ;
F_151 ( & V_5 -> V_36 ) ;
if ( ! V_5 -> V_81 && ( V_5 -> V_73 & V_74 ) &&
! F_184 ( V_7 , & V_680 , V_146 |
V_232 ) ) {
F_313 ( V_7 , & V_680 , & V_80 ) ;
V_679 = true ;
}
F_147 ( & V_5 -> V_36 ) ;
if ( V_679 ) {
V_5 -> V_73 |= V_486 ;
V_5 -> V_490 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_493 ) ;
}
F_87 (ifp, &idev->addr_list, if_list) {
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_187 ) {
V_10 -> V_169 = 0 ;
V_10 -> V_170 = 0 ;
}
F_128 ( & V_10 -> V_36 ) ;
}
F_151 ( & V_5 -> V_36 ) ;
F_300 ( V_471 , V_5 ) ;
F_268 () ;
return 0 ;
}
static int F_391 ( const struct V_6 * V_7 ,
const struct V_118 * V_666 )
{
struct V_118 * V_119 [ V_681 + 1 ] ;
if ( V_7 && ! F_52 ( V_7 ) )
return - V_682 ;
return F_392 ( V_119 , V_681 , V_666 , V_683 ) ;
}
static int F_393 ( struct V_6 * V_7 , const struct V_118 * V_666 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
struct V_118 * V_119 [ V_681 + 1 ] ;
if ( ! V_5 )
return - V_682 ;
if ( F_392 ( V_119 , V_681 , V_666 , NULL ) < 0 )
F_394 () ;
if ( V_119 [ V_676 ] ) {
V_32 = F_390 ( V_5 , F_347 ( V_119 [ V_676 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_119 [ V_677 ] ) {
T_3 V_684 = F_395 ( V_119 [ V_677 ] ) ;
if ( V_684 != V_45 &&
V_684 != V_457 &&
V_684 != V_44 &&
V_684 != V_362 )
return - V_35 ;
if ( V_684 == V_44 &&
! V_5 -> V_39 . V_41 . V_42 &&
! F_34 ( V_7 ) -> V_18 . V_40 -> V_41 . V_42 )
return - V_35 ;
V_5 -> V_43 = V_684 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_396 ( struct V_91 * V_92 , struct V_4 * V_5 ,
T_1 V_96 , T_1 V_97 , int V_98 , unsigned int V_55 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_653 * V_685 ;
struct V_99 * V_100 ;
void * V_686 ;
V_100 = F_60 ( V_92 , V_96 , V_97 , V_98 , sizeof( * V_685 ) , V_55 ) ;
if ( ! V_100 )
return - V_102 ;
V_685 = F_61 ( V_100 ) ;
V_685 -> V_687 = V_104 ;
V_685 -> V_688 = 0 ;
V_685 -> V_689 = V_7 -> type ;
V_685 -> V_690 = V_7 -> V_93 ;
V_685 -> V_691 = F_397 ( V_7 ) ;
V_685 -> V_692 = 0 ;
if ( F_398 ( V_92 , V_693 , V_7 -> V_53 ) ||
( V_7 -> V_308 &&
F_355 ( V_92 , V_694 , V_7 -> V_308 , V_7 -> V_310 ) ) ||
F_360 ( V_92 , V_695 , V_7 -> V_33 ) ||
( V_7 -> V_93 != F_399 ( V_7 ) &&
F_360 ( V_92 , V_696 , F_399 ( V_7 ) ) ) ||
F_387 ( V_92 , V_697 ,
F_44 ( V_7 ) ? V_7 -> V_698 : V_699 ) )
goto V_106;
V_686 = F_400 ( V_92 , V_700 ) ;
if ( ! V_686 )
goto V_106;
if ( F_384 ( V_92 , V_5 , 0 ) < 0 )
goto V_106;
F_401 ( V_92 , V_686 ) ;
F_63 ( V_92 , V_100 ) ;
return 0 ;
V_106:
F_64 ( V_92 , V_100 ) ;
return - V_102 ;
}
static int F_402 ( struct V_91 * V_92 , struct V_127 * V_128 )
{
struct V_110 * V_110 = F_72 ( V_92 -> V_117 ) ;
int V_129 , V_130 ;
int V_131 = 0 , V_132 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_133 * V_134 ;
V_130 = V_128 -> args [ 0 ] ;
V_132 = V_128 -> args [ 1 ] ;
F_79 () ;
for ( V_129 = V_130 ; V_129 < V_135 ; V_129 ++ , V_132 = 0 ) {
V_131 = 0 ;
V_134 = & V_110 -> V_136 [ V_129 ] ;
F_81 (dev, head, index_hlist) {
if ( V_131 < V_132 )
goto V_139;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_139;
if ( F_396 ( V_92 , V_5 ,
F_76 ( V_128 -> V_92 ) . V_96 ,
V_128 -> V_100 -> V_126 ,
V_471 , V_140 ) < 0 )
goto V_184;
V_139:
V_131 ++ ;
}
}
V_184:
F_82 () ;
V_128 -> args [ 1 ] = V_131 ;
V_128 -> args [ 0 ] = V_129 ;
return V_92 -> V_142 ;
}
void F_300 ( int V_98 , struct V_4 * V_5 )
{
struct V_91 * V_92 ;
struct V_110 * V_110 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_111 ;
V_92 = F_66 ( F_376 () , V_112 ) ;
if ( ! V_92 )
goto V_113;
V_32 = F_396 ( V_92 , V_5 , 0 , 0 , V_98 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_102 ) ;
F_68 ( V_92 ) ;
goto V_113;
}
F_69 ( V_92 , V_110 , 0 , V_701 , NULL , V_112 ) ;
return;
V_113:
if ( V_32 < 0 )
F_70 ( V_110 , V_701 , V_32 ) ;
}
static inline T_14 F_403 ( void )
{
return F_56 ( sizeof( struct V_702 ) )
+ F_57 ( sizeof( struct V_164 ) )
+ F_57 ( sizeof( struct V_703 ) ) ;
}
static int F_404 ( struct V_91 * V_92 , struct V_4 * V_5 ,
struct V_365 * V_366 , T_1 V_96 , T_1 V_97 ,
int V_98 , unsigned int V_55 )
{
struct V_702 * V_704 ;
struct V_99 * V_100 ;
struct V_703 V_544 ;
V_100 = F_60 ( V_92 , V_96 , V_97 , V_98 , sizeof( * V_704 ) , V_55 ) ;
if ( ! V_100 )
return - V_102 ;
V_704 = F_61 ( V_100 ) ;
V_704 -> V_705 = V_104 ;
V_704 -> V_706 = 0 ;
V_704 -> V_707 = 0 ;
V_704 -> V_708 = V_5 -> V_7 -> V_93 ;
V_704 -> V_186 = V_366 -> V_186 ;
V_704 -> V_709 = V_366 -> type ;
V_704 -> V_710 = 0 ;
V_704 -> V_711 = 0 ;
if ( V_366 -> V_285 )
V_704 -> V_711 |= V_712 ;
if ( V_366 -> V_375 )
V_704 -> V_711 |= V_713 ;
if ( F_355 ( V_92 , V_714 , sizeof( V_366 -> V_367 ) , & V_366 -> V_367 ) )
goto V_106;
V_544 . V_715 = F_245 ( V_366 -> V_370 ) ;
V_544 . V_716 = F_245 ( V_366 -> V_369 ) ;
if ( F_355 ( V_92 , V_717 , sizeof( V_544 ) , & V_544 ) )
goto V_106;
F_63 ( V_92 , V_100 ) ;
return 0 ;
V_106:
F_64 ( V_92 , V_100 ) ;
return - V_102 ;
}
static void F_254 ( int V_98 , struct V_4 * V_5 ,
struct V_365 * V_366 )
{
struct V_91 * V_92 ;
struct V_110 * V_110 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_111 ;
V_92 = F_66 ( F_403 () , V_112 ) ;
if ( ! V_92 )
goto V_113;
V_32 = F_404 ( V_92 , V_5 , V_366 , 0 , 0 , V_98 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_102 ) ;
F_68 ( V_92 ) ;
goto V_113;
}
F_69 ( V_92 , V_110 , 0 , V_718 , NULL , V_112 ) ;
return;
V_113:
if ( V_32 < 0 )
F_70 ( V_110 , V_718 , V_32 ) ;
}
static void F_309 ( int V_98 , struct V_9 * V_10 )
{
struct V_110 * V_110 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_98 )
F_29 () ;
F_369 ( V_98 ? : V_424 , V_10 ) ;
switch ( V_98 ) {
case V_424 :
if ( ! ( V_10 -> V_158 -> V_719 ) )
F_278 ( V_10 -> V_158 ) ;
if ( V_10 -> V_5 -> V_39 . V_50 )
F_88 ( V_10 ) ;
if ( ! F_206 ( & V_10 -> V_166 ) )
F_232 ( & V_10 -> V_166 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_207 :
if ( V_10 -> V_5 -> V_39 . V_50 )
F_89 ( V_10 ) ;
F_203 ( V_10 -> V_5 , & V_10 -> V_162 ) ;
if ( ! F_206 ( & V_10 -> V_166 ) ) {
struct V_171 * V_158 ;
V_158 = F_140 ( & V_10 -> V_166 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
if ( V_158 )
F_141 ( V_158 ) ;
}
if ( V_10 -> V_158 ) {
F_237 ( & V_10 -> V_158 -> V_240 ) ;
F_141 ( V_10 -> V_158 ) ;
}
F_405 ( V_110 ) ;
break;
}
F_406 ( & V_110 -> V_18 . V_137 ) ;
}
static void F_152 ( int V_98 , struct V_9 * V_10 )
{
F_118 () ;
if ( F_133 ( V_10 -> V_5 -> V_81 == 0 ) )
F_309 ( V_98 , V_10 ) ;
F_132 () ;
}
static
int F_407 ( struct V_149 * V_720 , int V_721 ,
void T_6 * V_722 , T_14 * V_723 , T_8 * V_724 )
{
int * V_725 = V_720 -> V_327 ;
int V_726 = * V_725 ;
T_8 V_508 = * V_724 ;
struct V_149 V_727 ;
int V_217 ;
V_727 = * V_720 ;
V_727 . V_327 = & V_726 ;
V_217 = F_408 ( & V_727 , V_721 , V_722 , V_723 , V_724 ) ;
if ( V_721 )
V_217 = F_92 ( V_720 , V_725 , V_726 ) ;
if ( V_217 )
* V_724 = V_508 ;
return V_217 ;
}
static
int F_409 ( struct V_149 * V_720 , int V_721 ,
void T_6 * V_722 , T_14 * V_723 , T_8 * V_724 )
{
struct V_149 V_727 ;
int V_728 = 1 , V_729 = 255 ;
V_727 = * V_720 ;
V_727 . V_154 = & V_728 ;
V_727 . V_153 = & V_729 ;
return F_410 ( & V_727 , V_721 , V_722 , V_723 , V_724 ) ;
}
static
int F_411 ( struct V_149 * V_720 , int V_721 ,
void T_6 * V_722 , T_14 * V_723 , T_8 * V_724 )
{
struct V_4 * V_5 = V_720 -> V_154 ;
int V_730 = V_34 ;
struct V_149 V_727 ;
V_727 = * V_720 ;
V_727 . V_154 = & V_730 ;
V_727 . V_153 = V_5 ? & V_5 -> V_7 -> V_33 : NULL ;
return F_410 ( & V_727 , V_721 , V_722 , V_723 , V_724 ) ;
}
static void F_412 ( struct V_4 * V_5 )
{
struct V_731 V_463 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_413 ( & V_463 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_180 )
F_294 ( NULL , V_208 , & V_463 ) ;
else
F_294 ( NULL , V_191 , & V_463 ) ;
}
static void F_414 ( struct V_110 * V_110 , T_2 V_147 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_79 () ;
F_181 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_148 = ( ! V_5 -> V_39 . V_180 ) ^ ( ! V_147 ) ;
V_5 -> V_39 . V_180 = V_147 ;
if ( V_148 )
F_412 ( V_5 ) ;
}
}
F_82 () ;
}
static int F_415 ( struct V_149 * V_150 , int * V_151 , int V_147 )
{
struct V_110 * V_110 ;
int V_152 ;
if ( ! F_93 () )
return F_94 () ;
V_110 = (struct V_110 * ) V_150 -> V_153 ;
V_152 = * V_151 ;
* V_151 = V_147 ;
if ( V_151 == & V_110 -> V_18 . V_40 -> V_180 ) {
F_95 () ;
return 0 ;
}
if ( V_151 == & V_110 -> V_18 . V_124 -> V_180 ) {
V_110 -> V_18 . V_40 -> V_180 = V_147 ;
F_414 ( V_110 , V_147 ) ;
} else if ( ( ! V_147 ) ^ ( ! V_152 ) )
F_412 ( (struct V_4 * ) V_150 -> V_154 ) ;
F_95 () ;
return 0 ;
}
static
int F_416 ( struct V_149 * V_720 , int V_721 ,
void T_6 * V_722 , T_14 * V_723 , T_8 * V_724 )
{
int * V_725 = V_720 -> V_327 ;
int V_726 = * V_725 ;
T_8 V_508 = * V_724 ;
struct V_149 V_727 ;
int V_217 ;
V_727 = * V_720 ;
V_727 . V_327 = & V_726 ;
V_217 = F_408 ( & V_727 , V_721 , V_722 , V_723 , V_724 ) ;
if ( V_721 )
V_217 = F_415 ( V_720 , V_725 , V_726 ) ;
if ( V_217 )
* V_724 = V_508 ;
return V_217 ;
}
static
int F_417 ( struct V_149 * V_720 , int V_721 ,
void T_6 * V_722 , T_14 * V_723 , T_8 * V_724 )
{
int * V_725 = V_720 -> V_327 ;
int V_217 ;
int V_152 , V_732 ;
V_152 = * V_725 ;
V_217 = F_408 ( V_720 , V_721 , V_722 , V_723 , V_724 ) ;
V_732 = * V_725 ;
if ( V_721 && V_152 != V_732 ) {
struct V_110 * V_110 = V_720 -> V_153 ;
if ( ! F_93 () )
return F_94 () ;
if ( V_725 == & V_110 -> V_18 . V_40 -> V_108 )
F_65 ( V_110 , V_89 ,
V_125 ,
V_110 -> V_18 . V_40 ) ;
else if ( V_725 == & V_110 -> V_18 . V_124 -> V_108 )
F_65 ( V_110 , V_89 ,
V_123 ,
V_110 -> V_18 . V_124 ) ;
else {
struct V_4 * V_5 = V_720 -> V_154 ;
F_65 ( V_110 , V_89 ,
V_5 -> V_7 -> V_93 ,
& V_5 -> V_39 ) ;
}
F_95 () ;
}
return V_217 ;
}
static int F_418 ( struct V_149 * V_720 , int V_721 ,
void T_6 * V_722 , T_14 * V_723 ,
T_8 * V_724 )
{
int V_32 ;
struct V_164 V_162 ;
char V_733 [ V_734 ] ;
struct V_149 V_727 = * V_720 ;
struct V_110 * V_110 = V_720 -> V_153 ;
struct V_454 * V_449 = V_720 -> V_327 ;
if ( & V_110 -> V_18 . V_124 -> V_41 == V_720 -> V_327 )
return - V_735 ;
V_727 . V_736 = V_734 ;
V_727 . V_327 = V_733 ;
if ( ! F_93 () )
return F_94 () ;
if ( ! V_721 && ! V_449 -> V_42 ) {
V_32 = - V_735 ;
goto V_184;
}
V_32 = snprintf ( V_733 , sizeof( V_733 ) , L_30 , & V_449 -> V_449 ) ;
if ( V_32 >= sizeof( V_733 ) ) {
V_32 = - V_735 ;
goto V_184;
}
V_32 = F_419 ( & V_727 , V_721 , V_722 , V_723 , V_724 ) ;
if ( V_32 || ! V_721 )
goto V_184;
if ( F_420 ( V_733 , - 1 , V_162 . V_737 . V_738 , - 1 , NULL ) != 1 ) {
V_32 = - V_735 ;
goto V_184;
}
V_449 -> V_42 = true ;
V_449 -> V_449 = V_162 ;
if ( & V_110 -> V_18 . V_40 -> V_41 == V_720 -> V_327 ) {
struct V_6 * V_7 ;
F_91 (net, dev) {
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_43 =
V_44 ;
}
}
} else {
struct V_4 * V_5 = V_720 -> V_154 ;
V_5 -> V_43 = V_44 ;
}
V_184:
F_95 () ;
return V_32 ;
}
static
int F_421 ( struct V_149 * V_720 ,
int V_721 ,
void T_6 * V_722 ,
T_14 * V_723 ,
T_8 * V_724 )
{
int * V_725 = V_720 -> V_327 ;
int V_726 = * V_725 ;
T_8 V_508 = * V_724 ;
struct V_149 V_727 ;
int V_217 ;
V_727 = * V_720 ;
V_727 . V_327 = & V_726 ;
V_217 = F_408 ( & V_727 , V_721 , V_722 , V_723 , V_724 ) ;
if ( V_721 )
V_217 = F_98 ( V_720 , V_725 , V_726 ) ;
if ( V_217 )
* V_724 = V_508 ;
return V_217 ;
}
static int F_422 ( struct V_110 * V_110 , char * V_739 ,
struct V_4 * V_5 , struct V_94 * V_151 )
{
int V_16 ;
struct V_740 * V_741 ;
char V_742 [ sizeof( L_31 ) + V_654 ] ;
V_741 = F_423 ( & V_743 , sizeof( * V_741 ) , V_25 ) ;
if ( ! V_741 )
goto V_184;
for ( V_16 = 0 ; V_741 -> V_744 [ V_16 ] . V_327 ; V_16 ++ ) {
V_741 -> V_744 [ V_16 ] . V_327 += ( char * ) V_151 - ( char * ) & V_94 ;
V_741 -> V_744 [ V_16 ] . V_154 = V_5 ;
V_741 -> V_744 [ V_16 ] . V_153 = V_110 ;
}
snprintf ( V_742 , sizeof( V_742 ) , L_32 , V_739 ) ;
V_741 -> V_745 = F_424 ( V_110 , V_742 , V_741 -> V_744 ) ;
if ( ! V_741 -> V_745 )
goto free;
V_151 -> V_47 = V_741 ;
return 0 ;
free:
F_26 ( V_741 ) ;
V_184:
return - V_111 ;
}
static void F_425 ( struct V_94 * V_151 )
{
struct V_740 * V_741 ;
if ( ! V_151 -> V_47 )
return;
V_741 = V_151 -> V_47 ;
V_151 -> V_47 = NULL ;
F_426 ( V_741 -> V_745 ) ;
F_26 ( V_741 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_427 ( V_5 -> V_7 -> V_53 ) )
return - V_35 ;
V_32 = F_428 ( V_5 -> V_7 , V_5 -> V_48 ,
& V_746 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_422 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_53 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_429 ( V_5 -> V_48 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_425 ( & V_5 -> V_39 ) ;
F_429 ( V_5 -> V_48 ) ;
}
static int T_10 F_430 ( struct V_110 * V_110 )
{
int V_32 = - V_30 ;
struct V_94 * V_85 , * V_747 ;
V_85 = F_423 ( & V_94 , sizeof( V_94 ) , V_25 ) ;
if ( ! V_85 )
goto V_748;
V_747 = F_423 ( & V_749 , sizeof( V_749 ) , V_25 ) ;
if ( ! V_747 )
goto V_750;
V_747 -> V_375 = V_751 . V_375 ;
V_747 -> V_180 = V_751 . V_180 ;
V_747 -> V_41 . V_42 = false ;
V_85 -> V_41 . V_42 = false ;
V_110 -> V_18 . V_124 = V_85 ;
V_110 -> V_18 . V_40 = V_747 ;
#ifdef F_431
V_32 = F_422 ( V_110 , L_33 , NULL , V_85 ) ;
if ( V_32 < 0 )
goto V_752;
V_32 = F_422 ( V_110 , L_34 , NULL , V_747 ) ;
if ( V_32 < 0 )
goto V_753;
#endif
return 0 ;
#ifdef F_431
V_753:
F_425 ( V_85 ) ;
V_752:
F_26 ( V_747 ) ;
#endif
V_750:
F_26 ( V_85 ) ;
V_748:
return V_32 ;
}
static void T_11 F_432 ( struct V_110 * V_110 )
{
#ifdef F_431
F_425 ( V_110 -> V_18 . V_40 ) ;
F_425 ( V_110 -> V_18 . V_124 ) ;
#endif
F_26 ( V_110 -> V_18 . V_40 ) ;
F_26 ( V_110 -> V_18 . V_124 ) ;
}
int T_12 F_433 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_434 () ;
if ( V_32 < 0 ) {
F_435 ( L_35 ,
V_52 , V_32 ) ;
goto V_184;
}
V_32 = F_340 ( & V_754 ) ;
if ( V_32 < 0 )
goto V_755;
V_15 = F_436 ( L_36 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_756;
}
F_256 () ;
V_5 = F_28 ( V_757 . V_758 ) ;
F_95 () ;
if ( F_53 ( V_5 ) ) {
V_32 = F_122 ( V_5 ) ;
goto V_759;
}
for ( V_16 = 0 ; V_16 < V_484 ; V_16 ++ )
F_437 ( & V_188 [ V_16 ] ) ;
F_438 ( & V_760 ) ;
F_253 () ;
F_439 ( & V_761 ) ;
V_32 = F_440 ( V_762 , V_763 , NULL , F_402 ,
NULL ) ;
if ( V_32 < 0 )
goto V_113;
F_440 ( V_762 , V_424 , F_352 , NULL , NULL ) ;
F_440 ( V_762 , V_207 , F_349 , NULL , NULL ) ;
F_440 ( V_762 , V_764 , F_368 ,
F_365 , NULL ) ;
F_440 ( V_762 , V_577 , NULL ,
F_366 , NULL ) ;
F_440 ( V_762 , V_581 , NULL ,
F_367 , NULL ) ;
F_440 ( V_762 , V_765 , F_71 ,
F_78 , NULL ) ;
F_441 () ;
return 0 ;
V_113:
F_442 ( & V_761 ) ;
F_443 ( & V_760 ) ;
V_759:
F_444 ( V_15 ) ;
V_756:
F_342 ( & V_754 ) ;
V_755:
F_445 () ;
V_184:
return V_32 ;
}
void F_446 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_443 ( & V_760 ) ;
F_342 ( & V_754 ) ;
F_445 () ;
F_256 () ;
F_447 ( & V_761 ) ;
F_91 (&init_net, dev) {
if ( F_52 ( V_7 ) == NULL )
continue;
F_297 ( V_7 , 1 ) ;
}
F_297 ( V_757 . V_758 , 2 ) ;
F_144 ( & V_182 ) ;
for ( V_16 = 0 ; V_16 < V_484 ; V_16 ++ )
F_67 ( ! F_448 ( & V_188 [ V_16 ] ) ) ;
F_145 ( & V_182 ) ;
F_10 ( & V_525 ) ;
F_95 () ;
F_444 ( V_15 ) ;
}
