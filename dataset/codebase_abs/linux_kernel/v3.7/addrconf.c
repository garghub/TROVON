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
F_24 ( L_1 , V_41 , V_7 ? V_7 -> V_42 : L_2 ) ;
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
V_41 , V_7 -> V_42 ) ) ;
F_37 ( & V_54 , V_45 -> V_53 ) ;
F_25 ( V_7 ) ;
F_17 ( V_45 ) ;
return NULL ;
}
if ( F_38 ( V_45 ) < 0 ) {
F_36 ( ( V_56
L_5 ,
V_41 , V_7 -> V_42 ) ) ;
F_37 ( & V_54 , V_45 -> V_53 ) ;
V_45 -> V_43 = 1 ;
F_20 ( V_45 ) ;
return NULL ;
}
F_39 ( V_45 ) ;
if ( V_7 -> V_57 & ( V_58 | V_59 ) )
V_45 -> V_49 . V_60 = - 1 ;
#if F_40 ( V_61 ) || F_40 ( V_62 )
if ( V_7 -> type == V_63 && ( V_7 -> V_64 & V_65 ) ) {
F_41 ( L_6 , V_7 -> V_42 ) ;
V_45 -> V_49 . V_66 = 0 ;
}
#endif
#ifdef F_42
F_31 ( & V_45 -> V_67 ) ;
F_43 ( & V_45 -> V_68 , V_69 , ( unsigned long ) V_45 ) ;
if ( ( V_7 -> V_57 & V_59 ) ||
V_7 -> type == V_70 ||
V_7 -> type == V_71 ||
V_7 -> type == V_63 ||
V_7 -> type == V_72 ) {
V_45 -> V_49 . V_73 = - 1 ;
} else {
F_39 ( V_45 ) ;
V_69 ( ( unsigned long ) V_45 ) ;
}
#endif
if ( F_44 ( V_7 ) && F_4 ( V_7 ) )
V_45 -> V_74 |= V_75 ;
F_45 ( V_45 ) ;
V_45 -> V_76 = V_25 ;
F_2 ( V_45 ) ;
F_46 ( V_7 -> V_77 , V_45 ) ;
F_47 ( V_7 , & V_78 ) ;
if ( V_45 -> V_49 . V_55 && ( V_7 -> V_57 & V_79 ) )
F_47 ( V_7 , & V_80 ) ;
return V_45 ;
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
if ( V_7 -> V_57 & V_81 )
F_50 ( V_5 ) ;
return V_5 ;
}
static void F_51 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_13 * V_82 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_49 . V_55 )
F_34 ( V_7 ) ;
if ( V_7 && ( V_7 -> V_57 & V_79 ) ) {
if ( V_5 -> V_49 . V_55 )
F_47 ( V_7 , & V_80 ) ;
else
F_52 ( V_7 , & V_80 ) ;
}
F_53 (ifa, &idev->addr_list, if_list) {
if ( V_82 -> V_57 & V_83 )
continue;
if ( V_5 -> V_49 . V_55 )
F_54 ( V_82 ) ;
else
F_55 ( V_82 ) ;
}
}
static void F_56 ( struct V_84 * V_84 , T_2 V_85 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_57 (net, dev) {
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
int V_86 = ( ! V_5 -> V_49 . V_55 ) ^ ( ! V_85 ) ;
V_5 -> V_49 . V_55 = V_85 ;
if ( V_86 )
F_51 ( V_5 ) ;
}
}
}
static int F_58 ( struct V_87 * V_88 , int * V_89 , int V_85 )
{
struct V_84 * V_84 ;
int V_90 ;
if ( ! F_59 () )
return F_60 () ;
V_84 = (struct V_84 * ) V_88 -> V_91 ;
V_90 = * V_89 ;
* V_89 = V_85 ;
if ( V_89 == & V_84 -> V_28 . V_50 -> V_55 ) {
F_61 () ;
return 0 ;
}
if ( V_89 == & V_84 -> V_28 . V_92 -> V_55 ) {
V_84 -> V_28 . V_50 -> V_55 = V_85 ;
F_56 ( V_84 , V_85 ) ;
} else if ( ( ! V_85 ) ^ ( ! V_90 ) )
F_51 ( (struct V_4 * ) V_88 -> V_93 ) ;
F_61 () ;
if ( V_85 )
F_62 ( V_84 ) ;
return 1 ;
}
void F_63 ( struct V_13 * V_14 )
{
F_21 ( ! F_64 ( & V_14 -> V_94 ) ) ;
#ifdef F_23
F_24 ( L_7 , V_41 ) ;
#endif
F_65 ( V_14 -> V_5 ) ;
if ( F_8 ( & V_14 -> V_15 ) )
F_66 ( L_8 , V_14 ) ;
if ( V_14 -> V_95 != V_96 ) {
F_26 ( L_9 , V_14 ) ;
return;
}
F_67 ( & V_14 -> V_9 -> V_97 ) ;
F_27 ( V_14 , V_44 ) ;
}
static void
F_68 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_98 * V_89 ;
int V_99 = F_69 ( & V_14 -> V_100 ) ;
F_70 (p, &idev->addr_list) {
struct V_13 * V_82
= F_71 ( V_89 , struct V_13 , V_101 ) ;
if ( V_99 >= F_69 ( & V_82 -> V_100 ) )
break;
}
F_72 ( & V_14 -> V_101 , V_89 ) ;
}
static T_1 F_73 ( const struct V_102 * V_100 )
{
return F_74 ( F_75 ( V_100 ) , V_103 ) ;
}
static struct V_13 *
F_76 ( struct V_4 * V_5 , const struct V_102 * V_100 , int V_104 ,
int V_105 , T_1 V_57 )
{
struct V_13 * V_82 = NULL ;
struct V_8 * V_9 ;
unsigned int V_106 ;
int V_107 = 0 ;
int V_108 = F_77 ( V_100 ) ;
if ( V_108 == V_109 ||
V_108 & V_110 ||
( ! ( V_5 -> V_7 -> V_57 & V_59 ) &&
V_108 & V_111 ) )
return F_78 ( - V_112 ) ;
F_79 () ;
if ( V_5 -> V_43 ) {
V_107 = - V_113 ;
goto V_114;
}
if ( V_5 -> V_49 . V_115 ) {
V_107 = - V_116 ;
goto V_114;
}
F_80 ( & V_117 ) ;
if ( F_81 ( F_32 ( V_5 -> V_7 ) , V_100 , V_5 -> V_7 ) ) {
F_36 ( ( L_10 ) ) ;
V_107 = - V_118 ;
goto V_119;
}
V_82 = F_16 ( sizeof( struct V_13 ) , V_120 ) ;
if ( V_82 == NULL ) {
F_36 ( ( L_11 ) ) ;
V_107 = - V_121 ;
goto V_119;
}
V_9 = F_82 ( V_5 , V_100 , false ) ;
if ( F_83 ( V_9 ) ) {
V_107 = F_84 ( V_9 ) ;
goto V_119;
}
V_82 -> V_100 = * V_100 ;
F_85 ( & V_82 -> V_48 ) ;
F_85 ( & V_82 -> V_122 ) ;
F_86 ( & V_82 -> V_15 ) ;
F_87 ( & V_82 -> V_94 ) ;
V_82 -> V_15 . V_123 = ( unsigned long ) V_82 ;
V_82 -> V_105 = V_105 ;
V_82 -> V_124 = V_104 ;
V_82 -> V_57 = V_57 | V_83 ;
V_82 -> V_1 = V_82 -> V_76 = V_25 ;
V_82 -> V_9 = V_9 ;
V_82 -> V_5 = V_5 ;
F_39 ( V_5 ) ;
F_11 ( V_82 ) ;
V_106 = F_73 ( V_100 ) ;
F_88 ( & V_82 -> V_94 , & V_125 [ V_106 ] ) ;
F_89 ( & V_117 ) ;
F_90 ( & V_5 -> V_48 ) ;
F_68 ( V_5 , V_82 ) ;
#ifdef F_42
if ( V_82 -> V_57 & V_126 ) {
F_91 ( & V_82 -> V_127 , & V_5 -> V_67 ) ;
F_11 ( V_82 ) ;
}
#endif
F_11 ( V_82 ) ;
F_92 ( & V_5 -> V_48 ) ;
V_114:
F_93 () ;
if ( F_94 ( V_107 == 0 ) )
F_95 ( & V_128 , V_129 , V_82 ) ;
else {
F_17 ( V_82 ) ;
V_82 = F_78 ( V_107 ) ;
}
return V_82 ;
V_119:
F_89 ( & V_117 ) ;
goto V_114;
}
static void F_96 ( struct V_13 * V_14 )
{
struct V_13 * V_82 , * V_130 ;
struct V_4 * V_5 = V_14 -> V_5 ;
int V_95 ;
int V_131 = 0 , V_132 = 0 ;
unsigned long V_24 = V_25 ;
F_97 ( & V_14 -> V_122 ) ;
V_95 = V_14 -> V_95 ;
V_14 -> V_95 = V_96 ;
F_98 ( & V_14 -> V_122 ) ;
if ( V_95 == V_96 )
goto V_119;
F_97 ( & V_117 ) ;
F_99 ( & V_14 -> V_94 ) ;
F_98 ( & V_117 ) ;
F_100 ( & V_5 -> V_48 ) ;
#ifdef F_42
if ( V_14 -> V_57 & V_126 ) {
F_101 ( & V_14 -> V_127 ) ;
if ( V_14 -> V_133 ) {
F_102 ( V_14 -> V_133 ) ;
V_14 -> V_133 = NULL ;
}
F_9 ( V_14 ) ;
}
#endif
F_103 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_82 == V_14 ) {
F_104 ( & V_14 -> V_101 ) ;
F_9 ( V_14 ) ;
if ( ! ( V_14 -> V_57 & V_134 ) || V_132 > 0 )
break;
V_131 = 1 ;
continue;
} else if ( V_14 -> V_57 & V_134 ) {
if ( F_105 ( & V_82 -> V_100 , & V_14 -> V_100 ,
V_14 -> V_124 ) ) {
if ( V_82 -> V_57 & V_134 ) {
V_132 = 1 ;
if ( V_131 )
break;
} else {
unsigned long V_135 ;
if ( ! V_132 )
V_132 = - 1 ;
F_80 ( & V_82 -> V_48 ) ;
V_135 = F_106 ( V_82 -> V_136 , V_3 ) ;
if ( F_107 ( V_24 ,
V_82 -> V_76 + V_135 * V_3 ) )
V_24 = V_82 -> V_76 + V_135 * V_3 ;
F_89 ( & V_82 -> V_48 ) ;
}
}
}
}
F_108 ( & V_5 -> V_48 ) ;
F_7 ( V_14 ) ;
F_109 ( V_137 , V_14 ) ;
F_95 ( & V_128 , V_138 , V_14 ) ;
if ( ( V_14 -> V_57 & V_134 ) && V_132 < 1 ) {
struct V_102 V_139 ;
struct V_8 * V_9 ;
struct V_84 * V_84 = F_32 ( V_14 -> V_5 -> V_7 ) ;
struct V_140 V_141 = {} ;
F_110 ( & V_139 , & V_14 -> V_100 , V_14 -> V_124 ) ;
V_141 . V_142 = V_14 -> V_5 -> V_7 -> V_143 ;
V_141 . V_144 = V_139 ;
V_9 = (struct V_8 * ) F_111 ( V_84 , & V_141 ,
V_145 ) ;
if ( V_9 != V_84 -> V_28 . V_146 &&
F_6 ( V_9 ) ) {
if ( V_132 == 0 ) {
F_112 ( V_9 ) ;
V_9 = NULL ;
} else if ( ! ( V_9 -> V_10 & V_147 ) ) {
F_113 ( V_9 , V_24 ) ;
}
}
F_67 ( & V_9 -> V_97 ) ;
}
F_114 ( V_14 ) ;
V_119:
F_102 ( V_14 ) ;
}
static int F_115 ( struct V_13 * V_14 , struct V_13 * V_148 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_102 V_100 , * V_149 ;
unsigned long V_150 , V_151 , V_152 , V_153 ;
unsigned long V_154 ;
int V_155 ;
int V_156 = 0 ;
int V_157 ;
T_1 V_158 ;
unsigned long V_159 = V_25 ;
F_90 ( & V_5 -> V_48 ) ;
if ( V_148 ) {
F_97 ( & V_148 -> V_48 ) ;
memcpy ( & V_100 . V_160 [ 8 ] , & V_148 -> V_100 . V_160 [ 8 ] , 8 ) ;
F_98 ( & V_148 -> V_48 ) ;
V_149 = & V_100 ;
} else {
V_149 = NULL ;
}
V_161:
F_39 ( V_5 ) ;
if ( V_5 -> V_49 . V_73 <= 0 ) {
F_92 ( & V_5 -> V_48 ) ;
F_41 ( L_12 , V_41 ) ;
F_65 ( V_5 ) ;
V_156 = - 1 ;
goto V_119;
}
F_97 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_162 ++ >= V_5 -> V_49 . V_163 ) {
V_5 -> V_49 . V_73 = - 1 ;
F_98 ( & V_14 -> V_48 ) ;
F_92 ( & V_5 -> V_48 ) ;
F_26 ( L_13 ,
V_41 ) ;
F_65 ( V_5 ) ;
V_156 = - 1 ;
goto V_119;
}
F_11 ( V_14 ) ;
memcpy ( V_100 . V_160 , V_14 -> V_100 . V_160 , 8 ) ;
F_116 ( V_5 , V_149 ) ;
memcpy ( & V_100 . V_160 [ 8 ] , V_5 -> V_164 , 8 ) ;
V_153 = ( V_159 - V_14 -> V_76 ) / V_3 ;
V_151 = F_117 ( V_165 ,
V_14 -> V_136 ,
V_5 -> V_49 . V_166 + V_153 ) ;
V_150 = F_117 ( V_165 ,
V_14 -> V_167 ,
V_5 -> V_49 . V_168 + V_153 -
V_5 -> V_49 . V_169 ) ;
V_155 = V_14 -> V_124 ;
V_157 = V_5 -> V_49 . V_157 ;
V_152 = V_14 -> V_76 ;
F_98 ( & V_14 -> V_48 ) ;
V_154 = V_5 -> V_49 . V_163 *
V_5 -> V_49 . V_170 *
V_5 -> V_53 -> V_171 / V_3 ;
F_92 ( & V_5 -> V_48 ) ;
if ( V_150 <= V_154 ) {
F_102 ( V_14 ) ;
F_65 ( V_5 ) ;
V_156 = - 1 ;
goto V_119;
}
V_158 = V_126 ;
if ( V_14 -> V_57 & V_172 )
V_158 |= V_172 ;
V_148 = ! V_157 ||
F_118 ( V_5 ) < V_157 ?
F_76 ( V_5 , & V_100 , V_155 ,
F_77 ( & V_100 ) & V_173 ,
V_158 ) : NULL ;
if ( ! V_148 || F_83 ( V_148 ) ) {
F_102 ( V_14 ) ;
F_65 ( V_5 ) ;
F_41 ( L_14 , V_41 ) ;
V_149 = & V_100 ;
F_90 ( & V_5 -> V_48 ) ;
goto V_161;
}
F_97 ( & V_148 -> V_48 ) ;
V_148 -> V_133 = V_14 ;
V_148 -> V_136 = V_151 ;
V_148 -> V_167 = V_150 ;
V_148 -> V_1 = V_159 ;
V_148 -> V_76 = V_152 ;
F_98 ( & V_148 -> V_48 ) ;
F_119 ( V_148 ) ;
F_102 ( V_148 ) ;
F_65 ( V_5 ) ;
V_119:
return V_156 ;
}
static inline int F_120 ( int type )
{
if ( type & ( V_174 | V_175 | V_111 ) )
return 1 ;
return 0 ;
}
static int F_121 ( struct V_84 * V_84 ,
struct V_176 * V_177 ,
struct V_178 * V_97 ,
int V_179 )
{
int V_156 ;
if ( V_179 <= V_177 -> V_180 ) {
switch ( V_179 ) {
case V_181 :
V_156 = V_177 -> V_182 ;
break;
case V_183 :
V_156 = V_177 -> V_184 ;
break;
default:
V_156 = ! ! F_122 ( V_179 , V_177 -> V_185 ) ;
}
goto V_119;
}
switch ( V_179 ) {
case V_186 :
V_156 = ! ! V_177 -> V_82 ;
break;
case V_187 :
V_156 = F_123 ( & V_177 -> V_82 -> V_100 , V_97 -> V_100 ) ;
break;
case V_181 :
V_156 = F_124 ( V_177 -> V_108 ) ;
if ( V_156 >= V_97 -> V_105 )
V_156 = - V_156 ;
else
V_156 -= 128 ;
V_177 -> V_182 = V_156 ;
break;
case V_188 :
V_156 = F_120 ( V_177 -> V_108 ) ||
! ( V_177 -> V_82 -> V_57 & ( V_189 | V_172 ) ) ;
break;
#ifdef F_125
case V_190 :
{
int V_191 = ! ( V_97 -> V_192 & V_193 ) ;
V_156 = ! ( V_177 -> V_82 -> V_57 & V_194 ) ^ V_191 ;
break;
}
#endif
case V_195 :
V_156 = ( ! V_97 -> V_143 ||
V_97 -> V_143 == V_177 -> V_82 -> V_5 -> V_7 -> V_143 ) ;
break;
case V_196 :
V_156 = F_126 ( V_84 ,
& V_177 -> V_82 -> V_100 , V_177 -> V_108 ,
V_177 -> V_82 -> V_5 -> V_7 -> V_143 ) == V_97 -> V_197 ;
break;
#ifdef F_42
case V_198 :
{
int V_199 = V_97 -> V_192 & ( V_200 | V_201 ) ?
! ! ( V_97 -> V_192 & V_201 ) :
V_177 -> V_82 -> V_5 -> V_49 . V_73 >= 2 ;
V_156 = ( ! ( V_177 -> V_82 -> V_57 & V_126 ) ) ^ V_199 ;
break;
}
#endif
case V_202 :
V_156 = ! ( F_127 ( & V_177 -> V_82 -> V_100 ) ^
F_127 ( V_97 -> V_100 ) ) ;
break;
case V_183 :
V_156 = F_128 ( & V_177 -> V_82 -> V_100 , V_97 -> V_100 ) ;
if ( V_156 > V_177 -> V_82 -> V_124 )
V_156 = V_177 -> V_82 -> V_124 ;
V_177 -> V_184 = V_156 ;
break;
default:
V_156 = 0 ;
}
if ( V_156 )
F_129 ( V_179 , V_177 -> V_185 ) ;
V_177 -> V_180 = V_179 ;
V_119:
return V_156 ;
}
int F_130 ( struct V_84 * V_84 , const struct V_6 * V_203 ,
const struct V_102 * V_144 , unsigned int V_192 ,
struct V_102 * V_204 )
{
struct V_176 V_205 [ 2 ] ,
* V_177 = & V_205 [ 0 ] , * V_206 = & V_205 [ 1 ] ;
struct V_178 V_97 ;
struct V_6 * V_7 ;
int V_207 ;
V_207 = F_131 ( V_144 ) ;
V_97 . V_100 = V_144 ;
V_97 . V_143 = V_203 ? V_203 -> V_143 : 0 ;
V_97 . V_105 = F_124 ( V_207 ) ;
V_97 . V_197 = F_126 ( V_84 , V_144 , V_207 , V_97 . V_143 ) ;
V_97 . V_192 = V_192 ;
V_206 -> V_180 = - 1 ;
V_206 -> V_82 = NULL ;
F_132 () ;
F_133 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_207 & V_110 ) ||
V_97 . V_105 <= V_208 ) &&
V_97 . V_143 && V_7 -> V_143 != V_97 . V_143 )
continue;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
continue;
F_134 ( & V_5 -> V_48 ) ;
F_53 (score->ifa, &idev->addr_list, if_list) {
int V_179 ;
if ( ( V_177 -> V_82 -> V_57 & V_83 ) &&
( ! ( V_177 -> V_82 -> V_57 & V_172 ) ) )
continue;
V_177 -> V_108 = F_131 ( & V_177 -> V_82 -> V_100 ) ;
if ( F_135 ( V_177 -> V_108 == V_109 ||
V_177 -> V_108 & V_110 ) ) {
F_136 ( V_209
L_15
L_16 ,
V_7 -> V_42 ) ;
continue;
}
V_177 -> V_180 = - 1 ;
F_137 ( V_177 -> V_185 , V_210 ) ;
for ( V_179 = 0 ; V_179 < V_210 ; V_179 ++ ) {
int V_211 , V_212 ;
V_211 = F_121 ( V_84 , V_206 , & V_97 , V_179 ) ;
V_212 = F_121 ( V_84 , V_177 , & V_97 , V_179 ) ;
if ( V_211 > V_212 ) {
if ( V_179 == V_181 &&
V_177 -> V_182 > 0 ) {
goto V_213;
}
break;
} else if ( V_211 < V_212 ) {
if ( V_206 -> V_82 )
F_102 ( V_206 -> V_82 ) ;
F_11 ( V_177 -> V_82 ) ;
F_138 ( V_206 , V_177 ) ;
V_177 -> V_82 = V_206 -> V_82 ;
break;
}
}
}
V_213:
F_139 ( & V_5 -> V_48 ) ;
}
F_140 () ;
if ( ! V_206 -> V_82 )
return - V_112 ;
* V_204 = V_206 -> V_82 -> V_100 ;
F_102 ( V_206 -> V_82 ) ;
return 0 ;
}
int F_141 ( struct V_6 * V_7 , struct V_102 * V_100 ,
unsigned char V_214 )
{
struct V_4 * V_5 ;
int V_107 = - V_112 ;
F_132 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
struct V_13 * V_14 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_105 == V_215 &&
! ( V_14 -> V_57 & V_214 ) ) {
* V_100 = V_14 -> V_100 ;
V_107 = 0 ;
break;
}
}
F_139 ( & V_5 -> V_48 ) ;
}
F_140 () ;
return V_107 ;
}
static int F_118 ( struct V_4 * V_5 )
{
int V_216 = 0 ;
struct V_13 * V_14 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list)
V_216 ++ ;
F_139 ( & V_5 -> V_48 ) ;
return V_216 ;
}
int F_142 ( struct V_84 * V_84 , const struct V_102 * V_100 ,
struct V_6 * V_7 , int V_217 )
{
struct V_13 * V_14 ;
struct V_218 * V_219 ;
unsigned int V_106 = F_73 ( V_100 ) ;
F_79 () ;
F_143 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_144 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_123 ( & V_14 -> V_100 , V_100 ) &&
! ( V_14 -> V_57 & V_83 ) &&
( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_105 & ( V_215 | V_220 ) || V_217 ) ) ) {
F_93 () ;
return 1 ;
}
}
F_93 () ;
return 0 ;
}
static bool F_81 ( struct V_84 * V_84 , const struct V_102 * V_100 ,
struct V_6 * V_7 )
{
unsigned int V_106 = F_73 ( V_100 ) ;
struct V_13 * V_14 ;
struct V_218 * V_219 ;
F_145 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_144 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_123 ( & V_14 -> V_100 , V_100 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
int F_146 ( const struct V_102 * V_100 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_132 ;
V_132 = 0 ;
F_132 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifa, &idev->addr_list, if_list) {
V_132 = F_105 ( V_100 , & V_82 -> V_100 ,
V_82 -> V_124 ) ;
if ( V_132 )
break;
}
F_139 ( & V_5 -> V_48 ) ;
}
F_140 () ;
return V_132 ;
}
struct V_13 * F_147 ( struct V_84 * V_84 , const struct V_102 * V_100 ,
struct V_6 * V_7 , int V_217 )
{
struct V_13 * V_14 , * V_221 = NULL ;
unsigned int V_106 = F_73 ( V_100 ) ;
struct V_218 * V_219 ;
F_79 () ;
F_148 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_144 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_123 ( & V_14 -> V_100 , V_100 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_105 & ( V_215 | V_220 ) || V_217 ) ) {
V_221 = V_14 ;
F_11 ( V_14 ) ;
break;
}
}
}
F_93 () ;
return V_221 ;
}
static void F_149 ( struct V_13 * V_14 , int V_222 )
{
if ( V_14 -> V_57 & V_134 ) {
F_97 ( & V_14 -> V_48 ) ;
F_7 ( V_14 ) ;
V_14 -> V_57 |= V_83 ;
if ( V_222 )
V_14 -> V_57 |= V_223 ;
F_98 ( & V_14 -> V_48 ) ;
if ( V_222 )
F_109 ( 0 , V_14 ) ;
F_102 ( V_14 ) ;
#ifdef F_42
} else if ( V_14 -> V_57 & V_126 ) {
struct V_13 * V_133 ;
F_97 ( & V_14 -> V_48 ) ;
V_133 = V_14 -> V_133 ;
if ( V_133 ) {
F_11 ( V_133 ) ;
F_98 ( & V_14 -> V_48 ) ;
F_115 ( V_133 , V_14 ) ;
F_102 ( V_133 ) ;
} else {
F_98 ( & V_14 -> V_48 ) ;
}
F_96 ( V_14 ) ;
#endif
} else
F_96 ( V_14 ) ;
}
static int F_150 ( struct V_13 * V_14 )
{
int V_107 = - V_224 ;
F_80 ( & V_14 -> V_122 ) ;
if ( V_14 -> V_95 == V_225 ) {
V_14 -> V_95 = V_226 ;
V_107 = 0 ;
}
F_89 ( & V_14 -> V_122 ) ;
return V_107 ;
}
void F_151 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
if ( F_150 ( V_14 ) ) {
F_102 ( V_14 ) ;
return;
}
F_152 ( L_17 ,
V_14 -> V_5 -> V_7 -> V_42 , & V_14 -> V_100 ) ;
if ( V_5 -> V_49 . V_60 > 1 && ! V_5 -> V_49 . V_115 ) {
struct V_102 V_100 ;
V_100 . V_227 [ 0 ] = F_153 ( 0xfe800000 ) ;
V_100 . V_227 [ 1 ] = 0 ;
if ( ! F_154 ( V_100 . V_160 + 8 , V_5 -> V_7 ) &&
F_123 ( & V_14 -> V_100 , & V_100 ) ) {
V_5 -> V_49 . V_115 = 1 ;
F_41 ( L_18 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
}
}
F_149 ( V_14 , 1 ) ;
}
void F_155 ( struct V_6 * V_7 , const struct V_102 * V_100 )
{
struct V_102 V_228 ;
if ( V_7 -> V_57 & ( V_59 | V_58 ) )
return;
F_156 ( V_100 , & V_228 ) ;
F_47 ( V_7 , & V_228 ) ;
}
void F_157 ( struct V_4 * V_5 , const struct V_102 * V_100 )
{
struct V_102 V_228 ;
if ( V_5 -> V_7 -> V_57 & ( V_59 | V_58 ) )
return;
F_156 ( V_100 , & V_228 ) ;
F_158 ( V_5 , & V_228 ) ;
}
static void F_54 ( struct V_13 * V_14 )
{
struct V_102 V_100 ;
if ( V_14 -> V_124 == 127 )
return;
F_110 ( & V_100 , & V_14 -> V_100 , V_14 -> V_124 ) ;
if ( F_159 ( & V_100 ) )
return;
F_160 ( V_14 -> V_5 -> V_7 , & V_100 ) ;
}
static void F_55 ( struct V_13 * V_14 )
{
struct V_102 V_100 ;
if ( V_14 -> V_124 == 127 )
return;
F_110 ( & V_100 , & V_14 -> V_100 , V_14 -> V_124 ) ;
if ( F_159 ( & V_100 ) )
return;
F_161 ( V_14 -> V_5 , & V_100 ) ;
}
static int F_162 ( T_3 * V_229 , struct V_6 * V_7 )
{
if ( V_7 -> V_230 != V_231 )
return - 1 ;
memcpy ( V_229 , V_7 -> V_232 , 3 ) ;
memcpy ( V_229 + 5 , V_7 -> V_232 + 3 , 3 ) ;
if ( V_7 -> V_233 ) {
V_229 [ 3 ] = ( V_7 -> V_233 >> 8 ) & 0xFF ;
V_229 [ 4 ] = V_7 -> V_233 & 0xFF ;
} else {
V_229 [ 3 ] = 0xFF ;
V_229 [ 4 ] = 0xFE ;
V_229 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_163 ( T_3 * V_229 , struct V_6 * V_7 )
{
if ( V_7 -> V_230 != V_234 )
return - 1 ;
memcpy ( V_229 , V_7 -> V_232 , 8 ) ;
return 0 ;
}
static int F_164 ( T_3 * V_229 , struct V_6 * V_7 )
{
if ( V_7 -> V_230 != V_235 )
return - 1 ;
memset ( V_229 , 0 , 7 ) ;
V_229 [ 7 ] = * ( T_3 * ) V_7 -> V_232 ;
return 0 ;
}
static int F_165 ( T_3 * V_229 , struct V_6 * V_7 )
{
if ( V_7 -> V_230 != V_236 )
return - 1 ;
memcpy ( V_229 , V_7 -> V_232 + 12 , 8 ) ;
V_229 [ 0 ] |= 2 ;
return 0 ;
}
static int F_166 ( T_3 * V_229 , T_4 V_100 )
{
if ( V_100 == 0 )
return - 1 ;
V_229 [ 0 ] = ( F_167 ( V_100 ) || F_168 ( V_100 ) ||
F_169 ( V_100 ) || F_170 ( V_100 ) ||
F_171 ( V_100 ) || F_172 ( V_100 ) ||
F_173 ( V_100 ) || F_174 ( V_100 ) ||
F_175 ( V_100 ) || F_176 ( V_100 ) ||
F_177 ( V_100 ) ) ? 0x00 : 0x02 ;
V_229 [ 1 ] = 0 ;
V_229 [ 2 ] = 0x5E ;
V_229 [ 3 ] = 0xFE ;
memcpy ( V_229 + 4 , & V_100 , 4 ) ;
return 0 ;
}
static int F_178 ( T_3 * V_229 , struct V_6 * V_7 )
{
if ( V_7 -> V_64 & V_65 )
return F_166 ( V_229 , * ( T_4 * ) V_7 -> V_232 ) ;
return - 1 ;
}
static int F_179 ( T_3 * V_229 , struct V_6 * V_7 )
{
return F_166 ( V_229 , * ( T_4 * ) V_7 -> V_232 ) ;
}
static int F_154 ( T_3 * V_229 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_237 :
case V_238 :
return F_162 ( V_229 , V_7 ) ;
case V_239 :
return F_164 ( V_229 , V_7 ) ;
case V_240 :
return F_165 ( V_229 , V_7 ) ;
case V_63 :
return F_178 ( V_229 , V_7 ) ;
case V_241 :
return F_179 ( V_229 , V_7 ) ;
case V_242 :
return F_163 ( V_229 , V_7 ) ;
}
return - 1 ;
}
static int F_180 ( T_3 * V_229 , struct V_4 * V_5 )
{
int V_107 = - 1 ;
struct V_13 * V_14 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_105 == V_215 && ! ( V_14 -> V_57 & V_83 ) ) {
memcpy ( V_229 , V_14 -> V_100 . V_160 + 8 , 8 ) ;
V_107 = 0 ;
break;
}
}
F_139 ( & V_5 -> V_48 ) ;
return V_107 ;
}
static void F_181 ( struct V_4 * V_5 )
{
V_243:
F_182 ( V_5 -> V_164 , sizeof( V_5 -> V_164 ) ) ;
V_5 -> V_164 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_164 [ 0 ] == 0xfd &&
( V_5 -> V_164 [ 1 ] & V_5 -> V_164 [ 2 ] & V_5 -> V_164 [ 3 ] & V_5 -> V_164 [ 4 ] & V_5 -> V_164 [ 5 ] & V_5 -> V_164 [ 6 ] ) == 0xff &&
( V_5 -> V_164 [ 7 ] & 0x80 ) )
goto V_243;
if ( ( V_5 -> V_164 [ 0 ] | V_5 -> V_164 [ 1 ] ) == 0 ) {
if ( V_5 -> V_164 [ 2 ] == 0x5e && V_5 -> V_164 [ 3 ] == 0xfe )
goto V_243;
if ( ( V_5 -> V_164 [ 2 ] | V_5 -> V_164 [ 3 ] | V_5 -> V_164 [ 4 ] | V_5 -> V_164 [ 5 ] | V_5 -> V_164 [ 6 ] | V_5 -> V_164 [ 7 ] ) == 0x00 )
goto V_243;
}
}
static void V_69 ( unsigned long V_123 )
{
struct V_4 * V_5 = (struct V_4 * ) V_123 ;
unsigned long V_24 ;
F_79 () ;
F_100 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 )
goto V_119;
F_181 ( V_5 ) ;
V_24 = V_25 +
V_5 -> V_49 . V_168 * V_3 -
V_5 -> V_49 . V_163 * V_5 -> V_49 . V_170 * V_5 -> V_53 -> V_171 -
V_5 -> V_49 . V_169 * V_3 ;
if ( F_107 ( V_24 , V_25 ) ) {
F_26 ( L_19 ,
V_41 , V_5 -> V_7 -> V_42 ) ;
goto V_119;
}
if ( ! F_183 ( & V_5 -> V_68 , V_24 ) )
F_39 ( V_5 ) ;
V_119:
F_108 ( & V_5 -> V_48 ) ;
F_93 () ;
F_65 ( V_5 ) ;
}
static void F_116 ( struct V_4 * V_5 , struct V_102 * V_149 )
{
if ( V_149 && memcmp ( V_5 -> V_164 , & V_149 -> V_160 [ 8 ] , 8 ) == 0 )
F_181 ( V_5 ) ;
}
static void
F_184 ( struct V_102 * V_244 , int V_245 , struct V_6 * V_7 ,
unsigned long V_24 , T_1 V_57 )
{
struct V_246 V_247 = {
. V_248 = V_249 ,
. V_250 = V_251 ,
. V_252 = V_7 -> V_143 ,
. V_253 = V_24 ,
. V_254 = V_245 ,
. V_255 = V_256 | V_57 ,
. V_257 . V_258 = F_32 ( V_7 ) ,
. V_259 = V_260 ,
} ;
V_247 . V_261 = * V_244 ;
#if F_40 ( V_61 ) || F_40 ( V_62 )
if ( V_7 -> type == V_63 && ( V_7 -> V_57 & V_262 ) )
V_247 . V_255 |= V_263 ;
#endif
F_185 ( & V_247 ) ;
}
static struct V_8 * F_186 ( const struct V_102 * V_244 ,
int V_245 ,
const struct V_6 * V_7 ,
T_1 V_57 , T_1 V_264 )
{
struct V_265 * V_266 ;
struct V_8 * V_9 = NULL ;
struct V_267 * V_88 ;
V_88 = F_187 ( F_32 ( V_7 ) , V_249 ) ;
if ( V_88 == NULL )
return NULL ;
F_134 ( & V_88 -> V_268 ) ;
V_266 = F_188 ( & V_88 -> V_269 , V_244 , V_245 , NULL , 0 ) ;
if ( ! V_266 )
goto V_119;
for ( V_9 = V_266 -> V_270 ; V_9 ; V_9 = V_9 -> V_97 . V_271 ) {
if ( V_9 -> V_97 . V_7 -> V_143 != V_7 -> V_143 )
continue;
if ( ( V_9 -> V_10 & V_57 ) != V_57 )
continue;
if ( ( V_264 != 0 ) && ( ( V_9 -> V_10 & V_57 ) != 0 ) )
continue;
F_189 ( & V_9 -> V_97 ) ;
break;
}
V_119:
F_139 ( & V_88 -> V_268 ) ;
return V_9 ;
}
static void F_190 ( struct V_6 * V_7 )
{
struct V_246 V_247 = {
. V_248 = V_272 ,
. V_250 = V_251 ,
. V_252 = V_7 -> V_143 ,
. V_254 = 8 ,
. V_255 = V_256 ,
. V_257 . V_258 = F_32 ( V_7 ) ,
} ;
F_191 ( & V_247 . V_261 , F_153 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_185 ( & V_247 ) ;
}
static void F_192 ( struct V_6 * V_7 )
{
struct V_246 V_247 = {
. V_248 = V_273 ,
. V_250 = V_251 ,
. V_252 = V_7 -> V_143 ,
. V_254 = 96 ,
. V_255 = V_256 | V_263 ,
. V_257 . V_258 = F_32 ( V_7 ) ,
} ;
F_185 ( & V_247 ) ;
}
static struct V_4 * F_193 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
return F_78 ( - V_121 ) ;
if ( V_5 -> V_49 . V_115 )
return F_78 ( - V_116 ) ;
if ( ! ( V_7 -> V_57 & V_59 ) )
F_190 ( V_7 ) ;
return V_5 ;
}
void F_194 ( struct V_6 * V_7 , T_3 * V_274 , int V_275 , bool V_276 )
{
struct V_277 * V_278 ;
V_165 V_136 ;
V_165 V_167 ;
int V_108 ;
struct V_4 * V_279 ;
struct V_84 * V_84 = F_32 ( V_7 ) ;
V_278 = (struct V_277 * ) V_274 ;
if ( V_275 < sizeof( struct V_277 ) ) {
F_36 ( ( L_20 ) ) ;
return;
}
V_108 = F_77 ( & V_278 -> V_139 ) ;
if ( V_108 & ( V_110 | V_280 ) )
return;
V_136 = F_195 ( V_278 -> V_281 ) ;
V_167 = F_195 ( V_278 -> V_282 ) ;
if ( V_167 > V_136 ) {
F_196 ( L_21 ) ;
return;
}
V_279 = F_197 ( V_7 ) ;
if ( V_279 == NULL ) {
F_198 ( L_22 ,
V_7 -> V_42 ) ;
return;
}
if ( V_278 -> V_132 ) {
struct V_8 * V_9 ;
unsigned long V_283 ;
if ( V_3 > V_284 )
V_283 = F_106 ( V_136 , V_3 ) ;
else
V_283 = F_106 ( V_136 , V_284 ) ;
if ( F_199 ( V_283 ) )
V_283 *= V_3 ;
V_9 = F_186 ( & V_278 -> V_139 ,
V_278 -> V_124 ,
V_7 ,
V_285 | V_286 ,
V_11 | V_12 ) ;
if ( V_9 ) {
if ( V_136 == 0 ) {
F_112 ( V_9 ) ;
V_9 = NULL ;
} else if ( F_199 ( V_283 ) ) {
F_113 ( V_9 , V_25 + V_283 ) ;
} else {
F_200 ( V_9 ) ;
}
} else if ( V_136 ) {
T_5 V_24 = 0 ;
int V_57 = V_285 | V_286 ;
if ( F_199 ( V_283 ) ) {
V_57 |= V_147 ;
V_24 = F_201 ( V_283 ) ;
}
F_184 ( & V_278 -> V_139 , V_278 -> V_124 ,
V_7 , V_24 , V_57 ) ;
}
if ( V_9 )
F_67 ( & V_9 -> V_97 ) ;
}
if ( V_278 -> V_287 && V_279 -> V_49 . V_287 ) {
struct V_13 * V_14 ;
struct V_102 V_100 ;
int V_288 = 0 , V_289 = 0 ;
if ( V_278 -> V_124 == 64 ) {
memcpy ( & V_100 , & V_278 -> V_139 , 8 ) ;
if ( F_154 ( V_100 . V_160 + 8 , V_7 ) &&
F_180 ( V_100 . V_160 + 8 , V_279 ) ) {
F_65 ( V_279 ) ;
return;
}
goto V_290;
}
F_198 ( L_23 ,
V_278 -> V_124 ) ;
F_65 ( V_279 ) ;
return;
V_290:
V_14 = F_147 ( V_84 , & V_100 , V_7 , 1 ) ;
if ( V_14 == NULL && V_136 ) {
int V_157 = V_279 -> V_49 . V_157 ;
T_1 V_158 = 0 ;
#ifdef F_202
if ( V_279 -> V_49 . V_291 &&
! V_84 -> V_28 . V_92 -> V_55 && V_276 )
V_158 = V_172 ;
#endif
if ( ! V_157 ||
F_118 ( V_279 ) < V_157 )
V_14 = F_76 ( V_279 , & V_100 , V_278 -> V_124 ,
V_108 & V_173 ,
V_158 ) ;
if ( ! V_14 || F_83 ( V_14 ) ) {
F_65 ( V_279 ) ;
return;
}
V_289 = V_288 = 1 ;
V_14 -> V_1 = V_25 ;
F_119 ( V_14 ) ;
}
if ( V_14 ) {
int V_57 ;
unsigned long V_159 ;
#ifdef F_42
struct V_13 * V_148 ;
#endif
T_1 V_292 ;
F_80 ( & V_14 -> V_48 ) ;
V_159 = V_25 ;
if ( V_14 -> V_136 > ( V_159 - V_14 -> V_76 ) / V_3 )
V_292 = V_14 -> V_136 - ( V_159 - V_14 -> V_76 ) / V_3 ;
else
V_292 = 0 ;
if ( ! V_289 && V_292 ) {
if ( V_136 > V_293 ||
V_136 > V_292 )
V_289 = 1 ;
else if ( V_292 <= V_293 ) {
if ( V_167 != V_14 -> V_167 ) {
V_136 = V_292 ;
V_289 = 1 ;
}
} else {
V_136 = V_293 ;
if ( V_136 < V_167 )
V_167 = V_136 ;
V_289 = 1 ;
}
}
if ( V_289 ) {
V_14 -> V_136 = V_136 ;
V_14 -> V_167 = V_167 ;
V_14 -> V_76 = V_159 ;
V_57 = V_14 -> V_57 ;
V_14 -> V_57 &= ~ V_189 ;
F_89 ( & V_14 -> V_48 ) ;
if ( ! ( V_57 & V_83 ) )
F_109 ( 0 , V_14 ) ;
} else
F_89 ( & V_14 -> V_48 ) ;
#ifdef F_42
F_134 ( & V_279 -> V_48 ) ;
F_53 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_153 , V_294 , V_295 ;
if ( V_14 != V_148 -> V_133 )
continue;
V_153 = ( V_159 - V_148 -> V_1 ) / V_3 ;
V_294 = V_279 -> V_49 . V_166 - V_153 ;
if ( V_294 < 0 )
V_294 = 0 ;
V_295 = V_279 -> V_49 . V_168 -
V_279 -> V_49 . V_169 -
V_153 ;
if ( V_295 < 0 )
V_295 = 0 ;
if ( V_136 > V_294 )
V_136 = V_294 ;
if ( V_167 > V_295 )
V_167 = V_295 ;
F_80 ( & V_148 -> V_48 ) ;
V_57 = V_148 -> V_57 ;
V_148 -> V_136 = V_136 ;
V_148 -> V_167 = V_167 ;
V_148 -> V_76 = V_159 ;
if ( V_167 > 0 )
V_148 -> V_57 &= ~ V_189 ;
F_89 ( & V_148 -> V_48 ) ;
if ( ! ( V_57 & V_83 ) )
F_109 ( 0 , V_148 ) ;
}
if ( ( V_288 || F_22 ( & V_279 -> V_67 ) ) && V_279 -> V_49 . V_73 > 0 ) {
F_139 ( & V_279 -> V_48 ) ;
F_115 ( V_14 , NULL ) ;
} else {
F_139 ( & V_279 -> V_48 ) ;
}
#endif
F_102 ( V_14 ) ;
F_203 ( 0 ) ;
}
}
F_204 ( V_296 , V_279 , V_278 ) ;
F_65 ( V_279 ) ;
}
int F_205 ( struct V_84 * V_84 , void T_6 * V_297 )
{
struct V_298 V_299 ;
struct V_6 * V_7 ;
int V_107 = - V_300 ;
F_206 () ;
V_107 = - V_301 ;
if ( F_207 ( & V_299 , V_297 , sizeof( struct V_298 ) ) )
goto V_302;
V_7 = F_208 ( V_84 , V_299 . V_303 ) ;
V_107 = - V_113 ;
if ( V_7 == NULL )
goto V_302;
#if F_40 ( V_61 ) || F_40 ( V_62 )
if ( V_7 -> type == V_63 ) {
const struct V_304 * V_305 = V_7 -> V_306 ;
struct V_307 V_308 ;
struct V_309 V_89 ;
V_107 = - V_112 ;
if ( ! ( F_77 ( & V_299 . V_310 ) & V_175 ) )
goto V_302;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_311 . V_144 = V_299 . V_310 . V_227 [ 3 ] ;
V_89 . V_311 . V_204 = 0 ;
V_89 . V_311 . V_312 = 4 ;
V_89 . V_311 . V_313 = 5 ;
V_89 . V_311 . V_314 = V_315 ;
V_89 . V_311 . V_316 = 64 ;
V_308 . V_317 . V_318 = ( V_319 void T_6 * ) & V_89 ;
if ( V_305 -> V_320 ) {
T_7 V_321 = F_209 () ;
F_210 ( V_322 ) ;
V_107 = V_305 -> V_320 ( V_7 , & V_308 , V_323 ) ;
F_210 ( V_321 ) ;
} else
V_107 = - V_324 ;
if ( V_107 == 0 ) {
V_107 = - V_121 ;
V_7 = F_211 ( V_84 , V_89 . V_42 ) ;
if ( ! V_7 )
goto V_302;
V_107 = F_212 ( V_7 ) ;
}
}
#endif
V_302:
F_61 () ;
return V_107 ;
}
static int F_213 ( struct V_84 * V_84 , int V_143 , const struct V_102 * V_244 ,
unsigned int V_245 , T_8 V_325 , V_165 V_167 ,
V_165 V_136 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_105 ;
T_1 V_57 ;
T_5 V_24 ;
unsigned long V_326 ;
F_29 () ;
if ( V_245 > 128 )
return - V_300 ;
if ( ! V_136 || V_167 > V_136 )
return - V_300 ;
V_7 = F_208 ( V_84 , V_143 ) ;
if ( ! V_7 )
return - V_113 ;
V_5 = F_193 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return F_84 ( V_5 ) ;
V_105 = F_214 ( V_244 ) ;
V_326 = F_106 ( V_136 , V_3 ) ;
if ( F_199 ( V_326 ) ) {
V_24 = F_201 ( V_326 * V_3 ) ;
V_136 = V_326 ;
V_57 = V_147 ;
} else {
V_24 = 0 ;
V_57 = 0 ;
V_325 |= V_134 ;
}
V_326 = F_106 ( V_167 , V_3 ) ;
if ( F_199 ( V_326 ) ) {
if ( V_326 == 0 )
V_325 |= V_189 ;
V_167 = V_326 ;
}
V_14 = F_76 ( V_5 , V_244 , V_245 , V_105 , V_325 ) ;
if ( ! F_83 ( V_14 ) ) {
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_136 = V_136 ;
V_14 -> V_167 = V_167 ;
V_14 -> V_76 = V_25 ;
F_98 ( & V_14 -> V_48 ) ;
F_184 ( & V_14 -> V_100 , V_14 -> V_124 , V_7 ,
V_24 , V_57 ) ;
F_119 ( V_14 ) ;
F_102 ( V_14 ) ;
F_203 ( 0 ) ;
return 0 ;
}
return F_84 ( V_14 ) ;
}
static int F_215 ( struct V_84 * V_84 , int V_143 , const struct V_102 * V_244 ,
unsigned int V_245 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_245 > 128 )
return - V_300 ;
V_7 = F_208 ( V_84 , V_143 ) ;
if ( ! V_7 )
return - V_113 ;
if ( ( V_5 = F_49 ( V_7 ) ) == NULL )
return - V_327 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_124 == V_245 &&
F_123 ( V_244 , & V_14 -> V_100 ) ) {
F_11 ( V_14 ) ;
F_139 ( & V_5 -> V_48 ) ;
F_96 ( V_14 ) ;
if ( F_22 ( & V_5 -> V_39 ) )
F_216 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_139 ( & V_5 -> V_48 ) ;
return - V_112 ;
}
int F_217 ( struct V_84 * V_84 , void T_6 * V_297 )
{
struct V_298 V_299 ;
int V_107 ;
if ( ! F_218 ( V_328 ) )
return - V_329 ;
if ( F_207 ( & V_299 , V_297 , sizeof( struct V_298 ) ) )
return - V_301 ;
F_206 () ;
V_107 = F_213 ( V_84 , V_299 . V_303 , & V_299 . V_310 ,
V_299 . V_330 , V_134 ,
V_331 , V_331 ) ;
F_61 () ;
return V_107 ;
}
int F_219 ( struct V_84 * V_84 , void T_6 * V_297 )
{
struct V_298 V_299 ;
int V_107 ;
if ( ! F_218 ( V_328 ) )
return - V_329 ;
if ( F_207 ( & V_299 , V_297 , sizeof( struct V_298 ) ) )
return - V_301 ;
F_206 () ;
V_107 = F_215 ( V_84 , V_299 . V_303 , & V_299 . V_310 ,
V_299 . V_330 ) ;
F_61 () ;
return V_107 ;
}
static void F_220 ( struct V_4 * V_5 , const struct V_102 * V_100 ,
int V_245 , int V_105 )
{
struct V_13 * V_14 ;
V_14 = F_76 ( V_5 , V_100 , V_245 , V_105 , V_134 ) ;
if ( ! F_83 ( V_14 ) ) {
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_57 &= ~ V_83 ;
F_98 ( & V_14 -> V_48 ) ;
F_109 ( V_332 , V_14 ) ;
F_102 ( V_14 ) ;
}
}
static void F_221 ( struct V_4 * V_5 )
{
struct V_102 V_100 ;
struct V_6 * V_7 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
int V_105 ;
F_29 () ;
memset ( & V_100 , 0 , sizeof( struct V_102 ) ) ;
memcpy ( & V_100 . V_227 [ 3 ] , V_5 -> V_7 -> V_232 , 4 ) ;
if ( V_5 -> V_7 -> V_57 & V_262 ) {
V_100 . V_227 [ 0 ] = F_153 ( 0xfe800000 ) ;
V_105 = V_215 ;
} else {
V_105 = V_175 ;
}
if ( V_100 . V_227 [ 3 ] ) {
F_220 ( V_5 , & V_100 , 128 , V_105 ) ;
return;
}
F_57 (net, dev) {
struct V_333 * V_334 = F_222 ( V_7 ) ;
if ( V_334 && ( V_7 -> V_57 & V_81 ) ) {
struct V_335 * V_82 ;
int V_336 = V_105 ;
for ( V_82 = V_334 -> V_337 ; V_82 ; V_82 = V_82 -> V_338 ) {
int V_245 ;
V_100 . V_227 [ 3 ] = V_82 -> V_339 ;
if ( V_82 -> V_340 == V_341 )
continue;
if ( V_82 -> V_340 >= V_342 ) {
if ( V_5 -> V_7 -> V_57 & V_262 )
continue;
V_336 |= V_220 ;
}
if ( V_5 -> V_7 -> V_57 & V_262 )
V_245 = 64 ;
else
V_245 = 96 ;
F_220 ( V_5 , & V_100 , V_245 , V_336 ) ;
}
}
}
}
static void F_223 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_24 ( L_24 , V_41 ) ;
return;
}
F_220 ( V_5 , & V_343 , 128 , V_220 ) ;
}
static void F_224 ( struct V_4 * V_5 , const struct V_102 * V_100 )
{
struct V_13 * V_14 ;
T_1 V_158 = V_134 ;
#ifdef F_202
if ( V_5 -> V_49 . V_291 &&
! F_32 ( V_5 -> V_7 ) -> V_28 . V_92 -> V_55 )
V_158 |= V_172 ;
#endif
V_14 = F_76 ( V_5 , V_100 , 64 , V_215 , V_158 ) ;
if ( ! F_83 ( V_14 ) ) {
F_184 ( & V_14 -> V_100 , V_14 -> V_124 , V_5 -> V_7 , 0 , 0 ) ;
F_119 ( V_14 ) ;
F_102 ( V_14 ) ;
}
}
static void F_225 ( struct V_6 * V_7 )
{
struct V_102 V_100 ;
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_237 ) &&
( V_7 -> type != V_238 ) &&
( V_7 -> type != V_239 ) &&
( V_7 -> type != V_240 ) &&
( V_7 -> type != V_242 ) ) {
return;
}
V_5 = F_193 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return;
memset ( & V_100 , 0 , sizeof( struct V_102 ) ) ;
V_100 . V_227 [ 0 ] = F_153 ( 0xFE800000 ) ;
if ( F_154 ( V_100 . V_160 + 8 , V_7 ) == 0 )
F_224 ( V_5 , & V_100 ) ;
}
static void F_226 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_24 ( L_24 , V_41 ) ;
return;
}
if ( V_7 -> V_64 & V_65 ) {
struct V_102 V_100 ;
F_191 ( & V_100 , F_153 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_184 ( & V_100 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_154 ( V_100 . V_160 + 8 , V_7 ) )
F_224 ( V_5 , & V_100 ) ;
return;
}
F_221 ( V_5 ) ;
if ( V_7 -> V_57 & V_262 )
F_190 ( V_7 ) ;
else
F_192 ( V_7 ) ;
}
static void F_227 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_102 V_100 ;
F_41 ( L_25 , V_41 , V_7 -> V_42 ) ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_24 ( L_24 , V_41 ) ;
return;
}
F_191 ( & V_100 , F_153 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_184 ( & V_100 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_154 ( V_100 . V_160 + 8 , V_7 ) )
F_224 ( V_5 , & V_100 ) ;
}
static inline int
F_228 ( struct V_4 * V_5 , struct V_6 * V_344 )
{
struct V_102 V_345 ;
if ( ! F_141 ( V_344 , & V_345 , V_83 ) ) {
F_224 ( V_5 , & V_345 ) ;
return 0 ;
}
return - 1 ;
}
static void F_229 ( struct V_4 * V_5 )
{
struct V_6 * V_344 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_346 &&
( V_344 = F_208 ( V_84 , V_5 -> V_7 -> V_346 ) ) ) {
if ( ! F_228 ( V_5 , V_344 ) )
return;
}
F_57 (net, link_dev) {
if ( ! F_228 ( V_5 , V_344 ) )
return;
}
F_24 ( L_26 ) ;
}
static void F_230 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_193 ( V_7 ) ;
if ( F_83 ( V_5 ) ) {
F_24 ( L_27 ) ;
return;
}
F_229 ( V_5 ) ;
}
static int F_231 ( struct V_347 * V_348 , unsigned long V_349 ,
void * V_123 )
{
struct V_6 * V_7 = (struct V_6 * ) V_123 ;
struct V_4 * V_5 = F_49 ( V_7 ) ;
int V_350 = 0 ;
int V_107 ;
switch ( V_349 ) {
case V_351 :
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! V_5 )
return F_232 ( - V_38 ) ;
}
break;
case V_129 :
case V_352 :
if ( V_7 -> V_57 & V_353 )
break;
if ( V_349 == V_129 ) {
if ( ! F_4 ( V_7 ) ) {
F_41 ( L_28 ,
V_7 -> V_42 ) ;
break;
}
if ( ! V_5 && V_7 -> V_46 >= V_47 )
V_5 = F_28 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_74 |= V_75 ;
V_350 = 1 ;
}
} else {
if ( ! F_4 ( V_7 ) ) {
break;
}
if ( V_5 ) {
if ( V_5 -> V_74 & V_75 )
break;
V_5 -> V_74 |= V_75 ;
}
F_41 ( L_29 ,
V_7 -> V_42 ) ;
V_350 = 1 ;
}
switch ( V_7 -> type ) {
#if F_40 ( V_61 ) || F_40 ( V_62 )
case V_63 :
F_226 ( V_7 ) ;
break;
#endif
#if F_40 ( V_354 ) || F_40 ( V_355 )
case V_241 :
F_227 ( V_7 ) ;
break;
#endif
case V_71 :
F_230 ( V_7 ) ;
break;
case V_356 :
F_223 ( V_7 ) ;
break;
default:
F_225 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_350 )
F_233 ( V_5 ) ;
if ( V_5 -> V_49 . V_51 != V_7 -> V_46 &&
V_7 -> V_46 >= V_47 ) {
F_234 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
}
V_5 -> V_76 = V_25 ;
F_235 ( V_357 , V_5 ) ;
if ( V_7 -> V_46 < V_47 )
F_216 ( V_7 , 1 ) ;
}
break;
case V_358 :
if ( V_5 && V_7 -> V_46 >= V_47 ) {
F_234 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
break;
}
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
break;
}
case V_138 :
case V_359 :
F_216 ( V_7 , V_349 != V_138 ) ;
break;
case V_360 :
if ( V_5 ) {
F_236 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_107 = F_38 ( V_5 ) ;
if ( V_107 )
return F_232 ( V_107 ) ;
}
break;
case V_361 :
case V_362 :
F_237 ( V_7 , V_349 ) ;
break;
}
return V_363 ;
}
static void F_237 ( struct V_6 * V_7 , unsigned long V_349 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_349 == V_362 )
F_238 ( V_5 ) ;
else if ( V_349 == V_361 )
F_239 ( V_5 ) ;
}
static int F_216 ( struct V_6 * V_7 , int V_364 )
{
struct V_84 * V_84 = F_32 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_95 , V_179 ;
F_29 () ;
F_240 ( V_84 , V_7 ) ;
F_241 ( & V_54 , V_7 ) ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 == NULL )
return - V_113 ;
if ( V_364 ) {
V_5 -> V_43 = 1 ;
F_242 ( V_7 -> V_77 , NULL ) ;
F_236 ( V_5 ) ;
}
for ( V_179 = 0 ; V_179 < V_365 ; V_179 ++ ) {
struct V_366 * V_367 = & V_125 [ V_179 ] ;
struct V_218 * V_368 ;
F_97 ( & V_117 ) ;
V_369:
F_143 (ifa, n, h, addr_lst) {
if ( V_82 -> V_5 == V_5 ) {
F_99 ( & V_82 -> V_94 ) ;
F_7 ( V_82 ) ;
goto V_369;
}
}
F_98 ( & V_117 ) ;
}
F_100 ( & V_5 -> V_48 ) ;
if ( ! V_364 )
V_5 -> V_74 &= ~ ( V_370 | V_371 | V_75 ) ;
#ifdef F_42
if ( V_364 && F_8 ( & V_5 -> V_68 ) )
F_65 ( V_5 ) ;
while ( ! F_22 ( & V_5 -> V_67 ) ) {
V_82 = F_243 ( & V_5 -> V_67 ,
struct V_13 , V_127 ) ;
F_101 ( & V_82 -> V_127 ) ;
F_108 ( & V_5 -> V_48 ) ;
F_97 ( & V_82 -> V_48 ) ;
if ( V_82 -> V_133 ) {
F_102 ( V_82 -> V_133 ) ;
V_82 -> V_133 = NULL ;
}
F_98 ( & V_82 -> V_48 ) ;
F_102 ( V_82 ) ;
F_100 ( & V_5 -> V_48 ) ;
}
#endif
while ( ! F_22 ( & V_5 -> V_39 ) ) {
V_82 = F_243 ( & V_5 -> V_39 ,
struct V_13 , V_101 ) ;
F_7 ( V_82 ) ;
F_101 ( & V_82 -> V_101 ) ;
F_108 ( & V_5 -> V_48 ) ;
F_97 ( & V_82 -> V_122 ) ;
V_95 = V_82 -> V_95 ;
V_82 -> V_95 = V_96 ;
F_98 ( & V_82 -> V_122 ) ;
if ( V_95 != V_96 ) {
F_244 ( V_137 , V_82 ) ;
F_95 ( & V_128 , V_138 , V_82 ) ;
}
F_102 ( V_82 ) ;
F_100 ( & V_5 -> V_48 ) ;
}
F_108 ( & V_5 -> V_48 ) ;
if ( V_364 )
F_245 ( V_5 ) ;
else
F_246 ( V_5 ) ;
V_5 -> V_76 = V_25 ;
if ( V_364 ) {
F_3 ( V_5 ) ;
F_37 ( & V_54 , V_5 -> V_53 ) ;
F_241 ( & V_54 , V_7 ) ;
F_65 ( V_5 ) ;
}
return 0 ;
}
static void V_23 ( unsigned long V_123 )
{
struct V_13 * V_14 = (struct V_13 * ) V_123 ;
struct V_4 * V_5 = V_14 -> V_5 ;
F_247 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_74 & V_75 ) )
goto V_119;
if ( V_5 -> V_49 . V_55 )
goto V_119;
if ( V_5 -> V_74 & V_371 )
goto V_119;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_372 ++ < V_5 -> V_49 . V_66 ) {
F_10 ( V_14 , V_22 ,
( V_14 -> V_372 == V_5 -> V_49 . V_66 ) ?
V_5 -> V_49 . V_373 :
V_5 -> V_49 . V_374 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_248 ( V_5 -> V_7 , & V_14 -> V_100 , & V_80 ) ;
} else {
F_89 ( & V_14 -> V_48 ) ;
F_24 ( L_30 , V_5 -> V_7 -> V_42 ) ;
}
V_119:
F_249 ( & V_5 -> V_48 ) ;
F_102 ( V_14 ) ;
}
static void F_250 ( struct V_13 * V_14 )
{
unsigned long V_375 ;
struct V_4 * V_5 = V_14 -> V_5 ;
if ( V_14 -> V_57 & V_172 )
V_375 = 0 ;
else
V_375 = F_251 () % ( V_5 -> V_49 . V_373 ? : 1 ) ;
V_14 -> V_372 = V_5 -> V_49 . V_170 ;
F_10 ( V_14 , V_19 , V_375 ) ;
}
static void F_119 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_155 ( V_7 , & V_14 -> V_100 ) ;
F_252 ( V_14 -> V_100 . V_227 [ 3 ] ) ;
F_134 ( & V_5 -> V_48 ) ;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_95 == V_96 )
goto V_119;
if ( V_7 -> V_57 & ( V_58 | V_59 ) ||
V_5 -> V_49 . V_60 < 1 ||
! ( V_14 -> V_57 & V_83 ) ||
V_14 -> V_57 & V_376 ) {
V_14 -> V_57 &= ~ ( V_83 | V_172 | V_223 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_139 ( & V_5 -> V_48 ) ;
F_253 ( V_14 ) ;
return;
}
if ( ! ( V_5 -> V_74 & V_75 ) ) {
F_89 ( & V_14 -> V_48 ) ;
F_139 ( & V_5 -> V_48 ) ;
F_11 ( V_14 ) ;
F_149 ( V_14 , 0 ) ;
return;
}
if ( V_14 -> V_57 & V_172 )
F_254 ( V_14 -> V_9 ) ;
F_250 ( V_14 ) ;
V_119:
F_89 ( & V_14 -> V_48 ) ;
F_139 ( & V_5 -> V_48 ) ;
}
static void V_21 ( unsigned long V_123 )
{
struct V_13 * V_14 = (struct V_13 * ) V_123 ;
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_102 V_377 ;
if ( ! V_14 -> V_372 && F_150 ( V_14 ) )
goto V_119;
F_247 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_74 & V_75 ) ) {
F_249 ( & V_5 -> V_48 ) ;
goto V_119;
}
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_95 == V_96 ) {
F_89 ( & V_14 -> V_48 ) ;
F_249 ( & V_5 -> V_48 ) ;
goto V_119;
}
if ( V_14 -> V_372 == 0 ) {
V_14 -> V_57 &= ~ ( V_83 | V_172 | V_223 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_249 ( & V_5 -> V_48 ) ;
F_253 ( V_14 ) ;
goto V_119;
}
V_14 -> V_372 -- ;
F_10 ( V_14 , V_19 , V_14 -> V_5 -> V_53 -> V_171 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_249 ( & V_5 -> V_48 ) ;
F_156 ( & V_14 -> V_100 , & V_377 ) ;
F_255 ( V_14 -> V_5 -> V_7 , NULL , & V_14 -> V_100 , & V_377 , & V_378 ) ;
V_119:
F_102 ( V_14 ) ;
}
static void F_253 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = V_14 -> V_5 -> V_7 ;
F_109 ( V_332 , V_14 ) ;
if ( ( ( V_14 -> V_5 -> V_49 . V_379 == 1 && ! V_14 -> V_5 -> V_49 . V_55 ) ||
V_14 -> V_5 -> V_49 . V_379 == 2 ) &&
V_14 -> V_5 -> V_49 . V_66 > 0 &&
( V_7 -> V_57 & V_59 ) == 0 &&
( F_77 ( & V_14 -> V_100 ) & V_280 ) ) {
F_248 ( V_14 -> V_5 -> V_7 , & V_14 -> V_100 , & V_80 ) ;
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_372 = 1 ;
V_14 -> V_5 -> V_74 |= V_370 ;
F_10 ( V_14 , V_22 , V_14 -> V_5 -> V_49 . V_374 ) ;
F_98 ( & V_14 -> V_48 ) ;
}
}
static void F_233 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_57 & V_83 &&
V_14 -> V_95 == V_225 )
F_250 ( V_14 ) ;
F_89 ( & V_14 -> V_48 ) ;
}
F_139 ( & V_5 -> V_48 ) ;
}
static struct V_13 * F_256 ( struct V_380 * V_381 , T_9 V_382 )
{
struct V_13 * V_82 = NULL ;
struct V_383 * V_95 = V_381 -> V_384 ;
struct V_84 * V_84 = F_257 ( V_381 ) ;
int V_89 = 0 ;
if ( V_382 == 0 ) {
V_95 -> V_385 = 0 ;
V_95 -> V_386 = 0 ;
}
for (; V_95 -> V_385 < V_365 ; ++ V_95 -> V_385 ) {
struct V_218 * V_368 ;
F_148 (ifa, n, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_144 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( V_89 < V_95 -> V_386 ) {
V_89 ++ ;
continue;
}
V_95 -> V_386 ++ ;
return V_82 ;
}
V_95 -> V_386 = 0 ;
V_89 = 0 ;
}
return NULL ;
}
static struct V_13 * F_258 ( struct V_380 * V_381 ,
struct V_13 * V_82 )
{
struct V_383 * V_95 = V_381 -> V_384 ;
struct V_84 * V_84 = F_257 ( V_381 ) ;
struct V_218 * V_368 = & V_82 -> V_94 ;
F_259 (ifa, n, addr_lst) {
if ( ! F_144 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_84 ) )
continue;
V_95 -> V_386 ++ ;
return V_82 ;
}
while ( ++ V_95 -> V_385 < V_365 ) {
V_95 -> V_386 = 0 ;
F_148 (ifa, n,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_144 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_84 ) )
continue;
V_95 -> V_386 ++ ;
return V_82 ;
}
}
return NULL ;
}
static void * F_260 ( struct V_380 * V_381 , T_9 * V_382 )
__acquires( T_10 )
{
F_79 () ;
return F_256 ( V_381 , * V_382 ) ;
}
static void * F_261 ( struct V_380 * V_381 , void * V_387 , T_9 * V_382 )
{
struct V_13 * V_82 ;
V_82 = F_258 ( V_381 , V_387 ) ;
++ * V_382 ;
return V_82 ;
}
static void F_262 ( struct V_380 * V_381 , void * V_387 )
__releases( T_10 )
{
F_93 () ;
}
static int F_263 ( struct V_380 * V_381 , void * V_387 )
{
struct V_13 * V_14 = (struct V_13 * ) V_387 ;
F_264 ( V_381 , L_31 ,
& V_14 -> V_100 ,
V_14 -> V_5 -> V_7 -> V_143 ,
V_14 -> V_124 ,
V_14 -> V_105 ,
V_14 -> V_57 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
return 0 ;
}
static int F_265 ( struct V_388 * V_388 , struct V_389 * V_389 )
{
return F_266 ( V_388 , V_389 , & V_390 ,
sizeof( struct V_383 ) ) ;
}
static int T_11 F_267 ( struct V_84 * V_84 )
{
if ( ! F_268 ( V_84 , L_32 , V_391 , & V_392 ) )
return - V_38 ;
return 0 ;
}
static void T_12 F_269 ( struct V_84 * V_84 )
{
F_270 ( V_84 , L_32 ) ;
}
int T_13 F_271 ( void )
{
return F_272 ( & V_393 ) ;
}
void F_273 ( void )
{
F_274 ( & V_393 ) ;
}
int F_275 ( struct V_84 * V_84 , const struct V_102 * V_100 )
{
int V_156 = 0 ;
struct V_13 * V_14 = NULL ;
struct V_218 * V_368 ;
unsigned int V_106 = F_73 ( V_100 ) ;
F_79 () ;
F_148 (ifp, n, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_144 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_123 ( & V_14 -> V_100 , V_100 ) &&
( V_14 -> V_57 & V_194 ) ) {
V_156 = 1 ;
break;
}
}
F_93 () ;
return V_156 ;
}
static void F_203 ( unsigned long V_394 )
{
unsigned long V_159 , V_395 , V_396 , V_397 ;
struct V_13 * V_14 ;
struct V_218 * V_219 ;
int V_179 ;
F_79 () ;
F_80 ( & V_398 ) ;
V_159 = V_25 ;
V_395 = F_276 ( V_159 + V_399 ) ;
F_8 ( & V_400 ) ;
for ( V_179 = 0 ; V_179 < V_365 ; V_179 ++ ) {
V_369:
F_148 (ifp, node,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_153 ;
if ( V_14 -> V_57 & V_134 )
continue;
F_80 ( & V_14 -> V_48 ) ;
V_153 = ( V_159 - V_14 -> V_76 + V_401 ) / V_3 ;
if ( V_14 -> V_136 != V_331 &&
V_153 >= V_14 -> V_136 ) {
F_89 ( & V_14 -> V_48 ) ;
F_11 ( V_14 ) ;
F_96 ( V_14 ) ;
goto V_369;
} else if ( V_14 -> V_167 == V_331 ) {
F_89 ( & V_14 -> V_48 ) ;
continue;
} else if ( V_153 >= V_14 -> V_167 ) {
int V_402 = 0 ;
if ( ! ( V_14 -> V_57 & V_189 ) ) {
V_402 = 1 ;
V_14 -> V_57 |= V_189 ;
}
if ( F_107 ( V_14 -> V_76 + V_14 -> V_136 * V_3 , V_395 ) )
V_395 = V_14 -> V_76 + V_14 -> V_136 * V_3 ;
F_89 ( & V_14 -> V_48 ) ;
if ( V_402 ) {
F_11 ( V_14 ) ;
F_109 ( 0 , V_14 ) ;
F_102 ( V_14 ) ;
goto V_369;
}
#ifdef F_42
} else if ( ( V_14 -> V_57 & V_126 ) &&
! ( V_14 -> V_57 & V_83 ) ) {
unsigned long V_154 = V_14 -> V_5 -> V_49 . V_163 *
V_14 -> V_5 -> V_49 . V_170 *
V_14 -> V_5 -> V_53 -> V_171 / V_3 ;
if ( V_153 >= V_14 -> V_167 - V_154 ) {
struct V_13 * V_133 = V_14 -> V_133 ;
if ( F_107 ( V_14 -> V_76 + V_14 -> V_167 * V_3 , V_395 ) )
V_395 = V_14 -> V_76 + V_14 -> V_167 * V_3 ;
if ( ! V_14 -> V_162 && V_133 ) {
V_14 -> V_162 ++ ;
F_11 ( V_14 ) ;
F_11 ( V_133 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_80 ( & V_133 -> V_48 ) ;
V_133 -> V_162 = 0 ;
F_89 ( & V_133 -> V_48 ) ;
F_115 ( V_133 , V_14 ) ;
F_102 ( V_133 ) ;
F_102 ( V_14 ) ;
goto V_369;
}
} else if ( F_107 ( V_14 -> V_76 + V_14 -> V_167 * V_3 - V_154 * V_3 , V_395 ) )
V_395 = V_14 -> V_76 + V_14 -> V_167 * V_3 - V_154 * V_3 ;
F_89 ( & V_14 -> V_48 ) ;
#endif
} else {
if ( F_107 ( V_14 -> V_76 + V_14 -> V_167 * V_3 , V_395 ) )
V_395 = V_14 -> V_76 + V_14 -> V_167 * V_3 ;
F_89 ( & V_14 -> V_48 ) ;
}
}
}
V_396 = F_276 ( V_395 ) ;
V_397 = V_395 ;
if ( F_107 ( V_396 , V_395 + V_403 ) )
V_397 = V_396 ;
if ( F_107 ( V_397 , V_25 + V_404 ) )
V_397 = V_25 + V_404 ;
F_36 ( ( V_209 L_33 ,
V_159 , V_395 , V_396 , V_397 ) ) ;
V_400 . V_24 = V_397 ;
F_12 ( & V_400 ) ;
F_89 ( & V_398 ) ;
F_93 () ;
}
static struct V_102 * F_277 ( struct V_405 * V_100 , struct V_405 * V_406 )
{
struct V_102 * V_244 = NULL ;
if ( V_100 )
V_244 = F_278 ( V_100 ) ;
if ( V_406 ) {
if ( V_244 && F_279 ( V_406 , V_244 , sizeof( * V_244 ) ) )
V_244 = NULL ;
else
V_244 = F_278 ( V_406 ) ;
}
return V_244 ;
}
static int
F_280 ( struct V_407 * V_408 , struct V_409 * V_410 , void * V_297 )
{
struct V_84 * V_84 = F_281 ( V_408 -> V_411 ) ;
struct V_412 * V_413 ;
struct V_405 * V_414 [ V_415 + 1 ] ;
struct V_102 * V_244 ;
int V_107 ;
V_107 = F_282 ( V_410 , sizeof( * V_413 ) , V_414 , V_415 , V_416 ) ;
if ( V_107 < 0 )
return V_107 ;
V_413 = F_283 ( V_410 ) ;
V_244 = F_277 ( V_414 [ V_417 ] , V_414 [ V_418 ] ) ;
if ( V_244 == NULL )
return - V_300 ;
return F_215 ( V_84 , V_413 -> V_419 , V_244 , V_413 -> V_420 ) ;
}
static int F_284 ( struct V_13 * V_14 , T_3 V_325 ,
T_1 V_167 , T_1 V_136 )
{
T_1 V_57 ;
T_5 V_24 ;
unsigned long V_326 ;
if ( ! V_136 || ( V_167 > V_136 ) )
return - V_300 ;
V_326 = F_106 ( V_136 , V_3 ) ;
if ( F_199 ( V_326 ) ) {
V_24 = F_201 ( V_326 * V_3 ) ;
V_136 = V_326 ;
V_57 = V_147 ;
} else {
V_24 = 0 ;
V_57 = 0 ;
V_325 |= V_134 ;
}
V_326 = F_106 ( V_167 , V_3 ) ;
if ( F_199 ( V_326 ) ) {
if ( V_326 == 0 )
V_325 |= V_189 ;
V_167 = V_326 ;
}
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_57 = ( V_14 -> V_57 & ~ ( V_189 | V_134 | V_376 | V_194 ) ) | V_325 ;
V_14 -> V_76 = V_25 ;
V_14 -> V_136 = V_136 ;
V_14 -> V_167 = V_167 ;
F_98 ( & V_14 -> V_48 ) ;
if ( ! ( V_14 -> V_57 & V_83 ) )
F_109 ( 0 , V_14 ) ;
F_184 ( & V_14 -> V_100 , V_14 -> V_124 , V_14 -> V_5 -> V_7 ,
V_24 , V_57 ) ;
F_203 ( 0 ) ;
return 0 ;
}
static int
F_285 ( struct V_407 * V_408 , struct V_409 * V_410 , void * V_297 )
{
struct V_84 * V_84 = F_281 ( V_408 -> V_411 ) ;
struct V_412 * V_413 ;
struct V_405 * V_414 [ V_415 + 1 ] ;
struct V_102 * V_244 ;
struct V_13 * V_82 ;
struct V_6 * V_7 ;
T_1 V_136 = V_331 , V_421 = V_331 ;
T_3 V_325 ;
int V_107 ;
V_107 = F_282 ( V_410 , sizeof( * V_413 ) , V_414 , V_415 , V_416 ) ;
if ( V_107 < 0 )
return V_107 ;
V_413 = F_283 ( V_410 ) ;
V_244 = F_277 ( V_414 [ V_417 ] , V_414 [ V_418 ] ) ;
if ( V_244 == NULL )
return - V_300 ;
if ( V_414 [ V_422 ] ) {
struct V_423 * V_424 ;
V_424 = F_278 ( V_414 [ V_422 ] ) ;
V_136 = V_424 -> V_425 ;
V_421 = V_424 -> V_426 ;
} else {
V_421 = V_331 ;
V_136 = V_331 ;
}
V_7 = F_208 ( V_84 , V_413 -> V_419 ) ;
if ( V_7 == NULL )
return - V_113 ;
V_325 = V_413 -> V_325 & ( V_376 | V_194 ) ;
V_82 = F_147 ( V_84 , V_244 , V_7 , 1 ) ;
if ( V_82 == NULL ) {
return F_213 ( V_84 , V_413 -> V_419 , V_244 ,
V_413 -> V_420 , V_325 ,
V_421 , V_136 ) ;
}
if ( V_410 -> V_427 & V_428 ||
! ( V_410 -> V_427 & V_429 ) )
V_107 = - V_118 ;
else
V_107 = F_284 ( V_82 , V_325 , V_421 , V_136 ) ;
F_102 ( V_82 ) ;
return V_107 ;
}
static void F_286 ( struct V_409 * V_410 , T_3 V_430 , T_3 V_57 ,
T_3 V_105 , int V_143 )
{
struct V_412 * V_413 ;
V_413 = F_283 ( V_410 ) ;
V_413 -> V_431 = V_432 ;
V_413 -> V_420 = V_430 ;
V_413 -> V_325 = V_57 ;
V_413 -> V_340 = V_105 ;
V_413 -> V_419 = V_143 ;
}
static int F_287 ( struct V_407 * V_408 , unsigned long V_1 ,
unsigned long V_76 , T_1 V_433 , T_1 V_281 )
{
struct V_423 V_424 ;
V_424 . V_1 = F_1 ( V_1 ) ;
V_424 . V_76 = F_1 ( V_76 ) ;
V_424 . V_426 = V_433 ;
V_424 . V_425 = V_281 ;
return F_288 ( V_408 , V_422 , sizeof( V_424 ) , & V_424 ) ;
}
static inline int F_289 ( int V_340 )
{
if ( V_340 & V_220 )
return V_342 ;
else if ( V_340 & V_215 )
return V_341 ;
else if ( V_340 & V_434 )
return V_435 ;
else
return V_436 ;
}
static inline int F_290 ( void )
{
return F_291 ( sizeof( struct V_412 ) )
+ F_292 ( 16 )
+ F_292 ( sizeof( struct V_423 ) ) ;
}
static int F_293 ( struct V_407 * V_408 , struct V_13 * V_82 ,
T_1 V_437 , T_1 V_381 , int V_349 , unsigned int V_57 )
{
struct V_409 * V_410 ;
T_1 V_433 , V_281 ;
V_410 = F_294 ( V_408 , V_437 , V_381 , V_349 , sizeof( struct V_412 ) , V_57 ) ;
if ( V_410 == NULL )
return - V_438 ;
F_286 ( V_410 , V_82 -> V_124 , V_82 -> V_57 , F_289 ( V_82 -> V_105 ) ,
V_82 -> V_5 -> V_7 -> V_143 ) ;
if ( ! ( V_82 -> V_57 & V_134 ) ) {
V_433 = V_82 -> V_167 ;
V_281 = V_82 -> V_136 ;
if ( V_433 != V_331 ) {
long V_439 = ( V_25 - V_82 -> V_76 ) / V_3 ;
if ( V_433 > V_439 )
V_433 -= V_439 ;
else
V_433 = 0 ;
if ( V_281 != V_331 ) {
if ( V_281 > V_439 )
V_281 -= V_439 ;
else
V_281 = 0 ;
}
}
} else {
V_433 = V_331 ;
V_281 = V_331 ;
}
if ( F_288 ( V_408 , V_417 , 16 , & V_82 -> V_100 ) < 0 ||
F_287 ( V_408 , V_82 -> V_1 , V_82 -> V_76 , V_433 , V_281 ) < 0 ) {
F_295 ( V_408 , V_410 ) ;
return - V_438 ;
}
return F_296 ( V_408 , V_410 ) ;
}
static int F_297 ( struct V_407 * V_408 , struct V_440 * V_441 ,
T_1 V_437 , T_1 V_381 , int V_349 , T_14 V_57 )
{
struct V_409 * V_410 ;
T_3 V_105 = V_436 ;
int V_143 = V_441 -> V_5 -> V_7 -> V_143 ;
if ( F_214 ( & V_441 -> V_442 ) & V_434 )
V_105 = V_435 ;
V_410 = F_294 ( V_408 , V_437 , V_381 , V_349 , sizeof( struct V_412 ) , V_57 ) ;
if ( V_410 == NULL )
return - V_438 ;
F_286 ( V_410 , 128 , V_134 , V_105 , V_143 ) ;
if ( F_288 ( V_408 , V_443 , 16 , & V_441 -> V_442 ) < 0 ||
F_287 ( V_408 , V_441 -> V_444 , V_441 -> V_445 ,
V_331 , V_331 ) < 0 ) {
F_295 ( V_408 , V_410 ) ;
return - V_438 ;
}
return F_296 ( V_408 , V_410 ) ;
}
static int F_298 ( struct V_407 * V_408 , struct V_446 * V_447 ,
T_1 V_437 , T_1 V_381 , int V_349 , unsigned int V_57 )
{
struct V_409 * V_410 ;
T_3 V_105 = V_436 ;
int V_143 = V_447 -> V_448 -> V_7 -> V_143 ;
if ( F_214 ( & V_447 -> V_449 ) & V_434 )
V_105 = V_435 ;
V_410 = F_294 ( V_408 , V_437 , V_381 , V_349 , sizeof( struct V_412 ) , V_57 ) ;
if ( V_410 == NULL )
return - V_438 ;
F_286 ( V_410 , 128 , V_134 , V_105 , V_143 ) ;
if ( F_288 ( V_408 , V_450 , 16 , & V_447 -> V_449 ) < 0 ||
F_287 ( V_408 , V_447 -> V_451 , V_447 -> V_452 ,
V_331 , V_331 ) < 0 ) {
F_295 ( V_408 , V_410 ) ;
return - V_438 ;
}
return F_296 ( V_408 , V_410 ) ;
}
static int F_299 ( struct V_4 * V_5 , struct V_407 * V_408 ,
struct V_453 * V_454 , enum V_455 type ,
int V_456 , int * V_457 )
{
struct V_440 * V_441 ;
struct V_446 * V_447 ;
int V_107 = 1 ;
int V_458 = * V_457 ;
F_134 ( & V_5 -> V_48 ) ;
switch ( type ) {
case V_459 : {
struct V_13 * V_82 ;
F_53 (ifa, &idev->addr_list, if_list) {
if ( ++ V_458 < V_456 )
continue;
V_107 = F_293 ( V_408 , V_82 ,
F_300 ( V_454 -> V_408 ) . V_437 ,
V_454 -> V_410 -> V_460 ,
V_332 ,
V_461 ) ;
if ( V_107 <= 0 )
break;
}
break;
}
case V_462 :
for ( V_441 = V_5 -> V_40 ; V_441 ;
V_441 = V_441 -> V_395 , V_458 ++ ) {
if ( V_458 < V_456 )
continue;
V_107 = F_297 ( V_408 , V_441 ,
F_300 ( V_454 -> V_408 ) . V_437 ,
V_454 -> V_410 -> V_460 ,
V_463 ,
V_461 ) ;
if ( V_107 <= 0 )
break;
}
break;
case V_464 :
for ( V_447 = V_5 -> V_465 ; V_447 ;
V_447 = V_447 -> V_466 , V_458 ++ ) {
if ( V_458 < V_456 )
continue;
V_107 = F_298 ( V_408 , V_447 ,
F_300 ( V_454 -> V_408 ) . V_437 ,
V_454 -> V_410 -> V_460 ,
V_467 ,
V_461 ) ;
if ( V_107 <= 0 )
break;
}
break;
default:
break;
}
F_139 ( & V_5 -> V_48 ) ;
* V_457 = V_458 ;
return V_107 ;
}
static int F_301 ( struct V_407 * V_408 , struct V_453 * V_454 ,
enum V_455 type )
{
struct V_84 * V_84 = F_281 ( V_408 -> V_411 ) ;
int V_367 , V_468 ;
int V_469 , V_458 ;
int V_470 , V_456 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_366 * V_471 ;
struct V_218 * V_219 ;
V_468 = V_454 -> args [ 0 ] ;
V_470 = V_469 = V_454 -> args [ 1 ] ;
V_456 = V_458 = V_454 -> args [ 2 ] ;
F_132 () ;
for ( V_367 = V_468 ; V_367 < V_472 ; V_367 ++ , V_470 = 0 ) {
V_469 = 0 ;
V_471 = & V_84 -> V_473 [ V_367 ] ;
F_143 (dev, node, head, index_hlist) {
if ( V_469 < V_470 )
goto V_474;
if ( V_367 > V_468 || V_469 > V_470 )
V_456 = 0 ;
V_458 = 0 ;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
goto V_474;
if ( F_299 ( V_5 , V_408 , V_454 , type ,
V_456 , & V_458 ) <= 0 )
goto V_475;
V_474:
V_469 ++ ;
}
}
V_475:
F_140 () ;
V_454 -> args [ 0 ] = V_367 ;
V_454 -> args [ 1 ] = V_469 ;
V_454 -> args [ 2 ] = V_458 ;
return V_408 -> V_275 ;
}
static int F_302 ( struct V_407 * V_408 , struct V_453 * V_454 )
{
enum V_455 type = V_459 ;
return F_301 ( V_408 , V_454 , type ) ;
}
static int F_303 ( struct V_407 * V_408 , struct V_453 * V_454 )
{
enum V_455 type = V_462 ;
return F_301 ( V_408 , V_454 , type ) ;
}
static int F_304 ( struct V_407 * V_408 , struct V_453 * V_454 )
{
enum V_455 type = V_464 ;
return F_301 ( V_408 , V_454 , type ) ;
}
static int F_305 ( struct V_407 * V_476 , struct V_409 * V_410 ,
void * V_297 )
{
struct V_84 * V_84 = F_281 ( V_476 -> V_411 ) ;
struct V_412 * V_413 ;
struct V_405 * V_414 [ V_415 + 1 ] ;
struct V_102 * V_100 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_13 * V_82 ;
struct V_407 * V_408 ;
int V_107 ;
V_107 = F_282 ( V_410 , sizeof( * V_413 ) , V_414 , V_415 , V_416 ) ;
if ( V_107 < 0 )
goto V_477;
V_100 = F_277 ( V_414 [ V_417 ] , V_414 [ V_418 ] ) ;
if ( V_100 == NULL ) {
V_107 = - V_300 ;
goto V_477;
}
V_413 = F_283 ( V_410 ) ;
if ( V_413 -> V_419 )
V_7 = F_208 ( V_84 , V_413 -> V_419 ) ;
V_82 = F_147 ( V_84 , V_100 , V_7 , 1 ) ;
if ( ! V_82 ) {
V_107 = - V_112 ;
goto V_477;
}
V_408 = F_306 ( F_290 () , V_33 ) ;
if ( ! V_408 ) {
V_107 = - V_121 ;
goto V_478;
}
V_107 = F_293 ( V_408 , V_82 , F_300 ( V_476 ) . V_437 ,
V_410 -> V_460 , V_332 , 0 ) ;
if ( V_107 < 0 ) {
F_21 ( V_107 == - V_438 ) ;
F_307 ( V_408 ) ;
goto V_478;
}
V_107 = F_308 ( V_408 , V_84 , F_300 ( V_476 ) . V_437 ) ;
V_478:
F_102 ( V_82 ) ;
V_477:
return V_107 ;
}
static void F_309 ( int V_349 , struct V_13 * V_82 )
{
struct V_407 * V_408 ;
struct V_84 * V_84 = F_32 ( V_82 -> V_5 -> V_7 ) ;
int V_107 = - V_121 ;
V_408 = F_306 ( F_290 () , V_120 ) ;
if ( V_408 == NULL )
goto V_477;
V_107 = F_293 ( V_408 , V_82 , 0 , 0 , V_349 , 0 ) ;
if ( V_107 < 0 ) {
F_21 ( V_107 == - V_438 ) ;
F_307 ( V_408 ) ;
goto V_477;
}
F_310 ( V_408 , V_84 , 0 , V_479 , NULL , V_120 ) ;
return;
V_477:
if ( V_107 < 0 )
F_311 ( V_84 , V_479 , V_107 ) ;
}
static inline void F_312 ( struct V_480 * V_49 ,
T_2 * V_481 , int V_482 )
{
F_313 ( V_482 < ( V_483 * 4 ) ) ;
memset ( V_481 , 0 , V_482 ) ;
V_481 [ V_484 ] = V_49 -> V_55 ;
V_481 [ V_485 ] = V_49 -> V_486 ;
V_481 [ V_487 ] = V_49 -> V_51 ;
V_481 [ V_488 ] = V_49 -> V_379 ;
V_481 [ V_489 ] = V_49 -> V_490 ;
V_481 [ V_491 ] = V_49 -> V_287 ;
V_481 [ V_492 ] = V_49 -> V_170 ;
V_481 [ V_493 ] = V_49 -> V_66 ;
V_481 [ V_494 ] =
F_314 ( V_49 -> V_374 ) ;
V_481 [ V_495 ] =
F_314 ( V_49 -> V_373 ) ;
V_481 [ V_496 ] = V_49 -> V_497 ;
#ifdef F_42
V_481 [ V_498 ] = V_49 -> V_73 ;
V_481 [ V_499 ] = V_49 -> V_166 ;
V_481 [ V_500 ] = V_49 -> V_168 ;
V_481 [ V_501 ] = V_49 -> V_163 ;
V_481 [ V_502 ] = V_49 -> V_169 ;
#endif
V_481 [ V_503 ] = V_49 -> V_157 ;
V_481 [ V_504 ] = V_49 -> V_505 ;
V_481 [ V_506 ] = V_49 -> V_507 ;
#ifdef F_315
V_481 [ V_508 ] = V_49 -> V_509 ;
V_481 [ V_510 ] =
F_314 ( V_49 -> V_511 ) ;
#ifdef F_316
V_481 [ V_512 ] = V_49 -> V_513 ;
#endif
#endif
V_481 [ V_514 ] = V_49 -> V_515 ;
V_481 [ V_516 ] = V_49 -> V_517 ;
#ifdef F_202
V_481 [ V_518 ] = V_49 -> V_291 ;
#endif
#ifdef F_317
V_481 [ V_519 ] = V_49 -> V_520 ;
#endif
V_481 [ V_521 ] = V_49 -> V_115 ;
V_481 [ V_522 ] = V_49 -> V_60 ;
V_481 [ V_523 ] = V_49 -> V_524 ;
}
static inline T_15 F_318 ( void )
{
return F_292 ( 4 )
+ F_292 ( sizeof( struct V_525 ) )
+ F_292 ( V_483 * 4 )
+ F_292 ( V_526 * 8 )
+ F_292 ( V_527 * 8 ) ;
}
static inline T_15 F_319 ( void )
{
return F_291 ( sizeof( struct V_528 ) )
+ F_292 ( V_529 )
+ F_292 ( V_530 )
+ F_292 ( 4 )
+ F_292 ( 4 )
+ F_292 ( F_318 () ) ;
}
static inline void F_320 ( T_16 * V_27 , T_17 * V_531 ,
int V_532 , int V_482 )
{
int V_179 ;
int V_533 = V_482 - sizeof( T_16 ) * V_532 ;
F_313 ( V_533 < 0 ) ;
F_321 ( V_532 , & V_27 [ 0 ] ) ;
for ( V_179 = 1 ; V_179 < V_532 ; V_179 ++ )
F_321 ( F_322 ( & V_531 [ V_179 ] ) , & V_27 [ V_179 ] ) ;
memset ( & V_27 [ V_532 ] , 0 , V_533 ) ;
}
static inline void F_323 ( T_16 * V_27 , void V_26 * * V_531 ,
int V_532 , int V_482 , T_15 V_534 )
{
int V_179 ;
int V_533 = V_482 - sizeof( T_16 ) * V_532 ;
F_313 ( V_533 < 0 ) ;
F_321 ( V_532 , & V_27 [ 0 ] ) ;
for ( V_179 = 1 ; V_179 < V_532 ; V_179 ++ )
F_321 ( F_324 ( V_531 , V_179 , V_534 ) , & V_27 [ V_179 ] ) ;
memset ( & V_27 [ V_532 ] , 0 , V_533 ) ;
}
static void F_325 ( T_16 * V_27 , struct V_4 * V_5 , int V_535 ,
int V_482 )
{
switch ( V_535 ) {
case V_536 :
F_323 ( V_27 , ( void V_26 * * ) V_5 -> V_27 . V_28 ,
V_526 , V_482 , F_326 ( struct V_29 , V_537 ) ) ;
break;
case V_538 :
F_320 ( V_27 , V_5 -> V_27 . V_31 -> V_539 , V_527 , V_482 ) ;
break;
}
}
static int F_327 ( struct V_407 * V_408 , struct V_4 * V_5 )
{
struct V_405 * V_540 ;
struct V_525 V_424 ;
if ( F_328 ( V_408 , V_541 , V_5 -> V_74 ) )
goto V_542;
V_424 . V_543 = V_544 ;
V_424 . V_76 = F_1 ( V_5 -> V_76 ) ;
V_424 . V_545 = F_314 ( V_5 -> V_53 -> V_545 ) ;
V_424 . V_171 = F_314 ( V_5 -> V_53 -> V_171 ) ;
if ( F_288 ( V_408 , V_546 , sizeof( V_424 ) , & V_424 ) )
goto V_542;
V_540 = F_329 ( V_408 , V_547 , V_483 * sizeof( V_548 ) ) ;
if ( V_540 == NULL )
goto V_542;
F_312 ( & V_5 -> V_49 , F_278 ( V_540 ) , F_330 ( V_540 ) ) ;
V_540 = F_329 ( V_408 , V_536 , V_526 * sizeof( T_16 ) ) ;
if ( V_540 == NULL )
goto V_542;
F_325 ( F_278 ( V_540 ) , V_5 , V_536 , F_330 ( V_540 ) ) ;
V_540 = F_329 ( V_408 , V_538 , V_527 * sizeof( T_16 ) ) ;
if ( V_540 == NULL )
goto V_542;
F_325 ( F_278 ( V_540 ) , V_5 , V_538 , F_330 ( V_540 ) ) ;
return 0 ;
V_542:
return - V_438 ;
}
static T_15 F_331 ( const struct V_6 * V_7 )
{
if ( ! F_49 ( V_7 ) )
return 0 ;
return F_318 () ;
}
static int F_332 ( struct V_407 * V_408 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
return - V_549 ;
if ( F_327 ( V_408 , V_5 ) < 0 )
return - V_438 ;
return 0 ;
}
static int F_333 ( struct V_407 * V_408 , struct V_4 * V_5 ,
T_1 V_437 , T_1 V_381 , int V_349 , unsigned int V_57 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_528 * V_550 ;
struct V_409 * V_410 ;
void * V_551 ;
V_410 = F_294 ( V_408 , V_437 , V_381 , V_349 , sizeof( * V_550 ) , V_57 ) ;
if ( V_410 == NULL )
return - V_438 ;
V_550 = F_283 ( V_410 ) ;
V_550 -> V_552 = V_432 ;
V_550 -> V_553 = 0 ;
V_550 -> V_554 = V_7 -> type ;
V_550 -> V_555 = V_7 -> V_143 ;
V_550 -> V_556 = F_334 ( V_7 ) ;
V_550 -> V_557 = 0 ;
if ( F_335 ( V_408 , V_558 , V_7 -> V_42 ) ||
( V_7 -> V_230 &&
F_288 ( V_408 , V_559 , V_7 -> V_230 , V_7 -> V_232 ) ) ||
F_328 ( V_408 , V_560 , V_7 -> V_46 ) ||
( V_7 -> V_143 != V_7 -> V_346 &&
F_328 ( V_408 , V_561 , V_7 -> V_346 ) ) )
goto V_542;
V_551 = F_336 ( V_408 , V_562 ) ;
if ( V_551 == NULL )
goto V_542;
if ( F_327 ( V_408 , V_5 ) < 0 )
goto V_542;
F_337 ( V_408 , V_551 ) ;
return F_296 ( V_408 , V_410 ) ;
V_542:
F_295 ( V_408 , V_410 ) ;
return - V_438 ;
}
static int F_338 ( struct V_407 * V_408 , struct V_453 * V_454 )
{
struct V_84 * V_84 = F_281 ( V_408 -> V_411 ) ;
int V_367 , V_468 ;
int V_469 = 0 , V_470 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_366 * V_471 ;
struct V_218 * V_219 ;
V_468 = V_454 -> args [ 0 ] ;
V_470 = V_454 -> args [ 1 ] ;
F_132 () ;
for ( V_367 = V_468 ; V_367 < V_472 ; V_367 ++ , V_470 = 0 ) {
V_469 = 0 ;
V_471 = & V_84 -> V_473 [ V_367 ] ;
F_143 (dev, node, head, index_hlist) {
if ( V_469 < V_470 )
goto V_474;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
goto V_474;
if ( F_333 ( V_408 , V_5 ,
F_300 ( V_454 -> V_408 ) . V_437 ,
V_454 -> V_410 -> V_460 ,
V_357 , V_461 ) <= 0 )
goto V_119;
V_474:
V_469 ++ ;
}
}
V_119:
F_140 () ;
V_454 -> args [ 1 ] = V_469 ;
V_454 -> args [ 0 ] = V_367 ;
return V_408 -> V_275 ;
}
void F_235 ( int V_349 , struct V_4 * V_5 )
{
struct V_407 * V_408 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
int V_107 = - V_121 ;
V_408 = F_306 ( F_319 () , V_120 ) ;
if ( V_408 == NULL )
goto V_477;
V_107 = F_333 ( V_408 , V_5 , 0 , 0 , V_349 , 0 ) ;
if ( V_107 < 0 ) {
F_21 ( V_107 == - V_438 ) ;
F_307 ( V_408 ) ;
goto V_477;
}
F_310 ( V_408 , V_84 , 0 , V_563 , NULL , V_120 ) ;
return;
V_477:
if ( V_107 < 0 )
F_311 ( V_84 , V_563 , V_107 ) ;
}
static inline T_15 F_339 ( void )
{
return F_291 ( sizeof( struct V_564 ) )
+ F_292 ( sizeof( struct V_102 ) )
+ F_292 ( sizeof( struct V_565 ) ) ;
}
static int F_340 ( struct V_407 * V_408 , struct V_4 * V_5 ,
struct V_277 * V_278 , T_1 V_437 , T_1 V_381 ,
int V_349 , unsigned int V_57 )
{
struct V_564 * V_566 ;
struct V_409 * V_410 ;
struct V_565 V_424 ;
V_410 = F_294 ( V_408 , V_437 , V_381 , V_349 , sizeof( * V_566 ) , V_57 ) ;
if ( V_410 == NULL )
return - V_438 ;
V_566 = F_283 ( V_410 ) ;
V_566 -> V_567 = V_432 ;
V_566 -> V_568 = 0 ;
V_566 -> V_569 = 0 ;
V_566 -> V_570 = V_5 -> V_7 -> V_143 ;
V_566 -> V_124 = V_278 -> V_124 ;
V_566 -> V_571 = V_278 -> type ;
V_566 -> V_572 = 0 ;
V_566 -> V_573 = 0 ;
if ( V_278 -> V_132 )
V_566 -> V_573 |= V_574 ;
if ( V_278 -> V_287 )
V_566 -> V_573 |= V_575 ;
if ( F_288 ( V_408 , V_576 , sizeof( V_278 -> V_139 ) , & V_278 -> V_139 ) )
goto V_542;
V_424 . V_577 = F_195 ( V_278 -> V_282 ) ;
V_424 . V_578 = F_195 ( V_278 -> V_281 ) ;
if ( F_288 ( V_408 , V_579 , sizeof( V_424 ) , & V_424 ) )
goto V_542;
return F_296 ( V_408 , V_410 ) ;
V_542:
F_295 ( V_408 , V_410 ) ;
return - V_438 ;
}
static void F_204 ( int V_349 , struct V_4 * V_5 ,
struct V_277 * V_278 )
{
struct V_407 * V_408 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
int V_107 = - V_121 ;
V_408 = F_306 ( F_339 () , V_120 ) ;
if ( V_408 == NULL )
goto V_477;
V_107 = F_340 ( V_408 , V_5 , V_278 , 0 , 0 , V_349 , 0 ) ;
if ( V_107 < 0 ) {
F_21 ( V_107 == - V_438 ) ;
F_307 ( V_408 ) ;
goto V_477;
}
F_310 ( V_408 , V_84 , 0 , V_580 , NULL , V_120 ) ;
return;
V_477:
if ( V_107 < 0 )
F_311 ( V_84 , V_580 , V_107 ) ;
}
static void F_244 ( int V_349 , struct V_13 * V_14 )
{
F_309 ( V_349 ? : V_332 , V_14 ) ;
switch ( V_349 ) {
case V_332 :
if ( ! ( V_14 -> V_9 -> V_581 ) )
F_254 ( V_14 -> V_9 ) ;
if ( V_14 -> V_5 -> V_49 . V_55 )
F_54 ( V_14 ) ;
break;
case V_137 :
if ( V_14 -> V_5 -> V_49 . V_55 )
F_55 ( V_14 ) ;
F_157 ( V_14 -> V_5 , & V_14 -> V_100 ) ;
F_189 ( & V_14 -> V_9 -> V_97 ) ;
if ( F_112 ( V_14 -> V_9 ) )
F_341 ( & V_14 -> V_9 -> V_97 ) ;
break;
}
}
static void F_109 ( int V_349 , struct V_13 * V_14 )
{
F_79 () ;
if ( F_94 ( V_14 -> V_5 -> V_43 == 0 ) )
F_244 ( V_349 , V_14 ) ;
F_93 () ;
}
static
int F_342 ( V_87 * V_582 , int V_583 ,
void T_6 * V_584 , T_15 * V_585 , T_9 * V_586 )
{
int * V_587 = V_582 -> V_123 ;
int V_588 = * V_587 ;
T_9 V_382 = * V_586 ;
V_87 V_589 ;
int V_156 ;
V_589 = * V_582 ;
V_589 . V_123 = & V_588 ;
V_156 = F_343 ( & V_589 , V_583 , V_584 , V_585 , V_586 ) ;
if ( V_583 )
V_156 = F_58 ( V_582 , V_587 , V_588 ) ;
if ( V_156 )
* V_586 = V_382 ;
return V_156 ;
}
static void F_344 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_49 . V_115 )
F_231 ( NULL , V_138 , V_5 -> V_7 ) ;
else
F_231 ( NULL , V_129 , V_5 -> V_7 ) ;
}
static void F_345 ( struct V_84 * V_84 , T_2 V_85 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_132 () ;
F_133 (net, dev) {
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
int V_86 = ( ! V_5 -> V_49 . V_115 ) ^ ( ! V_85 ) ;
V_5 -> V_49 . V_115 = V_85 ;
if ( V_86 )
F_344 ( V_5 ) ;
}
}
F_140 () ;
}
static int F_346 ( struct V_87 * V_88 , int * V_89 , int V_85 )
{
struct V_84 * V_84 ;
int V_90 ;
if ( ! F_59 () )
return F_60 () ;
V_84 = (struct V_84 * ) V_88 -> V_91 ;
V_90 = * V_89 ;
* V_89 = V_85 ;
if ( V_89 == & V_84 -> V_28 . V_50 -> V_115 ) {
F_61 () ;
return 0 ;
}
if ( V_89 == & V_84 -> V_28 . V_92 -> V_115 ) {
V_84 -> V_28 . V_50 -> V_115 = V_85 ;
F_345 ( V_84 , V_85 ) ;
} else if ( ( ! V_85 ) ^ ( ! V_90 ) )
F_344 ( (struct V_4 * ) V_88 -> V_93 ) ;
F_61 () ;
return 0 ;
}
static
int F_347 ( V_87 * V_582 , int V_583 ,
void T_6 * V_584 , T_15 * V_585 , T_9 * V_586 )
{
int * V_587 = V_582 -> V_123 ;
int V_588 = * V_587 ;
T_9 V_382 = * V_586 ;
V_87 V_589 ;
int V_156 ;
V_589 = * V_582 ;
V_589 . V_123 = & V_588 ;
V_156 = F_343 ( & V_589 , V_583 , V_584 , V_585 , V_586 ) ;
if ( V_583 )
V_156 = F_346 ( V_582 , V_587 , V_588 ) ;
if ( V_156 )
* V_586 = V_382 ;
return V_156 ;
}
static int F_348 ( struct V_84 * V_84 , char * V_590 ,
struct V_4 * V_5 , struct V_480 * V_89 )
{
int V_179 ;
struct V_591 * V_592 ;
char V_593 [ sizeof( L_34 ) + V_529 ] ;
V_592 = F_349 ( & V_594 , sizeof( * V_592 ) , V_33 ) ;
if ( V_592 == NULL )
goto V_119;
for ( V_179 = 0 ; V_592 -> V_595 [ V_179 ] . V_123 ; V_179 ++ ) {
V_592 -> V_595 [ V_179 ] . V_123 += ( char * ) V_89 - ( char * ) & V_480 ;
V_592 -> V_595 [ V_179 ] . V_93 = V_5 ;
V_592 -> V_595 [ V_179 ] . V_91 = V_84 ;
}
snprintf ( V_593 , sizeof( V_593 ) , L_35 , V_590 ) ;
V_592 -> V_596 = F_350 ( V_84 , V_593 , V_592 -> V_595 ) ;
if ( V_592 -> V_596 == NULL )
goto free;
V_89 -> V_52 = V_592 ;
return 0 ;
free:
F_17 ( V_592 ) ;
V_119:
return - V_121 ;
}
static void F_351 ( struct V_480 * V_89 )
{
struct V_591 * V_592 ;
if ( V_89 -> V_52 == NULL )
return;
V_592 = V_89 -> V_52 ;
V_89 -> V_52 = NULL ;
F_352 ( V_592 -> V_596 ) ;
F_17 ( V_592 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_353 ( V_5 -> V_7 , V_5 -> V_53 , L_36 ,
& V_597 ) ;
F_348 ( F_32 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_42 ,
V_5 , & V_5 -> V_49 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_351 ( & V_5 -> V_49 ) ;
F_354 ( V_5 -> V_53 ) ;
}
static int T_11 F_355 ( struct V_84 * V_84 )
{
int V_107 ;
struct V_480 * V_598 , * V_599 ;
V_107 = - V_38 ;
V_598 = & V_480 ;
V_599 = & V_600 ;
if ( ! F_144 ( V_84 , & V_601 ) ) {
V_598 = F_349 ( V_598 , sizeof( V_480 ) , V_33 ) ;
if ( V_598 == NULL )
goto V_602;
V_599 = F_349 ( V_599 , sizeof( V_600 ) , V_33 ) ;
if ( V_599 == NULL )
goto V_603;
} else {
V_599 -> V_287 = V_604 . V_287 ;
V_599 -> V_115 = V_604 . V_115 ;
}
V_84 -> V_28 . V_92 = V_598 ;
V_84 -> V_28 . V_50 = V_599 ;
#ifdef F_356
V_107 = F_348 ( V_84 , L_37 , NULL , V_598 ) ;
if ( V_107 < 0 )
goto V_605;
V_107 = F_348 ( V_84 , L_38 , NULL , V_599 ) ;
if ( V_107 < 0 )
goto V_606;
#endif
return 0 ;
#ifdef F_356
V_606:
F_351 ( V_598 ) ;
V_605:
F_17 ( V_599 ) ;
#endif
V_603:
F_17 ( V_598 ) ;
V_602:
return V_107 ;
}
static void T_12 F_357 ( struct V_84 * V_84 )
{
#ifdef F_356
F_351 ( V_84 -> V_28 . V_50 ) ;
F_351 ( V_84 -> V_28 . V_92 ) ;
#endif
if ( ! F_144 ( V_84 , & V_601 ) ) {
F_17 ( V_84 -> V_28 . V_50 ) ;
F_17 ( V_84 -> V_28 . V_92 ) ;
}
}
int F_358 ( struct V_347 * V_607 )
{
return F_359 ( & V_128 , V_607 ) ;
}
int F_360 ( struct V_347 * V_607 )
{
return F_361 ( & V_128 , V_607 ) ;
}
int T_13 F_362 ( void )
{
int V_179 , V_107 ;
V_107 = F_363 () ;
if ( V_107 < 0 ) {
F_364 ( L_39 ,
V_41 , V_107 ) ;
goto V_119;
}
V_107 = F_272 ( & V_608 ) ;
if ( V_107 < 0 )
goto V_609;
F_206 () ;
if ( ! F_28 ( V_601 . V_610 ) )
V_107 = - V_38 ;
F_61 () ;
if ( V_107 )
goto V_611;
for ( V_179 = 0 ; V_179 < V_365 ; V_179 ++ )
F_365 ( & V_125 [ V_179 ] ) ;
F_366 ( & V_612 ) ;
F_203 ( 0 ) ;
V_107 = F_367 ( & V_613 ) ;
if ( V_107 < 0 )
goto V_614;
V_107 = F_368 ( V_615 , V_616 , NULL , F_338 ,
NULL ) ;
if ( V_107 < 0 )
goto V_477;
F_368 ( V_615 , V_332 , F_285 , NULL , NULL ) ;
F_368 ( V_615 , V_137 , F_280 , NULL , NULL ) ;
F_368 ( V_615 , V_617 , F_305 ,
F_302 , NULL ) ;
F_368 ( V_615 , V_463 , NULL ,
F_303 , NULL ) ;
F_368 ( V_615 , V_467 , NULL ,
F_304 , NULL ) ;
F_369 () ;
return 0 ;
V_477:
F_370 ( & V_613 ) ;
V_614:
F_371 ( & V_612 ) ;
V_611:
F_274 ( & V_608 ) ;
V_609:
F_372 () ;
V_119:
return V_107 ;
}
void F_373 ( void )
{
struct V_6 * V_7 ;
int V_179 ;
F_371 ( & V_612 ) ;
F_274 ( & V_608 ) ;
F_372 () ;
F_206 () ;
F_374 ( & V_613 ) ;
F_57 (&init_net, dev) {
if ( F_49 ( V_7 ) == NULL )
continue;
F_216 ( V_7 , 1 ) ;
}
F_216 ( V_601 . V_610 , 2 ) ;
F_97 ( & V_117 ) ;
for ( V_179 = 0 ; V_179 < V_365 ; V_179 ++ )
F_21 ( ! F_375 ( & V_125 [ V_179 ] ) ) ;
F_98 ( & V_117 ) ;
F_8 ( & V_400 ) ;
F_61 () ;
}
