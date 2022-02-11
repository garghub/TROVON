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
F_110 ( & V_139 , & V_14 -> V_100 , V_14 -> V_124 ) ;
V_9 = F_111 ( V_84 , & V_139 , NULL , V_14 -> V_5 -> V_7 -> V_140 , 1 ) ;
if ( V_9 && F_6 ( V_9 ) ) {
if ( V_132 == 0 ) {
F_112 ( V_9 ) ;
V_9 = NULL ;
} else if ( ! ( V_9 -> V_10 & V_141 ) ) {
F_113 ( V_9 , V_24 ) ;
}
}
F_67 ( & V_9 -> V_97 ) ;
}
F_114 ( V_14 ) ;
V_119:
F_102 ( V_14 ) ;
}
static int F_115 ( struct V_13 * V_14 , struct V_13 * V_142 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_102 V_100 , * V_143 ;
unsigned long V_144 , V_145 , V_146 , V_147 ;
unsigned long V_148 ;
int V_149 ;
int V_150 = 0 ;
int V_151 ;
T_1 V_152 ;
unsigned long V_153 = V_25 ;
F_90 ( & V_5 -> V_48 ) ;
if ( V_142 ) {
F_97 ( & V_142 -> V_48 ) ;
memcpy ( & V_100 . V_154 [ 8 ] , & V_142 -> V_100 . V_154 [ 8 ] , 8 ) ;
F_98 ( & V_142 -> V_48 ) ;
V_143 = & V_100 ;
} else {
V_143 = NULL ;
}
V_155:
F_39 ( V_5 ) ;
if ( V_5 -> V_49 . V_73 <= 0 ) {
F_92 ( & V_5 -> V_48 ) ;
F_41 ( L_12 , V_41 ) ;
F_65 ( V_5 ) ;
V_150 = - 1 ;
goto V_119;
}
F_97 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_156 ++ >= V_5 -> V_49 . V_157 ) {
V_5 -> V_49 . V_73 = - 1 ;
F_98 ( & V_14 -> V_48 ) ;
F_92 ( & V_5 -> V_48 ) ;
F_26 ( L_13 ,
V_41 ) ;
F_65 ( V_5 ) ;
V_150 = - 1 ;
goto V_119;
}
F_11 ( V_14 ) ;
memcpy ( V_100 . V_154 , V_14 -> V_100 . V_154 , 8 ) ;
if ( F_116 ( V_5 , V_143 ) < 0 ) {
F_98 ( & V_14 -> V_48 ) ;
F_92 ( & V_5 -> V_48 ) ;
F_26 ( L_14 ,
V_41 ) ;
F_102 ( V_14 ) ;
F_65 ( V_5 ) ;
V_150 = - 1 ;
goto V_119;
}
memcpy ( & V_100 . V_154 [ 8 ] , V_5 -> V_158 , 8 ) ;
V_147 = ( V_153 - V_14 -> V_76 ) / V_3 ;
V_145 = F_117 ( V_159 ,
V_14 -> V_136 ,
V_5 -> V_49 . V_160 + V_147 ) ;
V_144 = F_117 ( V_159 ,
V_14 -> V_161 ,
V_5 -> V_49 . V_162 + V_147 -
V_5 -> V_49 . V_163 ) ;
V_149 = V_14 -> V_124 ;
V_151 = V_5 -> V_49 . V_151 ;
V_146 = V_14 -> V_76 ;
F_98 ( & V_14 -> V_48 ) ;
V_148 = V_5 -> V_49 . V_157 *
V_5 -> V_49 . V_164 *
V_5 -> V_53 -> V_165 / V_3 ;
F_92 ( & V_5 -> V_48 ) ;
if ( V_144 <= V_148 ) {
F_102 ( V_14 ) ;
F_65 ( V_5 ) ;
V_150 = - 1 ;
goto V_119;
}
V_152 = V_126 ;
if ( V_14 -> V_57 & V_166 )
V_152 |= V_166 ;
V_142 = ! V_151 ||
F_118 ( V_5 ) < V_151 ?
F_76 ( V_5 , & V_100 , V_149 ,
F_77 ( & V_100 ) & V_167 ,
V_152 ) : NULL ;
if ( ! V_142 || F_83 ( V_142 ) ) {
F_102 ( V_14 ) ;
F_65 ( V_5 ) ;
F_41 ( L_15 , V_41 ) ;
V_143 = & V_100 ;
F_90 ( & V_5 -> V_48 ) ;
goto V_155;
}
F_97 ( & V_142 -> V_48 ) ;
V_142 -> V_133 = V_14 ;
V_142 -> V_136 = V_145 ;
V_142 -> V_161 = V_144 ;
V_142 -> V_1 = V_153 ;
V_142 -> V_76 = V_146 ;
F_98 ( & V_142 -> V_48 ) ;
F_119 ( V_142 ) ;
F_102 ( V_142 ) ;
F_65 ( V_5 ) ;
V_119:
return V_150 ;
}
static inline int F_120 ( int type )
{
if ( type & ( V_168 | V_169 | V_111 ) )
return 1 ;
return 0 ;
}
static int F_121 ( struct V_84 * V_84 ,
struct V_170 * V_171 ,
struct V_172 * V_97 ,
int V_173 )
{
int V_150 ;
if ( V_173 <= V_171 -> V_174 ) {
switch ( V_173 ) {
case V_175 :
V_150 = V_171 -> V_176 ;
break;
case V_177 :
V_150 = V_171 -> V_178 ;
break;
default:
V_150 = ! ! F_122 ( V_173 , V_171 -> V_179 ) ;
}
goto V_119;
}
switch ( V_173 ) {
case V_180 :
V_150 = ! ! V_171 -> V_82 ;
break;
case V_181 :
V_150 = F_123 ( & V_171 -> V_82 -> V_100 , V_97 -> V_100 ) ;
break;
case V_175 :
V_150 = F_124 ( V_171 -> V_108 ) ;
if ( V_150 >= V_97 -> V_105 )
V_150 = - V_150 ;
else
V_150 -= 128 ;
V_171 -> V_176 = V_150 ;
break;
case V_182 :
V_150 = F_120 ( V_171 -> V_108 ) ||
! ( V_171 -> V_82 -> V_57 & ( V_183 | V_166 ) ) ;
break;
#ifdef F_125
case V_184 :
{
int V_185 = ! ( V_97 -> V_186 & V_187 ) ;
V_150 = ! ( V_171 -> V_82 -> V_57 & V_188 ) ^ V_185 ;
break;
}
#endif
case V_189 :
V_150 = ( ! V_97 -> V_140 ||
V_97 -> V_140 == V_171 -> V_82 -> V_5 -> V_7 -> V_140 ) ;
break;
case V_190 :
V_150 = F_126 ( V_84 ,
& V_171 -> V_82 -> V_100 , V_171 -> V_108 ,
V_171 -> V_82 -> V_5 -> V_7 -> V_140 ) == V_97 -> V_191 ;
break;
#ifdef F_42
case V_192 :
{
int V_193 = V_97 -> V_186 & ( V_194 | V_195 ) ?
! ! ( V_97 -> V_186 & V_195 ) :
V_171 -> V_82 -> V_5 -> V_49 . V_73 >= 2 ;
V_150 = ( ! ( V_171 -> V_82 -> V_57 & V_126 ) ) ^ V_193 ;
break;
}
#endif
case V_196 :
V_150 = ! ( F_127 ( & V_171 -> V_82 -> V_100 ) ^
F_127 ( V_97 -> V_100 ) ) ;
break;
case V_177 :
V_171 -> V_178 = V_150 = F_128 ( & V_171 -> V_82 -> V_100 ,
V_97 -> V_100 ) ;
break;
default:
V_150 = 0 ;
}
if ( V_150 )
F_129 ( V_173 , V_171 -> V_179 ) ;
V_171 -> V_174 = V_173 ;
V_119:
return V_150 ;
}
int F_130 ( struct V_84 * V_84 , struct V_6 * V_197 ,
const struct V_102 * V_198 , unsigned int V_186 ,
struct V_102 * V_199 )
{
struct V_170 V_200 [ 2 ] ,
* V_171 = & V_200 [ 0 ] , * V_201 = & V_200 [ 1 ] ;
struct V_172 V_97 ;
struct V_6 * V_7 ;
int V_202 ;
V_202 = F_131 ( V_198 ) ;
V_97 . V_100 = V_198 ;
V_97 . V_140 = V_197 ? V_197 -> V_140 : 0 ;
V_97 . V_105 = F_124 ( V_202 ) ;
V_97 . V_191 = F_126 ( V_84 , V_198 , V_202 , V_97 . V_140 ) ;
V_97 . V_186 = V_186 ;
V_201 -> V_174 = - 1 ;
V_201 -> V_82 = NULL ;
F_132 () ;
F_133 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_202 & V_110 ) ||
V_97 . V_105 <= V_203 ) &&
V_97 . V_140 && V_7 -> V_140 != V_97 . V_140 )
continue;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
continue;
F_134 ( & V_5 -> V_48 ) ;
F_53 (score->ifa, &idev->addr_list, if_list) {
int V_173 ;
if ( ( V_171 -> V_82 -> V_57 & V_83 ) &&
( ! ( V_171 -> V_82 -> V_57 & V_166 ) ) )
continue;
V_171 -> V_108 = F_131 ( & V_171 -> V_82 -> V_100 ) ;
if ( F_135 ( V_171 -> V_108 == V_109 ||
V_171 -> V_108 & V_110 ) ) {
F_136 ( V_204
L_16
L_17 ,
V_7 -> V_42 ) ;
continue;
}
V_171 -> V_174 = - 1 ;
F_137 ( V_171 -> V_179 , V_205 ) ;
for ( V_173 = 0 ; V_173 < V_205 ; V_173 ++ ) {
int V_206 , V_207 ;
V_206 = F_121 ( V_84 , V_201 , & V_97 , V_173 ) ;
V_207 = F_121 ( V_84 , V_171 , & V_97 , V_173 ) ;
if ( V_206 > V_207 ) {
if ( V_173 == V_175 &&
V_171 -> V_176 > 0 ) {
goto V_208;
}
break;
} else if ( V_206 < V_207 ) {
if ( V_201 -> V_82 )
F_102 ( V_201 -> V_82 ) ;
F_11 ( V_171 -> V_82 ) ;
F_138 ( V_201 , V_171 ) ;
V_171 -> V_82 = V_201 -> V_82 ;
break;
}
}
}
V_208:
F_139 ( & V_5 -> V_48 ) ;
}
F_140 () ;
if ( ! V_201 -> V_82 )
return - V_112 ;
* V_199 = V_201 -> V_82 -> V_100 ;
F_102 ( V_201 -> V_82 ) ;
return 0 ;
}
int F_141 ( struct V_6 * V_7 , struct V_102 * V_100 ,
unsigned char V_209 )
{
struct V_4 * V_5 ;
int V_107 = - V_112 ;
F_132 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 ) {
struct V_13 * V_14 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_105 == V_210 &&
! ( V_14 -> V_57 & V_209 ) ) {
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
int V_211 = 0 ;
struct V_13 * V_14 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list)
V_211 ++ ;
F_139 ( & V_5 -> V_48 ) ;
return V_211 ;
}
int F_142 ( struct V_84 * V_84 , const struct V_102 * V_100 ,
struct V_6 * V_7 , int V_212 )
{
struct V_13 * V_14 ;
struct V_213 * V_214 ;
unsigned int V_106 = F_73 ( V_100 ) ;
F_79 () ;
F_143 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_144 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_123 ( & V_14 -> V_100 , V_100 ) &&
! ( V_14 -> V_57 & V_83 ) &&
( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_105 & ( V_210 | V_215 ) || V_212 ) ) ) {
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
struct V_213 * V_214 ;
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
struct V_6 * V_7 , int V_212 )
{
struct V_13 * V_14 , * V_216 = NULL ;
unsigned int V_106 = F_73 ( V_100 ) ;
struct V_213 * V_214 ;
F_79 () ;
F_148 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_144 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_123 ( & V_14 -> V_100 , V_100 ) ) {
if ( V_7 == NULL || V_14 -> V_5 -> V_7 == V_7 ||
! ( V_14 -> V_105 & ( V_210 | V_215 ) || V_212 ) ) {
V_216 = V_14 ;
F_11 ( V_14 ) ;
break;
}
}
}
F_93 () ;
return V_216 ;
}
static void F_149 ( struct V_13 * V_14 , int V_217 )
{
if ( V_14 -> V_57 & V_134 ) {
F_97 ( & V_14 -> V_48 ) ;
F_7 ( V_14 ) ;
V_14 -> V_57 |= V_83 ;
if ( V_217 )
V_14 -> V_57 |= V_218 ;
F_98 ( & V_14 -> V_48 ) ;
if ( V_217 )
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
int V_107 = - V_219 ;
F_80 ( & V_14 -> V_122 ) ;
if ( V_14 -> V_95 == V_220 ) {
V_14 -> V_95 = V_221 ;
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
F_152 ( L_18 ,
V_14 -> V_5 -> V_7 -> V_42 , & V_14 -> V_100 ) ;
if ( V_5 -> V_49 . V_60 > 1 && ! V_5 -> V_49 . V_115 ) {
struct V_102 V_100 ;
V_100 . V_222 [ 0 ] = F_153 ( 0xfe800000 ) ;
V_100 . V_222 [ 1 ] = 0 ;
if ( ! F_154 ( V_100 . V_154 + 8 , V_5 -> V_7 ) &&
F_123 ( & V_14 -> V_100 , & V_100 ) ) {
V_5 -> V_49 . V_115 = 1 ;
F_41 ( L_19 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
}
}
F_149 ( V_14 , 1 ) ;
}
void F_155 ( struct V_6 * V_7 , const struct V_102 * V_100 )
{
struct V_102 V_223 ;
if ( V_7 -> V_57 & ( V_59 | V_58 ) )
return;
F_156 ( V_100 , & V_223 ) ;
F_47 ( V_7 , & V_223 ) ;
}
void F_157 ( struct V_4 * V_5 , const struct V_102 * V_100 )
{
struct V_102 V_223 ;
if ( V_5 -> V_7 -> V_57 & ( V_59 | V_58 ) )
return;
F_156 ( V_100 , & V_223 ) ;
F_158 ( V_5 , & V_223 ) ;
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
static int F_162 ( T_3 * V_224 , struct V_6 * V_7 )
{
if ( V_7 -> V_225 != V_226 )
return - 1 ;
memcpy ( V_224 , V_7 -> V_227 , 3 ) ;
memcpy ( V_224 + 5 , V_7 -> V_227 + 3 , 3 ) ;
if ( V_7 -> V_228 ) {
V_224 [ 3 ] = ( V_7 -> V_228 >> 8 ) & 0xFF ;
V_224 [ 4 ] = V_7 -> V_228 & 0xFF ;
} else {
V_224 [ 3 ] = 0xFF ;
V_224 [ 4 ] = 0xFE ;
V_224 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_163 ( T_3 * V_224 , struct V_6 * V_7 )
{
if ( V_7 -> V_225 != V_229 )
return - 1 ;
memcpy ( V_224 , V_7 -> V_227 , 8 ) ;
return 0 ;
}
static int F_164 ( T_3 * V_224 , struct V_6 * V_7 )
{
if ( V_7 -> V_225 != V_230 )
return - 1 ;
memset ( V_224 , 0 , 7 ) ;
V_224 [ 7 ] = * ( T_3 * ) V_7 -> V_227 ;
return 0 ;
}
static int F_165 ( T_3 * V_224 , struct V_6 * V_7 )
{
if ( V_7 -> V_225 != V_231 )
return - 1 ;
memcpy ( V_224 , V_7 -> V_227 + 12 , 8 ) ;
V_224 [ 0 ] |= 2 ;
return 0 ;
}
static int F_166 ( T_3 * V_224 , T_4 V_100 )
{
if ( V_100 == 0 )
return - 1 ;
V_224 [ 0 ] = ( F_167 ( V_100 ) || F_168 ( V_100 ) ||
F_169 ( V_100 ) || F_170 ( V_100 ) ||
F_171 ( V_100 ) || F_172 ( V_100 ) ||
F_173 ( V_100 ) || F_174 ( V_100 ) ||
F_175 ( V_100 ) || F_176 ( V_100 ) ||
F_177 ( V_100 ) ) ? 0x00 : 0x02 ;
V_224 [ 1 ] = 0 ;
V_224 [ 2 ] = 0x5E ;
V_224 [ 3 ] = 0xFE ;
memcpy ( V_224 + 4 , & V_100 , 4 ) ;
return 0 ;
}
static int F_178 ( T_3 * V_224 , struct V_6 * V_7 )
{
if ( V_7 -> V_64 & V_65 )
return F_166 ( V_224 , * ( T_4 * ) V_7 -> V_227 ) ;
return - 1 ;
}
static int F_179 ( T_3 * V_224 , struct V_6 * V_7 )
{
return F_166 ( V_224 , * ( T_4 * ) V_7 -> V_227 ) ;
}
static int F_154 ( T_3 * V_224 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_232 :
case V_233 :
return F_162 ( V_224 , V_7 ) ;
case V_234 :
return F_164 ( V_224 , V_7 ) ;
case V_235 :
return F_165 ( V_224 , V_7 ) ;
case V_63 :
return F_178 ( V_224 , V_7 ) ;
case V_236 :
return F_179 ( V_224 , V_7 ) ;
case V_237 :
return F_163 ( V_224 , V_7 ) ;
}
return - 1 ;
}
static int F_180 ( T_3 * V_224 , struct V_4 * V_5 )
{
int V_107 = - 1 ;
struct V_13 * V_14 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_105 == V_210 && ! ( V_14 -> V_57 & V_83 ) ) {
memcpy ( V_224 , V_14 -> V_100 . V_154 + 8 , 8 ) ;
V_107 = 0 ;
break;
}
}
F_139 ( & V_5 -> V_48 ) ;
return V_107 ;
}
static int F_181 ( struct V_4 * V_5 )
{
V_238:
F_182 ( V_5 -> V_158 , sizeof( V_5 -> V_158 ) ) ;
V_5 -> V_158 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_158 [ 0 ] == 0xfd &&
( V_5 -> V_158 [ 1 ] & V_5 -> V_158 [ 2 ] & V_5 -> V_158 [ 3 ] & V_5 -> V_158 [ 4 ] & V_5 -> V_158 [ 5 ] & V_5 -> V_158 [ 6 ] ) == 0xff &&
( V_5 -> V_158 [ 7 ] & 0x80 ) )
goto V_238;
if ( ( V_5 -> V_158 [ 0 ] | V_5 -> V_158 [ 1 ] ) == 0 ) {
if ( V_5 -> V_158 [ 2 ] == 0x5e && V_5 -> V_158 [ 3 ] == 0xfe )
goto V_238;
if ( ( V_5 -> V_158 [ 2 ] | V_5 -> V_158 [ 3 ] | V_5 -> V_158 [ 4 ] | V_5 -> V_158 [ 5 ] | V_5 -> V_158 [ 6 ] | V_5 -> V_158 [ 7 ] ) == 0x00 )
goto V_238;
}
return 0 ;
}
static void V_69 ( unsigned long V_123 )
{
struct V_4 * V_5 = (struct V_4 * ) V_123 ;
unsigned long V_24 ;
F_79 () ;
F_100 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 )
goto V_119;
if ( F_181 ( V_5 ) < 0 )
goto V_119;
V_24 = V_25 +
V_5 -> V_49 . V_162 * V_3 -
V_5 -> V_49 . V_157 * V_5 -> V_49 . V_164 * V_5 -> V_53 -> V_165 -
V_5 -> V_49 . V_163 * V_3 ;
if ( F_107 ( V_24 , V_25 ) ) {
F_26 ( L_20 ,
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
static int F_116 ( struct V_4 * V_5 , struct V_102 * V_143 )
{
int V_150 = 0 ;
if ( V_143 && memcmp ( V_5 -> V_158 , & V_143 -> V_154 [ 8 ] , 8 ) == 0 )
V_150 = F_181 ( V_5 ) ;
return V_150 ;
}
static void
F_184 ( struct V_102 * V_239 , int V_240 , struct V_6 * V_7 ,
unsigned long V_24 , T_1 V_57 )
{
struct V_241 V_242 = {
. V_243 = V_244 ,
. V_245 = V_246 ,
. V_247 = V_7 -> V_140 ,
. V_248 = V_24 ,
. V_249 = V_240 ,
. V_250 = V_251 | V_57 ,
. V_252 . V_253 = F_32 ( V_7 ) ,
. V_254 = V_255 ,
} ;
V_242 . V_256 = * V_239 ;
#if F_40 ( V_61 ) || F_40 ( V_62 )
if ( V_7 -> type == V_63 && ( V_7 -> V_57 & V_257 ) )
V_242 . V_250 |= V_258 ;
#endif
F_185 ( & V_242 ) ;
}
static struct V_8 * F_186 ( const struct V_102 * V_239 ,
int V_240 ,
const struct V_6 * V_7 ,
T_1 V_57 , T_1 V_259 )
{
struct V_260 * V_261 ;
struct V_8 * V_9 = NULL ;
struct V_262 * V_88 ;
V_88 = F_187 ( F_32 ( V_7 ) , V_244 ) ;
if ( V_88 == NULL )
return NULL ;
F_100 ( & V_88 -> V_263 ) ;
V_261 = F_188 ( & V_88 -> V_264 , V_239 , V_240 , NULL , 0 ) ;
if ( ! V_261 )
goto V_119;
for ( V_9 = V_261 -> V_265 ; V_9 ; V_9 = V_9 -> V_97 . V_266 ) {
if ( V_9 -> V_97 . V_7 -> V_140 != V_7 -> V_140 )
continue;
if ( ( V_9 -> V_10 & V_57 ) != V_57 )
continue;
if ( ( V_259 != 0 ) && ( ( V_9 -> V_10 & V_57 ) != 0 ) )
continue;
F_189 ( & V_9 -> V_97 ) ;
break;
}
V_119:
F_108 ( & V_88 -> V_263 ) ;
return V_9 ;
}
static void F_190 ( struct V_6 * V_7 )
{
struct V_241 V_242 = {
. V_243 = V_267 ,
. V_245 = V_246 ,
. V_247 = V_7 -> V_140 ,
. V_249 = 8 ,
. V_250 = V_251 ,
. V_252 . V_253 = F_32 ( V_7 ) ,
} ;
F_191 ( & V_242 . V_256 , F_153 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_185 ( & V_242 ) ;
}
static void F_192 ( struct V_6 * V_7 )
{
struct V_241 V_242 = {
. V_243 = V_268 ,
. V_245 = V_246 ,
. V_247 = V_7 -> V_140 ,
. V_249 = 96 ,
. V_250 = V_251 | V_258 ,
. V_252 . V_253 = F_32 ( V_7 ) ,
} ;
F_185 ( & V_242 ) ;
}
static void F_193 ( struct V_6 * V_7 )
{
struct V_102 V_100 ;
F_191 ( & V_100 , F_153 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_184 ( & V_100 , 64 , V_7 , 0 , 0 ) ;
}
static struct V_4 * F_194 ( struct V_6 * V_7 )
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
F_193 ( V_7 ) ;
return V_5 ;
}
void F_195 ( struct V_6 * V_7 , T_3 * V_269 , int V_270 , bool V_271 )
{
struct V_272 * V_273 ;
V_159 V_136 ;
V_159 V_161 ;
int V_108 ;
struct V_4 * V_274 ;
struct V_84 * V_84 = F_32 ( V_7 ) ;
V_273 = (struct V_272 * ) V_269 ;
if ( V_270 < sizeof( struct V_272 ) ) {
F_36 ( ( L_21 ) ) ;
return;
}
V_108 = F_77 ( & V_273 -> V_139 ) ;
if ( V_108 & ( V_110 | V_275 ) )
return;
V_136 = F_196 ( V_273 -> V_276 ) ;
V_161 = F_196 ( V_273 -> V_277 ) ;
if ( V_161 > V_136 ) {
F_197 ( L_22 ) ;
return;
}
V_274 = F_198 ( V_7 ) ;
if ( V_274 == NULL ) {
F_199 ( L_23 ,
V_7 -> V_42 ) ;
return;
}
if ( V_273 -> V_132 ) {
struct V_8 * V_9 ;
unsigned long V_278 ;
if ( V_3 > V_279 )
V_278 = F_106 ( V_136 , V_3 ) ;
else
V_278 = F_106 ( V_136 , V_279 ) ;
if ( F_200 ( V_278 ) )
V_278 *= V_3 ;
V_9 = F_186 ( & V_273 -> V_139 ,
V_273 -> V_124 ,
V_7 ,
V_280 | V_281 ,
V_11 | V_12 ) ;
if ( V_9 ) {
if ( V_136 == 0 ) {
F_112 ( V_9 ) ;
V_9 = NULL ;
} else if ( F_200 ( V_278 ) ) {
F_113 ( V_9 , V_25 + V_278 ) ;
} else {
F_201 ( V_9 ) ;
}
} else if ( V_136 ) {
T_5 V_24 = 0 ;
int V_57 = V_280 | V_281 ;
if ( F_200 ( V_278 ) ) {
V_57 |= V_141 ;
V_24 = F_202 ( V_278 ) ;
}
F_184 ( & V_273 -> V_139 , V_273 -> V_124 ,
V_7 , V_24 , V_57 ) ;
}
if ( V_9 )
F_67 ( & V_9 -> V_97 ) ;
}
if ( V_273 -> V_282 && V_274 -> V_49 . V_282 ) {
struct V_13 * V_14 ;
struct V_102 V_100 ;
int V_283 = 0 , V_284 = 0 ;
if ( V_273 -> V_124 == 64 ) {
memcpy ( & V_100 , & V_273 -> V_139 , 8 ) ;
if ( F_154 ( V_100 . V_154 + 8 , V_7 ) &&
F_180 ( V_100 . V_154 + 8 , V_274 ) ) {
F_65 ( V_274 ) ;
return;
}
goto V_285;
}
F_199 ( L_24 ,
V_273 -> V_124 ) ;
F_65 ( V_274 ) ;
return;
V_285:
V_14 = F_147 ( V_84 , & V_100 , V_7 , 1 ) ;
if ( V_14 == NULL && V_136 ) {
int V_151 = V_274 -> V_49 . V_151 ;
T_1 V_152 = 0 ;
#ifdef F_203
if ( V_274 -> V_49 . V_286 &&
! V_84 -> V_28 . V_92 -> V_55 && V_271 )
V_152 = V_166 ;
#endif
if ( ! V_151 ||
F_118 ( V_274 ) < V_151 )
V_14 = F_76 ( V_274 , & V_100 , V_273 -> V_124 ,
V_108 & V_167 ,
V_152 ) ;
if ( ! V_14 || F_83 ( V_14 ) ) {
F_65 ( V_274 ) ;
return;
}
V_284 = V_283 = 1 ;
V_14 -> V_1 = V_25 ;
F_119 ( V_14 ) ;
}
if ( V_14 ) {
int V_57 ;
unsigned long V_153 ;
#ifdef F_42
struct V_13 * V_142 ;
#endif
T_1 V_287 ;
F_80 ( & V_14 -> V_48 ) ;
V_153 = V_25 ;
if ( V_14 -> V_136 > ( V_153 - V_14 -> V_76 ) / V_3 )
V_287 = V_14 -> V_136 - ( V_153 - V_14 -> V_76 ) / V_3 ;
else
V_287 = 0 ;
if ( ! V_284 && V_287 ) {
if ( V_136 > V_288 ||
V_136 > V_287 )
V_284 = 1 ;
else if ( V_287 <= V_288 ) {
if ( V_161 != V_14 -> V_161 ) {
V_136 = V_287 ;
V_284 = 1 ;
}
} else {
V_136 = V_288 ;
if ( V_136 < V_161 )
V_161 = V_136 ;
V_284 = 1 ;
}
}
if ( V_284 ) {
V_14 -> V_136 = V_136 ;
V_14 -> V_161 = V_161 ;
V_14 -> V_76 = V_153 ;
V_57 = V_14 -> V_57 ;
V_14 -> V_57 &= ~ V_183 ;
F_89 ( & V_14 -> V_48 ) ;
if ( ! ( V_57 & V_83 ) )
F_109 ( 0 , V_14 ) ;
} else
F_89 ( & V_14 -> V_48 ) ;
#ifdef F_42
F_134 ( & V_274 -> V_48 ) ;
F_53 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_147 , V_289 , V_290 ;
if ( V_14 != V_142 -> V_133 )
continue;
V_147 = ( V_153 - V_142 -> V_1 ) / V_3 ;
V_289 = V_274 -> V_49 . V_160 - V_147 ;
if ( V_289 < 0 )
V_289 = 0 ;
V_290 = V_274 -> V_49 . V_162 -
V_274 -> V_49 . V_163 -
V_147 ;
if ( V_290 < 0 )
V_290 = 0 ;
if ( V_136 > V_289 )
V_136 = V_289 ;
if ( V_161 > V_290 )
V_161 = V_290 ;
F_80 ( & V_142 -> V_48 ) ;
V_57 = V_142 -> V_57 ;
V_142 -> V_136 = V_136 ;
V_142 -> V_161 = V_161 ;
V_142 -> V_76 = V_153 ;
if ( V_161 > 0 )
V_142 -> V_57 &= ~ V_183 ;
F_89 ( & V_142 -> V_48 ) ;
if ( ! ( V_57 & V_83 ) )
F_109 ( 0 , V_142 ) ;
}
if ( ( V_283 || F_22 ( & V_274 -> V_67 ) ) && V_274 -> V_49 . V_73 > 0 ) {
F_139 ( & V_274 -> V_48 ) ;
F_115 ( V_14 , NULL ) ;
} else {
F_139 ( & V_274 -> V_48 ) ;
}
#endif
F_102 ( V_14 ) ;
F_204 ( 0 ) ;
}
}
F_205 ( V_291 , V_274 , V_273 ) ;
F_65 ( V_274 ) ;
}
int F_206 ( struct V_84 * V_84 , void T_6 * V_292 )
{
struct V_293 V_294 ;
struct V_6 * V_7 ;
int V_107 = - V_295 ;
F_207 () ;
V_107 = - V_296 ;
if ( F_208 ( & V_294 , V_292 , sizeof( struct V_293 ) ) )
goto V_297;
V_7 = F_209 ( V_84 , V_294 . V_298 ) ;
V_107 = - V_113 ;
if ( V_7 == NULL )
goto V_297;
#if F_40 ( V_61 ) || F_40 ( V_62 )
if ( V_7 -> type == V_63 ) {
const struct V_299 * V_300 = V_7 -> V_301 ;
struct V_302 V_303 ;
struct V_304 V_89 ;
V_107 = - V_112 ;
if ( ! ( F_77 ( & V_294 . V_305 ) & V_169 ) )
goto V_297;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_306 . V_198 = V_294 . V_305 . V_222 [ 3 ] ;
V_89 . V_306 . V_199 = 0 ;
V_89 . V_306 . V_307 = 4 ;
V_89 . V_306 . V_308 = 5 ;
V_89 . V_306 . V_309 = V_310 ;
V_89 . V_306 . V_311 = 64 ;
V_303 . V_312 . V_313 = ( V_314 void T_6 * ) & V_89 ;
if ( V_300 -> V_315 ) {
T_7 V_316 = F_210 () ;
F_211 ( V_317 ) ;
V_107 = V_300 -> V_315 ( V_7 , & V_303 , V_318 ) ;
F_211 ( V_316 ) ;
} else
V_107 = - V_319 ;
if ( V_107 == 0 ) {
V_107 = - V_121 ;
V_7 = F_212 ( V_84 , V_89 . V_42 ) ;
if ( ! V_7 )
goto V_297;
V_107 = F_213 ( V_7 ) ;
}
}
#endif
V_297:
F_61 () ;
return V_107 ;
}
static int F_214 ( struct V_84 * V_84 , int V_140 , const struct V_102 * V_239 ,
unsigned int V_240 , T_8 V_320 , V_159 V_161 ,
V_159 V_136 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_105 ;
T_1 V_57 ;
T_5 V_24 ;
unsigned long V_321 ;
F_29 () ;
if ( V_240 > 128 )
return - V_295 ;
if ( ! V_136 || V_161 > V_136 )
return - V_295 ;
V_7 = F_209 ( V_84 , V_140 ) ;
if ( ! V_7 )
return - V_113 ;
V_5 = F_194 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return F_84 ( V_5 ) ;
V_105 = F_215 ( V_239 ) ;
V_321 = F_106 ( V_136 , V_3 ) ;
if ( F_200 ( V_321 ) ) {
V_24 = F_202 ( V_321 * V_3 ) ;
V_136 = V_321 ;
V_57 = V_141 ;
} else {
V_24 = 0 ;
V_57 = 0 ;
V_320 |= V_134 ;
}
V_321 = F_106 ( V_161 , V_3 ) ;
if ( F_200 ( V_321 ) ) {
if ( V_321 == 0 )
V_320 |= V_183 ;
V_161 = V_321 ;
}
V_14 = F_76 ( V_5 , V_239 , V_240 , V_105 , V_320 ) ;
if ( ! F_83 ( V_14 ) ) {
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_136 = V_136 ;
V_14 -> V_161 = V_161 ;
V_14 -> V_76 = V_25 ;
F_98 ( & V_14 -> V_48 ) ;
F_184 ( & V_14 -> V_100 , V_14 -> V_124 , V_7 ,
V_24 , V_57 ) ;
F_119 ( V_14 ) ;
F_102 ( V_14 ) ;
F_204 ( 0 ) ;
return 0 ;
}
return F_84 ( V_14 ) ;
}
static int F_216 ( struct V_84 * V_84 , int V_140 , const struct V_102 * V_239 ,
unsigned int V_240 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_240 > 128 )
return - V_295 ;
V_7 = F_209 ( V_84 , V_140 ) ;
if ( ! V_7 )
return - V_113 ;
if ( ( V_5 = F_49 ( V_7 ) ) == NULL )
return - V_322 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
if ( V_14 -> V_124 == V_240 &&
F_123 ( V_239 , & V_14 -> V_100 ) ) {
F_11 ( V_14 ) ;
F_139 ( & V_5 -> V_48 ) ;
F_96 ( V_14 ) ;
if ( F_22 ( & V_5 -> V_39 ) )
F_217 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_139 ( & V_5 -> V_48 ) ;
return - V_112 ;
}
int F_218 ( struct V_84 * V_84 , void T_6 * V_292 )
{
struct V_293 V_294 ;
int V_107 ;
if ( ! F_219 ( V_323 ) )
return - V_324 ;
if ( F_208 ( & V_294 , V_292 , sizeof( struct V_293 ) ) )
return - V_296 ;
F_207 () ;
V_107 = F_214 ( V_84 , V_294 . V_298 , & V_294 . V_305 ,
V_294 . V_325 , V_134 ,
V_326 , V_326 ) ;
F_61 () ;
return V_107 ;
}
int F_220 ( struct V_84 * V_84 , void T_6 * V_292 )
{
struct V_293 V_294 ;
int V_107 ;
if ( ! F_219 ( V_323 ) )
return - V_324 ;
if ( F_208 ( & V_294 , V_292 , sizeof( struct V_293 ) ) )
return - V_296 ;
F_207 () ;
V_107 = F_216 ( V_84 , V_294 . V_298 , & V_294 . V_305 ,
V_294 . V_325 ) ;
F_61 () ;
return V_107 ;
}
static void F_221 ( struct V_4 * V_5 , const struct V_102 * V_100 ,
int V_240 , int V_105 )
{
struct V_13 * V_14 ;
V_14 = F_76 ( V_5 , V_100 , V_240 , V_105 , V_134 ) ;
if ( ! F_83 ( V_14 ) ) {
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_57 &= ~ V_83 ;
F_98 ( & V_14 -> V_48 ) ;
F_109 ( V_327 , V_14 ) ;
F_102 ( V_14 ) ;
}
}
static void F_222 ( struct V_4 * V_5 )
{
struct V_102 V_100 ;
struct V_6 * V_7 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
int V_105 ;
F_29 () ;
memset ( & V_100 , 0 , sizeof( struct V_102 ) ) ;
memcpy ( & V_100 . V_222 [ 3 ] , V_5 -> V_7 -> V_227 , 4 ) ;
if ( V_5 -> V_7 -> V_57 & V_257 ) {
V_100 . V_222 [ 0 ] = F_153 ( 0xfe800000 ) ;
V_105 = V_210 ;
} else {
V_105 = V_169 ;
}
if ( V_100 . V_222 [ 3 ] ) {
F_221 ( V_5 , & V_100 , 128 , V_105 ) ;
return;
}
F_57 (net, dev) {
struct V_328 * V_329 = F_223 ( V_7 ) ;
if ( V_329 && ( V_7 -> V_57 & V_81 ) ) {
struct V_330 * V_82 ;
int V_331 = V_105 ;
for ( V_82 = V_329 -> V_332 ; V_82 ; V_82 = V_82 -> V_333 ) {
int V_240 ;
V_100 . V_222 [ 3 ] = V_82 -> V_334 ;
if ( V_82 -> V_335 == V_336 )
continue;
if ( V_82 -> V_335 >= V_337 ) {
if ( V_5 -> V_7 -> V_57 & V_257 )
continue;
V_331 |= V_215 ;
}
if ( V_5 -> V_7 -> V_57 & V_257 )
V_240 = 64 ;
else
V_240 = 96 ;
F_221 ( V_5 , & V_100 , V_240 , V_331 ) ;
}
}
}
}
static void F_224 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_24 ( L_25 , V_41 ) ;
return;
}
F_221 ( V_5 , & V_338 , 128 , V_215 ) ;
}
static void F_225 ( struct V_4 * V_5 , const struct V_102 * V_100 )
{
struct V_13 * V_14 ;
T_1 V_152 = V_134 ;
#ifdef F_203
if ( V_5 -> V_49 . V_286 &&
! F_32 ( V_5 -> V_7 ) -> V_28 . V_92 -> V_55 )
V_152 |= V_166 ;
#endif
V_14 = F_76 ( V_5 , V_100 , 64 , V_210 , V_152 ) ;
if ( ! F_83 ( V_14 ) ) {
F_184 ( & V_14 -> V_100 , V_14 -> V_124 , V_5 -> V_7 , 0 , 0 ) ;
F_119 ( V_14 ) ;
F_102 ( V_14 ) ;
}
}
static void F_226 ( struct V_6 * V_7 )
{
struct V_102 V_100 ;
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_7 -> type != V_232 ) &&
( V_7 -> type != V_233 ) &&
( V_7 -> type != V_234 ) &&
( V_7 -> type != V_235 ) &&
( V_7 -> type != V_237 ) ) {
return;
}
V_5 = F_194 ( V_7 ) ;
if ( F_83 ( V_5 ) )
return;
memset ( & V_100 , 0 , sizeof( struct V_102 ) ) ;
V_100 . V_222 [ 0 ] = F_153 ( 0xFE800000 ) ;
if ( F_154 ( V_100 . V_154 + 8 , V_7 ) == 0 )
F_225 ( V_5 , & V_100 ) ;
}
static void F_227 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_24 ( L_25 , V_41 ) ;
return;
}
if ( V_7 -> V_64 & V_65 ) {
struct V_102 V_100 ;
F_191 ( & V_100 , F_153 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_184 ( & V_100 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_154 ( V_100 . V_154 + 8 , V_7 ) )
F_225 ( V_5 , & V_100 ) ;
return;
}
F_222 ( V_5 ) ;
if ( V_7 -> V_57 & V_257 ) {
F_190 ( V_7 ) ;
F_193 ( V_7 ) ;
} else
F_192 ( V_7 ) ;
}
static void F_228 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_102 V_100 ;
F_41 ( L_26 , V_41 , V_7 -> V_42 ) ;
F_29 () ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL ) {
F_24 ( L_25 , V_41 ) ;
return;
}
F_191 ( & V_100 , F_153 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_184 ( & V_100 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_154 ( V_100 . V_154 + 8 , V_7 ) )
F_225 ( V_5 , & V_100 ) ;
}
static inline int
F_229 ( struct V_4 * V_5 , struct V_6 * V_339 )
{
struct V_102 V_340 ;
if ( ! F_141 ( V_339 , & V_340 , V_83 ) ) {
F_225 ( V_5 , & V_340 ) ;
return 0 ;
}
return - 1 ;
}
static void F_230 ( struct V_4 * V_5 )
{
struct V_6 * V_339 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_341 &&
( V_339 = F_209 ( V_84 , V_5 -> V_7 -> V_341 ) ) ) {
if ( ! F_229 ( V_5 , V_339 ) )
return;
}
F_57 (net, link_dev) {
if ( ! F_229 ( V_5 , V_339 ) )
return;
}
F_24 ( L_27 ) ;
}
static void F_231 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_194 ( V_7 ) ;
if ( F_83 ( V_5 ) ) {
F_24 ( L_28 ) ;
return;
}
F_230 ( V_5 ) ;
}
static int F_232 ( struct V_342 * V_343 , unsigned long V_344 ,
void * V_123 )
{
struct V_6 * V_7 = (struct V_6 * ) V_123 ;
struct V_4 * V_5 = F_49 ( V_7 ) ;
int V_345 = 0 ;
int V_107 ;
switch ( V_344 ) {
case V_346 :
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( ! V_5 )
return F_233 ( - V_38 ) ;
}
break;
case V_129 :
case V_347 :
if ( V_7 -> V_57 & V_348 )
break;
if ( V_344 == V_129 ) {
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
F_227 ( V_7 ) ;
break;
#endif
#if F_40 ( V_349 ) || F_40 ( V_350 )
case V_236 :
F_228 ( V_7 ) ;
break;
#endif
case V_71 :
F_231 ( V_7 ) ;
break;
case V_351 :
F_224 ( V_7 ) ;
break;
default:
F_226 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_345 )
F_234 ( V_5 ) ;
if ( V_5 -> V_49 . V_51 != V_7 -> V_46 &&
V_7 -> V_46 >= V_47 ) {
F_235 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
}
V_5 -> V_76 = V_25 ;
F_236 ( V_352 , V_5 ) ;
if ( V_7 -> V_46 < V_47 )
F_217 ( V_7 , 1 ) ;
}
break;
case V_353 :
if ( V_5 && V_7 -> V_46 >= V_47 ) {
F_235 ( V_7 , V_7 -> V_46 ) ;
V_5 -> V_49 . V_51 = V_7 -> V_46 ;
break;
}
if ( ! V_5 && V_7 -> V_46 >= V_47 ) {
V_5 = F_28 ( V_7 ) ;
if ( V_5 )
break;
}
case V_138 :
case V_354 :
F_217 ( V_7 , V_344 != V_138 ) ;
break;
case V_355 :
if ( V_5 ) {
F_237 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_107 = F_38 ( V_5 ) ;
if ( V_107 )
return F_233 ( V_107 ) ;
}
break;
case V_356 :
case V_357 :
F_238 ( V_7 , V_344 ) ;
break;
}
return V_358 ;
}
static void F_238 ( struct V_6 * V_7 , unsigned long V_344 )
{
struct V_4 * V_5 ;
F_29 () ;
V_5 = F_49 ( V_7 ) ;
if ( V_344 == V_357 )
F_239 ( V_5 ) ;
else if ( V_344 == V_356 )
F_240 ( V_5 ) ;
}
static int F_217 ( struct V_6 * V_7 , int V_359 )
{
struct V_84 * V_84 = F_32 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_13 * V_82 ;
int V_95 , V_173 ;
F_29 () ;
F_241 ( V_84 , V_7 ) ;
F_242 ( & V_54 , V_7 ) ;
V_5 = F_49 ( V_7 ) ;
if ( V_5 == NULL )
return - V_113 ;
if ( V_359 ) {
V_5 -> V_43 = 1 ;
F_243 ( V_7 -> V_77 , NULL ) ;
F_237 ( V_5 ) ;
}
for ( V_173 = 0 ; V_173 < V_360 ; V_173 ++ ) {
struct V_361 * V_362 = & V_125 [ V_173 ] ;
struct V_213 * V_363 ;
F_97 ( & V_117 ) ;
V_364:
F_143 (ifa, n, h, addr_lst) {
if ( V_82 -> V_5 == V_5 ) {
F_99 ( & V_82 -> V_94 ) ;
F_7 ( V_82 ) ;
goto V_364;
}
}
F_98 ( & V_117 ) ;
}
F_100 ( & V_5 -> V_48 ) ;
if ( ! V_359 )
V_5 -> V_74 &= ~ ( V_365 | V_366 | V_75 ) ;
#ifdef F_42
if ( V_359 && F_8 ( & V_5 -> V_68 ) )
F_65 ( V_5 ) ;
while ( ! F_22 ( & V_5 -> V_67 ) ) {
V_82 = F_244 ( & V_5 -> V_67 ,
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
V_82 = F_244 ( & V_5 -> V_39 ,
struct V_13 , V_101 ) ;
F_7 ( V_82 ) ;
F_101 ( & V_82 -> V_101 ) ;
F_108 ( & V_5 -> V_48 ) ;
F_97 ( & V_82 -> V_122 ) ;
V_95 = V_82 -> V_95 ;
V_82 -> V_95 = V_96 ;
F_98 ( & V_82 -> V_122 ) ;
if ( V_95 != V_96 ) {
F_245 ( V_137 , V_82 ) ;
F_95 ( & V_128 , V_138 , V_82 ) ;
}
F_102 ( V_82 ) ;
F_100 ( & V_5 -> V_48 ) ;
}
F_108 ( & V_5 -> V_48 ) ;
if ( V_359 )
F_246 ( V_5 ) ;
else
F_247 ( V_5 ) ;
V_5 -> V_76 = V_25 ;
if ( V_359 ) {
F_3 ( V_5 ) ;
F_37 ( & V_54 , V_5 -> V_53 ) ;
F_242 ( & V_54 , V_7 ) ;
F_65 ( V_5 ) ;
}
return 0 ;
}
static void V_23 ( unsigned long V_123 )
{
struct V_13 * V_14 = (struct V_13 * ) V_123 ;
struct V_4 * V_5 = V_14 -> V_5 ;
F_248 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_74 & V_75 ) )
goto V_119;
if ( V_5 -> V_49 . V_55 )
goto V_119;
if ( V_5 -> V_74 & V_366 )
goto V_119;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_367 ++ < V_5 -> V_49 . V_66 ) {
F_10 ( V_14 , V_22 ,
( V_14 -> V_367 == V_5 -> V_49 . V_66 ) ?
V_5 -> V_49 . V_368 :
V_5 -> V_49 . V_369 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_249 ( V_5 -> V_7 , & V_14 -> V_100 , & V_80 ) ;
} else {
F_89 ( & V_14 -> V_48 ) ;
F_24 ( L_31 , V_5 -> V_7 -> V_42 ) ;
}
V_119:
F_250 ( & V_5 -> V_48 ) ;
F_102 ( V_14 ) ;
}
static void F_251 ( struct V_13 * V_14 )
{
unsigned long V_370 ;
struct V_4 * V_5 = V_14 -> V_5 ;
if ( V_14 -> V_57 & V_166 )
V_370 = 0 ;
else
V_370 = F_252 () % ( V_5 -> V_49 . V_368 ? : 1 ) ;
V_14 -> V_367 = V_5 -> V_49 . V_164 ;
F_10 ( V_14 , V_19 , V_370 ) ;
}
static void F_119 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_155 ( V_7 , & V_14 -> V_100 ) ;
F_253 ( V_14 -> V_100 . V_222 [ 3 ] ) ;
F_134 ( & V_5 -> V_48 ) ;
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_95 == V_96 )
goto V_119;
if ( V_7 -> V_57 & ( V_58 | V_59 ) ||
V_5 -> V_49 . V_60 < 1 ||
! ( V_14 -> V_57 & V_83 ) ||
V_14 -> V_57 & V_371 ) {
V_14 -> V_57 &= ~ ( V_83 | V_166 | V_218 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_139 ( & V_5 -> V_48 ) ;
F_254 ( V_14 ) ;
return;
}
if ( ! ( V_5 -> V_74 & V_75 ) ) {
F_89 ( & V_14 -> V_48 ) ;
F_139 ( & V_5 -> V_48 ) ;
F_11 ( V_14 ) ;
F_149 ( V_14 , 0 ) ;
return;
}
if ( V_14 -> V_57 & V_166 )
F_255 ( V_14 -> V_9 ) ;
F_251 ( V_14 ) ;
V_119:
F_89 ( & V_14 -> V_48 ) ;
F_139 ( & V_5 -> V_48 ) ;
}
static void V_21 ( unsigned long V_123 )
{
struct V_13 * V_14 = (struct V_13 * ) V_123 ;
struct V_4 * V_5 = V_14 -> V_5 ;
struct V_102 V_372 ;
if ( ! V_14 -> V_367 && F_150 ( V_14 ) )
goto V_119;
F_248 ( & V_5 -> V_48 ) ;
if ( V_5 -> V_43 || ! ( V_5 -> V_74 & V_75 ) ) {
F_250 ( & V_5 -> V_48 ) ;
goto V_119;
}
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_95 == V_96 ) {
F_89 ( & V_14 -> V_48 ) ;
F_250 ( & V_5 -> V_48 ) ;
goto V_119;
}
if ( V_14 -> V_367 == 0 ) {
V_14 -> V_57 &= ~ ( V_83 | V_166 | V_218 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_250 ( & V_5 -> V_48 ) ;
F_254 ( V_14 ) ;
goto V_119;
}
V_14 -> V_367 -- ;
F_10 ( V_14 , V_19 , V_14 -> V_5 -> V_53 -> V_165 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_250 ( & V_5 -> V_48 ) ;
F_156 ( & V_14 -> V_100 , & V_372 ) ;
F_256 ( V_14 -> V_5 -> V_7 , NULL , & V_14 -> V_100 , & V_372 , & V_373 ) ;
V_119:
F_102 ( V_14 ) ;
}
static void F_254 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = V_14 -> V_5 -> V_7 ;
F_109 ( V_327 , V_14 ) ;
if ( ( ( V_14 -> V_5 -> V_49 . V_374 == 1 && ! V_14 -> V_5 -> V_49 . V_55 ) ||
V_14 -> V_5 -> V_49 . V_374 == 2 ) &&
V_14 -> V_5 -> V_49 . V_66 > 0 &&
( V_7 -> V_57 & V_59 ) == 0 &&
( F_77 ( & V_14 -> V_100 ) & V_275 ) ) {
F_249 ( V_14 -> V_5 -> V_7 , & V_14 -> V_100 , & V_80 ) ;
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_367 = 1 ;
V_14 -> V_5 -> V_74 |= V_365 ;
F_10 ( V_14 , V_22 , V_14 -> V_5 -> V_49 . V_369 ) ;
F_98 ( & V_14 -> V_48 ) ;
}
}
static void F_234 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
F_134 ( & V_5 -> V_48 ) ;
F_53 (ifp, &idev->addr_list, if_list) {
F_80 ( & V_14 -> V_48 ) ;
if ( V_14 -> V_57 & V_83 &&
V_14 -> V_95 == V_220 )
F_251 ( V_14 ) ;
F_89 ( & V_14 -> V_48 ) ;
}
F_139 ( & V_5 -> V_48 ) ;
}
static struct V_13 * F_257 ( struct V_375 * V_376 , T_9 V_377 )
{
struct V_13 * V_82 = NULL ;
struct V_378 * V_95 = V_376 -> V_379 ;
struct V_84 * V_84 = F_258 ( V_376 ) ;
int V_89 = 0 ;
if ( V_377 == 0 ) {
V_95 -> V_380 = 0 ;
V_95 -> V_381 = 0 ;
}
for (; V_95 -> V_380 < V_360 ; ++ V_95 -> V_380 ) {
struct V_213 * V_363 ;
F_148 (ifa, n, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( V_89 < V_95 -> V_381 ) {
V_89 ++ ;
continue;
}
V_95 -> V_381 ++ ;
if ( F_144 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_84 ) )
return V_82 ;
}
V_95 -> V_381 = 0 ;
V_89 = 0 ;
}
return NULL ;
}
static struct V_13 * F_259 ( struct V_375 * V_376 ,
struct V_13 * V_82 )
{
struct V_378 * V_95 = V_376 -> V_379 ;
struct V_84 * V_84 = F_258 ( V_376 ) ;
struct V_213 * V_363 = & V_82 -> V_94 ;
F_260 (ifa, n, addr_lst) {
V_95 -> V_381 ++ ;
if ( F_144 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_84 ) )
return V_82 ;
}
while ( ++ V_95 -> V_380 < V_360 ) {
V_95 -> V_381 = 0 ;
F_148 (ifa, n,
&inet6_addr_lst[state->bucket], addr_lst) {
V_95 -> V_381 ++ ;
if ( F_144 ( F_32 ( V_82 -> V_5 -> V_7 ) , V_84 ) )
return V_82 ;
}
}
return NULL ;
}
static void * F_261 ( struct V_375 * V_376 , T_9 * V_377 )
__acquires( T_10 )
{
F_79 () ;
return F_257 ( V_376 , * V_377 ) ;
}
static void * F_262 ( struct V_375 * V_376 , void * V_382 , T_9 * V_377 )
{
struct V_13 * V_82 ;
V_82 = F_259 ( V_376 , V_382 ) ;
++ * V_377 ;
return V_82 ;
}
static void F_263 ( struct V_375 * V_376 , void * V_382 )
__releases( T_10 )
{
F_93 () ;
}
static int F_264 ( struct V_375 * V_376 , void * V_382 )
{
struct V_13 * V_14 = (struct V_13 * ) V_382 ;
F_265 ( V_376 , L_32 ,
& V_14 -> V_100 ,
V_14 -> V_5 -> V_7 -> V_140 ,
V_14 -> V_124 ,
V_14 -> V_105 ,
V_14 -> V_57 ,
V_14 -> V_5 -> V_7 -> V_42 ) ;
return 0 ;
}
static int F_266 ( struct V_383 * V_383 , struct V_384 * V_384 )
{
return F_267 ( V_383 , V_384 , & V_385 ,
sizeof( struct V_378 ) ) ;
}
static int T_11 F_268 ( struct V_84 * V_84 )
{
if ( ! F_269 ( V_84 , L_33 , V_386 , & V_387 ) )
return - V_38 ;
return 0 ;
}
static void T_12 F_270 ( struct V_84 * V_84 )
{
F_271 ( V_84 , L_33 ) ;
}
int T_13 F_272 ( void )
{
return F_273 ( & V_388 ) ;
}
void F_274 ( void )
{
F_275 ( & V_388 ) ;
}
int F_276 ( struct V_84 * V_84 , const struct V_102 * V_100 )
{
int V_150 = 0 ;
struct V_13 * V_14 = NULL ;
struct V_213 * V_363 ;
unsigned int V_106 = F_73 ( V_100 ) ;
F_79 () ;
F_148 (ifp, n, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_144 ( F_32 ( V_14 -> V_5 -> V_7 ) , V_84 ) )
continue;
if ( F_123 ( & V_14 -> V_100 , V_100 ) &&
( V_14 -> V_57 & V_188 ) ) {
V_150 = 1 ;
break;
}
}
F_93 () ;
return V_150 ;
}
static void F_204 ( unsigned long V_389 )
{
unsigned long V_153 , V_390 , V_391 , V_392 ;
struct V_13 * V_14 ;
struct V_213 * V_214 ;
int V_173 ;
F_79 () ;
F_80 ( & V_393 ) ;
V_153 = V_25 ;
V_390 = F_277 ( V_153 + V_394 ) ;
F_8 ( & V_395 ) ;
for ( V_173 = 0 ; V_173 < V_360 ; V_173 ++ ) {
V_364:
F_148 (ifp, node,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_147 ;
if ( V_14 -> V_57 & V_134 )
continue;
F_80 ( & V_14 -> V_48 ) ;
V_147 = ( V_153 - V_14 -> V_76 + V_396 ) / V_3 ;
if ( V_14 -> V_136 != V_326 &&
V_147 >= V_14 -> V_136 ) {
F_89 ( & V_14 -> V_48 ) ;
F_11 ( V_14 ) ;
F_96 ( V_14 ) ;
goto V_364;
} else if ( V_14 -> V_161 == V_326 ) {
F_89 ( & V_14 -> V_48 ) ;
continue;
} else if ( V_147 >= V_14 -> V_161 ) {
int V_397 = 0 ;
if ( ! ( V_14 -> V_57 & V_183 ) ) {
V_397 = 1 ;
V_14 -> V_57 |= V_183 ;
}
if ( F_107 ( V_14 -> V_76 + V_14 -> V_136 * V_3 , V_390 ) )
V_390 = V_14 -> V_76 + V_14 -> V_136 * V_3 ;
F_89 ( & V_14 -> V_48 ) ;
if ( V_397 ) {
F_11 ( V_14 ) ;
F_109 ( 0 , V_14 ) ;
F_102 ( V_14 ) ;
goto V_364;
}
#ifdef F_42
} else if ( ( V_14 -> V_57 & V_126 ) &&
! ( V_14 -> V_57 & V_83 ) ) {
unsigned long V_148 = V_14 -> V_5 -> V_49 . V_157 *
V_14 -> V_5 -> V_49 . V_164 *
V_14 -> V_5 -> V_53 -> V_165 / V_3 ;
if ( V_147 >= V_14 -> V_161 - V_148 ) {
struct V_13 * V_133 = V_14 -> V_133 ;
if ( F_107 ( V_14 -> V_76 + V_14 -> V_161 * V_3 , V_390 ) )
V_390 = V_14 -> V_76 + V_14 -> V_161 * V_3 ;
if ( ! V_14 -> V_156 && V_133 ) {
V_14 -> V_156 ++ ;
F_11 ( V_14 ) ;
F_11 ( V_133 ) ;
F_89 ( & V_14 -> V_48 ) ;
F_80 ( & V_133 -> V_48 ) ;
V_133 -> V_156 = 0 ;
F_89 ( & V_133 -> V_48 ) ;
F_115 ( V_133 , V_14 ) ;
F_102 ( V_133 ) ;
F_102 ( V_14 ) ;
goto V_364;
}
} else if ( F_107 ( V_14 -> V_76 + V_14 -> V_161 * V_3 - V_148 * V_3 , V_390 ) )
V_390 = V_14 -> V_76 + V_14 -> V_161 * V_3 - V_148 * V_3 ;
F_89 ( & V_14 -> V_48 ) ;
#endif
} else {
if ( F_107 ( V_14 -> V_76 + V_14 -> V_161 * V_3 , V_390 ) )
V_390 = V_14 -> V_76 + V_14 -> V_161 * V_3 ;
F_89 ( & V_14 -> V_48 ) ;
}
}
}
V_391 = F_277 ( V_390 ) ;
V_392 = V_390 ;
if ( F_107 ( V_391 , V_390 + V_398 ) )
V_392 = V_391 ;
if ( F_107 ( V_392 , V_25 + V_399 ) )
V_392 = V_25 + V_399 ;
F_36 ( ( V_204 L_34 ,
V_153 , V_390 , V_391 , V_392 ) ) ;
V_395 . V_24 = V_392 ;
F_12 ( & V_395 ) ;
F_89 ( & V_393 ) ;
F_93 () ;
}
static struct V_102 * F_278 ( struct V_400 * V_100 , struct V_400 * V_401 )
{
struct V_102 * V_239 = NULL ;
if ( V_100 )
V_239 = F_279 ( V_100 ) ;
if ( V_401 ) {
if ( V_239 && F_280 ( V_401 , V_239 , sizeof( * V_239 ) ) )
V_239 = NULL ;
else
V_239 = F_279 ( V_401 ) ;
}
return V_239 ;
}
static int
F_281 ( struct V_402 * V_403 , struct V_404 * V_405 , void * V_292 )
{
struct V_84 * V_84 = F_282 ( V_403 -> V_406 ) ;
struct V_407 * V_408 ;
struct V_400 * V_409 [ V_410 + 1 ] ;
struct V_102 * V_239 ;
int V_107 ;
V_107 = F_283 ( V_405 , sizeof( * V_408 ) , V_409 , V_410 , V_411 ) ;
if ( V_107 < 0 )
return V_107 ;
V_408 = F_284 ( V_405 ) ;
V_239 = F_278 ( V_409 [ V_412 ] , V_409 [ V_413 ] ) ;
if ( V_239 == NULL )
return - V_295 ;
return F_216 ( V_84 , V_408 -> V_414 , V_239 , V_408 -> V_415 ) ;
}
static int F_285 ( struct V_13 * V_14 , T_3 V_320 ,
T_1 V_161 , T_1 V_136 )
{
T_1 V_57 ;
T_5 V_24 ;
unsigned long V_321 ;
if ( ! V_136 || ( V_161 > V_136 ) )
return - V_295 ;
V_321 = F_106 ( V_136 , V_3 ) ;
if ( F_200 ( V_321 ) ) {
V_24 = F_202 ( V_321 * V_3 ) ;
V_136 = V_321 ;
V_57 = V_141 ;
} else {
V_24 = 0 ;
V_57 = 0 ;
V_320 |= V_134 ;
}
V_321 = F_106 ( V_161 , V_3 ) ;
if ( F_200 ( V_321 ) ) {
if ( V_321 == 0 )
V_320 |= V_183 ;
V_161 = V_321 ;
}
F_97 ( & V_14 -> V_48 ) ;
V_14 -> V_57 = ( V_14 -> V_57 & ~ ( V_183 | V_134 | V_371 | V_188 ) ) | V_320 ;
V_14 -> V_76 = V_25 ;
V_14 -> V_136 = V_136 ;
V_14 -> V_161 = V_161 ;
F_98 ( & V_14 -> V_48 ) ;
if ( ! ( V_14 -> V_57 & V_83 ) )
F_109 ( 0 , V_14 ) ;
F_184 ( & V_14 -> V_100 , V_14 -> V_124 , V_14 -> V_5 -> V_7 ,
V_24 , V_57 ) ;
F_204 ( 0 ) ;
return 0 ;
}
static int
F_286 ( struct V_402 * V_403 , struct V_404 * V_405 , void * V_292 )
{
struct V_84 * V_84 = F_282 ( V_403 -> V_406 ) ;
struct V_407 * V_408 ;
struct V_400 * V_409 [ V_410 + 1 ] ;
struct V_102 * V_239 ;
struct V_13 * V_82 ;
struct V_6 * V_7 ;
T_1 V_136 = V_326 , V_416 = V_326 ;
T_3 V_320 ;
int V_107 ;
V_107 = F_283 ( V_405 , sizeof( * V_408 ) , V_409 , V_410 , V_411 ) ;
if ( V_107 < 0 )
return V_107 ;
V_408 = F_284 ( V_405 ) ;
V_239 = F_278 ( V_409 [ V_412 ] , V_409 [ V_413 ] ) ;
if ( V_239 == NULL )
return - V_295 ;
if ( V_409 [ V_417 ] ) {
struct V_418 * V_419 ;
V_419 = F_279 ( V_409 [ V_417 ] ) ;
V_136 = V_419 -> V_420 ;
V_416 = V_419 -> V_421 ;
} else {
V_416 = V_326 ;
V_136 = V_326 ;
}
V_7 = F_209 ( V_84 , V_408 -> V_414 ) ;
if ( V_7 == NULL )
return - V_113 ;
V_320 = V_408 -> V_320 & ( V_371 | V_188 ) ;
V_82 = F_147 ( V_84 , V_239 , V_7 , 1 ) ;
if ( V_82 == NULL ) {
return F_214 ( V_84 , V_408 -> V_414 , V_239 ,
V_408 -> V_415 , V_320 ,
V_416 , V_136 ) ;
}
if ( V_405 -> V_422 & V_423 ||
! ( V_405 -> V_422 & V_424 ) )
V_107 = - V_118 ;
else
V_107 = F_285 ( V_82 , V_320 , V_416 , V_136 ) ;
F_102 ( V_82 ) ;
return V_107 ;
}
static void F_287 ( struct V_404 * V_405 , T_3 V_425 , T_3 V_57 ,
T_3 V_105 , int V_140 )
{
struct V_407 * V_408 ;
V_408 = F_284 ( V_405 ) ;
V_408 -> V_426 = V_427 ;
V_408 -> V_415 = V_425 ;
V_408 -> V_320 = V_57 ;
V_408 -> V_335 = V_105 ;
V_408 -> V_414 = V_140 ;
}
static int F_288 ( struct V_402 * V_403 , unsigned long V_1 ,
unsigned long V_76 , T_1 V_428 , T_1 V_276 )
{
struct V_418 V_419 ;
V_419 . V_1 = F_1 ( V_1 ) ;
V_419 . V_76 = F_1 ( V_76 ) ;
V_419 . V_421 = V_428 ;
V_419 . V_420 = V_276 ;
return F_289 ( V_403 , V_417 , sizeof( V_419 ) , & V_419 ) ;
}
static inline int F_290 ( int V_335 )
{
if ( V_335 & V_215 )
return V_337 ;
else if ( V_335 & V_210 )
return V_336 ;
else if ( V_335 & V_429 )
return V_430 ;
else
return V_431 ;
}
static inline int F_291 ( void )
{
return F_292 ( sizeof( struct V_407 ) )
+ F_293 ( 16 )
+ F_293 ( sizeof( struct V_418 ) ) ;
}
static int F_294 ( struct V_402 * V_403 , struct V_13 * V_82 ,
T_1 V_432 , T_1 V_376 , int V_344 , unsigned int V_57 )
{
struct V_404 * V_405 ;
T_1 V_428 , V_276 ;
V_405 = F_295 ( V_403 , V_432 , V_376 , V_344 , sizeof( struct V_407 ) , V_57 ) ;
if ( V_405 == NULL )
return - V_433 ;
F_287 ( V_405 , V_82 -> V_124 , V_82 -> V_57 , F_290 ( V_82 -> V_105 ) ,
V_82 -> V_5 -> V_7 -> V_140 ) ;
if ( ! ( V_82 -> V_57 & V_134 ) ) {
V_428 = V_82 -> V_161 ;
V_276 = V_82 -> V_136 ;
if ( V_428 != V_326 ) {
long V_434 = ( V_25 - V_82 -> V_76 ) / V_3 ;
if ( V_428 > V_434 )
V_428 -= V_434 ;
else
V_428 = 0 ;
if ( V_276 != V_326 ) {
if ( V_276 > V_434 )
V_276 -= V_434 ;
else
V_276 = 0 ;
}
}
} else {
V_428 = V_326 ;
V_276 = V_326 ;
}
if ( F_289 ( V_403 , V_412 , 16 , & V_82 -> V_100 ) < 0 ||
F_288 ( V_403 , V_82 -> V_1 , V_82 -> V_76 , V_428 , V_276 ) < 0 ) {
F_296 ( V_403 , V_405 ) ;
return - V_433 ;
}
return F_297 ( V_403 , V_405 ) ;
}
static int F_298 ( struct V_402 * V_403 , struct V_435 * V_436 ,
T_1 V_432 , T_1 V_376 , int V_344 , T_14 V_57 )
{
struct V_404 * V_405 ;
T_3 V_105 = V_431 ;
int V_140 = V_436 -> V_5 -> V_7 -> V_140 ;
if ( F_215 ( & V_436 -> V_437 ) & V_429 )
V_105 = V_430 ;
V_405 = F_295 ( V_403 , V_432 , V_376 , V_344 , sizeof( struct V_407 ) , V_57 ) ;
if ( V_405 == NULL )
return - V_433 ;
F_287 ( V_405 , 128 , V_134 , V_105 , V_140 ) ;
if ( F_289 ( V_403 , V_438 , 16 , & V_436 -> V_437 ) < 0 ||
F_288 ( V_403 , V_436 -> V_439 , V_436 -> V_440 ,
V_326 , V_326 ) < 0 ) {
F_296 ( V_403 , V_405 ) ;
return - V_433 ;
}
return F_297 ( V_403 , V_405 ) ;
}
static int F_299 ( struct V_402 * V_403 , struct V_441 * V_442 ,
T_1 V_432 , T_1 V_376 , int V_344 , unsigned int V_57 )
{
struct V_404 * V_405 ;
T_3 V_105 = V_431 ;
int V_140 = V_442 -> V_443 -> V_7 -> V_140 ;
if ( F_215 ( & V_442 -> V_444 ) & V_429 )
V_105 = V_430 ;
V_405 = F_295 ( V_403 , V_432 , V_376 , V_344 , sizeof( struct V_407 ) , V_57 ) ;
if ( V_405 == NULL )
return - V_433 ;
F_287 ( V_405 , 128 , V_134 , V_105 , V_140 ) ;
if ( F_289 ( V_403 , V_445 , 16 , & V_442 -> V_444 ) < 0 ||
F_288 ( V_403 , V_442 -> V_446 , V_442 -> V_447 ,
V_326 , V_326 ) < 0 ) {
F_296 ( V_403 , V_405 ) ;
return - V_433 ;
}
return F_297 ( V_403 , V_405 ) ;
}
static int F_300 ( struct V_4 * V_5 , struct V_402 * V_403 ,
struct V_448 * V_449 , enum V_450 type ,
int V_451 , int * V_452 )
{
struct V_435 * V_436 ;
struct V_441 * V_442 ;
int V_107 = 1 ;
int V_453 = * V_452 ;
F_134 ( & V_5 -> V_48 ) ;
switch ( type ) {
case V_454 : {
struct V_13 * V_82 ;
F_53 (ifa, &idev->addr_list, if_list) {
if ( ++ V_453 < V_451 )
continue;
V_107 = F_294 ( V_403 , V_82 ,
F_301 ( V_449 -> V_403 ) . V_432 ,
V_449 -> V_405 -> V_455 ,
V_327 ,
V_456 ) ;
if ( V_107 <= 0 )
break;
}
break;
}
case V_457 :
for ( V_436 = V_5 -> V_40 ; V_436 ;
V_436 = V_436 -> V_390 , V_453 ++ ) {
if ( V_453 < V_451 )
continue;
V_107 = F_298 ( V_403 , V_436 ,
F_301 ( V_449 -> V_403 ) . V_432 ,
V_449 -> V_405 -> V_455 ,
V_458 ,
V_456 ) ;
if ( V_107 <= 0 )
break;
}
break;
case V_459 :
for ( V_442 = V_5 -> V_460 ; V_442 ;
V_442 = V_442 -> V_461 , V_453 ++ ) {
if ( V_453 < V_451 )
continue;
V_107 = F_299 ( V_403 , V_442 ,
F_301 ( V_449 -> V_403 ) . V_432 ,
V_449 -> V_405 -> V_455 ,
V_462 ,
V_456 ) ;
if ( V_107 <= 0 )
break;
}
break;
default:
break;
}
F_139 ( & V_5 -> V_48 ) ;
* V_452 = V_453 ;
return V_107 ;
}
static int F_302 ( struct V_402 * V_403 , struct V_448 * V_449 ,
enum V_450 type )
{
struct V_84 * V_84 = F_282 ( V_403 -> V_406 ) ;
int V_362 , V_463 ;
int V_464 , V_453 ;
int V_465 , V_451 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_361 * V_466 ;
struct V_213 * V_214 ;
V_463 = V_449 -> args [ 0 ] ;
V_465 = V_464 = V_449 -> args [ 1 ] ;
V_451 = V_453 = V_449 -> args [ 2 ] ;
F_132 () ;
for ( V_362 = V_463 ; V_362 < V_467 ; V_362 ++ , V_465 = 0 ) {
V_464 = 0 ;
V_466 = & V_84 -> V_468 [ V_362 ] ;
F_143 (dev, node, head, index_hlist) {
if ( V_464 < V_465 )
goto V_469;
if ( V_362 > V_463 || V_464 > V_465 )
V_451 = 0 ;
V_453 = 0 ;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
goto V_469;
if ( F_300 ( V_5 , V_403 , V_449 , type ,
V_451 , & V_453 ) <= 0 )
goto V_470;
V_469:
V_464 ++ ;
}
}
V_470:
F_140 () ;
V_449 -> args [ 0 ] = V_362 ;
V_449 -> args [ 1 ] = V_464 ;
V_449 -> args [ 2 ] = V_453 ;
return V_403 -> V_270 ;
}
static int F_303 ( struct V_402 * V_403 , struct V_448 * V_449 )
{
enum V_450 type = V_454 ;
return F_302 ( V_403 , V_449 , type ) ;
}
static int F_304 ( struct V_402 * V_403 , struct V_448 * V_449 )
{
enum V_450 type = V_457 ;
return F_302 ( V_403 , V_449 , type ) ;
}
static int F_305 ( struct V_402 * V_403 , struct V_448 * V_449 )
{
enum V_450 type = V_459 ;
return F_302 ( V_403 , V_449 , type ) ;
}
static int F_306 ( struct V_402 * V_471 , struct V_404 * V_405 ,
void * V_292 )
{
struct V_84 * V_84 = F_282 ( V_471 -> V_406 ) ;
struct V_407 * V_408 ;
struct V_400 * V_409 [ V_410 + 1 ] ;
struct V_102 * V_100 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_13 * V_82 ;
struct V_402 * V_403 ;
int V_107 ;
V_107 = F_283 ( V_405 , sizeof( * V_408 ) , V_409 , V_410 , V_411 ) ;
if ( V_107 < 0 )
goto V_472;
V_100 = F_278 ( V_409 [ V_412 ] , V_409 [ V_413 ] ) ;
if ( V_100 == NULL ) {
V_107 = - V_295 ;
goto V_472;
}
V_408 = F_284 ( V_405 ) ;
if ( V_408 -> V_414 )
V_7 = F_209 ( V_84 , V_408 -> V_414 ) ;
V_82 = F_147 ( V_84 , V_100 , V_7 , 1 ) ;
if ( ! V_82 ) {
V_107 = - V_112 ;
goto V_472;
}
V_403 = F_307 ( F_291 () , V_33 ) ;
if ( ! V_403 ) {
V_107 = - V_121 ;
goto V_473;
}
V_107 = F_294 ( V_403 , V_82 , F_301 ( V_471 ) . V_432 ,
V_405 -> V_455 , V_327 , 0 ) ;
if ( V_107 < 0 ) {
F_21 ( V_107 == - V_433 ) ;
F_308 ( V_403 ) ;
goto V_473;
}
V_107 = F_309 ( V_403 , V_84 , F_301 ( V_471 ) . V_432 ) ;
V_473:
F_102 ( V_82 ) ;
V_472:
return V_107 ;
}
static void F_310 ( int V_344 , struct V_13 * V_82 )
{
struct V_402 * V_403 ;
struct V_84 * V_84 = F_32 ( V_82 -> V_5 -> V_7 ) ;
int V_107 = - V_121 ;
V_403 = F_307 ( F_291 () , V_120 ) ;
if ( V_403 == NULL )
goto V_472;
V_107 = F_294 ( V_403 , V_82 , 0 , 0 , V_344 , 0 ) ;
if ( V_107 < 0 ) {
F_21 ( V_107 == - V_433 ) ;
F_308 ( V_403 ) ;
goto V_472;
}
F_311 ( V_403 , V_84 , 0 , V_474 , NULL , V_120 ) ;
return;
V_472:
if ( V_107 < 0 )
F_312 ( V_84 , V_474 , V_107 ) ;
}
static inline void F_313 ( struct V_475 * V_49 ,
T_2 * V_476 , int V_477 )
{
F_314 ( V_477 < ( V_478 * 4 ) ) ;
memset ( V_476 , 0 , V_477 ) ;
V_476 [ V_479 ] = V_49 -> V_55 ;
V_476 [ V_480 ] = V_49 -> V_481 ;
V_476 [ V_482 ] = V_49 -> V_51 ;
V_476 [ V_483 ] = V_49 -> V_374 ;
V_476 [ V_484 ] = V_49 -> V_485 ;
V_476 [ V_486 ] = V_49 -> V_282 ;
V_476 [ V_487 ] = V_49 -> V_164 ;
V_476 [ V_488 ] = V_49 -> V_66 ;
V_476 [ V_489 ] =
F_315 ( V_49 -> V_369 ) ;
V_476 [ V_490 ] =
F_315 ( V_49 -> V_368 ) ;
V_476 [ V_491 ] = V_49 -> V_492 ;
#ifdef F_42
V_476 [ V_493 ] = V_49 -> V_73 ;
V_476 [ V_494 ] = V_49 -> V_160 ;
V_476 [ V_495 ] = V_49 -> V_162 ;
V_476 [ V_496 ] = V_49 -> V_157 ;
V_476 [ V_497 ] = V_49 -> V_163 ;
#endif
V_476 [ V_498 ] = V_49 -> V_151 ;
V_476 [ V_499 ] = V_49 -> V_500 ;
V_476 [ V_501 ] = V_49 -> V_502 ;
#ifdef F_316
V_476 [ V_503 ] = V_49 -> V_504 ;
V_476 [ V_505 ] =
F_315 ( V_49 -> V_506 ) ;
#ifdef F_317
V_476 [ V_507 ] = V_49 -> V_508 ;
#endif
#endif
V_476 [ V_509 ] = V_49 -> V_510 ;
V_476 [ V_511 ] = V_49 -> V_512 ;
#ifdef F_203
V_476 [ V_513 ] = V_49 -> V_286 ;
#endif
#ifdef F_318
V_476 [ V_514 ] = V_49 -> V_515 ;
#endif
V_476 [ V_516 ] = V_49 -> V_115 ;
V_476 [ V_517 ] = V_49 -> V_60 ;
V_476 [ V_518 ] = V_49 -> V_519 ;
}
static inline T_15 F_319 ( void )
{
return F_293 ( 4 )
+ F_293 ( sizeof( struct V_520 ) )
+ F_293 ( V_478 * 4 )
+ F_293 ( V_521 * 8 )
+ F_293 ( V_522 * 8 ) ;
}
static inline T_15 F_320 ( void )
{
return F_292 ( sizeof( struct V_523 ) )
+ F_293 ( V_524 )
+ F_293 ( V_525 )
+ F_293 ( 4 )
+ F_293 ( 4 )
+ F_293 ( F_319 () ) ;
}
static inline void F_321 ( T_16 * V_27 , T_17 * V_526 ,
int V_527 , int V_477 )
{
int V_173 ;
int V_528 = V_477 - sizeof( T_16 ) * V_527 ;
F_314 ( V_528 < 0 ) ;
F_322 ( V_527 , & V_27 [ 0 ] ) ;
for ( V_173 = 1 ; V_173 < V_527 ; V_173 ++ )
F_322 ( F_323 ( & V_526 [ V_173 ] ) , & V_27 [ V_173 ] ) ;
memset ( & V_27 [ V_527 ] , 0 , V_528 ) ;
}
static inline void F_324 ( T_16 * V_27 , void V_26 * * V_526 ,
int V_527 , int V_477 , T_15 V_529 )
{
int V_173 ;
int V_528 = V_477 - sizeof( T_16 ) * V_527 ;
F_314 ( V_528 < 0 ) ;
F_322 ( V_527 , & V_27 [ 0 ] ) ;
for ( V_173 = 1 ; V_173 < V_527 ; V_173 ++ )
F_322 ( F_325 ( V_526 , V_173 , V_529 ) , & V_27 [ V_173 ] ) ;
memset ( & V_27 [ V_527 ] , 0 , V_528 ) ;
}
static void F_326 ( T_16 * V_27 , struct V_4 * V_5 , int V_530 ,
int V_477 )
{
switch ( V_530 ) {
case V_531 :
F_324 ( V_27 , ( void V_26 * * ) V_5 -> V_27 . V_28 ,
V_521 , V_477 , F_327 ( struct V_29 , V_532 ) ) ;
break;
case V_533 :
F_321 ( V_27 , V_5 -> V_27 . V_31 -> V_534 , V_522 , V_477 ) ;
break;
}
}
static int F_328 ( struct V_402 * V_403 , struct V_4 * V_5 )
{
struct V_400 * V_535 ;
struct V_520 V_419 ;
if ( F_329 ( V_403 , V_536 , V_5 -> V_74 ) )
goto V_537;
V_419 . V_538 = V_539 ;
V_419 . V_76 = F_1 ( V_5 -> V_76 ) ;
V_419 . V_540 = F_315 ( V_5 -> V_53 -> V_540 ) ;
V_419 . V_165 = F_315 ( V_5 -> V_53 -> V_165 ) ;
if ( F_289 ( V_403 , V_541 , sizeof( V_419 ) , & V_419 ) )
goto V_537;
V_535 = F_330 ( V_403 , V_542 , V_478 * sizeof( V_543 ) ) ;
if ( V_535 == NULL )
goto V_537;
F_313 ( & V_5 -> V_49 , F_279 ( V_535 ) , F_331 ( V_535 ) ) ;
V_535 = F_330 ( V_403 , V_531 , V_521 * sizeof( T_16 ) ) ;
if ( V_535 == NULL )
goto V_537;
F_326 ( F_279 ( V_535 ) , V_5 , V_531 , F_331 ( V_535 ) ) ;
V_535 = F_330 ( V_403 , V_533 , V_522 * sizeof( T_16 ) ) ;
if ( V_535 == NULL )
goto V_537;
F_326 ( F_279 ( V_535 ) , V_5 , V_533 , F_331 ( V_535 ) ) ;
return 0 ;
V_537:
return - V_433 ;
}
static T_15 F_332 ( const struct V_6 * V_7 )
{
if ( ! F_49 ( V_7 ) )
return 0 ;
return F_319 () ;
}
static int F_333 ( struct V_402 * V_403 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
return - V_544 ;
if ( F_328 ( V_403 , V_5 ) < 0 )
return - V_433 ;
return 0 ;
}
static int F_334 ( struct V_402 * V_403 , struct V_4 * V_5 ,
T_1 V_432 , T_1 V_376 , int V_344 , unsigned int V_57 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_523 * V_545 ;
struct V_404 * V_405 ;
void * V_546 ;
V_405 = F_295 ( V_403 , V_432 , V_376 , V_344 , sizeof( * V_545 ) , V_57 ) ;
if ( V_405 == NULL )
return - V_433 ;
V_545 = F_284 ( V_405 ) ;
V_545 -> V_547 = V_427 ;
V_545 -> V_548 = 0 ;
V_545 -> V_549 = V_7 -> type ;
V_545 -> V_550 = V_7 -> V_140 ;
V_545 -> V_551 = F_335 ( V_7 ) ;
V_545 -> V_552 = 0 ;
if ( F_336 ( V_403 , V_553 , V_7 -> V_42 ) ||
( V_7 -> V_225 &&
F_289 ( V_403 , V_554 , V_7 -> V_225 , V_7 -> V_227 ) ) ||
F_329 ( V_403 , V_555 , V_7 -> V_46 ) ||
( V_7 -> V_140 != V_7 -> V_341 &&
F_329 ( V_403 , V_556 , V_7 -> V_341 ) ) )
goto V_537;
V_546 = F_337 ( V_403 , V_557 ) ;
if ( V_546 == NULL )
goto V_537;
if ( F_328 ( V_403 , V_5 ) < 0 )
goto V_537;
F_338 ( V_403 , V_546 ) ;
return F_297 ( V_403 , V_405 ) ;
V_537:
F_296 ( V_403 , V_405 ) ;
return - V_433 ;
}
static int F_339 ( struct V_402 * V_403 , struct V_448 * V_449 )
{
struct V_84 * V_84 = F_282 ( V_403 -> V_406 ) ;
int V_362 , V_463 ;
int V_464 = 0 , V_465 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_361 * V_466 ;
struct V_213 * V_214 ;
V_463 = V_449 -> args [ 0 ] ;
V_465 = V_449 -> args [ 1 ] ;
F_132 () ;
for ( V_362 = V_463 ; V_362 < V_467 ; V_362 ++ , V_465 = 0 ) {
V_464 = 0 ;
V_466 = & V_84 -> V_468 [ V_362 ] ;
F_143 (dev, node, head, index_hlist) {
if ( V_464 < V_465 )
goto V_469;
V_5 = F_49 ( V_7 ) ;
if ( ! V_5 )
goto V_469;
if ( F_334 ( V_403 , V_5 ,
F_301 ( V_449 -> V_403 ) . V_432 ,
V_449 -> V_405 -> V_455 ,
V_352 , V_456 ) <= 0 )
goto V_119;
V_469:
V_464 ++ ;
}
}
V_119:
F_140 () ;
V_449 -> args [ 1 ] = V_464 ;
V_449 -> args [ 0 ] = V_362 ;
return V_403 -> V_270 ;
}
void F_236 ( int V_344 , struct V_4 * V_5 )
{
struct V_402 * V_403 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
int V_107 = - V_121 ;
V_403 = F_307 ( F_320 () , V_120 ) ;
if ( V_403 == NULL )
goto V_472;
V_107 = F_334 ( V_403 , V_5 , 0 , 0 , V_344 , 0 ) ;
if ( V_107 < 0 ) {
F_21 ( V_107 == - V_433 ) ;
F_308 ( V_403 ) ;
goto V_472;
}
F_311 ( V_403 , V_84 , 0 , V_558 , NULL , V_120 ) ;
return;
V_472:
if ( V_107 < 0 )
F_312 ( V_84 , V_558 , V_107 ) ;
}
static inline T_15 F_340 ( void )
{
return F_292 ( sizeof( struct V_559 ) )
+ F_293 ( sizeof( struct V_102 ) )
+ F_293 ( sizeof( struct V_560 ) ) ;
}
static int F_341 ( struct V_402 * V_403 , struct V_4 * V_5 ,
struct V_272 * V_273 , T_1 V_432 , T_1 V_376 ,
int V_344 , unsigned int V_57 )
{
struct V_559 * V_561 ;
struct V_404 * V_405 ;
struct V_560 V_419 ;
V_405 = F_295 ( V_403 , V_432 , V_376 , V_344 , sizeof( * V_561 ) , V_57 ) ;
if ( V_405 == NULL )
return - V_433 ;
V_561 = F_284 ( V_405 ) ;
V_561 -> V_562 = V_427 ;
V_561 -> V_563 = 0 ;
V_561 -> V_564 = 0 ;
V_561 -> V_565 = V_5 -> V_7 -> V_140 ;
V_561 -> V_124 = V_273 -> V_124 ;
V_561 -> V_566 = V_273 -> type ;
V_561 -> V_567 = 0 ;
V_561 -> V_568 = 0 ;
if ( V_273 -> V_132 )
V_561 -> V_568 |= V_569 ;
if ( V_273 -> V_282 )
V_561 -> V_568 |= V_570 ;
if ( F_289 ( V_403 , V_571 , sizeof( V_273 -> V_139 ) , & V_273 -> V_139 ) )
goto V_537;
V_419 . V_572 = F_196 ( V_273 -> V_277 ) ;
V_419 . V_573 = F_196 ( V_273 -> V_276 ) ;
if ( F_289 ( V_403 , V_574 , sizeof( V_419 ) , & V_419 ) )
goto V_537;
return F_297 ( V_403 , V_405 ) ;
V_537:
F_296 ( V_403 , V_405 ) ;
return - V_433 ;
}
static void F_205 ( int V_344 , struct V_4 * V_5 ,
struct V_272 * V_273 )
{
struct V_402 * V_403 ;
struct V_84 * V_84 = F_32 ( V_5 -> V_7 ) ;
int V_107 = - V_121 ;
V_403 = F_307 ( F_340 () , V_120 ) ;
if ( V_403 == NULL )
goto V_472;
V_107 = F_341 ( V_403 , V_5 , V_273 , 0 , 0 , V_344 , 0 ) ;
if ( V_107 < 0 ) {
F_21 ( V_107 == - V_433 ) ;
F_308 ( V_403 ) ;
goto V_472;
}
F_311 ( V_403 , V_84 , 0 , V_575 , NULL , V_120 ) ;
return;
V_472:
if ( V_107 < 0 )
F_312 ( V_84 , V_575 , V_107 ) ;
}
static void F_245 ( int V_344 , struct V_13 * V_14 )
{
F_310 ( V_344 ? : V_327 , V_14 ) ;
switch ( V_344 ) {
case V_327 :
if ( ! ( V_14 -> V_9 -> V_576 ) )
F_255 ( V_14 -> V_9 ) ;
if ( V_14 -> V_5 -> V_49 . V_55 )
F_54 ( V_14 ) ;
break;
case V_137 :
if ( V_14 -> V_5 -> V_49 . V_55 )
F_55 ( V_14 ) ;
F_157 ( V_14 -> V_5 , & V_14 -> V_100 ) ;
F_189 ( & V_14 -> V_9 -> V_97 ) ;
if ( F_112 ( V_14 -> V_9 ) )
F_342 ( & V_14 -> V_9 -> V_97 ) ;
break;
}
}
static void F_109 ( int V_344 , struct V_13 * V_14 )
{
F_79 () ;
if ( F_94 ( V_14 -> V_5 -> V_43 == 0 ) )
F_245 ( V_344 , V_14 ) ;
F_93 () ;
}
static
int F_343 ( V_87 * V_577 , int V_578 ,
void T_6 * V_579 , T_15 * V_580 , T_9 * V_581 )
{
int * V_582 = V_577 -> V_123 ;
int V_583 = * V_582 ;
T_9 V_377 = * V_581 ;
V_87 V_584 ;
int V_150 ;
V_584 = * V_577 ;
V_584 . V_123 = & V_583 ;
V_150 = F_344 ( & V_584 , V_578 , V_579 , V_580 , V_581 ) ;
if ( V_578 )
V_150 = F_58 ( V_577 , V_582 , V_583 ) ;
if ( V_150 )
* V_581 = V_377 ;
return V_150 ;
}
static void F_345 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_49 . V_115 )
F_232 ( NULL , V_138 , V_5 -> V_7 ) ;
else
F_232 ( NULL , V_129 , V_5 -> V_7 ) ;
}
static void F_346 ( struct V_84 * V_84 , T_2 V_85 )
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
F_345 ( V_5 ) ;
}
}
F_140 () ;
}
static int F_347 ( struct V_87 * V_88 , int * V_89 , int V_85 )
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
F_346 ( V_84 , V_85 ) ;
} else if ( ( ! V_85 ) ^ ( ! V_90 ) )
F_345 ( (struct V_4 * ) V_88 -> V_93 ) ;
F_61 () ;
return 0 ;
}
static
int F_348 ( V_87 * V_577 , int V_578 ,
void T_6 * V_579 , T_15 * V_580 , T_9 * V_581 )
{
int * V_582 = V_577 -> V_123 ;
int V_583 = * V_582 ;
T_9 V_377 = * V_581 ;
V_87 V_584 ;
int V_150 ;
V_584 = * V_577 ;
V_584 . V_123 = & V_583 ;
V_150 = F_344 ( & V_584 , V_578 , V_579 , V_580 , V_581 ) ;
if ( V_578 )
V_150 = F_347 ( V_577 , V_582 , V_583 ) ;
if ( V_150 )
* V_581 = V_377 ;
return V_150 ;
}
static int F_349 ( struct V_84 * V_84 , char * V_585 ,
struct V_4 * V_5 , struct V_475 * V_89 )
{
int V_173 ;
struct V_586 * V_587 ;
char V_588 [ sizeof( L_35 ) + V_524 ] ;
V_587 = F_350 ( & V_589 , sizeof( * V_587 ) , V_33 ) ;
if ( V_587 == NULL )
goto V_119;
for ( V_173 = 0 ; V_587 -> V_590 [ V_173 ] . V_123 ; V_173 ++ ) {
V_587 -> V_590 [ V_173 ] . V_123 += ( char * ) V_89 - ( char * ) & V_475 ;
V_587 -> V_590 [ V_173 ] . V_93 = V_5 ;
V_587 -> V_590 [ V_173 ] . V_91 = V_84 ;
}
snprintf ( V_588 , sizeof( V_588 ) , L_36 , V_585 ) ;
V_587 -> V_591 = F_351 ( V_84 , V_588 , V_587 -> V_590 ) ;
if ( V_587 -> V_591 == NULL )
goto free;
V_89 -> V_52 = V_587 ;
return 0 ;
free:
F_17 ( V_587 ) ;
V_119:
return - V_121 ;
}
static void F_352 ( struct V_475 * V_89 )
{
struct V_586 * V_587 ;
if ( V_89 -> V_52 == NULL )
return;
V_587 = V_89 -> V_52 ;
V_89 -> V_52 = NULL ;
F_353 ( V_587 -> V_591 ) ;
F_17 ( V_587 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_354 ( V_5 -> V_7 , V_5 -> V_53 , L_37 ,
& V_592 ) ;
F_349 ( F_32 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_42 ,
V_5 , & V_5 -> V_49 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_352 ( & V_5 -> V_49 ) ;
F_355 ( V_5 -> V_53 ) ;
}
static int T_11 F_356 ( struct V_84 * V_84 )
{
int V_107 ;
struct V_475 * V_593 , * V_594 ;
V_107 = - V_38 ;
V_593 = & V_475 ;
V_594 = & V_595 ;
if ( ! F_144 ( V_84 , & V_596 ) ) {
V_593 = F_350 ( V_593 , sizeof( V_475 ) , V_33 ) ;
if ( V_593 == NULL )
goto V_597;
V_594 = F_350 ( V_594 , sizeof( V_595 ) , V_33 ) ;
if ( V_594 == NULL )
goto V_598;
} else {
V_594 -> V_282 = V_599 . V_282 ;
V_594 -> V_115 = V_599 . V_115 ;
}
V_84 -> V_28 . V_92 = V_593 ;
V_84 -> V_28 . V_50 = V_594 ;
#ifdef F_357
V_107 = F_349 ( V_84 , L_38 , NULL , V_593 ) ;
if ( V_107 < 0 )
goto V_600;
V_107 = F_349 ( V_84 , L_39 , NULL , V_594 ) ;
if ( V_107 < 0 )
goto V_601;
#endif
return 0 ;
#ifdef F_357
V_601:
F_352 ( V_593 ) ;
V_600:
F_17 ( V_594 ) ;
#endif
V_598:
F_17 ( V_593 ) ;
V_597:
return V_107 ;
}
static void T_12 F_358 ( struct V_84 * V_84 )
{
#ifdef F_357
F_352 ( V_84 -> V_28 . V_50 ) ;
F_352 ( V_84 -> V_28 . V_92 ) ;
#endif
if ( ! F_144 ( V_84 , & V_596 ) ) {
F_17 ( V_84 -> V_28 . V_50 ) ;
F_17 ( V_84 -> V_28 . V_92 ) ;
}
}
int F_359 ( struct V_342 * V_602 )
{
return F_360 ( & V_128 , V_602 ) ;
}
int F_361 ( struct V_342 * V_602 )
{
return F_362 ( & V_128 , V_602 ) ;
}
int T_13 F_363 ( void )
{
int V_173 , V_107 ;
V_107 = F_364 () ;
if ( V_107 < 0 ) {
F_365 ( L_40 ,
V_41 , V_107 ) ;
goto V_119;
}
V_107 = F_273 ( & V_603 ) ;
if ( V_107 < 0 )
goto V_604;
F_207 () ;
if ( ! F_28 ( V_596 . V_605 ) )
V_107 = - V_38 ;
F_61 () ;
if ( V_107 )
goto V_606;
for ( V_173 = 0 ; V_173 < V_360 ; V_173 ++ )
F_366 ( & V_125 [ V_173 ] ) ;
F_367 ( & V_607 ) ;
F_204 ( 0 ) ;
V_107 = F_368 ( & V_608 ) ;
if ( V_107 < 0 )
goto V_609;
V_107 = F_369 ( V_610 , V_611 , NULL , F_339 ,
NULL ) ;
if ( V_107 < 0 )
goto V_472;
F_369 ( V_610 , V_327 , F_286 , NULL , NULL ) ;
F_369 ( V_610 , V_137 , F_281 , NULL , NULL ) ;
F_369 ( V_610 , V_612 , F_306 ,
F_303 , NULL ) ;
F_369 ( V_610 , V_458 , NULL ,
F_304 , NULL ) ;
F_369 ( V_610 , V_462 , NULL ,
F_305 , NULL ) ;
F_370 () ;
return 0 ;
V_472:
F_371 ( & V_608 ) ;
V_609:
F_372 ( & V_607 ) ;
V_606:
F_275 ( & V_603 ) ;
V_604:
F_373 () ;
V_119:
return V_107 ;
}
void F_374 ( void )
{
struct V_6 * V_7 ;
int V_173 ;
F_372 ( & V_607 ) ;
F_275 ( & V_603 ) ;
F_373 () ;
F_207 () ;
F_375 ( & V_608 ) ;
F_57 (&init_net, dev) {
if ( F_49 ( V_7 ) == NULL )
continue;
F_217 ( V_7 , 1 ) ;
}
F_217 ( V_596 . V_605 , 2 ) ;
F_97 ( & V_117 ) ;
for ( V_173 = 0 ; V_173 < V_360 ; V_173 ++ )
F_21 ( ! F_376 ( & V_125 [ V_173 ] ) ) ;
F_98 ( & V_117 ) ;
F_8 ( & V_395 ) ;
F_61 () ;
}
