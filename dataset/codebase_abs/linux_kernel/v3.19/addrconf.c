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
static inline bool F_158 ( struct V_4 * V_5 )
{
#ifdef F_159
return V_5 && V_5 -> V_39 . V_227 && V_5 -> V_39 . V_228 ;
#else
return false ;
#endif
}
static int F_160 ( struct V_101 * V_101 ,
struct V_229 * V_230 ,
struct V_231 * V_232 ,
int V_16 )
{
int V_209 ;
if ( V_16 <= V_230 -> V_233 ) {
switch ( V_16 ) {
case V_234 :
V_209 = V_230 -> V_235 ;
break;
case V_236 :
V_209 = V_230 -> V_237 ;
break;
default:
V_209 = ! ! F_161 ( V_16 , V_230 -> V_238 ) ;
}
goto V_175;
}
switch ( V_16 ) {
case V_239 :
V_209 = ! ! V_230 -> V_134 ;
break;
case V_240 :
V_209 = F_162 ( & V_230 -> V_134 -> V_153 , V_232 -> V_153 ) ;
break;
case V_234 :
V_209 = F_163 ( V_230 -> V_164 ) ;
if ( V_209 >= V_232 -> V_159 )
V_209 = - V_209 ;
else
V_209 -= 128 ;
V_230 -> V_235 = V_209 ;
break;
case V_241 :
{
T_3 V_242 = V_243 ;
if ( ! F_158 ( V_230 -> V_134 -> V_5 ) )
V_242 |= V_224 ;
V_209 = F_157 ( V_230 -> V_164 ) ||
! ( V_230 -> V_134 -> V_50 & V_242 ) ;
break;
}
#ifdef F_164
case V_244 :
{
int V_245 = ! ( V_232 -> V_246 & V_247 ) ;
V_209 = ! ( V_230 -> V_134 -> V_50 & V_248 ) ^ V_245 ;
break;
}
#endif
case V_249 :
V_209 = ( ! V_232 -> V_85 ||
V_232 -> V_85 == V_230 -> V_134 -> V_5 -> V_7 -> V_85 ) ;
break;
case V_250 :
V_209 = F_165 ( V_101 ,
& V_230 -> V_134 -> V_153 , V_230 -> V_164 ,
V_230 -> V_134 -> V_5 -> V_7 -> V_85 ) == V_232 -> V_251 ;
break;
case V_252 :
{
int V_253 = V_232 -> V_246 & ( V_254 | V_255 ) ?
! ! ( V_232 -> V_246 & V_255 ) :
V_230 -> V_134 -> V_5 -> V_39 . V_65 >= 2 ;
V_209 = ( ! ( V_230 -> V_134 -> V_50 & V_181 ) ) ^ V_253 ;
break;
}
case V_256 :
V_209 = ! ( F_166 ( & V_230 -> V_134 -> V_153 ) ^
F_166 ( V_232 -> V_153 ) ) ;
break;
case V_236 :
V_209 = F_167 ( & V_230 -> V_134 -> V_153 , V_232 -> V_153 ) ;
if ( V_209 > V_230 -> V_134 -> V_178 )
V_209 = V_230 -> V_134 -> V_178 ;
V_230 -> V_237 = V_209 ;
break;
#ifdef F_159
case V_257 :
V_209 = ! ( V_230 -> V_134 -> V_50 & V_224 ) ;
break;
#endif
default:
V_209 = 0 ;
}
if ( V_209 )
F_168 ( V_16 , V_230 -> V_238 ) ;
V_230 -> V_233 = V_16 ;
V_175:
return V_209 ;
}
int F_169 ( struct V_101 * V_101 , const struct V_6 * V_258 ,
const struct V_155 * V_259 , unsigned int V_246 ,
struct V_155 * V_260 )
{
struct V_229 V_261 [ 2 ] ,
* V_230 = & V_261 [ 0 ] , * V_262 = & V_261 [ 1 ] ;
struct V_231 V_232 ;
struct V_6 * V_7 ;
int V_263 ;
V_263 = F_170 ( V_259 ) ;
V_232 . V_153 = V_259 ;
V_232 . V_85 = V_258 ? V_258 -> V_85 : 0 ;
V_232 . V_159 = F_163 ( V_263 ) ;
V_232 . V_251 = F_165 ( V_101 , V_259 , V_263 , V_232 . V_85 ) ;
V_232 . V_246 = V_246 ;
V_262 -> V_233 = - 1 ;
V_262 -> V_134 = NULL ;
F_78 () ;
F_171 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_263 & V_166 ) ||
V_232 . V_159 <= V_264 ) &&
V_232 . V_85 && V_7 -> V_85 != V_232 . V_85 )
continue;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
continue;
F_172 ( & V_5 -> V_36 ) ;
F_86 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_230 -> V_134 -> V_50 & V_137 ) &&
( ! ( V_230 -> V_134 -> V_50 & V_224 ) ) )
continue;
V_230 -> V_164 = F_170 ( & V_230 -> V_134 -> V_153 ) ;
if ( F_173 ( V_230 -> V_164 == V_165 ||
V_230 -> V_164 & V_166 ) ) {
F_174 ( L_12 ,
V_7 -> V_48 ) ;
continue;
}
V_230 -> V_233 = - 1 ;
F_175 ( V_230 -> V_238 , V_265 ) ;
for ( V_16 = 0 ; V_16 < V_265 ; V_16 ++ ) {
int V_266 , V_267 ;
V_266 = F_160 ( V_101 , V_262 , & V_232 , V_16 ) ;
V_267 = F_160 ( V_101 , V_230 , & V_232 , V_16 ) ;
if ( V_266 > V_267 ) {
if ( V_16 == V_234 &&
V_230 -> V_235 > 0 ) {
goto V_268;
}
break;
} else if ( V_266 < V_267 ) {
if ( V_262 -> V_134 )
F_146 ( V_262 -> V_134 ) ;
F_18 ( V_230 -> V_134 ) ;
F_176 ( V_262 , V_230 ) ;
V_230 -> V_134 = V_262 -> V_134 ;
break;
}
}
}
V_268:
F_177 ( & V_5 -> V_36 ) ;
}
F_81 () ;
if ( ! V_262 -> V_134 )
return - V_168 ;
* V_260 = V_262 -> V_134 -> V_153 ;
F_146 ( V_262 -> V_134 ) ;
return 0 ;
}
int F_178 ( struct V_4 * V_5 , struct V_155 * V_153 ,
T_1 V_269 )
{
struct V_9 * V_10 ;
int V_32 = - V_168 ;
F_179 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_159 > V_270 )
break;
if ( V_10 -> V_159 == V_270 &&
! ( V_10 -> V_50 & V_269 ) ) {
* V_153 = V_10 -> V_153 ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
int F_180 ( struct V_6 * V_7 , struct V_155 * V_153 ,
T_1 V_269 )
{
struct V_4 * V_5 ;
int V_32 = - V_168 ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_172 ( & V_5 -> V_36 ) ;
V_32 = F_178 ( V_5 , V_153 , V_269 ) ;
F_177 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_32 ;
}
static int F_181 ( struct V_4 * V_5 )
{
int V_271 = 0 ;
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list)
V_271 ++ ;
F_177 ( & V_5 -> V_36 ) ;
return V_271 ;
}
int F_182 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
const struct V_6 * V_7 , int V_272 )
{
struct V_9 * V_10 ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_80 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_183 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_162 ( & V_10 -> V_153 , V_153 ) &&
! ( V_10 -> V_50 & V_137 ) &&
( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_159 & ( V_270 | V_273 ) || V_272 ) ) ) {
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
F_184 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_183 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_162 ( & V_10 -> V_153 , V_153 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_185 ( const struct V_155 * V_153 ,
const unsigned int V_178 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_134 ;
bool V_209 = false ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifa, &idev->addr_list, if_list) {
V_209 = F_133 ( V_153 , & V_134 -> V_153 , V_178 ) ;
if ( V_209 )
break;
}
F_177 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_209 ;
}
int F_186 ( const struct V_155 * V_153 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_134 ;
int V_274 ;
V_274 = 0 ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifa, &idev->addr_list, if_list) {
V_274 = F_133 ( V_153 , & V_134 -> V_153 ,
V_134 -> V_178 ) ;
if ( V_274 )
break;
}
F_177 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_274 ;
}
struct V_9 * F_187 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
struct V_6 * V_7 , int V_272 )
{
struct V_9 * V_10 , * V_275 = NULL ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_188 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_183 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_162 ( & V_10 -> V_153 , V_153 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_159 & ( V_270 | V_273 ) || V_272 ) ) {
V_275 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_129 () ;
return V_275 ;
}
static void F_189 ( struct V_9 * V_10 , int V_276 )
{
if ( V_10 -> V_50 & V_189 ) {
F_141 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_50 |= V_137 ;
if ( V_276 )
V_10 -> V_50 |= V_277 ;
F_142 ( & V_10 -> V_36 ) ;
if ( V_276 )
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
static int F_190 ( struct V_9 * V_10 )
{
int V_32 = - V_278 ;
F_141 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_147 == V_279 ) {
V_10 -> V_147 = V_280 ;
V_32 = 0 ;
}
F_142 ( & V_10 -> V_176 ) ;
return V_32 ;
}
void F_191 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_190 ( V_10 ) ) {
F_146 ( V_10 ) ;
return;
}
F_192 ( L_13 ,
V_10 -> V_5 -> V_7 -> V_48 , & V_10 -> V_153 ) ;
if ( V_5 -> V_39 . V_53 > 1 && ! V_5 -> V_39 . V_171 ) {
struct V_155 V_153 ;
V_153 . V_281 [ 0 ] = F_193 ( 0xfe800000 ) ;
V_153 . V_281 [ 1 ] = 0 ;
if ( ! F_194 ( V_153 . V_212 + 8 , V_5 -> V_7 ) &&
F_162 ( & V_10 -> V_153 , & V_153 ) ) {
V_5 -> V_39 . V_171 = 1 ;
F_43 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
}
}
F_141 ( & V_10 -> V_176 ) ;
V_10 -> V_147 = V_282 ;
F_142 ( & V_10 -> V_176 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_195 ( struct V_6 * V_7 , const struct V_155 * V_153 )
{
struct V_155 V_283 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_196 ( V_153 , & V_283 ) ;
F_48 ( V_7 , & V_283 ) ;
}
void F_197 ( struct V_4 * V_5 , const struct V_155 * V_153 )
{
struct V_155 V_283 ;
if ( V_5 -> V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_196 ( V_153 , & V_283 ) ;
F_198 ( V_5 , & V_283 ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_155 V_153 ;
if ( V_10 -> V_178 >= 127 )
return;
F_199 ( & V_153 , & V_10 -> V_153 , V_10 -> V_178 ) ;
if ( F_200 ( & V_153 ) )
return;
F_201 ( V_10 -> V_5 , & V_153 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_155 V_153 ;
if ( V_10 -> V_178 >= 127 )
return;
F_199 ( & V_153 , & V_10 -> V_153 , V_10 -> V_178 ) ;
if ( F_200 ( & V_153 ) )
return;
F_202 ( V_10 -> V_5 , & V_153 ) ;
}
static int F_203 ( T_3 * V_284 , struct V_6 * V_7 )
{
if ( V_7 -> V_285 != V_286 )
return - 1 ;
memcpy ( V_284 , V_7 -> V_287 , 3 ) ;
memcpy ( V_284 + 5 , V_7 -> V_287 + 3 , 3 ) ;
if ( V_7 -> V_288 ) {
V_284 [ 3 ] = ( V_7 -> V_288 >> 8 ) & 0xFF ;
V_284 [ 4 ] = V_7 -> V_288 & 0xFF ;
} else {
V_284 [ 3 ] = 0xFF ;
V_284 [ 4 ] = 0xFE ;
V_284 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_204 ( T_3 * V_284 , struct V_6 * V_7 )
{
if ( V_7 -> V_285 != V_289 )
return - 1 ;
memcpy ( V_284 , V_7 -> V_287 , 8 ) ;
V_284 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_205 ( T_3 * V_284 , struct V_6 * V_7 )
{
union V_290 * V_291 ;
if ( V_7 -> V_285 != V_292 )
return - 1 ;
V_291 = (union V_290 * ) V_7 -> V_287 ;
memcpy ( V_284 , & V_291 -> V_293 . V_294 , sizeof( V_291 -> V_293 . V_294 ) ) ;
V_284 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_206 ( T_3 * V_284 , struct V_6 * V_7 )
{
if ( V_7 -> V_285 != V_295 )
return - 1 ;
memset ( V_284 , 0 , 7 ) ;
V_284 [ 7 ] = * ( T_3 * ) V_7 -> V_287 ;
return 0 ;
}
static int F_207 ( T_3 * V_284 , struct V_6 * V_7 )
{
if ( V_7 -> V_285 != V_296 )
return - 1 ;
memcpy ( V_284 , V_7 -> V_287 + 12 , 8 ) ;
V_284 [ 0 ] |= 2 ;
return 0 ;
}
static int F_208 ( T_3 * V_284 , T_4 V_153 )
{
if ( V_153 == 0 )
return - 1 ;
V_284 [ 0 ] = ( F_209 ( V_153 ) || F_210 ( V_153 ) ||
F_211 ( V_153 ) || F_212 ( V_153 ) ||
F_213 ( V_153 ) || F_214 ( V_153 ) ||
F_215 ( V_153 ) || F_216 ( V_153 ) ||
F_217 ( V_153 ) || F_218 ( V_153 ) ||
F_219 ( V_153 ) ) ? 0x00 : 0x02 ;
V_284 [ 1 ] = 0 ;
V_284 [ 2 ] = 0x5E ;
V_284 [ 3 ] = 0xFE ;
memcpy ( V_284 + 4 , & V_153 , 4 ) ;
return 0 ;
}
static int F_220 ( T_3 * V_284 , struct V_6 * V_7 )
{
if ( V_7 -> V_56 & V_57 )
return F_208 ( V_284 , * ( T_4 * ) V_7 -> V_287 ) ;
return - 1 ;
}
static int F_221 ( T_3 * V_284 , struct V_6 * V_7 )
{
return F_208 ( V_284 , * ( T_4 * ) V_7 -> V_287 ) ;
}
static int F_222 ( T_3 * V_284 , struct V_6 * V_7 )
{
memcpy ( V_284 , V_7 -> V_297 , 3 ) ;
memcpy ( V_284 + 5 , V_7 -> V_297 + 3 , 3 ) ;
V_284 [ 3 ] = 0xFF ;
V_284 [ 4 ] = 0xFE ;
V_284 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_194 ( T_3 * V_284 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_298 :
case V_299 :
return F_203 ( V_284 , V_7 ) ;
case V_300 :
return F_206 ( V_284 , V_7 ) ;
case V_301 :
return F_207 ( V_284 , V_7 ) ;
case V_55 :
return F_220 ( V_284 , V_7 ) ;
case V_302 :
return F_221 ( V_284 , V_7 ) ;
case V_303 :
case V_304 :
return F_204 ( V_284 , V_7 ) ;
case V_305 :
return F_205 ( V_284 , V_7 ) ;
case V_63 :
return F_222 ( V_284 , V_7 ) ;
}
return - 1 ;
}
static int F_223 ( T_3 * V_284 , struct V_4 * V_5 )
{
int V_32 = - 1 ;
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_179 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_159 > V_270 )
break;
if ( V_10 -> V_159 == V_270 && ! ( V_10 -> V_50 & V_137 ) ) {
memcpy ( V_284 , V_10 -> V_153 . V_212 + 8 , 8 ) ;
V_32 = 0 ;
break;
}
}
F_177 ( & V_5 -> V_36 ) ;
return V_32 ;
}
static void F_224 ( struct V_4 * V_5 )
{
V_306:
F_225 ( V_5 -> V_216 , sizeof( V_5 -> V_216 ) ) ;
V_5 -> V_216 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_216 [ 0 ] == 0xfd &&
( V_5 -> V_216 [ 1 ] & V_5 -> V_216 [ 2 ] & V_5 -> V_216 [ 3 ] & V_5 -> V_216 [ 4 ] & V_5 -> V_216 [ 5 ] & V_5 -> V_216 [ 6 ] ) == 0xff &&
( V_5 -> V_216 [ 7 ] & 0x80 ) )
goto V_306;
if ( ( V_5 -> V_216 [ 0 ] | V_5 -> V_216 [ 1 ] ) == 0 ) {
if ( V_5 -> V_216 [ 2 ] == 0x5e && V_5 -> V_216 [ 3 ] == 0xfe )
goto V_306;
if ( ( V_5 -> V_216 [ 2 ] | V_5 -> V_216 [ 3 ] | V_5 -> V_216 [ 4 ] | V_5 -> V_216 [ 5 ] | V_5 -> V_216 [ 6 ] | V_5 -> V_216 [ 7 ] ) == 0x00 )
goto V_306;
}
}
static void V_61 ( unsigned long V_307 )
{
struct V_4 * V_5 = (struct V_4 * ) V_307 ;
unsigned long V_185 ;
F_115 () ;
F_144 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 )
goto V_175;
F_224 ( V_5 ) ;
V_185 = V_13 +
V_5 -> V_39 . V_219 * V_3 -
V_5 -> V_39 . V_215 * V_5 -> V_39 . V_221 *
F_154 ( V_5 -> V_43 , V_222 ) -
V_5 -> V_39 . V_220 * V_3 ;
if ( F_135 ( V_185 , V_13 ) ) {
F_102 ( L_15 ,
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
F_224 ( V_5 ) ;
}
static void
F_226 ( struct V_155 * V_308 , int V_309 , struct V_6 * V_7 ,
unsigned long V_185 , T_1 V_50 )
{
struct V_310 V_311 = {
. V_312 = V_313 ,
. V_314 = V_315 ,
. V_316 = V_7 -> V_85 ,
. V_317 = V_185 ,
. V_318 = V_309 ,
. V_319 = V_320 | V_50 ,
. V_321 . V_322 = F_34 ( V_7 ) ,
. V_323 = V_324 ,
} ;
V_311 . V_325 = * V_308 ;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 && ( V_7 -> V_50 & V_326 ) )
V_311 . V_319 |= V_327 ;
#endif
F_227 ( & V_311 ) ;
}
static struct V_162 * F_137 ( const struct V_155 * V_308 ,
int V_309 ,
const struct V_6 * V_7 ,
T_1 V_50 , T_1 V_328 )
{
struct V_329 * V_330 ;
struct V_162 * V_149 = NULL ;
struct V_331 * V_141 ;
V_141 = F_228 ( F_34 ( V_7 ) , V_313 ) ;
if ( V_141 == NULL )
return NULL ;
F_172 ( & V_141 -> V_332 ) ;
V_330 = F_229 ( & V_141 -> V_333 , V_308 , V_309 , NULL , 0 ) ;
if ( ! V_330 )
goto V_175;
for ( V_149 = V_330 -> V_334 ; V_149 ; V_149 = V_149 -> V_232 . V_335 ) {
if ( V_149 -> V_232 . V_7 -> V_85 != V_7 -> V_85 )
continue;
if ( ( V_149 -> V_196 & V_50 ) != V_50 )
continue;
if ( ( V_149 -> V_196 & V_328 ) != 0 )
continue;
F_230 ( & V_149 -> V_232 ) ;
break;
}
V_175:
F_177 ( & V_141 -> V_332 ) ;
return V_149 ;
}
static void F_231 ( struct V_6 * V_7 )
{
struct V_310 V_311 = {
. V_312 = V_336 ,
. V_314 = V_315 ,
. V_316 = V_7 -> V_85 ,
. V_318 = 8 ,
. V_319 = V_320 ,
. V_321 . V_322 = F_34 ( V_7 ) ,
} ;
F_232 ( & V_311 . V_325 , F_193 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_227 ( & V_311 ) ;
}
static struct V_4 * F_233 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
return F_30 ( - V_102 ) ;
if ( V_5 -> V_39 . V_171 )
return F_30 ( - V_172 ) ;
if ( ! ( V_7 -> V_50 & V_52 ) )
F_231 ( V_7 ) ;
return V_5 ;
}
static void F_234 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_217 V_160 , V_217 V_161 ,
bool V_337 , unsigned long V_211 )
{
T_1 V_50 ;
struct V_9 * V_201 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ift, &idev->tempaddr_list, tmp_list) {
int V_206 , V_338 , V_339 ;
if ( V_10 != V_201 -> V_198 )
continue;
V_206 = ( V_211 - V_201 -> V_1 ) / V_3 ;
V_338 = V_5 -> V_39 . V_218 - V_206 ;
if ( V_338 < 0 )
V_338 = 0 ;
V_339 = V_5 -> V_39 . V_219 -
V_5 -> V_39 . V_220 - V_206 ;
if ( V_339 < 0 )
V_339 = 0 ;
if ( V_160 > V_338 )
V_160 = V_338 ;
if ( V_161 > V_339 )
V_161 = V_339 ;
F_116 ( & V_201 -> V_36 ) ;
V_50 = V_201 -> V_50 ;
V_201 -> V_160 = V_160 ;
V_201 -> V_161 = V_161 ;
V_201 -> V_70 = V_211 ;
if ( V_161 > 0 )
V_201 -> V_50 &= ~ V_243 ;
F_125 ( & V_201 -> V_36 ) ;
if ( ! ( V_50 & V_137 ) )
F_149 ( 0 , V_201 ) ;
}
if ( ( V_337 || F_235 ( & V_5 -> V_59 ) ) &&
V_5 -> V_39 . V_65 > 0 ) {
F_177 ( & V_5 -> V_36 ) ;
F_151 ( V_10 , NULL ) ;
} else {
F_177 ( & V_5 -> V_36 ) ;
}
}
void F_236 ( struct V_6 * V_7 , T_3 * V_340 , int V_133 , bool V_341 )
{
struct V_342 * V_343 ;
V_217 V_160 ;
V_217 V_161 ;
int V_164 ;
struct V_4 * V_112 ;
struct V_101 * V_101 = F_34 ( V_7 ) ;
V_343 = (struct V_342 * ) V_340 ;
if ( V_133 < sizeof( struct V_342 ) ) {
F_38 ( L_16 ) ;
return;
}
V_164 = F_114 ( & V_343 -> V_344 ) ;
if ( V_164 & ( V_166 | V_345 ) )
return;
V_160 = F_237 ( V_343 -> V_346 ) ;
V_161 = F_237 ( V_343 -> V_347 ) ;
if ( V_161 > V_160 ) {
F_238 ( L_17 ) ;
return;
}
V_112 = F_239 ( V_7 ) ;
if ( V_112 == NULL ) {
F_174 ( L_18 ,
V_7 -> V_48 ) ;
return;
}
if ( V_343 -> V_274 ) {
struct V_162 * V_149 ;
unsigned long V_348 ;
if ( V_3 > V_349 )
V_348 = F_134 ( V_160 , V_3 ) ;
else
V_348 = F_134 ( V_160 , V_349 ) ;
if ( F_240 ( V_348 ) )
V_348 *= V_3 ;
V_149 = F_137 ( & V_343 -> V_344 ,
V_343 -> V_178 ,
V_7 ,
V_350 | V_351 ,
V_194 | V_195 ) ;
if ( V_149 ) {
if ( V_160 == 0 ) {
F_138 ( V_149 ) ;
V_149 = NULL ;
} else if ( F_240 ( V_348 ) ) {
F_139 ( V_149 , V_13 + V_348 ) ;
} else {
F_241 ( V_149 ) ;
}
} else if ( V_160 ) {
T_5 V_185 = 0 ;
int V_50 = V_350 | V_351 ;
if ( F_240 ( V_348 ) ) {
V_50 |= V_197 ;
V_185 = F_242 ( V_348 ) ;
}
F_226 ( & V_343 -> V_344 , V_343 -> V_178 ,
V_7 , V_185 , V_50 ) ;
}
F_103 ( V_149 ) ;
}
if ( V_343 -> V_352 && V_112 -> V_39 . V_352 ) {
struct V_9 * V_10 ;
struct V_155 V_153 ;
int V_337 = 0 , V_353 = 0 ;
bool V_179 = false ;
if ( V_343 -> V_178 == 64 ) {
memcpy ( & V_153 , & V_343 -> V_344 , 8 ) ;
if ( ! F_200 ( & V_112 -> V_66 ) ) {
F_172 ( & V_112 -> V_36 ) ;
memcpy ( V_153 . V_212 + 8 ,
V_112 -> V_66 . V_212 + 8 , 8 ) ;
F_177 ( & V_112 -> V_36 ) ;
V_179 = true ;
} else if ( F_194 ( V_153 . V_212 + 8 , V_7 ) &&
F_223 ( V_153 . V_212 + 8 , V_112 ) ) {
F_100 ( V_112 ) ;
return;
}
goto V_354;
}
F_174 ( L_19 ,
V_343 -> V_178 ) ;
F_100 ( V_112 ) ;
return;
V_354:
V_10 = F_187 ( V_101 , & V_153 , V_7 , 1 ) ;
if ( V_10 == NULL && V_160 ) {
int V_355 = V_112 -> V_39 . V_355 ;
T_1 V_210 = 0 ;
#ifdef F_159
if ( V_112 -> V_39 . V_227 &&
! V_101 -> V_18 . V_115 -> V_45 && V_341 )
V_210 = V_224 ;
#endif
if ( ! V_355 ||
F_181 ( V_112 ) < V_355 )
V_10 = F_113 ( V_112 , & V_153 , NULL ,
V_343 -> V_178 ,
V_164 & V_356 ,
V_210 , V_160 ,
V_161 ) ;
if ( F_243 ( V_10 ) ) {
F_100 ( V_112 ) ;
return;
}
V_353 = 0 ;
V_337 = 1 ;
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 |= V_357 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_179 = V_179 ;
F_142 ( & V_10 -> V_36 ) ;
F_156 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_50 ;
unsigned long V_211 ;
T_1 V_358 ;
F_116 ( & V_10 -> V_36 ) ;
V_211 = V_13 ;
if ( V_10 -> V_160 > ( V_211 - V_10 -> V_70 ) / V_3 )
V_358 = V_10 -> V_160 - ( V_211 - V_10 -> V_70 ) / V_3 ;
else
V_358 = 0 ;
if ( ! V_353 && ! V_337 && V_358 ) {
const T_1 V_359 = F_153 ( T_1 ,
V_358 , V_360 ) ;
V_160 = F_244 ( V_160 , V_359 ) ;
V_353 = 1 ;
}
if ( V_353 ) {
V_10 -> V_160 = V_160 ;
V_10 -> V_161 = V_161 ;
V_10 -> V_70 = V_211 ;
V_50 = V_10 -> V_50 ;
V_10 -> V_50 &= ~ V_243 ;
F_125 ( & V_10 -> V_36 ) ;
if ( ! ( V_50 & V_137 ) )
F_149 ( 0 , V_10 ) ;
} else
F_125 ( & V_10 -> V_36 ) ;
F_234 ( V_112 , V_10 , V_160 , V_161 ,
V_337 , V_211 ) ;
F_146 ( V_10 ) ;
F_245 () ;
}
}
F_246 ( V_361 , V_112 , V_343 ) ;
F_100 ( V_112 ) ;
}
int F_247 ( struct V_101 * V_101 , void T_6 * V_362 )
{
struct V_363 V_364 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_248 () ;
V_32 = - V_365 ;
if ( F_249 ( & V_364 , V_362 , sizeof( struct V_363 ) ) )
goto V_366;
V_7 = F_74 ( V_101 , V_364 . V_367 ) ;
V_32 = - V_169 ;
if ( V_7 == NULL )
goto V_366;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 ) {
const struct V_368 * V_369 = V_7 -> V_370 ;
struct V_371 V_372 ;
struct V_373 V_142 ;
V_32 = - V_168 ;
if ( ! ( F_114 ( & V_364 . V_374 ) & V_226 ) )
goto V_366;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_375 . V_259 = V_364 . V_374 . V_281 [ 3 ] ;
V_142 . V_375 . V_260 = 0 ;
V_142 . V_375 . V_376 = 4 ;
V_142 . V_375 . V_377 = 5 ;
V_142 . V_375 . V_378 = V_379 ;
V_142 . V_375 . V_380 = 64 ;
V_372 . V_381 . V_382 = ( V_383 void T_6 * ) & V_142 ;
if ( V_369 -> V_384 ) {
T_7 V_385 = F_250 () ;
F_251 ( V_386 ) ;
V_32 = V_369 -> V_384 ( V_7 , & V_372 , V_387 ) ;
F_251 ( V_385 ) ;
} else
V_32 = - V_388 ;
if ( V_32 == 0 ) {
V_32 = - V_102 ;
V_7 = F_252 ( V_101 , V_142 . V_48 ) ;
if ( ! V_7 )
goto V_366;
V_32 = F_253 ( V_7 ) ;
}
}
#endif
V_366:
F_94 () ;
return V_32 ;
}
static int F_254 ( struct V_101 * V_101 , int V_85 ,
const struct V_155 * V_308 ,
const struct V_155 * V_389 ,
unsigned int V_309 , V_217 V_390 ,
V_217 V_161 , V_217 V_160 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_159 ;
T_1 V_50 ;
T_5 V_185 ;
unsigned long V_391 ;
F_29 () ;
if ( V_309 > 128 )
return - V_35 ;
if ( ! V_160 || V_161 > V_160 )
return - V_35 ;
if ( V_390 & V_357 && V_309 != 64 )
return - V_35 ;
V_7 = F_74 ( V_101 , V_85 ) ;
if ( ! V_7 )
return - V_169 ;
V_5 = F_233 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_119 ( V_5 ) ;
V_159 = F_155 ( V_308 ) ;
V_391 = F_134 ( V_160 , V_3 ) ;
if ( F_240 ( V_391 ) ) {
V_185 = F_242 ( V_391 * V_3 ) ;
V_160 = V_391 ;
V_50 = V_197 ;
} else {
V_185 = 0 ;
V_50 = 0 ;
V_390 |= V_189 ;
}
V_391 = F_134 ( V_161 , V_3 ) ;
if ( F_240 ( V_391 ) ) {
if ( V_391 == 0 )
V_390 |= V_243 ;
V_161 = V_391 ;
}
V_10 = F_113 ( V_5 , V_308 , V_389 , V_309 , V_159 , V_390 ,
V_160 , V_161 ) ;
if ( ! F_52 ( V_10 ) ) {
if ( ! ( V_390 & V_190 ) ) {
F_226 ( & V_10 -> V_153 , V_10 -> V_178 , V_7 ,
V_185 , V_50 ) ;
}
F_156 ( V_10 ) ;
if ( V_390 & V_357 )
F_234 ( V_5 , V_10 , V_160 , V_161 ,
true , V_13 ) ;
F_146 ( V_10 ) ;
F_255 () ;
return 0 ;
}
return F_119 ( V_10 ) ;
}
static int F_256 ( struct V_101 * V_101 , int V_85 , T_1 V_390 ,
const struct V_155 * V_308 , unsigned int V_309 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_309 > 128 )
return - V_35 ;
V_7 = F_74 ( V_101 , V_85 ) ;
if ( ! V_7 )
return - V_169 ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 == NULL )
return - V_392 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_178 == V_309 &&
F_162 ( V_308 , & V_10 -> V_153 ) ) {
F_18 ( V_10 ) ;
F_177 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_181 ) &&
( V_390 & V_357 ) )
F_234 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_140 ( V_10 ) ;
F_255 () ;
return 0 ;
}
}
F_177 ( & V_5 -> V_36 ) ;
return - V_168 ;
}
int F_257 ( struct V_101 * V_101 , void T_6 * V_362 )
{
struct V_363 V_364 ;
int V_32 ;
if ( ! F_258 ( V_101 -> V_393 , V_394 ) )
return - V_395 ;
if ( F_249 ( & V_364 , V_362 , sizeof( struct V_363 ) ) )
return - V_365 ;
F_248 () ;
V_32 = F_254 ( V_101 , V_364 . V_367 , & V_364 . V_374 , NULL ,
V_364 . V_396 , V_189 ,
V_397 , V_397 ) ;
F_94 () ;
return V_32 ;
}
int F_259 ( struct V_101 * V_101 , void T_6 * V_362 )
{
struct V_363 V_364 ;
int V_32 ;
if ( ! F_258 ( V_101 -> V_393 , V_394 ) )
return - V_395 ;
if ( F_249 ( & V_364 , V_362 , sizeof( struct V_363 ) ) )
return - V_365 ;
F_248 () ;
V_32 = F_256 ( V_101 , V_364 . V_367 , 0 , & V_364 . V_374 ,
V_364 . V_396 ) ;
F_94 () ;
return V_32 ;
}
static void F_260 ( struct V_4 * V_5 , const struct V_155 * V_153 ,
int V_309 , int V_159 )
{
struct V_9 * V_10 ;
V_10 = F_113 ( V_5 , V_153 , NULL , V_309 ,
V_159 , V_189 ,
V_397 , V_397 ) ;
if ( ! F_52 ( V_10 ) ) {
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 &= ~ V_137 ;
F_142 ( & V_10 -> V_36 ) ;
F_149 ( V_398 , V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_261 ( struct V_4 * V_5 )
{
struct V_155 V_153 ;
struct V_6 * V_7 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_159 , V_309 ;
T_1 V_399 = 0 ;
F_29 () ;
memset ( & V_153 , 0 , sizeof( struct V_155 ) ) ;
memcpy ( & V_153 . V_281 [ 3 ] , V_5 -> V_7 -> V_287 , 4 ) ;
if ( V_5 -> V_7 -> V_50 & V_326 ) {
V_153 . V_281 [ 0 ] = F_193 ( 0xfe800000 ) ;
V_159 = V_270 ;
V_309 = 64 ;
} else {
V_159 = V_226 ;
V_309 = 96 ;
V_399 |= V_327 ;
}
if ( V_153 . V_281 [ 3 ] ) {
F_260 ( V_5 , & V_153 , V_309 , V_159 ) ;
F_226 ( & V_153 , V_309 , V_5 -> V_7 , 0 , V_399 ) ;
return;
}
F_90 (net, dev) {
struct V_400 * V_401 = F_262 ( V_7 ) ;
if ( V_401 && ( V_7 -> V_50 & V_77 ) ) {
struct V_402 * V_134 ;
int V_403 = V_159 ;
for ( V_134 = V_401 -> V_404 ; V_134 ; V_134 = V_134 -> V_405 ) {
V_153 . V_281 [ 3 ] = V_134 -> V_406 ;
if ( V_134 -> V_407 == V_408 )
continue;
if ( V_134 -> V_407 >= V_409 ) {
if ( V_5 -> V_7 -> V_50 & V_326 )
continue;
V_403 |= V_273 ;
}
F_260 ( V_5 , & V_153 , V_309 , V_403 ) ;
F_226 ( & V_153 , V_309 , V_5 -> V_7 , 0 ,
V_399 ) ;
}
}
}
}
static void F_263 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_410 ;
struct V_9 * V_411 ;
struct V_162 * V_412 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( V_5 == NULL ) {
F_99 ( L_20 , V_47 ) ;
return;
}
F_260 ( V_5 , & V_413 , 128 , V_273 ) ;
F_90 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_410 -> V_48 , V_7 -> V_48 ) )
continue;
V_5 = F_51 ( V_410 ) ;
if ( ! V_5 )
continue;
F_172 ( & V_5 -> V_36 ) ;
F_86 (sp_ifa, &idev->addr_list, if_list) {
if ( V_411 -> V_50 & ( V_277 | V_137 ) )
continue;
if ( V_411 -> V_149 ) {
if ( V_411 -> V_149 -> V_232 . V_414 > 0 ) {
F_103 ( V_411 -> V_149 ) ;
V_411 -> V_149 = NULL ;
} else {
continue;
}
}
V_412 = F_118 ( V_5 , & V_411 -> V_153 , false ) ;
if ( ! F_52 ( V_412 ) ) {
V_411 -> V_149 = V_412 ;
F_264 ( V_412 ) ;
}
}
F_177 ( & V_5 -> V_36 ) ;
}
}
static void F_265 ( struct V_4 * V_5 , const struct V_155 * V_153 )
{
struct V_9 * V_10 ;
T_1 V_210 = V_189 ;
#ifdef F_159
if ( V_5 -> V_39 . V_227 &&
! F_34 ( V_5 -> V_7 ) -> V_18 . V_115 -> V_45 )
V_210 |= V_224 ;
#endif
V_10 = F_113 ( V_5 , V_153 , NULL , 64 , V_270 , V_210 ,
V_397 , V_397 ) ;
if ( ! F_52 ( V_10 ) ) {
F_226 ( & V_10 -> V_153 , V_10 -> V_178 , V_5 -> V_7 , 0 , 0 ) ;
F_156 ( V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_266 ( struct V_4 * V_5 , bool V_415 )
{
if ( V_5 -> V_416 == V_417 ) {
struct V_155 V_153 ;
F_232 ( & V_153 , F_193 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( F_194 ( V_153 . V_212 + 8 , V_5 -> V_7 ) == 0 )
F_265 ( V_5 , & V_153 ) ;
else if ( V_415 )
F_226 ( & V_153 , 64 , V_5 -> V_7 , 0 , 0 ) ;
}
}
static void F_267 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_298 ) &&
( V_7 -> type != V_299 ) &&
( V_7 -> type != V_300 ) &&
( V_7 -> type != V_301 ) &&
( V_7 -> type != V_304 ) &&
( V_7 -> type != V_305 ) &&
( V_7 -> type != V_63 ) &&
( V_7 -> type != V_303 ) ) {
return;
}
V_5 = F_233 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return;
F_266 ( V_5 , false ) ;
}
static void F_268 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( V_5 == NULL ) {
F_99 ( L_20 , V_47 ) ;
return;
}
if ( V_7 -> V_56 & V_57 ) {
F_266 ( V_5 , false ) ;
return;
}
F_261 ( V_5 ) ;
if ( V_7 -> V_50 & V_326 )
F_231 ( V_7 ) ;
}
static void F_269 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( V_5 == NULL ) {
F_99 ( L_20 , V_47 ) ;
return;
}
F_266 ( V_5 , true ) ;
}
static int F_270 ( struct V_418 * V_419 , unsigned long V_90 ,
void * V_420 )
{
struct V_6 * V_7 = F_271 ( V_420 ) ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
int V_421 = 0 ;
int V_32 ;
switch ( V_90 ) {
case V_422 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_272 ( F_119 ( V_5 ) ) ;
}
break;
case V_183 :
case V_423 :
if ( V_7 -> V_50 & V_424 )
break;
if ( V_5 && V_5 -> V_39 . V_171 )
break;
if ( V_90 == V_183 ) {
if ( ! F_4 ( V_7 ) ) {
F_43 ( L_21 ,
V_7 -> V_48 ) ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 )
V_5 = F_28 ( V_7 ) ;
if ( ! F_243 ( V_5 ) ) {
V_5 -> V_68 |= V_69 ;
V_421 = 1 ;
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
F_43 ( L_22 ,
V_7 -> V_48 ) ;
V_421 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_54 )
case V_55 :
F_268 ( V_7 ) ;
break;
#endif
#if F_42 ( V_425 )
case V_302 :
F_269 ( V_7 ) ;
break;
#endif
case V_426 :
F_263 ( V_7 ) ;
break;
default:
F_267 ( V_7 ) ;
break;
}
if ( ! F_243 ( V_5 ) ) {
if ( V_421 )
F_273 ( V_5 ) ;
if ( V_5 -> V_39 . V_41 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_274 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
}
V_5 -> V_70 = V_13 ;
F_275 ( V_427 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_276 ( V_7 , 1 ) ;
}
break;
case V_428 :
if ( V_5 && V_7 -> V_33 >= V_34 ) {
F_274 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! F_52 ( V_5 ) )
break;
}
case V_200 :
case V_429 :
F_276 ( V_7 , V_90 != V_200 ) ;
break;
case V_430 :
if ( V_5 ) {
F_277 ( V_5 ) ;
F_3 ( V_5 ) ;
V_32 = F_2 ( V_5 ) ;
if ( V_32 )
return F_272 ( V_32 ) ;
V_32 = F_41 ( V_5 ) ;
if ( V_32 ) {
F_3 ( V_5 ) ;
return F_272 ( V_32 ) ;
}
}
break;
case V_431 :
case V_432 :
F_278 ( V_7 , V_90 ) ;
break;
}
return V_433 ;
}
static void F_278 ( struct V_6 * V_7 , unsigned long V_90 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_90 == V_432 )
F_279 ( V_5 ) ;
else if ( V_90 == V_431 )
F_280 ( V_5 ) ;
}
static int F_276 ( struct V_6 * V_7 , int V_434 )
{
struct V_101 * V_101 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_134 ;
int V_147 , V_16 ;
F_29 () ;
F_281 ( V_101 , V_7 ) ;
F_282 ( & V_44 , V_7 ) ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 == NULL )
return - V_169 ;
if ( V_434 ) {
V_5 -> V_76 = 1 ;
F_283 ( V_7 -> V_71 , NULL ) ;
F_277 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_435 ; V_16 ++ ) {
struct V_124 * V_120 = & V_180 [ V_16 ] ;
F_141 ( & V_173 ) ;
V_436:
F_80 (ifa, h, addr_lst) {
if ( V_134 -> V_5 == V_5 ) {
F_143 ( & V_134 -> V_146 ) ;
F_9 ( V_134 ) ;
goto V_436;
}
}
F_142 ( & V_173 ) ;
}
F_144 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_434 )
V_5 -> V_68 &= ~ ( V_437 | V_438 | V_69 ) ;
if ( V_434 && F_7 ( & V_5 -> V_60 ) )
F_100 ( V_5 ) ;
while ( ! F_235 ( & V_5 -> V_59 ) ) {
V_134 = F_284 ( & V_5 -> V_59 ,
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
while ( ! F_235 ( & V_5 -> V_37 ) ) {
V_134 = F_284 ( & V_5 -> V_37 ,
struct V_9 , V_154 ) ;
F_9 ( V_134 ) ;
F_145 ( & V_134 -> V_154 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_141 ( & V_134 -> V_176 ) ;
V_147 = V_134 -> V_147 ;
V_134 -> V_147 = V_148 ;
F_142 ( & V_134 -> V_176 ) ;
if ( V_147 != V_148 ) {
F_285 ( V_199 , V_134 ) ;
F_131 ( V_200 , V_134 ) ;
}
F_146 ( V_134 ) ;
F_144 ( & V_5 -> V_36 ) ;
}
F_148 ( & V_5 -> V_36 ) ;
if ( V_434 ) {
F_286 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_287 ( V_5 ) ;
}
V_5 -> V_70 = V_13 ;
if ( V_434 ) {
F_3 ( V_5 ) ;
F_39 ( & V_44 , V_5 -> V_43 ) ;
F_282 ( & V_44 , V_7 ) ;
F_100 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_307 )
{
struct V_4 * V_5 = (struct V_4 * ) V_307 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_155 V_439 ;
F_126 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 || ! ( V_5 -> V_68 & V_69 ) )
goto V_175;
if ( ! F_288 ( V_5 ) )
goto V_175;
if ( V_5 -> V_68 & V_438 )
goto V_175;
if ( V_5 -> V_440 ++ < V_5 -> V_39 . V_58 ) {
F_128 ( & V_5 -> V_36 ) ;
if ( ! F_180 ( V_7 , & V_439 , V_137 ) )
F_289 ( V_7 , & V_439 ,
& V_75 ) ;
else
goto V_441;
F_126 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_440 ==
V_5 -> V_39 . V_58 ) ?
V_5 -> V_39 . V_442 :
V_5 -> V_39 . V_443 ) ;
} else {
F_99 ( L_23 , V_5 -> V_7 -> V_48 ) ;
}
V_175:
F_128 ( & V_5 -> V_36 ) ;
V_441:
F_100 ( V_5 ) ;
}
static void F_290 ( struct V_9 * V_10 )
{
unsigned long V_444 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_50 & V_224 )
V_444 = 0 ;
else
V_444 = F_291 () % ( V_5 -> V_39 . V_442 ? : 1 ) ;
V_10 -> V_445 = V_5 -> V_39 . V_221 ;
F_16 ( V_10 , V_444 ) ;
}
static void F_292 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_195 ( V_7 , & V_10 -> V_153 ) ;
F_293 ( ( V_383 T_1 ) V_10 -> V_153 . V_281 [ 3 ] ) ;
F_172 ( & V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 == V_148 )
goto V_175;
if ( V_7 -> V_50 & ( V_51 | V_52 ) ||
V_5 -> V_39 . V_53 < 1 ||
! ( V_10 -> V_50 & V_137 ) ||
V_10 -> V_50 & V_446 ) {
V_10 -> V_50 &= ~ ( V_137 | V_224 | V_277 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
F_294 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_68 & V_69 ) ) {
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
F_18 ( V_10 ) ;
F_189 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_50 & V_224 ) {
F_264 ( V_10 -> V_149 ) ;
if ( F_158 ( V_5 ) ) {
F_149 ( V_398 , V_10 ) ;
}
}
F_290 ( V_10 ) ;
V_175:
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
bool V_447 = false ;
F_141 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_147 != V_148 ) {
V_10 -> V_147 = V_448 ;
V_447 = true ;
}
F_142 ( & V_10 -> V_176 ) ;
if ( V_447 )
F_16 ( V_10 , 0 ) ;
}
static void V_177 ( struct V_449 * V_450 )
{
struct V_9 * V_10 = F_295 ( F_296 ( V_450 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_155 V_451 ;
enum {
V_452 ,
V_453 ,
V_454 ,
} V_187 = V_452 ;
F_248 () ;
F_141 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_147 == V_448 ) {
V_187 = V_453 ;
V_10 -> V_147 = V_279 ;
} else if ( V_10 -> V_147 == V_282 ) {
V_187 = V_454 ;
V_10 -> V_147 = V_280 ;
}
F_142 ( & V_10 -> V_176 ) ;
if ( V_187 == V_453 ) {
F_292 ( V_10 ) ;
goto V_175;
} else if ( V_187 == V_454 ) {
F_189 ( V_10 , 1 ) ;
goto V_175;
}
if ( ! V_10 -> V_445 && F_190 ( V_10 ) )
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
if ( V_10 -> V_445 == 0 ) {
V_10 -> V_50 &= ~ ( V_137 | V_224 | V_277 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_294 ( V_10 ) ;
goto V_175;
}
V_10 -> V_445 -- ;
F_16 ( V_10 ,
F_154 ( V_10 -> V_5 -> V_43 , V_222 ) ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_196 ( & V_10 -> V_153 , & V_451 ) ;
F_297 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_153 , & V_451 , & V_67 ) ;
V_175:
F_146 ( V_10 ) ;
F_94 () ;
}
static bool F_298 ( struct V_9 * V_10 )
{
struct V_9 * V_455 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_179 (ifpiter, &idev->addr_list, if_list) {
if ( V_455 -> V_159 > V_270 )
break;
if ( V_10 != V_455 && V_455 -> V_159 == V_270 &&
( V_455 -> V_50 & ( V_189 | V_137 |
V_224 | V_277 ) ) ==
V_189 )
return false ;
}
return true ;
}
static void F_294 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_155 V_439 ;
bool V_456 , V_457 ;
F_9 ( V_10 ) ;
F_149 ( V_398 , V_10 ) ;
F_172 ( & V_10 -> V_5 -> V_36 ) ;
V_457 = V_10 -> V_159 == V_270 && F_298 ( V_10 ) ;
V_456 = V_457 &&
F_288 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_58 > 0 &&
( V_7 -> V_50 & V_52 ) == 0 ;
F_177 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_457 )
F_299 ( V_10 -> V_5 ) ;
if ( V_456 ) {
if ( F_180 ( V_7 , & V_439 , V_137 ) )
return;
F_289 ( V_7 , & V_439 , & V_75 ) ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_440 = 1 ;
V_10 -> V_5 -> V_68 |= V_437 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_443 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_273 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_50 & V_137 &&
V_10 -> V_147 == V_279 )
F_290 ( V_10 ) ;
F_125 ( & V_10 -> V_36 ) ;
}
F_177 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_300 ( struct V_458 * V_89 , T_8 V_459 )
{
struct V_9 * V_134 = NULL ;
struct V_460 * V_147 = V_89 -> V_461 ;
struct V_101 * V_101 = F_301 ( V_89 ) ;
int V_142 = 0 ;
if ( V_459 == 0 ) {
V_147 -> V_462 = 0 ;
V_147 -> V_463 = 0 ;
}
for (; V_147 -> V_462 < V_435 ; ++ V_147 -> V_462 ) {
F_188 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_183 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( V_142 < V_147 -> V_463 ) {
V_142 ++ ;
continue;
}
V_147 -> V_463 ++ ;
return V_134 ;
}
V_147 -> V_463 = 0 ;
V_142 = 0 ;
}
return NULL ;
}
static struct V_9 * F_302 ( struct V_458 * V_89 ,
struct V_9 * V_134 )
{
struct V_460 * V_147 = V_89 -> V_461 ;
struct V_101 * V_101 = F_301 ( V_89 ) ;
F_303 (ifa, addr_lst) {
if ( ! F_183 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_463 ++ ;
return V_134 ;
}
while ( ++ V_147 -> V_462 < V_435 ) {
V_147 -> V_463 = 0 ;
F_188 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_183 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_463 ++ ;
return V_134 ;
}
}
return NULL ;
}
static void * F_304 ( struct V_458 * V_89 , T_8 * V_459 )
__acquires( T_9 )
{
F_115 () ;
return F_300 ( V_89 , * V_459 ) ;
}
static void * F_305 ( struct V_458 * V_89 , void * V_464 , T_8 * V_459 )
{
struct V_9 * V_134 ;
V_134 = F_302 ( V_89 , V_464 ) ;
++ * V_459 ;
return V_134 ;
}
static void F_306 ( struct V_458 * V_89 , void * V_464 )
__releases( T_9 )
{
F_129 () ;
}
static int F_307 ( struct V_458 * V_89 , void * V_464 )
{
struct V_9 * V_10 = (struct V_9 * ) V_464 ;
F_308 ( V_89 , L_24 ,
& V_10 -> V_153 ,
V_10 -> V_5 -> V_7 -> V_85 ,
V_10 -> V_178 ,
V_10 -> V_159 ,
( T_3 ) V_10 -> V_50 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
return 0 ;
}
static int F_309 ( struct V_465 * V_465 , struct V_466 * V_466 )
{
return F_310 ( V_465 , V_466 , & V_467 ,
sizeof( struct V_460 ) ) ;
}
static int T_10 F_311 ( struct V_101 * V_101 )
{
if ( ! F_312 ( L_25 , V_468 , V_101 -> V_469 , & V_470 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_313 ( struct V_101 * V_101 )
{
F_314 ( L_25 , V_101 -> V_469 ) ;
}
int T_12 F_315 ( void )
{
return F_316 ( & V_471 ) ;
}
void F_317 ( void )
{
F_318 ( & V_471 ) ;
}
int F_319 ( struct V_101 * V_101 , const struct V_155 * V_153 )
{
int V_209 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_188 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_183 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_162 ( & V_10 -> V_153 , V_153 ) &&
( V_10 -> V_50 & V_248 ) ) {
V_209 = 1 ;
break;
}
}
F_129 () ;
return V_209 ;
}
static void F_255 ( void )
{
unsigned long V_211 , V_472 , V_473 , V_474 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_115 () ;
V_211 = V_13 ;
V_472 = F_320 ( V_211 + V_475 ) ;
F_10 ( & V_476 ) ;
for ( V_16 = 0 ; V_16 < V_435 ; V_16 ++ ) {
V_436:
F_188 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_206 ;
if ( ( V_10 -> V_50 & V_189 ) &&
( V_10 -> V_161 == V_397 ) )
continue;
F_116 ( & V_10 -> V_36 ) ;
V_206 = ( V_211 - V_10 -> V_70 + V_223 ) / V_3 ;
if ( V_10 -> V_160 != V_397 &&
V_206 >= V_10 -> V_160 ) {
F_125 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_140 ( V_10 ) ;
goto V_436;
} else if ( V_10 -> V_161 == V_397 ) {
F_125 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_206 >= V_10 -> V_161 ) {
int V_477 = 0 ;
if ( ! ( V_10 -> V_50 & V_243 ) ) {
V_477 = 1 ;
V_10 -> V_50 |= V_243 ;
}
if ( ( V_10 -> V_160 != V_397 ) &&
( F_135 ( V_10 -> V_70 + V_10 -> V_160 * V_3 , V_472 ) ) )
V_472 = V_10 -> V_70 + V_10 -> V_160 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
if ( V_477 ) {
F_18 ( V_10 ) ;
F_149 ( 0 , V_10 ) ;
F_146 ( V_10 ) ;
goto V_436;
}
} else if ( ( V_10 -> V_50 & V_181 ) &&
! ( V_10 -> V_50 & V_137 ) ) {
unsigned long V_207 = V_10 -> V_5 -> V_39 . V_215 *
V_10 -> V_5 -> V_39 . V_221 *
F_154 ( V_10 -> V_5 -> V_43 , V_222 ) / V_3 ;
if ( V_206 >= V_10 -> V_161 - V_207 ) {
struct V_9 * V_198 = V_10 -> V_198 ;
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_472 ) )
V_472 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
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
goto V_436;
}
} else if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 - V_207 * V_3 , V_472 ) )
V_472 = V_10 -> V_70 + V_10 -> V_161 * V_3 - V_207 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
} else {
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_472 ) )
V_472 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
}
}
}
V_473 = F_320 ( V_472 ) ;
V_474 = V_472 ;
if ( F_135 ( V_473 , V_472 + V_478 ) )
V_474 = V_473 ;
if ( F_135 ( V_474 , V_13 + V_479 ) )
V_474 = V_13 + V_479 ;
F_38 ( V_480 L_26 ,
V_211 , V_472 , V_473 , V_474 ) ;
F_19 ( V_15 , & V_476 , V_474 - V_211 ) ;
F_129 () ;
}
static void F_321 ( struct V_449 * V_450 )
{
F_248 () ;
F_255 () ;
F_94 () ;
}
static void F_245 ( void )
{
F_19 ( V_15 , & V_476 , 0 ) ;
}
static struct V_155 * F_322 ( struct V_109 * V_153 , struct V_109 * V_481 ,
struct V_155 * * V_389 )
{
struct V_155 * V_308 = NULL ;
* V_389 = NULL ;
if ( V_153 )
V_308 = F_323 ( V_153 ) ;
if ( V_481 ) {
if ( V_308 && F_324 ( V_481 , V_308 , sizeof( * V_308 ) ) )
* V_389 = V_308 ;
V_308 = F_323 ( V_481 ) ;
}
return V_308 ;
}
static int
F_325 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_482 * V_483 ;
struct V_109 * V_110 [ V_484 + 1 ] ;
struct V_155 * V_308 , * V_389 ;
T_1 V_390 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_483 ) , V_110 , V_484 , V_485 ) ;
if ( V_32 < 0 )
return V_32 ;
V_483 = F_60 ( V_92 ) ;
V_308 = F_322 ( V_110 [ V_486 ] , V_110 [ V_487 ] , & V_389 ) ;
if ( V_308 == NULL )
return - V_35 ;
V_390 = V_110 [ V_488 ] ? F_326 ( V_110 [ V_488 ] ) : V_483 -> V_390 ;
V_390 &= V_357 ;
return F_256 ( V_101 , V_483 -> V_489 , V_390 , V_308 ,
V_483 -> V_490 ) ;
}
static int F_327 ( struct V_9 * V_10 , T_1 V_390 ,
T_1 V_161 , T_1 V_160 )
{
T_1 V_50 ;
T_5 V_185 ;
unsigned long V_391 ;
bool V_491 ;
bool V_492 ;
F_29 () ;
if ( ! V_160 || ( V_161 > V_160 ) )
return - V_35 ;
if ( V_390 & V_357 &&
( V_10 -> V_50 & V_181 || V_10 -> V_178 != 64 ) )
return - V_35 ;
V_391 = F_134 ( V_160 , V_3 ) ;
if ( F_240 ( V_391 ) ) {
V_185 = F_242 ( V_391 * V_3 ) ;
V_160 = V_391 ;
V_50 = V_197 ;
} else {
V_185 = 0 ;
V_50 = 0 ;
V_390 |= V_189 ;
}
V_391 = F_134 ( V_161 , V_3 ) ;
if ( F_240 ( V_391 ) ) {
if ( V_391 == 0 )
V_390 |= V_243 ;
V_161 = V_391 ;
}
F_141 ( & V_10 -> V_36 ) ;
V_491 = V_10 -> V_50 & V_357 ;
V_492 = V_10 -> V_50 & V_189 &&
! ( V_10 -> V_50 & V_190 ) ;
V_10 -> V_50 &= ~ ( V_243 | V_189 | V_446 |
V_248 | V_357 |
V_190 ) ;
V_10 -> V_50 |= V_390 ;
V_10 -> V_70 = V_13 ;
V_10 -> V_160 = V_160 ;
V_10 -> V_161 = V_161 ;
F_142 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_137 ) )
F_149 ( 0 , V_10 ) ;
if ( ! ( V_390 & V_190 ) ) {
F_226 ( & V_10 -> V_153 , V_10 -> V_178 , V_10 -> V_5 -> V_7 ,
V_185 , V_50 ) ;
} else if ( V_492 ) {
enum V_184 V_187 ;
unsigned long V_348 ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
V_187 = F_132 ( V_10 , & V_348 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_187 != V_191 ) {
F_136 ( V_10 , V_348 ,
V_187 == V_188 ) ;
}
}
if ( V_491 || V_10 -> V_50 & V_357 ) {
if ( V_491 && ! ( V_10 -> V_50 & V_357 ) )
V_160 = V_161 = 0 ;
F_234 ( V_10 -> V_5 , V_10 , V_160 , V_161 ,
! V_491 , V_13 ) ;
}
F_255 () ;
return 0 ;
}
static int
F_328 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_482 * V_483 ;
struct V_109 * V_110 [ V_484 + 1 ] ;
struct V_155 * V_308 , * V_389 ;
struct V_9 * V_134 ;
struct V_6 * V_7 ;
T_1 V_160 = V_397 , V_493 = V_397 ;
T_1 V_390 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_483 ) , V_110 , V_484 , V_485 ) ;
if ( V_32 < 0 )
return V_32 ;
V_483 = F_60 ( V_92 ) ;
V_308 = F_322 ( V_110 [ V_486 ] , V_110 [ V_487 ] , & V_389 ) ;
if ( V_308 == NULL )
return - V_35 ;
if ( V_110 [ V_494 ] ) {
struct V_495 * V_496 ;
V_496 = F_323 ( V_110 [ V_494 ] ) ;
V_160 = V_496 -> V_497 ;
V_493 = V_496 -> V_498 ;
} else {
V_493 = V_397 ;
V_160 = V_397 ;
}
V_7 = F_74 ( V_101 , V_483 -> V_489 ) ;
if ( V_7 == NULL )
return - V_169 ;
V_390 = V_110 [ V_488 ] ? F_326 ( V_110 [ V_488 ] ) : V_483 -> V_390 ;
V_390 &= V_446 | V_248 | V_357 |
V_190 ;
V_134 = F_187 ( V_101 , V_308 , V_7 , 1 ) ;
if ( V_134 == NULL ) {
return F_254 ( V_101 , V_483 -> V_489 , V_308 , V_389 ,
V_483 -> V_490 , V_390 ,
V_493 , V_160 ) ;
}
if ( V_92 -> V_499 & V_500 ||
! ( V_92 -> V_499 & V_501 ) )
V_32 = - V_174 ;
else
V_32 = F_327 ( V_134 , V_390 , V_493 , V_160 ) ;
F_146 ( V_134 ) ;
return V_32 ;
}
static void F_329 ( struct V_91 * V_92 , T_3 V_502 , T_1 V_50 ,
T_3 V_159 , int V_85 )
{
struct V_482 * V_483 ;
V_483 = F_60 ( V_92 ) ;
V_483 -> V_503 = V_96 ;
V_483 -> V_490 = V_502 ;
V_483 -> V_390 = V_50 ;
V_483 -> V_407 = V_159 ;
V_483 -> V_489 = V_85 ;
}
static int F_330 ( struct V_83 * V_84 , unsigned long V_1 ,
unsigned long V_70 , T_1 V_504 , T_1 V_346 )
{
struct V_495 V_496 ;
V_496 . V_1 = F_1 ( V_1 ) ;
V_496 . V_70 = F_1 ( V_70 ) ;
V_496 . V_498 = V_504 ;
V_496 . V_497 = V_346 ;
return F_331 ( V_84 , V_494 , sizeof( V_496 ) , & V_496 ) ;
}
static inline int F_332 ( int V_407 )
{
if ( V_407 & V_273 )
return V_409 ;
else if ( V_407 & V_270 )
return V_408 ;
else if ( V_407 & V_505 )
return V_506 ;
else
return V_507 ;
}
static inline int F_333 ( void )
{
return F_55 ( sizeof( struct V_482 ) )
+ F_56 ( 16 )
+ F_56 ( 16 )
+ F_56 ( sizeof( struct V_495 ) )
+ F_56 ( 4 ) ;
}
static int F_334 ( struct V_83 * V_84 , struct V_9 * V_134 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_1 V_504 , V_346 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_482 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_329 ( V_92 , V_134 -> V_178 , V_134 -> V_50 , F_332 ( V_134 -> V_159 ) ,
V_134 -> V_5 -> V_7 -> V_85 ) ;
if ( ! ( ( V_134 -> V_50 & V_189 ) &&
( V_134 -> V_161 == V_397 ) ) ) {
V_504 = V_134 -> V_161 ;
V_346 = V_134 -> V_160 ;
if ( V_504 != V_397 ) {
long V_508 = ( V_13 - V_134 -> V_70 ) / V_3 ;
if ( V_504 > V_508 )
V_504 -= V_508 ;
else
V_504 = 0 ;
if ( V_346 != V_397 ) {
if ( V_346 > V_508 )
V_346 -= V_508 ;
else
V_346 = 0 ;
}
}
} else {
V_504 = V_397 ;
V_346 = V_397 ;
}
if ( ! F_200 ( & V_134 -> V_157 ) ) {
if ( F_331 ( V_84 , V_487 , 16 , & V_134 -> V_153 ) < 0 ||
F_331 ( V_84 , V_486 , 16 , & V_134 -> V_157 ) < 0 )
goto error;
} else
if ( F_331 ( V_84 , V_486 , 16 , & V_134 -> V_153 ) < 0 )
goto error;
if ( F_330 ( V_84 , V_134 -> V_1 , V_134 -> V_70 , V_504 , V_346 ) < 0 )
goto error;
if ( F_335 ( V_84 , V_488 , V_134 -> V_50 ) < 0 )
goto error;
return F_62 ( V_84 , V_92 ) ;
error:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_336 ( struct V_83 * V_84 , struct V_509 * V_510 ,
T_1 V_88 , T_1 V_89 , int V_90 , T_13 V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_507 ;
int V_85 = V_510 -> V_5 -> V_7 -> V_85 ;
if ( F_155 ( & V_510 -> V_511 ) & V_505 )
V_159 = V_506 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_482 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_329 ( V_92 , 128 , V_189 , V_159 , V_85 ) ;
if ( F_331 ( V_84 , V_512 , 16 , & V_510 -> V_511 ) < 0 ||
F_330 ( V_84 , V_510 -> V_513 , V_510 -> V_514 ,
V_397 , V_397 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
return F_62 ( V_84 , V_92 ) ;
}
static int F_337 ( struct V_83 * V_84 , struct V_515 * V_516 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_507 ;
int V_85 = V_516 -> V_517 -> V_7 -> V_85 ;
if ( F_155 ( & V_516 -> V_518 ) & V_505 )
V_159 = V_506 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_482 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_329 ( V_92 , 128 , V_189 , V_159 , V_85 ) ;
if ( F_331 ( V_84 , V_519 , 16 , & V_516 -> V_518 ) < 0 ||
F_330 ( V_84 , V_516 -> V_520 , V_516 -> V_521 ,
V_397 , V_397 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
return F_62 ( V_84 , V_92 ) ;
}
static int F_338 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_118 * V_119 , enum V_522 type ,
int V_523 , int * V_524 )
{
struct V_509 * V_510 ;
struct V_515 * V_516 ;
int V_32 = 1 ;
int V_525 = * V_524 ;
F_172 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_526 : {
struct V_9 * V_134 ;
F_86 (ifa, &idev->addr_list, if_list) {
if ( ++ V_525 < V_523 )
continue;
V_32 = F_334 ( V_84 , V_134 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_398 ,
V_131 ) ;
if ( V_32 <= 0 )
break;
F_82 ( V_119 , F_83 ( V_84 ) ) ;
}
break;
}
case V_527 :
for ( V_510 = V_5 -> V_528 ; V_510 ;
V_510 = V_510 -> V_472 , V_525 ++ ) {
if ( V_525 < V_523 )
continue;
V_32 = F_336 ( V_84 , V_510 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_529 ,
V_131 ) ;
if ( V_32 <= 0 )
break;
}
break;
case V_530 :
for ( V_516 = V_5 -> V_531 ; V_516 ;
V_516 = V_516 -> V_532 , V_525 ++ ) {
if ( V_525 < V_523 )
continue;
V_32 = F_337 ( V_84 , V_516 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_533 ,
V_131 ) ;
if ( V_32 <= 0 )
break;
}
break;
default:
break;
}
F_177 ( & V_5 -> V_36 ) ;
* V_524 = V_525 ;
return V_32 ;
}
static int F_339 ( struct V_83 * V_84 , struct V_118 * V_119 ,
enum V_522 type )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
int V_120 , V_121 ;
int V_122 , V_525 ;
int V_123 , V_523 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_124 * V_125 ;
V_121 = V_119 -> args [ 0 ] ;
V_123 = V_122 = V_119 -> args [ 1 ] ;
V_523 = V_525 = V_119 -> args [ 2 ] ;
F_78 () ;
V_119 -> V_89 = F_79 ( & V_101 -> V_18 . V_128 ) ^ V_101 -> V_129 ;
for ( V_120 = V_121 ; V_120 < V_126 ; V_120 ++ , V_123 = 0 ) {
V_122 = 0 ;
V_125 = & V_101 -> V_127 [ V_120 ] ;
F_80 (dev, head, index_hlist) {
if ( V_122 < V_123 )
goto V_130;
if ( V_120 > V_121 || V_122 > V_123 )
V_523 = 0 ;
V_525 = 0 ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_130;
if ( F_338 ( V_5 , V_84 , V_119 , type ,
V_523 , & V_525 ) <= 0 )
goto V_132;
V_130:
V_122 ++ ;
}
}
V_132:
F_81 () ;
V_119 -> args [ 0 ] = V_120 ;
V_119 -> args [ 1 ] = V_122 ;
V_119 -> args [ 2 ] = V_525 ;
return V_84 -> V_133 ;
}
static int F_340 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_522 type = V_526 ;
return F_339 ( V_84 , V_119 , type ) ;
}
static int F_341 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_522 type = V_527 ;
return F_339 ( V_84 , V_119 , type ) ;
}
static int F_342 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_522 type = V_530 ;
return F_339 ( V_84 , V_119 , type ) ;
}
static int F_343 ( struct V_83 * V_107 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_107 -> V_108 ) ;
struct V_482 * V_483 ;
struct V_109 * V_110 [ V_484 + 1 ] ;
struct V_155 * V_153 = NULL , * V_534 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_134 ;
struct V_83 * V_84 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_483 ) , V_110 , V_484 , V_485 ) ;
if ( V_32 < 0 )
goto V_104;
V_153 = F_322 ( V_110 [ V_486 ] , V_110 [ V_487 ] , & V_534 ) ;
if ( V_153 == NULL ) {
V_32 = - V_35 ;
goto V_104;
}
V_483 = F_60 ( V_92 ) ;
if ( V_483 -> V_489 )
V_7 = F_74 ( V_101 , V_483 -> V_489 ) ;
V_134 = F_187 ( V_101 , V_153 , V_7 , 1 ) ;
if ( ! V_134 ) {
V_32 = - V_168 ;
goto V_104;
}
V_84 = F_65 ( F_333 () , V_25 ) ;
if ( ! V_84 ) {
V_32 = - V_102 ;
goto V_535;
}
V_32 = F_334 ( V_84 , V_134 , F_75 ( V_107 ) . V_88 ,
V_92 -> V_117 , V_398 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_535;
}
V_32 = F_76 ( V_84 , V_101 , F_75 ( V_107 ) . V_88 ) ;
V_535:
F_146 ( V_134 ) ;
V_104:
return V_32 ;
}
static void F_344 ( int V_90 , struct V_9 * V_134 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_134 -> V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_333 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_32 = F_334 ( V_84 , V_134 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_536 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_536 , V_32 ) ;
}
static inline void F_345 ( struct V_86 * V_39 ,
T_2 * V_537 , int V_538 )
{
F_346 ( V_538 < ( V_539 * 4 ) ) ;
memset ( V_537 , 0 , V_538 ) ;
V_537 [ V_540 ] = V_39 -> V_45 ;
V_537 [ V_541 ] = V_39 -> V_542 ;
V_537 [ V_543 ] = V_39 -> V_41 ;
V_537 [ V_544 ] = V_39 -> V_545 ;
V_537 [ V_546 ] = V_39 -> V_547 ;
V_537 [ V_548 ] = V_39 -> V_352 ;
V_537 [ V_549 ] = V_39 -> V_221 ;
V_537 [ V_550 ] = V_39 -> V_58 ;
V_537 [ V_551 ] =
F_347 ( V_39 -> V_443 ) ;
V_537 [ V_552 ] =
F_347 ( V_39 -> V_442 ) ;
V_537 [ V_553 ] = V_39 -> V_554 ;
V_537 [ V_555 ] =
F_347 ( V_39 -> V_556 ) ;
V_537 [ V_557 ] =
F_347 ( V_39 -> V_558 ) ;
V_537 [ V_559 ] = V_39 -> V_65 ;
V_537 [ V_560 ] = V_39 -> V_218 ;
V_537 [ V_561 ] = V_39 -> V_219 ;
V_537 [ V_562 ] = V_39 -> V_215 ;
V_537 [ V_563 ] = V_39 -> V_220 ;
V_537 [ V_564 ] = V_39 -> V_355 ;
V_537 [ V_565 ] = V_39 -> V_566 ;
V_537 [ V_567 ] = V_39 -> V_568 ;
#ifdef F_348
V_537 [ V_569 ] = V_39 -> V_570 ;
V_537 [ V_571 ] =
F_347 ( V_39 -> V_572 ) ;
#ifdef F_349
V_537 [ V_573 ] = V_39 -> V_574 ;
#endif
#endif
V_537 [ V_575 ] = V_39 -> V_100 ;
V_537 [ V_576 ] = V_39 -> V_577 ;
#ifdef F_159
V_537 [ V_578 ] = V_39 -> V_227 ;
V_537 [ V_579 ] = V_39 -> V_228 ;
#endif
#ifdef F_57
V_537 [ V_580 ] = V_39 -> V_99 ;
#endif
V_537 [ V_581 ] = V_39 -> V_171 ;
V_537 [ V_582 ] = V_39 -> V_53 ;
V_537 [ V_583 ] = V_39 -> V_584 ;
V_537 [ V_585 ] = V_39 -> V_586 ;
V_537 [ V_587 ] = V_39 -> V_588 ;
V_537 [ V_589 ] = V_39 -> V_590 ;
}
static inline T_14 F_350 ( void )
{
return F_56 ( 4 )
+ F_56 ( sizeof( struct V_591 ) )
+ F_56 ( V_539 * 4 )
+ F_56 ( V_592 * 8 )
+ F_56 ( V_593 * 8 )
+ F_56 ( sizeof( struct V_155 ) ) ;
}
static inline T_14 F_351 ( void )
{
return F_55 ( sizeof( struct V_594 ) )
+ F_56 ( V_595 )
+ F_56 ( V_596 )
+ F_56 ( 4 )
+ F_56 ( 4 )
+ F_56 ( F_350 () ) ;
}
static inline void F_352 ( T_15 * V_17 , T_16 * V_597 ,
int V_598 , int V_538 )
{
int V_16 ;
int V_599 = V_538 - sizeof( T_15 ) * V_598 ;
F_346 ( V_599 < 0 ) ;
F_353 ( V_598 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_598 ; V_16 ++ )
F_353 ( F_354 ( & V_597 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_598 ] , 0 , V_599 ) ;
}
static inline void F_355 ( T_15 * V_17 , void T_17 * V_597 ,
int V_598 , int V_538 , T_14 V_600 )
{
int V_16 ;
int V_599 = V_538 - sizeof( T_15 ) * V_598 ;
F_346 ( V_599 < 0 ) ;
F_353 ( V_598 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_598 ; V_16 ++ )
F_353 ( F_356 ( V_597 , V_16 , V_600 ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_598 ] , 0 , V_599 ) ;
}
static void F_357 ( T_15 * V_17 , struct V_4 * V_5 , int V_601 ,
int V_538 )
{
switch ( V_601 ) {
case V_602 :
F_355 ( V_17 , V_5 -> V_17 . V_18 ,
V_592 , V_538 , F_358 ( struct V_19 , V_22 ) ) ;
break;
case V_603 :
F_352 ( V_17 , V_5 -> V_17 . V_23 -> V_604 , V_593 , V_538 ) ;
break;
}
}
static int F_359 ( struct V_83 * V_84 , struct V_4 * V_5 )
{
struct V_109 * V_605 ;
struct V_591 V_496 ;
if ( F_335 ( V_84 , V_606 , V_5 -> V_68 ) )
goto V_98;
V_496 . V_607 = V_608 ;
V_496 . V_70 = F_1 ( V_5 -> V_70 ) ;
V_496 . V_609 = F_347 ( V_5 -> V_43 -> V_609 ) ;
V_496 . V_610 = F_347 ( F_154 ( V_5 -> V_43 , V_222 ) ) ;
if ( F_331 ( V_84 , V_611 , sizeof( V_496 ) , & V_496 ) )
goto V_98;
V_605 = F_360 ( V_84 , V_612 , V_539 * sizeof( V_613 ) ) ;
if ( V_605 == NULL )
goto V_98;
F_345 ( & V_5 -> V_39 , F_323 ( V_605 ) , F_361 ( V_605 ) ) ;
V_605 = F_360 ( V_84 , V_602 , V_592 * sizeof( T_15 ) ) ;
if ( V_605 == NULL )
goto V_98;
F_357 ( F_323 ( V_605 ) , V_5 , V_602 , F_361 ( V_605 ) ) ;
V_605 = F_360 ( V_84 , V_603 , V_593 * sizeof( T_15 ) ) ;
if ( V_605 == NULL )
goto V_98;
F_357 ( F_323 ( V_605 ) , V_5 , V_603 , F_361 ( V_605 ) ) ;
V_605 = F_360 ( V_84 , V_614 , sizeof( struct V_155 ) ) ;
if ( V_605 == NULL )
goto V_98;
if ( F_362 ( V_84 , V_615 , V_5 -> V_416 ) )
goto V_98;
F_172 ( & V_5 -> V_36 ) ;
memcpy ( F_323 ( V_605 ) , V_5 -> V_66 . V_212 , F_361 ( V_605 ) ) ;
F_177 ( & V_5 -> V_36 ) ;
return 0 ;
V_98:
return - V_94 ;
}
static T_14 F_363 ( const struct V_6 * V_7 )
{
if ( ! F_51 ( V_7 ) )
return 0 ;
return F_350 () ;
}
static int F_364 ( struct V_83 * V_84 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return - V_616 ;
if ( F_359 ( V_84 , V_5 ) < 0 )
return - V_94 ;
return 0 ;
}
static int F_365 ( struct V_4 * V_5 , struct V_155 * V_66 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_617 = false ;
struct V_155 V_618 ;
F_29 () ;
if ( V_66 == NULL )
return - V_35 ;
if ( F_200 ( V_66 ) )
return - V_35 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return - V_35 ;
if ( ! F_288 ( V_5 ) )
return - V_35 ;
if ( V_5 -> V_39 . V_58 <= 0 )
return - V_35 ;
F_144 ( & V_5 -> V_36 ) ;
F_366 ( sizeof( V_66 -> V_212 ) != 16 ) ;
memcpy ( V_5 -> V_66 . V_212 + 8 , V_66 -> V_212 + 8 , 8 ) ;
F_148 ( & V_5 -> V_36 ) ;
if ( ! V_5 -> V_76 && ( V_5 -> V_68 & V_69 ) &&
! F_180 ( V_7 , & V_618 , V_137 |
V_224 ) ) {
F_289 ( V_7 , & V_618 , & V_75 ) ;
V_617 = true ;
}
F_144 ( & V_5 -> V_36 ) ;
if ( V_617 ) {
V_5 -> V_68 |= V_437 ;
V_5 -> V_440 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_443 ) ;
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
F_275 ( V_427 , V_5 ) ;
F_255 () ;
return 0 ;
}
static int F_367 ( struct V_6 * V_7 , const struct V_109 * V_605 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
struct V_109 * V_110 [ V_619 + 1 ] ;
if ( ! V_5 )
return - V_620 ;
if ( F_368 ( V_110 , V_619 , V_605 , NULL ) < 0 )
F_369 () ;
if ( V_110 [ V_614 ] ) {
V_32 = F_365 ( V_5 , F_323 ( V_110 [ V_614 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_110 [ V_615 ] ) {
T_3 V_621 = F_370 ( V_110 [ V_615 ] ) ;
if ( V_621 != V_417 &&
V_621 != V_622 )
return - V_35 ;
V_5 -> V_416 = V_621 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_371 ( struct V_83 * V_84 , struct V_4 * V_5 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_594 * V_623 ;
struct V_91 * V_92 ;
void * V_624 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_623 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_623 = F_60 ( V_92 ) ;
V_623 -> V_625 = V_96 ;
V_623 -> V_626 = 0 ;
V_623 -> V_627 = V_7 -> type ;
V_623 -> V_628 = V_7 -> V_85 ;
V_623 -> V_629 = F_372 ( V_7 ) ;
V_623 -> V_630 = 0 ;
if ( F_373 ( V_84 , V_631 , V_7 -> V_48 ) ||
( V_7 -> V_285 &&
F_331 ( V_84 , V_632 , V_7 -> V_285 , V_7 -> V_287 ) ) ||
F_335 ( V_84 , V_633 , V_7 -> V_33 ) ||
( V_7 -> V_85 != V_7 -> V_634 &&
F_335 ( V_84 , V_635 , V_7 -> V_634 ) ) )
goto V_98;
V_624 = F_374 ( V_84 , V_636 ) ;
if ( V_624 == NULL )
goto V_98;
if ( F_359 ( V_84 , V_5 ) < 0 )
goto V_98;
F_375 ( V_84 , V_624 ) ;
return F_62 ( V_84 , V_92 ) ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_376 ( struct V_83 * V_84 , struct V_118 * V_119 )
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
if ( F_371 ( V_84 , V_5 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_427 , V_131 ) <= 0 )
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
void F_275 ( int V_90 , struct V_4 * V_5 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_351 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_32 = F_371 ( V_84 , V_5 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_637 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_637 , V_32 ) ;
}
static inline T_14 F_377 ( void )
{
return F_55 ( sizeof( struct V_638 ) )
+ F_56 ( sizeof( struct V_155 ) )
+ F_56 ( sizeof( struct V_639 ) ) ;
}
static int F_378 ( struct V_83 * V_84 , struct V_4 * V_5 ,
struct V_342 * V_343 , T_1 V_88 , T_1 V_89 ,
int V_90 , unsigned int V_50 )
{
struct V_638 * V_640 ;
struct V_91 * V_92 ;
struct V_639 V_496 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_640 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_640 = F_60 ( V_92 ) ;
V_640 -> V_641 = V_96 ;
V_640 -> V_642 = 0 ;
V_640 -> V_643 = 0 ;
V_640 -> V_644 = V_5 -> V_7 -> V_85 ;
V_640 -> V_178 = V_343 -> V_178 ;
V_640 -> V_645 = V_343 -> type ;
V_640 -> V_646 = 0 ;
V_640 -> V_647 = 0 ;
if ( V_343 -> V_274 )
V_640 -> V_647 |= V_648 ;
if ( V_343 -> V_352 )
V_640 -> V_647 |= V_649 ;
if ( F_331 ( V_84 , V_650 , sizeof( V_343 -> V_344 ) , & V_343 -> V_344 ) )
goto V_98;
V_496 . V_651 = F_237 ( V_343 -> V_347 ) ;
V_496 . V_652 = F_237 ( V_343 -> V_346 ) ;
if ( F_331 ( V_84 , V_653 , sizeof( V_496 ) , & V_496 ) )
goto V_98;
return F_62 ( V_84 , V_92 ) ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static void F_246 ( int V_90 , struct V_4 * V_5 ,
struct V_342 * V_343 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_377 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_32 = F_378 ( V_84 , V_5 , V_343 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_654 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_654 , V_32 ) ;
}
static void F_285 ( int V_90 , struct V_9 * V_10 )
{
struct V_101 * V_101 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_90 )
F_29 () ;
F_344 ( V_90 ? : V_398 , V_10 ) ;
switch ( V_90 ) {
case V_398 :
if ( ! ( V_10 -> V_149 -> V_655 ) )
F_264 ( V_10 -> V_149 ) ;
if ( V_10 -> V_5 -> V_39 . V_45 )
F_87 ( V_10 ) ;
if ( ! F_200 ( & V_10 -> V_157 ) )
F_226 ( & V_10 -> V_157 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_199 :
if ( V_10 -> V_5 -> V_39 . V_45 )
F_88 ( V_10 ) ;
F_197 ( V_10 -> V_5 , & V_10 -> V_153 ) ;
if ( ! F_200 ( & V_10 -> V_157 ) ) {
struct V_162 * V_149 ;
V_149 = F_137 ( & V_10 -> V_157 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
if ( V_149 && F_138 ( V_149 ) )
F_379 ( & V_149 -> V_232 ) ;
}
F_230 ( & V_10 -> V_149 -> V_232 ) ;
if ( F_138 ( V_10 -> V_149 ) )
F_379 ( & V_10 -> V_149 -> V_232 ) ;
F_380 ( V_101 ) ;
break;
}
F_381 ( & V_101 -> V_18 . V_128 ) ;
}
static void F_149 ( int V_90 , struct V_9 * V_10 )
{
F_115 () ;
if ( F_130 ( V_10 -> V_5 -> V_76 == 0 ) )
F_285 ( V_90 , V_10 ) ;
F_129 () ;
}
static
int F_382 ( struct V_140 * V_656 , int V_657 ,
void T_6 * V_658 , T_14 * V_659 , T_8 * V_660 )
{
int * V_661 = V_656 -> V_307 ;
int V_662 = * V_661 ;
T_8 V_459 = * V_660 ;
struct V_140 V_663 ;
int V_209 ;
V_663 = * V_656 ;
V_663 . V_307 = & V_662 ;
V_209 = F_383 ( & V_663 , V_657 , V_658 , V_659 , V_660 ) ;
if ( V_657 )
V_209 = F_91 ( V_656 , V_661 , V_662 ) ;
if ( V_209 )
* V_660 = V_459 ;
return V_209 ;
}
static void F_384 ( struct V_4 * V_5 )
{
struct V_664 V_665 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_385 ( & V_665 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_171 )
F_270 ( NULL , V_200 , & V_665 ) ;
else
F_270 ( NULL , V_183 , & V_665 ) ;
}
static void F_386 ( struct V_101 * V_101 , T_2 V_138 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_78 () ;
F_171 (net, dev) {
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
int V_139 = ( ! V_5 -> V_39 . V_171 ) ^ ( ! V_138 ) ;
V_5 -> V_39 . V_171 = V_138 ;
if ( V_139 )
F_384 ( V_5 ) ;
}
}
F_81 () ;
}
static int F_387 ( struct V_140 * V_141 , int * V_142 , int V_138 )
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
F_386 ( V_101 , V_138 ) ;
} else if ( ( ! V_138 ) ^ ( ! V_143 ) )
F_384 ( (struct V_4 * ) V_141 -> V_145 ) ;
F_94 () ;
return 0 ;
}
static
int F_388 ( struct V_140 * V_656 , int V_657 ,
void T_6 * V_658 , T_14 * V_659 , T_8 * V_660 )
{
int * V_661 = V_656 -> V_307 ;
int V_662 = * V_661 ;
T_8 V_459 = * V_660 ;
struct V_140 V_663 ;
int V_209 ;
V_663 = * V_656 ;
V_663 . V_307 = & V_662 ;
V_209 = F_383 ( & V_663 , V_657 , V_658 , V_659 , V_660 ) ;
if ( V_657 )
V_209 = F_387 ( V_656 , V_661 , V_662 ) ;
if ( V_209 )
* V_660 = V_459 ;
return V_209 ;
}
static
int F_389 ( struct V_140 * V_656 , int V_657 ,
void T_6 * V_658 , T_14 * V_659 , T_8 * V_660 )
{
int * V_661 = V_656 -> V_307 ;
int V_209 ;
int V_143 , V_666 ;
V_143 = * V_661 ;
V_209 = F_383 ( V_656 , V_657 , V_658 , V_659 , V_660 ) ;
V_666 = * V_661 ;
if ( V_657 && V_143 != V_666 ) {
struct V_101 * V_101 = V_656 -> V_144 ;
if ( ! F_92 () )
return F_93 () ;
if ( V_661 == & V_101 -> V_18 . V_40 -> V_100 )
F_64 ( V_101 , V_82 ,
V_116 ,
V_101 -> V_18 . V_40 ) ;
else if ( V_661 == & V_101 -> V_18 . V_115 -> V_100 )
F_64 ( V_101 , V_82 ,
V_114 ,
V_101 -> V_18 . V_115 ) ;
else {
struct V_4 * V_5 = V_656 -> V_145 ;
F_64 ( V_101 , V_82 ,
V_5 -> V_7 -> V_85 ,
& V_5 -> V_39 ) ;
}
F_94 () ;
}
return V_209 ;
}
static int F_390 ( struct V_101 * V_101 , char * V_667 ,
struct V_4 * V_5 , struct V_86 * V_142 )
{
int V_16 ;
struct V_668 * V_669 ;
char V_670 [ sizeof( L_27 ) + V_595 ] ;
V_669 = F_391 ( & V_671 , sizeof( * V_669 ) , V_25 ) ;
if ( V_669 == NULL )
goto V_175;
for ( V_16 = 0 ; V_669 -> V_672 [ V_16 ] . V_307 ; V_16 ++ ) {
V_669 -> V_672 [ V_16 ] . V_307 += ( char * ) V_142 - ( char * ) & V_86 ;
V_669 -> V_672 [ V_16 ] . V_145 = V_5 ;
V_669 -> V_672 [ V_16 ] . V_144 = V_101 ;
}
snprintf ( V_670 , sizeof( V_670 ) , L_28 , V_667 ) ;
V_669 -> V_673 = F_392 ( V_101 , V_670 , V_669 -> V_672 ) ;
if ( V_669 -> V_673 == NULL )
goto free;
V_142 -> V_42 = V_669 ;
return 0 ;
free:
F_26 ( V_669 ) ;
V_175:
return - V_102 ;
}
static void F_393 ( struct V_86 * V_142 )
{
struct V_668 * V_669 ;
if ( V_142 -> V_42 == NULL )
return;
V_669 = V_142 -> V_42 ;
V_142 -> V_42 = NULL ;
F_394 ( V_669 -> V_673 ) ;
F_26 ( V_669 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_395 ( V_5 -> V_7 -> V_48 ) )
return - V_35 ;
V_32 = F_396 ( V_5 -> V_7 , V_5 -> V_43 ,
& V_674 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_390 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_48 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_397 ( V_5 -> V_43 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_393 ( & V_5 -> V_39 ) ;
F_397 ( V_5 -> V_43 ) ;
}
static int T_10 F_398 ( struct V_101 * V_101 )
{
int V_32 = - V_30 ;
struct V_86 * V_675 , * V_676 ;
V_675 = F_391 ( & V_86 , sizeof( V_86 ) , V_25 ) ;
if ( V_675 == NULL )
goto V_677;
V_676 = F_391 ( & V_678 , sizeof( V_678 ) , V_25 ) ;
if ( V_676 == NULL )
goto V_679;
V_676 -> V_352 = V_680 . V_352 ;
V_676 -> V_171 = V_680 . V_171 ;
V_101 -> V_18 . V_115 = V_675 ;
V_101 -> V_18 . V_40 = V_676 ;
#ifdef F_399
V_32 = F_390 ( V_101 , L_29 , NULL , V_675 ) ;
if ( V_32 < 0 )
goto V_681;
V_32 = F_390 ( V_101 , L_30 , NULL , V_676 ) ;
if ( V_32 < 0 )
goto V_682;
#endif
return 0 ;
#ifdef F_399
V_682:
F_393 ( V_675 ) ;
V_681:
F_26 ( V_676 ) ;
#endif
V_679:
F_26 ( V_675 ) ;
V_677:
return V_32 ;
}
static void T_11 F_400 ( struct V_101 * V_101 )
{
#ifdef F_399
F_393 ( V_101 -> V_18 . V_40 ) ;
F_393 ( V_101 -> V_18 . V_115 ) ;
#endif
F_26 ( V_101 -> V_18 . V_40 ) ;
F_26 ( V_101 -> V_18 . V_115 ) ;
}
int T_12 F_401 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_402 () ;
if ( V_32 < 0 ) {
F_403 ( L_31 ,
V_47 , V_32 ) ;
goto V_175;
}
V_32 = F_316 ( & V_683 ) ;
if ( V_32 < 0 )
goto V_684;
V_15 = F_404 ( L_32 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_685;
}
F_248 () ;
V_5 = F_28 ( V_686 . V_687 ) ;
F_94 () ;
if ( F_52 ( V_5 ) ) {
V_32 = F_119 ( V_5 ) ;
goto V_688;
}
for ( V_16 = 0 ; V_16 < V_435 ; V_16 ++ )
F_405 ( & V_180 [ V_16 ] ) ;
F_406 ( & V_689 ) ;
F_245 () ;
F_407 ( & V_690 ) ;
V_32 = F_408 ( V_691 , V_692 , NULL , F_376 ,
NULL ) ;
if ( V_32 < 0 )
goto V_104;
F_408 ( V_691 , V_398 , F_328 , NULL , NULL ) ;
F_408 ( V_691 , V_199 , F_325 , NULL , NULL ) ;
F_408 ( V_691 , V_693 , F_343 ,
F_340 , NULL ) ;
F_408 ( V_691 , V_529 , NULL ,
F_341 , NULL ) ;
F_408 ( V_691 , V_533 , NULL ,
F_342 , NULL ) ;
F_408 ( V_691 , V_694 , F_70 ,
F_77 , NULL ) ;
F_409 () ;
return 0 ;
V_104:
F_410 ( & V_690 ) ;
F_411 ( & V_689 ) ;
V_688:
F_412 ( V_15 ) ;
V_685:
F_318 ( & V_683 ) ;
V_684:
F_413 () ;
V_175:
return V_32 ;
}
void F_414 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_411 ( & V_689 ) ;
F_318 ( & V_683 ) ;
F_413 () ;
F_248 () ;
F_415 ( & V_690 ) ;
F_90 (&init_net, dev) {
if ( F_51 ( V_7 ) == NULL )
continue;
F_276 ( V_7 , 1 ) ;
}
F_276 ( V_686 . V_687 , 2 ) ;
F_141 ( & V_173 ) ;
for ( V_16 = 0 ; V_16 < V_435 ; V_16 ++ )
F_66 ( ! F_416 ( & V_180 [ V_16 ] ) ) ;
F_142 ( & V_173 ) ;
F_10 ( & V_476 ) ;
F_94 () ;
F_412 ( V_15 ) ;
}
