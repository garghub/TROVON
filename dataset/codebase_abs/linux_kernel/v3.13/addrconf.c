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
int V_14 ;
if ( F_18 ( ( void V_15 * * ) V_5 -> V_16 . V_17 ,
sizeof( struct V_18 ) ,
F_19 ( struct V_18 ) ) < 0 )
goto V_19;
F_20 (i) {
struct V_18 * V_20 ;
V_20 = F_21 ( V_5 -> V_16 . V_17 [ 0 ] , V_14 ) ;
F_22 ( & V_20 -> V_21 ) ;
#if V_22 == 2
V_20 = F_21 ( V_5 -> V_16 . V_17 [ 1 ] , V_14 ) ;
F_22 ( & V_20 -> V_21 ) ;
#endif
}
V_5 -> V_16 . V_23 = F_23 ( sizeof( struct V_24 ) ,
V_25 ) ;
if ( ! V_5 -> V_16 . V_23 )
goto V_26;
V_5 -> V_16 . V_27 = F_23 ( sizeof( struct V_28 ) ,
V_25 ) ;
if ( ! V_5 -> V_16 . V_27 )
goto V_29;
return 0 ;
V_29:
F_24 ( V_5 -> V_16 . V_23 ) ;
V_26:
F_25 ( ( void V_15 * * ) V_5 -> V_16 . V_17 ) ;
V_19:
return - V_30 ;
}
static struct V_4 * F_26 ( struct V_6 * V_7 )
{
struct V_4 * V_31 ;
F_27 () ;
if ( V_7 -> V_32 < V_33 )
return NULL ;
V_31 = F_23 ( sizeof( struct V_4 ) , V_25 ) ;
if ( V_31 == NULL )
return NULL ;
F_28 ( & V_31 -> V_34 ) ;
V_31 -> V_7 = V_7 ;
F_29 ( & V_31 -> V_35 ) ;
F_30 ( & V_31 -> V_8 , V_36 ,
( unsigned long ) V_31 ) ;
memcpy ( & V_31 -> V_37 , F_31 ( V_7 ) -> V_17 . V_38 , sizeof( V_31 -> V_37 ) ) ;
V_31 -> V_37 . V_39 = V_7 -> V_32 ;
V_31 -> V_37 . V_40 = NULL ;
V_31 -> V_41 = F_32 ( V_7 , & V_42 ) ;
if ( V_31 -> V_41 == NULL ) {
F_24 ( V_31 ) ;
return NULL ;
}
if ( V_31 -> V_37 . V_43 )
F_33 ( V_7 ) ;
F_34 ( V_7 ) ;
if ( F_17 ( V_31 ) < 0 ) {
F_35 ( V_44
L_1 ,
V_45 , V_7 -> V_46 ) ;
F_36 ( & V_42 , V_31 -> V_41 ) ;
F_37 ( V_7 ) ;
F_24 ( V_31 ) ;
return NULL ;
}
if ( F_38 ( V_31 ) < 0 ) {
F_35 ( V_44
L_2 ,
V_45 , V_7 -> V_46 ) ;
F_36 ( & V_42 , V_31 -> V_41 ) ;
V_31 -> V_47 = 1 ;
F_39 ( V_31 ) ;
return NULL ;
}
F_13 ( V_31 ) ;
if ( V_7 -> V_48 & ( V_49 | V_50 ) )
V_31 -> V_37 . V_51 = - 1 ;
#if F_40 ( V_52 )
if ( V_7 -> type == V_53 && ( V_7 -> V_54 & V_55 ) ) {
F_41 ( L_3 , V_7 -> V_46 ) ;
V_31 -> V_37 . V_56 = 0 ;
}
#endif
F_29 ( & V_31 -> V_57 ) ;
F_30 ( & V_31 -> V_58 , V_59 , ( unsigned long ) V_31 ) ;
if ( ( V_7 -> V_48 & V_50 ) ||
V_7 -> type == V_60 ||
V_7 -> type == V_61 ||
V_7 -> type == V_53 ||
V_7 -> type == V_62 ) {
V_31 -> V_37 . V_63 = - 1 ;
} else {
F_13 ( V_31 ) ;
V_59 ( ( unsigned long ) V_31 ) ;
}
V_31 -> V_64 = V_65 ;
if ( F_42 ( V_7 ) && F_4 ( V_7 ) )
V_31 -> V_66 |= V_67 ;
F_43 ( V_31 ) ;
V_31 -> V_68 = V_13 ;
F_2 ( V_31 ) ;
F_44 ( V_7 -> V_69 , V_31 ) ;
F_45 ( V_7 , & V_70 ) ;
F_45 ( V_7 , & V_71 ) ;
if ( V_31 -> V_37 . V_43 && ( V_7 -> V_48 & V_72 ) )
F_45 ( V_7 , & V_73 ) ;
return V_31 ;
}
static struct V_4 * F_46 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_27 () ;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_26 ( V_7 ) ;
if ( ! V_5 )
return NULL ;
}
if ( V_7 -> V_48 & V_74 )
F_48 ( V_5 ) ;
return V_5 ;
}
static int F_49 ( int type )
{
int V_75 = F_50 ( sizeof( struct V_76 ) )
+ F_51 ( 4 ) ;
if ( type == - 1 || type == V_77 )
V_75 += F_51 ( 4 ) ;
#ifdef F_52
if ( type == - 1 || type == V_78 )
V_75 += F_51 ( 4 ) ;
#endif
return V_75 ;
}
static int F_53 ( struct V_79 * V_80 , int V_81 ,
struct V_82 * V_83 , T_1 V_84 ,
T_1 V_85 , int V_86 , unsigned int V_48 ,
int type )
{
struct V_87 * V_88 ;
struct V_76 * V_89 ;
V_88 = F_54 ( V_80 , V_84 , V_85 , V_86 , sizeof( struct V_76 ) ,
V_48 ) ;
if ( V_88 == NULL )
return - V_90 ;
V_89 = F_55 ( V_88 ) ;
V_89 -> V_91 = V_92 ;
if ( F_56 ( V_80 , V_93 , V_81 ) < 0 )
goto V_94;
if ( ( type == - 1 || type == V_77 ) &&
F_56 ( V_80 , V_77 , V_83 -> V_43 ) < 0 )
goto V_94;
#ifdef F_52
if ( ( type == - 1 || type == V_78 ) &&
F_56 ( V_80 , V_78 ,
V_83 -> V_95 ) < 0 )
goto V_94;
#endif
return F_57 ( V_80 , V_88 ) ;
V_94:
F_58 ( V_80 , V_88 ) ;
return - V_90 ;
}
void F_59 ( struct V_96 * V_96 , int type , int V_81 ,
struct V_82 * V_83 )
{
struct V_79 * V_80 ;
int V_97 = - V_98 ;
V_80 = F_60 ( F_49 ( type ) , V_99 ) ;
if ( V_80 == NULL )
goto V_100;
V_97 = F_53 ( V_80 , V_81 , V_83 , 0 , 0 ,
V_101 , 0 , type ) ;
if ( V_97 < 0 ) {
F_61 ( V_97 == - V_90 ) ;
F_62 ( V_80 ) ;
goto V_100;
}
F_63 ( V_80 , V_96 , 0 , V_102 , NULL , V_99 ) ;
return;
V_100:
F_64 ( V_96 , V_102 , V_97 ) ;
}
static int F_65 ( struct V_79 * V_103 ,
struct V_87 * V_88 )
{
struct V_96 * V_96 = F_66 ( V_103 -> V_104 ) ;
struct V_105 * V_106 [ V_107 + 1 ] ;
struct V_76 * V_89 ;
struct V_79 * V_80 ;
struct V_82 * V_83 ;
struct V_4 * V_108 ;
struct V_6 * V_7 ;
int V_81 ;
int V_97 ;
V_97 = F_67 ( V_88 , sizeof( * V_89 ) , V_106 , V_107 ,
V_109 ) ;
if ( V_97 < 0 )
goto V_100;
V_97 = V_110 ;
if ( ! V_106 [ V_93 ] )
goto V_100;
V_81 = F_68 ( V_106 [ V_93 ] ) ;
switch ( V_81 ) {
case V_111 :
V_83 = V_96 -> V_17 . V_112 ;
break;
case V_113 :
V_83 = V_96 -> V_17 . V_38 ;
break;
default:
V_7 = F_69 ( V_96 , V_81 ) ;
if ( V_7 == NULL )
goto V_100;
V_108 = F_47 ( V_7 ) ;
if ( V_108 == NULL )
goto V_100;
V_83 = & V_108 -> V_37 ;
break;
}
V_97 = - V_98 ;
V_80 = F_60 ( F_49 ( - 1 ) , V_99 ) ;
if ( V_80 == NULL )
goto V_100;
V_97 = F_53 ( V_80 , V_81 , V_83 ,
F_70 ( V_103 ) . V_84 ,
V_88 -> V_114 , V_101 , 0 ,
- 1 ) ;
if ( V_97 < 0 ) {
F_61 ( V_97 == - V_90 ) ;
F_62 ( V_80 ) ;
goto V_100;
}
V_97 = F_71 ( V_80 , V_96 , F_70 ( V_103 ) . V_84 ) ;
V_100:
return V_97 ;
}
static int F_72 ( struct V_79 * V_80 ,
struct V_115 * V_116 )
{
struct V_96 * V_96 = F_66 ( V_80 -> V_104 ) ;
int V_117 , V_118 ;
int V_119 , V_120 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_121 * V_122 ;
V_118 = V_116 -> args [ 0 ] ;
V_120 = V_119 = V_116 -> args [ 1 ] ;
for ( V_117 = V_118 ; V_117 < V_123 ; V_117 ++ , V_120 = 0 ) {
V_119 = 0 ;
V_122 = & V_96 -> V_124 [ V_117 ] ;
F_73 () ;
V_116 -> V_85 = F_74 ( & V_96 -> V_17 . V_125 ) ^
V_96 -> V_126 ;
F_75 (dev, head, index_hlist) {
if ( V_119 < V_120 )
goto V_127;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
goto V_127;
if ( F_53 ( V_80 , V_7 -> V_81 ,
& V_5 -> V_37 ,
F_70 ( V_116 -> V_80 ) . V_84 ,
V_116 -> V_88 -> V_114 ,
V_101 ,
V_128 ,
- 1 ) <= 0 ) {
F_76 () ;
goto V_129;
}
F_77 ( V_116 , F_78 ( V_80 ) ) ;
V_127:
V_119 ++ ;
}
F_76 () ;
}
if ( V_117 == V_123 ) {
if ( F_53 ( V_80 , V_111 ,
V_96 -> V_17 . V_112 ,
F_70 ( V_116 -> V_80 ) . V_84 ,
V_116 -> V_88 -> V_114 ,
V_101 , V_128 ,
- 1 ) <= 0 )
goto V_129;
else
V_117 ++ ;
}
if ( V_117 == V_123 + 1 ) {
if ( F_53 ( V_80 , V_113 ,
V_96 -> V_17 . V_38 ,
F_70 ( V_116 -> V_80 ) . V_84 ,
V_116 -> V_88 -> V_114 ,
V_101 , V_128 ,
- 1 ) <= 0 )
goto V_129;
else
V_117 ++ ;
}
V_129:
V_116 -> args [ 0 ] = V_117 ;
V_116 -> args [ 1 ] = V_119 ;
return V_80 -> V_130 ;
}
static void F_79 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_9 * V_131 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_37 . V_43 )
F_33 ( V_7 ) ;
if ( V_7 -> V_48 & V_72 ) {
if ( V_5 -> V_37 . V_43 ) {
F_45 ( V_7 , & V_73 ) ;
F_45 ( V_7 , & V_132 ) ;
F_45 ( V_7 , & V_133 ) ;
} else {
F_80 ( V_7 , & V_73 ) ;
F_80 ( V_7 , & V_132 ) ;
F_80 ( V_7 , & V_133 ) ;
}
}
F_81 (ifa, &idev->addr_list, if_list) {
if ( V_131 -> V_48 & V_134 )
continue;
if ( V_5 -> V_37 . V_43 )
F_82 ( V_131 ) ;
else
F_83 ( V_131 ) ;
}
F_59 ( F_31 ( V_7 ) , V_77 ,
V_7 -> V_81 , & V_5 -> V_37 ) ;
}
static void F_84 ( struct V_96 * V_96 , T_2 V_135 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_85 (net, dev) {
V_5 = F_47 ( V_7 ) ;
if ( V_5 ) {
int V_136 = ( ! V_5 -> V_37 . V_43 ) ^ ( ! V_135 ) ;
V_5 -> V_37 . V_43 = V_135 ;
if ( V_136 )
F_79 ( V_5 ) ;
}
}
}
static int F_86 ( struct V_137 * V_138 , int * V_139 , int V_135 )
{
struct V_96 * V_96 ;
int V_140 ;
if ( ! F_87 () )
return F_88 () ;
V_96 = (struct V_96 * ) V_138 -> V_141 ;
V_140 = * V_139 ;
* V_139 = V_135 ;
if ( V_139 == & V_96 -> V_17 . V_38 -> V_43 ) {
if ( ( ! V_135 ) ^ ( ! V_140 ) )
F_59 ( V_96 , V_77 ,
V_113 ,
V_96 -> V_17 . V_38 ) ;
F_89 () ;
return 0 ;
}
if ( V_139 == & V_96 -> V_17 . V_112 -> V_43 ) {
V_96 -> V_17 . V_38 -> V_43 = V_135 ;
F_84 ( V_96 , V_135 ) ;
if ( ( ! V_135 ) ^ ( ! V_140 ) )
F_59 ( V_96 , V_77 ,
V_111 ,
V_96 -> V_17 . V_112 ) ;
} else if ( ( ! V_135 ) ^ ( ! V_140 ) )
F_79 ( (struct V_4 * ) V_138 -> V_142 ) ;
F_89 () ;
if ( V_135 )
F_90 ( V_96 ) ;
return 1 ;
}
void F_91 ( struct V_9 * V_10 )
{
F_61 ( ! F_92 ( & V_10 -> V_143 ) ) ;
#ifdef F_93
F_94 ( L_4 , V_45 ) ;
#endif
F_95 ( V_10 -> V_5 ) ;
if ( F_7 ( & V_10 -> V_11 ) )
F_96 ( L_5 , V_10 ) ;
if ( V_10 -> V_144 != V_145 ) {
F_97 ( L_6 , V_10 ) ;
return;
}
F_98 ( V_10 -> V_146 ) ;
F_99 ( V_10 , V_147 ) ;
}
static void
F_100 ( struct V_4 * V_5 , struct V_9 * V_10 )
{
struct V_148 * V_139 ;
int V_149 = F_101 ( & V_10 -> V_150 ) ;
F_102 (p, &idev->addr_list) {
struct V_9 * V_131
= F_103 ( V_139 , struct V_9 , V_151 ) ;
if ( V_149 >= F_101 ( & V_131 -> V_150 ) )
break;
}
F_104 ( & V_10 -> V_151 , V_139 ) ;
}
static T_1 F_105 ( const struct V_152 * V_150 )
{
return F_106 ( F_107 ( V_150 ) , V_153 ) ;
}
static struct V_9 *
F_108 ( struct V_4 * V_5 , const struct V_152 * V_150 ,
const struct V_152 * V_154 , int V_155 ,
int V_156 , T_1 V_48 , T_1 V_157 , T_1 V_158 )
{
struct V_9 * V_131 = NULL ;
struct V_159 * V_146 ;
unsigned int V_160 ;
int V_97 = 0 ;
int V_161 = F_109 ( V_150 ) ;
if ( V_161 == V_162 ||
V_161 & V_163 ||
( ! ( V_5 -> V_7 -> V_48 & V_50 ) &&
V_161 & V_164 ) )
return F_110 ( - V_165 ) ;
F_111 () ;
if ( V_5 -> V_47 ) {
V_97 = - V_166 ;
goto V_167;
}
if ( V_5 -> V_37 . V_168 ) {
V_97 = - V_169 ;
goto V_167;
}
F_112 ( & V_170 ) ;
if ( F_113 ( F_31 ( V_5 -> V_7 ) , V_150 , V_5 -> V_7 ) ) {
F_35 ( L_7 ) ;
V_97 = - V_171 ;
goto V_172;
}
V_131 = F_23 ( sizeof( struct V_9 ) , V_99 ) ;
if ( V_131 == NULL ) {
F_35 ( L_8 ) ;
V_97 = - V_98 ;
goto V_172;
}
V_146 = F_114 ( V_5 , V_150 , false ) ;
if ( F_115 ( V_146 ) ) {
V_97 = F_116 ( V_146 ) ;
goto V_172;
}
V_131 -> V_150 = * V_150 ;
if ( V_154 )
V_131 -> V_154 = * V_154 ;
F_117 ( & V_131 -> V_34 ) ;
F_117 ( & V_131 -> V_173 ) ;
F_30 ( & V_131 -> V_11 , V_174 ,
( unsigned long ) V_131 ) ;
F_118 ( & V_131 -> V_143 ) ;
V_131 -> V_156 = V_156 ;
V_131 -> V_175 = V_155 ;
V_131 -> V_48 = V_48 | V_134 ;
V_131 -> V_157 = V_157 ;
V_131 -> V_158 = V_158 ;
V_131 -> V_1 = V_131 -> V_68 = V_13 ;
V_131 -> V_176 = false ;
V_131 -> V_146 = V_146 ;
V_131 -> V_5 = V_5 ;
F_13 ( V_5 ) ;
F_16 ( V_131 ) ;
V_160 = F_105 ( V_150 ) ;
F_119 ( & V_131 -> V_143 , & V_177 [ V_160 ] ) ;
F_120 ( & V_170 ) ;
F_121 ( & V_5 -> V_34 ) ;
F_100 ( V_5 , V_131 ) ;
if ( V_131 -> V_48 & V_178 ) {
F_122 ( & V_131 -> V_179 , & V_5 -> V_57 ) ;
F_16 ( V_131 ) ;
}
F_16 ( V_131 ) ;
F_123 ( & V_5 -> V_34 ) ;
V_167:
F_124 () ;
if ( F_125 ( V_97 == 0 ) )
F_126 ( V_180 , V_131 ) ;
else {
F_24 ( V_131 ) ;
V_131 = F_110 ( V_97 ) ;
}
return V_131 ;
V_172:
F_120 ( & V_170 ) ;
goto V_167;
}
static void F_127 ( struct V_9 * V_10 )
{
struct V_9 * V_131 , * V_181 ;
struct V_4 * V_5 = V_10 -> V_5 ;
int V_144 ;
int V_182 = 0 , V_183 = 0 ;
unsigned long V_184 = V_13 ;
F_128 ( & V_10 -> V_173 ) ;
V_144 = V_10 -> V_144 ;
V_10 -> V_144 = V_145 ;
F_129 ( & V_10 -> V_173 ) ;
if ( V_144 == V_145 )
goto V_172;
F_128 ( & V_170 ) ;
F_130 ( & V_10 -> V_143 ) ;
F_129 ( & V_170 ) ;
F_131 ( & V_5 -> V_34 ) ;
if ( V_10 -> V_48 & V_178 ) {
F_132 ( & V_10 -> V_179 ) ;
if ( V_10 -> V_185 ) {
F_133 ( V_10 -> V_185 ) ;
V_10 -> V_185 = NULL ;
}
F_10 ( V_10 ) ;
}
F_134 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_131 == V_10 ) {
F_135 ( & V_10 -> V_151 ) ;
F_10 ( V_10 ) ;
if ( ! ( V_10 -> V_48 & V_186 ) || V_183 > 0 )
break;
V_182 = 1 ;
continue;
} else if ( V_10 -> V_48 & V_186 ) {
if ( F_136 ( & V_131 -> V_150 , & V_10 -> V_150 ,
V_10 -> V_175 ) ) {
if ( V_131 -> V_48 & V_186 ) {
V_183 = 1 ;
if ( V_182 )
break;
} else {
unsigned long V_187 ;
if ( ! V_183 )
V_183 = - 1 ;
F_112 ( & V_131 -> V_34 ) ;
V_187 = F_137 ( V_131 -> V_157 , V_3 ) ;
if ( F_138 ( V_184 ,
V_131 -> V_68 + V_187 * V_3 ) )
V_184 = V_131 -> V_68 + V_187 * V_3 ;
F_120 ( & V_131 -> V_34 ) ;
}
}
}
}
F_139 ( & V_5 -> V_34 ) ;
F_9 ( V_10 ) ;
F_140 ( V_188 , V_10 ) ;
F_126 ( V_189 , V_10 ) ;
if ( ( V_10 -> V_48 & V_186 ) && V_183 < 1 ) {
struct V_152 V_190 ;
struct V_159 * V_146 ;
F_141 ( & V_190 , & V_10 -> V_150 , V_10 -> V_175 ) ;
V_146 = F_142 ( & V_190 ,
V_10 -> V_175 ,
V_10 -> V_5 -> V_7 ,
0 , V_191 | V_192 ) ;
if ( V_146 ) {
if ( V_183 == 0 ) {
F_143 ( V_146 ) ;
V_146 = NULL ;
} else if ( ! ( V_146 -> V_193 & V_194 ) ) {
F_144 ( V_146 , V_184 ) ;
}
}
F_98 ( V_146 ) ;
}
F_145 ( V_10 ) ;
V_172:
F_133 ( V_10 ) ;
}
static int F_146 ( struct V_9 * V_10 , struct V_9 * V_195 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_152 V_150 , * V_196 ;
unsigned long V_197 , V_198 , V_199 , V_200 ;
unsigned long V_201 ;
int V_202 ;
int V_203 = 0 ;
T_1 V_204 ;
unsigned long V_205 = V_13 ;
F_121 ( & V_5 -> V_34 ) ;
if ( V_195 ) {
F_128 ( & V_195 -> V_34 ) ;
memcpy ( & V_150 . V_206 [ 8 ] , & V_195 -> V_150 . V_206 [ 8 ] , 8 ) ;
F_129 ( & V_195 -> V_34 ) ;
V_196 = & V_150 ;
} else {
V_196 = NULL ;
}
V_207:
F_13 ( V_5 ) ;
if ( V_5 -> V_37 . V_63 <= 0 ) {
F_123 ( & V_5 -> V_34 ) ;
F_41 ( L_9 , V_45 ) ;
F_95 ( V_5 ) ;
V_203 = - 1 ;
goto V_172;
}
F_128 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_208 ++ >= V_5 -> V_37 . V_209 ) {
V_5 -> V_37 . V_63 = - 1 ;
F_129 ( & V_10 -> V_34 ) ;
F_123 ( & V_5 -> V_34 ) ;
F_97 ( L_10 ,
V_45 ) ;
F_95 ( V_5 ) ;
V_203 = - 1 ;
goto V_172;
}
F_16 ( V_10 ) ;
memcpy ( V_150 . V_206 , V_10 -> V_150 . V_206 , 8 ) ;
F_147 ( V_5 , V_196 ) ;
memcpy ( & V_150 . V_206 [ 8 ] , V_5 -> V_210 , 8 ) ;
V_200 = ( V_205 - V_10 -> V_68 ) / V_3 ;
V_198 = F_148 ( V_211 ,
V_10 -> V_157 ,
V_5 -> V_37 . V_212 + V_200 ) ;
V_197 = F_148 ( V_211 ,
V_10 -> V_158 ,
V_5 -> V_37 . V_213 + V_200 -
V_5 -> V_37 . V_214 ) ;
V_202 = V_10 -> V_175 ;
V_199 = V_10 -> V_68 ;
F_129 ( & V_10 -> V_34 ) ;
V_201 = V_5 -> V_37 . V_209 *
V_5 -> V_37 . V_215 *
V_5 -> V_41 -> V_216 / V_3 ;
F_123 ( & V_5 -> V_34 ) ;
if ( V_197 <= V_201 ) {
F_133 ( V_10 ) ;
F_95 ( V_5 ) ;
V_203 = - 1 ;
goto V_172;
}
V_204 = V_178 ;
if ( V_10 -> V_48 & V_217 )
V_204 |= V_217 ;
V_195 = F_108 ( V_5 , & V_150 , NULL , V_202 ,
F_149 ( & V_150 ) , V_204 ,
V_198 , V_197 ) ;
if ( F_115 ( V_195 ) ) {
F_133 ( V_10 ) ;
F_95 ( V_5 ) ;
F_41 ( L_11 , V_45 ) ;
V_196 = & V_150 ;
F_121 ( & V_5 -> V_34 ) ;
goto V_207;
}
F_128 ( & V_195 -> V_34 ) ;
V_195 -> V_185 = V_10 ;
V_195 -> V_1 = V_205 ;
V_195 -> V_68 = V_199 ;
F_129 ( & V_195 -> V_34 ) ;
F_150 ( V_195 ) ;
F_133 ( V_195 ) ;
F_95 ( V_5 ) ;
V_172:
return V_203 ;
}
static inline int F_151 ( int type )
{
if ( type & ( V_218 | V_219 | V_164 ) )
return 1 ;
return 0 ;
}
static int F_152 ( struct V_96 * V_96 ,
struct V_220 * V_221 ,
struct V_222 * V_223 ,
int V_14 )
{
int V_203 ;
if ( V_14 <= V_221 -> V_224 ) {
switch ( V_14 ) {
case V_225 :
V_203 = V_221 -> V_226 ;
break;
case V_227 :
V_203 = V_221 -> V_228 ;
break;
default:
V_203 = ! ! F_153 ( V_14 , V_221 -> V_229 ) ;
}
goto V_172;
}
switch ( V_14 ) {
case V_230 :
V_203 = ! ! V_221 -> V_131 ;
break;
case V_231 :
V_203 = F_154 ( & V_221 -> V_131 -> V_150 , V_223 -> V_150 ) ;
break;
case V_225 :
V_203 = F_155 ( V_221 -> V_161 ) ;
if ( V_203 >= V_223 -> V_156 )
V_203 = - V_203 ;
else
V_203 -= 128 ;
V_221 -> V_226 = V_203 ;
break;
case V_232 :
V_203 = F_151 ( V_221 -> V_161 ) ||
! ( V_221 -> V_131 -> V_48 & ( V_233 | V_217 ) ) ;
break;
#ifdef F_156
case V_234 :
{
int V_235 = ! ( V_223 -> V_236 & V_237 ) ;
V_203 = ! ( V_221 -> V_131 -> V_48 & V_238 ) ^ V_235 ;
break;
}
#endif
case V_239 :
V_203 = ( ! V_223 -> V_81 ||
V_223 -> V_81 == V_221 -> V_131 -> V_5 -> V_7 -> V_81 ) ;
break;
case V_240 :
V_203 = F_157 ( V_96 ,
& V_221 -> V_131 -> V_150 , V_221 -> V_161 ,
V_221 -> V_131 -> V_5 -> V_7 -> V_81 ) == V_223 -> V_241 ;
break;
case V_242 :
{
int V_243 = V_223 -> V_236 & ( V_244 | V_245 ) ?
! ! ( V_223 -> V_236 & V_245 ) :
V_221 -> V_131 -> V_5 -> V_37 . V_63 >= 2 ;
V_203 = ( ! ( V_221 -> V_131 -> V_48 & V_178 ) ) ^ V_243 ;
break;
}
case V_246 :
V_203 = ! ( F_158 ( & V_221 -> V_131 -> V_150 ) ^
F_158 ( V_223 -> V_150 ) ) ;
break;
case V_227 :
V_203 = F_159 ( & V_221 -> V_131 -> V_150 , V_223 -> V_150 ) ;
if ( V_203 > V_221 -> V_131 -> V_175 )
V_203 = V_221 -> V_131 -> V_175 ;
V_221 -> V_228 = V_203 ;
break;
default:
V_203 = 0 ;
}
if ( V_203 )
F_160 ( V_14 , V_221 -> V_229 ) ;
V_221 -> V_224 = V_14 ;
V_172:
return V_203 ;
}
int F_161 ( struct V_96 * V_96 , const struct V_6 * V_247 ,
const struct V_152 * V_248 , unsigned int V_236 ,
struct V_152 * V_249 )
{
struct V_220 V_250 [ 2 ] ,
* V_221 = & V_250 [ 0 ] , * V_251 = & V_250 [ 1 ] ;
struct V_222 V_223 ;
struct V_6 * V_7 ;
int V_252 ;
V_252 = F_162 ( V_248 ) ;
V_223 . V_150 = V_248 ;
V_223 . V_81 = V_247 ? V_247 -> V_81 : 0 ;
V_223 . V_156 = F_155 ( V_252 ) ;
V_223 . V_241 = F_157 ( V_96 , V_248 , V_252 , V_223 . V_81 ) ;
V_223 . V_236 = V_236 ;
V_251 -> V_224 = - 1 ;
V_251 -> V_131 = NULL ;
F_73 () ;
F_163 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_252 & V_163 ) ||
V_223 . V_156 <= V_253 ) &&
V_223 . V_81 && V_7 -> V_81 != V_223 . V_81 )
continue;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
continue;
F_164 ( & V_5 -> V_34 ) ;
F_81 (score->ifa, &idev->addr_list, if_list) {
int V_14 ;
if ( ( V_221 -> V_131 -> V_48 & V_134 ) &&
( ! ( V_221 -> V_131 -> V_48 & V_217 ) ) )
continue;
V_221 -> V_161 = F_162 ( & V_221 -> V_131 -> V_150 ) ;
if ( F_165 ( V_221 -> V_161 == V_162 ||
V_221 -> V_161 & V_163 ) ) {
F_166 ( V_254
L_12
L_13 ,
V_7 -> V_46 ) ;
continue;
}
V_221 -> V_224 = - 1 ;
F_167 ( V_221 -> V_229 , V_255 ) ;
for ( V_14 = 0 ; V_14 < V_255 ; V_14 ++ ) {
int V_256 , V_257 ;
V_256 = F_152 ( V_96 , V_251 , & V_223 , V_14 ) ;
V_257 = F_152 ( V_96 , V_221 , & V_223 , V_14 ) ;
if ( V_256 > V_257 ) {
if ( V_14 == V_225 &&
V_221 -> V_226 > 0 ) {
goto V_258;
}
break;
} else if ( V_256 < V_257 ) {
if ( V_251 -> V_131 )
F_133 ( V_251 -> V_131 ) ;
F_16 ( V_221 -> V_131 ) ;
F_168 ( V_251 , V_221 ) ;
V_221 -> V_131 = V_251 -> V_131 ;
break;
}
}
}
V_258:
F_169 ( & V_5 -> V_34 ) ;
}
F_76 () ;
if ( ! V_251 -> V_131 )
return - V_165 ;
* V_249 = V_251 -> V_131 -> V_150 ;
F_133 ( V_251 -> V_131 ) ;
return 0 ;
}
int F_170 ( struct V_4 * V_5 , struct V_152 * V_150 ,
unsigned char V_259 )
{
struct V_9 * V_10 ;
int V_97 = - V_165 ;
F_81 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_156 == V_260 &&
! ( V_10 -> V_48 & V_259 ) ) {
* V_150 = V_10 -> V_150 ;
V_97 = 0 ;
break;
}
}
return V_97 ;
}
int F_171 ( struct V_6 * V_7 , struct V_152 * V_150 ,
unsigned char V_259 )
{
struct V_4 * V_5 ;
int V_97 = - V_165 ;
F_73 () ;
V_5 = F_47 ( V_7 ) ;
if ( V_5 ) {
F_164 ( & V_5 -> V_34 ) ;
V_97 = F_170 ( V_5 , V_150 , V_259 ) ;
F_169 ( & V_5 -> V_34 ) ;
}
F_76 () ;
return V_97 ;
}
static int F_172 ( struct V_4 * V_5 )
{
int V_261 = 0 ;
struct V_9 * V_10 ;
F_164 ( & V_5 -> V_34 ) ;
F_81 (ifp, &idev->addr_list, if_list)
V_261 ++ ;
F_169 ( & V_5 -> V_34 ) ;
return V_261 ;
}
int F_173 ( struct V_96 * V_96 , const struct V_152 * V_150 ,
const struct V_6 * V_7 , int V_262 )
{
struct V_9 * V_10 ;
unsigned int V_160 = F_105 ( V_150 ) ;
F_111 () ;
F_75 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_174 ( F_31 ( V_10 -> V_5 -> V_7 ) , V_96 ) )
continue;
if ( F_154 ( & V_10 -> V_150 , V_150 ) &&
! ( V_10 -> V_48 & V_134 ) &&
( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_156 & ( V_260 | V_263 ) || V_262 ) ) ) {
F_124 () ;
return 1 ;
}
}
F_124 () ;
return 0 ;
}
static bool F_113 ( struct V_96 * V_96 , const struct V_152 * V_150 ,
struct V_6 * V_7 )
{
unsigned int V_160 = F_105 ( V_150 ) ;
struct V_9 * V_10 ;
F_175 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_174 ( F_31 ( V_10 -> V_5 -> V_7 ) , V_96 ) )
continue;
if ( F_154 ( & V_10 -> V_150 , V_150 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
bool F_176 ( const struct V_152 * V_150 ,
const unsigned int V_175 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_131 ;
bool V_203 = false ;
F_73 () ;
V_5 = F_47 ( V_7 ) ;
if ( V_5 ) {
F_164 ( & V_5 -> V_34 ) ;
F_81 (ifa, &idev->addr_list, if_list) {
V_203 = F_136 ( V_150 , & V_131 -> V_150 , V_175 ) ;
if ( V_203 )
break;
}
F_169 ( & V_5 -> V_34 ) ;
}
F_76 () ;
return V_203 ;
}
int F_177 ( const struct V_152 * V_150 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_9 * V_131 ;
int V_183 ;
V_183 = 0 ;
F_73 () ;
V_5 = F_47 ( V_7 ) ;
if ( V_5 ) {
F_164 ( & V_5 -> V_34 ) ;
F_81 (ifa, &idev->addr_list, if_list) {
V_183 = F_136 ( V_150 , & V_131 -> V_150 ,
V_131 -> V_175 ) ;
if ( V_183 )
break;
}
F_169 ( & V_5 -> V_34 ) ;
}
F_76 () ;
return V_183 ;
}
struct V_9 * F_178 ( struct V_96 * V_96 , const struct V_152 * V_150 ,
struct V_6 * V_7 , int V_262 )
{
struct V_9 * V_10 , * V_264 = NULL ;
unsigned int V_160 = F_105 ( V_150 ) ;
F_111 () ;
F_179 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_174 ( F_31 ( V_10 -> V_5 -> V_7 ) , V_96 ) )
continue;
if ( F_154 ( & V_10 -> V_150 , V_150 ) ) {
if ( V_7 == NULL || V_10 -> V_5 -> V_7 == V_7 ||
! ( V_10 -> V_156 & ( V_260 | V_263 ) || V_262 ) ) {
V_264 = V_10 ;
F_16 ( V_10 ) ;
break;
}
}
}
F_124 () ;
return V_264 ;
}
static void F_180 ( struct V_9 * V_10 , int V_265 )
{
if ( V_10 -> V_48 & V_186 ) {
F_128 ( & V_10 -> V_34 ) ;
F_9 ( V_10 ) ;
V_10 -> V_48 |= V_134 ;
if ( V_265 )
V_10 -> V_48 |= V_266 ;
F_129 ( & V_10 -> V_34 ) ;
if ( V_265 )
F_140 ( 0 , V_10 ) ;
F_133 ( V_10 ) ;
} else if ( V_10 -> V_48 & V_178 ) {
struct V_9 * V_185 ;
F_128 ( & V_10 -> V_34 ) ;
V_185 = V_10 -> V_185 ;
if ( V_185 ) {
F_16 ( V_185 ) ;
F_129 ( & V_10 -> V_34 ) ;
F_146 ( V_185 , V_10 ) ;
F_133 ( V_185 ) ;
} else {
F_129 ( & V_10 -> V_34 ) ;
}
F_127 ( V_10 ) ;
} else
F_127 ( V_10 ) ;
}
static int F_181 ( struct V_9 * V_10 )
{
int V_97 = - V_267 ;
F_112 ( & V_10 -> V_173 ) ;
if ( V_10 -> V_144 == V_268 ) {
V_10 -> V_144 = V_269 ;
V_97 = 0 ;
}
F_120 ( & V_10 -> V_173 ) ;
return V_97 ;
}
void F_182 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_181 ( V_10 ) ) {
F_133 ( V_10 ) ;
return;
}
F_183 ( L_14 ,
V_10 -> V_5 -> V_7 -> V_46 , & V_10 -> V_150 ) ;
if ( V_5 -> V_37 . V_51 > 1 && ! V_5 -> V_37 . V_168 ) {
struct V_152 V_150 ;
V_150 . V_270 [ 0 ] = F_184 ( 0xfe800000 ) ;
V_150 . V_270 [ 1 ] = 0 ;
if ( ! F_185 ( V_150 . V_206 + 8 , V_5 -> V_7 ) &&
F_154 ( & V_10 -> V_150 , & V_150 ) ) {
V_5 -> V_37 . V_168 = 1 ;
F_41 ( L_15 ,
V_10 -> V_5 -> V_7 -> V_46 ) ;
}
}
F_180 ( V_10 , 1 ) ;
}
void F_186 ( struct V_6 * V_7 , const struct V_152 * V_150 )
{
struct V_152 V_271 ;
if ( V_7 -> V_48 & ( V_50 | V_49 ) )
return;
F_187 ( V_150 , & V_271 ) ;
F_45 ( V_7 , & V_271 ) ;
}
void F_188 ( struct V_4 * V_5 , const struct V_152 * V_150 )
{
struct V_152 V_271 ;
if ( V_5 -> V_7 -> V_48 & ( V_50 | V_49 ) )
return;
F_187 ( V_150 , & V_271 ) ;
F_189 ( V_5 , & V_271 ) ;
}
static void F_82 ( struct V_9 * V_10 )
{
struct V_152 V_150 ;
if ( V_10 -> V_175 >= 127 )
return;
F_141 ( & V_150 , & V_10 -> V_150 , V_10 -> V_175 ) ;
if ( F_190 ( & V_150 ) )
return;
F_191 ( V_10 -> V_5 -> V_7 , & V_150 ) ;
}
static void F_83 ( struct V_9 * V_10 )
{
struct V_152 V_150 ;
if ( V_10 -> V_175 >= 127 )
return;
F_141 ( & V_150 , & V_10 -> V_150 , V_10 -> V_175 ) ;
if ( F_190 ( & V_150 ) )
return;
F_192 ( V_10 -> V_5 , & V_150 ) ;
}
static int F_193 ( T_3 * V_272 , struct V_6 * V_7 )
{
if ( V_7 -> V_273 != V_274 )
return - 1 ;
memcpy ( V_272 , V_7 -> V_275 , 3 ) ;
memcpy ( V_272 + 5 , V_7 -> V_275 + 3 , 3 ) ;
if ( V_7 -> V_276 ) {
V_272 [ 3 ] = ( V_7 -> V_276 >> 8 ) & 0xFF ;
V_272 [ 4 ] = V_7 -> V_276 & 0xFF ;
} else {
V_272 [ 3 ] = 0xFF ;
V_272 [ 4 ] = 0xFE ;
V_272 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_194 ( T_3 * V_272 , struct V_6 * V_7 )
{
if ( V_7 -> V_273 != V_277 )
return - 1 ;
memcpy ( V_272 , V_7 -> V_275 , 8 ) ;
V_272 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_195 ( T_3 * V_272 , struct V_6 * V_7 )
{
union V_278 * V_279 ;
if ( V_7 -> V_273 != V_280 )
return - 1 ;
V_279 = (union V_278 * ) V_7 -> V_275 ;
memcpy ( V_272 , & V_279 -> V_281 . V_282 , sizeof( V_279 -> V_281 . V_282 ) ) ;
V_272 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_196 ( T_3 * V_272 , struct V_6 * V_7 )
{
if ( V_7 -> V_273 != V_283 )
return - 1 ;
memset ( V_272 , 0 , 7 ) ;
V_272 [ 7 ] = * ( T_3 * ) V_7 -> V_275 ;
return 0 ;
}
static int F_197 ( T_3 * V_272 , struct V_6 * V_7 )
{
if ( V_7 -> V_273 != V_284 )
return - 1 ;
memcpy ( V_272 , V_7 -> V_275 + 12 , 8 ) ;
V_272 [ 0 ] |= 2 ;
return 0 ;
}
static int F_198 ( T_3 * V_272 , T_4 V_150 )
{
if ( V_150 == 0 )
return - 1 ;
V_272 [ 0 ] = ( F_199 ( V_150 ) || F_200 ( V_150 ) ||
F_201 ( V_150 ) || F_202 ( V_150 ) ||
F_203 ( V_150 ) || F_204 ( V_150 ) ||
F_205 ( V_150 ) || F_206 ( V_150 ) ||
F_207 ( V_150 ) || F_208 ( V_150 ) ||
F_209 ( V_150 ) ) ? 0x00 : 0x02 ;
V_272 [ 1 ] = 0 ;
V_272 [ 2 ] = 0x5E ;
V_272 [ 3 ] = 0xFE ;
memcpy ( V_272 + 4 , & V_150 , 4 ) ;
return 0 ;
}
static int F_210 ( T_3 * V_272 , struct V_6 * V_7 )
{
if ( V_7 -> V_54 & V_55 )
return F_198 ( V_272 , * ( T_4 * ) V_7 -> V_275 ) ;
return - 1 ;
}
static int F_211 ( T_3 * V_272 , struct V_6 * V_7 )
{
return F_198 ( V_272 , * ( T_4 * ) V_7 -> V_275 ) ;
}
static int F_212 ( T_3 * V_272 , struct V_6 * V_7 )
{
memcpy ( V_272 , V_7 -> V_285 , 3 ) ;
memcpy ( V_272 + 5 , V_7 -> V_285 + 3 , 3 ) ;
V_272 [ 3 ] = 0xFF ;
V_272 [ 4 ] = 0xFE ;
V_272 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_185 ( T_3 * V_272 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_286 :
case V_287 :
return F_193 ( V_272 , V_7 ) ;
case V_288 :
return F_196 ( V_272 , V_7 ) ;
case V_289 :
return F_197 ( V_272 , V_7 ) ;
case V_53 :
return F_210 ( V_272 , V_7 ) ;
case V_290 :
return F_211 ( V_272 , V_7 ) ;
case V_291 :
return F_194 ( V_272 , V_7 ) ;
case V_292 :
return F_195 ( V_272 , V_7 ) ;
case V_61 :
return F_212 ( V_272 , V_7 ) ;
}
return - 1 ;
}
static int F_213 ( T_3 * V_272 , struct V_4 * V_5 )
{
int V_97 = - 1 ;
struct V_9 * V_10 ;
F_164 ( & V_5 -> V_34 ) ;
F_81 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_156 == V_260 && ! ( V_10 -> V_48 & V_134 ) ) {
memcpy ( V_272 , V_10 -> V_150 . V_206 + 8 , 8 ) ;
V_97 = 0 ;
break;
}
}
F_169 ( & V_5 -> V_34 ) ;
return V_97 ;
}
static void F_214 ( struct V_4 * V_5 )
{
V_293:
F_215 ( V_5 -> V_210 , sizeof( V_5 -> V_210 ) ) ;
V_5 -> V_210 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_210 [ 0 ] == 0xfd &&
( V_5 -> V_210 [ 1 ] & V_5 -> V_210 [ 2 ] & V_5 -> V_210 [ 3 ] & V_5 -> V_210 [ 4 ] & V_5 -> V_210 [ 5 ] & V_5 -> V_210 [ 6 ] ) == 0xff &&
( V_5 -> V_210 [ 7 ] & 0x80 ) )
goto V_293;
if ( ( V_5 -> V_210 [ 0 ] | V_5 -> V_210 [ 1 ] ) == 0 ) {
if ( V_5 -> V_210 [ 2 ] == 0x5e && V_5 -> V_210 [ 3 ] == 0xfe )
goto V_293;
if ( ( V_5 -> V_210 [ 2 ] | V_5 -> V_210 [ 3 ] | V_5 -> V_210 [ 4 ] | V_5 -> V_210 [ 5 ] | V_5 -> V_210 [ 6 ] | V_5 -> V_210 [ 7 ] ) == 0x00 )
goto V_293;
}
}
static void V_59 ( unsigned long V_294 )
{
struct V_4 * V_5 = (struct V_4 * ) V_294 ;
unsigned long V_184 ;
F_111 () ;
F_131 ( & V_5 -> V_34 ) ;
if ( V_5 -> V_47 )
goto V_172;
F_214 ( V_5 ) ;
V_184 = V_13 +
V_5 -> V_37 . V_213 * V_3 -
V_5 -> V_37 . V_209 * V_5 -> V_37 . V_215 * V_5 -> V_41 -> V_216 -
V_5 -> V_37 . V_214 * V_3 ;
if ( F_138 ( V_184 , V_13 ) ) {
F_97 ( L_16 ,
V_45 , V_5 -> V_7 -> V_46 ) ;
goto V_172;
}
if ( ! F_14 ( & V_5 -> V_58 , V_184 ) )
F_13 ( V_5 ) ;
V_172:
F_139 ( & V_5 -> V_34 ) ;
F_124 () ;
F_95 ( V_5 ) ;
}
static void F_147 ( struct V_4 * V_5 , struct V_152 * V_196 )
{
if ( V_196 && memcmp ( V_5 -> V_210 , & V_196 -> V_206 [ 8 ] , 8 ) == 0 )
F_214 ( V_5 ) ;
}
static void
F_216 ( struct V_152 * V_295 , int V_296 , struct V_6 * V_7 ,
unsigned long V_184 , T_1 V_48 )
{
struct V_297 V_298 = {
. V_299 = V_300 ,
. V_301 = V_302 ,
. V_303 = V_7 -> V_81 ,
. V_304 = V_184 ,
. V_305 = V_296 ,
. V_306 = V_307 | V_48 ,
. V_308 . V_309 = F_31 ( V_7 ) ,
. V_310 = V_311 ,
} ;
V_298 . V_312 = * V_295 ;
#if F_40 ( V_52 )
if ( V_7 -> type == V_53 && ( V_7 -> V_48 & V_313 ) )
V_298 . V_306 |= V_314 ;
#endif
F_217 ( & V_298 ) ;
}
static struct V_159 * F_142 ( const struct V_152 * V_295 ,
int V_296 ,
const struct V_6 * V_7 ,
T_1 V_48 , T_1 V_315 )
{
struct V_316 * V_317 ;
struct V_159 * V_146 = NULL ;
struct V_318 * V_138 ;
V_138 = F_218 ( F_31 ( V_7 ) , V_300 ) ;
if ( V_138 == NULL )
return NULL ;
F_164 ( & V_138 -> V_319 ) ;
V_317 = F_219 ( & V_138 -> V_320 , V_295 , V_296 , NULL , 0 ) ;
if ( ! V_317 )
goto V_172;
for ( V_146 = V_317 -> V_321 ; V_146 ; V_146 = V_146 -> V_223 . V_322 ) {
if ( V_146 -> V_223 . V_7 -> V_81 != V_7 -> V_81 )
continue;
if ( ( V_146 -> V_193 & V_48 ) != V_48 )
continue;
if ( ( V_146 -> V_193 & V_315 ) != 0 )
continue;
F_220 ( & V_146 -> V_223 ) ;
break;
}
V_172:
F_169 ( & V_138 -> V_319 ) ;
return V_146 ;
}
static void F_221 ( struct V_6 * V_7 )
{
struct V_297 V_298 = {
. V_299 = V_323 ,
. V_301 = V_302 ,
. V_303 = V_7 -> V_81 ,
. V_305 = 8 ,
. V_306 = V_307 ,
. V_308 . V_309 = F_31 ( V_7 ) ,
} ;
F_222 ( & V_298 . V_312 , F_184 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_217 ( & V_298 ) ;
}
static struct V_4 * F_223 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_27 () ;
V_5 = F_46 ( V_7 ) ;
if ( ! V_5 )
return F_110 ( - V_98 ) ;
if ( V_5 -> V_37 . V_168 )
return F_110 ( - V_169 ) ;
if ( ! ( V_7 -> V_48 & V_50 ) )
F_221 ( V_7 ) ;
return V_5 ;
}
void F_224 ( struct V_6 * V_7 , T_3 * V_324 , int V_130 , bool V_325 )
{
struct V_326 * V_327 ;
V_211 V_157 ;
V_211 V_158 ;
int V_161 ;
struct V_4 * V_108 ;
struct V_96 * V_96 = F_31 ( V_7 ) ;
V_327 = (struct V_326 * ) V_324 ;
if ( V_130 < sizeof( struct V_326 ) ) {
F_35 ( L_17 ) ;
return;
}
V_161 = F_109 ( & V_327 -> V_190 ) ;
if ( V_161 & ( V_163 | V_328 ) )
return;
V_157 = F_225 ( V_327 -> V_329 ) ;
V_158 = F_225 ( V_327 -> V_330 ) ;
if ( V_158 > V_157 ) {
F_226 ( L_18 ) ;
return;
}
V_108 = F_227 ( V_7 ) ;
if ( V_108 == NULL ) {
F_228 ( L_19 ,
V_7 -> V_46 ) ;
return;
}
if ( V_327 -> V_183 ) {
struct V_159 * V_146 ;
unsigned long V_331 ;
if ( V_3 > V_332 )
V_331 = F_137 ( V_157 , V_3 ) ;
else
V_331 = F_137 ( V_157 , V_332 ) ;
if ( F_229 ( V_331 ) )
V_331 *= V_3 ;
V_146 = F_142 ( & V_327 -> V_190 ,
V_327 -> V_175 ,
V_7 ,
V_333 | V_334 ,
V_191 | V_192 ) ;
if ( V_146 ) {
if ( V_157 == 0 ) {
F_143 ( V_146 ) ;
V_146 = NULL ;
} else if ( F_229 ( V_331 ) ) {
F_144 ( V_146 , V_13 + V_331 ) ;
} else {
F_230 ( V_146 ) ;
}
} else if ( V_157 ) {
T_5 V_184 = 0 ;
int V_48 = V_333 | V_334 ;
if ( F_229 ( V_331 ) ) {
V_48 |= V_194 ;
V_184 = F_231 ( V_331 ) ;
}
F_216 ( & V_327 -> V_190 , V_327 -> V_175 ,
V_7 , V_184 , V_48 ) ;
}
F_98 ( V_146 ) ;
}
if ( V_327 -> V_335 && V_108 -> V_37 . V_335 ) {
struct V_9 * V_10 ;
struct V_152 V_150 ;
int V_336 = 0 , V_337 = 0 ;
bool V_176 = false ;
if ( V_327 -> V_175 == 64 ) {
memcpy ( & V_150 , & V_327 -> V_190 , 8 ) ;
if ( ! F_190 ( & V_108 -> V_64 ) ) {
F_164 ( & V_108 -> V_34 ) ;
memcpy ( V_150 . V_206 + 8 ,
V_108 -> V_64 . V_206 + 8 , 8 ) ;
F_169 ( & V_108 -> V_34 ) ;
V_176 = true ;
} else if ( F_185 ( V_150 . V_206 + 8 , V_7 ) &&
F_213 ( V_150 . V_206 + 8 , V_108 ) ) {
F_95 ( V_108 ) ;
return;
}
goto V_338;
}
F_228 ( L_20 ,
V_327 -> V_175 ) ;
F_95 ( V_108 ) ;
return;
V_338:
V_10 = F_178 ( V_96 , & V_150 , V_7 , 1 ) ;
if ( V_10 == NULL && V_157 ) {
int V_339 = V_108 -> V_37 . V_339 ;
T_1 V_204 = 0 ;
#ifdef F_232
if ( V_108 -> V_37 . V_340 &&
! V_96 -> V_17 . V_112 -> V_43 && V_325 )
V_204 = V_217 ;
#endif
if ( ! V_339 ||
F_172 ( V_108 ) < V_339 )
V_10 = F_108 ( V_108 , & V_150 , NULL ,
V_327 -> V_175 ,
V_161 & V_341 ,
V_204 , V_157 ,
V_158 ) ;
if ( F_233 ( V_10 ) ) {
F_95 ( V_108 ) ;
return;
}
V_337 = 0 ;
V_336 = 1 ;
V_10 -> V_1 = V_13 ;
V_10 -> V_176 = V_176 ;
F_150 ( V_10 ) ;
}
if ( V_10 ) {
int V_48 ;
unsigned long V_205 ;
struct V_9 * V_195 ;
T_1 V_342 ;
F_112 ( & V_10 -> V_34 ) ;
V_205 = V_13 ;
if ( V_10 -> V_157 > ( V_205 - V_10 -> V_68 ) / V_3 )
V_342 = V_10 -> V_157 - ( V_205 - V_10 -> V_68 ) / V_3 ;
else
V_342 = 0 ;
if ( ! V_337 && ! V_336 && V_342 ) {
const T_1 V_343 = F_234 (
V_342 , ( T_1 ) V_344 ) ;
V_157 = F_235 ( V_157 , V_343 ) ;
V_337 = 1 ;
}
if ( V_337 ) {
V_10 -> V_157 = V_157 ;
V_10 -> V_158 = V_158 ;
V_10 -> V_68 = V_205 ;
V_48 = V_10 -> V_48 ;
V_10 -> V_48 &= ~ V_233 ;
F_120 ( & V_10 -> V_34 ) ;
if ( ! ( V_48 & V_134 ) )
F_140 ( 0 , V_10 ) ;
} else
F_120 ( & V_10 -> V_34 ) ;
F_164 ( & V_108 -> V_34 ) ;
F_81 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_200 , V_345 , V_346 ;
if ( V_10 != V_195 -> V_185 )
continue;
V_200 = ( V_205 - V_195 -> V_1 ) / V_3 ;
V_345 = V_108 -> V_37 . V_212 - V_200 ;
if ( V_345 < 0 )
V_345 = 0 ;
V_346 = V_108 -> V_37 . V_213 -
V_108 -> V_37 . V_214 -
V_200 ;
if ( V_346 < 0 )
V_346 = 0 ;
if ( V_157 > V_345 )
V_157 = V_345 ;
if ( V_158 > V_346 )
V_158 = V_346 ;
F_112 ( & V_195 -> V_34 ) ;
V_48 = V_195 -> V_48 ;
V_195 -> V_157 = V_157 ;
V_195 -> V_158 = V_158 ;
V_195 -> V_68 = V_205 ;
if ( V_158 > 0 )
V_195 -> V_48 &= ~ V_233 ;
F_120 ( & V_195 -> V_34 ) ;
if ( ! ( V_48 & V_134 ) )
F_140 ( 0 , V_195 ) ;
}
if ( ( V_336 || F_236 ( & V_108 -> V_57 ) ) && V_108 -> V_37 . V_63 > 0 ) {
F_169 ( & V_108 -> V_34 ) ;
F_146 ( V_10 , NULL ) ;
} else {
F_169 ( & V_108 -> V_34 ) ;
}
F_133 ( V_10 ) ;
F_237 ( 0 ) ;
}
}
F_238 ( V_347 , V_108 , V_327 ) ;
F_95 ( V_108 ) ;
}
int F_239 ( struct V_96 * V_96 , void T_6 * V_348 )
{
struct V_349 V_350 ;
struct V_6 * V_7 ;
int V_97 = - V_110 ;
F_240 () ;
V_97 = - V_351 ;
if ( F_241 ( & V_350 , V_348 , sizeof( struct V_349 ) ) )
goto V_352;
V_7 = F_69 ( V_96 , V_350 . V_353 ) ;
V_97 = - V_166 ;
if ( V_7 == NULL )
goto V_352;
#if F_40 ( V_52 )
if ( V_7 -> type == V_53 ) {
const struct V_354 * V_355 = V_7 -> V_356 ;
struct V_357 V_358 ;
struct V_359 V_139 ;
V_97 = - V_165 ;
if ( ! ( F_109 ( & V_350 . V_360 ) & V_219 ) )
goto V_352;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_361 . V_248 = V_350 . V_360 . V_270 [ 3 ] ;
V_139 . V_361 . V_249 = 0 ;
V_139 . V_361 . V_362 = 4 ;
V_139 . V_361 . V_363 = 5 ;
V_139 . V_361 . V_364 = V_365 ;
V_139 . V_361 . V_366 = 64 ;
V_358 . V_367 . V_368 = ( V_369 void T_6 * ) & V_139 ;
if ( V_355 -> V_370 ) {
T_7 V_371 = F_242 () ;
F_243 ( V_372 ) ;
V_97 = V_355 -> V_370 ( V_7 , & V_358 , V_373 ) ;
F_243 ( V_371 ) ;
} else
V_97 = - V_374 ;
if ( V_97 == 0 ) {
V_97 = - V_98 ;
V_7 = F_244 ( V_96 , V_139 . V_46 ) ;
if ( ! V_7 )
goto V_352;
V_97 = F_245 ( V_7 ) ;
}
}
#endif
V_352:
F_89 () ;
return V_97 ;
}
static int F_246 ( struct V_96 * V_96 , int V_81 , const struct V_152 * V_295 ,
const struct V_152 * V_375 ,
unsigned int V_296 , T_8 V_376 , V_211 V_158 ,
V_211 V_157 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_156 ;
T_1 V_48 ;
T_5 V_184 ;
unsigned long V_377 ;
F_27 () ;
if ( V_296 > 128 )
return - V_110 ;
if ( ! V_157 || V_158 > V_157 )
return - V_110 ;
V_7 = F_69 ( V_96 , V_81 ) ;
if ( ! V_7 )
return - V_166 ;
V_5 = F_223 ( V_7 ) ;
if ( F_115 ( V_5 ) )
return F_116 ( V_5 ) ;
V_156 = F_149 ( V_295 ) ;
V_377 = F_137 ( V_157 , V_3 ) ;
if ( F_229 ( V_377 ) ) {
V_184 = F_231 ( V_377 * V_3 ) ;
V_157 = V_377 ;
V_48 = V_194 ;
} else {
V_184 = 0 ;
V_48 = 0 ;
V_376 |= V_186 ;
}
V_377 = F_137 ( V_158 , V_3 ) ;
if ( F_229 ( V_377 ) ) {
if ( V_377 == 0 )
V_376 |= V_233 ;
V_158 = V_377 ;
}
V_10 = F_108 ( V_5 , V_295 , V_375 , V_296 , V_156 , V_376 ,
V_157 , V_158 ) ;
if ( ! F_115 ( V_10 ) ) {
F_216 ( & V_10 -> V_150 , V_10 -> V_175 , V_7 ,
V_184 , V_48 ) ;
F_150 ( V_10 ) ;
F_133 ( V_10 ) ;
F_237 ( 0 ) ;
return 0 ;
}
return F_116 ( V_10 ) ;
}
static int F_247 ( struct V_96 * V_96 , int V_81 , const struct V_152 * V_295 ,
unsigned int V_296 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_296 > 128 )
return - V_110 ;
V_7 = F_69 ( V_96 , V_81 ) ;
if ( ! V_7 )
return - V_166 ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL )
return - V_378 ;
F_164 ( & V_5 -> V_34 ) ;
F_81 (ifp, &idev->addr_list, if_list) {
if ( V_10 -> V_175 == V_296 &&
F_154 ( V_295 , & V_10 -> V_150 ) ) {
F_16 ( V_10 ) ;
F_169 ( & V_5 -> V_34 ) ;
F_127 ( V_10 ) ;
return 0 ;
}
}
F_169 ( & V_5 -> V_34 ) ;
return - V_165 ;
}
int F_248 ( struct V_96 * V_96 , void T_6 * V_348 )
{
struct V_349 V_350 ;
int V_97 ;
if ( ! F_249 ( V_96 -> V_379 , V_380 ) )
return - V_381 ;
if ( F_241 ( & V_350 , V_348 , sizeof( struct V_349 ) ) )
return - V_351 ;
F_240 () ;
V_97 = F_246 ( V_96 , V_350 . V_353 , & V_350 . V_360 , NULL ,
V_350 . V_382 , V_186 ,
V_383 , V_383 ) ;
F_89 () ;
return V_97 ;
}
int F_250 ( struct V_96 * V_96 , void T_6 * V_348 )
{
struct V_349 V_350 ;
int V_97 ;
if ( ! F_249 ( V_96 -> V_379 , V_380 ) )
return - V_381 ;
if ( F_241 ( & V_350 , V_348 , sizeof( struct V_349 ) ) )
return - V_351 ;
F_240 () ;
V_97 = F_247 ( V_96 , V_350 . V_353 , & V_350 . V_360 ,
V_350 . V_382 ) ;
F_89 () ;
return V_97 ;
}
static void F_251 ( struct V_4 * V_5 , const struct V_152 * V_150 ,
int V_296 , int V_156 )
{
struct V_9 * V_10 ;
V_10 = F_108 ( V_5 , V_150 , NULL , V_296 ,
V_156 , V_186 ,
V_383 , V_383 ) ;
if ( ! F_115 ( V_10 ) ) {
F_128 ( & V_10 -> V_34 ) ;
V_10 -> V_48 &= ~ V_134 ;
F_129 ( & V_10 -> V_34 ) ;
F_140 ( V_384 , V_10 ) ;
F_133 ( V_10 ) ;
}
}
static void F_252 ( struct V_4 * V_5 )
{
struct V_152 V_150 ;
struct V_6 * V_7 ;
struct V_96 * V_96 = F_31 ( V_5 -> V_7 ) ;
int V_156 , V_296 ;
T_1 V_385 = 0 ;
F_27 () ;
memset ( & V_150 , 0 , sizeof( struct V_152 ) ) ;
memcpy ( & V_150 . V_270 [ 3 ] , V_5 -> V_7 -> V_275 , 4 ) ;
if ( V_5 -> V_7 -> V_48 & V_313 ) {
V_150 . V_270 [ 0 ] = F_184 ( 0xfe800000 ) ;
V_156 = V_260 ;
V_296 = 64 ;
} else {
V_156 = V_219 ;
V_296 = 96 ;
V_385 |= V_314 ;
}
if ( V_150 . V_270 [ 3 ] ) {
F_251 ( V_5 , & V_150 , V_296 , V_156 ) ;
F_216 ( & V_150 , V_296 , V_5 -> V_7 , 0 , V_385 ) ;
return;
}
F_85 (net, dev) {
struct V_386 * V_387 = F_253 ( V_7 ) ;
if ( V_387 && ( V_7 -> V_48 & V_74 ) ) {
struct V_388 * V_131 ;
int V_389 = V_156 ;
for ( V_131 = V_387 -> V_390 ; V_131 ; V_131 = V_131 -> V_391 ) {
V_150 . V_270 [ 3 ] = V_131 -> V_392 ;
if ( V_131 -> V_393 == V_394 )
continue;
if ( V_131 -> V_393 >= V_395 ) {
if ( V_5 -> V_7 -> V_48 & V_313 )
continue;
V_389 |= V_263 ;
}
F_251 ( V_5 , & V_150 , V_296 , V_389 ) ;
F_216 ( & V_150 , V_296 , V_5 -> V_7 , 0 ,
V_385 ) ;
}
}
}
}
static void F_254 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_6 * V_396 ;
struct V_9 * V_397 ;
struct V_159 * V_398 ;
F_27 () ;
if ( ( V_5 = F_46 ( V_7 ) ) == NULL ) {
F_94 ( L_21 , V_45 ) ;
return;
}
F_251 ( V_5 , & V_399 , 128 , V_263 ) ;
F_85 (dev_net(dev), sp_dev) {
if ( ! strcmp ( V_396 -> V_46 , V_7 -> V_46 ) )
continue;
V_5 = F_47 ( V_396 ) ;
if ( ! V_5 )
continue;
F_164 ( & V_5 -> V_34 ) ;
F_81 (sp_ifa, &idev->addr_list, if_list) {
if ( V_397 -> V_48 & ( V_266 | V_134 ) )
continue;
if ( V_397 -> V_146 )
continue;
V_398 = F_114 ( V_5 , & V_397 -> V_150 , false ) ;
if ( ! F_115 ( V_398 ) ) {
V_397 -> V_146 = V_398 ;
F_255 ( V_398 ) ;
}
}
F_169 ( & V_5 -> V_34 ) ;
}
}
static void F_256 ( struct V_4 * V_5 , const struct V_152 * V_150 )
{
struct V_9 * V_10 ;
T_1 V_204 = V_186 ;
#ifdef F_232
if ( V_5 -> V_37 . V_340 &&
! F_31 ( V_5 -> V_7 ) -> V_17 . V_112 -> V_43 )
V_204 |= V_217 ;
#endif
V_10 = F_108 ( V_5 , V_150 , NULL , 64 , V_260 , V_204 ,
V_383 , V_383 ) ;
if ( ! F_115 ( V_10 ) ) {
F_216 ( & V_10 -> V_150 , V_10 -> V_175 , V_5 -> V_7 , 0 , 0 ) ;
F_150 ( V_10 ) ;
F_133 ( V_10 ) ;
}
}
static void F_257 ( struct V_6 * V_7 )
{
struct V_152 V_150 ;
struct V_4 * V_5 ;
F_27 () ;
if ( ( V_7 -> type != V_286 ) &&
( V_7 -> type != V_287 ) &&
( V_7 -> type != V_288 ) &&
( V_7 -> type != V_289 ) &&
( V_7 -> type != V_291 ) &&
( V_7 -> type != V_292 ) &&
( V_7 -> type != V_61 ) ) {
return;
}
V_5 = F_223 ( V_7 ) ;
if ( F_115 ( V_5 ) )
return;
memset ( & V_150 , 0 , sizeof( struct V_152 ) ) ;
V_150 . V_270 [ 0 ] = F_184 ( 0xFE800000 ) ;
if ( F_185 ( V_150 . V_206 + 8 , V_7 ) == 0 )
F_256 ( V_5 , & V_150 ) ;
}
static void F_258 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_27 () ;
if ( ( V_5 = F_46 ( V_7 ) ) == NULL ) {
F_94 ( L_21 , V_45 ) ;
return;
}
if ( V_7 -> V_54 & V_55 ) {
struct V_152 V_150 ;
F_222 ( & V_150 , F_184 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( ! F_185 ( V_150 . V_206 + 8 , V_7 ) )
F_256 ( V_5 , & V_150 ) ;
return;
}
F_252 ( V_5 ) ;
if ( V_7 -> V_48 & V_313 )
F_221 ( V_7 ) ;
}
static void F_259 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_152 V_150 ;
F_27 () ;
if ( ( V_5 = F_46 ( V_7 ) ) == NULL ) {
F_94 ( L_21 , V_45 ) ;
return;
}
F_222 ( & V_150 , F_184 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
if ( ! F_185 ( V_150 . V_206 + 8 , V_7 ) )
F_256 ( V_5 , & V_150 ) ;
}
static inline int
F_260 ( struct V_4 * V_5 , struct V_6 * V_400 )
{
struct V_152 V_401 ;
if ( ! F_171 ( V_400 , & V_401 , V_134 ) ) {
F_256 ( V_5 , & V_401 ) ;
return 0 ;
}
return - 1 ;
}
static int F_261 ( struct V_402 * V_403 , unsigned long V_86 ,
void * V_404 )
{
struct V_6 * V_7 = F_262 ( V_404 ) ;
struct V_4 * V_5 = F_47 ( V_7 ) ;
int V_405 = 0 ;
int V_97 ;
switch ( V_86 ) {
case V_406 :
if ( ! V_5 && V_7 -> V_32 >= V_33 ) {
V_5 = F_26 ( V_7 ) ;
if ( ! V_5 )
return F_263 ( - V_30 ) ;
}
break;
case V_180 :
case V_407 :
if ( V_7 -> V_48 & V_408 )
break;
if ( V_86 == V_180 ) {
if ( ! F_4 ( V_7 ) ) {
F_41 ( L_22 ,
V_7 -> V_46 ) ;
break;
}
if ( ! V_5 && V_7 -> V_32 >= V_33 )
V_5 = F_26 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_66 |= V_67 ;
V_405 = 1 ;
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
F_41 ( L_23 ,
V_7 -> V_46 ) ;
V_405 = 1 ;
}
switch ( V_7 -> type ) {
#if F_40 ( V_52 )
case V_53 :
F_258 ( V_7 ) ;
break;
#endif
#if F_40 ( V_409 )
case V_290 :
F_259 ( V_7 ) ;
break;
#endif
case V_410 :
F_254 ( V_7 ) ;
break;
default:
F_257 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_405 )
F_264 ( V_5 ) ;
if ( V_5 -> V_37 . V_39 != V_7 -> V_32 &&
V_7 -> V_32 >= V_33 ) {
F_265 ( V_7 , V_7 -> V_32 ) ;
V_5 -> V_37 . V_39 = V_7 -> V_32 ;
}
V_5 -> V_68 = V_13 ;
F_266 ( V_411 , V_5 ) ;
if ( V_7 -> V_32 < V_33 )
F_267 ( V_7 , 1 ) ;
}
break;
case V_412 :
if ( V_5 && V_7 -> V_32 >= V_33 ) {
F_265 ( V_7 , V_7 -> V_32 ) ;
V_5 -> V_37 . V_39 = V_7 -> V_32 ;
break;
}
if ( ! V_5 && V_7 -> V_32 >= V_33 ) {
V_5 = F_26 ( V_7 ) ;
if ( V_5 )
break;
}
case V_189 :
case V_413 :
F_267 ( V_7 , V_86 != V_189 ) ;
break;
case V_414 :
if ( V_5 ) {
F_268 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_97 = F_38 ( V_5 ) ;
if ( V_97 )
return F_263 ( V_97 ) ;
}
break;
case V_415 :
case V_416 :
F_269 ( V_7 , V_86 ) ;
break;
}
return V_417 ;
}
static void F_269 ( struct V_6 * V_7 , unsigned long V_86 )
{
struct V_4 * V_5 ;
F_27 () ;
V_5 = F_47 ( V_7 ) ;
if ( V_86 == V_416 )
F_270 ( V_5 ) ;
else if ( V_86 == V_415 )
F_271 ( V_5 ) ;
}
static int F_267 ( struct V_6 * V_7 , int V_418 )
{
struct V_96 * V_96 = F_31 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_9 * V_131 ;
int V_144 , V_14 ;
F_27 () ;
F_272 ( V_96 , V_7 ) ;
F_273 ( & V_42 , V_7 ) ;
V_5 = F_47 ( V_7 ) ;
if ( V_5 == NULL )
return - V_166 ;
if ( V_418 ) {
V_5 -> V_47 = 1 ;
F_274 ( V_7 -> V_69 , NULL ) ;
F_268 ( V_5 ) ;
}
for ( V_14 = 0 ; V_14 < V_419 ; V_14 ++ ) {
struct V_121 * V_117 = & V_177 [ V_14 ] ;
F_128 ( & V_170 ) ;
V_420:
F_75 (ifa, h, addr_lst) {
if ( V_131 -> V_5 == V_5 ) {
F_130 ( & V_131 -> V_143 ) ;
F_9 ( V_131 ) ;
goto V_420;
}
}
F_129 ( & V_170 ) ;
}
F_131 ( & V_5 -> V_34 ) ;
F_6 ( V_5 ) ;
if ( ! V_418 )
V_5 -> V_66 &= ~ ( V_421 | V_422 | V_67 ) ;
if ( V_418 && F_7 ( & V_5 -> V_58 ) )
F_95 ( V_5 ) ;
while ( ! F_236 ( & V_5 -> V_57 ) ) {
V_131 = F_275 ( & V_5 -> V_57 ,
struct V_9 , V_179 ) ;
F_132 ( & V_131 -> V_179 ) ;
F_139 ( & V_5 -> V_34 ) ;
F_128 ( & V_131 -> V_34 ) ;
if ( V_131 -> V_185 ) {
F_133 ( V_131 -> V_185 ) ;
V_131 -> V_185 = NULL ;
}
F_129 ( & V_131 -> V_34 ) ;
F_133 ( V_131 ) ;
F_131 ( & V_5 -> V_34 ) ;
}
while ( ! F_236 ( & V_5 -> V_35 ) ) {
V_131 = F_275 ( & V_5 -> V_35 ,
struct V_9 , V_151 ) ;
F_9 ( V_131 ) ;
F_132 ( & V_131 -> V_151 ) ;
F_139 ( & V_5 -> V_34 ) ;
F_128 ( & V_131 -> V_173 ) ;
V_144 = V_131 -> V_144 ;
V_131 -> V_144 = V_145 ;
F_129 ( & V_131 -> V_173 ) ;
if ( V_144 != V_145 ) {
F_276 ( V_188 , V_131 ) ;
F_126 ( V_189 , V_131 ) ;
}
F_133 ( V_131 ) ;
F_131 ( & V_5 -> V_34 ) ;
}
F_139 ( & V_5 -> V_34 ) ;
if ( V_418 )
F_277 ( V_5 ) ;
else
F_278 ( V_5 ) ;
V_5 -> V_68 = V_13 ;
if ( V_418 ) {
F_3 ( V_5 ) ;
F_36 ( & V_42 , V_5 -> V_41 ) ;
F_273 ( & V_42 , V_7 ) ;
F_95 ( V_5 ) ;
}
return 0 ;
}
static void V_36 ( unsigned long V_294 )
{
struct V_4 * V_5 = (struct V_4 * ) V_294 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_152 V_401 ;
F_121 ( & V_5 -> V_34 ) ;
if ( V_5 -> V_47 || ! ( V_5 -> V_66 & V_67 ) )
goto V_172;
if ( ! F_279 ( V_5 ) )
goto V_172;
if ( V_5 -> V_66 & V_422 )
goto V_172;
if ( V_5 -> V_423 ++ < V_5 -> V_37 . V_56 ) {
F_123 ( & V_5 -> V_34 ) ;
if ( ! F_171 ( V_7 , & V_401 , V_134 ) )
F_280 ( V_7 , & V_401 ,
& V_73 ) ;
else
goto V_424;
F_121 ( & V_5 -> V_34 ) ;
F_11 ( V_5 , ( V_5 -> V_423 ==
V_5 -> V_37 . V_56 ) ?
V_5 -> V_37 . V_425 :
V_5 -> V_37 . V_426 ) ;
} else {
F_94 ( L_24 , V_5 -> V_7 -> V_46 ) ;
}
V_172:
F_123 ( & V_5 -> V_34 ) ;
V_424:
F_95 ( V_5 ) ;
}
static void F_281 ( struct V_9 * V_10 )
{
unsigned long V_427 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( V_10 -> V_48 & V_217 )
V_427 = 0 ;
else
V_427 = F_282 () % ( V_5 -> V_37 . V_425 ? : 1 ) ;
V_10 -> V_428 = V_5 -> V_37 . V_215 ;
F_15 ( V_10 , V_427 ) ;
}
static void F_150 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_186 ( V_7 , & V_10 -> V_150 ) ;
F_283 ( V_10 -> V_150 . V_270 [ 3 ] ) ;
F_164 ( & V_5 -> V_34 ) ;
F_112 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_144 == V_145 )
goto V_172;
if ( V_7 -> V_48 & ( V_49 | V_50 ) ||
V_5 -> V_37 . V_51 < 1 ||
! ( V_10 -> V_48 & V_134 ) ||
V_10 -> V_48 & V_429 ) {
V_10 -> V_48 &= ~ ( V_134 | V_217 | V_266 ) ;
F_120 ( & V_10 -> V_34 ) ;
F_169 ( & V_5 -> V_34 ) ;
F_284 ( V_10 ) ;
return;
}
if ( ! ( V_5 -> V_66 & V_67 ) ) {
F_120 ( & V_10 -> V_34 ) ;
F_169 ( & V_5 -> V_34 ) ;
F_16 ( V_10 ) ;
F_180 ( V_10 , 0 ) ;
return;
}
if ( V_10 -> V_48 & V_217 )
F_255 ( V_10 -> V_146 ) ;
F_281 ( V_10 ) ;
V_172:
F_120 ( & V_10 -> V_34 ) ;
F_169 ( & V_5 -> V_34 ) ;
}
static void V_174 ( unsigned long V_294 )
{
struct V_9 * V_10 = (struct V_9 * ) V_294 ;
struct V_4 * V_5 = V_10 -> V_5 ;
struct V_152 V_430 ;
if ( ! V_10 -> V_428 && F_181 ( V_10 ) )
goto V_172;
F_121 ( & V_5 -> V_34 ) ;
if ( V_5 -> V_47 || ! ( V_5 -> V_66 & V_67 ) ) {
F_123 ( & V_5 -> V_34 ) ;
goto V_172;
}
F_112 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_144 == V_145 ) {
F_120 ( & V_10 -> V_34 ) ;
F_123 ( & V_5 -> V_34 ) ;
goto V_172;
}
if ( V_10 -> V_428 == 0 ) {
V_10 -> V_48 &= ~ ( V_134 | V_217 | V_266 ) ;
F_120 ( & V_10 -> V_34 ) ;
F_123 ( & V_5 -> V_34 ) ;
F_284 ( V_10 ) ;
goto V_172;
}
V_10 -> V_428 -- ;
F_15 ( V_10 , V_10 -> V_5 -> V_41 -> V_216 ) ;
F_120 ( & V_10 -> V_34 ) ;
F_123 ( & V_5 -> V_34 ) ;
F_187 ( & V_10 -> V_150 , & V_430 ) ;
F_285 ( V_10 -> V_5 -> V_7 , NULL , & V_10 -> V_150 , & V_430 , & V_65 ) ;
V_172:
F_133 ( V_10 ) ;
}
static bool F_286 ( struct V_9 * V_10 )
{
struct V_9 * V_431 ;
struct V_4 * V_5 = V_10 -> V_5 ;
F_81 (ifpiter, &idev->addr_list, if_list) {
if ( V_10 != V_431 && V_431 -> V_156 == V_260 &&
( V_431 -> V_48 & ( V_186 | V_134 |
V_217 | V_266 ) ) ==
V_186 )
return false ;
}
return true ;
}
static void F_284 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
struct V_152 V_401 ;
bool V_432 , V_433 ;
F_9 ( V_10 ) ;
F_140 ( V_384 , V_10 ) ;
F_164 ( & V_10 -> V_5 -> V_34 ) ;
V_433 = V_10 -> V_156 == V_260 && F_286 ( V_10 ) ;
V_432 = V_433 &&
F_279 ( V_10 -> V_5 ) &&
V_10 -> V_5 -> V_37 . V_56 > 0 &&
( V_7 -> V_48 & V_50 ) == 0 ;
F_169 ( & V_10 -> V_5 -> V_34 ) ;
if ( V_433 )
F_287 ( V_10 -> V_5 ) ;
if ( V_432 ) {
if ( F_171 ( V_7 , & V_401 , V_134 ) )
return;
F_280 ( V_7 , & V_401 , & V_73 ) ;
F_131 ( & V_10 -> V_5 -> V_34 ) ;
F_112 ( & V_10 -> V_34 ) ;
V_10 -> V_5 -> V_423 = 1 ;
V_10 -> V_5 -> V_66 |= V_421 ;
F_11 ( V_10 -> V_5 ,
V_10 -> V_5 -> V_37 . V_426 ) ;
F_120 ( & V_10 -> V_34 ) ;
F_139 ( & V_10 -> V_5 -> V_34 ) ;
}
}
static void F_264 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
F_164 ( & V_5 -> V_34 ) ;
F_81 (ifp, &idev->addr_list, if_list) {
F_112 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_48 & V_134 &&
V_10 -> V_144 == V_268 )
F_281 ( V_10 ) ;
F_120 ( & V_10 -> V_34 ) ;
}
F_169 ( & V_5 -> V_34 ) ;
}
static struct V_9 * F_288 ( struct V_434 * V_85 , T_9 V_435 )
{
struct V_9 * V_131 = NULL ;
struct V_436 * V_144 = V_85 -> V_437 ;
struct V_96 * V_96 = F_289 ( V_85 ) ;
int V_139 = 0 ;
if ( V_435 == 0 ) {
V_144 -> V_438 = 0 ;
V_144 -> V_439 = 0 ;
}
for (; V_144 -> V_438 < V_419 ; ++ V_144 -> V_438 ) {
F_179 (ifa, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_174 ( F_31 ( V_131 -> V_5 -> V_7 ) , V_96 ) )
continue;
if ( V_139 < V_144 -> V_439 ) {
V_139 ++ ;
continue;
}
V_144 -> V_439 ++ ;
return V_131 ;
}
V_144 -> V_439 = 0 ;
V_139 = 0 ;
}
return NULL ;
}
static struct V_9 * F_290 ( struct V_434 * V_85 ,
struct V_9 * V_131 )
{
struct V_436 * V_144 = V_85 -> V_437 ;
struct V_96 * V_96 = F_289 ( V_85 ) ;
F_291 (ifa, addr_lst) {
if ( ! F_174 ( F_31 ( V_131 -> V_5 -> V_7 ) , V_96 ) )
continue;
V_144 -> V_439 ++ ;
return V_131 ;
}
while ( ++ V_144 -> V_438 < V_419 ) {
V_144 -> V_439 = 0 ;
F_179 (ifa,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_174 ( F_31 ( V_131 -> V_5 -> V_7 ) , V_96 ) )
continue;
V_144 -> V_439 ++ ;
return V_131 ;
}
}
return NULL ;
}
static void * F_292 ( struct V_434 * V_85 , T_9 * V_435 )
__acquires( T_10 )
{
F_111 () ;
return F_288 ( V_85 , * V_435 ) ;
}
static void * F_293 ( struct V_434 * V_85 , void * V_440 , T_9 * V_435 )
{
struct V_9 * V_131 ;
V_131 = F_290 ( V_85 , V_440 ) ;
++ * V_435 ;
return V_131 ;
}
static void F_294 ( struct V_434 * V_85 , void * V_440 )
__releases( T_10 )
{
F_124 () ;
}
static int F_295 ( struct V_434 * V_85 , void * V_440 )
{
struct V_9 * V_10 = (struct V_9 * ) V_440 ;
F_296 ( V_85 , L_25 ,
& V_10 -> V_150 ,
V_10 -> V_5 -> V_7 -> V_81 ,
V_10 -> V_175 ,
V_10 -> V_156 ,
V_10 -> V_48 ,
V_10 -> V_5 -> V_7 -> V_46 ) ;
return 0 ;
}
static int F_297 ( struct V_441 * V_441 , struct V_442 * V_442 )
{
return F_298 ( V_441 , V_442 , & V_443 ,
sizeof( struct V_436 ) ) ;
}
static int T_11 F_299 ( struct V_96 * V_96 )
{
if ( ! F_300 ( L_26 , V_444 , V_96 -> V_445 , & V_446 ) )
return - V_30 ;
return 0 ;
}
static void T_12 F_301 ( struct V_96 * V_96 )
{
F_302 ( L_26 , V_96 -> V_445 ) ;
}
int T_13 F_303 ( void )
{
return F_304 ( & V_447 ) ;
}
void F_305 ( void )
{
F_306 ( & V_447 ) ;
}
int F_307 ( struct V_96 * V_96 , const struct V_152 * V_150 )
{
int V_203 = 0 ;
struct V_9 * V_10 = NULL ;
unsigned int V_160 = F_105 ( V_150 ) ;
F_111 () ;
F_179 (ifp, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_174 ( F_31 ( V_10 -> V_5 -> V_7 ) , V_96 ) )
continue;
if ( F_154 ( & V_10 -> V_150 , V_150 ) &&
( V_10 -> V_48 & V_238 ) ) {
V_203 = 1 ;
break;
}
}
F_124 () ;
return V_203 ;
}
static void F_237 ( unsigned long V_448 )
{
unsigned long V_205 , V_449 , V_450 , V_451 ;
struct V_9 * V_10 ;
int V_14 ;
F_111 () ;
F_112 ( & V_452 ) ;
V_205 = V_13 ;
V_449 = F_308 ( V_205 + V_453 ) ;
F_7 ( & V_454 ) ;
for ( V_14 = 0 ; V_14 < V_419 ; V_14 ++ ) {
V_420:
F_179 (ifp,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_200 ;
if ( ( V_10 -> V_48 & V_186 ) &&
( V_10 -> V_158 == V_383 ) )
continue;
F_112 ( & V_10 -> V_34 ) ;
V_200 = ( V_205 - V_10 -> V_68 + V_455 ) / V_3 ;
if ( V_10 -> V_157 != V_383 &&
V_200 >= V_10 -> V_157 ) {
F_120 ( & V_10 -> V_34 ) ;
F_16 ( V_10 ) ;
F_127 ( V_10 ) ;
goto V_420;
} else if ( V_10 -> V_158 == V_383 ) {
F_120 ( & V_10 -> V_34 ) ;
continue;
} else if ( V_200 >= V_10 -> V_158 ) {
int V_456 = 0 ;
if ( ! ( V_10 -> V_48 & V_233 ) ) {
V_456 = 1 ;
V_10 -> V_48 |= V_233 ;
}
if ( ( V_10 -> V_157 != V_383 ) &&
( F_138 ( V_10 -> V_68 + V_10 -> V_157 * V_3 , V_449 ) ) )
V_449 = V_10 -> V_68 + V_10 -> V_157 * V_3 ;
F_120 ( & V_10 -> V_34 ) ;
if ( V_456 ) {
F_16 ( V_10 ) ;
F_140 ( 0 , V_10 ) ;
F_133 ( V_10 ) ;
goto V_420;
}
} else if ( ( V_10 -> V_48 & V_178 ) &&
! ( V_10 -> V_48 & V_134 ) ) {
unsigned long V_201 = V_10 -> V_5 -> V_37 . V_209 *
V_10 -> V_5 -> V_37 . V_215 *
V_10 -> V_5 -> V_41 -> V_216 / V_3 ;
if ( V_200 >= V_10 -> V_158 - V_201 ) {
struct V_9 * V_185 = V_10 -> V_185 ;
if ( F_138 ( V_10 -> V_68 + V_10 -> V_158 * V_3 , V_449 ) )
V_449 = V_10 -> V_68 + V_10 -> V_158 * V_3 ;
if ( ! V_10 -> V_208 && V_185 ) {
V_10 -> V_208 ++ ;
F_16 ( V_10 ) ;
F_16 ( V_185 ) ;
F_120 ( & V_10 -> V_34 ) ;
F_112 ( & V_185 -> V_34 ) ;
V_185 -> V_208 = 0 ;
F_120 ( & V_185 -> V_34 ) ;
F_146 ( V_185 , V_10 ) ;
F_133 ( V_185 ) ;
F_133 ( V_10 ) ;
goto V_420;
}
} else if ( F_138 ( V_10 -> V_68 + V_10 -> V_158 * V_3 - V_201 * V_3 , V_449 ) )
V_449 = V_10 -> V_68 + V_10 -> V_158 * V_3 - V_201 * V_3 ;
F_120 ( & V_10 -> V_34 ) ;
} else {
if ( F_138 ( V_10 -> V_68 + V_10 -> V_158 * V_3 , V_449 ) )
V_449 = V_10 -> V_68 + V_10 -> V_158 * V_3 ;
F_120 ( & V_10 -> V_34 ) ;
}
}
}
V_450 = F_308 ( V_449 ) ;
V_451 = V_449 ;
if ( F_138 ( V_450 , V_449 + V_457 ) )
V_451 = V_450 ;
if ( F_138 ( V_451 , V_13 + V_458 ) )
V_451 = V_13 + V_458 ;
F_35 ( V_254 L_27 ,
V_205 , V_449 , V_450 , V_451 ) ;
V_454 . V_184 = V_451 ;
F_309 ( & V_454 ) ;
F_120 ( & V_452 ) ;
F_124 () ;
}
static struct V_152 * F_310 ( struct V_105 * V_150 , struct V_105 * V_459 ,
struct V_152 * * V_375 )
{
struct V_152 * V_295 = NULL ;
* V_375 = NULL ;
if ( V_150 )
V_295 = F_311 ( V_150 ) ;
if ( V_459 ) {
if ( V_295 && F_312 ( V_459 , V_295 , sizeof( * V_295 ) ) )
* V_375 = V_295 ;
V_295 = F_311 ( V_459 ) ;
}
return V_295 ;
}
static int
F_313 ( struct V_79 * V_80 , struct V_87 * V_88 )
{
struct V_96 * V_96 = F_66 ( V_80 -> V_104 ) ;
struct V_460 * V_461 ;
struct V_105 * V_106 [ V_462 + 1 ] ;
struct V_152 * V_295 , * V_375 ;
int V_97 ;
V_97 = F_67 ( V_88 , sizeof( * V_461 ) , V_106 , V_462 , V_463 ) ;
if ( V_97 < 0 )
return V_97 ;
V_461 = F_55 ( V_88 ) ;
V_295 = F_310 ( V_106 [ V_464 ] , V_106 [ V_465 ] , & V_375 ) ;
if ( V_295 == NULL )
return - V_110 ;
return F_247 ( V_96 , V_461 -> V_466 , V_295 , V_461 -> V_467 ) ;
}
static int F_314 ( struct V_9 * V_10 , T_3 V_376 ,
T_1 V_158 , T_1 V_157 )
{
T_1 V_48 ;
T_5 V_184 ;
unsigned long V_377 ;
if ( ! V_157 || ( V_158 > V_157 ) )
return - V_110 ;
V_377 = F_137 ( V_157 , V_3 ) ;
if ( F_229 ( V_377 ) ) {
V_184 = F_231 ( V_377 * V_3 ) ;
V_157 = V_377 ;
V_48 = V_194 ;
} else {
V_184 = 0 ;
V_48 = 0 ;
V_376 |= V_186 ;
}
V_377 = F_137 ( V_158 , V_3 ) ;
if ( F_229 ( V_377 ) ) {
if ( V_377 == 0 )
V_376 |= V_233 ;
V_158 = V_377 ;
}
F_128 ( & V_10 -> V_34 ) ;
V_10 -> V_48 = ( V_10 -> V_48 & ~ ( V_233 | V_186 | V_429 | V_238 ) ) | V_376 ;
V_10 -> V_68 = V_13 ;
V_10 -> V_157 = V_157 ;
V_10 -> V_158 = V_158 ;
F_129 ( & V_10 -> V_34 ) ;
if ( ! ( V_10 -> V_48 & V_134 ) )
F_140 ( 0 , V_10 ) ;
F_216 ( & V_10 -> V_150 , V_10 -> V_175 , V_10 -> V_5 -> V_7 ,
V_184 , V_48 ) ;
F_237 ( 0 ) ;
return 0 ;
}
static int
F_315 ( struct V_79 * V_80 , struct V_87 * V_88 )
{
struct V_96 * V_96 = F_66 ( V_80 -> V_104 ) ;
struct V_460 * V_461 ;
struct V_105 * V_106 [ V_462 + 1 ] ;
struct V_152 * V_295 , * V_375 ;
struct V_9 * V_131 ;
struct V_6 * V_7 ;
T_1 V_157 = V_383 , V_468 = V_383 ;
T_3 V_376 ;
int V_97 ;
V_97 = F_67 ( V_88 , sizeof( * V_461 ) , V_106 , V_462 , V_463 ) ;
if ( V_97 < 0 )
return V_97 ;
V_461 = F_55 ( V_88 ) ;
V_295 = F_310 ( V_106 [ V_464 ] , V_106 [ V_465 ] , & V_375 ) ;
if ( V_295 == NULL )
return - V_110 ;
if ( V_106 [ V_469 ] ) {
struct V_470 * V_471 ;
V_471 = F_311 ( V_106 [ V_469 ] ) ;
V_157 = V_471 -> V_472 ;
V_468 = V_471 -> V_473 ;
} else {
V_468 = V_383 ;
V_157 = V_383 ;
}
V_7 = F_69 ( V_96 , V_461 -> V_466 ) ;
if ( V_7 == NULL )
return - V_166 ;
V_376 = V_461 -> V_376 & ( V_429 | V_238 ) ;
V_131 = F_178 ( V_96 , V_295 , V_7 , 1 ) ;
if ( V_131 == NULL ) {
return F_246 ( V_96 , V_461 -> V_466 , V_295 , V_375 ,
V_461 -> V_467 , V_376 ,
V_468 , V_157 ) ;
}
if ( V_88 -> V_474 & V_475 ||
! ( V_88 -> V_474 & V_476 ) )
V_97 = - V_171 ;
else
V_97 = F_314 ( V_131 , V_376 , V_468 , V_157 ) ;
F_133 ( V_131 ) ;
return V_97 ;
}
static void F_316 ( struct V_87 * V_88 , T_3 V_477 , T_3 V_48 ,
T_3 V_156 , int V_81 )
{
struct V_460 * V_461 ;
V_461 = F_55 ( V_88 ) ;
V_461 -> V_478 = V_92 ;
V_461 -> V_467 = V_477 ;
V_461 -> V_376 = V_48 ;
V_461 -> V_393 = V_156 ;
V_461 -> V_466 = V_81 ;
}
static int F_317 ( struct V_79 * V_80 , unsigned long V_1 ,
unsigned long V_68 , T_1 V_479 , T_1 V_329 )
{
struct V_470 V_471 ;
V_471 . V_1 = F_1 ( V_1 ) ;
V_471 . V_68 = F_1 ( V_68 ) ;
V_471 . V_473 = V_479 ;
V_471 . V_472 = V_329 ;
return F_318 ( V_80 , V_469 , sizeof( V_471 ) , & V_471 ) ;
}
static inline int F_319 ( int V_393 )
{
if ( V_393 & V_263 )
return V_395 ;
else if ( V_393 & V_260 )
return V_394 ;
else if ( V_393 & V_480 )
return V_481 ;
else
return V_482 ;
}
static inline int F_320 ( void )
{
return F_50 ( sizeof( struct V_460 ) )
+ F_51 ( 16 )
+ F_51 ( 16 )
+ F_51 ( sizeof( struct V_470 ) ) ;
}
static int F_321 ( struct V_79 * V_80 , struct V_9 * V_131 ,
T_1 V_84 , T_1 V_85 , int V_86 , unsigned int V_48 )
{
struct V_87 * V_88 ;
T_1 V_479 , V_329 ;
V_88 = F_54 ( V_80 , V_84 , V_85 , V_86 , sizeof( struct V_460 ) , V_48 ) ;
if ( V_88 == NULL )
return - V_90 ;
F_316 ( V_88 , V_131 -> V_175 , V_131 -> V_48 , F_319 ( V_131 -> V_156 ) ,
V_131 -> V_5 -> V_7 -> V_81 ) ;
if ( ! ( ( V_131 -> V_48 & V_186 ) &&
( V_131 -> V_158 == V_383 ) ) ) {
V_479 = V_131 -> V_158 ;
V_329 = V_131 -> V_157 ;
if ( V_479 != V_383 ) {
long V_483 = ( V_13 - V_131 -> V_68 ) / V_3 ;
if ( V_479 > V_483 )
V_479 -= V_483 ;
else
V_479 = 0 ;
if ( V_329 != V_383 ) {
if ( V_329 > V_483 )
V_329 -= V_483 ;
else
V_329 = 0 ;
}
}
} else {
V_479 = V_383 ;
V_329 = V_383 ;
}
if ( ! F_190 ( & V_131 -> V_154 ) ) {
if ( F_318 ( V_80 , V_465 , 16 , & V_131 -> V_150 ) < 0 ||
F_318 ( V_80 , V_464 , 16 , & V_131 -> V_154 ) < 0 )
goto error;
} else
if ( F_318 ( V_80 , V_464 , 16 , & V_131 -> V_150 ) < 0 )
goto error;
if ( F_317 ( V_80 , V_131 -> V_1 , V_131 -> V_68 , V_479 , V_329 ) < 0 )
goto error;
return F_57 ( V_80 , V_88 ) ;
error:
F_58 ( V_80 , V_88 ) ;
return - V_90 ;
}
static int F_322 ( struct V_79 * V_80 , struct V_484 * V_485 ,
T_1 V_84 , T_1 V_85 , int V_86 , T_14 V_48 )
{
struct V_87 * V_88 ;
T_3 V_156 = V_482 ;
int V_81 = V_485 -> V_5 -> V_7 -> V_81 ;
if ( F_149 ( & V_485 -> V_486 ) & V_480 )
V_156 = V_481 ;
V_88 = F_54 ( V_80 , V_84 , V_85 , V_86 , sizeof( struct V_460 ) , V_48 ) ;
if ( V_88 == NULL )
return - V_90 ;
F_316 ( V_88 , 128 , V_186 , V_156 , V_81 ) ;
if ( F_318 ( V_80 , V_487 , 16 , & V_485 -> V_486 ) < 0 ||
F_317 ( V_80 , V_485 -> V_488 , V_485 -> V_489 ,
V_383 , V_383 ) < 0 ) {
F_58 ( V_80 , V_88 ) ;
return - V_90 ;
}
return F_57 ( V_80 , V_88 ) ;
}
static int F_323 ( struct V_79 * V_80 , struct V_490 * V_491 ,
T_1 V_84 , T_1 V_85 , int V_86 , unsigned int V_48 )
{
struct V_87 * V_88 ;
T_3 V_156 = V_482 ;
int V_81 = V_491 -> V_492 -> V_7 -> V_81 ;
if ( F_149 ( & V_491 -> V_493 ) & V_480 )
V_156 = V_481 ;
V_88 = F_54 ( V_80 , V_84 , V_85 , V_86 , sizeof( struct V_460 ) , V_48 ) ;
if ( V_88 == NULL )
return - V_90 ;
F_316 ( V_88 , 128 , V_186 , V_156 , V_81 ) ;
if ( F_318 ( V_80 , V_494 , 16 , & V_491 -> V_493 ) < 0 ||
F_317 ( V_80 , V_491 -> V_495 , V_491 -> V_496 ,
V_383 , V_383 ) < 0 ) {
F_58 ( V_80 , V_88 ) ;
return - V_90 ;
}
return F_57 ( V_80 , V_88 ) ;
}
static int F_324 ( struct V_4 * V_5 , struct V_79 * V_80 ,
struct V_115 * V_116 , enum V_497 type ,
int V_498 , int * V_499 )
{
struct V_484 * V_485 ;
struct V_490 * V_491 ;
int V_97 = 1 ;
int V_500 = * V_499 ;
F_164 ( & V_5 -> V_34 ) ;
switch ( type ) {
case V_501 : {
struct V_9 * V_131 ;
F_81 (ifa, &idev->addr_list, if_list) {
if ( ++ V_500 < V_498 )
continue;
V_97 = F_321 ( V_80 , V_131 ,
F_70 ( V_116 -> V_80 ) . V_84 ,
V_116 -> V_88 -> V_114 ,
V_384 ,
V_128 ) ;
if ( V_97 <= 0 )
break;
F_77 ( V_116 , F_78 ( V_80 ) ) ;
}
break;
}
case V_502 :
for ( V_485 = V_5 -> V_503 ; V_485 ;
V_485 = V_485 -> V_449 , V_500 ++ ) {
if ( V_500 < V_498 )
continue;
V_97 = F_322 ( V_80 , V_485 ,
F_70 ( V_116 -> V_80 ) . V_84 ,
V_116 -> V_88 -> V_114 ,
V_504 ,
V_128 ) ;
if ( V_97 <= 0 )
break;
}
break;
case V_505 :
for ( V_491 = V_5 -> V_506 ; V_491 ;
V_491 = V_491 -> V_507 , V_500 ++ ) {
if ( V_500 < V_498 )
continue;
V_97 = F_323 ( V_80 , V_491 ,
F_70 ( V_116 -> V_80 ) . V_84 ,
V_116 -> V_88 -> V_114 ,
V_508 ,
V_128 ) ;
if ( V_97 <= 0 )
break;
}
break;
default:
break;
}
F_169 ( & V_5 -> V_34 ) ;
* V_499 = V_500 ;
return V_97 ;
}
static int F_325 ( struct V_79 * V_80 , struct V_115 * V_116 ,
enum V_497 type )
{
struct V_96 * V_96 = F_66 ( V_80 -> V_104 ) ;
int V_117 , V_118 ;
int V_119 , V_500 ;
int V_120 , V_498 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_121 * V_122 ;
V_118 = V_116 -> args [ 0 ] ;
V_120 = V_119 = V_116 -> args [ 1 ] ;
V_498 = V_500 = V_116 -> args [ 2 ] ;
F_73 () ;
V_116 -> V_85 = F_74 ( & V_96 -> V_17 . V_125 ) ^ V_96 -> V_126 ;
for ( V_117 = V_118 ; V_117 < V_123 ; V_117 ++ , V_120 = 0 ) {
V_119 = 0 ;
V_122 = & V_96 -> V_124 [ V_117 ] ;
F_75 (dev, head, index_hlist) {
if ( V_119 < V_120 )
goto V_127;
if ( V_117 > V_118 || V_119 > V_120 )
V_498 = 0 ;
V_500 = 0 ;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
goto V_127;
if ( F_324 ( V_5 , V_80 , V_116 , type ,
V_498 , & V_500 ) <= 0 )
goto V_129;
V_127:
V_119 ++ ;
}
}
V_129:
F_76 () ;
V_116 -> args [ 0 ] = V_117 ;
V_116 -> args [ 1 ] = V_119 ;
V_116 -> args [ 2 ] = V_500 ;
return V_80 -> V_130 ;
}
static int F_326 ( struct V_79 * V_80 , struct V_115 * V_116 )
{
enum V_497 type = V_501 ;
return F_325 ( V_80 , V_116 , type ) ;
}
static int F_327 ( struct V_79 * V_80 , struct V_115 * V_116 )
{
enum V_497 type = V_502 ;
return F_325 ( V_80 , V_116 , type ) ;
}
static int F_328 ( struct V_79 * V_80 , struct V_115 * V_116 )
{
enum V_497 type = V_505 ;
return F_325 ( V_80 , V_116 , type ) ;
}
static int F_329 ( struct V_79 * V_103 , struct V_87 * V_88 )
{
struct V_96 * V_96 = F_66 ( V_103 -> V_104 ) ;
struct V_460 * V_461 ;
struct V_105 * V_106 [ V_462 + 1 ] ;
struct V_152 * V_150 = NULL , * V_509 ;
struct V_6 * V_7 = NULL ;
struct V_9 * V_131 ;
struct V_79 * V_80 ;
int V_97 ;
V_97 = F_67 ( V_88 , sizeof( * V_461 ) , V_106 , V_462 , V_463 ) ;
if ( V_97 < 0 )
goto V_100;
V_150 = F_310 ( V_106 [ V_464 ] , V_106 [ V_465 ] , & V_509 ) ;
if ( V_150 == NULL ) {
V_97 = - V_110 ;
goto V_100;
}
V_461 = F_55 ( V_88 ) ;
if ( V_461 -> V_466 )
V_7 = F_69 ( V_96 , V_461 -> V_466 ) ;
V_131 = F_178 ( V_96 , V_150 , V_7 , 1 ) ;
if ( ! V_131 ) {
V_97 = - V_165 ;
goto V_100;
}
V_80 = F_60 ( F_320 () , V_25 ) ;
if ( ! V_80 ) {
V_97 = - V_98 ;
goto V_510;
}
V_97 = F_321 ( V_80 , V_131 , F_70 ( V_103 ) . V_84 ,
V_88 -> V_114 , V_384 , 0 ) ;
if ( V_97 < 0 ) {
F_61 ( V_97 == - V_90 ) ;
F_62 ( V_80 ) ;
goto V_510;
}
V_97 = F_71 ( V_80 , V_96 , F_70 ( V_103 ) . V_84 ) ;
V_510:
F_133 ( V_131 ) ;
V_100:
return V_97 ;
}
static void F_330 ( int V_86 , struct V_9 * V_131 )
{
struct V_79 * V_80 ;
struct V_96 * V_96 = F_31 ( V_131 -> V_5 -> V_7 ) ;
int V_97 = - V_98 ;
V_80 = F_60 ( F_320 () , V_99 ) ;
if ( V_80 == NULL )
goto V_100;
V_97 = F_321 ( V_80 , V_131 , 0 , 0 , V_86 , 0 ) ;
if ( V_97 < 0 ) {
F_61 ( V_97 == - V_90 ) ;
F_62 ( V_80 ) ;
goto V_100;
}
F_63 ( V_80 , V_96 , 0 , V_511 , NULL , V_99 ) ;
return;
V_100:
if ( V_97 < 0 )
F_64 ( V_96 , V_511 , V_97 ) ;
}
static inline void F_331 ( struct V_82 * V_37 ,
T_2 * V_512 , int V_513 )
{
F_332 ( V_513 < ( V_514 * 4 ) ) ;
memset ( V_512 , 0 , V_513 ) ;
V_512 [ V_515 ] = V_37 -> V_43 ;
V_512 [ V_516 ] = V_37 -> V_517 ;
V_512 [ V_518 ] = V_37 -> V_39 ;
V_512 [ V_519 ] = V_37 -> V_520 ;
V_512 [ V_521 ] = V_37 -> V_522 ;
V_512 [ V_523 ] = V_37 -> V_335 ;
V_512 [ V_524 ] = V_37 -> V_215 ;
V_512 [ V_525 ] = V_37 -> V_56 ;
V_512 [ V_526 ] =
F_333 ( V_37 -> V_426 ) ;
V_512 [ V_527 ] =
F_333 ( V_37 -> V_425 ) ;
V_512 [ V_528 ] = V_37 -> V_529 ;
V_512 [ V_530 ] =
F_333 ( V_37 -> V_531 ) ;
V_512 [ V_532 ] =
F_333 ( V_37 -> V_533 ) ;
V_512 [ V_534 ] = V_37 -> V_63 ;
V_512 [ V_535 ] = V_37 -> V_212 ;
V_512 [ V_536 ] = V_37 -> V_213 ;
V_512 [ V_537 ] = V_37 -> V_209 ;
V_512 [ V_538 ] = V_37 -> V_214 ;
V_512 [ V_539 ] = V_37 -> V_339 ;
V_512 [ V_540 ] = V_37 -> V_541 ;
V_512 [ V_542 ] = V_37 -> V_543 ;
#ifdef F_334
V_512 [ V_544 ] = V_37 -> V_545 ;
V_512 [ V_546 ] =
F_333 ( V_37 -> V_547 ) ;
#ifdef F_335
V_512 [ V_548 ] = V_37 -> V_549 ;
#endif
#endif
V_512 [ V_550 ] = V_37 -> V_551 ;
V_512 [ V_552 ] = V_37 -> V_553 ;
#ifdef F_232
V_512 [ V_554 ] = V_37 -> V_340 ;
#endif
#ifdef F_52
V_512 [ V_555 ] = V_37 -> V_95 ;
#endif
V_512 [ V_556 ] = V_37 -> V_168 ;
V_512 [ V_557 ] = V_37 -> V_51 ;
V_512 [ V_558 ] = V_37 -> V_559 ;
V_512 [ V_560 ] = V_37 -> V_561 ;
V_512 [ V_562 ] = V_37 -> V_563 ;
}
static inline T_15 F_336 ( void )
{
return F_51 ( 4 )
+ F_51 ( sizeof( struct V_564 ) )
+ F_51 ( V_514 * 4 )
+ F_51 ( V_565 * 8 )
+ F_51 ( V_566 * 8 )
+ F_51 ( sizeof( struct V_152 ) ) ;
}
static inline T_15 F_337 ( void )
{
return F_50 ( sizeof( struct V_567 ) )
+ F_51 ( V_568 )
+ F_51 ( V_569 )
+ F_51 ( 4 )
+ F_51 ( 4 )
+ F_51 ( F_336 () ) ;
}
static inline void F_338 ( T_16 * V_16 , T_17 * V_570 ,
int V_571 , int V_513 )
{
int V_14 ;
int V_572 = V_513 - sizeof( T_16 ) * V_571 ;
F_332 ( V_572 < 0 ) ;
F_339 ( V_571 , & V_16 [ 0 ] ) ;
for ( V_14 = 1 ; V_14 < V_571 ; V_14 ++ )
F_339 ( F_340 ( & V_570 [ V_14 ] ) , & V_16 [ V_14 ] ) ;
memset ( & V_16 [ V_571 ] , 0 , V_572 ) ;
}
static inline void F_341 ( T_16 * V_16 , void V_15 * * V_570 ,
int V_571 , int V_513 , T_15 V_573 )
{
int V_14 ;
int V_572 = V_513 - sizeof( T_16 ) * V_571 ;
F_332 ( V_572 < 0 ) ;
F_339 ( V_571 , & V_16 [ 0 ] ) ;
for ( V_14 = 1 ; V_14 < V_571 ; V_14 ++ )
F_339 ( F_342 ( V_570 , V_14 , V_573 ) , & V_16 [ V_14 ] ) ;
memset ( & V_16 [ V_571 ] , 0 , V_572 ) ;
}
static void F_343 ( T_16 * V_16 , struct V_4 * V_5 , int V_574 ,
int V_513 )
{
switch ( V_574 ) {
case V_575 :
F_341 ( V_16 , ( void V_15 * * ) V_5 -> V_16 . V_17 ,
V_565 , V_513 , F_344 ( struct V_18 , V_21 ) ) ;
break;
case V_576 :
F_338 ( V_16 , V_5 -> V_16 . V_23 -> V_577 , V_566 , V_513 ) ;
break;
}
}
static int F_345 ( struct V_79 * V_80 , struct V_4 * V_5 )
{
struct V_105 * V_578 ;
struct V_564 V_471 ;
if ( F_346 ( V_80 , V_579 , V_5 -> V_66 ) )
goto V_94;
V_471 . V_580 = V_581 ;
V_471 . V_68 = F_1 ( V_5 -> V_68 ) ;
V_471 . V_582 = F_333 ( V_5 -> V_41 -> V_582 ) ;
V_471 . V_216 = F_333 ( V_5 -> V_41 -> V_216 ) ;
if ( F_318 ( V_80 , V_583 , sizeof( V_471 ) , & V_471 ) )
goto V_94;
V_578 = F_347 ( V_80 , V_584 , V_514 * sizeof( V_585 ) ) ;
if ( V_578 == NULL )
goto V_94;
F_331 ( & V_5 -> V_37 , F_311 ( V_578 ) , F_348 ( V_578 ) ) ;
V_578 = F_347 ( V_80 , V_575 , V_565 * sizeof( T_16 ) ) ;
if ( V_578 == NULL )
goto V_94;
F_343 ( F_311 ( V_578 ) , V_5 , V_575 , F_348 ( V_578 ) ) ;
V_578 = F_347 ( V_80 , V_576 , V_566 * sizeof( T_16 ) ) ;
if ( V_578 == NULL )
goto V_94;
F_343 ( F_311 ( V_578 ) , V_5 , V_576 , F_348 ( V_578 ) ) ;
V_578 = F_347 ( V_80 , V_586 , sizeof( struct V_152 ) ) ;
if ( V_578 == NULL )
goto V_94;
F_164 ( & V_5 -> V_34 ) ;
memcpy ( F_311 ( V_578 ) , V_5 -> V_64 . V_206 , F_348 ( V_578 ) ) ;
F_169 ( & V_5 -> V_34 ) ;
return 0 ;
V_94:
return - V_90 ;
}
static T_15 F_349 ( const struct V_6 * V_7 )
{
if ( ! F_47 ( V_7 ) )
return 0 ;
return F_336 () ;
}
static int F_350 ( struct V_79 * V_80 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
return - V_587 ;
if ( F_345 ( V_80 , V_5 ) < 0 )
return - V_90 ;
return 0 ;
}
static int F_351 ( struct V_4 * V_5 , struct V_152 * V_64 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 = V_5 -> V_7 ;
bool V_588 = false ;
struct V_152 V_589 ;
if ( V_64 == NULL )
return - V_110 ;
if ( F_190 ( V_64 ) )
return - V_110 ;
if ( V_7 -> V_48 & ( V_50 | V_49 ) )
return - V_110 ;
if ( ! F_279 ( V_5 ) )
return - V_110 ;
if ( V_5 -> V_37 . V_56 <= 0 )
return - V_110 ;
F_131 ( & V_5 -> V_34 ) ;
F_352 ( sizeof( V_64 -> V_206 ) != 16 ) ;
memcpy ( V_5 -> V_64 . V_206 + 8 , V_64 -> V_206 + 8 , 8 ) ;
F_139 ( & V_5 -> V_34 ) ;
if ( ! V_5 -> V_47 && ( V_5 -> V_66 & V_67 ) &&
! F_171 ( V_7 , & V_589 , V_134 |
V_217 ) ) {
F_280 ( V_7 , & V_589 , & V_73 ) ;
V_588 = true ;
}
F_131 ( & V_5 -> V_34 ) ;
if ( V_588 ) {
V_5 -> V_66 |= V_421 ;
V_5 -> V_423 = 1 ;
F_11 ( V_5 , V_5 -> V_37 . V_426 ) ;
}
F_81 (ifp, &idev->addr_list, if_list) {
F_112 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_176 ) {
V_10 -> V_157 = 0 ;
V_10 -> V_158 = 0 ;
}
F_120 ( & V_10 -> V_34 ) ;
}
F_139 ( & V_5 -> V_34 ) ;
F_237 ( 0 ) ;
return 0 ;
}
static int F_353 ( struct V_6 * V_7 , const struct V_105 * V_578 )
{
int V_97 = - V_110 ;
struct V_4 * V_5 = F_47 ( V_7 ) ;
struct V_105 * V_106 [ V_590 + 1 ] ;
if ( ! V_5 )
return - V_591 ;
if ( F_354 ( V_106 , V_590 , V_578 , NULL ) < 0 )
F_355 () ;
if ( V_106 [ V_586 ] )
V_97 = F_351 ( V_5 , F_311 ( V_106 [ V_586 ] ) ) ;
return V_97 ;
}
static int F_356 ( struct V_79 * V_80 , struct V_4 * V_5 ,
T_1 V_84 , T_1 V_85 , int V_86 , unsigned int V_48 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_567 * V_592 ;
struct V_87 * V_88 ;
void * V_593 ;
V_88 = F_54 ( V_80 , V_84 , V_85 , V_86 , sizeof( * V_592 ) , V_48 ) ;
if ( V_88 == NULL )
return - V_90 ;
V_592 = F_55 ( V_88 ) ;
V_592 -> V_594 = V_92 ;
V_592 -> V_595 = 0 ;
V_592 -> V_596 = V_7 -> type ;
V_592 -> V_597 = V_7 -> V_81 ;
V_592 -> V_598 = F_357 ( V_7 ) ;
V_592 -> V_599 = 0 ;
if ( F_358 ( V_80 , V_600 , V_7 -> V_46 ) ||
( V_7 -> V_273 &&
F_318 ( V_80 , V_601 , V_7 -> V_273 , V_7 -> V_275 ) ) ||
F_346 ( V_80 , V_602 , V_7 -> V_32 ) ||
( V_7 -> V_81 != V_7 -> V_603 &&
F_346 ( V_80 , V_604 , V_7 -> V_603 ) ) )
goto V_94;
V_593 = F_359 ( V_80 , V_605 ) ;
if ( V_593 == NULL )
goto V_94;
if ( F_345 ( V_80 , V_5 ) < 0 )
goto V_94;
F_360 ( V_80 , V_593 ) ;
return F_57 ( V_80 , V_88 ) ;
V_94:
F_58 ( V_80 , V_88 ) ;
return - V_90 ;
}
static int F_361 ( struct V_79 * V_80 , struct V_115 * V_116 )
{
struct V_96 * V_96 = F_66 ( V_80 -> V_104 ) ;
int V_117 , V_118 ;
int V_119 = 0 , V_120 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_121 * V_122 ;
V_118 = V_116 -> args [ 0 ] ;
V_120 = V_116 -> args [ 1 ] ;
F_73 () ;
for ( V_117 = V_118 ; V_117 < V_123 ; V_117 ++ , V_120 = 0 ) {
V_119 = 0 ;
V_122 = & V_96 -> V_124 [ V_117 ] ;
F_75 (dev, head, index_hlist) {
if ( V_119 < V_120 )
goto V_127;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
goto V_127;
if ( F_356 ( V_80 , V_5 ,
F_70 ( V_116 -> V_80 ) . V_84 ,
V_116 -> V_88 -> V_114 ,
V_411 , V_128 ) <= 0 )
goto V_172;
V_127:
V_119 ++ ;
}
}
V_172:
F_76 () ;
V_116 -> args [ 1 ] = V_119 ;
V_116 -> args [ 0 ] = V_117 ;
return V_80 -> V_130 ;
}
void F_266 ( int V_86 , struct V_4 * V_5 )
{
struct V_79 * V_80 ;
struct V_96 * V_96 = F_31 ( V_5 -> V_7 ) ;
int V_97 = - V_98 ;
V_80 = F_60 ( F_337 () , V_99 ) ;
if ( V_80 == NULL )
goto V_100;
V_97 = F_356 ( V_80 , V_5 , 0 , 0 , V_86 , 0 ) ;
if ( V_97 < 0 ) {
F_61 ( V_97 == - V_90 ) ;
F_62 ( V_80 ) ;
goto V_100;
}
F_63 ( V_80 , V_96 , 0 , V_606 , NULL , V_99 ) ;
return;
V_100:
if ( V_97 < 0 )
F_64 ( V_96 , V_606 , V_97 ) ;
}
static inline T_15 F_362 ( void )
{
return F_50 ( sizeof( struct V_607 ) )
+ F_51 ( sizeof( struct V_152 ) )
+ F_51 ( sizeof( struct V_608 ) ) ;
}
static int F_363 ( struct V_79 * V_80 , struct V_4 * V_5 ,
struct V_326 * V_327 , T_1 V_84 , T_1 V_85 ,
int V_86 , unsigned int V_48 )
{
struct V_607 * V_609 ;
struct V_87 * V_88 ;
struct V_608 V_471 ;
V_88 = F_54 ( V_80 , V_84 , V_85 , V_86 , sizeof( * V_609 ) , V_48 ) ;
if ( V_88 == NULL )
return - V_90 ;
V_609 = F_55 ( V_88 ) ;
V_609 -> V_610 = V_92 ;
V_609 -> V_611 = 0 ;
V_609 -> V_612 = 0 ;
V_609 -> V_613 = V_5 -> V_7 -> V_81 ;
V_609 -> V_175 = V_327 -> V_175 ;
V_609 -> V_614 = V_327 -> type ;
V_609 -> V_615 = 0 ;
V_609 -> V_616 = 0 ;
if ( V_327 -> V_183 )
V_609 -> V_616 |= V_617 ;
if ( V_327 -> V_335 )
V_609 -> V_616 |= V_618 ;
if ( F_318 ( V_80 , V_619 , sizeof( V_327 -> V_190 ) , & V_327 -> V_190 ) )
goto V_94;
V_471 . V_620 = F_225 ( V_327 -> V_330 ) ;
V_471 . V_621 = F_225 ( V_327 -> V_329 ) ;
if ( F_318 ( V_80 , V_622 , sizeof( V_471 ) , & V_471 ) )
goto V_94;
return F_57 ( V_80 , V_88 ) ;
V_94:
F_58 ( V_80 , V_88 ) ;
return - V_90 ;
}
static void F_238 ( int V_86 , struct V_4 * V_5 ,
struct V_326 * V_327 )
{
struct V_79 * V_80 ;
struct V_96 * V_96 = F_31 ( V_5 -> V_7 ) ;
int V_97 = - V_98 ;
V_80 = F_60 ( F_362 () , V_99 ) ;
if ( V_80 == NULL )
goto V_100;
V_97 = F_363 ( V_80 , V_5 , V_327 , 0 , 0 , V_86 , 0 ) ;
if ( V_97 < 0 ) {
F_61 ( V_97 == - V_90 ) ;
F_62 ( V_80 ) ;
goto V_100;
}
F_63 ( V_80 , V_96 , 0 , V_623 , NULL , V_99 ) ;
return;
V_100:
if ( V_97 < 0 )
F_64 ( V_96 , V_623 , V_97 ) ;
}
static void F_276 ( int V_86 , struct V_9 * V_10 )
{
struct V_96 * V_96 = F_31 ( V_10 -> V_5 -> V_7 ) ;
F_330 ( V_86 ? : V_384 , V_10 ) ;
switch ( V_86 ) {
case V_384 :
if ( ! ( V_10 -> V_146 -> V_624 ) )
F_255 ( V_10 -> V_146 ) ;
if ( V_10 -> V_5 -> V_37 . V_43 )
F_82 ( V_10 ) ;
if ( ! F_190 ( & V_10 -> V_154 ) )
F_216 ( & V_10 -> V_154 , 128 ,
V_10 -> V_5 -> V_7 , 0 , 0 ) ;
break;
case V_188 :
if ( V_10 -> V_5 -> V_37 . V_43 )
F_83 ( V_10 ) ;
F_188 ( V_10 -> V_5 , & V_10 -> V_150 ) ;
if ( ! F_190 ( & V_10 -> V_154 ) ) {
struct V_159 * V_146 ;
struct V_6 * V_7 = V_10 -> V_5 -> V_7 ;
V_146 = F_364 ( F_31 ( V_7 ) , & V_10 -> V_154 , NULL ,
V_7 -> V_81 , 1 ) ;
if ( V_146 ) {
F_220 ( & V_146 -> V_223 ) ;
if ( F_143 ( V_146 ) )
F_365 ( & V_146 -> V_223 ) ;
}
}
F_220 ( & V_10 -> V_146 -> V_223 ) ;
if ( F_143 ( V_10 -> V_146 ) )
F_365 ( & V_10 -> V_146 -> V_223 ) ;
break;
}
F_366 ( & V_96 -> V_17 . V_125 ) ;
F_367 ( V_96 ) ;
}
static void F_140 ( int V_86 , struct V_9 * V_10 )
{
F_111 () ;
if ( F_125 ( V_10 -> V_5 -> V_47 == 0 ) )
F_276 ( V_86 , V_10 ) ;
F_124 () ;
}
static
int F_368 ( struct V_137 * V_625 , int V_626 ,
void T_6 * V_627 , T_15 * V_628 , T_9 * V_629 )
{
int * V_630 = V_625 -> V_294 ;
int V_631 = * V_630 ;
T_9 V_435 = * V_629 ;
struct V_137 V_632 ;
int V_203 ;
V_632 = * V_625 ;
V_632 . V_294 = & V_631 ;
V_203 = F_369 ( & V_632 , V_626 , V_627 , V_628 , V_629 ) ;
if ( V_626 )
V_203 = F_86 ( V_625 , V_630 , V_631 ) ;
if ( V_203 )
* V_629 = V_435 ;
return V_203 ;
}
static void F_370 ( struct V_4 * V_5 )
{
struct V_633 V_634 ;
if ( ! V_5 || ! V_5 -> V_7 )
return;
F_371 ( & V_634 , V_5 -> V_7 ) ;
if ( V_5 -> V_37 . V_168 )
F_261 ( NULL , V_189 , & V_634 ) ;
else
F_261 ( NULL , V_180 , & V_634 ) ;
}
static void F_372 ( struct V_96 * V_96 , T_2 V_135 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_73 () ;
F_163 (net, dev) {
V_5 = F_47 ( V_7 ) ;
if ( V_5 ) {
int V_136 = ( ! V_5 -> V_37 . V_168 ) ^ ( ! V_135 ) ;
V_5 -> V_37 . V_168 = V_135 ;
if ( V_136 )
F_370 ( V_5 ) ;
}
}
F_76 () ;
}
static int F_373 ( struct V_137 * V_138 , int * V_139 , int V_135 )
{
struct V_96 * V_96 ;
int V_140 ;
if ( ! F_87 () )
return F_88 () ;
V_96 = (struct V_96 * ) V_138 -> V_141 ;
V_140 = * V_139 ;
* V_139 = V_135 ;
if ( V_139 == & V_96 -> V_17 . V_38 -> V_168 ) {
F_89 () ;
return 0 ;
}
if ( V_139 == & V_96 -> V_17 . V_112 -> V_168 ) {
V_96 -> V_17 . V_38 -> V_168 = V_135 ;
F_372 ( V_96 , V_135 ) ;
} else if ( ( ! V_135 ) ^ ( ! V_140 ) )
F_370 ( (struct V_4 * ) V_138 -> V_142 ) ;
F_89 () ;
return 0 ;
}
static
int F_374 ( struct V_137 * V_625 , int V_626 ,
void T_6 * V_627 , T_15 * V_628 , T_9 * V_629 )
{
int * V_630 = V_625 -> V_294 ;
int V_631 = * V_630 ;
T_9 V_435 = * V_629 ;
struct V_137 V_632 ;
int V_203 ;
V_632 = * V_625 ;
V_632 . V_294 = & V_631 ;
V_203 = F_369 ( & V_632 , V_626 , V_627 , V_628 , V_629 ) ;
if ( V_626 )
V_203 = F_373 ( V_625 , V_630 , V_631 ) ;
if ( V_203 )
* V_629 = V_435 ;
return V_203 ;
}
static int F_375 ( struct V_96 * V_96 , char * V_635 ,
struct V_4 * V_5 , struct V_82 * V_139 )
{
int V_14 ;
struct V_636 * V_637 ;
char V_638 [ sizeof( L_28 ) + V_568 ] ;
V_637 = F_376 ( & V_639 , sizeof( * V_637 ) , V_25 ) ;
if ( V_637 == NULL )
goto V_172;
for ( V_14 = 0 ; V_637 -> V_640 [ V_14 ] . V_294 ; V_14 ++ ) {
V_637 -> V_640 [ V_14 ] . V_294 += ( char * ) V_139 - ( char * ) & V_82 ;
V_637 -> V_640 [ V_14 ] . V_142 = V_5 ;
V_637 -> V_640 [ V_14 ] . V_141 = V_96 ;
}
snprintf ( V_638 , sizeof( V_638 ) , L_29 , V_635 ) ;
V_637 -> V_641 = F_377 ( V_96 , V_638 , V_637 -> V_640 ) ;
if ( V_637 -> V_641 == NULL )
goto free;
V_139 -> V_40 = V_637 ;
return 0 ;
free:
F_24 ( V_637 ) ;
V_172:
return - V_98 ;
}
static void F_378 ( struct V_82 * V_139 )
{
struct V_636 * V_637 ;
if ( V_139 -> V_40 == NULL )
return;
V_637 = V_139 -> V_40 ;
V_139 -> V_40 = NULL ;
F_379 ( V_637 -> V_641 ) ;
F_24 ( V_637 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_380 ( V_5 -> V_7 , V_5 -> V_41 , L_30 ,
& V_642 ) ;
F_375 ( F_31 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_46 ,
V_5 , & V_5 -> V_37 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_378 ( & V_5 -> V_37 ) ;
F_381 ( V_5 -> V_41 ) ;
}
static int T_11 F_382 ( struct V_96 * V_96 )
{
int V_97 = - V_30 ;
struct V_82 * V_643 , * V_644 ;
V_643 = F_376 ( & V_82 , sizeof( V_82 ) , V_25 ) ;
if ( V_643 == NULL )
goto V_645;
V_644 = F_376 ( & V_646 , sizeof( V_646 ) , V_25 ) ;
if ( V_644 == NULL )
goto V_647;
V_644 -> V_335 = V_648 . V_335 ;
V_644 -> V_168 = V_648 . V_168 ;
V_96 -> V_17 . V_112 = V_643 ;
V_96 -> V_17 . V_38 = V_644 ;
#ifdef F_383
V_97 = F_375 ( V_96 , L_31 , NULL , V_643 ) ;
if ( V_97 < 0 )
goto V_649;
V_97 = F_375 ( V_96 , L_32 , NULL , V_644 ) ;
if ( V_97 < 0 )
goto V_650;
#endif
return 0 ;
#ifdef F_383
V_650:
F_378 ( V_643 ) ;
V_649:
F_24 ( V_644 ) ;
#endif
V_647:
F_24 ( V_643 ) ;
V_645:
return V_97 ;
}
static void T_12 F_384 ( struct V_96 * V_96 )
{
#ifdef F_383
F_378 ( V_96 -> V_17 . V_38 ) ;
F_378 ( V_96 -> V_17 . V_112 ) ;
#endif
if ( ! F_174 ( V_96 , & V_651 ) ) {
F_24 ( V_96 -> V_17 . V_38 ) ;
F_24 ( V_96 -> V_17 . V_112 ) ;
}
}
int T_13 F_385 ( void )
{
int V_14 , V_97 ;
V_97 = F_386 () ;
if ( V_97 < 0 ) {
F_387 ( L_33 ,
V_45 , V_97 ) ;
goto V_172;
}
V_97 = F_304 ( & V_652 ) ;
if ( V_97 < 0 )
goto V_653;
F_240 () ;
if ( ! F_26 ( V_651 . V_654 ) )
V_97 = - V_30 ;
F_89 () ;
if ( V_97 )
goto V_655;
for ( V_14 = 0 ; V_14 < V_419 ; V_14 ++ )
F_388 ( & V_177 [ V_14 ] ) ;
F_389 ( & V_656 ) ;
F_237 ( 0 ) ;
V_97 = F_390 ( & V_657 ) ;
if ( V_97 < 0 )
goto V_658;
V_97 = F_391 ( V_659 , V_660 , NULL , F_361 ,
NULL ) ;
if ( V_97 < 0 )
goto V_100;
F_391 ( V_659 , V_384 , F_315 , NULL , NULL ) ;
F_391 ( V_659 , V_188 , F_313 , NULL , NULL ) ;
F_391 ( V_659 , V_661 , F_329 ,
F_326 , NULL ) ;
F_391 ( V_659 , V_504 , NULL ,
F_327 , NULL ) ;
F_391 ( V_659 , V_508 , NULL ,
F_328 , NULL ) ;
F_391 ( V_659 , V_662 , F_65 ,
F_72 , NULL ) ;
F_392 () ;
return 0 ;
V_100:
F_393 ( & V_657 ) ;
V_658:
F_394 ( & V_656 ) ;
V_655:
F_306 ( & V_652 ) ;
V_653:
F_395 () ;
V_172:
return V_97 ;
}
void F_396 ( void )
{
struct V_6 * V_7 ;
int V_14 ;
F_394 ( & V_656 ) ;
F_306 ( & V_652 ) ;
F_395 () ;
F_240 () ;
F_397 ( & V_657 ) ;
F_85 (&init_net, dev) {
if ( F_47 ( V_7 ) == NULL )
continue;
F_267 ( V_7 , 1 ) ;
}
F_267 ( V_651 . V_654 , 2 ) ;
F_128 ( & V_170 ) ;
for ( V_14 = 0 ; V_14 < V_419 ; V_14 ++ )
F_61 ( ! F_398 ( & V_177 [ V_14 ] ) ) ;
F_129 ( & V_170 ) ;
F_7 ( & V_454 ) ;
F_89 () ;
}
