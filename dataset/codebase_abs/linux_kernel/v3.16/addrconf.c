static inline T_1 F_1 ( unsigned long V_1 )
{
return ( V_1 - V_2 ) * 100UL / V_3 ;
}
static inline void F_2 ( struct V_4 * V_5 )
{
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
F_29 () ;
if ( V_7 -> V_32 < V_33 )
return NULL ;
V_31 = F_25 ( sizeof( struct V_4 ) , V_25 ) ;
if ( V_31 == NULL )
return NULL ;
F_30 ( & V_31 -> V_34 ) ;
V_31 -> V_7 = V_7 ;
F_31 ( & V_31 -> V_35 ) ;
F_32 ( & V_31 -> V_8 , V_36 ,
( unsigned long ) V_31 ) ;
memcpy ( & V_31 -> V_37 , F_33 ( V_7 ) -> V_18 . V_38 , sizeof( V_31 -> V_37 ) ) ;
V_31 -> V_37 . V_39 = V_7 -> V_32 ;
V_31 -> V_37 . V_40 = NULL ;
V_31 -> V_41 = F_34 ( V_7 , & V_42 ) ;
if ( V_31 -> V_41 == NULL ) {
F_26 ( V_31 ) ;
return NULL ;
}
if ( V_31 -> V_37 . V_43 )
F_35 ( V_7 ) ;
F_36 ( V_7 ) ;
if ( F_20 ( V_31 ) < 0 ) {
F_37 ( V_44
L_1 ,
V_45 , V_7 -> V_46 ) ;
F_38 ( & V_42 , V_31 -> V_41 ) ;
F_39 ( V_7 ) ;
F_26 ( V_31 ) ;
return NULL ;
}
if ( F_40 ( V_31 ) < 0 ) {
F_37 ( V_44
L_2 ,
V_45 , V_7 -> V_46 ) ;
F_38 ( & V_42 , V_31 -> V_41 ) ;
V_31 -> V_47 = 1 ;
F_41 ( V_31 ) ;
return NULL ;
}
F_14 ( V_31 ) ;
if ( V_7 -> V_48 & ( V_49 | V_50 ) )
V_31 -> V_37 . V_51 = - 1 ;
#if F_42 ( V_52 )
if ( V_7 -> type == V_53 && ( V_7 -> V_54 & V_55 ) ) {
F_43 ( L_3 , V_7 -> V_46 ) ;
V_31 -> V_37 . V_56 = 0 ;
}
#endif
F_31 ( & V_31 -> V_57 ) ;
F_32 ( & V_31 -> V_58 , V_59 , ( unsigned long ) V_31 ) ;
if ( ( V_7 -> V_48 & V_50 ) ||
V_7 -> type == V_60 ||
V_7 -> type == V_61 ||
V_7 -> type == V_53 ||
V_7 -> type == V_62 ) {
V_31 -> V_37 . V_63 = - 1 ;
} else {
F_14 ( V_31 ) ;
V_59 ( ( unsigned long ) V_31 ) ;
}
V_31 -> V_64 = V_65 ;
if ( F_44 ( V_7 ) && F_4 ( V_7 ) )
V_31 -> V_66 |= V_67 ;
F_45 ( V_31 ) ;
V_31 -> V_68 = V_13 ;
F_2 ( V_31 ) ;
F_46 ( V_7 -> V_69 , V_31 ) ;
F_47 ( V_7 , & V_70 ) ;
F_47 ( V_7 , & V_71 ) ;
if ( V_31 -> V_37 . V_43 && ( V_7 -> V_48 & V_72 ) )
F_47 ( V_7 , & V_73 ) ;
return V_31 ;
}
static struct V_4 * F_48 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! V_5 )
return NULL ;
}
if ( V_7 -> V_48 & V_74 )
F_50 ( V_5 ) ;
return V_5 ;
}
static int F_51 ( int type )
{
int V_75 = F_52 ( sizeof( struct V_76 ) )
+ F_53 ( 4 ) ;
if ( type == - 1 || type == V_77 )
V_75 += F_53 ( 4 ) ;
#ifdef F_54
if ( type == - 1 || type == V_78 )
V_75 += F_53 ( 4 ) ;
#endif
if ( type == - 1 || type == V_79 )
V_75 += F_53 ( 4 ) ;
return V_75 ;
}
static int F_55 ( struct V_80 * V_81 , int V_82 ,
struct V_83 * V_84 , T_1 V_85 ,
T_1 V_86 , int V_87 , unsigned int V_48 ,
int type )
{
struct V_88 * V_89 ;
struct V_76 * V_90 ;
V_89 = F_56 ( V_81 , V_85 , V_86 , V_87 , sizeof( struct V_76 ) ,
V_48 ) ;
if ( V_89 == NULL )
return - V_91 ;
V_90 = F_57 ( V_89 ) ;
V_90 -> V_92 = V_93 ;
if ( F_58 ( V_81 , V_94 , V_82 ) < 0 )
goto V_95;
if ( ( type == - 1 || type == V_77 ) &&
F_58 ( V_81 , V_77 , V_84 -> V_43 ) < 0 )
goto V_95;
#ifdef F_54
if ( ( type == - 1 || type == V_78 ) &&
F_58 ( V_81 , V_78 ,
V_84 -> V_96 ) < 0 )
goto V_95;
#endif
if ( ( type == - 1 || type == V_79 ) &&
F_58 ( V_81 , V_79 , V_84 -> V_97 ) < 0 )
goto V_95;
return F_59 ( V_81 , V_89 ) ;
V_95:
F_60 ( V_81 , V_89 ) ;
return - V_91 ;
}
void F_61 ( struct V_98 * V_98 , int type , int V_82 ,
struct V_83 * V_84 )
{
struct V_80 * V_81 ;
int V_99 = - V_100 ;
V_81 = F_62 ( F_51 ( type ) , V_101 ) ;
if ( V_81 == NULL )
goto V_102;
V_99 = F_55 ( V_81 , V_82 , V_84 , 0 , 0 ,
V_103 , 0 , type ) ;
if ( V_99 < 0 ) {
F_63 ( V_99 == - V_91 ) ;
F_64 ( V_81 ) ;
goto V_102;
}
F_65 ( V_81 , V_98 , 0 , V_104 , NULL , V_101 ) ;
return;
V_102:
F_66 ( V_98 , V_104 , V_99 ) ;
}
static int F_67 ( struct V_80 * V_105 ,
struct V_88 * V_89 )
{
struct V_98 * V_98 = F_68 ( V_105 -> V_106 ) ;
struct V_107 * V_108 [ V_109 + 1 ] ;
struct V_76 * V_90 ;
struct V_80 * V_81 ;
struct V_83 * V_84 ;
struct V_4 * V_110 ;
struct V_6 * V_7 ;
int V_82 ;
int V_99 ;
V_99 = F_69 ( V_89 , sizeof( * V_90 ) , V_108 , V_109 ,
V_111 ) ;
if ( V_99 < 0 )
goto V_102;
V_99 = V_112 ;
if ( ! V_108 [ V_94 ] )
goto V_102;
V_82 = F_70 ( V_108 [ V_94 ] ) ;
switch ( V_82 ) {
case V_113 :
V_84 = V_98 -> V_18 . V_114 ;
break;
case V_115 :
V_84 = V_98 -> V_18 . V_38 ;
break;
default:
V_7 = F_71 ( V_98 , V_82 ) ;
if ( V_7 == NULL )
goto V_102;
V_110 = F_49 ( V_7 ) ;
if ( V_110 == NULL )
goto V_102;
V_84 = & V_110 -> V_37 ;
break;
}
V_99 = - V_100 ;
V_81 = F_62 ( F_51 ( - 1 ) , V_101 ) ;
if ( V_81 == NULL )
goto V_102;
V_99 = F_55 ( V_81 , V_82 , V_84 ,
F_72 ( V_105 ) . V_85 ,
V_89 -> V_116 , V_103 , 0 ,
- 1 ) ;
if ( V_99 < 0 ) {
F_63 ( V_99 == - V_91 ) ;
F_64 ( V_81 ) ;
goto V_102;
}
V_99 = F_73 ( V_81 , V_98 , F_72 ( V_105 ) . V_85 ) ;
V_102:
return V_99 ;
}
static int F_74 ( struct V_80 * V_81 ,
struct V_117 * V_118 )
{
struct V_98 * V_98 = F_68 ( V_81 -> V_106 ) ;
int V_119 , V_120 ;
int V_121 , V_122 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_123 * V_124 ;
V_120 = V_118 -> args [ 0 ] ;
V_122 = V_121 = V_118 -> args [ 1 ] ;
for ( V_119 = V_120 ; V_119 < V_125 ; V_119 ++ , V_122 = 0 ) {
V_121 = 0 ;
V_124 = & V_98 -> V_126 [ V_119 ] ;
F_75 () ;
V_118 -> V_86 = F_76 ( & V_98 -> V_18 . V_127 ) ^
V_98 -> V_128 ;
F_77 (dev, head, index_hlist) {
if ( V_121 < V_122 )
goto V_129;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
goto V_129;
if ( F_55 ( V_81 , V_7 -> V_82 ,
& V_5 -> V_37 ,
F_72 ( V_118 -> V_81 ) . V_85 ,
V_118 -> V_89 -> V_116 ,
V_103 ,
V_130 ,
- 1 ) <= 0 ) {
F_78 () ;
goto V_131;
}
F_79 ( V_118 , F_80 ( V_81 ) ) ;
V_129:
V_121 ++ ;
}
F_78 () ;
}
if ( V_119 == V_125 ) {
if ( F_55 ( V_81 , V_113 ,
V_98 -> V_18 . V_114 ,
F_72 ( V_118 -> V_81 ) . V_85 ,
V_118 -> V_89 -> V_116 ,
V_103 , V_130 ,
- 1 ) <= 0 )
goto V_131;
else
V_119 ++ ;
}
if ( V_119 == V_125 + 1 ) {
if ( F_55 ( V_81 , V_115 ,
V_98 -> V_18 . V_38 ,
F_72 ( V_118 -> V_81 ) . V_85 ,
V_118 -> V_89 -> V_116 ,
V_103 , V_130 ,
- 1 ) <= 0 )
goto V_131;
else
V_119 ++ ;
}
V_131:
V_118 -> args [ 0 ] = V_119 ;
V_118 -> args [ 1 ] = V_121 ;
return V_81 -> V_132 ;
}
static void F_81 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_133 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_37 . V_43 )
F_35 ( V_7 ) ;
if ( V_7 -> V_48 & V_72 ) {
if ( V_5 -> V_37 . V_43 ) {
F_47 ( V_7 , & V_73 ) ;
F_47 ( V_7 , & V_134 ) ;
F_47 ( V_7 , & V_135 ) ;
} else {
F_82 ( V_7 , & V_73 ) ;
F_82 ( V_7 , & V_134 ) ;
F_82 ( V_7 , & V_135 ) ;
}
}
F_83 (ifa, &idev->addr_list, if_list) {
if ( V_133 -> V_48 & V_136 )
continue;
if ( V_5 -> V_37 . V_43 )
F_84 ( V_133 ) ;
else
F_85 ( V_133 ) ;
}
F_61 ( F_33 ( V_7 ) , V_77 ,
V_7 -> V_82 , & V_5 -> V_37 ) ;
}
static void F_86 ( struct V_98 * V_98 , T_2 V_137 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_87 (net, dev) {
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
int V_138 = ( ! V_5 -> V_37 . V_43 ) ^ ( ! V_137 ) ;
V_5 -> V_37 . V_43 = V_137 ;
if ( V_138 )
F_81 ( V_5 ) ;
}
}
}
static int F_88 ( struct V_139 * V_140 , int * V_141 , int V_137 )
{
struct V_98 * V_98 ;
int V_142 ;
if ( ! F_89 () )
return F_90 () ;
V_98 = (struct V_98 * ) V_140 -> V_143 ;
V_142 = * V_141 ;
* V_141 = V_137 ;
if ( V_141 == & V_98 -> V_18 . V_38 -> V_43 ) {
if ( ( ! V_137 ) ^ ( ! V_142 ) )
F_61 ( V_98 , V_77 ,
V_115 ,
V_98 -> V_18 . V_38 ) ;
F_91 () ;
return 0 ;
}
if ( V_141 == & V_98 -> V_18 . V_114 -> V_43 ) {
V_98 -> V_18 . V_38 -> V_43 = V_137 ;
F_86 ( V_98 , V_137 ) ;
if ( ( ! V_137 ) ^ ( ! V_142 ) )
F_61 ( V_98 , V_77 ,
V_113 ,
V_98 -> V_18 . V_114 ) ;
} else if ( ( ! V_137 ) ^ ( ! V_142 ) )
F_81 ( (struct V_4 * ) V_140 -> V_144 ) ;
F_91 () ;
if ( V_137 )
F_92 ( V_98 ) ;
return 1 ;
}
void F_93 ( struct V_9 * V_10 )
{
F_63 ( ! F_94 ( & V_10 -> V_145 ) ) ;
#ifdef F_95
F_96 ( L_4 , V_45 ) ;
#endif
F_97 ( V_10 -> V_5 ) ;
if ( F_10 ( & V_10 -> V_11 ) )
F_98 ( L_5 ,
V_10 ) ;
if ( V_10 -> V_146 != V_147 ) {
F_99 ( L_6 , V_10 ) ;
return;
}
F_100 ( V_10 -> V_148 ) ;
F_101 ( V_10 , V_149 ) ;
}
static void
F_102 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_150 * V_141 ;
int V_151 = F_103 ( & V_10 -> V_152 ) ;
F_104 (p, &idev->addr_list) {
struct V_9 * V_133
= F_105 ( V_141 , struct V_9 , V_153 ) ;
if ( V_151 >= F_103 ( & V_133 -> V_152 ) )
break;
}
F_106 ( & V_10 -> V_153 , V_141 ) ;
}
static T_1 F_107 ( const struct V_154 * V_152 )
{
return F_108 ( F_109 ( V_152 ) , V_155 ) ;
}
static struct V_9 *
F_110 ( struct V_4 * V_5 , const struct V_154 * V_152 ,
const struct V_154 * V_156 , int V_157 ,
int V_158 , T_1 V_48 , T_1 V_159 , T_1 V_160 )
{
struct V_9 * V_133 = NULL ;
struct V_161 * V_148 ;
unsigned int V_162 ;
int V_99 = 0 ;
int V_163 = F_111 ( V_152 ) ;
if ( V_163 == V_164 ||
V_163 & V_165 ||
( ! ( V_5 -> V_7 -> V_48 & V_50 ) &&
V_163 & V_166 ) )
return F_112 ( - V_167 ) ;
F_113 () ;
if ( V_5 -> V_47 ) {
V_99 = - V_168 ;
goto V_169;
}
if ( V_5 -> V_37 . V_170 ) {
V_99 = - V_171 ;
goto V_169;
}
F_114 ( & V_172 ) ;
if ( F_115 ( F_33 ( V_5 -> V_7 ) , V_152 , V_5 -> V_7 ) ) {
F_37 ( L_7 ) ;
V_99 = - V_173 ;
goto V_174;
}
V_133 = F_25 ( sizeof( struct V_9 ) , V_101 ) ;
if ( V_133 == NULL ) {
F_37 ( L_8 ) ;
V_99 = - V_100 ;
goto V_174;
}
V_148 = F_116 ( V_5 , V_152 , false ) ;
if ( F_117 ( V_148 ) ) {
V_99 = F_118 ( V_148 ) ;
goto V_174;
}
F_119 ( V_5 -> V_41 ) ;
V_133 -> V_152 = * V_152 ;
if ( V_156 )
V_133 -> V_156 = * V_156 ;
F_120 ( & V_133 -> V_34 ) ;
F_120 ( & V_133 -> V_175 ) ;
F_121 ( & V_133 -> V_11 , V_176 ) ;
F_122 ( & V_133 -> V_145 ) ;
V_133 -> V_158 = V_158 ;
V_133 -> V_177 = V_157 ;
V_133 -> V_48 = V_48 | V_136 ;
V_133 -> V_159 = V_159 ;
V_133 -> V_160 = V_160 ;
V_133 -> V_1 = V_133 -> V_68 = V_13 ;
V_133 -> V_178 = false ;
V_133 -> V_148 = V_148 ;
V_133 -> V_5 = V_5 ;
F_14 ( V_5 ) ;
F_18 ( V_133 ) ;
V_162 = F_107 ( V_152 ) ;
F_123 ( & V_133 -> V_145 , & V_179 [ V_162 ] ) ;
F_124 ( & V_172 ) ;
F_125 ( & V_5 -> V_34 ) ;
F_102 ( V_5 , V_133 ) ;
if ( V_133 -> V_48 & V_180 ) {
F_126 ( & V_133 -> V_181 , & V_5 -> V_57 ) ;
F_18 ( V_133 ) ;
}
F_18 ( V_133 ) ;
F_127 ( & V_5 -> V_34 ) ;
V_169:
F_128 () ;
if ( F_129 ( V_99 == 0 ) )
F_130 ( V_182 , V_133 ) ;
else {
F_26 ( V_133 ) ;
V_133 = F_112 ( V_99 ) ;
}
return V_133 ;
V_174:
F_124 ( & V_172 ) ;
goto V_169;
}
static enum V_183
F_131 ( struct V_9 * V_10 , unsigned long * V_184 )
{
struct V_9 * V_133 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_185 ;
enum V_183 V_186 = V_187 ;
* V_184 = V_13 ;
F_83 (ifa, &idev->addr_list, if_list) {
if ( V_133 == V_10 )
continue;
if ( ! F_132 ( & V_133 -> V_152 , & V_10 -> V_152 ,
V_10 -> V_177 ) )
continue;
if ( V_133 -> V_48 & ( V_188 | V_189 ) )
return V_190 ;
V_186 = V_191 ;
F_114 ( & V_133 -> V_34 ) ;
V_185 = F_133 ( V_133 -> V_159 , V_3 ) ;
if ( F_134 ( * V_184 , V_133 -> V_68 + V_185 * V_3 ) )
* V_184 = V_133 -> V_68 + V_185 * V_3 ;
F_124 ( & V_133 -> V_34 ) ;
}
return V_186 ;
}
static void
F_135 ( struct V_9 * V_10 , unsigned long V_184 , bool V_192 )
{
struct V_161 * V_148 ;
V_148 = F_136 ( & V_10 -> V_152 ,
V_10 -> V_177 ,
V_10 -> V_5 -> V_7 ,
0 , V_193 | V_194 ) ;
if ( V_148 ) {
if ( V_192 )
F_137 ( V_148 ) ;
else {
if ( ! ( V_148 -> V_195 & V_196 ) )
F_138 ( V_148 , V_184 ) ;
F_100 ( V_148 ) ;
}
}
}
static void F_139 ( struct V_9 * V_10 )
{
int V_146 ;
enum V_183 V_186 = V_190 ;
unsigned long V_184 ;
F_29 () ;
F_140 ( & V_10 -> V_175 ) ;
V_146 = V_10 -> V_146 ;
V_10 -> V_146 = V_147 ;
F_141 ( & V_10 -> V_175 ) ;
if ( V_146 == V_147 )
goto V_174;
F_140 ( & V_172 ) ;
F_142 ( & V_10 -> V_145 ) ;
F_141 ( & V_172 ) ;
F_143 ( & V_10 -> V_5 -> V_34 ) ;
if ( V_10 -> V_48 & V_180 ) {
F_144 ( & V_10 -> V_181 ) ;
if ( V_10 -> V_197 ) {
F_145 ( V_10 -> V_197 ) ;
V_10 -> V_197 = NULL ;
}
F_11 ( V_10 ) ;
}
if ( V_10 -> V_48 & V_188 && ! ( V_10 -> V_48 & V_189 ) )
V_186 = F_131 ( V_10 , & V_184 ) ;
F_146 ( & V_10 -> V_153 ) ;
F_11 ( V_10 ) ;
F_147 ( & V_10 -> V_5 -> V_34 ) ;
F_9 ( V_10 ) ;
F_148 ( V_198 , V_10 ) ;
F_130 ( V_199 , V_10 ) ;
if ( V_186 != V_190 ) {
F_135 ( V_10 , V_184 ,
V_186 == V_187 ) ;
}
F_149 ( V_10 ) ;
V_174:
F_145 ( V_10 ) ;
}
static int F_150 ( struct V_9 * V_10 , struct V_9 * V_200 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_154 V_152 , * V_201 ;
unsigned long V_202 , V_203 , V_204 , V_205 ;
unsigned long V_206 ;
int V_207 ;
int V_208 = 0 ;
T_1 V_209 ;
unsigned long V_210 = V_13 ;
F_143 ( & V_5 -> V_34 ) ;
if ( V_200 ) {
F_140 ( & V_200 -> V_34 ) ;
memcpy ( & V_152 . V_211 [ 8 ] , & V_200 -> V_152 . V_211 [ 8 ] , 8 ) ;
F_141 ( & V_200 -> V_34 ) ;
V_201 = & V_152 ;
} else {
V_201 = NULL ;
}
V_212:
F_14 ( V_5 ) ;
if ( V_5 -> V_37 . V_63 <= 0 ) {
F_147 ( & V_5 -> V_34 ) ;
F_43 ( L_9 , V_45 ) ;
F_97 ( V_5 ) ;
V_208 = - 1 ;
goto V_174;
}
F_140 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_213 ++ >= V_5 -> V_37 . V_214 ) {
V_5 -> V_37 . V_63 = - 1 ;
F_141 ( & V_10 -> V_34 ) ;
F_147 ( & V_5 -> V_34 ) ;
F_99 ( L_10 ,
V_45 ) ;
F_97 ( V_5 ) ;
V_208 = - 1 ;
goto V_174;
}
F_18 ( V_10 ) ;
memcpy ( V_152 . V_211 , V_10 -> V_152 . V_211 , 8 ) ;
F_151 ( V_5 , V_201 ) ;
memcpy ( & V_152 . V_211 [ 8 ] , V_5 -> V_215 , 8 ) ;
V_205 = ( V_210 - V_10 -> V_68 ) / V_3 ;
V_203 = F_152 ( V_216 ,
V_10 -> V_159 ,
V_5 -> V_37 . V_217 + V_205 ) ;
V_202 = F_152 ( V_216 ,
V_10 -> V_160 ,
V_5 -> V_37 . V_218 + V_205 -
V_5 -> V_37 . V_219 ) ;
V_207 = V_10 -> V_177 ;
V_204 = V_10 -> V_68 ;
F_141 ( & V_10 -> V_34 ) ;
V_206 = V_5 -> V_37 . V_214 *
V_5 -> V_37 . V_220 *
F_153 ( V_5 -> V_41 , V_221 ) / V_3 ;
F_147 ( & V_5 -> V_34 ) ;
V_205 = ( V_210 - V_204 + V_222 ) / V_3 ;
if ( V_202 <= V_206 + V_205 ) {
F_145 ( V_10 ) ;
F_97 ( V_5 ) ;
V_208 = - 1 ;
goto V_174;
}
V_209 = V_180 ;
if ( V_10 -> V_48 & V_223 )
V_209 |= V_223 ;
V_200 = F_110 ( V_5 , & V_152 , NULL , V_207 ,
F_154 ( & V_152 ) , V_209 ,
V_203 , V_202 ) ;
if ( F_117 ( V_200 ) ) {
F_145 ( V_10 ) ;
F_97 ( V_5 ) ;
F_43 ( L_11 , V_45 ) ;
V_201 = & V_152 ;
F_143 ( & V_5 -> V_34 ) ;
goto V_212;
}
F_140 ( & V_200 -> V_34 ) ;
V_200 -> V_197 = V_10 ;
V_200 -> V_1 = V_210 ;
V_200 -> V_68 = V_204 ;
F_141 ( & V_200 -> V_34 ) ;
F_155 ( V_200 ) ;
F_145 ( V_200 ) ;
F_97 ( V_5 ) ;
V_174:
return V_208 ;
}
static inline int F_156 ( int type )
{
if ( type & ( V_224 | V_225 | V_166 ) )
return 1 ;
return 0 ;
}
static int F_157 ( struct V_98 * V_98 ,
struct V_226 * V_227 ,
struct V_228 * V_229 ,
int V_16 )
{
int V_208 ;
if ( V_16 <= V_227 -> V_230 ) {
switch ( V_16 ) {
case V_231 :
V_208 = V_227 -> V_232 ;
break;
case V_233 :
V_208 = V_227 -> V_234 ;
break;
default:
V_208 = ! ! F_158 ( V_16 , V_227 -> V_235 ) ;
}
goto V_174;
}
switch ( V_16 ) {
case V_236 :
V_208 = ! ! V_227 -> V_133 ;
break;
case V_237 :
V_208 = F_159 ( & V_227 -> V_133 -> V_152 , V_229 -> V_152 ) ;
break;
case V_231 :
V_208 = F_160 ( V_227 -> V_163 ) ;
if ( V_208 >= V_229 -> V_158 )
V_208 = - V_208 ;
else
V_208 -= 128 ;
V_227 -> V_232 = V_208 ;
break;
case V_238 :
V_208 = F_156 ( V_227 -> V_163 ) ||
! ( V_227 -> V_133 -> V_48 & ( V_239 | V_223 ) ) ;
break;
#ifdef F_161
case V_240 :
{
int V_241 = ! ( V_229 -> V_242 & V_243 ) ;
V_208 = ! ( V_227 -> V_133 -> V_48 & V_244 ) ^ V_241 ;
break;
}
#endif
case V_245 :
V_208 = ( ! V_229 -> V_82 ||
V_229 -> V_82 == V_227 -> V_133 -> V_5 -> V_7 -> V_82 ) ;
break;
case V_246 :
V_208 = F_162 ( V_98 ,
& V_227 -> V_133 -> V_152 , V_227 -> V_163 ,
V_227 -> V_133 -> V_5 -> V_7 -> V_82 ) == V_229 -> V_247 ;
break;
case V_248 :
{
int V_249 = V_229 -> V_242 & ( V_250 | V_251 ) ?
! ! ( V_229 -> V_242 & V_251 ) :
V_227 -> V_133 -> V_5 -> V_37 . V_63 >= 2 ;
V_208 = ( ! ( V_227 -> V_133 -> V_48 & V_180 ) ) ^ V_249 ;
break;
}
case V_252 :
V_208 = ! ( F_163 ( & V_227 -> V_133 -> V_152 ) ^
F_163 ( V_229 -> V_152 ) ) ;
break;
case V_233 :
V_208 = F_164 ( & V_227 -> V_133 -> V_152 , V_229 -> V_152 ) ;
if ( V_208 > V_227 -> V_133 -> V_177 )
V_208 = V_227 -> V_133 -> V_177 ;
V_227 -> V_234 = V_208 ;
break;
default:
V_208 = 0 ;
}
if ( V_208 )
F_165 ( V_16 , V_227 -> V_235 ) ;
V_227 -> V_230 = V_16 ;
V_174:
return V_208 ;
}
int F_166 ( struct V_98 * V_98 , const struct V_6 * V_253 ,
const struct V_154 * V_254 , unsigned int V_242 ,
struct V_154 * V_255 )
{
struct V_226 V_256 [ 2 ] ,
* V_227 = & V_256 [ 0 ] , * V_257 = & V_256 [ 1 ] ;
struct V_228 V_229 ;
struct V_6 * V_7 ;
int V_258 ;
V_258 = F_167 ( V_254 ) ;
V_229 . V_152 = V_254 ;
V_229 . V_82 = V_253 ? V_253 -> V_82 : 0 ;
V_229 . V_158 = F_160 ( V_258 ) ;
V_229 . V_247 = F_162 ( V_98 , V_254 , V_258 , V_229 . V_82 ) ;
V_229 . V_242 = V_242 ;
V_257 -> V_230 = - 1 ;
V_257 -> V_133 = NULL ;
F_75 () ;
F_168 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_258 & V_165 ) ||
V_229 . V_158 <= V_259 ) &&
V_229 . V_82 && V_7 -> V_82 != V_229 . V_82 )
continue;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
continue;
F_169 ( & V_5 -> V_34 ) ;
F_83 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_227 -> V_133 -> V_48 & V_136 ) &&
( ! ( V_227 -> V_133 -> V_48 & V_223 ) ) )
continue;
V_227 -> V_163 = F_167 ( & V_227 -> V_133 -> V_152 ) ;
if ( F_170 ( V_227 -> V_163 == V_164 ||
V_227 -> V_163 & V_165 ) ) {
F_171 ( V_260
L_12
L_13 ,
V_7 -> V_46 ) ;
continue;
}
V_227 -> V_230 = - 1 ;
F_172 ( V_227 -> V_235 , V_261 ) ;
for ( V_16 = 0 ; V_16 < V_261 ; V_16 ++ ) {
int V_262 , V_263 ;
V_262 = F_157 ( V_98 , V_257 , & V_229 , V_16 ) ;
V_263 = F_157 ( V_98 , V_227 , & V_229 , V_16 ) ;
if ( V_262 > V_263 ) {
if ( V_16 == V_231 &&
V_227 -> V_232 > 0 ) {
goto V_264;
}
break;
} else if ( V_262 < V_263 ) {
if ( V_257 -> V_133 )
F_145 ( V_257 -> V_133 ) ;
F_18 ( V_227 -> V_133 ) ;
F_173 ( V_257 , V_227 ) ;
V_227 -> V_133 = V_257 -> V_133 ;
break;
}
}
}
V_264:
F_174 ( & V_5 -> V_34 ) ;
}
F_78 () ;
if ( ! V_257 -> V_133 )
return - V_167 ;
* V_255 = V_257 -> V_133 -> V_152 ;
F_145 ( V_257 -> V_133 ) ;
return 0 ;
}
int F_175 ( struct V_4 * V_5 , struct V_154 * V_152 ,
T_1 V_265 )
{
struct V_9 * V_10 ;
int V_99 = - V_167 ;
F_176 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_158 > V_266 )
break;
if ( V_10 -> V_158 == V_266 &&
! ( V_10 -> V_48 & V_265 ) ) {
* V_152 = V_10 -> V_152 ;
V_99 = 0 ;
break;
}
}
return V_99 ;
}
int F_177 ( struct V_6 * V_7 , struct V_154 * V_152 ,
T_1 V_265 )
{
struct V_4 * V_5 ;
int V_99 = - V_167 ;
F_75 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
F_169 ( & V_5 -> V_34 ) ;
V_99 = F_175 ( V_5 , V_152 , V_265 ) ;
F_174 ( & V_5 -> V_34 ) ;
}
F_78 () ;
return V_99 ;
}
static int F_178 ( struct V_4 * V_5 )
{
int V_267 = 0 ;
struct V_9 * V_10 ;
F_169 ( & V_5 -> V_34 ) ;
F_83 (ifp, &idev->addr_list, if_list)
V_267 ++ ;
F_174 ( & V_5 -> V_34 ) ;
return V_267 ;
}
int F_179 ( struct V_98 * V_98 , const struct V_154 * V_152 ,
const struct V_6 * V_7 , int V_268 )
{
struct V_9 * V_10 ;
unsigned int V_162 = F_107 ( V_152 ) ;
F_113 () ;
F_77 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_180 ( F_33 ( V_10 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( F_159 ( & V_10 -> V_152 , V_152 ) &&
! ( V_10 -> V_48 & V_136 ) &&
( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_158 & ( V_266 | V_269 ) || V_268 ) ) ) {
F_128 () ;
return 1 ;
}
}
F_128 () ;
return 0 ;
}
static bool F_115 ( struct V_98 * V_98 , const struct V_154 * V_152 ,
struct V_6 * V_7 )
{
unsigned int V_162 = F_107 ( V_152 ) ;
struct V_9 * V_10 ;
F_181 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_180 ( F_33 ( V_10 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( F_159 ( & V_10 -> V_152 , V_152 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_182 ( const struct V_154 * V_152 ,
const unsigned int V_177 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_133 ;
bool V_208 = false ;
F_75 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
F_169 ( & V_5 -> V_34 ) ;
F_83 (ifa, &idev->addr_list, if_list) {
V_208 = F_132 ( V_152 , & V_133 -> V_152 , V_177 ) ;
if ( V_208 )
break;
}
F_174 ( & V_5 -> V_34 ) ;
}
F_78 () ;
return V_208 ;
}
int F_183 ( const struct V_154 * V_152 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_133 ;
int V_270 ;
V_270 = 0 ;
F_75 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
F_169 ( & V_5 -> V_34 ) ;
F_83 (ifa, &idev->addr_list, if_list) {
V_270 = F_132 ( V_152 , & V_133 -> V_152 ,
V_133 -> V_177 ) ;
if ( V_270 )
break;
}
F_174 ( & V_5 -> V_34 ) ;
}
F_78 () ;
return V_270 ;
}
struct V_9 * F_184 ( struct V_98 * V_98 , const struct V_154 * V_152 ,
struct V_6 * V_7 , int V_268 )
{
struct V_9 * V_10 , * V_271 = NULL ;
unsigned int V_162 = F_107 ( V_152 ) ;
F_113 () ;
F_185 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_180 ( F_33 ( V_10 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( F_159 ( & V_10 -> V_152 , V_152 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_158 & ( V_266 | V_269 ) || V_268 ) ) {
V_271 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_128 () ;
return V_271 ;
}
static void F_186 ( struct V_9 * V_10 , int V_272 )
{
if ( V_10 -> V_48 & V_188 ) {
F_140 ( & V_10 -> V_34 ) ;
F_9 ( V_10 ) ;
V_10 -> V_48 |= V_136 ;
if ( V_272 )
V_10 -> V_48 |= V_273 ;
F_141 ( & V_10 -> V_34 ) ;
if ( V_272 )
F_148 ( 0 , V_10 ) ;
F_145 ( V_10 ) ;
} else if ( V_10 -> V_48 & V_180 ) {
struct V_9 * V_197 ;
F_140 ( & V_10 -> V_34 ) ;
V_197 = V_10 -> V_197 ;
if ( V_197 ) {
F_18 ( V_197 ) ;
F_141 ( & V_10 -> V_34 ) ;
F_150 ( V_197 , V_10 ) ;
F_145 ( V_197 ) ;
} else {
F_141 ( & V_10 -> V_34 ) ;
}
F_139 ( V_10 ) ;
} else {
F_139 ( V_10 ) ;
}
}
static int F_187 ( struct V_9 * V_10 )
{
int V_99 = - V_274 ;
F_140 ( & V_10 -> V_175 ) ;
if ( V_10 -> V_146 == V_275 ) {
V_10 -> V_146 = V_276 ;
V_99 = 0 ;
}
F_141 ( & V_10 -> V_175 ) ;
return V_99 ;
}
void F_188 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_187 ( V_10 ) ) {
F_145 ( V_10 ) ;
return;
}
F_189 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_46 , & V_10 -> V_152 ) ;
if ( V_5 -> V_37 . V_51 > 1 && ! V_5 -> V_37 . V_170 ) {
struct V_154 V_152 ;
V_152 . V_277 [ 0 ] = F_190 ( 0xfe800000 ) ;
V_152 . V_277 [ 1 ] = 0 ;
if ( ! F_191 ( V_152 . V_211 + 8 , V_5 -> V_7 ) &&
F_159 ( & V_10 -> V_152 , & V_152 ) ) {
V_5 -> V_37 . V_170 = 1 ;
F_43 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_46 ) ;
}
}
F_140 ( & V_10 -> V_175 ) ;
V_10 -> V_146 = V_278 ;
F_141 ( & V_10 -> V_175 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_192 ( struct V_6 * V_7 , const struct V_154 * V_152 )
{
struct V_154 V_279 ;
F_29 () ;
if ( V_7 -> V_48 & ( V_50 | V_49 ) )
return;
F_193 ( V_152 , & V_279 ) ;
F_47 ( V_7 , & V_279 ) ;
}
void F_194 ( struct V_4 * V_5 , const struct V_154 * V_152 )
{
struct V_154 V_279 ;
F_29 () ;
if ( V_5 -> V_7 -> V_48 & ( V_50 | V_49 ) )
return;
F_193 ( V_152 , & V_279 ) ;
F_195 ( V_5 , & V_279 ) ;
}
static void F_84 ( struct V_9 * V_10 )
{
struct V_154 V_152 ;
F_29 () ;
if ( V_10 -> V_177 >= 127 )
return;
F_196 ( & V_152 , & V_10 -> V_152 , V_10 -> V_177 ) ;
if ( F_197 ( & V_152 ) )
return;
F_198 ( V_10 -> V_5 -> V_7 , & V_152 ) ;
}
static void F_85 ( struct V_9 * V_10 )
{
struct V_154 V_152 ;
F_29 () ;
if ( V_10 -> V_177 >= 127 )
return;
F_196 ( & V_152 , & V_10 -> V_152 , V_10 -> V_177 ) ;
if ( F_197 ( & V_152 ) )
return;
F_199 ( V_10 -> V_5 , & V_152 ) ;
}
static int F_200 ( T_3 * V_280 , struct V_6 * V_7 )
{
if ( V_7 -> V_281 != V_282 )
return - 1 ;
memcpy ( V_280 , V_7 -> V_283 , 3 ) ;
memcpy ( V_280 + 5 , V_7 -> V_283 + 3 , 3 ) ;
if ( V_7 -> V_284 ) {
V_280 [ 3 ] = ( V_7 -> V_284 >> 8 ) & 0xFF ;
V_280 [ 4 ] = V_7 -> V_284 & 0xFF ;
} else {
V_280 [ 3 ] = 0xFF ;
V_280 [ 4 ] = 0xFE ;
V_280 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_201 ( T_3 * V_280 , struct V_6 * V_7 )
{
if ( V_7 -> V_281 != V_285 )
return - 1 ;
memcpy ( V_280 , V_7 -> V_283 , 8 ) ;
V_280 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_202 ( T_3 * V_280 , struct V_6 * V_7 )
{
union V_286 * V_287 ;
if ( V_7 -> V_281 != V_288 )
return - 1 ;
V_287 = (union V_286 * ) V_7 -> V_283 ;
memcpy ( V_280 , & V_287 -> V_289 . V_290 , sizeof( V_287 -> V_289 . V_290 ) ) ;
V_280 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_203 ( T_3 * V_280 , struct V_6 * V_7 )
{
if ( V_7 -> V_281 != V_291 )
return - 1 ;
memset ( V_280 , 0 , 7 ) ;
V_280 [ 7 ] = * ( T_3 * ) V_7 -> V_283 ;
return 0 ;
}
static int F_204 ( T_3 * V_280 , struct V_6 * V_7 )
{
if ( V_7 -> V_281 != V_292 )
return - 1 ;
memcpy ( V_280 , V_7 -> V_283 + 12 , 8 ) ;
V_280 [ 0 ] |= 2 ;
return 0 ;
}
static int F_205 ( T_3 * V_280 , T_4 V_152 )
{
if ( V_152 == 0 )
return - 1 ;
V_280 [ 0 ] = ( F_206 ( V_152 ) || F_207 ( V_152 ) ||
F_208 ( V_152 ) || F_209 ( V_152 ) ||
F_210 ( V_152 ) || F_211 ( V_152 ) ||
F_212 ( V_152 ) || F_213 ( V_152 ) ||
F_214 ( V_152 ) || F_215 ( V_152 ) ||
F_216 ( V_152 ) ) ? 0x00 : 0x02 ;
V_280 [ 1 ] = 0 ;
V_280 [ 2 ] = 0x5E ;
V_280 [ 3 ] = 0xFE ;
memcpy ( V_280 + 4 , & V_152 , 4 ) ;
return 0 ;
}
static int F_217 ( T_3 * V_280 , struct V_6 * V_7 )
{
if ( V_7 -> V_54 & V_55 )
return F_205 ( V_280 , * ( T_4 * ) V_7 -> V_283 ) ;
return - 1 ;
}
static int F_218 ( T_3 * V_280 , struct V_6 * V_7 )
{
return F_205 ( V_280 , * ( T_4 * ) V_7 -> V_283 ) ;
}
static int F_219 ( T_3 * V_280 , struct V_6 * V_7 )
{
memcpy ( V_280 , V_7 -> V_293 , 3 ) ;
memcpy ( V_280 + 5 , V_7 -> V_293 + 3 , 3 ) ;
V_280 [ 3 ] = 0xFF ;
V_280 [ 4 ] = 0xFE ;
V_280 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_191 ( T_3 * V_280 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_294 :
case V_295 :
return F_200 ( V_280 , V_7 ) ;
case V_296 :
return F_203 ( V_280 , V_7 ) ;
case V_297 :
return F_204 ( V_280 , V_7 ) ;
case V_53 :
return F_217 ( V_280 , V_7 ) ;
case V_298 :
return F_218 ( V_280 , V_7 ) ;
case V_299 :
case V_300 :
return F_201 ( V_280 , V_7 ) ;
case V_301 :
return F_202 ( V_280 , V_7 ) ;
case V_61 :
return F_219 ( V_280 , V_7 ) ;
}
return - 1 ;
}
static int F_220 ( T_3 * V_280 , struct V_4 * V_5 )
{
int V_99 = - 1 ;
struct V_9 * V_10 ;
F_169 ( & V_5 -> V_34 ) ;
F_176 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_158 > V_266 )
break;
if ( V_10 -> V_158 == V_266 && ! ( V_10 -> V_48 & V_136 ) ) {
memcpy ( V_280 , V_10 -> V_152 . V_211 + 8 , 8 ) ;
V_99 = 0 ;
break;
}
}
F_174 ( & V_5 -> V_34 ) ;
return V_99 ;
}
static void F_221 ( struct V_4 * V_5 )
{
V_302:
F_222 ( V_5 -> V_215 , sizeof( V_5 -> V_215 ) ) ;
V_5 -> V_215 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_215 [ 0 ] == 0xfd &&
( V_5 -> V_215 [ 1 ] & V_5 -> V_215 [ 2 ] & V_5 -> V_215 [ 3 ] & V_5 -> V_215 [ 4 ] & V_5 -> V_215 [ 5 ] & V_5 -> V_215 [ 6 ] ) == 0xff &&
( V_5 -> V_215 [ 7 ] & 0x80 ) )
goto V_302;
if ( ( V_5 -> V_215 [ 0 ] | V_5 -> V_215 [ 1 ] ) == 0 ) {
if ( V_5 -> V_215 [ 2 ] == 0x5e && V_5 -> V_215 [ 3 ] == 0xfe )
goto V_302;
if ( ( V_5 -> V_215 [ 2 ] | V_5 -> V_215 [ 3 ] | V_5 -> V_215 [ 4 ] | V_5 -> V_215 [ 5 ] | V_5 -> V_215 [ 6 ] | V_5 -> V_215 [ 7 ] ) == 0x00 )
goto V_302;
}
}
static void V_59 ( unsigned long V_303 )
{
struct V_4 * V_5 = (struct V_4 * ) V_303 ;
unsigned long V_184 ;
F_113 () ;
F_143 ( & V_5 -> V_34 ) ;
if ( V_5 -> V_47 )
goto V_174;
F_221 ( V_5 ) ;
V_184 = V_13 +
V_5 -> V_37 . V_218 * V_3 -
V_5 -> V_37 . V_214 * V_5 -> V_37 . V_220 *
F_153 ( V_5 -> V_41 , V_221 ) -
V_5 -> V_37 . V_219 * V_3 ;
if ( F_134 ( V_184 , V_13 ) ) {
F_99 ( L_16 ,
V_45 , V_5 -> V_7 -> V_46 ) ;
goto V_174;
}
if ( ! F_15 ( & V_5 -> V_58 , V_184 ) )
F_14 ( V_5 ) ;
V_174:
F_147 ( & V_5 -> V_34 ) ;
F_128 () ;
F_97 ( V_5 ) ;
}
static void F_151 ( struct V_4 * V_5 , struct V_154 * V_201 )
{
if ( V_201 && memcmp ( V_5 -> V_215 , & V_201 -> V_211 [ 8 ] , 8 ) == 0 )
F_221 ( V_5 ) ;
}
static void
F_223 ( struct V_154 * V_304 , int V_305 , struct V_6 * V_7 ,
unsigned long V_184 , T_1 V_48 )
{
struct V_306 V_307 = {
. V_308 = V_309 ,
. V_310 = V_311 ,
. V_312 = V_7 -> V_82 ,
. V_313 = V_184 ,
. V_314 = V_305 ,
. V_315 = V_316 | V_48 ,
. V_317 . V_318 = F_33 ( V_7 ) ,
. V_319 = V_320 ,
} ;
V_307 . V_321 = * V_304 ;
#if F_42 ( V_52 )
if ( V_7 -> type == V_53 && ( V_7 -> V_48 & V_322 ) )
V_307 . V_315 |= V_323 ;
#endif
F_224 ( & V_307 ) ;
}
static struct V_161 * F_136 ( const struct V_154 * V_304 ,
int V_305 ,
const struct V_6 * V_7 ,
T_1 V_48 , T_1 V_324 )
{
struct V_325 * V_326 ;
struct V_161 * V_148 = NULL ;
struct V_327 * V_140 ;
V_140 = F_225 ( F_33 ( V_7 ) , V_309 ) ;
if ( V_140 == NULL )
return NULL ;
F_169 ( & V_140 -> V_328 ) ;
V_326 = F_226 ( & V_140 -> V_329 , V_304 , V_305 , NULL , 0 ) ;
if ( ! V_326 )
goto V_174;
for ( V_148 = V_326 -> V_330 ; V_148 ; V_148 = V_148 -> V_229 . V_331 ) {
if ( V_148 -> V_229 . V_7 -> V_82 != V_7 -> V_82 )
continue;
if ( ( V_148 -> V_195 & V_48 ) != V_48 )
continue;
if ( ( V_148 -> V_195 & V_324 ) != 0 )
continue;
F_227 ( & V_148 -> V_229 ) ;
break;
}
V_174:
F_174 ( & V_140 -> V_328 ) ;
return V_148 ;
}
static void F_228 ( struct V_6 * V_7 )
{
struct V_306 V_307 = {
. V_308 = V_332 ,
. V_310 = V_311 ,
. V_312 = V_7 -> V_82 ,
. V_314 = 8 ,
. V_315 = V_316 ,
. V_317 . V_318 = F_33 ( V_7 ) ,
} ;
F_229 ( & V_307 . V_321 , F_190 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_224 ( & V_307 ) ;
}
static struct V_4 * F_230 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
return F_112 ( - V_100 ) ;
if ( V_5 -> V_37 . V_170 )
return F_112 ( - V_171 ) ;
if ( ! ( V_7 -> V_48 & V_50 ) )
F_228 ( V_7 ) ;
return V_5 ;
}
static void F_231 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_216 V_159 , V_216 V_160 ,
bool V_333 , unsigned long V_210 )
{
T_1 V_48 ;
struct V_9 * V_200 ;
F_169 ( & V_5 -> V_34 ) ;
F_83 (ift, &idev->tempaddr_list, tmp_list) {
int V_205 , V_334 , V_335 ;
if ( V_10 != V_200 -> V_197 )
continue;
V_205 = ( V_210 - V_200 -> V_1 ) / V_3 ;
V_334 = V_5 -> V_37 . V_217 - V_205 ;
if ( V_334 < 0 )
V_334 = 0 ;
V_335 = V_5 -> V_37 . V_218 -
V_5 -> V_37 . V_219 - V_205 ;
if ( V_335 < 0 )
V_335 = 0 ;
if ( V_159 > V_334 )
V_159 = V_334 ;
if ( V_160 > V_335 )
V_160 = V_335 ;
F_114 ( & V_200 -> V_34 ) ;
V_48 = V_200 -> V_48 ;
V_200 -> V_159 = V_159 ;
V_200 -> V_160 = V_160 ;
V_200 -> V_68 = V_210 ;
if ( V_160 > 0 )
V_200 -> V_48 &= ~ V_239 ;
F_124 ( & V_200 -> V_34 ) ;
if ( ! ( V_48 & V_136 ) )
F_148 ( 0 , V_200 ) ;
}
if ( ( V_333 || F_232 ( & V_5 -> V_57 ) ) &&
V_5 -> V_37 . V_63 > 0 ) {
F_174 ( & V_5 -> V_34 ) ;
F_150 ( V_10 , NULL ) ;
} else {
F_174 ( & V_5 -> V_34 ) ;
}
}
void F_233 ( struct V_6 * V_7 , T_3 * V_336 , int V_132 , bool V_337 )
{
struct V_338 * V_339 ;
V_216 V_159 ;
V_216 V_160 ;
int V_163 ;
struct V_4 * V_110 ;
struct V_98 * V_98 = F_33 ( V_7 ) ;
V_339 = (struct V_338 * ) V_336 ;
if ( V_132 < sizeof( struct V_338 ) ) {
F_37 ( L_17 ) ;
return;
}
V_163 = F_111 ( & V_339 -> V_340 ) ;
if ( V_163 & ( V_165 | V_341 ) )
return;
V_159 = F_234 ( V_339 -> V_342 ) ;
V_160 = F_234 ( V_339 -> V_343 ) ;
if ( V_160 > V_159 ) {
F_235 ( L_18 ) ;
return;
}
V_110 = F_236 ( V_7 ) ;
if ( V_110 == NULL ) {
F_237 ( L_19 ,
V_7 -> V_46 ) ;
return;
}
if ( V_339 -> V_270 ) {
struct V_161 * V_148 ;
unsigned long V_344 ;
if ( V_3 > V_345 )
V_344 = F_133 ( V_159 , V_3 ) ;
else
V_344 = F_133 ( V_159 , V_345 ) ;
if ( F_238 ( V_344 ) )
V_344 *= V_3 ;
V_148 = F_136 ( & V_339 -> V_340 ,
V_339 -> V_177 ,
V_7 ,
V_346 | V_347 ,
V_193 | V_194 ) ;
if ( V_148 ) {
if ( V_159 == 0 ) {
F_137 ( V_148 ) ;
V_148 = NULL ;
} else if ( F_238 ( V_344 ) ) {
F_138 ( V_148 , V_13 + V_344 ) ;
} else {
F_239 ( V_148 ) ;
}
} else if ( V_159 ) {
T_5 V_184 = 0 ;
int V_48 = V_346 | V_347 ;
if ( F_238 ( V_344 ) ) {
V_48 |= V_196 ;
V_184 = F_240 ( V_344 ) ;
}
F_223 ( & V_339 -> V_340 , V_339 -> V_177 ,
V_7 , V_184 , V_48 ) ;
}
F_100 ( V_148 ) ;
}
if ( V_339 -> V_348 && V_110 -> V_37 . V_348 ) {
struct V_9 * V_10 ;
struct V_154 V_152 ;
int V_333 = 0 , V_349 = 0 ;
bool V_178 = false ;
if ( V_339 -> V_177 == 64 ) {
memcpy ( & V_152 , & V_339 -> V_340 , 8 ) ;
if ( ! F_197 ( & V_110 -> V_64 ) ) {
F_169 ( & V_110 -> V_34 ) ;
memcpy ( V_152 . V_211 + 8 ,
V_110 -> V_64 . V_211 + 8 , 8 ) ;
F_174 ( & V_110 -> V_34 ) ;
V_178 = true ;
} else if ( F_191 ( V_152 . V_211 + 8 , V_7 ) &&
F_220 ( V_152 . V_211 + 8 , V_110 ) ) {
F_97 ( V_110 ) ;
return;
}
goto V_350;
}
F_237 ( L_20 ,
V_339 -> V_177 ) ;
F_97 ( V_110 ) ;
return;
V_350:
V_10 = F_184 ( V_98 , & V_152 , V_7 , 1 ) ;
if ( V_10 == NULL && V_159 ) {
int V_351 = V_110 -> V_37 . V_351 ;
T_1 V_209 = 0 ;
#ifdef F_241
if ( V_110 -> V_37 . V_352 &&
! V_98 -> V_18 . V_114 -> V_43 && V_337 )
V_209 = V_223 ;
#endif
if ( ! V_351 ||
F_178 ( V_110 ) < V_351 )
V_10 = F_110 ( V_110 , & V_152 , NULL ,
V_339 -> V_177 ,
V_163 & V_353 ,
V_209 , V_159 ,
V_160 ) ;
if ( F_242 ( V_10 ) ) {
F_97 ( V_110 ) ;
return;
}
V_349 = 0 ;
V_333 = 1 ;
F_140 ( & V_10 -> V_34 ) ;
V_10 -> V_48 |= V_354 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_178 = V_178 ;
F_141 ( & V_10 -> V_34 ) ;
F_155 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_48 ;
unsigned long V_210 ;
T_1 V_355 ;
F_114 ( & V_10 -> V_34 ) ;
V_210 = V_13 ;
if ( V_10 -> V_159 > ( V_210 - V_10 -> V_68 ) / V_3 )
V_355 = V_10 -> V_159 - ( V_210 - V_10 -> V_68 ) / V_3 ;
else
V_355 = 0 ;
if ( ! V_349 && ! V_333 && V_355 ) {
const T_1 V_356 = F_243 (
V_355 , ( T_1 ) V_357 ) ;
V_159 = F_244 ( V_159 , V_356 ) ;
V_349 = 1 ;
}
if ( V_349 ) {
V_10 -> V_159 = V_159 ;
V_10 -> V_160 = V_160 ;
V_10 -> V_68 = V_210 ;
V_48 = V_10 -> V_48 ;
V_10 -> V_48 &= ~ V_239 ;
F_124 ( & V_10 -> V_34 ) ;
if ( ! ( V_48 & V_136 ) )
F_148 ( 0 , V_10 ) ;
} else
F_124 ( & V_10 -> V_34 ) ;
F_231 ( V_110 , V_10 , V_159 , V_160 ,
V_333 , V_210 ) ;
F_145 ( V_10 ) ;
F_245 () ;
}
}
F_246 ( V_358 , V_110 , V_339 ) ;
F_97 ( V_110 ) ;
}
int F_247 ( struct V_98 * V_98 , void T_6 * V_359 )
{
struct V_360 V_361 ;
struct V_6 * V_7 ;
int V_99 = - V_112 ;
F_248 () ;
V_99 = - V_362 ;
if ( F_249 ( & V_361 , V_359 , sizeof( struct V_360 ) ) )
goto V_363;
V_7 = F_71 ( V_98 , V_361 . V_364 ) ;
V_99 = - V_168 ;
if ( V_7 == NULL )
goto V_363;
#if F_42 ( V_52 )
if ( V_7 -> type == V_53 ) {
const struct V_365 * V_366 = V_7 -> V_367 ;
struct V_368 V_369 ;
struct V_370 V_141 ;
V_99 = - V_167 ;
if ( ! ( F_111 ( & V_361 . V_371 ) & V_225 ) )
goto V_363;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_372 . V_254 = V_361 . V_371 . V_277 [ 3 ] ;
V_141 . V_372 . V_255 = 0 ;
V_141 . V_372 . V_373 = 4 ;
V_141 . V_372 . V_374 = 5 ;
V_141 . V_372 . V_375 = V_376 ;
V_141 . V_372 . V_377 = 64 ;
V_369 . V_378 . V_379 = ( V_380 void T_6 * ) & V_141 ;
if ( V_366 -> V_381 ) {
T_7 V_382 = F_250 () ;
F_251 ( V_383 ) ;
V_99 = V_366 -> V_381 ( V_7 , & V_369 , V_384 ) ;
F_251 ( V_382 ) ;
} else
V_99 = - V_385 ;
if ( V_99 == 0 ) {
V_99 = - V_100 ;
V_7 = F_252 ( V_98 , V_141 . V_46 ) ;
if ( ! V_7 )
goto V_363;
V_99 = F_253 ( V_7 ) ;
}
}
#endif
V_363:
F_91 () ;
return V_99 ;
}
static int F_254 ( struct V_98 * V_98 , int V_82 ,
const struct V_154 * V_304 ,
const struct V_154 * V_386 ,
unsigned int V_305 , V_216 V_387 ,
V_216 V_160 , V_216 V_159 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_158 ;
T_1 V_48 ;
T_5 V_184 ;
unsigned long V_388 ;
F_29 () ;
if ( V_305 > 128 )
return - V_112 ;
if ( ! V_159 || V_160 > V_159 )
return - V_112 ;
if ( V_387 & V_354 && V_305 != 64 )
return - V_112 ;
V_7 = F_71 ( V_98 , V_82 ) ;
if ( ! V_7 )
return - V_168 ;
V_5 = F_230 ( V_7 ) ;
if ( F_117 ( V_5 ) )
return F_118 ( V_5 ) ;
V_158 = F_154 ( V_304 ) ;
V_388 = F_133 ( V_159 , V_3 ) ;
if ( F_238 ( V_388 ) ) {
V_184 = F_240 ( V_388 * V_3 ) ;
V_159 = V_388 ;
V_48 = V_196 ;
} else {
V_184 = 0 ;
V_48 = 0 ;
V_387 |= V_188 ;
}
V_388 = F_133 ( V_160 , V_3 ) ;
if ( F_238 ( V_388 ) ) {
if ( V_388 == 0 )
V_387 |= V_239 ;
V_160 = V_388 ;
}
V_10 = F_110 ( V_5 , V_304 , V_386 , V_305 , V_158 , V_387 ,
V_159 , V_160 ) ;
if ( ! F_117 ( V_10 ) ) {
if ( ! ( V_387 & V_189 ) ) {
F_223 ( & V_10 -> V_152 , V_10 -> V_177 , V_7 ,
V_184 , V_48 ) ;
}
F_155 ( V_10 ) ;
if ( V_387 & V_354 )
F_231 ( V_5 , V_10 , V_159 , V_160 ,
true , V_13 ) ;
F_145 ( V_10 ) ;
F_255 () ;
return 0 ;
}
return F_118 ( V_10 ) ;
}
static int F_256 ( struct V_98 * V_98 , int V_82 , T_1 V_387 ,
const struct V_154 * V_304 , unsigned int V_305 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_305 > 128 )
return - V_112 ;
V_7 = F_71 ( V_98 , V_82 ) ;
if ( ! V_7 )
return - V_168 ;
if ( ( V_5 = F_49 ( V_7 ) ) == NULL )
return - V_389 ;
F_169 ( & V_5 -> V_34 ) ;
F_83 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_177 == V_305 &&
F_159 ( V_304 , & V_10 -> V_152 ) ) {
F_18 ( V_10 ) ;
F_174 ( & V_5 -> V_34 ) ;
if ( ! ( V_10 -> V_48 & V_180 ) &&
( V_387 & V_354 ) )
F_231 ( V_5 , V_10 , 0 , 0 , false ,
V_13 ) ;
F_139 ( V_10 ) ;
F_255 () ;
return 0 ;
}
}
F_174 ( & V_5 -> V_34 ) ;
return - V_167 ;
}
int F_257 ( struct V_98 * V_98 , void T_6 * V_359 )
{
struct V_360 V_361 ;
int V_99 ;
if ( ! F_258 ( V_98 -> V_390 , V_391 ) )
return - V_392 ;
if ( F_249 ( & V_361 , V_359 , sizeof( struct V_360 ) ) )
return - V_362 ;
F_248 () ;
V_99 = F_254 ( V_98 , V_361 . V_364 , & V_361 . V_371 , NULL ,
V_361 . V_393 , V_188 ,
V_394 , V_394 ) ;
F_91 () ;
return V_99 ;
}
int F_259 ( struct V_98 * V_98 , void T_6 * V_359 )
{
struct V_360 V_361 ;
int V_99 ;
if ( ! F_258 ( V_98 -> V_390 , V_391 ) )
return - V_392 ;
if ( F_249 ( & V_361 , V_359 , sizeof( struct V_360 ) ) )
return - V_362 ;
F_248 () ;
V_99 = F_256 ( V_98 , V_361 . V_364 , 0 , & V_361 . V_371 ,
V_361 . V_393 ) ;
F_91 () ;
return V_99 ;
}
static void F_260 ( struct V_4 * V_5 , const struct V_154 * V_152 ,
int V_305 , int V_158 )
{
struct V_9 * V_10 ;
V_10 = F_110 ( V_5 , V_152 , NULL , V_305 ,
V_158 , V_188 ,
V_394 , V_394 ) ;
if ( ! F_117 ( V_10 ) ) {
F_140 ( & V_10 -> V_34 ) ;
V_10 -> V_48 &= ~ V_136 ;
F_141 ( & V_10 -> V_34 ) ;
F_148 ( V_395 , V_10 ) ;
F_145 ( V_10 ) ;
}
}
static void F_261 ( struct V_4 * V_5 )
{
struct V_154 V_152 ;
struct V_6 * V_7 ;
struct V_98 * V_98 = F_33 ( V_5 -> V_7 ) ;
int V_158 , V_305 ;
T_1 V_396 = 0 ;
F_29 () ;
memset ( & V_152 , 0 , sizeof( struct V_154 ) ) ;
memcpy ( & V_152 . V_277 [ 3 ] , V_5 -> V_7 -> V_283 , 4 ) ;
if ( V_5 -> V_7 -> V_48 & V_322 ) {
V_152 . V_277 [ 0 ] = F_190 ( 0xfe800000 ) ;
V_158 = V_266 ;
V_305 = 64 ;
} else {
V_158 = V_225 ;
V_305 = 96 ;
V_396 |= V_323 ;
}
if ( V_152 . V_277 [ 3 ] ) {
F_260 ( V_5 , & V_152 , V_305 , V_158 ) ;
F_223 ( & V_152 , V_305 , V_5 -> V_7 , 0 , V_396 ) ;
return;
}
F_87 (net, dev) {
struct V_397 * V_398 = F_262 ( V_7 ) ;
if ( V_398 && ( V_7 -> V_48 & V_74 ) ) {
struct V_399 * V_133 ;
int V_400 = V_158 ;
for ( V_133 = V_398 -> V_401 ; V_133 ; V_133 = V_133 -> V_402 ) {
V_152 . V_277 [ 3 ] = V_133 -> V_403 ;
if ( V_133 -> V_404 == V_405 )
continue;
if ( V_133 -> V_404 >= V_406 ) {
if ( V_5 -> V_7 -> V_48 & V_322 )
continue;
V_400 |= V_269 ;
}
F_260 ( V_5 , & V_152 , V_305 , V_400 ) ;
F_223 ( & V_152 , V_305 , V_5 -> V_7 , 0 ,
V_396 ) ;
}
}
}
}
static void F_263 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_407 ;
struct V_9 * V_408 ;
struct V_161 * V_409 ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_96 ( L_21 , V_45 ) ;
return;
}
F_260 ( V_5 , & V_410 , 128 , V_269 ) ;
F_87 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_407 -> V_46 , V_7 -> V_46 ) )
continue;
V_5 = F_49 ( V_407 ) ;
if ( ! V_5 )
continue;
F_169 ( & V_5 -> V_34 ) ;
F_83 (sp_ifa, &idev->addr_list, if_list) {
if ( V_408 -> V_48 & ( V_273 | V_136 ) )
continue;
if ( V_408 -> V_148 ) {
if ( V_408 -> V_148 -> V_229 . V_411 > 0 ) {
F_100 ( V_408 -> V_148 ) ;
V_408 -> V_148 = NULL ;
} else {
continue;
}
}
V_409 = F_116 ( V_5 , & V_408 -> V_152 , false ) ;
if ( ! F_117 ( V_409 ) ) {
V_408 -> V_148 = V_409 ;
F_264 ( V_409 ) ;
}
}
F_174 ( & V_5 -> V_34 ) ;
}
}
static void F_265 ( struct V_4 * V_5 , const struct V_154 * V_152 )
{
struct V_9 * V_10 ;
T_1 V_209 = V_188 ;
#ifdef F_241
if ( V_5 -> V_37 . V_352 &&
! F_33 ( V_5 -> V_7 ) -> V_18 . V_114 -> V_43 )
V_209 |= V_223 ;
#endif
V_10 = F_110 ( V_5 , V_152 , NULL , 64 , V_266 , V_209 ,
V_394 , V_394 ) ;
if ( ! F_117 ( V_10 ) ) {
F_223 ( & V_10 -> V_152 , V_10 -> V_177 , V_5 -> V_7 , 0 , 0 ) ;
F_155 ( V_10 ) ;
F_145 ( V_10 ) ;
}
}
static void F_266 ( struct V_6 * V_7 )
{
struct V_154 V_152 ;
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_294 ) &&
( V_7 -> type != V_295 ) &&
( V_7 -> type != V_296 ) &&
( V_7 -> type != V_297 ) &&
( V_7 -> type != V_300 ) &&
( V_7 -> type != V_301 ) &&
( V_7 -> type != V_61 ) &&
( V_7 -> type != V_299 ) ) {
return;
}
V_5 = F_230 ( V_7 ) ;
if ( F_117 ( V_5 ) )
return;
memset ( & V_152 , 0 , sizeof( struct V_154 ) ) ;
V_152 . V_277 [ 0 ] = F_190 ( 0xFE800000 ) ;
if ( F_191 ( V_152 . V_211 + 8 , V_7 ) == 0 )
F_265 ( V_5 , & V_152 ) ;
}
static void F_267 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_96 ( L_21 , V_45 ) ;
return;
}
if ( V_7 -> V_54 & V_55 ) {
struct V_154 V_152 ;
F_229 ( & V_152 , F_190 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( ! F_191 ( V_152 . V_211 + 8 , V_7 ) )
F_265 ( V_5 , & V_152 ) ;
return;
}
F_261 ( V_5 ) ;
if ( V_7 -> V_48 & V_322 )
F_228 ( V_7 ) ;
}
static void F_268 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_154 V_152 ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_96 ( L_21 , V_45 ) ;
return;
}
F_229 ( & V_152 , F_190 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( ! F_191 ( V_152 . V_211 + 8 , V_7 ) )
F_265 ( V_5 , & V_152 ) ;
else
F_223 ( & V_152 , 64 , V_7 , 0 , 0 ) ;
}
static int F_269 ( struct V_412 * V_413 , unsigned long V_87 ,
void * V_414 )
{
struct V_6 * V_7 = F_270 ( V_414 ) ;
struct V_4 * V_5 = F_49 ( V_7 ) ;
int V_415 = 0 ;
int V_99 ;
switch ( V_87 ) {
case V_416 :
if ( ! V_5 && V_7 -> V_32 >= V_33 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! V_5 )
return F_271 ( - V_30 ) ;
}
break;
case V_182 :
case V_417 :
if ( V_7 -> V_48 & V_418 )
break;
if ( V_87 == V_182 ) {
if ( ! F_4 ( V_7 ) ) {
F_43 ( L_22 ,
V_7 -> V_46 ) ;
break;
}
if ( ! V_5 && V_7 -> V_32 >= V_33 )
V_5 = F_28 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_66 |= V_67 ;
V_415 = 1 ;
}
} else {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_66 & V_67 )
break;
V_5 -> V_66 |= V_67 ;
}
F_43 ( L_23 ,
V_7 -> V_46 ) ;
V_415 = 1 ;
}
switch ( V_7 -> type ) {
#if F_42 ( V_52 )
case V_53 :
F_267 ( V_7 ) ;
break;
#endif
#if F_42 ( V_419 )
case V_298 :
F_268 ( V_7 ) ;
break;
#endif
case V_420 :
F_263 ( V_7 ) ;
break;
default:
F_266 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_415 )
F_272 ( V_5 ) ;
if ( V_5 -> V_37 . V_39 != V_7 -> V_32 &&
V_7 -> V_32 >= V_33 ) {
F_273 ( V_7 , V_7 -> V_32 ) ;
V_5 -> V_37 . V_39 = V_7 -> V_32 ;
}
V_5 -> V_68 = V_13 ;
F_274 ( V_421 , V_5 ) ;
if ( V_7 -> V_32 < V_33 )
F_275 ( V_7 , 1 ) ;
}
break;
case V_422 :
if ( V_5 && V_7 -> V_32 >= V_33 ) {
F_273 ( V_7 , V_7 -> V_32 ) ;
V_5 -> V_37 . V_39 = V_7 -> V_32 ;
break;
}
if ( ! V_5 && V_7 -> V_32 >= V_33 ) {
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
break;
}
case V_199 :
case V_423 :
F_275 ( V_7 , V_87 != V_199 ) ;
break;
case V_424 :
if ( V_5 ) {
F_276 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_99 = F_40 ( V_5 ) ;
if ( V_99 )
return F_271 ( V_99 ) ;
}
break;
case V_425 :
case V_426 :
F_277 ( V_7 , V_87 ) ;
break;
}
return V_427 ;
}
static void F_277 ( struct V_6 * V_7 , unsigned long V_87 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_87 == V_426 )
F_278 ( V_5 ) ;
else if ( V_87 == V_425 )
F_279 ( V_5 ) ;
}
static int F_275 ( struct V_6 * V_7 , int V_428 )
{
struct V_98 * V_98 = F_33 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_133 ;
int V_146 , V_16 ;
F_29 () ;
F_280 ( V_98 , V_7 ) ;
F_281 ( & V_42 , V_7 ) ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 == NULL )
return - V_168 ;
if ( V_428 ) {
V_5 -> V_47 = 1 ;
F_282 ( V_7 -> V_69 , NULL ) ;
F_276 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_429 ; V_16 ++ ) {
struct V_123 * V_119 = & V_179 [ V_16 ] ;
F_140 ( & V_172 ) ;
V_430:
F_77 (ifa, h, addr_lst) {
if ( V_133 -> V_5 == V_5 ) {
F_142 ( & V_133 -> V_145 ) ;
F_9 ( V_133 ) ;
goto V_430;
}
}
F_141 ( & V_172 ) ;
}
F_143 ( & V_5 -> V_34 ) ;
F_6 ( V_5 ) ;
if ( ! V_428 )
V_5 -> V_66 &= ~ ( V_431 | V_432 | V_67 ) ;
if ( V_428 && F_7 ( & V_5 -> V_58 ) )
F_97 ( V_5 ) ;
while ( ! F_232 ( & V_5 -> V_57 ) ) {
V_133 = F_283 ( & V_5 -> V_57 ,
struct V_9 , V_181 ) ;
F_144 ( & V_133 -> V_181 ) ;
F_147 ( & V_5 -> V_34 ) ;
F_140 ( & V_133 -> V_34 ) ;
if ( V_133 -> V_197 ) {
F_145 ( V_133 -> V_197 ) ;
V_133 -> V_197 = NULL ;
}
F_141 ( & V_133 -> V_34 ) ;
F_145 ( V_133 ) ;
F_143 ( & V_5 -> V_34 ) ;
}
while ( ! F_232 ( & V_5 -> V_35 ) ) {
V_133 = F_283 ( & V_5 -> V_35 ,
struct V_9 , V_153 ) ;
F_9 ( V_133 ) ;
F_144 ( & V_133 -> V_153 ) ;
F_147 ( & V_5 -> V_34 ) ;
F_140 ( & V_133 -> V_175 ) ;
V_146 = V_133 -> V_146 ;
V_133 -> V_146 = V_147 ;
F_141 ( & V_133 -> V_175 ) ;
if ( V_146 != V_147 ) {
F_284 ( V_198 , V_133 ) ;
F_130 ( V_199 , V_133 ) ;
}
F_145 ( V_133 ) ;
F_143 ( & V_5 -> V_34 ) ;
}
F_147 ( & V_5 -> V_34 ) ;
if ( V_428 )
F_285 ( V_5 ) ;
else
F_286 ( V_5 ) ;
V_5 -> V_68 = V_13 ;
if ( V_428 ) {
F_3 ( V_5 ) ;
F_38 ( & V_42 , V_5 -> V_41 ) ;
F_281 ( & V_42 , V_7 ) ;
F_97 ( V_5 ) ;
}
return 0 ;
}
static void V_36 ( unsigned long V_303 )
{
struct V_4 * V_5 = (struct V_4 * ) V_303 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_154 V_433 ;
F_125 ( & V_5 -> V_34 ) ;
if ( V_5 -> V_47 || ! ( V_5 -> V_66 & V_67 ) )
goto V_174;
if ( ! F_287 ( V_5 ) )
goto V_174;
if ( V_5 -> V_66 & V_432 )
goto V_174;
if ( V_5 -> V_434 ++ < V_5 -> V_37 . V_56 ) {
F_127 ( & V_5 -> V_34 ) ;
if ( ! F_177 ( V_7 , & V_433 , V_136 ) )
F_288 ( V_7 , & V_433 ,
& V_73 ) ;
else
goto V_435;
F_125 ( & V_5 -> V_34 ) ;
F_12 ( V_5 , ( V_5 -> V_434 ==
V_5 -> V_37 . V_56 ) ?
V_5 -> V_37 . V_436 :
V_5 -> V_37 . V_437 ) ;
} else {
F_96 ( L_24 , V_5 -> V_7 -> V_46 ) ;
}
V_174:
F_127 ( & V_5 -> V_34 ) ;
V_435:
F_97 ( V_5 ) ;
}
static void F_289 ( struct V_9 * V_10 )
{
unsigned long V_438 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_48 & V_223 )
V_438 = 0 ;
else
V_438 = F_290 () % ( V_5 -> V_37 . V_436 ? : 1 ) ;
V_10 -> V_439 = V_5 -> V_37 . V_220 ;
F_16 ( V_10 , V_438 ) ;
}
static void F_291 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_192 ( V_7 , & V_10 -> V_152 ) ;
F_292 ( ( V_380 T_1 ) V_10 -> V_152 . V_277 [ 3 ] ) ;
F_169 ( & V_5 -> V_34 ) ;
F_114 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_146 == V_147 )
goto V_174;
if ( V_7 -> V_48 & ( V_49 | V_50 ) ||
V_5 -> V_37 . V_51 < 1 ||
! ( V_10 -> V_48 & V_136 ) ||
V_10 -> V_48 & V_440 ) {
V_10 -> V_48 &= ~ ( V_136 | V_223 | V_273 ) ;
F_124 ( & V_10 -> V_34 ) ;
F_174 ( & V_5 -> V_34 ) ;
F_293 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_66 & V_67 ) ) {
F_124 ( & V_10 -> V_34 ) ;
F_174 ( & V_5 -> V_34 ) ;
F_18 ( V_10 ) ;
F_186 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_48 & V_223 )
F_264 ( V_10 -> V_148 ) ;
F_289 ( V_10 ) ;
V_174:
F_124 ( & V_10 -> V_34 ) ;
F_174 ( & V_5 -> V_34 ) ;
}
static void F_155 ( struct V_9 * V_10 )
{
bool V_441 = false ;
F_140 ( & V_10 -> V_175 ) ;
if ( V_10 -> V_146 != V_147 ) {
V_10 -> V_146 = V_442 ;
V_441 = true ;
}
F_141 ( & V_10 -> V_175 ) ;
if ( V_441 )
F_16 ( V_10 , 0 ) ;
}
static void V_176 ( struct V_443 * V_444 )
{
struct V_9 * V_10 = F_294 ( F_295 ( V_444 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_154 V_445 ;
enum {
V_446 ,
V_447 ,
V_448 ,
} V_186 = V_446 ;
F_248 () ;
F_140 ( & V_10 -> V_175 ) ;
if ( V_10 -> V_146 == V_442 ) {
V_186 = V_447 ;
V_10 -> V_146 = V_275 ;
} else if ( V_10 -> V_146 == V_278 ) {
V_186 = V_448 ;
V_10 -> V_146 = V_276 ;
}
F_141 ( & V_10 -> V_175 ) ;
if ( V_186 == V_447 ) {
F_291 ( V_10 ) ;
goto V_174;
} else if ( V_186 == V_448 ) {
F_186 ( V_10 , 1 ) ;
goto V_174;
}
if ( ! V_10 -> V_439 && F_187 ( V_10 ) )
goto V_174;
F_143 ( & V_5 -> V_34 ) ;
if ( V_5 -> V_47 || ! ( V_5 -> V_66 & V_67 ) ) {
F_147 ( & V_5 -> V_34 ) ;
goto V_174;
}
F_114 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_146 == V_147 ) {
F_124 ( & V_10 -> V_34 ) ;
F_147 ( & V_5 -> V_34 ) ;
goto V_174;
}
if ( V_10 -> V_439 == 0 ) {
V_10 -> V_48 &= ~ ( V_136 | V_223 | V_273 ) ;
F_124 ( & V_10 -> V_34 ) ;
F_147 ( & V_5 -> V_34 ) ;
F_293 ( V_10 ) ;
goto V_174;
}
V_10 -> V_439 -- ;
F_16 ( V_10 ,
F_153 ( V_10 -> V_5 -> V_41 , V_221 ) ) ;
F_124 ( & V_10 -> V_34 ) ;
F_147 ( & V_5 -> V_34 ) ;
F_193 ( & V_10 -> V_152 , & V_445 ) ;
F_296 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_152 , & V_445 , & V_65 ) ;
V_174:
F_145 ( V_10 ) ;
F_91 () ;
}
static bool F_297 ( struct V_9 * V_10 )
{
struct V_9 * V_449 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_176 (ifpiter, &idev->addr_list, if_list) {
if ( V_449 -> V_158 > V_266 )
break;
if ( V_10 != V_449 && V_449 -> V_158 == V_266 &&
( V_449 -> V_48 & ( V_188 | V_136 |
V_223 | V_273 ) ) ==
V_188 )
return false ;
}
return true ;
}
static void F_293 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_154 V_433 ;
bool V_450 , V_451 ;
F_9 ( V_10 ) ;
F_148 ( V_395 , V_10 ) ;
F_169 ( & V_10 -> V_5 -> V_34 ) ;
V_451 = V_10 -> V_158 == V_266 && F_297 ( V_10 ) ;
V_450 = V_451 &&
F_287 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_37 . V_56 > 0 &&
( V_7 -> V_48 & V_50 ) == 0 ;
F_174 ( & V_10 -> V_5 -> V_34 ) ;
if ( V_451 )
F_298 ( V_10 -> V_5 ) ;
if ( V_450 ) {
if ( F_177 ( V_7 , & V_433 , V_136 ) )
return;
F_288 ( V_7 , & V_433 , & V_73 ) ;
F_143 ( & V_10 -> V_5 -> V_34 ) ;
F_114 ( & V_10 -> V_34 ) ;
V_10 -> V_5 -> V_434 = 1 ;
V_10 -> V_5 -> V_66 |= V_431 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_37 . V_437 ) ;
F_124 ( & V_10 -> V_34 ) ;
F_147 ( & V_10 -> V_5 -> V_34 ) ;
}
}
static void F_272 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_169 ( & V_5 -> V_34 ) ;
F_83 (ifp, &idev->addr_list, if_list) {
F_114 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_48 & V_136 &&
V_10 -> V_146 == V_275 )
F_289 ( V_10 ) ;
F_124 ( & V_10 -> V_34 ) ;
}
F_174 ( & V_5 -> V_34 ) ;
}
static struct V_9 * F_299 ( struct V_452 * V_86 , T_8 V_453 )
{
struct V_9 * V_133 = NULL ;
struct V_454 * V_146 = V_86 -> V_455 ;
struct V_98 * V_98 = F_300 ( V_86 ) ;
int V_141 = 0 ;
if ( V_453 == 0 ) {
V_146 -> V_456 = 0 ;
V_146 -> V_457 = 0 ;
}
for (; V_146 -> V_456 < V_429 ; ++ V_146 -> V_456 ) {
F_185 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_180 ( F_33 ( V_133 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( V_141 < V_146 -> V_457 ) {
V_141 ++ ;
continue;
}
V_146 -> V_457 ++ ;
return V_133 ;
}
V_146 -> V_457 = 0 ;
V_141 = 0 ;
}
return NULL ;
}
static struct V_9 * F_301 ( struct V_452 * V_86 ,
struct V_9 * V_133 )
{
struct V_454 * V_146 = V_86 -> V_455 ;
struct V_98 * V_98 = F_300 ( V_86 ) ;
F_302 (ifa, addr_lst) {
if ( ! F_180 ( F_33 ( V_133 -> V_5 -> V_7 ) , V_98 ) )
continue;
V_146 -> V_457 ++ ;
return V_133 ;
}
while ( ++ V_146 -> V_456 < V_429 ) {
V_146 -> V_457 = 0 ;
F_185 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_180 ( F_33 ( V_133 -> V_5 -> V_7 ) , V_98 ) )
continue;
V_146 -> V_457 ++ ;
return V_133 ;
}
}
return NULL ;
}
static void * F_303 ( struct V_452 * V_86 , T_8 * V_453 )
__acquires( T_9 )
{
F_113 () ;
return F_299 ( V_86 , * V_453 ) ;
}
static void * F_304 ( struct V_452 * V_86 , void * V_458 , T_8 * V_453 )
{
struct V_9 * V_133 ;
V_133 = F_301 ( V_86 , V_458 ) ;
++ * V_453 ;
return V_133 ;
}
static void F_305 ( struct V_452 * V_86 , void * V_458 )
__releases( T_9 )
{
F_128 () ;
}
static int F_306 ( struct V_452 * V_86 , void * V_458 )
{
struct V_9 * V_10 = (struct V_9 * ) V_458 ;
F_307 ( V_86 , L_25 ,
& V_10 -> V_152 ,
V_10 -> V_5 -> V_7 -> V_82 ,
V_10 -> V_177 ,
V_10 -> V_158 ,
( T_3 ) V_10 -> V_48 ,
V_10 -> V_5 -> V_7 -> V_46 ) ;
return 0 ;
}
static int F_308 ( struct V_459 * V_459 , struct V_460 * V_460 )
{
return F_309 ( V_459 , V_460 , & V_461 ,
sizeof( struct V_454 ) ) ;
}
static int T_10 F_310 ( struct V_98 * V_98 )
{
if ( ! F_311 ( L_26 , V_462 , V_98 -> V_463 , & V_464 ) )
return - V_30 ;
return 0 ;
}
static void T_11 F_312 ( struct V_98 * V_98 )
{
F_313 ( L_26 , V_98 -> V_463 ) ;
}
int T_12 F_314 ( void )
{
return F_315 ( & V_465 ) ;
}
void F_316 ( void )
{
F_317 ( & V_465 ) ;
}
int F_318 ( struct V_98 * V_98 , const struct V_154 * V_152 )
{
int V_208 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_162 = F_107 ( V_152 ) ;
F_113 () ;
F_185 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_180 ( F_33 ( V_10 -> V_5 -> V_7 ) , V_98 ) )
continue;
if ( F_159 ( & V_10 -> V_152 , V_152 ) &&
( V_10 -> V_48 & V_244 ) ) {
V_208 = 1 ;
break;
}
}
F_128 () ;
return V_208 ;
}
static void F_255 ( void )
{
unsigned long V_210 , V_466 , V_467 , V_468 ;
struct V_9 * V_10 ;
int V_16 ;
F_29 () ;
F_113 () ;
V_210 = V_13 ;
V_466 = F_319 ( V_210 + V_469 ) ;
F_10 ( & V_470 ) ;
for ( V_16 = 0 ; V_16 < V_429 ; V_16 ++ ) {
V_430:
F_185 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_205 ;
if ( ( V_10 -> V_48 & V_188 ) &&
( V_10 -> V_160 == V_394 ) )
continue;
F_114 ( & V_10 -> V_34 ) ;
V_205 = ( V_210 - V_10 -> V_68 + V_222 ) / V_3 ;
if ( V_10 -> V_159 != V_394 &&
V_205 >= V_10 -> V_159 ) {
F_124 ( & V_10 -> V_34 ) ;
F_18 ( V_10 ) ;
F_139 ( V_10 ) ;
goto V_430;
} else if ( V_10 -> V_160 == V_394 ) {
F_124 ( & V_10 -> V_34 ) ;
continue;
} else if ( V_205 >= V_10 -> V_160 ) {
int V_471 = 0 ;
if ( ! ( V_10 -> V_48 & V_239 ) ) {
V_471 = 1 ;
V_10 -> V_48 |= V_239 ;
}
if ( ( V_10 -> V_159 != V_394 ) &&
( F_134 ( V_10 -> V_68 + V_10 -> V_159 * V_3 , V_466 ) ) )
V_466 = V_10 -> V_68 + V_10 -> V_159 * V_3 ;
F_124 ( & V_10 -> V_34 ) ;
if ( V_471 ) {
F_18 ( V_10 ) ;
F_148 ( 0 , V_10 ) ;
F_145 ( V_10 ) ;
goto V_430;
}
} else if ( ( V_10 -> V_48 & V_180 ) &&
! ( V_10 -> V_48 & V_136 ) ) {
unsigned long V_206 = V_10 -> V_5 -> V_37 . V_214 *
V_10 -> V_5 -> V_37 . V_220 *
F_153 ( V_10 -> V_5 -> V_41 , V_221 ) / V_3 ;
if ( V_205 >= V_10 -> V_160 - V_206 ) {
struct V_9 * V_197 = V_10 -> V_197 ;
if ( F_134 ( V_10 -> V_68 + V_10 -> V_160 * V_3 , V_466 ) )
V_466 = V_10 -> V_68 + V_10 -> V_160 * V_3 ;
if ( ! V_10 -> V_213 && V_197 ) {
V_10 -> V_213 ++ ;
F_18 ( V_10 ) ;
F_18 ( V_197 ) ;
F_124 ( & V_10 -> V_34 ) ;
F_114 ( & V_197 -> V_34 ) ;
V_197 -> V_213 = 0 ;
F_124 ( & V_197 -> V_34 ) ;
F_150 ( V_197 , V_10 ) ;
F_145 ( V_197 ) ;
F_145 ( V_10 ) ;
goto V_430;
}
} else if ( F_134 ( V_10 -> V_68 + V_10 -> V_160 * V_3 - V_206 * V_3 , V_466 ) )
V_466 = V_10 -> V_68 + V_10 -> V_160 * V_3 - V_206 * V_3 ;
F_124 ( & V_10 -> V_34 ) ;
} else {
if ( F_134 ( V_10 -> V_68 + V_10 -> V_160 * V_3 , V_466 ) )
V_466 = V_10 -> V_68 + V_10 -> V_160 * V_3 ;
F_124 ( & V_10 -> V_34 ) ;
}
}
}
V_467 = F_319 ( V_466 ) ;
V_468 = V_466 ;
if ( F_134 ( V_467 , V_466 + V_472 ) )
V_468 = V_467 ;
if ( F_134 ( V_468 , V_13 + V_473 ) )
V_468 = V_13 + V_473 ;
F_37 ( V_260 L_27 ,
V_210 , V_466 , V_467 , V_468 ) ;
F_19 ( V_15 , & V_470 , V_468 - V_210 ) ;
F_128 () ;
}
static void F_320 ( struct V_443 * V_444 )
{
F_248 () ;
F_255 () ;
F_91 () ;
}
static void F_245 ( void )
{
F_19 ( V_15 , & V_470 , 0 ) ;
}
static struct V_154 * F_321 ( struct V_107 * V_152 , struct V_107 * V_474 ,
struct V_154 * * V_386 )
{
struct V_154 * V_304 = NULL ;
* V_386 = NULL ;
if ( V_152 )
V_304 = F_322 ( V_152 ) ;
if ( V_474 ) {
if ( V_304 && F_323 ( V_474 , V_304 , sizeof( * V_304 ) ) )
* V_386 = V_304 ;
V_304 = F_322 ( V_474 ) ;
}
return V_304 ;
}
static int
F_324 ( struct V_80 * V_81 , struct V_88 * V_89 )
{
struct V_98 * V_98 = F_68 ( V_81 -> V_106 ) ;
struct V_475 * V_476 ;
struct V_107 * V_108 [ V_477 + 1 ] ;
struct V_154 * V_304 , * V_386 ;
T_1 V_387 ;
int V_99 ;
V_99 = F_69 ( V_89 , sizeof( * V_476 ) , V_108 , V_477 , V_478 ) ;
if ( V_99 < 0 )
return V_99 ;
V_476 = F_57 ( V_89 ) ;
V_304 = F_321 ( V_108 [ V_479 ] , V_108 [ V_480 ] , & V_386 ) ;
if ( V_304 == NULL )
return - V_112 ;
V_387 = V_108 [ V_481 ] ? F_325 ( V_108 [ V_481 ] ) : V_476 -> V_387 ;
V_387 &= V_354 ;
return F_256 ( V_98 , V_476 -> V_482 , V_387 , V_304 ,
V_476 -> V_483 ) ;
}
static int F_326 ( struct V_9 * V_10 , T_1 V_387 ,
T_1 V_160 , T_1 V_159 )
{
T_1 V_48 ;
T_5 V_184 ;
unsigned long V_388 ;
bool V_484 ;
bool V_485 ;
F_29 () ;
if ( ! V_159 || ( V_160 > V_159 ) )
return - V_112 ;
if ( V_387 & V_354 &&
( V_10 -> V_48 & V_180 || V_10 -> V_177 != 64 ) )
return - V_112 ;
V_388 = F_133 ( V_159 , V_3 ) ;
if ( F_238 ( V_388 ) ) {
V_184 = F_240 ( V_388 * V_3 ) ;
V_159 = V_388 ;
V_48 = V_196 ;
} else {
V_184 = 0 ;
V_48 = 0 ;
V_387 |= V_188 ;
}
V_388 = F_133 ( V_160 , V_3 ) ;
if ( F_238 ( V_388 ) ) {
if ( V_388 == 0 )
V_387 |= V_239 ;
V_160 = V_388 ;
}
F_140 ( & V_10 -> V_34 ) ;
V_484 = V_10 -> V_48 & V_354 ;
V_485 = V_10 -> V_48 & V_188 &&
! ( V_10 -> V_48 & V_189 ) ;
V_10 -> V_48 &= ~ ( V_239 | V_188 | V_440 |
V_244 | V_354 |
V_189 ) ;
V_10 -> V_48 |= V_387 ;
V_10 -> V_68 = V_13 ;
V_10 -> V_159 = V_159 ;
V_10 -> V_160 = V_160 ;
F_141 ( & V_10 -> V_34 ) ;
if ( ! ( V_10 -> V_48 & V_136 ) )
F_148 ( 0 , V_10 ) ;
if ( ! ( V_387 & V_189 ) ) {
F_223 ( & V_10 -> V_152 , V_10 -> V_177 , V_10 -> V_5 -> V_7 ,
V_184 , V_48 ) ;
} else if ( V_485 ) {
enum V_183 V_186 ;
unsigned long V_344 ;
F_143 ( & V_10 -> V_5 -> V_34 ) ;
V_186 = F_131 ( V_10 , & V_344 ) ;
F_147 ( & V_10 -> V_5 -> V_34 ) ;
if ( V_186 != V_190 ) {
F_135 ( V_10 , V_344 ,
V_186 == V_187 ) ;
}
}
if ( V_484 || V_10 -> V_48 & V_354 ) {
if ( V_484 && ! ( V_10 -> V_48 & V_354 ) )
V_159 = V_160 = 0 ;
F_231 ( V_10 -> V_5 , V_10 , V_159 , V_160 ,
! V_484 , V_13 ) ;
}
F_255 () ;
return 0 ;
}
static int
F_327 ( struct V_80 * V_81 , struct V_88 * V_89 )
{
struct V_98 * V_98 = F_68 ( V_81 -> V_106 ) ;
struct V_475 * V_476 ;
struct V_107 * V_108 [ V_477 + 1 ] ;
struct V_154 * V_304 , * V_386 ;
struct V_9 * V_133 ;
struct V_6 * V_7 ;
T_1 V_159 = V_394 , V_486 = V_394 ;
T_1 V_387 ;
int V_99 ;
V_99 = F_69 ( V_89 , sizeof( * V_476 ) , V_108 , V_477 , V_478 ) ;
if ( V_99 < 0 )
return V_99 ;
V_476 = F_57 ( V_89 ) ;
V_304 = F_321 ( V_108 [ V_479 ] , V_108 [ V_480 ] , & V_386 ) ;
if ( V_304 == NULL )
return - V_112 ;
if ( V_108 [ V_487 ] ) {
struct V_488 * V_489 ;
V_489 = F_322 ( V_108 [ V_487 ] ) ;
V_159 = V_489 -> V_490 ;
V_486 = V_489 -> V_491 ;
} else {
V_486 = V_394 ;
V_159 = V_394 ;
}
V_7 = F_71 ( V_98 , V_476 -> V_482 ) ;
if ( V_7 == NULL )
return - V_168 ;
V_387 = V_108 [ V_481 ] ? F_325 ( V_108 [ V_481 ] ) : V_476 -> V_387 ;
V_387 &= V_440 | V_244 | V_354 |
V_189 ;
V_133 = F_184 ( V_98 , V_304 , V_7 , 1 ) ;
if ( V_133 == NULL ) {
return F_254 ( V_98 , V_476 -> V_482 , V_304 , V_386 ,
V_476 -> V_483 , V_387 ,
V_486 , V_159 ) ;
}
if ( V_89 -> V_492 & V_493 ||
! ( V_89 -> V_492 & V_494 ) )
V_99 = - V_173 ;
else
V_99 = F_326 ( V_133 , V_387 , V_486 , V_159 ) ;
F_145 ( V_133 ) ;
return V_99 ;
}
static void F_328 ( struct V_88 * V_89 , T_3 V_495 , T_1 V_48 ,
T_3 V_158 , int V_82 )
{
struct V_475 * V_476 ;
V_476 = F_57 ( V_89 ) ;
V_476 -> V_496 = V_93 ;
V_476 -> V_483 = V_495 ;
V_476 -> V_387 = V_48 ;
V_476 -> V_404 = V_158 ;
V_476 -> V_482 = V_82 ;
}
static int F_329 ( struct V_80 * V_81 , unsigned long V_1 ,
unsigned long V_68 , T_1 V_497 , T_1 V_342 )
{
struct V_488 V_489 ;
V_489 . V_1 = F_1 ( V_1 ) ;
V_489 . V_68 = F_1 ( V_68 ) ;
V_489 . V_491 = V_497 ;
V_489 . V_490 = V_342 ;
return F_330 ( V_81 , V_487 , sizeof( V_489 ) , & V_489 ) ;
}
static inline int F_331 ( int V_404 )
{
if ( V_404 & V_269 )
return V_406 ;
else if ( V_404 & V_266 )
return V_405 ;
else if ( V_404 & V_498 )
return V_499 ;
else
return V_500 ;
}
static inline int F_332 ( void )
{
return F_52 ( sizeof( struct V_475 ) )
+ F_53 ( 16 )
+ F_53 ( 16 )
+ F_53 ( sizeof( struct V_488 ) )
+ F_53 ( 4 ) ;
}
static int F_333 ( struct V_80 * V_81 , struct V_9 * V_133 ,
T_1 V_85 , T_1 V_86 , int V_87 , unsigned int V_48 )
{
struct V_88 * V_89 ;
T_1 V_497 , V_342 ;
V_89 = F_56 ( V_81 , V_85 , V_86 , V_87 , sizeof( struct V_475 ) , V_48 ) ;
if ( V_89 == NULL )
return - V_91 ;
F_328 ( V_89 , V_133 -> V_177 , V_133 -> V_48 , F_331 ( V_133 -> V_158 ) ,
V_133 -> V_5 -> V_7 -> V_82 ) ;
if ( ! ( ( V_133 -> V_48 & V_188 ) &&
( V_133 -> V_160 == V_394 ) ) ) {
V_497 = V_133 -> V_160 ;
V_342 = V_133 -> V_159 ;
if ( V_497 != V_394 ) {
long V_501 = ( V_13 - V_133 -> V_68 ) / V_3 ;
if ( V_497 > V_501 )
V_497 -= V_501 ;
else
V_497 = 0 ;
if ( V_342 != V_394 ) {
if ( V_342 > V_501 )
V_342 -= V_501 ;
else
V_342 = 0 ;
}
}
} else {
V_497 = V_394 ;
V_342 = V_394 ;
}
if ( ! F_197 ( & V_133 -> V_156 ) ) {
if ( F_330 ( V_81 , V_480 , 16 , & V_133 -> V_152 ) < 0 ||
F_330 ( V_81 , V_479 , 16 , & V_133 -> V_156 ) < 0 )
goto error;
} else
if ( F_330 ( V_81 , V_479 , 16 , & V_133 -> V_152 ) < 0 )
goto error;
if ( F_329 ( V_81 , V_133 -> V_1 , V_133 -> V_68 , V_497 , V_342 ) < 0 )
goto error;
if ( F_334 ( V_81 , V_481 , V_133 -> V_48 ) < 0 )
goto error;
return F_59 ( V_81 , V_89 ) ;
error:
F_60 ( V_81 , V_89 ) ;
return - V_91 ;
}
static int F_335 ( struct V_80 * V_81 , struct V_502 * V_503 ,
T_1 V_85 , T_1 V_86 , int V_87 , T_13 V_48 )
{
struct V_88 * V_89 ;
T_3 V_158 = V_500 ;
int V_82 = V_503 -> V_5 -> V_7 -> V_82 ;
if ( F_154 ( & V_503 -> V_504 ) & V_498 )
V_158 = V_499 ;
V_89 = F_56 ( V_81 , V_85 , V_86 , V_87 , sizeof( struct V_475 ) , V_48 ) ;
if ( V_89 == NULL )
return - V_91 ;
F_328 ( V_89 , 128 , V_188 , V_158 , V_82 ) ;
if ( F_330 ( V_81 , V_505 , 16 , & V_503 -> V_504 ) < 0 ||
F_329 ( V_81 , V_503 -> V_506 , V_503 -> V_507 ,
V_394 , V_394 ) < 0 ) {
F_60 ( V_81 , V_89 ) ;
return - V_91 ;
}
return F_59 ( V_81 , V_89 ) ;
}
static int F_336 ( struct V_80 * V_81 , struct V_508 * V_509 ,
T_1 V_85 , T_1 V_86 , int V_87 , unsigned int V_48 )
{
struct V_88 * V_89 ;
T_3 V_158 = V_500 ;
int V_82 = V_509 -> V_510 -> V_7 -> V_82 ;
if ( F_154 ( & V_509 -> V_511 ) & V_498 )
V_158 = V_499 ;
V_89 = F_56 ( V_81 , V_85 , V_86 , V_87 , sizeof( struct V_475 ) , V_48 ) ;
if ( V_89 == NULL )
return - V_91 ;
F_328 ( V_89 , 128 , V_188 , V_158 , V_82 ) ;
if ( F_330 ( V_81 , V_512 , 16 , & V_509 -> V_511 ) < 0 ||
F_329 ( V_81 , V_509 -> V_513 , V_509 -> V_514 ,
V_394 , V_394 ) < 0 ) {
F_60 ( V_81 , V_89 ) ;
return - V_91 ;
}
return F_59 ( V_81 , V_89 ) ;
}
static int F_337 ( struct V_4 * V_5 , struct V_80 * V_81 ,
struct V_117 * V_118 , enum V_515 type ,
int V_516 , int * V_517 )
{
struct V_502 * V_503 ;
struct V_508 * V_509 ;
int V_99 = 1 ;
int V_518 = * V_517 ;
F_169 ( & V_5 -> V_34 ) ;
switch ( type ) {
case V_519 : {
struct V_9 * V_133 ;
F_83 (ifa, &idev->addr_list, if_list) {
if ( ++ V_518 < V_516 )
continue;
V_99 = F_333 ( V_81 , V_133 ,
F_72 ( V_118 -> V_81 ) . V_85 ,
V_118 -> V_89 -> V_116 ,
V_395 ,
V_130 ) ;
if ( V_99 <= 0 )
break;
F_79 ( V_118 , F_80 ( V_81 ) ) ;
}
break;
}
case V_520 :
for ( V_503 = V_5 -> V_521 ; V_503 ;
V_503 = V_503 -> V_466 , V_518 ++ ) {
if ( V_518 < V_516 )
continue;
V_99 = F_335 ( V_81 , V_503 ,
F_72 ( V_118 -> V_81 ) . V_85 ,
V_118 -> V_89 -> V_116 ,
V_522 ,
V_130 ) ;
if ( V_99 <= 0 )
break;
}
break;
case V_523 :
for ( V_509 = V_5 -> V_524 ; V_509 ;
V_509 = V_509 -> V_525 , V_518 ++ ) {
if ( V_518 < V_516 )
continue;
V_99 = F_336 ( V_81 , V_509 ,
F_72 ( V_118 -> V_81 ) . V_85 ,
V_118 -> V_89 -> V_116 ,
V_526 ,
V_130 ) ;
if ( V_99 <= 0 )
break;
}
break;
default:
break;
}
F_174 ( & V_5 -> V_34 ) ;
* V_517 = V_518 ;
return V_99 ;
}
static int F_338 ( struct V_80 * V_81 , struct V_117 * V_118 ,
enum V_515 type )
{
struct V_98 * V_98 = F_68 ( V_81 -> V_106 ) ;
int V_119 , V_120 ;
int V_121 , V_518 ;
int V_122 , V_516 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_123 * V_124 ;
V_120 = V_118 -> args [ 0 ] ;
V_122 = V_121 = V_118 -> args [ 1 ] ;
V_516 = V_518 = V_118 -> args [ 2 ] ;
F_75 () ;
V_118 -> V_86 = F_76 ( & V_98 -> V_18 . V_127 ) ^ V_98 -> V_128 ;
for ( V_119 = V_120 ; V_119 < V_125 ; V_119 ++ , V_122 = 0 ) {
V_121 = 0 ;
V_124 = & V_98 -> V_126 [ V_119 ] ;
F_77 (dev, head, index_hlist) {
if ( V_121 < V_122 )
goto V_129;
if ( V_119 > V_120 || V_121 > V_122 )
V_516 = 0 ;
V_518 = 0 ;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
goto V_129;
if ( F_337 ( V_5 , V_81 , V_118 , type ,
V_516 , & V_518 ) <= 0 )
goto V_131;
V_129:
V_121 ++ ;
}
}
V_131:
F_78 () ;
V_118 -> args [ 0 ] = V_119 ;
V_118 -> args [ 1 ] = V_121 ;
V_118 -> args [ 2 ] = V_518 ;
return V_81 -> V_132 ;
}
static int F_339 ( struct V_80 * V_81 , struct V_117 * V_118 )
{
enum V_515 type = V_519 ;
return F_338 ( V_81 , V_118 , type ) ;
}
static int F_340 ( struct V_80 * V_81 , struct V_117 * V_118 )
{
enum V_515 type = V_520 ;
return F_338 ( V_81 , V_118 , type ) ;
}
static int F_341 ( struct V_80 * V_81 , struct V_117 * V_118 )
{
enum V_515 type = V_523 ;
return F_338 ( V_81 , V_118 , type ) ;
}
static int F_342 ( struct V_80 * V_105 , struct V_88 * V_89 )
{
struct V_98 * V_98 = F_68 ( V_105 -> V_106 ) ;
struct V_475 * V_476 ;
struct V_107 * V_108 [ V_477 + 1 ] ;
struct V_154 * V_152 = NULL , * V_527 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_133 ;
struct V_80 * V_81 ;
int V_99 ;
V_99 = F_69 ( V_89 , sizeof( * V_476 ) , V_108 , V_477 , V_478 ) ;
if ( V_99 < 0 )
goto V_102;
V_152 = F_321 ( V_108 [ V_479 ] , V_108 [ V_480 ] , & V_527 ) ;
if ( V_152 == NULL ) {
V_99 = - V_112 ;
goto V_102;
}
V_476 = F_57 ( V_89 ) ;
if ( V_476 -> V_482 )
V_7 = F_71 ( V_98 , V_476 -> V_482 ) ;
V_133 = F_184 ( V_98 , V_152 , V_7 , 1 ) ;
if ( ! V_133 ) {
V_99 = - V_167 ;
goto V_102;
}
V_81 = F_62 ( F_332 () , V_25 ) ;
if ( ! V_81 ) {
V_99 = - V_100 ;
goto V_528;
}
V_99 = F_333 ( V_81 , V_133 , F_72 ( V_105 ) . V_85 ,
V_89 -> V_116 , V_395 , 0 ) ;
if ( V_99 < 0 ) {
F_63 ( V_99 == - V_91 ) ;
F_64 ( V_81 ) ;
goto V_528;
}
V_99 = F_73 ( V_81 , V_98 , F_72 ( V_105 ) . V_85 ) ;
V_528:
F_145 ( V_133 ) ;
V_102:
return V_99 ;
}
static void F_343 ( int V_87 , struct V_9 * V_133 )
{
struct V_80 * V_81 ;
struct V_98 * V_98 = F_33 ( V_133 -> V_5 -> V_7 ) ;
int V_99 = - V_100 ;
V_81 = F_62 ( F_332 () , V_101 ) ;
if ( V_81 == NULL )
goto V_102;
V_99 = F_333 ( V_81 , V_133 , 0 , 0 , V_87 , 0 ) ;
if ( V_99 < 0 ) {
F_63 ( V_99 == - V_91 ) ;
F_64 ( V_81 ) ;
goto V_102;
}
F_65 ( V_81 , V_98 , 0 , V_529 , NULL , V_101 ) ;
return;
V_102:
if ( V_99 < 0 )
F_66 ( V_98 , V_529 , V_99 ) ;
}
static inline void F_344 ( struct V_83 * V_37 ,
T_2 * V_530 , int V_531 )
{
F_345 ( V_531 < ( V_532 * 4 ) ) ;
memset ( V_530 , 0 , V_531 ) ;
V_530 [ V_533 ] = V_37 -> V_43 ;
V_530 [ V_534 ] = V_37 -> V_535 ;
V_530 [ V_536 ] = V_37 -> V_39 ;
V_530 [ V_537 ] = V_37 -> V_538 ;
V_530 [ V_539 ] = V_37 -> V_540 ;
V_530 [ V_541 ] = V_37 -> V_348 ;
V_530 [ V_542 ] = V_37 -> V_220 ;
V_530 [ V_543 ] = V_37 -> V_56 ;
V_530 [ V_544 ] =
F_346 ( V_37 -> V_437 ) ;
V_530 [ V_545 ] =
F_346 ( V_37 -> V_436 ) ;
V_530 [ V_546 ] = V_37 -> V_547 ;
V_530 [ V_548 ] =
F_346 ( V_37 -> V_549 ) ;
V_530 [ V_550 ] =
F_346 ( V_37 -> V_551 ) ;
V_530 [ V_552 ] = V_37 -> V_63 ;
V_530 [ V_553 ] = V_37 -> V_217 ;
V_530 [ V_554 ] = V_37 -> V_218 ;
V_530 [ V_555 ] = V_37 -> V_214 ;
V_530 [ V_556 ] = V_37 -> V_219 ;
V_530 [ V_557 ] = V_37 -> V_351 ;
V_530 [ V_558 ] = V_37 -> V_559 ;
V_530 [ V_560 ] = V_37 -> V_561 ;
#ifdef F_347
V_530 [ V_562 ] = V_37 -> V_563 ;
V_530 [ V_564 ] =
F_346 ( V_37 -> V_565 ) ;
#ifdef F_348
V_530 [ V_566 ] = V_37 -> V_567 ;
#endif
#endif
V_530 [ V_568 ] = V_37 -> V_97 ;
V_530 [ V_569 ] = V_37 -> V_570 ;
#ifdef F_241
V_530 [ V_571 ] = V_37 -> V_352 ;
#endif
#ifdef F_54
V_530 [ V_572 ] = V_37 -> V_96 ;
#endif
V_530 [ V_573 ] = V_37 -> V_170 ;
V_530 [ V_574 ] = V_37 -> V_51 ;
V_530 [ V_575 ] = V_37 -> V_576 ;
V_530 [ V_577 ] = V_37 -> V_578 ;
V_530 [ V_579 ] = V_37 -> V_580 ;
}
static inline T_14 F_349 ( void )
{
return F_53 ( 4 )
+ F_53 ( sizeof( struct V_581 ) )
+ F_53 ( V_532 * 4 )
+ F_53 ( V_582 * 8 )
+ F_53 ( V_583 * 8 )
+ F_53 ( sizeof( struct V_154 ) ) ;
}
static inline T_14 F_350 ( void )
{
return F_52 ( sizeof( struct V_584 ) )
+ F_53 ( V_585 )
+ F_53 ( V_586 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( F_349 () ) ;
}
static inline void F_351 ( T_15 * V_17 , T_16 * V_587 ,
int V_588 , int V_531 )
{
int V_16 ;
int V_589 = V_531 - sizeof( T_15 ) * V_588 ;
F_345 ( V_589 < 0 ) ;
F_352 ( V_588 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_588 ; V_16 ++ )
F_352 ( F_353 ( & V_587 [ V_16 ] ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_588 ] , 0 , V_589 ) ;
}
static inline void F_354 ( T_15 * V_17 , void T_17 * V_587 ,
int V_588 , int V_531 , T_14 V_590 )
{
int V_16 ;
int V_589 = V_531 - sizeof( T_15 ) * V_588 ;
F_345 ( V_589 < 0 ) ;
F_352 ( V_588 , & V_17 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_588 ; V_16 ++ )
F_352 ( F_355 ( V_587 , V_16 , V_590 ) , & V_17 [ V_16 ] ) ;
memset ( & V_17 [ V_588 ] , 0 , V_589 ) ;
}
static void F_356 ( T_15 * V_17 , struct V_4 * V_5 , int V_591 ,
int V_531 )
{
switch ( V_591 ) {
case V_592 :
F_354 ( V_17 , V_5 -> V_17 . V_18 ,
V_582 , V_531 , F_357 ( struct V_19 , V_22 ) ) ;
break;
case V_593 :
F_351 ( V_17 , V_5 -> V_17 . V_23 -> V_594 , V_583 , V_531 ) ;
break;
}
}
static int F_358 ( struct V_80 * V_81 , struct V_4 * V_5 )
{
struct V_107 * V_595 ;
struct V_581 V_489 ;
if ( F_334 ( V_81 , V_596 , V_5 -> V_66 ) )
goto V_95;
V_489 . V_597 = V_598 ;
V_489 . V_68 = F_1 ( V_5 -> V_68 ) ;
V_489 . V_599 = F_346 ( V_5 -> V_41 -> V_599 ) ;
V_489 . V_600 = F_346 ( F_153 ( V_5 -> V_41 , V_221 ) ) ;
if ( F_330 ( V_81 , V_601 , sizeof( V_489 ) , & V_489 ) )
goto V_95;
V_595 = F_359 ( V_81 , V_602 , V_532 * sizeof( V_603 ) ) ;
if ( V_595 == NULL )
goto V_95;
F_344 ( & V_5 -> V_37 , F_322 ( V_595 ) , F_360 ( V_595 ) ) ;
V_595 = F_359 ( V_81 , V_592 , V_582 * sizeof( T_15 ) ) ;
if ( V_595 == NULL )
goto V_95;
F_356 ( F_322 ( V_595 ) , V_5 , V_592 , F_360 ( V_595 ) ) ;
V_595 = F_359 ( V_81 , V_593 , V_583 * sizeof( T_15 ) ) ;
if ( V_595 == NULL )
goto V_95;
F_356 ( F_322 ( V_595 ) , V_5 , V_593 , F_360 ( V_595 ) ) ;
V_595 = F_359 ( V_81 , V_604 , sizeof( struct V_154 ) ) ;
if ( V_595 == NULL )
goto V_95;
F_169 ( & V_5 -> V_34 ) ;
memcpy ( F_322 ( V_595 ) , V_5 -> V_64 . V_211 , F_360 ( V_595 ) ) ;
F_174 ( & V_5 -> V_34 ) ;
return 0 ;
V_95:
return - V_91 ;
}
static T_14 F_361 ( const struct V_6 * V_7 )
{
if ( ! F_49 ( V_7 ) )
return 0 ;
return F_349 () ;
}
static int F_362 ( struct V_80 * V_81 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
return - V_605 ;
if ( F_358 ( V_81 , V_5 ) < 0 )
return - V_91 ;
return 0 ;
}
static int F_363 ( struct V_4 * V_5 , struct V_154 * V_64 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_606 = false ;
struct V_154 V_607 ;
F_29 () ;
if ( V_64 == NULL )
return - V_112 ;
if ( F_197 ( V_64 ) )
return - V_112 ;
if ( V_7 -> V_48 & ( V_50 | V_49 ) )
return - V_112 ;
if ( ! F_287 ( V_5 ) )
return - V_112 ;
if ( V_5 -> V_37 . V_56 <= 0 )
return - V_112 ;
F_143 ( & V_5 -> V_34 ) ;
F_364 ( sizeof( V_64 -> V_211 ) != 16 ) ;
memcpy ( V_5 -> V_64 . V_211 + 8 , V_64 -> V_211 + 8 , 8 ) ;
F_147 ( & V_5 -> V_34 ) ;
if ( ! V_5 -> V_47 && ( V_5 -> V_66 & V_67 ) &&
! F_177 ( V_7 , & V_607 , V_136 |
V_223 ) ) {
F_288 ( V_7 , & V_607 , & V_73 ) ;
V_606 = true ;
}
F_143 ( & V_5 -> V_34 ) ;
if ( V_606 ) {
V_5 -> V_66 |= V_431 ;
V_5 -> V_434 = 1 ;
F_12 ( V_5 , V_5 -> V_37 . V_437 ) ;
}
F_83 (ifp, &idev->addr_list, if_list) {
F_114 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_178 ) {
V_10 -> V_159 = 0 ;
V_10 -> V_160 = 0 ;
}
F_124 ( & V_10 -> V_34 ) ;
}
F_147 ( & V_5 -> V_34 ) ;
F_255 () ;
return 0 ;
}
static int F_365 ( struct V_6 * V_7 , const struct V_107 * V_595 )
{
int V_99 = - V_112 ;
struct V_4 * V_5 = F_49 ( V_7 ) ;
struct V_107 * V_108 [ V_608 + 1 ] ;
if ( ! V_5 )
return - V_609 ;
if ( F_366 ( V_108 , V_608 , V_595 , NULL ) < 0 )
F_367 () ;
if ( V_108 [ V_604 ] )
V_99 = F_363 ( V_5 , F_322 ( V_108 [ V_604 ] ) ) ;
return V_99 ;
}
static int F_368 ( struct V_80 * V_81 , struct V_4 * V_5 ,
T_1 V_85 , T_1 V_86 , int V_87 , unsigned int V_48 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_584 * V_610 ;
struct V_88 * V_89 ;
void * V_611 ;
V_89 = F_56 ( V_81 , V_85 , V_86 , V_87 , sizeof( * V_610 ) , V_48 ) ;
if ( V_89 == NULL )
return - V_91 ;
V_610 = F_57 ( V_89 ) ;
V_610 -> V_612 = V_93 ;
V_610 -> V_613 = 0 ;
V_610 -> V_614 = V_7 -> type ;
V_610 -> V_615 = V_7 -> V_82 ;
V_610 -> V_616 = F_369 ( V_7 ) ;
V_610 -> V_617 = 0 ;
if ( F_370 ( V_81 , V_618 , V_7 -> V_46 ) ||
( V_7 -> V_281 &&
F_330 ( V_81 , V_619 , V_7 -> V_281 , V_7 -> V_283 ) ) ||
F_334 ( V_81 , V_620 , V_7 -> V_32 ) ||
( V_7 -> V_82 != V_7 -> V_621 &&
F_334 ( V_81 , V_622 , V_7 -> V_621 ) ) )
goto V_95;
V_611 = F_371 ( V_81 , V_623 ) ;
if ( V_611 == NULL )
goto V_95;
if ( F_358 ( V_81 , V_5 ) < 0 )
goto V_95;
F_372 ( V_81 , V_611 ) ;
return F_59 ( V_81 , V_89 ) ;
V_95:
F_60 ( V_81 , V_89 ) ;
return - V_91 ;
}
static int F_373 ( struct V_80 * V_81 , struct V_117 * V_118 )
{
struct V_98 * V_98 = F_68 ( V_81 -> V_106 ) ;
int V_119 , V_120 ;
int V_121 = 0 , V_122 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_123 * V_124 ;
V_120 = V_118 -> args [ 0 ] ;
V_122 = V_118 -> args [ 1 ] ;
F_75 () ;
for ( V_119 = V_120 ; V_119 < V_125 ; V_119 ++ , V_122 = 0 ) {
V_121 = 0 ;
V_124 = & V_98 -> V_126 [ V_119 ] ;
F_77 (dev, head, index_hlist) {
if ( V_121 < V_122 )
goto V_129;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
goto V_129;
if ( F_368 ( V_81 , V_5 ,
F_72 ( V_118 -> V_81 ) . V_85 ,
V_118 -> V_89 -> V_116 ,
V_421 , V_130 ) <= 0 )
goto V_174;
V_129:
V_121 ++ ;
}
}
V_174:
F_78 () ;
V_118 -> args [ 1 ] = V_121 ;
V_118 -> args [ 0 ] = V_119 ;
return V_81 -> V_132 ;
}
void F_274 ( int V_87 , struct V_4 * V_5 )
{
struct V_80 * V_81 ;
struct V_98 * V_98 = F_33 ( V_5 -> V_7 ) ;
int V_99 = - V_100 ;
V_81 = F_62 ( F_350 () , V_101 ) ;
if ( V_81 == NULL )
goto V_102;
V_99 = F_368 ( V_81 , V_5 , 0 , 0 , V_87 , 0 ) ;
if ( V_99 < 0 ) {
F_63 ( V_99 == - V_91 ) ;
F_64 ( V_81 ) ;
goto V_102;
}
F_65 ( V_81 , V_98 , 0 , V_624 , NULL , V_101 ) ;
return;
V_102:
if ( V_99 < 0 )
F_66 ( V_98 , V_624 , V_99 ) ;
}
static inline T_14 F_374 ( void )
{
return F_52 ( sizeof( struct V_625 ) )
+ F_53 ( sizeof( struct V_154 ) )
+ F_53 ( sizeof( struct V_626 ) ) ;
}
static int F_375 ( struct V_80 * V_81 , struct V_4 * V_5 ,
struct V_338 * V_339 , T_1 V_85 , T_1 V_86 ,
int V_87 , unsigned int V_48 )
{
struct V_625 * V_627 ;
struct V_88 * V_89 ;
struct V_626 V_489 ;
V_89 = F_56 ( V_81 , V_85 , V_86 , V_87 , sizeof( * V_627 ) , V_48 ) ;
if ( V_89 == NULL )
return - V_91 ;
V_627 = F_57 ( V_89 ) ;
V_627 -> V_628 = V_93 ;
V_627 -> V_629 = 0 ;
V_627 -> V_630 = 0 ;
V_627 -> V_631 = V_5 -> V_7 -> V_82 ;
V_627 -> V_177 = V_339 -> V_177 ;
V_627 -> V_632 = V_339 -> type ;
V_627 -> V_633 = 0 ;
V_627 -> V_634 = 0 ;
if ( V_339 -> V_270 )
V_627 -> V_634 |= V_635 ;
if ( V_339 -> V_348 )
V_627 -> V_634 |= V_636 ;
if ( F_330 ( V_81 , V_637 , sizeof( V_339 -> V_340 ) , & V_339 -> V_340 ) )
goto V_95;
V_489 . V_638 = F_234 ( V_339 -> V_343 ) ;
V_489 . V_639 = F_234 ( V_339 -> V_342 ) ;
if ( F_330 ( V_81 , V_640 , sizeof( V_489 ) , & V_489 ) )
goto V_95;
return F_59 ( V_81 , V_89 ) ;
V_95:
F_60 ( V_81 , V_89 ) ;
return - V_91 ;
}
static void F_246 ( int V_87 , struct V_4 * V_5 ,
struct V_338 * V_339 )
{
struct V_80 * V_81 ;
struct V_98 * V_98 = F_33 ( V_5 -> V_7 ) ;
int V_99 = - V_100 ;
V_81 = F_62 ( F_374 () , V_101 ) ;
if ( V_81 == NULL )
goto V_102;
V_99 = F_375 ( V_81 , V_5 , V_339 , 0 , 0 , V_87 , 0 ) ;
if ( V_99 < 0 ) {
F_63 ( V_99 == - V_91 ) ;
F_64 ( V_81 ) ;
goto V_102;
}
F_65 ( V_81 , V_98 , 0 , V_641 , NULL , V_101 ) ;
return;
V_102:
if ( V_99 < 0 )
F_66 ( V_98 , V_641 , V_99 ) ;
}
static void F_284 ( int V_87 , struct V_9 * V_10 )
{
struct V_98 * V_98 = F_33 ( V_10 -> V_5 -> V_7 ) ;
if ( V_87 )
F_29 () ;
F_343 ( V_87 ? : V_395 , V_10 ) ;
switch ( V_87 ) {
case V_395 :
if ( ! ( V_10 -> V_148 -> V_642 ) )
F_264 ( V_10 -> V_148 ) ;
if ( V_10 -> V_5 -> V_37 . V_43 )
F_84 ( V_10 ) ;
if ( ! F_197 ( & V_10 -> V_156 ) )
F_223 ( & V_10 -> V_156 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_198 :
if ( V_10 -> V_5 -> V_37 . V_43 )
F_85 ( V_10 ) ;
F_194 ( V_10 -> V_5 , & V_10 -> V_152 ) ;
if ( ! F_197 ( & V_10 -> V_156 ) ) {
struct V_161 * V_148 ;
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
V_148 = F_376 ( F_33 ( V_7 ) , & V_10 -> V_156 , NULL ,
V_7 -> V_82 , 1 ) ;
if ( V_148 ) {
F_227 ( & V_148 -> V_229 ) ;
if ( F_137 ( V_148 ) )
F_377 ( & V_148 -> V_229 ) ;
}
}
F_227 ( & V_10 -> V_148 -> V_229 ) ;
if ( F_137 ( V_10 -> V_148 ) )
F_377 ( & V_10 -> V_148 -> V_229 ) ;
break;
}
F_378 ( & V_98 -> V_18 . V_127 ) ;
F_379 ( V_98 ) ;
}
static void F_148 ( int V_87 , struct V_9 * V_10 )
{
F_113 () ;
if ( F_129 ( V_10 -> V_5 -> V_47 == 0 ) )
F_284 ( V_87 , V_10 ) ;
F_128 () ;
}
static
int F_380 ( struct V_139 * V_643 , int V_644 ,
void T_6 * V_645 , T_14 * V_646 , T_8 * V_647 )
{
int * V_648 = V_643 -> V_303 ;
int V_649 = * V_648 ;
T_8 V_453 = * V_647 ;
struct V_139 V_650 ;
int V_208 ;
V_650 = * V_643 ;
V_650 . V_303 = & V_649 ;
V_208 = F_381 ( & V_650 , V_644 , V_645 , V_646 , V_647 ) ;
if ( V_644 )
V_208 = F_88 ( V_643 , V_648 , V_649 ) ;
if ( V_208 )
* V_647 = V_453 ;
return V_208 ;
}
static void F_382 ( struct V_4 * V_5 )
{
struct V_651 V_652 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_383 ( & V_652 , V_5 -> V_7 ) ;
if ( V_5 -> V_37 . V_170 )
F_269 ( NULL , V_199 , & V_652 ) ;
else
F_269 ( NULL , V_182 , & V_652 ) ;
}
static void F_384 ( struct V_98 * V_98 , T_2 V_137 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_75 () ;
F_168 (net, dev) {
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
int V_138 = ( ! V_5 -> V_37 . V_170 ) ^ ( ! V_137 ) ;
V_5 -> V_37 . V_170 = V_137 ;
if ( V_138 )
F_382 ( V_5 ) ;
}
}
F_78 () ;
}
static int F_385 ( struct V_139 * V_140 , int * V_141 , int V_137 )
{
struct V_98 * V_98 ;
int V_142 ;
if ( ! F_89 () )
return F_90 () ;
V_98 = (struct V_98 * ) V_140 -> V_143 ;
V_142 = * V_141 ;
* V_141 = V_137 ;
if ( V_141 == & V_98 -> V_18 . V_38 -> V_170 ) {
F_91 () ;
return 0 ;
}
if ( V_141 == & V_98 -> V_18 . V_114 -> V_170 ) {
V_98 -> V_18 . V_38 -> V_170 = V_137 ;
F_384 ( V_98 , V_137 ) ;
} else if ( ( ! V_137 ) ^ ( ! V_142 ) )
F_382 ( (struct V_4 * ) V_140 -> V_144 ) ;
F_91 () ;
return 0 ;
}
static
int F_386 ( struct V_139 * V_643 , int V_644 ,
void T_6 * V_645 , T_14 * V_646 , T_8 * V_647 )
{
int * V_648 = V_643 -> V_303 ;
int V_649 = * V_648 ;
T_8 V_453 = * V_647 ;
struct V_139 V_650 ;
int V_208 ;
V_650 = * V_643 ;
V_650 . V_303 = & V_649 ;
V_208 = F_381 ( & V_650 , V_644 , V_645 , V_646 , V_647 ) ;
if ( V_644 )
V_208 = F_385 ( V_643 , V_648 , V_649 ) ;
if ( V_208 )
* V_647 = V_453 ;
return V_208 ;
}
static
int F_387 ( struct V_139 * V_643 , int V_644 ,
void T_6 * V_645 , T_14 * V_646 , T_8 * V_647 )
{
int * V_648 = V_643 -> V_303 ;
int V_208 ;
int V_142 , V_653 ;
V_142 = * V_648 ;
V_208 = F_381 ( V_643 , V_644 , V_645 , V_646 , V_647 ) ;
V_653 = * V_648 ;
if ( V_644 && V_142 != V_653 ) {
struct V_98 * V_98 = V_643 -> V_143 ;
if ( ! F_89 () )
return F_90 () ;
if ( V_648 == & V_98 -> V_18 . V_38 -> V_97 )
F_61 ( V_98 , V_79 ,
V_115 ,
V_98 -> V_18 . V_38 ) ;
else if ( V_648 == & V_98 -> V_18 . V_114 -> V_97 )
F_61 ( V_98 , V_79 ,
V_113 ,
V_98 -> V_18 . V_114 ) ;
else {
struct V_4 * V_5 = V_643 -> V_144 ;
F_61 ( V_98 , V_79 ,
V_5 -> V_7 -> V_82 ,
& V_5 -> V_37 ) ;
}
F_91 () ;
}
return V_208 ;
}
static int F_388 ( struct V_98 * V_98 , char * V_654 ,
struct V_4 * V_5 , struct V_83 * V_141 )
{
int V_16 ;
struct V_655 * V_656 ;
char V_657 [ sizeof( L_28 ) + V_585 ] ;
V_656 = F_389 ( & V_658 , sizeof( * V_656 ) , V_25 ) ;
if ( V_656 == NULL )
goto V_174;
for ( V_16 = 0 ; V_656 -> V_659 [ V_16 ] . V_303 ; V_16 ++ ) {
V_656 -> V_659 [ V_16 ] . V_303 += ( char * ) V_141 - ( char * ) & V_83 ;
V_656 -> V_659 [ V_16 ] . V_144 = V_5 ;
V_656 -> V_659 [ V_16 ] . V_143 = V_98 ;
}
snprintf ( V_657 , sizeof( V_657 ) , L_29 , V_654 ) ;
V_656 -> V_660 = F_390 ( V_98 , V_657 , V_656 -> V_659 ) ;
if ( V_656 -> V_660 == NULL )
goto free;
V_141 -> V_40 = V_656 ;
return 0 ;
free:
F_26 ( V_656 ) ;
V_174:
return - V_100 ;
}
static void F_391 ( struct V_83 * V_141 )
{
struct V_655 * V_656 ;
if ( V_141 -> V_40 == NULL )
return;
V_656 = V_141 -> V_40 ;
V_141 -> V_40 = NULL ;
F_392 ( V_656 -> V_660 ) ;
F_26 ( V_656 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_393 ( V_5 -> V_7 , V_5 -> V_41 ,
& V_661 ) ;
F_388 ( F_33 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_46 ,
V_5 , & V_5 -> V_37 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_391 ( & V_5 -> V_37 ) ;
F_394 ( V_5 -> V_41 ) ;
}
static int T_10 F_395 ( struct V_98 * V_98 )
{
int V_99 = - V_30 ;
struct V_83 * V_662 , * V_663 ;
V_662 = F_389 ( & V_83 , sizeof( V_83 ) , V_25 ) ;
if ( V_662 == NULL )
goto V_664;
V_663 = F_389 ( & V_665 , sizeof( V_665 ) , V_25 ) ;
if ( V_663 == NULL )
goto V_666;
V_663 -> V_348 = V_667 . V_348 ;
V_663 -> V_170 = V_667 . V_170 ;
V_98 -> V_18 . V_114 = V_662 ;
V_98 -> V_18 . V_38 = V_663 ;
#ifdef F_396
V_99 = F_388 ( V_98 , L_30 , NULL , V_662 ) ;
if ( V_99 < 0 )
goto V_668;
V_99 = F_388 ( V_98 , L_31 , NULL , V_663 ) ;
if ( V_99 < 0 )
goto V_669;
#endif
return 0 ;
#ifdef F_396
V_669:
F_391 ( V_662 ) ;
V_668:
F_26 ( V_663 ) ;
#endif
V_666:
F_26 ( V_662 ) ;
V_664:
return V_99 ;
}
static void T_11 F_397 ( struct V_98 * V_98 )
{
#ifdef F_396
F_391 ( V_98 -> V_18 . V_38 ) ;
F_391 ( V_98 -> V_18 . V_114 ) ;
#endif
if ( ! F_180 ( V_98 , & V_670 ) ) {
F_26 ( V_98 -> V_18 . V_38 ) ;
F_26 ( V_98 -> V_18 . V_114 ) ;
}
}
int T_12 F_398 ( void )
{
int V_16 , V_99 ;
V_99 = F_399 () ;
if ( V_99 < 0 ) {
F_400 ( L_32 ,
V_45 , V_99 ) ;
goto V_174;
}
V_99 = F_315 ( & V_671 ) ;
if ( V_99 < 0 )
goto V_672;
V_15 = F_401 ( L_33 ) ;
if ( ! V_15 ) {
V_99 = - V_30 ;
goto V_673;
}
F_248 () ;
if ( ! F_28 ( V_670 . V_674 ) )
V_99 = - V_30 ;
F_91 () ;
if ( V_99 )
goto V_675;
for ( V_16 = 0 ; V_16 < V_429 ; V_16 ++ )
F_402 ( & V_179 [ V_16 ] ) ;
F_403 ( & V_676 ) ;
F_245 () ;
F_404 ( & V_677 ) ;
V_99 = F_405 ( V_678 , V_679 , NULL , F_373 ,
NULL ) ;
if ( V_99 < 0 )
goto V_102;
F_405 ( V_678 , V_395 , F_327 , NULL , NULL ) ;
F_405 ( V_678 , V_198 , F_324 , NULL , NULL ) ;
F_405 ( V_678 , V_680 , F_342 ,
F_339 , NULL ) ;
F_405 ( V_678 , V_522 , NULL ,
F_340 , NULL ) ;
F_405 ( V_678 , V_526 , NULL ,
F_341 , NULL ) ;
F_405 ( V_678 , V_681 , F_67 ,
F_74 , NULL ) ;
F_406 () ;
return 0 ;
V_102:
F_407 ( & V_677 ) ;
F_408 ( & V_676 ) ;
V_675:
F_409 ( V_15 ) ;
V_673:
F_317 ( & V_671 ) ;
V_672:
F_410 () ;
V_174:
return V_99 ;
}
void F_411 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_408 ( & V_676 ) ;
F_317 ( & V_671 ) ;
F_410 () ;
F_248 () ;
F_412 ( & V_677 ) ;
F_87 (&init_net, dev) {
if ( F_49 ( V_7 ) == NULL )
continue;
F_275 ( V_7 , 1 ) ;
}
F_275 ( V_670 . V_674 , 2 ) ;
F_140 ( & V_172 ) ;
for ( V_16 = 0 ; V_16 < V_429 ; V_16 ++ )
F_63 ( ! F_413 ( & V_179 [ V_16 ] ) ) ;
F_141 ( & V_172 ) ;
F_10 ( & V_470 ) ;
F_91 () ;
F_409 ( V_15 ) ;
}
