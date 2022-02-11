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
F_62 ( V_84 , V_92 ) ;
return 0 ;
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
- 1 ) < 0 ) {
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
- 1 ) < 0 )
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
- 1 ) < 0 )
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
return F_183 ( V_101 , V_153 , V_7 , V_272 , V_137 ) ;
}
int F_183 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
const struct V_6 * V_7 , int V_272 ,
T_1 V_269 )
{
struct V_9 * V_10 ;
unsigned int V_163 = F_110 ( V_153 ) ;
T_1 V_273 ;
F_115 () ;
F_80 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_184 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_273 = ( V_10 -> V_50 & V_224 )
? ( V_10 -> V_50 & ~ V_137 )
: V_10 -> V_50 ;
if ( F_162 ( & V_10 -> V_153 , V_153 ) &&
! ( V_273 & V_269 ) &&
( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_159 & ( V_270 | V_274 ) || V_272 ) ) ) {
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
F_185 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_184 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_162 ( & V_10 -> V_153 , V_153 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_186 ( const struct V_155 * V_153 ,
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
int F_187 ( const struct V_155 * V_153 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_134 ;
int V_275 ;
V_275 = 0 ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifa, &idev->addr_list, if_list) {
V_275 = F_133 ( V_153 , & V_134 -> V_153 ,
V_134 -> V_178 ) ;
if ( V_275 )
break;
}
F_177 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_275 ;
}
struct V_9 * F_188 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
struct V_6 * V_7 , int V_272 )
{
struct V_9 * V_10 , * V_276 = NULL ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_189 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_184 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_162 ( & V_10 -> V_153 , V_153 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_159 & ( V_270 | V_274 ) || V_272 ) ) {
V_276 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_129 () ;
return V_276 ;
}
static void F_190 ( struct V_9 * V_10 , int V_277 )
{
if ( V_10 -> V_50 & V_189 ) {
F_141 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_50 |= V_137 ;
if ( V_277 )
V_10 -> V_50 |= V_278 ;
F_142 ( & V_10 -> V_36 ) ;
if ( V_277 )
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
static int F_191 ( struct V_9 * V_10 )
{
int V_32 = - V_279 ;
F_141 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_147 == V_280 ) {
V_10 -> V_147 = V_281 ;
V_32 = 0 ;
}
F_142 ( & V_10 -> V_176 ) ;
return V_32 ;
}
void F_192 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_191 ( V_10 ) ) {
F_146 ( V_10 ) ;
return;
}
F_193 ( L_13 ,
V_10 -> V_5 -> V_7 -> V_48 , & V_10 -> V_153 ) ;
if ( V_5 -> V_39 . V_53 > 1 && ! V_5 -> V_39 . V_171 ) {
struct V_155 V_153 ;
V_153 . V_282 [ 0 ] = F_194 ( 0xfe800000 ) ;
V_153 . V_282 [ 1 ] = 0 ;
if ( ! F_195 ( V_153 . V_212 + 8 , V_5 -> V_7 ) &&
F_162 ( & V_10 -> V_153 , & V_153 ) ) {
V_5 -> V_39 . V_171 = 1 ;
F_43 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
}
}
F_141 ( & V_10 -> V_176 ) ;
V_10 -> V_147 = V_283 ;
F_142 ( & V_10 -> V_176 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_196 ( struct V_6 * V_7 , const struct V_155 * V_153 )
{
struct V_155 V_284 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_197 ( V_153 , & V_284 ) ;
F_48 ( V_7 , & V_284 ) ;
}
void F_198 ( struct V_4 * V_5 , const struct V_155 * V_153 )
{
struct V_155 V_284 ;
if ( V_5 -> V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_197 ( V_153 , & V_284 ) ;
F_199 ( V_5 , & V_284 ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_155 V_153 ;
if ( V_10 -> V_178 >= 127 )
return;
F_200 ( & V_153 , & V_10 -> V_153 , V_10 -> V_178 ) ;
if ( F_201 ( & V_153 ) )
return;
F_202 ( V_10 -> V_5 , & V_153 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_155 V_153 ;
if ( V_10 -> V_178 >= 127 )
return;
F_200 ( & V_153 , & V_10 -> V_153 , V_10 -> V_178 ) ;
if ( F_201 ( & V_153 ) )
return;
F_203 ( V_10 -> V_5 , & V_153 ) ;
}
static int F_204 ( T_3 * V_285 , struct V_6 * V_7 )
{
if ( V_7 -> V_286 != V_287 )
return - 1 ;
memcpy ( V_285 , V_7 -> V_288 , 3 ) ;
memcpy ( V_285 + 5 , V_7 -> V_288 + 3 , 3 ) ;
if ( V_7 -> V_289 ) {
V_285 [ 3 ] = ( V_7 -> V_289 >> 8 ) & 0xFF ;
V_285 [ 4 ] = V_7 -> V_289 & 0xFF ;
} else {
V_285 [ 3 ] = 0xFF ;
V_285 [ 4 ] = 0xFE ;
V_285 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_205 ( T_3 * V_285 , struct V_6 * V_7 )
{
if ( V_7 -> V_286 != V_290 )
return - 1 ;
memcpy ( V_285 , V_7 -> V_288 , 8 ) ;
V_285 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_206 ( T_3 * V_285 , struct V_6 * V_7 )
{
union V_291 * V_292 ;
if ( V_7 -> V_286 != V_293 )
return - 1 ;
V_292 = (union V_291 * ) V_7 -> V_288 ;
memcpy ( V_285 , & V_292 -> V_294 . V_295 , sizeof( V_292 -> V_294 . V_295 ) ) ;
V_285 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_207 ( T_3 * V_285 , struct V_6 * V_7 )
{
if ( V_7 -> V_286 != V_296 )
return - 1 ;
memset ( V_285 , 0 , 7 ) ;
V_285 [ 7 ] = * ( T_3 * ) V_7 -> V_288 ;
return 0 ;
}
static int F_208 ( T_3 * V_285 , struct V_6 * V_7 )
{
if ( V_7 -> V_286 != V_297 )
return - 1 ;
memcpy ( V_285 , V_7 -> V_288 + 12 , 8 ) ;
V_285 [ 0 ] |= 2 ;
return 0 ;
}
static int F_209 ( T_3 * V_285 , T_4 V_153 )
{
if ( V_153 == 0 )
return - 1 ;
V_285 [ 0 ] = ( F_210 ( V_153 ) || F_211 ( V_153 ) ||
F_212 ( V_153 ) || F_213 ( V_153 ) ||
F_214 ( V_153 ) || F_215 ( V_153 ) ||
F_216 ( V_153 ) || F_217 ( V_153 ) ||
F_218 ( V_153 ) || F_219 ( V_153 ) ||
F_220 ( V_153 ) ) ? 0x00 : 0x02 ;
V_285 [ 1 ] = 0 ;
V_285 [ 2 ] = 0x5E ;
V_285 [ 3 ] = 0xFE ;
memcpy ( V_285 + 4 , & V_153 , 4 ) ;
return 0 ;
}
static int F_221 ( T_3 * V_285 , struct V_6 * V_7 )
{
if ( V_7 -> V_56 & V_57 )
return F_209 ( V_285 , * ( T_4 * ) V_7 -> V_288 ) ;
return - 1 ;
}
static int F_222 ( T_3 * V_285 , struct V_6 * V_7 )
{
return F_209 ( V_285 , * ( T_4 * ) V_7 -> V_288 ) ;
}
static int F_223 ( T_3 * V_285 , struct V_6 * V_7 )
{
memcpy ( V_285 , V_7 -> V_298 , 3 ) ;
memcpy ( V_285 + 5 , V_7 -> V_298 + 3 , 3 ) ;
V_285 [ 3 ] = 0xFF ;
V_285 [ 4 ] = 0xFE ;
V_285 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_195 ( T_3 * V_285 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_299 :
case V_300 :
return F_204 ( V_285 , V_7 ) ;
case V_301 :
return F_207 ( V_285 , V_7 ) ;
case V_302 :
return F_208 ( V_285 , V_7 ) ;
case V_55 :
return F_221 ( V_285 , V_7 ) ;
case V_303 :
return F_222 ( V_285 , V_7 ) ;
case V_304 :
case V_305 :
return F_205 ( V_285 , V_7 ) ;
case V_306 :
return F_206 ( V_285 , V_7 ) ;
case V_63 :
return F_223 ( V_285 , V_7 ) ;
}
return - 1 ;
}
static int F_224 ( T_3 * V_285 , struct V_4 * V_5 )
{
int V_32 = - 1 ;
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_179 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_159 > V_270 )
break;
if ( V_10 -> V_159 == V_270 && ! ( V_10 -> V_50 & V_137 ) ) {
memcpy ( V_285 , V_10 -> V_153 . V_212 + 8 , 8 ) ;
V_32 = 0 ;
break;
}
}
F_177 ( & V_5 -> V_36 ) ;
return V_32 ;
}
static void F_225 ( struct V_4 * V_5 )
{
V_307:
F_226 ( V_5 -> V_216 , sizeof( V_5 -> V_216 ) ) ;
V_5 -> V_216 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_216 [ 0 ] == 0xfd &&
( V_5 -> V_216 [ 1 ] & V_5 -> V_216 [ 2 ] & V_5 -> V_216 [ 3 ] & V_5 -> V_216 [ 4 ] & V_5 -> V_216 [ 5 ] & V_5 -> V_216 [ 6 ] ) == 0xff &&
( V_5 -> V_216 [ 7 ] & 0x80 ) )
goto V_307;
if ( ( V_5 -> V_216 [ 0 ] | V_5 -> V_216 [ 1 ] ) == 0 ) {
if ( V_5 -> V_216 [ 2 ] == 0x5e && V_5 -> V_216 [ 3 ] == 0xfe )
goto V_307;
if ( ( V_5 -> V_216 [ 2 ] | V_5 -> V_216 [ 3 ] | V_5 -> V_216 [ 4 ] | V_5 -> V_216 [ 5 ] | V_5 -> V_216 [ 6 ] | V_5 -> V_216 [ 7 ] ) == 0x00 )
goto V_307;
}
}
static void V_61 ( unsigned long V_308 )
{
struct V_4 * V_5 = (struct V_4 * ) V_308 ;
unsigned long V_185 ;
F_115 () ;
F_144 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 )
goto V_175;
F_225 ( V_5 ) ;
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
F_225 ( V_5 ) ;
}
static void
F_227 ( struct V_155 * V_309 , int V_310 , struct V_6 * V_7 ,
unsigned long V_185 , T_1 V_50 )
{
struct V_311 V_312 = {
. V_313 = V_314 ,
. V_315 = V_316 ,
. V_317 = V_7 -> V_85 ,
. V_318 = V_185 ,
. V_319 = V_310 ,
. V_320 = V_321 | V_50 ,
. V_322 . V_323 = F_34 ( V_7 ) ,
. V_324 = V_325 ,
} ;
V_312 . V_326 = * V_309 ;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 && ( V_7 -> V_50 & V_327 ) )
V_312 . V_320 |= V_328 ;
#endif
F_228 ( & V_312 ) ;
}
static struct V_162 * F_137 ( const struct V_155 * V_309 ,
int V_310 ,
const struct V_6 * V_7 ,
T_1 V_50 , T_1 V_329 )
{
struct V_330 * V_331 ;
struct V_162 * V_149 = NULL ;
struct V_332 * V_141 ;
V_141 = F_229 ( F_34 ( V_7 ) , V_314 ) ;
if ( V_141 == NULL )
return NULL ;
F_172 ( & V_141 -> V_333 ) ;
V_331 = F_230 ( & V_141 -> V_334 , V_309 , V_310 , NULL , 0 ) ;
if ( ! V_331 )
goto V_175;
for ( V_149 = V_331 -> V_335 ; V_149 ; V_149 = V_149 -> V_232 . V_336 ) {
if ( V_149 -> V_232 . V_7 -> V_85 != V_7 -> V_85 )
continue;
if ( ( V_149 -> V_196 & V_50 ) != V_50 )
continue;
if ( ( V_149 -> V_196 & V_329 ) != 0 )
continue;
F_231 ( & V_149 -> V_232 ) ;
break;
}
V_175:
F_177 ( & V_141 -> V_333 ) ;
return V_149 ;
}
static void F_232 ( struct V_6 * V_7 )
{
struct V_311 V_312 = {
. V_313 = V_337 ,
. V_315 = V_316 ,
. V_317 = V_7 -> V_85 ,
. V_319 = 8 ,
. V_320 = V_321 ,
. V_322 . V_323 = F_34 ( V_7 ) ,
} ;
F_233 ( & V_312 . V_326 , F_194 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_228 ( & V_312 ) ;
}
static struct V_4 * F_234 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
return F_30 ( - V_102 ) ;
if ( V_5 -> V_39 . V_171 )
return F_30 ( - V_172 ) ;
if ( ! ( V_7 -> V_50 & V_52 ) )
F_232 ( V_7 ) ;
return V_5 ;
}
static void F_235 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_217 V_160 , V_217 V_161 ,
bool V_338 , unsigned long V_211 )
{
T_1 V_50 ;
struct V_9 * V_201 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ift, &idev->tempaddr_list, tmp_list) {
int V_206 , V_339 , V_340 ;
if ( V_10 != V_201 -> V_198 )
continue;
V_206 = ( V_211 - V_201 -> V_1 ) / V_3 ;
V_339 = V_5 -> V_39 . V_218 - V_206 ;
if ( V_339 < 0 )
V_339 = 0 ;
V_340 = V_5 -> V_39 . V_219 -
V_5 -> V_39 . V_220 - V_206 ;
if ( V_340 < 0 )
V_340 = 0 ;
if ( V_160 > V_339 )
V_160 = V_339 ;
if ( V_161 > V_340 )
V_161 = V_340 ;
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
if ( ( V_338 || F_236 ( & V_5 -> V_59 ) ) &&
V_5 -> V_39 . V_65 > 0 ) {
F_177 ( & V_5 -> V_36 ) ;
F_151 ( V_10 , NULL ) ;
} else {
F_177 ( & V_5 -> V_36 ) ;
}
}
void F_237 ( struct V_6 * V_7 , T_3 * V_341 , int V_133 , bool V_342 )
{
struct V_343 * V_344 ;
V_217 V_160 ;
V_217 V_161 ;
int V_164 ;
struct V_4 * V_112 ;
struct V_101 * V_101 = F_34 ( V_7 ) ;
V_344 = (struct V_343 * ) V_341 ;
if ( V_133 < sizeof( struct V_343 ) ) {
F_38 ( L_16 ) ;
return;
}
V_164 = F_114 ( & V_344 -> V_345 ) ;
if ( V_164 & ( V_166 | V_346 ) )
return;
V_160 = F_238 ( V_344 -> V_347 ) ;
V_161 = F_238 ( V_344 -> V_348 ) ;
if ( V_161 > V_160 ) {
F_239 ( L_17 ) ;
return;
}
V_112 = F_240 ( V_7 ) ;
if ( V_112 == NULL ) {
F_174 ( L_18 ,
V_7 -> V_48 ) ;
return;
}
if ( V_344 -> V_275 ) {
struct V_162 * V_149 ;
unsigned long V_349 ;
if ( V_3 > V_350 )
V_349 = F_134 ( V_160 , V_3 ) ;
else
V_349 = F_134 ( V_160 , V_350 ) ;
if ( F_241 ( V_349 ) )
V_349 *= V_3 ;
V_149 = F_137 ( & V_344 -> V_345 ,
V_344 -> V_178 ,
V_7 ,
V_351 | V_352 ,
V_194 | V_195 ) ;
if ( V_149 ) {
if ( V_160 == 0 ) {
F_138 ( V_149 ) ;
V_149 = NULL ;
} else if ( F_241 ( V_349 ) ) {
F_139 ( V_149 , V_13 + V_349 ) ;
} else {
F_242 ( V_149 ) ;
}
} else if ( V_160 ) {
T_5 V_185 = 0 ;
int V_50 = V_351 | V_352 ;
if ( F_241 ( V_349 ) ) {
V_50 |= V_197 ;
V_185 = F_243 ( V_349 ) ;
}
F_227 ( & V_344 -> V_345 , V_344 -> V_178 ,
V_7 , V_185 , V_50 ) ;
}
F_103 ( V_149 ) ;
}
if ( V_344 -> V_353 && V_112 -> V_39 . V_353 ) {
struct V_9 * V_10 ;
struct V_155 V_153 ;
int V_338 = 0 , V_354 = 0 ;
bool V_179 = false ;
if ( V_344 -> V_178 == 64 ) {
memcpy ( & V_153 , & V_344 -> V_345 , 8 ) ;
if ( ! F_201 ( & V_112 -> V_66 ) ) {
F_172 ( & V_112 -> V_36 ) ;
memcpy ( V_153 . V_212 + 8 ,
V_112 -> V_66 . V_212 + 8 , 8 ) ;
F_177 ( & V_112 -> V_36 ) ;
V_179 = true ;
} else if ( F_195 ( V_153 . V_212 + 8 , V_7 ) &&
F_224 ( V_153 . V_212 + 8 , V_112 ) ) {
F_100 ( V_112 ) ;
return;
}
goto V_355;
}
F_174 ( L_19 ,
V_344 -> V_178 ) ;
F_100 ( V_112 ) ;
return;
V_355:
V_10 = F_188 ( V_101 , & V_153 , V_7 , 1 ) ;
if ( V_10 == NULL && V_160 ) {
int V_356 = V_112 -> V_39 . V_356 ;
T_1 V_210 = 0 ;
#ifdef F_159
if ( V_112 -> V_39 . V_227 &&
! V_101 -> V_18 . V_115 -> V_45 && V_342 )
V_210 = V_224 ;
#endif
if ( ! V_356 ||
F_181 ( V_112 ) < V_356 )
V_10 = F_113 ( V_112 , & V_153 , NULL ,
V_344 -> V_178 ,
V_164 & V_357 ,
V_210 , V_160 ,
V_161 ) ;
if ( F_244 ( V_10 ) ) {
F_100 ( V_112 ) ;
return;
}
V_354 = 0 ;
V_338 = 1 ;
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 |= V_358 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_179 = V_179 ;
F_142 ( & V_10 -> V_36 ) ;
F_156 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_50 ;
unsigned long V_211 ;
T_1 V_359 ;
F_116 ( & V_10 -> V_36 ) ;
V_211 = V_13 ;
if ( V_10 -> V_160 > ( V_211 - V_10 -> V_70 ) / V_3 )
V_359 = V_10 -> V_160 - ( V_211 - V_10 -> V_70 ) / V_3 ;
else
V_359 = 0 ;
if ( ! V_354 && ! V_338 && V_359 ) {
const T_1 V_360 = F_153 ( T_1 ,
V_359 , V_361 ) ;
V_160 = F_245 ( V_160 , V_360 ) ;
V_354 = 1 ;
}
if ( V_354 ) {
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
F_235 ( V_112 , V_10 , V_160 , V_161 ,
V_338 , V_211 ) ;
F_146 ( V_10 ) ;
F_246 () ;
}
}
F_247 ( V_362 , V_112 , V_344 ) ;
F_100 ( V_112 ) ;
}
int F_248 ( struct V_101 * V_101 , void T_6 * V_363 )
{
struct V_364 V_365 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_249 () ;
V_32 = - V_366 ;
if ( F_250 ( & V_365 , V_363 , sizeof( struct V_364 ) ) )
goto V_367;
V_7 = F_74 ( V_101 , V_365 . V_368 ) ;
V_32 = - V_169 ;
if ( V_7 == NULL )
goto V_367;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 ) {
const struct V_369 * V_370 = V_7 -> V_371 ;
struct V_372 V_373 ;
struct V_374 V_142 ;
V_32 = - V_168 ;
if ( ! ( F_114 ( & V_365 . V_375 ) & V_226 ) )
goto V_367;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_376 . V_259 = V_365 . V_375 . V_282 [ 3 ] ;
V_142 . V_376 . V_260 = 0 ;
V_142 . V_376 . V_377 = 4 ;
V_142 . V_376 . V_378 = 5 ;
V_142 . V_376 . V_379 = V_380 ;
V_142 . V_376 . V_381 = 64 ;
V_373 . V_382 . V_383 = ( V_384 void T_6 * ) & V_142 ;
if ( V_370 -> V_385 ) {
T_7 V_386 = F_251 () ;
F_252 ( V_387 ) ;
V_32 = V_370 -> V_385 ( V_7 , & V_373 , V_388 ) ;
F_252 ( V_386 ) ;
} else
V_32 = - V_389 ;
if ( V_32 == 0 ) {
V_32 = - V_102 ;
V_7 = F_253 ( V_101 , V_142 . V_48 ) ;
if ( ! V_7 )
goto V_367;
V_32 = F_254 ( V_7 ) ;
}
}
#endif
V_367:
F_94 () ;
return V_32 ;
}
static int F_255 ( struct V_101 * V_101 , int V_85 ,
const struct V_155 * V_309 ,
const struct V_155 * V_390 ,
unsigned int V_310 , V_217 V_391 ,
V_217 V_161 , V_217 V_160 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_159 ;
T_1 V_50 ;
T_5 V_185 ;
unsigned long V_392 ;
F_29 () ;
if ( V_310 > 128 )
return - V_35 ;
if ( ! V_160 || V_161 > V_160 )
return - V_35 ;
if ( V_391 & V_358 && V_310 != 64 )
return - V_35 ;
V_7 = F_74 ( V_101 , V_85 ) ;
if ( ! V_7 )
return - V_169 ;
V_5 = F_234 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_119 ( V_5 ) ;
V_159 = F_155 ( V_309 ) ;
V_392 = F_134 ( V_160 , V_3 ) ;
if ( F_241 ( V_392 ) ) {
V_185 = F_243 ( V_392 * V_3 ) ;
V_160 = V_392 ;
V_50 = V_197 ;
} else {
V_185 = 0 ;
V_50 = 0 ;
V_391 |= V_189 ;
}
V_392 = F_134 ( V_161 , V_3 ) ;
if ( F_241 ( V_392 ) ) {
if ( V_392 == 0 )
V_391 |= V_243 ;
V_161 = V_392 ;
}
V_10 = F_113 ( V_5 , V_309 , V_390 , V_310 , V_159 , V_391 ,
V_160 , V_161 ) ;
if ( ! F_52 ( V_10 ) ) {
if ( ! ( V_391 & V_190 ) ) {
F_227 ( & V_10 -> V_153 , V_10 -> V_178 , V_7 ,
V_185 , V_50 ) ;
}
F_156 ( V_10 ) ;
if ( V_391 & V_358 )
F_235 ( V_5 , V_10 , V_160 , V_161 ,
true , V_13 ) ;
F_146 ( V_10 ) ;
F_256 () ;
return 0 ;
}
return F_119 ( V_10 ) ;
}
static int F_257 ( struct V_101 * V_101 , int V_85 , T_1 V_391 ,
const struct V_155 * V_309 , unsigned int V_310 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_310 > 128 )
return - V_35 ;
V_7 = F_74 ( V_101 , V_85 ) ;
if ( ! V_7 )
return - V_169 ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 == NULL )
return - V_393 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_178 == V_310 &&
F_162 ( V_309 , & V_10 -> V_153 ) ) {
F_18 ( V_10 ) ;
F_177 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_181 ) &&
( V_391 & V_358 ) )
F_235 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_140 ( V_10 ) ;
F_256 () ;
return 0 ;
}
}
F_177 ( & V_5 -> V_36 ) ;
return - V_168 ;
}
int F_258 ( struct V_101 * V_101 , void T_6 * V_363 )
{
struct V_364 V_365 ;
int V_32 ;
if ( ! F_259 ( V_101 -> V_394 , V_395 ) )
return - V_396 ;
if ( F_250 ( & V_365 , V_363 , sizeof( struct V_364 ) ) )
return - V_366 ;
F_249 () ;
V_32 = F_255 ( V_101 , V_365 . V_368 , & V_365 . V_375 , NULL ,
V_365 . V_397 , V_189 ,
V_398 , V_398 ) ;
F_94 () ;
return V_32 ;
}
int F_260 ( struct V_101 * V_101 , void T_6 * V_363 )
{
struct V_364 V_365 ;
int V_32 ;
if ( ! F_259 ( V_101 -> V_394 , V_395 ) )
return - V_396 ;
if ( F_250 ( & V_365 , V_363 , sizeof( struct V_364 ) ) )
return - V_366 ;
F_249 () ;
V_32 = F_257 ( V_101 , V_365 . V_368 , 0 , & V_365 . V_375 ,
V_365 . V_397 ) ;
F_94 () ;
return V_32 ;
}
static void F_261 ( struct V_4 * V_5 , const struct V_155 * V_153 ,
int V_310 , int V_159 )
{
struct V_9 * V_10 ;
V_10 = F_113 ( V_5 , V_153 , NULL , V_310 ,
V_159 , V_189 ,
V_398 , V_398 ) ;
if ( ! F_52 ( V_10 ) ) {
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 &= ~ V_137 ;
F_142 ( & V_10 -> V_36 ) ;
F_149 ( V_399 , V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_262 ( struct V_4 * V_5 )
{
struct V_155 V_153 ;
struct V_6 * V_7 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_159 , V_310 ;
T_1 V_400 = 0 ;
F_29 () ;
memset ( & V_153 , 0 , sizeof( struct V_155 ) ) ;
memcpy ( & V_153 . V_282 [ 3 ] , V_5 -> V_7 -> V_288 , 4 ) ;
if ( V_5 -> V_7 -> V_50 & V_327 ) {
V_153 . V_282 [ 0 ] = F_194 ( 0xfe800000 ) ;
V_159 = V_270 ;
V_310 = 64 ;
} else {
V_159 = V_226 ;
V_310 = 96 ;
V_400 |= V_328 ;
}
if ( V_153 . V_282 [ 3 ] ) {
F_261 ( V_5 , & V_153 , V_310 , V_159 ) ;
F_227 ( & V_153 , V_310 , V_5 -> V_7 , 0 , V_400 ) ;
return;
}
F_90 (net, dev) {
struct V_401 * V_402 = F_263 ( V_7 ) ;
if ( V_402 && ( V_7 -> V_50 & V_77 ) ) {
struct V_403 * V_134 ;
int V_404 = V_159 ;
for ( V_134 = V_402 -> V_405 ; V_134 ; V_134 = V_134 -> V_406 ) {
V_153 . V_282 [ 3 ] = V_134 -> V_407 ;
if ( V_134 -> V_408 == V_409 )
continue;
if ( V_134 -> V_408 >= V_410 ) {
if ( V_5 -> V_7 -> V_50 & V_327 )
continue;
V_404 |= V_274 ;
}
F_261 ( V_5 , & V_153 , V_310 , V_404 ) ;
F_227 ( & V_153 , V_310 , V_5 -> V_7 , 0 ,
V_400 ) ;
}
}
}
}
static void F_264 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_411 ;
struct V_9 * V_412 ;
struct V_162 * V_413 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( V_5 == NULL ) {
F_99 ( L_20 , V_47 ) ;
return;
}
F_261 ( V_5 , & V_414 , 128 , V_274 ) ;
F_90 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_411 -> V_48 , V_7 -> V_48 ) )
continue;
V_5 = F_51 ( V_411 ) ;
if ( ! V_5 )
continue;
F_172 ( & V_5 -> V_36 ) ;
F_86 (sp_ifa, &idev->addr_list, if_list) {
if ( V_412 -> V_50 & ( V_278 | V_137 ) )
continue;
if ( V_412 -> V_149 ) {
if ( V_412 -> V_149 -> V_232 . V_415 > 0 ) {
F_103 ( V_412 -> V_149 ) ;
V_412 -> V_149 = NULL ;
} else {
continue;
}
}
V_413 = F_118 ( V_5 , & V_412 -> V_153 , false ) ;
if ( ! F_52 ( V_413 ) ) {
V_412 -> V_149 = V_413 ;
F_265 ( V_413 ) ;
}
}
F_177 ( & V_5 -> V_36 ) ;
}
}
static void F_266 ( struct V_4 * V_5 , const struct V_155 * V_153 )
{
struct V_9 * V_10 ;
T_1 V_210 = V_189 ;
#ifdef F_159
if ( V_5 -> V_39 . V_227 &&
! F_34 ( V_5 -> V_7 ) -> V_18 . V_115 -> V_45 )
V_210 |= V_224 ;
#endif
V_10 = F_113 ( V_5 , V_153 , NULL , 64 , V_270 , V_210 ,
V_398 , V_398 ) ;
if ( ! F_52 ( V_10 ) ) {
F_227 ( & V_10 -> V_153 , V_10 -> V_178 , V_5 -> V_7 , 0 , 0 ) ;
F_156 ( V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_267 ( struct V_4 * V_5 , bool V_416 )
{
if ( V_5 -> V_417 == V_418 ) {
struct V_155 V_153 ;
F_233 ( & V_153 , F_194 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( F_195 ( V_153 . V_212 + 8 , V_5 -> V_7 ) == 0 )
F_266 ( V_5 , & V_153 ) ;
else if ( V_416 )
F_227 ( & V_153 , 64 , V_5 -> V_7 , 0 , 0 ) ;
}
}
static void F_268 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_299 ) &&
( V_7 -> type != V_300 ) &&
( V_7 -> type != V_301 ) &&
( V_7 -> type != V_302 ) &&
( V_7 -> type != V_305 ) &&
( V_7 -> type != V_306 ) &&
( V_7 -> type != V_63 ) &&
( V_7 -> type != V_304 ) ) {
return;
}
V_5 = F_234 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return;
F_267 ( V_5 , false ) ;
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
if ( V_7 -> V_56 & V_57 ) {
F_267 ( V_5 , false ) ;
return;
}
F_262 ( V_5 ) ;
if ( V_7 -> V_50 & V_327 )
F_232 ( V_7 ) ;
}
static void F_270 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( V_5 == NULL ) {
F_99 ( L_20 , V_47 ) ;
return;
}
F_267 ( V_5 , true ) ;
}
static int F_271 ( struct V_419 * V_420 , unsigned long V_90 ,
void * V_421 )
{
struct V_6 * V_7 = F_272 ( V_421 ) ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
int V_422 = 0 ;
int V_32 ;
switch ( V_90 ) {
case V_423 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_273 ( F_119 ( V_5 ) ) ;
}
break;
case V_183 :
case V_424 :
if ( V_7 -> V_50 & V_425 )
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
if ( ! F_244 ( V_5 ) ) {
V_5 -> V_68 |= V_69 ;
V_422 = 1 ;
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
V_422 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_54 )
case V_55 :
F_269 ( V_7 ) ;
break;
#endif
#if F_42 ( V_426 )
case V_303 :
F_270 ( V_7 ) ;
break;
#endif
case V_427 :
F_264 ( V_7 ) ;
break;
default:
F_268 ( V_7 ) ;
break;
}
if ( ! F_244 ( V_5 ) ) {
if ( V_422 )
F_274 ( V_5 ) ;
if ( V_5 -> V_39 . V_41 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_275 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
}
V_5 -> V_70 = V_13 ;
F_276 ( V_428 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_277 ( V_7 , 1 ) ;
}
break;
case V_429 :
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
case V_430 :
F_277 ( V_7 , V_90 != V_200 ) ;
break;
case V_431 :
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
case V_432 :
case V_433 :
F_279 ( V_7 , V_90 ) ;
break;
}
return V_434 ;
}
static void F_279 ( struct V_6 * V_7 , unsigned long V_90 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_90 == V_433 )
F_280 ( V_5 ) ;
else if ( V_90 == V_432 )
F_281 ( V_5 ) ;
}
static int F_277 ( struct V_6 * V_7 , int V_435 )
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
if ( V_435 ) {
V_5 -> V_76 = 1 ;
F_284 ( V_7 -> V_71 , NULL ) ;
F_278 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_436 ; V_16 ++ ) {
struct V_124 * V_120 = & V_180 [ V_16 ] ;
F_141 ( & V_173 ) ;
V_437:
F_80 (ifa, h, addr_lst) {
if ( V_134 -> V_5 == V_5 ) {
F_143 ( & V_134 -> V_146 ) ;
F_9 ( V_134 ) ;
goto V_437;
}
}
F_142 ( & V_173 ) ;
}
F_144 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_435 )
V_5 -> V_68 &= ~ ( V_438 | V_439 | V_69 ) ;
if ( V_435 && F_7 ( & V_5 -> V_60 ) )
F_100 ( V_5 ) ;
while ( ! F_236 ( & V_5 -> V_59 ) ) {
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
while ( ! F_236 ( & V_5 -> V_37 ) ) {
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
if ( V_435 ) {
F_287 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_288 ( V_5 ) ;
}
V_5 -> V_70 = V_13 ;
if ( V_435 ) {
F_3 ( V_5 ) ;
F_39 ( & V_44 , V_5 -> V_43 ) ;
F_283 ( & V_44 , V_7 ) ;
F_100 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_308 )
{
struct V_4 * V_5 = (struct V_4 * ) V_308 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_155 V_440 ;
F_126 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 || ! ( V_5 -> V_68 & V_69 ) )
goto V_175;
if ( ! F_289 ( V_5 ) )
goto V_175;
if ( V_5 -> V_68 & V_439 )
goto V_175;
if ( V_5 -> V_441 ++ < V_5 -> V_39 . V_58 ) {
F_128 ( & V_5 -> V_36 ) ;
if ( ! F_180 ( V_7 , & V_440 , V_137 ) )
F_290 ( V_7 , & V_440 ,
& V_75 ) ;
else
goto V_442;
F_126 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_441 ==
V_5 -> V_39 . V_58 ) ?
V_5 -> V_39 . V_443 :
V_5 -> V_39 . V_444 ) ;
} else {
F_99 ( L_23 , V_5 -> V_7 -> V_48 ) ;
}
V_175:
F_128 ( & V_5 -> V_36 ) ;
V_442:
F_100 ( V_5 ) ;
}
static void F_291 ( struct V_9 * V_10 )
{
unsigned long V_445 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_50 & V_224 )
V_445 = 0 ;
else
V_445 = F_292 () % ( V_5 -> V_39 . V_443 ? : 1 ) ;
V_10 -> V_446 = V_5 -> V_39 . V_221 ;
F_16 ( V_10 , V_445 ) ;
}
static void F_293 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_196 ( V_7 , & V_10 -> V_153 ) ;
F_294 ( ( V_384 T_1 ) V_10 -> V_153 . V_282 [ 3 ] ) ;
F_172 ( & V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 == V_148 )
goto V_175;
if ( V_7 -> V_50 & ( V_51 | V_52 ) ||
V_5 -> V_39 . V_53 < 1 ||
! ( V_10 -> V_50 & V_137 ) ||
V_10 -> V_50 & V_447 ) {
V_10 -> V_50 &= ~ ( V_137 | V_224 | V_278 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
F_295 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_68 & V_69 ) ) {
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
F_18 ( V_10 ) ;
F_190 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_50 & V_224 ) {
F_265 ( V_10 -> V_149 ) ;
if ( F_158 ( V_5 ) ) {
F_149 ( V_399 , V_10 ) ;
}
}
F_291 ( V_10 ) ;
V_175:
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
bool V_448 = false ;
F_141 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_147 != V_148 ) {
V_10 -> V_147 = V_449 ;
V_448 = true ;
}
F_142 ( & V_10 -> V_176 ) ;
if ( V_448 )
F_16 ( V_10 , 0 ) ;
}
static void V_177 ( struct V_450 * V_451 )
{
struct V_9 * V_10 = F_296 ( F_297 ( V_451 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_155 V_452 ;
enum {
V_453 ,
V_454 ,
V_455 ,
} V_187 = V_453 ;
F_249 () ;
F_141 ( & V_10 -> V_176 ) ;
if ( V_10 -> V_147 == V_449 ) {
V_187 = V_454 ;
V_10 -> V_147 = V_280 ;
} else if ( V_10 -> V_147 == V_283 ) {
V_187 = V_455 ;
V_10 -> V_147 = V_281 ;
}
F_142 ( & V_10 -> V_176 ) ;
if ( V_187 == V_454 ) {
F_293 ( V_10 ) ;
goto V_175;
} else if ( V_187 == V_455 ) {
F_190 ( V_10 , 1 ) ;
goto V_175;
}
if ( ! V_10 -> V_446 && F_191 ( V_10 ) )
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
if ( V_10 -> V_446 == 0 ) {
V_10 -> V_50 &= ~ ( V_137 | V_224 | V_278 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_295 ( V_10 ) ;
goto V_175;
}
V_10 -> V_446 -- ;
F_16 ( V_10 ,
F_154 ( V_10 -> V_5 -> V_43 , V_222 ) ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_197 ( & V_10 -> V_153 , & V_452 ) ;
F_298 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_153 , & V_452 , & V_67 ) ;
V_175:
F_146 ( V_10 ) ;
F_94 () ;
}
static bool F_299 ( struct V_9 * V_10 )
{
struct V_9 * V_456 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_179 (ifpiter, &idev->addr_list, if_list) {
if ( V_456 -> V_159 > V_270 )
break;
if ( V_10 != V_456 && V_456 -> V_159 == V_270 &&
( V_456 -> V_50 & ( V_189 | V_137 |
V_224 | V_278 ) ) ==
V_189 )
return false ;
}
return true ;
}
static void F_295 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_155 V_440 ;
bool V_457 , V_458 ;
F_9 ( V_10 ) ;
F_149 ( V_399 , V_10 ) ;
F_172 ( & V_10 -> V_5 -> V_36 ) ;
V_458 = V_10 -> V_159 == V_270 && F_299 ( V_10 ) ;
V_457 = V_458 &&
F_289 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_58 > 0 &&
( V_7 -> V_50 & V_52 ) == 0 ;
F_177 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_458 )
F_300 ( V_10 -> V_5 ) ;
if ( V_457 ) {
if ( F_180 ( V_7 , & V_440 , V_137 ) )
return;
F_290 ( V_7 , & V_440 , & V_75 ) ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_441 = 1 ;
V_10 -> V_5 -> V_68 |= V_438 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_444 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_274 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_50 & V_137 &&
V_10 -> V_147 == V_280 )
F_291 ( V_10 ) ;
F_125 ( & V_10 -> V_36 ) ;
}
F_177 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_301 ( struct V_459 * V_89 , T_8 V_460 )
{
struct V_9 * V_134 = NULL ;
struct V_461 * V_147 = V_89 -> V_462 ;
struct V_101 * V_101 = F_302 ( V_89 ) ;
int V_142 = 0 ;
if ( V_460 == 0 ) {
V_147 -> V_463 = 0 ;
V_147 -> V_464 = 0 ;
}
for (; V_147 -> V_463 < V_436 ; ++ V_147 -> V_463 ) {
F_189 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_184 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( V_142 < V_147 -> V_464 ) {
V_142 ++ ;
continue;
}
V_147 -> V_464 ++ ;
return V_134 ;
}
V_147 -> V_464 = 0 ;
V_142 = 0 ;
}
return NULL ;
}
static struct V_9 * F_303 ( struct V_459 * V_89 ,
struct V_9 * V_134 )
{
struct V_461 * V_147 = V_89 -> V_462 ;
struct V_101 * V_101 = F_302 ( V_89 ) ;
F_304 (ifa, addr_lst) {
if ( ! F_184 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_464 ++ ;
return V_134 ;
}
while ( ++ V_147 -> V_463 < V_436 ) {
V_147 -> V_464 = 0 ;
F_189 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_184 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_464 ++ ;
return V_134 ;
}
}
return NULL ;
}
static void * F_305 ( struct V_459 * V_89 , T_8 * V_460 )
__acquires( T_9 )
{
F_115 () ;
return F_301 ( V_89 , * V_460 ) ;
}
static void * F_306 ( struct V_459 * V_89 , void * V_465 , T_8 * V_460 )
{
struct V_9 * V_134 ;
V_134 = F_303 ( V_89 , V_465 ) ;
++ * V_460 ;
return V_134 ;
}
static void F_307 ( struct V_459 * V_89 , void * V_465 )
__releases( T_9 )
{
F_129 () ;
}
static int F_308 ( struct V_459 * V_89 , void * V_465 )
{
struct V_9 * V_10 = (struct V_9 * ) V_465 ;
F_309 ( V_89 , L_24 ,
& V_10 -> V_153 ,
V_10 -> V_5 -> V_7 -> V_85 ,
V_10 -> V_178 ,
V_10 -> V_159 ,
( T_3 ) V_10 -> V_50 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
return 0 ;
}
static int F_310 ( struct V_466 * V_466 , struct V_467 * V_467 )
{
return F_311 ( V_466 , V_467 , & V_468 ,
sizeof( struct V_461 ) ) ;
}
static int T_10 F_312 ( struct V_101 * V_101 )
{
if ( ! F_313 ( L_25 , V_469 , V_101 -> V_470 , & V_471 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_314 ( struct V_101 * V_101 )
{
F_315 ( L_25 , V_101 -> V_470 ) ;
}
int T_12 F_316 ( void )
{
return F_317 ( & V_472 ) ;
}
void F_318 ( void )
{
F_319 ( & V_472 ) ;
}
int F_320 ( struct V_101 * V_101 , const struct V_155 * V_153 )
{
int V_209 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_189 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_184 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
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
static void F_256 ( void )
{
unsigned long V_211 , V_473 , V_474 , V_475 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_115 () ;
V_211 = V_13 ;
V_473 = F_321 ( V_211 + V_476 ) ;
F_10 ( & V_477 ) ;
for ( V_16 = 0 ; V_16 < V_436 ; V_16 ++ ) {
V_437:
F_189 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_206 ;
if ( ( V_10 -> V_50 & V_189 ) &&
( V_10 -> V_161 == V_398 ) )
continue;
F_116 ( & V_10 -> V_36 ) ;
V_206 = ( V_211 - V_10 -> V_70 + V_223 ) / V_3 ;
if ( V_10 -> V_160 != V_398 &&
V_206 >= V_10 -> V_160 ) {
F_125 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_140 ( V_10 ) ;
goto V_437;
} else if ( V_10 -> V_161 == V_398 ) {
F_125 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_206 >= V_10 -> V_161 ) {
int V_478 = 0 ;
if ( ! ( V_10 -> V_50 & V_243 ) ) {
V_478 = 1 ;
V_10 -> V_50 |= V_243 ;
}
if ( ( V_10 -> V_160 != V_398 ) &&
( F_135 ( V_10 -> V_70 + V_10 -> V_160 * V_3 , V_473 ) ) )
V_473 = V_10 -> V_70 + V_10 -> V_160 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
if ( V_478 ) {
F_18 ( V_10 ) ;
F_149 ( 0 , V_10 ) ;
F_146 ( V_10 ) ;
goto V_437;
}
} else if ( ( V_10 -> V_50 & V_181 ) &&
! ( V_10 -> V_50 & V_137 ) ) {
unsigned long V_207 = V_10 -> V_5 -> V_39 . V_215 *
V_10 -> V_5 -> V_39 . V_221 *
F_154 ( V_10 -> V_5 -> V_43 , V_222 ) / V_3 ;
if ( V_206 >= V_10 -> V_161 - V_207 ) {
struct V_9 * V_198 = V_10 -> V_198 ;
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_473 ) )
V_473 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
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
goto V_437;
}
} else if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 - V_207 * V_3 , V_473 ) )
V_473 = V_10 -> V_70 + V_10 -> V_161 * V_3 - V_207 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
} else {
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_473 ) )
V_473 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
}
}
}
V_474 = F_321 ( V_473 ) ;
V_475 = V_473 ;
if ( F_135 ( V_474 , V_473 + V_479 ) )
V_475 = V_474 ;
if ( F_135 ( V_475 , V_13 + V_480 ) )
V_475 = V_13 + V_480 ;
F_38 ( V_481 L_26 ,
V_211 , V_473 , V_474 , V_475 ) ;
F_19 ( V_15 , & V_477 , V_475 - V_211 ) ;
F_129 () ;
}
static void F_322 ( struct V_450 * V_451 )
{
F_249 () ;
F_256 () ;
F_94 () ;
}
static void F_246 ( void )
{
F_19 ( V_15 , & V_477 , 0 ) ;
}
static struct V_155 * F_323 ( struct V_109 * V_153 , struct V_109 * V_482 ,
struct V_155 * * V_390 )
{
struct V_155 * V_309 = NULL ;
* V_390 = NULL ;
if ( V_153 )
V_309 = F_324 ( V_153 ) ;
if ( V_482 ) {
if ( V_309 && F_325 ( V_482 , V_309 , sizeof( * V_309 ) ) )
* V_390 = V_309 ;
V_309 = F_324 ( V_482 ) ;
}
return V_309 ;
}
static int
F_326 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_483 * V_484 ;
struct V_109 * V_110 [ V_485 + 1 ] ;
struct V_155 * V_309 , * V_390 ;
T_1 V_391 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_484 ) , V_110 , V_485 , V_486 ) ;
if ( V_32 < 0 )
return V_32 ;
V_484 = F_60 ( V_92 ) ;
V_309 = F_323 ( V_110 [ V_487 ] , V_110 [ V_488 ] , & V_390 ) ;
if ( V_309 == NULL )
return - V_35 ;
V_391 = V_110 [ V_489 ] ? F_327 ( V_110 [ V_489 ] ) : V_484 -> V_391 ;
V_391 &= V_358 ;
return F_257 ( V_101 , V_484 -> V_490 , V_391 , V_309 ,
V_484 -> V_491 ) ;
}
static int F_328 ( struct V_9 * V_10 , T_1 V_391 ,
T_1 V_161 , T_1 V_160 )
{
T_1 V_50 ;
T_5 V_185 ;
unsigned long V_392 ;
bool V_492 ;
bool V_493 ;
F_29 () ;
if ( ! V_160 || ( V_161 > V_160 ) )
return - V_35 ;
if ( V_391 & V_358 &&
( V_10 -> V_50 & V_181 || V_10 -> V_178 != 64 ) )
return - V_35 ;
V_392 = F_134 ( V_160 , V_3 ) ;
if ( F_241 ( V_392 ) ) {
V_185 = F_243 ( V_392 * V_3 ) ;
V_160 = V_392 ;
V_50 = V_197 ;
} else {
V_185 = 0 ;
V_50 = 0 ;
V_391 |= V_189 ;
}
V_392 = F_134 ( V_161 , V_3 ) ;
if ( F_241 ( V_392 ) ) {
if ( V_392 == 0 )
V_391 |= V_243 ;
V_161 = V_392 ;
}
F_141 ( & V_10 -> V_36 ) ;
V_492 = V_10 -> V_50 & V_358 ;
V_493 = V_10 -> V_50 & V_189 &&
! ( V_10 -> V_50 & V_190 ) ;
V_10 -> V_50 &= ~ ( V_243 | V_189 | V_447 |
V_248 | V_358 |
V_190 ) ;
V_10 -> V_50 |= V_391 ;
V_10 -> V_70 = V_13 ;
V_10 -> V_160 = V_160 ;
V_10 -> V_161 = V_161 ;
F_142 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_137 ) )
F_149 ( 0 , V_10 ) ;
if ( ! ( V_391 & V_190 ) ) {
F_227 ( & V_10 -> V_153 , V_10 -> V_178 , V_10 -> V_5 -> V_7 ,
V_185 , V_50 ) ;
} else if ( V_493 ) {
enum V_184 V_187 ;
unsigned long V_349 ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
V_187 = F_132 ( V_10 , & V_349 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_187 != V_191 ) {
F_136 ( V_10 , V_349 ,
V_187 == V_188 ) ;
}
}
if ( V_492 || V_10 -> V_50 & V_358 ) {
if ( V_492 && ! ( V_10 -> V_50 & V_358 ) )
V_160 = V_161 = 0 ;
F_235 ( V_10 -> V_5 , V_10 , V_160 , V_161 ,
! V_492 , V_13 ) ;
}
F_256 () ;
return 0 ;
}
static int
F_329 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_483 * V_484 ;
struct V_109 * V_110 [ V_485 + 1 ] ;
struct V_155 * V_309 , * V_390 ;
struct V_9 * V_134 ;
struct V_6 * V_7 ;
T_1 V_160 = V_398 , V_494 = V_398 ;
T_1 V_391 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_484 ) , V_110 , V_485 , V_486 ) ;
if ( V_32 < 0 )
return V_32 ;
V_484 = F_60 ( V_92 ) ;
V_309 = F_323 ( V_110 [ V_487 ] , V_110 [ V_488 ] , & V_390 ) ;
if ( V_309 == NULL )
return - V_35 ;
if ( V_110 [ V_495 ] ) {
struct V_496 * V_497 ;
V_497 = F_324 ( V_110 [ V_495 ] ) ;
V_160 = V_497 -> V_498 ;
V_494 = V_497 -> V_499 ;
} else {
V_494 = V_398 ;
V_160 = V_398 ;
}
V_7 = F_74 ( V_101 , V_484 -> V_490 ) ;
if ( V_7 == NULL )
return - V_169 ;
V_391 = V_110 [ V_489 ] ? F_327 ( V_110 [ V_489 ] ) : V_484 -> V_391 ;
V_391 &= V_447 | V_248 | V_358 |
V_190 ;
V_134 = F_188 ( V_101 , V_309 , V_7 , 1 ) ;
if ( V_134 == NULL ) {
return F_255 ( V_101 , V_484 -> V_490 , V_309 , V_390 ,
V_484 -> V_491 , V_391 ,
V_494 , V_160 ) ;
}
if ( V_92 -> V_500 & V_501 ||
! ( V_92 -> V_500 & V_502 ) )
V_32 = - V_174 ;
else
V_32 = F_328 ( V_134 , V_391 , V_494 , V_160 ) ;
F_146 ( V_134 ) ;
return V_32 ;
}
static void F_330 ( struct V_91 * V_92 , T_3 V_503 , T_1 V_50 ,
T_3 V_159 , int V_85 )
{
struct V_483 * V_484 ;
V_484 = F_60 ( V_92 ) ;
V_484 -> V_504 = V_96 ;
V_484 -> V_491 = V_503 ;
V_484 -> V_391 = V_50 ;
V_484 -> V_408 = V_159 ;
V_484 -> V_490 = V_85 ;
}
static int F_331 ( struct V_83 * V_84 , unsigned long V_1 ,
unsigned long V_70 , T_1 V_505 , T_1 V_347 )
{
struct V_496 V_497 ;
V_497 . V_1 = F_1 ( V_1 ) ;
V_497 . V_70 = F_1 ( V_70 ) ;
V_497 . V_499 = V_505 ;
V_497 . V_498 = V_347 ;
return F_332 ( V_84 , V_495 , sizeof( V_497 ) , & V_497 ) ;
}
static inline int F_333 ( int V_408 )
{
if ( V_408 & V_274 )
return V_410 ;
else if ( V_408 & V_270 )
return V_409 ;
else if ( V_408 & V_506 )
return V_507 ;
else
return V_508 ;
}
static inline int F_334 ( void )
{
return F_55 ( sizeof( struct V_483 ) )
+ F_56 ( 16 )
+ F_56 ( 16 )
+ F_56 ( sizeof( struct V_496 ) )
+ F_56 ( 4 ) ;
}
static int F_335 ( struct V_83 * V_84 , struct V_9 * V_134 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_1 V_505 , V_347 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_483 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_330 ( V_92 , V_134 -> V_178 , V_134 -> V_50 , F_333 ( V_134 -> V_159 ) ,
V_134 -> V_5 -> V_7 -> V_85 ) ;
if ( ! ( ( V_134 -> V_50 & V_189 ) &&
( V_134 -> V_161 == V_398 ) ) ) {
V_505 = V_134 -> V_161 ;
V_347 = V_134 -> V_160 ;
if ( V_505 != V_398 ) {
long V_509 = ( V_13 - V_134 -> V_70 ) / V_3 ;
if ( V_505 > V_509 )
V_505 -= V_509 ;
else
V_505 = 0 ;
if ( V_347 != V_398 ) {
if ( V_347 > V_509 )
V_347 -= V_509 ;
else
V_347 = 0 ;
}
}
} else {
V_505 = V_398 ;
V_347 = V_398 ;
}
if ( ! F_201 ( & V_134 -> V_157 ) ) {
if ( F_332 ( V_84 , V_488 , 16 , & V_134 -> V_153 ) < 0 ||
F_332 ( V_84 , V_487 , 16 , & V_134 -> V_157 ) < 0 )
goto error;
} else
if ( F_332 ( V_84 , V_487 , 16 , & V_134 -> V_153 ) < 0 )
goto error;
if ( F_331 ( V_84 , V_134 -> V_1 , V_134 -> V_70 , V_505 , V_347 ) < 0 )
goto error;
if ( F_336 ( V_84 , V_489 , V_134 -> V_50 ) < 0 )
goto error;
F_62 ( V_84 , V_92 ) ;
return 0 ;
error:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_337 ( struct V_83 * V_84 , struct V_510 * V_511 ,
T_1 V_88 , T_1 V_89 , int V_90 , T_13 V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_508 ;
int V_85 = V_511 -> V_5 -> V_7 -> V_85 ;
if ( F_155 ( & V_511 -> V_512 ) & V_506 )
V_159 = V_507 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_483 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_330 ( V_92 , 128 , V_189 , V_159 , V_85 ) ;
if ( F_332 ( V_84 , V_513 , 16 , & V_511 -> V_512 ) < 0 ||
F_331 ( V_84 , V_511 -> V_514 , V_511 -> V_515 ,
V_398 , V_398 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
F_62 ( V_84 , V_92 ) ;
return 0 ;
}
static int F_338 ( struct V_83 * V_84 , struct V_516 * V_517 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_508 ;
int V_85 = V_517 -> V_518 -> V_7 -> V_85 ;
if ( F_155 ( & V_517 -> V_519 ) & V_506 )
V_159 = V_507 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_483 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
F_330 ( V_92 , 128 , V_189 , V_159 , V_85 ) ;
if ( F_332 ( V_84 , V_520 , 16 , & V_517 -> V_519 ) < 0 ||
F_331 ( V_84 , V_517 -> V_521 , V_517 -> V_522 ,
V_398 , V_398 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
F_62 ( V_84 , V_92 ) ;
return 0 ;
}
static int F_339 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_118 * V_119 , enum V_523 type ,
int V_524 , int * V_525 )
{
struct V_510 * V_511 ;
struct V_516 * V_517 ;
int V_32 = 1 ;
int V_526 = * V_525 ;
F_172 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_527 : {
struct V_9 * V_134 ;
F_86 (ifa, &idev->addr_list, if_list) {
if ( ++ V_526 < V_524 )
continue;
V_32 = F_335 ( V_84 , V_134 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_399 ,
V_131 ) ;
if ( V_32 < 0 )
break;
F_82 ( V_119 , F_83 ( V_84 ) ) ;
}
break;
}
case V_528 :
for ( V_511 = V_5 -> V_529 ; V_511 ;
V_511 = V_511 -> V_473 , V_526 ++ ) {
if ( V_526 < V_524 )
continue;
V_32 = F_337 ( V_84 , V_511 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_530 ,
V_131 ) ;
if ( V_32 < 0 )
break;
}
break;
case V_531 :
for ( V_517 = V_5 -> V_532 ; V_517 ;
V_517 = V_517 -> V_533 , V_526 ++ ) {
if ( V_526 < V_524 )
continue;
V_32 = F_338 ( V_84 , V_517 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_534 ,
V_131 ) ;
if ( V_32 < 0 )
break;
}
break;
default:
break;
}
F_177 ( & V_5 -> V_36 ) ;
* V_525 = V_526 ;
return V_32 ;
}
static int F_340 ( struct V_83 * V_84 , struct V_118 * V_119 ,
enum V_523 type )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
int V_120 , V_121 ;
int V_122 , V_526 ;
int V_123 , V_524 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_124 * V_125 ;
V_121 = V_119 -> args [ 0 ] ;
V_123 = V_122 = V_119 -> args [ 1 ] ;
V_524 = V_526 = V_119 -> args [ 2 ] ;
F_78 () ;
V_119 -> V_89 = F_79 ( & V_101 -> V_18 . V_128 ) ^ V_101 -> V_129 ;
for ( V_120 = V_121 ; V_120 < V_126 ; V_120 ++ , V_123 = 0 ) {
V_122 = 0 ;
V_125 = & V_101 -> V_127 [ V_120 ] ;
F_80 (dev, head, index_hlist) {
if ( V_122 < V_123 )
goto V_130;
if ( V_120 > V_121 || V_122 > V_123 )
V_524 = 0 ;
V_526 = 0 ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_130;
if ( F_339 ( V_5 , V_84 , V_119 , type ,
V_524 , & V_526 ) < 0 )
goto V_132;
V_130:
V_122 ++ ;
}
}
V_132:
F_81 () ;
V_119 -> args [ 0 ] = V_120 ;
V_119 -> args [ 1 ] = V_122 ;
V_119 -> args [ 2 ] = V_526 ;
return V_84 -> V_133 ;
}
static int F_341 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_523 type = V_527 ;
return F_340 ( V_84 , V_119 , type ) ;
}
static int F_342 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_523 type = V_528 ;
return F_340 ( V_84 , V_119 , type ) ;
}
static int F_343 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_523 type = V_531 ;
return F_340 ( V_84 , V_119 , type ) ;
}
static int F_344 ( struct V_83 * V_107 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_107 -> V_108 ) ;
struct V_483 * V_484 ;
struct V_109 * V_110 [ V_485 + 1 ] ;
struct V_155 * V_153 = NULL , * V_535 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_134 ;
struct V_83 * V_84 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_484 ) , V_110 , V_485 , V_486 ) ;
if ( V_32 < 0 )
goto V_104;
V_153 = F_323 ( V_110 [ V_487 ] , V_110 [ V_488 ] , & V_535 ) ;
if ( V_153 == NULL ) {
V_32 = - V_35 ;
goto V_104;
}
V_484 = F_60 ( V_92 ) ;
if ( V_484 -> V_490 )
V_7 = F_74 ( V_101 , V_484 -> V_490 ) ;
V_134 = F_188 ( V_101 , V_153 , V_7 , 1 ) ;
if ( ! V_134 ) {
V_32 = - V_168 ;
goto V_104;
}
V_84 = F_65 ( F_334 () , V_25 ) ;
if ( ! V_84 ) {
V_32 = - V_102 ;
goto V_536;
}
V_32 = F_335 ( V_84 , V_134 , F_75 ( V_107 ) . V_88 ,
V_92 -> V_117 , V_399 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_536;
}
V_32 = F_76 ( V_84 , V_101 , F_75 ( V_107 ) . V_88 ) ;
V_536:
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
F_68 ( V_84 , V_101 , 0 , V_537 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_537 , V_32 ) ;
}
static inline void F_346 ( struct V_86 * V_39 ,
T_2 * V_538 , int V_539 )
{
F_347 ( V_539 < ( V_540 * 4 ) ) ;
memset ( V_538 , 0 , V_539 ) ;
V_538 [ V_541 ] = V_39 -> V_45 ;
V_538 [ V_542 ] = V_39 -> V_543 ;
V_538 [ V_544 ] = V_39 -> V_41 ;
V_538 [ V_545 ] = V_39 -> V_546 ;
V_538 [ V_547 ] = V_39 -> V_548 ;
V_538 [ V_549 ] = V_39 -> V_353 ;
V_538 [ V_550 ] = V_39 -> V_221 ;
V_538 [ V_551 ] = V_39 -> V_58 ;
V_538 [ V_552 ] =
F_348 ( V_39 -> V_444 ) ;
V_538 [ V_553 ] =
F_348 ( V_39 -> V_443 ) ;
V_538 [ V_554 ] = V_39 -> V_555 ;
V_538 [ V_556 ] =
F_348 ( V_39 -> V_557 ) ;
V_538 [ V_558 ] =
F_348 ( V_39 -> V_559 ) ;
V_538 [ V_560 ] = V_39 -> V_65 ;
V_538 [ V_561 ] = V_39 -> V_218 ;
V_538 [ V_562 ] = V_39 -> V_219 ;
V_538 [ V_563 ] = V_39 -> V_215 ;
V_538 [ V_564 ] = V_39 -> V_220 ;
V_538 [ V_565 ] = V_39 -> V_356 ;
V_538 [ V_566 ] = V_39 -> V_567 ;
V_538 [ V_568 ] = V_39 -> V_569 ;
#ifdef F_349
V_538 [ V_570 ] = V_39 -> V_571 ;
V_538 [ V_572 ] =
F_348 ( V_39 -> V_573 ) ;
#ifdef F_350
V_538 [ V_574 ] = V_39 -> V_575 ;
#endif
#endif
V_538 [ V_576 ] = V_39 -> V_100 ;
V_538 [ V_577 ] = V_39 -> V_578 ;
#ifdef F_159
V_538 [ V_579 ] = V_39 -> V_227 ;
V_538 [ V_580 ] = V_39 -> V_228 ;
#endif
#ifdef F_57
V_538 [ V_581 ] = V_39 -> V_99 ;
#endif
V_538 [ V_582 ] = V_39 -> V_171 ;
V_538 [ V_583 ] = V_39 -> V_53 ;
V_538 [ V_584 ] = V_39 -> V_585 ;
V_538 [ V_586 ] = V_39 -> V_587 ;
V_538 [ V_588 ] = V_39 -> V_589 ;
V_538 [ V_590 ] = V_39 -> V_591 ;
V_538 [ V_592 ] = V_39 -> V_593 ;
}
static inline T_14 F_351 ( void )
{
return F_56 ( 4 )
+ F_56 ( sizeof( struct V_594 ) )
+ F_56 ( V_540 * 4 )
+ F_56 ( V_595 * 8 )
+ F_56 ( V_596 * 8 )
+ F_56 ( sizeof( struct V_155 ) ) ;
}
static inline T_14 F_352 ( void )
{
return F_55 ( sizeof( struct V_597 ) )
+ F_56 ( V_598 )
+ F_56 ( V_599 )
+ F_56 ( 4 )
+ F_56 ( 4 )
+ F_56 ( F_351 () ) ;
}
static inline void F_353 ( T_15 * V_17 , T_16 * V_600 ,
int V_601 , int V_539 )
{
int V_16 ;
int V_602 = V_539 - sizeof( T_15 ) * V_601 ;
F_347 ( V_602 < 0 ) ;
F_354 ( V_601 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_601 ; V_16 ++ )
F_354 ( F_355 ( & V_600 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_601 ] , 0 , V_602 ) ;
}
static inline void F_356 ( T_15 * V_17 , void T_17 * V_600 ,
int V_601 , int V_539 , T_14 V_603 )
{
int V_16 ;
int V_602 = V_539 - sizeof( T_15 ) * V_601 ;
F_347 ( V_602 < 0 ) ;
F_354 ( V_601 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_601 ; V_16 ++ )
F_354 ( F_357 ( V_600 , V_16 , V_603 ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_601 ] , 0 , V_602 ) ;
}
static void F_358 ( T_15 * V_17 , struct V_4 * V_5 , int V_604 ,
int V_539 )
{
switch ( V_604 ) {
case V_605 :
F_356 ( V_17 , V_5 -> V_17 . V_18 ,
V_595 , V_539 , F_359 ( struct V_19 , V_22 ) ) ;
break;
case V_606 :
F_353 ( V_17 , V_5 -> V_17 . V_23 -> V_607 , V_596 , V_539 ) ;
break;
}
}
static int F_360 ( struct V_83 * V_84 , struct V_4 * V_5 )
{
struct V_109 * V_608 ;
struct V_594 V_497 ;
if ( F_336 ( V_84 , V_609 , V_5 -> V_68 ) )
goto V_98;
V_497 . V_610 = V_611 ;
V_497 . V_70 = F_1 ( V_5 -> V_70 ) ;
V_497 . V_612 = F_348 ( V_5 -> V_43 -> V_612 ) ;
V_497 . V_613 = F_348 ( F_154 ( V_5 -> V_43 , V_222 ) ) ;
if ( F_332 ( V_84 , V_614 , sizeof( V_497 ) , & V_497 ) )
goto V_98;
V_608 = F_361 ( V_84 , V_615 , V_540 * sizeof( V_616 ) ) ;
if ( V_608 == NULL )
goto V_98;
F_346 ( & V_5 -> V_39 , F_324 ( V_608 ) , F_362 ( V_608 ) ) ;
V_608 = F_361 ( V_84 , V_605 , V_595 * sizeof( T_15 ) ) ;
if ( V_608 == NULL )
goto V_98;
F_358 ( F_324 ( V_608 ) , V_5 , V_605 , F_362 ( V_608 ) ) ;
V_608 = F_361 ( V_84 , V_606 , V_596 * sizeof( T_15 ) ) ;
if ( V_608 == NULL )
goto V_98;
F_358 ( F_324 ( V_608 ) , V_5 , V_606 , F_362 ( V_608 ) ) ;
V_608 = F_361 ( V_84 , V_617 , sizeof( struct V_155 ) ) ;
if ( V_608 == NULL )
goto V_98;
if ( F_363 ( V_84 , V_618 , V_5 -> V_417 ) )
goto V_98;
F_172 ( & V_5 -> V_36 ) ;
memcpy ( F_324 ( V_608 ) , V_5 -> V_66 . V_212 , F_362 ( V_608 ) ) ;
F_177 ( & V_5 -> V_36 ) ;
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
return - V_619 ;
if ( F_360 ( V_84 , V_5 ) < 0 )
return - V_94 ;
return 0 ;
}
static int F_366 ( struct V_4 * V_5 , struct V_155 * V_66 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_620 = false ;
struct V_155 V_621 ;
F_29 () ;
if ( V_66 == NULL )
return - V_35 ;
if ( F_201 ( V_66 ) )
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
! F_180 ( V_7 , & V_621 , V_137 |
V_224 ) ) {
F_290 ( V_7 , & V_621 , & V_75 ) ;
V_620 = true ;
}
F_144 ( & V_5 -> V_36 ) ;
if ( V_620 ) {
V_5 -> V_68 |= V_438 ;
V_5 -> V_441 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_444 ) ;
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
F_276 ( V_428 , V_5 ) ;
F_256 () ;
return 0 ;
}
static int F_368 ( const struct V_6 * V_7 ,
const struct V_109 * V_608 )
{
struct V_109 * V_110 [ V_622 + 1 ] ;
if ( V_7 && ! F_51 ( V_7 ) )
return - V_623 ;
return F_369 ( V_110 , V_622 , V_608 , V_624 ) ;
}
static int F_370 ( struct V_6 * V_7 , const struct V_109 * V_608 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
struct V_109 * V_110 [ V_622 + 1 ] ;
if ( ! V_5 )
return - V_623 ;
if ( F_369 ( V_110 , V_622 , V_608 , NULL ) < 0 )
F_371 () ;
if ( V_110 [ V_617 ] ) {
V_32 = F_366 ( V_5 , F_324 ( V_110 [ V_617 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_110 [ V_618 ] ) {
T_3 V_625 = F_372 ( V_110 [ V_618 ] ) ;
if ( V_625 != V_418 &&
V_625 != V_626 )
return - V_35 ;
V_5 -> V_417 = V_625 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_373 ( struct V_83 * V_84 , struct V_4 * V_5 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_597 * V_627 ;
struct V_91 * V_92 ;
void * V_628 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_627 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_627 = F_60 ( V_92 ) ;
V_627 -> V_629 = V_96 ;
V_627 -> V_630 = 0 ;
V_627 -> V_631 = V_7 -> type ;
V_627 -> V_632 = V_7 -> V_85 ;
V_627 -> V_633 = F_374 ( V_7 ) ;
V_627 -> V_634 = 0 ;
if ( F_375 ( V_84 , V_635 , V_7 -> V_48 ) ||
( V_7 -> V_286 &&
F_332 ( V_84 , V_636 , V_7 -> V_286 , V_7 -> V_288 ) ) ||
F_336 ( V_84 , V_637 , V_7 -> V_33 ) ||
( V_7 -> V_85 != V_7 -> V_638 &&
F_336 ( V_84 , V_639 , V_7 -> V_638 ) ) )
goto V_98;
V_628 = F_376 ( V_84 , V_640 ) ;
if ( V_628 == NULL )
goto V_98;
if ( F_360 ( V_84 , V_5 ) < 0 )
goto V_98;
F_377 ( V_84 , V_628 ) ;
F_62 ( V_84 , V_92 ) ;
return 0 ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_378 ( struct V_83 * V_84 , struct V_118 * V_119 )
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
if ( F_373 ( V_84 , V_5 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_428 , V_131 ) < 0 )
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
V_32 = F_373 ( V_84 , V_5 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_641 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_641 , V_32 ) ;
}
static inline T_14 F_379 ( void )
{
return F_55 ( sizeof( struct V_642 ) )
+ F_56 ( sizeof( struct V_155 ) )
+ F_56 ( sizeof( struct V_643 ) ) ;
}
static int F_380 ( struct V_83 * V_84 , struct V_4 * V_5 ,
struct V_343 * V_344 , T_1 V_88 , T_1 V_89 ,
int V_90 , unsigned int V_50 )
{
struct V_642 * V_644 ;
struct V_91 * V_92 ;
struct V_643 V_497 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_644 ) , V_50 ) ;
if ( V_92 == NULL )
return - V_94 ;
V_644 = F_60 ( V_92 ) ;
V_644 -> V_645 = V_96 ;
V_644 -> V_646 = 0 ;
V_644 -> V_647 = 0 ;
V_644 -> V_648 = V_5 -> V_7 -> V_85 ;
V_644 -> V_178 = V_344 -> V_178 ;
V_644 -> V_649 = V_344 -> type ;
V_644 -> V_650 = 0 ;
V_644 -> V_651 = 0 ;
if ( V_344 -> V_275 )
V_644 -> V_651 |= V_652 ;
if ( V_344 -> V_353 )
V_644 -> V_651 |= V_653 ;
if ( F_332 ( V_84 , V_654 , sizeof( V_344 -> V_345 ) , & V_344 -> V_345 ) )
goto V_98;
V_497 . V_655 = F_238 ( V_344 -> V_348 ) ;
V_497 . V_656 = F_238 ( V_344 -> V_347 ) ;
if ( F_332 ( V_84 , V_657 , sizeof( V_497 ) , & V_497 ) )
goto V_98;
F_62 ( V_84 , V_92 ) ;
return 0 ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static void F_247 ( int V_90 , struct V_4 * V_5 ,
struct V_343 * V_344 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_379 () , V_103 ) ;
if ( V_84 == NULL )
goto V_104;
V_32 = F_380 ( V_84 , V_5 , V_344 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_658 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_658 , V_32 ) ;
}
static void F_286 ( int V_90 , struct V_9 * V_10 )
{
struct V_101 * V_101 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_90 )
F_29 () ;
F_345 ( V_90 ? : V_399 , V_10 ) ;
switch ( V_90 ) {
case V_399 :
if ( ! ( V_10 -> V_149 -> V_659 ) )
F_265 ( V_10 -> V_149 ) ;
if ( V_10 -> V_5 -> V_39 . V_45 )
F_87 ( V_10 ) ;
if ( ! F_201 ( & V_10 -> V_157 ) )
F_227 ( & V_10 -> V_157 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_199 :
if ( V_10 -> V_5 -> V_39 . V_45 )
F_88 ( V_10 ) ;
F_198 ( V_10 -> V_5 , & V_10 -> V_153 ) ;
if ( ! F_201 ( & V_10 -> V_157 ) ) {
struct V_162 * V_149 ;
V_149 = F_137 ( & V_10 -> V_157 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
if ( V_149 && F_138 ( V_149 ) )
F_381 ( & V_149 -> V_232 ) ;
}
F_231 ( & V_10 -> V_149 -> V_232 ) ;
if ( F_138 ( V_10 -> V_149 ) )
F_381 ( & V_10 -> V_149 -> V_232 ) ;
F_382 ( V_101 ) ;
break;
}
F_383 ( & V_101 -> V_18 . V_128 ) ;
}
static void F_149 ( int V_90 , struct V_9 * V_10 )
{
F_115 () ;
if ( F_130 ( V_10 -> V_5 -> V_76 == 0 ) )
F_286 ( V_90 , V_10 ) ;
F_129 () ;
}
static
int F_384 ( struct V_140 * V_660 , int V_661 ,
void T_6 * V_662 , T_14 * V_663 , T_8 * V_664 )
{
int * V_665 = V_660 -> V_308 ;
int V_666 = * V_665 ;
T_8 V_460 = * V_664 ;
struct V_140 V_667 ;
int V_209 ;
V_667 = * V_660 ;
V_667 . V_308 = & V_666 ;
V_209 = F_385 ( & V_667 , V_661 , V_662 , V_663 , V_664 ) ;
if ( V_661 )
V_209 = F_91 ( V_660 , V_665 , V_666 ) ;
if ( V_209 )
* V_664 = V_460 ;
return V_209 ;
}
static
int F_386 ( struct V_140 * V_660 , int V_661 ,
void T_6 * V_662 , T_14 * V_663 , T_8 * V_664 )
{
struct V_4 * V_5 = V_660 -> V_145 ;
int V_668 = V_34 ;
struct V_140 V_667 ;
V_667 = * V_660 ;
V_667 . V_145 = & V_668 ;
V_667 . V_144 = V_5 ? & V_5 -> V_7 -> V_33 : NULL ;
return F_387 ( & V_667 , V_661 , V_662 , V_663 , V_664 ) ;
}
static void F_388 ( struct V_4 * V_5 )
{
struct V_669 V_670 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_389 ( & V_670 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_171 )
F_271 ( NULL , V_200 , & V_670 ) ;
else
F_271 ( NULL , V_183 , & V_670 ) ;
}
static void F_390 ( struct V_101 * V_101 , T_2 V_138 )
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
F_388 ( V_5 ) ;
}
}
F_81 () ;
}
static int F_391 ( struct V_140 * V_141 , int * V_142 , int V_138 )
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
F_390 ( V_101 , V_138 ) ;
} else if ( ( ! V_138 ) ^ ( ! V_143 ) )
F_388 ( (struct V_4 * ) V_141 -> V_145 ) ;
F_94 () ;
return 0 ;
}
static
int F_392 ( struct V_140 * V_660 , int V_661 ,
void T_6 * V_662 , T_14 * V_663 , T_8 * V_664 )
{
int * V_665 = V_660 -> V_308 ;
int V_666 = * V_665 ;
T_8 V_460 = * V_664 ;
struct V_140 V_667 ;
int V_209 ;
V_667 = * V_660 ;
V_667 . V_308 = & V_666 ;
V_209 = F_385 ( & V_667 , V_661 , V_662 , V_663 , V_664 ) ;
if ( V_661 )
V_209 = F_391 ( V_660 , V_665 , V_666 ) ;
if ( V_209 )
* V_664 = V_460 ;
return V_209 ;
}
static
int F_393 ( struct V_140 * V_660 , int V_661 ,
void T_6 * V_662 , T_14 * V_663 , T_8 * V_664 )
{
int * V_665 = V_660 -> V_308 ;
int V_209 ;
int V_143 , V_671 ;
V_143 = * V_665 ;
V_209 = F_385 ( V_660 , V_661 , V_662 , V_663 , V_664 ) ;
V_671 = * V_665 ;
if ( V_661 && V_143 != V_671 ) {
struct V_101 * V_101 = V_660 -> V_144 ;
if ( ! F_92 () )
return F_93 () ;
if ( V_665 == & V_101 -> V_18 . V_40 -> V_100 )
F_64 ( V_101 , V_82 ,
V_116 ,
V_101 -> V_18 . V_40 ) ;
else if ( V_665 == & V_101 -> V_18 . V_115 -> V_100 )
F_64 ( V_101 , V_82 ,
V_114 ,
V_101 -> V_18 . V_115 ) ;
else {
struct V_4 * V_5 = V_660 -> V_145 ;
F_64 ( V_101 , V_82 ,
V_5 -> V_7 -> V_85 ,
& V_5 -> V_39 ) ;
}
F_94 () ;
}
return V_209 ;
}
static int F_394 ( struct V_101 * V_101 , char * V_672 ,
struct V_4 * V_5 , struct V_86 * V_142 )
{
int V_16 ;
struct V_673 * V_674 ;
char V_675 [ sizeof( L_27 ) + V_598 ] ;
V_674 = F_395 ( & V_676 , sizeof( * V_674 ) , V_25 ) ;
if ( V_674 == NULL )
goto V_175;
for ( V_16 = 0 ; V_674 -> V_677 [ V_16 ] . V_308 ; V_16 ++ ) {
V_674 -> V_677 [ V_16 ] . V_308 += ( char * ) V_142 - ( char * ) & V_86 ;
V_674 -> V_677 [ V_16 ] . V_145 = V_5 ;
V_674 -> V_677 [ V_16 ] . V_144 = V_101 ;
}
snprintf ( V_675 , sizeof( V_675 ) , L_28 , V_672 ) ;
V_674 -> V_678 = F_396 ( V_101 , V_675 , V_674 -> V_677 ) ;
if ( V_674 -> V_678 == NULL )
goto free;
V_142 -> V_42 = V_674 ;
return 0 ;
free:
F_26 ( V_674 ) ;
V_175:
return - V_102 ;
}
static void F_397 ( struct V_86 * V_142 )
{
struct V_673 * V_674 ;
if ( V_142 -> V_42 == NULL )
return;
V_674 = V_142 -> V_42 ;
V_142 -> V_42 = NULL ;
F_398 ( V_674 -> V_678 ) ;
F_26 ( V_674 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_399 ( V_5 -> V_7 -> V_48 ) )
return - V_35 ;
V_32 = F_400 ( V_5 -> V_7 , V_5 -> V_43 ,
& V_679 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_394 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_48 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_401 ( V_5 -> V_43 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_397 ( & V_5 -> V_39 ) ;
F_401 ( V_5 -> V_43 ) ;
}
static int T_10 F_402 ( struct V_101 * V_101 )
{
int V_32 = - V_30 ;
struct V_86 * V_680 , * V_681 ;
V_680 = F_395 ( & V_86 , sizeof( V_86 ) , V_25 ) ;
if ( V_680 == NULL )
goto V_682;
V_681 = F_395 ( & V_683 , sizeof( V_683 ) , V_25 ) ;
if ( V_681 == NULL )
goto V_684;
V_681 -> V_353 = V_685 . V_353 ;
V_681 -> V_171 = V_685 . V_171 ;
V_101 -> V_18 . V_115 = V_680 ;
V_101 -> V_18 . V_40 = V_681 ;
#ifdef F_403
V_32 = F_394 ( V_101 , L_29 , NULL , V_680 ) ;
if ( V_32 < 0 )
goto V_686;
V_32 = F_394 ( V_101 , L_30 , NULL , V_681 ) ;
if ( V_32 < 0 )
goto V_687;
#endif
return 0 ;
#ifdef F_403
V_687:
F_397 ( V_680 ) ;
V_686:
F_26 ( V_681 ) ;
#endif
V_684:
F_26 ( V_680 ) ;
V_682:
return V_32 ;
}
static void T_11 F_404 ( struct V_101 * V_101 )
{
#ifdef F_403
F_397 ( V_101 -> V_18 . V_40 ) ;
F_397 ( V_101 -> V_18 . V_115 ) ;
#endif
F_26 ( V_101 -> V_18 . V_40 ) ;
F_26 ( V_101 -> V_18 . V_115 ) ;
}
int T_12 F_405 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_406 () ;
if ( V_32 < 0 ) {
F_407 ( L_31 ,
V_47 , V_32 ) ;
goto V_175;
}
V_32 = F_317 ( & V_688 ) ;
if ( V_32 < 0 )
goto V_689;
V_15 = F_408 ( L_32 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_690;
}
F_249 () ;
V_5 = F_28 ( V_691 . V_692 ) ;
F_94 () ;
if ( F_52 ( V_5 ) ) {
V_32 = F_119 ( V_5 ) ;
goto V_693;
}
for ( V_16 = 0 ; V_16 < V_436 ; V_16 ++ )
F_409 ( & V_180 [ V_16 ] ) ;
F_410 ( & V_694 ) ;
F_246 () ;
F_411 ( & V_695 ) ;
V_32 = F_412 ( V_696 , V_697 , NULL , F_378 ,
NULL ) ;
if ( V_32 < 0 )
goto V_104;
F_412 ( V_696 , V_399 , F_329 , NULL , NULL ) ;
F_412 ( V_696 , V_199 , F_326 , NULL , NULL ) ;
F_412 ( V_696 , V_698 , F_344 ,
F_341 , NULL ) ;
F_412 ( V_696 , V_530 , NULL ,
F_342 , NULL ) ;
F_412 ( V_696 , V_534 , NULL ,
F_343 , NULL ) ;
F_412 ( V_696 , V_699 , F_70 ,
F_77 , NULL ) ;
F_413 () ;
return 0 ;
V_104:
F_414 ( & V_695 ) ;
F_415 ( & V_694 ) ;
V_693:
F_416 ( V_15 ) ;
V_690:
F_319 ( & V_688 ) ;
V_689:
F_417 () ;
V_175:
return V_32 ;
}
void F_418 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_415 ( & V_694 ) ;
F_319 ( & V_688 ) ;
F_417 () ;
F_249 () ;
F_419 ( & V_695 ) ;
F_90 (&init_net, dev) {
if ( F_51 ( V_7 ) == NULL )
continue;
F_277 ( V_7 , 1 ) ;
}
F_277 ( V_691 . V_692 , 2 ) ;
F_141 ( & V_173 ) ;
for ( V_16 = 0 ; V_16 < V_436 ; V_16 ++ )
F_66 ( ! F_420 ( & V_180 [ V_16 ] ) ) ;
F_142 ( & V_173 ) ;
F_10 ( & V_477 ) ;
F_94 () ;
F_416 ( V_15 ) ;
}
