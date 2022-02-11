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
unsigned long V_150 , V_151 , V_152 , V_153 ;
unsigned long V_154 ;
int V_155 ;
int V_156 = 0 ;
int V_157 ;
T_1 V_158 ;
unsigned long V_159 = V_25 ;
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
V_156 = - 1 ;
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
V_156 = - 1 ;
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
V_156 = - 1 ;
goto V_123;
}
memcpy ( & V_102 . V_160 [ 8 ] , V_5 -> V_164 , 8 ) ;
V_153 = ( V_159 - V_14 -> V_78 ) / V_3 ;
V_151 = F_118 ( V_165 ,
V_14 -> V_141 ,
V_5 -> V_49 . V_166 + V_153 ) ;
V_150 = F_118 ( V_165 ,
V_14 -> V_167 ,
V_5 -> V_49 . V_168 + V_153 -
V_5 -> V_49 . V_169 ) ;
V_155 = V_14 -> V_128 ;
V_157 = V_5 -> V_49 . V_157 ;
V_152 = V_14 -> V_78 ;
F_100 ( & V_14 -> V_48 ) ;
V_154 = V_5 -> V_49 . V_163 *
V_5 -> V_49 . V_170 *
V_5 -> V_53 -> V_171 / V_3 ;
F_94 ( & V_5 -> V_48 ) ;
if ( V_150 <= V_154 ) {
F_104 ( V_14 ) ;
F_66 ( V_5 ) ;
V_156 = - 1 ;
goto V_123;
}
V_158 = V_131 ;
if ( V_14 -> V_58 & V_129 )
V_158 |= V_129 ;
V_148 = ! V_157 ||
F_119 ( V_5 ) < V_157 ?
F_76 ( V_5 , & V_102 , V_155 ,
F_77 ( & V_102 ) & V_172 ,
V_158 ) : NULL ;
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
V_148 -> V_1 = V_159 ;
V_148 -> V_78 = V_152 ;
F_100 ( & V_148 -> V_48 ) ;
F_120 ( V_148 , 0 ) ;
F_104 ( V_148 ) ;
F_66 ( V_5 ) ;
V_123:
return V_156 ;
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
int V_156 ;
if ( V_178 <= V_176 -> V_179 ) {
switch ( V_178 ) {
case V_180 :
V_156 = V_176 -> V_181 ;
break;
case V_182 :
V_156 = V_176 -> V_183 ;
break;
default:
V_156 = ! ! F_123 ( V_178 , V_176 -> V_184 ) ;
}
goto V_123;
}
switch ( V_178 ) {
case V_185 :
V_156 = ! ! V_176 -> V_82 ;
break;
case V_186 :
V_156 = F_124 ( & V_176 -> V_82 -> V_102 , V_99 -> V_102 ) ;
break;
case V_180 :
V_156 = F_125 ( V_176 -> V_112 ) ;
if ( V_156 >= V_99 -> V_109 )
V_156 = - V_156 ;
else
V_156 -= 128 ;
V_176 -> V_181 = V_156 ;
break;
case V_187 :
V_156 = F_121 ( V_176 -> V_112 ) ||
! ( V_176 -> V_82 -> V_58 & ( V_188 | V_129 ) ) ;
break;
#ifdef F_126
case V_189 :
{
int V_190 = ! ( V_99 -> V_191 & V_192 ) ;
V_156 = ! ( V_176 -> V_82 -> V_58 & V_193 ) ^ V_190 ;
break;
}
#endif
case V_194 :
V_156 = ( ! V_99 -> V_145 ||
V_99 -> V_145 == V_176 -> V_82 -> V_5 -> V_7 -> V_145 ) ;
break;
case V_195 :
V_156 = F_127 ( V_86 ,
& V_176 -> V_82 -> V_102 , V_176 -> V_112 ,
V_176 -> V_82 -> V_5 -> V_7 -> V_145 ) == V_99 -> V_196 ;
break;
#ifdef F_41
case V_197 :
{
int V_198 = V_99 -> V_191 & ( V_199 | V_200 ) ?
! ! ( V_99 -> V_191 & V_200 ) :
V_176 -> V_82 -> V_5 -> V_49 . V_75 >= 2 ;
V_156 = ( ! ( V_176 -> V_82 -> V_58 & V_131 ) ) ^ V_198 ;
break;
}
#endif
case V_201 :
V_156 = ! ( F_128 ( & V_176 -> V_82 -> V_102 ) ^
F_128 ( V_99 -> V_102 ) ) ;
break;
case V_182 :
V_176 -> V_183 = V_156 = F_129 ( & V_176 -> V_82 -> V_102 ,
V_99 -> V_102 ) ;
break;
default:
V_156 = 0 ;
}
if ( V_156 )
F_130 ( V_178 , V_176 -> V_184 ) ;
V_176 -> V_179 = V_178 ;
V_123:
return V_156 ;
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
int V_156 = 0 ;
if ( V_149 && memcmp ( V_5 -> V_164 , & V_149 -> V_160 [ 8 ] , 8 ) == 0 )
V_156 = F_178 ( V_5 ) ;
return V_156 ;
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
static struct V_8 * F_183 ( const struct V_104 * V_241 ,
int V_242 ,
const struct V_6 * V_7 ,
T_1 V_58 , T_1 V_261 )
{
struct V_262 * V_263 ;
struct V_8 * V_9 = NULL ;
struct V_264 * V_90 ;
V_90 = F_184 ( F_32 ( V_7 ) , V_246 ) ;
if ( V_90 == NULL )
return NULL ;
F_102 ( & V_90 -> V_265 ) ;
V_263 = F_185 ( & V_90 -> V_266 , V_241 , V_242 , NULL , 0 ) ;
if ( ! V_263 )
goto V_123;
for ( V_9 = V_263 -> V_267 ; V_9 ; V_9 = V_9 -> V_99 . V_268 ) {
if ( V_9 -> V_269 -> V_145 != V_7 -> V_145 )
continue;
if ( ( V_9 -> V_10 & V_58 ) != V_58 )
continue;
if ( ( V_261 != 0 ) && ( ( V_9 -> V_10 & V_58 ) != 0 ) )
continue;
F_186 ( & V_9 -> V_99 ) ;
break;
}
V_123:
F_110 ( & V_90 -> V_265 ) ;
return V_9 ;
}
static void F_187 ( struct V_6 * V_7 )
{
struct V_243 V_244 = {
. V_245 = V_270 ,
. V_247 = V_248 ,
. V_249 = V_7 -> V_145 ,
. V_251 = 8 ,
. V_252 = V_253 ,
. V_254 . V_255 = F_32 ( V_7 ) ,
} ;
F_188 ( & V_244 . V_258 , F_151 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_182 ( & V_244 ) ;
}
static void F_189 ( struct V_6 * V_7 )
{
struct V_243 V_244 = {
. V_245 = V_271 ,
. V_247 = V_248 ,
. V_249 = V_7 -> V_145 ,
. V_251 = 96 ,
. V_252 = V_253 | V_260 ,
. V_254 . V_255 = F_32 ( V_7 ) ,
} ;
F_182 ( & V_244 ) ;
}
static void F_190 ( struct V_6 * V_7 )
{
struct V_104 V_102 ;
F_188 ( & V_102 , F_151 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_181 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
}
static struct V_4 * F_191 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
return F_78 ( - V_125 ) ;
if ( V_5 -> V_49 . V_119 )
return F_78 ( - V_120 ) ;
if ( ! ( V_7 -> V_58 & V_60 ) )
F_187 ( V_7 ) ;
F_190 ( V_7 ) ;
return V_5 ;
}
void F_192 ( struct V_6 * V_7 , T_3 * V_272 , int V_273 )
{
struct V_274 * V_275 ;
V_165 V_141 ;
V_165 V_167 ;
int V_112 ;
struct V_4 * V_276 ;
struct V_86 * V_86 = F_32 ( V_7 ) ;
V_275 = (struct V_274 * ) V_272 ;
if ( V_273 < sizeof( struct V_274 ) ) {
F_36 ( ( L_21 ) ) ;
return;
}
V_112 = F_77 ( & V_275 -> V_144 ) ;
if ( V_112 & ( V_114 | V_277 ) )
return;
V_141 = F_193 ( V_275 -> V_278 ) ;
V_167 = F_193 ( V_275 -> V_279 ) ;
if ( V_167 > V_141 ) {
if ( F_150 () )
F_24 ( V_56 L_22 ) ;
return;
}
V_276 = F_194 ( V_7 ) ;
if ( V_276 == NULL ) {
if ( F_150 () )
F_24 ( V_41 L_23 , V_7 -> V_42 ) ;
return;
}
if ( V_275 -> V_137 ) {
struct V_8 * V_9 ;
unsigned long V_280 ;
if ( V_3 > V_281 )
V_280 = F_108 ( V_141 , V_3 ) ;
else
V_280 = F_108 ( V_141 , V_281 ) ;
if ( F_195 ( V_280 ) )
V_280 *= V_3 ;
V_9 = F_183 ( & V_275 -> V_144 ,
V_275 -> V_128 ,
V_7 ,
V_282 | V_283 ,
V_11 | V_12 ) ;
if ( V_9 ) {
if ( V_141 == 0 ) {
F_114 ( V_9 ) ;
V_9 = NULL ;
} else if ( F_195 ( V_280 ) ) {
V_9 -> V_147 = V_25 + V_280 ;
V_9 -> V_10 |= V_146 ;
} else {
V_9 -> V_10 &= ~ V_146 ;
V_9 -> V_147 = 0 ;
}
} else if ( V_141 ) {
T_5 V_24 = 0 ;
int V_58 = V_282 | V_283 ;
if ( F_195 ( V_280 ) ) {
V_58 |= V_146 ;
V_24 = F_196 ( V_280 ) ;
}
F_181 ( & V_275 -> V_144 , V_275 -> V_128 ,
V_7 , V_24 , V_58 ) ;
}
if ( V_9 )
F_68 ( & V_9 -> V_99 ) ;
}
if ( V_275 -> V_284 && V_276 -> V_49 . V_284 ) {
struct V_13 * V_14 ;
struct V_104 V_102 ;
int V_285 = 0 , V_286 = 0 ;
if ( V_275 -> V_128 == 64 ) {
memcpy ( & V_102 , & V_275 -> V_144 , 8 ) ;
if ( F_152 ( V_102 . V_160 + 8 , V_7 ) &&
F_177 ( V_102 . V_160 + 8 , V_276 ) ) {
F_66 ( V_276 ) ;
return;
}
goto V_287;
}
if ( F_150 () )
F_24 ( V_41 L_24 ,
V_275 -> V_128 ) ;
F_66 ( V_276 ) ;
return;
V_287:
V_14 = F_145 ( V_86 , & V_102 , V_7 , 1 ) ;
if ( V_14 == NULL && V_141 ) {
int V_157 = V_276 -> V_49 . V_157 ;
T_1 V_158 = 0 ;
#ifdef F_197
if ( V_276 -> V_49 . V_288 &&
! V_86 -> V_28 . V_94 -> V_55 )
V_158 = V_129 ;
#endif
if ( ! V_157 ||
F_119 ( V_276 ) < V_157 )
V_14 = F_76 ( V_276 , & V_102 , V_275 -> V_128 ,
V_112 & V_172 ,
V_158 ) ;
if ( ! V_14 || F_83 ( V_14 ) ) {
F_66 ( V_276 ) ;
return;
}
V_286 = V_285 = 1 ;
V_14 -> V_1 = V_25 ;
F_120 ( V_14 , V_282 | V_283 ) ;
}
if ( V_14 ) {
int V_58 ;
unsigned long V_159 ;
#ifdef F_41
struct V_13 * V_148 ;
#endif
T_1 V_289 ;
F_80 ( & V_14 -> V_48 ) ;
V_159 = V_25 ;
if ( V_14 -> V_141 > ( V_159 - V_14 -> V_78 ) / V_3 )
V_289 = V_14 -> V_141 - ( V_159 - V_14 -> V_78 ) / V_3 ;
else
V_289 = 0 ;
if ( ! V_286 && V_289 ) {
if ( V_141 > V_290 ||
V_141 > V_289 )
V_286 = 1 ;
else if ( V_289 <= V_290 ) {
if ( V_167 != V_14 -> V_167 ) {
V_141 = V_289 ;
V_286 = 1 ;
}
} else {
V_141 = V_290 ;
if ( V_141 < V_167 )
V_167 = V_141 ;
V_286 = 1 ;
}
}
if ( V_286 ) {
V_14 -> V_141 = V_141 ;
V_14 -> V_167 = V_167 ;
V_14 -> V_78 = V_159 ;
V_58 = V_14 -> V_58 ;
V_14 -> V_58 &= ~ V_188 ;
F_91 ( & V_14 -> V_48 ) ;
if ( ! ( V_58 & V_85 ) )
F_111 ( 0 , V_14 ) ;
} else
F_91 ( & V_14 -> V_48 ) ;
#ifdef F_41
F_133 ( & V_276 -> V_48 ) ;
F_52 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_153 , V_291 , V_292 ;
if ( V_14 != V_148 -> V_138 )
continue;
V_153 = ( V_159 - V_148 -> V_1 ) / V_3 ;
V_291 = V_276 -> V_49 . V_166 - V_153 ;
if ( V_291 < 0 )
V_291 = 0 ;
V_292 = V_276 -> V_49 . V_168 -
V_276 -> V_49 . V_169 -
V_153 ;
if ( V_292 < 0 )
V_292 = 0 ;
if ( V_141 > V_291 )
V_141 = V_291 ;
if ( V_167 > V_292 )
V_167 = V_292 ;
F_80 ( & V_148 -> V_48 ) ;
V_58 = V_148 -> V_58 ;
V_148 -> V_141 = V_141 ;
V_148 -> V_167 = V_167 ;
V_148 -> V_78 = V_159 ;
if ( V_167 > 0 )
V_148 -> V_58 &= ~ V_188 ;
F_91 ( & V_148 -> V_48 ) ;
if ( ! ( V_58 & V_85 ) )
F_111 ( 0 , V_148 ) ;
}
if ( ( V_285 || F_22 ( & V_276 -> V_69 ) ) && V_276 -> V_49 . V_75 > 0 ) {
F_138 ( & V_276 -> V_48 ) ;
F_116 ( V_14 , NULL ) ;
} else {
F_138 ( & V_276 -> V_48 ) ;
}
#endif
F_104 ( V_14 ) ;
F_198 ( 0 ) ;
}
}
F_199 ( V_293 , V_276 , V_275 ) ;
F_66 ( V_276 ) ;
}
int F_200 ( struct V_86 * V_86 , void T_6 * V_294 )
{
struct V_295 V_296 ;
struct V_6 * V_7 ;
int V_111 = - V_297 ;
F_201 () ;
V_111 = - V_298 ;
if ( F_202 ( & V_296 , V_294 , sizeof( struct V_295 ) ) )
goto V_299;
V_7 = F_203 ( V_86 , V_296 . V_300 ) ;
V_111 = - V_117 ;
if ( V_7 == NULL )
goto V_299;
#if F_40 ( V_62 ) || F_40 ( V_63 )
if ( V_7 -> type == V_64 ) {
const struct V_301 * V_302 = V_7 -> V_303 ;
struct V_304 V_305 ;
struct V_306 V_91 ;
V_111 = - V_116 ;
if ( ! ( F_77 ( & V_296 . V_307 ) & V_174 ) )
goto V_299;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_308 . V_203 = V_296 . V_307 . V_106 [ 3 ] ;
V_91 . V_308 . V_204 = 0 ;
V_91 . V_308 . V_309 = 4 ;
V_91 . V_308 . V_310 = 5 ;
V_91 . V_308 . V_311 = V_312 ;
V_91 . V_308 . V_313 = 64 ;
V_305 . V_314 . V_315 = ( V_105 void T_6 * ) & V_91 ;
if ( V_302 -> V_316 ) {
T_7 V_317 = F_204 () ;
F_205 ( V_318 ) ;
V_111 = V_302 -> V_316 ( V_7 , & V_305 , V_319 ) ;
F_205 ( V_317 ) ;
} else
V_111 = - V_320 ;
if ( V_111 == 0 ) {
V_111 = - V_125 ;
V_7 = F_206 ( V_86 , V_91 . V_42 ) ;
if ( ! V_7 )
goto V_299;
V_111 = F_207 ( V_7 ) ;
}
}
#endif
V_299:
F_62 () ;
return V_111 ;
}
static int F_208 ( struct V_86 * V_86 , int V_145 , const struct V_104 * V_241 ,
unsigned int V_242 , T_8 V_321 , V_165 V_167 ,
V_165 V_141 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_109 ;
T_1 V_58 ;
T_5 V_24 ;
unsigned long V_322 ;
F_29 () ;
if ( V_242 > 128 )
return - V_297 ;
if ( ! V_141 || V_167 > V_141 )
return - V_297 ;
V_7 = F_203 ( V_86 , V_145 ) ;
if ( ! V_7 )
return - V_117 ;
V_5 = F_191 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return F_84 ( V_5 ) ;
V_109 = F_209 ( V_241 ) ;
V_322 = F_108 ( V_141 , V_3 ) ;
if ( F_195 ( V_322 ) ) {
V_24 = F_196 ( V_322 * V_3 ) ;
V_141 = V_322 ;
V_58 = V_146 ;
} else {
V_24 = 0 ;
V_58 = 0 ;
V_321 |= V_139 ;
}
V_322 = F_108 ( V_167 , V_3 ) ;
if ( F_195 ( V_322 ) ) {
if ( V_322 == 0 )
V_321 |= V_188 ;
V_167 = V_322 ;
}
V_14 = F_76 ( V_5 , V_241 , V_242 , V_109 , V_321 ) ;
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
F_198 ( 0 ) ;
return 0 ;
}
return F_84 ( V_14 ) ;
}
static int F_210 ( struct V_86 * V_86 , int V_145 , const struct V_104 * V_241 ,
unsigned int V_242 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_242 > 128 )
return - V_297 ;
V_7 = F_203 ( V_86 , V_145 ) ;
if ( ! V_7 )
return - V_117 ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL )
return - V_323 ;
F_133 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_128 == V_242 &&
F_124 ( V_241 , & V_14 -> V_102 ) ) {
F_11 ( V_14 ) ;
F_138 ( & V_5 -> V_48 ) ;
F_98 ( V_14 ) ;
if ( F_22 ( & V_5 -> V_39 ) )
F_211 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_138 ( & V_5 -> V_48 ) ;
return - V_116 ;
}
int F_212 ( struct V_86 * V_86 , void T_6 * V_294 )
{
struct V_295 V_296 ;
int V_111 ;
if ( ! F_213 ( V_324 ) )
return - V_325 ;
if ( F_202 ( & V_296 , V_294 , sizeof( struct V_295 ) ) )
return - V_298 ;
F_201 () ;
V_111 = F_208 ( V_86 , V_296 . V_300 , & V_296 . V_307 ,
V_296 . V_326 , V_139 ,
V_327 , V_327 ) ;
F_62 () ;
return V_111 ;
}
int F_214 ( struct V_86 * V_86 , void T_6 * V_294 )
{
struct V_295 V_296 ;
int V_111 ;
if ( ! F_213 ( V_324 ) )
return - V_325 ;
if ( F_202 ( & V_296 , V_294 , sizeof( struct V_295 ) ) )
return - V_298 ;
F_201 () ;
V_111 = F_210 ( V_86 , V_296 . V_300 , & V_296 . V_307 ,
V_296 . V_326 ) ;
F_62 () ;
return V_111 ;
}
static void F_215 ( struct V_4 * V_5 , const struct V_104 * V_102 ,
int V_242 , int V_109 )
{
struct V_13 * V_14 ;
V_14 = F_76 ( V_5 , V_102 , V_242 , V_109 , V_139 ) ;
if ( ! F_83 ( V_14 ) ) {
F_99 ( & V_14 -> V_48 ) ;
V_14 -> V_58 &= ~ V_85 ;
F_100 ( & V_14 -> V_48 ) ;
F_111 ( V_328 , V_14 ) ;
F_104 ( V_14 ) ;
}
}
static void F_216 ( struct V_4 * V_5 )
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
F_215 ( V_5 , & V_102 , 128 , V_109 ) ;
return;
}
F_217 (net, dev) {
struct V_329 * V_330 = F_218 ( V_7 ) ;
if ( V_330 && ( V_7 -> V_58 & V_81 ) ) {
struct V_331 * V_82 ;
int V_332 = V_109 ;
for ( V_82 = V_330 -> V_333 ; V_82 ; V_82 = V_82 -> V_334 ) {
int V_242 ;
V_102 . V_106 [ 3 ] = V_82 -> V_335 ;
if ( V_82 -> V_336 == V_337 )
continue;
if ( V_82 -> V_336 >= V_338 ) {
if ( V_5 -> V_7 -> V_58 & V_259 )
continue;
V_332 |= V_219 ;
}
if ( V_5 -> V_7 -> V_58 & V_259 )
V_242 = 64 ;
else
V_242 = 96 ;
F_215 ( V_5 , & V_102 , V_242 , V_332 ) ;
}
}
}
}
static void F_219 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_24 ( V_41 L_25 ) ;
return;
}
F_215 ( V_5 , & V_339 , 128 , V_219 ) ;
}
static void F_220 ( struct V_4 * V_5 , const struct V_104 * V_102 )
{
struct V_13 * V_14 ;
T_1 V_158 = V_139 ;
#ifdef F_197
if ( V_5 -> V_49 . V_288 &&
! F_32 ( V_5 -> V_7 ) -> V_28 . V_94 -> V_55 )
V_158 |= V_129 ;
#endif
V_14 = F_76 ( V_5 , V_102 , 64 , V_214 , V_158 ) ;
if ( ! F_83 ( V_14 ) ) {
F_181 ( & V_14 -> V_102 , V_14 -> V_128 , V_5 -> V_7 , 0 , 0 ) ;
F_120 ( V_14 , 0 ) ;
F_104 ( V_14 ) ;
}
}
static void F_221 ( struct V_6 * V_7 )
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
V_5 = F_191 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return;
memset ( & V_102 , 0 , sizeof( struct V_104 ) ) ;
V_102 . V_106 [ 0 ] = F_151 ( 0xFE800000 ) ;
if ( F_152 ( V_102 . V_160 + 8 , V_7 ) == 0 )
F_220 ( V_5 , & V_102 ) ;
}
static void F_222 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_24 ( V_41 L_26 ) ;
return;
}
if ( V_7 -> V_65 & V_66 ) {
struct V_104 V_102 ;
F_188 ( & V_102 , F_151 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_181 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_152 ( V_102 . V_160 + 8 , V_7 ) )
F_220 ( V_5 , & V_102 ) ;
return;
}
F_216 ( V_5 ) ;
if ( V_7 -> V_58 & V_259 ) {
F_187 ( V_7 ) ;
F_190 ( V_7 ) ;
} else
F_189 ( V_7 ) ;
}
static void F_223 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_104 V_102 ;
F_224 ( L_27 , V_7 -> V_42 ) ;
F_29 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_24 ( V_41 L_28 ) ;
return;
}
F_188 ( & V_102 , F_151 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_181 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_152 ( V_102 . V_160 + 8 , V_7 ) )
F_220 ( V_5 , & V_102 ) ;
}
static inline int
F_225 ( struct V_4 * V_5 , struct V_6 * V_340 )
{
struct V_104 V_341 ;
if ( ! F_139 ( V_340 , & V_341 , V_85 ) ) {
F_220 ( V_5 , & V_341 ) ;
return 0 ;
}
return - 1 ;
}
static void F_226 ( struct V_4 * V_5 )
{
struct V_6 * V_340 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_342 &&
( V_340 = F_203 ( V_86 , V_5 -> V_7 -> V_342 ) ) ) {
if ( ! F_225 ( V_5 , V_340 ) )
return;
}
F_217 (net, link_dev) {
if ( ! F_225 ( V_5 , V_340 ) )
return;
}
F_24 ( V_41 L_29 ) ;
}
static void F_227 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_191 ( V_7 ) ;
if ( F_83 ( V_5 ) ) {
F_24 ( V_41 L_30 ) ;
return;
}
F_226 ( V_5 ) ;
}
static int F_228 ( struct V_343 * V_344 , unsigned long V_345 ,
void * V_127 )
{
struct V_6 * V_7 = (struct V_6 * ) V_127 ;
struct V_4 * V_5 = F_48 ( V_7 ) ;
int V_346 = 0 ;
int V_111 ;
switch ( V_345 ) {
case V_347 :
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! V_5 )
return F_229 ( - V_38 ) ;
}
break;
case V_134 :
case V_348 :
if ( V_7 -> V_58 & V_349 )
break;
if ( V_345 == V_134 ) {
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
V_346 = 1 ;
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
V_346 = 1 ;
}
switch ( V_7 -> type ) {
#if F_40 ( V_62 ) || F_40 ( V_63 )
case V_64 :
F_222 ( V_7 ) ;
break;
#endif
#if F_40 ( V_350 ) || F_40 ( V_351 )
case V_239 :
F_223 ( V_7 ) ;
break;
#endif
case V_73 :
F_227 ( V_7 ) ;
break;
case V_352 :
F_219 ( V_7 ) ;
break;
default:
F_221 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_346 )
F_230 ( V_5 ) ;
if ( V_5 -> V_49 . V_51 != V_7 -> V_46 &&
V_7 -> V_46 >= V_47 ) {
F_231 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
}
V_5 -> V_78 = V_25 ;
F_232 ( V_353 , V_5 ) ;
if ( V_7 -> V_46 < V_47 )
F_211 ( V_7 , 1 ) ;
}
break;
case V_354 :
if ( V_5 && V_7 -> V_46 >= V_47 ) {
F_231 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
break;
}
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
break;
}
case V_143 :
case V_355 :
F_211 ( V_7 , V_345 != V_143 ) ;
break;
case V_356 :
if ( V_5 ) {
F_233 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_111 = F_38 ( V_5 ) ;
if ( V_111 )
return F_229 ( V_111 ) ;
}
break;
case V_357 :
case V_358 :
F_234 ( V_7 , V_345 ) ;
break;
}
return V_359 ;
}
static void F_234 ( struct V_6 * V_7 , unsigned long V_345 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_345 == V_358 )
F_235 ( V_5 ) ;
else if ( V_345 == V_357 )
F_236 ( V_5 ) ;
}
static int F_211 ( struct V_6 * V_7 , int V_360 )
{
struct V_86 * V_86 = F_32 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_97 , V_178 ;
F_29 () ;
F_237 ( V_86 , V_7 ) ;
F_238 ( & V_54 , V_7 ) ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 == NULL )
return - V_117 ;
if ( V_360 ) {
V_5 -> V_43 = 1 ;
F_45 ( V_7 -> V_79 , NULL ) ;
F_233 ( V_5 ) ;
}
for ( V_178 = 0 ; V_178 < V_107 ; V_178 ++ ) {
struct V_361 * V_362 = & V_130 [ V_178 ] ;
struct V_217 * V_363 ;
F_99 ( & V_121 ) ;
V_364:
F_141 (ifa, n, h, addr_lst) {
if ( V_82 -> V_5 == V_5 ) {
F_101 ( & V_82 -> V_96 ) ;
F_7 ( V_82 ) ;
goto V_364;
}
}
F_100 ( & V_121 ) ;
}
F_102 ( & V_5 -> V_48 ) ;
if ( ! V_360 )
V_5 -> V_76 &= ~ ( V_365 | V_366 | V_77 ) ;
#ifdef F_41
if ( V_360 && F_8 ( & V_5 -> V_70 ) )
F_66 ( V_5 ) ;
while ( ! F_22 ( & V_5 -> V_69 ) ) {
V_82 = F_239 ( & V_5 -> V_69 ,
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
V_82 = F_239 ( & V_5 -> V_39 ,
struct V_13 , V_103 ) ;
F_7 ( V_82 ) ;
F_103 ( & V_82 -> V_103 ) ;
F_110 ( & V_5 -> V_48 ) ;
F_99 ( & V_82 -> V_126 ) ;
V_97 = V_82 -> V_97 ;
V_82 -> V_97 = V_98 ;
F_100 ( & V_82 -> V_126 ) ;
if ( V_97 != V_98 ) {
F_240 ( V_142 , V_82 ) ;
F_97 ( & V_133 , V_143 , V_82 ) ;
}
F_104 ( V_82 ) ;
F_102 ( & V_5 -> V_48 ) ;
}
F_110 ( & V_5 -> V_48 ) ;
if ( V_360 )
F_241 ( V_5 ) ;
else
F_242 ( V_5 ) ;
V_5 -> V_78 = V_25 ;
if ( V_360 ) {
F_3 ( V_5 ) ;
F_37 ( & V_54 , V_5 -> V_53 ) ;
F_238 ( & V_54 , V_7 ) ;
F_66 ( V_5 ) ;
}
return 0 ;
}
static void V_23 ( unsigned long V_127 )
{
struct V_13 * V_14 = (struct V_13 * ) V_127 ;
struct V_4 * V_5 = V_14 -> V_5 ;
F_243 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_76 & V_77 ) )
goto V_123;
if ( V_5 -> V_49 . V_55 )
goto V_123;
if ( V_5 -> V_76 & V_366 )
goto V_123;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_367 ++ < V_5 -> V_49 . V_68 ) {
F_10 ( V_14 , V_22 ,
( V_14 -> V_367 == V_5 -> V_49 . V_68 ) ?
V_5 -> V_49 . V_368 :
V_5 -> V_49 . V_369 ) ;
F_91 ( & V_14 -> V_48 ) ;
F_244 ( V_5 -> V_7 , & V_14 -> V_102 , & V_84 ) ;
} else {
F_91 ( & V_14 -> V_48 ) ;
F_24 ( V_41 L_35 ,
V_5 -> V_7 -> V_42 ) ;
}
V_123:
F_245 ( & V_5 -> V_48 ) ;
F_104 ( V_14 ) ;
}
static void F_246 ( struct V_13 * V_14 )
{
unsigned long V_370 ;
struct V_4 * V_5 = V_14 -> V_5 ;
if ( V_14 -> V_58 & V_129 )
V_370 = 0 ;
else
V_370 = F_247 () % ( V_5 -> V_49 . V_368 ? : 1 ) ;
V_14 -> V_367 = V_5 -> V_49 . V_170 ;
F_10 ( V_14 , V_19 , V_370 ) ;
}
static void F_120 ( struct V_13 * V_14 , T_1 V_58 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_153 ( V_7 , & V_14 -> V_102 ) ;
F_248 ( V_14 -> V_102 . V_106 [ 3 ] ) ;
F_133 ( & V_5 -> V_48 ) ;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_97 == V_98 )
goto V_123;
if ( V_7 -> V_58 & ( V_59 | V_60 ) ||
V_5 -> V_49 . V_61 < 1 ||
! ( V_14 -> V_58 & V_85 ) ||
V_14 -> V_58 & V_371 ) {
V_14 -> V_58 &= ~ ( V_85 | V_129 | V_222 ) ;
F_91 ( & V_14 -> V_48 ) ;
F_138 ( & V_5 -> V_48 ) ;
F_249 ( V_14 ) ;
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
F_250 ( V_14 -> V_9 ) ;
F_246 ( V_14 ) ;
V_123:
F_91 ( & V_14 -> V_48 ) ;
F_138 ( & V_5 -> V_48 ) ;
}
static void V_21 ( unsigned long V_127 )
{
struct V_13 * V_14 = (struct V_13 * ) V_127 ;
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_104 V_372 ;
if ( ! V_14 -> V_367 && F_148 ( V_14 ) )
goto V_123;
F_243 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_76 & V_77 ) ) {
F_245 ( & V_5 -> V_48 ) ;
goto V_123;
}
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_97 == V_98 ) {
F_91 ( & V_14 -> V_48 ) ;
F_245 ( & V_5 -> V_48 ) ;
goto V_123;
}
if ( V_14 -> V_367 == 0 ) {
V_14 -> V_58 &= ~ ( V_85 | V_129 | V_222 ) ;
F_91 ( & V_14 -> V_48 ) ;
F_245 ( & V_5 -> V_48 ) ;
F_249 ( V_14 ) ;
goto V_123;
}
V_14 -> V_367 -- ;
F_10 ( V_14 , V_19 , V_14 -> V_5 -> V_53 -> V_171 ) ;
F_91 ( & V_14 -> V_48 ) ;
F_245 ( & V_5 -> V_48 ) ;
F_154 ( & V_14 -> V_102 , & V_372 ) ;
F_251 ( V_14 -> V_5 -> V_7 , NULL , & V_14 -> V_102 , & V_372 , & V_373 ) ;
V_123:
F_104 ( V_14 ) ;
}
static void F_249 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = V_14 -> V_5 -> V_7 ;
F_111 ( V_328 , V_14 ) ;
if ( ( ( V_14 -> V_5 -> V_49 . V_374 == 1 && ! V_14 -> V_5 -> V_49 . V_55 ) ||
V_14 -> V_5 -> V_49 . V_374 == 2 ) &&
V_14 -> V_5 -> V_49 . V_68 > 0 &&
( V_7 -> V_58 & V_60 ) == 0 &&
( F_77 ( & V_14 -> V_102 ) & V_277 ) ) {
F_244 ( V_14 -> V_5 -> V_7 , & V_14 -> V_102 , & V_84 ) ;
F_99 ( & V_14 -> V_48 ) ;
V_14 -> V_367 = 1 ;
V_14 -> V_5 -> V_76 |= V_365 ;
F_10 ( V_14 , V_22 , V_14 -> V_5 -> V_49 . V_369 ) ;
F_100 ( & V_14 -> V_48 ) ;
}
}
static void F_230 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
F_133 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_58 & V_85 &&
V_14 -> V_97 == V_224 )
F_246 ( V_14 ) ;
F_91 ( & V_14 -> V_48 ) ;
}
F_138 ( & V_5 -> V_48 ) ;
}
static struct V_13 * F_252 ( struct V_375 * V_376 )
{
struct V_13 * V_82 = NULL ;
struct V_377 * V_97 = V_376 -> V_378 ;
struct V_86 * V_86 = F_253 ( V_376 ) ;
for ( V_97 -> V_379 = 0 ; V_97 -> V_379 < V_107 ; ++ V_97 -> V_379 ) {
struct V_217 * V_363 ;
F_146 (ifa, n, &inet6_addr_lst[state->bucket],
addr_lst)
if ( F_142 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_86 ) )
return V_82 ;
}
return NULL ;
}
static struct V_13 * F_254 ( struct V_375 * V_376 ,
struct V_13 * V_82 )
{
struct V_377 * V_97 = V_376 -> V_378 ;
struct V_86 * V_86 = F_253 ( V_376 ) ;
struct V_217 * V_363 = & V_82 -> V_96 ;
F_255 (ifa, n, addr_lst)
if ( F_142 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_86 ) )
return V_82 ;
while ( ++ V_97 -> V_379 < V_107 ) {
F_146 (ifa, n,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( F_142 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_86 ) )
return V_82 ;
}
}
return NULL ;
}
static struct V_13 * F_256 ( struct V_375 * V_376 , T_9 V_380 )
{
struct V_13 * V_82 = F_252 ( V_376 ) ;
if ( V_82 )
while ( V_380 && ( V_82 = F_254 ( V_376 , V_82 ) ) != NULL )
-- V_380 ;
return V_380 ? NULL : V_82 ;
}
static void * F_257 ( struct V_375 * V_376 , T_9 * V_380 )
__acquires( T_10 )
{
F_79 () ;
return F_256 ( V_376 , * V_380 ) ;
}
static void * F_258 ( struct V_375 * V_376 , void * V_381 , T_9 * V_380 )
{
struct V_13 * V_82 ;
V_82 = F_254 ( V_376 , V_381 ) ;
++ * V_380 ;
return V_82 ;
}
static void F_259 ( struct V_375 * V_376 , void * V_381 )
__releases( T_10 )
{
F_95 () ;
}
static int F_260 ( struct V_375 * V_376 , void * V_381 )
{
struct V_13 * V_14 = (struct V_13 * ) V_381 ;
F_261 ( V_376 , L_36 ,
& V_14 -> V_102 ,
V_14 -> V_5 -> V_7 -> V_145 ,
V_14 -> V_128 ,
V_14 -> V_109 ,
V_14 -> V_58 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
return 0 ;
}
static int F_262 ( struct V_382 * V_382 , struct V_383 * V_383 )
{
return F_263 ( V_382 , V_383 , & V_384 ,
sizeof( struct V_377 ) ) ;
}
static int T_11 F_264 ( struct V_86 * V_86 )
{
if ( ! F_265 ( V_86 , L_37 , V_385 , & V_386 ) )
return - V_38 ;
return 0 ;
}
static void T_12 F_266 ( struct V_86 * V_86 )
{
F_267 ( V_86 , L_37 ) ;
}
int T_13 F_268 ( void )
{
return F_269 ( & V_387 ) ;
}
void F_270 ( void )
{
F_271 ( & V_387 ) ;
}
int F_272 ( struct V_86 * V_86 , const struct V_104 * V_102 )
{
int V_156 = 0 ;
struct V_13 * V_14 = NULL ;
struct V_217 * V_363 ;
unsigned int V_110 = F_74 ( V_102 ) ;
F_79 () ;
F_146 (ifp, n, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_142 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_124 ( & V_14 -> V_102 , V_102 ) &&
( V_14 -> V_58 & V_193 ) ) {
V_156 = 1 ;
break;
}
}
F_95 () ;
return V_156 ;
}
static void F_198 ( unsigned long V_388 )
{
unsigned long V_159 , V_389 , V_390 , V_391 ;
struct V_13 * V_14 ;
struct V_217 * V_218 ;
int V_178 ;
F_79 () ;
F_80 ( & V_392 ) ;
V_159 = V_25 ;
V_389 = F_273 ( V_159 + V_393 ) ;
F_8 ( & V_394 ) ;
for ( V_178 = 0 ; V_178 < V_107 ; V_178 ++ ) {
V_364:
F_146 (ifp, node,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_153 ;
if ( V_14 -> V_58 & V_139 )
continue;
F_80 ( & V_14 -> V_48 ) ;
V_153 = ( V_159 - V_14 -> V_78 + V_395 ) / V_3 ;
if ( V_14 -> V_141 != V_327 &&
V_153 >= V_14 -> V_141 ) {
F_91 ( & V_14 -> V_48 ) ;
F_11 ( V_14 ) ;
F_98 ( V_14 ) ;
goto V_364;
} else if ( V_14 -> V_167 == V_327 ) {
F_91 ( & V_14 -> V_48 ) ;
continue;
} else if ( V_153 >= V_14 -> V_167 ) {
int V_396 = 0 ;
if ( ! ( V_14 -> V_58 & V_188 ) ) {
V_396 = 1 ;
V_14 -> V_58 |= V_188 ;
}
if ( F_109 ( V_14 -> V_78 + V_14 -> V_141 * V_3 , V_389 ) )
V_389 = V_14 -> V_78 + V_14 -> V_141 * V_3 ;
F_91 ( & V_14 -> V_48 ) ;
if ( V_396 ) {
F_11 ( V_14 ) ;
F_111 ( 0 , V_14 ) ;
F_104 ( V_14 ) ;
goto V_364;
}
#ifdef F_41
} else if ( ( V_14 -> V_58 & V_131 ) &&
! ( V_14 -> V_58 & V_85 ) ) {
unsigned long V_154 = V_14 -> V_5 -> V_49 . V_163 *
V_14 -> V_5 -> V_49 . V_170 *
V_14 -> V_5 -> V_53 -> V_171 / V_3 ;
if ( V_153 >= V_14 -> V_167 - V_154 ) {
struct V_13 * V_138 = V_14 -> V_138 ;
if ( F_109 ( V_14 -> V_78 + V_14 -> V_167 * V_3 , V_389 ) )
V_389 = V_14 -> V_78 + V_14 -> V_167 * V_3 ;
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
goto V_364;
}
} else if ( F_109 ( V_14 -> V_78 + V_14 -> V_167 * V_3 - V_154 * V_3 , V_389 ) )
V_389 = V_14 -> V_78 + V_14 -> V_167 * V_3 - V_154 * V_3 ;
F_91 ( & V_14 -> V_48 ) ;
#endif
} else {
if ( F_109 ( V_14 -> V_78 + V_14 -> V_167 * V_3 , V_389 ) )
V_389 = V_14 -> V_78 + V_14 -> V_167 * V_3 ;
F_91 ( & V_14 -> V_48 ) ;
}
}
}
V_390 = F_273 ( V_389 ) ;
V_391 = V_389 ;
if ( F_109 ( V_390 , V_389 + V_397 ) )
V_391 = V_390 ;
if ( F_109 ( V_391 , V_25 + V_398 ) )
V_391 = V_25 + V_398 ;
F_36 ( ( V_41 L_38 ,
V_159 , V_389 , V_390 , V_391 ) ) ;
V_394 . V_24 = V_391 ;
F_12 ( & V_394 ) ;
F_91 ( & V_392 ) ;
F_95 () ;
}
static struct V_104 * F_274 ( struct V_399 * V_102 , struct V_399 * V_400 )
{
struct V_104 * V_241 = NULL ;
if ( V_102 )
V_241 = F_275 ( V_102 ) ;
if ( V_400 ) {
if ( V_241 && F_276 ( V_400 , V_241 , sizeof( * V_241 ) ) )
V_241 = NULL ;
else
V_241 = F_275 ( V_400 ) ;
}
return V_241 ;
}
static int
F_277 ( struct V_401 * V_402 , struct V_403 * V_404 , void * V_294 )
{
struct V_86 * V_86 = F_278 ( V_402 -> V_405 ) ;
struct V_406 * V_407 ;
struct V_399 * V_408 [ V_409 + 1 ] ;
struct V_104 * V_241 ;
int V_111 ;
V_111 = F_279 ( V_404 , sizeof( * V_407 ) , V_408 , V_409 , V_410 ) ;
if ( V_111 < 0 )
return V_111 ;
V_407 = F_280 ( V_404 ) ;
V_241 = F_274 ( V_408 [ V_411 ] , V_408 [ V_412 ] ) ;
if ( V_241 == NULL )
return - V_297 ;
return F_210 ( V_86 , V_407 -> V_413 , V_241 , V_407 -> V_414 ) ;
}
static int F_281 ( struct V_13 * V_14 , T_3 V_321 ,
T_1 V_167 , T_1 V_141 )
{
T_1 V_58 ;
T_5 V_24 ;
unsigned long V_322 ;
if ( ! V_141 || ( V_167 > V_141 ) )
return - V_297 ;
V_322 = F_108 ( V_141 , V_3 ) ;
if ( F_195 ( V_322 ) ) {
V_24 = F_196 ( V_322 * V_3 ) ;
V_141 = V_322 ;
V_58 = V_146 ;
} else {
V_24 = 0 ;
V_58 = 0 ;
V_321 |= V_139 ;
}
V_322 = F_108 ( V_167 , V_3 ) ;
if ( F_195 ( V_322 ) ) {
if ( V_322 == 0 )
V_321 |= V_188 ;
V_167 = V_322 ;
}
F_99 ( & V_14 -> V_48 ) ;
V_14 -> V_58 = ( V_14 -> V_58 & ~ ( V_188 | V_139 | V_371 | V_193 ) ) | V_321 ;
V_14 -> V_78 = V_25 ;
V_14 -> V_141 = V_141 ;
V_14 -> V_167 = V_167 ;
F_100 ( & V_14 -> V_48 ) ;
if ( ! ( V_14 -> V_58 & V_85 ) )
F_111 ( 0 , V_14 ) ;
F_181 ( & V_14 -> V_102 , V_14 -> V_128 , V_14 -> V_5 -> V_7 ,
V_24 , V_58 ) ;
F_198 ( 0 ) ;
return 0 ;
}
static int
F_282 ( struct V_401 * V_402 , struct V_403 * V_404 , void * V_294 )
{
struct V_86 * V_86 = F_278 ( V_402 -> V_405 ) ;
struct V_406 * V_407 ;
struct V_399 * V_408 [ V_409 + 1 ] ;
struct V_104 * V_241 ;
struct V_13 * V_82 ;
struct V_6 * V_7 ;
T_1 V_141 = V_327 , V_415 = V_327 ;
T_3 V_321 ;
int V_111 ;
V_111 = F_279 ( V_404 , sizeof( * V_407 ) , V_408 , V_409 , V_410 ) ;
if ( V_111 < 0 )
return V_111 ;
V_407 = F_280 ( V_404 ) ;
V_241 = F_274 ( V_408 [ V_411 ] , V_408 [ V_412 ] ) ;
if ( V_241 == NULL )
return - V_297 ;
if ( V_408 [ V_416 ] ) {
struct V_417 * V_418 ;
V_418 = F_275 ( V_408 [ V_416 ] ) ;
V_141 = V_418 -> V_419 ;
V_415 = V_418 -> V_420 ;
} else {
V_415 = V_327 ;
V_141 = V_327 ;
}
V_7 = F_203 ( V_86 , V_407 -> V_413 ) ;
if ( V_7 == NULL )
return - V_117 ;
V_321 = V_407 -> V_321 & ( V_371 | V_193 ) ;
V_82 = F_145 ( V_86 , V_241 , V_7 , 1 ) ;
if ( V_82 == NULL ) {
return F_208 ( V_86 , V_407 -> V_413 , V_241 ,
V_407 -> V_414 , V_321 ,
V_415 , V_141 ) ;
}
if ( V_404 -> V_421 & V_422 ||
! ( V_404 -> V_421 & V_423 ) )
V_111 = - V_122 ;
else
V_111 = F_281 ( V_82 , V_321 , V_415 , V_141 ) ;
F_104 ( V_82 ) ;
return V_111 ;
}
static void F_283 ( struct V_403 * V_404 , T_3 V_424 , T_3 V_58 ,
T_3 V_109 , int V_145 )
{
struct V_406 * V_407 ;
V_407 = F_280 ( V_404 ) ;
V_407 -> V_425 = V_426 ;
V_407 -> V_414 = V_424 ;
V_407 -> V_321 = V_58 ;
V_407 -> V_336 = V_109 ;
V_407 -> V_413 = V_145 ;
}
static int F_284 ( struct V_401 * V_402 , unsigned long V_1 ,
unsigned long V_78 , T_1 V_427 , T_1 V_278 )
{
struct V_417 V_418 ;
V_418 . V_1 = F_1 ( V_1 ) ;
V_418 . V_78 = F_1 ( V_78 ) ;
V_418 . V_420 = V_427 ;
V_418 . V_419 = V_278 ;
return F_285 ( V_402 , V_416 , sizeof( V_418 ) , & V_418 ) ;
}
static inline int F_286 ( int V_336 )
{
if ( V_336 & V_219 )
return V_338 ;
else if ( V_336 & V_214 )
return V_337 ;
else if ( V_336 & V_428 )
return V_429 ;
else
return V_430 ;
}
static inline int F_287 ( void )
{
return F_288 ( sizeof( struct V_406 ) )
+ F_289 ( 16 )
+ F_289 ( sizeof( struct V_417 ) ) ;
}
static int F_290 ( struct V_401 * V_402 , struct V_13 * V_82 ,
T_1 V_431 , T_1 V_376 , int V_345 , unsigned int V_58 )
{
struct V_403 * V_404 ;
T_1 V_427 , V_278 ;
V_404 = F_291 ( V_402 , V_431 , V_376 , V_345 , sizeof( struct V_406 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
F_283 ( V_404 , V_82 -> V_128 , V_82 -> V_58 , F_286 ( V_82 -> V_109 ) ,
V_82 -> V_5 -> V_7 -> V_145 ) ;
if ( ! ( V_82 -> V_58 & V_139 ) ) {
V_427 = V_82 -> V_167 ;
V_278 = V_82 -> V_141 ;
if ( V_427 != V_327 ) {
long V_433 = ( V_25 - V_82 -> V_78 ) / V_3 ;
if ( V_427 > V_433 )
V_427 -= V_433 ;
else
V_427 = 0 ;
if ( V_278 != V_327 ) {
if ( V_278 > V_433 )
V_278 -= V_433 ;
else
V_278 = 0 ;
}
}
} else {
V_427 = V_327 ;
V_278 = V_327 ;
}
if ( F_285 ( V_402 , V_411 , 16 , & V_82 -> V_102 ) < 0 ||
F_284 ( V_402 , V_82 -> V_1 , V_82 -> V_78 , V_427 , V_278 ) < 0 ) {
F_292 ( V_402 , V_404 ) ;
return - V_432 ;
}
return F_293 ( V_402 , V_404 ) ;
}
static int F_294 ( struct V_401 * V_402 , struct V_434 * V_435 ,
T_1 V_431 , T_1 V_376 , int V_345 , T_14 V_58 )
{
struct V_403 * V_404 ;
T_3 V_109 = V_430 ;
int V_145 = V_435 -> V_5 -> V_7 -> V_145 ;
if ( F_209 ( & V_435 -> V_436 ) & V_428 )
V_109 = V_429 ;
V_404 = F_291 ( V_402 , V_431 , V_376 , V_345 , sizeof( struct V_406 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
F_283 ( V_404 , 128 , V_139 , V_109 , V_145 ) ;
if ( F_285 ( V_402 , V_437 , 16 , & V_435 -> V_436 ) < 0 ||
F_284 ( V_402 , V_435 -> V_438 , V_435 -> V_439 ,
V_327 , V_327 ) < 0 ) {
F_292 ( V_402 , V_404 ) ;
return - V_432 ;
}
return F_293 ( V_402 , V_404 ) ;
}
static int F_295 ( struct V_401 * V_402 , struct V_440 * V_441 ,
T_1 V_431 , T_1 V_376 , int V_345 , unsigned int V_58 )
{
struct V_403 * V_404 ;
T_3 V_109 = V_430 ;
int V_145 = V_441 -> V_442 -> V_7 -> V_145 ;
if ( F_209 ( & V_441 -> V_443 ) & V_428 )
V_109 = V_429 ;
V_404 = F_291 ( V_402 , V_431 , V_376 , V_345 , sizeof( struct V_406 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
F_283 ( V_404 , 128 , V_139 , V_109 , V_145 ) ;
if ( F_285 ( V_402 , V_444 , 16 , & V_441 -> V_443 ) < 0 ||
F_284 ( V_402 , V_441 -> V_445 , V_441 -> V_446 ,
V_327 , V_327 ) < 0 ) {
F_292 ( V_402 , V_404 ) ;
return - V_432 ;
}
return F_293 ( V_402 , V_404 ) ;
}
static int F_296 ( struct V_4 * V_5 , struct V_401 * V_402 ,
struct V_447 * V_448 , enum V_449 type ,
int V_450 , int * V_451 )
{
struct V_434 * V_435 ;
struct V_440 * V_441 ;
int V_111 = 1 ;
int V_452 = * V_451 ;
F_133 ( & V_5 -> V_48 ) ;
switch ( type ) {
case V_453 : {
struct V_13 * V_82 ;
F_52 (ifa, &idev->addr_list, if_list) {
if ( ++ V_452 < V_450 )
continue;
V_111 = F_290 ( V_402 , V_82 ,
F_297 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_328 ,
V_455 ) ;
if ( V_111 <= 0 )
break;
}
break;
}
case V_456 :
for ( V_435 = V_5 -> V_40 ; V_435 ;
V_435 = V_435 -> V_389 , V_452 ++ ) {
if ( V_452 < V_450 )
continue;
V_111 = F_294 ( V_402 , V_435 ,
F_297 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_457 ,
V_455 ) ;
if ( V_111 <= 0 )
break;
}
break;
case V_458 :
for ( V_441 = V_5 -> V_459 ; V_441 ;
V_441 = V_441 -> V_460 , V_452 ++ ) {
if ( V_452 < V_450 )
continue;
V_111 = F_295 ( V_402 , V_441 ,
F_297 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_461 ,
V_455 ) ;
if ( V_111 <= 0 )
break;
}
break;
default:
break;
}
F_138 ( & V_5 -> V_48 ) ;
* V_451 = V_452 ;
return V_111 ;
}
static int F_298 ( struct V_401 * V_402 , struct V_447 * V_448 ,
enum V_449 type )
{
struct V_86 * V_86 = F_278 ( V_402 -> V_405 ) ;
int V_362 , V_462 ;
int V_463 , V_452 ;
int V_464 , V_450 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_361 * V_465 ;
struct V_217 * V_218 ;
V_462 = V_448 -> args [ 0 ] ;
V_464 = V_463 = V_448 -> args [ 1 ] ;
V_450 = V_452 = V_448 -> args [ 2 ] ;
F_56 () ;
for ( V_362 = V_462 ; V_362 < V_466 ; V_362 ++ , V_464 = 0 ) {
V_463 = 0 ;
V_465 = & V_86 -> V_467 [ V_362 ] ;
F_141 (dev, node, head, index_hlist) {
if ( V_463 < V_464 )
goto V_468;
if ( V_362 > V_462 || V_463 > V_464 )
V_450 = 0 ;
V_452 = 0 ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_468;
if ( F_296 ( V_5 , V_402 , V_448 , type ,
V_450 , & V_452 ) <= 0 )
goto V_469;
V_468:
V_463 ++ ;
}
}
V_469:
F_58 () ;
V_448 -> args [ 0 ] = V_362 ;
V_448 -> args [ 1 ] = V_463 ;
V_448 -> args [ 2 ] = V_452 ;
return V_402 -> V_273 ;
}
static int F_299 ( struct V_401 * V_402 , struct V_447 * V_448 )
{
enum V_449 type = V_453 ;
return F_298 ( V_402 , V_448 , type ) ;
}
static int F_300 ( struct V_401 * V_402 , struct V_447 * V_448 )
{
enum V_449 type = V_456 ;
return F_298 ( V_402 , V_448 , type ) ;
}
static int F_301 ( struct V_401 * V_402 , struct V_447 * V_448 )
{
enum V_449 type = V_458 ;
return F_298 ( V_402 , V_448 , type ) ;
}
static int F_302 ( struct V_401 * V_470 , struct V_403 * V_404 ,
void * V_294 )
{
struct V_86 * V_86 = F_278 ( V_470 -> V_405 ) ;
struct V_406 * V_407 ;
struct V_399 * V_408 [ V_409 + 1 ] ;
struct V_104 * V_102 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_13 * V_82 ;
struct V_401 * V_402 ;
int V_111 ;
V_111 = F_279 ( V_404 , sizeof( * V_407 ) , V_408 , V_409 , V_410 ) ;
if ( V_111 < 0 )
goto V_471;
V_102 = F_274 ( V_408 [ V_411 ] , V_408 [ V_412 ] ) ;
if ( V_102 == NULL ) {
V_111 = - V_297 ;
goto V_471;
}
V_407 = F_280 ( V_404 ) ;
if ( V_407 -> V_413 )
V_7 = F_203 ( V_86 , V_407 -> V_413 ) ;
V_82 = F_145 ( V_86 , V_102 , V_7 , 1 ) ;
if ( ! V_82 ) {
V_111 = - V_116 ;
goto V_471;
}
V_402 = F_303 ( F_287 () , V_33 ) ;
if ( ! V_402 ) {
V_111 = - V_125 ;
goto V_472;
}
V_111 = F_290 ( V_402 , V_82 , F_297 ( V_470 ) . V_431 ,
V_404 -> V_454 , V_328 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_432 ) ;
F_304 ( V_402 ) ;
goto V_472;
}
V_111 = F_305 ( V_402 , V_86 , F_297 ( V_470 ) . V_431 ) ;
V_472:
F_104 ( V_82 ) ;
V_471:
return V_111 ;
}
static void F_306 ( int V_345 , struct V_13 * V_82 )
{
struct V_401 * V_402 ;
struct V_86 * V_86 = F_32 ( V_82 -> V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_402 = F_303 ( F_287 () , V_124 ) ;
if ( V_402 == NULL )
goto V_471;
V_111 = F_290 ( V_402 , V_82 , 0 , 0 , V_345 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_432 ) ;
F_304 ( V_402 ) ;
goto V_471;
}
F_307 ( V_402 , V_86 , 0 , V_473 , NULL , V_124 ) ;
return;
V_471:
if ( V_111 < 0 )
F_308 ( V_86 , V_473 , V_111 ) ;
}
static inline void F_309 ( struct V_474 * V_49 ,
T_2 * V_475 , int V_476 )
{
F_310 ( V_476 < ( V_477 * 4 ) ) ;
memset ( V_475 , 0 , V_476 ) ;
V_475 [ V_478 ] = V_49 -> V_55 ;
V_475 [ V_479 ] = V_49 -> V_480 ;
V_475 [ V_481 ] = V_49 -> V_51 ;
V_475 [ V_482 ] = V_49 -> V_374 ;
V_475 [ V_483 ] = V_49 -> V_484 ;
V_475 [ V_485 ] = V_49 -> V_284 ;
V_475 [ V_486 ] = V_49 -> V_170 ;
V_475 [ V_487 ] = V_49 -> V_68 ;
V_475 [ V_488 ] =
F_311 ( V_49 -> V_369 ) ;
V_475 [ V_489 ] =
F_311 ( V_49 -> V_368 ) ;
V_475 [ V_490 ] = V_49 -> V_491 ;
#ifdef F_41
V_475 [ V_492 ] = V_49 -> V_75 ;
V_475 [ V_493 ] = V_49 -> V_166 ;
V_475 [ V_494 ] = V_49 -> V_168 ;
V_475 [ V_495 ] = V_49 -> V_163 ;
V_475 [ V_496 ] = V_49 -> V_169 ;
#endif
V_475 [ V_497 ] = V_49 -> V_157 ;
V_475 [ V_498 ] = V_49 -> V_499 ;
V_475 [ V_500 ] = V_49 -> V_501 ;
#ifdef F_312
V_475 [ V_502 ] = V_49 -> V_503 ;
V_475 [ V_504 ] =
F_311 ( V_49 -> V_505 ) ;
#ifdef F_313
V_475 [ V_506 ] = V_49 -> V_507 ;
#endif
#endif
V_475 [ V_508 ] = V_49 -> V_509 ;
V_475 [ V_510 ] = V_49 -> V_511 ;
#ifdef F_197
V_475 [ V_512 ] = V_49 -> V_288 ;
#endif
#ifdef F_314
V_475 [ V_513 ] = V_49 -> V_514 ;
#endif
V_475 [ V_515 ] = V_49 -> V_119 ;
V_475 [ V_516 ] = V_49 -> V_61 ;
V_475 [ V_517 ] = V_49 -> V_518 ;
}
static inline T_15 F_315 ( void )
{
return F_289 ( 4 )
+ F_289 ( sizeof( struct V_519 ) )
+ F_289 ( V_477 * 4 )
+ F_289 ( V_520 * 8 )
+ F_289 ( V_521 * 8 ) ;
}
static inline T_15 F_316 ( void )
{
return F_288 ( sizeof( struct V_522 ) )
+ F_289 ( V_523 )
+ F_289 ( V_524 )
+ F_289 ( 4 )
+ F_289 ( 4 )
+ F_289 ( F_315 () ) ;
}
static inline void F_317 ( T_16 * V_27 , T_17 * V_525 ,
int V_526 , int V_476 )
{
int V_178 ;
int V_527 = V_476 - sizeof( T_16 ) * V_526 ;
F_310 ( V_527 < 0 ) ;
F_318 ( V_526 , & V_27 [ 0 ] ) ;
for ( V_178 = 1 ; V_178 < V_526 ; V_178 ++ )
F_318 ( F_319 ( & V_525 [ V_178 ] ) , & V_27 [ V_178 ] ) ;
memset ( & V_27 [ V_526 ] , 0 , V_527 ) ;
}
static inline void F_320 ( T_16 * V_27 , void V_26 * * V_525 ,
int V_526 , int V_476 , T_15 V_528 )
{
int V_178 ;
int V_527 = V_476 - sizeof( T_16 ) * V_526 ;
F_310 ( V_527 < 0 ) ;
F_318 ( V_526 , & V_27 [ 0 ] ) ;
for ( V_178 = 1 ; V_178 < V_526 ; V_178 ++ )
F_318 ( F_321 ( V_525 , V_178 , V_528 ) , & V_27 [ V_178 ] ) ;
memset ( & V_27 [ V_526 ] , 0 , V_527 ) ;
}
static void F_322 ( T_16 * V_27 , struct V_4 * V_5 , int V_529 ,
int V_476 )
{
switch ( V_529 ) {
case V_530 :
F_320 ( V_27 , ( void V_26 * * ) V_5 -> V_27 . V_28 ,
V_520 , V_476 , F_323 ( struct V_29 , V_531 ) ) ;
break;
case V_532 :
F_317 ( V_27 , V_5 -> V_27 . V_31 -> V_533 , V_521 , V_476 ) ;
break;
}
}
static int F_324 ( struct V_401 * V_402 , struct V_4 * V_5 )
{
struct V_399 * V_534 ;
struct V_519 V_418 ;
F_325 ( V_402 , V_535 , V_5 -> V_76 ) ;
V_418 . V_536 = V_537 ;
V_418 . V_78 = F_1 ( V_5 -> V_78 ) ;
V_418 . V_538 = F_311 ( V_5 -> V_53 -> V_538 ) ;
V_418 . V_171 = F_311 ( V_5 -> V_53 -> V_171 ) ;
F_326 ( V_402 , V_539 , sizeof( V_418 ) , & V_418 ) ;
V_534 = F_327 ( V_402 , V_540 , V_477 * sizeof( V_541 ) ) ;
if ( V_534 == NULL )
goto V_542;
F_309 ( & V_5 -> V_49 , F_275 ( V_534 ) , F_328 ( V_534 ) ) ;
V_534 = F_327 ( V_402 , V_530 , V_520 * sizeof( T_16 ) ) ;
if ( V_534 == NULL )
goto V_542;
F_322 ( F_275 ( V_534 ) , V_5 , V_530 , F_328 ( V_534 ) ) ;
V_534 = F_327 ( V_402 , V_532 , V_521 * sizeof( T_16 ) ) ;
if ( V_534 == NULL )
goto V_542;
F_322 ( F_275 ( V_534 ) , V_5 , V_532 , F_328 ( V_534 ) ) ;
return 0 ;
V_542:
return - V_432 ;
}
static T_15 F_329 ( const struct V_6 * V_7 )
{
if ( ! F_48 ( V_7 ) )
return 0 ;
return F_315 () ;
}
static int F_330 ( struct V_401 * V_402 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
return - V_543 ;
if ( F_324 ( V_402 , V_5 ) < 0 )
return - V_432 ;
return 0 ;
}
static int F_331 ( struct V_401 * V_402 , struct V_4 * V_5 ,
T_1 V_431 , T_1 V_376 , int V_345 , unsigned int V_58 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_522 * V_544 ;
struct V_403 * V_404 ;
void * V_545 ;
V_404 = F_291 ( V_402 , V_431 , V_376 , V_345 , sizeof( * V_544 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
V_544 = F_280 ( V_404 ) ;
V_544 -> V_546 = V_426 ;
V_544 -> V_547 = 0 ;
V_544 -> V_548 = V_7 -> type ;
V_544 -> V_549 = V_7 -> V_145 ;
V_544 -> V_550 = F_332 ( V_7 ) ;
V_544 -> V_551 = 0 ;
F_333 ( V_402 , V_552 , V_7 -> V_42 ) ;
if ( V_7 -> V_228 )
F_326 ( V_402 , V_553 , V_7 -> V_228 , V_7 -> V_230 ) ;
F_325 ( V_402 , V_554 , V_7 -> V_46 ) ;
if ( V_7 -> V_145 != V_7 -> V_342 )
F_325 ( V_402 , V_555 , V_7 -> V_342 ) ;
V_545 = F_334 ( V_402 , V_556 ) ;
if ( V_545 == NULL )
goto V_542;
if ( F_324 ( V_402 , V_5 ) < 0 )
goto V_542;
F_335 ( V_402 , V_545 ) ;
return F_293 ( V_402 , V_404 ) ;
V_542:
F_292 ( V_402 , V_404 ) ;
return - V_432 ;
}
static int F_336 ( struct V_401 * V_402 , struct V_447 * V_448 )
{
struct V_86 * V_86 = F_278 ( V_402 -> V_405 ) ;
int V_362 , V_462 ;
int V_463 = 0 , V_464 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_361 * V_465 ;
struct V_217 * V_218 ;
V_462 = V_448 -> args [ 0 ] ;
V_464 = V_448 -> args [ 1 ] ;
F_56 () ;
for ( V_362 = V_462 ; V_362 < V_466 ; V_362 ++ , V_464 = 0 ) {
V_463 = 0 ;
V_465 = & V_86 -> V_467 [ V_362 ] ;
F_141 (dev, node, head, index_hlist) {
if ( V_463 < V_464 )
goto V_468;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_468;
if ( F_331 ( V_402 , V_5 ,
F_297 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_353 , V_455 ) <= 0 )
goto V_123;
V_468:
V_463 ++ ;
}
}
V_123:
F_58 () ;
V_448 -> args [ 1 ] = V_463 ;
V_448 -> args [ 0 ] = V_362 ;
return V_402 -> V_273 ;
}
void F_232 ( int V_345 , struct V_4 * V_5 )
{
struct V_401 * V_402 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_402 = F_303 ( F_316 () , V_124 ) ;
if ( V_402 == NULL )
goto V_471;
V_111 = F_331 ( V_402 , V_5 , 0 , 0 , V_345 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_432 ) ;
F_304 ( V_402 ) ;
goto V_471;
}
F_307 ( V_402 , V_86 , 0 , V_557 , NULL , V_124 ) ;
return;
V_471:
if ( V_111 < 0 )
F_308 ( V_86 , V_557 , V_111 ) ;
}
static inline T_15 F_337 ( void )
{
return F_288 ( sizeof( struct V_558 ) )
+ F_289 ( sizeof( struct V_104 ) )
+ F_289 ( sizeof( struct V_559 ) ) ;
}
static int F_338 ( struct V_401 * V_402 , struct V_4 * V_5 ,
struct V_274 * V_275 , T_1 V_431 , T_1 V_376 ,
int V_345 , unsigned int V_58 )
{
struct V_558 * V_560 ;
struct V_403 * V_404 ;
struct V_559 V_418 ;
V_404 = F_291 ( V_402 , V_431 , V_376 , V_345 , sizeof( * V_560 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
V_560 = F_280 ( V_404 ) ;
V_560 -> V_561 = V_426 ;
V_560 -> V_562 = 0 ;
V_560 -> V_563 = 0 ;
V_560 -> V_564 = V_5 -> V_7 -> V_145 ;
V_560 -> V_128 = V_275 -> V_128 ;
V_560 -> V_565 = V_275 -> type ;
V_560 -> V_566 = 0 ;
V_560 -> V_567 = 0 ;
if ( V_275 -> V_137 )
V_560 -> V_567 |= V_568 ;
if ( V_275 -> V_284 )
V_560 -> V_567 |= V_569 ;
F_326 ( V_402 , V_570 , sizeof( V_275 -> V_144 ) , & V_275 -> V_144 ) ;
V_418 . V_571 = F_193 ( V_275 -> V_279 ) ;
V_418 . V_572 = F_193 ( V_275 -> V_278 ) ;
F_326 ( V_402 , V_573 , sizeof( V_418 ) , & V_418 ) ;
return F_293 ( V_402 , V_404 ) ;
V_542:
F_292 ( V_402 , V_404 ) ;
return - V_432 ;
}
static void F_199 ( int V_345 , struct V_4 * V_5 ,
struct V_274 * V_275 )
{
struct V_401 * V_402 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_402 = F_303 ( F_337 () , V_124 ) ;
if ( V_402 == NULL )
goto V_471;
V_111 = F_338 ( V_402 , V_5 , V_275 , 0 , 0 , V_345 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_432 ) ;
F_304 ( V_402 ) ;
goto V_471;
}
F_307 ( V_402 , V_86 , 0 , V_574 , NULL , V_124 ) ;
return;
V_471:
if ( V_111 < 0 )
F_308 ( V_86 , V_574 , V_111 ) ;
}
static void F_240 ( int V_345 , struct V_13 * V_14 )
{
F_306 ( V_345 ? : V_328 , V_14 ) ;
switch ( V_345 ) {
case V_328 :
if ( ! ( V_14 -> V_9 -> V_575 ) )
F_250 ( V_14 -> V_9 ) ;
if ( V_14 -> V_5 -> V_49 . V_55 )
F_53 ( V_14 ) ;
break;
case V_142 :
if ( V_14 -> V_5 -> V_49 . V_55 )
F_54 ( V_14 ) ;
F_155 ( V_14 -> V_5 , & V_14 -> V_102 ) ;
F_186 ( & V_14 -> V_9 -> V_99 ) ;
if ( F_114 ( V_14 -> V_9 ) )
F_339 ( & V_14 -> V_9 -> V_99 ) ;
break;
}
}
static void F_111 ( int V_345 , struct V_13 * V_14 )
{
F_79 () ;
if ( F_96 ( V_14 -> V_5 -> V_43 == 0 ) )
F_240 ( V_345 , V_14 ) ;
F_95 () ;
}
static
int F_340 ( V_89 * V_576 , int V_577 ,
void T_6 * V_578 , T_15 * V_579 , T_9 * V_580 )
{
int * V_581 = V_576 -> V_127 ;
int V_582 = * V_581 ;
T_9 V_380 = * V_580 ;
int V_156 ;
V_156 = F_341 ( V_576 , V_577 , V_578 , V_579 , V_580 ) ;
if ( V_577 )
V_156 = F_59 ( V_576 , V_581 , V_582 ) ;
if ( V_156 )
* V_580 = V_380 ;
return V_156 ;
}
static void F_342 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_49 . V_119 )
F_228 ( NULL , V_143 , V_5 -> V_7 ) ;
else
F_228 ( NULL , V_134 , V_5 -> V_7 ) ;
}
static void F_343 ( struct V_86 * V_86 , T_2 V_87 )
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
F_342 ( V_5 ) ;
}
}
F_58 () ;
}
static int F_344 ( struct V_89 * V_90 , int * V_91 , int V_92 )
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
F_343 ( V_86 , V_87 ) ;
} else if ( ( ! * V_91 ) ^ ( ! V_92 ) )
F_342 ( (struct V_4 * ) V_90 -> V_95 ) ;
F_62 () ;
return 0 ;
}
static
int F_345 ( V_89 * V_576 , int V_577 ,
void T_6 * V_578 , T_15 * V_579 , T_9 * V_580 )
{
int * V_581 = V_576 -> V_127 ;
int V_582 = * V_581 ;
T_9 V_380 = * V_580 ;
int V_156 ;
V_156 = F_341 ( V_576 , V_577 , V_578 , V_579 , V_580 ) ;
if ( V_577 )
V_156 = F_344 ( V_576 , V_581 , V_582 ) ;
if ( V_156 )
* V_580 = V_380 ;
return V_156 ;
}
static int F_346 ( struct V_86 * V_86 , char * V_583 ,
struct V_4 * V_5 , struct V_474 * V_91 )
{
int V_178 ;
struct V_584 * V_585 ;
#define F_347 3
struct V_586 V_587 [] = {
{ . V_588 = L_39 , } ,
{ . V_588 = L_40 , } ,
{ . V_588 = L_41 , } ,
{ } ,
{ } ,
} ;
V_585 = F_348 ( & V_589 , sizeof( * V_585 ) , V_33 ) ;
if ( V_585 == NULL )
goto V_123;
for ( V_178 = 0 ; V_585 -> V_590 [ V_178 ] . V_127 ; V_178 ++ ) {
V_585 -> V_590 [ V_178 ] . V_127 += ( char * ) V_91 - ( char * ) & V_474 ;
V_585 -> V_590 [ V_178 ] . V_95 = V_5 ;
V_585 -> V_590 [ V_178 ] . V_93 = V_86 ;
}
V_585 -> V_583 = F_349 ( V_583 , V_33 ) ;
if ( ! V_585 -> V_583 )
goto free;
V_587 [ F_347 ] . V_588 = V_585 -> V_583 ;
V_585 -> V_591 = F_350 ( V_86 , V_587 ,
V_585 -> V_590 ) ;
if ( V_585 -> V_591 == NULL )
goto V_592;
V_91 -> V_52 = V_585 ;
return 0 ;
V_592:
F_17 ( V_585 -> V_583 ) ;
free:
F_17 ( V_585 ) ;
V_123:
return - V_125 ;
}
static void F_351 ( struct V_474 * V_91 )
{
struct V_584 * V_585 ;
if ( V_91 -> V_52 == NULL )
return;
V_585 = V_91 -> V_52 ;
V_91 -> V_52 = NULL ;
F_352 ( V_585 -> V_591 ) ;
F_17 ( V_585 -> V_583 ) ;
F_17 ( V_585 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_353 ( V_5 -> V_7 , V_5 -> V_53 , L_40 ,
& V_593 ) ;
F_346 ( F_32 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_42 ,
V_5 , & V_5 -> V_49 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_351 ( & V_5 -> V_49 ) ;
F_354 ( V_5 -> V_53 ) ;
}
static int T_11 F_355 ( struct V_86 * V_86 )
{
int V_111 ;
struct V_474 * V_594 , * V_595 ;
V_111 = - V_38 ;
V_594 = & V_474 ;
V_595 = & V_596 ;
if ( ! F_142 ( V_86 , & V_597 ) ) {
V_594 = F_348 ( V_594 , sizeof( V_474 ) , V_33 ) ;
if ( V_594 == NULL )
goto V_598;
V_595 = F_348 ( V_595 , sizeof( V_596 ) , V_33 ) ;
if ( V_595 == NULL )
goto V_599;
} else {
V_595 -> V_284 = V_600 . V_284 ;
V_595 -> V_119 = V_600 . V_119 ;
}
V_86 -> V_28 . V_94 = V_594 ;
V_86 -> V_28 . V_50 = V_595 ;
#ifdef F_356
V_111 = F_346 ( V_86 , L_42 , NULL , V_594 ) ;
if ( V_111 < 0 )
goto V_601;
V_111 = F_346 ( V_86 , L_43 , NULL , V_595 ) ;
if ( V_111 < 0 )
goto V_602;
#endif
return 0 ;
#ifdef F_356
V_602:
F_351 ( V_594 ) ;
V_601:
F_17 ( V_595 ) ;
#endif
V_599:
F_17 ( V_594 ) ;
V_598:
return V_111 ;
}
static void T_12 F_357 ( struct V_86 * V_86 )
{
#ifdef F_356
F_351 ( V_86 -> V_28 . V_50 ) ;
F_351 ( V_86 -> V_28 . V_94 ) ;
#endif
if ( ! F_142 ( V_86 , & V_597 ) ) {
F_17 ( V_86 -> V_28 . V_50 ) ;
F_17 ( V_86 -> V_28 . V_94 ) ;
}
}
int F_358 ( struct V_343 * V_603 )
{
return F_359 ( & V_133 , V_603 ) ;
}
int F_360 ( struct V_343 * V_603 )
{
return F_361 ( & V_133 , V_603 ) ;
}
int T_13 F_362 ( void )
{
int V_178 , V_111 ;
V_111 = F_363 () ;
if ( V_111 < 0 ) {
F_24 ( V_604 L_44
L_45 , V_111 ) ;
goto V_123;
}
V_111 = F_269 ( & V_605 ) ;
if ( V_111 < 0 )
goto V_606;
F_201 () ;
if ( ! F_28 ( V_597 . V_607 ) )
V_111 = - V_38 ;
F_62 () ;
if ( V_111 )
goto V_608;
for ( V_178 = 0 ; V_178 < V_107 ; V_178 ++ )
F_364 ( & V_130 [ V_178 ] ) ;
F_365 ( & V_609 ) ;
F_198 ( 0 ) ;
V_111 = F_366 ( & V_610 ) ;
if ( V_111 < 0 )
goto V_611;
V_111 = F_367 ( V_612 , V_613 , NULL , F_336 ,
NULL ) ;
if ( V_111 < 0 )
goto V_471;
F_367 ( V_612 , V_328 , F_282 , NULL , NULL ) ;
F_367 ( V_612 , V_142 , F_277 , NULL , NULL ) ;
F_367 ( V_612 , V_614 , F_302 ,
F_299 , NULL ) ;
F_367 ( V_612 , V_457 , NULL ,
F_300 , NULL ) ;
F_367 ( V_612 , V_461 , NULL ,
F_301 , NULL ) ;
F_368 () ;
return 0 ;
V_471:
F_369 ( & V_610 ) ;
V_611:
F_370 ( & V_609 ) ;
V_608:
F_271 ( & V_605 ) ;
V_606:
F_371 () ;
V_123:
return V_111 ;
}
void F_372 ( void )
{
struct V_6 * V_7 ;
int V_178 ;
F_370 ( & V_609 ) ;
F_271 ( & V_605 ) ;
F_371 () ;
F_201 () ;
F_373 ( & V_610 ) ;
F_217 (&init_net, dev) {
if ( F_48 ( V_7 ) == NULL )
continue;
F_211 ( V_7 , 1 ) ;
}
F_211 ( V_597 . V_607 , 2 ) ;
F_99 ( & V_121 ) ;
for ( V_178 = 0 ; V_178 < V_107 ; V_178 ++ )
F_21 ( ! F_374 ( & V_130 [ V_178 ] ) ) ;
F_100 ( & V_121 ) ;
F_8 ( & V_394 ) ;
F_62 () ;
}
