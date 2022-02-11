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
static inline int F_6 ( const struct V_8 * V_9 )
{
return ( V_9 -> V_10 & ( V_11 | V_12 ) ) == 0 ;
}
static void F_7 ( struct V_13 * V_14 )
{
if ( F_8 ( & V_14 -> V_15 ) )
F_9 ( V_14 ) ;
}
static void F_10 ( struct V_13 * V_14 ,
enum V_16 V_17 ,
unsigned long V_18 )
{
if ( ! F_8 ( & V_14 -> V_15 ) )
F_11 ( V_14 ) ;
switch ( V_17 ) {
case V_19 :
V_14 -> V_15 . V_20 = V_21 ;
break;
case V_22 :
V_14 -> V_15 . V_20 = V_23 ;
break;
default:
break;
}
V_14 -> V_15 . V_24 = V_25 + V_18 ;
F_12 ( & V_14 -> V_15 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
if ( F_14 ( ( void V_26 * * ) V_5 -> V_27 . V_28 ,
sizeof( struct V_29 ) ,
F_15 ( struct V_29 ) ) < 0 )
goto V_30;
V_5 -> V_27 . V_31 = F_16 ( sizeof( struct V_32 ) ,
V_33 ) ;
if ( ! V_5 -> V_27 . V_31 )
goto V_34;
V_5 -> V_27 . V_35 = F_16 ( sizeof( struct V_36 ) ,
V_33 ) ;
if ( ! V_5 -> V_27 . V_35 )
goto V_37;
return 0 ;
V_37:
F_17 ( V_5 -> V_27 . V_31 ) ;
V_34:
F_18 ( ( void V_26 * * ) V_5 -> V_27 . V_28 ) ;
V_30:
return - V_38 ;
}
static void F_19 ( struct V_4 * V_5 )
{
F_17 ( V_5 -> V_27 . V_35 ) ;
F_17 ( V_5 -> V_27 . V_31 ) ;
F_18 ( ( void V_26 * * ) V_5 -> V_27 . V_28 ) ;
}
void F_20 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
F_21 ( ! F_22 ( & V_5 -> V_39 ) ) ;
F_21 ( V_5 -> V_40 != NULL ) ;
#ifdef F_23
F_24 ( V_41 L_1 , V_7 ? V_7 -> V_42 : L_2 ) ;
#endif
F_25 ( V_7 ) ;
if ( ! V_5 -> V_43 ) {
F_26 ( L_3 , V_5 ) ;
return;
}
F_19 ( V_5 ) ;
F_27 ( V_5 , V_44 ) ;
}
static struct V_4 * F_28 ( struct V_6 * V_7 )
{
struct V_4 * V_45 ;
F_29 () ;
if ( V_7 -> V_46 < V_47 )
return NULL ;
V_45 = F_16 ( sizeof( struct V_4 ) , V_33 ) ;
if ( V_45 == NULL )
return NULL ;
F_30 ( & V_45 -> V_48 ) ;
V_45 -> V_7 = V_7 ;
F_31 ( & V_45 -> V_39 ) ;
memcpy ( & V_45 -> V_49 , F_32 ( V_7 ) -> V_28 . V_50 , sizeof( V_45 -> V_49 ) ) ;
V_45 -> V_49 . V_51 = V_7 -> V_46 ;
V_45 -> V_49 . V_52 = NULL ;
V_45 -> V_53 = F_33 ( V_7 , & V_54 ) ;
if ( V_45 -> V_53 == NULL ) {
F_17 ( V_45 ) ;
return NULL ;
}
if ( V_45 -> V_49 . V_55 )
F_34 ( V_7 ) ;
F_35 ( V_7 ) ;
if ( F_13 ( V_45 ) < 0 ) {
F_36 ( ( V_56
L_4 ,
V_57 , V_7 -> V_42 ) ) ;
F_37 ( & V_54 , V_45 -> V_53 ) ;
V_45 -> V_43 = 1 ;
F_20 ( V_45 ) ;
return NULL ;
}
if ( F_38 ( V_45 ) < 0 ) {
F_36 ( ( V_56
L_5 ,
V_57 , V_7 -> V_42 ) ) ;
F_37 ( & V_54 , V_45 -> V_53 ) ;
V_45 -> V_43 = 1 ;
F_20 ( V_45 ) ;
return NULL ;
}
F_39 ( V_45 ) ;
if ( V_7 -> V_58 & ( V_59 | V_60 ) )
V_45 -> V_49 . V_61 = - 1 ;
#if F_40 ( V_62 ) || F_40 ( V_63 )
if ( V_7 -> type == V_64 && ( V_7 -> V_65 & V_66 ) ) {
F_24 ( V_67
L_6 ,
V_7 -> V_42 ) ;
V_45 -> V_49 . V_68 = 0 ;
}
#endif
#ifdef F_41
F_31 ( & V_45 -> V_69 ) ;
F_42 ( & V_45 -> V_70 , V_71 , ( unsigned long ) V_45 ) ;
if ( ( V_7 -> V_58 & V_60 ) ||
V_7 -> type == V_72 ||
V_7 -> type == V_73 ||
V_7 -> type == V_64 ||
V_7 -> type == V_74 ) {
V_45 -> V_49 . V_75 = - 1 ;
} else {
F_39 ( V_45 ) ;
V_71 ( ( unsigned long ) V_45 ) ;
}
#endif
if ( F_43 ( V_7 ) && F_4 ( V_7 ) )
V_45 -> V_76 |= V_77 ;
F_44 ( V_45 ) ;
V_45 -> V_78 = V_25 ;
F_2 ( V_45 ) ;
F_45 ( V_7 -> V_79 , V_45 ) ;
F_46 ( V_7 , & V_80 ) ;
return V_45 ;
}
static struct V_4 * F_47 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! V_5 )
return NULL ;
}
if ( V_7 -> V_58 & V_81 )
F_49 ( V_5 ) ;
return V_5 ;
}
static void F_50 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_13 * V_82 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_49 . V_55 )
F_34 ( V_7 ) ;
if ( V_7 && ( V_7 -> V_58 & V_83 ) ) {
if ( V_5 -> V_49 . V_55 )
F_46 ( V_7 , & V_84 ) ;
else
F_51 ( V_7 , & V_84 ) ;
}
F_52 (ifa, &idev->addr_list, if_list) {
if ( V_82 -> V_58 & V_85 )
continue;
if ( V_5 -> V_49 . V_55 )
F_53 ( V_82 ) ;
else
F_54 ( V_82 ) ;
}
}
static void F_55 ( struct V_86 * V_86 , T_2 V_87 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_56 () ;
F_57 (net, dev) {
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
int V_88 = ( ! V_5 -> V_49 . V_55 ) ^ ( ! V_87 ) ;
V_5 -> V_49 . V_55 = V_87 ;
if ( V_88 )
F_50 ( V_5 ) ;
}
}
F_58 () ;
}
static int F_59 ( struct V_89 * V_90 , int * V_91 , int V_92 )
{
struct V_86 * V_86 ;
V_86 = (struct V_86 * ) V_90 -> V_93 ;
if ( V_91 == & V_86 -> V_28 . V_50 -> V_55 )
return 0 ;
if ( ! F_60 () ) {
* V_91 = V_92 ;
return F_61 () ;
}
if ( V_91 == & V_86 -> V_28 . V_94 -> V_55 ) {
T_2 V_87 = V_86 -> V_28 . V_94 -> V_55 ;
V_86 -> V_28 . V_50 -> V_55 = V_87 ;
F_55 ( V_86 , V_87 ) ;
} else if ( ( ! * V_91 ) ^ ( ! V_92 ) )
F_50 ( (struct V_4 * ) V_90 -> V_95 ) ;
F_62 () ;
if ( * V_91 )
F_63 ( V_86 ) ;
return 1 ;
}
void F_64 ( struct V_13 * V_14 )
{
F_21 ( ! F_65 ( & V_14 -> V_96 ) ) ;
#ifdef F_23
F_24 ( V_41 L_7 ) ;
#endif
F_66 ( V_14 -> V_5 ) ;
if ( F_8 ( & V_14 -> V_15 ) )
F_67 ( L_8 , V_14 ) ;
if ( V_14 -> V_97 != V_98 ) {
F_26 ( L_9 , V_14 ) ;
return;
}
F_68 ( & V_14 -> V_9 -> V_99 ) ;
F_27 ( V_14 , V_44 ) ;
}
static void
F_69 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_100 * V_91 ;
int V_101 = F_70 ( & V_14 -> V_102 ) ;
F_71 (p, &idev->addr_list) {
struct V_13 * V_82
= F_72 ( V_91 , struct V_13 , V_103 ) ;
if ( V_101 >= F_70 ( & V_82 -> V_102 ) )
break;
}
F_73 ( & V_14 -> V_103 , V_91 ) ;
}
static T_1 F_74 ( const struct V_104 * V_102 )
{
return F_75 ( ( V_105 T_1 ) V_102 -> V_106 [ 2 ] ,
( V_105 T_1 ) V_102 -> V_106 [ 3 ] , 0 )
& ( V_107 - 1 ) ;
}
static struct V_13 *
F_76 ( struct V_4 * V_5 , const struct V_104 * V_102 , int V_108 ,
int V_109 , T_1 V_58 )
{
struct V_13 * V_82 = NULL ;
struct V_8 * V_9 ;
unsigned int V_110 ;
int V_111 = 0 ;
int V_112 = F_77 ( V_102 ) ;
if ( V_112 == V_113 ||
V_112 & V_114 ||
( ! ( V_5 -> V_7 -> V_58 & V_60 ) &&
V_112 & V_115 ) )
return F_78 ( - V_116 ) ;
F_79 () ;
if ( V_5 -> V_43 ) {
V_111 = - V_117 ;
goto V_118;
}
if ( V_5 -> V_49 . V_119 ) {
V_111 = - V_120 ;
goto V_118;
}
F_80 ( & V_121 ) ;
if ( F_81 ( F_32 ( V_5 -> V_7 ) , V_102 , V_5 -> V_7 ) ) {
F_36 ( ( L_10 ) ) ;
V_111 = - V_122 ;
goto V_123;
}
V_82 = F_16 ( sizeof( struct V_13 ) , V_124 ) ;
if ( V_82 == NULL ) {
F_36 ( ( L_11 ) ) ;
V_111 = - V_125 ;
goto V_123;
}
V_9 = F_82 ( V_5 , V_102 , 0 ) ;
if ( F_83 ( V_9 ) ) {
V_111 = F_84 ( V_9 ) ;
goto V_123;
}
F_85 ( & V_82 -> V_102 , V_102 ) ;
F_86 ( & V_82 -> V_48 ) ;
F_86 ( & V_82 -> V_126 ) ;
F_87 ( & V_82 -> V_15 ) ;
F_88 ( & V_82 -> V_96 ) ;
V_82 -> V_15 . V_127 = ( unsigned long ) V_82 ;
V_82 -> V_109 = V_109 ;
V_82 -> V_128 = V_108 ;
V_82 -> V_58 = V_58 | V_85 ;
V_82 -> V_1 = V_82 -> V_78 = V_25 ;
V_82 -> V_9 = V_9 ;
if ( V_9 -> V_129 == NULL )
V_82 -> V_58 &= ~ V_130 ;
V_82 -> V_5 = V_5 ;
F_39 ( V_5 ) ;
F_11 ( V_82 ) ;
V_110 = F_74 ( V_102 ) ;
F_89 ( & V_82 -> V_96 , & V_131 [ V_110 ] ) ;
F_90 ( & V_121 ) ;
F_91 ( & V_5 -> V_48 ) ;
F_69 ( V_5 , V_82 ) ;
#ifdef F_41
if ( V_82 -> V_58 & V_132 ) {
F_92 ( & V_82 -> V_133 , & V_5 -> V_69 ) ;
F_11 ( V_82 ) ;
}
#endif
F_11 ( V_82 ) ;
F_93 ( & V_5 -> V_48 ) ;
V_118:
F_94 () ;
if ( F_95 ( V_111 == 0 ) )
F_96 ( & V_134 , V_135 , V_82 ) ;
else {
F_17 ( V_82 ) ;
V_82 = F_78 ( V_111 ) ;
}
return V_82 ;
V_123:
F_90 ( & V_121 ) ;
goto V_118;
}
static void F_97 ( struct V_13 * V_14 )
{
struct V_13 * V_82 , * V_136 ;
struct V_4 * V_5 = V_14 -> V_5 ;
int V_97 ;
int V_137 = 0 , V_138 = 0 ;
unsigned long V_24 = V_25 ;
F_98 ( & V_14 -> V_126 ) ;
V_97 = V_14 -> V_97 ;
V_14 -> V_97 = V_98 ;
F_99 ( & V_14 -> V_126 ) ;
if ( V_97 == V_98 )
goto V_123;
F_98 ( & V_121 ) ;
F_100 ( & V_14 -> V_96 ) ;
F_99 ( & V_121 ) ;
F_101 ( & V_5 -> V_48 ) ;
#ifdef F_41
if ( V_14 -> V_58 & V_132 ) {
F_102 ( & V_14 -> V_133 ) ;
if ( V_14 -> V_139 ) {
F_103 ( V_14 -> V_139 ) ;
V_14 -> V_139 = NULL ;
}
F_9 ( V_14 ) ;
}
#endif
F_104 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_82 == V_14 ) {
F_105 ( & V_14 -> V_103 ) ;
F_9 ( V_14 ) ;
if ( ! ( V_14 -> V_58 & V_140 ) || V_138 > 0 )
break;
V_137 = 1 ;
continue;
} else if ( V_14 -> V_58 & V_140 ) {
if ( F_106 ( & V_82 -> V_102 , & V_14 -> V_102 ,
V_14 -> V_128 ) ) {
if ( V_82 -> V_58 & V_140 ) {
V_138 = 1 ;
if ( V_137 )
break;
} else {
unsigned long V_141 ;
if ( ! V_138 )
V_138 = - 1 ;
F_80 ( & V_82 -> V_48 ) ;
V_141 = F_107 ( V_82 -> V_142 , V_3 ) ;
if ( F_108 ( V_24 ,
V_82 -> V_78 + V_141 * V_3 ) )
V_24 = V_82 -> V_78 + V_141 * V_3 ;
F_90 ( & V_82 -> V_48 ) ;
}
}
}
}
F_109 ( & V_5 -> V_48 ) ;
F_7 ( V_14 ) ;
F_110 ( V_143 , V_14 ) ;
F_96 ( & V_134 , V_144 , V_14 ) ;
if ( ( V_14 -> V_58 & V_140 ) && V_138 < 1 ) {
struct V_104 V_145 ;
struct V_8 * V_9 ;
struct V_86 * V_86 = F_32 ( V_14 -> V_5 -> V_7 ) ;
F_111 ( & V_145 , & V_14 -> V_102 , V_14 -> V_128 ) ;
V_9 = F_112 ( V_86 , & V_145 , NULL , V_14 -> V_5 -> V_7 -> V_146 , 1 ) ;
if ( V_9 && F_6 ( V_9 ) ) {
if ( V_138 == 0 ) {
F_113 ( V_9 ) ;
V_9 = NULL ;
} else if ( ! ( V_9 -> V_10 & V_147 ) ) {
V_9 -> V_148 = V_24 ;
V_9 -> V_10 |= V_147 ;
}
}
F_68 ( & V_9 -> V_99 ) ;
}
F_114 ( V_14 ) ;
V_123:
F_103 ( V_14 ) ;
}
static int F_115 ( struct V_13 * V_14 , struct V_13 * V_149 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_104 V_102 , * V_150 ;
unsigned long V_151 , V_152 , V_153 , V_154 , V_155 ;
unsigned long V_156 ;
int V_157 ;
int V_158 = 0 ;
int V_159 ;
T_1 V_160 ;
F_91 ( & V_5 -> V_48 ) ;
if ( V_149 ) {
F_98 ( & V_149 -> V_48 ) ;
memcpy ( & V_102 . V_161 [ 8 ] , & V_149 -> V_102 . V_161 [ 8 ] , 8 ) ;
F_99 ( & V_149 -> V_48 ) ;
V_150 = & V_102 ;
} else {
V_150 = NULL ;
}
V_162:
F_39 ( V_5 ) ;
if ( V_5 -> V_49 . V_75 <= 0 ) {
F_93 ( & V_5 -> V_48 ) ;
F_24 ( V_67
L_12 ) ;
F_66 ( V_5 ) ;
V_158 = - 1 ;
goto V_123;
}
F_98 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_163 ++ >= V_5 -> V_49 . V_164 ) {
V_5 -> V_49 . V_75 = - 1 ;
F_99 ( & V_14 -> V_48 ) ;
F_93 ( & V_5 -> V_48 ) ;
F_24 ( V_56
L_13 ) ;
F_66 ( V_5 ) ;
V_158 = - 1 ;
goto V_123;
}
F_11 ( V_14 ) ;
memcpy ( V_102 . V_161 , V_14 -> V_102 . V_161 , 8 ) ;
if ( F_116 ( V_5 , V_150 ) < 0 ) {
F_99 ( & V_14 -> V_48 ) ;
F_93 ( & V_5 -> V_48 ) ;
F_24 ( V_56
L_14 ) ;
F_103 ( V_14 ) ;
F_66 ( V_5 ) ;
V_158 = - 1 ;
goto V_123;
}
memcpy ( & V_102 . V_161 [ 8 ] , V_5 -> V_165 , 8 ) ;
V_155 = ( V_25 - V_14 -> V_78 ) / V_3 ;
V_152 = F_117 ( V_166 ,
V_14 -> V_142 ,
V_5 -> V_49 . V_167 + V_155 ) ;
V_151 = F_117 ( V_166 ,
V_14 -> V_168 ,
V_5 -> V_49 . V_169 + V_155 -
V_5 -> V_49 . V_170 ) ;
V_157 = V_14 -> V_128 ;
V_159 = V_5 -> V_49 . V_159 ;
V_153 = V_14 -> V_1 ;
V_154 = V_14 -> V_78 ;
F_99 ( & V_14 -> V_48 ) ;
V_156 = V_5 -> V_49 . V_164 *
V_5 -> V_49 . V_171 *
V_5 -> V_53 -> V_172 / V_3 ;
F_93 ( & V_5 -> V_48 ) ;
if ( V_151 <= V_156 ) {
F_103 ( V_14 ) ;
F_66 ( V_5 ) ;
V_158 = - 1 ;
goto V_123;
}
V_160 = V_132 ;
if ( V_14 -> V_58 & V_130 )
V_160 |= V_130 ;
V_149 = ! V_159 ||
F_118 ( V_5 ) < V_159 ?
F_76 ( V_5 , & V_102 , V_157 ,
F_77 ( & V_102 ) & V_173 ,
V_160 ) : NULL ;
if ( ! V_149 || F_83 ( V_149 ) ) {
F_103 ( V_14 ) ;
F_66 ( V_5 ) ;
F_24 ( V_67
L_15 ) ;
V_150 = & V_102 ;
F_91 ( & V_5 -> V_48 ) ;
goto V_162;
}
F_98 ( & V_149 -> V_48 ) ;
V_149 -> V_139 = V_14 ;
V_149 -> V_142 = V_152 ;
V_149 -> V_168 = V_151 ;
V_149 -> V_1 = V_153 ;
V_149 -> V_78 = V_154 ;
F_99 ( & V_149 -> V_48 ) ;
F_119 ( V_149 , 0 ) ;
F_103 ( V_149 ) ;
F_66 ( V_5 ) ;
V_123:
return V_158 ;
}
static inline int F_120 ( int type )
{
if ( type & ( V_174 | V_175 | V_115 ) )
return 1 ;
return 0 ;
}
static int F_121 ( struct V_86 * V_86 ,
struct V_176 * V_177 ,
struct V_178 * V_99 ,
int V_179 )
{
int V_158 ;
if ( V_179 <= V_177 -> V_180 ) {
switch ( V_179 ) {
case V_181 :
V_158 = V_177 -> V_182 ;
break;
case V_183 :
V_158 = V_177 -> V_184 ;
break;
default:
V_158 = ! ! F_122 ( V_179 , V_177 -> V_185 ) ;
}
goto V_123;
}
switch ( V_179 ) {
case V_186 :
V_158 = ! ! V_177 -> V_82 ;
break;
case V_187 :
V_158 = F_123 ( & V_177 -> V_82 -> V_102 , V_99 -> V_102 ) ;
break;
case V_181 :
V_158 = F_124 ( V_177 -> V_112 ) ;
if ( V_158 >= V_99 -> V_109 )
V_158 = - V_158 ;
else
V_158 -= 128 ;
V_177 -> V_182 = V_158 ;
break;
case V_188 :
V_158 = F_120 ( V_177 -> V_112 ) ||
! ( V_177 -> V_82 -> V_58 & ( V_189 | V_130 ) ) ;
break;
#ifdef F_125
case V_190 :
{
int V_191 = ! ( V_99 -> V_192 & V_193 ) ;
V_158 = ! ( V_177 -> V_82 -> V_58 & V_194 ) ^ V_191 ;
break;
}
#endif
case V_195 :
V_158 = ( ! V_99 -> V_146 ||
V_99 -> V_146 == V_177 -> V_82 -> V_5 -> V_7 -> V_146 ) ;
break;
case V_196 :
V_158 = F_126 ( V_86 ,
& V_177 -> V_82 -> V_102 , V_177 -> V_112 ,
V_177 -> V_82 -> V_5 -> V_7 -> V_146 ) == V_99 -> V_197 ;
break;
#ifdef F_41
case V_198 :
{
int V_199 = V_99 -> V_192 & ( V_200 | V_201 ) ?
! ! ( V_99 -> V_192 & V_201 ) :
V_177 -> V_82 -> V_5 -> V_49 . V_75 >= 2 ;
V_158 = ( ! ( V_177 -> V_82 -> V_58 & V_132 ) ) ^ V_199 ;
break;
}
#endif
case V_202 :
V_158 = ! ( F_127 ( & V_177 -> V_82 -> V_102 ) ^
F_127 ( V_99 -> V_102 ) ) ;
break;
case V_183 :
V_177 -> V_184 = V_158 = F_128 ( & V_177 -> V_82 -> V_102 ,
V_99 -> V_102 ) ;
break;
default:
V_158 = 0 ;
}
if ( V_158 )
F_129 ( V_179 , V_177 -> V_185 ) ;
V_177 -> V_180 = V_179 ;
V_123:
return V_158 ;
}
int F_130 ( struct V_86 * V_86 , struct V_6 * V_203 ,
const struct V_104 * V_204 , unsigned int V_192 ,
struct V_104 * V_205 )
{
struct V_176 V_206 [ 2 ] ,
* V_177 = & V_206 [ 0 ] , * V_207 = & V_206 [ 1 ] ;
struct V_178 V_99 ;
struct V_6 * V_7 ;
int V_208 ;
V_208 = F_131 ( V_204 ) ;
V_99 . V_102 = V_204 ;
V_99 . V_146 = V_203 ? V_203 -> V_146 : 0 ;
V_99 . V_109 = F_124 ( V_208 ) ;
V_99 . V_197 = F_126 ( V_86 , V_204 , V_208 , V_99 . V_146 ) ;
V_99 . V_192 = V_192 ;
V_207 -> V_180 = - 1 ;
V_207 -> V_82 = NULL ;
F_56 () ;
F_57 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_208 & V_114 ) ||
V_99 . V_109 <= V_209 ) &&
V_99 . V_146 && V_7 -> V_146 != V_99 . V_146 )
continue;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
continue;
F_132 ( & V_5 -> V_48 ) ;
F_52 (score->ifa, &idev->addr_list, if_list) {
int V_179 ;
if ( ( V_177 -> V_82 -> V_58 & V_85 ) &&
( ! ( V_177 -> V_82 -> V_58 & V_130 ) ) )
continue;
V_177 -> V_112 = F_131 ( & V_177 -> V_82 -> V_102 ) ;
if ( F_133 ( V_177 -> V_112 == V_113 ||
V_177 -> V_112 & V_114 ) ) {
F_134 ( V_41
L_16
L_17 ,
V_7 -> V_42 ) ;
continue;
}
V_177 -> V_180 = - 1 ;
F_135 ( V_177 -> V_185 , V_210 ) ;
for ( V_179 = 0 ; V_179 < V_210 ; V_179 ++ ) {
int V_211 , V_212 ;
V_211 = F_121 ( V_86 , V_207 , & V_99 , V_179 ) ;
V_212 = F_121 ( V_86 , V_177 , & V_99 , V_179 ) ;
if ( V_211 > V_212 ) {
if ( V_179 == V_181 &&
V_177 -> V_182 > 0 ) {
goto V_213;
}
break;
} else if ( V_211 < V_212 ) {
if ( V_207 -> V_82 )
F_103 ( V_207 -> V_82 ) ;
F_11 ( V_177 -> V_82 ) ;
F_136 ( V_207 , V_177 ) ;
V_177 -> V_82 = V_207 -> V_82 ;
break;
}
}
}
V_213:
F_137 ( & V_5 -> V_48 ) ;
}
F_58 () ;
if ( ! V_207 -> V_82 )
return - V_116 ;
F_85 ( V_205 , & V_207 -> V_82 -> V_102 ) ;
F_103 ( V_207 -> V_82 ) ;
return 0 ;
}
int F_138 ( struct V_6 * V_7 , struct V_104 * V_102 ,
unsigned char V_214 )
{
struct V_4 * V_5 ;
int V_111 = - V_116 ;
F_56 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
struct V_13 * V_14 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_109 == V_215 &&
! ( V_14 -> V_58 & V_214 ) ) {
F_85 ( V_102 , & V_14 -> V_102 ) ;
V_111 = 0 ;
break;
}
}
F_137 ( & V_5 -> V_48 ) ;
}
F_58 () ;
return V_111 ;
}
static int F_118 ( struct V_4 * V_5 )
{
int V_216 = 0 ;
struct V_13 * V_14 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list)
V_216 ++ ;
F_137 ( & V_5 -> V_48 ) ;
return V_216 ;
}
int F_139 ( struct V_86 * V_86 , const struct V_104 * V_102 ,
struct V_6 * V_7 , int V_217 )
{
struct V_13 * V_14 ;
struct V_218 * V_219 ;
unsigned int V_110 = F_74 ( V_102 ) ;
F_79 () ;
F_140 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_141 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_123 ( & V_14 -> V_102 , V_102 ) &&
! ( V_14 -> V_58 & V_85 ) &&
( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_109 & ( V_215 | V_220 ) || V_217 ) ) ) {
F_94 () ;
return 1 ;
}
}
F_94 () ;
return 0 ;
}
static bool F_81 ( struct V_86 * V_86 , const struct V_104 * V_102 ,
struct V_6 * V_7 )
{
unsigned int V_110 = F_74 ( V_102 ) ;
struct V_13 * V_14 ;
struct V_218 * V_219 ;
F_142 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_141 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_123 ( & V_14 -> V_102 , V_102 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
int F_143 ( const struct V_104 * V_102 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_138 ;
V_138 = 0 ;
F_56 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifa, &idev->addr_list, if_list) {
V_138 = F_106 ( V_102 , & V_82 -> V_102 ,
V_82 -> V_128 ) ;
if ( V_138 )
break;
}
F_137 ( & V_5 -> V_48 ) ;
}
F_58 () ;
return V_138 ;
}
struct V_13 * F_144 ( struct V_86 * V_86 , const struct V_104 * V_102 ,
struct V_6 * V_7 , int V_217 )
{
struct V_13 * V_14 , * V_221 = NULL ;
unsigned int V_110 = F_74 ( V_102 ) ;
struct V_218 * V_219 ;
F_79 () ;
F_145 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_141 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_123 ( & V_14 -> V_102 , V_102 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_109 & ( V_215 | V_220 ) || V_217 ) ) {
V_221 = V_14 ;
F_11 ( V_14 ) ;
break;
}
}
}
F_94 () ;
return V_221 ;
}
static void F_146 ( struct V_13 * V_14 , int V_222 )
{
if ( V_14 -> V_58 & V_140 ) {
F_98 ( & V_14 -> V_48 ) ;
F_7 ( V_14 ) ;
V_14 -> V_58 |= V_85 ;
if ( V_222 )
V_14 -> V_58 |= V_223 ;
F_99 ( & V_14 -> V_48 ) ;
if ( V_222 )
F_110 ( 0 , V_14 ) ;
F_103 ( V_14 ) ;
#ifdef F_41
} else if ( V_14 -> V_58 & V_132 ) {
struct V_13 * V_139 ;
F_98 ( & V_14 -> V_48 ) ;
V_139 = V_14 -> V_139 ;
if ( V_139 ) {
F_11 ( V_139 ) ;
F_99 ( & V_14 -> V_48 ) ;
F_115 ( V_139 , V_14 ) ;
F_103 ( V_139 ) ;
} else {
F_99 ( & V_14 -> V_48 ) ;
}
F_97 ( V_14 ) ;
#endif
} else
F_97 ( V_14 ) ;
}
static int F_147 ( struct V_13 * V_14 )
{
int V_111 = - V_224 ;
F_80 ( & V_14 -> V_126 ) ;
if ( V_14 -> V_97 == V_225 ) {
V_14 -> V_97 = V_226 ;
V_111 = 0 ;
}
F_90 ( & V_14 -> V_126 ) ;
return V_111 ;
}
void F_148 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
if ( F_147 ( V_14 ) ) {
F_103 ( V_14 ) ;
return;
}
if ( F_149 () )
F_24 ( V_67 L_18 ,
V_14 -> V_5 -> V_7 -> V_42 , & V_14 -> V_102 ) ;
if ( V_5 -> V_49 . V_61 > 1 && ! V_5 -> V_49 . V_119 ) {
struct V_104 V_102 ;
V_102 . V_106 [ 0 ] = F_150 ( 0xfe800000 ) ;
V_102 . V_106 [ 1 ] = 0 ;
if ( ! F_151 ( V_102 . V_161 + 8 , V_5 -> V_7 ) &&
F_123 ( & V_14 -> V_102 , & V_102 ) ) {
V_5 -> V_49 . V_119 = 1 ;
F_24 ( V_67 L_19 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
}
}
F_146 ( V_14 , 1 ) ;
}
void F_152 ( struct V_6 * V_7 , const struct V_104 * V_102 )
{
struct V_104 V_227 ;
if ( V_7 -> V_58 & ( V_60 | V_59 ) )
return;
F_153 ( V_102 , & V_227 ) ;
F_46 ( V_7 , & V_227 ) ;
}
void F_154 ( struct V_4 * V_5 , const struct V_104 * V_102 )
{
struct V_104 V_227 ;
if ( V_5 -> V_7 -> V_58 & ( V_60 | V_59 ) )
return;
F_153 ( V_102 , & V_227 ) ;
F_155 ( V_5 , & V_227 ) ;
}
static void F_53 ( struct V_13 * V_14 )
{
struct V_104 V_102 ;
F_111 ( & V_102 , & V_14 -> V_102 , V_14 -> V_128 ) ;
if ( F_156 ( & V_102 ) )
return;
F_157 ( V_14 -> V_5 -> V_7 , & V_102 ) ;
}
static void F_54 ( struct V_13 * V_14 )
{
struct V_104 V_102 ;
F_111 ( & V_102 , & V_14 -> V_102 , V_14 -> V_128 ) ;
if ( F_156 ( & V_102 ) )
return;
F_158 ( V_14 -> V_5 , & V_102 ) ;
}
static int F_159 ( T_3 * V_228 , struct V_6 * V_7 )
{
if ( V_7 -> V_229 != V_230 )
return - 1 ;
memcpy ( V_228 , V_7 -> V_231 , 3 ) ;
memcpy ( V_228 + 5 , V_7 -> V_231 + 3 , 3 ) ;
if ( V_7 -> V_232 ) {
V_228 [ 3 ] = ( V_7 -> V_232 >> 8 ) & 0xFF ;
V_228 [ 4 ] = V_7 -> V_232 & 0xFF ;
} else {
V_228 [ 3 ] = 0xFF ;
V_228 [ 4 ] = 0xFE ;
V_228 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_160 ( T_3 * V_228 , struct V_6 * V_7 )
{
if ( V_7 -> V_229 != V_233 )
return - 1 ;
memset ( V_228 , 0 , 7 ) ;
V_228 [ 7 ] = * ( T_3 * ) V_7 -> V_231 ;
return 0 ;
}
static int F_161 ( T_3 * V_228 , struct V_6 * V_7 )
{
if ( V_7 -> V_229 != V_234 )
return - 1 ;
memcpy ( V_228 , V_7 -> V_231 + 12 , 8 ) ;
V_228 [ 0 ] |= 2 ;
return 0 ;
}
static int F_162 ( T_3 * V_228 , T_4 V_102 )
{
if ( V_102 == 0 )
return - 1 ;
V_228 [ 0 ] = ( F_163 ( V_102 ) || F_164 ( V_102 ) ||
F_165 ( V_102 ) || F_166 ( V_102 ) ||
F_167 ( V_102 ) || F_168 ( V_102 ) ||
F_169 ( V_102 ) || F_170 ( V_102 ) ||
F_171 ( V_102 ) || F_172 ( V_102 ) ||
F_173 ( V_102 ) ) ? 0x00 : 0x02 ;
V_228 [ 1 ] = 0 ;
V_228 [ 2 ] = 0x5E ;
V_228 [ 3 ] = 0xFE ;
memcpy ( V_228 + 4 , & V_102 , 4 ) ;
return 0 ;
}
static int F_174 ( T_3 * V_228 , struct V_6 * V_7 )
{
if ( V_7 -> V_65 & V_66 )
return F_162 ( V_228 , * ( T_4 * ) V_7 -> V_231 ) ;
return - 1 ;
}
static int F_151 ( T_3 * V_228 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_235 :
case V_236 :
case V_237 :
return F_159 ( V_228 , V_7 ) ;
case V_238 :
return F_160 ( V_228 , V_7 ) ;
case V_239 :
return F_161 ( V_228 , V_7 ) ;
case V_64 :
return F_174 ( V_228 , V_7 ) ;
}
return - 1 ;
}
static int F_175 ( T_3 * V_228 , struct V_4 * V_5 )
{
int V_111 = - 1 ;
struct V_13 * V_14 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_109 == V_215 && ! ( V_14 -> V_58 & V_85 ) ) {
memcpy ( V_228 , V_14 -> V_102 . V_161 + 8 , 8 ) ;
V_111 = 0 ;
break;
}
}
F_137 ( & V_5 -> V_48 ) ;
return V_111 ;
}
static int F_176 ( struct V_4 * V_5 )
{
V_240:
F_177 ( V_5 -> V_165 , sizeof( V_5 -> V_165 ) ) ;
V_5 -> V_165 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_165 [ 0 ] == 0xfd &&
( V_5 -> V_165 [ 1 ] & V_5 -> V_165 [ 2 ] & V_5 -> V_165 [ 3 ] & V_5 -> V_165 [ 4 ] & V_5 -> V_165 [ 5 ] & V_5 -> V_165 [ 6 ] ) == 0xff &&
( V_5 -> V_165 [ 7 ] & 0x80 ) )
goto V_240;
if ( ( V_5 -> V_165 [ 0 ] | V_5 -> V_165 [ 1 ] ) == 0 ) {
if ( V_5 -> V_165 [ 2 ] == 0x5e && V_5 -> V_165 [ 3 ] == 0xfe )
goto V_240;
if ( ( V_5 -> V_165 [ 2 ] | V_5 -> V_165 [ 3 ] | V_5 -> V_165 [ 4 ] | V_5 -> V_165 [ 5 ] | V_5 -> V_165 [ 6 ] | V_5 -> V_165 [ 7 ] ) == 0x00 )
goto V_240;
}
return 0 ;
}
static void V_71 ( unsigned long V_127 )
{
struct V_4 * V_5 = (struct V_4 * ) V_127 ;
unsigned long V_24 ;
F_79 () ;
F_101 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 )
goto V_123;
if ( F_176 ( V_5 ) < 0 )
goto V_123;
V_24 = V_25 +
V_5 -> V_49 . V_169 * V_3 -
V_5 -> V_49 . V_164 * V_5 -> V_49 . V_171 * V_5 -> V_53 -> V_172 -
V_5 -> V_49 . V_170 * V_3 ;
if ( F_108 ( V_24 , V_25 ) ) {
F_24 ( V_56
L_20 ,
V_5 -> V_7 -> V_42 ) ;
goto V_123;
}
if ( ! F_178 ( & V_5 -> V_70 , V_24 ) )
F_39 ( V_5 ) ;
V_123:
F_109 ( & V_5 -> V_48 ) ;
F_94 () ;
F_66 ( V_5 ) ;
}
static int F_116 ( struct V_4 * V_5 , struct V_104 * V_150 ) {
int V_158 = 0 ;
if ( V_150 && memcmp ( V_5 -> V_165 , & V_150 -> V_161 [ 8 ] , 8 ) == 0 )
V_158 = F_176 ( V_5 ) ;
return V_158 ;
}
static void
F_179 ( struct V_104 * V_241 , int V_242 , struct V_6 * V_7 ,
unsigned long V_24 , T_1 V_58 )
{
struct V_243 V_244 = {
. V_245 = V_246 ,
. V_247 = V_248 ,
. V_249 = V_7 -> V_146 ,
. V_250 = V_24 ,
. V_251 = V_242 ,
. V_252 = V_253 | V_58 ,
. V_254 . V_255 = F_32 ( V_7 ) ,
. V_256 = V_257 ,
} ;
F_85 ( & V_244 . V_258 , V_241 ) ;
#if F_40 ( V_62 ) || F_40 ( V_63 )
if ( V_7 -> type == V_64 && ( V_7 -> V_58 & V_259 ) )
V_244 . V_252 |= V_260 ;
#endif
F_180 ( & V_244 ) ;
}
static void F_181 ( struct V_6 * V_7 )
{
struct V_243 V_244 = {
. V_245 = V_261 ,
. V_247 = V_248 ,
. V_249 = V_7 -> V_146 ,
. V_251 = 8 ,
. V_252 = V_253 ,
. V_254 . V_255 = F_32 ( V_7 ) ,
} ;
F_182 ( & V_244 . V_258 , F_150 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_180 ( & V_244 ) ;
}
static void F_183 ( struct V_6 * V_7 )
{
struct V_243 V_244 = {
. V_245 = V_262 ,
. V_247 = V_248 ,
. V_249 = V_7 -> V_146 ,
. V_251 = 96 ,
. V_252 = V_253 | V_260 ,
. V_254 . V_255 = F_32 ( V_7 ) ,
} ;
F_180 ( & V_244 ) ;
}
static void F_184 ( struct V_6 * V_7 )
{
struct V_104 V_102 ;
F_182 ( & V_102 , F_150 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_179 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
}
static struct V_4 * F_185 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
return F_78 ( - V_125 ) ;
if ( V_5 -> V_49 . V_119 )
return F_78 ( - V_120 ) ;
F_181 ( V_7 ) ;
F_184 ( V_7 ) ;
return V_5 ;
}
void F_186 ( struct V_6 * V_7 , T_3 * V_263 , int V_264 )
{
struct V_265 * V_266 ;
V_166 V_142 ;
V_166 V_168 ;
int V_112 ;
struct V_4 * V_267 ;
struct V_86 * V_86 = F_32 ( V_7 ) ;
V_266 = (struct V_265 * ) V_263 ;
if ( V_264 < sizeof( struct V_265 ) ) {
F_36 ( ( L_21 ) ) ;
return;
}
V_112 = F_77 ( & V_266 -> V_145 ) ;
if ( V_112 & ( V_114 | V_268 ) )
return;
V_142 = F_187 ( V_266 -> V_269 ) ;
V_168 = F_187 ( V_266 -> V_270 ) ;
if ( V_168 > V_142 ) {
if ( F_149 () )
F_24 ( V_56 L_22 ) ;
return;
}
V_267 = F_188 ( V_7 ) ;
if ( V_267 == NULL ) {
if ( F_149 () )
F_24 ( V_41 L_23 , V_7 -> V_42 ) ;
return;
}
if ( V_266 -> V_138 ) {
struct V_8 * V_9 ;
unsigned long V_271 ;
if ( V_3 > V_272 )
V_271 = F_107 ( V_142 , V_3 ) ;
else
V_271 = F_107 ( V_142 , V_272 ) ;
if ( F_189 ( V_271 ) )
V_271 *= V_3 ;
V_9 = F_112 ( V_86 , & V_266 -> V_145 , NULL ,
V_7 -> V_146 , 1 ) ;
if ( V_9 && F_6 ( V_9 ) ) {
if ( V_142 == 0 ) {
F_113 ( V_9 ) ;
V_9 = NULL ;
} else if ( F_189 ( V_271 ) ) {
V_9 -> V_148 = V_25 + V_271 ;
V_9 -> V_10 |= V_147 ;
} else {
V_9 -> V_10 &= ~ V_147 ;
V_9 -> V_148 = 0 ;
}
} else if ( V_142 ) {
T_5 V_24 = 0 ;
int V_58 = V_273 | V_274 ;
if ( F_189 ( V_271 ) ) {
V_58 |= V_147 ;
V_24 = F_190 ( V_271 ) ;
}
F_179 ( & V_266 -> V_145 , V_266 -> V_128 ,
V_7 , V_24 , V_58 ) ;
}
if ( V_9 )
F_68 ( & V_9 -> V_99 ) ;
}
if ( V_266 -> V_275 && V_267 -> V_49 . V_275 ) {
struct V_13 * V_14 ;
struct V_104 V_102 ;
int V_276 = 0 , V_277 = 0 ;
if ( V_266 -> V_128 == 64 ) {
memcpy ( & V_102 , & V_266 -> V_145 , 8 ) ;
if ( F_151 ( V_102 . V_161 + 8 , V_7 ) &&
F_175 ( V_102 . V_161 + 8 , V_267 ) ) {
F_66 ( V_267 ) ;
return;
}
goto V_278;
}
if ( F_149 () )
F_24 ( V_41 L_24 ,
V_266 -> V_128 ) ;
F_66 ( V_267 ) ;
return;
V_278:
V_14 = F_144 ( V_86 , & V_102 , V_7 , 1 ) ;
if ( V_14 == NULL && V_142 ) {
int V_159 = V_267 -> V_49 . V_159 ;
T_1 V_160 = 0 ;
#ifdef F_191
if ( V_267 -> V_49 . V_279 &&
! V_86 -> V_28 . V_94 -> V_55 )
V_160 = V_130 ;
#endif
if ( ! V_159 ||
F_118 ( V_267 ) < V_159 )
V_14 = F_76 ( V_267 , & V_102 , V_266 -> V_128 ,
V_112 & V_173 ,
V_160 ) ;
if ( ! V_14 || F_83 ( V_14 ) ) {
F_66 ( V_267 ) ;
return;
}
V_277 = V_276 = 1 ;
V_14 -> V_1 = V_25 ;
F_119 ( V_14 , V_273 | V_274 ) ;
}
if ( V_14 ) {
int V_58 ;
unsigned long V_280 ;
#ifdef F_41
struct V_13 * V_149 ;
#endif
T_1 V_281 ;
F_80 ( & V_14 -> V_48 ) ;
V_280 = V_25 ;
if ( V_14 -> V_142 > ( V_280 - V_14 -> V_78 ) / V_3 )
V_281 = V_14 -> V_142 - ( V_280 - V_14 -> V_78 ) / V_3 ;
else
V_281 = 0 ;
if ( ! V_277 && V_281 ) {
if ( V_142 > V_282 ||
V_142 > V_281 )
V_277 = 1 ;
else if ( V_281 <= V_282 ) {
if ( V_168 != V_14 -> V_168 ) {
V_142 = V_281 ;
V_277 = 1 ;
}
} else {
V_142 = V_282 ;
if ( V_142 < V_168 )
V_168 = V_142 ;
V_277 = 1 ;
}
}
if ( V_277 ) {
V_14 -> V_142 = V_142 ;
V_14 -> V_168 = V_168 ;
V_14 -> V_78 = V_280 ;
V_58 = V_14 -> V_58 ;
V_14 -> V_58 &= ~ V_189 ;
F_90 ( & V_14 -> V_48 ) ;
if ( ! ( V_58 & V_85 ) )
F_110 ( 0 , V_14 ) ;
} else
F_90 ( & V_14 -> V_48 ) ;
#ifdef F_41
F_132 ( & V_267 -> V_48 ) ;
F_52 (ift, &in6_dev->tempaddr_list, tmp_list) {
if ( V_14 != V_149 -> V_139 )
continue;
F_80 ( & V_149 -> V_48 ) ;
V_58 = V_149 -> V_58 ;
if ( V_149 -> V_142 > V_142 &&
V_149 -> V_142 - V_142 > ( V_25 - V_149 -> V_78 ) / V_3 )
V_149 -> V_142 = V_142 + ( V_25 - V_149 -> V_78 ) / V_3 ;
if ( V_149 -> V_168 > V_168 &&
V_149 -> V_168 - V_168 > ( V_25 - V_149 -> V_78 ) / V_3 )
V_149 -> V_168 = V_168 + ( V_25 - V_149 -> V_78 ) / V_3 ;
F_90 ( & V_149 -> V_48 ) ;
if ( ! ( V_58 & V_85 ) )
F_110 ( 0 , V_149 ) ;
}
if ( ( V_276 || F_22 ( & V_267 -> V_69 ) ) && V_267 -> V_49 . V_75 > 0 ) {
F_137 ( & V_267 -> V_48 ) ;
F_115 ( V_14 , NULL ) ;
} else {
F_137 ( & V_267 -> V_48 ) ;
}
#endif
F_103 ( V_14 ) ;
F_192 ( 0 ) ;
}
}
F_193 ( V_283 , V_267 , V_266 ) ;
F_66 ( V_267 ) ;
}
int F_194 ( struct V_86 * V_86 , void T_6 * V_284 )
{
struct V_285 V_286 ;
struct V_6 * V_7 ;
int V_111 = - V_287 ;
F_195 () ;
V_111 = - V_288 ;
if ( F_196 ( & V_286 , V_284 , sizeof( struct V_285 ) ) )
goto V_289;
V_7 = F_197 ( V_86 , V_286 . V_290 ) ;
V_111 = - V_117 ;
if ( V_7 == NULL )
goto V_289;
#if F_40 ( V_62 ) || F_40 ( V_63 )
if ( V_7 -> type == V_64 ) {
const struct V_291 * V_292 = V_7 -> V_293 ;
struct V_294 V_295 ;
struct V_296 V_91 ;
V_111 = - V_116 ;
if ( ! ( F_77 ( & V_286 . V_297 ) & V_175 ) )
goto V_289;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_298 . V_204 = V_286 . V_297 . V_106 [ 3 ] ;
V_91 . V_298 . V_205 = 0 ;
V_91 . V_298 . V_299 = 4 ;
V_91 . V_298 . V_300 = 5 ;
V_91 . V_298 . V_301 = V_302 ;
V_91 . V_298 . V_303 = 64 ;
V_295 . V_304 . V_305 = ( V_105 void T_6 * ) & V_91 ;
if ( V_292 -> V_306 ) {
T_7 V_307 = F_198 () ;
F_199 ( V_308 ) ;
V_111 = V_292 -> V_306 ( V_7 , & V_295 , V_309 ) ;
F_199 ( V_307 ) ;
} else
V_111 = - V_310 ;
if ( V_111 == 0 ) {
V_111 = - V_125 ;
V_7 = F_200 ( V_86 , V_91 . V_42 ) ;
if ( ! V_7 )
goto V_289;
V_111 = F_201 ( V_7 ) ;
}
}
#endif
V_289:
F_62 () ;
return V_111 ;
}
static int F_202 ( struct V_86 * V_86 , int V_146 , const struct V_104 * V_241 ,
unsigned int V_242 , T_8 V_311 , V_166 V_168 ,
V_166 V_142 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_109 ;
T_1 V_58 ;
T_5 V_24 ;
unsigned long V_312 ;
F_29 () ;
if ( V_242 > 128 )
return - V_287 ;
if ( ! V_142 || V_168 > V_142 )
return - V_287 ;
V_7 = F_197 ( V_86 , V_146 ) ;
if ( ! V_7 )
return - V_117 ;
V_5 = F_185 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return F_84 ( V_5 ) ;
V_109 = F_203 ( V_241 ) ;
V_312 = F_107 ( V_142 , V_3 ) ;
if ( F_189 ( V_312 ) ) {
V_24 = F_190 ( V_312 * V_3 ) ;
V_142 = V_312 ;
V_58 = V_147 ;
} else {
V_24 = 0 ;
V_58 = 0 ;
V_311 |= V_140 ;
}
V_312 = F_107 ( V_168 , V_3 ) ;
if ( F_189 ( V_312 ) ) {
if ( V_312 == 0 )
V_311 |= V_189 ;
V_168 = V_312 ;
}
V_14 = F_76 ( V_5 , V_241 , V_242 , V_109 , V_311 ) ;
if ( ! F_83 ( V_14 ) ) {
F_98 ( & V_14 -> V_48 ) ;
V_14 -> V_142 = V_142 ;
V_14 -> V_168 = V_168 ;
V_14 -> V_78 = V_25 ;
F_99 ( & V_14 -> V_48 ) ;
F_179 ( & V_14 -> V_102 , V_14 -> V_128 , V_7 ,
V_24 , V_58 ) ;
F_119 ( V_14 , 0 ) ;
F_103 ( V_14 ) ;
F_192 ( 0 ) ;
return 0 ;
}
return F_84 ( V_14 ) ;
}
static int F_204 ( struct V_86 * V_86 , int V_146 , const struct V_104 * V_241 ,
unsigned int V_242 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_242 > 128 )
return - V_287 ;
V_7 = F_197 ( V_86 , V_146 ) ;
if ( ! V_7 )
return - V_117 ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL )
return - V_313 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_128 == V_242 &&
F_123 ( V_241 , & V_14 -> V_102 ) ) {
F_11 ( V_14 ) ;
F_137 ( & V_5 -> V_48 ) ;
F_97 ( V_14 ) ;
if ( F_22 ( & V_5 -> V_39 ) )
F_205 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_137 ( & V_5 -> V_48 ) ;
return - V_116 ;
}
int F_206 ( struct V_86 * V_86 , void T_6 * V_284 )
{
struct V_285 V_286 ;
int V_111 ;
if ( ! F_207 ( V_314 ) )
return - V_315 ;
if ( F_196 ( & V_286 , V_284 , sizeof( struct V_285 ) ) )
return - V_288 ;
F_195 () ;
V_111 = F_202 ( V_86 , V_286 . V_290 , & V_286 . V_297 ,
V_286 . V_316 , V_140 ,
V_317 , V_317 ) ;
F_62 () ;
return V_111 ;
}
int F_208 ( struct V_86 * V_86 , void T_6 * V_284 )
{
struct V_285 V_286 ;
int V_111 ;
if ( ! F_207 ( V_314 ) )
return - V_315 ;
if ( F_196 ( & V_286 , V_284 , sizeof( struct V_285 ) ) )
return - V_288 ;
F_195 () ;
V_111 = F_204 ( V_86 , V_286 . V_290 , & V_286 . V_297 ,
V_286 . V_316 ) ;
F_62 () ;
return V_111 ;
}
static void F_209 ( struct V_4 * V_5 , const struct V_104 * V_102 ,
int V_242 , int V_109 )
{
struct V_13 * V_14 ;
V_14 = F_76 ( V_5 , V_102 , V_242 , V_109 , V_140 ) ;
if ( ! F_83 ( V_14 ) ) {
F_98 ( & V_14 -> V_48 ) ;
V_14 -> V_58 &= ~ V_85 ;
F_99 ( & V_14 -> V_48 ) ;
F_110 ( V_318 , V_14 ) ;
F_103 ( V_14 ) ;
}
}
static void F_210 ( struct V_4 * V_5 )
{
struct V_104 V_102 ;
struct V_6 * V_7 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_109 ;
F_29 () ;
memset ( & V_102 , 0 , sizeof( struct V_104 ) ) ;
memcpy ( & V_102 . V_106 [ 3 ] , V_5 -> V_7 -> V_231 , 4 ) ;
if ( V_5 -> V_7 -> V_58 & V_259 ) {
V_102 . V_106 [ 0 ] = F_150 ( 0xfe800000 ) ;
V_109 = V_215 ;
} else {
V_109 = V_175 ;
}
if ( V_102 . V_106 [ 3 ] ) {
F_209 ( V_5 , & V_102 , 128 , V_109 ) ;
return;
}
F_211 (net, dev) {
struct V_319 * V_320 = F_212 ( V_7 ) ;
if ( V_320 && ( V_7 -> V_58 & V_81 ) ) {
struct V_321 * V_82 ;
int V_322 = V_109 ;
for ( V_82 = V_320 -> V_323 ; V_82 ; V_82 = V_82 -> V_324 ) {
int V_242 ;
V_102 . V_106 [ 3 ] = V_82 -> V_325 ;
if ( V_82 -> V_326 == V_327 )
continue;
if ( V_82 -> V_326 >= V_328 ) {
if ( V_5 -> V_7 -> V_58 & V_259 )
continue;
V_322 |= V_220 ;
}
if ( V_5 -> V_7 -> V_58 & V_259 )
V_242 = 64 ;
else
V_242 = 96 ;
F_209 ( V_5 , & V_102 , V_242 , V_322 ) ;
}
}
}
}
static void F_213 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_24 ( V_41 L_25 ) ;
return;
}
F_209 ( V_5 , & V_329 , 128 , V_220 ) ;
}
static void F_214 ( struct V_4 * V_5 , const struct V_104 * V_102 )
{
struct V_13 * V_14 ;
T_1 V_160 = V_140 ;
#ifdef F_191
if ( V_5 -> V_49 . V_279 &&
! F_32 ( V_5 -> V_7 ) -> V_28 . V_94 -> V_55 )
V_160 |= V_130 ;
#endif
V_14 = F_76 ( V_5 , V_102 , 64 , V_215 , V_160 ) ;
if ( ! F_83 ( V_14 ) ) {
F_179 ( & V_14 -> V_102 , V_14 -> V_128 , V_5 -> V_7 , 0 , 0 ) ;
F_119 ( V_14 , 0 ) ;
F_103 ( V_14 ) ;
}
}
static void F_215 ( struct V_6 * V_7 )
{
struct V_104 V_102 ;
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_235 ) &&
( V_7 -> type != V_236 ) &&
( V_7 -> type != V_237 ) &&
( V_7 -> type != V_238 ) &&
( V_7 -> type != V_239 ) ) {
return;
}
V_5 = F_185 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return;
memset ( & V_102 , 0 , sizeof( struct V_104 ) ) ;
V_102 . V_106 [ 0 ] = F_150 ( 0xFE800000 ) ;
if ( F_151 ( V_102 . V_161 + 8 , V_7 ) == 0 )
F_214 ( V_5 , & V_102 ) ;
}
static void F_216 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_24 ( V_41 L_26 ) ;
return;
}
if ( V_7 -> V_65 & V_66 ) {
struct V_104 V_102 ;
F_182 ( & V_102 , F_150 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_179 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_151 ( V_102 . V_161 + 8 , V_7 ) )
F_214 ( V_5 , & V_102 ) ;
return;
}
F_210 ( V_5 ) ;
if ( V_7 -> V_58 & V_259 ) {
F_181 ( V_7 ) ;
F_184 ( V_7 ) ;
} else
F_183 ( V_7 ) ;
}
static inline int
F_217 ( struct V_4 * V_5 , struct V_6 * V_330 )
{
struct V_104 V_331 ;
if ( ! F_138 ( V_330 , & V_331 , V_85 ) ) {
F_214 ( V_5 , & V_331 ) ;
return 0 ;
}
return - 1 ;
}
static void F_218 ( struct V_4 * V_5 )
{
struct V_6 * V_330 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_332 &&
( V_330 = F_197 ( V_86 , V_5 -> V_7 -> V_332 ) ) ) {
if ( ! F_217 ( V_5 , V_330 ) )
return;
}
F_211 (net, link_dev) {
if ( ! F_217 ( V_5 , V_330 ) )
return;
}
F_24 ( V_41 L_27 ) ;
}
static void F_219 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_185 ( V_7 ) ;
if ( F_83 ( V_5 ) ) {
F_24 ( V_41 L_28 ) ;
return;
}
F_218 ( V_5 ) ;
}
static int F_220 ( struct V_333 * V_334 , unsigned long V_335 ,
void * V_127 )
{
struct V_6 * V_7 = (struct V_6 * ) V_127 ;
struct V_4 * V_5 = F_48 ( V_7 ) ;
int V_336 = 0 ;
int V_111 ;
switch ( V_335 ) {
case V_337 :
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! V_5 )
return F_221 ( - V_38 ) ;
}
break;
case V_135 :
case V_338 :
if ( V_7 -> V_58 & V_339 )
break;
if ( V_335 == V_135 ) {
if ( ! F_4 ( V_7 ) ) {
F_24 ( V_67
L_29
L_30 ,
V_7 -> V_42 ) ;
break;
}
if ( ! V_5 && V_7 -> V_46 >= V_47 )
V_5 = F_28 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_76 |= V_77 ;
V_336 = 1 ;
}
} else {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_76 & V_77 )
break;
V_5 -> V_76 |= V_77 ;
}
F_24 ( V_67
L_31
L_32 ,
V_7 -> V_42 ) ;
V_336 = 1 ;
}
switch ( V_7 -> type ) {
#if F_40 ( V_62 ) || F_40 ( V_63 )
case V_64 :
F_216 ( V_7 ) ;
break;
#endif
case V_73 :
F_219 ( V_7 ) ;
break;
case V_340 :
F_213 ( V_7 ) ;
break;
default:
F_215 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_336 )
F_222 ( V_5 ) ;
if ( V_5 -> V_49 . V_51 != V_7 -> V_46 &&
V_7 -> V_46 >= V_47 ) {
F_223 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
}
V_5 -> V_78 = V_25 ;
F_224 ( V_341 , V_5 ) ;
if ( V_7 -> V_46 < V_47 )
F_205 ( V_7 , 1 ) ;
}
break;
case V_342 :
if ( V_5 && V_7 -> V_46 >= V_47 ) {
F_223 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
break;
}
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
break;
}
case V_144 :
case V_343 :
F_205 ( V_7 , V_335 != V_144 ) ;
break;
case V_344 :
if ( V_5 ) {
F_225 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_111 = F_38 ( V_5 ) ;
if ( V_111 )
return F_221 ( V_111 ) ;
}
break;
case V_345 :
case V_346 :
F_226 ( V_7 , V_335 ) ;
break;
}
return V_347 ;
}
static void F_226 ( struct V_6 * V_7 , unsigned long V_335 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_335 == V_346 )
F_227 ( V_5 ) ;
else if ( V_335 == V_345 )
F_228 ( V_5 ) ;
}
static int F_205 ( struct V_6 * V_7 , int V_348 )
{
struct V_86 * V_86 = F_32 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_97 , V_179 ;
F_29 () ;
F_229 ( V_86 , V_7 ) ;
F_230 ( & V_54 , V_7 ) ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 == NULL )
return - V_117 ;
if ( V_348 ) {
V_5 -> V_43 = 1 ;
F_45 ( V_7 -> V_79 , NULL ) ;
F_225 ( V_5 ) ;
}
for ( V_179 = 0 ; V_179 < V_107 ; V_179 ++ ) {
struct V_349 * V_350 = & V_131 [ V_179 ] ;
struct V_218 * V_351 ;
F_98 ( & V_121 ) ;
V_352:
F_140 (ifa, n, h, addr_lst) {
if ( V_82 -> V_5 == V_5 ) {
F_100 ( & V_82 -> V_96 ) ;
F_7 ( V_82 ) ;
goto V_352;
}
}
F_99 ( & V_121 ) ;
}
F_101 ( & V_5 -> V_48 ) ;
if ( ! V_348 )
V_5 -> V_76 &= ~ ( V_353 | V_354 | V_77 ) ;
#ifdef F_41
if ( V_348 && F_8 ( & V_5 -> V_70 ) )
F_66 ( V_5 ) ;
while ( ! F_22 ( & V_5 -> V_69 ) ) {
V_82 = F_231 ( & V_5 -> V_69 ,
struct V_13 , V_133 ) ;
F_102 ( & V_82 -> V_133 ) ;
F_109 ( & V_5 -> V_48 ) ;
F_98 ( & V_82 -> V_48 ) ;
if ( V_82 -> V_139 ) {
F_103 ( V_82 -> V_139 ) ;
V_82 -> V_139 = NULL ;
}
F_99 ( & V_82 -> V_48 ) ;
F_103 ( V_82 ) ;
F_101 ( & V_5 -> V_48 ) ;
}
#endif
while ( ! F_22 ( & V_5 -> V_39 ) ) {
V_82 = F_231 ( & V_5 -> V_39 ,
struct V_13 , V_103 ) ;
F_7 ( V_82 ) ;
F_102 ( & V_82 -> V_103 ) ;
F_109 ( & V_5 -> V_48 ) ;
F_98 ( & V_82 -> V_126 ) ;
V_97 = V_82 -> V_97 ;
V_82 -> V_97 = V_98 ;
F_99 ( & V_82 -> V_126 ) ;
if ( V_97 != V_98 ) {
F_232 ( V_143 , V_82 ) ;
F_96 ( & V_134 , V_144 , V_82 ) ;
}
F_103 ( V_82 ) ;
F_101 ( & V_5 -> V_48 ) ;
}
F_109 ( & V_5 -> V_48 ) ;
if ( V_348 )
F_233 ( V_5 ) ;
else
F_234 ( V_5 ) ;
V_5 -> V_78 = V_25 ;
if ( V_348 ) {
F_3 ( V_5 ) ;
F_37 ( & V_54 , V_5 -> V_53 ) ;
F_230 ( & V_54 , V_7 ) ;
F_66 ( V_5 ) ;
}
return 0 ;
}
static void V_23 ( unsigned long V_127 )
{
struct V_13 * V_14 = (struct V_13 * ) V_127 ;
struct V_4 * V_5 = V_14 -> V_5 ;
F_235 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_76 & V_77 ) )
goto V_123;
if ( V_5 -> V_49 . V_55 )
goto V_123;
if ( V_5 -> V_76 & V_354 )
goto V_123;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_355 ++ < V_5 -> V_49 . V_68 ) {
F_10 ( V_14 , V_22 ,
( V_14 -> V_355 == V_5 -> V_49 . V_68 ) ?
V_5 -> V_49 . V_356 :
V_5 -> V_49 . V_357 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_236 ( V_5 -> V_7 , & V_14 -> V_102 , & V_84 ) ;
} else {
F_90 ( & V_14 -> V_48 ) ;
F_24 ( V_41 L_33 ,
V_5 -> V_7 -> V_42 ) ;
}
V_123:
F_237 ( & V_5 -> V_48 ) ;
F_103 ( V_14 ) ;
}
static void F_238 ( struct V_13 * V_14 )
{
unsigned long V_358 ;
struct V_4 * V_5 = V_14 -> V_5 ;
if ( V_14 -> V_58 & V_130 )
V_358 = 0 ;
else
V_358 = F_239 () % ( V_5 -> V_49 . V_356 ? : 1 ) ;
V_14 -> V_355 = V_5 -> V_49 . V_171 ;
F_10 ( V_14 , V_19 , V_358 ) ;
}
static void F_119 ( struct V_13 * V_14 , T_1 V_58 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_152 ( V_7 , & V_14 -> V_102 ) ;
F_240 ( V_14 -> V_102 . V_106 [ 3 ] ) ;
F_132 ( & V_5 -> V_48 ) ;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_97 == V_98 )
goto V_123;
if ( V_7 -> V_58 & ( V_59 | V_60 ) ||
V_5 -> V_49 . V_61 < 1 ||
! ( V_14 -> V_58 & V_85 ) ||
V_14 -> V_58 & V_359 ) {
V_14 -> V_58 &= ~ ( V_85 | V_130 | V_223 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_137 ( & V_5 -> V_48 ) ;
F_241 ( V_14 ) ;
return;
}
if ( ! ( V_5 -> V_76 & V_77 ) ) {
F_90 ( & V_14 -> V_48 ) ;
F_137 ( & V_5 -> V_48 ) ;
F_11 ( V_14 ) ;
F_146 ( V_14 , 0 ) ;
return;
}
if ( V_14 -> V_58 & V_130 )
F_242 ( V_14 -> V_9 ) ;
F_238 ( V_14 ) ;
V_123:
F_90 ( & V_14 -> V_48 ) ;
F_137 ( & V_5 -> V_48 ) ;
}
static void V_21 ( unsigned long V_127 )
{
struct V_13 * V_14 = (struct V_13 * ) V_127 ;
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_104 V_360 ;
if ( ! V_14 -> V_355 && F_147 ( V_14 ) )
goto V_123;
F_235 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_76 & V_77 ) ) {
F_237 ( & V_5 -> V_48 ) ;
goto V_123;
}
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_97 == V_98 ) {
F_90 ( & V_14 -> V_48 ) ;
F_237 ( & V_5 -> V_48 ) ;
goto V_123;
}
if ( V_14 -> V_355 == 0 ) {
V_14 -> V_58 &= ~ ( V_85 | V_130 | V_223 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_237 ( & V_5 -> V_48 ) ;
F_241 ( V_14 ) ;
goto V_123;
}
V_14 -> V_355 -- ;
F_10 ( V_14 , V_19 , V_14 -> V_5 -> V_53 -> V_172 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_237 ( & V_5 -> V_48 ) ;
F_153 ( & V_14 -> V_102 , & V_360 ) ;
F_243 ( V_14 -> V_5 -> V_7 , NULL , & V_14 -> V_102 , & V_360 , & V_361 ) ;
V_123:
F_103 ( V_14 ) ;
}
static void F_241 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = V_14 -> V_5 -> V_7 ;
F_110 ( V_318 , V_14 ) ;
if ( ( V_14 -> V_5 -> V_49 . V_55 == 0 ||
V_14 -> V_5 -> V_49 . V_55 == 2 ) &&
V_14 -> V_5 -> V_49 . V_68 > 0 &&
( V_7 -> V_58 & V_60 ) == 0 &&
( F_77 ( & V_14 -> V_102 ) & V_268 ) ) {
F_236 ( V_14 -> V_5 -> V_7 , & V_14 -> V_102 , & V_84 ) ;
F_98 ( & V_14 -> V_48 ) ;
V_14 -> V_355 = 1 ;
V_14 -> V_5 -> V_76 |= V_353 ;
F_10 ( V_14 , V_22 , V_14 -> V_5 -> V_49 . V_357 ) ;
F_99 ( & V_14 -> V_48 ) ;
}
}
static void F_222 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_58 & V_85 &&
V_14 -> V_97 == V_225 )
F_238 ( V_14 ) ;
F_90 ( & V_14 -> V_48 ) ;
}
F_137 ( & V_5 -> V_48 ) ;
}
static struct V_13 * F_244 ( struct V_362 * V_363 )
{
struct V_13 * V_82 = NULL ;
struct V_364 * V_97 = V_363 -> V_365 ;
struct V_86 * V_86 = F_245 ( V_363 ) ;
for ( V_97 -> V_366 = 0 ; V_97 -> V_366 < V_107 ; ++ V_97 -> V_366 ) {
struct V_218 * V_351 ;
F_145 (ifa, n, &inet6_addr_lst[state->bucket],
addr_lst)
if ( F_141 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_86 ) )
return V_82 ;
}
return NULL ;
}
static struct V_13 * F_246 ( struct V_362 * V_363 ,
struct V_13 * V_82 )
{
struct V_364 * V_97 = V_363 -> V_365 ;
struct V_86 * V_86 = F_245 ( V_363 ) ;
struct V_218 * V_351 = & V_82 -> V_96 ;
F_247 (ifa, n, addr_lst)
if ( F_141 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_86 ) )
return V_82 ;
while ( ++ V_97 -> V_366 < V_107 ) {
F_145 (ifa, n,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( F_141 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_86 ) )
return V_82 ;
}
}
return NULL ;
}
static struct V_13 * F_248 ( struct V_362 * V_363 , T_9 V_367 )
{
struct V_13 * V_82 = F_244 ( V_363 ) ;
if ( V_82 )
while ( V_367 && ( V_82 = F_246 ( V_363 , V_82 ) ) != NULL )
-- V_367 ;
return V_367 ? NULL : V_82 ;
}
static void * F_249 ( struct V_362 * V_363 , T_9 * V_367 )
__acquires( T_10 )
{
F_79 () ;
return F_248 ( V_363 , * V_367 ) ;
}
static void * F_250 ( struct V_362 * V_363 , void * V_368 , T_9 * V_367 )
{
struct V_13 * V_82 ;
V_82 = F_246 ( V_363 , V_368 ) ;
++ * V_367 ;
return V_82 ;
}
static void F_251 ( struct V_362 * V_363 , void * V_368 )
__releases( T_10 )
{
F_94 () ;
}
static int F_252 ( struct V_362 * V_363 , void * V_368 )
{
struct V_13 * V_14 = (struct V_13 * ) V_368 ;
F_253 ( V_363 , L_34 ,
& V_14 -> V_102 ,
V_14 -> V_5 -> V_7 -> V_146 ,
V_14 -> V_128 ,
V_14 -> V_109 ,
V_14 -> V_58 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
return 0 ;
}
static int F_254 ( struct V_369 * V_369 , struct V_370 * V_370 )
{
return F_255 ( V_369 , V_370 , & V_371 ,
sizeof( struct V_364 ) ) ;
}
static int T_11 F_256 ( struct V_86 * V_86 )
{
if ( ! F_257 ( V_86 , L_35 , V_372 , & V_373 ) )
return - V_38 ;
return 0 ;
}
static void T_12 F_258 ( struct V_86 * V_86 )
{
F_259 ( V_86 , L_35 ) ;
}
int T_13 F_260 ( void )
{
return F_261 ( & V_374 ) ;
}
void F_262 ( void )
{
F_263 ( & V_374 ) ;
}
int F_264 ( struct V_86 * V_86 , const struct V_104 * V_102 )
{
int V_158 = 0 ;
struct V_13 * V_14 = NULL ;
struct V_218 * V_351 ;
unsigned int V_110 = F_74 ( V_102 ) ;
F_79 () ;
F_145 (ifp, n, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_141 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_123 ( & V_14 -> V_102 , V_102 ) &&
( V_14 -> V_58 & V_194 ) ) {
V_158 = 1 ;
break;
}
}
F_94 () ;
return V_158 ;
}
static void F_192 ( unsigned long V_375 )
{
unsigned long V_280 , V_376 , V_377 , V_378 ;
struct V_13 * V_14 ;
struct V_218 * V_219 ;
int V_179 ;
F_79 () ;
F_80 ( & V_379 ) ;
V_280 = V_25 ;
V_376 = F_265 ( V_280 + V_380 ) ;
F_8 ( & V_381 ) ;
for ( V_179 = 0 ; V_179 < V_107 ; V_179 ++ ) {
V_352:
F_145 (ifp, node,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_155 ;
if ( V_14 -> V_58 & V_140 )
continue;
F_80 ( & V_14 -> V_48 ) ;
V_155 = ( V_280 - V_14 -> V_78 + V_382 ) / V_3 ;
if ( V_14 -> V_142 != V_317 &&
V_155 >= V_14 -> V_142 ) {
F_90 ( & V_14 -> V_48 ) ;
F_11 ( V_14 ) ;
F_97 ( V_14 ) ;
goto V_352;
} else if ( V_14 -> V_168 == V_317 ) {
F_90 ( & V_14 -> V_48 ) ;
continue;
} else if ( V_155 >= V_14 -> V_168 ) {
int V_383 = 0 ;
if ( ! ( V_14 -> V_58 & V_189 ) ) {
V_383 = 1 ;
V_14 -> V_58 |= V_189 ;
}
if ( F_108 ( V_14 -> V_78 + V_14 -> V_142 * V_3 , V_376 ) )
V_376 = V_14 -> V_78 + V_14 -> V_142 * V_3 ;
F_90 ( & V_14 -> V_48 ) ;
if ( V_383 ) {
F_11 ( V_14 ) ;
F_110 ( 0 , V_14 ) ;
F_103 ( V_14 ) ;
goto V_352;
}
#ifdef F_41
} else if ( ( V_14 -> V_58 & V_132 ) &&
! ( V_14 -> V_58 & V_85 ) ) {
unsigned long V_156 = V_14 -> V_5 -> V_49 . V_164 *
V_14 -> V_5 -> V_49 . V_171 *
V_14 -> V_5 -> V_53 -> V_172 / V_3 ;
if ( V_155 >= V_14 -> V_168 - V_156 ) {
struct V_13 * V_139 = V_14 -> V_139 ;
if ( F_108 ( V_14 -> V_78 + V_14 -> V_168 * V_3 , V_376 ) )
V_376 = V_14 -> V_78 + V_14 -> V_168 * V_3 ;
if ( ! V_14 -> V_163 && V_139 ) {
V_14 -> V_163 ++ ;
F_11 ( V_14 ) ;
F_11 ( V_139 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_80 ( & V_139 -> V_48 ) ;
V_139 -> V_163 = 0 ;
F_90 ( & V_139 -> V_48 ) ;
F_115 ( V_139 , V_14 ) ;
F_103 ( V_139 ) ;
F_103 ( V_14 ) ;
goto V_352;
}
} else if ( F_108 ( V_14 -> V_78 + V_14 -> V_168 * V_3 - V_156 * V_3 , V_376 ) )
V_376 = V_14 -> V_78 + V_14 -> V_168 * V_3 - V_156 * V_3 ;
F_90 ( & V_14 -> V_48 ) ;
#endif
} else {
if ( F_108 ( V_14 -> V_78 + V_14 -> V_168 * V_3 , V_376 ) )
V_376 = V_14 -> V_78 + V_14 -> V_168 * V_3 ;
F_90 ( & V_14 -> V_48 ) ;
}
}
}
V_377 = F_265 ( V_376 ) ;
V_378 = V_376 ;
if ( F_108 ( V_377 , V_376 + V_384 ) )
V_378 = V_377 ;
if ( F_108 ( V_378 , V_25 + V_385 ) )
V_378 = V_25 + V_385 ;
F_36 ( ( V_41 L_36 ,
V_280 , V_376 , V_377 , V_378 ) ) ;
V_381 . V_24 = V_378 ;
F_12 ( & V_381 ) ;
F_90 ( & V_379 ) ;
F_94 () ;
}
static struct V_104 * F_266 ( struct V_386 * V_102 , struct V_386 * V_387 )
{
struct V_104 * V_241 = NULL ;
if ( V_102 )
V_241 = F_267 ( V_102 ) ;
if ( V_387 ) {
if ( V_241 && F_268 ( V_387 , V_241 , sizeof( * V_241 ) ) )
V_241 = NULL ;
else
V_241 = F_267 ( V_387 ) ;
}
return V_241 ;
}
static int
F_269 ( struct V_388 * V_389 , struct V_390 * V_391 , void * V_284 )
{
struct V_86 * V_86 = F_270 ( V_389 -> V_392 ) ;
struct V_393 * V_394 ;
struct V_386 * V_395 [ V_396 + 1 ] ;
struct V_104 * V_241 ;
int V_111 ;
V_111 = F_271 ( V_391 , sizeof( * V_394 ) , V_395 , V_396 , V_397 ) ;
if ( V_111 < 0 )
return V_111 ;
V_394 = F_272 ( V_391 ) ;
V_241 = F_266 ( V_395 [ V_398 ] , V_395 [ V_399 ] ) ;
if ( V_241 == NULL )
return - V_287 ;
return F_204 ( V_86 , V_394 -> V_400 , V_241 , V_394 -> V_401 ) ;
}
static int F_273 ( struct V_13 * V_14 , T_3 V_311 ,
T_1 V_168 , T_1 V_142 )
{
T_1 V_58 ;
T_5 V_24 ;
unsigned long V_312 ;
if ( ! V_142 || ( V_168 > V_142 ) )
return - V_287 ;
V_312 = F_107 ( V_142 , V_3 ) ;
if ( F_189 ( V_312 ) ) {
V_24 = F_190 ( V_312 * V_3 ) ;
V_142 = V_312 ;
V_58 = V_147 ;
} else {
V_24 = 0 ;
V_58 = 0 ;
V_311 |= V_140 ;
}
V_312 = F_107 ( V_168 , V_3 ) ;
if ( F_189 ( V_312 ) ) {
if ( V_312 == 0 )
V_311 |= V_189 ;
V_168 = V_312 ;
}
F_98 ( & V_14 -> V_48 ) ;
V_14 -> V_58 = ( V_14 -> V_58 & ~ ( V_189 | V_140 | V_359 | V_194 ) ) | V_311 ;
V_14 -> V_78 = V_25 ;
V_14 -> V_142 = V_142 ;
V_14 -> V_168 = V_168 ;
F_99 ( & V_14 -> V_48 ) ;
if ( ! ( V_14 -> V_58 & V_85 ) )
F_110 ( 0 , V_14 ) ;
F_179 ( & V_14 -> V_102 , V_14 -> V_128 , V_14 -> V_5 -> V_7 ,
V_24 , V_58 ) ;
F_192 ( 0 ) ;
return 0 ;
}
static int
F_274 ( struct V_388 * V_389 , struct V_390 * V_391 , void * V_284 )
{
struct V_86 * V_86 = F_270 ( V_389 -> V_392 ) ;
struct V_393 * V_394 ;
struct V_386 * V_395 [ V_396 + 1 ] ;
struct V_104 * V_241 ;
struct V_13 * V_82 ;
struct V_6 * V_7 ;
T_1 V_142 = V_317 , V_402 = V_317 ;
T_3 V_311 ;
int V_111 ;
V_111 = F_271 ( V_391 , sizeof( * V_394 ) , V_395 , V_396 , V_397 ) ;
if ( V_111 < 0 )
return V_111 ;
V_394 = F_272 ( V_391 ) ;
V_241 = F_266 ( V_395 [ V_398 ] , V_395 [ V_399 ] ) ;
if ( V_241 == NULL )
return - V_287 ;
if ( V_395 [ V_403 ] ) {
struct V_404 * V_405 ;
V_405 = F_267 ( V_395 [ V_403 ] ) ;
V_142 = V_405 -> V_406 ;
V_402 = V_405 -> V_407 ;
} else {
V_402 = V_317 ;
V_142 = V_317 ;
}
V_7 = F_197 ( V_86 , V_394 -> V_400 ) ;
if ( V_7 == NULL )
return - V_117 ;
V_311 = V_394 -> V_311 & ( V_359 | V_194 ) ;
V_82 = F_144 ( V_86 , V_241 , V_7 , 1 ) ;
if ( V_82 == NULL ) {
return F_202 ( V_86 , V_394 -> V_400 , V_241 ,
V_394 -> V_401 , V_311 ,
V_402 , V_142 ) ;
}
if ( V_391 -> V_408 & V_409 ||
! ( V_391 -> V_408 & V_410 ) )
V_111 = - V_122 ;
else
V_111 = F_273 ( V_82 , V_311 , V_402 , V_142 ) ;
F_103 ( V_82 ) ;
return V_111 ;
}
static void F_275 ( struct V_390 * V_391 , T_3 V_411 , T_3 V_58 ,
T_3 V_109 , int V_146 )
{
struct V_393 * V_394 ;
V_394 = F_272 ( V_391 ) ;
V_394 -> V_412 = V_413 ;
V_394 -> V_401 = V_411 ;
V_394 -> V_311 = V_58 ;
V_394 -> V_326 = V_109 ;
V_394 -> V_400 = V_146 ;
}
static int F_276 ( struct V_388 * V_389 , unsigned long V_1 ,
unsigned long V_78 , T_1 V_414 , T_1 V_269 )
{
struct V_404 V_405 ;
V_405 . V_1 = F_1 ( V_1 ) ;
V_405 . V_78 = F_1 ( V_78 ) ;
V_405 . V_407 = V_414 ;
V_405 . V_406 = V_269 ;
return F_277 ( V_389 , V_403 , sizeof( V_405 ) , & V_405 ) ;
}
static inline int F_278 ( int V_326 )
{
if ( V_326 & V_220 )
return V_328 ;
else if ( V_326 & V_215 )
return V_327 ;
else if ( V_326 & V_415 )
return V_416 ;
else
return V_417 ;
}
static inline int F_279 ( void )
{
return F_280 ( sizeof( struct V_393 ) )
+ F_281 ( 16 )
+ F_281 ( sizeof( struct V_404 ) ) ;
}
static int F_282 ( struct V_388 * V_389 , struct V_13 * V_82 ,
T_1 V_418 , T_1 V_363 , int V_335 , unsigned int V_58 )
{
struct V_390 * V_391 ;
T_1 V_414 , V_269 ;
V_391 = F_283 ( V_389 , V_418 , V_363 , V_335 , sizeof( struct V_393 ) , V_58 ) ;
if ( V_391 == NULL )
return - V_419 ;
F_275 ( V_391 , V_82 -> V_128 , V_82 -> V_58 , F_278 ( V_82 -> V_109 ) ,
V_82 -> V_5 -> V_7 -> V_146 ) ;
if ( ! ( V_82 -> V_58 & V_140 ) ) {
V_414 = V_82 -> V_168 ;
V_269 = V_82 -> V_142 ;
if ( V_414 != V_317 ) {
long V_420 = ( V_25 - V_82 -> V_78 ) / V_3 ;
if ( V_414 > V_420 )
V_414 -= V_420 ;
else
V_414 = 0 ;
if ( V_269 != V_317 ) {
if ( V_269 > V_420 )
V_269 -= V_420 ;
else
V_269 = 0 ;
}
}
} else {
V_414 = V_317 ;
V_269 = V_317 ;
}
if ( F_277 ( V_389 , V_398 , 16 , & V_82 -> V_102 ) < 0 ||
F_276 ( V_389 , V_82 -> V_1 , V_82 -> V_78 , V_414 , V_269 ) < 0 ) {
F_284 ( V_389 , V_391 ) ;
return - V_419 ;
}
return F_285 ( V_389 , V_391 ) ;
}
static int F_286 ( struct V_388 * V_389 , struct V_421 * V_422 ,
T_1 V_418 , T_1 V_363 , int V_335 , T_14 V_58 )
{
struct V_390 * V_391 ;
T_3 V_109 = V_417 ;
int V_146 = V_422 -> V_5 -> V_7 -> V_146 ;
if ( F_203 ( & V_422 -> V_423 ) & V_415 )
V_109 = V_416 ;
V_391 = F_283 ( V_389 , V_418 , V_363 , V_335 , sizeof( struct V_393 ) , V_58 ) ;
if ( V_391 == NULL )
return - V_419 ;
F_275 ( V_391 , 128 , V_140 , V_109 , V_146 ) ;
if ( F_277 ( V_389 , V_424 , 16 , & V_422 -> V_423 ) < 0 ||
F_276 ( V_389 , V_422 -> V_425 , V_422 -> V_426 ,
V_317 , V_317 ) < 0 ) {
F_284 ( V_389 , V_391 ) ;
return - V_419 ;
}
return F_285 ( V_389 , V_391 ) ;
}
static int F_287 ( struct V_388 * V_389 , struct V_427 * V_428 ,
T_1 V_418 , T_1 V_363 , int V_335 , unsigned int V_58 )
{
struct V_390 * V_391 ;
T_3 V_109 = V_417 ;
int V_146 = V_428 -> V_429 -> V_7 -> V_146 ;
if ( F_203 ( & V_428 -> V_430 ) & V_415 )
V_109 = V_416 ;
V_391 = F_283 ( V_389 , V_418 , V_363 , V_335 , sizeof( struct V_393 ) , V_58 ) ;
if ( V_391 == NULL )
return - V_419 ;
F_275 ( V_391 , 128 , V_140 , V_109 , V_146 ) ;
if ( F_277 ( V_389 , V_431 , 16 , & V_428 -> V_430 ) < 0 ||
F_276 ( V_389 , V_428 -> V_432 , V_428 -> V_433 ,
V_317 , V_317 ) < 0 ) {
F_284 ( V_389 , V_391 ) ;
return - V_419 ;
}
return F_285 ( V_389 , V_391 ) ;
}
static int F_288 ( struct V_4 * V_5 , struct V_388 * V_389 ,
struct V_434 * V_435 , enum V_436 type ,
int V_437 , int * V_438 )
{
struct V_421 * V_422 ;
struct V_427 * V_428 ;
int V_111 = 1 ;
int V_439 = * V_438 ;
F_132 ( & V_5 -> V_48 ) ;
switch ( type ) {
case V_440 : {
struct V_13 * V_82 ;
F_52 (ifa, &idev->addr_list, if_list) {
if ( ++ V_439 < V_437 )
continue;
V_111 = F_282 ( V_389 , V_82 ,
F_289 ( V_435 -> V_389 ) . V_418 ,
V_435 -> V_391 -> V_441 ,
V_318 ,
V_442 ) ;
if ( V_111 <= 0 )
break;
}
break;
}
case V_443 :
for ( V_422 = V_5 -> V_40 ; V_422 ;
V_422 = V_422 -> V_376 , V_439 ++ ) {
if ( V_439 < V_437 )
continue;
V_111 = F_286 ( V_389 , V_422 ,
F_289 ( V_435 -> V_389 ) . V_418 ,
V_435 -> V_391 -> V_441 ,
V_444 ,
V_442 ) ;
if ( V_111 <= 0 )
break;
}
break;
case V_445 :
for ( V_428 = V_5 -> V_446 ; V_428 ;
V_428 = V_428 -> V_447 , V_439 ++ ) {
if ( V_439 < V_437 )
continue;
V_111 = F_287 ( V_389 , V_428 ,
F_289 ( V_435 -> V_389 ) . V_418 ,
V_435 -> V_391 -> V_441 ,
V_448 ,
V_442 ) ;
if ( V_111 <= 0 )
break;
}
break;
default:
break;
}
F_137 ( & V_5 -> V_48 ) ;
* V_438 = V_439 ;
return V_111 ;
}
static int F_290 ( struct V_388 * V_389 , struct V_434 * V_435 ,
enum V_436 type )
{
struct V_86 * V_86 = F_270 ( V_389 -> V_392 ) ;
int V_350 , V_449 ;
int V_450 , V_439 ;
int V_451 , V_437 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_349 * V_452 ;
struct V_218 * V_219 ;
V_449 = V_435 -> args [ 0 ] ;
V_451 = V_450 = V_435 -> args [ 1 ] ;
V_437 = V_439 = V_435 -> args [ 2 ] ;
F_56 () ;
for ( V_350 = V_449 ; V_350 < V_453 ; V_350 ++ , V_451 = 0 ) {
V_450 = 0 ;
V_452 = & V_86 -> V_454 [ V_350 ] ;
F_140 (dev, node, head, index_hlist) {
if ( V_450 < V_451 )
goto V_455;
if ( V_350 > V_449 || V_450 > V_451 )
V_437 = 0 ;
V_439 = 0 ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_455;
if ( F_288 ( V_5 , V_389 , V_435 , type ,
V_437 , & V_439 ) <= 0 )
goto V_456;
V_455:
V_450 ++ ;
}
}
V_456:
F_58 () ;
V_435 -> args [ 0 ] = V_350 ;
V_435 -> args [ 1 ] = V_450 ;
V_435 -> args [ 2 ] = V_439 ;
return V_389 -> V_264 ;
}
static int F_291 ( struct V_388 * V_389 , struct V_434 * V_435 )
{
enum V_436 type = V_440 ;
return F_290 ( V_389 , V_435 , type ) ;
}
static int F_292 ( struct V_388 * V_389 , struct V_434 * V_435 )
{
enum V_436 type = V_443 ;
return F_290 ( V_389 , V_435 , type ) ;
}
static int F_293 ( struct V_388 * V_389 , struct V_434 * V_435 )
{
enum V_436 type = V_445 ;
return F_290 ( V_389 , V_435 , type ) ;
}
static int F_294 ( struct V_388 * V_457 , struct V_390 * V_391 ,
void * V_284 )
{
struct V_86 * V_86 = F_270 ( V_457 -> V_392 ) ;
struct V_393 * V_394 ;
struct V_386 * V_395 [ V_396 + 1 ] ;
struct V_104 * V_102 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_13 * V_82 ;
struct V_388 * V_389 ;
int V_111 ;
V_111 = F_271 ( V_391 , sizeof( * V_394 ) , V_395 , V_396 , V_397 ) ;
if ( V_111 < 0 )
goto V_458;
V_102 = F_266 ( V_395 [ V_398 ] , V_395 [ V_399 ] ) ;
if ( V_102 == NULL ) {
V_111 = - V_287 ;
goto V_458;
}
V_394 = F_272 ( V_391 ) ;
if ( V_394 -> V_400 )
V_7 = F_197 ( V_86 , V_394 -> V_400 ) ;
V_82 = F_144 ( V_86 , V_102 , V_7 , 1 ) ;
if ( ! V_82 ) {
V_111 = - V_116 ;
goto V_458;
}
V_389 = F_295 ( F_279 () , V_33 ) ;
if ( ! V_389 ) {
V_111 = - V_125 ;
goto V_459;
}
V_111 = F_282 ( V_389 , V_82 , F_289 ( V_457 ) . V_418 ,
V_391 -> V_441 , V_318 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_419 ) ;
F_296 ( V_389 ) ;
goto V_459;
}
V_111 = F_297 ( V_389 , V_86 , F_289 ( V_457 ) . V_418 ) ;
V_459:
F_103 ( V_82 ) ;
V_458:
return V_111 ;
}
static void F_298 ( int V_335 , struct V_13 * V_82 )
{
struct V_388 * V_389 ;
struct V_86 * V_86 = F_32 ( V_82 -> V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_389 = F_295 ( F_279 () , V_124 ) ;
if ( V_389 == NULL )
goto V_458;
V_111 = F_282 ( V_389 , V_82 , 0 , 0 , V_335 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_419 ) ;
F_296 ( V_389 ) ;
goto V_458;
}
F_299 ( V_389 , V_86 , 0 , V_460 , NULL , V_124 ) ;
return;
V_458:
if ( V_111 < 0 )
F_300 ( V_86 , V_460 , V_111 ) ;
}
static inline void F_301 ( struct V_461 * V_49 ,
T_2 * V_462 , int V_463 )
{
F_302 ( V_463 < ( V_464 * 4 ) ) ;
memset ( V_462 , 0 , V_463 ) ;
V_462 [ V_465 ] = V_49 -> V_55 ;
V_462 [ V_466 ] = V_49 -> V_467 ;
V_462 [ V_468 ] = V_49 -> V_51 ;
V_462 [ V_469 ] = V_49 -> V_470 ;
V_462 [ V_471 ] = V_49 -> V_472 ;
V_462 [ V_473 ] = V_49 -> V_275 ;
V_462 [ V_474 ] = V_49 -> V_171 ;
V_462 [ V_475 ] = V_49 -> V_68 ;
V_462 [ V_476 ] =
F_303 ( V_49 -> V_357 ) ;
V_462 [ V_477 ] =
F_303 ( V_49 -> V_356 ) ;
V_462 [ V_478 ] = V_49 -> V_479 ;
#ifdef F_41
V_462 [ V_480 ] = V_49 -> V_75 ;
V_462 [ V_481 ] = V_49 -> V_167 ;
V_462 [ V_482 ] = V_49 -> V_169 ;
V_462 [ V_483 ] = V_49 -> V_164 ;
V_462 [ V_484 ] = V_49 -> V_170 ;
#endif
V_462 [ V_485 ] = V_49 -> V_159 ;
V_462 [ V_486 ] = V_49 -> V_487 ;
V_462 [ V_488 ] = V_49 -> V_489 ;
#ifdef F_304
V_462 [ V_490 ] = V_49 -> V_491 ;
V_462 [ V_492 ] =
F_303 ( V_49 -> V_493 ) ;
#ifdef F_305
V_462 [ V_494 ] = V_49 -> V_495 ;
#endif
#endif
V_462 [ V_496 ] = V_49 -> V_497 ;
V_462 [ V_498 ] = V_49 -> V_499 ;
#ifdef F_191
V_462 [ V_500 ] = V_49 -> V_279 ;
#endif
#ifdef F_306
V_462 [ V_501 ] = V_49 -> V_502 ;
#endif
V_462 [ V_503 ] = V_49 -> V_119 ;
V_462 [ V_504 ] = V_49 -> V_61 ;
V_462 [ V_505 ] = V_49 -> V_506 ;
}
static inline T_15 F_307 ( void )
{
return F_281 ( 4 )
+ F_281 ( sizeof( struct V_507 ) )
+ F_281 ( V_464 * 4 )
+ F_281 ( V_508 * 8 )
+ F_281 ( V_509 * 8 ) ;
}
static inline T_15 F_308 ( void )
{
return F_280 ( sizeof( struct V_510 ) )
+ F_281 ( V_511 )
+ F_281 ( V_512 )
+ F_281 ( 4 )
+ F_281 ( 4 )
+ F_281 ( F_307 () ) ;
}
static inline void F_309 ( T_16 * V_27 , T_17 * V_513 ,
int V_514 , int V_463 )
{
int V_179 ;
int V_515 = V_463 - sizeof( T_16 ) * V_514 ;
F_302 ( V_515 < 0 ) ;
F_310 ( V_514 , & V_27 [ 0 ] ) ;
for ( V_179 = 1 ; V_179 < V_514 ; V_179 ++ )
F_310 ( F_311 ( & V_513 [ V_179 ] ) , & V_27 [ V_179 ] ) ;
memset ( & V_27 [ V_514 ] , 0 , V_515 ) ;
}
static inline void F_312 ( T_16 * V_27 , void V_26 * * V_513 ,
int V_514 , int V_463 , T_15 V_516 )
{
int V_179 ;
int V_515 = V_463 - sizeof( T_16 ) * V_514 ;
F_302 ( V_515 < 0 ) ;
F_310 ( V_514 , & V_27 [ 0 ] ) ;
for ( V_179 = 1 ; V_179 < V_514 ; V_179 ++ )
F_310 ( F_313 ( V_513 , V_179 , V_516 ) , & V_27 [ V_179 ] ) ;
memset ( & V_27 [ V_514 ] , 0 , V_515 ) ;
}
static void F_314 ( T_16 * V_27 , struct V_4 * V_5 , int V_517 ,
int V_463 )
{
switch ( V_517 ) {
case V_518 :
F_312 ( V_27 , ( void V_26 * * ) V_5 -> V_27 . V_28 ,
V_508 , V_463 , F_315 ( struct V_29 , V_519 ) ) ;
break;
case V_520 :
F_309 ( V_27 , V_5 -> V_27 . V_31 -> V_521 , V_509 , V_463 ) ;
break;
}
}
static int F_316 ( struct V_388 * V_389 , struct V_4 * V_5 )
{
struct V_386 * V_522 ;
struct V_507 V_405 ;
F_317 ( V_389 , V_523 , V_5 -> V_76 ) ;
V_405 . V_524 = V_525 ;
V_405 . V_78 = F_1 ( V_5 -> V_78 ) ;
V_405 . V_526 = F_303 ( V_5 -> V_53 -> V_526 ) ;
V_405 . V_172 = F_303 ( V_5 -> V_53 -> V_172 ) ;
F_318 ( V_389 , V_527 , sizeof( V_405 ) , & V_405 ) ;
V_522 = F_319 ( V_389 , V_528 , V_464 * sizeof( V_529 ) ) ;
if ( V_522 == NULL )
goto V_530;
F_301 ( & V_5 -> V_49 , F_267 ( V_522 ) , F_320 ( V_522 ) ) ;
V_522 = F_319 ( V_389 , V_518 , V_508 * sizeof( T_16 ) ) ;
if ( V_522 == NULL )
goto V_530;
F_314 ( F_267 ( V_522 ) , V_5 , V_518 , F_320 ( V_522 ) ) ;
V_522 = F_319 ( V_389 , V_520 , V_509 * sizeof( T_16 ) ) ;
if ( V_522 == NULL )
goto V_530;
F_314 ( F_267 ( V_522 ) , V_5 , V_520 , F_320 ( V_522 ) ) ;
return 0 ;
V_530:
return - V_419 ;
}
static T_15 F_321 ( const struct V_6 * V_7 )
{
if ( ! F_48 ( V_7 ) )
return 0 ;
return F_307 () ;
}
static int F_322 ( struct V_388 * V_389 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
return - V_531 ;
if ( F_316 ( V_389 , V_5 ) < 0 )
return - V_419 ;
return 0 ;
}
static int F_323 ( struct V_388 * V_389 , struct V_4 * V_5 ,
T_1 V_418 , T_1 V_363 , int V_335 , unsigned int V_58 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_510 * V_532 ;
struct V_390 * V_391 ;
void * V_533 ;
V_391 = F_283 ( V_389 , V_418 , V_363 , V_335 , sizeof( * V_532 ) , V_58 ) ;
if ( V_391 == NULL )
return - V_419 ;
V_532 = F_272 ( V_391 ) ;
V_532 -> V_534 = V_413 ;
V_532 -> V_535 = 0 ;
V_532 -> V_536 = V_7 -> type ;
V_532 -> V_537 = V_7 -> V_146 ;
V_532 -> V_538 = F_324 ( V_7 ) ;
V_532 -> V_539 = 0 ;
F_325 ( V_389 , V_540 , V_7 -> V_42 ) ;
if ( V_7 -> V_229 )
F_318 ( V_389 , V_541 , V_7 -> V_229 , V_7 -> V_231 ) ;
F_317 ( V_389 , V_542 , V_7 -> V_46 ) ;
if ( V_7 -> V_146 != V_7 -> V_332 )
F_317 ( V_389 , V_543 , V_7 -> V_332 ) ;
V_533 = F_326 ( V_389 , V_544 ) ;
if ( V_533 == NULL )
goto V_530;
if ( F_316 ( V_389 , V_5 ) < 0 )
goto V_530;
F_327 ( V_389 , V_533 ) ;
return F_285 ( V_389 , V_391 ) ;
V_530:
F_284 ( V_389 , V_391 ) ;
return - V_419 ;
}
static int F_328 ( struct V_388 * V_389 , struct V_434 * V_435 )
{
struct V_86 * V_86 = F_270 ( V_389 -> V_392 ) ;
int V_350 , V_449 ;
int V_450 = 0 , V_451 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_349 * V_452 ;
struct V_218 * V_219 ;
V_449 = V_435 -> args [ 0 ] ;
V_451 = V_435 -> args [ 1 ] ;
F_56 () ;
for ( V_350 = V_449 ; V_350 < V_453 ; V_350 ++ , V_451 = 0 ) {
V_450 = 0 ;
V_452 = & V_86 -> V_454 [ V_350 ] ;
F_140 (dev, node, head, index_hlist) {
if ( V_450 < V_451 )
goto V_455;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_455;
if ( F_323 ( V_389 , V_5 ,
F_289 ( V_435 -> V_389 ) . V_418 ,
V_435 -> V_391 -> V_441 ,
V_341 , V_442 ) <= 0 )
goto V_123;
V_455:
V_450 ++ ;
}
}
V_123:
F_58 () ;
V_435 -> args [ 1 ] = V_450 ;
V_435 -> args [ 0 ] = V_350 ;
return V_389 -> V_264 ;
}
void F_224 ( int V_335 , struct V_4 * V_5 )
{
struct V_388 * V_389 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_389 = F_295 ( F_308 () , V_124 ) ;
if ( V_389 == NULL )
goto V_458;
V_111 = F_323 ( V_389 , V_5 , 0 , 0 , V_335 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_419 ) ;
F_296 ( V_389 ) ;
goto V_458;
}
F_299 ( V_389 , V_86 , 0 , V_545 , NULL , V_124 ) ;
return;
V_458:
if ( V_111 < 0 )
F_300 ( V_86 , V_545 , V_111 ) ;
}
static inline T_15 F_329 ( void )
{
return F_280 ( sizeof( struct V_546 ) )
+ F_281 ( sizeof( struct V_104 ) )
+ F_281 ( sizeof( struct V_547 ) ) ;
}
static int F_330 ( struct V_388 * V_389 , struct V_4 * V_5 ,
struct V_265 * V_266 , T_1 V_418 , T_1 V_363 ,
int V_335 , unsigned int V_58 )
{
struct V_546 * V_548 ;
struct V_390 * V_391 ;
struct V_547 V_405 ;
V_391 = F_283 ( V_389 , V_418 , V_363 , V_335 , sizeof( * V_548 ) , V_58 ) ;
if ( V_391 == NULL )
return - V_419 ;
V_548 = F_272 ( V_391 ) ;
V_548 -> V_549 = V_413 ;
V_548 -> V_550 = 0 ;
V_548 -> V_551 = 0 ;
V_548 -> V_552 = V_5 -> V_7 -> V_146 ;
V_548 -> V_128 = V_266 -> V_128 ;
V_548 -> V_553 = V_266 -> type ;
V_548 -> V_554 = 0 ;
V_548 -> V_555 = 0 ;
if ( V_266 -> V_138 )
V_548 -> V_555 |= V_556 ;
if ( V_266 -> V_275 )
V_548 -> V_555 |= V_557 ;
F_318 ( V_389 , V_558 , sizeof( V_266 -> V_145 ) , & V_266 -> V_145 ) ;
V_405 . V_559 = F_187 ( V_266 -> V_270 ) ;
V_405 . V_560 = F_187 ( V_266 -> V_269 ) ;
F_318 ( V_389 , V_561 , sizeof( V_405 ) , & V_405 ) ;
return F_285 ( V_389 , V_391 ) ;
V_530:
F_284 ( V_389 , V_391 ) ;
return - V_419 ;
}
static void F_193 ( int V_335 , struct V_4 * V_5 ,
struct V_265 * V_266 )
{
struct V_388 * V_389 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_389 = F_295 ( F_329 () , V_124 ) ;
if ( V_389 == NULL )
goto V_458;
V_111 = F_330 ( V_389 , V_5 , V_266 , 0 , 0 , V_335 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_419 ) ;
F_296 ( V_389 ) ;
goto V_458;
}
F_299 ( V_389 , V_86 , 0 , V_562 , NULL , V_124 ) ;
return;
V_458:
if ( V_111 < 0 )
F_300 ( V_86 , V_562 , V_111 ) ;
}
static void F_232 ( int V_335 , struct V_13 * V_14 )
{
F_298 ( V_335 ? : V_318 , V_14 ) ;
switch ( V_335 ) {
case V_318 :
if ( ! ( V_14 -> V_9 -> V_563 ) )
F_242 ( V_14 -> V_9 ) ;
if ( V_14 -> V_5 -> V_49 . V_55 )
F_53 ( V_14 ) ;
break;
case V_143 :
if ( V_14 -> V_5 -> V_49 . V_55 )
F_54 ( V_14 ) ;
F_154 ( V_14 -> V_5 , & V_14 -> V_102 ) ;
F_331 ( & V_14 -> V_9 -> V_99 ) ;
if ( F_113 ( V_14 -> V_9 ) )
F_332 ( & V_14 -> V_9 -> V_99 ) ;
break;
}
}
static void F_110 ( int V_335 , struct V_13 * V_14 )
{
F_79 () ;
if ( F_95 ( V_14 -> V_5 -> V_43 == 0 ) )
F_232 ( V_335 , V_14 ) ;
F_94 () ;
}
static
int F_333 ( V_89 * V_564 , int V_565 ,
void T_6 * V_566 , T_15 * V_567 , T_9 * V_568 )
{
int * V_569 = V_564 -> V_127 ;
int V_570 = * V_569 ;
T_9 V_367 = * V_568 ;
int V_158 ;
V_158 = F_334 ( V_564 , V_565 , V_566 , V_567 , V_568 ) ;
if ( V_565 )
V_158 = F_59 ( V_564 , V_569 , V_570 ) ;
if ( V_158 )
* V_568 = V_367 ;
return V_158 ;
}
static void F_335 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_49 . V_119 )
F_220 ( NULL , V_144 , V_5 -> V_7 ) ;
else
F_220 ( NULL , V_135 , V_5 -> V_7 ) ;
}
static void F_336 ( struct V_86 * V_86 , T_2 V_87 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_56 () ;
F_57 (net, dev) {
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
int V_88 = ( ! V_5 -> V_49 . V_119 ) ^ ( ! V_87 ) ;
V_5 -> V_49 . V_119 = V_87 ;
if ( V_88 )
F_335 ( V_5 ) ;
}
}
F_58 () ;
}
static int F_337 ( struct V_89 * V_90 , int * V_91 , int V_92 )
{
struct V_86 * V_86 ;
V_86 = (struct V_86 * ) V_90 -> V_93 ;
if ( V_91 == & V_86 -> V_28 . V_50 -> V_119 )
return 0 ;
if ( ! F_60 () ) {
* V_91 = V_92 ;
return F_61 () ;
}
if ( V_91 == & V_86 -> V_28 . V_94 -> V_119 ) {
T_2 V_87 = V_86 -> V_28 . V_94 -> V_119 ;
V_86 -> V_28 . V_50 -> V_119 = V_87 ;
F_336 ( V_86 , V_87 ) ;
} else if ( ( ! * V_91 ) ^ ( ! V_92 ) )
F_335 ( (struct V_4 * ) V_90 -> V_95 ) ;
F_62 () ;
return 0 ;
}
static
int F_338 ( V_89 * V_564 , int V_565 ,
void T_6 * V_566 , T_15 * V_567 , T_9 * V_568 )
{
int * V_569 = V_564 -> V_127 ;
int V_570 = * V_569 ;
T_9 V_367 = * V_568 ;
int V_158 ;
V_158 = F_334 ( V_564 , V_565 , V_566 , V_567 , V_568 ) ;
if ( V_565 )
V_158 = F_337 ( V_564 , V_569 , V_570 ) ;
if ( V_158 )
* V_568 = V_367 ;
return V_158 ;
}
static int F_339 ( struct V_86 * V_86 , char * V_571 ,
struct V_4 * V_5 , struct V_461 * V_91 )
{
int V_179 ;
struct V_572 * V_573 ;
#define F_340 3
struct V_574 V_575 [] = {
{ . V_576 = L_37 , } ,
{ . V_576 = L_38 , } ,
{ . V_576 = L_39 , } ,
{ } ,
{ } ,
} ;
V_573 = F_341 ( & V_577 , sizeof( * V_573 ) , V_33 ) ;
if ( V_573 == NULL )
goto V_123;
for ( V_179 = 0 ; V_573 -> V_578 [ V_179 ] . V_127 ; V_179 ++ ) {
V_573 -> V_578 [ V_179 ] . V_127 += ( char * ) V_91 - ( char * ) & V_461 ;
V_573 -> V_578 [ V_179 ] . V_95 = V_5 ;
V_573 -> V_578 [ V_179 ] . V_93 = V_86 ;
}
V_573 -> V_571 = F_342 ( V_571 , V_33 ) ;
if ( ! V_573 -> V_571 )
goto free;
V_575 [ F_340 ] . V_576 = V_573 -> V_571 ;
V_573 -> V_579 = F_343 ( V_86 , V_575 ,
V_573 -> V_578 ) ;
if ( V_573 -> V_579 == NULL )
goto V_580;
V_91 -> V_52 = V_573 ;
return 0 ;
V_580:
F_17 ( V_573 -> V_571 ) ;
free:
F_17 ( V_573 ) ;
V_123:
return - V_125 ;
}
static void F_344 ( struct V_461 * V_91 )
{
struct V_572 * V_573 ;
if ( V_91 -> V_52 == NULL )
return;
V_573 = V_91 -> V_52 ;
V_91 -> V_52 = NULL ;
F_345 ( V_573 -> V_579 ) ;
F_17 ( V_573 -> V_571 ) ;
F_17 ( V_573 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_346 ( V_5 -> V_7 , V_5 -> V_53 , L_38 ,
& V_581 ) ;
F_339 ( F_32 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_42 ,
V_5 , & V_5 -> V_49 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_344 ( & V_5 -> V_49 ) ;
F_347 ( V_5 -> V_53 ) ;
}
static int T_11 F_348 ( struct V_86 * V_86 )
{
int V_111 ;
struct V_461 * V_582 , * V_583 ;
V_111 = - V_38 ;
V_582 = & V_461 ;
V_583 = & V_584 ;
if ( ! F_141 ( V_86 , & V_585 ) ) {
V_582 = F_341 ( V_582 , sizeof( V_461 ) , V_33 ) ;
if ( V_582 == NULL )
goto V_586;
V_583 = F_341 ( V_583 , sizeof( V_584 ) , V_33 ) ;
if ( V_583 == NULL )
goto V_587;
} else {
V_583 -> V_275 = V_588 . V_275 ;
V_583 -> V_119 = V_588 . V_119 ;
}
V_86 -> V_28 . V_94 = V_582 ;
V_86 -> V_28 . V_50 = V_583 ;
#ifdef F_349
V_111 = F_339 ( V_86 , L_40 , NULL , V_582 ) ;
if ( V_111 < 0 )
goto V_589;
V_111 = F_339 ( V_86 , L_41 , NULL , V_583 ) ;
if ( V_111 < 0 )
goto V_590;
#endif
return 0 ;
#ifdef F_349
V_590:
F_344 ( V_582 ) ;
V_589:
F_17 ( V_583 ) ;
#endif
V_587:
F_17 ( V_582 ) ;
V_586:
return V_111 ;
}
static void T_12 F_350 ( struct V_86 * V_86 )
{
#ifdef F_349
F_344 ( V_86 -> V_28 . V_50 ) ;
F_344 ( V_86 -> V_28 . V_94 ) ;
#endif
if ( ! F_141 ( V_86 , & V_585 ) ) {
F_17 ( V_86 -> V_28 . V_50 ) ;
F_17 ( V_86 -> V_28 . V_94 ) ;
}
}
int F_351 ( struct V_333 * V_591 )
{
return F_352 ( & V_134 , V_591 ) ;
}
int F_353 ( struct V_333 * V_591 )
{
return F_354 ( & V_134 , V_591 ) ;
}
int T_13 F_355 ( void )
{
int V_179 , V_111 ;
V_111 = F_356 () ;
if ( V_111 < 0 ) {
F_24 ( V_592 L_42
L_43 , V_111 ) ;
goto V_123;
}
V_111 = F_261 ( & V_593 ) ;
if ( V_111 < 0 )
goto V_594;
F_195 () ;
if ( ! F_28 ( V_585 . V_595 ) )
V_111 = - V_38 ;
F_62 () ;
if ( V_111 )
goto V_596;
for ( V_179 = 0 ; V_179 < V_107 ; V_179 ++ )
F_357 ( & V_131 [ V_179 ] ) ;
F_358 ( & V_597 ) ;
F_192 ( 0 ) ;
V_111 = F_359 ( & V_598 ) ;
if ( V_111 < 0 )
goto V_599;
V_111 = F_360 ( V_600 , V_601 , NULL , F_328 ) ;
if ( V_111 < 0 )
goto V_458;
F_360 ( V_600 , V_318 , F_274 , NULL ) ;
F_360 ( V_600 , V_143 , F_269 , NULL ) ;
F_360 ( V_600 , V_602 , F_294 , F_291 ) ;
F_360 ( V_600 , V_444 , NULL , F_292 ) ;
F_360 ( V_600 , V_448 , NULL , F_293 ) ;
F_361 () ;
return 0 ;
V_458:
F_362 ( & V_598 ) ;
V_599:
F_363 ( & V_597 ) ;
V_596:
F_263 ( & V_593 ) ;
V_594:
F_364 () ;
V_123:
return V_111 ;
}
void F_365 ( void )
{
struct V_6 * V_7 ;
int V_179 ;
F_363 ( & V_597 ) ;
F_263 ( & V_593 ) ;
F_364 () ;
F_195 () ;
F_366 ( & V_598 ) ;
F_211 (&init_net, dev) {
if ( F_48 ( V_7 ) == NULL )
continue;
F_205 ( V_7 , 1 ) ;
}
F_205 ( V_585 . V_595 , 2 ) ;
F_98 ( & V_121 ) ;
for ( V_179 = 0 ; V_179 < V_107 ; V_179 ++ )
F_21 ( ! F_367 ( & V_131 [ V_179 ] ) ) ;
F_99 ( & V_121 ) ;
F_8 ( & V_381 ) ;
F_62 () ;
}
