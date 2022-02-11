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
F_25 ( V_7 ) ;
F_17 ( V_45 ) ;
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
if ( F_89 ( & V_9 -> V_99 ) == NULL )
V_82 -> V_58 &= ~ V_129 ;
V_82 -> V_5 = V_5 ;
F_39 ( V_5 ) ;
F_11 ( V_82 ) ;
V_110 = F_74 ( V_102 ) ;
F_90 ( & V_82 -> V_96 , & V_130 [ V_110 ] ) ;
F_91 ( & V_121 ) ;
F_92 ( & V_5 -> V_48 ) ;
F_69 ( V_5 , V_82 ) ;
#ifdef F_41
if ( V_82 -> V_58 & V_131 ) {
F_93 ( & V_82 -> V_132 , & V_5 -> V_69 ) ;
F_11 ( V_82 ) ;
}
#endif
F_11 ( V_82 ) ;
F_94 ( & V_5 -> V_48 ) ;
V_118:
F_95 () ;
if ( F_96 ( V_111 == 0 ) )
F_97 ( & V_133 , V_134 , V_82 ) ;
else {
F_17 ( V_82 ) ;
V_82 = F_78 ( V_111 ) ;
}
return V_82 ;
V_123:
F_91 ( & V_121 ) ;
goto V_118;
}
static void F_98 ( struct V_13 * V_14 )
{
struct V_13 * V_82 , * V_135 ;
struct V_4 * V_5 = V_14 -> V_5 ;
int V_97 ;
int V_136 = 0 , V_137 = 0 ;
unsigned long V_24 = V_25 ;
F_99 ( & V_14 -> V_126 ) ;
V_97 = V_14 -> V_97 ;
V_14 -> V_97 = V_98 ;
F_100 ( & V_14 -> V_126 ) ;
if ( V_97 == V_98 )
goto V_123;
F_99 ( & V_121 ) ;
F_101 ( & V_14 -> V_96 ) ;
F_100 ( & V_121 ) ;
F_102 ( & V_5 -> V_48 ) ;
#ifdef F_41
if ( V_14 -> V_58 & V_131 ) {
F_103 ( & V_14 -> V_132 ) ;
if ( V_14 -> V_138 ) {
F_104 ( V_14 -> V_138 ) ;
V_14 -> V_138 = NULL ;
}
F_9 ( V_14 ) ;
}
#endif
F_105 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_82 == V_14 ) {
F_106 ( & V_14 -> V_103 ) ;
F_9 ( V_14 ) ;
if ( ! ( V_14 -> V_58 & V_139 ) || V_137 > 0 )
break;
V_136 = 1 ;
continue;
} else if ( V_14 -> V_58 & V_139 ) {
if ( F_107 ( & V_82 -> V_102 , & V_14 -> V_102 ,
V_14 -> V_128 ) ) {
if ( V_82 -> V_58 & V_139 ) {
V_137 = 1 ;
if ( V_136 )
break;
} else {
unsigned long V_140 ;
if ( ! V_137 )
V_137 = - 1 ;
F_80 ( & V_82 -> V_48 ) ;
V_140 = F_108 ( V_82 -> V_141 , V_3 ) ;
if ( F_109 ( V_24 ,
V_82 -> V_78 + V_140 * V_3 ) )
V_24 = V_82 -> V_78 + V_140 * V_3 ;
F_91 ( & V_82 -> V_48 ) ;
}
}
}
}
F_110 ( & V_5 -> V_48 ) ;
F_7 ( V_14 ) ;
F_111 ( V_142 , V_14 ) ;
F_97 ( & V_133 , V_143 , V_14 ) ;
if ( ( V_14 -> V_58 & V_139 ) && V_137 < 1 ) {
struct V_104 V_144 ;
struct V_8 * V_9 ;
struct V_86 * V_86 = F_32 ( V_14 -> V_5 -> V_7 ) ;
F_112 ( & V_144 , & V_14 -> V_102 , V_14 -> V_128 ) ;
V_9 = F_113 ( V_86 , & V_144 , NULL , V_14 -> V_5 -> V_7 -> V_145 , 1 ) ;
if ( V_9 && F_6 ( V_9 ) ) {
if ( V_137 == 0 ) {
F_114 ( V_9 ) ;
V_9 = NULL ;
} else if ( ! ( V_9 -> V_10 & V_146 ) ) {
V_9 -> V_147 = V_24 ;
V_9 -> V_10 |= V_146 ;
}
}
F_68 ( & V_9 -> V_99 ) ;
}
F_115 ( V_14 ) ;
V_123:
F_104 ( V_14 ) ;
}
static int F_116 ( struct V_13 * V_14 , struct V_13 * V_148 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_104 V_102 , * V_149 ;
unsigned long V_150 , V_151 , V_152 , V_153 , V_154 ;
unsigned long V_155 ;
int V_156 ;
int V_157 = 0 ;
int V_158 ;
T_1 V_159 ;
F_92 ( & V_5 -> V_48 ) ;
if ( V_148 ) {
F_99 ( & V_148 -> V_48 ) ;
memcpy ( & V_102 . V_160 [ 8 ] , & V_148 -> V_102 . V_160 [ 8 ] , 8 ) ;
F_100 ( & V_148 -> V_48 ) ;
V_149 = & V_102 ;
} else {
V_149 = NULL ;
}
V_161:
F_39 ( V_5 ) ;
if ( V_5 -> V_49 . V_75 <= 0 ) {
F_94 ( & V_5 -> V_48 ) ;
F_24 ( V_67
L_12 ) ;
F_66 ( V_5 ) ;
V_157 = - 1 ;
goto V_123;
}
F_99 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_162 ++ >= V_5 -> V_49 . V_163 ) {
V_5 -> V_49 . V_75 = - 1 ;
F_100 ( & V_14 -> V_48 ) ;
F_94 ( & V_5 -> V_48 ) ;
F_24 ( V_56
L_13 ) ;
F_66 ( V_5 ) ;
V_157 = - 1 ;
goto V_123;
}
F_11 ( V_14 ) ;
memcpy ( V_102 . V_160 , V_14 -> V_102 . V_160 , 8 ) ;
if ( F_117 ( V_5 , V_149 ) < 0 ) {
F_100 ( & V_14 -> V_48 ) ;
F_94 ( & V_5 -> V_48 ) ;
F_24 ( V_56
L_14 ) ;
F_104 ( V_14 ) ;
F_66 ( V_5 ) ;
V_157 = - 1 ;
goto V_123;
}
memcpy ( & V_102 . V_160 [ 8 ] , V_5 -> V_164 , 8 ) ;
V_154 = ( V_25 - V_14 -> V_78 ) / V_3 ;
V_151 = F_118 ( V_165 ,
V_14 -> V_141 ,
V_5 -> V_49 . V_166 + V_154 ) ;
V_150 = F_118 ( V_165 ,
V_14 -> V_167 ,
V_5 -> V_49 . V_168 + V_154 -
V_5 -> V_49 . V_169 ) ;
V_156 = V_14 -> V_128 ;
V_158 = V_5 -> V_49 . V_158 ;
V_152 = V_14 -> V_1 ;
V_153 = V_14 -> V_78 ;
F_100 ( & V_14 -> V_48 ) ;
V_155 = V_5 -> V_49 . V_163 *
V_5 -> V_49 . V_170 *
V_5 -> V_53 -> V_171 / V_3 ;
F_94 ( & V_5 -> V_48 ) ;
if ( V_150 <= V_155 ) {
F_104 ( V_14 ) ;
F_66 ( V_5 ) ;
V_157 = - 1 ;
goto V_123;
}
V_159 = V_131 ;
if ( V_14 -> V_58 & V_129 )
V_159 |= V_129 ;
V_148 = ! V_158 ||
F_119 ( V_5 ) < V_158 ?
F_76 ( V_5 , & V_102 , V_156 ,
F_77 ( & V_102 ) & V_172 ,
V_159 ) : NULL ;
if ( ! V_148 || F_83 ( V_148 ) ) {
F_104 ( V_14 ) ;
F_66 ( V_5 ) ;
F_24 ( V_67
L_15 ) ;
V_149 = & V_102 ;
F_92 ( & V_5 -> V_48 ) ;
goto V_161;
}
F_99 ( & V_148 -> V_48 ) ;
V_148 -> V_138 = V_14 ;
V_148 -> V_141 = V_151 ;
V_148 -> V_167 = V_150 ;
V_148 -> V_1 = V_152 ;
V_148 -> V_78 = V_153 ;
F_100 ( & V_148 -> V_48 ) ;
F_120 ( V_148 , 0 ) ;
F_104 ( V_148 ) ;
F_66 ( V_5 ) ;
V_123:
return V_157 ;
}
static inline int F_121 ( int type )
{
if ( type & ( V_173 | V_174 | V_115 ) )
return 1 ;
return 0 ;
}
static int F_122 ( struct V_86 * V_86 ,
struct V_175 * V_176 ,
struct V_177 * V_99 ,
int V_178 )
{
int V_157 ;
if ( V_178 <= V_176 -> V_179 ) {
switch ( V_178 ) {
case V_180 :
V_157 = V_176 -> V_181 ;
break;
case V_182 :
V_157 = V_176 -> V_183 ;
break;
default:
V_157 = ! ! F_123 ( V_178 , V_176 -> V_184 ) ;
}
goto V_123;
}
switch ( V_178 ) {
case V_185 :
V_157 = ! ! V_176 -> V_82 ;
break;
case V_186 :
V_157 = F_124 ( & V_176 -> V_82 -> V_102 , V_99 -> V_102 ) ;
break;
case V_180 :
V_157 = F_125 ( V_176 -> V_112 ) ;
if ( V_157 >= V_99 -> V_109 )
V_157 = - V_157 ;
else
V_157 -= 128 ;
V_176 -> V_181 = V_157 ;
break;
case V_187 :
V_157 = F_121 ( V_176 -> V_112 ) ||
! ( V_176 -> V_82 -> V_58 & ( V_188 | V_129 ) ) ;
break;
#ifdef F_126
case V_189 :
{
int V_190 = ! ( V_99 -> V_191 & V_192 ) ;
V_157 = ! ( V_176 -> V_82 -> V_58 & V_193 ) ^ V_190 ;
break;
}
#endif
case V_194 :
V_157 = ( ! V_99 -> V_145 ||
V_99 -> V_145 == V_176 -> V_82 -> V_5 -> V_7 -> V_145 ) ;
break;
case V_195 :
V_157 = F_127 ( V_86 ,
& V_176 -> V_82 -> V_102 , V_176 -> V_112 ,
V_176 -> V_82 -> V_5 -> V_7 -> V_145 ) == V_99 -> V_196 ;
break;
#ifdef F_41
case V_197 :
{
int V_198 = V_99 -> V_191 & ( V_199 | V_200 ) ?
! ! ( V_99 -> V_191 & V_200 ) :
V_176 -> V_82 -> V_5 -> V_49 . V_75 >= 2 ;
V_157 = ( ! ( V_176 -> V_82 -> V_58 & V_131 ) ) ^ V_198 ;
break;
}
#endif
case V_201 :
V_157 = ! ( F_128 ( & V_176 -> V_82 -> V_102 ) ^
F_128 ( V_99 -> V_102 ) ) ;
break;
case V_182 :
V_176 -> V_183 = V_157 = F_129 ( & V_176 -> V_82 -> V_102 ,
V_99 -> V_102 ) ;
break;
default:
V_157 = 0 ;
}
if ( V_157 )
F_130 ( V_178 , V_176 -> V_184 ) ;
V_176 -> V_179 = V_178 ;
V_123:
return V_157 ;
}
int F_131 ( struct V_86 * V_86 , struct V_6 * V_202 ,
const struct V_104 * V_203 , unsigned int V_191 ,
struct V_104 * V_204 )
{
struct V_175 V_205 [ 2 ] ,
* V_176 = & V_205 [ 0 ] , * V_206 = & V_205 [ 1 ] ;
struct V_177 V_99 ;
struct V_6 * V_7 ;
int V_207 ;
V_207 = F_132 ( V_203 ) ;
V_99 . V_102 = V_203 ;
V_99 . V_145 = V_202 ? V_202 -> V_145 : 0 ;
V_99 . V_109 = F_125 ( V_207 ) ;
V_99 . V_196 = F_127 ( V_86 , V_203 , V_207 , V_99 . V_145 ) ;
V_99 . V_191 = V_191 ;
V_206 -> V_179 = - 1 ;
V_206 -> V_82 = NULL ;
F_56 () ;
F_57 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_207 & V_114 ) ||
V_99 . V_109 <= V_208 ) &&
V_99 . V_145 && V_7 -> V_145 != V_99 . V_145 )
continue;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
continue;
F_133 ( & V_5 -> V_48 ) ;
F_52 (score->ifa, &idev->addr_list, if_list) {
int V_178 ;
if ( ( V_176 -> V_82 -> V_58 & V_85 ) &&
( ! ( V_176 -> V_82 -> V_58 & V_129 ) ) )
continue;
V_176 -> V_112 = F_132 ( & V_176 -> V_82 -> V_102 ) ;
if ( F_134 ( V_176 -> V_112 == V_113 ||
V_176 -> V_112 & V_114 ) ) {
F_135 ( V_41
L_16
L_17 ,
V_7 -> V_42 ) ;
continue;
}
V_176 -> V_179 = - 1 ;
F_136 ( V_176 -> V_184 , V_209 ) ;
for ( V_178 = 0 ; V_178 < V_209 ; V_178 ++ ) {
int V_210 , V_211 ;
V_210 = F_122 ( V_86 , V_206 , & V_99 , V_178 ) ;
V_211 = F_122 ( V_86 , V_176 , & V_99 , V_178 ) ;
if ( V_210 > V_211 ) {
if ( V_178 == V_180 &&
V_176 -> V_181 > 0 ) {
goto V_212;
}
break;
} else if ( V_210 < V_211 ) {
if ( V_206 -> V_82 )
F_104 ( V_206 -> V_82 ) ;
F_11 ( V_176 -> V_82 ) ;
F_137 ( V_206 , V_176 ) ;
V_176 -> V_82 = V_206 -> V_82 ;
break;
}
}
}
V_212:
F_138 ( & V_5 -> V_48 ) ;
}
F_58 () ;
if ( ! V_206 -> V_82 )
return - V_116 ;
F_85 ( V_204 , & V_206 -> V_82 -> V_102 ) ;
F_104 ( V_206 -> V_82 ) ;
return 0 ;
}
int F_139 ( struct V_6 * V_7 , struct V_104 * V_102 ,
unsigned char V_213 )
{
struct V_4 * V_5 ;
int V_111 = - V_116 ;
F_56 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
struct V_13 * V_14 ;
F_133 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_109 == V_214 &&
! ( V_14 -> V_58 & V_213 ) ) {
F_85 ( V_102 , & V_14 -> V_102 ) ;
V_111 = 0 ;
break;
}
}
F_138 ( & V_5 -> V_48 ) ;
}
F_58 () ;
return V_111 ;
}
static int F_119 ( struct V_4 * V_5 )
{
int V_215 = 0 ;
struct V_13 * V_14 ;
F_133 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list)
V_215 ++ ;
F_138 ( & V_5 -> V_48 ) ;
return V_215 ;
}
int F_140 ( struct V_86 * V_86 , const struct V_104 * V_102 ,
struct V_6 * V_7 , int V_216 )
{
struct V_13 * V_14 ;
struct V_217 * V_218 ;
unsigned int V_110 = F_74 ( V_102 ) ;
F_79 () ;
F_141 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_142 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_124 ( & V_14 -> V_102 , V_102 ) &&
! ( V_14 -> V_58 & V_85 ) &&
( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_109 & ( V_214 | V_219 ) || V_216 ) ) ) {
F_95 () ;
return 1 ;
}
}
F_95 () ;
return 0 ;
}
static bool F_81 ( struct V_86 * V_86 , const struct V_104 * V_102 ,
struct V_6 * V_7 )
{
unsigned int V_110 = F_74 ( V_102 ) ;
struct V_13 * V_14 ;
struct V_217 * V_218 ;
F_143 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_142 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_124 ( & V_14 -> V_102 , V_102 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
int F_144 ( const struct V_104 * V_102 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_137 ;
V_137 = 0 ;
F_56 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
F_133 ( & V_5 -> V_48 ) ;
F_52 (ifa, &idev->addr_list, if_list) {
V_137 = F_107 ( V_102 , & V_82 -> V_102 ,
V_82 -> V_128 ) ;
if ( V_137 )
break;
}
F_138 ( & V_5 -> V_48 ) ;
}
F_58 () ;
return V_137 ;
}
struct V_13 * F_145 ( struct V_86 * V_86 , const struct V_104 * V_102 ,
struct V_6 * V_7 , int V_216 )
{
struct V_13 * V_14 , * V_220 = NULL ;
unsigned int V_110 = F_74 ( V_102 ) ;
struct V_217 * V_218 ;
F_79 () ;
F_146 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_142 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_124 ( & V_14 -> V_102 , V_102 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_109 & ( V_214 | V_219 ) || V_216 ) ) {
V_220 = V_14 ;
F_11 ( V_14 ) ;
break;
}
}
}
F_95 () ;
return V_220 ;
}
static void F_147 ( struct V_13 * V_14 , int V_221 )
{
if ( V_14 -> V_58 & V_139 ) {
F_99 ( & V_14 -> V_48 ) ;
F_7 ( V_14 ) ;
V_14 -> V_58 |= V_85 ;
if ( V_221 )
V_14 -> V_58 |= V_222 ;
F_100 ( & V_14 -> V_48 ) ;
if ( V_221 )
F_111 ( 0 , V_14 ) ;
F_104 ( V_14 ) ;
#ifdef F_41
} else if ( V_14 -> V_58 & V_131 ) {
struct V_13 * V_138 ;
F_99 ( & V_14 -> V_48 ) ;
V_138 = V_14 -> V_138 ;
if ( V_138 ) {
F_11 ( V_138 ) ;
F_100 ( & V_14 -> V_48 ) ;
F_116 ( V_138 , V_14 ) ;
F_104 ( V_138 ) ;
} else {
F_100 ( & V_14 -> V_48 ) ;
}
F_98 ( V_14 ) ;
#endif
} else
F_98 ( V_14 ) ;
}
static int F_148 ( struct V_13 * V_14 )
{
int V_111 = - V_223 ;
F_80 ( & V_14 -> V_126 ) ;
if ( V_14 -> V_97 == V_224 ) {
V_14 -> V_97 = V_225 ;
V_111 = 0 ;
}
F_91 ( & V_14 -> V_126 ) ;
return V_111 ;
}
void F_149 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
if ( F_148 ( V_14 ) ) {
F_104 ( V_14 ) ;
return;
}
if ( F_150 () )
F_24 ( V_67 L_18 ,
V_14 -> V_5 -> V_7 -> V_42 , & V_14 -> V_102 ) ;
if ( V_5 -> V_49 . V_61 > 1 && ! V_5 -> V_49 . V_119 ) {
struct V_104 V_102 ;
V_102 . V_106 [ 0 ] = F_151 ( 0xfe800000 ) ;
V_102 . V_106 [ 1 ] = 0 ;
if ( ! F_152 ( V_102 . V_160 + 8 , V_5 -> V_7 ) &&
F_124 ( & V_14 -> V_102 , & V_102 ) ) {
V_5 -> V_49 . V_119 = 1 ;
F_24 ( V_67 L_19 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
}
}
F_147 ( V_14 , 1 ) ;
}
void F_153 ( struct V_6 * V_7 , const struct V_104 * V_102 )
{
struct V_104 V_226 ;
if ( V_7 -> V_58 & ( V_60 | V_59 ) )
return;
F_154 ( V_102 , & V_226 ) ;
F_46 ( V_7 , & V_226 ) ;
}
void F_155 ( struct V_4 * V_5 , const struct V_104 * V_102 )
{
struct V_104 V_226 ;
if ( V_5 -> V_7 -> V_58 & ( V_60 | V_59 ) )
return;
F_154 ( V_102 , & V_226 ) ;
F_156 ( V_5 , & V_226 ) ;
}
static void F_53 ( struct V_13 * V_14 )
{
struct V_104 V_102 ;
if ( V_14 -> V_128 == 127 )
return;
F_112 ( & V_102 , & V_14 -> V_102 , V_14 -> V_128 ) ;
if ( F_157 ( & V_102 ) )
return;
F_158 ( V_14 -> V_5 -> V_7 , & V_102 ) ;
}
static void F_54 ( struct V_13 * V_14 )
{
struct V_104 V_102 ;
if ( V_14 -> V_128 == 127 )
return;
F_112 ( & V_102 , & V_14 -> V_102 , V_14 -> V_128 ) ;
if ( F_157 ( & V_102 ) )
return;
F_159 ( V_14 -> V_5 , & V_102 ) ;
}
static int F_160 ( T_3 * V_227 , struct V_6 * V_7 )
{
if ( V_7 -> V_228 != V_229 )
return - 1 ;
memcpy ( V_227 , V_7 -> V_230 , 3 ) ;
memcpy ( V_227 + 5 , V_7 -> V_230 + 3 , 3 ) ;
if ( V_7 -> V_231 ) {
V_227 [ 3 ] = ( V_7 -> V_231 >> 8 ) & 0xFF ;
V_227 [ 4 ] = V_7 -> V_231 & 0xFF ;
} else {
V_227 [ 3 ] = 0xFF ;
V_227 [ 4 ] = 0xFE ;
V_227 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_161 ( T_3 * V_227 , struct V_6 * V_7 )
{
if ( V_7 -> V_228 != V_232 )
return - 1 ;
memset ( V_227 , 0 , 7 ) ;
V_227 [ 7 ] = * ( T_3 * ) V_7 -> V_230 ;
return 0 ;
}
static int F_162 ( T_3 * V_227 , struct V_6 * V_7 )
{
if ( V_7 -> V_228 != V_233 )
return - 1 ;
memcpy ( V_227 , V_7 -> V_230 + 12 , 8 ) ;
V_227 [ 0 ] |= 2 ;
return 0 ;
}
static int F_163 ( T_3 * V_227 , T_4 V_102 )
{
if ( V_102 == 0 )
return - 1 ;
V_227 [ 0 ] = ( F_164 ( V_102 ) || F_165 ( V_102 ) ||
F_166 ( V_102 ) || F_167 ( V_102 ) ||
F_168 ( V_102 ) || F_169 ( V_102 ) ||
F_170 ( V_102 ) || F_171 ( V_102 ) ||
F_172 ( V_102 ) || F_173 ( V_102 ) ||
F_174 ( V_102 ) ) ? 0x00 : 0x02 ;
V_227 [ 1 ] = 0 ;
V_227 [ 2 ] = 0x5E ;
V_227 [ 3 ] = 0xFE ;
memcpy ( V_227 + 4 , & V_102 , 4 ) ;
return 0 ;
}
static int F_175 ( T_3 * V_227 , struct V_6 * V_7 )
{
if ( V_7 -> V_65 & V_66 )
return F_163 ( V_227 , * ( T_4 * ) V_7 -> V_230 ) ;
return - 1 ;
}
static int F_176 ( T_3 * V_227 , struct V_6 * V_7 )
{
return F_163 ( V_227 , * ( T_4 * ) V_7 -> V_230 ) ;
}
static int F_152 ( T_3 * V_227 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_234 :
case V_235 :
case V_236 :
return F_160 ( V_227 , V_7 ) ;
case V_237 :
return F_161 ( V_227 , V_7 ) ;
case V_238 :
return F_162 ( V_227 , V_7 ) ;
case V_64 :
return F_175 ( V_227 , V_7 ) ;
case V_239 :
return F_176 ( V_227 , V_7 ) ;
}
return - 1 ;
}
static int F_177 ( T_3 * V_227 , struct V_4 * V_5 )
{
int V_111 = - 1 ;
struct V_13 * V_14 ;
F_133 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_109 == V_214 && ! ( V_14 -> V_58 & V_85 ) ) {
memcpy ( V_227 , V_14 -> V_102 . V_160 + 8 , 8 ) ;
V_111 = 0 ;
break;
}
}
F_138 ( & V_5 -> V_48 ) ;
return V_111 ;
}
static int F_178 ( struct V_4 * V_5 )
{
V_240:
F_179 ( V_5 -> V_164 , sizeof( V_5 -> V_164 ) ) ;
V_5 -> V_164 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_164 [ 0 ] == 0xfd &&
( V_5 -> V_164 [ 1 ] & V_5 -> V_164 [ 2 ] & V_5 -> V_164 [ 3 ] & V_5 -> V_164 [ 4 ] & V_5 -> V_164 [ 5 ] & V_5 -> V_164 [ 6 ] ) == 0xff &&
( V_5 -> V_164 [ 7 ] & 0x80 ) )
goto V_240;
if ( ( V_5 -> V_164 [ 0 ] | V_5 -> V_164 [ 1 ] ) == 0 ) {
if ( V_5 -> V_164 [ 2 ] == 0x5e && V_5 -> V_164 [ 3 ] == 0xfe )
goto V_240;
if ( ( V_5 -> V_164 [ 2 ] | V_5 -> V_164 [ 3 ] | V_5 -> V_164 [ 4 ] | V_5 -> V_164 [ 5 ] | V_5 -> V_164 [ 6 ] | V_5 -> V_164 [ 7 ] ) == 0x00 )
goto V_240;
}
return 0 ;
}
static void V_71 ( unsigned long V_127 )
{
struct V_4 * V_5 = (struct V_4 * ) V_127 ;
unsigned long V_24 ;
F_79 () ;
F_102 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 )
goto V_123;
if ( F_178 ( V_5 ) < 0 )
goto V_123;
V_24 = V_25 +
V_5 -> V_49 . V_168 * V_3 -
V_5 -> V_49 . V_163 * V_5 -> V_49 . V_170 * V_5 -> V_53 -> V_171 -
V_5 -> V_49 . V_169 * V_3 ;
if ( F_109 ( V_24 , V_25 ) ) {
F_24 ( V_56
L_20 ,
V_5 -> V_7 -> V_42 ) ;
goto V_123;
}
if ( ! F_180 ( & V_5 -> V_70 , V_24 ) )
F_39 ( V_5 ) ;
V_123:
F_110 ( & V_5 -> V_48 ) ;
F_95 () ;
F_66 ( V_5 ) ;
}
static int F_117 ( struct V_4 * V_5 , struct V_104 * V_149 ) {
int V_157 = 0 ;
if ( V_149 && memcmp ( V_5 -> V_164 , & V_149 -> V_160 [ 8 ] , 8 ) == 0 )
V_157 = F_178 ( V_5 ) ;
return V_157 ;
}
static void
F_181 ( struct V_104 * V_241 , int V_242 , struct V_6 * V_7 ,
unsigned long V_24 , T_1 V_58 )
{
struct V_243 V_244 = {
. V_245 = V_246 ,
. V_247 = V_248 ,
. V_249 = V_7 -> V_145 ,
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
F_182 ( & V_244 ) ;
}
static void F_183 ( struct V_6 * V_7 )
{
struct V_243 V_244 = {
. V_245 = V_261 ,
. V_247 = V_248 ,
. V_249 = V_7 -> V_145 ,
. V_251 = 8 ,
. V_252 = V_253 ,
. V_254 . V_255 = F_32 ( V_7 ) ,
} ;
F_184 ( & V_244 . V_258 , F_151 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_182 ( & V_244 ) ;
}
static void F_185 ( struct V_6 * V_7 )
{
struct V_243 V_244 = {
. V_245 = V_262 ,
. V_247 = V_248 ,
. V_249 = V_7 -> V_145 ,
. V_251 = 96 ,
. V_252 = V_253 | V_260 ,
. V_254 . V_255 = F_32 ( V_7 ) ,
} ;
F_182 ( & V_244 ) ;
}
static void F_186 ( struct V_6 * V_7 )
{
struct V_104 V_102 ;
F_184 ( & V_102 , F_151 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_181 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
}
static struct V_4 * F_187 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
return F_78 ( - V_125 ) ;
if ( V_5 -> V_49 . V_119 )
return F_78 ( - V_120 ) ;
F_183 ( V_7 ) ;
F_186 ( V_7 ) ;
return V_5 ;
}
void F_188 ( struct V_6 * V_7 , T_3 * V_263 , int V_264 )
{
struct V_265 * V_266 ;
V_165 V_141 ;
V_165 V_167 ;
int V_112 ;
struct V_4 * V_267 ;
struct V_86 * V_86 = F_32 ( V_7 ) ;
V_266 = (struct V_265 * ) V_263 ;
if ( V_264 < sizeof( struct V_265 ) ) {
F_36 ( ( L_21 ) ) ;
return;
}
V_112 = F_77 ( & V_266 -> V_144 ) ;
if ( V_112 & ( V_114 | V_268 ) )
return;
V_141 = F_189 ( V_266 -> V_269 ) ;
V_167 = F_189 ( V_266 -> V_270 ) ;
if ( V_167 > V_141 ) {
if ( F_150 () )
F_24 ( V_56 L_22 ) ;
return;
}
V_267 = F_190 ( V_7 ) ;
if ( V_267 == NULL ) {
if ( F_150 () )
F_24 ( V_41 L_23 , V_7 -> V_42 ) ;
return;
}
if ( V_266 -> V_137 ) {
struct V_8 * V_9 ;
unsigned long V_271 ;
if ( V_3 > V_272 )
V_271 = F_108 ( V_141 , V_3 ) ;
else
V_271 = F_108 ( V_141 , V_272 ) ;
if ( F_191 ( V_271 ) )
V_271 *= V_3 ;
V_9 = F_113 ( V_86 , & V_266 -> V_144 , NULL ,
V_7 -> V_145 , 1 ) ;
if ( V_9 && F_6 ( V_9 ) ) {
if ( V_141 == 0 ) {
F_114 ( V_9 ) ;
V_9 = NULL ;
} else if ( F_191 ( V_271 ) ) {
V_9 -> V_147 = V_25 + V_271 ;
V_9 -> V_10 |= V_146 ;
} else {
V_9 -> V_10 &= ~ V_146 ;
V_9 -> V_147 = 0 ;
}
} else if ( V_141 ) {
T_5 V_24 = 0 ;
int V_58 = V_273 | V_274 ;
if ( F_191 ( V_271 ) ) {
V_58 |= V_146 ;
V_24 = F_192 ( V_271 ) ;
}
F_181 ( & V_266 -> V_144 , V_266 -> V_128 ,
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
memcpy ( & V_102 , & V_266 -> V_144 , 8 ) ;
if ( F_152 ( V_102 . V_160 + 8 , V_7 ) &&
F_177 ( V_102 . V_160 + 8 , V_267 ) ) {
F_66 ( V_267 ) ;
return;
}
goto V_278;
}
if ( F_150 () )
F_24 ( V_41 L_24 ,
V_266 -> V_128 ) ;
F_66 ( V_267 ) ;
return;
V_278:
V_14 = F_145 ( V_86 , & V_102 , V_7 , 1 ) ;
if ( V_14 == NULL && V_141 ) {
int V_158 = V_267 -> V_49 . V_158 ;
T_1 V_159 = 0 ;
#ifdef F_193
if ( V_267 -> V_49 . V_279 &&
! V_86 -> V_28 . V_94 -> V_55 )
V_159 = V_129 ;
#endif
if ( ! V_158 ||
F_119 ( V_267 ) < V_158 )
V_14 = F_76 ( V_267 , & V_102 , V_266 -> V_128 ,
V_112 & V_172 ,
V_159 ) ;
if ( ! V_14 || F_83 ( V_14 ) ) {
F_66 ( V_267 ) ;
return;
}
V_277 = V_276 = 1 ;
V_14 -> V_1 = V_25 ;
F_120 ( V_14 , V_273 | V_274 ) ;
}
if ( V_14 ) {
int V_58 ;
unsigned long V_280 ;
#ifdef F_41
struct V_13 * V_148 ;
#endif
T_1 V_281 ;
F_80 ( & V_14 -> V_48 ) ;
V_280 = V_25 ;
if ( V_14 -> V_141 > ( V_280 - V_14 -> V_78 ) / V_3 )
V_281 = V_14 -> V_141 - ( V_280 - V_14 -> V_78 ) / V_3 ;
else
V_281 = 0 ;
if ( ! V_277 && V_281 ) {
if ( V_141 > V_282 ||
V_141 > V_281 )
V_277 = 1 ;
else if ( V_281 <= V_282 ) {
if ( V_167 != V_14 -> V_167 ) {
V_141 = V_281 ;
V_277 = 1 ;
}
} else {
V_141 = V_282 ;
if ( V_141 < V_167 )
V_167 = V_141 ;
V_277 = 1 ;
}
}
if ( V_277 ) {
V_14 -> V_141 = V_141 ;
V_14 -> V_167 = V_167 ;
V_14 -> V_78 = V_280 ;
V_58 = V_14 -> V_58 ;
V_14 -> V_58 &= ~ V_188 ;
F_91 ( & V_14 -> V_48 ) ;
if ( ! ( V_58 & V_85 ) )
F_111 ( 0 , V_14 ) ;
} else
F_91 ( & V_14 -> V_48 ) ;
#ifdef F_41
F_133 ( & V_267 -> V_48 ) ;
F_52 (ift, &in6_dev->tempaddr_list, tmp_list) {
if ( V_14 != V_148 -> V_138 )
continue;
F_80 ( & V_148 -> V_48 ) ;
V_58 = V_148 -> V_58 ;
if ( V_148 -> V_141 > V_141 &&
V_148 -> V_141 - V_141 > ( V_25 - V_148 -> V_78 ) / V_3 )
V_148 -> V_141 = V_141 + ( V_25 - V_148 -> V_78 ) / V_3 ;
if ( V_148 -> V_167 > V_167 &&
V_148 -> V_167 - V_167 > ( V_25 - V_148 -> V_78 ) / V_3 )
V_148 -> V_167 = V_167 + ( V_25 - V_148 -> V_78 ) / V_3 ;
F_91 ( & V_148 -> V_48 ) ;
if ( ! ( V_58 & V_85 ) )
F_111 ( 0 , V_148 ) ;
}
if ( ( V_276 || F_22 ( & V_267 -> V_69 ) ) && V_267 -> V_49 . V_75 > 0 ) {
F_138 ( & V_267 -> V_48 ) ;
F_116 ( V_14 , NULL ) ;
} else {
F_138 ( & V_267 -> V_48 ) ;
}
#endif
F_104 ( V_14 ) ;
F_194 ( 0 ) ;
}
}
F_195 ( V_283 , V_267 , V_266 ) ;
F_66 ( V_267 ) ;
}
int F_196 ( struct V_86 * V_86 , void T_6 * V_284 )
{
struct V_285 V_286 ;
struct V_6 * V_7 ;
int V_111 = - V_287 ;
F_197 () ;
V_111 = - V_288 ;
if ( F_198 ( & V_286 , V_284 , sizeof( struct V_285 ) ) )
goto V_289;
V_7 = F_199 ( V_86 , V_286 . V_290 ) ;
V_111 = - V_117 ;
if ( V_7 == NULL )
goto V_289;
#if F_40 ( V_62 ) || F_40 ( V_63 )
if ( V_7 -> type == V_64 ) {
const struct V_291 * V_292 = V_7 -> V_293 ;
struct V_294 V_295 ;
struct V_296 V_91 ;
V_111 = - V_116 ;
if ( ! ( F_77 ( & V_286 . V_297 ) & V_174 ) )
goto V_289;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_298 . V_203 = V_286 . V_297 . V_106 [ 3 ] ;
V_91 . V_298 . V_204 = 0 ;
V_91 . V_298 . V_299 = 4 ;
V_91 . V_298 . V_300 = 5 ;
V_91 . V_298 . V_301 = V_302 ;
V_91 . V_298 . V_303 = 64 ;
V_295 . V_304 . V_305 = ( V_105 void T_6 * ) & V_91 ;
if ( V_292 -> V_306 ) {
T_7 V_307 = F_200 () ;
F_201 ( V_308 ) ;
V_111 = V_292 -> V_306 ( V_7 , & V_295 , V_309 ) ;
F_201 ( V_307 ) ;
} else
V_111 = - V_310 ;
if ( V_111 == 0 ) {
V_111 = - V_125 ;
V_7 = F_202 ( V_86 , V_91 . V_42 ) ;
if ( ! V_7 )
goto V_289;
V_111 = F_203 ( V_7 ) ;
}
}
#endif
V_289:
F_62 () ;
return V_111 ;
}
static int F_204 ( struct V_86 * V_86 , int V_145 , const struct V_104 * V_241 ,
unsigned int V_242 , T_8 V_311 , V_165 V_167 ,
V_165 V_141 )
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
if ( ! V_141 || V_167 > V_141 )
return - V_287 ;
V_7 = F_199 ( V_86 , V_145 ) ;
if ( ! V_7 )
return - V_117 ;
V_5 = F_187 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return F_84 ( V_5 ) ;
V_109 = F_205 ( V_241 ) ;
V_312 = F_108 ( V_141 , V_3 ) ;
if ( F_191 ( V_312 ) ) {
V_24 = F_192 ( V_312 * V_3 ) ;
V_141 = V_312 ;
V_58 = V_146 ;
} else {
V_24 = 0 ;
V_58 = 0 ;
V_311 |= V_139 ;
}
V_312 = F_108 ( V_167 , V_3 ) ;
if ( F_191 ( V_312 ) ) {
if ( V_312 == 0 )
V_311 |= V_188 ;
V_167 = V_312 ;
}
V_14 = F_76 ( V_5 , V_241 , V_242 , V_109 , V_311 ) ;
if ( ! F_83 ( V_14 ) ) {
F_99 ( & V_14 -> V_48 ) ;
V_14 -> V_141 = V_141 ;
V_14 -> V_167 = V_167 ;
V_14 -> V_78 = V_25 ;
F_100 ( & V_14 -> V_48 ) ;
F_181 ( & V_14 -> V_102 , V_14 -> V_128 , V_7 ,
V_24 , V_58 ) ;
F_120 ( V_14 , 0 ) ;
F_104 ( V_14 ) ;
F_194 ( 0 ) ;
return 0 ;
}
return F_84 ( V_14 ) ;
}
static int F_206 ( struct V_86 * V_86 , int V_145 , const struct V_104 * V_241 ,
unsigned int V_242 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_242 > 128 )
return - V_287 ;
V_7 = F_199 ( V_86 , V_145 ) ;
if ( ! V_7 )
return - V_117 ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL )
return - V_313 ;
F_133 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_128 == V_242 &&
F_124 ( V_241 , & V_14 -> V_102 ) ) {
F_11 ( V_14 ) ;
F_138 ( & V_5 -> V_48 ) ;
F_98 ( V_14 ) ;
if ( F_22 ( & V_5 -> V_39 ) )
F_207 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_138 ( & V_5 -> V_48 ) ;
return - V_116 ;
}
int F_208 ( struct V_86 * V_86 , void T_6 * V_284 )
{
struct V_285 V_286 ;
int V_111 ;
if ( ! F_209 ( V_314 ) )
return - V_315 ;
if ( F_198 ( & V_286 , V_284 , sizeof( struct V_285 ) ) )
return - V_288 ;
F_197 () ;
V_111 = F_204 ( V_86 , V_286 . V_290 , & V_286 . V_297 ,
V_286 . V_316 , V_139 ,
V_317 , V_317 ) ;
F_62 () ;
return V_111 ;
}
int F_210 ( struct V_86 * V_86 , void T_6 * V_284 )
{
struct V_285 V_286 ;
int V_111 ;
if ( ! F_209 ( V_314 ) )
return - V_315 ;
if ( F_198 ( & V_286 , V_284 , sizeof( struct V_285 ) ) )
return - V_288 ;
F_197 () ;
V_111 = F_206 ( V_86 , V_286 . V_290 , & V_286 . V_297 ,
V_286 . V_316 ) ;
F_62 () ;
return V_111 ;
}
static void F_211 ( struct V_4 * V_5 , const struct V_104 * V_102 ,
int V_242 , int V_109 )
{
struct V_13 * V_14 ;
V_14 = F_76 ( V_5 , V_102 , V_242 , V_109 , V_139 ) ;
if ( ! F_83 ( V_14 ) ) {
F_99 ( & V_14 -> V_48 ) ;
V_14 -> V_58 &= ~ V_85 ;
F_100 ( & V_14 -> V_48 ) ;
F_111 ( V_318 , V_14 ) ;
F_104 ( V_14 ) ;
}
}
static void F_212 ( struct V_4 * V_5 )
{
struct V_104 V_102 ;
struct V_6 * V_7 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_109 ;
F_29 () ;
memset ( & V_102 , 0 , sizeof( struct V_104 ) ) ;
memcpy ( & V_102 . V_106 [ 3 ] , V_5 -> V_7 -> V_230 , 4 ) ;
if ( V_5 -> V_7 -> V_58 & V_259 ) {
V_102 . V_106 [ 0 ] = F_151 ( 0xfe800000 ) ;
V_109 = V_214 ;
} else {
V_109 = V_174 ;
}
if ( V_102 . V_106 [ 3 ] ) {
F_211 ( V_5 , & V_102 , 128 , V_109 ) ;
return;
}
F_213 (net, dev) {
struct V_319 * V_320 = F_214 ( V_7 ) ;
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
V_322 |= V_219 ;
}
if ( V_5 -> V_7 -> V_58 & V_259 )
V_242 = 64 ;
else
V_242 = 96 ;
F_211 ( V_5 , & V_102 , V_242 , V_322 ) ;
}
}
}
}
static void F_215 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_24 ( V_41 L_25 ) ;
return;
}
F_211 ( V_5 , & V_329 , 128 , V_219 ) ;
}
static void F_216 ( struct V_4 * V_5 , const struct V_104 * V_102 )
{
struct V_13 * V_14 ;
T_1 V_159 = V_139 ;
#ifdef F_193
if ( V_5 -> V_49 . V_279 &&
! F_32 ( V_5 -> V_7 ) -> V_28 . V_94 -> V_55 )
V_159 |= V_129 ;
#endif
V_14 = F_76 ( V_5 , V_102 , 64 , V_214 , V_159 ) ;
if ( ! F_83 ( V_14 ) ) {
F_181 ( & V_14 -> V_102 , V_14 -> V_128 , V_5 -> V_7 , 0 , 0 ) ;
F_120 ( V_14 , 0 ) ;
F_104 ( V_14 ) ;
}
}
static void F_217 ( struct V_6 * V_7 )
{
struct V_104 V_102 ;
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_234 ) &&
( V_7 -> type != V_235 ) &&
( V_7 -> type != V_236 ) &&
( V_7 -> type != V_237 ) &&
( V_7 -> type != V_238 ) ) {
return;
}
V_5 = F_187 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return;
memset ( & V_102 , 0 , sizeof( struct V_104 ) ) ;
V_102 . V_106 [ 0 ] = F_151 ( 0xFE800000 ) ;
if ( F_152 ( V_102 . V_160 + 8 , V_7 ) == 0 )
F_216 ( V_5 , & V_102 ) ;
}
static void F_218 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_24 ( V_41 L_26 ) ;
return;
}
if ( V_7 -> V_65 & V_66 ) {
struct V_104 V_102 ;
F_184 ( & V_102 , F_151 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_181 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_152 ( V_102 . V_160 + 8 , V_7 ) )
F_216 ( V_5 , & V_102 ) ;
return;
}
F_212 ( V_5 ) ;
if ( V_7 -> V_58 & V_259 ) {
F_183 ( V_7 ) ;
F_186 ( V_7 ) ;
} else
F_185 ( V_7 ) ;
}
static void F_219 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_104 V_102 ;
F_220 ( L_27 , V_7 -> V_42 ) ;
F_29 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_24 ( V_41 L_28 ) ;
return;
}
F_184 ( & V_102 , F_151 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_181 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_152 ( V_102 . V_160 + 8 , V_7 ) )
F_216 ( V_5 , & V_102 ) ;
}
static inline int
F_221 ( struct V_4 * V_5 , struct V_6 * V_330 )
{
struct V_104 V_331 ;
if ( ! F_139 ( V_330 , & V_331 , V_85 ) ) {
F_216 ( V_5 , & V_331 ) ;
return 0 ;
}
return - 1 ;
}
static void F_222 ( struct V_4 * V_5 )
{
struct V_6 * V_330 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_332 &&
( V_330 = F_199 ( V_86 , V_5 -> V_7 -> V_332 ) ) ) {
if ( ! F_221 ( V_5 , V_330 ) )
return;
}
F_213 (net, link_dev) {
if ( ! F_221 ( V_5 , V_330 ) )
return;
}
F_24 ( V_41 L_29 ) ;
}
static void F_223 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_187 ( V_7 ) ;
if ( F_83 ( V_5 ) ) {
F_24 ( V_41 L_30 ) ;
return;
}
F_222 ( V_5 ) ;
}
static int F_224 ( struct V_333 * V_334 , unsigned long V_335 ,
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
return F_225 ( - V_38 ) ;
}
break;
case V_134 :
case V_338 :
if ( V_7 -> V_58 & V_339 )
break;
if ( V_335 == V_134 ) {
if ( ! F_4 ( V_7 ) ) {
F_24 ( V_67
L_31
L_32 ,
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
L_33
L_34 ,
V_7 -> V_42 ) ;
V_336 = 1 ;
}
switch ( V_7 -> type ) {
#if F_40 ( V_62 ) || F_40 ( V_63 )
case V_64 :
F_218 ( V_7 ) ;
break;
#endif
#if F_40 ( V_340 ) || F_40 ( V_341 )
case V_239 :
F_219 ( V_7 ) ;
break;
#endif
case V_73 :
F_223 ( V_7 ) ;
break;
case V_342 :
F_215 ( V_7 ) ;
break;
default:
F_217 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_336 )
F_226 ( V_5 ) ;
if ( V_5 -> V_49 . V_51 != V_7 -> V_46 &&
V_7 -> V_46 >= V_47 ) {
F_227 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
}
V_5 -> V_78 = V_25 ;
F_228 ( V_343 , V_5 ) ;
if ( V_7 -> V_46 < V_47 )
F_207 ( V_7 , 1 ) ;
}
break;
case V_344 :
if ( V_5 && V_7 -> V_46 >= V_47 ) {
F_227 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
break;
}
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
break;
}
case V_143 :
case V_345 :
F_207 ( V_7 , V_335 != V_143 ) ;
break;
case V_346 :
if ( V_5 ) {
F_229 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_111 = F_38 ( V_5 ) ;
if ( V_111 )
return F_225 ( V_111 ) ;
}
break;
case V_347 :
case V_348 :
F_230 ( V_7 , V_335 ) ;
break;
}
return V_349 ;
}
static void F_230 ( struct V_6 * V_7 , unsigned long V_335 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_335 == V_348 )
F_231 ( V_5 ) ;
else if ( V_335 == V_347 )
F_232 ( V_5 ) ;
}
static int F_207 ( struct V_6 * V_7 , int V_350 )
{
struct V_86 * V_86 = F_32 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_97 , V_178 ;
F_29 () ;
F_233 ( V_86 , V_7 ) ;
F_234 ( & V_54 , V_7 ) ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 == NULL )
return - V_117 ;
if ( V_350 ) {
V_5 -> V_43 = 1 ;
F_45 ( V_7 -> V_79 , NULL ) ;
F_229 ( V_5 ) ;
}
for ( V_178 = 0 ; V_178 < V_107 ; V_178 ++ ) {
struct V_351 * V_352 = & V_130 [ V_178 ] ;
struct V_217 * V_353 ;
F_99 ( & V_121 ) ;
V_354:
F_141 (ifa, n, h, addr_lst) {
if ( V_82 -> V_5 == V_5 ) {
F_101 ( & V_82 -> V_96 ) ;
F_7 ( V_82 ) ;
goto V_354;
}
}
F_100 ( & V_121 ) ;
}
F_102 ( & V_5 -> V_48 ) ;
if ( ! V_350 )
V_5 -> V_76 &= ~ ( V_355 | V_356 | V_77 ) ;
#ifdef F_41
if ( V_350 && F_8 ( & V_5 -> V_70 ) )
F_66 ( V_5 ) ;
while ( ! F_22 ( & V_5 -> V_69 ) ) {
V_82 = F_235 ( & V_5 -> V_69 ,
struct V_13 , V_132 ) ;
F_103 ( & V_82 -> V_132 ) ;
F_110 ( & V_5 -> V_48 ) ;
F_99 ( & V_82 -> V_48 ) ;
if ( V_82 -> V_138 ) {
F_104 ( V_82 -> V_138 ) ;
V_82 -> V_138 = NULL ;
}
F_100 ( & V_82 -> V_48 ) ;
F_104 ( V_82 ) ;
F_102 ( & V_5 -> V_48 ) ;
}
#endif
while ( ! F_22 ( & V_5 -> V_39 ) ) {
V_82 = F_235 ( & V_5 -> V_39 ,
struct V_13 , V_103 ) ;
F_7 ( V_82 ) ;
F_103 ( & V_82 -> V_103 ) ;
F_110 ( & V_5 -> V_48 ) ;
F_99 ( & V_82 -> V_126 ) ;
V_97 = V_82 -> V_97 ;
V_82 -> V_97 = V_98 ;
F_100 ( & V_82 -> V_126 ) ;
if ( V_97 != V_98 ) {
F_236 ( V_142 , V_82 ) ;
F_97 ( & V_133 , V_143 , V_82 ) ;
}
F_104 ( V_82 ) ;
F_102 ( & V_5 -> V_48 ) ;
}
F_110 ( & V_5 -> V_48 ) ;
if ( V_350 )
F_237 ( V_5 ) ;
else
F_238 ( V_5 ) ;
V_5 -> V_78 = V_25 ;
if ( V_350 ) {
F_3 ( V_5 ) ;
F_37 ( & V_54 , V_5 -> V_53 ) ;
F_234 ( & V_54 , V_7 ) ;
F_66 ( V_5 ) ;
}
return 0 ;
}
static void V_23 ( unsigned long V_127 )
{
struct V_13 * V_14 = (struct V_13 * ) V_127 ;
struct V_4 * V_5 = V_14 -> V_5 ;
F_239 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_76 & V_77 ) )
goto V_123;
if ( V_5 -> V_49 . V_55 )
goto V_123;
if ( V_5 -> V_76 & V_356 )
goto V_123;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_357 ++ < V_5 -> V_49 . V_68 ) {
F_10 ( V_14 , V_22 ,
( V_14 -> V_357 == V_5 -> V_49 . V_68 ) ?
V_5 -> V_49 . V_358 :
V_5 -> V_49 . V_359 ) ;
F_91 ( & V_14 -> V_48 ) ;
F_240 ( V_5 -> V_7 , & V_14 -> V_102 , & V_84 ) ;
} else {
F_91 ( & V_14 -> V_48 ) ;
F_24 ( V_41 L_35 ,
V_5 -> V_7 -> V_42 ) ;
}
V_123:
F_241 ( & V_5 -> V_48 ) ;
F_104 ( V_14 ) ;
}
static void F_242 ( struct V_13 * V_14 )
{
unsigned long V_360 ;
struct V_4 * V_5 = V_14 -> V_5 ;
if ( V_14 -> V_58 & V_129 )
V_360 = 0 ;
else
V_360 = F_243 () % ( V_5 -> V_49 . V_358 ? : 1 ) ;
V_14 -> V_357 = V_5 -> V_49 . V_170 ;
F_10 ( V_14 , V_19 , V_360 ) ;
}
static void F_120 ( struct V_13 * V_14 , T_1 V_58 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_153 ( V_7 , & V_14 -> V_102 ) ;
F_244 ( V_14 -> V_102 . V_106 [ 3 ] ) ;
F_133 ( & V_5 -> V_48 ) ;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_97 == V_98 )
goto V_123;
if ( V_7 -> V_58 & ( V_59 | V_60 ) ||
V_5 -> V_49 . V_61 < 1 ||
! ( V_14 -> V_58 & V_85 ) ||
V_14 -> V_58 & V_361 ) {
V_14 -> V_58 &= ~ ( V_85 | V_129 | V_222 ) ;
F_91 ( & V_14 -> V_48 ) ;
F_138 ( & V_5 -> V_48 ) ;
F_245 ( V_14 ) ;
return;
}
if ( ! ( V_5 -> V_76 & V_77 ) ) {
F_91 ( & V_14 -> V_48 ) ;
F_138 ( & V_5 -> V_48 ) ;
F_11 ( V_14 ) ;
F_147 ( V_14 , 0 ) ;
return;
}
if ( V_14 -> V_58 & V_129 )
F_246 ( V_14 -> V_9 ) ;
F_242 ( V_14 ) ;
V_123:
F_91 ( & V_14 -> V_48 ) ;
F_138 ( & V_5 -> V_48 ) ;
}
static void V_21 ( unsigned long V_127 )
{
struct V_13 * V_14 = (struct V_13 * ) V_127 ;
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_104 V_362 ;
if ( ! V_14 -> V_357 && F_148 ( V_14 ) )
goto V_123;
F_239 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_76 & V_77 ) ) {
F_241 ( & V_5 -> V_48 ) ;
goto V_123;
}
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_97 == V_98 ) {
F_91 ( & V_14 -> V_48 ) ;
F_241 ( & V_5 -> V_48 ) ;
goto V_123;
}
if ( V_14 -> V_357 == 0 ) {
V_14 -> V_58 &= ~ ( V_85 | V_129 | V_222 ) ;
F_91 ( & V_14 -> V_48 ) ;
F_241 ( & V_5 -> V_48 ) ;
F_245 ( V_14 ) ;
goto V_123;
}
V_14 -> V_357 -- ;
F_10 ( V_14 , V_19 , V_14 -> V_5 -> V_53 -> V_171 ) ;
F_91 ( & V_14 -> V_48 ) ;
F_241 ( & V_5 -> V_48 ) ;
F_154 ( & V_14 -> V_102 , & V_362 ) ;
F_247 ( V_14 -> V_5 -> V_7 , NULL , & V_14 -> V_102 , & V_362 , & V_363 ) ;
V_123:
F_104 ( V_14 ) ;
}
static void F_245 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = V_14 -> V_5 -> V_7 ;
F_111 ( V_318 , V_14 ) ;
if ( ( V_14 -> V_5 -> V_49 . V_55 == 0 ||
V_14 -> V_5 -> V_49 . V_55 == 2 ) &&
V_14 -> V_5 -> V_49 . V_68 > 0 &&
( V_7 -> V_58 & V_60 ) == 0 &&
( F_77 ( & V_14 -> V_102 ) & V_268 ) ) {
F_240 ( V_14 -> V_5 -> V_7 , & V_14 -> V_102 , & V_84 ) ;
F_99 ( & V_14 -> V_48 ) ;
V_14 -> V_357 = 1 ;
V_14 -> V_5 -> V_76 |= V_355 ;
F_10 ( V_14 , V_22 , V_14 -> V_5 -> V_49 . V_359 ) ;
F_100 ( & V_14 -> V_48 ) ;
}
}
static void F_226 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
F_133 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_58 & V_85 &&
V_14 -> V_97 == V_224 )
F_242 ( V_14 ) ;
F_91 ( & V_14 -> V_48 ) ;
}
F_138 ( & V_5 -> V_48 ) ;
}
static struct V_13 * F_248 ( struct V_364 * V_365 )
{
struct V_13 * V_82 = NULL ;
struct V_366 * V_97 = V_365 -> V_367 ;
struct V_86 * V_86 = F_249 ( V_365 ) ;
for ( V_97 -> V_368 = 0 ; V_97 -> V_368 < V_107 ; ++ V_97 -> V_368 ) {
struct V_217 * V_353 ;
F_146 (ifa, n, &inet6_addr_lst[state->bucket],
addr_lst)
if ( F_142 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_86 ) )
return V_82 ;
}
return NULL ;
}
static struct V_13 * F_250 ( struct V_364 * V_365 ,
struct V_13 * V_82 )
{
struct V_366 * V_97 = V_365 -> V_367 ;
struct V_86 * V_86 = F_249 ( V_365 ) ;
struct V_217 * V_353 = & V_82 -> V_96 ;
F_251 (ifa, n, addr_lst)
if ( F_142 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_86 ) )
return V_82 ;
while ( ++ V_97 -> V_368 < V_107 ) {
F_146 (ifa, n,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( F_142 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_86 ) )
return V_82 ;
}
}
return NULL ;
}
static struct V_13 * F_252 ( struct V_364 * V_365 , T_9 V_369 )
{
struct V_13 * V_82 = F_248 ( V_365 ) ;
if ( V_82 )
while ( V_369 && ( V_82 = F_250 ( V_365 , V_82 ) ) != NULL )
-- V_369 ;
return V_369 ? NULL : V_82 ;
}
static void * F_253 ( struct V_364 * V_365 , T_9 * V_369 )
__acquires( T_10 )
{
F_79 () ;
return F_252 ( V_365 , * V_369 ) ;
}
static void * F_254 ( struct V_364 * V_365 , void * V_370 , T_9 * V_369 )
{
struct V_13 * V_82 ;
V_82 = F_250 ( V_365 , V_370 ) ;
++ * V_369 ;
return V_82 ;
}
static void F_255 ( struct V_364 * V_365 , void * V_370 )
__releases( T_10 )
{
F_95 () ;
}
static int F_256 ( struct V_364 * V_365 , void * V_370 )
{
struct V_13 * V_14 = (struct V_13 * ) V_370 ;
F_257 ( V_365 , L_36 ,
& V_14 -> V_102 ,
V_14 -> V_5 -> V_7 -> V_145 ,
V_14 -> V_128 ,
V_14 -> V_109 ,
V_14 -> V_58 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
return 0 ;
}
static int F_258 ( struct V_371 * V_371 , struct V_372 * V_372 )
{
return F_259 ( V_371 , V_372 , & V_373 ,
sizeof( struct V_366 ) ) ;
}
static int T_11 F_260 ( struct V_86 * V_86 )
{
if ( ! F_261 ( V_86 , L_37 , V_374 , & V_375 ) )
return - V_38 ;
return 0 ;
}
static void T_12 F_262 ( struct V_86 * V_86 )
{
F_263 ( V_86 , L_37 ) ;
}
int T_13 F_264 ( void )
{
return F_265 ( & V_376 ) ;
}
void F_266 ( void )
{
F_267 ( & V_376 ) ;
}
int F_268 ( struct V_86 * V_86 , const struct V_104 * V_102 )
{
int V_157 = 0 ;
struct V_13 * V_14 = NULL ;
struct V_217 * V_353 ;
unsigned int V_110 = F_74 ( V_102 ) ;
F_79 () ;
F_146 (ifp, n, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_142 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_124 ( & V_14 -> V_102 , V_102 ) &&
( V_14 -> V_58 & V_193 ) ) {
V_157 = 1 ;
break;
}
}
F_95 () ;
return V_157 ;
}
static void F_194 ( unsigned long V_377 )
{
unsigned long V_280 , V_378 , V_379 , V_380 ;
struct V_13 * V_14 ;
struct V_217 * V_218 ;
int V_178 ;
F_79 () ;
F_80 ( & V_381 ) ;
V_280 = V_25 ;
V_378 = F_269 ( V_280 + V_382 ) ;
F_8 ( & V_383 ) ;
for ( V_178 = 0 ; V_178 < V_107 ; V_178 ++ ) {
V_354:
F_146 (ifp, node,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_154 ;
if ( V_14 -> V_58 & V_139 )
continue;
F_80 ( & V_14 -> V_48 ) ;
V_154 = ( V_280 - V_14 -> V_78 + V_384 ) / V_3 ;
if ( V_14 -> V_141 != V_317 &&
V_154 >= V_14 -> V_141 ) {
F_91 ( & V_14 -> V_48 ) ;
F_11 ( V_14 ) ;
F_98 ( V_14 ) ;
goto V_354;
} else if ( V_14 -> V_167 == V_317 ) {
F_91 ( & V_14 -> V_48 ) ;
continue;
} else if ( V_154 >= V_14 -> V_167 ) {
int V_385 = 0 ;
if ( ! ( V_14 -> V_58 & V_188 ) ) {
V_385 = 1 ;
V_14 -> V_58 |= V_188 ;
}
if ( F_109 ( V_14 -> V_78 + V_14 -> V_141 * V_3 , V_378 ) )
V_378 = V_14 -> V_78 + V_14 -> V_141 * V_3 ;
F_91 ( & V_14 -> V_48 ) ;
if ( V_385 ) {
F_11 ( V_14 ) ;
F_111 ( 0 , V_14 ) ;
F_104 ( V_14 ) ;
goto V_354;
}
#ifdef F_41
} else if ( ( V_14 -> V_58 & V_131 ) &&
! ( V_14 -> V_58 & V_85 ) ) {
unsigned long V_155 = V_14 -> V_5 -> V_49 . V_163 *
V_14 -> V_5 -> V_49 . V_170 *
V_14 -> V_5 -> V_53 -> V_171 / V_3 ;
if ( V_154 >= V_14 -> V_167 - V_155 ) {
struct V_13 * V_138 = V_14 -> V_138 ;
if ( F_109 ( V_14 -> V_78 + V_14 -> V_167 * V_3 , V_378 ) )
V_378 = V_14 -> V_78 + V_14 -> V_167 * V_3 ;
if ( ! V_14 -> V_162 && V_138 ) {
V_14 -> V_162 ++ ;
F_11 ( V_14 ) ;
F_11 ( V_138 ) ;
F_91 ( & V_14 -> V_48 ) ;
F_80 ( & V_138 -> V_48 ) ;
V_138 -> V_162 = 0 ;
F_91 ( & V_138 -> V_48 ) ;
F_116 ( V_138 , V_14 ) ;
F_104 ( V_138 ) ;
F_104 ( V_14 ) ;
goto V_354;
}
} else if ( F_109 ( V_14 -> V_78 + V_14 -> V_167 * V_3 - V_155 * V_3 , V_378 ) )
V_378 = V_14 -> V_78 + V_14 -> V_167 * V_3 - V_155 * V_3 ;
F_91 ( & V_14 -> V_48 ) ;
#endif
} else {
if ( F_109 ( V_14 -> V_78 + V_14 -> V_167 * V_3 , V_378 ) )
V_378 = V_14 -> V_78 + V_14 -> V_167 * V_3 ;
F_91 ( & V_14 -> V_48 ) ;
}
}
}
V_379 = F_269 ( V_378 ) ;
V_380 = V_378 ;
if ( F_109 ( V_379 , V_378 + V_386 ) )
V_380 = V_379 ;
if ( F_109 ( V_380 , V_25 + V_387 ) )
V_380 = V_25 + V_387 ;
F_36 ( ( V_41 L_38 ,
V_280 , V_378 , V_379 , V_380 ) ) ;
V_383 . V_24 = V_380 ;
F_12 ( & V_383 ) ;
F_91 ( & V_381 ) ;
F_95 () ;
}
static struct V_104 * F_270 ( struct V_388 * V_102 , struct V_388 * V_389 )
{
struct V_104 * V_241 = NULL ;
if ( V_102 )
V_241 = F_271 ( V_102 ) ;
if ( V_389 ) {
if ( V_241 && F_272 ( V_389 , V_241 , sizeof( * V_241 ) ) )
V_241 = NULL ;
else
V_241 = F_271 ( V_389 ) ;
}
return V_241 ;
}
static int
F_273 ( struct V_390 * V_391 , struct V_392 * V_393 , void * V_284 )
{
struct V_86 * V_86 = F_274 ( V_391 -> V_394 ) ;
struct V_395 * V_396 ;
struct V_388 * V_397 [ V_398 + 1 ] ;
struct V_104 * V_241 ;
int V_111 ;
V_111 = F_275 ( V_393 , sizeof( * V_396 ) , V_397 , V_398 , V_399 ) ;
if ( V_111 < 0 )
return V_111 ;
V_396 = F_276 ( V_393 ) ;
V_241 = F_270 ( V_397 [ V_400 ] , V_397 [ V_401 ] ) ;
if ( V_241 == NULL )
return - V_287 ;
return F_206 ( V_86 , V_396 -> V_402 , V_241 , V_396 -> V_403 ) ;
}
static int F_277 ( struct V_13 * V_14 , T_3 V_311 ,
T_1 V_167 , T_1 V_141 )
{
T_1 V_58 ;
T_5 V_24 ;
unsigned long V_312 ;
if ( ! V_141 || ( V_167 > V_141 ) )
return - V_287 ;
V_312 = F_108 ( V_141 , V_3 ) ;
if ( F_191 ( V_312 ) ) {
V_24 = F_192 ( V_312 * V_3 ) ;
V_141 = V_312 ;
V_58 = V_146 ;
} else {
V_24 = 0 ;
V_58 = 0 ;
V_311 |= V_139 ;
}
V_312 = F_108 ( V_167 , V_3 ) ;
if ( F_191 ( V_312 ) ) {
if ( V_312 == 0 )
V_311 |= V_188 ;
V_167 = V_312 ;
}
F_99 ( & V_14 -> V_48 ) ;
V_14 -> V_58 = ( V_14 -> V_58 & ~ ( V_188 | V_139 | V_361 | V_193 ) ) | V_311 ;
V_14 -> V_78 = V_25 ;
V_14 -> V_141 = V_141 ;
V_14 -> V_167 = V_167 ;
F_100 ( & V_14 -> V_48 ) ;
if ( ! ( V_14 -> V_58 & V_85 ) )
F_111 ( 0 , V_14 ) ;
F_181 ( & V_14 -> V_102 , V_14 -> V_128 , V_14 -> V_5 -> V_7 ,
V_24 , V_58 ) ;
F_194 ( 0 ) ;
return 0 ;
}
static int
F_278 ( struct V_390 * V_391 , struct V_392 * V_393 , void * V_284 )
{
struct V_86 * V_86 = F_274 ( V_391 -> V_394 ) ;
struct V_395 * V_396 ;
struct V_388 * V_397 [ V_398 + 1 ] ;
struct V_104 * V_241 ;
struct V_13 * V_82 ;
struct V_6 * V_7 ;
T_1 V_141 = V_317 , V_404 = V_317 ;
T_3 V_311 ;
int V_111 ;
V_111 = F_275 ( V_393 , sizeof( * V_396 ) , V_397 , V_398 , V_399 ) ;
if ( V_111 < 0 )
return V_111 ;
V_396 = F_276 ( V_393 ) ;
V_241 = F_270 ( V_397 [ V_400 ] , V_397 [ V_401 ] ) ;
if ( V_241 == NULL )
return - V_287 ;
if ( V_397 [ V_405 ] ) {
struct V_406 * V_407 ;
V_407 = F_271 ( V_397 [ V_405 ] ) ;
V_141 = V_407 -> V_408 ;
V_404 = V_407 -> V_409 ;
} else {
V_404 = V_317 ;
V_141 = V_317 ;
}
V_7 = F_199 ( V_86 , V_396 -> V_402 ) ;
if ( V_7 == NULL )
return - V_117 ;
V_311 = V_396 -> V_311 & ( V_361 | V_193 ) ;
V_82 = F_145 ( V_86 , V_241 , V_7 , 1 ) ;
if ( V_82 == NULL ) {
return F_204 ( V_86 , V_396 -> V_402 , V_241 ,
V_396 -> V_403 , V_311 ,
V_404 , V_141 ) ;
}
if ( V_393 -> V_410 & V_411 ||
! ( V_393 -> V_410 & V_412 ) )
V_111 = - V_122 ;
else
V_111 = F_277 ( V_82 , V_311 , V_404 , V_141 ) ;
F_104 ( V_82 ) ;
return V_111 ;
}
static void F_279 ( struct V_392 * V_393 , T_3 V_413 , T_3 V_58 ,
T_3 V_109 , int V_145 )
{
struct V_395 * V_396 ;
V_396 = F_276 ( V_393 ) ;
V_396 -> V_414 = V_415 ;
V_396 -> V_403 = V_413 ;
V_396 -> V_311 = V_58 ;
V_396 -> V_326 = V_109 ;
V_396 -> V_402 = V_145 ;
}
static int F_280 ( struct V_390 * V_391 , unsigned long V_1 ,
unsigned long V_78 , T_1 V_416 , T_1 V_269 )
{
struct V_406 V_407 ;
V_407 . V_1 = F_1 ( V_1 ) ;
V_407 . V_78 = F_1 ( V_78 ) ;
V_407 . V_409 = V_416 ;
V_407 . V_408 = V_269 ;
return F_281 ( V_391 , V_405 , sizeof( V_407 ) , & V_407 ) ;
}
static inline int F_282 ( int V_326 )
{
if ( V_326 & V_219 )
return V_328 ;
else if ( V_326 & V_214 )
return V_327 ;
else if ( V_326 & V_417 )
return V_418 ;
else
return V_419 ;
}
static inline int F_283 ( void )
{
return F_284 ( sizeof( struct V_395 ) )
+ F_285 ( 16 )
+ F_285 ( sizeof( struct V_406 ) ) ;
}
static int F_286 ( struct V_390 * V_391 , struct V_13 * V_82 ,
T_1 V_420 , T_1 V_365 , int V_335 , unsigned int V_58 )
{
struct V_392 * V_393 ;
T_1 V_416 , V_269 ;
V_393 = F_287 ( V_391 , V_420 , V_365 , V_335 , sizeof( struct V_395 ) , V_58 ) ;
if ( V_393 == NULL )
return - V_421 ;
F_279 ( V_393 , V_82 -> V_128 , V_82 -> V_58 , F_282 ( V_82 -> V_109 ) ,
V_82 -> V_5 -> V_7 -> V_145 ) ;
if ( ! ( V_82 -> V_58 & V_139 ) ) {
V_416 = V_82 -> V_167 ;
V_269 = V_82 -> V_141 ;
if ( V_416 != V_317 ) {
long V_422 = ( V_25 - V_82 -> V_78 ) / V_3 ;
if ( V_416 > V_422 )
V_416 -= V_422 ;
else
V_416 = 0 ;
if ( V_269 != V_317 ) {
if ( V_269 > V_422 )
V_269 -= V_422 ;
else
V_269 = 0 ;
}
}
} else {
V_416 = V_317 ;
V_269 = V_317 ;
}
if ( F_281 ( V_391 , V_400 , 16 , & V_82 -> V_102 ) < 0 ||
F_280 ( V_391 , V_82 -> V_1 , V_82 -> V_78 , V_416 , V_269 ) < 0 ) {
F_288 ( V_391 , V_393 ) ;
return - V_421 ;
}
return F_289 ( V_391 , V_393 ) ;
}
static int F_290 ( struct V_390 * V_391 , struct V_423 * V_424 ,
T_1 V_420 , T_1 V_365 , int V_335 , T_14 V_58 )
{
struct V_392 * V_393 ;
T_3 V_109 = V_419 ;
int V_145 = V_424 -> V_5 -> V_7 -> V_145 ;
if ( F_205 ( & V_424 -> V_425 ) & V_417 )
V_109 = V_418 ;
V_393 = F_287 ( V_391 , V_420 , V_365 , V_335 , sizeof( struct V_395 ) , V_58 ) ;
if ( V_393 == NULL )
return - V_421 ;
F_279 ( V_393 , 128 , V_139 , V_109 , V_145 ) ;
if ( F_281 ( V_391 , V_426 , 16 , & V_424 -> V_425 ) < 0 ||
F_280 ( V_391 , V_424 -> V_427 , V_424 -> V_428 ,
V_317 , V_317 ) < 0 ) {
F_288 ( V_391 , V_393 ) ;
return - V_421 ;
}
return F_289 ( V_391 , V_393 ) ;
}
static int F_291 ( struct V_390 * V_391 , struct V_429 * V_430 ,
T_1 V_420 , T_1 V_365 , int V_335 , unsigned int V_58 )
{
struct V_392 * V_393 ;
T_3 V_109 = V_419 ;
int V_145 = V_430 -> V_431 -> V_7 -> V_145 ;
if ( F_205 ( & V_430 -> V_432 ) & V_417 )
V_109 = V_418 ;
V_393 = F_287 ( V_391 , V_420 , V_365 , V_335 , sizeof( struct V_395 ) , V_58 ) ;
if ( V_393 == NULL )
return - V_421 ;
F_279 ( V_393 , 128 , V_139 , V_109 , V_145 ) ;
if ( F_281 ( V_391 , V_433 , 16 , & V_430 -> V_432 ) < 0 ||
F_280 ( V_391 , V_430 -> V_434 , V_430 -> V_435 ,
V_317 , V_317 ) < 0 ) {
F_288 ( V_391 , V_393 ) ;
return - V_421 ;
}
return F_289 ( V_391 , V_393 ) ;
}
static int F_292 ( struct V_4 * V_5 , struct V_390 * V_391 ,
struct V_436 * V_437 , enum V_438 type ,
int V_439 , int * V_440 )
{
struct V_423 * V_424 ;
struct V_429 * V_430 ;
int V_111 = 1 ;
int V_441 = * V_440 ;
F_133 ( & V_5 -> V_48 ) ;
switch ( type ) {
case V_442 : {
struct V_13 * V_82 ;
F_52 (ifa, &idev->addr_list, if_list) {
if ( ++ V_441 < V_439 )
continue;
V_111 = F_286 ( V_391 , V_82 ,
F_293 ( V_437 -> V_391 ) . V_420 ,
V_437 -> V_393 -> V_443 ,
V_318 ,
V_444 ) ;
if ( V_111 <= 0 )
break;
}
break;
}
case V_445 :
for ( V_424 = V_5 -> V_40 ; V_424 ;
V_424 = V_424 -> V_378 , V_441 ++ ) {
if ( V_441 < V_439 )
continue;
V_111 = F_290 ( V_391 , V_424 ,
F_293 ( V_437 -> V_391 ) . V_420 ,
V_437 -> V_393 -> V_443 ,
V_446 ,
V_444 ) ;
if ( V_111 <= 0 )
break;
}
break;
case V_447 :
for ( V_430 = V_5 -> V_448 ; V_430 ;
V_430 = V_430 -> V_449 , V_441 ++ ) {
if ( V_441 < V_439 )
continue;
V_111 = F_291 ( V_391 , V_430 ,
F_293 ( V_437 -> V_391 ) . V_420 ,
V_437 -> V_393 -> V_443 ,
V_450 ,
V_444 ) ;
if ( V_111 <= 0 )
break;
}
break;
default:
break;
}
F_138 ( & V_5 -> V_48 ) ;
* V_440 = V_441 ;
return V_111 ;
}
static int F_294 ( struct V_390 * V_391 , struct V_436 * V_437 ,
enum V_438 type )
{
struct V_86 * V_86 = F_274 ( V_391 -> V_394 ) ;
int V_352 , V_451 ;
int V_452 , V_441 ;
int V_453 , V_439 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_351 * V_454 ;
struct V_217 * V_218 ;
V_451 = V_437 -> args [ 0 ] ;
V_453 = V_452 = V_437 -> args [ 1 ] ;
V_439 = V_441 = V_437 -> args [ 2 ] ;
F_56 () ;
for ( V_352 = V_451 ; V_352 < V_455 ; V_352 ++ , V_453 = 0 ) {
V_452 = 0 ;
V_454 = & V_86 -> V_456 [ V_352 ] ;
F_141 (dev, node, head, index_hlist) {
if ( V_452 < V_453 )
goto V_457;
if ( V_352 > V_451 || V_452 > V_453 )
V_439 = 0 ;
V_441 = 0 ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_457;
if ( F_292 ( V_5 , V_391 , V_437 , type ,
V_439 , & V_441 ) <= 0 )
goto V_458;
V_457:
V_452 ++ ;
}
}
V_458:
F_58 () ;
V_437 -> args [ 0 ] = V_352 ;
V_437 -> args [ 1 ] = V_452 ;
V_437 -> args [ 2 ] = V_441 ;
return V_391 -> V_264 ;
}
static int F_295 ( struct V_390 * V_391 , struct V_436 * V_437 )
{
enum V_438 type = V_442 ;
return F_294 ( V_391 , V_437 , type ) ;
}
static int F_296 ( struct V_390 * V_391 , struct V_436 * V_437 )
{
enum V_438 type = V_445 ;
return F_294 ( V_391 , V_437 , type ) ;
}
static int F_297 ( struct V_390 * V_391 , struct V_436 * V_437 )
{
enum V_438 type = V_447 ;
return F_294 ( V_391 , V_437 , type ) ;
}
static int F_298 ( struct V_390 * V_459 , struct V_392 * V_393 ,
void * V_284 )
{
struct V_86 * V_86 = F_274 ( V_459 -> V_394 ) ;
struct V_395 * V_396 ;
struct V_388 * V_397 [ V_398 + 1 ] ;
struct V_104 * V_102 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_13 * V_82 ;
struct V_390 * V_391 ;
int V_111 ;
V_111 = F_275 ( V_393 , sizeof( * V_396 ) , V_397 , V_398 , V_399 ) ;
if ( V_111 < 0 )
goto V_460;
V_102 = F_270 ( V_397 [ V_400 ] , V_397 [ V_401 ] ) ;
if ( V_102 == NULL ) {
V_111 = - V_287 ;
goto V_460;
}
V_396 = F_276 ( V_393 ) ;
if ( V_396 -> V_402 )
V_7 = F_199 ( V_86 , V_396 -> V_402 ) ;
V_82 = F_145 ( V_86 , V_102 , V_7 , 1 ) ;
if ( ! V_82 ) {
V_111 = - V_116 ;
goto V_460;
}
V_391 = F_299 ( F_283 () , V_33 ) ;
if ( ! V_391 ) {
V_111 = - V_125 ;
goto V_461;
}
V_111 = F_286 ( V_391 , V_82 , F_293 ( V_459 ) . V_420 ,
V_393 -> V_443 , V_318 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_421 ) ;
F_300 ( V_391 ) ;
goto V_461;
}
V_111 = F_301 ( V_391 , V_86 , F_293 ( V_459 ) . V_420 ) ;
V_461:
F_104 ( V_82 ) ;
V_460:
return V_111 ;
}
static void F_302 ( int V_335 , struct V_13 * V_82 )
{
struct V_390 * V_391 ;
struct V_86 * V_86 = F_32 ( V_82 -> V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_391 = F_299 ( F_283 () , V_124 ) ;
if ( V_391 == NULL )
goto V_460;
V_111 = F_286 ( V_391 , V_82 , 0 , 0 , V_335 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_421 ) ;
F_300 ( V_391 ) ;
goto V_460;
}
F_303 ( V_391 , V_86 , 0 , V_462 , NULL , V_124 ) ;
return;
V_460:
if ( V_111 < 0 )
F_304 ( V_86 , V_462 , V_111 ) ;
}
static inline void F_305 ( struct V_463 * V_49 ,
T_2 * V_464 , int V_465 )
{
F_306 ( V_465 < ( V_466 * 4 ) ) ;
memset ( V_464 , 0 , V_465 ) ;
V_464 [ V_467 ] = V_49 -> V_55 ;
V_464 [ V_468 ] = V_49 -> V_469 ;
V_464 [ V_470 ] = V_49 -> V_51 ;
V_464 [ V_471 ] = V_49 -> V_472 ;
V_464 [ V_473 ] = V_49 -> V_474 ;
V_464 [ V_475 ] = V_49 -> V_275 ;
V_464 [ V_476 ] = V_49 -> V_170 ;
V_464 [ V_477 ] = V_49 -> V_68 ;
V_464 [ V_478 ] =
F_307 ( V_49 -> V_359 ) ;
V_464 [ V_479 ] =
F_307 ( V_49 -> V_358 ) ;
V_464 [ V_480 ] = V_49 -> V_481 ;
#ifdef F_41
V_464 [ V_482 ] = V_49 -> V_75 ;
V_464 [ V_483 ] = V_49 -> V_166 ;
V_464 [ V_484 ] = V_49 -> V_168 ;
V_464 [ V_485 ] = V_49 -> V_163 ;
V_464 [ V_486 ] = V_49 -> V_169 ;
#endif
V_464 [ V_487 ] = V_49 -> V_158 ;
V_464 [ V_488 ] = V_49 -> V_489 ;
V_464 [ V_490 ] = V_49 -> V_491 ;
#ifdef F_308
V_464 [ V_492 ] = V_49 -> V_493 ;
V_464 [ V_494 ] =
F_307 ( V_49 -> V_495 ) ;
#ifdef F_309
V_464 [ V_496 ] = V_49 -> V_497 ;
#endif
#endif
V_464 [ V_498 ] = V_49 -> V_499 ;
V_464 [ V_500 ] = V_49 -> V_501 ;
#ifdef F_193
V_464 [ V_502 ] = V_49 -> V_279 ;
#endif
#ifdef F_310
V_464 [ V_503 ] = V_49 -> V_504 ;
#endif
V_464 [ V_505 ] = V_49 -> V_119 ;
V_464 [ V_506 ] = V_49 -> V_61 ;
V_464 [ V_507 ] = V_49 -> V_508 ;
}
static inline T_15 F_311 ( void )
{
return F_285 ( 4 )
+ F_285 ( sizeof( struct V_509 ) )
+ F_285 ( V_466 * 4 )
+ F_285 ( V_510 * 8 )
+ F_285 ( V_511 * 8 ) ;
}
static inline T_15 F_312 ( void )
{
return F_284 ( sizeof( struct V_512 ) )
+ F_285 ( V_513 )
+ F_285 ( V_514 )
+ F_285 ( 4 )
+ F_285 ( 4 )
+ F_285 ( F_311 () ) ;
}
static inline void F_313 ( T_16 * V_27 , T_17 * V_515 ,
int V_516 , int V_465 )
{
int V_178 ;
int V_517 = V_465 - sizeof( T_16 ) * V_516 ;
F_306 ( V_517 < 0 ) ;
F_314 ( V_516 , & V_27 [ 0 ] ) ;
for ( V_178 = 1 ; V_178 < V_516 ; V_178 ++ )
F_314 ( F_315 ( & V_515 [ V_178 ] ) , & V_27 [ V_178 ] ) ;
memset ( & V_27 [ V_516 ] , 0 , V_517 ) ;
}
static inline void F_316 ( T_16 * V_27 , void V_26 * * V_515 ,
int V_516 , int V_465 , T_15 V_518 )
{
int V_178 ;
int V_517 = V_465 - sizeof( T_16 ) * V_516 ;
F_306 ( V_517 < 0 ) ;
F_314 ( V_516 , & V_27 [ 0 ] ) ;
for ( V_178 = 1 ; V_178 < V_516 ; V_178 ++ )
F_314 ( F_317 ( V_515 , V_178 , V_518 ) , & V_27 [ V_178 ] ) ;
memset ( & V_27 [ V_516 ] , 0 , V_517 ) ;
}
static void F_318 ( T_16 * V_27 , struct V_4 * V_5 , int V_519 ,
int V_465 )
{
switch ( V_519 ) {
case V_520 :
F_316 ( V_27 , ( void V_26 * * ) V_5 -> V_27 . V_28 ,
V_510 , V_465 , F_319 ( struct V_29 , V_521 ) ) ;
break;
case V_522 :
F_313 ( V_27 , V_5 -> V_27 . V_31 -> V_523 , V_511 , V_465 ) ;
break;
}
}
static int F_320 ( struct V_390 * V_391 , struct V_4 * V_5 )
{
struct V_388 * V_524 ;
struct V_509 V_407 ;
F_321 ( V_391 , V_525 , V_5 -> V_76 ) ;
V_407 . V_526 = V_527 ;
V_407 . V_78 = F_1 ( V_5 -> V_78 ) ;
V_407 . V_528 = F_307 ( V_5 -> V_53 -> V_528 ) ;
V_407 . V_171 = F_307 ( V_5 -> V_53 -> V_171 ) ;
F_322 ( V_391 , V_529 , sizeof( V_407 ) , & V_407 ) ;
V_524 = F_323 ( V_391 , V_530 , V_466 * sizeof( V_531 ) ) ;
if ( V_524 == NULL )
goto V_532;
F_305 ( & V_5 -> V_49 , F_271 ( V_524 ) , F_324 ( V_524 ) ) ;
V_524 = F_323 ( V_391 , V_520 , V_510 * sizeof( T_16 ) ) ;
if ( V_524 == NULL )
goto V_532;
F_318 ( F_271 ( V_524 ) , V_5 , V_520 , F_324 ( V_524 ) ) ;
V_524 = F_323 ( V_391 , V_522 , V_511 * sizeof( T_16 ) ) ;
if ( V_524 == NULL )
goto V_532;
F_318 ( F_271 ( V_524 ) , V_5 , V_522 , F_324 ( V_524 ) ) ;
return 0 ;
V_532:
return - V_421 ;
}
static T_15 F_325 ( const struct V_6 * V_7 )
{
if ( ! F_48 ( V_7 ) )
return 0 ;
return F_311 () ;
}
static int F_326 ( struct V_390 * V_391 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
return - V_533 ;
if ( F_320 ( V_391 , V_5 ) < 0 )
return - V_421 ;
return 0 ;
}
static int F_327 ( struct V_390 * V_391 , struct V_4 * V_5 ,
T_1 V_420 , T_1 V_365 , int V_335 , unsigned int V_58 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_512 * V_534 ;
struct V_392 * V_393 ;
void * V_535 ;
V_393 = F_287 ( V_391 , V_420 , V_365 , V_335 , sizeof( * V_534 ) , V_58 ) ;
if ( V_393 == NULL )
return - V_421 ;
V_534 = F_276 ( V_393 ) ;
V_534 -> V_536 = V_415 ;
V_534 -> V_537 = 0 ;
V_534 -> V_538 = V_7 -> type ;
V_534 -> V_539 = V_7 -> V_145 ;
V_534 -> V_540 = F_328 ( V_7 ) ;
V_534 -> V_541 = 0 ;
F_329 ( V_391 , V_542 , V_7 -> V_42 ) ;
if ( V_7 -> V_228 )
F_322 ( V_391 , V_543 , V_7 -> V_228 , V_7 -> V_230 ) ;
F_321 ( V_391 , V_544 , V_7 -> V_46 ) ;
if ( V_7 -> V_145 != V_7 -> V_332 )
F_321 ( V_391 , V_545 , V_7 -> V_332 ) ;
V_535 = F_330 ( V_391 , V_546 ) ;
if ( V_535 == NULL )
goto V_532;
if ( F_320 ( V_391 , V_5 ) < 0 )
goto V_532;
F_331 ( V_391 , V_535 ) ;
return F_289 ( V_391 , V_393 ) ;
V_532:
F_288 ( V_391 , V_393 ) ;
return - V_421 ;
}
static int F_332 ( struct V_390 * V_391 , struct V_436 * V_437 )
{
struct V_86 * V_86 = F_274 ( V_391 -> V_394 ) ;
int V_352 , V_451 ;
int V_452 = 0 , V_453 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_351 * V_454 ;
struct V_217 * V_218 ;
V_451 = V_437 -> args [ 0 ] ;
V_453 = V_437 -> args [ 1 ] ;
F_56 () ;
for ( V_352 = V_451 ; V_352 < V_455 ; V_352 ++ , V_453 = 0 ) {
V_452 = 0 ;
V_454 = & V_86 -> V_456 [ V_352 ] ;
F_141 (dev, node, head, index_hlist) {
if ( V_452 < V_453 )
goto V_457;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_457;
if ( F_327 ( V_391 , V_5 ,
F_293 ( V_437 -> V_391 ) . V_420 ,
V_437 -> V_393 -> V_443 ,
V_343 , V_444 ) <= 0 )
goto V_123;
V_457:
V_452 ++ ;
}
}
V_123:
F_58 () ;
V_437 -> args [ 1 ] = V_452 ;
V_437 -> args [ 0 ] = V_352 ;
return V_391 -> V_264 ;
}
void F_228 ( int V_335 , struct V_4 * V_5 )
{
struct V_390 * V_391 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_391 = F_299 ( F_312 () , V_124 ) ;
if ( V_391 == NULL )
goto V_460;
V_111 = F_327 ( V_391 , V_5 , 0 , 0 , V_335 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_421 ) ;
F_300 ( V_391 ) ;
goto V_460;
}
F_303 ( V_391 , V_86 , 0 , V_547 , NULL , V_124 ) ;
return;
V_460:
if ( V_111 < 0 )
F_304 ( V_86 , V_547 , V_111 ) ;
}
static inline T_15 F_333 ( void )
{
return F_284 ( sizeof( struct V_548 ) )
+ F_285 ( sizeof( struct V_104 ) )
+ F_285 ( sizeof( struct V_549 ) ) ;
}
static int F_334 ( struct V_390 * V_391 , struct V_4 * V_5 ,
struct V_265 * V_266 , T_1 V_420 , T_1 V_365 ,
int V_335 , unsigned int V_58 )
{
struct V_548 * V_550 ;
struct V_392 * V_393 ;
struct V_549 V_407 ;
V_393 = F_287 ( V_391 , V_420 , V_365 , V_335 , sizeof( * V_550 ) , V_58 ) ;
if ( V_393 == NULL )
return - V_421 ;
V_550 = F_276 ( V_393 ) ;
V_550 -> V_551 = V_415 ;
V_550 -> V_552 = 0 ;
V_550 -> V_553 = 0 ;
V_550 -> V_554 = V_5 -> V_7 -> V_145 ;
V_550 -> V_128 = V_266 -> V_128 ;
V_550 -> V_555 = V_266 -> type ;
V_550 -> V_556 = 0 ;
V_550 -> V_557 = 0 ;
if ( V_266 -> V_137 )
V_550 -> V_557 |= V_558 ;
if ( V_266 -> V_275 )
V_550 -> V_557 |= V_559 ;
F_322 ( V_391 , V_560 , sizeof( V_266 -> V_144 ) , & V_266 -> V_144 ) ;
V_407 . V_561 = F_189 ( V_266 -> V_270 ) ;
V_407 . V_562 = F_189 ( V_266 -> V_269 ) ;
F_322 ( V_391 , V_563 , sizeof( V_407 ) , & V_407 ) ;
return F_289 ( V_391 , V_393 ) ;
V_532:
F_288 ( V_391 , V_393 ) ;
return - V_421 ;
}
static void F_195 ( int V_335 , struct V_4 * V_5 ,
struct V_265 * V_266 )
{
struct V_390 * V_391 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_391 = F_299 ( F_333 () , V_124 ) ;
if ( V_391 == NULL )
goto V_460;
V_111 = F_334 ( V_391 , V_5 , V_266 , 0 , 0 , V_335 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_421 ) ;
F_300 ( V_391 ) ;
goto V_460;
}
F_303 ( V_391 , V_86 , 0 , V_564 , NULL , V_124 ) ;
return;
V_460:
if ( V_111 < 0 )
F_304 ( V_86 , V_564 , V_111 ) ;
}
static void F_236 ( int V_335 , struct V_13 * V_14 )
{
F_302 ( V_335 ? : V_318 , V_14 ) ;
switch ( V_335 ) {
case V_318 :
if ( ! ( V_14 -> V_9 -> V_565 ) )
F_246 ( V_14 -> V_9 ) ;
if ( V_14 -> V_5 -> V_49 . V_55 )
F_53 ( V_14 ) ;
break;
case V_142 :
if ( V_14 -> V_5 -> V_49 . V_55 )
F_54 ( V_14 ) ;
F_155 ( V_14 -> V_5 , & V_14 -> V_102 ) ;
F_335 ( & V_14 -> V_9 -> V_99 ) ;
if ( F_114 ( V_14 -> V_9 ) )
F_336 ( & V_14 -> V_9 -> V_99 ) ;
break;
}
}
static void F_111 ( int V_335 , struct V_13 * V_14 )
{
F_79 () ;
if ( F_96 ( V_14 -> V_5 -> V_43 == 0 ) )
F_236 ( V_335 , V_14 ) ;
F_95 () ;
}
static
int F_337 ( V_89 * V_566 , int V_567 ,
void T_6 * V_568 , T_15 * V_569 , T_9 * V_570 )
{
int * V_571 = V_566 -> V_127 ;
int V_572 = * V_571 ;
T_9 V_369 = * V_570 ;
int V_157 ;
V_157 = F_338 ( V_566 , V_567 , V_568 , V_569 , V_570 ) ;
if ( V_567 )
V_157 = F_59 ( V_566 , V_571 , V_572 ) ;
if ( V_157 )
* V_570 = V_369 ;
return V_157 ;
}
static void F_339 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_49 . V_119 )
F_224 ( NULL , V_143 , V_5 -> V_7 ) ;
else
F_224 ( NULL , V_134 , V_5 -> V_7 ) ;
}
static void F_340 ( struct V_86 * V_86 , T_2 V_87 )
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
F_339 ( V_5 ) ;
}
}
F_58 () ;
}
static int F_341 ( struct V_89 * V_90 , int * V_91 , int V_92 )
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
F_340 ( V_86 , V_87 ) ;
} else if ( ( ! * V_91 ) ^ ( ! V_92 ) )
F_339 ( (struct V_4 * ) V_90 -> V_95 ) ;
F_62 () ;
return 0 ;
}
static
int F_342 ( V_89 * V_566 , int V_567 ,
void T_6 * V_568 , T_15 * V_569 , T_9 * V_570 )
{
int * V_571 = V_566 -> V_127 ;
int V_572 = * V_571 ;
T_9 V_369 = * V_570 ;
int V_157 ;
V_157 = F_338 ( V_566 , V_567 , V_568 , V_569 , V_570 ) ;
if ( V_567 )
V_157 = F_341 ( V_566 , V_571 , V_572 ) ;
if ( V_157 )
* V_570 = V_369 ;
return V_157 ;
}
static int F_343 ( struct V_86 * V_86 , char * V_573 ,
struct V_4 * V_5 , struct V_463 * V_91 )
{
int V_178 ;
struct V_574 * V_575 ;
#define F_344 3
struct V_576 V_577 [] = {
{ . V_578 = L_39 , } ,
{ . V_578 = L_40 , } ,
{ . V_578 = L_41 , } ,
{ } ,
{ } ,
} ;
V_575 = F_345 ( & V_579 , sizeof( * V_575 ) , V_33 ) ;
if ( V_575 == NULL )
goto V_123;
for ( V_178 = 0 ; V_575 -> V_580 [ V_178 ] . V_127 ; V_178 ++ ) {
V_575 -> V_580 [ V_178 ] . V_127 += ( char * ) V_91 - ( char * ) & V_463 ;
V_575 -> V_580 [ V_178 ] . V_95 = V_5 ;
V_575 -> V_580 [ V_178 ] . V_93 = V_86 ;
}
V_575 -> V_573 = F_346 ( V_573 , V_33 ) ;
if ( ! V_575 -> V_573 )
goto free;
V_577 [ F_344 ] . V_578 = V_575 -> V_573 ;
V_575 -> V_581 = F_347 ( V_86 , V_577 ,
V_575 -> V_580 ) ;
if ( V_575 -> V_581 == NULL )
goto V_582;
V_91 -> V_52 = V_575 ;
return 0 ;
V_582:
F_17 ( V_575 -> V_573 ) ;
free:
F_17 ( V_575 ) ;
V_123:
return - V_125 ;
}
static void F_348 ( struct V_463 * V_91 )
{
struct V_574 * V_575 ;
if ( V_91 -> V_52 == NULL )
return;
V_575 = V_91 -> V_52 ;
V_91 -> V_52 = NULL ;
F_349 ( V_575 -> V_581 ) ;
F_17 ( V_575 -> V_573 ) ;
F_17 ( V_575 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_350 ( V_5 -> V_7 , V_5 -> V_53 , L_40 ,
& V_583 ) ;
F_343 ( F_32 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_42 ,
V_5 , & V_5 -> V_49 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_348 ( & V_5 -> V_49 ) ;
F_351 ( V_5 -> V_53 ) ;
}
static int T_11 F_352 ( struct V_86 * V_86 )
{
int V_111 ;
struct V_463 * V_584 , * V_585 ;
V_111 = - V_38 ;
V_584 = & V_463 ;
V_585 = & V_586 ;
if ( ! F_142 ( V_86 , & V_587 ) ) {
V_584 = F_345 ( V_584 , sizeof( V_463 ) , V_33 ) ;
if ( V_584 == NULL )
goto V_588;
V_585 = F_345 ( V_585 , sizeof( V_586 ) , V_33 ) ;
if ( V_585 == NULL )
goto V_589;
} else {
V_585 -> V_275 = V_590 . V_275 ;
V_585 -> V_119 = V_590 . V_119 ;
}
V_86 -> V_28 . V_94 = V_584 ;
V_86 -> V_28 . V_50 = V_585 ;
#ifdef F_353
V_111 = F_343 ( V_86 , L_42 , NULL , V_584 ) ;
if ( V_111 < 0 )
goto V_591;
V_111 = F_343 ( V_86 , L_43 , NULL , V_585 ) ;
if ( V_111 < 0 )
goto V_592;
#endif
return 0 ;
#ifdef F_353
V_592:
F_348 ( V_584 ) ;
V_591:
F_17 ( V_585 ) ;
#endif
V_589:
F_17 ( V_584 ) ;
V_588:
return V_111 ;
}
static void T_12 F_354 ( struct V_86 * V_86 )
{
#ifdef F_353
F_348 ( V_86 -> V_28 . V_50 ) ;
F_348 ( V_86 -> V_28 . V_94 ) ;
#endif
if ( ! F_142 ( V_86 , & V_587 ) ) {
F_17 ( V_86 -> V_28 . V_50 ) ;
F_17 ( V_86 -> V_28 . V_94 ) ;
}
}
int F_355 ( struct V_333 * V_593 )
{
return F_356 ( & V_133 , V_593 ) ;
}
int F_357 ( struct V_333 * V_593 )
{
return F_358 ( & V_133 , V_593 ) ;
}
int T_13 F_359 ( void )
{
int V_178 , V_111 ;
V_111 = F_360 () ;
if ( V_111 < 0 ) {
F_24 ( V_594 L_44
L_45 , V_111 ) ;
goto V_123;
}
V_111 = F_265 ( & V_595 ) ;
if ( V_111 < 0 )
goto V_596;
F_197 () ;
if ( ! F_28 ( V_587 . V_597 ) )
V_111 = - V_38 ;
F_62 () ;
if ( V_111 )
goto V_598;
for ( V_178 = 0 ; V_178 < V_107 ; V_178 ++ )
F_361 ( & V_130 [ V_178 ] ) ;
F_362 ( & V_599 ) ;
F_194 ( 0 ) ;
V_111 = F_363 ( & V_600 ) ;
if ( V_111 < 0 )
goto V_601;
V_111 = F_364 ( V_602 , V_603 , NULL , F_332 ,
NULL ) ;
if ( V_111 < 0 )
goto V_460;
F_364 ( V_602 , V_318 , F_278 , NULL , NULL ) ;
F_364 ( V_602 , V_142 , F_273 , NULL , NULL ) ;
F_364 ( V_602 , V_604 , F_298 ,
F_295 , NULL ) ;
F_364 ( V_602 , V_446 , NULL ,
F_296 , NULL ) ;
F_364 ( V_602 , V_450 , NULL ,
F_297 , NULL ) ;
F_365 () ;
return 0 ;
V_460:
F_366 ( & V_600 ) ;
V_601:
F_367 ( & V_599 ) ;
V_598:
F_267 ( & V_595 ) ;
V_596:
F_368 () ;
V_123:
return V_111 ;
}
void F_369 ( void )
{
struct V_6 * V_7 ;
int V_178 ;
F_367 ( & V_599 ) ;
F_267 ( & V_595 ) ;
F_368 () ;
F_197 () ;
F_370 ( & V_600 ) ;
F_213 (&init_net, dev) {
if ( F_48 ( V_7 ) == NULL )
continue;
F_207 ( V_7 , 1 ) ;
}
F_207 ( V_587 . V_597 , 2 ) ;
F_99 ( & V_121 ) ;
for ( V_178 = 0 ; V_178 < V_107 ; V_178 ++ )
F_21 ( ! F_371 ( & V_130 [ V_178 ] ) ) ;
F_100 ( & V_121 ) ;
F_8 ( & V_383 ) ;
F_62 () ;
}
