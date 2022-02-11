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
if ( V_31 == NULL )
return F_30 ( V_32 ) ;
F_31 ( & V_31 -> V_36 ) ;
V_31 -> V_7 = V_7 ;
F_32 ( & V_31 -> V_37 ) ;
F_33 ( & V_31 -> V_8 , V_38 ,
( unsigned long ) V_31 ) ;
memcpy ( & V_31 -> V_39 , F_34 ( V_7 ) -> V_18 . V_40 , sizeof( V_31 -> V_39 ) ) ;
V_31 -> V_39 . V_41 = V_7 -> V_33 ;
V_31 -> V_39 . V_42 = NULL ;
V_31 -> V_43 = F_35 ( V_7 , & V_44 ) ;
if ( V_31 -> V_43 == NULL ) {
F_26 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
if ( V_31 -> V_39 . V_45 )
F_36 ( V_7 ) ;
F_37 ( V_7 ) ;
if ( F_20 ( V_31 ) < 0 ) {
F_38 ( V_46
L_1 ,
V_47 , V_7 -> V_48 ) ;
F_39 ( & V_44 , V_31 -> V_43 ) ;
F_40 ( V_7 ) ;
F_26 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
if ( F_41 ( V_31 ) < 0 ) {
F_38 ( V_46
L_2 ,
V_47 , V_7 -> V_48 ) ;
goto V_49;
}
F_14 ( V_31 ) ;
if ( V_7 -> V_50 & ( V_51 | V_52 ) )
V_31 -> V_39 . V_53 = - 1 ;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 && ( V_7 -> V_56 & V_57 ) ) {
F_43 ( L_3 , V_7 -> V_48 ) ;
V_31 -> V_39 . V_58 = 0 ;
}
#endif
F_32 ( & V_31 -> V_59 ) ;
F_33 ( & V_31 -> V_60 , V_61 , ( unsigned long ) V_31 ) ;
if ( ( V_7 -> V_50 & V_52 ) ||
V_7 -> type == V_62 ||
V_7 -> type == V_63 ||
V_7 -> type == V_55 ||
V_7 -> type == V_64 ) {
V_31 -> V_39 . V_65 = - 1 ;
} else {
F_14 ( V_31 ) ;
V_61 ( ( unsigned long ) V_31 ) ;
}
V_31 -> V_66 = V_67 ;
if ( F_44 ( V_7 ) && F_4 ( V_7 ) )
V_31 -> V_68 |= V_69 ;
F_45 ( V_31 ) ;
V_31 -> V_70 = V_13 ;
V_32 = F_2 ( V_31 ) ;
if ( V_32 ) {
F_46 ( V_31 ) ;
F_7 ( & V_31 -> V_60 ) ;
goto V_49;
}
F_47 ( V_7 -> V_71 , V_31 ) ;
F_48 ( V_7 , & V_72 ) ;
F_48 ( V_7 , & V_73 ) ;
if ( V_31 -> V_39 . V_45 && ( V_7 -> V_50 & V_74 ) )
F_48 ( V_7 , & V_75 ) ;
return V_31 ;
V_49:
F_39 ( & V_44 , V_31 -> V_43 ) ;
V_31 -> V_76 = 1 ;
F_49 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
static struct V_4 * F_50 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return NULL ;
}
if ( V_7 -> V_50 & V_77 )
F_53 ( V_5 ) ;
return V_5 ;
}
static int F_54 ( int type )
{
int V_78 = F_55 ( sizeof( struct V_79 ) )
+ F_56 ( 4 ) ;
if ( type == - 1 || type == V_80 )
V_78 += F_56 ( 4 ) ;
#ifdef F_57
if ( type == - 1 || type == V_81 )
V_78 += F_56 ( 4 ) ;
#endif
if ( type == - 1 || type == V_82 )
V_78 += F_56 ( 4 ) ;
return V_78 ;
}
static int F_58 ( struct V_83 * V_84 , int V_85 ,
struct V_86 * V_87 , T_1 V_88 ,
T_1 V_89 , int V_90 , unsigned int V_50 ,
int type )
{
struct V_91 * V_92 ;
struct V_79 * V_93 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_79 ) ,
V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_93 = F_60 ( V_92 ) ;
V_93 -> V_95 = V_96 ;
if ( F_61 ( V_84 , V_97 , V_85 ) < 0 )
goto V_98;
if ( ( type == - 1 || type == V_80 ) &&
F_61 ( V_84 , V_80 , V_87 -> V_45 ) < 0 )
goto V_98;
#ifdef F_57
if ( ( type == - 1 || type == V_81 ) &&
F_61 ( V_84 , V_81 ,
V_87 -> V_99 ) < 0 )
goto V_98;
#endif
if ( ( type == - 1 || type == V_82 ) &&
F_61 ( V_84 , V_82 , V_87 -> V_100 ) < 0 )
goto V_98;
return F_62 ( V_84 , V_92 ) ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
void F_64 ( struct V_101 * V_101 , int type , int V_85 ,
struct V_86 * V_87 )
{
struct V_83 * V_84 ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_54 ( type ) , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_32 = F_58 ( V_84 , V_85 , V_87 , 0 , 0 ,
V_105 , 0 , type ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_106 , NULL , V_103 ) ;
return;
V_104:
F_69 ( V_101 , V_106 , V_32 ) ;
}
static int F_70 ( struct V_83 * V_107 ,
struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_107 -> V_108 ) ;
struct V_109 * V_110 [ V_111 + 1 ] ;
struct V_79 * V_93 ;
struct V_83 * V_84 ;
struct V_86 * V_87 ;
struct V_4 * V_112 ;
struct V_6 * V_7 ;
int V_85 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_93 ) , V_110 , V_111 ,
V_113 ) ;
if ( V_32 < 0 )
goto V_104;
V_32 = V_35 ;
if ( ! V_110 [ V_97 ] )
goto V_104;
V_85 = F_73 ( V_110 [ V_97 ] ) ;
switch ( V_85 ) {
case V_114 :
V_87 = V_101 -> V_18 . V_115 ;
break;
case V_116 :
V_87 = V_101 -> V_18 . V_40 ;
break;
default:
V_7 = F_74 ( V_101 , V_85 ) ;
if ( V_7 == NULL )
goto V_104;
V_112 = F_51 ( V_7 ) ;
if ( V_112 == NULL )
goto V_104;
V_87 = & V_112 -> V_39 ;
break;
}
V_32 = - V_102 ;
V_84 = F_65 ( F_54 ( - 1 ) , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_32 = F_58 ( V_84 , V_85 , V_87 ,
F_75 ( V_107 ) . V_88 ,
V_92 -> V_117 , V_105 , 0 ,
- 1 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
V_32 = F_76 ( V_84 , V_101 , F_75 ( V_107 ) . V_88 ) ;
V_104:
return V_32 ;
}
static int F_77 ( struct V_83 * V_84 ,
struct V_118 * V_119 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
int V_120 , V_121 ;
int V_122 , V_123 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_124 * V_125 ;
V_121 = V_119 -> args [ 0 ] ;
V_123 = V_122 = V_119 -> args [ 1 ] ;
for ( V_120 = V_121 ; V_120 < V_126 ; V_120 ++ , V_123 = 0 ) {
V_122 = 0 ;
V_125 = & V_101 -> V_127 [ V_120 ] ;
F_78 () ;
V_119 -> V_89 = F_79 ( & V_101 -> V_18 . V_128 ) ^
V_101 -> V_129 ;
F_80 (dev, head, index_hlist) {
if ( V_122 < V_123 )
goto V_130;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_130;
if ( F_58 ( V_84 , V_7 -> V_85 ,
& V_5 -> V_39 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_105 ,
V_131 ,
- 1 ) <= 0 ) {
F_81 () ;
goto V_132;
}
F_82 ( V_119 , F_83 ( V_84 ) ) ;
V_130:
V_122 ++ ;
}
F_81 () ;
}
if ( V_120 == V_126 ) {
if ( F_58 ( V_84 , V_114 ,
V_101 -> V_18 . V_115 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_105 , V_131 ,
- 1 ) <= 0 )
goto V_132;
else
V_120 ++ ;
}
if ( V_120 == V_126 + 1 ) {
if ( F_58 ( V_84 , V_116 ,
V_101 -> V_18 . V_40 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_105 , V_131 ,
- 1 ) <= 0 )
goto V_132;
else
V_120 ++ ;
}
V_132:
V_119 -> args [ 0 ] = V_120 ;
V_119 -> args [ 1 ] = V_122 ;
return V_84 -> V_133 ;
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_134 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_39 . V_45 )
F_36 ( V_7 ) ;
if ( V_7 -> V_50 & V_74 ) {
if ( V_5 -> V_39 . V_45 ) {
F_48 ( V_7 , & V_75 ) ;
F_48 ( V_7 , & V_135 ) ;
F_48 ( V_7 , & V_136 ) ;
} else {
F_85 ( V_7 , & V_75 ) ;
F_85 ( V_7 , & V_135 ) ;
F_85 ( V_7 , & V_136 ) ;
}
}
F_86 (ifa, &idev->addr_list, if_list) {
if ( V_134 -> V_50 & V_137 )
continue;
if ( V_5 -> V_39 . V_45 )
F_87 ( V_134 ) ;
else
F_88 ( V_134 ) ;
}
F_64 ( F_34 ( V_7 ) , V_80 ,
V_7 -> V_85 , & V_5 -> V_39 ) ;
}
static void F_89 ( struct V_101 * V_101 , T_2 V_138 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_90 (net, dev) {
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
int V_139 = ( ! V_5 -> V_39 . V_45 ) ^ ( ! V_138 ) ;
V_5 -> V_39 . V_45 = V_138 ;
if ( V_139 )
F_84 ( V_5 ) ;
}
}
}
static int F_91 ( struct V_140 * V_141 , int * V_142 , int V_138 )
{
struct V_101 * V_101 ;
int V_143 ;
if ( ! F_92 () )
return F_93 () ;
V_101 = (struct V_101 * ) V_141 -> V_144 ;
V_143 = * V_142 ;
* V_142 = V_138 ;
if ( V_142 == & V_101 -> V_18 . V_40 -> V_45 ) {
if ( ( ! V_138 ) ^ ( ! V_143 ) )
F_64 ( V_101 , V_80 ,
V_116 ,
V_101 -> V_18 . V_40 ) ;
F_94 () ;
return 0 ;
}
if ( V_142 == & V_101 -> V_18 . V_115 -> V_45 ) {
V_101 -> V_18 . V_40 -> V_45 = V_138 ;
F_89 ( V_101 , V_138 ) ;
if ( ( ! V_138 ) ^ ( ! V_143 ) )
F_64 ( V_101 , V_80 ,
V_114 ,
V_101 -> V_18 . V_115 ) ;
} else if ( ( ! V_138 ) ^ ( ! V_143 ) )
F_84 ( (struct V_4 * ) V_141 -> V_145 ) ;
F_94 () ;
if ( V_138 )
F_95 ( V_101 ) ;
return 1 ;
}
void F_96 ( struct V_9 * V_10 )
{
F_66 ( ! F_97 ( & V_10 -> V_146 ) ) ;
#ifdef F_98
F_99 ( L_4 , V_47 ) ;
#endif
F_100 ( V_10 -> V_5 ) ;
if ( F_10 ( & V_10 -> V_11 ) )
F_101 ( L_5 ,
V_10 ) ;
if ( V_10 -> V_147 != V_148 ) {
F_102 ( L_6 , V_10 ) ;
return;
}
F_103 ( V_10 -> V_149 ) ;
F_104 ( V_10 , V_150 ) ;
}
static void
F_105 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_151 * V_142 ;
int V_152 = F_106 ( & V_10 -> V_153 ) ;
F_107 (p, &idev->addr_list) {
struct V_9 * V_134
= F_108 ( V_142 , struct V_9 , V_154 ) ;
if ( V_152 >= F_106 ( & V_134 -> V_153 ) )
break;
}
F_109 ( & V_10 -> V_154 , V_142 ) ;
}
static T_1 F_110 ( const struct V_155 * V_153 )
{
return F_111 ( F_112 ( V_153 ) , V_156 ) ;
}
static struct V_9 *
F_113 ( struct V_4 * V_5 , const struct V_155 * V_153 ,
const struct V_155 * V_157 , int V_158 ,
int V_159 , T_1 V_50 , T_1 V_160 , T_1 V_161 )
{
struct V_9 * V_134 = NULL ;
struct V_162 * V_149 ;
unsigned int V_163 ;
int V_32 = 0 ;
int V_164 = F_114 ( V_153 ) ;
if ( V_164 == V_165 ||
V_164 & V_166 ||
( ! ( V_5 -> V_7 -> V_50 & V_52 ) &&
V_164 & V_167 ) )
return F_30 ( - V_168 ) ;
F_115 () ;
if ( V_5 -> V_76 ) {
V_32 = - V_169 ;
goto V_170;
}
if ( V_5 -> V_39 . V_171 ) {
V_32 = - V_172 ;
goto V_170;
}
F_116 ( & V_173 ) ;
if ( F_117 ( F_34 ( V_5 -> V_7 ) , V_153 , V_5 -> V_7 ) ) {
F_38 ( L_7 ) ;
V_32 = - V_174 ;
goto V_175;
}
V_134 = F_25 ( sizeof( struct V_9 ) , V_103 ) ;
if ( V_134 == NULL ) {
F_38 ( L_8 ) ;
V_32 = - V_102 ;
goto V_175;
}
V_149 = F_118 ( V_5 , V_153 , false ) ;
if ( F_52 ( V_149 ) ) {
V_32 = F_119 ( V_149 ) ;
goto V_175;
}
F_120 ( V_5 -> V_43 ) ;
V_134 -> V_153 = * V_153 ;
if ( V_157 )
V_134 -> V_157 = * V_157 ;
F_121 ( & V_134 -> V_36 ) ;
F_121 ( & V_134 -> V_176 ) ;
F_122 ( & V_134 -> V_11 , V_177 ) ;
F_123 ( & V_134 -> V_146 ) ;
V_134 -> V_159 = V_159 ;
V_134 -> V_178 = V_158 ;
V_134 -> V_50 = V_50 | V_137 ;
V_134 -> V_160 = V_160 ;
V_134 -> V_161 = V_161 ;
V_134 -> V_1 = V_134 -> V_70 = V_13 ;
V_134 -> V_179 = false ;
V_134 -> V_149 = V_149 ;
V_134 -> V_5 = V_5 ;
F_14 ( V_5 ) ;
F_18 ( V_134 ) ;
V_163 = F_110 ( V_153 ) ;
F_124 ( & V_134 -> V_146 , & V_180 [ V_163 ] ) ;
F_125 ( & V_173 ) ;
F_126 ( & V_5 -> V_36 ) ;
F_105 ( V_5 , V_134 ) ;
if ( V_134 -> V_50 & V_181 ) {
F_127 ( & V_134 -> V_182 , & V_5 -> V_59 ) ;
F_18 ( V_134 ) ;
}
F_18 ( V_134 ) ;
F_128 ( & V_5 -> V_36 ) ;
V_170:
F_129 () ;
if ( F_130 ( V_32 == 0 ) )
F_131 ( V_183 , V_134 ) ;
else {
F_26 ( V_134 ) ;
V_134 = F_30 ( V_32 ) ;
}
return V_134 ;
V_175:
F_125 ( & V_173 ) ;
goto V_170;
}
static enum V_184
F_132 ( struct V_9 * V_10 , unsigned long * V_185 )
{
struct V_9 * V_134 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_186 ;
enum V_184 V_187 = V_188 ;
* V_185 = V_13 ;
F_86 (ifa, &idev->addr_list, if_list) {
if ( V_134 == V_10 )
continue;
if ( ! F_133 ( & V_134 -> V_153 , & V_10 -> V_153 ,
V_10 -> V_178 ) )
continue;
if ( V_134 -> V_50 & ( V_189 | V_190 ) )
return V_191 ;
V_187 = V_192 ;
F_116 ( & V_134 -> V_36 ) ;
V_186 = F_134 ( V_134 -> V_160 , V_3 ) ;
if ( F_135 ( * V_185 , V_134 -> V_70 + V_186 * V_3 ) )
* V_185 = V_134 -> V_70 + V_186 * V_3 ;
F_125 ( & V_134 -> V_36 ) ;
}
return V_187 ;
}
static void
F_136 ( struct V_9 * V_10 , unsigned long V_185 , bool V_193 )
{
struct V_162 * V_149 ;
V_149 = F_137 ( & V_10 -> V_153 ,
V_10 -> V_178 ,
V_10 -> V_5 -> V_7 ,
0 , V_194 | V_195 ) ;
if ( V_149 ) {
if ( V_193 )
F_138 ( V_149 ) ;
else {
if ( ! ( V_149 -> V_196 & V_197 ) )
F_139 ( V_149 , V_185 ) ;
F_103 ( V_149 ) ;
}
}
}
static void F_140 ( struct V_9 * V_10 )
{
int V_147 ;
enum V_184 V_187 = V_191 ;
unsigned long V_185 ;
F_29 () ;
F_141 ( & V_10 -> V_176 ) ;
V_147 = V_10 -> V_147 ;
V_10 -> V_147 = V_148 ;
F_142 ( & V_10 -> V_176 ) ;
if ( V_147 == V_148 )
goto V_175;
F_141 ( & V_173 ) ;
F_143 ( & V_10 -> V_146 ) ;
F_142 ( & V_173 ) ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_10 -> V_50 & V_181 ) {
F_145 ( & V_10 -> V_182 ) ;
if ( V_10 -> V_198 ) {
F_146 ( V_10 -> V_198 ) ;
V_10 -> V_198 = NULL ;
}
F_11 ( V_10 ) ;
}
if ( V_10 -> V_50 & V_189 && ! ( V_10 -> V_50 & V_190 ) )
V_187 = F_132 ( V_10 , & V_185 ) ;
F_147 ( & V_10 -> V_154 ) ;
F_11 ( V_10 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
F_9 ( V_10 ) ;
F_149 ( V_199 , V_10 ) ;
F_131 ( V_200 , V_10 ) ;
if ( V_187 != V_191 ) {
F_136 ( V_10 , V_185 ,
V_187 == V_188 ) ;
}
F_150 ( V_10 ) ;
V_175:
F_146 ( V_10 ) ;
}
static int F_151 ( struct V_9 * V_10 , struct V_9 * V_201 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_155 V_153 , * V_202 ;
unsigned long V_203 , V_204 , V_205 , V_206 ;
unsigned long V_207 ;
int V_208 ;
int V_209 = 0 ;
T_1 V_210 ;
unsigned long V_211 = V_13 ;
F_144 ( & V_5 -> V_36 ) ;
if ( V_201 ) {
F_141 ( & V_201 -> V_36 ) ;
memcpy ( & V_153 . V_212 [ 8 ] , & V_201 -> V_153 . V_212 [ 8 ] , 8 ) ;
F_142 ( & V_201 -> V_36 ) ;
V_202 = & V_153 ;
} else {
V_202 = NULL ;
}
V_213:
F_14 ( V_5 ) ;
if ( V_5 -> V_39 . V_65 <= 0 ) {
F_148 ( & V_5 -> V_36 ) ;
F_43 ( L_9 , V_47 ) ;
F_100 ( V_5 ) ;
V_209 = - 1 ;
goto V_175;
}
F_141 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_214 ++ >= V_5 -> V_39 . V_215 ) {
V_5 -> V_39 . V_65 = - 1 ;
F_142 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_102 ( L_10 ,
V_47 ) ;
F_100 ( V_5 ) ;
V_209 = - 1 ;
goto V_175;
}
F_18 ( V_10 ) ;
memcpy ( V_153 . V_212 , V_10 -> V_153 . V_212 , 8 ) ;
F_152 ( V_5 , V_202 ) ;
memcpy ( & V_153 . V_212 [ 8 ] , V_5 -> V_216 , 8 ) ;
V_206 = ( V_211 - V_10 -> V_70 ) / V_3 ;
V_204 = F_153 ( V_217 ,
V_10 -> V_160 ,
V_5 -> V_39 . V_218 + V_206 ) ;
V_203 = F_153 ( V_217 ,
V_10 -> V_161 ,
V_5 -> V_39 . V_219 + V_206 -
V_5 -> V_39 . V_220 ) ;
V_208 = V_10 -> V_178 ;
V_205 = V_10 -> V_70 ;
F_142 ( & V_10 -> V_36 ) ;
V_207 = V_5 -> V_39 . V_215 *
V_5 -> V_39 . V_221 *
F_154 ( V_5 -> V_43 , V_222 ) / V_3 ;
F_148 ( & V_5 -> V_36 ) ;
V_206 = ( V_211 - V_205 + V_223 ) / V_3 ;
if ( V_203 <= V_207 + V_206 ) {
F_146 ( V_10 ) ;
F_100 ( V_5 ) ;
V_209 = - 1 ;
goto V_175;
}
V_210 = V_181 ;
if ( V_10 -> V_50 & V_224 )
V_210 |= V_224 ;
V_201 = F_113 ( V_5 , & V_153 , NULL , V_208 ,
F_155 ( & V_153 ) , V_210 ,
V_204 , V_203 ) ;
if ( F_52 ( V_201 ) ) {
F_146 ( V_10 ) ;
F_100 ( V_5 ) ;
F_43 ( L_11 , V_47 ) ;
V_202 = & V_153 ;
F_144 ( & V_5 -> V_36 ) ;
goto V_213;
}
F_141 ( & V_201 -> V_36 ) ;
V_201 -> V_198 = V_10 ;
V_201 -> V_1 = V_211 ;
V_201 -> V_70 = V_205 ;
F_142 ( & V_201 -> V_36 ) ;
F_156 ( V_201 ) ;
F_146 ( V_201 ) ;
F_100 ( V_5 ) ;
V_175:
return V_209 ;
}
static inline int F_157 ( int type )
{
if ( type & ( V_225 | V_226 | V_167 ) )
return 1 ;
return 0 ;
}
static int F_158 ( struct V_101 * V_101 ,
struct V_227 * V_228 ,
struct V_229 * V_230 ,
int V_16 )
{
int V_209 ;
if ( V_16 <= V_228 -> V_231 ) {
switch ( V_16 ) {
case V_232 :
V_209 = V_228 -> V_233 ;
break;
case V_234 :
V_209 = V_228 -> V_235 ;
break;
default:
V_209 = ! ! F_159 ( V_16 , V_228 -> V_236 ) ;
}
goto V_175;
}
switch ( V_16 ) {
case V_237 :
V_209 = ! ! V_228 -> V_134 ;
break;
case V_238 :
V_209 = F_160 ( & V_228 -> V_134 -> V_153 , V_230 -> V_153 ) ;
break;
case V_232 :
V_209 = F_161 ( V_228 -> V_164 ) ;
if ( V_209 >= V_230 -> V_159 )
V_209 = - V_209 ;
else
V_209 -= 128 ;
V_228 -> V_233 = V_209 ;
break;
case V_239 :
V_209 = F_157 ( V_228 -> V_164 ) ||
! ( V_228 -> V_134 -> V_50 & ( V_240 | V_224 ) ) ;
break;
#ifdef F_162
case V_241 :
{
int V_242 = ! ( V_230 -> V_243 & V_244 ) ;
V_209 = ! ( V_228 -> V_134 -> V_50 & V_245 ) ^ V_242 ;
break;
}
#endif
case V_246 :
V_209 = ( ! V_230 -> V_85 ||
V_230 -> V_85 == V_228 -> V_134 -> V_5 -> V_7 -> V_85 ) ;
break;
case V_247 :
V_209 = F_163 ( V_101 ,
& V_228 -> V_134 -> V_153 , V_228 -> V_164 ,
V_228 -> V_134 -> V_5 -> V_7 -> V_85 ) == V_230 -> V_248 ;
break;
case V_249 :
{
int V_250 = V_230 -> V_243 & ( V_251 | V_252 ) ?
! ! ( V_230 -> V_243 & V_252 ) :
V_228 -> V_134 -> V_5 -> V_39 . V_65 >= 2 ;
V_209 = ( ! ( V_228 -> V_134 -> V_50 & V_181 ) ) ^ V_250 ;
break;
}
case V_253 :
V_209 = ! ( F_164 ( & V_228 -> V_134 -> V_153 ) ^
F_164 ( V_230 -> V_153 ) ) ;
break;
case V_234 :
V_209 = F_165 ( & V_228 -> V_134 -> V_153 , V_230 -> V_153 ) ;
if ( V_209 > V_228 -> V_134 -> V_178 )
V_209 = V_228 -> V_134 -> V_178 ;
V_228 -> V_235 = V_209 ;
break;
default:
V_209 = 0 ;
}
if ( V_209 )
F_166 ( V_16 , V_228 -> V_236 ) ;
V_228 -> V_231 = V_16 ;
V_175:
return V_209 ;
}
int F_167 ( struct V_101 * V_101 , const struct V_6 * V_254 ,
const struct V_155 * V_255 , unsigned int V_243 ,
struct V_155 * V_256 )
{
struct V_227 V_257 [ 2 ] ,
* V_228 = & V_257 [ 0 ] , * V_258 = & V_257 [ 1 ] ;
struct V_229 V_230 ;
struct V_6 * V_7 ;
int V_259 ;
V_259 = F_168 ( V_255 ) ;
V_230 . V_153 = V_255 ;
V_230 . V_85 = V_254 ? V_254 -> V_85 : 0 ;
V_230 . V_159 = F_161 ( V_259 ) ;
V_230 . V_248 = F_163 ( V_101 , V_255 , V_259 , V_230 . V_85 ) ;
V_230 . V_243 = V_243 ;
V_258 -> V_231 = - 1 ;
V_258 -> V_134 = NULL ;
F_78 () ;
F_169 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_259 & V_166 ) ||
V_230 . V_159 <= V_260 ) &&
V_230 . V_85 && V_7 -> V_85 != V_230 . V_85 )
continue;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
continue;
F_170 ( & V_5 -> V_36 ) ;
F_86 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_228 -> V_134 -> V_50 & V_137 ) &&
( ! ( V_228 -> V_134 -> V_50 & V_224 ) ) )
continue;
V_228 -> V_164 = F_168 ( & V_228 -> V_134 -> V_153 ) ;
if ( F_171 ( V_228 -> V_164 == V_165 ||
V_228 -> V_164 & V_166 ) ) {
F_172 ( V_261
L_12
L_13 ,
V_7 -> V_48 ) ;
continue;
}
V_228 -> V_231 = - 1 ;
F_173 ( V_228 -> V_236 , V_262 ) ;
for ( V_16 = 0 ; V_16 < V_262 ; V_16 ++ ) {
int V_263 , V_264 ;
V_263 = F_158 ( V_101 , V_258 , & V_230 , V_16 ) ;
V_264 = F_158 ( V_101 , V_228 , & V_230 , V_16 ) ;
if ( V_263 > V_264 ) {
if ( V_16 == V_232 &&
V_228 -> V_233 > 0 ) {
goto V_265;
}
break;
} else if ( V_263 < V_264 ) {
if ( V_258 -> V_134 )
F_146 ( V_258 -> V_134 ) ;
F_18 ( V_228 -> V_134 ) ;
F_174 ( V_258 , V_228 ) ;
V_228 -> V_134 = V_258 -> V_134 ;
break;
}
}
}
V_265:
F_175 ( & V_5 -> V_36 ) ;
}
F_81 () ;
if ( ! V_258 -> V_134 )
return - V_168 ;
* V_256 = V_258 -> V_134 -> V_153 ;
F_146 ( V_258 -> V_134 ) ;
return 0 ;
}
int F_176 ( struct V_4 * V_5 , struct V_155 * V_153 ,
T_1 V_266 )
{
struct V_9 * V_10 ;
int V_32 = - V_168 ;
F_177 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_159 > V_267 )
break;
if ( V_10 -> V_159 == V_267 &&
! ( V_10 -> V_50 & V_266 ) ) {
* V_153 = V_10 -> V_153 ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
int F_178 ( struct V_6 * V_7 , struct V_155 * V_153 ,
T_1 V_266 )
{
struct V_4 * V_5 ;
int V_32 = - V_168 ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_170 ( & V_5 -> V_36 ) ;
V_32 = F_176 ( V_5 , V_153 , V_266 ) ;
F_175 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_32 ;
}
static int F_179 ( struct V_4 * V_5 )
{
int V_268 = 0 ;
struct V_9 * V_10 ;
F_170 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list)
V_268 ++ ;
F_175 ( & V_5 -> V_36 ) ;
return V_268 ;
}
int F_180 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
const struct V_6 * V_7 , int V_269 )
{
struct V_9 * V_10 ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_80 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_181 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_160 ( & V_10 -> V_153 , V_153 ) &&
! ( V_10 -> V_50 & V_137 ) &&
( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_159 & ( V_267 | V_270 ) || V_269 ) ) ) {
F_129 () ;
return 1 ;
}
}
F_129 () ;
return 0 ;
}
static bool F_117 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
struct V_6 * V_7 )
{
unsigned int V_163 = F_110 ( V_153 ) ;
struct V_9 * V_10 ;
F_182 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_181 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_160 ( & V_10 -> V_153 , V_153 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_183 ( const struct V_155 * V_153 ,
const unsigned int V_178 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_134 ;
bool V_209 = false ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_170 ( & V_5 -> V_36 ) ;
F_86 (ifa, &idev->addr_list, if_list) {
V_209 = F_133 ( V_153 , & V_134 -> V_153 , V_178 ) ;
if ( V_209 )
break;
}
F_175 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_209 ;
}
int F_184 ( const struct V_155 * V_153 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_134 ;
int V_271 ;
V_271 = 0 ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_170 ( & V_5 -> V_36 ) ;
F_86 (ifa, &idev->addr_list, if_list) {
V_271 = F_133 ( V_153 , & V_134 -> V_153 ,
V_134 -> V_178 ) ;
if ( V_271 )
break;
}
F_175 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_271 ;
}
struct V_9 * F_185 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
struct V_6 * V_7 , int V_269 )
{
struct V_9 * V_10 , * V_272 = NULL ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_186 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_181 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_160 ( & V_10 -> V_153 , V_153 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_159 & ( V_267 | V_270 ) || V_269 ) ) {
V_272 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_129 () ;
return V_272 ;
}
static void F_187 ( struct V_9 * V_10 , int V_273 )
{
if ( V_10 -> V_50 & V_189 ) {
F_141 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_50 |= V_137 ;
if ( V_273 )
V_10 -> V_50 |= V_274 ;
F_142 ( & V_10 -> V_36 ) ;
if ( V_273 )
F_149 ( 0 , V_10 ) ;
F_146 ( V_10 ) ;
} else if ( V_10 -> V_50 & V_181 ) {
struct V_9 * V_198 ;
F_141 ( & V_10 -> V_36 ) ;
V_198 = V_10 -> V_198 ;
if ( V_198 ) {
F_18 ( V_198 ) ;
F_142 ( & V_10 -> V_36 ) ;
F_151 ( V_198 , V_10 ) ;
F_146 ( V_198 ) ;
} else {
F_142 ( & V_10 -> V_36 ) ;
}
F_140 ( V_10 ) ;
} else {
F_140 ( V_10 ) ;
}
}
static int F_188 ( struct V_9 * V_10 )
{
int V_32 = - V_275 ;
F_141 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_147 == V_276 ) {
V_10 -> V_147 = V_277 ;
V_32 = 0 ;
}
F_142 ( & V_10 -> V_176 ) ;
return V_32 ;
}
void F_189 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_188 ( V_10 ) ) {
F_146 ( V_10 ) ;
return;
}
F_190 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_48 , & V_10 -> V_153 ) ;
if ( V_5 -> V_39 . V_53 > 1 && ! V_5 -> V_39 . V_171 ) {
struct V_155 V_153 ;
V_153 . V_278 [ 0 ] = F_191 ( 0xfe800000 ) ;
V_153 . V_278 [ 1 ] = 0 ;
if ( ! F_192 ( V_153 . V_212 + 8 , V_5 -> V_7 ) &&
F_160 ( & V_10 -> V_153 , & V_153 ) ) {
V_5 -> V_39 . V_171 = 1 ;
F_43 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
}
}
F_141 ( & V_10 -> V_176 ) ;
V_10 -> V_147 = V_279 ;
F_142 ( & V_10 -> V_176 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_193 ( struct V_6 * V_7 , const struct V_155 * V_153 )
{
struct V_155 V_280 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_194 ( V_153 , & V_280 ) ;
F_48 ( V_7 , & V_280 ) ;
}
void F_195 ( struct V_4 * V_5 , const struct V_155 * V_153 )
{
struct V_155 V_280 ;
if ( V_5 -> V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_194 ( V_153 , & V_280 ) ;
F_196 ( V_5 , & V_280 ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_155 V_153 ;
if ( V_10 -> V_178 >= 127 )
return;
F_197 ( & V_153 , & V_10 -> V_153 , V_10 -> V_178 ) ;
if ( F_198 ( & V_153 ) )
return;
F_199 ( V_10 -> V_5 -> V_7 , & V_153 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_155 V_153 ;
if ( V_10 -> V_178 >= 127 )
return;
F_197 ( & V_153 , & V_10 -> V_153 , V_10 -> V_178 ) ;
if ( F_198 ( & V_153 ) )
return;
F_200 ( V_10 -> V_5 , & V_153 ) ;
}
static int F_201 ( T_3 * V_281 , struct V_6 * V_7 )
{
if ( V_7 -> V_282 != V_283 )
return - 1 ;
memcpy ( V_281 , V_7 -> V_284 , 3 ) ;
memcpy ( V_281 + 5 , V_7 -> V_284 + 3 , 3 ) ;
if ( V_7 -> V_285 ) {
V_281 [ 3 ] = ( V_7 -> V_285 >> 8 ) & 0xFF ;
V_281 [ 4 ] = V_7 -> V_285 & 0xFF ;
} else {
V_281 [ 3 ] = 0xFF ;
V_281 [ 4 ] = 0xFE ;
V_281 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_202 ( T_3 * V_281 , struct V_6 * V_7 )
{
if ( V_7 -> V_282 != V_286 )
return - 1 ;
memcpy ( V_281 , V_7 -> V_284 , 8 ) ;
V_281 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_203 ( T_3 * V_281 , struct V_6 * V_7 )
{
union V_287 * V_288 ;
if ( V_7 -> V_282 != V_289 )
return - 1 ;
V_288 = (union V_287 * ) V_7 -> V_284 ;
memcpy ( V_281 , & V_288 -> V_290 . V_291 , sizeof( V_288 -> V_290 . V_291 ) ) ;
V_281 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_204 ( T_3 * V_281 , struct V_6 * V_7 )
{
if ( V_7 -> V_282 != V_292 )
return - 1 ;
memset ( V_281 , 0 , 7 ) ;
V_281 [ 7 ] = * ( T_3 * ) V_7 -> V_284 ;
return 0 ;
}
static int F_205 ( T_3 * V_281 , struct V_6 * V_7 )
{
if ( V_7 -> V_282 != V_293 )
return - 1 ;
memcpy ( V_281 , V_7 -> V_284 + 12 , 8 ) ;
V_281 [ 0 ] |= 2 ;
return 0 ;
}
static int F_206 ( T_3 * V_281 , T_4 V_153 )
{
if ( V_153 == 0 )
return - 1 ;
V_281 [ 0 ] = ( F_207 ( V_153 ) || F_208 ( V_153 ) ||
F_209 ( V_153 ) || F_210 ( V_153 ) ||
F_211 ( V_153 ) || F_212 ( V_153 ) ||
F_213 ( V_153 ) || F_214 ( V_153 ) ||
F_215 ( V_153 ) || F_216 ( V_153 ) ||
F_217 ( V_153 ) ) ? 0x00 : 0x02 ;
V_281 [ 1 ] = 0 ;
V_281 [ 2 ] = 0x5E ;
V_281 [ 3 ] = 0xFE ;
memcpy ( V_281 + 4 , & V_153 , 4 ) ;
return 0 ;
}
static int F_218 ( T_3 * V_281 , struct V_6 * V_7 )
{
if ( V_7 -> V_56 & V_57 )
return F_206 ( V_281 , * ( T_4 * ) V_7 -> V_284 ) ;
return - 1 ;
}
static int F_219 ( T_3 * V_281 , struct V_6 * V_7 )
{
return F_206 ( V_281 , * ( T_4 * ) V_7 -> V_284 ) ;
}
static int F_220 ( T_3 * V_281 , struct V_6 * V_7 )
{
memcpy ( V_281 , V_7 -> V_294 , 3 ) ;
memcpy ( V_281 + 5 , V_7 -> V_294 + 3 , 3 ) ;
V_281 [ 3 ] = 0xFF ;
V_281 [ 4 ] = 0xFE ;
V_281 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_192 ( T_3 * V_281 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_295 :
case V_296 :
return F_201 ( V_281 , V_7 ) ;
case V_297 :
return F_204 ( V_281 , V_7 ) ;
case V_298 :
return F_205 ( V_281 , V_7 ) ;
case V_55 :
return F_218 ( V_281 , V_7 ) ;
case V_299 :
return F_219 ( V_281 , V_7 ) ;
case V_300 :
case V_301 :
return F_202 ( V_281 , V_7 ) ;
case V_302 :
return F_203 ( V_281 , V_7 ) ;
case V_63 :
return F_220 ( V_281 , V_7 ) ;
}
return - 1 ;
}
static int F_221 ( T_3 * V_281 , struct V_4 * V_5 )
{
int V_32 = - 1 ;
struct V_9 * V_10 ;
F_170 ( & V_5 -> V_36 ) ;
F_177 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_159 > V_267 )
break;
if ( V_10 -> V_159 == V_267 && ! ( V_10 -> V_50 & V_137 ) ) {
memcpy ( V_281 , V_10 -> V_153 . V_212 + 8 , 8 ) ;
V_32 = 0 ;
break;
}
}
F_175 ( & V_5 -> V_36 ) ;
return V_32 ;
}
static void F_222 ( struct V_4 * V_5 )
{
V_303:
F_223 ( V_5 -> V_216 , sizeof( V_5 -> V_216 ) ) ;
V_5 -> V_216 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_216 [ 0 ] == 0xfd &&
( V_5 -> V_216 [ 1 ] & V_5 -> V_216 [ 2 ] & V_5 -> V_216 [ 3 ] & V_5 -> V_216 [ 4 ] & V_5 -> V_216 [ 5 ] & V_5 -> V_216 [ 6 ] ) == 0xff &&
( V_5 -> V_216 [ 7 ] & 0x80 ) )
goto V_303;
if ( ( V_5 -> V_216 [ 0 ] | V_5 -> V_216 [ 1 ] ) == 0 ) {
if ( V_5 -> V_216 [ 2 ] == 0x5e && V_5 -> V_216 [ 3 ] == 0xfe )
goto V_303;
if ( ( V_5 -> V_216 [ 2 ] | V_5 -> V_216 [ 3 ] | V_5 -> V_216 [ 4 ] | V_5 -> V_216 [ 5 ] | V_5 -> V_216 [ 6 ] | V_5 -> V_216 [ 7 ] ) == 0x00 )
goto V_303;
}
}
static void V_61 ( unsigned long V_304 )
{
struct V_4 * V_5 = (struct V_4 * ) V_304 ;
unsigned long V_185 ;
F_115 () ;
F_144 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 )
goto V_175;
F_222 ( V_5 ) ;
V_185 = V_13 +
V_5 -> V_39 . V_219 * V_3 -
V_5 -> V_39 . V_215 * V_5 -> V_39 . V_221 *
F_154 ( V_5 -> V_43 , V_222 ) -
V_5 -> V_39 . V_220 * V_3 ;
if ( F_135 ( V_185 , V_13 ) ) {
F_102 ( L_16 ,
V_47 , V_5 -> V_7 -> V_48 ) ;
goto V_175;
}
if ( ! F_15 ( & V_5 -> V_60 , V_185 ) )
F_14 ( V_5 ) ;
V_175:
F_148 ( & V_5 -> V_36 ) ;
F_129 () ;
F_100 ( V_5 ) ;
}
static void F_152 ( struct V_4 * V_5 , struct V_155 * V_202 )
{
if ( V_202 && memcmp ( V_5 -> V_216 , & V_202 -> V_212 [ 8 ] , 8 ) == 0 )
F_222 ( V_5 ) ;
}
static void
F_224 ( struct V_155 * V_305 , int V_306 , struct V_6 * V_7 ,
unsigned long V_185 , T_1 V_50 )
{
struct V_307 V_308 = {
. V_309 = V_310 ,
. V_311 = V_312 ,
. V_313 = V_7 -> V_85 ,
. V_314 = V_185 ,
. V_315 = V_306 ,
. V_316 = V_317 | V_50 ,
. V_318 . V_319 = F_34 ( V_7 ) ,
. V_320 = V_321 ,
} ;
V_308 . V_322 = * V_305 ;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 && ( V_7 -> V_50 & V_323 ) )
V_308 . V_316 |= V_324 ;
#endif
F_225 ( & V_308 ) ;
}
static struct V_162 * F_137 ( const struct V_155 * V_305 ,
int V_306 ,
const struct V_6 * V_7 ,
T_1 V_50 , T_1 V_325 )
{
struct V_326 * V_327 ;
struct V_162 * V_149 = NULL ;
struct V_328 * V_141 ;
V_141 = F_226 ( F_34 ( V_7 ) , V_310 ) ;
if ( V_141 == NULL )
return NULL ;
F_170 ( & V_141 -> V_329 ) ;
V_327 = F_227 ( & V_141 -> V_330 , V_305 , V_306 , NULL , 0 ) ;
if ( ! V_327 )
goto V_175;
for ( V_149 = V_327 -> V_331 ; V_149 ; V_149 = V_149 -> V_230 . V_332 ) {
if ( V_149 -> V_230 . V_7 -> V_85 != V_7 -> V_85 )
continue;
if ( ( V_149 -> V_196 & V_50 ) != V_50 )
continue;
if ( ( V_149 -> V_196 & V_325 ) != 0 )
continue;
F_228 ( & V_149 -> V_230 ) ;
break;
}
V_175:
F_175 ( & V_141 -> V_329 ) ;
return V_149 ;
}
static void F_229 ( struct V_6 * V_7 )
{
struct V_307 V_308 = {
. V_309 = V_333 ,
. V_311 = V_312 ,
. V_313 = V_7 -> V_85 ,
. V_315 = 8 ,
. V_316 = V_317 ,
. V_318 . V_319 = F_34 ( V_7 ) ,
} ;
F_230 ( & V_308 . V_322 , F_191 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_225 ( & V_308 ) ;
}
static struct V_4 * F_231 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
return F_30 ( - V_102 ) ;
if ( V_5 -> V_39 . V_171 )
return F_30 ( - V_172 ) ;
if ( ! ( V_7 -> V_50 & V_52 ) )
F_229 ( V_7 ) ;
return V_5 ;
}
static void F_232 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_217 V_160 , V_217 V_161 ,
bool V_334 , unsigned long V_211 )
{
T_1 V_50 ;
struct V_9 * V_201 ;
F_170 ( & V_5 -> V_36 ) ;
F_86 (ift, &idev->tempaddr_list, tmp_list) {
int V_206 , V_335 , V_336 ;
if ( V_10 != V_201 -> V_198 )
continue;
V_206 = ( V_211 - V_201 -> V_1 ) / V_3 ;
V_335 = V_5 -> V_39 . V_218 - V_206 ;
if ( V_335 < 0 )
V_335 = 0 ;
V_336 = V_5 -> V_39 . V_219 -
V_5 -> V_39 . V_220 - V_206 ;
if ( V_336 < 0 )
V_336 = 0 ;
if ( V_160 > V_335 )
V_160 = V_335 ;
if ( V_161 > V_336 )
V_161 = V_336 ;
F_116 ( & V_201 -> V_36 ) ;
V_50 = V_201 -> V_50 ;
V_201 -> V_160 = V_160 ;
V_201 -> V_161 = V_161 ;
V_201 -> V_70 = V_211 ;
if ( V_161 > 0 )
V_201 -> V_50 &= ~ V_240 ;
F_125 ( & V_201 -> V_36 ) ;
if ( ! ( V_50 & V_137 ) )
F_149 ( 0 , V_201 ) ;
}
if ( ( V_334 || F_233 ( & V_5 -> V_59 ) ) &&
V_5 -> V_39 . V_65 > 0 ) {
F_175 ( & V_5 -> V_36 ) ;
F_151 ( V_10 , NULL ) ;
} else {
F_175 ( & V_5 -> V_36 ) ;
}
}
void F_234 ( struct V_6 * V_7 , T_3 * V_337 , int V_133 , bool V_338 )
{
struct V_339 * V_340 ;
V_217 V_160 ;
V_217 V_161 ;
int V_164 ;
struct V_4 * V_112 ;
struct V_101 * V_101 = F_34 ( V_7 ) ;
V_340 = (struct V_339 * ) V_337 ;
if ( V_133 < sizeof( struct V_339 ) ) {
F_38 ( L_17 ) ;
return;
}
V_164 = F_114 ( & V_340 -> V_341 ) ;
if ( V_164 & ( V_166 | V_342 ) )
return;
V_160 = F_235 ( V_340 -> V_343 ) ;
V_161 = F_235 ( V_340 -> V_344 ) ;
if ( V_161 > V_160 ) {
F_236 ( L_18 ) ;
return;
}
V_112 = F_237 ( V_7 ) ;
if ( V_112 == NULL ) {
F_238 ( L_19 ,
V_7 -> V_48 ) ;
return;
}
if ( V_340 -> V_271 ) {
struct V_162 * V_149 ;
unsigned long V_345 ;
if ( V_3 > V_346 )
V_345 = F_134 ( V_160 , V_3 ) ;
else
V_345 = F_134 ( V_160 , V_346 ) ;
if ( F_239 ( V_345 ) )
V_345 *= V_3 ;
V_149 = F_137 ( & V_340 -> V_341 ,
V_340 -> V_178 ,
V_7 ,
V_347 | V_348 ,
V_194 | V_195 ) ;
if ( V_149 ) {
if ( V_160 == 0 ) {
F_138 ( V_149 ) ;
V_149 = NULL ;
} else if ( F_239 ( V_345 ) ) {
F_139 ( V_149 , V_13 + V_345 ) ;
} else {
F_240 ( V_149 ) ;
}
} else if ( V_160 ) {
T_5 V_185 = 0 ;
int V_50 = V_347 | V_348 ;
if ( F_239 ( V_345 ) ) {
V_50 |= V_197 ;
V_185 = F_241 ( V_345 ) ;
}
F_224 ( & V_340 -> V_341 , V_340 -> V_178 ,
V_7 , V_185 , V_50 ) ;
}
F_103 ( V_149 ) ;
}
if ( V_340 -> V_349 && V_112 -> V_39 . V_349 ) {
struct V_9 * V_10 ;
struct V_155 V_153 ;
int V_334 = 0 , V_350 = 0 ;
bool V_179 = false ;
if ( V_340 -> V_178 == 64 ) {
memcpy ( & V_153 , & V_340 -> V_341 , 8 ) ;
if ( ! F_198 ( & V_112 -> V_66 ) ) {
F_170 ( & V_112 -> V_36 ) ;
memcpy ( V_153 . V_212 + 8 ,
V_112 -> V_66 . V_212 + 8 , 8 ) ;
F_175 ( & V_112 -> V_36 ) ;
V_179 = true ;
} else if ( F_192 ( V_153 . V_212 + 8 , V_7 ) &&
F_221 ( V_153 . V_212 + 8 , V_112 ) ) {
F_100 ( V_112 ) ;
return;
}
goto V_351;
}
F_238 ( L_20 ,
V_340 -> V_178 ) ;
F_100 ( V_112 ) ;
return;
V_351:
V_10 = F_185 ( V_101 , & V_153 , V_7 , 1 ) ;
if ( V_10 == NULL && V_160 ) {
int V_352 = V_112 -> V_39 . V_352 ;
T_1 V_210 = 0 ;
#ifdef F_242
if ( V_112 -> V_39 . V_353 &&
! V_101 -> V_18 . V_115 -> V_45 && V_338 )
V_210 = V_224 ;
#endif
if ( ! V_352 ||
F_179 ( V_112 ) < V_352 )
V_10 = F_113 ( V_112 , & V_153 , NULL ,
V_340 -> V_178 ,
V_164 & V_354 ,
V_210 , V_160 ,
V_161 ) ;
if ( F_243 ( V_10 ) ) {
F_100 ( V_112 ) ;
return;
}
V_350 = 0 ;
V_334 = 1 ;
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 |= V_355 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_179 = V_179 ;
F_142 ( & V_10 -> V_36 ) ;
F_156 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_50 ;
unsigned long V_211 ;
T_1 V_356 ;
F_116 ( & V_10 -> V_36 ) ;
V_211 = V_13 ;
if ( V_10 -> V_160 > ( V_211 - V_10 -> V_70 ) / V_3 )
V_356 = V_10 -> V_160 - ( V_211 - V_10 -> V_70 ) / V_3 ;
else
V_356 = 0 ;
if ( ! V_350 && ! V_334 && V_356 ) {
const T_1 V_357 = F_244 (
V_356 , ( T_1 ) V_358 ) ;
V_160 = F_245 ( V_160 , V_357 ) ;
V_350 = 1 ;
}
if ( V_350 ) {
V_10 -> V_160 = V_160 ;
V_10 -> V_161 = V_161 ;
V_10 -> V_70 = V_211 ;
V_50 = V_10 -> V_50 ;
V_10 -> V_50 &= ~ V_240 ;
F_125 ( & V_10 -> V_36 ) ;
if ( ! ( V_50 & V_137 ) )
F_149 ( 0 , V_10 ) ;
} else
F_125 ( & V_10 -> V_36 ) ;
F_232 ( V_112 , V_10 , V_160 , V_161 ,
V_334 , V_211 ) ;
F_146 ( V_10 ) ;
F_246 () ;
}
}
F_247 ( V_359 , V_112 , V_340 ) ;
F_100 ( V_112 ) ;
}
int F_248 ( struct V_101 * V_101 , void T_6 * V_360 )
{
struct V_361 V_362 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_249 () ;
V_32 = - V_363 ;
if ( F_250 ( & V_362 , V_360 , sizeof( struct V_361 ) ) )
goto V_364;
V_7 = F_74 ( V_101 , V_362 . V_365 ) ;
V_32 = - V_169 ;
if ( V_7 == NULL )
goto V_364;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 ) {
const struct V_366 * V_367 = V_7 -> V_368 ;
struct V_369 V_370 ;
struct V_371 V_142 ;
V_32 = - V_168 ;
if ( ! ( F_114 ( & V_362 . V_372 ) & V_226 ) )
goto V_364;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_373 . V_255 = V_362 . V_372 . V_278 [ 3 ] ;
V_142 . V_373 . V_256 = 0 ;
V_142 . V_373 . V_374 = 4 ;
V_142 . V_373 . V_375 = 5 ;
V_142 . V_373 . V_376 = V_377 ;
V_142 . V_373 . V_378 = 64 ;
V_370 . V_379 . V_380 = ( V_381 void T_6 * ) & V_142 ;
if ( V_367 -> V_382 ) {
T_7 V_383 = F_251 () ;
F_252 ( V_384 ) ;
V_32 = V_367 -> V_382 ( V_7 , & V_370 , V_385 ) ;
F_252 ( V_383 ) ;
} else
V_32 = - V_386 ;
if ( V_32 == 0 ) {
V_32 = - V_102 ;
V_7 = F_253 ( V_101 , V_142 . V_48 ) ;
if ( ! V_7 )
goto V_364;
V_32 = F_254 ( V_7 ) ;
}
}
#endif
V_364:
F_94 () ;
return V_32 ;
}
static int F_255 ( struct V_101 * V_101 , int V_85 ,
const struct V_155 * V_305 ,
const struct V_155 * V_387 ,
unsigned int V_306 , V_217 V_388 ,
V_217 V_161 , V_217 V_160 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_159 ;
T_1 V_50 ;
T_5 V_185 ;
unsigned long V_389 ;
F_29 () ;
if ( V_306 > 128 )
return - V_35 ;
if ( ! V_160 || V_161 > V_160 )
return - V_35 ;
if ( V_388 & V_355 && V_306 != 64 )
return - V_35 ;
V_7 = F_74 ( V_101 , V_85 ) ;
if ( ! V_7 )
return - V_169 ;
V_5 = F_231 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_119 ( V_5 ) ;
V_159 = F_155 ( V_305 ) ;
V_389 = F_134 ( V_160 , V_3 ) ;
if ( F_239 ( V_389 ) ) {
V_185 = F_241 ( V_389 * V_3 ) ;
V_160 = V_389 ;
V_50 = V_197 ;
} else {
V_185 = 0 ;
V_50 = 0 ;
V_388 |= V_189 ;
}
V_389 = F_134 ( V_161 , V_3 ) ;
if ( F_239 ( V_389 ) ) {
if ( V_389 == 0 )
V_388 |= V_240 ;
V_161 = V_389 ;
}
V_10 = F_113 ( V_5 , V_305 , V_387 , V_306 , V_159 , V_388 ,
V_160 , V_161 ) ;
if ( ! F_52 ( V_10 ) ) {
if ( ! ( V_388 & V_190 ) ) {
F_224 ( & V_10 -> V_153 , V_10 -> V_178 , V_7 ,
V_185 , V_50 ) ;
}
F_156 ( V_10 ) ;
if ( V_388 & V_355 )
F_232 ( V_5 , V_10 , V_160 , V_161 ,
true , V_13 ) ;
F_146 ( V_10 ) ;
F_256 () ;
return 0 ;
}
return F_119 ( V_10 ) ;
}
static int F_257 ( struct V_101 * V_101 , int V_85 , T_1 V_388 ,
const struct V_155 * V_305 , unsigned int V_306 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_306 > 128 )
return - V_35 ;
V_7 = F_74 ( V_101 , V_85 ) ;
if ( ! V_7 )
return - V_169 ;
if ( ( V_5 = F_51 ( V_7 ) ) == NULL )
return - V_390 ;
F_170 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_178 == V_306 &&
F_160 ( V_305 , & V_10 -> V_153 ) ) {
F_18 ( V_10 ) ;
F_175 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_181 ) &&
( V_388 & V_355 ) )
F_232 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_140 ( V_10 ) ;
F_256 () ;
return 0 ;
}
}
F_175 ( & V_5 -> V_36 ) ;
return - V_168 ;
}
int F_258 ( struct V_101 * V_101 , void T_6 * V_360 )
{
struct V_361 V_362 ;
int V_32 ;
if ( ! F_259 ( V_101 -> V_391 , V_392 ) )
return - V_393 ;
if ( F_250 ( & V_362 , V_360 , sizeof( struct V_361 ) ) )
return - V_363 ;
F_249 () ;
V_32 = F_255 ( V_101 , V_362 . V_365 , & V_362 . V_372 , NULL ,
V_362 . V_394 , V_189 ,
V_395 , V_395 ) ;
F_94 () ;
return V_32 ;
}
int F_260 ( struct V_101 * V_101 , void T_6 * V_360 )
{
struct V_361 V_362 ;
int V_32 ;
if ( ! F_259 ( V_101 -> V_391 , V_392 ) )
return - V_393 ;
if ( F_250 ( & V_362 , V_360 , sizeof( struct V_361 ) ) )
return - V_363 ;
F_249 () ;
V_32 = F_257 ( V_101 , V_362 . V_365 , 0 , & V_362 . V_372 ,
V_362 . V_394 ) ;
F_94 () ;
return V_32 ;
}
static void F_261 ( struct V_4 * V_5 , const struct V_155 * V_153 ,
int V_306 , int V_159 )
{
struct V_9 * V_10 ;
V_10 = F_113 ( V_5 , V_153 , NULL , V_306 ,
V_159 , V_189 ,
V_395 , V_395 ) ;
if ( ! F_52 ( V_10 ) ) {
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 &= ~ V_137 ;
F_142 ( & V_10 -> V_36 ) ;
F_149 ( V_396 , V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_262 ( struct V_4 * V_5 )
{
struct V_155 V_153 ;
struct V_6 * V_7 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_159 , V_306 ;
T_1 V_397 = 0 ;
F_29 () ;
memset ( & V_153 , 0 , sizeof( struct V_155 ) ) ;
memcpy ( & V_153 . V_278 [ 3 ] , V_5 -> V_7 -> V_284 , 4 ) ;
if ( V_5 -> V_7 -> V_50 & V_323 ) {
V_153 . V_278 [ 0 ] = F_191 ( 0xfe800000 ) ;
V_159 = V_267 ;
V_306 = 64 ;
} else {
V_159 = V_226 ;
V_306 = 96 ;
V_397 |= V_324 ;
}
if ( V_153 . V_278 [ 3 ] ) {
F_261 ( V_5 , & V_153 , V_306 , V_159 ) ;
F_224 ( & V_153 , V_306 , V_5 -> V_7 , 0 , V_397 ) ;
return;
}
F_90 (net, dev) {
struct V_398 * V_399 = F_263 ( V_7 ) ;
if ( V_399 && ( V_7 -> V_50 & V_77 ) ) {
struct V_400 * V_134 ;
int V_401 = V_159 ;
for ( V_134 = V_399 -> V_402 ; V_134 ; V_134 = V_134 -> V_403 ) {
V_153 . V_278 [ 3 ] = V_134 -> V_404 ;
if ( V_134 -> V_405 == V_406 )
continue;
if ( V_134 -> V_405 >= V_407 ) {
if ( V_5 -> V_7 -> V_50 & V_323 )
continue;
V_401 |= V_270 ;
}
F_261 ( V_5 , & V_153 , V_306 , V_401 ) ;
F_224 ( & V_153 , V_306 , V_5 -> V_7 , 0 ,
V_397 ) ;
}
}
}
}
static void F_264 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_408 ;
struct V_9 * V_409 ;
struct V_162 * V_410 ;
F_29 () ;
if ( ( V_5 = F_50 ( V_7 ) ) == NULL ) {
F_99 ( L_21 , V_47 ) ;
return;
}
F_261 ( V_5 , & V_411 , 128 , V_270 ) ;
F_90 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_408 -> V_48 , V_7 -> V_48 ) )
continue;
V_5 = F_51 ( V_408 ) ;
if ( ! V_5 )
continue;
F_170 ( & V_5 -> V_36 ) ;
F_86 (sp_ifa, &idev->addr_list, if_list) {
if ( V_409 -> V_50 & ( V_274 | V_137 ) )
continue;
if ( V_409 -> V_149 ) {
if ( V_409 -> V_149 -> V_230 . V_412 > 0 ) {
F_103 ( V_409 -> V_149 ) ;
V_409 -> V_149 = NULL ;
} else {
continue;
}
}
V_410 = F_118 ( V_5 , & V_409 -> V_153 , false ) ;
if ( ! F_52 ( V_410 ) ) {
V_409 -> V_149 = V_410 ;
F_265 ( V_410 ) ;
}
}
F_175 ( & V_5 -> V_36 ) ;
}
}
static void F_266 ( struct V_4 * V_5 , const struct V_155 * V_153 )
{
struct V_9 * V_10 ;
T_1 V_210 = V_189 ;
#ifdef F_242
if ( V_5 -> V_39 . V_353 &&
! F_34 ( V_5 -> V_7 ) -> V_18 . V_115 -> V_45 )
V_210 |= V_224 ;
#endif
V_10 = F_113 ( V_5 , V_153 , NULL , 64 , V_267 , V_210 ,
V_395 , V_395 ) ;
if ( ! F_52 ( V_10 ) ) {
F_224 ( & V_10 -> V_153 , V_10 -> V_178 , V_5 -> V_7 , 0 , 0 ) ;
F_156 ( V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_267 ( struct V_4 * V_5 , bool V_413 )
{
if ( V_5 -> V_414 == V_415 ) {
struct V_155 V_153 ;
F_230 ( & V_153 , F_191 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( F_192 ( V_153 . V_212 + 8 , V_5 -> V_7 ) == 0 )
F_266 ( V_5 , & V_153 ) ;
else if ( V_413 )
F_224 ( & V_153 , 64 , V_5 -> V_7 , 0 , 0 ) ;
}
}
static void F_268 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_295 ) &&
( V_7 -> type != V_296 ) &&
( V_7 -> type != V_297 ) &&
( V_7 -> type != V_298 ) &&
( V_7 -> type != V_301 ) &&
( V_7 -> type != V_302 ) &&
( V_7 -> type != V_63 ) &&
( V_7 -> type != V_300 ) ) {
return;
}
V_5 = F_231 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return;
F_267 ( V_5 , false ) ;
}
static void F_269 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_50 ( V_7 ) ) == NULL ) {
F_99 ( L_21 , V_47 ) ;
return;
}
if ( V_7 -> V_56 & V_57 ) {
F_267 ( V_5 , false ) ;
return;
}
F_262 ( V_5 ) ;
if ( V_7 -> V_50 & V_323 )
F_229 ( V_7 ) ;
}
static void F_270 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_50 ( V_7 ) ) == NULL ) {
F_99 ( L_21 , V_47 ) ;
return;
}
F_267 ( V_5 , true ) ;
}
static int F_271 ( struct V_416 * V_417 , unsigned long V_90 ,
void * V_418 )
{
struct V_6 * V_7 = F_272 ( V_418 ) ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
int V_419 = 0 ;
int V_32 ;
switch ( V_90 ) {
case V_420 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_273 ( F_119 ( V_5 ) ) ;
}
break;
case V_183 :
case V_421 :
if ( V_7 -> V_50 & V_422 )
break;
if ( V_90 == V_183 ) {
if ( ! F_4 ( V_7 ) ) {
F_43 ( L_22 ,
V_7 -> V_48 ) ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 )
V_5 = F_28 ( V_7 ) ;
if ( ! F_243 ( V_5 ) ) {
V_5 -> V_68 |= V_69 ;
V_419 = 1 ;
}
} else {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_68 & V_69 )
break;
V_5 -> V_68 |= V_69 ;
}
F_43 ( L_23 ,
V_7 -> V_48 ) ;
V_419 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_54 )
case V_55 :
F_269 ( V_7 ) ;
break;
#endif
#if F_42 ( V_423 )
case V_299 :
F_270 ( V_7 ) ;
break;
#endif
case V_424 :
F_264 ( V_7 ) ;
break;
default:
F_268 ( V_7 ) ;
break;
}
if ( ! F_243 ( V_5 ) ) {
if ( V_419 )
F_274 ( V_5 ) ;
if ( V_5 -> V_39 . V_41 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_275 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
}
V_5 -> V_70 = V_13 ;
F_276 ( V_425 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_277 ( V_7 , 1 ) ;
}
break;
case V_426 :
if ( V_5 && V_7 -> V_33 >= V_34 ) {
F_275 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! F_52 ( V_5 ) )
break;
}
case V_200 :
case V_427 :
F_277 ( V_7 , V_90 != V_200 ) ;
break;
case V_428 :
if ( V_5 ) {
F_278 ( V_5 ) ;
F_3 ( V_5 ) ;
V_32 = F_2 ( V_5 ) ;
if ( V_32 )
return F_273 ( V_32 ) ;
V_32 = F_41 ( V_5 ) ;
if ( V_32 ) {
F_3 ( V_5 ) ;
return F_273 ( V_32 ) ;
}
}
break;
case V_429 :
case V_430 :
F_279 ( V_7 , V_90 ) ;
break;
}
return V_431 ;
}
static void F_279 ( struct V_6 * V_7 , unsigned long V_90 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_90 == V_430 )
F_280 ( V_5 ) ;
else if ( V_90 == V_429 )
F_281 ( V_5 ) ;
}
static int F_277 ( struct V_6 * V_7 , int V_432 )
{
struct V_101 * V_101 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_134 ;
int V_147 , V_16 ;
F_29 () ;
F_282 ( V_101 , V_7 ) ;
F_283 ( & V_44 , V_7 ) ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 == NULL )
return - V_169 ;
if ( V_432 ) {
V_5 -> V_76 = 1 ;
F_284 ( V_7 -> V_71 , NULL ) ;
F_278 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_433 ; V_16 ++ ) {
struct V_124 * V_120 = & V_180 [ V_16 ] ;
F_141 ( & V_173 ) ;
V_434:
F_80 (ifa, h, addr_lst) {
if ( V_134 -> V_5 == V_5 ) {
F_143 ( & V_134 -> V_146 ) ;
F_9 ( V_134 ) ;
goto V_434;
}
}
F_142 ( & V_173 ) ;
}
F_144 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_432 )
V_5 -> V_68 &= ~ ( V_435 | V_436 | V_69 ) ;
if ( V_432 && F_7 ( & V_5 -> V_60 ) )
F_100 ( V_5 ) ;
while ( ! F_233 ( & V_5 -> V_59 ) ) {
V_134 = F_285 ( & V_5 -> V_59 ,
struct V_9 , V_182 ) ;
F_145 ( & V_134 -> V_182 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_141 ( & V_134 -> V_36 ) ;
if ( V_134 -> V_198 ) {
F_146 ( V_134 -> V_198 ) ;
V_134 -> V_198 = NULL ;
}
F_142 ( & V_134 -> V_36 ) ;
F_146 ( V_134 ) ;
F_144 ( & V_5 -> V_36 ) ;
}
while ( ! F_233 ( & V_5 -> V_37 ) ) {
V_134 = F_285 ( & V_5 -> V_37 ,
struct V_9 , V_154 ) ;
F_9 ( V_134 ) ;
F_145 ( & V_134 -> V_154 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_141 ( & V_134 -> V_176 ) ;
V_147 = V_134 -> V_147 ;
V_134 -> V_147 = V_148 ;
F_142 ( & V_134 -> V_176 ) ;
if ( V_147 != V_148 ) {
F_286 ( V_199 , V_134 ) ;
F_131 ( V_200 , V_134 ) ;
}
F_146 ( V_134 ) ;
F_144 ( & V_5 -> V_36 ) ;
}
F_148 ( & V_5 -> V_36 ) ;
if ( V_432 ) {
F_287 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_288 ( V_5 ) ;
}
V_5 -> V_70 = V_13 ;
if ( V_432 ) {
F_3 ( V_5 ) ;
F_39 ( & V_44 , V_5 -> V_43 ) ;
F_283 ( & V_44 , V_7 ) ;
F_100 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_304 )
{
struct V_4 * V_5 = (struct V_4 * ) V_304 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_155 V_437 ;
F_126 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 || ! ( V_5 -> V_68 & V_69 ) )
goto V_175;
if ( ! F_289 ( V_5 ) )
goto V_175;
if ( V_5 -> V_68 & V_436 )
goto V_175;
if ( V_5 -> V_438 ++ < V_5 -> V_39 . V_58 ) {
F_128 ( & V_5 -> V_36 ) ;
if ( ! F_178 ( V_7 , & V_437 , V_137 ) )
F_290 ( V_7 , & V_437 ,
& V_75 ) ;
else
goto V_439;
F_126 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_438 ==
V_5 -> V_39 . V_58 ) ?
V_5 -> V_39 . V_440 :
V_5 -> V_39 . V_441 ) ;
} else {
F_99 ( L_24 , V_5 -> V_7 -> V_48 ) ;
}
V_175:
F_128 ( & V_5 -> V_36 ) ;
V_439:
F_100 ( V_5 ) ;
}
static void F_291 ( struct V_9 * V_10 )
{
unsigned long V_442 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_50 & V_224 )
V_442 = 0 ;
else
V_442 = F_292 () % ( V_5 -> V_39 . V_440 ? : 1 ) ;
V_10 -> V_443 = V_5 -> V_39 . V_221 ;
F_16 ( V_10 , V_442 ) ;
}
static void F_293 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_193 ( V_7 , & V_10 -> V_153 ) ;
F_294 ( ( V_381 T_1 ) V_10 -> V_153 . V_278 [ 3 ] ) ;
F_170 ( & V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 == V_148 )
goto V_175;
if ( V_7 -> V_50 & ( V_51 | V_52 ) ||
V_5 -> V_39 . V_53 < 1 ||
! ( V_10 -> V_50 & V_137 ) ||
V_10 -> V_50 & V_444 ) {
V_10 -> V_50 &= ~ ( V_137 | V_224 | V_274 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_175 ( & V_5 -> V_36 ) ;
F_295 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_68 & V_69 ) ) {
F_125 ( & V_10 -> V_36 ) ;
F_175 ( & V_5 -> V_36 ) ;
F_18 ( V_10 ) ;
F_187 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_50 & V_224 )
F_265 ( V_10 -> V_149 ) ;
F_291 ( V_10 ) ;
V_175:
F_125 ( & V_10 -> V_36 ) ;
F_175 ( & V_5 -> V_36 ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
bool V_445 = false ;
F_141 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_147 != V_148 ) {
V_10 -> V_147 = V_446 ;
V_445 = true ;
}
F_142 ( & V_10 -> V_176 ) ;
if ( V_445 )
F_16 ( V_10 , 0 ) ;
}
static void V_177 ( struct V_447 * V_448 )
{
struct V_9 * V_10 = F_296 ( F_297 ( V_448 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_155 V_449 ;
enum {
V_450 ,
V_451 ,
V_452 ,
} V_187 = V_450 ;
F_249 () ;
F_141 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_147 == V_446 ) {
V_187 = V_451 ;
V_10 -> V_147 = V_276 ;
} else if ( V_10 -> V_147 == V_279 ) {
V_187 = V_452 ;
V_10 -> V_147 = V_277 ;
}
F_142 ( & V_10 -> V_176 ) ;
if ( V_187 == V_451 ) {
F_293 ( V_10 ) ;
goto V_175;
} else if ( V_187 == V_452 ) {
F_187 ( V_10 , 1 ) ;
goto V_175;
}
if ( ! V_10 -> V_443 && F_188 ( V_10 ) )
goto V_175;
F_144 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 || ! ( V_5 -> V_68 & V_69 ) ) {
F_148 ( & V_5 -> V_36 ) ;
goto V_175;
}
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 == V_148 ) {
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
goto V_175;
}
if ( V_10 -> V_443 == 0 ) {
V_10 -> V_50 &= ~ ( V_137 | V_224 | V_274 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_295 ( V_10 ) ;
goto V_175;
}
V_10 -> V_443 -- ;
F_16 ( V_10 ,
F_154 ( V_10 -> V_5 -> V_43 , V_222 ) ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_194 ( & V_10 -> V_153 , & V_449 ) ;
F_298 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_153 , & V_449 , & V_67 ) ;
V_175:
F_146 ( V_10 ) ;
F_94 () ;
}
static bool F_299 ( struct V_9 * V_10 )
{
struct V_9 * V_453 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_177 (ifpiter, &idev->addr_list, if_list) {
if ( V_453 -> V_159 > V_267 )
break;
if ( V_10 != V_453 && V_453 -> V_159 == V_267 &&
( V_453 -> V_50 & ( V_189 | V_137 |
V_224 | V_274 ) ) ==
V_189 )
return false ;
}
return true ;
}
static void F_295 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_155 V_437 ;
bool V_454 , V_455 ;
F_9 ( V_10 ) ;
F_149 ( V_396 , V_10 ) ;
F_170 ( & V_10 -> V_5 -> V_36 ) ;
V_455 = V_10 -> V_159 == V_267 && F_299 ( V_10 ) ;
V_454 = V_455 &&
F_289 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_58 > 0 &&
( V_7 -> V_50 & V_52 ) == 0 ;
F_175 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_455 )
F_300 ( V_10 -> V_5 ) ;
if ( V_454 ) {
if ( F_178 ( V_7 , & V_437 , V_137 ) )
return;
F_290 ( V_7 , & V_437 , & V_75 ) ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_438 = 1 ;
V_10 -> V_5 -> V_68 |= V_435 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_441 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_274 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_170 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_50 & V_137 &&
V_10 -> V_147 == V_276 )
F_291 ( V_10 ) ;
F_125 ( & V_10 -> V_36 ) ;
}
F_175 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_301 ( struct V_456 * V_89 , T_8 V_457 )
{
struct V_9 * V_134 = NULL ;
struct V_458 * V_147 = V_89 -> V_459 ;
struct V_101 * V_101 = F_302 ( V_89 ) ;
int V_142 = 0 ;
if ( V_457 == 0 ) {
V_147 -> V_460 = 0 ;
V_147 -> V_461 = 0 ;
}
for (; V_147 -> V_460 < V_433 ; ++ V_147 -> V_460 ) {
F_186 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_181 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( V_142 < V_147 -> V_461 ) {
V_142 ++ ;
continue;
}
V_147 -> V_461 ++ ;
return V_134 ;
}
V_147 -> V_461 = 0 ;
V_142 = 0 ;
}
return NULL ;
}
static struct V_9 * F_303 ( struct V_456 * V_89 ,
struct V_9 * V_134 )
{
struct V_458 * V_147 = V_89 -> V_459 ;
struct V_101 * V_101 = F_302 ( V_89 ) ;
F_304 (ifa, addr_lst) {
if ( ! F_181 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_461 ++ ;
return V_134 ;
}
while ( ++ V_147 -> V_460 < V_433 ) {
V_147 -> V_461 = 0 ;
F_186 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_181 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_461 ++ ;
return V_134 ;
}
}
return NULL ;
}
static void * F_305 ( struct V_456 * V_89 , T_8 * V_457 )
__acquires( T_9 )
{
F_115 () ;
return F_301 ( V_89 , * V_457 ) ;
}
static void * F_306 ( struct V_456 * V_89 , void * V_462 , T_8 * V_457 )
{
struct V_9 * V_134 ;
V_134 = F_303 ( V_89 , V_462 ) ;
++ * V_457 ;
return V_134 ;
}
static void F_307 ( struct V_456 * V_89 , void * V_462 )
__releases( T_9 )
{
F_129 () ;
}
static int F_308 ( struct V_456 * V_89 , void * V_462 )
{
struct V_9 * V_10 = (struct V_9 * ) V_462 ;
F_309 ( V_89 , L_25 ,
& V_10 -> V_153 ,
V_10 -> V_5 -> V_7 -> V_85 ,
V_10 -> V_178 ,
V_10 -> V_159 ,
( T_3 ) V_10 -> V_50 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
return 0 ;
}
static int F_310 ( struct V_463 * V_463 , struct V_464 * V_464 )
{
return F_311 ( V_463 , V_464 , & V_465 ,
sizeof( struct V_458 ) ) ;
}
static int T_10 F_312 ( struct V_101 * V_101 )
{
if ( ! F_313 ( L_26 , V_466 , V_101 -> V_467 , & V_468 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_314 ( struct V_101 * V_101 )
{
F_315 ( L_26 , V_101 -> V_467 ) ;
}
int T_12 F_316 ( void )
{
return F_317 ( & V_469 ) ;
}
void F_318 ( void )
{
F_319 ( & V_469 ) ;
}
int F_320 ( struct V_101 * V_101 , const struct V_155 * V_153 )
{
int V_209 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_186 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_181 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_160 ( & V_10 -> V_153 , V_153 ) &&
( V_10 -> V_50 & V_245 ) ) {
V_209 = 1 ;
break;
}
}
F_129 () ;
return V_209 ;
}
static void F_256 ( void )
{
unsigned long V_211 , V_470 , V_471 , V_472 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_115 () ;
V_211 = V_13 ;
V_470 = F_321 ( V_211 + V_473 ) ;
F_10 ( & V_474 ) ;
for ( V_16 = 0 ; V_16 < V_433 ; V_16 ++ ) {
V_434:
F_186 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_206 ;
if ( ( V_10 -> V_50 & V_189 ) &&
( V_10 -> V_161 == V_395 ) )
continue;
F_116 ( & V_10 -> V_36 ) ;
V_206 = ( V_211 - V_10 -> V_70 + V_223 ) / V_3 ;
if ( V_10 -> V_160 != V_395 &&
V_206 >= V_10 -> V_160 ) {
F_125 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_140 ( V_10 ) ;
goto V_434;
} else if ( V_10 -> V_161 == V_395 ) {
F_125 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_206 >= V_10 -> V_161 ) {
int V_475 = 0 ;
if ( ! ( V_10 -> V_50 & V_240 ) ) {
V_475 = 1 ;
V_10 -> V_50 |= V_240 ;
}
if ( ( V_10 -> V_160 != V_395 ) &&
( F_135 ( V_10 -> V_70 + V_10 -> V_160 * V_3 , V_470 ) ) )
V_470 = V_10 -> V_70 + V_10 -> V_160 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
if ( V_475 ) {
F_18 ( V_10 ) ;
F_149 ( 0 , V_10 ) ;
F_146 ( V_10 ) ;
goto V_434;
}
} else if ( ( V_10 -> V_50 & V_181 ) &&
! ( V_10 -> V_50 & V_137 ) ) {
unsigned long V_207 = V_10 -> V_5 -> V_39 . V_215 *
V_10 -> V_5 -> V_39 . V_221 *
F_154 ( V_10 -> V_5 -> V_43 , V_222 ) / V_3 ;
if ( V_206 >= V_10 -> V_161 - V_207 ) {
struct V_9 * V_198 = V_10 -> V_198 ;
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_470 ) )
V_470 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
if ( ! V_10 -> V_214 && V_198 ) {
V_10 -> V_214 ++ ;
F_18 ( V_10 ) ;
F_18 ( V_198 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_116 ( & V_198 -> V_36 ) ;
V_198 -> V_214 = 0 ;
F_125 ( & V_198 -> V_36 ) ;
F_151 ( V_198 , V_10 ) ;
F_146 ( V_198 ) ;
F_146 ( V_10 ) ;
goto V_434;
}
} else if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 - V_207 * V_3 , V_470 ) )
V_470 = V_10 -> V_70 + V_10 -> V_161 * V_3 - V_207 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
} else {
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_470 ) )
V_470 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
}
}
}
V_471 = F_321 ( V_470 ) ;
V_472 = V_470 ;
if ( F_135 ( V_471 , V_470 + V_476 ) )
V_472 = V_471 ;
if ( F_135 ( V_472 , V_13 + V_477 ) )
V_472 = V_13 + V_477 ;
F_38 ( V_261 L_27 ,
V_211 , V_470 , V_471 , V_472 ) ;
F_19 ( V_15 , & V_474 , V_472 - V_211 ) ;
F_129 () ;
}
static void F_322 ( struct V_447 * V_448 )
{
F_249 () ;
F_256 () ;
F_94 () ;
}
static void F_246 ( void )
{
F_19 ( V_15 , & V_474 , 0 ) ;
}
static struct V_155 * F_323 ( struct V_109 * V_153 , struct V_109 * V_478 ,
struct V_155 * * V_387 )
{
struct V_155 * V_305 = NULL ;
* V_387 = NULL ;
if ( V_153 )
V_305 = F_324 ( V_153 ) ;
if ( V_478 ) {
if ( V_305 && F_325 ( V_478 , V_305 , sizeof( * V_305 ) ) )
* V_387 = V_305 ;
V_305 = F_324 ( V_478 ) ;
}
return V_305 ;
}
static int
F_326 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_479 * V_480 ;
struct V_109 * V_110 [ V_481 + 1 ] ;
struct V_155 * V_305 , * V_387 ;
T_1 V_388 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_480 ) , V_110 , V_481 , V_482 ) ;
if ( V_32 < 0 )
return V_32 ;
V_480 = F_60 ( V_92 ) ;
V_305 = F_323 ( V_110 [ V_483 ] , V_110 [ V_484 ] , & V_387 ) ;
if ( V_305 == NULL )
return - V_35 ;
V_388 = V_110 [ V_485 ] ? F_327 ( V_110 [ V_485 ] ) : V_480 -> V_388 ;
V_388 &= V_355 ;
return F_257 ( V_101 , V_480 -> V_486 , V_388 , V_305 ,
V_480 -> V_487 ) ;
}
static int F_328 ( struct V_9 * V_10 , T_1 V_388 ,
T_1 V_161 , T_1 V_160 )
{
T_1 V_50 ;
T_5 V_185 ;
unsigned long V_389 ;
bool V_488 ;
bool V_489 ;
F_29 () ;
if ( ! V_160 || ( V_161 > V_160 ) )
return - V_35 ;
if ( V_388 & V_355 &&
( V_10 -> V_50 & V_181 || V_10 -> V_178 != 64 ) )
return - V_35 ;
V_389 = F_134 ( V_160 , V_3 ) ;
if ( F_239 ( V_389 ) ) {
V_185 = F_241 ( V_389 * V_3 ) ;
V_160 = V_389 ;
V_50 = V_197 ;
} else {
V_185 = 0 ;
V_50 = 0 ;
V_388 |= V_189 ;
}
V_389 = F_134 ( V_161 , V_3 ) ;
if ( F_239 ( V_389 ) ) {
if ( V_389 == 0 )
V_388 |= V_240 ;
V_161 = V_389 ;
}
F_141 ( & V_10 -> V_36 ) ;
V_488 = V_10 -> V_50 & V_355 ;
V_489 = V_10 -> V_50 & V_189 &&
! ( V_10 -> V_50 & V_190 ) ;
V_10 -> V_50 &= ~ ( V_240 | V_189 | V_444 |
V_245 | V_355 |
V_190 ) ;
V_10 -> V_50 |= V_388 ;
V_10 -> V_70 = V_13 ;
V_10 -> V_160 = V_160 ;
V_10 -> V_161 = V_161 ;
F_142 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_137 ) )
F_149 ( 0 , V_10 ) ;
if ( ! ( V_388 & V_190 ) ) {
F_224 ( & V_10 -> V_153 , V_10 -> V_178 , V_10 -> V_5 -> V_7 ,
V_185 , V_50 ) ;
} else if ( V_489 ) {
enum V_184 V_187 ;
unsigned long V_345 ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
V_187 = F_132 ( V_10 , & V_345 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_187 != V_191 ) {
F_136 ( V_10 , V_345 ,
V_187 == V_188 ) ;
}
}
if ( V_488 || V_10 -> V_50 & V_355 ) {
if ( V_488 && ! ( V_10 -> V_50 & V_355 ) )
V_160 = V_161 = 0 ;
F_232 ( V_10 -> V_5 , V_10 , V_160 , V_161 ,
! V_488 , V_13 ) ;
}
F_256 () ;
return 0 ;
}
static int
F_329 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_479 * V_480 ;
struct V_109 * V_110 [ V_481 + 1 ] ;
struct V_155 * V_305 , * V_387 ;
struct V_9 * V_134 ;
struct V_6 * V_7 ;
T_1 V_160 = V_395 , V_490 = V_395 ;
T_1 V_388 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_480 ) , V_110 , V_481 , V_482 ) ;
if ( V_32 < 0 )
return V_32 ;
V_480 = F_60 ( V_92 ) ;
V_305 = F_323 ( V_110 [ V_483 ] , V_110 [ V_484 ] , & V_387 ) ;
if ( V_305 == NULL )
return - V_35 ;
if ( V_110 [ V_491 ] ) {
struct V_492 * V_493 ;
V_493 = F_324 ( V_110 [ V_491 ] ) ;
V_160 = V_493 -> V_494 ;
V_490 = V_493 -> V_495 ;
} else {
V_490 = V_395 ;
V_160 = V_395 ;
}
V_7 = F_74 ( V_101 , V_480 -> V_486 ) ;
if ( V_7 == NULL )
return - V_169 ;
V_388 = V_110 [ V_485 ] ? F_327 ( V_110 [ V_485 ] ) : V_480 -> V_388 ;
V_388 &= V_444 | V_245 | V_355 |
V_190 ;
V_134 = F_185 ( V_101 , V_305 , V_7 , 1 ) ;
if ( V_134 == NULL ) {
return F_255 ( V_101 , V_480 -> V_486 , V_305 , V_387 ,
V_480 -> V_487 , V_388 ,
V_490 , V_160 ) ;
}
if ( V_92 -> V_496 & V_497 ||
! ( V_92 -> V_496 & V_498 ) )
V_32 = - V_174 ;
else
V_32 = F_328 ( V_134 , V_388 , V_490 , V_160 ) ;
F_146 ( V_134 ) ;
return V_32 ;
}
static void F_330 ( struct V_91 * V_92 , T_3 V_499 , T_1 V_50 ,
T_3 V_159 , int V_85 )
{
struct V_479 * V_480 ;
V_480 = F_60 ( V_92 ) ;
V_480 -> V_500 = V_96 ;
V_480 -> V_487 = V_499 ;
V_480 -> V_388 = V_50 ;
V_480 -> V_405 = V_159 ;
V_480 -> V_486 = V_85 ;
}
static int F_331 ( struct V_83 * V_84 , unsigned long V_1 ,
unsigned long V_70 , T_1 V_501 , T_1 V_343 )
{
struct V_492 V_493 ;
V_493 . V_1 = F_1 ( V_1 ) ;
V_493 . V_70 = F_1 ( V_70 ) ;
V_493 . V_495 = V_501 ;
V_493 . V_494 = V_343 ;
return F_332 ( V_84 , V_491 , sizeof( V_493 ) , & V_493 ) ;
}
static inline int F_333 ( int V_405 )
{
if ( V_405 & V_270 )
return V_407 ;
else if ( V_405 & V_267 )
return V_406 ;
else if ( V_405 & V_502 )
return V_503 ;
else
return V_504 ;
}
static inline int F_334 ( void )
{
return F_55 ( sizeof( struct V_479 ) )
+ F_56 ( 16 )
+ F_56 ( 16 )
+ F_56 ( sizeof( struct V_492 ) )
+ F_56 ( 4 ) ;
}
static int F_335 ( struct V_83 * V_84 , struct V_9 * V_134 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_1 V_501 , V_343 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_479 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_330 ( V_92 , V_134 -> V_178 , V_134 -> V_50 , F_333 ( V_134 -> V_159 ) ,
V_134 -> V_5 -> V_7 -> V_85 ) ;
if ( ! ( ( V_134 -> V_50 & V_189 ) &&
( V_134 -> V_161 == V_395 ) ) ) {
V_501 = V_134 -> V_161 ;
V_343 = V_134 -> V_160 ;
if ( V_501 != V_395 ) {
long V_505 = ( V_13 - V_134 -> V_70 ) / V_3 ;
if ( V_501 > V_505 )
V_501 -= V_505 ;
else
V_501 = 0 ;
if ( V_343 != V_395 ) {
if ( V_343 > V_505 )
V_343 -= V_505 ;
else
V_343 = 0 ;
}
}
} else {
V_501 = V_395 ;
V_343 = V_395 ;
}
if ( ! F_198 ( & V_134 -> V_157 ) ) {
if ( F_332 ( V_84 , V_484 , 16 , & V_134 -> V_153 ) < 0 ||
F_332 ( V_84 , V_483 , 16 , & V_134 -> V_157 ) < 0 )
goto error;
} else
if ( F_332 ( V_84 , V_483 , 16 , & V_134 -> V_153 ) < 0 )
goto error;
if ( F_331 ( V_84 , V_134 -> V_1 , V_134 -> V_70 , V_501 , V_343 ) < 0 )
goto error;
if ( F_336 ( V_84 , V_485 , V_134 -> V_50 ) < 0 )
goto error;
return F_62 ( V_84 , V_92 ) ;
error:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_337 ( struct V_83 * V_84 , struct V_506 * V_507 ,
T_1 V_88 , T_1 V_89 , int V_90 , T_13 V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_504 ;
int V_85 = V_507 -> V_5 -> V_7 -> V_85 ;
if ( F_155 ( & V_507 -> V_508 ) & V_502 )
V_159 = V_503 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_479 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_330 ( V_92 , 128 , V_189 , V_159 , V_85 ) ;
if ( F_332 ( V_84 , V_509 , 16 , & V_507 -> V_508 ) < 0 ||
F_331 ( V_84 , V_507 -> V_510 , V_507 -> V_511 ,
V_395 , V_395 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
return F_62 ( V_84 , V_92 ) ;
}
static int F_338 ( struct V_83 * V_84 , struct V_512 * V_513 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_504 ;
int V_85 = V_513 -> V_514 -> V_7 -> V_85 ;
if ( F_155 ( & V_513 -> V_515 ) & V_502 )
V_159 = V_503 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_479 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_330 ( V_92 , 128 , V_189 , V_159 , V_85 ) ;
if ( F_332 ( V_84 , V_516 , 16 , & V_513 -> V_515 ) < 0 ||
F_331 ( V_84 , V_513 -> V_517 , V_513 -> V_518 ,
V_395 , V_395 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
return F_62 ( V_84 , V_92 ) ;
}
static int F_339 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_118 * V_119 , enum V_519 type ,
int V_520 , int * V_521 )
{
struct V_506 * V_507 ;
struct V_512 * V_513 ;
int V_32 = 1 ;
int V_522 = * V_521 ;
F_170 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_523 : {
struct V_9 * V_134 ;
F_86 (ifa, &idev->addr_list, if_list) {
if ( ++ V_522 < V_520 )
continue;
V_32 = F_335 ( V_84 , V_134 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_396 ,
V_131 ) ;
if ( V_32 <= 0 )
break;
F_82 ( V_119 , F_83 ( V_84 ) ) ;
}
break;
}
case V_524 :
for ( V_507 = V_5 -> V_525 ; V_507 ;
V_507 = V_507 -> V_470 , V_522 ++ ) {
if ( V_522 < V_520 )
continue;
V_32 = F_337 ( V_84 , V_507 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_526 ,
V_131 ) ;
if ( V_32 <= 0 )
break;
}
break;
case V_527 :
for ( V_513 = V_5 -> V_528 ; V_513 ;
V_513 = V_513 -> V_529 , V_522 ++ ) {
if ( V_522 < V_520 )
continue;
V_32 = F_338 ( V_84 , V_513 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_530 ,
V_131 ) ;
if ( V_32 <= 0 )
break;
}
break;
default:
break;
}
F_175 ( & V_5 -> V_36 ) ;
* V_521 = V_522 ;
return V_32 ;
}
static int F_340 ( struct V_83 * V_84 , struct V_118 * V_119 ,
enum V_519 type )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
int V_120 , V_121 ;
int V_122 , V_522 ;
int V_123 , V_520 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_124 * V_125 ;
V_121 = V_119 -> args [ 0 ] ;
V_123 = V_122 = V_119 -> args [ 1 ] ;
V_520 = V_522 = V_119 -> args [ 2 ] ;
F_78 () ;
V_119 -> V_89 = F_79 ( & V_101 -> V_18 . V_128 ) ^ V_101 -> V_129 ;
for ( V_120 = V_121 ; V_120 < V_126 ; V_120 ++ , V_123 = 0 ) {
V_122 = 0 ;
V_125 = & V_101 -> V_127 [ V_120 ] ;
F_80 (dev, head, index_hlist) {
if ( V_122 < V_123 )
goto V_130;
if ( V_120 > V_121 || V_122 > V_123 )
V_520 = 0 ;
V_522 = 0 ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_130;
if ( F_339 ( V_5 , V_84 , V_119 , type ,
V_520 , & V_522 ) <= 0 )
goto V_132;
V_130:
V_122 ++ ;
}
}
V_132:
F_81 () ;
V_119 -> args [ 0 ] = V_120 ;
V_119 -> args [ 1 ] = V_122 ;
V_119 -> args [ 2 ] = V_522 ;
return V_84 -> V_133 ;
}
static int F_341 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_519 type = V_523 ;
return F_340 ( V_84 , V_119 , type ) ;
}
static int F_342 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_519 type = V_524 ;
return F_340 ( V_84 , V_119 , type ) ;
}
static int F_343 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_519 type = V_527 ;
return F_340 ( V_84 , V_119 , type ) ;
}
static int F_344 ( struct V_83 * V_107 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_107 -> V_108 ) ;
struct V_479 * V_480 ;
struct V_109 * V_110 [ V_481 + 1 ] ;
struct V_155 * V_153 = NULL , * V_531 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_134 ;
struct V_83 * V_84 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_480 ) , V_110 , V_481 , V_482 ) ;
if ( V_32 < 0 )
goto V_104;
V_153 = F_323 ( V_110 [ V_483 ] , V_110 [ V_484 ] , & V_531 ) ;
if ( V_153 == NULL ) {
V_32 = - V_35 ;
goto V_104;
}
V_480 = F_60 ( V_92 ) ;
if ( V_480 -> V_486 )
V_7 = F_74 ( V_101 , V_480 -> V_486 ) ;
V_134 = F_185 ( V_101 , V_153 , V_7 , 1 ) ;
if ( ! V_134 ) {
V_32 = - V_168 ;
goto V_104;
}
V_84 = F_65 ( F_334 () , V_25 ) ;
if ( ! V_84 ) {
V_32 = - V_102 ;
goto V_532;
}
V_32 = F_335 ( V_84 , V_134 , F_75 ( V_107 ) . V_88 ,
V_92 -> V_117 , V_396 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_532;
}
V_32 = F_76 ( V_84 , V_101 , F_75 ( V_107 ) . V_88 ) ;
V_532:
F_146 ( V_134 ) ;
V_104:
return V_32 ;
}
static void F_345 ( int V_90 , struct V_9 * V_134 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_134 -> V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_334 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_32 = F_335 ( V_84 , V_134 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_533 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_533 , V_32 ) ;
}
static inline void F_346 ( struct V_86 * V_39 ,
T_2 * V_534 , int V_535 )
{
F_347 ( V_535 < ( V_536 * 4 ) ) ;
memset ( V_534 , 0 , V_535 ) ;
V_534 [ V_537 ] = V_39 -> V_45 ;
V_534 [ V_538 ] = V_39 -> V_539 ;
V_534 [ V_540 ] = V_39 -> V_41 ;
V_534 [ V_541 ] = V_39 -> V_542 ;
V_534 [ V_543 ] = V_39 -> V_544 ;
V_534 [ V_545 ] = V_39 -> V_349 ;
V_534 [ V_546 ] = V_39 -> V_221 ;
V_534 [ V_547 ] = V_39 -> V_58 ;
V_534 [ V_548 ] =
F_348 ( V_39 -> V_441 ) ;
V_534 [ V_549 ] =
F_348 ( V_39 -> V_440 ) ;
V_534 [ V_550 ] = V_39 -> V_551 ;
V_534 [ V_552 ] =
F_348 ( V_39 -> V_553 ) ;
V_534 [ V_554 ] =
F_348 ( V_39 -> V_555 ) ;
V_534 [ V_556 ] = V_39 -> V_65 ;
V_534 [ V_557 ] = V_39 -> V_218 ;
V_534 [ V_558 ] = V_39 -> V_219 ;
V_534 [ V_559 ] = V_39 -> V_215 ;
V_534 [ V_560 ] = V_39 -> V_220 ;
V_534 [ V_561 ] = V_39 -> V_352 ;
V_534 [ V_562 ] = V_39 -> V_563 ;
V_534 [ V_564 ] = V_39 -> V_565 ;
#ifdef F_349
V_534 [ V_566 ] = V_39 -> V_567 ;
V_534 [ V_568 ] =
F_348 ( V_39 -> V_569 ) ;
#ifdef F_350
V_534 [ V_570 ] = V_39 -> V_571 ;
#endif
#endif
V_534 [ V_572 ] = V_39 -> V_100 ;
V_534 [ V_573 ] = V_39 -> V_574 ;
#ifdef F_242
V_534 [ V_575 ] = V_39 -> V_353 ;
#endif
#ifdef F_57
V_534 [ V_576 ] = V_39 -> V_99 ;
#endif
V_534 [ V_577 ] = V_39 -> V_171 ;
V_534 [ V_578 ] = V_39 -> V_53 ;
V_534 [ V_579 ] = V_39 -> V_580 ;
V_534 [ V_581 ] = V_39 -> V_582 ;
V_534 [ V_583 ] = V_39 -> V_584 ;
V_534 [ V_585 ] = V_39 -> V_586 ;
}
static inline T_14 F_351 ( void )
{
return F_56 ( 4 )
+ F_56 ( sizeof( struct V_587 ) )
+ F_56 ( V_536 * 4 )
+ F_56 ( V_588 * 8 )
+ F_56 ( V_589 * 8 )
+ F_56 ( sizeof( struct V_155 ) ) ;
}
static inline T_14 F_352 ( void )
{
return F_55 ( sizeof( struct V_590 ) )
+ F_56 ( V_591 )
+ F_56 ( V_592 )
+ F_56 ( 4 )
+ F_56 ( 4 )
+ F_56 ( F_351 () ) ;
}
static inline void F_353 ( T_15 * V_17 , T_16 * V_593 ,
int V_594 , int V_535 )
{
int V_16 ;
int V_595 = V_535 - sizeof( T_15 ) * V_594 ;
F_347 ( V_595 < 0 ) ;
F_354 ( V_594 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_594 ; V_16 ++ )
F_354 ( F_355 ( & V_593 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_594 ] , 0 , V_595 ) ;
}
static inline void F_356 ( T_15 * V_17 , void T_17 * V_593 ,
int V_594 , int V_535 , T_14 V_596 )
{
int V_16 ;
int V_595 = V_535 - sizeof( T_15 ) * V_594 ;
F_347 ( V_595 < 0 ) ;
F_354 ( V_594 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_594 ; V_16 ++ )
F_354 ( F_357 ( V_593 , V_16 , V_596 ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_594 ] , 0 , V_595 ) ;
}
static void F_358 ( T_15 * V_17 , struct V_4 * V_5 , int V_597 ,
int V_535 )
{
switch ( V_597 ) {
case V_598 :
F_356 ( V_17 , V_5 -> V_17 . V_18 ,
V_588 , V_535 , F_359 ( struct V_19 , V_22 ) ) ;
break;
case V_599 :
F_353 ( V_17 , V_5 -> V_17 . V_23 -> V_600 , V_589 , V_535 ) ;
break;
}
}
static int F_360 ( struct V_83 * V_84 , struct V_4 * V_5 )
{
struct V_109 * V_601 ;
struct V_587 V_493 ;
if ( F_336 ( V_84 , V_602 , V_5 -> V_68 ) )
goto V_98;
V_493 . V_603 = V_604 ;
V_493 . V_70 = F_1 ( V_5 -> V_70 ) ;
V_493 . V_605 = F_348 ( V_5 -> V_43 -> V_605 ) ;
V_493 . V_606 = F_348 ( F_154 ( V_5 -> V_43 , V_222 ) ) ;
if ( F_332 ( V_84 , V_607 , sizeof( V_493 ) , & V_493 ) )
goto V_98;
V_601 = F_361 ( V_84 , V_608 , V_536 * sizeof( V_609 ) ) ;
if ( V_601 == NULL )
goto V_98;
F_346 ( & V_5 -> V_39 , F_324 ( V_601 ) , F_362 ( V_601 ) ) ;
V_601 = F_361 ( V_84 , V_598 , V_588 * sizeof( T_15 ) ) ;
if ( V_601 == NULL )
goto V_98;
F_358 ( F_324 ( V_601 ) , V_5 , V_598 , F_362 ( V_601 ) ) ;
V_601 = F_361 ( V_84 , V_599 , V_589 * sizeof( T_15 ) ) ;
if ( V_601 == NULL )
goto V_98;
F_358 ( F_324 ( V_601 ) , V_5 , V_599 , F_362 ( V_601 ) ) ;
V_601 = F_361 ( V_84 , V_610 , sizeof( struct V_155 ) ) ;
if ( V_601 == NULL )
goto V_98;
if ( F_363 ( V_84 , V_611 , V_5 -> V_414 ) )
goto V_98;
F_170 ( & V_5 -> V_36 ) ;
memcpy ( F_324 ( V_601 ) , V_5 -> V_66 . V_212 , F_362 ( V_601 ) ) ;
F_175 ( & V_5 -> V_36 ) ;
return 0 ;
V_98:
return - V_94 ;
}
static T_14 F_364 ( const struct V_6 * V_7 )
{
if ( ! F_51 ( V_7 ) )
return 0 ;
return F_351 () ;
}
static int F_365 ( struct V_83 * V_84 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return - V_612 ;
if ( F_360 ( V_84 , V_5 ) < 0 )
return - V_94 ;
return 0 ;
}
static int F_366 ( struct V_4 * V_5 , struct V_155 * V_66 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_613 = false ;
struct V_155 V_614 ;
F_29 () ;
if ( V_66 == NULL )
return - V_35 ;
if ( F_198 ( V_66 ) )
return - V_35 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return - V_35 ;
if ( ! F_289 ( V_5 ) )
return - V_35 ;
if ( V_5 -> V_39 . V_58 <= 0 )
return - V_35 ;
F_144 ( & V_5 -> V_36 ) ;
F_367 ( sizeof( V_66 -> V_212 ) != 16 ) ;
memcpy ( V_5 -> V_66 . V_212 + 8 , V_66 -> V_212 + 8 , 8 ) ;
F_148 ( & V_5 -> V_36 ) ;
if ( ! V_5 -> V_76 && ( V_5 -> V_68 & V_69 ) &&
! F_178 ( V_7 , & V_614 , V_137 |
V_224 ) ) {
F_290 ( V_7 , & V_614 , & V_75 ) ;
V_613 = true ;
}
F_144 ( & V_5 -> V_36 ) ;
if ( V_613 ) {
V_5 -> V_68 |= V_435 ;
V_5 -> V_438 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_441 ) ;
}
F_86 (ifp, &idev->addr_list, if_list) {
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_179 ) {
V_10 -> V_160 = 0 ;
V_10 -> V_161 = 0 ;
}
F_125 ( & V_10 -> V_36 ) ;
}
F_148 ( & V_5 -> V_36 ) ;
F_256 () ;
return 0 ;
}
static int F_368 ( struct V_6 * V_7 , const struct V_109 * V_601 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
struct V_109 * V_110 [ V_615 + 1 ] ;
if ( ! V_5 )
return - V_616 ;
if ( F_369 ( V_110 , V_615 , V_601 , NULL ) < 0 )
F_370 () ;
if ( V_110 [ V_610 ] ) {
V_32 = F_366 ( V_5 , F_324 ( V_110 [ V_610 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_110 [ V_611 ] ) {
T_3 V_617 = F_371 ( V_110 [ V_611 ] ) ;
if ( V_617 != V_415 &&
V_617 != V_618 )
return - V_35 ;
V_5 -> V_414 = V_617 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_372 ( struct V_83 * V_84 , struct V_4 * V_5 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_590 * V_619 ;
struct V_91 * V_92 ;
void * V_620 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_619 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_619 = F_60 ( V_92 ) ;
V_619 -> V_621 = V_96 ;
V_619 -> V_622 = 0 ;
V_619 -> V_623 = V_7 -> type ;
V_619 -> V_624 = V_7 -> V_85 ;
V_619 -> V_625 = F_373 ( V_7 ) ;
V_619 -> V_626 = 0 ;
if ( F_374 ( V_84 , V_627 , V_7 -> V_48 ) ||
( V_7 -> V_282 &&
F_332 ( V_84 , V_628 , V_7 -> V_282 , V_7 -> V_284 ) ) ||
F_336 ( V_84 , V_629 , V_7 -> V_33 ) ||
( V_7 -> V_85 != V_7 -> V_630 &&
F_336 ( V_84 , V_631 , V_7 -> V_630 ) ) )
goto V_98;
V_620 = F_375 ( V_84 , V_632 ) ;
if ( V_620 == NULL )
goto V_98;
if ( F_360 ( V_84 , V_5 ) < 0 )
goto V_98;
F_376 ( V_84 , V_620 ) ;
return F_62 ( V_84 , V_92 ) ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_377 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
int V_120 , V_121 ;
int V_122 = 0 , V_123 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_124 * V_125 ;
V_121 = V_119 -> args [ 0 ] ;
V_123 = V_119 -> args [ 1 ] ;
F_78 () ;
for ( V_120 = V_121 ; V_120 < V_126 ; V_120 ++ , V_123 = 0 ) {
V_122 = 0 ;
V_125 = & V_101 -> V_127 [ V_120 ] ;
F_80 (dev, head, index_hlist) {
if ( V_122 < V_123 )
goto V_130;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_130;
if ( F_372 ( V_84 , V_5 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_425 , V_131 ) <= 0 )
goto V_175;
V_130:
V_122 ++ ;
}
}
V_175:
F_81 () ;
V_119 -> args [ 1 ] = V_122 ;
V_119 -> args [ 0 ] = V_120 ;
return V_84 -> V_133 ;
}
void F_276 ( int V_90 , struct V_4 * V_5 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_352 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_32 = F_372 ( V_84 , V_5 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_633 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_633 , V_32 ) ;
}
static inline T_14 F_378 ( void )
{
return F_55 ( sizeof( struct V_634 ) )
+ F_56 ( sizeof( struct V_155 ) )
+ F_56 ( sizeof( struct V_635 ) ) ;
}
static int F_379 ( struct V_83 * V_84 , struct V_4 * V_5 ,
struct V_339 * V_340 , T_1 V_88 , T_1 V_89 ,
int V_90 , unsigned int V_50 )
{
struct V_634 * V_636 ;
struct V_91 * V_92 ;
struct V_635 V_493 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_636 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_636 = F_60 ( V_92 ) ;
V_636 -> V_637 = V_96 ;
V_636 -> V_638 = 0 ;
V_636 -> V_639 = 0 ;
V_636 -> V_640 = V_5 -> V_7 -> V_85 ;
V_636 -> V_178 = V_340 -> V_178 ;
V_636 -> V_641 = V_340 -> type ;
V_636 -> V_642 = 0 ;
V_636 -> V_643 = 0 ;
if ( V_340 -> V_271 )
V_636 -> V_643 |= V_644 ;
if ( V_340 -> V_349 )
V_636 -> V_643 |= V_645 ;
if ( F_332 ( V_84 , V_646 , sizeof( V_340 -> V_341 ) , & V_340 -> V_341 ) )
goto V_98;
V_493 . V_647 = F_235 ( V_340 -> V_344 ) ;
V_493 . V_648 = F_235 ( V_340 -> V_343 ) ;
if ( F_332 ( V_84 , V_649 , sizeof( V_493 ) , & V_493 ) )
goto V_98;
return F_62 ( V_84 , V_92 ) ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static void F_247 ( int V_90 , struct V_4 * V_5 ,
struct V_339 * V_340 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_378 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_32 = F_379 ( V_84 , V_5 , V_340 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_650 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_650 , V_32 ) ;
}
static void F_286 ( int V_90 , struct V_9 * V_10 )
{
struct V_101 * V_101 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_90 )
F_29 () ;
F_345 ( V_90 ? : V_396 , V_10 ) ;
switch ( V_90 ) {
case V_396 :
if ( ! ( V_10 -> V_149 -> V_651 ) )
F_265 ( V_10 -> V_149 ) ;
if ( V_10 -> V_5 -> V_39 . V_45 )
F_87 ( V_10 ) ;
if ( ! F_198 ( & V_10 -> V_157 ) )
F_224 ( & V_10 -> V_157 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_199 :
if ( V_10 -> V_5 -> V_39 . V_45 )
F_88 ( V_10 ) ;
F_195 ( V_10 -> V_5 , & V_10 -> V_153 ) ;
if ( ! F_198 ( & V_10 -> V_157 ) ) {
struct V_162 * V_149 ;
V_149 = F_137 ( & V_10 -> V_157 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
if ( V_149 && F_138 ( V_149 ) )
F_380 ( & V_149 -> V_230 ) ;
}
F_228 ( & V_10 -> V_149 -> V_230 ) ;
if ( F_138 ( V_10 -> V_149 ) )
F_380 ( & V_10 -> V_149 -> V_230 ) ;
F_381 ( V_101 ) ;
break;
}
F_382 ( & V_101 -> V_18 . V_128 ) ;
}
static void F_149 ( int V_90 , struct V_9 * V_10 )
{
F_115 () ;
if ( F_130 ( V_10 -> V_5 -> V_76 == 0 ) )
F_286 ( V_90 , V_10 ) ;
F_129 () ;
}
static
int F_383 ( struct V_140 * V_652 , int V_653 ,
void T_6 * V_654 , T_14 * V_655 , T_8 * V_656 )
{
int * V_657 = V_652 -> V_304 ;
int V_658 = * V_657 ;
T_8 V_457 = * V_656 ;
struct V_140 V_659 ;
int V_209 ;
V_659 = * V_652 ;
V_659 . V_304 = & V_658 ;
V_209 = F_384 ( & V_659 , V_653 , V_654 , V_655 , V_656 ) ;
if ( V_653 )
V_209 = F_91 ( V_652 , V_657 , V_658 ) ;
if ( V_209 )
* V_656 = V_457 ;
return V_209 ;
}
static void F_385 ( struct V_4 * V_5 )
{
struct V_660 V_661 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_386 ( & V_661 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_171 )
F_271 ( NULL , V_200 , & V_661 ) ;
else
F_271 ( NULL , V_183 , & V_661 ) ;
}
static void F_387 ( struct V_101 * V_101 , T_2 V_138 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_78 () ;
F_169 (net, dev) {
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
int V_139 = ( ! V_5 -> V_39 . V_171 ) ^ ( ! V_138 ) ;
V_5 -> V_39 . V_171 = V_138 ;
if ( V_139 )
F_385 ( V_5 ) ;
}
}
F_81 () ;
}
static int F_388 ( struct V_140 * V_141 , int * V_142 , int V_138 )
{
struct V_101 * V_101 ;
int V_143 ;
if ( ! F_92 () )
return F_93 () ;
V_101 = (struct V_101 * ) V_141 -> V_144 ;
V_143 = * V_142 ;
* V_142 = V_138 ;
if ( V_142 == & V_101 -> V_18 . V_40 -> V_171 ) {
F_94 () ;
return 0 ;
}
if ( V_142 == & V_101 -> V_18 . V_115 -> V_171 ) {
V_101 -> V_18 . V_40 -> V_171 = V_138 ;
F_387 ( V_101 , V_138 ) ;
} else if ( ( ! V_138 ) ^ ( ! V_143 ) )
F_385 ( (struct V_4 * ) V_141 -> V_145 ) ;
F_94 () ;
return 0 ;
}
static
int F_389 ( struct V_140 * V_652 , int V_653 ,
void T_6 * V_654 , T_14 * V_655 , T_8 * V_656 )
{
int * V_657 = V_652 -> V_304 ;
int V_658 = * V_657 ;
T_8 V_457 = * V_656 ;
struct V_140 V_659 ;
int V_209 ;
V_659 = * V_652 ;
V_659 . V_304 = & V_658 ;
V_209 = F_384 ( & V_659 , V_653 , V_654 , V_655 , V_656 ) ;
if ( V_653 )
V_209 = F_388 ( V_652 , V_657 , V_658 ) ;
if ( V_209 )
* V_656 = V_457 ;
return V_209 ;
}
static
int F_390 ( struct V_140 * V_652 , int V_653 ,
void T_6 * V_654 , T_14 * V_655 , T_8 * V_656 )
{
int * V_657 = V_652 -> V_304 ;
int V_209 ;
int V_143 , V_662 ;
V_143 = * V_657 ;
V_209 = F_384 ( V_652 , V_653 , V_654 , V_655 , V_656 ) ;
V_662 = * V_657 ;
if ( V_653 && V_143 != V_662 ) {
struct V_101 * V_101 = V_652 -> V_144 ;
if ( ! F_92 () )
return F_93 () ;
if ( V_657 == & V_101 -> V_18 . V_40 -> V_100 )
F_64 ( V_101 , V_82 ,
V_116 ,
V_101 -> V_18 . V_40 ) ;
else if ( V_657 == & V_101 -> V_18 . V_115 -> V_100 )
F_64 ( V_101 , V_82 ,
V_114 ,
V_101 -> V_18 . V_115 ) ;
else {
struct V_4 * V_5 = V_652 -> V_145 ;
F_64 ( V_101 , V_82 ,
V_5 -> V_7 -> V_85 ,
& V_5 -> V_39 ) ;
}
F_94 () ;
}
return V_209 ;
}
static int F_391 ( struct V_101 * V_101 , char * V_663 ,
struct V_4 * V_5 , struct V_86 * V_142 )
{
int V_16 ;
struct V_664 * V_665 ;
char V_666 [ sizeof( L_28 ) + V_591 ] ;
V_665 = F_392 ( & V_667 , sizeof( * V_665 ) , V_25 ) ;
if ( V_665 == NULL )
goto V_175;
for ( V_16 = 0 ; V_665 -> V_668 [ V_16 ] . V_304 ; V_16 ++ ) {
V_665 -> V_668 [ V_16 ] . V_304 += ( char * ) V_142 - ( char * ) & V_86 ;
V_665 -> V_668 [ V_16 ] . V_145 = V_5 ;
V_665 -> V_668 [ V_16 ] . V_144 = V_101 ;
}
snprintf ( V_666 , sizeof( V_666 ) , L_29 , V_663 ) ;
V_665 -> V_669 = F_393 ( V_101 , V_666 , V_665 -> V_668 ) ;
if ( V_665 -> V_669 == NULL )
goto free;
V_142 -> V_42 = V_665 ;
return 0 ;
free:
F_26 ( V_665 ) ;
V_175:
return - V_102 ;
}
static void F_394 ( struct V_86 * V_142 )
{
struct V_664 * V_665 ;
if ( V_142 -> V_42 == NULL )
return;
V_665 = V_142 -> V_42 ;
V_142 -> V_42 = NULL ;
F_395 ( V_665 -> V_669 ) ;
F_26 ( V_665 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_396 ( V_5 -> V_7 -> V_48 ) )
return - V_35 ;
V_32 = F_397 ( V_5 -> V_7 , V_5 -> V_43 ,
& V_670 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_391 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_48 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_398 ( V_5 -> V_43 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_394 ( & V_5 -> V_39 ) ;
F_398 ( V_5 -> V_43 ) ;
}
static int T_10 F_399 ( struct V_101 * V_101 )
{
int V_32 = - V_30 ;
struct V_86 * V_671 , * V_672 ;
V_671 = F_392 ( & V_86 , sizeof( V_86 ) , V_25 ) ;
if ( V_671 == NULL )
goto V_673;
V_672 = F_392 ( & V_674 , sizeof( V_674 ) , V_25 ) ;
if ( V_672 == NULL )
goto V_675;
V_672 -> V_349 = V_676 . V_349 ;
V_672 -> V_171 = V_676 . V_171 ;
V_101 -> V_18 . V_115 = V_671 ;
V_101 -> V_18 . V_40 = V_672 ;
#ifdef F_400
V_32 = F_391 ( V_101 , L_30 , NULL , V_671 ) ;
if ( V_32 < 0 )
goto V_677;
V_32 = F_391 ( V_101 , L_31 , NULL , V_672 ) ;
if ( V_32 < 0 )
goto V_678;
#endif
return 0 ;
#ifdef F_400
V_678:
F_394 ( V_671 ) ;
V_677:
F_26 ( V_672 ) ;
#endif
V_675:
F_26 ( V_671 ) ;
V_673:
return V_32 ;
}
static void T_11 F_401 ( struct V_101 * V_101 )
{
#ifdef F_400
F_394 ( V_101 -> V_18 . V_40 ) ;
F_394 ( V_101 -> V_18 . V_115 ) ;
#endif
if ( ! F_181 ( V_101 , & V_679 ) ) {
F_26 ( V_101 -> V_18 . V_40 ) ;
F_26 ( V_101 -> V_18 . V_115 ) ;
}
}
int T_12 F_402 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_403 () ;
if ( V_32 < 0 ) {
F_404 ( L_32 ,
V_47 , V_32 ) ;
goto V_175;
}
V_32 = F_317 ( & V_680 ) ;
if ( V_32 < 0 )
goto V_681;
V_15 = F_405 ( L_33 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_682;
}
F_249 () ;
V_5 = F_28 ( V_679 . V_683 ) ;
F_94 () ;
if ( F_52 ( V_5 ) ) {
V_32 = F_119 ( V_5 ) ;
goto V_684;
}
for ( V_16 = 0 ; V_16 < V_433 ; V_16 ++ )
F_406 ( & V_180 [ V_16 ] ) ;
F_407 ( & V_685 ) ;
F_246 () ;
F_408 ( & V_686 ) ;
V_32 = F_409 ( V_687 , V_688 , NULL , F_377 ,
NULL ) ;
if ( V_32 < 0 )
goto V_104;
F_409 ( V_687 , V_396 , F_329 , NULL , NULL ) ;
F_409 ( V_687 , V_199 , F_326 , NULL , NULL ) ;
F_409 ( V_687 , V_689 , F_344 ,
F_341 , NULL ) ;
F_409 ( V_687 , V_526 , NULL ,
F_342 , NULL ) ;
F_409 ( V_687 , V_530 , NULL ,
F_343 , NULL ) ;
F_409 ( V_687 , V_690 , F_70 ,
F_77 , NULL ) ;
F_410 () ;
return 0 ;
V_104:
F_411 ( & V_686 ) ;
F_412 ( & V_685 ) ;
V_684:
F_413 ( V_15 ) ;
V_682:
F_319 ( & V_680 ) ;
V_681:
F_414 () ;
V_175:
return V_32 ;
}
void F_415 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_412 ( & V_685 ) ;
F_319 ( & V_680 ) ;
F_414 () ;
F_249 () ;
F_416 ( & V_686 ) ;
F_90 (&init_net, dev) {
if ( F_51 ( V_7 ) == NULL )
continue;
F_277 ( V_7 , 1 ) ;
}
F_277 ( V_679 . V_683 , 2 ) ;
F_141 ( & V_173 ) ;
for ( V_16 = 0 ; V_16 < V_433 ; V_16 ++ )
F_66 ( ! F_417 ( & V_180 [ V_16 ] ) ) ;
F_142 ( & V_173 ) ;
F_10 ( & V_474 ) ;
F_94 () ;
F_413 ( V_15 ) ;
}
