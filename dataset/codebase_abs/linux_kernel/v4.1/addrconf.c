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
V_31 -> V_39 . V_41 = V_7 -> V_33 ;
V_31 -> V_39 . V_42 = NULL ;
V_31 -> V_43 = F_35 ( V_7 , & V_44 ) ;
if ( ! V_31 -> V_43 ) {
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
if ( ! V_92 )
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
if ( ! V_84 )
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
if ( ! V_7 )
goto V_104;
V_112 = F_51 ( V_7 ) ;
if ( ! V_112 )
goto V_104;
V_87 = & V_112 -> V_39 ;
break;
}
V_32 = - V_102 ;
V_84 = F_65 ( F_54 ( - 1 ) , V_103 ) ;
if ( ! V_84 )
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
if ( ! V_134 ) {
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
F_122 ( & V_134 -> V_11 , V_176 ) ;
F_123 ( & V_134 -> V_146 ) ;
V_134 -> V_159 = V_159 ;
V_134 -> V_177 = V_158 ;
V_134 -> V_50 = V_50 | V_137 ;
V_134 -> V_160 = V_160 ;
V_134 -> V_161 = V_161 ;
V_134 -> V_1 = V_134 -> V_70 = V_13 ;
V_134 -> V_178 = false ;
V_134 -> V_149 = V_149 ;
V_134 -> V_5 = V_5 ;
F_14 ( V_5 ) ;
F_18 ( V_134 ) ;
V_163 = F_110 ( V_153 ) ;
F_124 ( & V_134 -> V_146 , & V_179 [ V_163 ] ) ;
F_125 ( & V_173 ) ;
F_126 ( & V_5 -> V_36 ) ;
F_105 ( V_5 , V_134 ) ;
if ( V_134 -> V_50 & V_180 ) {
F_127 ( & V_134 -> V_181 , & V_5 -> V_59 ) ;
F_18 ( V_134 ) ;
}
F_18 ( V_134 ) ;
F_128 ( & V_5 -> V_36 ) ;
V_170:
F_129 () ;
if ( F_130 ( V_32 == 0 ) )
F_131 ( V_182 , V_134 ) ;
else {
F_26 ( V_134 ) ;
V_134 = F_30 ( V_32 ) ;
}
return V_134 ;
V_175:
F_125 ( & V_173 ) ;
goto V_170;
}
static enum V_183
F_132 ( struct V_9 * V_10 , unsigned long * V_184 )
{
struct V_9 * V_134 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_185 ;
enum V_183 V_186 = V_187 ;
* V_184 = V_13 ;
F_86 (ifa, &idev->addr_list, if_list) {
if ( V_134 == V_10 )
continue;
if ( ! F_133 ( & V_134 -> V_153 , & V_10 -> V_153 ,
V_10 -> V_177 ) )
continue;
if ( V_134 -> V_50 & ( V_188 | V_189 ) )
return V_190 ;
V_186 = V_191 ;
F_116 ( & V_134 -> V_36 ) ;
V_185 = F_134 ( V_134 -> V_160 , V_3 ) ;
if ( F_135 ( * V_184 , V_134 -> V_70 + V_185 * V_3 ) )
* V_184 = V_134 -> V_70 + V_185 * V_3 ;
F_125 ( & V_134 -> V_36 ) ;
}
return V_186 ;
}
static void
F_136 ( struct V_9 * V_10 , unsigned long V_184 , bool V_192 )
{
struct V_162 * V_149 ;
V_149 = F_137 ( & V_10 -> V_153 ,
V_10 -> V_177 ,
V_10 -> V_5 -> V_7 ,
0 , V_193 | V_194 ) ;
if ( V_149 ) {
if ( V_192 )
F_138 ( V_149 ) ;
else {
if ( ! ( V_149 -> V_195 & V_196 ) )
F_139 ( V_149 , V_184 ) ;
F_103 ( V_149 ) ;
}
}
}
static void F_140 ( struct V_9 * V_10 )
{
int V_147 ;
enum V_183 V_186 = V_190 ;
unsigned long V_184 ;
F_29 () ;
F_141 ( & V_10 -> V_36 ) ;
V_147 = V_10 -> V_147 ;
V_10 -> V_147 = V_148 ;
F_142 ( & V_10 -> V_36 ) ;
if ( V_147 == V_148 )
goto V_175;
F_141 ( & V_173 ) ;
F_143 ( & V_10 -> V_146 ) ;
F_142 ( & V_173 ) ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_10 -> V_50 & V_180 ) {
F_145 ( & V_10 -> V_181 ) ;
if ( V_10 -> V_197 ) {
F_146 ( V_10 -> V_197 ) ;
V_10 -> V_197 = NULL ;
}
F_11 ( V_10 ) ;
}
if ( V_10 -> V_50 & V_188 && ! ( V_10 -> V_50 & V_189 ) )
V_186 = F_132 ( V_10 , & V_184 ) ;
F_147 ( & V_10 -> V_154 ) ;
F_11 ( V_10 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
F_9 ( V_10 ) ;
F_149 ( V_198 , V_10 ) ;
F_131 ( V_199 , V_10 ) ;
if ( V_186 != V_190 ) {
F_136 ( V_10 , V_184 ,
V_186 == V_187 ) ;
}
F_150 ( V_10 ) ;
V_175:
F_146 ( V_10 ) ;
}
static int F_151 ( struct V_9 * V_10 , struct V_9 * V_200 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_155 V_153 , * V_201 ;
unsigned long V_202 , V_203 , V_204 , V_205 ;
unsigned long V_206 ;
int V_207 ;
int V_208 = 0 ;
T_1 V_209 ;
unsigned long V_210 = V_13 ;
F_144 ( & V_5 -> V_36 ) ;
if ( V_200 ) {
F_141 ( & V_200 -> V_36 ) ;
memcpy ( & V_153 . V_211 [ 8 ] , & V_200 -> V_153 . V_211 [ 8 ] , 8 ) ;
F_142 ( & V_200 -> V_36 ) ;
V_201 = & V_153 ;
} else {
V_201 = NULL ;
}
V_212:
F_14 ( V_5 ) ;
if ( V_5 -> V_39 . V_65 <= 0 ) {
F_148 ( & V_5 -> V_36 ) ;
F_43 ( L_9 , V_47 ) ;
F_100 ( V_5 ) ;
V_208 = - 1 ;
goto V_175;
}
F_141 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_213 ++ >= V_5 -> V_39 . V_214 ) {
V_5 -> V_39 . V_65 = - 1 ;
F_142 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_102 ( L_10 ,
V_47 ) ;
F_100 ( V_5 ) ;
V_208 = - 1 ;
goto V_175;
}
F_18 ( V_10 ) ;
memcpy ( V_153 . V_211 , V_10 -> V_153 . V_211 , 8 ) ;
F_152 ( V_5 , V_201 ) ;
memcpy ( & V_153 . V_211 [ 8 ] , V_5 -> V_215 , 8 ) ;
V_205 = ( V_210 - V_10 -> V_70 ) / V_3 ;
V_203 = F_153 ( V_216 ,
V_10 -> V_160 ,
V_5 -> V_39 . V_217 + V_205 ) ;
V_202 = F_153 ( V_216 ,
V_10 -> V_161 ,
V_5 -> V_39 . V_218 + V_205 -
V_5 -> V_39 . V_219 ) ;
V_207 = V_10 -> V_177 ;
V_204 = V_10 -> V_70 ;
F_142 ( & V_10 -> V_36 ) ;
V_206 = V_5 -> V_39 . V_214 *
V_5 -> V_39 . V_220 *
F_154 ( V_5 -> V_43 , V_221 ) / V_3 ;
F_148 ( & V_5 -> V_36 ) ;
V_205 = ( V_210 - V_204 + V_222 ) / V_3 ;
if ( V_202 <= V_206 + V_205 ) {
F_146 ( V_10 ) ;
F_100 ( V_5 ) ;
V_208 = - 1 ;
goto V_175;
}
V_209 = V_180 ;
if ( V_10 -> V_50 & V_223 )
V_209 |= V_223 ;
V_200 = F_113 ( V_5 , & V_153 , NULL , V_207 ,
F_155 ( & V_153 ) , V_209 ,
V_203 , V_202 ) ;
if ( F_52 ( V_200 ) ) {
F_146 ( V_10 ) ;
F_100 ( V_5 ) ;
F_43 ( L_11 , V_47 ) ;
V_201 = & V_153 ;
F_144 ( & V_5 -> V_36 ) ;
goto V_212;
}
F_141 ( & V_200 -> V_36 ) ;
V_200 -> V_197 = V_10 ;
V_200 -> V_1 = V_210 ;
V_200 -> V_70 = V_204 ;
F_142 ( & V_200 -> V_36 ) ;
F_156 ( V_200 ) ;
F_146 ( V_200 ) ;
F_100 ( V_5 ) ;
V_175:
return V_208 ;
}
static inline int F_157 ( int type )
{
if ( type & ( V_224 | V_225 | V_167 ) )
return 1 ;
return 0 ;
}
static inline bool F_158 ( struct V_4 * V_5 )
{
#ifdef F_159
return V_5 && V_5 -> V_39 . V_226 && V_5 -> V_39 . V_227 ;
#else
return false ;
#endif
}
static int F_160 ( struct V_101 * V_101 ,
struct V_228 * V_229 ,
struct V_230 * V_231 ,
int V_16 )
{
int V_208 ;
if ( V_16 <= V_229 -> V_232 ) {
switch ( V_16 ) {
case V_233 :
V_208 = V_229 -> V_234 ;
break;
case V_235 :
V_208 = V_229 -> V_236 ;
break;
default:
V_208 = ! ! F_161 ( V_16 , V_229 -> V_237 ) ;
}
goto V_175;
}
switch ( V_16 ) {
case V_238 :
V_208 = ! ! V_229 -> V_134 ;
break;
case V_239 :
V_208 = F_162 ( & V_229 -> V_134 -> V_153 , V_231 -> V_153 ) ;
break;
case V_233 :
V_208 = F_163 ( V_229 -> V_164 ) ;
if ( V_208 >= V_231 -> V_159 )
V_208 = - V_208 ;
else
V_208 -= 128 ;
V_229 -> V_234 = V_208 ;
break;
case V_240 :
{
T_3 V_241 = V_242 ;
if ( ! F_158 ( V_229 -> V_134 -> V_5 ) )
V_241 |= V_223 ;
V_208 = F_157 ( V_229 -> V_164 ) ||
! ( V_229 -> V_134 -> V_50 & V_241 ) ;
break;
}
#ifdef F_164
case V_243 :
{
int V_244 = ! ( V_231 -> V_245 & V_246 ) ;
V_208 = ! ( V_229 -> V_134 -> V_50 & V_247 ) ^ V_244 ;
break;
}
#endif
case V_248 :
V_208 = ( ! V_231 -> V_85 ||
V_231 -> V_85 == V_229 -> V_134 -> V_5 -> V_7 -> V_85 ) ;
break;
case V_249 :
V_208 = F_165 ( V_101 ,
& V_229 -> V_134 -> V_153 , V_229 -> V_164 ,
V_229 -> V_134 -> V_5 -> V_7 -> V_85 ) == V_231 -> V_250 ;
break;
case V_251 :
{
int V_252 = V_231 -> V_245 & ( V_253 | V_254 ) ?
! ! ( V_231 -> V_245 & V_254 ) :
V_229 -> V_134 -> V_5 -> V_39 . V_65 >= 2 ;
V_208 = ( ! ( V_229 -> V_134 -> V_50 & V_180 ) ) ^ V_252 ;
break;
}
case V_255 :
V_208 = ! ( F_166 ( & V_229 -> V_134 -> V_153 ) ^
F_166 ( V_231 -> V_153 ) ) ;
break;
case V_235 :
V_208 = F_167 ( & V_229 -> V_134 -> V_153 , V_231 -> V_153 ) ;
if ( V_208 > V_229 -> V_134 -> V_177 )
V_208 = V_229 -> V_134 -> V_177 ;
V_229 -> V_236 = V_208 ;
break;
#ifdef F_159
case V_256 :
V_208 = ! ( V_229 -> V_134 -> V_50 & V_223 ) ;
break;
#endif
default:
V_208 = 0 ;
}
if ( V_208 )
F_168 ( V_16 , V_229 -> V_237 ) ;
V_229 -> V_232 = V_16 ;
V_175:
return V_208 ;
}
int F_169 ( struct V_101 * V_101 , const struct V_6 * V_257 ,
const struct V_155 * V_258 , unsigned int V_245 ,
struct V_155 * V_259 )
{
struct V_228 V_260 [ 2 ] ,
* V_229 = & V_260 [ 0 ] , * V_261 = & V_260 [ 1 ] ;
struct V_230 V_231 ;
struct V_6 * V_7 ;
int V_262 ;
V_262 = F_170 ( V_258 ) ;
V_231 . V_153 = V_258 ;
V_231 . V_85 = V_257 ? V_257 -> V_85 : 0 ;
V_231 . V_159 = F_163 ( V_262 ) ;
V_231 . V_250 = F_165 ( V_101 , V_258 , V_262 , V_231 . V_85 ) ;
V_231 . V_245 = V_245 ;
V_261 -> V_232 = - 1 ;
V_261 -> V_134 = NULL ;
F_78 () ;
F_171 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_262 & V_166 ) ||
V_231 . V_159 <= V_263 ) &&
V_231 . V_85 && V_7 -> V_85 != V_231 . V_85 )
continue;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
continue;
F_172 ( & V_5 -> V_36 ) ;
F_86 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_229 -> V_134 -> V_50 & V_137 ) &&
( ! ( V_229 -> V_134 -> V_50 & V_223 ) ) )
continue;
V_229 -> V_164 = F_170 ( & V_229 -> V_134 -> V_153 ) ;
if ( F_173 ( V_229 -> V_164 == V_165 ||
V_229 -> V_164 & V_166 ) ) {
F_174 ( L_12 ,
V_7 -> V_48 ) ;
continue;
}
V_229 -> V_232 = - 1 ;
F_175 ( V_229 -> V_237 , V_264 ) ;
for ( V_16 = 0 ; V_16 < V_264 ; V_16 ++ ) {
int V_265 , V_266 ;
V_265 = F_160 ( V_101 , V_261 , & V_231 , V_16 ) ;
V_266 = F_160 ( V_101 , V_229 , & V_231 , V_16 ) ;
if ( V_265 > V_266 ) {
if ( V_16 == V_233 &&
V_229 -> V_234 > 0 ) {
goto V_267;
}
break;
} else if ( V_265 < V_266 ) {
if ( V_261 -> V_134 )
F_146 ( V_261 -> V_134 ) ;
F_18 ( V_229 -> V_134 ) ;
F_176 ( V_261 , V_229 ) ;
V_229 -> V_134 = V_261 -> V_134 ;
break;
}
}
}
V_267:
F_177 ( & V_5 -> V_36 ) ;
}
F_81 () ;
if ( ! V_261 -> V_134 )
return - V_168 ;
* V_259 = V_261 -> V_134 -> V_153 ;
F_146 ( V_261 -> V_134 ) ;
return 0 ;
}
int F_178 ( struct V_4 * V_5 , struct V_155 * V_153 ,
T_1 V_268 )
{
struct V_9 * V_10 ;
int V_32 = - V_168 ;
F_179 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_159 > V_269 )
break;
if ( V_10 -> V_159 == V_269 &&
! ( V_10 -> V_50 & V_268 ) ) {
* V_153 = V_10 -> V_153 ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
int F_180 ( struct V_6 * V_7 , struct V_155 * V_153 ,
T_1 V_268 )
{
struct V_4 * V_5 ;
int V_32 = - V_168 ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_172 ( & V_5 -> V_36 ) ;
V_32 = F_178 ( V_5 , V_153 , V_268 ) ;
F_177 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_32 ;
}
static int F_181 ( struct V_4 * V_5 )
{
int V_270 = 0 ;
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list)
V_270 ++ ;
F_177 ( & V_5 -> V_36 ) ;
return V_270 ;
}
int F_182 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
const struct V_6 * V_7 , int V_271 )
{
return F_183 ( V_101 , V_153 , V_7 , V_271 , V_137 ) ;
}
int F_183 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
const struct V_6 * V_7 , int V_271 ,
T_1 V_268 )
{
struct V_9 * V_10 ;
unsigned int V_163 = F_110 ( V_153 ) ;
T_1 V_272 ;
F_115 () ;
F_80 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_184 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_272 = ( V_10 -> V_50 & V_223 )
? ( V_10 -> V_50 & ~ V_137 )
: V_10 -> V_50 ;
if ( F_162 ( & V_10 -> V_153 , V_153 ) &&
! ( V_272 & V_268 ) &&
( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_159 & ( V_269 | V_273 ) || V_271 ) ) ) {
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
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_186 ( const struct V_155 * V_153 ,
const unsigned int V_177 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_134 ;
bool V_208 = false ;
F_78 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifa, &idev->addr_list, if_list) {
V_208 = F_133 ( V_153 , & V_134 -> V_153 , V_177 ) ;
if ( V_208 )
break;
}
F_177 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_208 ;
}
int F_187 ( const struct V_155 * V_153 , struct V_6 * V_7 )
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
V_134 -> V_177 ) ;
if ( V_274 )
break;
}
F_177 ( & V_5 -> V_36 ) ;
}
F_81 () ;
return V_274 ;
}
struct V_9 * F_188 ( struct V_101 * V_101 , const struct V_155 * V_153 ,
struct V_6 * V_7 , int V_271 )
{
struct V_9 * V_10 , * V_275 = NULL ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_189 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_184 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_162 ( & V_10 -> V_153 , V_153 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_159 & ( V_269 | V_273 ) || V_271 ) ) {
V_275 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_129 () ;
return V_275 ;
}
static void F_190 ( struct V_9 * V_10 , int V_276 )
{
if ( V_10 -> V_50 & V_188 ) {
F_141 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_50 |= V_137 ;
if ( V_276 )
V_10 -> V_50 |= V_277 ;
F_142 ( & V_10 -> V_36 ) ;
if ( V_276 )
F_149 ( 0 , V_10 ) ;
F_146 ( V_10 ) ;
} else if ( V_10 -> V_50 & V_180 ) {
struct V_9 * V_197 ;
F_141 ( & V_10 -> V_36 ) ;
V_197 = V_10 -> V_197 ;
if ( V_197 ) {
F_18 ( V_197 ) ;
F_142 ( & V_10 -> V_36 ) ;
F_151 ( V_197 , V_10 ) ;
F_146 ( V_197 ) ;
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
int V_32 = - V_278 ;
F_141 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 == V_279 ) {
V_10 -> V_147 = V_280 ;
V_32 = 0 ;
}
F_142 ( & V_10 -> V_36 ) ;
return V_32 ;
}
void F_192 ( struct V_9 * V_10 )
{
struct V_155 V_153 ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_101 * V_101 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( F_191 ( V_10 ) ) {
F_146 ( V_10 ) ;
return;
}
F_193 ( L_13 ,
V_10 -> V_5 -> V_7 -> V_48 , & V_10 -> V_153 ) ;
F_141 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_50 & V_281 ) {
int V_159 = V_10 -> V_159 ;
T_1 V_50 = V_10 -> V_50 ;
struct V_155 V_282 ;
struct V_9 * V_283 ;
T_1 V_160 , V_284 ;
int V_158 = V_10 -> V_177 ;
int V_285 = V_10 -> V_286 + 1 ;
if ( V_285 > V_101 -> V_18 . V_42 . V_287 ) {
F_193 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
goto V_288;
}
V_282 = V_10 -> V_153 ;
if ( F_194 ( & V_282 , V_285 ,
V_5 ) )
goto V_288;
V_160 = V_10 -> V_160 ;
V_284 = V_10 -> V_161 ;
F_142 ( & V_10 -> V_36 ) ;
if ( V_5 -> V_39 . V_289 &&
F_181 ( V_5 ) >=
V_5 -> V_39 . V_289 )
goto V_290;
F_193 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
V_283 = F_113 ( V_5 , & V_282 , NULL , V_158 ,
V_159 , V_50 , V_160 ,
V_284 ) ;
if ( F_52 ( V_283 ) )
goto V_290;
F_141 ( & V_283 -> V_36 ) ;
V_283 -> V_286 = V_285 ;
V_283 -> V_147 = V_291 ;
F_142 ( & V_283 -> V_36 ) ;
F_16 ( V_283 , V_101 -> V_18 . V_42 . V_292 ) ;
F_146 ( V_283 ) ;
V_290:
F_141 ( & V_10 -> V_36 ) ;
} else if ( V_5 -> V_39 . V_53 > 1 && ! V_5 -> V_39 . V_171 ) {
V_153 . V_293 [ 0 ] = F_195 ( 0xfe800000 ) ;
V_153 . V_293 [ 1 ] = 0 ;
if ( ! F_196 ( V_153 . V_211 + 8 , V_5 -> V_7 ) &&
F_162 ( & V_10 -> V_153 , & V_153 ) ) {
V_5 -> V_39 . V_171 = 1 ;
F_43 ( L_16 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
}
}
V_288:
V_10 -> V_147 = V_294 ;
F_142 ( & V_10 -> V_36 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_197 ( struct V_6 * V_7 , const struct V_155 * V_153 )
{
struct V_155 V_295 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_198 ( V_153 , & V_295 ) ;
F_48 ( V_7 , & V_295 ) ;
}
void F_199 ( struct V_4 * V_5 , const struct V_155 * V_153 )
{
struct V_155 V_295 ;
if ( V_5 -> V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_198 ( V_153 , & V_295 ) ;
F_200 ( V_5 , & V_295 ) ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_155 V_153 ;
if ( V_10 -> V_177 >= 127 )
return;
F_201 ( & V_153 , & V_10 -> V_153 , V_10 -> V_177 ) ;
if ( F_202 ( & V_153 ) )
return;
F_203 ( V_10 -> V_5 , & V_153 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_155 V_153 ;
if ( V_10 -> V_177 >= 127 )
return;
F_201 ( & V_153 , & V_10 -> V_153 , V_10 -> V_177 ) ;
if ( F_202 ( & V_153 ) )
return;
F_204 ( V_10 -> V_5 , & V_153 ) ;
}
static int F_205 ( T_3 * V_296 , struct V_6 * V_7 )
{
if ( V_7 -> V_297 != V_298 )
return - 1 ;
memcpy ( V_296 , V_7 -> V_299 , 3 ) ;
memcpy ( V_296 + 5 , V_7 -> V_299 + 3 , 3 ) ;
if ( V_7 -> V_300 ) {
V_296 [ 3 ] = ( V_7 -> V_300 >> 8 ) & 0xFF ;
V_296 [ 4 ] = V_7 -> V_300 & 0xFF ;
} else {
V_296 [ 3 ] = 0xFF ;
V_296 [ 4 ] = 0xFE ;
V_296 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_206 ( T_3 * V_296 , struct V_6 * V_7 )
{
if ( V_7 -> V_297 != V_301 )
return - 1 ;
memcpy ( V_296 , V_7 -> V_299 , 8 ) ;
V_296 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_207 ( T_3 * V_296 , struct V_6 * V_7 )
{
union V_302 * V_303 ;
if ( V_7 -> V_297 != V_304 )
return - 1 ;
V_303 = (union V_302 * ) V_7 -> V_299 ;
memcpy ( V_296 , & V_303 -> V_305 . V_306 , sizeof( V_303 -> V_305 . V_306 ) ) ;
V_296 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_208 ( T_3 * V_296 , struct V_6 * V_7 )
{
if ( V_7 -> V_297 != V_307 )
return - 1 ;
memset ( V_296 , 0 , 7 ) ;
V_296 [ 7 ] = * ( T_3 * ) V_7 -> V_299 ;
return 0 ;
}
static int F_209 ( T_3 * V_296 , struct V_6 * V_7 )
{
if ( V_7 -> V_297 != V_308 )
return - 1 ;
memcpy ( V_296 , V_7 -> V_299 + 12 , 8 ) ;
V_296 [ 0 ] |= 2 ;
return 0 ;
}
static int F_210 ( T_3 * V_296 , T_4 V_153 )
{
if ( V_153 == 0 )
return - 1 ;
V_296 [ 0 ] = ( F_211 ( V_153 ) || F_212 ( V_153 ) ||
F_213 ( V_153 ) || F_214 ( V_153 ) ||
F_215 ( V_153 ) || F_216 ( V_153 ) ||
F_217 ( V_153 ) || F_218 ( V_153 ) ||
F_219 ( V_153 ) || F_220 ( V_153 ) ||
F_221 ( V_153 ) ) ? 0x00 : 0x02 ;
V_296 [ 1 ] = 0 ;
V_296 [ 2 ] = 0x5E ;
V_296 [ 3 ] = 0xFE ;
memcpy ( V_296 + 4 , & V_153 , 4 ) ;
return 0 ;
}
static int F_222 ( T_3 * V_296 , struct V_6 * V_7 )
{
if ( V_7 -> V_56 & V_57 )
return F_210 ( V_296 , * ( T_4 * ) V_7 -> V_299 ) ;
return - 1 ;
}
static int F_223 ( T_3 * V_296 , struct V_6 * V_7 )
{
return F_210 ( V_296 , * ( T_4 * ) V_7 -> V_299 ) ;
}
static int F_224 ( T_3 * V_296 , struct V_6 * V_7 )
{
memcpy ( V_296 , V_7 -> V_309 , 3 ) ;
memcpy ( V_296 + 5 , V_7 -> V_309 + 3 , 3 ) ;
V_296 [ 3 ] = 0xFF ;
V_296 [ 4 ] = 0xFE ;
V_296 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_196 ( T_3 * V_296 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_310 :
case V_311 :
return F_205 ( V_296 , V_7 ) ;
case V_312 :
return F_208 ( V_296 , V_7 ) ;
case V_313 :
return F_209 ( V_296 , V_7 ) ;
case V_55 :
return F_222 ( V_296 , V_7 ) ;
case V_314 :
return F_223 ( V_296 , V_7 ) ;
case V_315 :
case V_316 :
return F_206 ( V_296 , V_7 ) ;
case V_317 :
return F_207 ( V_296 , V_7 ) ;
case V_63 :
return F_224 ( V_296 , V_7 ) ;
}
return - 1 ;
}
static int F_225 ( T_3 * V_296 , struct V_4 * V_5 )
{
int V_32 = - 1 ;
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_179 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_159 > V_269 )
break;
if ( V_10 -> V_159 == V_269 && ! ( V_10 -> V_50 & V_137 ) ) {
memcpy ( V_296 , V_10 -> V_153 . V_211 + 8 , 8 ) ;
V_32 = 0 ;
break;
}
}
F_177 ( & V_5 -> V_36 ) ;
return V_32 ;
}
static void F_226 ( struct V_4 * V_5 )
{
V_318:
F_227 ( V_5 -> V_215 , sizeof( V_5 -> V_215 ) ) ;
V_5 -> V_215 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_215 [ 0 ] == 0xfd &&
( V_5 -> V_215 [ 1 ] & V_5 -> V_215 [ 2 ] & V_5 -> V_215 [ 3 ] & V_5 -> V_215 [ 4 ] & V_5 -> V_215 [ 5 ] & V_5 -> V_215 [ 6 ] ) == 0xff &&
( V_5 -> V_215 [ 7 ] & 0x80 ) )
goto V_318;
if ( ( V_5 -> V_215 [ 0 ] | V_5 -> V_215 [ 1 ] ) == 0 ) {
if ( V_5 -> V_215 [ 2 ] == 0x5e && V_5 -> V_215 [ 3 ] == 0xfe )
goto V_318;
if ( ( V_5 -> V_215 [ 2 ] | V_5 -> V_215 [ 3 ] | V_5 -> V_215 [ 4 ] | V_5 -> V_215 [ 5 ] | V_5 -> V_215 [ 6 ] | V_5 -> V_215 [ 7 ] ) == 0x00 )
goto V_318;
}
}
static void V_61 ( unsigned long V_319 )
{
struct V_4 * V_5 = (struct V_4 * ) V_319 ;
unsigned long V_184 ;
F_115 () ;
F_144 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 )
goto V_175;
F_226 ( V_5 ) ;
V_184 = V_13 +
V_5 -> V_39 . V_218 * V_3 -
V_5 -> V_39 . V_214 * V_5 -> V_39 . V_220 *
F_154 ( V_5 -> V_43 , V_221 ) -
V_5 -> V_39 . V_219 * V_3 ;
if ( F_135 ( V_184 , V_13 ) ) {
F_102 ( L_17 ,
V_47 , V_5 -> V_7 -> V_48 ) ;
goto V_175;
}
if ( ! F_15 ( & V_5 -> V_60 , V_184 ) )
F_14 ( V_5 ) ;
V_175:
F_148 ( & V_5 -> V_36 ) ;
F_129 () ;
F_100 ( V_5 ) ;
}
static void F_152 ( struct V_4 * V_5 , struct V_155 * V_201 )
{
if ( V_201 && memcmp ( V_5 -> V_215 , & V_201 -> V_211 [ 8 ] , 8 ) == 0 )
F_226 ( V_5 ) ;
}
static void
F_228 ( struct V_155 * V_320 , int V_321 , struct V_6 * V_7 ,
unsigned long V_184 , T_1 V_50 )
{
struct V_322 V_323 = {
. V_324 = V_325 ,
. V_326 = V_327 ,
. V_328 = V_7 -> V_85 ,
. V_329 = V_184 ,
. V_330 = V_321 ,
. V_331 = V_332 | V_50 ,
. V_333 . V_334 = F_34 ( V_7 ) ,
. V_335 = V_336 ,
} ;
V_323 . V_337 = * V_320 ;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 && ( V_7 -> V_50 & V_338 ) )
V_323 . V_331 |= V_339 ;
#endif
F_229 ( & V_323 ) ;
}
static struct V_162 * F_137 ( const struct V_155 * V_320 ,
int V_321 ,
const struct V_6 * V_7 ,
T_1 V_50 , T_1 V_340 )
{
struct V_341 * V_342 ;
struct V_162 * V_149 = NULL ;
struct V_343 * V_141 ;
V_141 = F_230 ( F_34 ( V_7 ) , V_325 ) ;
if ( ! V_141 )
return NULL ;
F_172 ( & V_141 -> V_344 ) ;
V_342 = F_231 ( & V_141 -> V_345 , V_320 , V_321 , NULL , 0 ) ;
if ( ! V_342 )
goto V_175;
for ( V_149 = V_342 -> V_346 ; V_149 ; V_149 = V_149 -> V_231 . V_347 ) {
if ( V_149 -> V_231 . V_7 -> V_85 != V_7 -> V_85 )
continue;
if ( ( V_149 -> V_195 & V_50 ) != V_50 )
continue;
if ( ( V_149 -> V_195 & V_340 ) != 0 )
continue;
F_232 ( & V_149 -> V_231 ) ;
break;
}
V_175:
F_177 ( & V_141 -> V_344 ) ;
return V_149 ;
}
static void F_233 ( struct V_6 * V_7 )
{
struct V_322 V_323 = {
. V_324 = V_348 ,
. V_326 = V_327 ,
. V_328 = V_7 -> V_85 ,
. V_330 = 8 ,
. V_331 = V_332 ,
. V_333 . V_334 = F_34 ( V_7 ) ,
} ;
F_234 ( & V_323 . V_337 , F_195 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_229 ( & V_323 ) ;
}
static struct V_4 * F_235 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
return F_30 ( - V_102 ) ;
if ( V_5 -> V_39 . V_171 )
return F_30 ( - V_172 ) ;
if ( ! ( V_7 -> V_50 & V_52 ) )
F_233 ( V_7 ) ;
return V_5 ;
}
static void F_236 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_216 V_160 , V_216 V_161 ,
bool V_349 , unsigned long V_210 )
{
T_1 V_50 ;
struct V_9 * V_200 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ift, &idev->tempaddr_list, tmp_list) {
int V_205 , V_350 , V_351 ;
if ( V_10 != V_200 -> V_197 )
continue;
V_205 = ( V_210 - V_200 -> V_1 ) / V_3 ;
V_350 = V_5 -> V_39 . V_217 - V_205 ;
if ( V_350 < 0 )
V_350 = 0 ;
V_351 = V_5 -> V_39 . V_218 -
V_5 -> V_39 . V_219 - V_205 ;
if ( V_351 < 0 )
V_351 = 0 ;
if ( V_160 > V_350 )
V_160 = V_350 ;
if ( V_161 > V_351 )
V_161 = V_351 ;
F_116 ( & V_200 -> V_36 ) ;
V_50 = V_200 -> V_50 ;
V_200 -> V_160 = V_160 ;
V_200 -> V_161 = V_161 ;
V_200 -> V_70 = V_210 ;
if ( V_161 > 0 )
V_200 -> V_50 &= ~ V_242 ;
F_125 ( & V_200 -> V_36 ) ;
if ( ! ( V_50 & V_137 ) )
F_149 ( 0 , V_200 ) ;
}
if ( ( V_349 || F_237 ( & V_5 -> V_59 ) ) &&
V_5 -> V_39 . V_65 > 0 ) {
F_177 ( & V_5 -> V_36 ) ;
F_151 ( V_10 , NULL ) ;
} else {
F_177 ( & V_5 -> V_36 ) ;
}
}
void F_238 ( struct V_6 * V_7 , T_3 * V_352 , int V_133 , bool V_353 )
{
struct V_354 * V_355 ;
V_216 V_160 ;
V_216 V_161 ;
int V_164 ;
T_1 V_209 = 0 ;
struct V_4 * V_112 ;
struct V_101 * V_101 = F_34 ( V_7 ) ;
V_355 = (struct V_354 * ) V_352 ;
if ( V_133 < sizeof( struct V_354 ) ) {
F_38 ( L_18 ) ;
return;
}
V_164 = F_114 ( & V_355 -> V_356 ) ;
if ( V_164 & ( V_166 | V_357 ) )
return;
V_160 = F_239 ( V_355 -> V_358 ) ;
V_161 = F_239 ( V_355 -> V_359 ) ;
if ( V_161 > V_160 ) {
F_240 ( L_19 ) ;
return;
}
V_112 = F_241 ( V_7 ) ;
if ( ! V_112 ) {
F_174 ( L_20 ,
V_7 -> V_48 ) ;
return;
}
if ( V_355 -> V_274 ) {
struct V_162 * V_149 ;
unsigned long V_360 ;
if ( V_3 > V_361 )
V_360 = F_134 ( V_160 , V_3 ) ;
else
V_360 = F_134 ( V_160 , V_361 ) ;
if ( F_242 ( V_360 ) )
V_360 *= V_3 ;
V_149 = F_137 ( & V_355 -> V_356 ,
V_355 -> V_177 ,
V_7 ,
V_362 | V_363 ,
V_193 | V_194 ) ;
if ( V_149 ) {
if ( V_160 == 0 ) {
F_138 ( V_149 ) ;
V_149 = NULL ;
} else if ( F_242 ( V_360 ) ) {
F_139 ( V_149 , V_13 + V_360 ) ;
} else {
F_243 ( V_149 ) ;
}
} else if ( V_160 ) {
T_5 V_184 = 0 ;
int V_50 = V_362 | V_363 ;
if ( F_242 ( V_360 ) ) {
V_50 |= V_196 ;
V_184 = F_244 ( V_360 ) ;
}
F_228 ( & V_355 -> V_356 , V_355 -> V_177 ,
V_7 , V_184 , V_50 ) ;
}
F_103 ( V_149 ) ;
}
if ( V_355 -> V_364 && V_112 -> V_39 . V_364 ) {
struct V_9 * V_10 ;
struct V_155 V_153 ;
int V_349 = 0 , V_365 = 0 ;
bool V_178 = false ;
if ( V_355 -> V_177 == 64 ) {
memcpy ( & V_153 , & V_355 -> V_356 , 8 ) ;
if ( ! F_202 ( & V_112 -> V_66 ) ) {
F_172 ( & V_112 -> V_36 ) ;
memcpy ( V_153 . V_211 + 8 ,
V_112 -> V_66 . V_211 + 8 , 8 ) ;
F_177 ( & V_112 -> V_36 ) ;
V_178 = true ;
} else if ( V_112 -> V_366 ==
V_367 &&
! F_194 ( & V_153 , 0 ,
V_112 ) ) {
V_209 |= V_281 ;
goto V_368;
} else if ( F_196 ( V_153 . V_211 + 8 , V_7 ) &&
F_225 ( V_153 . V_211 + 8 , V_112 ) ) {
F_100 ( V_112 ) ;
return;
}
goto V_368;
}
F_174 ( L_21 ,
V_355 -> V_177 ) ;
F_100 ( V_112 ) ;
return;
V_368:
V_10 = F_188 ( V_101 , & V_153 , V_7 , 1 ) ;
if ( ! V_10 && V_160 ) {
int V_289 = V_112 -> V_39 . V_289 ;
#ifdef F_159
if ( V_112 -> V_39 . V_226 &&
! V_101 -> V_18 . V_115 -> V_45 && V_353 )
V_209 = V_223 ;
#endif
if ( ! V_289 ||
F_181 ( V_112 ) < V_289 )
V_10 = F_113 ( V_112 , & V_153 , NULL ,
V_355 -> V_177 ,
V_164 & V_369 ,
V_209 , V_160 ,
V_161 ) ;
if ( F_245 ( V_10 ) ) {
F_100 ( V_112 ) ;
return;
}
V_365 = 0 ;
V_349 = 1 ;
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 |= V_370 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_178 = V_178 ;
F_142 ( & V_10 -> V_36 ) ;
F_156 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_50 ;
unsigned long V_210 ;
T_1 V_371 ;
F_141 ( & V_10 -> V_36 ) ;
V_210 = V_13 ;
if ( V_10 -> V_160 > ( V_210 - V_10 -> V_70 ) / V_3 )
V_371 = V_10 -> V_160 - ( V_210 - V_10 -> V_70 ) / V_3 ;
else
V_371 = 0 ;
if ( ! V_365 && ! V_349 && V_371 ) {
const T_1 V_372 = F_153 ( T_1 ,
V_371 , V_373 ) ;
V_160 = F_246 ( V_160 , V_372 ) ;
V_365 = 1 ;
}
if ( V_365 ) {
V_10 -> V_160 = V_160 ;
V_10 -> V_161 = V_161 ;
V_10 -> V_70 = V_210 ;
V_50 = V_10 -> V_50 ;
V_10 -> V_50 &= ~ V_242 ;
F_142 ( & V_10 -> V_36 ) ;
if ( ! ( V_50 & V_137 ) )
F_149 ( 0 , V_10 ) ;
} else
F_142 ( & V_10 -> V_36 ) ;
F_236 ( V_112 , V_10 , V_160 , V_161 ,
V_349 , V_210 ) ;
F_146 ( V_10 ) ;
F_247 () ;
}
}
F_248 ( V_374 , V_112 , V_355 ) ;
F_100 ( V_112 ) ;
}
int F_249 ( struct V_101 * V_101 , void T_6 * V_375 )
{
struct V_376 V_377 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_250 () ;
V_32 = - V_378 ;
if ( F_251 ( & V_377 , V_375 , sizeof( struct V_376 ) ) )
goto V_379;
V_7 = F_74 ( V_101 , V_377 . V_380 ) ;
V_32 = - V_169 ;
if ( ! V_7 )
goto V_379;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 ) {
const struct V_381 * V_382 = V_7 -> V_383 ;
struct V_384 V_385 ;
struct V_386 V_142 ;
V_32 = - V_168 ;
if ( ! ( F_114 ( & V_377 . V_387 ) & V_225 ) )
goto V_379;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_388 . V_258 = V_377 . V_387 . V_293 [ 3 ] ;
V_142 . V_388 . V_259 = 0 ;
V_142 . V_388 . V_389 = 4 ;
V_142 . V_388 . V_390 = 5 ;
V_142 . V_388 . V_391 = V_392 ;
V_142 . V_388 . V_393 = 64 ;
V_385 . V_394 . V_395 = ( V_396 void T_6 * ) & V_142 ;
if ( V_382 -> V_397 ) {
T_7 V_398 = F_252 () ;
F_253 ( V_399 ) ;
V_32 = V_382 -> V_397 ( V_7 , & V_385 , V_400 ) ;
F_253 ( V_398 ) ;
} else
V_32 = - V_401 ;
if ( V_32 == 0 ) {
V_32 = - V_102 ;
V_7 = F_254 ( V_101 , V_142 . V_48 ) ;
if ( ! V_7 )
goto V_379;
V_32 = F_255 ( V_7 ) ;
}
}
#endif
V_379:
F_94 () ;
return V_32 ;
}
static int F_256 ( struct V_402 * V_108 , bool V_403 ,
const struct V_155 * V_153 , int V_85 )
{
int V_208 ;
F_29 () ;
F_257 ( V_108 ) ;
if ( V_403 )
V_208 = F_258 ( V_108 , V_85 , V_153 ) ;
else
V_208 = F_259 ( V_108 , V_85 , V_153 ) ;
F_260 ( V_108 ) ;
return V_208 ;
}
static int F_261 ( struct V_101 * V_101 , int V_85 ,
const struct V_155 * V_320 ,
const struct V_155 * V_404 ,
unsigned int V_321 , V_216 V_405 ,
V_216 V_161 , V_216 V_160 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_406 ;
T_5 V_184 ;
int V_159 ;
T_1 V_50 ;
F_29 () ;
if ( V_321 > 128 )
return - V_35 ;
if ( ! V_160 || V_161 > V_160 )
return - V_35 ;
if ( V_405 & V_370 && V_321 != 64 )
return - V_35 ;
V_7 = F_74 ( V_101 , V_85 ) ;
if ( ! V_7 )
return - V_169 ;
V_5 = F_235 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_119 ( V_5 ) ;
if ( V_405 & V_407 ) {
int V_208 = F_256 ( V_101 -> V_18 . V_408 ,
true , V_320 , V_85 ) ;
if ( V_208 < 0 )
return V_208 ;
}
V_159 = F_155 ( V_320 ) ;
V_406 = F_134 ( V_160 , V_3 ) ;
if ( F_242 ( V_406 ) ) {
V_184 = F_244 ( V_406 * V_3 ) ;
V_160 = V_406 ;
V_50 = V_196 ;
} else {
V_184 = 0 ;
V_50 = 0 ;
V_405 |= V_188 ;
}
V_406 = F_134 ( V_161 , V_3 ) ;
if ( F_242 ( V_406 ) ) {
if ( V_406 == 0 )
V_405 |= V_242 ;
V_161 = V_406 ;
}
V_10 = F_113 ( V_5 , V_320 , V_404 , V_321 , V_159 , V_405 ,
V_160 , V_161 ) ;
if ( ! F_52 ( V_10 ) ) {
if ( ! ( V_405 & V_189 ) ) {
F_228 ( & V_10 -> V_153 , V_10 -> V_177 , V_7 ,
V_184 , V_50 ) ;
}
F_156 ( V_10 ) ;
if ( V_405 & V_370 )
F_236 ( V_5 , V_10 , V_160 , V_161 ,
true , V_13 ) ;
F_146 ( V_10 ) ;
F_262 () ;
return 0 ;
} else if ( V_405 & V_407 ) {
F_256 ( V_101 -> V_18 . V_408 ,
false , V_320 , V_85 ) ;
}
return F_119 ( V_10 ) ;
}
static int F_263 ( struct V_101 * V_101 , int V_85 , T_1 V_405 ,
const struct V_155 * V_320 , unsigned int V_321 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_321 > 128 )
return - V_35 ;
V_7 = F_74 ( V_101 , V_85 ) ;
if ( ! V_7 )
return - V_169 ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return - V_409 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_177 == V_321 &&
F_162 ( V_320 , & V_10 -> V_153 ) ) {
F_18 ( V_10 ) ;
F_177 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_180 ) &&
( V_405 & V_370 ) )
F_236 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_140 ( V_10 ) ;
F_262 () ;
if ( F_264 ( V_320 ) ) {
F_256 ( V_101 -> V_18 . V_408 ,
false , V_320 , V_7 -> V_85 ) ;
}
return 0 ;
}
}
F_177 ( & V_5 -> V_36 ) ;
return - V_168 ;
}
int F_265 ( struct V_101 * V_101 , void T_6 * V_375 )
{
struct V_376 V_377 ;
int V_32 ;
if ( ! F_266 ( V_101 -> V_410 , V_411 ) )
return - V_412 ;
if ( F_251 ( & V_377 , V_375 , sizeof( struct V_376 ) ) )
return - V_378 ;
F_250 () ;
V_32 = F_261 ( V_101 , V_377 . V_380 , & V_377 . V_387 , NULL ,
V_377 . V_413 , V_188 ,
V_414 , V_414 ) ;
F_94 () ;
return V_32 ;
}
int F_267 ( struct V_101 * V_101 , void T_6 * V_375 )
{
struct V_376 V_377 ;
int V_32 ;
if ( ! F_266 ( V_101 -> V_410 , V_411 ) )
return - V_412 ;
if ( F_251 ( & V_377 , V_375 , sizeof( struct V_376 ) ) )
return - V_378 ;
F_250 () ;
V_32 = F_263 ( V_101 , V_377 . V_380 , 0 , & V_377 . V_387 ,
V_377 . V_413 ) ;
F_94 () ;
return V_32 ;
}
static void F_268 ( struct V_4 * V_5 , const struct V_155 * V_153 ,
int V_321 , int V_159 )
{
struct V_9 * V_10 ;
V_10 = F_113 ( V_5 , V_153 , NULL , V_321 ,
V_159 , V_188 ,
V_414 , V_414 ) ;
if ( ! F_52 ( V_10 ) ) {
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 &= ~ V_137 ;
F_142 ( & V_10 -> V_36 ) ;
F_149 ( V_415 , V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_269 ( struct V_4 * V_5 )
{
struct V_155 V_153 ;
struct V_6 * V_7 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_159 , V_321 ;
T_1 V_416 = 0 ;
F_29 () ;
memset ( & V_153 , 0 , sizeof( struct V_155 ) ) ;
memcpy ( & V_153 . V_293 [ 3 ] , V_5 -> V_7 -> V_299 , 4 ) ;
if ( V_5 -> V_7 -> V_50 & V_338 ) {
V_153 . V_293 [ 0 ] = F_195 ( 0xfe800000 ) ;
V_159 = V_269 ;
V_321 = 64 ;
} else {
V_159 = V_225 ;
V_321 = 96 ;
V_416 |= V_339 ;
}
if ( V_153 . V_293 [ 3 ] ) {
F_268 ( V_5 , & V_153 , V_321 , V_159 ) ;
F_228 ( & V_153 , V_321 , V_5 -> V_7 , 0 , V_416 ) ;
return;
}
F_90 (net, dev) {
struct V_417 * V_418 = F_270 ( V_7 ) ;
if ( V_418 && ( V_7 -> V_50 & V_77 ) ) {
struct V_419 * V_134 ;
int V_420 = V_159 ;
for ( V_134 = V_418 -> V_421 ; V_134 ; V_134 = V_134 -> V_422 ) {
V_153 . V_293 [ 3 ] = V_134 -> V_423 ;
if ( V_134 -> V_424 == V_425 )
continue;
if ( V_134 -> V_424 >= V_426 ) {
if ( V_5 -> V_7 -> V_50 & V_338 )
continue;
V_420 |= V_273 ;
}
F_268 ( V_5 , & V_153 , V_321 , V_420 ) ;
F_228 ( & V_153 , V_321 , V_5 -> V_7 , 0 ,
V_416 ) ;
}
}
}
}
static void F_271 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_427 ;
struct V_9 * V_428 ;
struct V_162 * V_429 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 ) {
F_99 ( L_22 , V_47 ) ;
return;
}
F_268 ( V_5 , & V_430 , 128 , V_273 ) ;
F_90 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_427 -> V_48 , V_7 -> V_48 ) )
continue;
V_5 = F_51 ( V_427 ) ;
if ( ! V_5 )
continue;
F_172 ( & V_5 -> V_36 ) ;
F_86 (sp_ifa, &idev->addr_list, if_list) {
if ( V_428 -> V_50 & ( V_277 | V_137 ) )
continue;
if ( V_428 -> V_149 ) {
if ( V_428 -> V_149 -> V_231 . V_431 > 0 ) {
F_103 ( V_428 -> V_149 ) ;
V_428 -> V_149 = NULL ;
} else {
continue;
}
}
V_429 = F_118 ( V_5 , & V_428 -> V_153 , false ) ;
if ( ! F_52 ( V_429 ) ) {
V_428 -> V_149 = V_429 ;
F_272 ( V_429 ) ;
}
}
F_177 ( & V_5 -> V_36 ) ;
}
}
static void F_273 ( struct V_4 * V_5 ,
const struct V_155 * V_153 , T_1 V_50 )
{
struct V_9 * V_10 ;
T_1 V_209 = V_50 | V_188 ;
#ifdef F_159
if ( V_5 -> V_39 . V_226 &&
! F_34 ( V_5 -> V_7 ) -> V_18 . V_115 -> V_45 )
V_209 |= V_223 ;
#endif
V_10 = F_113 ( V_5 , V_153 , NULL , 64 , V_269 , V_209 ,
V_414 , V_414 ) ;
if ( ! F_52 ( V_10 ) ) {
F_228 ( & V_10 -> V_153 , V_10 -> V_177 , V_5 -> V_7 , 0 , 0 ) ;
F_156 ( V_10 ) ;
F_146 ( V_10 ) ;
}
}
static bool F_274 ( struct V_155 V_432 )
{
if ( ( V_432 . V_293 [ 2 ] | V_432 . V_293 [ 3 ] ) == 0 )
return true ;
if ( V_432 . V_293 [ 2 ] == F_195 ( 0x02005eff ) &&
( ( V_432 . V_293 [ 3 ] & F_195 ( 0xfe000000 ) ) == F_195 ( 0xfe000000 ) ) )
return true ;
if ( V_432 . V_293 [ 2 ] == F_195 ( 0xfdffffff ) &&
( ( V_432 . V_293 [ 3 ] & F_195 ( 0xffffff80 ) ) == F_195 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_194 ( struct V_155 * V_432 ,
T_3 V_433 ,
const struct V_4 * V_5 )
{
static F_275 ( V_36 ) ;
static V_216 V_434 [ V_435 ] ;
static V_216 V_436 [ V_437 ] ;
static union {
char V_438 [ V_439 ] ;
struct {
struct V_155 V_440 ;
T_4 V_356 [ 2 ] ;
unsigned char V_441 [ V_442 ] ;
T_3 V_433 ;
} V_443 ;
} V_319 ;
struct V_155 V_440 ;
struct V_155 V_444 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
F_276 ( sizeof( V_319 . V_438 ) != sizeof( V_319 ) ) ;
if ( V_5 -> V_39 . V_445 . V_446 )
V_440 = V_5 -> V_39 . V_445 . V_440 ;
else if ( V_101 -> V_18 . V_40 -> V_445 . V_446 )
V_440 = V_101 -> V_18 . V_40 -> V_445 . V_440 ;
else
return - 1 ;
V_212:
F_141 ( & V_36 ) ;
F_277 ( V_434 ) ;
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
memset ( V_436 , 0 , sizeof( V_436 ) ) ;
memcpy ( V_319 . V_441 , V_5 -> V_7 -> V_309 , V_5 -> V_7 -> V_297 ) ;
V_319 . V_356 [ 0 ] = V_432 -> V_293 [ 0 ] ;
V_319 . V_356 [ 1 ] = V_432 -> V_293 [ 1 ] ;
V_319 . V_440 = V_440 ;
V_319 . V_433 = V_433 ;
F_278 ( V_434 , V_319 . V_438 , V_436 ) ;
V_444 = * V_432 ;
V_444 . V_293 [ 2 ] = ( V_396 T_4 ) V_434 [ 0 ] ;
V_444 . V_293 [ 3 ] = ( V_396 T_4 ) V_434 [ 1 ] ;
F_142 ( & V_36 ) ;
if ( F_274 ( V_444 ) ) {
V_433 ++ ;
if ( V_433 > F_34 ( V_5 -> V_7 ) -> V_18 . V_42 . V_287 )
return - 1 ;
goto V_212;
}
* V_432 = V_444 ;
return 0 ;
}
static void F_279 ( struct V_4 * V_5 , bool V_447 )
{
struct V_155 V_153 ;
F_234 ( & V_153 , F_195 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( V_5 -> V_366 == V_367 ) {
if ( ! F_194 ( & V_153 , 0 , V_5 ) )
F_273 ( V_5 , & V_153 ,
V_281 ) ;
else if ( V_447 )
F_228 ( & V_153 , 64 , V_5 -> V_7 , 0 , 0 ) ;
} else if ( V_5 -> V_366 == V_448 ) {
if ( F_196 ( V_153 . V_211 + 8 , V_5 -> V_7 ) == 0 )
F_273 ( V_5 , & V_153 , 0 ) ;
else if ( V_447 )
F_228 ( & V_153 , 64 , V_5 -> V_7 , 0 , 0 ) ;
}
}
static void F_280 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_310 ) &&
( V_7 -> type != V_311 ) &&
( V_7 -> type != V_312 ) &&
( V_7 -> type != V_313 ) &&
( V_7 -> type != V_316 ) &&
( V_7 -> type != V_317 ) &&
( V_7 -> type != V_63 ) &&
( V_7 -> type != V_315 ) ) {
return;
}
V_5 = F_235 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return;
F_279 ( V_5 , false ) ;
}
static void F_281 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 ) {
F_99 ( L_22 , V_47 ) ;
return;
}
if ( V_7 -> V_56 & V_57 ) {
F_279 ( V_5 , false ) ;
return;
}
F_269 ( V_5 ) ;
if ( V_7 -> V_50 & V_338 )
F_233 ( V_7 ) ;
}
static void F_282 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 ) {
F_99 ( L_22 , V_47 ) ;
return;
}
F_279 ( V_5 , true ) ;
}
static int F_283 ( struct V_449 * V_450 , unsigned long V_90 ,
void * V_451 )
{
struct V_6 * V_7 = F_284 ( V_451 ) ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
int V_452 = 0 ;
int V_32 ;
switch ( V_90 ) {
case V_453 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_285 ( F_119 ( V_5 ) ) ;
}
break;
case V_182 :
case V_454 :
if ( V_7 -> V_50 & V_455 )
break;
if ( V_5 && V_5 -> V_39 . V_171 )
break;
if ( V_90 == V_182 ) {
if ( ! F_4 ( V_7 ) ) {
F_43 ( L_23 ,
V_7 -> V_48 ) ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 )
V_5 = F_28 ( V_7 ) ;
if ( ! F_245 ( V_5 ) ) {
V_5 -> V_68 |= V_69 ;
V_452 = 1 ;
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
F_43 ( L_24 ,
V_7 -> V_48 ) ;
V_452 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_54 )
case V_55 :
F_281 ( V_7 ) ;
break;
#endif
#if F_42 ( V_456 )
case V_314 :
F_282 ( V_7 ) ;
break;
#endif
case V_457 :
F_271 ( V_7 ) ;
break;
default:
F_280 ( V_7 ) ;
break;
}
if ( ! F_245 ( V_5 ) ) {
if ( V_452 )
F_286 ( V_5 ) ;
if ( V_5 -> V_39 . V_41 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_287 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
}
V_5 -> V_70 = V_13 ;
F_288 ( V_458 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_289 ( V_7 , 1 ) ;
}
break;
case V_459 :
if ( V_5 && V_7 -> V_33 >= V_34 ) {
F_287 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! F_52 ( V_5 ) )
break;
}
case V_199 :
case V_460 :
F_289 ( V_7 , V_90 != V_199 ) ;
break;
case V_461 :
if ( V_5 ) {
F_290 ( V_5 ) ;
F_3 ( V_5 ) ;
V_32 = F_2 ( V_5 ) ;
if ( V_32 )
return F_285 ( V_32 ) ;
V_32 = F_41 ( V_5 ) ;
if ( V_32 ) {
F_3 ( V_5 ) ;
return F_285 ( V_32 ) ;
}
}
break;
case V_462 :
case V_463 :
F_291 ( V_7 , V_90 ) ;
break;
}
return V_464 ;
}
static void F_291 ( struct V_6 * V_7 , unsigned long V_90 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_90 == V_463 )
F_292 ( V_5 ) ;
else if ( V_90 == V_462 )
F_293 ( V_5 ) ;
}
static int F_289 ( struct V_6 * V_7 , int V_465 )
{
struct V_101 * V_101 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_134 ;
int V_147 , V_16 ;
F_29 () ;
F_294 ( V_101 , V_7 ) ;
F_295 ( & V_44 , V_7 ) ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return - V_169 ;
if ( V_465 ) {
V_5 -> V_76 = 1 ;
F_296 ( V_7 -> V_71 , NULL ) ;
F_290 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_466 ; V_16 ++ ) {
struct V_124 * V_120 = & V_179 [ V_16 ] ;
F_141 ( & V_173 ) ;
V_467:
F_80 (ifa, h, addr_lst) {
if ( V_134 -> V_5 == V_5 ) {
F_143 ( & V_134 -> V_146 ) ;
F_9 ( V_134 ) ;
goto V_467;
}
}
F_142 ( & V_173 ) ;
}
F_144 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_465 )
V_5 -> V_68 &= ~ ( V_468 | V_469 | V_69 ) ;
if ( V_465 && F_7 ( & V_5 -> V_60 ) )
F_100 ( V_5 ) ;
while ( ! F_237 ( & V_5 -> V_59 ) ) {
V_134 = F_297 ( & V_5 -> V_59 ,
struct V_9 , V_181 ) ;
F_145 ( & V_134 -> V_181 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_141 ( & V_134 -> V_36 ) ;
if ( V_134 -> V_197 ) {
F_146 ( V_134 -> V_197 ) ;
V_134 -> V_197 = NULL ;
}
F_142 ( & V_134 -> V_36 ) ;
F_146 ( V_134 ) ;
F_144 ( & V_5 -> V_36 ) ;
}
while ( ! F_237 ( & V_5 -> V_37 ) ) {
V_134 = F_297 ( & V_5 -> V_37 ,
struct V_9 , V_154 ) ;
F_9 ( V_134 ) ;
F_145 ( & V_134 -> V_154 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_141 ( & V_134 -> V_36 ) ;
V_147 = V_134 -> V_147 ;
V_134 -> V_147 = V_148 ;
F_142 ( & V_134 -> V_36 ) ;
if ( V_147 != V_148 ) {
F_298 ( V_198 , V_134 ) ;
F_131 ( V_199 , V_134 ) ;
}
F_146 ( V_134 ) ;
F_144 ( & V_5 -> V_36 ) ;
}
F_148 ( & V_5 -> V_36 ) ;
if ( V_465 ) {
F_299 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_300 ( V_5 ) ;
}
V_5 -> V_70 = V_13 ;
if ( V_465 ) {
F_3 ( V_5 ) ;
F_39 ( & V_44 , V_5 -> V_43 ) ;
F_295 ( & V_44 , V_7 ) ;
F_100 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_319 )
{
struct V_4 * V_5 = (struct V_4 * ) V_319 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_155 V_470 ;
F_126 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 || ! ( V_5 -> V_68 & V_69 ) )
goto V_175;
if ( ! F_301 ( V_5 ) )
goto V_175;
if ( V_5 -> V_68 & V_469 )
goto V_175;
if ( V_5 -> V_471 ++ < V_5 -> V_39 . V_58 ) {
F_128 ( & V_5 -> V_36 ) ;
if ( ! F_180 ( V_7 , & V_470 , V_137 ) )
F_302 ( V_7 , & V_470 ,
& V_75 ) ;
else
goto V_472;
F_126 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_471 ==
V_5 -> V_39 . V_58 ) ?
V_5 -> V_39 . V_473 :
V_5 -> V_39 . V_474 ) ;
} else {
F_99 ( L_25 , V_5 -> V_7 -> V_48 ) ;
}
V_175:
F_128 ( & V_5 -> V_36 ) ;
V_472:
F_100 ( V_5 ) ;
}
static void F_303 ( struct V_9 * V_10 )
{
unsigned long V_475 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_50 & V_223 )
V_475 = 0 ;
else
V_475 = F_304 () % ( V_5 -> V_39 . V_473 ? : 1 ) ;
V_10 -> V_476 = V_5 -> V_39 . V_220 ;
F_16 ( V_10 , V_475 ) ;
}
static void F_305 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_197 ( V_7 , & V_10 -> V_153 ) ;
F_306 ( ( V_396 T_1 ) V_10 -> V_153 . V_293 [ 3 ] ) ;
F_172 ( & V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 == V_148 )
goto V_175;
if ( V_7 -> V_50 & ( V_51 | V_52 ) ||
V_5 -> V_39 . V_53 < 1 ||
! ( V_10 -> V_50 & V_137 ) ||
V_10 -> V_50 & V_477 ) {
V_10 -> V_50 &= ~ ( V_137 | V_223 | V_277 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
F_307 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_68 & V_69 ) ) {
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
F_18 ( V_10 ) ;
F_190 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_50 & V_223 ) {
F_272 ( V_10 -> V_149 ) ;
if ( F_158 ( V_5 ) ) {
F_149 ( V_415 , V_10 ) ;
}
}
F_303 ( V_10 ) ;
V_175:
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
bool V_478 = false ;
F_141 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 != V_148 ) {
V_10 -> V_147 = V_291 ;
V_478 = true ;
}
F_142 ( & V_10 -> V_36 ) ;
if ( V_478 )
F_16 ( V_10 , 0 ) ;
}
static void V_176 ( struct V_479 * V_480 )
{
struct V_9 * V_10 = F_308 ( F_309 ( V_480 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_155 V_481 ;
enum {
V_482 ,
V_483 ,
V_484 ,
} V_186 = V_482 ;
F_250 () ;
F_141 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 == V_291 ) {
V_186 = V_483 ;
V_10 -> V_147 = V_279 ;
} else if ( V_10 -> V_147 == V_294 ) {
V_186 = V_484 ;
V_10 -> V_147 = V_280 ;
}
F_142 ( & V_10 -> V_36 ) ;
if ( V_186 == V_483 ) {
F_305 ( V_10 ) ;
goto V_175;
} else if ( V_186 == V_484 ) {
F_190 ( V_10 , 1 ) ;
goto V_175;
}
if ( ! V_10 -> V_476 && F_191 ( V_10 ) )
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
if ( V_10 -> V_476 == 0 ) {
V_10 -> V_50 &= ~ ( V_137 | V_223 | V_277 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_307 ( V_10 ) ;
goto V_175;
}
V_10 -> V_476 -- ;
F_16 ( V_10 ,
F_154 ( V_10 -> V_5 -> V_43 , V_221 ) ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_198 ( & V_10 -> V_153 , & V_481 ) ;
F_310 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_153 , & V_481 , & V_67 ) ;
V_175:
F_146 ( V_10 ) ;
F_94 () ;
}
static bool F_311 ( struct V_9 * V_10 )
{
struct V_9 * V_485 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_179 (ifpiter, &idev->addr_list, if_list) {
if ( V_485 -> V_159 > V_269 )
break;
if ( V_10 != V_485 && V_485 -> V_159 == V_269 &&
( V_485 -> V_50 & ( V_188 | V_137 |
V_223 | V_277 ) ) ==
V_188 )
return false ;
}
return true ;
}
static void F_307 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_155 V_470 ;
bool V_486 , V_487 ;
F_9 ( V_10 ) ;
F_149 ( V_415 , V_10 ) ;
F_172 ( & V_10 -> V_5 -> V_36 ) ;
V_487 = V_10 -> V_159 == V_269 && F_311 ( V_10 ) ;
V_486 = V_487 &&
F_301 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_58 > 0 &&
( V_7 -> V_50 & V_52 ) == 0 ;
F_177 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_487 )
F_312 ( V_10 -> V_5 ) ;
if ( V_486 ) {
if ( F_180 ( V_7 , & V_470 , V_137 ) )
return;
F_302 ( V_7 , & V_470 , & V_75 ) ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_471 = 1 ;
V_10 -> V_5 -> V_68 |= V_468 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_474 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_286 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_50 & V_137 &&
V_10 -> V_147 == V_279 )
F_303 ( V_10 ) ;
F_125 ( & V_10 -> V_36 ) ;
}
F_177 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_313 ( struct V_488 * V_89 , T_8 V_489 )
{
struct V_9 * V_134 = NULL ;
struct V_490 * V_147 = V_89 -> V_491 ;
struct V_101 * V_101 = F_314 ( V_89 ) ;
int V_142 = 0 ;
if ( V_489 == 0 ) {
V_147 -> V_492 = 0 ;
V_147 -> V_493 = 0 ;
}
for (; V_147 -> V_492 < V_466 ; ++ V_147 -> V_492 ) {
F_189 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_184 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( V_142 < V_147 -> V_493 ) {
V_142 ++ ;
continue;
}
V_147 -> V_493 ++ ;
return V_134 ;
}
V_147 -> V_493 = 0 ;
V_142 = 0 ;
}
return NULL ;
}
static struct V_9 * F_315 ( struct V_488 * V_89 ,
struct V_9 * V_134 )
{
struct V_490 * V_147 = V_89 -> V_491 ;
struct V_101 * V_101 = F_314 ( V_89 ) ;
F_316 (ifa, addr_lst) {
if ( ! F_184 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_493 ++ ;
return V_134 ;
}
while ( ++ V_147 -> V_492 < V_466 ) {
V_147 -> V_493 = 0 ;
F_189 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_184 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_493 ++ ;
return V_134 ;
}
}
return NULL ;
}
static void * F_317 ( struct V_488 * V_89 , T_8 * V_489 )
__acquires( T_9 )
{
F_115 () ;
return F_313 ( V_89 , * V_489 ) ;
}
static void * F_318 ( struct V_488 * V_89 , void * V_494 , T_8 * V_489 )
{
struct V_9 * V_134 ;
V_134 = F_315 ( V_89 , V_494 ) ;
++ * V_489 ;
return V_134 ;
}
static void F_319 ( struct V_488 * V_89 , void * V_494 )
__releases( T_9 )
{
F_129 () ;
}
static int F_320 ( struct V_488 * V_89 , void * V_494 )
{
struct V_9 * V_10 = (struct V_9 * ) V_494 ;
F_321 ( V_89 , L_26 ,
& V_10 -> V_153 ,
V_10 -> V_5 -> V_7 -> V_85 ,
V_10 -> V_177 ,
V_10 -> V_159 ,
( T_3 ) V_10 -> V_50 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
return 0 ;
}
static int F_322 ( struct V_495 * V_495 , struct V_496 * V_496 )
{
return F_323 ( V_495 , V_496 , & V_497 ,
sizeof( struct V_490 ) ) ;
}
static int T_10 F_324 ( struct V_101 * V_101 )
{
if ( ! F_325 ( L_27 , V_498 , V_101 -> V_499 , & V_500 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_326 ( struct V_101 * V_101 )
{
F_327 ( L_27 , V_101 -> V_499 ) ;
}
int T_12 F_328 ( void )
{
return F_329 ( & V_501 ) ;
}
void F_330 ( void )
{
F_331 ( & V_501 ) ;
}
int F_332 ( struct V_101 * V_101 , const struct V_155 * V_153 )
{
int V_208 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_163 = F_110 ( V_153 ) ;
F_115 () ;
F_189 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_184 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( F_162 ( & V_10 -> V_153 , V_153 ) &&
( V_10 -> V_50 & V_247 ) ) {
V_208 = 1 ;
break;
}
}
F_129 () ;
return V_208 ;
}
static void F_262 ( void )
{
unsigned long V_210 , V_502 , V_503 , V_504 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_115 () ;
V_210 = V_13 ;
V_502 = F_333 ( V_210 + V_505 ) ;
F_10 ( & V_506 ) ;
for ( V_16 = 0 ; V_16 < V_466 ; V_16 ++ ) {
V_467:
F_189 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_205 ;
if ( ( V_10 -> V_50 & V_188 ) &&
( V_10 -> V_161 == V_414 ) )
continue;
F_116 ( & V_10 -> V_36 ) ;
V_205 = ( V_210 - V_10 -> V_70 + V_222 ) / V_3 ;
if ( V_10 -> V_160 != V_414 &&
V_205 >= V_10 -> V_160 ) {
F_125 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_140 ( V_10 ) ;
goto V_467;
} else if ( V_10 -> V_161 == V_414 ) {
F_125 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_205 >= V_10 -> V_161 ) {
int V_507 = 0 ;
if ( ! ( V_10 -> V_50 & V_242 ) ) {
V_507 = 1 ;
V_10 -> V_50 |= V_242 ;
}
if ( ( V_10 -> V_160 != V_414 ) &&
( F_135 ( V_10 -> V_70 + V_10 -> V_160 * V_3 , V_502 ) ) )
V_502 = V_10 -> V_70 + V_10 -> V_160 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
if ( V_507 ) {
F_18 ( V_10 ) ;
F_149 ( 0 , V_10 ) ;
F_146 ( V_10 ) ;
goto V_467;
}
} else if ( ( V_10 -> V_50 & V_180 ) &&
! ( V_10 -> V_50 & V_137 ) ) {
unsigned long V_206 = V_10 -> V_5 -> V_39 . V_214 *
V_10 -> V_5 -> V_39 . V_220 *
F_154 ( V_10 -> V_5 -> V_43 , V_221 ) / V_3 ;
if ( V_205 >= V_10 -> V_161 - V_206 ) {
struct V_9 * V_197 = V_10 -> V_197 ;
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_502 ) )
V_502 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
if ( ! V_10 -> V_213 && V_197 ) {
V_10 -> V_213 ++ ;
F_18 ( V_10 ) ;
F_18 ( V_197 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_116 ( & V_197 -> V_36 ) ;
V_197 -> V_213 = 0 ;
F_125 ( & V_197 -> V_36 ) ;
F_151 ( V_197 , V_10 ) ;
F_146 ( V_197 ) ;
F_146 ( V_10 ) ;
goto V_467;
}
} else if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 - V_206 * V_3 , V_502 ) )
V_502 = V_10 -> V_70 + V_10 -> V_161 * V_3 - V_206 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
} else {
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_502 ) )
V_502 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
}
}
}
V_503 = F_333 ( V_502 ) ;
V_504 = V_502 ;
if ( F_135 ( V_503 , V_502 + V_508 ) )
V_504 = V_503 ;
if ( F_135 ( V_504 , V_13 + V_509 ) )
V_504 = V_13 + V_509 ;
F_38 ( V_510 L_28 ,
V_210 , V_502 , V_503 , V_504 ) ;
F_19 ( V_15 , & V_506 , V_504 - V_210 ) ;
F_129 () ;
}
static void F_334 ( struct V_479 * V_480 )
{
F_250 () ;
F_262 () ;
F_94 () ;
}
static void F_247 ( void )
{
F_19 ( V_15 , & V_506 , 0 ) ;
}
static struct V_155 * F_335 ( struct V_109 * V_153 , struct V_109 * V_511 ,
struct V_155 * * V_404 )
{
struct V_155 * V_320 = NULL ;
* V_404 = NULL ;
if ( V_153 )
V_320 = F_336 ( V_153 ) ;
if ( V_511 ) {
if ( V_320 && F_337 ( V_511 , V_320 , sizeof( * V_320 ) ) )
* V_404 = V_320 ;
V_320 = F_336 ( V_511 ) ;
}
return V_320 ;
}
static int
F_338 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_512 * V_513 ;
struct V_109 * V_110 [ V_514 + 1 ] ;
struct V_155 * V_320 , * V_404 ;
T_1 V_405 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_513 ) , V_110 , V_514 , V_515 ) ;
if ( V_32 < 0 )
return V_32 ;
V_513 = F_60 ( V_92 ) ;
V_320 = F_335 ( V_110 [ V_516 ] , V_110 [ V_517 ] , & V_404 ) ;
if ( ! V_320 )
return - V_35 ;
V_405 = V_110 [ V_518 ] ? F_339 ( V_110 [ V_518 ] ) : V_513 -> V_405 ;
V_405 &= V_370 ;
return F_263 ( V_101 , V_513 -> V_519 , V_405 , V_320 ,
V_513 -> V_520 ) ;
}
static int F_340 ( struct V_9 * V_10 , T_1 V_405 ,
T_1 V_161 , T_1 V_160 )
{
T_1 V_50 ;
T_5 V_184 ;
unsigned long V_406 ;
bool V_521 ;
bool V_522 ;
F_29 () ;
if ( ! V_160 || ( V_161 > V_160 ) )
return - V_35 ;
if ( V_405 & V_370 &&
( V_10 -> V_50 & V_180 || V_10 -> V_177 != 64 ) )
return - V_35 ;
V_406 = F_134 ( V_160 , V_3 ) ;
if ( F_242 ( V_406 ) ) {
V_184 = F_244 ( V_406 * V_3 ) ;
V_160 = V_406 ;
V_50 = V_196 ;
} else {
V_184 = 0 ;
V_50 = 0 ;
V_405 |= V_188 ;
}
V_406 = F_134 ( V_161 , V_3 ) ;
if ( F_242 ( V_406 ) ) {
if ( V_406 == 0 )
V_405 |= V_242 ;
V_161 = V_406 ;
}
F_141 ( & V_10 -> V_36 ) ;
V_521 = V_10 -> V_50 & V_370 ;
V_522 = V_10 -> V_50 & V_188 &&
! ( V_10 -> V_50 & V_189 ) ;
V_10 -> V_50 &= ~ ( V_242 | V_188 | V_477 |
V_247 | V_370 |
V_189 ) ;
V_10 -> V_50 |= V_405 ;
V_10 -> V_70 = V_13 ;
V_10 -> V_160 = V_160 ;
V_10 -> V_161 = V_161 ;
F_142 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_137 ) )
F_149 ( 0 , V_10 ) ;
if ( ! ( V_405 & V_189 ) ) {
F_228 ( & V_10 -> V_153 , V_10 -> V_177 , V_10 -> V_5 -> V_7 ,
V_184 , V_50 ) ;
} else if ( V_522 ) {
enum V_183 V_186 ;
unsigned long V_360 ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
V_186 = F_132 ( V_10 , & V_360 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_186 != V_190 ) {
F_136 ( V_10 , V_360 ,
V_186 == V_187 ) ;
}
}
if ( V_521 || V_10 -> V_50 & V_370 ) {
if ( V_521 && ! ( V_10 -> V_50 & V_370 ) )
V_160 = V_161 = 0 ;
F_236 ( V_10 -> V_5 , V_10 , V_160 , V_161 ,
! V_521 , V_13 ) ;
}
F_262 () ;
return 0 ;
}
static int
F_341 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_512 * V_513 ;
struct V_109 * V_110 [ V_514 + 1 ] ;
struct V_155 * V_320 , * V_404 ;
struct V_9 * V_134 ;
struct V_6 * V_7 ;
T_1 V_160 = V_414 , V_284 = V_414 ;
T_1 V_405 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_513 ) , V_110 , V_514 , V_515 ) ;
if ( V_32 < 0 )
return V_32 ;
V_513 = F_60 ( V_92 ) ;
V_320 = F_335 ( V_110 [ V_516 ] , V_110 [ V_517 ] , & V_404 ) ;
if ( ! V_320 )
return - V_35 ;
if ( V_110 [ V_523 ] ) {
struct V_524 * V_525 ;
V_525 = F_336 ( V_110 [ V_523 ] ) ;
V_160 = V_525 -> V_526 ;
V_284 = V_525 -> V_527 ;
} else {
V_284 = V_414 ;
V_160 = V_414 ;
}
V_7 = F_74 ( V_101 , V_513 -> V_519 ) ;
if ( ! V_7 )
return - V_169 ;
V_405 = V_110 [ V_518 ] ? F_339 ( V_110 [ V_518 ] ) : V_513 -> V_405 ;
V_405 &= V_477 | V_247 | V_370 |
V_189 | V_407 ;
V_134 = F_188 ( V_101 , V_320 , V_7 , 1 ) ;
if ( ! V_134 ) {
return F_261 ( V_101 , V_513 -> V_519 , V_320 , V_404 ,
V_513 -> V_520 , V_405 ,
V_284 , V_160 ) ;
}
if ( V_92 -> V_528 & V_529 ||
! ( V_92 -> V_528 & V_530 ) )
V_32 = - V_174 ;
else
V_32 = F_340 ( V_134 , V_405 , V_284 , V_160 ) ;
F_146 ( V_134 ) ;
return V_32 ;
}
static void F_342 ( struct V_91 * V_92 , T_3 V_531 , T_1 V_50 ,
T_3 V_159 , int V_85 )
{
struct V_512 * V_513 ;
V_513 = F_60 ( V_92 ) ;
V_513 -> V_532 = V_96 ;
V_513 -> V_520 = V_531 ;
V_513 -> V_405 = V_50 ;
V_513 -> V_424 = V_159 ;
V_513 -> V_519 = V_85 ;
}
static int F_343 ( struct V_83 * V_84 , unsigned long V_1 ,
unsigned long V_70 , T_1 V_533 , T_1 V_358 )
{
struct V_524 V_525 ;
V_525 . V_1 = F_1 ( V_1 ) ;
V_525 . V_70 = F_1 ( V_70 ) ;
V_525 . V_527 = V_533 ;
V_525 . V_526 = V_358 ;
return F_344 ( V_84 , V_523 , sizeof( V_525 ) , & V_525 ) ;
}
static inline int F_345 ( int V_424 )
{
if ( V_424 & V_273 )
return V_426 ;
else if ( V_424 & V_269 )
return V_425 ;
else if ( V_424 & V_534 )
return V_535 ;
else
return V_536 ;
}
static inline int F_346 ( void )
{
return F_55 ( sizeof( struct V_512 ) )
+ F_56 ( 16 )
+ F_56 ( 16 )
+ F_56 ( sizeof( struct V_524 ) )
+ F_56 ( 4 ) ;
}
static int F_347 ( struct V_83 * V_84 , struct V_9 * V_134 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_1 V_533 , V_358 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_512 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
F_342 ( V_92 , V_134 -> V_177 , V_134 -> V_50 , F_345 ( V_134 -> V_159 ) ,
V_134 -> V_5 -> V_7 -> V_85 ) ;
if ( ! ( ( V_134 -> V_50 & V_188 ) &&
( V_134 -> V_161 == V_414 ) ) ) {
V_533 = V_134 -> V_161 ;
V_358 = V_134 -> V_160 ;
if ( V_533 != V_414 ) {
long V_537 = ( V_13 - V_134 -> V_70 ) / V_3 ;
if ( V_533 > V_537 )
V_533 -= V_537 ;
else
V_533 = 0 ;
if ( V_358 != V_414 ) {
if ( V_358 > V_537 )
V_358 -= V_537 ;
else
V_358 = 0 ;
}
}
} else {
V_533 = V_414 ;
V_358 = V_414 ;
}
if ( ! F_202 ( & V_134 -> V_157 ) ) {
if ( F_348 ( V_84 , V_517 , & V_134 -> V_153 ) < 0 ||
F_348 ( V_84 , V_516 , & V_134 -> V_157 ) < 0 )
goto error;
} else
if ( F_348 ( V_84 , V_516 , & V_134 -> V_153 ) < 0 )
goto error;
if ( F_343 ( V_84 , V_134 -> V_1 , V_134 -> V_70 , V_533 , V_358 ) < 0 )
goto error;
if ( F_349 ( V_84 , V_518 , V_134 -> V_50 ) < 0 )
goto error;
F_62 ( V_84 , V_92 ) ;
return 0 ;
error:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_350 ( struct V_83 * V_84 , struct V_538 * V_539 ,
T_1 V_88 , T_1 V_89 , int V_90 , T_13 V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_536 ;
int V_85 = V_539 -> V_5 -> V_7 -> V_85 ;
if ( F_155 ( & V_539 -> V_540 ) & V_534 )
V_159 = V_535 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_512 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
F_342 ( V_92 , 128 , V_188 , V_159 , V_85 ) ;
if ( F_348 ( V_84 , V_541 , & V_539 -> V_540 ) < 0 ||
F_343 ( V_84 , V_539 -> V_542 , V_539 -> V_543 ,
V_414 , V_414 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
F_62 ( V_84 , V_92 ) ;
return 0 ;
}
static int F_351 ( struct V_83 * V_84 , struct V_544 * V_545 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_536 ;
int V_85 = V_545 -> V_546 -> V_7 -> V_85 ;
if ( F_155 ( & V_545 -> V_547 ) & V_534 )
V_159 = V_535 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_512 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
F_342 ( V_92 , 128 , V_188 , V_159 , V_85 ) ;
if ( F_348 ( V_84 , V_548 , & V_545 -> V_547 ) < 0 ||
F_343 ( V_84 , V_545 -> V_549 , V_545 -> V_550 ,
V_414 , V_414 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
F_62 ( V_84 , V_92 ) ;
return 0 ;
}
static int F_352 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_118 * V_119 , enum V_551 type ,
int V_552 , int * V_553 )
{
struct V_538 * V_539 ;
struct V_544 * V_545 ;
int V_32 = 1 ;
int V_554 = * V_553 ;
F_172 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_555 : {
struct V_9 * V_134 ;
F_86 (ifa, &idev->addr_list, if_list) {
if ( ++ V_554 < V_552 )
continue;
V_32 = F_347 ( V_84 , V_134 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_415 ,
V_131 ) ;
if ( V_32 < 0 )
break;
F_82 ( V_119 , F_83 ( V_84 ) ) ;
}
break;
}
case V_556 :
for ( V_539 = V_5 -> V_557 ; V_539 ;
V_539 = V_539 -> V_502 , V_554 ++ ) {
if ( V_554 < V_552 )
continue;
V_32 = F_350 ( V_84 , V_539 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_558 ,
V_131 ) ;
if ( V_32 < 0 )
break;
}
break;
case V_559 :
for ( V_545 = V_5 -> V_560 ; V_545 ;
V_545 = V_545 -> V_561 , V_554 ++ ) {
if ( V_554 < V_552 )
continue;
V_32 = F_351 ( V_84 , V_545 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_562 ,
V_131 ) ;
if ( V_32 < 0 )
break;
}
break;
default:
break;
}
F_177 ( & V_5 -> V_36 ) ;
* V_553 = V_554 ;
return V_32 ;
}
static int F_353 ( struct V_83 * V_84 , struct V_118 * V_119 ,
enum V_551 type )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
int V_120 , V_121 ;
int V_122 , V_554 ;
int V_123 , V_552 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_124 * V_125 ;
V_121 = V_119 -> args [ 0 ] ;
V_123 = V_122 = V_119 -> args [ 1 ] ;
V_552 = V_554 = V_119 -> args [ 2 ] ;
F_78 () ;
V_119 -> V_89 = F_79 ( & V_101 -> V_18 . V_128 ) ^ V_101 -> V_129 ;
for ( V_120 = V_121 ; V_120 < V_126 ; V_120 ++ , V_123 = 0 ) {
V_122 = 0 ;
V_125 = & V_101 -> V_127 [ V_120 ] ;
F_80 (dev, head, index_hlist) {
if ( V_122 < V_123 )
goto V_130;
if ( V_120 > V_121 || V_122 > V_123 )
V_552 = 0 ;
V_554 = 0 ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_130;
if ( F_352 ( V_5 , V_84 , V_119 , type ,
V_552 , & V_554 ) < 0 )
goto V_132;
V_130:
V_122 ++ ;
}
}
V_132:
F_81 () ;
V_119 -> args [ 0 ] = V_120 ;
V_119 -> args [ 1 ] = V_122 ;
V_119 -> args [ 2 ] = V_554 ;
return V_84 -> V_133 ;
}
static int F_354 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_551 type = V_555 ;
return F_353 ( V_84 , V_119 , type ) ;
}
static int F_355 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_551 type = V_556 ;
return F_353 ( V_84 , V_119 , type ) ;
}
static int F_356 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_551 type = V_559 ;
return F_353 ( V_84 , V_119 , type ) ;
}
static int F_357 ( struct V_83 * V_107 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_107 -> V_108 ) ;
struct V_512 * V_513 ;
struct V_109 * V_110 [ V_514 + 1 ] ;
struct V_155 * V_153 = NULL , * V_563 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_134 ;
struct V_83 * V_84 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_513 ) , V_110 , V_514 , V_515 ) ;
if ( V_32 < 0 )
goto V_104;
V_153 = F_335 ( V_110 [ V_516 ] , V_110 [ V_517 ] , & V_563 ) ;
if ( ! V_153 ) {
V_32 = - V_35 ;
goto V_104;
}
V_513 = F_60 ( V_92 ) ;
if ( V_513 -> V_519 )
V_7 = F_74 ( V_101 , V_513 -> V_519 ) ;
V_134 = F_188 ( V_101 , V_153 , V_7 , 1 ) ;
if ( ! V_134 ) {
V_32 = - V_168 ;
goto V_104;
}
V_84 = F_65 ( F_346 () , V_25 ) ;
if ( ! V_84 ) {
V_32 = - V_102 ;
goto V_564;
}
V_32 = F_347 ( V_84 , V_134 , F_75 ( V_107 ) . V_88 ,
V_92 -> V_117 , V_415 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_564;
}
V_32 = F_76 ( V_84 , V_101 , F_75 ( V_107 ) . V_88 ) ;
V_564:
F_146 ( V_134 ) ;
V_104:
return V_32 ;
}
static void F_358 ( int V_90 , struct V_9 * V_134 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_134 -> V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_346 () , V_103 ) ;
if ( ! V_84 )
goto V_104;
V_32 = F_347 ( V_84 , V_134 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_565 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_565 , V_32 ) ;
}
static inline void F_359 ( struct V_86 * V_39 ,
T_2 * V_566 , int V_567 )
{
F_360 ( V_567 < ( V_568 * 4 ) ) ;
memset ( V_566 , 0 , V_567 ) ;
V_566 [ V_569 ] = V_39 -> V_45 ;
V_566 [ V_570 ] = V_39 -> V_571 ;
V_566 [ V_572 ] = V_39 -> V_41 ;
V_566 [ V_573 ] = V_39 -> V_574 ;
V_566 [ V_575 ] = V_39 -> V_576 ;
V_566 [ V_577 ] = V_39 -> V_364 ;
V_566 [ V_578 ] = V_39 -> V_220 ;
V_566 [ V_579 ] = V_39 -> V_58 ;
V_566 [ V_580 ] =
F_361 ( V_39 -> V_474 ) ;
V_566 [ V_581 ] =
F_361 ( V_39 -> V_473 ) ;
V_566 [ V_582 ] = V_39 -> V_583 ;
V_566 [ V_584 ] =
F_361 ( V_39 -> V_585 ) ;
V_566 [ V_586 ] =
F_361 ( V_39 -> V_587 ) ;
V_566 [ V_588 ] = V_39 -> V_65 ;
V_566 [ V_589 ] = V_39 -> V_217 ;
V_566 [ V_590 ] = V_39 -> V_218 ;
V_566 [ V_591 ] = V_39 -> V_214 ;
V_566 [ V_592 ] = V_39 -> V_219 ;
V_566 [ V_593 ] = V_39 -> V_289 ;
V_566 [ V_594 ] = V_39 -> V_595 ;
V_566 [ V_596 ] = V_39 -> V_597 ;
#ifdef F_362
V_566 [ V_598 ] = V_39 -> V_599 ;
V_566 [ V_600 ] =
F_361 ( V_39 -> V_601 ) ;
#ifdef F_363
V_566 [ V_602 ] = V_39 -> V_603 ;
#endif
#endif
V_566 [ V_604 ] = V_39 -> V_100 ;
V_566 [ V_605 ] = V_39 -> V_606 ;
#ifdef F_159
V_566 [ V_607 ] = V_39 -> V_226 ;
V_566 [ V_608 ] = V_39 -> V_227 ;
#endif
#ifdef F_57
V_566 [ V_609 ] = V_39 -> V_99 ;
#endif
V_566 [ V_610 ] = V_39 -> V_171 ;
V_566 [ V_611 ] = V_39 -> V_53 ;
V_566 [ V_612 ] = V_39 -> V_613 ;
V_566 [ V_614 ] = V_39 -> V_615 ;
V_566 [ V_616 ] = V_39 -> V_617 ;
V_566 [ V_618 ] = V_39 -> V_619 ;
V_566 [ V_620 ] = V_39 -> V_621 ;
}
static inline T_14 F_364 ( void )
{
return F_56 ( 4 )
+ F_56 ( sizeof( struct V_622 ) )
+ F_56 ( V_568 * 4 )
+ F_56 ( V_623 * 8 )
+ F_56 ( V_624 * 8 )
+ F_56 ( sizeof( struct V_155 ) ) ;
}
static inline T_14 F_365 ( void )
{
return F_55 ( sizeof( struct V_625 ) )
+ F_56 ( V_626 )
+ F_56 ( V_442 )
+ F_56 ( 4 )
+ F_56 ( 4 )
+ F_56 ( F_364 () ) ;
}
static inline void F_366 ( T_15 * V_17 , T_16 * V_627 ,
int V_628 , int V_567 )
{
int V_16 ;
int V_629 = V_567 - sizeof( T_15 ) * V_628 ;
F_360 ( V_629 < 0 ) ;
F_367 ( V_628 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_628 ; V_16 ++ )
F_367 ( F_368 ( & V_627 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_628 ] , 0 , V_629 ) ;
}
static inline void F_369 ( T_15 * V_17 , void T_17 * V_627 ,
int V_628 , int V_567 , T_14 V_630 )
{
int V_16 ;
int V_629 = V_567 - sizeof( T_15 ) * V_628 ;
F_360 ( V_629 < 0 ) ;
F_367 ( V_628 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_628 ; V_16 ++ )
F_367 ( F_370 ( V_627 , V_16 , V_630 ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_628 ] , 0 , V_629 ) ;
}
static void F_371 ( T_15 * V_17 , struct V_4 * V_5 , int V_631 ,
int V_567 )
{
switch ( V_631 ) {
case V_632 :
F_369 ( V_17 , V_5 -> V_17 . V_18 ,
V_623 , V_567 , F_372 ( struct V_19 , V_22 ) ) ;
break;
case V_633 :
F_366 ( V_17 , V_5 -> V_17 . V_23 -> V_634 , V_624 , V_567 ) ;
break;
}
}
static int F_373 ( struct V_83 * V_84 , struct V_4 * V_5 )
{
struct V_109 * V_635 ;
struct V_622 V_525 ;
if ( F_349 ( V_84 , V_636 , V_5 -> V_68 ) )
goto V_98;
V_525 . V_637 = V_638 ;
V_525 . V_70 = F_1 ( V_5 -> V_70 ) ;
V_525 . V_639 = F_361 ( V_5 -> V_43 -> V_639 ) ;
V_525 . V_640 = F_361 ( F_154 ( V_5 -> V_43 , V_221 ) ) ;
if ( F_344 ( V_84 , V_641 , sizeof( V_525 ) , & V_525 ) )
goto V_98;
V_635 = F_374 ( V_84 , V_642 , V_568 * sizeof( V_643 ) ) ;
if ( ! V_635 )
goto V_98;
F_359 ( & V_5 -> V_39 , F_336 ( V_635 ) , F_375 ( V_635 ) ) ;
V_635 = F_374 ( V_84 , V_632 , V_623 * sizeof( T_15 ) ) ;
if ( ! V_635 )
goto V_98;
F_371 ( F_336 ( V_635 ) , V_5 , V_632 , F_375 ( V_635 ) ) ;
V_635 = F_374 ( V_84 , V_633 , V_624 * sizeof( T_15 ) ) ;
if ( ! V_635 )
goto V_98;
F_371 ( F_336 ( V_635 ) , V_5 , V_633 , F_375 ( V_635 ) ) ;
V_635 = F_374 ( V_84 , V_644 , sizeof( struct V_155 ) ) ;
if ( ! V_635 )
goto V_98;
if ( F_376 ( V_84 , V_645 , V_5 -> V_366 ) )
goto V_98;
F_172 ( & V_5 -> V_36 ) ;
memcpy ( F_336 ( V_635 ) , V_5 -> V_66 . V_211 , F_375 ( V_635 ) ) ;
F_177 ( & V_5 -> V_36 ) ;
return 0 ;
V_98:
return - V_94 ;
}
static T_14 F_377 ( const struct V_6 * V_7 )
{
if ( ! F_51 ( V_7 ) )
return 0 ;
return F_364 () ;
}
static int F_378 ( struct V_83 * V_84 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return - V_646 ;
if ( F_373 ( V_84 , V_5 ) < 0 )
return - V_94 ;
return 0 ;
}
static int F_379 ( struct V_4 * V_5 , struct V_155 * V_66 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_647 = false ;
struct V_155 V_648 ;
F_29 () ;
if ( ! V_66 )
return - V_35 ;
if ( F_202 ( V_66 ) )
return - V_35 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return - V_35 ;
if ( ! F_301 ( V_5 ) )
return - V_35 ;
if ( V_5 -> V_39 . V_58 <= 0 )
return - V_35 ;
F_144 ( & V_5 -> V_36 ) ;
F_276 ( sizeof( V_66 -> V_211 ) != 16 ) ;
memcpy ( V_5 -> V_66 . V_211 + 8 , V_66 -> V_211 + 8 , 8 ) ;
F_148 ( & V_5 -> V_36 ) ;
if ( ! V_5 -> V_76 && ( V_5 -> V_68 & V_69 ) &&
! F_180 ( V_7 , & V_648 , V_137 |
V_223 ) ) {
F_302 ( V_7 , & V_648 , & V_75 ) ;
V_647 = true ;
}
F_144 ( & V_5 -> V_36 ) ;
if ( V_647 ) {
V_5 -> V_68 |= V_468 ;
V_5 -> V_471 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_474 ) ;
}
F_86 (ifp, &idev->addr_list, if_list) {
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_178 ) {
V_10 -> V_160 = 0 ;
V_10 -> V_161 = 0 ;
}
F_125 ( & V_10 -> V_36 ) ;
}
F_148 ( & V_5 -> V_36 ) ;
F_288 ( V_458 , V_5 ) ;
F_262 () ;
return 0 ;
}
static int F_380 ( const struct V_6 * V_7 ,
const struct V_109 * V_635 )
{
struct V_109 * V_110 [ V_649 + 1 ] ;
if ( V_7 && ! F_51 ( V_7 ) )
return - V_650 ;
return F_381 ( V_110 , V_649 , V_635 , V_651 ) ;
}
static int F_382 ( struct V_6 * V_7 , const struct V_109 * V_635 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
struct V_109 * V_110 [ V_649 + 1 ] ;
if ( ! V_5 )
return - V_650 ;
if ( F_381 ( V_110 , V_649 , V_635 , NULL ) < 0 )
F_383 () ;
if ( V_110 [ V_644 ] ) {
V_32 = F_379 ( V_5 , F_336 ( V_110 [ V_644 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_110 [ V_645 ] ) {
T_3 V_652 = F_384 ( V_110 [ V_645 ] ) ;
if ( V_652 != V_448 &&
V_652 != V_653 &&
V_652 != V_367 )
return - V_35 ;
if ( V_652 == V_367 &&
! V_5 -> V_39 . V_445 . V_446 &&
! F_34 ( V_7 ) -> V_18 . V_40 -> V_445 . V_446 )
return - V_35 ;
V_5 -> V_366 = V_652 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_385 ( struct V_83 * V_84 , struct V_4 * V_5 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_625 * V_654 ;
struct V_91 * V_92 ;
void * V_655 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_654 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
V_654 = F_60 ( V_92 ) ;
V_654 -> V_656 = V_96 ;
V_654 -> V_657 = 0 ;
V_654 -> V_658 = V_7 -> type ;
V_654 -> V_659 = V_7 -> V_85 ;
V_654 -> V_660 = F_386 ( V_7 ) ;
V_654 -> V_661 = 0 ;
if ( F_387 ( V_84 , V_662 , V_7 -> V_48 ) ||
( V_7 -> V_297 &&
F_344 ( V_84 , V_663 , V_7 -> V_297 , V_7 -> V_299 ) ) ||
F_349 ( V_84 , V_664 , V_7 -> V_33 ) ||
( V_7 -> V_85 != F_388 ( V_7 ) &&
F_349 ( V_84 , V_665 , F_388 ( V_7 ) ) ) )
goto V_98;
V_655 = F_389 ( V_84 , V_666 ) ;
if ( ! V_655 )
goto V_98;
if ( F_373 ( V_84 , V_5 ) < 0 )
goto V_98;
F_390 ( V_84 , V_655 ) ;
F_62 ( V_84 , V_92 ) ;
return 0 ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_391 ( struct V_83 * V_84 , struct V_118 * V_119 )
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
if ( F_385 ( V_84 , V_5 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_458 , V_131 ) < 0 )
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
void F_288 ( int V_90 , struct V_4 * V_5 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_365 () , V_103 ) ;
if ( ! V_84 )
goto V_104;
V_32 = F_385 ( V_84 , V_5 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_667 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_667 , V_32 ) ;
}
static inline T_14 F_392 ( void )
{
return F_55 ( sizeof( struct V_668 ) )
+ F_56 ( sizeof( struct V_155 ) )
+ F_56 ( sizeof( struct V_669 ) ) ;
}
static int F_393 ( struct V_83 * V_84 , struct V_4 * V_5 ,
struct V_354 * V_355 , T_1 V_88 , T_1 V_89 ,
int V_90 , unsigned int V_50 )
{
struct V_668 * V_670 ;
struct V_91 * V_92 ;
struct V_669 V_525 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_670 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
V_670 = F_60 ( V_92 ) ;
V_670 -> V_671 = V_96 ;
V_670 -> V_672 = 0 ;
V_670 -> V_673 = 0 ;
V_670 -> V_674 = V_5 -> V_7 -> V_85 ;
V_670 -> V_177 = V_355 -> V_177 ;
V_670 -> V_675 = V_355 -> type ;
V_670 -> V_676 = 0 ;
V_670 -> V_677 = 0 ;
if ( V_355 -> V_274 )
V_670 -> V_677 |= V_678 ;
if ( V_355 -> V_364 )
V_670 -> V_677 |= V_679 ;
if ( F_344 ( V_84 , V_680 , sizeof( V_355 -> V_356 ) , & V_355 -> V_356 ) )
goto V_98;
V_525 . V_681 = F_239 ( V_355 -> V_359 ) ;
V_525 . V_682 = F_239 ( V_355 -> V_358 ) ;
if ( F_344 ( V_84 , V_683 , sizeof( V_525 ) , & V_525 ) )
goto V_98;
F_62 ( V_84 , V_92 ) ;
return 0 ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static void F_248 ( int V_90 , struct V_4 * V_5 ,
struct V_354 * V_355 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_392 () , V_103 ) ;
if ( ! V_84 )
goto V_104;
V_32 = F_393 ( V_84 , V_5 , V_355 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_684 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_684 , V_32 ) ;
}
static void F_298 ( int V_90 , struct V_9 * V_10 )
{
struct V_101 * V_101 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_90 )
F_29 () ;
F_358 ( V_90 ? : V_415 , V_10 ) ;
switch ( V_90 ) {
case V_415 :
if ( ! ( V_10 -> V_149 -> V_685 ) )
F_272 ( V_10 -> V_149 ) ;
if ( V_10 -> V_5 -> V_39 . V_45 )
F_87 ( V_10 ) ;
if ( ! F_202 ( & V_10 -> V_157 ) )
F_228 ( & V_10 -> V_157 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_198 :
if ( V_10 -> V_5 -> V_39 . V_45 )
F_88 ( V_10 ) ;
F_199 ( V_10 -> V_5 , & V_10 -> V_153 ) ;
if ( ! F_202 ( & V_10 -> V_157 ) ) {
struct V_162 * V_149 ;
V_149 = F_137 ( & V_10 -> V_157 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
if ( V_149 && F_138 ( V_149 ) )
F_394 ( & V_149 -> V_231 ) ;
}
F_232 ( & V_10 -> V_149 -> V_231 ) ;
if ( F_138 ( V_10 -> V_149 ) )
F_394 ( & V_10 -> V_149 -> V_231 ) ;
F_395 ( V_101 ) ;
break;
}
F_396 ( & V_101 -> V_18 . V_128 ) ;
}
static void F_149 ( int V_90 , struct V_9 * V_10 )
{
F_115 () ;
if ( F_130 ( V_10 -> V_5 -> V_76 == 0 ) )
F_298 ( V_90 , V_10 ) ;
F_129 () ;
}
static
int F_397 ( struct V_140 * V_686 , int V_687 ,
void T_6 * V_688 , T_14 * V_689 , T_8 * V_690 )
{
int * V_691 = V_686 -> V_319 ;
int V_692 = * V_691 ;
T_8 V_489 = * V_690 ;
struct V_140 V_693 ;
int V_208 ;
V_693 = * V_686 ;
V_693 . V_319 = & V_692 ;
V_208 = F_398 ( & V_693 , V_687 , V_688 , V_689 , V_690 ) ;
if ( V_687 )
V_208 = F_91 ( V_686 , V_691 , V_692 ) ;
if ( V_208 )
* V_690 = V_489 ;
return V_208 ;
}
static
int F_399 ( struct V_140 * V_686 , int V_687 ,
void T_6 * V_688 , T_14 * V_689 , T_8 * V_690 )
{
struct V_4 * V_5 = V_686 -> V_145 ;
int V_694 = V_34 ;
struct V_140 V_693 ;
V_693 = * V_686 ;
V_693 . V_145 = & V_694 ;
V_693 . V_144 = V_5 ? & V_5 -> V_7 -> V_33 : NULL ;
return F_400 ( & V_693 , V_687 , V_688 , V_689 , V_690 ) ;
}
static void F_401 ( struct V_4 * V_5 )
{
struct V_695 V_696 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_402 ( & V_696 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_171 )
F_283 ( NULL , V_199 , & V_696 ) ;
else
F_283 ( NULL , V_182 , & V_696 ) ;
}
static void F_403 ( struct V_101 * V_101 , T_2 V_138 )
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
F_401 ( V_5 ) ;
}
}
F_81 () ;
}
static int F_404 ( struct V_140 * V_141 , int * V_142 , int V_138 )
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
F_403 ( V_101 , V_138 ) ;
} else if ( ( ! V_138 ) ^ ( ! V_143 ) )
F_401 ( (struct V_4 * ) V_141 -> V_145 ) ;
F_94 () ;
return 0 ;
}
static
int F_405 ( struct V_140 * V_686 , int V_687 ,
void T_6 * V_688 , T_14 * V_689 , T_8 * V_690 )
{
int * V_691 = V_686 -> V_319 ;
int V_692 = * V_691 ;
T_8 V_489 = * V_690 ;
struct V_140 V_693 ;
int V_208 ;
V_693 = * V_686 ;
V_693 . V_319 = & V_692 ;
V_208 = F_398 ( & V_693 , V_687 , V_688 , V_689 , V_690 ) ;
if ( V_687 )
V_208 = F_404 ( V_686 , V_691 , V_692 ) ;
if ( V_208 )
* V_690 = V_489 ;
return V_208 ;
}
static
int F_406 ( struct V_140 * V_686 , int V_687 ,
void T_6 * V_688 , T_14 * V_689 , T_8 * V_690 )
{
int * V_691 = V_686 -> V_319 ;
int V_208 ;
int V_143 , V_697 ;
V_143 = * V_691 ;
V_208 = F_398 ( V_686 , V_687 , V_688 , V_689 , V_690 ) ;
V_697 = * V_691 ;
if ( V_687 && V_143 != V_697 ) {
struct V_101 * V_101 = V_686 -> V_144 ;
if ( ! F_92 () )
return F_93 () ;
if ( V_691 == & V_101 -> V_18 . V_40 -> V_100 )
F_64 ( V_101 , V_82 ,
V_116 ,
V_101 -> V_18 . V_40 ) ;
else if ( V_691 == & V_101 -> V_18 . V_115 -> V_100 )
F_64 ( V_101 , V_82 ,
V_114 ,
V_101 -> V_18 . V_115 ) ;
else {
struct V_4 * V_5 = V_686 -> V_145 ;
F_64 ( V_101 , V_82 ,
V_5 -> V_7 -> V_85 ,
& V_5 -> V_39 ) ;
}
F_94 () ;
}
return V_208 ;
}
static int F_407 ( struct V_140 * V_686 , int V_687 ,
void T_6 * V_688 , T_14 * V_689 ,
T_8 * V_690 )
{
int V_32 ;
struct V_155 V_153 ;
char V_698 [ V_699 ] ;
struct V_140 V_693 = * V_686 ;
struct V_101 * V_101 = V_686 -> V_144 ;
struct V_700 * V_440 = V_686 -> V_319 ;
if ( & V_101 -> V_18 . V_115 -> V_445 == V_686 -> V_319 )
return - V_701 ;
V_693 . V_702 = V_699 ;
V_693 . V_319 = V_698 ;
if ( ! F_92 () )
return F_93 () ;
if ( ! V_687 && ! V_440 -> V_446 ) {
V_32 = - V_701 ;
goto V_175;
}
if ( ! V_687 ) {
V_32 = snprintf ( V_698 , sizeof( V_698 ) , L_29 ,
& V_440 -> V_440 ) ;
if ( V_32 >= sizeof( V_698 ) ) {
V_32 = - V_701 ;
goto V_175;
}
}
V_32 = F_408 ( & V_693 , V_687 , V_688 , V_689 , V_690 ) ;
if ( V_32 || ! V_687 )
goto V_175;
if ( F_409 ( V_698 , - 1 , V_153 . V_703 . V_704 , - 1 , NULL ) != 1 ) {
V_32 = - V_701 ;
goto V_175;
}
V_440 -> V_446 = true ;
V_440 -> V_440 = V_153 ;
if ( & V_101 -> V_18 . V_40 -> V_445 == V_686 -> V_319 ) {
struct V_6 * V_7 ;
F_90 (net, dev) {
struct V_4 * V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_366 =
V_367 ;
}
}
} else {
struct V_4 * V_5 = V_686 -> V_145 ;
V_5 -> V_366 = V_367 ;
}
V_175:
F_94 () ;
return V_32 ;
}
static int F_410 ( struct V_101 * V_101 , char * V_705 ,
struct V_4 * V_5 , struct V_86 * V_142 )
{
int V_16 ;
struct V_706 * V_707 ;
char V_708 [ sizeof( L_30 ) + V_626 ] ;
V_707 = F_411 ( & V_709 , sizeof( * V_707 ) , V_25 ) ;
if ( ! V_707 )
goto V_175;
for ( V_16 = 0 ; V_707 -> V_710 [ V_16 ] . V_319 ; V_16 ++ ) {
V_707 -> V_710 [ V_16 ] . V_319 += ( char * ) V_142 - ( char * ) & V_86 ;
V_707 -> V_710 [ V_16 ] . V_145 = V_5 ;
V_707 -> V_710 [ V_16 ] . V_144 = V_101 ;
}
snprintf ( V_708 , sizeof( V_708 ) , L_31 , V_705 ) ;
V_707 -> V_711 = F_412 ( V_101 , V_708 , V_707 -> V_710 ) ;
if ( ! V_707 -> V_711 )
goto free;
V_142 -> V_42 = V_707 ;
return 0 ;
free:
F_26 ( V_707 ) ;
V_175:
return - V_102 ;
}
static void F_413 ( struct V_86 * V_142 )
{
struct V_706 * V_707 ;
if ( ! V_142 -> V_42 )
return;
V_707 = V_142 -> V_42 ;
V_142 -> V_42 = NULL ;
F_414 ( V_707 -> V_711 ) ;
F_26 ( V_707 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_415 ( V_5 -> V_7 -> V_48 ) )
return - V_35 ;
V_32 = F_416 ( V_5 -> V_7 , V_5 -> V_43 ,
& V_712 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_410 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_48 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_417 ( V_5 -> V_43 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_413 ( & V_5 -> V_39 ) ;
F_417 ( V_5 -> V_43 ) ;
}
static int T_10 F_418 ( struct V_101 * V_101 )
{
int V_32 = - V_30 ;
struct V_86 * V_713 , * V_714 ;
V_713 = F_411 ( & V_86 , sizeof( V_86 ) , V_25 ) ;
if ( ! V_713 )
goto V_715;
V_714 = F_411 ( & V_716 , sizeof( V_716 ) , V_25 ) ;
if ( ! V_714 )
goto V_717;
V_714 -> V_364 = V_718 . V_364 ;
V_714 -> V_171 = V_718 . V_171 ;
V_714 -> V_445 . V_446 = false ;
V_713 -> V_445 . V_446 = false ;
V_101 -> V_18 . V_115 = V_713 ;
V_101 -> V_18 . V_40 = V_714 ;
#ifdef F_419
V_32 = F_410 ( V_101 , L_32 , NULL , V_713 ) ;
if ( V_32 < 0 )
goto V_719;
V_32 = F_410 ( V_101 , L_33 , NULL , V_714 ) ;
if ( V_32 < 0 )
goto V_720;
#endif
return 0 ;
#ifdef F_419
V_720:
F_413 ( V_713 ) ;
V_719:
F_26 ( V_714 ) ;
#endif
V_717:
F_26 ( V_713 ) ;
V_715:
return V_32 ;
}
static void T_11 F_420 ( struct V_101 * V_101 )
{
#ifdef F_419
F_413 ( V_101 -> V_18 . V_40 ) ;
F_413 ( V_101 -> V_18 . V_115 ) ;
#endif
F_26 ( V_101 -> V_18 . V_40 ) ;
F_26 ( V_101 -> V_18 . V_115 ) ;
}
int T_12 F_421 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_422 () ;
if ( V_32 < 0 ) {
F_423 ( L_34 ,
V_47 , V_32 ) ;
goto V_175;
}
V_32 = F_329 ( & V_721 ) ;
if ( V_32 < 0 )
goto V_722;
V_15 = F_424 ( L_35 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_723;
}
F_250 () ;
V_5 = F_28 ( V_724 . V_725 ) ;
F_94 () ;
if ( F_52 ( V_5 ) ) {
V_32 = F_119 ( V_5 ) ;
goto V_726;
}
for ( V_16 = 0 ; V_16 < V_466 ; V_16 ++ )
F_425 ( & V_179 [ V_16 ] ) ;
F_426 ( & V_727 ) ;
F_247 () ;
F_427 ( & V_728 ) ;
V_32 = F_428 ( V_729 , V_730 , NULL , F_391 ,
NULL ) ;
if ( V_32 < 0 )
goto V_104;
F_428 ( V_729 , V_415 , F_341 , NULL , NULL ) ;
F_428 ( V_729 , V_198 , F_338 , NULL , NULL ) ;
F_428 ( V_729 , V_731 , F_357 ,
F_354 , NULL ) ;
F_428 ( V_729 , V_558 , NULL ,
F_355 , NULL ) ;
F_428 ( V_729 , V_562 , NULL ,
F_356 , NULL ) ;
F_428 ( V_729 , V_732 , F_70 ,
F_77 , NULL ) ;
F_429 () ;
return 0 ;
V_104:
F_430 ( & V_728 ) ;
F_431 ( & V_727 ) ;
V_726:
F_432 ( V_15 ) ;
V_723:
F_331 ( & V_721 ) ;
V_722:
F_433 () ;
V_175:
return V_32 ;
}
void F_434 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_431 ( & V_727 ) ;
F_331 ( & V_721 ) ;
F_433 () ;
F_250 () ;
F_435 ( & V_728 ) ;
F_90 (&init_net, dev) {
if ( F_51 ( V_7 ) == NULL )
continue;
F_289 ( V_7 , 1 ) ;
}
F_289 ( V_724 . V_725 , 2 ) ;
F_141 ( & V_173 ) ;
for ( V_16 = 0 ; V_16 < V_466 ; V_16 ++ )
F_66 ( ! F_436 ( & V_179 [ V_16 ] ) ) ;
F_142 ( & V_173 ) ;
F_10 ( & V_506 ) ;
F_94 () ;
F_432 ( V_15 ) ;
}
