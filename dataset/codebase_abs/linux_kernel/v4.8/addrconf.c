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
V_31 -> V_47 = F_35 ( V_7 , & V_48 ) ;
if ( ! V_31 -> V_47 ) {
F_26 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
if ( V_31 -> V_39 . V_49 )
F_36 ( V_7 ) ;
F_37 ( V_7 ) ;
if ( F_20 ( V_31 ) < 0 ) {
F_38 ( V_50
L_1 ,
V_51 , V_7 -> V_52 ) ;
F_39 ( & V_48 , V_31 -> V_47 ) ;
F_40 ( V_7 ) ;
F_26 ( V_31 ) ;
return F_30 ( V_32 ) ;
}
if ( F_41 ( V_31 ) < 0 ) {
F_38 ( V_50
L_2 ,
V_51 , V_7 -> V_52 ) ;
goto V_53;
}
F_14 ( V_31 ) ;
if ( V_7 -> V_54 & ( V_55 | V_56 ) )
V_31 -> V_39 . V_57 = - 1 ;
#if F_42 ( V_58 )
if ( V_7 -> type == V_59 && ( V_7 -> V_60 & V_61 ) ) {
F_43 ( L_3 , V_7 -> V_52 ) ;
V_31 -> V_39 . V_62 = 0 ;
}
#endif
F_32 ( & V_31 -> V_63 ) ;
F_33 ( & V_31 -> V_64 , V_65 , ( unsigned long ) V_31 ) ;
if ( ( V_7 -> V_54 & V_56 ) ||
V_7 -> type == V_66 ||
V_7 -> type == V_67 ||
V_7 -> type == V_59 ||
V_7 -> type == V_68 ) {
V_31 -> V_39 . V_69 = - 1 ;
} else {
F_14 ( V_31 ) ;
V_65 ( ( unsigned long ) V_31 ) ;
}
V_31 -> V_70 = V_71 ;
if ( F_44 ( V_7 ) && F_4 ( V_7 ) )
V_31 -> V_72 |= V_73 ;
F_45 ( V_31 ) ;
V_31 -> V_74 = V_13 ;
V_32 = F_2 ( V_31 ) ;
if ( V_32 ) {
F_46 ( V_31 ) ;
F_7 ( & V_31 -> V_64 ) ;
F_47 ( V_31 ) ;
goto V_53;
}
F_48 ( V_7 -> V_75 , V_31 ) ;
F_49 ( V_7 , & V_76 ) ;
F_49 ( V_7 , & V_77 ) ;
if ( V_31 -> V_39 . V_49 && ( V_7 -> V_54 & V_78 ) )
F_49 ( V_7 , & V_79 ) ;
return V_31 ;
V_53:
F_39 ( & V_48 , V_31 -> V_47 ) ;
V_31 -> V_80 = 1 ;
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
if ( V_7 -> V_54 & V_81 )
F_54 ( V_5 ) ;
return V_5 ;
}
static int F_55 ( int type )
{
int V_82 = F_56 ( sizeof( struct V_83 ) )
+ F_57 ( 4 ) ;
bool V_84 = false ;
if ( type == V_85 )
V_84 = true ;
if ( V_84 || type == V_86 )
V_82 += F_57 ( 4 ) ;
#ifdef F_58
if ( V_84 || type == V_87 )
V_82 += F_57 ( 4 ) ;
#endif
if ( V_84 || type == V_88 )
V_82 += F_57 ( 4 ) ;
if ( V_84 || type == V_89 )
V_82 += F_57 ( 4 ) ;
return V_82 ;
}
static int F_59 ( struct V_90 * V_91 , int V_92 ,
struct V_93 * V_94 , T_1 V_95 ,
T_1 V_96 , int V_97 , unsigned int V_54 ,
int type )
{
struct V_98 * V_99 ;
struct V_83 * V_100 ;
bool V_84 = false ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( struct V_83 ) ,
V_54 ) ;
if ( ! V_99 )
return - V_101 ;
if ( type == V_85 )
V_84 = true ;
V_100 = F_61 ( V_99 ) ;
V_100 -> V_102 = V_103 ;
if ( F_62 ( V_91 , V_104 , V_92 ) < 0 )
goto V_105;
if ( ( V_84 || type == V_86 ) &&
F_62 ( V_91 , V_86 , V_94 -> V_49 ) < 0 )
goto V_105;
#ifdef F_58
if ( ( V_84 || type == V_87 ) &&
F_62 ( V_91 , V_87 ,
V_94 -> V_106 ) < 0 )
goto V_105;
#endif
if ( ( V_84 || type == V_88 ) &&
F_62 ( V_91 , V_88 , V_94 -> V_107 ) < 0 )
goto V_105;
if ( ( V_84 || type == V_89 ) &&
F_62 ( V_91 , V_89 ,
V_94 -> V_108 ) < 0 )
goto V_105;
F_63 ( V_91 , V_99 ) ;
return 0 ;
V_105:
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
void F_65 ( struct V_109 * V_109 , int type , int V_92 ,
struct V_93 * V_94 )
{
struct V_90 * V_91 ;
int V_32 = - V_110 ;
V_91 = F_66 ( F_55 ( type ) , V_25 ) ;
if ( ! V_91 )
goto V_111;
V_32 = F_59 ( V_91 , V_92 , V_94 , 0 , 0 ,
V_112 , 0 , type ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_111;
}
F_69 ( V_91 , V_109 , 0 , V_113 , NULL , V_25 ) ;
return;
V_111:
F_70 ( V_109 , V_113 , V_32 ) ;
}
static int F_71 ( struct V_90 * V_114 ,
struct V_98 * V_99 )
{
struct V_109 * V_109 = F_72 ( V_114 -> V_115 ) ;
struct V_116 * V_117 [ V_118 + 1 ] ;
struct V_83 * V_100 ;
struct V_90 * V_91 ;
struct V_93 * V_94 ;
struct V_4 * V_119 ;
struct V_6 * V_7 ;
int V_92 ;
int V_32 ;
V_32 = F_73 ( V_99 , sizeof( * V_100 ) , V_117 , V_118 ,
V_120 ) ;
if ( V_32 < 0 )
goto V_111;
V_32 = - V_35 ;
if ( ! V_117 [ V_104 ] )
goto V_111;
V_92 = F_74 ( V_117 [ V_104 ] ) ;
switch ( V_92 ) {
case V_121 :
V_94 = V_109 -> V_18 . V_122 ;
break;
case V_123 :
V_94 = V_109 -> V_18 . V_40 ;
break;
default:
V_7 = F_75 ( V_109 , V_92 ) ;
if ( ! V_7 )
goto V_111;
V_119 = F_52 ( V_7 ) ;
if ( ! V_119 )
goto V_111;
V_94 = & V_119 -> V_39 ;
break;
}
V_32 = - V_110 ;
V_91 = F_66 ( F_55 ( V_85 ) , V_124 ) ;
if ( ! V_91 )
goto V_111;
V_32 = F_59 ( V_91 , V_92 , V_94 ,
F_76 ( V_114 ) . V_95 ,
V_99 -> V_125 , V_112 , 0 ,
V_85 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_111;
}
V_32 = F_77 ( V_91 , V_109 , F_76 ( V_114 ) . V_95 ) ;
V_111:
return V_32 ;
}
static int F_78 ( struct V_90 * V_91 ,
struct V_126 * V_127 )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_115 ) ;
int V_128 , V_129 ;
int V_130 , V_131 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_132 * V_133 ;
V_129 = V_127 -> args [ 0 ] ;
V_131 = V_130 = V_127 -> args [ 1 ] ;
for ( V_128 = V_129 ; V_128 < V_134 ; V_128 ++ , V_131 = 0 ) {
V_130 = 0 ;
V_133 = & V_109 -> V_135 [ V_128 ] ;
F_79 () ;
V_127 -> V_96 = F_80 ( & V_109 -> V_18 . V_136 ) ^
V_109 -> V_137 ;
F_81 (dev, head, index_hlist) {
if ( V_130 < V_131 )
goto V_138;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_138;
if ( F_59 ( V_91 , V_7 -> V_92 ,
& V_5 -> V_39 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_112 ,
V_139 ,
V_85 ) < 0 ) {
F_82 () ;
goto V_140;
}
F_83 ( V_127 , F_84 ( V_91 ) ) ;
V_138:
V_130 ++ ;
}
F_82 () ;
}
if ( V_128 == V_134 ) {
if ( F_59 ( V_91 , V_121 ,
V_109 -> V_18 . V_122 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_112 , V_139 ,
V_85 ) < 0 )
goto V_140;
else
V_128 ++ ;
}
if ( V_128 == V_134 + 1 ) {
if ( F_59 ( V_91 , V_123 ,
V_109 -> V_18 . V_40 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_112 , V_139 ,
V_85 ) < 0 )
goto V_140;
else
V_128 ++ ;
}
V_140:
V_127 -> args [ 0 ] = V_128 ;
V_127 -> args [ 1 ] = V_130 ;
return V_91 -> V_141 ;
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_142 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_39 . V_49 )
F_36 ( V_7 ) ;
if ( V_7 -> V_54 & V_78 ) {
if ( V_5 -> V_39 . V_49 ) {
F_49 ( V_7 , & V_79 ) ;
F_49 ( V_7 , & V_143 ) ;
F_49 ( V_7 , & V_144 ) ;
} else {
F_86 ( V_7 , & V_79 ) ;
F_86 ( V_7 , & V_143 ) ;
F_86 ( V_7 , & V_144 ) ;
}
}
F_87 (ifa, &idev->addr_list, if_list) {
if ( V_142 -> V_54 & V_145 )
continue;
if ( V_5 -> V_39 . V_49 )
F_88 ( V_142 ) ;
else
F_89 ( V_142 ) ;
}
F_65 ( F_34 ( V_7 ) , V_86 ,
V_7 -> V_92 , & V_5 -> V_39 ) ;
}
static void F_90 ( struct V_109 * V_109 , T_2 V_146 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_91 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_147 = ( ! V_5 -> V_39 . V_49 ) ^ ( ! V_146 ) ;
V_5 -> V_39 . V_49 = V_146 ;
if ( V_147 )
F_85 ( V_5 ) ;
}
}
}
static int F_92 ( struct V_148 * V_149 , int * V_150 , int V_146 )
{
struct V_109 * V_109 ;
int V_151 ;
if ( ! F_93 () )
return F_94 () ;
V_109 = (struct V_109 * ) V_149 -> V_152 ;
V_151 = * V_150 ;
* V_150 = V_146 ;
if ( V_150 == & V_109 -> V_18 . V_40 -> V_49 ) {
if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_65 ( V_109 , V_86 ,
V_123 ,
V_109 -> V_18 . V_40 ) ;
F_95 () ;
return 0 ;
}
if ( V_150 == & V_109 -> V_18 . V_122 -> V_49 ) {
int V_153 = V_109 -> V_18 . V_40 -> V_49 ;
V_109 -> V_18 . V_40 -> V_49 = V_146 ;
if ( ( ! V_146 ) ^ ( ! V_153 ) )
F_65 ( V_109 , V_86 ,
V_123 ,
V_109 -> V_18 . V_40 ) ;
F_90 ( V_109 , V_146 ) ;
if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_65 ( V_109 , V_86 ,
V_121 ,
V_109 -> V_18 . V_122 ) ;
} else if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_85 ( (struct V_4 * ) V_149 -> V_154 ) ;
F_95 () ;
if ( V_146 )
F_96 ( V_109 ) ;
return 1 ;
}
static void F_97 ( struct V_109 * V_109 , T_2 V_146 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_91 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_147 = ( ! V_5 -> V_39 . V_108 ) ^ ( ! V_146 ) ;
V_5 -> V_39 . V_108 = V_146 ;
if ( V_147 )
F_65 ( F_34 ( V_7 ) ,
V_89 ,
V_7 -> V_92 ,
& V_5 -> V_39 ) ;
}
}
}
static int F_98 ( struct V_148 * V_149 , int * V_150 , int V_146 )
{
struct V_109 * V_109 ;
int V_151 ;
if ( ! F_93 () )
return F_94 () ;
V_109 = (struct V_109 * ) V_149 -> V_152 ;
V_151 = * V_150 ;
* V_150 = V_146 ;
if ( V_150 == & V_109 -> V_18 . V_40 -> V_108 ) {
if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_65 ( V_109 ,
V_89 ,
V_123 ,
V_109 -> V_18 . V_40 ) ;
F_95 () ;
return 0 ;
}
if ( V_150 == & V_109 -> V_18 . V_122 -> V_108 ) {
V_109 -> V_18 . V_40 -> V_108 = V_146 ;
F_97 ( V_109 , V_146 ) ;
if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_65 ( V_109 ,
V_89 ,
V_121 ,
V_109 -> V_18 . V_122 ) ;
}
F_95 () ;
return 1 ;
}
void F_99 ( struct V_9 * V_10 )
{
F_67 ( ! F_100 ( & V_10 -> V_155 ) ) ;
#ifdef F_101
F_102 ( L_4 , V_51 ) ;
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
struct V_160 * V_150 ;
int V_161 = F_109 ( & V_10 -> V_162 ) ;
F_110 (p, &idev->addr_list) {
struct V_9 * V_142
= F_111 ( V_150 , struct V_9 , V_163 ) ;
if ( V_161 >= F_109 ( & V_142 -> V_162 ) )
break;
}
F_112 ( & V_10 -> V_163 , V_150 ) ;
}
static T_1 F_113 ( const struct V_164 * V_162 )
{
return F_114 ( F_115 ( V_162 ) , V_165 ) ;
}
static struct V_9 *
F_116 ( struct V_4 * V_5 , const struct V_164 * V_162 ,
const struct V_164 * V_166 , int V_167 ,
int V_168 , T_1 V_54 , T_1 V_169 , T_1 V_170 )
{
struct V_9 * V_142 = NULL ;
struct V_171 * V_158 ;
unsigned int V_172 ;
int V_32 = 0 ;
int V_173 = F_117 ( V_162 ) ;
if ( V_173 == V_174 ||
V_173 & V_175 ||
( ! ( V_5 -> V_7 -> V_54 & V_56 ) &&
V_173 & V_176 ) )
return F_30 ( - V_177 ) ;
F_118 () ;
if ( V_5 -> V_80 ) {
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
V_142 = F_25 ( sizeof( struct V_9 ) , V_124 ) ;
if ( ! V_142 ) {
F_38 ( L_8 ) ;
V_32 = - V_110 ;
goto V_184;
}
V_158 = F_121 ( V_5 , V_162 , false ) ;
if ( F_53 ( V_158 ) ) {
V_32 = F_122 ( V_158 ) ;
goto V_184;
}
F_123 ( V_5 -> V_47 ) ;
V_142 -> V_162 = * V_162 ;
if ( V_166 )
V_142 -> V_166 = * V_166 ;
F_124 ( & V_142 -> V_36 ) ;
F_125 ( & V_142 -> V_11 , V_185 ) ;
F_126 ( & V_142 -> V_155 ) ;
V_142 -> V_168 = V_168 ;
V_142 -> V_186 = V_167 ;
V_142 -> V_54 = V_54 | V_145 ;
V_142 -> V_169 = V_169 ;
V_142 -> V_170 = V_170 ;
V_142 -> V_1 = V_142 -> V_74 = V_13 ;
V_142 -> V_187 = false ;
V_142 -> V_158 = V_158 ;
V_142 -> V_5 = V_5 ;
F_14 ( V_5 ) ;
F_18 ( V_142 ) ;
V_172 = F_113 ( V_162 ) ;
F_127 ( & V_142 -> V_155 , & V_188 [ V_172 ] ) ;
F_128 ( & V_182 ) ;
F_129 ( & V_5 -> V_36 ) ;
F_108 ( V_5 , V_142 ) ;
if ( V_142 -> V_54 & V_189 ) {
F_130 ( & V_142 -> V_190 , & V_5 -> V_63 ) ;
F_18 ( V_142 ) ;
}
F_18 ( V_142 ) ;
F_131 ( & V_5 -> V_36 ) ;
V_179:
F_132 () ;
if ( F_133 ( V_32 == 0 ) )
F_134 ( V_191 , V_142 ) ;
else {
F_26 ( V_142 ) ;
V_142 = F_30 ( V_32 ) ;
}
return V_142 ;
V_184:
F_128 ( & V_182 ) ;
goto V_179;
}
static enum V_192
F_135 ( struct V_9 * V_10 , unsigned long * V_193 )
{
struct V_9 * V_142 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_194 ;
enum V_192 V_195 = V_196 ;
* V_193 = V_13 ;
F_87 (ifa, &idev->addr_list, if_list) {
if ( V_142 == V_10 )
continue;
if ( ! F_136 ( & V_142 -> V_162 , & V_10 -> V_162 ,
V_10 -> V_186 ) )
continue;
if ( V_142 -> V_54 & ( V_197 | V_198 ) )
return V_199 ;
V_195 = V_200 ;
F_119 ( & V_142 -> V_36 ) ;
V_194 = F_137 ( V_142 -> V_169 , V_3 ) ;
if ( F_138 ( * V_193 , V_142 -> V_74 + V_194 * V_3 ) )
* V_193 = V_142 -> V_74 + V_194 * V_3 ;
F_128 ( & V_142 -> V_36 ) ;
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
if ( V_10 -> V_54 & V_189 ) {
F_148 ( & V_10 -> V_190 ) ;
if ( V_10 -> V_206 ) {
F_149 ( V_10 -> V_206 ) ;
V_10 -> V_206 = NULL ;
}
F_11 ( V_10 ) ;
}
if ( V_10 -> V_54 & V_197 && ! ( V_10 -> V_54 & V_198 ) )
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
if ( V_5 -> V_39 . V_69 <= 0 ) {
F_151 ( & V_5 -> V_36 ) ;
F_43 ( L_9 , V_51 ) ;
F_103 ( V_5 ) ;
V_217 = - 1 ;
goto V_184;
}
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_222 ++ >= V_5 -> V_39 . V_223 ) {
V_5 -> V_39 . V_69 = - 1 ;
F_145 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_105 ( L_10 ,
V_51 ) ;
F_103 ( V_5 ) ;
V_217 = - 1 ;
goto V_184;
}
F_18 ( V_10 ) ;
memcpy ( V_162 . V_220 , V_10 -> V_162 . V_220 , 8 ) ;
F_155 ( V_5 , V_210 ) ;
memcpy ( & V_162 . V_220 [ 8 ] , V_5 -> V_224 , 8 ) ;
V_214 = ( V_219 - V_10 -> V_74 ) / V_3 ;
V_212 = F_156 ( V_225 ,
V_10 -> V_169 ,
V_5 -> V_39 . V_226 + V_214 ) ;
V_211 = F_156 ( V_225 ,
V_10 -> V_170 ,
V_5 -> V_39 . V_227 + V_214 -
V_5 -> V_39 . V_228 ) ;
V_216 = V_10 -> V_186 ;
V_213 = V_10 -> V_74 ;
F_145 ( & V_10 -> V_36 ) ;
V_215 = V_5 -> V_39 . V_223 *
V_5 -> V_39 . V_229 *
F_157 ( V_5 -> V_47 , V_230 ) / V_3 ;
F_151 ( & V_5 -> V_36 ) ;
V_214 = ( V_219 - V_213 + V_231 ) / V_3 ;
if ( V_211 <= V_215 + V_214 ) {
F_149 ( V_10 ) ;
F_103 ( V_5 ) ;
V_217 = - 1 ;
goto V_184;
}
V_218 = V_189 ;
if ( V_10 -> V_54 & V_232 )
V_218 |= V_232 ;
V_209 = F_116 ( V_5 , & V_162 , NULL , V_216 ,
F_158 ( & V_162 ) , V_218 ,
V_212 , V_211 ) ;
if ( F_53 ( V_209 ) ) {
F_149 ( V_10 ) ;
F_103 ( V_5 ) ;
F_43 ( L_11 , V_51 ) ;
V_210 = & V_162 ;
F_147 ( & V_5 -> V_36 ) ;
goto V_221;
}
F_144 ( & V_209 -> V_36 ) ;
V_209 -> V_206 = V_10 ;
V_209 -> V_1 = V_219 ;
V_209 -> V_74 = V_213 ;
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
static int F_163 ( struct V_109 * V_109 ,
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
V_217 = ! ! V_238 -> V_142 ;
break;
case V_248 :
V_217 = F_165 ( & V_238 -> V_142 -> V_162 , V_240 -> V_162 ) ;
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
if ( ! F_161 ( V_238 -> V_142 -> V_5 ) )
V_250 |= V_232 ;
V_217 = F_160 ( V_238 -> V_173 ) ||
! ( V_238 -> V_142 -> V_54 & V_250 ) ;
break;
}
#ifdef F_167
case V_252 :
{
int V_253 = ! ( V_240 -> V_254 & V_255 ) ;
V_217 = ! ( V_238 -> V_142 -> V_54 & V_256 ) ^ V_253 ;
break;
}
#endif
case V_257 :
V_217 = ( ! V_240 -> V_92 ||
V_240 -> V_92 == V_238 -> V_142 -> V_5 -> V_7 -> V_92 ) ;
break;
case V_258 :
V_217 = F_168 ( V_109 ,
& V_238 -> V_142 -> V_162 , V_238 -> V_173 ,
V_238 -> V_142 -> V_5 -> V_7 -> V_92 ) == V_240 -> V_259 ;
break;
case V_260 :
{
int V_261 = V_240 -> V_254 & ( V_262 | V_263 ) ?
! ! ( V_240 -> V_254 & V_263 ) :
V_238 -> V_142 -> V_5 -> V_39 . V_69 >= 2 ;
V_217 = ( ! ( V_238 -> V_142 -> V_54 & V_189 ) ) ^ V_261 ;
break;
}
case V_264 :
V_217 = ! ( F_169 ( & V_238 -> V_142 -> V_162 ) ^
F_169 ( V_240 -> V_162 ) ) ;
break;
case V_244 :
V_217 = F_170 ( & V_238 -> V_142 -> V_162 , V_240 -> V_162 ) ;
if ( V_217 > V_238 -> V_142 -> V_186 )
V_217 = V_238 -> V_142 -> V_186 ;
V_238 -> V_245 = V_217 ;
break;
#ifdef F_162
case V_265 :
V_217 = ! ( V_238 -> V_142 -> V_54 & V_232 ) ;
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
static int F_172 ( struct V_109 * V_109 ,
struct V_239 * V_240 ,
struct V_4 * V_5 ,
struct V_237 * V_266 ,
int V_267 )
{
struct V_237 * V_238 = & V_266 [ 1 - V_267 ] , * V_268 = & V_266 [ V_267 ] ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_238 -> V_142 -> V_54 & V_145 ) &&
( ! ( V_238 -> V_142 -> V_54 & V_232 ) ) )
continue;
V_238 -> V_173 = F_174 ( & V_238 -> V_142 -> V_162 ) ;
if ( F_175 ( V_238 -> V_173 == V_174 ||
V_238 -> V_173 & V_175 ) ) {
F_176 ( L_12 ,
V_5 -> V_7 -> V_52 ) ;
continue;
}
V_238 -> V_241 = - 1 ;
F_177 ( V_238 -> V_246 , V_269 ) ;
for ( V_16 = 0 ; V_16 < V_269 ; V_16 ++ ) {
int V_270 , V_271 ;
V_270 = F_163 ( V_109 , V_268 , V_240 , V_16 ) ;
V_271 = F_163 ( V_109 , V_238 , V_240 , V_16 ) ;
if ( V_270 > V_271 ) {
if ( V_16 == V_242 &&
V_238 -> V_243 > 0 ) {
goto V_184;
}
break;
} else if ( V_270 < V_271 ) {
if ( V_268 -> V_142 )
F_149 ( V_268 -> V_142 ) ;
F_18 ( V_238 -> V_142 ) ;
F_178 ( V_268 , V_238 ) ;
V_267 = 1 - V_267 ;
V_238 -> V_142 = V_268 -> V_142 ;
break;
}
}
}
V_184:
F_179 ( & V_5 -> V_36 ) ;
return V_267 ;
}
static int F_180 ( struct V_109 * V_109 ,
const struct V_6 * V_272 ,
const struct V_6 * V_273 ,
struct V_239 * V_240 ,
struct V_237 * V_266 ,
int V_267 )
{
struct V_4 * V_5 ;
V_5 = F_52 ( V_272 ) ;
if ( V_5 )
V_267 = F_172 ( V_109 , V_240 , V_5 ,
V_266 , V_267 ) ;
V_5 = F_52 ( V_273 ) ;
if ( V_5 )
V_267 = F_172 ( V_109 , V_240 , V_5 ,
V_266 , V_267 ) ;
return V_267 ;
}
int F_181 ( struct V_109 * V_109 , const struct V_6 * V_272 ,
const struct V_164 * V_274 , unsigned int V_254 ,
struct V_164 * V_275 )
{
struct V_237 V_266 [ 2 ] , * V_268 ;
struct V_239 V_240 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_276 ;
bool V_277 = false ;
int V_267 = 0 ;
V_276 = F_174 ( V_274 ) ;
V_240 . V_162 = V_274 ;
V_240 . V_92 = V_272 ? V_272 -> V_92 : 0 ;
V_240 . V_168 = F_166 ( V_276 ) ;
V_240 . V_259 = F_168 ( V_109 , V_274 , V_276 , V_240 . V_92 ) ;
V_240 . V_254 = V_254 ;
V_266 [ V_267 ] . V_241 = - 1 ;
V_266 [ V_267 ] . V_142 = NULL ;
F_79 () ;
if ( V_272 ) {
V_5 = F_52 ( V_272 ) ;
if ( ( V_276 & V_175 ) ||
V_240 . V_168 <= V_278 ||
( V_5 && V_5 -> V_39 . V_279 ) ) {
V_277 = true ;
}
}
if ( V_277 ) {
if ( V_5 )
V_267 = F_172 ( V_109 , & V_240 , V_5 , V_266 , V_267 ) ;
} else {
const struct V_6 * V_273 ;
int V_280 = 0 ;
V_273 = F_182 ( V_272 ) ;
if ( V_273 ) {
V_280 = V_273 -> V_92 ;
V_267 = F_180 ( V_109 , V_272 ,
V_273 , & V_240 ,
V_266 , V_267 ) ;
if ( V_266 [ V_267 ] . V_142 )
goto V_184;
}
F_183 (net, dev) {
if ( F_184 ( V_7 ) != V_280 )
continue;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
continue;
V_267 = F_172 ( V_109 , & V_240 , V_5 , V_266 , V_267 ) ;
}
}
V_184:
F_82 () ;
V_268 = & V_266 [ V_267 ] ;
if ( ! V_268 -> V_142 )
return - V_177 ;
* V_275 = V_268 -> V_142 -> V_162 ;
F_149 ( V_268 -> V_142 ) ;
return 0 ;
}
int F_185 ( struct V_4 * V_5 , struct V_164 * V_162 ,
T_1 V_281 )
{
struct V_9 * V_10 ;
int V_32 = - V_177 ;
F_186 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_168 > V_282 )
break;
if ( V_10 -> V_168 == V_282 &&
! ( V_10 -> V_54 & V_281 ) ) {
* V_162 = V_10 -> V_162 ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
int F_187 ( struct V_6 * V_7 , struct V_164 * V_162 ,
T_1 V_281 )
{
struct V_4 * V_5 ;
int V_32 = - V_177 ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
V_32 = F_185 ( V_5 , V_162 , V_281 ) ;
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_32 ;
}
static int F_188 ( struct V_4 * V_5 )
{
int V_283 = 0 ;
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list)
V_283 ++ ;
F_179 ( & V_5 -> V_36 ) ;
return V_283 ;
}
int F_189 ( struct V_109 * V_109 , const struct V_164 * V_162 ,
const struct V_6 * V_7 , int V_284 )
{
return F_190 ( V_109 , V_162 , V_7 , V_284 , V_145 ) ;
}
int F_190 ( struct V_109 * V_109 , const struct V_164 * V_162 ,
const struct V_6 * V_7 , int V_284 ,
T_1 V_281 )
{
struct V_9 * V_10 ;
unsigned int V_172 = F_113 ( V_162 ) ;
T_1 V_285 ;
F_118 () ;
F_81 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_191 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_109 ) )
continue;
V_285 = ( V_10 -> V_54 & V_232 )
? ( V_10 -> V_54 & ~ V_145 )
: V_10 -> V_54 ;
if ( F_165 ( & V_10 -> V_162 , V_162 ) &&
! ( V_285 & V_281 ) &&
( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_168 & ( V_282 | V_286 ) || V_284 ) ) ) {
F_132 () ;
return 1 ;
}
}
F_132 () ;
return 0 ;
}
static bool F_120 ( struct V_109 * V_109 , const struct V_164 * V_162 ,
struct V_6 * V_7 )
{
unsigned int V_172 = F_113 ( V_162 ) ;
struct V_9 * V_10 ;
F_192 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_191 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_109 ) )
continue;
if ( F_165 ( & V_10 -> V_162 , V_162 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_193 ( const struct V_164 * V_162 ,
const unsigned int V_186 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_142 ;
bool V_217 = false ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifa, &idev->addr_list, if_list) {
V_217 = F_136 ( V_162 , & V_142 -> V_162 , V_186 ) ;
if ( V_217 )
break;
}
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_217 ;
}
int F_194 ( const struct V_164 * V_162 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_142 ;
int V_287 ;
V_287 = 0 ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifa, &idev->addr_list, if_list) {
V_287 = F_136 ( V_162 , & V_142 -> V_162 ,
V_142 -> V_186 ) ;
if ( V_287 )
break;
}
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_287 ;
}
struct V_9 * F_195 ( struct V_109 * V_109 , const struct V_164 * V_162 ,
struct V_6 * V_7 , int V_284 )
{
struct V_9 * V_10 , * V_288 = NULL ;
unsigned int V_172 = F_113 ( V_162 ) ;
F_118 () ;
F_196 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_191 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_109 ) )
continue;
if ( F_165 ( & V_10 -> V_162 , V_162 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_168 & ( V_282 | V_286 ) || V_284 ) ) {
V_288 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_132 () ;
return V_288 ;
}
static void F_197 ( struct V_9 * V_10 , int V_289 )
{
if ( V_289 )
V_10 -> V_54 |= V_290 ;
if ( V_10 -> V_54 & V_197 ) {
F_144 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_54 |= V_145 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_289 )
F_152 ( 0 , V_10 ) ;
F_149 ( V_10 ) ;
} else if ( V_10 -> V_54 & V_189 ) {
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
static int F_198 ( struct V_9 * V_10 )
{
int V_32 = - V_291 ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 == V_292 ) {
V_10 -> V_156 = V_293 ;
V_32 = 0 ;
}
F_145 ( & V_10 -> V_36 ) ;
return V_32 ;
}
void F_199 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_109 * V_109 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( F_198 ( V_10 ) ) {
F_149 ( V_10 ) ;
return;
}
F_200 ( L_13 ,
V_10 -> V_5 -> V_7 -> V_52 , & V_10 -> V_162 ) ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_54 & V_294 ) {
int V_168 = V_10 -> V_168 ;
T_1 V_54 = V_10 -> V_54 ;
struct V_164 V_295 ;
struct V_9 * V_296 ;
T_1 V_169 , V_297 ;
int V_167 = V_10 -> V_186 ;
int V_298 = V_10 -> V_299 + 1 ;
if ( V_298 > V_109 -> V_18 . V_300 . V_301 ) {
F_200 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_52 ) ;
goto V_302;
}
V_295 = V_10 -> V_162 ;
if ( F_201 ( & V_295 , V_298 ,
V_5 ) )
goto V_302;
V_169 = V_10 -> V_169 ;
V_297 = V_10 -> V_170 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_5 -> V_39 . V_303 &&
F_188 ( V_5 ) >=
V_5 -> V_39 . V_303 )
goto V_304;
F_200 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_52 ) ;
V_296 = F_116 ( V_5 , & V_295 , NULL , V_167 ,
V_168 , V_54 , V_169 ,
V_297 ) ;
if ( F_53 ( V_296 ) )
goto V_304;
F_144 ( & V_296 -> V_36 ) ;
V_296 -> V_299 = V_298 ;
V_296 -> V_156 = V_305 ;
F_145 ( & V_296 -> V_36 ) ;
F_16 ( V_296 , V_109 -> V_18 . V_300 . V_306 ) ;
F_149 ( V_296 ) ;
V_304:
F_144 ( & V_10 -> V_36 ) ;
}
V_302:
V_10 -> V_156 = V_307 ;
F_145 ( & V_10 -> V_36 ) ;
F_16 ( V_10 , 0 ) ;
F_149 ( V_10 ) ;
}
void F_202 ( struct V_6 * V_7 , const struct V_164 * V_162 )
{
struct V_164 V_308 ;
if ( V_7 -> V_54 & ( V_56 | V_55 ) )
return;
F_203 ( V_162 , & V_308 ) ;
F_49 ( V_7 , & V_308 ) ;
}
void F_204 ( struct V_4 * V_5 , const struct V_164 * V_162 )
{
struct V_164 V_308 ;
if ( V_5 -> V_7 -> V_54 & ( V_56 | V_55 ) )
return;
F_203 ( V_162 , & V_308 ) ;
F_205 ( V_5 , & V_308 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_164 V_162 ;
if ( V_10 -> V_186 >= 127 )
return;
F_206 ( & V_162 , & V_10 -> V_162 , V_10 -> V_186 ) ;
if ( F_207 ( & V_162 ) )
return;
F_208 ( V_10 -> V_5 , & V_162 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
struct V_164 V_162 ;
if ( V_10 -> V_186 >= 127 )
return;
F_206 ( & V_162 , & V_10 -> V_162 , V_10 -> V_186 ) ;
if ( F_207 ( & V_162 ) )
return;
F_209 ( V_10 -> V_5 , & V_162 ) ;
}
static int F_210 ( T_3 * V_309 , struct V_6 * V_7 )
{
if ( V_7 -> V_310 != V_311 )
return - 1 ;
memcpy ( V_309 , V_7 -> V_312 , V_311 ) ;
V_309 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_211 ( T_3 * V_309 , struct V_6 * V_7 )
{
union V_313 * V_314 ;
if ( V_7 -> V_310 != V_315 )
return - 1 ;
V_314 = (union V_313 * ) V_7 -> V_312 ;
memcpy ( V_309 , & V_314 -> V_316 . V_317 , sizeof( V_314 -> V_316 . V_317 ) ) ;
V_309 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_212 ( T_3 * V_309 , struct V_6 * V_7 )
{
if ( V_7 -> V_310 != V_318 )
return - 1 ;
memset ( V_309 , 0 , 7 ) ;
V_309 [ 7 ] = * ( T_3 * ) V_7 -> V_312 ;
return 0 ;
}
static int F_213 ( T_3 * V_309 , struct V_6 * V_7 )
{
if ( V_7 -> V_310 != V_319 )
return - 1 ;
memcpy ( V_309 , V_7 -> V_312 + 12 , 8 ) ;
V_309 [ 0 ] |= 2 ;
return 0 ;
}
static int F_214 ( T_3 * V_309 , T_4 V_162 )
{
if ( V_162 == 0 )
return - 1 ;
V_309 [ 0 ] = ( F_215 ( V_162 ) || F_216 ( V_162 ) ||
F_217 ( V_162 ) || F_218 ( V_162 ) ||
F_219 ( V_162 ) || F_220 ( V_162 ) ||
F_221 ( V_162 ) || F_222 ( V_162 ) ||
F_223 ( V_162 ) || F_224 ( V_162 ) ||
F_225 ( V_162 ) ) ? 0x00 : 0x02 ;
V_309 [ 1 ] = 0 ;
V_309 [ 2 ] = 0x5E ;
V_309 [ 3 ] = 0xFE ;
memcpy ( V_309 + 4 , & V_162 , 4 ) ;
return 0 ;
}
static int F_226 ( T_3 * V_309 , struct V_6 * V_7 )
{
if ( V_7 -> V_60 & V_61 )
return F_214 ( V_309 , * ( T_4 * ) V_7 -> V_312 ) ;
return - 1 ;
}
static int F_227 ( T_3 * V_309 , struct V_6 * V_7 )
{
return F_214 ( V_309 , * ( T_4 * ) V_7 -> V_312 ) ;
}
static int F_228 ( T_3 * V_309 , struct V_6 * V_7 )
{
memcpy ( V_309 , V_7 -> V_320 , 3 ) ;
memcpy ( V_309 + 5 , V_7 -> V_320 + 3 , 3 ) ;
V_309 [ 3 ] = 0xFF ;
V_309 [ 4 ] = 0xFE ;
V_309 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_229 ( T_3 * V_309 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_321 :
case V_322 :
return F_230 ( V_309 , V_7 ) ;
case V_323 :
return F_212 ( V_309 , V_7 ) ;
case V_324 :
return F_213 ( V_309 , V_7 ) ;
case V_59 :
return F_226 ( V_309 , V_7 ) ;
case V_325 :
return F_227 ( V_309 , V_7 ) ;
case V_326 :
return F_210 ( V_309 , V_7 ) ;
case V_327 :
return F_211 ( V_309 , V_7 ) ;
case V_67 :
return F_228 ( V_309 , V_7 ) ;
}
return - 1 ;
}
static int F_231 ( T_3 * V_309 , struct V_4 * V_5 )
{
int V_32 = - 1 ;
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_186 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_168 > V_282 )
break;
if ( V_10 -> V_168 == V_282 && ! ( V_10 -> V_54 & V_145 ) ) {
memcpy ( V_309 , V_10 -> V_162 . V_220 + 8 , 8 ) ;
V_32 = 0 ;
break;
}
}
F_179 ( & V_5 -> V_36 ) ;
return V_32 ;
}
static void F_232 ( struct V_4 * V_5 )
{
V_328:
F_233 ( V_5 -> V_224 , sizeof( V_5 -> V_224 ) ) ;
V_5 -> V_224 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_224 [ 0 ] == 0xfd &&
( V_5 -> V_224 [ 1 ] & V_5 -> V_224 [ 2 ] & V_5 -> V_224 [ 3 ] & V_5 -> V_224 [ 4 ] & V_5 -> V_224 [ 5 ] & V_5 -> V_224 [ 6 ] ) == 0xff &&
( V_5 -> V_224 [ 7 ] & 0x80 ) )
goto V_328;
if ( ( V_5 -> V_224 [ 0 ] | V_5 -> V_224 [ 1 ] ) == 0 ) {
if ( V_5 -> V_224 [ 2 ] == 0x5e && V_5 -> V_224 [ 3 ] == 0xfe )
goto V_328;
if ( ( V_5 -> V_224 [ 2 ] | V_5 -> V_224 [ 3 ] | V_5 -> V_224 [ 4 ] | V_5 -> V_224 [ 5 ] | V_5 -> V_224 [ 6 ] | V_5 -> V_224 [ 7 ] ) == 0x00 )
goto V_328;
}
}
static void V_65 ( unsigned long V_329 )
{
struct V_4 * V_5 = (struct V_4 * ) V_329 ;
unsigned long V_193 ;
F_118 () ;
F_147 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_80 )
goto V_184;
F_232 ( V_5 ) ;
V_193 = V_13 +
V_5 -> V_39 . V_227 * V_3 -
V_5 -> V_39 . V_223 * V_5 -> V_39 . V_229 *
F_157 ( V_5 -> V_47 , V_230 ) -
V_5 -> V_39 . V_228 * V_3 ;
if ( F_138 ( V_193 , V_13 ) ) {
F_105 ( L_16 ,
V_51 , V_5 -> V_7 -> V_52 ) ;
goto V_184;
}
if ( ! F_15 ( & V_5 -> V_64 , V_193 ) )
F_14 ( V_5 ) ;
V_184:
F_151 ( & V_5 -> V_36 ) ;
F_132 () ;
F_103 ( V_5 ) ;
}
static void F_155 ( struct V_4 * V_5 , struct V_164 * V_210 )
{
if ( V_210 && memcmp ( V_5 -> V_224 , & V_210 -> V_220 [ 8 ] , 8 ) == 0 )
F_232 ( V_5 ) ;
}
static void
F_234 ( struct V_164 * V_330 , int V_331 , struct V_6 * V_7 ,
unsigned long V_193 , T_1 V_54 )
{
struct V_332 V_333 = {
. V_334 = F_235 ( V_7 ) ? : V_335 ,
. V_336 = V_337 ,
. V_338 = V_7 -> V_92 ,
. V_339 = V_193 ,
. V_340 = V_331 ,
. V_341 = V_342 | V_54 ,
. V_343 . V_344 = F_34 ( V_7 ) ,
. V_345 = V_346 ,
} ;
V_333 . V_347 = * V_330 ;
#if F_42 ( V_58 )
if ( V_7 -> type == V_59 && ( V_7 -> V_54 & V_348 ) )
V_333 . V_341 |= V_349 ;
#endif
F_236 ( & V_333 ) ;
}
static struct V_171 * F_140 ( const struct V_164 * V_330 ,
int V_331 ,
const struct V_6 * V_7 ,
T_1 V_54 , T_1 V_350 )
{
struct V_351 * V_352 ;
struct V_171 * V_158 = NULL ;
struct V_353 * V_149 ;
T_1 V_354 = F_235 ( V_7 ) ? : V_335 ;
V_149 = F_237 ( F_34 ( V_7 ) , V_354 ) ;
if ( ! V_149 )
return NULL ;
F_173 ( & V_149 -> V_355 ) ;
V_352 = F_238 ( & V_149 -> V_356 , V_330 , V_331 , NULL , 0 ) ;
if ( ! V_352 )
goto V_184;
V_350 |= V_357 ;
for ( V_158 = V_352 -> V_358 ; V_158 ; V_158 = V_158 -> V_240 . V_359 ) {
if ( V_158 -> V_240 . V_7 -> V_92 != V_7 -> V_92 )
continue;
if ( ( V_158 -> V_204 & V_54 ) != V_54 )
continue;
if ( ( V_158 -> V_204 & V_350 ) != 0 )
continue;
F_239 ( & V_158 -> V_240 ) ;
break;
}
V_184:
F_179 ( & V_149 -> V_355 ) ;
return V_158 ;
}
static void F_240 ( struct V_6 * V_7 )
{
struct V_332 V_333 = {
. V_334 = F_235 ( V_7 ) ? : V_360 ,
. V_336 = V_337 ,
. V_338 = V_7 -> V_92 ,
. V_340 = 8 ,
. V_341 = V_342 ,
. V_343 . V_344 = F_34 ( V_7 ) ,
} ;
F_241 ( & V_333 . V_347 , F_242 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_236 ( & V_333 ) ;
}
static struct V_4 * F_243 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 )
return F_30 ( - V_110 ) ;
if ( V_5 -> V_39 . V_180 )
return F_30 ( - V_181 ) ;
if ( ! ( V_7 -> V_54 & V_56 ) && ! F_244 ( V_7 ) )
F_240 ( V_7 ) ;
return V_5 ;
}
static void F_245 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_225 V_169 , V_225 V_170 ,
bool V_361 , unsigned long V_219 )
{
T_1 V_54 ;
struct V_9 * V_209 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ift, &idev->tempaddr_list, tmp_list) {
int V_214 , V_362 , V_363 ;
if ( V_10 != V_209 -> V_206 )
continue;
V_214 = ( V_219 - V_209 -> V_1 ) / V_3 ;
V_362 = V_5 -> V_39 . V_226 - V_214 ;
if ( V_362 < 0 )
V_362 = 0 ;
V_363 = V_5 -> V_39 . V_227 -
V_5 -> V_39 . V_228 - V_214 ;
if ( V_363 < 0 )
V_363 = 0 ;
if ( V_169 > V_362 )
V_169 = V_362 ;
if ( V_170 > V_363 )
V_170 = V_363 ;
F_119 ( & V_209 -> V_36 ) ;
V_54 = V_209 -> V_54 ;
V_209 -> V_169 = V_169 ;
V_209 -> V_170 = V_170 ;
V_209 -> V_74 = V_219 ;
if ( V_170 > 0 )
V_209 -> V_54 &= ~ V_251 ;
F_128 ( & V_209 -> V_36 ) ;
if ( ! ( V_54 & V_145 ) )
F_152 ( 0 , V_209 ) ;
}
if ( ( V_361 || F_246 ( & V_5 -> V_63 ) ) &&
V_5 -> V_39 . V_69 > 0 ) {
F_179 ( & V_5 -> V_36 ) ;
F_154 ( V_10 , NULL ) ;
} else {
F_179 ( & V_5 -> V_36 ) ;
}
}
static bool F_247 ( struct V_4 * V_5 )
{
return V_5 -> V_43 == V_44 ||
V_5 -> V_43 == V_364 ;
}
int F_248 ( struct V_109 * V_109 , struct V_6 * V_7 ,
const struct V_365 * V_366 ,
struct V_4 * V_119 ,
const struct V_164 * V_162 , int V_173 ,
T_1 V_218 , bool V_367 , bool V_187 ,
V_225 V_169 , T_1 V_170 )
{
struct V_9 * V_10 = F_195 ( V_109 , V_162 , V_7 , 1 ) ;
int V_361 = 0 , V_368 = 0 ;
if ( ! V_10 && V_169 ) {
int V_303 = V_119 -> V_39 . V_303 ;
#ifdef F_162
if ( V_119 -> V_39 . V_235 &&
! V_109 -> V_18 . V_122 -> V_49 && V_367 )
V_218 |= V_232 ;
#endif
if ( ! V_303 ||
F_188 ( V_119 ) < V_303 )
V_10 = F_116 ( V_119 , V_162 , NULL ,
V_366 -> V_186 ,
V_173 & V_369 ,
V_218 , V_169 ,
V_170 ) ;
if ( F_249 ( V_10 ) )
return - 1 ;
V_368 = 0 ;
V_361 = 1 ;
F_144 ( & V_10 -> V_36 ) ;
V_10 -> V_54 |= V_370 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_187 = V_187 ;
F_145 ( & V_10 -> V_36 ) ;
F_159 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_54 ;
unsigned long V_219 ;
T_1 V_371 ;
F_144 ( & V_10 -> V_36 ) ;
V_219 = V_13 ;
if ( V_10 -> V_169 > ( V_219 - V_10 -> V_74 ) / V_3 )
V_371 = V_10 -> V_169 - ( V_219 - V_10 -> V_74 ) / V_3 ;
else
V_371 = 0 ;
if ( ! V_368 && ! V_361 && V_371 ) {
const T_1 V_372 = F_156 ( T_1 ,
V_371 , V_373 ) ;
V_169 = F_250 ( V_169 , V_372 ) ;
V_368 = 1 ;
}
if ( V_368 ) {
V_10 -> V_169 = V_169 ;
V_10 -> V_170 = V_170 ;
V_10 -> V_74 = V_219 ;
V_54 = V_10 -> V_54 ;
V_10 -> V_54 &= ~ V_251 ;
F_145 ( & V_10 -> V_36 ) ;
if ( ! ( V_54 & V_145 ) )
F_152 ( 0 , V_10 ) ;
} else
F_145 ( & V_10 -> V_36 ) ;
F_245 ( V_119 , V_10 , V_169 , V_170 ,
V_361 , V_219 ) ;
F_149 ( V_10 ) ;
F_251 () ;
}
return 0 ;
}
void F_252 ( struct V_6 * V_7 , T_3 * V_374 , int V_141 , bool V_367 )
{
struct V_365 * V_366 ;
V_225 V_169 ;
V_225 V_170 ;
int V_173 , V_32 ;
T_1 V_218 = 0 ;
struct V_4 * V_119 ;
struct V_109 * V_109 = F_34 ( V_7 ) ;
V_366 = (struct V_365 * ) V_374 ;
if ( V_141 < sizeof( struct V_365 ) ) {
F_38 ( L_17 ) ;
return;
}
V_173 = F_117 ( & V_366 -> V_375 ) ;
if ( V_173 & ( V_175 | V_376 ) )
return;
V_169 = F_253 ( V_366 -> V_377 ) ;
V_170 = F_253 ( V_366 -> V_378 ) ;
if ( V_170 > V_169 ) {
F_254 ( L_18 ) ;
return;
}
V_119 = F_255 ( V_7 ) ;
if ( ! V_119 ) {
F_176 ( L_19 ,
V_7 -> V_52 ) ;
return;
}
if ( V_366 -> V_287 ) {
struct V_171 * V_158 ;
unsigned long V_379 ;
if ( V_3 > V_380 )
V_379 = F_137 ( V_169 , V_3 ) ;
else
V_379 = F_137 ( V_169 , V_380 ) ;
if ( F_256 ( V_379 ) )
V_379 *= V_3 ;
V_158 = F_140 ( & V_366 -> V_375 ,
V_366 -> V_186 ,
V_7 ,
V_381 | V_382 ,
V_202 | V_203 ) ;
if ( V_158 ) {
if ( V_169 == 0 ) {
F_141 ( V_158 ) ;
V_158 = NULL ;
} else if ( F_256 ( V_379 ) ) {
F_142 ( V_158 , V_13 + V_379 ) ;
} else {
F_257 ( V_158 ) ;
}
} else if ( V_169 ) {
T_5 V_193 = 0 ;
int V_54 = V_381 | V_382 ;
if ( F_256 ( V_379 ) ) {
V_54 |= V_205 ;
V_193 = F_258 ( V_379 ) ;
}
F_234 ( & V_366 -> V_375 , V_366 -> V_186 ,
V_7 , V_193 , V_54 ) ;
}
F_106 ( V_158 ) ;
}
if ( V_366 -> V_383 && V_119 -> V_39 . V_383 ) {
struct V_164 V_162 ;
bool V_187 = false , V_384 = false ;
if ( V_366 -> V_186 == 64 ) {
memcpy ( & V_162 , & V_366 -> V_375 , 8 ) ;
if ( ! F_207 ( & V_119 -> V_70 ) ) {
F_173 ( & V_119 -> V_36 ) ;
memcpy ( V_162 . V_220 + 8 ,
V_119 -> V_70 . V_220 + 8 , 8 ) ;
F_179 ( & V_119 -> V_36 ) ;
V_187 = true ;
} else if ( F_247 ( V_119 ) &&
! F_201 ( & V_162 , 0 ,
V_119 ) ) {
V_218 |= V_294 ;
goto V_385;
} else if ( F_229 ( V_162 . V_220 + 8 , V_7 ) &&
F_231 ( V_162 . V_220 + 8 , V_119 ) ) {
goto V_386;
} else {
V_384 = true ;
}
goto V_385;
}
F_176 ( L_20 ,
V_366 -> V_186 ) ;
goto V_386;
V_385:
V_32 = F_248 ( V_109 , V_7 , V_366 , V_119 ,
& V_162 , V_173 ,
V_218 , V_367 ,
V_187 , V_169 ,
V_170 ) ;
if ( V_32 )
goto V_386;
F_259 ( V_109 , V_7 , V_366 , V_119 , & V_162 ,
V_173 , V_218 , V_367 ,
V_187 , V_169 ,
V_170 ,
V_384 ) ;
}
F_260 ( V_387 , V_119 , V_366 ) ;
V_386:
F_103 ( V_119 ) ;
}
int F_261 ( struct V_109 * V_109 , void T_6 * V_388 )
{
struct V_389 V_390 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_262 () ;
V_32 = - V_391 ;
if ( F_263 ( & V_390 , V_388 , sizeof( struct V_389 ) ) )
goto V_392;
V_7 = F_75 ( V_109 , V_390 . V_393 ) ;
V_32 = - V_178 ;
if ( ! V_7 )
goto V_392;
#if F_42 ( V_58 )
if ( V_7 -> type == V_59 ) {
const struct V_394 * V_395 = V_7 -> V_396 ;
struct V_397 V_398 ;
struct V_399 V_150 ;
V_32 = - V_177 ;
if ( ! ( F_117 ( & V_390 . V_400 ) & V_234 ) )
goto V_392;
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
V_150 . V_401 . V_274 = V_390 . V_400 . V_402 [ 3 ] ;
V_150 . V_401 . V_275 = 0 ;
V_150 . V_401 . V_403 = 4 ;
V_150 . V_401 . V_404 = 5 ;
V_150 . V_401 . V_405 = V_406 ;
V_150 . V_401 . V_407 = 64 ;
V_398 . V_408 . V_409 = ( V_410 void T_6 * ) & V_150 ;
if ( V_395 -> V_411 ) {
T_7 V_412 = F_264 () ;
F_265 ( V_413 ) ;
V_32 = V_395 -> V_411 ( V_7 , & V_398 , V_414 ) ;
F_265 ( V_412 ) ;
} else
V_32 = - V_415 ;
if ( V_32 == 0 ) {
V_32 = - V_110 ;
V_7 = F_266 ( V_109 , V_150 . V_52 ) ;
if ( ! V_7 )
goto V_392;
V_32 = F_267 ( V_7 ) ;
}
}
#endif
V_392:
F_95 () ;
return V_32 ;
}
static int F_268 ( struct V_416 * V_115 , bool V_417 ,
const struct V_164 * V_162 , int V_92 )
{
int V_217 ;
F_29 () ;
F_269 ( V_115 ) ;
if ( V_417 )
V_217 = F_270 ( V_115 , V_92 , V_162 ) ;
else
V_217 = F_271 ( V_115 , V_92 , V_162 ) ;
F_272 ( V_115 ) ;
return V_217 ;
}
static int F_273 ( struct V_109 * V_109 , int V_92 ,
const struct V_164 * V_330 ,
const struct V_164 * V_418 ,
unsigned int V_331 , V_225 V_419 ,
V_225 V_170 , V_225 V_169 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_420 ;
T_5 V_193 ;
int V_168 ;
T_1 V_54 ;
F_29 () ;
if ( V_331 > 128 )
return - V_35 ;
if ( ! V_169 || V_170 > V_169 )
return - V_35 ;
if ( V_419 & V_370 && V_331 != 64 )
return - V_35 ;
V_7 = F_75 ( V_109 , V_92 ) ;
if ( ! V_7 )
return - V_178 ;
V_5 = F_243 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return F_122 ( V_5 ) ;
if ( V_419 & V_421 ) {
int V_217 = F_268 ( V_109 -> V_18 . V_422 ,
true , V_330 , V_92 ) ;
if ( V_217 < 0 )
return V_217 ;
}
V_168 = F_158 ( V_330 ) ;
V_420 = F_137 ( V_169 , V_3 ) ;
if ( F_256 ( V_420 ) ) {
V_193 = F_258 ( V_420 * V_3 ) ;
V_169 = V_420 ;
V_54 = V_205 ;
} else {
V_193 = 0 ;
V_54 = 0 ;
V_419 |= V_197 ;
}
V_420 = F_137 ( V_170 , V_3 ) ;
if ( F_256 ( V_420 ) ) {
if ( V_420 == 0 )
V_419 |= V_251 ;
V_170 = V_420 ;
}
V_10 = F_116 ( V_5 , V_330 , V_418 , V_331 , V_168 , V_419 ,
V_169 , V_170 ) ;
if ( ! F_53 ( V_10 ) ) {
if ( ! ( V_419 & V_198 ) ) {
F_234 ( & V_10 -> V_162 , V_10 -> V_186 , V_7 ,
V_193 , V_54 ) ;
}
F_159 ( V_10 ) ;
if ( V_419 & V_370 )
F_245 ( V_5 , V_10 , V_169 , V_170 ,
true , V_13 ) ;
F_149 ( V_10 ) ;
F_274 () ;
return 0 ;
} else if ( V_419 & V_421 ) {
F_268 ( V_109 -> V_18 . V_422 ,
false , V_330 , V_92 ) ;
}
return F_122 ( V_10 ) ;
}
static int F_275 ( struct V_109 * V_109 , int V_92 , T_1 V_419 ,
const struct V_164 * V_330 , unsigned int V_331 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_331 > 128 )
return - V_35 ;
V_7 = F_75 ( V_109 , V_92 ) ;
if ( ! V_7 )
return - V_178 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_423 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_186 == V_331 &&
F_165 ( V_330 , & V_10 -> V_162 ) ) {
F_18 ( V_10 ) ;
F_179 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_54 & V_189 ) &&
( V_419 & V_370 ) )
F_245 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_143 ( V_10 ) ;
F_274 () ;
if ( F_276 ( V_330 ) ) {
F_268 ( V_109 -> V_18 . V_422 ,
false , V_330 , V_7 -> V_92 ) ;
}
return 0 ;
}
}
F_179 ( & V_5 -> V_36 ) ;
return - V_177 ;
}
int F_277 ( struct V_109 * V_109 , void T_6 * V_388 )
{
struct V_389 V_390 ;
int V_32 ;
if ( ! F_278 ( V_109 -> V_424 , V_425 ) )
return - V_426 ;
if ( F_263 ( & V_390 , V_388 , sizeof( struct V_389 ) ) )
return - V_391 ;
F_262 () ;
V_32 = F_273 ( V_109 , V_390 . V_393 , & V_390 . V_400 , NULL ,
V_390 . V_427 , V_197 ,
V_428 , V_428 ) ;
F_95 () ;
return V_32 ;
}
int F_279 ( struct V_109 * V_109 , void T_6 * V_388 )
{
struct V_389 V_390 ;
int V_32 ;
if ( ! F_278 ( V_109 -> V_424 , V_425 ) )
return - V_426 ;
if ( F_263 ( & V_390 , V_388 , sizeof( struct V_389 ) ) )
return - V_391 ;
F_262 () ;
V_32 = F_275 ( V_109 , V_390 . V_393 , 0 , & V_390 . V_400 ,
V_390 . V_427 ) ;
F_95 () ;
return V_32 ;
}
static void F_280 ( struct V_4 * V_5 , const struct V_164 * V_162 ,
int V_331 , int V_168 )
{
struct V_9 * V_10 ;
V_10 = F_116 ( V_5 , V_162 , NULL , V_331 ,
V_168 , V_197 ,
V_428 , V_428 ) ;
if ( ! F_53 ( V_10 ) ) {
F_144 ( & V_10 -> V_36 ) ;
V_10 -> V_54 &= ~ V_145 ;
F_145 ( & V_10 -> V_36 ) ;
F_152 ( V_429 , V_10 ) ;
F_149 ( V_10 ) ;
}
}
static void F_281 ( struct V_4 * V_5 )
{
struct V_164 V_162 ;
struct V_6 * V_7 ;
struct V_109 * V_109 = F_34 ( V_5 -> V_7 ) ;
int V_168 , V_331 ;
T_1 V_430 = 0 ;
F_29 () ;
memset ( & V_162 , 0 , sizeof( struct V_164 ) ) ;
memcpy ( & V_162 . V_402 [ 3 ] , V_5 -> V_7 -> V_312 , 4 ) ;
if ( V_5 -> V_7 -> V_54 & V_348 ) {
V_162 . V_402 [ 0 ] = F_242 ( 0xfe800000 ) ;
V_168 = V_282 ;
V_331 = 64 ;
} else {
V_168 = V_234 ;
V_331 = 96 ;
V_430 |= V_349 ;
}
if ( V_162 . V_402 [ 3 ] ) {
F_280 ( V_5 , & V_162 , V_331 , V_168 ) ;
F_234 ( & V_162 , V_331 , V_5 -> V_7 , 0 , V_430 ) ;
return;
}
F_91 (net, dev) {
struct V_431 * V_432 = F_282 ( V_7 ) ;
if ( V_432 && ( V_7 -> V_54 & V_81 ) ) {
struct V_433 * V_142 ;
int V_434 = V_168 ;
for ( V_142 = V_432 -> V_435 ; V_142 ; V_142 = V_142 -> V_436 ) {
V_162 . V_402 [ 3 ] = V_142 -> V_437 ;
if ( V_142 -> V_438 == V_439 )
continue;
if ( V_142 -> V_438 >= V_440 ) {
if ( V_5 -> V_7 -> V_54 & V_348 )
continue;
V_434 |= V_286 ;
}
F_280 ( V_5 , & V_162 , V_331 , V_434 ) ;
F_234 ( & V_162 , V_331 , V_5 -> V_7 , 0 ,
V_430 ) ;
}
}
}
}
static void F_283 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_441 ;
struct V_9 * V_442 ;
struct V_171 * V_443 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_21 , V_51 ) ;
return;
}
F_280 ( V_5 , & V_444 , 128 , V_286 ) ;
F_91 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_441 -> V_52 , V_7 -> V_52 ) )
continue;
V_5 = F_52 ( V_441 ) ;
if ( ! V_5 )
continue;
F_173 ( & V_5 -> V_36 ) ;
F_87 (sp_ifa, &idev->addr_list, if_list) {
if ( V_442 -> V_54 & ( V_290 | V_145 ) )
continue;
if ( V_442 -> V_158 ) {
if ( V_442 -> V_158 -> V_240 . V_445 > 0 ) {
F_106 ( V_442 -> V_158 ) ;
V_442 -> V_158 = NULL ;
} else {
continue;
}
}
V_443 = F_121 ( V_5 , & V_442 -> V_162 , false ) ;
if ( ! F_53 ( V_443 ) ) {
V_442 -> V_158 = V_443 ;
F_284 ( V_443 ) ;
}
}
F_179 ( & V_5 -> V_36 ) ;
}
}
void F_285 ( struct V_4 * V_5 ,
const struct V_164 * V_162 , T_1 V_54 )
{
struct V_9 * V_10 ;
T_1 V_218 = V_54 | V_197 ;
#ifdef F_162
if ( V_5 -> V_39 . V_235 &&
! F_34 ( V_5 -> V_7 ) -> V_18 . V_122 -> V_49 )
V_218 |= V_232 ;
#endif
V_10 = F_116 ( V_5 , V_162 , NULL , 64 , V_282 , V_218 ,
V_428 , V_428 ) ;
if ( ! F_53 ( V_10 ) ) {
F_234 ( & V_10 -> V_162 , V_10 -> V_186 , V_5 -> V_7 , 0 , 0 ) ;
F_159 ( V_10 ) ;
F_149 ( V_10 ) ;
}
}
static bool F_286 ( struct V_164 V_446 )
{
if ( ( V_446 . V_402 [ 2 ] | V_446 . V_402 [ 3 ] ) == 0 )
return true ;
if ( V_446 . V_402 [ 2 ] == F_242 ( 0x02005eff ) &&
( ( V_446 . V_402 [ 3 ] & F_242 ( 0xfe000000 ) ) == F_242 ( 0xfe000000 ) ) )
return true ;
if ( V_446 . V_402 [ 2 ] == F_242 ( 0xfdffffff ) &&
( ( V_446 . V_402 [ 3 ] & F_242 ( 0xffffff80 ) ) == F_242 ( 0xffffff80 ) ) )
return true ;
return false ;
}
static int F_201 ( struct V_164 * V_446 ,
T_3 V_447 ,
const struct V_4 * V_5 )
{
static F_287 ( V_36 ) ;
static V_225 V_448 [ V_449 ] ;
static V_225 V_450 [ V_451 ] ;
static union {
char V_452 [ V_453 ] ;
struct {
struct V_164 V_454 ;
T_4 V_375 [ 2 ] ;
unsigned char V_455 [ V_456 ] ;
T_3 V_447 ;
} V_457 ;
} V_329 ;
struct V_164 V_454 ;
struct V_164 V_458 ;
struct V_109 * V_109 = F_34 ( V_5 -> V_7 ) ;
F_288 ( sizeof( V_329 . V_452 ) != sizeof( V_329 ) ) ;
if ( V_5 -> V_39 . V_41 . V_42 )
V_454 = V_5 -> V_39 . V_41 . V_454 ;
else if ( V_109 -> V_18 . V_40 -> V_41 . V_42 )
V_454 = V_109 -> V_18 . V_40 -> V_41 . V_454 ;
else
return - 1 ;
V_221:
F_144 ( & V_36 ) ;
F_289 ( V_448 ) ;
memset ( & V_329 , 0 , sizeof( V_329 ) ) ;
memset ( V_450 , 0 , sizeof( V_450 ) ) ;
memcpy ( V_329 . V_455 , V_5 -> V_7 -> V_320 , V_5 -> V_7 -> V_310 ) ;
V_329 . V_375 [ 0 ] = V_446 -> V_402 [ 0 ] ;
V_329 . V_375 [ 1 ] = V_446 -> V_402 [ 1 ] ;
V_329 . V_454 = V_454 ;
V_329 . V_447 = V_447 ;
F_290 ( V_448 , V_329 . V_452 , V_450 ) ;
V_458 = * V_446 ;
V_458 . V_402 [ 2 ] = ( V_410 T_4 ) V_448 [ 0 ] ;
V_458 . V_402 [ 3 ] = ( V_410 T_4 ) V_448 [ 1 ] ;
F_145 ( & V_36 ) ;
if ( F_286 ( V_458 ) ) {
V_447 ++ ;
if ( V_447 > F_34 ( V_5 -> V_7 ) -> V_18 . V_300 . V_301 )
return - 1 ;
goto V_221;
}
* V_446 = V_458 ;
return 0 ;
}
static void F_291 ( struct V_4 * V_5 )
{
struct V_459 * V_460 = & V_5 -> V_39 . V_41 ;
if ( V_460 -> V_42 )
return;
V_460 = & V_5 -> V_39 . V_41 ;
F_233 ( & V_460 -> V_454 , sizeof( V_460 -> V_454 ) ) ;
V_460 -> V_42 = true ;
}
static void F_292 ( struct V_4 * V_5 , bool V_461 )
{
struct V_164 V_162 ;
if ( F_244 ( V_5 -> V_7 ) )
return;
F_241 ( & V_162 , F_242 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
switch ( V_5 -> V_43 ) {
case V_364 :
F_291 ( V_5 ) ;
case V_44 :
if ( ! F_201 ( & V_162 , 0 , V_5 ) )
F_285 ( V_5 , & V_162 ,
V_294 ) ;
else if ( V_461 )
F_234 ( & V_162 , 64 , V_5 -> V_7 , 0 , 0 ) ;
break;
case V_45 :
if ( F_229 ( V_162 . V_220 + 8 , V_5 -> V_7 ) == 0 )
F_285 ( V_5 , & V_162 , 0 ) ;
else if ( V_461 )
F_234 ( & V_162 , 64 , V_5 -> V_7 , 0 , 0 ) ;
break;
case V_462 :
default:
break;
}
}
static void F_293 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_321 ) &&
( V_7 -> type != V_322 ) &&
( V_7 -> type != V_323 ) &&
( V_7 -> type != V_324 ) &&
( V_7 -> type != V_327 ) &&
( V_7 -> type != V_67 ) &&
( V_7 -> type != V_326 ) &&
( V_7 -> type != V_68 ) ) {
return;
}
V_5 = F_243 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return;
if ( V_7 -> type == V_68 &&
V_5 -> V_43 == V_45 )
V_5 -> V_43 = V_364 ;
F_292 ( V_5 , false ) ;
}
static void F_294 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_21 , V_51 ) ;
return;
}
if ( V_7 -> V_60 & V_61 ) {
F_292 ( V_5 , false ) ;
return;
}
F_281 ( V_5 ) ;
if ( V_7 -> V_54 & V_348 )
F_240 ( V_7 ) ;
}
static void F_295 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_21 , V_51 ) ;
return;
}
F_292 ( V_5 , true ) ;
if ( V_7 -> V_54 & V_348 )
F_240 ( V_7 ) ;
}
static int F_296 ( struct V_4 * V_5 ,
struct V_9 * V_10 )
{
if ( ! V_10 -> V_158 ) {
struct V_171 * V_158 ;
V_158 = F_121 ( V_5 , & V_10 -> V_162 , false ) ;
if ( F_175 ( F_53 ( V_158 ) ) )
return F_122 ( V_158 ) ;
V_10 -> V_158 = V_158 ;
}
if ( ! ( V_10 -> V_54 & V_198 ) ) {
F_234 ( & V_10 -> V_162 , V_10 -> V_186 ,
V_5 -> V_7 , 0 , 0 ) ;
}
F_159 ( V_10 ) ;
return 0 ;
}
static void F_297 ( struct V_6 * V_7 )
{
struct V_9 * V_10 , * V_463 ;
struct V_4 * V_5 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return;
F_147 ( & V_5 -> V_36 ) ;
F_298 (ifp, tmp, &idev->addr_list, if_list) {
if ( ( V_10 -> V_54 & V_197 ) &&
F_296 ( V_5 , V_10 ) < 0 ) {
F_151 ( & V_5 -> V_36 ) ;
F_143 ( V_10 ) ;
F_147 ( & V_5 -> V_36 ) ;
F_200 ( L_22 ,
V_5 -> V_7 -> V_52 , & V_10 -> V_162 ) ;
}
}
F_151 ( & V_5 -> V_36 ) ;
}
static int F_299 ( struct V_464 * V_465 , unsigned long V_97 ,
void * V_466 )
{
struct V_6 * V_7 = F_300 ( V_466 ) ;
struct V_467 * V_468 ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
int V_469 = 0 ;
int V_32 ;
switch ( V_97 ) {
case V_470 :
if ( ! V_5 && V_7 -> V_33 >= V_34 ) {
V_5 = F_28 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return F_301 ( F_122 ( V_5 ) ) ;
}
break;
case V_471 :
if ( V_7 -> V_33 < V_34 ) {
F_302 ( V_7 , 1 ) ;
break;
}
if ( V_5 ) {
F_303 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_46 = V_7 -> V_33 ;
break;
}
V_5 = F_28 ( V_7 ) ;
if ( F_53 ( V_5 ) )
break;
if ( ! ( V_5 -> V_72 & V_73 ) )
break;
V_469 = 1 ;
case V_191 :
case V_472 :
if ( V_7 -> V_54 & V_473 )
break;
if ( V_5 && V_5 -> V_39 . V_180 )
break;
if ( V_97 == V_191 ) {
F_297 ( V_7 ) ;
if ( ! F_4 ( V_7 ) ) {
F_43 ( L_23 ,
V_7 -> V_52 ) ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 )
V_5 = F_28 ( V_7 ) ;
if ( ! F_249 ( V_5 ) ) {
V_5 -> V_72 |= V_73 ;
V_469 = 1 ;
}
} else if ( V_97 == V_472 ) {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_72 & V_73 )
break;
V_5 -> V_72 |= V_73 ;
}
F_43 ( L_24 ,
V_7 -> V_52 ) ;
V_469 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_58 )
case V_59 :
F_294 ( V_7 ) ;
break;
#endif
#if F_42 ( V_474 )
case V_325 :
F_295 ( V_7 ) ;
break;
#endif
case V_475 :
F_283 ( V_7 ) ;
break;
default:
F_293 ( V_7 ) ;
break;
}
if ( ! F_249 ( V_5 ) ) {
if ( V_469 )
F_304 ( V_5 ) ;
if ( V_5 -> V_39 . V_46 != V_7 -> V_33 &&
V_7 -> V_33 >= V_34 ) {
F_303 ( V_7 , V_7 -> V_33 ) ;
V_5 -> V_39 . V_46 = V_7 -> V_33 ;
}
V_5 -> V_74 = V_13 ;
F_305 ( V_476 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_302 ( V_7 , 1 ) ;
}
break;
case V_208 :
case V_477 :
F_302 ( V_7 , V_97 != V_208 ) ;
break;
case V_478 :
if ( V_5 ) {
F_47 ( V_5 ) ;
F_3 ( V_5 ) ;
V_32 = F_2 ( V_5 ) ;
if ( V_32 )
return F_301 ( V_32 ) ;
V_32 = F_41 ( V_5 ) ;
if ( V_32 ) {
F_3 ( V_5 ) ;
return F_301 ( V_32 ) ;
}
}
break;
case V_479 :
case V_480 :
if ( V_5 )
F_306 ( V_7 , V_97 ) ;
break;
case V_481 :
V_468 = V_466 ;
if ( V_468 -> V_482 && F_244 ( V_468 -> V_482 ) )
F_302 ( V_7 , 0 ) ;
}
return V_483 ;
}
static void F_306 ( struct V_6 * V_7 , unsigned long V_97 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_97 == V_480 )
F_307 ( V_5 ) ;
else if ( V_97 == V_479 )
F_308 ( V_5 ) ;
}
static bool F_309 ( const struct V_164 * V_162 )
{
return F_117 ( V_162 ) &
( V_376 | V_176 ) ;
}
static int F_302 ( struct V_6 * V_7 , int V_484 )
{
struct V_109 * V_109 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_142 , * V_463 ;
struct V_160 V_485 ;
int V_486 ;
bool V_487 ;
int V_156 , V_16 ;
F_29 () ;
F_310 ( V_109 , V_7 ) ;
F_311 ( & V_48 , V_7 ) ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_178 ;
if ( V_484 ) {
V_5 -> V_80 = 1 ;
F_312 ( V_7 -> V_75 , NULL ) ;
F_47 ( V_5 ) ;
}
V_486 = V_109 -> V_18 . V_122 -> V_488 ;
if ( ! V_486 )
V_486 = V_5 -> V_39 . V_488 ;
V_487 = ! ( V_484 || V_486 <= 0 || V_5 -> V_39 . V_180 ) ;
for ( V_16 = 0 ; V_16 < V_489 ; V_16 ++ ) {
struct V_132 * V_128 = & V_188 [ V_16 ] ;
F_144 ( & V_182 ) ;
V_490:
F_81 (ifa, h, addr_lst) {
if ( V_142 -> V_5 == V_5 ) {
F_9 ( V_142 ) ;
if ( ! V_487 ||
! ( V_142 -> V_54 & V_197 ) ||
F_309 ( & V_142 -> V_162 ) ) {
F_146 ( & V_142 -> V_155 ) ;
goto V_490;
}
}
}
F_145 ( & V_182 ) ;
}
F_147 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_484 )
V_5 -> V_72 &= ~ ( V_491 | V_492 | V_73 ) ;
if ( V_484 && F_7 ( & V_5 -> V_64 ) )
F_103 ( V_5 ) ;
while ( ! F_246 ( & V_5 -> V_63 ) ) {
V_142 = F_313 ( & V_5 -> V_63 ,
struct V_9 , V_190 ) ;
F_148 ( & V_142 -> V_190 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_144 ( & V_142 -> V_36 ) ;
if ( V_142 -> V_206 ) {
F_149 ( V_142 -> V_206 ) ;
V_142 -> V_206 = NULL ;
}
F_145 ( & V_142 -> V_36 ) ;
F_149 ( V_142 ) ;
F_147 ( & V_5 -> V_36 ) ;
}
V_487 = ( ! V_484 && V_486 > 0 && ! V_5 -> V_39 . V_180 ) ;
F_32 ( & V_485 ) ;
F_298 (ifa, tmp, &idev->addr_list, if_list) {
struct V_171 * V_158 = NULL ;
F_9 ( V_142 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_144 ( & V_142 -> V_36 ) ;
if ( V_487 && ( V_142 -> V_54 & V_197 ) &&
! F_309 ( & V_142 -> V_162 ) ) {
V_156 = V_157 ;
V_142 -> V_156 = 0 ;
if ( ! ( V_142 -> V_54 & V_493 ) )
V_142 -> V_54 |= V_145 ;
V_158 = V_142 -> V_158 ;
V_142 -> V_158 = NULL ;
} else {
V_156 = V_142 -> V_156 ;
V_142 -> V_156 = V_157 ;
F_314 ( & V_142 -> V_163 , & V_485 ) ;
}
F_145 ( & V_142 -> V_36 ) ;
if ( V_158 )
F_141 ( V_158 ) ;
if ( V_156 != V_157 ) {
F_315 ( V_207 , V_142 ) ;
F_134 ( V_208 , V_142 ) ;
} else {
if ( V_5 -> V_39 . V_49 )
F_89 ( V_142 ) ;
F_204 ( V_142 -> V_5 , & V_142 -> V_162 ) ;
}
F_147 ( & V_5 -> V_36 ) ;
}
F_151 ( & V_5 -> V_36 ) ;
while ( ! F_246 ( & V_485 ) ) {
V_142 = F_313 ( & V_485 ,
struct V_9 , V_163 ) ;
F_148 ( & V_142 -> V_163 ) ;
F_149 ( V_142 ) ;
}
if ( V_484 ) {
F_316 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_317 ( V_5 ) ;
}
V_5 -> V_74 = V_13 ;
if ( V_484 ) {
F_3 ( V_5 ) ;
F_39 ( & V_48 , V_5 -> V_47 ) ;
F_311 ( & V_48 , V_7 ) ;
F_103 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_329 )
{
struct V_4 * V_5 = (struct V_4 * ) V_329 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_164 V_494 ;
F_129 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_80 || ! ( V_5 -> V_72 & V_73 ) )
goto V_184;
if ( ! F_318 ( V_5 ) )
goto V_184;
if ( V_5 -> V_72 & V_492 )
goto V_184;
if ( V_5 -> V_495 ++ < V_5 -> V_39 . V_62 ) {
F_131 ( & V_5 -> V_36 ) ;
if ( ! F_187 ( V_7 , & V_494 , V_145 ) )
F_319 ( V_7 , & V_494 ,
& V_79 ) ;
else
goto V_386;
F_129 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_495 ==
V_5 -> V_39 . V_62 ) ?
V_5 -> V_39 . V_496 :
V_5 -> V_39 . V_497 ) ;
} else {
F_102 ( L_25 , V_5 -> V_7 -> V_52 ) ;
}
V_184:
F_131 ( & V_5 -> V_36 ) ;
V_386:
F_103 ( V_5 ) ;
}
static void F_320 ( struct V_9 * V_10 )
{
unsigned long V_498 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_54 & V_232 )
V_498 = 0 ;
else
V_498 = F_321 () % ( V_5 -> V_39 . V_496 ? : 1 ) ;
V_10 -> V_499 = V_5 -> V_39 . V_229 ;
F_16 ( V_10 , V_498 ) ;
}
static void F_322 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_500 = false ;
F_202 ( V_7 , & V_10 -> V_162 ) ;
F_323 ( ( V_410 T_1 ) V_10 -> V_162 . V_402 [ 3 ] ) ;
F_173 ( & V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 == V_157 )
goto V_184;
if ( V_7 -> V_54 & ( V_55 | V_56 ) ||
V_5 -> V_39 . V_57 < 1 ||
! ( V_10 -> V_54 & V_145 ) ||
V_10 -> V_54 & V_493 ) {
V_10 -> V_54 &= ~ ( V_145 | V_232 | V_290 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
F_324 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_72 & V_73 ) ) {
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
F_18 ( V_10 ) ;
F_197 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_54 & V_232 ) {
F_284 ( V_10 -> V_158 ) ;
if ( F_161 ( V_5 ) ) {
V_500 = true ;
}
}
F_320 ( V_10 ) ;
V_184:
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
if ( V_500 )
F_152 ( V_429 , V_10 ) ;
}
static void F_159 ( struct V_9 * V_10 )
{
bool V_501 = false ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 != V_157 ) {
V_10 -> V_156 = V_305 ;
V_501 = true ;
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_501 )
F_16 ( V_10 , 0 ) ;
}
static void V_185 ( struct V_502 * V_503 )
{
struct V_9 * V_10 = F_325 ( F_326 ( V_503 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_164 V_504 ;
bool V_180 = false ;
enum {
V_505 ,
V_506 ,
V_507 ,
} V_195 = V_505 ;
F_262 () ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 == V_305 ) {
V_195 = V_506 ;
V_10 -> V_156 = V_292 ;
} else if ( V_10 -> V_156 == V_307 ) {
V_195 = V_507 ;
V_10 -> V_156 = V_293 ;
if ( V_5 -> V_39 . V_57 > 1 && ! V_5 -> V_39 . V_180 &&
! ( V_10 -> V_54 & V_294 ) ) {
struct V_164 V_162 ;
V_162 . V_402 [ 0 ] = F_242 ( 0xfe800000 ) ;
V_162 . V_402 [ 1 ] = 0 ;
if ( ! F_229 ( V_162 . V_220 + 8 , V_5 -> V_7 ) &&
F_165 ( & V_10 -> V_162 , & V_162 ) ) {
V_5 -> V_39 . V_180 = 1 ;
F_43 ( L_26 ,
V_10 -> V_5 -> V_7 -> V_52 ) ;
V_180 = true ;
}
}
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_195 == V_506 ) {
F_322 ( V_10 ) ;
goto V_184;
} else if ( V_195 == V_507 ) {
F_18 ( V_10 ) ;
F_197 ( V_10 , 1 ) ;
if ( V_180 )
F_302 ( V_5 -> V_7 , 0 ) ;
goto V_184;
}
if ( ! V_10 -> V_499 && F_198 ( V_10 ) )
goto V_184;
F_147 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_80 || ! ( V_5 -> V_72 & V_73 ) ) {
F_151 ( & V_5 -> V_36 ) ;
goto V_184;
}
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_156 == V_157 ) {
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
goto V_184;
}
if ( V_10 -> V_499 == 0 ) {
V_10 -> V_54 &= ~ ( V_145 | V_232 | V_290 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_324 ( V_10 ) ;
goto V_184;
}
V_10 -> V_499 -- ;
F_16 ( V_10 ,
F_157 ( V_10 -> V_5 -> V_47 , V_230 ) ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_203 ( & V_10 -> V_162 , & V_504 ) ;
F_327 ( V_10 -> V_5 -> V_7 , & V_10 -> V_162 , & V_504 , & V_71 ) ;
V_184:
F_149 ( V_10 ) ;
F_95 () ;
}
static bool F_328 ( struct V_9 * V_10 )
{
struct V_9 * V_508 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_186 (ifpiter, &idev->addr_list, if_list) {
if ( V_508 -> V_168 > V_282 )
break;
if ( V_10 != V_508 && V_508 -> V_168 == V_282 &&
( V_508 -> V_54 & ( V_197 | V_145 |
V_232 | V_290 ) ) ==
V_197 )
return false ;
}
return true ;
}
static void F_324 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_164 V_494 ;
bool V_509 , V_510 ;
F_9 ( V_10 ) ;
F_152 ( V_429 , V_10 ) ;
F_173 ( & V_10 -> V_5 -> V_36 ) ;
V_510 = V_10 -> V_168 == V_282 && F_328 ( V_10 ) ;
V_509 = V_510 &&
F_318 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_62 > 0 &&
( V_7 -> V_54 & V_56 ) == 0 ;
F_179 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_510 )
F_329 ( V_10 -> V_5 ) ;
if ( V_509 ) {
if ( F_187 ( V_7 , & V_494 , V_145 ) )
return;
F_319 ( V_7 , & V_494 , & V_79 ) ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_495 = 1 ;
V_10 -> V_5 -> V_72 |= V_491 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_497 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_304 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list) {
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_54 & V_145 &&
V_10 -> V_156 == V_292 )
F_320 ( V_10 ) ;
F_128 ( & V_10 -> V_36 ) ;
}
F_179 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_330 ( struct V_511 * V_96 , T_8 V_512 )
{
struct V_9 * V_142 = NULL ;
struct V_513 * V_156 = V_96 -> V_514 ;
struct V_109 * V_109 = F_331 ( V_96 ) ;
int V_150 = 0 ;
if ( V_512 == 0 ) {
V_156 -> V_515 = 0 ;
V_156 -> V_516 = 0 ;
}
for (; V_156 -> V_515 < V_489 ; ++ V_156 -> V_515 ) {
F_196 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_191 ( F_34 ( V_142 -> V_5 -> V_7 ) , V_109 ) )
continue;
if ( V_150 < V_156 -> V_516 ) {
V_150 ++ ;
continue;
}
V_156 -> V_516 ++ ;
return V_142 ;
}
V_156 -> V_516 = 0 ;
V_150 = 0 ;
}
return NULL ;
}
static struct V_9 * F_332 ( struct V_511 * V_96 ,
struct V_9 * V_142 )
{
struct V_513 * V_156 = V_96 -> V_514 ;
struct V_109 * V_109 = F_331 ( V_96 ) ;
F_333 (ifa, addr_lst) {
if ( ! F_191 ( F_34 ( V_142 -> V_5 -> V_7 ) , V_109 ) )
continue;
V_156 -> V_516 ++ ;
return V_142 ;
}
while ( ++ V_156 -> V_515 < V_489 ) {
V_156 -> V_516 = 0 ;
F_196 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_191 ( F_34 ( V_142 -> V_5 -> V_7 ) , V_109 ) )
continue;
V_156 -> V_516 ++ ;
return V_142 ;
}
}
return NULL ;
}
static void * F_334 ( struct V_511 * V_96 , T_8 * V_512 )
__acquires( T_9 )
{
F_118 () ;
return F_330 ( V_96 , * V_512 ) ;
}
static void * F_335 ( struct V_511 * V_96 , void * V_517 , T_8 * V_512 )
{
struct V_9 * V_142 ;
V_142 = F_332 ( V_96 , V_517 ) ;
++ * V_512 ;
return V_142 ;
}
static void F_336 ( struct V_511 * V_96 , void * V_517 )
__releases( T_9 )
{
F_132 () ;
}
static int F_337 ( struct V_511 * V_96 , void * V_517 )
{
struct V_9 * V_10 = (struct V_9 * ) V_517 ;
F_338 ( V_96 , L_27 ,
& V_10 -> V_162 ,
V_10 -> V_5 -> V_7 -> V_92 ,
V_10 -> V_186 ,
V_10 -> V_168 ,
( T_3 ) V_10 -> V_54 ,
V_10 -> V_5 -> V_7 -> V_52 ) ;
return 0 ;
}
static int F_339 ( struct V_518 * V_518 , struct V_519 * V_519 )
{
return F_340 ( V_518 , V_519 , & V_520 ,
sizeof( struct V_513 ) ) ;
}
static int T_10 F_341 ( struct V_109 * V_109 )
{
if ( ! F_342 ( L_28 , V_521 , V_109 -> V_522 , & V_523 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_343 ( struct V_109 * V_109 )
{
F_344 ( L_28 , V_109 -> V_522 ) ;
}
int T_12 F_345 ( void )
{
return F_346 ( & V_524 ) ;
}
void F_347 ( void )
{
F_348 ( & V_524 ) ;
}
int F_349 ( struct V_109 * V_109 , const struct V_164 * V_162 )
{
int V_217 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_172 = F_113 ( V_162 ) ;
F_118 () ;
F_196 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_191 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_109 ) )
continue;
if ( F_165 ( & V_10 -> V_162 , V_162 ) &&
( V_10 -> V_54 & V_256 ) ) {
V_217 = 1 ;
break;
}
}
F_132 () ;
return V_217 ;
}
static void F_274 ( void )
{
unsigned long V_219 , V_525 , V_526 , V_527 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_118 () ;
V_219 = V_13 ;
V_525 = F_350 ( V_219 + V_528 ) ;
F_10 ( & V_529 ) ;
for ( V_16 = 0 ; V_16 < V_489 ; V_16 ++ ) {
V_490:
F_196 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_214 ;
if ( ( V_10 -> V_54 & V_197 ) &&
( V_10 -> V_170 == V_428 ) )
continue;
F_119 ( & V_10 -> V_36 ) ;
V_214 = ( V_219 - V_10 -> V_74 + V_231 ) / V_3 ;
if ( V_10 -> V_169 != V_428 &&
V_214 >= V_10 -> V_169 ) {
F_128 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_143 ( V_10 ) ;
goto V_490;
} else if ( V_10 -> V_170 == V_428 ) {
F_128 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_214 >= V_10 -> V_170 ) {
int V_530 = 0 ;
if ( ! ( V_10 -> V_54 & V_251 ) ) {
V_530 = 1 ;
V_10 -> V_54 |= V_251 ;
}
if ( ( V_10 -> V_169 != V_428 ) &&
( F_138 ( V_10 -> V_74 + V_10 -> V_169 * V_3 , V_525 ) ) )
V_525 = V_10 -> V_74 + V_10 -> V_169 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
if ( V_530 ) {
F_18 ( V_10 ) ;
F_152 ( 0 , V_10 ) ;
F_149 ( V_10 ) ;
goto V_490;
}
} else if ( ( V_10 -> V_54 & V_189 ) &&
! ( V_10 -> V_54 & V_145 ) ) {
unsigned long V_215 = V_10 -> V_5 -> V_39 . V_223 *
V_10 -> V_5 -> V_39 . V_229 *
F_157 ( V_10 -> V_5 -> V_47 , V_230 ) / V_3 ;
if ( V_214 >= V_10 -> V_170 - V_215 ) {
struct V_9 * V_206 = V_10 -> V_206 ;
if ( F_138 ( V_10 -> V_74 + V_10 -> V_170 * V_3 , V_525 ) )
V_525 = V_10 -> V_74 + V_10 -> V_170 * V_3 ;
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
goto V_490;
}
} else if ( F_138 ( V_10 -> V_74 + V_10 -> V_170 * V_3 - V_215 * V_3 , V_525 ) )
V_525 = V_10 -> V_74 + V_10 -> V_170 * V_3 - V_215 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
} else {
if ( F_138 ( V_10 -> V_74 + V_10 -> V_170 * V_3 , V_525 ) )
V_525 = V_10 -> V_74 + V_10 -> V_170 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
}
}
}
V_526 = F_350 ( V_525 ) ;
V_527 = V_525 ;
if ( F_138 ( V_526 , V_525 + V_531 ) )
V_527 = V_526 ;
if ( F_138 ( V_527 , V_13 + V_532 ) )
V_527 = V_13 + V_532 ;
F_38 ( V_533 L_29 ,
V_219 , V_525 , V_526 , V_527 ) ;
F_19 ( V_15 , & V_529 , V_527 - V_219 ) ;
F_132 () ;
}
static void F_351 ( struct V_502 * V_503 )
{
F_262 () ;
F_274 () ;
F_95 () ;
}
static void F_251 ( void )
{
F_19 ( V_15 , & V_529 , 0 ) ;
}
static struct V_164 * F_352 ( struct V_116 * V_162 , struct V_116 * V_534 ,
struct V_164 * * V_418 )
{
struct V_164 * V_330 = NULL ;
* V_418 = NULL ;
if ( V_162 )
V_330 = F_353 ( V_162 ) ;
if ( V_534 ) {
if ( V_330 && F_354 ( V_534 , V_330 , sizeof( * V_330 ) ) )
* V_418 = V_330 ;
V_330 = F_353 ( V_534 ) ;
}
return V_330 ;
}
static int
F_355 ( struct V_90 * V_91 , struct V_98 * V_99 )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_115 ) ;
struct V_535 * V_536 ;
struct V_116 * V_117 [ V_537 + 1 ] ;
struct V_164 * V_330 , * V_418 ;
T_1 V_419 ;
int V_32 ;
V_32 = F_73 ( V_99 , sizeof( * V_536 ) , V_117 , V_537 , V_538 ) ;
if ( V_32 < 0 )
return V_32 ;
V_536 = F_61 ( V_99 ) ;
V_330 = F_352 ( V_117 [ V_539 ] , V_117 [ V_540 ] , & V_418 ) ;
if ( ! V_330 )
return - V_35 ;
V_419 = V_117 [ V_541 ] ? F_356 ( V_117 [ V_541 ] ) : V_536 -> V_419 ;
V_419 &= V_370 ;
return F_275 ( V_109 , V_536 -> V_542 , V_419 , V_330 ,
V_536 -> V_543 ) ;
}
static int F_357 ( struct V_9 * V_10 , T_1 V_419 ,
T_1 V_170 , T_1 V_169 )
{
T_1 V_54 ;
T_5 V_193 ;
unsigned long V_420 ;
bool V_544 ;
bool V_545 ;
F_29 () ;
if ( ! V_169 || ( V_170 > V_169 ) )
return - V_35 ;
if ( V_419 & V_370 &&
( V_10 -> V_54 & V_189 || V_10 -> V_186 != 64 ) )
return - V_35 ;
V_420 = F_137 ( V_169 , V_3 ) ;
if ( F_256 ( V_420 ) ) {
V_193 = F_258 ( V_420 * V_3 ) ;
V_169 = V_420 ;
V_54 = V_205 ;
} else {
V_193 = 0 ;
V_54 = 0 ;
V_419 |= V_197 ;
}
V_420 = F_137 ( V_170 , V_3 ) ;
if ( F_256 ( V_420 ) ) {
if ( V_420 == 0 )
V_419 |= V_251 ;
V_170 = V_420 ;
}
F_144 ( & V_10 -> V_36 ) ;
V_544 = V_10 -> V_54 & V_370 ;
V_545 = V_10 -> V_54 & V_197 &&
! ( V_10 -> V_54 & V_198 ) ;
V_10 -> V_54 &= ~ ( V_251 | V_197 | V_493 |
V_256 | V_370 |
V_198 ) ;
V_10 -> V_54 |= V_419 ;
V_10 -> V_74 = V_13 ;
V_10 -> V_169 = V_169 ;
V_10 -> V_170 = V_170 ;
F_145 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_54 & V_145 ) )
F_152 ( 0 , V_10 ) ;
if ( ! ( V_419 & V_198 ) ) {
F_234 ( & V_10 -> V_162 , V_10 -> V_186 , V_10 -> V_5 -> V_7 ,
V_193 , V_54 ) ;
} else if ( V_545 ) {
enum V_192 V_195 ;
unsigned long V_379 ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
V_195 = F_135 ( V_10 , & V_379 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_195 != V_199 ) {
F_139 ( V_10 , V_379 ,
V_195 == V_196 ) ;
}
}
if ( V_544 || V_10 -> V_54 & V_370 ) {
if ( V_544 && ! ( V_10 -> V_54 & V_370 ) )
V_169 = V_170 = 0 ;
F_245 ( V_10 -> V_5 , V_10 , V_169 , V_170 ,
! V_544 , V_13 ) ;
}
F_274 () ;
return 0 ;
}
static int
F_358 ( struct V_90 * V_91 , struct V_98 * V_99 )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_115 ) ;
struct V_535 * V_536 ;
struct V_116 * V_117 [ V_537 + 1 ] ;
struct V_164 * V_330 , * V_418 ;
struct V_9 * V_142 ;
struct V_6 * V_7 ;
T_1 V_169 = V_428 , V_297 = V_428 ;
T_1 V_419 ;
int V_32 ;
V_32 = F_73 ( V_99 , sizeof( * V_536 ) , V_117 , V_537 , V_538 ) ;
if ( V_32 < 0 )
return V_32 ;
V_536 = F_61 ( V_99 ) ;
V_330 = F_352 ( V_117 [ V_539 ] , V_117 [ V_540 ] , & V_418 ) ;
if ( ! V_330 )
return - V_35 ;
if ( V_117 [ V_546 ] ) {
struct V_547 * V_548 ;
V_548 = F_353 ( V_117 [ V_546 ] ) ;
V_169 = V_548 -> V_549 ;
V_297 = V_548 -> V_550 ;
} else {
V_297 = V_428 ;
V_169 = V_428 ;
}
V_7 = F_75 ( V_109 , V_536 -> V_542 ) ;
if ( ! V_7 )
return - V_178 ;
V_419 = V_117 [ V_541 ] ? F_356 ( V_117 [ V_541 ] ) : V_536 -> V_419 ;
V_419 &= V_493 | V_256 | V_370 |
V_198 | V_421 ;
V_142 = F_195 ( V_109 , V_330 , V_7 , 1 ) ;
if ( ! V_142 ) {
return F_273 ( V_109 , V_536 -> V_542 , V_330 , V_418 ,
V_536 -> V_543 , V_419 ,
V_297 , V_169 ) ;
}
if ( V_99 -> V_551 & V_552 ||
! ( V_99 -> V_551 & V_553 ) )
V_32 = - V_183 ;
else
V_32 = F_357 ( V_142 , V_419 , V_297 , V_169 ) ;
F_149 ( V_142 ) ;
return V_32 ;
}
static void F_359 ( struct V_98 * V_99 , T_3 V_554 , T_1 V_54 ,
T_3 V_168 , int V_92 )
{
struct V_535 * V_536 ;
V_536 = F_61 ( V_99 ) ;
V_536 -> V_555 = V_103 ;
V_536 -> V_543 = V_554 ;
V_536 -> V_419 = V_54 ;
V_536 -> V_438 = V_168 ;
V_536 -> V_542 = V_92 ;
}
static int F_360 ( struct V_90 * V_91 , unsigned long V_1 ,
unsigned long V_74 , T_1 V_556 , T_1 V_377 )
{
struct V_547 V_548 ;
V_548 . V_1 = F_1 ( V_1 ) ;
V_548 . V_74 = F_1 ( V_74 ) ;
V_548 . V_550 = V_556 ;
V_548 . V_549 = V_377 ;
return F_361 ( V_91 , V_546 , sizeof( V_548 ) , & V_548 ) ;
}
static inline int F_362 ( int V_438 )
{
if ( V_438 & V_286 )
return V_440 ;
else if ( V_438 & V_282 )
return V_439 ;
else if ( V_438 & V_557 )
return V_558 ;
else
return V_559 ;
}
static inline int F_363 ( void )
{
return F_56 ( sizeof( struct V_535 ) )
+ F_57 ( 16 )
+ F_57 ( 16 )
+ F_57 ( sizeof( struct V_547 ) )
+ F_57 ( 4 ) ;
}
static int F_364 ( struct V_90 * V_91 , struct V_9 * V_142 ,
T_1 V_95 , T_1 V_96 , int V_97 , unsigned int V_54 )
{
struct V_98 * V_99 ;
T_1 V_556 , V_377 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( struct V_535 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
F_359 ( V_99 , V_142 -> V_186 , V_142 -> V_54 , F_362 ( V_142 -> V_168 ) ,
V_142 -> V_5 -> V_7 -> V_92 ) ;
if ( ! ( ( V_142 -> V_54 & V_197 ) &&
( V_142 -> V_170 == V_428 ) ) ) {
V_556 = V_142 -> V_170 ;
V_377 = V_142 -> V_169 ;
if ( V_556 != V_428 ) {
long V_560 = ( V_13 - V_142 -> V_74 ) / V_3 ;
if ( V_556 > V_560 )
V_556 -= V_560 ;
else
V_556 = 0 ;
if ( V_377 != V_428 ) {
if ( V_377 > V_560 )
V_377 -= V_560 ;
else
V_377 = 0 ;
}
}
} else {
V_556 = V_428 ;
V_377 = V_428 ;
}
if ( ! F_207 ( & V_142 -> V_166 ) ) {
if ( F_365 ( V_91 , V_540 , & V_142 -> V_162 ) < 0 ||
F_365 ( V_91 , V_539 , & V_142 -> V_166 ) < 0 )
goto error;
} else
if ( F_365 ( V_91 , V_539 , & V_142 -> V_162 ) < 0 )
goto error;
if ( F_360 ( V_91 , V_142 -> V_1 , V_142 -> V_74 , V_556 , V_377 ) < 0 )
goto error;
if ( F_366 ( V_91 , V_541 , V_142 -> V_54 ) < 0 )
goto error;
F_63 ( V_91 , V_99 ) ;
return 0 ;
error:
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
static int F_367 ( struct V_90 * V_91 , struct V_561 * V_562 ,
T_1 V_95 , T_1 V_96 , int V_97 , T_13 V_54 )
{
struct V_98 * V_99 ;
T_3 V_168 = V_559 ;
int V_92 = V_562 -> V_5 -> V_7 -> V_92 ;
if ( F_158 ( & V_562 -> V_563 ) & V_557 )
V_168 = V_558 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( struct V_535 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
F_359 ( V_99 , 128 , V_197 , V_168 , V_92 ) ;
if ( F_365 ( V_91 , V_564 , & V_562 -> V_563 ) < 0 ||
F_360 ( V_91 , V_562 -> V_565 , V_562 -> V_566 ,
V_428 , V_428 ) < 0 ) {
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
F_63 ( V_91 , V_99 ) ;
return 0 ;
}
static int F_368 ( struct V_90 * V_91 , struct V_567 * V_568 ,
T_1 V_95 , T_1 V_96 , int V_97 , unsigned int V_54 )
{
struct V_98 * V_99 ;
T_3 V_168 = V_559 ;
int V_92 = V_568 -> V_569 -> V_7 -> V_92 ;
if ( F_158 ( & V_568 -> V_570 ) & V_557 )
V_168 = V_558 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( struct V_535 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
F_359 ( V_99 , 128 , V_197 , V_168 , V_92 ) ;
if ( F_365 ( V_91 , V_571 , & V_568 -> V_570 ) < 0 ||
F_360 ( V_91 , V_568 -> V_572 , V_568 -> V_573 ,
V_428 , V_428 ) < 0 ) {
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
F_63 ( V_91 , V_99 ) ;
return 0 ;
}
static int F_369 ( struct V_4 * V_5 , struct V_90 * V_91 ,
struct V_126 * V_127 , enum V_574 type ,
int V_575 , int * V_576 )
{
struct V_561 * V_562 ;
struct V_567 * V_568 ;
int V_32 = 1 ;
int V_577 = * V_576 ;
F_173 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_578 : {
struct V_9 * V_142 ;
F_87 (ifa, &idev->addr_list, if_list) {
if ( ++ V_577 < V_575 )
continue;
V_32 = F_364 ( V_91 , V_142 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_429 ,
V_139 ) ;
if ( V_32 < 0 )
break;
F_83 ( V_127 , F_84 ( V_91 ) ) ;
}
break;
}
case V_579 :
for ( V_562 = V_5 -> V_580 ; V_562 ;
V_562 = V_562 -> V_525 , V_577 ++ ) {
if ( V_577 < V_575 )
continue;
V_32 = F_367 ( V_91 , V_562 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_581 ,
V_139 ) ;
if ( V_32 < 0 )
break;
}
break;
case V_582 :
for ( V_568 = V_5 -> V_583 ; V_568 ;
V_568 = V_568 -> V_584 , V_577 ++ ) {
if ( V_577 < V_575 )
continue;
V_32 = F_368 ( V_91 , V_568 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_585 ,
V_139 ) ;
if ( V_32 < 0 )
break;
}
break;
default:
break;
}
F_179 ( & V_5 -> V_36 ) ;
* V_576 = V_577 ;
return V_32 ;
}
static int F_370 ( struct V_90 * V_91 , struct V_126 * V_127 ,
enum V_574 type )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_115 ) ;
int V_128 , V_129 ;
int V_130 , V_577 ;
int V_131 , V_575 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_132 * V_133 ;
V_129 = V_127 -> args [ 0 ] ;
V_131 = V_130 = V_127 -> args [ 1 ] ;
V_575 = V_577 = V_127 -> args [ 2 ] ;
F_79 () ;
V_127 -> V_96 = F_80 ( & V_109 -> V_18 . V_136 ) ^ V_109 -> V_137 ;
for ( V_128 = V_129 ; V_128 < V_134 ; V_128 ++ , V_131 = 0 ) {
V_130 = 0 ;
V_133 = & V_109 -> V_135 [ V_128 ] ;
F_81 (dev, head, index_hlist) {
if ( V_130 < V_131 )
goto V_138;
if ( V_128 > V_129 || V_130 > V_131 )
V_575 = 0 ;
V_577 = 0 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_138;
if ( F_369 ( V_5 , V_91 , V_127 , type ,
V_575 , & V_577 ) < 0 )
goto V_140;
V_138:
V_130 ++ ;
}
}
V_140:
F_82 () ;
V_127 -> args [ 0 ] = V_128 ;
V_127 -> args [ 1 ] = V_130 ;
V_127 -> args [ 2 ] = V_577 ;
return V_91 -> V_141 ;
}
static int F_371 ( struct V_90 * V_91 , struct V_126 * V_127 )
{
enum V_574 type = V_578 ;
return F_370 ( V_91 , V_127 , type ) ;
}
static int F_372 ( struct V_90 * V_91 , struct V_126 * V_127 )
{
enum V_574 type = V_579 ;
return F_370 ( V_91 , V_127 , type ) ;
}
static int F_373 ( struct V_90 * V_91 , struct V_126 * V_127 )
{
enum V_574 type = V_582 ;
return F_370 ( V_91 , V_127 , type ) ;
}
static int F_374 ( struct V_90 * V_114 , struct V_98 * V_99 )
{
struct V_109 * V_109 = F_72 ( V_114 -> V_115 ) ;
struct V_535 * V_536 ;
struct V_116 * V_117 [ V_537 + 1 ] ;
struct V_164 * V_162 = NULL , * V_586 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_142 ;
struct V_90 * V_91 ;
int V_32 ;
V_32 = F_73 ( V_99 , sizeof( * V_536 ) , V_117 , V_537 , V_538 ) ;
if ( V_32 < 0 )
goto V_111;
V_162 = F_352 ( V_117 [ V_539 ] , V_117 [ V_540 ] , & V_586 ) ;
if ( ! V_162 ) {
V_32 = - V_35 ;
goto V_111;
}
V_536 = F_61 ( V_99 ) ;
if ( V_536 -> V_542 )
V_7 = F_75 ( V_109 , V_536 -> V_542 ) ;
V_142 = F_195 ( V_109 , V_162 , V_7 , 1 ) ;
if ( ! V_142 ) {
V_32 = - V_177 ;
goto V_111;
}
V_91 = F_66 ( F_363 () , V_25 ) ;
if ( ! V_91 ) {
V_32 = - V_110 ;
goto V_587;
}
V_32 = F_364 ( V_91 , V_142 , F_76 ( V_114 ) . V_95 ,
V_99 -> V_125 , V_429 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_587;
}
V_32 = F_77 ( V_91 , V_109 , F_76 ( V_114 ) . V_95 ) ;
V_587:
F_149 ( V_142 ) ;
V_111:
return V_32 ;
}
static void F_375 ( int V_97 , struct V_9 * V_142 )
{
struct V_90 * V_91 ;
struct V_109 * V_109 = F_34 ( V_142 -> V_5 -> V_7 ) ;
int V_32 = - V_110 ;
V_91 = F_66 ( F_363 () , V_124 ) ;
if ( ! V_91 )
goto V_111;
V_32 = F_364 ( V_91 , V_142 , 0 , 0 , V_97 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_111;
}
F_69 ( V_91 , V_109 , 0 , V_588 , NULL , V_124 ) ;
return;
V_111:
if ( V_32 < 0 )
F_70 ( V_109 , V_588 , V_32 ) ;
}
static inline void F_376 ( struct V_93 * V_39 ,
T_2 * V_589 , int V_590 )
{
F_377 ( V_590 < ( V_591 * 4 ) ) ;
memset ( V_589 , 0 , V_590 ) ;
V_589 [ V_592 ] = V_39 -> V_49 ;
V_589 [ V_593 ] = V_39 -> V_594 ;
V_589 [ V_595 ] = V_39 -> V_46 ;
V_589 [ V_596 ] = V_39 -> V_597 ;
V_589 [ V_598 ] = V_39 -> V_599 ;
V_589 [ V_600 ] = V_39 -> V_383 ;
V_589 [ V_601 ] = V_39 -> V_229 ;
V_589 [ V_602 ] = V_39 -> V_62 ;
V_589 [ V_603 ] =
F_378 ( V_39 -> V_497 ) ;
V_589 [ V_604 ] =
F_378 ( V_39 -> V_496 ) ;
V_589 [ V_605 ] = V_39 -> V_606 ;
V_589 [ V_607 ] =
F_378 ( V_39 -> V_608 ) ;
V_589 [ V_609 ] =
F_378 ( V_39 -> V_610 ) ;
V_589 [ V_611 ] = V_39 -> V_69 ;
V_589 [ V_612 ] = V_39 -> V_226 ;
V_589 [ V_613 ] = V_39 -> V_227 ;
V_589 [ V_614 ] = V_39 -> V_223 ;
V_589 [ V_615 ] = V_39 -> V_228 ;
V_589 [ V_616 ] = V_39 -> V_303 ;
V_589 [ V_617 ] = V_39 -> V_618 ;
V_589 [ V_619 ] = V_39 -> V_620 ;
V_589 [ V_621 ] = V_39 -> V_622 ;
#ifdef F_379
V_589 [ V_623 ] = V_39 -> V_624 ;
V_589 [ V_625 ] =
F_378 ( V_39 -> V_626 ) ;
#ifdef F_380
V_589 [ V_627 ] = V_39 -> V_628 ;
#endif
#endif
V_589 [ V_629 ] = V_39 -> V_107 ;
V_589 [ V_630 ] = V_39 -> V_631 ;
#ifdef F_162
V_589 [ V_632 ] = V_39 -> V_235 ;
V_589 [ V_633 ] = V_39 -> V_236 ;
#endif
#ifdef F_58
V_589 [ V_634 ] = V_39 -> V_106 ;
#endif
V_589 [ V_635 ] = V_39 -> V_180 ;
V_589 [ V_636 ] = V_39 -> V_57 ;
V_589 [ V_637 ] = V_39 -> V_638 ;
V_589 [ V_639 ] = V_39 -> V_640 ;
V_589 [ V_641 ] = V_39 -> V_642 ;
V_589 [ V_643 ] = V_39 -> V_644 ;
V_589 [ V_645 ] = V_39 -> V_646 ;
V_589 [ V_647 ] = V_39 -> V_108 ;
V_589 [ V_648 ] = V_39 -> V_279 ;
V_589 [ V_649 ] = V_39 -> V_650 ;
V_589 [ V_651 ] = V_39 -> V_652 ;
V_589 [ V_653 ] = V_39 -> V_488 ;
}
static inline T_14 F_381 ( void )
{
return F_57 ( 4 )
+ F_57 ( sizeof( struct V_654 ) )
+ F_57 ( V_591 * 4 )
+ F_57 ( V_655 * 8 )
+ F_57 ( V_656 * 8 )
+ F_57 ( sizeof( struct V_164 ) ) ;
}
static inline T_14 F_382 ( void )
{
return F_56 ( sizeof( struct V_657 ) )
+ F_57 ( V_658 )
+ F_57 ( V_456 )
+ F_57 ( 4 )
+ F_57 ( 4 )
+ F_57 ( 1 )
+ F_57 ( F_381 () ) ;
}
static inline void F_383 ( T_15 * V_17 , T_16 * V_659 ,
int V_660 , int V_590 )
{
int V_16 ;
int V_661 = V_590 - sizeof( T_15 ) * V_660 ;
F_377 ( V_661 < 0 ) ;
F_384 ( V_660 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_660 ; V_16 ++ )
F_384 ( F_385 ( & V_659 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_660 ] , 0 , V_661 ) ;
}
static inline void F_386 ( T_15 * V_17 , void T_17 * V_659 ,
int V_590 , T_14 V_662 )
{
int V_16 , V_663 ;
T_15 V_664 [ V_655 ] ;
int V_661 = V_590 - sizeof( T_15 ) * V_655 ;
F_377 ( V_661 < 0 ) ;
memset ( V_664 , 0 , sizeof( V_664 ) ) ;
V_664 [ 0 ] = V_655 ;
F_22 (c) {
for ( V_16 = 1 ; V_16 < V_655 ; V_16 ++ )
V_664 [ V_16 ] += F_387 ( V_659 , V_663 , V_16 , V_662 ) ;
}
memcpy ( V_17 , V_664 , V_655 * sizeof( T_15 ) ) ;
memset ( & V_17 [ V_655 ] , 0 , V_661 ) ;
}
static void F_388 ( T_15 * V_17 , struct V_4 * V_5 , int V_665 ,
int V_590 )
{
switch ( V_665 ) {
case V_666 :
F_386 ( V_17 , V_5 -> V_17 . V_18 , V_590 ,
F_389 ( struct V_19 , V_22 ) ) ;
break;
case V_667 :
F_383 ( V_17 , V_5 -> V_17 . V_23 -> V_668 , V_656 , V_590 ) ;
break;
}
}
static int F_390 ( struct V_90 * V_91 , struct V_4 * V_5 ,
T_1 V_669 )
{
struct V_116 * V_670 ;
struct V_654 V_548 ;
if ( F_366 ( V_91 , V_671 , V_5 -> V_72 ) )
goto V_105;
V_548 . V_672 = V_673 ;
V_548 . V_74 = F_1 ( V_5 -> V_74 ) ;
V_548 . V_674 = F_378 ( V_5 -> V_47 -> V_674 ) ;
V_548 . V_675 = F_378 ( F_157 ( V_5 -> V_47 , V_230 ) ) ;
if ( F_361 ( V_91 , V_676 , sizeof( V_548 ) , & V_548 ) )
goto V_105;
V_670 = F_391 ( V_91 , V_677 , V_591 * sizeof( V_678 ) ) ;
if ( ! V_670 )
goto V_105;
F_376 ( & V_5 -> V_39 , F_353 ( V_670 ) , F_392 ( V_670 ) ) ;
if ( V_669 & V_679 )
return 0 ;
V_670 = F_391 ( V_91 , V_666 , V_655 * sizeof( T_15 ) ) ;
if ( ! V_670 )
goto V_105;
F_388 ( F_353 ( V_670 ) , V_5 , V_666 , F_392 ( V_670 ) ) ;
V_670 = F_391 ( V_91 , V_667 , V_656 * sizeof( T_15 ) ) ;
if ( ! V_670 )
goto V_105;
F_388 ( F_353 ( V_670 ) , V_5 , V_667 , F_392 ( V_670 ) ) ;
V_670 = F_391 ( V_91 , V_680 , sizeof( struct V_164 ) ) ;
if ( ! V_670 )
goto V_105;
if ( F_393 ( V_91 , V_681 , V_5 -> V_43 ) )
goto V_105;
F_173 ( & V_5 -> V_36 ) ;
memcpy ( F_353 ( V_670 ) , V_5 -> V_70 . V_220 , F_392 ( V_670 ) ) ;
F_179 ( & V_5 -> V_36 ) ;
return 0 ;
V_105:
return - V_101 ;
}
static T_14 F_394 ( const struct V_6 * V_7 ,
T_1 V_669 )
{
if ( ! F_52 ( V_7 ) )
return 0 ;
return F_381 () ;
}
static int F_395 ( struct V_90 * V_91 , const struct V_6 * V_7 ,
T_1 V_669 )
{
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_682 ;
if ( F_390 ( V_91 , V_5 , V_669 ) < 0 )
return - V_101 ;
return 0 ;
}
static int F_396 ( struct V_4 * V_5 , struct V_164 * V_70 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_683 , V_684 = false ;
struct V_164 V_685 ;
F_29 () ;
if ( ! V_70 )
return - V_35 ;
if ( V_7 -> V_54 & ( V_56 | V_55 ) )
return - V_35 ;
if ( ! F_318 ( V_5 ) )
return - V_35 ;
if ( V_5 -> V_39 . V_62 <= 0 )
return - V_35 ;
F_147 ( & V_5 -> V_36 ) ;
F_288 ( sizeof( V_70 -> V_220 ) != 16 ) ;
memcpy ( V_5 -> V_70 . V_220 + 8 , V_70 -> V_220 + 8 , 8 ) ;
F_151 ( & V_5 -> V_36 ) ;
V_683 = F_207 ( V_70 ) ;
if ( V_683 )
goto V_368;
if ( ! V_5 -> V_80 && ( V_5 -> V_72 & V_73 ) &&
! F_187 ( V_7 , & V_685 , V_145 |
V_232 ) ) {
F_319 ( V_7 , & V_685 , & V_79 ) ;
V_684 = true ;
}
V_368:
F_147 ( & V_5 -> V_36 ) ;
if ( V_684 ) {
V_5 -> V_72 |= V_491 ;
V_5 -> V_495 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_497 ) ;
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
F_305 ( V_476 , V_5 ) ;
F_274 () ;
return 0 ;
}
static int F_397 ( const struct V_6 * V_7 ,
const struct V_116 * V_670 )
{
struct V_116 * V_117 [ V_686 + 1 ] ;
if ( V_7 && ! F_52 ( V_7 ) )
return - V_687 ;
return F_398 ( V_117 , V_686 , V_670 , V_688 ) ;
}
static int F_399 ( struct V_6 * V_7 , const struct V_116 * V_670 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
struct V_116 * V_117 [ V_686 + 1 ] ;
if ( ! V_5 )
return - V_687 ;
if ( F_398 ( V_117 , V_686 , V_670 , NULL ) < 0 )
F_400 () ;
if ( V_117 [ V_680 ] ) {
V_32 = F_396 ( V_5 , F_353 ( V_117 [ V_680 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_117 [ V_681 ] ) {
T_3 V_689 = F_401 ( V_117 [ V_681 ] ) ;
if ( V_689 != V_45 &&
V_689 != V_462 &&
V_689 != V_44 &&
V_689 != V_364 )
return - V_35 ;
if ( V_689 == V_44 &&
! V_5 -> V_39 . V_41 . V_42 &&
! F_34 ( V_7 ) -> V_18 . V_40 -> V_41 . V_42 )
return - V_35 ;
V_5 -> V_43 = V_689 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_402 ( struct V_90 * V_91 , struct V_4 * V_5 ,
T_1 V_95 , T_1 V_96 , int V_97 , unsigned int V_54 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_657 * V_690 ;
struct V_98 * V_99 ;
void * V_691 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( * V_690 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
V_690 = F_61 ( V_99 ) ;
V_690 -> V_692 = V_103 ;
V_690 -> V_693 = 0 ;
V_690 -> V_694 = V_7 -> type ;
V_690 -> V_695 = V_7 -> V_92 ;
V_690 -> V_696 = F_403 ( V_7 ) ;
V_690 -> V_697 = 0 ;
if ( F_404 ( V_91 , V_698 , V_7 -> V_52 ) ||
( V_7 -> V_310 &&
F_361 ( V_91 , V_699 , V_7 -> V_310 , V_7 -> V_312 ) ) ||
F_366 ( V_91 , V_700 , V_7 -> V_33 ) ||
( V_7 -> V_92 != F_405 ( V_7 ) &&
F_366 ( V_91 , V_701 , F_405 ( V_7 ) ) ) ||
F_393 ( V_91 , V_702 ,
F_44 ( V_7 ) ? V_7 -> V_703 : V_704 ) )
goto V_105;
V_691 = F_406 ( V_91 , V_705 ) ;
if ( ! V_691 )
goto V_105;
if ( F_390 ( V_91 , V_5 , 0 ) < 0 )
goto V_105;
F_407 ( V_91 , V_691 ) ;
F_63 ( V_91 , V_99 ) ;
return 0 ;
V_105:
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
static int F_408 ( struct V_90 * V_91 , struct V_126 * V_127 )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_115 ) ;
int V_128 , V_129 ;
int V_130 = 0 , V_131 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_132 * V_133 ;
V_129 = V_127 -> args [ 0 ] ;
V_131 = V_127 -> args [ 1 ] ;
F_79 () ;
for ( V_128 = V_129 ; V_128 < V_134 ; V_128 ++ , V_131 = 0 ) {
V_130 = 0 ;
V_133 = & V_109 -> V_135 [ V_128 ] ;
F_81 (dev, head, index_hlist) {
if ( V_130 < V_131 )
goto V_138;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_138;
if ( F_402 ( V_91 , V_5 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_476 , V_139 ) < 0 )
goto V_184;
V_138:
V_130 ++ ;
}
}
V_184:
F_82 () ;
V_127 -> args [ 1 ] = V_130 ;
V_127 -> args [ 0 ] = V_128 ;
return V_91 -> V_141 ;
}
void F_305 ( int V_97 , struct V_4 * V_5 )
{
struct V_90 * V_91 ;
struct V_109 * V_109 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_110 ;
V_91 = F_66 ( F_382 () , V_124 ) ;
if ( ! V_91 )
goto V_111;
V_32 = F_402 ( V_91 , V_5 , 0 , 0 , V_97 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_111;
}
F_69 ( V_91 , V_109 , 0 , V_706 , NULL , V_124 ) ;
return;
V_111:
if ( V_32 < 0 )
F_70 ( V_109 , V_706 , V_32 ) ;
}
static inline T_14 F_409 ( void )
{
return F_56 ( sizeof( struct V_707 ) )
+ F_57 ( sizeof( struct V_164 ) )
+ F_57 ( sizeof( struct V_708 ) ) ;
}
static int F_410 ( struct V_90 * V_91 , struct V_4 * V_5 ,
struct V_365 * V_366 , T_1 V_95 , T_1 V_96 ,
int V_97 , unsigned int V_54 )
{
struct V_707 * V_709 ;
struct V_98 * V_99 ;
struct V_708 V_548 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( * V_709 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
V_709 = F_61 ( V_99 ) ;
V_709 -> V_710 = V_103 ;
V_709 -> V_711 = 0 ;
V_709 -> V_712 = 0 ;
V_709 -> V_713 = V_5 -> V_7 -> V_92 ;
V_709 -> V_186 = V_366 -> V_186 ;
V_709 -> V_714 = V_366 -> type ;
V_709 -> V_715 = 0 ;
V_709 -> V_716 = 0 ;
if ( V_366 -> V_287 )
V_709 -> V_716 |= V_717 ;
if ( V_366 -> V_383 )
V_709 -> V_716 |= V_718 ;
if ( F_361 ( V_91 , V_719 , sizeof( V_366 -> V_375 ) , & V_366 -> V_375 ) )
goto V_105;
V_548 . V_720 = F_253 ( V_366 -> V_378 ) ;
V_548 . V_721 = F_253 ( V_366 -> V_377 ) ;
if ( F_361 ( V_91 , V_722 , sizeof( V_548 ) , & V_548 ) )
goto V_105;
F_63 ( V_91 , V_99 ) ;
return 0 ;
V_105:
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
static void F_260 ( int V_97 , struct V_4 * V_5 ,
struct V_365 * V_366 )
{
struct V_90 * V_91 ;
struct V_109 * V_109 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_110 ;
V_91 = F_66 ( F_409 () , V_124 ) ;
if ( ! V_91 )
goto V_111;
V_32 = F_410 ( V_91 , V_5 , V_366 , 0 , 0 , V_97 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_111;
}
F_69 ( V_91 , V_109 , 0 , V_723 , NULL , V_124 ) ;
return;
V_111:
if ( V_32 < 0 )
F_70 ( V_109 , V_723 , V_32 ) ;
}
static void F_315 ( int V_97 , struct V_9 * V_10 )
{
struct V_109 * V_109 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_97 )
F_29 () ;
F_375 ( V_97 ? : V_429 , V_10 ) ;
switch ( V_97 ) {
case V_429 :
if ( ! ( V_10 -> V_158 -> V_724 ) )
F_284 ( V_10 -> V_158 ) ;
if ( V_10 -> V_5 -> V_39 . V_49 )
F_88 ( V_10 ) ;
if ( ! F_207 ( & V_10 -> V_166 ) )
F_234 ( & V_10 -> V_166 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_207 :
if ( V_10 -> V_5 -> V_39 . V_49 )
F_89 ( V_10 ) ;
F_204 ( V_10 -> V_5 , & V_10 -> V_162 ) ;
if ( ! F_207 ( & V_10 -> V_166 ) ) {
struct V_171 * V_158 ;
V_158 = F_140 ( & V_10 -> V_166 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
if ( V_158 )
F_141 ( V_158 ) ;
}
if ( V_10 -> V_158 ) {
F_239 ( & V_10 -> V_158 -> V_240 ) ;
F_141 ( V_10 -> V_158 ) ;
}
F_411 ( V_109 ) ;
break;
}
F_412 ( & V_109 -> V_18 . V_136 ) ;
}
static void F_152 ( int V_97 , struct V_9 * V_10 )
{
F_118 () ;
if ( F_133 ( V_10 -> V_5 -> V_80 == 0 ) )
F_315 ( V_97 , V_10 ) ;
F_132 () ;
}
static
int F_413 ( struct V_148 * V_725 , int V_726 ,
void T_6 * V_727 , T_14 * V_728 , T_8 * V_729 )
{
int * V_730 = V_725 -> V_329 ;
int V_731 = * V_730 ;
T_8 V_512 = * V_729 ;
struct V_148 V_732 ;
int V_217 ;
V_732 = * V_725 ;
V_732 . V_329 = & V_731 ;
V_217 = F_414 ( & V_732 , V_726 , V_727 , V_728 , V_729 ) ;
if ( V_726 )
V_217 = F_92 ( V_725 , V_730 , V_731 ) ;
if ( V_217 )
* V_729 = V_512 ;
return V_217 ;
}
static
int F_415 ( struct V_148 * V_725 , int V_726 ,
void T_6 * V_727 , T_14 * V_728 , T_8 * V_729 )
{
struct V_148 V_732 ;
int V_733 = 1 , V_734 = 255 ;
V_732 = * V_725 ;
V_732 . V_154 = & V_733 ;
V_732 . V_152 = & V_734 ;
return F_416 ( & V_732 , V_726 , V_727 , V_728 , V_729 ) ;
}
static
int F_417 ( struct V_148 * V_725 , int V_726 ,
void T_6 * V_727 , T_14 * V_728 , T_8 * V_729 )
{
struct V_4 * V_5 = V_725 -> V_154 ;
int V_735 = V_34 ;
struct V_148 V_732 ;
V_732 = * V_725 ;
V_732 . V_154 = & V_735 ;
V_732 . V_152 = V_5 ? & V_5 -> V_7 -> V_33 : NULL ;
return F_416 ( & V_732 , V_726 , V_727 , V_728 , V_729 ) ;
}
static void F_418 ( struct V_4 * V_5 )
{
struct V_736 V_468 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_419 ( & V_468 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_180 )
F_299 ( NULL , V_208 , & V_468 ) ;
else
F_299 ( NULL , V_191 , & V_468 ) ;
}
static void F_420 ( struct V_109 * V_109 , T_2 V_146 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_79 () ;
F_183 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_147 = ( ! V_5 -> V_39 . V_180 ) ^ ( ! V_146 ) ;
V_5 -> V_39 . V_180 = V_146 ;
if ( V_147 )
F_418 ( V_5 ) ;
}
}
F_82 () ;
}
static int F_421 ( struct V_148 * V_149 , int * V_150 , int V_146 )
{
struct V_109 * V_109 ;
int V_151 ;
if ( ! F_93 () )
return F_94 () ;
V_109 = (struct V_109 * ) V_149 -> V_152 ;
V_151 = * V_150 ;
* V_150 = V_146 ;
if ( V_150 == & V_109 -> V_18 . V_40 -> V_180 ) {
F_95 () ;
return 0 ;
}
if ( V_150 == & V_109 -> V_18 . V_122 -> V_180 ) {
V_109 -> V_18 . V_40 -> V_180 = V_146 ;
F_420 ( V_109 , V_146 ) ;
} else if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_418 ( (struct V_4 * ) V_149 -> V_154 ) ;
F_95 () ;
return 0 ;
}
static
int F_422 ( struct V_148 * V_725 , int V_726 ,
void T_6 * V_727 , T_14 * V_728 , T_8 * V_729 )
{
int * V_730 = V_725 -> V_329 ;
int V_731 = * V_730 ;
T_8 V_512 = * V_729 ;
struct V_148 V_732 ;
int V_217 ;
V_732 = * V_725 ;
V_732 . V_329 = & V_731 ;
V_217 = F_414 ( & V_732 , V_726 , V_727 , V_728 , V_729 ) ;
if ( V_726 )
V_217 = F_421 ( V_725 , V_730 , V_731 ) ;
if ( V_217 )
* V_729 = V_512 ;
return V_217 ;
}
static
int F_423 ( struct V_148 * V_725 , int V_726 ,
void T_6 * V_727 , T_14 * V_728 , T_8 * V_729 )
{
int * V_730 = V_725 -> V_329 ;
int V_217 ;
int V_151 , V_737 ;
V_151 = * V_730 ;
V_217 = F_414 ( V_725 , V_726 , V_727 , V_728 , V_729 ) ;
V_737 = * V_730 ;
if ( V_726 && V_151 != V_737 ) {
struct V_109 * V_109 = V_725 -> V_152 ;
if ( ! F_93 () )
return F_94 () ;
if ( V_730 == & V_109 -> V_18 . V_40 -> V_107 )
F_65 ( V_109 , V_88 ,
V_123 ,
V_109 -> V_18 . V_40 ) ;
else if ( V_730 == & V_109 -> V_18 . V_122 -> V_107 )
F_65 ( V_109 , V_88 ,
V_121 ,
V_109 -> V_18 . V_122 ) ;
else {
struct V_4 * V_5 = V_725 -> V_154 ;
F_65 ( V_109 , V_88 ,
V_5 -> V_7 -> V_92 ,
& V_5 -> V_39 ) ;
}
F_95 () ;
}
return V_217 ;
}
static int F_424 ( struct V_148 * V_725 , int V_726 ,
void T_6 * V_727 , T_14 * V_728 ,
T_8 * V_729 )
{
int V_32 ;
struct V_164 V_162 ;
char V_738 [ V_739 ] ;
struct V_148 V_732 = * V_725 ;
struct V_109 * V_109 = V_725 -> V_152 ;
struct V_459 * V_454 = V_725 -> V_329 ;
if ( & V_109 -> V_18 . V_122 -> V_41 == V_725 -> V_329 )
return - V_740 ;
V_732 . V_741 = V_739 ;
V_732 . V_329 = V_738 ;
if ( ! F_93 () )
return F_94 () ;
if ( ! V_726 && ! V_454 -> V_42 ) {
V_32 = - V_740 ;
goto V_184;
}
V_32 = snprintf ( V_738 , sizeof( V_738 ) , L_30 , & V_454 -> V_454 ) ;
if ( V_32 >= sizeof( V_738 ) ) {
V_32 = - V_740 ;
goto V_184;
}
V_32 = F_425 ( & V_732 , V_726 , V_727 , V_728 , V_729 ) ;
if ( V_32 || ! V_726 )
goto V_184;
if ( F_426 ( V_738 , - 1 , V_162 . V_742 . V_743 , - 1 , NULL ) != 1 ) {
V_32 = - V_740 ;
goto V_184;
}
V_454 -> V_42 = true ;
V_454 -> V_454 = V_162 ;
if ( & V_109 -> V_18 . V_40 -> V_41 == V_725 -> V_329 ) {
struct V_6 * V_7 ;
F_91 (net, dev) {
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_43 =
V_44 ;
}
}
} else {
struct V_4 * V_5 = V_725 -> V_154 ;
V_5 -> V_43 = V_44 ;
}
V_184:
F_95 () ;
return V_32 ;
}
static
int F_427 ( struct V_148 * V_725 ,
int V_726 ,
void T_6 * V_727 ,
T_14 * V_728 ,
T_8 * V_729 )
{
int * V_730 = V_725 -> V_329 ;
int V_731 = * V_730 ;
T_8 V_512 = * V_729 ;
struct V_148 V_732 ;
int V_217 ;
V_732 = * V_725 ;
V_732 . V_329 = & V_731 ;
V_217 = F_414 ( & V_732 , V_726 , V_727 , V_728 , V_729 ) ;
if ( V_726 )
V_217 = F_98 ( V_725 , V_730 , V_731 ) ;
if ( V_217 )
* V_729 = V_512 ;
return V_217 ;
}
static int F_428 ( struct V_109 * V_109 , char * V_744 ,
struct V_4 * V_5 , struct V_93 * V_150 )
{
int V_16 , V_92 ;
struct V_148 * V_149 ;
char V_745 [ sizeof( L_31 ) + V_658 ] ;
V_149 = F_429 ( V_746 , sizeof( V_746 ) , V_25 ) ;
if ( ! V_149 )
goto V_184;
for ( V_16 = 0 ; V_149 [ V_16 ] . V_329 ; V_16 ++ ) {
V_149 [ V_16 ] . V_329 += ( char * ) V_150 - ( char * ) & V_93 ;
V_149 [ V_16 ] . V_154 = V_5 ;
V_149 [ V_16 ] . V_152 = V_109 ;
}
snprintf ( V_745 , sizeof( V_745 ) , L_32 , V_744 ) ;
V_150 -> V_747 = F_430 ( V_109 , V_745 , V_149 ) ;
if ( ! V_150 -> V_747 )
goto free;
if ( ! strcmp ( V_744 , L_33 ) )
V_92 = V_121 ;
else if ( ! strcmp ( V_744 , L_34 ) )
V_92 = V_123 ;
else
V_92 = V_5 -> V_7 -> V_92 ;
F_65 ( V_109 , V_85 , V_92 , V_150 ) ;
return 0 ;
free:
F_26 ( V_149 ) ;
V_184:
return - V_110 ;
}
static void F_431 ( struct V_93 * V_150 )
{
struct V_148 * V_149 ;
if ( ! V_150 -> V_747 )
return;
V_149 = V_150 -> V_747 -> V_748 ;
F_432 ( V_150 -> V_747 ) ;
V_150 -> V_747 = NULL ;
F_26 ( V_149 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_433 ( V_5 -> V_7 -> V_52 ) )
return - V_35 ;
V_32 = F_434 ( V_5 -> V_7 , V_5 -> V_47 ,
& V_749 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_428 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_52 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_435 ( V_5 -> V_47 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_431 ( & V_5 -> V_39 ) ;
F_435 ( V_5 -> V_47 ) ;
}
static int T_10 F_436 ( struct V_109 * V_109 )
{
int V_32 = - V_30 ;
struct V_93 * V_84 , * V_750 ;
V_84 = F_429 ( & V_93 , sizeof( V_93 ) , V_25 ) ;
if ( ! V_84 )
goto V_751;
V_750 = F_429 ( & V_752 , sizeof( V_752 ) , V_25 ) ;
if ( ! V_750 )
goto V_753;
V_750 -> V_383 = V_754 . V_383 ;
V_750 -> V_180 = V_754 . V_180 ;
V_750 -> V_41 . V_42 = false ;
V_84 -> V_41 . V_42 = false ;
V_109 -> V_18 . V_122 = V_84 ;
V_109 -> V_18 . V_40 = V_750 ;
#ifdef F_437
V_32 = F_428 ( V_109 , L_33 , NULL , V_84 ) ;
if ( V_32 < 0 )
goto V_755;
V_32 = F_428 ( V_109 , L_34 , NULL , V_750 ) ;
if ( V_32 < 0 )
goto V_756;
#endif
return 0 ;
#ifdef F_437
V_756:
F_431 ( V_84 ) ;
V_755:
F_26 ( V_750 ) ;
#endif
V_753:
F_26 ( V_84 ) ;
V_751:
return V_32 ;
}
static void T_11 F_438 ( struct V_109 * V_109 )
{
#ifdef F_437
F_431 ( V_109 -> V_18 . V_40 ) ;
F_431 ( V_109 -> V_18 . V_122 ) ;
#endif
F_26 ( V_109 -> V_18 . V_40 ) ;
F_26 ( V_109 -> V_18 . V_122 ) ;
}
int T_12 F_439 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_440 () ;
if ( V_32 < 0 ) {
F_441 ( L_35 ,
V_51 , V_32 ) ;
goto V_184;
}
V_32 = F_346 ( & V_757 ) ;
if ( V_32 < 0 )
goto V_758;
V_15 = F_442 ( L_36 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_759;
}
F_262 () ;
V_5 = F_28 ( V_760 . V_761 ) ;
F_95 () ;
if ( F_53 ( V_5 ) ) {
V_32 = F_122 ( V_5 ) ;
goto V_762;
}
for ( V_16 = 0 ; V_16 < V_489 ; V_16 ++ )
F_443 ( & V_188 [ V_16 ] ) ;
F_444 ( & V_763 ) ;
F_251 () ;
F_445 ( & V_764 ) ;
V_32 = F_446 ( V_765 , V_766 , NULL , F_408 ,
NULL ) ;
if ( V_32 < 0 )
goto V_111;
F_446 ( V_765 , V_429 , F_358 , NULL , NULL ) ;
F_446 ( V_765 , V_207 , F_355 , NULL , NULL ) ;
F_446 ( V_765 , V_767 , F_374 ,
F_371 , NULL ) ;
F_446 ( V_765 , V_581 , NULL ,
F_372 , NULL ) ;
F_446 ( V_765 , V_585 , NULL ,
F_373 , NULL ) ;
F_446 ( V_765 , V_768 , F_71 ,
F_78 , NULL ) ;
F_447 () ;
return 0 ;
V_111:
F_448 ( & V_764 ) ;
F_449 ( & V_763 ) ;
V_762:
F_450 ( V_15 ) ;
V_759:
F_348 ( & V_757 ) ;
V_758:
F_451 () ;
V_184:
return V_32 ;
}
void F_452 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_449 ( & V_763 ) ;
F_348 ( & V_757 ) ;
F_451 () ;
F_262 () ;
F_453 ( & V_764 ) ;
F_91 (&init_net, dev) {
if ( F_52 ( V_7 ) == NULL )
continue;
F_302 ( V_7 , 1 ) ;
}
F_302 ( V_760 . V_761 , 2 ) ;
F_144 ( & V_182 ) ;
for ( V_16 = 0 ; V_16 < V_489 ; V_16 ++ )
F_67 ( ! F_454 ( & V_188 [ V_16 ] ) ) ;
F_145 ( & V_182 ) ;
F_10 ( & V_529 ) ;
F_95 () ;
F_450 ( V_15 ) ;
}
