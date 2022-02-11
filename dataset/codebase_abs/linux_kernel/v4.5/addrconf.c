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
if ( type == - 1 || type == V_85 )
V_83 += F_57 ( 4 ) ;
#ifdef F_58
if ( type == - 1 || type == V_86 )
V_83 += F_57 ( 4 ) ;
#endif
if ( type == - 1 || type == V_87 )
V_83 += F_57 ( 4 ) ;
if ( type == - 1 || type == V_88 )
V_83 += F_57 ( 4 ) ;
return V_83 ;
}
static int F_59 ( struct V_89 * V_90 , int V_91 ,
struct V_92 * V_93 , T_1 V_94 ,
T_1 V_95 , int V_96 , unsigned int V_55 ,
int type )
{
struct V_97 * V_98 ;
struct V_84 * V_99 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( struct V_84 ) ,
V_55 ) ;
if ( ! V_98 )
return - V_100 ;
V_99 = F_61 ( V_98 ) ;
V_99 -> V_101 = V_102 ;
if ( F_62 ( V_90 , V_103 , V_91 ) < 0 )
goto V_104;
if ( ( type == - 1 || type == V_85 ) &&
F_62 ( V_90 , V_85 , V_93 -> V_50 ) < 0 )
goto V_104;
#ifdef F_58
if ( ( type == - 1 || type == V_86 ) &&
F_62 ( V_90 , V_86 ,
V_93 -> V_105 ) < 0 )
goto V_104;
#endif
if ( ( type == - 1 || type == V_87 ) &&
F_62 ( V_90 , V_87 , V_93 -> V_106 ) < 0 )
goto V_104;
if ( ( type == - 1 || type == V_88 ) &&
F_62 ( V_90 , V_88 ,
V_93 -> V_107 ) < 0 )
goto V_104;
F_63 ( V_90 , V_98 ) ;
return 0 ;
V_104:
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
void F_65 ( struct V_108 * V_108 , int type , int V_91 ,
struct V_92 * V_93 )
{
struct V_89 * V_90 ;
int V_32 = - V_109 ;
V_90 = F_66 ( F_55 ( type ) , V_110 ) ;
if ( ! V_90 )
goto V_111;
V_32 = F_59 ( V_90 , V_91 , V_93 , 0 , 0 ,
V_112 , 0 , type ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_111;
}
F_69 ( V_90 , V_108 , 0 , V_113 , NULL , V_110 ) ;
return;
V_111:
F_70 ( V_108 , V_113 , V_32 ) ;
}
static int F_71 ( struct V_89 * V_114 ,
struct V_97 * V_98 )
{
struct V_108 * V_108 = F_72 ( V_114 -> V_115 ) ;
struct V_116 * V_117 [ V_118 + 1 ] ;
struct V_84 * V_99 ;
struct V_89 * V_90 ;
struct V_92 * V_93 ;
struct V_4 * V_119 ;
struct V_6 * V_7 ;
int V_91 ;
int V_32 ;
V_32 = F_73 ( V_98 , sizeof( * V_99 ) , V_117 , V_118 ,
V_120 ) ;
if ( V_32 < 0 )
goto V_111;
V_32 = - V_35 ;
if ( ! V_117 [ V_103 ] )
goto V_111;
V_91 = F_74 ( V_117 [ V_103 ] ) ;
switch ( V_91 ) {
case V_121 :
V_93 = V_108 -> V_18 . V_122 ;
break;
case V_123 :
V_93 = V_108 -> V_18 . V_40 ;
break;
default:
V_7 = F_75 ( V_108 , V_91 ) ;
if ( ! V_7 )
goto V_111;
V_119 = F_52 ( V_7 ) ;
if ( ! V_119 )
goto V_111;
V_93 = & V_119 -> V_39 ;
break;
}
V_32 = - V_109 ;
V_90 = F_66 ( F_55 ( - 1 ) , V_110 ) ;
if ( ! V_90 )
goto V_111;
V_32 = F_59 ( V_90 , V_91 , V_93 ,
F_76 ( V_114 ) . V_94 ,
V_98 -> V_124 , V_112 , 0 ,
- 1 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_111;
}
V_32 = F_77 ( V_90 , V_108 , F_76 ( V_114 ) . V_94 ) ;
V_111:
return V_32 ;
}
static int F_78 ( struct V_89 * V_90 ,
struct V_125 * V_126 )
{
struct V_108 * V_108 = F_72 ( V_90 -> V_115 ) ;
int V_127 , V_128 ;
int V_129 , V_130 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_131 * V_132 ;
V_128 = V_126 -> args [ 0 ] ;
V_130 = V_129 = V_126 -> args [ 1 ] ;
for ( V_127 = V_128 ; V_127 < V_133 ; V_127 ++ , V_130 = 0 ) {
V_129 = 0 ;
V_132 = & V_108 -> V_134 [ V_127 ] ;
F_79 () ;
V_126 -> V_95 = F_80 ( & V_108 -> V_18 . V_135 ) ^
V_108 -> V_136 ;
F_81 (dev, head, index_hlist) {
if ( V_129 < V_130 )
goto V_137;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_137;
if ( F_59 ( V_90 , V_7 -> V_91 ,
& V_5 -> V_39 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_112 ,
V_138 ,
- 1 ) < 0 ) {
F_82 () ;
goto V_139;
}
F_83 ( V_126 , F_84 ( V_90 ) ) ;
V_137:
V_129 ++ ;
}
F_82 () ;
}
if ( V_127 == V_133 ) {
if ( F_59 ( V_90 , V_121 ,
V_108 -> V_18 . V_122 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_112 , V_138 ,
- 1 ) < 0 )
goto V_139;
else
V_127 ++ ;
}
if ( V_127 == V_133 + 1 ) {
if ( F_59 ( V_90 , V_123 ,
V_108 -> V_18 . V_40 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_112 , V_138 ,
- 1 ) < 0 )
goto V_139;
else
V_127 ++ ;
}
V_139:
V_126 -> args [ 0 ] = V_127 ;
V_126 -> args [ 1 ] = V_129 ;
return V_90 -> V_140 ;
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_141 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_39 . V_50 )
F_36 ( V_7 ) ;
if ( V_7 -> V_55 & V_79 ) {
if ( V_5 -> V_39 . V_50 ) {
F_49 ( V_7 , & V_80 ) ;
F_49 ( V_7 , & V_142 ) ;
F_49 ( V_7 , & V_143 ) ;
} else {
F_86 ( V_7 , & V_80 ) ;
F_86 ( V_7 , & V_142 ) ;
F_86 ( V_7 , & V_143 ) ;
}
}
F_87 (ifa, &idev->addr_list, if_list) {
if ( V_141 -> V_55 & V_144 )
continue;
if ( V_5 -> V_39 . V_50 )
F_88 ( V_141 ) ;
else
F_89 ( V_141 ) ;
}
F_65 ( F_34 ( V_7 ) , V_85 ,
V_7 -> V_91 , & V_5 -> V_39 ) ;
}
static void F_90 ( struct V_108 * V_108 , T_2 V_145 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_91 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_146 = ( ! V_5 -> V_39 . V_50 ) ^ ( ! V_145 ) ;
V_5 -> V_39 . V_50 = V_145 ;
if ( V_146 )
F_85 ( V_5 ) ;
}
}
}
static int F_92 ( struct V_147 * V_148 , int * V_149 , int V_145 )
{
struct V_108 * V_108 ;
int V_150 ;
if ( ! F_93 () )
return F_94 () ;
V_108 = (struct V_108 * ) V_148 -> V_151 ;
V_150 = * V_149 ;
* V_149 = V_145 ;
if ( V_149 == & V_108 -> V_18 . V_40 -> V_50 ) {
if ( ( ! V_145 ) ^ ( ! V_150 ) )
F_65 ( V_108 , V_85 ,
V_123 ,
V_108 -> V_18 . V_40 ) ;
F_95 () ;
return 0 ;
}
if ( V_149 == & V_108 -> V_18 . V_122 -> V_50 ) {
V_108 -> V_18 . V_40 -> V_50 = V_145 ;
F_90 ( V_108 , V_145 ) ;
if ( ( ! V_145 ) ^ ( ! V_150 ) )
F_65 ( V_108 , V_85 ,
V_121 ,
V_108 -> V_18 . V_122 ) ;
} else if ( ( ! V_145 ) ^ ( ! V_150 ) )
F_85 ( (struct V_4 * ) V_148 -> V_152 ) ;
F_95 () ;
if ( V_145 )
F_96 ( V_108 ) ;
return 1 ;
}
static void F_97 ( struct V_108 * V_108 , T_2 V_145 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_91 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_146 = ( ! V_5 -> V_39 . V_107 ) ^ ( ! V_145 ) ;
V_5 -> V_39 . V_107 = V_145 ;
if ( V_146 )
F_65 ( F_34 ( V_7 ) ,
V_88 ,
V_7 -> V_91 ,
& V_5 -> V_39 ) ;
}
}
}
static int F_98 ( struct V_147 * V_148 , int * V_149 , int V_145 )
{
struct V_108 * V_108 ;
int V_150 ;
if ( ! F_93 () )
return F_94 () ;
V_108 = (struct V_108 * ) V_148 -> V_151 ;
V_150 = * V_149 ;
* V_149 = V_145 ;
if ( V_149 == & V_108 -> V_18 . V_40 -> V_107 ) {
if ( ( ! V_145 ) ^ ( ! V_150 ) )
F_65 ( V_108 ,
V_88 ,
V_123 ,
V_108 -> V_18 . V_40 ) ;
F_95 () ;
return 0 ;
}
if ( V_149 == & V_108 -> V_18 . V_122 -> V_107 ) {
V_108 -> V_18 . V_40 -> V_107 = V_145 ;
F_97 ( V_108 , V_145 ) ;
if ( ( ! V_145 ) ^ ( ! V_150 ) )
F_65 ( V_108 ,
V_88 ,
V_121 ,
V_108 -> V_18 . V_122 ) ;
}
F_95 () ;
return 1 ;
}
void F_99 ( struct V_9 * V_10 )
{
F_67 ( ! F_100 ( & V_10 -> V_153 ) ) ;
#ifdef F_101
F_102 ( L_4 , V_52 ) ;
#endif
F_103 ( V_10 -> V_5 ) ;
if ( F_10 ( & V_10 -> V_11 ) )
F_104 ( L_5 ,
V_10 ) ;
if ( V_10 -> V_154 != V_155 ) {
F_105 ( L_6 , V_10 ) ;
return;
}
F_106 ( V_10 -> V_156 ) ;
F_107 ( V_10 , V_157 ) ;
}
static void
F_108 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_158 * V_149 ;
int V_159 = F_109 ( & V_10 -> V_160 ) ;
F_110 (p, &idev->addr_list) {
struct V_9 * V_141
= F_111 ( V_149 , struct V_9 , V_161 ) ;
if ( V_159 >= F_109 ( & V_141 -> V_160 ) )
break;
}
F_112 ( & V_10 -> V_161 , V_149 ) ;
}
static T_1 F_113 ( const struct V_162 * V_160 )
{
return F_114 ( F_115 ( V_160 ) , V_163 ) ;
}
static struct V_9 *
F_116 ( struct V_4 * V_5 , const struct V_162 * V_160 ,
const struct V_162 * V_164 , int V_165 ,
int V_166 , T_1 V_55 , T_1 V_167 , T_1 V_168 )
{
struct V_9 * V_141 = NULL ;
struct V_169 * V_156 ;
unsigned int V_170 ;
int V_32 = 0 ;
int V_171 = F_117 ( V_160 ) ;
if ( V_171 == V_172 ||
V_171 & V_173 ||
( ! ( V_5 -> V_7 -> V_55 & V_57 ) &&
V_171 & V_174 ) )
return F_30 ( - V_175 ) ;
F_118 () ;
if ( V_5 -> V_81 ) {
V_32 = - V_176 ;
goto V_177;
}
if ( V_5 -> V_39 . V_178 ) {
V_32 = - V_179 ;
goto V_177;
}
F_119 ( & V_180 ) ;
if ( F_120 ( F_34 ( V_5 -> V_7 ) , V_160 , V_5 -> V_7 ) ) {
F_38 ( L_7 ) ;
V_32 = - V_181 ;
goto V_182;
}
V_141 = F_25 ( sizeof( struct V_9 ) , V_110 ) ;
if ( ! V_141 ) {
F_38 ( L_8 ) ;
V_32 = - V_109 ;
goto V_182;
}
V_156 = F_121 ( V_5 , V_160 , false ) ;
if ( F_53 ( V_156 ) ) {
V_32 = F_122 ( V_156 ) ;
goto V_182;
}
F_123 ( V_5 -> V_48 ) ;
V_141 -> V_160 = * V_160 ;
if ( V_164 )
V_141 -> V_164 = * V_164 ;
F_124 ( & V_141 -> V_36 ) ;
F_125 ( & V_141 -> V_11 , V_183 ) ;
F_126 ( & V_141 -> V_153 ) ;
V_141 -> V_166 = V_166 ;
V_141 -> V_184 = V_165 ;
V_141 -> V_55 = V_55 | V_144 ;
V_141 -> V_167 = V_167 ;
V_141 -> V_168 = V_168 ;
V_141 -> V_1 = V_141 -> V_75 = V_13 ;
V_141 -> V_185 = false ;
V_141 -> V_156 = V_156 ;
V_141 -> V_5 = V_5 ;
F_14 ( V_5 ) ;
F_18 ( V_141 ) ;
V_170 = F_113 ( V_160 ) ;
F_127 ( & V_141 -> V_153 , & V_186 [ V_170 ] ) ;
F_128 ( & V_180 ) ;
F_129 ( & V_5 -> V_36 ) ;
F_108 ( V_5 , V_141 ) ;
if ( V_141 -> V_55 & V_187 ) {
F_130 ( & V_141 -> V_188 , & V_5 -> V_64 ) ;
F_18 ( V_141 ) ;
}
F_18 ( V_141 ) ;
F_131 ( & V_5 -> V_36 ) ;
V_177:
F_132 () ;
if ( F_133 ( V_32 == 0 ) )
F_134 ( V_189 , V_141 ) ;
else {
F_26 ( V_141 ) ;
V_141 = F_30 ( V_32 ) ;
}
return V_141 ;
V_182:
F_128 ( & V_180 ) ;
goto V_177;
}
static enum V_190
F_135 ( struct V_9 * V_10 , unsigned long * V_191 )
{
struct V_9 * V_141 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_192 ;
enum V_190 V_193 = V_194 ;
* V_191 = V_13 ;
F_87 (ifa, &idev->addr_list, if_list) {
if ( V_141 == V_10 )
continue;
if ( ! F_136 ( & V_141 -> V_160 , & V_10 -> V_160 ,
V_10 -> V_184 ) )
continue;
if ( V_141 -> V_55 & ( V_195 | V_196 ) )
return V_197 ;
V_193 = V_198 ;
F_119 ( & V_141 -> V_36 ) ;
V_192 = F_137 ( V_141 -> V_167 , V_3 ) ;
if ( F_138 ( * V_191 , V_141 -> V_75 + V_192 * V_3 ) )
* V_191 = V_141 -> V_75 + V_192 * V_3 ;
F_128 ( & V_141 -> V_36 ) ;
}
return V_193 ;
}
static void
F_139 ( struct V_9 * V_10 , unsigned long V_191 , bool V_199 )
{
struct V_169 * V_156 ;
V_156 = F_140 ( & V_10 -> V_160 ,
V_10 -> V_184 ,
V_10 -> V_5 -> V_7 ,
0 , V_200 | V_201 ) ;
if ( V_156 ) {
if ( V_199 )
F_141 ( V_156 ) ;
else {
if ( ! ( V_156 -> V_202 & V_203 ) )
F_142 ( V_156 , V_191 ) ;
F_106 ( V_156 ) ;
}
}
}
static void F_143 ( struct V_9 * V_10 )
{
int V_154 ;
enum V_190 V_193 = V_197 ;
unsigned long V_191 ;
F_29 () ;
F_144 ( & V_10 -> V_36 ) ;
V_154 = V_10 -> V_154 ;
V_10 -> V_154 = V_155 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_154 == V_155 )
goto V_182;
F_144 ( & V_180 ) ;
F_146 ( & V_10 -> V_153 ) ;
F_145 ( & V_180 ) ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_10 -> V_55 & V_187 ) {
F_148 ( & V_10 -> V_188 ) ;
if ( V_10 -> V_204 ) {
F_149 ( V_10 -> V_204 ) ;
V_10 -> V_204 = NULL ;
}
F_11 ( V_10 ) ;
}
if ( V_10 -> V_55 & V_195 && ! ( V_10 -> V_55 & V_196 ) )
V_193 = F_135 ( V_10 , & V_191 ) ;
F_150 ( & V_10 -> V_161 ) ;
F_11 ( V_10 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
F_9 ( V_10 ) ;
F_152 ( V_205 , V_10 ) ;
F_134 ( V_206 , V_10 ) ;
if ( V_193 != V_197 ) {
F_139 ( V_10 , V_191 ,
V_193 == V_194 ) ;
}
F_153 ( V_10 ) ;
V_182:
F_149 ( V_10 ) ;
}
static int F_154 ( struct V_9 * V_10 , struct V_9 * V_207 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_162 V_160 , * V_208 ;
unsigned long V_209 , V_210 , V_211 , V_212 ;
unsigned long V_213 ;
int V_214 ;
int V_215 = 0 ;
T_1 V_216 ;
unsigned long V_217 = V_13 ;
F_147 ( & V_5 -> V_36 ) ;
if ( V_207 ) {
F_144 ( & V_207 -> V_36 ) ;
memcpy ( & V_160 . V_218 [ 8 ] , & V_207 -> V_160 . V_218 [ 8 ] , 8 ) ;
F_145 ( & V_207 -> V_36 ) ;
V_208 = & V_160 ;
} else {
V_208 = NULL ;
}
V_219:
F_14 ( V_5 ) ;
if ( V_5 -> V_39 . V_70 <= 0 ) {
F_151 ( & V_5 -> V_36 ) ;
F_43 ( L_9 , V_52 ) ;
F_103 ( V_5 ) ;
V_215 = - 1 ;
goto V_182;
}
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_220 ++ >= V_5 -> V_39 . V_221 ) {
V_5 -> V_39 . V_70 = - 1 ;
F_145 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_105 ( L_10 ,
V_52 ) ;
F_103 ( V_5 ) ;
V_215 = - 1 ;
goto V_182;
}
F_18 ( V_10 ) ;
memcpy ( V_160 . V_218 , V_10 -> V_160 . V_218 , 8 ) ;
F_155 ( V_5 , V_208 ) ;
memcpy ( & V_160 . V_218 [ 8 ] , V_5 -> V_222 , 8 ) ;
V_212 = ( V_217 - V_10 -> V_75 ) / V_3 ;
V_210 = F_156 ( V_223 ,
V_10 -> V_167 ,
V_5 -> V_39 . V_224 + V_212 ) ;
V_209 = F_156 ( V_223 ,
V_10 -> V_168 ,
V_5 -> V_39 . V_225 + V_212 -
V_5 -> V_39 . V_226 ) ;
V_214 = V_10 -> V_184 ;
V_211 = V_10 -> V_75 ;
F_145 ( & V_10 -> V_36 ) ;
V_213 = V_5 -> V_39 . V_221 *
V_5 -> V_39 . V_227 *
F_157 ( V_5 -> V_48 , V_228 ) / V_3 ;
F_151 ( & V_5 -> V_36 ) ;
V_212 = ( V_217 - V_211 + V_229 ) / V_3 ;
if ( V_209 <= V_213 + V_212 ) {
F_149 ( V_10 ) ;
F_103 ( V_5 ) ;
V_215 = - 1 ;
goto V_182;
}
V_216 = V_187 ;
if ( V_10 -> V_55 & V_230 )
V_216 |= V_230 ;
V_207 = F_116 ( V_5 , & V_160 , NULL , V_214 ,
F_158 ( & V_160 ) , V_216 ,
V_210 , V_209 ) ;
if ( F_53 ( V_207 ) ) {
F_149 ( V_10 ) ;
F_103 ( V_5 ) ;
F_43 ( L_11 , V_52 ) ;
V_208 = & V_160 ;
F_147 ( & V_5 -> V_36 ) ;
goto V_219;
}
F_144 ( & V_207 -> V_36 ) ;
V_207 -> V_204 = V_10 ;
V_207 -> V_1 = V_217 ;
V_207 -> V_75 = V_211 ;
F_145 ( & V_207 -> V_36 ) ;
F_159 ( V_207 ) ;
F_149 ( V_207 ) ;
F_103 ( V_5 ) ;
V_182:
return V_215 ;
}
static inline int F_160 ( int type )
{
if ( type & ( V_231 | V_232 | V_174 ) )
return 1 ;
return 0 ;
}
static inline bool F_161 ( struct V_4 * V_5 )
{
#ifdef F_162
return V_5 && V_5 -> V_39 . V_233 && V_5 -> V_39 . V_234 ;
#else
return false ;
#endif
}
static int F_163 ( struct V_108 * V_108 ,
struct V_235 * V_236 ,
struct V_237 * V_238 ,
int V_16 )
{
int V_215 ;
if ( V_16 <= V_236 -> V_239 ) {
switch ( V_16 ) {
case V_240 :
V_215 = V_236 -> V_241 ;
break;
case V_242 :
V_215 = V_236 -> V_243 ;
break;
default:
V_215 = ! ! F_164 ( V_16 , V_236 -> V_244 ) ;
}
goto V_182;
}
switch ( V_16 ) {
case V_245 :
V_215 = ! ! V_236 -> V_141 ;
break;
case V_246 :
V_215 = F_165 ( & V_236 -> V_141 -> V_160 , V_238 -> V_160 ) ;
break;
case V_240 :
V_215 = F_166 ( V_236 -> V_171 ) ;
if ( V_215 >= V_238 -> V_166 )
V_215 = - V_215 ;
else
V_215 -= 128 ;
V_236 -> V_241 = V_215 ;
break;
case V_247 :
{
T_3 V_248 = V_249 ;
if ( ! F_161 ( V_236 -> V_141 -> V_5 ) )
V_248 |= V_230 ;
V_215 = F_160 ( V_236 -> V_171 ) ||
! ( V_236 -> V_141 -> V_55 & V_248 ) ;
break;
}
#ifdef F_167
case V_250 :
{
int V_251 = ! ( V_238 -> V_252 & V_253 ) ;
V_215 = ! ( V_236 -> V_141 -> V_55 & V_254 ) ^ V_251 ;
break;
}
#endif
case V_255 :
V_215 = ( ! V_238 -> V_91 ||
V_238 -> V_91 == V_236 -> V_141 -> V_5 -> V_7 -> V_91 ) ;
break;
case V_256 :
V_215 = F_168 ( V_108 ,
& V_236 -> V_141 -> V_160 , V_236 -> V_171 ,
V_236 -> V_141 -> V_5 -> V_7 -> V_91 ) == V_238 -> V_257 ;
break;
case V_258 :
{
int V_259 = V_238 -> V_252 & ( V_260 | V_261 ) ?
! ! ( V_238 -> V_252 & V_261 ) :
V_236 -> V_141 -> V_5 -> V_39 . V_70 >= 2 ;
V_215 = ( ! ( V_236 -> V_141 -> V_55 & V_187 ) ) ^ V_259 ;
break;
}
case V_262 :
V_215 = ! ( F_169 ( & V_236 -> V_141 -> V_160 ) ^
F_169 ( V_238 -> V_160 ) ) ;
break;
case V_242 :
V_215 = F_170 ( & V_236 -> V_141 -> V_160 , V_238 -> V_160 ) ;
if ( V_215 > V_236 -> V_141 -> V_184 )
V_215 = V_236 -> V_141 -> V_184 ;
V_236 -> V_243 = V_215 ;
break;
#ifdef F_162
case V_263 :
V_215 = ! ( V_236 -> V_141 -> V_55 & V_230 ) ;
break;
#endif
default:
V_215 = 0 ;
}
if ( V_215 )
F_171 ( V_16 , V_236 -> V_244 ) ;
V_236 -> V_239 = V_16 ;
V_182:
return V_215 ;
}
static int F_172 ( struct V_108 * V_108 ,
struct V_237 * V_238 ,
struct V_4 * V_5 ,
struct V_235 * V_264 ,
int V_265 )
{
struct V_235 * V_236 = & V_264 [ 1 - V_265 ] , * V_266 = & V_264 [ V_265 ] ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_236 -> V_141 -> V_55 & V_144 ) &&
( ! ( V_236 -> V_141 -> V_55 & V_230 ) ) )
continue;
V_236 -> V_171 = F_174 ( & V_236 -> V_141 -> V_160 ) ;
if ( F_175 ( V_236 -> V_171 == V_172 ||
V_236 -> V_171 & V_173 ) ) {
F_176 ( L_12 ,
V_5 -> V_7 -> V_53 ) ;
continue;
}
V_236 -> V_239 = - 1 ;
F_177 ( V_236 -> V_244 , V_267 ) ;
for ( V_16 = 0 ; V_16 < V_267 ; V_16 ++ ) {
int V_268 , V_269 ;
V_268 = F_163 ( V_108 , V_266 , V_238 , V_16 ) ;
V_269 = F_163 ( V_108 , V_236 , V_238 , V_16 ) ;
if ( V_268 > V_269 ) {
if ( V_16 == V_240 &&
V_236 -> V_241 > 0 ) {
goto V_182;
}
break;
} else if ( V_268 < V_269 ) {
if ( V_266 -> V_141 )
F_149 ( V_266 -> V_141 ) ;
F_18 ( V_236 -> V_141 ) ;
F_178 ( V_266 , V_236 ) ;
V_265 = 1 - V_265 ;
V_236 -> V_141 = V_266 -> V_141 ;
break;
}
}
}
V_182:
F_179 ( & V_5 -> V_36 ) ;
return V_265 ;
}
int F_180 ( struct V_108 * V_108 , const struct V_6 * V_270 ,
const struct V_162 * V_271 , unsigned int V_252 ,
struct V_162 * V_272 )
{
struct V_235 V_264 [ 2 ] , * V_266 ;
struct V_237 V_238 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_273 ;
bool V_274 = false ;
int V_265 = 0 ;
V_273 = F_174 ( V_271 ) ;
V_238 . V_160 = V_271 ;
V_238 . V_91 = V_270 ? V_270 -> V_91 : 0 ;
V_238 . V_166 = F_166 ( V_273 ) ;
V_238 . V_257 = F_168 ( V_108 , V_271 , V_273 , V_238 . V_91 ) ;
V_238 . V_252 = V_252 ;
V_264 [ V_265 ] . V_239 = - 1 ;
V_264 [ V_265 ] . V_141 = NULL ;
F_79 () ;
if ( V_270 ) {
V_5 = F_52 ( V_270 ) ;
if ( ( V_273 & V_173 ) ||
V_238 . V_166 <= V_275 ||
( V_5 && V_5 -> V_39 . V_276 ) ) {
V_274 = true ;
}
}
if ( V_274 ) {
if ( V_5 )
V_265 = F_172 ( V_108 , & V_238 , V_5 , V_264 , V_265 ) ;
} else {
F_181 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
continue;
V_265 = F_172 ( V_108 , & V_238 , V_5 , V_264 , V_265 ) ;
}
}
F_82 () ;
V_266 = & V_264 [ V_265 ] ;
if ( ! V_266 -> V_141 )
return - V_175 ;
* V_272 = V_266 -> V_141 -> V_160 ;
F_149 ( V_266 -> V_141 ) ;
return 0 ;
}
int F_182 ( struct V_4 * V_5 , struct V_162 * V_160 ,
T_1 V_277 )
{
struct V_9 * V_10 ;
int V_32 = - V_175 ;
F_183 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_166 > V_278 )
break;
if ( V_10 -> V_166 == V_278 &&
! ( V_10 -> V_55 & V_277 ) ) {
* V_160 = V_10 -> V_160 ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
int F_184 ( struct V_6 * V_7 , struct V_162 * V_160 ,
T_1 V_277 )
{
struct V_4 * V_5 ;
int V_32 = - V_175 ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
V_32 = F_182 ( V_5 , V_160 , V_277 ) ;
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_32 ;
}
static int F_185 ( struct V_4 * V_5 )
{
int V_279 = 0 ;
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list)
V_279 ++ ;
F_179 ( & V_5 -> V_36 ) ;
return V_279 ;
}
int F_186 ( struct V_108 * V_108 , const struct V_162 * V_160 ,
const struct V_6 * V_7 , int V_280 )
{
return F_187 ( V_108 , V_160 , V_7 , V_280 , V_144 ) ;
}
int F_187 ( struct V_108 * V_108 , const struct V_162 * V_160 ,
const struct V_6 * V_7 , int V_280 ,
T_1 V_277 )
{
struct V_9 * V_10 ;
unsigned int V_170 = F_113 ( V_160 ) ;
T_1 V_281 ;
F_118 () ;
F_81 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_108 ) )
continue;
V_281 = ( V_10 -> V_55 & V_230 )
? ( V_10 -> V_55 & ~ V_144 )
: V_10 -> V_55 ;
if ( F_165 ( & V_10 -> V_160 , V_160 ) &&
! ( V_281 & V_277 ) &&
( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_166 & ( V_278 | V_282 ) || V_280 ) ) ) {
F_132 () ;
return 1 ;
}
}
F_132 () ;
return 0 ;
}
static bool F_120 ( struct V_108 * V_108 , const struct V_162 * V_160 ,
struct V_6 * V_7 )
{
unsigned int V_170 = F_113 ( V_160 ) ;
struct V_9 * V_10 ;
F_189 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_108 ) )
continue;
if ( F_165 ( & V_10 -> V_160 , V_160 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_190 ( const struct V_162 * V_160 ,
const unsigned int V_184 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_141 ;
bool V_215 = false ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifa, &idev->addr_list, if_list) {
V_215 = F_136 ( V_160 , & V_141 -> V_160 , V_184 ) ;
if ( V_215 )
break;
}
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_215 ;
}
int F_191 ( const struct V_162 * V_160 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_141 ;
int V_283 ;
V_283 = 0 ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifa, &idev->addr_list, if_list) {
V_283 = F_136 ( V_160 , & V_141 -> V_160 ,
V_141 -> V_184 ) ;
if ( V_283 )
break;
}
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_283 ;
}
struct V_9 * F_192 ( struct V_108 * V_108 , const struct V_162 * V_160 ,
struct V_6 * V_7 , int V_280 )
{
struct V_9 * V_10 , * V_284 = NULL ;
unsigned int V_170 = F_113 ( V_160 ) ;
F_118 () ;
F_193 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_108 ) )
continue;
if ( F_165 ( & V_10 -> V_160 , V_160 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_166 & ( V_278 | V_282 ) || V_280 ) ) {
V_284 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_132 () ;
return V_284 ;
}
static void F_194 ( struct V_9 * V_10 , int V_285 )
{
if ( V_285 )
V_10 -> V_55 |= V_286 ;
if ( V_10 -> V_55 & V_195 ) {
F_144 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_55 |= V_144 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_285 )
F_152 ( 0 , V_10 ) ;
F_149 ( V_10 ) ;
} else if ( V_10 -> V_55 & V_187 ) {
struct V_9 * V_204 ;
F_144 ( & V_10 -> V_36 ) ;
V_204 = V_10 -> V_204 ;
if ( V_204 ) {
F_18 ( V_204 ) ;
F_145 ( & V_10 -> V_36 ) ;
F_154 ( V_204 , V_10 ) ;
F_149 ( V_204 ) ;
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
int V_32 = - V_287 ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_154 == V_288 ) {
V_10 -> V_154 = V_289 ;
V_32 = 0 ;
}
F_145 ( & V_10 -> V_36 ) ;
return V_32 ;
}
void F_196 ( struct V_9 * V_10 )
{
struct V_162 V_160 ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_108 * V_108 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( F_195 ( V_10 ) ) {
F_149 ( V_10 ) ;
return;
}
F_197 ( L_13 ,
V_10 -> V_5 -> V_7 -> V_53 , & V_10 -> V_160 ) ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_55 & V_290 ) {
int V_166 = V_10 -> V_166 ;
T_1 V_55 = V_10 -> V_55 ;
struct V_162 V_291 ;
struct V_9 * V_292 ;
T_1 V_167 , V_293 ;
int V_165 = V_10 -> V_184 ;
int V_294 = V_10 -> V_295 + 1 ;
if ( V_294 > V_108 -> V_18 . V_47 . V_296 ) {
F_197 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_53 ) ;
goto V_297;
}
V_291 = V_10 -> V_160 ;
if ( F_198 ( & V_291 , V_294 ,
V_5 ) )
goto V_297;
V_167 = V_10 -> V_167 ;
V_293 = V_10 -> V_168 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_5 -> V_39 . V_298 &&
F_185 ( V_5 ) >=
V_5 -> V_39 . V_298 )
goto V_299;
F_197 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_53 ) ;
V_292 = F_116 ( V_5 , & V_291 , NULL , V_165 ,
V_166 , V_55 , V_167 ,
V_293 ) ;
if ( F_53 ( V_292 ) )
goto V_299;
F_144 ( & V_292 -> V_36 ) ;
V_292 -> V_295 = V_294 ;
V_292 -> V_154 = V_300 ;
F_145 ( & V_292 -> V_36 ) ;
F_16 ( V_292 , V_108 -> V_18 . V_47 . V_301 ) ;
F_149 ( V_292 ) ;
V_299:
F_144 ( & V_10 -> V_36 ) ;
} else if ( V_5 -> V_39 . V_58 > 1 && ! V_5 -> V_39 . V_178 ) {
V_160 . V_302 [ 0 ] = F_199 ( 0xfe800000 ) ;
V_160 . V_302 [ 1 ] = 0 ;
if ( ! F_200 ( V_160 . V_218 + 8 , V_5 -> V_7 ) &&
F_165 ( & V_10 -> V_160 , & V_160 ) ) {
V_5 -> V_39 . V_178 = 1 ;
F_43 ( L_16 ,
V_10 -> V_5 -> V_7 -> V_53 ) ;
}
}
V_297:
V_10 -> V_154 = V_303 ;
F_145 ( & V_10 -> V_36 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_201 ( struct V_6 * V_7 , const struct V_162 * V_160 )
{
struct V_162 V_304 ;
if ( V_7 -> V_55 & ( V_57 | V_56 ) )
return;
F_202 ( V_160 , & V_304 ) ;
F_49 ( V_7 , & V_304 ) ;
}
void F_203 ( struct V_4 * V_5 , const struct V_162 * V_160 )
{
struct V_162 V_304 ;
if ( V_5 -> V_7 -> V_55 & ( V_57 | V_56 ) )
return;
F_202 ( V_160 , & V_304 ) ;
F_204 ( V_5 , & V_304 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_162 V_160 ;
if ( V_10 -> V_184 >= 127 )
return;
F_205 ( & V_160 , & V_10 -> V_160 , V_10 -> V_184 ) ;
if ( F_206 ( & V_160 ) )
return;
F_207 ( V_10 -> V_5 , & V_160 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
struct V_162 V_160 ;
if ( V_10 -> V_184 >= 127 )
return;
F_205 ( & V_160 , & V_10 -> V_160 , V_10 -> V_184 ) ;
if ( F_206 ( & V_160 ) )
return;
F_208 ( V_10 -> V_5 , & V_160 ) ;
}
static int F_209 ( T_3 * V_305 , struct V_6 * V_7 )
{
if ( V_7 -> V_306 != V_307 )
return - 1 ;
memcpy ( V_305 , V_7 -> V_308 , V_307 ) ;
V_305 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_210 ( T_3 * V_305 , struct V_6 * V_7 )
{
union V_309 * V_310 ;
if ( V_7 -> V_306 != V_311 )
return - 1 ;
V_310 = (union V_309 * ) V_7 -> V_308 ;
memcpy ( V_305 , & V_310 -> V_312 . V_313 , sizeof( V_310 -> V_312 . V_313 ) ) ;
V_305 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_211 ( T_3 * V_305 , struct V_6 * V_7 )
{
if ( V_7 -> V_306 != V_314 )
return - 1 ;
memset ( V_305 , 0 , 7 ) ;
V_305 [ 7 ] = * ( T_3 * ) V_7 -> V_308 ;
return 0 ;
}
static int F_212 ( T_3 * V_305 , struct V_6 * V_7 )
{
if ( V_7 -> V_306 != V_315 )
return - 1 ;
memcpy ( V_305 , V_7 -> V_308 + 12 , 8 ) ;
V_305 [ 0 ] |= 2 ;
return 0 ;
}
static int F_213 ( T_3 * V_305 , T_4 V_160 )
{
if ( V_160 == 0 )
return - 1 ;
V_305 [ 0 ] = ( F_214 ( V_160 ) || F_215 ( V_160 ) ||
F_216 ( V_160 ) || F_217 ( V_160 ) ||
F_218 ( V_160 ) || F_219 ( V_160 ) ||
F_220 ( V_160 ) || F_221 ( V_160 ) ||
F_222 ( V_160 ) || F_223 ( V_160 ) ||
F_224 ( V_160 ) ) ? 0x00 : 0x02 ;
V_305 [ 1 ] = 0 ;
V_305 [ 2 ] = 0x5E ;
V_305 [ 3 ] = 0xFE ;
memcpy ( V_305 + 4 , & V_160 , 4 ) ;
return 0 ;
}
static int F_225 ( T_3 * V_305 , struct V_6 * V_7 )
{
if ( V_7 -> V_61 & V_62 )
return F_213 ( V_305 , * ( T_4 * ) V_7 -> V_308 ) ;
return - 1 ;
}
static int F_226 ( T_3 * V_305 , struct V_6 * V_7 )
{
return F_213 ( V_305 , * ( T_4 * ) V_7 -> V_308 ) ;
}
static int F_227 ( T_3 * V_305 , struct V_6 * V_7 )
{
memcpy ( V_305 , V_7 -> V_316 , 3 ) ;
memcpy ( V_305 + 5 , V_7 -> V_316 + 3 , 3 ) ;
V_305 [ 3 ] = 0xFF ;
V_305 [ 4 ] = 0xFE ;
V_305 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_200 ( T_3 * V_305 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_317 :
case V_318 :
return F_228 ( V_305 , V_7 ) ;
case V_319 :
return F_211 ( V_305 , V_7 ) ;
case V_320 :
return F_212 ( V_305 , V_7 ) ;
case V_60 :
return F_225 ( V_305 , V_7 ) ;
case V_321 :
return F_226 ( V_305 , V_7 ) ;
case V_322 :
return F_209 ( V_305 , V_7 ) ;
case V_323 :
return F_210 ( V_305 , V_7 ) ;
case V_68 :
return F_227 ( V_305 , V_7 ) ;
}
return - 1 ;
}
static int F_229 ( T_3 * V_305 , struct V_4 * V_5 )
{
int V_32 = - 1 ;
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_183 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_166 > V_278 )
break;
if ( V_10 -> V_166 == V_278 && ! ( V_10 -> V_55 & V_144 ) ) {
memcpy ( V_305 , V_10 -> V_160 . V_218 + 8 , 8 ) ;
V_32 = 0 ;
break;
}
}
F_179 ( & V_5 -> V_36 ) ;
return V_32 ;
}
static void F_230 ( struct V_4 * V_5 )
{
V_324:
F_231 ( V_5 -> V_222 , sizeof( V_5 -> V_222 ) ) ;
V_5 -> V_222 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_222 [ 0 ] == 0xfd &&
( V_5 -> V_222 [ 1 ] & V_5 -> V_222 [ 2 ] & V_5 -> V_222 [ 3 ] & V_5 -> V_222 [ 4 ] & V_5 -> V_222 [ 5 ] & V_5 -> V_222 [ 6 ] ) == 0xff &&
( V_5 -> V_222 [ 7 ] & 0x80 ) )
goto V_324;
if ( ( V_5 -> V_222 [ 0 ] | V_5 -> V_222 [ 1 ] ) == 0 ) {
if ( V_5 -> V_222 [ 2 ] == 0x5e && V_5 -> V_222 [ 3 ] == 0xfe )
goto V_324;
if ( ( V_5 -> V_222 [ 2 ] | V_5 -> V_222 [ 3 ] | V_5 -> V_222 [ 4 ] | V_5 -> V_222 [ 5 ] | V_5 -> V_222 [ 6 ] | V_5 -> V_222 [ 7 ] ) == 0x00 )
goto V_324;
}
}
static void V_66 ( unsigned long V_325 )
{
struct V_4 * V_5 = (struct V_4 * ) V_325 ;
unsigned long V_191 ;
F_118 () ;
F_147 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_81 )
goto V_182;
F_230 ( V_5 ) ;
V_191 = V_13 +
V_5 -> V_39 . V_225 * V_3 -
V_5 -> V_39 . V_221 * V_5 -> V_39 . V_227 *
F_157 ( V_5 -> V_48 , V_228 ) -
V_5 -> V_39 . V_226 * V_3 ;
if ( F_138 ( V_191 , V_13 ) ) {
F_105 ( L_17 ,
V_52 , V_5 -> V_7 -> V_53 ) ;
goto V_182;
}
if ( ! F_15 ( & V_5 -> V_65 , V_191 ) )
F_14 ( V_5 ) ;
V_182:
F_151 ( & V_5 -> V_36 ) ;
F_132 () ;
F_103 ( V_5 ) ;
}
static void F_155 ( struct V_4 * V_5 , struct V_162 * V_208 )
{
if ( V_208 && memcmp ( V_5 -> V_222 , & V_208 -> V_218 [ 8 ] , 8 ) == 0 )
F_230 ( V_5 ) ;
}
static void
F_232 ( struct V_162 * V_326 , int V_327 , struct V_6 * V_7 ,
unsigned long V_191 , T_1 V_55 )
{
struct V_328 V_329 = {
. V_330 = F_233 ( V_7 ) ? : V_331 ,
. V_332 = V_333 ,
. V_334 = V_7 -> V_91 ,
. V_335 = V_191 ,
. V_336 = V_327 ,
. V_337 = V_338 | V_55 ,
. V_339 . V_340 = F_34 ( V_7 ) ,
. V_341 = V_342 ,
} ;
V_329 . V_343 = * V_326 ;
#if F_42 ( V_59 )
if ( V_7 -> type == V_60 && ( V_7 -> V_55 & V_344 ) )
V_329 . V_337 |= V_345 ;
#endif
F_234 ( & V_329 ) ;
}
static struct V_169 * F_140 ( const struct V_162 * V_326 ,
int V_327 ,
const struct V_6 * V_7 ,
T_1 V_55 , T_1 V_346 )
{
struct V_347 * V_348 ;
struct V_169 * V_156 = NULL ;
struct V_349 * V_148 ;
T_1 V_350 = F_233 ( V_7 ) ? : V_331 ;
V_148 = F_235 ( F_34 ( V_7 ) , V_350 ) ;
if ( ! V_148 )
return NULL ;
F_173 ( & V_148 -> V_351 ) ;
V_348 = F_236 ( & V_148 -> V_352 , V_326 , V_327 , NULL , 0 ) ;
if ( ! V_348 )
goto V_182;
V_346 |= V_353 ;
for ( V_156 = V_348 -> V_354 ; V_156 ; V_156 = V_156 -> V_238 . V_355 ) {
if ( V_156 -> V_238 . V_7 -> V_91 != V_7 -> V_91 )
continue;
if ( ( V_156 -> V_202 & V_55 ) != V_55 )
continue;
if ( ( V_156 -> V_202 & V_346 ) != 0 )
continue;
F_237 ( & V_156 -> V_238 ) ;
break;
}
V_182:
F_179 ( & V_148 -> V_351 ) ;
return V_156 ;
}
static void F_238 ( struct V_6 * V_7 )
{
struct V_328 V_329 = {
. V_330 = F_233 ( V_7 ) ? : V_356 ,
. V_332 = V_333 ,
. V_334 = V_7 -> V_91 ,
. V_336 = 8 ,
. V_337 = V_338 ,
. V_339 . V_340 = F_34 ( V_7 ) ,
} ;
F_239 ( & V_329 . V_343 , F_199 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_234 ( & V_329 ) ;
}
static struct V_4 * F_240 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return F_30 ( - V_109 ) ;
if ( V_5 -> V_39 . V_178 )
return F_30 ( - V_179 ) ;
if ( ! ( V_7 -> V_55 & V_57 ) )
F_238 ( V_7 ) ;
return V_5 ;
}
static void F_241 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_223 V_167 , V_223 V_168 ,
bool V_357 , unsigned long V_217 )
{
T_1 V_55 ;
struct V_9 * V_207 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ift, &idev->tempaddr_list, tmp_list) {
int V_212 , V_358 , V_359 ;
if ( V_10 != V_207 -> V_204 )
continue;
V_212 = ( V_217 - V_207 -> V_1 ) / V_3 ;
V_358 = V_5 -> V_39 . V_224 - V_212 ;
if ( V_358 < 0 )
V_358 = 0 ;
V_359 = V_5 -> V_39 . V_225 -
V_5 -> V_39 . V_226 - V_212 ;
if ( V_359 < 0 )
V_359 = 0 ;
if ( V_167 > V_358 )
V_167 = V_358 ;
if ( V_168 > V_359 )
V_168 = V_359 ;
F_119 ( & V_207 -> V_36 ) ;
V_55 = V_207 -> V_55 ;
V_207 -> V_167 = V_167 ;
V_207 -> V_168 = V_168 ;
V_207 -> V_75 = V_217 ;
if ( V_168 > 0 )
V_207 -> V_55 &= ~ V_249 ;
F_128 ( & V_207 -> V_36 ) ;
if ( ! ( V_55 & V_144 ) )
F_152 ( 0 , V_207 ) ;
}
if ( ( V_357 || F_242 ( & V_5 -> V_64 ) ) &&
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
V_5 -> V_43 == V_360 ;
}
void F_244 ( struct V_6 * V_7 , T_3 * V_361 , int V_140 , bool V_362 )
{
struct V_363 * V_364 ;
V_223 V_167 ;
V_223 V_168 ;
int V_171 ;
T_1 V_216 = 0 ;
struct V_4 * V_119 ;
struct V_108 * V_108 = F_34 ( V_7 ) ;
V_364 = (struct V_363 * ) V_361 ;
if ( V_140 < sizeof( struct V_363 ) ) {
F_38 ( L_18 ) ;
return;
}
V_171 = F_117 ( & V_364 -> V_365 ) ;
if ( V_171 & ( V_173 | V_366 ) )
return;
V_167 = F_245 ( V_364 -> V_367 ) ;
V_168 = F_245 ( V_364 -> V_368 ) ;
if ( V_168 > V_167 ) {
F_246 ( L_19 ) ;
return;
}
V_119 = F_247 ( V_7 ) ;
if ( ! V_119 ) {
F_176 ( L_20 ,
V_7 -> V_53 ) ;
return;
}
if ( V_364 -> V_283 ) {
struct V_169 * V_156 ;
unsigned long V_369 ;
if ( V_3 > V_370 )
V_369 = F_137 ( V_167 , V_3 ) ;
else
V_369 = F_137 ( V_167 , V_370 ) ;
if ( F_248 ( V_369 ) )
V_369 *= V_3 ;
V_156 = F_140 ( & V_364 -> V_365 ,
V_364 -> V_184 ,
V_7 ,
V_371 | V_372 ,
V_200 | V_201 ) ;
if ( V_156 ) {
if ( V_167 == 0 ) {
F_141 ( V_156 ) ;
V_156 = NULL ;
} else if ( F_248 ( V_369 ) ) {
F_142 ( V_156 , V_13 + V_369 ) ;
} else {
F_249 ( V_156 ) ;
}
} else if ( V_167 ) {
T_5 V_191 = 0 ;
int V_55 = V_371 | V_372 ;
if ( F_248 ( V_369 ) ) {
V_55 |= V_203 ;
V_191 = F_250 ( V_369 ) ;
}
F_232 ( & V_364 -> V_365 , V_364 -> V_184 ,
V_7 , V_191 , V_55 ) ;
}
F_106 ( V_156 ) ;
}
if ( V_364 -> V_373 && V_119 -> V_39 . V_373 ) {
struct V_9 * V_10 ;
struct V_162 V_160 ;
int V_357 = 0 , V_374 = 0 ;
bool V_185 = false ;
if ( V_364 -> V_184 == 64 ) {
memcpy ( & V_160 , & V_364 -> V_365 , 8 ) ;
if ( ! F_206 ( & V_119 -> V_71 ) ) {
F_173 ( & V_119 -> V_36 ) ;
memcpy ( V_160 . V_218 + 8 ,
V_119 -> V_71 . V_218 + 8 , 8 ) ;
F_179 ( & V_119 -> V_36 ) ;
V_185 = true ;
} else if ( F_243 ( V_119 ) &&
! F_198 ( & V_160 , 0 ,
V_119 ) ) {
V_216 |= V_290 ;
goto V_375;
} else if ( F_200 ( V_160 . V_218 + 8 , V_7 ) &&
F_229 ( V_160 . V_218 + 8 , V_119 ) ) {
F_103 ( V_119 ) ;
return;
}
goto V_375;
}
F_176 ( L_21 ,
V_364 -> V_184 ) ;
F_103 ( V_119 ) ;
return;
V_375:
V_10 = F_192 ( V_108 , & V_160 , V_7 , 1 ) ;
if ( ! V_10 && V_167 ) {
int V_298 = V_119 -> V_39 . V_298 ;
#ifdef F_162
if ( V_119 -> V_39 . V_233 &&
! V_108 -> V_18 . V_122 -> V_50 && V_362 )
V_216 |= V_230 ;
#endif
if ( ! V_298 ||
F_185 ( V_119 ) < V_298 )
V_10 = F_116 ( V_119 , & V_160 , NULL ,
V_364 -> V_184 ,
V_171 & V_376 ,
V_216 , V_167 ,
V_168 ) ;
if ( F_251 ( V_10 ) ) {
F_103 ( V_119 ) ;
return;
}
V_374 = 0 ;
V_357 = 1 ;
F_144 ( & V_10 -> V_36 ) ;
V_10 -> V_55 |= V_377 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_185 = V_185 ;
F_145 ( & V_10 -> V_36 ) ;
F_159 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_55 ;
unsigned long V_217 ;
T_1 V_378 ;
F_144 ( & V_10 -> V_36 ) ;
V_217 = V_13 ;
if ( V_10 -> V_167 > ( V_217 - V_10 -> V_75 ) / V_3 )
V_378 = V_10 -> V_167 - ( V_217 - V_10 -> V_75 ) / V_3 ;
else
V_378 = 0 ;
if ( ! V_374 && ! V_357 && V_378 ) {
const T_1 V_379 = F_156 ( T_1 ,
V_378 , V_380 ) ;
V_167 = F_252 ( V_167 , V_379 ) ;
V_374 = 1 ;
}
if ( V_374 ) {
V_10 -> V_167 = V_167 ;
V_10 -> V_168 = V_168 ;
V_10 -> V_75 = V_217 ;
V_55 = V_10 -> V_55 ;
V_10 -> V_55 &= ~ V_249 ;
F_145 ( & V_10 -> V_36 ) ;
if ( ! ( V_55 & V_144 ) )
F_152 ( 0 , V_10 ) ;
} else
F_145 ( & V_10 -> V_36 ) ;
F_241 ( V_119 , V_10 , V_167 , V_168 ,
V_357 , V_217 ) ;
F_149 ( V_10 ) ;
F_253 () ;
}
}
F_254 ( V_381 , V_119 , V_364 ) ;
F_103 ( V_119 ) ;
}
int F_255 ( struct V_108 * V_108 , void T_6 * V_382 )
{
struct V_383 V_384 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_256 () ;
V_32 = - V_385 ;
if ( F_257 ( & V_384 , V_382 , sizeof( struct V_383 ) ) )
goto V_386;
V_7 = F_75 ( V_108 , V_384 . V_387 ) ;
V_32 = - V_176 ;
if ( ! V_7 )
goto V_386;
#if F_42 ( V_59 )
if ( V_7 -> type == V_60 ) {
const struct V_388 * V_389 = V_7 -> V_390 ;
struct V_391 V_392 ;
struct V_393 V_149 ;
V_32 = - V_175 ;
if ( ! ( F_117 ( & V_384 . V_394 ) & V_232 ) )
goto V_386;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_149 . V_395 . V_271 = V_384 . V_394 . V_302 [ 3 ] ;
V_149 . V_395 . V_272 = 0 ;
V_149 . V_395 . V_396 = 4 ;
V_149 . V_395 . V_397 = 5 ;
V_149 . V_395 . V_398 = V_399 ;
V_149 . V_395 . V_400 = 64 ;
V_392 . V_401 . V_402 = ( V_403 void T_6 * ) & V_149 ;
if ( V_389 -> V_404 ) {
T_7 V_405 = F_258 () ;
F_259 ( V_406 ) ;
V_32 = V_389 -> V_404 ( V_7 , & V_392 , V_407 ) ;
F_259 ( V_405 ) ;
} else
V_32 = - V_408 ;
if ( V_32 == 0 ) {
V_32 = - V_109 ;
V_7 = F_260 ( V_108 , V_149 . V_53 ) ;
if ( ! V_7 )
goto V_386;
V_32 = F_261 ( V_7 ) ;
}
}
#endif
V_386:
F_95 () ;
return V_32 ;
}
static int F_262 ( struct V_409 * V_115 , bool V_410 ,
const struct V_162 * V_160 , int V_91 )
{
int V_215 ;
F_29 () ;
F_263 ( V_115 ) ;
if ( V_410 )
V_215 = F_264 ( V_115 , V_91 , V_160 ) ;
else
V_215 = F_265 ( V_115 , V_91 , V_160 ) ;
F_266 ( V_115 ) ;
return V_215 ;
}
static int F_267 ( struct V_108 * V_108 , int V_91 ,
const struct V_162 * V_326 ,
const struct V_162 * V_411 ,
unsigned int V_327 , V_223 V_412 ,
V_223 V_168 , V_223 V_167 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_413 ;
T_5 V_191 ;
int V_166 ;
T_1 V_55 ;
F_29 () ;
if ( V_327 > 128 )
return - V_35 ;
if ( ! V_167 || V_168 > V_167 )
return - V_35 ;
if ( V_412 & V_377 && V_327 != 64 )
return - V_35 ;
V_7 = F_75 ( V_108 , V_91 ) ;
if ( ! V_7 )
return - V_176 ;
V_5 = F_240 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return F_122 ( V_5 ) ;
if ( V_412 & V_414 ) {
int V_215 = F_262 ( V_108 -> V_18 . V_415 ,
true , V_326 , V_91 ) ;
if ( V_215 < 0 )
return V_215 ;
}
V_166 = F_158 ( V_326 ) ;
V_413 = F_137 ( V_167 , V_3 ) ;
if ( F_248 ( V_413 ) ) {
V_191 = F_250 ( V_413 * V_3 ) ;
V_167 = V_413 ;
V_55 = V_203 ;
} else {
V_191 = 0 ;
V_55 = 0 ;
V_412 |= V_195 ;
}
V_413 = F_137 ( V_168 , V_3 ) ;
if ( F_248 ( V_413 ) ) {
if ( V_413 == 0 )
V_412 |= V_249 ;
V_168 = V_413 ;
}
V_10 = F_116 ( V_5 , V_326 , V_411 , V_327 , V_166 , V_412 ,
V_167 , V_168 ) ;
if ( ! F_53 ( V_10 ) ) {
if ( ! ( V_412 & V_196 ) ) {
F_232 ( & V_10 -> V_160 , V_10 -> V_184 , V_7 ,
V_191 , V_55 ) ;
}
F_159 ( V_10 ) ;
if ( V_412 & V_377 )
F_241 ( V_5 , V_10 , V_167 , V_168 ,
true , V_13 ) ;
F_149 ( V_10 ) ;
F_268 () ;
return 0 ;
} else if ( V_412 & V_414 ) {
F_262 ( V_108 -> V_18 . V_415 ,
false , V_326 , V_91 ) ;
}
return F_122 ( V_10 ) ;
}
static int F_269 ( struct V_108 * V_108 , int V_91 , T_1 V_412 ,
const struct V_162 * V_326 , unsigned int V_327 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_327 > 128 )
return - V_35 ;
V_7 = F_75 ( V_108 , V_91 ) ;
if ( ! V_7 )
return - V_176 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_416 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_184 == V_327 &&
F_165 ( V_326 , & V_10 -> V_160 ) ) {
F_18 ( V_10 ) ;
F_179 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_55 & V_187 ) &&
( V_412 & V_377 ) )
F_241 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_143 ( V_10 ) ;
F_268 () ;
if ( F_270 ( V_326 ) ) {
F_262 ( V_108 -> V_18 . V_415 ,
false , V_326 , V_7 -> V_91 ) ;
}
return 0 ;
}
}
F_179 ( & V_5 -> V_36 ) ;
return - V_175 ;
}
int F_271 ( struct V_108 * V_108 , void T_6 * V_382 )
{
struct V_383 V_384 ;
int V_32 ;
if ( ! F_272 ( V_108 -> V_417 , V_418 ) )
return - V_419 ;
if ( F_257 ( & V_384 , V_382 , sizeof( struct V_383 ) ) )
return - V_385 ;
F_256 () ;
V_32 = F_267 ( V_108 , V_384 . V_387 , & V_384 . V_394 , NULL ,
V_384 . V_420 , V_195 ,
V_421 , V_421 ) ;
F_95 () ;
return V_32 ;
}
int F_273 ( struct V_108 * V_108 , void T_6 * V_382 )
{
struct V_383 V_384 ;
int V_32 ;
if ( ! F_272 ( V_108 -> V_417 , V_418 ) )
return - V_419 ;
if ( F_257 ( & V_384 , V_382 , sizeof( struct V_383 ) ) )
return - V_385 ;
F_256 () ;
V_32 = F_269 ( V_108 , V_384 . V_387 , 0 , & V_384 . V_394 ,
V_384 . V_420 ) ;
F_95 () ;
return V_32 ;
}
static void F_274 ( struct V_4 * V_5 , const struct V_162 * V_160 ,
int V_327 , int V_166 )
{
struct V_9 * V_10 ;
V_10 = F_116 ( V_5 , V_160 , NULL , V_327 ,
V_166 , V_195 ,
V_421 , V_421 ) ;
if ( ! F_53 ( V_10 ) ) {
F_144 ( & V_10 -> V_36 ) ;
V_10 -> V_55 &= ~ V_144 ;
F_145 ( & V_10 -> V_36 ) ;
F_152 ( V_422 , V_10 ) ;
F_149 ( V_10 ) ;
}
}
static void F_275 ( struct V_4 * V_5 )
{
struct V_162 V_160 ;
struct V_6 * V_7 ;
struct V_108 * V_108 = F_34 ( V_5 -> V_7 ) ;
int V_166 , V_327 ;
T_1 V_423 = 0 ;
F_29 () ;
memset ( & V_160 , 0 , sizeof( struct V_162 ) ) ;
memcpy ( & V_160 . V_302 [ 3 ] , V_5 -> V_7 -> V_308 , 4 ) ;
if ( V_5 -> V_7 -> V_55 & V_344 ) {
V_160 . V_302 [ 0 ] = F_199 ( 0xfe800000 ) ;
V_166 = V_278 ;
V_327 = 64 ;
} else {
V_166 = V_232 ;
V_327 = 96 ;
V_423 |= V_345 ;
}
if ( V_160 . V_302 [ 3 ] ) {
F_274 ( V_5 , & V_160 , V_327 , V_166 ) ;
F_232 ( & V_160 , V_327 , V_5 -> V_7 , 0 , V_423 ) ;
return;
}
F_91 (net, dev) {
struct V_424 * V_425 = F_276 ( V_7 ) ;
if ( V_425 && ( V_7 -> V_55 & V_82 ) ) {
struct V_426 * V_141 ;
int V_427 = V_166 ;
for ( V_141 = V_425 -> V_428 ; V_141 ; V_141 = V_141 -> V_429 ) {
V_160 . V_302 [ 3 ] = V_141 -> V_430 ;
if ( V_141 -> V_431 == V_432 )
continue;
if ( V_141 -> V_431 >= V_433 ) {
if ( V_5 -> V_7 -> V_55 & V_344 )
continue;
V_427 |= V_282 ;
}
F_274 ( V_5 , & V_160 , V_327 , V_427 ) ;
F_232 ( & V_160 , V_327 , V_5 -> V_7 , 0 ,
V_423 ) ;
}
}
}
}
static void F_277 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_434 ;
struct V_9 * V_435 ;
struct V_169 * V_436 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_22 , V_52 ) ;
return;
}
F_274 ( V_5 , & V_437 , 128 , V_282 ) ;
F_91 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_434 -> V_53 , V_7 -> V_53 ) )
continue;
V_5 = F_52 ( V_434 ) ;
if ( ! V_5 )
continue;
F_173 ( & V_5 -> V_36 ) ;
F_87 (sp_ifa, &idev->addr_list, if_list) {
if ( V_435 -> V_55 & ( V_286 | V_144 ) )
continue;
if ( V_435 -> V_156 ) {
if ( V_435 -> V_156 -> V_238 . V_438 > 0 ) {
F_106 ( V_435 -> V_156 ) ;
V_435 -> V_156 = NULL ;
} else {
continue;
}
}
V_436 = F_121 ( V_5 , & V_435 -> V_160 , false ) ;
if ( ! F_53 ( V_436 ) ) {
V_435 -> V_156 = V_436 ;
F_278 ( V_436 ) ;
}
}
F_179 ( & V_5 -> V_36 ) ;
}
}
static void F_279 ( struct V_4 * V_5 ,
const struct V_162 * V_160 , T_1 V_55 )
{
struct V_9 * V_10 ;
T_1 V_216 = V_55 | V_195 ;
#ifdef F_162
if ( V_5 -> V_39 . V_233 &&
! F_34 ( V_5 -> V_7 ) -> V_18 . V_122 -> V_50 )
V_216 |= V_230 ;
#endif
V_10 = F_116 ( V_5 , V_160 , NULL , 64 , V_278 , V_216 ,
V_421 , V_421 ) ;
if ( ! F_53 ( V_10 ) ) {
F_232 ( & V_10 -> V_160 , V_10 -> V_184 , V_5 -> V_7 , 0 , 0 ) ;
F_159 ( V_10 ) ;
F_149 ( V_10 ) ;
}
}
static bool F_280 ( struct V_162 V_439 )
{
if ( ( V_439 . V_302 [ 2 ] | V_439 . V_302 [ 3 ] ) == 0 )
return true ;
if ( V_439 . V_302 [ 2 ] == F_199 ( 0x02005eff ) &&
( ( V_439 . V_302 [ 3 ] & F_199 ( 0xfe000000 ) ) == F_199 ( 0xfe000000 ) ) )
return true ;
if ( V_439 . V_302 [ 2 ] == F_199 ( 0xfdffffff ) &&
( ( V_439 . V_302 [ 3 ] & F_199 ( 0xffffff80 ) ) == F_199 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_198 ( struct V_162 * V_439 ,
T_3 V_440 ,
const struct V_4 * V_5 )
{
static F_281 ( V_36 ) ;
static V_223 V_441 [ V_442 ] ;
static V_223 V_443 [ V_444 ] ;
static union {
char V_445 [ V_446 ] ;
struct {
struct V_162 V_447 ;
T_4 V_365 [ 2 ] ;
unsigned char V_448 [ V_449 ] ;
T_3 V_440 ;
} V_450 ;
} V_325 ;
struct V_162 V_447 ;
struct V_162 V_451 ;
struct V_108 * V_108 = F_34 ( V_5 -> V_7 ) ;
F_282 ( sizeof( V_325 . V_445 ) != sizeof( V_325 ) ) ;
if ( V_5 -> V_39 . V_41 . V_42 )
V_447 = V_5 -> V_39 . V_41 . V_447 ;
else if ( V_108 -> V_18 . V_40 -> V_41 . V_42 )
V_447 = V_108 -> V_18 . V_40 -> V_41 . V_447 ;
else
return - 1 ;
V_219:
F_144 ( & V_36 ) ;
F_283 ( V_441 ) ;
memset ( & V_325 , 0 , sizeof( V_325 ) ) ;
memset ( V_443 , 0 , sizeof( V_443 ) ) ;
memcpy ( V_325 . V_448 , V_5 -> V_7 -> V_316 , V_5 -> V_7 -> V_306 ) ;
V_325 . V_365 [ 0 ] = V_439 -> V_302 [ 0 ] ;
V_325 . V_365 [ 1 ] = V_439 -> V_302 [ 1 ] ;
V_325 . V_447 = V_447 ;
V_325 . V_440 = V_440 ;
F_284 ( V_441 , V_325 . V_445 , V_443 ) ;
V_451 = * V_439 ;
V_451 . V_302 [ 2 ] = ( V_403 T_4 ) V_441 [ 0 ] ;
V_451 . V_302 [ 3 ] = ( V_403 T_4 ) V_441 [ 1 ] ;
F_145 ( & V_36 ) ;
if ( F_280 ( V_451 ) ) {
V_440 ++ ;
if ( V_440 > F_34 ( V_5 -> V_7 ) -> V_18 . V_47 . V_296 )
return - 1 ;
goto V_219;
}
* V_439 = V_451 ;
return 0 ;
}
static void F_285 ( struct V_4 * V_5 )
{
struct V_452 * V_453 = & V_5 -> V_39 . V_41 ;
if ( V_453 -> V_42 )
return;
V_453 = & V_5 -> V_39 . V_41 ;
F_231 ( & V_453 -> V_447 , sizeof( V_453 -> V_447 ) ) ;
V_453 -> V_42 = true ;
}
static void F_286 ( struct V_4 * V_5 , bool V_454 )
{
struct V_162 V_160 ;
if ( F_287 ( V_5 -> V_7 ) )
return;
F_239 ( & V_160 , F_199 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
switch ( V_5 -> V_43 ) {
case V_360 :
F_285 ( V_5 ) ;
case V_44 :
if ( ! F_198 ( & V_160 , 0 , V_5 ) )
F_279 ( V_5 , & V_160 ,
V_290 ) ;
else if ( V_454 )
F_232 ( & V_160 , 64 , V_5 -> V_7 , 0 , 0 ) ;
break;
case V_45 :
if ( F_200 ( V_160 . V_218 + 8 , V_5 -> V_7 ) == 0 )
F_279 ( V_5 , & V_160 , 0 ) ;
else if ( V_454 )
F_232 ( & V_160 , 64 , V_5 -> V_7 , 0 , 0 ) ;
break;
case V_455 :
default:
break;
}
}
static void F_288 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_317 ) &&
( V_7 -> type != V_318 ) &&
( V_7 -> type != V_319 ) &&
( V_7 -> type != V_320 ) &&
( V_7 -> type != V_323 ) &&
( V_7 -> type != V_68 ) &&
( V_7 -> type != V_322 ) &&
( V_7 -> type != V_69 ) ) {
return;
}
V_5 = F_240 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return;
if ( V_7 -> type == V_69 &&
V_5 -> V_43 == V_45 )
V_5 -> V_43 = V_360 ;
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
if ( V_7 -> V_55 & V_344 )
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
if ( V_7 -> V_55 & V_344 )
F_238 ( V_7 ) ;
}
static int F_291 ( struct V_456 * V_457 , unsigned long V_96 ,
void * V_458 )
{
struct V_6 * V_7 = F_292 ( V_458 ) ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
int V_459 = 0 ;
int V_32 ;
switch ( V_96 ) {
case V_460 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return F_293 ( F_122 ( V_5 ) ) ;
}
break;
case V_461 :
if ( V_7 -> V_33 < V_34 ) {
F_294 ( V_7 , 1 ) ;
break;
}
if ( V_5 ) {
F_295 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_46 = V_7 -> V_33 ;
break;
}
V_5 = F_28 ( V_7 ) ;
if ( F_53 ( V_5 ) )
break;
if ( ! ( V_5 -> V_73 & V_74 ) )
break;
V_459 = 1 ;
case V_189 :
case V_462 :
if ( V_7 -> V_55 & V_463 )
break;
if ( V_5 && V_5 -> V_39 . V_178 )
break;
if ( V_96 == V_189 ) {
if ( ! F_4 ( V_7 ) ) {
F_43 ( L_23 ,
V_7 -> V_53 ) ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 )
V_5 = F_28 ( V_7 ) ;
if ( ! F_251 ( V_5 ) ) {
V_5 -> V_73 |= V_74 ;
V_459 = 1 ;
}
} else if ( V_96 == V_462 ) {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_73 & V_74 )
break;
V_5 -> V_73 |= V_74 ;
}
F_43 ( L_24 ,
V_7 -> V_53 ) ;
V_459 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_59 )
case V_60 :
F_289 ( V_7 ) ;
break;
#endif
#if F_42 ( V_464 )
case V_321 :
F_290 ( V_7 ) ;
break;
#endif
case V_465 :
F_277 ( V_7 ) ;
break;
default:
F_288 ( V_7 ) ;
break;
}
if ( ! F_251 ( V_5 ) ) {
if ( V_459 )
F_296 ( V_5 ) ;
if ( V_5 -> V_39 . V_46 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_295 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_46 = V_7 -> V_33 ;
}
V_5 -> V_75 = V_13 ;
F_297 ( V_466 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_294 ( V_7 , 1 ) ;
}
break;
case V_206 :
case V_467 :
F_294 ( V_7 , V_96 != V_206 ) ;
break;
case V_468 :
if ( V_5 ) {
F_47 ( V_5 ) ;
F_3 ( V_5 ) ;
V_32 = F_2 ( V_5 ) ;
if ( V_32 )
return F_293 ( V_32 ) ;
V_32 = F_41 ( V_5 ) ;
if ( V_32 ) {
F_3 ( V_5 ) ;
return F_293 ( V_32 ) ;
}
}
break;
case V_469 :
case V_470 :
if ( V_5 )
F_298 ( V_7 , V_96 ) ;
break;
}
return V_471 ;
}
static void F_298 ( struct V_6 * V_7 , unsigned long V_96 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_96 == V_470 )
F_299 ( V_5 ) ;
else if ( V_96 == V_469 )
F_300 ( V_5 ) ;
}
static int F_294 ( struct V_6 * V_7 , int V_472 )
{
struct V_108 * V_108 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_141 ;
int V_154 , V_16 ;
F_29 () ;
F_301 ( V_108 , V_7 ) ;
F_302 ( & V_49 , V_7 ) ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_176 ;
if ( V_472 ) {
V_5 -> V_81 = 1 ;
F_303 ( V_7 -> V_76 , NULL ) ;
F_47 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_473 ; V_16 ++ ) {
struct V_131 * V_127 = & V_186 [ V_16 ] ;
F_144 ( & V_180 ) ;
V_474:
F_81 (ifa, h, addr_lst) {
if ( V_141 -> V_5 == V_5 ) {
F_146 ( & V_141 -> V_153 ) ;
F_9 ( V_141 ) ;
goto V_474;
}
}
F_145 ( & V_180 ) ;
}
F_147 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_472 )
V_5 -> V_73 &= ~ ( V_475 | V_476 | V_74 ) ;
if ( V_472 && F_7 ( & V_5 -> V_65 ) )
F_103 ( V_5 ) ;
while ( ! F_242 ( & V_5 -> V_64 ) ) {
V_141 = F_304 ( & V_5 -> V_64 ,
struct V_9 , V_188 ) ;
F_148 ( & V_141 -> V_188 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_144 ( & V_141 -> V_36 ) ;
if ( V_141 -> V_204 ) {
F_149 ( V_141 -> V_204 ) ;
V_141 -> V_204 = NULL ;
}
F_145 ( & V_141 -> V_36 ) ;
F_149 ( V_141 ) ;
F_147 ( & V_5 -> V_36 ) ;
}
while ( ! F_242 ( & V_5 -> V_37 ) ) {
V_141 = F_304 ( & V_5 -> V_37 ,
struct V_9 , V_161 ) ;
F_9 ( V_141 ) ;
F_148 ( & V_141 -> V_161 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_144 ( & V_141 -> V_36 ) ;
V_154 = V_141 -> V_154 ;
V_141 -> V_154 = V_155 ;
F_145 ( & V_141 -> V_36 ) ;
if ( V_154 != V_155 ) {
F_305 ( V_205 , V_141 ) ;
F_134 ( V_206 , V_141 ) ;
}
F_149 ( V_141 ) ;
F_147 ( & V_5 -> V_36 ) ;
}
F_151 ( & V_5 -> V_36 ) ;
if ( V_472 ) {
F_306 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_307 ( V_5 ) ;
}
V_5 -> V_75 = V_13 ;
if ( V_472 ) {
F_3 ( V_5 ) ;
F_39 ( & V_49 , V_5 -> V_48 ) ;
F_302 ( & V_49 , V_7 ) ;
F_103 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_325 )
{
struct V_4 * V_5 = (struct V_4 * ) V_325 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_162 V_477 ;
F_129 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_81 || ! ( V_5 -> V_73 & V_74 ) )
goto V_182;
if ( ! F_308 ( V_5 ) )
goto V_182;
if ( V_5 -> V_73 & V_476 )
goto V_182;
if ( V_5 -> V_478 ++ < V_5 -> V_39 . V_63 ) {
F_131 ( & V_5 -> V_36 ) ;
if ( ! F_184 ( V_7 , & V_477 , V_144 ) )
F_309 ( V_7 , & V_477 ,
& V_80 ) ;
else
goto V_479;
F_129 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_478 ==
V_5 -> V_39 . V_63 ) ?
V_5 -> V_39 . V_480 :
V_5 -> V_39 . V_481 ) ;
} else {
F_102 ( L_25 , V_5 -> V_7 -> V_53 ) ;
}
V_182:
F_131 ( & V_5 -> V_36 ) ;
V_479:
F_103 ( V_5 ) ;
}
static void F_310 ( struct V_9 * V_10 )
{
unsigned long V_482 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_55 & V_230 )
V_482 = 0 ;
else
V_482 = F_311 () % ( V_5 -> V_39 . V_480 ? : 1 ) ;
V_10 -> V_483 = V_5 -> V_39 . V_227 ;
F_16 ( V_10 , V_482 ) ;
}
static void F_312 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_484 = false ;
F_201 ( V_7 , & V_10 -> V_160 ) ;
F_313 ( ( V_403 T_1 ) V_10 -> V_160 . V_302 [ 3 ] ) ;
F_173 ( & V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_154 == V_155 )
goto V_182;
if ( V_7 -> V_55 & ( V_56 | V_57 ) ||
V_5 -> V_39 . V_58 < 1 ||
! ( V_10 -> V_55 & V_144 ) ||
V_10 -> V_55 & V_485 ) {
V_10 -> V_55 &= ~ ( V_144 | V_230 | V_286 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
F_314 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_73 & V_74 ) ) {
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
F_18 ( V_10 ) ;
F_194 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_55 & V_230 ) {
F_278 ( V_10 -> V_156 ) ;
if ( F_161 ( V_5 ) ) {
V_484 = true ;
}
}
F_310 ( V_10 ) ;
V_182:
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
if ( V_484 )
F_152 ( V_422 , V_10 ) ;
}
static void F_159 ( struct V_9 * V_10 )
{
bool V_486 = false ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_154 != V_155 ) {
V_10 -> V_154 = V_300 ;
V_486 = true ;
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_486 )
F_16 ( V_10 , 0 ) ;
}
static void V_183 ( struct V_487 * V_488 )
{
struct V_9 * V_10 = F_315 ( F_316 ( V_488 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_162 V_489 ;
enum {
V_490 ,
V_491 ,
V_492 ,
} V_193 = V_490 ;
F_256 () ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_154 == V_300 ) {
V_193 = V_491 ;
V_10 -> V_154 = V_288 ;
} else if ( V_10 -> V_154 == V_303 ) {
V_193 = V_492 ;
V_10 -> V_154 = V_289 ;
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_193 == V_491 ) {
F_312 ( V_10 ) ;
goto V_182;
} else if ( V_193 == V_492 ) {
F_194 ( V_10 , 1 ) ;
goto V_182;
}
if ( ! V_10 -> V_483 && F_195 ( V_10 ) )
goto V_182;
F_147 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_81 || ! ( V_5 -> V_73 & V_74 ) ) {
F_151 ( & V_5 -> V_36 ) ;
goto V_182;
}
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_154 == V_155 ) {
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
goto V_182;
}
if ( V_10 -> V_483 == 0 ) {
V_10 -> V_55 &= ~ ( V_144 | V_230 | V_286 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_314 ( V_10 ) ;
goto V_182;
}
V_10 -> V_483 -- ;
F_16 ( V_10 ,
F_157 ( V_10 -> V_5 -> V_48 , V_228 ) ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_202 ( & V_10 -> V_160 , & V_489 ) ;
F_317 ( V_10 -> V_5 -> V_7 , & V_10 -> V_160 , & V_489 , & V_72 ) ;
V_182:
F_149 ( V_10 ) ;
F_95 () ;
}
static bool F_318 ( struct V_9 * V_10 )
{
struct V_9 * V_493 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_183 (ifpiter, &idev->addr_list, if_list) {
if ( V_493 -> V_166 > V_278 )
break;
if ( V_10 != V_493 && V_493 -> V_166 == V_278 &&
( V_493 -> V_55 & ( V_195 | V_144 |
V_230 | V_286 ) ) ==
V_195 )
return false ;
}
return true ;
}
static void F_314 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_162 V_477 ;
bool V_494 , V_495 ;
F_9 ( V_10 ) ;
F_152 ( V_422 , V_10 ) ;
F_173 ( & V_10 -> V_5 -> V_36 ) ;
V_495 = V_10 -> V_166 == V_278 && F_318 ( V_10 ) ;
V_494 = V_495 &&
F_308 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_63 > 0 &&
( V_7 -> V_55 & V_57 ) == 0 ;
F_179 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_495 )
F_319 ( V_10 -> V_5 ) ;
if ( V_494 ) {
if ( F_184 ( V_7 , & V_477 , V_144 ) )
return;
F_309 ( V_7 , & V_477 , & V_80 ) ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_478 = 1 ;
V_10 -> V_5 -> V_73 |= V_475 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_481 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_296 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list) {
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_55 & V_144 &&
V_10 -> V_154 == V_288 )
F_310 ( V_10 ) ;
F_128 ( & V_10 -> V_36 ) ;
}
F_179 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_320 ( struct V_496 * V_95 , T_8 V_497 )
{
struct V_9 * V_141 = NULL ;
struct V_498 * V_154 = V_95 -> V_499 ;
struct V_108 * V_108 = F_321 ( V_95 ) ;
int V_149 = 0 ;
if ( V_497 == 0 ) {
V_154 -> V_500 = 0 ;
V_154 -> V_501 = 0 ;
}
for (; V_154 -> V_500 < V_473 ; ++ V_154 -> V_500 ) {
F_193 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_188 ( F_34 ( V_141 -> V_5 -> V_7 ) , V_108 ) )
continue;
if ( V_149 < V_154 -> V_501 ) {
V_149 ++ ;
continue;
}
V_154 -> V_501 ++ ;
return V_141 ;
}
V_154 -> V_501 = 0 ;
V_149 = 0 ;
}
return NULL ;
}
static struct V_9 * F_322 ( struct V_496 * V_95 ,
struct V_9 * V_141 )
{
struct V_498 * V_154 = V_95 -> V_499 ;
struct V_108 * V_108 = F_321 ( V_95 ) ;
F_323 (ifa, addr_lst) {
if ( ! F_188 ( F_34 ( V_141 -> V_5 -> V_7 ) , V_108 ) )
continue;
V_154 -> V_501 ++ ;
return V_141 ;
}
while ( ++ V_154 -> V_500 < V_473 ) {
V_154 -> V_501 = 0 ;
F_193 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_188 ( F_34 ( V_141 -> V_5 -> V_7 ) , V_108 ) )
continue;
V_154 -> V_501 ++ ;
return V_141 ;
}
}
return NULL ;
}
static void * F_324 ( struct V_496 * V_95 , T_8 * V_497 )
__acquires( T_9 )
{
F_118 () ;
return F_320 ( V_95 , * V_497 ) ;
}
static void * F_325 ( struct V_496 * V_95 , void * V_502 , T_8 * V_497 )
{
struct V_9 * V_141 ;
V_141 = F_322 ( V_95 , V_502 ) ;
++ * V_497 ;
return V_141 ;
}
static void F_326 ( struct V_496 * V_95 , void * V_502 )
__releases( T_9 )
{
F_132 () ;
}
static int F_327 ( struct V_496 * V_95 , void * V_502 )
{
struct V_9 * V_10 = (struct V_9 * ) V_502 ;
F_328 ( V_95 , L_26 ,
& V_10 -> V_160 ,
V_10 -> V_5 -> V_7 -> V_91 ,
V_10 -> V_184 ,
V_10 -> V_166 ,
( T_3 ) V_10 -> V_55 ,
V_10 -> V_5 -> V_7 -> V_53 ) ;
return 0 ;
}
static int F_329 ( struct V_503 * V_503 , struct V_504 * V_504 )
{
return F_330 ( V_503 , V_504 , & V_505 ,
sizeof( struct V_498 ) ) ;
}
static int T_10 F_331 ( struct V_108 * V_108 )
{
if ( ! F_332 ( L_27 , V_506 , V_108 -> V_507 , & V_508 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_333 ( struct V_108 * V_108 )
{
F_334 ( L_27 , V_108 -> V_507 ) ;
}
int T_12 F_335 ( void )
{
return F_336 ( & V_509 ) ;
}
void F_337 ( void )
{
F_338 ( & V_509 ) ;
}
int F_339 ( struct V_108 * V_108 , const struct V_162 * V_160 )
{
int V_215 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_170 = F_113 ( V_160 ) ;
F_118 () ;
F_193 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_108 ) )
continue;
if ( F_165 ( & V_10 -> V_160 , V_160 ) &&
( V_10 -> V_55 & V_254 ) ) {
V_215 = 1 ;
break;
}
}
F_132 () ;
return V_215 ;
}
static void F_268 ( void )
{
unsigned long V_217 , V_510 , V_511 , V_512 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_118 () ;
V_217 = V_13 ;
V_510 = F_340 ( V_217 + V_513 ) ;
F_10 ( & V_514 ) ;
for ( V_16 = 0 ; V_16 < V_473 ; V_16 ++ ) {
V_474:
F_193 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_212 ;
if ( ( V_10 -> V_55 & V_195 ) &&
( V_10 -> V_168 == V_421 ) )
continue;
F_119 ( & V_10 -> V_36 ) ;
V_212 = ( V_217 - V_10 -> V_75 + V_229 ) / V_3 ;
if ( V_10 -> V_167 != V_421 &&
V_212 >= V_10 -> V_167 ) {
F_128 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_143 ( V_10 ) ;
goto V_474;
} else if ( V_10 -> V_168 == V_421 ) {
F_128 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_212 >= V_10 -> V_168 ) {
int V_515 = 0 ;
if ( ! ( V_10 -> V_55 & V_249 ) ) {
V_515 = 1 ;
V_10 -> V_55 |= V_249 ;
}
if ( ( V_10 -> V_167 != V_421 ) &&
( F_138 ( V_10 -> V_75 + V_10 -> V_167 * V_3 , V_510 ) ) )
V_510 = V_10 -> V_75 + V_10 -> V_167 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
if ( V_515 ) {
F_18 ( V_10 ) ;
F_152 ( 0 , V_10 ) ;
F_149 ( V_10 ) ;
goto V_474;
}
} else if ( ( V_10 -> V_55 & V_187 ) &&
! ( V_10 -> V_55 & V_144 ) ) {
unsigned long V_213 = V_10 -> V_5 -> V_39 . V_221 *
V_10 -> V_5 -> V_39 . V_227 *
F_157 ( V_10 -> V_5 -> V_48 , V_228 ) / V_3 ;
if ( V_212 >= V_10 -> V_168 - V_213 ) {
struct V_9 * V_204 = V_10 -> V_204 ;
if ( F_138 ( V_10 -> V_75 + V_10 -> V_168 * V_3 , V_510 ) )
V_510 = V_10 -> V_75 + V_10 -> V_168 * V_3 ;
if ( ! V_10 -> V_220 && V_204 ) {
V_10 -> V_220 ++ ;
F_18 ( V_10 ) ;
F_18 ( V_204 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_119 ( & V_204 -> V_36 ) ;
V_204 -> V_220 = 0 ;
F_128 ( & V_204 -> V_36 ) ;
F_154 ( V_204 , V_10 ) ;
F_149 ( V_204 ) ;
F_149 ( V_10 ) ;
goto V_474;
}
} else if ( F_138 ( V_10 -> V_75 + V_10 -> V_168 * V_3 - V_213 * V_3 , V_510 ) )
V_510 = V_10 -> V_75 + V_10 -> V_168 * V_3 - V_213 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
} else {
if ( F_138 ( V_10 -> V_75 + V_10 -> V_168 * V_3 , V_510 ) )
V_510 = V_10 -> V_75 + V_10 -> V_168 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
}
}
}
V_511 = F_340 ( V_510 ) ;
V_512 = V_510 ;
if ( F_138 ( V_511 , V_510 + V_516 ) )
V_512 = V_511 ;
if ( F_138 ( V_512 , V_13 + V_517 ) )
V_512 = V_13 + V_517 ;
F_38 ( V_518 L_28 ,
V_217 , V_510 , V_511 , V_512 ) ;
F_19 ( V_15 , & V_514 , V_512 - V_217 ) ;
F_132 () ;
}
static void F_341 ( struct V_487 * V_488 )
{
F_256 () ;
F_268 () ;
F_95 () ;
}
static void F_253 ( void )
{
F_19 ( V_15 , & V_514 , 0 ) ;
}
static struct V_162 * F_342 ( struct V_116 * V_160 , struct V_116 * V_519 ,
struct V_162 * * V_411 )
{
struct V_162 * V_326 = NULL ;
* V_411 = NULL ;
if ( V_160 )
V_326 = F_343 ( V_160 ) ;
if ( V_519 ) {
if ( V_326 && F_344 ( V_519 , V_326 , sizeof( * V_326 ) ) )
* V_411 = V_326 ;
V_326 = F_343 ( V_519 ) ;
}
return V_326 ;
}
static int
F_345 ( struct V_89 * V_90 , struct V_97 * V_98 )
{
struct V_108 * V_108 = F_72 ( V_90 -> V_115 ) ;
struct V_520 * V_521 ;
struct V_116 * V_117 [ V_522 + 1 ] ;
struct V_162 * V_326 , * V_411 ;
T_1 V_412 ;
int V_32 ;
V_32 = F_73 ( V_98 , sizeof( * V_521 ) , V_117 , V_522 , V_523 ) ;
if ( V_32 < 0 )
return V_32 ;
V_521 = F_61 ( V_98 ) ;
V_326 = F_342 ( V_117 [ V_524 ] , V_117 [ V_525 ] , & V_411 ) ;
if ( ! V_326 )
return - V_35 ;
V_412 = V_117 [ V_526 ] ? F_346 ( V_117 [ V_526 ] ) : V_521 -> V_412 ;
V_412 &= V_377 ;
return F_269 ( V_108 , V_521 -> V_527 , V_412 , V_326 ,
V_521 -> V_528 ) ;
}
static int F_347 ( struct V_9 * V_10 , T_1 V_412 ,
T_1 V_168 , T_1 V_167 )
{
T_1 V_55 ;
T_5 V_191 ;
unsigned long V_413 ;
bool V_529 ;
bool V_530 ;
F_29 () ;
if ( ! V_167 || ( V_168 > V_167 ) )
return - V_35 ;
if ( V_412 & V_377 &&
( V_10 -> V_55 & V_187 || V_10 -> V_184 != 64 ) )
return - V_35 ;
V_413 = F_137 ( V_167 , V_3 ) ;
if ( F_248 ( V_413 ) ) {
V_191 = F_250 ( V_413 * V_3 ) ;
V_167 = V_413 ;
V_55 = V_203 ;
} else {
V_191 = 0 ;
V_55 = 0 ;
V_412 |= V_195 ;
}
V_413 = F_137 ( V_168 , V_3 ) ;
if ( F_248 ( V_413 ) ) {
if ( V_413 == 0 )
V_412 |= V_249 ;
V_168 = V_413 ;
}
F_144 ( & V_10 -> V_36 ) ;
V_529 = V_10 -> V_55 & V_377 ;
V_530 = V_10 -> V_55 & V_195 &&
! ( V_10 -> V_55 & V_196 ) ;
V_10 -> V_55 &= ~ ( V_249 | V_195 | V_485 |
V_254 | V_377 |
V_196 ) ;
V_10 -> V_55 |= V_412 ;
V_10 -> V_75 = V_13 ;
V_10 -> V_167 = V_167 ;
V_10 -> V_168 = V_168 ;
F_145 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_55 & V_144 ) )
F_152 ( 0 , V_10 ) ;
if ( ! ( V_412 & V_196 ) ) {
F_232 ( & V_10 -> V_160 , V_10 -> V_184 , V_10 -> V_5 -> V_7 ,
V_191 , V_55 ) ;
} else if ( V_530 ) {
enum V_190 V_193 ;
unsigned long V_369 ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
V_193 = F_135 ( V_10 , & V_369 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_193 != V_197 ) {
F_139 ( V_10 , V_369 ,
V_193 == V_194 ) ;
}
}
if ( V_529 || V_10 -> V_55 & V_377 ) {
if ( V_529 && ! ( V_10 -> V_55 & V_377 ) )
V_167 = V_168 = 0 ;
F_241 ( V_10 -> V_5 , V_10 , V_167 , V_168 ,
! V_529 , V_13 ) ;
}
F_268 () ;
return 0 ;
}
static int
F_348 ( struct V_89 * V_90 , struct V_97 * V_98 )
{
struct V_108 * V_108 = F_72 ( V_90 -> V_115 ) ;
struct V_520 * V_521 ;
struct V_116 * V_117 [ V_522 + 1 ] ;
struct V_162 * V_326 , * V_411 ;
struct V_9 * V_141 ;
struct V_6 * V_7 ;
T_1 V_167 = V_421 , V_293 = V_421 ;
T_1 V_412 ;
int V_32 ;
V_32 = F_73 ( V_98 , sizeof( * V_521 ) , V_117 , V_522 , V_523 ) ;
if ( V_32 < 0 )
return V_32 ;
V_521 = F_61 ( V_98 ) ;
V_326 = F_342 ( V_117 [ V_524 ] , V_117 [ V_525 ] , & V_411 ) ;
if ( ! V_326 )
return - V_35 ;
if ( V_117 [ V_531 ] ) {
struct V_532 * V_533 ;
V_533 = F_343 ( V_117 [ V_531 ] ) ;
V_167 = V_533 -> V_534 ;
V_293 = V_533 -> V_535 ;
} else {
V_293 = V_421 ;
V_167 = V_421 ;
}
V_7 = F_75 ( V_108 , V_521 -> V_527 ) ;
if ( ! V_7 )
return - V_176 ;
V_412 = V_117 [ V_526 ] ? F_346 ( V_117 [ V_526 ] ) : V_521 -> V_412 ;
V_412 &= V_485 | V_254 | V_377 |
V_196 | V_414 ;
V_141 = F_192 ( V_108 , V_326 , V_7 , 1 ) ;
if ( ! V_141 ) {
return F_267 ( V_108 , V_521 -> V_527 , V_326 , V_411 ,
V_521 -> V_528 , V_412 ,
V_293 , V_167 ) ;
}
if ( V_98 -> V_536 & V_537 ||
! ( V_98 -> V_536 & V_538 ) )
V_32 = - V_181 ;
else
V_32 = F_347 ( V_141 , V_412 , V_293 , V_167 ) ;
F_149 ( V_141 ) ;
return V_32 ;
}
static void F_349 ( struct V_97 * V_98 , T_3 V_539 , T_1 V_55 ,
T_3 V_166 , int V_91 )
{
struct V_520 * V_521 ;
V_521 = F_61 ( V_98 ) ;
V_521 -> V_540 = V_102 ;
V_521 -> V_528 = V_539 ;
V_521 -> V_412 = V_55 ;
V_521 -> V_431 = V_166 ;
V_521 -> V_527 = V_91 ;
}
static int F_350 ( struct V_89 * V_90 , unsigned long V_1 ,
unsigned long V_75 , T_1 V_541 , T_1 V_367 )
{
struct V_532 V_533 ;
V_533 . V_1 = F_1 ( V_1 ) ;
V_533 . V_75 = F_1 ( V_75 ) ;
V_533 . V_535 = V_541 ;
V_533 . V_534 = V_367 ;
return F_351 ( V_90 , V_531 , sizeof( V_533 ) , & V_533 ) ;
}
static inline int F_352 ( int V_431 )
{
if ( V_431 & V_282 )
return V_433 ;
else if ( V_431 & V_278 )
return V_432 ;
else if ( V_431 & V_542 )
return V_543 ;
else
return V_544 ;
}
static inline int F_353 ( void )
{
return F_56 ( sizeof( struct V_520 ) )
+ F_57 ( 16 )
+ F_57 ( 16 )
+ F_57 ( sizeof( struct V_532 ) )
+ F_57 ( 4 ) ;
}
static int F_354 ( struct V_89 * V_90 , struct V_9 * V_141 ,
T_1 V_94 , T_1 V_95 , int V_96 , unsigned int V_55 )
{
struct V_97 * V_98 ;
T_1 V_541 , V_367 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( struct V_520 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
F_349 ( V_98 , V_141 -> V_184 , V_141 -> V_55 , F_352 ( V_141 -> V_166 ) ,
V_141 -> V_5 -> V_7 -> V_91 ) ;
if ( ! ( ( V_141 -> V_55 & V_195 ) &&
( V_141 -> V_168 == V_421 ) ) ) {
V_541 = V_141 -> V_168 ;
V_367 = V_141 -> V_167 ;
if ( V_541 != V_421 ) {
long V_545 = ( V_13 - V_141 -> V_75 ) / V_3 ;
if ( V_541 > V_545 )
V_541 -= V_545 ;
else
V_541 = 0 ;
if ( V_367 != V_421 ) {
if ( V_367 > V_545 )
V_367 -= V_545 ;
else
V_367 = 0 ;
}
}
} else {
V_541 = V_421 ;
V_367 = V_421 ;
}
if ( ! F_206 ( & V_141 -> V_164 ) ) {
if ( F_355 ( V_90 , V_525 , & V_141 -> V_160 ) < 0 ||
F_355 ( V_90 , V_524 , & V_141 -> V_164 ) < 0 )
goto error;
} else
if ( F_355 ( V_90 , V_524 , & V_141 -> V_160 ) < 0 )
goto error;
if ( F_350 ( V_90 , V_141 -> V_1 , V_141 -> V_75 , V_541 , V_367 ) < 0 )
goto error;
if ( F_356 ( V_90 , V_526 , V_141 -> V_55 ) < 0 )
goto error;
F_63 ( V_90 , V_98 ) ;
return 0 ;
error:
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
static int F_357 ( struct V_89 * V_90 , struct V_546 * V_547 ,
T_1 V_94 , T_1 V_95 , int V_96 , T_13 V_55 )
{
struct V_97 * V_98 ;
T_3 V_166 = V_544 ;
int V_91 = V_547 -> V_5 -> V_7 -> V_91 ;
if ( F_158 ( & V_547 -> V_548 ) & V_542 )
V_166 = V_543 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( struct V_520 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
F_349 ( V_98 , 128 , V_195 , V_166 , V_91 ) ;
if ( F_355 ( V_90 , V_549 , & V_547 -> V_548 ) < 0 ||
F_350 ( V_90 , V_547 -> V_550 , V_547 -> V_551 ,
V_421 , V_421 ) < 0 ) {
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
F_63 ( V_90 , V_98 ) ;
return 0 ;
}
static int F_358 ( struct V_89 * V_90 , struct V_552 * V_553 ,
T_1 V_94 , T_1 V_95 , int V_96 , unsigned int V_55 )
{
struct V_97 * V_98 ;
T_3 V_166 = V_544 ;
int V_91 = V_553 -> V_554 -> V_7 -> V_91 ;
if ( F_158 ( & V_553 -> V_555 ) & V_542 )
V_166 = V_543 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( struct V_520 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
F_349 ( V_98 , 128 , V_195 , V_166 , V_91 ) ;
if ( F_355 ( V_90 , V_556 , & V_553 -> V_555 ) < 0 ||
F_350 ( V_90 , V_553 -> V_557 , V_553 -> V_558 ,
V_421 , V_421 ) < 0 ) {
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
F_63 ( V_90 , V_98 ) ;
return 0 ;
}
static int F_359 ( struct V_4 * V_5 , struct V_89 * V_90 ,
struct V_125 * V_126 , enum V_559 type ,
int V_560 , int * V_561 )
{
struct V_546 * V_547 ;
struct V_552 * V_553 ;
int V_32 = 1 ;
int V_562 = * V_561 ;
F_173 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_563 : {
struct V_9 * V_141 ;
F_87 (ifa, &idev->addr_list, if_list) {
if ( ++ V_562 < V_560 )
continue;
V_32 = F_354 ( V_90 , V_141 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_422 ,
V_138 ) ;
if ( V_32 < 0 )
break;
F_83 ( V_126 , F_84 ( V_90 ) ) ;
}
break;
}
case V_564 :
for ( V_547 = V_5 -> V_565 ; V_547 ;
V_547 = V_547 -> V_510 , V_562 ++ ) {
if ( V_562 < V_560 )
continue;
V_32 = F_357 ( V_90 , V_547 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_566 ,
V_138 ) ;
if ( V_32 < 0 )
break;
}
break;
case V_567 :
for ( V_553 = V_5 -> V_568 ; V_553 ;
V_553 = V_553 -> V_569 , V_562 ++ ) {
if ( V_562 < V_560 )
continue;
V_32 = F_358 ( V_90 , V_553 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_570 ,
V_138 ) ;
if ( V_32 < 0 )
break;
}
break;
default:
break;
}
F_179 ( & V_5 -> V_36 ) ;
* V_561 = V_562 ;
return V_32 ;
}
static int F_360 ( struct V_89 * V_90 , struct V_125 * V_126 ,
enum V_559 type )
{
struct V_108 * V_108 = F_72 ( V_90 -> V_115 ) ;
int V_127 , V_128 ;
int V_129 , V_562 ;
int V_130 , V_560 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_131 * V_132 ;
V_128 = V_126 -> args [ 0 ] ;
V_130 = V_129 = V_126 -> args [ 1 ] ;
V_560 = V_562 = V_126 -> args [ 2 ] ;
F_79 () ;
V_126 -> V_95 = F_80 ( & V_108 -> V_18 . V_135 ) ^ V_108 -> V_136 ;
for ( V_127 = V_128 ; V_127 < V_133 ; V_127 ++ , V_130 = 0 ) {
V_129 = 0 ;
V_132 = & V_108 -> V_134 [ V_127 ] ;
F_81 (dev, head, index_hlist) {
if ( V_129 < V_130 )
goto V_137;
if ( V_127 > V_128 || V_129 > V_130 )
V_560 = 0 ;
V_562 = 0 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_137;
if ( F_359 ( V_5 , V_90 , V_126 , type ,
V_560 , & V_562 ) < 0 )
goto V_139;
V_137:
V_129 ++ ;
}
}
V_139:
F_82 () ;
V_126 -> args [ 0 ] = V_127 ;
V_126 -> args [ 1 ] = V_129 ;
V_126 -> args [ 2 ] = V_562 ;
return V_90 -> V_140 ;
}
static int F_361 ( struct V_89 * V_90 , struct V_125 * V_126 )
{
enum V_559 type = V_563 ;
return F_360 ( V_90 , V_126 , type ) ;
}
static int F_362 ( struct V_89 * V_90 , struct V_125 * V_126 )
{
enum V_559 type = V_564 ;
return F_360 ( V_90 , V_126 , type ) ;
}
static int F_363 ( struct V_89 * V_90 , struct V_125 * V_126 )
{
enum V_559 type = V_567 ;
return F_360 ( V_90 , V_126 , type ) ;
}
static int F_364 ( struct V_89 * V_114 , struct V_97 * V_98 )
{
struct V_108 * V_108 = F_72 ( V_114 -> V_115 ) ;
struct V_520 * V_521 ;
struct V_116 * V_117 [ V_522 + 1 ] ;
struct V_162 * V_160 = NULL , * V_571 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_141 ;
struct V_89 * V_90 ;
int V_32 ;
V_32 = F_73 ( V_98 , sizeof( * V_521 ) , V_117 , V_522 , V_523 ) ;
if ( V_32 < 0 )
goto V_111;
V_160 = F_342 ( V_117 [ V_524 ] , V_117 [ V_525 ] , & V_571 ) ;
if ( ! V_160 ) {
V_32 = - V_35 ;
goto V_111;
}
V_521 = F_61 ( V_98 ) ;
if ( V_521 -> V_527 )
V_7 = F_75 ( V_108 , V_521 -> V_527 ) ;
V_141 = F_192 ( V_108 , V_160 , V_7 , 1 ) ;
if ( ! V_141 ) {
V_32 = - V_175 ;
goto V_111;
}
V_90 = F_66 ( F_353 () , V_25 ) ;
if ( ! V_90 ) {
V_32 = - V_109 ;
goto V_572;
}
V_32 = F_354 ( V_90 , V_141 , F_76 ( V_114 ) . V_94 ,
V_98 -> V_124 , V_422 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_572;
}
V_32 = F_77 ( V_90 , V_108 , F_76 ( V_114 ) . V_94 ) ;
V_572:
F_149 ( V_141 ) ;
V_111:
return V_32 ;
}
static void F_365 ( int V_96 , struct V_9 * V_141 )
{
struct V_89 * V_90 ;
struct V_108 * V_108 = F_34 ( V_141 -> V_5 -> V_7 ) ;
int V_32 = - V_109 ;
V_90 = F_66 ( F_353 () , V_110 ) ;
if ( ! V_90 )
goto V_111;
V_32 = F_354 ( V_90 , V_141 , 0 , 0 , V_96 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_111;
}
F_69 ( V_90 , V_108 , 0 , V_573 , NULL , V_110 ) ;
return;
V_111:
if ( V_32 < 0 )
F_70 ( V_108 , V_573 , V_32 ) ;
}
static inline void F_366 ( struct V_92 * V_39 ,
T_2 * V_574 , int V_575 )
{
F_367 ( V_575 < ( V_576 * 4 ) ) ;
memset ( V_574 , 0 , V_575 ) ;
V_574 [ V_577 ] = V_39 -> V_50 ;
V_574 [ V_578 ] = V_39 -> V_579 ;
V_574 [ V_580 ] = V_39 -> V_46 ;
V_574 [ V_581 ] = V_39 -> V_582 ;
V_574 [ V_583 ] = V_39 -> V_584 ;
V_574 [ V_585 ] = V_39 -> V_373 ;
V_574 [ V_586 ] = V_39 -> V_227 ;
V_574 [ V_587 ] = V_39 -> V_63 ;
V_574 [ V_588 ] =
F_368 ( V_39 -> V_481 ) ;
V_574 [ V_589 ] =
F_368 ( V_39 -> V_480 ) ;
V_574 [ V_590 ] = V_39 -> V_591 ;
V_574 [ V_592 ] =
F_368 ( V_39 -> V_593 ) ;
V_574 [ V_594 ] =
F_368 ( V_39 -> V_595 ) ;
V_574 [ V_596 ] = V_39 -> V_70 ;
V_574 [ V_597 ] = V_39 -> V_224 ;
V_574 [ V_598 ] = V_39 -> V_225 ;
V_574 [ V_599 ] = V_39 -> V_221 ;
V_574 [ V_600 ] = V_39 -> V_226 ;
V_574 [ V_601 ] = V_39 -> V_298 ;
V_574 [ V_602 ] = V_39 -> V_603 ;
V_574 [ V_604 ] = V_39 -> V_605 ;
V_574 [ V_606 ] = V_39 -> V_607 ;
#ifdef F_369
V_574 [ V_608 ] = V_39 -> V_609 ;
V_574 [ V_610 ] =
F_368 ( V_39 -> V_611 ) ;
#ifdef F_370
V_574 [ V_612 ] = V_39 -> V_613 ;
#endif
#endif
V_574 [ V_614 ] = V_39 -> V_106 ;
V_574 [ V_615 ] = V_39 -> V_616 ;
#ifdef F_162
V_574 [ V_617 ] = V_39 -> V_233 ;
V_574 [ V_618 ] = V_39 -> V_234 ;
#endif
#ifdef F_58
V_574 [ V_619 ] = V_39 -> V_105 ;
#endif
V_574 [ V_620 ] = V_39 -> V_178 ;
V_574 [ V_621 ] = V_39 -> V_58 ;
V_574 [ V_622 ] = V_39 -> V_623 ;
V_574 [ V_624 ] = V_39 -> V_625 ;
V_574 [ V_626 ] = V_39 -> V_627 ;
V_574 [ V_628 ] = V_39 -> V_629 ;
V_574 [ V_630 ] = V_39 -> V_631 ;
V_574 [ V_632 ] = V_39 -> V_107 ;
V_574 [ V_633 ] = V_39 -> V_276 ;
}
static inline T_14 F_371 ( void )
{
return F_57 ( 4 )
+ F_57 ( sizeof( struct V_634 ) )
+ F_57 ( V_576 * 4 )
+ F_57 ( V_635 * 8 )
+ F_57 ( V_636 * 8 )
+ F_57 ( sizeof( struct V_162 ) ) ;
}
static inline T_14 F_372 ( void )
{
return F_56 ( sizeof( struct V_637 ) )
+ F_57 ( V_638 )
+ F_57 ( V_449 )
+ F_57 ( 4 )
+ F_57 ( 4 )
+ F_57 ( 1 )
+ F_57 ( F_371 () ) ;
}
static inline void F_373 ( T_15 * V_17 , T_16 * V_639 ,
int V_640 , int V_575 )
{
int V_16 ;
int V_641 = V_575 - sizeof( T_15 ) * V_640 ;
F_367 ( V_641 < 0 ) ;
F_374 ( V_640 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_640 ; V_16 ++ )
F_374 ( F_375 ( & V_639 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_640 ] , 0 , V_641 ) ;
}
static inline void F_376 ( T_15 * V_17 , void T_17 * V_639 ,
int V_575 , T_14 V_642 )
{
int V_16 , V_643 ;
T_15 V_644 [ V_635 ] ;
int V_641 = V_575 - sizeof( T_15 ) * V_635 ;
F_367 ( V_641 < 0 ) ;
memset ( V_644 , 0 , sizeof( V_644 ) ) ;
V_644 [ 0 ] = V_635 ;
F_22 (c) {
for ( V_16 = 1 ; V_16 < V_635 ; V_16 ++ )
V_644 [ V_16 ] += F_377 ( V_639 , V_643 , V_16 , V_642 ) ;
}
memcpy ( V_17 , V_644 , V_635 * sizeof( T_15 ) ) ;
memset ( & V_17 [ V_635 ] , 0 , V_641 ) ;
}
static void F_378 ( T_15 * V_17 , struct V_4 * V_5 , int V_645 ,
int V_575 )
{
switch ( V_645 ) {
case V_646 :
F_376 ( V_17 , V_5 -> V_17 . V_18 , V_575 ,
F_379 ( struct V_19 , V_22 ) ) ;
break;
case V_647 :
F_373 ( V_17 , V_5 -> V_17 . V_23 -> V_648 , V_636 , V_575 ) ;
break;
}
}
static int F_380 ( struct V_89 * V_90 , struct V_4 * V_5 ,
T_1 V_649 )
{
struct V_116 * V_650 ;
struct V_634 V_533 ;
if ( F_356 ( V_90 , V_651 , V_5 -> V_73 ) )
goto V_104;
V_533 . V_652 = V_653 ;
V_533 . V_75 = F_1 ( V_5 -> V_75 ) ;
V_533 . V_654 = F_368 ( V_5 -> V_48 -> V_654 ) ;
V_533 . V_655 = F_368 ( F_157 ( V_5 -> V_48 , V_228 ) ) ;
if ( F_351 ( V_90 , V_656 , sizeof( V_533 ) , & V_533 ) )
goto V_104;
V_650 = F_381 ( V_90 , V_657 , V_576 * sizeof( V_658 ) ) ;
if ( ! V_650 )
goto V_104;
F_366 ( & V_5 -> V_39 , F_343 ( V_650 ) , F_382 ( V_650 ) ) ;
if ( V_649 & V_659 )
return 0 ;
V_650 = F_381 ( V_90 , V_646 , V_635 * sizeof( T_15 ) ) ;
if ( ! V_650 )
goto V_104;
F_378 ( F_343 ( V_650 ) , V_5 , V_646 , F_382 ( V_650 ) ) ;
V_650 = F_381 ( V_90 , V_647 , V_636 * sizeof( T_15 ) ) ;
if ( ! V_650 )
goto V_104;
F_378 ( F_343 ( V_650 ) , V_5 , V_647 , F_382 ( V_650 ) ) ;
V_650 = F_381 ( V_90 , V_660 , sizeof( struct V_162 ) ) ;
if ( ! V_650 )
goto V_104;
if ( F_383 ( V_90 , V_661 , V_5 -> V_43 ) )
goto V_104;
F_173 ( & V_5 -> V_36 ) ;
memcpy ( F_343 ( V_650 ) , V_5 -> V_71 . V_218 , F_382 ( V_650 ) ) ;
F_179 ( & V_5 -> V_36 ) ;
return 0 ;
V_104:
return - V_100 ;
}
static T_14 F_384 ( const struct V_6 * V_7 ,
T_1 V_649 )
{
if ( ! F_52 ( V_7 ) )
return 0 ;
return F_371 () ;
}
static int F_385 ( struct V_89 * V_90 , const struct V_6 * V_7 ,
T_1 V_649 )
{
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_662 ;
if ( F_380 ( V_90 , V_5 , V_649 ) < 0 )
return - V_100 ;
return 0 ;
}
static int F_386 ( struct V_4 * V_5 , struct V_162 * V_71 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_663 = false ;
struct V_162 V_664 ;
F_29 () ;
if ( ! V_71 )
return - V_35 ;
if ( F_206 ( V_71 ) )
return - V_35 ;
if ( V_7 -> V_55 & ( V_57 | V_56 ) )
return - V_35 ;
if ( ! F_308 ( V_5 ) )
return - V_35 ;
if ( V_5 -> V_39 . V_63 <= 0 )
return - V_35 ;
F_147 ( & V_5 -> V_36 ) ;
F_282 ( sizeof( V_71 -> V_218 ) != 16 ) ;
memcpy ( V_5 -> V_71 . V_218 + 8 , V_71 -> V_218 + 8 , 8 ) ;
F_151 ( & V_5 -> V_36 ) ;
if ( ! V_5 -> V_81 && ( V_5 -> V_73 & V_74 ) &&
! F_184 ( V_7 , & V_664 , V_144 |
V_230 ) ) {
F_309 ( V_7 , & V_664 , & V_80 ) ;
V_663 = true ;
}
F_147 ( & V_5 -> V_36 ) ;
if ( V_663 ) {
V_5 -> V_73 |= V_475 ;
V_5 -> V_478 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_481 ) ;
}
F_87 (ifp, &idev->addr_list, if_list) {
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_185 ) {
V_10 -> V_167 = 0 ;
V_10 -> V_168 = 0 ;
}
F_128 ( & V_10 -> V_36 ) ;
}
F_151 ( & V_5 -> V_36 ) ;
F_297 ( V_466 , V_5 ) ;
F_268 () ;
return 0 ;
}
static int F_387 ( const struct V_6 * V_7 ,
const struct V_116 * V_650 )
{
struct V_116 * V_117 [ V_665 + 1 ] ;
if ( V_7 && ! F_52 ( V_7 ) )
return - V_666 ;
return F_388 ( V_117 , V_665 , V_650 , V_667 ) ;
}
static int F_389 ( struct V_6 * V_7 , const struct V_116 * V_650 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
struct V_116 * V_117 [ V_665 + 1 ] ;
if ( ! V_5 )
return - V_666 ;
if ( F_388 ( V_117 , V_665 , V_650 , NULL ) < 0 )
F_390 () ;
if ( V_117 [ V_660 ] ) {
V_32 = F_386 ( V_5 , F_343 ( V_117 [ V_660 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_117 [ V_661 ] ) {
T_3 V_668 = F_391 ( V_117 [ V_661 ] ) ;
if ( V_668 != V_45 &&
V_668 != V_455 &&
V_668 != V_44 &&
V_668 != V_360 )
return - V_35 ;
if ( V_668 == V_44 &&
! V_5 -> V_39 . V_41 . V_42 &&
! F_34 ( V_7 ) -> V_18 . V_40 -> V_41 . V_42 )
return - V_35 ;
V_5 -> V_43 = V_668 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_392 ( struct V_89 * V_90 , struct V_4 * V_5 ,
T_1 V_94 , T_1 V_95 , int V_96 , unsigned int V_55 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_637 * V_669 ;
struct V_97 * V_98 ;
void * V_670 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( * V_669 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
V_669 = F_61 ( V_98 ) ;
V_669 -> V_671 = V_102 ;
V_669 -> V_672 = 0 ;
V_669 -> V_673 = V_7 -> type ;
V_669 -> V_674 = V_7 -> V_91 ;
V_669 -> V_675 = F_393 ( V_7 ) ;
V_669 -> V_676 = 0 ;
if ( F_394 ( V_90 , V_677 , V_7 -> V_53 ) ||
( V_7 -> V_306 &&
F_351 ( V_90 , V_678 , V_7 -> V_306 , V_7 -> V_308 ) ) ||
F_356 ( V_90 , V_679 , V_7 -> V_33 ) ||
( V_7 -> V_91 != F_395 ( V_7 ) &&
F_356 ( V_90 , V_680 , F_395 ( V_7 ) ) ) ||
F_383 ( V_90 , V_681 ,
F_44 ( V_7 ) ? V_7 -> V_682 : V_683 ) )
goto V_104;
V_670 = F_396 ( V_90 , V_684 ) ;
if ( ! V_670 )
goto V_104;
if ( F_380 ( V_90 , V_5 , 0 ) < 0 )
goto V_104;
F_397 ( V_90 , V_670 ) ;
F_63 ( V_90 , V_98 ) ;
return 0 ;
V_104:
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
static int F_398 ( struct V_89 * V_90 , struct V_125 * V_126 )
{
struct V_108 * V_108 = F_72 ( V_90 -> V_115 ) ;
int V_127 , V_128 ;
int V_129 = 0 , V_130 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_131 * V_132 ;
V_128 = V_126 -> args [ 0 ] ;
V_130 = V_126 -> args [ 1 ] ;
F_79 () ;
for ( V_127 = V_128 ; V_127 < V_133 ; V_127 ++ , V_130 = 0 ) {
V_129 = 0 ;
V_132 = & V_108 -> V_134 [ V_127 ] ;
F_81 (dev, head, index_hlist) {
if ( V_129 < V_130 )
goto V_137;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_137;
if ( F_392 ( V_90 , V_5 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_466 , V_138 ) < 0 )
goto V_182;
V_137:
V_129 ++ ;
}
}
V_182:
F_82 () ;
V_126 -> args [ 1 ] = V_129 ;
V_126 -> args [ 0 ] = V_127 ;
return V_90 -> V_140 ;
}
void F_297 ( int V_96 , struct V_4 * V_5 )
{
struct V_89 * V_90 ;
struct V_108 * V_108 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_109 ;
V_90 = F_66 ( F_372 () , V_110 ) ;
if ( ! V_90 )
goto V_111;
V_32 = F_392 ( V_90 , V_5 , 0 , 0 , V_96 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_111;
}
F_69 ( V_90 , V_108 , 0 , V_685 , NULL , V_110 ) ;
return;
V_111:
if ( V_32 < 0 )
F_70 ( V_108 , V_685 , V_32 ) ;
}
static inline T_14 F_399 ( void )
{
return F_56 ( sizeof( struct V_686 ) )
+ F_57 ( sizeof( struct V_162 ) )
+ F_57 ( sizeof( struct V_687 ) ) ;
}
static int F_400 ( struct V_89 * V_90 , struct V_4 * V_5 ,
struct V_363 * V_364 , T_1 V_94 , T_1 V_95 ,
int V_96 , unsigned int V_55 )
{
struct V_686 * V_688 ;
struct V_97 * V_98 ;
struct V_687 V_533 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( * V_688 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
V_688 = F_61 ( V_98 ) ;
V_688 -> V_689 = V_102 ;
V_688 -> V_690 = 0 ;
V_688 -> V_691 = 0 ;
V_688 -> V_692 = V_5 -> V_7 -> V_91 ;
V_688 -> V_184 = V_364 -> V_184 ;
V_688 -> V_693 = V_364 -> type ;
V_688 -> V_694 = 0 ;
V_688 -> V_695 = 0 ;
if ( V_364 -> V_283 )
V_688 -> V_695 |= V_696 ;
if ( V_364 -> V_373 )
V_688 -> V_695 |= V_697 ;
if ( F_351 ( V_90 , V_698 , sizeof( V_364 -> V_365 ) , & V_364 -> V_365 ) )
goto V_104;
V_533 . V_699 = F_245 ( V_364 -> V_368 ) ;
V_533 . V_700 = F_245 ( V_364 -> V_367 ) ;
if ( F_351 ( V_90 , V_701 , sizeof( V_533 ) , & V_533 ) )
goto V_104;
F_63 ( V_90 , V_98 ) ;
return 0 ;
V_104:
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
static void F_254 ( int V_96 , struct V_4 * V_5 ,
struct V_363 * V_364 )
{
struct V_89 * V_90 ;
struct V_108 * V_108 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_109 ;
V_90 = F_66 ( F_399 () , V_110 ) ;
if ( ! V_90 )
goto V_111;
V_32 = F_400 ( V_90 , V_5 , V_364 , 0 , 0 , V_96 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_111;
}
F_69 ( V_90 , V_108 , 0 , V_702 , NULL , V_110 ) ;
return;
V_111:
if ( V_32 < 0 )
F_70 ( V_108 , V_702 , V_32 ) ;
}
static void F_305 ( int V_96 , struct V_9 * V_10 )
{
struct V_108 * V_108 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_96 )
F_29 () ;
F_365 ( V_96 ? : V_422 , V_10 ) ;
switch ( V_96 ) {
case V_422 :
if ( ! ( V_10 -> V_156 -> V_703 ) )
F_278 ( V_10 -> V_156 ) ;
if ( V_10 -> V_5 -> V_39 . V_50 )
F_88 ( V_10 ) ;
if ( ! F_206 ( & V_10 -> V_164 ) )
F_232 ( & V_10 -> V_164 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_205 :
if ( V_10 -> V_5 -> V_39 . V_50 )
F_89 ( V_10 ) ;
F_203 ( V_10 -> V_5 , & V_10 -> V_160 ) ;
if ( ! F_206 ( & V_10 -> V_164 ) ) {
struct V_169 * V_156 ;
V_156 = F_140 ( & V_10 -> V_164 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
if ( V_156 )
F_141 ( V_156 ) ;
}
F_237 ( & V_10 -> V_156 -> V_238 ) ;
F_141 ( V_10 -> V_156 ) ;
F_401 ( V_108 ) ;
break;
}
F_402 ( & V_108 -> V_18 . V_135 ) ;
}
static void F_152 ( int V_96 , struct V_9 * V_10 )
{
F_118 () ;
if ( F_133 ( V_10 -> V_5 -> V_81 == 0 ) )
F_305 ( V_96 , V_10 ) ;
F_132 () ;
}
static
int F_403 ( struct V_147 * V_704 , int V_705 ,
void T_6 * V_706 , T_14 * V_707 , T_8 * V_708 )
{
int * V_709 = V_704 -> V_325 ;
int V_710 = * V_709 ;
T_8 V_497 = * V_708 ;
struct V_147 V_711 ;
int V_215 ;
V_711 = * V_704 ;
V_711 . V_325 = & V_710 ;
V_215 = F_404 ( & V_711 , V_705 , V_706 , V_707 , V_708 ) ;
if ( V_705 )
V_215 = F_92 ( V_704 , V_709 , V_710 ) ;
if ( V_215 )
* V_708 = V_497 ;
return V_215 ;
}
static
int F_405 ( struct V_147 * V_704 , int V_705 ,
void T_6 * V_706 , T_14 * V_707 , T_8 * V_708 )
{
struct V_147 V_711 ;
int V_712 = 1 , V_713 = 255 ;
V_711 = * V_704 ;
V_711 . V_152 = & V_712 ;
V_711 . V_151 = & V_713 ;
return F_406 ( & V_711 , V_705 , V_706 , V_707 , V_708 ) ;
}
static
int F_407 ( struct V_147 * V_704 , int V_705 ,
void T_6 * V_706 , T_14 * V_707 , T_8 * V_708 )
{
struct V_4 * V_5 = V_704 -> V_152 ;
int V_714 = V_34 ;
struct V_147 V_711 ;
V_711 = * V_704 ;
V_711 . V_152 = & V_714 ;
V_711 . V_151 = V_5 ? & V_5 -> V_7 -> V_33 : NULL ;
return F_406 ( & V_711 , V_705 , V_706 , V_707 , V_708 ) ;
}
static void F_408 ( struct V_4 * V_5 )
{
struct V_715 V_716 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_409 ( & V_716 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_178 )
F_291 ( NULL , V_206 , & V_716 ) ;
else
F_291 ( NULL , V_189 , & V_716 ) ;
}
static void F_410 ( struct V_108 * V_108 , T_2 V_145 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_79 () ;
F_181 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_146 = ( ! V_5 -> V_39 . V_178 ) ^ ( ! V_145 ) ;
V_5 -> V_39 . V_178 = V_145 ;
if ( V_146 )
F_408 ( V_5 ) ;
}
}
F_82 () ;
}
static int F_411 ( struct V_147 * V_148 , int * V_149 , int V_145 )
{
struct V_108 * V_108 ;
int V_150 ;
if ( ! F_93 () )
return F_94 () ;
V_108 = (struct V_108 * ) V_148 -> V_151 ;
V_150 = * V_149 ;
* V_149 = V_145 ;
if ( V_149 == & V_108 -> V_18 . V_40 -> V_178 ) {
F_95 () ;
return 0 ;
}
if ( V_149 == & V_108 -> V_18 . V_122 -> V_178 ) {
V_108 -> V_18 . V_40 -> V_178 = V_145 ;
F_410 ( V_108 , V_145 ) ;
} else if ( ( ! V_145 ) ^ ( ! V_150 ) )
F_408 ( (struct V_4 * ) V_148 -> V_152 ) ;
F_95 () ;
return 0 ;
}
static
int F_412 ( struct V_147 * V_704 , int V_705 ,
void T_6 * V_706 , T_14 * V_707 , T_8 * V_708 )
{
int * V_709 = V_704 -> V_325 ;
int V_710 = * V_709 ;
T_8 V_497 = * V_708 ;
struct V_147 V_711 ;
int V_215 ;
V_711 = * V_704 ;
V_711 . V_325 = & V_710 ;
V_215 = F_404 ( & V_711 , V_705 , V_706 , V_707 , V_708 ) ;
if ( V_705 )
V_215 = F_411 ( V_704 , V_709 , V_710 ) ;
if ( V_215 )
* V_708 = V_497 ;
return V_215 ;
}
static
int F_413 ( struct V_147 * V_704 , int V_705 ,
void T_6 * V_706 , T_14 * V_707 , T_8 * V_708 )
{
int * V_709 = V_704 -> V_325 ;
int V_215 ;
int V_150 , V_717 ;
V_150 = * V_709 ;
V_215 = F_404 ( V_704 , V_705 , V_706 , V_707 , V_708 ) ;
V_717 = * V_709 ;
if ( V_705 && V_150 != V_717 ) {
struct V_108 * V_108 = V_704 -> V_151 ;
if ( ! F_93 () )
return F_94 () ;
if ( V_709 == & V_108 -> V_18 . V_40 -> V_106 )
F_65 ( V_108 , V_87 ,
V_123 ,
V_108 -> V_18 . V_40 ) ;
else if ( V_709 == & V_108 -> V_18 . V_122 -> V_106 )
F_65 ( V_108 , V_87 ,
V_121 ,
V_108 -> V_18 . V_122 ) ;
else {
struct V_4 * V_5 = V_704 -> V_152 ;
F_65 ( V_108 , V_87 ,
V_5 -> V_7 -> V_91 ,
& V_5 -> V_39 ) ;
}
F_95 () ;
}
return V_215 ;
}
static int F_414 ( struct V_147 * V_704 , int V_705 ,
void T_6 * V_706 , T_14 * V_707 ,
T_8 * V_708 )
{
int V_32 ;
struct V_162 V_160 ;
char V_718 [ V_719 ] ;
struct V_147 V_711 = * V_704 ;
struct V_108 * V_108 = V_704 -> V_151 ;
struct V_452 * V_447 = V_704 -> V_325 ;
if ( & V_108 -> V_18 . V_122 -> V_41 == V_704 -> V_325 )
return - V_720 ;
V_711 . V_721 = V_719 ;
V_711 . V_325 = V_718 ;
if ( ! F_93 () )
return F_94 () ;
if ( ! V_705 && ! V_447 -> V_42 ) {
V_32 = - V_720 ;
goto V_182;
}
V_32 = snprintf ( V_718 , sizeof( V_718 ) , L_29 , & V_447 -> V_447 ) ;
if ( V_32 >= sizeof( V_718 ) ) {
V_32 = - V_720 ;
goto V_182;
}
V_32 = F_415 ( & V_711 , V_705 , V_706 , V_707 , V_708 ) ;
if ( V_32 || ! V_705 )
goto V_182;
if ( F_416 ( V_718 , - 1 , V_160 . V_722 . V_723 , - 1 , NULL ) != 1 ) {
V_32 = - V_720 ;
goto V_182;
}
V_447 -> V_42 = true ;
V_447 -> V_447 = V_160 ;
if ( & V_108 -> V_18 . V_40 -> V_41 == V_704 -> V_325 ) {
struct V_6 * V_7 ;
F_91 (net, dev) {
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_43 =
V_44 ;
}
}
} else {
struct V_4 * V_5 = V_704 -> V_152 ;
V_5 -> V_43 = V_44 ;
}
V_182:
F_95 () ;
return V_32 ;
}
static
int F_417 ( struct V_147 * V_704 ,
int V_705 ,
void T_6 * V_706 ,
T_14 * V_707 ,
T_8 * V_708 )
{
int * V_709 = V_704 -> V_325 ;
int V_710 = * V_709 ;
T_8 V_497 = * V_708 ;
struct V_147 V_711 ;
int V_215 ;
V_711 = * V_704 ;
V_711 . V_325 = & V_710 ;
V_215 = F_404 ( & V_711 , V_705 , V_706 , V_707 , V_708 ) ;
if ( V_705 )
V_215 = F_98 ( V_704 , V_709 , V_710 ) ;
if ( V_215 )
* V_708 = V_497 ;
return V_215 ;
}
static int F_418 ( struct V_108 * V_108 , char * V_724 ,
struct V_4 * V_5 , struct V_92 * V_149 )
{
int V_16 ;
struct V_725 * V_726 ;
char V_727 [ sizeof( L_30 ) + V_638 ] ;
V_726 = F_419 ( & V_728 , sizeof( * V_726 ) , V_25 ) ;
if ( ! V_726 )
goto V_182;
for ( V_16 = 0 ; V_726 -> V_729 [ V_16 ] . V_325 ; V_16 ++ ) {
V_726 -> V_729 [ V_16 ] . V_325 += ( char * ) V_149 - ( char * ) & V_92 ;
V_726 -> V_729 [ V_16 ] . V_152 = V_5 ;
V_726 -> V_729 [ V_16 ] . V_151 = V_108 ;
}
snprintf ( V_727 , sizeof( V_727 ) , L_31 , V_724 ) ;
V_726 -> V_730 = F_420 ( V_108 , V_727 , V_726 -> V_729 ) ;
if ( ! V_726 -> V_730 )
goto free;
V_149 -> V_47 = V_726 ;
return 0 ;
free:
F_26 ( V_726 ) ;
V_182:
return - V_109 ;
}
static void F_421 ( struct V_92 * V_149 )
{
struct V_725 * V_726 ;
if ( ! V_149 -> V_47 )
return;
V_726 = V_149 -> V_47 ;
V_149 -> V_47 = NULL ;
F_422 ( V_726 -> V_730 ) ;
F_26 ( V_726 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_423 ( V_5 -> V_7 -> V_53 ) )
return - V_35 ;
V_32 = F_424 ( V_5 -> V_7 , V_5 -> V_48 ,
& V_731 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_418 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_53 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_425 ( V_5 -> V_48 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_421 ( & V_5 -> V_39 ) ;
F_425 ( V_5 -> V_48 ) ;
}
static int T_10 F_426 ( struct V_108 * V_108 )
{
int V_32 = - V_30 ;
struct V_92 * V_732 , * V_733 ;
V_732 = F_419 ( & V_92 , sizeof( V_92 ) , V_25 ) ;
if ( ! V_732 )
goto V_734;
V_733 = F_419 ( & V_735 , sizeof( V_735 ) , V_25 ) ;
if ( ! V_733 )
goto V_736;
V_733 -> V_373 = V_737 . V_373 ;
V_733 -> V_178 = V_737 . V_178 ;
V_733 -> V_41 . V_42 = false ;
V_732 -> V_41 . V_42 = false ;
V_108 -> V_18 . V_122 = V_732 ;
V_108 -> V_18 . V_40 = V_733 ;
#ifdef F_427
V_32 = F_418 ( V_108 , L_32 , NULL , V_732 ) ;
if ( V_32 < 0 )
goto V_738;
V_32 = F_418 ( V_108 , L_33 , NULL , V_733 ) ;
if ( V_32 < 0 )
goto V_739;
#endif
return 0 ;
#ifdef F_427
V_739:
F_421 ( V_732 ) ;
V_738:
F_26 ( V_733 ) ;
#endif
V_736:
F_26 ( V_732 ) ;
V_734:
return V_32 ;
}
static void T_11 F_428 ( struct V_108 * V_108 )
{
#ifdef F_427
F_421 ( V_108 -> V_18 . V_40 ) ;
F_421 ( V_108 -> V_18 . V_122 ) ;
#endif
F_26 ( V_108 -> V_18 . V_40 ) ;
F_26 ( V_108 -> V_18 . V_122 ) ;
}
int T_12 F_429 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_430 () ;
if ( V_32 < 0 ) {
F_431 ( L_34 ,
V_52 , V_32 ) ;
goto V_182;
}
V_32 = F_336 ( & V_740 ) ;
if ( V_32 < 0 )
goto V_741;
V_15 = F_432 ( L_35 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_742;
}
F_256 () ;
V_5 = F_28 ( V_743 . V_744 ) ;
F_95 () ;
if ( F_53 ( V_5 ) ) {
V_32 = F_122 ( V_5 ) ;
goto V_745;
}
for ( V_16 = 0 ; V_16 < V_473 ; V_16 ++ )
F_433 ( & V_186 [ V_16 ] ) ;
F_434 ( & V_746 ) ;
F_253 () ;
F_435 ( & V_747 ) ;
V_32 = F_436 ( V_748 , V_749 , NULL , F_398 ,
NULL ) ;
if ( V_32 < 0 )
goto V_111;
F_436 ( V_748 , V_422 , F_348 , NULL , NULL ) ;
F_436 ( V_748 , V_205 , F_345 , NULL , NULL ) ;
F_436 ( V_748 , V_750 , F_364 ,
F_361 , NULL ) ;
F_436 ( V_748 , V_566 , NULL ,
F_362 , NULL ) ;
F_436 ( V_748 , V_570 , NULL ,
F_363 , NULL ) ;
F_436 ( V_748 , V_751 , F_71 ,
F_78 , NULL ) ;
F_437 () ;
return 0 ;
V_111:
F_438 ( & V_747 ) ;
F_439 ( & V_746 ) ;
V_745:
F_440 ( V_15 ) ;
V_742:
F_338 ( & V_740 ) ;
V_741:
F_441 () ;
V_182:
return V_32 ;
}
void F_442 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_439 ( & V_746 ) ;
F_338 ( & V_740 ) ;
F_441 () ;
F_256 () ;
F_443 ( & V_747 ) ;
F_91 (&init_net, dev) {
if ( F_52 ( V_7 ) == NULL )
continue;
F_294 ( V_7 , 1 ) ;
}
F_294 ( V_743 . V_744 , 2 ) ;
F_144 ( & V_180 ) ;
for ( V_16 = 0 ; V_16 < V_473 ; V_16 ++ )
F_67 ( ! F_444 ( & V_186 [ V_16 ] ) ) ;
F_145 ( & V_180 ) ;
F_10 ( & V_514 ) ;
F_95 () ;
F_440 ( V_15 ) ;
}
