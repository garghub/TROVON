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
static void F_6 ( struct V_8 * V_9 )
{
if ( F_7 ( & V_9 -> V_10 ) )
F_8 ( V_9 ) ;
}
static void F_9 ( struct V_8 * V_9 ,
enum V_11 V_12 ,
unsigned long V_13 )
{
if ( ! F_7 ( & V_9 -> V_10 ) )
F_10 ( V_9 ) ;
switch ( V_12 ) {
case V_14 :
V_9 -> V_10 . V_15 = V_16 ;
break;
case V_17 :
V_9 -> V_10 . V_15 = V_18 ;
break;
default:
break;
}
V_9 -> V_10 . V_19 = V_20 + V_13 ;
F_11 ( & V_9 -> V_10 ) ;
}
static int F_12 ( struct V_4 * V_5 )
{
if ( F_13 ( ( void V_21 * * ) V_5 -> V_22 . V_23 ,
sizeof( struct V_24 ) ,
F_14 ( struct V_24 ) ) < 0 )
goto V_25;
V_5 -> V_22 . V_26 = F_15 ( sizeof( struct V_27 ) ,
V_28 ) ;
if ( ! V_5 -> V_22 . V_26 )
goto V_29;
V_5 -> V_22 . V_30 = F_15 ( sizeof( struct V_31 ) ,
V_28 ) ;
if ( ! V_5 -> V_22 . V_30 )
goto V_32;
return 0 ;
V_32:
F_16 ( V_5 -> V_22 . V_26 ) ;
V_29:
F_17 ( ( void V_21 * * ) V_5 -> V_22 . V_23 ) ;
V_25:
return - V_33 ;
}
static void F_18 ( struct V_4 * V_5 )
{
F_16 ( V_5 -> V_22 . V_30 ) ;
F_16 ( V_5 -> V_22 . V_26 ) ;
F_17 ( ( void V_21 * * ) V_5 -> V_22 . V_23 ) ;
}
void F_19 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
F_20 ( ! F_21 ( & V_5 -> V_34 ) ) ;
F_20 ( V_5 -> V_35 != NULL ) ;
#ifdef F_22
F_23 ( L_1 , V_36 , V_7 ? V_7 -> V_37 : L_2 ) ;
#endif
F_24 ( V_7 ) ;
if ( ! V_5 -> V_38 ) {
F_25 ( L_3 , V_5 ) ;
return;
}
F_18 ( V_5 ) ;
F_26 ( V_5 , V_39 ) ;
}
static struct V_4 * F_27 ( struct V_6 * V_7 )
{
struct V_4 * V_40 ;
F_28 () ;
if ( V_7 -> V_41 < V_42 )
return NULL ;
V_40 = F_15 ( sizeof( struct V_4 ) , V_28 ) ;
if ( V_40 == NULL )
return NULL ;
F_29 ( & V_40 -> V_43 ) ;
V_40 -> V_7 = V_7 ;
F_30 ( & V_40 -> V_34 ) ;
memcpy ( & V_40 -> V_44 , F_31 ( V_7 ) -> V_23 . V_45 , sizeof( V_40 -> V_44 ) ) ;
V_40 -> V_44 . V_46 = V_7 -> V_41 ;
V_40 -> V_44 . V_47 = NULL ;
V_40 -> V_48 = F_32 ( V_7 , & V_49 ) ;
if ( V_40 -> V_48 == NULL ) {
F_16 ( V_40 ) ;
return NULL ;
}
if ( V_40 -> V_44 . V_50 )
F_33 ( V_7 ) ;
F_34 ( V_7 ) ;
if ( F_12 ( V_40 ) < 0 ) {
F_35 ( ( V_51
L_4 ,
V_36 , V_7 -> V_37 ) ) ;
F_36 ( & V_49 , V_40 -> V_48 ) ;
F_24 ( V_7 ) ;
F_16 ( V_40 ) ;
return NULL ;
}
if ( F_37 ( V_40 ) < 0 ) {
F_35 ( ( V_51
L_5 ,
V_36 , V_7 -> V_37 ) ) ;
F_36 ( & V_49 , V_40 -> V_48 ) ;
V_40 -> V_38 = 1 ;
F_19 ( V_40 ) ;
return NULL ;
}
F_38 ( V_40 ) ;
if ( V_7 -> V_52 & ( V_53 | V_54 ) )
V_40 -> V_44 . V_55 = - 1 ;
#if F_39 ( V_56 )
if ( V_7 -> type == V_57 && ( V_7 -> V_58 & V_59 ) ) {
F_40 ( L_6 , V_7 -> V_37 ) ;
V_40 -> V_44 . V_60 = 0 ;
}
#endif
#ifdef F_41
F_30 ( & V_40 -> V_61 ) ;
F_42 ( & V_40 -> V_62 , V_63 , ( unsigned long ) V_40 ) ;
if ( ( V_7 -> V_52 & V_54 ) ||
V_7 -> type == V_64 ||
V_7 -> type == V_65 ||
V_7 -> type == V_57 ||
V_7 -> type == V_66 ) {
V_40 -> V_44 . V_67 = - 1 ;
} else {
F_38 ( V_40 ) ;
V_63 ( ( unsigned long ) V_40 ) ;
}
#endif
if ( F_43 ( V_7 ) && F_4 ( V_7 ) )
V_40 -> V_68 |= V_69 ;
F_44 ( V_40 ) ;
V_40 -> V_70 = V_20 ;
F_2 ( V_40 ) ;
F_45 ( V_7 -> V_71 , V_40 ) ;
F_46 ( V_7 , & V_72 ) ;
if ( V_40 -> V_44 . V_50 && ( V_7 -> V_52 & V_73 ) )
F_46 ( V_7 , & V_74 ) ;
return V_40 ;
}
static struct V_4 * F_47 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 ) {
V_5 = F_27 ( V_7 ) ;
if ( ! V_5 )
return NULL ;
}
if ( V_7 -> V_52 & V_75 )
F_49 ( V_5 ) ;
return V_5 ;
}
static int F_50 ( int type )
{
int V_76 = F_51 ( sizeof( struct V_77 ) )
+ F_52 ( 4 ) ;
if ( type == - 1 || type == V_78 )
V_76 += F_52 ( 4 ) ;
#ifdef F_53
if ( type == - 1 || type == V_79 )
V_76 += F_52 ( 4 ) ;
#endif
return V_76 ;
}
static int F_54 ( struct V_80 * V_81 , int V_82 ,
struct V_83 * V_84 , T_1 V_85 ,
T_1 V_86 , int V_87 , unsigned int V_52 ,
int type )
{
struct V_88 * V_89 ;
struct V_77 * V_90 ;
V_89 = F_55 ( V_81 , V_85 , V_86 , V_87 , sizeof( struct V_77 ) ,
V_52 ) ;
if ( V_89 == NULL )
return - V_91 ;
V_90 = F_56 ( V_89 ) ;
V_90 -> V_92 = V_93 ;
if ( F_57 ( V_81 , V_94 , V_82 ) < 0 )
goto V_95;
if ( ( type == - 1 || type == V_78 ) &&
F_57 ( V_81 , V_78 , V_84 -> V_50 ) < 0 )
goto V_95;
#ifdef F_53
if ( ( type == - 1 || type == V_79 ) &&
F_57 ( V_81 , V_79 ,
V_84 -> V_96 ) < 0 )
goto V_95;
#endif
return F_58 ( V_81 , V_89 ) ;
V_95:
F_59 ( V_81 , V_89 ) ;
return - V_91 ;
}
void F_60 ( struct V_97 * V_97 , int type , int V_82 ,
struct V_83 * V_84 )
{
struct V_80 * V_81 ;
int V_98 = - V_99 ;
V_81 = F_61 ( F_50 ( type ) , V_100 ) ;
if ( V_81 == NULL )
goto V_101;
V_98 = F_54 ( V_81 , V_82 , V_84 , 0 , 0 ,
V_102 , 0 , type ) ;
if ( V_98 < 0 ) {
F_20 ( V_98 == - V_91 ) ;
F_62 ( V_81 ) ;
goto V_101;
}
F_63 ( V_81 , V_97 , 0 , V_103 , NULL , V_100 ) ;
return;
V_101:
F_64 ( V_97 , V_103 , V_98 ) ;
}
static int F_65 ( struct V_80 * V_104 ,
struct V_88 * V_89 ,
void * V_105 )
{
struct V_97 * V_97 = F_66 ( V_104 -> V_106 ) ;
struct V_107 * V_108 [ V_109 + 1 ] ;
struct V_77 * V_90 ;
struct V_80 * V_81 ;
struct V_83 * V_84 ;
struct V_4 * V_110 ;
struct V_6 * V_7 ;
int V_82 ;
int V_98 ;
V_98 = F_67 ( V_89 , sizeof( * V_90 ) , V_108 , V_109 ,
V_111 ) ;
if ( V_98 < 0 )
goto V_101;
V_98 = V_112 ;
if ( ! V_108 [ V_94 ] )
goto V_101;
V_82 = F_68 ( V_108 [ V_94 ] ) ;
switch ( V_82 ) {
case V_113 :
V_84 = V_97 -> V_23 . V_114 ;
break;
case V_115 :
V_84 = V_97 -> V_23 . V_45 ;
break;
default:
V_7 = F_69 ( V_97 , V_82 ) ;
if ( V_7 == NULL )
goto V_101;
V_110 = F_48 ( V_7 ) ;
if ( V_110 == NULL )
goto V_101;
V_84 = & V_110 -> V_44 ;
break;
}
V_98 = - V_99 ;
V_81 = F_61 ( F_50 ( - 1 ) , V_100 ) ;
if ( V_81 == NULL )
goto V_101;
V_98 = F_54 ( V_81 , V_82 , V_84 ,
F_70 ( V_104 ) . V_85 ,
V_89 -> V_116 , V_102 , 0 ,
- 1 ) ;
if ( V_98 < 0 ) {
F_20 ( V_98 == - V_91 ) ;
F_62 ( V_81 ) ;
goto V_101;
}
V_98 = F_71 ( V_81 , V_97 , F_70 ( V_104 ) . V_85 ) ;
V_101:
return V_98 ;
}
static void F_72 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_117 ;
if ( ! V_5 )
return;
V_7 = V_5 -> V_7 ;
if ( V_5 -> V_44 . V_50 )
F_33 ( V_7 ) ;
if ( V_7 -> V_52 & V_73 ) {
if ( V_5 -> V_44 . V_50 )
F_46 ( V_7 , & V_74 ) ;
else
F_73 ( V_7 , & V_74 ) ;
}
F_74 (ifa, &idev->addr_list, if_list) {
if ( V_117 -> V_52 & V_118 )
continue;
if ( V_5 -> V_44 . V_50 )
F_75 ( V_117 ) ;
else
F_76 ( V_117 ) ;
}
F_60 ( F_31 ( V_7 ) , V_78 ,
V_7 -> V_82 , & V_5 -> V_44 ) ;
}
static void F_77 ( struct V_97 * V_97 , T_2 V_119 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_78 (net, dev) {
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
int V_120 = ( ! V_5 -> V_44 . V_50 ) ^ ( ! V_119 ) ;
V_5 -> V_44 . V_50 = V_119 ;
if ( V_120 )
F_72 ( V_5 ) ;
}
}
}
static int F_79 ( struct V_121 * V_122 , int * V_123 , int V_119 )
{
struct V_97 * V_97 ;
int V_124 ;
if ( ! F_80 () )
return F_81 () ;
V_97 = (struct V_97 * ) V_122 -> V_125 ;
V_124 = * V_123 ;
* V_123 = V_119 ;
if ( V_123 == & V_97 -> V_23 . V_45 -> V_50 ) {
if ( ( ! V_119 ) ^ ( ! V_124 ) )
F_60 ( V_97 , V_78 ,
V_115 ,
V_97 -> V_23 . V_45 ) ;
F_82 () ;
return 0 ;
}
if ( V_123 == & V_97 -> V_23 . V_114 -> V_50 ) {
V_97 -> V_23 . V_45 -> V_50 = V_119 ;
F_77 ( V_97 , V_119 ) ;
if ( ( ! V_119 ) ^ ( ! V_124 ) )
F_60 ( V_97 , V_78 ,
V_113 ,
V_97 -> V_23 . V_114 ) ;
} else if ( ( ! V_119 ) ^ ( ! V_124 ) )
F_72 ( (struct V_4 * ) V_122 -> V_126 ) ;
F_82 () ;
if ( V_119 )
F_83 ( V_97 ) ;
return 1 ;
}
void F_84 ( struct V_8 * V_9 )
{
F_20 ( ! F_85 ( & V_9 -> V_127 ) ) ;
#ifdef F_22
F_23 ( L_7 , V_36 ) ;
#endif
F_86 ( V_9 -> V_5 ) ;
if ( F_7 ( & V_9 -> V_10 ) )
F_87 ( L_8 , V_9 ) ;
if ( V_9 -> V_128 != V_129 ) {
F_25 ( L_9 , V_9 ) ;
return;
}
F_88 ( V_9 -> V_130 ) ;
F_26 ( V_9 , V_39 ) ;
}
static void
F_89 ( struct V_4 * V_5 , struct V_8 * V_9 )
{
struct V_131 * V_123 ;
int V_132 = F_90 ( & V_9 -> V_133 ) ;
F_91 (p, &idev->addr_list) {
struct V_8 * V_117
= F_92 ( V_123 , struct V_8 , V_134 ) ;
if ( V_132 >= F_90 ( & V_117 -> V_133 ) )
break;
}
F_93 ( & V_9 -> V_134 , V_123 ) ;
}
static T_1 F_94 ( const struct V_135 * V_133 )
{
return F_95 ( F_96 ( V_133 ) , V_136 ) ;
}
static struct V_8 *
F_97 ( struct V_4 * V_5 , const struct V_135 * V_133 , int V_137 ,
int V_138 , T_1 V_52 )
{
struct V_8 * V_117 = NULL ;
struct V_139 * V_130 ;
unsigned int V_140 ;
int V_98 = 0 ;
int V_141 = F_98 ( V_133 ) ;
if ( V_141 == V_142 ||
V_141 & V_143 ||
( ! ( V_5 -> V_7 -> V_52 & V_54 ) &&
V_141 & V_144 ) )
return F_99 ( - V_145 ) ;
F_100 () ;
if ( V_5 -> V_38 ) {
V_98 = - V_146 ;
goto V_147;
}
if ( V_5 -> V_44 . V_148 ) {
V_98 = - V_149 ;
goto V_147;
}
F_101 ( & V_150 ) ;
if ( F_102 ( F_31 ( V_5 -> V_7 ) , V_133 , V_5 -> V_7 ) ) {
F_35 ( ( L_10 ) ) ;
V_98 = - V_151 ;
goto V_152;
}
V_117 = F_15 ( sizeof( struct V_8 ) , V_100 ) ;
if ( V_117 == NULL ) {
F_35 ( ( L_11 ) ) ;
V_98 = - V_99 ;
goto V_152;
}
V_130 = F_103 ( V_5 , V_133 , false ) ;
if ( F_104 ( V_130 ) ) {
V_98 = F_105 ( V_130 ) ;
goto V_152;
}
V_117 -> V_133 = * V_133 ;
F_106 ( & V_117 -> V_43 ) ;
F_106 ( & V_117 -> V_153 ) ;
F_107 ( & V_117 -> V_10 ) ;
F_108 ( & V_117 -> V_127 ) ;
V_117 -> V_10 . V_154 = ( unsigned long ) V_117 ;
V_117 -> V_138 = V_138 ;
V_117 -> V_155 = V_137 ;
V_117 -> V_52 = V_52 | V_118 ;
V_117 -> V_1 = V_117 -> V_70 = V_20 ;
V_117 -> V_130 = V_130 ;
V_117 -> V_5 = V_5 ;
F_38 ( V_5 ) ;
F_10 ( V_117 ) ;
V_140 = F_94 ( V_133 ) ;
F_109 ( & V_117 -> V_127 , & V_156 [ V_140 ] ) ;
F_110 ( & V_150 ) ;
F_111 ( & V_5 -> V_43 ) ;
F_89 ( V_5 , V_117 ) ;
#ifdef F_41
if ( V_117 -> V_52 & V_157 ) {
F_112 ( & V_117 -> V_158 , & V_5 -> V_61 ) ;
F_10 ( V_117 ) ;
}
#endif
F_10 ( V_117 ) ;
F_113 ( & V_5 -> V_43 ) ;
V_147:
F_114 () ;
if ( F_115 ( V_98 == 0 ) )
F_116 ( & V_159 , V_160 , V_117 ) ;
else {
F_16 ( V_117 ) ;
V_117 = F_99 ( V_98 ) ;
}
return V_117 ;
V_152:
F_110 ( & V_150 ) ;
goto V_147;
}
static void F_117 ( struct V_8 * V_9 )
{
struct V_8 * V_117 , * V_161 ;
struct V_4 * V_5 = V_9 -> V_5 ;
int V_128 ;
int V_162 = 0 , V_163 = 0 ;
unsigned long V_19 = V_20 ;
F_118 ( & V_9 -> V_153 ) ;
V_128 = V_9 -> V_128 ;
V_9 -> V_128 = V_129 ;
F_119 ( & V_9 -> V_153 ) ;
if ( V_128 == V_129 )
goto V_152;
F_118 ( & V_150 ) ;
F_120 ( & V_9 -> V_127 ) ;
F_119 ( & V_150 ) ;
F_121 ( & V_5 -> V_43 ) ;
#ifdef F_41
if ( V_9 -> V_52 & V_157 ) {
F_122 ( & V_9 -> V_158 ) ;
if ( V_9 -> V_164 ) {
F_123 ( V_9 -> V_164 ) ;
V_9 -> V_164 = NULL ;
}
F_8 ( V_9 ) ;
}
#endif
F_124 (ifa, ifn, &idev->addr_list, if_list) {
if ( V_117 == V_9 ) {
F_125 ( & V_9 -> V_134 ) ;
F_8 ( V_9 ) ;
if ( ! ( V_9 -> V_52 & V_165 ) || V_163 > 0 )
break;
V_162 = 1 ;
continue;
} else if ( V_9 -> V_52 & V_165 ) {
if ( F_126 ( & V_117 -> V_133 , & V_9 -> V_133 ,
V_9 -> V_155 ) ) {
if ( V_117 -> V_52 & V_165 ) {
V_163 = 1 ;
if ( V_162 )
break;
} else {
unsigned long V_166 ;
if ( ! V_163 )
V_163 = - 1 ;
F_101 ( & V_117 -> V_43 ) ;
V_166 = F_127 ( V_117 -> V_167 , V_3 ) ;
if ( F_128 ( V_19 ,
V_117 -> V_70 + V_166 * V_3 ) )
V_19 = V_117 -> V_70 + V_166 * V_3 ;
F_110 ( & V_117 -> V_43 ) ;
}
}
}
}
F_129 ( & V_5 -> V_43 ) ;
F_6 ( V_9 ) ;
F_130 ( V_168 , V_9 ) ;
F_116 ( & V_159 , V_169 , V_9 ) ;
if ( ( V_9 -> V_52 & V_165 ) && V_163 < 1 ) {
struct V_135 V_170 ;
struct V_139 * V_130 ;
F_131 ( & V_170 , & V_9 -> V_133 , V_9 -> V_155 ) ;
V_130 = F_132 ( & V_170 ,
V_9 -> V_155 ,
V_9 -> V_5 -> V_7 ,
0 , V_171 | V_172 ) ;
if ( V_130 ) {
if ( V_163 == 0 ) {
F_133 ( V_130 ) ;
V_130 = NULL ;
} else if ( ! ( V_130 -> V_173 & V_174 ) ) {
F_134 ( V_130 , V_19 ) ;
}
}
F_88 ( V_130 ) ;
}
F_135 ( V_9 ) ;
V_152:
F_123 ( V_9 ) ;
}
static int F_136 ( struct V_8 * V_9 , struct V_8 * V_175 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_135 V_133 , * V_176 ;
unsigned long V_177 , V_178 , V_179 , V_180 ;
unsigned long V_181 ;
int V_182 ;
int V_183 = 0 ;
int V_184 ;
T_1 V_185 ;
unsigned long V_186 = V_20 ;
F_111 ( & V_5 -> V_43 ) ;
if ( V_175 ) {
F_118 ( & V_175 -> V_43 ) ;
memcpy ( & V_133 . V_187 [ 8 ] , & V_175 -> V_133 . V_187 [ 8 ] , 8 ) ;
F_119 ( & V_175 -> V_43 ) ;
V_176 = & V_133 ;
} else {
V_176 = NULL ;
}
V_188:
F_38 ( V_5 ) ;
if ( V_5 -> V_44 . V_67 <= 0 ) {
F_113 ( & V_5 -> V_43 ) ;
F_40 ( L_12 , V_36 ) ;
F_86 ( V_5 ) ;
V_183 = - 1 ;
goto V_152;
}
F_118 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_189 ++ >= V_5 -> V_44 . V_190 ) {
V_5 -> V_44 . V_67 = - 1 ;
F_119 ( & V_9 -> V_43 ) ;
F_113 ( & V_5 -> V_43 ) ;
F_25 ( L_13 ,
V_36 ) ;
F_86 ( V_5 ) ;
V_183 = - 1 ;
goto V_152;
}
F_10 ( V_9 ) ;
memcpy ( V_133 . V_187 , V_9 -> V_133 . V_187 , 8 ) ;
F_137 ( V_5 , V_176 ) ;
memcpy ( & V_133 . V_187 [ 8 ] , V_5 -> V_191 , 8 ) ;
V_180 = ( V_186 - V_9 -> V_70 ) / V_3 ;
V_178 = F_138 ( V_192 ,
V_9 -> V_167 ,
V_5 -> V_44 . V_193 + V_180 ) ;
V_177 = F_138 ( V_192 ,
V_9 -> V_194 ,
V_5 -> V_44 . V_195 + V_180 -
V_5 -> V_44 . V_196 ) ;
V_182 = V_9 -> V_155 ;
V_184 = V_5 -> V_44 . V_184 ;
V_179 = V_9 -> V_70 ;
F_119 ( & V_9 -> V_43 ) ;
V_181 = V_5 -> V_44 . V_190 *
V_5 -> V_44 . V_197 *
V_5 -> V_48 -> V_198 / V_3 ;
F_113 ( & V_5 -> V_43 ) ;
if ( V_177 <= V_181 ) {
F_123 ( V_9 ) ;
F_86 ( V_5 ) ;
V_183 = - 1 ;
goto V_152;
}
V_185 = V_157 ;
if ( V_9 -> V_52 & V_199 )
V_185 |= V_199 ;
V_175 = ! V_184 ||
F_139 ( V_5 ) < V_184 ?
F_97 ( V_5 , & V_133 , V_182 ,
F_98 ( & V_133 ) & V_200 ,
V_185 ) : NULL ;
if ( ! V_175 || F_104 ( V_175 ) ) {
F_123 ( V_9 ) ;
F_86 ( V_5 ) ;
F_40 ( L_14 , V_36 ) ;
V_176 = & V_133 ;
F_111 ( & V_5 -> V_43 ) ;
goto V_188;
}
F_118 ( & V_175 -> V_43 ) ;
V_175 -> V_164 = V_9 ;
V_175 -> V_167 = V_178 ;
V_175 -> V_194 = V_177 ;
V_175 -> V_1 = V_186 ;
V_175 -> V_70 = V_179 ;
F_119 ( & V_175 -> V_43 ) ;
F_140 ( V_175 ) ;
F_123 ( V_175 ) ;
F_86 ( V_5 ) ;
V_152:
return V_183 ;
}
static inline int F_141 ( int type )
{
if ( type & ( V_201 | V_202 | V_144 ) )
return 1 ;
return 0 ;
}
static int F_142 ( struct V_97 * V_97 ,
struct V_203 * V_204 ,
struct V_205 * V_206 ,
int V_207 )
{
int V_183 ;
if ( V_207 <= V_204 -> V_208 ) {
switch ( V_207 ) {
case V_209 :
V_183 = V_204 -> V_210 ;
break;
case V_211 :
V_183 = V_204 -> V_212 ;
break;
default:
V_183 = ! ! F_143 ( V_207 , V_204 -> V_213 ) ;
}
goto V_152;
}
switch ( V_207 ) {
case V_214 :
V_183 = ! ! V_204 -> V_117 ;
break;
case V_215 :
V_183 = F_144 ( & V_204 -> V_117 -> V_133 , V_206 -> V_133 ) ;
break;
case V_209 :
V_183 = F_145 ( V_204 -> V_141 ) ;
if ( V_183 >= V_206 -> V_138 )
V_183 = - V_183 ;
else
V_183 -= 128 ;
V_204 -> V_210 = V_183 ;
break;
case V_216 :
V_183 = F_141 ( V_204 -> V_141 ) ||
! ( V_204 -> V_117 -> V_52 & ( V_217 | V_199 ) ) ;
break;
#ifdef F_146
case V_218 :
{
int V_219 = ! ( V_206 -> V_220 & V_221 ) ;
V_183 = ! ( V_204 -> V_117 -> V_52 & V_222 ) ^ V_219 ;
break;
}
#endif
case V_223 :
V_183 = ( ! V_206 -> V_82 ||
V_206 -> V_82 == V_204 -> V_117 -> V_5 -> V_7 -> V_82 ) ;
break;
case V_224 :
V_183 = F_147 ( V_97 ,
& V_204 -> V_117 -> V_133 , V_204 -> V_141 ,
V_204 -> V_117 -> V_5 -> V_7 -> V_82 ) == V_206 -> V_225 ;
break;
#ifdef F_41
case V_226 :
{
int V_227 = V_206 -> V_220 & ( V_228 | V_229 ) ?
! ! ( V_206 -> V_220 & V_229 ) :
V_204 -> V_117 -> V_5 -> V_44 . V_67 >= 2 ;
V_183 = ( ! ( V_204 -> V_117 -> V_52 & V_157 ) ) ^ V_227 ;
break;
}
#endif
case V_230 :
V_183 = ! ( F_148 ( & V_204 -> V_117 -> V_133 ) ^
F_148 ( V_206 -> V_133 ) ) ;
break;
case V_211 :
V_183 = F_149 ( & V_204 -> V_117 -> V_133 , V_206 -> V_133 ) ;
if ( V_183 > V_204 -> V_117 -> V_155 )
V_183 = V_204 -> V_117 -> V_155 ;
V_204 -> V_212 = V_183 ;
break;
default:
V_183 = 0 ;
}
if ( V_183 )
F_150 ( V_207 , V_204 -> V_213 ) ;
V_204 -> V_208 = V_207 ;
V_152:
return V_183 ;
}
int F_151 ( struct V_97 * V_97 , const struct V_6 * V_231 ,
const struct V_135 * V_232 , unsigned int V_220 ,
struct V_135 * V_233 )
{
struct V_203 V_234 [ 2 ] ,
* V_204 = & V_234 [ 0 ] , * V_235 = & V_234 [ 1 ] ;
struct V_205 V_206 ;
struct V_6 * V_7 ;
int V_236 ;
V_236 = F_152 ( V_232 ) ;
V_206 . V_133 = V_232 ;
V_206 . V_82 = V_231 ? V_231 -> V_82 : 0 ;
V_206 . V_138 = F_145 ( V_236 ) ;
V_206 . V_225 = F_147 ( V_97 , V_232 , V_236 , V_206 . V_82 ) ;
V_206 . V_220 = V_220 ;
V_235 -> V_208 = - 1 ;
V_235 -> V_117 = NULL ;
F_153 () ;
F_154 (net, dev) {
struct V_4 * V_5 ;
if ( ( ( V_236 & V_143 ) ||
V_206 . V_138 <= V_237 ) &&
V_206 . V_82 && V_7 -> V_82 != V_206 . V_82 )
continue;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
continue;
F_155 ( & V_5 -> V_43 ) ;
F_74 (score->ifa, &idev->addr_list, if_list) {
int V_207 ;
if ( ( V_204 -> V_117 -> V_52 & V_118 ) &&
( ! ( V_204 -> V_117 -> V_52 & V_199 ) ) )
continue;
V_204 -> V_141 = F_152 ( & V_204 -> V_117 -> V_133 ) ;
if ( F_156 ( V_204 -> V_141 == V_142 ||
V_204 -> V_141 & V_143 ) ) {
F_157 ( V_238
L_15
L_16 ,
V_7 -> V_37 ) ;
continue;
}
V_204 -> V_208 = - 1 ;
F_158 ( V_204 -> V_213 , V_239 ) ;
for ( V_207 = 0 ; V_207 < V_239 ; V_207 ++ ) {
int V_240 , V_241 ;
V_240 = F_142 ( V_97 , V_235 , & V_206 , V_207 ) ;
V_241 = F_142 ( V_97 , V_204 , & V_206 , V_207 ) ;
if ( V_240 > V_241 ) {
if ( V_207 == V_209 &&
V_204 -> V_210 > 0 ) {
goto V_242;
}
break;
} else if ( V_240 < V_241 ) {
if ( V_235 -> V_117 )
F_123 ( V_235 -> V_117 ) ;
F_10 ( V_204 -> V_117 ) ;
F_159 ( V_235 , V_204 ) ;
V_204 -> V_117 = V_235 -> V_117 ;
break;
}
}
}
V_242:
F_160 ( & V_5 -> V_43 ) ;
}
F_161 () ;
if ( ! V_235 -> V_117 )
return - V_145 ;
* V_233 = V_235 -> V_117 -> V_133 ;
F_123 ( V_235 -> V_117 ) ;
return 0 ;
}
int F_162 ( struct V_6 * V_7 , struct V_135 * V_133 ,
unsigned char V_243 )
{
struct V_4 * V_5 ;
int V_98 = - V_145 ;
F_153 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
struct V_8 * V_9 ;
F_155 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list) {
if ( V_9 -> V_138 == V_244 &&
! ( V_9 -> V_52 & V_243 ) ) {
* V_133 = V_9 -> V_133 ;
V_98 = 0 ;
break;
}
}
F_160 ( & V_5 -> V_43 ) ;
}
F_161 () ;
return V_98 ;
}
static int F_139 ( struct V_4 * V_5 )
{
int V_245 = 0 ;
struct V_8 * V_9 ;
F_155 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list)
V_245 ++ ;
F_160 ( & V_5 -> V_43 ) ;
return V_245 ;
}
int F_163 ( struct V_97 * V_97 , const struct V_135 * V_133 ,
struct V_6 * V_7 , int V_246 )
{
struct V_8 * V_9 ;
struct V_247 * V_248 ;
unsigned int V_140 = F_94 ( V_133 ) ;
F_100 () ;
F_164 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_165 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_97 ) )
continue;
if ( F_144 ( & V_9 -> V_133 , V_133 ) &&
! ( V_9 -> V_52 & V_118 ) &&
( V_7 == NULL || V_9 -> V_5 -> V_7 == V_7 ||
! ( V_9 -> V_138 & ( V_244 | V_249 ) || V_246 ) ) ) {
F_114 () ;
return 1 ;
}
}
F_114 () ;
return 0 ;
}
static bool F_102 ( struct V_97 * V_97 , const struct V_135 * V_133 ,
struct V_6 * V_7 )
{
unsigned int V_140 = F_94 ( V_133 ) ;
struct V_8 * V_9 ;
struct V_247 * V_248 ;
F_166 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_165 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_97 ) )
continue;
if ( F_144 ( & V_9 -> V_133 , V_133 ) ) {
if ( V_7 == NULL || V_9 -> V_5 -> V_7 == V_7 )
return true ;
}
}
return false ;
}
int F_167 ( const struct V_135 * V_133 , struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_8 * V_117 ;
int V_163 ;
V_163 = 0 ;
F_153 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
F_155 ( & V_5 -> V_43 ) ;
F_74 (ifa, &idev->addr_list, if_list) {
V_163 = F_126 ( V_133 , & V_117 -> V_133 ,
V_117 -> V_155 ) ;
if ( V_163 )
break;
}
F_160 ( & V_5 -> V_43 ) ;
}
F_161 () ;
return V_163 ;
}
struct V_8 * F_168 ( struct V_97 * V_97 , const struct V_135 * V_133 ,
struct V_6 * V_7 , int V_246 )
{
struct V_8 * V_9 , * V_250 = NULL ;
unsigned int V_140 = F_94 ( V_133 ) ;
struct V_247 * V_248 ;
F_100 () ;
F_169 (ifp, node, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_165 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_97 ) )
continue;
if ( F_144 ( & V_9 -> V_133 , V_133 ) ) {
if ( V_7 == NULL || V_9 -> V_5 -> V_7 == V_7 ||
! ( V_9 -> V_138 & ( V_244 | V_249 ) || V_246 ) ) {
V_250 = V_9 ;
F_10 ( V_9 ) ;
break;
}
}
}
F_114 () ;
return V_250 ;
}
static void F_170 ( struct V_8 * V_9 , int V_251 )
{
if ( V_9 -> V_52 & V_165 ) {
F_118 ( & V_9 -> V_43 ) ;
F_6 ( V_9 ) ;
V_9 -> V_52 |= V_118 ;
if ( V_251 )
V_9 -> V_52 |= V_252 ;
F_119 ( & V_9 -> V_43 ) ;
if ( V_251 )
F_130 ( 0 , V_9 ) ;
F_123 ( V_9 ) ;
#ifdef F_41
} else if ( V_9 -> V_52 & V_157 ) {
struct V_8 * V_164 ;
F_118 ( & V_9 -> V_43 ) ;
V_164 = V_9 -> V_164 ;
if ( V_164 ) {
F_10 ( V_164 ) ;
F_119 ( & V_9 -> V_43 ) ;
F_136 ( V_164 , V_9 ) ;
F_123 ( V_164 ) ;
} else {
F_119 ( & V_9 -> V_43 ) ;
}
F_117 ( V_9 ) ;
#endif
} else
F_117 ( V_9 ) ;
}
static int F_171 ( struct V_8 * V_9 )
{
int V_98 = - V_253 ;
F_101 ( & V_9 -> V_153 ) ;
if ( V_9 -> V_128 == V_254 ) {
V_9 -> V_128 = V_255 ;
V_98 = 0 ;
}
F_110 ( & V_9 -> V_153 ) ;
return V_98 ;
}
void F_172 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
if ( F_171 ( V_9 ) ) {
F_123 ( V_9 ) ;
return;
}
F_173 ( L_17 ,
V_9 -> V_5 -> V_7 -> V_37 , & V_9 -> V_133 ) ;
if ( V_5 -> V_44 . V_55 > 1 && ! V_5 -> V_44 . V_148 ) {
struct V_135 V_133 ;
V_133 . V_256 [ 0 ] = F_174 ( 0xfe800000 ) ;
V_133 . V_256 [ 1 ] = 0 ;
if ( ! F_175 ( V_133 . V_187 + 8 , V_5 -> V_7 ) &&
F_144 ( & V_9 -> V_133 , & V_133 ) ) {
V_5 -> V_44 . V_148 = 1 ;
F_40 ( L_18 ,
V_9 -> V_5 -> V_7 -> V_37 ) ;
}
}
F_170 ( V_9 , 1 ) ;
}
void F_176 ( struct V_6 * V_7 , const struct V_135 * V_133 )
{
struct V_135 V_257 ;
if ( V_7 -> V_52 & ( V_54 | V_53 ) )
return;
F_177 ( V_133 , & V_257 ) ;
F_46 ( V_7 , & V_257 ) ;
}
void F_178 ( struct V_4 * V_5 , const struct V_135 * V_133 )
{
struct V_135 V_257 ;
if ( V_5 -> V_7 -> V_52 & ( V_54 | V_53 ) )
return;
F_177 ( V_133 , & V_257 ) ;
F_179 ( V_5 , & V_257 ) ;
}
static void F_75 ( struct V_8 * V_9 )
{
struct V_135 V_133 ;
if ( V_9 -> V_155 == 127 )
return;
F_131 ( & V_133 , & V_9 -> V_133 , V_9 -> V_155 ) ;
if ( F_180 ( & V_133 ) )
return;
F_181 ( V_9 -> V_5 -> V_7 , & V_133 ) ;
}
static void F_76 ( struct V_8 * V_9 )
{
struct V_135 V_133 ;
if ( V_9 -> V_155 == 127 )
return;
F_131 ( & V_133 , & V_9 -> V_133 , V_9 -> V_155 ) ;
if ( F_180 ( & V_133 ) )
return;
F_182 ( V_9 -> V_5 , & V_133 ) ;
}
static int F_183 ( T_3 * V_258 , struct V_6 * V_7 )
{
if ( V_7 -> V_259 != V_260 )
return - 1 ;
memcpy ( V_258 , V_7 -> V_261 , 3 ) ;
memcpy ( V_258 + 5 , V_7 -> V_261 + 3 , 3 ) ;
if ( V_7 -> V_262 ) {
V_258 [ 3 ] = ( V_7 -> V_262 >> 8 ) & 0xFF ;
V_258 [ 4 ] = V_7 -> V_262 & 0xFF ;
} else {
V_258 [ 3 ] = 0xFF ;
V_258 [ 4 ] = 0xFE ;
V_258 [ 0 ] ^= 2 ;
}
return 0 ;
}
static int F_184 ( T_3 * V_258 , struct V_6 * V_7 )
{
if ( V_7 -> V_259 != V_263 )
return - 1 ;
memcpy ( V_258 , V_7 -> V_261 , 8 ) ;
V_258 [ 0 ] ^= 2 ;
return 0 ;
}
static int F_185 ( T_3 * V_258 , struct V_6 * V_7 )
{
if ( V_7 -> V_259 != V_264 )
return - 1 ;
memset ( V_258 , 0 , 7 ) ;
V_258 [ 7 ] = * ( T_3 * ) V_7 -> V_261 ;
return 0 ;
}
static int F_186 ( T_3 * V_258 , struct V_6 * V_7 )
{
if ( V_7 -> V_259 != V_265 )
return - 1 ;
memcpy ( V_258 , V_7 -> V_261 + 12 , 8 ) ;
V_258 [ 0 ] |= 2 ;
return 0 ;
}
static int F_187 ( T_3 * V_258 , T_4 V_133 )
{
if ( V_133 == 0 )
return - 1 ;
V_258 [ 0 ] = ( F_188 ( V_133 ) || F_189 ( V_133 ) ||
F_190 ( V_133 ) || F_191 ( V_133 ) ||
F_192 ( V_133 ) || F_193 ( V_133 ) ||
F_194 ( V_133 ) || F_195 ( V_133 ) ||
F_196 ( V_133 ) || F_197 ( V_133 ) ||
F_198 ( V_133 ) ) ? 0x00 : 0x02 ;
V_258 [ 1 ] = 0 ;
V_258 [ 2 ] = 0x5E ;
V_258 [ 3 ] = 0xFE ;
memcpy ( V_258 + 4 , & V_133 , 4 ) ;
return 0 ;
}
static int F_199 ( T_3 * V_258 , struct V_6 * V_7 )
{
if ( V_7 -> V_58 & V_59 )
return F_187 ( V_258 , * ( T_4 * ) V_7 -> V_261 ) ;
return - 1 ;
}
static int F_200 ( T_3 * V_258 , struct V_6 * V_7 )
{
return F_187 ( V_258 , * ( T_4 * ) V_7 -> V_261 ) ;
}
static int F_175 ( T_3 * V_258 , struct V_6 * V_7 )
{
switch ( V_7 -> type ) {
case V_266 :
case V_267 :
return F_183 ( V_258 , V_7 ) ;
case V_268 :
return F_185 ( V_258 , V_7 ) ;
case V_269 :
return F_186 ( V_258 , V_7 ) ;
case V_57 :
return F_199 ( V_258 , V_7 ) ;
case V_270 :
return F_200 ( V_258 , V_7 ) ;
case V_271 :
return F_184 ( V_258 , V_7 ) ;
}
return - 1 ;
}
static int F_201 ( T_3 * V_258 , struct V_4 * V_5 )
{
int V_98 = - 1 ;
struct V_8 * V_9 ;
F_155 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list) {
if ( V_9 -> V_138 == V_244 && ! ( V_9 -> V_52 & V_118 ) ) {
memcpy ( V_258 , V_9 -> V_133 . V_187 + 8 , 8 ) ;
V_98 = 0 ;
break;
}
}
F_160 ( & V_5 -> V_43 ) ;
return V_98 ;
}
static void F_202 ( struct V_4 * V_5 )
{
V_272:
F_203 ( V_5 -> V_191 , sizeof( V_5 -> V_191 ) ) ;
V_5 -> V_191 [ 0 ] &= ~ 0x02 ;
if ( V_5 -> V_191 [ 0 ] == 0xfd &&
( V_5 -> V_191 [ 1 ] & V_5 -> V_191 [ 2 ] & V_5 -> V_191 [ 3 ] & V_5 -> V_191 [ 4 ] & V_5 -> V_191 [ 5 ] & V_5 -> V_191 [ 6 ] ) == 0xff &&
( V_5 -> V_191 [ 7 ] & 0x80 ) )
goto V_272;
if ( ( V_5 -> V_191 [ 0 ] | V_5 -> V_191 [ 1 ] ) == 0 ) {
if ( V_5 -> V_191 [ 2 ] == 0x5e && V_5 -> V_191 [ 3 ] == 0xfe )
goto V_272;
if ( ( V_5 -> V_191 [ 2 ] | V_5 -> V_191 [ 3 ] | V_5 -> V_191 [ 4 ] | V_5 -> V_191 [ 5 ] | V_5 -> V_191 [ 6 ] | V_5 -> V_191 [ 7 ] ) == 0x00 )
goto V_272;
}
}
static void V_63 ( unsigned long V_154 )
{
struct V_4 * V_5 = (struct V_4 * ) V_154 ;
unsigned long V_19 ;
F_100 () ;
F_121 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_38 )
goto V_152;
F_202 ( V_5 ) ;
V_19 = V_20 +
V_5 -> V_44 . V_195 * V_3 -
V_5 -> V_44 . V_190 * V_5 -> V_44 . V_197 * V_5 -> V_48 -> V_198 -
V_5 -> V_44 . V_196 * V_3 ;
if ( F_128 ( V_19 , V_20 ) ) {
F_25 ( L_19 ,
V_36 , V_5 -> V_7 -> V_37 ) ;
goto V_152;
}
if ( ! F_204 ( & V_5 -> V_62 , V_19 ) )
F_38 ( V_5 ) ;
V_152:
F_129 ( & V_5 -> V_43 ) ;
F_114 () ;
F_86 ( V_5 ) ;
}
static void F_137 ( struct V_4 * V_5 , struct V_135 * V_176 )
{
if ( V_176 && memcmp ( V_5 -> V_191 , & V_176 -> V_187 [ 8 ] , 8 ) == 0 )
F_202 ( V_5 ) ;
}
static void
F_205 ( struct V_135 * V_273 , int V_274 , struct V_6 * V_7 ,
unsigned long V_19 , T_1 V_52 )
{
struct V_275 V_276 = {
. V_277 = V_278 ,
. V_279 = V_280 ,
. V_281 = V_7 -> V_82 ,
. V_282 = V_19 ,
. V_283 = V_274 ,
. V_284 = V_285 | V_52 ,
. V_286 . V_287 = F_31 ( V_7 ) ,
. V_288 = V_289 ,
} ;
V_276 . V_290 = * V_273 ;
#if F_39 ( V_56 )
if ( V_7 -> type == V_57 && ( V_7 -> V_52 & V_291 ) )
V_276 . V_284 |= V_292 ;
#endif
F_206 ( & V_276 ) ;
}
static struct V_139 * F_132 ( const struct V_135 * V_273 ,
int V_274 ,
const struct V_6 * V_7 ,
T_1 V_52 , T_1 V_293 )
{
struct V_294 * V_295 ;
struct V_139 * V_130 = NULL ;
struct V_296 * V_122 ;
V_122 = F_207 ( F_31 ( V_7 ) , V_278 ) ;
if ( V_122 == NULL )
return NULL ;
F_155 ( & V_122 -> V_297 ) ;
V_295 = F_208 ( & V_122 -> V_298 , V_273 , V_274 , NULL , 0 ) ;
if ( ! V_295 )
goto V_152;
for ( V_130 = V_295 -> V_299 ; V_130 ; V_130 = V_130 -> V_206 . V_300 ) {
if ( V_130 -> V_206 . V_7 -> V_82 != V_7 -> V_82 )
continue;
if ( ( V_130 -> V_173 & V_52 ) != V_52 )
continue;
if ( ( V_130 -> V_173 & V_293 ) != 0 )
continue;
F_209 ( & V_130 -> V_206 ) ;
break;
}
V_152:
F_160 ( & V_122 -> V_297 ) ;
return V_130 ;
}
static void F_210 ( struct V_6 * V_7 )
{
struct V_275 V_276 = {
. V_277 = V_301 ,
. V_279 = V_280 ,
. V_281 = V_7 -> V_82 ,
. V_283 = 8 ,
. V_284 = V_285 ,
. V_286 . V_287 = F_31 ( V_7 ) ,
} ;
F_211 ( & V_276 . V_290 , F_174 ( 0xFF000000 ) , 0 , 0 , 0 ) ;
F_206 ( & V_276 ) ;
}
static void F_212 ( struct V_6 * V_7 )
{
struct V_275 V_276 = {
. V_277 = V_302 ,
. V_279 = V_280 ,
. V_281 = V_7 -> V_82 ,
. V_283 = 96 ,
. V_284 = V_285 | V_292 ,
. V_286 . V_287 = F_31 ( V_7 ) ,
} ;
F_206 ( & V_276 ) ;
}
static struct V_4 * F_213 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_47 ( V_7 ) ;
if ( ! V_5 )
return F_99 ( - V_99 ) ;
if ( V_5 -> V_44 . V_148 )
return F_99 ( - V_149 ) ;
if ( ! ( V_7 -> V_52 & V_54 ) )
F_210 ( V_7 ) ;
return V_5 ;
}
void F_214 ( struct V_6 * V_7 , T_3 * V_303 , int V_304 , bool V_305 )
{
struct V_306 * V_307 ;
V_192 V_167 ;
V_192 V_194 ;
int V_141 ;
struct V_4 * V_110 ;
struct V_97 * V_97 = F_31 ( V_7 ) ;
V_307 = (struct V_306 * ) V_303 ;
if ( V_304 < sizeof( struct V_306 ) ) {
F_35 ( ( L_20 ) ) ;
return;
}
V_141 = F_98 ( & V_307 -> V_170 ) ;
if ( V_141 & ( V_143 | V_308 ) )
return;
V_167 = F_215 ( V_307 -> V_309 ) ;
V_194 = F_215 ( V_307 -> V_310 ) ;
if ( V_194 > V_167 ) {
F_216 ( L_21 ) ;
return;
}
V_110 = F_217 ( V_7 ) ;
if ( V_110 == NULL ) {
F_218 ( L_22 ,
V_7 -> V_37 ) ;
return;
}
if ( V_307 -> V_163 ) {
struct V_139 * V_130 ;
unsigned long V_311 ;
if ( V_3 > V_312 )
V_311 = F_127 ( V_167 , V_3 ) ;
else
V_311 = F_127 ( V_167 , V_312 ) ;
if ( F_219 ( V_311 ) )
V_311 *= V_3 ;
V_130 = F_132 ( & V_307 -> V_170 ,
V_307 -> V_155 ,
V_7 ,
V_313 | V_314 ,
V_171 | V_172 ) ;
if ( V_130 ) {
if ( V_167 == 0 ) {
F_133 ( V_130 ) ;
V_130 = NULL ;
} else if ( F_219 ( V_311 ) ) {
F_134 ( V_130 , V_20 + V_311 ) ;
} else {
F_220 ( V_130 ) ;
}
} else if ( V_167 ) {
T_5 V_19 = 0 ;
int V_52 = V_313 | V_314 ;
if ( F_219 ( V_311 ) ) {
V_52 |= V_174 ;
V_19 = F_221 ( V_311 ) ;
}
F_205 ( & V_307 -> V_170 , V_307 -> V_155 ,
V_7 , V_19 , V_52 ) ;
}
F_88 ( V_130 ) ;
}
if ( V_307 -> V_315 && V_110 -> V_44 . V_315 ) {
struct V_8 * V_9 ;
struct V_135 V_133 ;
int V_316 = 0 , V_317 = 0 ;
if ( V_307 -> V_155 == 64 ) {
memcpy ( & V_133 , & V_307 -> V_170 , 8 ) ;
if ( F_175 ( V_133 . V_187 + 8 , V_7 ) &&
F_201 ( V_133 . V_187 + 8 , V_110 ) ) {
F_86 ( V_110 ) ;
return;
}
goto V_318;
}
F_218 ( L_23 ,
V_307 -> V_155 ) ;
F_86 ( V_110 ) ;
return;
V_318:
V_9 = F_168 ( V_97 , & V_133 , V_7 , 1 ) ;
if ( V_9 == NULL && V_167 ) {
int V_184 = V_110 -> V_44 . V_184 ;
T_1 V_185 = 0 ;
#ifdef F_222
if ( V_110 -> V_44 . V_319 &&
! V_97 -> V_23 . V_114 -> V_50 && V_305 )
V_185 = V_199 ;
#endif
if ( ! V_184 ||
F_139 ( V_110 ) < V_184 )
V_9 = F_97 ( V_110 , & V_133 , V_307 -> V_155 ,
V_141 & V_200 ,
V_185 ) ;
if ( ! V_9 || F_104 ( V_9 ) ) {
F_86 ( V_110 ) ;
return;
}
V_317 = V_316 = 1 ;
V_9 -> V_1 = V_20 ;
F_140 ( V_9 ) ;
}
if ( V_9 ) {
int V_52 ;
unsigned long V_186 ;
#ifdef F_41
struct V_8 * V_175 ;
#endif
T_1 V_320 ;
F_101 ( & V_9 -> V_43 ) ;
V_186 = V_20 ;
if ( V_9 -> V_167 > ( V_186 - V_9 -> V_70 ) / V_3 )
V_320 = V_9 -> V_167 - ( V_186 - V_9 -> V_70 ) / V_3 ;
else
V_320 = 0 ;
if ( ! V_317 && V_320 ) {
if ( V_167 > V_321 ||
V_167 > V_320 )
V_317 = 1 ;
else if ( V_320 <= V_321 ) {
if ( V_194 != V_9 -> V_194 ) {
V_167 = V_320 ;
V_317 = 1 ;
}
} else {
V_167 = V_321 ;
if ( V_167 < V_194 )
V_194 = V_167 ;
V_317 = 1 ;
}
}
if ( V_317 ) {
V_9 -> V_167 = V_167 ;
V_9 -> V_194 = V_194 ;
V_9 -> V_70 = V_186 ;
V_52 = V_9 -> V_52 ;
V_9 -> V_52 &= ~ V_217 ;
F_110 ( & V_9 -> V_43 ) ;
if ( ! ( V_52 & V_118 ) )
F_130 ( 0 , V_9 ) ;
} else
F_110 ( & V_9 -> V_43 ) ;
#ifdef F_41
F_155 ( & V_110 -> V_43 ) ;
F_74 (ift, &in6_dev->tempaddr_list,
tmp_list) {
int V_180 , V_322 , V_323 ;
if ( V_9 != V_175 -> V_164 )
continue;
V_180 = ( V_186 - V_175 -> V_1 ) / V_3 ;
V_322 = V_110 -> V_44 . V_193 - V_180 ;
if ( V_322 < 0 )
V_322 = 0 ;
V_323 = V_110 -> V_44 . V_195 -
V_110 -> V_44 . V_196 -
V_180 ;
if ( V_323 < 0 )
V_323 = 0 ;
if ( V_167 > V_322 )
V_167 = V_322 ;
if ( V_194 > V_323 )
V_194 = V_323 ;
F_101 ( & V_175 -> V_43 ) ;
V_52 = V_175 -> V_52 ;
V_175 -> V_167 = V_167 ;
V_175 -> V_194 = V_194 ;
V_175 -> V_70 = V_186 ;
if ( V_194 > 0 )
V_175 -> V_52 &= ~ V_217 ;
F_110 ( & V_175 -> V_43 ) ;
if ( ! ( V_52 & V_118 ) )
F_130 ( 0 , V_175 ) ;
}
if ( ( V_316 || F_21 ( & V_110 -> V_61 ) ) && V_110 -> V_44 . V_67 > 0 ) {
F_160 ( & V_110 -> V_43 ) ;
F_136 ( V_9 , NULL ) ;
} else {
F_160 ( & V_110 -> V_43 ) ;
}
#endif
F_123 ( V_9 ) ;
F_223 ( 0 ) ;
}
}
F_224 ( V_324 , V_110 , V_307 ) ;
F_86 ( V_110 ) ;
}
int F_225 ( struct V_97 * V_97 , void T_6 * V_105 )
{
struct V_325 V_326 ;
struct V_6 * V_7 ;
int V_98 = - V_112 ;
F_226 () ;
V_98 = - V_327 ;
if ( F_227 ( & V_326 , V_105 , sizeof( struct V_325 ) ) )
goto V_328;
V_7 = F_69 ( V_97 , V_326 . V_329 ) ;
V_98 = - V_146 ;
if ( V_7 == NULL )
goto V_328;
#if F_39 ( V_56 )
if ( V_7 -> type == V_57 ) {
const struct V_330 * V_331 = V_7 -> V_332 ;
struct V_333 V_334 ;
struct V_335 V_123 ;
V_98 = - V_145 ;
if ( ! ( F_98 ( & V_326 . V_336 ) & V_202 ) )
goto V_328;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_337 . V_232 = V_326 . V_336 . V_256 [ 3 ] ;
V_123 . V_337 . V_233 = 0 ;
V_123 . V_337 . V_338 = 4 ;
V_123 . V_337 . V_339 = 5 ;
V_123 . V_337 . V_340 = V_341 ;
V_123 . V_337 . V_342 = 64 ;
V_334 . V_343 . V_344 = ( V_345 void T_6 * ) & V_123 ;
if ( V_331 -> V_346 ) {
T_7 V_347 = F_228 () ;
F_229 ( V_348 ) ;
V_98 = V_331 -> V_346 ( V_7 , & V_334 , V_349 ) ;
F_229 ( V_347 ) ;
} else
V_98 = - V_350 ;
if ( V_98 == 0 ) {
V_98 = - V_99 ;
V_7 = F_230 ( V_97 , V_123 . V_37 ) ;
if ( ! V_7 )
goto V_328;
V_98 = F_231 ( V_7 ) ;
}
}
#endif
V_328:
F_82 () ;
return V_98 ;
}
static int F_232 ( struct V_97 * V_97 , int V_82 , const struct V_135 * V_273 ,
unsigned int V_274 , T_8 V_351 , V_192 V_194 ,
V_192 V_167 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_138 ;
T_1 V_52 ;
T_5 V_19 ;
unsigned long V_352 ;
F_28 () ;
if ( V_274 > 128 )
return - V_112 ;
if ( ! V_167 || V_194 > V_167 )
return - V_112 ;
V_7 = F_69 ( V_97 , V_82 ) ;
if ( ! V_7 )
return - V_146 ;
V_5 = F_213 ( V_7 ) ;
if ( F_104 ( V_5 ) )
return F_105 ( V_5 ) ;
V_138 = F_233 ( V_273 ) ;
V_352 = F_127 ( V_167 , V_3 ) ;
if ( F_219 ( V_352 ) ) {
V_19 = F_221 ( V_352 * V_3 ) ;
V_167 = V_352 ;
V_52 = V_174 ;
} else {
V_19 = 0 ;
V_52 = 0 ;
V_351 |= V_165 ;
}
V_352 = F_127 ( V_194 , V_3 ) ;
if ( F_219 ( V_352 ) ) {
if ( V_352 == 0 )
V_351 |= V_217 ;
V_194 = V_352 ;
}
V_9 = F_97 ( V_5 , V_273 , V_274 , V_138 , V_351 ) ;
if ( ! F_104 ( V_9 ) ) {
F_118 ( & V_9 -> V_43 ) ;
V_9 -> V_167 = V_167 ;
V_9 -> V_194 = V_194 ;
V_9 -> V_70 = V_20 ;
F_119 ( & V_9 -> V_43 ) ;
F_205 ( & V_9 -> V_133 , V_9 -> V_155 , V_7 ,
V_19 , V_52 ) ;
F_140 ( V_9 ) ;
F_123 ( V_9 ) ;
F_223 ( 0 ) ;
return 0 ;
}
return F_105 ( V_9 ) ;
}
static int F_234 ( struct V_97 * V_97 , int V_82 , const struct V_135 * V_273 ,
unsigned int V_274 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
if ( V_274 > 128 )
return - V_112 ;
V_7 = F_69 ( V_97 , V_82 ) ;
if ( ! V_7 )
return - V_146 ;
if ( ( V_5 = F_48 ( V_7 ) ) == NULL )
return - V_353 ;
F_155 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list) {
if ( V_9 -> V_155 == V_274 &&
F_144 ( V_273 , & V_9 -> V_133 ) ) {
F_10 ( V_9 ) ;
F_160 ( & V_5 -> V_43 ) ;
F_117 ( V_9 ) ;
if ( F_21 ( & V_5 -> V_34 ) )
F_235 ( V_5 -> V_7 , 1 ) ;
return 0 ;
}
}
F_160 ( & V_5 -> V_43 ) ;
return - V_145 ;
}
int F_236 ( struct V_97 * V_97 , void T_6 * V_105 )
{
struct V_325 V_326 ;
int V_98 ;
if ( ! F_237 ( V_97 -> V_354 , V_355 ) )
return - V_356 ;
if ( F_227 ( & V_326 , V_105 , sizeof( struct V_325 ) ) )
return - V_327 ;
F_226 () ;
V_98 = F_232 ( V_97 , V_326 . V_329 , & V_326 . V_336 ,
V_326 . V_357 , V_165 ,
V_358 , V_358 ) ;
F_82 () ;
return V_98 ;
}
int F_238 ( struct V_97 * V_97 , void T_6 * V_105 )
{
struct V_325 V_326 ;
int V_98 ;
if ( ! F_237 ( V_97 -> V_354 , V_355 ) )
return - V_356 ;
if ( F_227 ( & V_326 , V_105 , sizeof( struct V_325 ) ) )
return - V_327 ;
F_226 () ;
V_98 = F_234 ( V_97 , V_326 . V_329 , & V_326 . V_336 ,
V_326 . V_357 ) ;
F_82 () ;
return V_98 ;
}
static void F_239 ( struct V_4 * V_5 , const struct V_135 * V_133 ,
int V_274 , int V_138 )
{
struct V_8 * V_9 ;
V_9 = F_97 ( V_5 , V_133 , V_274 , V_138 , V_165 ) ;
if ( ! F_104 ( V_9 ) ) {
F_118 ( & V_9 -> V_43 ) ;
V_9 -> V_52 &= ~ V_118 ;
F_119 ( & V_9 -> V_43 ) ;
F_130 ( V_359 , V_9 ) ;
F_123 ( V_9 ) ;
}
}
static void F_240 ( struct V_4 * V_5 )
{
struct V_135 V_133 ;
struct V_6 * V_7 ;
struct V_97 * V_97 = F_31 ( V_5 -> V_7 ) ;
int V_138 ;
F_28 () ;
memset ( & V_133 , 0 , sizeof( struct V_135 ) ) ;
memcpy ( & V_133 . V_256 [ 3 ] , V_5 -> V_7 -> V_261 , 4 ) ;
if ( V_5 -> V_7 -> V_52 & V_291 ) {
V_133 . V_256 [ 0 ] = F_174 ( 0xfe800000 ) ;
V_138 = V_244 ;
} else {
V_138 = V_202 ;
}
if ( V_133 . V_256 [ 3 ] ) {
F_239 ( V_5 , & V_133 , 128 , V_138 ) ;
return;
}
F_78 (net, dev) {
struct V_360 * V_361 = F_241 ( V_7 ) ;
if ( V_361 && ( V_7 -> V_52 & V_75 ) ) {
struct V_362 * V_117 ;
int V_363 = V_138 ;
for ( V_117 = V_361 -> V_364 ; V_117 ; V_117 = V_117 -> V_365 ) {
int V_274 ;
V_133 . V_256 [ 3 ] = V_117 -> V_366 ;
if ( V_117 -> V_367 == V_368 )
continue;
if ( V_117 -> V_367 >= V_369 ) {
if ( V_5 -> V_7 -> V_52 & V_291 )
continue;
V_363 |= V_249 ;
}
if ( V_5 -> V_7 -> V_52 & V_291 )
V_274 = 64 ;
else
V_274 = 96 ;
F_239 ( V_5 , & V_133 , V_274 , V_363 ) ;
}
}
}
}
static void F_242 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_23 ( L_24 , V_36 ) ;
return;
}
F_239 ( V_5 , & V_370 , 128 , V_249 ) ;
}
static void F_243 ( struct V_4 * V_5 , const struct V_135 * V_133 )
{
struct V_8 * V_9 ;
T_1 V_185 = V_165 ;
#ifdef F_222
if ( V_5 -> V_44 . V_319 &&
! F_31 ( V_5 -> V_7 ) -> V_23 . V_114 -> V_50 )
V_185 |= V_199 ;
#endif
V_9 = F_97 ( V_5 , V_133 , 64 , V_244 , V_185 ) ;
if ( ! F_104 ( V_9 ) ) {
F_205 ( & V_9 -> V_133 , V_9 -> V_155 , V_5 -> V_7 , 0 , 0 ) ;
F_140 ( V_9 ) ;
F_123 ( V_9 ) ;
}
}
static void F_244 ( struct V_6 * V_7 )
{
struct V_135 V_133 ;
struct V_4 * V_5 ;
F_28 () ;
if ( ( V_7 -> type != V_266 ) &&
( V_7 -> type != V_267 ) &&
( V_7 -> type != V_268 ) &&
( V_7 -> type != V_269 ) &&
( V_7 -> type != V_271 ) ) {
return;
}
V_5 = F_213 ( V_7 ) ;
if ( F_104 ( V_5 ) )
return;
memset ( & V_133 , 0 , sizeof( struct V_135 ) ) ;
V_133 . V_256 [ 0 ] = F_174 ( 0xFE800000 ) ;
if ( F_175 ( V_133 . V_187 + 8 , V_7 ) == 0 )
F_243 ( V_5 , & V_133 ) ;
}
static void F_245 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_23 ( L_24 , V_36 ) ;
return;
}
if ( V_7 -> V_58 & V_59 ) {
struct V_135 V_133 ;
F_211 ( & V_133 , F_174 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_205 ( & V_133 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_175 ( V_133 . V_187 + 8 , V_7 ) )
F_243 ( V_5 , & V_133 ) ;
return;
}
F_240 ( V_5 ) ;
if ( V_7 -> V_52 & V_291 )
F_210 ( V_7 ) ;
else
F_212 ( V_7 ) ;
}
static void F_246 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
struct V_135 V_133 ;
F_40 ( L_25 , V_36 , V_7 -> V_37 ) ;
F_28 () ;
if ( ( V_5 = F_47 ( V_7 ) ) == NULL ) {
F_23 ( L_24 , V_36 ) ;
return;
}
F_211 ( & V_133 , F_174 ( 0xFE800000 ) , 0 , 0 , 0 ) ;
F_205 ( & V_133 , 64 , V_7 , 0 , 0 ) ;
if ( ! F_175 ( V_133 . V_187 + 8 , V_7 ) )
F_243 ( V_5 , & V_133 ) ;
}
static inline int
F_247 ( struct V_4 * V_5 , struct V_6 * V_371 )
{
struct V_135 V_372 ;
if ( ! F_162 ( V_371 , & V_372 , V_118 ) ) {
F_243 ( V_5 , & V_372 ) ;
return 0 ;
}
return - 1 ;
}
static void F_248 ( struct V_4 * V_5 )
{
struct V_6 * V_371 ;
struct V_97 * V_97 = F_31 ( V_5 -> V_7 ) ;
if ( V_5 -> V_7 -> V_373 &&
( V_371 = F_69 ( V_97 , V_5 -> V_7 -> V_373 ) ) ) {
if ( ! F_247 ( V_5 , V_371 ) )
return;
}
F_78 (net, link_dev) {
if ( ! F_247 ( V_5 , V_371 ) )
return;
}
F_23 ( L_26 ) ;
}
static void F_249 ( struct V_6 * V_7 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_213 ( V_7 ) ;
if ( F_104 ( V_5 ) ) {
F_23 ( L_27 ) ;
return;
}
F_248 ( V_5 ) ;
}
static int F_250 ( struct V_374 * V_375 , unsigned long V_87 ,
void * V_154 )
{
struct V_6 * V_7 = (struct V_6 * ) V_154 ;
struct V_4 * V_5 = F_48 ( V_7 ) ;
int V_376 = 0 ;
int V_98 ;
switch ( V_87 ) {
case V_377 :
if ( ! V_5 && V_7 -> V_41 >= V_42 ) {
V_5 = F_27 ( V_7 ) ;
if ( ! V_5 )
return F_251 ( - V_33 ) ;
}
break;
case V_160 :
case V_378 :
if ( V_7 -> V_52 & V_379 )
break;
if ( V_87 == V_160 ) {
if ( ! F_4 ( V_7 ) ) {
F_40 ( L_28 ,
V_7 -> V_37 ) ;
break;
}
if ( ! V_5 && V_7 -> V_41 >= V_42 )
V_5 = F_27 ( V_7 ) ;
if ( V_5 ) {
V_5 -> V_68 |= V_69 ;
V_376 = 1 ;
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
F_40 ( L_29 ,
V_7 -> V_37 ) ;
V_376 = 1 ;
}
switch ( V_7 -> type ) {
#if F_39 ( V_56 )
case V_57 :
F_245 ( V_7 ) ;
break;
#endif
#if F_39 ( V_380 )
case V_270 :
F_246 ( V_7 ) ;
break;
#endif
case V_65 :
F_249 ( V_7 ) ;
break;
case V_381 :
F_242 ( V_7 ) ;
break;
default:
F_244 ( V_7 ) ;
break;
}
if ( V_5 ) {
if ( V_376 )
F_252 ( V_5 ) ;
if ( V_5 -> V_44 . V_46 != V_7 -> V_41 &&
V_7 -> V_41 >= V_42 ) {
F_253 ( V_7 , V_7 -> V_41 ) ;
V_5 -> V_44 . V_46 = V_7 -> V_41 ;
}
V_5 -> V_70 = V_20 ;
F_254 ( V_382 , V_5 ) ;
if ( V_7 -> V_41 < V_42 )
F_235 ( V_7 , 1 ) ;
}
break;
case V_383 :
if ( V_5 && V_7 -> V_41 >= V_42 ) {
F_253 ( V_7 , V_7 -> V_41 ) ;
V_5 -> V_44 . V_46 = V_7 -> V_41 ;
break;
}
if ( ! V_5 && V_7 -> V_41 >= V_42 ) {
V_5 = F_27 ( V_7 ) ;
if ( V_5 )
break;
}
case V_169 :
case V_384 :
F_235 ( V_7 , V_87 != V_169 ) ;
break;
case V_385 :
if ( V_5 ) {
F_255 ( V_5 ) ;
F_3 ( V_5 ) ;
F_2 ( V_5 ) ;
V_98 = F_37 ( V_5 ) ;
if ( V_98 )
return F_251 ( V_98 ) ;
}
break;
case V_386 :
case V_387 :
F_256 ( V_7 , V_87 ) ;
break;
}
return V_388 ;
}
static void F_256 ( struct V_6 * V_7 , unsigned long V_87 )
{
struct V_4 * V_5 ;
F_28 () ;
V_5 = F_48 ( V_7 ) ;
if ( V_87 == V_387 )
F_257 ( V_5 ) ;
else if ( V_87 == V_386 )
F_258 ( V_5 ) ;
}
static int F_235 ( struct V_6 * V_7 , int V_389 )
{
struct V_97 * V_97 = F_31 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_8 * V_117 ;
int V_128 , V_207 ;
F_28 () ;
F_259 ( V_97 , V_7 ) ;
F_260 ( & V_49 , V_7 ) ;
V_5 = F_48 ( V_7 ) ;
if ( V_5 == NULL )
return - V_146 ;
if ( V_389 ) {
V_5 -> V_38 = 1 ;
F_261 ( V_7 -> V_71 , NULL ) ;
F_255 ( V_5 ) ;
}
for ( V_207 = 0 ; V_207 < V_390 ; V_207 ++ ) {
struct V_391 * V_392 = & V_156 [ V_207 ] ;
struct V_247 * V_393 ;
F_118 ( & V_150 ) ;
V_394:
F_164 (ifa, n, h, addr_lst) {
if ( V_117 -> V_5 == V_5 ) {
F_120 ( & V_117 -> V_127 ) ;
F_6 ( V_117 ) ;
goto V_394;
}
}
F_119 ( & V_150 ) ;
}
F_121 ( & V_5 -> V_43 ) ;
if ( ! V_389 )
V_5 -> V_68 &= ~ ( V_395 | V_396 | V_69 ) ;
#ifdef F_41
if ( V_389 && F_7 ( & V_5 -> V_62 ) )
F_86 ( V_5 ) ;
while ( ! F_21 ( & V_5 -> V_61 ) ) {
V_117 = F_262 ( & V_5 -> V_61 ,
struct V_8 , V_158 ) ;
F_122 ( & V_117 -> V_158 ) ;
F_129 ( & V_5 -> V_43 ) ;
F_118 ( & V_117 -> V_43 ) ;
if ( V_117 -> V_164 ) {
F_123 ( V_117 -> V_164 ) ;
V_117 -> V_164 = NULL ;
}
F_119 ( & V_117 -> V_43 ) ;
F_123 ( V_117 ) ;
F_121 ( & V_5 -> V_43 ) ;
}
#endif
while ( ! F_21 ( & V_5 -> V_34 ) ) {
V_117 = F_262 ( & V_5 -> V_34 ,
struct V_8 , V_134 ) ;
F_6 ( V_117 ) ;
F_122 ( & V_117 -> V_134 ) ;
F_129 ( & V_5 -> V_43 ) ;
F_118 ( & V_117 -> V_153 ) ;
V_128 = V_117 -> V_128 ;
V_117 -> V_128 = V_129 ;
F_119 ( & V_117 -> V_153 ) ;
if ( V_128 != V_129 ) {
F_263 ( V_168 , V_117 ) ;
F_116 ( & V_159 , V_169 , V_117 ) ;
}
F_123 ( V_117 ) ;
F_121 ( & V_5 -> V_43 ) ;
}
F_129 ( & V_5 -> V_43 ) ;
if ( V_389 )
F_264 ( V_5 ) ;
else
F_265 ( V_5 ) ;
V_5 -> V_70 = V_20 ;
if ( V_389 ) {
F_3 ( V_5 ) ;
F_36 ( & V_49 , V_5 -> V_48 ) ;
F_260 ( & V_49 , V_7 ) ;
F_86 ( V_5 ) ;
}
return 0 ;
}
static void V_18 ( unsigned long V_154 )
{
struct V_8 * V_9 = (struct V_8 * ) V_154 ;
struct V_4 * V_5 = V_9 -> V_5 ;
F_266 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_38 || ! ( V_5 -> V_68 & V_69 ) )
goto V_152;
if ( ! F_267 ( V_5 ) )
goto V_152;
if ( V_5 -> V_68 & V_396 )
goto V_152;
F_101 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_397 ++ < V_5 -> V_44 . V_60 ) {
F_9 ( V_9 , V_17 ,
( V_9 -> V_397 == V_5 -> V_44 . V_60 ) ?
V_5 -> V_44 . V_398 :
V_5 -> V_44 . V_399 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_268 ( V_5 -> V_7 , & V_9 -> V_133 , & V_74 ) ;
} else {
F_110 ( & V_9 -> V_43 ) ;
F_23 ( L_30 , V_5 -> V_7 -> V_37 ) ;
}
V_152:
F_269 ( & V_5 -> V_43 ) ;
F_123 ( V_9 ) ;
}
static void F_270 ( struct V_8 * V_9 )
{
unsigned long V_400 ;
struct V_4 * V_5 = V_9 -> V_5 ;
if ( V_9 -> V_52 & V_199 )
V_400 = 0 ;
else
V_400 = F_271 () % ( V_5 -> V_44 . V_398 ? : 1 ) ;
V_9 -> V_397 = V_5 -> V_44 . V_197 ;
F_9 ( V_9 , V_14 , V_400 ) ;
}
static void F_140 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_176 ( V_7 , & V_9 -> V_133 ) ;
F_272 ( V_9 -> V_133 . V_256 [ 3 ] ) ;
F_155 ( & V_5 -> V_43 ) ;
F_101 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_128 == V_129 )
goto V_152;
if ( V_7 -> V_52 & ( V_53 | V_54 ) ||
V_5 -> V_44 . V_55 < 1 ||
! ( V_9 -> V_52 & V_118 ) ||
V_9 -> V_52 & V_401 ) {
V_9 -> V_52 &= ~ ( V_118 | V_199 | V_252 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_160 ( & V_5 -> V_43 ) ;
F_273 ( V_9 ) ;
return;
}
if ( ! ( V_5 -> V_68 & V_69 ) ) {
F_110 ( & V_9 -> V_43 ) ;
F_160 ( & V_5 -> V_43 ) ;
F_10 ( V_9 ) ;
F_170 ( V_9 , 0 ) ;
return;
}
if ( V_9 -> V_52 & V_199 )
F_274 ( V_9 -> V_130 ) ;
F_270 ( V_9 ) ;
V_152:
F_110 ( & V_9 -> V_43 ) ;
F_160 ( & V_5 -> V_43 ) ;
}
static void V_16 ( unsigned long V_154 )
{
struct V_8 * V_9 = (struct V_8 * ) V_154 ;
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_135 V_402 ;
if ( ! V_9 -> V_397 && F_171 ( V_9 ) )
goto V_152;
F_266 ( & V_5 -> V_43 ) ;
if ( V_5 -> V_38 || ! ( V_5 -> V_68 & V_69 ) ) {
F_269 ( & V_5 -> V_43 ) ;
goto V_152;
}
F_101 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_128 == V_129 ) {
F_110 ( & V_9 -> V_43 ) ;
F_269 ( & V_5 -> V_43 ) ;
goto V_152;
}
if ( V_9 -> V_397 == 0 ) {
V_9 -> V_52 &= ~ ( V_118 | V_199 | V_252 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_269 ( & V_5 -> V_43 ) ;
F_273 ( V_9 ) ;
goto V_152;
}
V_9 -> V_397 -- ;
F_9 ( V_9 , V_14 , V_9 -> V_5 -> V_48 -> V_198 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_269 ( & V_5 -> V_43 ) ;
F_177 ( & V_9 -> V_133 , & V_402 ) ;
F_275 ( V_9 -> V_5 -> V_7 , NULL , & V_9 -> V_133 , & V_402 , & V_403 ) ;
V_152:
F_123 ( V_9 ) ;
}
static void F_273 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_5 -> V_7 ;
F_130 ( V_359 , V_9 ) ;
if ( F_267 ( V_9 -> V_5 ) &&
V_9 -> V_5 -> V_44 . V_60 > 0 &&
( V_7 -> V_52 & V_54 ) == 0 &&
( F_98 ( & V_9 -> V_133 ) & V_308 ) ) {
F_268 ( V_9 -> V_5 -> V_7 , & V_9 -> V_133 , & V_74 ) ;
F_118 ( & V_9 -> V_43 ) ;
V_9 -> V_397 = 1 ;
V_9 -> V_5 -> V_68 |= V_395 ;
F_9 ( V_9 , V_17 , V_9 -> V_5 -> V_44 . V_399 ) ;
F_119 ( & V_9 -> V_43 ) ;
}
}
static void F_252 ( struct V_4 * V_5 )
{
struct V_8 * V_9 ;
F_155 ( & V_5 -> V_43 ) ;
F_74 (ifp, &idev->addr_list, if_list) {
F_101 ( & V_9 -> V_43 ) ;
if ( V_9 -> V_52 & V_118 &&
V_9 -> V_128 == V_254 )
F_270 ( V_9 ) ;
F_110 ( & V_9 -> V_43 ) ;
}
F_160 ( & V_5 -> V_43 ) ;
}
static struct V_8 * F_276 ( struct V_404 * V_86 , T_9 V_405 )
{
struct V_8 * V_117 = NULL ;
struct V_406 * V_128 = V_86 -> V_407 ;
struct V_97 * V_97 = F_277 ( V_86 ) ;
int V_123 = 0 ;
if ( V_405 == 0 ) {
V_128 -> V_408 = 0 ;
V_128 -> V_409 = 0 ;
}
for (; V_128 -> V_408 < V_390 ; ++ V_128 -> V_408 ) {
struct V_247 * V_393 ;
F_169 (ifa, n, &inet6_addr_lst[state->bucket],
addr_lst) {
if ( ! F_165 ( F_31 ( V_117 -> V_5 -> V_7 ) , V_97 ) )
continue;
if ( V_123 < V_128 -> V_409 ) {
V_123 ++ ;
continue;
}
V_128 -> V_409 ++ ;
return V_117 ;
}
V_128 -> V_409 = 0 ;
V_123 = 0 ;
}
return NULL ;
}
static struct V_8 * F_278 ( struct V_404 * V_86 ,
struct V_8 * V_117 )
{
struct V_406 * V_128 = V_86 -> V_407 ;
struct V_97 * V_97 = F_277 ( V_86 ) ;
struct V_247 * V_393 = & V_117 -> V_127 ;
F_279 (ifa, n, addr_lst) {
if ( ! F_165 ( F_31 ( V_117 -> V_5 -> V_7 ) , V_97 ) )
continue;
V_128 -> V_409 ++ ;
return V_117 ;
}
while ( ++ V_128 -> V_408 < V_390 ) {
V_128 -> V_409 = 0 ;
F_169 (ifa, n,
&inet6_addr_lst[state->bucket], addr_lst) {
if ( ! F_165 ( F_31 ( V_117 -> V_5 -> V_7 ) , V_97 ) )
continue;
V_128 -> V_409 ++ ;
return V_117 ;
}
}
return NULL ;
}
static void * F_280 ( struct V_404 * V_86 , T_9 * V_405 )
__acquires( T_10 )
{
F_100 () ;
return F_276 ( V_86 , * V_405 ) ;
}
static void * F_281 ( struct V_404 * V_86 , void * V_410 , T_9 * V_405 )
{
struct V_8 * V_117 ;
V_117 = F_278 ( V_86 , V_410 ) ;
++ * V_405 ;
return V_117 ;
}
static void F_282 ( struct V_404 * V_86 , void * V_410 )
__releases( T_10 )
{
F_114 () ;
}
static int F_283 ( struct V_404 * V_86 , void * V_410 )
{
struct V_8 * V_9 = (struct V_8 * ) V_410 ;
F_284 ( V_86 , L_31 ,
& V_9 -> V_133 ,
V_9 -> V_5 -> V_7 -> V_82 ,
V_9 -> V_155 ,
V_9 -> V_138 ,
V_9 -> V_52 ,
V_9 -> V_5 -> V_7 -> V_37 ) ;
return 0 ;
}
static int F_285 ( struct V_411 * V_411 , struct V_412 * V_412 )
{
return F_286 ( V_411 , V_412 , & V_413 ,
sizeof( struct V_406 ) ) ;
}
static int T_11 F_287 ( struct V_97 * V_97 )
{
if ( ! F_288 ( V_97 , L_32 , V_414 , & V_415 ) )
return - V_33 ;
return 0 ;
}
static void T_12 F_289 ( struct V_97 * V_97 )
{
F_290 ( V_97 , L_32 ) ;
}
int T_13 F_291 ( void )
{
return F_292 ( & V_416 ) ;
}
void F_293 ( void )
{
F_294 ( & V_416 ) ;
}
int F_295 ( struct V_97 * V_97 , const struct V_135 * V_133 )
{
int V_183 = 0 ;
struct V_8 * V_9 = NULL ;
struct V_247 * V_393 ;
unsigned int V_140 = F_94 ( V_133 ) ;
F_100 () ;
F_169 (ifp, n, &inet6_addr_lst[hash], addr_lst) {
if ( ! F_165 ( F_31 ( V_9 -> V_5 -> V_7 ) , V_97 ) )
continue;
if ( F_144 ( & V_9 -> V_133 , V_133 ) &&
( V_9 -> V_52 & V_222 ) ) {
V_183 = 1 ;
break;
}
}
F_114 () ;
return V_183 ;
}
static void F_223 ( unsigned long V_417 )
{
unsigned long V_186 , V_418 , V_419 , V_420 ;
struct V_8 * V_9 ;
struct V_247 * V_248 ;
int V_207 ;
F_100 () ;
F_101 ( & V_421 ) ;
V_186 = V_20 ;
V_418 = F_296 ( V_186 + V_422 ) ;
F_7 ( & V_423 ) ;
for ( V_207 = 0 ; V_207 < V_390 ; V_207 ++ ) {
V_394:
F_169 (ifp, node,
&inet6_addr_lst[i], addr_lst) {
unsigned long V_180 ;
if ( V_9 -> V_52 & V_165 )
continue;
F_101 ( & V_9 -> V_43 ) ;
V_180 = ( V_186 - V_9 -> V_70 + V_424 ) / V_3 ;
if ( V_9 -> V_167 != V_358 &&
V_180 >= V_9 -> V_167 ) {
F_110 ( & V_9 -> V_43 ) ;
F_10 ( V_9 ) ;
F_117 ( V_9 ) ;
goto V_394;
} else if ( V_9 -> V_194 == V_358 ) {
F_110 ( & V_9 -> V_43 ) ;
continue;
} else if ( V_180 >= V_9 -> V_194 ) {
int V_425 = 0 ;
if ( ! ( V_9 -> V_52 & V_217 ) ) {
V_425 = 1 ;
V_9 -> V_52 |= V_217 ;
}
if ( F_128 ( V_9 -> V_70 + V_9 -> V_167 * V_3 , V_418 ) )
V_418 = V_9 -> V_70 + V_9 -> V_167 * V_3 ;
F_110 ( & V_9 -> V_43 ) ;
if ( V_425 ) {
F_10 ( V_9 ) ;
F_130 ( 0 , V_9 ) ;
F_123 ( V_9 ) ;
goto V_394;
}
#ifdef F_41
} else if ( ( V_9 -> V_52 & V_157 ) &&
! ( V_9 -> V_52 & V_118 ) ) {
unsigned long V_181 = V_9 -> V_5 -> V_44 . V_190 *
V_9 -> V_5 -> V_44 . V_197 *
V_9 -> V_5 -> V_48 -> V_198 / V_3 ;
if ( V_180 >= V_9 -> V_194 - V_181 ) {
struct V_8 * V_164 = V_9 -> V_164 ;
if ( F_128 ( V_9 -> V_70 + V_9 -> V_194 * V_3 , V_418 ) )
V_418 = V_9 -> V_70 + V_9 -> V_194 * V_3 ;
if ( ! V_9 -> V_189 && V_164 ) {
V_9 -> V_189 ++ ;
F_10 ( V_9 ) ;
F_10 ( V_164 ) ;
F_110 ( & V_9 -> V_43 ) ;
F_101 ( & V_164 -> V_43 ) ;
V_164 -> V_189 = 0 ;
F_110 ( & V_164 -> V_43 ) ;
F_136 ( V_164 , V_9 ) ;
F_123 ( V_164 ) ;
F_123 ( V_9 ) ;
goto V_394;
}
} else if ( F_128 ( V_9 -> V_70 + V_9 -> V_194 * V_3 - V_181 * V_3 , V_418 ) )
V_418 = V_9 -> V_70 + V_9 -> V_194 * V_3 - V_181 * V_3 ;
F_110 ( & V_9 -> V_43 ) ;
#endif
} else {
if ( F_128 ( V_9 -> V_70 + V_9 -> V_194 * V_3 , V_418 ) )
V_418 = V_9 -> V_70 + V_9 -> V_194 * V_3 ;
F_110 ( & V_9 -> V_43 ) ;
}
}
}
V_419 = F_296 ( V_418 ) ;
V_420 = V_418 ;
if ( F_128 ( V_419 , V_418 + V_426 ) )
V_420 = V_419 ;
if ( F_128 ( V_420 , V_20 + V_427 ) )
V_420 = V_20 + V_427 ;
F_35 ( ( V_238 L_33 ,
V_186 , V_418 , V_419 , V_420 ) ) ;
V_423 . V_19 = V_420 ;
F_11 ( & V_423 ) ;
F_110 ( & V_421 ) ;
F_114 () ;
}
static struct V_135 * F_297 ( struct V_107 * V_133 , struct V_107 * V_428 )
{
struct V_135 * V_273 = NULL ;
if ( V_133 )
V_273 = F_298 ( V_133 ) ;
if ( V_428 ) {
if ( V_273 && F_299 ( V_428 , V_273 , sizeof( * V_273 ) ) )
V_273 = NULL ;
else
V_273 = F_298 ( V_428 ) ;
}
return V_273 ;
}
static int
F_300 ( struct V_80 * V_81 , struct V_88 * V_89 , void * V_105 )
{
struct V_97 * V_97 = F_66 ( V_81 -> V_106 ) ;
struct V_429 * V_430 ;
struct V_107 * V_108 [ V_431 + 1 ] ;
struct V_135 * V_273 ;
int V_98 ;
V_98 = F_67 ( V_89 , sizeof( * V_430 ) , V_108 , V_431 , V_432 ) ;
if ( V_98 < 0 )
return V_98 ;
V_430 = F_56 ( V_89 ) ;
V_273 = F_297 ( V_108 [ V_433 ] , V_108 [ V_434 ] ) ;
if ( V_273 == NULL )
return - V_112 ;
return F_234 ( V_97 , V_430 -> V_435 , V_273 , V_430 -> V_436 ) ;
}
static int F_301 ( struct V_8 * V_9 , T_3 V_351 ,
T_1 V_194 , T_1 V_167 )
{
T_1 V_52 ;
T_5 V_19 ;
unsigned long V_352 ;
if ( ! V_167 || ( V_194 > V_167 ) )
return - V_112 ;
V_352 = F_127 ( V_167 , V_3 ) ;
if ( F_219 ( V_352 ) ) {
V_19 = F_221 ( V_352 * V_3 ) ;
V_167 = V_352 ;
V_52 = V_174 ;
} else {
V_19 = 0 ;
V_52 = 0 ;
V_351 |= V_165 ;
}
V_352 = F_127 ( V_194 , V_3 ) ;
if ( F_219 ( V_352 ) ) {
if ( V_352 == 0 )
V_351 |= V_217 ;
V_194 = V_352 ;
}
F_118 ( & V_9 -> V_43 ) ;
V_9 -> V_52 = ( V_9 -> V_52 & ~ ( V_217 | V_165 | V_401 | V_222 ) ) | V_351 ;
V_9 -> V_70 = V_20 ;
V_9 -> V_167 = V_167 ;
V_9 -> V_194 = V_194 ;
F_119 ( & V_9 -> V_43 ) ;
if ( ! ( V_9 -> V_52 & V_118 ) )
F_130 ( 0 , V_9 ) ;
F_205 ( & V_9 -> V_133 , V_9 -> V_155 , V_9 -> V_5 -> V_7 ,
V_19 , V_52 ) ;
F_223 ( 0 ) ;
return 0 ;
}
static int
F_302 ( struct V_80 * V_81 , struct V_88 * V_89 , void * V_105 )
{
struct V_97 * V_97 = F_66 ( V_81 -> V_106 ) ;
struct V_429 * V_430 ;
struct V_107 * V_108 [ V_431 + 1 ] ;
struct V_135 * V_273 ;
struct V_8 * V_117 ;
struct V_6 * V_7 ;
T_1 V_167 = V_358 , V_437 = V_358 ;
T_3 V_351 ;
int V_98 ;
V_98 = F_67 ( V_89 , sizeof( * V_430 ) , V_108 , V_431 , V_432 ) ;
if ( V_98 < 0 )
return V_98 ;
V_430 = F_56 ( V_89 ) ;
V_273 = F_297 ( V_108 [ V_433 ] , V_108 [ V_434 ] ) ;
if ( V_273 == NULL )
return - V_112 ;
if ( V_108 [ V_438 ] ) {
struct V_439 * V_440 ;
V_440 = F_298 ( V_108 [ V_438 ] ) ;
V_167 = V_440 -> V_441 ;
V_437 = V_440 -> V_442 ;
} else {
V_437 = V_358 ;
V_167 = V_358 ;
}
V_7 = F_69 ( V_97 , V_430 -> V_435 ) ;
if ( V_7 == NULL )
return - V_146 ;
V_351 = V_430 -> V_351 & ( V_401 | V_222 ) ;
V_117 = F_168 ( V_97 , V_273 , V_7 , 1 ) ;
if ( V_117 == NULL ) {
return F_232 ( V_97 , V_430 -> V_435 , V_273 ,
V_430 -> V_436 , V_351 ,
V_437 , V_167 ) ;
}
if ( V_89 -> V_443 & V_444 ||
! ( V_89 -> V_443 & V_445 ) )
V_98 = - V_151 ;
else
V_98 = F_301 ( V_117 , V_351 , V_437 , V_167 ) ;
F_123 ( V_117 ) ;
return V_98 ;
}
static void F_303 ( struct V_88 * V_89 , T_3 V_446 , T_3 V_52 ,
T_3 V_138 , int V_82 )
{
struct V_429 * V_430 ;
V_430 = F_56 ( V_89 ) ;
V_430 -> V_447 = V_93 ;
V_430 -> V_436 = V_446 ;
V_430 -> V_351 = V_52 ;
V_430 -> V_367 = V_138 ;
V_430 -> V_435 = V_82 ;
}
static int F_304 ( struct V_80 * V_81 , unsigned long V_1 ,
unsigned long V_70 , T_1 V_448 , T_1 V_309 )
{
struct V_439 V_440 ;
V_440 . V_1 = F_1 ( V_1 ) ;
V_440 . V_70 = F_1 ( V_70 ) ;
V_440 . V_442 = V_448 ;
V_440 . V_441 = V_309 ;
return F_305 ( V_81 , V_438 , sizeof( V_440 ) , & V_440 ) ;
}
static inline int F_306 ( int V_367 )
{
if ( V_367 & V_249 )
return V_369 ;
else if ( V_367 & V_244 )
return V_368 ;
else if ( V_367 & V_449 )
return V_450 ;
else
return V_451 ;
}
static inline int F_307 ( void )
{
return F_51 ( sizeof( struct V_429 ) )
+ F_52 ( 16 )
+ F_52 ( sizeof( struct V_439 ) ) ;
}
static int F_308 ( struct V_80 * V_81 , struct V_8 * V_117 ,
T_1 V_85 , T_1 V_86 , int V_87 , unsigned int V_52 )
{
struct V_88 * V_89 ;
T_1 V_448 , V_309 ;
V_89 = F_55 ( V_81 , V_85 , V_86 , V_87 , sizeof( struct V_429 ) , V_52 ) ;
if ( V_89 == NULL )
return - V_91 ;
F_303 ( V_89 , V_117 -> V_155 , V_117 -> V_52 , F_306 ( V_117 -> V_138 ) ,
V_117 -> V_5 -> V_7 -> V_82 ) ;
if ( ! ( V_117 -> V_52 & V_165 ) ) {
V_448 = V_117 -> V_194 ;
V_309 = V_117 -> V_167 ;
if ( V_448 != V_358 ) {
long V_452 = ( V_20 - V_117 -> V_70 ) / V_3 ;
if ( V_448 > V_452 )
V_448 -= V_452 ;
else
V_448 = 0 ;
if ( V_309 != V_358 ) {
if ( V_309 > V_452 )
V_309 -= V_452 ;
else
V_309 = 0 ;
}
}
} else {
V_448 = V_358 ;
V_309 = V_358 ;
}
if ( F_305 ( V_81 , V_433 , 16 , & V_117 -> V_133 ) < 0 ||
F_304 ( V_81 , V_117 -> V_1 , V_117 -> V_70 , V_448 , V_309 ) < 0 ) {
F_59 ( V_81 , V_89 ) ;
return - V_91 ;
}
return F_58 ( V_81 , V_89 ) ;
}
static int F_309 ( struct V_80 * V_81 , struct V_453 * V_454 ,
T_1 V_85 , T_1 V_86 , int V_87 , T_14 V_52 )
{
struct V_88 * V_89 ;
T_3 V_138 = V_451 ;
int V_82 = V_454 -> V_5 -> V_7 -> V_82 ;
if ( F_233 ( & V_454 -> V_455 ) & V_449 )
V_138 = V_450 ;
V_89 = F_55 ( V_81 , V_85 , V_86 , V_87 , sizeof( struct V_429 ) , V_52 ) ;
if ( V_89 == NULL )
return - V_91 ;
F_303 ( V_89 , 128 , V_165 , V_138 , V_82 ) ;
if ( F_305 ( V_81 , V_456 , 16 , & V_454 -> V_455 ) < 0 ||
F_304 ( V_81 , V_454 -> V_457 , V_454 -> V_458 ,
V_358 , V_358 ) < 0 ) {
F_59 ( V_81 , V_89 ) ;
return - V_91 ;
}
return F_58 ( V_81 , V_89 ) ;
}
static int F_310 ( struct V_80 * V_81 , struct V_459 * V_460 ,
T_1 V_85 , T_1 V_86 , int V_87 , unsigned int V_52 )
{
struct V_88 * V_89 ;
T_3 V_138 = V_451 ;
int V_82 = V_460 -> V_461 -> V_7 -> V_82 ;
if ( F_233 ( & V_460 -> V_462 ) & V_449 )
V_138 = V_450 ;
V_89 = F_55 ( V_81 , V_85 , V_86 , V_87 , sizeof( struct V_429 ) , V_52 ) ;
if ( V_89 == NULL )
return - V_91 ;
F_303 ( V_89 , 128 , V_165 , V_138 , V_82 ) ;
if ( F_305 ( V_81 , V_463 , 16 , & V_460 -> V_462 ) < 0 ||
F_304 ( V_81 , V_460 -> V_464 , V_460 -> V_465 ,
V_358 , V_358 ) < 0 ) {
F_59 ( V_81 , V_89 ) ;
return - V_91 ;
}
return F_58 ( V_81 , V_89 ) ;
}
static int F_311 ( struct V_4 * V_5 , struct V_80 * V_81 ,
struct V_466 * V_467 , enum V_468 type ,
int V_469 , int * V_470 )
{
struct V_453 * V_454 ;
struct V_459 * V_460 ;
int V_98 = 1 ;
int V_471 = * V_470 ;
F_155 ( & V_5 -> V_43 ) ;
switch ( type ) {
case V_472 : {
struct V_8 * V_117 ;
F_74 (ifa, &idev->addr_list, if_list) {
if ( ++ V_471 < V_469 )
continue;
V_98 = F_308 ( V_81 , V_117 ,
F_70 ( V_467 -> V_81 ) . V_85 ,
V_467 -> V_89 -> V_116 ,
V_359 ,
V_473 ) ;
if ( V_98 <= 0 )
break;
}
break;
}
case V_474 :
for ( V_454 = V_5 -> V_35 ; V_454 ;
V_454 = V_454 -> V_418 , V_471 ++ ) {
if ( V_471 < V_469 )
continue;
V_98 = F_309 ( V_81 , V_454 ,
F_70 ( V_467 -> V_81 ) . V_85 ,
V_467 -> V_89 -> V_116 ,
V_475 ,
V_473 ) ;
if ( V_98 <= 0 )
break;
}
break;
case V_476 :
for ( V_460 = V_5 -> V_477 ; V_460 ;
V_460 = V_460 -> V_478 , V_471 ++ ) {
if ( V_471 < V_469 )
continue;
V_98 = F_310 ( V_81 , V_460 ,
F_70 ( V_467 -> V_81 ) . V_85 ,
V_467 -> V_89 -> V_116 ,
V_479 ,
V_473 ) ;
if ( V_98 <= 0 )
break;
}
break;
default:
break;
}
F_160 ( & V_5 -> V_43 ) ;
* V_470 = V_471 ;
return V_98 ;
}
static int F_312 ( struct V_80 * V_81 , struct V_466 * V_467 ,
enum V_468 type )
{
struct V_97 * V_97 = F_66 ( V_81 -> V_106 ) ;
int V_392 , V_480 ;
int V_481 , V_471 ;
int V_482 , V_469 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_391 * V_483 ;
struct V_247 * V_248 ;
V_480 = V_467 -> args [ 0 ] ;
V_482 = V_481 = V_467 -> args [ 1 ] ;
V_469 = V_471 = V_467 -> args [ 2 ] ;
F_153 () ;
for ( V_392 = V_480 ; V_392 < V_484 ; V_392 ++ , V_482 = 0 ) {
V_481 = 0 ;
V_483 = & V_97 -> V_485 [ V_392 ] ;
F_164 (dev, node, head, index_hlist) {
if ( V_481 < V_482 )
goto V_486;
if ( V_392 > V_480 || V_481 > V_482 )
V_469 = 0 ;
V_471 = 0 ;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_486;
if ( F_311 ( V_5 , V_81 , V_467 , type ,
V_469 , & V_471 ) <= 0 )
goto V_487;
V_486:
V_481 ++ ;
}
}
V_487:
F_161 () ;
V_467 -> args [ 0 ] = V_392 ;
V_467 -> args [ 1 ] = V_481 ;
V_467 -> args [ 2 ] = V_471 ;
return V_81 -> V_304 ;
}
static int F_313 ( struct V_80 * V_81 , struct V_466 * V_467 )
{
enum V_468 type = V_472 ;
return F_312 ( V_81 , V_467 , type ) ;
}
static int F_314 ( struct V_80 * V_81 , struct V_466 * V_467 )
{
enum V_468 type = V_474 ;
return F_312 ( V_81 , V_467 , type ) ;
}
static int F_315 ( struct V_80 * V_81 , struct V_466 * V_467 )
{
enum V_468 type = V_476 ;
return F_312 ( V_81 , V_467 , type ) ;
}
static int F_316 ( struct V_80 * V_104 , struct V_88 * V_89 ,
void * V_105 )
{
struct V_97 * V_97 = F_66 ( V_104 -> V_106 ) ;
struct V_429 * V_430 ;
struct V_107 * V_108 [ V_431 + 1 ] ;
struct V_135 * V_133 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_117 ;
struct V_80 * V_81 ;
int V_98 ;
V_98 = F_67 ( V_89 , sizeof( * V_430 ) , V_108 , V_431 , V_432 ) ;
if ( V_98 < 0 )
goto V_101;
V_133 = F_297 ( V_108 [ V_433 ] , V_108 [ V_434 ] ) ;
if ( V_133 == NULL ) {
V_98 = - V_112 ;
goto V_101;
}
V_430 = F_56 ( V_89 ) ;
if ( V_430 -> V_435 )
V_7 = F_69 ( V_97 , V_430 -> V_435 ) ;
V_117 = F_168 ( V_97 , V_133 , V_7 , 1 ) ;
if ( ! V_117 ) {
V_98 = - V_145 ;
goto V_101;
}
V_81 = F_61 ( F_307 () , V_28 ) ;
if ( ! V_81 ) {
V_98 = - V_99 ;
goto V_488;
}
V_98 = F_308 ( V_81 , V_117 , F_70 ( V_104 ) . V_85 ,
V_89 -> V_116 , V_359 , 0 ) ;
if ( V_98 < 0 ) {
F_20 ( V_98 == - V_91 ) ;
F_62 ( V_81 ) ;
goto V_488;
}
V_98 = F_71 ( V_81 , V_97 , F_70 ( V_104 ) . V_85 ) ;
V_488:
F_123 ( V_117 ) ;
V_101:
return V_98 ;
}
static void F_317 ( int V_87 , struct V_8 * V_117 )
{
struct V_80 * V_81 ;
struct V_97 * V_97 = F_31 ( V_117 -> V_5 -> V_7 ) ;
int V_98 = - V_99 ;
V_81 = F_61 ( F_307 () , V_100 ) ;
if ( V_81 == NULL )
goto V_101;
V_98 = F_308 ( V_81 , V_117 , 0 , 0 , V_87 , 0 ) ;
if ( V_98 < 0 ) {
F_20 ( V_98 == - V_91 ) ;
F_62 ( V_81 ) ;
goto V_101;
}
F_63 ( V_81 , V_97 , 0 , V_489 , NULL , V_100 ) ;
return;
V_101:
if ( V_98 < 0 )
F_64 ( V_97 , V_489 , V_98 ) ;
}
static inline void F_318 ( struct V_83 * V_44 ,
T_2 * V_490 , int V_491 )
{
F_319 ( V_491 < ( V_492 * 4 ) ) ;
memset ( V_490 , 0 , V_491 ) ;
V_490 [ V_493 ] = V_44 -> V_50 ;
V_490 [ V_494 ] = V_44 -> V_495 ;
V_490 [ V_496 ] = V_44 -> V_46 ;
V_490 [ V_497 ] = V_44 -> V_498 ;
V_490 [ V_499 ] = V_44 -> V_500 ;
V_490 [ V_501 ] = V_44 -> V_315 ;
V_490 [ V_502 ] = V_44 -> V_197 ;
V_490 [ V_503 ] = V_44 -> V_60 ;
V_490 [ V_504 ] =
F_320 ( V_44 -> V_399 ) ;
V_490 [ V_505 ] =
F_320 ( V_44 -> V_398 ) ;
V_490 [ V_506 ] = V_44 -> V_507 ;
#ifdef F_41
V_490 [ V_508 ] = V_44 -> V_67 ;
V_490 [ V_509 ] = V_44 -> V_193 ;
V_490 [ V_510 ] = V_44 -> V_195 ;
V_490 [ V_511 ] = V_44 -> V_190 ;
V_490 [ V_512 ] = V_44 -> V_196 ;
#endif
V_490 [ V_513 ] = V_44 -> V_184 ;
V_490 [ V_514 ] = V_44 -> V_515 ;
V_490 [ V_516 ] = V_44 -> V_517 ;
#ifdef F_321
V_490 [ V_518 ] = V_44 -> V_519 ;
V_490 [ V_520 ] =
F_320 ( V_44 -> V_521 ) ;
#ifdef F_322
V_490 [ V_522 ] = V_44 -> V_523 ;
#endif
#endif
V_490 [ V_524 ] = V_44 -> V_525 ;
V_490 [ V_526 ] = V_44 -> V_527 ;
#ifdef F_222
V_490 [ V_528 ] = V_44 -> V_319 ;
#endif
#ifdef F_53
V_490 [ V_529 ] = V_44 -> V_96 ;
#endif
V_490 [ V_530 ] = V_44 -> V_148 ;
V_490 [ V_531 ] = V_44 -> V_55 ;
V_490 [ V_532 ] = V_44 -> V_533 ;
V_490 [ V_534 ] = V_44 -> V_535 ;
}
static inline T_15 F_323 ( void )
{
return F_52 ( 4 )
+ F_52 ( sizeof( struct V_536 ) )
+ F_52 ( V_492 * 4 )
+ F_52 ( V_537 * 8 )
+ F_52 ( V_538 * 8 ) ;
}
static inline T_15 F_324 ( void )
{
return F_51 ( sizeof( struct V_539 ) )
+ F_52 ( V_540 )
+ F_52 ( V_541 )
+ F_52 ( 4 )
+ F_52 ( 4 )
+ F_52 ( F_323 () ) ;
}
static inline void F_325 ( T_16 * V_22 , T_17 * V_542 ,
int V_543 , int V_491 )
{
int V_207 ;
int V_544 = V_491 - sizeof( T_16 ) * V_543 ;
F_319 ( V_544 < 0 ) ;
F_326 ( V_543 , & V_22 [ 0 ] ) ;
for ( V_207 = 1 ; V_207 < V_543 ; V_207 ++ )
F_326 ( F_327 ( & V_542 [ V_207 ] ) , & V_22 [ V_207 ] ) ;
memset ( & V_22 [ V_543 ] , 0 , V_544 ) ;
}
static inline void F_328 ( T_16 * V_22 , void V_21 * * V_542 ,
int V_543 , int V_491 , T_15 V_545 )
{
int V_207 ;
int V_544 = V_491 - sizeof( T_16 ) * V_543 ;
F_319 ( V_544 < 0 ) ;
F_326 ( V_543 , & V_22 [ 0 ] ) ;
for ( V_207 = 1 ; V_207 < V_543 ; V_207 ++ )
F_326 ( F_329 ( V_542 , V_207 , V_545 ) , & V_22 [ V_207 ] ) ;
memset ( & V_22 [ V_543 ] , 0 , V_544 ) ;
}
static void F_330 ( T_16 * V_22 , struct V_4 * V_5 , int V_546 ,
int V_491 )
{
switch ( V_546 ) {
case V_547 :
F_328 ( V_22 , ( void V_21 * * ) V_5 -> V_22 . V_23 ,
V_537 , V_491 , F_331 ( struct V_24 , V_548 ) ) ;
break;
case V_549 :
F_325 ( V_22 , V_5 -> V_22 . V_26 -> V_550 , V_538 , V_491 ) ;
break;
}
}
static int F_332 ( struct V_80 * V_81 , struct V_4 * V_5 )
{
struct V_107 * V_551 ;
struct V_536 V_440 ;
if ( F_333 ( V_81 , V_552 , V_5 -> V_68 ) )
goto V_95;
V_440 . V_553 = V_554 ;
V_440 . V_70 = F_1 ( V_5 -> V_70 ) ;
V_440 . V_555 = F_320 ( V_5 -> V_48 -> V_555 ) ;
V_440 . V_198 = F_320 ( V_5 -> V_48 -> V_198 ) ;
if ( F_305 ( V_81 , V_556 , sizeof( V_440 ) , & V_440 ) )
goto V_95;
V_551 = F_334 ( V_81 , V_557 , V_492 * sizeof( V_558 ) ) ;
if ( V_551 == NULL )
goto V_95;
F_318 ( & V_5 -> V_44 , F_298 ( V_551 ) , F_335 ( V_551 ) ) ;
V_551 = F_334 ( V_81 , V_547 , V_537 * sizeof( T_16 ) ) ;
if ( V_551 == NULL )
goto V_95;
F_330 ( F_298 ( V_551 ) , V_5 , V_547 , F_335 ( V_551 ) ) ;
V_551 = F_334 ( V_81 , V_549 , V_538 * sizeof( T_16 ) ) ;
if ( V_551 == NULL )
goto V_95;
F_330 ( F_298 ( V_551 ) , V_5 , V_549 , F_335 ( V_551 ) ) ;
return 0 ;
V_95:
return - V_91 ;
}
static T_15 F_336 ( const struct V_6 * V_7 )
{
if ( ! F_48 ( V_7 ) )
return 0 ;
return F_323 () ;
}
static int F_337 ( struct V_80 * V_81 , const struct V_6 * V_7 )
{
struct V_4 * V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
return - V_559 ;
if ( F_332 ( V_81 , V_5 ) < 0 )
return - V_91 ;
return 0 ;
}
static int F_338 ( struct V_80 * V_81 , struct V_4 * V_5 ,
T_1 V_85 , T_1 V_86 , int V_87 , unsigned int V_52 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_539 * V_560 ;
struct V_88 * V_89 ;
void * V_561 ;
V_89 = F_55 ( V_81 , V_85 , V_86 , V_87 , sizeof( * V_560 ) , V_52 ) ;
if ( V_89 == NULL )
return - V_91 ;
V_560 = F_56 ( V_89 ) ;
V_560 -> V_562 = V_93 ;
V_560 -> V_563 = 0 ;
V_560 -> V_564 = V_7 -> type ;
V_560 -> V_565 = V_7 -> V_82 ;
V_560 -> V_566 = F_339 ( V_7 ) ;
V_560 -> V_567 = 0 ;
if ( F_340 ( V_81 , V_568 , V_7 -> V_37 ) ||
( V_7 -> V_259 &&
F_305 ( V_81 , V_569 , V_7 -> V_259 , V_7 -> V_261 ) ) ||
F_333 ( V_81 , V_570 , V_7 -> V_41 ) ||
( V_7 -> V_82 != V_7 -> V_373 &&
F_333 ( V_81 , V_571 , V_7 -> V_373 ) ) )
goto V_95;
V_561 = F_341 ( V_81 , V_572 ) ;
if ( V_561 == NULL )
goto V_95;
if ( F_332 ( V_81 , V_5 ) < 0 )
goto V_95;
F_342 ( V_81 , V_561 ) ;
return F_58 ( V_81 , V_89 ) ;
V_95:
F_59 ( V_81 , V_89 ) ;
return - V_91 ;
}
static int F_343 ( struct V_80 * V_81 , struct V_466 * V_467 )
{
struct V_97 * V_97 = F_66 ( V_81 -> V_106 ) ;
int V_392 , V_480 ;
int V_481 = 0 , V_482 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_391 * V_483 ;
struct V_247 * V_248 ;
V_480 = V_467 -> args [ 0 ] ;
V_482 = V_467 -> args [ 1 ] ;
F_153 () ;
for ( V_392 = V_480 ; V_392 < V_484 ; V_392 ++ , V_482 = 0 ) {
V_481 = 0 ;
V_483 = & V_97 -> V_485 [ V_392 ] ;
F_164 (dev, node, head, index_hlist) {
if ( V_481 < V_482 )
goto V_486;
V_5 = F_48 ( V_7 ) ;
if ( ! V_5 )
goto V_486;
if ( F_338 ( V_81 , V_5 ,
F_70 ( V_467 -> V_81 ) . V_85 ,
V_467 -> V_89 -> V_116 ,
V_382 , V_473 ) <= 0 )
goto V_152;
V_486:
V_481 ++ ;
}
}
V_152:
F_161 () ;
V_467 -> args [ 1 ] = V_481 ;
V_467 -> args [ 0 ] = V_392 ;
return V_81 -> V_304 ;
}
void F_254 ( int V_87 , struct V_4 * V_5 )
{
struct V_80 * V_81 ;
struct V_97 * V_97 = F_31 ( V_5 -> V_7 ) ;
int V_98 = - V_99 ;
V_81 = F_61 ( F_324 () , V_100 ) ;
if ( V_81 == NULL )
goto V_101;
V_98 = F_338 ( V_81 , V_5 , 0 , 0 , V_87 , 0 ) ;
if ( V_98 < 0 ) {
F_20 ( V_98 == - V_91 ) ;
F_62 ( V_81 ) ;
goto V_101;
}
F_63 ( V_81 , V_97 , 0 , V_573 , NULL , V_100 ) ;
return;
V_101:
if ( V_98 < 0 )
F_64 ( V_97 , V_573 , V_98 ) ;
}
static inline T_15 F_344 ( void )
{
return F_51 ( sizeof( struct V_574 ) )
+ F_52 ( sizeof( struct V_135 ) )
+ F_52 ( sizeof( struct V_575 ) ) ;
}
static int F_345 ( struct V_80 * V_81 , struct V_4 * V_5 ,
struct V_306 * V_307 , T_1 V_85 , T_1 V_86 ,
int V_87 , unsigned int V_52 )
{
struct V_574 * V_576 ;
struct V_88 * V_89 ;
struct V_575 V_440 ;
V_89 = F_55 ( V_81 , V_85 , V_86 , V_87 , sizeof( * V_576 ) , V_52 ) ;
if ( V_89 == NULL )
return - V_91 ;
V_576 = F_56 ( V_89 ) ;
V_576 -> V_577 = V_93 ;
V_576 -> V_578 = 0 ;
V_576 -> V_579 = 0 ;
V_576 -> V_580 = V_5 -> V_7 -> V_82 ;
V_576 -> V_155 = V_307 -> V_155 ;
V_576 -> V_581 = V_307 -> type ;
V_576 -> V_582 = 0 ;
V_576 -> V_583 = 0 ;
if ( V_307 -> V_163 )
V_576 -> V_583 |= V_584 ;
if ( V_307 -> V_315 )
V_576 -> V_583 |= V_585 ;
if ( F_305 ( V_81 , V_586 , sizeof( V_307 -> V_170 ) , & V_307 -> V_170 ) )
goto V_95;
V_440 . V_587 = F_215 ( V_307 -> V_310 ) ;
V_440 . V_588 = F_215 ( V_307 -> V_309 ) ;
if ( F_305 ( V_81 , V_589 , sizeof( V_440 ) , & V_440 ) )
goto V_95;
return F_58 ( V_81 , V_89 ) ;
V_95:
F_59 ( V_81 , V_89 ) ;
return - V_91 ;
}
static void F_224 ( int V_87 , struct V_4 * V_5 ,
struct V_306 * V_307 )
{
struct V_80 * V_81 ;
struct V_97 * V_97 = F_31 ( V_5 -> V_7 ) ;
int V_98 = - V_99 ;
V_81 = F_61 ( F_344 () , V_100 ) ;
if ( V_81 == NULL )
goto V_101;
V_98 = F_345 ( V_81 , V_5 , V_307 , 0 , 0 , V_87 , 0 ) ;
if ( V_98 < 0 ) {
F_20 ( V_98 == - V_91 ) ;
F_62 ( V_81 ) ;
goto V_101;
}
F_63 ( V_81 , V_97 , 0 , V_590 , NULL , V_100 ) ;
return;
V_101:
if ( V_98 < 0 )
F_64 ( V_97 , V_590 , V_98 ) ;
}
static void F_263 ( int V_87 , struct V_8 * V_9 )
{
F_317 ( V_87 ? : V_359 , V_9 ) ;
switch ( V_87 ) {
case V_359 :
if ( ! ( V_9 -> V_130 -> V_591 ) )
F_274 ( V_9 -> V_130 ) ;
if ( V_9 -> V_5 -> V_44 . V_50 )
F_75 ( V_9 ) ;
break;
case V_168 :
if ( V_9 -> V_5 -> V_44 . V_50 )
F_76 ( V_9 ) ;
F_178 ( V_9 -> V_5 , & V_9 -> V_133 ) ;
F_209 ( & V_9 -> V_130 -> V_206 ) ;
if ( F_133 ( V_9 -> V_130 ) )
F_346 ( & V_9 -> V_130 -> V_206 ) ;
break;
}
}
static void F_130 ( int V_87 , struct V_8 * V_9 )
{
F_100 () ;
if ( F_115 ( V_9 -> V_5 -> V_38 == 0 ) )
F_263 ( V_87 , V_9 ) ;
F_114 () ;
}
static
int F_347 ( V_121 * V_592 , int V_593 ,
void T_6 * V_594 , T_15 * V_595 , T_9 * V_596 )
{
int * V_597 = V_592 -> V_154 ;
int V_598 = * V_597 ;
T_9 V_405 = * V_596 ;
V_121 V_599 ;
int V_183 ;
V_599 = * V_592 ;
V_599 . V_154 = & V_598 ;
V_183 = F_348 ( & V_599 , V_593 , V_594 , V_595 , V_596 ) ;
if ( V_593 )
V_183 = F_79 ( V_592 , V_597 , V_598 ) ;
if ( V_183 )
* V_596 = V_405 ;
return V_183 ;
}
static void F_349 ( struct V_4 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_7 )
return;
if ( V_5 -> V_44 . V_148 )
F_250 ( NULL , V_169 , V_5 -> V_7 ) ;
else
F_250 ( NULL , V_160 , V_5 -> V_7 ) ;
}
static void F_350 ( struct V_97 * V_97 , T_2 V_119 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
F_153 () ;
F_154 (net, dev) {
V_5 = F_48 ( V_7 ) ;
if ( V_5 ) {
int V_120 = ( ! V_5 -> V_44 . V_148 ) ^ ( ! V_119 ) ;
V_5 -> V_44 . V_148 = V_119 ;
if ( V_120 )
F_349 ( V_5 ) ;
}
}
F_161 () ;
}
static int F_351 ( struct V_121 * V_122 , int * V_123 , int V_119 )
{
struct V_97 * V_97 ;
int V_124 ;
if ( ! F_80 () )
return F_81 () ;
V_97 = (struct V_97 * ) V_122 -> V_125 ;
V_124 = * V_123 ;
* V_123 = V_119 ;
if ( V_123 == & V_97 -> V_23 . V_45 -> V_148 ) {
F_82 () ;
return 0 ;
}
if ( V_123 == & V_97 -> V_23 . V_114 -> V_148 ) {
V_97 -> V_23 . V_45 -> V_148 = V_119 ;
F_350 ( V_97 , V_119 ) ;
} else if ( ( ! V_119 ) ^ ( ! V_124 ) )
F_349 ( (struct V_4 * ) V_122 -> V_126 ) ;
F_82 () ;
return 0 ;
}
static
int F_352 ( V_121 * V_592 , int V_593 ,
void T_6 * V_594 , T_15 * V_595 , T_9 * V_596 )
{
int * V_597 = V_592 -> V_154 ;
int V_598 = * V_597 ;
T_9 V_405 = * V_596 ;
V_121 V_599 ;
int V_183 ;
V_599 = * V_592 ;
V_599 . V_154 = & V_598 ;
V_183 = F_348 ( & V_599 , V_593 , V_594 , V_595 , V_596 ) ;
if ( V_593 )
V_183 = F_351 ( V_592 , V_597 , V_598 ) ;
if ( V_183 )
* V_596 = V_405 ;
return V_183 ;
}
static int F_353 ( struct V_97 * V_97 , char * V_600 ,
struct V_4 * V_5 , struct V_83 * V_123 )
{
int V_207 ;
struct V_601 * V_602 ;
char V_603 [ sizeof( L_34 ) + V_540 ] ;
V_602 = F_354 ( & V_604 , sizeof( * V_602 ) , V_28 ) ;
if ( V_602 == NULL )
goto V_152;
for ( V_207 = 0 ; V_602 -> V_605 [ V_207 ] . V_154 ; V_207 ++ ) {
V_602 -> V_605 [ V_207 ] . V_154 += ( char * ) V_123 - ( char * ) & V_83 ;
V_602 -> V_605 [ V_207 ] . V_126 = V_5 ;
V_602 -> V_605 [ V_207 ] . V_125 = V_97 ;
}
snprintf ( V_603 , sizeof( V_603 ) , L_35 , V_600 ) ;
V_602 -> V_606 = F_355 ( V_97 , V_603 , V_602 -> V_605 ) ;
if ( V_602 -> V_606 == NULL )
goto free;
V_123 -> V_47 = V_602 ;
return 0 ;
free:
F_16 ( V_602 ) ;
V_152:
return - V_99 ;
}
static void F_356 ( struct V_83 * V_123 )
{
struct V_601 * V_602 ;
if ( V_123 -> V_47 == NULL )
return;
V_602 = V_123 -> V_47 ;
V_123 -> V_47 = NULL ;
F_357 ( V_602 -> V_606 ) ;
F_16 ( V_602 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_358 ( V_5 -> V_7 , V_5 -> V_48 , L_36 ,
& V_607 ) ;
F_353 ( F_31 ( V_5 -> V_7 ) , V_5 -> V_7 -> V_37 ,
V_5 , & V_5 -> V_44 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
F_356 ( & V_5 -> V_44 ) ;
F_359 ( V_5 -> V_48 ) ;
}
static int T_11 F_360 ( struct V_97 * V_97 )
{
int V_98 ;
struct V_83 * V_608 , * V_609 ;
V_98 = - V_33 ;
V_608 = & V_83 ;
V_609 = & V_610 ;
if ( ! F_165 ( V_97 , & V_611 ) ) {
V_608 = F_354 ( V_608 , sizeof( V_83 ) , V_28 ) ;
if ( V_608 == NULL )
goto V_612;
V_609 = F_354 ( V_609 , sizeof( V_610 ) , V_28 ) ;
if ( V_609 == NULL )
goto V_613;
} else {
V_609 -> V_315 = V_614 . V_315 ;
V_609 -> V_148 = V_614 . V_148 ;
}
V_97 -> V_23 . V_114 = V_608 ;
V_97 -> V_23 . V_45 = V_609 ;
#ifdef F_361
V_98 = F_353 ( V_97 , L_37 , NULL , V_608 ) ;
if ( V_98 < 0 )
goto V_615;
V_98 = F_353 ( V_97 , L_38 , NULL , V_609 ) ;
if ( V_98 < 0 )
goto V_616;
#endif
return 0 ;
#ifdef F_361
V_616:
F_356 ( V_608 ) ;
V_615:
F_16 ( V_609 ) ;
#endif
V_613:
F_16 ( V_608 ) ;
V_612:
return V_98 ;
}
static void T_12 F_362 ( struct V_97 * V_97 )
{
#ifdef F_361
F_356 ( V_97 -> V_23 . V_45 ) ;
F_356 ( V_97 -> V_23 . V_114 ) ;
#endif
if ( ! F_165 ( V_97 , & V_611 ) ) {
F_16 ( V_97 -> V_23 . V_45 ) ;
F_16 ( V_97 -> V_23 . V_114 ) ;
}
}
int F_363 ( struct V_374 * V_617 )
{
return F_364 ( & V_159 , V_617 ) ;
}
int F_365 ( struct V_374 * V_617 )
{
return F_366 ( & V_159 , V_617 ) ;
}
int T_13 F_367 ( void )
{
int V_207 , V_98 ;
V_98 = F_368 () ;
if ( V_98 < 0 ) {
F_369 ( L_39 ,
V_36 , V_98 ) ;
goto V_152;
}
V_98 = F_292 ( & V_618 ) ;
if ( V_98 < 0 )
goto V_619;
F_226 () ;
if ( ! F_27 ( V_611 . V_620 ) )
V_98 = - V_33 ;
F_82 () ;
if ( V_98 )
goto V_621;
for ( V_207 = 0 ; V_207 < V_390 ; V_207 ++ )
F_370 ( & V_156 [ V_207 ] ) ;
F_371 ( & V_622 ) ;
F_223 ( 0 ) ;
V_98 = F_372 ( & V_623 ) ;
if ( V_98 < 0 )
goto V_624;
V_98 = F_373 ( V_625 , V_626 , NULL , F_343 ,
NULL ) ;
if ( V_98 < 0 )
goto V_101;
F_373 ( V_625 , V_359 , F_302 , NULL , NULL ) ;
F_373 ( V_625 , V_168 , F_300 , NULL , NULL ) ;
F_373 ( V_625 , V_627 , F_316 ,
F_313 , NULL ) ;
F_373 ( V_625 , V_475 , NULL ,
F_314 , NULL ) ;
F_373 ( V_625 , V_479 , NULL ,
F_315 , NULL ) ;
F_373 ( V_625 , V_628 , F_65 ,
NULL , NULL ) ;
F_374 () ;
return 0 ;
V_101:
F_375 ( & V_623 ) ;
V_624:
F_376 ( & V_622 ) ;
V_621:
F_294 ( & V_618 ) ;
V_619:
F_377 () ;
V_152:
return V_98 ;
}
void F_378 ( void )
{
struct V_6 * V_7 ;
int V_207 ;
F_376 ( & V_622 ) ;
F_294 ( & V_618 ) ;
F_377 () ;
F_226 () ;
F_379 ( & V_623 ) ;
F_78 (&init_net, dev) {
if ( F_48 ( V_7 ) == NULL )
continue;
F_235 ( V_7 , 1 ) ;
}
F_235 ( V_611 . V_620 , 2 ) ;
F_118 ( & V_150 ) ;
for ( V_207 = 0 ; V_207 < V_390 ; V_207 ++ )
F_20 ( ! F_380 ( & V_156 [ V_207 ] ) ) ;
F_119 ( & V_150 ) ;
F_7 ( & V_423 ) ;
F_82 () ;
}
