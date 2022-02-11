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
if ( F_7 ( & V_10 -> V_11 ) )
F_10 ( V_10 ) ;
}
static void F_11 ( struct V_4 * V_5 ,
unsigned long V_12 )
{
if ( ! F_12 ( & V_5 -> V_8 ) )
F_13 ( V_5 ) ;
F_14 ( & V_5 -> V_8 , V_13 + V_12 ) ;
}
static void F_15 ( struct V_9 * V_10 ,
unsigned long V_12 )
{
if ( ! F_12 ( & V_10 -> V_11 ) )
F_16 ( V_10 ) ;
F_14 ( & V_10 -> V_11 , V_13 + V_12 ) ;
}
static int F_17 ( struct V_4 * V_5 )
{
if ( F_18 ( ( void V_14 * * ) V_5 -> V_15 . V_16 ,
sizeof( struct V_17 ) ,
F_19 ( struct V_17 ) ) < 0 )
goto V_18;
V_5 -> V_15 . V_19 = F_20 ( sizeof( struct V_20 ) ,
V_21 ) ;
if ( ! V_5 -> V_15 . V_19 )
goto V_22;
V_5 -> V_15 . V_23 = F_20 ( sizeof( struct V_24 ) ,
V_21 ) ;
if ( ! V_5 -> V_15 . V_23 )
goto V_25;
return 0 ;
V_25:
F_21 ( V_5 -> V_15 . V_19 ) ;
V_22:
F_22 ( ( void V_14 * * ) V_5 -> V_15 . V_16 ) ;
V_18:
return - V_26 ;
}
static struct V_4 * F_23 ( struct V_6 * V_7 )
{
struct V_4 * V_27 ;
F_24 () ;
if ( V_7 -> V_28 < V_29 )
return NULL ;
V_27 = F_20 ( sizeof( struct V_4 ) , V_21 ) ;
if ( V_27 == NULL )
return NULL ;
F_25 ( & V_27 -> V_30 ) ;
V_27 -> V_7 = V_7 ;
F_26 ( & V_27 -> V_31 ) ;
F_27 ( & V_27 -> V_8 , V_32 ,
( unsigned long ) V_27 ) ;
memcpy ( & V_27 -> V_33 , F_28 ( V_7 ) -> V_16 . V_34 , sizeof( V_27 -> V_33 ) ) ;
V_27 -> V_33 . V_35 = V_7 -> V_28 ;
V_27 -> V_33 . V_36 = NULL ;
V_27 -> V_37 = F_29 ( V_7 , & V_38 ) ;
if ( V_27 -> V_37 == NULL ) {
F_21 ( V_27 ) ;
return NULL ;
}
if ( V_27 -> V_33 . V_39 )
F_30 ( V_7 ) ;
F_31 ( V_7 ) ;
if ( F_17 ( V_27 ) < 0 ) {
F_32 ( V_40
L_1 ,
V_41 , V_7 -> V_42 ) ;
F_33 ( & V_38 , V_27 -> V_37 ) ;
F_34 ( V_7 ) ;
F_21 ( V_27 ) ;
return NULL ;
}
if ( F_35 ( V_27 ) < 0 ) {
F_32 ( V_40
L_2 ,
V_41 , V_7 -> V_42 ) ;
F_33 ( & V_38 , V_27 -> V_37 ) ;
V_27 -> V_43 = 1 ;
F_36 ( V_27 ) ;
return NULL ;
}
F_13 ( V_27 ) ;
if ( V_7 -> V_44 & ( V_45 | V_46 ) )
V_27 -> V_33 . V_47 = - 1 ;
#if F_37 ( V_48 )
if ( V_7 -> type == V_49 && ( V_7 -> V_50 & V_51 ) ) {
F_38 ( L_3 , V_7 -> V_42 ) ;
V_27 -> V_33 . V_52 = 0 ;
}
#endif
#ifdef F_39
F_26 ( & V_27 -> V_53 ) ;
F_27 ( & V_27 -> V_54 , V_55 , ( unsigned long ) V_27 ) ;
if ( ( V_7 -> V_44 & V_46 ) ||
V_7 -> type == V_56 ||
V_7 -> type == V_57 ||
V_7 -> type == V_49 ||
V_7 -> type == V_58 ) {
V_27 -> V_33 . V_59 = - 1 ;
} else {
F_13 ( V_27 ) ;
V_55 ( ( unsigned long ) V_27 ) ;
}
#endif
V_27 -> V_60 = V_61 ;
if ( F_40 ( V_7 ) && F_4 ( V_7 ) )
V_27 -> V_62 |= V_63 ;
F_41 ( V_27 ) ;
V_27 -> V_64 = V_13 ;
F_2 ( V_27 ) ;
F_42 ( V_7 -> V_65 , V_27 ) ;
F_43 ( V_7 , & V_66 ) ;
F_43 ( V_7 , & V_67 ) ;
if ( V_27 -> V_33 . V_39 && ( V_7 -> V_44 & V_68 ) )
F_43 ( V_7 , & V_69 ) ;
return V_27 ;
}
static struct V_4 * F_44 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_24 () ;
V_5 = F_45 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_23 ( V_7 ) ;
if ( ! V_5 )
return NULL ;
}
if ( V_7 -> V_44 & V_70 )
F_46 ( V_5 ) ;
return V_5 ;
}
static int F_47 ( int type )
{
int V_71 = F_48 ( sizeof( struct V_72 ) )
+ F_49 ( 4 ) ;
if ( type == - 1 || type == V_73 )
V_71 += F_49 ( 4 ) ;
#ifdef F_50
if ( type == - 1 || type == V_74 )
V_71 += F_49 ( 4 ) ;
#endif
return V_71 ;
}
static int F_51 ( struct V_75 * V_76 , int V_77 ,
struct V_78 * V_79 , T_1 V_80 ,
T_1 V_81 , int V_82 , unsigned int V_44 ,
int type )
{
struct V_83 * V_84 ;
struct V_72 * V_85 ;
V_84 = F_52 ( V_76 , V_80 , V_81 , V_82 , sizeof( struct V_72 ) ,
V_44 ) ;
if ( V_84 == NULL )
return - V_86 ;
V_85 = F_53 ( V_84 ) ;
V_85 -> V_87 = V_88 ;
if ( F_54 ( V_76 , V_89 , V_77 ) < 0 )
goto V_90;
if ( ( type == - 1 || type == V_73 ) &&
F_54 ( V_76 , V_73 , V_79 -> V_39 ) < 0 )
goto V_90;
#ifdef F_50
if ( ( type == - 1 || type == V_74 ) &&
F_54 ( V_76 , V_74 ,
V_79 -> V_91 ) < 0 )
goto V_90;
#endif
return F_55 ( V_76 , V_84 ) ;
V_90:
F_56 ( V_76 , V_84 ) ;
return - V_86 ;
}
void F_57 ( struct V_92 * V_92 , int type , int V_77 ,
struct V_78 * V_79 )
{
struct V_75 * V_76 ;
int V_93 = - V_94 ;
V_76 = F_58 ( F_47 ( type ) , V_95 ) ;
if ( V_76 == NULL )
goto V_96;
V_93 = F_51 ( V_76 , V_77 , V_79 , 0 , 0 ,
V_97 , 0 , type ) ;
if ( V_93 < 0 ) {
F_59 ( V_93 == - V_86 ) ;
F_60 ( V_76 ) ;
goto V_96;
}
F_61 ( V_76 , V_92 , 0 , V_98 , NULL , V_95 ) ;
return;
V_96:
F_62 ( V_92 , V_98 , V_93 ) ;
}
static int F_63 ( struct V_75 * V_99 ,
struct V_83 * V_84 )
{
struct V_92 * V_92 = F_64 ( V_99 -> V_100 ) ;
struct V_101 * V_102 [ V_103 + 1 ] ;
struct V_72 * V_85 ;
struct V_75 * V_76 ;
struct V_78 * V_79 ;
struct V_4 * V_104 ;
struct V_6 * V_7 ;
int V_77 ;
int V_93 ;
V_93 = F_65 ( V_84 , sizeof( * V_85 ) , V_102 , V_103 ,
V_105 ) ;
if ( V_93 < 0 )
goto V_96;
V_93 = V_106 ;
if ( ! V_102 [ V_89 ] )
goto V_96;
V_77 = F_66 ( V_102 [ V_89 ] ) ;
switch ( V_77 ) {
case V_107 :
V_79 = V_92 -> V_16 . V_108 ;
break;
case V_109 :
V_79 = V_92 -> V_16 . V_34 ;
break;
default:
V_7 = F_67 ( V_92 , V_77 ) ;
if ( V_7 == NULL )
goto V_96;
V_104 = F_45 ( V_7 ) ;
if ( V_104 == NULL )
goto V_96;
V_79 = & V_104 -> V_33 ;
break;
}
V_93 = - V_94 ;
V_76 = F_58 ( F_47 ( - 1 ) , V_95 ) ;
if ( V_76 == NULL )
goto V_96;
V_93 = F_51 ( V_76 , V_77 , V_79 ,
F_68 ( V_99 ) . V_80 ,
V_84 -> V_110 , V_97 , 0 ,
- 1 ) ;
if ( V_93 < 0 ) {
F_59 ( V_93 == - V_86 ) ;
F_60 ( V_76 ) ;
goto V_96;
}
V_93 = F_69 ( V_76 , V_92 , F_68 ( V_99 ) . V_80 ) ;
V_96:
return V_93 ;
}
static int F_70 ( struct V_75 * V_76 ,
struct V_111 * V_112 )
{
struct V_92 * V_92 = F_64 ( V_76 -> V_100 ) ;
int V_113 , V_114 ;
int V_115 , V_116 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_117 * V_118 ;
V_114 = V_112 -> args [ 0 ] ;
V_116 = V_115 = V_112 -> args [ 1 ] ;
for ( V_113 = V_114 ; V_113 < V_119 ; V_113 ++ , V_116 = 0 ) {
V_115 = 0 ;
V_118 = & V_92 -> V_120 [ V_113 ] ;
F_71 () ;
V_112 -> V_81 = F_72 ( & V_92 -> V_16 . V_121 ) ^
V_92 -> V_122 ;
F_73 (dev, head, index_hlist) {
if ( V_115 < V_116 )
goto V_123;
V_5 = F_45 ( V_7 ) ;
if ( ! V_5 )
goto V_123;
if ( F_51 ( V_76 , V_7 -> V_77 ,
& V_5 -> V_33 ,
F_68 ( V_112 -> V_76 ) . V_80 ,
V_112 -> V_84 -> V_110 ,
V_97 ,
V_124 ,
- 1 ) <= 0 ) {
F_74 () ;
goto V_125;
}
F_75 ( V_112 , F_76 ( V_76 ) ) ;
V_123:
V_115 ++ ;
}
F_74 () ;
}
if ( V_113 == V_119 ) {
if ( F_51 ( V_76 , V_107 ,
V_92 -> V_16 . V_108 ,
F_68 ( V_112 -> V_76 ) . V_80 ,
V_112 -> V_84 -> V_110 ,
V_97 , V_124 ,
- 1 ) <= 0 )
goto V_125;
else
V_113 ++ ;
}
if ( V_113 == V_119 + 1 ) {
if ( F_51 ( V_76 , V_109 ,
V_92 -> V_16 . V_34 ,
F_68 ( V_112 -> V_76 ) . V_80 ,
V_112 -> V_84 -> V_110 ,
V_97 , V_124 ,
- 1 ) <= 0 )
goto V_125;
else
V_113 ++ ;
}
V_125:
V_112 -> args [ 0 ] = V_113 ;
V_112 -> args [ 1 ] = V_115 ;
return V_76 -> V_126 ;
}
static void F_77 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_127 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_33 . V_39 )
F_30 ( V_7 ) ;
if ( V_7 -> V_44 & V_68 ) {
if ( V_5 -> V_33 . V_39 ) {
F_43 ( V_7 , & V_69 ) ;
F_43 ( V_7 , & V_128 ) ;
F_43 ( V_7 , & V_129 ) ;
} else {
F_78 ( V_7 , & V_69 ) ;
F_78 ( V_7 , & V_128 ) ;
F_78 ( V_7 , & V_129 ) ;
}
}
F_79 (ifa, &idev->addr_list, if_list) {
if ( V_127 -> V_44 & V_130 )
continue;
if ( V_5 -> V_33 . V_39 )
F_80 ( V_127 ) ;
else
F_81 ( V_127 ) ;
}
F_57 ( F_28 ( V_7 ) , V_73 ,
V_7 -> V_77 , & V_5 -> V_33 ) ;
}
static void F_82 ( struct V_92 * V_92 , T_2 V_131 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_83 (net, dev) {
V_5 = F_45 ( V_7 ) ;
if ( V_5 ) {
int V_132 = ( ! V_5 -> V_33 . V_39 ) ^ ( ! V_131 ) ;
V_5 -> V_33 . V_39 = V_131 ;
if ( V_132 )
F_77 ( V_5 ) ;
}
}
}
static int F_84 ( struct V_133 * V_134 , int * V_135 , int V_131 )
{
struct V_92 * V_92 ;
int V_136 ;
if ( ! F_85 () )
return F_86 () ;
V_92 = (struct V_92 * ) V_134 -> V_137 ;
V_136 = * V_135 ;
* V_135 = V_131 ;
if ( V_135 == & V_92 -> V_16 . V_34 -> V_39 ) {
if ( ( ! V_131 ) ^ ( ! V_136 ) )
F_57 ( V_92 , V_73 ,
V_109 ,
V_92 -> V_16 . V_34 ) ;
F_87 () ;
return 0 ;
}
if ( V_135 == & V_92 -> V_16 . V_108 -> V_39 ) {
V_92 -> V_16 . V_34 -> V_39 = V_131 ;
F_82 ( V_92 , V_131 ) ;
if ( ( ! V_131 ) ^ ( ! V_136 ) )
F_57 ( V_92 , V_73 ,
V_107 ,
V_92 -> V_16 . V_108 ) ;
} else if ( ( ! V_131 ) ^ ( ! V_136 ) )
F_77 ( (struct V_4 * ) V_134 -> V_138 ) ;
F_87 () ;
if ( V_131 )
F_88 ( V_92 ) ;
return 1 ;
}
void F_89 ( struct V_9 * V_10 )
{
F_59 ( ! F_90 ( & V_10 -> V_139 ) ) ;
#ifdef F_91
F_92 ( L_4 , V_41 ) ;
#endif
F_93 ( V_10 -> V_5 ) ;
if ( F_7 ( & V_10 -> V_11 ) )
F_94 ( L_5 , V_10 ) ;
if ( V_10 -> V_140 != V_141 ) {
F_95 ( L_6 , V_10 ) ;
return;
}
F_96 ( V_10 -> V_142 ) ;
F_97 ( V_10 , V_143 ) ;
}
static void
F_98 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_144 * V_135 ;
int V_145 = F_99 ( & V_10 -> V_146 ) ;
F_100 (p, &idev->addr_list) {
struct V_9 * V_127
= F_101 ( V_135 , struct V_9 , V_147 ) ;
if ( V_145 >= F_99 ( & V_127 -> V_146 ) )
break;
}
F_102 ( & V_10 -> V_147 , V_135 ) ;
}
static T_1 F_103 ( const struct V_148 * V_146 )
{
return F_104 ( F_105 ( V_146 ) , V_149 ) ;
}
static struct V_9 *
F_106 ( struct V_4 * V_5 , const struct V_148 * V_146 ,
const struct V_148 * V_150 , int V_151 ,
int V_152 , T_1 V_44 , T_1 V_153 , T_1 V_154 )
{
struct V_9 * V_127 = NULL ;
struct V_155 * V_142 ;
unsigned int V_156 ;
int V_93 = 0 ;
int V_157 = F_107 ( V_146 ) ;
if ( V_157 == V_158 ||
V_157 & V_159 ||
( ! ( V_5 -> V_7 -> V_44 & V_46 ) &&
V_157 & V_160 ) )
return F_108 ( - V_161 ) ;
F_109 () ;
if ( V_5 -> V_43 ) {
V_93 = - V_162 ;
goto V_163;
}
if ( V_5 -> V_33 . V_164 ) {
V_93 = - V_165 ;
goto V_163;
}
F_110 ( & V_166 ) ;
if ( F_111 ( F_28 ( V_5 -> V_7 ) , V_146 , V_5 -> V_7 ) ) {
F_32 ( L_7 ) ;
V_93 = - V_167 ;
goto V_168;
}
V_127 = F_20 ( sizeof( struct V_9 ) , V_95 ) ;
if ( V_127 == NULL ) {
F_32 ( L_8 ) ;
V_93 = - V_94 ;
goto V_168;
}
V_142 = F_112 ( V_5 , V_146 , false ) ;
if ( F_113 ( V_142 ) ) {
V_93 = F_114 ( V_142 ) ;
goto V_168;
}
V_127 -> V_146 = * V_146 ;
if ( V_150 )
V_127 -> V_150 = * V_150 ;
F_115 ( & V_127 -> V_30 ) ;
F_115 ( & V_127 -> V_169 ) ;
F_27 ( & V_127 -> V_11 , V_170 ,
( unsigned long ) V_127 ) ;
F_116 ( & V_127 -> V_139 ) ;
V_127 -> V_152 = V_152 ;
V_127 -> V_171 = V_151 ;
V_127 -> V_44 = V_44 | V_130 ;
V_127 -> V_153 = V_153 ;
V_127 -> V_154 = V_154 ;
V_127 -> V_1 = V_127 -> V_64 = V_13 ;
V_127 -> V_172 = false ;
V_127 -> V_142 = V_142 ;
V_127 -> V_5 = V_5 ;
F_13 ( V_5 ) ;
F_16 ( V_127 ) ;
V_156 = F_103 ( V_146 ) ;
F_117 ( & V_127 -> V_139 , & V_173 [ V_156 ] ) ;
F_118 ( & V_166 ) ;
F_119 ( & V_5 -> V_30 ) ;
F_98 ( V_5 , V_127 ) ;
#ifdef F_39
if ( V_127 -> V_44 & V_174 ) {
F_120 ( & V_127 -> V_175 , & V_5 -> V_53 ) ;
F_16 ( V_127 ) ;
}
#endif
F_16 ( V_127 ) ;
F_121 ( & V_5 -> V_30 ) ;
V_163:
F_122 () ;
if ( F_123 ( V_93 == 0 ) )
F_124 ( V_176 , V_127 ) ;
else {
F_21 ( V_127 ) ;
V_127 = F_108 ( V_93 ) ;
}
return V_127 ;
V_168:
F_118 ( & V_166 ) ;
goto V_163;
}
static void F_125 ( struct V_9 * V_10 )
{
struct V_9 * V_127 , * V_177 ;
struct V_4 * V_5 = V_10 -> V_5 ;
int V_140 ;
int V_178 = 0 , V_179 = 0 ;
unsigned long V_180 = V_13 ;
F_126 ( & V_10 -> V_169 ) ;
V_140 = V_10 -> V_140 ;
V_10 -> V_140 = V_141 ;
F_127 ( & V_10 -> V_169 ) ;
if ( V_140 == V_141 )
goto V_168;
F_126 ( & V_166 ) ;
F_128 ( & V_10 -> V_139 ) ;
F_127 ( & V_166 ) ;
F_129 ( & V_5 -> V_30 ) ;
#ifdef F_39
if ( V_10 -> V_44 & V_174 ) {
F_130 ( & V_10 -> V_175 ) ;
if ( V_10 -> V_181 ) {
F_131 ( V_10 -> V_181 ) ;
V_10 -> V_181 = NULL ;
}
F_10 ( V_10 ) ;
}
#endif
F_132 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_127 == V_10 ) {
F_133 ( & V_10 -> V_147 ) ;
F_10 ( V_10 ) ;
if ( ! ( V_10 -> V_44 & V_182 ) || V_179 > 0 )
break;
V_178 = 1 ;
continue;
} else if ( V_10 -> V_44 & V_182 ) {
if ( F_134 ( & V_127 -> V_146 , & V_10 -> V_146 ,
V_10 -> V_171 ) ) {
if ( V_127 -> V_44 & V_182 ) {
V_179 = 1 ;
if ( V_178 )
break;
} else {
unsigned long V_183 ;
if ( ! V_179 )
V_179 = - 1 ;
F_110 ( & V_127 -> V_30 ) ;
V_183 = F_135 ( V_127 -> V_153 , V_3 ) ;
if ( F_136 ( V_180 ,
V_127 -> V_64 + V_183 * V_3 ) )
V_180 = V_127 -> V_64 + V_183 * V_3 ;
F_118 ( & V_127 -> V_30 ) ;
}
}
}
}
F_137 ( & V_5 -> V_30 ) ;
F_9 ( V_10 ) ;
F_138 ( V_184 , V_10 ) ;
F_124 ( V_185 , V_10 ) ;
if ( ( V_10 -> V_44 & V_182 ) && V_179 < 1 ) {
struct V_148 V_186 ;
struct V_155 * V_142 ;
F_139 ( & V_186 , & V_10 -> V_146 , V_10 -> V_171 ) ;
V_142 = F_140 ( & V_186 ,
V_10 -> V_171 ,
V_10 -> V_5 -> V_7 ,
0 , V_187 | V_188 ) ;
if ( V_142 ) {
if ( V_179 == 0 ) {
F_141 ( V_142 ) ;
V_142 = NULL ;
} else if ( ! ( V_142 -> V_189 & V_190 ) ) {
F_142 ( V_142 , V_180 ) ;
}
}
F_96 ( V_142 ) ;
}
F_143 ( V_10 ) ;
V_168:
F_131 ( V_10 ) ;
}
static int F_144 ( struct V_9 * V_10 , struct V_9 * V_191 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_148 V_146 , * V_192 ;
unsigned long V_193 , V_194 , V_195 , V_196 ;
unsigned long V_197 ;
int V_198 ;
int V_199 = 0 ;
T_1 V_200 ;
unsigned long V_201 = V_13 ;
F_119 ( & V_5 -> V_30 ) ;
if ( V_191 ) {
F_126 ( & V_191 -> V_30 ) ;
memcpy ( & V_146 . V_202 [ 8 ] , & V_191 -> V_146 . V_202 [ 8 ] , 8 ) ;
F_127 ( & V_191 -> V_30 ) ;
V_192 = & V_146 ;
} else {
V_192 = NULL ;
}
V_203:
F_13 ( V_5 ) ;
if ( V_5 -> V_33 . V_59 <= 0 ) {
F_121 ( & V_5 -> V_30 ) ;
F_38 ( L_9 , V_41 ) ;
F_93 ( V_5 ) ;
V_199 = - 1 ;
goto V_168;
}
F_126 ( & V_10 -> V_30 ) ;
if ( V_10 -> V_204 ++ >= V_5 -> V_33 . V_205 ) {
V_5 -> V_33 . V_59 = - 1 ;
F_127 ( & V_10 -> V_30 ) ;
F_121 ( & V_5 -> V_30 ) ;
F_95 ( L_10 ,
V_41 ) ;
F_93 ( V_5 ) ;
V_199 = - 1 ;
goto V_168;
}
F_16 ( V_10 ) ;
memcpy ( V_146 . V_202 , V_10 -> V_146 . V_202 , 8 ) ;
F_145 ( V_5 , V_192 ) ;
memcpy ( & V_146 . V_202 [ 8 ] , V_5 -> V_206 , 8 ) ;
V_196 = ( V_201 - V_10 -> V_64 ) / V_3 ;
V_194 = F_146 ( V_207 ,
V_10 -> V_153 ,
V_5 -> V_33 . V_208 + V_196 ) ;
V_193 = F_146 ( V_207 ,
V_10 -> V_154 ,
V_5 -> V_33 . V_209 + V_196 -
V_5 -> V_33 . V_210 ) ;
V_198 = V_10 -> V_171 ;
V_195 = V_10 -> V_64 ;
F_127 ( & V_10 -> V_30 ) ;
V_197 = V_5 -> V_33 . V_205 *
V_5 -> V_33 . V_211 *
V_5 -> V_37 -> V_212 / V_3 ;
F_121 ( & V_5 -> V_30 ) ;
if ( V_193 <= V_197 ) {
F_131 ( V_10 ) ;
F_93 ( V_5 ) ;
V_199 = - 1 ;
goto V_168;
}
V_200 = V_174 ;
if ( V_10 -> V_44 & V_213 )
V_200 |= V_213 ;
V_191 = F_106 ( V_5 , & V_146 , NULL , V_198 ,
F_147 ( & V_146 ) , V_200 ,
V_194 , V_193 ) ;
if ( F_113 ( V_191 ) ) {
F_131 ( V_10 ) ;
F_93 ( V_5 ) ;
F_38 ( L_11 , V_41 ) ;
V_192 = & V_146 ;
F_119 ( & V_5 -> V_30 ) ;
goto V_203;
}
F_126 ( & V_191 -> V_30 ) ;
V_191 -> V_181 = V_10 ;
V_191 -> V_1 = V_201 ;
V_191 -> V_64 = V_195 ;
F_127 ( & V_191 -> V_30 ) ;
F_148 ( V_191 ) ;
F_131 ( V_191 ) ;
F_93 ( V_5 ) ;
V_168:
return V_199 ;
}
static inline int F_149 ( int type )
{
if ( type & ( V_214 | V_215 | V_160 ) )
return 1 ;
return 0 ;
}
static int F_150 ( struct V_92 * V_92 ,
struct V_216 * V_217 ,
struct V_218 * V_219 ,
int V_220 )
{
int V_199 ;
if ( V_220 <= V_217 -> V_221 ) {
switch ( V_220 ) {
case V_222 :
V_199 = V_217 -> V_223 ;
break;
case V_224 :
V_199 = V_217 -> V_225 ;
break;
default:
V_199 = ! ! F_151 ( V_220 , V_217 -> V_226 ) ;
}
goto V_168;
}
switch ( V_220 ) {
case V_227 :
V_199 = ! ! V_217 -> V_127 ;
break;
case V_228 :
V_199 = F_152 ( & V_217 -> V_127 -> V_146 , V_219 -> V_146 ) ;
break;
case V_222 :
V_199 = F_153 ( V_217 -> V_157 ) ;
if ( V_199 >= V_219 -> V_152 )
V_199 = - V_199 ;
else
V_199 -= 128 ;
V_217 -> V_223 = V_199 ;
break;
case V_229 :
V_199 = F_149 ( V_217 -> V_157 ) ||
! ( V_217 -> V_127 -> V_44 & ( V_230 | V_213 ) ) ;
break;
#ifdef F_154
case V_231 :
{
int V_232 = ! ( V_219 -> V_233 & V_234 ) ;
V_199 = ! ( V_217 -> V_127 -> V_44 & V_235 ) ^ V_232 ;
break;
}
#endif
case V_236 :
V_199 = ( ! V_219 -> V_77 ||
V_219 -> V_77 == V_217 -> V_127 -> V_5 -> V_7 -> V_77 ) ;
break;
case V_237 :
V_199 = F_155 ( V_92 ,
& V_217 -> V_127 -> V_146 , V_217 -> V_157 ,
V_217 -> V_127 -> V_5 -> V_7 -> V_77 ) == V_219 -> V_238 ;
break;
#ifdef F_39
case V_239 :
{
int V_240 = V_219 -> V_233 & ( V_241 | V_242 ) ?
! ! ( V_219 -> V_233 & V_242 ) :
V_217 -> V_127 -> V_5 -> V_33 . V_59 >= 2 ;
V_199 = ( ! ( V_217 -> V_127 -> V_44 & V_174 ) ) ^ V_240 ;
break;
}
#endif
case V_243 :
V_199 = ! ( F_156 ( & V_217 -> V_127 -> V_146 ) ^
F_156 ( V_219 -> V_146 ) ) ;
break;
case V_224 :
V_199 = F_157 ( & V_217 -> V_127 -> V_146 , V_219 -> V_146 ) ;
if ( V_199 > V_217 -> V_127 -> V_171 )
V_199 = V_217 -> V_127 -> V_171 ;
V_217 -> V_225 = V_199 ;
break;
default:
V_199 = 0 ;
}
if ( V_199 )
F_158 ( V_220 , V_217 -> V_226 ) ;
V_217 -> V_221 = V_220 ;
V_168:
return V_199 ;
}
int F_159 ( struct V_92 * V_92 , const struct V_6 * V_244 ,
const struct V_148 * V_245 , unsigned int V_233 ,
struct V_148 * V_246 )
{
struct V_216 V_247 [ 2 ] ,
* V_217 = & V_247 [ 0 ] , * V_248 = & V_247 [ 1 ] ;
struct V_218 V_219 ;
struct V_6 * V_7 ;
int V_249 ;
V_249 = F_160 ( V_245 ) ;
V_219 . V_146 = V_245 ;
V_219 . V_77 = V_244 ? V_244 -> V_77 : 0 ;
V_219 . V_152 = F_153 ( V_249 ) ;
V_219 . V_238 = F_155 ( V_92 , V_245 , V_249 , V_219 . V_77 ) ;
V_219 . V_233 = V_233 ;
V_248 -> V_221 = - 1 ;
V_248 -> V_127 = NULL ;
F_71 () ;
F_161 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_249 & V_159 ) ||
V_219 . V_152 <= V_250 ) &&
V_219 . V_77 && V_7 -> V_77 != V_219 . V_77 )
continue;
V_5 = F_45 ( V_7 ) ;
if ( ! V_5 )
continue;
F_162 ( & V_5 -> V_30 ) ;
F_79 (score->ifa, &idev->addr_list, if_list) {
int V_220 ;
if ( ( V_217 -> V_127 -> V_44 & V_130 ) &&
( ! ( V_217 -> V_127 -> V_44 & V_213 ) ) )
continue;
V_217 -> V_157 = F_160 ( & V_217 -> V_127 -> V_146 ) ;
if ( F_163 ( V_217 -> V_157 == V_158 ||
V_217 -> V_157 & V_159 ) ) {
F_164 ( V_251
L_12
L_13 ,
V_7 -> V_42 ) ;
continue;
}
V_217 -> V_221 = - 1 ;
F_165 ( V_217 -> V_226 , V_252 ) ;
for ( V_220 = 0 ; V_220 < V_252 ; V_220 ++ ) {
int V_253 , V_254 ;
V_253 = F_150 ( V_92 , V_248 , & V_219 , V_220 ) ;
V_254 = F_150 ( V_92 , V_217 , & V_219 , V_220 ) ;
if ( V_253 > V_254 ) {
if ( V_220 == V_222 &&
V_217 -> V_223 > 0 ) {
goto V_255;
}
break;
} else if ( V_253 < V_254 ) {
if ( V_248 -> V_127 )
F_131 ( V_248 -> V_127 ) ;
F_16 ( V_217 -> V_127 ) ;
F_166 ( V_248 , V_217 ) ;
V_217 -> V_127 = V_248 -> V_127 ;
break;
}
}
}
V_255:
F_167 ( & V_5 -> V_30 ) ;
}
F_74 () ;
if ( ! V_248 -> V_127 )
return - V_161 ;
* V_246 = V_248 -> V_127 -> V_146 ;
F_131 ( V_248 -> V_127 ) ;
return 0 ;
}
int F_168 ( struct V_4 * V_5 , struct V_148 * V_146 ,
unsigned char V_256 )
{
struct V_9 * V_10 ;
int V_93 = - V_161 ;
F_79 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_152 == V_257 &&
! ( V_10 -> V_44 & V_256 ) ) {
* V_146 = V_10 -> V_146 ;
V_93 = 0 ;
break;
}
}
return V_93 ;
}
int F_169 ( struct V_6 * V_7 , struct V_148 * V_146 ,
unsigned char V_256 )
{
struct V_4 * V_5 ;
int V_93 = - V_161 ;
F_71 () ;
V_5 = F_45 ( V_7 ) ;
if ( V_5 ) {
F_162 ( & V_5 -> V_30 ) ;
V_93 = F_168 ( V_5 , V_146 , V_256 ) ;
F_167 ( & V_5 -> V_30 ) ;
}
F_74 () ;
return V_93 ;
}
static int F_170 ( struct V_4 * V_5 )
{
int V_258 = 0 ;
struct V_9 * V_10 ;
F_162 ( & V_5 -> V_30 ) ;
F_79 (ifp, &idev->addr_list, if_list)
V_258 ++ ;
F_167 ( & V_5 -> V_30 ) ;
return V_258 ;
}
int F_171 ( struct V_92 * V_92 , const struct V_148 * V_146 ,
const struct V_6 * V_7 , int V_259 )
{
struct V_9 * V_10 ;
unsigned int V_156 = F_103 ( V_146 ) ;
F_109 () ;
F_73 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_172 ( F_28 ( V_10 -> V_5 -> V_7 ) , V_92 ) )
continue;
if ( F_152 ( & V_10 -> V_146 , V_146 ) &&
! ( V_10 -> V_44 & V_130 ) &&
( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_152 & ( V_257 | V_260 ) || V_259 ) ) ) {
F_122 () ;
return 1 ;
}
}
F_122 () ;
return 0 ;
}
static bool F_111 ( struct V_92 * V_92 , const struct V_148 * V_146 ,
struct V_6 * V_7 )
{
unsigned int V_156 = F_103 ( V_146 ) ;
struct V_9 * V_10 ;
F_173 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_172 ( F_28 ( V_10 -> V_5 -> V_7 ) , V_92 ) )
continue;
if ( F_152 ( & V_10 -> V_146 , V_146 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_174 ( const struct V_148 * V_146 ,
const unsigned int V_171 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_127 ;
bool V_199 = false ;
F_71 () ;
V_5 = F_45 ( V_7 ) ;
if ( V_5 ) {
F_162 ( & V_5 -> V_30 ) ;
F_79 (ifa, &idev->addr_list, if_list) {
V_199 = F_134 ( V_146 , & V_127 -> V_146 , V_171 ) ;
if ( V_199 )
break;
}
F_167 ( & V_5 -> V_30 ) ;
}
F_74 () ;
return V_199 ;
}
int F_175 ( const struct V_148 * V_146 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_127 ;
int V_179 ;
V_179 = 0 ;
F_71 () ;
V_5 = F_45 ( V_7 ) ;
if ( V_5 ) {
F_162 ( & V_5 -> V_30 ) ;
F_79 (ifa, &idev->addr_list, if_list) {
V_179 = F_134 ( V_146 , & V_127 -> V_146 ,
V_127 -> V_171 ) ;
if ( V_179 )
break;
}
F_167 ( & V_5 -> V_30 ) ;
}
F_74 () ;
return V_179 ;
}
struct V_9 * F_176 ( struct V_92 * V_92 , const struct V_148 * V_146 ,
struct V_6 * V_7 , int V_259 )
{
struct V_9 * V_10 , * V_261 = NULL ;
unsigned int V_156 = F_103 ( V_146 ) ;
F_109 () ;
F_177 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_172 ( F_28 ( V_10 -> V_5 -> V_7 ) , V_92 ) )
continue;
if ( F_152 ( & V_10 -> V_146 , V_146 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_152 & ( V_257 | V_260 ) || V_259 ) ) {
V_261 = V_10 ;
F_16 ( V_10 ) ;
break;
}
}
}
F_122 () ;
return V_261 ;
}
static void F_178 ( struct V_9 * V_10 , int V_262 )
{
if ( V_10 -> V_44 & V_182 ) {
F_126 ( & V_10 -> V_30 ) ;
F_9 ( V_10 ) ;
V_10 -> V_44 |= V_130 ;
if ( V_262 )
V_10 -> V_44 |= V_263 ;
F_127 ( & V_10 -> V_30 ) ;
if ( V_262 )
F_138 ( 0 , V_10 ) ;
F_131 ( V_10 ) ;
#ifdef F_39
} else if ( V_10 -> V_44 & V_174 ) {
struct V_9 * V_181 ;
F_126 ( & V_10 -> V_30 ) ;
V_181 = V_10 -> V_181 ;
if ( V_181 ) {
F_16 ( V_181 ) ;
F_127 ( & V_10 -> V_30 ) ;
F_144 ( V_181 , V_10 ) ;
F_131 ( V_181 ) ;
} else {
F_127 ( & V_10 -> V_30 ) ;
}
F_125 ( V_10 ) ;
#endif
} else
F_125 ( V_10 ) ;
}
static int F_179 ( struct V_9 * V_10 )
{
int V_93 = - V_264 ;
F_110 ( & V_10 -> V_169 ) ;
if ( V_10 -> V_140 == V_265 ) {
V_10 -> V_140 = V_266 ;
V_93 = 0 ;
}
F_118 ( & V_10 -> V_169 ) ;
return V_93 ;
}
void F_180 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_179 ( V_10 ) ) {
F_131 ( V_10 ) ;
return;
}
F_181 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_42 , & V_10 -> V_146 ) ;
if ( V_5 -> V_33 . V_47 > 1 && ! V_5 -> V_33 . V_164 ) {
struct V_148 V_146 ;
V_146 . V_267 [ 0 ] = F_182 ( 0xfe800000 ) ;
V_146 . V_267 [ 1 ] = 0 ;
if ( ! F_183 ( V_146 . V_202 + 8 , V_5 -> V_7 ) &&
F_152 ( & V_10 -> V_146 , & V_146 ) ) {
V_5 -> V_33 . V_164 = 1 ;
F_38 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_42 ) ;
}
}
F_178 ( V_10 , 1 ) ;
}
void F_184 ( struct V_6 * V_7 , const struct V_148 * V_146 )
{
struct V_148 V_268 ;
if ( V_7 -> V_44 & ( V_46 | V_45 ) )
return;
F_185 ( V_146 , & V_268 ) ;
F_43 ( V_7 , & V_268 ) ;
}
void F_186 ( struct V_4 * V_5 , const struct V_148 * V_146 )
{
struct V_148 V_268 ;
if ( V_5 -> V_7 -> V_44 & ( V_46 | V_45 ) )
return;
F_185 ( V_146 , & V_268 ) ;
F_187 ( V_5 , & V_268 ) ;
}
static void F_80 ( struct V_9 * V_10 )
{
struct V_148 V_146 ;
if ( V_10 -> V_171 == 127 )
return;
F_139 ( & V_146 , & V_10 -> V_146 , V_10 -> V_171 ) ;
if ( F_188 ( & V_146 ) )
return;
F_189 ( V_10 -> V_5 -> V_7 , & V_146 ) ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_148 V_146 ;
if ( V_10 -> V_171 == 127 )
return;
F_139 ( & V_146 , & V_10 -> V_146 , V_10 -> V_171 ) ;
if ( F_188 ( & V_146 ) )
return;
F_190 ( V_10 -> V_5 , & V_146 ) ;
}
static int F_191 ( T_3 * V_269 , struct V_6 * V_7 )
{
if ( V_7 -> V_270 != V_271 )
return - 1 ;
memcpy ( V_269 , V_7 -> V_272 , 3 ) ;
memcpy ( V_269 + 5 , V_7 -> V_272 + 3 , 3 ) ;
if ( V_7 -> V_273 ) {
V_269 [ 3 ] = ( V_7 -> V_273 >> 8 ) & 0xFF ;
V_269 [ 4 ] = V_7 -> V_273 & 0xFF ;
} else {
V_269 [ 3 ] = 0xFF ;
V_269 [ 4 ] = 0xFE ;
V_269 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_192 ( T_3 * V_269 , struct V_6 * V_7 )
{
if ( V_7 -> V_270 != V_274 )
return - 1 ;
memcpy ( V_269 , V_7 -> V_272 , 8 ) ;
V_269 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_193 ( T_3 * V_269 , struct V_6 * V_7 )
{
union V_275 * V_276 ;
if ( V_7 -> V_270 != V_277 )
return - 1 ;
V_276 = (union V_275 * ) V_7 -> V_272 ;
memcpy ( V_269 , & V_276 -> V_278 . V_279 , sizeof( V_276 -> V_278 . V_279 ) ) ;
V_269 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_194 ( T_3 * V_269 , struct V_6 * V_7 )
{
if ( V_7 -> V_270 != V_280 )
return - 1 ;
memset ( V_269 , 0 , 7 ) ;
V_269 [ 7 ] = * ( T_3 * ) V_7 -> V_272 ;
return 0 ;
}
static int F_195 ( T_3 * V_269 , struct V_6 * V_7 )
{
if ( V_7 -> V_270 != V_281 )
return - 1 ;
memcpy ( V_269 , V_7 -> V_272 + 12 , 8 ) ;
V_269 [ 0 ] |= 2 ;
return 0 ;
}
static int F_196 ( T_3 * V_269 , T_4 V_146 )
{
if ( V_146 == 0 )
return - 1 ;
V_269 [ 0 ] = ( F_197 ( V_146 ) || F_198 ( V_146 ) ||
F_199 ( V_146 ) || F_200 ( V_146 ) ||
F_201 ( V_146 ) || F_202 ( V_146 ) ||
F_203 ( V_146 ) || F_204 ( V_146 ) ||
F_205 ( V_146 ) || F_206 ( V_146 ) ||
F_207 ( V_146 ) ) ? 0x00 : 0x02 ;
V_269 [ 1 ] = 0 ;
V_269 [ 2 ] = 0x5E ;
V_269 [ 3 ] = 0xFE ;
memcpy ( V_269 + 4 , & V_146 , 4 ) ;
return 0 ;
}
static int F_208 ( T_3 * V_269 , struct V_6 * V_7 )
{
if ( V_7 -> V_50 & V_51 )
return F_196 ( V_269 , * ( T_4 * ) V_7 -> V_272 ) ;
return - 1 ;
}
static int F_209 ( T_3 * V_269 , struct V_6 * V_7 )
{
return F_196 ( V_269 , * ( T_4 * ) V_7 -> V_272 ) ;
}
static int F_210 ( T_3 * V_269 , struct V_6 * V_7 )
{
memcpy ( V_269 , V_7 -> V_282 , 3 ) ;
memcpy ( V_269 + 5 , V_7 -> V_282 + 3 , 3 ) ;
V_269 [ 3 ] = 0xFF ;
V_269 [ 4 ] = 0xFE ;
V_269 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_183 ( T_3 * V_269 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_283 :
case V_284 :
return F_191 ( V_269 , V_7 ) ;
case V_285 :
return F_194 ( V_269 , V_7 ) ;
case V_286 :
return F_195 ( V_269 , V_7 ) ;
case V_49 :
return F_208 ( V_269 , V_7 ) ;
case V_287 :
return F_209 ( V_269 , V_7 ) ;
case V_288 :
return F_192 ( V_269 , V_7 ) ;
case V_289 :
return F_193 ( V_269 , V_7 ) ;
case V_57 :
return F_210 ( V_269 , V_7 ) ;
}
return - 1 ;
}
static int F_211 ( T_3 * V_269 , struct V_4 * V_5 )
{
int V_93 = - 1 ;
struct V_9 * V_10 ;
F_162 ( & V_5 -> V_30 ) ;
F_79 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_152 == V_257 && ! ( V_10 -> V_44 & V_130 ) ) {
memcpy ( V_269 , V_10 -> V_146 . V_202 + 8 , 8 ) ;
V_93 = 0 ;
break;
}
}
F_167 ( & V_5 -> V_30 ) ;
return V_93 ;
}
static void F_212 ( struct V_4 * V_5 )
{
V_290:
F_213 ( V_5 -> V_206 , sizeof( V_5 -> V_206 ) ) ;
V_5 -> V_206 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_206 [ 0 ] == 0xfd &&
( V_5 -> V_206 [ 1 ] & V_5 -> V_206 [ 2 ] & V_5 -> V_206 [ 3 ] & V_5 -> V_206 [ 4 ] & V_5 -> V_206 [ 5 ] & V_5 -> V_206 [ 6 ] ) == 0xff &&
( V_5 -> V_206 [ 7 ] & 0x80 ) )
goto V_290;
if ( ( V_5 -> V_206 [ 0 ] | V_5 -> V_206 [ 1 ] ) == 0 ) {
if ( V_5 -> V_206 [ 2 ] == 0x5e && V_5 -> V_206 [ 3 ] == 0xfe )
goto V_290;
if ( ( V_5 -> V_206 [ 2 ] | V_5 -> V_206 [ 3 ] | V_5 -> V_206 [ 4 ] | V_5 -> V_206 [ 5 ] | V_5 -> V_206 [ 6 ] | V_5 -> V_206 [ 7 ] ) == 0x00 )
goto V_290;
}
}
static void V_55 ( unsigned long V_291 )
{
struct V_4 * V_5 = (struct V_4 * ) V_291 ;
unsigned long V_180 ;
F_109 () ;
F_129 ( & V_5 -> V_30 ) ;
if ( V_5 -> V_43 )
goto V_168;
F_212 ( V_5 ) ;
V_180 = V_13 +
V_5 -> V_33 . V_209 * V_3 -
V_5 -> V_33 . V_205 * V_5 -> V_33 . V_211 * V_5 -> V_37 -> V_212 -
V_5 -> V_33 . V_210 * V_3 ;
if ( F_136 ( V_180 , V_13 ) ) {
F_95 ( L_16 ,
V_41 , V_5 -> V_7 -> V_42 ) ;
goto V_168;
}
if ( ! F_14 ( & V_5 -> V_54 , V_180 ) )
F_13 ( V_5 ) ;
V_168:
F_137 ( & V_5 -> V_30 ) ;
F_122 () ;
F_93 ( V_5 ) ;
}
static void F_145 ( struct V_4 * V_5 , struct V_148 * V_192 )
{
if ( V_192 && memcmp ( V_5 -> V_206 , & V_192 -> V_202 [ 8 ] , 8 ) == 0 )
F_212 ( V_5 ) ;
}
static void
F_214 ( struct V_148 * V_292 , int V_293 , struct V_6 * V_7 ,
unsigned long V_180 , T_1 V_44 )
{
struct V_294 V_295 = {
. V_296 = V_297 ,
. V_298 = V_299 ,
. V_300 = V_7 -> V_77 ,
. V_301 = V_180 ,
. V_302 = V_293 ,
. V_303 = V_304 | V_44 ,
. V_305 . V_306 = F_28 ( V_7 ) ,
. V_307 = V_308 ,
} ;
V_295 . V_309 = * V_292 ;
#if F_37 ( V_48 )
if ( V_7 -> type == V_49 && ( V_7 -> V_44 & V_310 ) )
V_295 . V_303 |= V_311 ;
#endif
F_215 ( & V_295 ) ;
}
static struct V_155 * F_140 ( const struct V_148 * V_292 ,
int V_293 ,
const struct V_6 * V_7 ,
T_1 V_44 , T_1 V_312 )
{
struct V_313 * V_314 ;
struct V_155 * V_142 = NULL ;
struct V_315 * V_134 ;
V_134 = F_216 ( F_28 ( V_7 ) , V_297 ) ;
if ( V_134 == NULL )
return NULL ;
F_162 ( & V_134 -> V_316 ) ;
V_314 = F_217 ( & V_134 -> V_317 , V_292 , V_293 , NULL , 0 ) ;
if ( ! V_314 )
goto V_168;
for ( V_142 = V_314 -> V_318 ; V_142 ; V_142 = V_142 -> V_219 . V_319 ) {
if ( V_142 -> V_219 . V_7 -> V_77 != V_7 -> V_77 )
continue;
if ( ( V_142 -> V_189 & V_44 ) != V_44 )
continue;
if ( ( V_142 -> V_189 & V_312 ) != 0 )
continue;
F_218 ( & V_142 -> V_219 ) ;
break;
}
V_168:
F_167 ( & V_134 -> V_316 ) ;
return V_142 ;
}
static void F_219 ( struct V_6 * V_7 )
{
struct V_294 V_295 = {
. V_296 = V_320 ,
. V_298 = V_299 ,
. V_300 = V_7 -> V_77 ,
. V_302 = 8 ,
. V_303 = V_304 ,
. V_305 . V_306 = F_28 ( V_7 ) ,
} ;
F_220 ( & V_295 . V_309 , F_182 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_215 ( & V_295 ) ;
}
static void F_221 ( struct V_6 * V_7 )
{
struct V_294 V_295 = {
. V_296 = V_321 ,
. V_298 = V_299 ,
. V_300 = V_7 -> V_77 ,
. V_302 = 96 ,
. V_303 = V_304 | V_311 ,
. V_305 . V_306 = F_28 ( V_7 ) ,
} ;
F_215 ( & V_295 ) ;
}
static struct V_4 * F_222 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_24 () ;
V_5 = F_44 ( V_7 ) ;
if ( ! V_5 )
return F_108 ( - V_94 ) ;
if ( V_5 -> V_33 . V_164 )
return F_108 ( - V_165 ) ;
if ( ! ( V_7 -> V_44 & V_46 ) )
F_219 ( V_7 ) ;
return V_5 ;
}
void F_223 ( struct V_6 * V_7 , T_3 * V_322 , int V_126 , bool V_323 )
{
struct V_324 * V_325 ;
V_207 V_153 ;
V_207 V_154 ;
int V_157 ;
struct V_4 * V_104 ;
struct V_92 * V_92 = F_28 ( V_7 ) ;
V_325 = (struct V_324 * ) V_322 ;
if ( V_126 < sizeof( struct V_324 ) ) {
F_32 ( L_17 ) ;
return;
}
V_157 = F_107 ( & V_325 -> V_186 ) ;
if ( V_157 & ( V_159 | V_326 ) )
return;
V_153 = F_224 ( V_325 -> V_327 ) ;
V_154 = F_224 ( V_325 -> V_328 ) ;
if ( V_154 > V_153 ) {
F_225 ( L_18 ) ;
return;
}
V_104 = F_226 ( V_7 ) ;
if ( V_104 == NULL ) {
F_227 ( L_19 ,
V_7 -> V_42 ) ;
return;
}
if ( V_325 -> V_179 ) {
struct V_155 * V_142 ;
unsigned long V_329 ;
if ( V_3 > V_330 )
V_329 = F_135 ( V_153 , V_3 ) ;
else
V_329 = F_135 ( V_153 , V_330 ) ;
if ( F_228 ( V_329 ) )
V_329 *= V_3 ;
V_142 = F_140 ( & V_325 -> V_186 ,
V_325 -> V_171 ,
V_7 ,
V_331 | V_332 ,
V_187 | V_188 ) ;
if ( V_142 ) {
if ( V_153 == 0 ) {
F_141 ( V_142 ) ;
V_142 = NULL ;
} else if ( F_228 ( V_329 ) ) {
F_142 ( V_142 , V_13 + V_329 ) ;
} else {
F_229 ( V_142 ) ;
}
} else if ( V_153 ) {
T_5 V_180 = 0 ;
int V_44 = V_331 | V_332 ;
if ( F_228 ( V_329 ) ) {
V_44 |= V_190 ;
V_180 = F_230 ( V_329 ) ;
}
F_214 ( & V_325 -> V_186 , V_325 -> V_171 ,
V_7 , V_180 , V_44 ) ;
}
F_96 ( V_142 ) ;
}
if ( V_325 -> V_333 && V_104 -> V_33 . V_333 ) {
struct V_9 * V_10 ;
struct V_148 V_146 ;
int V_334 = 0 , V_335 = 0 ;
bool V_172 = false ;
if ( V_325 -> V_171 == 64 ) {
memcpy ( & V_146 , & V_325 -> V_186 , 8 ) ;
if ( ! F_188 ( & V_104 -> V_60 ) ) {
F_162 ( & V_104 -> V_30 ) ;
memcpy ( V_146 . V_202 + 8 ,
V_104 -> V_60 . V_202 + 8 , 8 ) ;
F_167 ( & V_104 -> V_30 ) ;
V_172 = true ;
} else if ( F_183 ( V_146 . V_202 + 8 , V_7 ) &&
F_211 ( V_146 . V_202 + 8 , V_104 ) ) {
F_93 ( V_104 ) ;
return;
}
goto V_336;
}
F_227 ( L_20 ,
V_325 -> V_171 ) ;
F_93 ( V_104 ) ;
return;
V_336:
V_10 = F_176 ( V_92 , & V_146 , V_7 , 1 ) ;
if ( V_10 == NULL && V_153 ) {
int V_337 = V_104 -> V_33 . V_337 ;
T_1 V_200 = 0 ;
#ifdef F_231
if ( V_104 -> V_33 . V_338 &&
! V_92 -> V_16 . V_108 -> V_39 && V_323 )
V_200 = V_213 ;
#endif
if ( ! V_337 ||
F_170 ( V_104 ) < V_337 )
V_10 = F_106 ( V_104 , & V_146 , NULL ,
V_325 -> V_171 ,
V_157 & V_339 ,
V_200 , V_153 ,
V_154 ) ;
if ( F_232 ( V_10 ) ) {
F_93 ( V_104 ) ;
return;
}
V_335 = 0 ;
V_334 = 1 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_172 = V_172 ;
F_148 ( V_10 ) ;
}
if ( V_10 ) {
int V_44 ;
unsigned long V_201 ;
#ifdef F_39
struct V_9 * V_191 ;
#endif
T_1 V_340 ;
F_110 ( & V_10 -> V_30 ) ;
V_201 = V_13 ;
if ( V_10 -> V_153 > ( V_201 - V_10 -> V_64 ) / V_3 )
V_340 = V_10 -> V_153 - ( V_201 - V_10 -> V_64 ) / V_3 ;
else
V_340 = 0 ;
if ( ! V_335 && ! V_334 && V_340 ) {
const T_1 V_341 = F_233 (
V_340 , ( T_1 ) V_342 ) ;
V_153 = F_234 ( V_153 , V_341 ) ;
V_335 = 1 ;
}
if ( V_335 ) {
V_10 -> V_153 = V_153 ;
V_10 -> V_154 = V_154 ;
V_10 -> V_64 = V_201 ;
V_44 = V_10 -> V_44 ;
V_10 -> V_44 &= ~ V_230 ;
F_118 ( & V_10 -> V_30 ) ;
if ( ! ( V_44 & V_130 ) )
F_138 ( 0 , V_10 ) ;
} else
F_118 ( & V_10 -> V_30 ) ;
#ifdef F_39
F_162 ( & V_104 -> V_30 ) ;
F_79 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_196 , V_343 , V_344 ;
if ( V_10 != V_191 -> V_181 )
continue;
V_196 = ( V_201 - V_191 -> V_1 ) / V_3 ;
V_343 = V_104 -> V_33 . V_208 - V_196 ;
if ( V_343 < 0 )
V_343 = 0 ;
V_344 = V_104 -> V_33 . V_209 -
V_104 -> V_33 . V_210 -
V_196 ;
if ( V_344 < 0 )
V_344 = 0 ;
if ( V_153 > V_343 )
V_153 = V_343 ;
if ( V_154 > V_344 )
V_154 = V_344 ;
F_110 ( & V_191 -> V_30 ) ;
V_44 = V_191 -> V_44 ;
V_191 -> V_153 = V_153 ;
V_191 -> V_154 = V_154 ;
V_191 -> V_64 = V_201 ;
if ( V_154 > 0 )
V_191 -> V_44 &= ~ V_230 ;
F_118 ( & V_191 -> V_30 ) ;
if ( ! ( V_44 & V_130 ) )
F_138 ( 0 , V_191 ) ;
}
if ( ( V_334 || F_235 ( & V_104 -> V_53 ) ) && V_104 -> V_33 . V_59 > 0 ) {
F_167 ( & V_104 -> V_30 ) ;
F_144 ( V_10 , NULL ) ;
} else {
F_167 ( & V_104 -> V_30 ) ;
}
#endif
F_131 ( V_10 ) ;
F_236 ( 0 ) ;
}
}
F_237 ( V_345 , V_104 , V_325 ) ;
F_93 ( V_104 ) ;
}
int F_238 ( struct V_92 * V_92 , void T_6 * V_346 )
{
struct V_347 V_348 ;
struct V_6 * V_7 ;
int V_93 = - V_106 ;
F_239 () ;
V_93 = - V_349 ;
if ( F_240 ( & V_348 , V_346 , sizeof( struct V_347 ) ) )
goto V_350;
V_7 = F_67 ( V_92 , V_348 . V_351 ) ;
V_93 = - V_162 ;
if ( V_7 == NULL )
goto V_350;
#if F_37 ( V_48 )
if ( V_7 -> type == V_49 ) {
const struct V_352 * V_353 = V_7 -> V_354 ;
struct V_355 V_356 ;
struct V_357 V_135 ;
V_93 = - V_161 ;
if ( ! ( F_107 ( & V_348 . V_358 ) & V_215 ) )
goto V_350;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_135 . V_359 . V_245 = V_348 . V_358 . V_267 [ 3 ] ;
V_135 . V_359 . V_246 = 0 ;
V_135 . V_359 . V_360 = 4 ;
V_135 . V_359 . V_361 = 5 ;
V_135 . V_359 . V_362 = V_363 ;
V_135 . V_359 . V_364 = 64 ;
V_356 . V_365 . V_366 = ( V_367 void T_6 * ) & V_135 ;
if ( V_353 -> V_368 ) {
T_7 V_369 = F_241 () ;
F_242 ( V_370 ) ;
V_93 = V_353 -> V_368 ( V_7 , & V_356 , V_371 ) ;
F_242 ( V_369 ) ;
} else
V_93 = - V_372 ;
if ( V_93 == 0 ) {
V_93 = - V_94 ;
V_7 = F_243 ( V_92 , V_135 . V_42 ) ;
if ( ! V_7 )
goto V_350;
V_93 = F_244 ( V_7 ) ;
}
}
#endif
V_350:
F_87 () ;
return V_93 ;
}
static int F_245 ( struct V_92 * V_92 , int V_77 , const struct V_148 * V_292 ,
const struct V_148 * V_373 ,
unsigned int V_293 , T_8 V_374 , V_207 V_154 ,
V_207 V_153 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_152 ;
T_1 V_44 ;
T_5 V_180 ;
unsigned long V_375 ;
F_24 () ;
if ( V_293 > 128 )
return - V_106 ;
if ( ! V_153 || V_154 > V_153 )
return - V_106 ;
V_7 = F_67 ( V_92 , V_77 ) ;
if ( ! V_7 )
return - V_162 ;
V_5 = F_222 ( V_7 ) ;
if ( F_113 ( V_5 ) )
return F_114 ( V_5 ) ;
V_152 = F_147 ( V_292 ) ;
V_375 = F_135 ( V_153 , V_3 ) ;
if ( F_228 ( V_375 ) ) {
V_180 = F_230 ( V_375 * V_3 ) ;
V_153 = V_375 ;
V_44 = V_190 ;
} else {
V_180 = 0 ;
V_44 = 0 ;
V_374 |= V_182 ;
}
V_375 = F_135 ( V_154 , V_3 ) ;
if ( F_228 ( V_375 ) ) {
if ( V_375 == 0 )
V_374 |= V_230 ;
V_154 = V_375 ;
}
V_10 = F_106 ( V_5 , V_292 , V_373 , V_293 , V_152 , V_374 ,
V_153 , V_154 ) ;
if ( ! F_113 ( V_10 ) ) {
F_214 ( & V_10 -> V_146 , V_10 -> V_171 , V_7 ,
V_180 , V_44 ) ;
F_148 ( V_10 ) ;
F_131 ( V_10 ) ;
F_236 ( 0 ) ;
return 0 ;
}
return F_114 ( V_10 ) ;
}
static int F_246 ( struct V_92 * V_92 , int V_77 , const struct V_148 * V_292 ,
unsigned int V_293 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_293 > 128 )
return - V_106 ;
V_7 = F_67 ( V_92 , V_77 ) ;
if ( ! V_7 )
return - V_162 ;
if ( ( V_5 = F_45 ( V_7 ) ) == NULL )
return - V_376 ;
F_162 ( & V_5 -> V_30 ) ;
F_79 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_171 == V_293 &&
F_152 ( V_292 , & V_10 -> V_146 ) ) {
F_16 ( V_10 ) ;
F_167 ( & V_5 -> V_30 ) ;
F_125 ( V_10 ) ;
return 0 ;
}
}
F_167 ( & V_5 -> V_30 ) ;
return - V_161 ;
}
int F_247 ( struct V_92 * V_92 , void T_6 * V_346 )
{
struct V_347 V_348 ;
int V_93 ;
if ( ! F_248 ( V_92 -> V_377 , V_378 ) )
return - V_379 ;
if ( F_240 ( & V_348 , V_346 , sizeof( struct V_347 ) ) )
return - V_349 ;
F_239 () ;
V_93 = F_245 ( V_92 , V_348 . V_351 , & V_348 . V_358 , NULL ,
V_348 . V_380 , V_182 ,
V_381 , V_381 ) ;
F_87 () ;
return V_93 ;
}
int F_249 ( struct V_92 * V_92 , void T_6 * V_346 )
{
struct V_347 V_348 ;
int V_93 ;
if ( ! F_248 ( V_92 -> V_377 , V_378 ) )
return - V_379 ;
if ( F_240 ( & V_348 , V_346 , sizeof( struct V_347 ) ) )
return - V_349 ;
F_239 () ;
V_93 = F_246 ( V_92 , V_348 . V_351 , & V_348 . V_358 ,
V_348 . V_380 ) ;
F_87 () ;
return V_93 ;
}
static void F_250 ( struct V_4 * V_5 , const struct V_148 * V_146 ,
int V_293 , int V_152 )
{
struct V_9 * V_10 ;
V_10 = F_106 ( V_5 , V_146 , NULL , V_293 ,
V_152 , V_182 , 0 , 0 ) ;
if ( ! F_113 ( V_10 ) ) {
F_126 ( & V_10 -> V_30 ) ;
V_10 -> V_44 &= ~ V_130 ;
F_127 ( & V_10 -> V_30 ) ;
F_138 ( V_382 , V_10 ) ;
F_131 ( V_10 ) ;
}
}
static void F_251 ( struct V_4 * V_5 )
{
struct V_148 V_146 ;
struct V_6 * V_7 ;
struct V_92 * V_92 = F_28 ( V_5 -> V_7 ) ;
int V_152 ;
F_24 () ;
memset ( & V_146 , 0 , sizeof( struct V_148 ) ) ;
memcpy ( & V_146 . V_267 [ 3 ] , V_5 -> V_7 -> V_272 , 4 ) ;
if ( V_5 -> V_7 -> V_44 & V_310 ) {
V_146 . V_267 [ 0 ] = F_182 ( 0xfe800000 ) ;
V_152 = V_257 ;
} else {
V_152 = V_215 ;
}
if ( V_146 . V_267 [ 3 ] ) {
F_250 ( V_5 , & V_146 , 128 , V_152 ) ;
return;
}
F_83 (net, dev) {
struct V_383 * V_384 = F_252 ( V_7 ) ;
if ( V_384 && ( V_7 -> V_44 & V_70 ) ) {
struct V_385 * V_127 ;
int V_386 = V_152 ;
for ( V_127 = V_384 -> V_387 ; V_127 ; V_127 = V_127 -> V_388 ) {
int V_293 ;
V_146 . V_267 [ 3 ] = V_127 -> V_389 ;
if ( V_127 -> V_390 == V_391 )
continue;
if ( V_127 -> V_390 >= V_392 ) {
if ( V_5 -> V_7 -> V_44 & V_310 )
continue;
V_386 |= V_260 ;
}
if ( V_5 -> V_7 -> V_44 & V_310 )
V_293 = 64 ;
else
V_293 = 96 ;
F_250 ( V_5 , & V_146 , V_293 , V_386 ) ;
}
}
}
}
static void F_253 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_393 ;
struct V_9 * V_394 ;
struct V_155 * V_395 ;
F_24 () ;
if ( ( V_5 = F_44 ( V_7 ) ) == NULL ) {
F_92 ( L_21 , V_41 ) ;
return;
}
F_250 ( V_5 , & V_396 , 128 , V_260 ) ;
F_83 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_393 -> V_42 , V_7 -> V_42 ) )
continue;
V_5 = F_45 ( V_393 ) ;
if ( ! V_5 )
continue;
F_162 ( & V_5 -> V_30 ) ;
F_79 (sp_ifa, &idev->addr_list, if_list) {
if ( V_394 -> V_44 & ( V_263 | V_130 ) )
continue;
if ( V_394 -> V_142 )
continue;
V_395 = F_112 ( V_5 , & V_394 -> V_146 , 0 ) ;
if ( ! F_113 ( V_395 ) ) {
V_394 -> V_142 = V_395 ;
F_254 ( V_395 ) ;
}
}
F_167 ( & V_5 -> V_30 ) ;
}
}
static void F_255 ( struct V_4 * V_5 , const struct V_148 * V_146 )
{
struct V_9 * V_10 ;
T_1 V_200 = V_182 ;
#ifdef F_231
if ( V_5 -> V_33 . V_338 &&
! F_28 ( V_5 -> V_7 ) -> V_16 . V_108 -> V_39 )
V_200 |= V_213 ;
#endif
V_10 = F_106 ( V_5 , V_146 , NULL , 64 , V_257 , V_200 , 0 , 0 ) ;
if ( ! F_113 ( V_10 ) ) {
F_214 ( & V_10 -> V_146 , V_10 -> V_171 , V_5 -> V_7 , 0 , 0 ) ;
F_148 ( V_10 ) ;
F_131 ( V_10 ) ;
}
}
static void F_256 ( struct V_6 * V_7 )
{
struct V_148 V_146 ;
struct V_4 * V_5 ;
F_24 () ;
if ( ( V_7 -> type != V_283 ) &&
( V_7 -> type != V_284 ) &&
( V_7 -> type != V_285 ) &&
( V_7 -> type != V_286 ) &&
( V_7 -> type != V_288 ) &&
( V_7 -> type != V_289 ) &&
( V_7 -> type != V_57 ) ) {
return;
}
V_5 = F_222 ( V_7 ) ;
if ( F_113 ( V_5 ) )
return;
memset ( & V_146 , 0 , sizeof( struct V_148 ) ) ;
V_146 . V_267 [ 0 ] = F_182 ( 0xFE800000 ) ;
if ( F_183 ( V_146 . V_202 + 8 , V_7 ) == 0 )
F_255 ( V_5 , & V_146 ) ;
}
static void F_257 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_24 () ;
if ( ( V_5 = F_44 ( V_7 ) ) == NULL ) {
F_92 ( L_21 , V_41 ) ;
return;
}
if ( V_7 -> V_50 & V_51 ) {
struct V_148 V_146 ;
F_220 ( & V_146 , F_182 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_214 ( & V_146 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_183 ( V_146 . V_202 + 8 , V_7 ) )
F_255 ( V_5 , & V_146 ) ;
return;
}
F_251 ( V_5 ) ;
if ( V_7 -> V_44 & V_310 )
F_219 ( V_7 ) ;
else
F_221 ( V_7 ) ;
}
static void F_258 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_148 V_146 ;
F_24 () ;
if ( ( V_5 = F_44 ( V_7 ) ) == NULL ) {
F_92 ( L_21 , V_41 ) ;
return;
}
F_220 ( & V_146 , F_182 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_214 ( & V_146 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_183 ( V_146 . V_202 + 8 , V_7 ) )
F_255 ( V_5 , & V_146 ) ;
}
static inline int
F_259 ( struct V_4 * V_5 , struct V_6 * V_397 )
{
struct V_148 V_398 ;
if ( ! F_169 ( V_397 , & V_398 , V_130 ) ) {
F_255 ( V_5 , & V_398 ) ;
return 0 ;
}
return - 1 ;
}
static int F_260 ( struct V_399 * V_400 , unsigned long V_82 ,
void * V_401 )
{
struct V_6 * V_7 = F_261 ( V_401 ) ;
struct V_4 * V_5 = F_45 ( V_7 ) ;
int V_402 = 0 ;
int V_93 ;
switch ( V_82 ) {
case V_403 :
if ( ! V_5 && V_7 -> V_28 >= V_29 ) {
V_5 = F_23 ( V_7 ) ;
if ( ! V_5 )
return F_262 ( - V_26 ) ;
}
break;
case V_176 :
case V_404 :
if ( V_7 -> V_44 & V_405 )
break;
if ( V_82 == V_176 ) {
if ( ! F_4 ( V_7 ) ) {
F_38 ( L_22 ,
V_7 -> V_42 ) ;
break;
}
if ( ! V_5 && V_7 -> V_28 >= V_29 )
V_5 = F_23 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_62 |= V_63 ;
V_402 = 1 ;
}
} else {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_62 & V_63 )
break;
V_5 -> V_62 |= V_63 ;
}
F_38 ( L_23 ,
V_7 -> V_42 ) ;
V_402 = 1 ;
}
switch ( V_7 -> type ) {
#if F_37 ( V_48 )
case V_49 :
F_257 ( V_7 ) ;
break;
#endif
#if F_37 ( V_406 )
case V_287 :
F_258 ( V_7 ) ;
break;
#endif
case V_407 :
F_253 ( V_7 ) ;
break;
default:
F_256 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_402 )
F_263 ( V_5 ) ;
if ( V_5 -> V_33 . V_35 != V_7 -> V_28 &&
V_7 -> V_28 >= V_29 ) {
F_264 ( V_7 , V_7 -> V_28 ) ;
V_5 -> V_33 . V_35 = V_7 -> V_28 ;
}
V_5 -> V_64 = V_13 ;
F_265 ( V_408 , V_5 ) ;
if ( V_7 -> V_28 < V_29 )
F_266 ( V_7 , 1 ) ;
}
break;
case V_409 :
if ( V_5 && V_7 -> V_28 >= V_29 ) {
F_264 ( V_7 , V_7 -> V_28 ) ;
V_5 -> V_33 . V_35 = V_7 -> V_28 ;
break;
}
if ( ! V_5 && V_7 -> V_28 >= V_29 ) {
V_5 = F_23 ( V_7 ) ;
if ( V_5 )
break;
}
case V_185 :
case V_410 :
F_266 ( V_7 , V_82 != V_185 ) ;
break;
case V_411 :
if ( V_5 ) {
F_267 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_93 = F_35 ( V_5 ) ;
if ( V_93 )
return F_262 ( V_93 ) ;
}
break;
case V_412 :
case V_413 :
F_268 ( V_7 , V_82 ) ;
break;
}
return V_414 ;
}
static void F_268 ( struct V_6 * V_7 , unsigned long V_82 )
{
struct V_4 * V_5 ;
F_24 () ;
V_5 = F_45 ( V_7 ) ;
if ( V_82 == V_413 )
F_269 ( V_5 ) ;
else if ( V_82 == V_412 )
F_270 ( V_5 ) ;
}
static int F_266 ( struct V_6 * V_7 , int V_415 )
{
struct V_92 * V_92 = F_28 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_127 ;
int V_140 , V_220 ;
F_24 () ;
F_271 ( V_92 , V_7 ) ;
F_272 ( & V_38 , V_7 ) ;
V_5 = F_45 ( V_7 ) ;
if ( V_5 == NULL )
return - V_162 ;
if ( V_415 ) {
V_5 -> V_43 = 1 ;
F_273 ( V_7 -> V_65 , NULL ) ;
F_267 ( V_5 ) ;
}
for ( V_220 = 0 ; V_220 < V_416 ; V_220 ++ ) {
struct V_117 * V_113 = & V_173 [ V_220 ] ;
F_126 ( & V_166 ) ;
V_417:
F_73 (ifa, h, addr_lst) {
if ( V_127 -> V_5 == V_5 ) {
F_128 ( & V_127 -> V_139 ) ;
F_9 ( V_127 ) ;
goto V_417;
}
}
F_127 ( & V_166 ) ;
}
F_129 ( & V_5 -> V_30 ) ;
F_6 ( V_5 ) ;
if ( ! V_415 )
V_5 -> V_62 &= ~ ( V_418 | V_419 | V_63 ) ;
#ifdef F_39
if ( V_415 && F_7 ( & V_5 -> V_54 ) )
F_93 ( V_5 ) ;
while ( ! F_235 ( & V_5 -> V_53 ) ) {
V_127 = F_274 ( & V_5 -> V_53 ,
struct V_9 , V_175 ) ;
F_130 ( & V_127 -> V_175 ) ;
F_137 ( & V_5 -> V_30 ) ;
F_126 ( & V_127 -> V_30 ) ;
if ( V_127 -> V_181 ) {
F_131 ( V_127 -> V_181 ) ;
V_127 -> V_181 = NULL ;
}
F_127 ( & V_127 -> V_30 ) ;
F_131 ( V_127 ) ;
F_129 ( & V_5 -> V_30 ) ;
}
#endif
while ( ! F_235 ( & V_5 -> V_31 ) ) {
V_127 = F_274 ( & V_5 -> V_31 ,
struct V_9 , V_147 ) ;
F_9 ( V_127 ) ;
F_130 ( & V_127 -> V_147 ) ;
F_137 ( & V_5 -> V_30 ) ;
F_126 ( & V_127 -> V_169 ) ;
V_140 = V_127 -> V_140 ;
V_127 -> V_140 = V_141 ;
F_127 ( & V_127 -> V_169 ) ;
if ( V_140 != V_141 ) {
F_275 ( V_184 , V_127 ) ;
F_124 ( V_185 , V_127 ) ;
}
F_131 ( V_127 ) ;
F_129 ( & V_5 -> V_30 ) ;
}
F_137 ( & V_5 -> V_30 ) ;
if ( V_415 )
F_276 ( V_5 ) ;
else
F_277 ( V_5 ) ;
V_5 -> V_64 = V_13 ;
if ( V_415 ) {
F_3 ( V_5 ) ;
F_33 ( & V_38 , V_5 -> V_37 ) ;
F_272 ( & V_38 , V_7 ) ;
F_93 ( V_5 ) ;
}
return 0 ;
}
static void V_32 ( unsigned long V_291 )
{
struct V_4 * V_5 = (struct V_4 * ) V_291 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_148 V_398 ;
F_119 ( & V_5 -> V_30 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_62 & V_63 ) )
goto V_168;
if ( ! F_278 ( V_5 ) )
goto V_168;
if ( V_5 -> V_62 & V_419 )
goto V_168;
if ( V_5 -> V_420 ++ < V_5 -> V_33 . V_52 ) {
F_121 ( & V_5 -> V_30 ) ;
if ( ! F_169 ( V_7 , & V_398 , V_130 ) )
F_279 ( V_7 , & V_398 ,
& V_69 ) ;
else
goto V_421;
F_119 ( & V_5 -> V_30 ) ;
F_11 ( V_5 , ( V_5 -> V_420 ==
V_5 -> V_33 . V_52 ) ?
V_5 -> V_33 . V_422 :
V_5 -> V_33 . V_423 ) ;
} else {
F_92 ( L_24 , V_5 -> V_7 -> V_42 ) ;
}
V_168:
F_121 ( & V_5 -> V_30 ) ;
V_421:
F_93 ( V_5 ) ;
}
static void F_280 ( struct V_9 * V_10 )
{
unsigned long V_424 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_44 & V_213 )
V_424 = 0 ;
else
V_424 = F_281 () % ( V_5 -> V_33 . V_422 ? : 1 ) ;
V_10 -> V_425 = V_5 -> V_33 . V_211 ;
F_15 ( V_10 , V_424 ) ;
}
static void F_148 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_184 ( V_7 , & V_10 -> V_146 ) ;
F_282 ( V_10 -> V_146 . V_267 [ 3 ] ) ;
F_162 ( & V_5 -> V_30 ) ;
F_110 ( & V_10 -> V_30 ) ;
if ( V_10 -> V_140 == V_141 )
goto V_168;
if ( V_7 -> V_44 & ( V_45 | V_46 ) ||
V_5 -> V_33 . V_47 < 1 ||
! ( V_10 -> V_44 & V_130 ) ||
V_10 -> V_44 & V_426 ) {
V_10 -> V_44 &= ~ ( V_130 | V_213 | V_263 ) ;
F_118 ( & V_10 -> V_30 ) ;
F_167 ( & V_5 -> V_30 ) ;
F_283 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_62 & V_63 ) ) {
F_118 ( & V_10 -> V_30 ) ;
F_167 ( & V_5 -> V_30 ) ;
F_16 ( V_10 ) ;
F_178 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_44 & V_213 )
F_254 ( V_10 -> V_142 ) ;
F_280 ( V_10 ) ;
V_168:
F_118 ( & V_10 -> V_30 ) ;
F_167 ( & V_5 -> V_30 ) ;
}
static void V_170 ( unsigned long V_291 )
{
struct V_9 * V_10 = (struct V_9 * ) V_291 ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_148 V_427 ;
if ( ! V_10 -> V_425 && F_179 ( V_10 ) )
goto V_168;
F_119 ( & V_5 -> V_30 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_62 & V_63 ) ) {
F_121 ( & V_5 -> V_30 ) ;
goto V_168;
}
F_110 ( & V_10 -> V_30 ) ;
if ( V_10 -> V_140 == V_141 ) {
F_118 ( & V_10 -> V_30 ) ;
F_121 ( & V_5 -> V_30 ) ;
goto V_168;
}
if ( V_10 -> V_425 == 0 ) {
V_10 -> V_44 &= ~ ( V_130 | V_213 | V_263 ) ;
F_118 ( & V_10 -> V_30 ) ;
F_121 ( & V_5 -> V_30 ) ;
F_283 ( V_10 ) ;
goto V_168;
}
V_10 -> V_425 -- ;
F_15 ( V_10 , V_10 -> V_5 -> V_37 -> V_212 ) ;
F_118 ( & V_10 -> V_30 ) ;
F_121 ( & V_5 -> V_30 ) ;
F_185 ( & V_10 -> V_146 , & V_427 ) ;
F_284 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_146 , & V_427 , & V_61 ) ;
V_168:
F_131 ( V_10 ) ;
}
static void F_283 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_148 V_398 ;
bool V_428 , V_429 ;
F_9 ( V_10 ) ;
F_138 ( V_382 , V_10 ) ;
F_162 ( & V_10 -> V_5 -> V_30 ) ;
F_110 ( & V_10 -> V_30 ) ;
V_429 = F_107 ( & V_10 -> V_146 ) & V_326 &&
V_10 -> V_5 -> V_430 == 1 ;
V_428 = V_429 &&
F_278 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_33 . V_52 > 0 &&
( V_7 -> V_44 & V_46 ) == 0 ;
F_118 ( & V_10 -> V_30 ) ;
F_167 ( & V_10 -> V_5 -> V_30 ) ;
if ( V_429 )
F_285 ( V_10 -> V_5 ) ;
if ( V_428 ) {
if ( F_169 ( V_7 , & V_398 , V_130 ) )
return;
F_279 ( V_7 , & V_398 , & V_69 ) ;
F_129 ( & V_10 -> V_5 -> V_30 ) ;
F_110 ( & V_10 -> V_30 ) ;
V_10 -> V_5 -> V_420 = 1 ;
V_10 -> V_5 -> V_62 |= V_418 ;
F_11 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_33 . V_423 ) ;
F_118 ( & V_10 -> V_30 ) ;
F_137 ( & V_10 -> V_5 -> V_30 ) ;
}
}
static void F_263 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_162 ( & V_5 -> V_30 ) ;
F_79 (ifp, &idev->addr_list, if_list) {
F_110 ( & V_10 -> V_30 ) ;
if ( V_10 -> V_44 & V_130 &&
V_10 -> V_140 == V_265 )
F_280 ( V_10 ) ;
F_118 ( & V_10 -> V_30 ) ;
}
F_167 ( & V_5 -> V_30 ) ;
}
static struct V_9 * F_286 ( struct V_431 * V_81 , T_9 V_432 )
{
struct V_9 * V_127 = NULL ;
struct V_433 * V_140 = V_81 -> V_434 ;
struct V_92 * V_92 = F_287 ( V_81 ) ;
int V_135 = 0 ;
if ( V_432 == 0 ) {
V_140 -> V_435 = 0 ;
V_140 -> V_436 = 0 ;
}
for (; V_140 -> V_435 < V_416 ; ++ V_140 -> V_435 ) {
F_177 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_172 ( F_28 ( V_127 -> V_5 -> V_7 ) , V_92 ) )
continue;
if ( V_135 < V_140 -> V_436 ) {
V_135 ++ ;
continue;
}
V_140 -> V_436 ++ ;
return V_127 ;
}
V_140 -> V_436 = 0 ;
V_135 = 0 ;
}
return NULL ;
}
static struct V_9 * F_288 ( struct V_431 * V_81 ,
struct V_9 * V_127 )
{
struct V_433 * V_140 = V_81 -> V_434 ;
struct V_92 * V_92 = F_287 ( V_81 ) ;
F_289 (ifa, addr_lst) {
if ( ! F_172 ( F_28 ( V_127 -> V_5 -> V_7 ) , V_92 ) )
continue;
V_140 -> V_436 ++ ;
return V_127 ;
}
while ( ++ V_140 -> V_435 < V_416 ) {
V_140 -> V_436 = 0 ;
F_177 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_172 ( F_28 ( V_127 -> V_5 -> V_7 ) , V_92 ) )
continue;
V_140 -> V_436 ++ ;
return V_127 ;
}
}
return NULL ;
}
static void * F_290 ( struct V_431 * V_81 , T_9 * V_432 )
__acquires( T_10 )
{
F_109 () ;
return F_286 ( V_81 , * V_432 ) ;
}
static void * F_291 ( struct V_431 * V_81 , void * V_437 , T_9 * V_432 )
{
struct V_9 * V_127 ;
V_127 = F_288 ( V_81 , V_437 ) ;
++ * V_432 ;
return V_127 ;
}
static void F_292 ( struct V_431 * V_81 , void * V_437 )
__releases( T_10 )
{
F_122 () ;
}
static int F_293 ( struct V_431 * V_81 , void * V_437 )
{
struct V_9 * V_10 = (struct V_9 * ) V_437 ;
F_294 ( V_81 , L_25 ,
& V_10 -> V_146 ,
V_10 -> V_5 -> V_7 -> V_77 ,
V_10 -> V_171 ,
V_10 -> V_152 ,
V_10 -> V_44 ,
V_10 -> V_5 -> V_7 -> V_42 ) ;
return 0 ;
}
static int F_295 ( struct V_438 * V_438 , struct V_439 * V_439 )
{
return F_296 ( V_438 , V_439 , & V_440 ,
sizeof( struct V_433 ) ) ;
}
static int T_11 F_297 ( struct V_92 * V_92 )
{
if ( ! F_298 ( L_26 , V_441 , V_92 -> V_442 , & V_443 ) )
return - V_26 ;
return 0 ;
}
static void T_12 F_299 ( struct V_92 * V_92 )
{
F_300 ( L_26 , V_92 -> V_442 ) ;
}
int T_13 F_301 ( void )
{
return F_302 ( & V_444 ) ;
}
void F_303 ( void )
{
F_304 ( & V_444 ) ;
}
int F_305 ( struct V_92 * V_92 , const struct V_148 * V_146 )
{
int V_199 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_156 = F_103 ( V_146 ) ;
F_109 () ;
F_177 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_172 ( F_28 ( V_10 -> V_5 -> V_7 ) , V_92 ) )
continue;
if ( F_152 ( & V_10 -> V_146 , V_146 ) &&
( V_10 -> V_44 & V_235 ) ) {
V_199 = 1 ;
break;
}
}
F_122 () ;
return V_199 ;
}
static void F_236 ( unsigned long V_445 )
{
unsigned long V_201 , V_446 , V_447 , V_448 ;
struct V_9 * V_10 ;
int V_220 ;
F_109 () ;
F_110 ( & V_449 ) ;
V_201 = V_13 ;
V_446 = F_306 ( V_201 + V_450 ) ;
F_7 ( & V_451 ) ;
for ( V_220 = 0 ; V_220 < V_416 ; V_220 ++ ) {
V_417:
F_177 (ifp,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_196 ;
if ( V_10 -> V_44 & V_182 )
continue;
F_110 ( & V_10 -> V_30 ) ;
V_196 = ( V_201 - V_10 -> V_64 + V_452 ) / V_3 ;
if ( V_10 -> V_153 != V_381 &&
V_196 >= V_10 -> V_153 ) {
F_118 ( & V_10 -> V_30 ) ;
F_16 ( V_10 ) ;
F_125 ( V_10 ) ;
goto V_417;
} else if ( V_10 -> V_154 == V_381 ) {
F_118 ( & V_10 -> V_30 ) ;
continue;
} else if ( V_196 >= V_10 -> V_154 ) {
int V_453 = 0 ;
if ( ! ( V_10 -> V_44 & V_230 ) ) {
V_453 = 1 ;
V_10 -> V_44 |= V_230 ;
}
if ( F_136 ( V_10 -> V_64 + V_10 -> V_153 * V_3 , V_446 ) )
V_446 = V_10 -> V_64 + V_10 -> V_153 * V_3 ;
F_118 ( & V_10 -> V_30 ) ;
if ( V_453 ) {
F_16 ( V_10 ) ;
F_138 ( 0 , V_10 ) ;
F_131 ( V_10 ) ;
goto V_417;
}
#ifdef F_39
} else if ( ( V_10 -> V_44 & V_174 ) &&
! ( V_10 -> V_44 & V_130 ) ) {
unsigned long V_197 = V_10 -> V_5 -> V_33 . V_205 *
V_10 -> V_5 -> V_33 . V_211 *
V_10 -> V_5 -> V_37 -> V_212 / V_3 ;
if ( V_196 >= V_10 -> V_154 - V_197 ) {
struct V_9 * V_181 = V_10 -> V_181 ;
if ( F_136 ( V_10 -> V_64 + V_10 -> V_154 * V_3 , V_446 ) )
V_446 = V_10 -> V_64 + V_10 -> V_154 * V_3 ;
if ( ! V_10 -> V_204 && V_181 ) {
V_10 -> V_204 ++ ;
F_16 ( V_10 ) ;
F_16 ( V_181 ) ;
F_118 ( & V_10 -> V_30 ) ;
F_110 ( & V_181 -> V_30 ) ;
V_181 -> V_204 = 0 ;
F_118 ( & V_181 -> V_30 ) ;
F_144 ( V_181 , V_10 ) ;
F_131 ( V_181 ) ;
F_131 ( V_10 ) ;
goto V_417;
}
} else if ( F_136 ( V_10 -> V_64 + V_10 -> V_154 * V_3 - V_197 * V_3 , V_446 ) )
V_446 = V_10 -> V_64 + V_10 -> V_154 * V_3 - V_197 * V_3 ;
F_118 ( & V_10 -> V_30 ) ;
#endif
} else {
if ( F_136 ( V_10 -> V_64 + V_10 -> V_154 * V_3 , V_446 ) )
V_446 = V_10 -> V_64 + V_10 -> V_154 * V_3 ;
F_118 ( & V_10 -> V_30 ) ;
}
}
}
V_447 = F_306 ( V_446 ) ;
V_448 = V_446 ;
if ( F_136 ( V_447 , V_446 + V_454 ) )
V_448 = V_447 ;
if ( F_136 ( V_448 , V_13 + V_455 ) )
V_448 = V_13 + V_455 ;
F_32 ( V_251 L_27 ,
V_201 , V_446 , V_447 , V_448 ) ;
V_451 . V_180 = V_448 ;
F_307 ( & V_451 ) ;
F_118 ( & V_449 ) ;
F_122 () ;
}
static struct V_148 * F_308 ( struct V_101 * V_146 , struct V_101 * V_456 ,
struct V_148 * * V_373 )
{
struct V_148 * V_292 = NULL ;
* V_373 = NULL ;
if ( V_146 )
V_292 = F_309 ( V_146 ) ;
if ( V_456 ) {
if ( V_292 && F_310 ( V_456 , V_292 , sizeof( * V_292 ) ) )
* V_373 = V_292 ;
V_292 = F_309 ( V_456 ) ;
}
return V_292 ;
}
static int
F_311 ( struct V_75 * V_76 , struct V_83 * V_84 )
{
struct V_92 * V_92 = F_64 ( V_76 -> V_100 ) ;
struct V_457 * V_458 ;
struct V_101 * V_102 [ V_459 + 1 ] ;
struct V_148 * V_292 , * V_373 ;
int V_93 ;
V_93 = F_65 ( V_84 , sizeof( * V_458 ) , V_102 , V_459 , V_460 ) ;
if ( V_93 < 0 )
return V_93 ;
V_458 = F_53 ( V_84 ) ;
V_292 = F_308 ( V_102 [ V_461 ] , V_102 [ V_462 ] , & V_373 ) ;
if ( V_292 == NULL )
return - V_106 ;
return F_246 ( V_92 , V_458 -> V_463 , V_292 , V_458 -> V_464 ) ;
}
static int F_312 ( struct V_9 * V_10 , T_3 V_374 ,
T_1 V_154 , T_1 V_153 )
{
T_1 V_44 ;
T_5 V_180 ;
unsigned long V_375 ;
if ( ! V_153 || ( V_154 > V_153 ) )
return - V_106 ;
V_375 = F_135 ( V_153 , V_3 ) ;
if ( F_228 ( V_375 ) ) {
V_180 = F_230 ( V_375 * V_3 ) ;
V_153 = V_375 ;
V_44 = V_190 ;
} else {
V_180 = 0 ;
V_44 = 0 ;
V_374 |= V_182 ;
}
V_375 = F_135 ( V_154 , V_3 ) ;
if ( F_228 ( V_375 ) ) {
if ( V_375 == 0 )
V_374 |= V_230 ;
V_154 = V_375 ;
}
F_126 ( & V_10 -> V_30 ) ;
V_10 -> V_44 = ( V_10 -> V_44 & ~ ( V_230 | V_182 | V_426 | V_235 ) ) | V_374 ;
V_10 -> V_64 = V_13 ;
V_10 -> V_153 = V_153 ;
V_10 -> V_154 = V_154 ;
F_127 ( & V_10 -> V_30 ) ;
if ( ! ( V_10 -> V_44 & V_130 ) )
F_138 ( 0 , V_10 ) ;
F_214 ( & V_10 -> V_146 , V_10 -> V_171 , V_10 -> V_5 -> V_7 ,
V_180 , V_44 ) ;
F_236 ( 0 ) ;
return 0 ;
}
static int
F_313 ( struct V_75 * V_76 , struct V_83 * V_84 )
{
struct V_92 * V_92 = F_64 ( V_76 -> V_100 ) ;
struct V_457 * V_458 ;
struct V_101 * V_102 [ V_459 + 1 ] ;
struct V_148 * V_292 , * V_373 ;
struct V_9 * V_127 ;
struct V_6 * V_7 ;
T_1 V_153 = V_381 , V_465 = V_381 ;
T_3 V_374 ;
int V_93 ;
V_93 = F_65 ( V_84 , sizeof( * V_458 ) , V_102 , V_459 , V_460 ) ;
if ( V_93 < 0 )
return V_93 ;
V_458 = F_53 ( V_84 ) ;
V_292 = F_308 ( V_102 [ V_461 ] , V_102 [ V_462 ] , & V_373 ) ;
if ( V_292 == NULL )
return - V_106 ;
if ( V_102 [ V_466 ] ) {
struct V_467 * V_468 ;
V_468 = F_309 ( V_102 [ V_466 ] ) ;
V_153 = V_468 -> V_469 ;
V_465 = V_468 -> V_470 ;
} else {
V_465 = V_381 ;
V_153 = V_381 ;
}
V_7 = F_67 ( V_92 , V_458 -> V_463 ) ;
if ( V_7 == NULL )
return - V_162 ;
V_374 = V_458 -> V_374 & ( V_426 | V_235 ) ;
V_127 = F_176 ( V_92 , V_292 , V_7 , 1 ) ;
if ( V_127 == NULL ) {
return F_245 ( V_92 , V_458 -> V_463 , V_292 , V_373 ,
V_458 -> V_464 , V_374 ,
V_465 , V_153 ) ;
}
if ( V_84 -> V_471 & V_472 ||
! ( V_84 -> V_471 & V_473 ) )
V_93 = - V_167 ;
else
V_93 = F_312 ( V_127 , V_374 , V_465 , V_153 ) ;
F_131 ( V_127 ) ;
return V_93 ;
}
static void F_314 ( struct V_83 * V_84 , T_3 V_474 , T_3 V_44 ,
T_3 V_152 , int V_77 )
{
struct V_457 * V_458 ;
V_458 = F_53 ( V_84 ) ;
V_458 -> V_475 = V_88 ;
V_458 -> V_464 = V_474 ;
V_458 -> V_374 = V_44 ;
V_458 -> V_390 = V_152 ;
V_458 -> V_463 = V_77 ;
}
static int F_315 ( struct V_75 * V_76 , unsigned long V_1 ,
unsigned long V_64 , T_1 V_476 , T_1 V_327 )
{
struct V_467 V_468 ;
V_468 . V_1 = F_1 ( V_1 ) ;
V_468 . V_64 = F_1 ( V_64 ) ;
V_468 . V_470 = V_476 ;
V_468 . V_469 = V_327 ;
return F_316 ( V_76 , V_466 , sizeof( V_468 ) , & V_468 ) ;
}
static inline int F_317 ( int V_390 )
{
if ( V_390 & V_260 )
return V_392 ;
else if ( V_390 & V_257 )
return V_391 ;
else if ( V_390 & V_477 )
return V_478 ;
else
return V_479 ;
}
static inline int F_318 ( void )
{
return F_48 ( sizeof( struct V_457 ) )
+ F_49 ( 16 )
+ F_49 ( 16 )
+ F_49 ( sizeof( struct V_467 ) ) ;
}
static int F_319 ( struct V_75 * V_76 , struct V_9 * V_127 ,
T_1 V_80 , T_1 V_81 , int V_82 , unsigned int V_44 )
{
struct V_83 * V_84 ;
T_1 V_476 , V_327 ;
V_84 = F_52 ( V_76 , V_80 , V_81 , V_82 , sizeof( struct V_457 ) , V_44 ) ;
if ( V_84 == NULL )
return - V_86 ;
F_314 ( V_84 , V_127 -> V_171 , V_127 -> V_44 , F_317 ( V_127 -> V_152 ) ,
V_127 -> V_5 -> V_7 -> V_77 ) ;
if ( ! ( V_127 -> V_44 & V_182 ) ) {
V_476 = V_127 -> V_154 ;
V_327 = V_127 -> V_153 ;
if ( V_476 != V_381 ) {
long V_480 = ( V_13 - V_127 -> V_64 ) / V_3 ;
if ( V_476 > V_480 )
V_476 -= V_480 ;
else
V_476 = 0 ;
if ( V_327 != V_381 ) {
if ( V_327 > V_480 )
V_327 -= V_480 ;
else
V_327 = 0 ;
}
}
} else {
V_476 = V_381 ;
V_327 = V_381 ;
}
if ( ! F_188 ( & V_127 -> V_150 ) ) {
if ( F_316 ( V_76 , V_462 , 16 , & V_127 -> V_146 ) < 0 ||
F_316 ( V_76 , V_461 , 16 , & V_127 -> V_150 ) < 0 )
goto error;
} else
if ( F_316 ( V_76 , V_461 , 16 , & V_127 -> V_146 ) < 0 )
goto error;
if ( F_315 ( V_76 , V_127 -> V_1 , V_127 -> V_64 , V_476 , V_327 ) < 0 )
goto error;
return F_55 ( V_76 , V_84 ) ;
error:
F_56 ( V_76 , V_84 ) ;
return - V_86 ;
}
static int F_320 ( struct V_75 * V_76 , struct V_481 * V_482 ,
T_1 V_80 , T_1 V_81 , int V_82 , T_14 V_44 )
{
struct V_83 * V_84 ;
T_3 V_152 = V_479 ;
int V_77 = V_482 -> V_5 -> V_7 -> V_77 ;
if ( F_147 ( & V_482 -> V_483 ) & V_477 )
V_152 = V_478 ;
V_84 = F_52 ( V_76 , V_80 , V_81 , V_82 , sizeof( struct V_457 ) , V_44 ) ;
if ( V_84 == NULL )
return - V_86 ;
F_314 ( V_84 , 128 , V_182 , V_152 , V_77 ) ;
if ( F_316 ( V_76 , V_484 , 16 , & V_482 -> V_483 ) < 0 ||
F_315 ( V_76 , V_482 -> V_485 , V_482 -> V_486 ,
V_381 , V_381 ) < 0 ) {
F_56 ( V_76 , V_84 ) ;
return - V_86 ;
}
return F_55 ( V_76 , V_84 ) ;
}
static int F_321 ( struct V_75 * V_76 , struct V_487 * V_488 ,
T_1 V_80 , T_1 V_81 , int V_82 , unsigned int V_44 )
{
struct V_83 * V_84 ;
T_3 V_152 = V_479 ;
int V_77 = V_488 -> V_489 -> V_7 -> V_77 ;
if ( F_147 ( & V_488 -> V_490 ) & V_477 )
V_152 = V_478 ;
V_84 = F_52 ( V_76 , V_80 , V_81 , V_82 , sizeof( struct V_457 ) , V_44 ) ;
if ( V_84 == NULL )
return - V_86 ;
F_314 ( V_84 , 128 , V_182 , V_152 , V_77 ) ;
if ( F_316 ( V_76 , V_491 , 16 , & V_488 -> V_490 ) < 0 ||
F_315 ( V_76 , V_488 -> V_492 , V_488 -> V_493 ,
V_381 , V_381 ) < 0 ) {
F_56 ( V_76 , V_84 ) ;
return - V_86 ;
}
return F_55 ( V_76 , V_84 ) ;
}
static int F_322 ( struct V_4 * V_5 , struct V_75 * V_76 ,
struct V_111 * V_112 , enum V_494 type ,
int V_495 , int * V_496 )
{
struct V_481 * V_482 ;
struct V_487 * V_488 ;
int V_93 = 1 ;
int V_497 = * V_496 ;
F_162 ( & V_5 -> V_30 ) ;
switch ( type ) {
case V_498 : {
struct V_9 * V_127 ;
F_79 (ifa, &idev->addr_list, if_list) {
if ( ++ V_497 < V_495 )
continue;
V_93 = F_319 ( V_76 , V_127 ,
F_68 ( V_112 -> V_76 ) . V_80 ,
V_112 -> V_84 -> V_110 ,
V_382 ,
V_124 ) ;
if ( V_93 <= 0 )
break;
F_75 ( V_112 , F_76 ( V_76 ) ) ;
}
break;
}
case V_499 :
for ( V_482 = V_5 -> V_500 ; V_482 ;
V_482 = V_482 -> V_446 , V_497 ++ ) {
if ( V_497 < V_495 )
continue;
V_93 = F_320 ( V_76 , V_482 ,
F_68 ( V_112 -> V_76 ) . V_80 ,
V_112 -> V_84 -> V_110 ,
V_501 ,
V_124 ) ;
if ( V_93 <= 0 )
break;
}
break;
case V_502 :
for ( V_488 = V_5 -> V_503 ; V_488 ;
V_488 = V_488 -> V_504 , V_497 ++ ) {
if ( V_497 < V_495 )
continue;
V_93 = F_321 ( V_76 , V_488 ,
F_68 ( V_112 -> V_76 ) . V_80 ,
V_112 -> V_84 -> V_110 ,
V_505 ,
V_124 ) ;
if ( V_93 <= 0 )
break;
}
break;
default:
break;
}
F_167 ( & V_5 -> V_30 ) ;
* V_496 = V_497 ;
return V_93 ;
}
static int F_323 ( struct V_75 * V_76 , struct V_111 * V_112 ,
enum V_494 type )
{
struct V_92 * V_92 = F_64 ( V_76 -> V_100 ) ;
int V_113 , V_114 ;
int V_115 , V_497 ;
int V_116 , V_495 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_117 * V_118 ;
V_114 = V_112 -> args [ 0 ] ;
V_116 = V_115 = V_112 -> args [ 1 ] ;
V_495 = V_497 = V_112 -> args [ 2 ] ;
F_71 () ;
V_112 -> V_81 = F_72 ( & V_92 -> V_16 . V_121 ) ^ V_92 -> V_122 ;
for ( V_113 = V_114 ; V_113 < V_119 ; V_113 ++ , V_116 = 0 ) {
V_115 = 0 ;
V_118 = & V_92 -> V_120 [ V_113 ] ;
F_73 (dev, head, index_hlist) {
if ( V_115 < V_116 )
goto V_123;
if ( V_113 > V_114 || V_115 > V_116 )
V_495 = 0 ;
V_497 = 0 ;
V_5 = F_45 ( V_7 ) ;
if ( ! V_5 )
goto V_123;
if ( F_322 ( V_5 , V_76 , V_112 , type ,
V_495 , & V_497 ) <= 0 )
goto V_125;
V_123:
V_115 ++ ;
}
}
V_125:
F_74 () ;
V_112 -> args [ 0 ] = V_113 ;
V_112 -> args [ 1 ] = V_115 ;
V_112 -> args [ 2 ] = V_497 ;
return V_76 -> V_126 ;
}
static int F_324 ( struct V_75 * V_76 , struct V_111 * V_112 )
{
enum V_494 type = V_498 ;
return F_323 ( V_76 , V_112 , type ) ;
}
static int F_325 ( struct V_75 * V_76 , struct V_111 * V_112 )
{
enum V_494 type = V_499 ;
return F_323 ( V_76 , V_112 , type ) ;
}
static int F_326 ( struct V_75 * V_76 , struct V_111 * V_112 )
{
enum V_494 type = V_502 ;
return F_323 ( V_76 , V_112 , type ) ;
}
static int F_327 ( struct V_75 * V_99 , struct V_83 * V_84 )
{
struct V_92 * V_92 = F_64 ( V_99 -> V_100 ) ;
struct V_457 * V_458 ;
struct V_101 * V_102 [ V_459 + 1 ] ;
struct V_148 * V_146 = NULL , * V_506 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_127 ;
struct V_75 * V_76 ;
int V_93 ;
V_93 = F_65 ( V_84 , sizeof( * V_458 ) , V_102 , V_459 , V_460 ) ;
if ( V_93 < 0 )
goto V_96;
V_146 = F_308 ( V_102 [ V_461 ] , V_102 [ V_462 ] , & V_506 ) ;
if ( V_146 == NULL ) {
V_93 = - V_106 ;
goto V_96;
}
V_458 = F_53 ( V_84 ) ;
if ( V_458 -> V_463 )
V_7 = F_67 ( V_92 , V_458 -> V_463 ) ;
V_127 = F_176 ( V_92 , V_146 , V_7 , 1 ) ;
if ( ! V_127 ) {
V_93 = - V_161 ;
goto V_96;
}
V_76 = F_58 ( F_318 () , V_21 ) ;
if ( ! V_76 ) {
V_93 = - V_94 ;
goto V_507;
}
V_93 = F_319 ( V_76 , V_127 , F_68 ( V_99 ) . V_80 ,
V_84 -> V_110 , V_382 , 0 ) ;
if ( V_93 < 0 ) {
F_59 ( V_93 == - V_86 ) ;
F_60 ( V_76 ) ;
goto V_507;
}
V_93 = F_69 ( V_76 , V_92 , F_68 ( V_99 ) . V_80 ) ;
V_507:
F_131 ( V_127 ) ;
V_96:
return V_93 ;
}
static void F_328 ( int V_82 , struct V_9 * V_127 )
{
struct V_75 * V_76 ;
struct V_92 * V_92 = F_28 ( V_127 -> V_5 -> V_7 ) ;
int V_93 = - V_94 ;
V_76 = F_58 ( F_318 () , V_95 ) ;
if ( V_76 == NULL )
goto V_96;
V_93 = F_319 ( V_76 , V_127 , 0 , 0 , V_82 , 0 ) ;
if ( V_93 < 0 ) {
F_59 ( V_93 == - V_86 ) ;
F_60 ( V_76 ) ;
goto V_96;
}
F_61 ( V_76 , V_92 , 0 , V_508 , NULL , V_95 ) ;
return;
V_96:
if ( V_93 < 0 )
F_62 ( V_92 , V_508 , V_93 ) ;
}
static inline void F_329 ( struct V_78 * V_33 ,
T_2 * V_509 , int V_510 )
{
F_330 ( V_510 < ( V_511 * 4 ) ) ;
memset ( V_509 , 0 , V_510 ) ;
V_509 [ V_512 ] = V_33 -> V_39 ;
V_509 [ V_513 ] = V_33 -> V_514 ;
V_509 [ V_515 ] = V_33 -> V_35 ;
V_509 [ V_516 ] = V_33 -> V_517 ;
V_509 [ V_518 ] = V_33 -> V_519 ;
V_509 [ V_520 ] = V_33 -> V_333 ;
V_509 [ V_521 ] = V_33 -> V_211 ;
V_509 [ V_522 ] = V_33 -> V_52 ;
V_509 [ V_523 ] =
F_331 ( V_33 -> V_423 ) ;
V_509 [ V_524 ] =
F_331 ( V_33 -> V_422 ) ;
V_509 [ V_525 ] = V_33 -> V_526 ;
V_509 [ V_527 ] =
F_331 ( V_33 -> V_528 ) ;
V_509 [ V_529 ] =
F_331 ( V_33 -> V_530 ) ;
#ifdef F_39
V_509 [ V_531 ] = V_33 -> V_59 ;
V_509 [ V_532 ] = V_33 -> V_208 ;
V_509 [ V_533 ] = V_33 -> V_209 ;
V_509 [ V_534 ] = V_33 -> V_205 ;
V_509 [ V_535 ] = V_33 -> V_210 ;
#endif
V_509 [ V_536 ] = V_33 -> V_337 ;
V_509 [ V_537 ] = V_33 -> V_538 ;
V_509 [ V_539 ] = V_33 -> V_540 ;
#ifdef F_332
V_509 [ V_541 ] = V_33 -> V_542 ;
V_509 [ V_543 ] =
F_331 ( V_33 -> V_544 ) ;
#ifdef F_333
V_509 [ V_545 ] = V_33 -> V_546 ;
#endif
#endif
V_509 [ V_547 ] = V_33 -> V_548 ;
V_509 [ V_549 ] = V_33 -> V_550 ;
#ifdef F_231
V_509 [ V_551 ] = V_33 -> V_338 ;
#endif
#ifdef F_50
V_509 [ V_552 ] = V_33 -> V_91 ;
#endif
V_509 [ V_553 ] = V_33 -> V_164 ;
V_509 [ V_554 ] = V_33 -> V_47 ;
V_509 [ V_555 ] = V_33 -> V_556 ;
V_509 [ V_557 ] = V_33 -> V_558 ;
V_509 [ V_559 ] = V_33 -> V_560 ;
}
static inline T_15 F_334 ( void )
{
return F_49 ( 4 )
+ F_49 ( sizeof( struct V_561 ) )
+ F_49 ( V_511 * 4 )
+ F_49 ( V_562 * 8 )
+ F_49 ( V_563 * 8 )
+ F_49 ( sizeof( struct V_148 ) ) ;
}
static inline T_15 F_335 ( void )
{
return F_48 ( sizeof( struct V_564 ) )
+ F_49 ( V_565 )
+ F_49 ( V_566 )
+ F_49 ( 4 )
+ F_49 ( 4 )
+ F_49 ( F_334 () ) ;
}
static inline void F_336 ( T_16 * V_15 , T_17 * V_567 ,
int V_568 , int V_510 )
{
int V_220 ;
int V_569 = V_510 - sizeof( T_16 ) * V_568 ;
F_330 ( V_569 < 0 ) ;
F_337 ( V_568 , & V_15 [ 0 ] ) ;
for ( V_220 = 1 ; V_220 < V_568 ; V_220 ++ )
F_337 ( F_338 ( & V_567 [ V_220 ] ) , & V_15 [ V_220 ] ) ;
memset ( & V_15 [ V_568 ] , 0 , V_569 ) ;
}
static inline void F_339 ( T_16 * V_15 , void V_14 * * V_567 ,
int V_568 , int V_510 , T_15 V_570 )
{
int V_220 ;
int V_569 = V_510 - sizeof( T_16 ) * V_568 ;
F_330 ( V_569 < 0 ) ;
F_337 ( V_568 , & V_15 [ 0 ] ) ;
for ( V_220 = 1 ; V_220 < V_568 ; V_220 ++ )
F_337 ( F_340 ( V_567 , V_220 , V_570 ) , & V_15 [ V_220 ] ) ;
memset ( & V_15 [ V_568 ] , 0 , V_569 ) ;
}
static void F_341 ( T_16 * V_15 , struct V_4 * V_5 , int V_571 ,
int V_510 )
{
switch ( V_571 ) {
case V_572 :
F_339 ( V_15 , ( void V_14 * * ) V_5 -> V_15 . V_16 ,
V_562 , V_510 , F_342 ( struct V_17 , V_573 ) ) ;
break;
case V_574 :
F_336 ( V_15 , V_5 -> V_15 . V_19 -> V_575 , V_563 , V_510 ) ;
break;
}
}
static int F_343 ( struct V_75 * V_76 , struct V_4 * V_5 )
{
struct V_101 * V_576 ;
struct V_561 V_468 ;
if ( F_344 ( V_76 , V_577 , V_5 -> V_62 ) )
goto V_90;
V_468 . V_578 = V_579 ;
V_468 . V_64 = F_1 ( V_5 -> V_64 ) ;
V_468 . V_580 = F_331 ( V_5 -> V_37 -> V_580 ) ;
V_468 . V_212 = F_331 ( V_5 -> V_37 -> V_212 ) ;
if ( F_316 ( V_76 , V_581 , sizeof( V_468 ) , & V_468 ) )
goto V_90;
V_576 = F_345 ( V_76 , V_582 , V_511 * sizeof( V_583 ) ) ;
if ( V_576 == NULL )
goto V_90;
F_329 ( & V_5 -> V_33 , F_309 ( V_576 ) , F_346 ( V_576 ) ) ;
V_576 = F_345 ( V_76 , V_572 , V_562 * sizeof( T_16 ) ) ;
if ( V_576 == NULL )
goto V_90;
F_341 ( F_309 ( V_576 ) , V_5 , V_572 , F_346 ( V_576 ) ) ;
V_576 = F_345 ( V_76 , V_574 , V_563 * sizeof( T_16 ) ) ;
if ( V_576 == NULL )
goto V_90;
F_341 ( F_309 ( V_576 ) , V_5 , V_574 , F_346 ( V_576 ) ) ;
V_576 = F_345 ( V_76 , V_584 , sizeof( struct V_148 ) ) ;
if ( V_576 == NULL )
goto V_90;
F_162 ( & V_5 -> V_30 ) ;
memcpy ( F_309 ( V_576 ) , V_5 -> V_60 . V_202 , F_346 ( V_576 ) ) ;
F_167 ( & V_5 -> V_30 ) ;
return 0 ;
V_90:
return - V_86 ;
}
static T_15 F_347 ( const struct V_6 * V_7 )
{
if ( ! F_45 ( V_7 ) )
return 0 ;
return F_334 () ;
}
static int F_348 ( struct V_75 * V_76 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_45 ( V_7 ) ;
if ( ! V_5 )
return - V_585 ;
if ( F_343 ( V_76 , V_5 ) < 0 )
return - V_86 ;
return 0 ;
}
static int F_349 ( struct V_4 * V_5 , struct V_148 * V_60 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_586 = false ;
struct V_148 V_587 ;
if ( V_60 == NULL )
return - V_106 ;
if ( F_188 ( V_60 ) )
return - V_106 ;
if ( V_7 -> V_44 & ( V_46 | V_45 ) )
return - V_106 ;
if ( ! F_278 ( V_5 ) )
return - V_106 ;
if ( V_5 -> V_33 . V_52 <= 0 )
return - V_106 ;
F_129 ( & V_5 -> V_30 ) ;
F_350 ( sizeof( V_60 -> V_202 ) != 16 ) ;
memcpy ( V_5 -> V_60 . V_202 + 8 , V_60 -> V_202 + 8 , 8 ) ;
F_137 ( & V_5 -> V_30 ) ;
if ( ! V_5 -> V_43 && ( V_5 -> V_62 & V_63 ) &&
! F_169 ( V_7 , & V_587 , V_130 |
V_213 ) ) {
F_279 ( V_7 , & V_587 , & V_69 ) ;
V_586 = true ;
}
F_129 ( & V_5 -> V_30 ) ;
if ( V_586 ) {
V_5 -> V_62 |= V_418 ;
V_5 -> V_420 = 1 ;
F_11 ( V_5 , V_5 -> V_33 . V_423 ) ;
}
F_79 (ifp, &idev->addr_list, if_list) {
F_110 ( & V_10 -> V_30 ) ;
if ( V_10 -> V_172 ) {
V_10 -> V_153 = 0 ;
V_10 -> V_154 = 0 ;
}
F_118 ( & V_10 -> V_30 ) ;
}
F_137 ( & V_5 -> V_30 ) ;
F_236 ( 0 ) ;
return 0 ;
}
static int F_351 ( struct V_6 * V_7 , const struct V_101 * V_576 )
{
int V_93 = - V_106 ;
struct V_4 * V_5 = F_45 ( V_7 ) ;
struct V_101 * V_102 [ V_588 + 1 ] ;
if ( ! V_5 )
return - V_589 ;
if ( F_352 ( V_102 , V_588 , V_576 , NULL ) < 0 )
F_353 () ;
if ( V_102 [ V_584 ] )
V_93 = F_349 ( V_5 , F_309 ( V_102 [ V_584 ] ) ) ;
return V_93 ;
}
static int F_354 ( struct V_75 * V_76 , struct V_4 * V_5 ,
T_1 V_80 , T_1 V_81 , int V_82 , unsigned int V_44 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_564 * V_590 ;
struct V_83 * V_84 ;
void * V_591 ;
V_84 = F_52 ( V_76 , V_80 , V_81 , V_82 , sizeof( * V_590 ) , V_44 ) ;
if ( V_84 == NULL )
return - V_86 ;
V_590 = F_53 ( V_84 ) ;
V_590 -> V_592 = V_88 ;
V_590 -> V_593 = 0 ;
V_590 -> V_594 = V_7 -> type ;
V_590 -> V_595 = V_7 -> V_77 ;
V_590 -> V_596 = F_355 ( V_7 ) ;
V_590 -> V_597 = 0 ;
if ( F_356 ( V_76 , V_598 , V_7 -> V_42 ) ||
( V_7 -> V_270 &&
F_316 ( V_76 , V_599 , V_7 -> V_270 , V_7 -> V_272 ) ) ||
F_344 ( V_76 , V_600 , V_7 -> V_28 ) ||
( V_7 -> V_77 != V_7 -> V_601 &&
F_344 ( V_76 , V_602 , V_7 -> V_601 ) ) )
goto V_90;
V_591 = F_357 ( V_76 , V_603 ) ;
if ( V_591 == NULL )
goto V_90;
if ( F_343 ( V_76 , V_5 ) < 0 )
goto V_90;
F_358 ( V_76 , V_591 ) ;
return F_55 ( V_76 , V_84 ) ;
V_90:
F_56 ( V_76 , V_84 ) ;
return - V_86 ;
}
static int F_359 ( struct V_75 * V_76 , struct V_111 * V_112 )
{
struct V_92 * V_92 = F_64 ( V_76 -> V_100 ) ;
int V_113 , V_114 ;
int V_115 = 0 , V_116 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_117 * V_118 ;
V_114 = V_112 -> args [ 0 ] ;
V_116 = V_112 -> args [ 1 ] ;
F_71 () ;
for ( V_113 = V_114 ; V_113 < V_119 ; V_113 ++ , V_116 = 0 ) {
V_115 = 0 ;
V_118 = & V_92 -> V_120 [ V_113 ] ;
F_73 (dev, head, index_hlist) {
if ( V_115 < V_116 )
goto V_123;
V_5 = F_45 ( V_7 ) ;
if ( ! V_5 )
goto V_123;
if ( F_354 ( V_76 , V_5 ,
F_68 ( V_112 -> V_76 ) . V_80 ,
V_112 -> V_84 -> V_110 ,
V_408 , V_124 ) <= 0 )
goto V_168;
V_123:
V_115 ++ ;
}
}
V_168:
F_74 () ;
V_112 -> args [ 1 ] = V_115 ;
V_112 -> args [ 0 ] = V_113 ;
return V_76 -> V_126 ;
}
void F_265 ( int V_82 , struct V_4 * V_5 )
{
struct V_75 * V_76 ;
struct V_92 * V_92 = F_28 ( V_5 -> V_7 ) ;
int V_93 = - V_94 ;
V_76 = F_58 ( F_335 () , V_95 ) ;
if ( V_76 == NULL )
goto V_96;
V_93 = F_354 ( V_76 , V_5 , 0 , 0 , V_82 , 0 ) ;
if ( V_93 < 0 ) {
F_59 ( V_93 == - V_86 ) ;
F_60 ( V_76 ) ;
goto V_96;
}
F_61 ( V_76 , V_92 , 0 , V_604 , NULL , V_95 ) ;
return;
V_96:
if ( V_93 < 0 )
F_62 ( V_92 , V_604 , V_93 ) ;
}
static inline T_15 F_360 ( void )
{
return F_48 ( sizeof( struct V_605 ) )
+ F_49 ( sizeof( struct V_148 ) )
+ F_49 ( sizeof( struct V_606 ) ) ;
}
static int F_361 ( struct V_75 * V_76 , struct V_4 * V_5 ,
struct V_324 * V_325 , T_1 V_80 , T_1 V_81 ,
int V_82 , unsigned int V_44 )
{
struct V_605 * V_607 ;
struct V_83 * V_84 ;
struct V_606 V_468 ;
V_84 = F_52 ( V_76 , V_80 , V_81 , V_82 , sizeof( * V_607 ) , V_44 ) ;
if ( V_84 == NULL )
return - V_86 ;
V_607 = F_53 ( V_84 ) ;
V_607 -> V_608 = V_88 ;
V_607 -> V_609 = 0 ;
V_607 -> V_610 = 0 ;
V_607 -> V_611 = V_5 -> V_7 -> V_77 ;
V_607 -> V_171 = V_325 -> V_171 ;
V_607 -> V_612 = V_325 -> type ;
V_607 -> V_613 = 0 ;
V_607 -> V_614 = 0 ;
if ( V_325 -> V_179 )
V_607 -> V_614 |= V_615 ;
if ( V_325 -> V_333 )
V_607 -> V_614 |= V_616 ;
if ( F_316 ( V_76 , V_617 , sizeof( V_325 -> V_186 ) , & V_325 -> V_186 ) )
goto V_90;
V_468 . V_618 = F_224 ( V_325 -> V_328 ) ;
V_468 . V_619 = F_224 ( V_325 -> V_327 ) ;
if ( F_316 ( V_76 , V_620 , sizeof( V_468 ) , & V_468 ) )
goto V_90;
return F_55 ( V_76 , V_84 ) ;
V_90:
F_56 ( V_76 , V_84 ) ;
return - V_86 ;
}
static void F_237 ( int V_82 , struct V_4 * V_5 ,
struct V_324 * V_325 )
{
struct V_75 * V_76 ;
struct V_92 * V_92 = F_28 ( V_5 -> V_7 ) ;
int V_93 = - V_94 ;
V_76 = F_58 ( F_360 () , V_95 ) ;
if ( V_76 == NULL )
goto V_96;
V_93 = F_361 ( V_76 , V_5 , V_325 , 0 , 0 , V_82 , 0 ) ;
if ( V_93 < 0 ) {
F_59 ( V_93 == - V_86 ) ;
F_60 ( V_76 ) ;
goto V_96;
}
F_61 ( V_76 , V_92 , 0 , V_621 , NULL , V_95 ) ;
return;
V_96:
if ( V_93 < 0 )
F_62 ( V_92 , V_621 , V_93 ) ;
}
static void F_362 ( struct V_9 * V_10 , int V_622 )
{
F_129 ( & V_10 -> V_5 -> V_30 ) ;
F_110 ( & V_10 -> V_30 ) ;
if ( ( ( V_10 -> V_44 & ( V_182 | V_130 | V_213 |
V_263 ) ) == V_182 ) &&
( F_107 ( & V_10 -> V_146 ) & V_326 ) )
V_10 -> V_5 -> V_430 += V_622 ;
F_59 ( V_10 -> V_5 -> V_430 < 0 ) ;
F_118 ( & V_10 -> V_30 ) ;
F_137 ( & V_10 -> V_5 -> V_30 ) ;
}
static void F_275 ( int V_82 , struct V_9 * V_10 )
{
struct V_92 * V_92 = F_28 ( V_10 -> V_5 -> V_7 ) ;
F_328 ( V_82 ? : V_382 , V_10 ) ;
switch ( V_82 ) {
case V_382 :
F_362 ( V_10 , 1 ) ;
if ( ! ( V_10 -> V_142 -> V_623 ) )
F_254 ( V_10 -> V_142 ) ;
if ( V_10 -> V_5 -> V_33 . V_39 )
F_80 ( V_10 ) ;
if ( ! F_188 ( & V_10 -> V_150 ) )
F_214 ( & V_10 -> V_150 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_184 :
F_362 ( V_10 , - 1 ) ;
if ( V_10 -> V_5 -> V_33 . V_39 )
F_81 ( V_10 ) ;
F_186 ( V_10 -> V_5 , & V_10 -> V_146 ) ;
if ( ! F_188 ( & V_10 -> V_150 ) ) {
struct V_155 * V_142 ;
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
V_142 = F_363 ( F_28 ( V_7 ) , & V_10 -> V_150 , NULL ,
V_7 -> V_77 , 1 ) ;
if ( V_142 ) {
F_218 ( & V_142 -> V_219 ) ;
if ( F_141 ( V_142 ) )
F_364 ( & V_142 -> V_219 ) ;
}
}
F_218 ( & V_10 -> V_142 -> V_219 ) ;
if ( F_141 ( V_10 -> V_142 ) )
F_364 ( & V_10 -> V_142 -> V_219 ) ;
break;
}
F_365 ( & V_92 -> V_16 . V_121 ) ;
F_366 ( V_92 ) ;
}
static void F_138 ( int V_82 , struct V_9 * V_10 )
{
F_109 () ;
if ( F_123 ( V_10 -> V_5 -> V_43 == 0 ) )
F_275 ( V_82 , V_10 ) ;
F_122 () ;
}
static
int F_367 ( struct V_133 * V_624 , int V_625 ,
void T_6 * V_626 , T_15 * V_627 , T_9 * V_628 )
{
int * V_629 = V_624 -> V_291 ;
int V_630 = * V_629 ;
T_9 V_432 = * V_628 ;
struct V_133 V_631 ;
int V_199 ;
V_631 = * V_624 ;
V_631 . V_291 = & V_630 ;
V_199 = F_368 ( & V_631 , V_625 , V_626 , V_627 , V_628 ) ;
if ( V_625 )
V_199 = F_84 ( V_624 , V_629 , V_630 ) ;
if ( V_199 )
* V_628 = V_432 ;
return V_199 ;
}
static void F_369 ( struct V_4 * V_5 )
{
struct V_632 V_633 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_370 ( & V_633 , V_5 -> V_7 ) ;
if ( V_5 -> V_33 . V_164 )
F_260 ( NULL , V_185 , & V_633 ) ;
else
F_260 ( NULL , V_176 , & V_633 ) ;
}
static void F_371 ( struct V_92 * V_92 , T_2 V_131 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_71 () ;
F_161 (net, dev) {
V_5 = F_45 ( V_7 ) ;
if ( V_5 ) {
int V_132 = ( ! V_5 -> V_33 . V_164 ) ^ ( ! V_131 ) ;
V_5 -> V_33 . V_164 = V_131 ;
if ( V_132 )
F_369 ( V_5 ) ;
}
}
F_74 () ;
}
static int F_372 ( struct V_133 * V_134 , int * V_135 , int V_131 )
{
struct V_92 * V_92 ;
int V_136 ;
if ( ! F_85 () )
return F_86 () ;
V_92 = (struct V_92 * ) V_134 -> V_137 ;
V_136 = * V_135 ;
* V_135 = V_131 ;
if ( V_135 == & V_92 -> V_16 . V_34 -> V_164 ) {
F_87 () ;
return 0 ;
}
if ( V_135 == & V_92 -> V_16 . V_108 -> V_164 ) {
V_92 -> V_16 . V_34 -> V_164 = V_131 ;
F_371 ( V_92 , V_131 ) ;
} else if ( ( ! V_131 ) ^ ( ! V_136 ) )
F_369 ( (struct V_4 * ) V_134 -> V_138 ) ;
F_87 () ;
return 0 ;
}
static
int F_373 ( struct V_133 * V_624 , int V_625 ,
void T_6 * V_626 , T_15 * V_627 , T_9 * V_628 )
{
int * V_629 = V_624 -> V_291 ;
int V_630 = * V_629 ;
T_9 V_432 = * V_628 ;
struct V_133 V_631 ;
int V_199 ;
V_631 = * V_624 ;
V_631 . V_291 = & V_630 ;
V_199 = F_368 ( & V_631 , V_625 , V_626 , V_627 , V_628 ) ;
if ( V_625 )
V_199 = F_372 ( V_624 , V_629 , V_630 ) ;
if ( V_199 )
* V_628 = V_432 ;
return V_199 ;
}
static int F_374 ( struct V_92 * V_92 , char * V_634 ,
struct V_4 * V_5 , struct V_78 * V_135 )
{
int V_220 ;
struct V_635 * V_636 ;
char V_637 [ sizeof( L_28 ) + V_565 ] ;
V_636 = F_375 ( & V_638 , sizeof( * V_636 ) , V_21 ) ;
if ( V_636 == NULL )
goto V_168;
for ( V_220 = 0 ; V_636 -> V_639 [ V_220 ] . V_291 ; V_220 ++ ) {
V_636 -> V_639 [ V_220 ] . V_291 += ( char * ) V_135 - ( char * ) & V_78 ;
V_636 -> V_639 [ V_220 ] . V_138 = V_5 ;
V_636 -> V_639 [ V_220 ] . V_137 = V_92 ;
}
snprintf ( V_637 , sizeof( V_637 ) , L_29 , V_634 ) ;
V_636 -> V_640 = F_376 ( V_92 , V_637 , V_636 -> V_639 ) ;
if ( V_636 -> V_640 == NULL )
goto free;
V_135 -> V_36 = V_636 ;
return 0 ;
free:
F_21 ( V_636 ) ;
V_168:
return - V_94 ;
}
static void F_377 ( struct V_78 * V_135 )
{
struct V_635 * V_636 ;
if ( V_135 -> V_36 == NULL )
return;
V_636 = V_135 -> V_36 ;
V_135 -> V_36 = NULL ;
F_378 ( V_636 -> V_640 ) ;
F_21 ( V_636 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_379 ( V_5 -> V_7 , V_5 -> V_37 , L_30 ,
& V_641 ) ;
F_374 ( F_28 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_42 ,
V_5 , & V_5 -> V_33 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_377 ( & V_5 -> V_33 ) ;
F_380 ( V_5 -> V_37 ) ;
}
static int T_11 F_381 ( struct V_92 * V_92 )
{
int V_93 = - V_26 ;
struct V_78 * V_642 , * V_643 ;
V_642 = F_375 ( & V_78 , sizeof( V_78 ) , V_21 ) ;
if ( V_642 == NULL )
goto V_644;
V_643 = F_375 ( & V_645 , sizeof( V_645 ) , V_21 ) ;
if ( V_643 == NULL )
goto V_646;
V_643 -> V_333 = V_647 . V_333 ;
V_643 -> V_164 = V_647 . V_164 ;
V_92 -> V_16 . V_108 = V_642 ;
V_92 -> V_16 . V_34 = V_643 ;
#ifdef F_382
V_93 = F_374 ( V_92 , L_31 , NULL , V_642 ) ;
if ( V_93 < 0 )
goto V_648;
V_93 = F_374 ( V_92 , L_32 , NULL , V_643 ) ;
if ( V_93 < 0 )
goto V_649;
#endif
return 0 ;
#ifdef F_382
V_649:
F_377 ( V_642 ) ;
V_648:
F_21 ( V_643 ) ;
#endif
V_646:
F_21 ( V_642 ) ;
V_644:
return V_93 ;
}
static void T_12 F_383 ( struct V_92 * V_92 )
{
#ifdef F_382
F_377 ( V_92 -> V_16 . V_34 ) ;
F_377 ( V_92 -> V_16 . V_108 ) ;
#endif
if ( ! F_172 ( V_92 , & V_650 ) ) {
F_21 ( V_92 -> V_16 . V_34 ) ;
F_21 ( V_92 -> V_16 . V_108 ) ;
}
}
int T_13 F_384 ( void )
{
int V_220 , V_93 ;
V_93 = F_385 () ;
if ( V_93 < 0 ) {
F_386 ( L_33 ,
V_41 , V_93 ) ;
goto V_168;
}
V_93 = F_302 ( & V_651 ) ;
if ( V_93 < 0 )
goto V_652;
F_239 () ;
if ( ! F_23 ( V_650 . V_653 ) )
V_93 = - V_26 ;
F_87 () ;
if ( V_93 )
goto V_654;
for ( V_220 = 0 ; V_220 < V_416 ; V_220 ++ )
F_387 ( & V_173 [ V_220 ] ) ;
F_388 ( & V_655 ) ;
F_236 ( 0 ) ;
V_93 = F_389 ( & V_656 ) ;
if ( V_93 < 0 )
goto V_657;
V_93 = F_390 ( V_658 , V_659 , NULL , F_359 ,
NULL ) ;
if ( V_93 < 0 )
goto V_96;
F_390 ( V_658 , V_382 , F_313 , NULL , NULL ) ;
F_390 ( V_658 , V_184 , F_311 , NULL , NULL ) ;
F_390 ( V_658 , V_660 , F_327 ,
F_324 , NULL ) ;
F_390 ( V_658 , V_501 , NULL ,
F_325 , NULL ) ;
F_390 ( V_658 , V_505 , NULL ,
F_326 , NULL ) ;
F_390 ( V_658 , V_661 , F_63 ,
F_70 , NULL ) ;
F_391 () ;
return 0 ;
V_96:
F_392 ( & V_656 ) ;
V_657:
F_393 ( & V_655 ) ;
V_654:
F_304 ( & V_651 ) ;
V_652:
F_394 () ;
V_168:
return V_93 ;
}
void F_395 ( void )
{
struct V_6 * V_7 ;
int V_220 ;
F_393 ( & V_655 ) ;
F_304 ( & V_651 ) ;
F_394 () ;
F_239 () ;
F_396 ( & V_656 ) ;
F_83 (&init_net, dev) {
if ( F_45 ( V_7 ) == NULL )
continue;
F_266 ( V_7 , 1 ) ;
}
F_266 ( V_650 . V_653 , 2 ) ;
F_126 ( & V_166 ) ;
for ( V_220 = 0 ; V_220 < V_416 ; V_220 ++ )
F_59 ( ! F_397 ( & V_173 [ V_220 ] ) ) ;
F_127 ( & V_166 ) ;
F_7 ( & V_451 ) ;
F_87 () ;
}
