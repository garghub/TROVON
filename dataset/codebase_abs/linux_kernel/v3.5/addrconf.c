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
F_57 () ;
F_58 (net, dev) {
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
int V_86 = ( ! V_5 -> V_49 . V_55 ) ^ ( ! V_85 ) ;
V_5 -> V_49 . V_55 = V_85 ;
if ( V_86 )
F_51 ( V_5 ) ;
}
}
F_59 () ;
}
static int F_60 ( struct V_87 * V_88 , int * V_89 , int V_85 )
{
struct V_84 * V_84 ;
int V_90 ;
if ( ! F_61 () )
return F_62 () ;
V_84 = (struct V_84 * ) V_88 -> V_91 ;
V_90 = * V_89 ;
* V_89 = V_85 ;
if ( V_89 == & V_84 -> V_28 . V_50 -> V_55 ) {
F_63 () ;
return 0 ;
}
if ( V_89 == & V_84 -> V_28 . V_92 -> V_55 ) {
V_84 -> V_28 . V_50 -> V_55 = V_85 ;
F_56 ( V_84 , V_85 ) ;
} else if ( ( ! V_85 ) ^ ( ! V_90 ) )
F_51 ( (struct V_4 * ) V_88 -> V_93 ) ;
F_63 () ;
if ( V_85 )
F_64 ( V_84 ) ;
return 1 ;
}
void F_65 ( struct V_13 * V_14 )
{
F_21 ( ! F_66 ( & V_14 -> V_94 ) ) ;
#ifdef F_23
F_24 ( L_7 , V_41 ) ;
#endif
F_67 ( V_14 -> V_5 ) ;
if ( F_8 ( & V_14 -> V_15 ) )
F_68 ( L_8 , V_14 ) ;
if ( V_14 -> V_95 != V_96 ) {
F_26 ( L_9 , V_14 ) ;
return;
}
F_69 ( & V_14 -> V_9 -> V_97 ) ;
F_27 ( V_14 , V_44 ) ;
}
static void
F_70 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_98 * V_89 ;
int V_99 = F_71 ( & V_14 -> V_100 ) ;
F_72 (p, &idev->addr_list) {
struct V_13 * V_82
= F_73 ( V_89 , struct V_13 , V_101 ) ;
if ( V_99 >= F_71 ( & V_82 -> V_100 ) )
break;
}
F_74 ( & V_14 -> V_101 , V_89 ) ;
}
static T_1 F_75 ( const struct V_102 * V_100 )
{
return F_76 ( ( V_103 T_1 ) V_100 -> V_104 [ 2 ] ,
( V_103 T_1 ) V_100 -> V_104 [ 3 ] , 0 )
& ( V_105 - 1 ) ;
}
static struct V_13 *
F_77 ( struct V_4 * V_5 , const struct V_102 * V_100 , int V_106 ,
int V_107 , T_1 V_57 )
{
struct V_13 * V_82 = NULL ;
struct V_8 * V_9 ;
unsigned int V_108 ;
int V_109 = 0 ;
int V_110 = F_78 ( V_100 ) ;
if ( V_110 == V_111 ||
V_110 & V_112 ||
( ! ( V_5 -> V_7 -> V_57 & V_59 ) &&
V_110 & V_113 ) )
return F_79 ( - V_114 ) ;
F_80 () ;
if ( V_5 -> V_43 ) {
V_109 = - V_115 ;
goto V_116;
}
if ( V_5 -> V_49 . V_117 ) {
V_109 = - V_118 ;
goto V_116;
}
F_81 ( & V_119 ) ;
if ( F_82 ( F_32 ( V_5 -> V_7 ) , V_100 , V_5 -> V_7 ) ) {
F_36 ( ( L_10 ) ) ;
V_109 = - V_120 ;
goto V_121;
}
V_82 = F_16 ( sizeof( struct V_13 ) , V_122 ) ;
if ( V_82 == NULL ) {
F_36 ( ( L_11 ) ) ;
V_109 = - V_123 ;
goto V_121;
}
V_9 = F_83 ( V_5 , V_100 , false ) ;
if ( F_84 ( V_9 ) ) {
V_109 = F_85 ( V_9 ) ;
goto V_121;
}
V_82 -> V_100 = * V_100 ;
F_86 ( & V_82 -> V_48 ) ;
F_86 ( & V_82 -> V_124 ) ;
F_87 ( & V_82 -> V_15 ) ;
F_88 ( & V_82 -> V_94 ) ;
V_82 -> V_15 . V_125 = ( unsigned long ) V_82 ;
V_82 -> V_107 = V_107 ;
V_82 -> V_126 = V_106 ;
V_82 -> V_57 = V_57 | V_83 ;
V_82 -> V_1 = V_82 -> V_76 = V_25 ;
V_82 -> V_9 = V_9 ;
V_82 -> V_5 = V_5 ;
F_39 ( V_5 ) ;
F_11 ( V_82 ) ;
V_108 = F_75 ( V_100 ) ;
F_89 ( & V_82 -> V_94 , & V_127 [ V_108 ] ) ;
F_90 ( & V_119 ) ;
F_91 ( & V_5 -> V_48 ) ;
F_70 ( V_5 , V_82 ) ;
#ifdef F_42
if ( V_82 -> V_57 & V_128 ) {
F_92 ( & V_82 -> V_129 , & V_5 -> V_67 ) ;
F_11 ( V_82 ) ;
}
#endif
F_11 ( V_82 ) ;
F_93 ( & V_5 -> V_48 ) ;
V_116:
F_94 () ;
if ( F_95 ( V_109 == 0 ) )
F_96 ( & V_130 , V_131 , V_82 ) ;
else {
F_17 ( V_82 ) ;
V_82 = F_79 ( V_109 ) ;
}
return V_82 ;
V_121:
F_90 ( & V_119 ) ;
goto V_116;
}
static void F_97 ( struct V_13 * V_14 )
{
struct V_13 * V_82 , * V_132 ;
struct V_4 * V_5 = V_14 -> V_5 ;
int V_95 ;
int V_133 = 0 , V_134 = 0 ;
unsigned long V_24 = V_25 ;
F_98 ( & V_14 -> V_124 ) ;
V_95 = V_14 -> V_95 ;
V_14 -> V_95 = V_96 ;
F_99 ( & V_14 -> V_124 ) ;
if ( V_95 == V_96 )
goto V_121;
F_98 ( & V_119 ) ;
F_100 ( & V_14 -> V_94 ) ;
F_99 ( & V_119 ) ;
F_101 ( & V_5 -> V_48 ) ;
#ifdef F_42
if ( V_14 -> V_57 & V_128 ) {
F_102 ( & V_14 -> V_129 ) ;
if ( V_14 -> V_135 ) {
F_103 ( V_14 -> V_135 ) ;
V_14 -> V_135 = NULL ;
}
F_9 ( V_14 ) ;
}
#endif
F_104 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_82 == V_14 ) {
F_105 ( & V_14 -> V_101 ) ;
F_9 ( V_14 ) ;
if ( ! ( V_14 -> V_57 & V_136 ) || V_134 > 0 )
break;
V_133 = 1 ;
continue;
} else if ( V_14 -> V_57 & V_136 ) {
if ( F_106 ( & V_82 -> V_100 , & V_14 -> V_100 ,
V_14 -> V_126 ) ) {
if ( V_82 -> V_57 & V_136 ) {
V_134 = 1 ;
if ( V_133 )
break;
} else {
unsigned long V_137 ;
if ( ! V_134 )
V_134 = - 1 ;
F_81 ( & V_82 -> V_48 ) ;
V_137 = F_107 ( V_82 -> V_138 , V_3 ) ;
if ( F_108 ( V_24 ,
V_82 -> V_76 + V_137 * V_3 ) )
V_24 = V_82 -> V_76 + V_137 * V_3 ;
F_90 ( & V_82 -> V_48 ) ;
}
}
}
}
F_109 ( & V_5 -> V_48 ) ;
F_7 ( V_14 ) ;
F_110 ( V_139 , V_14 ) ;
F_96 ( & V_130 , V_140 , V_14 ) ;
if ( ( V_14 -> V_57 & V_136 ) && V_134 < 1 ) {
struct V_102 V_141 ;
struct V_8 * V_9 ;
struct V_84 * V_84 = F_32 ( V_14 -> V_5 -> V_7 ) ;
F_111 ( & V_141 , & V_14 -> V_100 , V_14 -> V_126 ) ;
V_9 = F_112 ( V_84 , & V_141 , NULL , V_14 -> V_5 -> V_7 -> V_142 , 1 ) ;
if ( V_9 && F_6 ( V_9 ) ) {
if ( V_134 == 0 ) {
F_113 ( V_9 ) ;
V_9 = NULL ;
} else if ( ! ( V_9 -> V_10 & V_143 ) ) {
F_114 ( V_9 , V_24 ) ;
}
}
F_69 ( & V_9 -> V_97 ) ;
}
F_115 ( V_14 ) ;
V_121:
F_103 ( V_14 ) ;
}
static int F_116 ( struct V_13 * V_14 , struct V_13 * V_144 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_102 V_100 , * V_145 ;
unsigned long V_146 , V_147 , V_148 , V_149 ;
unsigned long V_150 ;
int V_151 ;
int V_152 = 0 ;
int V_153 ;
T_1 V_154 ;
unsigned long V_155 = V_25 ;
F_91 ( & V_5 -> V_48 ) ;
if ( V_144 ) {
F_98 ( & V_144 -> V_48 ) ;
memcpy ( & V_100 . V_156 [ 8 ] , & V_144 -> V_100 . V_156 [ 8 ] , 8 ) ;
F_99 ( & V_144 -> V_48 ) ;
V_145 = & V_100 ;
} else {
V_145 = NULL ;
}
V_157:
F_39 ( V_5 ) ;
if ( V_5 -> V_49 . V_73 <= 0 ) {
F_93 ( & V_5 -> V_48 ) ;
F_41 ( L_12 , V_41 ) ;
F_67 ( V_5 ) ;
V_152 = - 1 ;
goto V_121;
}
F_98 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_158 ++ >= V_5 -> V_49 . V_159 ) {
V_5 -> V_49 . V_73 = - 1 ;
F_99 ( & V_14 -> V_48 ) ;
F_93 ( & V_5 -> V_48 ) ;
F_26 ( L_13 ,
V_41 ) ;
F_67 ( V_5 ) ;
V_152 = - 1 ;
goto V_121;
}
F_11 ( V_14 ) ;
memcpy ( V_100 . V_156 , V_14 -> V_100 . V_156 , 8 ) ;
if ( F_117 ( V_5 , V_145 ) < 0 ) {
F_99 ( & V_14 -> V_48 ) ;
F_93 ( & V_5 -> V_48 ) ;
F_26 ( L_14 ,
V_41 ) ;
F_103 ( V_14 ) ;
F_67 ( V_5 ) ;
V_152 = - 1 ;
goto V_121;
}
memcpy ( & V_100 . V_156 [ 8 ] , V_5 -> V_160 , 8 ) ;
V_149 = ( V_155 - V_14 -> V_76 ) / V_3 ;
V_147 = F_118 ( V_161 ,
V_14 -> V_138 ,
V_5 -> V_49 . V_162 + V_149 ) ;
V_146 = F_118 ( V_161 ,
V_14 -> V_163 ,
V_5 -> V_49 . V_164 + V_149 -
V_5 -> V_49 . V_165 ) ;
V_151 = V_14 -> V_126 ;
V_153 = V_5 -> V_49 . V_153 ;
V_148 = V_14 -> V_76 ;
F_99 ( & V_14 -> V_48 ) ;
V_150 = V_5 -> V_49 . V_159 *
V_5 -> V_49 . V_166 *
V_5 -> V_53 -> V_167 / V_3 ;
F_93 ( & V_5 -> V_48 ) ;
if ( V_146 <= V_150 ) {
F_103 ( V_14 ) ;
F_67 ( V_5 ) ;
V_152 = - 1 ;
goto V_121;
}
V_154 = V_128 ;
if ( V_14 -> V_57 & V_168 )
V_154 |= V_168 ;
V_144 = ! V_153 ||
F_119 ( V_5 ) < V_153 ?
F_77 ( V_5 , & V_100 , V_151 ,
F_78 ( & V_100 ) & V_169 ,
V_154 ) : NULL ;
if ( ! V_144 || F_84 ( V_144 ) ) {
F_103 ( V_14 ) ;
F_67 ( V_5 ) ;
F_41 ( L_15 , V_41 ) ;
V_145 = & V_100 ;
F_91 ( & V_5 -> V_48 ) ;
goto V_157;
}
F_98 ( & V_144 -> V_48 ) ;
V_144 -> V_135 = V_14 ;
V_144 -> V_138 = V_147 ;
V_144 -> V_163 = V_146 ;
V_144 -> V_1 = V_155 ;
V_144 -> V_76 = V_148 ;
F_99 ( & V_144 -> V_48 ) ;
F_120 ( V_144 ) ;
F_103 ( V_144 ) ;
F_67 ( V_5 ) ;
V_121:
return V_152 ;
}
static inline int F_121 ( int type )
{
if ( type & ( V_170 | V_171 | V_113 ) )
return 1 ;
return 0 ;
}
static int F_122 ( struct V_84 * V_84 ,
struct V_172 * V_173 ,
struct V_174 * V_97 ,
int V_175 )
{
int V_152 ;
if ( V_175 <= V_173 -> V_176 ) {
switch ( V_175 ) {
case V_177 :
V_152 = V_173 -> V_178 ;
break;
case V_179 :
V_152 = V_173 -> V_180 ;
break;
default:
V_152 = ! ! F_123 ( V_175 , V_173 -> V_181 ) ;
}
goto V_121;
}
switch ( V_175 ) {
case V_182 :
V_152 = ! ! V_173 -> V_82 ;
break;
case V_183 :
V_152 = F_124 ( & V_173 -> V_82 -> V_100 , V_97 -> V_100 ) ;
break;
case V_177 :
V_152 = F_125 ( V_173 -> V_110 ) ;
if ( V_152 >= V_97 -> V_107 )
V_152 = - V_152 ;
else
V_152 -= 128 ;
V_173 -> V_178 = V_152 ;
break;
case V_184 :
V_152 = F_121 ( V_173 -> V_110 ) ||
! ( V_173 -> V_82 -> V_57 & ( V_185 | V_168 ) ) ;
break;
#ifdef F_126
case V_186 :
{
int V_187 = ! ( V_97 -> V_188 & V_189 ) ;
V_152 = ! ( V_173 -> V_82 -> V_57 & V_190 ) ^ V_187 ;
break;
}
#endif
case V_191 :
V_152 = ( ! V_97 -> V_142 ||
V_97 -> V_142 == V_173 -> V_82 -> V_5 -> V_7 -> V_142 ) ;
break;
case V_192 :
V_152 = F_127 ( V_84 ,
& V_173 -> V_82 -> V_100 , V_173 -> V_110 ,
V_173 -> V_82 -> V_5 -> V_7 -> V_142 ) == V_97 -> V_193 ;
break;
#ifdef F_42
case V_194 :
{
int V_195 = V_97 -> V_188 & ( V_196 | V_197 ) ?
! ! ( V_97 -> V_188 & V_197 ) :
V_173 -> V_82 -> V_5 -> V_49 . V_73 >= 2 ;
V_152 = ( ! ( V_173 -> V_82 -> V_57 & V_128 ) ) ^ V_195 ;
break;
}
#endif
case V_198 :
V_152 = ! ( F_128 ( & V_173 -> V_82 -> V_100 ) ^
F_128 ( V_97 -> V_100 ) ) ;
break;
case V_179 :
V_173 -> V_180 = V_152 = F_129 ( & V_173 -> V_82 -> V_100 ,
V_97 -> V_100 ) ;
break;
default:
V_152 = 0 ;
}
if ( V_152 )
F_130 ( V_175 , V_173 -> V_181 ) ;
V_173 -> V_176 = V_175 ;
V_121:
return V_152 ;
}
int F_131 ( struct V_84 * V_84 , struct V_6 * V_199 ,
const struct V_102 * V_200 , unsigned int V_188 ,
struct V_102 * V_201 )
{
struct V_172 V_202 [ 2 ] ,
* V_173 = & V_202 [ 0 ] , * V_203 = & V_202 [ 1 ] ;
struct V_174 V_97 ;
struct V_6 * V_7 ;
int V_204 ;
V_204 = F_132 ( V_200 ) ;
V_97 . V_100 = V_200 ;
V_97 . V_142 = V_199 ? V_199 -> V_142 : 0 ;
V_97 . V_107 = F_125 ( V_204 ) ;
V_97 . V_193 = F_127 ( V_84 , V_200 , V_204 , V_97 . V_142 ) ;
V_97 . V_188 = V_188 ;
V_203 -> V_176 = - 1 ;
V_203 -> V_82 = NULL ;
F_57 () ;
F_58 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_204 & V_112 ) ||
V_97 . V_107 <= V_205 ) &&
V_97 . V_142 && V_7 -> V_142 != V_97 . V_142 )
continue;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
continue;
F_133 ( & V_5 -> V_48 ) ;
F_53 (score->ifa, &idev->addr_list, if_list) {
int V_175 ;
if ( ( V_173 -> V_82 -> V_57 & V_83 ) &&
( ! ( V_173 -> V_82 -> V_57 & V_168 ) ) )
continue;
V_173 -> V_110 = F_132 ( & V_173 -> V_82 -> V_100 ) ;
if ( F_134 ( V_173 -> V_110 == V_111 ||
V_173 -> V_110 & V_112 ) ) {
F_135 ( V_206
L_16
L_17 ,
V_7 -> V_42 ) ;
continue;
}
V_173 -> V_176 = - 1 ;
F_136 ( V_173 -> V_181 , V_207 ) ;
for ( V_175 = 0 ; V_175 < V_207 ; V_175 ++ ) {
int V_208 , V_209 ;
V_208 = F_122 ( V_84 , V_203 , & V_97 , V_175 ) ;
V_209 = F_122 ( V_84 , V_173 , & V_97 , V_175 ) ;
if ( V_208 > V_209 ) {
if ( V_175 == V_177 &&
V_173 -> V_178 > 0 ) {
goto V_210;
}
break;
} else if ( V_208 < V_209 ) {
if ( V_203 -> V_82 )
F_103 ( V_203 -> V_82 ) ;
F_11 ( V_173 -> V_82 ) ;
F_137 ( V_203 , V_173 ) ;
V_173 -> V_82 = V_203 -> V_82 ;
break;
}
}
}
V_210:
F_138 ( & V_5 -> V_48 ) ;
}
F_59 () ;
if ( ! V_203 -> V_82 )
return - V_114 ;
* V_201 = V_203 -> V_82 -> V_100 ;
F_103 ( V_203 -> V_82 ) ;
return 0 ;
}
int F_139 ( struct V_6 * V_7 , struct V_102 * V_100 ,
unsigned char V_211 )
{
struct V_4 * V_5 ;
int V_109 = - V_114 ;
F_57 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
struct V_13 * V_14 ;
F_133 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_107 == V_212 &&
! ( V_14 -> V_57 & V_211 ) ) {
* V_100 = V_14 -> V_100 ;
V_109 = 0 ;
break;
}
}
F_138 ( & V_5 -> V_48 ) ;
}
F_59 () ;
return V_109 ;
}
static int F_119 ( struct V_4 * V_5 )
{
int V_213 = 0 ;
struct V_13 * V_14 ;
F_133 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list)
V_213 ++ ;
F_138 ( & V_5 -> V_48 ) ;
return V_213 ;
}
int F_140 ( struct V_84 * V_84 , const struct V_102 * V_100 ,
struct V_6 * V_7 , int V_214 )
{
struct V_13 * V_14 ;
struct V_215 * V_216 ;
unsigned int V_108 = F_75 ( V_100 ) ;
F_80 () ;
F_141 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_142 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_124 ( & V_14 -> V_100 , V_100 ) &&
! ( V_14 -> V_57 & V_83 ) &&
( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_107 & ( V_212 | V_217 ) || V_214 ) ) ) {
F_94 () ;
return 1 ;
}
}
F_94 () ;
return 0 ;
}
static bool F_82 ( struct V_84 * V_84 , const struct V_102 * V_100 ,
struct V_6 * V_7 )
{
unsigned int V_108 = F_75 ( V_100 ) ;
struct V_13 * V_14 ;
struct V_215 * V_216 ;
F_143 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_142 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_124 ( & V_14 -> V_100 , V_100 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
int F_144 ( const struct V_102 * V_100 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_134 ;
V_134 = 0 ;
F_57 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
F_133 ( & V_5 -> V_48 ) ;
F_53 (ifa, &idev->addr_list, if_list) {
V_134 = F_106 ( V_100 , & V_82 -> V_100 ,
V_82 -> V_126 ) ;
if ( V_134 )
break;
}
F_138 ( & V_5 -> V_48 ) ;
}
F_59 () ;
return V_134 ;
}
struct V_13 * F_145 ( struct V_84 * V_84 , const struct V_102 * V_100 ,
struct V_6 * V_7 , int V_214 )
{
struct V_13 * V_14 , * V_218 = NULL ;
unsigned int V_108 = F_75 ( V_100 ) ;
struct V_215 * V_216 ;
F_80 () ;
F_146 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_142 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_124 ( & V_14 -> V_100 , V_100 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_107 & ( V_212 | V_217 ) || V_214 ) ) {
V_218 = V_14 ;
F_11 ( V_14 ) ;
break;
}
}
}
F_94 () ;
return V_218 ;
}
static void F_147 ( struct V_13 * V_14 , int V_219 )
{
if ( V_14 -> V_57 & V_136 ) {
F_98 ( & V_14 -> V_48 ) ;
F_7 ( V_14 ) ;
V_14 -> V_57 |= V_83 ;
if ( V_219 )
V_14 -> V_57 |= V_220 ;
F_99 ( & V_14 -> V_48 ) ;
if ( V_219 )
F_110 ( 0 , V_14 ) ;
F_103 ( V_14 ) ;
#ifdef F_42
} else if ( V_14 -> V_57 & V_128 ) {
struct V_13 * V_135 ;
F_98 ( & V_14 -> V_48 ) ;
V_135 = V_14 -> V_135 ;
if ( V_135 ) {
F_11 ( V_135 ) ;
F_99 ( & V_14 -> V_48 ) ;
F_116 ( V_135 , V_14 ) ;
F_103 ( V_135 ) ;
} else {
F_99 ( & V_14 -> V_48 ) ;
}
F_97 ( V_14 ) ;
#endif
} else
F_97 ( V_14 ) ;
}
static int F_148 ( struct V_13 * V_14 )
{
int V_109 = - V_221 ;
F_81 ( & V_14 -> V_124 ) ;
if ( V_14 -> V_95 == V_222 ) {
V_14 -> V_95 = V_223 ;
V_109 = 0 ;
}
F_90 ( & V_14 -> V_124 ) ;
return V_109 ;
}
void F_149 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
if ( F_148 ( V_14 ) ) {
F_103 ( V_14 ) ;
return;
}
F_150 ( L_18 ,
V_14 -> V_5 -> V_7 -> V_42 , & V_14 -> V_100 ) ;
if ( V_5 -> V_49 . V_60 > 1 && ! V_5 -> V_49 . V_117 ) {
struct V_102 V_100 ;
V_100 . V_104 [ 0 ] = F_151 ( 0xfe800000 ) ;
V_100 . V_104 [ 1 ] = 0 ;
if ( ! F_152 ( V_100 . V_156 + 8 , V_5 -> V_7 ) &&
F_124 ( & V_14 -> V_100 , & V_100 ) ) {
V_5 -> V_49 . V_117 = 1 ;
F_41 ( L_19 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
}
}
F_147 ( V_14 , 1 ) ;
}
void F_153 ( struct V_6 * V_7 , const struct V_102 * V_100 )
{
struct V_102 V_224 ;
if ( V_7 -> V_57 & ( V_59 | V_58 ) )
return;
F_154 ( V_100 , & V_224 ) ;
F_47 ( V_7 , & V_224 ) ;
}
void F_155 ( struct V_4 * V_5 , const struct V_102 * V_100 )
{
struct V_102 V_224 ;
if ( V_5 -> V_7 -> V_57 & ( V_59 | V_58 ) )
return;
F_154 ( V_100 , & V_224 ) ;
F_156 ( V_5 , & V_224 ) ;
}
static void F_54 ( struct V_13 * V_14 )
{
struct V_102 V_100 ;
if ( V_14 -> V_126 == 127 )
return;
F_111 ( & V_100 , & V_14 -> V_100 , V_14 -> V_126 ) ;
if ( F_157 ( & V_100 ) )
return;
F_158 ( V_14 -> V_5 -> V_7 , & V_100 ) ;
}
static void F_55 ( struct V_13 * V_14 )
{
struct V_102 V_100 ;
if ( V_14 -> V_126 == 127 )
return;
F_111 ( & V_100 , & V_14 -> V_100 , V_14 -> V_126 ) ;
if ( F_157 ( & V_100 ) )
return;
F_159 ( V_14 -> V_5 , & V_100 ) ;
}
static int F_160 ( T_3 * V_225 , struct V_6 * V_7 )
{
if ( V_7 -> V_226 != V_227 )
return - 1 ;
memcpy ( V_225 , V_7 -> V_228 , 3 ) ;
memcpy ( V_225 + 5 , V_7 -> V_228 + 3 , 3 ) ;
if ( V_7 -> V_229 ) {
V_225 [ 3 ] = ( V_7 -> V_229 >> 8 ) & 0xFF ;
V_225 [ 4 ] = V_7 -> V_229 & 0xFF ;
} else {
V_225 [ 3 ] = 0xFF ;
V_225 [ 4 ] = 0xFE ;
V_225 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_161 ( T_3 * V_225 , struct V_6 * V_7 )
{
if ( V_7 -> V_226 != V_230 )
return - 1 ;
memcpy ( V_225 , V_7 -> V_228 , 8 ) ;
return 0 ;
}
static int F_162 ( T_3 * V_225 , struct V_6 * V_7 )
{
if ( V_7 -> V_226 != V_231 )
return - 1 ;
memset ( V_225 , 0 , 7 ) ;
V_225 [ 7 ] = * ( T_3 * ) V_7 -> V_228 ;
return 0 ;
}
static int F_163 ( T_3 * V_225 , struct V_6 * V_7 )
{
if ( V_7 -> V_226 != V_232 )
return - 1 ;
memcpy ( V_225 , V_7 -> V_228 + 12 , 8 ) ;
V_225 [ 0 ] |= 2 ;
return 0 ;
}
static int F_164 ( T_3 * V_225 , T_4 V_100 )
{
if ( V_100 == 0 )
return - 1 ;
V_225 [ 0 ] = ( F_165 ( V_100 ) || F_166 ( V_100 ) ||
F_167 ( V_100 ) || F_168 ( V_100 ) ||
F_169 ( V_100 ) || F_170 ( V_100 ) ||
F_171 ( V_100 ) || F_172 ( V_100 ) ||
F_173 ( V_100 ) || F_174 ( V_100 ) ||
F_175 ( V_100 ) ) ? 0x00 : 0x02 ;
V_225 [ 1 ] = 0 ;
V_225 [ 2 ] = 0x5E ;
V_225 [ 3 ] = 0xFE ;
memcpy ( V_225 + 4 , & V_100 , 4 ) ;
return 0 ;
}
static int F_176 ( T_3 * V_225 , struct V_6 * V_7 )
{
if ( V_7 -> V_64 & V_65 )
return F_164 ( V_225 , * ( T_4 * ) V_7 -> V_228 ) ;
return - 1 ;
}
static int F_177 ( T_3 * V_225 , struct V_6 * V_7 )
{
return F_164 ( V_225 , * ( T_4 * ) V_7 -> V_228 ) ;
}
static int F_152 ( T_3 * V_225 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_233 :
case V_234 :
return F_160 ( V_225 , V_7 ) ;
case V_235 :
return F_162 ( V_225 , V_7 ) ;
case V_236 :
return F_163 ( V_225 , V_7 ) ;
case V_63 :
return F_176 ( V_225 , V_7 ) ;
case V_237 :
return F_177 ( V_225 , V_7 ) ;
case V_238 :
return F_161 ( V_225 , V_7 ) ;
}
return - 1 ;
}
static int F_178 ( T_3 * V_225 , struct V_4 * V_5 )
{
int V_109 = - 1 ;
struct V_13 * V_14 ;
F_133 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_107 == V_212 && ! ( V_14 -> V_57 & V_83 ) ) {
memcpy ( V_225 , V_14 -> V_100 . V_156 + 8 , 8 ) ;
V_109 = 0 ;
break;
}
}
F_138 ( & V_5 -> V_48 ) ;
return V_109 ;
}
static int F_179 ( struct V_4 * V_5 )
{
V_239:
F_180 ( V_5 -> V_160 , sizeof( V_5 -> V_160 ) ) ;
V_5 -> V_160 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_160 [ 0 ] == 0xfd &&
( V_5 -> V_160 [ 1 ] & V_5 -> V_160 [ 2 ] & V_5 -> V_160 [ 3 ] & V_5 -> V_160 [ 4 ] & V_5 -> V_160 [ 5 ] & V_5 -> V_160 [ 6 ] ) == 0xff &&
( V_5 -> V_160 [ 7 ] & 0x80 ) )
goto V_239;
if ( ( V_5 -> V_160 [ 0 ] | V_5 -> V_160 [ 1 ] ) == 0 ) {
if ( V_5 -> V_160 [ 2 ] == 0x5e && V_5 -> V_160 [ 3 ] == 0xfe )
goto V_239;
if ( ( V_5 -> V_160 [ 2 ] | V_5 -> V_160 [ 3 ] | V_5 -> V_160 [ 4 ] | V_5 -> V_160 [ 5 ] | V_5 -> V_160 [ 6 ] | V_5 -> V_160 [ 7 ] ) == 0x00 )
goto V_239;
}
return 0 ;
}
static void V_69 ( unsigned long V_125 )
{
struct V_4 * V_5 = (struct V_4 * ) V_125 ;
unsigned long V_24 ;
F_80 () ;
F_101 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 )
goto V_121;
if ( F_179 ( V_5 ) < 0 )
goto V_121;
V_24 = V_25 +
V_5 -> V_49 . V_164 * V_3 -
V_5 -> V_49 . V_159 * V_5 -> V_49 . V_166 * V_5 -> V_53 -> V_167 -
V_5 -> V_49 . V_165 * V_3 ;
if ( F_108 ( V_24 , V_25 ) ) {
F_26 ( L_20 ,
V_41 , V_5 -> V_7 -> V_42 ) ;
goto V_121;
}
if ( ! F_181 ( & V_5 -> V_68 , V_24 ) )
F_39 ( V_5 ) ;
V_121:
F_109 ( & V_5 -> V_48 ) ;
F_94 () ;
F_67 ( V_5 ) ;
}
static int F_117 ( struct V_4 * V_5 , struct V_102 * V_145 )
{
int V_152 = 0 ;
if ( V_145 && memcmp ( V_5 -> V_160 , & V_145 -> V_156 [ 8 ] , 8 ) == 0 )
V_152 = F_179 ( V_5 ) ;
return V_152 ;
}
static void
F_182 ( struct V_102 * V_240 , int V_241 , struct V_6 * V_7 ,
unsigned long V_24 , T_1 V_57 )
{
struct V_242 V_243 = {
. V_244 = V_245 ,
. V_246 = V_247 ,
. V_248 = V_7 -> V_142 ,
. V_249 = V_24 ,
. V_250 = V_241 ,
. V_251 = V_252 | V_57 ,
. V_253 . V_254 = F_32 ( V_7 ) ,
. V_255 = V_256 ,
} ;
V_243 . V_257 = * V_240 ;
#if F_40 ( V_61 ) || F_40 ( V_62 )
if ( V_7 -> type == V_63 && ( V_7 -> V_57 & V_258 ) )
V_243 . V_251 |= V_259 ;
#endif
F_183 ( & V_243 ) ;
}
static struct V_8 * F_184 ( const struct V_102 * V_240 ,
int V_241 ,
const struct V_6 * V_7 ,
T_1 V_57 , T_1 V_260 )
{
struct V_261 * V_262 ;
struct V_8 * V_9 = NULL ;
struct V_263 * V_88 ;
V_88 = F_185 ( F_32 ( V_7 ) , V_245 ) ;
if ( V_88 == NULL )
return NULL ;
F_101 ( & V_88 -> V_264 ) ;
V_262 = F_186 ( & V_88 -> V_265 , V_240 , V_241 , NULL , 0 ) ;
if ( ! V_262 )
goto V_121;
for ( V_9 = V_262 -> V_266 ; V_9 ; V_9 = V_9 -> V_97 . V_267 ) {
if ( V_9 -> V_97 . V_7 -> V_142 != V_7 -> V_142 )
continue;
if ( ( V_9 -> V_10 & V_57 ) != V_57 )
continue;
if ( ( V_260 != 0 ) && ( ( V_9 -> V_10 & V_57 ) != 0 ) )
continue;
F_187 ( & V_9 -> V_97 ) ;
break;
}
V_121:
F_109 ( & V_88 -> V_264 ) ;
return V_9 ;
}
static void F_188 ( struct V_6 * V_7 )
{
struct V_242 V_243 = {
. V_244 = V_268 ,
. V_246 = V_247 ,
. V_248 = V_7 -> V_142 ,
. V_250 = 8 ,
. V_251 = V_252 ,
. V_253 . V_254 = F_32 ( V_7 ) ,
} ;
F_189 ( & V_243 . V_257 , F_151 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_183 ( & V_243 ) ;
}
static void F_190 ( struct V_6 * V_7 )
{
struct V_242 V_243 = {
. V_244 = V_269 ,
. V_246 = V_247 ,
. V_248 = V_7 -> V_142 ,
. V_250 = 96 ,
. V_251 = V_252 | V_259 ,
. V_253 . V_254 = F_32 ( V_7 ) ,
} ;
F_183 ( & V_243 ) ;
}
static void F_191 ( struct V_6 * V_7 )
{
struct V_102 V_100 ;
F_189 ( & V_100 , F_151 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_182 ( & V_100 , 64 , V_7 , 0 , 0 ) ;
}
static struct V_4 * F_192 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
return F_79 ( - V_123 ) ;
if ( V_5 -> V_49 . V_117 )
return F_79 ( - V_118 ) ;
if ( ! ( V_7 -> V_57 & V_59 ) )
F_188 ( V_7 ) ;
F_191 ( V_7 ) ;
return V_5 ;
}
void F_193 ( struct V_6 * V_7 , T_3 * V_270 , int V_271 , bool V_272 )
{
struct V_273 * V_274 ;
V_161 V_138 ;
V_161 V_163 ;
int V_110 ;
struct V_4 * V_275 ;
struct V_84 * V_84 = F_32 ( V_7 ) ;
V_274 = (struct V_273 * ) V_270 ;
if ( V_271 < sizeof( struct V_273 ) ) {
F_36 ( ( L_21 ) ) ;
return;
}
V_110 = F_78 ( & V_274 -> V_141 ) ;
if ( V_110 & ( V_112 | V_276 ) )
return;
V_138 = F_194 ( V_274 -> V_277 ) ;
V_163 = F_194 ( V_274 -> V_278 ) ;
if ( V_163 > V_138 ) {
F_195 ( L_22 ) ;
return;
}
V_275 = F_196 ( V_7 ) ;
if ( V_275 == NULL ) {
F_197 ( L_23 ,
V_7 -> V_42 ) ;
return;
}
if ( V_274 -> V_134 ) {
struct V_8 * V_9 ;
unsigned long V_279 ;
if ( V_3 > V_280 )
V_279 = F_107 ( V_138 , V_3 ) ;
else
V_279 = F_107 ( V_138 , V_280 ) ;
if ( F_198 ( V_279 ) )
V_279 *= V_3 ;
V_9 = F_184 ( & V_274 -> V_141 ,
V_274 -> V_126 ,
V_7 ,
V_281 | V_282 ,
V_11 | V_12 ) ;
if ( V_9 ) {
if ( V_138 == 0 ) {
F_113 ( V_9 ) ;
V_9 = NULL ;
} else if ( F_198 ( V_279 ) ) {
F_114 ( V_9 , V_25 + V_279 ) ;
} else {
F_199 ( V_9 ) ;
}
} else if ( V_138 ) {
T_5 V_24 = 0 ;
int V_57 = V_281 | V_282 ;
if ( F_198 ( V_279 ) ) {
V_57 |= V_143 ;
V_24 = F_200 ( V_279 ) ;
}
F_182 ( & V_274 -> V_141 , V_274 -> V_126 ,
V_7 , V_24 , V_57 ) ;
}
if ( V_9 )
F_69 ( & V_9 -> V_97 ) ;
}
if ( V_274 -> V_283 && V_275 -> V_49 . V_283 ) {
struct V_13 * V_14 ;
struct V_102 V_100 ;
int V_284 = 0 , V_285 = 0 ;
if ( V_274 -> V_126 == 64 ) {
memcpy ( & V_100 , & V_274 -> V_141 , 8 ) ;
if ( F_152 ( V_100 . V_156 + 8 , V_7 ) &&
F_178 ( V_100 . V_156 + 8 , V_275 ) ) {
F_67 ( V_275 ) ;
return;
}
goto V_286;
}
F_197 ( L_24 ,
V_274 -> V_126 ) ;
F_67 ( V_275 ) ;
return;
V_286:
V_14 = F_145 ( V_84 , & V_100 , V_7 , 1 ) ;
if ( V_14 == NULL && V_138 ) {
int V_153 = V_275 -> V_49 . V_153 ;
T_1 V_154 = 0 ;
#ifdef F_201
if ( V_275 -> V_49 . V_287 &&
! V_84 -> V_28 . V_92 -> V_55 && V_272 )
V_154 = V_168 ;
#endif
if ( ! V_153 ||
F_119 ( V_275 ) < V_153 )
V_14 = F_77 ( V_275 , & V_100 , V_274 -> V_126 ,
V_110 & V_169 ,
V_154 ) ;
if ( ! V_14 || F_84 ( V_14 ) ) {
F_67 ( V_275 ) ;
return;
}
V_285 = V_284 = 1 ;
V_14 -> V_1 = V_25 ;
F_120 ( V_14 ) ;
}
if ( V_14 ) {
int V_57 ;
unsigned long V_155 ;
#ifdef F_42
struct V_13 * V_144 ;
#endif
T_1 V_288 ;
F_81 ( & V_14 -> V_48 ) ;
V_155 = V_25 ;
if ( V_14 -> V_138 > ( V_155 - V_14 -> V_76 ) / V_3 )
V_288 = V_14 -> V_138 - ( V_155 - V_14 -> V_76 ) / V_3 ;
else
V_288 = 0 ;
if ( ! V_285 && V_288 ) {
if ( V_138 > V_289 ||
V_138 > V_288 )
V_285 = 1 ;
else if ( V_288 <= V_289 ) {
if ( V_163 != V_14 -> V_163 ) {
V_138 = V_288 ;
V_285 = 1 ;
}
} else {
V_138 = V_289 ;
if ( V_138 < V_163 )
V_163 = V_138 ;
V_285 = 1 ;
}
}
if ( V_285 ) {
V_14 -> V_138 = V_138 ;
V_14 -> V_163 = V_163 ;
V_14 -> V_76 = V_155 ;
V_57 = V_14 -> V_57 ;
V_14 -> V_57 &= ~ V_185 ;
F_90 ( & V_14 -> V_48 ) ;
if ( ! ( V_57 & V_83 ) )
F_110 ( 0 , V_14 ) ;
} else
F_90 ( & V_14 -> V_48 ) ;
#ifdef F_42
F_133 ( & V_275 -> V_48 ) ;
F_53 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_149 , V_290 , V_291 ;
if ( V_14 != V_144 -> V_135 )
continue;
V_149 = ( V_155 - V_144 -> V_1 ) / V_3 ;
V_290 = V_275 -> V_49 . V_162 - V_149 ;
if ( V_290 < 0 )
V_290 = 0 ;
V_291 = V_275 -> V_49 . V_164 -
V_275 -> V_49 . V_165 -
V_149 ;
if ( V_291 < 0 )
V_291 = 0 ;
if ( V_138 > V_290 )
V_138 = V_290 ;
if ( V_163 > V_291 )
V_163 = V_291 ;
F_81 ( & V_144 -> V_48 ) ;
V_57 = V_144 -> V_57 ;
V_144 -> V_138 = V_138 ;
V_144 -> V_163 = V_163 ;
V_144 -> V_76 = V_155 ;
if ( V_163 > 0 )
V_144 -> V_57 &= ~ V_185 ;
F_90 ( & V_144 -> V_48 ) ;
if ( ! ( V_57 & V_83 ) )
F_110 ( 0 , V_144 ) ;
}
if ( ( V_284 || F_22 ( & V_275 -> V_67 ) ) && V_275 -> V_49 . V_73 > 0 ) {
F_138 ( & V_275 -> V_48 ) ;
F_116 ( V_14 , NULL ) ;
} else {
F_138 ( & V_275 -> V_48 ) ;
}
#endif
F_103 ( V_14 ) ;
F_202 ( 0 ) ;
}
}
F_203 ( V_292 , V_275 , V_274 ) ;
F_67 ( V_275 ) ;
}
int F_204 ( struct V_84 * V_84 , void T_6 * V_293 )
{
struct V_294 V_295 ;
struct V_6 * V_7 ;
int V_109 = - V_296 ;
F_205 () ;
V_109 = - V_297 ;
if ( F_206 ( & V_295 , V_293 , sizeof( struct V_294 ) ) )
goto V_298;
V_7 = F_207 ( V_84 , V_295 . V_299 ) ;
V_109 = - V_115 ;
if ( V_7 == NULL )
goto V_298;
#if F_40 ( V_61 ) || F_40 ( V_62 )
if ( V_7 -> type == V_63 ) {
const struct V_300 * V_301 = V_7 -> V_302 ;
struct V_303 V_304 ;
struct V_305 V_89 ;
V_109 = - V_114 ;
if ( ! ( F_78 ( & V_295 . V_306 ) & V_171 ) )
goto V_298;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_307 . V_200 = V_295 . V_306 . V_104 [ 3 ] ;
V_89 . V_307 . V_201 = 0 ;
V_89 . V_307 . V_308 = 4 ;
V_89 . V_307 . V_309 = 5 ;
V_89 . V_307 . V_310 = V_311 ;
V_89 . V_307 . V_312 = 64 ;
V_304 . V_313 . V_314 = ( V_103 void T_6 * ) & V_89 ;
if ( V_301 -> V_315 ) {
T_7 V_316 = F_208 () ;
F_209 ( V_317 ) ;
V_109 = V_301 -> V_315 ( V_7 , & V_304 , V_318 ) ;
F_209 ( V_316 ) ;
} else
V_109 = - V_319 ;
if ( V_109 == 0 ) {
V_109 = - V_123 ;
V_7 = F_210 ( V_84 , V_89 . V_42 ) ;
if ( ! V_7 )
goto V_298;
V_109 = F_211 ( V_7 ) ;
}
}
#endif
V_298:
F_63 () ;
return V_109 ;
}
static int F_212 ( struct V_84 * V_84 , int V_142 , const struct V_102 * V_240 ,
unsigned int V_241 , T_8 V_320 , V_161 V_163 ,
V_161 V_138 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_107 ;
T_1 V_57 ;
T_5 V_24 ;
unsigned long V_321 ;
F_29 () ;
if ( V_241 > 128 )
return - V_296 ;
if ( ! V_138 || V_163 > V_138 )
return - V_296 ;
V_7 = F_207 ( V_84 , V_142 ) ;
if ( ! V_7 )
return - V_115 ;
V_5 = F_192 ( V_7 ) ;
if ( F_84 ( V_5 ) )
return F_85 ( V_5 ) ;
V_107 = F_213 ( V_240 ) ;
V_321 = F_107 ( V_138 , V_3 ) ;
if ( F_198 ( V_321 ) ) {
V_24 = F_200 ( V_321 * V_3 ) ;
V_138 = V_321 ;
V_57 = V_143 ;
} else {
V_24 = 0 ;
V_57 = 0 ;
V_320 |= V_136 ;
}
V_321 = F_107 ( V_163 , V_3 ) ;
if ( F_198 ( V_321 ) ) {
if ( V_321 == 0 )
V_320 |= V_185 ;
V_163 = V_321 ;
}
V_14 = F_77 ( V_5 , V_240 , V_241 , V_107 , V_320 ) ;
if ( ! F_84 ( V_14 ) ) {
F_98 ( & V_14 -> V_48 ) ;
V_14 -> V_138 = V_138 ;
V_14 -> V_163 = V_163 ;
V_14 -> V_76 = V_25 ;
F_99 ( & V_14 -> V_48 ) ;
F_182 ( & V_14 -> V_100 , V_14 -> V_126 , V_7 ,
V_24 , V_57 ) ;
F_120 ( V_14 ) ;
F_103 ( V_14 ) ;
F_202 ( 0 ) ;
return 0 ;
}
return F_85 ( V_14 ) ;
}
static int F_214 ( struct V_84 * V_84 , int V_142 , const struct V_102 * V_240 ,
unsigned int V_241 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_241 > 128 )
return - V_296 ;
V_7 = F_207 ( V_84 , V_142 ) ;
if ( ! V_7 )
return - V_115 ;
if ( ( V_5 = F_49 ( V_7 ) ) == NULL )
return - V_322 ;
F_133 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_126 == V_241 &&
F_124 ( V_240 , & V_14 -> V_100 ) ) {
F_11 ( V_14 ) ;
F_138 ( & V_5 -> V_48 ) ;
F_97 ( V_14 ) ;
if ( F_22 ( & V_5 -> V_39 ) )
F_215 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_138 ( & V_5 -> V_48 ) ;
return - V_114 ;
}
int F_216 ( struct V_84 * V_84 , void T_6 * V_293 )
{
struct V_294 V_295 ;
int V_109 ;
if ( ! F_217 ( V_323 ) )
return - V_324 ;
if ( F_206 ( & V_295 , V_293 , sizeof( struct V_294 ) ) )
return - V_297 ;
F_205 () ;
V_109 = F_212 ( V_84 , V_295 . V_299 , & V_295 . V_306 ,
V_295 . V_325 , V_136 ,
V_326 , V_326 ) ;
F_63 () ;
return V_109 ;
}
int F_218 ( struct V_84 * V_84 , void T_6 * V_293 )
{
struct V_294 V_295 ;
int V_109 ;
if ( ! F_217 ( V_323 ) )
return - V_324 ;
if ( F_206 ( & V_295 , V_293 , sizeof( struct V_294 ) ) )
return - V_297 ;
F_205 () ;
V_109 = F_214 ( V_84 , V_295 . V_299 , & V_295 . V_306 ,
V_295 . V_325 ) ;
F_63 () ;
return V_109 ;
}
static void F_219 ( struct V_4 * V_5 , const struct V_102 * V_100 ,
int V_241 , int V_107 )
{
struct V_13 * V_14 ;
V_14 = F_77 ( V_5 , V_100 , V_241 , V_107 , V_136 ) ;
if ( ! F_84 ( V_14 ) ) {
F_98 ( & V_14 -> V_48 ) ;
V_14 -> V_57 &= ~ V_83 ;
F_99 ( & V_14 -> V_48 ) ;
F_110 ( V_327 , V_14 ) ;
F_103 ( V_14 ) ;
}
}
static void F_220 ( struct V_4 * V_5 )
{
struct V_102 V_100 ;
struct V_6 * V_7 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
int V_107 ;
F_29 () ;
memset ( & V_100 , 0 , sizeof( struct V_102 ) ) ;
memcpy ( & V_100 . V_104 [ 3 ] , V_5 -> V_7 -> V_228 , 4 ) ;
if ( V_5 -> V_7 -> V_57 & V_258 ) {
V_100 . V_104 [ 0 ] = F_151 ( 0xfe800000 ) ;
V_107 = V_212 ;
} else {
V_107 = V_171 ;
}
if ( V_100 . V_104 [ 3 ] ) {
F_219 ( V_5 , & V_100 , 128 , V_107 ) ;
return;
}
F_221 (net, dev) {
struct V_328 * V_329 = F_222 ( V_7 ) ;
if ( V_329 && ( V_7 -> V_57 & V_81 ) ) {
struct V_330 * V_82 ;
int V_331 = V_107 ;
for ( V_82 = V_329 -> V_332 ; V_82 ; V_82 = V_82 -> V_333 ) {
int V_241 ;
V_100 . V_104 [ 3 ] = V_82 -> V_334 ;
if ( V_82 -> V_335 == V_336 )
continue;
if ( V_82 -> V_335 >= V_337 ) {
if ( V_5 -> V_7 -> V_57 & V_258 )
continue;
V_331 |= V_217 ;
}
if ( V_5 -> V_7 -> V_57 & V_258 )
V_241 = 64 ;
else
V_241 = 96 ;
F_219 ( V_5 , & V_100 , V_241 , V_331 ) ;
}
}
}
}
static void F_223 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_24 ( L_25 , V_41 ) ;
return;
}
F_219 ( V_5 , & V_338 , 128 , V_217 ) ;
}
static void F_224 ( struct V_4 * V_5 , const struct V_102 * V_100 )
{
struct V_13 * V_14 ;
T_1 V_154 = V_136 ;
#ifdef F_201
if ( V_5 -> V_49 . V_287 &&
! F_32 ( V_5 -> V_7 ) -> V_28 . V_92 -> V_55 )
V_154 |= V_168 ;
#endif
V_14 = F_77 ( V_5 , V_100 , 64 , V_212 , V_154 ) ;
if ( ! F_84 ( V_14 ) ) {
F_182 ( & V_14 -> V_100 , V_14 -> V_126 , V_5 -> V_7 , 0 , 0 ) ;
F_120 ( V_14 ) ;
F_103 ( V_14 ) ;
}
}
static void F_225 ( struct V_6 * V_7 )
{
struct V_102 V_100 ;
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_233 ) &&
( V_7 -> type != V_234 ) &&
( V_7 -> type != V_235 ) &&
( V_7 -> type != V_236 ) &&
( V_7 -> type != V_238 ) ) {
return;
}
V_5 = F_192 ( V_7 ) ;
if ( F_84 ( V_5 ) )
return;
memset ( & V_100 , 0 , sizeof( struct V_102 ) ) ;
V_100 . V_104 [ 0 ] = F_151 ( 0xFE800000 ) ;
if ( F_152 ( V_100 . V_156 + 8 , V_7 ) == 0 )
F_224 ( V_5 , & V_100 ) ;
}
static void F_226 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_24 ( L_25 , V_41 ) ;
return;
}
if ( V_7 -> V_64 & V_65 ) {
struct V_102 V_100 ;
F_189 ( & V_100 , F_151 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_182 ( & V_100 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_152 ( V_100 . V_156 + 8 , V_7 ) )
F_224 ( V_5 , & V_100 ) ;
return;
}
F_220 ( V_5 ) ;
if ( V_7 -> V_57 & V_258 ) {
F_188 ( V_7 ) ;
F_191 ( V_7 ) ;
} else
F_190 ( V_7 ) ;
}
static void F_227 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_102 V_100 ;
F_41 ( L_26 , V_41 , V_7 -> V_42 ) ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_24 ( L_25 , V_41 ) ;
return;
}
F_189 ( & V_100 , F_151 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_182 ( & V_100 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_152 ( V_100 . V_156 + 8 , V_7 ) )
F_224 ( V_5 , & V_100 ) ;
}
static inline int
F_228 ( struct V_4 * V_5 , struct V_6 * V_339 )
{
struct V_102 V_340 ;
if ( ! F_139 ( V_339 , & V_340 , V_83 ) ) {
F_224 ( V_5 , & V_340 ) ;
return 0 ;
}
return - 1 ;
}
static void F_229 ( struct V_4 * V_5 )
{
struct V_6 * V_339 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_341 &&
( V_339 = F_207 ( V_84 , V_5 -> V_7 -> V_341 ) ) ) {
if ( ! F_228 ( V_5 , V_339 ) )
return;
}
F_221 (net, link_dev) {
if ( ! F_228 ( V_5 , V_339 ) )
return;
}
F_24 ( L_27 ) ;
}
static void F_230 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_192 ( V_7 ) ;
if ( F_84 ( V_5 ) ) {
F_24 ( L_28 ) ;
return;
}
F_229 ( V_5 ) ;
}
static int F_231 ( struct V_342 * V_343 , unsigned long V_344 ,
void * V_125 )
{
struct V_6 * V_7 = (struct V_6 * ) V_125 ;
struct V_4 * V_5 = F_49 ( V_7 ) ;
int V_345 = 0 ;
int V_109 ;
switch ( V_344 ) {
case V_346 :
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! V_5 )
return F_232 ( - V_38 ) ;
}
break;
case V_131 :
case V_347 :
if ( V_7 -> V_57 & V_348 )
break;
if ( V_344 == V_131 ) {
if ( ! F_4 ( V_7 ) ) {
F_41 ( L_29 ,
V_7 -> V_42 ) ;
break;
}
if ( ! V_5 && V_7 -> V_46 >= V_47 )
V_5 = F_28 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_74 |= V_75 ;
V_345 = 1 ;
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
F_41 ( L_30 ,
V_7 -> V_42 ) ;
V_345 = 1 ;
}
switch ( V_7 -> type ) {
#if F_40 ( V_61 ) || F_40 ( V_62 )
case V_63 :
F_226 ( V_7 ) ;
break;
#endif
#if F_40 ( V_349 ) || F_40 ( V_350 )
case V_237 :
F_227 ( V_7 ) ;
break;
#endif
case V_71 :
F_230 ( V_7 ) ;
break;
case V_351 :
F_223 ( V_7 ) ;
break;
default:
F_225 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_345 )
F_233 ( V_5 ) ;
if ( V_5 -> V_49 . V_51 != V_7 -> V_46 &&
V_7 -> V_46 >= V_47 ) {
F_234 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
}
V_5 -> V_76 = V_25 ;
F_235 ( V_352 , V_5 ) ;
if ( V_7 -> V_46 < V_47 )
F_215 ( V_7 , 1 ) ;
}
break;
case V_353 :
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
case V_140 :
case V_354 :
F_215 ( V_7 , V_344 != V_140 ) ;
break;
case V_355 :
if ( V_5 ) {
F_236 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_109 = F_38 ( V_5 ) ;
if ( V_109 )
return F_232 ( V_109 ) ;
}
break;
case V_356 :
case V_357 :
F_237 ( V_7 , V_344 ) ;
break;
}
return V_358 ;
}
static void F_237 ( struct V_6 * V_7 , unsigned long V_344 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_344 == V_357 )
F_238 ( V_5 ) ;
else if ( V_344 == V_356 )
F_239 ( V_5 ) ;
}
static int F_215 ( struct V_6 * V_7 , int V_359 )
{
struct V_84 * V_84 = F_32 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_95 , V_175 ;
F_29 () ;
F_240 ( V_84 , V_7 ) ;
F_241 ( & V_54 , V_7 ) ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 == NULL )
return - V_115 ;
if ( V_359 ) {
V_5 -> V_43 = 1 ;
F_242 ( V_7 -> V_77 , NULL ) ;
F_236 ( V_5 ) ;
}
for ( V_175 = 0 ; V_175 < V_105 ; V_175 ++ ) {
struct V_360 * V_361 = & V_127 [ V_175 ] ;
struct V_215 * V_362 ;
F_98 ( & V_119 ) ;
V_363:
F_141 (ifa, n, h, addr_lst) {
if ( V_82 -> V_5 == V_5 ) {
F_100 ( & V_82 -> V_94 ) ;
F_7 ( V_82 ) ;
goto V_363;
}
}
F_99 ( & V_119 ) ;
}
F_101 ( & V_5 -> V_48 ) ;
if ( ! V_359 )
V_5 -> V_74 &= ~ ( V_364 | V_365 | V_75 ) ;
#ifdef F_42
if ( V_359 && F_8 ( & V_5 -> V_68 ) )
F_67 ( V_5 ) ;
while ( ! F_22 ( & V_5 -> V_67 ) ) {
V_82 = F_243 ( & V_5 -> V_67 ,
struct V_13 , V_129 ) ;
F_102 ( & V_82 -> V_129 ) ;
F_109 ( & V_5 -> V_48 ) ;
F_98 ( & V_82 -> V_48 ) ;
if ( V_82 -> V_135 ) {
F_103 ( V_82 -> V_135 ) ;
V_82 -> V_135 = NULL ;
}
F_99 ( & V_82 -> V_48 ) ;
F_103 ( V_82 ) ;
F_101 ( & V_5 -> V_48 ) ;
}
#endif
while ( ! F_22 ( & V_5 -> V_39 ) ) {
V_82 = F_243 ( & V_5 -> V_39 ,
struct V_13 , V_101 ) ;
F_7 ( V_82 ) ;
F_102 ( & V_82 -> V_101 ) ;
F_109 ( & V_5 -> V_48 ) ;
F_98 ( & V_82 -> V_124 ) ;
V_95 = V_82 -> V_95 ;
V_82 -> V_95 = V_96 ;
F_99 ( & V_82 -> V_124 ) ;
if ( V_95 != V_96 ) {
F_244 ( V_139 , V_82 ) ;
F_96 ( & V_130 , V_140 , V_82 ) ;
}
F_103 ( V_82 ) ;
F_101 ( & V_5 -> V_48 ) ;
}
F_109 ( & V_5 -> V_48 ) ;
if ( V_359 )
F_245 ( V_5 ) ;
else
F_246 ( V_5 ) ;
V_5 -> V_76 = V_25 ;
if ( V_359 ) {
F_3 ( V_5 ) ;
F_37 ( & V_54 , V_5 -> V_53 ) ;
F_241 ( & V_54 , V_7 ) ;
F_67 ( V_5 ) ;
}
return 0 ;
}
static void V_23 ( unsigned long V_125 )
{
struct V_13 * V_14 = (struct V_13 * ) V_125 ;
struct V_4 * V_5 = V_14 -> V_5 ;
F_247 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_74 & V_75 ) )
goto V_121;
if ( V_5 -> V_49 . V_55 )
goto V_121;
if ( V_5 -> V_74 & V_365 )
goto V_121;
F_81 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_366 ++ < V_5 -> V_49 . V_66 ) {
F_10 ( V_14 , V_22 ,
( V_14 -> V_366 == V_5 -> V_49 . V_66 ) ?
V_5 -> V_49 . V_367 :
V_5 -> V_49 . V_368 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_248 ( V_5 -> V_7 , & V_14 -> V_100 , & V_80 ) ;
} else {
F_90 ( & V_14 -> V_48 ) ;
F_24 ( L_31 , V_5 -> V_7 -> V_42 ) ;
}
V_121:
F_249 ( & V_5 -> V_48 ) ;
F_103 ( V_14 ) ;
}
static void F_250 ( struct V_13 * V_14 )
{
unsigned long V_369 ;
struct V_4 * V_5 = V_14 -> V_5 ;
if ( V_14 -> V_57 & V_168 )
V_369 = 0 ;
else
V_369 = F_251 () % ( V_5 -> V_49 . V_367 ? : 1 ) ;
V_14 -> V_366 = V_5 -> V_49 . V_166 ;
F_10 ( V_14 , V_19 , V_369 ) ;
}
static void F_120 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_153 ( V_7 , & V_14 -> V_100 ) ;
F_252 ( V_14 -> V_100 . V_104 [ 3 ] ) ;
F_133 ( & V_5 -> V_48 ) ;
F_81 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_95 == V_96 )
goto V_121;
if ( V_7 -> V_57 & ( V_58 | V_59 ) ||
V_5 -> V_49 . V_60 < 1 ||
! ( V_14 -> V_57 & V_83 ) ||
V_14 -> V_57 & V_370 ) {
V_14 -> V_57 &= ~ ( V_83 | V_168 | V_220 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_138 ( & V_5 -> V_48 ) ;
F_253 ( V_14 ) ;
return;
}
if ( ! ( V_5 -> V_74 & V_75 ) ) {
F_90 ( & V_14 -> V_48 ) ;
F_138 ( & V_5 -> V_48 ) ;
F_11 ( V_14 ) ;
F_147 ( V_14 , 0 ) ;
return;
}
if ( V_14 -> V_57 & V_168 )
F_254 ( V_14 -> V_9 ) ;
F_250 ( V_14 ) ;
V_121:
F_90 ( & V_14 -> V_48 ) ;
F_138 ( & V_5 -> V_48 ) ;
}
static void V_21 ( unsigned long V_125 )
{
struct V_13 * V_14 = (struct V_13 * ) V_125 ;
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_102 V_371 ;
if ( ! V_14 -> V_366 && F_148 ( V_14 ) )
goto V_121;
F_247 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_74 & V_75 ) ) {
F_249 ( & V_5 -> V_48 ) ;
goto V_121;
}
F_81 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_95 == V_96 ) {
F_90 ( & V_14 -> V_48 ) ;
F_249 ( & V_5 -> V_48 ) ;
goto V_121;
}
if ( V_14 -> V_366 == 0 ) {
V_14 -> V_57 &= ~ ( V_83 | V_168 | V_220 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_249 ( & V_5 -> V_48 ) ;
F_253 ( V_14 ) ;
goto V_121;
}
V_14 -> V_366 -- ;
F_10 ( V_14 , V_19 , V_14 -> V_5 -> V_53 -> V_167 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_249 ( & V_5 -> V_48 ) ;
F_154 ( & V_14 -> V_100 , & V_371 ) ;
F_255 ( V_14 -> V_5 -> V_7 , NULL , & V_14 -> V_100 , & V_371 , & V_372 ) ;
V_121:
F_103 ( V_14 ) ;
}
static void F_253 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = V_14 -> V_5 -> V_7 ;
F_110 ( V_327 , V_14 ) ;
if ( ( ( V_14 -> V_5 -> V_49 . V_373 == 1 && ! V_14 -> V_5 -> V_49 . V_55 ) ||
V_14 -> V_5 -> V_49 . V_373 == 2 ) &&
V_14 -> V_5 -> V_49 . V_66 > 0 &&
( V_7 -> V_57 & V_59 ) == 0 &&
( F_78 ( & V_14 -> V_100 ) & V_276 ) ) {
F_248 ( V_14 -> V_5 -> V_7 , & V_14 -> V_100 , & V_80 ) ;
F_98 ( & V_14 -> V_48 ) ;
V_14 -> V_366 = 1 ;
V_14 -> V_5 -> V_74 |= V_364 ;
F_10 ( V_14 , V_22 , V_14 -> V_5 -> V_49 . V_368 ) ;
F_99 ( & V_14 -> V_48 ) ;
}
}
static void F_233 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
F_133 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
F_81 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_57 & V_83 &&
V_14 -> V_95 == V_222 )
F_250 ( V_14 ) ;
F_90 ( & V_14 -> V_48 ) ;
}
F_138 ( & V_5 -> V_48 ) ;
}
static struct V_13 * F_256 ( struct V_374 * V_375 , T_9 V_376 )
{
struct V_13 * V_82 = NULL ;
struct V_377 * V_95 = V_375 -> V_378 ;
struct V_84 * V_84 = F_257 ( V_375 ) ;
int V_89 = 0 ;
if ( V_376 == 0 ) {
V_95 -> V_379 = 0 ;
V_95 -> V_380 = 0 ;
}
for (; V_95 -> V_379 < V_105 ; ++ V_95 -> V_379 ) {
struct V_215 * V_362 ;
F_146 (ifa, n, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( V_89 < V_95 -> V_380 ) {
V_89 ++ ;
continue;
}
V_95 -> V_380 ++ ;
if ( F_142 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_84 ) )
return V_82 ;
}
V_95 -> V_380 = 0 ;
V_89 = 0 ;
}
return NULL ;
}
static struct V_13 * F_258 ( struct V_374 * V_375 ,
struct V_13 * V_82 )
{
struct V_377 * V_95 = V_375 -> V_378 ;
struct V_84 * V_84 = F_257 ( V_375 ) ;
struct V_215 * V_362 = & V_82 -> V_94 ;
F_259 (ifa, n, addr_lst) {
V_95 -> V_380 ++ ;
if ( F_142 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_84 ) )
return V_82 ;
}
while ( ++ V_95 -> V_379 < V_105 ) {
V_95 -> V_380 = 0 ;
F_146 (ifa, n,
&inet6_addr_lst[state->bucket], addr_lst) {
V_95 -> V_380 ++ ;
if ( F_142 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_84 ) )
return V_82 ;
}
}
return NULL ;
}
static void * F_260 ( struct V_374 * V_375 , T_9 * V_376 )
__acquires( T_10 )
{
F_80 () ;
return F_256 ( V_375 , * V_376 ) ;
}
static void * F_261 ( struct V_374 * V_375 , void * V_381 , T_9 * V_376 )
{
struct V_13 * V_82 ;
V_82 = F_258 ( V_375 , V_381 ) ;
++ * V_376 ;
return V_82 ;
}
static void F_262 ( struct V_374 * V_375 , void * V_381 )
__releases( T_10 )
{
F_94 () ;
}
static int F_263 ( struct V_374 * V_375 , void * V_381 )
{
struct V_13 * V_14 = (struct V_13 * ) V_381 ;
F_264 ( V_375 , L_32 ,
& V_14 -> V_100 ,
V_14 -> V_5 -> V_7 -> V_142 ,
V_14 -> V_126 ,
V_14 -> V_107 ,
V_14 -> V_57 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
return 0 ;
}
static int F_265 ( struct V_382 * V_382 , struct V_383 * V_383 )
{
return F_266 ( V_382 , V_383 , & V_384 ,
sizeof( struct V_377 ) ) ;
}
static int T_11 F_267 ( struct V_84 * V_84 )
{
if ( ! F_268 ( V_84 , L_33 , V_385 , & V_386 ) )
return - V_38 ;
return 0 ;
}
static void T_12 F_269 ( struct V_84 * V_84 )
{
F_270 ( V_84 , L_33 ) ;
}
int T_13 F_271 ( void )
{
return F_272 ( & V_387 ) ;
}
void F_273 ( void )
{
F_274 ( & V_387 ) ;
}
int F_275 ( struct V_84 * V_84 , const struct V_102 * V_100 )
{
int V_152 = 0 ;
struct V_13 * V_14 = NULL ;
struct V_215 * V_362 ;
unsigned int V_108 = F_75 ( V_100 ) ;
F_80 () ;
F_146 (ifp, n, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_142 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_124 ( & V_14 -> V_100 , V_100 ) &&
( V_14 -> V_57 & V_190 ) ) {
V_152 = 1 ;
break;
}
}
F_94 () ;
return V_152 ;
}
static void F_202 ( unsigned long V_388 )
{
unsigned long V_155 , V_389 , V_390 , V_391 ;
struct V_13 * V_14 ;
struct V_215 * V_216 ;
int V_175 ;
F_80 () ;
F_81 ( & V_392 ) ;
V_155 = V_25 ;
V_389 = F_276 ( V_155 + V_393 ) ;
F_8 ( & V_394 ) ;
for ( V_175 = 0 ; V_175 < V_105 ; V_175 ++ ) {
V_363:
F_146 (ifp, node,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_149 ;
if ( V_14 -> V_57 & V_136 )
continue;
F_81 ( & V_14 -> V_48 ) ;
V_149 = ( V_155 - V_14 -> V_76 + V_395 ) / V_3 ;
if ( V_14 -> V_138 != V_326 &&
V_149 >= V_14 -> V_138 ) {
F_90 ( & V_14 -> V_48 ) ;
F_11 ( V_14 ) ;
F_97 ( V_14 ) ;
goto V_363;
} else if ( V_14 -> V_163 == V_326 ) {
F_90 ( & V_14 -> V_48 ) ;
continue;
} else if ( V_149 >= V_14 -> V_163 ) {
int V_396 = 0 ;
if ( ! ( V_14 -> V_57 & V_185 ) ) {
V_396 = 1 ;
V_14 -> V_57 |= V_185 ;
}
if ( F_108 ( V_14 -> V_76 + V_14 -> V_138 * V_3 , V_389 ) )
V_389 = V_14 -> V_76 + V_14 -> V_138 * V_3 ;
F_90 ( & V_14 -> V_48 ) ;
if ( V_396 ) {
F_11 ( V_14 ) ;
F_110 ( 0 , V_14 ) ;
F_103 ( V_14 ) ;
goto V_363;
}
#ifdef F_42
} else if ( ( V_14 -> V_57 & V_128 ) &&
! ( V_14 -> V_57 & V_83 ) ) {
unsigned long V_150 = V_14 -> V_5 -> V_49 . V_159 *
V_14 -> V_5 -> V_49 . V_166 *
V_14 -> V_5 -> V_53 -> V_167 / V_3 ;
if ( V_149 >= V_14 -> V_163 - V_150 ) {
struct V_13 * V_135 = V_14 -> V_135 ;
if ( F_108 ( V_14 -> V_76 + V_14 -> V_163 * V_3 , V_389 ) )
V_389 = V_14 -> V_76 + V_14 -> V_163 * V_3 ;
if ( ! V_14 -> V_158 && V_135 ) {
V_14 -> V_158 ++ ;
F_11 ( V_14 ) ;
F_11 ( V_135 ) ;
F_90 ( & V_14 -> V_48 ) ;
F_81 ( & V_135 -> V_48 ) ;
V_135 -> V_158 = 0 ;
F_90 ( & V_135 -> V_48 ) ;
F_116 ( V_135 , V_14 ) ;
F_103 ( V_135 ) ;
F_103 ( V_14 ) ;
goto V_363;
}
} else if ( F_108 ( V_14 -> V_76 + V_14 -> V_163 * V_3 - V_150 * V_3 , V_389 ) )
V_389 = V_14 -> V_76 + V_14 -> V_163 * V_3 - V_150 * V_3 ;
F_90 ( & V_14 -> V_48 ) ;
#endif
} else {
if ( F_108 ( V_14 -> V_76 + V_14 -> V_163 * V_3 , V_389 ) )
V_389 = V_14 -> V_76 + V_14 -> V_163 * V_3 ;
F_90 ( & V_14 -> V_48 ) ;
}
}
}
V_390 = F_276 ( V_389 ) ;
V_391 = V_389 ;
if ( F_108 ( V_390 , V_389 + V_397 ) )
V_391 = V_390 ;
if ( F_108 ( V_391 , V_25 + V_398 ) )
V_391 = V_25 + V_398 ;
F_36 ( ( V_206 L_34 ,
V_155 , V_389 , V_390 , V_391 ) ) ;
V_394 . V_24 = V_391 ;
F_12 ( & V_394 ) ;
F_90 ( & V_392 ) ;
F_94 () ;
}
static struct V_102 * F_277 ( struct V_399 * V_100 , struct V_399 * V_400 )
{
struct V_102 * V_240 = NULL ;
if ( V_100 )
V_240 = F_278 ( V_100 ) ;
if ( V_400 ) {
if ( V_240 && F_279 ( V_400 , V_240 , sizeof( * V_240 ) ) )
V_240 = NULL ;
else
V_240 = F_278 ( V_400 ) ;
}
return V_240 ;
}
static int
F_280 ( struct V_401 * V_402 , struct V_403 * V_404 , void * V_293 )
{
struct V_84 * V_84 = F_281 ( V_402 -> V_405 ) ;
struct V_406 * V_407 ;
struct V_399 * V_408 [ V_409 + 1 ] ;
struct V_102 * V_240 ;
int V_109 ;
V_109 = F_282 ( V_404 , sizeof( * V_407 ) , V_408 , V_409 , V_410 ) ;
if ( V_109 < 0 )
return V_109 ;
V_407 = F_283 ( V_404 ) ;
V_240 = F_277 ( V_408 [ V_411 ] , V_408 [ V_412 ] ) ;
if ( V_240 == NULL )
return - V_296 ;
return F_214 ( V_84 , V_407 -> V_413 , V_240 , V_407 -> V_414 ) ;
}
static int F_284 ( struct V_13 * V_14 , T_3 V_320 ,
T_1 V_163 , T_1 V_138 )
{
T_1 V_57 ;
T_5 V_24 ;
unsigned long V_321 ;
if ( ! V_138 || ( V_163 > V_138 ) )
return - V_296 ;
V_321 = F_107 ( V_138 , V_3 ) ;
if ( F_198 ( V_321 ) ) {
V_24 = F_200 ( V_321 * V_3 ) ;
V_138 = V_321 ;
V_57 = V_143 ;
} else {
V_24 = 0 ;
V_57 = 0 ;
V_320 |= V_136 ;
}
V_321 = F_107 ( V_163 , V_3 ) ;
if ( F_198 ( V_321 ) ) {
if ( V_321 == 0 )
V_320 |= V_185 ;
V_163 = V_321 ;
}
F_98 ( & V_14 -> V_48 ) ;
V_14 -> V_57 = ( V_14 -> V_57 & ~ ( V_185 | V_136 | V_370 | V_190 ) ) | V_320 ;
V_14 -> V_76 = V_25 ;
V_14 -> V_138 = V_138 ;
V_14 -> V_163 = V_163 ;
F_99 ( & V_14 -> V_48 ) ;
if ( ! ( V_14 -> V_57 & V_83 ) )
F_110 ( 0 , V_14 ) ;
F_182 ( & V_14 -> V_100 , V_14 -> V_126 , V_14 -> V_5 -> V_7 ,
V_24 , V_57 ) ;
F_202 ( 0 ) ;
return 0 ;
}
static int
F_285 ( struct V_401 * V_402 , struct V_403 * V_404 , void * V_293 )
{
struct V_84 * V_84 = F_281 ( V_402 -> V_405 ) ;
struct V_406 * V_407 ;
struct V_399 * V_408 [ V_409 + 1 ] ;
struct V_102 * V_240 ;
struct V_13 * V_82 ;
struct V_6 * V_7 ;
T_1 V_138 = V_326 , V_415 = V_326 ;
T_3 V_320 ;
int V_109 ;
V_109 = F_282 ( V_404 , sizeof( * V_407 ) , V_408 , V_409 , V_410 ) ;
if ( V_109 < 0 )
return V_109 ;
V_407 = F_283 ( V_404 ) ;
V_240 = F_277 ( V_408 [ V_411 ] , V_408 [ V_412 ] ) ;
if ( V_240 == NULL )
return - V_296 ;
if ( V_408 [ V_416 ] ) {
struct V_417 * V_418 ;
V_418 = F_278 ( V_408 [ V_416 ] ) ;
V_138 = V_418 -> V_419 ;
V_415 = V_418 -> V_420 ;
} else {
V_415 = V_326 ;
V_138 = V_326 ;
}
V_7 = F_207 ( V_84 , V_407 -> V_413 ) ;
if ( V_7 == NULL )
return - V_115 ;
V_320 = V_407 -> V_320 & ( V_370 | V_190 ) ;
V_82 = F_145 ( V_84 , V_240 , V_7 , 1 ) ;
if ( V_82 == NULL ) {
return F_212 ( V_84 , V_407 -> V_413 , V_240 ,
V_407 -> V_414 , V_320 ,
V_415 , V_138 ) ;
}
if ( V_404 -> V_421 & V_422 ||
! ( V_404 -> V_421 & V_423 ) )
V_109 = - V_120 ;
else
V_109 = F_284 ( V_82 , V_320 , V_415 , V_138 ) ;
F_103 ( V_82 ) ;
return V_109 ;
}
static void F_286 ( struct V_403 * V_404 , T_3 V_424 , T_3 V_57 ,
T_3 V_107 , int V_142 )
{
struct V_406 * V_407 ;
V_407 = F_283 ( V_404 ) ;
V_407 -> V_425 = V_426 ;
V_407 -> V_414 = V_424 ;
V_407 -> V_320 = V_57 ;
V_407 -> V_335 = V_107 ;
V_407 -> V_413 = V_142 ;
}
static int F_287 ( struct V_401 * V_402 , unsigned long V_1 ,
unsigned long V_76 , T_1 V_427 , T_1 V_277 )
{
struct V_417 V_418 ;
V_418 . V_1 = F_1 ( V_1 ) ;
V_418 . V_76 = F_1 ( V_76 ) ;
V_418 . V_420 = V_427 ;
V_418 . V_419 = V_277 ;
return F_288 ( V_402 , V_416 , sizeof( V_418 ) , & V_418 ) ;
}
static inline int F_289 ( int V_335 )
{
if ( V_335 & V_217 )
return V_337 ;
else if ( V_335 & V_212 )
return V_336 ;
else if ( V_335 & V_428 )
return V_429 ;
else
return V_430 ;
}
static inline int F_290 ( void )
{
return F_291 ( sizeof( struct V_406 ) )
+ F_292 ( 16 )
+ F_292 ( sizeof( struct V_417 ) ) ;
}
static int F_293 ( struct V_401 * V_402 , struct V_13 * V_82 ,
T_1 V_431 , T_1 V_375 , int V_344 , unsigned int V_57 )
{
struct V_403 * V_404 ;
T_1 V_427 , V_277 ;
V_404 = F_294 ( V_402 , V_431 , V_375 , V_344 , sizeof( struct V_406 ) , V_57 ) ;
if ( V_404 == NULL )
return - V_432 ;
F_286 ( V_404 , V_82 -> V_126 , V_82 -> V_57 , F_289 ( V_82 -> V_107 ) ,
V_82 -> V_5 -> V_7 -> V_142 ) ;
if ( ! ( V_82 -> V_57 & V_136 ) ) {
V_427 = V_82 -> V_163 ;
V_277 = V_82 -> V_138 ;
if ( V_427 != V_326 ) {
long V_433 = ( V_25 - V_82 -> V_76 ) / V_3 ;
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
if ( F_288 ( V_402 , V_411 , 16 , & V_82 -> V_100 ) < 0 ||
F_287 ( V_402 , V_82 -> V_1 , V_82 -> V_76 , V_427 , V_277 ) < 0 ) {
F_295 ( V_402 , V_404 ) ;
return - V_432 ;
}
return F_296 ( V_402 , V_404 ) ;
}
static int F_297 ( struct V_401 * V_402 , struct V_434 * V_435 ,
T_1 V_431 , T_1 V_375 , int V_344 , T_14 V_57 )
{
struct V_403 * V_404 ;
T_3 V_107 = V_430 ;
int V_142 = V_435 -> V_5 -> V_7 -> V_142 ;
if ( F_213 ( & V_435 -> V_436 ) & V_428 )
V_107 = V_429 ;
V_404 = F_294 ( V_402 , V_431 , V_375 , V_344 , sizeof( struct V_406 ) , V_57 ) ;
if ( V_404 == NULL )
return - V_432 ;
F_286 ( V_404 , 128 , V_136 , V_107 , V_142 ) ;
if ( F_288 ( V_402 , V_437 , 16 , & V_435 -> V_436 ) < 0 ||
F_287 ( V_402 , V_435 -> V_438 , V_435 -> V_439 ,
V_326 , V_326 ) < 0 ) {
F_295 ( V_402 , V_404 ) ;
return - V_432 ;
}
return F_296 ( V_402 , V_404 ) ;
}
static int F_298 ( struct V_401 * V_402 , struct V_440 * V_441 ,
T_1 V_431 , T_1 V_375 , int V_344 , unsigned int V_57 )
{
struct V_403 * V_404 ;
T_3 V_107 = V_430 ;
int V_142 = V_441 -> V_442 -> V_7 -> V_142 ;
if ( F_213 ( & V_441 -> V_443 ) & V_428 )
V_107 = V_429 ;
V_404 = F_294 ( V_402 , V_431 , V_375 , V_344 , sizeof( struct V_406 ) , V_57 ) ;
if ( V_404 == NULL )
return - V_432 ;
F_286 ( V_404 , 128 , V_136 , V_107 , V_142 ) ;
if ( F_288 ( V_402 , V_444 , 16 , & V_441 -> V_443 ) < 0 ||
F_287 ( V_402 , V_441 -> V_445 , V_441 -> V_446 ,
V_326 , V_326 ) < 0 ) {
F_295 ( V_402 , V_404 ) ;
return - V_432 ;
}
return F_296 ( V_402 , V_404 ) ;
}
static int F_299 ( struct V_4 * V_5 , struct V_401 * V_402 ,
struct V_447 * V_448 , enum V_449 type ,
int V_450 , int * V_451 )
{
struct V_434 * V_435 ;
struct V_440 * V_441 ;
int V_109 = 1 ;
int V_452 = * V_451 ;
F_133 ( & V_5 -> V_48 ) ;
switch ( type ) {
case V_453 : {
struct V_13 * V_82 ;
F_53 (ifa, &idev->addr_list, if_list) {
if ( ++ V_452 < V_450 )
continue;
V_109 = F_293 ( V_402 , V_82 ,
F_300 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_327 ,
V_455 ) ;
if ( V_109 <= 0 )
break;
}
break;
}
case V_456 :
for ( V_435 = V_5 -> V_40 ; V_435 ;
V_435 = V_435 -> V_389 , V_452 ++ ) {
if ( V_452 < V_450 )
continue;
V_109 = F_297 ( V_402 , V_435 ,
F_300 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_457 ,
V_455 ) ;
if ( V_109 <= 0 )
break;
}
break;
case V_458 :
for ( V_441 = V_5 -> V_459 ; V_441 ;
V_441 = V_441 -> V_460 , V_452 ++ ) {
if ( V_452 < V_450 )
continue;
V_109 = F_298 ( V_402 , V_441 ,
F_300 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_461 ,
V_455 ) ;
if ( V_109 <= 0 )
break;
}
break;
default:
break;
}
F_138 ( & V_5 -> V_48 ) ;
* V_451 = V_452 ;
return V_109 ;
}
static int F_301 ( struct V_401 * V_402 , struct V_447 * V_448 ,
enum V_449 type )
{
struct V_84 * V_84 = F_281 ( V_402 -> V_405 ) ;
int V_361 , V_462 ;
int V_463 , V_452 ;
int V_464 , V_450 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_360 * V_465 ;
struct V_215 * V_216 ;
V_462 = V_448 -> args [ 0 ] ;
V_464 = V_463 = V_448 -> args [ 1 ] ;
V_450 = V_452 = V_448 -> args [ 2 ] ;
F_57 () ;
for ( V_361 = V_462 ; V_361 < V_466 ; V_361 ++ , V_464 = 0 ) {
V_463 = 0 ;
V_465 = & V_84 -> V_467 [ V_361 ] ;
F_141 (dev, node, head, index_hlist) {
if ( V_463 < V_464 )
goto V_468;
if ( V_361 > V_462 || V_463 > V_464 )
V_450 = 0 ;
V_452 = 0 ;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
goto V_468;
if ( F_299 ( V_5 , V_402 , V_448 , type ,
V_450 , & V_452 ) <= 0 )
goto V_469;
V_468:
V_463 ++ ;
}
}
V_469:
F_59 () ;
V_448 -> args [ 0 ] = V_361 ;
V_448 -> args [ 1 ] = V_463 ;
V_448 -> args [ 2 ] = V_452 ;
return V_402 -> V_271 ;
}
static int F_302 ( struct V_401 * V_402 , struct V_447 * V_448 )
{
enum V_449 type = V_453 ;
return F_301 ( V_402 , V_448 , type ) ;
}
static int F_303 ( struct V_401 * V_402 , struct V_447 * V_448 )
{
enum V_449 type = V_456 ;
return F_301 ( V_402 , V_448 , type ) ;
}
static int F_304 ( struct V_401 * V_402 , struct V_447 * V_448 )
{
enum V_449 type = V_458 ;
return F_301 ( V_402 , V_448 , type ) ;
}
static int F_305 ( struct V_401 * V_470 , struct V_403 * V_404 ,
void * V_293 )
{
struct V_84 * V_84 = F_281 ( V_470 -> V_405 ) ;
struct V_406 * V_407 ;
struct V_399 * V_408 [ V_409 + 1 ] ;
struct V_102 * V_100 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_13 * V_82 ;
struct V_401 * V_402 ;
int V_109 ;
V_109 = F_282 ( V_404 , sizeof( * V_407 ) , V_408 , V_409 , V_410 ) ;
if ( V_109 < 0 )
goto V_471;
V_100 = F_277 ( V_408 [ V_411 ] , V_408 [ V_412 ] ) ;
if ( V_100 == NULL ) {
V_109 = - V_296 ;
goto V_471;
}
V_407 = F_283 ( V_404 ) ;
if ( V_407 -> V_413 )
V_7 = F_207 ( V_84 , V_407 -> V_413 ) ;
V_82 = F_145 ( V_84 , V_100 , V_7 , 1 ) ;
if ( ! V_82 ) {
V_109 = - V_114 ;
goto V_471;
}
V_402 = F_306 ( F_290 () , V_33 ) ;
if ( ! V_402 ) {
V_109 = - V_123 ;
goto V_472;
}
V_109 = F_293 ( V_402 , V_82 , F_300 ( V_470 ) . V_431 ,
V_404 -> V_454 , V_327 , 0 ) ;
if ( V_109 < 0 ) {
F_21 ( V_109 == - V_432 ) ;
F_307 ( V_402 ) ;
goto V_472;
}
V_109 = F_308 ( V_402 , V_84 , F_300 ( V_470 ) . V_431 ) ;
V_472:
F_103 ( V_82 ) ;
V_471:
return V_109 ;
}
static void F_309 ( int V_344 , struct V_13 * V_82 )
{
struct V_401 * V_402 ;
struct V_84 * V_84 = F_32 ( V_82 -> V_5 -> V_7 ) ;
int V_109 = - V_123 ;
V_402 = F_306 ( F_290 () , V_122 ) ;
if ( V_402 == NULL )
goto V_471;
V_109 = F_293 ( V_402 , V_82 , 0 , 0 , V_344 , 0 ) ;
if ( V_109 < 0 ) {
F_21 ( V_109 == - V_432 ) ;
F_307 ( V_402 ) ;
goto V_471;
}
F_310 ( V_402 , V_84 , 0 , V_473 , NULL , V_122 ) ;
return;
V_471:
if ( V_109 < 0 )
F_311 ( V_84 , V_473 , V_109 ) ;
}
static inline void F_312 ( struct V_474 * V_49 ,
T_2 * V_475 , int V_476 )
{
F_313 ( V_476 < ( V_477 * 4 ) ) ;
memset ( V_475 , 0 , V_476 ) ;
V_475 [ V_478 ] = V_49 -> V_55 ;
V_475 [ V_479 ] = V_49 -> V_480 ;
V_475 [ V_481 ] = V_49 -> V_51 ;
V_475 [ V_482 ] = V_49 -> V_373 ;
V_475 [ V_483 ] = V_49 -> V_484 ;
V_475 [ V_485 ] = V_49 -> V_283 ;
V_475 [ V_486 ] = V_49 -> V_166 ;
V_475 [ V_487 ] = V_49 -> V_66 ;
V_475 [ V_488 ] =
F_314 ( V_49 -> V_368 ) ;
V_475 [ V_489 ] =
F_314 ( V_49 -> V_367 ) ;
V_475 [ V_490 ] = V_49 -> V_491 ;
#ifdef F_42
V_475 [ V_492 ] = V_49 -> V_73 ;
V_475 [ V_493 ] = V_49 -> V_162 ;
V_475 [ V_494 ] = V_49 -> V_164 ;
V_475 [ V_495 ] = V_49 -> V_159 ;
V_475 [ V_496 ] = V_49 -> V_165 ;
#endif
V_475 [ V_497 ] = V_49 -> V_153 ;
V_475 [ V_498 ] = V_49 -> V_499 ;
V_475 [ V_500 ] = V_49 -> V_501 ;
#ifdef F_315
V_475 [ V_502 ] = V_49 -> V_503 ;
V_475 [ V_504 ] =
F_314 ( V_49 -> V_505 ) ;
#ifdef F_316
V_475 [ V_506 ] = V_49 -> V_507 ;
#endif
#endif
V_475 [ V_508 ] = V_49 -> V_509 ;
V_475 [ V_510 ] = V_49 -> V_511 ;
#ifdef F_201
V_475 [ V_512 ] = V_49 -> V_287 ;
#endif
#ifdef F_317
V_475 [ V_513 ] = V_49 -> V_514 ;
#endif
V_475 [ V_515 ] = V_49 -> V_117 ;
V_475 [ V_516 ] = V_49 -> V_60 ;
V_475 [ V_517 ] = V_49 -> V_518 ;
}
static inline T_15 F_318 ( void )
{
return F_292 ( 4 )
+ F_292 ( sizeof( struct V_519 ) )
+ F_292 ( V_477 * 4 )
+ F_292 ( V_520 * 8 )
+ F_292 ( V_521 * 8 ) ;
}
static inline T_15 F_319 ( void )
{
return F_291 ( sizeof( struct V_522 ) )
+ F_292 ( V_523 )
+ F_292 ( V_524 )
+ F_292 ( 4 )
+ F_292 ( 4 )
+ F_292 ( F_318 () ) ;
}
static inline void F_320 ( T_16 * V_27 , T_17 * V_525 ,
int V_526 , int V_476 )
{
int V_175 ;
int V_527 = V_476 - sizeof( T_16 ) * V_526 ;
F_313 ( V_527 < 0 ) ;
F_321 ( V_526 , & V_27 [ 0 ] ) ;
for ( V_175 = 1 ; V_175 < V_526 ; V_175 ++ )
F_321 ( F_322 ( & V_525 [ V_175 ] ) , & V_27 [ V_175 ] ) ;
memset ( & V_27 [ V_526 ] , 0 , V_527 ) ;
}
static inline void F_323 ( T_16 * V_27 , void V_26 * * V_525 ,
int V_526 , int V_476 , T_15 V_528 )
{
int V_175 ;
int V_527 = V_476 - sizeof( T_16 ) * V_526 ;
F_313 ( V_527 < 0 ) ;
F_321 ( V_526 , & V_27 [ 0 ] ) ;
for ( V_175 = 1 ; V_175 < V_526 ; V_175 ++ )
F_321 ( F_324 ( V_525 , V_175 , V_528 ) , & V_27 [ V_175 ] ) ;
memset ( & V_27 [ V_526 ] , 0 , V_527 ) ;
}
static void F_325 ( T_16 * V_27 , struct V_4 * V_5 , int V_529 ,
int V_476 )
{
switch ( V_529 ) {
case V_530 :
F_323 ( V_27 , ( void V_26 * * ) V_5 -> V_27 . V_28 ,
V_520 , V_476 , F_326 ( struct V_29 , V_531 ) ) ;
break;
case V_532 :
F_320 ( V_27 , V_5 -> V_27 . V_31 -> V_533 , V_521 , V_476 ) ;
break;
}
}
static int F_327 ( struct V_401 * V_402 , struct V_4 * V_5 )
{
struct V_399 * V_534 ;
struct V_519 V_418 ;
if ( F_328 ( V_402 , V_535 , V_5 -> V_74 ) )
goto V_536;
V_418 . V_537 = V_538 ;
V_418 . V_76 = F_1 ( V_5 -> V_76 ) ;
V_418 . V_539 = F_314 ( V_5 -> V_53 -> V_539 ) ;
V_418 . V_167 = F_314 ( V_5 -> V_53 -> V_167 ) ;
if ( F_288 ( V_402 , V_540 , sizeof( V_418 ) , & V_418 ) )
goto V_536;
V_534 = F_329 ( V_402 , V_541 , V_477 * sizeof( V_542 ) ) ;
if ( V_534 == NULL )
goto V_536;
F_312 ( & V_5 -> V_49 , F_278 ( V_534 ) , F_330 ( V_534 ) ) ;
V_534 = F_329 ( V_402 , V_530 , V_520 * sizeof( T_16 ) ) ;
if ( V_534 == NULL )
goto V_536;
F_325 ( F_278 ( V_534 ) , V_5 , V_530 , F_330 ( V_534 ) ) ;
V_534 = F_329 ( V_402 , V_532 , V_521 * sizeof( T_16 ) ) ;
if ( V_534 == NULL )
goto V_536;
F_325 ( F_278 ( V_534 ) , V_5 , V_532 , F_330 ( V_534 ) ) ;
return 0 ;
V_536:
return - V_432 ;
}
static T_15 F_331 ( const struct V_6 * V_7 )
{
if ( ! F_49 ( V_7 ) )
return 0 ;
return F_318 () ;
}
static int F_332 ( struct V_401 * V_402 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
return - V_543 ;
if ( F_327 ( V_402 , V_5 ) < 0 )
return - V_432 ;
return 0 ;
}
static int F_333 ( struct V_401 * V_402 , struct V_4 * V_5 ,
T_1 V_431 , T_1 V_375 , int V_344 , unsigned int V_57 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_522 * V_544 ;
struct V_403 * V_404 ;
void * V_545 ;
V_404 = F_294 ( V_402 , V_431 , V_375 , V_344 , sizeof( * V_544 ) , V_57 ) ;
if ( V_404 == NULL )
return - V_432 ;
V_544 = F_283 ( V_404 ) ;
V_544 -> V_546 = V_426 ;
V_544 -> V_547 = 0 ;
V_544 -> V_548 = V_7 -> type ;
V_544 -> V_549 = V_7 -> V_142 ;
V_544 -> V_550 = F_334 ( V_7 ) ;
V_544 -> V_551 = 0 ;
if ( F_335 ( V_402 , V_552 , V_7 -> V_42 ) ||
( V_7 -> V_226 &&
F_288 ( V_402 , V_553 , V_7 -> V_226 , V_7 -> V_228 ) ) ||
F_328 ( V_402 , V_554 , V_7 -> V_46 ) ||
( V_7 -> V_142 != V_7 -> V_341 &&
F_328 ( V_402 , V_555 , V_7 -> V_341 ) ) )
goto V_536;
V_545 = F_336 ( V_402 , V_556 ) ;
if ( V_545 == NULL )
goto V_536;
if ( F_327 ( V_402 , V_5 ) < 0 )
goto V_536;
F_337 ( V_402 , V_545 ) ;
return F_296 ( V_402 , V_404 ) ;
V_536:
F_295 ( V_402 , V_404 ) ;
return - V_432 ;
}
static int F_338 ( struct V_401 * V_402 , struct V_447 * V_448 )
{
struct V_84 * V_84 = F_281 ( V_402 -> V_405 ) ;
int V_361 , V_462 ;
int V_463 = 0 , V_464 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_360 * V_465 ;
struct V_215 * V_216 ;
V_462 = V_448 -> args [ 0 ] ;
V_464 = V_448 -> args [ 1 ] ;
F_57 () ;
for ( V_361 = V_462 ; V_361 < V_466 ; V_361 ++ , V_464 = 0 ) {
V_463 = 0 ;
V_465 = & V_84 -> V_467 [ V_361 ] ;
F_141 (dev, node, head, index_hlist) {
if ( V_463 < V_464 )
goto V_468;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
goto V_468;
if ( F_333 ( V_402 , V_5 ,
F_300 ( V_448 -> V_402 ) . V_431 ,
V_448 -> V_404 -> V_454 ,
V_352 , V_455 ) <= 0 )
goto V_121;
V_468:
V_463 ++ ;
}
}
V_121:
F_59 () ;
V_448 -> args [ 1 ] = V_463 ;
V_448 -> args [ 0 ] = V_361 ;
return V_402 -> V_271 ;
}
void F_235 ( int V_344 , struct V_4 * V_5 )
{
struct V_401 * V_402 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
int V_109 = - V_123 ;
V_402 = F_306 ( F_319 () , V_122 ) ;
if ( V_402 == NULL )
goto V_471;
V_109 = F_333 ( V_402 , V_5 , 0 , 0 , V_344 , 0 ) ;
if ( V_109 < 0 ) {
F_21 ( V_109 == - V_432 ) ;
F_307 ( V_402 ) ;
goto V_471;
}
F_310 ( V_402 , V_84 , 0 , V_557 , NULL , V_122 ) ;
return;
V_471:
if ( V_109 < 0 )
F_311 ( V_84 , V_557 , V_109 ) ;
}
static inline T_15 F_339 ( void )
{
return F_291 ( sizeof( struct V_558 ) )
+ F_292 ( sizeof( struct V_102 ) )
+ F_292 ( sizeof( struct V_559 ) ) ;
}
static int F_340 ( struct V_401 * V_402 , struct V_4 * V_5 ,
struct V_273 * V_274 , T_1 V_431 , T_1 V_375 ,
int V_344 , unsigned int V_57 )
{
struct V_558 * V_560 ;
struct V_403 * V_404 ;
struct V_559 V_418 ;
V_404 = F_294 ( V_402 , V_431 , V_375 , V_344 , sizeof( * V_560 ) , V_57 ) ;
if ( V_404 == NULL )
return - V_432 ;
V_560 = F_283 ( V_404 ) ;
V_560 -> V_561 = V_426 ;
V_560 -> V_562 = 0 ;
V_560 -> V_563 = 0 ;
V_560 -> V_564 = V_5 -> V_7 -> V_142 ;
V_560 -> V_126 = V_274 -> V_126 ;
V_560 -> V_565 = V_274 -> type ;
V_560 -> V_566 = 0 ;
V_560 -> V_567 = 0 ;
if ( V_274 -> V_134 )
V_560 -> V_567 |= V_568 ;
if ( V_274 -> V_283 )
V_560 -> V_567 |= V_569 ;
if ( F_288 ( V_402 , V_570 , sizeof( V_274 -> V_141 ) , & V_274 -> V_141 ) )
goto V_536;
V_418 . V_571 = F_194 ( V_274 -> V_278 ) ;
V_418 . V_572 = F_194 ( V_274 -> V_277 ) ;
if ( F_288 ( V_402 , V_573 , sizeof( V_418 ) , & V_418 ) )
goto V_536;
return F_296 ( V_402 , V_404 ) ;
V_536:
F_295 ( V_402 , V_404 ) ;
return - V_432 ;
}
static void F_203 ( int V_344 , struct V_4 * V_5 ,
struct V_273 * V_274 )
{
struct V_401 * V_402 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
int V_109 = - V_123 ;
V_402 = F_306 ( F_339 () , V_122 ) ;
if ( V_402 == NULL )
goto V_471;
V_109 = F_340 ( V_402 , V_5 , V_274 , 0 , 0 , V_344 , 0 ) ;
if ( V_109 < 0 ) {
F_21 ( V_109 == - V_432 ) ;
F_307 ( V_402 ) ;
goto V_471;
}
F_310 ( V_402 , V_84 , 0 , V_574 , NULL , V_122 ) ;
return;
V_471:
if ( V_109 < 0 )
F_311 ( V_84 , V_574 , V_109 ) ;
}
static void F_244 ( int V_344 , struct V_13 * V_14 )
{
F_309 ( V_344 ? : V_327 , V_14 ) ;
switch ( V_344 ) {
case V_327 :
if ( ! ( V_14 -> V_9 -> V_575 ) )
F_254 ( V_14 -> V_9 ) ;
if ( V_14 -> V_5 -> V_49 . V_55 )
F_54 ( V_14 ) ;
break;
case V_139 :
if ( V_14 -> V_5 -> V_49 . V_55 )
F_55 ( V_14 ) ;
F_155 ( V_14 -> V_5 , & V_14 -> V_100 ) ;
F_187 ( & V_14 -> V_9 -> V_97 ) ;
if ( F_113 ( V_14 -> V_9 ) )
F_341 ( & V_14 -> V_9 -> V_97 ) ;
break;
}
}
static void F_110 ( int V_344 , struct V_13 * V_14 )
{
F_80 () ;
if ( F_95 ( V_14 -> V_5 -> V_43 == 0 ) )
F_244 ( V_344 , V_14 ) ;
F_94 () ;
}
static
int F_342 ( V_87 * V_576 , int V_577 ,
void T_6 * V_578 , T_15 * V_579 , T_9 * V_580 )
{
int * V_581 = V_576 -> V_125 ;
int V_582 = * V_581 ;
T_9 V_376 = * V_580 ;
V_87 V_583 ;
int V_152 ;
V_583 = * V_576 ;
V_583 . V_125 = & V_582 ;
V_152 = F_343 ( & V_583 , V_577 , V_578 , V_579 , V_580 ) ;
if ( V_577 )
V_152 = F_60 ( V_576 , V_581 , V_582 ) ;
if ( V_152 )
* V_580 = V_376 ;
return V_152 ;
}
static void F_344 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_49 . V_117 )
F_231 ( NULL , V_140 , V_5 -> V_7 ) ;
else
F_231 ( NULL , V_131 , V_5 -> V_7 ) ;
}
static void F_345 ( struct V_84 * V_84 , T_2 V_85 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_57 () ;
F_58 (net, dev) {
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
int V_86 = ( ! V_5 -> V_49 . V_117 ) ^ ( ! V_85 ) ;
V_5 -> V_49 . V_117 = V_85 ;
if ( V_86 )
F_344 ( V_5 ) ;
}
}
F_59 () ;
}
static int F_346 ( struct V_87 * V_88 , int * V_89 , int V_85 )
{
struct V_84 * V_84 ;
int V_90 ;
if ( ! F_61 () )
return F_62 () ;
V_84 = (struct V_84 * ) V_88 -> V_91 ;
V_90 = * V_89 ;
* V_89 = V_85 ;
if ( V_89 == & V_84 -> V_28 . V_50 -> V_117 ) {
F_63 () ;
return 0 ;
}
if ( V_89 == & V_84 -> V_28 . V_92 -> V_117 ) {
V_84 -> V_28 . V_50 -> V_117 = V_85 ;
F_345 ( V_84 , V_85 ) ;
} else if ( ( ! V_85 ) ^ ( ! V_90 ) )
F_344 ( (struct V_4 * ) V_88 -> V_93 ) ;
F_63 () ;
return 0 ;
}
static
int F_347 ( V_87 * V_576 , int V_577 ,
void T_6 * V_578 , T_15 * V_579 , T_9 * V_580 )
{
int * V_581 = V_576 -> V_125 ;
int V_582 = * V_581 ;
T_9 V_376 = * V_580 ;
V_87 V_583 ;
int V_152 ;
V_583 = * V_576 ;
V_583 . V_125 = & V_582 ;
V_152 = F_343 ( & V_583 , V_577 , V_578 , V_579 , V_580 ) ;
if ( V_577 )
V_152 = F_346 ( V_576 , V_581 , V_582 ) ;
if ( V_152 )
* V_580 = V_376 ;
return V_152 ;
}
static int F_348 ( struct V_84 * V_84 , char * V_584 ,
struct V_4 * V_5 , struct V_474 * V_89 )
{
int V_175 ;
struct V_585 * V_586 ;
char V_587 [ sizeof( L_35 ) + V_523 ] ;
V_586 = F_349 ( & V_588 , sizeof( * V_586 ) , V_33 ) ;
if ( V_586 == NULL )
goto V_121;
for ( V_175 = 0 ; V_586 -> V_589 [ V_175 ] . V_125 ; V_175 ++ ) {
V_586 -> V_589 [ V_175 ] . V_125 += ( char * ) V_89 - ( char * ) & V_474 ;
V_586 -> V_589 [ V_175 ] . V_93 = V_5 ;
V_586 -> V_589 [ V_175 ] . V_91 = V_84 ;
}
snprintf ( V_587 , sizeof( V_587 ) , L_36 , V_584 ) ;
V_586 -> V_590 = F_350 ( V_84 , V_587 , V_586 -> V_589 ) ;
if ( V_586 -> V_590 == NULL )
goto free;
V_89 -> V_52 = V_586 ;
return 0 ;
free:
F_17 ( V_586 ) ;
V_121:
return - V_123 ;
}
static void F_351 ( struct V_474 * V_89 )
{
struct V_585 * V_586 ;
if ( V_89 -> V_52 == NULL )
return;
V_586 = V_89 -> V_52 ;
V_89 -> V_52 = NULL ;
F_352 ( V_586 -> V_590 ) ;
F_17 ( V_586 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_353 ( V_5 -> V_7 , V_5 -> V_53 , L_37 ,
& V_591 ) ;
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
int V_109 ;
struct V_474 * V_592 , * V_593 ;
V_109 = - V_38 ;
V_592 = & V_474 ;
V_593 = & V_594 ;
if ( ! F_142 ( V_84 , & V_595 ) ) {
V_592 = F_349 ( V_592 , sizeof( V_474 ) , V_33 ) ;
if ( V_592 == NULL )
goto V_596;
V_593 = F_349 ( V_593 , sizeof( V_594 ) , V_33 ) ;
if ( V_593 == NULL )
goto V_597;
} else {
V_593 -> V_283 = V_598 . V_283 ;
V_593 -> V_117 = V_598 . V_117 ;
}
V_84 -> V_28 . V_92 = V_592 ;
V_84 -> V_28 . V_50 = V_593 ;
#ifdef F_356
V_109 = F_348 ( V_84 , L_38 , NULL , V_592 ) ;
if ( V_109 < 0 )
goto V_599;
V_109 = F_348 ( V_84 , L_39 , NULL , V_593 ) ;
if ( V_109 < 0 )
goto V_600;
#endif
return 0 ;
#ifdef F_356
V_600:
F_351 ( V_592 ) ;
V_599:
F_17 ( V_593 ) ;
#endif
V_597:
F_17 ( V_592 ) ;
V_596:
return V_109 ;
}
static void T_12 F_357 ( struct V_84 * V_84 )
{
#ifdef F_356
F_351 ( V_84 -> V_28 . V_50 ) ;
F_351 ( V_84 -> V_28 . V_92 ) ;
#endif
if ( ! F_142 ( V_84 , & V_595 ) ) {
F_17 ( V_84 -> V_28 . V_50 ) ;
F_17 ( V_84 -> V_28 . V_92 ) ;
}
}
int F_358 ( struct V_342 * V_601 )
{
return F_359 ( & V_130 , V_601 ) ;
}
int F_360 ( struct V_342 * V_601 )
{
return F_361 ( & V_130 , V_601 ) ;
}
int T_13 F_362 ( void )
{
int V_175 , V_109 ;
V_109 = F_363 () ;
if ( V_109 < 0 ) {
F_364 ( L_40 ,
V_41 , V_109 ) ;
goto V_121;
}
V_109 = F_272 ( & V_602 ) ;
if ( V_109 < 0 )
goto V_603;
F_205 () ;
if ( ! F_28 ( V_595 . V_604 ) )
V_109 = - V_38 ;
F_63 () ;
if ( V_109 )
goto V_605;
for ( V_175 = 0 ; V_175 < V_105 ; V_175 ++ )
F_365 ( & V_127 [ V_175 ] ) ;
F_366 ( & V_606 ) ;
F_202 ( 0 ) ;
V_109 = F_367 ( & V_607 ) ;
if ( V_109 < 0 )
goto V_608;
V_109 = F_368 ( V_609 , V_610 , NULL , F_338 ,
NULL ) ;
if ( V_109 < 0 )
goto V_471;
F_368 ( V_609 , V_327 , F_285 , NULL , NULL ) ;
F_368 ( V_609 , V_139 , F_280 , NULL , NULL ) ;
F_368 ( V_609 , V_611 , F_305 ,
F_302 , NULL ) ;
F_368 ( V_609 , V_457 , NULL ,
F_303 , NULL ) ;
F_368 ( V_609 , V_461 , NULL ,
F_304 , NULL ) ;
F_369 () ;
return 0 ;
V_471:
F_370 ( & V_607 ) ;
V_608:
F_371 ( & V_606 ) ;
V_605:
F_274 ( & V_602 ) ;
V_603:
F_372 () ;
V_121:
return V_109 ;
}
void F_373 ( void )
{
struct V_6 * V_7 ;
int V_175 ;
F_371 ( & V_606 ) ;
F_274 ( & V_602 ) ;
F_372 () ;
F_205 () ;
F_374 ( & V_607 ) ;
F_221 (&init_net, dev) {
if ( F_49 ( V_7 ) == NULL )
continue;
F_215 ( V_7 , 1 ) ;
}
F_215 ( V_595 . V_604 , 2 ) ;
F_98 ( & V_119 ) ;
for ( V_175 = 0 ; V_175 < V_105 ; V_175 ++ )
F_21 ( ! F_375 ( & V_127 [ V_175 ] ) ) ;
F_99 ( & V_119 ) ;
F_8 ( & V_394 ) ;
F_63 () ;
}
