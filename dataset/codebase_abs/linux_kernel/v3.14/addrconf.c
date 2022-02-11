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
if ( F_21 ( ( void V_17 * * ) V_5 -> V_18 . V_19 ,
sizeof( struct V_20 ) ,
F_22 ( struct V_20 ) ) < 0 )
goto V_21;
F_23 (i) {
struct V_20 * V_22 ;
V_22 = F_24 ( V_5 -> V_18 . V_19 [ 0 ] , V_16 ) ;
F_25 ( & V_22 -> V_23 ) ;
#if V_24 == 2
V_22 = F_24 ( V_5 -> V_18 . V_19 [ 1 ] , V_16 ) ;
F_25 ( & V_22 -> V_23 ) ;
#endif
}
V_5 -> V_18 . V_25 = F_26 ( sizeof( struct V_26 ) ,
V_27 ) ;
if ( ! V_5 -> V_18 . V_25 )
goto V_28;
V_5 -> V_18 . V_29 = F_26 ( sizeof( struct V_30 ) ,
V_27 ) ;
if ( ! V_5 -> V_18 . V_29 )
goto V_31;
return 0 ;
V_31:
F_27 ( V_5 -> V_18 . V_25 ) ;
V_28:
F_28 ( ( void V_17 * * ) V_5 -> V_18 . V_19 ) ;
V_21:
return - V_32 ;
}
static struct V_4 * F_29 ( struct V_6 * V_7 )
{
struct V_4 * V_33 ;
F_30 () ;
if ( V_7 -> V_34 < V_35 )
return NULL ;
V_33 = F_26 ( sizeof( struct V_4 ) , V_27 ) ;
if ( V_33 == NULL )
return NULL ;
F_31 ( & V_33 -> V_36 ) ;
V_33 -> V_7 = V_7 ;
F_32 ( & V_33 -> V_37 ) ;
F_33 ( & V_33 -> V_8 , V_38 ,
( unsigned long ) V_33 ) ;
memcpy ( & V_33 -> V_39 , F_34 ( V_7 ) -> V_19 . V_40 , sizeof( V_33 -> V_39 ) ) ;
V_33 -> V_39 . V_41 = V_7 -> V_34 ;
V_33 -> V_39 . V_42 = NULL ;
V_33 -> V_43 = F_35 ( V_7 , & V_44 ) ;
if ( V_33 -> V_43 == NULL ) {
F_27 ( V_33 ) ;
return NULL ;
}
if ( V_33 -> V_39 . V_45 )
F_36 ( V_7 ) ;
F_37 ( V_7 ) ;
if ( F_20 ( V_33 ) < 0 ) {
F_38 ( V_46
L_1 ,
V_47 , V_7 -> V_48 ) ;
F_39 ( & V_44 , V_33 -> V_43 ) ;
F_40 ( V_7 ) ;
F_27 ( V_33 ) ;
return NULL ;
}
if ( F_41 ( V_33 ) < 0 ) {
F_38 ( V_46
L_2 ,
V_47 , V_7 -> V_48 ) ;
F_39 ( & V_44 , V_33 -> V_43 ) ;
V_33 -> V_49 = 1 ;
F_42 ( V_33 ) ;
return NULL ;
}
F_14 ( V_33 ) ;
if ( V_7 -> V_50 & ( V_51 | V_52 ) )
V_33 -> V_39 . V_53 = - 1 ;
#if F_43 ( V_54 )
if ( V_7 -> type == V_55 && ( V_7 -> V_56 & V_57 ) ) {
F_44 ( L_3 , V_7 -> V_48 ) ;
V_33 -> V_39 . V_58 = 0 ;
}
#endif
F_32 ( & V_33 -> V_59 ) ;
F_33 ( & V_33 -> V_60 , V_61 , ( unsigned long ) V_33 ) ;
if ( ( V_7 -> V_50 & V_52 ) ||
V_7 -> type == V_62 ||
V_7 -> type == V_63 ||
V_7 -> type == V_55 ||
V_7 -> type == V_64 ) {
V_33 -> V_39 . V_65 = - 1 ;
} else {
F_14 ( V_33 ) ;
V_61 ( ( unsigned long ) V_33 ) ;
}
V_33 -> V_66 = V_67 ;
if ( F_45 ( V_7 ) && F_4 ( V_7 ) )
V_33 -> V_68 |= V_69 ;
F_46 ( V_33 ) ;
V_33 -> V_70 = V_13 ;
F_2 ( V_33 ) ;
F_47 ( V_7 -> V_71 , V_33 ) ;
F_48 ( V_7 , & V_72 ) ;
F_48 ( V_7 , & V_73 ) ;
if ( V_33 -> V_39 . V_45 && ( V_7 -> V_50 & V_74 ) )
F_48 ( V_7 , & V_75 ) ;
return V_33 ;
}
static struct V_4 * F_49 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_30 () ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_29 ( V_7 ) ;
if ( ! V_5 )
return NULL ;
}
if ( V_7 -> V_50 & V_76 )
F_51 ( V_5 ) ;
return V_5 ;
}
static int F_52 ( int type )
{
int V_77 = F_53 ( sizeof( struct V_78 ) )
+ F_54 ( 4 ) ;
if ( type == - 1 || type == V_79 )
V_77 += F_54 ( 4 ) ;
#ifdef F_55
if ( type == - 1 || type == V_80 )
V_77 += F_54 ( 4 ) ;
#endif
if ( type == - 1 || type == V_81 )
V_77 += F_54 ( 4 ) ;
return V_77 ;
}
static int F_56 ( struct V_82 * V_83 , int V_84 ,
struct V_85 * V_86 , T_1 V_87 ,
T_1 V_88 , int V_89 , unsigned int V_50 ,
int type )
{
struct V_90 * V_91 ;
struct V_78 * V_92 ;
V_91 = F_57 ( V_83 , V_87 , V_88 , V_89 , sizeof( struct V_78 ) ,
V_50 ) ;
if ( V_91 == NULL )
return - V_93 ;
V_92 = F_58 ( V_91 ) ;
V_92 -> V_94 = V_95 ;
if ( F_59 ( V_83 , V_96 , V_84 ) < 0 )
goto V_97;
if ( ( type == - 1 || type == V_79 ) &&
F_59 ( V_83 , V_79 , V_86 -> V_45 ) < 0 )
goto V_97;
#ifdef F_55
if ( ( type == - 1 || type == V_80 ) &&
F_59 ( V_83 , V_80 ,
V_86 -> V_98 ) < 0 )
goto V_97;
#endif
if ( ( type == - 1 || type == V_81 ) &&
F_59 ( V_83 , V_81 , V_86 -> V_99 ) < 0 )
goto V_97;
return F_60 ( V_83 , V_91 ) ;
V_97:
F_61 ( V_83 , V_91 ) ;
return - V_93 ;
}
void F_62 ( struct V_100 * V_100 , int type , int V_84 ,
struct V_85 * V_86 )
{
struct V_82 * V_83 ;
int V_101 = - V_102 ;
V_83 = F_63 ( F_52 ( type ) , V_103 ) ;
if ( V_83 == NULL )
goto V_104;
V_101 = F_56 ( V_83 , V_84 , V_86 , 0 , 0 ,
V_105 , 0 , type ) ;
if ( V_101 < 0 ) {
F_64 ( V_101 == - V_93 ) ;
F_65 ( V_83 ) ;
goto V_104;
}
F_66 ( V_83 , V_100 , 0 , V_106 , NULL , V_103 ) ;
return;
V_104:
F_67 ( V_100 , V_106 , V_101 ) ;
}
static int F_68 ( struct V_82 * V_107 ,
struct V_90 * V_91 )
{
struct V_100 * V_100 = F_69 ( V_107 -> V_108 ) ;
struct V_109 * V_110 [ V_111 + 1 ] ;
struct V_78 * V_92 ;
struct V_82 * V_83 ;
struct V_85 * V_86 ;
struct V_4 * V_112 ;
struct V_6 * V_7 ;
int V_84 ;
int V_101 ;
V_101 = F_70 ( V_91 , sizeof( * V_92 ) , V_110 , V_111 ,
V_113 ) ;
if ( V_101 < 0 )
goto V_104;
V_101 = V_114 ;
if ( ! V_110 [ V_96 ] )
goto V_104;
V_84 = F_71 ( V_110 [ V_96 ] ) ;
switch ( V_84 ) {
case V_115 :
V_86 = V_100 -> V_19 . V_116 ;
break;
case V_117 :
V_86 = V_100 -> V_19 . V_40 ;
break;
default:
V_7 = F_72 ( V_100 , V_84 ) ;
if ( V_7 == NULL )
goto V_104;
V_112 = F_50 ( V_7 ) ;
if ( V_112 == NULL )
goto V_104;
V_86 = & V_112 -> V_39 ;
break;
}
V_101 = - V_102 ;
V_83 = F_63 ( F_52 ( - 1 ) , V_103 ) ;
if ( V_83 == NULL )
goto V_104;
V_101 = F_56 ( V_83 , V_84 , V_86 ,
F_73 ( V_107 ) . V_87 ,
V_91 -> V_118 , V_105 , 0 ,
- 1 ) ;
if ( V_101 < 0 ) {
F_64 ( V_101 == - V_93 ) ;
F_65 ( V_83 ) ;
goto V_104;
}
V_101 = F_74 ( V_83 , V_100 , F_73 ( V_107 ) . V_87 ) ;
V_104:
return V_101 ;
}
static int F_75 ( struct V_82 * V_83 ,
struct V_119 * V_120 )
{
struct V_100 * V_100 = F_69 ( V_83 -> V_108 ) ;
int V_121 , V_122 ;
int V_123 , V_124 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_125 * V_126 ;
V_122 = V_120 -> args [ 0 ] ;
V_124 = V_123 = V_120 -> args [ 1 ] ;
for ( V_121 = V_122 ; V_121 < V_127 ; V_121 ++ , V_124 = 0 ) {
V_123 = 0 ;
V_126 = & V_100 -> V_128 [ V_121 ] ;
F_76 () ;
V_120 -> V_88 = F_77 ( & V_100 -> V_19 . V_129 ) ^
V_100 -> V_130 ;
F_78 (dev, head, index_hlist) {
if ( V_123 < V_124 )
goto V_131;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
goto V_131;
if ( F_56 ( V_83 , V_7 -> V_84 ,
& V_5 -> V_39 ,
F_73 ( V_120 -> V_83 ) . V_87 ,
V_120 -> V_91 -> V_118 ,
V_105 ,
V_132 ,
- 1 ) <= 0 ) {
F_79 () ;
goto V_133;
}
F_80 ( V_120 , F_81 ( V_83 ) ) ;
V_131:
V_123 ++ ;
}
F_79 () ;
}
if ( V_121 == V_127 ) {
if ( F_56 ( V_83 , V_115 ,
V_100 -> V_19 . V_116 ,
F_73 ( V_120 -> V_83 ) . V_87 ,
V_120 -> V_91 -> V_118 ,
V_105 , V_132 ,
- 1 ) <= 0 )
goto V_133;
else
V_121 ++ ;
}
if ( V_121 == V_127 + 1 ) {
if ( F_56 ( V_83 , V_117 ,
V_100 -> V_19 . V_40 ,
F_73 ( V_120 -> V_83 ) . V_87 ,
V_120 -> V_91 -> V_118 ,
V_105 , V_132 ,
- 1 ) <= 0 )
goto V_133;
else
V_121 ++ ;
}
V_133:
V_120 -> args [ 0 ] = V_121 ;
V_120 -> args [ 1 ] = V_123 ;
return V_83 -> V_134 ;
}
static void F_82 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_135 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_39 . V_45 )
F_36 ( V_7 ) ;
if ( V_7 -> V_50 & V_74 ) {
if ( V_5 -> V_39 . V_45 ) {
F_48 ( V_7 , & V_75 ) ;
F_48 ( V_7 , & V_136 ) ;
F_48 ( V_7 , & V_137 ) ;
} else {
F_83 ( V_7 , & V_75 ) ;
F_83 ( V_7 , & V_136 ) ;
F_83 ( V_7 , & V_137 ) ;
}
}
F_84 (ifa, &idev->addr_list, if_list) {
if ( V_135 -> V_50 & V_138 )
continue;
if ( V_5 -> V_39 . V_45 )
F_85 ( V_135 ) ;
else
F_86 ( V_135 ) ;
}
F_62 ( F_34 ( V_7 ) , V_79 ,
V_7 -> V_84 , & V_5 -> V_39 ) ;
}
static void F_87 ( struct V_100 * V_100 , T_2 V_139 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_88 (net, dev) {
V_5 = F_50 ( V_7 ) ;
if ( V_5 ) {
int V_140 = ( ! V_5 -> V_39 . V_45 ) ^ ( ! V_139 ) ;
V_5 -> V_39 . V_45 = V_139 ;
if ( V_140 )
F_82 ( V_5 ) ;
}
}
}
static int F_89 ( struct V_141 * V_142 , int * V_143 , int V_139 )
{
struct V_100 * V_100 ;
int V_144 ;
if ( ! F_90 () )
return F_91 () ;
V_100 = (struct V_100 * ) V_142 -> V_145 ;
V_144 = * V_143 ;
* V_143 = V_139 ;
if ( V_143 == & V_100 -> V_19 . V_40 -> V_45 ) {
if ( ( ! V_139 ) ^ ( ! V_144 ) )
F_62 ( V_100 , V_79 ,
V_117 ,
V_100 -> V_19 . V_40 ) ;
F_92 () ;
return 0 ;
}
if ( V_143 == & V_100 -> V_19 . V_116 -> V_45 ) {
V_100 -> V_19 . V_40 -> V_45 = V_139 ;
F_87 ( V_100 , V_139 ) ;
if ( ( ! V_139 ) ^ ( ! V_144 ) )
F_62 ( V_100 , V_79 ,
V_115 ,
V_100 -> V_19 . V_116 ) ;
} else if ( ( ! V_139 ) ^ ( ! V_144 ) )
F_82 ( (struct V_4 * ) V_142 -> V_146 ) ;
F_92 () ;
if ( V_139 )
F_93 ( V_100 ) ;
return 1 ;
}
void F_94 ( struct V_9 * V_10 )
{
F_64 ( ! F_95 ( & V_10 -> V_147 ) ) ;
#ifdef F_96
F_97 ( L_4 , V_47 ) ;
#endif
F_98 ( V_10 -> V_5 ) ;
if ( F_10 ( & V_10 -> V_11 ) )
F_99 ( L_5 ,
V_10 ) ;
if ( V_10 -> V_148 != V_149 ) {
F_100 ( L_6 , V_10 ) ;
return;
}
F_101 ( V_10 -> V_150 ) ;
F_102 ( V_10 , V_151 ) ;
}
static void
F_103 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_152 * V_143 ;
int V_153 = F_104 ( & V_10 -> V_154 ) ;
F_105 (p, &idev->addr_list) {
struct V_9 * V_135
= F_106 ( V_143 , struct V_9 , V_155 ) ;
if ( V_153 >= F_104 ( & V_135 -> V_154 ) )
break;
}
F_107 ( & V_10 -> V_155 , V_143 ) ;
}
static T_1 F_108 ( const struct V_156 * V_154 )
{
return F_109 ( F_110 ( V_154 ) , V_157 ) ;
}
static struct V_9 *
F_111 ( struct V_4 * V_5 , const struct V_156 * V_154 ,
const struct V_156 * V_158 , int V_159 ,
int V_160 , T_1 V_50 , T_1 V_161 , T_1 V_162 )
{
struct V_9 * V_135 = NULL ;
struct V_163 * V_150 ;
unsigned int V_164 ;
int V_101 = 0 ;
int V_165 = F_112 ( V_154 ) ;
if ( V_165 == V_166 ||
V_165 & V_167 ||
( ! ( V_5 -> V_7 -> V_50 & V_52 ) &&
V_165 & V_168 ) )
return F_113 ( - V_169 ) ;
F_114 () ;
if ( V_5 -> V_49 ) {
V_101 = - V_170 ;
goto V_171;
}
if ( V_5 -> V_39 . V_172 ) {
V_101 = - V_173 ;
goto V_171;
}
F_115 ( & V_174 ) ;
if ( F_116 ( F_34 ( V_5 -> V_7 ) , V_154 , V_5 -> V_7 ) ) {
F_38 ( L_7 ) ;
V_101 = - V_175 ;
goto V_176;
}
V_135 = F_26 ( sizeof( struct V_9 ) , V_103 ) ;
if ( V_135 == NULL ) {
F_38 ( L_8 ) ;
V_101 = - V_102 ;
goto V_176;
}
V_150 = F_117 ( V_5 , V_154 , false ) ;
if ( F_118 ( V_150 ) ) {
V_101 = F_119 ( V_150 ) ;
goto V_176;
}
F_120 ( V_5 -> V_43 ) ;
V_135 -> V_154 = * V_154 ;
if ( V_158 )
V_135 -> V_158 = * V_158 ;
F_121 ( & V_135 -> V_36 ) ;
F_121 ( & V_135 -> V_177 ) ;
F_122 ( & V_135 -> V_11 , V_178 ) ;
F_123 ( & V_135 -> V_147 ) ;
V_135 -> V_160 = V_160 ;
V_135 -> V_179 = V_159 ;
V_135 -> V_50 = V_50 | V_138 ;
V_135 -> V_161 = V_161 ;
V_135 -> V_162 = V_162 ;
V_135 -> V_1 = V_135 -> V_70 = V_13 ;
V_135 -> V_180 = false ;
V_135 -> V_150 = V_150 ;
V_135 -> V_5 = V_5 ;
F_14 ( V_5 ) ;
F_18 ( V_135 ) ;
V_164 = F_108 ( V_154 ) ;
F_124 ( & V_135 -> V_147 , & V_181 [ V_164 ] ) ;
F_125 ( & V_174 ) ;
F_126 ( & V_5 -> V_36 ) ;
F_103 ( V_5 , V_135 ) ;
if ( V_135 -> V_50 & V_182 ) {
F_127 ( & V_135 -> V_183 , & V_5 -> V_59 ) ;
F_18 ( V_135 ) ;
}
F_18 ( V_135 ) ;
F_128 ( & V_5 -> V_36 ) ;
V_171:
F_129 () ;
if ( F_130 ( V_101 == 0 ) )
F_131 ( V_184 , V_135 ) ;
else {
F_27 ( V_135 ) ;
V_135 = F_113 ( V_101 ) ;
}
return V_135 ;
V_176:
F_125 ( & V_174 ) ;
goto V_171;
}
static enum V_185
F_132 ( struct V_9 * V_10 , unsigned long * V_186 )
{
struct V_9 * V_135 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_187 ;
enum V_185 V_188 = V_189 ;
* V_186 = V_13 ;
F_84 (ifa, &idev->addr_list, if_list) {
if ( V_135 == V_10 )
continue;
if ( ! F_133 ( & V_135 -> V_154 , & V_10 -> V_154 ,
V_10 -> V_179 ) )
continue;
if ( V_135 -> V_50 & ( V_190 | V_191 ) )
return V_192 ;
V_188 = V_193 ;
F_115 ( & V_135 -> V_36 ) ;
V_187 = F_134 ( V_135 -> V_161 , V_3 ) ;
if ( F_135 ( * V_186 , V_135 -> V_70 + V_187 * V_3 ) )
* V_186 = V_135 -> V_70 + V_187 * V_3 ;
F_125 ( & V_135 -> V_36 ) ;
}
return V_188 ;
}
static void
F_136 ( struct V_9 * V_10 , unsigned long V_186 , bool V_194 )
{
struct V_163 * V_150 ;
V_150 = F_137 ( & V_10 -> V_154 ,
V_10 -> V_179 ,
V_10 -> V_5 -> V_7 ,
0 , V_195 | V_196 ) ;
if ( V_150 ) {
if ( V_194 )
F_138 ( V_150 ) ;
else {
if ( ! ( V_150 -> V_197 & V_198 ) )
F_139 ( V_150 , V_186 ) ;
F_101 ( V_150 ) ;
}
}
}
static void F_140 ( struct V_9 * V_10 )
{
int V_148 ;
enum V_185 V_188 = V_192 ;
unsigned long V_186 ;
F_30 () ;
F_141 ( & V_10 -> V_177 ) ;
V_148 = V_10 -> V_148 ;
V_10 -> V_148 = V_149 ;
F_142 ( & V_10 -> V_177 ) ;
if ( V_148 == V_149 )
goto V_176;
F_141 ( & V_174 ) ;
F_143 ( & V_10 -> V_147 ) ;
F_142 ( & V_174 ) ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_10 -> V_50 & V_182 ) {
F_145 ( & V_10 -> V_183 ) ;
if ( V_10 -> V_199 ) {
F_146 ( V_10 -> V_199 ) ;
V_10 -> V_199 = NULL ;
}
F_11 ( V_10 ) ;
}
if ( V_10 -> V_50 & V_190 && ! ( V_10 -> V_50 & V_191 ) )
V_188 = F_132 ( V_10 , & V_186 ) ;
F_147 ( & V_10 -> V_155 ) ;
F_11 ( V_10 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
F_9 ( V_10 ) ;
F_149 ( V_200 , V_10 ) ;
F_131 ( V_201 , V_10 ) ;
if ( V_188 != V_192 ) {
F_136 ( V_10 , V_186 ,
V_188 == V_189 ) ;
}
F_150 ( V_10 ) ;
V_176:
F_146 ( V_10 ) ;
}
static int F_151 ( struct V_9 * V_10 , struct V_9 * V_202 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_156 V_154 , * V_203 ;
unsigned long V_204 , V_205 , V_206 , V_207 ;
unsigned long V_208 ;
int V_209 ;
int V_210 = 0 ;
T_1 V_211 ;
unsigned long V_212 = V_13 ;
F_144 ( & V_5 -> V_36 ) ;
if ( V_202 ) {
F_141 ( & V_202 -> V_36 ) ;
memcpy ( & V_154 . V_213 [ 8 ] , & V_202 -> V_154 . V_213 [ 8 ] , 8 ) ;
F_142 ( & V_202 -> V_36 ) ;
V_203 = & V_154 ;
} else {
V_203 = NULL ;
}
V_214:
F_14 ( V_5 ) ;
if ( V_5 -> V_39 . V_65 <= 0 ) {
F_148 ( & V_5 -> V_36 ) ;
F_44 ( L_9 , V_47 ) ;
F_98 ( V_5 ) ;
V_210 = - 1 ;
goto V_176;
}
F_141 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_215 ++ >= V_5 -> V_39 . V_216 ) {
V_5 -> V_39 . V_65 = - 1 ;
F_142 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_100 ( L_10 ,
V_47 ) ;
F_98 ( V_5 ) ;
V_210 = - 1 ;
goto V_176;
}
F_18 ( V_10 ) ;
memcpy ( V_154 . V_213 , V_10 -> V_154 . V_213 , 8 ) ;
F_152 ( V_5 , V_203 ) ;
memcpy ( & V_154 . V_213 [ 8 ] , V_5 -> V_217 , 8 ) ;
V_207 = ( V_212 - V_10 -> V_70 ) / V_3 ;
V_205 = F_153 ( V_218 ,
V_10 -> V_161 ,
V_5 -> V_39 . V_219 + V_207 ) ;
V_204 = F_153 ( V_218 ,
V_10 -> V_162 ,
V_5 -> V_39 . V_220 + V_207 -
V_5 -> V_39 . V_221 ) ;
V_209 = V_10 -> V_179 ;
V_206 = V_10 -> V_70 ;
F_142 ( & V_10 -> V_36 ) ;
V_208 = V_5 -> V_39 . V_216 *
V_5 -> V_39 . V_222 *
F_154 ( V_5 -> V_43 , V_223 ) / V_3 ;
F_148 ( & V_5 -> V_36 ) ;
V_207 = ( V_212 - V_206 + V_224 ) / V_3 ;
if ( V_204 <= V_208 + V_207 ) {
F_146 ( V_10 ) ;
F_98 ( V_5 ) ;
V_210 = - 1 ;
goto V_176;
}
V_211 = V_182 ;
if ( V_10 -> V_50 & V_225 )
V_211 |= V_225 ;
V_202 = F_111 ( V_5 , & V_154 , NULL , V_209 ,
F_155 ( & V_154 ) , V_211 ,
V_205 , V_204 ) ;
if ( F_118 ( V_202 ) ) {
F_146 ( V_10 ) ;
F_98 ( V_5 ) ;
F_44 ( L_11 , V_47 ) ;
V_203 = & V_154 ;
F_144 ( & V_5 -> V_36 ) ;
goto V_214;
}
F_141 ( & V_202 -> V_36 ) ;
V_202 -> V_199 = V_10 ;
V_202 -> V_1 = V_212 ;
V_202 -> V_70 = V_206 ;
F_142 ( & V_202 -> V_36 ) ;
F_156 ( V_202 ) ;
F_146 ( V_202 ) ;
F_98 ( V_5 ) ;
V_176:
return V_210 ;
}
static inline int F_157 ( int type )
{
if ( type & ( V_226 | V_227 | V_168 ) )
return 1 ;
return 0 ;
}
static int F_158 ( struct V_100 * V_100 ,
struct V_228 * V_229 ,
struct V_230 * V_231 ,
int V_16 )
{
int V_210 ;
if ( V_16 <= V_229 -> V_232 ) {
switch ( V_16 ) {
case V_233 :
V_210 = V_229 -> V_234 ;
break;
case V_235 :
V_210 = V_229 -> V_236 ;
break;
default:
V_210 = ! ! F_159 ( V_16 , V_229 -> V_237 ) ;
}
goto V_176;
}
switch ( V_16 ) {
case V_238 :
V_210 = ! ! V_229 -> V_135 ;
break;
case V_239 :
V_210 = F_160 ( & V_229 -> V_135 -> V_154 , V_231 -> V_154 ) ;
break;
case V_233 :
V_210 = F_161 ( V_229 -> V_165 ) ;
if ( V_210 >= V_231 -> V_160 )
V_210 = - V_210 ;
else
V_210 -= 128 ;
V_229 -> V_234 = V_210 ;
break;
case V_240 :
V_210 = F_157 ( V_229 -> V_165 ) ||
! ( V_229 -> V_135 -> V_50 & ( V_241 | V_225 ) ) ;
break;
#ifdef F_162
case V_242 :
{
int V_243 = ! ( V_231 -> V_244 & V_245 ) ;
V_210 = ! ( V_229 -> V_135 -> V_50 & V_246 ) ^ V_243 ;
break;
}
#endif
case V_247 :
V_210 = ( ! V_231 -> V_84 ||
V_231 -> V_84 == V_229 -> V_135 -> V_5 -> V_7 -> V_84 ) ;
break;
case V_248 :
V_210 = F_163 ( V_100 ,
& V_229 -> V_135 -> V_154 , V_229 -> V_165 ,
V_229 -> V_135 -> V_5 -> V_7 -> V_84 ) == V_231 -> V_249 ;
break;
case V_250 :
{
int V_251 = V_231 -> V_244 & ( V_252 | V_253 ) ?
! ! ( V_231 -> V_244 & V_253 ) :
V_229 -> V_135 -> V_5 -> V_39 . V_65 >= 2 ;
V_210 = ( ! ( V_229 -> V_135 -> V_50 & V_182 ) ) ^ V_251 ;
break;
}
case V_254 :
V_210 = ! ( F_164 ( & V_229 -> V_135 -> V_154 ) ^
F_164 ( V_231 -> V_154 ) ) ;
break;
case V_235 :
V_210 = F_165 ( & V_229 -> V_135 -> V_154 , V_231 -> V_154 ) ;
if ( V_210 > V_229 -> V_135 -> V_179 )
V_210 = V_229 -> V_135 -> V_179 ;
V_229 -> V_236 = V_210 ;
break;
default:
V_210 = 0 ;
}
if ( V_210 )
F_166 ( V_16 , V_229 -> V_237 ) ;
V_229 -> V_232 = V_16 ;
V_176:
return V_210 ;
}
int F_167 ( struct V_100 * V_100 , const struct V_6 * V_255 ,
const struct V_156 * V_256 , unsigned int V_244 ,
struct V_156 * V_257 )
{
struct V_228 V_258 [ 2 ] ,
* V_229 = & V_258 [ 0 ] , * V_259 = & V_258 [ 1 ] ;
struct V_230 V_231 ;
struct V_6 * V_7 ;
int V_260 ;
V_260 = F_168 ( V_256 ) ;
V_231 . V_154 = V_256 ;
V_231 . V_84 = V_255 ? V_255 -> V_84 : 0 ;
V_231 . V_160 = F_161 ( V_260 ) ;
V_231 . V_249 = F_163 ( V_100 , V_256 , V_260 , V_231 . V_84 ) ;
V_231 . V_244 = V_244 ;
V_259 -> V_232 = - 1 ;
V_259 -> V_135 = NULL ;
F_76 () ;
F_169 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_260 & V_167 ) ||
V_231 . V_160 <= V_261 ) &&
V_231 . V_84 && V_7 -> V_84 != V_231 . V_84 )
continue;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
continue;
F_170 ( & V_5 -> V_36 ) ;
F_84 (score->ifa, &idev->addr_list, if_list) {
int V_16 ;
if ( ( V_229 -> V_135 -> V_50 & V_138 ) &&
( ! ( V_229 -> V_135 -> V_50 & V_225 ) ) )
continue;
V_229 -> V_165 = F_168 ( & V_229 -> V_135 -> V_154 ) ;
if ( F_171 ( V_229 -> V_165 == V_166 ||
V_229 -> V_165 & V_167 ) ) {
F_172 ( V_262
L_12
L_13 ,
V_7 -> V_48 ) ;
continue;
}
V_229 -> V_232 = - 1 ;
F_173 ( V_229 -> V_237 , V_263 ) ;
for ( V_16 = 0 ; V_16 < V_263 ; V_16 ++ ) {
int V_264 , V_265 ;
V_264 = F_158 ( V_100 , V_259 , & V_231 , V_16 ) ;
V_265 = F_158 ( V_100 , V_229 , & V_231 , V_16 ) ;
if ( V_264 > V_265 ) {
if ( V_16 == V_233 &&
V_229 -> V_234 > 0 ) {
goto V_266;
}
break;
} else if ( V_264 < V_265 ) {
if ( V_259 -> V_135 )
F_146 ( V_259 -> V_135 ) ;
F_18 ( V_229 -> V_135 ) ;
F_174 ( V_259 , V_229 ) ;
V_229 -> V_135 = V_259 -> V_135 ;
break;
}
}
}
V_266:
F_175 ( & V_5 -> V_36 ) ;
}
F_79 () ;
if ( ! V_259 -> V_135 )
return - V_169 ;
* V_257 = V_259 -> V_135 -> V_154 ;
F_146 ( V_259 -> V_135 ) ;
return 0 ;
}
int F_176 ( struct V_4 * V_5 , struct V_156 * V_154 ,
T_1 V_267 )
{
struct V_9 * V_10 ;
int V_101 = - V_169 ;
F_177 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_160 > V_268 )
break;
if ( V_10 -> V_160 == V_268 &&
! ( V_10 -> V_50 & V_267 ) ) {
* V_154 = V_10 -> V_154 ;
V_101 = 0 ;
break;
}
}
return V_101 ;
}
int F_178 ( struct V_6 * V_7 , struct V_156 * V_154 ,
T_1 V_267 )
{
struct V_4 * V_5 ;
int V_101 = - V_169 ;
F_76 () ;
V_5 = F_50 ( V_7 ) ;
if ( V_5 ) {
F_170 ( & V_5 -> V_36 ) ;
V_101 = F_176 ( V_5 , V_154 , V_267 ) ;
F_175 ( & V_5 -> V_36 ) ;
}
F_79 () ;
return V_101 ;
}
static int F_179 ( struct V_4 * V_5 )
{
int V_269 = 0 ;
struct V_9 * V_10 ;
F_170 ( & V_5 -> V_36 ) ;
F_84 (ifp, &idev->addr_list, if_list)
V_269 ++ ;
F_175 ( & V_5 -> V_36 ) ;
return V_269 ;
}
int F_180 ( struct V_100 * V_100 , const struct V_156 * V_154 ,
const struct V_6 * V_7 , int V_270 )
{
struct V_9 * V_10 ;
unsigned int V_164 = F_108 ( V_154 ) ;
F_114 () ;
F_78 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_181 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( F_160 ( & V_10 -> V_154 , V_154 ) &&
! ( V_10 -> V_50 & V_138 ) &&
( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_160 & ( V_268 | V_271 ) || V_270 ) ) ) {
F_129 () ;
return 1 ;
}
}
F_129 () ;
return 0 ;
}
static bool F_116 ( struct V_100 * V_100 , const struct V_156 * V_154 ,
struct V_6 * V_7 )
{
unsigned int V_164 = F_108 ( V_154 ) ;
struct V_9 * V_10 ;
F_182 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_181 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( F_160 ( & V_10 -> V_154 , V_154 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_183 ( const struct V_156 * V_154 ,
const unsigned int V_179 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_135 ;
bool V_210 = false ;
F_76 () ;
V_5 = F_50 ( V_7 ) ;
if ( V_5 ) {
F_170 ( & V_5 -> V_36 ) ;
F_84 (ifa, &idev->addr_list, if_list) {
V_210 = F_133 ( V_154 , & V_135 -> V_154 , V_179 ) ;
if ( V_210 )
break;
}
F_175 ( & V_5 -> V_36 ) ;
}
F_79 () ;
return V_210 ;
}
int F_184 ( const struct V_156 * V_154 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_135 ;
int V_272 ;
V_272 = 0 ;
F_76 () ;
V_5 = F_50 ( V_7 ) ;
if ( V_5 ) {
F_170 ( & V_5 -> V_36 ) ;
F_84 (ifa, &idev->addr_list, if_list) {
V_272 = F_133 ( V_154 , & V_135 -> V_154 ,
V_135 -> V_179 ) ;
if ( V_272 )
break;
}
F_175 ( & V_5 -> V_36 ) ;
}
F_79 () ;
return V_272 ;
}
struct V_9 * F_185 ( struct V_100 * V_100 , const struct V_156 * V_154 ,
struct V_6 * V_7 , int V_270 )
{
struct V_9 * V_10 , * V_273 = NULL ;
unsigned int V_164 = F_108 ( V_154 ) ;
F_114 () ;
F_186 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_181 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( F_160 ( & V_10 -> V_154 , V_154 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_160 & ( V_268 | V_271 ) || V_270 ) ) {
V_273 = V_10 ;
F_18 ( V_10 ) ;
break;
}
}
}
F_129 () ;
return V_273 ;
}
static void F_187 ( struct V_9 * V_10 , int V_274 )
{
if ( V_10 -> V_50 & V_190 ) {
F_141 ( & V_10 -> V_36 ) ;
F_9 ( V_10 ) ;
V_10 -> V_50 |= V_138 ;
if ( V_274 )
V_10 -> V_50 |= V_275 ;
F_142 ( & V_10 -> V_36 ) ;
if ( V_274 )
F_149 ( 0 , V_10 ) ;
F_146 ( V_10 ) ;
} else if ( V_10 -> V_50 & V_182 ) {
struct V_9 * V_199 ;
F_141 ( & V_10 -> V_36 ) ;
V_199 = V_10 -> V_199 ;
if ( V_199 ) {
F_18 ( V_199 ) ;
F_142 ( & V_10 -> V_36 ) ;
F_151 ( V_199 , V_10 ) ;
F_146 ( V_199 ) ;
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
int V_101 = - V_276 ;
F_141 ( & V_10 -> V_177 ) ;
if ( V_10 -> V_148 == V_277 ) {
V_10 -> V_148 = V_278 ;
V_101 = 0 ;
}
F_142 ( & V_10 -> V_177 ) ;
return V_101 ;
}
void F_189 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_188 ( V_10 ) ) {
F_146 ( V_10 ) ;
return;
}
F_190 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_48 , & V_10 -> V_154 ) ;
if ( V_5 -> V_39 . V_53 > 1 && ! V_5 -> V_39 . V_172 ) {
struct V_156 V_154 ;
V_154 . V_279 [ 0 ] = F_191 ( 0xfe800000 ) ;
V_154 . V_279 [ 1 ] = 0 ;
if ( ! F_192 ( V_154 . V_213 + 8 , V_5 -> V_7 ) &&
F_160 ( & V_10 -> V_154 , & V_154 ) ) {
V_5 -> V_39 . V_172 = 1 ;
F_44 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
}
}
F_141 ( & V_10 -> V_177 ) ;
V_10 -> V_148 = V_280 ;
F_142 ( & V_10 -> V_177 ) ;
F_16 ( V_10 , 0 ) ;
}
void F_193 ( struct V_6 * V_7 , const struct V_156 * V_154 )
{
struct V_156 V_281 ;
F_30 () ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_194 ( V_154 , & V_281 ) ;
F_48 ( V_7 , & V_281 ) ;
}
void F_195 ( struct V_4 * V_5 , const struct V_156 * V_154 )
{
struct V_156 V_281 ;
F_30 () ;
if ( V_5 -> V_7 -> V_50 & ( V_52 | V_51 ) )
return;
F_194 ( V_154 , & V_281 ) ;
F_196 ( V_5 , & V_281 ) ;
}
static void F_85 ( struct V_9 * V_10 )
{
struct V_156 V_154 ;
F_30 () ;
if ( V_10 -> V_179 >= 127 )
return;
F_197 ( & V_154 , & V_10 -> V_154 , V_10 -> V_179 ) ;
if ( F_198 ( & V_154 ) )
return;
F_199 ( V_10 -> V_5 -> V_7 , & V_154 ) ;
}
static void F_86 ( struct V_9 * V_10 )
{
struct V_156 V_154 ;
F_30 () ;
if ( V_10 -> V_179 >= 127 )
return;
F_197 ( & V_154 , & V_10 -> V_154 , V_10 -> V_179 ) ;
if ( F_198 ( & V_154 ) )
return;
F_200 ( V_10 -> V_5 , & V_154 ) ;
}
static int F_201 ( T_3 * V_282 , struct V_6 * V_7 )
{
if ( V_7 -> V_283 != V_284 )
return - 1 ;
memcpy ( V_282 , V_7 -> V_285 , 3 ) ;
memcpy ( V_282 + 5 , V_7 -> V_285 + 3 , 3 ) ;
if ( V_7 -> V_286 ) {
V_282 [ 3 ] = ( V_7 -> V_286 >> 8 ) & 0xFF ;
V_282 [ 4 ] = V_7 -> V_286 & 0xFF ;
} else {
V_282 [ 3 ] = 0xFF ;
V_282 [ 4 ] = 0xFE ;
V_282 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_202 ( T_3 * V_282 , struct V_6 * V_7 )
{
if ( V_7 -> V_283 != V_287 )
return - 1 ;
memcpy ( V_282 , V_7 -> V_285 , 8 ) ;
V_282 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_203 ( T_3 * V_282 , struct V_6 * V_7 )
{
union V_288 * V_289 ;
if ( V_7 -> V_283 != V_290 )
return - 1 ;
V_289 = (union V_288 * ) V_7 -> V_285 ;
memcpy ( V_282 , & V_289 -> V_291 . V_292 , sizeof( V_289 -> V_291 . V_292 ) ) ;
V_282 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_204 ( T_3 * V_282 , struct V_6 * V_7 )
{
if ( V_7 -> V_283 != V_293 )
return - 1 ;
memset ( V_282 , 0 , 7 ) ;
V_282 [ 7 ] = * ( T_3 * ) V_7 -> V_285 ;
return 0 ;
}
static int F_205 ( T_3 * V_282 , struct V_6 * V_7 )
{
if ( V_7 -> V_283 != V_294 )
return - 1 ;
memcpy ( V_282 , V_7 -> V_285 + 12 , 8 ) ;
V_282 [ 0 ] |= 2 ;
return 0 ;
}
static int F_206 ( T_3 * V_282 , T_4 V_154 )
{
if ( V_154 == 0 )
return - 1 ;
V_282 [ 0 ] = ( F_207 ( V_154 ) || F_208 ( V_154 ) ||
F_209 ( V_154 ) || F_210 ( V_154 ) ||
F_211 ( V_154 ) || F_212 ( V_154 ) ||
F_213 ( V_154 ) || F_214 ( V_154 ) ||
F_215 ( V_154 ) || F_216 ( V_154 ) ||
F_217 ( V_154 ) ) ? 0x00 : 0x02 ;
V_282 [ 1 ] = 0 ;
V_282 [ 2 ] = 0x5E ;
V_282 [ 3 ] = 0xFE ;
memcpy ( V_282 + 4 , & V_154 , 4 ) ;
return 0 ;
}
static int F_218 ( T_3 * V_282 , struct V_6 * V_7 )
{
if ( V_7 -> V_56 & V_57 )
return F_206 ( V_282 , * ( T_4 * ) V_7 -> V_285 ) ;
return - 1 ;
}
static int F_219 ( T_3 * V_282 , struct V_6 * V_7 )
{
return F_206 ( V_282 , * ( T_4 * ) V_7 -> V_285 ) ;
}
static int F_220 ( T_3 * V_282 , struct V_6 * V_7 )
{
memcpy ( V_282 , V_7 -> V_295 , 3 ) ;
memcpy ( V_282 + 5 , V_7 -> V_295 + 3 , 3 ) ;
V_282 [ 3 ] = 0xFF ;
V_282 [ 4 ] = 0xFE ;
V_282 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_192 ( T_3 * V_282 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_296 :
case V_297 :
return F_201 ( V_282 , V_7 ) ;
case V_298 :
return F_204 ( V_282 , V_7 ) ;
case V_299 :
return F_205 ( V_282 , V_7 ) ;
case V_55 :
return F_218 ( V_282 , V_7 ) ;
case V_300 :
return F_219 ( V_282 , V_7 ) ;
case V_301 :
case V_302 :
return F_202 ( V_282 , V_7 ) ;
case V_303 :
return F_203 ( V_282 , V_7 ) ;
case V_63 :
return F_220 ( V_282 , V_7 ) ;
}
return - 1 ;
}
static int F_221 ( T_3 * V_282 , struct V_4 * V_5 )
{
int V_101 = - 1 ;
struct V_9 * V_10 ;
F_170 ( & V_5 -> V_36 ) ;
F_177 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_160 > V_268 )
break;
if ( V_10 -> V_160 == V_268 && ! ( V_10 -> V_50 & V_138 ) ) {
memcpy ( V_282 , V_10 -> V_154 . V_213 + 8 , 8 ) ;
V_101 = 0 ;
break;
}
}
F_175 ( & V_5 -> V_36 ) ;
return V_101 ;
}
static void F_222 ( struct V_4 * V_5 )
{
V_304:
F_223 ( V_5 -> V_217 , sizeof( V_5 -> V_217 ) ) ;
V_5 -> V_217 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_217 [ 0 ] == 0xfd &&
( V_5 -> V_217 [ 1 ] & V_5 -> V_217 [ 2 ] & V_5 -> V_217 [ 3 ] & V_5 -> V_217 [ 4 ] & V_5 -> V_217 [ 5 ] & V_5 -> V_217 [ 6 ] ) == 0xff &&
( V_5 -> V_217 [ 7 ] & 0x80 ) )
goto V_304;
if ( ( V_5 -> V_217 [ 0 ] | V_5 -> V_217 [ 1 ] ) == 0 ) {
if ( V_5 -> V_217 [ 2 ] == 0x5e && V_5 -> V_217 [ 3 ] == 0xfe )
goto V_304;
if ( ( V_5 -> V_217 [ 2 ] | V_5 -> V_217 [ 3 ] | V_5 -> V_217 [ 4 ] | V_5 -> V_217 [ 5 ] | V_5 -> V_217 [ 6 ] | V_5 -> V_217 [ 7 ] ) == 0x00 )
goto V_304;
}
}
static void V_61 ( unsigned long V_305 )
{
struct V_4 * V_5 = (struct V_4 * ) V_305 ;
unsigned long V_186 ;
F_114 () ;
F_144 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_49 )
goto V_176;
F_222 ( V_5 ) ;
V_186 = V_13 +
V_5 -> V_39 . V_220 * V_3 -
V_5 -> V_39 . V_216 * V_5 -> V_39 . V_222 *
F_154 ( V_5 -> V_43 , V_223 ) -
V_5 -> V_39 . V_221 * V_3 ;
if ( F_135 ( V_186 , V_13 ) ) {
F_100 ( L_16 ,
V_47 , V_5 -> V_7 -> V_48 ) ;
goto V_176;
}
if ( ! F_15 ( & V_5 -> V_60 , V_186 ) )
F_14 ( V_5 ) ;
V_176:
F_148 ( & V_5 -> V_36 ) ;
F_129 () ;
F_98 ( V_5 ) ;
}
static void F_152 ( struct V_4 * V_5 , struct V_156 * V_203 )
{
if ( V_203 && memcmp ( V_5 -> V_217 , & V_203 -> V_213 [ 8 ] , 8 ) == 0 )
F_222 ( V_5 ) ;
}
static void
F_224 ( struct V_156 * V_306 , int V_307 , struct V_6 * V_7 ,
unsigned long V_186 , T_1 V_50 )
{
struct V_308 V_309 = {
. V_310 = V_311 ,
. V_312 = V_313 ,
. V_314 = V_7 -> V_84 ,
. V_315 = V_186 ,
. V_316 = V_307 ,
. V_317 = V_318 | V_50 ,
. V_319 . V_320 = F_34 ( V_7 ) ,
. V_321 = V_322 ,
} ;
V_309 . V_323 = * V_306 ;
#if F_43 ( V_54 )
if ( V_7 -> type == V_55 && ( V_7 -> V_50 & V_324 ) )
V_309 . V_317 |= V_325 ;
#endif
F_225 ( & V_309 ) ;
}
static struct V_163 * F_137 ( const struct V_156 * V_306 ,
int V_307 ,
const struct V_6 * V_7 ,
T_1 V_50 , T_1 V_326 )
{
struct V_327 * V_328 ;
struct V_163 * V_150 = NULL ;
struct V_329 * V_142 ;
V_142 = F_226 ( F_34 ( V_7 ) , V_311 ) ;
if ( V_142 == NULL )
return NULL ;
F_170 ( & V_142 -> V_330 ) ;
V_328 = F_227 ( & V_142 -> V_331 , V_306 , V_307 , NULL , 0 ) ;
if ( ! V_328 )
goto V_176;
for ( V_150 = V_328 -> V_332 ; V_150 ; V_150 = V_150 -> V_231 . V_333 ) {
if ( V_150 -> V_231 . V_7 -> V_84 != V_7 -> V_84 )
continue;
if ( ( V_150 -> V_197 & V_50 ) != V_50 )
continue;
if ( ( V_150 -> V_197 & V_326 ) != 0 )
continue;
F_228 ( & V_150 -> V_231 ) ;
break;
}
V_176:
F_175 ( & V_142 -> V_330 ) ;
return V_150 ;
}
static void F_229 ( struct V_6 * V_7 )
{
struct V_308 V_309 = {
. V_310 = V_334 ,
. V_312 = V_313 ,
. V_314 = V_7 -> V_84 ,
. V_316 = 8 ,
. V_317 = V_318 ,
. V_319 . V_320 = F_34 ( V_7 ) ,
} ;
F_230 ( & V_309 . V_323 , F_191 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_225 ( & V_309 ) ;
}
static struct V_4 * F_231 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_30 () ;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
return F_113 ( - V_102 ) ;
if ( V_5 -> V_39 . V_172 )
return F_113 ( - V_173 ) ;
if ( ! ( V_7 -> V_50 & V_52 ) )
F_229 ( V_7 ) ;
return V_5 ;
}
static void F_232 ( struct V_4 * V_5 ,
struct V_9 * V_10 ,
V_218 V_161 , V_218 V_162 ,
bool V_335 , unsigned long V_212 )
{
T_1 V_50 ;
struct V_9 * V_202 ;
F_170 ( & V_5 -> V_36 ) ;
F_84 (ift, &idev->tempaddr_list, tmp_list) {
int V_207 , V_336 , V_337 ;
if ( V_10 != V_202 -> V_199 )
continue;
V_207 = ( V_212 - V_202 -> V_1 ) / V_3 ;
V_336 = V_5 -> V_39 . V_219 - V_207 ;
if ( V_336 < 0 )
V_336 = 0 ;
V_337 = V_5 -> V_39 . V_220 -
V_5 -> V_39 . V_221 - V_207 ;
if ( V_337 < 0 )
V_337 = 0 ;
if ( V_161 > V_336 )
V_161 = V_336 ;
if ( V_162 > V_337 )
V_162 = V_337 ;
F_115 ( & V_202 -> V_36 ) ;
V_50 = V_202 -> V_50 ;
V_202 -> V_161 = V_161 ;
V_202 -> V_162 = V_162 ;
V_202 -> V_70 = V_212 ;
if ( V_162 > 0 )
V_202 -> V_50 &= ~ V_241 ;
F_125 ( & V_202 -> V_36 ) ;
if ( ! ( V_50 & V_138 ) )
F_149 ( 0 , V_202 ) ;
}
if ( ( V_335 || F_233 ( & V_5 -> V_59 ) ) &&
V_5 -> V_39 . V_65 > 0 ) {
F_175 ( & V_5 -> V_36 ) ;
F_151 ( V_10 , NULL ) ;
} else {
F_175 ( & V_5 -> V_36 ) ;
}
}
void F_234 ( struct V_6 * V_7 , T_3 * V_338 , int V_134 , bool V_339 )
{
struct V_340 * V_341 ;
V_218 V_161 ;
V_218 V_162 ;
int V_165 ;
struct V_4 * V_112 ;
struct V_100 * V_100 = F_34 ( V_7 ) ;
V_341 = (struct V_340 * ) V_338 ;
if ( V_134 < sizeof( struct V_340 ) ) {
F_38 ( L_17 ) ;
return;
}
V_165 = F_112 ( & V_341 -> V_342 ) ;
if ( V_165 & ( V_167 | V_343 ) )
return;
V_161 = F_235 ( V_341 -> V_344 ) ;
V_162 = F_235 ( V_341 -> V_345 ) ;
if ( V_162 > V_161 ) {
F_236 ( L_18 ) ;
return;
}
V_112 = F_237 ( V_7 ) ;
if ( V_112 == NULL ) {
F_238 ( L_19 ,
V_7 -> V_48 ) ;
return;
}
if ( V_341 -> V_272 ) {
struct V_163 * V_150 ;
unsigned long V_346 ;
if ( V_3 > V_347 )
V_346 = F_134 ( V_161 , V_3 ) ;
else
V_346 = F_134 ( V_161 , V_347 ) ;
if ( F_239 ( V_346 ) )
V_346 *= V_3 ;
V_150 = F_137 ( & V_341 -> V_342 ,
V_341 -> V_179 ,
V_7 ,
V_348 | V_349 ,
V_195 | V_196 ) ;
if ( V_150 ) {
if ( V_161 == 0 ) {
F_138 ( V_150 ) ;
V_150 = NULL ;
} else if ( F_239 ( V_346 ) ) {
F_139 ( V_150 , V_13 + V_346 ) ;
} else {
F_240 ( V_150 ) ;
}
} else if ( V_161 ) {
T_5 V_186 = 0 ;
int V_50 = V_348 | V_349 ;
if ( F_239 ( V_346 ) ) {
V_50 |= V_198 ;
V_186 = F_241 ( V_346 ) ;
}
F_224 ( & V_341 -> V_342 , V_341 -> V_179 ,
V_7 , V_186 , V_50 ) ;
}
F_101 ( V_150 ) ;
}
if ( V_341 -> V_350 && V_112 -> V_39 . V_350 ) {
struct V_9 * V_10 ;
struct V_156 V_154 ;
int V_335 = 0 , V_351 = 0 ;
bool V_180 = false ;
if ( V_341 -> V_179 == 64 ) {
memcpy ( & V_154 , & V_341 -> V_342 , 8 ) ;
if ( ! F_198 ( & V_112 -> V_66 ) ) {
F_170 ( & V_112 -> V_36 ) ;
memcpy ( V_154 . V_213 + 8 ,
V_112 -> V_66 . V_213 + 8 , 8 ) ;
F_175 ( & V_112 -> V_36 ) ;
V_180 = true ;
} else if ( F_192 ( V_154 . V_213 + 8 , V_7 ) &&
F_221 ( V_154 . V_213 + 8 , V_112 ) ) {
F_98 ( V_112 ) ;
return;
}
goto V_352;
}
F_238 ( L_20 ,
V_341 -> V_179 ) ;
F_98 ( V_112 ) ;
return;
V_352:
V_10 = F_185 ( V_100 , & V_154 , V_7 , 1 ) ;
if ( V_10 == NULL && V_161 ) {
int V_353 = V_112 -> V_39 . V_353 ;
T_1 V_211 = 0 ;
#ifdef F_242
if ( V_112 -> V_39 . V_354 &&
! V_100 -> V_19 . V_116 -> V_45 && V_339 )
V_211 = V_225 ;
#endif
if ( ! V_353 ||
F_179 ( V_112 ) < V_353 )
V_10 = F_111 ( V_112 , & V_154 , NULL ,
V_341 -> V_179 ,
V_165 & V_355 ,
V_211 , V_161 ,
V_162 ) ;
if ( F_243 ( V_10 ) ) {
F_98 ( V_112 ) ;
return;
}
V_351 = 0 ;
V_335 = 1 ;
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 |= V_356 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_180 = V_180 ;
F_142 ( & V_10 -> V_36 ) ;
F_156 ( V_10 ) ;
}
if ( V_10 ) {
T_1 V_50 ;
unsigned long V_212 ;
T_1 V_357 ;
F_115 ( & V_10 -> V_36 ) ;
V_212 = V_13 ;
if ( V_10 -> V_161 > ( V_212 - V_10 -> V_70 ) / V_3 )
V_357 = V_10 -> V_161 - ( V_212 - V_10 -> V_70 ) / V_3 ;
else
V_357 = 0 ;
if ( ! V_351 && ! V_335 && V_357 ) {
const T_1 V_358 = F_244 (
V_357 , ( T_1 ) V_359 ) ;
V_161 = F_245 ( V_161 , V_358 ) ;
V_351 = 1 ;
}
if ( V_351 ) {
V_10 -> V_161 = V_161 ;
V_10 -> V_162 = V_162 ;
V_10 -> V_70 = V_212 ;
V_50 = V_10 -> V_50 ;
V_10 -> V_50 &= ~ V_241 ;
F_125 ( & V_10 -> V_36 ) ;
if ( ! ( V_50 & V_138 ) )
F_149 ( 0 , V_10 ) ;
} else
F_125 ( & V_10 -> V_36 ) ;
F_232 ( V_112 , V_10 , V_161 , V_162 ,
V_335 , V_212 ) ;
F_146 ( V_10 ) ;
F_246 () ;
}
}
F_247 ( V_360 , V_112 , V_341 ) ;
F_98 ( V_112 ) ;
}
int F_248 ( struct V_100 * V_100 , void T_6 * V_361 )
{
struct V_362 V_363 ;
struct V_6 * V_7 ;
int V_101 = - V_114 ;
F_249 () ;
V_101 = - V_364 ;
if ( F_250 ( & V_363 , V_361 , sizeof( struct V_362 ) ) )
goto V_365;
V_7 = F_72 ( V_100 , V_363 . V_366 ) ;
V_101 = - V_170 ;
if ( V_7 == NULL )
goto V_365;
#if F_43 ( V_54 )
if ( V_7 -> type == V_55 ) {
const struct V_367 * V_368 = V_7 -> V_369 ;
struct V_370 V_371 ;
struct V_372 V_143 ;
V_101 = - V_169 ;
if ( ! ( F_112 ( & V_363 . V_373 ) & V_227 ) )
goto V_365;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_374 . V_256 = V_363 . V_373 . V_279 [ 3 ] ;
V_143 . V_374 . V_257 = 0 ;
V_143 . V_374 . V_375 = 4 ;
V_143 . V_374 . V_376 = 5 ;
V_143 . V_374 . V_377 = V_378 ;
V_143 . V_374 . V_379 = 64 ;
V_371 . V_380 . V_381 = ( V_382 void T_6 * ) & V_143 ;
if ( V_368 -> V_383 ) {
T_7 V_384 = F_251 () ;
F_252 ( V_385 ) ;
V_101 = V_368 -> V_383 ( V_7 , & V_371 , V_386 ) ;
F_252 ( V_384 ) ;
} else
V_101 = - V_387 ;
if ( V_101 == 0 ) {
V_101 = - V_102 ;
V_7 = F_253 ( V_100 , V_143 . V_48 ) ;
if ( ! V_7 )
goto V_365;
V_101 = F_254 ( V_7 ) ;
}
}
#endif
V_365:
F_92 () ;
return V_101 ;
}
static int F_255 ( struct V_100 * V_100 , int V_84 ,
const struct V_156 * V_306 ,
const struct V_156 * V_388 ,
unsigned int V_307 , V_218 V_389 ,
V_218 V_162 , V_218 V_161 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_160 ;
T_1 V_50 ;
T_5 V_186 ;
unsigned long V_390 ;
F_30 () ;
if ( V_307 > 128 )
return - V_114 ;
if ( ! V_161 || V_162 > V_161 )
return - V_114 ;
if ( V_389 & V_356 && V_307 != 64 )
return - V_114 ;
V_7 = F_72 ( V_100 , V_84 ) ;
if ( ! V_7 )
return - V_170 ;
V_5 = F_231 ( V_7 ) ;
if ( F_118 ( V_5 ) )
return F_119 ( V_5 ) ;
V_160 = F_155 ( V_306 ) ;
V_390 = F_134 ( V_161 , V_3 ) ;
if ( F_239 ( V_390 ) ) {
V_186 = F_241 ( V_390 * V_3 ) ;
V_161 = V_390 ;
V_50 = V_198 ;
} else {
V_186 = 0 ;
V_50 = 0 ;
V_389 |= V_190 ;
}
V_390 = F_134 ( V_162 , V_3 ) ;
if ( F_239 ( V_390 ) ) {
if ( V_390 == 0 )
V_389 |= V_241 ;
V_162 = V_390 ;
}
V_10 = F_111 ( V_5 , V_306 , V_388 , V_307 , V_160 , V_389 ,
V_161 , V_162 ) ;
if ( ! F_118 ( V_10 ) ) {
if ( ! ( V_389 & V_191 ) ) {
F_224 ( & V_10 -> V_154 , V_10 -> V_179 , V_7 ,
V_186 , V_50 ) ;
}
F_156 ( V_10 ) ;
if ( V_389 & V_356 )
F_232 ( V_5 , V_10 , V_161 , V_162 ,
true , V_13 ) ;
F_146 ( V_10 ) ;
F_256 () ;
return 0 ;
}
return F_119 ( V_10 ) ;
}
static int F_257 ( struct V_100 * V_100 , int V_84 , const struct V_156 * V_306 ,
unsigned int V_307 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_307 > 128 )
return - V_114 ;
V_7 = F_72 ( V_100 , V_84 ) ;
if ( ! V_7 )
return - V_170 ;
if ( ( V_5 = F_50 ( V_7 ) ) == NULL )
return - V_391 ;
F_170 ( & V_5 -> V_36 ) ;
F_84 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_179 == V_307 &&
F_160 ( V_306 , & V_10 -> V_154 ) ) {
F_18 ( V_10 ) ;
F_175 ( & V_5 -> V_36 ) ;
F_140 ( V_10 ) ;
return 0 ;
}
}
F_175 ( & V_5 -> V_36 ) ;
return - V_169 ;
}
int F_258 ( struct V_100 * V_100 , void T_6 * V_361 )
{
struct V_362 V_363 ;
int V_101 ;
if ( ! F_259 ( V_100 -> V_392 , V_393 ) )
return - V_394 ;
if ( F_250 ( & V_363 , V_361 , sizeof( struct V_362 ) ) )
return - V_364 ;
F_249 () ;
V_101 = F_255 ( V_100 , V_363 . V_366 , & V_363 . V_373 , NULL ,
V_363 . V_395 , V_190 ,
V_396 , V_396 ) ;
F_92 () ;
return V_101 ;
}
int F_260 ( struct V_100 * V_100 , void T_6 * V_361 )
{
struct V_362 V_363 ;
int V_101 ;
if ( ! F_259 ( V_100 -> V_392 , V_393 ) )
return - V_394 ;
if ( F_250 ( & V_363 , V_361 , sizeof( struct V_362 ) ) )
return - V_364 ;
F_249 () ;
V_101 = F_257 ( V_100 , V_363 . V_366 , & V_363 . V_373 ,
V_363 . V_395 ) ;
F_92 () ;
return V_101 ;
}
static void F_261 ( struct V_4 * V_5 , const struct V_156 * V_154 ,
int V_307 , int V_160 )
{
struct V_9 * V_10 ;
V_10 = F_111 ( V_5 , V_154 , NULL , V_307 ,
V_160 , V_190 ,
V_396 , V_396 ) ;
if ( ! F_118 ( V_10 ) ) {
F_141 ( & V_10 -> V_36 ) ;
V_10 -> V_50 &= ~ V_138 ;
F_142 ( & V_10 -> V_36 ) ;
F_149 ( V_397 , V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_262 ( struct V_4 * V_5 )
{
struct V_156 V_154 ;
struct V_6 * V_7 ;
struct V_100 * V_100 = F_34 ( V_5 -> V_7 ) ;
int V_160 , V_307 ;
T_1 V_398 = 0 ;
F_30 () ;
memset ( & V_154 , 0 , sizeof( struct V_156 ) ) ;
memcpy ( & V_154 . V_279 [ 3 ] , V_5 -> V_7 -> V_285 , 4 ) ;
if ( V_5 -> V_7 -> V_50 & V_324 ) {
V_154 . V_279 [ 0 ] = F_191 ( 0xfe800000 ) ;
V_160 = V_268 ;
V_307 = 64 ;
} else {
V_160 = V_227 ;
V_307 = 96 ;
V_398 |= V_325 ;
}
if ( V_154 . V_279 [ 3 ] ) {
F_261 ( V_5 , & V_154 , V_307 , V_160 ) ;
F_224 ( & V_154 , V_307 , V_5 -> V_7 , 0 , V_398 ) ;
return;
}
F_88 (net, dev) {
struct V_399 * V_400 = F_263 ( V_7 ) ;
if ( V_400 && ( V_7 -> V_50 & V_76 ) ) {
struct V_401 * V_135 ;
int V_402 = V_160 ;
for ( V_135 = V_400 -> V_403 ; V_135 ; V_135 = V_135 -> V_404 ) {
V_154 . V_279 [ 3 ] = V_135 -> V_405 ;
if ( V_135 -> V_406 == V_407 )
continue;
if ( V_135 -> V_406 >= V_408 ) {
if ( V_5 -> V_7 -> V_50 & V_324 )
continue;
V_402 |= V_271 ;
}
F_261 ( V_5 , & V_154 , V_307 , V_402 ) ;
F_224 ( & V_154 , V_307 , V_5 -> V_7 , 0 ,
V_398 ) ;
}
}
}
}
static void F_264 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_409 ;
struct V_9 * V_410 ;
struct V_163 * V_411 ;
F_30 () ;
if ( ( V_5 = F_49 ( V_7 ) ) == NULL ) {
F_97 ( L_21 , V_47 ) ;
return;
}
F_261 ( V_5 , & V_412 , 128 , V_271 ) ;
F_88 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_409 -> V_48 , V_7 -> V_48 ) )
continue;
V_5 = F_50 ( V_409 ) ;
if ( ! V_5 )
continue;
F_170 ( & V_5 -> V_36 ) ;
F_84 (sp_ifa, &idev->addr_list, if_list) {
if ( V_410 -> V_50 & ( V_275 | V_138 ) )
continue;
if ( V_410 -> V_150 ) {
if ( V_410 -> V_150 -> V_231 . V_413 > 0 ) {
F_101 ( V_410 -> V_150 ) ;
V_410 -> V_150 = NULL ;
} else {
continue;
}
}
V_411 = F_117 ( V_5 , & V_410 -> V_154 , false ) ;
if ( ! F_118 ( V_411 ) ) {
V_410 -> V_150 = V_411 ;
F_265 ( V_411 ) ;
}
}
F_175 ( & V_5 -> V_36 ) ;
}
}
static void F_266 ( struct V_4 * V_5 , const struct V_156 * V_154 )
{
struct V_9 * V_10 ;
T_1 V_211 = V_190 ;
#ifdef F_242
if ( V_5 -> V_39 . V_354 &&
! F_34 ( V_5 -> V_7 ) -> V_19 . V_116 -> V_45 )
V_211 |= V_225 ;
#endif
V_10 = F_111 ( V_5 , V_154 , NULL , 64 , V_268 , V_211 ,
V_396 , V_396 ) ;
if ( ! F_118 ( V_10 ) ) {
F_224 ( & V_10 -> V_154 , V_10 -> V_179 , V_5 -> V_7 , 0 , 0 ) ;
F_156 ( V_10 ) ;
F_146 ( V_10 ) ;
}
}
static void F_267 ( struct V_6 * V_7 )
{
struct V_156 V_154 ;
struct V_4 * V_5 ;
F_30 () ;
if ( ( V_7 -> type != V_296 ) &&
( V_7 -> type != V_297 ) &&
( V_7 -> type != V_298 ) &&
( V_7 -> type != V_299 ) &&
( V_7 -> type != V_302 ) &&
( V_7 -> type != V_303 ) &&
( V_7 -> type != V_63 ) &&
( V_7 -> type != V_301 ) ) {
return;
}
V_5 = F_231 ( V_7 ) ;
if ( F_118 ( V_5 ) )
return;
memset ( & V_154 , 0 , sizeof( struct V_156 ) ) ;
V_154 . V_279 [ 0 ] = F_191 ( 0xFE800000 ) ;
if ( F_192 ( V_154 . V_213 + 8 , V_7 ) == 0 )
F_266 ( V_5 , & V_154 ) ;
}
static void F_268 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_30 () ;
if ( ( V_5 = F_49 ( V_7 ) ) == NULL ) {
F_97 ( L_21 , V_47 ) ;
return;
}
if ( V_7 -> V_56 & V_57 ) {
struct V_156 V_154 ;
F_230 ( & V_154 , F_191 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( ! F_192 ( V_154 . V_213 + 8 , V_7 ) )
F_266 ( V_5 , & V_154 ) ;
return;
}
F_262 ( V_5 ) ;
if ( V_7 -> V_50 & V_324 )
F_229 ( V_7 ) ;
}
static void F_269 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_156 V_154 ;
F_30 () ;
if ( ( V_5 = F_49 ( V_7 ) ) == NULL ) {
F_97 ( L_21 , V_47 ) ;
return;
}
F_230 ( & V_154 , F_191 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( ! F_192 ( V_154 . V_213 + 8 , V_7 ) )
F_266 ( V_5 , & V_154 ) ;
else
F_224 ( & V_154 , 64 , V_7 , 0 , 0 ) ;
}
static inline int
F_270 ( struct V_4 * V_5 , struct V_6 * V_414 )
{
struct V_156 V_415 ;
if ( ! F_178 ( V_414 , & V_415 , V_138 ) ) {
F_266 ( V_5 , & V_415 ) ;
return 0 ;
}
return - 1 ;
}
static int F_271 ( struct V_416 * V_417 , unsigned long V_89 ,
void * V_418 )
{
struct V_6 * V_7 = F_272 ( V_418 ) ;
struct V_4 * V_5 = F_50 ( V_7 ) ;
int V_419 = 0 ;
int V_101 ;
switch ( V_89 ) {
case V_420 :
if ( ! V_5 && V_7 -> V_34 >= V_35 ) {
V_5 = F_29 ( V_7 ) ;
if ( ! V_5 )
return F_273 ( - V_32 ) ;
}
break;
case V_184 :
case V_421 :
if ( V_7 -> V_50 & V_422 )
break;
if ( V_89 == V_184 ) {
if ( ! F_4 ( V_7 ) ) {
F_44 ( L_22 ,
V_7 -> V_48 ) ;
break;
}
if ( ! V_5 && V_7 -> V_34 >= V_35 )
V_5 = F_29 ( V_7 ) ;
if ( V_5 ) {
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
F_44 ( L_23 ,
V_7 -> V_48 ) ;
V_419 = 1 ;
}
switch ( V_7 -> type ) {
#if F_43 ( V_54 )
case V_55 :
F_268 ( V_7 ) ;
break;
#endif
#if F_43 ( V_423 )
case V_300 :
F_269 ( V_7 ) ;
break;
#endif
case V_424 :
F_264 ( V_7 ) ;
break;
default:
F_267 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_419 )
F_274 ( V_5 ) ;
if ( V_5 -> V_39 . V_41 != V_7 -> V_34 &&
V_7 -> V_34 >= V_35 ) {
F_275 ( V_7 , V_7 -> V_34 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_34 ;
}
V_5 -> V_70 = V_13 ;
F_276 ( V_425 , V_5 ) ;
if ( V_7 -> V_34 < V_35 )
F_277 ( V_7 , 1 ) ;
}
break;
case V_426 :
if ( V_5 && V_7 -> V_34 >= V_35 ) {
F_275 ( V_7 , V_7 -> V_34 ) ;
V_5 -> V_39 . V_41 = V_7 -> V_34 ;
break;
}
if ( ! V_5 && V_7 -> V_34 >= V_35 ) {
V_5 = F_29 ( V_7 ) ;
if ( V_5 )
break;
}
case V_201 :
case V_427 :
F_277 ( V_7 , V_89 != V_201 ) ;
break;
case V_428 :
if ( V_5 ) {
F_278 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_101 = F_41 ( V_5 ) ;
if ( V_101 )
return F_273 ( V_101 ) ;
}
break;
case V_429 :
case V_430 :
F_279 ( V_7 , V_89 ) ;
break;
}
return V_431 ;
}
static void F_279 ( struct V_6 * V_7 , unsigned long V_89 )
{
struct V_4 * V_5 ;
F_30 () ;
V_5 = F_50 ( V_7 ) ;
if ( V_89 == V_430 )
F_280 ( V_5 ) ;
else if ( V_89 == V_429 )
F_281 ( V_5 ) ;
}
static int F_277 ( struct V_6 * V_7 , int V_432 )
{
struct V_100 * V_100 = F_34 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_135 ;
int V_148 , V_16 ;
F_30 () ;
F_282 ( V_100 , V_7 ) ;
F_283 ( & V_44 , V_7 ) ;
V_5 = F_50 ( V_7 ) ;
if ( V_5 == NULL )
return - V_170 ;
if ( V_432 ) {
V_5 -> V_49 = 1 ;
F_284 ( V_7 -> V_71 , NULL ) ;
F_278 ( V_5 ) ;
}
for ( V_16 = 0 ; V_16 < V_433 ; V_16 ++ ) {
struct V_125 * V_121 = & V_181 [ V_16 ] ;
F_141 ( & V_174 ) ;
V_434:
F_78 (ifa, h, addr_lst) {
if ( V_135 -> V_5 == V_5 ) {
F_143 ( & V_135 -> V_147 ) ;
F_9 ( V_135 ) ;
goto V_434;
}
}
F_142 ( & V_174 ) ;
}
F_144 ( & V_5 -> V_36 ) ;
F_6 ( V_5 ) ;
if ( ! V_432 )
V_5 -> V_68 &= ~ ( V_435 | V_436 | V_69 ) ;
if ( V_432 && F_7 ( & V_5 -> V_60 ) )
F_98 ( V_5 ) ;
while ( ! F_233 ( & V_5 -> V_59 ) ) {
V_135 = F_285 ( & V_5 -> V_59 ,
struct V_9 , V_183 ) ;
F_145 ( & V_135 -> V_183 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_141 ( & V_135 -> V_36 ) ;
if ( V_135 -> V_199 ) {
F_146 ( V_135 -> V_199 ) ;
V_135 -> V_199 = NULL ;
}
F_142 ( & V_135 -> V_36 ) ;
F_146 ( V_135 ) ;
F_144 ( & V_5 -> V_36 ) ;
}
while ( ! F_233 ( & V_5 -> V_37 ) ) {
V_135 = F_285 ( & V_5 -> V_37 ,
struct V_9 , V_155 ) ;
F_9 ( V_135 ) ;
F_145 ( & V_135 -> V_155 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_141 ( & V_135 -> V_177 ) ;
V_148 = V_135 -> V_148 ;
V_135 -> V_148 = V_149 ;
F_142 ( & V_135 -> V_177 ) ;
if ( V_148 != V_149 ) {
F_286 ( V_200 , V_135 ) ;
F_131 ( V_201 , V_135 ) ;
}
F_146 ( V_135 ) ;
F_144 ( & V_5 -> V_36 ) ;
}
F_148 ( & V_5 -> V_36 ) ;
if ( V_432 )
F_287 ( V_5 ) ;
else
F_288 ( V_5 ) ;
V_5 -> V_70 = V_13 ;
if ( V_432 ) {
F_3 ( V_5 ) ;
F_39 ( & V_44 , V_5 -> V_43 ) ;
F_283 ( & V_44 , V_7 ) ;
F_98 ( V_5 ) ;
}
return 0 ;
}
static void V_38 ( unsigned long V_305 )
{
struct V_4 * V_5 = (struct V_4 * ) V_305 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_156 V_415 ;
F_126 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_49 || ! ( V_5 -> V_68 & V_69 ) )
goto V_176;
if ( ! F_289 ( V_5 ) )
goto V_176;
if ( V_5 -> V_68 & V_436 )
goto V_176;
if ( V_5 -> V_437 ++ < V_5 -> V_39 . V_58 ) {
F_128 ( & V_5 -> V_36 ) ;
if ( ! F_178 ( V_7 , & V_415 , V_138 ) )
F_290 ( V_7 , & V_415 ,
& V_75 ) ;
else
goto V_438;
F_126 ( & V_5 -> V_36 ) ;
F_12 ( V_5 , ( V_5 -> V_437 ==
V_5 -> V_39 . V_58 ) ?
V_5 -> V_39 . V_439 :
V_5 -> V_39 . V_440 ) ;
} else {
F_97 ( L_24 , V_5 -> V_7 -> V_48 ) ;
}
V_176:
F_128 ( & V_5 -> V_36 ) ;
V_438:
F_98 ( V_5 ) ;
}
static void F_291 ( struct V_9 * V_10 )
{
unsigned long V_441 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_50 & V_225 )
V_441 = 0 ;
else
V_441 = F_292 () % ( V_5 -> V_39 . V_439 ? : 1 ) ;
V_10 -> V_442 = V_5 -> V_39 . V_222 ;
F_16 ( V_10 , V_441 ) ;
}
static void F_293 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_193 ( V_7 , & V_10 -> V_154 ) ;
F_294 ( ( V_382 T_1 ) V_10 -> V_154 . V_279 [ 3 ] ) ;
F_170 ( & V_5 -> V_36 ) ;
F_115 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_148 == V_149 )
goto V_176;
if ( V_7 -> V_50 & ( V_51 | V_52 ) ||
V_5 -> V_39 . V_53 < 1 ||
! ( V_10 -> V_50 & V_138 ) ||
V_10 -> V_50 & V_443 ) {
V_10 -> V_50 &= ~ ( V_138 | V_225 | V_275 ) ;
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
if ( V_10 -> V_50 & V_225 )
F_265 ( V_10 -> V_150 ) ;
F_291 ( V_10 ) ;
V_176:
F_125 ( & V_10 -> V_36 ) ;
F_175 ( & V_5 -> V_36 ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
bool V_444 = false ;
F_141 ( & V_10 -> V_177 ) ;
if ( V_10 -> V_148 != V_149 ) {
V_10 -> V_148 = V_445 ;
V_444 = true ;
}
F_142 ( & V_10 -> V_177 ) ;
if ( V_444 )
F_16 ( V_10 , 0 ) ;
}
static void V_178 ( struct V_446 * V_447 )
{
struct V_9 * V_10 = F_296 ( F_297 ( V_447 ) ,
struct V_9 ,
V_11 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_156 V_448 ;
enum {
V_449 ,
V_450 ,
V_451 ,
} V_188 = V_449 ;
F_249 () ;
F_141 ( & V_10 -> V_177 ) ;
if ( V_10 -> V_148 == V_445 ) {
V_188 = V_450 ;
V_10 -> V_148 = V_277 ;
} else if ( V_10 -> V_148 == V_280 ) {
V_188 = V_451 ;
V_10 -> V_148 = V_278 ;
}
F_142 ( & V_10 -> V_177 ) ;
if ( V_188 == V_450 ) {
F_293 ( V_10 ) ;
goto V_176;
} else if ( V_188 == V_451 ) {
F_187 ( V_10 , 1 ) ;
goto V_176;
}
if ( ! V_10 -> V_442 && F_188 ( V_10 ) )
goto V_176;
F_144 ( & V_5 -> V_36 ) ;
if ( V_5 -> V_49 || ! ( V_5 -> V_68 & V_69 ) ) {
F_148 ( & V_5 -> V_36 ) ;
goto V_176;
}
F_115 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_148 == V_149 ) {
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
goto V_176;
}
if ( V_10 -> V_442 == 0 ) {
V_10 -> V_50 &= ~ ( V_138 | V_225 | V_275 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_295 ( V_10 ) ;
goto V_176;
}
V_10 -> V_442 -- ;
F_16 ( V_10 ,
F_154 ( V_10 -> V_5 -> V_43 , V_223 ) ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_5 -> V_36 ) ;
F_194 ( & V_10 -> V_154 , & V_448 ) ;
F_298 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_154 , & V_448 , & V_67 ) ;
V_176:
F_146 ( V_10 ) ;
F_92 () ;
}
static bool F_299 ( struct V_9 * V_10 )
{
struct V_9 * V_452 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_177 (ifpiter, &idev->addr_list, if_list) {
if ( V_452 -> V_160 > V_268 )
break;
if ( V_10 != V_452 && V_452 -> V_160 == V_268 &&
( V_452 -> V_50 & ( V_190 | V_138 |
V_225 | V_275 ) ) ==
V_190 )
return false ;
}
return true ;
}
static void F_295 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_156 V_415 ;
bool V_453 , V_454 ;
F_9 ( V_10 ) ;
F_149 ( V_397 , V_10 ) ;
F_170 ( & V_10 -> V_5 -> V_36 ) ;
V_454 = V_10 -> V_160 == V_268 && F_299 ( V_10 ) ;
V_453 = V_454 &&
F_289 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_39 . V_58 > 0 &&
( V_7 -> V_50 & V_52 ) == 0 ;
F_175 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_454 )
F_300 ( V_10 -> V_5 ) ;
if ( V_453 ) {
if ( F_178 ( V_7 , & V_415 , V_138 ) )
return;
F_290 ( V_7 , & V_415 , & V_75 ) ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
F_115 ( & V_10 -> V_36 ) ;
V_10 -> V_5 -> V_437 = 1 ;
V_10 -> V_5 -> V_68 |= V_435 ;
F_12 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_39 . V_440 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
}
}
static void F_274 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_170 ( & V_5 -> V_36 ) ;
F_84 (ifp, &idev->addr_list, if_list) {
F_115 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_50 & V_138 &&
V_10 -> V_148 == V_277 )
F_291 ( V_10 ) ;
F_125 ( & V_10 -> V_36 ) ;
}
F_175 ( & V_5 -> V_36 ) ;
}
static struct V_9 * F_301 ( struct V_455 * V_88 , T_8 V_456 )
{
struct V_9 * V_135 = NULL ;
struct V_457 * V_148 = V_88 -> V_458 ;
struct V_100 * V_100 = F_302 ( V_88 ) ;
int V_143 = 0 ;
if ( V_456 == 0 ) {
V_148 -> V_459 = 0 ;
V_148 -> V_460 = 0 ;
}
for (; V_148 -> V_459 < V_433 ; ++ V_148 -> V_459 ) {
F_186 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_181 ( F_34 ( V_135 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( V_143 < V_148 -> V_460 ) {
V_143 ++ ;
continue;
}
V_148 -> V_460 ++ ;
return V_135 ;
}
V_148 -> V_460 = 0 ;
V_143 = 0 ;
}
return NULL ;
}
static struct V_9 * F_303 ( struct V_455 * V_88 ,
struct V_9 * V_135 )
{
struct V_457 * V_148 = V_88 -> V_458 ;
struct V_100 * V_100 = F_302 ( V_88 ) ;
F_304 (ifa, addr_lst) {
if ( ! F_181 ( F_34 ( V_135 -> V_5 -> V_7 ) , V_100 ) )
continue;
V_148 -> V_460 ++ ;
return V_135 ;
}
while ( ++ V_148 -> V_459 < V_433 ) {
V_148 -> V_460 = 0 ;
F_186 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_181 ( F_34 ( V_135 -> V_5 -> V_7 ) , V_100 ) )
continue;
V_148 -> V_460 ++ ;
return V_135 ;
}
}
return NULL ;
}
static void * F_305 ( struct V_455 * V_88 , T_8 * V_456 )
__acquires( T_9 )
{
F_114 () ;
return F_301 ( V_88 , * V_456 ) ;
}
static void * F_306 ( struct V_455 * V_88 , void * V_461 , T_8 * V_456 )
{
struct V_9 * V_135 ;
V_135 = F_303 ( V_88 , V_461 ) ;
++ * V_456 ;
return V_135 ;
}
static void F_307 ( struct V_455 * V_88 , void * V_461 )
__releases( T_9 )
{
F_129 () ;
}
static int F_308 ( struct V_455 * V_88 , void * V_461 )
{
struct V_9 * V_10 = (struct V_9 * ) V_461 ;
F_309 ( V_88 , L_25 ,
& V_10 -> V_154 ,
V_10 -> V_5 -> V_7 -> V_84 ,
V_10 -> V_179 ,
V_10 -> V_160 ,
( T_3 ) V_10 -> V_50 ,
V_10 -> V_5 -> V_7 -> V_48 ) ;
return 0 ;
}
static int F_310 ( struct V_462 * V_462 , struct V_463 * V_463 )
{
return F_311 ( V_462 , V_463 , & V_464 ,
sizeof( struct V_457 ) ) ;
}
static int T_10 F_312 ( struct V_100 * V_100 )
{
if ( ! F_313 ( L_26 , V_465 , V_100 -> V_466 , & V_467 ) )
return - V_32 ;
return 0 ;
}
static void T_11 F_314 ( struct V_100 * V_100 )
{
F_315 ( L_26 , V_100 -> V_466 ) ;
}
int T_12 F_316 ( void )
{
return F_317 ( & V_468 ) ;
}
void F_318 ( void )
{
F_319 ( & V_468 ) ;
}
int F_320 ( struct V_100 * V_100 , const struct V_156 * V_154 )
{
int V_210 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_164 = F_108 ( V_154 ) ;
F_114 () ;
F_186 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_181 ( F_34 ( V_10 -> V_5 -> V_7 ) , V_100 ) )
continue;
if ( F_160 ( & V_10 -> V_154 , V_154 ) &&
( V_10 -> V_50 & V_246 ) ) {
V_210 = 1 ;
break;
}
}
F_129 () ;
return V_210 ;
}
static void F_256 ( void )
{
unsigned long V_212 , V_469 , V_470 , V_471 ;
struct V_9 * V_10 ;
int V_16 ;
F_30 () ;
F_114 () ;
V_212 = V_13 ;
V_469 = F_321 ( V_212 + V_472 ) ;
F_10 ( & V_473 ) ;
for ( V_16 = 0 ; V_16 < V_433 ; V_16 ++ ) {
V_434:
F_186 (ifp, &inet6_addr_lst[i], addr_lst) {
unsigned long V_207 ;
if ( ( V_10 -> V_50 & V_190 ) &&
( V_10 -> V_162 == V_396 ) )
continue;
F_115 ( & V_10 -> V_36 ) ;
V_207 = ( V_212 - V_10 -> V_70 + V_224 ) / V_3 ;
if ( V_10 -> V_161 != V_396 &&
V_207 >= V_10 -> V_161 ) {
F_125 ( & V_10 -> V_36 ) ;
F_18 ( V_10 ) ;
F_140 ( V_10 ) ;
goto V_434;
} else if ( V_10 -> V_162 == V_396 ) {
F_125 ( & V_10 -> V_36 ) ;
continue;
} else if ( V_207 >= V_10 -> V_162 ) {
int V_474 = 0 ;
if ( ! ( V_10 -> V_50 & V_241 ) ) {
V_474 = 1 ;
V_10 -> V_50 |= V_241 ;
}
if ( ( V_10 -> V_161 != V_396 ) &&
( F_135 ( V_10 -> V_70 + V_10 -> V_161 * V_3 , V_469 ) ) )
V_469 = V_10 -> V_70 + V_10 -> V_161 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
if ( V_474 ) {
F_18 ( V_10 ) ;
F_149 ( 0 , V_10 ) ;
F_146 ( V_10 ) ;
goto V_434;
}
} else if ( ( V_10 -> V_50 & V_182 ) &&
! ( V_10 -> V_50 & V_138 ) ) {
unsigned long V_208 = V_10 -> V_5 -> V_39 . V_216 *
V_10 -> V_5 -> V_39 . V_222 *
F_154 ( V_10 -> V_5 -> V_43 , V_223 ) / V_3 ;
if ( V_207 >= V_10 -> V_162 - V_208 ) {
struct V_9 * V_199 = V_10 -> V_199 ;
if ( F_135 ( V_10 -> V_70 + V_10 -> V_162 * V_3 , V_469 ) )
V_469 = V_10 -> V_70 + V_10 -> V_162 * V_3 ;
if ( ! V_10 -> V_215 && V_199 ) {
V_10 -> V_215 ++ ;
F_18 ( V_10 ) ;
F_18 ( V_199 ) ;
F_125 ( & V_10 -> V_36 ) ;
F_115 ( & V_199 -> V_36 ) ;
V_199 -> V_215 = 0 ;
F_125 ( & V_199 -> V_36 ) ;
F_151 ( V_199 , V_10 ) ;
F_146 ( V_199 ) ;
F_146 ( V_10 ) ;
goto V_434;
}
} else if ( F_135 ( V_10 -> V_70 + V_10 -> V_162 * V_3 - V_208 * V_3 , V_469 ) )
V_469 = V_10 -> V_70 + V_10 -> V_162 * V_3 - V_208 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
} else {
if ( F_135 ( V_10 -> V_70 + V_10 -> V_162 * V_3 , V_469 ) )
V_469 = V_10 -> V_70 + V_10 -> V_162 * V_3 ;
F_125 ( & V_10 -> V_36 ) ;
}
}
}
V_470 = F_321 ( V_469 ) ;
V_471 = V_469 ;
if ( F_135 ( V_470 , V_469 + V_475 ) )
V_471 = V_470 ;
if ( F_135 ( V_471 , V_13 + V_476 ) )
V_471 = V_13 + V_476 ;
F_38 ( V_262 L_27 ,
V_212 , V_469 , V_470 , V_471 ) ;
F_19 ( V_15 , & V_473 , V_471 - V_212 ) ;
F_129 () ;
}
static void F_322 ( struct V_446 * V_447 )
{
F_249 () ;
F_256 () ;
F_92 () ;
}
static void F_246 ( void )
{
F_19 ( V_15 , & V_473 , 0 ) ;
}
static struct V_156 * F_323 ( struct V_109 * V_154 , struct V_109 * V_477 ,
struct V_156 * * V_388 )
{
struct V_156 * V_306 = NULL ;
* V_388 = NULL ;
if ( V_154 )
V_306 = F_324 ( V_154 ) ;
if ( V_477 ) {
if ( V_306 && F_325 ( V_477 , V_306 , sizeof( * V_306 ) ) )
* V_388 = V_306 ;
V_306 = F_324 ( V_477 ) ;
}
return V_306 ;
}
static int
F_326 ( struct V_82 * V_83 , struct V_90 * V_91 )
{
struct V_100 * V_100 = F_69 ( V_83 -> V_108 ) ;
struct V_478 * V_479 ;
struct V_109 * V_110 [ V_480 + 1 ] ;
struct V_156 * V_306 , * V_388 ;
int V_101 ;
V_101 = F_70 ( V_91 , sizeof( * V_479 ) , V_110 , V_480 , V_481 ) ;
if ( V_101 < 0 )
return V_101 ;
V_479 = F_58 ( V_91 ) ;
V_306 = F_323 ( V_110 [ V_482 ] , V_110 [ V_483 ] , & V_388 ) ;
if ( V_306 == NULL )
return - V_114 ;
return F_257 ( V_100 , V_479 -> V_484 , V_306 , V_479 -> V_485 ) ;
}
static int F_327 ( struct V_9 * V_10 , T_1 V_389 ,
T_1 V_162 , T_1 V_161 )
{
T_1 V_50 ;
T_5 V_186 ;
unsigned long V_390 ;
bool V_486 ;
bool V_487 ;
F_30 () ;
if ( ! V_161 || ( V_162 > V_161 ) )
return - V_114 ;
if ( V_389 & V_356 &&
( V_10 -> V_50 & V_182 || V_10 -> V_179 != 64 ) )
return - V_114 ;
V_390 = F_134 ( V_161 , V_3 ) ;
if ( F_239 ( V_390 ) ) {
V_186 = F_241 ( V_390 * V_3 ) ;
V_161 = V_390 ;
V_50 = V_198 ;
} else {
V_186 = 0 ;
V_50 = 0 ;
V_389 |= V_190 ;
}
V_390 = F_134 ( V_162 , V_3 ) ;
if ( F_239 ( V_390 ) ) {
if ( V_390 == 0 )
V_389 |= V_241 ;
V_162 = V_390 ;
}
F_141 ( & V_10 -> V_36 ) ;
V_486 = V_10 -> V_50 & V_356 ;
V_487 = V_10 -> V_50 & V_190 &&
! ( V_10 -> V_50 & V_191 ) ;
V_10 -> V_50 &= ~ ( V_241 | V_190 | V_443 |
V_246 | V_356 |
V_191 ) ;
V_10 -> V_50 |= V_389 ;
V_10 -> V_70 = V_13 ;
V_10 -> V_161 = V_161 ;
V_10 -> V_162 = V_162 ;
F_142 ( & V_10 -> V_36 ) ;
if ( ! ( V_10 -> V_50 & V_138 ) )
F_149 ( 0 , V_10 ) ;
if ( ! ( V_389 & V_191 ) ) {
F_224 ( & V_10 -> V_154 , V_10 -> V_179 , V_10 -> V_5 -> V_7 ,
V_186 , V_50 ) ;
} else if ( V_487 ) {
enum V_185 V_188 ;
unsigned long V_346 ;
F_144 ( & V_10 -> V_5 -> V_36 ) ;
V_188 = F_132 ( V_10 , & V_346 ) ;
F_148 ( & V_10 -> V_5 -> V_36 ) ;
if ( V_188 != V_192 ) {
F_136 ( V_10 , V_346 ,
V_188 == V_189 ) ;
}
}
if ( V_486 || V_10 -> V_50 & V_356 ) {
if ( V_486 && ! ( V_10 -> V_50 & V_356 ) )
V_161 = V_162 = 0 ;
F_232 ( V_10 -> V_5 , V_10 , V_161 , V_162 ,
! V_486 , V_13 ) ;
}
F_256 () ;
return 0 ;
}
static int
F_328 ( struct V_82 * V_83 , struct V_90 * V_91 )
{
struct V_100 * V_100 = F_69 ( V_83 -> V_108 ) ;
struct V_478 * V_479 ;
struct V_109 * V_110 [ V_480 + 1 ] ;
struct V_156 * V_306 , * V_388 ;
struct V_9 * V_135 ;
struct V_6 * V_7 ;
T_1 V_161 = V_396 , V_488 = V_396 ;
T_1 V_389 ;
int V_101 ;
V_101 = F_70 ( V_91 , sizeof( * V_479 ) , V_110 , V_480 , V_481 ) ;
if ( V_101 < 0 )
return V_101 ;
V_479 = F_58 ( V_91 ) ;
V_306 = F_323 ( V_110 [ V_482 ] , V_110 [ V_483 ] , & V_388 ) ;
if ( V_306 == NULL )
return - V_114 ;
if ( V_110 [ V_489 ] ) {
struct V_490 * V_491 ;
V_491 = F_324 ( V_110 [ V_489 ] ) ;
V_161 = V_491 -> V_492 ;
V_488 = V_491 -> V_493 ;
} else {
V_488 = V_396 ;
V_161 = V_396 ;
}
V_7 = F_72 ( V_100 , V_479 -> V_484 ) ;
if ( V_7 == NULL )
return - V_170 ;
V_389 = V_110 [ V_494 ] ? F_329 ( V_110 [ V_494 ] ) : V_479 -> V_389 ;
V_389 &= V_443 | V_246 | V_356 |
V_191 ;
V_135 = F_185 ( V_100 , V_306 , V_7 , 1 ) ;
if ( V_135 == NULL ) {
return F_255 ( V_100 , V_479 -> V_484 , V_306 , V_388 ,
V_479 -> V_485 , V_389 ,
V_488 , V_161 ) ;
}
if ( V_91 -> V_495 & V_496 ||
! ( V_91 -> V_495 & V_497 ) )
V_101 = - V_175 ;
else
V_101 = F_327 ( V_135 , V_389 , V_488 , V_161 ) ;
F_146 ( V_135 ) ;
return V_101 ;
}
static void F_330 ( struct V_90 * V_91 , T_3 V_498 , T_1 V_50 ,
T_3 V_160 , int V_84 )
{
struct V_478 * V_479 ;
V_479 = F_58 ( V_91 ) ;
V_479 -> V_499 = V_95 ;
V_479 -> V_485 = V_498 ;
V_479 -> V_389 = V_50 ;
V_479 -> V_406 = V_160 ;
V_479 -> V_484 = V_84 ;
}
static int F_331 ( struct V_82 * V_83 , unsigned long V_1 ,
unsigned long V_70 , T_1 V_500 , T_1 V_344 )
{
struct V_490 V_491 ;
V_491 . V_1 = F_1 ( V_1 ) ;
V_491 . V_70 = F_1 ( V_70 ) ;
V_491 . V_493 = V_500 ;
V_491 . V_492 = V_344 ;
return F_332 ( V_83 , V_489 , sizeof( V_491 ) , & V_491 ) ;
}
static inline int F_333 ( int V_406 )
{
if ( V_406 & V_271 )
return V_408 ;
else if ( V_406 & V_268 )
return V_407 ;
else if ( V_406 & V_501 )
return V_502 ;
else
return V_503 ;
}
static inline int F_334 ( void )
{
return F_53 ( sizeof( struct V_478 ) )
+ F_54 ( 16 )
+ F_54 ( 16 )
+ F_54 ( sizeof( struct V_490 ) )
+ F_54 ( 4 ) ;
}
static int F_335 ( struct V_82 * V_83 , struct V_9 * V_135 ,
T_1 V_87 , T_1 V_88 , int V_89 , unsigned int V_50 )
{
struct V_90 * V_91 ;
T_1 V_500 , V_344 ;
V_91 = F_57 ( V_83 , V_87 , V_88 , V_89 , sizeof( struct V_478 ) , V_50 ) ;
if ( V_91 == NULL )
return - V_93 ;
F_330 ( V_91 , V_135 -> V_179 , V_135 -> V_50 , F_333 ( V_135 -> V_160 ) ,
V_135 -> V_5 -> V_7 -> V_84 ) ;
if ( ! ( ( V_135 -> V_50 & V_190 ) &&
( V_135 -> V_162 == V_396 ) ) ) {
V_500 = V_135 -> V_162 ;
V_344 = V_135 -> V_161 ;
if ( V_500 != V_396 ) {
long V_504 = ( V_13 - V_135 -> V_70 ) / V_3 ;
if ( V_500 > V_504 )
V_500 -= V_504 ;
else
V_500 = 0 ;
if ( V_344 != V_396 ) {
if ( V_344 > V_504 )
V_344 -= V_504 ;
else
V_344 = 0 ;
}
}
} else {
V_500 = V_396 ;
V_344 = V_396 ;
}
if ( ! F_198 ( & V_135 -> V_158 ) ) {
if ( F_332 ( V_83 , V_483 , 16 , & V_135 -> V_154 ) < 0 ||
F_332 ( V_83 , V_482 , 16 , & V_135 -> V_158 ) < 0 )
goto error;
} else
if ( F_332 ( V_83 , V_482 , 16 , & V_135 -> V_154 ) < 0 )
goto error;
if ( F_331 ( V_83 , V_135 -> V_1 , V_135 -> V_70 , V_500 , V_344 ) < 0 )
goto error;
if ( F_336 ( V_83 , V_494 , V_135 -> V_50 ) < 0 )
goto error;
return F_60 ( V_83 , V_91 ) ;
error:
F_61 ( V_83 , V_91 ) ;
return - V_93 ;
}
static int F_337 ( struct V_82 * V_83 , struct V_505 * V_506 ,
T_1 V_87 , T_1 V_88 , int V_89 , T_13 V_50 )
{
struct V_90 * V_91 ;
T_3 V_160 = V_503 ;
int V_84 = V_506 -> V_5 -> V_7 -> V_84 ;
if ( F_155 ( & V_506 -> V_507 ) & V_501 )
V_160 = V_502 ;
V_91 = F_57 ( V_83 , V_87 , V_88 , V_89 , sizeof( struct V_478 ) , V_50 ) ;
if ( V_91 == NULL )
return - V_93 ;
F_330 ( V_91 , 128 , V_190 , V_160 , V_84 ) ;
if ( F_332 ( V_83 , V_508 , 16 , & V_506 -> V_507 ) < 0 ||
F_331 ( V_83 , V_506 -> V_509 , V_506 -> V_510 ,
V_396 , V_396 ) < 0 ) {
F_61 ( V_83 , V_91 ) ;
return - V_93 ;
}
return F_60 ( V_83 , V_91 ) ;
}
static int F_338 ( struct V_82 * V_83 , struct V_511 * V_512 ,
T_1 V_87 , T_1 V_88 , int V_89 , unsigned int V_50 )
{
struct V_90 * V_91 ;
T_3 V_160 = V_503 ;
int V_84 = V_512 -> V_513 -> V_7 -> V_84 ;
if ( F_155 ( & V_512 -> V_514 ) & V_501 )
V_160 = V_502 ;
V_91 = F_57 ( V_83 , V_87 , V_88 , V_89 , sizeof( struct V_478 ) , V_50 ) ;
if ( V_91 == NULL )
return - V_93 ;
F_330 ( V_91 , 128 , V_190 , V_160 , V_84 ) ;
if ( F_332 ( V_83 , V_515 , 16 , & V_512 -> V_514 ) < 0 ||
F_331 ( V_83 , V_512 -> V_516 , V_512 -> V_517 ,
V_396 , V_396 ) < 0 ) {
F_61 ( V_83 , V_91 ) ;
return - V_93 ;
}
return F_60 ( V_83 , V_91 ) ;
}
static int F_339 ( struct V_4 * V_5 , struct V_82 * V_83 ,
struct V_119 * V_120 , enum V_518 type ,
int V_519 , int * V_520 )
{
struct V_505 * V_506 ;
struct V_511 * V_512 ;
int V_101 = 1 ;
int V_521 = * V_520 ;
F_170 ( & V_5 -> V_36 ) ;
switch ( type ) {
case V_522 : {
struct V_9 * V_135 ;
F_84 (ifa, &idev->addr_list, if_list) {
if ( ++ V_521 < V_519 )
continue;
V_101 = F_335 ( V_83 , V_135 ,
F_73 ( V_120 -> V_83 ) . V_87 ,
V_120 -> V_91 -> V_118 ,
V_397 ,
V_132 ) ;
if ( V_101 <= 0 )
break;
F_80 ( V_120 , F_81 ( V_83 ) ) ;
}
break;
}
case V_523 :
for ( V_506 = V_5 -> V_524 ; V_506 ;
V_506 = V_506 -> V_469 , V_521 ++ ) {
if ( V_521 < V_519 )
continue;
V_101 = F_337 ( V_83 , V_506 ,
F_73 ( V_120 -> V_83 ) . V_87 ,
V_120 -> V_91 -> V_118 ,
V_525 ,
V_132 ) ;
if ( V_101 <= 0 )
break;
}
break;
case V_526 :
for ( V_512 = V_5 -> V_527 ; V_512 ;
V_512 = V_512 -> V_528 , V_521 ++ ) {
if ( V_521 < V_519 )
continue;
V_101 = F_338 ( V_83 , V_512 ,
F_73 ( V_120 -> V_83 ) . V_87 ,
V_120 -> V_91 -> V_118 ,
V_529 ,
V_132 ) ;
if ( V_101 <= 0 )
break;
}
break;
default:
break;
}
F_175 ( & V_5 -> V_36 ) ;
* V_520 = V_521 ;
return V_101 ;
}
static int F_340 ( struct V_82 * V_83 , struct V_119 * V_120 ,
enum V_518 type )
{
struct V_100 * V_100 = F_69 ( V_83 -> V_108 ) ;
int V_121 , V_122 ;
int V_123 , V_521 ;
int V_124 , V_519 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_125 * V_126 ;
V_122 = V_120 -> args [ 0 ] ;
V_124 = V_123 = V_120 -> args [ 1 ] ;
V_519 = V_521 = V_120 -> args [ 2 ] ;
F_76 () ;
V_120 -> V_88 = F_77 ( & V_100 -> V_19 . V_129 ) ^ V_100 -> V_130 ;
for ( V_121 = V_122 ; V_121 < V_127 ; V_121 ++ , V_124 = 0 ) {
V_123 = 0 ;
V_126 = & V_100 -> V_128 [ V_121 ] ;
F_78 (dev, head, index_hlist) {
if ( V_123 < V_124 )
goto V_131;
if ( V_121 > V_122 || V_123 > V_124 )
V_519 = 0 ;
V_521 = 0 ;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
goto V_131;
if ( F_339 ( V_5 , V_83 , V_120 , type ,
V_519 , & V_521 ) <= 0 )
goto V_133;
V_131:
V_123 ++ ;
}
}
V_133:
F_79 () ;
V_120 -> args [ 0 ] = V_121 ;
V_120 -> args [ 1 ] = V_123 ;
V_120 -> args [ 2 ] = V_521 ;
return V_83 -> V_134 ;
}
static int F_341 ( struct V_82 * V_83 , struct V_119 * V_120 )
{
enum V_518 type = V_522 ;
return F_340 ( V_83 , V_120 , type ) ;
}
static int F_342 ( struct V_82 * V_83 , struct V_119 * V_120 )
{
enum V_518 type = V_523 ;
return F_340 ( V_83 , V_120 , type ) ;
}
static int F_343 ( struct V_82 * V_83 , struct V_119 * V_120 )
{
enum V_518 type = V_526 ;
return F_340 ( V_83 , V_120 , type ) ;
}
static int F_344 ( struct V_82 * V_107 , struct V_90 * V_91 )
{
struct V_100 * V_100 = F_69 ( V_107 -> V_108 ) ;
struct V_478 * V_479 ;
struct V_109 * V_110 [ V_480 + 1 ] ;
struct V_156 * V_154 = NULL , * V_530 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_135 ;
struct V_82 * V_83 ;
int V_101 ;
V_101 = F_70 ( V_91 , sizeof( * V_479 ) , V_110 , V_480 , V_481 ) ;
if ( V_101 < 0 )
goto V_104;
V_154 = F_323 ( V_110 [ V_482 ] , V_110 [ V_483 ] , & V_530 ) ;
if ( V_154 == NULL ) {
V_101 = - V_114 ;
goto V_104;
}
V_479 = F_58 ( V_91 ) ;
if ( V_479 -> V_484 )
V_7 = F_72 ( V_100 , V_479 -> V_484 ) ;
V_135 = F_185 ( V_100 , V_154 , V_7 , 1 ) ;
if ( ! V_135 ) {
V_101 = - V_169 ;
goto V_104;
}
V_83 = F_63 ( F_334 () , V_27 ) ;
if ( ! V_83 ) {
V_101 = - V_102 ;
goto V_531;
}
V_101 = F_335 ( V_83 , V_135 , F_73 ( V_107 ) . V_87 ,
V_91 -> V_118 , V_397 , 0 ) ;
if ( V_101 < 0 ) {
F_64 ( V_101 == - V_93 ) ;
F_65 ( V_83 ) ;
goto V_531;
}
V_101 = F_74 ( V_83 , V_100 , F_73 ( V_107 ) . V_87 ) ;
V_531:
F_146 ( V_135 ) ;
V_104:
return V_101 ;
}
static void F_345 ( int V_89 , struct V_9 * V_135 )
{
struct V_82 * V_83 ;
struct V_100 * V_100 = F_34 ( V_135 -> V_5 -> V_7 ) ;
int V_101 = - V_102 ;
V_83 = F_63 ( F_334 () , V_103 ) ;
if ( V_83 == NULL )
goto V_104;
V_101 = F_335 ( V_83 , V_135 , 0 , 0 , V_89 , 0 ) ;
if ( V_101 < 0 ) {
F_64 ( V_101 == - V_93 ) ;
F_65 ( V_83 ) ;
goto V_104;
}
F_66 ( V_83 , V_100 , 0 , V_532 , NULL , V_103 ) ;
return;
V_104:
if ( V_101 < 0 )
F_67 ( V_100 , V_532 , V_101 ) ;
}
static inline void F_346 ( struct V_85 * V_39 ,
T_2 * V_533 , int V_534 )
{
F_347 ( V_534 < ( V_535 * 4 ) ) ;
memset ( V_533 , 0 , V_534 ) ;
V_533 [ V_536 ] = V_39 -> V_45 ;
V_533 [ V_537 ] = V_39 -> V_538 ;
V_533 [ V_539 ] = V_39 -> V_41 ;
V_533 [ V_540 ] = V_39 -> V_541 ;
V_533 [ V_542 ] = V_39 -> V_543 ;
V_533 [ V_544 ] = V_39 -> V_350 ;
V_533 [ V_545 ] = V_39 -> V_222 ;
V_533 [ V_546 ] = V_39 -> V_58 ;
V_533 [ V_547 ] =
F_348 ( V_39 -> V_440 ) ;
V_533 [ V_548 ] =
F_348 ( V_39 -> V_439 ) ;
V_533 [ V_549 ] = V_39 -> V_550 ;
V_533 [ V_551 ] =
F_348 ( V_39 -> V_552 ) ;
V_533 [ V_553 ] =
F_348 ( V_39 -> V_554 ) ;
V_533 [ V_555 ] = V_39 -> V_65 ;
V_533 [ V_556 ] = V_39 -> V_219 ;
V_533 [ V_557 ] = V_39 -> V_220 ;
V_533 [ V_558 ] = V_39 -> V_216 ;
V_533 [ V_559 ] = V_39 -> V_221 ;
V_533 [ V_560 ] = V_39 -> V_353 ;
V_533 [ V_561 ] = V_39 -> V_562 ;
V_533 [ V_563 ] = V_39 -> V_564 ;
#ifdef F_349
V_533 [ V_565 ] = V_39 -> V_566 ;
V_533 [ V_567 ] =
F_348 ( V_39 -> V_568 ) ;
#ifdef F_350
V_533 [ V_569 ] = V_39 -> V_570 ;
#endif
#endif
V_533 [ V_571 ] = V_39 -> V_99 ;
V_533 [ V_572 ] = V_39 -> V_573 ;
#ifdef F_242
V_533 [ V_574 ] = V_39 -> V_354 ;
#endif
#ifdef F_55
V_533 [ V_575 ] = V_39 -> V_98 ;
#endif
V_533 [ V_576 ] = V_39 -> V_172 ;
V_533 [ V_577 ] = V_39 -> V_53 ;
V_533 [ V_578 ] = V_39 -> V_579 ;
V_533 [ V_580 ] = V_39 -> V_581 ;
V_533 [ V_582 ] = V_39 -> V_583 ;
}
static inline T_14 F_351 ( void )
{
return F_54 ( 4 )
+ F_54 ( sizeof( struct V_584 ) )
+ F_54 ( V_535 * 4 )
+ F_54 ( V_585 * 8 )
+ F_54 ( V_586 * 8 )
+ F_54 ( sizeof( struct V_156 ) ) ;
}
static inline T_14 F_352 ( void )
{
return F_53 ( sizeof( struct V_587 ) )
+ F_54 ( V_588 )
+ F_54 ( V_589 )
+ F_54 ( 4 )
+ F_54 ( 4 )
+ F_54 ( F_351 () ) ;
}
static inline void F_353 ( T_15 * V_18 , T_16 * V_590 ,
int V_591 , int V_534 )
{
int V_16 ;
int V_592 = V_534 - sizeof( T_15 ) * V_591 ;
F_347 ( V_592 < 0 ) ;
F_354 ( V_591 , & V_18 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_591 ; V_16 ++ )
F_354 ( F_355 ( & V_590 [ V_16 ] ) , & V_18 [ V_16 ] ) ;
memset ( & V_18 [ V_591 ] , 0 , V_592 ) ;
}
static inline void F_356 ( T_15 * V_18 , void V_17 * * V_590 ,
int V_591 , int V_534 , T_14 V_593 )
{
int V_16 ;
int V_592 = V_534 - sizeof( T_15 ) * V_591 ;
F_347 ( V_592 < 0 ) ;
F_354 ( V_591 , & V_18 [ 0 ] ) ;
for ( V_16 = 1 ; V_16 < V_591 ; V_16 ++ )
F_354 ( F_357 ( V_590 , V_16 , V_593 ) , & V_18 [ V_16 ] ) ;
memset ( & V_18 [ V_591 ] , 0 , V_592 ) ;
}
static void F_358 ( T_15 * V_18 , struct V_4 * V_5 , int V_594 ,
int V_534 )
{
switch ( V_594 ) {
case V_595 :
F_356 ( V_18 , ( void V_17 * * ) V_5 -> V_18 . V_19 ,
V_585 , V_534 , F_359 ( struct V_20 , V_23 ) ) ;
break;
case V_596 :
F_353 ( V_18 , V_5 -> V_18 . V_25 -> V_597 , V_586 , V_534 ) ;
break;
}
}
static int F_360 ( struct V_82 * V_83 , struct V_4 * V_5 )
{
struct V_109 * V_598 ;
struct V_584 V_491 ;
if ( F_336 ( V_83 , V_599 , V_5 -> V_68 ) )
goto V_97;
V_491 . V_600 = V_601 ;
V_491 . V_70 = F_1 ( V_5 -> V_70 ) ;
V_491 . V_602 = F_348 ( V_5 -> V_43 -> V_602 ) ;
V_491 . V_603 = F_348 ( F_154 ( V_5 -> V_43 , V_223 ) ) ;
if ( F_332 ( V_83 , V_604 , sizeof( V_491 ) , & V_491 ) )
goto V_97;
V_598 = F_361 ( V_83 , V_605 , V_535 * sizeof( V_606 ) ) ;
if ( V_598 == NULL )
goto V_97;
F_346 ( & V_5 -> V_39 , F_324 ( V_598 ) , F_362 ( V_598 ) ) ;
V_598 = F_361 ( V_83 , V_595 , V_585 * sizeof( T_15 ) ) ;
if ( V_598 == NULL )
goto V_97;
F_358 ( F_324 ( V_598 ) , V_5 , V_595 , F_362 ( V_598 ) ) ;
V_598 = F_361 ( V_83 , V_596 , V_586 * sizeof( T_15 ) ) ;
if ( V_598 == NULL )
goto V_97;
F_358 ( F_324 ( V_598 ) , V_5 , V_596 , F_362 ( V_598 ) ) ;
V_598 = F_361 ( V_83 , V_607 , sizeof( struct V_156 ) ) ;
if ( V_598 == NULL )
goto V_97;
F_170 ( & V_5 -> V_36 ) ;
memcpy ( F_324 ( V_598 ) , V_5 -> V_66 . V_213 , F_362 ( V_598 ) ) ;
F_175 ( & V_5 -> V_36 ) ;
return 0 ;
V_97:
return - V_93 ;
}
static T_14 F_363 ( const struct V_6 * V_7 )
{
if ( ! F_50 ( V_7 ) )
return 0 ;
return F_351 () ;
}
static int F_364 ( struct V_82 * V_83 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
return - V_608 ;
if ( F_360 ( V_83 , V_5 ) < 0 )
return - V_93 ;
return 0 ;
}
static int F_365 ( struct V_4 * V_5 , struct V_156 * V_66 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_609 = false ;
struct V_156 V_610 ;
F_30 () ;
if ( V_66 == NULL )
return - V_114 ;
if ( F_198 ( V_66 ) )
return - V_114 ;
if ( V_7 -> V_50 & ( V_52 | V_51 ) )
return - V_114 ;
if ( ! F_289 ( V_5 ) )
return - V_114 ;
if ( V_5 -> V_39 . V_58 <= 0 )
return - V_114 ;
F_144 ( & V_5 -> V_36 ) ;
F_366 ( sizeof( V_66 -> V_213 ) != 16 ) ;
memcpy ( V_5 -> V_66 . V_213 + 8 , V_66 -> V_213 + 8 , 8 ) ;
F_148 ( & V_5 -> V_36 ) ;
if ( ! V_5 -> V_49 && ( V_5 -> V_68 & V_69 ) &&
! F_178 ( V_7 , & V_610 , V_138 |
V_225 ) ) {
F_290 ( V_7 , & V_610 , & V_75 ) ;
V_609 = true ;
}
F_144 ( & V_5 -> V_36 ) ;
if ( V_609 ) {
V_5 -> V_68 |= V_435 ;
V_5 -> V_437 = 1 ;
F_12 ( V_5 , V_5 -> V_39 . V_440 ) ;
}
F_84 (ifp, &idev->addr_list, if_list) {
F_115 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_180 ) {
V_10 -> V_161 = 0 ;
V_10 -> V_162 = 0 ;
}
F_125 ( & V_10 -> V_36 ) ;
}
F_148 ( & V_5 -> V_36 ) ;
F_256 () ;
return 0 ;
}
static int F_367 ( struct V_6 * V_7 , const struct V_109 * V_598 )
{
int V_101 = - V_114 ;
struct V_4 * V_5 = F_50 ( V_7 ) ;
struct V_109 * V_110 [ V_611 + 1 ] ;
if ( ! V_5 )
return - V_612 ;
if ( F_368 ( V_110 , V_611 , V_598 , NULL ) < 0 )
F_369 () ;
if ( V_110 [ V_607 ] )
V_101 = F_365 ( V_5 , F_324 ( V_110 [ V_607 ] ) ) ;
return V_101 ;
}
static int F_370 ( struct V_82 * V_83 , struct V_4 * V_5 ,
T_1 V_87 , T_1 V_88 , int V_89 , unsigned int V_50 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_587 * V_613 ;
struct V_90 * V_91 ;
void * V_614 ;
V_91 = F_57 ( V_83 , V_87 , V_88 , V_89 , sizeof( * V_613 ) , V_50 ) ;
if ( V_91 == NULL )
return - V_93 ;
V_613 = F_58 ( V_91 ) ;
V_613 -> V_615 = V_95 ;
V_613 -> V_616 = 0 ;
V_613 -> V_617 = V_7 -> type ;
V_613 -> V_618 = V_7 -> V_84 ;
V_613 -> V_619 = F_371 ( V_7 ) ;
V_613 -> V_620 = 0 ;
if ( F_372 ( V_83 , V_621 , V_7 -> V_48 ) ||
( V_7 -> V_283 &&
F_332 ( V_83 , V_622 , V_7 -> V_283 , V_7 -> V_285 ) ) ||
F_336 ( V_83 , V_623 , V_7 -> V_34 ) ||
( V_7 -> V_84 != V_7 -> V_624 &&
F_336 ( V_83 , V_625 , V_7 -> V_624 ) ) )
goto V_97;
V_614 = F_373 ( V_83 , V_626 ) ;
if ( V_614 == NULL )
goto V_97;
if ( F_360 ( V_83 , V_5 ) < 0 )
goto V_97;
F_374 ( V_83 , V_614 ) ;
return F_60 ( V_83 , V_91 ) ;
V_97:
F_61 ( V_83 , V_91 ) ;
return - V_93 ;
}
static int F_375 ( struct V_82 * V_83 , struct V_119 * V_120 )
{
struct V_100 * V_100 = F_69 ( V_83 -> V_108 ) ;
int V_121 , V_122 ;
int V_123 = 0 , V_124 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_125 * V_126 ;
V_122 = V_120 -> args [ 0 ] ;
V_124 = V_120 -> args [ 1 ] ;
F_76 () ;
for ( V_121 = V_122 ; V_121 < V_127 ; V_121 ++ , V_124 = 0 ) {
V_123 = 0 ;
V_126 = & V_100 -> V_128 [ V_121 ] ;
F_78 (dev, head, index_hlist) {
if ( V_123 < V_124 )
goto V_131;
V_5 = F_50 ( V_7 ) ;
if ( ! V_5 )
goto V_131;
if ( F_370 ( V_83 , V_5 ,
F_73 ( V_120 -> V_83 ) . V_87 ,
V_120 -> V_91 -> V_118 ,
V_425 , V_132 ) <= 0 )
goto V_176;
V_131:
V_123 ++ ;
}
}
V_176:
F_79 () ;
V_120 -> args [ 1 ] = V_123 ;
V_120 -> args [ 0 ] = V_121 ;
return V_83 -> V_134 ;
}
void F_276 ( int V_89 , struct V_4 * V_5 )
{
struct V_82 * V_83 ;
struct V_100 * V_100 = F_34 ( V_5 -> V_7 ) ;
int V_101 = - V_102 ;
V_83 = F_63 ( F_352 () , V_103 ) ;
if ( V_83 == NULL )
goto V_104;
V_101 = F_370 ( V_83 , V_5 , 0 , 0 , V_89 , 0 ) ;
if ( V_101 < 0 ) {
F_64 ( V_101 == - V_93 ) ;
F_65 ( V_83 ) ;
goto V_104;
}
F_66 ( V_83 , V_100 , 0 , V_627 , NULL , V_103 ) ;
return;
V_104:
if ( V_101 < 0 )
F_67 ( V_100 , V_627 , V_101 ) ;
}
static inline T_14 F_376 ( void )
{
return F_53 ( sizeof( struct V_628 ) )
+ F_54 ( sizeof( struct V_156 ) )
+ F_54 ( sizeof( struct V_629 ) ) ;
}
static int F_377 ( struct V_82 * V_83 , struct V_4 * V_5 ,
struct V_340 * V_341 , T_1 V_87 , T_1 V_88 ,
int V_89 , unsigned int V_50 )
{
struct V_628 * V_630 ;
struct V_90 * V_91 ;
struct V_629 V_491 ;
V_91 = F_57 ( V_83 , V_87 , V_88 , V_89 , sizeof( * V_630 ) , V_50 ) ;
if ( V_91 == NULL )
return - V_93 ;
V_630 = F_58 ( V_91 ) ;
V_630 -> V_631 = V_95 ;
V_630 -> V_632 = 0 ;
V_630 -> V_633 = 0 ;
V_630 -> V_634 = V_5 -> V_7 -> V_84 ;
V_630 -> V_179 = V_341 -> V_179 ;
V_630 -> V_635 = V_341 -> type ;
V_630 -> V_636 = 0 ;
V_630 -> V_637 = 0 ;
if ( V_341 -> V_272 )
V_630 -> V_637 |= V_638 ;
if ( V_341 -> V_350 )
V_630 -> V_637 |= V_639 ;
if ( F_332 ( V_83 , V_640 , sizeof( V_341 -> V_342 ) , & V_341 -> V_342 ) )
goto V_97;
V_491 . V_641 = F_235 ( V_341 -> V_345 ) ;
V_491 . V_642 = F_235 ( V_341 -> V_344 ) ;
if ( F_332 ( V_83 , V_643 , sizeof( V_491 ) , & V_491 ) )
goto V_97;
return F_60 ( V_83 , V_91 ) ;
V_97:
F_61 ( V_83 , V_91 ) ;
return - V_93 ;
}
static void F_247 ( int V_89 , struct V_4 * V_5 ,
struct V_340 * V_341 )
{
struct V_82 * V_83 ;
struct V_100 * V_100 = F_34 ( V_5 -> V_7 ) ;
int V_101 = - V_102 ;
V_83 = F_63 ( F_376 () , V_103 ) ;
if ( V_83 == NULL )
goto V_104;
V_101 = F_377 ( V_83 , V_5 , V_341 , 0 , 0 , V_89 , 0 ) ;
if ( V_101 < 0 ) {
F_64 ( V_101 == - V_93 ) ;
F_65 ( V_83 ) ;
goto V_104;
}
F_66 ( V_83 , V_100 , 0 , V_644 , NULL , V_103 ) ;
return;
V_104:
if ( V_101 < 0 )
F_67 ( V_100 , V_644 , V_101 ) ;
}
static void F_286 ( int V_89 , struct V_9 * V_10 )
{
struct V_100 * V_100 = F_34 ( V_10 -> V_5 -> V_7 ) ;
if ( V_89 )
F_30 () ;
F_345 ( V_89 ? : V_397 , V_10 ) ;
switch ( V_89 ) {
case V_397 :
if ( ! ( V_10 -> V_150 -> V_645 ) )
F_265 ( V_10 -> V_150 ) ;
if ( V_10 -> V_5 -> V_39 . V_45 )
F_85 ( V_10 ) ;
if ( ! F_198 ( & V_10 -> V_158 ) )
F_224 ( & V_10 -> V_158 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_200 :
if ( V_10 -> V_5 -> V_39 . V_45 )
F_86 ( V_10 ) ;
F_195 ( V_10 -> V_5 , & V_10 -> V_154 ) ;
if ( ! F_198 ( & V_10 -> V_158 ) ) {
struct V_163 * V_150 ;
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
V_150 = F_378 ( F_34 ( V_7 ) , & V_10 -> V_158 , NULL ,
V_7 -> V_84 , 1 ) ;
if ( V_150 ) {
F_228 ( & V_150 -> V_231 ) ;
if ( F_138 ( V_150 ) )
F_379 ( & V_150 -> V_231 ) ;
}
}
F_228 ( & V_10 -> V_150 -> V_231 ) ;
if ( F_138 ( V_10 -> V_150 ) )
F_379 ( & V_10 -> V_150 -> V_231 ) ;
break;
}
F_380 ( & V_100 -> V_19 . V_129 ) ;
F_381 ( V_100 ) ;
}
static void F_149 ( int V_89 , struct V_9 * V_10 )
{
F_114 () ;
if ( F_130 ( V_10 -> V_5 -> V_49 == 0 ) )
F_286 ( V_89 , V_10 ) ;
F_129 () ;
}
static
int F_382 ( struct V_141 * V_646 , int V_647 ,
void T_6 * V_648 , T_14 * V_649 , T_8 * V_650 )
{
int * V_651 = V_646 -> V_305 ;
int V_652 = * V_651 ;
T_8 V_456 = * V_650 ;
struct V_141 V_653 ;
int V_210 ;
V_653 = * V_646 ;
V_653 . V_305 = & V_652 ;
V_210 = F_383 ( & V_653 , V_647 , V_648 , V_649 , V_650 ) ;
if ( V_647 )
V_210 = F_89 ( V_646 , V_651 , V_652 ) ;
if ( V_210 )
* V_650 = V_456 ;
return V_210 ;
}
static void F_384 ( struct V_4 * V_5 )
{
struct V_654 V_655 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_385 ( & V_655 , V_5 -> V_7 ) ;
if ( V_5 -> V_39 . V_172 )
F_271 ( NULL , V_201 , & V_655 ) ;
else
F_271 ( NULL , V_184 , & V_655 ) ;
}
static void F_386 ( struct V_100 * V_100 , T_2 V_139 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_76 () ;
F_169 (net, dev) {
V_5 = F_50 ( V_7 ) ;
if ( V_5 ) {
int V_140 = ( ! V_5 -> V_39 . V_172 ) ^ ( ! V_139 ) ;
V_5 -> V_39 . V_172 = V_139 ;
if ( V_140 )
F_384 ( V_5 ) ;
}
}
F_79 () ;
}
static int F_387 ( struct V_141 * V_142 , int * V_143 , int V_139 )
{
struct V_100 * V_100 ;
int V_144 ;
if ( ! F_90 () )
return F_91 () ;
V_100 = (struct V_100 * ) V_142 -> V_145 ;
V_144 = * V_143 ;
* V_143 = V_139 ;
if ( V_143 == & V_100 -> V_19 . V_40 -> V_172 ) {
F_92 () ;
return 0 ;
}
if ( V_143 == & V_100 -> V_19 . V_116 -> V_172 ) {
V_100 -> V_19 . V_40 -> V_172 = V_139 ;
F_386 ( V_100 , V_139 ) ;
} else if ( ( ! V_139 ) ^ ( ! V_144 ) )
F_384 ( (struct V_4 * ) V_142 -> V_146 ) ;
F_92 () ;
return 0 ;
}
static
int F_388 ( struct V_141 * V_646 , int V_647 ,
void T_6 * V_648 , T_14 * V_649 , T_8 * V_650 )
{
int * V_651 = V_646 -> V_305 ;
int V_652 = * V_651 ;
T_8 V_456 = * V_650 ;
struct V_141 V_653 ;
int V_210 ;
V_653 = * V_646 ;
V_653 . V_305 = & V_652 ;
V_210 = F_383 ( & V_653 , V_647 , V_648 , V_649 , V_650 ) ;
if ( V_647 )
V_210 = F_387 ( V_646 , V_651 , V_652 ) ;
if ( V_210 )
* V_650 = V_456 ;
return V_210 ;
}
static
int F_389 ( struct V_141 * V_646 , int V_647 ,
void T_6 * V_648 , T_14 * V_649 , T_8 * V_650 )
{
int * V_651 = V_646 -> V_305 ;
int V_210 ;
int V_144 , V_656 ;
V_144 = * V_651 ;
V_210 = F_383 ( V_646 , V_647 , V_648 , V_649 , V_650 ) ;
V_656 = * V_651 ;
if ( V_647 && V_144 != V_656 ) {
struct V_100 * V_100 = V_646 -> V_145 ;
if ( ! F_90 () )
return F_91 () ;
if ( V_651 == & V_100 -> V_19 . V_40 -> V_99 )
F_62 ( V_100 , V_81 ,
V_117 ,
V_100 -> V_19 . V_40 ) ;
else if ( V_651 == & V_100 -> V_19 . V_116 -> V_99 )
F_62 ( V_100 , V_81 ,
V_115 ,
V_100 -> V_19 . V_116 ) ;
else {
struct V_4 * V_5 = V_646 -> V_146 ;
F_62 ( V_100 , V_81 ,
V_5 -> V_7 -> V_84 ,
& V_5 -> V_39 ) ;
}
F_92 () ;
}
return V_210 ;
}
static int F_390 ( struct V_100 * V_100 , char * V_657 ,
struct V_4 * V_5 , struct V_85 * V_143 )
{
int V_16 ;
struct V_658 * V_659 ;
char V_660 [ sizeof( L_28 ) + V_588 ] ;
V_659 = F_391 ( & V_661 , sizeof( * V_659 ) , V_27 ) ;
if ( V_659 == NULL )
goto V_176;
for ( V_16 = 0 ; V_659 -> V_662 [ V_16 ] . V_305 ; V_16 ++ ) {
V_659 -> V_662 [ V_16 ] . V_305 += ( char * ) V_143 - ( char * ) & V_85 ;
V_659 -> V_662 [ V_16 ] . V_146 = V_5 ;
V_659 -> V_662 [ V_16 ] . V_145 = V_100 ;
}
snprintf ( V_660 , sizeof( V_660 ) , L_29 , V_657 ) ;
V_659 -> V_663 = F_392 ( V_100 , V_660 , V_659 -> V_662 ) ;
if ( V_659 -> V_663 == NULL )
goto free;
V_143 -> V_42 = V_659 ;
return 0 ;
free:
F_27 ( V_659 ) ;
V_176:
return - V_102 ;
}
static void F_393 ( struct V_85 * V_143 )
{
struct V_658 * V_659 ;
if ( V_143 -> V_42 == NULL )
return;
V_659 = V_143 -> V_42 ;
V_143 -> V_42 = NULL ;
F_394 ( V_659 -> V_663 ) ;
F_27 ( V_659 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_395 ( V_5 -> V_7 , V_5 -> V_43 ,
& V_664 ) ;
F_390 ( F_34 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_48 ,
V_5 , & V_5 -> V_39 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_393 ( & V_5 -> V_39 ) ;
F_396 ( V_5 -> V_43 ) ;
}
static int T_10 F_397 ( struct V_100 * V_100 )
{
int V_101 = - V_32 ;
struct V_85 * V_665 , * V_666 ;
V_665 = F_391 ( & V_85 , sizeof( V_85 ) , V_27 ) ;
if ( V_665 == NULL )
goto V_667;
V_666 = F_391 ( & V_668 , sizeof( V_668 ) , V_27 ) ;
if ( V_666 == NULL )
goto V_669;
V_666 -> V_350 = V_670 . V_350 ;
V_666 -> V_172 = V_670 . V_172 ;
V_100 -> V_19 . V_116 = V_665 ;
V_100 -> V_19 . V_40 = V_666 ;
#ifdef F_398
V_101 = F_390 ( V_100 , L_30 , NULL , V_665 ) ;
if ( V_101 < 0 )
goto V_671;
V_101 = F_390 ( V_100 , L_31 , NULL , V_666 ) ;
if ( V_101 < 0 )
goto V_672;
#endif
return 0 ;
#ifdef F_398
V_672:
F_393 ( V_665 ) ;
V_671:
F_27 ( V_666 ) ;
#endif
V_669:
F_27 ( V_665 ) ;
V_667:
return V_101 ;
}
static void T_11 F_399 ( struct V_100 * V_100 )
{
#ifdef F_398
F_393 ( V_100 -> V_19 . V_40 ) ;
F_393 ( V_100 -> V_19 . V_116 ) ;
#endif
if ( ! F_181 ( V_100 , & V_673 ) ) {
F_27 ( V_100 -> V_19 . V_40 ) ;
F_27 ( V_100 -> V_19 . V_116 ) ;
}
}
int T_12 F_400 ( void )
{
int V_16 , V_101 ;
V_101 = F_401 () ;
if ( V_101 < 0 ) {
F_402 ( L_32 ,
V_47 , V_101 ) ;
goto V_176;
}
V_101 = F_317 ( & V_674 ) ;
if ( V_101 < 0 )
goto V_675;
V_15 = F_403 ( L_33 ) ;
if ( ! V_15 ) {
V_101 = - V_32 ;
goto V_676;
}
F_249 () ;
if ( ! F_29 ( V_673 . V_677 ) )
V_101 = - V_32 ;
F_92 () ;
if ( V_101 )
goto V_678;
for ( V_16 = 0 ; V_16 < V_433 ; V_16 ++ )
F_404 ( & V_181 [ V_16 ] ) ;
F_405 ( & V_679 ) ;
F_246 () ;
F_406 ( & V_680 ) ;
V_101 = F_407 ( V_681 , V_682 , NULL , F_375 ,
NULL ) ;
if ( V_101 < 0 )
goto V_104;
F_407 ( V_681 , V_397 , F_328 , NULL , NULL ) ;
F_407 ( V_681 , V_200 , F_326 , NULL , NULL ) ;
F_407 ( V_681 , V_683 , F_344 ,
F_341 , NULL ) ;
F_407 ( V_681 , V_525 , NULL ,
F_342 , NULL ) ;
F_407 ( V_681 , V_529 , NULL ,
F_343 , NULL ) ;
F_407 ( V_681 , V_684 , F_68 ,
F_75 , NULL ) ;
F_408 () ;
return 0 ;
V_104:
F_409 ( & V_680 ) ;
F_410 ( & V_679 ) ;
V_678:
F_411 ( V_15 ) ;
V_676:
F_319 ( & V_674 ) ;
V_675:
F_412 () ;
V_176:
return V_101 ;
}
void F_413 ( void )
{
struct V_6 * V_7 ;
int V_16 ;
F_410 ( & V_679 ) ;
F_319 ( & V_674 ) ;
F_412 () ;
F_249 () ;
F_414 ( & V_680 ) ;
F_88 (&init_net, dev) {
if ( F_50 ( V_7 ) == NULL )
continue;
F_277 ( V_7 , 1 ) ;
}
F_277 ( V_673 . V_677 , 2 ) ;
F_141 ( & V_174 ) ;
for ( V_16 = 0 ; V_16 < V_433 ; V_16 ++ )
F_64 ( ! F_415 ( & V_181 [ V_16 ] ) ) ;
F_142 ( & V_174 ) ;
F_10 ( & V_473 ) ;
F_92 () ;
F_411 ( V_15 ) ;
}
