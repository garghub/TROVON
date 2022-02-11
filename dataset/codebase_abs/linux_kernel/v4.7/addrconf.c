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
V_91 = F_66 ( F_55 ( type ) , V_111 ) ;
if ( ! V_91 )
goto V_112;
V_32 = F_59 ( V_91 , V_92 , V_94 , 0 , 0 ,
V_113 , 0 , type ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_112;
}
F_69 ( V_91 , V_109 , 0 , V_114 , NULL , V_111 ) ;
return;
V_112:
F_70 ( V_109 , V_114 , V_32 ) ;
}
static int F_71 ( struct V_90 * V_115 ,
struct V_98 * V_99 )
{
struct V_109 * V_109 = F_72 ( V_115 -> V_116 ) ;
struct V_117 * V_118 [ V_119 + 1 ] ;
struct V_83 * V_100 ;
struct V_90 * V_91 ;
struct V_93 * V_94 ;
struct V_4 * V_120 ;
struct V_6 * V_7 ;
int V_92 ;
int V_32 ;
V_32 = F_73 ( V_99 , sizeof( * V_100 ) , V_118 , V_119 ,
V_121 ) ;
if ( V_32 < 0 )
goto V_112;
V_32 = - V_35 ;
if ( ! V_118 [ V_104 ] )
goto V_112;
V_92 = F_74 ( V_118 [ V_104 ] ) ;
switch ( V_92 ) {
case V_122 :
V_94 = V_109 -> V_18 . V_123 ;
break;
case V_124 :
V_94 = V_109 -> V_18 . V_40 ;
break;
default:
V_7 = F_75 ( V_109 , V_92 ) ;
if ( ! V_7 )
goto V_112;
V_120 = F_52 ( V_7 ) ;
if ( ! V_120 )
goto V_112;
V_94 = & V_120 -> V_39 ;
break;
}
V_32 = - V_110 ;
V_91 = F_66 ( F_55 ( V_85 ) , V_111 ) ;
if ( ! V_91 )
goto V_112;
V_32 = F_59 ( V_91 , V_92 , V_94 ,
F_76 ( V_115 ) . V_95 ,
V_99 -> V_125 , V_113 , 0 ,
V_85 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_112;
}
V_32 = F_77 ( V_91 , V_109 , F_76 ( V_115 ) . V_95 ) ;
V_112:
return V_32 ;
}
static int F_78 ( struct V_90 * V_91 ,
struct V_126 * V_127 )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_116 ) ;
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
V_113 ,
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
if ( F_59 ( V_91 , V_122 ,
V_109 -> V_18 . V_123 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_113 , V_139 ,
V_85 ) < 0 )
goto V_140;
else
V_128 ++ ;
}
if ( V_128 == V_134 + 1 ) {
if ( F_59 ( V_91 , V_124 ,
V_109 -> V_18 . V_40 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_113 , V_139 ,
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
V_124 ,
V_109 -> V_18 . V_40 ) ;
F_95 () ;
return 0 ;
}
if ( V_150 == & V_109 -> V_18 . V_123 -> V_49 ) {
V_109 -> V_18 . V_40 -> V_49 = V_146 ;
F_90 ( V_109 , V_146 ) ;
if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_65 ( V_109 , V_86 ,
V_122 ,
V_109 -> V_18 . V_123 ) ;
} else if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_85 ( (struct V_4 * ) V_149 -> V_153 ) ;
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
V_124 ,
V_109 -> V_18 . V_40 ) ;
F_95 () ;
return 0 ;
}
if ( V_150 == & V_109 -> V_18 . V_123 -> V_108 ) {
V_109 -> V_18 . V_40 -> V_108 = V_146 ;
F_97 ( V_109 , V_146 ) ;
if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_65 ( V_109 ,
V_89 ,
V_122 ,
V_109 -> V_18 . V_123 ) ;
}
F_95 () ;
return 1 ;
}
void F_99 ( struct V_9 * V_10 )
{
F_67 ( ! F_100 ( & V_10 -> V_154 ) ) ;
#ifdef F_101
F_102 ( L_4 , V_51 ) ;
#endif
F_103 ( V_10 -> V_5 ) ;
if ( F_10 ( & V_10 -> V_11 ) )
F_104 ( L_5 ,
V_10 ) ;
if ( V_10 -> V_155 != V_156 ) {
F_105 ( L_6 , V_10 ) ;
return;
}
F_106 ( V_10 -> V_157 ) ;
F_107 ( V_10 , V_158 ) ;
}
static void
F_108 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_159 * V_150 ;
int V_160 = F_109 ( & V_10 -> V_161 ) ;
F_110 (p, &idev->addr_list) {
struct V_9 * V_142
= F_111 ( V_150 , struct V_9 , V_162 ) ;
if ( V_160 >= F_109 ( & V_142 -> V_161 ) )
break;
}
F_112 ( & V_10 -> V_162 , V_150 ) ;
}
static T_1 F_113 ( const struct V_163 * V_161 )
{
return F_114 ( F_115 ( V_161 ) , V_164 ) ;
}
static struct V_9 *
F_116 ( struct V_4 * V_5 , const struct V_163 * V_161 ,
const struct V_163 * V_165 , int V_166 ,
int V_167 , T_1 V_54 , T_1 V_168 , T_1 V_169 )
{
struct V_9 * V_142 = NULL ;
struct V_170 * V_157 ;
unsigned int V_171 ;
int V_32 = 0 ;
int V_172 = F_117 ( V_161 ) ;
if ( V_172 == V_173 ||
V_172 & V_174 ||
( ! ( V_5 -> V_7 -> V_54 & V_56 ) &&
V_172 & V_175 ) )
return F_30 ( - V_176 ) ;
F_118 () ;
if ( V_5 -> V_80 ) {
V_32 = - V_177 ;
goto V_178;
}
if ( V_5 -> V_39 . V_179 ) {
V_32 = - V_180 ;
goto V_178;
}
F_119 ( & V_181 ) ;
if ( F_120 ( F_34 ( V_5 -> V_7 ) , V_161 , V_5 -> V_7 ) ) {
F_38 ( L_7 ) ;
V_32 = - V_182 ;
goto V_183;
}
V_142 = F_25 ( sizeof( struct V_9 ) , V_111 ) ;
if ( ! V_142 ) {
F_38 ( L_8 ) ;
V_32 = - V_110 ;
goto V_183;
}
V_157 = F_121 ( V_5 , V_161 , false ) ;
if ( F_53 ( V_157 ) ) {
V_32 = F_122 ( V_157 ) ;
goto V_183;
}
F_123 ( V_5 -> V_47 ) ;
V_142 -> V_161 = * V_161 ;
if ( V_165 )
V_142 -> V_165 = * V_165 ;
F_124 ( & V_142 -> V_36 ) ;
F_125 ( & V_142 -> V_11 , V_184 ) ;
F_126 ( & V_142 -> V_154 ) ;
V_142 -> V_167 = V_167 ;
V_142 -> V_185 = V_166 ;
V_142 -> V_54 = V_54 | V_145 ;
V_142 -> V_168 = V_168 ;
V_142 -> V_169 = V_169 ;
V_142 -> V_1 = V_142 -> V_74 = V_13 ;
V_142 -> V_186 = false ;
V_142 -> V_157 = V_157 ;
V_142 -> V_5 = V_5 ;
F_14 ( V_5 ) ;
F_18 ( V_142 ) ;
V_171 = F_113 ( V_161 ) ;
F_127 ( & V_142 -> V_154 , & V_187 [ V_171 ] ) ;
F_128 ( & V_181 ) ;
F_129 ( & V_5 -> V_36 ) ;
F_108 ( V_5 , V_142 ) ;
if ( V_142 -> V_54 & V_188 ) {
F_130 ( & V_142 -> V_189 , & V_5 -> V_63 ) ;
F_18 ( V_142 ) ;
}
F_18 ( V_142 ) ;
F_131 ( & V_5 -> V_36 ) ;
V_178:
F_132 () ;
if ( F_133 ( V_32 == 0 ) )
F_134 ( V_190 , V_142 ) ;
else {
F_26 ( V_142 ) ;
V_142 = F_30 ( V_32 ) ;
}
return V_142 ;
V_183:
F_128 ( & V_181 ) ;
goto V_178;
}
static enum V_191
F_135 ( struct V_9 * V_10 , unsigned long * V_192 )
{
struct V_9 * V_142 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_193 ;
enum V_191 V_194 = V_195 ;
* V_192 = V_13 ;
F_87 (ifa, &idev->addr_list, if_list) {
if ( V_142 == V_10 )
continue;
if ( ! F_136 ( & V_142 -> V_161 , & V_10 -> V_161 ,
V_10 -> V_185 ) )
continue;
if ( V_142 -> V_54 & ( V_196 | V_197 ) )
return V_198 ;
V_194 = V_199 ;
F_119 ( & V_142 -> V_36 ) ;
V_193 = F_137 ( V_142 -> V_168 , V_3 ) ;
if ( F_138 ( * V_192 , V_142 -> V_74 + V_193 * V_3 ) )
* V_192 = V_142 -> V_74 + V_193 * V_3 ;
F_128 ( & V_142 -> V_36 ) ;
}
return V_194 ;
}
static void
F_139 ( struct V_9 * V_10 , unsigned long V_192 , bool V_200 )
{
struct V_170 * V_157 ;
V_157 = F_140 ( & V_10 -> V_161 ,
V_10 -> V_185 ,
V_10 -> V_5 -> V_7 ,
0 , V_201 | V_202 ) ;
if ( V_157 ) {
if ( V_200 )
F_141 ( V_157 ) ;
else {
if ( ! ( V_157 -> V_203 & V_204 ) )
F_142 ( V_157 , V_192 ) ;
F_106 ( V_157 ) ;
}
}
}
static void F_143 ( struct V_9 * V_10 )
{
int V_155 ;
enum V_191 V_194 = V_198 ;
unsigned long V_192 ;
F_29 () ;
F_144 ( & V_10 -> V_36 ) ;
V_155 = V_10 -> V_155 ;
V_10 -> V_155 = V_156 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_155 == V_156 )
goto V_183;
F_144 ( & V_181 ) ;
F_146 ( & V_10 -> V_154 ) ;
F_145 ( & V_181 ) ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_10 -> V_54 & V_188 ) {
F_148 ( & V_10 -> V_189 ) ;
if ( V_10 -> V_205 ) {
F_149 ( V_10 -> V_205 ) ;
V_10 -> V_205 = NULL ;
}
F_11 ( V_10 ) ;
}
if ( V_10 -> V_54 & V_196 && ! ( V_10 -> V_54 & V_197 ) )
V_194 = F_135 ( V_10 , & V_192 ) ;
F_150 ( & V_10 -> V_162 ) ;
F_11 ( V_10 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
F_9 ( V_10 ) ;
F_152 ( V_206 , V_10 ) ;
F_134 ( V_207 , V_10 ) ;
if ( V_194 != V_198 ) {
F_139 ( V_10 , V_192 ,
V_194 == V_195 ) ;
}
F_153 ( V_10 ) ;
V_183:
F_149 ( V_10 ) ;
}
static int F_154 ( struct V_9 * V_10 , struct V_9 * V_208 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_163 V_161 , * V_209 ;
unsigned long V_210 , V_211 , V_212 , V_213 ;
unsigned long V_214 ;
int V_215 ;
int V_216 = 0 ;
T_1 V_217 ;
unsigned long V_218 = V_13 ;
F_147 ( & V_5 -> V_36 ) ;
if ( V_208 ) {
F_144 ( & V_208 -> V_36 ) ;
memcpy ( & V_161 . V_219 [ 8 ] , & V_208 -> V_161 . V_219 [ 8 ] , 8 ) ;
F_145 ( & V_208 -> V_36 ) ;
V_209 = & V_161 ;
} else {
V_209 = NULL ;
}
V_220:
F_14 ( V_5 ) ;
if ( V_5 -> V_39 . V_69 <= 0 ) {
F_151 ( & V_5 -> V_36 ) ;
F_43 ( L_9 , V_51 ) ;
F_103 ( V_5 ) ;
V_216 = - 1 ;
goto V_183;
}
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_221 ++ >= V_5 -> V_39 . V_222 ) {
V_5 -> V_39 . V_69 = - 1 ;
F_145 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_105 ( L_10 ,
V_51 ) ;
F_103 ( V_5 ) ;
V_216 = - 1 ;
goto V_183;
}
F_18 ( V_10 ) ;
memcpy ( V_161 . V_219 , V_10 -> V_161 . V_219 , 8 ) ;
F_155 ( V_5 , V_209 ) ;
memcpy ( & V_161 . V_219 [ 8 ] , V_5 -> V_223 , 8 ) ;
V_213 = ( V_218 - V_10 -> V_74 ) / V_3 ;
V_211 = F_156 ( V_224 ,
V_10 -> V_168 ,
V_5 -> V_39 . V_225 + V_213 ) ;
V_210 = F_156 ( V_224 ,
V_10 -> V_169 ,
V_5 -> V_39 . V_226 + V_213 -
V_5 -> V_39 . V_227 ) ;
V_215 = V_10 -> V_185 ;
V_212 = V_10 -> V_74 ;
F_145 ( & V_10 -> V_36 ) ;
V_214 = V_5 -> V_39 . V_222 *
V_5 -> V_39 . V_228 *
F_157 ( V_5 -> V_47 , V_229 ) / V_3 ;
F_151 ( & V_5 -> V_36 ) ;
V_213 = ( V_218 - V_212 + V_230 ) / V_3 ;
if ( V_210 <= V_214 + V_213 ) {
F_149 ( V_10 ) ;
F_103 ( V_5 ) ;
V_216 = - 1 ;
goto V_183;
}
V_217 = V_188 ;
if ( V_10 -> V_54 & V_231 )
V_217 |= V_231 ;
V_208 = F_116 ( V_5 , & V_161 , NULL , V_215 ,
F_158 ( & V_161 ) , V_217 ,
V_211 , V_210 ) ;
if ( F_53 ( V_208 ) ) {
F_149 ( V_10 ) ;
F_103 ( V_5 ) ;
F_43 ( L_11 , V_51 ) ;
V_209 = & V_161 ;
F_147 ( & V_5 -> V_36 ) ;
goto V_220;
}
F_144 ( & V_208 -> V_36 ) ;
V_208 -> V_205 = V_10 ;
V_208 -> V_1 = V_218 ;
V_208 -> V_74 = V_212 ;
F_145 ( & V_208 -> V_36 ) ;
F_159 ( V_208 ) ;
F_149 ( V_208 ) ;
F_103 ( V_5 ) ;
V_183:
return V_216 ;
}
static inline int F_160 ( int type )
{
if ( type & ( V_232 | V_233 | V_175 ) )
return 1 ;
return 0 ;
}
static inline bool F_161 ( struct V_4 * V_5 )
{
#ifdef F_162
return V_5 && V_5 -> V_39 . V_234 && V_5 -> V_39 . V_235 ;
#else
return false ;
#endif
}
static int F_163 ( struct V_109 * V_109 ,
struct V_236 * V_237 ,
struct V_238 * V_239 ,
int V_16 )
{
int V_216 ;
if ( V_16 <= V_237 -> V_240 ) {
switch ( V_16 ) {
case V_241 :
V_216 = V_237 -> V_242 ;
break;
case V_243 :
V_216 = V_237 -> V_244 ;
break;
default:
V_216 = ! ! F_164 ( V_16 , V_237 -> V_245 ) ;
}
goto V_183;
}
switch ( V_16 ) {
case V_246 :
V_216 = ! ! V_237 -> V_142 ;
break;
case V_247 :
V_216 = F_165 ( & V_237 -> V_142 -> V_161 , V_239 -> V_161 ) ;
break;
case V_241 :
V_216 = F_166 ( V_237 -> V_172 ) ;
if ( V_216 >= V_239 -> V_167 )
V_216 = - V_216 ;
else
V_216 -= 128 ;
V_237 -> V_242 = V_216 ;
break;
case V_248 :
{
T_3 V_249 = V_250 ;
if ( ! F_161 ( V_237 -> V_142 -> V_5 ) )
V_249 |= V_231 ;
V_216 = F_160 ( V_237 -> V_172 ) ||
! ( V_237 -> V_142 -> V_54 & V_249 ) ;
break;
}
#ifdef F_167
case V_251 :
{
int V_252 = ! ( V_239 -> V_253 & V_254 ) ;
V_216 = ! ( V_237 -> V_142 -> V_54 & V_255 ) ^ V_252 ;
break;
}
#endif
case V_256 :
V_216 = ( ! V_239 -> V_92 ||
V_239 -> V_92 == V_237 -> V_142 -> V_5 -> V_7 -> V_92 ) ;
break;
case V_257 :
V_216 = F_168 ( V_109 ,
& V_237 -> V_142 -> V_161 , V_237 -> V_172 ,
V_237 -> V_142 -> V_5 -> V_7 -> V_92 ) == V_239 -> V_258 ;
break;
case V_259 :
{
int V_260 = V_239 -> V_253 & ( V_261 | V_262 ) ?
! ! ( V_239 -> V_253 & V_262 ) :
V_237 -> V_142 -> V_5 -> V_39 . V_69 >= 2 ;
V_216 = ( ! ( V_237 -> V_142 -> V_54 & V_188 ) ) ^ V_260 ;
break;
}
case V_263 :
V_216 = ! ( F_169 ( & V_237 -> V_142 -> V_161 ) ^
F_169 ( V_239 -> V_161 ) ) ;
break;
case V_243 :
V_216 = F_170 ( & V_237 -> V_142 -> V_161 , V_239 -> V_161 ) ;
if ( V_216 > V_237 -> V_142 -> V_185 )
V_216 = V_237 -> V_142 -> V_185 ;
V_237 -> V_244 = V_216 ;
break;
#ifdef F_162
case V_264 :
V_216 = ! ( V_237 -> V_142 -> V_54 & V_231 ) ;
break;
#endif
default:
V_216 = 0 ;
}
if ( V_216 )
F_171 ( V_16 , V_237 -> V_245 ) ;
V_237 -> V_240 = V_16 ;
V_183:
return V_216 ;
}
static int F_172 ( struct V_109 * V_109 ,
struct V_238 * V_239 ,
struct V_4 * V_5 ,
struct V_236 * V_265 ,
int V_266 )
{
struct V_236 * V_237 = & V_265 [ 1 - V_266 ] , * V_267 = & V_265 [ V_266 ] ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_237 -> V_142 -> V_54 & V_145 ) &&
( ! ( V_237 -> V_142 -> V_54 & V_231 ) ) )
continue;
V_237 -> V_172 = F_174 ( & V_237 -> V_142 -> V_161 ) ;
if ( F_175 ( V_237 -> V_172 == V_173 ||
V_237 -> V_172 & V_174 ) ) {
F_176 ( L_12 ,
V_5 -> V_7 -> V_52 ) ;
continue;
}
V_237 -> V_240 = - 1 ;
F_177 ( V_237 -> V_245 , V_268 ) ;
for ( V_16 = 0 ; V_16 < V_268 ; V_16 ++ ) {
int V_269 , V_270 ;
V_269 = F_163 ( V_109 , V_267 , V_239 , V_16 ) ;
V_270 = F_163 ( V_109 , V_237 , V_239 , V_16 ) ;
if ( V_269 > V_270 ) {
if ( V_16 == V_241 &&
V_237 -> V_242 > 0 ) {
goto V_183;
}
break;
} else if ( V_269 < V_270 ) {
if ( V_267 -> V_142 )
F_149 ( V_267 -> V_142 ) ;
F_18 ( V_237 -> V_142 ) ;
F_178 ( V_267 , V_237 ) ;
V_266 = 1 - V_266 ;
V_237 -> V_142 = V_267 -> V_142 ;
break;
}
}
}
V_183:
F_179 ( & V_5 -> V_36 ) ;
return V_266 ;
}
int F_180 ( struct V_109 * V_109 , const struct V_6 * V_271 ,
const struct V_163 * V_272 , unsigned int V_253 ,
struct V_163 * V_273 )
{
struct V_236 V_265 [ 2 ] , * V_267 ;
struct V_238 V_239 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_274 ;
bool V_275 = false ;
int V_266 = 0 ;
V_274 = F_174 ( V_272 ) ;
V_239 . V_161 = V_272 ;
V_239 . V_92 = V_271 ? V_271 -> V_92 : 0 ;
V_239 . V_167 = F_166 ( V_274 ) ;
V_239 . V_258 = F_168 ( V_109 , V_272 , V_274 , V_239 . V_92 ) ;
V_239 . V_253 = V_253 ;
V_265 [ V_266 ] . V_240 = - 1 ;
V_265 [ V_266 ] . V_142 = NULL ;
F_79 () ;
if ( V_271 ) {
V_5 = F_52 ( V_271 ) ;
if ( ( V_274 & V_174 ) ||
V_239 . V_167 <= V_276 ||
( V_5 && V_5 -> V_39 . V_277 ) ) {
V_275 = true ;
}
}
if ( V_275 ) {
if ( V_5 )
V_266 = F_172 ( V_109 , & V_239 , V_5 , V_265 , V_266 ) ;
} else {
F_181 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
continue;
V_266 = F_172 ( V_109 , & V_239 , V_5 , V_265 , V_266 ) ;
}
}
F_82 () ;
V_267 = & V_265 [ V_266 ] ;
if ( ! V_267 -> V_142 )
return - V_176 ;
* V_273 = V_267 -> V_142 -> V_161 ;
F_149 ( V_267 -> V_142 ) ;
return 0 ;
}
int F_182 ( struct V_4 * V_5 , struct V_163 * V_161 ,
T_1 V_278 )
{
struct V_9 * V_10 ;
int V_32 = - V_176 ;
F_183 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_167 > V_279 )
break;
if ( V_10 -> V_167 == V_279 &&
! ( V_10 -> V_54 & V_278 ) ) {
* V_161 = V_10 -> V_161 ;
V_32 = 0 ;
break;
}
}
return V_32 ;
}
int F_184 ( struct V_6 * V_7 , struct V_163 * V_161 ,
T_1 V_278 )
{
struct V_4 * V_5 ;
int V_32 = - V_176 ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
V_32 = F_182 ( V_5 , V_161 , V_278 ) ;
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_32 ;
}
static int F_185 ( struct V_4 * V_5 )
{
int V_280 = 0 ;
struct V_9 * V_10 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list)
V_280 ++ ;
F_179 ( & V_5 -> V_36 ) ;
return V_280 ;
}
int F_186 ( struct V_109 * V_109 , const struct V_163 * V_161 ,
const struct V_6 * V_7 , int V_281 )
{
return F_187 ( V_109 , V_161 , V_7 , V_281 , V_145 ) ;
}
int F_187 ( struct V_109 * V_109 , const struct V_163 * V_161 ,
const struct V_6 * V_7 , int V_281 ,
T_1 V_278 )
{
struct V_9 * V_10 ;
unsigned int V_171 = F_113 ( V_161 ) ;
T_1 V_282 ;
F_118 () ;
F_81 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_109 ) )
continue;
V_282 = ( V_10 -> V_54 & V_231 )
? ( V_10 -> V_54 & ~ V_145 )
: V_10 -> V_54 ;
if ( F_165 ( & V_10 -> V_161 , V_161 ) &&
! ( V_282 & V_278 ) &&
( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_167 & ( V_279 | V_283 ) || V_281 ) ) ) {
F_132 () ;
return 1 ;
}
}
F_132 () ;
return 0 ;
}
static bool F_120 ( struct V_109 * V_109 , const struct V_163 * V_161 ,
struct V_6 * V_7 )
{
unsigned int V_171 = F_113 ( V_161 ) ;
struct V_9 * V_10 ;
F_189 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_109 ) )
continue;
if ( F_165 ( & V_10 -> V_161 , V_161 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_190 ( const struct V_163 * V_161 ,
const unsigned int V_185 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_142 ;
bool V_216 = false ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifa, &idev->addr_list, if_list) {
V_216 = F_136 ( V_161 , & V_142 -> V_161 , V_185 ) ;
if ( V_216 )
break;
}
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_216 ;
}
int F_191 ( const struct V_163 * V_161 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_142 ;
int V_284 ;
V_284 = 0 ;
F_79 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifa, &idev->addr_list, if_list) {
V_284 = F_136 ( V_161 , & V_142 -> V_161 ,
V_142 -> V_185 ) ;
if ( V_284 )
break;
}
F_179 ( & V_5 -> V_36 ) ;
}
F_82 () ;
return V_284 ;
}
struct V_9 * F_192 ( struct V_109 * V_109 , const struct V_163 * V_161 ,
struct V_6 * V_7 , int V_281 )
{
struct V_9 * V_10 , * V_285 = NULL ;
unsigned int V_171 = F_113 ( V_161 ) ;
F_118 () ;
F_193 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_109 ) )
continue;
if ( F_165 ( & V_10 -> V_161 , V_161 ) ) {
if ( ! V_7 || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_167 & ( V_279 | V_283 ) || V_281 ) ) {
V_285 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_132 () ;
return V_285 ;
}
static void F_194 ( struct V_9 * V_10 , int V_286 )
{
if ( V_286 )
V_10 -> V_54 |= V_287 ;
if ( V_10 -> V_54 & V_196 ) {
F_144 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_54 |= V_145 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_286 )
F_152 ( 0 , V_10 ) ;
F_149 ( V_10 ) ;
} else if ( V_10 -> V_54 & V_188 ) {
struct V_9 * V_205 ;
F_144 ( & V_10 -> V_36 ) ;
V_205 = V_10 -> V_205 ;
if ( V_205 ) {
F_18 ( V_205 ) ;
F_145 ( & V_10 -> V_36 ) ;
F_154 ( V_205 , V_10 ) ;
F_149 ( V_205 ) ;
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
int V_32 = - V_288 ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_155 == V_289 ) {
V_10 -> V_155 = V_290 ;
V_32 = 0 ;
}
F_145 ( & V_10 -> V_36 ) ;
return V_32 ;
}
void F_196 ( struct V_9 * V_10 )
{
struct V_163 V_161 ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_109 * V_109 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( F_195 ( V_10 ) ) {
F_149 ( V_10 ) ;
return;
}
F_197 ( L_13 ,
V_10 -> V_5 -> V_7 -> V_52 , & V_10 -> V_161 ) ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_54 & V_291 ) {
int V_167 = V_10 -> V_167 ;
T_1 V_54 = V_10 -> V_54 ;
struct V_163 V_292 ;
struct V_9 * V_293 ;
T_1 V_168 , V_294 ;
int V_166 = V_10 -> V_185 ;
int V_295 = V_10 -> V_296 + 1 ;
if ( V_295 > V_109 -> V_18 . V_297 . V_298 ) {
F_197 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_52 ) ;
goto V_299;
}
V_292 = V_10 -> V_161 ;
if ( F_198 ( & V_292 , V_295 ,
V_5 ) )
goto V_299;
V_168 = V_10 -> V_168 ;
V_294 = V_10 -> V_169 ;
F_145 ( & V_10 -> V_36 ) ;
if ( V_5 -> V_39 . V_300 &&
F_185 ( V_5 ) >=
V_5 -> V_39 . V_300 )
goto V_301;
F_197 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_52 ) ;
V_293 = F_116 ( V_5 , & V_292 , NULL , V_166 ,
V_167 , V_54 , V_168 ,
V_294 ) ;
if ( F_53 ( V_293 ) )
goto V_301;
F_144 ( & V_293 -> V_36 ) ;
V_293 -> V_296 = V_295 ;
V_293 -> V_155 = V_302 ;
F_145 ( & V_293 -> V_36 ) ;
F_16 ( V_293 , V_109 -> V_18 . V_297 . V_303 ) ;
F_149 ( V_293 ) ;
V_301:
F_144 ( & V_10 -> V_36 ) ;
} else if ( V_5 -> V_39 . V_57 > 1 && ! V_5 -> V_39 . V_179 ) {
V_161 . V_304 [ 0 ] = F_199 ( 0xfe800000 ) ;
V_161 . V_304 [ 1 ] = 0 ;
if ( ! F_200 ( V_161 . V_219 + 8 , V_5 -> V_7 ) &&
F_165 ( & V_10 -> V_161 , & V_161 ) ) {
V_5 -> V_39 . V_179 = 1 ;
F_43 ( L_16 ,
V_10 -> V_5 -> V_7 -> V_52 ) ;
}
}
V_299:
V_10 -> V_155 = V_305 ;
F_145 ( & V_10 -> V_36 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_201 ( struct V_6 * V_7 , const struct V_163 * V_161 )
{
struct V_163 V_306 ;
if ( V_7 -> V_54 & ( V_56 | V_55 ) )
return;
F_202 ( V_161 , & V_306 ) ;
F_49 ( V_7 , & V_306 ) ;
}
void F_203 ( struct V_4 * V_5 , const struct V_163 * V_161 )
{
struct V_163 V_306 ;
if ( V_5 -> V_7 -> V_54 & ( V_56 | V_55 ) )
return;
F_202 ( V_161 , & V_306 ) ;
F_204 ( V_5 , & V_306 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_163 V_161 ;
if ( V_10 -> V_185 >= 127 )
return;
F_205 ( & V_161 , & V_10 -> V_161 , V_10 -> V_185 ) ;
if ( F_206 ( & V_161 ) )
return;
F_207 ( V_10 -> V_5 , & V_161 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
struct V_163 V_161 ;
if ( V_10 -> V_185 >= 127 )
return;
F_205 ( & V_161 , & V_10 -> V_161 , V_10 -> V_185 ) ;
if ( F_206 ( & V_161 ) )
return;
F_208 ( V_10 -> V_5 , & V_161 ) ;
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
static int F_213 ( T_3 * V_307 , T_4 V_161 )
{
if ( V_161 == 0 )
return - 1 ;
V_307 [ 0 ] = ( F_214 ( V_161 ) || F_215 ( V_161 ) ||
F_216 ( V_161 ) || F_217 ( V_161 ) ||
F_218 ( V_161 ) || F_219 ( V_161 ) ||
F_220 ( V_161 ) || F_221 ( V_161 ) ||
F_222 ( V_161 ) || F_223 ( V_161 ) ||
F_224 ( V_161 ) ) ? 0x00 : 0x02 ;
V_307 [ 1 ] = 0 ;
V_307 [ 2 ] = 0x5E ;
V_307 [ 3 ] = 0xFE ;
memcpy ( V_307 + 4 , & V_161 , 4 ) ;
return 0 ;
}
static int F_225 ( T_3 * V_307 , struct V_6 * V_7 )
{
if ( V_7 -> V_60 & V_61 )
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
case V_59 :
return F_225 ( V_307 , V_7 ) ;
case V_323 :
return F_226 ( V_307 , V_7 ) ;
case V_324 :
return F_209 ( V_307 , V_7 ) ;
case V_325 :
return F_210 ( V_307 , V_7 ) ;
case V_67 :
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
if ( V_10 -> V_167 > V_279 )
break;
if ( V_10 -> V_167 == V_279 && ! ( V_10 -> V_54 & V_145 ) ) {
memcpy ( V_307 , V_10 -> V_161 . V_219 + 8 , 8 ) ;
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
F_231 ( V_5 -> V_223 , sizeof( V_5 -> V_223 ) ) ;
V_5 -> V_223 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_223 [ 0 ] == 0xfd &&
( V_5 -> V_223 [ 1 ] & V_5 -> V_223 [ 2 ] & V_5 -> V_223 [ 3 ] & V_5 -> V_223 [ 4 ] & V_5 -> V_223 [ 5 ] & V_5 -> V_223 [ 6 ] ) == 0xff &&
( V_5 -> V_223 [ 7 ] & 0x80 ) )
goto V_326;
if ( ( V_5 -> V_223 [ 0 ] | V_5 -> V_223 [ 1 ] ) == 0 ) {
if ( V_5 -> V_223 [ 2 ] == 0x5e && V_5 -> V_223 [ 3 ] == 0xfe )
goto V_326;
if ( ( V_5 -> V_223 [ 2 ] | V_5 -> V_223 [ 3 ] | V_5 -> V_223 [ 4 ] | V_5 -> V_223 [ 5 ] | V_5 -> V_223 [ 6 ] | V_5 -> V_223 [ 7 ] ) == 0x00 )
goto V_326;
}
}
static void V_65 ( unsigned long V_327 )
{
struct V_4 * V_5 = (struct V_4 * ) V_327 ;
unsigned long V_192 ;
F_118 () ;
F_147 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_80 )
goto V_183;
F_230 ( V_5 ) ;
V_192 = V_13 +
V_5 -> V_39 . V_226 * V_3 -
V_5 -> V_39 . V_222 * V_5 -> V_39 . V_228 *
F_157 ( V_5 -> V_47 , V_229 ) -
V_5 -> V_39 . V_227 * V_3 ;
if ( F_138 ( V_192 , V_13 ) ) {
F_105 ( L_17 ,
V_51 , V_5 -> V_7 -> V_52 ) ;
goto V_183;
}
if ( ! F_15 ( & V_5 -> V_64 , V_192 ) )
F_14 ( V_5 ) ;
V_183:
F_151 ( & V_5 -> V_36 ) ;
F_132 () ;
F_103 ( V_5 ) ;
}
static void F_155 ( struct V_4 * V_5 , struct V_163 * V_209 )
{
if ( V_209 && memcmp ( V_5 -> V_223 , & V_209 -> V_219 [ 8 ] , 8 ) == 0 )
F_230 ( V_5 ) ;
}
static void
F_232 ( struct V_163 * V_328 , int V_329 , struct V_6 * V_7 ,
unsigned long V_192 , T_1 V_54 )
{
struct V_330 V_331 = {
. V_332 = F_233 ( V_7 ) ? : V_333 ,
. V_334 = V_335 ,
. V_336 = V_7 -> V_92 ,
. V_337 = V_192 ,
. V_338 = V_329 ,
. V_339 = V_340 | V_54 ,
. V_341 . V_342 = F_34 ( V_7 ) ,
. V_343 = V_344 ,
} ;
V_331 . V_345 = * V_328 ;
#if F_42 ( V_58 )
if ( V_7 -> type == V_59 && ( V_7 -> V_54 & V_346 ) )
V_331 . V_339 |= V_347 ;
#endif
F_234 ( & V_331 ) ;
}
static struct V_170 * F_140 ( const struct V_163 * V_328 ,
int V_329 ,
const struct V_6 * V_7 ,
T_1 V_54 , T_1 V_348 )
{
struct V_349 * V_350 ;
struct V_170 * V_157 = NULL ;
struct V_351 * V_149 ;
T_1 V_352 = F_233 ( V_7 ) ? : V_333 ;
V_149 = F_235 ( F_34 ( V_7 ) , V_352 ) ;
if ( ! V_149 )
return NULL ;
F_173 ( & V_149 -> V_353 ) ;
V_350 = F_236 ( & V_149 -> V_354 , V_328 , V_329 , NULL , 0 ) ;
if ( ! V_350 )
goto V_183;
V_348 |= V_355 ;
for ( V_157 = V_350 -> V_356 ; V_157 ; V_157 = V_157 -> V_239 . V_357 ) {
if ( V_157 -> V_239 . V_7 -> V_92 != V_7 -> V_92 )
continue;
if ( ( V_157 -> V_203 & V_54 ) != V_54 )
continue;
if ( ( V_157 -> V_203 & V_348 ) != 0 )
continue;
F_237 ( & V_157 -> V_239 ) ;
break;
}
V_183:
F_179 ( & V_149 -> V_353 ) ;
return V_157 ;
}
static void F_238 ( struct V_6 * V_7 )
{
struct V_330 V_331 = {
. V_332 = F_233 ( V_7 ) ? : V_358 ,
. V_334 = V_335 ,
. V_336 = V_7 -> V_92 ,
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
return F_30 ( - V_110 ) ;
if ( V_5 -> V_39 . V_179 )
return F_30 ( - V_180 ) ;
if ( ! ( V_7 -> V_54 & V_56 ) )
F_238 ( V_7 ) ;
return V_5 ;
}
static void F_241 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_224 V_168 , V_224 V_169 ,
bool V_359 , unsigned long V_218 )
{
T_1 V_54 ;
struct V_9 * V_208 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ift, &idev->tempaddr_list, tmp_list) {
int V_213 , V_360 , V_361 ;
if ( V_10 != V_208 -> V_205 )
continue;
V_213 = ( V_218 - V_208 -> V_1 ) / V_3 ;
V_360 = V_5 -> V_39 . V_225 - V_213 ;
if ( V_360 < 0 )
V_360 = 0 ;
V_361 = V_5 -> V_39 . V_226 -
V_5 -> V_39 . V_227 - V_213 ;
if ( V_361 < 0 )
V_361 = 0 ;
if ( V_168 > V_360 )
V_168 = V_360 ;
if ( V_169 > V_361 )
V_169 = V_361 ;
F_119 ( & V_208 -> V_36 ) ;
V_54 = V_208 -> V_54 ;
V_208 -> V_168 = V_168 ;
V_208 -> V_169 = V_169 ;
V_208 -> V_74 = V_218 ;
if ( V_169 > 0 )
V_208 -> V_54 &= ~ V_250 ;
F_128 ( & V_208 -> V_36 ) ;
if ( ! ( V_54 & V_145 ) )
F_152 ( 0 , V_208 ) ;
}
if ( ( V_359 || F_242 ( & V_5 -> V_63 ) ) &&
V_5 -> V_39 . V_69 > 0 ) {
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
void F_244 ( struct V_6 * V_7 , T_3 * V_363 , int V_141 , bool V_364 )
{
struct V_365 * V_366 ;
V_224 V_168 ;
V_224 V_169 ;
int V_172 ;
T_1 V_217 = 0 ;
struct V_4 * V_120 ;
struct V_109 * V_109 = F_34 ( V_7 ) ;
V_366 = (struct V_365 * ) V_363 ;
if ( V_141 < sizeof( struct V_365 ) ) {
F_38 ( L_18 ) ;
return;
}
V_172 = F_117 ( & V_366 -> V_367 ) ;
if ( V_172 & ( V_174 | V_368 ) )
return;
V_168 = F_245 ( V_366 -> V_369 ) ;
V_169 = F_245 ( V_366 -> V_370 ) ;
if ( V_169 > V_168 ) {
F_246 ( L_19 ) ;
return;
}
V_120 = F_247 ( V_7 ) ;
if ( ! V_120 ) {
F_176 ( L_20 ,
V_7 -> V_52 ) ;
return;
}
if ( V_366 -> V_284 ) {
struct V_170 * V_157 ;
unsigned long V_371 ;
if ( V_3 > V_372 )
V_371 = F_137 ( V_168 , V_3 ) ;
else
V_371 = F_137 ( V_168 , V_372 ) ;
if ( F_248 ( V_371 ) )
V_371 *= V_3 ;
V_157 = F_140 ( & V_366 -> V_367 ,
V_366 -> V_185 ,
V_7 ,
V_373 | V_374 ,
V_201 | V_202 ) ;
if ( V_157 ) {
if ( V_168 == 0 ) {
F_141 ( V_157 ) ;
V_157 = NULL ;
} else if ( F_248 ( V_371 ) ) {
F_142 ( V_157 , V_13 + V_371 ) ;
} else {
F_249 ( V_157 ) ;
}
} else if ( V_168 ) {
T_5 V_192 = 0 ;
int V_54 = V_373 | V_374 ;
if ( F_248 ( V_371 ) ) {
V_54 |= V_204 ;
V_192 = F_250 ( V_371 ) ;
}
F_232 ( & V_366 -> V_367 , V_366 -> V_185 ,
V_7 , V_192 , V_54 ) ;
}
F_106 ( V_157 ) ;
}
if ( V_366 -> V_375 && V_120 -> V_39 . V_375 ) {
struct V_9 * V_10 ;
struct V_163 V_161 ;
int V_359 = 0 , V_376 = 0 ;
bool V_186 = false ;
if ( V_366 -> V_185 == 64 ) {
memcpy ( & V_161 , & V_366 -> V_367 , 8 ) ;
if ( ! F_206 ( & V_120 -> V_70 ) ) {
F_173 ( & V_120 -> V_36 ) ;
memcpy ( V_161 . V_219 + 8 ,
V_120 -> V_70 . V_219 + 8 , 8 ) ;
F_179 ( & V_120 -> V_36 ) ;
V_186 = true ;
} else if ( F_243 ( V_120 ) &&
! F_198 ( & V_161 , 0 ,
V_120 ) ) {
V_217 |= V_291 ;
goto V_377;
} else if ( F_200 ( V_161 . V_219 + 8 , V_7 ) &&
F_229 ( V_161 . V_219 + 8 , V_120 ) ) {
F_103 ( V_120 ) ;
return;
}
goto V_377;
}
F_176 ( L_21 ,
V_366 -> V_185 ) ;
F_103 ( V_120 ) ;
return;
V_377:
V_10 = F_192 ( V_109 , & V_161 , V_7 , 1 ) ;
if ( ! V_10 && V_168 ) {
int V_300 = V_120 -> V_39 . V_300 ;
#ifdef F_162
if ( V_120 -> V_39 . V_234 &&
! V_109 -> V_18 . V_123 -> V_49 && V_364 )
V_217 |= V_231 ;
#endif
if ( ! V_300 ||
F_185 ( V_120 ) < V_300 )
V_10 = F_116 ( V_120 , & V_161 , NULL ,
V_366 -> V_185 ,
V_172 & V_378 ,
V_217 , V_168 ,
V_169 ) ;
if ( F_251 ( V_10 ) ) {
F_103 ( V_120 ) ;
return;
}
V_376 = 0 ;
V_359 = 1 ;
F_144 ( & V_10 -> V_36 ) ;
V_10 -> V_54 |= V_379 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_186 = V_186 ;
F_145 ( & V_10 -> V_36 ) ;
F_159 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_54 ;
unsigned long V_218 ;
T_1 V_380 ;
F_144 ( & V_10 -> V_36 ) ;
V_218 = V_13 ;
if ( V_10 -> V_168 > ( V_218 - V_10 -> V_74 ) / V_3 )
V_380 = V_10 -> V_168 - ( V_218 - V_10 -> V_74 ) / V_3 ;
else
V_380 = 0 ;
if ( ! V_376 && ! V_359 && V_380 ) {
const T_1 V_381 = F_156 ( T_1 ,
V_380 , V_382 ) ;
V_168 = F_252 ( V_168 , V_381 ) ;
V_376 = 1 ;
}
if ( V_376 ) {
V_10 -> V_168 = V_168 ;
V_10 -> V_169 = V_169 ;
V_10 -> V_74 = V_218 ;
V_54 = V_10 -> V_54 ;
V_10 -> V_54 &= ~ V_250 ;
F_145 ( & V_10 -> V_36 ) ;
if ( ! ( V_54 & V_145 ) )
F_152 ( 0 , V_10 ) ;
} else
F_145 ( & V_10 -> V_36 ) ;
F_241 ( V_120 , V_10 , V_168 , V_169 ,
V_359 , V_218 ) ;
F_149 ( V_10 ) ;
F_253 () ;
}
}
F_254 ( V_383 , V_120 , V_366 ) ;
F_103 ( V_120 ) ;
}
int F_255 ( struct V_109 * V_109 , void T_6 * V_384 )
{
struct V_385 V_386 ;
struct V_6 * V_7 ;
int V_32 = - V_35 ;
F_256 () ;
V_32 = - V_387 ;
if ( F_257 ( & V_386 , V_384 , sizeof( struct V_385 ) ) )
goto V_388;
V_7 = F_75 ( V_109 , V_386 . V_389 ) ;
V_32 = - V_177 ;
if ( ! V_7 )
goto V_388;
#if F_42 ( V_58 )
if ( V_7 -> type == V_59 ) {
const struct V_390 * V_391 = V_7 -> V_392 ;
struct V_393 V_394 ;
struct V_395 V_150 ;
V_32 = - V_176 ;
if ( ! ( F_117 ( & V_386 . V_396 ) & V_233 ) )
goto V_388;
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
V_150 . V_397 . V_272 = V_386 . V_396 . V_304 [ 3 ] ;
V_150 . V_397 . V_273 = 0 ;
V_150 . V_397 . V_398 = 4 ;
V_150 . V_397 . V_399 = 5 ;
V_150 . V_397 . V_400 = V_401 ;
V_150 . V_397 . V_402 = 64 ;
V_394 . V_403 . V_404 = ( V_405 void T_6 * ) & V_150 ;
if ( V_391 -> V_406 ) {
T_7 V_407 = F_258 () ;
F_259 ( V_408 ) ;
V_32 = V_391 -> V_406 ( V_7 , & V_394 , V_409 ) ;
F_259 ( V_407 ) ;
} else
V_32 = - V_410 ;
if ( V_32 == 0 ) {
V_32 = - V_110 ;
V_7 = F_260 ( V_109 , V_150 . V_52 ) ;
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
static int F_262 ( struct V_411 * V_116 , bool V_412 ,
const struct V_163 * V_161 , int V_92 )
{
int V_216 ;
F_29 () ;
F_263 ( V_116 ) ;
if ( V_412 )
V_216 = F_264 ( V_116 , V_92 , V_161 ) ;
else
V_216 = F_265 ( V_116 , V_92 , V_161 ) ;
F_266 ( V_116 ) ;
return V_216 ;
}
static int F_267 ( struct V_109 * V_109 , int V_92 ,
const struct V_163 * V_328 ,
const struct V_163 * V_413 ,
unsigned int V_329 , V_224 V_414 ,
V_224 V_169 , V_224 V_168 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_415 ;
T_5 V_192 ;
int V_167 ;
T_1 V_54 ;
F_29 () ;
if ( V_329 > 128 )
return - V_35 ;
if ( ! V_168 || V_169 > V_168 )
return - V_35 ;
if ( V_414 & V_379 && V_329 != 64 )
return - V_35 ;
V_7 = F_75 ( V_109 , V_92 ) ;
if ( ! V_7 )
return - V_177 ;
V_5 = F_240 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return F_122 ( V_5 ) ;
if ( V_414 & V_416 ) {
int V_216 = F_262 ( V_109 -> V_18 . V_417 ,
true , V_328 , V_92 ) ;
if ( V_216 < 0 )
return V_216 ;
}
V_167 = F_158 ( V_328 ) ;
V_415 = F_137 ( V_168 , V_3 ) ;
if ( F_248 ( V_415 ) ) {
V_192 = F_250 ( V_415 * V_3 ) ;
V_168 = V_415 ;
V_54 = V_204 ;
} else {
V_192 = 0 ;
V_54 = 0 ;
V_414 |= V_196 ;
}
V_415 = F_137 ( V_169 , V_3 ) ;
if ( F_248 ( V_415 ) ) {
if ( V_415 == 0 )
V_414 |= V_250 ;
V_169 = V_415 ;
}
V_10 = F_116 ( V_5 , V_328 , V_413 , V_329 , V_167 , V_414 ,
V_168 , V_169 ) ;
if ( ! F_53 ( V_10 ) ) {
if ( ! ( V_414 & V_197 ) ) {
F_232 ( & V_10 -> V_161 , V_10 -> V_185 , V_7 ,
V_192 , V_54 ) ;
}
F_159 ( V_10 ) ;
if ( V_414 & V_379 )
F_241 ( V_5 , V_10 , V_168 , V_169 ,
true , V_13 ) ;
F_149 ( V_10 ) ;
F_268 () ;
return 0 ;
} else if ( V_414 & V_416 ) {
F_262 ( V_109 -> V_18 . V_417 ,
false , V_328 , V_92 ) ;
}
return F_122 ( V_10 ) ;
}
static int F_269 ( struct V_109 * V_109 , int V_92 , T_1 V_414 ,
const struct V_163 * V_328 , unsigned int V_329 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_329 > 128 )
return - V_35 ;
V_7 = F_75 ( V_109 , V_92 ) ;
if ( ! V_7 )
return - V_177 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_418 ;
F_173 ( & V_5 -> V_36 ) ;
F_87 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_185 == V_329 &&
F_165 ( V_328 , & V_10 -> V_161 ) ) {
F_18 ( V_10 ) ;
F_179 ( & V_5 -> V_36 ) ;
if ( ! ( V_10 -> V_54 & V_188 ) &&
( V_414 & V_379 ) )
F_241 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_143 ( V_10 ) ;
F_268 () ;
if ( F_270 ( V_328 ) ) {
F_262 ( V_109 -> V_18 . V_417 ,
false , V_328 , V_7 -> V_92 ) ;
}
return 0 ;
}
}
F_179 ( & V_5 -> V_36 ) ;
return - V_176 ;
}
int F_271 ( struct V_109 * V_109 , void T_6 * V_384 )
{
struct V_385 V_386 ;
int V_32 ;
if ( ! F_272 ( V_109 -> V_419 , V_420 ) )
return - V_421 ;
if ( F_257 ( & V_386 , V_384 , sizeof( struct V_385 ) ) )
return - V_387 ;
F_256 () ;
V_32 = F_267 ( V_109 , V_386 . V_389 , & V_386 . V_396 , NULL ,
V_386 . V_422 , V_196 ,
V_423 , V_423 ) ;
F_95 () ;
return V_32 ;
}
int F_273 ( struct V_109 * V_109 , void T_6 * V_384 )
{
struct V_385 V_386 ;
int V_32 ;
if ( ! F_272 ( V_109 -> V_419 , V_420 ) )
return - V_421 ;
if ( F_257 ( & V_386 , V_384 , sizeof( struct V_385 ) ) )
return - V_387 ;
F_256 () ;
V_32 = F_269 ( V_109 , V_386 . V_389 , 0 , & V_386 . V_396 ,
V_386 . V_422 ) ;
F_95 () ;
return V_32 ;
}
static void F_274 ( struct V_4 * V_5 , const struct V_163 * V_161 ,
int V_329 , int V_167 )
{
struct V_9 * V_10 ;
V_10 = F_116 ( V_5 , V_161 , NULL , V_329 ,
V_167 , V_196 ,
V_423 , V_423 ) ;
if ( ! F_53 ( V_10 ) ) {
F_144 ( & V_10 -> V_36 ) ;
V_10 -> V_54 &= ~ V_145 ;
F_145 ( & V_10 -> V_36 ) ;
F_152 ( V_424 , V_10 ) ;
F_149 ( V_10 ) ;
}
}
static void F_275 ( struct V_4 * V_5 )
{
struct V_163 V_161 ;
struct V_6 * V_7 ;
struct V_109 * V_109 = F_34 ( V_5 -> V_7 ) ;
int V_167 , V_329 ;
T_1 V_425 = 0 ;
F_29 () ;
memset ( & V_161 , 0 , sizeof( struct V_163 ) ) ;
memcpy ( & V_161 . V_304 [ 3 ] , V_5 -> V_7 -> V_310 , 4 ) ;
if ( V_5 -> V_7 -> V_54 & V_346 ) {
V_161 . V_304 [ 0 ] = F_199 ( 0xfe800000 ) ;
V_167 = V_279 ;
V_329 = 64 ;
} else {
V_167 = V_233 ;
V_329 = 96 ;
V_425 |= V_347 ;
}
if ( V_161 . V_304 [ 3 ] ) {
F_274 ( V_5 , & V_161 , V_329 , V_167 ) ;
F_232 ( & V_161 , V_329 , V_5 -> V_7 , 0 , V_425 ) ;
return;
}
F_91 (net, dev) {
struct V_426 * V_427 = F_276 ( V_7 ) ;
if ( V_427 && ( V_7 -> V_54 & V_81 ) ) {
struct V_428 * V_142 ;
int V_429 = V_167 ;
for ( V_142 = V_427 -> V_430 ; V_142 ; V_142 = V_142 -> V_431 ) {
V_161 . V_304 [ 3 ] = V_142 -> V_432 ;
if ( V_142 -> V_433 == V_434 )
continue;
if ( V_142 -> V_433 >= V_435 ) {
if ( V_5 -> V_7 -> V_54 & V_346 )
continue;
V_429 |= V_283 ;
}
F_274 ( V_5 , & V_161 , V_329 , V_429 ) ;
F_232 ( & V_161 , V_329 , V_5 -> V_7 , 0 ,
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
struct V_170 * V_438 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_22 , V_51 ) ;
return;
}
F_274 ( V_5 , & V_439 , 128 , V_283 ) ;
F_91 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_436 -> V_52 , V_7 -> V_52 ) )
continue;
V_5 = F_52 ( V_436 ) ;
if ( ! V_5 )
continue;
F_173 ( & V_5 -> V_36 ) ;
F_87 (sp_ifa, &idev->addr_list, if_list) {
if ( V_437 -> V_54 & ( V_287 | V_145 ) )
continue;
if ( V_437 -> V_157 ) {
if ( V_437 -> V_157 -> V_239 . V_440 > 0 ) {
F_106 ( V_437 -> V_157 ) ;
V_437 -> V_157 = NULL ;
} else {
continue;
}
}
V_438 = F_121 ( V_5 , & V_437 -> V_161 , false ) ;
if ( ! F_53 ( V_438 ) ) {
V_437 -> V_157 = V_438 ;
F_278 ( V_438 ) ;
}
}
F_179 ( & V_5 -> V_36 ) ;
}
}
static void F_279 ( struct V_4 * V_5 ,
const struct V_163 * V_161 , T_1 V_54 )
{
struct V_9 * V_10 ;
T_1 V_217 = V_54 | V_196 ;
#ifdef F_162
if ( V_5 -> V_39 . V_234 &&
! F_34 ( V_5 -> V_7 ) -> V_18 . V_123 -> V_49 )
V_217 |= V_231 ;
#endif
V_10 = F_116 ( V_5 , V_161 , NULL , 64 , V_279 , V_217 ,
V_423 , V_423 ) ;
if ( ! F_53 ( V_10 ) ) {
F_232 ( & V_10 -> V_161 , V_10 -> V_185 , V_5 -> V_7 , 0 , 0 ) ;
F_159 ( V_10 ) ;
F_149 ( V_10 ) ;
}
}
static bool F_280 ( struct V_163 V_441 )
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
static int F_198 ( struct V_163 * V_441 ,
T_3 V_442 ,
const struct V_4 * V_5 )
{
static F_281 ( V_36 ) ;
static V_224 V_443 [ V_444 ] ;
static V_224 V_445 [ V_446 ] ;
static union {
char V_447 [ V_448 ] ;
struct {
struct V_163 V_449 ;
T_4 V_367 [ 2 ] ;
unsigned char V_450 [ V_451 ] ;
T_3 V_442 ;
} V_452 ;
} V_327 ;
struct V_163 V_449 ;
struct V_163 V_453 ;
struct V_109 * V_109 = F_34 ( V_5 -> V_7 ) ;
F_282 ( sizeof( V_327 . V_447 ) != sizeof( V_327 ) ) ;
if ( V_5 -> V_39 . V_41 . V_42 )
V_449 = V_5 -> V_39 . V_41 . V_449 ;
else if ( V_109 -> V_18 . V_40 -> V_41 . V_42 )
V_449 = V_109 -> V_18 . V_40 -> V_41 . V_449 ;
else
return - 1 ;
V_220:
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
if ( V_442 > F_34 ( V_5 -> V_7 ) -> V_18 . V_297 . V_298 )
return - 1 ;
goto V_220;
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
struct V_163 V_161 ;
if ( F_287 ( V_5 -> V_7 ) )
return;
F_239 ( & V_161 , F_199 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
switch ( V_5 -> V_43 ) {
case V_362 :
F_285 ( V_5 ) ;
case V_44 :
if ( ! F_198 ( & V_161 , 0 , V_5 ) )
F_279 ( V_5 , & V_161 ,
V_291 ) ;
else if ( V_456 )
F_232 ( & V_161 , 64 , V_5 -> V_7 , 0 , 0 ) ;
break;
case V_45 :
if ( F_200 ( V_161 . V_219 + 8 , V_5 -> V_7 ) == 0 )
F_279 ( V_5 , & V_161 , 0 ) ;
else if ( V_456 )
F_232 ( & V_161 , 64 , V_5 -> V_7 , 0 , 0 ) ;
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
( V_7 -> type != V_67 ) &&
( V_7 -> type != V_324 ) &&
( V_7 -> type != V_68 ) ) {
return;
}
V_5 = F_240 ( V_7 ) ;
if ( F_53 ( V_5 ) )
return;
if ( V_7 -> type == V_68 &&
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
F_102 ( L_22 , V_51 ) ;
return;
}
if ( V_7 -> V_60 & V_61 ) {
F_286 ( V_5 , false ) ;
return;
}
F_275 ( V_5 ) ;
if ( V_7 -> V_54 & V_346 )
F_238 ( V_7 ) ;
}
static void F_290 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_51 ( V_7 ) ;
if ( ! V_5 ) {
F_102 ( L_22 , V_51 ) ;
return;
}
F_286 ( V_5 , true ) ;
if ( V_7 -> V_54 & V_346 )
F_238 ( V_7 ) ;
}
static int F_291 ( struct V_4 * V_5 ,
struct V_9 * V_10 )
{
if ( ! V_10 -> V_157 ) {
struct V_170 * V_157 ;
V_157 = F_121 ( V_5 , & V_10 -> V_161 , false ) ;
if ( F_175 ( F_53 ( V_157 ) ) )
return F_122 ( V_157 ) ;
V_10 -> V_157 = V_157 ;
}
if ( ! ( V_10 -> V_54 & V_197 ) ) {
F_232 ( & V_10 -> V_161 , V_10 -> V_185 ,
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
if ( ( V_10 -> V_54 & V_196 ) &&
F_291 ( V_5 , V_10 ) < 0 ) {
F_151 ( & V_5 -> V_36 ) ;
F_143 ( V_10 ) ;
F_147 ( & V_5 -> V_36 ) ;
F_197 ( L_23 ,
V_5 -> V_7 -> V_52 , & V_10 -> V_161 ) ;
}
}
F_151 ( & V_5 -> V_36 ) ;
}
static int F_294 ( struct V_459 * V_460 , unsigned long V_97 ,
void * V_461 )
{
struct V_6 * V_7 = F_295 ( V_461 ) ;
struct V_462 * V_463 ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
int V_464 = 0 ;
int V_32 ;
switch ( V_97 ) {
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
if ( ! ( V_5 -> V_72 & V_73 ) )
break;
V_464 = 1 ;
case V_190 :
case V_467 :
if ( V_7 -> V_54 & V_468 )
break;
if ( V_5 && V_5 -> V_39 . V_179 )
break;
if ( V_97 == V_190 ) {
F_292 ( V_7 ) ;
if ( ! F_4 ( V_7 ) ) {
F_43 ( L_24 ,
V_7 -> V_52 ) ;
break;
}
if ( ! V_5 && V_7 -> V_33 >= V_34 )
V_5 = F_28 ( V_7 ) ;
if ( ! F_251 ( V_5 ) ) {
V_5 -> V_72 |= V_73 ;
V_464 = 1 ;
}
} else if ( V_97 == V_467 ) {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_72 & V_73 )
break;
V_5 -> V_72 |= V_73 ;
}
F_43 ( L_25 ,
V_7 -> V_52 ) ;
V_464 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_58 )
case V_59 :
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
V_5 -> V_74 = V_13 ;
F_300 ( V_471 , V_5 ) ;
if ( V_7 -> V_33 < V_34 )
F_297 ( V_7 , 1 ) ;
}
break;
case V_207 :
case V_472 :
F_297 ( V_7 , V_97 != V_207 ) ;
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
F_301 ( V_7 , V_97 ) ;
break;
case V_476 :
V_463 = V_461 ;
if ( V_463 -> V_477 && F_287 ( V_463 -> V_477 ) )
F_297 ( V_7 , 0 ) ;
}
return V_478 ;
}
static void F_301 ( struct V_6 * V_7 , unsigned long V_97 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_52 ( V_7 ) ;
if ( V_97 == V_475 )
F_302 ( V_5 ) ;
else if ( V_97 == V_474 )
F_303 ( V_5 ) ;
}
static bool F_304 ( const struct V_163 * V_161 )
{
return F_117 ( V_161 ) &
( V_368 | V_175 ) ;
}
static int F_297 ( struct V_6 * V_7 , int V_479 )
{
struct V_109 * V_109 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_142 , * V_458 ;
struct V_159 V_480 ;
int V_481 ;
bool V_482 ;
int V_155 , V_16 ;
F_29 () ;
F_305 ( V_109 , V_7 ) ;
F_306 ( & V_48 , V_7 ) ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_177 ;
if ( V_479 ) {
V_5 -> V_80 = 1 ;
F_307 ( V_7 -> V_75 , NULL ) ;
F_47 ( V_5 ) ;
}
V_481 = V_109 -> V_18 . V_123 -> V_483 ;
if ( ! V_481 )
V_481 = V_5 -> V_39 . V_483 ;
V_482 = ! ( V_479 || V_481 <= 0 ) ;
for ( V_16 = 0 ; V_16 < V_484 ; V_16 ++ ) {
struct V_132 * V_128 = & V_187 [ V_16 ] ;
F_144 ( & V_181 ) ;
V_485:
F_81 (ifa, h, addr_lst) {
if ( V_142 -> V_5 == V_5 ) {
F_9 ( V_142 ) ;
if ( ! V_482 ||
! ( V_142 -> V_54 & V_196 ) ||
F_304 ( & V_142 -> V_161 ) ) {
F_146 ( & V_142 -> V_154 ) ;
goto V_485;
}
}
}
F_145 ( & V_181 ) ;
}
F_147 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_479 )
V_5 -> V_72 &= ~ ( V_486 | V_487 | V_73 ) ;
if ( V_479 && F_7 ( & V_5 -> V_64 ) )
F_103 ( V_5 ) ;
while ( ! F_242 ( & V_5 -> V_63 ) ) {
V_142 = F_308 ( & V_5 -> V_63 ,
struct V_9 , V_189 ) ;
F_148 ( & V_142 -> V_189 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_144 ( & V_142 -> V_36 ) ;
if ( V_142 -> V_205 ) {
F_149 ( V_142 -> V_205 ) ;
V_142 -> V_205 = NULL ;
}
F_145 ( & V_142 -> V_36 ) ;
F_149 ( V_142 ) ;
F_147 ( & V_5 -> V_36 ) ;
}
V_482 = ( ! V_479 && V_481 > 0 ) ;
F_32 ( & V_480 ) ;
F_293 (ifa, tmp, &idev->addr_list, if_list) {
struct V_170 * V_157 = NULL ;
F_9 ( V_142 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_144 ( & V_142 -> V_36 ) ;
if ( V_482 && ( V_142 -> V_54 & V_196 ) &&
! F_304 ( & V_142 -> V_161 ) ) {
V_155 = V_156 ;
V_142 -> V_155 = 0 ;
if ( ! ( V_142 -> V_54 & V_488 ) )
V_142 -> V_54 |= V_145 ;
V_157 = V_142 -> V_157 ;
V_142 -> V_157 = NULL ;
} else {
V_155 = V_142 -> V_155 ;
V_142 -> V_155 = V_156 ;
F_148 ( & V_142 -> V_162 ) ;
F_130 ( & V_142 -> V_162 , & V_480 ) ;
}
F_145 ( & V_142 -> V_36 ) ;
if ( V_157 )
F_141 ( V_157 ) ;
if ( V_155 != V_156 ) {
F_309 ( V_206 , V_142 ) ;
F_134 ( V_207 , V_142 ) ;
}
F_147 ( & V_5 -> V_36 ) ;
}
F_151 ( & V_5 -> V_36 ) ;
while ( ! F_242 ( & V_480 ) ) {
V_142 = F_308 ( & V_480 ,
struct V_9 , V_162 ) ;
F_148 ( & V_142 -> V_162 ) ;
F_149 ( V_142 ) ;
}
if ( V_479 ) {
F_310 ( V_5 ) ;
F_46 ( V_5 ) ;
} else {
F_311 ( V_5 ) ;
}
V_5 -> V_74 = V_13 ;
if ( V_479 ) {
F_3 ( V_5 ) ;
F_39 ( & V_48 , V_5 -> V_47 ) ;
F_306 ( & V_48 , V_7 ) ;
F_103 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_327 )
{
struct V_4 * V_5 = (struct V_4 * ) V_327 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_163 V_489 ;
F_129 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_80 || ! ( V_5 -> V_72 & V_73 ) )
goto V_183;
if ( ! F_312 ( V_5 ) )
goto V_183;
if ( V_5 -> V_72 & V_487 )
goto V_183;
if ( V_5 -> V_490 ++ < V_5 -> V_39 . V_62 ) {
F_131 ( & V_5 -> V_36 ) ;
if ( ! F_184 ( V_7 , & V_489 , V_145 ) )
F_313 ( V_7 , & V_489 ,
& V_79 ) ;
else
goto V_491;
F_129 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_490 ==
V_5 -> V_39 . V_62 ) ?
V_5 -> V_39 . V_492 :
V_5 -> V_39 . V_493 ) ;
} else {
F_102 ( L_26 , V_5 -> V_7 -> V_52 ) ;
}
V_183:
F_131 ( & V_5 -> V_36 ) ;
V_491:
F_103 ( V_5 ) ;
}
static void F_314 ( struct V_9 * V_10 )
{
unsigned long V_494 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_54 & V_231 )
V_494 = 0 ;
else
V_494 = F_315 () % ( V_5 -> V_39 . V_492 ? : 1 ) ;
V_10 -> V_495 = V_5 -> V_39 . V_228 ;
F_16 ( V_10 , V_494 ) ;
}
static void F_316 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_496 = false ;
F_201 ( V_7 , & V_10 -> V_161 ) ;
F_317 ( ( V_405 T_1 ) V_10 -> V_161 . V_304 [ 3 ] ) ;
F_173 ( & V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_155 == V_156 )
goto V_183;
if ( V_7 -> V_54 & ( V_55 | V_56 ) ||
V_5 -> V_39 . V_57 < 1 ||
! ( V_10 -> V_54 & V_145 ) ||
V_10 -> V_54 & V_488 ) {
V_10 -> V_54 &= ~ ( V_145 | V_231 | V_287 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
F_318 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_72 & V_73 ) ) {
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
F_18 ( V_10 ) ;
F_194 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_54 & V_231 ) {
F_278 ( V_10 -> V_157 ) ;
if ( F_161 ( V_5 ) ) {
V_496 = true ;
}
}
F_314 ( V_10 ) ;
V_183:
F_128 ( & V_10 -> V_36 ) ;
F_179 ( & V_5 -> V_36 ) ;
if ( V_496 )
F_152 ( V_424 , V_10 ) ;
}
static void F_159 ( struct V_9 * V_10 )
{
bool V_497 = false ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_155 != V_156 ) {
V_10 -> V_155 = V_302 ;
V_497 = true ;
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_497 )
F_16 ( V_10 , 0 ) ;
}
static void V_184 ( struct V_498 * V_499 )
{
struct V_9 * V_10 = F_319 ( F_320 ( V_499 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_163 V_500 ;
enum {
V_501 ,
V_502 ,
V_503 ,
} V_194 = V_501 ;
F_256 () ;
F_144 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_155 == V_302 ) {
V_194 = V_502 ;
V_10 -> V_155 = V_289 ;
} else if ( V_10 -> V_155 == V_305 ) {
V_194 = V_503 ;
V_10 -> V_155 = V_290 ;
}
F_145 ( & V_10 -> V_36 ) ;
if ( V_194 == V_502 ) {
F_316 ( V_10 ) ;
goto V_183;
} else if ( V_194 == V_503 ) {
F_194 ( V_10 , 1 ) ;
goto V_183;
}
if ( ! V_10 -> V_495 && F_195 ( V_10 ) )
goto V_183;
F_147 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_80 || ! ( V_5 -> V_72 & V_73 ) ) {
F_151 ( & V_5 -> V_36 ) ;
goto V_183;
}
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_155 == V_156 ) {
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
goto V_183;
}
if ( V_10 -> V_495 == 0 ) {
V_10 -> V_54 &= ~ ( V_145 | V_231 | V_287 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_318 ( V_10 ) ;
goto V_183;
}
V_10 -> V_495 -- ;
F_16 ( V_10 ,
F_157 ( V_10 -> V_5 -> V_47 , V_229 ) ) ;
F_128 ( & V_10 -> V_36 ) ;
F_151 ( & V_5 -> V_36 ) ;
F_202 ( & V_10 -> V_161 , & V_500 ) ;
F_321 ( V_10 -> V_5 -> V_7 , & V_10 -> V_161 , & V_500 , & V_71 ) ;
V_183:
F_149 ( V_10 ) ;
F_95 () ;
}
static bool F_322 ( struct V_9 * V_10 )
{
struct V_9 * V_504 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_183 (ifpiter, &idev->addr_list, if_list) {
if ( V_504 -> V_167 > V_279 )
break;
if ( V_10 != V_504 && V_504 -> V_167 == V_279 &&
( V_504 -> V_54 & ( V_196 | V_145 |
V_231 | V_287 ) ) ==
V_196 )
return false ;
}
return true ;
}
static void F_318 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_163 V_489 ;
bool V_505 , V_506 ;
F_9 ( V_10 ) ;
F_152 ( V_424 , V_10 ) ;
F_173 ( & V_10 -> V_5 -> V_36 ) ;
V_506 = V_10 -> V_167 == V_279 && F_322 ( V_10 ) ;
V_505 = V_506 &&
F_312 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_62 > 0 &&
( V_7 -> V_54 & V_56 ) == 0 ;
F_179 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_506 )
F_323 ( V_10 -> V_5 ) ;
if ( V_505 ) {
if ( F_184 ( V_7 , & V_489 , V_145 ) )
return;
F_313 ( V_7 , & V_489 , & V_79 ) ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
F_119 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_490 = 1 ;
V_10 -> V_5 -> V_72 |= V_486 ;
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
if ( V_10 -> V_54 & V_145 &&
V_10 -> V_155 == V_289 )
F_314 ( V_10 ) ;
F_128 ( & V_10 -> V_36 ) ;
}
F_179 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_324 ( struct V_507 * V_96 , T_8 V_508 )
{
struct V_9 * V_142 = NULL ;
struct V_509 * V_155 = V_96 -> V_510 ;
struct V_109 * V_109 = F_325 ( V_96 ) ;
int V_150 = 0 ;
if ( V_508 == 0 ) {
V_155 -> V_511 = 0 ;
V_155 -> V_512 = 0 ;
}
for (; V_155 -> V_511 < V_484 ; ++ V_155 -> V_511 ) {
F_193 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_188 ( F_34 ( V_142 -> V_5 -> V_7 ) , V_109 ) )
continue;
if ( V_150 < V_155 -> V_512 ) {
V_150 ++ ;
continue;
}
V_155 -> V_512 ++ ;
return V_142 ;
}
V_155 -> V_512 = 0 ;
V_150 = 0 ;
}
return NULL ;
}
static struct V_9 * F_326 ( struct V_507 * V_96 ,
struct V_9 * V_142 )
{
struct V_509 * V_155 = V_96 -> V_510 ;
struct V_109 * V_109 = F_325 ( V_96 ) ;
F_327 (ifa, addr_lst) {
if ( ! F_188 ( F_34 ( V_142 -> V_5 -> V_7 ) , V_109 ) )
continue;
V_155 -> V_512 ++ ;
return V_142 ;
}
while ( ++ V_155 -> V_511 < V_484 ) {
V_155 -> V_512 = 0 ;
F_193 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_188 ( F_34 ( V_142 -> V_5 -> V_7 ) , V_109 ) )
continue;
V_155 -> V_512 ++ ;
return V_142 ;
}
}
return NULL ;
}
static void * F_328 ( struct V_507 * V_96 , T_8 * V_508 )
__acquires( T_9 )
{
F_118 () ;
return F_324 ( V_96 , * V_508 ) ;
}
static void * F_329 ( struct V_507 * V_96 , void * V_513 , T_8 * V_508 )
{
struct V_9 * V_142 ;
V_142 = F_326 ( V_96 , V_513 ) ;
++ * V_508 ;
return V_142 ;
}
static void F_330 ( struct V_507 * V_96 , void * V_513 )
__releases( T_9 )
{
F_132 () ;
}
static int F_331 ( struct V_507 * V_96 , void * V_513 )
{
struct V_9 * V_10 = (struct V_9 * ) V_513 ;
F_332 ( V_96 , L_27 ,
& V_10 -> V_161 ,
V_10 -> V_5 -> V_7 -> V_92 ,
V_10 -> V_185 ,
V_10 -> V_167 ,
( T_3 ) V_10 -> V_54 ,
V_10 -> V_5 -> V_7 -> V_52 ) ;
return 0 ;
}
static int F_333 ( struct V_514 * V_514 , struct V_515 * V_515 )
{
return F_334 ( V_514 , V_515 , & V_516 ,
sizeof( struct V_509 ) ) ;
}
static int T_10 F_335 ( struct V_109 * V_109 )
{
if ( ! F_336 ( L_28 , V_517 , V_109 -> V_518 , & V_519 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_337 ( struct V_109 * V_109 )
{
F_338 ( L_28 , V_109 -> V_518 ) ;
}
int T_12 F_339 ( void )
{
return F_340 ( & V_520 ) ;
}
void F_341 ( void )
{
F_342 ( & V_520 ) ;
}
int F_343 ( struct V_109 * V_109 , const struct V_163 * V_161 )
{
int V_216 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_171 = F_113 ( V_161 ) ;
F_118 () ;
F_193 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_188 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_109 ) )
continue;
if ( F_165 ( & V_10 -> V_161 , V_161 ) &&
( V_10 -> V_54 & V_255 ) ) {
V_216 = 1 ;
break;
}
}
F_132 () ;
return V_216 ;
}
static void F_268 ( void )
{
unsigned long V_218 , V_521 , V_522 , V_523 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_118 () ;
V_218 = V_13 ;
V_521 = F_344 ( V_218 + V_524 ) ;
F_10 ( & V_525 ) ;
for ( V_16 = 0 ; V_16 < V_484 ; V_16 ++ ) {
V_485:
F_193 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_213 ;
if ( ( V_10 -> V_54 & V_196 ) &&
( V_10 -> V_169 == V_423 ) )
continue;
F_119 ( & V_10 -> V_36 ) ;
V_213 = ( V_218 - V_10 -> V_74 + V_230 ) / V_3 ;
if ( V_10 -> V_168 != V_423 &&
V_213 >= V_10 -> V_168 ) {
F_128 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_143 ( V_10 ) ;
goto V_485;
} else if ( V_10 -> V_169 == V_423 ) {
F_128 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_213 >= V_10 -> V_169 ) {
int V_526 = 0 ;
if ( ! ( V_10 -> V_54 & V_250 ) ) {
V_526 = 1 ;
V_10 -> V_54 |= V_250 ;
}
if ( ( V_10 -> V_168 != V_423 ) &&
( F_138 ( V_10 -> V_74 + V_10 -> V_168 * V_3 , V_521 ) ) )
V_521 = V_10 -> V_74 + V_10 -> V_168 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
if ( V_526 ) {
F_18 ( V_10 ) ;
F_152 ( 0 , V_10 ) ;
F_149 ( V_10 ) ;
goto V_485;
}
} else if ( ( V_10 -> V_54 & V_188 ) &&
! ( V_10 -> V_54 & V_145 ) ) {
unsigned long V_214 = V_10 -> V_5 -> V_39 . V_222 *
V_10 -> V_5 -> V_39 . V_228 *
F_157 ( V_10 -> V_5 -> V_47 , V_229 ) / V_3 ;
if ( V_213 >= V_10 -> V_169 - V_214 ) {
struct V_9 * V_205 = V_10 -> V_205 ;
if ( F_138 ( V_10 -> V_74 + V_10 -> V_169 * V_3 , V_521 ) )
V_521 = V_10 -> V_74 + V_10 -> V_169 * V_3 ;
if ( ! V_10 -> V_221 && V_205 ) {
V_10 -> V_221 ++ ;
F_18 ( V_10 ) ;
F_18 ( V_205 ) ;
F_128 ( & V_10 -> V_36 ) ;
F_119 ( & V_205 -> V_36 ) ;
V_205 -> V_221 = 0 ;
F_128 ( & V_205 -> V_36 ) ;
F_154 ( V_205 , V_10 ) ;
F_149 ( V_205 ) ;
F_149 ( V_10 ) ;
goto V_485;
}
} else if ( F_138 ( V_10 -> V_74 + V_10 -> V_169 * V_3 - V_214 * V_3 , V_521 ) )
V_521 = V_10 -> V_74 + V_10 -> V_169 * V_3 - V_214 * V_3 ;
F_128 ( & V_10 -> V_36 ) ;
} else {
if ( F_138 ( V_10 -> V_74 + V_10 -> V_169 * V_3 , V_521 ) )
V_521 = V_10 -> V_74 + V_10 -> V_169 * V_3 ;
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
V_218 , V_521 , V_522 , V_523 ) ;
F_19 ( V_15 , & V_525 , V_523 - V_218 ) ;
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
static struct V_163 * F_346 ( struct V_117 * V_161 , struct V_117 * V_530 ,
struct V_163 * * V_413 )
{
struct V_163 * V_328 = NULL ;
* V_413 = NULL ;
if ( V_161 )
V_328 = F_347 ( V_161 ) ;
if ( V_530 ) {
if ( V_328 && F_348 ( V_530 , V_328 , sizeof( * V_328 ) ) )
* V_413 = V_328 ;
V_328 = F_347 ( V_530 ) ;
}
return V_328 ;
}
static int
F_349 ( struct V_90 * V_91 , struct V_98 * V_99 )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_116 ) ;
struct V_531 * V_532 ;
struct V_117 * V_118 [ V_533 + 1 ] ;
struct V_163 * V_328 , * V_413 ;
T_1 V_414 ;
int V_32 ;
V_32 = F_73 ( V_99 , sizeof( * V_532 ) , V_118 , V_533 , V_534 ) ;
if ( V_32 < 0 )
return V_32 ;
V_532 = F_61 ( V_99 ) ;
V_328 = F_346 ( V_118 [ V_535 ] , V_118 [ V_536 ] , & V_413 ) ;
if ( ! V_328 )
return - V_35 ;
V_414 = V_118 [ V_537 ] ? F_350 ( V_118 [ V_537 ] ) : V_532 -> V_414 ;
V_414 &= V_379 ;
return F_269 ( V_109 , V_532 -> V_538 , V_414 , V_328 ,
V_532 -> V_539 ) ;
}
static int F_351 ( struct V_9 * V_10 , T_1 V_414 ,
T_1 V_169 , T_1 V_168 )
{
T_1 V_54 ;
T_5 V_192 ;
unsigned long V_415 ;
bool V_540 ;
bool V_541 ;
F_29 () ;
if ( ! V_168 || ( V_169 > V_168 ) )
return - V_35 ;
if ( V_414 & V_379 &&
( V_10 -> V_54 & V_188 || V_10 -> V_185 != 64 ) )
return - V_35 ;
V_415 = F_137 ( V_168 , V_3 ) ;
if ( F_248 ( V_415 ) ) {
V_192 = F_250 ( V_415 * V_3 ) ;
V_168 = V_415 ;
V_54 = V_204 ;
} else {
V_192 = 0 ;
V_54 = 0 ;
V_414 |= V_196 ;
}
V_415 = F_137 ( V_169 , V_3 ) ;
if ( F_248 ( V_415 ) ) {
if ( V_415 == 0 )
V_414 |= V_250 ;
V_169 = V_415 ;
}
F_144 ( & V_10 -> V_36 ) ;
V_540 = V_10 -> V_54 & V_379 ;
V_541 = V_10 -> V_54 & V_196 &&
! ( V_10 -> V_54 & V_197 ) ;
V_10 -> V_54 &= ~ ( V_250 | V_196 | V_488 |
V_255 | V_379 |
V_197 ) ;
V_10 -> V_54 |= V_414 ;
V_10 -> V_74 = V_13 ;
V_10 -> V_168 = V_168 ;
V_10 -> V_169 = V_169 ;
F_145 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_54 & V_145 ) )
F_152 ( 0 , V_10 ) ;
if ( ! ( V_414 & V_197 ) ) {
F_232 ( & V_10 -> V_161 , V_10 -> V_185 , V_10 -> V_5 -> V_7 ,
V_192 , V_54 ) ;
} else if ( V_541 ) {
enum V_191 V_194 ;
unsigned long V_371 ;
F_147 ( & V_10 -> V_5 -> V_36 ) ;
V_194 = F_135 ( V_10 , & V_371 ) ;
F_151 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_194 != V_198 ) {
F_139 ( V_10 , V_371 ,
V_194 == V_195 ) ;
}
}
if ( V_540 || V_10 -> V_54 & V_379 ) {
if ( V_540 && ! ( V_10 -> V_54 & V_379 ) )
V_168 = V_169 = 0 ;
F_241 ( V_10 -> V_5 , V_10 , V_168 , V_169 ,
! V_540 , V_13 ) ;
}
F_268 () ;
return 0 ;
}
static int
F_352 ( struct V_90 * V_91 , struct V_98 * V_99 )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_116 ) ;
struct V_531 * V_532 ;
struct V_117 * V_118 [ V_533 + 1 ] ;
struct V_163 * V_328 , * V_413 ;
struct V_9 * V_142 ;
struct V_6 * V_7 ;
T_1 V_168 = V_423 , V_294 = V_423 ;
T_1 V_414 ;
int V_32 ;
V_32 = F_73 ( V_99 , sizeof( * V_532 ) , V_118 , V_533 , V_534 ) ;
if ( V_32 < 0 )
return V_32 ;
V_532 = F_61 ( V_99 ) ;
V_328 = F_346 ( V_118 [ V_535 ] , V_118 [ V_536 ] , & V_413 ) ;
if ( ! V_328 )
return - V_35 ;
if ( V_118 [ V_542 ] ) {
struct V_543 * V_544 ;
V_544 = F_347 ( V_118 [ V_542 ] ) ;
V_168 = V_544 -> V_545 ;
V_294 = V_544 -> V_546 ;
} else {
V_294 = V_423 ;
V_168 = V_423 ;
}
V_7 = F_75 ( V_109 , V_532 -> V_538 ) ;
if ( ! V_7 )
return - V_177 ;
V_414 = V_118 [ V_537 ] ? F_350 ( V_118 [ V_537 ] ) : V_532 -> V_414 ;
V_414 &= V_488 | V_255 | V_379 |
V_197 | V_416 ;
V_142 = F_192 ( V_109 , V_328 , V_7 , 1 ) ;
if ( ! V_142 ) {
return F_267 ( V_109 , V_532 -> V_538 , V_328 , V_413 ,
V_532 -> V_539 , V_414 ,
V_294 , V_168 ) ;
}
if ( V_99 -> V_547 & V_548 ||
! ( V_99 -> V_547 & V_549 ) )
V_32 = - V_182 ;
else
V_32 = F_351 ( V_142 , V_414 , V_294 , V_168 ) ;
F_149 ( V_142 ) ;
return V_32 ;
}
static void F_353 ( struct V_98 * V_99 , T_3 V_550 , T_1 V_54 ,
T_3 V_167 , int V_92 )
{
struct V_531 * V_532 ;
V_532 = F_61 ( V_99 ) ;
V_532 -> V_551 = V_103 ;
V_532 -> V_539 = V_550 ;
V_532 -> V_414 = V_54 ;
V_532 -> V_433 = V_167 ;
V_532 -> V_538 = V_92 ;
}
static int F_354 ( struct V_90 * V_91 , unsigned long V_1 ,
unsigned long V_74 , T_1 V_552 , T_1 V_369 )
{
struct V_543 V_544 ;
V_544 . V_1 = F_1 ( V_1 ) ;
V_544 . V_74 = F_1 ( V_74 ) ;
V_544 . V_546 = V_552 ;
V_544 . V_545 = V_369 ;
return F_355 ( V_91 , V_542 , sizeof( V_544 ) , & V_544 ) ;
}
static inline int F_356 ( int V_433 )
{
if ( V_433 & V_283 )
return V_435 ;
else if ( V_433 & V_279 )
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
static int F_358 ( struct V_90 * V_91 , struct V_9 * V_142 ,
T_1 V_95 , T_1 V_96 , int V_97 , unsigned int V_54 )
{
struct V_98 * V_99 ;
T_1 V_552 , V_369 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( struct V_531 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
F_353 ( V_99 , V_142 -> V_185 , V_142 -> V_54 , F_356 ( V_142 -> V_167 ) ,
V_142 -> V_5 -> V_7 -> V_92 ) ;
if ( ! ( ( V_142 -> V_54 & V_196 ) &&
( V_142 -> V_169 == V_423 ) ) ) {
V_552 = V_142 -> V_169 ;
V_369 = V_142 -> V_168 ;
if ( V_552 != V_423 ) {
long V_556 = ( V_13 - V_142 -> V_74 ) / V_3 ;
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
if ( ! F_206 ( & V_142 -> V_165 ) ) {
if ( F_359 ( V_91 , V_536 , & V_142 -> V_161 ) < 0 ||
F_359 ( V_91 , V_535 , & V_142 -> V_165 ) < 0 )
goto error;
} else
if ( F_359 ( V_91 , V_535 , & V_142 -> V_161 ) < 0 )
goto error;
if ( F_354 ( V_91 , V_142 -> V_1 , V_142 -> V_74 , V_552 , V_369 ) < 0 )
goto error;
if ( F_360 ( V_91 , V_537 , V_142 -> V_54 ) < 0 )
goto error;
F_63 ( V_91 , V_99 ) ;
return 0 ;
error:
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
static int F_361 ( struct V_90 * V_91 , struct V_557 * V_558 ,
T_1 V_95 , T_1 V_96 , int V_97 , T_13 V_54 )
{
struct V_98 * V_99 ;
T_3 V_167 = V_555 ;
int V_92 = V_558 -> V_5 -> V_7 -> V_92 ;
if ( F_158 ( & V_558 -> V_559 ) & V_553 )
V_167 = V_554 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( struct V_531 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
F_353 ( V_99 , 128 , V_196 , V_167 , V_92 ) ;
if ( F_359 ( V_91 , V_560 , & V_558 -> V_559 ) < 0 ||
F_354 ( V_91 , V_558 -> V_561 , V_558 -> V_562 ,
V_423 , V_423 ) < 0 ) {
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
F_63 ( V_91 , V_99 ) ;
return 0 ;
}
static int F_362 ( struct V_90 * V_91 , struct V_563 * V_564 ,
T_1 V_95 , T_1 V_96 , int V_97 , unsigned int V_54 )
{
struct V_98 * V_99 ;
T_3 V_167 = V_555 ;
int V_92 = V_564 -> V_565 -> V_7 -> V_92 ;
if ( F_158 ( & V_564 -> V_566 ) & V_553 )
V_167 = V_554 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( struct V_531 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
F_353 ( V_99 , 128 , V_196 , V_167 , V_92 ) ;
if ( F_359 ( V_91 , V_567 , & V_564 -> V_566 ) < 0 ||
F_354 ( V_91 , V_564 -> V_568 , V_564 -> V_569 ,
V_423 , V_423 ) < 0 ) {
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
F_63 ( V_91 , V_99 ) ;
return 0 ;
}
static int F_363 ( struct V_4 * V_5 , struct V_90 * V_91 ,
struct V_126 * V_127 , enum V_570 type ,
int V_571 , int * V_572 )
{
struct V_557 * V_558 ;
struct V_563 * V_564 ;
int V_32 = 1 ;
int V_573 = * V_572 ;
F_173 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_574 : {
struct V_9 * V_142 ;
F_87 (ifa, &idev->addr_list, if_list) {
if ( ++ V_573 < V_571 )
continue;
V_32 = F_358 ( V_91 , V_142 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_424 ,
V_139 ) ;
if ( V_32 < 0 )
break;
F_83 ( V_127 , F_84 ( V_91 ) ) ;
}
break;
}
case V_575 :
for ( V_558 = V_5 -> V_576 ; V_558 ;
V_558 = V_558 -> V_521 , V_573 ++ ) {
if ( V_573 < V_571 )
continue;
V_32 = F_361 ( V_91 , V_558 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_577 ,
V_139 ) ;
if ( V_32 < 0 )
break;
}
break;
case V_578 :
for ( V_564 = V_5 -> V_579 ; V_564 ;
V_564 = V_564 -> V_580 , V_573 ++ ) {
if ( V_573 < V_571 )
continue;
V_32 = F_362 ( V_91 , V_564 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_581 ,
V_139 ) ;
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
static int F_364 ( struct V_90 * V_91 , struct V_126 * V_127 ,
enum V_570 type )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_116 ) ;
int V_128 , V_129 ;
int V_130 , V_573 ;
int V_131 , V_571 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_132 * V_133 ;
V_129 = V_127 -> args [ 0 ] ;
V_131 = V_130 = V_127 -> args [ 1 ] ;
V_571 = V_573 = V_127 -> args [ 2 ] ;
F_79 () ;
V_127 -> V_96 = F_80 ( & V_109 -> V_18 . V_136 ) ^ V_109 -> V_137 ;
for ( V_128 = V_129 ; V_128 < V_134 ; V_128 ++ , V_131 = 0 ) {
V_130 = 0 ;
V_133 = & V_109 -> V_135 [ V_128 ] ;
F_81 (dev, head, index_hlist) {
if ( V_130 < V_131 )
goto V_138;
if ( V_128 > V_129 || V_130 > V_131 )
V_571 = 0 ;
V_573 = 0 ;
V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
goto V_138;
if ( F_363 ( V_5 , V_91 , V_127 , type ,
V_571 , & V_573 ) < 0 )
goto V_140;
V_138:
V_130 ++ ;
}
}
V_140:
F_82 () ;
V_127 -> args [ 0 ] = V_128 ;
V_127 -> args [ 1 ] = V_130 ;
V_127 -> args [ 2 ] = V_573 ;
return V_91 -> V_141 ;
}
static int F_365 ( struct V_90 * V_91 , struct V_126 * V_127 )
{
enum V_570 type = V_574 ;
return F_364 ( V_91 , V_127 , type ) ;
}
static int F_366 ( struct V_90 * V_91 , struct V_126 * V_127 )
{
enum V_570 type = V_575 ;
return F_364 ( V_91 , V_127 , type ) ;
}
static int F_367 ( struct V_90 * V_91 , struct V_126 * V_127 )
{
enum V_570 type = V_578 ;
return F_364 ( V_91 , V_127 , type ) ;
}
static int F_368 ( struct V_90 * V_115 , struct V_98 * V_99 )
{
struct V_109 * V_109 = F_72 ( V_115 -> V_116 ) ;
struct V_531 * V_532 ;
struct V_117 * V_118 [ V_533 + 1 ] ;
struct V_163 * V_161 = NULL , * V_582 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_142 ;
struct V_90 * V_91 ;
int V_32 ;
V_32 = F_73 ( V_99 , sizeof( * V_532 ) , V_118 , V_533 , V_534 ) ;
if ( V_32 < 0 )
goto V_112;
V_161 = F_346 ( V_118 [ V_535 ] , V_118 [ V_536 ] , & V_582 ) ;
if ( ! V_161 ) {
V_32 = - V_35 ;
goto V_112;
}
V_532 = F_61 ( V_99 ) ;
if ( V_532 -> V_538 )
V_7 = F_75 ( V_109 , V_532 -> V_538 ) ;
V_142 = F_192 ( V_109 , V_161 , V_7 , 1 ) ;
if ( ! V_142 ) {
V_32 = - V_176 ;
goto V_112;
}
V_91 = F_66 ( F_357 () , V_25 ) ;
if ( ! V_91 ) {
V_32 = - V_110 ;
goto V_583;
}
V_32 = F_358 ( V_91 , V_142 , F_76 ( V_115 ) . V_95 ,
V_99 -> V_125 , V_424 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_583;
}
V_32 = F_77 ( V_91 , V_109 , F_76 ( V_115 ) . V_95 ) ;
V_583:
F_149 ( V_142 ) ;
V_112:
return V_32 ;
}
static void F_369 ( int V_97 , struct V_9 * V_142 )
{
struct V_90 * V_91 ;
struct V_109 * V_109 = F_34 ( V_142 -> V_5 -> V_7 ) ;
int V_32 = - V_110 ;
V_91 = F_66 ( F_357 () , V_111 ) ;
if ( ! V_91 )
goto V_112;
V_32 = F_358 ( V_91 , V_142 , 0 , 0 , V_97 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_112;
}
F_69 ( V_91 , V_109 , 0 , V_584 , NULL , V_111 ) ;
return;
V_112:
if ( V_32 < 0 )
F_70 ( V_109 , V_584 , V_32 ) ;
}
static inline void F_370 ( struct V_93 * V_39 ,
T_2 * V_585 , int V_586 )
{
F_371 ( V_586 < ( V_587 * 4 ) ) ;
memset ( V_585 , 0 , V_586 ) ;
V_585 [ V_588 ] = V_39 -> V_49 ;
V_585 [ V_589 ] = V_39 -> V_590 ;
V_585 [ V_591 ] = V_39 -> V_46 ;
V_585 [ V_592 ] = V_39 -> V_593 ;
V_585 [ V_594 ] = V_39 -> V_595 ;
V_585 [ V_596 ] = V_39 -> V_375 ;
V_585 [ V_597 ] = V_39 -> V_228 ;
V_585 [ V_598 ] = V_39 -> V_62 ;
V_585 [ V_599 ] =
F_372 ( V_39 -> V_493 ) ;
V_585 [ V_600 ] =
F_372 ( V_39 -> V_492 ) ;
V_585 [ V_601 ] = V_39 -> V_602 ;
V_585 [ V_603 ] =
F_372 ( V_39 -> V_604 ) ;
V_585 [ V_605 ] =
F_372 ( V_39 -> V_606 ) ;
V_585 [ V_607 ] = V_39 -> V_69 ;
V_585 [ V_608 ] = V_39 -> V_225 ;
V_585 [ V_609 ] = V_39 -> V_226 ;
V_585 [ V_610 ] = V_39 -> V_222 ;
V_585 [ V_611 ] = V_39 -> V_227 ;
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
V_585 [ V_625 ] = V_39 -> V_107 ;
V_585 [ V_626 ] = V_39 -> V_627 ;
#ifdef F_162
V_585 [ V_628 ] = V_39 -> V_234 ;
V_585 [ V_629 ] = V_39 -> V_235 ;
#endif
#ifdef F_58
V_585 [ V_630 ] = V_39 -> V_106 ;
#endif
V_585 [ V_631 ] = V_39 -> V_179 ;
V_585 [ V_632 ] = V_39 -> V_57 ;
V_585 [ V_633 ] = V_39 -> V_634 ;
V_585 [ V_635 ] = V_39 -> V_636 ;
V_585 [ V_637 ] = V_39 -> V_638 ;
V_585 [ V_639 ] = V_39 -> V_640 ;
V_585 [ V_641 ] = V_39 -> V_642 ;
V_585 [ V_643 ] = V_39 -> V_108 ;
V_585 [ V_644 ] = V_39 -> V_277 ;
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
+ F_57 ( sizeof( struct V_163 ) ) ;
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
static int F_384 ( struct V_90 * V_91 , struct V_4 * V_5 ,
T_1 V_665 )
{
struct V_117 * V_666 ;
struct V_650 V_544 ;
if ( F_360 ( V_91 , V_667 , V_5 -> V_72 ) )
goto V_105;
V_544 . V_668 = V_669 ;
V_544 . V_74 = F_1 ( V_5 -> V_74 ) ;
V_544 . V_670 = F_372 ( V_5 -> V_47 -> V_670 ) ;
V_544 . V_671 = F_372 ( F_157 ( V_5 -> V_47 , V_229 ) ) ;
if ( F_355 ( V_91 , V_672 , sizeof( V_544 ) , & V_544 ) )
goto V_105;
V_666 = F_385 ( V_91 , V_673 , V_587 * sizeof( V_674 ) ) ;
if ( ! V_666 )
goto V_105;
F_370 ( & V_5 -> V_39 , F_347 ( V_666 ) , F_386 ( V_666 ) ) ;
if ( V_665 & V_675 )
return 0 ;
V_666 = F_385 ( V_91 , V_662 , V_651 * sizeof( T_15 ) ) ;
if ( ! V_666 )
goto V_105;
F_382 ( F_347 ( V_666 ) , V_5 , V_662 , F_386 ( V_666 ) ) ;
V_666 = F_385 ( V_91 , V_663 , V_652 * sizeof( T_15 ) ) ;
if ( ! V_666 )
goto V_105;
F_382 ( F_347 ( V_666 ) , V_5 , V_663 , F_386 ( V_666 ) ) ;
V_666 = F_385 ( V_91 , V_676 , sizeof( struct V_163 ) ) ;
if ( ! V_666 )
goto V_105;
if ( F_387 ( V_91 , V_677 , V_5 -> V_43 ) )
goto V_105;
F_173 ( & V_5 -> V_36 ) ;
memcpy ( F_347 ( V_666 ) , V_5 -> V_70 . V_219 , F_386 ( V_666 ) ) ;
F_179 ( & V_5 -> V_36 ) ;
return 0 ;
V_105:
return - V_101 ;
}
static T_14 F_388 ( const struct V_6 * V_7 ,
T_1 V_665 )
{
if ( ! F_52 ( V_7 ) )
return 0 ;
return F_375 () ;
}
static int F_389 ( struct V_90 * V_91 , const struct V_6 * V_7 ,
T_1 V_665 )
{
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( ! V_5 )
return - V_678 ;
if ( F_384 ( V_91 , V_5 , V_665 ) < 0 )
return - V_101 ;
return 0 ;
}
static int F_390 ( struct V_4 * V_5 , struct V_163 * V_70 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_679 , V_680 = false ;
struct V_163 V_681 ;
F_29 () ;
if ( ! V_70 )
return - V_35 ;
if ( V_7 -> V_54 & ( V_56 | V_55 ) )
return - V_35 ;
if ( ! F_312 ( V_5 ) )
return - V_35 ;
if ( V_5 -> V_39 . V_62 <= 0 )
return - V_35 ;
F_147 ( & V_5 -> V_36 ) ;
F_282 ( sizeof( V_70 -> V_219 ) != 16 ) ;
memcpy ( V_5 -> V_70 . V_219 + 8 , V_70 -> V_219 + 8 , 8 ) ;
F_151 ( & V_5 -> V_36 ) ;
V_679 = F_206 ( V_70 ) ;
if ( V_679 )
goto V_376;
if ( ! V_5 -> V_80 && ( V_5 -> V_72 & V_73 ) &&
! F_184 ( V_7 , & V_681 , V_145 |
V_231 ) ) {
F_313 ( V_7 , & V_681 , & V_79 ) ;
V_680 = true ;
}
V_376:
F_147 ( & V_5 -> V_36 ) ;
if ( V_680 ) {
V_5 -> V_72 |= V_486 ;
V_5 -> V_490 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_493 ) ;
}
F_87 (ifp, &idev->addr_list, if_list) {
F_119 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_186 ) {
V_10 -> V_168 = 0 ;
V_10 -> V_169 = 0 ;
}
F_128 ( & V_10 -> V_36 ) ;
}
F_151 ( & V_5 -> V_36 ) ;
F_300 ( V_471 , V_5 ) ;
F_268 () ;
return 0 ;
}
static int F_391 ( const struct V_6 * V_7 ,
const struct V_117 * V_666 )
{
struct V_117 * V_118 [ V_682 + 1 ] ;
if ( V_7 && ! F_52 ( V_7 ) )
return - V_683 ;
return F_392 ( V_118 , V_682 , V_666 , V_684 ) ;
}
static int F_393 ( struct V_6 * V_7 , const struct V_117 * V_666 )
{
int V_32 = - V_35 ;
struct V_4 * V_5 = F_52 ( V_7 ) ;
struct V_117 * V_118 [ V_682 + 1 ] ;
if ( ! V_5 )
return - V_683 ;
if ( F_392 ( V_118 , V_682 , V_666 , NULL ) < 0 )
F_394 () ;
if ( V_118 [ V_676 ] ) {
V_32 = F_390 ( V_5 , F_347 ( V_118 [ V_676 ] ) ) ;
if ( V_32 )
return V_32 ;
}
if ( V_118 [ V_677 ] ) {
T_3 V_685 = F_395 ( V_118 [ V_677 ] ) ;
if ( V_685 != V_45 &&
V_685 != V_457 &&
V_685 != V_44 &&
V_685 != V_362 )
return - V_35 ;
if ( V_685 == V_44 &&
! V_5 -> V_39 . V_41 . V_42 &&
! F_34 ( V_7 ) -> V_18 . V_40 -> V_41 . V_42 )
return - V_35 ;
V_5 -> V_43 = V_685 ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_396 ( struct V_90 * V_91 , struct V_4 * V_5 ,
T_1 V_95 , T_1 V_96 , int V_97 , unsigned int V_54 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_653 * V_686 ;
struct V_98 * V_99 ;
void * V_687 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( * V_686 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
V_686 = F_61 ( V_99 ) ;
V_686 -> V_688 = V_103 ;
V_686 -> V_689 = 0 ;
V_686 -> V_690 = V_7 -> type ;
V_686 -> V_691 = V_7 -> V_92 ;
V_686 -> V_692 = F_397 ( V_7 ) ;
V_686 -> V_693 = 0 ;
if ( F_398 ( V_91 , V_694 , V_7 -> V_52 ) ||
( V_7 -> V_308 &&
F_355 ( V_91 , V_695 , V_7 -> V_308 , V_7 -> V_310 ) ) ||
F_360 ( V_91 , V_696 , V_7 -> V_33 ) ||
( V_7 -> V_92 != F_399 ( V_7 ) &&
F_360 ( V_91 , V_697 , F_399 ( V_7 ) ) ) ||
F_387 ( V_91 , V_698 ,
F_44 ( V_7 ) ? V_7 -> V_699 : V_700 ) )
goto V_105;
V_687 = F_400 ( V_91 , V_701 ) ;
if ( ! V_687 )
goto V_105;
if ( F_384 ( V_91 , V_5 , 0 ) < 0 )
goto V_105;
F_401 ( V_91 , V_687 ) ;
F_63 ( V_91 , V_99 ) ;
return 0 ;
V_105:
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
static int F_402 ( struct V_90 * V_91 , struct V_126 * V_127 )
{
struct V_109 * V_109 = F_72 ( V_91 -> V_116 ) ;
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
if ( F_396 ( V_91 , V_5 ,
F_76 ( V_127 -> V_91 ) . V_95 ,
V_127 -> V_99 -> V_125 ,
V_471 , V_139 ) < 0 )
goto V_183;
V_138:
V_130 ++ ;
}
}
V_183:
F_82 () ;
V_127 -> args [ 1 ] = V_130 ;
V_127 -> args [ 0 ] = V_128 ;
return V_91 -> V_141 ;
}
void F_300 ( int V_97 , struct V_4 * V_5 )
{
struct V_90 * V_91 ;
struct V_109 * V_109 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_110 ;
V_91 = F_66 ( F_376 () , V_111 ) ;
if ( ! V_91 )
goto V_112;
V_32 = F_396 ( V_91 , V_5 , 0 , 0 , V_97 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_112;
}
F_69 ( V_91 , V_109 , 0 , V_702 , NULL , V_111 ) ;
return;
V_112:
if ( V_32 < 0 )
F_70 ( V_109 , V_702 , V_32 ) ;
}
static inline T_14 F_403 ( void )
{
return F_56 ( sizeof( struct V_703 ) )
+ F_57 ( sizeof( struct V_163 ) )
+ F_57 ( sizeof( struct V_704 ) ) ;
}
static int F_404 ( struct V_90 * V_91 , struct V_4 * V_5 ,
struct V_365 * V_366 , T_1 V_95 , T_1 V_96 ,
int V_97 , unsigned int V_54 )
{
struct V_703 * V_705 ;
struct V_98 * V_99 ;
struct V_704 V_544 ;
V_99 = F_60 ( V_91 , V_95 , V_96 , V_97 , sizeof( * V_705 ) , V_54 ) ;
if ( ! V_99 )
return - V_101 ;
V_705 = F_61 ( V_99 ) ;
V_705 -> V_706 = V_103 ;
V_705 -> V_707 = 0 ;
V_705 -> V_708 = 0 ;
V_705 -> V_709 = V_5 -> V_7 -> V_92 ;
V_705 -> V_185 = V_366 -> V_185 ;
V_705 -> V_710 = V_366 -> type ;
V_705 -> V_711 = 0 ;
V_705 -> V_712 = 0 ;
if ( V_366 -> V_284 )
V_705 -> V_712 |= V_713 ;
if ( V_366 -> V_375 )
V_705 -> V_712 |= V_714 ;
if ( F_355 ( V_91 , V_715 , sizeof( V_366 -> V_367 ) , & V_366 -> V_367 ) )
goto V_105;
V_544 . V_716 = F_245 ( V_366 -> V_370 ) ;
V_544 . V_717 = F_245 ( V_366 -> V_369 ) ;
if ( F_355 ( V_91 , V_718 , sizeof( V_544 ) , & V_544 ) )
goto V_105;
F_63 ( V_91 , V_99 ) ;
return 0 ;
V_105:
F_64 ( V_91 , V_99 ) ;
return - V_101 ;
}
static void F_254 ( int V_97 , struct V_4 * V_5 ,
struct V_365 * V_366 )
{
struct V_90 * V_91 ;
struct V_109 * V_109 = F_34 ( V_5 -> V_7 ) ;
int V_32 = - V_110 ;
V_91 = F_66 ( F_403 () , V_111 ) ;
if ( ! V_91 )
goto V_112;
V_32 = F_404 ( V_91 , V_5 , V_366 , 0 , 0 , V_97 , 0 ) ;
if ( V_32 < 0 ) {
F_67 ( V_32 == - V_101 ) ;
F_68 ( V_91 ) ;
goto V_112;
}
F_69 ( V_91 , V_109 , 0 , V_719 , NULL , V_111 ) ;
return;
V_112:
if ( V_32 < 0 )
F_70 ( V_109 , V_719 , V_32 ) ;
}
static void F_309 ( int V_97 , struct V_9 * V_10 )
{
struct V_109 * V_109 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_97 )
F_29 () ;
F_369 ( V_97 ? : V_424 , V_10 ) ;
switch ( V_97 ) {
case V_424 :
if ( ! ( V_10 -> V_157 -> V_720 ) )
F_278 ( V_10 -> V_157 ) ;
if ( V_10 -> V_5 -> V_39 . V_49 )
F_88 ( V_10 ) ;
if ( ! F_206 ( & V_10 -> V_165 ) )
F_232 ( & V_10 -> V_165 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_206 :
if ( V_10 -> V_5 -> V_39 . V_49 )
F_89 ( V_10 ) ;
F_203 ( V_10 -> V_5 , & V_10 -> V_161 ) ;
if ( ! F_206 ( & V_10 -> V_165 ) ) {
struct V_170 * V_157 ;
V_157 = F_140 ( & V_10 -> V_165 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
if ( V_157 )
F_141 ( V_157 ) ;
}
if ( V_10 -> V_157 ) {
F_237 ( & V_10 -> V_157 -> V_239 ) ;
F_141 ( V_10 -> V_157 ) ;
}
F_405 ( V_109 ) ;
break;
}
F_406 ( & V_109 -> V_18 . V_136 ) ;
}
static void F_152 ( int V_97 , struct V_9 * V_10 )
{
F_118 () ;
if ( F_133 ( V_10 -> V_5 -> V_80 == 0 ) )
F_309 ( V_97 , V_10 ) ;
F_132 () ;
}
static
int F_407 ( struct V_148 * V_721 , int V_722 ,
void T_6 * V_723 , T_14 * V_724 , T_8 * V_725 )
{
int * V_726 = V_721 -> V_327 ;
int V_727 = * V_726 ;
T_8 V_508 = * V_725 ;
struct V_148 V_728 ;
int V_216 ;
V_728 = * V_721 ;
V_728 . V_327 = & V_727 ;
V_216 = F_408 ( & V_728 , V_722 , V_723 , V_724 , V_725 ) ;
if ( V_722 )
V_216 = F_92 ( V_721 , V_726 , V_727 ) ;
if ( V_216 )
* V_725 = V_508 ;
return V_216 ;
}
static
int F_409 ( struct V_148 * V_721 , int V_722 ,
void T_6 * V_723 , T_14 * V_724 , T_8 * V_725 )
{
struct V_148 V_728 ;
int V_729 = 1 , V_730 = 255 ;
V_728 = * V_721 ;
V_728 . V_153 = & V_729 ;
V_728 . V_152 = & V_730 ;
return F_410 ( & V_728 , V_722 , V_723 , V_724 , V_725 ) ;
}
static
int F_411 ( struct V_148 * V_721 , int V_722 ,
void T_6 * V_723 , T_14 * V_724 , T_8 * V_725 )
{
struct V_4 * V_5 = V_721 -> V_153 ;
int V_731 = V_34 ;
struct V_148 V_728 ;
V_728 = * V_721 ;
V_728 . V_153 = & V_731 ;
V_728 . V_152 = V_5 ? & V_5 -> V_7 -> V_33 : NULL ;
return F_410 ( & V_728 , V_722 , V_723 , V_724 , V_725 ) ;
}
static void F_412 ( struct V_4 * V_5 )
{
struct V_732 V_463 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_413 ( & V_463 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_179 )
F_294 ( NULL , V_207 , & V_463 ) ;
else
F_294 ( NULL , V_190 , & V_463 ) ;
}
static void F_414 ( struct V_109 * V_109 , T_2 V_146 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_79 () ;
F_181 (net, dev) {
V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
int V_147 = ( ! V_5 -> V_39 . V_179 ) ^ ( ! V_146 ) ;
V_5 -> V_39 . V_179 = V_146 ;
if ( V_147 )
F_412 ( V_5 ) ;
}
}
F_82 () ;
}
static int F_415 ( struct V_148 * V_149 , int * V_150 , int V_146 )
{
struct V_109 * V_109 ;
int V_151 ;
if ( ! F_93 () )
return F_94 () ;
V_109 = (struct V_109 * ) V_149 -> V_152 ;
V_151 = * V_150 ;
* V_150 = V_146 ;
if ( V_150 == & V_109 -> V_18 . V_40 -> V_179 ) {
F_95 () ;
return 0 ;
}
if ( V_150 == & V_109 -> V_18 . V_123 -> V_179 ) {
V_109 -> V_18 . V_40 -> V_179 = V_146 ;
F_414 ( V_109 , V_146 ) ;
} else if ( ( ! V_146 ) ^ ( ! V_151 ) )
F_412 ( (struct V_4 * ) V_149 -> V_153 ) ;
F_95 () ;
return 0 ;
}
static
int F_416 ( struct V_148 * V_721 , int V_722 ,
void T_6 * V_723 , T_14 * V_724 , T_8 * V_725 )
{
int * V_726 = V_721 -> V_327 ;
int V_727 = * V_726 ;
T_8 V_508 = * V_725 ;
struct V_148 V_728 ;
int V_216 ;
V_728 = * V_721 ;
V_728 . V_327 = & V_727 ;
V_216 = F_408 ( & V_728 , V_722 , V_723 , V_724 , V_725 ) ;
if ( V_722 )
V_216 = F_415 ( V_721 , V_726 , V_727 ) ;
if ( V_216 )
* V_725 = V_508 ;
return V_216 ;
}
static
int F_417 ( struct V_148 * V_721 , int V_722 ,
void T_6 * V_723 , T_14 * V_724 , T_8 * V_725 )
{
int * V_726 = V_721 -> V_327 ;
int V_216 ;
int V_151 , V_733 ;
V_151 = * V_726 ;
V_216 = F_408 ( V_721 , V_722 , V_723 , V_724 , V_725 ) ;
V_733 = * V_726 ;
if ( V_722 && V_151 != V_733 ) {
struct V_109 * V_109 = V_721 -> V_152 ;
if ( ! F_93 () )
return F_94 () ;
if ( V_726 == & V_109 -> V_18 . V_40 -> V_107 )
F_65 ( V_109 , V_88 ,
V_124 ,
V_109 -> V_18 . V_40 ) ;
else if ( V_726 == & V_109 -> V_18 . V_123 -> V_107 )
F_65 ( V_109 , V_88 ,
V_122 ,
V_109 -> V_18 . V_123 ) ;
else {
struct V_4 * V_5 = V_721 -> V_153 ;
F_65 ( V_109 , V_88 ,
V_5 -> V_7 -> V_92 ,
& V_5 -> V_39 ) ;
}
F_95 () ;
}
return V_216 ;
}
static int F_418 ( struct V_148 * V_721 , int V_722 ,
void T_6 * V_723 , T_14 * V_724 ,
T_8 * V_725 )
{
int V_32 ;
struct V_163 V_161 ;
char V_734 [ V_735 ] ;
struct V_148 V_728 = * V_721 ;
struct V_109 * V_109 = V_721 -> V_152 ;
struct V_454 * V_449 = V_721 -> V_327 ;
if ( & V_109 -> V_18 . V_123 -> V_41 == V_721 -> V_327 )
return - V_736 ;
V_728 . V_737 = V_735 ;
V_728 . V_327 = V_734 ;
if ( ! F_93 () )
return F_94 () ;
if ( ! V_722 && ! V_449 -> V_42 ) {
V_32 = - V_736 ;
goto V_183;
}
V_32 = snprintf ( V_734 , sizeof( V_734 ) , L_30 , & V_449 -> V_449 ) ;
if ( V_32 >= sizeof( V_734 ) ) {
V_32 = - V_736 ;
goto V_183;
}
V_32 = F_419 ( & V_728 , V_722 , V_723 , V_724 , V_725 ) ;
if ( V_32 || ! V_722 )
goto V_183;
if ( F_420 ( V_734 , - 1 , V_161 . V_738 . V_739 , - 1 , NULL ) != 1 ) {
V_32 = - V_736 ;
goto V_183;
}
V_449 -> V_42 = true ;
V_449 -> V_449 = V_161 ;
if ( & V_109 -> V_18 . V_40 -> V_41 == V_721 -> V_327 ) {
struct V_6 * V_7 ;
F_91 (net, dev) {
struct V_4 * V_5 = F_52 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_43 =
V_44 ;
}
}
} else {
struct V_4 * V_5 = V_721 -> V_153 ;
V_5 -> V_43 = V_44 ;
}
V_183:
F_95 () ;
return V_32 ;
}
static
int F_421 ( struct V_148 * V_721 ,
int V_722 ,
void T_6 * V_723 ,
T_14 * V_724 ,
T_8 * V_725 )
{
int * V_726 = V_721 -> V_327 ;
int V_727 = * V_726 ;
T_8 V_508 = * V_725 ;
struct V_148 V_728 ;
int V_216 ;
V_728 = * V_721 ;
V_728 . V_327 = & V_727 ;
V_216 = F_408 ( & V_728 , V_722 , V_723 , V_724 , V_725 ) ;
if ( V_722 )
V_216 = F_98 ( V_721 , V_726 , V_727 ) ;
if ( V_216 )
* V_725 = V_508 ;
return V_216 ;
}
static int F_422 ( struct V_109 * V_109 , char * V_740 ,
struct V_4 * V_5 , struct V_93 * V_150 )
{
int V_16 ;
struct V_148 * V_149 ;
char V_741 [ sizeof( L_31 ) + V_654 ] ;
V_149 = F_423 ( V_742 , sizeof( V_742 ) , V_25 ) ;
if ( ! V_149 )
goto V_183;
for ( V_16 = 0 ; V_149 [ V_16 ] . V_327 ; V_16 ++ ) {
V_149 [ V_16 ] . V_327 += ( char * ) V_150 - ( char * ) & V_93 ;
V_149 [ V_16 ] . V_153 = V_5 ;
V_149 [ V_16 ] . V_152 = V_109 ;
}
snprintf ( V_741 , sizeof( V_741 ) , L_32 , V_740 ) ;
V_150 -> V_743 = F_424 ( V_109 , V_741 , V_149 ) ;
if ( ! V_150 -> V_743 )
goto free;
return 0 ;
free:
F_26 ( V_149 ) ;
V_183:
return - V_110 ;
}
static void F_425 ( struct V_93 * V_150 )
{
struct V_148 * V_149 ;
if ( ! V_150 -> V_743 )
return;
V_149 = V_150 -> V_743 -> V_744 ;
F_426 ( V_150 -> V_743 ) ;
V_150 -> V_743 = NULL ;
F_26 ( V_149 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
int V_32 ;
if ( ! F_427 ( V_5 -> V_7 -> V_52 ) )
return - V_35 ;
V_32 = F_428 ( V_5 -> V_7 , V_5 -> V_47 ,
& V_745 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_422 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_52 ,
V_5 , & V_5 -> V_39 ) ;
if ( V_32 )
F_429 ( V_5 -> V_47 ) ;
return V_32 ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_425 ( & V_5 -> V_39 ) ;
F_429 ( V_5 -> V_47 ) ;
}
static int T_10 F_430 ( struct V_109 * V_109 )
{
int V_32 = - V_30 ;
struct V_93 * V_84 , * V_746 ;
V_84 = F_423 ( & V_93 , sizeof( V_93 ) , V_25 ) ;
if ( ! V_84 )
goto V_747;
V_746 = F_423 ( & V_748 , sizeof( V_748 ) , V_25 ) ;
if ( ! V_746 )
goto V_749;
V_746 -> V_375 = V_750 . V_375 ;
V_746 -> V_179 = V_750 . V_179 ;
V_746 -> V_41 . V_42 = false ;
V_84 -> V_41 . V_42 = false ;
V_109 -> V_18 . V_123 = V_84 ;
V_109 -> V_18 . V_40 = V_746 ;
#ifdef F_431
V_32 = F_422 ( V_109 , L_33 , NULL , V_84 ) ;
if ( V_32 < 0 )
goto V_751;
V_32 = F_422 ( V_109 , L_34 , NULL , V_746 ) ;
if ( V_32 < 0 )
goto V_752;
#endif
return 0 ;
#ifdef F_431
V_752:
F_425 ( V_84 ) ;
V_751:
F_26 ( V_746 ) ;
#endif
V_749:
F_26 ( V_84 ) ;
V_747:
return V_32 ;
}
static void T_11 F_432 ( struct V_109 * V_109 )
{
#ifdef F_431
F_425 ( V_109 -> V_18 . V_40 ) ;
F_425 ( V_109 -> V_18 . V_123 ) ;
#endif
F_26 ( V_109 -> V_18 . V_40 ) ;
F_26 ( V_109 -> V_18 . V_123 ) ;
}
int T_12 F_433 ( void )
{
struct V_4 * V_5 ;
int V_16 , V_32 ;
V_32 = F_434 () ;
if ( V_32 < 0 ) {
F_435 ( L_35 ,
V_51 , V_32 ) ;
goto V_183;
}
V_32 = F_340 ( & V_753 ) ;
if ( V_32 < 0 )
goto V_754;
V_15 = F_436 ( L_36 ) ;
if ( ! V_15 ) {
V_32 = - V_30 ;
goto V_755;
}
F_256 () ;
V_5 = F_28 ( V_756 . V_757 ) ;
F_95 () ;
if ( F_53 ( V_5 ) ) {
V_32 = F_122 ( V_5 ) ;
goto V_758;
}
for ( V_16 = 0 ; V_16 < V_484 ; V_16 ++ )
F_437 ( & V_187 [ V_16 ] ) ;
F_438 ( & V_759 ) ;
F_253 () ;
F_439 ( & V_760 ) ;
V_32 = F_440 ( V_761 , V_762 , NULL , F_402 ,
NULL ) ;
if ( V_32 < 0 )
goto V_112;
F_440 ( V_761 , V_424 , F_352 , NULL , NULL ) ;
F_440 ( V_761 , V_206 , F_349 , NULL , NULL ) ;
F_440 ( V_761 , V_763 , F_368 ,
F_365 , NULL ) ;
F_440 ( V_761 , V_577 , NULL ,
F_366 , NULL ) ;
F_440 ( V_761 , V_581 , NULL ,
F_367 , NULL ) ;
F_440 ( V_761 , V_764 , F_71 ,
F_78 , NULL ) ;
F_441 () ;
return 0 ;
V_112:
F_442 ( & V_760 ) ;
F_443 ( & V_759 ) ;
V_758:
F_444 ( V_15 ) ;
V_755:
F_342 ( & V_753 ) ;
V_754:
F_445 () ;
V_183:
return V_32 ;
}
void F_446 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_443 ( & V_759 ) ;
F_342 ( & V_753 ) ;
F_445 () ;
F_256 () ;
F_447 ( & V_760 ) ;
F_91 (&init_net, dev) {
if ( F_52 ( V_7 ) == NULL )
continue;
F_297 ( V_7 , 1 ) ;
}
F_297 ( V_756 . V_757 , 2 ) ;
F_144 ( & V_181 ) ;
for ( V_16 = 0 ; V_16 < V_484 ; V_16 ++ )
F_67 ( ! F_448 ( & V_187 [ V_16 ] ) ) ;
F_145 ( & V_181 ) ;
F_10 ( & V_525 ) ;
F_95 () ;
F_444 ( V_15 ) ;
}
