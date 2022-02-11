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
if ( V_45 -> V_49 . V_55 && ( V_7 -> V_58 & V_81 ) )
F_46 ( V_7 , & V_82 ) ;
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
if ( V_7 -> V_58 & V_83 )
F_49 ( V_5 ) ;
return V_5 ;
}
static void F_50 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_13 * V_84 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_49 . V_55 )
F_34 ( V_7 ) ;
if ( V_7 && ( V_7 -> V_58 & V_81 ) ) {
if ( V_5 -> V_49 . V_55 )
F_46 ( V_7 , & V_82 ) ;
else
F_51 ( V_7 , & V_82 ) ;
}
F_52 (ifa, &idev->addr_list, if_list) {
if ( V_84 -> V_58 & V_85 )
continue;
if ( V_5 -> V_49 . V_55 )
F_53 ( V_84 ) ;
else
F_54 ( V_84 ) ;
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
static int F_59 ( struct V_89 * V_90 , int * V_91 , int V_87 )
{
struct V_86 * V_86 ;
int V_92 ;
if ( ! F_60 () )
return F_61 () ;
V_86 = (struct V_86 * ) V_90 -> V_93 ;
V_92 = * V_91 ;
* V_91 = V_87 ;
if ( V_91 == & V_86 -> V_28 . V_50 -> V_55 ) {
F_62 () ;
return 0 ;
}
if ( V_91 == & V_86 -> V_28 . V_94 -> V_55 ) {
V_86 -> V_28 . V_50 -> V_55 = V_87 ;
F_55 ( V_86 , V_87 ) ;
} else if ( ( ! V_87 ) ^ ( ! V_92 ) )
F_50 ( (struct V_4 * ) V_90 -> V_95 ) ;
F_62 () ;
if ( V_87 )
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
struct V_13 * V_84
= F_72 ( V_91 , struct V_13 , V_103 ) ;
if ( V_101 >= F_70 ( & V_84 -> V_102 ) )
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
struct V_13 * V_84 = NULL ;
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
V_84 = F_16 ( sizeof( struct V_13 ) , V_124 ) ;
if ( V_84 == NULL ) {
F_36 ( ( L_11 ) ) ;
V_111 = - V_125 ;
goto V_123;
}
V_9 = F_82 ( V_5 , V_102 , false ) ;
if ( F_83 ( V_9 ) ) {
V_111 = F_84 ( V_9 ) ;
goto V_123;
}
V_84 -> V_102 = * V_102 ;
F_85 ( & V_84 -> V_48 ) ;
F_85 ( & V_84 -> V_126 ) ;
F_86 ( & V_84 -> V_15 ) ;
F_87 ( & V_84 -> V_96 ) ;
V_84 -> V_15 . V_127 = ( unsigned long ) V_84 ;
V_84 -> V_109 = V_109 ;
V_84 -> V_128 = V_108 ;
V_84 -> V_58 = V_58 | V_85 ;
V_84 -> V_1 = V_84 -> V_78 = V_25 ;
V_84 -> V_9 = V_9 ;
V_84 -> V_5 = V_5 ;
F_39 ( V_5 ) ;
F_11 ( V_84 ) ;
V_110 = F_74 ( V_102 ) ;
F_88 ( & V_84 -> V_96 , & V_129 [ V_110 ] ) ;
F_89 ( & V_121 ) ;
F_90 ( & V_5 -> V_48 ) ;
F_69 ( V_5 , V_84 ) ;
#ifdef F_41
if ( V_84 -> V_58 & V_130 ) {
F_91 ( & V_84 -> V_131 , & V_5 -> V_69 ) ;
F_11 ( V_84 ) ;
}
#endif
F_11 ( V_84 ) ;
F_92 ( & V_5 -> V_48 ) ;
V_118:
F_93 () ;
if ( F_94 ( V_111 == 0 ) )
F_95 ( & V_132 , V_133 , V_84 ) ;
else {
F_17 ( V_84 ) ;
V_84 = F_78 ( V_111 ) ;
}
return V_84 ;
V_123:
F_89 ( & V_121 ) ;
goto V_118;
}
static void F_96 ( struct V_13 * V_14 )
{
struct V_13 * V_84 , * V_134 ;
struct V_4 * V_5 = V_14 -> V_5 ;
int V_97 ;
int V_135 = 0 , V_136 = 0 ;
unsigned long V_24 = V_25 ;
F_97 ( & V_14 -> V_126 ) ;
V_97 = V_14 -> V_97 ;
V_14 -> V_97 = V_98 ;
F_98 ( & V_14 -> V_126 ) ;
if ( V_97 == V_98 )
goto V_123;
F_97 ( & V_121 ) ;
F_99 ( & V_14 -> V_96 ) ;
F_98 ( & V_121 ) ;
F_100 ( & V_5 -> V_48 ) ;
#ifdef F_41
if ( V_14 -> V_58 & V_130 ) {
F_101 ( & V_14 -> V_131 ) ;
if ( V_14 -> V_137 ) {
F_102 ( V_14 -> V_137 ) ;
V_14 -> V_137 = NULL ;
}
F_9 ( V_14 ) ;
}
#endif
F_103 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_84 == V_14 ) {
F_104 ( & V_14 -> V_103 ) ;
F_9 ( V_14 ) ;
if ( ! ( V_14 -> V_58 & V_138 ) || V_136 > 0 )
break;
V_135 = 1 ;
continue;
} else if ( V_14 -> V_58 & V_138 ) {
if ( F_105 ( & V_84 -> V_102 , & V_14 -> V_102 ,
V_14 -> V_128 ) ) {
if ( V_84 -> V_58 & V_138 ) {
V_136 = 1 ;
if ( V_135 )
break;
} else {
unsigned long V_139 ;
if ( ! V_136 )
V_136 = - 1 ;
F_80 ( & V_84 -> V_48 ) ;
V_139 = F_106 ( V_84 -> V_140 , V_3 ) ;
if ( F_107 ( V_24 ,
V_84 -> V_78 + V_139 * V_3 ) )
V_24 = V_84 -> V_78 + V_139 * V_3 ;
F_89 ( & V_84 -> V_48 ) ;
}
}
}
}
F_108 ( & V_5 -> V_48 ) ;
F_7 ( V_14 ) ;
F_109 ( V_141 , V_14 ) ;
F_95 ( & V_132 , V_142 , V_14 ) ;
if ( ( V_14 -> V_58 & V_138 ) && V_136 < 1 ) {
struct V_104 V_143 ;
struct V_8 * V_9 ;
struct V_86 * V_86 = F_32 ( V_14 -> V_5 -> V_7 ) ;
F_110 ( & V_143 , & V_14 -> V_102 , V_14 -> V_128 ) ;
V_9 = F_111 ( V_86 , & V_143 , NULL , V_14 -> V_5 -> V_7 -> V_144 , 1 ) ;
if ( V_9 && F_6 ( V_9 ) ) {
if ( V_136 == 0 ) {
F_112 ( V_9 ) ;
V_9 = NULL ;
} else if ( ! ( V_9 -> V_10 & V_145 ) ) {
F_113 ( V_9 , V_24 ) ;
}
}
F_68 ( & V_9 -> V_99 ) ;
}
F_114 ( V_14 ) ;
V_123:
F_102 ( V_14 ) ;
}
static int F_115 ( struct V_13 * V_14 , struct V_13 * V_146 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_104 V_102 , * V_147 ;
unsigned long V_148 , V_149 , V_150 , V_151 ;
unsigned long V_152 ;
int V_153 ;
int V_154 = 0 ;
int V_155 ;
T_1 V_156 ;
unsigned long V_157 = V_25 ;
F_90 ( & V_5 -> V_48 ) ;
if ( V_146 ) {
F_97 ( & V_146 -> V_48 ) ;
memcpy ( & V_102 . V_158 [ 8 ] , & V_146 -> V_102 . V_158 [ 8 ] , 8 ) ;
F_98 ( & V_146 -> V_48 ) ;
V_147 = & V_102 ;
} else {
V_147 = NULL ;
}
V_159:
F_39 ( V_5 ) ;
if ( V_5 -> V_49 . V_75 <= 0 ) {
F_92 ( & V_5 -> V_48 ) ;
F_24 ( V_67
L_12 ) ;
F_66 ( V_5 ) ;
V_154 = - 1 ;
goto V_123;
}
F_97 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_160 ++ >= V_5 -> V_49 . V_161 ) {
V_5 -> V_49 . V_75 = - 1 ;
F_98 ( & V_14 -> V_48 ) ;
F_92 ( & V_5 -> V_48 ) ;
F_24 ( V_56
L_13 ) ;
F_66 ( V_5 ) ;
V_154 = - 1 ;
goto V_123;
}
F_11 ( V_14 ) ;
memcpy ( V_102 . V_158 , V_14 -> V_102 . V_158 , 8 ) ;
if ( F_116 ( V_5 , V_147 ) < 0 ) {
F_98 ( & V_14 -> V_48 ) ;
F_92 ( & V_5 -> V_48 ) ;
F_24 ( V_56
L_14 ) ;
F_102 ( V_14 ) ;
F_66 ( V_5 ) ;
V_154 = - 1 ;
goto V_123;
}
memcpy ( & V_102 . V_158 [ 8 ] , V_5 -> V_162 , 8 ) ;
V_151 = ( V_157 - V_14 -> V_78 ) / V_3 ;
V_149 = F_117 ( V_163 ,
V_14 -> V_140 ,
V_5 -> V_49 . V_164 + V_151 ) ;
V_148 = F_117 ( V_163 ,
V_14 -> V_165 ,
V_5 -> V_49 . V_166 + V_151 -
V_5 -> V_49 . V_167 ) ;
V_153 = V_14 -> V_128 ;
V_155 = V_5 -> V_49 . V_155 ;
V_150 = V_14 -> V_78 ;
F_98 ( & V_14 -> V_48 ) ;
V_152 = V_5 -> V_49 . V_161 *
V_5 -> V_49 . V_168 *
V_5 -> V_53 -> V_169 / V_3 ;
F_92 ( & V_5 -> V_48 ) ;
if ( V_148 <= V_152 ) {
F_102 ( V_14 ) ;
F_66 ( V_5 ) ;
V_154 = - 1 ;
goto V_123;
}
V_156 = V_130 ;
if ( V_14 -> V_58 & V_170 )
V_156 |= V_170 ;
V_146 = ! V_155 ||
F_118 ( V_5 ) < V_155 ?
F_76 ( V_5 , & V_102 , V_153 ,
F_77 ( & V_102 ) & V_171 ,
V_156 ) : NULL ;
if ( ! V_146 || F_83 ( V_146 ) ) {
F_102 ( V_14 ) ;
F_66 ( V_5 ) ;
F_24 ( V_67
L_15 ) ;
V_147 = & V_102 ;
F_90 ( & V_5 -> V_48 ) ;
goto V_159;
}
F_97 ( & V_146 -> V_48 ) ;
V_146 -> V_137 = V_14 ;
V_146 -> V_140 = V_149 ;
V_146 -> V_165 = V_148 ;
V_146 -> V_1 = V_157 ;
V_146 -> V_78 = V_150 ;
F_98 ( & V_146 -> V_48 ) ;
F_119 ( V_146 , 0 ) ;
F_102 ( V_146 ) ;
F_66 ( V_5 ) ;
V_123:
return V_154 ;
}
static inline int F_120 ( int type )
{
if ( type & ( V_172 | V_173 | V_115 ) )
return 1 ;
return 0 ;
}
static int F_121 ( struct V_86 * V_86 ,
struct V_174 * V_175 ,
struct V_176 * V_99 ,
int V_177 )
{
int V_154 ;
if ( V_177 <= V_175 -> V_178 ) {
switch ( V_177 ) {
case V_179 :
V_154 = V_175 -> V_180 ;
break;
case V_181 :
V_154 = V_175 -> V_182 ;
break;
default:
V_154 = ! ! F_122 ( V_177 , V_175 -> V_183 ) ;
}
goto V_123;
}
switch ( V_177 ) {
case V_184 :
V_154 = ! ! V_175 -> V_84 ;
break;
case V_185 :
V_154 = F_123 ( & V_175 -> V_84 -> V_102 , V_99 -> V_102 ) ;
break;
case V_179 :
V_154 = F_124 ( V_175 -> V_112 ) ;
if ( V_154 >= V_99 -> V_109 )
V_154 = - V_154 ;
else
V_154 -= 128 ;
V_175 -> V_180 = V_154 ;
break;
case V_186 :
V_154 = F_120 ( V_175 -> V_112 ) ||
! ( V_175 -> V_84 -> V_58 & ( V_187 | V_170 ) ) ;
break;
#ifdef F_125
case V_188 :
{
int V_189 = ! ( V_99 -> V_190 & V_191 ) ;
V_154 = ! ( V_175 -> V_84 -> V_58 & V_192 ) ^ V_189 ;
break;
}
#endif
case V_193 :
V_154 = ( ! V_99 -> V_144 ||
V_99 -> V_144 == V_175 -> V_84 -> V_5 -> V_7 -> V_144 ) ;
break;
case V_194 :
V_154 = F_126 ( V_86 ,
& V_175 -> V_84 -> V_102 , V_175 -> V_112 ,
V_175 -> V_84 -> V_5 -> V_7 -> V_144 ) == V_99 -> V_195 ;
break;
#ifdef F_41
case V_196 :
{
int V_197 = V_99 -> V_190 & ( V_198 | V_199 ) ?
! ! ( V_99 -> V_190 & V_199 ) :
V_175 -> V_84 -> V_5 -> V_49 . V_75 >= 2 ;
V_154 = ( ! ( V_175 -> V_84 -> V_58 & V_130 ) ) ^ V_197 ;
break;
}
#endif
case V_200 :
V_154 = ! ( F_127 ( & V_175 -> V_84 -> V_102 ) ^
F_127 ( V_99 -> V_102 ) ) ;
break;
case V_181 :
V_175 -> V_182 = V_154 = F_128 ( & V_175 -> V_84 -> V_102 ,
V_99 -> V_102 ) ;
break;
default:
V_154 = 0 ;
}
if ( V_154 )
F_129 ( V_177 , V_175 -> V_183 ) ;
V_175 -> V_178 = V_177 ;
V_123:
return V_154 ;
}
int F_130 ( struct V_86 * V_86 , struct V_6 * V_201 ,
const struct V_104 * V_202 , unsigned int V_190 ,
struct V_104 * V_203 )
{
struct V_174 V_204 [ 2 ] ,
* V_175 = & V_204 [ 0 ] , * V_205 = & V_204 [ 1 ] ;
struct V_176 V_99 ;
struct V_6 * V_7 ;
int V_206 ;
V_206 = F_131 ( V_202 ) ;
V_99 . V_102 = V_202 ;
V_99 . V_144 = V_201 ? V_201 -> V_144 : 0 ;
V_99 . V_109 = F_124 ( V_206 ) ;
V_99 . V_195 = F_126 ( V_86 , V_202 , V_206 , V_99 . V_144 ) ;
V_99 . V_190 = V_190 ;
V_205 -> V_178 = - 1 ;
V_205 -> V_84 = NULL ;
F_56 () ;
F_57 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_206 & V_114 ) ||
V_99 . V_109 <= V_207 ) &&
V_99 . V_144 && V_7 -> V_144 != V_99 . V_144 )
continue;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
continue;
F_132 ( & V_5 -> V_48 ) ;
F_52 (score->ifa, &idev->addr_list, if_list) {
int V_177 ;
if ( ( V_175 -> V_84 -> V_58 & V_85 ) &&
( ! ( V_175 -> V_84 -> V_58 & V_170 ) ) )
continue;
V_175 -> V_112 = F_131 ( & V_175 -> V_84 -> V_102 ) ;
if ( F_133 ( V_175 -> V_112 == V_113 ||
V_175 -> V_112 & V_114 ) ) {
F_134 ( V_41
L_16
L_17 ,
V_7 -> V_42 ) ;
continue;
}
V_175 -> V_178 = - 1 ;
F_135 ( V_175 -> V_183 , V_208 ) ;
for ( V_177 = 0 ; V_177 < V_208 ; V_177 ++ ) {
int V_209 , V_210 ;
V_209 = F_121 ( V_86 , V_205 , & V_99 , V_177 ) ;
V_210 = F_121 ( V_86 , V_175 , & V_99 , V_177 ) ;
if ( V_209 > V_210 ) {
if ( V_177 == V_179 &&
V_175 -> V_180 > 0 ) {
goto V_211;
}
break;
} else if ( V_209 < V_210 ) {
if ( V_205 -> V_84 )
F_102 ( V_205 -> V_84 ) ;
F_11 ( V_175 -> V_84 ) ;
F_136 ( V_205 , V_175 ) ;
V_175 -> V_84 = V_205 -> V_84 ;
break;
}
}
}
V_211:
F_137 ( & V_5 -> V_48 ) ;
}
F_58 () ;
if ( ! V_205 -> V_84 )
return - V_116 ;
* V_203 = V_205 -> V_84 -> V_102 ;
F_102 ( V_205 -> V_84 ) ;
return 0 ;
}
int F_138 ( struct V_6 * V_7 , struct V_104 * V_102 ,
unsigned char V_212 )
{
struct V_4 * V_5 ;
int V_111 = - V_116 ;
F_56 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
struct V_13 * V_14 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_109 == V_213 &&
! ( V_14 -> V_58 & V_212 ) ) {
* V_102 = V_14 -> V_102 ;
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
int V_214 = 0 ;
struct V_13 * V_14 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list)
V_214 ++ ;
F_137 ( & V_5 -> V_48 ) ;
return V_214 ;
}
int F_139 ( struct V_86 * V_86 , const struct V_104 * V_102 ,
struct V_6 * V_7 , int V_215 )
{
struct V_13 * V_14 ;
struct V_216 * V_217 ;
unsigned int V_110 = F_74 ( V_102 ) ;
F_79 () ;
F_140 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_141 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_123 ( & V_14 -> V_102 , V_102 ) &&
! ( V_14 -> V_58 & V_85 ) &&
( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_109 & ( V_213 | V_218 ) || V_215 ) ) ) {
F_93 () ;
return 1 ;
}
}
F_93 () ;
return 0 ;
}
static bool F_81 ( struct V_86 * V_86 , const struct V_104 * V_102 ,
struct V_6 * V_7 )
{
unsigned int V_110 = F_74 ( V_102 ) ;
struct V_13 * V_14 ;
struct V_216 * V_217 ;
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
struct V_13 * V_84 ;
int V_136 ;
V_136 = 0 ;
F_56 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifa, &idev->addr_list, if_list) {
V_136 = F_105 ( V_102 , & V_84 -> V_102 ,
V_84 -> V_128 ) ;
if ( V_136 )
break;
}
F_137 ( & V_5 -> V_48 ) ;
}
F_58 () ;
return V_136 ;
}
struct V_13 * F_144 ( struct V_86 * V_86 , const struct V_104 * V_102 ,
struct V_6 * V_7 , int V_215 )
{
struct V_13 * V_14 , * V_219 = NULL ;
unsigned int V_110 = F_74 ( V_102 ) ;
struct V_216 * V_217 ;
F_79 () ;
F_145 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_141 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_123 ( & V_14 -> V_102 , V_102 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_109 & ( V_213 | V_218 ) || V_215 ) ) {
V_219 = V_14 ;
F_11 ( V_14 ) ;
break;
}
}
}
F_93 () ;
return V_219 ;
}
static void F_146 ( struct V_13 * V_14 , int V_220 )
{
if ( V_14 -> V_58 & V_138 ) {
F_97 ( & V_14 -> V_48 ) ;
F_7 ( V_14 ) ;
V_14 -> V_58 |= V_85 ;
if ( V_220 )
V_14 -> V_58 |= V_221 ;
F_98 ( & V_14 -> V_48 ) ;
if ( V_220 )
F_109 ( 0 , V_14 ) ;
F_102 ( V_14 ) ;
#ifdef F_41
} else if ( V_14 -> V_58 & V_130 ) {
struct V_13 * V_137 ;
F_97 ( & V_14 -> V_48 ) ;
V_137 = V_14 -> V_137 ;
if ( V_137 ) {
F_11 ( V_137 ) ;
F_98 ( & V_14 -> V_48 ) ;
F_115 ( V_137 , V_14 ) ;
F_102 ( V_137 ) ;
} else {
F_98 ( & V_14 -> V_48 ) ;
}
F_96 ( V_14 ) ;
#endif
} else
F_96 ( V_14 ) ;
}
static int F_147 ( struct V_13 * V_14 )
{
int V_111 = - V_222 ;
F_80 ( & V_14 -> V_126 ) ;
if ( V_14 -> V_97 == V_223 ) {
V_14 -> V_97 = V_224 ;
V_111 = 0 ;
}
F_89 ( & V_14 -> V_126 ) ;
return V_111 ;
}
void F_148 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
if ( F_147 ( V_14 ) ) {
F_102 ( V_14 ) ;
return;
}
if ( F_149 () )
F_24 ( V_67 L_18 ,
V_14 -> V_5 -> V_7 -> V_42 , & V_14 -> V_102 ) ;
if ( V_5 -> V_49 . V_61 > 1 && ! V_5 -> V_49 . V_119 ) {
struct V_104 V_102 ;
V_102 . V_106 [ 0 ] = F_150 ( 0xfe800000 ) ;
V_102 . V_106 [ 1 ] = 0 ;
if ( ! F_151 ( V_102 . V_158 + 8 , V_5 -> V_7 ) &&
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
struct V_104 V_225 ;
if ( V_7 -> V_58 & ( V_60 | V_59 ) )
return;
F_153 ( V_102 , & V_225 ) ;
F_46 ( V_7 , & V_225 ) ;
}
void F_154 ( struct V_4 * V_5 , const struct V_104 * V_102 )
{
struct V_104 V_225 ;
if ( V_5 -> V_7 -> V_58 & ( V_60 | V_59 ) )
return;
F_153 ( V_102 , & V_225 ) ;
F_155 ( V_5 , & V_225 ) ;
}
static void F_53 ( struct V_13 * V_14 )
{
struct V_104 V_102 ;
if ( V_14 -> V_128 == 127 )
return;
F_110 ( & V_102 , & V_14 -> V_102 , V_14 -> V_128 ) ;
if ( F_156 ( & V_102 ) )
return;
F_157 ( V_14 -> V_5 -> V_7 , & V_102 ) ;
}
static void F_54 ( struct V_13 * V_14 )
{
struct V_104 V_102 ;
if ( V_14 -> V_128 == 127 )
return;
F_110 ( & V_102 , & V_14 -> V_102 , V_14 -> V_128 ) ;
if ( F_156 ( & V_102 ) )
return;
F_158 ( V_14 -> V_5 , & V_102 ) ;
}
static int F_159 ( T_3 * V_226 , struct V_6 * V_7 )
{
if ( V_7 -> V_227 != V_228 )
return - 1 ;
memcpy ( V_226 , V_7 -> V_229 , 3 ) ;
memcpy ( V_226 + 5 , V_7 -> V_229 + 3 , 3 ) ;
if ( V_7 -> V_230 ) {
V_226 [ 3 ] = ( V_7 -> V_230 >> 8 ) & 0xFF ;
V_226 [ 4 ] = V_7 -> V_230 & 0xFF ;
} else {
V_226 [ 3 ] = 0xFF ;
V_226 [ 4 ] = 0xFE ;
V_226 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_160 ( T_3 * V_226 , struct V_6 * V_7 )
{
if ( V_7 -> V_227 != V_231 )
return - 1 ;
memset ( V_226 , 0 , 7 ) ;
V_226 [ 7 ] = * ( T_3 * ) V_7 -> V_229 ;
return 0 ;
}
static int F_161 ( T_3 * V_226 , struct V_6 * V_7 )
{
if ( V_7 -> V_227 != V_232 )
return - 1 ;
memcpy ( V_226 , V_7 -> V_229 + 12 , 8 ) ;
V_226 [ 0 ] |= 2 ;
return 0 ;
}
static int F_162 ( T_3 * V_226 , T_4 V_102 )
{
if ( V_102 == 0 )
return - 1 ;
V_226 [ 0 ] = ( F_163 ( V_102 ) || F_164 ( V_102 ) ||
F_165 ( V_102 ) || F_166 ( V_102 ) ||
F_167 ( V_102 ) || F_168 ( V_102 ) ||
F_169 ( V_102 ) || F_170 ( V_102 ) ||
F_171 ( V_102 ) || F_172 ( V_102 ) ||
F_173 ( V_102 ) ) ? 0x00 : 0x02 ;
V_226 [ 1 ] = 0 ;
V_226 [ 2 ] = 0x5E ;
V_226 [ 3 ] = 0xFE ;
memcpy ( V_226 + 4 , & V_102 , 4 ) ;
return 0 ;
}
static int F_174 ( T_3 * V_226 , struct V_6 * V_7 )
{
if ( V_7 -> V_65 & V_66 )
return F_162 ( V_226 , * ( T_4 * ) V_7 -> V_229 ) ;
return - 1 ;
}
static int F_175 ( T_3 * V_226 , struct V_6 * V_7 )
{
return F_162 ( V_226 , * ( T_4 * ) V_7 -> V_229 ) ;
}
static int F_151 ( T_3 * V_226 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_233 :
case V_234 :
case V_235 :
return F_159 ( V_226 , V_7 ) ;
case V_236 :
return F_160 ( V_226 , V_7 ) ;
case V_237 :
return F_161 ( V_226 , V_7 ) ;
case V_64 :
return F_174 ( V_226 , V_7 ) ;
case V_238 :
return F_175 ( V_226 , V_7 ) ;
}
return - 1 ;
}
static int F_176 ( T_3 * V_226 , struct V_4 * V_5 )
{
int V_111 = - 1 ;
struct V_13 * V_14 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_109 == V_213 && ! ( V_14 -> V_58 & V_85 ) ) {
memcpy ( V_226 , V_14 -> V_102 . V_158 + 8 , 8 ) ;
V_111 = 0 ;
break;
}
}
F_137 ( & V_5 -> V_48 ) ;
return V_111 ;
}
static int F_177 ( struct V_4 * V_5 )
{
V_239:
F_178 ( V_5 -> V_162 , sizeof( V_5 -> V_162 ) ) ;
V_5 -> V_162 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_162 [ 0 ] == 0xfd &&
( V_5 -> V_162 [ 1 ] & V_5 -> V_162 [ 2 ] & V_5 -> V_162 [ 3 ] & V_5 -> V_162 [ 4 ] & V_5 -> V_162 [ 5 ] & V_5 -> V_162 [ 6 ] ) == 0xff &&
( V_5 -> V_162 [ 7 ] & 0x80 ) )
goto V_239;
if ( ( V_5 -> V_162 [ 0 ] | V_5 -> V_162 [ 1 ] ) == 0 ) {
if ( V_5 -> V_162 [ 2 ] == 0x5e && V_5 -> V_162 [ 3 ] == 0xfe )
goto V_239;
if ( ( V_5 -> V_162 [ 2 ] | V_5 -> V_162 [ 3 ] | V_5 -> V_162 [ 4 ] | V_5 -> V_162 [ 5 ] | V_5 -> V_162 [ 6 ] | V_5 -> V_162 [ 7 ] ) == 0x00 )
goto V_239;
}
return 0 ;
}
static void V_71 ( unsigned long V_127 )
{
struct V_4 * V_5 = (struct V_4 * ) V_127 ;
unsigned long V_24 ;
F_79 () ;
F_100 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 )
goto V_123;
if ( F_177 ( V_5 ) < 0 )
goto V_123;
V_24 = V_25 +
V_5 -> V_49 . V_166 * V_3 -
V_5 -> V_49 . V_161 * V_5 -> V_49 . V_168 * V_5 -> V_53 -> V_169 -
V_5 -> V_49 . V_167 * V_3 ;
if ( F_107 ( V_24 , V_25 ) ) {
F_24 ( V_56
L_20 ,
V_5 -> V_7 -> V_42 ) ;
goto V_123;
}
if ( ! F_179 ( & V_5 -> V_70 , V_24 ) )
F_39 ( V_5 ) ;
V_123:
F_108 ( & V_5 -> V_48 ) ;
F_93 () ;
F_66 ( V_5 ) ;
}
static int F_116 ( struct V_4 * V_5 , struct V_104 * V_147 ) {
int V_154 = 0 ;
if ( V_147 && memcmp ( V_5 -> V_162 , & V_147 -> V_158 [ 8 ] , 8 ) == 0 )
V_154 = F_177 ( V_5 ) ;
return V_154 ;
}
static void
F_180 ( struct V_104 * V_240 , int V_241 , struct V_6 * V_7 ,
unsigned long V_24 , T_1 V_58 )
{
struct V_242 V_243 = {
. V_244 = V_245 ,
. V_246 = V_247 ,
. V_248 = V_7 -> V_144 ,
. V_249 = V_24 ,
. V_250 = V_241 ,
. V_251 = V_252 | V_58 ,
. V_253 . V_254 = F_32 ( V_7 ) ,
. V_255 = V_256 ,
} ;
V_243 . V_257 = * V_240 ;
#if F_40 ( V_62 ) || F_40 ( V_63 )
if ( V_7 -> type == V_64 && ( V_7 -> V_58 & V_258 ) )
V_243 . V_251 |= V_259 ;
#endif
F_181 ( & V_243 ) ;
}
static struct V_8 * F_182 ( const struct V_104 * V_240 ,
int V_241 ,
const struct V_6 * V_7 ,
T_1 V_58 , T_1 V_260 )
{
struct V_261 * V_262 ;
struct V_8 * V_9 = NULL ;
struct V_263 * V_90 ;
V_90 = F_183 ( F_32 ( V_7 ) , V_245 ) ;
if ( V_90 == NULL )
return NULL ;
F_100 ( & V_90 -> V_264 ) ;
V_262 = F_184 ( & V_90 -> V_265 , V_240 , V_241 , NULL , 0 ) ;
if ( ! V_262 )
goto V_123;
for ( V_9 = V_262 -> V_266 ; V_9 ; V_9 = V_9 -> V_99 . V_267 ) {
if ( V_9 -> V_99 . V_7 -> V_144 != V_7 -> V_144 )
continue;
if ( ( V_9 -> V_10 & V_58 ) != V_58 )
continue;
if ( ( V_260 != 0 ) && ( ( V_9 -> V_10 & V_58 ) != 0 ) )
continue;
F_185 ( & V_9 -> V_99 ) ;
break;
}
V_123:
F_108 ( & V_90 -> V_264 ) ;
return V_9 ;
}
static void F_186 ( struct V_6 * V_7 )
{
struct V_242 V_243 = {
. V_244 = V_268 ,
. V_246 = V_247 ,
. V_248 = V_7 -> V_144 ,
. V_250 = 8 ,
. V_251 = V_252 ,
. V_253 . V_254 = F_32 ( V_7 ) ,
} ;
F_187 ( & V_243 . V_257 , F_150 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_181 ( & V_243 ) ;
}
static void F_188 ( struct V_6 * V_7 )
{
struct V_242 V_243 = {
. V_244 = V_269 ,
. V_246 = V_247 ,
. V_248 = V_7 -> V_144 ,
. V_250 = 96 ,
. V_251 = V_252 | V_259 ,
. V_253 . V_254 = F_32 ( V_7 ) ,
} ;
F_181 ( & V_243 ) ;
}
static void F_189 ( struct V_6 * V_7 )
{
struct V_104 V_102 ;
F_187 ( & V_102 , F_150 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_180 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
}
static struct V_4 * F_190 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
return F_78 ( - V_125 ) ;
if ( V_5 -> V_49 . V_119 )
return F_78 ( - V_120 ) ;
if ( ! ( V_7 -> V_58 & V_60 ) )
F_186 ( V_7 ) ;
F_189 ( V_7 ) ;
return V_5 ;
}
void F_191 ( struct V_6 * V_7 , T_3 * V_270 , int V_271 , bool V_272 )
{
struct V_273 * V_274 ;
V_163 V_140 ;
V_163 V_165 ;
int V_112 ;
struct V_4 * V_275 ;
struct V_86 * V_86 = F_32 ( V_7 ) ;
V_274 = (struct V_273 * ) V_270 ;
if ( V_271 < sizeof( struct V_273 ) ) {
F_36 ( ( L_21 ) ) ;
return;
}
V_112 = F_77 ( & V_274 -> V_143 ) ;
if ( V_112 & ( V_114 | V_276 ) )
return;
V_140 = F_192 ( V_274 -> V_277 ) ;
V_165 = F_192 ( V_274 -> V_278 ) ;
if ( V_165 > V_140 ) {
if ( F_149 () )
F_24 ( V_56 L_22 ) ;
return;
}
V_275 = F_193 ( V_7 ) ;
if ( V_275 == NULL ) {
if ( F_149 () )
F_24 ( V_41 L_23 , V_7 -> V_42 ) ;
return;
}
if ( V_274 -> V_136 ) {
struct V_8 * V_9 ;
unsigned long V_279 ;
if ( V_3 > V_280 )
V_279 = F_106 ( V_140 , V_3 ) ;
else
V_279 = F_106 ( V_140 , V_280 ) ;
if ( F_194 ( V_279 ) )
V_279 *= V_3 ;
V_9 = F_182 ( & V_274 -> V_143 ,
V_274 -> V_128 ,
V_7 ,
V_281 | V_282 ,
V_11 | V_12 ) ;
if ( V_9 ) {
if ( V_140 == 0 ) {
F_112 ( V_9 ) ;
V_9 = NULL ;
} else if ( F_194 ( V_279 ) ) {
F_113 ( V_9 , V_25 + V_279 ) ;
} else {
F_195 ( V_9 ) ;
}
} else if ( V_140 ) {
T_5 V_24 = 0 ;
int V_58 = V_281 | V_282 ;
if ( F_194 ( V_279 ) ) {
V_58 |= V_145 ;
V_24 = F_196 ( V_279 ) ;
}
F_180 ( & V_274 -> V_143 , V_274 -> V_128 ,
V_7 , V_24 , V_58 ) ;
}
if ( V_9 )
F_68 ( & V_9 -> V_99 ) ;
}
if ( V_274 -> V_283 && V_275 -> V_49 . V_283 ) {
struct V_13 * V_14 ;
struct V_104 V_102 ;
int V_284 = 0 , V_285 = 0 ;
if ( V_274 -> V_128 == 64 ) {
memcpy ( & V_102 , & V_274 -> V_143 , 8 ) ;
if ( F_151 ( V_102 . V_158 + 8 , V_7 ) &&
F_176 ( V_102 . V_158 + 8 , V_275 ) ) {
F_66 ( V_275 ) ;
return;
}
goto V_286;
}
if ( F_149 () )
F_24 ( V_41 L_24 ,
V_274 -> V_128 ) ;
F_66 ( V_275 ) ;
return;
V_286:
V_14 = F_144 ( V_86 , & V_102 , V_7 , 1 ) ;
if ( V_14 == NULL && V_140 ) {
int V_155 = V_275 -> V_49 . V_155 ;
T_1 V_156 = 0 ;
#ifdef F_197
if ( V_275 -> V_49 . V_287 &&
! V_86 -> V_28 . V_94 -> V_55 && V_272 )
V_156 = V_170 ;
#endif
if ( ! V_155 ||
F_118 ( V_275 ) < V_155 )
V_14 = F_76 ( V_275 , & V_102 , V_274 -> V_128 ,
V_112 & V_171 ,
V_156 ) ;
if ( ! V_14 || F_83 ( V_14 ) ) {
F_66 ( V_275 ) ;
return;
}
V_285 = V_284 = 1 ;
V_14 -> V_1 = V_25 ;
F_119 ( V_14 , V_281 | V_282 ) ;
}
if ( V_14 ) {
int V_58 ;
unsigned long V_157 ;
#ifdef F_41
struct V_13 * V_146 ;
#endif
T_1 V_288 ;
F_80 ( & V_14 -> V_48 ) ;
V_157 = V_25 ;
if ( V_14 -> V_140 > ( V_157 - V_14 -> V_78 ) / V_3 )
V_288 = V_14 -> V_140 - ( V_157 - V_14 -> V_78 ) / V_3 ;
else
V_288 = 0 ;
if ( ! V_285 && V_288 ) {
if ( V_140 > V_289 ||
V_140 > V_288 )
V_285 = 1 ;
else if ( V_288 <= V_289 ) {
if ( V_165 != V_14 -> V_165 ) {
V_140 = V_288 ;
V_285 = 1 ;
}
} else {
V_140 = V_289 ;
if ( V_140 < V_165 )
V_165 = V_140 ;
V_285 = 1 ;
}
}
if ( V_285 ) {
V_14 -> V_140 = V_140 ;
V_14 -> V_165 = V_165 ;
V_14 -> V_78 = V_157 ;
V_58 = V_14 -> V_58 ;
V_14 -> V_58 &= ~ V_187 ;
F_89 ( & V_14 -> V_48 ) ;
if ( ! ( V_58 & V_85 ) )
F_109 ( 0 , V_14 ) ;
} else
F_89 ( & V_14 -> V_48 ) ;
#ifdef F_41
F_132 ( & V_275 -> V_48 ) ;
F_52 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_151 , V_290 , V_291 ;
if ( V_14 != V_146 -> V_137 )
continue;
V_151 = ( V_157 - V_146 -> V_1 ) / V_3 ;
V_290 = V_275 -> V_49 . V_164 - V_151 ;
if ( V_290 < 0 )
V_290 = 0 ;
V_291 = V_275 -> V_49 . V_166 -
V_275 -> V_49 . V_167 -
V_151 ;
if ( V_291 < 0 )
V_291 = 0 ;
if ( V_140 > V_290 )
V_140 = V_290 ;
if ( V_165 > V_291 )
V_165 = V_291 ;
F_80 ( & V_146 -> V_48 ) ;
V_58 = V_146 -> V_58 ;
V_146 -> V_140 = V_140 ;
V_146 -> V_165 = V_165 ;
V_146 -> V_78 = V_157 ;
if ( V_165 > 0 )
V_146 -> V_58 &= ~ V_187 ;
F_89 ( & V_146 -> V_48 ) ;
if ( ! ( V_58 & V_85 ) )
F_109 ( 0 , V_146 ) ;
}
if ( ( V_284 || F_22 ( & V_275 -> V_69 ) ) && V_275 -> V_49 . V_75 > 0 ) {
F_137 ( & V_275 -> V_48 ) ;
F_115 ( V_14 , NULL ) ;
} else {
F_137 ( & V_275 -> V_48 ) ;
}
#endif
F_102 ( V_14 ) ;
F_198 ( 0 ) ;
}
}
F_199 ( V_292 , V_275 , V_274 ) ;
F_66 ( V_275 ) ;
}
int F_200 ( struct V_86 * V_86 , void T_6 * V_293 )
{
struct V_294 V_295 ;
struct V_6 * V_7 ;
int V_111 = - V_296 ;
F_201 () ;
V_111 = - V_297 ;
if ( F_202 ( & V_295 , V_293 , sizeof( struct V_294 ) ) )
goto V_298;
V_7 = F_203 ( V_86 , V_295 . V_299 ) ;
V_111 = - V_117 ;
if ( V_7 == NULL )
goto V_298;
#if F_40 ( V_62 ) || F_40 ( V_63 )
if ( V_7 -> type == V_64 ) {
const struct V_300 * V_301 = V_7 -> V_302 ;
struct V_303 V_304 ;
struct V_305 V_91 ;
V_111 = - V_116 ;
if ( ! ( F_77 ( & V_295 . V_306 ) & V_173 ) )
goto V_298;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_307 . V_202 = V_295 . V_306 . V_106 [ 3 ] ;
V_91 . V_307 . V_203 = 0 ;
V_91 . V_307 . V_308 = 4 ;
V_91 . V_307 . V_309 = 5 ;
V_91 . V_307 . V_310 = V_311 ;
V_91 . V_307 . V_312 = 64 ;
V_304 . V_313 . V_314 = ( V_105 void T_6 * ) & V_91 ;
if ( V_301 -> V_315 ) {
T_7 V_316 = F_204 () ;
F_205 ( V_317 ) ;
V_111 = V_301 -> V_315 ( V_7 , & V_304 , V_318 ) ;
F_205 ( V_316 ) ;
} else
V_111 = - V_319 ;
if ( V_111 == 0 ) {
V_111 = - V_125 ;
V_7 = F_206 ( V_86 , V_91 . V_42 ) ;
if ( ! V_7 )
goto V_298;
V_111 = F_207 ( V_7 ) ;
}
}
#endif
V_298:
F_62 () ;
return V_111 ;
}
static int F_208 ( struct V_86 * V_86 , int V_144 , const struct V_104 * V_240 ,
unsigned int V_241 , T_8 V_320 , V_163 V_165 ,
V_163 V_140 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_109 ;
T_1 V_58 ;
T_5 V_24 ;
unsigned long V_321 ;
F_29 () ;
if ( V_241 > 128 )
return - V_296 ;
if ( ! V_140 || V_165 > V_140 )
return - V_296 ;
V_7 = F_203 ( V_86 , V_144 ) ;
if ( ! V_7 )
return - V_117 ;
V_5 = F_190 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return F_84 ( V_5 ) ;
V_109 = F_209 ( V_240 ) ;
V_321 = F_106 ( V_140 , V_3 ) ;
if ( F_194 ( V_321 ) ) {
V_24 = F_196 ( V_321 * V_3 ) ;
V_140 = V_321 ;
V_58 = V_145 ;
} else {
V_24 = 0 ;
V_58 = 0 ;
V_320 |= V_138 ;
}
V_321 = F_106 ( V_165 , V_3 ) ;
if ( F_194 ( V_321 ) ) {
if ( V_321 == 0 )
V_320 |= V_187 ;
V_165 = V_321 ;
}
V_14 = F_76 ( V_5 , V_240 , V_241 , V_109 , V_320 ) ;
if ( ! F_83 ( V_14 ) ) {
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_140 = V_140 ;
V_14 -> V_165 = V_165 ;
V_14 -> V_78 = V_25 ;
F_98 ( & V_14 -> V_48 ) ;
F_180 ( & V_14 -> V_102 , V_14 -> V_128 , V_7 ,
V_24 , V_58 ) ;
F_119 ( V_14 , 0 ) ;
F_102 ( V_14 ) ;
F_198 ( 0 ) ;
return 0 ;
}
return F_84 ( V_14 ) ;
}
static int F_210 ( struct V_86 * V_86 , int V_144 , const struct V_104 * V_240 ,
unsigned int V_241 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_241 > 128 )
return - V_296 ;
V_7 = F_203 ( V_86 , V_144 ) ;
if ( ! V_7 )
return - V_117 ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL )
return - V_322 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_128 == V_241 &&
F_123 ( V_240 , & V_14 -> V_102 ) ) {
F_11 ( V_14 ) ;
F_137 ( & V_5 -> V_48 ) ;
F_96 ( V_14 ) ;
if ( F_22 ( & V_5 -> V_39 ) )
F_211 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_137 ( & V_5 -> V_48 ) ;
return - V_116 ;
}
int F_212 ( struct V_86 * V_86 , void T_6 * V_293 )
{
struct V_294 V_295 ;
int V_111 ;
if ( ! F_213 ( V_323 ) )
return - V_324 ;
if ( F_202 ( & V_295 , V_293 , sizeof( struct V_294 ) ) )
return - V_297 ;
F_201 () ;
V_111 = F_208 ( V_86 , V_295 . V_299 , & V_295 . V_306 ,
V_295 . V_325 , V_138 ,
V_326 , V_326 ) ;
F_62 () ;
return V_111 ;
}
int F_214 ( struct V_86 * V_86 , void T_6 * V_293 )
{
struct V_294 V_295 ;
int V_111 ;
if ( ! F_213 ( V_323 ) )
return - V_324 ;
if ( F_202 ( & V_295 , V_293 , sizeof( struct V_294 ) ) )
return - V_297 ;
F_201 () ;
V_111 = F_210 ( V_86 , V_295 . V_299 , & V_295 . V_306 ,
V_295 . V_325 ) ;
F_62 () ;
return V_111 ;
}
static void F_215 ( struct V_4 * V_5 , const struct V_104 * V_102 ,
int V_241 , int V_109 )
{
struct V_13 * V_14 ;
V_14 = F_76 ( V_5 , V_102 , V_241 , V_109 , V_138 ) ;
if ( ! F_83 ( V_14 ) ) {
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_58 &= ~ V_85 ;
F_98 ( & V_14 -> V_48 ) ;
F_109 ( V_327 , V_14 ) ;
F_102 ( V_14 ) ;
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
memcpy ( & V_102 . V_106 [ 3 ] , V_5 -> V_7 -> V_229 , 4 ) ;
if ( V_5 -> V_7 -> V_58 & V_258 ) {
V_102 . V_106 [ 0 ] = F_150 ( 0xfe800000 ) ;
V_109 = V_213 ;
} else {
V_109 = V_173 ;
}
if ( V_102 . V_106 [ 3 ] ) {
F_215 ( V_5 , & V_102 , 128 , V_109 ) ;
return;
}
F_217 (net, dev) {
struct V_328 * V_329 = F_218 ( V_7 ) ;
if ( V_329 && ( V_7 -> V_58 & V_83 ) ) {
struct V_330 * V_84 ;
int V_331 = V_109 ;
for ( V_84 = V_329 -> V_332 ; V_84 ; V_84 = V_84 -> V_333 ) {
int V_241 ;
V_102 . V_106 [ 3 ] = V_84 -> V_334 ;
if ( V_84 -> V_335 == V_336 )
continue;
if ( V_84 -> V_335 >= V_337 ) {
if ( V_5 -> V_7 -> V_58 & V_258 )
continue;
V_331 |= V_218 ;
}
if ( V_5 -> V_7 -> V_58 & V_258 )
V_241 = 64 ;
else
V_241 = 96 ;
F_215 ( V_5 , & V_102 , V_241 , V_331 ) ;
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
F_215 ( V_5 , & V_338 , 128 , V_218 ) ;
}
static void F_220 ( struct V_4 * V_5 , const struct V_104 * V_102 )
{
struct V_13 * V_14 ;
T_1 V_156 = V_138 ;
#ifdef F_197
if ( V_5 -> V_49 . V_287 &&
! F_32 ( V_5 -> V_7 ) -> V_28 . V_94 -> V_55 )
V_156 |= V_170 ;
#endif
V_14 = F_76 ( V_5 , V_102 , 64 , V_213 , V_156 ) ;
if ( ! F_83 ( V_14 ) ) {
F_180 ( & V_14 -> V_102 , V_14 -> V_128 , V_5 -> V_7 , 0 , 0 ) ;
F_119 ( V_14 , 0 ) ;
F_102 ( V_14 ) ;
}
}
static void F_221 ( struct V_6 * V_7 )
{
struct V_104 V_102 ;
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_233 ) &&
( V_7 -> type != V_234 ) &&
( V_7 -> type != V_235 ) &&
( V_7 -> type != V_236 ) &&
( V_7 -> type != V_237 ) ) {
return;
}
V_5 = F_190 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return;
memset ( & V_102 , 0 , sizeof( struct V_104 ) ) ;
V_102 . V_106 [ 0 ] = F_150 ( 0xFE800000 ) ;
if ( F_151 ( V_102 . V_158 + 8 , V_7 ) == 0 )
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
F_187 ( & V_102 , F_150 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_180 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_151 ( V_102 . V_158 + 8 , V_7 ) )
F_220 ( V_5 , & V_102 ) ;
return;
}
F_216 ( V_5 ) ;
if ( V_7 -> V_58 & V_258 ) {
F_186 ( V_7 ) ;
F_189 ( V_7 ) ;
} else
F_188 ( V_7 ) ;
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
F_187 ( & V_102 , F_150 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_180 ( & V_102 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_151 ( V_102 . V_158 + 8 , V_7 ) )
F_220 ( V_5 , & V_102 ) ;
}
static inline int
F_225 ( struct V_4 * V_5 , struct V_6 * V_339 )
{
struct V_104 V_340 ;
if ( ! F_138 ( V_339 , & V_340 , V_85 ) ) {
F_220 ( V_5 , & V_340 ) ;
return 0 ;
}
return - 1 ;
}
static void F_226 ( struct V_4 * V_5 )
{
struct V_6 * V_339 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_341 &&
( V_339 = F_203 ( V_86 , V_5 -> V_7 -> V_341 ) ) ) {
if ( ! F_225 ( V_5 , V_339 ) )
return;
}
F_217 (net, link_dev) {
if ( ! F_225 ( V_5 , V_339 ) )
return;
}
F_24 ( V_41 L_29 ) ;
}
static void F_227 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_190 ( V_7 ) ;
if ( F_83 ( V_5 ) ) {
F_24 ( V_41 L_30 ) ;
return;
}
F_226 ( V_5 ) ;
}
static int F_228 ( struct V_342 * V_343 , unsigned long V_344 ,
void * V_127 )
{
struct V_6 * V_7 = (struct V_6 * ) V_127 ;
struct V_4 * V_5 = F_48 ( V_7 ) ;
int V_345 = 0 ;
int V_111 ;
switch ( V_344 ) {
case V_346 :
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! V_5 )
return F_229 ( - V_38 ) ;
}
break;
case V_133 :
case V_347 :
if ( V_7 -> V_58 & V_348 )
break;
if ( V_344 == V_133 ) {
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
V_345 = 1 ;
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
V_345 = 1 ;
}
switch ( V_7 -> type ) {
#if F_40 ( V_62 ) || F_40 ( V_63 )
case V_64 :
F_222 ( V_7 ) ;
break;
#endif
#if F_40 ( V_349 ) || F_40 ( V_350 )
case V_238 :
F_223 ( V_7 ) ;
break;
#endif
case V_73 :
F_227 ( V_7 ) ;
break;
case V_351 :
F_219 ( V_7 ) ;
break;
default:
F_221 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_345 )
F_230 ( V_5 ) ;
if ( V_5 -> V_49 . V_51 != V_7 -> V_46 &&
V_7 -> V_46 >= V_47 ) {
F_231 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
}
V_5 -> V_78 = V_25 ;
F_232 ( V_352 , V_5 ) ;
if ( V_7 -> V_46 < V_47 )
F_211 ( V_7 , 1 ) ;
}
break;
case V_353 :
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
case V_142 :
case V_354 :
F_211 ( V_7 , V_344 != V_142 ) ;
break;
case V_355 :
if ( V_5 ) {
F_233 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_111 = F_38 ( V_5 ) ;
if ( V_111 )
return F_229 ( V_111 ) ;
}
break;
case V_356 :
case V_357 :
F_234 ( V_7 , V_344 ) ;
break;
}
return V_358 ;
}
static void F_234 ( struct V_6 * V_7 , unsigned long V_344 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_344 == V_357 )
F_235 ( V_5 ) ;
else if ( V_344 == V_356 )
F_236 ( V_5 ) ;
}
static int F_211 ( struct V_6 * V_7 , int V_359 )
{
struct V_86 * V_86 = F_32 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_13 * V_84 ;
int V_97 , V_177 ;
F_29 () ;
F_237 ( V_86 , V_7 ) ;
F_238 ( & V_54 , V_7 ) ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 == NULL )
return - V_117 ;
if ( V_359 ) {
V_5 -> V_43 = 1 ;
F_239 ( V_7 -> V_79 , NULL ) ;
F_233 ( V_5 ) ;
}
for ( V_177 = 0 ; V_177 < V_107 ; V_177 ++ ) {
struct V_360 * V_361 = & V_129 [ V_177 ] ;
struct V_216 * V_362 ;
F_97 ( & V_121 ) ;
V_363:
F_140 (ifa, n, h, addr_lst) {
if ( V_84 -> V_5 == V_5 ) {
F_99 ( & V_84 -> V_96 ) ;
F_7 ( V_84 ) ;
goto V_363;
}
}
F_98 ( & V_121 ) ;
}
F_100 ( & V_5 -> V_48 ) ;
if ( ! V_359 )
V_5 -> V_76 &= ~ ( V_364 | V_365 | V_77 ) ;
#ifdef F_41
if ( V_359 && F_8 ( & V_5 -> V_70 ) )
F_66 ( V_5 ) ;
while ( ! F_22 ( & V_5 -> V_69 ) ) {
V_84 = F_240 ( & V_5 -> V_69 ,
struct V_13 , V_131 ) ;
F_101 ( & V_84 -> V_131 ) ;
F_108 ( & V_5 -> V_48 ) ;
F_97 ( & V_84 -> V_48 ) ;
if ( V_84 -> V_137 ) {
F_102 ( V_84 -> V_137 ) ;
V_84 -> V_137 = NULL ;
}
F_98 ( & V_84 -> V_48 ) ;
F_102 ( V_84 ) ;
F_100 ( & V_5 -> V_48 ) ;
}
#endif
while ( ! F_22 ( & V_5 -> V_39 ) ) {
V_84 = F_240 ( & V_5 -> V_39 ,
struct V_13 , V_103 ) ;
F_7 ( V_84 ) ;
F_101 ( & V_84 -> V_103 ) ;
F_108 ( & V_5 -> V_48 ) ;
F_97 ( & V_84 -> V_126 ) ;
V_97 = V_84 -> V_97 ;
V_84 -> V_97 = V_98 ;
F_98 ( & V_84 -> V_126 ) ;
if ( V_97 != V_98 ) {
F_241 ( V_141 , V_84 ) ;
F_95 ( & V_132 , V_142 , V_84 ) ;
}
F_102 ( V_84 ) ;
F_100 ( & V_5 -> V_48 ) ;
}
F_108 ( & V_5 -> V_48 ) ;
if ( V_359 )
F_242 ( V_5 ) ;
else
F_243 ( V_5 ) ;
V_5 -> V_78 = V_25 ;
if ( V_359 ) {
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
F_244 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_76 & V_77 ) )
goto V_123;
if ( V_5 -> V_49 . V_55 )
goto V_123;
if ( V_5 -> V_76 & V_365 )
goto V_123;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_366 ++ < V_5 -> V_49 . V_68 ) {
F_10 ( V_14 , V_22 ,
( V_14 -> V_366 == V_5 -> V_49 . V_68 ) ?
V_5 -> V_49 . V_367 :
V_5 -> V_49 . V_368 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_245 ( V_5 -> V_7 , & V_14 -> V_102 , & V_82 ) ;
} else {
F_89 ( & V_14 -> V_48 ) ;
F_24 ( V_41 L_35 ,
V_5 -> V_7 -> V_42 ) ;
}
V_123:
F_246 ( & V_5 -> V_48 ) ;
F_102 ( V_14 ) ;
}
static void F_247 ( struct V_13 * V_14 )
{
unsigned long V_369 ;
struct V_4 * V_5 = V_14 -> V_5 ;
if ( V_14 -> V_58 & V_170 )
V_369 = 0 ;
else
V_369 = F_248 () % ( V_5 -> V_49 . V_367 ? : 1 ) ;
V_14 -> V_366 = V_5 -> V_49 . V_168 ;
F_10 ( V_14 , V_19 , V_369 ) ;
}
static void F_119 ( struct V_13 * V_14 , T_1 V_58 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_152 ( V_7 , & V_14 -> V_102 ) ;
F_249 ( V_14 -> V_102 . V_106 [ 3 ] ) ;
F_132 ( & V_5 -> V_48 ) ;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_97 == V_98 )
goto V_123;
if ( V_7 -> V_58 & ( V_59 | V_60 ) ||
V_5 -> V_49 . V_61 < 1 ||
! ( V_14 -> V_58 & V_85 ) ||
V_14 -> V_58 & V_370 ) {
V_14 -> V_58 &= ~ ( V_85 | V_170 | V_221 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_137 ( & V_5 -> V_48 ) ;
F_250 ( V_14 ) ;
return;
}
if ( ! ( V_5 -> V_76 & V_77 ) ) {
F_89 ( & V_14 -> V_48 ) ;
F_137 ( & V_5 -> V_48 ) ;
F_11 ( V_14 ) ;
F_146 ( V_14 , 0 ) ;
return;
}
if ( V_14 -> V_58 & V_170 )
F_251 ( V_14 -> V_9 ) ;
F_247 ( V_14 ) ;
V_123:
F_89 ( & V_14 -> V_48 ) ;
F_137 ( & V_5 -> V_48 ) ;
}
static void V_21 ( unsigned long V_127 )
{
struct V_13 * V_14 = (struct V_13 * ) V_127 ;
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_104 V_371 ;
if ( ! V_14 -> V_366 && F_147 ( V_14 ) )
goto V_123;
F_244 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_76 & V_77 ) ) {
F_246 ( & V_5 -> V_48 ) ;
goto V_123;
}
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_97 == V_98 ) {
F_89 ( & V_14 -> V_48 ) ;
F_246 ( & V_5 -> V_48 ) ;
goto V_123;
}
if ( V_14 -> V_366 == 0 ) {
V_14 -> V_58 &= ~ ( V_85 | V_170 | V_221 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_246 ( & V_5 -> V_48 ) ;
F_250 ( V_14 ) ;
goto V_123;
}
V_14 -> V_366 -- ;
F_10 ( V_14 , V_19 , V_14 -> V_5 -> V_53 -> V_169 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_246 ( & V_5 -> V_48 ) ;
F_153 ( & V_14 -> V_102 , & V_371 ) ;
F_252 ( V_14 -> V_5 -> V_7 , NULL , & V_14 -> V_102 , & V_371 , & V_372 ) ;
V_123:
F_102 ( V_14 ) ;
}
static void F_250 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = V_14 -> V_5 -> V_7 ;
F_109 ( V_327 , V_14 ) ;
if ( ( ( V_14 -> V_5 -> V_49 . V_373 == 1 && ! V_14 -> V_5 -> V_49 . V_55 ) ||
V_14 -> V_5 -> V_49 . V_373 == 2 ) &&
V_14 -> V_5 -> V_49 . V_68 > 0 &&
( V_7 -> V_58 & V_60 ) == 0 &&
( F_77 ( & V_14 -> V_102 ) & V_276 ) ) {
F_245 ( V_14 -> V_5 -> V_7 , & V_14 -> V_102 , & V_82 ) ;
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_366 = 1 ;
V_14 -> V_5 -> V_76 |= V_364 ;
F_10 ( V_14 , V_22 , V_14 -> V_5 -> V_49 . V_368 ) ;
F_98 ( & V_14 -> V_48 ) ;
}
}
static void F_230 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
F_132 ( & V_5 -> V_48 ) ;
F_52 (ifp, &idev->addr_list, if_list) {
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_58 & V_85 &&
V_14 -> V_97 == V_223 )
F_247 ( V_14 ) ;
F_89 ( & V_14 -> V_48 ) ;
}
F_137 ( & V_5 -> V_48 ) ;
}
static struct V_13 * F_253 ( struct V_374 * V_375 , T_9 V_376 )
{
struct V_13 * V_84 = NULL ;
struct V_377 * V_97 = V_375 -> V_378 ;
struct V_86 * V_86 = F_254 ( V_375 ) ;
int V_91 = 0 ;
if ( V_376 == 0 ) {
V_97 -> V_379 = 0 ;
V_97 -> V_380 = 0 ;
}
for (; V_97 -> V_379 < V_107 ; ++ V_97 -> V_379 ) {
struct V_216 * V_362 ;
F_145 (ifa, n, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( V_91 < V_97 -> V_380 ) {
V_91 ++ ;
continue;
}
V_97 -> V_380 ++ ;
if ( F_141 ( F_32 ( V_84 -> V_5 -> V_7 ) , V_86 ) )
return V_84 ;
}
V_97 -> V_380 = 0 ;
V_91 = 0 ;
}
return NULL ;
}
static struct V_13 * F_255 ( struct V_374 * V_375 ,
struct V_13 * V_84 )
{
struct V_377 * V_97 = V_375 -> V_378 ;
struct V_86 * V_86 = F_254 ( V_375 ) ;
struct V_216 * V_362 = & V_84 -> V_96 ;
F_256 (ifa, n, addr_lst) {
V_97 -> V_380 ++ ;
if ( F_141 ( F_32 ( V_84 -> V_5 -> V_7 ) , V_86 ) )
return V_84 ;
}
while ( ++ V_97 -> V_379 < V_107 ) {
V_97 -> V_380 = 0 ;
F_145 (ifa, n,
&inet6_addr_lst[state->bucket], addr_lst) {
V_97 -> V_380 ++ ;
if ( F_141 ( F_32 ( V_84 -> V_5 -> V_7 ) , V_86 ) )
return V_84 ;
}
}
return NULL ;
}
static void * F_257 ( struct V_374 * V_375 , T_9 * V_376 )
__acquires( T_10 )
{
F_79 () ;
return F_253 ( V_375 , * V_376 ) ;
}
static void * F_258 ( struct V_374 * V_375 , void * V_381 , T_9 * V_376 )
{
struct V_13 * V_84 ;
V_84 = F_255 ( V_375 , V_381 ) ;
++ * V_376 ;
return V_84 ;
}
static void F_259 ( struct V_374 * V_375 , void * V_381 )
__releases( T_10 )
{
F_93 () ;
}
static int F_260 ( struct V_374 * V_375 , void * V_381 )
{
struct V_13 * V_14 = (struct V_13 * ) V_381 ;
F_261 ( V_375 , L_36 ,
& V_14 -> V_102 ,
V_14 -> V_5 -> V_7 -> V_144 ,
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
int V_154 = 0 ;
struct V_13 * V_14 = NULL ;
struct V_216 * V_362 ;
unsigned int V_110 = F_74 ( V_102 ) ;
F_79 () ;
F_145 (ifp, n, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_141 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_86 ) )
continue;
if ( F_123 ( & V_14 -> V_102 , V_102 ) &&
( V_14 -> V_58 & V_192 ) ) {
V_154 = 1 ;
break;
}
}
F_93 () ;
return V_154 ;
}
static void F_198 ( unsigned long V_388 )
{
unsigned long V_157 , V_389 , V_390 , V_391 ;
struct V_13 * V_14 ;
struct V_216 * V_217 ;
int V_177 ;
F_79 () ;
F_80 ( & V_392 ) ;
V_157 = V_25 ;
V_389 = F_273 ( V_157 + V_393 ) ;
F_8 ( & V_394 ) ;
for ( V_177 = 0 ; V_177 < V_107 ; V_177 ++ ) {
V_363:
F_145 (ifp, node,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_151 ;
if ( V_14 -> V_58 & V_138 )
continue;
F_80 ( & V_14 -> V_48 ) ;
V_151 = ( V_157 - V_14 -> V_78 + V_395 ) / V_3 ;
if ( V_14 -> V_140 != V_326 &&
V_151 >= V_14 -> V_140 ) {
F_89 ( & V_14 -> V_48 ) ;
F_11 ( V_14 ) ;
F_96 ( V_14 ) ;
goto V_363;
} else if ( V_14 -> V_165 == V_326 ) {
F_89 ( & V_14 -> V_48 ) ;
continue;
} else if ( V_151 >= V_14 -> V_165 ) {
int V_396 = 0 ;
if ( ! ( V_14 -> V_58 & V_187 ) ) {
V_396 = 1 ;
V_14 -> V_58 |= V_187 ;
}
if ( F_107 ( V_14 -> V_78 + V_14 -> V_140 * V_3 , V_389 ) )
V_389 = V_14 -> V_78 + V_14 -> V_140 * V_3 ;
F_89 ( & V_14 -> V_48 ) ;
if ( V_396 ) {
F_11 ( V_14 ) ;
F_109 ( 0 , V_14 ) ;
F_102 ( V_14 ) ;
goto V_363;
}
#ifdef F_41
} else if ( ( V_14 -> V_58 & V_130 ) &&
! ( V_14 -> V_58 & V_85 ) ) {
unsigned long V_152 = V_14 -> V_5 -> V_49 . V_161 *
V_14 -> V_5 -> V_49 . V_168 *
V_14 -> V_5 -> V_53 -> V_169 / V_3 ;
if ( V_151 >= V_14 -> V_165 - V_152 ) {
struct V_13 * V_137 = V_14 -> V_137 ;
if ( F_107 ( V_14 -> V_78 + V_14 -> V_165 * V_3 , V_389 ) )
V_389 = V_14 -> V_78 + V_14 -> V_165 * V_3 ;
if ( ! V_14 -> V_160 && V_137 ) {
V_14 -> V_160 ++ ;
F_11 ( V_14 ) ;
F_11 ( V_137 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_80 ( & V_137 -> V_48 ) ;
V_137 -> V_160 = 0 ;
F_89 ( & V_137 -> V_48 ) ;
F_115 ( V_137 , V_14 ) ;
F_102 ( V_137 ) ;
F_102 ( V_14 ) ;
goto V_363;
}
} else if ( F_107 ( V_14 -> V_78 + V_14 -> V_165 * V_3 - V_152 * V_3 , V_389 ) )
V_389 = V_14 -> V_78 + V_14 -> V_165 * V_3 - V_152 * V_3 ;
F_89 ( & V_14 -> V_48 ) ;
#endif
} else {
if ( F_107 ( V_14 -> V_78 + V_14 -> V_165 * V_3 , V_389 ) )
V_389 = V_14 -> V_78 + V_14 -> V_165 * V_3 ;
F_89 ( & V_14 -> V_48 ) ;
}
}
}
V_390 = F_273 ( V_389 ) ;
V_391 = V_389 ;
if ( F_107 ( V_390 , V_389 + V_397 ) )
V_391 = V_390 ;
if ( F_107 ( V_391 , V_25 + V_398 ) )
V_391 = V_25 + V_398 ;
F_36 ( ( V_41 L_38 ,
V_157 , V_389 , V_390 , V_391 ) ) ;
V_394 . V_24 = V_391 ;
F_12 ( & V_394 ) ;
F_89 ( & V_392 ) ;
F_93 () ;
}
static struct V_104 * F_274 ( struct V_399 * V_102 , struct V_399 * V_400 )
{
struct V_104 * V_240 = NULL ;
if ( V_102 )
V_240 = F_275 ( V_102 ) ;
if ( V_400 ) {
if ( V_240 && F_276 ( V_400 , V_240 , sizeof( * V_240 ) ) )
V_240 = NULL ;
else
V_240 = F_275 ( V_400 ) ;
}
return V_240 ;
}
static int
F_277 ( struct V_401 * V_402 , struct V_403 * V_404 , void * V_293 )
{
struct V_86 * V_86 = F_278 ( V_402 -> V_405 ) ;
struct V_406 * V_407 ;
struct V_399 * V_408 [ V_409 + 1 ] ;
struct V_104 * V_240 ;
int V_111 ;
V_111 = F_279 ( V_404 , sizeof( * V_407 ) , V_408 , V_409 , V_410 ) ;
if ( V_111 < 0 )
return V_111 ;
V_407 = F_280 ( V_404 ) ;
V_240 = F_274 ( V_408 [ V_411 ] , V_408 [ V_412 ] ) ;
if ( V_240 == NULL )
return - V_296 ;
return F_210 ( V_86 , V_407 -> V_413 , V_240 , V_407 -> V_414 ) ;
}
static int F_281 ( struct V_13 * V_14 , T_3 V_320 ,
T_1 V_165 , T_1 V_140 )
{
T_1 V_58 ;
T_5 V_24 ;
unsigned long V_321 ;
if ( ! V_140 || ( V_165 > V_140 ) )
return - V_296 ;
V_321 = F_106 ( V_140 , V_3 ) ;
if ( F_194 ( V_321 ) ) {
V_24 = F_196 ( V_321 * V_3 ) ;
V_140 = V_321 ;
V_58 = V_145 ;
} else {
V_24 = 0 ;
V_58 = 0 ;
V_320 |= V_138 ;
}
V_321 = F_106 ( V_165 , V_3 ) ;
if ( F_194 ( V_321 ) ) {
if ( V_321 == 0 )
V_320 |= V_187 ;
V_165 = V_321 ;
}
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_58 = ( V_14 -> V_58 & ~ ( V_187 | V_138 | V_370 | V_192 ) ) | V_320 ;
V_14 -> V_78 = V_25 ;
V_14 -> V_140 = V_140 ;
V_14 -> V_165 = V_165 ;
F_98 ( & V_14 -> V_48 ) ;
if ( ! ( V_14 -> V_58 & V_85 ) )
F_109 ( 0 , V_14 ) ;
F_180 ( & V_14 -> V_102 , V_14 -> V_128 , V_14 -> V_5 -> V_7 ,
V_24 , V_58 ) ;
F_198 ( 0 ) ;
return 0 ;
}
static int
F_282 ( struct V_401 * V_402 , struct V_403 * V_404 , void * V_293 )
{
struct V_86 * V_86 = F_278 ( V_402 -> V_405 ) ;
struct V_406 * V_407 ;
struct V_399 * V_408 [ V_409 + 1 ] ;
struct V_104 * V_240 ;
struct V_13 * V_84 ;
struct V_6 * V_7 ;
T_1 V_140 = V_326 , V_415 = V_326 ;
T_3 V_320 ;
int V_111 ;
V_111 = F_279 ( V_404 , sizeof( * V_407 ) , V_408 , V_409 , V_410 ) ;
if ( V_111 < 0 )
return V_111 ;
V_407 = F_280 ( V_404 ) ;
V_240 = F_274 ( V_408 [ V_411 ] , V_408 [ V_412 ] ) ;
if ( V_240 == NULL )
return - V_296 ;
if ( V_408 [ V_416 ] ) {
struct V_417 * V_418 ;
V_418 = F_275 ( V_408 [ V_416 ] ) ;
V_140 = V_418 -> V_419 ;
V_415 = V_418 -> V_420 ;
} else {
V_415 = V_326 ;
V_140 = V_326 ;
}
V_7 = F_203 ( V_86 , V_407 -> V_413 ) ;
if ( V_7 == NULL )
return - V_117 ;
V_320 = V_407 -> V_320 & ( V_370 | V_192 ) ;
V_84 = F_144 ( V_86 , V_240 , V_7 , 1 ) ;
if ( V_84 == NULL ) {
return F_208 ( V_86 , V_407 -> V_413 , V_240 ,
V_407 -> V_414 , V_320 ,
V_415 , V_140 ) ;
}
if ( V_404 -> V_421 & V_422 ||
! ( V_404 -> V_421 & V_423 ) )
V_111 = - V_122 ;
else
V_111 = F_281 ( V_84 , V_320 , V_415 , V_140 ) ;
F_102 ( V_84 ) ;
return V_111 ;
}
static void F_283 ( struct V_403 * V_404 , T_3 V_424 , T_3 V_58 ,
T_3 V_109 , int V_144 )
{
struct V_406 * V_407 ;
V_407 = F_280 ( V_404 ) ;
V_407 -> V_425 = V_426 ;
V_407 -> V_414 = V_424 ;
V_407 -> V_320 = V_58 ;
V_407 -> V_335 = V_109 ;
V_407 -> V_413 = V_144 ;
}
static int F_284 ( struct V_401 * V_402 , unsigned long V_1 ,
unsigned long V_78 , T_1 V_427 , T_1 V_277 )
{
struct V_417 V_418 ;
V_418 . V_1 = F_1 ( V_1 ) ;
V_418 . V_78 = F_1 ( V_78 ) ;
V_418 . V_420 = V_427 ;
V_418 . V_419 = V_277 ;
return F_285 ( V_402 , V_416 , sizeof( V_418 ) , & V_418 ) ;
}
static inline int F_286 ( int V_335 )
{
if ( V_335 & V_218 )
return V_337 ;
else if ( V_335 & V_213 )
return V_336 ;
else if ( V_335 & V_428 )
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
static int F_290 ( struct V_401 * V_402 , struct V_13 * V_84 ,
T_1 V_431 , T_1 V_375 , int V_344 , unsigned int V_58 )
{
struct V_403 * V_404 ;
T_1 V_427 , V_277 ;
V_404 = F_291 ( V_402 , V_431 , V_375 , V_344 , sizeof( struct V_406 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
F_283 ( V_404 , V_84 -> V_128 , V_84 -> V_58 , F_286 ( V_84 -> V_109 ) ,
V_84 -> V_5 -> V_7 -> V_144 ) ;
if ( ! ( V_84 -> V_58 & V_138 ) ) {
V_427 = V_84 -> V_165 ;
V_277 = V_84 -> V_140 ;
if ( V_427 != V_326 ) {
long V_433 = ( V_25 - V_84 -> V_78 ) / V_3 ;
if ( V_427 > V_433 )
V_427 -= V_433 ;
else
V_427 = 0 ;
if ( V_277 != V_326 ) {
if ( V_277 > V_433 )
V_277 -= V_433 ;
else
V_277 = 0 ;
}
}
} else {
V_427 = V_326 ;
V_277 = V_326 ;
}
if ( F_285 ( V_402 , V_411 , 16 , & V_84 -> V_102 ) < 0 ||
F_284 ( V_402 , V_84 -> V_1 , V_84 -> V_78 , V_427 , V_277 ) < 0 ) {
F_292 ( V_402 , V_404 ) ;
return - V_432 ;
}
return F_293 ( V_402 , V_404 ) ;
}
static int F_294 ( struct V_401 * V_402 , struct V_434 * V_435 ,
T_1 V_431 , T_1 V_375 , int V_344 , T_14 V_58 )
{
struct V_403 * V_404 ;
T_3 V_109 = V_430 ;
int V_144 = V_435 -> V_5 -> V_7 -> V_144 ;
if ( F_209 ( & V_435 -> V_436 ) & V_428 )
V_109 = V_429 ;
V_404 = F_291 ( V_402 , V_431 , V_375 , V_344 , sizeof( struct V_406 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
F_283 ( V_404 , 128 , V_138 , V_109 , V_144 ) ;
if ( F_285 ( V_402 , V_437 , 16 , & V_435 -> V_436 ) < 0 ||
F_284 ( V_402 , V_435 -> V_438 , V_435 -> V_439 ,
V_326 , V_326 ) < 0 ) {
F_292 ( V_402 , V_404 ) ;
return - V_432 ;
}
return F_293 ( V_402 , V_404 ) ;
}
static int F_295 ( struct V_401 * V_402 , struct V_440 * V_441 ,
T_1 V_431 , T_1 V_375 , int V_344 , unsigned int V_58 )
{
struct V_403 * V_404 ;
T_3 V_109 = V_430 ;
int V_144 = V_441 -> V_442 -> V_7 -> V_144 ;
if ( F_209 ( & V_441 -> V_443 ) & V_428 )
V_109 = V_429 ;
V_404 = F_291 ( V_402 , V_431 , V_375 , V_344 , sizeof( struct V_406 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
F_283 ( V_404 , 128 , V_138 , V_109 , V_144 ) ;
if ( F_285 ( V_402 , V_444 , 16 , & V_441 -> V_443 ) < 0 ||
F_284 ( V_402 , V_441 -> V_445 , V_441 -> V_446 ,
V_326 , V_326 ) < 0 ) {
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
F_132 ( & V_5 -> V_48 ) ;
switch ( type ) {
case V_453 : {
struct V_13 * V_84 ;
F_52 (ifa, &idev->addr_list, if_list) {
if ( ++ V_452 < V_450 )
continue;
V_111 = F_290 ( V_402 , V_84 ,
F_297 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_327 ,
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
F_137 ( & V_5 -> V_48 ) ;
* V_451 = V_452 ;
return V_111 ;
}
static int F_298 ( struct V_401 * V_402 , struct V_447 * V_448 ,
enum V_449 type )
{
struct V_86 * V_86 = F_278 ( V_402 -> V_405 ) ;
int V_361 , V_462 ;
int V_463 , V_452 ;
int V_464 , V_450 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_360 * V_465 ;
struct V_216 * V_217 ;
V_462 = V_448 -> args [ 0 ] ;
V_464 = V_463 = V_448 -> args [ 1 ] ;
V_450 = V_452 = V_448 -> args [ 2 ] ;
F_56 () ;
for ( V_361 = V_462 ; V_361 < V_466 ; V_361 ++ , V_464 = 0 ) {
V_463 = 0 ;
V_465 = & V_86 -> V_467 [ V_361 ] ;
F_140 (dev, node, head, index_hlist) {
if ( V_463 < V_464 )
goto V_468;
if ( V_361 > V_462 || V_463 > V_464 )
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
V_448 -> args [ 0 ] = V_361 ;
V_448 -> args [ 1 ] = V_463 ;
V_448 -> args [ 2 ] = V_452 ;
return V_402 -> V_271 ;
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
void * V_293 )
{
struct V_86 * V_86 = F_278 ( V_470 -> V_405 ) ;
struct V_406 * V_407 ;
struct V_399 * V_408 [ V_409 + 1 ] ;
struct V_104 * V_102 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_13 * V_84 ;
struct V_401 * V_402 ;
int V_111 ;
V_111 = F_279 ( V_404 , sizeof( * V_407 ) , V_408 , V_409 , V_410 ) ;
if ( V_111 < 0 )
goto V_471;
V_102 = F_274 ( V_408 [ V_411 ] , V_408 [ V_412 ] ) ;
if ( V_102 == NULL ) {
V_111 = - V_296 ;
goto V_471;
}
V_407 = F_280 ( V_404 ) ;
if ( V_407 -> V_413 )
V_7 = F_203 ( V_86 , V_407 -> V_413 ) ;
V_84 = F_144 ( V_86 , V_102 , V_7 , 1 ) ;
if ( ! V_84 ) {
V_111 = - V_116 ;
goto V_471;
}
V_402 = F_303 ( F_287 () , V_33 ) ;
if ( ! V_402 ) {
V_111 = - V_125 ;
goto V_472;
}
V_111 = F_290 ( V_402 , V_84 , F_297 ( V_470 ) . V_431 ,
V_404 -> V_454 , V_327 , 0 ) ;
if ( V_111 < 0 ) {
F_21 ( V_111 == - V_432 ) ;
F_304 ( V_402 ) ;
goto V_472;
}
V_111 = F_305 ( V_402 , V_86 , F_297 ( V_470 ) . V_431 ) ;
V_472:
F_102 ( V_84 ) ;
V_471:
return V_111 ;
}
static void F_306 ( int V_344 , struct V_13 * V_84 )
{
struct V_401 * V_402 ;
struct V_86 * V_86 = F_32 ( V_84 -> V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_402 = F_303 ( F_287 () , V_124 ) ;
if ( V_402 == NULL )
goto V_471;
V_111 = F_290 ( V_402 , V_84 , 0 , 0 , V_344 , 0 ) ;
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
V_475 [ V_482 ] = V_49 -> V_373 ;
V_475 [ V_483 ] = V_49 -> V_484 ;
V_475 [ V_485 ] = V_49 -> V_283 ;
V_475 [ V_486 ] = V_49 -> V_168 ;
V_475 [ V_487 ] = V_49 -> V_68 ;
V_475 [ V_488 ] =
F_311 ( V_49 -> V_368 ) ;
V_475 [ V_489 ] =
F_311 ( V_49 -> V_367 ) ;
V_475 [ V_490 ] = V_49 -> V_491 ;
#ifdef F_41
V_475 [ V_492 ] = V_49 -> V_75 ;
V_475 [ V_493 ] = V_49 -> V_164 ;
V_475 [ V_494 ] = V_49 -> V_166 ;
V_475 [ V_495 ] = V_49 -> V_161 ;
V_475 [ V_496 ] = V_49 -> V_167 ;
#endif
V_475 [ V_497 ] = V_49 -> V_155 ;
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
V_475 [ V_512 ] = V_49 -> V_287 ;
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
int V_177 ;
int V_527 = V_476 - sizeof( T_16 ) * V_526 ;
F_310 ( V_527 < 0 ) ;
F_318 ( V_526 , & V_27 [ 0 ] ) ;
for ( V_177 = 1 ; V_177 < V_526 ; V_177 ++ )
F_318 ( F_319 ( & V_525 [ V_177 ] ) , & V_27 [ V_177 ] ) ;
memset ( & V_27 [ V_526 ] , 0 , V_527 ) ;
}
static inline void F_320 ( T_16 * V_27 , void V_26 * * V_525 ,
int V_526 , int V_476 , T_15 V_528 )
{
int V_177 ;
int V_527 = V_476 - sizeof( T_16 ) * V_526 ;
F_310 ( V_527 < 0 ) ;
F_318 ( V_526 , & V_27 [ 0 ] ) ;
for ( V_177 = 1 ; V_177 < V_526 ; V_177 ++ )
F_318 ( F_321 ( V_525 , V_177 , V_528 ) , & V_27 [ V_177 ] ) ;
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
V_418 . V_169 = F_311 ( V_5 -> V_53 -> V_169 ) ;
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
T_1 V_431 , T_1 V_375 , int V_344 , unsigned int V_58 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_522 * V_544 ;
struct V_403 * V_404 ;
void * V_545 ;
V_404 = F_291 ( V_402 , V_431 , V_375 , V_344 , sizeof( * V_544 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
V_544 = F_280 ( V_404 ) ;
V_544 -> V_546 = V_426 ;
V_544 -> V_547 = 0 ;
V_544 -> V_548 = V_7 -> type ;
V_544 -> V_549 = V_7 -> V_144 ;
V_544 -> V_550 = F_332 ( V_7 ) ;
V_544 -> V_551 = 0 ;
F_333 ( V_402 , V_552 , V_7 -> V_42 ) ;
if ( V_7 -> V_227 )
F_326 ( V_402 , V_553 , V_7 -> V_227 , V_7 -> V_229 ) ;
F_325 ( V_402 , V_554 , V_7 -> V_46 ) ;
if ( V_7 -> V_144 != V_7 -> V_341 )
F_325 ( V_402 , V_555 , V_7 -> V_341 ) ;
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
int V_361 , V_462 ;
int V_463 = 0 , V_464 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_360 * V_465 ;
struct V_216 * V_217 ;
V_462 = V_448 -> args [ 0 ] ;
V_464 = V_448 -> args [ 1 ] ;
F_56 () ;
for ( V_361 = V_462 ; V_361 < V_466 ; V_361 ++ , V_464 = 0 ) {
V_463 = 0 ;
V_465 = & V_86 -> V_467 [ V_361 ] ;
F_140 (dev, node, head, index_hlist) {
if ( V_463 < V_464 )
goto V_468;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_468;
if ( F_331 ( V_402 , V_5 ,
F_297 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_352 , V_455 ) <= 0 )
goto V_123;
V_468:
V_463 ++ ;
}
}
V_123:
F_58 () ;
V_448 -> args [ 1 ] = V_463 ;
V_448 -> args [ 0 ] = V_361 ;
return V_402 -> V_271 ;
}
void F_232 ( int V_344 , struct V_4 * V_5 )
{
struct V_401 * V_402 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_402 = F_303 ( F_316 () , V_124 ) ;
if ( V_402 == NULL )
goto V_471;
V_111 = F_331 ( V_402 , V_5 , 0 , 0 , V_344 , 0 ) ;
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
struct V_273 * V_274 , T_1 V_431 , T_1 V_375 ,
int V_344 , unsigned int V_58 )
{
struct V_558 * V_560 ;
struct V_403 * V_404 ;
struct V_559 V_418 ;
V_404 = F_291 ( V_402 , V_431 , V_375 , V_344 , sizeof( * V_560 ) , V_58 ) ;
if ( V_404 == NULL )
return - V_432 ;
V_560 = F_280 ( V_404 ) ;
V_560 -> V_561 = V_426 ;
V_560 -> V_562 = 0 ;
V_560 -> V_563 = 0 ;
V_560 -> V_564 = V_5 -> V_7 -> V_144 ;
V_560 -> V_128 = V_274 -> V_128 ;
V_560 -> V_565 = V_274 -> type ;
V_560 -> V_566 = 0 ;
V_560 -> V_567 = 0 ;
if ( V_274 -> V_136 )
V_560 -> V_567 |= V_568 ;
if ( V_274 -> V_283 )
V_560 -> V_567 |= V_569 ;
F_326 ( V_402 , V_570 , sizeof( V_274 -> V_143 ) , & V_274 -> V_143 ) ;
V_418 . V_571 = F_192 ( V_274 -> V_278 ) ;
V_418 . V_572 = F_192 ( V_274 -> V_277 ) ;
F_326 ( V_402 , V_573 , sizeof( V_418 ) , & V_418 ) ;
return F_293 ( V_402 , V_404 ) ;
V_542:
F_292 ( V_402 , V_404 ) ;
return - V_432 ;
}
static void F_199 ( int V_344 , struct V_4 * V_5 ,
struct V_273 * V_274 )
{
struct V_401 * V_402 ;
struct V_86 * V_86 = F_32 ( V_5 -> V_7 ) ;
int V_111 = - V_125 ;
V_402 = F_303 ( F_337 () , V_124 ) ;
if ( V_402 == NULL )
goto V_471;
V_111 = F_338 ( V_402 , V_5 , V_274 , 0 , 0 , V_344 , 0 ) ;
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
static void F_241 ( int V_344 , struct V_13 * V_14 )
{
F_306 ( V_344 ? : V_327 , V_14 ) ;
switch ( V_344 ) {
case V_327 :
if ( ! ( V_14 -> V_9 -> V_575 ) )
F_251 ( V_14 -> V_9 ) ;
if ( V_14 -> V_5 -> V_49 . V_55 )
F_53 ( V_14 ) ;
break;
case V_141 :
if ( V_14 -> V_5 -> V_49 . V_55 )
F_54 ( V_14 ) ;
F_154 ( V_14 -> V_5 , & V_14 -> V_102 ) ;
F_185 ( & V_14 -> V_9 -> V_99 ) ;
if ( F_112 ( V_14 -> V_9 ) )
F_339 ( & V_14 -> V_9 -> V_99 ) ;
break;
}
}
static void F_109 ( int V_344 , struct V_13 * V_14 )
{
F_79 () ;
if ( F_94 ( V_14 -> V_5 -> V_43 == 0 ) )
F_241 ( V_344 , V_14 ) ;
F_93 () ;
}
static
int F_340 ( V_89 * V_576 , int V_577 ,
void T_6 * V_578 , T_15 * V_579 , T_9 * V_580 )
{
int * V_581 = V_576 -> V_127 ;
int V_582 = * V_581 ;
T_9 V_376 = * V_580 ;
V_89 V_583 ;
int V_154 ;
V_583 = * V_576 ;
V_583 . V_127 = & V_582 ;
V_154 = F_341 ( & V_583 , V_577 , V_578 , V_579 , V_580 ) ;
if ( V_577 )
V_154 = F_59 ( V_576 , V_581 , V_582 ) ;
if ( V_154 )
* V_580 = V_376 ;
return V_154 ;
}
static void F_342 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_49 . V_119 )
F_228 ( NULL , V_142 , V_5 -> V_7 ) ;
else
F_228 ( NULL , V_133 , V_5 -> V_7 ) ;
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
static int F_344 ( struct V_89 * V_90 , int * V_91 , int V_87 )
{
struct V_86 * V_86 ;
int V_92 ;
if ( ! F_60 () )
return F_61 () ;
V_86 = (struct V_86 * ) V_90 -> V_93 ;
V_92 = * V_91 ;
* V_91 = V_87 ;
if ( V_91 == & V_86 -> V_28 . V_50 -> V_119 ) {
F_62 () ;
return 0 ;
}
if ( V_91 == & V_86 -> V_28 . V_94 -> V_119 ) {
V_86 -> V_28 . V_50 -> V_119 = V_87 ;
F_343 ( V_86 , V_87 ) ;
} else if ( ( ! V_87 ) ^ ( ! V_92 ) )
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
T_9 V_376 = * V_580 ;
V_89 V_583 ;
int V_154 ;
V_583 = * V_576 ;
V_583 . V_127 = & V_582 ;
V_154 = F_341 ( & V_583 , V_577 , V_578 , V_579 , V_580 ) ;
if ( V_577 )
V_154 = F_344 ( V_576 , V_581 , V_582 ) ;
if ( V_154 )
* V_580 = V_376 ;
return V_154 ;
}
static int F_346 ( struct V_86 * V_86 , char * V_584 ,
struct V_4 * V_5 , struct V_474 * V_91 )
{
int V_177 ;
struct V_585 * V_586 ;
#define F_347 3
struct V_587 V_588 [] = {
{ . V_589 = L_39 , } ,
{ . V_589 = L_40 , } ,
{ . V_589 = L_41 , } ,
{ } ,
{ } ,
} ;
V_586 = F_348 ( & V_590 , sizeof( * V_586 ) , V_33 ) ;
if ( V_586 == NULL )
goto V_123;
for ( V_177 = 0 ; V_586 -> V_591 [ V_177 ] . V_127 ; V_177 ++ ) {
V_586 -> V_591 [ V_177 ] . V_127 += ( char * ) V_91 - ( char * ) & V_474 ;
V_586 -> V_591 [ V_177 ] . V_95 = V_5 ;
V_586 -> V_591 [ V_177 ] . V_93 = V_86 ;
}
V_586 -> V_584 = F_349 ( V_584 , V_33 ) ;
if ( ! V_586 -> V_584 )
goto free;
V_588 [ F_347 ] . V_589 = V_586 -> V_584 ;
V_586 -> V_592 = F_350 ( V_86 , V_588 ,
V_586 -> V_591 ) ;
if ( V_586 -> V_592 == NULL )
goto V_593;
V_91 -> V_52 = V_586 ;
return 0 ;
V_593:
F_17 ( V_586 -> V_584 ) ;
free:
F_17 ( V_586 ) ;
V_123:
return - V_125 ;
}
static void F_351 ( struct V_474 * V_91 )
{
struct V_585 * V_586 ;
if ( V_91 -> V_52 == NULL )
return;
V_586 = V_91 -> V_52 ;
V_91 -> V_52 = NULL ;
F_352 ( V_586 -> V_592 ) ;
F_17 ( V_586 -> V_584 ) ;
F_17 ( V_586 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_353 ( V_5 -> V_7 , V_5 -> V_53 , L_40 ,
& V_594 ) ;
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
struct V_474 * V_595 , * V_596 ;
V_111 = - V_38 ;
V_595 = & V_474 ;
V_596 = & V_597 ;
if ( ! F_141 ( V_86 , & V_598 ) ) {
V_595 = F_348 ( V_595 , sizeof( V_474 ) , V_33 ) ;
if ( V_595 == NULL )
goto V_599;
V_596 = F_348 ( V_596 , sizeof( V_597 ) , V_33 ) ;
if ( V_596 == NULL )
goto V_600;
} else {
V_596 -> V_283 = V_601 . V_283 ;
V_596 -> V_119 = V_601 . V_119 ;
}
V_86 -> V_28 . V_94 = V_595 ;
V_86 -> V_28 . V_50 = V_596 ;
#ifdef F_356
V_111 = F_346 ( V_86 , L_42 , NULL , V_595 ) ;
if ( V_111 < 0 )
goto V_602;
V_111 = F_346 ( V_86 , L_43 , NULL , V_596 ) ;
if ( V_111 < 0 )
goto V_603;
#endif
return 0 ;
#ifdef F_356
V_603:
F_351 ( V_595 ) ;
V_602:
F_17 ( V_596 ) ;
#endif
V_600:
F_17 ( V_595 ) ;
V_599:
return V_111 ;
}
static void T_12 F_357 ( struct V_86 * V_86 )
{
#ifdef F_356
F_351 ( V_86 -> V_28 . V_50 ) ;
F_351 ( V_86 -> V_28 . V_94 ) ;
#endif
if ( ! F_141 ( V_86 , & V_598 ) ) {
F_17 ( V_86 -> V_28 . V_50 ) ;
F_17 ( V_86 -> V_28 . V_94 ) ;
}
}
int F_358 ( struct V_342 * V_604 )
{
return F_359 ( & V_132 , V_604 ) ;
}
int F_360 ( struct V_342 * V_604 )
{
return F_361 ( & V_132 , V_604 ) ;
}
int T_13 F_362 ( void )
{
int V_177 , V_111 ;
V_111 = F_363 () ;
if ( V_111 < 0 ) {
F_24 ( V_605 L_44
L_45 , V_111 ) ;
goto V_123;
}
V_111 = F_269 ( & V_606 ) ;
if ( V_111 < 0 )
goto V_607;
F_201 () ;
if ( ! F_28 ( V_598 . V_608 ) )
V_111 = - V_38 ;
F_62 () ;
if ( V_111 )
goto V_609;
for ( V_177 = 0 ; V_177 < V_107 ; V_177 ++ )
F_364 ( & V_129 [ V_177 ] ) ;
F_365 ( & V_610 ) ;
F_198 ( 0 ) ;
V_111 = F_366 ( & V_611 ) ;
if ( V_111 < 0 )
goto V_612;
V_111 = F_367 ( V_613 , V_614 , NULL , F_336 ,
NULL ) ;
if ( V_111 < 0 )
goto V_471;
F_367 ( V_613 , V_327 , F_282 , NULL , NULL ) ;
F_367 ( V_613 , V_141 , F_277 , NULL , NULL ) ;
F_367 ( V_613 , V_615 , F_302 ,
F_299 , NULL ) ;
F_367 ( V_613 , V_457 , NULL ,
F_300 , NULL ) ;
F_367 ( V_613 , V_461 , NULL ,
F_301 , NULL ) ;
F_368 () ;
return 0 ;
V_471:
F_369 ( & V_611 ) ;
V_612:
F_370 ( & V_610 ) ;
V_609:
F_271 ( & V_606 ) ;
V_607:
F_371 () ;
V_123:
return V_111 ;
}
void F_372 ( void )
{
struct V_6 * V_7 ;
int V_177 ;
F_370 ( & V_610 ) ;
F_271 ( & V_606 ) ;
F_371 () ;
F_201 () ;
F_373 ( & V_611 ) ;
F_217 (&init_net, dev) {
if ( F_48 ( V_7 ) == NULL )
continue;
F_211 ( V_7 , 1 ) ;
}
F_211 ( V_598 . V_608 , 2 ) ;
F_97 ( & V_121 ) ;
for ( V_177 = 0 ; V_177 < V_107 ; V_177 ++ )
F_21 ( ! F_374 ( & V_129 [ V_177 ] ) ) ;
F_98 ( & V_121 ) ;
F_8 ( & V_394 ) ;
F_62 () ;
}
