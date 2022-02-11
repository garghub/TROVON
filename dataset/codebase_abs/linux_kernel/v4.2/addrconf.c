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
V_340 |= V_346 ;
for ( V_149 = V_342 -> V_347 ; V_149 ; V_149 = V_149 -> V_231 . V_348 ) {
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
. V_324 = V_349 ,
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
bool V_350 , unsigned long V_210 )
{
T_1 V_50 ;
struct V_9 * V_200 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ift, &idev->tempaddr_list, tmp_list) {
int V_205 , V_351 , V_352 ;
if ( V_10 != V_200 -> V_197 )
continue;
V_205 = ( V_210 - V_200 -> V_1 ) / V_3 ;
V_351 = V_5 -> V_39 . V_217 - V_205 ;
if ( V_351 < 0 )
V_351 = 0 ;
V_352 = V_5 -> V_39 . V_218 -
V_5 -> V_39 . V_219 - V_205 ;
if ( V_352 < 0 )
V_352 = 0 ;
if ( V_160 > V_351 )
V_160 = V_351 ;
if ( V_161 > V_352 )
V_161 = V_352 ;
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
if ( ( V_350 || F_237 ( & V_5 -> V_59 ) ) &&
V_5 -> V_39 . V_65 > 0 ) {
F_177 ( & V_5 -> V_36 ) ;
F_151 ( V_10 , NULL ) ;
} else {
F_177 ( & V_5 -> V_36 ) ;
}
}
void F_238 ( struct V_6 * V_7 , T_3 * V_353 , int V_133 , bool V_354 )
{
struct V_355 * V_356 ;
V_216 V_160 ;
V_216 V_161 ;
int V_164 ;
T_1 V_209 = 0 ;
struct V_4 * V_112 ;
struct V_101 * V_101 = F_34 ( V_7 ) ;
V_356 = (struct V_355 * ) V_353 ;
if ( V_133 < sizeof( struct V_355 ) ) {
F_38 ( L_18 ) ;
return;
}
V_164 = F_114 ( & V_356 -> V_357 ) ;
if ( V_164 & ( V_166 | V_358 ) )
return;
V_160 = F_239 ( V_356 -> V_359 ) ;
V_161 = F_239 ( V_356 -> V_360 ) ;
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
if ( V_356 -> V_274 ) {
struct V_162 * V_149 ;
unsigned long V_361 ;
if ( V_3 > V_362 )
V_361 = F_134 ( V_160 , V_3 ) ;
else
V_361 = F_134 ( V_160 , V_362 ) ;
if ( F_242 ( V_361 ) )
V_361 *= V_3 ;
V_149 = F_137 ( & V_356 -> V_357 ,
V_356 -> V_177 ,
V_7 ,
V_363 | V_364 ,
V_193 | V_194 ) ;
if ( V_149 ) {
if ( V_160 == 0 ) {
F_138 ( V_149 ) ;
V_149 = NULL ;
} else if ( F_242 ( V_361 ) ) {
F_139 ( V_149 , V_13 + V_361 ) ;
} else {
F_243 ( V_149 ) ;
}
} else if ( V_160 ) {
T_5 V_184 = 0 ;
int V_50 = V_363 | V_364 ;
if ( F_242 ( V_361 ) ) {
V_50 |= V_196 ;
V_184 = F_244 ( V_361 ) ;
}
F_228 ( & V_356 -> V_357 , V_356 -> V_177 ,
V_7 , V_184 , V_50 ) ;
}
F_103 ( V_149 ) ;
}
if ( V_356 -> V_365 && V_112 -> V_39 . V_365 ) {
struct V_9 * V_10 ;
struct V_155 V_153 ;
int V_350 = 0 , V_366 = 0 ;
bool V_178 = false ;
if ( V_356 -> V_177 == 64 ) {
memcpy ( & V_153 , & V_356 -> V_357 , 8 ) ;
if ( ! F_202 ( & V_112 -> V_66 ) ) {
F_172 ( & V_112 -> V_36 ) ;
memcpy ( V_153 . V_211 + 8 ,
V_112 -> V_66 . V_211 + 8 , 8 ) ;
F_177 ( & V_112 -> V_36 ) ;
V_178 = true ;
} else if ( V_112 -> V_367 ==
V_368 &&
! F_194 ( & V_153 , 0 ,
V_112 ) ) {
V_209 |= V_281 ;
goto V_369;
} else if ( F_196 ( V_153 . V_211 + 8 , V_7 ) &&
F_225 ( V_153 . V_211 + 8 , V_112 ) ) {
F_100 ( V_112 ) ;
return;
}
goto V_369;
}
F_174 ( L_21 ,
V_356 -> V_177 ) ;
F_100 ( V_112 ) ;
return;
V_369:
V_10 = F_188 ( V_101 , & V_153 , V_7 , 1 ) ;
if ( ! V_10 && V_160 ) {
int V_289 = V_112 -> V_39 . V_289 ;
#ifdef F_159
if ( V_112 -> V_39 . V_226 &&
! V_101 -> V_18 . V_115 -> V_45 && V_354 )
V_209 = V_223 ;
#endif
if ( ! V_289 ||
F_181 ( V_112 ) < V_289 )
V_10 = F_113 ( V_112 , & V_153 , NULL ,
V_356 -> V_177 ,
V_164 & V_370 ,
V_209 , V_160 ,
V_161 ) ;
if ( F_245 ( V_10 ) ) {
F_100 ( V_112 ) ;
return;
}
V_366 = 0 ;
V_350 = 1 ;
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 |= V_371 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_178 = V_178 ;
F_142 ( & V_10 -> V_36 ) ;
F_156 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_50 ;
unsigned long V_210 ;
T_1 V_372 ;
F_141 ( & V_10 -> V_36 ) ;
V_210 = V_13 ;
if ( V_10 -> V_160 > ( V_210 - V_10 -> V_70 ) / V_3 )
V_372 = V_10 -> V_160 - ( V_210 - V_10 -> V_70 ) / V_3 ;
else
V_372 = 0 ;
if ( ! V_366 && ! V_350 && V_372 ) {
const T_1 V_373 = F_153 ( T_1 ,
V_372 , V_374 ) ;
V_160 = F_246 ( V_160 , V_373 ) ;
V_366 = 1 ;
}
if ( V_366 ) {
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
V_350 , V_210 ) ;
F_146 ( V_10 ) ;
F_247 () ;
}
}
F_248 ( V_375 , V_112 , V_356 ) ;
F_100 ( V_112 ) ;
}
int F_249 ( struct V_101 * V_101 , void T_6 * V_376 )
{
struct V_377 V_378 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_250 () ;
V_32 = - V_379 ;
if ( F_251 ( & V_378 , V_376 , sizeof( struct V_377 ) ) )
goto V_380;
V_7 = F_74 ( V_101 , V_378 . V_381 ) ;
V_32 = - V_169 ;
if ( ! V_7 )
goto V_380;
#if F_42 ( V_54 )
if ( V_7 -> type == V_55 ) {
const struct V_382 * V_383 = V_7 -> V_384 ;
struct V_385 V_386 ;
struct V_387 V_142 ;
V_32 = - V_168 ;
if ( ! ( F_114 ( & V_378 . V_388 ) & V_225 ) )
goto V_380;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_389 . V_258 = V_378 . V_388 . V_293 [ 3 ] ;
V_142 . V_389 . V_259 = 0 ;
V_142 . V_389 . V_390 = 4 ;
V_142 . V_389 . V_391 = 5 ;
V_142 . V_389 . V_392 = V_393 ;
V_142 . V_389 . V_394 = 64 ;
V_386 . V_395 . V_396 = ( V_397 void T_6 * ) & V_142 ;
if ( V_383 -> V_398 ) {
T_7 V_399 = F_252 () ;
F_253 ( V_400 ) ;
V_32 = V_383 -> V_398 ( V_7 , & V_386 , V_401 ) ;
F_253 ( V_399 ) ;
} else
V_32 = - V_402 ;
if ( V_32 == 0 ) {
V_32 = - V_102 ;
V_7 = F_254 ( V_101 , V_142 . V_48 ) ;
if ( ! V_7 )
goto V_380;
V_32 = F_255 ( V_7 ) ;
}
}
#endif
V_380:
F_94 () ;
return V_32 ;
}
static int F_256 ( struct V_403 * V_108 , bool V_404 ,
const struct V_155 * V_153 , int V_85 )
{
int V_208 ;
F_29 () ;
F_257 ( V_108 ) ;
if ( V_404 )
V_208 = F_258 ( V_108 , V_85 , V_153 ) ;
else
V_208 = F_259 ( V_108 , V_85 , V_153 ) ;
F_260 ( V_108 ) ;
return V_208 ;
}
static int F_261 ( struct V_101 * V_101 , int V_85 ,
const struct V_155 * V_320 ,
const struct V_155 * V_405 ,
unsigned int V_321 , V_216 V_406 ,
V_216 V_161 , V_216 V_160 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_407 ;
T_5 V_184 ;
int V_159 ;
T_1 V_50 ;
F_29 () ;
if ( V_321 > 128 )
return - V_35 ;
if ( ! V_160 || V_161 > V_160 )
return - V_35 ;
if ( V_406 & V_371 && V_321 != 64 )
return - V_35 ;
V_7 = F_74 ( V_101 , V_85 ) ;
if ( ! V_7 )
return - V_169 ;
V_5 = F_235 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_119 ( V_5 ) ;
if ( V_406 & V_408 ) {
int V_208 = F_256 ( V_101 -> V_18 . V_409 ,
true , V_320 , V_85 ) ;
if ( V_208 < 0 )
return V_208 ;
}
V_159 = F_155 ( V_320 ) ;
V_407 = F_134 ( V_160 , V_3 ) ;
if ( F_242 ( V_407 ) ) {
V_184 = F_244 ( V_407 * V_3 ) ;
V_160 = V_407 ;
V_50 = V_196 ;
} else {
V_184 = 0 ;
V_50 = 0 ;
V_406 |= V_188 ;
}
V_407 = F_134 ( V_161 , V_3 ) ;
if ( F_242 ( V_407 ) ) {
if ( V_407 == 0 )
V_406 |= V_242 ;
V_161 = V_407 ;
}
V_10 = F_113 ( V_5 , V_320 , V_405 , V_321 , V_159 , V_406 ,
V_160 , V_161 ) ;
if ( ! F_52 ( V_10 ) ) {
if ( ! ( V_406 & V_189 ) ) {
F_228 ( & V_10 -> V_153 , V_10 -> V_177 , V_7 ,
V_184 , V_50 ) ;
}
F_156 ( V_10 ) ;
if ( V_406 & V_371 )
F_236 ( V_5 , V_10 , V_160 , V_161 ,
true , V_13 ) ;
F_146 ( V_10 ) ;
F_262 () ;
return 0 ;
} else if ( V_406 & V_408 ) {
F_256 ( V_101 -> V_18 . V_409 ,
false , V_320 , V_85 ) ;
}
return F_119 ( V_10 ) ;
}
static int F_263 ( struct V_101 * V_101 , int V_85 , T_1 V_406 ,
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
return - V_410 ;
F_172 ( & V_5 -> V_36 ) ;
F_86 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_177 == V_321 &&
F_162 ( V_320 , & V_10 -> V_153 ) ) {
F_18 ( V_10 ) ;
F_177 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_180 ) &&
( V_406 & V_371 ) )
F_236 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_140 ( V_10 ) ;
F_262 () ;
if ( F_264 ( V_320 ) ) {
F_256 ( V_101 -> V_18 . V_409 ,
false , V_320 , V_7 -> V_85 ) ;
}
return 0 ;
}
}
F_177 ( & V_5 -> V_36 ) ;
return - V_168 ;
}
int F_265 ( struct V_101 * V_101 , void T_6 * V_376 )
{
struct V_377 V_378 ;
int V_32 ;
if ( ! F_266 ( V_101 -> V_411 , V_412 ) )
return - V_413 ;
if ( F_251 ( & V_378 , V_376 , sizeof( struct V_377 ) ) )
return - V_379 ;
F_250 () ;
V_32 = F_261 ( V_101 , V_378 . V_381 , & V_378 . V_388 , NULL ,
V_378 . V_414 , V_188 ,
V_415 , V_415 ) ;
F_94 () ;
return V_32 ;
}
int F_267 ( struct V_101 * V_101 , void T_6 * V_376 )
{
struct V_377 V_378 ;
int V_32 ;
if ( ! F_266 ( V_101 -> V_411 , V_412 ) )
return - V_413 ;
if ( F_251 ( & V_378 , V_376 , sizeof( struct V_377 ) ) )
return - V_379 ;
F_250 () ;
V_32 = F_263 ( V_101 , V_378 . V_381 , 0 , & V_378 . V_388 ,
V_378 . V_414 ) ;
F_94 () ;
return V_32 ;
}
static void F_268 ( struct V_4 * V_5 , const struct V_155 * V_153 ,
int V_321 , int V_159 )
{
struct V_9 * V_10 ;
V_10 = F_113 ( V_5 , V_153 , NULL , V_321 ,
V_159 , V_188 ,
V_415 , V_415 ) ;
if ( ! F_52 ( V_10 ) ) {
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 &= ~ V_137 ;
F_142 ( & V_10 -> V_36 ) ;
F_149 ( V_416 , V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_269 ( struct V_4 * V_5 )
{
struct V_155 V_153 ;
struct V_6 * V_7 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_159 , V_321 ;
T_1 V_417 = 0 ;
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
V_417 |= V_339 ;
}
if ( V_153 . V_293 [ 3 ] ) {
F_268 ( V_5 , & V_153 , V_321 , V_159 ) ;
F_228 ( & V_153 , V_321 , V_5 -> V_7 , 0 , V_417 ) ;
return;
}
F_90 (net, dev) {
struct V_418 * V_419 = F_270 ( V_7 ) ;
if ( V_419 && ( V_7 -> V_50 & V_77 ) ) {
struct V_420 * V_134 ;
int V_421 = V_159 ;
for ( V_134 = V_419 -> V_422 ; V_134 ; V_134 = V_134 -> V_423 ) {
V_153 . V_293 [ 3 ] = V_134 -> V_424 ;
if ( V_134 -> V_425 == V_426 )
continue;
if ( V_134 -> V_425 >= V_427 ) {
if ( V_5 -> V_7 -> V_50 & V_338 )
continue;
V_421 |= V_273 ;
}
F_268 ( V_5 , & V_153 , V_321 , V_421 ) ;
F_228 ( & V_153 , V_321 , V_5 -> V_7 , 0 ,
V_417 ) ;
}
}
}
}
static void F_271 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_428 ;
struct V_9 * V_429 ;
struct V_162 * V_430 ;
F_29 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 ) {
F_99 ( L_22 , V_47 ) ;
return;
}
F_268 ( V_5 , & V_431 , 128 , V_273 ) ;
F_90 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_428 -> V_48 , V_7 -> V_48 ) )
continue;
V_5 = F_51 ( V_428 ) ;
if ( ! V_5 )
continue;
F_172 ( & V_5 -> V_36 ) ;
F_86 (sp_ifa, &idev->addr_list, if_list) {
if ( V_429 -> V_50 & ( V_277 | V_137 ) )
continue;
if ( V_429 -> V_149 ) {
if ( V_429 -> V_149 -> V_231 . V_432 > 0 ) {
F_103 ( V_429 -> V_149 ) ;
V_429 -> V_149 = NULL ;
} else {
continue;
}
}
V_430 = F_118 ( V_5 , & V_429 -> V_153 , false ) ;
if ( ! F_52 ( V_430 ) ) {
V_429 -> V_149 = V_430 ;
F_272 ( V_430 ) ;
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
V_415 , V_415 ) ;
if ( ! F_52 ( V_10 ) ) {
F_228 ( & V_10 -> V_153 , V_10 -> V_177 , V_5 -> V_7 , 0 , 0 ) ;
F_156 ( V_10 ) ;
F_146 ( V_10 ) ;
}
}
static bool F_274 ( struct V_155 V_433 )
{
if ( ( V_433 . V_293 [ 2 ] | V_433 . V_293 [ 3 ] ) == 0 )
return true ;
if ( V_433 . V_293 [ 2 ] == F_195 ( 0x02005eff ) &&
( ( V_433 . V_293 [ 3 ] & F_195 ( 0xfe000000 ) ) == F_195 ( 0xfe000000 ) ) )
return true ;
if ( V_433 . V_293 [ 2 ] == F_195 ( 0xfdffffff ) &&
( ( V_433 . V_293 [ 3 ] & F_195 ( 0xffffff80 ) ) == F_195 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_194 ( struct V_155 * V_433 ,
T_3 V_434 ,
const struct V_4 * V_5 )
{
static F_275 ( V_36 ) ;
static V_216 V_435 [ V_436 ] ;
static V_216 V_437 [ V_438 ] ;
static union {
char V_439 [ V_440 ] ;
struct {
struct V_155 V_441 ;
T_4 V_357 [ 2 ] ;
unsigned char V_442 [ V_443 ] ;
T_3 V_434 ;
} V_444 ;
} V_319 ;
struct V_155 V_441 ;
struct V_155 V_445 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
F_276 ( sizeof( V_319 . V_439 ) != sizeof( V_319 ) ) ;
if ( V_5 -> V_39 . V_446 . V_447 )
V_441 = V_5 -> V_39 . V_446 . V_441 ;
else if ( V_101 -> V_18 . V_40 -> V_446 . V_447 )
V_441 = V_101 -> V_18 . V_40 -> V_446 . V_441 ;
else
return - 1 ;
V_212:
F_141 ( & V_36 ) ;
F_277 ( V_435 ) ;
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
memset ( V_437 , 0 , sizeof( V_437 ) ) ;
memcpy ( V_319 . V_442 , V_5 -> V_7 -> V_309 , V_5 -> V_7 -> V_297 ) ;
V_319 . V_357 [ 0 ] = V_433 -> V_293 [ 0 ] ;
V_319 . V_357 [ 1 ] = V_433 -> V_293 [ 1 ] ;
V_319 . V_441 = V_441 ;
V_319 . V_434 = V_434 ;
F_278 ( V_435 , V_319 . V_439 , V_437 ) ;
V_445 = * V_433 ;
V_445 . V_293 [ 2 ] = ( V_397 T_4 ) V_435 [ 0 ] ;
V_445 . V_293 [ 3 ] = ( V_397 T_4 ) V_435 [ 1 ] ;
F_142 ( & V_36 ) ;
if ( F_274 ( V_445 ) ) {
V_434 ++ ;
if ( V_434 > F_34 ( V_5 -> V_7 ) -> V_18 . V_42 . V_287 )
return - 1 ;
goto V_212;
}
* V_433 = V_445 ;
return 0 ;
}
static void F_279 ( struct V_4 * V_5 , bool V_448 )
{
struct V_155 V_153 ;
F_234 ( & V_153 , F_195 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( V_5 -> V_367 == V_368 ) {
if ( ! F_194 ( & V_153 , 0 , V_5 ) )
F_273 ( V_5 , & V_153 ,
V_281 ) ;
else if ( V_448 )
F_228 ( & V_153 , 64 , V_5 -> V_7 , 0 , 0 ) ;
} else if ( V_5 -> V_367 == V_449 ) {
if ( F_196 ( V_153 . V_211 + 8 , V_5 -> V_7 ) == 0 )
F_273 ( V_5 , & V_153 , 0 ) ;
else if ( V_448 )
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
static int F_283 ( struct V_450 * V_451 , unsigned long V_90 ,
void * V_452 )
{
struct V_6 * V_7 = F_284 ( V_452 ) ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
int V_453 = 0 ;
int V_32 ;
switch ( V_90 ) {
case V_454 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_52 ( V_5 ) )
return F_285 ( F_119 ( V_5 ) ) ;
}
break;
case V_182 :
case V_455 :
if ( V_7 -> V_50 & V_456 )
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
V_453 = 1 ;
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
V_453 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_54 )
case V_55 :
F_281 ( V_7 ) ;
break;
#endif
#if F_42 ( V_457 )
case V_314 :
F_282 ( V_7 ) ;
break;
#endif
case V_458 :
F_271 ( V_7 ) ;
break;
default:
F_280 ( V_7 ) ;
break;
}
if ( ! F_245 ( V_5 ) ) {
if ( V_453 )
F_286 ( V_5 ) ;
if ( V_5 -> V_39 . V_41 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_287 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_33 ;
}
V_5 -> V_70 = V_13 ;
F_288 ( V_459 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_289 ( V_7 , 1 ) ;
}
break;
case V_460 :
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
case V_461 :
F_289 ( V_7 , V_90 != V_199 ) ;
break;
case V_462 :
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
case V_463 :
case V_464 :
F_291 ( V_7 , V_90 ) ;
break;
}
return V_465 ;
}
static void F_291 ( struct V_6 * V_7 , unsigned long V_90 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( V_90 == V_464 )
F_292 ( V_5 ) ;
else if ( V_90 == V_463 )
F_293 ( V_5 ) ;
}
static int F_289 ( struct V_6 * V_7 , int V_466 )
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
if ( V_466 ) {
V_5 -> V_76 = 1 ;
F_296 ( V_7 -> V_71 , NULL ) ;
F_290 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_467 ; V_16 ++ ) {
struct V_124 * V_120 = & V_179 [ V_16 ] ;
F_141 ( & V_173 ) ;
V_468:
F_80 (ifa, h, addr_lst) {
if ( V_134 -> V_5 == V_5 ) {
F_143 ( & V_134 -> V_146 ) ;
F_9 ( V_134 ) ;
goto V_468;
}
}
F_142 ( & V_173 ) ;
}
F_144 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_466 )
V_5 -> V_68 &= ~ ( V_469 | V_470 | V_69 ) ;
if ( V_466 && F_7 ( & V_5 -> V_60 ) )
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
if ( V_466 ) {
F_299 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_300 ( V_5 ) ;
}
V_5 -> V_70 = V_13 ;
if ( V_466 ) {
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
struct V_155 V_471 ;
F_126 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_76 || ! ( V_5 -> V_68 & V_69 ) )
goto V_175;
if ( ! F_301 ( V_5 ) )
goto V_175;
if ( V_5 -> V_68 & V_470 )
goto V_175;
if ( V_5 -> V_472 ++ < V_5 -> V_39 . V_58 ) {
F_128 ( & V_5 -> V_36 ) ;
if ( ! F_180 ( V_7 , & V_471 , V_137 ) )
F_302 ( V_7 , & V_471 ,
& V_75 ) ;
else
goto V_473;
F_126 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_472 ==
V_5 -> V_39 . V_58 ) ?
V_5 -> V_39 . V_474 :
V_5 -> V_39 . V_475 ) ;
} else {
F_99 ( L_25 , V_5 -> V_7 -> V_48 ) ;
}
V_175:
F_128 ( & V_5 -> V_36 ) ;
V_473:
F_100 ( V_5 ) ;
}
static void F_303 ( struct V_9 * V_10 )
{
unsigned long V_476 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_50 & V_223 )
V_476 = 0 ;
else
V_476 = F_304 () % ( V_5 -> V_39 . V_474 ? : 1 ) ;
V_10 -> V_477 = V_5 -> V_39 . V_220 ;
F_16 ( V_10 , V_476 ) ;
}
static void F_305 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_197 ( V_7 , & V_10 -> V_153 ) ;
F_306 ( ( V_397 T_1 ) V_10 -> V_153 . V_293 [ 3 ] ) ;
F_172 ( & V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 == V_148 )
goto V_175;
if ( V_7 -> V_50 & ( V_51 | V_52 ) ||
V_5 -> V_39 . V_53 < 1 ||
! ( V_10 -> V_50 & V_137 ) ||
V_10 -> V_50 & V_478 ) {
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
F_149 ( V_416 , V_10 ) ;
}
}
F_303 ( V_10 ) ;
V_175:
F_125 ( & V_10 -> V_36 ) ;
F_177 ( & V_5 -> V_36 ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
bool V_479 = false ;
F_141 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 != V_148 ) {
V_10 -> V_147 = V_291 ;
V_479 = true ;
}
F_142 ( & V_10 -> V_36 ) ;
if ( V_479 )
F_16 ( V_10 , 0 ) ;
}
static void V_176 ( struct V_480 * V_481 )
{
struct V_9 * V_10 = F_308 ( F_309 ( V_481 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_155 V_482 ;
enum {
V_483 ,
V_484 ,
V_485 ,
} V_186 = V_483 ;
F_250 () ;
F_141 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_147 == V_291 ) {
V_186 = V_484 ;
V_10 -> V_147 = V_279 ;
} else if ( V_10 -> V_147 == V_294 ) {
V_186 = V_485 ;
V_10 -> V_147 = V_280 ;
}
F_142 ( & V_10 -> V_36 ) ;
if ( V_186 == V_484 ) {
F_305 ( V_10 ) ;
goto V_175;
} else if ( V_186 == V_485 ) {
F_190 ( V_10 , 1 ) ;
goto V_175;
}
if ( ! V_10 -> V_477 && F_191 ( V_10 ) )
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
if ( V_10 -> V_477 == 0 ) {
V_10 -> V_50 &= ~ ( V_137 | V_223 | V_277 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_307 ( V_10 ) ;
goto V_175;
}
V_10 -> V_477 -- ;
F_16 ( V_10 ,
F_154 ( V_10 -> V_5 -> V_43 , V_221 ) ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_198 ( & V_10 -> V_153 , & V_482 ) ;
F_310 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_153 , & V_482 , & V_67 ) ;
V_175:
F_146 ( V_10 ) ;
F_94 () ;
}
static bool F_311 ( struct V_9 * V_10 )
{
struct V_9 * V_486 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_179 (ifpiter, &idev->addr_list, if_list) {
if ( V_486 -> V_159 > V_269 )
break;
if ( V_10 != V_486 && V_486 -> V_159 == V_269 &&
( V_486 -> V_50 & ( V_188 | V_137 |
V_223 | V_277 ) ) ==
V_188 )
return false ;
}
return true ;
}
static void F_307 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_155 V_471 ;
bool V_487 , V_488 ;
F_9 ( V_10 ) ;
F_149 ( V_416 , V_10 ) ;
F_172 ( & V_10 -> V_5 -> V_36 ) ;
V_488 = V_10 -> V_159 == V_269 && F_311 ( V_10 ) ;
V_487 = V_488 &&
F_301 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_58 > 0 &&
( V_7 -> V_50 & V_52 ) == 0 ;
F_177 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_488 )
F_312 ( V_10 -> V_5 ) ;
if ( V_487 ) {
if ( F_180 ( V_7 , & V_471 , V_137 ) )
return;
F_302 ( V_7 , & V_471 , & V_75 ) ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
F_116 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_472 = 1 ;
V_10 -> V_5 -> V_68 |= V_469 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_475 ) ;
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
static struct V_9 * F_313 ( struct V_489 * V_89 , T_8 V_490 )
{
struct V_9 * V_134 = NULL ;
struct V_491 * V_147 = V_89 -> V_492 ;
struct V_101 * V_101 = F_314 ( V_89 ) ;
int V_142 = 0 ;
if ( V_490 == 0 ) {
V_147 -> V_493 = 0 ;
V_147 -> V_494 = 0 ;
}
for (; V_147 -> V_493 < V_467 ; ++ V_147 -> V_493 ) {
F_189 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_184 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
if ( V_142 < V_147 -> V_494 ) {
V_142 ++ ;
continue;
}
V_147 -> V_494 ++ ;
return V_134 ;
}
V_147 -> V_494 = 0 ;
V_142 = 0 ;
}
return NULL ;
}
static struct V_9 * F_315 ( struct V_489 * V_89 ,
struct V_9 * V_134 )
{
struct V_491 * V_147 = V_89 -> V_492 ;
struct V_101 * V_101 = F_314 ( V_89 ) ;
F_316 (ifa, addr_lst) {
if ( ! F_184 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_494 ++ ;
return V_134 ;
}
while ( ++ V_147 -> V_493 < V_467 ) {
V_147 -> V_494 = 0 ;
F_189 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_184 ( F_34 ( V_134 -> V_5 -> V_7 ) , V_101 ) )
continue;
V_147 -> V_494 ++ ;
return V_134 ;
}
}
return NULL ;
}
static void * F_317 ( struct V_489 * V_89 , T_8 * V_490 )
__acquires( T_9 )
{
F_115 () ;
return F_313 ( V_89 , * V_490 ) ;
}
static void * F_318 ( struct V_489 * V_89 , void * V_495 , T_8 * V_490 )
{
struct V_9 * V_134 ;
V_134 = F_315 ( V_89 , V_495 ) ;
++ * V_490 ;
return V_134 ;
}
static void F_319 ( struct V_489 * V_89 , void * V_495 )
__releases( T_9 )
{
F_129 () ;
}
static int F_320 ( struct V_489 * V_89 , void * V_495 )
{
struct V_9 * V_10 = (struct V_9 * ) V_495 ;
F_321 ( V_89 , L_26 ,
& V_10 -> V_153 ,
V_10 -> V_5 -> V_7 -> V_85 ,
V_10 -> V_177 ,
V_10 -> V_159 ,
( T_3 ) V_10 -> V_50 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
return 0 ;
}
static int F_322 ( struct V_496 * V_496 , struct V_497 * V_497 )
{
return F_323 ( V_496 , V_497 , & V_498 ,
sizeof( struct V_491 ) ) ;
}
static int T_10 F_324 ( struct V_101 * V_101 )
{
if ( ! F_325 ( L_27 , V_499 , V_101 -> V_500 , & V_501 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_326 ( struct V_101 * V_101 )
{
F_327 ( L_27 , V_101 -> V_500 ) ;
}
int T_12 F_328 ( void )
{
return F_329 ( & V_502 ) ;
}
void F_330 ( void )
{
F_331 ( & V_502 ) ;
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
unsigned long V_210 , V_503 , V_504 , V_505 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_115 () ;
V_210 = V_13 ;
V_503 = F_333 ( V_210 + V_506 ) ;
F_10 ( & V_507 ) ;
for ( V_16 = 0 ; V_16 < V_467 ; V_16 ++ ) {
V_468:
F_189 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_205 ;
if ( ( V_10 -> V_50 & V_188 ) &&
( V_10 -> V_161 == V_415 ) )
continue;
F_116 ( & V_10 -> V_36 ) ;
V_205 = ( V_210 - V_10 -> V_70 + V_222 ) / V_3 ;
if ( V_10 -> V_160 != V_415 &&
V_205 >= V_10 -> V_160 ) {
F_125 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_140 ( V_10 ) ;
goto V_468;
} else if ( V_10 -> V_161 == V_415 ) {
F_125 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_205 >= V_10 -> V_161 ) {
int V_508 = 0 ;
if ( ! ( V_10 -> V_50 & V_242 ) ) {
V_508 = 1 ;
V_10 -> V_50 |= V_242 ;
}
if ( ( V_10 -> V_160 != V_415 ) &&
( F_135 ( V_10 -> V_70 + V_10 -> V_160 * V_3 , V_503 ) ) )
V_503 = V_10 -> V_70 + V_10 -> V_160 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
if ( V_508 ) {
F_18 ( V_10 ) ;
F_149 ( 0 , V_10 ) ;
F_146 ( V_10 ) ;
goto V_468;
}
} else if ( ( V_10 -> V_50 & V_180 ) &&
! ( V_10 -> V_50 & V_137 ) ) {
unsigned long V_206 = V_10 -> V_5 -> V_39 . V_214 *
V_10 -> V_5 -> V_39 . V_220 *
F_154 ( V_10 -> V_5 -> V_43 , V_221 ) / V_3 ;
if ( V_205 >= V_10 -> V_161 - V_206 ) {
struct V_9 * V_197 = V_10 -> V_197 ;
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_503 ) )
V_503 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
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
goto V_468;
}
} else if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 - V_206 * V_3 , V_503 ) )
V_503 = V_10 -> V_70 + V_10 -> V_161 * V_3 - V_206 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
} else {
if ( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_503 ) )
V_503 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
}
}
}
V_504 = F_333 ( V_503 ) ;
V_505 = V_503 ;
if ( F_135 ( V_504 , V_503 + V_509 ) )
V_505 = V_504 ;
if ( F_135 ( V_505 , V_13 + V_510 ) )
V_505 = V_13 + V_510 ;
F_38 ( V_511 L_28 ,
V_210 , V_503 , V_504 , V_505 ) ;
F_19 ( V_15 , & V_507 , V_505 - V_210 ) ;
F_129 () ;
}
static void F_334 ( struct V_480 * V_481 )
{
F_250 () ;
F_262 () ;
F_94 () ;
}
static void F_247 ( void )
{
F_19 ( V_15 , & V_507 , 0 ) ;
}
static struct V_155 * F_335 ( struct V_109 * V_153 , struct V_109 * V_512 ,
struct V_155 * * V_405 )
{
struct V_155 * V_320 = NULL ;
* V_405 = NULL ;
if ( V_153 )
V_320 = F_336 ( V_153 ) ;
if ( V_512 ) {
if ( V_320 && F_337 ( V_512 , V_320 , sizeof( * V_320 ) ) )
* V_405 = V_320 ;
V_320 = F_336 ( V_512 ) ;
}
return V_320 ;
}
static int
F_338 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_513 * V_514 ;
struct V_109 * V_110 [ V_515 + 1 ] ;
struct V_155 * V_320 , * V_405 ;
T_1 V_406 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_514 ) , V_110 , V_515 , V_516 ) ;
if ( V_32 < 0 )
return V_32 ;
V_514 = F_60 ( V_92 ) ;
V_320 = F_335 ( V_110 [ V_517 ] , V_110 [ V_518 ] , & V_405 ) ;
if ( ! V_320 )
return - V_35 ;
V_406 = V_110 [ V_519 ] ? F_339 ( V_110 [ V_519 ] ) : V_514 -> V_406 ;
V_406 &= V_371 ;
return F_263 ( V_101 , V_514 -> V_520 , V_406 , V_320 ,
V_514 -> V_521 ) ;
}
static int F_340 ( struct V_9 * V_10 , T_1 V_406 ,
T_1 V_161 , T_1 V_160 )
{
T_1 V_50 ;
T_5 V_184 ;
unsigned long V_407 ;
bool V_522 ;
bool V_523 ;
F_29 () ;
if ( ! V_160 || ( V_161 > V_160 ) )
return - V_35 ;
if ( V_406 & V_371 &&
( V_10 -> V_50 & V_180 || V_10 -> V_177 != 64 ) )
return - V_35 ;
V_407 = F_134 ( V_160 , V_3 ) ;
if ( F_242 ( V_407 ) ) {
V_184 = F_244 ( V_407 * V_3 ) ;
V_160 = V_407 ;
V_50 = V_196 ;
} else {
V_184 = 0 ;
V_50 = 0 ;
V_406 |= V_188 ;
}
V_407 = F_134 ( V_161 , V_3 ) ;
if ( F_242 ( V_407 ) ) {
if ( V_407 == 0 )
V_406 |= V_242 ;
V_161 = V_407 ;
}
F_141 ( & V_10 -> V_36 ) ;
V_522 = V_10 -> V_50 & V_371 ;
V_523 = V_10 -> V_50 & V_188 &&
! ( V_10 -> V_50 & V_189 ) ;
V_10 -> V_50 &= ~ ( V_242 | V_188 | V_478 |
V_247 | V_371 |
V_189 ) ;
V_10 -> V_50 |= V_406 ;
V_10 -> V_70 = V_13 ;
V_10 -> V_160 = V_160 ;
V_10 -> V_161 = V_161 ;
F_142 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_137 ) )
F_149 ( 0 , V_10 ) ;
if ( ! ( V_406 & V_189 ) ) {
F_228 ( & V_10 -> V_153 , V_10 -> V_177 , V_10 -> V_5 -> V_7 ,
V_184 , V_50 ) ;
} else if ( V_523 ) {
enum V_183 V_186 ;
unsigned long V_361 ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
V_186 = F_132 ( V_10 , & V_361 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_186 != V_190 ) {
F_136 ( V_10 , V_361 ,
V_186 == V_187 ) ;
}
}
if ( V_522 || V_10 -> V_50 & V_371 ) {
if ( V_522 && ! ( V_10 -> V_50 & V_371 ) )
V_160 = V_161 = 0 ;
F_236 ( V_10 -> V_5 , V_10 , V_160 , V_161 ,
! V_522 , V_13 ) ;
}
F_262 () ;
return 0 ;
}
static int
F_341 ( struct V_83 * V_84 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
struct V_513 * V_514 ;
struct V_109 * V_110 [ V_515 + 1 ] ;
struct V_155 * V_320 , * V_405 ;
struct V_9 * V_134 ;
struct V_6 * V_7 ;
T_1 V_160 = V_415 , V_284 = V_415 ;
T_1 V_406 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_514 ) , V_110 , V_515 , V_516 ) ;
if ( V_32 < 0 )
return V_32 ;
V_514 = F_60 ( V_92 ) ;
V_320 = F_335 ( V_110 [ V_517 ] , V_110 [ V_518 ] , & V_405 ) ;
if ( ! V_320 )
return - V_35 ;
if ( V_110 [ V_524 ] ) {
struct V_525 * V_526 ;
V_526 = F_336 ( V_110 [ V_524 ] ) ;
V_160 = V_526 -> V_527 ;
V_284 = V_526 -> V_528 ;
} else {
V_284 = V_415 ;
V_160 = V_415 ;
}
V_7 = F_74 ( V_101 , V_514 -> V_520 ) ;
if ( ! V_7 )
return - V_169 ;
V_406 = V_110 [ V_519 ] ? F_339 ( V_110 [ V_519 ] ) : V_514 -> V_406 ;
V_406 &= V_478 | V_247 | V_371 |
V_189 | V_408 ;
V_134 = F_188 ( V_101 , V_320 , V_7 , 1 ) ;
if ( ! V_134 ) {
return F_261 ( V_101 , V_514 -> V_520 , V_320 , V_405 ,
V_514 -> V_521 , V_406 ,
V_284 , V_160 ) ;
}
if ( V_92 -> V_529 & V_530 ||
! ( V_92 -> V_529 & V_531 ) )
V_32 = - V_174 ;
else
V_32 = F_340 ( V_134 , V_406 , V_284 , V_160 ) ;
F_146 ( V_134 ) ;
return V_32 ;
}
static void F_342 ( struct V_91 * V_92 , T_3 V_532 , T_1 V_50 ,
T_3 V_159 , int V_85 )
{
struct V_513 * V_514 ;
V_514 = F_60 ( V_92 ) ;
V_514 -> V_533 = V_96 ;
V_514 -> V_521 = V_532 ;
V_514 -> V_406 = V_50 ;
V_514 -> V_425 = V_159 ;
V_514 -> V_520 = V_85 ;
}
static int F_343 ( struct V_83 * V_84 , unsigned long V_1 ,
unsigned long V_70 , T_1 V_534 , T_1 V_359 )
{
struct V_525 V_526 ;
V_526 . V_1 = F_1 ( V_1 ) ;
V_526 . V_70 = F_1 ( V_70 ) ;
V_526 . V_528 = V_534 ;
V_526 . V_527 = V_359 ;
return F_344 ( V_84 , V_524 , sizeof( V_526 ) , & V_526 ) ;
}
static inline int F_345 ( int V_425 )
{
if ( V_425 & V_273 )
return V_427 ;
else if ( V_425 & V_269 )
return V_426 ;
else if ( V_425 & V_535 )
return V_536 ;
else
return V_537 ;
}
static inline int F_346 ( void )
{
return F_55 ( sizeof( struct V_513 ) )
+ F_56 ( 16 )
+ F_56 ( 16 )
+ F_56 ( sizeof( struct V_525 ) )
+ F_56 ( 4 ) ;
}
static int F_347 ( struct V_83 * V_84 , struct V_9 * V_134 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_1 V_534 , V_359 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_513 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
F_342 ( V_92 , V_134 -> V_177 , V_134 -> V_50 , F_345 ( V_134 -> V_159 ) ,
V_134 -> V_5 -> V_7 -> V_85 ) ;
if ( ! ( ( V_134 -> V_50 & V_188 ) &&
( V_134 -> V_161 == V_415 ) ) ) {
V_534 = V_134 -> V_161 ;
V_359 = V_134 -> V_160 ;
if ( V_534 != V_415 ) {
long V_538 = ( V_13 - V_134 -> V_70 ) / V_3 ;
if ( V_534 > V_538 )
V_534 -= V_538 ;
else
V_534 = 0 ;
if ( V_359 != V_415 ) {
if ( V_359 > V_538 )
V_359 -= V_538 ;
else
V_359 = 0 ;
}
}
} else {
V_534 = V_415 ;
V_359 = V_415 ;
}
if ( ! F_202 ( & V_134 -> V_157 ) ) {
if ( F_348 ( V_84 , V_518 , & V_134 -> V_153 ) < 0 ||
F_348 ( V_84 , V_517 , & V_134 -> V_157 ) < 0 )
goto error;
} else
if ( F_348 ( V_84 , V_517 , & V_134 -> V_153 ) < 0 )
goto error;
if ( F_343 ( V_84 , V_134 -> V_1 , V_134 -> V_70 , V_534 , V_359 ) < 0 )
goto error;
if ( F_349 ( V_84 , V_519 , V_134 -> V_50 ) < 0 )
goto error;
F_62 ( V_84 , V_92 ) ;
return 0 ;
error:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static int F_350 ( struct V_83 * V_84 , struct V_539 * V_540 ,
T_1 V_88 , T_1 V_89 , int V_90 , T_13 V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_537 ;
int V_85 = V_540 -> V_5 -> V_7 -> V_85 ;
if ( F_155 ( & V_540 -> V_541 ) & V_535 )
V_159 = V_536 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_513 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
F_342 ( V_92 , 128 , V_188 , V_159 , V_85 ) ;
if ( F_348 ( V_84 , V_542 , & V_540 -> V_541 ) < 0 ||
F_343 ( V_84 , V_540 -> V_543 , V_540 -> V_544 ,
V_415 , V_415 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
F_62 ( V_84 , V_92 ) ;
return 0 ;
}
static int F_351 ( struct V_83 * V_84 , struct V_545 * V_546 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_91 * V_92 ;
T_3 V_159 = V_537 ;
int V_85 = V_546 -> V_547 -> V_7 -> V_85 ;
if ( F_155 ( & V_546 -> V_548 ) & V_535 )
V_159 = V_536 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( struct V_513 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
F_342 ( V_92 , 128 , V_188 , V_159 , V_85 ) ;
if ( F_348 ( V_84 , V_549 , & V_546 -> V_548 ) < 0 ||
F_343 ( V_84 , V_546 -> V_550 , V_546 -> V_551 ,
V_415 , V_415 ) < 0 ) {
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
F_62 ( V_84 , V_92 ) ;
return 0 ;
}
static int F_352 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_118 * V_119 , enum V_552 type ,
int V_553 , int * V_554 )
{
struct V_539 * V_540 ;
struct V_545 * V_546 ;
int V_32 = 1 ;
int V_555 = * V_554 ;
F_172 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_556 : {
struct V_9 * V_134 ;
F_86 (ifa, &idev->addr_list, if_list) {
if ( ++ V_555 < V_553 )
continue;
V_32 = F_347 ( V_84 , V_134 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_416 ,
V_131 ) ;
if ( V_32 < 0 )
break;
F_82 ( V_119 , F_83 ( V_84 ) ) ;
}
break;
}
case V_557 :
for ( V_540 = V_5 -> V_558 ; V_540 ;
V_540 = V_540 -> V_503 , V_555 ++ ) {
if ( V_555 < V_553 )
continue;
V_32 = F_350 ( V_84 , V_540 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_559 ,
V_131 ) ;
if ( V_32 < 0 )
break;
}
break;
case V_560 :
for ( V_546 = V_5 -> V_561 ; V_546 ;
V_546 = V_546 -> V_562 , V_555 ++ ) {
if ( V_555 < V_553 )
continue;
V_32 = F_351 ( V_84 , V_546 ,
F_75 ( V_119 -> V_84 ) . V_88 ,
V_119 -> V_92 -> V_117 ,
V_563 ,
V_131 ) ;
if ( V_32 < 0 )
break;
}
break;
default:
break;
}
F_177 ( & V_5 -> V_36 ) ;
* V_554 = V_555 ;
return V_32 ;
}
static int F_353 ( struct V_83 * V_84 , struct V_118 * V_119 ,
enum V_552 type )
{
struct V_101 * V_101 = F_71 ( V_84 -> V_108 ) ;
int V_120 , V_121 ;
int V_122 , V_555 ;
int V_123 , V_553 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_124 * V_125 ;
V_121 = V_119 -> args [ 0 ] ;
V_123 = V_122 = V_119 -> args [ 1 ] ;
V_553 = V_555 = V_119 -> args [ 2 ] ;
F_78 () ;
V_119 -> V_89 = F_79 ( & V_101 -> V_18 . V_128 ) ^ V_101 -> V_129 ;
for ( V_120 = V_121 ; V_120 < V_126 ; V_120 ++ , V_123 = 0 ) {
V_122 = 0 ;
V_125 = & V_101 -> V_127 [ V_120 ] ;
F_80 (dev, head, index_hlist) {
if ( V_122 < V_123 )
goto V_130;
if ( V_120 > V_121 || V_122 > V_123 )
V_553 = 0 ;
V_555 = 0 ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
goto V_130;
if ( F_352 ( V_5 , V_84 , V_119 , type ,
V_553 , & V_555 ) < 0 )
goto V_132;
V_130:
V_122 ++ ;
}
}
V_132:
F_81 () ;
V_119 -> args [ 0 ] = V_120 ;
V_119 -> args [ 1 ] = V_122 ;
V_119 -> args [ 2 ] = V_555 ;
return V_84 -> V_133 ;
}
static int F_354 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_552 type = V_556 ;
return F_353 ( V_84 , V_119 , type ) ;
}
static int F_355 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_552 type = V_557 ;
return F_353 ( V_84 , V_119 , type ) ;
}
static int F_356 ( struct V_83 * V_84 , struct V_118 * V_119 )
{
enum V_552 type = V_560 ;
return F_353 ( V_84 , V_119 , type ) ;
}
static int F_357 ( struct V_83 * V_107 , struct V_91 * V_92 )
{
struct V_101 * V_101 = F_71 ( V_107 -> V_108 ) ;
struct V_513 * V_514 ;
struct V_109 * V_110 [ V_515 + 1 ] ;
struct V_155 * V_153 = NULL , * V_564 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_134 ;
struct V_83 * V_84 ;
int V_32 ;
V_32 = F_72 ( V_92 , sizeof( * V_514 ) , V_110 , V_515 , V_516 ) ;
if ( V_32 < 0 )
goto V_104;
V_153 = F_335 ( V_110 [ V_517 ] , V_110 [ V_518 ] , & V_564 ) ;
if ( ! V_153 ) {
V_32 = - V_35 ;
goto V_104;
}
V_514 = F_60 ( V_92 ) ;
if ( V_514 -> V_520 )
V_7 = F_74 ( V_101 , V_514 -> V_520 ) ;
V_134 = F_188 ( V_101 , V_153 , V_7 , 1 ) ;
if ( ! V_134 ) {
V_32 = - V_168 ;
goto V_104;
}
V_84 = F_65 ( F_346 () , V_25 ) ;
if ( ! V_84 ) {
V_32 = - V_102 ;
goto V_565;
}
V_32 = F_347 ( V_84 , V_134 , F_75 ( V_107 ) . V_88 ,
V_92 -> V_117 , V_416 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_565;
}
V_32 = F_76 ( V_84 , V_101 , F_75 ( V_107 ) . V_88 ) ;
V_565:
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
F_68 ( V_84 , V_101 , 0 , V_566 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_566 , V_32 ) ;
}
static inline void F_359 ( struct V_86 * V_39 ,
T_2 * V_567 , int V_568 )
{
F_360 ( V_568 < ( V_569 * 4 ) ) ;
memset ( V_567 , 0 , V_568 ) ;
V_567 [ V_570 ] = V_39 -> V_45 ;
V_567 [ V_571 ] = V_39 -> V_572 ;
V_567 [ V_573 ] = V_39 -> V_41 ;
V_567 [ V_574 ] = V_39 -> V_575 ;
V_567 [ V_576 ] = V_39 -> V_577 ;
V_567 [ V_578 ] = V_39 -> V_365 ;
V_567 [ V_579 ] = V_39 -> V_220 ;
V_567 [ V_580 ] = V_39 -> V_58 ;
V_567 [ V_581 ] =
F_361 ( V_39 -> V_475 ) ;
V_567 [ V_582 ] =
F_361 ( V_39 -> V_474 ) ;
V_567 [ V_583 ] = V_39 -> V_584 ;
V_567 [ V_585 ] =
F_361 ( V_39 -> V_586 ) ;
V_567 [ V_587 ] =
F_361 ( V_39 -> V_588 ) ;
V_567 [ V_589 ] = V_39 -> V_65 ;
V_567 [ V_590 ] = V_39 -> V_217 ;
V_567 [ V_591 ] = V_39 -> V_218 ;
V_567 [ V_592 ] = V_39 -> V_214 ;
V_567 [ V_593 ] = V_39 -> V_219 ;
V_567 [ V_594 ] = V_39 -> V_289 ;
V_567 [ V_595 ] = V_39 -> V_596 ;
V_567 [ V_597 ] = V_39 -> V_598 ;
#ifdef F_362
V_567 [ V_599 ] = V_39 -> V_600 ;
V_567 [ V_601 ] =
F_361 ( V_39 -> V_602 ) ;
#ifdef F_363
V_567 [ V_603 ] = V_39 -> V_604 ;
#endif
#endif
V_567 [ V_605 ] = V_39 -> V_100 ;
V_567 [ V_606 ] = V_39 -> V_607 ;
#ifdef F_159
V_567 [ V_608 ] = V_39 -> V_226 ;
V_567 [ V_609 ] = V_39 -> V_227 ;
#endif
#ifdef F_57
V_567 [ V_610 ] = V_39 -> V_99 ;
#endif
V_567 [ V_611 ] = V_39 -> V_171 ;
V_567 [ V_612 ] = V_39 -> V_53 ;
V_567 [ V_613 ] = V_39 -> V_614 ;
V_567 [ V_615 ] = V_39 -> V_616 ;
V_567 [ V_617 ] = V_39 -> V_618 ;
V_567 [ V_619 ] = V_39 -> V_620 ;
V_567 [ V_621 ] = V_39 -> V_622 ;
}
static inline T_14 F_364 ( void )
{
return F_56 ( 4 )
+ F_56 ( sizeof( struct V_623 ) )
+ F_56 ( V_569 * 4 )
+ F_56 ( V_624 * 8 )
+ F_56 ( V_625 * 8 )
+ F_56 ( sizeof( struct V_155 ) ) ;
}
static inline T_14 F_365 ( void )
{
return F_55 ( sizeof( struct V_626 ) )
+ F_56 ( V_627 )
+ F_56 ( V_443 )
+ F_56 ( 4 )
+ F_56 ( 4 )
+ F_56 ( F_364 () ) ;
}
static inline void F_366 ( T_15 * V_17 , T_16 * V_628 ,
int V_629 , int V_568 )
{
int V_16 ;
int V_630 = V_568 - sizeof( T_15 ) * V_629 ;
F_360 ( V_630 < 0 ) ;
F_367 ( V_629 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_629 ; V_16 ++ )
F_367 ( F_368 ( & V_628 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_629 ] , 0 , V_630 ) ;
}
static inline void F_369 ( T_15 * V_17 , void T_17 * V_628 ,
int V_629 , int V_568 , T_14 V_631 )
{
int V_16 ;
int V_630 = V_568 - sizeof( T_15 ) * V_629 ;
F_360 ( V_630 < 0 ) ;
F_367 ( V_629 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_629 ; V_16 ++ )
F_367 ( F_370 ( V_628 , V_16 , V_631 ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_629 ] , 0 , V_630 ) ;
}
static void F_371 ( T_15 * V_17 , struct V_4 * V_5 , int V_632 ,
int V_568 )
{
switch ( V_632 ) {
case V_633 :
F_369 ( V_17 , V_5 -> V_17 . V_18 ,
V_624 , V_568 , F_372 ( struct V_19 , V_22 ) ) ;
break;
case V_634 :
F_366 ( V_17 , V_5 -> V_17 . V_23 -> V_635 , V_625 , V_568 ) ;
break;
}
}
static int F_373 ( struct V_83 * V_84 , struct V_4 * V_5 )
{
struct V_109 * V_636 ;
struct V_623 V_526 ;
if ( F_349 ( V_84 , V_637 , V_5 -> V_68 ) )
goto V_98;
V_526 . V_638 = V_639 ;
V_526 . V_70 = F_1 ( V_5 -> V_70 ) ;
V_526 . V_640 = F_361 ( V_5 -> V_43 -> V_640 ) ;
V_526 . V_641 = F_361 ( F_154 ( V_5 -> V_43 , V_221 ) ) ;
if ( F_344 ( V_84 , V_642 , sizeof( V_526 ) , & V_526 ) )
goto V_98;
V_636 = F_374 ( V_84 , V_643 , V_569 * sizeof( V_644 ) ) ;
if ( ! V_636 )
goto V_98;
F_359 ( & V_5 -> V_39 , F_336 ( V_636 ) , F_375 ( V_636 ) ) ;
V_636 = F_374 ( V_84 , V_633 , V_624 * sizeof( T_15 ) ) ;
if ( ! V_636 )
goto V_98;
F_371 ( F_336 ( V_636 ) , V_5 , V_633 , F_375 ( V_636 ) ) ;
V_636 = F_374 ( V_84 , V_634 , V_625 * sizeof( T_15 ) ) ;
if ( ! V_636 )
goto V_98;
F_371 ( F_336 ( V_636 ) , V_5 , V_634 , F_375 ( V_636 ) ) ;
V_636 = F_374 ( V_84 , V_645 , sizeof( struct V_155 ) ) ;
if ( ! V_636 )
goto V_98;
if ( F_376 ( V_84 , V_646 , V_5 -> V_367 ) )
goto V_98;
F_172 ( & V_5 -> V_36 ) ;
memcpy ( F_336 ( V_636 ) , V_5 -> V_66 . V_211 , F_375 ( V_636 ) ) ;
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
return - V_647 ;
if ( F_373 ( V_84 , V_5 ) < 0 )
return - V_94 ;
return 0 ;
}
static int F_379 ( struct V_4 * V_5 , struct V_155 * V_66 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_648 = false ;
struct V_155 V_649 ;
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
! F_180 ( V_7 , & V_649 , V_137 |
V_223 ) ) {
F_302 ( V_7 , & V_649 , & V_75 ) ;
V_648 = true ;
}
F_144 ( & V_5 -> V_36 ) ;
if ( V_648 ) {
V_5 -> V_68 |= V_469 ;
V_5 -> V_472 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_475 ) ;
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
F_288 ( V_459 , V_5 ) ;
F_262 () ;
return 0 ;
}
static int F_380 ( const struct V_6 * V_7 ,
const struct V_109 * V_636 )
{
struct V_109 * V_110 [ V_650 + 1 ] ;
if ( V_7 && ! F_51 ( V_7 ) )
return - V_651 ;
return F_381 ( V_110 , V_650 , V_636 , V_652 ) ;
}
static int F_382 ( struct V_6 * V_7 , const struct V_109 * V_636 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_51 ( V_7 ) ;
struct V_109 * V_110 [ V_650 + 1 ] ;
if ( ! V_5 )
return - V_651 ;
if ( F_381 ( V_110 , V_650 , V_636 , NULL ) < 0 )
F_383 () ;
if ( V_110 [ V_645 ] ) {
V_32 = F_379 ( V_5 , F_336 ( V_110 [ V_645 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_110 [ V_646 ] ) {
T_3 V_653 = F_384 ( V_110 [ V_646 ] ) ;
if ( V_653 != V_449 &&
V_653 != V_654 &&
V_653 != V_368 )
return - V_35 ;
if ( V_653 == V_368 &&
! V_5 -> V_39 . V_446 . V_447 &&
! F_34 ( V_7 ) -> V_18 . V_40 -> V_446 . V_447 )
return - V_35 ;
V_5 -> V_367 = V_653 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_385 ( struct V_83 * V_84 , struct V_4 * V_5 ,
T_1 V_88 , T_1 V_89 , int V_90 , unsigned int V_50 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_626 * V_655 ;
struct V_91 * V_92 ;
void * V_656 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_655 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
V_655 = F_60 ( V_92 ) ;
V_655 -> V_657 = V_96 ;
V_655 -> V_658 = 0 ;
V_655 -> V_659 = V_7 -> type ;
V_655 -> V_660 = V_7 -> V_85 ;
V_655 -> V_661 = F_386 ( V_7 ) ;
V_655 -> V_662 = 0 ;
if ( F_387 ( V_84 , V_663 , V_7 -> V_48 ) ||
( V_7 -> V_297 &&
F_344 ( V_84 , V_664 , V_7 -> V_297 , V_7 -> V_299 ) ) ||
F_349 ( V_84 , V_665 , V_7 -> V_33 ) ||
( V_7 -> V_85 != F_388 ( V_7 ) &&
F_349 ( V_84 , V_666 , F_388 ( V_7 ) ) ) )
goto V_98;
V_656 = F_389 ( V_84 , V_667 ) ;
if ( ! V_656 )
goto V_98;
if ( F_373 ( V_84 , V_5 ) < 0 )
goto V_98;
F_390 ( V_84 , V_656 ) ;
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
V_459 , V_131 ) < 0 )
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
F_68 ( V_84 , V_101 , 0 , V_668 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_668 , V_32 ) ;
}
static inline T_14 F_392 ( void )
{
return F_55 ( sizeof( struct V_669 ) )
+ F_56 ( sizeof( struct V_155 ) )
+ F_56 ( sizeof( struct V_670 ) ) ;
}
static int F_393 ( struct V_83 * V_84 , struct V_4 * V_5 ,
struct V_355 * V_356 , T_1 V_88 , T_1 V_89 ,
int V_90 , unsigned int V_50 )
{
struct V_669 * V_671 ;
struct V_91 * V_92 ;
struct V_670 V_526 ;
V_92 = F_59 ( V_84 , V_88 , V_89 , V_90 , sizeof( * V_671 ) , V_50 ) ;
if ( ! V_92 )
return - V_94 ;
V_671 = F_60 ( V_92 ) ;
V_671 -> V_672 = V_96 ;
V_671 -> V_673 = 0 ;
V_671 -> V_674 = 0 ;
V_671 -> V_675 = V_5 -> V_7 -> V_85 ;
V_671 -> V_177 = V_356 -> V_177 ;
V_671 -> V_676 = V_356 -> type ;
V_671 -> V_677 = 0 ;
V_671 -> V_678 = 0 ;
if ( V_356 -> V_274 )
V_671 -> V_678 |= V_679 ;
if ( V_356 -> V_365 )
V_671 -> V_678 |= V_680 ;
if ( F_344 ( V_84 , V_681 , sizeof( V_356 -> V_357 ) , & V_356 -> V_357 ) )
goto V_98;
V_526 . V_682 = F_239 ( V_356 -> V_360 ) ;
V_526 . V_683 = F_239 ( V_356 -> V_359 ) ;
if ( F_344 ( V_84 , V_684 , sizeof( V_526 ) , & V_526 ) )
goto V_98;
F_62 ( V_84 , V_92 ) ;
return 0 ;
V_98:
F_63 ( V_84 , V_92 ) ;
return - V_94 ;
}
static void F_248 ( int V_90 , struct V_4 * V_5 ,
struct V_355 * V_356 )
{
struct V_83 * V_84 ;
struct V_101 * V_101 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_102 ;
V_84 = F_65 ( F_392 () , V_103 ) ;
if ( ! V_84 )
goto V_104;
V_32 = F_393 ( V_84 , V_5 , V_356 , 0 , 0 , V_90 , 0 ) ;
if ( V_32 < 0 ) {
F_66 ( V_32 == - V_94 ) ;
F_67 ( V_84 ) ;
goto V_104;
}
F_68 ( V_84 , V_101 , 0 , V_685 , NULL , V_103 ) ;
return;
V_104:
if ( V_32 < 0 )
F_69 ( V_101 , V_685 , V_32 ) ;
}
static void F_298 ( int V_90 , struct V_9 * V_10 )
{
struct V_101 * V_101 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_90 )
F_29 () ;
F_358 ( V_90 ? : V_416 , V_10 ) ;
switch ( V_90 ) {
case V_416 :
if ( ! ( V_10 -> V_149 -> V_686 ) )
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
int F_397 ( struct V_140 * V_687 , int V_688 ,
void T_6 * V_689 , T_14 * V_690 , T_8 * V_691 )
{
int * V_692 = V_687 -> V_319 ;
int V_693 = * V_692 ;
T_8 V_490 = * V_691 ;
struct V_140 V_694 ;
int V_208 ;
V_694 = * V_687 ;
V_694 . V_319 = & V_693 ;
V_208 = F_398 ( & V_694 , V_688 , V_689 , V_690 , V_691 ) ;
if ( V_688 )
V_208 = F_91 ( V_687 , V_692 , V_693 ) ;
if ( V_208 )
* V_691 = V_490 ;
return V_208 ;
}
static
int F_399 ( struct V_140 * V_687 , int V_688 ,
void T_6 * V_689 , T_14 * V_690 , T_8 * V_691 )
{
struct V_4 * V_5 = V_687 -> V_145 ;
int V_695 = V_34 ;
struct V_140 V_694 ;
V_694 = * V_687 ;
V_694 . V_145 = & V_695 ;
V_694 . V_144 = V_5 ? & V_5 -> V_7 -> V_33 : NULL ;
return F_400 ( & V_694 , V_688 , V_689 , V_690 , V_691 ) ;
}
static void F_401 ( struct V_4 * V_5 )
{
struct V_696 V_697 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_402 ( & V_697 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_171 )
F_283 ( NULL , V_199 , & V_697 ) ;
else
F_283 ( NULL , V_182 , & V_697 ) ;
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
int F_405 ( struct V_140 * V_687 , int V_688 ,
void T_6 * V_689 , T_14 * V_690 , T_8 * V_691 )
{
int * V_692 = V_687 -> V_319 ;
int V_693 = * V_692 ;
T_8 V_490 = * V_691 ;
struct V_140 V_694 ;
int V_208 ;
V_694 = * V_687 ;
V_694 . V_319 = & V_693 ;
V_208 = F_398 ( & V_694 , V_688 , V_689 , V_690 , V_691 ) ;
if ( V_688 )
V_208 = F_404 ( V_687 , V_692 , V_693 ) ;
if ( V_208 )
* V_691 = V_490 ;
return V_208 ;
}
static
int F_406 ( struct V_140 * V_687 , int V_688 ,
void T_6 * V_689 , T_14 * V_690 , T_8 * V_691 )
{
int * V_692 = V_687 -> V_319 ;
int V_208 ;
int V_143 , V_698 ;
V_143 = * V_692 ;
V_208 = F_398 ( V_687 , V_688 , V_689 , V_690 , V_691 ) ;
V_698 = * V_692 ;
if ( V_688 && V_143 != V_698 ) {
struct V_101 * V_101 = V_687 -> V_144 ;
if ( ! F_92 () )
return F_93 () ;
if ( V_692 == & V_101 -> V_18 . V_40 -> V_100 )
F_64 ( V_101 , V_82 ,
V_116 ,
V_101 -> V_18 . V_40 ) ;
else if ( V_692 == & V_101 -> V_18 . V_115 -> V_100 )
F_64 ( V_101 , V_82 ,
V_114 ,
V_101 -> V_18 . V_115 ) ;
else {
struct V_4 * V_5 = V_687 -> V_145 ;
F_64 ( V_101 , V_82 ,
V_5 -> V_7 -> V_85 ,
& V_5 -> V_39 ) ;
}
F_94 () ;
}
return V_208 ;
}
static int F_407 ( struct V_140 * V_687 , int V_688 ,
void T_6 * V_689 , T_14 * V_690 ,
T_8 * V_691 )
{
int V_32 ;
struct V_155 V_153 ;
char V_699 [ V_700 ] ;
struct V_140 V_694 = * V_687 ;
struct V_101 * V_101 = V_687 -> V_144 ;
struct V_701 * V_441 = V_687 -> V_319 ;
if ( & V_101 -> V_18 . V_115 -> V_446 == V_687 -> V_319 )
return - V_702 ;
V_694 . V_703 = V_700 ;
V_694 . V_319 = V_699 ;
if ( ! F_92 () )
return F_93 () ;
if ( ! V_688 && ! V_441 -> V_447 ) {
V_32 = - V_702 ;
goto V_175;
}
if ( ! V_688 ) {
V_32 = snprintf ( V_699 , sizeof( V_699 ) , L_29 ,
& V_441 -> V_441 ) ;
if ( V_32 >= sizeof( V_699 ) ) {
V_32 = - V_702 ;
goto V_175;
}
}
V_32 = F_408 ( & V_694 , V_688 , V_689 , V_690 , V_691 ) ;
if ( V_32 || ! V_688 )
goto V_175;
if ( F_409 ( V_699 , - 1 , V_153 . V_704 . V_705 , - 1 , NULL ) != 1 ) {
V_32 = - V_702 ;
goto V_175;
}
V_441 -> V_447 = true ;
V_441 -> V_441 = V_153 ;
if ( & V_101 -> V_18 . V_40 -> V_446 == V_687 -> V_319 ) {
struct V_6 * V_7 ;
F_90 (net, dev) {
struct V_4 * V_5 = F_51 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_367 =
V_368 ;
}
}
} else {
struct V_4 * V_5 = V_687 -> V_145 ;
V_5 -> V_367 = V_368 ;
}
V_175:
F_94 () ;
return V_32 ;
}
static int F_410 ( struct V_101 * V_101 , char * V_706 ,
struct V_4 * V_5 , struct V_86 * V_142 )
{
int V_16 ;
struct V_707 * V_708 ;
char V_709 [ sizeof( L_30 ) + V_627 ] ;
V_708 = F_411 ( & V_710 , sizeof( * V_708 ) , V_25 ) ;
if ( ! V_708 )
goto V_175;
for ( V_16 = 0 ; V_708 -> V_711 [ V_16 ] . V_319 ; V_16 ++ ) {
V_708 -> V_711 [ V_16 ] . V_319 += ( char * ) V_142 - ( char * ) & V_86 ;
V_708 -> V_711 [ V_16 ] . V_145 = V_5 ;
V_708 -> V_711 [ V_16 ] . V_144 = V_101 ;
}
snprintf ( V_709 , sizeof( V_709 ) , L_31 , V_706 ) ;
V_708 -> V_712 = F_412 ( V_101 , V_709 , V_708 -> V_711 ) ;
if ( ! V_708 -> V_712 )
goto free;
V_142 -> V_42 = V_708 ;
return 0 ;
free:
F_26 ( V_708 ) ;
V_175:
return - V_102 ;
}
static void F_413 ( struct V_86 * V_142 )
{
struct V_707 * V_708 ;
if ( ! V_142 -> V_42 )
return;
V_708 = V_142 -> V_42 ;
V_142 -> V_42 = NULL ;
F_414 ( V_708 -> V_712 ) ;
F_26 ( V_708 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_415 ( V_5 -> V_7 -> V_48 ) )
return - V_35 ;
V_32 = F_416 ( V_5 -> V_7 , V_5 -> V_43 ,
& V_713 ) ;
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
struct V_86 * V_714 , * V_715 ;
V_714 = F_411 ( & V_86 , sizeof( V_86 ) , V_25 ) ;
if ( ! V_714 )
goto V_716;
V_715 = F_411 ( & V_717 , sizeof( V_717 ) , V_25 ) ;
if ( ! V_715 )
goto V_718;
V_715 -> V_365 = V_719 . V_365 ;
V_715 -> V_171 = V_719 . V_171 ;
V_715 -> V_446 . V_447 = false ;
V_714 -> V_446 . V_447 = false ;
V_101 -> V_18 . V_115 = V_714 ;
V_101 -> V_18 . V_40 = V_715 ;
#ifdef F_419
V_32 = F_410 ( V_101 , L_32 , NULL , V_714 ) ;
if ( V_32 < 0 )
goto V_720;
V_32 = F_410 ( V_101 , L_33 , NULL , V_715 ) ;
if ( V_32 < 0 )
goto V_721;
#endif
return 0 ;
#ifdef F_419
V_721:
F_413 ( V_714 ) ;
V_720:
F_26 ( V_715 ) ;
#endif
V_718:
F_26 ( V_714 ) ;
V_716:
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
V_32 = F_329 ( & V_722 ) ;
if ( V_32 < 0 )
goto V_723;
V_15 = F_424 ( L_35 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_724;
}
F_250 () ;
V_5 = F_28 ( V_725 . V_726 ) ;
F_94 () ;
if ( F_52 ( V_5 ) ) {
V_32 = F_119 ( V_5 ) ;
goto V_727;
}
for ( V_16 = 0 ; V_16 < V_467 ; V_16 ++ )
F_425 ( & V_179 [ V_16 ] ) ;
F_426 ( & V_728 ) ;
F_247 () ;
F_427 ( & V_729 ) ;
V_32 = F_428 ( V_730 , V_731 , NULL , F_391 ,
NULL ) ;
if ( V_32 < 0 )
goto V_104;
F_428 ( V_730 , V_416 , F_341 , NULL , NULL ) ;
F_428 ( V_730 , V_198 , F_338 , NULL , NULL ) ;
F_428 ( V_730 , V_732 , F_357 ,
F_354 , NULL ) ;
F_428 ( V_730 , V_559 , NULL ,
F_355 , NULL ) ;
F_428 ( V_730 , V_563 , NULL ,
F_356 , NULL ) ;
F_428 ( V_730 , V_733 , F_70 ,
F_77 , NULL ) ;
F_429 () ;
return 0 ;
V_104:
F_430 ( & V_729 ) ;
F_431 ( & V_728 ) ;
V_727:
F_432 ( V_15 ) ;
V_724:
F_331 ( & V_722 ) ;
V_723:
F_433 () ;
V_175:
return V_32 ;
}
void F_434 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_431 ( & V_728 ) ;
F_331 ( & V_722 ) ;
F_433 () ;
F_250 () ;
F_435 ( & V_729 ) ;
F_90 (&init_net, dev) {
if ( F_51 ( V_7 ) == NULL )
continue;
F_289 ( V_7 , 1 ) ;
}
F_289 ( V_725 . V_726 , 2 ) ;
F_141 ( & V_173 ) ;
for ( V_16 = 0 ; V_16 < V_467 ; V_16 ++ )
F_66 ( ! F_436 ( & V_179 [ V_16 ] ) ) ;
F_142 ( & V_173 ) ;
F_10 ( & V_507 ) ;
F_94 () ;
F_432 ( V_15 ) ;
}
