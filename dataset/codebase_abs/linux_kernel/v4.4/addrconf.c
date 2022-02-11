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
V_32 = V_35 ;
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
if ( V_10 -> V_55 & V_195 ) {
F_144 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_55 |= V_144 ;
if ( V_285 )
V_10 -> V_55 |= V_286 ;
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
memcpy ( V_305 , V_7 -> V_308 , 8 ) ;
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
case V_323 :
return F_209 ( V_305 , V_7 ) ;
case V_324 :
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
V_325:
F_231 ( V_5 -> V_222 , sizeof( V_5 -> V_222 ) ) ;
V_5 -> V_222 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_222 [ 0 ] == 0xfd &&
( V_5 -> V_222 [ 1 ] & V_5 -> V_222 [ 2 ] & V_5 -> V_222 [ 3 ] & V_5 -> V_222 [ 4 ] & V_5 -> V_222 [ 5 ] & V_5 -> V_222 [ 6 ] ) == 0xff &&
( V_5 -> V_222 [ 7 ] & 0x80 ) )
goto V_325;
if ( ( V_5 -> V_222 [ 0 ] | V_5 -> V_222 [ 1 ] ) == 0 ) {
if ( V_5 -> V_222 [ 2 ] == 0x5e && V_5 -> V_222 [ 3 ] == 0xfe )
goto V_325;
if ( ( V_5 -> V_222 [ 2 ] | V_5 -> V_222 [ 3 ] | V_5 -> V_222 [ 4 ] | V_5 -> V_222 [ 5 ] | V_5 -> V_222 [ 6 ] | V_5 -> V_222 [ 7 ] ) == 0x00 )
goto V_325;
}
}
static void V_66 ( unsigned long V_326 )
{
struct V_4 * V_5 = (struct V_4 * ) V_326 ;
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
F_232 ( struct V_162 * V_327 , int V_328 , struct V_6 * V_7 ,
unsigned long V_191 , T_1 V_55 )
{
struct V_329 V_330 = {
. V_331 = F_233 ( V_7 ) ? : V_332 ,
. V_333 = V_334 ,
. V_335 = V_7 -> V_91 ,
. V_336 = V_191 ,
. V_337 = V_328 ,
. V_338 = V_339 | V_55 ,
. V_340 . V_341 = F_34 ( V_7 ) ,
. V_342 = V_343 ,
} ;
V_330 . V_344 = * V_327 ;
#if F_42 ( V_59 )
if ( V_7 -> type == V_60 && ( V_7 -> V_55 & V_345 ) )
V_330 . V_338 |= V_346 ;
#endif
F_234 ( & V_330 ) ;
}
static struct V_169 * F_140 ( const struct V_162 * V_327 ,
int V_328 ,
const struct V_6 * V_7 ,
T_1 V_55 , T_1 V_347 )
{
struct V_348 * V_349 ;
struct V_169 * V_156 = NULL ;
struct V_350 * V_148 ;
T_1 V_351 = F_233 ( V_7 ) ? : V_332 ;
V_148 = F_235 ( F_34 ( V_7 ) , V_351 ) ;
if ( ! V_148 )
return NULL ;
F_173 ( & V_148 -> V_352 ) ;
V_349 = F_236 ( & V_148 -> V_353 , V_327 , V_328 , NULL , 0 ) ;
if ( ! V_349 )
goto V_182;
V_347 |= V_354 ;
for ( V_156 = V_349 -> V_355 ; V_156 ; V_156 = V_156 -> V_238 . V_356 ) {
if ( V_156 -> V_238 . V_7 -> V_91 != V_7 -> V_91 )
continue;
if ( ( V_156 -> V_202 & V_55 ) != V_55 )
continue;
if ( ( V_156 -> V_202 & V_347 ) != 0 )
continue;
F_237 ( & V_156 -> V_238 ) ;
break;
}
V_182:
F_179 ( & V_148 -> V_352 ) ;
return V_156 ;
}
static void F_238 ( struct V_6 * V_7 )
{
struct V_329 V_330 = {
. V_331 = F_233 ( V_7 ) ? : V_357 ,
. V_333 = V_334 ,
. V_335 = V_7 -> V_91 ,
. V_337 = 8 ,
. V_338 = V_339 ,
. V_340 . V_341 = F_34 ( V_7 ) ,
} ;
F_239 ( & V_330 . V_344 , F_199 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_234 ( & V_330 ) ;
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
bool V_358 , unsigned long V_217 )
{
T_1 V_55 ;
struct V_9 * V_207 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ift, &idev->tempaddr_list, tmp_list) {
int V_212 , V_359 , V_360 ;
if ( V_10 != V_207 -> V_204 )
continue;
V_212 = ( V_217 - V_207 -> V_1 ) / V_3 ;
V_359 = V_5 -> V_39 . V_224 - V_212 ;
if ( V_359 < 0 )
V_359 = 0 ;
V_360 = V_5 -> V_39 . V_225 -
V_5 -> V_39 . V_226 - V_212 ;
if ( V_360 < 0 )
V_360 = 0 ;
if ( V_167 > V_359 )
V_167 = V_359 ;
if ( V_168 > V_360 )
V_168 = V_360 ;
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
if ( ( V_358 || F_242 ( & V_5 -> V_64 ) ) &&
V_5 -> V_39 . V_70 > 0 ) {
F_179 ( & V_5 -> V_36 ) ;
F_154 ( V_10 , NULL ) ;
} else {
F_179 ( & V_5 -> V_36 ) ;
}
}
void F_243 ( struct V_6 * V_7 , T_3 * V_361 , int V_140 , bool V_362 )
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
V_167 = F_244 ( V_364 -> V_367 ) ;
V_168 = F_244 ( V_364 -> V_368 ) ;
if ( V_168 > V_167 ) {
F_245 ( L_19 ) ;
return;
}
V_119 = F_246 ( V_7 ) ;
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
if ( F_247 ( V_369 ) )
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
} else if ( F_247 ( V_369 ) ) {
F_142 ( V_156 , V_13 + V_369 ) ;
} else {
F_248 ( V_156 ) ;
}
} else if ( V_167 ) {
T_5 V_191 = 0 ;
int V_55 = V_371 | V_372 ;
if ( F_247 ( V_369 ) ) {
V_55 |= V_203 ;
V_191 = F_249 ( V_369 ) ;
}
F_232 ( & V_364 -> V_365 , V_364 -> V_184 ,
V_7 , V_191 , V_55 ) ;
}
F_106 ( V_156 ) ;
}
if ( V_364 -> V_373 && V_119 -> V_39 . V_373 ) {
struct V_9 * V_10 ;
struct V_162 V_160 ;
int V_358 = 0 , V_374 = 0 ;
bool V_185 = false ;
if ( V_364 -> V_184 == 64 ) {
memcpy ( & V_160 , & V_364 -> V_365 , 8 ) ;
if ( ! F_206 ( & V_119 -> V_71 ) ) {
F_173 ( & V_119 -> V_36 ) ;
memcpy ( V_160 . V_218 + 8 ,
V_119 -> V_71 . V_218 + 8 , 8 ) ;
F_179 ( & V_119 -> V_36 ) ;
V_185 = true ;
} else if ( V_119 -> V_43 ==
V_44 &&
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
if ( F_250 ( V_10 ) ) {
F_103 ( V_119 ) ;
return;
}
V_374 = 0 ;
V_358 = 1 ;
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
if ( ! V_374 && ! V_358 && V_378 ) {
const T_1 V_379 = F_156 ( T_1 ,
V_378 , V_380 ) ;
V_167 = F_251 ( V_167 , V_379 ) ;
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
V_358 , V_217 ) ;
F_149 ( V_10 ) ;
F_252 () ;
}
}
F_253 ( V_381 , V_119 , V_364 ) ;
F_103 ( V_119 ) ;
}
int F_254 ( struct V_108 * V_108 , void T_6 * V_382 )
{
struct V_383 V_384 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_255 () ;
V_32 = - V_385 ;
if ( F_256 ( & V_384 , V_382 , sizeof( struct V_383 ) ) )
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
T_7 V_405 = F_257 () ;
F_258 ( V_406 ) ;
V_32 = V_389 -> V_404 ( V_7 , & V_392 , V_407 ) ;
F_258 ( V_405 ) ;
} else
V_32 = - V_408 ;
if ( V_32 == 0 ) {
V_32 = - V_109 ;
V_7 = F_259 ( V_108 , V_149 . V_53 ) ;
if ( ! V_7 )
goto V_386;
V_32 = F_260 ( V_7 ) ;
}
}
#endif
V_386:
F_95 () ;
return V_32 ;
}
static int F_261 ( struct V_409 * V_115 , bool V_410 ,
const struct V_162 * V_160 , int V_91 )
{
int V_215 ;
F_29 () ;
F_262 ( V_115 ) ;
if ( V_410 )
V_215 = F_263 ( V_115 , V_91 , V_160 ) ;
else
V_215 = F_264 ( V_115 , V_91 , V_160 ) ;
F_265 ( V_115 ) ;
return V_215 ;
}
static int F_266 ( struct V_108 * V_108 , int V_91 ,
const struct V_162 * V_327 ,
const struct V_162 * V_411 ,
unsigned int V_328 , V_223 V_412 ,
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
if ( V_328 > 128 )
return - V_35 ;
if ( ! V_167 || V_168 > V_167 )
return - V_35 ;
if ( V_412 & V_377 && V_328 != 64 )
return - V_35 ;
V_7 = F_75 ( V_108 , V_91 ) ;
if ( ! V_7 )
return - V_176 ;
V_5 = F_240 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return F_122 ( V_5 ) ;
if ( V_412 & V_414 ) {
int V_215 = F_261 ( V_108 -> V_18 . V_415 ,
true , V_327 , V_91 ) ;
if ( V_215 < 0 )
return V_215 ;
}
V_166 = F_158 ( V_327 ) ;
V_413 = F_137 ( V_167 , V_3 ) ;
if ( F_247 ( V_413 ) ) {
V_191 = F_249 ( V_413 * V_3 ) ;
V_167 = V_413 ;
V_55 = V_203 ;
} else {
V_191 = 0 ;
V_55 = 0 ;
V_412 |= V_195 ;
}
V_413 = F_137 ( V_168 , V_3 ) ;
if ( F_247 ( V_413 ) ) {
if ( V_413 == 0 )
V_412 |= V_249 ;
V_168 = V_413 ;
}
V_10 = F_116 ( V_5 , V_327 , V_411 , V_328 , V_166 , V_412 ,
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
F_267 () ;
return 0 ;
} else if ( V_412 & V_414 ) {
F_261 ( V_108 -> V_18 . V_415 ,
false , V_327 , V_91 ) ;
}
return F_122 ( V_10 ) ;
}
static int F_268 ( struct V_108 * V_108 , int V_91 , T_1 V_412 ,
const struct V_162 * V_327 , unsigned int V_328 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_328 > 128 )
return - V_35 ;
V_7 = F_75 ( V_108 , V_91 ) ;
if ( ! V_7 )
return - V_176 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_416 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_184 == V_328 &&
F_165 ( V_327 , & V_10 -> V_160 ) ) {
F_18 ( V_10 ) ;
F_179 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_55 & V_187 ) &&
( V_412 & V_377 ) )
F_241 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_143 ( V_10 ) ;
F_267 () ;
if ( F_269 ( V_327 ) ) {
F_261 ( V_108 -> V_18 . V_415 ,
false , V_327 , V_7 -> V_91 ) ;
}
return 0 ;
}
}
F_179 ( & V_5 -> V_36 ) ;
return - V_175 ;
}
int F_270 ( struct V_108 * V_108 , void T_6 * V_382 )
{
struct V_383 V_384 ;
int V_32 ;
if ( ! F_271 ( V_108 -> V_417 , V_418 ) )
return - V_419 ;
if ( F_256 ( & V_384 , V_382 , sizeof( struct V_383 ) ) )
return - V_385 ;
F_255 () ;
V_32 = F_266 ( V_108 , V_384 . V_387 , & V_384 . V_394 , NULL ,
V_384 . V_420 , V_195 ,
V_421 , V_421 ) ;
F_95 () ;
return V_32 ;
}
int F_272 ( struct V_108 * V_108 , void T_6 * V_382 )
{
struct V_383 V_384 ;
int V_32 ;
if ( ! F_271 ( V_108 -> V_417 , V_418 ) )
return - V_419 ;
if ( F_256 ( & V_384 , V_382 , sizeof( struct V_383 ) ) )
return - V_385 ;
F_255 () ;
V_32 = F_268 ( V_108 , V_384 . V_387 , 0 , & V_384 . V_394 ,
V_384 . V_420 ) ;
F_95 () ;
return V_32 ;
}
static void F_273 ( struct V_4 * V_5 , const struct V_162 * V_160 ,
int V_328 , int V_166 )
{
struct V_9 * V_10 ;
V_10 = F_116 ( V_5 , V_160 , NULL , V_328 ,
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
static void F_274 ( struct V_4 * V_5 )
{
struct V_162 V_160 ;
struct V_6 * V_7 ;
struct V_108 * V_108 = F_34 ( V_5 -> V_7 ) ;
int V_166 , V_328 ;
T_1 V_423 = 0 ;
F_29 () ;
memset ( & V_160 , 0 , sizeof( struct V_162 ) ) ;
memcpy ( & V_160 . V_302 [ 3 ] , V_5 -> V_7 -> V_308 , 4 ) ;
if ( V_5 -> V_7 -> V_55 & V_345 ) {
V_160 . V_302 [ 0 ] = F_199 ( 0xfe800000 ) ;
V_166 = V_278 ;
V_328 = 64 ;
} else {
V_166 = V_232 ;
V_328 = 96 ;
V_423 |= V_346 ;
}
if ( V_160 . V_302 [ 3 ] ) {
F_273 ( V_5 , & V_160 , V_328 , V_166 ) ;
F_232 ( & V_160 , V_328 , V_5 -> V_7 , 0 , V_423 ) ;
return;
}
F_91 (net, dev) {
struct V_424 * V_425 = F_275 ( V_7 ) ;
if ( V_425 && ( V_7 -> V_55 & V_82 ) ) {
struct V_426 * V_141 ;
int V_427 = V_166 ;
for ( V_141 = V_425 -> V_428 ; V_141 ; V_141 = V_141 -> V_429 ) {
V_160 . V_302 [ 3 ] = V_141 -> V_430 ;
if ( V_141 -> V_431 == V_432 )
continue;
if ( V_141 -> V_431 >= V_433 ) {
if ( V_5 -> V_7 -> V_55 & V_345 )
continue;
V_427 |= V_282 ;
}
F_273 ( V_5 , & V_160 , V_328 , V_427 ) ;
F_232 ( & V_160 , V_328 , V_5 -> V_7 , 0 ,
V_423 ) ;
}
}
}
}
static void F_276 ( struct V_6 * V_7 )
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
F_273 ( V_5 , & V_437 , 128 , V_282 ) ;
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
F_277 ( V_436 ) ;
}
}
F_179 ( & V_5 -> V_36 ) ;
}
}
static void F_278 ( struct V_4 * V_5 ,
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
static bool F_279 ( struct V_162 V_439 )
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
static F_280 ( V_36 ) ;
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
} V_326 ;
struct V_162 V_447 ;
struct V_162 V_451 ;
struct V_108 * V_108 = F_34 ( V_5 -> V_7 ) ;
F_281 ( sizeof( V_326 . V_445 ) != sizeof( V_326 ) ) ;
if ( V_5 -> V_39 . V_41 . V_42 )
V_447 = V_5 -> V_39 . V_41 . V_447 ;
else if ( V_108 -> V_18 . V_40 -> V_41 . V_42 )
V_447 = V_108 -> V_18 . V_40 -> V_41 . V_447 ;
else
return - 1 ;
V_219:
F_144 ( & V_36 ) ;
F_282 ( V_441 ) ;
memset ( & V_326 , 0 , sizeof( V_326 ) ) ;
memset ( V_443 , 0 , sizeof( V_443 ) ) ;
memcpy ( V_326 . V_448 , V_5 -> V_7 -> V_316 , V_5 -> V_7 -> V_306 ) ;
V_326 . V_365 [ 0 ] = V_439 -> V_302 [ 0 ] ;
V_326 . V_365 [ 1 ] = V_439 -> V_302 [ 1 ] ;
V_326 . V_447 = V_447 ;
V_326 . V_440 = V_440 ;
F_283 ( V_441 , V_326 . V_445 , V_443 ) ;
V_451 = * V_439 ;
V_451 . V_302 [ 2 ] = ( V_403 T_4 ) V_441 [ 0 ] ;
V_451 . V_302 [ 3 ] = ( V_403 T_4 ) V_441 [ 1 ] ;
F_145 ( & V_36 ) ;
if ( F_279 ( V_451 ) ) {
V_440 ++ ;
if ( V_440 > F_34 ( V_5 -> V_7 ) -> V_18 . V_47 . V_296 )
return - 1 ;
goto V_219;
}
* V_439 = V_451 ;
return 0 ;
}
static void F_284 ( struct V_4 * V_5 , bool V_452 )
{
struct V_162 V_160 ;
if ( F_285 ( V_5 -> V_7 ) )
return;
F_239 ( & V_160 , F_199 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( V_5 -> V_43 == V_44 ) {
if ( ! F_198 ( & V_160 , 0 , V_5 ) )
F_278 ( V_5 , & V_160 ,
V_290 ) ;
else if ( V_452 )
F_232 ( & V_160 , 64 , V_5 -> V_7 , 0 , 0 ) ;
} else if ( V_5 -> V_43 == V_45 ) {
if ( F_200 ( V_160 . V_218 + 8 , V_5 -> V_7 ) == 0 )
F_278 ( V_5 , & V_160 , 0 ) ;
else if ( V_452 )
F_232 ( & V_160 , 64 , V_5 -> V_7 , 0 , 0 ) ;
}
}
static void F_286 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_317 ) &&
( V_7 -> type != V_318 ) &&
( V_7 -> type != V_319 ) &&
( V_7 -> type != V_320 ) &&
( V_7 -> type != V_323 ) &&
( V_7 -> type != V_324 ) &&
( V_7 -> type != V_68 ) &&
( V_7 -> type != V_322 ) ) {
return;
}
V_5 = F_240 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return;
F_284 ( V_5 , false ) ;
}
static void F_287 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_22 , V_52 ) ;
return;
}
if ( V_7 -> V_61 & V_62 ) {
F_284 ( V_5 , false ) ;
return;
}
F_274 ( V_5 ) ;
if ( V_7 -> V_55 & V_345 )
F_238 ( V_7 ) ;
}
static void F_288 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_22 , V_52 ) ;
return;
}
F_284 ( V_5 , true ) ;
if ( V_7 -> V_55 & V_345 )
F_238 ( V_7 ) ;
}
static int F_289 ( struct V_453 * V_454 , unsigned long V_96 ,
void * V_455 )
{
struct V_6 * V_7 = F_290 ( V_455 ) ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
int V_456 = 0 ;
int V_32 ;
switch ( V_96 ) {
case V_457 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return F_291 ( F_122 ( V_5 ) ) ;
}
break;
case V_458 :
if ( V_7 -> V_33 < V_34 ) {
F_292 ( V_7 , 1 ) ;
break;
}
if ( V_5 ) {
F_293 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_46 = V_7 -> V_33 ;
break;
}
V_5 = F_28 ( V_7 ) ;
if ( F_53 ( V_5 ) )
break;
if ( ! ( V_5 -> V_73 & V_74 ) )
break;
V_456 = 1 ;
case V_189 :
case V_459 :
if ( V_7 -> V_55 & V_460 )
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
if ( ! F_250 ( V_5 ) ) {
V_5 -> V_73 |= V_74 ;
V_456 = 1 ;
}
} else if ( V_96 == V_459 ) {
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
V_456 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_59 )
case V_60 :
F_287 ( V_7 ) ;
break;
#endif
#if F_42 ( V_461 )
case V_321 :
F_288 ( V_7 ) ;
break;
#endif
case V_462 :
F_276 ( V_7 ) ;
break;
default:
F_286 ( V_7 ) ;
break;
}
if ( ! F_250 ( V_5 ) ) {
if ( V_456 )
F_294 ( V_5 ) ;
if ( V_5 -> V_39 . V_46 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_293 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_46 = V_7 -> V_33 ;
}
V_5 -> V_75 = V_13 ;
F_295 ( V_463 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_292 ( V_7 , 1 ) ;
}
break;
case V_206 :
case V_464 :
F_292 ( V_7 , V_96 != V_206 ) ;
break;
case V_465 :
if ( V_5 ) {
F_47 ( V_5 ) ;
F_3 ( V_5 ) ;
V_32 = F_2 ( V_5 ) ;
if ( V_32 )
return F_291 ( V_32 ) ;
V_32 = F_41 ( V_5 ) ;
if ( V_32 ) {
F_3 ( V_5 ) ;
return F_291 ( V_32 ) ;
}
}
break;
case V_466 :
case V_467 :
F_296 ( V_7 , V_96 ) ;
break;
}
return V_468 ;
}
static void F_296 ( struct V_6 * V_7 , unsigned long V_96 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_96 == V_467 )
F_297 ( V_5 ) ;
else if ( V_96 == V_466 )
F_298 ( V_5 ) ;
}
static int F_292 ( struct V_6 * V_7 , int V_469 )
{
struct V_108 * V_108 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_141 ;
int V_154 , V_16 ;
F_29 () ;
F_299 ( V_108 , V_7 ) ;
F_300 ( & V_49 , V_7 ) ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_176 ;
if ( V_469 ) {
V_5 -> V_81 = 1 ;
F_301 ( V_7 -> V_76 , NULL ) ;
F_47 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_470 ; V_16 ++ ) {
struct V_131 * V_127 = & V_186 [ V_16 ] ;
F_144 ( & V_180 ) ;
V_471:
F_81 (ifa, h, addr_lst) {
if ( V_141 -> V_5 == V_5 ) {
F_146 ( & V_141 -> V_153 ) ;
F_9 ( V_141 ) ;
goto V_471;
}
}
F_145 ( & V_180 ) ;
}
F_147 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_469 )
V_5 -> V_73 &= ~ ( V_472 | V_473 | V_74 ) ;
if ( V_469 && F_7 ( & V_5 -> V_65 ) )
F_103 ( V_5 ) ;
while ( ! F_242 ( & V_5 -> V_64 ) ) {
V_141 = F_302 ( & V_5 -> V_64 ,
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
V_141 = F_302 ( & V_5 -> V_37 ,
struct V_9 , V_161 ) ;
F_9 ( V_141 ) ;
F_148 ( & V_141 -> V_161 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_144 ( & V_141 -> V_36 ) ;
V_154 = V_141 -> V_154 ;
V_141 -> V_154 = V_155 ;
F_145 ( & V_141 -> V_36 ) ;
if ( V_154 != V_155 ) {
F_303 ( V_205 , V_141 ) ;
F_134 ( V_206 , V_141 ) ;
}
F_149 ( V_141 ) ;
F_147 ( & V_5 -> V_36 ) ;
}
F_151 ( & V_5 -> V_36 ) ;
if ( V_469 ) {
F_304 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_305 ( V_5 ) ;
}
V_5 -> V_75 = V_13 ;
if ( V_469 ) {
F_3 ( V_5 ) ;
F_39 ( & V_49 , V_5 -> V_48 ) ;
F_300 ( & V_49 , V_7 ) ;
F_103 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_326 )
{
struct V_4 * V_5 = (struct V_4 * ) V_326 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_162 V_474 ;
F_129 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_81 || ! ( V_5 -> V_73 & V_74 ) )
goto V_182;
if ( ! F_306 ( V_5 ) )
goto V_182;
if ( V_5 -> V_73 & V_473 )
goto V_182;
if ( V_5 -> V_475 ++ < V_5 -> V_39 . V_63 ) {
F_131 ( & V_5 -> V_36 ) ;
if ( ! F_184 ( V_7 , & V_474 , V_144 ) )
F_307 ( V_7 , & V_474 ,
& V_80 ) ;
else
goto V_476;
F_129 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_475 ==
V_5 -> V_39 . V_63 ) ?
V_5 -> V_39 . V_477 :
V_5 -> V_39 . V_478 ) ;
} else {
F_102 ( L_25 , V_5 -> V_7 -> V_53 ) ;
}
V_182:
F_131 ( & V_5 -> V_36 ) ;
V_476:
F_103 ( V_5 ) ;
}
static void F_308 ( struct V_9 * V_10 )
{
unsigned long V_479 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_55 & V_230 )
V_479 = 0 ;
else
V_479 = F_309 () % ( V_5 -> V_39 . V_477 ? : 1 ) ;
V_10 -> V_480 = V_5 -> V_39 . V_227 ;
F_16 ( V_10 , V_479 ) ;
}
static void F_310 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_201 ( V_7 , & V_10 -> V_160 ) ;
F_311 ( ( V_403 T_1 ) V_10 -> V_160 . V_302 [ 3 ] ) ;
F_173 ( & V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_154 == V_155 )
goto V_182;
if ( V_7 -> V_55 & ( V_56 | V_57 ) ||
V_5 -> V_39 . V_58 < 1 ||
! ( V_10 -> V_55 & V_144 ) ||
V_10 -> V_55 & V_481 ) {
V_10 -> V_55 &= ~ ( V_144 | V_230 | V_286 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
F_312 ( V_10 ) ;
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
F_277 ( V_10 -> V_156 ) ;
if ( F_161 ( V_5 ) ) {
F_152 ( V_422 , V_10 ) ;
}
}
F_308 ( V_10 ) ;
V_182:
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
}
static void F_159 ( struct V_9 * V_10 )
{
bool V_482 = false ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_154 != V_155 ) {
V_10 -> V_154 = V_300 ;
V_482 = true ;
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_482 )
F_16 ( V_10 , 0 ) ;
}
static void V_183 ( struct V_483 * V_484 )
{
struct V_9 * V_10 = F_313 ( F_314 ( V_484 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_162 V_485 ;
enum {
V_486 ,
V_487 ,
V_488 ,
} V_193 = V_486 ;
F_255 () ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_154 == V_300 ) {
V_193 = V_487 ;
V_10 -> V_154 = V_288 ;
} else if ( V_10 -> V_154 == V_303 ) {
V_193 = V_488 ;
V_10 -> V_154 = V_289 ;
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_193 == V_487 ) {
F_310 ( V_10 ) ;
goto V_182;
} else if ( V_193 == V_488 ) {
F_194 ( V_10 , 1 ) ;
goto V_182;
}
if ( ! V_10 -> V_480 && F_195 ( V_10 ) )
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
if ( V_10 -> V_480 == 0 ) {
V_10 -> V_55 &= ~ ( V_144 | V_230 | V_286 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_312 ( V_10 ) ;
goto V_182;
}
V_10 -> V_480 -- ;
F_16 ( V_10 ,
F_157 ( V_10 -> V_5 -> V_48 , V_228 ) ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_202 ( & V_10 -> V_160 , & V_485 ) ;
F_315 ( V_10 -> V_5 -> V_7 , & V_10 -> V_160 , & V_485 , & V_72 ) ;
V_182:
F_149 ( V_10 ) ;
F_95 () ;
}
static bool F_316 ( struct V_9 * V_10 )
{
struct V_9 * V_489 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_183 (ifpiter, &idev->addr_list, if_list) {
if ( V_489 -> V_166 > V_278 )
break;
if ( V_10 != V_489 && V_489 -> V_166 == V_278 &&
( V_489 -> V_55 & ( V_195 | V_144 |
V_230 | V_286 ) ) ==
V_195 )
return false ;
}
return true ;
}
static void F_312 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_162 V_474 ;
bool V_490 , V_491 ;
F_9 ( V_10 ) ;
F_152 ( V_422 , V_10 ) ;
F_173 ( & V_10 -> V_5 -> V_36 ) ;
V_491 = V_10 -> V_166 == V_278 && F_316 ( V_10 ) ;
V_490 = V_491 &&
F_306 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_63 > 0 &&
( V_7 -> V_55 & V_57 ) == 0 ;
F_179 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_491 )
F_317 ( V_10 -> V_5 ) ;
if ( V_490 ) {
if ( F_184 ( V_7 , & V_474 , V_144 ) )
return;
F_307 ( V_7 , & V_474 , & V_80 ) ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_475 = 1 ;
V_10 -> V_5 -> V_73 |= V_472 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_478 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_294 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list) {
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_55 & V_144 &&
V_10 -> V_154 == V_288 )
F_308 ( V_10 ) ;
F_128 ( & V_10 -> V_36 ) ;
}
F_179 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_318 ( struct V_492 * V_95 , T_8 V_493 )
{
struct V_9 * V_141 = NULL ;
struct V_494 * V_154 = V_95 -> V_495 ;
struct V_108 * V_108 = F_319 ( V_95 ) ;
int V_149 = 0 ;
if ( V_493 == 0 ) {
V_154 -> V_496 = 0 ;
V_154 -> V_497 = 0 ;
}
for (; V_154 -> V_496 < V_470 ; ++ V_154 -> V_496 ) {
F_193 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_188 ( F_34 ( V_141 -> V_5 -> V_7 ) , V_108 ) )
continue;
if ( V_149 < V_154 -> V_497 ) {
V_149 ++ ;
continue;
}
V_154 -> V_497 ++ ;
return V_141 ;
}
V_154 -> V_497 = 0 ;
V_149 = 0 ;
}
return NULL ;
}
static struct V_9 * F_320 ( struct V_492 * V_95 ,
struct V_9 * V_141 )
{
struct V_494 * V_154 = V_95 -> V_495 ;
struct V_108 * V_108 = F_319 ( V_95 ) ;
F_321 (ifa, addr_lst) {
if ( ! F_188 ( F_34 ( V_141 -> V_5 -> V_7 ) , V_108 ) )
continue;
V_154 -> V_497 ++ ;
return V_141 ;
}
while ( ++ V_154 -> V_496 < V_470 ) {
V_154 -> V_497 = 0 ;
F_193 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_188 ( F_34 ( V_141 -> V_5 -> V_7 ) , V_108 ) )
continue;
V_154 -> V_497 ++ ;
return V_141 ;
}
}
return NULL ;
}
static void * F_322 ( struct V_492 * V_95 , T_8 * V_493 )
__acquires( T_9 )
{
F_118 () ;
return F_318 ( V_95 , * V_493 ) ;
}
static void * F_323 ( struct V_492 * V_95 , void * V_498 , T_8 * V_493 )
{
struct V_9 * V_141 ;
V_141 = F_320 ( V_95 , V_498 ) ;
++ * V_493 ;
return V_141 ;
}
static void F_324 ( struct V_492 * V_95 , void * V_498 )
__releases( T_9 )
{
F_132 () ;
}
static int F_325 ( struct V_492 * V_95 , void * V_498 )
{
struct V_9 * V_10 = (struct V_9 * ) V_498 ;
F_326 ( V_95 , L_26 ,
& V_10 -> V_160 ,
V_10 -> V_5 -> V_7 -> V_91 ,
V_10 -> V_184 ,
V_10 -> V_166 ,
( T_3 ) V_10 -> V_55 ,
V_10 -> V_5 -> V_7 -> V_53 ) ;
return 0 ;
}
static int F_327 ( struct V_499 * V_499 , struct V_500 * V_500 )
{
return F_328 ( V_499 , V_500 , & V_501 ,
sizeof( struct V_494 ) ) ;
}
static int T_10 F_329 ( struct V_108 * V_108 )
{
if ( ! F_330 ( L_27 , V_502 , V_108 -> V_503 , & V_504 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_331 ( struct V_108 * V_108 )
{
F_332 ( L_27 , V_108 -> V_503 ) ;
}
int T_12 F_333 ( void )
{
return F_334 ( & V_505 ) ;
}
void F_335 ( void )
{
F_336 ( & V_505 ) ;
}
int F_337 ( struct V_108 * V_108 , const struct V_162 * V_160 )
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
static void F_267 ( void )
{
unsigned long V_217 , V_506 , V_507 , V_508 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_118 () ;
V_217 = V_13 ;
V_506 = F_338 ( V_217 + V_509 ) ;
F_10 ( & V_510 ) ;
for ( V_16 = 0 ; V_16 < V_470 ; V_16 ++ ) {
V_471:
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
goto V_471;
} else if ( V_10 -> V_168 == V_421 ) {
F_128 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_212 >= V_10 -> V_168 ) {
int V_511 = 0 ;
if ( ! ( V_10 -> V_55 & V_249 ) ) {
V_511 = 1 ;
V_10 -> V_55 |= V_249 ;
}
if ( ( V_10 -> V_167 != V_421 ) &&
( F_138 ( V_10 -> V_75 + V_10 -> V_167 * V_3 , V_506 ) ) )
V_506 = V_10 -> V_75 + V_10 -> V_167 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
if ( V_511 ) {
F_18 ( V_10 ) ;
F_152 ( 0 , V_10 ) ;
F_149 ( V_10 ) ;
goto V_471;
}
} else if ( ( V_10 -> V_55 & V_187 ) &&
! ( V_10 -> V_55 & V_144 ) ) {
unsigned long V_213 = V_10 -> V_5 -> V_39 . V_221 *
V_10 -> V_5 -> V_39 . V_227 *
F_157 ( V_10 -> V_5 -> V_48 , V_228 ) / V_3 ;
if ( V_212 >= V_10 -> V_168 - V_213 ) {
struct V_9 * V_204 = V_10 -> V_204 ;
if ( F_138 ( V_10 -> V_75 + V_10 -> V_168 * V_3 , V_506 ) )
V_506 = V_10 -> V_75 + V_10 -> V_168 * V_3 ;
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
goto V_471;
}
} else if ( F_138 ( V_10 -> V_75 + V_10 -> V_168 * V_3 - V_213 * V_3 , V_506 ) )
V_506 = V_10 -> V_75 + V_10 -> V_168 * V_3 - V_213 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
} else {
if ( F_138 ( V_10 -> V_75 + V_10 -> V_168 * V_3 , V_506 ) )
V_506 = V_10 -> V_75 + V_10 -> V_168 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
}
}
}
V_507 = F_338 ( V_506 ) ;
V_508 = V_506 ;
if ( F_138 ( V_507 , V_506 + V_512 ) )
V_508 = V_507 ;
if ( F_138 ( V_508 , V_13 + V_513 ) )
V_508 = V_13 + V_513 ;
F_38 ( V_514 L_28 ,
V_217 , V_506 , V_507 , V_508 ) ;
F_19 ( V_15 , & V_510 , V_508 - V_217 ) ;
F_132 () ;
}
static void F_339 ( struct V_483 * V_484 )
{
F_255 () ;
F_267 () ;
F_95 () ;
}
static void F_252 ( void )
{
F_19 ( V_15 , & V_510 , 0 ) ;
}
static struct V_162 * F_340 ( struct V_116 * V_160 , struct V_116 * V_515 ,
struct V_162 * * V_411 )
{
struct V_162 * V_327 = NULL ;
* V_411 = NULL ;
if ( V_160 )
V_327 = F_341 ( V_160 ) ;
if ( V_515 ) {
if ( V_327 && F_342 ( V_515 , V_327 , sizeof( * V_327 ) ) )
* V_411 = V_327 ;
V_327 = F_341 ( V_515 ) ;
}
return V_327 ;
}
static int
F_343 ( struct V_89 * V_90 , struct V_97 * V_98 )
{
struct V_108 * V_108 = F_72 ( V_90 -> V_115 ) ;
struct V_516 * V_517 ;
struct V_116 * V_117 [ V_518 + 1 ] ;
struct V_162 * V_327 , * V_411 ;
T_1 V_412 ;
int V_32 ;
V_32 = F_73 ( V_98 , sizeof( * V_517 ) , V_117 , V_518 , V_519 ) ;
if ( V_32 < 0 )
return V_32 ;
V_517 = F_61 ( V_98 ) ;
V_327 = F_340 ( V_117 [ V_520 ] , V_117 [ V_521 ] , & V_411 ) ;
if ( ! V_327 )
return - V_35 ;
V_412 = V_117 [ V_522 ] ? F_344 ( V_117 [ V_522 ] ) : V_517 -> V_412 ;
V_412 &= V_377 ;
return F_268 ( V_108 , V_517 -> V_523 , V_412 , V_327 ,
V_517 -> V_524 ) ;
}
static int F_345 ( struct V_9 * V_10 , T_1 V_412 ,
T_1 V_168 , T_1 V_167 )
{
T_1 V_55 ;
T_5 V_191 ;
unsigned long V_413 ;
bool V_525 ;
bool V_526 ;
F_29 () ;
if ( ! V_167 || ( V_168 > V_167 ) )
return - V_35 ;
if ( V_412 & V_377 &&
( V_10 -> V_55 & V_187 || V_10 -> V_184 != 64 ) )
return - V_35 ;
V_413 = F_137 ( V_167 , V_3 ) ;
if ( F_247 ( V_413 ) ) {
V_191 = F_249 ( V_413 * V_3 ) ;
V_167 = V_413 ;
V_55 = V_203 ;
} else {
V_191 = 0 ;
V_55 = 0 ;
V_412 |= V_195 ;
}
V_413 = F_137 ( V_168 , V_3 ) ;
if ( F_247 ( V_413 ) ) {
if ( V_413 == 0 )
V_412 |= V_249 ;
V_168 = V_413 ;
}
F_144 ( & V_10 -> V_36 ) ;
V_525 = V_10 -> V_55 & V_377 ;
V_526 = V_10 -> V_55 & V_195 &&
! ( V_10 -> V_55 & V_196 ) ;
V_10 -> V_55 &= ~ ( V_249 | V_195 | V_481 |
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
} else if ( V_526 ) {
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
if ( V_525 || V_10 -> V_55 & V_377 ) {
if ( V_525 && ! ( V_10 -> V_55 & V_377 ) )
V_167 = V_168 = 0 ;
F_241 ( V_10 -> V_5 , V_10 , V_167 , V_168 ,
! V_525 , V_13 ) ;
}
F_267 () ;
return 0 ;
}
static int
F_346 ( struct V_89 * V_90 , struct V_97 * V_98 )
{
struct V_108 * V_108 = F_72 ( V_90 -> V_115 ) ;
struct V_516 * V_517 ;
struct V_116 * V_117 [ V_518 + 1 ] ;
struct V_162 * V_327 , * V_411 ;
struct V_9 * V_141 ;
struct V_6 * V_7 ;
T_1 V_167 = V_421 , V_293 = V_421 ;
T_1 V_412 ;
int V_32 ;
V_32 = F_73 ( V_98 , sizeof( * V_517 ) , V_117 , V_518 , V_519 ) ;
if ( V_32 < 0 )
return V_32 ;
V_517 = F_61 ( V_98 ) ;
V_327 = F_340 ( V_117 [ V_520 ] , V_117 [ V_521 ] , & V_411 ) ;
if ( ! V_327 )
return - V_35 ;
if ( V_117 [ V_527 ] ) {
struct V_528 * V_529 ;
V_529 = F_341 ( V_117 [ V_527 ] ) ;
V_167 = V_529 -> V_530 ;
V_293 = V_529 -> V_531 ;
} else {
V_293 = V_421 ;
V_167 = V_421 ;
}
V_7 = F_75 ( V_108 , V_517 -> V_523 ) ;
if ( ! V_7 )
return - V_176 ;
V_412 = V_117 [ V_522 ] ? F_344 ( V_117 [ V_522 ] ) : V_517 -> V_412 ;
V_412 &= V_481 | V_254 | V_377 |
V_196 | V_414 ;
V_141 = F_192 ( V_108 , V_327 , V_7 , 1 ) ;
if ( ! V_141 ) {
return F_266 ( V_108 , V_517 -> V_523 , V_327 , V_411 ,
V_517 -> V_524 , V_412 ,
V_293 , V_167 ) ;
}
if ( V_98 -> V_532 & V_533 ||
! ( V_98 -> V_532 & V_534 ) )
V_32 = - V_181 ;
else
V_32 = F_345 ( V_141 , V_412 , V_293 , V_167 ) ;
F_149 ( V_141 ) ;
return V_32 ;
}
static void F_347 ( struct V_97 * V_98 , T_3 V_535 , T_1 V_55 ,
T_3 V_166 , int V_91 )
{
struct V_516 * V_517 ;
V_517 = F_61 ( V_98 ) ;
V_517 -> V_536 = V_102 ;
V_517 -> V_524 = V_535 ;
V_517 -> V_412 = V_55 ;
V_517 -> V_431 = V_166 ;
V_517 -> V_523 = V_91 ;
}
static int F_348 ( struct V_89 * V_90 , unsigned long V_1 ,
unsigned long V_75 , T_1 V_537 , T_1 V_367 )
{
struct V_528 V_529 ;
V_529 . V_1 = F_1 ( V_1 ) ;
V_529 . V_75 = F_1 ( V_75 ) ;
V_529 . V_531 = V_537 ;
V_529 . V_530 = V_367 ;
return F_349 ( V_90 , V_527 , sizeof( V_529 ) , & V_529 ) ;
}
static inline int F_350 ( int V_431 )
{
if ( V_431 & V_282 )
return V_433 ;
else if ( V_431 & V_278 )
return V_432 ;
else if ( V_431 & V_538 )
return V_539 ;
else
return V_540 ;
}
static inline int F_351 ( void )
{
return F_56 ( sizeof( struct V_516 ) )
+ F_57 ( 16 )
+ F_57 ( 16 )
+ F_57 ( sizeof( struct V_528 ) )
+ F_57 ( 4 ) ;
}
static int F_352 ( struct V_89 * V_90 , struct V_9 * V_141 ,
T_1 V_94 , T_1 V_95 , int V_96 , unsigned int V_55 )
{
struct V_97 * V_98 ;
T_1 V_537 , V_367 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( struct V_516 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
F_347 ( V_98 , V_141 -> V_184 , V_141 -> V_55 , F_350 ( V_141 -> V_166 ) ,
V_141 -> V_5 -> V_7 -> V_91 ) ;
if ( ! ( ( V_141 -> V_55 & V_195 ) &&
( V_141 -> V_168 == V_421 ) ) ) {
V_537 = V_141 -> V_168 ;
V_367 = V_141 -> V_167 ;
if ( V_537 != V_421 ) {
long V_541 = ( V_13 - V_141 -> V_75 ) / V_3 ;
if ( V_537 > V_541 )
V_537 -= V_541 ;
else
V_537 = 0 ;
if ( V_367 != V_421 ) {
if ( V_367 > V_541 )
V_367 -= V_541 ;
else
V_367 = 0 ;
}
}
} else {
V_537 = V_421 ;
V_367 = V_421 ;
}
if ( ! F_206 ( & V_141 -> V_164 ) ) {
if ( F_353 ( V_90 , V_521 , & V_141 -> V_160 ) < 0 ||
F_353 ( V_90 , V_520 , & V_141 -> V_164 ) < 0 )
goto error;
} else
if ( F_353 ( V_90 , V_520 , & V_141 -> V_160 ) < 0 )
goto error;
if ( F_348 ( V_90 , V_141 -> V_1 , V_141 -> V_75 , V_537 , V_367 ) < 0 )
goto error;
if ( F_354 ( V_90 , V_522 , V_141 -> V_55 ) < 0 )
goto error;
F_63 ( V_90 , V_98 ) ;
return 0 ;
error:
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
static int F_355 ( struct V_89 * V_90 , struct V_542 * V_543 ,
T_1 V_94 , T_1 V_95 , int V_96 , T_13 V_55 )
{
struct V_97 * V_98 ;
T_3 V_166 = V_540 ;
int V_91 = V_543 -> V_5 -> V_7 -> V_91 ;
if ( F_158 ( & V_543 -> V_544 ) & V_538 )
V_166 = V_539 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( struct V_516 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
F_347 ( V_98 , 128 , V_195 , V_166 , V_91 ) ;
if ( F_353 ( V_90 , V_545 , & V_543 -> V_544 ) < 0 ||
F_348 ( V_90 , V_543 -> V_546 , V_543 -> V_547 ,
V_421 , V_421 ) < 0 ) {
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
F_63 ( V_90 , V_98 ) ;
return 0 ;
}
static int F_356 ( struct V_89 * V_90 , struct V_548 * V_549 ,
T_1 V_94 , T_1 V_95 , int V_96 , unsigned int V_55 )
{
struct V_97 * V_98 ;
T_3 V_166 = V_540 ;
int V_91 = V_549 -> V_550 -> V_7 -> V_91 ;
if ( F_158 ( & V_549 -> V_551 ) & V_538 )
V_166 = V_539 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( struct V_516 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
F_347 ( V_98 , 128 , V_195 , V_166 , V_91 ) ;
if ( F_353 ( V_90 , V_552 , & V_549 -> V_551 ) < 0 ||
F_348 ( V_90 , V_549 -> V_553 , V_549 -> V_554 ,
V_421 , V_421 ) < 0 ) {
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
F_63 ( V_90 , V_98 ) ;
return 0 ;
}
static int F_357 ( struct V_4 * V_5 , struct V_89 * V_90 ,
struct V_125 * V_126 , enum V_555 type ,
int V_556 , int * V_557 )
{
struct V_542 * V_543 ;
struct V_548 * V_549 ;
int V_32 = 1 ;
int V_558 = * V_557 ;
F_173 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_559 : {
struct V_9 * V_141 ;
F_87 (ifa, &idev->addr_list, if_list) {
if ( ++ V_558 < V_556 )
continue;
V_32 = F_352 ( V_90 , V_141 ,
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
case V_560 :
for ( V_543 = V_5 -> V_561 ; V_543 ;
V_543 = V_543 -> V_506 , V_558 ++ ) {
if ( V_558 < V_556 )
continue;
V_32 = F_355 ( V_90 , V_543 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_562 ,
V_138 ) ;
if ( V_32 < 0 )
break;
}
break;
case V_563 :
for ( V_549 = V_5 -> V_564 ; V_549 ;
V_549 = V_549 -> V_565 , V_558 ++ ) {
if ( V_558 < V_556 )
continue;
V_32 = F_356 ( V_90 , V_549 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_566 ,
V_138 ) ;
if ( V_32 < 0 )
break;
}
break;
default:
break;
}
F_179 ( & V_5 -> V_36 ) ;
* V_557 = V_558 ;
return V_32 ;
}
static int F_358 ( struct V_89 * V_90 , struct V_125 * V_126 ,
enum V_555 type )
{
struct V_108 * V_108 = F_72 ( V_90 -> V_115 ) ;
int V_127 , V_128 ;
int V_129 , V_558 ;
int V_130 , V_556 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_131 * V_132 ;
V_128 = V_126 -> args [ 0 ] ;
V_130 = V_129 = V_126 -> args [ 1 ] ;
V_556 = V_558 = V_126 -> args [ 2 ] ;
F_79 () ;
V_126 -> V_95 = F_80 ( & V_108 -> V_18 . V_135 ) ^ V_108 -> V_136 ;
for ( V_127 = V_128 ; V_127 < V_133 ; V_127 ++ , V_130 = 0 ) {
V_129 = 0 ;
V_132 = & V_108 -> V_134 [ V_127 ] ;
F_81 (dev, head, index_hlist) {
if ( V_129 < V_130 )
goto V_137;
if ( V_127 > V_128 || V_129 > V_130 )
V_556 = 0 ;
V_558 = 0 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_137;
if ( F_357 ( V_5 , V_90 , V_126 , type ,
V_556 , & V_558 ) < 0 )
goto V_139;
V_137:
V_129 ++ ;
}
}
V_139:
F_82 () ;
V_126 -> args [ 0 ] = V_127 ;
V_126 -> args [ 1 ] = V_129 ;
V_126 -> args [ 2 ] = V_558 ;
return V_90 -> V_140 ;
}
static int F_359 ( struct V_89 * V_90 , struct V_125 * V_126 )
{
enum V_555 type = V_559 ;
return F_358 ( V_90 , V_126 , type ) ;
}
static int F_360 ( struct V_89 * V_90 , struct V_125 * V_126 )
{
enum V_555 type = V_560 ;
return F_358 ( V_90 , V_126 , type ) ;
}
static int F_361 ( struct V_89 * V_90 , struct V_125 * V_126 )
{
enum V_555 type = V_563 ;
return F_358 ( V_90 , V_126 , type ) ;
}
static int F_362 ( struct V_89 * V_114 , struct V_97 * V_98 )
{
struct V_108 * V_108 = F_72 ( V_114 -> V_115 ) ;
struct V_516 * V_517 ;
struct V_116 * V_117 [ V_518 + 1 ] ;
struct V_162 * V_160 = NULL , * V_567 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_141 ;
struct V_89 * V_90 ;
int V_32 ;
V_32 = F_73 ( V_98 , sizeof( * V_517 ) , V_117 , V_518 , V_519 ) ;
if ( V_32 < 0 )
goto V_111;
V_160 = F_340 ( V_117 [ V_520 ] , V_117 [ V_521 ] , & V_567 ) ;
if ( ! V_160 ) {
V_32 = - V_35 ;
goto V_111;
}
V_517 = F_61 ( V_98 ) ;
if ( V_517 -> V_523 )
V_7 = F_75 ( V_108 , V_517 -> V_523 ) ;
V_141 = F_192 ( V_108 , V_160 , V_7 , 1 ) ;
if ( ! V_141 ) {
V_32 = - V_175 ;
goto V_111;
}
V_90 = F_66 ( F_351 () , V_25 ) ;
if ( ! V_90 ) {
V_32 = - V_109 ;
goto V_568;
}
V_32 = F_352 ( V_90 , V_141 , F_76 ( V_114 ) . V_94 ,
V_98 -> V_124 , V_422 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_568;
}
V_32 = F_77 ( V_90 , V_108 , F_76 ( V_114 ) . V_94 ) ;
V_568:
F_149 ( V_141 ) ;
V_111:
return V_32 ;
}
static void F_363 ( int V_96 , struct V_9 * V_141 )
{
struct V_89 * V_90 ;
struct V_108 * V_108 = F_34 ( V_141 -> V_5 -> V_7 ) ;
int V_32 = - V_109 ;
V_90 = F_66 ( F_351 () , V_110 ) ;
if ( ! V_90 )
goto V_111;
V_32 = F_352 ( V_90 , V_141 , 0 , 0 , V_96 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_111;
}
F_69 ( V_90 , V_108 , 0 , V_569 , NULL , V_110 ) ;
return;
V_111:
if ( V_32 < 0 )
F_70 ( V_108 , V_569 , V_32 ) ;
}
static inline void F_364 ( struct V_92 * V_39 ,
T_2 * V_570 , int V_571 )
{
F_365 ( V_571 < ( V_572 * 4 ) ) ;
memset ( V_570 , 0 , V_571 ) ;
V_570 [ V_573 ] = V_39 -> V_50 ;
V_570 [ V_574 ] = V_39 -> V_575 ;
V_570 [ V_576 ] = V_39 -> V_46 ;
V_570 [ V_577 ] = V_39 -> V_578 ;
V_570 [ V_579 ] = V_39 -> V_580 ;
V_570 [ V_581 ] = V_39 -> V_373 ;
V_570 [ V_582 ] = V_39 -> V_227 ;
V_570 [ V_583 ] = V_39 -> V_63 ;
V_570 [ V_584 ] =
F_366 ( V_39 -> V_478 ) ;
V_570 [ V_585 ] =
F_366 ( V_39 -> V_477 ) ;
V_570 [ V_586 ] = V_39 -> V_587 ;
V_570 [ V_588 ] =
F_366 ( V_39 -> V_589 ) ;
V_570 [ V_590 ] =
F_366 ( V_39 -> V_591 ) ;
V_570 [ V_592 ] = V_39 -> V_70 ;
V_570 [ V_593 ] = V_39 -> V_224 ;
V_570 [ V_594 ] = V_39 -> V_225 ;
V_570 [ V_595 ] = V_39 -> V_221 ;
V_570 [ V_596 ] = V_39 -> V_226 ;
V_570 [ V_597 ] = V_39 -> V_298 ;
V_570 [ V_598 ] = V_39 -> V_599 ;
V_570 [ V_600 ] = V_39 -> V_601 ;
V_570 [ V_602 ] = V_39 -> V_603 ;
#ifdef F_367
V_570 [ V_604 ] = V_39 -> V_605 ;
V_570 [ V_606 ] =
F_366 ( V_39 -> V_607 ) ;
#ifdef F_368
V_570 [ V_608 ] = V_39 -> V_609 ;
#endif
#endif
V_570 [ V_610 ] = V_39 -> V_106 ;
V_570 [ V_611 ] = V_39 -> V_612 ;
#ifdef F_162
V_570 [ V_613 ] = V_39 -> V_233 ;
V_570 [ V_614 ] = V_39 -> V_234 ;
#endif
#ifdef F_58
V_570 [ V_615 ] = V_39 -> V_105 ;
#endif
V_570 [ V_616 ] = V_39 -> V_178 ;
V_570 [ V_617 ] = V_39 -> V_58 ;
V_570 [ V_618 ] = V_39 -> V_619 ;
V_570 [ V_620 ] = V_39 -> V_621 ;
V_570 [ V_622 ] = V_39 -> V_623 ;
V_570 [ V_624 ] = V_39 -> V_625 ;
V_570 [ V_626 ] = V_39 -> V_627 ;
V_570 [ V_628 ] = V_39 -> V_107 ;
V_570 [ V_629 ] = V_39 -> V_276 ;
}
static inline T_14 F_369 ( void )
{
return F_57 ( 4 )
+ F_57 ( sizeof( struct V_630 ) )
+ F_57 ( V_572 * 4 )
+ F_57 ( V_631 * 8 )
+ F_57 ( V_632 * 8 )
+ F_57 ( sizeof( struct V_162 ) ) ;
}
static inline T_14 F_370 ( void )
{
return F_56 ( sizeof( struct V_633 ) )
+ F_57 ( V_634 )
+ F_57 ( V_449 )
+ F_57 ( 4 )
+ F_57 ( 4 )
+ F_57 ( 1 )
+ F_57 ( F_369 () ) ;
}
static inline void F_371 ( T_15 * V_17 , T_16 * V_635 ,
int V_636 , int V_571 )
{
int V_16 ;
int V_637 = V_571 - sizeof( T_15 ) * V_636 ;
F_365 ( V_637 < 0 ) ;
F_372 ( V_636 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_636 ; V_16 ++ )
F_372 ( F_373 ( & V_635 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_636 ] , 0 , V_637 ) ;
}
static inline void F_374 ( T_15 * V_17 , void T_17 * V_635 ,
int V_571 , T_14 V_638 )
{
int V_16 , V_639 ;
T_15 V_640 [ V_631 ] ;
int V_637 = V_571 - sizeof( T_15 ) * V_631 ;
F_365 ( V_637 < 0 ) ;
memset ( V_640 , 0 , sizeof( V_640 ) ) ;
V_640 [ 0 ] = V_631 ;
F_22 (c) {
for ( V_16 = 1 ; V_16 < V_631 ; V_16 ++ )
V_640 [ V_16 ] += F_375 ( V_635 , V_639 , V_16 , V_638 ) ;
}
memcpy ( V_17 , V_640 , V_631 * sizeof( T_15 ) ) ;
memset ( & V_17 [ V_631 ] , 0 , V_637 ) ;
}
static void F_376 ( T_15 * V_17 , struct V_4 * V_5 , int V_641 ,
int V_571 )
{
switch ( V_641 ) {
case V_642 :
F_374 ( V_17 , V_5 -> V_17 . V_18 , V_571 ,
F_377 ( struct V_19 , V_22 ) ) ;
break;
case V_643 :
F_371 ( V_17 , V_5 -> V_17 . V_23 -> V_644 , V_632 , V_571 ) ;
break;
}
}
static int F_378 ( struct V_89 * V_90 , struct V_4 * V_5 ,
T_1 V_645 )
{
struct V_116 * V_646 ;
struct V_630 V_529 ;
if ( F_354 ( V_90 , V_647 , V_5 -> V_73 ) )
goto V_104;
V_529 . V_648 = V_649 ;
V_529 . V_75 = F_1 ( V_5 -> V_75 ) ;
V_529 . V_650 = F_366 ( V_5 -> V_48 -> V_650 ) ;
V_529 . V_651 = F_366 ( F_157 ( V_5 -> V_48 , V_228 ) ) ;
if ( F_349 ( V_90 , V_652 , sizeof( V_529 ) , & V_529 ) )
goto V_104;
V_646 = F_379 ( V_90 , V_653 , V_572 * sizeof( V_654 ) ) ;
if ( ! V_646 )
goto V_104;
F_364 ( & V_5 -> V_39 , F_341 ( V_646 ) , F_380 ( V_646 ) ) ;
if ( V_645 & V_655 )
return 0 ;
V_646 = F_379 ( V_90 , V_642 , V_631 * sizeof( T_15 ) ) ;
if ( ! V_646 )
goto V_104;
F_376 ( F_341 ( V_646 ) , V_5 , V_642 , F_380 ( V_646 ) ) ;
V_646 = F_379 ( V_90 , V_643 , V_632 * sizeof( T_15 ) ) ;
if ( ! V_646 )
goto V_104;
F_376 ( F_341 ( V_646 ) , V_5 , V_643 , F_380 ( V_646 ) ) ;
V_646 = F_379 ( V_90 , V_656 , sizeof( struct V_162 ) ) ;
if ( ! V_646 )
goto V_104;
if ( F_381 ( V_90 , V_657 , V_5 -> V_43 ) )
goto V_104;
F_173 ( & V_5 -> V_36 ) ;
memcpy ( F_341 ( V_646 ) , V_5 -> V_71 . V_218 , F_380 ( V_646 ) ) ;
F_179 ( & V_5 -> V_36 ) ;
return 0 ;
V_104:
return - V_100 ;
}
static T_14 F_382 ( const struct V_6 * V_7 ,
T_1 V_645 )
{
if ( ! F_52 ( V_7 ) )
return 0 ;
return F_369 () ;
}
static int F_383 ( struct V_89 * V_90 , const struct V_6 * V_7 ,
T_1 V_645 )
{
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_658 ;
if ( F_378 ( V_90 , V_5 , V_645 ) < 0 )
return - V_100 ;
return 0 ;
}
static int F_384 ( struct V_4 * V_5 , struct V_162 * V_71 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_659 = false ;
struct V_162 V_660 ;
F_29 () ;
if ( ! V_71 )
return - V_35 ;
if ( F_206 ( V_71 ) )
return - V_35 ;
if ( V_7 -> V_55 & ( V_57 | V_56 ) )
return - V_35 ;
if ( ! F_306 ( V_5 ) )
return - V_35 ;
if ( V_5 -> V_39 . V_63 <= 0 )
return - V_35 ;
F_147 ( & V_5 -> V_36 ) ;
F_281 ( sizeof( V_71 -> V_218 ) != 16 ) ;
memcpy ( V_5 -> V_71 . V_218 + 8 , V_71 -> V_218 + 8 , 8 ) ;
F_151 ( & V_5 -> V_36 ) ;
if ( ! V_5 -> V_81 && ( V_5 -> V_73 & V_74 ) &&
! F_184 ( V_7 , & V_660 , V_144 |
V_230 ) ) {
F_307 ( V_7 , & V_660 , & V_80 ) ;
V_659 = true ;
}
F_147 ( & V_5 -> V_36 ) ;
if ( V_659 ) {
V_5 -> V_73 |= V_472 ;
V_5 -> V_475 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_478 ) ;
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
F_295 ( V_463 , V_5 ) ;
F_267 () ;
return 0 ;
}
static int F_385 ( const struct V_6 * V_7 ,
const struct V_116 * V_646 )
{
struct V_116 * V_117 [ V_661 + 1 ] ;
if ( V_7 && ! F_52 ( V_7 ) )
return - V_662 ;
return F_386 ( V_117 , V_661 , V_646 , V_663 ) ;
}
static int F_387 ( struct V_6 * V_7 , const struct V_116 * V_646 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
struct V_116 * V_117 [ V_661 + 1 ] ;
if ( ! V_5 )
return - V_662 ;
if ( F_386 ( V_117 , V_661 , V_646 , NULL ) < 0 )
F_388 () ;
if ( V_117 [ V_656 ] ) {
V_32 = F_384 ( V_5 , F_341 ( V_117 [ V_656 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_117 [ V_657 ] ) {
T_3 V_664 = F_389 ( V_117 [ V_657 ] ) ;
if ( V_664 != V_45 &&
V_664 != V_665 &&
V_664 != V_44 )
return - V_35 ;
if ( V_664 == V_44 &&
! V_5 -> V_39 . V_41 . V_42 &&
! F_34 ( V_7 ) -> V_18 . V_40 -> V_41 . V_42 )
return - V_35 ;
V_5 -> V_43 = V_664 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_390 ( struct V_89 * V_90 , struct V_4 * V_5 ,
T_1 V_94 , T_1 V_95 , int V_96 , unsigned int V_55 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_633 * V_666 ;
struct V_97 * V_98 ;
void * V_667 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( * V_666 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
V_666 = F_61 ( V_98 ) ;
V_666 -> V_668 = V_102 ;
V_666 -> V_669 = 0 ;
V_666 -> V_670 = V_7 -> type ;
V_666 -> V_671 = V_7 -> V_91 ;
V_666 -> V_672 = F_391 ( V_7 ) ;
V_666 -> V_673 = 0 ;
if ( F_392 ( V_90 , V_674 , V_7 -> V_53 ) ||
( V_7 -> V_306 &&
F_349 ( V_90 , V_675 , V_7 -> V_306 , V_7 -> V_308 ) ) ||
F_354 ( V_90 , V_676 , V_7 -> V_33 ) ||
( V_7 -> V_91 != F_393 ( V_7 ) &&
F_354 ( V_90 , V_677 , F_393 ( V_7 ) ) ) ||
F_381 ( V_90 , V_678 ,
F_44 ( V_7 ) ? V_7 -> V_679 : V_680 ) )
goto V_104;
V_667 = F_394 ( V_90 , V_681 ) ;
if ( ! V_667 )
goto V_104;
if ( F_378 ( V_90 , V_5 , 0 ) < 0 )
goto V_104;
F_395 ( V_90 , V_667 ) ;
F_63 ( V_90 , V_98 ) ;
return 0 ;
V_104:
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
static int F_396 ( struct V_89 * V_90 , struct V_125 * V_126 )
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
if ( F_390 ( V_90 , V_5 ,
F_76 ( V_126 -> V_90 ) . V_94 ,
V_126 -> V_98 -> V_124 ,
V_463 , V_138 ) < 0 )
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
void F_295 ( int V_96 , struct V_4 * V_5 )
{
struct V_89 * V_90 ;
struct V_108 * V_108 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_109 ;
V_90 = F_66 ( F_370 () , V_110 ) ;
if ( ! V_90 )
goto V_111;
V_32 = F_390 ( V_90 , V_5 , 0 , 0 , V_96 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_111;
}
F_69 ( V_90 , V_108 , 0 , V_682 , NULL , V_110 ) ;
return;
V_111:
if ( V_32 < 0 )
F_70 ( V_108 , V_682 , V_32 ) ;
}
static inline T_14 F_397 ( void )
{
return F_56 ( sizeof( struct V_683 ) )
+ F_57 ( sizeof( struct V_162 ) )
+ F_57 ( sizeof( struct V_684 ) ) ;
}
static int F_398 ( struct V_89 * V_90 , struct V_4 * V_5 ,
struct V_363 * V_364 , T_1 V_94 , T_1 V_95 ,
int V_96 , unsigned int V_55 )
{
struct V_683 * V_685 ;
struct V_97 * V_98 ;
struct V_684 V_529 ;
V_98 = F_60 ( V_90 , V_94 , V_95 , V_96 , sizeof( * V_685 ) , V_55 ) ;
if ( ! V_98 )
return - V_100 ;
V_685 = F_61 ( V_98 ) ;
V_685 -> V_686 = V_102 ;
V_685 -> V_687 = 0 ;
V_685 -> V_688 = 0 ;
V_685 -> V_689 = V_5 -> V_7 -> V_91 ;
V_685 -> V_184 = V_364 -> V_184 ;
V_685 -> V_690 = V_364 -> type ;
V_685 -> V_691 = 0 ;
V_685 -> V_692 = 0 ;
if ( V_364 -> V_283 )
V_685 -> V_692 |= V_693 ;
if ( V_364 -> V_373 )
V_685 -> V_692 |= V_694 ;
if ( F_349 ( V_90 , V_695 , sizeof( V_364 -> V_365 ) , & V_364 -> V_365 ) )
goto V_104;
V_529 . V_696 = F_244 ( V_364 -> V_368 ) ;
V_529 . V_697 = F_244 ( V_364 -> V_367 ) ;
if ( F_349 ( V_90 , V_698 , sizeof( V_529 ) , & V_529 ) )
goto V_104;
F_63 ( V_90 , V_98 ) ;
return 0 ;
V_104:
F_64 ( V_90 , V_98 ) ;
return - V_100 ;
}
static void F_253 ( int V_96 , struct V_4 * V_5 ,
struct V_363 * V_364 )
{
struct V_89 * V_90 ;
struct V_108 * V_108 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_109 ;
V_90 = F_66 ( F_397 () , V_110 ) ;
if ( ! V_90 )
goto V_111;
V_32 = F_398 ( V_90 , V_5 , V_364 , 0 , 0 , V_96 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_100 ) ;
F_68 ( V_90 ) ;
goto V_111;
}
F_69 ( V_90 , V_108 , 0 , V_699 , NULL , V_110 ) ;
return;
V_111:
if ( V_32 < 0 )
F_70 ( V_108 , V_699 , V_32 ) ;
}
static void F_303 ( int V_96 , struct V_9 * V_10 )
{
struct V_108 * V_108 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_96 )
F_29 () ;
F_363 ( V_96 ? : V_422 , V_10 ) ;
switch ( V_96 ) {
case V_422 :
if ( ! ( V_10 -> V_156 -> V_700 ) )
F_277 ( V_10 -> V_156 ) ;
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
F_399 ( V_108 ) ;
break;
}
F_400 ( & V_108 -> V_18 . V_135 ) ;
}
static void F_152 ( int V_96 , struct V_9 * V_10 )
{
F_118 () ;
if ( F_133 ( V_10 -> V_5 -> V_81 == 0 ) )
F_303 ( V_96 , V_10 ) ;
F_132 () ;
}
static
int F_401 ( struct V_147 * V_701 , int V_702 ,
void T_6 * V_703 , T_14 * V_704 , T_8 * V_705 )
{
int * V_706 = V_701 -> V_326 ;
int V_707 = * V_706 ;
T_8 V_493 = * V_705 ;
struct V_147 V_708 ;
int V_215 ;
V_708 = * V_701 ;
V_708 . V_326 = & V_707 ;
V_215 = F_402 ( & V_708 , V_702 , V_703 , V_704 , V_705 ) ;
if ( V_702 )
V_215 = F_92 ( V_701 , V_706 , V_707 ) ;
if ( V_215 )
* V_705 = V_493 ;
return V_215 ;
}
static
int F_403 ( struct V_147 * V_701 , int V_702 ,
void T_6 * V_703 , T_14 * V_704 , T_8 * V_705 )
{
struct V_4 * V_5 = V_701 -> V_152 ;
int V_709 = V_34 ;
struct V_147 V_708 ;
V_708 = * V_701 ;
V_708 . V_152 = & V_709 ;
V_708 . V_151 = V_5 ? & V_5 -> V_7 -> V_33 : NULL ;
return F_404 ( & V_708 , V_702 , V_703 , V_704 , V_705 ) ;
}
static void F_405 ( struct V_4 * V_5 )
{
struct V_710 V_711 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_406 ( & V_711 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_178 )
F_289 ( NULL , V_206 , & V_711 ) ;
else
F_289 ( NULL , V_189 , & V_711 ) ;
}
static void F_407 ( struct V_108 * V_108 , T_2 V_145 )
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
F_405 ( V_5 ) ;
}
}
F_82 () ;
}
static int F_408 ( struct V_147 * V_148 , int * V_149 , int V_145 )
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
F_407 ( V_108 , V_145 ) ;
} else if ( ( ! V_145 ) ^ ( ! V_150 ) )
F_405 ( (struct V_4 * ) V_148 -> V_152 ) ;
F_95 () ;
return 0 ;
}
static
int F_409 ( struct V_147 * V_701 , int V_702 ,
void T_6 * V_703 , T_14 * V_704 , T_8 * V_705 )
{
int * V_706 = V_701 -> V_326 ;
int V_707 = * V_706 ;
T_8 V_493 = * V_705 ;
struct V_147 V_708 ;
int V_215 ;
V_708 = * V_701 ;
V_708 . V_326 = & V_707 ;
V_215 = F_402 ( & V_708 , V_702 , V_703 , V_704 , V_705 ) ;
if ( V_702 )
V_215 = F_408 ( V_701 , V_706 , V_707 ) ;
if ( V_215 )
* V_705 = V_493 ;
return V_215 ;
}
static
int F_410 ( struct V_147 * V_701 , int V_702 ,
void T_6 * V_703 , T_14 * V_704 , T_8 * V_705 )
{
int * V_706 = V_701 -> V_326 ;
int V_215 ;
int V_150 , V_712 ;
V_150 = * V_706 ;
V_215 = F_402 ( V_701 , V_702 , V_703 , V_704 , V_705 ) ;
V_712 = * V_706 ;
if ( V_702 && V_150 != V_712 ) {
struct V_108 * V_108 = V_701 -> V_151 ;
if ( ! F_93 () )
return F_94 () ;
if ( V_706 == & V_108 -> V_18 . V_40 -> V_106 )
F_65 ( V_108 , V_87 ,
V_123 ,
V_108 -> V_18 . V_40 ) ;
else if ( V_706 == & V_108 -> V_18 . V_122 -> V_106 )
F_65 ( V_108 , V_87 ,
V_121 ,
V_108 -> V_18 . V_122 ) ;
else {
struct V_4 * V_5 = V_701 -> V_152 ;
F_65 ( V_108 , V_87 ,
V_5 -> V_7 -> V_91 ,
& V_5 -> V_39 ) ;
}
F_95 () ;
}
return V_215 ;
}
static int F_411 ( struct V_147 * V_701 , int V_702 ,
void T_6 * V_703 , T_14 * V_704 ,
T_8 * V_705 )
{
int V_32 ;
struct V_162 V_160 ;
char V_713 [ V_714 ] ;
struct V_147 V_708 = * V_701 ;
struct V_108 * V_108 = V_701 -> V_151 ;
struct V_715 * V_447 = V_701 -> V_326 ;
if ( & V_108 -> V_18 . V_122 -> V_41 == V_701 -> V_326 )
return - V_716 ;
V_708 . V_717 = V_714 ;
V_708 . V_326 = V_713 ;
if ( ! F_93 () )
return F_94 () ;
if ( ! V_702 && ! V_447 -> V_42 ) {
V_32 = - V_716 ;
goto V_182;
}
V_32 = snprintf ( V_713 , sizeof( V_713 ) , L_29 , & V_447 -> V_447 ) ;
if ( V_32 >= sizeof( V_713 ) ) {
V_32 = - V_716 ;
goto V_182;
}
V_32 = F_412 ( & V_708 , V_702 , V_703 , V_704 , V_705 ) ;
if ( V_32 || ! V_702 )
goto V_182;
if ( F_413 ( V_713 , - 1 , V_160 . V_718 . V_719 , - 1 , NULL ) != 1 ) {
V_32 = - V_716 ;
goto V_182;
}
V_447 -> V_42 = true ;
V_447 -> V_447 = V_160 ;
if ( & V_108 -> V_18 . V_40 -> V_41 == V_701 -> V_326 ) {
struct V_6 * V_7 ;
F_91 (net, dev) {
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_43 =
V_44 ;
}
}
} else {
struct V_4 * V_5 = V_701 -> V_152 ;
V_5 -> V_43 = V_44 ;
}
V_182:
F_95 () ;
return V_32 ;
}
static
int F_414 ( struct V_147 * V_701 ,
int V_702 ,
void T_6 * V_703 ,
T_14 * V_704 ,
T_8 * V_705 )
{
int * V_706 = V_701 -> V_326 ;
int V_707 = * V_706 ;
T_8 V_493 = * V_705 ;
struct V_147 V_708 ;
int V_215 ;
V_708 = * V_701 ;
V_708 . V_326 = & V_707 ;
V_215 = F_402 ( & V_708 , V_702 , V_703 , V_704 , V_705 ) ;
if ( V_702 )
V_215 = F_98 ( V_701 , V_706 , V_707 ) ;
if ( V_215 )
* V_705 = V_493 ;
return V_215 ;
}
static int F_415 ( struct V_108 * V_108 , char * V_720 ,
struct V_4 * V_5 , struct V_92 * V_149 )
{
int V_16 ;
struct V_721 * V_722 ;
char V_723 [ sizeof( L_30 ) + V_634 ] ;
V_722 = F_416 ( & V_724 , sizeof( * V_722 ) , V_25 ) ;
if ( ! V_722 )
goto V_182;
for ( V_16 = 0 ; V_722 -> V_725 [ V_16 ] . V_326 ; V_16 ++ ) {
V_722 -> V_725 [ V_16 ] . V_326 += ( char * ) V_149 - ( char * ) & V_92 ;
V_722 -> V_725 [ V_16 ] . V_152 = V_5 ;
V_722 -> V_725 [ V_16 ] . V_151 = V_108 ;
}
snprintf ( V_723 , sizeof( V_723 ) , L_31 , V_720 ) ;
V_722 -> V_726 = F_417 ( V_108 , V_723 , V_722 -> V_725 ) ;
if ( ! V_722 -> V_726 )
goto free;
V_149 -> V_47 = V_722 ;
return 0 ;
free:
F_26 ( V_722 ) ;
V_182:
return - V_109 ;
}
static void F_418 ( struct V_92 * V_149 )
{
struct V_721 * V_722 ;
if ( ! V_149 -> V_47 )
return;
V_722 = V_149 -> V_47 ;
V_149 -> V_47 = NULL ;
F_419 ( V_722 -> V_726 ) ;
F_26 ( V_722 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_420 ( V_5 -> V_7 -> V_53 ) )
return - V_35 ;
V_32 = F_421 ( V_5 -> V_7 , V_5 -> V_48 ,
& V_727 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_415 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_53 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_422 ( V_5 -> V_48 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_418 ( & V_5 -> V_39 ) ;
F_422 ( V_5 -> V_48 ) ;
}
static int T_10 F_423 ( struct V_108 * V_108 )
{
int V_32 = - V_30 ;
struct V_92 * V_728 , * V_729 ;
V_728 = F_416 ( & V_92 , sizeof( V_92 ) , V_25 ) ;
if ( ! V_728 )
goto V_730;
V_729 = F_416 ( & V_731 , sizeof( V_731 ) , V_25 ) ;
if ( ! V_729 )
goto V_732;
V_729 -> V_373 = V_733 . V_373 ;
V_729 -> V_178 = V_733 . V_178 ;
V_729 -> V_41 . V_42 = false ;
V_728 -> V_41 . V_42 = false ;
V_108 -> V_18 . V_122 = V_728 ;
V_108 -> V_18 . V_40 = V_729 ;
#ifdef F_424
V_32 = F_415 ( V_108 , L_32 , NULL , V_728 ) ;
if ( V_32 < 0 )
goto V_734;
V_32 = F_415 ( V_108 , L_33 , NULL , V_729 ) ;
if ( V_32 < 0 )
goto V_735;
#endif
return 0 ;
#ifdef F_424
V_735:
F_418 ( V_728 ) ;
V_734:
F_26 ( V_729 ) ;
#endif
V_732:
F_26 ( V_728 ) ;
V_730:
return V_32 ;
}
static void T_11 F_425 ( struct V_108 * V_108 )
{
#ifdef F_424
F_418 ( V_108 -> V_18 . V_40 ) ;
F_418 ( V_108 -> V_18 . V_122 ) ;
#endif
F_26 ( V_108 -> V_18 . V_40 ) ;
F_26 ( V_108 -> V_18 . V_122 ) ;
}
int T_12 F_426 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_427 () ;
if ( V_32 < 0 ) {
F_428 ( L_34 ,
V_52 , V_32 ) ;
goto V_182;
}
V_32 = F_334 ( & V_736 ) ;
if ( V_32 < 0 )
goto V_737;
V_15 = F_429 ( L_35 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_738;
}
F_255 () ;
V_5 = F_28 ( V_739 . V_740 ) ;
F_95 () ;
if ( F_53 ( V_5 ) ) {
V_32 = F_122 ( V_5 ) ;
goto V_741;
}
for ( V_16 = 0 ; V_16 < V_470 ; V_16 ++ )
F_430 ( & V_186 [ V_16 ] ) ;
F_431 ( & V_742 ) ;
F_252 () ;
F_432 ( & V_743 ) ;
V_32 = F_433 ( V_744 , V_745 , NULL , F_396 ,
NULL ) ;
if ( V_32 < 0 )
goto V_111;
F_433 ( V_744 , V_422 , F_346 , NULL , NULL ) ;
F_433 ( V_744 , V_205 , F_343 , NULL , NULL ) ;
F_433 ( V_744 , V_746 , F_362 ,
F_359 , NULL ) ;
F_433 ( V_744 , V_562 , NULL ,
F_360 , NULL ) ;
F_433 ( V_744 , V_566 , NULL ,
F_361 , NULL ) ;
F_433 ( V_744 , V_747 , F_71 ,
F_78 , NULL ) ;
F_434 () ;
return 0 ;
V_111:
F_435 ( & V_743 ) ;
F_436 ( & V_742 ) ;
V_741:
F_437 ( V_15 ) ;
V_738:
F_336 ( & V_736 ) ;
V_737:
F_438 () ;
V_182:
return V_32 ;
}
void F_439 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_436 ( & V_742 ) ;
F_336 ( & V_736 ) ;
F_438 () ;
F_255 () ;
F_440 ( & V_743 ) ;
F_91 (&init_net, dev) {
if ( F_52 ( V_7 ) == NULL )
continue;
F_292 ( V_7 , 1 ) ;
}
F_292 ( V_739 . V_740 , 2 ) ;
F_144 ( & V_180 ) ;
for ( V_16 = 0 ; V_16 < V_470 ; V_16 ++ )
F_67 ( ! F_441 ( & V_186 [ V_16 ] ) ) ;
F_145 ( & V_180 ) ;
F_10 ( & V_510 ) ;
F_95 () ;
F_437 ( V_15 ) ;
}
